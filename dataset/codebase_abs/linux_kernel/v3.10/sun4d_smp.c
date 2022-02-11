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
void T_1 F_3 ( void * V_4 )
{
int V_3 = F_4 () ;
V_5 [ V_3 ] = 0x6 ;
F_2 ( V_3 ) ;
F_5 ( ( F_6 () & ~ 0x8000 ) | 0x4000 ) ;
}
void T_1 F_7 ( void * V_4 )
{
unsigned long V_6 ;
int V_3 ;
V_3 = F_4 () ;
F_1 ( ( unsigned long * ) & V_7 [ V_3 ] , 1 ) ;
V_8 -> V_9 () ;
V_8 -> V_10 () ;
while ( ( unsigned long ) V_11 [ V_3 ] < V_12 )
F_8 () ;
while ( V_11 [ V_3 ] -> V_13 != V_3 )
F_8 () ;
__asm__ __volatile__("ld [%0], %%g6\n\t"
: : "r" (&current_set[cpuid])
: "memory" );
V_5 [ V_3 ] = 0x9 ;
F_2 ( V_3 ) ;
F_9 ( & V_14 . V_15 ) ;
V_16 -> V_17 = & V_14 ;
V_8 -> V_9 () ;
V_8 -> V_10 () ;
while ( ! F_10 ( V_3 , & V_18 ) )
F_8 () ;
F_11 ( & V_19 , V_6 ) ;
F_5 ( F_6 () & ~ 0x4000 ) ;
F_12 ( & V_19 , V_6 ) ;
}
void T_2 F_13 ( void )
{
F_14 () ;
if ( V_20 )
V_11 [ 0 ] = NULL ;
V_8 -> V_9 () ;
}
int T_1 F_15 ( int V_21 , struct V_22 * V_23 )
{
unsigned long * V_24 = & V_25 ;
int V_26 ;
int V_27 ;
F_16 ( V_21 , & V_27 , NULL ) ;
V_11 [ V_21 ] = F_17 ( V_23 ) ;
V_28 . V_29 = 0 ;
V_28 . V_30 = ( unsigned int ) V_31 ;
V_28 . V_32 = 0 ;
F_18 ( V_33 L_1 , V_21 , V_24 ) ;
V_8 -> V_9 () ;
F_19 ( V_27 ,
& V_28 , 0 , ( char * ) V_24 ) ;
F_18 ( V_33 L_2 ) ;
for ( V_26 = 0 ; V_26 < 10000 ; V_26 ++ ) {
if ( V_7 [ V_21 ] )
break;
F_20 ( 200 ) ;
}
if ( ! ( V_7 [ V_21 ] ) ) {
F_18 ( V_34 L_3 , V_21 ) ;
return - V_35 ;
}
V_8 -> V_9 () ;
return 0 ;
}
void T_2 F_21 ( void )
{
int V_21 , V_36 ;
int * V_37 ;
V_36 = 0 ;
V_37 = & V_36 ;
F_22 (i) {
* V_37 = V_21 ;
V_37 = & F_23 ( V_21 ) . V_38 ;
}
* V_37 = V_36 ;
V_8 -> V_9 () ;
V_39 = 1 ;
F_24 () ;
}
static void T_2 F_14 ( void )
{
int V_13 ;
struct V_40 * V_41 ;
F_18 ( V_33 L_4 , V_42 ) ;
F_25 (cpu) {
V_41 = & F_26 ( V_40 , V_13 ) ;
V_41 -> V_43 = V_41 -> V_44 = V_41 -> V_45 = 0 ;
}
}
void F_27 ( void )
{
struct V_40 * V_41 = & F_28 ( V_40 ) ;
if ( V_41 -> V_43 ) {
V_41 -> V_43 = 0 ;
F_29 () ;
}
if ( V_41 -> V_44 ) {
V_41 -> V_44 = 0 ;
F_30 () ;
}
if ( V_41 -> V_45 ) {
V_41 -> V_45 = 0 ;
F_31 () ;
}
}
static void F_32 ( int V_13 , int V_46 )
{
F_33 ( F_34 ( 0 , V_13 << 3 , 6 + ( ( V_46 >> 1 ) & 7 ) , 1 << ( V_46 - 1 ) ) ) ;
}
static void F_35 ( int V_13 )
{
struct V_40 * V_41 = & F_26 ( V_40 , V_13 ) ;
V_41 -> V_43 = 1 ;
F_32 ( V_13 , V_42 ) ;
}
static void F_36 ( int V_13 )
{
struct V_40 * V_41 = & F_26 ( V_40 , V_13 ) ;
V_41 -> V_44 = 1 ;
F_32 ( V_13 , V_42 ) ;
}
static void F_37 ( int V_13 )
{
struct V_40 * V_41 = & F_26 ( V_40 , V_13 ) ;
V_41 -> V_45 = 1 ;
F_32 ( V_13 , V_42 ) ;
}
static void F_38 ( T_3 V_47 , T_4 V_48 , unsigned long V_49 ,
unsigned long V_50 , unsigned long V_51 ,
unsigned long V_52 )
{
if ( V_39 ) {
register int V_53 = V_54 ;
unsigned long V_6 ;
F_11 ( & V_55 , V_6 ) ;
{
register T_3 T_5 V_56 ( L_5 ) = V_47 ;
register unsigned long T_6 V_56 ( L_6 ) = V_49 ;
register unsigned long T_7 V_56 ( L_7 ) = V_50 ;
register unsigned long T_8 V_56 ( L_8 ) = V_51 ;
register unsigned long T_9 V_56 ( L_9 ) = V_52 ;
register unsigned long T_10 V_56 ( L_10 ) = 0 ;
__asm__ __volatile__(
"std %0, [%6]\n\t"
"std %2, [%6 + 8]\n\t"
"std %4, [%6 + 16]\n\t" : :
"r"(f), "r"(a1), "r"(a2), "r"(a3), "r"(a4), "r"(a5),
"r" (&ccall_info.func));
}
{
register int V_21 ;
F_39 ( F_40 () , & V_48 ) ;
F_41 ( & V_48 , V_57 , & V_48 ) ;
for ( V_21 = 0 ; V_21 <= V_53 ; V_21 ++ ) {
if ( F_10 ( V_21 , & V_48 ) ) {
V_58 . V_59 [ V_21 ] = 0 ;
V_58 . V_60 [ V_21 ] = 0 ;
F_32 ( V_21 , V_61 ) ;
}
}
}
{
register int V_21 ;
V_21 = 0 ;
do {
if ( ! F_10 ( V_21 , & V_48 ) )
continue;
while ( ! V_58 . V_59 [ V_21 ] )
F_8 () ;
} while ( ++ V_21 <= V_53 );
V_21 = 0 ;
do {
if ( ! F_10 ( V_21 , & V_48 ) )
continue;
while ( ! V_58 . V_60 [ V_21 ] )
F_8 () ;
} while ( ++ V_21 <= V_53 );
}
F_12 ( & V_55 , V_6 ) ;
}
}
void F_42 ( void )
{
int V_21 = F_4 () ;
V_58 . V_59 [ V_21 ] = 1 ;
V_58 . V_47 ( V_58 . V_49 , V_58 . V_50 , V_58 . V_51 ,
V_58 . V_52 , V_58 . V_62 ) ;
V_58 . V_60 [ V_21 ] = 1 ;
}
void F_43 ( struct V_63 * V_64 )
{
struct V_63 * V_65 ;
int V_13 = F_4 () ;
struct V_66 * V_67 ;
static int V_68 [ V_69 ] ;
static char V_70 [] = { 0xe , 0xd , 0xb , 0x7 , 0xb , 0xd } ;
V_65 = F_44 ( V_64 ) ;
F_45 ( V_13 ) ;
F_46 ( 0 , 1 ) ;
V_68 [ V_13 ] ++ ;
if ( ! ( V_68 [ V_13 ] & 15 ) ) {
if ( V_68 [ V_13 ] == 0x60 )
V_68 [ V_13 ] = 0 ;
V_5 [ V_13 ] = V_70 [ V_68 [ V_13 ] >> 4 ] ;
F_2 ( V_13 ) ;
}
V_67 = & F_26 ( V_71 , V_13 ) ;
F_47 () ;
V_67 -> V_72 ( V_67 ) ;
F_48 () ;
F_44 ( V_65 ) ;
}
void T_2 F_49 ( void )
{
int V_21 ;
V_73 [ 1 ] = V_73 [ 1 ] + ( V_74 - V_75 ) ;
V_76 = & V_77 ;
for ( V_21 = 0 ; V_21 < V_69 ; V_21 ++ ) {
V_58 . V_59 [ V_21 ] = 1 ;
V_58 . V_60 [ V_21 ] = 1 ;
}
}
