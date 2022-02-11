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
if ( ( V_20 & V_69 ) && ( V_16 -> V_28 & V_70 ) ) {
F_21 ( V_7 ,
L_15 ) ;
V_20 &= ~ V_69 ;
V_20 &= ~ V_71 ;
}
if ( ! ( V_19 & V_72 ) && ( V_16 -> V_28 & V_73 ) ) {
F_21 ( V_7 , L_16 ) ;
V_19 |= V_72 ;
}
if ( ( V_19 & V_72 ) && ( V_16 -> V_28 & V_74 ) ) {
F_21 ( V_7 , L_17 ) ;
V_19 &= ~ V_72 ;
}
if ( V_50 && V_53 != V_50 ) {
F_21 ( V_7 , L_18 ,
V_53 , V_50 ) ;
V_53 = V_50 ;
}
if ( V_51 ) {
F_22 ( V_7 , L_19 ,
V_53 ,
V_53 & V_51 ) ;
V_53 &= V_51 ;
}
if ( V_53 ) {
int V_75 = 0 ;
for ( V_2 = 0 ; V_2 < V_76 ; V_2 ++ )
if ( V_53 & ( 1 << V_2 ) )
V_75 ++ ;
if ( V_75 > F_23 ( V_19 ) ) {
F_22 ( V_7 ,
L_20 ,
V_53 , F_23 ( V_19 ) ) ;
V_53 = 0 ;
}
}
if ( ! V_53 ) {
V_53 = ( 1 << F_23 ( V_19 ) ) - 1 ;
F_22 ( V_7 , L_21 , V_53 ) ;
V_16 -> V_56 = V_53 ;
}
V_16 -> V_19 = V_19 ;
V_16 -> V_20 = V_20 ;
V_16 -> V_53 = V_53 ;
if ( ! V_16 -> V_77 )
V_16 -> V_77 = V_78 ;
}
static void F_24 ( struct V_79 * V_17 )
{
struct V_15 * V_16 = V_17 -> V_18 ;
void T_1 * V_1 = V_16 -> V_1 ;
F_3 ( V_16 -> V_54 , V_1 + V_55 ) ;
if ( V_16 -> V_58 )
F_3 ( V_16 -> V_58 , V_1 + V_59 ) ;
F_3 ( V_16 -> V_56 , V_1 + V_57 ) ;
( void ) F_2 ( V_1 + V_57 ) ;
}
static unsigned F_25 ( struct V_13 * V_14 , unsigned int V_80 )
{
static const int V_81 [] = {
[ V_82 ] = V_83 ,
[ V_84 ] = V_85 ,
[ V_86 ] = V_87 ,
[ V_88 ] = V_89 ,
[ V_90 ] = V_91 ,
} ;
struct V_15 * V_16 = V_14 -> V_17 -> V_18 ;
if ( V_80 < F_26 ( V_81 ) &&
( V_80 != V_90 || ( V_16 -> V_19 & V_67 ) ) )
return V_81 [ V_80 ] ;
return 0 ;
}
static int F_27 ( struct V_92 * V_93 , unsigned int V_80 , T_2 * V_94 )
{
void T_1 * V_22 = F_12 ( V_93 -> V_14 ) ;
int V_81 = F_25 ( V_93 -> V_14 , V_80 ) ;
if ( V_81 ) {
* V_94 = F_2 ( V_22 + V_81 ) ;
return 0 ;
}
return - V_36 ;
}
static int F_28 ( struct V_92 * V_93 , unsigned int V_80 , T_2 V_94 )
{
void T_1 * V_22 = F_12 ( V_93 -> V_14 ) ;
int V_81 = F_25 ( V_93 -> V_14 , V_80 ) ;
if ( V_81 ) {
F_3 ( V_94 , V_22 + V_81 ) ;
return 0 ;
}
return - V_36 ;
}
void V_78 ( struct V_13 * V_14 )
{
void T_1 * V_22 = F_12 ( V_14 ) ;
T_2 V_3 ;
V_3 = F_2 ( V_22 + V_23 ) ;
V_3 |= V_95 ;
F_3 ( V_3 , V_22 + V_23 ) ;
F_2 ( V_22 + V_23 ) ;
}
int F_29 ( struct V_13 * V_14 )
{
void T_1 * V_22 = F_12 ( V_14 ) ;
T_2 V_3 ;
V_3 = F_2 ( V_22 + V_23 ) ;
if ( ( V_3 & ( V_95 | V_96 ) ) == 0 )
return 0 ;
V_3 &= ~ V_95 ;
F_3 ( V_3 , V_22 + V_23 ) ;
V_3 = F_30 ( V_14 , V_22 + V_23 ,
V_96 , V_96 , 1 , 500 ) ;
if ( V_3 & V_96 )
return - V_97 ;
return 0 ;
}
void F_31 ( struct V_13 * V_14 )
{
void T_1 * V_22 = F_12 ( V_14 ) ;
struct V_15 * V_16 = V_14 -> V_17 -> V_18 ;
struct V_98 * V_99 = V_14 -> V_18 ;
T_2 V_3 ;
if ( V_16 -> V_19 & V_60 )
F_3 ( ( V_99 -> V_100 >> 16 ) >> 16 ,
V_22 + V_101 ) ;
F_3 ( V_99 -> V_100 & 0xffffffff , V_22 + V_102 ) ;
if ( V_16 -> V_19 & V_60 )
F_3 ( ( V_99 -> V_103 >> 16 ) >> 16 ,
V_22 + V_104 ) ;
F_3 ( V_99 -> V_103 & 0xffffffff , V_22 + V_105 ) ;
V_3 = F_2 ( V_22 + V_23 ) ;
V_3 |= V_106 ;
F_3 ( V_3 , V_22 + V_23 ) ;
F_2 ( V_22 + V_23 ) ;
}
static int F_32 ( struct V_13 * V_14 )
{
void T_1 * V_22 = F_12 ( V_14 ) ;
T_2 V_3 ;
V_3 = F_2 ( V_22 + V_23 ) ;
V_3 &= ~ V_106 ;
F_3 ( V_3 , V_22 + V_23 ) ;
V_3 = F_30 ( V_14 , V_22 + V_23 , V_107 ,
V_107 , 10 , 1000 ) ;
if ( V_3 & V_107 )
return - V_45 ;
return 0 ;
}
static void F_33 ( struct V_13 * V_14 )
{
struct V_15 * V_16 = V_14 -> V_17 -> V_18 ;
void T_1 * V_22 = F_12 ( V_14 ) ;
T_2 V_108 ;
V_108 = F_2 ( V_22 + V_23 ) & ~ V_109 ;
if ( V_16 -> V_19 & V_110 ) {
V_108 |= V_111 ;
F_3 ( V_108 , V_22 + V_23 ) ;
}
F_3 ( V_108 | V_112 , V_22 + V_23 ) ;
}
static int F_34 ( struct V_92 * V_93 , enum V_113 V_114 ,
unsigned int V_115 )
{
struct V_13 * V_14 = V_93 -> V_14 ;
struct V_15 * V_16 = V_14 -> V_17 -> V_18 ;
struct V_98 * V_99 = V_14 -> V_18 ;
void T_1 * V_22 = F_12 ( V_14 ) ;
if ( V_114 != V_116 ) {
V_99 -> V_117 &= ~ V_118 ;
F_3 ( V_99 -> V_117 , V_22 + V_119 ) ;
F_35 ( V_93 , V_114 , false ) ;
}
if ( V_16 -> V_19 & V_120 ) {
T_2 V_108 = F_2 ( V_22 + V_23 ) ;
if ( V_114 == V_116 || ! ( V_115 & V_121 ) ) {
V_108 &= ~ ( V_122 | V_123 ) ;
V_108 |= V_112 ;
F_3 ( V_108 , V_22 + V_23 ) ;
F_2 ( V_22 + V_23 ) ;
F_36 ( V_14 , 10 ) ;
} else {
V_108 |= V_123 ;
if ( V_114 == V_124 )
V_108 |= V_122 ;
F_3 ( V_108 , V_22 + V_23 ) ;
}
}
if ( ( V_16 -> V_20 & V_69 ) &&
( V_16 -> V_20 & V_71 ) &&
( V_93 -> V_6 -> V_28 & V_125 ) ) {
if ( V_114 == V_124 )
F_37 ( V_14 , true ) ;
else
F_37 ( V_14 , false ) ;
}
if ( V_114 == V_116 ) {
F_35 ( V_93 , V_114 , false ) ;
V_99 -> V_117 |= V_118 ;
F_3 ( V_99 -> V_117 , V_22 + V_119 ) ;
}
return 0 ;
}
static void F_38 ( struct V_13 * V_14 )
{
struct V_15 * V_16 = V_14 -> V_17 -> V_18 ;
void T_1 * V_22 = F_12 ( V_14 ) ;
T_2 V_108 , V_126 ;
if ( ! ( V_16 -> V_19 & V_110 ) )
return;
V_126 = F_2 ( V_22 + V_85 ) ;
V_126 &= ~ 0xf ;
F_3 ( V_126 , V_22 + V_85 ) ;
V_108 = F_2 ( V_22 + V_23 ) & ~ V_109 ;
V_108 &= ~ V_111 ;
F_3 ( V_108 , V_22 + V_23 ) ;
}
static void F_39 ( struct V_13 * V_14 )
{
struct V_15 * V_16 = V_14 -> V_17 -> V_18 ;
struct V_98 * V_99 = V_14 -> V_18 ;
struct V_92 * V_93 ;
struct V_127 * V_128 ;
T_3 V_129 ;
int V_2 ;
F_31 ( V_14 ) ;
if ( ! ( V_16 -> V_28 & V_130 ) )
V_16 -> V_77 ( V_14 ) ;
if ( V_14 -> V_28 & V_32 ) {
F_40 (link, ap, EDGE) {
V_128 = & V_99 -> V_131 [ V_93 -> V_132 ] ;
for ( V_2 = 0 ; V_2 < V_133 ; V_2 ++ ) {
V_129 = V_14 -> V_134 -> V_135 ( V_14 ,
V_128 -> V_136 ,
4 ) ;
if ( V_129 == - V_45 )
F_4 ( 1 ) ;
else
break;
}
}
}
if ( V_14 -> V_28 & V_137 )
F_40 (link, ap, EDGE)
F_41 ( V_93 ) ;
}
static int F_42 ( struct V_13 * V_14 , const char * * V_138 )
{
int V_129 ;
V_129 = F_29 ( V_14 ) ;
if ( V_129 ) {
* V_138 = L_22 ;
return V_129 ;
}
V_129 = F_32 ( V_14 ) ;
if ( V_129 ) {
* V_138 = L_23 ;
return V_129 ;
}
return 0 ;
}
int F_43 ( struct V_79 * V_17 )
{
struct V_15 * V_16 = V_17 -> V_18 ;
void T_1 * V_1 = V_16 -> V_1 ;
T_2 V_3 ;
F_1 ( V_1 ) ;
if ( ! V_139 ) {
V_3 = F_2 ( V_1 + V_4 ) ;
if ( ( V_3 & V_140 ) == 0 ) {
F_3 ( V_3 | V_140 , V_1 + V_4 ) ;
F_2 ( V_1 + V_4 ) ;
}
V_3 = F_30 ( NULL , V_1 + V_4 , V_140 ,
V_140 , 10 , 1000 ) ;
if ( V_3 & V_140 ) {
F_44 ( V_17 -> V_7 , L_24 ,
V_3 ) ;
return - V_97 ;
}
F_1 ( V_1 ) ;
F_24 ( V_17 ) ;
} else
F_21 ( V_17 -> V_7 , L_25 ) ;
return 0 ;
}
static void F_45 ( struct V_92 * V_93 )
{
struct V_13 * V_14 = V_93 -> V_14 ;
struct V_98 * V_99 = V_14 -> V_18 ;
struct V_127 * V_128 = & V_99 -> V_131 [ V_93 -> V_132 ] ;
if ( ! ( V_93 -> V_28 & V_141 ) )
return;
V_128 -> V_142 ++ ;
if ( ! F_46 ( & V_128 -> V_143 ) )
F_47 ( & V_128 -> V_143 , V_144 + F_48 ( 10 ) ) ;
}
static void F_49 ( unsigned long V_145 )
{
struct V_92 * V_93 = (struct V_92 * ) V_145 ;
struct V_13 * V_14 = V_93 -> V_14 ;
struct V_98 * V_99 = V_14 -> V_18 ;
struct V_127 * V_128 = & V_99 -> V_131 [ V_93 -> V_132 ] ;
unsigned long V_146 = V_128 -> V_136 ;
T_2 V_147 ;
unsigned long V_28 ;
V_146 &= V_148 ;
V_146 |= V_14 -> V_149 | ( V_93 -> V_132 << 8 ) ;
F_14 ( V_14 -> V_30 , V_28 ) ;
if ( V_128 -> V_150 != V_128 -> V_142 ) {
V_128 -> V_150 = V_128 -> V_142 ;
V_147 = V_146 & V_151 ;
if ( V_147 )
V_147 = 0 ;
else
V_147 = 1 ;
V_146 &= ~ V_152 ;
V_146 |= ( V_147 << 16 ) ;
F_47 ( & V_128 -> V_143 , V_144 + F_48 ( 100 ) ) ;
} else {
V_146 &= ~ V_152 ;
if ( V_128 -> V_153 == V_154 )
V_146 |= ( 1 << 16 ) ;
}
F_15 ( V_14 -> V_30 , V_28 ) ;
V_14 -> V_134 -> V_135 ( V_14 , V_146 , 4 ) ;
}
static void F_41 ( struct V_92 * V_93 )
{
struct V_13 * V_14 = V_93 -> V_14 ;
struct V_98 * V_99 = V_14 -> V_18 ;
struct V_127 * V_128 = & V_99 -> V_131 [ V_93 -> V_132 ] ;
V_128 -> V_150 = V_128 -> V_142 = 0 ;
F_50 ( & V_128 -> V_143 , F_49 , ( unsigned long ) V_93 ) ;
if ( V_128 -> V_153 )
V_93 -> V_28 |= V_141 ;
}
int F_51 ( struct V_79 * V_17 )
{
struct V_15 * V_16 = V_17 -> V_18 ;
void T_1 * V_1 = V_16 -> V_1 ;
T_2 V_26 ;
V_26 = F_2 ( V_1 + V_31 ) ;
if ( ( V_26 & V_44 ) || ( V_26 & V_155 ) )
return - V_36 ;
F_3 ( V_26 | V_155 , V_1 + V_31 ) ;
return 0 ;
}
static T_3 F_52 ( struct V_13 * V_14 , T_2 V_156 ,
T_3 V_42 )
{
struct V_15 * V_16 = V_14 -> V_17 -> V_18 ;
struct V_98 * V_99 = V_14 -> V_18 ;
void T_1 * V_1 = V_16 -> V_1 ;
T_2 V_26 ;
T_2 V_157 [] = { 0 , 0 } ;
unsigned long V_28 ;
int V_132 ;
struct V_127 * V_128 ;
V_132 = ( V_156 & V_158 ) >> 8 ;
if ( V_132 < V_159 )
V_128 = & V_99 -> V_131 [ V_132 ] ;
else
return - V_36 ;
F_14 ( V_14 -> V_30 , V_28 ) ;
V_26 = F_2 ( V_1 + V_31 ) ;
if ( V_26 & V_44 ) {
F_15 ( V_14 -> V_30 , V_28 ) ;
return - V_45 ;
}
if ( V_16 -> V_34 & V_160 ) {
V_157 [ 0 ] |= ( 4 << 8 ) ;
V_157 [ 1 ] = ( ( V_156 & ~ V_161 ) | V_14 -> V_149 ) ;
F_3 ( V_157 [ 0 ] , V_1 + V_16 -> V_25 ) ;
F_3 ( V_157 [ 1 ] , V_1 + V_16 -> V_25 + 4 ) ;
F_3 ( V_26 | V_44 , V_1 + V_31 ) ;
}
V_128 -> V_136 = V_156 ;
F_15 ( V_14 -> V_30 , V_28 ) ;
return V_42 ;
}
static T_3 F_53 ( struct V_13 * V_14 , char * V_10 )
{
struct V_98 * V_99 = V_14 -> V_18 ;
struct V_92 * V_93 ;
struct V_127 * V_128 ;
int V_129 = 0 ;
F_40 (link, ap, EDGE) {
V_128 = & V_99 -> V_131 [ V_93 -> V_132 ] ;
V_129 += sprintf ( V_10 , L_26 , V_128 -> V_136 ) ;
}
return V_129 ;
}
static T_3 F_54 ( struct V_13 * V_14 , const char * V_10 ,
T_4 V_42 )
{
unsigned int V_156 ;
int V_132 ;
struct V_98 * V_99 = V_14 -> V_18 ;
struct V_127 * V_128 ;
if ( F_55 ( V_10 , 0 , & V_156 ) < 0 )
return - V_36 ;
V_132 = ( V_156 & V_158 ) >> 8 ;
if ( V_132 < V_159 )
V_128 = & V_99 -> V_131 [ V_132 ] ;
else
return - V_36 ;
if ( V_128 -> V_153 )
V_156 &= ~ V_152 ;
return V_14 -> V_134 -> V_135 ( V_14 , V_156 , V_42 ) ;
}
static T_3 F_56 ( struct V_162 * V_7 , enum V_163 V_94 )
{
struct V_92 * V_93 = V_7 -> V_93 ;
struct V_13 * V_14 = V_93 -> V_14 ;
struct V_98 * V_99 = V_14 -> V_18 ;
struct V_127 * V_128 = & V_99 -> V_131 [ V_93 -> V_132 ] ;
T_2 V_164 = V_128 -> V_136 ;
if ( V_94 == V_165 ) {
V_93 -> V_28 &= ~ ( V_141 ) ;
V_164 &= V_166 ;
V_164 |= ( V_14 -> V_149 | ( V_93 -> V_132 << 8 ) ) ;
V_14 -> V_134 -> V_135 ( V_14 , V_164 , 4 ) ;
} else {
V_93 -> V_28 |= V_141 ;
if ( V_94 == V_154 ) {
V_164 &= V_166 ;
V_164 |= ( V_14 -> V_149 | ( V_93 -> V_132 << 8 ) ) ;
V_164 |= V_151 ;
V_14 -> V_134 -> V_135 ( V_14 , V_164 , 4 ) ;
}
}
V_128 -> V_153 = V_94 ;
return 0 ;
}
static T_3 F_57 ( struct V_162 * V_7 , char * V_10 )
{
struct V_92 * V_93 = V_7 -> V_93 ;
struct V_13 * V_14 = V_93 -> V_14 ;
struct V_98 * V_99 = V_14 -> V_18 ;
struct V_127 * V_128 = & V_99 -> V_131 [ V_93 -> V_132 ] ;
return sprintf ( V_10 , L_27 , V_128 -> V_153 ) ;
}
static void F_58 ( struct V_6 * V_7 , struct V_13 * V_14 ,
int V_149 , void T_1 * V_1 ,
void T_1 * V_22 )
{
const char * V_138 = NULL ;
int V_129 ;
T_2 V_3 ;
V_129 = F_42 ( V_14 , & V_138 ) ;
if ( V_129 )
F_22 ( V_7 , L_28 , V_138 , V_129 ) ;
V_3 = F_2 ( V_22 + V_87 ) ;
F_59 ( L_29 , V_3 ) ;
F_3 ( V_3 , V_22 + V_87 ) ;
V_3 = F_2 ( V_22 + V_167 ) ;
F_59 ( L_30 , V_3 ) ;
if ( V_3 )
F_3 ( V_3 , V_22 + V_167 ) ;
F_3 ( 1 << V_149 , V_1 + V_168 ) ;
}
void F_60 ( struct V_79 * V_17 )
{
struct V_15 * V_16 = V_17 -> V_18 ;
void T_1 * V_1 = V_16 -> V_1 ;
int V_2 ;
void T_1 * V_22 ;
T_2 V_3 ;
for ( V_2 = 0 ; V_2 < V_17 -> V_169 ; V_2 ++ ) {
struct V_13 * V_14 = V_17 -> V_170 [ V_2 ] ;
V_22 = F_12 ( V_14 ) ;
if ( F_61 ( V_14 ) )
continue;
F_58 ( V_17 -> V_7 , V_14 , V_2 , V_1 , V_22 ) ;
}
V_3 = F_2 ( V_1 + V_4 ) ;
F_59 ( L_31 , V_3 ) ;
F_3 ( V_3 | V_171 , V_1 + V_4 ) ;
V_3 = F_2 ( V_1 + V_4 ) ;
F_59 ( L_31 , V_3 ) ;
}
static void F_62 ( struct V_162 * V_7 )
{
struct V_15 * V_16 = V_7 -> V_93 -> V_14 -> V_17 -> V_18 ;
if ( V_16 -> V_28 & V_172 ) {
V_7 -> V_173 = 255 ;
F_63 ( V_7 ,
L_32 ) ;
}
}
unsigned int F_64 ( struct V_13 * V_14 )
{
void T_1 * V_22 = F_12 ( V_14 ) ;
struct V_174 V_175 ;
T_2 V_3 ;
V_3 = F_2 ( V_22 + V_176 ) ;
V_175 . V_177 = ( V_3 >> 24 ) & 0xff ;
V_175 . V_178 = ( V_3 >> 16 ) & 0xff ;
V_175 . V_179 = ( V_3 >> 8 ) & 0xff ;
V_175 . V_180 = ( V_3 ) & 0xff ;
return F_65 ( & V_175 ) ;
}
void F_66 ( struct V_98 * V_99 , unsigned int V_181 ,
T_2 V_182 )
{
T_5 V_183 ;
V_183 = V_99 -> V_183 + V_181 * V_184 ;
V_99 -> V_185 [ V_181 ] . V_182 = F_67 ( V_182 ) ;
V_99 -> V_185 [ V_181 ] . V_186 = 0 ;
V_99 -> V_185 [ V_181 ] . V_187 = F_67 ( V_183 & 0xffffffff ) ;
V_99 -> V_185 [ V_181 ] . V_188 = F_67 ( ( V_183 >> 16 ) >> 16 ) ;
}
int F_68 ( struct V_13 * V_14 )
{
void T_1 * V_22 = F_12 ( V_14 ) ;
struct V_15 * V_16 = V_14 -> V_17 -> V_18 ;
T_6 V_186 = F_2 ( V_22 + V_189 ) & 0xFF ;
T_2 V_3 ;
int V_190 , V_129 ;
V_129 = F_29 ( V_14 ) ;
if ( V_129 )
goto V_191;
V_190 = V_186 & ( V_192 | V_193 ) ;
if ( ! V_190 && ! F_69 ( V_14 ) ) {
V_129 = 0 ;
goto V_191;
}
if ( ! ( V_16 -> V_19 & V_194 ) ) {
V_129 = - V_195 ;
goto V_191;
}
V_3 = F_2 ( V_22 + V_23 ) ;
V_3 |= V_196 ;
F_3 ( V_3 , V_22 + V_23 ) ;
V_129 = 0 ;
V_3 = F_30 ( V_14 , V_22 + V_23 ,
V_196 , V_196 , 1 , 500 ) ;
if ( V_3 & V_196 )
V_129 = - V_97 ;
V_191:
V_16 -> V_77 ( V_14 ) ;
return V_129 ;
}
static int F_70 ( struct V_13 * V_14 , int V_132 ,
struct V_174 * V_175 , int V_197 , T_7 V_28 ,
unsigned long V_198 )
{
const T_2 V_199 = 5 ;
struct V_98 * V_99 = V_14 -> V_18 ;
void T_1 * V_22 = F_12 ( V_14 ) ;
T_6 * V_200 = V_99 -> V_201 ;
T_2 V_3 ;
F_71 ( V_175 , V_132 , V_197 , V_200 ) ;
F_66 ( V_99 , 0 , V_199 | V_28 | ( V_132 << 12 ) ) ;
F_3 ( 1 , V_22 + V_202 ) ;
if ( V_198 ) {
V_3 = F_30 ( V_14 , V_22 + V_202 ,
0x1 , 0x1 , 1 , V_198 ) ;
if ( V_3 & 0x1 ) {
F_68 ( V_14 ) ;
return - V_45 ;
}
} else
F_2 ( V_22 + V_202 ) ;
return 0 ;
}
int F_72 ( struct V_92 * V_93 , unsigned int * V_203 ,
int V_132 , unsigned long V_204 ,
int (* F_73)( struct V_92 * V_93 ) )
{
struct V_13 * V_14 = V_93 -> V_14 ;
struct V_15 * V_16 = V_14 -> V_17 -> V_18 ;
struct V_98 * V_99 = V_14 -> V_18 ;
const char * V_205 = NULL ;
unsigned long V_206 , V_207 ;
struct V_174 V_175 ;
bool V_208 = false ;
int V_129 ;
F_74 ( L_33 ) ;
V_129 = F_68 ( V_14 ) ;
if ( V_129 && V_129 != - V_195 )
F_75 ( V_93 , L_34 , V_129 ) ;
if ( ! F_76 ( V_93 ) && V_99 -> V_209 ) {
F_77 ( V_14 ) ;
V_208 = true ;
}
F_78 ( V_93 -> V_6 , & V_175 ) ;
V_207 = 0 ;
V_206 = V_144 ;
if ( F_79 ( V_204 , V_206 ) )
V_207 = F_80 ( V_204 - V_206 ) ;
V_175 . V_210 |= V_211 ;
if ( F_70 ( V_14 , V_132 , & V_175 , 0 ,
V_212 | V_213 , V_207 ) ) {
V_129 = - V_97 ;
V_205 = L_35 ;
goto V_214;
}
F_36 ( V_14 , 1 ) ;
V_175 . V_210 &= ~ V_211 ;
F_70 ( V_14 , V_132 , & V_175 , 0 , 0 , 0 ) ;
V_129 = F_81 ( V_93 , V_204 , F_73 ) ;
if ( V_129 == - V_45 && V_16 -> V_28 & V_215 ) {
F_82 ( V_93 , L_36 ) ;
* V_203 = V_216 ;
} else if ( V_129 ) {
V_205 = L_37 ;
goto V_214;
} else
* V_203 = F_64 ( V_14 ) ;
if ( V_208 )
F_83 ( V_14 ) ;
F_74 ( L_38 , * V_203 ) ;
return 0 ;
V_214:
F_84 ( V_93 , L_39 , V_205 ) ;
return V_129 ;
}
int F_85 ( struct V_92 * V_93 )
{
void T_1 * V_22 = F_12 ( V_93 -> V_14 ) ;
T_6 V_186 = F_2 ( V_22 + V_189 ) & 0xFF ;
return F_86 ( V_186 ) ;
}
static int F_87 ( struct V_92 * V_93 , unsigned int * V_203 ,
unsigned long V_204 )
{
int V_132 = F_88 ( V_93 ) ;
F_74 ( L_33 ) ;
return F_72 ( V_93 , V_203 , V_132 , V_204 , F_85 ) ;
}
static int F_89 ( struct V_92 * V_93 )
{
void T_1 * V_22 = F_12 ( V_93 -> V_14 ) ;
T_6 V_186 = F_2 ( V_22 + V_189 ) & 0xFF ;
T_2 V_217 = F_2 ( V_22 + V_167 ) ;
if ( V_217 & V_218 )
return - V_97 ;
return F_86 ( V_186 ) ;
}
static int F_90 ( struct V_92 * V_93 , unsigned int * V_203 ,
unsigned long V_204 )
{
struct V_13 * V_14 = V_93 -> V_14 ;
void T_1 * V_22 = F_12 ( V_14 ) ;
int V_132 = F_88 ( V_93 ) ;
int V_129 ;
T_2 V_219 ;
F_74 ( L_33 ) ;
V_129 = F_72 ( V_93 , V_203 , V_132 , V_204 ,
F_89 ) ;
if ( V_129 == - V_97 ) {
V_219 = F_2 ( V_22 + V_167 ) ;
if ( V_219 & V_218 ) {
F_75 ( V_93 ,
L_40
L_41 ) ;
V_129 = F_72 ( V_93 , V_203 , 0 , V_204 ,
F_85 ) ;
}
}
return V_129 ;
}
static int F_91 ( struct V_92 * V_93 , unsigned int * V_203 ,
unsigned long V_204 )
{
const unsigned long * V_220 = F_92 ( & V_93 -> V_221 ) ;
struct V_13 * V_14 = V_93 -> V_14 ;
struct V_98 * V_99 = V_14 -> V_18 ;
struct V_15 * V_16 = V_14 -> V_17 -> V_18 ;
T_6 * V_222 = V_99 -> V_223 + V_224 ;
struct V_174 V_175 ;
bool V_225 ;
int V_129 ;
F_74 ( L_33 ) ;
F_29 ( V_14 ) ;
F_78 ( V_93 -> V_6 , & V_175 ) ;
V_175 . V_226 = V_192 ;
F_71 ( & V_175 , 0 , 0 , V_222 ) ;
V_129 = F_93 ( V_93 , V_220 , V_204 , & V_225 ,
F_85 ) ;
V_16 -> V_77 ( V_14 ) ;
if ( V_225 )
* V_203 = F_64 ( V_14 ) ;
F_74 ( L_42 , V_129 , * V_203 ) ;
return V_129 ;
}
static void F_94 ( struct V_92 * V_93 , unsigned int * V_203 )
{
struct V_13 * V_14 = V_93 -> V_14 ;
void T_1 * V_22 = F_12 ( V_14 ) ;
T_2 V_227 , V_3 ;
F_95 ( V_93 , V_203 ) ;
V_227 = V_3 = F_2 ( V_22 + V_23 ) ;
if ( * V_203 == V_228 )
V_227 |= V_229 ;
else
V_227 &= ~ V_229 ;
if ( V_227 != V_3 ) {
F_3 ( V_227 , V_22 + V_23 ) ;
F_2 ( V_22 + V_23 ) ;
}
}
static unsigned int F_96 ( struct V_230 * V_231 , void * V_201 )
{
struct V_232 * V_233 ;
struct V_234 * V_234 = V_201 + V_235 ;
unsigned int V_236 ;
F_59 ( L_33 ) ;
F_97 (qc->sg, sg, qc->n_elem, si) {
T_5 V_237 = F_98 ( V_233 ) ;
T_2 V_238 = F_99 ( V_233 ) ;
V_234 [ V_236 ] . V_237 = F_67 ( V_237 & 0xffffffff ) ;
V_234 [ V_236 ] . V_239 = F_67 ( ( V_237 >> 16 ) >> 16 ) ;
V_234 [ V_236 ] . V_240 = F_67 ( V_238 - 1 ) ;
}
return V_236 ;
}
static int F_100 ( struct V_230 * V_231 )
{
struct V_13 * V_14 = V_231 -> V_14 ;
struct V_98 * V_99 = V_14 -> V_18 ;
if ( ! F_69 ( V_14 ) || V_99 -> V_209 )
return F_101 ( V_231 ) ;
else
return F_102 ( V_231 ) ;
}
static void F_103 ( struct V_230 * V_231 )
{
struct V_13 * V_14 = V_231 -> V_14 ;
struct V_98 * V_99 = V_14 -> V_18 ;
int V_241 = F_104 ( V_231 -> V_175 . V_242 ) ;
void * V_201 ;
T_2 V_182 ;
const T_2 V_199 = 5 ;
unsigned int V_243 ;
V_201 = V_99 -> V_201 + V_231 -> V_181 * V_184 ;
F_71 ( & V_231 -> V_175 , V_231 -> V_7 -> V_93 -> V_132 , 1 , V_201 ) ;
if ( V_241 ) {
memset ( V_201 + V_244 , 0 , 32 ) ;
memcpy ( V_201 + V_244 , V_231 -> V_245 , V_231 -> V_7 -> V_246 ) ;
}
V_243 = 0 ;
if ( V_231 -> V_28 & V_247 )
V_243 = F_96 ( V_231 , V_201 ) ;
V_182 = V_199 | V_243 << 16 | ( V_231 -> V_7 -> V_93 -> V_132 << 12 ) ;
if ( V_231 -> V_175 . V_28 & V_248 )
V_182 |= V_249 ;
if ( V_241 )
V_182 |= V_250 | V_251 ;
F_66 ( V_99 , V_231 -> V_181 , V_182 ) ;
}
static void F_105 ( struct V_13 * V_14 )
{
struct V_98 * V_99 = V_14 -> V_18 ;
void T_1 * V_22 = F_12 ( V_14 ) ;
T_2 V_252 = F_2 ( V_22 + V_253 ) ;
int V_254 = 3 ;
F_74 ( L_33 ) ;
F_106 ( ! V_99 -> V_209 ) ;
F_3 ( V_252 | V_255 , V_22 + V_253 ) ;
V_252 = F_2 ( V_22 + V_253 ) ;
while ( ( V_252 & V_255 ) && V_254 -- ) {
F_107 ( 1 ) ;
V_252 = F_2 ( V_22 + V_253 ) ;
}
if ( V_252 & V_255 )
F_44 ( V_14 -> V_17 -> V_7 , L_43 ) ;
}
static void F_108 ( struct V_13 * V_14 , T_2 V_256 )
{
struct V_15 * V_16 = V_14 -> V_17 -> V_18 ;
struct V_98 * V_99 = V_14 -> V_18 ;
struct V_257 * V_258 = & V_14 -> V_93 . V_259 ;
struct V_92 * V_93 = NULL ;
struct V_230 * V_260 ;
struct V_257 * V_261 ;
bool V_262 = false ;
T_2 V_263 ;
if ( V_99 -> V_209 ) {
void T_1 * V_22 = F_12 ( V_14 ) ;
T_2 V_252 = F_2 ( V_22 + V_253 ) ;
int V_132 = V_252 >> V_264 ;
if ( ( V_252 & V_265 ) && ( V_132 < V_14 -> V_266 ) ) {
V_93 = & V_14 -> V_267 [ V_132 ] ;
V_262 = true ;
}
} else
F_40 (link, ap, EDGE)
if ( F_109 ( V_93 ) )
break;
if ( ! V_93 )
V_93 = & V_14 -> V_93 ;
V_260 = F_110 ( V_14 , V_93 -> V_268 ) ;
V_261 = & V_93 -> V_259 ;
F_111 ( V_258 ) ;
F_112 ( V_258 , L_44 , V_256 ) ;
F_27 ( & V_14 -> V_93 , V_86 , & V_263 ) ;
F_28 ( & V_14 -> V_93 , V_86 , V_263 ) ;
V_258 -> V_263 |= V_263 ;
if ( V_16 -> V_28 & V_269 )
V_256 &= ~ V_270 ;
if ( V_256 & V_271 ) {
if ( V_260 )
V_260 -> V_272 |= V_273 ;
else
V_261 -> V_272 |= V_273 ;
if ( V_16 -> V_28 & V_274 )
V_258 -> V_263 &= ~ V_275 ;
}
if ( V_256 & V_276 ) {
T_2 * V_277 = V_99 -> V_223 + V_278 ;
V_261 -> V_272 |= V_279 ;
V_261 -> V_280 |= V_281 ;
F_112 ( V_261 ,
L_45 ,
V_277 [ 0 ] , V_277 [ 1 ] , V_277 [ 2 ] , V_277 [ 3 ] ) ;
}
if ( F_69 ( V_14 ) && ( V_256 & V_218 ) ) {
V_261 -> V_272 |= V_279 ;
V_261 -> V_280 |= V_281 ;
F_112 ( V_261 , L_46 ) ;
}
if ( V_256 & ( V_282 | V_283 ) ) {
V_258 -> V_272 |= V_284 ;
V_258 -> V_280 |= V_281 ;
F_112 ( V_258 , L_47 ) ;
}
if ( V_256 & V_270 ) {
if ( V_262 )
V_261 -> V_272 |= V_273 ;
else {
V_258 -> V_272 |= V_285 ;
V_258 -> V_280 |= V_281 ;
}
F_112 ( V_258 , L_48 ) ;
}
if ( V_256 & ( V_286 | V_118 ) ) {
F_113 ( V_258 ) ;
F_112 ( V_258 , L_49 ,
V_256 & V_286 ?
L_50 : L_51 ) ;
}
if ( V_256 & V_287 )
F_114 ( V_14 ) ;
else if ( V_262 ) {
F_115 ( V_93 ) ;
F_105 ( V_14 ) ;
} else
F_116 ( V_14 ) ;
}
static void F_117 ( struct V_13 * V_14 ,
void T_1 * V_22 , T_2 V_186 )
{
struct V_257 * V_288 = & V_14 -> V_93 . V_259 ;
struct V_98 * V_99 = V_14 -> V_18 ;
struct V_15 * V_16 = V_14 -> V_17 -> V_18 ;
int V_289 = ! ! ( V_14 -> V_290 & V_291 ) ;
T_2 V_292 = 0 ;
int V_129 ;
if ( F_118 ( V_289 ) )
V_186 &= ~ V_218 ;
if ( V_14 -> V_93 . V_293 > V_116 ) {
V_186 &= ~ V_118 ;
F_28 ( & V_14 -> V_93 , V_86 , V_294 ) ;
}
if ( F_118 ( V_186 & V_295 ) ) {
F_108 ( V_14 , V_186 ) ;
return;
}
if ( V_186 & V_296 ) {
if ( V_16 -> V_19 & V_67 )
F_119 ( V_14 ) ;
else {
if ( V_99 -> V_209 )
F_120 ( 1 ) ;
else {
const T_8 * V_297 = V_99 -> V_223 + V_298 ;
T_2 V_299 = F_121 ( V_297 [ 0 ] ) ;
if ( V_299 & ( 1 << 15 ) )
F_119 ( V_14 ) ;
}
}
}
if ( V_99 -> V_209 ) {
if ( V_14 -> V_292 ) {
V_292 = F_2 ( V_22 + V_89 ) ;
V_292 |= F_2 ( V_22 + V_202 ) ;
}
} else {
if ( V_14 -> V_292 && V_99 -> V_300 -> V_301 )
V_292 = F_2 ( V_22 + V_89 ) ;
else
V_292 = F_2 ( V_22 + V_202 ) ;
}
V_129 = F_122 ( V_14 , V_292 ) ;
if ( F_118 ( V_129 < 0 && ! V_289 ) ) {
V_288 -> V_272 |= V_279 ;
V_288 -> V_280 |= V_281 ;
F_114 ( V_14 ) ;
}
}
static void F_123 ( struct V_13 * V_14 )
{
void T_1 * V_22 = F_12 ( V_14 ) ;
T_2 V_186 ;
V_186 = F_2 ( V_22 + V_167 ) ;
F_3 ( V_186 , V_22 + V_167 ) ;
F_117 ( V_14 , V_22 , V_186 ) ;
}
T_9 F_124 ( int V_302 , void * V_303 )
{
struct V_13 * V_14 = V_303 ;
struct V_98 * V_99 = V_14 -> V_18 ;
void T_1 * V_22 = F_12 ( V_14 ) ;
unsigned long V_28 ;
T_2 V_186 ;
F_14 ( & V_14 -> V_17 -> V_30 , V_28 ) ;
V_186 = V_99 -> V_304 ;
if ( V_186 )
V_99 -> V_304 = 0 ;
F_15 ( & V_14 -> V_17 -> V_30 , V_28 ) ;
F_125 ( V_14 -> V_30 ) ;
F_117 ( V_14 , V_22 , V_186 ) ;
F_126 ( V_14 -> V_30 ) ;
return V_305 ;
}
static void F_127 ( struct V_13 * V_14 )
{
void T_1 * V_22 = F_12 ( V_14 ) ;
struct V_98 * V_99 = V_14 -> V_18 ;
T_2 V_186 ;
V_186 = F_2 ( V_22 + V_167 ) ;
F_3 ( V_186 , V_22 + V_167 ) ;
V_99 -> V_304 |= V_186 ;
}
T_9 F_128 ( int V_302 , void * V_303 )
{
struct V_13 * V_306 = V_303 ;
struct V_98 * V_99 = V_306 -> V_18 ;
struct V_79 * V_17 = V_306 -> V_17 ;
struct V_15 * V_16 = V_17 -> V_18 ;
void T_1 * V_1 = V_16 -> V_1 ;
unsigned int V_2 ;
T_2 V_256 , V_307 ;
F_59 ( L_33 ) ;
F_129 ( & V_17 -> V_30 ) ;
V_256 = F_2 ( V_1 + V_168 ) ;
if ( ! V_256 ) {
T_2 V_186 = V_99 -> V_304 ;
F_130 ( & V_17 -> V_30 ) ;
F_59 ( L_52 ) ;
return V_186 ? V_308 : V_309 ;
}
V_307 = V_256 & V_16 -> V_53 ;
for ( V_2 = 0 ; V_2 < V_17 -> V_169 ; V_2 ++ ) {
struct V_13 * V_14 ;
if ( ! ( V_307 & ( 1 << V_2 ) ) )
continue;
V_14 = V_17 -> V_170 [ V_2 ] ;
if ( V_14 ) {
F_127 ( V_14 ) ;
F_59 ( L_53 , V_2 ) ;
} else {
F_59 ( L_54 , V_2 ) ;
if ( F_131 () )
F_22 ( V_17 -> V_7 ,
L_55 , V_2 ) ;
}
}
F_3 ( V_256 , V_1 + V_168 ) ;
F_130 ( & V_17 -> V_30 ) ;
F_59 ( L_52 ) ;
return V_308 ;
}
T_9 F_132 ( int V_302 , void * V_303 )
{
struct V_79 * V_17 = V_303 ;
struct V_15 * V_16 ;
unsigned int V_2 , V_310 = 0 ;
void T_1 * V_1 ;
T_2 V_256 , V_307 ;
F_59 ( L_33 ) ;
V_16 = V_17 -> V_18 ;
V_1 = V_16 -> V_1 ;
V_256 = F_2 ( V_1 + V_168 ) ;
if ( ! V_256 )
return V_309 ;
V_307 = V_256 & V_16 -> V_53 ;
F_129 ( & V_17 -> V_30 ) ;
for ( V_2 = 0 ; V_2 < V_17 -> V_169 ; V_2 ++ ) {
struct V_13 * V_14 ;
if ( ! ( V_307 & ( 1 << V_2 ) ) )
continue;
V_14 = V_17 -> V_170 [ V_2 ] ;
if ( V_14 ) {
F_123 ( V_14 ) ;
F_59 ( L_53 , V_2 ) ;
} else {
F_59 ( L_54 , V_2 ) ;
if ( F_131 () )
F_22 ( V_17 -> V_7 ,
L_55 , V_2 ) ;
}
V_310 = 1 ;
}
F_3 ( V_256 , V_1 + V_168 ) ;
F_130 ( & V_17 -> V_30 ) ;
F_59 ( L_52 ) ;
return F_133 ( V_310 ) ;
}
unsigned int F_134 ( struct V_230 * V_231 )
{
struct V_13 * V_14 = V_231 -> V_14 ;
void T_1 * V_22 = F_12 ( V_14 ) ;
struct V_98 * V_99 = V_14 -> V_18 ;
V_99 -> V_300 = V_231 -> V_7 -> V_93 ;
if ( V_231 -> V_175 . V_242 == V_311 )
F_3 ( 1 << V_231 -> V_181 , V_22 + V_89 ) ;
if ( V_99 -> V_209 && V_99 -> V_312 != V_231 -> V_7 -> V_93 -> V_132 ) {
T_2 V_252 = F_2 ( V_22 + V_253 ) ;
V_252 &= ~ ( V_313 | V_255 ) ;
V_252 |= V_231 -> V_7 -> V_93 -> V_132 << V_314 ;
F_3 ( V_252 , V_22 + V_253 ) ;
V_99 -> V_312 = V_231 -> V_7 -> V_93 -> V_132 ;
}
F_3 ( 1 << V_231 -> V_181 , V_22 + V_202 ) ;
F_45 ( V_231 -> V_7 -> V_93 ) ;
return 0 ;
}
static bool F_135 ( struct V_230 * V_231 )
{
struct V_98 * V_99 = V_231 -> V_14 -> V_18 ;
T_6 * V_223 = V_99 -> V_223 ;
if ( V_99 -> V_209 )
V_223 += V_231 -> V_7 -> V_93 -> V_132 * V_315 ;
if ( V_231 -> V_175 . V_242 == V_316 && V_231 -> V_317 == V_318 &&
! ( V_231 -> V_28 & V_319 ) ) {
F_136 ( V_223 + V_320 , & V_231 -> V_321 ) ;
V_231 -> V_321 . V_226 = ( V_223 + V_320 ) [ 15 ] ;
} else
F_136 ( V_223 + V_224 , & V_231 -> V_321 ) ;
return true ;
}
static void F_137 ( struct V_13 * V_14 )
{
void T_1 * V_22 = F_12 ( V_14 ) ;
F_3 ( 0 , V_22 + V_119 ) ;
}
static void F_138 ( struct V_13 * V_14 )
{
struct V_15 * V_16 = V_14 -> V_17 -> V_18 ;
void T_1 * V_1 = V_16 -> V_1 ;
void T_1 * V_22 = F_12 ( V_14 ) ;
T_2 V_3 ;
struct V_98 * V_99 = V_14 -> V_18 ;
V_3 = F_2 ( V_22 + V_167 ) ;
F_3 ( V_3 , V_22 + V_167 ) ;
F_3 ( 1 << V_14 -> V_149 , V_1 + V_168 ) ;
F_3 ( V_99 -> V_117 , V_22 + V_119 ) ;
}
void F_139 ( struct V_13 * V_14 )
{
struct V_15 * V_16 = V_14 -> V_17 -> V_18 ;
if ( ! ( V_14 -> V_290 & V_322 ) ) {
F_29 ( V_14 ) ;
V_16 -> V_77 ( V_14 ) ;
}
F_140 ( V_14 ) ;
if ( ! F_141 ( V_14 -> V_93 . V_6 ) )
F_29 ( V_14 ) ;
}
static void F_142 ( struct V_230 * V_231 )
{
struct V_13 * V_14 = V_231 -> V_14 ;
if ( V_231 -> V_28 & V_319 )
F_68 ( V_14 ) ;
}
static void F_37 ( struct V_13 * V_14 , bool V_323 )
{
struct V_15 * V_16 = V_14 -> V_17 -> V_18 ;
void T_1 * V_22 = F_12 ( V_14 ) ;
struct V_162 * V_7 = V_14 -> V_93 . V_6 ;
T_2 V_324 , V_325 , V_326 , V_327 , V_328 ;
int V_129 ;
unsigned int V_272 ;
V_324 = F_2 ( V_22 + V_329 ) ;
if ( ! ( V_324 & V_330 ) ) {
F_44 ( V_14 -> V_17 -> V_7 , L_56 ) ;
return;
}
if ( ! V_323 ) {
if ( V_324 & V_331 ) {
F_3 ( V_324 & ~ V_331 ,
V_22 + V_329 ) ;
V_272 = F_143 ( V_7 ,
V_332 ,
V_333 ) ;
if ( V_272 && V_272 != V_273 )
F_144 ( V_7 , L_57 ) ;
}
return;
}
if ( V_324 & V_331 )
return;
V_129 = F_29 ( V_14 ) ;
if ( V_129 )
return;
V_325 = ( V_324 & V_334 ) >> V_335 ;
V_326 = V_336 / ( V_325 + 1 ) ;
if ( V_326 > 0x3ff )
V_326 = 0x3ff ;
if ( V_7 -> V_337 [ V_338 ] &
V_339 ) {
V_327 = V_7 -> V_337 [ V_340 ] &
V_341 ;
if ( ! V_327 )
V_327 = 10 ;
V_328 = V_7 -> V_337 [ V_342 ] ;
if ( ! V_328 )
V_328 = 20 ;
} else {
V_327 = 10 ;
V_328 = 20 ;
}
V_324 |= ( ( V_326 << V_343 ) |
( V_327 << V_344 ) |
( V_328 << V_345 ) |
V_331 ) ;
F_3 ( V_324 , V_22 + V_329 ) ;
V_16 -> V_77 ( V_14 ) ;
V_272 = F_143 ( V_7 ,
V_346 ,
V_333 ) ;
if ( V_272 && V_272 != V_273 )
F_144 ( V_7 , L_58 ) ;
}
static void F_83 ( struct V_13 * V_14 )
{
struct V_15 * V_16 = V_14 -> V_17 -> V_18 ;
struct V_98 * V_99 = V_14 -> V_18 ;
void T_1 * V_22 = F_12 ( V_14 ) ;
T_2 V_252 ;
int V_129 ;
if ( ! V_99 -> V_347 )
return;
V_252 = F_2 ( V_22 + V_253 ) ;
if ( V_252 & V_348 ) {
V_99 -> V_209 = true ;
V_99 -> V_312 = - 1 ;
return;
}
V_129 = F_29 ( V_14 ) ;
if ( V_129 )
return;
F_3 ( V_252 | V_348 , V_22 + V_253 ) ;
V_252 = F_2 ( V_22 + V_253 ) ;
if ( V_252 & V_348 ) {
F_21 ( V_14 -> V_17 -> V_7 , L_59 ) ;
V_99 -> V_209 = true ;
V_99 -> V_312 = - 1 ;
} else
F_44 ( V_14 -> V_17 -> V_7 , L_60 ) ;
V_16 -> V_77 ( V_14 ) ;
}
static void F_77 ( struct V_13 * V_14 )
{
struct V_15 * V_16 = V_14 -> V_17 -> V_18 ;
struct V_98 * V_99 = V_14 -> V_18 ;
void T_1 * V_22 = F_12 ( V_14 ) ;
T_2 V_252 ;
int V_129 ;
if ( ! V_99 -> V_347 )
return;
V_252 = F_2 ( V_22 + V_253 ) ;
if ( ( V_252 & V_348 ) == 0 ) {
V_99 -> V_209 = false ;
return;
}
V_129 = F_29 ( V_14 ) ;
if ( V_129 )
return;
F_3 ( V_252 & ~ V_348 , V_22 + V_253 ) ;
V_252 = F_2 ( V_22 + V_253 ) ;
if ( V_252 & V_348 )
F_44 ( V_14 -> V_17 -> V_7 , L_61 ) ;
else {
F_21 ( V_14 -> V_17 -> V_7 , L_62 ) ;
V_99 -> V_209 = false ;
}
V_16 -> V_77 ( V_14 ) ;
}
static void F_145 ( struct V_13 * V_14 )
{
void T_1 * V_22 = F_12 ( V_14 ) ;
struct V_98 * V_99 = V_14 -> V_18 ;
T_2 V_108 ;
V_108 = F_2 ( V_22 + V_23 ) ;
V_108 |= V_349 ;
F_3 ( V_108 , V_22 + V_23 ) ;
F_83 ( V_14 ) ;
V_99 -> V_117 |= V_218 ;
if ( ! ( V_14 -> V_290 & V_322 ) )
F_3 ( V_99 -> V_117 , V_22 + V_119 ) ;
}
static void F_146 ( struct V_13 * V_14 )
{
void T_1 * V_22 = F_12 ( V_14 ) ;
struct V_98 * V_99 = V_14 -> V_18 ;
T_2 V_108 ;
F_77 ( V_14 ) ;
V_108 = F_2 ( V_22 + V_23 ) ;
V_108 &= ~ V_349 ;
F_3 ( V_108 , V_22 + V_23 ) ;
V_99 -> V_117 &= ~ V_218 ;
if ( ! ( V_14 -> V_290 & V_322 ) )
F_3 ( V_99 -> V_117 , V_22 + V_119 ) ;
}
int F_147 ( struct V_13 * V_14 )
{
F_33 ( V_14 ) ;
F_39 ( V_14 ) ;
if ( F_69 ( V_14 ) )
F_145 ( V_14 ) ;
else
F_146 ( V_14 ) ;
return 0 ;
}
static int F_148 ( struct V_13 * V_14 , T_10 V_350 )
{
const char * V_138 = NULL ;
int V_129 ;
V_129 = F_42 ( V_14 , & V_138 ) ;
if ( V_129 == 0 )
F_38 ( V_14 ) ;
else {
F_149 ( V_14 , L_28 , V_138 , V_129 ) ;
F_114 ( V_14 ) ;
}
return V_129 ;
}
static int F_150 ( struct V_13 * V_14 )
{
struct V_15 * V_16 = V_14 -> V_17 -> V_18 ;
struct V_6 * V_7 = V_14 -> V_17 -> V_7 ;
struct V_98 * V_99 ;
void * V_351 ;
T_5 V_352 ;
T_4 V_353 , V_354 ;
V_99 = F_151 ( V_7 , sizeof( * V_99 ) , V_355 ) ;
if ( ! V_99 )
return - V_356 ;
if ( V_14 -> V_17 -> V_169 > 1 ) {
V_99 -> V_357 = F_151 ( V_7 , 8 , V_355 ) ;
if ( ! V_99 -> V_357 ) {
F_152 ( V_7 , V_99 ) ;
return - V_356 ;
}
snprintf ( V_99 -> V_357 , 8 ,
L_63 , F_153 ( V_7 ) , V_14 -> V_149 ) ;
}
if ( ( V_16 -> V_19 & V_72 ) && F_154 ( V_14 ) ) {
void T_1 * V_22 = F_12 ( V_14 ) ;
T_2 V_108 = F_2 ( V_22 + V_23 ) ;
if ( V_108 & V_358 )
V_99 -> V_347 = true ;
else if ( V_16 -> V_28 & V_73 ) {
F_21 ( V_7 , L_64 ,
V_14 -> V_149 ) ;
V_99 -> V_347 = true ;
} else
F_22 ( V_7 , L_65 ,
V_14 -> V_149 ) ;
}
if ( V_99 -> V_347 ) {
V_353 = V_359 ;
V_354 = V_315 * 16 ;
} else {
V_353 = V_360 ;
V_354 = V_315 ;
}
V_351 = F_155 ( V_7 , V_353 , & V_352 , V_355 ) ;
if ( ! V_351 )
return - V_356 ;
memset ( V_351 , 0 , V_353 ) ;
V_99 -> V_185 = V_351 ;
V_99 -> V_100 = V_352 ;
V_351 += V_361 ;
V_352 += V_361 ;
V_99 -> V_223 = V_351 ;
V_99 -> V_103 = V_352 ;
V_351 += V_354 ;
V_352 += V_354 ;
V_99 -> V_201 = V_351 ;
V_99 -> V_183 = V_352 ;
V_99 -> V_117 = V_362 ;
if ( ( V_16 -> V_28 & V_363 ) ) {
F_156 ( & V_99 -> V_30 ) ;
V_14 -> V_30 = & V_99 -> V_30 ;
}
V_14 -> V_18 = V_99 ;
return F_147 ( V_14 ) ;
}
static void F_157 ( struct V_13 * V_14 )
{
const char * V_138 = NULL ;
int V_129 ;
V_129 = F_42 ( V_14 , & V_138 ) ;
if ( V_129 )
F_17 ( V_14 , L_28 , V_138 , V_129 ) ;
}
void F_158 ( struct V_79 * V_17 , const char * V_364 )
{
struct V_15 * V_16 = V_17 -> V_18 ;
void T_1 * V_1 = V_16 -> V_1 ;
T_2 V_52 , V_19 , V_20 , V_365 , V_366 ;
const char * V_367 ;
V_52 = F_2 ( V_1 + V_21 ) ;
V_19 = V_16 -> V_19 ;
V_20 = V_16 -> V_20 ;
V_365 = V_16 -> V_53 ;
V_366 = ( V_19 >> 20 ) & 0xf ;
if ( V_366 == 1 )
V_367 = L_66 ;
else if ( V_366 == 2 )
V_367 = L_67 ;
else if ( V_366 == 3 )
V_367 = L_68 ;
else
V_367 = L_69 ;
F_21 ( V_17 -> V_7 ,
L_70
L_71
,
( V_52 >> 24 ) & 0xff ,
( V_52 >> 16 ) & 0xff ,
( V_52 >> 8 ) & 0xff ,
V_52 & 0xff ,
( ( V_19 >> 8 ) & 0x1f ) + 1 ,
( V_19 & 0x1f ) + 1 ,
V_367 ,
V_365 ,
V_364 ) ;
F_21 ( V_17 -> V_7 ,
L_72
L_73
L_73
L_73
L_74
,
V_19 & V_60 ? L_75 : L_6 ,
V_19 & V_62 ? L_76 : L_6 ,
V_19 & V_67 ? L_77 : L_6 ,
V_19 & V_368 ? L_78 : L_6 ,
V_19 & V_110 ? L_79 : L_6 ,
V_19 & V_120 ? L_80 : L_6 ,
V_19 & V_369 ? L_5 : L_6 ,
V_19 & V_194 ? L_81 : L_6 ,
V_19 & V_370 ? L_82 : L_6 ,
V_19 & V_65 ? L_83 : L_6 ,
V_19 & V_72 ? L_84 : L_6 ,
V_19 & V_371 ? L_85 : L_6 ,
V_19 & V_372 ? L_86 : L_6 ,
V_19 & V_373 ? L_87 : L_6 ,
V_19 & V_374 ? L_88 : L_6 ,
V_19 & V_375 ? L_89 : L_6 ,
V_19 & V_376 ? L_90 : L_6 ,
V_20 & V_377 ? L_91 : L_6 ,
V_20 & V_71 ? L_92 : L_6 ,
V_20 & V_69 ? L_93 : L_6 ,
V_20 & V_378 ? L_94 : L_6 ,
V_20 & V_379 ? L_95 : L_6 ,
V_20 & V_380 ? L_96 : L_6
) ;
}
void F_159 ( struct V_15 * V_16 ,
struct V_381 * V_382 )
{
T_6 V_383 ;
void T_1 * V_1 = V_16 -> V_1 ;
T_2 V_25 = F_2 ( V_1 + V_384 ) ;
T_2 V_26 = F_2 ( V_1 + V_31 ) ;
if ( ! V_385 || ! ( V_16 -> V_19 & V_375 ) )
return;
V_383 = ( V_26 & V_386 ) >> 16 ;
if ( V_383 ) {
V_16 -> V_25 = ( ( V_25 >> 16 ) * 4 ) ;
V_16 -> V_40 = ( ( V_25 & 0xff ) * 4 ) ;
V_16 -> V_34 = V_383 ;
V_382 -> V_28 |= V_32 ;
if ( ! ( V_26 & V_387 ) )
V_382 -> V_28 |= V_137 ;
}
}
