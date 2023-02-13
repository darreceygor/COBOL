
/* config.h, tested with x86/x64 VS2005-2019
   and OrangeC 6.0.45.1 (which ignores the lib comments) */

#define NOISAM       0
#define BDB          1
#define VBISAM       2
#define CISAM        3
#define DISAM        4

#define NOCURSES     0
#define PDCURSES     1

#define NOXML        0
#define XML2         1

#define NOJSON       0
#define CJSON        1
#define CJSON_CJSON  2	/* cJSON with header in CJSON_CJSON */
#define CJSON_LOCAL  3	/* cJSON in libsupport, activate external source */
#define JSON_C       4

#define MATHLIB_MPIR 1
#define MATHLIB_GMP  2

/* Use the following global define to adjust your configuration, if needed
   * adjust WITH_VARSEQ,  if you exactly know what the results will be
   * switch from VBISAM to another ISAM configuration
   * switch from PDCURSES  to "no curses"
   * switch from "no xml" to XML2"   (needs additional libraries, see below)
   * switch from "no json" to CJSON" (needs additional libraries, see below)
   * switch from MPIR (gmp-compat)  to GMP
*/

#define CONFIGURED_ISAM   VBISAM        /* see possible values above */
#define CONFIGURED_CURSES PDCURSES      /* see possible values above */
#define CONFIGURED_XML    NOXML         /* see possible values above */
#define CONFIGURED_JSON   NOJSON        /* see possible values above */
#define USED_MATHLIB      MATHLIB_MPIR  /* see possible values above */

/* define if you want to use the fall-back to GetUserName
   for ACCEPT var FROM USER NAME
   note: only active if %USERNAME% is not set, needs an additional
   library for each invocation of libcob, even if not used...
#define HAVE_GETUSERNAME 1
*/

/* adjust the following defines to override linker pragmas below */
/* #undef LIB_MATHLIB */
/* #undef LIB_CURSES  */
/* #undef LIB_ISAM    */
/* #undef LIB_JSON    */


#ifdef WITHIN_LIBCOB
#ifdef HAVE_GETUSERNAME
#pragma comment(lib, "advapi32")
#endif

#ifdef LIB_MATHLIB
#pragma comment(lib, LIB_MATHLIB)
#else
#if USED_MATHLIB == MATHLIB_MPIR
#pragma comment(lib, "mpir")
#elif USED_MATHLIB == MATHLIB_GMP
#pragma comment(lib, "libgmp")
#endif
#endif

#if CONFIGURED_CURSES == PDCURSES
#define PDC_DLL_BUILD	/* comment if you link against a static library */
/* the following options must match the version of PDCurses you link against
   recheck after building with cobcrun --info */
#ifndef PDC_WIDE
//#define PDC_WIDE		/* activate if used PDCurses was built with WIDE option */
#ifndef CHTYPE_32
#define CHTYPE_32		/* remove if used PDCurses was built using a 64-bit chtype,
                           even on non-WIDE versions (PDCurses 4.x only) */
#endif
#endif
#ifdef LIB_CURSES
#pragma comment(lib, LIB_CURSES)
#else
#pragma comment(lib, "pdcurses")
#endif
#endif

#ifdef LIB_ISAM
#pragma comment(lib, LIB_ISAM)
#else
#if CONFIGURED_ISAM == VBISAM
#pragma comment(lib, "libvbisam")
#elif CONFIGURED_ISAM == DISAM
#pragma comment(lib, "libdisam72")
#elif CONFIGURED_ISAM == BDB
//#ifdef _DEBUG
//#pragma comment(lib, "libdb48d")
//#pragma comment(lib, "libdb62d")
//#else
#pragma comment(lib, "libdb48")
//#pragma comment(lib, "libdb62")
//#endif
#endif /* CONFIGURED_ISAM */
#endif

#if CONFIGURED_XML == XML2
#if 0 /* provided from mingw */
#pragma comment(lib, "libxml2.dll.a")
#pragma comment(lib, "libcharset.dll.a")
#pragma comment(lib, "libiconv.dll.a")
#pragma comment(lib, "libz.dll.a")
#else
#pragma comment(lib, "libxml2")
#pragma comment(lib, "libcharset")
#pragma comment(lib, "libiconv")
#ifdef _DEBUG
#pragma comment(lib, "zlibd")
#else
#pragma comment(lib, "zlib")
#endif
#endif
#endif

