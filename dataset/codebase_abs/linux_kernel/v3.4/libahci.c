static void F_1 ( void T_1 * V_1 )
{
int V_2 ;
T_2 V_3 ;
V_3 = F_2 ( V_1 + V_4 ) ;
if ( V_3 & V_5 )
return;
for ( V_2 = 0 ; V_2 < 5 ; V_2 ++ ) {
V_3 |= V_5 ;
F_3 ( V_3 , V_1 + V_4 ) ;
V_3 = F_2 ( V_1 + V_4 ) ;
if ( V_3 & V_5 )
return;
F_4 ( 10 ) ;
}
F_5 ( 1 ) ;
}
static T_3 F_6 ( struct V_6 * V_7 ,
struct V_8 * V_9 , char * V_10 )
{
struct V_11 * V_12 = F_7 ( V_7 ) ;
struct V_13 * V_14 = F_8 ( V_12 ) ;
struct V_15 * V_16 = V_14 -> V_17 -> V_18 ;
return sprintf ( V_10 , L_1 , V_16 -> V_19 ) ;
}
static T_3 F_9 ( struct V_6 * V_7 ,
struct V_8 * V_9 , char * V_10 )
{
struct V_11 * V_12 = F_7 ( V_7 ) ;
struct V_13 * V_14 = F_8 ( V_12 ) ;
struct V_15 * V_16 = V_14 -> V_17 -> V_18 ;
return sprintf ( V_10 , L_1 , V_16 -> V_20 ) ;
}
static T_3 F_10 ( struct V_6 * V_7 ,
struct V_8 * V_9 , char * V_10 )
{
struct V_11 * V_12 = F_7 ( V_7 ) ;
struct V_13 * V_14 = F_8 ( V_12 ) ;
struct V_15 * V_16 = V_14 -> V_17 -> V_18 ;
void T_1 * V_1 = V_16 -> V_1 ;
return sprintf ( V_10 , L_1 , F_2 ( V_1 + V_21 ) ) ;
}
static T_3 F_11 ( struct V_6 * V_7 ,
struct V_8 * V_9 , char * V_10 )
{
struct V_11 * V_12 = F_7 ( V_7 ) ;
struct V_13 * V_14 = F_8 ( V_12 ) ;
void T_1 * V_22 = F_12 ( V_14 ) ;
return sprintf ( V_10 , L_1 , F_2 ( V_22 + V_23 ) ) ;
}
static T_3 F_13 ( struct V_6 * V_7 ,
struct V_8 * V_9 , char * V_10 )
{
struct V_11 * V_12 = F_7 ( V_7 ) ;
struct V_13 * V_14 = F_8 ( V_12 ) ;
struct V_15 * V_16 = V_14 -> V_17 -> V_18 ;
void T_1 * V_1 = V_16 -> V_1 ;
void T_1 * V_24 = V_1 + V_16 -> V_25 ;
T_2 V_26 , V_27 ;
unsigned long V_28 ;
T_4 V_29 ;
int V_2 ;
F_14 ( V_14 -> V_30 , V_28 ) ;
V_26 = F_2 ( V_1 + V_31 ) ;
if ( ! ( V_14 -> V_28 & V_32 ) || V_26 & V_33 ||
! ( V_16 -> V_34 & V_35 ) ) {
F_15 ( V_14 -> V_30 , V_28 ) ;
return - V_36 ;
}
if ( ! ( V_26 & V_37 ) ) {
F_15 ( V_14 -> V_30 , V_28 ) ;
return - V_38 ;
}
if ( ! ( V_26 & V_39 ) )
V_24 += V_16 -> V_40 ;
V_29 = V_16 -> V_40 ;
if ( V_29 > V_41 ) {
if ( F_16 () )
F_17 ( V_14 ,
L_2
L_3 ,
V_16 -> V_40 , V_41 ) ;
V_29 = V_41 ;
}
for ( V_2 = 0 ; V_2 < V_29 ; V_2 += 4 ) {
V_27 = F_2 ( V_24 + V_2 ) ;
V_10 [ V_2 ] = V_27 & 0xff ;
V_10 [ V_2 + 1 ] = ( V_27 >> 8 ) & 0xff ;
V_10 [ V_2 + 2 ] = ( V_27 >> 16 ) & 0xff ;
V_10 [ V_2 + 3 ] = ( V_27 >> 24 ) & 0xff ;
}
F_15 ( V_14 -> V_30 , V_28 ) ;
return V_2 ;
}
static T_3 F_18 ( struct V_6 * V_7 ,
struct V_8 * V_9 ,
const char * V_10 , T_4 V_42 )
{
struct V_11 * V_12 = F_7 ( V_7 ) ;
struct V_13 * V_14 = F_8 ( V_12 ) ;
struct V_15 * V_16 = V_14 -> V_17 -> V_18 ;
void T_1 * V_1 = V_16 -> V_1 ;
void T_1 * V_24 = V_1 + V_16 -> V_25 ;
const unsigned char * V_43 = V_10 ;
T_2 V_26 , V_27 ;
unsigned long V_28 ;
int V_2 ;
if ( ! ( V_14 -> V_28 & V_32 ) ||
! ( V_16 -> V_34 & V_35 ) ||
V_42 % 4 || V_42 > V_16 -> V_40 )
return - V_36 ;
F_14 ( V_14 -> V_30 , V_28 ) ;
V_26 = F_2 ( V_1 + V_31 ) ;
if ( V_26 & V_44 ) {
F_15 ( V_14 -> V_30 , V_28 ) ;
return - V_45 ;
}
for ( V_2 = 0 ; V_2 < V_42 ; V_2 += 4 ) {
V_27 = V_43 [ V_2 ] | V_43 [ V_2 + 1 ] << 8 |
V_43 [ V_2 + 2 ] << 16 | V_43 [ V_2 + 3 ] << 24 ;
F_3 ( V_27 , V_24 + V_2 ) ;
}
F_3 ( V_26 | V_44 , V_1 + V_31 ) ;
F_15 ( V_14 -> V_30 , V_28 ) ;
return V_42 ;
}
static T_3 F_19 ( struct V_6 * V_7 ,
struct V_8 * V_9 , char * V_10 )
{
struct V_11 * V_12 = F_7 ( V_7 ) ;
struct V_13 * V_14 = F_8 ( V_12 ) ;
struct V_15 * V_16 = V_14 -> V_17 -> V_18 ;
void T_1 * V_1 = V_16 -> V_1 ;
T_2 V_26 ;
V_26 = F_2 ( V_1 + V_31 ) ;
return sprintf ( V_10 , L_4 ,
V_26 & V_46 ? L_5 : L_6 ,
V_26 & V_47 ? L_7 : L_6 ,
V_26 & V_48 ? L_8 : L_6 ,
V_26 & V_49 ? L_9 : L_6 ) ;
}
void F_20 ( struct V_6 * V_7 ,
struct V_15 * V_16 ,
unsigned int V_50 ,
unsigned int V_51 )
{
void T_1 * V_1 = V_16 -> V_1 ;
T_2 V_19 , V_20 , V_52 , V_53 ;
int V_2 ;
F_1 ( V_1 ) ;
V_16 -> V_54 = V_19 = F_2 ( V_1 + V_55 ) ;
V_16 -> V_56 = V_53 = F_2 ( V_1 + V_57 ) ;
V_52 = F_2 ( V_1 + V_21 ) ;
if ( ( V_52 >> 16 ) > 1 ||
( ( V_52 >> 16 ) == 1 && ( V_52 & 0xFFFF ) >= 0x200 ) )
V_16 -> V_58 = V_20 = F_2 ( V_1 + V_59 ) ;
else
V_16 -> V_58 = V_20 = 0 ;
if ( ( V_19 & V_60 ) && ( V_16 -> V_28 & V_61 ) ) {
F_21 ( V_7 , L_10 ) ;
V_19 &= ~ V_60 ;
}
if ( ( V_19 & V_62 ) && ( V_16 -> V_28 & V_63 ) ) {
F_21 ( V_7 , L_11 ) ;
V_19 &= ~ V_62 ;
}
if ( ! ( V_19 & V_62 ) && ( V_16 -> V_28 & V_64 ) ) {
F_21 ( V_7 , L_12 ) ;
V_19 |= V_62 ;
}
if ( ( V_19 & V_65 ) && ( V_16 -> V_28 & V_66 ) ) {
F_21 ( V_7 , L_13 ) ;
V_19 &= ~ V_65 ;
}
if ( ( V_19 & V_67 ) && ( V_16 -> V_28 & V_68 ) ) {
F_21 ( V_7 ,
L_14 ) ;
V_19 &= ~ V_67 ;
}
if ( ! ( V_19 & V_69 ) && ( V_16 -> V_28 & V_70 ) ) {
F_21 ( V_7 , L_15 ) ;
V_19 |= V_69 ;
}
if ( V_50 && V_53 != V_50 ) {
F_21 ( V_7 , L_16 ,
V_53 , V_50 ) ;
V_53 = V_50 ;
}
if ( V_51 ) {
F_22 ( V_7 , L_17 ,
V_53 ,
V_53 & V_51 ) ;
V_53 &= V_51 ;
}
if ( V_53 ) {
int V_71 = 0 ;
for ( V_2 = 0 ; V_2 < V_72 ; V_2 ++ )
if ( V_53 & ( 1 << V_2 ) )
V_71 ++ ;
if ( V_71 > F_23 ( V_19 ) ) {
F_22 ( V_7 ,
L_18 ,
V_53 , F_23 ( V_19 ) ) ;
V_53 = 0 ;
}
}
if ( ! V_53 ) {
V_53 = ( 1 << F_23 ( V_19 ) ) - 1 ;
F_22 ( V_7 , L_19 , V_53 ) ;
V_16 -> V_56 = V_53 ;
}
V_16 -> V_19 = V_19 ;
V_16 -> V_20 = V_20 ;
V_16 -> V_53 = V_53 ;
}
static void F_24 ( struct V_73 * V_17 )
{
struct V_15 * V_16 = V_17 -> V_18 ;
void T_1 * V_1 = V_16 -> V_1 ;
F_3 ( V_16 -> V_54 , V_1 + V_55 ) ;
if ( V_16 -> V_58 )
F_3 ( V_16 -> V_58 , V_1 + V_59 ) ;
F_3 ( V_16 -> V_56 , V_1 + V_57 ) ;
( void ) F_2 ( V_1 + V_57 ) ;
}
static unsigned F_25 ( struct V_13 * V_14 , unsigned int V_74 )
{
static const int V_75 [] = {
[ V_76 ] = V_77 ,
[ V_78 ] = V_79 ,
[ V_80 ] = V_81 ,
[ V_82 ] = V_83 ,
[ V_84 ] = V_85 ,
} ;
struct V_15 * V_16 = V_14 -> V_17 -> V_18 ;
if ( V_74 < F_26 ( V_75 ) &&
( V_74 != V_84 || ( V_16 -> V_19 & V_67 ) ) )
return V_75 [ V_74 ] ;
return 0 ;
}
static int F_27 ( struct V_86 * V_87 , unsigned int V_74 , T_2 * V_88 )
{
void T_1 * V_22 = F_12 ( V_87 -> V_14 ) ;
int V_75 = F_25 ( V_87 -> V_14 , V_74 ) ;
if ( V_75 ) {
* V_88 = F_2 ( V_22 + V_75 ) ;
return 0 ;
}
return - V_36 ;
}
static int F_28 ( struct V_86 * V_87 , unsigned int V_74 , T_2 V_88 )
{
void T_1 * V_22 = F_12 ( V_87 -> V_14 ) ;
int V_75 = F_25 ( V_87 -> V_14 , V_74 ) ;
if ( V_75 ) {
F_3 ( V_88 , V_22 + V_75 ) ;
return 0 ;
}
return - V_36 ;
}
void F_29 ( struct V_13 * V_14 )
{
void T_1 * V_22 = F_12 ( V_14 ) ;
T_2 V_3 ;
V_3 = F_2 ( V_22 + V_23 ) ;
V_3 |= V_89 ;
F_3 ( V_3 , V_22 + V_23 ) ;
F_2 ( V_22 + V_23 ) ;
}
int F_30 ( struct V_13 * V_14 )
{
void T_1 * V_22 = F_12 ( V_14 ) ;
T_2 V_3 ;
V_3 = F_2 ( V_22 + V_23 ) ;
if ( ( V_3 & ( V_89 | V_90 ) ) == 0 )
return 0 ;
V_3 &= ~ V_89 ;
F_3 ( V_3 , V_22 + V_23 ) ;
V_3 = F_31 ( V_14 , V_22 + V_23 ,
V_90 , V_90 , 1 , 500 ) ;
if ( V_3 & V_90 )
return - V_91 ;
return 0 ;
}
static void F_32 ( struct V_13 * V_14 )
{
void T_1 * V_22 = F_12 ( V_14 ) ;
struct V_15 * V_16 = V_14 -> V_17 -> V_18 ;
struct V_92 * V_93 = V_14 -> V_18 ;
T_2 V_3 ;
if ( V_16 -> V_19 & V_60 )
F_3 ( ( V_93 -> V_94 >> 16 ) >> 16 ,
V_22 + V_95 ) ;
F_3 ( V_93 -> V_94 & 0xffffffff , V_22 + V_96 ) ;
if ( V_16 -> V_19 & V_60 )
F_3 ( ( V_93 -> V_97 >> 16 ) >> 16 ,
V_22 + V_98 ) ;
F_3 ( V_93 -> V_97 & 0xffffffff , V_22 + V_99 ) ;
V_3 = F_2 ( V_22 + V_23 ) ;
V_3 |= V_100 ;
F_3 ( V_3 , V_22 + V_23 ) ;
F_2 ( V_22 + V_23 ) ;
}
static int F_33 ( struct V_13 * V_14 )
{
void T_1 * V_22 = F_12 ( V_14 ) ;
T_2 V_3 ;
V_3 = F_2 ( V_22 + V_23 ) ;
V_3 &= ~ V_100 ;
F_3 ( V_3 , V_22 + V_23 ) ;
V_3 = F_31 ( V_14 , V_22 + V_23 , V_101 ,
V_101 , 10 , 1000 ) ;
if ( V_3 & V_101 )
return - V_45 ;
return 0 ;
}
static void F_34 ( struct V_13 * V_14 )
{
struct V_15 * V_16 = V_14 -> V_17 -> V_18 ;
void T_1 * V_22 = F_12 ( V_14 ) ;
T_2 V_102 ;
V_102 = F_2 ( V_22 + V_23 ) & ~ V_103 ;
if ( V_16 -> V_19 & V_104 ) {
V_102 |= V_105 ;
F_3 ( V_102 , V_22 + V_23 ) ;
}
F_3 ( V_102 | V_106 , V_22 + V_23 ) ;
}
static int F_35 ( struct V_86 * V_87 , enum V_107 V_108 ,
unsigned int V_109 )
{
struct V_13 * V_14 = V_87 -> V_14 ;
struct V_15 * V_16 = V_14 -> V_17 -> V_18 ;
struct V_92 * V_93 = V_14 -> V_18 ;
void T_1 * V_22 = F_12 ( V_14 ) ;
if ( V_108 != V_110 ) {
V_93 -> V_111 &= ~ V_112 ;
F_3 ( V_93 -> V_111 , V_22 + V_113 ) ;
F_36 ( V_87 , V_108 , false ) ;
}
if ( V_16 -> V_19 & V_114 ) {
T_2 V_102 = F_2 ( V_22 + V_23 ) ;
if ( V_108 == V_110 || ! ( V_109 & V_115 ) ) {
V_102 &= ~ ( V_116 | V_117 ) ;
V_102 |= V_106 ;
F_3 ( V_102 , V_22 + V_23 ) ;
F_2 ( V_22 + V_23 ) ;
F_37 ( V_14 , 10 ) ;
} else {
V_102 |= V_117 ;
if ( V_108 == V_118 )
V_102 |= V_116 ;
F_3 ( V_102 , V_22 + V_23 ) ;
}
}
if ( V_108 == V_110 ) {
F_36 ( V_87 , V_108 , false ) ;
V_93 -> V_111 |= V_112 ;
F_3 ( V_93 -> V_111 , V_22 + V_113 ) ;
}
return 0 ;
}
static void F_38 ( struct V_13 * V_14 )
{
struct V_15 * V_16 = V_14 -> V_17 -> V_18 ;
void T_1 * V_22 = F_12 ( V_14 ) ;
T_2 V_102 , V_119 ;
if ( ! ( V_16 -> V_19 & V_104 ) )
return;
V_119 = F_2 ( V_22 + V_79 ) ;
V_119 &= ~ 0xf ;
F_3 ( V_119 , V_22 + V_79 ) ;
V_102 = F_2 ( V_22 + V_23 ) & ~ V_103 ;
V_102 &= ~ V_105 ;
F_3 ( V_102 , V_22 + V_23 ) ;
}
static void F_39 ( struct V_13 * V_14 )
{
struct V_15 * V_16 = V_14 -> V_17 -> V_18 ;
struct V_92 * V_93 = V_14 -> V_18 ;
struct V_86 * V_87 ;
struct V_120 * V_121 ;
T_3 V_122 ;
int V_2 ;
F_32 ( V_14 ) ;
if ( ! ( V_16 -> V_28 & V_123 ) )
F_29 ( V_14 ) ;
if ( V_14 -> V_28 & V_32 ) {
F_40 (link, ap, EDGE) {
V_121 = & V_93 -> V_124 [ V_87 -> V_125 ] ;
for ( V_2 = 0 ; V_2 < V_126 ; V_2 ++ ) {
V_122 = F_41 ( V_14 ,
V_121 -> V_127 ,
4 ) ;
if ( V_122 == - V_45 )
F_37 ( V_14 , 1 ) ;
else
break;
}
}
}
if ( V_14 -> V_28 & V_128 )
F_40 (link, ap, EDGE)
F_42 ( V_87 ) ;
}
static int F_43 ( struct V_13 * V_14 , const char * * V_129 )
{
int V_122 ;
V_122 = F_30 ( V_14 ) ;
if ( V_122 ) {
* V_129 = L_20 ;
return V_122 ;
}
V_122 = F_33 ( V_14 ) ;
if ( V_122 ) {
* V_129 = L_21 ;
return V_122 ;
}
return 0 ;
}
int F_44 ( struct V_73 * V_17 )
{
struct V_15 * V_16 = V_17 -> V_18 ;
void T_1 * V_1 = V_16 -> V_1 ;
T_2 V_3 ;
F_1 ( V_1 ) ;
if ( ! V_130 ) {
V_3 = F_2 ( V_1 + V_4 ) ;
if ( ( V_3 & V_131 ) == 0 ) {
F_3 ( V_3 | V_131 , V_1 + V_4 ) ;
F_2 ( V_1 + V_4 ) ;
}
V_3 = F_31 ( NULL , V_1 + V_4 , V_131 ,
V_131 , 10 , 1000 ) ;
if ( V_3 & V_131 ) {
F_45 ( V_17 -> V_7 , L_22 ,
V_3 ) ;
return - V_91 ;
}
F_1 ( V_1 ) ;
F_24 ( V_17 ) ;
} else
F_21 ( V_17 -> V_7 , L_23 ) ;
return 0 ;
}
static void F_46 ( struct V_86 * V_87 )
{
struct V_13 * V_14 = V_87 -> V_14 ;
struct V_92 * V_93 = V_14 -> V_18 ;
struct V_120 * V_121 = & V_93 -> V_124 [ V_87 -> V_125 ] ;
if ( ! ( V_87 -> V_28 & V_132 ) )
return;
V_121 -> V_133 ++ ;
if ( ! F_47 ( & V_121 -> V_134 ) )
F_48 ( & V_121 -> V_134 , V_135 + F_49 ( 10 ) ) ;
}
static void F_50 ( unsigned long V_136 )
{
struct V_86 * V_87 = (struct V_86 * ) V_136 ;
struct V_13 * V_14 = V_87 -> V_14 ;
struct V_92 * V_93 = V_14 -> V_18 ;
struct V_120 * V_121 = & V_93 -> V_124 [ V_87 -> V_125 ] ;
unsigned long V_137 = V_121 -> V_127 ;
T_2 V_138 ;
unsigned long V_28 ;
V_137 &= V_139 ;
V_137 |= V_14 -> V_140 | ( V_87 -> V_125 << 8 ) ;
F_14 ( V_14 -> V_30 , V_28 ) ;
if ( V_121 -> V_141 != V_121 -> V_133 ) {
V_121 -> V_141 = V_121 -> V_133 ;
V_138 = V_137 & V_142 ;
if ( V_138 )
V_138 = 0 ;
else
V_138 = 1 ;
V_137 &= ~ V_143 ;
V_137 |= ( V_138 << 16 ) ;
F_48 ( & V_121 -> V_134 , V_135 + F_49 ( 100 ) ) ;
} else {
V_137 &= ~ V_143 ;
if ( V_121 -> V_144 == V_145 )
V_137 |= ( 1 << 16 ) ;
}
F_15 ( V_14 -> V_30 , V_28 ) ;
F_41 ( V_14 , V_137 , 4 ) ;
}
static void F_42 ( struct V_86 * V_87 )
{
struct V_13 * V_14 = V_87 -> V_14 ;
struct V_92 * V_93 = V_14 -> V_18 ;
struct V_120 * V_121 = & V_93 -> V_124 [ V_87 -> V_125 ] ;
V_121 -> V_141 = V_121 -> V_133 = 0 ;
F_51 ( & V_121 -> V_134 , F_50 , ( unsigned long ) V_87 ) ;
if ( V_121 -> V_144 )
V_87 -> V_28 |= V_132 ;
}
int F_52 ( struct V_73 * V_17 )
{
struct V_15 * V_16 = V_17 -> V_18 ;
void T_1 * V_1 = V_16 -> V_1 ;
T_2 V_26 ;
V_26 = F_2 ( V_1 + V_31 ) ;
if ( ( V_26 & V_44 ) || ( V_26 & V_146 ) )
return - V_36 ;
F_3 ( V_26 | V_146 , V_1 + V_31 ) ;
return 0 ;
}
static T_3 F_41 ( struct V_13 * V_14 , T_2 V_147 ,
T_3 V_42 )
{
struct V_15 * V_16 = V_14 -> V_17 -> V_18 ;
struct V_92 * V_93 = V_14 -> V_18 ;
void T_1 * V_1 = V_16 -> V_1 ;
T_2 V_26 ;
T_2 V_148 [] = { 0 , 0 } ;
unsigned long V_28 ;
int V_125 ;
struct V_120 * V_121 ;
V_125 = ( V_147 & V_149 ) >> 8 ;
if ( V_125 < V_150 )
V_121 = & V_93 -> V_124 [ V_125 ] ;
else
return - V_36 ;
F_14 ( V_14 -> V_30 , V_28 ) ;
V_26 = F_2 ( V_1 + V_31 ) ;
if ( V_26 & V_44 ) {
F_15 ( V_14 -> V_30 , V_28 ) ;
return - V_45 ;
}
if ( V_16 -> V_34 & V_151 ) {
V_148 [ 0 ] |= ( 4 << 8 ) ;
V_148 [ 1 ] = ( ( V_147 & ~ V_152 ) | V_14 -> V_140 ) ;
F_3 ( V_148 [ 0 ] , V_1 + V_16 -> V_25 ) ;
F_3 ( V_148 [ 1 ] , V_1 + V_16 -> V_25 + 4 ) ;
F_3 ( V_26 | V_44 , V_1 + V_31 ) ;
}
V_121 -> V_127 = V_147 ;
F_15 ( V_14 -> V_30 , V_28 ) ;
return V_42 ;
}
static T_3 F_53 ( struct V_13 * V_14 , char * V_10 )
{
struct V_92 * V_93 = V_14 -> V_18 ;
struct V_86 * V_87 ;
struct V_120 * V_121 ;
int V_122 = 0 ;
F_40 (link, ap, EDGE) {
V_121 = & V_93 -> V_124 [ V_87 -> V_125 ] ;
V_122 += sprintf ( V_10 , L_24 , V_121 -> V_127 ) ;
}
return V_122 ;
}
static T_3 F_54 ( struct V_13 * V_14 , const char * V_10 ,
T_4 V_42 )
{
int V_147 ;
int V_125 ;
struct V_92 * V_93 = V_14 -> V_18 ;
struct V_120 * V_121 ;
V_147 = F_55 ( V_10 , NULL , 0 ) ;
V_125 = ( V_147 & V_149 ) >> 8 ;
if ( V_125 < V_150 )
V_121 = & V_93 -> V_124 [ V_125 ] ;
else
return - V_36 ;
if ( V_121 -> V_144 )
V_147 &= ~ V_143 ;
return F_41 ( V_14 , V_147 , V_42 ) ;
}
static T_3 F_56 ( struct V_153 * V_7 , enum V_154 V_88 )
{
struct V_86 * V_87 = V_7 -> V_87 ;
struct V_13 * V_14 = V_87 -> V_14 ;
struct V_92 * V_93 = V_14 -> V_18 ;
struct V_120 * V_121 = & V_93 -> V_124 [ V_87 -> V_125 ] ;
T_2 V_155 = V_121 -> V_127 ;
if ( V_88 == V_156 ) {
V_87 -> V_28 &= ~ ( V_132 ) ;
V_155 &= V_157 ;
V_155 |= ( V_14 -> V_140 | ( V_87 -> V_125 << 8 ) ) ;
F_41 ( V_14 , V_155 , 4 ) ;
} else {
V_87 -> V_28 |= V_132 ;
if ( V_88 == V_145 ) {
V_155 &= V_157 ;
V_155 |= ( V_14 -> V_140 | ( V_87 -> V_125 << 8 ) ) ;
V_155 |= V_142 ;
F_41 ( V_14 , V_155 , 4 ) ;
}
}
V_121 -> V_144 = V_88 ;
return 0 ;
}
static T_3 F_57 ( struct V_153 * V_7 , char * V_10 )
{
struct V_86 * V_87 = V_7 -> V_87 ;
struct V_13 * V_14 = V_87 -> V_14 ;
struct V_92 * V_93 = V_14 -> V_18 ;
struct V_120 * V_121 = & V_93 -> V_124 [ V_87 -> V_125 ] ;
return sprintf ( V_10 , L_25 , V_121 -> V_144 ) ;
}
static void F_58 ( struct V_6 * V_7 , struct V_13 * V_14 ,
int V_140 , void T_1 * V_1 ,
void T_1 * V_22 )
{
const char * V_129 = NULL ;
int V_122 ;
T_2 V_3 ;
V_122 = F_43 ( V_14 , & V_129 ) ;
if ( V_122 )
F_22 ( V_7 , L_26 , V_129 , V_122 ) ;
V_3 = F_2 ( V_22 + V_81 ) ;
F_59 ( L_27 , V_3 ) ;
F_3 ( V_3 , V_22 + V_81 ) ;
V_3 = F_2 ( V_22 + V_158 ) ;
F_59 ( L_28 , V_3 ) ;
if ( V_3 )
F_3 ( V_3 , V_22 + V_158 ) ;
F_3 ( 1 << V_140 , V_1 + V_159 ) ;
}
void F_60 ( struct V_73 * V_17 )
{
struct V_15 * V_16 = V_17 -> V_18 ;
void T_1 * V_1 = V_16 -> V_1 ;
int V_2 ;
void T_1 * V_22 ;
T_2 V_3 ;
for ( V_2 = 0 ; V_2 < V_17 -> V_160 ; V_2 ++ ) {
struct V_13 * V_14 = V_17 -> V_161 [ V_2 ] ;
V_22 = F_12 ( V_14 ) ;
if ( F_61 ( V_14 ) )
continue;
F_58 ( V_17 -> V_7 , V_14 , V_2 , V_1 , V_22 ) ;
}
V_3 = F_2 ( V_1 + V_4 ) ;
F_59 ( L_29 , V_3 ) ;
F_3 ( V_3 | V_162 , V_1 + V_4 ) ;
V_3 = F_2 ( V_1 + V_4 ) ;
F_59 ( L_29 , V_3 ) ;
}
static void F_62 ( struct V_153 * V_7 )
{
struct V_15 * V_16 = V_7 -> V_87 -> V_14 -> V_17 -> V_18 ;
if ( V_16 -> V_28 & V_163 ) {
V_7 -> V_164 = 255 ;
F_63 ( V_7 ,
L_30 ) ;
}
}
static unsigned int F_64 ( struct V_13 * V_14 )
{
void T_1 * V_22 = F_12 ( V_14 ) ;
struct V_165 V_166 ;
T_2 V_3 ;
V_3 = F_2 ( V_22 + V_167 ) ;
V_166 . V_168 = ( V_3 >> 24 ) & 0xff ;
V_166 . V_169 = ( V_3 >> 16 ) & 0xff ;
V_166 . V_170 = ( V_3 >> 8 ) & 0xff ;
V_166 . V_171 = ( V_3 ) & 0xff ;
return F_65 ( & V_166 ) ;
}
void F_66 ( struct V_92 * V_93 , unsigned int V_172 ,
T_2 V_173 )
{
T_5 V_174 ;
V_174 = V_93 -> V_174 + V_172 * V_175 ;
V_93 -> V_176 [ V_172 ] . V_173 = F_67 ( V_173 ) ;
V_93 -> V_176 [ V_172 ] . V_177 = 0 ;
V_93 -> V_176 [ V_172 ] . V_178 = F_67 ( V_174 & 0xffffffff ) ;
V_93 -> V_176 [ V_172 ] . V_179 = F_67 ( ( V_174 >> 16 ) >> 16 ) ;
}
int F_68 ( struct V_13 * V_14 )
{
void T_1 * V_22 = F_12 ( V_14 ) ;
struct V_15 * V_16 = V_14 -> V_17 -> V_18 ;
T_6 V_177 = F_2 ( V_22 + V_180 ) & 0xFF ;
T_2 V_3 ;
int V_181 , V_122 ;
V_122 = F_30 ( V_14 ) ;
if ( V_122 )
goto V_182;
V_181 = V_177 & ( V_183 | V_184 ) ;
if ( ! V_181 && ! F_69 ( V_14 ) ) {
V_122 = 0 ;
goto V_182;
}
if ( ! ( V_16 -> V_19 & V_185 ) ) {
V_122 = - V_186 ;
goto V_182;
}
V_3 = F_2 ( V_22 + V_23 ) ;
V_3 |= V_187 ;
F_3 ( V_3 , V_22 + V_23 ) ;
V_122 = 0 ;
V_3 = F_31 ( V_14 , V_22 + V_23 ,
V_187 , V_187 , 1 , 500 ) ;
if ( V_3 & V_187 )
V_122 = - V_91 ;
V_182:
F_29 ( V_14 ) ;
return V_122 ;
}
static int F_70 ( struct V_13 * V_14 , int V_125 ,
struct V_165 * V_166 , int V_188 , T_7 V_28 ,
unsigned long V_189 )
{
const T_2 V_190 = 5 ;
struct V_92 * V_93 = V_14 -> V_18 ;
void T_1 * V_22 = F_12 ( V_14 ) ;
T_6 * V_191 = V_93 -> V_192 ;
T_2 V_3 ;
F_71 ( V_166 , V_125 , V_188 , V_191 ) ;
F_66 ( V_93 , 0 , V_190 | V_28 | ( V_125 << 12 ) ) ;
F_3 ( 1 , V_22 + V_193 ) ;
if ( V_189 ) {
V_3 = F_31 ( V_14 , V_22 + V_193 ,
0x1 , 0x1 , 1 , V_189 ) ;
if ( V_3 & 0x1 ) {
F_68 ( V_14 ) ;
return - V_45 ;
}
} else
F_2 ( V_22 + V_193 ) ;
return 0 ;
}
int F_72 ( struct V_86 * V_87 , unsigned int * V_194 ,
int V_125 , unsigned long V_195 ,
int (* F_73)( struct V_86 * V_87 ) )
{
struct V_13 * V_14 = V_87 -> V_14 ;
struct V_15 * V_16 = V_14 -> V_17 -> V_18 ;
const char * V_196 = NULL ;
unsigned long V_197 , V_198 ;
struct V_165 V_166 ;
int V_122 ;
F_74 ( L_31 ) ;
V_122 = F_68 ( V_14 ) ;
if ( V_122 && V_122 != - V_186 )
F_75 ( V_87 , L_32 , V_122 ) ;
F_76 ( V_87 -> V_6 , & V_166 ) ;
V_198 = 0 ;
V_197 = V_135 ;
if ( F_77 ( V_195 , V_197 ) )
V_198 = F_78 ( V_195 - V_197 ) ;
V_166 . V_199 |= V_200 ;
if ( F_70 ( V_14 , V_125 , & V_166 , 0 ,
V_201 | V_202 , V_198 ) ) {
V_122 = - V_91 ;
V_196 = L_33 ;
goto V_203;
}
F_37 ( V_14 , 1 ) ;
V_166 . V_199 &= ~ V_200 ;
F_70 ( V_14 , V_125 , & V_166 , 0 , 0 , 0 ) ;
V_122 = F_79 ( V_87 , V_195 , F_73 ) ;
if ( V_122 == - V_45 && V_16 -> V_28 & V_204 ) {
F_80 ( V_87 , L_34 ) ;
* V_194 = V_205 ;
} else if ( V_122 ) {
V_196 = L_35 ;
goto V_203;
} else
* V_194 = F_64 ( V_14 ) ;
F_74 ( L_36 , * V_194 ) ;
return 0 ;
V_203:
F_81 ( V_87 , L_37 , V_196 ) ;
return V_122 ;
}
int F_82 ( struct V_86 * V_87 )
{
void T_1 * V_22 = F_12 ( V_87 -> V_14 ) ;
T_6 V_177 = F_2 ( V_22 + V_180 ) & 0xFF ;
return F_83 ( V_177 ) ;
}
static int F_84 ( struct V_86 * V_87 , unsigned int * V_194 ,
unsigned long V_195 )
{
int V_125 = F_85 ( V_87 ) ;
F_74 ( L_31 ) ;
return F_72 ( V_87 , V_194 , V_125 , V_195 , F_82 ) ;
}
static int F_86 ( struct V_86 * V_87 )
{
void T_1 * V_22 = F_12 ( V_87 -> V_14 ) ;
T_6 V_177 = F_2 ( V_22 + V_180 ) & 0xFF ;
T_2 V_206 = F_2 ( V_22 + V_158 ) ;
if ( V_206 & V_207 )
return - V_91 ;
return F_83 ( V_177 ) ;
}
int F_87 ( struct V_86 * V_87 , unsigned int * V_194 ,
unsigned long V_195 )
{
struct V_13 * V_14 = V_87 -> V_14 ;
void T_1 * V_22 = F_12 ( V_14 ) ;
int V_125 = F_85 ( V_87 ) ;
int V_122 ;
T_2 V_208 ;
F_74 ( L_31 ) ;
V_122 = F_72 ( V_87 , V_194 , V_125 , V_195 ,
F_86 ) ;
if ( V_122 == - V_91 ) {
V_208 = F_2 ( V_22 + V_158 ) ;
if ( V_208 & V_207 ) {
F_88 ( V_87 , V_209 ,
L_38
L_39 ) ;
V_122 = F_72 ( V_87 , V_194 , 0 , V_195 ,
F_82 ) ;
}
}
return V_122 ;
}
static int F_89 ( struct V_86 * V_87 , unsigned int * V_194 ,
unsigned long V_195 )
{
const unsigned long * V_210 = F_90 ( & V_87 -> V_211 ) ;
struct V_13 * V_14 = V_87 -> V_14 ;
struct V_92 * V_93 = V_14 -> V_18 ;
T_6 * V_212 = V_93 -> V_213 + V_214 ;
struct V_165 V_166 ;
bool V_215 ;
int V_122 ;
F_74 ( L_31 ) ;
F_30 ( V_14 ) ;
F_76 ( V_87 -> V_6 , & V_166 ) ;
V_166 . V_216 = 0x80 ;
F_71 ( & V_166 , 0 , 0 , V_212 ) ;
V_122 = F_91 ( V_87 , V_210 , V_195 , & V_215 ,
F_82 ) ;
F_29 ( V_14 ) ;
if ( V_215 )
* V_194 = F_64 ( V_14 ) ;
F_74 ( L_40 , V_122 , * V_194 ) ;
return V_122 ;
}
static void F_92 ( struct V_86 * V_87 , unsigned int * V_194 )
{
struct V_13 * V_14 = V_87 -> V_14 ;
void T_1 * V_22 = F_12 ( V_14 ) ;
T_2 V_217 , V_3 ;
F_93 ( V_87 , V_194 ) ;
V_217 = V_3 = F_2 ( V_22 + V_23 ) ;
if ( * V_194 == V_218 )
V_217 |= V_219 ;
else
V_217 &= ~ V_219 ;
if ( V_217 != V_3 ) {
F_3 ( V_217 , V_22 + V_23 ) ;
F_2 ( V_22 + V_23 ) ;
}
}
static unsigned int F_94 ( struct V_220 * V_221 , void * V_192 )
{
struct V_222 * V_223 ;
struct V_224 * V_224 = V_192 + V_225 ;
unsigned int V_226 ;
F_59 ( L_31 ) ;
F_95 (qc->sg, sg, qc->n_elem, si) {
T_5 V_227 = F_96 ( V_223 ) ;
T_2 V_228 = F_97 ( V_223 ) ;
V_224 [ V_226 ] . V_227 = F_67 ( V_227 & 0xffffffff ) ;
V_224 [ V_226 ] . V_229 = F_67 ( ( V_227 >> 16 ) >> 16 ) ;
V_224 [ V_226 ] . V_230 = F_67 ( V_228 - 1 ) ;
}
return V_226 ;
}
static int F_98 ( struct V_220 * V_221 )
{
struct V_13 * V_14 = V_221 -> V_14 ;
struct V_92 * V_93 = V_14 -> V_18 ;
if ( ! F_69 ( V_14 ) || V_93 -> V_231 )
return F_99 ( V_221 ) ;
else
return F_100 ( V_221 ) ;
}
static void F_101 ( struct V_220 * V_221 )
{
struct V_13 * V_14 = V_221 -> V_14 ;
struct V_92 * V_93 = V_14 -> V_18 ;
int V_232 = F_102 ( V_221 -> V_166 . V_233 ) ;
void * V_192 ;
T_2 V_173 ;
const T_2 V_190 = 5 ;
unsigned int V_234 ;
V_192 = V_93 -> V_192 + V_221 -> V_172 * V_175 ;
F_71 ( & V_221 -> V_166 , V_221 -> V_7 -> V_87 -> V_125 , 1 , V_192 ) ;
if ( V_232 ) {
memset ( V_192 + V_235 , 0 , 32 ) ;
memcpy ( V_192 + V_235 , V_221 -> V_236 , V_221 -> V_7 -> V_237 ) ;
}
V_234 = 0 ;
if ( V_221 -> V_28 & V_238 )
V_234 = F_94 ( V_221 , V_192 ) ;
V_173 = V_190 | V_234 << 16 | ( V_221 -> V_7 -> V_87 -> V_125 << 12 ) ;
if ( V_221 -> V_166 . V_28 & V_239 )
V_173 |= V_240 ;
if ( V_232 )
V_173 |= V_241 | V_242 ;
F_66 ( V_93 , V_221 -> V_172 , V_173 ) ;
}
static void F_103 ( struct V_13 * V_14 )
{
struct V_92 * V_93 = V_14 -> V_18 ;
void T_1 * V_22 = F_12 ( V_14 ) ;
T_2 V_243 = F_2 ( V_22 + V_244 ) ;
int V_245 = 3 ;
F_74 ( L_31 ) ;
F_104 ( ! V_93 -> V_231 ) ;
F_3 ( V_243 | V_246 , V_22 + V_244 ) ;
V_243 = F_2 ( V_22 + V_244 ) ;
while ( ( V_243 & V_246 ) && V_245 -- ) {
F_105 ( 1 ) ;
V_243 = F_2 ( V_22 + V_244 ) ;
}
if ( V_243 & V_246 )
F_45 ( V_14 -> V_17 -> V_7 , L_41 ) ;
}
static void F_106 ( struct V_13 * V_14 , T_2 V_247 )
{
struct V_15 * V_16 = V_14 -> V_17 -> V_18 ;
struct V_92 * V_93 = V_14 -> V_18 ;
struct V_248 * V_249 = & V_14 -> V_87 . V_250 ;
struct V_86 * V_87 = NULL ;
struct V_220 * V_251 ;
struct V_248 * V_252 ;
bool V_253 = false ;
T_2 V_254 ;
if ( V_93 -> V_231 ) {
void T_1 * V_22 = F_12 ( V_14 ) ;
T_2 V_243 = F_2 ( V_22 + V_244 ) ;
int V_125 = V_243 >> V_255 ;
if ( ( V_243 & V_256 ) && ( V_125 < V_14 -> V_257 ) &&
F_107 ( & V_14 -> V_258 [ V_125 ] ) ) {
V_87 = & V_14 -> V_258 [ V_125 ] ;
V_253 = true ;
}
} else
F_40 (link, ap, EDGE)
if ( F_108 ( V_87 ) )
break;
if ( ! V_87 )
V_87 = & V_14 -> V_87 ;
V_251 = F_109 ( V_14 , V_87 -> V_259 ) ;
V_252 = & V_87 -> V_250 ;
F_110 ( V_249 ) ;
F_111 ( V_249 , L_42 , V_247 ) ;
F_27 ( & V_14 -> V_87 , V_80 , & V_254 ) ;
F_28 ( & V_14 -> V_87 , V_80 , V_254 ) ;
V_249 -> V_254 |= V_254 ;
if ( V_16 -> V_28 & V_260 )
V_247 &= ~ V_261 ;
if ( V_247 & V_262 ) {
if ( V_251 )
V_251 -> V_263 |= V_264 ;
else
V_252 -> V_263 |= V_264 ;
if ( V_16 -> V_28 & V_265 )
V_249 -> V_254 &= ~ V_266 ;
}
if ( V_247 & V_267 ) {
T_2 * V_268 = ( T_2 * ) ( V_93 -> V_213 + V_269 ) ;
V_252 -> V_263 |= V_270 ;
V_252 -> V_271 |= V_272 ;
F_111 ( V_252 ,
L_43 ,
V_268 [ 0 ] , V_268 [ 1 ] , V_268 [ 2 ] , V_268 [ 3 ] ) ;
}
if ( F_69 ( V_14 ) && ( V_247 & V_207 ) ) {
V_252 -> V_263 |= V_270 ;
V_252 -> V_271 |= V_272 ;
F_111 ( V_252 , L_44 ) ;
}
if ( V_247 & ( V_273 | V_274 ) ) {
V_249 -> V_263 |= V_275 ;
V_249 -> V_271 |= V_272 ;
F_111 ( V_249 , L_45 ) ;
}
if ( V_247 & V_261 ) {
if ( V_253 )
V_252 -> V_263 |= V_264 ;
else {
V_249 -> V_263 |= V_276 ;
V_249 -> V_271 |= V_272 ;
}
F_111 ( V_249 , L_46 ) ;
}
if ( V_247 & ( V_277 | V_112 ) ) {
F_112 ( V_249 ) ;
F_111 ( V_249 , L_47 ,
V_247 & V_277 ?
L_48 : L_49 ) ;
}
if ( V_247 & V_278 )
F_113 ( V_14 ) ;
else if ( V_253 ) {
F_114 ( V_87 ) ;
F_103 ( V_14 ) ;
} else
F_115 ( V_14 ) ;
}
static void F_116 ( struct V_13 * V_14 )
{
void T_1 * V_22 = F_12 ( V_14 ) ;
struct V_248 * V_279 = & V_14 -> V_87 . V_250 ;
struct V_92 * V_93 = V_14 -> V_18 ;
struct V_15 * V_16 = V_14 -> V_17 -> V_18 ;
int V_280 = ! ! ( V_14 -> V_281 & V_282 ) ;
T_2 V_177 , V_283 = 0 ;
int V_122 ;
V_177 = F_2 ( V_22 + V_158 ) ;
F_3 ( V_177 , V_22 + V_158 ) ;
if ( F_117 ( V_280 ) )
V_177 &= ~ V_207 ;
if ( V_14 -> V_87 . V_284 > V_110 ) {
V_177 &= ~ V_112 ;
F_28 ( & V_14 -> V_87 , V_80 , V_285 ) ;
}
if ( F_117 ( V_177 & V_286 ) ) {
F_106 ( V_14 , V_177 ) ;
return;
}
if ( V_177 & V_287 ) {
if ( V_16 -> V_19 & V_67 )
F_118 ( V_14 ) ;
else {
if ( V_93 -> V_231 )
F_119 ( 1 ) ;
else {
const T_8 * V_288 = V_93 -> V_213 + V_289 ;
T_2 V_290 = F_120 ( V_288 [ 0 ] ) ;
if ( V_290 & ( 1 << 15 ) )
F_118 ( V_14 ) ;
}
}
}
if ( V_93 -> V_231 ) {
if ( V_14 -> V_283 ) {
V_283 = F_2 ( V_22 + V_83 ) ;
V_283 |= F_2 ( V_22 + V_193 ) ;
}
} else {
if ( V_14 -> V_283 && V_93 -> V_291 -> V_292 )
V_283 = F_2 ( V_22 + V_83 ) ;
else
V_283 = F_2 ( V_22 + V_193 ) ;
}
V_122 = F_121 ( V_14 , V_283 ) ;
if ( F_117 ( V_122 < 0 && ! V_280 ) ) {
V_279 -> V_263 |= V_270 ;
V_279 -> V_271 |= V_272 ;
F_113 ( V_14 ) ;
}
}
T_9 F_122 ( int V_293 , void * V_294 )
{
struct V_73 * V_17 = V_294 ;
struct V_15 * V_16 ;
unsigned int V_2 , V_295 = 0 ;
void T_1 * V_1 ;
T_2 V_247 , V_296 ;
F_59 ( L_31 ) ;
V_16 = V_17 -> V_18 ;
V_1 = V_16 -> V_1 ;
V_247 = F_2 ( V_1 + V_159 ) ;
if ( ! V_247 )
return V_297 ;
V_296 = V_247 & V_16 -> V_53 ;
F_123 ( & V_17 -> V_30 ) ;
for ( V_2 = 0 ; V_2 < V_17 -> V_160 ; V_2 ++ ) {
struct V_13 * V_14 ;
if ( ! ( V_296 & ( 1 << V_2 ) ) )
continue;
V_14 = V_17 -> V_161 [ V_2 ] ;
if ( V_14 ) {
F_116 ( V_14 ) ;
F_59 ( L_50 , V_2 ) ;
} else {
F_59 ( L_51 , V_2 ) ;
if ( F_124 () )
F_22 ( V_17 -> V_7 ,
L_52 , V_2 ) ;
}
V_295 = 1 ;
}
F_3 ( V_247 , V_1 + V_159 ) ;
F_125 ( & V_17 -> V_30 ) ;
F_59 ( L_53 ) ;
return F_126 ( V_295 ) ;
}
static unsigned int F_127 ( struct V_220 * V_221 )
{
struct V_13 * V_14 = V_221 -> V_14 ;
void T_1 * V_22 = F_12 ( V_14 ) ;
struct V_92 * V_93 = V_14 -> V_18 ;
V_93 -> V_291 = V_221 -> V_7 -> V_87 ;
if ( V_221 -> V_166 . V_233 == V_298 )
F_3 ( 1 << V_221 -> V_172 , V_22 + V_83 ) ;
if ( V_93 -> V_231 && V_93 -> V_299 != V_221 -> V_7 -> V_87 -> V_125 ) {
T_2 V_243 = F_2 ( V_22 + V_244 ) ;
V_243 &= ~ ( V_300 | V_246 ) ;
V_243 |= V_221 -> V_7 -> V_87 -> V_125 << V_301 ;
F_3 ( V_243 , V_22 + V_244 ) ;
V_93 -> V_299 = V_221 -> V_7 -> V_87 -> V_125 ;
}
F_3 ( 1 << V_221 -> V_172 , V_22 + V_193 ) ;
F_46 ( V_221 -> V_7 -> V_87 ) ;
return 0 ;
}
static bool F_128 ( struct V_220 * V_221 )
{
struct V_92 * V_93 = V_221 -> V_14 -> V_18 ;
T_6 * V_213 = V_93 -> V_213 ;
if ( V_93 -> V_231 )
V_213 += V_221 -> V_7 -> V_87 -> V_125 * V_302 ;
if ( V_221 -> V_166 . V_233 == V_303 && V_221 -> V_304 == V_305 &&
! ( V_221 -> V_28 & V_306 ) ) {
F_129 ( V_213 + V_307 , & V_221 -> V_308 ) ;
V_221 -> V_308 . V_216 = ( V_213 + V_307 ) [ 15 ] ;
} else
F_129 ( V_213 + V_214 , & V_221 -> V_308 ) ;
return true ;
}
static void F_130 ( struct V_13 * V_14 )
{
void T_1 * V_22 = F_12 ( V_14 ) ;
F_3 ( 0 , V_22 + V_113 ) ;
}
static void F_131 ( struct V_13 * V_14 )
{
struct V_15 * V_16 = V_14 -> V_17 -> V_18 ;
void T_1 * V_1 = V_16 -> V_1 ;
void T_1 * V_22 = F_12 ( V_14 ) ;
T_2 V_3 ;
struct V_92 * V_93 = V_14 -> V_18 ;
V_3 = F_2 ( V_22 + V_158 ) ;
F_3 ( V_3 , V_22 + V_158 ) ;
F_3 ( 1 << V_14 -> V_140 , V_1 + V_159 ) ;
F_3 ( V_93 -> V_111 , V_22 + V_113 ) ;
}
static void F_132 ( struct V_13 * V_14 )
{
if ( ! ( V_14 -> V_281 & V_309 ) ) {
F_30 ( V_14 ) ;
F_29 ( V_14 ) ;
}
F_133 ( V_14 ) ;
if ( ! F_134 ( V_14 -> V_87 . V_6 ) )
F_30 ( V_14 ) ;
}
static void F_135 ( struct V_220 * V_221 )
{
struct V_13 * V_14 = V_221 -> V_14 ;
if ( V_221 -> V_28 & V_306 )
F_68 ( V_14 ) ;
}
static void F_136 ( struct V_13 * V_14 )
{
struct V_92 * V_93 = V_14 -> V_18 ;
void T_1 * V_22 = F_12 ( V_14 ) ;
T_2 V_243 ;
int V_122 ;
if ( ! V_93 -> V_310 )
return;
V_243 = F_2 ( V_22 + V_244 ) ;
if ( V_243 & V_311 ) {
V_93 -> V_231 = true ;
V_93 -> V_299 = - 1 ;
return;
}
V_122 = F_30 ( V_14 ) ;
if ( V_122 )
return;
F_3 ( V_243 | V_311 , V_22 + V_244 ) ;
V_243 = F_2 ( V_22 + V_244 ) ;
if ( V_243 & V_311 ) {
F_21 ( V_14 -> V_17 -> V_7 , L_54 ) ;
V_93 -> V_231 = true ;
V_93 -> V_299 = - 1 ;
} else
F_45 ( V_14 -> V_17 -> V_7 , L_55 ) ;
F_29 ( V_14 ) ;
}
static void F_137 ( struct V_13 * V_14 )
{
struct V_92 * V_93 = V_14 -> V_18 ;
void T_1 * V_22 = F_12 ( V_14 ) ;
T_2 V_243 ;
int V_122 ;
if ( ! V_93 -> V_310 )
return;
V_243 = F_2 ( V_22 + V_244 ) ;
if ( ( V_243 & V_311 ) == 0 ) {
V_93 -> V_231 = false ;
return;
}
V_122 = F_30 ( V_14 ) ;
if ( V_122 )
return;
F_3 ( V_243 & ~ V_311 , V_22 + V_244 ) ;
V_243 = F_2 ( V_22 + V_244 ) ;
if ( V_243 & V_311 )
F_45 ( V_14 -> V_17 -> V_7 , L_56 ) ;
else {
F_21 ( V_14 -> V_17 -> V_7 , L_57 ) ;
V_93 -> V_231 = false ;
}
F_29 ( V_14 ) ;
}
static void F_138 ( struct V_13 * V_14 )
{
void T_1 * V_22 = F_12 ( V_14 ) ;
struct V_92 * V_93 = V_14 -> V_18 ;
T_2 V_102 ;
V_102 = F_2 ( V_22 + V_23 ) ;
V_102 |= V_312 ;
F_3 ( V_102 , V_22 + V_23 ) ;
F_136 ( V_14 ) ;
V_93 -> V_111 |= V_207 ;
if ( ! ( V_14 -> V_281 & V_309 ) )
F_3 ( V_93 -> V_111 , V_22 + V_113 ) ;
}
static void F_139 ( struct V_13 * V_14 )
{
void T_1 * V_22 = F_12 ( V_14 ) ;
struct V_92 * V_93 = V_14 -> V_18 ;
T_2 V_102 ;
F_137 ( V_14 ) ;
V_102 = F_2 ( V_22 + V_23 ) ;
V_102 &= ~ V_312 ;
F_3 ( V_102 , V_22 + V_23 ) ;
V_93 -> V_111 &= ~ V_207 ;
if ( ! ( V_14 -> V_281 & V_309 ) )
F_3 ( V_93 -> V_111 , V_22 + V_113 ) ;
}
int F_140 ( struct V_13 * V_14 )
{
F_34 ( V_14 ) ;
F_39 ( V_14 ) ;
if ( F_69 ( V_14 ) )
F_138 ( V_14 ) ;
else
F_139 ( V_14 ) ;
return 0 ;
}
static int F_141 ( struct V_13 * V_14 , T_10 V_313 )
{
const char * V_129 = NULL ;
int V_122 ;
V_122 = F_43 ( V_14 , & V_129 ) ;
if ( V_122 == 0 )
F_38 ( V_14 ) ;
else {
F_142 ( V_14 , L_26 , V_129 , V_122 ) ;
F_113 ( V_14 ) ;
}
return V_122 ;
}
static int F_143 ( struct V_13 * V_14 )
{
struct V_15 * V_16 = V_14 -> V_17 -> V_18 ;
struct V_6 * V_7 = V_14 -> V_17 -> V_7 ;
struct V_92 * V_93 ;
void * V_314 ;
T_5 V_315 ;
T_4 V_316 , V_317 ;
V_93 = F_144 ( V_7 , sizeof( * V_93 ) , V_318 ) ;
if ( ! V_93 )
return - V_319 ;
if ( ( V_16 -> V_19 & V_69 ) && F_145 ( V_14 ) ) {
void T_1 * V_22 = F_12 ( V_14 ) ;
T_2 V_102 = F_2 ( V_22 + V_23 ) ;
if ( V_102 & V_320 )
V_93 -> V_310 = true ;
else if ( V_16 -> V_28 & V_70 ) {
F_21 ( V_7 , L_58 ,
V_14 -> V_140 ) ;
V_93 -> V_310 = true ;
} else
F_22 ( V_7 , L_59 ,
V_14 -> V_140 ) ;
}
if ( V_93 -> V_310 ) {
V_316 = V_321 ;
V_317 = V_302 * 16 ;
} else {
V_316 = V_322 ;
V_317 = V_302 ;
}
V_314 = F_146 ( V_7 , V_316 , & V_315 , V_318 ) ;
if ( ! V_314 )
return - V_319 ;
memset ( V_314 , 0 , V_316 ) ;
V_93 -> V_176 = V_314 ;
V_93 -> V_94 = V_315 ;
V_314 += V_323 ;
V_315 += V_323 ;
V_93 -> V_213 = V_314 ;
V_93 -> V_97 = V_315 ;
V_314 += V_317 ;
V_315 += V_317 ;
V_93 -> V_192 = V_314 ;
V_93 -> V_174 = V_315 ;
V_93 -> V_111 = V_324 ;
V_14 -> V_18 = V_93 ;
return F_140 ( V_14 ) ;
}
static void F_147 ( struct V_13 * V_14 )
{
const char * V_129 = NULL ;
int V_122 ;
V_122 = F_43 ( V_14 , & V_129 ) ;
if ( V_122 )
F_17 ( V_14 , L_26 , V_129 , V_122 ) ;
}
void F_148 ( struct V_73 * V_17 , const char * V_325 )
{
struct V_15 * V_16 = V_17 -> V_18 ;
void T_1 * V_1 = V_16 -> V_1 ;
T_2 V_52 , V_19 , V_20 , V_326 , V_327 ;
const char * V_328 ;
V_52 = F_2 ( V_1 + V_21 ) ;
V_19 = V_16 -> V_19 ;
V_20 = V_16 -> V_20 ;
V_326 = V_16 -> V_53 ;
V_327 = ( V_19 >> 20 ) & 0xf ;
if ( V_327 == 1 )
V_328 = L_60 ;
else if ( V_327 == 2 )
V_328 = L_61 ;
else if ( V_327 == 3 )
V_328 = L_62 ;
else
V_328 = L_63 ;
F_21 ( V_17 -> V_7 ,
L_64
L_65
,
( V_52 >> 24 ) & 0xff ,
( V_52 >> 16 ) & 0xff ,
( V_52 >> 8 ) & 0xff ,
V_52 & 0xff ,
( ( V_19 >> 8 ) & 0x1f ) + 1 ,
( V_19 & 0x1f ) + 1 ,
V_328 ,
V_326 ,
V_325 ) ;
F_21 ( V_17 -> V_7 ,
L_66
L_67
L_67
L_68
,
V_19 & V_60 ? L_69 : L_6 ,
V_19 & V_62 ? L_70 : L_6 ,
V_19 & V_67 ? L_71 : L_6 ,
V_19 & V_329 ? L_72 : L_6 ,
V_19 & V_104 ? L_73 : L_6 ,
V_19 & V_114 ? L_74 : L_6 ,
V_19 & V_330 ? L_5 : L_6 ,
V_19 & V_185 ? L_75 : L_6 ,
V_19 & V_331 ? L_76 : L_6 ,
V_19 & V_65 ? L_77 : L_6 ,
V_19 & V_69 ? L_78 : L_6 ,
V_19 & V_332 ? L_79 : L_6 ,
V_19 & V_333 ? L_80 : L_6 ,
V_19 & V_334 ? L_81 : L_6 ,
V_19 & V_335 ? L_82 : L_6 ,
V_19 & V_336 ? L_83 : L_6 ,
V_19 & V_337 ? L_84 : L_6 ,
V_20 & V_338 ? L_85 : L_6 ,
V_20 & V_339 ? L_86 : L_6 ,
V_20 & V_340 ? L_87 : L_6
) ;
}
void F_149 ( struct V_15 * V_16 ,
struct V_341 * V_342 )
{
T_6 V_343 ;
void T_1 * V_1 = V_16 -> V_1 ;
T_2 V_25 = F_2 ( V_1 + V_344 ) ;
T_2 V_26 = F_2 ( V_1 + V_31 ) ;
if ( ! V_345 || ! ( V_16 -> V_19 & V_336 ) )
return;
V_343 = ( V_26 & V_346 ) >> 16 ;
if ( V_343 ) {
V_16 -> V_25 = ( ( V_25 >> 16 ) * 4 ) ;
V_16 -> V_40 = ( ( V_25 & 0xff ) * 4 ) ;
V_16 -> V_34 = V_343 ;
V_342 -> V_28 |= V_32 ;
if ( ! ( V_26 & V_347 ) )
V_342 -> V_28 |= V_128 ;
}
}
