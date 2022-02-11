static void
F_1 ( struct V_1 * V_2 , const char * V_3 , unsigned V_4 )
{
F_2 ( V_3 , V_4 ) ;
}
static void T_1 F_3 ( char V_5 )
{
switch ( V_5 ) {
case 'd' :
case 's' :
break;
case 'h' :
F_4 ( L_1 ) ;
F_5 () ;
break;
case 'p' :
V_6 . V_7 &= ~ V_8 ;
break;
case 'P' :
if ( V_9 != V_10 ) {
F_6 ( L_2 ) ;
break;
}
V_11 = 1 ;
F_7 ( V_12 , V_13 ) ;
F_8 () ;
break;
default:
F_6 ( L_3 , V_5 ) ;
break;
}
}
static void T_1 F_9 ( char * V_14 )
{
while ( * V_14 ) {
while ( * V_14 && * V_14 == ' ' )
V_14 ++ ;
if ( * V_14 == '\0' )
break;
if ( * V_14 == '-' ) {
V_14 ++ ;
while ( * V_14 && * V_14 != ' ' )
F_3 ( * V_14 ++ ) ;
continue;
}
if ( ! strncmp ( V_14 , L_4 , 4 ) ) {
V_15 = F_10 ( V_14 + 4 ,
& V_14 , 0 ) ;
if ( * V_14 == 'K' || * V_14 == 'k' ) {
V_15 <<= 10 ;
V_14 ++ ;
} else if ( * V_14 == 'M' || * V_14 == 'm' ) {
V_15 <<= 20 ;
V_14 ++ ;
}
}
while ( * V_14 && * V_14 != ' ' )
V_14 ++ ;
}
}
void T_1 F_11 ( void )
{
struct V_16 * V_17 ;
unsigned long V_18 ;
int V_19 ;
if ( V_9 == V_20 && ! V_21 )
return;
V_19 = 0 ;
if ( V_9 != V_22 ) {
__asm__ ("rdpr %%ver, %0" : "=r" (ver));
V_19 = ( ( V_18 >> 32UL ) == V_23 ||
( V_18 >> 32UL ) == V_24 ) ;
}
V_17 = & V_25 ;
while ( V_17 < & V_26 ) {
unsigned long V_27 = V_17 -> V_27 ;
unsigned int * V_28 ;
switch ( V_9 ) {
case V_20 :
V_28 = & V_17 -> V_29 [ 0 ] ;
break;
case V_10 :
case V_30 :
if ( V_19 )
V_28 = & V_17 -> V_31 [ 0 ] ;
else
V_28 = & V_17 -> V_32 [ 0 ] ;
break;
case V_22 :
V_28 = & V_17 -> V_33 [ 0 ] ;
break;
default:
F_4 ( L_5 ) ;
F_5 () ;
}
* ( unsigned int * ) ( V_27 + 0 ) = V_28 [ 0 ] ;
F_12 () ;
__asm__ __volatile__("flush %0" : : "r" (addr + 0));
* ( unsigned int * ) ( V_27 + 4 ) = V_28 [ 1 ] ;
F_12 () ;
__asm__ __volatile__("flush %0" : : "r" (addr + 4));
* ( unsigned int * ) ( V_27 + 8 ) = V_28 [ 2 ] ;
F_12 () ;
__asm__ __volatile__("flush %0" : : "r" (addr + 8));
* ( unsigned int * ) ( V_27 + 12 ) = V_28 [ 3 ] ;
F_12 () ;
__asm__ __volatile__("flush %0" : : "r" (addr + 12));
V_17 ++ ;
}
}
void F_13 ( struct V_34 * V_35 ,
struct V_34 * V_36 )
{
while ( V_35 < V_36 ) {
unsigned long V_27 = V_35 -> V_27 ;
* ( unsigned int * ) ( V_27 + 0 ) = V_35 -> V_37 ;
F_12 () ;
__asm__ __volatile__("flush %0" : : "r" (addr + 0));
V_35 ++ ;
}
}
void F_14 ( struct V_38 * V_35 ,
struct V_38 * V_36 )
{
while ( V_35 < V_36 ) {
unsigned long V_27 = V_35 -> V_27 ;
* ( unsigned int * ) ( V_27 + 0 ) = V_35 -> V_28 [ 0 ] ;
F_12 () ;
__asm__ __volatile__("flush %0" : : "r" (addr + 0));
* ( unsigned int * ) ( V_27 + 4 ) = V_35 -> V_28 [ 1 ] ;
F_12 () ;
__asm__ __volatile__("flush %0" : : "r" (addr + 4));
V_35 ++ ;
}
}
void T_1 F_15 ( void )
{
extern void V_39 ( void ) ;
if ( V_9 != V_22 )
return;
F_13 ( & V_40 ,
& V_41 ) ;
F_14 ( & V_42 ,
& V_43 ) ;
V_39 () ;
}
static void T_1 F_16 ( void )
{
struct V_44 * V_45 ;
struct V_46 * V_47 ;
V_45 = & V_48 ;
while ( V_45 < & V_49 ) {
unsigned long V_50 , V_27 = V_45 -> V_27 ;
for ( V_50 = 0 ; V_50 < 3 ; V_50 ++ ) {
* ( unsigned int * ) ( V_27 + ( V_50 * 4 ) ) = V_45 -> V_28 [ V_50 ] ;
F_12 () ;
__asm__ __volatile__("flush %0"
: : "r" (addr + (i * 4)));
}
V_45 ++ ;
}
V_47 = & V_51 ;
while ( V_47 < & V_52 ) {
unsigned long V_50 , V_27 = V_47 -> V_27 ;
for ( V_50 = 0 ; V_50 < 6 ; V_50 ++ ) {
* ( unsigned int * ) ( V_27 + ( V_50 * 4 ) ) = V_47 -> V_28 [ V_50 ] ;
F_12 () ;
__asm__ __volatile__("flush %0"
: : "r" (addr + (i * 4)));
}
V_47 ++ ;
}
}
static void T_1 F_17 ( void )
{
struct V_53 * V_17 ;
V_17 = & V_54 ;
while ( V_17 < & V_55 ) {
unsigned long V_50 , V_27 = V_17 -> V_27 ;
for ( V_50 = 0 ; V_50 < 3 ; V_50 ++ ) {
* ( unsigned int * ) ( V_27 + ( V_50 * 4 ) ) = V_17 -> V_28 [ V_50 ] ;
F_12 () ;
__asm__ __volatile__("flush %0"
: : "r" (addr + (i * 4)));
}
V_17 ++ ;
}
}
void T_1 F_18 ( int V_56 )
{
F_4 ( L_6 ,
V_56 , V_57 ) ;
F_5 () ;
}
void F_19 ( struct V_58 * V_59 )
{
unsigned long V_60 = V_61 ;
int V_50 , V_62 = 0 ;
F_20 ( V_59 , L_7 ) ;
for ( V_50 = 0 ; V_50 < F_21 ( V_63 ) ; V_50 ++ ) {
unsigned long V_64 = 1UL << V_50 ;
if ( V_60 & V_64 ) {
F_22 ( V_59 , L_8 ,
V_62 ? L_9 : L_10 , V_63 [ V_50 ] ) ;
V_62 ++ ;
}
}
if ( V_60 & V_65 ) {
unsigned long V_66 ;
__asm__ __volatile__("rd %%asr26, %0" : "=r" (cfr));
for ( V_50 = 0 ; V_50 < F_21 ( V_67 ) ; V_50 ++ ) {
unsigned long V_64 = 1UL << V_50 ;
if ( V_66 & V_64 ) {
F_22 ( V_59 , L_8 ,
V_62 ? L_9 : L_10 , V_67 [ V_50 ] ) ;
V_62 ++ ;
}
}
}
F_23 ( V_59 , '\n' ) ;
}
static void T_1 F_24 ( int * V_62 , const char * V_68 )
{
if ( ( * V_62 ) == 0 )
F_6 ( V_69 L_11 ) ;
F_6 ( V_70 L_8 ,
( * V_62 ) ? L_9 : L_10 , V_68 ) ;
if ( ++ ( * V_62 ) == 8 ) {
F_6 ( V_70 L_12 ) ;
* V_62 = 0 ;
}
}
static void T_1 F_25 ( int * V_62 )
{
unsigned long V_66 ;
int V_50 ;
__asm__ __volatile__("rd %%asr26, %0" : "=r" (cfr));
for ( V_50 = 0 ; V_50 < F_21 ( V_67 ) ; V_50 ++ ) {
unsigned long V_64 = 1UL << V_50 ;
if ( V_66 & V_64 )
F_24 ( V_62 , V_67 [ V_50 ] ) ;
}
}
static void T_1 F_26 ( unsigned long V_60 )
{
int V_50 , V_62 = 0 ;
for ( V_50 = 0 ; V_50 < F_21 ( V_63 ) ; V_50 ++ ) {
unsigned long V_64 = 1UL << V_50 ;
if ( V_60 & V_64 )
F_24 ( & V_62 , V_63 [ V_50 ] ) ;
}
if ( V_60 & V_65 )
F_25 ( & V_62 ) ;
if ( V_62 != 0 )
F_6 ( V_70 L_12 ) ;
}
static unsigned long T_1 F_27 ( void )
{
struct V_71 * V_72 ;
unsigned long V_60 = 0 ;
const char * V_73 ;
int V_74 ;
T_2 V_75 ;
V_72 = F_28 () ;
if ( ! V_72 )
return 0 ;
V_75 = F_29 ( V_72 , V_76 , L_13 ) ;
if ( V_75 == V_76 )
goto V_77;
V_73 = F_30 ( V_72 , V_75 , L_14 , & V_74 ) ;
if ( ! V_73 )
goto V_77;
while ( V_74 ) {
int V_50 , V_78 ;
for ( V_50 = 0 ; V_50 < F_21 ( V_63 ) ; V_50 ++ ) {
unsigned long V_64 = 1UL << V_50 ;
if ( ! strcmp ( V_73 , V_63 [ V_50 ] ) ) {
V_60 |= V_64 ;
break;
}
}
for ( V_50 = 0 ; V_50 < F_21 ( V_67 ) ; V_50 ++ ) {
if ( ! strcmp ( V_73 , V_67 [ V_50 ] ) )
V_60 |= V_65 ;
}
V_78 = strlen ( V_73 ) + 1 ;
V_73 += V_78 ;
V_74 -= V_78 ;
}
V_77:
F_31 ( V_72 ) ;
return V_60 ;
}
static void T_1 F_32 ( void )
{
unsigned long V_79 = V_61 ;
unsigned long V_80 ;
if ( V_9 == V_10 || V_9 == V_30 )
V_79 |= V_81 ;
else if ( V_9 == V_22 ) {
if ( V_82 == V_83 ||
V_82 == V_84 ||
V_82 == V_85 ||
V_82 == V_86 ||
V_82 == V_87 ||
V_82 == V_88 )
V_79 |= V_89 ;
if ( V_82 == V_84 ||
V_82 == V_85 ||
V_82 == V_86 ||
V_82 == V_87 ||
V_82 == V_88 )
V_79 |= V_90 ;
}
V_79 |= ( V_91 | V_92 | V_93 ) ;
V_80 = F_27 () ;
if ( ! V_80 ) {
if ( V_9 == V_20 )
V_79 |= V_94 ;
if ( V_9 == V_10 || V_9 == V_30 )
V_79 |= V_94 | V_95 ;
if ( V_9 == V_30 ) {
unsigned long V_96 , V_18 ;
__asm__ __volatile__("rdpr %%ver, %0" : "=r" (ver));
V_96 = ( ( V_18 >> 32 ) & 0xffff ) ;
if ( V_96 == V_97 )
V_79 |= V_98 ;
}
if ( V_9 == V_22 ) {
if ( V_82 == V_83 )
V_79 |= V_99 ;
if ( V_82 == V_84 ||
V_82 == V_85 ||
V_82 == V_86 ||
V_82 == V_87 ||
V_82 == V_88 )
V_79 |= ( V_94 | V_95 |
V_99 |
V_98 ) ;
if ( V_82 == V_85 ||
V_82 == V_86 ||
V_82 == V_87 ||
V_82 == V_88 )
V_79 |= ( V_100 | V_101 |
V_102 ) ;
}
}
V_61 = V_79 | V_80 ;
F_26 ( V_61 ) ;
if ( V_61 & V_98 )
F_16 () ;
if ( V_61 & V_103 )
F_17 () ;
}
void T_1 F_33 ( char * * V_104 )
{
* V_104 = F_34 () ;
F_35 ( V_105 , * V_104 , V_106 ) ;
F_36 () ;
F_9 ( * V_104 ) ;
#ifdef F_37
if ( F_38 () )
#endif
F_39 ( & V_6 ) ;
if ( V_9 == V_22 )
F_6 ( L_15 ) ;
else
F_6 ( L_16 ) ;
#ifdef F_40
V_107 = & V_108 ;
#endif
F_41 () ;
if ( ! V_109 )
V_110 &= ~ V_111 ;
V_112 = F_42 ( V_113 ) ;
#ifdef F_43
V_114 = V_115 & V_116 ;
V_117 = ( ( V_115 & V_118 ) != 0 ) ;
V_119 = ( ( V_115 & V_120 ) != 0 ) ;
#endif
F_44 ( & V_121 ) -> V_122 = & V_123 ;
#ifdef F_45
if ( ! V_124 ) {
T_3 V_125 = F_46 ( L_17 ) ;
T_4 V_126 , V_127 , V_128 ;
V_126 = F_47 ( V_125 , L_18 , 0 ) ;
V_127 = F_47 ( V_125 , L_19 , 0 ) ;
V_128 = F_47 ( V_125 , L_20 , 0 ) ;
if ( V_126 && V_127 ) {
V_129 = V_126 ;
V_130 = V_127 ;
if ( V_128 )
V_131 = V_128 ;
#if F_48 ( V_132 ) || F_48 ( V_133 )
V_134 = 0 ;
#endif
}
}
#endif
F_49 ( F_50 () ) ;
F_51 () ;
F_32 () ;
}
void F_52 ( void )
{
if ( ! V_135 )
return;
F_4 ( L_21 ) ;
F_53 () ;
F_54 () ;
}