#ifdef LIB_JSON
#pragma comment(lib, LIB_JSON)
#elif CONFIGURED_JSON == CJSON || CONFIGURED_JSON == CJSON_CJSON
#pragma comment(lib, "cjson")
#elif CONFIGURED_JSON == JSON_C
#pragma comment(lib, "json-c")
#endif

#endif /* WITHIN_LIBCOB */

/* Define if building universal (internal helper macro) */
/* #undef AC_APPLE_UNIVERSAL_BUILD */

/* executable name for module runner */
#define COBCRUN_NAME     "cobcrun"

/* long int is 32 bits */
/* always true for MSC - even on x64 */
#define COB_32_BIT_LONG 1

/* Pointers are longer than 32 bits */
#ifdef _WIN64
#define COB_64_BIT_POINTER 1
#else
#undef COB_64_BIT_POINTER
#endif

/* informational: build environment during compilation */
#undef COB_BLD_BUILD	/* see below */

/* informational: compiler during compilation */
#undef COB_BLD_CC	/* see below */

/* informational: compiler flags during compilation */
#undef COB_BLD_CFLAGS	/* see below */

/* informational: preparser flags during compilation */
#undef COB_BLD_CPPFLAGS	/* see below */

/* informational: linker during compilation */
#undef COB_BLD_LD	/* see below */

/* informational: linker flags during compilation */
#undef COB_BLD_LDFLAGS	/* see below */

// /* try to use compile defines for that:
#if defined(__ORANGEC__)

#define COB_BLD_CC       "occ.exe"
#define COB_BLD_CPPFLAGS ""
#ifdef _DEBUG
#define COB_BLD_CFLAGS   "unknown OrangeC DEBUG generation"
#else
#define COB_BLD_CFLAGS   "unknown OrangeC RELEASE generation"
#endif

#define COB_BLD_LD       "olink.exe"
#define COB_BLD_LDFLAGS  ""
#define COB_BLD_BUILD    "i686-pc-windows"

#else  /* __ORANGEC__ */

#define COB_BLD_CC       "cl.exe"
#define COB_BLD_CPPFLAGS ""
#if defined (_MSC_VER)
#if _MSC_VER > 1910
#ifdef _DEBUG
#define COB_BLD_CFLAGS   "unknown MSC DEBUG generation"
#else
#define COB_BLD_CFLAGS   "unknown MSC RELEASE generation"
#endif
#elif _MSC_VER == 1900 || _MSC_VER == 1910
#ifdef _DEBUG
#define COB_BLD_CFLAGS	"/GS /analyze- /W3 /Zc:wchar_t /ZI /Gm /Od /Zc:inline /fp:precise /errorReport:prompt /WX- /Zc:forScope /RTC1 /Gd /Oy- /MDd /EHsc"
#else
#define COB_BLD_CFLAGS	"/GS /GL /analyze- /W4 /Zc:wchar_t /Gm- /O2 /Ob2 /Zc:inline /fp:precise /errorReport:prompt /WX- /Zc:forScope /Gd /Oy- /Oi /MD /EHsc /Ot"
#endif
#elif _MSC_VER == 1800
#ifdef _DEBUG
#define COB_BLD_CFLAGS	"/GS /analyze- /W3 /Zc:wchar_t /ZI /Gm /Od /fp:precise /errorReport:prompt /WX- /Zc:forScope /RTC1 /Gd /Oy- /MDd /EHsc"
#else
#define COB_BLD_CFLAGS	"/GS /GL /analyze- /W4 /Zc:wchar_t /Gm- /O2 /Ob2 /fp:precise /errorReport:prompt /WX- /Zc:forScope /Gd /Oy- /Oi /MD /EHsc"
#endif
#elif _MSC_VER == 1700
#ifdef _DEBUG
#define COB_BLD_CFLAGS   "/GS /GL /analyze- /W4 /Zc:wchar_t /Zi /Gm- /O2 /Ob2 /fp:precise /WX- /Zc:forScope /Gd /Oy- /Oi /MD /EHsc /Ot"
#else
#define COB_BLD_CFLAGS   "/Zi /nologo /W4 /WX- /O2 /Ob2 /Oi /Ot /Oy- /GL /Gm- /EHsc /MD /GS /fp:precise /Zc:wchar_t /Zc:forScope /Gd /analyze-"
#endif
#elif _MSC_VER == 1600
#ifdef _DEBUG
#define COB_BLD_CFLAGS   "/GS /GL /analyze- /W4 /Zc:wchar_t /Zi /Gm- /O2 /Ob2 /fp:precise /WX- /Zc:forScope /Gd /Oy- /Oi /MD /EHsc /Ot"
#else
#define COB_BLD_CFLAGS   "/Zi /nologo /W4 /WX- /O2 /Ob2 /Oi /Ot /Oy- /GL /Gm- /EHsc /MD /GS /fp:precise /Zc:wchar_t /Zc:forScope /Gd /analyze-"
#endif
#elif _MSC_VER == 1500
#ifdef _DEBUG
#define COB_BLD_CFLAGS   "/O2 /Ob2 /Oi /Ot /GL /FD /EHsc /MD /W4 /nologo /c /Zi /TP"
#else
#define COB_BLD_CFLAGS   "/Od /Gm /EHsc /RTC1 /MDd /W3 /nologo /c /Zi /TP"
#endif
#elif _MSC_VER == 1400
#ifdef _DEBUG
#define COB_BLD_CFLAGS   "/Od /Gm /EHsc /RTC1 /MDd /W3 /nologo /c /Zi /TP"
#else
#define COB_BLD_CFLAGS   "/O2 /Ob2 /Oi /Ot /GL /FD /EHsc /MD /c /Zi /TP"
#endif
#endif // _MSC_VER checks
#else
#ifdef _DEBUG
#define COB_BLD_CFLAGS   "unknown DEBUG generation"
#else
#define COB_BLD_CFLAGS   "unknown RELEASE generation"
#endif
#endif

