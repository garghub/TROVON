static inline unsigned long F_1 ( volatile unsigned long * V_1 , unsigned long V_2 )
{
__asm__ __volatile__("swap [%1], %0\n\t" :
"=&r" (val), "=&r" (ptr) :
"0" (val), "1" (ptr));
return V_2 ;
}
static inline void F_2 ( int V_3 )
{
V_3 &= 0x1e ;
__asm__ __volatile__ ("stba %0, [%1] %2" : :
"r" ((cpu_leds[cpuid] << 4) | cpu_leds[cpuid+1]),
"r" (ECSR_BASE(cpuid) | BB_LEDS),
"i" (ASI_M_CTL));
}
void T_1 F_3 ( void )
{
int V_3 = F_4 () ;
unsigned long V_4 ;
V_5 [ V_3 ] = 0x6 ;
F_2 ( V_3 ) ;
F_5 ( ( F_6 () & ~ 0x8000 ) | 0x4000 ) ;
V_6 -> V_7 () ;
V_6 -> V_8 () ;
F_7 ( V_3 ) ;
F_8 ( V_3 ) ;
F_9 () ;
F_10 ( V_3 ) ;
V_6 -> V_7 () ;
V_6 -> V_8 () ;
F_1 ( ( unsigned long * ) & V_9 [ V_3 ] , 1 ) ;
V_6 -> V_7 () ;
V_6 -> V_8 () ;
while ( ( unsigned long ) V_10 [ V_3 ] < V_11 )
F_11 () ;
while ( V_10 [ V_3 ] -> V_12 != V_3 )
F_11 () ;
__asm__ __volatile__("ld [%0], %%g6\n\t"
: : "r" (&current_set[cpuid])
: "memory" );
V_5 [ V_3 ] = 0x9 ;
F_2 ( V_3 ) ;
F_12 ( & V_13 . V_14 ) ;
V_15 -> V_16 = & V_13 ;
V_6 -> V_7 () ;
V_6 -> V_8 () ;
F_13 () ;
while ( ! F_14 ( V_3 , & V_17 ) )
F_11 () ;
F_15 ( & V_18 , V_4 ) ;
F_5 ( F_6 () & ~ 0x4000 ) ;
F_16 ( & V_18 , V_4 ) ;
F_17 ( V_3 , true ) ;
}
void T_2 F_18 ( void )
{
F_19 () ;
if ( V_19 )
V_10 [ 0 ] = NULL ;
V_6 -> V_7 () ;
}
int T_1 F_20 ( int V_20 , struct V_21 * V_22 )
{
unsigned long * V_23 = & V_24 ;
int V_25 ;
int V_26 ;
F_21 ( V_20 , & V_26 , NULL ) ;
V_10 [ V_20 ] = F_22 ( V_22 ) ;
V_27 . V_28 = 0 ;
V_27 . V_29 = ( unsigned int ) V_30 ;
V_27 . V_31 = 0 ;
F_23 ( V_32 L_1 , V_20 , V_23 ) ;
V_6 -> V_7 () ;
F_24 ( V_26 ,
& V_27 , 0 , ( char * ) V_23 ) ;
F_23 ( V_32 L_2 ) ;
for ( V_25 = 0 ; V_25 < 10000 ; V_25 ++ ) {
if ( V_9 [ V_20 ] )
break;
F_25 ( 200 ) ;
}
if ( ! ( V_9 [ V_20 ] ) ) {
F_23 ( V_33 L_3 , V_20 ) ;
return - V_34 ;
}
V_6 -> V_7 () ;
return 0 ;
}
void T_2 F_26 ( void )
{
int V_20 , V_35 ;
int * V_36 ;
V_35 = 0 ;
V_36 = & V_35 ;
F_27 (i) {
* V_36 = V_20 ;
V_36 = & F_28 ( V_20 ) . V_37 ;
}
* V_36 = V_35 ;
V_6 -> V_7 () ;
V_38 = 1 ;
F_29 () ;
}
static void T_2 F_19 ( void )
{
int V_12 ;
struct V_39 * V_40 ;
F_23 ( V_32 L_4 , V_41 ) ;
F_30 (cpu) {
V_40 = & F_31 ( V_39 , V_12 ) ;
V_40 -> V_42 = V_40 -> V_43 = V_40 -> V_44 = 0 ;
}
}
void F_32 ( void )
{
struct V_39 * V_40 = & F_33 ( V_39 ) ;
if ( V_40 -> V_42 ) {
V_40 -> V_42 = 0 ;
F_34 () ;
}
if ( V_40 -> V_43 ) {
V_40 -> V_43 = 0 ;
F_35 () ;
}
if ( V_40 -> V_44 ) {
V_40 -> V_44 = 0 ;
F_36 () ;
}
}
static void F_37 ( int V_12 , int V_45 )
{
F_38 ( F_39 ( 0 , V_12 << 3 , 6 + ( ( V_45 >> 1 ) & 7 ) , 1 << ( V_45 - 1 ) ) ) ;
}
static void F_40 ( int V_12 )
{
struct V_39 * V_40 = & F_31 ( V_39 , V_12 ) ;
V_40 -> V_42 = 1 ;
F_37 ( V_12 , V_41 ) ;
}
static void F_41 ( int V_12 )
{
struct V_39 * V_40 = & F_31 ( V_39 , V_12 ) ;
V_40 -> V_43 = 1 ;
F_37 ( V_12 , V_41 ) ;
}
static void F_42 ( int V_12 )
{
struct V_39 * V_40 = & F_31 ( V_39 , V_12 ) ;
V_40 -> V_44 = 1 ;
F_37 ( V_12 , V_41 ) ;
}
static void F_43 ( T_3 V_46 , T_4 V_47 , unsigned long V_48 ,
unsigned long V_49 , unsigned long V_50 ,
unsigned long V_51 )
{
if ( V_38 ) {
register int V_52 = V_53 ;
unsigned long V_4 ;
F_15 ( & V_54 , V_4 ) ;
{
register T_3 T_5 V_55 ( L_5 ) = V_46 ;
register unsigned long T_6 V_55 ( L_6 ) = V_48 ;
register unsigned long T_7 V_55 ( L_7 ) = V_49 ;
register unsigned long T_8 V_55 ( L_8 ) = V_50 ;
register unsigned long T_9 V_55 ( L_9 ) = V_51 ;
register unsigned long T_10 V_55 ( L_10 ) = 0 ;
__asm__ __volatile__(
"std %0, [%6]\n\t"
"std %2, [%6 + 8]\n\t"
"std %4, [%6 + 16]\n\t" : :
"r"(f), "r"(a1), "r"(a2), "r"(a3), "r"(a4), "r"(a5),
"r" (&ccall_info.func));
}
{
register int V_20 ;
F_44 ( F_45 () , & V_47 ) ;
F_46 ( & V_47 , V_56 , & V_47 ) ;
for ( V_20 = 0 ; V_20 <= V_52 ; V_20 ++ ) {
if ( F_14 ( V_20 , & V_47 ) ) {
V_57 . V_58 [ V_20 ] = 0 ;
V_57 . V_59 [ V_20 ] = 0 ;
F_37 ( V_20 , V_60 ) ;
}
}
}
{
register int V_20 ;
V_20 = 0 ;
do {
if ( ! F_14 ( V_20 , & V_47 ) )
continue;
while ( ! V_57 . V_58 [ V_20 ] )
F_11 () ;
} while ( ++ V_20 <= V_52 );
V_20 = 0 ;
do {
if ( ! F_14 ( V_20 , & V_47 ) )
continue;
while ( ! V_57 . V_59 [ V_20 ] )
F_11 () ;
} while ( ++ V_20 <= V_52 );
}
F_16 ( & V_54 , V_4 ) ;
}
}
void F_47 ( void )
{
int V_20 = F_4 () ;
V_57 . V_58 [ V_20 ] = 1 ;
V_57 . V_46 ( V_57 . V_48 , V_57 . V_49 , V_57 . V_50 ,
V_57 . V_51 , V_57 . V_61 ) ;
V_57 . V_59 [ V_20 ] = 1 ;
}
void F_48 ( struct V_62 * V_63 )
{
struct V_62 * V_64 ;
int V_12 = F_4 () ;
struct V_65 * V_66 ;
static int V_67 [ V_68 ] ;
static char V_69 [] = { 0xe , 0xd , 0xb , 0x7 , 0xb , 0xd } ;
V_64 = F_49 ( V_63 ) ;
F_50 ( V_12 ) ;
F_51 ( 0 , 1 ) ;
V_67 [ V_12 ] ++ ;
if ( ! ( V_67 [ V_12 ] & 15 ) ) {
if ( V_67 [ V_12 ] == 0x60 )
V_67 [ V_12 ] = 0 ;
V_5 [ V_12 ] = V_69 [ V_67 [ V_12 ] >> 4 ] ;
F_2 ( V_12 ) ;
}
V_66 = & F_31 ( V_70 , V_12 ) ;
F_52 () ;
V_66 -> V_71 ( V_66 ) ;
F_53 () ;
F_49 ( V_64 ) ;
}
void T_2 F_54 ( void )
{
int V_20 ;
V_72 [ 1 ] = V_72 [ 1 ] + ( V_73 - V_74 ) ;
V_75 = & V_76 ;
for ( V_20 = 0 ; V_20 < V_68 ; V_20 ++ ) {
V_57 . V_58 [ V_20 ] = 1 ;
V_57 . V_59 [ V_20 ] = 1 ;
}
}
