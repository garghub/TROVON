void F_1 ( void )
{
for (; ; ) {
if ( V_1 ) {
static int V_2 = V_3 ;
static unsigned long V_4 ;
static unsigned long V_5 ;
static unsigned long V_6 ;
unsigned long V_7 ;
unsigned long V_8 ;
extern unsigned long V_9 ;
extern void V_10 ( void ) ;
F_2 () ;
V_7 = V_11 ;
V_2 -= ( V_7 - V_4 ) ;
V_4 = V_7 ;
if ( V_2 < 0 ) {
V_2 += V_3 ;
V_8 = V_9 ;
V_6 = ( V_6 + ( V_8 - V_5 ) ) >> 1 ;
V_5 = V_8 ;
#if 0
printk("kernel faults / second = %ld\n", fps);
#endif
if ( V_6 >= V_12 ) {
V_10 () ;
}
}
F_3 () ;
}
if ( V_13 ) {
while ( ! F_4 () )
(* V_13)() ;
} else {
while ( ! F_4 () )
F_5 () ;
}
F_6 () ;
F_7 () ;
}
}
void F_1 ( void )
{
F_8 ( V_14 ) ;
while( 1 ) {
#ifdef F_9
if ( V_13 ) {
while ( ! F_4 () )
(* V_13)() ;
} else
#endif
{
while ( ! F_4 () )
F_5 () ;
}
F_6 () ;
F_7 () ;
}
}
void F_10 ( void )
{
F_3 () ;
F_11 ( 8 ) ;
F_2 () ;
F_12 () ;
F_13 ( L_1 ) ;
}
void F_14 ( char * V_15 )
{
char * V_16 ;
F_3 () ;
F_11 ( 8 ) ;
F_2 () ;
V_16 = strchr ( V_17 , '\n' ) ;
if ( V_16 ) * V_16 = 0 ;
if ( V_15 )
F_15 ( V_15 ) ;
if ( * V_17 )
F_15 ( V_17 ) ;
F_16 ( L_2 ) ;
F_13 ( L_3 ) ;
}
void F_17 ( void )
{
if ( V_18 &&
( strcmp ( V_19 -> type , L_4 ) || V_20 ) )
* V_18 |= V_21 ;
F_10 () ;
}
void F_18 ( struct V_22 * V_23 )
{
struct V_24 * V_25 = (struct V_24 * ) V_23 -> V_26 [ 14 ] ;
F_19 ( L_5 ,
V_23 -> V_27 , V_23 -> V_28 , V_23 -> V_29 , V_23 -> V_30 , F_20 () ) ;
F_19 ( L_6 , ( void * ) V_23 -> V_28 ) ;
F_19 ( L_7 ,
V_23 -> V_26 [ 0 ] , V_23 -> V_26 [ 1 ] , V_23 -> V_26 [ 2 ] , V_23 -> V_26 [ 3 ] ,
V_23 -> V_26 [ 4 ] , V_23 -> V_26 [ 5 ] , V_23 -> V_26 [ 6 ] , V_23 -> V_26 [ 7 ] ) ;
F_19 ( L_8 ,
V_23 -> V_26 [ 8 ] , V_23 -> V_26 [ 9 ] , V_23 -> V_26 [ 10 ] , V_23 -> V_26 [ 11 ] ,
V_23 -> V_26 [ 12 ] , V_23 -> V_26 [ 13 ] , V_23 -> V_26 [ 14 ] , V_23 -> V_26 [ 15 ] ) ;
F_19 ( L_9 , ( void * ) V_23 -> V_26 [ 15 ] ) ;
F_19 ( L_10 ,
V_25 -> V_31 [ 0 ] , V_25 -> V_31 [ 1 ] , V_25 -> V_31 [ 2 ] , V_25 -> V_31 [ 3 ] ,
V_25 -> V_31 [ 4 ] , V_25 -> V_31 [ 5 ] , V_25 -> V_31 [ 6 ] , V_25 -> V_31 [ 7 ] ) ;
F_19 ( L_11 ,
V_25 -> V_32 [ 0 ] , V_25 -> V_32 [ 1 ] , V_25 -> V_32 [ 2 ] , V_25 -> V_32 [ 3 ] ,
V_25 -> V_32 [ 4 ] , V_25 -> V_32 [ 5 ] , V_25 -> V_32 [ 6 ] , V_25 -> V_32 [ 7 ] ) ;
}
void F_21 ( struct V_33 * V_34 , unsigned long * V_35 )
{
unsigned long V_28 , V_36 ;
unsigned long V_37 ;
struct V_24 * V_25 ;
int V_2 = 0 ;
if ( V_34 != NULL )
V_37 = ( unsigned long ) F_22 ( V_34 ) ;
else
V_37 = ( unsigned long ) F_23 () ;
V_36 = ( unsigned long ) V_35 ;
do {
if ( V_36 < ( V_37 + sizeof( struct V_38 ) ) ||
V_36 >= ( V_37 + ( V_39 << 1 ) ) )
break;
V_25 = (struct V_24 * ) V_36 ;
V_28 = V_25 -> V_32 [ 7 ] ;
F_19 ( L_12 , V_28 ) ;
F_19 ( L_13 , ( void * ) V_28 ) ;
V_36 = V_25 -> V_32 [ 6 ] ;
} while ( ++ V_2 < 16 );
F_19 ( L_14 ) ;
}
void F_24 ( void )
{
unsigned long * V_40 ;
__asm__ __volatile__("mov %%fp, %0"
: "=r" (ksp));
F_21 ( V_41 , V_40 ) ;
}
unsigned long F_25 ( struct V_33 * V_34 )
{
return F_26 ( V_34 ) -> V_42 ;
}
static inline struct V_43 T_1 *
F_27 ( struct V_43 T_1 * V_44 ,
struct V_43 T_1 * V_45 )
{
unsigned long V_46 , V_36 ;
struct V_43 * V_47 ;
struct V_43 T_1 * V_48 ;
if ( F_28 ( V_47 , & V_45 -> V_36 ) )
return NULL ;
V_36 = ( unsigned long ) V_47 ;
V_46 = ( V_36 - ( ( unsigned long ) V_45 ) ) ;
V_36 = ( unsigned long ) V_44 ;
V_48 = (struct V_43 T_1 * ) ( V_36 - V_46 ) ;
if ( F_29 ( V_48 , V_45 , V_46 ) )
V_48 = NULL ;
else if ( F_30 ( V_36 , & V_48 -> V_36 ) )
V_48 = NULL ;
return V_48 ;
}
T_2 int F_31 ( unsigned long V_49 ,
unsigned long V_50 ,
struct V_22 * V_51 ,
unsigned long V_52 )
{
unsigned long V_53 , V_54 ;
unsigned long V_55 = V_51 -> V_26 [ V_56 ] ;
long V_57 ;
V_53 = V_51 -> V_26 [ V_58 ] ;
V_54 = V_51 -> V_26 [ V_59 ] ;
V_57 = F_32 ( V_49 , V_50 ,
V_51 , V_52 ,
( int T_1 * ) V_53 ,
( int T_1 * ) V_54 ) ;
if ( ( unsigned long ) V_57 >= - V_60 )
V_51 -> V_26 [ V_56 ] = V_55 ;
return V_57 ;
}
int F_33 ( struct V_22 * V_51 , T_3 * V_61 )
{
if ( F_34 () ) {
memset ( V_61 , 0 , sizeof( * V_61 ) ) ;
V_61 -> V_62 = 8 ;
return 1 ;
}
#ifdef F_35
if ( F_36 ( V_63 ) ) {
F_37 ( F_38 () | V_64 ) ;
F_39 ( & V_41 -> V_65 . V_66 [ 0 ] , & V_41 -> V_65 . V_67 ,
& V_41 -> V_65 . V_68 [ 0 ] , & V_41 -> V_65 . V_69 ) ;
if ( V_51 != NULL ) {
V_51 -> V_27 &= ~ ( V_64 ) ;
F_40 ( V_63 ) ;
}
}
#else
if ( V_41 == V_70 ) {
F_37 ( F_38 () | V_64 ) ;
F_39 ( & V_41 -> V_65 . V_66 [ 0 ] , & V_41 -> V_65 . V_67 ,
& V_41 -> V_65 . V_68 [ 0 ] , & V_41 -> V_65 . V_69 ) ;
if ( V_51 != NULL ) {
V_51 -> V_27 &= ~ ( V_64 ) ;
V_70 = NULL ;
}
}
#endif
memcpy ( & V_61 -> V_71 . V_72 [ 0 ] ,
& V_41 -> V_65 . V_66 [ 0 ] ,
(sizeof( unsigned long ) * 32 ) ) ;
V_61 -> V_73 = V_41 -> V_65 . V_67 ;
V_61 -> V_74 = V_41 -> V_65 . V_69 ;
V_61 -> V_62 = 8 ;
V_61 -> V_75 = 1 ;
if( V_61 -> V_74 != 0 ) {
memcpy ( & V_61 -> V_76 [ 0 ] ,
& V_41 -> V_65 . V_68 [ 0 ] ,
sizeof( struct V_77 ) * V_61 -> V_74 ) ;
}
memset ( & V_61 -> V_76 [ V_61 -> V_74 ] , 0 ,
sizeof( struct V_77 ) * ( 32 - V_61 -> V_74 ) ) ;
return 1 ;
}
T_2 int F_41 ( struct V_22 * V_51 )
{
int error , V_78 = 0 ;
char * V_79 ;
if( V_51 -> V_26 [ V_80 ] == 0 )
V_78 = 1 ;
V_79 = F_42 ( ( char T_1 * ) V_51 -> V_26 [ V_78 + V_81 ] ) ;
error = F_43 ( V_79 ) ;
if( F_44 ( V_79 ) )
goto V_82;
error = F_45 ( V_79 ,
( const char T_1 * const T_1 * )
V_51 -> V_26 [ V_78 + V_56 ] ,
( const char T_1 * const T_1 * )
V_51 -> V_26 [ V_78 + V_58 ] ,
V_51 ) ;
F_46 ( V_79 ) ;
V_82:
return error ;
}
T_4 F_47 ( int (* F_48)( void * ) , void * V_83 , unsigned long V_84 )
{
long V_85 ;
__asm__ __volatile__("mov %4, %%g2\n\t"
"mov %5, %%g3\n\t"
"mov %1, %%g1\n\t"
"mov %2, %%o0\n\t"
"mov 0, %%o1\n\t"
"t 0x10\n\t"
"cmp %%o1, 0\n\t"
"be 1f\n\t"
" nop\n\t"
"jmpl %%g2, %%o7\n\t"
" mov %%g3, %%o0\n\t"
"mov %3, %%g1\n\t"
"t 0x10\n\t"
"1: mov %%o0, %0\n\t" :
"=r" (retval) :
"i" (__NR_clone), "r" (flags | CLONE_VM | CLONE_UNTRACED),
"i" (__NR_exit), "r" (fn), "r" (arg) :
"g1", "g2", "g3", "o0", "o1", "memory", "cc");
return V_85 ;
}
unsigned long F_49 ( struct V_33 * V_86 )
{
unsigned long V_28 , V_36 , V_87 = 0 ;
unsigned long V_37 = ( unsigned long ) V_86 ;
unsigned long V_57 = 0 ;
struct V_24 * V_25 ;
int V_2 = 0 ;
if ( ! V_86 || V_86 == V_41 ||
V_86 -> V_88 == V_89 )
goto V_82;
V_36 = F_26 ( V_86 ) -> V_40 + V_87 ;
do {
if ( V_36 < ( V_37 + sizeof( struct V_38 ) ) ||
V_36 >= ( V_37 + ( 2 * V_39 ) ) )
break;
V_25 = (struct V_24 * ) V_36 ;
V_28 = V_25 -> V_32 [ 7 ] ;
if ( ! F_50 ( V_28 ) ) {
V_57 = V_28 ;
goto V_82;
}
V_36 = V_25 -> V_32 [ 6 ] + V_87 ;
} while ( ++ V_2 < 16 );
V_82:
return V_57 ;
}