#define COB_BLD_LD       "link.exe"
#define COB_BLD_LDFLAGS  ""
#define COB_BLD_BUILD    "i686-pc-windows"

#endif  /* __ORANGEC__ */

/* compiler used by cobc */
#if defined(__ORANGEC__)
#define COB_CC           "occ.exe"
#else
#define COB_CC           "cl.exe"
#endif

/* compiler flags passed to compiler by cobc */
#undef COB_CFLAGS

// Use \ to escape things, for example \\ for using in paths
// Use \" for paths with spaces

// define MAKE_DIST for using C:\\GnuCOBOL_Version:
//#define MAKE_DIST 1

#ifdef MAKE_DIST
#ifndef COB_MAIN_DIR
#define COB_MAIN_DIR     "C:\\" PACKAGE_NAME "_" PACKAGE_VERSION
#endif
#define COB_CFLAGS       "-I \"" COB_MAIN_DIR "\\include\""

#if defined(__ORANGEC__)
#ifdef _WIN64 /*note: currently no x64 with OrangeC */
#define COB_LDFLAGS      "/L\"" COB_MAIN_DIR "\\lib_x64\""
#else
#define COB_LDFLAGS      "/L\"" COB_MAIN_DIR "\\lib\""
#endif
#else  /* __ORANGEC__ */
#ifdef _WIN64
#define COB_LDFLAGS      "/incremental:no /LIBPATH:\"" COB_MAIN_DIR "\\lib_x64\""
#else
#define COB_LDFLAGS      "/incremental:no /LIBPATH:\"" COB_MAIN_DIR "\\lib\""
#endif
#endif

#else  // no MAKE_DIST

// specify the local path where the gnucobol sources reside in:

#ifndef COB_MAIN_DIR
#define COB_MAIN_DIR     "C:\\GnuCOBOL"
#endif
#define COB_CFLAGS       "-I \"" COB_MAIN_DIR "\" -I \"" COB_MAIN_DIR "\\build_windows\""

#ifdef _WIN64
#define TARGET_PLATFORM "x64"
#else
#define TARGET_PLATFORM "win32"
#endif

#ifdef _DEBUG
#define TARGET_CONFIG "debug"
#else
#define TARGET_CONFIG "release"
#endif

#if defined(__ORANGEC__)
#define COB_LDFLAGS      "/L\"" COB_MAIN_DIR "\\build_windows\\" TARGET_PLATFORM "\\" TARGET_CONFIG "\""
#else
#define COB_LDFLAGS      "/incremental:no /LIBPATH:\"" COB_MAIN_DIR "\\build_windows\\" TARGET_PLATFORM "\\" TARGET_CONFIG "\""
#endif

#endif // no MAKE_DIST

/* Compilation of computed gotos works */
/* #undef COB_COMPUTED_GOTO */

/* default search path for copybooks */
#define COB_CONFIG_DIR   COB_MAIN_DIR "\\config"

/* default search path for configuration files */
#define COB_COPY_DIR     COB_MAIN_DIR "\\copy"

