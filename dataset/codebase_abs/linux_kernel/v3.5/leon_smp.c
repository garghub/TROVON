static inline unsigned long F_1 ( volatile unsigned long * V_1 ,
unsigned long V_2 )
{
__asm__ __volatile__("swapa [%2] %3, %0\n\t" : "=&r"(val)
: "0"(val), "r"(ptr), "i"(ASI_LEON_DCACHE_MISS)
: "memory");
return V_2 ;
}
void T_1 F_2 ( void )
{
int V_3 = F_3 () ;
V_4 -> V_5 () ;
V_4 -> V_6 () ;
F_4 () ;
F_5 ( V_3 ) ;
F_6 ( V_3 ) ;
F_7 () ;
F_8 ( V_3 ) ;
V_4 -> V_5 () ;
V_4 -> V_6 () ;
F_1 ( & V_7 [ V_3 ] , 1 ) ;
V_4 -> V_5 () ;
V_4 -> V_6 () ;
__asm__ __volatile__("ld [%0], %%g6\n\t" : : "r"(&current_set[cpuid])
: "memory" );
F_9 ( & V_8 . V_9 ) ;
V_10 -> V_11 = & V_8 ;
while ( ! F_10 ( V_3 , & V_12 ) )
F_11 () ;
F_12 () ;
F_13 ( V_3 , true ) ;
}
void T_1 F_4 ( void )
{
unsigned long V_13 = F_14 () ;
int V_14 = F_15 () ;
if ( F_16 ( V_13 ) > 4 ) {
F_17 ( V_15 L_1 ,
( unsigned int ) F_16 ( V_13 ) ,
( unsigned int ) V_13 , ( unsigned int ) V_14 ) ;
F_18 () ;
} else {
if ( V_13 & V_16 ) {
F_19 () ;
} else {
F_17 ( V_15 L_2 ,
V_14 ) ;
F_18 () ;
}
}
V_4 -> V_5 () ;
V_4 -> V_6 () ;
}
void F_20 ( unsigned int V_17 )
{
int V_18 =
( ( F_21 ( & ( V_19 -> V_20 ) ) >>
V_21 ) & 1 ) ;
if ( ! V_18 ) {
F_22 ( L_3 ,
F_23 () ) ;
if ( F_23 () > 1 ) {
F_24 () ;
} else {
F_22 ( L_4 ) ;
return;
}
}
F_25 ( & ( V_19 -> V_22 ) , V_17 ) ;
}
unsigned int F_26 ( void )
{
unsigned int V_17 ;
V_17 = F_27 ( & ( V_19 -> V_22 ) ) ;
return V_17 ;
}
int F_23 ( void )
{
int V_23 =
( ( F_21 ( & ( V_19 -> V_20 ) ) >>
V_24 ) & 0xf ) + 1 ;
return V_23 ;
}
void T_2 F_28 ( void )
{
int V_23 = F_23 () ;
int V_14 = F_15 () ;
F_29 () ;
F_17 ( V_15 L_5 , ( unsigned int ) V_14 ,
( unsigned int ) V_23 , ( unsigned int ) V_25 ,
( unsigned int ) & ( V_19 -> V_20 ) ) ;
F_30 ( V_26 , V_14 ) ;
F_30 ( V_27 , V_14 ) ;
F_30 ( V_28 , V_14 ) ;
F_20 ( 1 << V_27 ) ;
F_4 () ;
V_4 -> V_5 () ;
}
int T_1 F_31 ( int V_29 , struct V_30 * V_31 )
{
int V_32 ;
V_33 [ V_29 ] = F_32 ( V_31 ) ;
V_34 . V_35 = 0 ;
V_34 . V_36 = ( unsigned int ) V_37 ;
V_34 . V_38 = 0 ;
F_17 ( V_15 L_6 , ( unsigned int ) V_29 ,
( unsigned int ) & V_19 -> V_20 ) ;
V_4 -> V_5 () ;
F_25 ( & V_19 -> V_17 [ V_29 ] , 0 ) ;
F_25 ( & ( V_19 -> V_20 ) , 1 << V_29 ) ;
for ( V_32 = 0 ; V_32 < 10000 ; V_32 ++ ) {
if ( V_7 [ V_29 ] )
break;
F_33 ( 200 ) ;
}
F_17 ( V_15 L_7 , ( unsigned int ) V_29 ) ;
if ( ! ( V_7 [ V_29 ] ) ) {
F_17 ( V_39 L_8 , V_29 ) ;
return - V_40 ;
} else {
F_30 ( V_26 , V_29 ) ;
F_30 ( V_27 , V_29 ) ;
F_30 ( V_28 , V_29 ) ;
}
V_4 -> V_5 () ;
return 0 ;
}
void T_2 F_34 ( void )
{
int V_29 , V_41 ;
int * V_42 ;
V_41 = 0 ;
V_42 = & V_41 ;
for ( V_29 = 0 ; V_29 < V_25 ; V_29 ++ ) {
if ( F_35 ( V_29 ) ) {
* V_42 = V_29 ;
V_42 = & F_36 ( V_29 ) . V_43 ;
}
}
* V_42 = V_41 ;
V_4 -> V_5 () ;
if ( ! F_37 ( 1 ) ) {
F_38 ( F_39 ( & V_44 ) ) ;
F_40 ( F_39 ( & V_44 ) ) ;
F_41 ( ( unsigned long ) & V_44 ) ;
V_45 ++ ;
V_46 ++ ;
}
if ( ! F_37 ( 2 ) ) {
F_38 ( F_39 ( & V_47 ) ) ;
F_40 ( F_39 ( & V_47 ) ) ;
F_41 ( ( unsigned long ) & V_47 ) ;
V_45 ++ ;
V_46 ++ ;
}
if ( ! F_37 ( 3 ) ) {
F_38 ( F_39 ( & V_48 ) ) ;
F_40 ( F_39 ( & V_48 ) ) ;
F_41 ( ( unsigned long ) & V_48 ) ;
V_45 ++ ;
V_46 ++ ;
}
V_49 = 1 ;
}
void F_42 ( int V_50 )
{
}
static void T_2 F_29 ( void )
{
int V_50 , V_51 ;
struct V_52 * V_53 ;
struct V_54 * V_55 ;
struct V_56 * V_57 ;
struct V_58 * V_59 ;
unsigned long V_60 ;
V_57 = F_43 ( L_9 ) ;
if ( V_57 ) {
V_55 = F_44 ( V_57 , L_10 , & V_51 ) ;
if ( V_55 && ( * ( int * ) V_55 -> V_61 ) )
V_28 = * ( int * ) V_55 -> V_61 ;
}
F_17 ( V_15 L_11 , V_28 ) ;
F_45 ( V_60 ) ;
V_59 = & V_62 [ V_63 + ( V_28 - 1 ) ] ;
V_59 -> V_64 += V_65 - V_66 ;
V_4 -> V_5 () ;
F_46 ( V_60 ) ;
F_47 (cpu) {
V_53 = & F_48 ( V_52 , V_50 ) ;
V_53 -> V_67 = V_53 -> V_68 = V_53 -> V_69 = 0 ;
}
}
static void F_49 ( int V_50 , int V_70 )
{
unsigned long V_17 ;
V_17 = F_50 ( V_70 ) ;
F_51 ( & V_19 -> V_71 [ V_50 ] , V_17 ) ;
}
static void F_52 ( int V_50 )
{
struct V_52 * V_53 = & F_48 ( V_52 , V_50 ) ;
V_53 -> V_67 = 1 ;
F_49 ( V_50 , V_28 ) ;
}
static void F_53 ( int V_50 )
{
struct V_52 * V_53 = & F_48 ( V_52 , V_50 ) ;
V_53 -> V_68 = 1 ;
F_49 ( V_50 , V_28 ) ;
}
static void F_54 ( int V_50 )
{
struct V_52 * V_53 = & F_48 ( V_52 , V_50 ) ;
V_53 -> V_69 = 1 ;
F_49 ( V_50 , V_28 ) ;
}
void F_55 ( void )
{
struct V_52 * V_53 = & F_56 ( V_52 ) ;
if ( V_53 -> V_67 ) {
V_53 -> V_67 = 0 ;
F_57 () ;
}
if ( V_53 -> V_68 ) {
V_53 -> V_68 = 0 ;
F_58 () ;
}
if ( V_53 -> V_69 ) {
V_53 -> V_69 = 0 ;
F_59 () ;
}
}
static void F_60 ( T_3 V_72 , T_4 V_17 , unsigned long V_73 ,
unsigned long V_74 , unsigned long V_75 ,
unsigned long V_76 )
{
if ( V_49 ) {
register int V_77 = V_25 - 1 ;
unsigned long V_60 ;
F_61 ( & V_78 , V_60 ) ;
{
register T_3 T_5 V_79 ( L_12 ) = V_72 ;
register unsigned long T_6 V_79 ( L_13 ) = V_73 ;
register unsigned long T_7 V_79 ( L_14 ) = V_74 ;
register unsigned long T_8 V_79 ( L_15 ) = V_75 ;
register unsigned long T_9 V_79 ( L_16 ) = V_76 ;
register unsigned long T_10 V_79 ( L_17 ) = 0 ;
__asm__ __volatile__("std %0, [%6]\n\t"
"std %2, [%6 + 8]\n\t"
"std %4, [%6 + 16]\n\t" : :
"r"(f), "r"(a1), "r"(a2), "r"(a3),
"r"(a4), "r"(a5),
"r"(&ccall_info.func));
}
{
register int V_29 ;
F_62 ( F_15 () , & V_17 ) ;
F_63 ( & V_17 , V_80 , & V_17 ) ;
for ( V_29 = 0 ; V_29 <= V_77 ; V_29 ++ ) {
if ( F_10 ( V_29 , & V_17 ) ) {
V_81 . V_82 [ V_29 ] = 0 ;
V_81 . V_83 [ V_29 ] = 0 ;
F_49 ( V_29 , V_26 ) ;
}
}
}
{
register int V_29 ;
V_29 = 0 ;
do {
if ( ! F_10 ( V_29 , & V_17 ) )
continue;
while ( ! V_81 . V_82 [ V_29 ] )
F_64 () ;
} while ( ++ V_29 <= V_77 );
V_29 = 0 ;
do {
if ( ! F_10 ( V_29 , & V_17 ) )
continue;
while ( ! V_81 . V_83 [ V_29 ] )
F_64 () ;
} while ( ++ V_29 <= V_77 );
}
F_65 ( & V_78 , V_60 ) ;
}
}
void F_66 ( void )
{
int V_29 = F_15 () ;
V_81 . V_82 [ V_29 ] = 1 ;
V_81 . V_72 ( V_81 . V_73 , V_81 . V_74 , V_81 . V_75 ,
V_81 . V_76 , V_81 . V_84 ) ;
V_81 . V_83 [ V_29 ] = 1 ;
}
void T_2 F_67 ( void )
{
V_85 [ 1 ] = V_85 [ 1 ] + ( V_86 - V_87 ) ;
V_88 = & V_89 ;
}
