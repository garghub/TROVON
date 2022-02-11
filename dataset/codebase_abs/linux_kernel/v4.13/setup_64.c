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
V_39 () ;
}
static void T_1 F_17 ( void )
{
struct V_50 * V_51 ;
struct V_52 * V_53 ;
V_51 = & V_54 ;
while ( V_51 < & V_55 ) {
unsigned long V_56 , V_27 = V_51 -> V_27 ;
for ( V_56 = 0 ; V_56 < 3 ; V_56 ++ ) {
* ( unsigned int * ) ( V_27 + ( V_56 * 4 ) ) = V_51 -> V_28 [ V_56 ] ;
F_12 () ;
__asm__ __volatile__("flush %0"
: : "r" (addr + (i * 4)));
}
V_51 ++ ;
}
V_53 = & V_57 ;
while ( V_53 < & V_58 ) {
unsigned long V_56 , V_27 = V_53 -> V_27 ;
for ( V_56 = 0 ; V_56 < 6 ; V_56 ++ ) {
* ( unsigned int * ) ( V_27 + ( V_56 * 4 ) ) = V_53 -> V_28 [ V_56 ] ;
F_12 () ;
__asm__ __volatile__("flush %0"
: : "r" (addr + (i * 4)));
}
V_53 ++ ;
}
}
static void T_1 F_18 ( void )
{
struct V_59 * V_17 ;
V_17 = & V_60 ;
while ( V_17 < & V_61 ) {
unsigned long V_56 , V_27 = V_17 -> V_27 ;
for ( V_56 = 0 ; V_56 < 3 ; V_56 ++ ) {
* ( unsigned int * ) ( V_27 + ( V_56 * 4 ) ) = V_17 -> V_28 [ V_56 ] ;
F_12 () ;
__asm__ __volatile__("flush %0"
: : "r" (addr + (i * 4)));
}
V_17 ++ ;
}
}
void T_1 F_19 ( void )
{
int V_62 ;
F_20 () ;
F_11 () ;
F_16 () ;
V_62 = F_21 () ;
if ( V_62 >= V_63 ) {
F_4 ( L_6 ,
V_62 , V_63 ) ;
F_5 () ;
}
F_22 () -> V_62 = V_62 ;
F_23 () ;
F_24 () ;
F_25 () ;
}
void F_26 ( struct V_64 * V_65 )
{
unsigned long V_66 = V_67 ;
int V_56 , V_68 = 0 ;
F_27 ( V_65 , L_7 ) ;
for ( V_56 = 0 ; V_56 < F_28 ( V_69 ) ; V_56 ++ ) {
unsigned long V_70 = 1UL << V_56 ;
if ( V_69 [ V_56 ] && ( V_66 & V_70 ) ) {
F_29 ( V_65 , L_8 ,
V_68 ? L_9 : L_10 , V_69 [ V_56 ] ) ;
V_68 ++ ;
}
}
if ( V_66 & V_71 ) {
unsigned long V_72 ;
__asm__ __volatile__("rd %%asr26, %0" : "=r" (cfr));
for ( V_56 = 0 ; V_56 < F_28 ( V_73 ) ; V_56 ++ ) {
unsigned long V_70 = 1UL << V_56 ;
if ( V_72 & V_70 ) {
F_29 ( V_65 , L_8 ,
V_68 ? L_9 : L_10 , V_73 [ V_56 ] ) ;
V_68 ++ ;
}
}
}
F_30 ( V_65 , '\n' ) ;
}
static void T_1 F_31 ( int * V_68 , const char * V_74 )
{
if ( ( * V_68 ) == 0 )
F_6 ( V_75 L_11 ) ;
F_6 ( V_76 L_8 ,
( * V_68 ) ? L_9 : L_10 , V_74 ) ;
if ( ++ ( * V_68 ) == 8 ) {
F_6 ( V_76 L_12 ) ;
* V_68 = 0 ;
}
}
static void T_1 F_32 ( int * V_68 )
{
unsigned long V_72 ;
int V_56 ;
__asm__ __volatile__("rd %%asr26, %0" : "=r" (cfr));
for ( V_56 = 0 ; V_56 < F_28 ( V_73 ) ; V_56 ++ ) {
unsigned long V_70 = 1UL << V_56 ;
if ( V_72 & V_70 )
F_31 ( V_68 , V_73 [ V_56 ] ) ;
}
}
static void T_1 F_33 ( unsigned long V_66 )
{
int V_56 , V_68 = 0 ;
for ( V_56 = 0 ; V_56 < F_28 ( V_69 ) ; V_56 ++ ) {
unsigned long V_70 = 1UL << V_56 ;
if ( V_69 [ V_56 ] && ( V_66 & V_70 ) )
F_31 ( & V_68 , V_69 [ V_56 ] ) ;
}
if ( V_66 & V_71 )
F_32 ( & V_68 ) ;
if ( V_68 != 0 )
F_6 ( V_76 L_12 ) ;
}
static unsigned long T_1 F_34 ( void )
{
struct V_77 * V_78 ;
unsigned long V_66 = 0 ;
const char * V_79 ;
int V_80 ;
T_2 V_81 ;
V_78 = F_35 () ;
if ( ! V_78 )
return 0 ;
V_81 = F_36 ( V_78 , V_82 , L_13 ) ;
if ( V_81 == V_82 )
goto V_83;
V_79 = F_37 ( V_78 , V_81 , L_14 , & V_80 ) ;
if ( ! V_79 )
goto V_83;
while ( V_80 ) {
int V_56 , V_84 ;
for ( V_56 = 0 ; V_56 < F_28 ( V_69 ) ; V_56 ++ ) {
unsigned long V_70 = 1UL << V_56 ;
if ( V_69 [ V_56 ] && ! strcmp ( V_79 , V_69 [ V_56 ] ) ) {
V_66 |= V_70 ;
break;
}
}
for ( V_56 = 0 ; V_56 < F_28 ( V_73 ) ; V_56 ++ ) {
if ( ! strcmp ( V_79 , V_73 [ V_56 ] ) )
V_66 |= V_71 ;
}
V_84 = strlen ( V_79 ) + 1 ;
V_79 += V_84 ;
V_80 -= V_84 ;
}
V_83:
F_38 ( V_78 ) ;
return V_66 ;
}
static void T_1 F_39 ( void )
{
unsigned long V_85 = V_67 ;
unsigned long V_86 ;
if ( V_9 == V_10 || V_9 == V_30 )
V_85 |= V_87 ;
else if ( V_9 == V_22 ) {
if ( V_44 == V_88 ||
V_44 == V_89 ||
V_44 == V_90 ||
V_44 == V_91 ||
V_44 == V_92 ||
V_44 == V_93 ||
V_44 == V_45 ||
V_44 == V_46 ||
V_44 == V_47 ||
V_44 == V_94 )
V_85 |= V_95 ;
if ( V_44 == V_89 ||
V_44 == V_90 ||
V_44 == V_91 ||
V_44 == V_92 ||
V_44 == V_93 ||
V_44 == V_45 ||
V_44 == V_46 ||
V_44 == V_47 ||
V_44 == V_94 )
V_85 |= V_96 ;
}
V_85 |= ( V_97 | V_98 | V_99 ) ;
V_86 = F_34 () ;
if ( ! V_86 ) {
if ( V_9 == V_20 )
V_85 |= V_100 ;
if ( V_9 == V_10 || V_9 == V_30 )
V_85 |= V_100 | V_101 ;
if ( V_9 == V_30 ) {
unsigned long V_102 , V_18 ;
__asm__ __volatile__("rdpr %%ver, %0" : "=r" (ver));
V_102 = ( ( V_18 >> 32 ) & 0xffff ) ;
if ( V_102 == V_103 )
V_85 |= V_104 ;
}
if ( V_9 == V_22 ) {
if ( V_44 == V_88 )
V_85 |= V_105 ;
if ( V_44 == V_89 ||
V_44 == V_90 ||
V_44 == V_91 ||
V_44 == V_92 ||
V_44 == V_93 ||
V_44 == V_45 ||
V_44 == V_46 ||
V_44 == V_47 ||
V_44 == V_94 )
V_85 |= ( V_100 | V_101 |
V_105 |
V_104 ) ;
if ( V_44 == V_90 ||
V_44 == V_91 ||
V_44 == V_92 ||
V_44 == V_93 ||
V_44 == V_45 ||
V_44 == V_46 ||
V_44 == V_47 ||
V_44 == V_94 )
V_85 |= ( V_106 | V_107 |
V_108 ) ;
}
}
V_67 = V_85 | V_86 ;
F_33 ( V_67 ) ;
if ( V_67 & V_104 )
F_17 () ;
if ( V_67 & V_109 )
F_18 () ;
}
void T_1 F_40 ( void )
{
unsigned int V_56 , V_110 ;
F_41 (i) {
V_110 = F_42 ( V_56 ) ;
V_111 [ V_56 ] = F_43 ( F_44 ( V_110 ) ,
V_112 ,
V_112 , 0 ) ;
V_113 [ V_56 ] = F_43 ( F_44 ( V_110 ) ,
V_112 ,
V_112 , 0 ) ;
}
}
void T_1 F_45 ( char * * V_114 )
{
* V_114 = F_46 () ;
F_47 ( V_115 , * V_114 , V_116 ) ;
F_48 () ;
F_9 ( * V_114 ) ;
#ifdef F_49
if ( F_50 () )
#endif
F_51 ( & V_6 ) ;
if ( V_9 == V_22 )
F_6 ( L_15 ) ;
else
F_6 ( L_16 ) ;
#ifdef F_52
V_117 = & V_118 ;
#endif
F_53 () ;
if ( ! V_119 )
V_120 &= ~ V_121 ;
V_122 = F_54 ( V_123 ) ;
#ifdef F_55
V_124 = V_125 & V_126 ;
V_127 = ( ( V_125 & V_128 ) != 0 ) ;
V_129 = ( ( V_125 & V_130 ) != 0 ) ;
#endif
F_56 ( & V_131 ) -> V_132 = & V_133 ;
#ifdef F_57
if ( ! V_134 ) {
T_3 V_135 = F_58 ( L_17 ) ;
T_4 V_136 , V_137 , V_138 ;
V_136 = F_59 ( V_135 , L_18 , 0 ) ;
V_137 = F_59 ( V_135 , L_19 , 0 ) ;
V_138 = F_59 ( V_135 , L_20 , 0 ) ;
if ( V_136 && V_137 ) {
V_139 = V_136 ;
V_140 = V_137 ;
if ( V_138 )
V_141 = V_138 ;
#if F_60 ( V_142 ) || F_60 ( V_143 )
V_144 = 0 ;
#endif
}
}
#endif
F_61 ( F_22 () ) ;
F_62 () ;
F_39 () ;
F_63 () ;
F_40 () ;
}
void F_64 ( void )
{
if ( ! V_145 )
return;
F_4 ( L_21 ) ;
F_65 () ;
F_66 () ;
}