/* Compile/link option for debugging */
#if defined(__ORANGEC__)
#define COB_DEBUG_FLAGS "-g"
#else
#undef COB_DEBUG_FLAGS
#endif

/* Enable internal logging (Developers only!) */
/* #undef COB_DEBUG_LOG */

/* Executable extension */
#define COB_EXE_EXT ".exe"

/* Enable experimental code (Developers only!) */
/* #undef COB_EXPERIMENTAL */

/* Compile/link option for exporting symbols */
#if defined(__ORANGEC__)
#define COB_EXPORT_DYN ""	/* needs to be specified for all but MSVC */
#else
#undef COB_EXPORT_DYN
#endif

/* Keyword for inline */
#define COB_KEYWORD_INLINE __inline

/* linker flags passed to linker by cobc */
/* COB_LDFLAGS set above */

/* default search path for extra modules */
#undef COB_LIBRARY_PATH	/* set to define built-in directory */

/* libraries passed to linker by cobc */
#ifndef __ORANGEC__
#define COB_LIBS         "libcob.lib"
#else
#define COB_LIBS         "libcob.l"
#endif


/* long int is long long */
/* #undef COB_LI_IS_LL */

/* Module extension */
#define COB_MODULE_EXT "dll"

/* Can not dlopen self */
#define COB_NO_SELFOPEN 1

/* Object extension */
#if defined(__ORANGEC__)
#define COB_OBJECT_EXT "o"
#else
#define COB_OBJECT_EXT "obj"
#endif

/* Enable minimum parameter check for system libraries */
/* #undef COB_PARAM_CHECK */

/* Compile/link option for PIC code */
#if defined(__ORANGEC__)
#define COB_PIC_FLAGS ""	/* needs to be specified for all but MSVC */
#else
#undef COB_PIC_FLAGS
#endif

/* Compile/link option for shared code */
#if defined(__ORANGEC__)
#define COB_SHARED_OPT "/Wd"
#else
#undef COB_SHARED_OPT
#endif

/* Strip command */
/* #undef COB_STRIP_CMD */

/* Enable extra checks within the compiler (Developers only!) */
/* #undef COB_TREE_DEBUG */

/* Define to 1 if translation of program messages to the user's native
   language is requested. */
/* #undef ENABLE_NLS */

/* Has __attribute__((aligned)) */
/* #undef HAVE_ATTRIBUTE_ALIGNED */

/* Define to 1 if you have the `canonicalize_file_name' function. */
#if defined(__ORANGEC__)
#define HAVE_CANONICALIZE_FILE_NAME 1
#else
/* #undef HAVE_CANONICALIZE_FILE_NAME */
#endif

/* Define to 1 if you have the Mac OS X function
   CFLocaleCopyPreferredLanguages in the CoreFoundation framework. */
/* #undef HAVE_CFLOCALECOPYPREFERREDLANGUAGES */

/* Define to 1 if you have the Mac OS X function CFPreferencesCopyAppValue in
   the CoreFoundation framework. */
/* #undef HAVE_CFPREFERENCESCOPYAPPVALUE */

/* Define to 1 if you have the <cjson/cJSON.h> header file. */
#if CONFIGURED_JSON == CJSON_CJSON
#define HAVE_CJSON_CJSON_H 1
#else
/* #undef HAVE_CJSON_CJSON_H */
#endif

/* Define to 1 if you have the <cJSON.h> header file. */
#if CONFIGURED_JSON == CJSON \
 || CONFIGURED_JSON == CJSON_LOCAL
#define HAVE_CJSON_H 1
#else
/* #undef HAVE_CJSON_H */
#endif

/* Has clock_gettime function and CLOCK_REALTIME */
/* #undef HAVE_CLOCK_GETTIME */

/* curses has color_set function */
#if CONFIGURED_CURSES != NOCURSES
#define HAVE_COLOR_SET 1
#else
/* #undef HAVE_COLOR_SET */
#endif

/* ncurses has _nc_freeall function */
/* #undef HAVE_CURSES_FREEALL */

/* Define to 1 if you have the <curses.h> header file. */
#if CONFIGURED_CURSES != NOCURSES
#define HAVE_CURSES_H 1
#else
/* #undef HAVE_CURSES_H */
#endif

/* Define to 1 if you have the <db.h> header file. */
#if CONFIGURED_ISAM == BDB
#define HAVE_DB_H 1
#else
/* #undef HAVE_DB_H */
#endif

