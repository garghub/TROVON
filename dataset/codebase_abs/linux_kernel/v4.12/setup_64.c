static void
F_1 ( struct V_1 * V_2 , const char * V_3 , unsigned int V_4 )
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
while ( * V_14 == ' ' )
V_14 ++ ;
if ( * V_14 == '\0' )
break;
if ( * V_14 == '-' ) {
V_14 ++ ;
while ( * V_14 && * V_14 != ' ' )
F_3 ( * V_14 ++ ) ;
continue;
}
if ( ! strncmp ( V_14 , L_4 , 4 ) )
V_15 = F_10 ( V_14 + 4 , & V_14 ) ;
while ( * V_14 && * V_14 != ' ' )
V_14 ++ ;
}
}
static void T_1 F_11 ( void )
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
void F_15 ( struct V_38 * V_35 ,
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
static void T_1 F_16 ( void )
{
extern void V_39 ( void ) ;
if ( V_9 != V_22 )
return;
F_13 ( & V_40 ,
& V_41 ) ;
F_14 ( & V_42 ,
& V_43 ) ;
if ( V_44 == V_45 ||
V_44 == V_46 )
F_15 ( & V_47 ,
& V_48 ) ;
V_39 () ;
}
static void T_1 F_17 ( void )
{
struct V_49 * V_50 ;
struct V_51 * V_52 ;
V_50 = & V_53 ;
while ( V_50 < & V_54 ) {
unsigned long V_55 , V_27 = V_50 -> V_27 ;
for ( V_55 = 0 ; V_55 < 3 ; V_55 ++ ) {
* ( unsigned int * ) ( V_27 + ( V_55 * 4 ) ) = V_50 -> V_28 [ V_55 ] ;
F_12 () ;
__asm__ __volatile__("flush %0"
: : "r" (addr + (i * 4)));
}
V_50 ++ ;
}
V_52 = & V_56 ;
while ( V_52 < & V_57 ) {
unsigned long V_55 , V_27 = V_52 -> V_27 ;
for ( V_55 = 0 ; V_55 < 6 ; V_55 ++ ) {
* ( unsigned int * ) ( V_27 + ( V_55 * 4 ) ) = V_52 -> V_28 [ V_55 ] ;
F_12 () ;
__asm__ __volatile__("flush %0"
: : "r" (addr + (i * 4)));
}
V_52 ++ ;
}
}
static void T_1 F_18 ( void )
{
struct V_58 * V_17 ;
V_17 = & V_59 ;
while ( V_17 < & V_60 ) {
unsigned long V_55 , V_27 = V_17 -> V_27 ;
for ( V_55 = 0 ; V_55 < 3 ; V_55 ++ ) {
* ( unsigned int * ) ( V_27 + ( V_55 * 4 ) ) = V_17 -> V_28 [ V_55 ] ;
F_12 () ;
__asm__ __volatile__("flush %0"
: : "r" (addr + (i * 4)));
}
V_17 ++ ;
}
}
void T_1 F_19 ( void )
{
int V_61 ;
F_20 () ;
F_11 () ;
F_16 () ;
V_61 = F_21 () ;
if ( V_61 >= V_62 ) {
F_4 ( L_6 ,
V_61 , V_62 ) ;
F_5 () ;
}
F_22 () -> V_61 = V_61 ;
F_23 () ;
F_24 () ;
}
void F_25 ( struct V_63 * V_64 )
{
unsigned long V_65 = V_66 ;
int V_55 , V_67 = 0 ;
F_26 ( V_64 , L_7 ) ;
for ( V_55 = 0 ; V_55 < F_27 ( V_68 ) ; V_55 ++ ) {
unsigned long V_69 = 1UL << V_55 ;
if ( V_68 [ V_55 ] && ( V_65 & V_69 ) ) {
F_28 ( V_64 , L_8 ,
V_67 ? L_9 : L_10 , V_68 [ V_55 ] ) ;
V_67 ++ ;
}
}
if ( V_65 & V_70 ) {
unsigned long V_71 ;
__asm__ __volatile__("rd %%asr26, %0" : "=r" (cfr));
for ( V_55 = 0 ; V_55 < F_27 ( V_72 ) ; V_55 ++ ) {
unsigned long V_69 = 1UL << V_55 ;
if ( V_71 & V_69 ) {
F_28 ( V_64 , L_8 ,
V_67 ? L_9 : L_10 , V_72 [ V_55 ] ) ;
V_67 ++ ;
}
}
}
F_29 ( V_64 , '\n' ) ;
}
static void T_1 F_30 ( int * V_67 , const char * V_73 )
{
if ( ( * V_67 ) == 0 )
F_6 ( V_74 L_11 ) ;
F_6 ( V_75 L_8 ,
( * V_67 ) ? L_9 : L_10 , V_73 ) ;
if ( ++ ( * V_67 ) == 8 ) {
F_6 ( V_75 L_12 ) ;
* V_67 = 0 ;
}
}
static void T_1 F_31 ( int * V_67 )
{
unsigned long V_71 ;
int V_55 ;
__asm__ __volatile__("rd %%asr26, %0" : "=r" (cfr));
for ( V_55 = 0 ; V_55 < F_27 ( V_72 ) ; V_55 ++ ) {
unsigned long V_69 = 1UL << V_55 ;
if ( V_71 & V_69 )
F_30 ( V_67 , V_72 [ V_55 ] ) ;
}
}
static void T_1 F_32 ( unsigned long V_65 )
{
int V_55 , V_67 = 0 ;
for ( V_55 = 0 ; V_55 < F_27 ( V_68 ) ; V_55 ++ ) {
unsigned long V_69 = 1UL << V_55 ;
if ( V_68 [ V_55 ] && ( V_65 & V_69 ) )
F_30 ( & V_67 , V_68 [ V_55 ] ) ;
}
if ( V_65 & V_70 )
F_31 ( & V_67 ) ;
if ( V_67 != 0 )
F_6 ( V_75 L_12 ) ;
}
static unsigned long T_1 F_33 ( void )
{
struct V_76 * V_77 ;
unsigned long V_65 = 0 ;
const char * V_78 ;
int V_79 ;
T_2 V_80 ;
V_77 = F_34 () ;
if ( ! V_77 )
return 0 ;
V_80 = F_35 ( V_77 , V_81 , L_13 ) ;
if ( V_80 == V_81 )
goto V_82;
V_78 = F_36 ( V_77 , V_80 , L_14 , & V_79 ) ;
if ( ! V_78 )
goto V_82;
while ( V_79 ) {
int V_55 , V_83 ;
for ( V_55 = 0 ; V_55 < F_27 ( V_68 ) ; V_55 ++ ) {
unsigned long V_69 = 1UL << V_55 ;
if ( V_68 [ V_55 ] && ! strcmp ( V_78 , V_68 [ V_55 ] ) ) {
V_65 |= V_69 ;
break;
}
}
for ( V_55 = 0 ; V_55 < F_27 ( V_72 ) ; V_55 ++ ) {
if ( ! strcmp ( V_78 , V_72 [ V_55 ] ) )
V_65 |= V_70 ;
}
V_83 = strlen ( V_78 ) + 1 ;
V_78 += V_83 ;
V_79 -= V_83 ;
}
V_82:
F_37 ( V_77 ) ;
return V_65 ;
}
static void T_1 F_38 ( void )
{
unsigned long V_84 = V_66 ;
unsigned long V_85 ;
if ( V_9 == V_10 || V_9 == V_30 )
V_84 |= V_86 ;
else if ( V_9 == V_22 ) {
if ( V_44 == V_87 ||
V_44 == V_88 ||
V_44 == V_89 ||
V_44 == V_90 ||
V_44 == V_91 ||
V_44 == V_92 ||
V_44 == V_45 ||
V_44 == V_46 ||
V_44 == V_93 )
V_84 |= V_94 ;
if ( V_44 == V_88 ||
V_44 == V_89 ||
V_44 == V_90 ||
V_44 == V_91 ||
V_44 == V_92 ||
V_44 == V_45 ||
V_44 == V_46 ||
V_44 == V_93 )
V_84 |= V_95 ;
}
V_84 |= ( V_96 | V_97 | V_98 ) ;
V_85 = F_33 () ;
if ( ! V_85 ) {
if ( V_9 == V_20 )
V_84 |= V_99 ;
if ( V_9 == V_10 || V_9 == V_30 )
V_84 |= V_99 | V_100 ;
if ( V_9 == V_30 ) {
unsigned long V_101 , V_18 ;
__asm__ __volatile__("rdpr %%ver, %0" : "=r" (ver));
V_101 = ( ( V_18 >> 32 ) & 0xffff ) ;
if ( V_101 == V_102 )
V_84 |= V_103 ;
}
if ( V_9 == V_22 ) {
if ( V_44 == V_87 )
V_84 |= V_104 ;
if ( V_44 == V_88 ||
V_44 == V_89 ||
V_44 == V_90 ||
V_44 == V_91 ||
V_44 == V_92 ||
V_44 == V_45 ||
V_44 == V_46 ||
V_44 == V_93 )
V_84 |= ( V_99 | V_100 |
V_104 |
V_103 ) ;
if ( V_44 == V_89 ||
V_44 == V_90 ||
V_44 == V_91 ||
V_44 == V_92 ||
V_44 == V_45 ||
V_44 == V_46 ||
V_44 == V_93 )
V_84 |= ( V_105 | V_106 |
V_107 ) ;
}
}
V_66 = V_84 | V_85 ;
F_32 ( V_66 ) ;
if ( V_66 & V_103 )
F_17 () ;
if ( V_66 & V_108 )
F_18 () ;
}
void T_1 F_39 ( void )
{
unsigned int V_55 , V_109 ;
F_40 (i) {
V_109 = F_41 ( V_55 ) ;
V_110 [ V_55 ] = F_42 ( F_43 ( V_109 ) ,
V_111 ,
V_111 , 0 ) ;
V_112 [ V_55 ] = F_42 ( F_43 ( V_109 ) ,
V_111 ,
V_111 , 0 ) ;
}
}
void T_1 F_44 ( char * * V_113 )
{
* V_113 = F_45 () ;
F_46 ( V_114 , * V_113 , V_115 ) ;
F_47 () ;
F_9 ( * V_113 ) ;
#ifdef F_48
if ( F_49 () )
#endif
F_50 ( & V_6 ) ;
if ( V_9 == V_22 )
F_6 ( L_15 ) ;
else
F_6 ( L_16 ) ;
#ifdef F_51
V_116 = & V_117 ;
#endif
F_52 () ;
if ( ! V_118 )
V_119 &= ~ V_120 ;
V_121 = F_53 ( V_122 ) ;
#ifdef F_54
V_123 = V_124 & V_125 ;
V_126 = ( ( V_124 & V_127 ) != 0 ) ;
V_128 = ( ( V_124 & V_129 ) != 0 ) ;
#endif
F_55 ( & V_130 ) -> V_131 = & V_132 ;
#ifdef F_56
if ( ! V_133 ) {
T_3 V_134 = F_57 ( L_17 ) ;
T_4 V_135 , V_136 , V_137 ;
V_135 = F_58 ( V_134 , L_18 , 0 ) ;
V_136 = F_58 ( V_134 , L_19 , 0 ) ;
V_137 = F_58 ( V_134 , L_20 , 0 ) ;
if ( V_135 && V_136 ) {
V_138 = V_135 ;
V_139 = V_136 ;
if ( V_137 )
V_140 = V_137 ;
#if F_59 ( V_141 ) || F_59 ( V_142 )
V_143 = 0 ;
#endif
}
}
#endif
F_60 ( F_22 () ) ;
F_61 () ;
F_38 () ;
F_62 () ;
F_39 () ;
}
void F_63 ( void )
{
if ( ! V_144 )
return;
F_4 ( L_21 ) ;
F_64 () ;
F_65 () ;
}
