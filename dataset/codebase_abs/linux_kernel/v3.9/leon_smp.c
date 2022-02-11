static inline unsigned long F_1 ( volatile unsigned long * V_1 ,
unsigned long V_2 )
{
__asm__ __volatile__("swapa [%2] %3, %0\n\t" : "=&r"(val)
: "0"(val), "r"(ptr), "i"(ASI_LEON_DCACHE_MISS)
: "memory");
return V_2 ;
}
void T_1 F_2 ( void * V_3 )
{
F_3 () ;
}
void T_1 F_4 ( void * V_3 )
{
int V_4 = F_5 () ;
F_1 ( & V_5 [ V_4 ] , 1 ) ;
V_6 -> V_7 () ;
V_6 -> V_8 () ;
__asm__ __volatile__("ld [%0], %%g6\n\t" : : "r"(&current_set[cpuid])
: "memory" );
F_6 ( & V_9 . V_10 ) ;
V_11 -> V_12 = & V_9 ;
while ( ! F_7 ( V_4 , & V_13 ) )
F_8 () ;
}
void T_1 F_3 ( void )
{
unsigned long V_14 = F_9 () ;
int V_15 = F_10 () ;
if ( F_11 ( V_14 ) > 4 ) {
F_12 ( V_16 L_1 ,
( unsigned int ) F_11 ( V_14 ) ,
( unsigned int ) V_14 , ( unsigned int ) V_15 ) ;
F_13 () ;
} else {
if ( V_14 & V_17 ) {
F_14 () ;
} else {
F_12 ( V_16 L_2 ,
V_15 ) ;
F_13 () ;
}
}
V_6 -> V_7 () ;
V_6 -> V_8 () ;
}
void F_15 ( unsigned int V_18 )
{
int V_19 =
( ( F_16 ( & ( V_20 -> V_21 ) ) >>
V_22 ) & 1 ) ;
if ( ! V_19 ) {
F_17 ( L_3 ,
F_18 () ) ;
if ( F_18 () > 1 ) {
F_19 () ;
} else {
F_17 ( L_4 ) ;
return;
}
}
F_20 ( & ( V_20 -> V_23 ) , V_18 ) ;
}
unsigned int F_21 ( void )
{
unsigned int V_18 ;
V_18 = F_22 ( & ( V_20 -> V_23 ) ) ;
return V_18 ;
}
int F_18 ( void )
{
int V_24 =
( ( F_16 ( & ( V_20 -> V_21 ) ) >>
V_25 ) & 0xf ) + 1 ;
return V_24 ;
}
void T_2 F_23 ( void )
{
int V_24 = F_18 () ;
int V_15 = F_10 () ;
F_24 () ;
F_12 ( V_16 L_5 , ( unsigned int ) V_15 ,
( unsigned int ) V_24 , ( unsigned int ) V_26 ,
( unsigned int ) & ( V_20 -> V_21 ) ) ;
F_25 ( V_27 , V_15 ) ;
F_25 ( V_28 , V_15 ) ;
F_25 ( V_29 , V_15 ) ;
F_15 ( 1 << V_28 ) ;
F_3 () ;
V_6 -> V_7 () ;
}
int T_1 F_26 ( int V_30 , struct V_31 * V_32 )
{
int V_33 ;
V_34 [ V_30 ] = F_27 ( V_32 ) ;
V_35 . V_36 = 0 ;
V_35 . V_37 = ( unsigned int ) V_38 ;
V_35 . V_39 = 0 ;
F_12 ( V_16 L_6 , ( unsigned int ) V_30 ,
( unsigned int ) & V_20 -> V_21 ) ;
V_6 -> V_7 () ;
F_20 ( & V_20 -> V_18 [ V_30 ] , 0 ) ;
F_20 ( & ( V_20 -> V_21 ) , 1 << V_30 ) ;
for ( V_33 = 0 ; V_33 < 10000 ; V_33 ++ ) {
if ( V_5 [ V_30 ] )
break;
F_28 ( 200 ) ;
}
F_12 ( V_16 L_7 , ( unsigned int ) V_30 ) ;
if ( ! ( V_5 [ V_30 ] ) ) {
F_12 ( V_40 L_8 , V_30 ) ;
return - V_41 ;
} else {
F_25 ( V_27 , V_30 ) ;
F_25 ( V_28 , V_30 ) ;
F_25 ( V_29 , V_30 ) ;
}
V_6 -> V_7 () ;
return 0 ;
}
void T_2 F_29 ( void )
{
int V_30 , V_42 ;
int * V_43 ;
V_42 = 0 ;
V_43 = & V_42 ;
for ( V_30 = 0 ; V_30 < V_26 ; V_30 ++ ) {
if ( F_30 ( V_30 ) ) {
* V_43 = V_30 ;
V_43 = & F_31 ( V_30 ) . V_44 ;
}
}
* V_43 = V_42 ;
V_6 -> V_7 () ;
if ( ! F_32 ( 1 ) ) {
F_33 ( F_34 ( & V_45 ) ) ;
F_35 ( F_34 ( & V_45 ) ) ;
F_36 ( ( unsigned long ) & V_45 ) ;
V_46 ++ ;
V_47 ++ ;
}
if ( ! F_32 ( 2 ) ) {
F_33 ( F_34 ( & V_48 ) ) ;
F_35 ( F_34 ( & V_48 ) ) ;
F_36 ( ( unsigned long ) & V_48 ) ;
V_46 ++ ;
V_47 ++ ;
}
if ( ! F_32 ( 3 ) ) {
F_33 ( F_34 ( & V_49 ) ) ;
F_35 ( F_34 ( & V_49 ) ) ;
F_36 ( ( unsigned long ) & V_49 ) ;
V_46 ++ ;
V_47 ++ ;
}
V_50 = 1 ;
}
void F_37 ( int V_51 )
{
}
static void T_2 F_24 ( void )
{
int V_51 , V_52 ;
struct V_53 * V_54 ;
struct V_55 * V_56 ;
struct V_57 * V_58 ;
struct V_59 * V_60 ;
unsigned long V_61 ;
V_58 = F_38 ( L_9 ) ;
if ( V_58 ) {
V_56 = F_39 ( V_58 , L_10 , & V_52 ) ;
if ( V_56 && ( * ( int * ) V_56 -> V_62 ) )
V_29 = * ( int * ) V_56 -> V_62 ;
}
F_12 ( V_16 L_11 , V_29 ) ;
F_40 ( V_61 ) ;
V_60 = & V_63 [ V_64 + ( V_29 - 1 ) ] ;
V_60 -> V_65 += V_66 - V_67 ;
V_6 -> V_7 () ;
F_41 ( V_61 ) ;
F_42 (cpu) {
V_54 = & F_43 ( V_53 , V_51 ) ;
V_54 -> V_68 = V_54 -> V_69 = V_54 -> V_70 = 0 ;
}
}
static void F_44 ( int V_51 , int V_71 )
{
unsigned long V_18 ;
V_18 = F_45 ( V_71 ) ;
F_46 ( & V_20 -> V_72 [ V_51 ] , V_18 ) ;
}
static void F_47 ( int V_51 )
{
struct V_53 * V_54 = & F_43 ( V_53 , V_51 ) ;
V_54 -> V_68 = 1 ;
F_44 ( V_51 , V_29 ) ;
}
static void F_48 ( int V_51 )
{
struct V_53 * V_54 = & F_43 ( V_53 , V_51 ) ;
V_54 -> V_69 = 1 ;
F_44 ( V_51 , V_29 ) ;
}
static void F_49 ( int V_51 )
{
struct V_53 * V_54 = & F_43 ( V_53 , V_51 ) ;
V_54 -> V_70 = 1 ;
F_44 ( V_51 , V_29 ) ;
}
void F_50 ( void )
{
struct V_53 * V_54 = & F_51 ( V_53 ) ;
if ( V_54 -> V_68 ) {
V_54 -> V_68 = 0 ;
F_52 () ;
}
if ( V_54 -> V_69 ) {
V_54 -> V_69 = 0 ;
F_53 () ;
}
if ( V_54 -> V_70 ) {
V_54 -> V_70 = 0 ;
F_54 () ;
}
}
static void F_55 ( T_3 V_73 , T_4 V_18 , unsigned long V_74 ,
unsigned long V_75 , unsigned long V_76 ,
unsigned long V_77 )
{
if ( V_50 ) {
register int V_78 = V_26 - 1 ;
unsigned long V_61 ;
F_56 ( & V_79 , V_61 ) ;
{
register T_3 T_5 V_80 ( L_12 ) = V_73 ;
register unsigned long T_6 V_80 ( L_13 ) = V_74 ;
register unsigned long T_7 V_80 ( L_14 ) = V_75 ;
register unsigned long T_8 V_80 ( L_15 ) = V_76 ;
register unsigned long T_9 V_80 ( L_16 ) = V_77 ;
register unsigned long T_10 V_80 ( L_17 ) = 0 ;
__asm__ __volatile__("std %0, [%6]\n\t"
"std %2, [%6 + 8]\n\t"
"std %4, [%6 + 16]\n\t" : :
"r"(f), "r"(a1), "r"(a2), "r"(a3),
"r"(a4), "r"(a5),
"r"(&ccall_info.func));
}
{
register int V_30 ;
F_57 ( F_10 () , & V_18 ) ;
F_58 ( & V_18 , V_81 , & V_18 ) ;
for ( V_30 = 0 ; V_30 <= V_78 ; V_30 ++ ) {
if ( F_7 ( V_30 , & V_18 ) ) {
V_82 . V_83 [ V_30 ] = 0 ;
V_82 . V_84 [ V_30 ] = 0 ;
F_44 ( V_30 , V_27 ) ;
}
}
}
{
register int V_30 ;
V_30 = 0 ;
do {
if ( ! F_7 ( V_30 , & V_18 ) )
continue;
while ( ! V_82 . V_83 [ V_30 ] )
F_59 () ;
} while ( ++ V_30 <= V_78 );
V_30 = 0 ;
do {
if ( ! F_7 ( V_30 , & V_18 ) )
continue;
while ( ! V_82 . V_84 [ V_30 ] )
F_59 () ;
} while ( ++ V_30 <= V_78 );
}
F_60 ( & V_79 , V_61 ) ;
}
}
void F_61 ( void )
{
int V_30 = F_10 () ;
V_82 . V_83 [ V_30 ] = 1 ;
V_82 . V_73 ( V_82 . V_74 , V_82 . V_75 , V_82 . V_76 ,
V_82 . V_77 , V_82 . V_85 ) ;
V_82 . V_84 [ V_30 ] = 1 ;
}
void T_2 F_62 ( void )
{
V_86 [ 1 ] = V_86 [ 1 ] + ( V_87 - V_88 ) ;
V_89 = & V_90 ;
}