/* Define if the GNU dcgettext() function is already present or preinstalled.
   */
/* #undef HAVE_DCGETTEXT */

/* Define to 1 if you have the declaration of `fdatasync', and to 0 if you
   don't. */
#define HAVE_DECL_FDATASYNC 0

/* Define to 1 if you have the declaration of `fmemopen', and to 0 if you
   don't. */
#undef HAVE_DECL_FMEMOPEN

/* curses has define_key function */
/* #undef HAVE_DEFINE_KEY */

/* Has designated initializers */
/* #undef HAVE_DESIGNATED_INITS */
#if defined(_MSC_VER) && _MSC_VER >= 1800 /* = COB_USE_VC2013_OR_GREATER [which is defined later] */ \
 || defined(__ORANGEC__)
#define HAVE_DESIGNATED_INITS 1
#endif


/* Define to 1 if you have the <disam.h> header file. */
#if CONFIGURED_ISAM == DISAM
#define HAVE_DISAM_H 1
#else
/* #undef HAVE_DISAM_H */
#endif

/* Has dladdr function */
/* #undef HAVE_DLADDR */

/* Define to 1 if you have the <dlfcn.h> header file. */
/* #undef HAVE_DLFCN_H */

/* Define to 1 if you don't have `vprintf' but do have `_doprnt.' */
/* #undef HAVE_DOPRNT */

/* Define to 1 if you have the `fcntl' function. */
#if defined(__ORANGEC__)
#define HAVE_FCNTL 1
#else
/* #undef HAVE_FCNTL */
#endif

/* Define to 1 if you have the <fcntl.h> header file. */
#define HAVE_FCNTL_H 1

/* Define to 1 if you have the `fdatasync' function. */
/* #undef HAVE_FDATASYNC */

/* Declaration of finite function in ieeefp.h instead of math.h */
/* #undef HAVE_FINITE_IEEEFP_H */

/* Define to 1 if you have the `flockfile' function. */
/* #undef HAVE_FLOCKFILE */

/* Define to 1 if you have the `fmemopen' function. */
/* #undef HAVE_FMEMOPEN */

/* Define to 1 if you have the `getexecname' function. */
#if defined(__ORANGEC__)
#define HAVE_GETEXECNAME 1
#else
/* #undef HAVE_GETEXECNAME */
#endif

/* Define if the GNU gettext() function is already present or preinstalled. */
/* #undef HAVE_GETTEXT */

/* Define to 1 if you have the `gettimeofday' function. */
#if defined(__ORANGEC__)
#define HAVE_GETTIMEOFDAY 1
#else
/* #undef HAVE_GETTIMEOFDAY */
#endif

/* Define to 1 if you have the <gmp.h> header file. */
#if USED_MATHLIB == MATHLIB_MPIR
/* #undef HAVE_GMP_H */
#else
#define HAVE_GMP_H 1
#endif

/* curses has has_mouse function */
/* #undef HAVE_HAS_MOUSE */

/* Define if you have the iconv() function and it works. */
#if CONFIGURED_XML == XML2	/* necessary, assume available */
#define HAVE_ICONV 1
#else
/* #undef HAVE_ICONV */
#endif

/* Define to 1 if you have the <inttypes.h> header file. */
#if !defined(_MSC_VER) || _MSC_VER >= 1700
#define HAVE_INTTYPES_H 1
#else
/* #undef HAVE_INTTYPES_H */
#endif

/* Define to 1 if you have the <isam.h> header file. */
#if CONFIGURED_ISAM == CISAM
#define HAVE_ISAM_H 1
#else
/* #undef HAVE_ISAM_H */
#endif

/* Has isfinite function */
#if defined(__ORANGEC__)
#define HAVE_ISFINITE 1
#else
/* #undef HAVE_ISFINITE */
#endif

/* Define if you have <langinfo.h> and nl_langinfo(CODESET). */
/* #undef HAVE_LANGINFO_CODESET */

/* Define to 1 if you have the `curses' library (-lcurses). */
/* #undef HAVE_LIBCURSES */

/* Define to 1 if you have the `ncurses' library (-lncurses). */
/* #undef HAVE_LIBNCURSES */

/* Define to 1 if you have the `ncursesw' library (-lncursesw). */
/* #undef HAVE_LIBNCURSESW */

/* Define to 1 if you have the `pdcurses' library (-lpdcurses). */
#if CONFIGURED_CURSES == PDCURSES
#define HAVE_LIBPDCURSES 1
#else
/* #undef HAVE_LIBPDCURSES */
#endif

