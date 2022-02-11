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
F_20 ( V_31 ) ;
V_32 -> V_33 . V_28 = V_34 ;
#ifdef F_22
if ( ! V_35 )
asm volatile (".chip 68k/68881\n\t"
"frestore %0@\n\t"
".chip 68k" : : "a" (&zero));
#endif
}
T_2 int F_23 ( struct V_5 * V_6 )
{
return ( - V_36 ) ;
}
T_2 int F_24 ( struct V_5 * V_6 )
{
return F_25 ( V_37 | V_27 | V_38 , F_16 () , V_6 , 0 , NULL , NULL ) ;
}
T_2 int F_26 ( struct V_5 * V_6 )
{
unsigned long V_39 ;
unsigned long V_40 ;
V_39 = V_6 -> V_21 ;
V_40 = V_6 -> V_20 ;
if ( ! V_40 )
V_40 = F_16 () ;
return F_25 ( V_39 , V_40 , V_6 , 0 , NULL , NULL ) ;
}
int F_27 ( unsigned long V_39 ,
unsigned long V_41 , unsigned long V_42 ,
struct V_43 * V_44 , struct V_5 * V_6 )
{
struct V_5 * V_45 ;
struct V_46 * V_47 , * V_48 ;
unsigned long * V_49 ;
V_45 = (struct V_5 * ) ( F_28 ( V_44 ) + V_50 ) - 1 ;
* V_45 = * V_6 ;
V_45 -> V_13 = 0 ;
V_49 = ( ( unsigned long * ) V_6 ) ;
V_48 = ( (struct V_46 * ) V_49 ) - 1 ;
V_47 = ( (struct V_46 * ) V_45 ) - 1 ;
* V_47 = * V_48 ;
V_47 -> V_51 = ( unsigned long ) V_52 ;
V_44 -> V_33 . V_41 = V_41 ;
V_44 -> V_33 . V_53 = ( unsigned long ) V_47 ;
if ( V_39 & V_54 )
F_29 ( V_44 ) -> V_55 = V_6 -> V_17 ;
V_44 -> V_33 . V_28 = F_19 () . V_56 ;
#ifdef F_22
if ( ! V_35 ) {
asm volatile ("fsave %0" : : "m" (p->thread.fpstate[0]) : "memory");
if ( V_44 -> V_33 . V_57 [ 0 ] )
asm volatile ("fmovemx %/fp0-%/fp7,%0\n\t"
"fmoveml %/fpiar/%/fpcr/%/fpsr,%1"
: : "m" (p->thread.fp[0]), "m" (p->thread.fpcntl[0])
: "memory");
asm volatile ("frestore %0" : : "m" (p->thread.fpstate[0]));
}
#endif
return 0 ;
}
int F_30 ( struct V_5 * V_6 , struct V_58 * V_59 )
{
#ifdef F_22
char V_60 [ 216 ] ;
if ( V_35 ) {
int V_61 ;
memcpy ( V_59 -> V_62 , V_32 -> V_33 . V_62 , 12 ) ;
memcpy ( V_59 -> V_63 , V_32 -> V_33 . V_64 , 96 ) ;
for ( V_61 = 0 ; V_61 < 24 ; V_61 += 3 )
V_59 -> V_63 [ V_61 ] = ( ( V_59 -> V_63 [ V_61 ] & 0xffff0000 ) << 15 ) |
( ( V_59 -> V_63 [ V_61 ] & 0x0000ffff ) << 16 ) ;
return 1 ;
}
asm volatile ("fsave %0" :: "m" (fpustate[0]) : "memory");
if ( ! V_60 [ 0 ] )
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
void F_31 ( struct V_5 * V_64 )
{
unsigned long * V_65 ;
unsigned char * V_66 ;
int V_61 ;
F_14 ( V_67 L_7 ) ;
F_14 ( V_67 L_8 , V_32 -> V_68 , V_32 -> V_69 ) ;
if ( V_32 -> V_70 ) {
F_14 ( V_67 L_9 ,
( int ) V_32 -> V_70 -> V_71 ,
( int ) V_32 -> V_70 -> V_72 ,
( int ) V_32 -> V_70 -> V_73 ,
( int ) V_32 -> V_70 -> V_74 ,
( int ) V_32 -> V_70 -> V_74 ,
( int ) V_32 -> V_70 -> V_75 ) ;
F_14 ( V_67 L_10 ,
( int ) V_32 -> V_70 -> V_76 ,
( int ) ( ( ( unsigned long ) V_32 ) + V_50 ) ) ;
}
F_14 ( V_67 L_11 , V_64 -> V_10 ) ;
F_14 ( V_67 L_12 , ( long ) V_64 -> V_11 , ( long ) V_64 ) ;
F_14 ( V_67 L_13 ,
V_64 -> V_13 , V_64 -> V_21 , V_64 -> V_20 , V_64 -> V_19 ) ;
F_14 ( V_67 L_14 ,
V_64 -> V_18 , V_64 -> V_17 , V_64 -> V_16 , V_64 -> V_15 ) ;
F_14 ( V_67 L_15 ,
( unsigned int ) F_16 () , V_64 ) ;
F_14 ( V_67 L_16 ) ;
V_66 = ( ( unsigned char * ) V_64 -> V_10 ) - 0x20 ;
for ( V_65 = ( unsigned long * ) V_66 , V_61 = 0 ; ( V_61 < 0x40 ) ; V_61 += 4 ) {
if ( ( V_61 % 0x10 ) == 0 )
F_14 ( V_67 L_17 , V_66 + V_61 ) ;
F_14 ( L_18 , ( int ) * V_65 ++ ) ;
}
F_14 ( V_67 L_1 ) ;
F_14 ( V_67 L_19 ) ;
V_66 = ( ( unsigned char * ) V_64 ) - 0x40 ;
for ( V_65 = ( unsigned long * ) V_66 , V_61 = 0 ; ( V_61 < 0xc0 ) ; V_61 += 4 ) {
if ( ( V_61 % 0x10 ) == 0 )
F_14 ( V_67 L_17 , V_66 + V_61 ) ;
F_14 ( L_18 , ( int ) * V_65 ++ ) ;
}
F_14 ( V_67 L_1 ) ;
F_14 ( V_67 L_20 ) ;
V_66 = ( unsigned char * ) ( F_16 () - 0x10 ) ;
for ( V_65 = ( unsigned long * ) V_66 , V_61 = 0 ; ( V_61 < 0x80 ) ; V_61 += 4 ) {
if ( ( V_61 % 0x10 ) == 0 )
F_14 ( V_67 L_17 , V_66 + V_61 ) ;
F_14 ( L_18 , ( int ) * V_65 ++ ) ;
}
F_14 ( V_67 L_1 ) ;
}
T_2 int F_32 ( const char * V_77 ,
const char * const * V_78 ,
const char * const * V_79 )
{
int error ;
char * V_80 ;
struct V_5 * V_6 = (struct V_5 * ) & V_77 ;
V_80 = F_33 ( V_77 ) ;
error = F_34 ( V_80 ) ;
if ( F_35 ( V_80 ) )
return error ;
error = F_36 ( V_80 , V_78 , V_79 , V_6 ) ;
F_37 ( V_80 ) ;
return error ;
}
unsigned long F_38 ( struct V_43 * V_44 )
{
unsigned long V_64 , V_10 ;
unsigned long V_81 ;
int V_82 = 0 ;
if ( ! V_44 || V_44 == V_32 || V_44 -> V_83 == V_84 )
return 0 ;
V_81 = ( unsigned long ) V_44 ;
V_64 = ( (struct V_46 * ) V_44 -> V_33 . V_53 ) -> V_85 ;
do {
if ( V_64 < V_81 + sizeof( struct V_86 ) ||
V_64 >= V_50 - 8 + V_81 )
return 0 ;
V_10 = ( ( unsigned long * ) V_64 ) [ 1 ] ;
if ( ! F_39 ( V_10 ) )
return V_10 ;
V_64 = * ( unsigned long * ) V_64 ;
} while ( V_82 ++ < 16 );
return 0 ;
}
unsigned long F_40 ( struct V_43 * V_87 )
{
struct V_46 * V_88 = (struct V_46 * ) V_87 -> V_33 . V_53 ;
if ( F_39 ( V_88 -> V_51 ) )
return ( ( unsigned long * ) V_88 -> V_85 ) [ 1 ] ;
else
return V_88 -> V_51 ;
}
