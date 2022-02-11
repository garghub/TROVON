static inline unsigned long F_1 ( volatile unsigned long * V_1 ,
unsigned long V_2 )
{
__asm__ __volatile__("swapa [%2] %3, %0\n\t" : "=&r"(val)
: "0"(val), "r"(ptr), "i"(ASI_LEON_DCACHE_MISS)
: "memory");
return V_2 ;
}
void F_2 ( void * V_3 )
{
F_3 () ;
}
void F_4 ( void * V_3 )
{
int V_4 = F_5 () ;
F_1 ( & V_5 [ V_4 ] , 1 ) ;
V_6 -> V_7 () ;
V_6 -> V_8 () ;
__asm__ __volatile__("ld [%0], %%g6\n\t" : : "r"(&current_set[cpuid])
: "memory" );
F_6 ( & V_9 ) ;
V_10 -> V_11 = & V_9 ;
while ( ! F_7 ( V_4 , & V_12 ) )
F_8 () ;
}
void F_3 ( void )
{
unsigned long V_13 = F_9 () ;
int V_14 = F_10 () ;
if ( F_11 ( V_13 ) > 4 ) {
F_12 ( V_15 L_1 ,
( unsigned int ) F_11 ( V_13 ) ,
( unsigned int ) V_13 , ( unsigned int ) V_14 ) ;
F_13 () ;
} else {
if ( V_13 & V_16 ) {
F_14 () ;
} else {
F_12 ( V_15 L_2 ,
V_14 ) ;
F_13 () ;
}
}
V_6 -> V_7 () ;
V_6 -> V_8 () ;
}
static void F_15 ( unsigned int V_17 )
{
int V_18 =
( ( F_16 ( & ( V_19 -> V_20 ) ) >>
V_21 ) & 1 ) ;
if ( ! V_18 ) {
F_17 ( L_3 ,
F_18 () ) ;
if ( F_18 () > 1 ) {
F_19 () ;
} else {
F_17 ( L_4 ) ;
return;
}
}
F_20 ( & ( V_19 -> V_22 ) , V_17 ) ;
}
int F_18 ( void )
{
int V_23 =
( ( F_16 ( & ( V_19 -> V_20 ) ) >>
V_24 ) & 0xf ) + 1 ;
return V_23 ;
}
void T_1 F_21 ( void )
{
int V_23 = F_18 () ;
int V_14 = F_10 () ;
F_22 () ;
F_12 ( V_15 L_5 , ( unsigned int ) V_14 ,
( unsigned int ) V_23 , ( unsigned int ) V_25 ,
( unsigned int ) & ( V_19 -> V_20 ) ) ;
F_23 ( V_26 , V_14 ) ;
F_23 ( V_27 , V_14 ) ;
F_23 ( V_28 , V_14 ) ;
F_15 ( 1 << V_27 ) ;
F_3 () ;
V_6 -> V_7 () ;
}
int F_24 ( int V_29 , struct V_30 * V_31 )
{
int V_32 ;
V_33 [ V_29 ] = F_25 ( V_31 ) ;
V_34 . V_35 = 0 ;
V_34 . V_36 = ( unsigned int ) V_37 ;
V_34 . V_38 = 0 ;
F_12 ( V_15 L_6 , ( unsigned int ) V_29 ,
( unsigned int ) & V_19 -> V_20 ) ;
V_6 -> V_7 () ;
F_20 ( & V_19 -> V_17 [ V_29 ] , 0 ) ;
F_20 ( & ( V_19 -> V_20 ) , 1 << V_29 ) ;
for ( V_32 = 0 ; V_32 < 10000 ; V_32 ++ ) {
if ( V_5 [ V_29 ] )
break;
F_26 ( 200 ) ;
}
F_12 ( V_15 L_7 , ( unsigned int ) V_29 ) ;
if ( ! ( V_5 [ V_29 ] ) ) {
F_12 ( V_39 L_8 , V_29 ) ;
return - V_40 ;
} else {
F_23 ( V_26 , V_29 ) ;
F_23 ( V_27 , V_29 ) ;
F_23 ( V_28 , V_29 ) ;
}
V_6 -> V_7 () ;
return 0 ;
}
void T_1 F_27 ( void )
{
int V_29 , V_41 ;
int * V_42 ;
V_41 = 0 ;
V_42 = & V_41 ;
for ( V_29 = 0 ; V_29 < V_25 ; V_29 ++ ) {
if ( F_28 ( V_29 ) ) {
* V_42 = V_29 ;
V_42 = & F_29 ( V_29 ) . V_43 ;
}
}
* V_42 = V_41 ;
V_6 -> V_7 () ;
if ( ! F_30 ( 1 ) ) {
F_31 ( F_32 ( & V_44 ) ) ;
}
if ( ! F_30 ( 2 ) ) {
F_31 ( F_32 ( & V_45 ) ) ;
}
if ( ! F_30 ( 3 ) ) {
F_31 ( F_32 ( & V_46 ) ) ;
}
V_47 = 1 ;
}
static void T_1 F_22 ( void )
{
int V_48 , V_49 ;
struct V_50 * V_51 ;
struct V_52 * V_53 ;
struct V_54 * V_55 ;
struct V_56 * V_57 ;
unsigned long V_58 ;
V_55 = F_33 ( L_9 ) ;
if ( V_55 ) {
V_53 = F_34 ( V_55 , L_10 , & V_49 ) ;
if ( V_53 && ( * ( int * ) V_53 -> V_59 ) )
V_28 = * ( int * ) V_53 -> V_59 ;
}
F_12 ( V_15 L_11 , V_28 ) ;
F_35 ( V_58 ) ;
V_57 = & V_60 [ V_61 + ( V_28 - 1 ) ] ;
V_57 -> V_62 += V_63 - V_64 ;
V_6 -> V_7 () ;
F_36 ( V_58 ) ;
F_37 (cpu) {
V_51 = & F_38 ( V_50 , V_48 ) ;
V_51 -> V_65 = V_51 -> V_66 = V_51 -> V_67 = 0 ;
}
}
static void F_39 ( int V_48 , int V_68 )
{
unsigned long V_17 ;
V_17 = F_40 ( V_68 ) ;
F_41 ( & V_19 -> V_69 [ V_48 ] , V_17 ) ;
}
static void F_42 ( int V_48 )
{
struct V_50 * V_51 = & F_38 ( V_50 , V_48 ) ;
V_51 -> V_65 = 1 ;
F_39 ( V_48 , V_28 ) ;
}
static void F_43 ( int V_48 )
{
struct V_50 * V_51 = & F_38 ( V_50 , V_48 ) ;
V_51 -> V_66 = 1 ;
F_39 ( V_48 , V_28 ) ;
}
static void F_44 ( int V_48 )
{
struct V_50 * V_51 = & F_38 ( V_50 , V_48 ) ;
V_51 -> V_67 = 1 ;
F_39 ( V_48 , V_28 ) ;
}
void F_45 ( void )
{
struct V_50 * V_51 = F_46 ( & V_50 ) ;
if ( V_51 -> V_65 ) {
V_51 -> V_65 = 0 ;
F_47 () ;
}
if ( V_51 -> V_66 ) {
V_51 -> V_66 = 0 ;
F_48 () ;
}
if ( V_51 -> V_67 ) {
V_51 -> V_67 = 0 ;
F_49 () ;
}
}
static void F_50 ( T_2 V_70 , T_3 V_17 , unsigned long V_71 ,
unsigned long V_72 , unsigned long V_73 ,
unsigned long V_74 )
{
if ( V_47 ) {
register int V_75 = V_25 - 1 ;
unsigned long V_58 ;
F_51 ( & V_76 , V_58 ) ;
{
register T_2 T_4 V_77 ( L_12 ) = V_70 ;
register unsigned long T_5 V_77 ( L_13 ) = V_71 ;
register unsigned long T_6 V_77 ( L_14 ) = V_72 ;
register unsigned long T_7 V_77 ( L_15 ) = V_73 ;
register unsigned long T_8 V_77 ( L_16 ) = V_74 ;
register unsigned long T_9 V_77 ( L_17 ) = 0 ;
__asm__ __volatile__("std %0, [%6]\n\t"
"std %2, [%6 + 8]\n\t"
"std %4, [%6 + 16]\n\t" : :
"r"(f), "r"(a1), "r"(a2), "r"(a3),
"r"(a4), "r"(a5),
"r"(&ccall_info.func));
}
{
register int V_29 ;
F_52 ( F_10 () , & V_17 ) ;
F_53 ( & V_17 , V_78 , & V_17 ) ;
for ( V_29 = 0 ; V_29 <= V_75 ; V_29 ++ ) {
if ( F_7 ( V_29 , & V_17 ) ) {
V_79 . V_80 [ V_29 ] = 0 ;
V_79 . V_81 [ V_29 ] = 0 ;
F_39 ( V_29 , V_26 ) ;
}
}
}
{
register int V_29 ;
V_29 = 0 ;
do {
if ( ! F_7 ( V_29 , & V_17 ) )
continue;
while ( ! V_79 . V_80 [ V_29 ] )
F_54 () ;
} while ( ++ V_29 <= V_75 );
V_29 = 0 ;
do {
if ( ! F_7 ( V_29 , & V_17 ) )
continue;
while ( ! V_79 . V_81 [ V_29 ] )
F_54 () ;
} while ( ++ V_29 <= V_75 );
}
F_55 ( & V_76 , V_58 ) ;
}
}
void F_56 ( void )
{
int V_29 = F_10 () ;
V_79 . V_80 [ V_29 ] = 1 ;
V_79 . V_70 ( V_79 . V_71 , V_79 . V_72 , V_79 . V_73 ,
V_79 . V_74 , V_79 . V_82 ) ;
V_79 . V_81 [ V_29 ] = 1 ;
}
void T_1 F_57 ( void )
{
V_83 [ 1 ] = V_83 [ 1 ] + ( V_84 - V_85 ) ;
V_86 = & V_87 ;
}