/* Define to 1 if you have the `posix4' library (-lposix4). */
/* #undef HAVE_LIBPOSIX4 */

/* Define to 1 if you have the `rt' library (-lrt). */
/* #undef HAVE_LIBRT */

/* Define to 1 if you have the `localeconv' function. */
#define HAVE_LOCALECONV 1

/* Define to 1 if you have the <locale.h> header file. */
#define HAVE_LOCALE_H 1

/* Define to 1 if you have the <ltdl.h> header file. */
/* #undef HAVE_LTDL_H */

/* Define to 1 if you have the <malloc.h> header file. */
#define HAVE_MALLOC_H 1

/* Define to 1 if you have the `memmove' function. */
#define HAVE_MEMMOVE 1

/* Define to 1 if you have the <memory.h> header file. */
#define HAVE_MEMORY_H 1

/* Define to 1 if you have the `memset' function. */
#define HAVE_MEMSET 1

/* curses has mouseinterval function */
#if CONFIGURED_CURSES != NOCURSES
#define HAVE_MOUSEINTERVAL 1
#else
/* #undef HAVE_MOUSEINTERVAL */
#endif

/* Define to 1 if you have the <mpir.h> header file. */
#if USED_MATHLIB == MATHLIB_MPIR
#define HAVE_MPIR_H 1
#else
/* #undef HAVE_MPIR_H */
#endif

/* Do we have mp_get_memory_functions in GMP/MPIR */
#define HAVE_MP_GET_MEMORY_FUNCTIONS 1

/* Has nanosleep function */
/* #undef HAVE_NANO_SLEEP */

/* Define to 1 if you have the <ncursesw/curses.h> header file. */
/* #undef HAVE_NCURSESW_CURSES_H */

/* Define to 1 if you have the <ncursesw/ncurses.h> header file. */
/* #undef HAVE_NCURSESW_NCURSES_H */

/* Define to 1 if you have the <ncurses.h> header file. */
/* #undef HAVE_NCURSES_H */

/* Define to 1 if you have the <ncurses/ncurses.h> header file. */
/* #undef HAVE_NCURSES_NCURSES_H */

/* Define to 1 if you have the <pdcurses.h> header file. */
/* #undef HAVE_PDCURSES_H */

/* Define to 1 if you have the `popen' function. */
#define HAVE_POPEN 1

/* Define to 1 if you have the `raise' function. */
#define HAVE_RAISE 1

/* Define to 1 if you have the `readlink' function. */
/* #undef HAVE_READLINK */

/* Define to 1 if you have the `realpath' function. */
#if defined(__ORANGEC__)
#define HAVE_REALPATH 1
#else
/* #undef HAVE_REALPATH */
#endif

/* Define to 1 if you have the `setenv' function. */
/* MSC does *NOT* have `setenv' (!)
   But as the handling of the fallback `putenv' is different in POSIX and _MSC
   (POSIX stores no duplicate of `putenv', where _MSC does), we pretend to
   have support for `setenv' and define it in common.c using _putenv_s,
   omitting the override parameter
   ORANGEC provides the function */
#define HAVE_SETENV 1

/* Define to 1 if you have the `setlocale' function. */
#define HAVE_SETLOCALE 1

/* Define to 1 if you have the `sigaction' function. */
#if defined(__ORANGEC__)
#define HAVE_SIGACTION 1
#else
/* #undef HAVE_SIGACTION */
#endif

/* Define to 1 if you have the <signal.h> header file. */
#define HAVE_SIGNAL_H 1

/* Define to 1 if the system has the type `sig_atomic_t'. */
#define HAVE_SIG_ATOMIC_T 1

/* Define to 1 if you have the <stddef.h> header file. */
#define HAVE_STDDEF_H 1

/* Define to 1 if you have the <stdint.h> header file. */
#if !defined(_MSC_VER) || _MSC_VER >= 1600 /* = COB_USE_VC2010_OR_GREATER */
#define HAVE_STDINT_H 1
#else
/* #undef HAVE_STDINT_H */
#define NO_STDINT_H 1	/* for pdcurses header */
#endif

/* Define to 1 if you have the <stdlib.h> header file. */
#define HAVE_STDLIB_H 1

/* Define to 1 if you have the `strcasecmp' function. */
#define HAVE_STRCASECMP 1

/* Define to 1 if you have the `strchr' function. */
#define HAVE_STRCHR 1

