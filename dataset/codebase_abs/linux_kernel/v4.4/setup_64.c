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
if ( V_44 == V_45 )
F_15 ( & V_46 ,
& V_47 ) ;
V_39 () ;
}
static void T_1 F_17 ( void )
{
struct V_48 * V_49 ;
struct V_50 * V_51 ;
V_49 = & V_52 ;
while ( V_49 < & V_53 ) {
unsigned long V_54 , V_27 = V_49 -> V_27 ;
for ( V_54 = 0 ; V_54 < 3 ; V_54 ++ ) {
* ( unsigned int * ) ( V_27 + ( V_54 * 4 ) ) = V_49 -> V_28 [ V_54 ] ;
F_12 () ;
__asm__ __volatile__("flush %0"
: : "r" (addr + (i * 4)));
}
V_49 ++ ;
}
V_51 = & V_55 ;
while ( V_51 < & V_56 ) {
unsigned long V_54 , V_27 = V_51 -> V_27 ;
for ( V_54 = 0 ; V_54 < 6 ; V_54 ++ ) {
* ( unsigned int * ) ( V_27 + ( V_54 * 4 ) ) = V_51 -> V_28 [ V_54 ] ;
F_12 () ;
__asm__ __volatile__("flush %0"
: : "r" (addr + (i * 4)));
}
V_51 ++ ;
}
}
static void T_1 F_18 ( void )
{
struct V_57 * V_17 ;
V_17 = & V_58 ;
while ( V_17 < & V_59 ) {
unsigned long V_54 , V_27 = V_17 -> V_27 ;
for ( V_54 = 0 ; V_54 < 3 ; V_54 ++ ) {
* ( unsigned int * ) ( V_27 + ( V_54 * 4 ) ) = V_17 -> V_28 [ V_54 ] ;
F_12 () ;
__asm__ __volatile__("flush %0"
: : "r" (addr + (i * 4)));
}
V_17 ++ ;
}
}
void T_1 F_19 ( void )
{
int V_60 ;
F_20 () ;
F_11 () ;
F_16 () ;
V_60 = F_21 () ;
if ( V_60 >= V_61 ) {
F_4 ( L_6 ,
V_60 , V_61 ) ;
F_5 () ;
}
F_22 () -> V_60 = V_60 ;
F_23 () ;
F_24 () ;
}
void F_25 ( struct V_62 * V_63 )
{
unsigned long V_64 = V_65 ;
int V_54 , V_66 = 0 ;
F_26 ( V_63 , L_7 ) ;
for ( V_54 = 0 ; V_54 < F_27 ( V_67 ) ; V_54 ++ ) {
unsigned long V_68 = 1UL << V_54 ;
if ( V_67 [ V_54 ] && ( V_64 & V_68 ) ) {
F_28 ( V_63 , L_8 ,
V_66 ? L_9 : L_10 , V_67 [ V_54 ] ) ;
V_66 ++ ;
}
}
if ( V_64 & V_69 ) {
unsigned long V_70 ;
__asm__ __volatile__("rd %%asr26, %0" : "=r" (cfr));
for ( V_54 = 0 ; V_54 < F_27 ( V_71 ) ; V_54 ++ ) {
unsigned long V_68 = 1UL << V_54 ;
if ( V_70 & V_68 ) {
F_28 ( V_63 , L_8 ,
V_66 ? L_9 : L_10 , V_71 [ V_54 ] ) ;
V_66 ++ ;
}
}
}
F_29 ( V_63 , '\n' ) ;
}
static void T_1 F_30 ( int * V_66 , const char * V_72 )
{
if ( ( * V_66 ) == 0 )
F_6 ( V_73 L_11 ) ;
F_6 ( V_74 L_8 ,
( * V_66 ) ? L_9 : L_10 , V_72 ) ;
if ( ++ ( * V_66 ) == 8 ) {
F_6 ( V_74 L_12 ) ;
* V_66 = 0 ;
}
}
static void T_1 F_31 ( int * V_66 )
{
unsigned long V_70 ;
int V_54 ;
__asm__ __volatile__("rd %%asr26, %0" : "=r" (cfr));
for ( V_54 = 0 ; V_54 < F_27 ( V_71 ) ; V_54 ++ ) {
unsigned long V_68 = 1UL << V_54 ;
if ( V_70 & V_68 )
F_30 ( V_66 , V_71 [ V_54 ] ) ;
}
}
static void T_1 F_32 ( unsigned long V_64 )
{
int V_54 , V_66 = 0 ;
for ( V_54 = 0 ; V_54 < F_27 ( V_67 ) ; V_54 ++ ) {
unsigned long V_68 = 1UL << V_54 ;
if ( V_67 [ V_54 ] && ( V_64 & V_68 ) )
F_30 ( & V_66 , V_67 [ V_54 ] ) ;
}
if ( V_64 & V_69 )
F_31 ( & V_66 ) ;
if ( V_66 != 0 )
F_6 ( V_74 L_12 ) ;
}
static unsigned long T_1 F_33 ( void )
{
struct V_75 * V_76 ;
unsigned long V_64 = 0 ;
const char * V_77 ;
int V_78 ;
T_2 V_79 ;
V_76 = F_34 () ;
if ( ! V_76 )
return 0 ;
V_79 = F_35 ( V_76 , V_80 , L_13 ) ;
if ( V_79 == V_80 )
goto V_81;
V_77 = F_36 ( V_76 , V_79 , L_14 , & V_78 ) ;
if ( ! V_77 )
goto V_81;
while ( V_78 ) {
int V_54 , V_82 ;
for ( V_54 = 0 ; V_54 < F_27 ( V_67 ) ; V_54 ++ ) {
unsigned long V_68 = 1UL << V_54 ;
if ( V_67 [ V_54 ] && ! strcmp ( V_77 , V_67 [ V_54 ] ) ) {
V_64 |= V_68 ;
break;
}
}
for ( V_54 = 0 ; V_54 < F_27 ( V_71 ) ; V_54 ++ ) {
if ( ! strcmp ( V_77 , V_71 [ V_54 ] ) )
V_64 |= V_69 ;
}
V_82 = strlen ( V_77 ) + 1 ;
V_77 += V_82 ;
V_78 -= V_82 ;
}
V_81:
F_37 ( V_76 ) ;
return V_64 ;
}
static void T_1 F_38 ( void )
{
unsigned long V_83 = V_65 ;
unsigned long V_84 ;
if ( V_9 == V_10 || V_9 == V_30 )
V_83 |= V_85 ;
else if ( V_9 == V_22 ) {
if ( V_44 == V_86 ||
V_44 == V_87 ||
V_44 == V_88 ||
V_44 == V_89 ||
V_44 == V_90 ||
V_44 == V_91 ||
V_44 == V_45 ||
V_44 == V_92 )
V_83 |= V_93 ;
if ( V_44 == V_87 ||
V_44 == V_88 ||
V_44 == V_89 ||
V_44 == V_90 ||
V_44 == V_91 ||
V_44 == V_45 ||
V_44 == V_92 )
V_83 |= V_94 ;
}
V_83 |= ( V_95 | V_96 | V_97 ) ;
V_84 = F_33 () ;
if ( ! V_84 ) {
if ( V_9 == V_20 )
V_83 |= V_98 ;
if ( V_9 == V_10 || V_9 == V_30 )
V_83 |= V_98 | V_99 ;
if ( V_9 == V_30 ) {
unsigned long V_100 , V_18 ;
__asm__ __volatile__("rdpr %%ver, %0" : "=r" (ver));
V_100 = ( ( V_18 >> 32 ) & 0xffff ) ;
if ( V_100 == V_101 )
V_83 |= V_102 ;
}
if ( V_9 == V_22 ) {
if ( V_44 == V_86 )
V_83 |= V_103 ;
if ( V_44 == V_87 ||
V_44 == V_88 ||
V_44 == V_89 ||
V_44 == V_90 ||
V_44 == V_91 ||
V_44 == V_45 ||
V_44 == V_92 )
V_83 |= ( V_98 | V_99 |
V_103 |
V_102 ) ;
if ( V_44 == V_88 ||
V_44 == V_89 ||
V_44 == V_90 ||
V_44 == V_91 ||
V_44 == V_45 ||
V_44 == V_92 )
V_83 |= ( V_104 | V_105 |
V_106 ) ;
}
}
V_65 = V_83 | V_84 ;
F_32 ( V_65 ) ;
if ( V_65 & V_102 )
F_17 () ;
if ( V_65 & V_107 )
F_18 () ;
}
void T_1 F_39 ( char * * V_108 )
{
* V_108 = F_40 () ;
F_41 ( V_109 , * V_108 , V_110 ) ;
F_42 () ;
F_9 ( * V_108 ) ;
#ifdef F_43
if ( F_44 () )
#endif
F_45 ( & V_6 ) ;
if ( V_9 == V_22 )
F_6 ( L_15 ) ;
else
F_6 ( L_16 ) ;
#ifdef F_46
V_111 = & V_112 ;
#endif
F_47 () ;
if ( ! V_113 )
V_114 &= ~ V_115 ;
V_116 = F_48 ( V_117 ) ;
#ifdef F_49
V_118 = V_119 & V_120 ;
V_121 = ( ( V_119 & V_122 ) != 0 ) ;
V_123 = ( ( V_119 & V_124 ) != 0 ) ;
#endif
F_50 ( & V_125 ) -> V_126 = & V_127 ;
#ifdef F_51
if ( ! V_128 ) {
T_3 V_129 = F_52 ( L_17 ) ;
T_4 V_130 , V_131 , V_132 ;
V_130 = F_53 ( V_129 , L_18 , 0 ) ;
V_131 = F_53 ( V_129 , L_19 , 0 ) ;
V_132 = F_53 ( V_129 , L_20 , 0 ) ;
if ( V_130 && V_131 ) {
V_133 = V_130 ;
V_134 = V_131 ;
if ( V_132 )
V_135 = V_132 ;
#if F_54 ( V_136 ) || F_54 ( V_137 )
V_138 = 0 ;
#endif
}
}
#endif
F_55 ( F_22 () ) ;
F_56 () ;
F_38 () ;
}
void F_57 ( void )
{
if ( ! V_139 )
return;
F_4 ( L_21 ) ;
F_58 () ;
F_59 () ;
}
