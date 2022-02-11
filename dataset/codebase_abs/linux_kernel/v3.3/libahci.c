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
struct V_92 * V_93 = V_14 -> V_18 ;
struct V_86 * V_87 ;
struct V_120 * V_121 ;
T_3 V_122 ;
int V_2 ;
F_32 ( V_14 ) ;
if ( V_14 -> V_28 & V_32 ) {
F_40 (link, ap, EDGE) {
V_121 = & V_93 -> V_123 [ V_87 -> V_124 ] ;
for ( V_2 = 0 ; V_2 < V_125 ; V_2 ++ ) {
V_122 = F_41 ( V_14 ,
V_121 -> V_126 ,
4 ) ;
if ( V_122 == - V_45 )
F_37 ( V_14 , 1 ) ;
else
break;
}
}
}
if ( V_14 -> V_28 & V_127 )
F_40 (link, ap, EDGE)
F_42 ( V_87 ) ;
}
static int F_43 ( struct V_13 * V_14 , const char * * V_128 )
{
int V_122 ;
V_122 = F_30 ( V_14 ) ;
if ( V_122 ) {
* V_128 = L_20 ;
return V_122 ;
}
V_122 = F_33 ( V_14 ) ;
if ( V_122 ) {
* V_128 = L_21 ;
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
if ( ! V_129 ) {
V_3 = F_2 ( V_1 + V_4 ) ;
if ( ( V_3 & V_130 ) == 0 ) {
F_3 ( V_3 | V_130 , V_1 + V_4 ) ;
F_2 ( V_1 + V_4 ) ;
}
V_3 = F_31 ( NULL , V_1 + V_4 , V_130 ,
V_130 , 10 , 1000 ) ;
if ( V_3 & V_130 ) {
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
struct V_120 * V_121 = & V_93 -> V_123 [ V_87 -> V_124 ] ;
if ( ! ( V_87 -> V_28 & V_131 ) )
return;
V_121 -> V_132 ++ ;
if ( ! F_47 ( & V_121 -> V_133 ) )
F_48 ( & V_121 -> V_133 , V_134 + F_49 ( 10 ) ) ;
}
static void F_50 ( unsigned long V_135 )
{
struct V_86 * V_87 = (struct V_86 * ) V_135 ;
struct V_13 * V_14 = V_87 -> V_14 ;
struct V_92 * V_93 = V_14 -> V_18 ;
struct V_120 * V_121 = & V_93 -> V_123 [ V_87 -> V_124 ] ;
unsigned long V_136 = V_121 -> V_126 ;
T_2 V_137 ;
unsigned long V_28 ;
V_136 &= V_138 ;
V_136 |= V_14 -> V_139 | ( V_87 -> V_124 << 8 ) ;
F_14 ( V_14 -> V_30 , V_28 ) ;
if ( V_121 -> V_140 != V_121 -> V_132 ) {
V_121 -> V_140 = V_121 -> V_132 ;
V_137 = V_136 & V_141 ;
if ( V_137 )
V_137 = 0 ;
else
V_137 = 1 ;
V_136 &= ~ V_142 ;
V_136 |= ( V_137 << 16 ) ;
F_48 ( & V_121 -> V_133 , V_134 + F_49 ( 100 ) ) ;
} else {
V_136 &= ~ V_142 ;
if ( V_121 -> V_143 == V_144 )
V_136 |= ( 1 << 16 ) ;
}
F_15 ( V_14 -> V_30 , V_28 ) ;
F_41 ( V_14 , V_136 , 4 ) ;
}
static void F_42 ( struct V_86 * V_87 )
{
struct V_13 * V_14 = V_87 -> V_14 ;
struct V_92 * V_93 = V_14 -> V_18 ;
struct V_120 * V_121 = & V_93 -> V_123 [ V_87 -> V_124 ] ;
V_121 -> V_140 = V_121 -> V_132 = 0 ;
F_51 ( & V_121 -> V_133 , F_50 , ( unsigned long ) V_87 ) ;
if ( V_121 -> V_143 )
V_87 -> V_28 |= V_131 ;
}
int F_52 ( struct V_73 * V_17 )
{
struct V_15 * V_16 = V_17 -> V_18 ;
void T_1 * V_1 = V_16 -> V_1 ;
T_2 V_26 ;
V_26 = F_2 ( V_1 + V_31 ) ;
if ( ( V_26 & V_44 ) || ( V_26 & V_145 ) )
return - V_36 ;
F_3 ( V_26 | V_145 , V_1 + V_31 ) ;
return 0 ;
}
static T_3 F_41 ( struct V_13 * V_14 , T_2 V_146 ,
T_3 V_42 )
{
struct V_15 * V_16 = V_14 -> V_17 -> V_18 ;
struct V_92 * V_93 = V_14 -> V_18 ;
void T_1 * V_1 = V_16 -> V_1 ;
T_2 V_26 ;
T_2 V_147 [] = { 0 , 0 } ;
unsigned long V_28 ;
int V_124 ;
struct V_120 * V_121 ;
V_124 = ( V_146 & V_148 ) >> 8 ;
if ( V_124 < V_149 )
V_121 = & V_93 -> V_123 [ V_124 ] ;
else
return - V_36 ;
F_14 ( V_14 -> V_30 , V_28 ) ;
V_26 = F_2 ( V_1 + V_31 ) ;
if ( V_26 & V_44 ) {
F_15 ( V_14 -> V_30 , V_28 ) ;
return - V_45 ;
}
if ( V_16 -> V_34 & V_150 ) {
V_147 [ 0 ] |= ( 4 << 8 ) ;
V_147 [ 1 ] = ( ( V_146 & ~ V_151 ) | V_14 -> V_139 ) ;
F_3 ( V_147 [ 0 ] , V_1 + V_16 -> V_25 ) ;
F_3 ( V_147 [ 1 ] , V_1 + V_16 -> V_25 + 4 ) ;
F_3 ( V_26 | V_44 , V_1 + V_31 ) ;
}
V_121 -> V_126 = V_146 ;
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
V_121 = & V_93 -> V_123 [ V_87 -> V_124 ] ;
V_122 += sprintf ( V_10 , L_24 , V_121 -> V_126 ) ;
}
return V_122 ;
}
static T_3 F_54 ( struct V_13 * V_14 , const char * V_10 ,
T_4 V_42 )
{
int V_146 ;
int V_124 ;
struct V_92 * V_93 = V_14 -> V_18 ;
struct V_120 * V_121 ;
V_146 = F_55 ( V_10 , NULL , 0 ) ;
V_124 = ( V_146 & V_148 ) >> 8 ;
if ( V_124 < V_149 )
V_121 = & V_93 -> V_123 [ V_124 ] ;
else
return - V_36 ;
if ( V_121 -> V_143 )
V_146 &= ~ V_142 ;
return F_41 ( V_14 , V_146 , V_42 ) ;
}
static T_3 F_56 ( struct V_152 * V_7 , enum V_153 V_88 )
{
struct V_86 * V_87 = V_7 -> V_87 ;
struct V_13 * V_14 = V_87 -> V_14 ;
struct V_92 * V_93 = V_14 -> V_18 ;
struct V_120 * V_121 = & V_93 -> V_123 [ V_87 -> V_124 ] ;
T_2 V_154 = V_121 -> V_126 ;
if ( V_88 == V_155 ) {
V_87 -> V_28 &= ~ ( V_131 ) ;
V_154 &= V_156 ;
V_154 |= ( V_14 -> V_139 | ( V_87 -> V_124 << 8 ) ) ;
F_41 ( V_14 , V_154 , 4 ) ;
} else {
V_87 -> V_28 |= V_131 ;
if ( V_88 == V_144 ) {
V_154 &= V_156 ;
V_154 |= ( V_14 -> V_139 | ( V_87 -> V_124 << 8 ) ) ;
V_154 |= V_141 ;
F_41 ( V_14 , V_154 , 4 ) ;
}
}
V_121 -> V_143 = V_88 ;
return 0 ;
}
static T_3 F_57 ( struct V_152 * V_7 , char * V_10 )
{
struct V_86 * V_87 = V_7 -> V_87 ;
struct V_13 * V_14 = V_87 -> V_14 ;
struct V_92 * V_93 = V_14 -> V_18 ;
struct V_120 * V_121 = & V_93 -> V_123 [ V_87 -> V_124 ] ;
return sprintf ( V_10 , L_25 , V_121 -> V_143 ) ;
}
static void F_58 ( struct V_6 * V_7 , struct V_13 * V_14 ,
int V_139 , void T_1 * V_1 ,
void T_1 * V_22 )
{
const char * V_128 = NULL ;
int V_122 ;
T_2 V_3 ;
V_122 = F_43 ( V_14 , & V_128 ) ;
if ( V_122 )
F_22 ( V_7 , L_26 , V_128 , V_122 ) ;
V_3 = F_2 ( V_22 + V_81 ) ;
F_59 ( L_27 , V_3 ) ;
F_3 ( V_3 , V_22 + V_81 ) ;
V_3 = F_2 ( V_22 + V_157 ) ;
F_59 ( L_28 , V_3 ) ;
if ( V_3 )
F_3 ( V_3 , V_22 + V_157 ) ;
F_3 ( 1 << V_139 , V_1 + V_158 ) ;
}
void F_60 ( struct V_73 * V_17 )
{
struct V_15 * V_16 = V_17 -> V_18 ;
void T_1 * V_1 = V_16 -> V_1 ;
int V_2 ;
void T_1 * V_22 ;
T_2 V_3 ;
for ( V_2 = 0 ; V_2 < V_17 -> V_159 ; V_2 ++ ) {
struct V_13 * V_14 = V_17 -> V_160 [ V_2 ] ;
V_22 = F_12 ( V_14 ) ;
if ( F_61 ( V_14 ) )
continue;
F_58 ( V_17 -> V_7 , V_14 , V_2 , V_1 , V_22 ) ;
}
V_3 = F_2 ( V_1 + V_4 ) ;
F_59 ( L_29 , V_3 ) ;
F_3 ( V_3 | V_161 , V_1 + V_4 ) ;
V_3 = F_2 ( V_1 + V_4 ) ;
F_59 ( L_29 , V_3 ) ;
}
static void F_62 ( struct V_152 * V_7 )
{
struct V_15 * V_16 = V_7 -> V_87 -> V_14 -> V_17 -> V_18 ;
if ( V_16 -> V_28 & V_162 ) {
V_7 -> V_163 = 255 ;
F_63 ( V_7 ,
L_30 ) ;
}
}
static unsigned int F_64 ( struct V_13 * V_14 )
{
void T_1 * V_22 = F_12 ( V_14 ) ;
struct V_164 V_165 ;
T_2 V_3 ;
V_3 = F_2 ( V_22 + V_166 ) ;
V_165 . V_167 = ( V_3 >> 24 ) & 0xff ;
V_165 . V_168 = ( V_3 >> 16 ) & 0xff ;
V_165 . V_169 = ( V_3 >> 8 ) & 0xff ;
V_165 . V_170 = ( V_3 ) & 0xff ;
return F_65 ( & V_165 ) ;
}
void F_66 ( struct V_92 * V_93 , unsigned int V_171 ,
T_2 V_172 )
{
T_5 V_173 ;
V_173 = V_93 -> V_173 + V_171 * V_174 ;
V_93 -> V_175 [ V_171 ] . V_172 = F_67 ( V_172 ) ;
V_93 -> V_175 [ V_171 ] . V_176 = 0 ;
V_93 -> V_175 [ V_171 ] . V_177 = F_67 ( V_173 & 0xffffffff ) ;
V_93 -> V_175 [ V_171 ] . V_178 = F_67 ( ( V_173 >> 16 ) >> 16 ) ;
}
int F_68 ( struct V_13 * V_14 )
{
void T_1 * V_22 = F_12 ( V_14 ) ;
struct V_15 * V_16 = V_14 -> V_17 -> V_18 ;
T_6 V_176 = F_2 ( V_22 + V_179 ) & 0xFF ;
T_2 V_3 ;
int V_180 , V_122 ;
V_122 = F_30 ( V_14 ) ;
if ( V_122 )
goto V_181;
V_180 = V_176 & ( V_182 | V_183 ) ;
if ( ! V_180 && ! F_69 ( V_14 ) ) {
V_122 = 0 ;
goto V_181;
}
if ( ! ( V_16 -> V_19 & V_184 ) ) {
V_122 = - V_185 ;
goto V_181;
}
V_3 = F_2 ( V_22 + V_23 ) ;
V_3 |= V_186 ;
F_3 ( V_3 , V_22 + V_23 ) ;
V_122 = 0 ;
V_3 = F_31 ( V_14 , V_22 + V_23 ,
V_186 , V_186 , 1 , 500 ) ;
if ( V_3 & V_186 )
V_122 = - V_91 ;
V_181:
F_29 ( V_14 ) ;
return V_122 ;
}
static int F_70 ( struct V_13 * V_14 , int V_124 ,
struct V_164 * V_165 , int V_187 , T_7 V_28 ,
unsigned long V_188 )
{
const T_2 V_189 = 5 ;
struct V_92 * V_93 = V_14 -> V_18 ;
void T_1 * V_22 = F_12 ( V_14 ) ;
T_6 * V_190 = V_93 -> V_191 ;
T_2 V_3 ;
F_71 ( V_165 , V_124 , V_187 , V_190 ) ;
F_66 ( V_93 , 0 , V_189 | V_28 | ( V_124 << 12 ) ) ;
F_3 ( 1 , V_22 + V_192 ) ;
if ( V_188 ) {
V_3 = F_31 ( V_14 , V_22 + V_192 ,
0x1 , 0x1 , 1 , V_188 ) ;
if ( V_3 & 0x1 ) {
F_68 ( V_14 ) ;
return - V_45 ;
}
} else
F_2 ( V_22 + V_192 ) ;
return 0 ;
}
int F_72 ( struct V_86 * V_87 , unsigned int * V_193 ,
int V_124 , unsigned long V_194 ,
int (* F_73)( struct V_86 * V_87 ) )
{
struct V_13 * V_14 = V_87 -> V_14 ;
struct V_15 * V_16 = V_14 -> V_17 -> V_18 ;
const char * V_195 = NULL ;
unsigned long V_196 , V_197 ;
struct V_164 V_165 ;
int V_122 ;
F_74 ( L_31 ) ;
V_122 = F_68 ( V_14 ) ;
if ( V_122 && V_122 != - V_185 )
F_75 ( V_87 , L_32 , V_122 ) ;
F_76 ( V_87 -> V_6 , & V_165 ) ;
V_197 = 0 ;
V_196 = V_134 ;
if ( F_77 ( V_194 , V_196 ) )
V_197 = F_78 ( V_194 - V_196 ) ;
V_165 . V_198 |= V_199 ;
if ( F_70 ( V_14 , V_124 , & V_165 , 0 ,
V_200 | V_201 , V_197 ) ) {
V_122 = - V_91 ;
V_195 = L_33 ;
goto V_202;
}
F_37 ( V_14 , 1 ) ;
V_165 . V_198 &= ~ V_199 ;
F_70 ( V_14 , V_124 , & V_165 , 0 , 0 , 0 ) ;
V_122 = F_79 ( V_87 , V_194 , F_73 ) ;
if ( V_122 == - V_45 && V_16 -> V_28 & V_203 ) {
F_80 ( V_87 , L_34 ) ;
* V_193 = V_204 ;
} else if ( V_122 ) {
V_195 = L_35 ;
goto V_202;
} else
* V_193 = F_64 ( V_14 ) ;
F_74 ( L_36 , * V_193 ) ;
return 0 ;
V_202:
F_81 ( V_87 , L_37 , V_195 ) ;
return V_122 ;
}
int F_82 ( struct V_86 * V_87 )
{
void T_1 * V_22 = F_12 ( V_87 -> V_14 ) ;
T_6 V_176 = F_2 ( V_22 + V_179 ) & 0xFF ;
return F_83 ( V_176 ) ;
}
static int F_84 ( struct V_86 * V_87 , unsigned int * V_193 ,
unsigned long V_194 )
{
int V_124 = F_85 ( V_87 ) ;
F_74 ( L_31 ) ;
return F_72 ( V_87 , V_193 , V_124 , V_194 , F_82 ) ;
}
static int F_86 ( struct V_86 * V_87 )
{
void T_1 * V_22 = F_12 ( V_87 -> V_14 ) ;
T_6 V_176 = F_2 ( V_22 + V_179 ) & 0xFF ;
T_2 V_205 = F_2 ( V_22 + V_157 ) ;
if ( V_205 & V_206 )
return - V_91 ;
return F_83 ( V_176 ) ;
}
int F_87 ( struct V_86 * V_87 , unsigned int * V_193 ,
unsigned long V_194 )
{
struct V_13 * V_14 = V_87 -> V_14 ;
void T_1 * V_22 = F_12 ( V_14 ) ;
int V_124 = F_85 ( V_87 ) ;
int V_122 ;
T_2 V_207 ;
F_74 ( L_31 ) ;
V_122 = F_72 ( V_87 , V_193 , V_124 , V_194 ,
F_86 ) ;
if ( V_122 == - V_91 ) {
V_207 = F_2 ( V_22 + V_157 ) ;
if ( V_207 & V_206 ) {
F_88 ( V_87 , V_208 ,
L_38
L_39 ) ;
V_122 = F_72 ( V_87 , V_193 , 0 , V_194 ,
F_82 ) ;
}
}
return V_122 ;
}
static int F_89 ( struct V_86 * V_87 , unsigned int * V_193 ,
unsigned long V_194 )
{
const unsigned long * V_209 = F_90 ( & V_87 -> V_210 ) ;
struct V_13 * V_14 = V_87 -> V_14 ;
struct V_92 * V_93 = V_14 -> V_18 ;
T_6 * V_211 = V_93 -> V_212 + V_213 ;
struct V_164 V_165 ;
bool V_214 ;
int V_122 ;
F_74 ( L_31 ) ;
F_30 ( V_14 ) ;
F_76 ( V_87 -> V_6 , & V_165 ) ;
V_165 . V_215 = 0x80 ;
F_71 ( & V_165 , 0 , 0 , V_211 ) ;
V_122 = F_91 ( V_87 , V_209 , V_194 , & V_214 ,
F_82 ) ;
F_29 ( V_14 ) ;
if ( V_214 )
* V_193 = F_64 ( V_14 ) ;
F_74 ( L_40 , V_122 , * V_193 ) ;
return V_122 ;
}
static void F_92 ( struct V_86 * V_87 , unsigned int * V_193 )
{
struct V_13 * V_14 = V_87 -> V_14 ;
void T_1 * V_22 = F_12 ( V_14 ) ;
T_2 V_216 , V_3 ;
F_93 ( V_87 , V_193 ) ;
V_216 = V_3 = F_2 ( V_22 + V_23 ) ;
if ( * V_193 == V_217 )
V_216 |= V_218 ;
else
V_216 &= ~ V_218 ;
if ( V_216 != V_3 ) {
F_3 ( V_216 , V_22 + V_23 ) ;
F_2 ( V_22 + V_23 ) ;
}
}
static unsigned int F_94 ( struct V_219 * V_220 , void * V_191 )
{
struct V_221 * V_222 ;
struct V_223 * V_223 = V_191 + V_224 ;
unsigned int V_225 ;
F_59 ( L_31 ) ;
F_95 (qc->sg, sg, qc->n_elem, si) {
T_5 V_226 = F_96 ( V_222 ) ;
T_2 V_227 = F_97 ( V_222 ) ;
V_223 [ V_225 ] . V_226 = F_67 ( V_226 & 0xffffffff ) ;
V_223 [ V_225 ] . V_228 = F_67 ( ( V_226 >> 16 ) >> 16 ) ;
V_223 [ V_225 ] . V_229 = F_67 ( V_227 - 1 ) ;
}
return V_225 ;
}
static int F_98 ( struct V_219 * V_220 )
{
struct V_13 * V_14 = V_220 -> V_14 ;
struct V_92 * V_93 = V_14 -> V_18 ;
if ( ! F_69 ( V_14 ) || V_93 -> V_230 )
return F_99 ( V_220 ) ;
else
return F_100 ( V_220 ) ;
}
static void F_101 ( struct V_219 * V_220 )
{
struct V_13 * V_14 = V_220 -> V_14 ;
struct V_92 * V_93 = V_14 -> V_18 ;
int V_231 = F_102 ( V_220 -> V_165 . V_232 ) ;
void * V_191 ;
T_2 V_172 ;
const T_2 V_189 = 5 ;
unsigned int V_233 ;
V_191 = V_93 -> V_191 + V_220 -> V_171 * V_174 ;
F_71 ( & V_220 -> V_165 , V_220 -> V_7 -> V_87 -> V_124 , 1 , V_191 ) ;
if ( V_231 ) {
memset ( V_191 + V_234 , 0 , 32 ) ;
memcpy ( V_191 + V_234 , V_220 -> V_235 , V_220 -> V_7 -> V_236 ) ;
}
V_233 = 0 ;
if ( V_220 -> V_28 & V_237 )
V_233 = F_94 ( V_220 , V_191 ) ;
V_172 = V_189 | V_233 << 16 | ( V_220 -> V_7 -> V_87 -> V_124 << 12 ) ;
if ( V_220 -> V_165 . V_28 & V_238 )
V_172 |= V_239 ;
if ( V_231 )
V_172 |= V_240 | V_241 ;
F_66 ( V_93 , V_220 -> V_171 , V_172 ) ;
}
static void F_103 ( struct V_13 * V_14 )
{
struct V_92 * V_93 = V_14 -> V_18 ;
void T_1 * V_22 = F_12 ( V_14 ) ;
T_2 V_242 = F_2 ( V_22 + V_243 ) ;
int V_244 = 3 ;
F_74 ( L_31 ) ;
F_104 ( ! V_93 -> V_230 ) ;
F_3 ( V_242 | V_245 , V_22 + V_243 ) ;
V_242 = F_2 ( V_22 + V_243 ) ;
while ( ( V_242 & V_245 ) && V_244 -- ) {
F_105 ( 1 ) ;
V_242 = F_2 ( V_22 + V_243 ) ;
}
if ( V_242 & V_245 )
F_45 ( V_14 -> V_17 -> V_7 , L_41 ) ;
}
static void F_106 ( struct V_13 * V_14 , T_2 V_246 )
{
struct V_15 * V_16 = V_14 -> V_17 -> V_18 ;
struct V_92 * V_93 = V_14 -> V_18 ;
struct V_247 * V_248 = & V_14 -> V_87 . V_249 ;
struct V_86 * V_87 = NULL ;
struct V_219 * V_250 ;
struct V_247 * V_251 ;
bool V_252 = false ;
T_2 V_253 ;
if ( V_93 -> V_230 ) {
void T_1 * V_22 = F_12 ( V_14 ) ;
T_2 V_242 = F_2 ( V_22 + V_243 ) ;
int V_124 = V_242 >> V_254 ;
if ( ( V_242 & V_255 ) && ( V_124 < V_14 -> V_256 ) &&
F_107 ( & V_14 -> V_257 [ V_124 ] ) ) {
V_87 = & V_14 -> V_257 [ V_124 ] ;
V_252 = true ;
}
} else
F_40 (link, ap, EDGE)
if ( F_108 ( V_87 ) )
break;
if ( ! V_87 )
V_87 = & V_14 -> V_87 ;
V_250 = F_109 ( V_14 , V_87 -> V_258 ) ;
V_251 = & V_87 -> V_249 ;
F_110 ( V_248 ) ;
F_111 ( V_248 , L_42 , V_246 ) ;
F_27 ( & V_14 -> V_87 , V_80 , & V_253 ) ;
F_28 ( & V_14 -> V_87 , V_80 , V_253 ) ;
V_248 -> V_253 |= V_253 ;
if ( V_16 -> V_28 & V_259 )
V_246 &= ~ V_260 ;
if ( V_246 & V_261 ) {
if ( V_250 )
V_250 -> V_262 |= V_263 ;
else
V_251 -> V_262 |= V_263 ;
if ( V_16 -> V_28 & V_264 )
V_248 -> V_253 &= ~ V_265 ;
}
if ( V_246 & V_266 ) {
T_2 * V_267 = ( T_2 * ) ( V_93 -> V_212 + V_268 ) ;
V_251 -> V_262 |= V_269 ;
V_251 -> V_270 |= V_271 ;
F_111 ( V_251 ,
L_43 ,
V_267 [ 0 ] , V_267 [ 1 ] , V_267 [ 2 ] , V_267 [ 3 ] ) ;
}
if ( F_69 ( V_14 ) && ( V_246 & V_206 ) ) {
V_251 -> V_262 |= V_269 ;
V_251 -> V_270 |= V_271 ;
F_111 ( V_251 , L_44 ) ;
}
if ( V_246 & ( V_272 | V_273 ) ) {
V_248 -> V_262 |= V_274 ;
V_248 -> V_270 |= V_271 ;
F_111 ( V_248 , L_45 ) ;
}
if ( V_246 & V_260 ) {
if ( V_252 )
V_251 -> V_262 |= V_263 ;
else {
V_248 -> V_262 |= V_275 ;
V_248 -> V_270 |= V_271 ;
}
F_111 ( V_248 , L_46 ) ;
}
if ( V_246 & ( V_276 | V_112 ) ) {
F_112 ( V_248 ) ;
F_111 ( V_248 , L_47 ,
V_246 & V_276 ?
L_48 : L_49 ) ;
}
if ( V_246 & V_277 )
F_113 ( V_14 ) ;
else if ( V_252 ) {
F_114 ( V_87 ) ;
F_103 ( V_14 ) ;
} else
F_115 ( V_14 ) ;
}
static void F_116 ( struct V_13 * V_14 )
{
void T_1 * V_22 = F_12 ( V_14 ) ;
struct V_247 * V_278 = & V_14 -> V_87 . V_249 ;
struct V_92 * V_93 = V_14 -> V_18 ;
struct V_15 * V_16 = V_14 -> V_17 -> V_18 ;
int V_279 = ! ! ( V_14 -> V_280 & V_281 ) ;
T_2 V_176 , V_282 = 0 ;
int V_122 ;
V_176 = F_2 ( V_22 + V_157 ) ;
F_3 ( V_176 , V_22 + V_157 ) ;
if ( F_117 ( V_279 ) )
V_176 &= ~ V_206 ;
if ( V_14 -> V_87 . V_283 > V_110 ) {
V_176 &= ~ V_112 ;
F_28 ( & V_14 -> V_87 , V_80 , V_284 ) ;
}
if ( F_117 ( V_176 & V_285 ) ) {
F_106 ( V_14 , V_176 ) ;
return;
}
if ( V_176 & V_286 ) {
if ( V_16 -> V_19 & V_67 )
F_118 ( V_14 ) ;
else {
if ( V_93 -> V_230 )
F_119 ( 1 ) ;
else {
const T_8 * V_287 = V_93 -> V_212 + V_288 ;
T_2 V_289 = F_120 ( V_287 [ 0 ] ) ;
if ( V_289 & ( 1 << 15 ) )
F_118 ( V_14 ) ;
}
}
}
if ( V_93 -> V_230 ) {
if ( V_14 -> V_282 ) {
V_282 = F_2 ( V_22 + V_83 ) ;
V_282 |= F_2 ( V_22 + V_192 ) ;
}
} else {
if ( V_14 -> V_282 && V_93 -> V_290 -> V_291 )
V_282 = F_2 ( V_22 + V_83 ) ;
else
V_282 = F_2 ( V_22 + V_192 ) ;
}
V_122 = F_121 ( V_14 , V_282 ) ;
if ( F_117 ( V_122 < 0 && ! V_279 ) ) {
V_278 -> V_262 |= V_269 ;
V_278 -> V_270 |= V_271 ;
F_113 ( V_14 ) ;
}
}
T_9 F_122 ( int V_292 , void * V_293 )
{
struct V_73 * V_17 = V_293 ;
struct V_15 * V_16 ;
unsigned int V_2 , V_294 = 0 ;
void T_1 * V_1 ;
T_2 V_246 , V_295 ;
F_59 ( L_31 ) ;
V_16 = V_17 -> V_18 ;
V_1 = V_16 -> V_1 ;
V_246 = F_2 ( V_1 + V_158 ) ;
if ( ! V_246 )
return V_296 ;
V_295 = V_246 & V_16 -> V_53 ;
F_123 ( & V_17 -> V_30 ) ;
for ( V_2 = 0 ; V_2 < V_17 -> V_159 ; V_2 ++ ) {
struct V_13 * V_14 ;
if ( ! ( V_295 & ( 1 << V_2 ) ) )
continue;
V_14 = V_17 -> V_160 [ V_2 ] ;
if ( V_14 ) {
F_116 ( V_14 ) ;
F_59 ( L_50 , V_2 ) ;
} else {
F_59 ( L_51 , V_2 ) ;
if ( F_124 () )
F_22 ( V_17 -> V_7 ,
L_52 , V_2 ) ;
}
V_294 = 1 ;
}
F_3 ( V_246 , V_1 + V_158 ) ;
F_125 ( & V_17 -> V_30 ) ;
F_59 ( L_53 ) ;
return F_126 ( V_294 ) ;
}
static unsigned int F_127 ( struct V_219 * V_220 )
{
struct V_13 * V_14 = V_220 -> V_14 ;
void T_1 * V_22 = F_12 ( V_14 ) ;
struct V_92 * V_93 = V_14 -> V_18 ;
V_93 -> V_290 = V_220 -> V_7 -> V_87 ;
if ( V_220 -> V_165 . V_232 == V_297 )
F_3 ( 1 << V_220 -> V_171 , V_22 + V_83 ) ;
if ( V_93 -> V_230 && V_93 -> V_298 != V_220 -> V_7 -> V_87 -> V_124 ) {
T_2 V_242 = F_2 ( V_22 + V_243 ) ;
V_242 &= ~ ( V_299 | V_245 ) ;
V_242 |= V_220 -> V_7 -> V_87 -> V_124 << V_300 ;
F_3 ( V_242 , V_22 + V_243 ) ;
V_93 -> V_298 = V_220 -> V_7 -> V_87 -> V_124 ;
}
F_3 ( 1 << V_220 -> V_171 , V_22 + V_192 ) ;
F_46 ( V_220 -> V_7 -> V_87 ) ;
return 0 ;
}
static bool F_128 ( struct V_219 * V_220 )
{
struct V_92 * V_93 = V_220 -> V_14 -> V_18 ;
T_6 * V_212 = V_93 -> V_212 ;
if ( V_93 -> V_230 )
V_212 += V_220 -> V_7 -> V_87 -> V_124 * V_301 ;
if ( V_220 -> V_165 . V_232 == V_302 && V_220 -> V_303 == V_304 &&
! ( V_220 -> V_28 & V_305 ) ) {
F_129 ( V_212 + V_306 , & V_220 -> V_307 ) ;
V_220 -> V_307 . V_215 = ( V_212 + V_306 ) [ 15 ] ;
} else
F_129 ( V_212 + V_213 , & V_220 -> V_307 ) ;
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
V_3 = F_2 ( V_22 + V_157 ) ;
F_3 ( V_3 , V_22 + V_157 ) ;
F_3 ( 1 << V_14 -> V_139 , V_1 + V_158 ) ;
F_3 ( V_93 -> V_111 , V_22 + V_113 ) ;
}
static void F_132 ( struct V_13 * V_14 )
{
if ( ! ( V_14 -> V_280 & V_308 ) ) {
F_30 ( V_14 ) ;
F_29 ( V_14 ) ;
}
F_133 ( V_14 ) ;
if ( ! F_134 ( V_14 -> V_87 . V_6 ) )
F_30 ( V_14 ) ;
}
static void F_135 ( struct V_219 * V_220 )
{
struct V_13 * V_14 = V_220 -> V_14 ;
if ( V_220 -> V_28 & V_305 )
F_68 ( V_14 ) ;
}
static void F_136 ( struct V_13 * V_14 )
{
struct V_92 * V_93 = V_14 -> V_18 ;
void T_1 * V_22 = F_12 ( V_14 ) ;
T_2 V_242 ;
int V_122 ;
if ( ! V_93 -> V_309 )
return;
V_242 = F_2 ( V_22 + V_243 ) ;
if ( V_242 & V_310 ) {
V_93 -> V_230 = true ;
V_93 -> V_298 = - 1 ;
return;
}
V_122 = F_30 ( V_14 ) ;
if ( V_122 )
return;
F_3 ( V_242 | V_310 , V_22 + V_243 ) ;
V_242 = F_2 ( V_22 + V_243 ) ;
if ( V_242 & V_310 ) {
F_21 ( V_14 -> V_17 -> V_7 , L_54 ) ;
V_93 -> V_230 = true ;
V_93 -> V_298 = - 1 ;
} else
F_45 ( V_14 -> V_17 -> V_7 , L_55 ) ;
F_29 ( V_14 ) ;
}
static void F_137 ( struct V_13 * V_14 )
{
struct V_92 * V_93 = V_14 -> V_18 ;
void T_1 * V_22 = F_12 ( V_14 ) ;
T_2 V_242 ;
int V_122 ;
if ( ! V_93 -> V_309 )
return;
V_242 = F_2 ( V_22 + V_243 ) ;
if ( ( V_242 & V_310 ) == 0 ) {
V_93 -> V_230 = false ;
return;
}
V_122 = F_30 ( V_14 ) ;
if ( V_122 )
return;
F_3 ( V_242 & ~ V_310 , V_22 + V_243 ) ;
V_242 = F_2 ( V_22 + V_243 ) ;
if ( V_242 & V_310 )
F_45 ( V_14 -> V_17 -> V_7 , L_56 ) ;
else {
F_21 ( V_14 -> V_17 -> V_7 , L_57 ) ;
V_93 -> V_230 = false ;
}
F_29 ( V_14 ) ;
}
static void F_138 ( struct V_13 * V_14 )
{
void T_1 * V_22 = F_12 ( V_14 ) ;
struct V_92 * V_93 = V_14 -> V_18 ;
T_2 V_102 ;
V_102 = F_2 ( V_22 + V_23 ) ;
V_102 |= V_311 ;
F_3 ( V_102 , V_22 + V_23 ) ;
F_136 ( V_14 ) ;
V_93 -> V_111 |= V_206 ;
if ( ! ( V_14 -> V_280 & V_308 ) )
F_3 ( V_93 -> V_111 , V_22 + V_113 ) ;
}
static void F_139 ( struct V_13 * V_14 )
{
void T_1 * V_22 = F_12 ( V_14 ) ;
struct V_92 * V_93 = V_14 -> V_18 ;
T_2 V_102 ;
F_137 ( V_14 ) ;
V_102 = F_2 ( V_22 + V_23 ) ;
V_102 &= ~ V_311 ;
F_3 ( V_102 , V_22 + V_23 ) ;
V_93 -> V_111 &= ~ V_206 ;
if ( ! ( V_14 -> V_280 & V_308 ) )
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
static int F_141 ( struct V_13 * V_14 , T_10 V_312 )
{
const char * V_128 = NULL ;
int V_122 ;
V_122 = F_43 ( V_14 , & V_128 ) ;
if ( V_122 == 0 )
F_38 ( V_14 ) ;
else {
F_142 ( V_14 , L_26 , V_128 , V_122 ) ;
F_113 ( V_14 ) ;
}
return V_122 ;
}
static int F_143 ( struct V_13 * V_14 )
{
struct V_15 * V_16 = V_14 -> V_17 -> V_18 ;
struct V_6 * V_7 = V_14 -> V_17 -> V_7 ;
struct V_92 * V_93 ;
void * V_313 ;
T_5 V_314 ;
T_4 V_315 , V_316 ;
V_93 = F_144 ( V_7 , sizeof( * V_93 ) , V_317 ) ;
if ( ! V_93 )
return - V_318 ;
if ( ( V_16 -> V_19 & V_69 ) && F_145 ( V_14 ) ) {
void T_1 * V_22 = F_12 ( V_14 ) ;
T_2 V_102 = F_2 ( V_22 + V_23 ) ;
if ( V_102 & V_319 )
V_93 -> V_309 = true ;
else if ( V_16 -> V_28 & V_70 ) {
F_21 ( V_7 , L_58 ,
V_14 -> V_139 ) ;
V_93 -> V_309 = true ;
} else
F_22 ( V_7 , L_59 ,
V_14 -> V_139 ) ;
}
if ( V_93 -> V_309 ) {
V_315 = V_320 ;
V_316 = V_301 * 16 ;
} else {
V_315 = V_321 ;
V_316 = V_301 ;
}
V_313 = F_146 ( V_7 , V_315 , & V_314 , V_317 ) ;
if ( ! V_313 )
return - V_318 ;
memset ( V_313 , 0 , V_315 ) ;
V_93 -> V_175 = V_313 ;
V_93 -> V_94 = V_314 ;
V_313 += V_322 ;
V_314 += V_322 ;
V_93 -> V_212 = V_313 ;
V_93 -> V_97 = V_314 ;
V_313 += V_316 ;
V_314 += V_316 ;
V_93 -> V_191 = V_313 ;
V_93 -> V_173 = V_314 ;
V_93 -> V_111 = V_323 ;
V_14 -> V_18 = V_93 ;
return F_140 ( V_14 ) ;
}
static void F_147 ( struct V_13 * V_14 )
{
const char * V_128 = NULL ;
int V_122 ;
V_122 = F_43 ( V_14 , & V_128 ) ;
if ( V_122 )
F_17 ( V_14 , L_26 , V_128 , V_122 ) ;
}
void F_148 ( struct V_73 * V_17 , const char * V_324 )
{
struct V_15 * V_16 = V_17 -> V_18 ;
void T_1 * V_1 = V_16 -> V_1 ;
T_2 V_52 , V_19 , V_20 , V_325 , V_326 ;
const char * V_327 ;
V_52 = F_2 ( V_1 + V_21 ) ;
V_19 = V_16 -> V_19 ;
V_20 = V_16 -> V_20 ;
V_325 = V_16 -> V_53 ;
V_326 = ( V_19 >> 20 ) & 0xf ;
if ( V_326 == 1 )
V_327 = L_60 ;
else if ( V_326 == 2 )
V_327 = L_61 ;
else if ( V_326 == 3 )
V_327 = L_62 ;
else
V_327 = L_63 ;
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
V_327 ,
V_325 ,
V_324 ) ;
F_21 ( V_17 -> V_7 ,
L_66
L_67
L_67
L_68
,
V_19 & V_60 ? L_69 : L_6 ,
V_19 & V_62 ? L_70 : L_6 ,
V_19 & V_67 ? L_71 : L_6 ,
V_19 & V_328 ? L_72 : L_6 ,
V_19 & V_104 ? L_73 : L_6 ,
V_19 & V_114 ? L_74 : L_6 ,
V_19 & V_329 ? L_5 : L_6 ,
V_19 & V_184 ? L_75 : L_6 ,
V_19 & V_330 ? L_76 : L_6 ,
V_19 & V_65 ? L_77 : L_6 ,
V_19 & V_69 ? L_78 : L_6 ,
V_19 & V_331 ? L_79 : L_6 ,
V_19 & V_332 ? L_80 : L_6 ,
V_19 & V_333 ? L_81 : L_6 ,
V_19 & V_334 ? L_82 : L_6 ,
V_19 & V_335 ? L_83 : L_6 ,
V_19 & V_336 ? L_84 : L_6 ,
V_20 & V_337 ? L_85 : L_6 ,
V_20 & V_338 ? L_86 : L_6 ,
V_20 & V_339 ? L_87 : L_6
) ;
}
void F_149 ( struct V_15 * V_16 ,
struct V_340 * V_341 )
{
T_6 V_342 ;
void T_1 * V_1 = V_16 -> V_1 ;
T_2 V_25 = F_2 ( V_1 + V_343 ) ;
T_2 V_26 = F_2 ( V_1 + V_31 ) ;
if ( ! V_344 || ! ( V_16 -> V_19 & V_335 ) )
return;
V_342 = ( V_26 & V_345 ) >> 16 ;
if ( V_342 ) {
V_16 -> V_25 = ( ( V_25 >> 16 ) * 4 ) ;
V_16 -> V_40 = ( ( V_25 & 0xff ) * 4 ) ;
V_16 -> V_34 = V_342 ;
V_341 -> V_28 |= V_32 ;
if ( ! ( V_26 & V_346 ) )
V_341 -> V_28 |= V_127 ;
}
}