/* Define to 1 if you have the `strcoll' function. */
#define HAVE_STRCOLL 1

/* Define to 1 if you have the `strdup' function. */
#define HAVE_STRDUP 1

/* Define to 1 if you have the `strerror' function. */
#define HAVE_STRERROR 1

/* Define to 1 if you have the <strings.h> header file. */
#if defined(__ORANGEC__)
#define HAVE_STRINGS_H 1
#else
/* #undef HAVE_STRINGS_H */
#endif

/* Define to 1 if you have the <string.h> header file. */
#define HAVE_STRING_H 1

/* Define to 1 if you have the `strrchr' function. */
#define HAVE_STRRCHR 1

/* Define to 1 if you have the `strstr' function. */
#define HAVE_STRSTR 1

/* Define to 1 if you have the `strtol' function. */
#define HAVE_STRTOL 1

/* Define to 1 if you have the <sys/stat.h> header file. */
#define HAVE_SYS_STAT_H 1

/* Define to 1 if you have the <sys/time.h> header file. */
#if defined(__ORANGEC__)
#define HAVE_SYS_TIME_H 1
#else
/* #undef HAVE_SYS_TIME_H */
#endif

/* Define to 1 if you have the <sys/types.h> header file. */
#define HAVE_SYS_TYPES_H 1

/* Define to 1 if you have the <sys/wait.h> header file. */
#if defined(__ORANGEC__)
#define HAVE_SYS_WAIT_H 1
#else
/* #undef HAVE_SYS_WAIT_H */
#endif

/* Has timezone variable */
/* note: MSC and ORANGEC have it as _timezone */
#define HAVE_TIMEZONE 1

/* Define to 1 if you have the <unistd.h> header file. */
#if defined(__ORANGEC__)
#define HAVE_UNISTD_H 1
#else
/* #undef HAVE_UNISTD_H */
#endif

/* ncurses has use_legacy_coding function */
/* #undef HAVE_USE_LEGACY_CODING */

/* Define to 1 if you have the <vbisam.h> header file. */
#if CONFIGURED_ISAM == VBISAM
#define HAVE_VBISAM_H 1
#else
/* #undef HAVE_VBISAM_H */
#endif

/* Define to 1 if you have the `vprintf' function. */
#define HAVE_VPRINTF 1

/* Define to 1 if you have the <wchar.h> header file. */
#define HAVE_WCHAR_H 1

/* Define to the sub-directory where libtool stores uninstalled libraries. */
/* #undef LT_OBJDIR */

/* Define maximum parameters for CALL */
#define MAX_CALL_FIELD_PARAMS 192

/* Name of package */
#define PACKAGE "gnucobol"

/* Define to the address where bug reports for this package should be sent. */
#define PACKAGE_BUGREPORT "bug-gnucobol@gnu.org"

/* Define to the full name of this package. */
#define PACKAGE_NAME "GnuCOBOL"

/* Define to the full name and version of this package. */
#define PACKAGE_STRING "GnuCOBOL 3.1.1-dev"

/* Define to the one symbol short name of this package. */
#define PACKAGE_TARNAME "gnucobol"

/* Define to the home page for this package. */
#define PACKAGE_URL "https://www.gnu.org/software/gnucobol/"

/* Define to the version of this package. */
#define PACKAGE_VERSION "3.1.1-dev"

/* Define a patch level (numeric, max. 8 digits) */
#define PATCH_LEVEL COB_NUM_TAR_DATE

/* Define to 1 if you have the ANSI C header files. */
#define STDC_HEADERS 1

/* Define to 1 if your <sys/time.h> declares `struct tm'. */
/* #undef TM_IN_SYS_TIME */

/* Use system dynamic loader */
/* #undef USE_LIBDL */

/* Enable extensions on AIX 3, Interix.  */
#ifndef _ALL_SOURCE
# define _ALL_SOURCE 1
#endif
/* Enable GNU extensions on systems that have them.  */
#ifndef _GNU_SOURCE
# define _GNU_SOURCE 1
#endif
/* Enable threading extensions on Solaris.  */
#ifndef _POSIX_PTHREAD_SEMANTICS
# define _POSIX_PTHREAD_SEMANTICS 1
#endif
/* Enable extensions on HP NonStop.  */
#ifndef _TANDEM_SOURCE
# define _TANDEM_SOURCE 1
#endif
/* Enable general extensions on Solaris.  */
#ifndef __EXTENSIONS__
# define __EXTENSIONS__ 1
#endif


