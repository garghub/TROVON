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
if ( V_50 && V_53 != V_50 ) {
F_21 ( V_7 , L_17 ,
V_53 , V_50 ) ;
V_53 = V_50 ;
}
if ( V_51 ) {
F_22 ( V_7 , L_18 ,
V_53 ,
V_53 & V_51 ) ;
V_53 &= V_51 ;
}
if ( V_53 ) {
int V_74 = 0 ;
for ( V_2 = 0 ; V_2 < V_75 ; V_2 ++ )
if ( V_53 & ( 1 << V_2 ) )
V_74 ++ ;
if ( V_74 > F_23 ( V_19 ) ) {
F_22 ( V_7 ,
L_19 ,
V_53 , F_23 ( V_19 ) ) ;
V_53 = 0 ;
}
}
if ( ! V_53 ) {
V_53 = ( 1 << F_23 ( V_19 ) ) - 1 ;
F_22 ( V_7 , L_20 , V_53 ) ;
V_16 -> V_56 = V_53 ;
}
V_16 -> V_19 = V_19 ;
V_16 -> V_20 = V_20 ;
V_16 -> V_53 = V_53 ;
if ( ! V_16 -> V_76 )
V_16 -> V_76 = V_77 ;
}
static void F_24 ( struct V_78 * V_17 )
{
struct V_15 * V_16 = V_17 -> V_18 ;
void T_1 * V_1 = V_16 -> V_1 ;
F_3 ( V_16 -> V_54 , V_1 + V_55 ) ;
if ( V_16 -> V_58 )
F_3 ( V_16 -> V_58 , V_1 + V_59 ) ;
F_3 ( V_16 -> V_56 , V_1 + V_57 ) ;
( void ) F_2 ( V_1 + V_57 ) ;
}
static unsigned F_25 ( struct V_13 * V_14 , unsigned int V_79 )
{
static const int V_80 [] = {
[ V_81 ] = V_82 ,
[ V_83 ] = V_84 ,
[ V_85 ] = V_86 ,
[ V_87 ] = V_88 ,
[ V_89 ] = V_90 ,
} ;
struct V_15 * V_16 = V_14 -> V_17 -> V_18 ;
if ( V_79 < F_26 ( V_80 ) &&
( V_79 != V_89 || ( V_16 -> V_19 & V_67 ) ) )
return V_80 [ V_79 ] ;
return 0 ;
}
static int F_27 ( struct V_91 * V_92 , unsigned int V_79 , T_2 * V_93 )
{
void T_1 * V_22 = F_12 ( V_92 -> V_14 ) ;
int V_80 = F_25 ( V_92 -> V_14 , V_79 ) ;
if ( V_80 ) {
* V_93 = F_2 ( V_22 + V_80 ) ;
return 0 ;
}
return - V_36 ;
}
static int F_28 ( struct V_91 * V_92 , unsigned int V_79 , T_2 V_93 )
{
void T_1 * V_22 = F_12 ( V_92 -> V_14 ) ;
int V_80 = F_25 ( V_92 -> V_14 , V_79 ) ;
if ( V_80 ) {
F_3 ( V_93 , V_22 + V_80 ) ;
return 0 ;
}
return - V_36 ;
}
void V_77 ( struct V_13 * V_14 )
{
void T_1 * V_22 = F_12 ( V_14 ) ;
T_2 V_3 ;
V_3 = F_2 ( V_22 + V_23 ) ;
V_3 |= V_94 ;
F_3 ( V_3 , V_22 + V_23 ) ;
F_2 ( V_22 + V_23 ) ;
}
int F_29 ( struct V_13 * V_14 )
{
void T_1 * V_22 = F_12 ( V_14 ) ;
T_2 V_3 ;
V_3 = F_2 ( V_22 + V_23 ) ;
if ( ( V_3 & ( V_94 | V_95 ) ) == 0 )
return 0 ;
V_3 &= ~ V_94 ;
F_3 ( V_3 , V_22 + V_23 ) ;
V_3 = F_30 ( V_14 , V_22 + V_23 ,
V_95 , V_95 , 1 , 500 ) ;
if ( V_3 & V_95 )
return - V_96 ;
return 0 ;
}
static void F_31 ( struct V_13 * V_14 )
{
void T_1 * V_22 = F_12 ( V_14 ) ;
struct V_15 * V_16 = V_14 -> V_17 -> V_18 ;
struct V_97 * V_98 = V_14 -> V_18 ;
T_2 V_3 ;
if ( V_16 -> V_19 & V_60 )
F_3 ( ( V_98 -> V_99 >> 16 ) >> 16 ,
V_22 + V_100 ) ;
F_3 ( V_98 -> V_99 & 0xffffffff , V_22 + V_101 ) ;
if ( V_16 -> V_19 & V_60 )
F_3 ( ( V_98 -> V_102 >> 16 ) >> 16 ,
V_22 + V_103 ) ;
F_3 ( V_98 -> V_102 & 0xffffffff , V_22 + V_104 ) ;
V_3 = F_2 ( V_22 + V_23 ) ;
V_3 |= V_105 ;
F_3 ( V_3 , V_22 + V_23 ) ;
F_2 ( V_22 + V_23 ) ;
}
static int F_32 ( struct V_13 * V_14 )
{
void T_1 * V_22 = F_12 ( V_14 ) ;
T_2 V_3 ;
V_3 = F_2 ( V_22 + V_23 ) ;
V_3 &= ~ V_105 ;
F_3 ( V_3 , V_22 + V_23 ) ;
V_3 = F_30 ( V_14 , V_22 + V_23 , V_106 ,
V_106 , 10 , 1000 ) ;
if ( V_3 & V_106 )
return - V_45 ;
return 0 ;
}
static void F_33 ( struct V_13 * V_14 )
{
struct V_15 * V_16 = V_14 -> V_17 -> V_18 ;
void T_1 * V_22 = F_12 ( V_14 ) ;
T_2 V_107 ;
V_107 = F_2 ( V_22 + V_23 ) & ~ V_108 ;
if ( V_16 -> V_19 & V_109 ) {
V_107 |= V_110 ;
F_3 ( V_107 , V_22 + V_23 ) ;
}
F_3 ( V_107 | V_111 , V_22 + V_23 ) ;
}
static int F_34 ( struct V_91 * V_92 , enum V_112 V_113 ,
unsigned int V_114 )
{
struct V_13 * V_14 = V_92 -> V_14 ;
struct V_15 * V_16 = V_14 -> V_17 -> V_18 ;
struct V_97 * V_98 = V_14 -> V_18 ;
void T_1 * V_22 = F_12 ( V_14 ) ;
if ( V_113 != V_115 ) {
V_98 -> V_116 &= ~ V_117 ;
F_3 ( V_98 -> V_116 , V_22 + V_118 ) ;
F_35 ( V_92 , V_113 , false ) ;
}
if ( V_16 -> V_19 & V_119 ) {
T_2 V_107 = F_2 ( V_22 + V_23 ) ;
if ( V_113 == V_115 || ! ( V_114 & V_120 ) ) {
V_107 &= ~ ( V_121 | V_122 ) ;
V_107 |= V_111 ;
F_3 ( V_107 , V_22 + V_23 ) ;
F_2 ( V_22 + V_23 ) ;
F_36 ( V_14 , 10 ) ;
} else {
V_107 |= V_122 ;
if ( V_113 == V_123 )
V_107 |= V_121 ;
F_3 ( V_107 , V_22 + V_23 ) ;
}
}
if ( ( V_16 -> V_20 & V_69 ) &&
( V_16 -> V_20 & V_71 ) &&
( V_92 -> V_6 -> V_28 & V_124 ) ) {
if ( V_113 == V_123 )
F_37 ( V_14 , true ) ;
else
F_37 ( V_14 , false ) ;
}
if ( V_113 == V_115 ) {
F_35 ( V_92 , V_113 , false ) ;
V_98 -> V_116 |= V_117 ;
F_3 ( V_98 -> V_116 , V_22 + V_118 ) ;
}
return 0 ;
}
static void F_38 ( struct V_13 * V_14 )
{
struct V_15 * V_16 = V_14 -> V_17 -> V_18 ;
void T_1 * V_22 = F_12 ( V_14 ) ;
T_2 V_107 , V_125 ;
if ( ! ( V_16 -> V_19 & V_109 ) )
return;
V_125 = F_2 ( V_22 + V_84 ) ;
V_125 &= ~ 0xf ;
F_3 ( V_125 , V_22 + V_84 ) ;
V_107 = F_2 ( V_22 + V_23 ) & ~ V_108 ;
V_107 &= ~ V_110 ;
F_3 ( V_107 , V_22 + V_23 ) ;
}
static void F_39 ( struct V_13 * V_14 )
{
struct V_15 * V_16 = V_14 -> V_17 -> V_18 ;
struct V_97 * V_98 = V_14 -> V_18 ;
struct V_91 * V_92 ;
struct V_126 * V_127 ;
T_3 V_128 ;
int V_2 ;
F_31 ( V_14 ) ;
if ( ! ( V_16 -> V_28 & V_129 ) )
V_16 -> V_76 ( V_14 ) ;
if ( V_14 -> V_28 & V_32 ) {
F_40 (link, ap, EDGE) {
V_127 = & V_98 -> V_130 [ V_92 -> V_131 ] ;
for ( V_2 = 0 ; V_2 < V_132 ; V_2 ++ ) {
V_128 = V_14 -> V_133 -> V_134 ( V_14 ,
V_127 -> V_135 ,
4 ) ;
if ( V_128 == - V_45 )
F_4 ( 1 ) ;
else
break;
}
}
}
if ( V_14 -> V_28 & V_136 )
F_40 (link, ap, EDGE)
F_41 ( V_92 ) ;
}
static int F_42 ( struct V_13 * V_14 , const char * * V_137 )
{
int V_128 ;
V_128 = F_29 ( V_14 ) ;
if ( V_128 ) {
* V_137 = L_21 ;
return V_128 ;
}
V_128 = F_32 ( V_14 ) ;
if ( V_128 ) {
* V_137 = L_22 ;
return V_128 ;
}
return 0 ;
}
int F_43 ( struct V_78 * V_17 )
{
struct V_15 * V_16 = V_17 -> V_18 ;
void T_1 * V_1 = V_16 -> V_1 ;
T_2 V_3 ;
F_1 ( V_1 ) ;
if ( ! V_138 ) {
V_3 = F_2 ( V_1 + V_4 ) ;
if ( ( V_3 & V_139 ) == 0 ) {
F_3 ( V_3 | V_139 , V_1 + V_4 ) ;
F_2 ( V_1 + V_4 ) ;
}
V_3 = F_30 ( NULL , V_1 + V_4 , V_139 ,
V_139 , 10 , 1000 ) ;
if ( V_3 & V_139 ) {
F_44 ( V_17 -> V_7 , L_23 ,
V_3 ) ;
return - V_96 ;
}
F_1 ( V_1 ) ;
F_24 ( V_17 ) ;
} else
F_21 ( V_17 -> V_7 , L_24 ) ;
return 0 ;
}
static void F_45 ( struct V_91 * V_92 )
{
struct V_13 * V_14 = V_92 -> V_14 ;
struct V_97 * V_98 = V_14 -> V_18 ;
struct V_126 * V_127 = & V_98 -> V_130 [ V_92 -> V_131 ] ;
if ( ! ( V_92 -> V_28 & V_140 ) )
return;
V_127 -> V_141 ++ ;
if ( ! F_46 ( & V_127 -> V_142 ) )
F_47 ( & V_127 -> V_142 , V_143 + F_48 ( 10 ) ) ;
}
static void F_49 ( unsigned long V_144 )
{
struct V_91 * V_92 = (struct V_91 * ) V_144 ;
struct V_13 * V_14 = V_92 -> V_14 ;
struct V_97 * V_98 = V_14 -> V_18 ;
struct V_126 * V_127 = & V_98 -> V_130 [ V_92 -> V_131 ] ;
unsigned long V_145 = V_127 -> V_135 ;
T_2 V_146 ;
unsigned long V_28 ;
V_145 &= V_147 ;
V_145 |= V_14 -> V_148 | ( V_92 -> V_131 << 8 ) ;
F_14 ( V_14 -> V_30 , V_28 ) ;
if ( V_127 -> V_149 != V_127 -> V_141 ) {
V_127 -> V_149 = V_127 -> V_141 ;
V_146 = V_145 & V_150 ;
if ( V_146 )
V_146 = 0 ;
else
V_146 = 1 ;
V_145 &= ~ V_151 ;
V_145 |= ( V_146 << 16 ) ;
F_47 ( & V_127 -> V_142 , V_143 + F_48 ( 100 ) ) ;
} else {
V_145 &= ~ V_151 ;
if ( V_127 -> V_152 == V_153 )
V_145 |= ( 1 << 16 ) ;
}
F_15 ( V_14 -> V_30 , V_28 ) ;
V_14 -> V_133 -> V_134 ( V_14 , V_145 , 4 ) ;
}
static void F_41 ( struct V_91 * V_92 )
{
struct V_13 * V_14 = V_92 -> V_14 ;
struct V_97 * V_98 = V_14 -> V_18 ;
struct V_126 * V_127 = & V_98 -> V_130 [ V_92 -> V_131 ] ;
V_127 -> V_149 = V_127 -> V_141 = 0 ;
F_50 ( & V_127 -> V_142 , F_49 , ( unsigned long ) V_92 ) ;
if ( V_127 -> V_152 )
V_92 -> V_28 |= V_140 ;
}
int F_51 ( struct V_78 * V_17 )
{
struct V_15 * V_16 = V_17 -> V_18 ;
void T_1 * V_1 = V_16 -> V_1 ;
T_2 V_26 ;
V_26 = F_2 ( V_1 + V_31 ) ;
if ( ( V_26 & V_44 ) || ( V_26 & V_154 ) )
return - V_36 ;
F_3 ( V_26 | V_154 , V_1 + V_31 ) ;
return 0 ;
}
static T_3 F_52 ( struct V_13 * V_14 , T_2 V_155 ,
T_3 V_42 )
{
struct V_15 * V_16 = V_14 -> V_17 -> V_18 ;
struct V_97 * V_98 = V_14 -> V_18 ;
void T_1 * V_1 = V_16 -> V_1 ;
T_2 V_26 ;
T_2 V_156 [] = { 0 , 0 } ;
unsigned long V_28 ;
int V_131 ;
struct V_126 * V_127 ;
V_131 = ( V_155 & V_157 ) >> 8 ;
if ( V_131 < V_158 )
V_127 = & V_98 -> V_130 [ V_131 ] ;
else
return - V_36 ;
F_14 ( V_14 -> V_30 , V_28 ) ;
V_26 = F_2 ( V_1 + V_31 ) ;
if ( V_26 & V_44 ) {
F_15 ( V_14 -> V_30 , V_28 ) ;
return - V_45 ;
}
if ( V_16 -> V_34 & V_159 ) {
V_156 [ 0 ] |= ( 4 << 8 ) ;
V_156 [ 1 ] = ( ( V_155 & ~ V_160 ) | V_14 -> V_148 ) ;
F_3 ( V_156 [ 0 ] , V_1 + V_16 -> V_25 ) ;
F_3 ( V_156 [ 1 ] , V_1 + V_16 -> V_25 + 4 ) ;
F_3 ( V_26 | V_44 , V_1 + V_31 ) ;
}
V_127 -> V_135 = V_155 ;
F_15 ( V_14 -> V_30 , V_28 ) ;
return V_42 ;
}
static T_3 F_53 ( struct V_13 * V_14 , char * V_10 )
{
struct V_97 * V_98 = V_14 -> V_18 ;
struct V_91 * V_92 ;
struct V_126 * V_127 ;
int V_128 = 0 ;
F_40 (link, ap, EDGE) {
V_127 = & V_98 -> V_130 [ V_92 -> V_131 ] ;
V_128 += sprintf ( V_10 , L_25 , V_127 -> V_135 ) ;
}
return V_128 ;
}
static T_3 F_54 ( struct V_13 * V_14 , const char * V_10 ,
T_4 V_42 )
{
unsigned int V_155 ;
int V_131 ;
struct V_97 * V_98 = V_14 -> V_18 ;
struct V_126 * V_127 ;
if ( F_55 ( V_10 , 0 , & V_155 ) < 0 )
return - V_36 ;
V_131 = ( V_155 & V_157 ) >> 8 ;
if ( V_131 < V_158 )
V_127 = & V_98 -> V_130 [ V_131 ] ;
else
return - V_36 ;
if ( V_127 -> V_152 )
V_155 &= ~ V_151 ;
return V_14 -> V_133 -> V_134 ( V_14 , V_155 , V_42 ) ;
}
static T_3 F_56 ( struct V_161 * V_7 , enum V_162 V_93 )
{
struct V_91 * V_92 = V_7 -> V_92 ;
struct V_13 * V_14 = V_92 -> V_14 ;
struct V_97 * V_98 = V_14 -> V_18 ;
struct V_126 * V_127 = & V_98 -> V_130 [ V_92 -> V_131 ] ;
T_2 V_163 = V_127 -> V_135 ;
if ( V_93 == V_164 ) {
V_92 -> V_28 &= ~ ( V_140 ) ;
V_163 &= V_165 ;
V_163 |= ( V_14 -> V_148 | ( V_92 -> V_131 << 8 ) ) ;
V_14 -> V_133 -> V_134 ( V_14 , V_163 , 4 ) ;
} else {
V_92 -> V_28 |= V_140 ;
if ( V_93 == V_153 ) {
V_163 &= V_165 ;
V_163 |= ( V_14 -> V_148 | ( V_92 -> V_131 << 8 ) ) ;
V_163 |= V_150 ;
V_14 -> V_133 -> V_134 ( V_14 , V_163 , 4 ) ;
}
}
V_127 -> V_152 = V_93 ;
return 0 ;
}
static T_3 F_57 ( struct V_161 * V_7 , char * V_10 )
{
struct V_91 * V_92 = V_7 -> V_92 ;
struct V_13 * V_14 = V_92 -> V_14 ;
struct V_97 * V_98 = V_14 -> V_18 ;
struct V_126 * V_127 = & V_98 -> V_130 [ V_92 -> V_131 ] ;
return sprintf ( V_10 , L_26 , V_127 -> V_152 ) ;
}
static void F_58 ( struct V_6 * V_7 , struct V_13 * V_14 ,
int V_148 , void T_1 * V_1 ,
void T_1 * V_22 )
{
const char * V_137 = NULL ;
int V_128 ;
T_2 V_3 ;
V_128 = F_42 ( V_14 , & V_137 ) ;
if ( V_128 )
F_22 ( V_7 , L_27 , V_137 , V_128 ) ;
V_3 = F_2 ( V_22 + V_86 ) ;
F_59 ( L_28 , V_3 ) ;
F_3 ( V_3 , V_22 + V_86 ) ;
V_3 = F_2 ( V_22 + V_166 ) ;
F_59 ( L_29 , V_3 ) ;
if ( V_3 )
F_3 ( V_3 , V_22 + V_166 ) ;
F_3 ( 1 << V_148 , V_1 + V_167 ) ;
}
void F_60 ( struct V_78 * V_17 )
{
struct V_15 * V_16 = V_17 -> V_18 ;
void T_1 * V_1 = V_16 -> V_1 ;
int V_2 ;
void T_1 * V_22 ;
T_2 V_3 ;
for ( V_2 = 0 ; V_2 < V_17 -> V_168 ; V_2 ++ ) {
struct V_13 * V_14 = V_17 -> V_169 [ V_2 ] ;
V_22 = F_12 ( V_14 ) ;
if ( F_61 ( V_14 ) )
continue;
F_58 ( V_17 -> V_7 , V_14 , V_2 , V_1 , V_22 ) ;
}
V_3 = F_2 ( V_1 + V_4 ) ;
F_59 ( L_30 , V_3 ) ;
F_3 ( V_3 | V_170 , V_1 + V_4 ) ;
V_3 = F_2 ( V_1 + V_4 ) ;
F_59 ( L_30 , V_3 ) ;
}
static void F_62 ( struct V_161 * V_7 )
{
struct V_15 * V_16 = V_7 -> V_92 -> V_14 -> V_17 -> V_18 ;
if ( V_16 -> V_28 & V_171 ) {
V_7 -> V_172 = 255 ;
F_63 ( V_7 ,
L_31 ) ;
}
}
unsigned int F_64 ( struct V_13 * V_14 )
{
void T_1 * V_22 = F_12 ( V_14 ) ;
struct V_173 V_174 ;
T_2 V_3 ;
V_3 = F_2 ( V_22 + V_175 ) ;
V_174 . V_176 = ( V_3 >> 24 ) & 0xff ;
V_174 . V_177 = ( V_3 >> 16 ) & 0xff ;
V_174 . V_178 = ( V_3 >> 8 ) & 0xff ;
V_174 . V_179 = ( V_3 ) & 0xff ;
return F_65 ( & V_174 ) ;
}
void F_66 ( struct V_97 * V_98 , unsigned int V_180 ,
T_2 V_181 )
{
T_5 V_182 ;
V_182 = V_98 -> V_182 + V_180 * V_183 ;
V_98 -> V_184 [ V_180 ] . V_181 = F_67 ( V_181 ) ;
V_98 -> V_184 [ V_180 ] . V_185 = 0 ;
V_98 -> V_184 [ V_180 ] . V_186 = F_67 ( V_182 & 0xffffffff ) ;
V_98 -> V_184 [ V_180 ] . V_187 = F_67 ( ( V_182 >> 16 ) >> 16 ) ;
}
int F_68 ( struct V_13 * V_14 )
{
void T_1 * V_22 = F_12 ( V_14 ) ;
struct V_15 * V_16 = V_14 -> V_17 -> V_18 ;
T_6 V_185 = F_2 ( V_22 + V_188 ) & 0xFF ;
T_2 V_3 ;
int V_189 , V_128 ;
V_128 = F_29 ( V_14 ) ;
if ( V_128 )
goto V_190;
V_189 = V_185 & ( V_191 | V_192 ) ;
if ( ! V_189 && ! F_69 ( V_14 ) ) {
V_128 = 0 ;
goto V_190;
}
if ( ! ( V_16 -> V_19 & V_193 ) ) {
V_128 = - V_194 ;
goto V_190;
}
V_3 = F_2 ( V_22 + V_23 ) ;
V_3 |= V_195 ;
F_3 ( V_3 , V_22 + V_23 ) ;
V_128 = 0 ;
V_3 = F_30 ( V_14 , V_22 + V_23 ,
V_195 , V_195 , 1 , 500 ) ;
if ( V_3 & V_195 )
V_128 = - V_96 ;
V_190:
V_16 -> V_76 ( V_14 ) ;
return V_128 ;
}
static int F_70 ( struct V_13 * V_14 , int V_131 ,
struct V_173 * V_174 , int V_196 , T_7 V_28 ,
unsigned long V_197 )
{
const T_2 V_198 = 5 ;
struct V_97 * V_98 = V_14 -> V_18 ;
void T_1 * V_22 = F_12 ( V_14 ) ;
T_6 * V_199 = V_98 -> V_200 ;
T_2 V_3 ;
F_71 ( V_174 , V_131 , V_196 , V_199 ) ;
F_66 ( V_98 , 0 , V_198 | V_28 | ( V_131 << 12 ) ) ;
F_3 ( 1 , V_22 + V_201 ) ;
if ( V_197 ) {
V_3 = F_30 ( V_14 , V_22 + V_201 ,
0x1 , 0x1 , 1 , V_197 ) ;
if ( V_3 & 0x1 ) {
F_68 ( V_14 ) ;
return - V_45 ;
}
} else
F_2 ( V_22 + V_201 ) ;
return 0 ;
}
int F_72 ( struct V_91 * V_92 , unsigned int * V_202 ,
int V_131 , unsigned long V_203 ,
int (* F_73)( struct V_91 * V_92 ) )
{
struct V_13 * V_14 = V_92 -> V_14 ;
struct V_15 * V_16 = V_14 -> V_17 -> V_18 ;
struct V_97 * V_98 = V_14 -> V_18 ;
const char * V_204 = NULL ;
unsigned long V_205 , V_206 ;
struct V_173 V_174 ;
bool V_207 = false ;
int V_128 ;
F_74 ( L_32 ) ;
V_128 = F_68 ( V_14 ) ;
if ( V_128 && V_128 != - V_194 )
F_75 ( V_92 , L_33 , V_128 ) ;
if ( ! F_76 ( V_92 ) && V_98 -> V_208 ) {
F_77 ( V_14 ) ;
V_207 = true ;
}
F_78 ( V_92 -> V_6 , & V_174 ) ;
V_206 = 0 ;
V_205 = V_143 ;
if ( F_79 ( V_203 , V_205 ) )
V_206 = F_80 ( V_203 - V_205 ) ;
V_174 . V_209 |= V_210 ;
if ( F_70 ( V_14 , V_131 , & V_174 , 0 ,
V_211 | V_212 , V_206 ) ) {
V_128 = - V_96 ;
V_204 = L_34 ;
goto V_213;
}
F_36 ( V_14 , 1 ) ;
V_174 . V_209 &= ~ V_210 ;
F_70 ( V_14 , V_131 , & V_174 , 0 , 0 , 0 ) ;
V_128 = F_81 ( V_92 , V_203 , F_73 ) ;
if ( V_128 == - V_45 && V_16 -> V_28 & V_214 ) {
F_82 ( V_92 , L_35 ) ;
* V_202 = V_215 ;
} else if ( V_128 ) {
V_204 = L_36 ;
goto V_213;
} else
* V_202 = F_64 ( V_14 ) ;
if ( V_207 )
F_83 ( V_14 ) ;
F_74 ( L_37 , * V_202 ) ;
return 0 ;
V_213:
F_84 ( V_92 , L_38 , V_204 ) ;
return V_128 ;
}
int F_85 ( struct V_91 * V_92 )
{
void T_1 * V_22 = F_12 ( V_92 -> V_14 ) ;
T_6 V_185 = F_2 ( V_22 + V_188 ) & 0xFF ;
return F_86 ( V_185 ) ;
}
static int F_87 ( struct V_91 * V_92 , unsigned int * V_202 ,
unsigned long V_203 )
{
int V_131 = F_88 ( V_92 ) ;
F_74 ( L_32 ) ;
return F_72 ( V_92 , V_202 , V_131 , V_203 , F_85 ) ;
}
static int F_89 ( struct V_91 * V_92 )
{
void T_1 * V_22 = F_12 ( V_92 -> V_14 ) ;
T_6 V_185 = F_2 ( V_22 + V_188 ) & 0xFF ;
T_2 V_216 = F_2 ( V_22 + V_166 ) ;
if ( V_216 & V_217 )
return - V_96 ;
return F_86 ( V_185 ) ;
}
static int F_90 ( struct V_91 * V_92 , unsigned int * V_202 ,
unsigned long V_203 )
{
struct V_13 * V_14 = V_92 -> V_14 ;
void T_1 * V_22 = F_12 ( V_14 ) ;
int V_131 = F_88 ( V_92 ) ;
int V_128 ;
T_2 V_218 ;
F_74 ( L_32 ) ;
V_128 = F_72 ( V_92 , V_202 , V_131 , V_203 ,
F_89 ) ;
if ( V_128 == - V_96 ) {
V_218 = F_2 ( V_22 + V_166 ) ;
if ( V_218 & V_217 ) {
F_75 ( V_92 ,
L_39
L_40 ) ;
V_128 = F_72 ( V_92 , V_202 , 0 , V_203 ,
F_85 ) ;
}
}
return V_128 ;
}
static int F_91 ( struct V_91 * V_92 , unsigned int * V_202 ,
unsigned long V_203 )
{
const unsigned long * V_219 = F_92 ( & V_92 -> V_220 ) ;
struct V_13 * V_14 = V_92 -> V_14 ;
struct V_97 * V_98 = V_14 -> V_18 ;
struct V_15 * V_16 = V_14 -> V_17 -> V_18 ;
T_6 * V_221 = V_98 -> V_222 + V_223 ;
struct V_173 V_174 ;
bool V_224 ;
int V_128 ;
F_74 ( L_32 ) ;
F_29 ( V_14 ) ;
F_78 ( V_92 -> V_6 , & V_174 ) ;
V_174 . V_225 = V_191 ;
F_71 ( & V_174 , 0 , 0 , V_221 ) ;
V_128 = F_93 ( V_92 , V_219 , V_203 , & V_224 ,
F_85 ) ;
V_16 -> V_76 ( V_14 ) ;
if ( V_224 )
* V_202 = F_64 ( V_14 ) ;
F_74 ( L_41 , V_128 , * V_202 ) ;
return V_128 ;
}
static void F_94 ( struct V_91 * V_92 , unsigned int * V_202 )
{
struct V_13 * V_14 = V_92 -> V_14 ;
void T_1 * V_22 = F_12 ( V_14 ) ;
T_2 V_226 , V_3 ;
F_95 ( V_92 , V_202 ) ;
V_226 = V_3 = F_2 ( V_22 + V_23 ) ;
if ( * V_202 == V_227 )
V_226 |= V_228 ;
else
V_226 &= ~ V_228 ;
if ( V_226 != V_3 ) {
F_3 ( V_226 , V_22 + V_23 ) ;
F_2 ( V_22 + V_23 ) ;
}
}
static unsigned int F_96 ( struct V_229 * V_230 , void * V_200 )
{
struct V_231 * V_232 ;
struct V_233 * V_233 = V_200 + V_234 ;
unsigned int V_235 ;
F_59 ( L_32 ) ;
F_97 (qc->sg, sg, qc->n_elem, si) {
T_5 V_236 = F_98 ( V_232 ) ;
T_2 V_237 = F_99 ( V_232 ) ;
V_233 [ V_235 ] . V_236 = F_67 ( V_236 & 0xffffffff ) ;
V_233 [ V_235 ] . V_238 = F_67 ( ( V_236 >> 16 ) >> 16 ) ;
V_233 [ V_235 ] . V_239 = F_67 ( V_237 - 1 ) ;
}
return V_235 ;
}
static int F_100 ( struct V_229 * V_230 )
{
struct V_13 * V_14 = V_230 -> V_14 ;
struct V_97 * V_98 = V_14 -> V_18 ;
if ( ! F_69 ( V_14 ) || V_98 -> V_208 )
return F_101 ( V_230 ) ;
else
return F_102 ( V_230 ) ;
}
static void F_103 ( struct V_229 * V_230 )
{
struct V_13 * V_14 = V_230 -> V_14 ;
struct V_97 * V_98 = V_14 -> V_18 ;
int V_240 = F_104 ( V_230 -> V_174 . V_241 ) ;
void * V_200 ;
T_2 V_181 ;
const T_2 V_198 = 5 ;
unsigned int V_242 ;
V_200 = V_98 -> V_200 + V_230 -> V_180 * V_183 ;
F_71 ( & V_230 -> V_174 , V_230 -> V_7 -> V_92 -> V_131 , 1 , V_200 ) ;
if ( V_240 ) {
memset ( V_200 + V_243 , 0 , 32 ) ;
memcpy ( V_200 + V_243 , V_230 -> V_244 , V_230 -> V_7 -> V_245 ) ;
}
V_242 = 0 ;
if ( V_230 -> V_28 & V_246 )
V_242 = F_96 ( V_230 , V_200 ) ;
V_181 = V_198 | V_242 << 16 | ( V_230 -> V_7 -> V_92 -> V_131 << 12 ) ;
if ( V_230 -> V_174 . V_28 & V_247 )
V_181 |= V_248 ;
if ( V_240 )
V_181 |= V_249 | V_250 ;
F_66 ( V_98 , V_230 -> V_180 , V_181 ) ;
}
static void F_105 ( struct V_13 * V_14 )
{
struct V_97 * V_98 = V_14 -> V_18 ;
void T_1 * V_22 = F_12 ( V_14 ) ;
T_2 V_251 = F_2 ( V_22 + V_252 ) ;
int V_253 = 3 ;
F_74 ( L_32 ) ;
F_106 ( ! V_98 -> V_208 ) ;
F_3 ( V_251 | V_254 , V_22 + V_252 ) ;
V_251 = F_2 ( V_22 + V_252 ) ;
while ( ( V_251 & V_254 ) && V_253 -- ) {
F_107 ( 1 ) ;
V_251 = F_2 ( V_22 + V_252 ) ;
}
if ( V_251 & V_254 )
F_44 ( V_14 -> V_17 -> V_7 , L_42 ) ;
}
static void F_108 ( struct V_13 * V_14 , T_2 V_255 )
{
struct V_15 * V_16 = V_14 -> V_17 -> V_18 ;
struct V_97 * V_98 = V_14 -> V_18 ;
struct V_256 * V_257 = & V_14 -> V_92 . V_258 ;
struct V_91 * V_92 = NULL ;
struct V_229 * V_259 ;
struct V_256 * V_260 ;
bool V_261 = false ;
T_2 V_262 ;
if ( V_98 -> V_208 ) {
void T_1 * V_22 = F_12 ( V_14 ) ;
T_2 V_251 = F_2 ( V_22 + V_252 ) ;
int V_131 = V_251 >> V_263 ;
if ( ( V_251 & V_264 ) && ( V_131 < V_14 -> V_265 ) ) {
V_92 = & V_14 -> V_266 [ V_131 ] ;
V_261 = true ;
}
} else
F_40 (link, ap, EDGE)
if ( F_109 ( V_92 ) )
break;
if ( ! V_92 )
V_92 = & V_14 -> V_92 ;
V_259 = F_110 ( V_14 , V_92 -> V_267 ) ;
V_260 = & V_92 -> V_258 ;
F_111 ( V_257 ) ;
F_112 ( V_257 , L_43 , V_255 ) ;
F_27 ( & V_14 -> V_92 , V_85 , & V_262 ) ;
F_28 ( & V_14 -> V_92 , V_85 , V_262 ) ;
V_257 -> V_262 |= V_262 ;
if ( V_16 -> V_28 & V_268 )
V_255 &= ~ V_269 ;
if ( V_255 & V_270 ) {
if ( V_259 )
V_259 -> V_271 |= V_272 ;
else
V_260 -> V_271 |= V_272 ;
if ( V_16 -> V_28 & V_273 )
V_257 -> V_262 &= ~ V_274 ;
}
if ( V_255 & V_275 ) {
T_2 * V_276 = V_98 -> V_222 + V_277 ;
V_260 -> V_271 |= V_278 ;
V_260 -> V_279 |= V_280 ;
F_112 ( V_260 ,
L_44 ,
V_276 [ 0 ] , V_276 [ 1 ] , V_276 [ 2 ] , V_276 [ 3 ] ) ;
}
if ( F_69 ( V_14 ) && ( V_255 & V_217 ) ) {
V_260 -> V_271 |= V_278 ;
V_260 -> V_279 |= V_280 ;
F_112 ( V_260 , L_45 ) ;
}
if ( V_255 & ( V_281 | V_282 ) ) {
V_257 -> V_271 |= V_283 ;
V_257 -> V_279 |= V_280 ;
F_112 ( V_257 , L_46 ) ;
}
if ( V_255 & V_269 ) {
if ( V_261 )
V_260 -> V_271 |= V_272 ;
else {
V_257 -> V_271 |= V_284 ;
V_257 -> V_279 |= V_280 ;
}
F_112 ( V_257 , L_47 ) ;
}
if ( V_255 & ( V_285 | V_117 ) ) {
F_113 ( V_257 ) ;
F_112 ( V_257 , L_48 ,
V_255 & V_285 ?
L_49 : L_50 ) ;
}
if ( V_255 & V_286 )
F_114 ( V_14 ) ;
else if ( V_261 ) {
F_115 ( V_92 ) ;
F_105 ( V_14 ) ;
} else
F_116 ( V_14 ) ;
}
static void F_117 ( struct V_13 * V_14 ,
void T_1 * V_22 , T_2 V_185 )
{
struct V_256 * V_287 = & V_14 -> V_92 . V_258 ;
struct V_97 * V_98 = V_14 -> V_18 ;
struct V_15 * V_16 = V_14 -> V_17 -> V_18 ;
int V_288 = ! ! ( V_14 -> V_289 & V_290 ) ;
T_2 V_291 = 0 ;
int V_128 ;
if ( F_118 ( V_288 ) )
V_185 &= ~ V_217 ;
if ( V_14 -> V_92 . V_292 > V_115 ) {
V_185 &= ~ V_117 ;
F_28 ( & V_14 -> V_92 , V_85 , V_293 ) ;
}
if ( F_118 ( V_185 & V_294 ) ) {
F_108 ( V_14 , V_185 ) ;
return;
}
if ( V_185 & V_295 ) {
if ( V_16 -> V_19 & V_67 )
F_119 ( V_14 ) ;
else {
if ( V_98 -> V_208 )
F_120 ( 1 ) ;
else {
const T_8 * V_296 = V_98 -> V_222 + V_297 ;
T_2 V_298 = F_121 ( V_296 [ 0 ] ) ;
if ( V_298 & ( 1 << 15 ) )
F_119 ( V_14 ) ;
}
}
}
if ( V_98 -> V_208 ) {
if ( V_14 -> V_291 ) {
V_291 = F_2 ( V_22 + V_88 ) ;
V_291 |= F_2 ( V_22 + V_201 ) ;
}
} else {
if ( V_14 -> V_291 && V_98 -> V_299 -> V_300 )
V_291 = F_2 ( V_22 + V_88 ) ;
else
V_291 = F_2 ( V_22 + V_201 ) ;
}
V_128 = F_122 ( V_14 , V_291 ) ;
if ( F_118 ( V_128 < 0 && ! V_288 ) ) {
V_287 -> V_271 |= V_278 ;
V_287 -> V_279 |= V_280 ;
F_114 ( V_14 ) ;
}
}
static void F_123 ( struct V_13 * V_14 )
{
void T_1 * V_22 = F_12 ( V_14 ) ;
T_2 V_185 ;
V_185 = F_2 ( V_22 + V_166 ) ;
F_3 ( V_185 , V_22 + V_166 ) ;
F_117 ( V_14 , V_22 , V_185 ) ;
}
T_9 F_124 ( int V_301 , void * V_302 )
{
struct V_13 * V_14 = V_302 ;
struct V_97 * V_98 = V_14 -> V_18 ;
void T_1 * V_22 = F_12 ( V_14 ) ;
unsigned long V_28 ;
T_2 V_185 ;
F_14 ( & V_14 -> V_17 -> V_30 , V_28 ) ;
V_185 = V_98 -> V_303 ;
if ( V_185 )
V_98 -> V_303 = 0 ;
F_15 ( & V_14 -> V_17 -> V_30 , V_28 ) ;
F_125 ( V_14 -> V_30 ) ;
F_117 ( V_14 , V_22 , V_185 ) ;
F_126 ( V_14 -> V_30 ) ;
return V_304 ;
}
static void F_127 ( struct V_13 * V_14 )
{
void T_1 * V_22 = F_12 ( V_14 ) ;
struct V_97 * V_98 = V_14 -> V_18 ;
T_2 V_185 ;
V_185 = F_2 ( V_22 + V_166 ) ;
F_3 ( V_185 , V_22 + V_166 ) ;
V_98 -> V_303 |= V_185 ;
}
T_9 F_128 ( int V_301 , void * V_302 )
{
struct V_13 * V_305 = V_302 ;
struct V_97 * V_98 = V_305 -> V_18 ;
struct V_78 * V_17 = V_305 -> V_17 ;
struct V_15 * V_16 = V_17 -> V_18 ;
void T_1 * V_1 = V_16 -> V_1 ;
unsigned int V_2 ;
T_2 V_255 , V_306 ;
F_59 ( L_32 ) ;
F_129 ( & V_17 -> V_30 ) ;
V_255 = F_2 ( V_1 + V_167 ) ;
if ( ! V_255 ) {
T_2 V_185 = V_98 -> V_303 ;
F_130 ( & V_17 -> V_30 ) ;
F_59 ( L_51 ) ;
return V_185 ? V_307 : V_308 ;
}
V_306 = V_255 & V_16 -> V_53 ;
for ( V_2 = 0 ; V_2 < V_17 -> V_168 ; V_2 ++ ) {
struct V_13 * V_14 ;
if ( ! ( V_306 & ( 1 << V_2 ) ) )
continue;
V_14 = V_17 -> V_169 [ V_2 ] ;
if ( V_14 ) {
F_127 ( V_14 ) ;
F_59 ( L_52 , V_2 ) ;
} else {
F_59 ( L_53 , V_2 ) ;
if ( F_131 () )
F_22 ( V_17 -> V_7 ,
L_54 , V_2 ) ;
}
}
F_3 ( V_255 , V_1 + V_167 ) ;
F_130 ( & V_17 -> V_30 ) ;
F_59 ( L_51 ) ;
return V_307 ;
}
T_9 F_132 ( int V_301 , void * V_302 )
{
struct V_78 * V_17 = V_302 ;
struct V_15 * V_16 ;
unsigned int V_2 , V_309 = 0 ;
void T_1 * V_1 ;
T_2 V_255 , V_306 ;
F_59 ( L_32 ) ;
V_16 = V_17 -> V_18 ;
V_1 = V_16 -> V_1 ;
V_255 = F_2 ( V_1 + V_167 ) ;
if ( ! V_255 )
return V_308 ;
V_306 = V_255 & V_16 -> V_53 ;
F_129 ( & V_17 -> V_30 ) ;
for ( V_2 = 0 ; V_2 < V_17 -> V_168 ; V_2 ++ ) {
struct V_13 * V_14 ;
if ( ! ( V_306 & ( 1 << V_2 ) ) )
continue;
V_14 = V_17 -> V_169 [ V_2 ] ;
if ( V_14 ) {
F_123 ( V_14 ) ;
F_59 ( L_52 , V_2 ) ;
} else {
F_59 ( L_53 , V_2 ) ;
if ( F_131 () )
F_22 ( V_17 -> V_7 ,
L_54 , V_2 ) ;
}
V_309 = 1 ;
}
F_3 ( V_255 , V_1 + V_167 ) ;
F_130 ( & V_17 -> V_30 ) ;
F_59 ( L_51 ) ;
return F_133 ( V_309 ) ;
}
static unsigned int F_134 ( struct V_229 * V_230 )
{
struct V_13 * V_14 = V_230 -> V_14 ;
void T_1 * V_22 = F_12 ( V_14 ) ;
struct V_97 * V_98 = V_14 -> V_18 ;
V_98 -> V_299 = V_230 -> V_7 -> V_92 ;
if ( V_230 -> V_174 . V_241 == V_310 )
F_3 ( 1 << V_230 -> V_180 , V_22 + V_88 ) ;
if ( V_98 -> V_208 && V_98 -> V_311 != V_230 -> V_7 -> V_92 -> V_131 ) {
T_2 V_251 = F_2 ( V_22 + V_252 ) ;
V_251 &= ~ ( V_312 | V_254 ) ;
V_251 |= V_230 -> V_7 -> V_92 -> V_131 << V_313 ;
F_3 ( V_251 , V_22 + V_252 ) ;
V_98 -> V_311 = V_230 -> V_7 -> V_92 -> V_131 ;
}
F_3 ( 1 << V_230 -> V_180 , V_22 + V_201 ) ;
F_45 ( V_230 -> V_7 -> V_92 ) ;
return 0 ;
}
static bool F_135 ( struct V_229 * V_230 )
{
struct V_97 * V_98 = V_230 -> V_14 -> V_18 ;
T_6 * V_222 = V_98 -> V_222 ;
if ( V_98 -> V_208 )
V_222 += V_230 -> V_7 -> V_92 -> V_131 * V_314 ;
if ( V_230 -> V_174 . V_241 == V_315 && V_230 -> V_316 == V_317 &&
! ( V_230 -> V_28 & V_318 ) ) {
F_136 ( V_222 + V_319 , & V_230 -> V_320 ) ;
V_230 -> V_320 . V_225 = ( V_222 + V_319 ) [ 15 ] ;
} else
F_136 ( V_222 + V_223 , & V_230 -> V_320 ) ;
return true ;
}
static void F_137 ( struct V_13 * V_14 )
{
void T_1 * V_22 = F_12 ( V_14 ) ;
F_3 ( 0 , V_22 + V_118 ) ;
}
static void F_138 ( struct V_13 * V_14 )
{
struct V_15 * V_16 = V_14 -> V_17 -> V_18 ;
void T_1 * V_1 = V_16 -> V_1 ;
void T_1 * V_22 = F_12 ( V_14 ) ;
T_2 V_3 ;
struct V_97 * V_98 = V_14 -> V_18 ;
V_3 = F_2 ( V_22 + V_166 ) ;
F_3 ( V_3 , V_22 + V_166 ) ;
F_3 ( 1 << V_14 -> V_148 , V_1 + V_167 ) ;
F_3 ( V_98 -> V_116 , V_22 + V_118 ) ;
}
void F_139 ( struct V_13 * V_14 )
{
struct V_15 * V_16 = V_14 -> V_17 -> V_18 ;
if ( ! ( V_14 -> V_289 & V_321 ) ) {
F_29 ( V_14 ) ;
V_16 -> V_76 ( V_14 ) ;
}
F_140 ( V_14 ) ;
if ( ! F_141 ( V_14 -> V_92 . V_6 ) )
F_29 ( V_14 ) ;
}
static void F_142 ( struct V_229 * V_230 )
{
struct V_13 * V_14 = V_230 -> V_14 ;
if ( V_230 -> V_28 & V_318 )
F_68 ( V_14 ) ;
}
static void F_37 ( struct V_13 * V_14 , bool V_322 )
{
struct V_15 * V_16 = V_14 -> V_17 -> V_18 ;
void T_1 * V_22 = F_12 ( V_14 ) ;
struct V_161 * V_7 = V_14 -> V_92 . V_6 ;
T_2 V_323 , V_324 , V_325 , V_326 , V_327 ;
int V_128 ;
unsigned int V_271 ;
V_323 = F_2 ( V_22 + V_328 ) ;
if ( ! ( V_323 & V_329 ) ) {
F_44 ( V_14 -> V_17 -> V_7 , L_55 ) ;
return;
}
if ( ! V_322 ) {
if ( V_323 & V_330 ) {
F_3 ( V_323 & ~ V_330 ,
V_22 + V_328 ) ;
V_271 = F_143 ( V_7 ,
V_331 ,
V_332 ) ;
if ( V_271 && V_271 != V_272 )
F_144 ( V_7 , L_56 ) ;
}
return;
}
if ( V_323 & V_330 )
return;
V_128 = F_29 ( V_14 ) ;
if ( V_128 )
return;
V_324 = ( V_323 & V_333 ) >> V_334 ;
V_325 = V_335 / ( V_324 + 1 ) ;
if ( V_325 > 0x3ff )
V_325 = 0x3ff ;
if ( V_7 -> V_336 [ V_337 ] &
V_338 ) {
V_326 = V_7 -> V_336 [ V_339 ] &
V_340 ;
if ( ! V_326 )
V_326 = 10 ;
V_327 = V_7 -> V_336 [ V_341 ] ;
if ( ! V_327 )
V_327 = 20 ;
} else {
V_326 = 10 ;
V_327 = 20 ;
}
V_323 |= ( ( V_325 << V_342 ) |
( V_326 << V_343 ) |
( V_327 << V_344 ) |
V_330 ) ;
F_3 ( V_323 , V_22 + V_328 ) ;
V_16 -> V_76 ( V_14 ) ;
V_271 = F_143 ( V_7 ,
V_345 ,
V_332 ) ;
if ( V_271 && V_271 != V_272 )
F_144 ( V_7 , L_57 ) ;
}
static void F_83 ( struct V_13 * V_14 )
{
struct V_15 * V_16 = V_14 -> V_17 -> V_18 ;
struct V_97 * V_98 = V_14 -> V_18 ;
void T_1 * V_22 = F_12 ( V_14 ) ;
T_2 V_251 ;
int V_128 ;
if ( ! V_98 -> V_346 )
return;
V_251 = F_2 ( V_22 + V_252 ) ;
if ( V_251 & V_347 ) {
V_98 -> V_208 = true ;
V_98 -> V_311 = - 1 ;
return;
}
V_128 = F_29 ( V_14 ) ;
if ( V_128 )
return;
F_3 ( V_251 | V_347 , V_22 + V_252 ) ;
V_251 = F_2 ( V_22 + V_252 ) ;
if ( V_251 & V_347 ) {
F_21 ( V_14 -> V_17 -> V_7 , L_58 ) ;
V_98 -> V_208 = true ;
V_98 -> V_311 = - 1 ;
} else
F_44 ( V_14 -> V_17 -> V_7 , L_59 ) ;
V_16 -> V_76 ( V_14 ) ;
}
static void F_77 ( struct V_13 * V_14 )
{
struct V_15 * V_16 = V_14 -> V_17 -> V_18 ;
struct V_97 * V_98 = V_14 -> V_18 ;
void T_1 * V_22 = F_12 ( V_14 ) ;
T_2 V_251 ;
int V_128 ;
if ( ! V_98 -> V_346 )
return;
V_251 = F_2 ( V_22 + V_252 ) ;
if ( ( V_251 & V_347 ) == 0 ) {
V_98 -> V_208 = false ;
return;
}
V_128 = F_29 ( V_14 ) ;
if ( V_128 )
return;
F_3 ( V_251 & ~ V_347 , V_22 + V_252 ) ;
V_251 = F_2 ( V_22 + V_252 ) ;
if ( V_251 & V_347 )
F_44 ( V_14 -> V_17 -> V_7 , L_60 ) ;
else {
F_21 ( V_14 -> V_17 -> V_7 , L_61 ) ;
V_98 -> V_208 = false ;
}
V_16 -> V_76 ( V_14 ) ;
}
static void F_145 ( struct V_13 * V_14 )
{
void T_1 * V_22 = F_12 ( V_14 ) ;
struct V_97 * V_98 = V_14 -> V_18 ;
T_2 V_107 ;
V_107 = F_2 ( V_22 + V_23 ) ;
V_107 |= V_348 ;
F_3 ( V_107 , V_22 + V_23 ) ;
F_83 ( V_14 ) ;
V_98 -> V_116 |= V_217 ;
if ( ! ( V_14 -> V_289 & V_321 ) )
F_3 ( V_98 -> V_116 , V_22 + V_118 ) ;
}
static void F_146 ( struct V_13 * V_14 )
{
void T_1 * V_22 = F_12 ( V_14 ) ;
struct V_97 * V_98 = V_14 -> V_18 ;
T_2 V_107 ;
F_77 ( V_14 ) ;
V_107 = F_2 ( V_22 + V_23 ) ;
V_107 &= ~ V_348 ;
F_3 ( V_107 , V_22 + V_23 ) ;
V_98 -> V_116 &= ~ V_217 ;
if ( ! ( V_14 -> V_289 & V_321 ) )
F_3 ( V_98 -> V_116 , V_22 + V_118 ) ;
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
static int F_148 ( struct V_13 * V_14 , T_10 V_349 )
{
const char * V_137 = NULL ;
int V_128 ;
V_128 = F_42 ( V_14 , & V_137 ) ;
if ( V_128 == 0 )
F_38 ( V_14 ) ;
else {
F_149 ( V_14 , L_27 , V_137 , V_128 ) ;
F_114 ( V_14 ) ;
}
return V_128 ;
}
static int F_150 ( struct V_13 * V_14 )
{
struct V_15 * V_16 = V_14 -> V_17 -> V_18 ;
struct V_6 * V_7 = V_14 -> V_17 -> V_7 ;
struct V_97 * V_98 ;
void * V_350 ;
T_5 V_351 ;
T_4 V_352 , V_353 ;
V_98 = F_151 ( V_7 , sizeof( * V_98 ) , V_354 ) ;
if ( ! V_98 )
return - V_355 ;
if ( V_14 -> V_17 -> V_168 > 1 ) {
V_98 -> V_356 = F_151 ( V_7 , 8 , V_354 ) ;
if ( ! V_98 -> V_356 ) {
F_152 ( V_7 , V_98 ) ;
return - V_355 ;
}
snprintf ( V_98 -> V_356 , 8 ,
L_62 , F_153 ( V_7 ) , V_14 -> V_148 ) ;
}
if ( ( V_16 -> V_19 & V_72 ) && F_154 ( V_14 ) ) {
void T_1 * V_22 = F_12 ( V_14 ) ;
T_2 V_107 = F_2 ( V_22 + V_23 ) ;
if ( V_107 & V_357 )
V_98 -> V_346 = true ;
else if ( V_16 -> V_28 & V_73 ) {
F_21 ( V_7 , L_63 ,
V_14 -> V_148 ) ;
V_98 -> V_346 = true ;
} else
F_22 ( V_7 , L_64 ,
V_14 -> V_148 ) ;
}
if ( V_98 -> V_346 ) {
V_352 = V_358 ;
V_353 = V_314 * 16 ;
} else {
V_352 = V_359 ;
V_353 = V_314 ;
}
V_350 = F_155 ( V_7 , V_352 , & V_351 , V_354 ) ;
if ( ! V_350 )
return - V_355 ;
memset ( V_350 , 0 , V_352 ) ;
V_98 -> V_184 = V_350 ;
V_98 -> V_99 = V_351 ;
V_350 += V_360 ;
V_351 += V_360 ;
V_98 -> V_222 = V_350 ;
V_98 -> V_102 = V_351 ;
V_350 += V_353 ;
V_351 += V_353 ;
V_98 -> V_200 = V_350 ;
V_98 -> V_182 = V_351 ;
V_98 -> V_116 = V_361 ;
if ( ( V_16 -> V_28 & V_362 ) ) {
F_156 ( & V_98 -> V_30 ) ;
V_14 -> V_30 = & V_98 -> V_30 ;
}
V_14 -> V_18 = V_98 ;
return F_147 ( V_14 ) ;
}
static void F_157 ( struct V_13 * V_14 )
{
const char * V_137 = NULL ;
int V_128 ;
V_128 = F_42 ( V_14 , & V_137 ) ;
if ( V_128 )
F_17 ( V_14 , L_27 , V_137 , V_128 ) ;
}
void F_158 ( struct V_78 * V_17 , const char * V_363 )
{
struct V_15 * V_16 = V_17 -> V_18 ;
void T_1 * V_1 = V_16 -> V_1 ;
T_2 V_52 , V_19 , V_20 , V_364 , V_365 ;
const char * V_366 ;
V_52 = F_2 ( V_1 + V_21 ) ;
V_19 = V_16 -> V_19 ;
V_20 = V_16 -> V_20 ;
V_364 = V_16 -> V_53 ;
V_365 = ( V_19 >> 20 ) & 0xf ;
if ( V_365 == 1 )
V_366 = L_65 ;
else if ( V_365 == 2 )
V_366 = L_66 ;
else if ( V_365 == 3 )
V_366 = L_67 ;
else
V_366 = L_68 ;
F_21 ( V_17 -> V_7 ,
L_69
L_70
,
( V_52 >> 24 ) & 0xff ,
( V_52 >> 16 ) & 0xff ,
( V_52 >> 8 ) & 0xff ,
V_52 & 0xff ,
( ( V_19 >> 8 ) & 0x1f ) + 1 ,
( V_19 & 0x1f ) + 1 ,
V_366 ,
V_364 ,
V_363 ) ;
F_21 ( V_17 -> V_7 ,
L_71
L_72
L_72
L_72
L_73
,
V_19 & V_60 ? L_74 : L_6 ,
V_19 & V_62 ? L_75 : L_6 ,
V_19 & V_67 ? L_76 : L_6 ,
V_19 & V_367 ? L_77 : L_6 ,
V_19 & V_109 ? L_78 : L_6 ,
V_19 & V_119 ? L_79 : L_6 ,
V_19 & V_368 ? L_5 : L_6 ,
V_19 & V_193 ? L_80 : L_6 ,
V_19 & V_369 ? L_81 : L_6 ,
V_19 & V_65 ? L_82 : L_6 ,
V_19 & V_72 ? L_83 : L_6 ,
V_19 & V_370 ? L_84 : L_6 ,
V_19 & V_371 ? L_85 : L_6 ,
V_19 & V_372 ? L_86 : L_6 ,
V_19 & V_373 ? L_87 : L_6 ,
V_19 & V_374 ? L_88 : L_6 ,
V_19 & V_375 ? L_89 : L_6 ,
V_20 & V_376 ? L_90 : L_6 ,
V_20 & V_71 ? L_91 : L_6 ,
V_20 & V_69 ? L_92 : L_6 ,
V_20 & V_377 ? L_93 : L_6 ,
V_20 & V_378 ? L_94 : L_6 ,
V_20 & V_379 ? L_95 : L_6
) ;
}
void F_159 ( struct V_15 * V_16 ,
struct V_380 * V_381 )
{
T_6 V_382 ;
void T_1 * V_1 = V_16 -> V_1 ;
T_2 V_25 = F_2 ( V_1 + V_383 ) ;
T_2 V_26 = F_2 ( V_1 + V_31 ) ;
if ( ! V_384 || ! ( V_16 -> V_19 & V_374 ) )
return;
V_382 = ( V_26 & V_385 ) >> 16 ;
if ( V_382 ) {
V_16 -> V_25 = ( ( V_25 >> 16 ) * 4 ) ;
V_16 -> V_40 = ( ( V_25 & 0xff ) * 4 ) ;
V_16 -> V_34 = V_382 ;
V_381 -> V_28 |= V_32 ;
if ( ! ( V_26 & V_386 ) )
V_381 -> V_28 |= V_136 ;
}
}
