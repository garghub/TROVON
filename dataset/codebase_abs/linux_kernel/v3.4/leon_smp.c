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
F_4 () ;
F_5 () ;
F_6 () ;
F_7 ( V_3 ) ;
F_8 () ;
F_9 () ;
F_10 ( V_3 ) ;
F_4 () ;
F_5 () ;
F_1 ( & V_4 [ V_3 ] , 1 ) ;
F_4 () ;
F_5 () ;
__asm__ __volatile__("ld [%0], %%g6\n\t" : : "r"(&current_set[cpuid])
: "memory" );
F_11 ( & V_5 . V_6 ) ;
V_7 -> V_8 = & V_5 ;
while ( ! F_12 ( V_3 , & V_9 ) )
F_13 () ;
F_14 () ;
F_15 ( V_3 , true ) ;
}
void T_2 F_6 ( void )
{
unsigned long V_10 = F_16 () ;
int V_11 = F_17 () ;
if ( F_18 ( V_10 ) > 4 ) {
F_19 ( V_12 L_1 ,
( unsigned int ) F_18 ( V_10 ) ,
( unsigned int ) V_10 , ( unsigned int ) V_11 ) ;
F_20 () ;
} else {
if ( V_10 & V_13 ) {
F_21 () ;
} else {
F_19 ( V_12 L_2 ,
V_11 ) ;
F_20 () ;
}
}
F_4 () ;
F_5 () ;
}
void F_22 ( unsigned int V_14 )
{
int V_15 =
( ( F_23 ( & ( V_16 -> V_17 ) ) >>
V_18 ) & 1 ) ;
if ( ! V_15 ) {
F_24 ( L_3 ,
F_25 () ) ;
if ( F_25 () > 1 ) {
F_26 () ;
} else {
F_24 ( L_4 ) ;
return;
}
}
F_27 ( & ( V_16 -> V_19 ) , V_14 ) ;
}
unsigned int F_28 ( void )
{
unsigned int V_14 ;
V_14 = F_29 ( & ( V_16 -> V_19 ) ) ;
return V_14 ;
}
int F_25 ( void )
{
int V_20 =
( ( F_23 ( & ( V_16 -> V_17 ) ) >>
V_21 ) & 0xf ) + 1 ;
return V_20 ;
}
void T_2 F_30 ( void )
{
int V_20 = F_25 () ;
int V_11 = F_17 () ;
F_31 () ;
F_19 ( V_12 L_5 , ( unsigned int ) V_11 ,
( unsigned int ) V_20 , ( unsigned int ) V_22 ,
( unsigned int ) & ( V_16 -> V_17 ) ) ;
F_32 ( V_23 , V_11 ) ;
F_32 ( V_24 , V_11 ) ;
F_32 ( V_25 , V_11 ) ;
F_22 ( 1 << V_24 ) ;
F_6 () ;
F_8 () ;
F_4 () ;
}
int T_1 F_33 ( int V_26 )
{
struct V_27 * V_28 ;
int V_29 ;
V_28 = F_34 ( V_26 ) ;
V_30 [ V_26 ] = F_35 ( V_28 ) ;
V_31 . V_32 = 0 ;
V_31 . V_33 = ( unsigned int ) V_34 ;
V_31 . V_35 = 0 ;
F_19 ( V_12 L_6 , ( unsigned int ) V_26 ,
( unsigned int ) & V_16 -> V_17 ) ;
F_4 () ;
F_27 ( & V_16 -> V_14 [ V_26 ] , 0 ) ;
F_27 ( & ( V_16 -> V_17 ) , 1 << V_26 ) ;
for ( V_29 = 0 ; V_29 < 10000 ; V_29 ++ ) {
if ( V_4 [ V_26 ] )
break;
F_36 ( 200 ) ;
}
F_19 ( V_12 L_7 , ( unsigned int ) V_26 ) ;
if ( ! ( V_4 [ V_26 ] ) ) {
F_19 ( V_36 L_8 , V_26 ) ;
return - V_37 ;
} else {
F_32 ( V_23 , V_26 ) ;
F_32 ( V_24 , V_26 ) ;
F_32 ( V_25 , V_26 ) ;
}
F_4 () ;
return 0 ;
}
void T_2 F_37 ( void )
{
int V_26 , V_38 ;
int * V_39 ;
V_38 = 0 ;
V_39 = & V_38 ;
for ( V_26 = 0 ; V_26 < V_22 ; V_26 ++ ) {
if ( F_38 ( V_26 ) ) {
* V_39 = V_26 ;
V_39 = & F_39 ( V_26 ) . V_40 ;
}
}
* V_39 = V_38 ;
F_4 () ;
if ( ! F_40 ( 1 ) ) {
F_41 ( F_42 ( & V_41 ) ) ;
F_43 ( F_42 ( & V_41 ) ) ;
F_44 ( ( unsigned long ) & V_41 ) ;
V_42 ++ ;
V_43 ++ ;
}
if ( ! F_40 ( 2 ) ) {
F_41 ( F_42 ( & V_44 ) ) ;
F_43 ( F_42 ( & V_44 ) ) ;
F_44 ( ( unsigned long ) & V_44 ) ;
V_42 ++ ;
V_43 ++ ;
}
if ( ! F_40 ( 3 ) ) {
F_41 ( F_42 ( & V_45 ) ) ;
F_43 ( F_42 ( & V_45 ) ) ;
F_44 ( ( unsigned long ) & V_45 ) ;
V_42 ++ ;
V_43 ++ ;
}
V_46 = 1 ;
}
void F_45 ( int V_47 )
{
}
static void T_2 F_31 ( void )
{
int V_47 , V_48 ;
struct V_49 * V_50 ;
struct V_51 * V_52 ;
struct V_53 * V_54 ;
struct V_55 * V_56 ;
unsigned long V_57 ;
V_54 = F_46 ( L_9 ) ;
if ( V_54 ) {
V_52 = F_47 ( V_54 , L_10 , & V_48 ) ;
if ( V_52 && ( * ( int * ) V_52 -> V_58 ) )
V_25 = * ( int * ) V_52 -> V_58 ;
}
F_19 ( V_12 L_11 , V_25 ) ;
F_48 ( V_57 ) ;
V_56 = & V_59 [ V_60 + ( V_25 - 1 ) ] ;
V_56 -> V_61 += V_62 - V_63 ;
F_4 () ;
F_49 ( V_57 ) ;
F_50 (cpu) {
V_50 = & F_51 ( V_49 , V_47 ) ;
V_50 -> V_64 = V_50 -> V_65 = V_50 -> V_66 = 0 ;
}
}
static void F_52 ( int V_47 )
{
struct V_49 * V_50 = & F_51 ( V_49 , V_47 ) ;
V_50 -> V_64 = 1 ;
F_53 ( V_47 , V_25 ) ;
}
static void F_54 ( int V_47 )
{
struct V_49 * V_50 = & F_51 ( V_49 , V_47 ) ;
V_50 -> V_65 = 1 ;
F_53 ( V_47 , V_25 ) ;
}
static void F_55 ( int V_47 )
{
struct V_49 * V_50 = & F_51 ( V_49 , V_47 ) ;
V_50 -> V_66 = 1 ;
F_53 ( V_47 , V_25 ) ;
}
void F_56 ( void )
{
struct V_49 * V_50 = & F_57 ( V_49 ) ;
if ( V_50 -> V_64 ) {
V_50 -> V_64 = 0 ;
F_58 () ;
}
if ( V_50 -> V_65 ) {
V_50 -> V_65 = 0 ;
F_59 () ;
}
if ( V_50 -> V_66 ) {
V_50 -> V_66 = 0 ;
F_60 () ;
}
}
static void F_61 ( T_3 V_67 , T_4 V_14 , unsigned long V_68 ,
unsigned long V_69 , unsigned long V_70 ,
unsigned long V_71 )
{
if ( V_46 ) {
register int V_72 = V_22 - 1 ;
unsigned long V_57 ;
F_62 ( & V_73 , V_57 ) ;
{
register T_3 T_5 V_74 ( L_12 ) = V_67 ;
register unsigned long T_6 V_74 ( L_13 ) = V_68 ;
register unsigned long T_7 V_74 ( L_14 ) = V_69 ;
register unsigned long T_8 V_74 ( L_15 ) = V_70 ;
register unsigned long T_9 V_74 ( L_16 ) = V_71 ;
register unsigned long T_10 V_74 ( L_17 ) = 0 ;
__asm__ __volatile__("std %0, [%6]\n\t"
"std %2, [%6 + 8]\n\t"
"std %4, [%6 + 16]\n\t" : :
"r"(f), "r"(a1), "r"(a2), "r"(a3),
"r"(a4), "r"(a5),
"r"(&ccall_info.func));
}
{
register int V_26 ;
F_63 ( F_17 () , & V_14 ) ;
F_64 ( & V_14 , V_75 , & V_14 ) ;
for ( V_26 = 0 ; V_26 <= V_72 ; V_26 ++ ) {
if ( F_12 ( V_26 , & V_14 ) ) {
V_76 . V_77 [ V_26 ] = 0 ;
V_76 . V_78 [ V_26 ] = 0 ;
F_53 ( V_26 , V_23 ) ;
}
}
}
{
register int V_26 ;
V_26 = 0 ;
do {
if ( ! F_12 ( V_26 , & V_14 ) )
continue;
while ( ! V_76 . V_77 [ V_26 ] )
F_65 () ;
} while ( ++ V_26 <= V_72 );
V_26 = 0 ;
do {
if ( ! F_12 ( V_26 , & V_14 ) )
continue;
while ( ! V_76 . V_78 [ V_26 ] )
F_65 () ;
} while ( ++ V_26 <= V_72 );
}
F_66 ( & V_73 , V_57 ) ;
}
}
void F_67 ( void )
{
int V_26 = F_17 () ;
V_76 . V_77 [ V_26 ] = 1 ;
V_76 . V_67 ( V_76 . V_68 , V_76 . V_69 , V_76 . V_70 ,
V_76 . V_71 , V_76 . V_79 ) ;
V_76 . V_78 [ V_26 ] = 1 ;
}
T_11 F_68 ( int V_80 , void * V_81 )
{
int V_47 = F_17 () ;
F_69 ( V_47 ) ;
F_70 ( V_82 ) ;
if ( ! -- F_71 ( V_47 ) ) {
int V_83 = F_72 ( F_73 () ) ;
F_74 ( V_83 ) ;
F_71 ( V_47 ) = F_75 ( V_47 ) ;
}
return V_84 ;
}
static void T_2 F_8 ( void )
{
int V_47 = F_17 () ;
F_71 ( V_47 ) = F_75 ( V_47 ) = 1 ;
}
void T_2 F_76 ( unsigned * V_85 )
{
int V_86 = * V_85 & 0x3e000000 ;
int V_87 = V_86 >> 11 ;
V_85 [ 0 ] = 0x81444000 | V_86 ;
V_85 [ 1 ] = 0x8130201c | V_86 | V_87 ;
V_85 [ 2 ] = 0x01000000 ;
}
void T_2 F_77 ( unsigned * V_85 )
{
int V_86 = * V_85 & 0x3e000000 ;
int V_87 = V_86 >> 11 ;
V_85 [ 0 ] = 0x81444000 | V_86 ;
V_85 [ 2 ] = 0x8130201c | V_86 | V_87 ;
V_85 [ 4 ] = 0x81282002 | V_86 | V_87 ;
}
void T_2 F_78 ( void )
{
V_88 [ 1 ] = V_88 [ 1 ] + ( V_89 - V_90 ) ;
F_79 ( V_91 , F_76 ) ;
F_79 ( V_92 , F_77 ) ;
F_80 ( V_93 , F_61 , V_94 ) ;
F_80 ( V_95 , V_96 ,
V_94 ) ;
F_80 ( V_97 , F_55 , V_94 ) ;
F_80 ( V_98 , F_52 , V_94 ) ;
F_80 ( V_99 , F_54 , V_94 ) ;
}