/* Version number of package */
#define VERSION "3.1-dev"

/* Use CISAM as ISAM handler */
#if CONFIGURED_ISAM == CISAM
#define WITH_CISAM 1
#else
/* #undef WITH_CISAM */
#endif

/* Use cJSON library/source as JSON handler */
#if CONFIGURED_JSON == CJSON \
 || CONFIGURED_JSON == CJSON_CJSON \
 || CONFIGURED_JSON == CJSON_LOCAL
#define WITH_CJSON 1
#else
/* #undef WITH_CJSON */
#endif

/* curses library for extended SCREEN I/O */
#if CONFIGURED_CURSES == PDCURSES
#define WITH_CURSES "pdcurses"
#else
#define WITH_CURSES "disabled"
#endif

/* Use Berkeley DB library as emulation of ISAM handler */
#if CONFIGURED_ISAM == BDB
#define WITH_DB 1
#else
/* #undef WITH_DB */
#endif

/* Use DISAM as ISAM handler */
#if CONFIGURED_ISAM == DISAM
#define WITH_DISAM 1
#else
/* #undef WITH_DISAM */
#endif

/* Compile with an external ISAM handler */
/* #undef WITH_INDEX_EXTFH */

/* JSON handler */
#if CONFIGURED_JSON == CJSON \
 || CONFIGURED_JSON == CJSON_CJSON \
 || CONFIGURED_JSON == CJSON_LOCAL
#define WITH_JSON "cJSON"
#elif CONFIGURED_JSON == JSON_C
#define WITH_JSON "json-c"
#else
#define WITH_JSON "disabled"
#endif

/* Use JSON-C library as JSON handler */
#if CONFIGURED_JSON == JSON_C
#define WITH_JSON_C 1
#else
/* #undef WITH_JSON_C */
#endif

/* Math multiple precision library */
#if USED_MATHLIB == MATHLIB_MPIR
#define WITH_MATH "mpir"
#else
#define WITH_MATH "gmp"
#endif

/* Compile with an external SEQ/RAN handler */
/* #undef WITH_SEQRA_EXTFH */

/* Define variable sequential file format */
#define WITH_VARSEQ 0

/* Use VBISAM as ISAM handler */
#if CONFIGURED_ISAM == VBISAM
#define WITH_VBISAM 1
#else
/* #undef WITH_VBISAM */
#endif

/* Use libxml2 as XML handler */
#if CONFIGURED_XML == XML2
#define WITH_XML2 1
#else
/* #undef WITH_XML2 */
#endif

/* Define WORDS_BIGENDIAN to 1 if your processor stores words with the most
   significant byte first (like Motorola and SPARC, unlike Intel). */
#if defined AC_APPLE_UNIVERSAL_BUILD
# if defined __BIG_ENDIAN__
#  define WORDS_BIGENDIAN 1
# endif
#else
# ifndef WORDS_BIGENDIAN
/* #  undef WORDS_BIGENDIAN */
# endif
#endif

/* Define to 1 if `lex' declares `yytext' as a `char *' by default, not a
   `char[]'. */
#define YYTEXT_POINTER 1

/* Define to 1 if on MINIX. */
/* #undef _MINIX */

/* Define to 2 if the system does not provide POSIX.1 features except with
   this defined. */
/* #undef _POSIX_1_SOURCE */

/* Define to 1 if you need to in order for `stat' and other things to work. */
/* #undef _POSIX_SOURCE */

/* Define to 1 if on HPUX.  */
#ifndef _XOPEN_SOURCE_EXTENDED
/* # undef _XOPEN_SOURCE_EXTENDED */
#endif

/* Define to empty if `const' does not conform to ANSI C. */
/* #undef const */

/* Define to `unsigned int' if <sys/types.h> does not define. */
/* #undef size_t */

#ifdef ENABLE_NLS
#pragma comment(lib, "libintl")
#endif

#undef NOISAM
#undef BDB
#undef VBISAM
#undef CISAM
#undef DISAM
#undef CONFIGURED_ISAM
#undef NOCURSES
#undef PDCURSES
#undef CONFIGURED_CURSES
#undef NOXML
#undef XML2
#undef CONFIGURED_XML
#undef NOJSON
#undef CJSON
#undef CJSON_CJSON
#undef CJSON_LOCAL
#undef JSON_C
#undef CONFIGURED_JSON
#undef MATHLIB_MPIR
#undef MATHLIB_GMP
#undef USED_MATHLIB
