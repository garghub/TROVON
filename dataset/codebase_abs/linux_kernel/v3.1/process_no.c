static void F_1 ( void )
{
F_2 () ;
while ( ! F_3 () ) {
__asm__("stop #0x2000" : : : "cc");
F_2 () ;
}
F_4 () ;
}
void F_5 ( void )
{
while ( 1 ) {
F_6 () ;
F_7 () ;
F_8 () ;
F_9 () ;
}
}
void F_10 ( char * V_1 )
{
if ( V_2 )
V_2 () ;
for (; ; ) ;
}
void F_11 ( void )
{
if ( V_3 )
V_3 () ;
for (; ; ) ;
}
void F_12 ( void )
{
if ( V_4 )
V_4 () ;
for (; ; ) ;
}
void F_13 ( struct V_5 * V_6 )
{
F_14 ( V_7 L_1 ) ;
F_14 ( V_7 L_2 ,
V_6 -> V_8 , V_6 -> V_9 , V_6 -> V_10 , V_6 -> V_11 , F_15 () ) ;
F_14 ( V_7 L_3 ,
V_6 -> V_12 , V_6 -> V_13 , V_6 -> V_14 , V_6 -> V_15 ) ;
F_14 ( V_7 L_4 ,
V_6 -> V_16 , V_6 -> V_17 , V_6 -> V_18 ) ;
F_14 ( V_7 L_5 ,
V_6 -> V_19 , V_6 -> V_20 , V_6 -> V_21 ) ;
if ( ! ( V_6 -> V_11 & V_22 ) )
F_14 ( V_7 L_6 , F_16 () ) ;
}
int F_17 ( int (* F_18)( void * ) , void * V_23 , unsigned long V_24 )
{
int V_25 ;
long V_26 = V_24 | V_27 ;
T_1 V_28 ;
V_28 = F_19 () ;
F_20 ( V_29 ) ;
__asm__ __volatile__ (
"movel %%sp, %%d2\n\t"
"movel %5, %%d1\n\t"
"movel %1, %%d0\n\t"
"trap #0\n\t"
"cmpl %%sp, %%d2\n\t"
"jeq 1f\n\t"
"movel %3, %%sp@-\n\t"
"jsr %4@\n\t"
"movel %2, %%d0\n\t"
"trap #0\n"
"1:\n\t"
"movel %%d0, %0\n"
: "=d" (retval)
: "i" (__NR_clone),
"i" (__NR_exit),
"a" (arg),
"a" (fn),
"a" (clone_arg)
: "cc", "%d0", "%d1", "%d2");
F_20 ( V_28 ) ;
return V_25 ;
}
void F_21 ( void )
{
#ifdef F_22
unsigned long V_30 = 0 ;
#endif
V_31 -> V_32 . V_28 = V_33 ;
#ifdef F_22
if ( ! V_34 )
asm volatile (".chip 68k/68881\n\t"
"frestore %0@\n\t"
".chip 68k" : : "a" (&zero));
#endif
}
T_2 int F_23 ( struct V_5 * V_6 )
{
return ( - V_35 ) ;
}
T_2 int F_24 ( struct V_5 * V_6 )
{
return F_25 ( V_36 | V_27 | V_37 , F_16 () , V_6 , 0 , NULL , NULL ) ;
}
T_2 int F_26 ( struct V_5 * V_6 )
{
unsigned long V_38 ;
unsigned long V_39 ;
V_38 = V_6 -> V_21 ;
V_39 = V_6 -> V_20 ;
if ( ! V_39 )
V_39 = F_16 () ;
return F_25 ( V_38 , V_39 , V_6 , 0 , NULL , NULL ) ;
}
int F_27 ( unsigned long V_38 ,
unsigned long V_40 , unsigned long V_41 ,
struct V_42 * V_43 , struct V_5 * V_6 )
{
struct V_5 * V_44 ;
struct V_45 * V_46 , * V_47 ;
unsigned long * V_48 ;
V_44 = (struct V_5 * ) ( F_28 ( V_43 ) + V_49 ) - 1 ;
* V_44 = * V_6 ;
V_44 -> V_13 = 0 ;
V_48 = ( ( unsigned long * ) V_6 ) ;
V_47 = ( (struct V_45 * ) V_48 ) - 1 ;
V_46 = ( (struct V_45 * ) V_44 ) - 1 ;
* V_46 = * V_47 ;
V_46 -> V_50 = ( unsigned long ) V_51 ;
V_43 -> V_32 . V_40 = V_40 ;
V_43 -> V_32 . V_52 = ( unsigned long ) V_46 ;
if ( V_38 & V_53 )
F_29 ( V_43 ) -> V_54 = V_6 -> V_17 ;
V_43 -> V_32 . V_28 = F_19 () . V_55 ;
#ifdef F_22
if ( ! V_34 ) {
asm volatile ("fsave %0" : : "m" (p->thread.fpstate[0]) : "memory");
if ( V_43 -> V_32 . V_56 [ 0 ] )
asm volatile ("fmovemx %/fp0-%/fp7,%0\n\t"
"fmoveml %/fpiar/%/fpcr/%/fpsr,%1"
: : "m" (p->thread.fp[0]), "m" (p->thread.fpcntl[0])
: "memory");
asm volatile ("frestore %0" : : "m" (p->thread.fpstate[0]));
}
#endif
return 0 ;
}
int F_30 ( struct V_5 * V_6 , struct V_57 * V_58 )
{
#ifdef F_22
char V_59 [ 216 ] ;
if ( V_34 ) {
int V_60 ;
memcpy ( V_58 -> V_61 , V_31 -> V_32 . V_61 , 12 ) ;
memcpy ( V_58 -> V_62 , V_31 -> V_32 . V_63 , 96 ) ;
for ( V_60 = 0 ; V_60 < 24 ; V_60 += 3 )
V_58 -> V_62 [ V_60 ] = ( ( V_58 -> V_62 [ V_60 ] & 0xffff0000 ) << 15 ) |
( ( V_58 -> V_62 [ V_60 ] & 0x0000ffff ) << 16 ) ;
return 1 ;
}
asm volatile ("fsave %0" :: "m" (fpustate[0]) : "memory");
if ( ! V_59 [ 0 ] )
return 0 ;
asm volatile ("fmovem %/fpiar/%/fpcr/%/fpsr,%0"
:: "m" (fpu->fpcntl[0])
: "memory");
asm volatile ("fmovemx %/fp0-%/fp7,%0"
:: "m" (fpu->fpregs[0])
: "memory");
#endif
return 1 ;
}
void F_31 ( struct V_5 * V_63 )
{
unsigned long * V_64 ;
unsigned char * V_65 ;
int V_60 ;
F_14 ( V_66 L_7 ) ;
F_14 ( V_66 L_8 , V_31 -> V_67 , V_31 -> V_68 ) ;
if ( V_31 -> V_69 ) {
F_14 ( V_66 L_9 ,
( int ) V_31 -> V_69 -> V_70 ,
( int ) V_31 -> V_69 -> V_71 ,
( int ) V_31 -> V_69 -> V_72 ,
( int ) V_31 -> V_69 -> V_73 ,
( int ) V_31 -> V_69 -> V_73 ,
( int ) V_31 -> V_69 -> V_74 ) ;
F_14 ( V_66 L_10 ,
( int ) V_31 -> V_69 -> V_75 ,
( int ) ( ( ( unsigned long ) V_31 ) + V_49 ) ) ;
}
F_14 ( V_66 L_11 , V_63 -> V_10 ) ;
F_14 ( V_66 L_12 , ( long ) V_63 -> V_11 , ( long ) V_63 ) ;
F_14 ( V_66 L_13 ,
V_63 -> V_13 , V_63 -> V_21 , V_63 -> V_20 , V_63 -> V_19 ) ;
F_14 ( V_66 L_14 ,
V_63 -> V_18 , V_63 -> V_17 , V_63 -> V_16 , V_63 -> V_15 ) ;
F_14 ( V_66 L_15 ,
( unsigned int ) F_16 () , V_63 ) ;
F_14 ( V_66 L_16 ) ;
V_65 = ( ( unsigned char * ) V_63 -> V_10 ) - 0x20 ;
for ( V_64 = ( unsigned long * ) V_65 , V_60 = 0 ; ( V_60 < 0x40 ) ; V_60 += 4 ) {
if ( ( V_60 % 0x10 ) == 0 )
F_14 ( V_66 L_17 , V_65 + V_60 ) ;
F_14 ( L_18 , ( int ) * V_64 ++ ) ;
}
F_14 ( V_66 L_1 ) ;
F_14 ( V_66 L_19 ) ;
V_65 = ( ( unsigned char * ) V_63 ) - 0x40 ;
for ( V_64 = ( unsigned long * ) V_65 , V_60 = 0 ; ( V_60 < 0xc0 ) ; V_60 += 4 ) {
if ( ( V_60 % 0x10 ) == 0 )
F_14 ( V_66 L_17 , V_65 + V_60 ) ;
F_14 ( L_18 , ( int ) * V_64 ++ ) ;
}
F_14 ( V_66 L_1 ) ;
F_14 ( V_66 L_20 ) ;
V_65 = ( unsigned char * ) ( F_16 () - 0x10 ) ;
for ( V_64 = ( unsigned long * ) V_65 , V_60 = 0 ; ( V_60 < 0x80 ) ; V_60 += 4 ) {
if ( ( V_60 % 0x10 ) == 0 )
F_14 ( V_66 L_17 , V_65 + V_60 ) ;
F_14 ( L_18 , ( int ) * V_64 ++ ) ;
}
F_14 ( V_66 L_1 ) ;
}
T_2 int F_32 ( const char * V_76 ,
const char * const * V_77 ,
const char * const * V_78 )
{
int error ;
char * V_79 ;
struct V_5 * V_6 = (struct V_5 * ) & V_76 ;
V_79 = F_33 ( V_76 ) ;
error = F_34 ( V_79 ) ;
if ( F_35 ( V_79 ) )
return error ;
error = F_36 ( V_79 , V_77 , V_78 , V_6 ) ;
F_37 ( V_79 ) ;
return error ;
}
unsigned long F_38 ( struct V_42 * V_43 )
{
unsigned long V_63 , V_10 ;
unsigned long V_80 ;
int V_81 = 0 ;
if ( ! V_43 || V_43 == V_31 || V_43 -> V_82 == V_83 )
return 0 ;
V_80 = ( unsigned long ) V_43 ;
V_63 = ( (struct V_45 * ) V_43 -> V_32 . V_52 ) -> V_84 ;
do {
if ( V_63 < V_80 + sizeof( struct V_85 ) ||
V_63 >= V_49 - 8 + V_80 )
return 0 ;
V_10 = ( ( unsigned long * ) V_63 ) [ 1 ] ;
if ( ! F_39 ( V_10 ) )
return V_10 ;
V_63 = * ( unsigned long * ) V_63 ;
} while ( V_81 ++ < 16 );
return 0 ;
}
unsigned long F_40 ( struct V_42 * V_86 )
{
struct V_45 * V_87 = (struct V_45 * ) V_86 -> V_32 . V_52 ;
if ( F_39 ( V_87 -> V_50 ) )
return ( ( unsigned long * ) V_87 -> V_84 ) [ 1 ] ;
else
return V_87 -> V_50 ;
}
