void F_1 ( void )
{
F_2 ( V_1 ) ;
for (; ; ) {
while ( ! F_3 () ) {
if ( V_2 )
(* V_2)() ;
else
F_4 () ;
}
F_5 () ;
}
}
void F_6 ( void )
{
F_7 () ;
F_8 ( 8 ) ;
F_9 () ;
F_10 () ;
F_11 ( L_1 ) ;
}
void F_12 ( char * V_3 )
{
char * V_4 ;
F_7 () ;
F_8 ( 8 ) ;
F_9 () ;
V_4 = strchr ( V_5 , '\n' ) ;
if ( V_4 ) * V_4 = 0 ;
if ( V_3 )
F_13 ( V_3 ) ;
if ( * V_5 )
F_13 ( V_5 ) ;
F_14 ( L_2 ) ;
F_11 ( L_3 ) ;
}
void F_15 ( void )
{
if ( V_6 &&
( strcmp ( V_7 -> type , L_4 ) || V_8 ) )
* V_6 |= V_9 ;
F_6 () ;
}
void F_16 ( struct V_10 * V_11 )
{
struct V_12 * V_13 = (struct V_12 * ) V_11 -> V_14 [ 14 ] ;
F_17 ( L_5 ,
V_11 -> V_15 , V_11 -> V_16 , V_11 -> V_17 , V_11 -> V_18 , F_18 () ) ;
F_17 ( L_6 , ( void * ) V_11 -> V_16 ) ;
F_17 ( L_7 ,
V_11 -> V_14 [ 0 ] , V_11 -> V_14 [ 1 ] , V_11 -> V_14 [ 2 ] , V_11 -> V_14 [ 3 ] ,
V_11 -> V_14 [ 4 ] , V_11 -> V_14 [ 5 ] , V_11 -> V_14 [ 6 ] , V_11 -> V_14 [ 7 ] ) ;
F_17 ( L_8 ,
V_11 -> V_14 [ 8 ] , V_11 -> V_14 [ 9 ] , V_11 -> V_14 [ 10 ] , V_11 -> V_14 [ 11 ] ,
V_11 -> V_14 [ 12 ] , V_11 -> V_14 [ 13 ] , V_11 -> V_14 [ 14 ] , V_11 -> V_14 [ 15 ] ) ;
F_17 ( L_9 , ( void * ) V_11 -> V_14 [ 15 ] ) ;
F_17 ( L_10 ,
V_13 -> V_19 [ 0 ] , V_13 -> V_19 [ 1 ] , V_13 -> V_19 [ 2 ] , V_13 -> V_19 [ 3 ] ,
V_13 -> V_19 [ 4 ] , V_13 -> V_19 [ 5 ] , V_13 -> V_19 [ 6 ] , V_13 -> V_19 [ 7 ] ) ;
F_17 ( L_11 ,
V_13 -> V_20 [ 0 ] , V_13 -> V_20 [ 1 ] , V_13 -> V_20 [ 2 ] , V_13 -> V_20 [ 3 ] ,
V_13 -> V_20 [ 4 ] , V_13 -> V_20 [ 5 ] , V_13 -> V_20 [ 6 ] , V_13 -> V_20 [ 7 ] ) ;
}
void F_19 ( struct V_21 * V_22 , unsigned long * V_23 )
{
unsigned long V_16 , V_24 ;
unsigned long V_25 ;
struct V_12 * V_13 ;
int V_26 = 0 ;
if ( V_22 != NULL )
V_25 = ( unsigned long ) F_20 ( V_22 ) ;
else
V_25 = ( unsigned long ) F_21 () ;
V_24 = ( unsigned long ) V_23 ;
do {
if ( V_24 < ( V_25 + sizeof( struct V_27 ) ) ||
V_24 >= ( V_25 + ( V_28 << 1 ) ) )
break;
V_13 = (struct V_12 * ) V_24 ;
V_16 = V_13 -> V_20 [ 7 ] ;
F_17 ( L_12 , V_16 ) ;
F_17 ( L_13 , ( void * ) V_16 ) ;
V_24 = V_13 -> V_20 [ 6 ] ;
} while ( ++ V_26 < 16 );
F_17 ( L_14 ) ;
}
void F_22 ( void )
{
unsigned long * V_29 ;
__asm__ __volatile__("mov %%fp, %0"
: "=r" (ksp));
F_19 ( V_30 , V_29 ) ;
}
unsigned long F_23 ( struct V_21 * V_22 )
{
return F_24 ( V_22 ) -> V_31 ;
}
static inline struct V_32 T_1 *
F_25 ( struct V_32 T_1 * V_33 ,
struct V_32 T_1 * V_34 )
{
unsigned long V_35 , V_24 ;
struct V_32 * V_36 ;
struct V_32 T_1 * V_37 ;
if ( F_26 ( V_36 , & V_34 -> V_24 ) )
return NULL ;
V_24 = ( unsigned long ) V_36 ;
V_35 = ( V_24 - ( ( unsigned long ) V_34 ) ) ;
V_24 = ( unsigned long ) V_33 ;
V_37 = (struct V_32 T_1 * ) ( V_24 - V_35 ) ;
if ( F_27 ( V_37 , V_34 , V_35 ) )
V_37 = NULL ;
else if ( F_28 ( V_24 , & V_37 -> V_24 ) )
V_37 = NULL ;
return V_37 ;
}
T_2 int F_29 ( unsigned long V_38 ,
unsigned long V_39 ,
struct V_10 * V_40 ,
unsigned long V_41 )
{
unsigned long V_42 , V_43 ;
unsigned long V_44 = V_40 -> V_14 [ V_45 ] ;
long V_46 ;
V_42 = V_40 -> V_14 [ V_47 ] ;
V_43 = V_40 -> V_14 [ V_48 ] ;
V_46 = F_30 ( V_38 , V_39 ,
V_40 , V_41 ,
( int T_1 * ) V_42 ,
( int T_1 * ) V_43 ) ;
if ( ( unsigned long ) V_46 >= - V_49 )
V_40 -> V_14 [ V_45 ] = V_44 ;
return V_46 ;
}
int F_31 ( struct V_10 * V_40 , T_3 * V_50 )
{
if ( F_32 () ) {
memset ( V_50 , 0 , sizeof( * V_50 ) ) ;
V_50 -> V_51 = 8 ;
return 1 ;
}
#ifdef F_33
if ( F_34 ( V_52 ) ) {
F_35 ( F_36 () | V_53 ) ;
F_37 ( & V_30 -> V_54 . V_55 [ 0 ] , & V_30 -> V_54 . V_56 ,
& V_30 -> V_54 . V_57 [ 0 ] , & V_30 -> V_54 . V_58 ) ;
if ( V_40 != NULL ) {
V_40 -> V_15 &= ~ ( V_53 ) ;
F_38 ( V_52 ) ;
}
}
#else
if ( V_30 == V_59 ) {
F_35 ( F_36 () | V_53 ) ;
F_37 ( & V_30 -> V_54 . V_55 [ 0 ] , & V_30 -> V_54 . V_56 ,
& V_30 -> V_54 . V_57 [ 0 ] , & V_30 -> V_54 . V_58 ) ;
if ( V_40 != NULL ) {
V_40 -> V_15 &= ~ ( V_53 ) ;
V_59 = NULL ;
}
}
#endif
memcpy ( & V_50 -> V_60 . V_61 [ 0 ] ,
& V_30 -> V_54 . V_55 [ 0 ] ,
(sizeof( unsigned long ) * 32 ) ) ;
V_50 -> V_62 = V_30 -> V_54 . V_56 ;
V_50 -> V_63 = V_30 -> V_54 . V_58 ;
V_50 -> V_51 = 8 ;
V_50 -> V_64 = 1 ;
if( V_50 -> V_63 != 0 ) {
memcpy ( & V_50 -> V_65 [ 0 ] ,
& V_30 -> V_54 . V_57 [ 0 ] ,
sizeof( struct V_66 ) * V_50 -> V_63 ) ;
}
memset ( & V_50 -> V_65 [ V_50 -> V_63 ] , 0 ,
sizeof( struct V_66 ) * ( 32 - V_50 -> V_63 ) ) ;
return 1 ;
}
T_2 int F_39 ( struct V_10 * V_40 )
{
int error , V_67 = 0 ;
char * V_68 ;
if( V_40 -> V_14 [ V_69 ] == 0 )
V_67 = 1 ;
V_68 = F_40 ( ( char T_1 * ) V_40 -> V_14 [ V_67 + V_70 ] ) ;
error = F_41 ( V_68 ) ;
if( F_42 ( V_68 ) )
goto V_71;
error = F_43 ( V_68 ,
( const char T_1 * const T_1 * )
V_40 -> V_14 [ V_67 + V_45 ] ,
( const char T_1 * const T_1 * )
V_40 -> V_14 [ V_67 + V_47 ] ,
V_40 ) ;
F_44 ( V_68 ) ;
V_71:
return error ;
}
T_4 F_45 ( int (* F_46)( void * ) , void * V_72 , unsigned long V_73 )
{
long V_74 ;
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
return V_74 ;
}
unsigned long F_47 ( struct V_21 * V_75 )
{
unsigned long V_16 , V_24 , V_76 = 0 ;
unsigned long V_25 = ( unsigned long ) V_75 ;
unsigned long V_46 = 0 ;
struct V_12 * V_13 ;
int V_26 = 0 ;
if ( ! V_75 || V_75 == V_30 ||
V_75 -> V_77 == V_78 )
goto V_71;
V_24 = F_24 ( V_75 ) -> V_29 + V_76 ;
do {
if ( V_24 < ( V_25 + sizeof( struct V_27 ) ) ||
V_24 >= ( V_25 + ( 2 * V_28 ) ) )
break;
V_13 = (struct V_12 * ) V_24 ;
V_16 = V_13 -> V_20 [ 7 ] ;
if ( ! F_48 ( V_16 ) ) {
V_46 = V_16 ;
goto V_71;
}
V_24 = V_13 -> V_20 [ 6 ] + V_76 ;
} while ( ++ V_26 < 16 );
V_71:
return V_46 ;
}
