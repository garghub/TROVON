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
F_7 ( V_12 ) ;
F_8 () ;
break;
default:
F_6 ( L_3 , V_5 ) ;
break;
}
}
static void T_1 F_9 ( char * V_13 )
{
while ( * V_13 ) {
while ( * V_13 && * V_13 == ' ' )
V_13 ++ ;
if ( * V_13 == '\0' )
break;
if ( * V_13 == '-' ) {
V_13 ++ ;
while ( * V_13 && * V_13 != ' ' )
F_3 ( * V_13 ++ ) ;
continue;
}
if ( ! strncmp ( V_13 , L_4 , 4 ) ) {
V_14 = F_10 ( V_13 + 4 ,
& V_13 , 0 ) ;
if ( * V_13 == 'K' || * V_13 == 'k' ) {
V_14 <<= 10 ;
V_13 ++ ;
} else if ( * V_13 == 'M' || * V_13 == 'm' ) {
V_14 <<= 20 ;
V_13 ++ ;
}
}
while ( * V_13 && * V_13 != ' ' )
V_13 ++ ;
}
}
void T_1 F_11 ( void )
{
struct V_15 * V_16 ;
unsigned long V_17 ;
int V_18 ;
if ( V_9 == V_19 && ! V_20 )
return;
V_18 = 0 ;
if ( V_9 != V_21 ) {
__asm__ ("rdpr %%ver, %0" : "=r" (ver));
V_18 = ( ( V_17 >> 32UL ) == V_22 ||
( V_17 >> 32UL ) == V_23 ) ;
}
V_16 = & V_24 ;
while ( V_16 < & V_25 ) {
unsigned long V_26 = V_16 -> V_26 ;
unsigned int * V_27 ;
switch ( V_9 ) {
case V_19 :
V_27 = & V_16 -> V_28 [ 0 ] ;
break;
case V_10 :
case V_29 :
if ( V_18 )
V_27 = & V_16 -> V_30 [ 0 ] ;
else
V_27 = & V_16 -> V_31 [ 0 ] ;
break;
case V_21 :
V_27 = & V_16 -> V_32 [ 0 ] ;
break;
default:
F_4 ( L_5 ) ;
F_5 () ;
}
* ( unsigned int * ) ( V_26 + 0 ) = V_27 [ 0 ] ;
F_12 () ;
__asm__ __volatile__("flush %0" : : "r" (addr + 0));
* ( unsigned int * ) ( V_26 + 4 ) = V_27 [ 1 ] ;
F_12 () ;
__asm__ __volatile__("flush %0" : : "r" (addr + 4));
* ( unsigned int * ) ( V_26 + 8 ) = V_27 [ 2 ] ;
F_12 () ;
__asm__ __volatile__("flush %0" : : "r" (addr + 8));
* ( unsigned int * ) ( V_26 + 12 ) = V_27 [ 3 ] ;
F_12 () ;
__asm__ __volatile__("flush %0" : : "r" (addr + 12));
V_16 ++ ;
}
}
void F_13 ( struct V_33 * V_34 ,
struct V_33 * V_35 )
{
while ( V_34 < V_35 ) {
unsigned long V_26 = V_34 -> V_26 ;
* ( unsigned int * ) ( V_26 + 0 ) = V_34 -> V_36 ;
F_12 () ;
__asm__ __volatile__("flush %0" : : "r" (addr + 0));
V_34 ++ ;
}
}
void F_14 ( struct V_37 * V_34 ,
struct V_37 * V_35 )
{
while ( V_34 < V_35 ) {
unsigned long V_26 = V_34 -> V_26 ;
* ( unsigned int * ) ( V_26 + 0 ) = V_34 -> V_27 [ 0 ] ;
F_12 () ;
__asm__ __volatile__("flush %0" : : "r" (addr + 0));
* ( unsigned int * ) ( V_26 + 4 ) = V_34 -> V_27 [ 1 ] ;
F_12 () ;
__asm__ __volatile__("flush %0" : : "r" (addr + 4));
V_34 ++ ;
}
}
void T_1 F_15 ( void )
{
extern void V_38 ( void ) ;
if ( V_9 != V_21 )
return;
F_13 ( & V_39 ,
& V_40 ) ;
F_14 ( & V_41 ,
& V_42 ) ;
V_38 () ;
}
static void T_1 F_16 ( void )
{
struct V_43 * V_44 ;
struct V_45 * V_46 ;
V_44 = & V_47 ;
while ( V_44 < & V_48 ) {
unsigned long V_49 , V_26 = V_44 -> V_26 ;
for ( V_49 = 0 ; V_49 < 3 ; V_49 ++ ) {
* ( unsigned int * ) ( V_26 + ( V_49 * 4 ) ) = V_44 -> V_27 [ V_49 ] ;
F_12 () ;
__asm__ __volatile__("flush %0"
: : "r" (addr + (i * 4)));
}
V_44 ++ ;
}
V_46 = & V_50 ;
while ( V_46 < & V_51 ) {
unsigned long V_49 , V_26 = V_46 -> V_26 ;
for ( V_49 = 0 ; V_49 < 6 ; V_49 ++ ) {
* ( unsigned int * ) ( V_26 + ( V_49 * 4 ) ) = V_46 -> V_27 [ V_49 ] ;
F_12 () ;
__asm__ __volatile__("flush %0"
: : "r" (addr + (i * 4)));
}
V_46 ++ ;
}
}
static void T_1 F_17 ( void )
{
struct V_52 * V_16 ;
V_16 = & V_53 ;
while ( V_16 < & V_54 ) {
unsigned long V_49 , V_26 = V_16 -> V_26 ;
for ( V_49 = 0 ; V_49 < 3 ; V_49 ++ ) {
* ( unsigned int * ) ( V_26 + ( V_49 * 4 ) ) = V_16 -> V_27 [ V_49 ] ;
F_12 () ;
__asm__ __volatile__("flush %0"
: : "r" (addr + (i * 4)));
}
V_16 ++ ;
}
}
void T_1 F_18 ( int V_55 )
{
F_4 ( L_6 ,
V_55 , V_56 ) ;
F_5 () ;
}
void F_19 ( struct V_57 * V_58 )
{
unsigned long V_59 = V_60 ;
int V_49 , V_61 = 0 ;
F_20 ( V_58 , L_7 ) ;
for ( V_49 = 0 ; V_49 < F_21 ( V_62 ) ; V_49 ++ ) {
unsigned long V_63 = 1UL << V_49 ;
if ( V_59 & V_63 ) {
F_22 ( V_58 , L_8 ,
V_61 ? L_9 : L_10 , V_62 [ V_49 ] ) ;
V_61 ++ ;
}
}
if ( V_59 & V_64 ) {
unsigned long V_65 ;
__asm__ __volatile__("rd %%asr26, %0" : "=r" (cfr));
for ( V_49 = 0 ; V_49 < F_21 ( V_66 ) ; V_49 ++ ) {
unsigned long V_63 = 1UL << V_49 ;
if ( V_65 & V_63 ) {
F_22 ( V_58 , L_8 ,
V_61 ? L_9 : L_10 , V_66 [ V_49 ] ) ;
V_61 ++ ;
}
}
}
F_23 ( V_58 , '\n' ) ;
}
static void T_1 F_24 ( int * V_61 , const char * V_67 )
{
if ( ( * V_61 ) == 0 )
F_6 ( V_68 L_11 ) ;
F_6 ( V_69 L_8 ,
( * V_61 ) ? L_9 : L_10 , V_67 ) ;
if ( ++ ( * V_61 ) == 8 ) {
F_6 ( V_69 L_12 ) ;
* V_61 = 0 ;
}
}
static void T_1 F_25 ( int * V_61 )
{
unsigned long V_65 ;
int V_49 ;
__asm__ __volatile__("rd %%asr26, %0" : "=r" (cfr));
for ( V_49 = 0 ; V_49 < F_21 ( V_66 ) ; V_49 ++ ) {
unsigned long V_63 = 1UL << V_49 ;
if ( V_65 & V_63 )
F_24 ( V_61 , V_66 [ V_49 ] ) ;
}
}
static void T_1 F_26 ( unsigned long V_59 )
{
int V_49 , V_61 = 0 ;
for ( V_49 = 0 ; V_49 < F_21 ( V_62 ) ; V_49 ++ ) {
unsigned long V_63 = 1UL << V_49 ;
if ( V_59 & V_63 )
F_24 ( & V_61 , V_62 [ V_49 ] ) ;
}
if ( V_59 & V_64 )
F_25 ( & V_61 ) ;
if ( V_61 != 0 )
F_6 ( V_69 L_12 ) ;
}
static unsigned long T_1 F_27 ( void )
{
struct V_70 * V_71 ;
unsigned long V_59 = 0 ;
const char * V_72 ;
int V_73 ;
T_2 V_74 ;
V_71 = F_28 () ;
if ( ! V_71 )
return 0 ;
V_74 = F_29 ( V_71 , V_75 , L_13 ) ;
if ( V_74 == V_75 )
goto V_76;
V_72 = F_30 ( V_71 , V_74 , L_14 , & V_73 ) ;
if ( ! V_72 )
goto V_76;
while ( V_73 ) {
int V_49 , V_77 ;
for ( V_49 = 0 ; V_49 < F_21 ( V_62 ) ; V_49 ++ ) {
unsigned long V_63 = 1UL << V_49 ;
if ( ! strcmp ( V_72 , V_62 [ V_49 ] ) ) {
V_59 |= V_63 ;
break;
}
}
for ( V_49 = 0 ; V_49 < F_21 ( V_66 ) ; V_49 ++ ) {
if ( ! strcmp ( V_72 , V_66 [ V_49 ] ) )
V_59 |= V_64 ;
}
V_77 = strlen ( V_72 ) + 1 ;
V_72 += V_77 ;
V_73 -= V_77 ;
}
V_76:
F_31 ( V_71 ) ;
return V_59 ;
}
static void T_1 F_32 ( void )
{
unsigned long V_78 = V_60 ;
unsigned long V_79 ;
if ( V_9 == V_10 || V_9 == V_29 )
V_78 |= V_80 ;
else if ( V_9 == V_21 ) {
if ( V_81 == V_82 ||
V_81 == V_83 ||
V_81 == V_84 ||
V_81 == V_85 ||
V_81 == V_86 )
V_78 |= V_87 ;
if ( V_81 == V_83 ||
V_81 == V_84 ||
V_81 == V_85 ||
V_81 == V_86 )
V_78 |= V_88 ;
}
V_78 |= ( V_89 | V_90 | V_91 ) ;
V_79 = F_27 () ;
if ( ! V_79 ) {
if ( V_9 == V_19 )
V_78 |= V_92 ;
if ( V_9 == V_10 || V_9 == V_29 )
V_78 |= V_92 | V_93 ;
if ( V_9 == V_29 ) {
unsigned long V_94 , V_17 ;
__asm__ __volatile__("rdpr %%ver, %0" : "=r" (ver));
V_94 = ( ( V_17 >> 32 ) & 0xffff ) ;
if ( V_94 == V_95 )
V_78 |= V_96 ;
}
if ( V_9 == V_21 ) {
if ( V_81 == V_82 )
V_78 |= V_97 ;
if ( V_81 == V_83 ||
V_81 == V_84 ||
V_81 == V_85 ||
V_81 == V_86 )
V_78 |= ( V_92 | V_93 |
V_97 |
V_96 ) ;
if ( V_81 == V_84 ||
V_81 == V_85 ||
V_81 == V_86 )
V_78 |= ( V_98 | V_99 |
V_100 ) ;
}
}
V_60 = V_78 | V_79 ;
F_26 ( V_60 ) ;
if ( V_60 & V_96 )
F_16 () ;
if ( V_60 & V_101 )
F_17 () ;
}
void T_1 F_33 ( char * * V_102 )
{
* V_102 = F_34 () ;
strcpy ( V_103 , * V_102 ) ;
F_35 () ;
F_9 ( * V_102 ) ;
#ifdef F_36
if ( F_37 () )
#endif
F_38 ( & V_6 ) ;
if ( V_9 == V_21 )
F_6 ( L_15 ) ;
else
F_6 ( L_16 ) ;
#ifdef F_39
V_104 = & V_105 ;
#endif
F_40 () ;
if ( ! V_106 )
V_107 &= ~ V_108 ;
V_109 = F_41 ( V_110 ) ;
#ifdef F_42
V_111 = V_112 & V_113 ;
V_114 = ( ( V_112 & V_115 ) != 0 ) ;
V_116 = ( ( V_112 & V_117 ) != 0 ) ;
#endif
F_43 ( & V_118 ) -> V_119 = & V_120 ;
#ifdef F_44
if ( ! V_121 ) {
T_3 V_122 = F_45 ( L_17 ) ;
T_4 V_123 , V_124 , V_125 ;
V_123 = F_46 ( V_122 , L_18 , 0 ) ;
V_124 = F_46 ( V_122 , L_19 , 0 ) ;
V_125 = F_46 ( V_122 , L_20 , 0 ) ;
if ( V_123 && V_124 ) {
V_126 = V_123 ;
V_127 = V_124 ;
if ( V_125 )
V_128 = V_125 ;
#if F_47 ( V_129 ) || F_47 ( V_130 )
V_131 = 0 ;
#endif
}
}
#endif
F_48 ( F_49 () ) ;
F_50 () ;
F_32 () ;
}
void F_51 ( void )
{
if ( ! V_132 )
return;
F_4 ( L_21 ) ;
F_52 () ;
F_53 () ;
}
