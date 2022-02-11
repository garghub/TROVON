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
switch ( V_44 ) {
case V_45 :
case V_46 :
case V_47 :
F_15 ( & V_48 ,
& V_49 ) ;
break;
default:
break;
}
if ( V_44 != V_50 ) {
F_13 ( & V_51 ,
& V_52 ) ;
}
V_39 () ;
}
static void T_1 F_17 ( void )
{
struct V_53 * V_54 ;
struct V_55 * V_56 ;
V_54 = & V_57 ;
while ( V_54 < & V_58 ) {
unsigned long V_59 , V_27 = V_54 -> V_27 ;
for ( V_59 = 0 ; V_59 < 3 ; V_59 ++ ) {
* ( unsigned int * ) ( V_27 + ( V_59 * 4 ) ) = V_54 -> V_28 [ V_59 ] ;
F_12 () ;
__asm__ __volatile__("flush %0"
: : "r" (addr + (i * 4)));
}
V_54 ++ ;
}
V_56 = & V_60 ;
while ( V_56 < & V_61 ) {
unsigned long V_59 , V_27 = V_56 -> V_27 ;
for ( V_59 = 0 ; V_59 < 6 ; V_59 ++ ) {
* ( unsigned int * ) ( V_27 + ( V_59 * 4 ) ) = V_56 -> V_28 [ V_59 ] ;
F_12 () ;
__asm__ __volatile__("flush %0"
: : "r" (addr + (i * 4)));
}
V_56 ++ ;
}
}
static void T_1 F_18 ( void )
{
struct V_62 * V_17 ;
V_17 = & V_63 ;
while ( V_17 < & V_64 ) {
unsigned long V_59 , V_27 = V_17 -> V_27 ;
for ( V_59 = 0 ; V_59 < 3 ; V_59 ++ ) {
* ( unsigned int * ) ( V_27 + ( V_59 * 4 ) ) = V_17 -> V_28 [ V_59 ] ;
F_12 () ;
__asm__ __volatile__("flush %0"
: : "r" (addr + (i * 4)));
}
V_17 ++ ;
}
}
void T_1 F_19 ( void )
{
int V_65 ;
F_20 () ;
F_11 () ;
F_16 () ;
F_21 () ;
V_65 = F_22 () ;
if ( V_65 >= V_66 ) {
F_4 ( L_6 ,
V_65 , V_66 ) ;
F_5 () ;
}
F_23 () -> V_65 = V_65 ;
F_24 () ;
F_25 () ;
F_26 () ;
}
void F_27 ( struct V_67 * V_68 )
{
unsigned long V_69 = V_70 ;
int V_59 , V_71 = 0 ;
F_28 ( V_68 , L_7 ) ;
for ( V_59 = 0 ; V_59 < F_29 ( V_72 ) ; V_59 ++ ) {
unsigned long V_73 = 1UL << V_59 ;
if ( V_72 [ V_59 ] && ( V_69 & V_73 ) ) {
F_30 ( V_68 , L_8 ,
V_71 ? L_9 : L_10 , V_72 [ V_59 ] ) ;
V_71 ++ ;
}
}
if ( V_69 & V_74 ) {
unsigned long V_75 ;
__asm__ __volatile__("rd %%asr26, %0" : "=r" (cfr));
for ( V_59 = 0 ; V_59 < F_29 ( V_76 ) ; V_59 ++ ) {
unsigned long V_73 = 1UL << V_59 ;
if ( V_75 & V_73 ) {
F_30 ( V_68 , L_8 ,
V_71 ? L_9 : L_10 , V_76 [ V_59 ] ) ;
V_71 ++ ;
}
}
}
F_31 ( V_68 , '\n' ) ;
}
static void T_1 F_32 ( int * V_71 , const char * V_77 )
{
if ( ( * V_71 ) == 0 )
F_6 ( V_78 L_11 ) ;
F_6 ( V_79 L_8 ,
( * V_71 ) ? L_9 : L_10 , V_77 ) ;
if ( ++ ( * V_71 ) == 8 ) {
F_6 ( V_79 L_12 ) ;
* V_71 = 0 ;
}
}
static void T_1 F_33 ( int * V_71 )
{
unsigned long V_75 ;
int V_59 ;
__asm__ __volatile__("rd %%asr26, %0" : "=r" (cfr));
for ( V_59 = 0 ; V_59 < F_29 ( V_76 ) ; V_59 ++ ) {
unsigned long V_73 = 1UL << V_59 ;
if ( V_75 & V_73 )
F_32 ( V_71 , V_76 [ V_59 ] ) ;
}
}
static void T_1 F_34 ( unsigned long V_69 )
{
int V_59 , V_71 = 0 ;
for ( V_59 = 0 ; V_59 < F_29 ( V_72 ) ; V_59 ++ ) {
unsigned long V_73 = 1UL << V_59 ;
if ( V_72 [ V_59 ] && ( V_69 & V_73 ) )
F_32 ( & V_71 , V_72 [ V_59 ] ) ;
}
if ( V_69 & V_74 )
F_33 ( & V_71 ) ;
if ( V_71 != 0 )
F_6 ( V_79 L_12 ) ;
}
static unsigned long T_1 F_35 ( void )
{
struct V_80 * V_81 ;
unsigned long V_69 = 0 ;
const char * V_82 ;
int V_83 ;
T_2 V_84 ;
V_81 = F_36 () ;
if ( ! V_81 )
return 0 ;
V_84 = F_37 ( V_81 , V_85 , L_13 ) ;
if ( V_84 == V_85 )
goto V_86;
V_82 = F_38 ( V_81 , V_84 , L_14 , & V_83 ) ;
if ( ! V_82 )
goto V_86;
while ( V_83 ) {
int V_59 , V_87 ;
for ( V_59 = 0 ; V_59 < F_29 ( V_72 ) ; V_59 ++ ) {
unsigned long V_73 = 1UL << V_59 ;
if ( V_72 [ V_59 ] && ! strcmp ( V_82 , V_72 [ V_59 ] ) ) {
V_69 |= V_73 ;
break;
}
}
for ( V_59 = 0 ; V_59 < F_29 ( V_76 ) ; V_59 ++ ) {
if ( ! strcmp ( V_82 , V_76 [ V_59 ] ) )
V_69 |= V_74 ;
}
V_87 = strlen ( V_82 ) + 1 ;
V_82 += V_87 ;
V_83 -= V_87 ;
}
V_86:
F_39 ( V_81 ) ;
return V_69 ;
}
static void T_1 F_40 ( void )
{
unsigned long V_88 = V_70 ;
unsigned long V_89 ;
if ( V_9 == V_10 || V_9 == V_30 )
V_88 |= V_90 ;
else if ( V_9 == V_22 ) {
if ( V_44 == V_50 ||
V_44 == V_91 ||
V_44 == V_92 ||
V_44 == V_93 ||
V_44 == V_94 ||
V_44 == V_95 ||
V_44 == V_45 ||
V_44 == V_46 ||
V_44 == V_47 ||
V_44 == V_96 )
V_88 |= V_97 ;
if ( V_44 == V_91 ||
V_44 == V_92 ||
V_44 == V_93 ||
V_44 == V_94 ||
V_44 == V_95 ||
V_44 == V_45 ||
V_44 == V_46 ||
V_44 == V_47 ||
V_44 == V_96 )
V_88 |= V_98 ;
}
V_88 |= ( V_99 | V_100 | V_101 ) ;
V_89 = F_35 () ;
if ( ! V_89 ) {
if ( V_9 == V_20 )
V_88 |= V_102 ;
if ( V_9 == V_10 || V_9 == V_30 )
V_88 |= V_102 | V_103 ;
if ( V_9 == V_30 ) {
unsigned long V_104 , V_18 ;
__asm__ __volatile__("rdpr %%ver, %0" : "=r" (ver));
V_104 = ( ( V_18 >> 32 ) & 0xffff ) ;
if ( V_104 == V_105 )
V_88 |= V_106 ;
}
if ( V_9 == V_22 ) {
if ( V_44 == V_50 )
V_88 |= V_107 ;
if ( V_44 == V_91 ||
V_44 == V_92 ||
V_44 == V_93 ||
V_44 == V_94 ||
V_44 == V_95 ||
V_44 == V_45 ||
V_44 == V_46 ||
V_44 == V_47 ||
V_44 == V_96 )
V_88 |= ( V_102 | V_103 |
V_107 |
V_106 ) ;
if ( V_44 == V_92 ||
V_44 == V_93 ||
V_44 == V_94 ||
V_44 == V_95 ||
V_44 == V_45 ||
V_44 == V_46 ||
V_44 == V_47 ||
V_44 == V_96 )
V_88 |= ( V_108 | V_109 |
V_110 ) ;
}
}
V_70 = V_88 | V_89 ;
F_34 ( V_70 ) ;
if ( V_70 & V_106 )
F_17 () ;
if ( V_70 & V_111 )
F_18 () ;
}
void T_1 F_41 ( void )
{
unsigned int V_59 , V_112 ;
F_42 (i) {
V_112 = F_43 ( V_59 ) ;
V_113 [ V_59 ] = F_44 ( F_45 ( V_112 ) ,
V_114 ,
V_114 , 0 ) ;
V_115 [ V_59 ] = F_44 ( F_45 ( V_112 ) ,
V_114 ,
V_114 , 0 ) ;
}
}
void T_1 F_46 ( char * * V_116 )
{
* V_116 = F_47 () ;
F_48 ( V_117 , * V_116 , V_118 ) ;
F_49 () ;
F_9 ( * V_116 ) ;
#ifdef F_50
if ( F_51 () )
#endif
F_52 ( & V_6 ) ;
if ( V_9 == V_22 )
F_6 ( L_15 ) ;
else
F_6 ( L_16 ) ;
#ifdef F_53
V_119 = & V_120 ;
#endif
F_54 () ;
if ( ! V_121 )
V_122 &= ~ V_123 ;
V_124 = F_55 ( V_125 ) ;
#ifdef F_56
V_126 = V_127 & V_128 ;
V_129 = ( ( V_127 & V_130 ) != 0 ) ;
V_131 = ( ( V_127 & V_132 ) != 0 ) ;
#endif
F_57 ( & V_133 ) -> V_134 = & V_135 ;
#ifdef F_58
if ( ! V_136 ) {
T_3 V_137 = F_59 ( L_17 ) ;
T_4 V_138 , V_139 , V_140 ;
V_138 = F_60 ( V_137 , L_18 , 0 ) ;
V_139 = F_60 ( V_137 , L_19 , 0 ) ;
V_140 = F_60 ( V_137 , L_20 , 0 ) ;
if ( V_138 && V_139 ) {
V_141 = V_138 ;
V_142 = V_139 ;
if ( V_140 )
V_143 = V_140 ;
#if F_61 ( V_144 ) || F_61 ( V_145 )
V_146 = 0 ;
#endif
}
}
#endif
F_62 ( F_23 () ) ;
F_63 () ;
F_40 () ;
F_64 () ;
F_41 () ;
}
void F_65 ( void )
{
if ( ! V_147 )
return;
F_4 ( L_21 ) ;
F_66 () ;
F_67 () ;
}
