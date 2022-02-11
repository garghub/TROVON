unsigned long F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = (struct V_3 * ) V_2 -> V_5 . V_6 ;
if ( F_2 ( V_4 -> V_7 ) )
return ( ( unsigned long * ) V_4 -> V_8 ) [ 1 ] ;
else
return V_4 -> V_7 ;
}
static void F_3 ( void )
{
if ( ! F_4 () )
#if F_5 ( V_9 )
__asm__("stop #0x2200" : : : "cc");
#else
__asm__("stop #0x2000" : : : "cc");
#endif
}
void F_6 ( void )
{
while ( 1 ) {
while ( ! F_4 () )
F_7 () ;
F_8 () ;
F_9 () ;
F_10 () ;
}
}
void F_11 ( char * V_10 )
{
if ( V_11 )
V_11 () ;
for (; ; ) ;
}
void F_12 ( void )
{
if ( V_12 )
V_12 () ;
for (; ; ) ;
}
void F_13 ( void )
{
if ( V_13 )
V_13 () ;
for (; ; ) ;
}
void F_14 ( struct V_14 * V_15 )
{
F_15 ( L_1 ) ;
F_15 ( L_2 ,
V_15 -> V_16 , V_15 -> V_17 , V_15 -> V_18 , V_15 -> V_19 , F_16 () ) ;
F_15 ( L_3 ,
V_15 -> V_20 , V_15 -> V_21 , V_15 -> V_22 , V_15 -> V_23 ) ;
F_15 ( L_4 ,
V_15 -> V_24 , V_15 -> V_25 , V_15 -> V_26 ) ;
F_15 ( L_5 ,
V_15 -> V_27 , V_15 -> V_28 , V_15 -> V_29 ) ;
if ( ! ( V_15 -> V_19 & V_30 ) )
F_15 ( L_6 , F_17 () ) ;
}
int F_18 ( int (* F_19)( void * ) , void * V_31 , unsigned long V_32 )
{
int V_33 ;
T_1 V_34 ;
V_34 = F_20 () ;
F_21 ( V_35 ) ;
{
register long T_2 V_36 ( L_7 ) ;
register long T_3 V_36 ( L_8 ) = V_32 | V_37 | V_38 ;
T_2 = V_39 ;
__asm__ __volatile__
("clrl %%d2\n\t"
"trap #0\n\t"
"tstl %0\n\t"
"jne 1f\n\t"
"lea %%sp@(%c7),%6\n\t"
"movel %6@,%6\n\t"
"movel %3,%%sp@-\n\t"
"jsr %4@\n\t"
"movel %0,%%d1\n\t"
"movel %2,%%d0\n\t"
"trap #0\n"
"1:"
: "+d" (retval)
: "i" (__NR_clone), "i" (__NR_exit),
"r" (arg), "a" (fn), "d" (clone_arg), "r" (current),
"i" (-THREAD_SIZE)
: "d2");
V_33 = T_2 ;
}
F_21 ( V_34 ) ;
return V_33 ;
}
void F_22 ( void )
{
unsigned long V_40 = 0 ;
F_21 ( V_41 ) ;
V_42 -> V_5 . V_34 = V_43 ;
if ( ! V_44 )
asm volatile (".chip 68k/68881\n\t"
"frestore %0@\n\t"
".chip 68k" : : "a" (&zero));
}
T_4 int F_23 ( struct V_14 * V_15 )
{
return F_24 ( V_45 , F_17 () , V_15 , 0 , NULL , NULL ) ;
}
T_4 int F_25 ( struct V_14 * V_15 )
{
return F_24 ( V_46 | V_37 | V_45 , F_17 () , V_15 , 0 ,
NULL , NULL ) ;
}
T_4 int F_26 ( struct V_14 * V_15 )
{
unsigned long V_47 ;
unsigned long V_48 ;
int T_5 * V_49 , * V_50 ;
V_47 = V_15 -> V_29 ;
V_48 = V_15 -> V_28 ;
V_49 = ( int T_5 * ) V_15 -> V_27 ;
V_50 = ( int T_5 * ) V_15 -> V_26 ;
if ( ! V_48 )
V_48 = F_17 () ;
return F_24 ( V_47 , V_48 , V_15 , 0 ,
V_49 , V_50 ) ;
}
int F_27 ( unsigned long V_47 , unsigned long V_51 ,
unsigned long V_52 ,
struct V_1 * V_53 , struct V_14 * V_15 )
{
struct V_14 * V_54 ;
struct V_3 * V_55 , * V_56 ;
unsigned long * V_57 ;
V_54 = (struct V_14 * ) ( F_28 ( V_53 ) + V_58 ) - 1 ;
* V_54 = * V_15 ;
V_54 -> V_21 = 0 ;
V_57 = ( ( unsigned long * ) V_15 ) ;
V_56 = ( (struct V_3 * ) V_57 ) - 1 ;
V_55 = ( (struct V_3 * ) V_54 ) - 1 ;
* V_55 = * V_56 ;
V_55 -> V_7 = ( unsigned long ) V_59 ;
V_53 -> V_5 . V_51 = V_51 ;
V_53 -> V_5 . V_6 = ( unsigned long ) V_55 ;
if ( V_47 & V_60 )
F_29 ( V_53 ) -> V_61 = V_15 -> V_25 ;
V_53 -> V_5 . V_34 = F_20 () . V_62 ;
if ( ! V_44 ) {
asm volatile ("fsave %0" : : "m" (p->thread.fpstate[0]) : "memory");
if ( ! V_63 ? V_53 -> V_5 . V_64 [ 0 ] : V_53 -> V_5 . V_64 [ 2 ] )
asm volatile ("fmovemx %/fp0-%/fp7,%0\n\t"
"fmoveml %/fpiar/%/fpcr/%/fpsr,%1"
: : "m" (p->thread.fp[0]), "m" (p->thread.fpcntl[0])
: "memory");
asm volatile ("frestore %0" : : "m" (p->thread.fpstate[0]));
}
return 0 ;
}
int F_30 ( struct V_14 * V_15 , struct V_65 * V_66 )
{
char V_67 [ 216 ] ;
if ( V_44 ) {
int V_68 ;
memcpy ( V_66 -> V_69 , V_42 -> V_5 . V_69 , 12 ) ;
memcpy ( V_66 -> V_70 , V_42 -> V_5 . V_71 , 96 ) ;
for ( V_68 = 0 ; V_68 < 24 ; V_68 += 3 )
V_66 -> V_70 [ V_68 ] = ( ( V_66 -> V_70 [ V_68 ] & 0xffff0000 ) << 15 ) |
( ( V_66 -> V_70 [ V_68 ] & 0x0000ffff ) << 16 ) ;
return 1 ;
}
asm volatile ("fsave %0" :: "m" (fpustate[0]) : "memory");
if ( ! V_63 ? ! V_67 [ 0 ] : ! V_67 [ 2 ] )
return 0 ;
asm volatile ("fmovem %/fpiar/%/fpcr/%/fpsr,%0"
:: "m" (fpu->fpcntl[0])
: "memory");
asm volatile ("fmovemx %/fp0-%/fp7,%0"
:: "m" (fpu->fpregs[0])
: "memory");
return 1 ;
}
T_4 int F_31 ( const char T_5 * V_72 ,
const char T_5 * const T_5 * V_73 ,
const char T_5 * const T_5 * V_74 )
{
int error ;
char * V_75 ;
struct V_14 * V_15 = (struct V_14 * ) & V_72 ;
V_75 = F_32 ( V_72 ) ;
error = F_33 ( V_75 ) ;
if ( F_34 ( V_75 ) )
return error ;
error = F_35 ( V_75 , V_73 , V_74 , V_15 ) ;
F_36 ( V_75 ) ;
return error ;
}
unsigned long F_37 ( struct V_1 * V_53 )
{
unsigned long V_71 , V_18 ;
unsigned long V_76 ;
int V_77 = 0 ;
if ( ! V_53 || V_53 == V_42 || V_53 -> V_78 == V_79 )
return 0 ;
V_76 = ( unsigned long ) F_28 ( V_53 ) ;
V_71 = ( (struct V_3 * ) V_53 -> V_5 . V_6 ) -> V_8 ;
do {
if ( V_71 < V_76 + sizeof( struct V_80 ) ||
V_71 >= 8184 + V_76 )
return 0 ;
V_18 = ( ( unsigned long * ) V_71 ) [ 1 ] ;
if ( ! F_2 ( V_18 ) )
return V_18 ;
V_71 = * ( unsigned long * ) V_71 ;
} while ( V_77 ++ < 16 );
return 0 ;
}
