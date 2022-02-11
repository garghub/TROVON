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
void T_1 F_13 ( void )
{
extern void V_33 ( void ) ;
struct V_34 * V_35 ;
struct V_36 * V_37 ;
if ( V_9 != V_21 )
return;
V_35 = & V_38 ;
while ( V_35 < & V_39 ) {
unsigned long V_26 = V_35 -> V_26 ;
* ( unsigned int * ) ( V_26 + 0 ) = V_35 -> V_40 ;
F_12 () ;
__asm__ __volatile__("flush %0" : : "r" (addr + 0));
V_35 ++ ;
}
V_37 = & V_41 ;
while ( V_37 < & V_42 ) {
unsigned long V_26 = V_37 -> V_26 ;
* ( unsigned int * ) ( V_26 + 0 ) = V_37 -> V_27 [ 0 ] ;
F_12 () ;
__asm__ __volatile__("flush %0" : : "r" (addr + 0));
* ( unsigned int * ) ( V_26 + 4 ) = V_37 -> V_27 [ 1 ] ;
F_12 () ;
__asm__ __volatile__("flush %0" : : "r" (addr + 4));
V_37 ++ ;
}
V_33 () ;
}
static void T_1 F_14 ( void )
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
void T_1 F_15 ( int V_52 )
{
F_4 ( L_6 ,
V_52 , V_53 ) ;
F_5 () ;
}
void F_16 ( struct V_54 * V_55 )
{
unsigned long V_56 = V_57 ;
int V_49 , V_58 = 0 ;
F_17 ( V_55 , L_7 ) ;
for ( V_49 = 0 ; V_49 < F_18 ( V_59 ) ; V_49 ++ ) {
unsigned long V_60 = 1UL << V_49 ;
if ( V_56 & V_60 ) {
F_19 ( V_55 , L_8 ,
V_58 ? L_9 : L_10 , V_59 [ V_49 ] ) ;
V_58 ++ ;
}
}
F_20 ( V_55 , '\n' ) ;
}
static void T_1 F_21 ( unsigned long V_56 )
{
int V_49 , V_58 = 0 ;
F_6 ( V_61 L_11 ) ;
for ( V_49 = 0 ; V_49 < F_18 ( V_59 ) ; V_49 ++ ) {
unsigned long V_60 = 1UL << V_49 ;
if ( V_56 & V_60 ) {
F_6 ( V_62 L_8 ,
V_58 ? L_9 : L_10 , V_59 [ V_49 ] ) ;
if ( ++ V_58 == 8 ) {
F_6 ( V_62 L_12 ) ;
F_6 ( V_61 L_11 ) ;
V_58 = 0 ;
}
}
}
F_6 ( V_62 L_12 ) ;
}
static unsigned long T_1 F_22 ( void )
{
struct V_63 * V_64 ;
unsigned long V_56 = 0 ;
const char * V_65 ;
int V_66 ;
T_2 V_67 ;
V_64 = F_23 () ;
if ( ! V_64 )
return 0 ;
V_67 = F_24 ( V_64 , V_68 , L_13 ) ;
if ( V_67 == V_68 )
goto V_69;
V_65 = F_25 ( V_64 , V_67 , L_14 , & V_66 ) ;
if ( ! V_65 )
goto V_69;
while ( V_66 ) {
int V_49 , V_70 ;
for ( V_49 = 0 ; V_49 < F_18 ( V_59 ) ; V_49 ++ ) {
unsigned long V_60 = 1UL << V_49 ;
if ( ! strcmp ( V_65 , V_59 [ V_49 ] ) ) {
V_56 |= V_60 ;
break;
}
}
V_70 = strlen ( V_65 ) + 1 ;
V_65 += V_70 ;
V_66 -= V_70 ;
}
V_69:
F_26 ( V_64 ) ;
return V_56 ;
}
static void T_1 F_27 ( void )
{
unsigned long V_71 = V_57 ;
unsigned long V_72 ;
if ( V_9 == V_10 || V_9 == V_29 )
V_71 |= V_73 ;
else if ( V_9 == V_21 ) {
if ( V_74 == V_75 ||
V_74 == V_76 ||
V_74 == V_77 ||
V_74 == V_78 ||
V_74 == V_79 )
V_71 |= V_80 ;
if ( V_74 == V_76 ||
V_74 == V_77 ||
V_74 == V_78 ||
V_74 == V_79 )
V_71 |= V_81 ;
}
V_71 |= ( V_82 | V_83 | V_84 ) ;
V_72 = F_22 () ;
if ( ! V_72 ) {
if ( V_9 == V_19 )
V_71 |= V_85 ;
if ( V_9 == V_10 || V_9 == V_29 )
V_71 |= V_85 | V_86 ;
if ( V_9 == V_29 ) {
unsigned long V_87 , V_17 ;
__asm__ __volatile__("rdpr %%ver, %0" : "=r" (ver));
V_87 = ( ( V_17 >> 32 ) & 0xffff ) ;
if ( V_87 == V_88 )
V_71 |= V_89 ;
}
if ( V_9 == V_21 ) {
if ( V_74 == V_75 )
V_71 |= V_90 ;
if ( V_74 == V_76 ||
V_74 == V_77 ||
V_74 == V_78 ||
V_74 == V_79 )
V_71 |= ( V_85 | V_86 |
V_90 |
V_89 ) ;
if ( V_74 == V_77 ||
V_74 == V_78 ||
V_74 == V_79 )
V_71 |= ( V_91 | V_92 |
V_93 ) ;
}
}
V_57 = V_71 | V_72 ;
F_21 ( V_57 ) ;
if ( V_57 & V_89 )
F_14 () ;
}
void T_1 F_28 ( char * * V_94 )
{
* V_94 = F_29 () ;
strcpy ( V_95 , * V_94 ) ;
F_30 () ;
F_9 ( * V_94 ) ;
#ifdef F_31
if ( F_32 () )
#endif
F_33 ( & V_6 ) ;
if ( V_9 == V_21 )
F_6 ( L_15 ) ;
else
F_6 ( L_16 ) ;
#ifdef F_34
V_96 = & V_97 ;
#endif
F_35 () ;
if ( ! V_98 )
V_99 &= ~ V_100 ;
V_101 = F_36 ( V_102 ) ;
#ifdef F_37
V_103 = V_104 & V_105 ;
V_106 = ( ( V_104 & V_107 ) != 0 ) ;
V_108 = ( ( V_104 & V_109 ) != 0 ) ;
#endif
F_38 ( & V_110 ) -> V_111 = & V_112 ;
#ifdef F_39
if ( ! V_113 ) {
T_3 V_114 = F_40 ( L_17 ) ;
T_4 V_115 , V_116 , V_117 ;
V_115 = F_41 ( V_114 , L_18 , 0 ) ;
V_116 = F_41 ( V_114 , L_19 , 0 ) ;
V_117 = F_41 ( V_114 , L_20 , 0 ) ;
if ( V_115 && V_116 ) {
V_118 = V_115 ;
V_119 = V_116 ;
if ( V_117 )
V_120 = V_117 ;
#if F_42 ( V_121 ) || F_42 ( V_122 )
V_123 = 0 ;
#endif
}
}
#endif
F_43 ( F_44 () ) ;
F_45 () ;
F_27 () ;
}
void F_46 ( void )
{
if ( ! V_124 )
return;
F_4 ( L_21 ) ;
F_47 () ;
F_48 () ;
}
