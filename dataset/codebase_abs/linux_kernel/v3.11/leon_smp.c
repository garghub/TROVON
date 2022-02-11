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
F_6 ( & V_9 . V_10 ) ;
V_11 -> V_12 = & V_9 ;
while ( ! F_7 ( V_4 , & V_13 ) )
F_8 () ;
}
void F_3 ( void )
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
void T_1 F_23 ( void )
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
int F_26 ( int V_30 , struct V_31 * V_32 )
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
void T_1 F_29 ( void )
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
}
if ( ! F_32 ( 2 ) ) {
F_33 ( F_34 ( & V_46 ) ) ;
}
if ( ! F_32 ( 3 ) ) {
F_33 ( F_34 ( & V_47 ) ) ;
}
V_48 = 1 ;
}
void F_35 ( int V_49 )
{
}
static void T_1 F_24 ( void )
{
int V_49 , V_50 ;
struct V_51 * V_52 ;
struct V_53 * V_54 ;
struct V_55 * V_56 ;
struct V_57 * V_58 ;
unsigned long V_59 ;
V_56 = F_36 ( L_9 ) ;
if ( V_56 ) {
V_54 = F_37 ( V_56 , L_10 , & V_50 ) ;
if ( V_54 && ( * ( int * ) V_54 -> V_60 ) )
V_29 = * ( int * ) V_54 -> V_60 ;
}
F_12 ( V_16 L_11 , V_29 ) ;
F_38 ( V_59 ) ;
V_58 = & V_61 [ V_62 + ( V_29 - 1 ) ] ;
V_58 -> V_63 += V_64 - V_65 ;
V_6 -> V_7 () ;
F_39 ( V_59 ) ;
F_40 (cpu) {
V_52 = & F_41 ( V_51 , V_49 ) ;
V_52 -> V_66 = V_52 -> V_67 = V_52 -> V_68 = 0 ;
}
}
static void F_42 ( int V_49 , int V_69 )
{
unsigned long V_18 ;
V_18 = F_43 ( V_69 ) ;
F_44 ( & V_20 -> V_70 [ V_49 ] , V_18 ) ;
}
static void F_45 ( int V_49 )
{
struct V_51 * V_52 = & F_41 ( V_51 , V_49 ) ;
V_52 -> V_66 = 1 ;
F_42 ( V_49 , V_29 ) ;
}
static void F_46 ( int V_49 )
{
struct V_51 * V_52 = & F_41 ( V_51 , V_49 ) ;
V_52 -> V_67 = 1 ;
F_42 ( V_49 , V_29 ) ;
}
static void F_47 ( int V_49 )
{
struct V_51 * V_52 = & F_41 ( V_51 , V_49 ) ;
V_52 -> V_68 = 1 ;
F_42 ( V_49 , V_29 ) ;
}
void F_48 ( void )
{
struct V_51 * V_52 = & F_49 ( V_51 ) ;
if ( V_52 -> V_66 ) {
V_52 -> V_66 = 0 ;
F_50 () ;
}
if ( V_52 -> V_67 ) {
V_52 -> V_67 = 0 ;
F_51 () ;
}
if ( V_52 -> V_68 ) {
V_52 -> V_68 = 0 ;
F_52 () ;
}
}
static void F_53 ( T_2 V_71 , T_3 V_18 , unsigned long V_72 ,
unsigned long V_73 , unsigned long V_74 ,
unsigned long V_75 )
{
if ( V_48 ) {
register int V_76 = V_26 - 1 ;
unsigned long V_59 ;
F_54 ( & V_77 , V_59 ) ;
{
register T_2 T_4 V_78 ( L_12 ) = V_71 ;
register unsigned long T_5 V_78 ( L_13 ) = V_72 ;
register unsigned long T_6 V_78 ( L_14 ) = V_73 ;
register unsigned long T_7 V_78 ( L_15 ) = V_74 ;
register unsigned long T_8 V_78 ( L_16 ) = V_75 ;
register unsigned long T_9 V_78 ( L_17 ) = 0 ;
__asm__ __volatile__("std %0, [%6]\n\t"
"std %2, [%6 + 8]\n\t"
"std %4, [%6 + 16]\n\t" : :
"r"(f), "r"(a1), "r"(a2), "r"(a3),
"r"(a4), "r"(a5),
"r"(&ccall_info.func));
}
{
register int V_30 ;
F_55 ( F_10 () , & V_18 ) ;
F_56 ( & V_18 , V_79 , & V_18 ) ;
for ( V_30 = 0 ; V_30 <= V_76 ; V_30 ++ ) {
if ( F_7 ( V_30 , & V_18 ) ) {
V_80 . V_81 [ V_30 ] = 0 ;
V_80 . V_82 [ V_30 ] = 0 ;
F_42 ( V_30 , V_27 ) ;
}
}
}
{
register int V_30 ;
V_30 = 0 ;
do {
if ( ! F_7 ( V_30 , & V_18 ) )
continue;
while ( ! V_80 . V_81 [ V_30 ] )
F_57 () ;
} while ( ++ V_30 <= V_76 );
V_30 = 0 ;
do {
if ( ! F_7 ( V_30 , & V_18 ) )
continue;
while ( ! V_80 . V_82 [ V_30 ] )
F_57 () ;
} while ( ++ V_30 <= V_76 );
}
F_58 ( & V_77 , V_59 ) ;
}
}
void F_59 ( void )
{
int V_30 = F_10 () ;
V_80 . V_81 [ V_30 ] = 1 ;
V_80 . V_71 ( V_80 . V_72 , V_80 . V_73 , V_80 . V_74 ,
V_80 . V_75 , V_80 . V_83 ) ;
V_80 . V_82 [ V_30 ] = 1 ;
}
void T_1 F_60 ( void )
{
V_84 [ 1 ] = V_84 [ 1 ] + ( V_85 - V_86 ) ;
V_87 = & V_88 ;
}
