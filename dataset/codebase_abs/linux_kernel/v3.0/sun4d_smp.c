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
F_7 () ;
F_8 () ;
F_9 ( V_3 ) ;
F_10 () ;
F_11 () ;
F_12 ( V_3 ) ;
F_7 () ;
F_8 () ;
F_1 ( ( unsigned long * ) & V_6 [ V_3 ] , 1 ) ;
F_7 () ;
F_8 () ;
while ( ( unsigned long ) V_7 [ V_3 ] < V_8 )
F_13 () ;
while ( V_7 [ V_3 ] -> V_9 != V_3 )
F_13 () ;
__asm__ __volatile__("ld [%0], %%g6\n\t"
: : "r" (&current_set[cpuid])
: "memory" );
V_5 [ V_3 ] = 0x9 ;
F_2 ( V_3 ) ;
F_14 ( & V_10 . V_11 ) ;
V_12 -> V_13 = & V_10 ;
F_7 () ;
F_8 () ;
F_15 () ;
while ( ! F_16 ( V_3 , & V_14 ) )
F_13 () ;
F_17 ( & V_15 , V_4 ) ;
F_5 ( F_6 () & ~ 0x4000 ) ;
F_18 ( & V_15 , V_4 ) ;
F_19 ( V_3 , true ) ;
}
void T_2 F_20 ( void )
{
F_21 () ;
if ( V_16 )
V_7 [ 0 ] = NULL ;
F_10 () ;
F_7 () ;
}
int T_1 F_22 ( int V_17 )
{
unsigned long * V_18 = & V_19 ;
struct V_20 * V_21 ;
int V_22 ;
int V_23 ;
F_23 ( V_17 , & V_23 , NULL ) ;
V_21 = F_24 ( V_17 ) ;
V_7 [ V_17 ] = F_25 ( V_21 ) ;
V_24 . V_25 = 0 ;
V_24 . V_26 = ( unsigned int ) V_27 ;
V_24 . V_28 = 0 ;
F_26 ( V_29 L_1 , V_17 , V_18 ) ;
F_7 () ;
F_27 ( V_23 ,
& V_24 , 0 , ( char * ) V_18 ) ;
F_26 ( V_29 L_2 ) ;
for ( V_22 = 0 ; V_22 < 10000 ; V_22 ++ ) {
if ( V_6 [ V_17 ] )
break;
F_28 ( 200 ) ;
}
if ( ! ( V_6 [ V_17 ] ) ) {
F_26 ( V_30 L_3 , V_17 ) ;
return - V_31 ;
}
F_7 () ;
return 0 ;
}
void T_2 F_29 ( void )
{
int V_17 , V_32 ;
int * V_33 ;
V_32 = 0 ;
V_33 = & V_32 ;
F_30 (i) {
* V_33 = V_17 ;
V_33 = & F_31 ( V_17 ) . V_34 ;
}
* V_33 = V_32 ;
F_7 () ;
V_35 = 1 ;
F_32 () ;
}
static void T_2 F_21 ( void )
{
int V_9 ;
struct V_36 * V_37 ;
F_26 ( V_29 L_4 , V_38 ) ;
F_33 (cpu) {
V_37 = & F_34 ( V_36 , V_9 ) ;
V_37 -> V_39 = V_37 -> V_40 = V_37 -> V_41 = 0 ;
}
}
void F_35 ( void )
{
struct V_36 * V_37 = & F_36 ( V_36 ) ;
if ( V_37 -> V_39 ) {
V_37 -> V_39 = 0 ;
F_37 () ;
}
if ( V_37 -> V_40 ) {
V_37 -> V_40 = 0 ;
F_38 () ;
}
if ( V_37 -> V_41 ) {
V_37 -> V_41 = 0 ;
F_39 () ;
}
}
static void F_40 ( int V_9 )
{
struct V_36 * V_37 = & F_34 ( V_36 , V_9 ) ;
V_37 -> V_39 = 1 ;
F_41 ( V_9 , V_38 ) ;
}
static void F_42 ( int V_9 )
{
struct V_36 * V_37 = & F_34 ( V_36 , V_9 ) ;
V_37 -> V_40 = 1 ;
F_41 ( V_9 , V_38 ) ;
}
static void F_43 ( int V_9 )
{
struct V_36 * V_37 = & F_34 ( V_36 , V_9 ) ;
V_37 -> V_41 = 1 ;
F_41 ( V_9 , V_38 ) ;
}
static void F_44 ( T_3 V_42 , T_4 V_43 , unsigned long V_44 ,
unsigned long V_45 , unsigned long V_46 ,
unsigned long V_47 )
{
if ( V_35 ) {
register int V_48 = V_49 ;
unsigned long V_4 ;
F_17 ( & V_50 , V_4 ) ;
{
register T_3 T_5 V_51 ( L_5 ) = V_42 ;
register unsigned long T_6 V_51 ( L_6 ) = V_44 ;
register unsigned long T_7 V_51 ( L_7 ) = V_45 ;
register unsigned long T_8 V_51 ( L_8 ) = V_46 ;
register unsigned long T_9 V_51 ( L_9 ) = V_47 ;
register unsigned long T_10 V_51 ( L_10 ) = 0 ;
__asm__ __volatile__(
"std %0, [%6]\n\t"
"std %2, [%6 + 8]\n\t"
"std %4, [%6 + 16]\n\t" : :
"r"(f), "r"(a1), "r"(a2), "r"(a3), "r"(a4), "r"(a5),
"r" (&ccall_info.func));
}
{
register int V_17 ;
F_45 ( F_46 () , & V_43 ) ;
F_47 ( & V_43 , V_52 , & V_43 ) ;
for ( V_17 = 0 ; V_17 <= V_48 ; V_17 ++ ) {
if ( F_16 ( V_17 , & V_43 ) ) {
V_53 . V_54 [ V_17 ] = 0 ;
V_53 . V_55 [ V_17 ] = 0 ;
F_41 ( V_17 , V_56 ) ;
}
}
}
{
register int V_17 ;
V_17 = 0 ;
do {
if ( ! F_16 ( V_17 , & V_43 ) )
continue;
while ( ! V_53 . V_54 [ V_17 ] )
F_13 () ;
} while ( ++ V_17 <= V_48 );
V_17 = 0 ;
do {
if ( ! F_16 ( V_17 , & V_43 ) )
continue;
while ( ! V_53 . V_55 [ V_17 ] )
F_13 () ;
} while ( ++ V_17 <= V_48 );
}
F_18 ( & V_50 , V_4 ) ;
}
}
void F_48 ( void )
{
int V_17 = F_4 () ;
V_53 . V_54 [ V_17 ] = 1 ;
V_53 . V_42 ( V_53 . V_44 , V_53 . V_45 , V_53 . V_46 ,
V_53 . V_47 , V_53 . V_57 ) ;
V_53 . V_55 [ V_17 ] = 1 ;
}
void F_49 ( struct V_58 * V_59 )
{
struct V_58 * V_60 ;
int V_9 = F_4 () ;
static int V_61 [ V_62 ] ;
static char V_63 [] = { 0xe , 0xd , 0xb , 0x7 , 0xb , 0xd } ;
V_60 = F_50 ( V_59 ) ;
F_51 ( V_9 ) ;
F_52 ( 0 , 1 ) ;
V_61 [ V_9 ] ++ ;
if ( ! ( V_61 [ V_9 ] & 15 ) ) {
if ( V_61 [ V_9 ] == 0x60 )
V_61 [ V_9 ] = 0 ;
V_5 [ V_9 ] = V_63 [ V_61 [ V_9 ] >> 4 ] ;
F_2 ( V_9 ) ;
}
F_53 ( V_64 ) ;
if ( ! -- F_54 ( V_9 ) ) {
int V_65 = F_55 ( V_59 ) ;
F_56 () ;
F_57 ( V_65 ) ;
F_58 () ;
F_54 ( V_9 ) = F_59 ( V_9 ) ;
}
F_50 ( V_60 ) ;
}
static void T_1 F_10 ( void )
{
int V_9 = F_4 () ;
F_54 ( V_9 ) = F_59 ( V_9 ) = 1 ;
F_60 ( V_9 , V_66 ) ;
}
void T_2 F_61 ( unsigned * V_67 )
{
int V_68 = * V_67 & 0x3e000000 ;
V_67 [ 0 ] = 0xc0800800 | V_68 ;
V_67 [ 1 ] = 0x01000000 ;
V_67 [ 2 ] = 0x01000000 ;
}
void T_2 F_62 ( unsigned * V_67 )
{
int V_68 = * V_67 & 0x3e000000 ;
V_67 [ 0 ] = 0xc0800800 | V_68 ;
V_67 [ 2 ] = 0x81282002 | V_68 | ( V_68 >> 11 ) ;
V_67 [ 4 ] = 0x01000000 ;
}
void T_2 F_63 ( void )
{
int V_17 ;
V_69 [ 1 ] = V_69 [ 1 ] + ( V_70 - V_71 ) ;
F_64 ( V_72 , F_61 ) ;
F_64 ( V_73 , F_62 ) ;
F_65 ( V_74 , F_44 , V_75 ) ;
F_65 ( V_76 , V_77 , V_75 ) ;
F_65 ( V_78 , F_43 , V_75 ) ;
F_65 ( V_79 , F_40 , V_75 ) ;
F_65 ( V_80 , F_42 , V_75 ) ;
for ( V_17 = 0 ; V_17 < V_62 ; V_17 ++ ) {
V_53 . V_54 [ V_17 ] = 1 ;
V_53 . V_55 [ V_17 ] = 1 ;
}
}
