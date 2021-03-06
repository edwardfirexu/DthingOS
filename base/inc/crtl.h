/**
 * Copyright (C) 2013 YarlungSoft. All Rights Reserved.
 * 
 * Created:         $Date: 2013/06/10 $
 * Last modified:	$Date: 2013/06/15 $
 * Version:         $ID: crtl.h#1
 */

/**
 * This file re-defined C rtuntime APIs into standard Dthing API.
 * All APIs are re-directed to CRTL(c runtime library) prefix.
 */

#ifndef __CRTL_CORE_H__
#define __CRTL_CORE_H__

#include <std_types.h>

//#ifdef WIN32
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#include <ctype.h>
//#endif 


#ifdef __cplusplus
extern "C" {
#endif

/*
 * ==================== ANSI style string operations ==========================
 */
#define CRTL_strlen(str)                (strlen(str))
#define CRTL_strcpy(dst, src)           (strcpy ((dst), (src)))
#define CRTL_strncpy(dst, src, n)       (strncpy ((dst), (src), (n)))
#define CRTL_strcat(dst, src)           (strcat ((dst), (src)))
#define CRTL_strncat(dst, src, n)       (strncat ((dst), (src), (n)))
#define CRTL_strchr(str, c)             (strchr ((str), (c)))
#define CRTL_strrchr(str, c)            (strrchr ((str), (c)))
#define CRTL_strerror(n)                (strerror (n))
#define CRTL_strcmp(s1, s2)             (strcmp ((s1), (s2)))
#define CRTL_strncmp(s1, s2, n)         (strncmp ((s1), (s2), (n)))
#define CRTL_strnicmp(s1, s2, n)        (strnicmp ((s1), (s2), (n)))
#define CRTL_strcasecmp(s1, s2)         (strcasecmp ((s1), (s2)))
#define CRTL_strstr(s1, s2)             (strstr ((s1), (s2)))
#define CRTL_strspn(s1, s2)             (strspn((s1), (s2)))
#define CRTL_strcspn(s1, s2)            (strcspn((s1), (s2)))
#define CRTL_strtol(str, ptr, base)     (strtol((str), (ptr), (base)))
#define CRTL_strtoul(str, ptr, base)    (strtoul((str), (ptr), (base)))
#define CRTL_strtoll( str, ptr, base)   (strtoll( (str), (ptr), (base)))
#define CRTL_strtoull(str, ptr, base)   (strtoull((str), (ptr), (base)))
#define CRTL_strdup(str)                (strdup((str)))

/*
 * ============== ANSI style character classification/translation =============
 */
#define CRTL_isalpha(c)                 (isalpha(c))
#define CRTL_isalnum(c)                 (isalnum(c))
#define CRTL_isdigit(c)                 (isdigit(c))
#define CRTL_islower(c)                 (islower(c))
#define CRTL_isspace(c)                 (isspace(c))
#define CRTL_isupper(c)                 (isupper(c))
#define CRTL_tolower(c)                 (tolower(c))
#define CRTL_toupper(c)                 (toupper(c))
#define CRTL_atoi(str)                  (atoi(str))

/*
 * ==================== ANSI style memory operations ==========================
 */
#define CRTL_memcpy(dst, src, n)        (memcpy ((dst), (src), (n)))
#define CRTL_memcmp(s1, s2, n)          (memcmp ((s1), (s2), (n)))
#define CRTL_memmove(dst, src, n)       (memmove ((dst), (src), (n)))
#define CRTL_memset(dst, v, n)          (memset ((dst), (v), (n)))

/*
 * ==================== ANSI style memory allocation operations ===============
 */
#define CRTL_malloc(sz)         (malloc(sz))
#define CRTL_free(ad)           (free(ad))
#define CRTL_calloc(num, sz)    (calloc((num), (sz)))
#define CRTL_freeif(X) \
    do { \
        if (X != NULL) { \
            CRTL_free(X); \
            X = NULL; \
        } \
    } \
    while(0)

/*
 * ==================== Stream operations =====================================
 */
#define CRTL_fopen(filename, type)      (fopen((filename), (type)))
#define CRTL_fclose(stream)             (fclose(stream))
#define CRTL_fdopen(fd, mode)           (fdopen((fd), (mode)))

#define CRTL_fflush(stream)             (fflush(stream))
#define CRTL_fgetc(stream)              (fgetc(stream))
#define CRTL_fgets(s, n, stream)        (fgets((s), (n), (stream)))
#define CRTL_fileno(stream)             (fileno(stream))
#define CRTL_fprintf                    fprintf
#define CRTL_fputc(c, stream)           (fputc((c), (stream)))
#define CRTL_fputs(s, stream)           (fputs((s), (stream)))
#define CRTL_fread(ptr, size, nitems, stream) (fread((ptr), (size), (nitems), (stream)))
#define CRTL_fseek(stream, offset, ptrname) (fseek((stream), (offset), (ptrname)))
#define CRTL_ftell(stream)              (ftell(stream))
#define CRTL_fwrite(ptr, size, nitems, stream) (fwrite((ptr), (size), (nitems), (stream)))
#define CRTL_printf                     printf
#define CRTL_putw(w, stream)            (putw((w), (stream)))
#define CRTL_puts(s)                    (puts(s))
#define CRTL_setvbuf(stream, buf, mode, size) (setvbuf((stream), (buf), (mode), (size)))
#define CRTL_IONBF                      _IONBF
#define CRTL_IOLBF                      _IOLBF
#define CRTL_sprintf                    sprintf
#define CRTL_sscanf                     sscanf
#define CRTL_vprintf                    vprintf
#define CRTL_vfprintf                   vfprintf
#define CRTL_vsprintf                   vsprintf
#define CRTL_vsscanf                    vsscanf

#define CRTL_stdin                      stdin
#define CRTL_stdout                     stdout
#define CRTL_stderr                     stderr

#define CRTL_offsetof(STRUCTURE,FIELD)  ((int)((char*)&((STRUCTURE*)0)->FIELD))
/*
 * ==================== varargs argument processing ===========================
 */
/* On some systems (e.g. Linux/PPC) the object defined by "va_list ap;"
 * cannot be simply copied and restored (or passed as an argument to
 * a function) to undo any effect of va_arg(). It may be a pointer to
 * a structure and the va_arg() may have changed state in that
 * structure. We use a CRTL_va_copy to cater for this strange case.
 *
 * CRTL_va_init is used in initialise a va_list in the rare case where we
 * don't use va_start or CRTL_va_copy (usually when the value is known not to
 * be used).
 */

#define CRTL_va_copy(a,b)       (a) = (b)
#define CRTL_va_init(a)         (a) = NULL

/*
 * ==================== Miscellaneous operations ==============================
 */
#define CRTL_getErrno()                 (errno)
#define CRTL_setErrno(val)              do { errno = (val); } while (0)
#define CRTL_jmp_buf                    jmp_buf
#define CRTL_setjmp(env)                (setjmp(env))
#define CRTL_longjmp(env, val)          (longjmp((env), (val)))
#define CRTL_perror(s)                  (perror(s))
#define CRTL_qsort(arr, n, siz, comp)   (qsort((arr), (n), (siz), (comp)))

/* Our CRTL_getenv returns const char *, even if the underlying library
 * returns plain char *
 */
#define CRTL_getenv(name)               ((const char *)(getenv(name)))

/* ==========================================================================*/
/*                      END OF MACRO DEFINITIONS                             */
/* ==========================================================================*/

/*
 * Allow target machine to override our default definitions if it wants.
 */
//#include <crtl_core_md.h>

/* ==========================================================================*/
/*                      CRTL PROTOTYPES                                      */
/* ==========================================================================*/

/*
 * If a CRTL macro is undefined (and not redefined) by crtl_md.h, the
 * corresponding default function prototype is supplied below
 */

/*
 * ==================== ANSI style string operations ==========================
 */
#ifndef CRTL_strlen
extern size_t CRTL_strlen(const char *str);
#endif

#ifndef CRTL_strcpy
extern char *CRTL_strcpy(char *dst, const char *src);
#endif

#ifndef CRTL_strncpy
extern char *CRTL_strncpy(char *dst, const char *src, size_t nchars);
#endif

#ifndef CRTL_strcat
extern char *CRTL_strcat(char *dst, const char *src);
#endif

#ifndef CRTL_strncat
extern char *CRTL_strncat(char *dst, const char *src, size_t nchars);
#endif

#ifndef CRTL_strchr
extern char *CRTL_strchr(const char *str, int c);
#endif

#ifndef CRTL_strrchr
extern char *CRTL_strrchr(const char *str, int c);
#endif

#ifndef CRTL_strerror
extern char *CRTL_strerror(int errnum);
#endif

#ifndef CRTL_strcmp
extern int CRTL_strcmp(const char *s1, const char *s2);
#endif

#ifndef CRTL_strncmp
extern int CRTL_strncmp(const char *s1, const char *s2, size_t nchars);
#endif

#ifndef CRTL_strnicmp
extern int CRTL_strnicmp(const char *s1, const char *s2, size_t nchars);
#endif

#ifndef CRTL_strcasecmp
extern int CRTL_strcasecmp(const char *s1, const char *s2);
#endif

#ifndef CRTL_strstr
extern char *CRTL_strstr(const char *s1, const char *s2);
#endif

#ifndef CRTL_strspn
extern size_t CRTL_strspn(const char *s1, const char *s2);
#endif

#ifndef CRTL_strcspn
extern size_t CRTL_strcspn(const char *s1, const char *s2);
#endif

#ifndef CRTL_strtol
extern long CRTL_strtol(const char *str, char **ptr, int base);
#endif

#ifndef CRTL_strtoul
extern unsigned long CRTL_strtoul(const char *str, char **ptr, int base);
#endif

#ifndef CRTL_strtoll
extern int64_t CRTL_strtoll(const char *str, char **ptr, int base);
#endif

#ifndef CRTL_strtoull
extern uint64_t  CRTL_strtoull(const char *str, char **ptr, int base);
#endif

#ifndef CRTL_strdup
extern  char * CRTL_strdup(const char *str);
#endif

/*
 * ============== ANSI style character classification/translation =============
 */
#ifndef CRTL_isascii
extern int CRTL_isascii(int c);
#endif

#ifndef CRTL_isxdigit
extern int CRTL_isxdigit(int c);
#endif

#ifndef CRTL_isalpha
extern int CRTL_isalpha(int c);
#endif

#ifndef CRTL_isalnum
extern int CRTL_isalnum(int c);
#endif

#ifndef CRTL_isdigit
extern int CRTL_isdigit(int c);
#endif

#ifndef CRTL_islower
extern int CRTL_islower(int c);
#endif

#ifndef CRTL_isspace
extern int CRTL_isspace(int c);
#endif

#ifndef CRTL_isupper
extern int CRTL_isupper(int c);
#endif

#ifndef CRTL_tolower
extern int CRTL_tolower(int c);
#endif

#ifndef CRTL_toupper
extern int CRTL_toupper(int c);
#endif

#ifndef CRTL_atoi
extern  int32_t CRTL_atoi(const char *str);
#endif

/*
 * ==================== ANSI style memory operations ==========================
 */
#ifndef CRTL_memcpy
extern void *CRTL_memcpy(void *dst, const void *src, size_t nchars);
#endif

#ifndef CRTL_memcmp
extern int CRTL_memcmp(const void *s1, const void *s2, size_t nchars);
#endif

#ifndef CRTL_memmove
extern void *CRTL_memmove(void *dst, const void *src, size_t nchars);
#endif

#ifndef CRTL_memset
extern void *CRTL_memset(void *dst, int value, size_t nbytes);
#endif

/*
 * ==================== ANSI style memory allocation operations ===============
 */
#ifndef CRTL_malloc
extern void *CRTL_malloc(size_t size);
#endif

#ifndef CRTL_free
extern void CRTL_free(void *ptr);
#endif

#ifndef CRTL_calloc
extern void *CRTL_calloc(size_t num, size_t size);
#endif

#ifndef CRTL_realloc
extern void *CRTL_realloc(void* mem_addr, unsigned int new_size);
#endif

/*
 * ==================== Stream operations =====================================
 */
#ifndef NO_CRTL_STREAMS

#ifndef CRTL_fopen
extern FILE *CRTL_fopen(const char *filename, const char *type);
#endif

#ifndef CRTL_fclose
extern int CRTL_fclose(FILE *stream);
#endif

#ifndef CRTL_fdopen
extern FILE *CRTL_fdopen(int fildes, const char *type);
#endif

#ifndef CRTL_fflush
extern PUBLICSYMBOL int CRTL_fflush(FILE *stream);
#endif

#ifndef CRTL_fgetc
extern int CRTL_fgetc(FILE *stream);
#endif

#ifndef CRTL_fgets
extern char *CRTL_fgets(char *s, int n, FILE *stream);
#endif

#ifndef CRTL_fileno
extern int CRTL_fileno(FILE *stream);
#endif

#ifndef CRTL_fprintf
extern PUBLICSYMBOL int CRTL_fprintf(FILE *stream, const char *fmt, ...);
#endif

#ifndef CRTL_fputc
extern int CRTL_fputc(int c, FILE *stream);
#endif

#ifndef CRTL_fputs
extern int CRTL_fputs(const char *s, FILE *stream);
#endif

#ifndef CRTL_fread
extern size_t CRTL_fread(void *ptr, size_t size, size_t nitems, FILE *stream);
#endif

#ifndef CRTL_fseek
extern int CRTL_fseek(FILE *stream, long offset, int ptrname);
#endif

#ifndef CRTL_ftell
extern long CRTL_ftell(FILE *stream);
#endif

#ifndef CRTL_fwrite
extern size_t CRTL_fwrite(const void *ptr, size_t size, size_t nitems, FILE *stream);
#endif

#ifndef CRTL_printf
extern PUBLICSYMBOL int CRTL_printf(const char *fmt, ...);
#endif

#ifndef CRTL_putw
extern int CRTL_putw(int w, FILE *stream);
#endif

#ifndef CRTL_puts
extern int CRTL_puts(const char *s);
#endif

#ifndef CRTL_setvbuf
extern int CRTL_setvbuf(FILE *stream, char *buf, int type, size_t size);
#endif

#ifndef CRTL_vprintf
extern PUBLICSYMBOL int CRTL_vprintf(const char *fmt, va_list ap);
#endif

#ifndef CRTL_vfprintf
extern PUBLICSYMBOL int CRTL_vfprintf(FILE *stream, const char *fmt, va_list ap);
#endif

#ifndef CRTL_stdin
extern FILE *CRTL_stdin;
#endif

#ifndef CRTL_stdout
extern FILE *CRTL_stdout;
#endif

#ifndef CRTL_stderr
extern FILE *CRTL_stderr;
#endif

#endif

/*
 * ==================== Formatted string operations ==========================
 */

#ifndef CRTL_sprintf
extern PUBLICSYMBOL int CRTL_sprintf(char *s, const char *fmt, ...);
#endif

#ifndef CRTL_sscanf
extern PUBLICSYMBOL int CRTL_sscanf(const char *s, const char *fmt, ...);
#endif

#ifndef CRTL_vsprintf
extern PUBLICSYMBOL int CRTL_vsprintf(char *s, const char *fmt, va_list ap);
#endif

#ifndef CRTL_vsscanf
extern PUBLICSYMBOL int CRTL_vsscanf(const char *s, const char *fmt, va_list ap);
#endif

/*
 * ==================== varargs argument processing ===========================
 */
#ifndef CRTL_va_copy
extern void CRTL_va_copy(va_list dst, va_list src);
#endif
#ifndef CRTL_va_init
extern void CRTL_va_init(va_list a);
#endif

/*
 * ==================== Miscellaneous operations ==============================
 */
#ifndef CRTL_getErrno
extern int CRTL_getErrno();
#endif

#ifndef CRTL_setErrno
extern void CRTL_setErrno(int newVal);
#endif

#ifndef CRTL_setjmp
extern int CRTL_setjmp(CRTL_jmp_buf env);
#endif

#ifndef CRTL_longjmp
extern void CRTL_longjmp(CRTL_jmp_buf env, int val);
#endif

#ifndef CRTL_perror
extern void CRTL_perror(const char *msg);
#endif

#ifndef CRTL_qsort
extern void CRTL_qsort(void *arr, size_t nelems, size_t esize,
                       int (*compFunc)(const void *, const void *));
#endif

#ifndef CRTL_getenv
extern const char *CRTL_getenv(const char *name);
#endif

#ifndef CRTL_wcslen
extern int32_t CRTL_wcslen(const uint16_t* s);
#endif

#ifndef CRTL_wcscmp
extern int32_t CRTL_wcscmp(const uint16_t* s1, const uint16_t* s2);
#endif

#ifndef CRTL_wcscpy
extern int32_t CRTL_wcscpy(uint16_t* s1, const uint16_t* s2);
#endif

#ifndef CRTL_wcscat
extern int32_t CRTL_wcscat(uint16_t* s1, const uint16_t* s2);
#endif


#ifndef CRTL_wstrtoutf8
extern uint32_t CRTL_wstrtoutf8(//utf8 len
                             uint8_t *utf8_ptr,//out
                             uint32_t utf8_buf_len,//in
                             const uint16_t *wstr_ptr,//in
                             uint32_t wstr_len//in
                             );
#endif


#ifdef __cplusplus
} /* extern "C" */
#endif /* __cplusplus */

#endif /* __CRTL_CORE_H__ */

