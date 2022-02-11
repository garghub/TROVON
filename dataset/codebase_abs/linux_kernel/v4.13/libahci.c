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
static int F_6 ( struct V_6 * V_7 )
{
return F_7 ( V_7 -> V_8 ) ;
}
static void F_8 ( struct V_6 * V_7 )
{
F_9 ( V_7 -> V_8 ) ;
}
static T_3 F_10 ( struct V_9 * V_8 ,
struct V_10 * V_11 , char * V_12 )
{
struct V_13 * V_14 = F_11 ( V_8 ) ;
struct V_6 * V_7 = F_12 ( V_14 ) ;
struct V_15 * V_16 = V_7 -> V_17 -> V_18 ;
return sprintf ( V_12 , L_1 , V_16 -> V_19 ) ;
}
static T_3 F_13 ( struct V_9 * V_8 ,
struct V_10 * V_11 , char * V_12 )
{
struct V_13 * V_14 = F_11 ( V_8 ) ;
struct V_6 * V_7 = F_12 ( V_14 ) ;
struct V_15 * V_16 = V_7 -> V_17 -> V_18 ;
return sprintf ( V_12 , L_1 , V_16 -> V_20 ) ;
}
static T_3 F_14 ( struct V_9 * V_8 ,
struct V_10 * V_11 , char * V_12 )
{
struct V_13 * V_14 = F_11 ( V_8 ) ;
struct V_6 * V_7 = F_12 ( V_14 ) ;
struct V_15 * V_16 = V_7 -> V_17 -> V_18 ;
return sprintf ( V_12 , L_1 , V_16 -> V_21 ) ;
}
static T_3 F_15 ( struct V_9 * V_8 ,
struct V_10 * V_11 , char * V_12 )
{
struct V_13 * V_14 = F_11 ( V_8 ) ;
struct V_6 * V_7 = F_12 ( V_14 ) ;
void T_1 * V_22 = F_16 ( V_7 ) ;
T_3 V_23 ;
F_6 ( V_7 ) ;
V_23 = sprintf ( V_12 , L_1 , F_2 ( V_22 + V_24 ) ) ;
F_8 ( V_7 ) ;
return V_23 ;
}
static T_3 F_17 ( struct V_9 * V_8 ,
struct V_10 * V_11 , char * V_12 )
{
struct V_13 * V_14 = F_11 ( V_8 ) ;
struct V_6 * V_7 = F_12 ( V_14 ) ;
struct V_15 * V_16 = V_7 -> V_17 -> V_18 ;
void T_1 * V_1 = V_16 -> V_1 ;
void T_1 * V_25 = V_1 + V_16 -> V_26 ;
T_2 V_27 , V_28 ;
unsigned long V_29 ;
T_4 V_30 ;
int V_2 ;
F_6 ( V_7 ) ;
F_18 ( V_7 -> V_31 , V_29 ) ;
V_27 = F_2 ( V_1 + V_32 ) ;
if ( ! ( V_7 -> V_29 & V_33 ) || V_27 & V_34 ||
! ( V_16 -> V_35 & V_36 ) ) {
F_19 ( V_7 -> V_31 , V_29 ) ;
F_8 ( V_7 ) ;
return - V_37 ;
}
if ( ! ( V_27 & V_38 ) ) {
F_19 ( V_7 -> V_31 , V_29 ) ;
F_8 ( V_7 ) ;
return - V_39 ;
}
if ( ! ( V_27 & V_40 ) )
V_25 += V_16 -> V_41 ;
V_30 = V_16 -> V_41 ;
if ( V_30 > V_42 ) {
if ( F_20 () )
F_21 ( V_7 ,
L_2
L_3 ,
V_16 -> V_41 , V_42 ) ;
V_30 = V_42 ;
}
for ( V_2 = 0 ; V_2 < V_30 ; V_2 += 4 ) {
V_28 = F_2 ( V_25 + V_2 ) ;
V_12 [ V_2 ] = V_28 & 0xff ;
V_12 [ V_2 + 1 ] = ( V_28 >> 8 ) & 0xff ;
V_12 [ V_2 + 2 ] = ( V_28 >> 16 ) & 0xff ;
V_12 [ V_2 + 3 ] = ( V_28 >> 24 ) & 0xff ;
}
F_19 ( V_7 -> V_31 , V_29 ) ;
F_8 ( V_7 ) ;
return V_2 ;
}
static T_3 F_22 ( struct V_9 * V_8 ,
struct V_10 * V_11 ,
const char * V_12 , T_4 V_43 )
{
struct V_13 * V_14 = F_11 ( V_8 ) ;
struct V_6 * V_7 = F_12 ( V_14 ) ;
struct V_15 * V_16 = V_7 -> V_17 -> V_18 ;
void T_1 * V_1 = V_16 -> V_1 ;
void T_1 * V_25 = V_1 + V_16 -> V_26 ;
const unsigned char * V_44 = V_12 ;
T_2 V_27 , V_28 ;
unsigned long V_29 ;
int V_2 ;
if ( ! ( V_7 -> V_29 & V_33 ) ||
! ( V_16 -> V_35 & V_36 ) ||
V_43 % 4 || V_43 > V_16 -> V_41 )
return - V_37 ;
F_6 ( V_7 ) ;
F_18 ( V_7 -> V_31 , V_29 ) ;
V_27 = F_2 ( V_1 + V_32 ) ;
if ( V_27 & V_45 ) {
F_19 ( V_7 -> V_31 , V_29 ) ;
F_8 ( V_7 ) ;
return - V_46 ;
}
for ( V_2 = 0 ; V_2 < V_43 ; V_2 += 4 ) {
V_28 = V_44 [ V_2 ] | V_44 [ V_2 + 1 ] << 8 |
V_44 [ V_2 + 2 ] << 16 | V_44 [ V_2 + 3 ] << 24 ;
F_3 ( V_28 , V_25 + V_2 ) ;
}
F_3 ( V_27 | V_45 , V_1 + V_32 ) ;
F_19 ( V_7 -> V_31 , V_29 ) ;
F_8 ( V_7 ) ;
return V_43 ;
}
static T_3 F_23 ( struct V_9 * V_8 ,
struct V_10 * V_11 , char * V_12 )
{
struct V_13 * V_14 = F_11 ( V_8 ) ;
struct V_6 * V_7 = F_12 ( V_14 ) ;
struct V_15 * V_16 = V_7 -> V_17 -> V_18 ;
void T_1 * V_1 = V_16 -> V_1 ;
T_2 V_27 ;
F_6 ( V_7 ) ;
V_27 = F_2 ( V_1 + V_32 ) ;
F_8 ( V_7 ) ;
return sprintf ( V_12 , L_4 ,
V_27 & V_47 ? L_5 : L_6 ,
V_27 & V_48 ? L_7 : L_6 ,
V_27 & V_49 ? L_8 : L_6 ,
V_27 & V_50 ? L_9 : L_6 ) ;
}
void F_24 ( struct V_9 * V_8 , struct V_15 * V_16 )
{
void T_1 * V_1 = V_16 -> V_1 ;
T_2 V_19 , V_20 , V_51 , V_52 ;
int V_2 ;
F_1 ( V_1 ) ;
V_16 -> V_53 = V_19 = F_2 ( V_1 + V_54 ) ;
V_16 -> V_55 = V_52 = F_2 ( V_1 + V_56 ) ;
V_51 = F_2 ( V_1 + V_57 ) ;
if ( ( V_51 >> 16 ) > 1 ||
( ( V_51 >> 16 ) == 1 && ( V_51 & 0xFFFF ) >= 0x200 ) )
V_16 -> V_58 = V_20 = F_2 ( V_1 + V_59 ) ;
else
V_16 -> V_58 = V_20 = 0 ;
if ( ( V_19 & V_60 ) && ( V_16 -> V_29 & V_61 ) ) {
F_25 ( V_8 , L_10 ) ;
V_19 &= ~ V_60 ;
}
if ( ( V_19 & V_62 ) && ( V_16 -> V_29 & V_63 ) ) {
F_25 ( V_8 , L_11 ) ;
V_19 &= ~ V_62 ;
}
if ( ! ( V_19 & V_62 ) && ( V_16 -> V_29 & V_64 ) ) {
F_25 ( V_8 , L_12 ) ;
V_19 |= V_62 ;
}
if ( ( V_19 & V_65 ) && ( V_16 -> V_29 & V_66 ) ) {
F_25 ( V_8 , L_13 ) ;
V_19 &= ~ V_65 ;
}
if ( ( V_19 & V_67 ) && ( V_16 -> V_29 & V_68 ) ) {
F_25 ( V_8 ,
L_14 ) ;
V_19 &= ~ V_67 ;
}
if ( ( V_20 & V_69 ) && ( V_16 -> V_29 & V_70 ) ) {
F_25 ( V_8 ,
L_15 ) ;
V_20 &= ~ V_69 ;
V_20 &= ~ V_71 ;
}
if ( ! ( V_19 & V_72 ) && ( V_16 -> V_29 & V_73 ) ) {
F_25 ( V_8 , L_16 ) ;
V_19 |= V_72 ;
}
if ( ( V_19 & V_72 ) && ( V_16 -> V_29 & V_74 ) ) {
F_25 ( V_8 , L_17 ) ;
V_19 &= ~ V_72 ;
}
if ( ! ( V_19 & V_75 ) && ( V_16 -> V_29 & V_76 ) ) {
F_25 ( V_8 , L_18 ) ;
V_19 |= V_75 ;
}
if ( V_16 -> V_77 && V_52 != V_16 -> V_77 ) {
F_25 ( V_8 , L_19 ,
V_52 , V_16 -> V_77 ) ;
V_52 = V_16 -> V_77 ;
V_16 -> V_55 = V_52 ;
}
if ( V_16 -> V_78 ) {
F_26 ( V_8 , L_20 ,
V_52 ,
V_52 & V_16 -> V_78 ) ;
V_52 &= V_16 -> V_78 ;
}
if ( V_52 ) {
int V_79 = 0 ;
for ( V_2 = 0 ; V_2 < V_80 ; V_2 ++ )
if ( V_52 & ( 1 << V_2 ) )
V_79 ++ ;
if ( V_79 > F_27 ( V_19 ) ) {
F_26 ( V_8 ,
L_21 ,
V_52 , F_27 ( V_19 ) ) ;
V_52 = 0 ;
}
}
if ( ! V_52 && V_51 < 0x10300 ) {
V_52 = ( 1 << F_27 ( V_19 ) ) - 1 ;
F_26 ( V_8 , L_22 , V_52 ) ;
V_16 -> V_55 = V_52 ;
}
V_16 -> V_19 = V_19 ;
V_16 -> V_20 = V_20 ;
V_16 -> V_21 = F_2 ( V_1 + V_57 ) ;
V_16 -> V_52 = V_52 ;
if ( ! V_16 -> V_81 )
V_16 -> V_81 = V_82 ;
if ( ! V_16 -> V_83 )
V_16 -> V_83 = V_84 ;
}
static void F_28 ( struct V_85 * V_17 )
{
struct V_15 * V_16 = V_17 -> V_18 ;
void T_1 * V_1 = V_16 -> V_1 ;
F_3 ( V_16 -> V_53 , V_1 + V_54 ) ;
if ( V_16 -> V_58 )
F_3 ( V_16 -> V_58 , V_1 + V_59 ) ;
F_3 ( V_16 -> V_55 , V_1 + V_56 ) ;
( void ) F_2 ( V_1 + V_56 ) ;
}
static unsigned F_29 ( struct V_6 * V_7 , unsigned int V_86 )
{
static const int V_87 [] = {
[ V_88 ] = V_89 ,
[ V_90 ] = V_91 ,
[ V_92 ] = V_93 ,
[ V_94 ] = V_95 ,
[ V_96 ] = V_97 ,
} ;
struct V_15 * V_16 = V_7 -> V_17 -> V_18 ;
if ( V_86 < F_30 ( V_87 ) &&
( V_86 != V_96 || ( V_16 -> V_19 & V_67 ) ) )
return V_87 [ V_86 ] ;
return 0 ;
}
static int F_31 ( struct V_98 * V_99 , unsigned int V_86 , T_2 * V_100 )
{
void T_1 * V_22 = F_16 ( V_99 -> V_7 ) ;
int V_87 = F_29 ( V_99 -> V_7 , V_86 ) ;
if ( V_87 ) {
* V_100 = F_2 ( V_22 + V_87 ) ;
return 0 ;
}
return - V_37 ;
}
static int F_32 ( struct V_98 * V_99 , unsigned int V_86 , T_2 V_100 )
{
void T_1 * V_22 = F_16 ( V_99 -> V_7 ) ;
int V_87 = F_29 ( V_99 -> V_7 , V_86 ) ;
if ( V_87 ) {
F_3 ( V_100 , V_22 + V_87 ) ;
return 0 ;
}
return - V_37 ;
}
void V_82 ( struct V_6 * V_7 )
{
void T_1 * V_22 = F_16 ( V_7 ) ;
T_2 V_3 ;
V_3 = F_2 ( V_22 + V_24 ) ;
V_3 |= V_101 ;
F_3 ( V_3 , V_22 + V_24 ) ;
F_2 ( V_22 + V_24 ) ;
}
int F_33 ( struct V_6 * V_7 )
{
void T_1 * V_22 = F_16 ( V_7 ) ;
struct V_15 * V_16 = V_7 -> V_17 -> V_18 ;
T_2 V_3 ;
if ( ( V_16 -> V_29 & V_102 ) &&
( V_7 -> V_99 . V_103 > V_104 ) &&
F_34 ( & V_7 -> V_99 , V_104 , V_105 ) ) {
F_35 ( V_7 -> V_17 -> V_8 , L_23 ) ;
return - V_106 ;
}
V_3 = F_2 ( V_22 + V_24 ) ;
if ( ( V_3 & ( V_101 | V_107 ) ) == 0 )
return 0 ;
V_3 &= ~ V_101 ;
F_3 ( V_3 , V_22 + V_24 ) ;
V_3 = F_36 ( V_7 , V_22 + V_24 ,
V_107 , V_107 , 1 , 500 ) ;
if ( V_3 & V_107 )
return - V_106 ;
return 0 ;
}
void F_37 ( struct V_6 * V_7 )
{
void T_1 * V_22 = F_16 ( V_7 ) ;
struct V_15 * V_16 = V_7 -> V_17 -> V_18 ;
struct V_108 * V_109 = V_7 -> V_18 ;
T_2 V_3 ;
if ( V_16 -> V_19 & V_60 )
F_3 ( ( V_109 -> V_110 >> 16 ) >> 16 ,
V_22 + V_111 ) ;
F_3 ( V_109 -> V_110 & 0xffffffff , V_22 + V_112 ) ;
if ( V_16 -> V_19 & V_60 )
F_3 ( ( V_109 -> V_113 >> 16 ) >> 16 ,
V_22 + V_114 ) ;
F_3 ( V_109 -> V_113 & 0xffffffff , V_22 + V_115 ) ;
V_3 = F_2 ( V_22 + V_24 ) ;
V_3 |= V_116 ;
F_3 ( V_3 , V_22 + V_24 ) ;
F_2 ( V_22 + V_24 ) ;
}
static int F_38 ( struct V_6 * V_7 )
{
void T_1 * V_22 = F_16 ( V_7 ) ;
T_2 V_3 ;
V_3 = F_2 ( V_22 + V_24 ) ;
V_3 &= ~ V_116 ;
F_3 ( V_3 , V_22 + V_24 ) ;
V_3 = F_36 ( V_7 , V_22 + V_24 , V_117 ,
V_117 , 10 , 1000 ) ;
if ( V_3 & V_117 )
return - V_46 ;
return 0 ;
}
static void F_39 ( struct V_6 * V_7 )
{
struct V_15 * V_16 = V_7 -> V_17 -> V_18 ;
void T_1 * V_22 = F_16 ( V_7 ) ;
T_2 V_118 ;
V_118 = F_2 ( V_22 + V_24 ) & ~ V_119 ;
if ( V_16 -> V_19 & V_120 ) {
V_118 |= V_121 ;
F_3 ( V_118 , V_22 + V_24 ) ;
}
F_3 ( V_118 | V_122 , V_22 + V_24 ) ;
}
static int F_34 ( struct V_98 * V_99 , enum V_123 V_124 ,
unsigned int V_125 )
{
struct V_6 * V_7 = V_99 -> V_7 ;
struct V_15 * V_16 = V_7 -> V_17 -> V_18 ;
struct V_108 * V_109 = V_7 -> V_18 ;
void T_1 * V_22 = F_16 ( V_7 ) ;
if ( V_124 != V_104 ) {
V_125 &= ~ V_105 ;
V_109 -> V_126 &= ~ V_127 ;
F_3 ( V_109 -> V_126 , V_22 + V_128 ) ;
F_40 ( V_99 , V_124 , false ) ;
}
if ( V_16 -> V_19 & V_75 ) {
T_2 V_118 = F_2 ( V_22 + V_24 ) ;
if ( V_124 == V_104 || ! ( V_125 & V_129 ) ) {
if ( ! ( V_125 & V_105 ) )
V_118 &= ~ ( V_130 | V_131 ) ;
V_118 |= V_122 ;
F_3 ( V_118 , V_22 + V_24 ) ;
F_2 ( V_22 + V_24 ) ;
F_41 ( V_7 , 10 ) ;
if ( V_125 & V_105 )
return 0 ;
} else {
V_118 |= V_131 ;
if ( V_124 == V_132 )
V_118 |= V_130 ;
F_3 ( V_118 , V_22 + V_24 ) ;
}
}
if ( ( V_16 -> V_20 & V_69 ) &&
( V_16 -> V_20 & V_71 ) &&
( V_99 -> V_9 -> V_29 & V_133 ) ) {
if ( V_124 == V_132 )
F_42 ( V_7 , true ) ;
else
F_42 ( V_7 , false ) ;
}
if ( V_124 == V_104 ) {
F_40 ( V_99 , V_124 , false ) ;
V_109 -> V_126 |= V_127 ;
F_3 ( V_109 -> V_126 , V_22 + V_128 ) ;
}
return 0 ;
}
static void F_43 ( struct V_6 * V_7 )
{
struct V_15 * V_16 = V_7 -> V_17 -> V_18 ;
void T_1 * V_22 = F_16 ( V_7 ) ;
T_2 V_118 , V_134 ;
if ( ! ( V_16 -> V_19 & V_120 ) )
return;
V_134 = F_2 ( V_22 + V_91 ) ;
V_134 &= ~ 0xf ;
F_3 ( V_134 , V_22 + V_91 ) ;
V_118 = F_2 ( V_22 + V_24 ) & ~ V_119 ;
V_118 &= ~ V_121 ;
F_3 ( V_118 , V_22 + V_24 ) ;
}
static void F_44 ( struct V_6 * V_7 )
{
struct V_15 * V_16 = V_7 -> V_17 -> V_18 ;
struct V_108 * V_109 = V_7 -> V_18 ;
struct V_98 * V_99 ;
struct V_135 * V_136 ;
T_3 V_137 ;
int V_2 ;
F_37 ( V_7 ) ;
if ( ! ( V_16 -> V_29 & V_138 ) )
V_16 -> V_81 ( V_7 ) ;
if ( V_7 -> V_29 & V_33 ) {
F_45 (link, ap, EDGE) {
V_136 = & V_109 -> V_139 [ V_99 -> V_140 ] ;
for ( V_2 = 0 ; V_2 < V_141 ; V_2 ++ ) {
V_137 = V_7 -> V_142 -> V_143 ( V_7 ,
V_136 -> V_144 ,
4 ) ;
if ( V_137 == - V_46 )
F_4 ( 1 ) ;
else
break;
}
}
}
if ( V_7 -> V_29 & V_145 )
F_45 (link, ap, EDGE)
F_46 ( V_99 ) ;
}
static int F_47 ( struct V_6 * V_7 , const char * * V_146 )
{
int V_137 ;
V_137 = F_33 ( V_7 ) ;
if ( V_137 ) {
* V_146 = L_24 ;
return V_137 ;
}
V_137 = F_38 ( V_7 ) ;
if ( V_137 ) {
* V_146 = L_25 ;
return V_137 ;
}
return 0 ;
}
int F_48 ( struct V_85 * V_17 )
{
struct V_15 * V_16 = V_17 -> V_18 ;
void T_1 * V_1 = V_16 -> V_1 ;
T_2 V_3 ;
F_1 ( V_1 ) ;
if ( ! V_147 ) {
V_3 = F_2 ( V_1 + V_4 ) ;
if ( ( V_3 & V_148 ) == 0 ) {
F_3 ( V_3 | V_148 , V_1 + V_4 ) ;
F_2 ( V_1 + V_4 ) ;
}
V_3 = F_36 ( NULL , V_1 + V_4 , V_148 ,
V_148 , 10 , 1000 ) ;
if ( V_3 & V_148 ) {
F_35 ( V_17 -> V_8 , L_26 ,
V_3 ) ;
return - V_106 ;
}
F_1 ( V_1 ) ;
if ( ! ( V_16 -> V_29 & V_149 ) )
F_28 ( V_17 ) ;
} else
F_25 ( V_17 -> V_8 , L_27 ) ;
return 0 ;
}
static void F_49 ( struct V_98 * V_99 )
{
struct V_6 * V_7 = V_99 -> V_7 ;
struct V_108 * V_109 = V_7 -> V_18 ;
struct V_135 * V_136 = & V_109 -> V_139 [ V_99 -> V_140 ] ;
if ( ! ( V_99 -> V_29 & V_150 ) )
return;
V_136 -> V_151 ++ ;
if ( ! F_50 ( & V_136 -> V_152 ) )
F_51 ( & V_136 -> V_152 , V_153 + F_52 ( 10 ) ) ;
}
static void F_53 ( unsigned long V_154 )
{
struct V_98 * V_99 = (struct V_98 * ) V_154 ;
struct V_6 * V_7 = V_99 -> V_7 ;
struct V_108 * V_109 = V_7 -> V_18 ;
struct V_135 * V_136 = & V_109 -> V_139 [ V_99 -> V_140 ] ;
unsigned long V_155 = V_136 -> V_144 ;
T_2 V_156 ;
unsigned long V_29 ;
V_155 &= V_157 ;
V_155 |= V_7 -> V_158 | ( V_99 -> V_140 << 8 ) ;
F_18 ( V_7 -> V_31 , V_29 ) ;
if ( V_136 -> V_159 != V_136 -> V_151 ) {
V_136 -> V_159 = V_136 -> V_151 ;
V_156 = V_155 & V_160 ;
if ( V_156 )
V_156 = 0 ;
else
V_156 = 1 ;
V_155 &= ~ V_161 ;
V_155 |= ( V_156 << 16 ) ;
F_51 ( & V_136 -> V_152 , V_153 + F_52 ( 100 ) ) ;
} else {
V_155 &= ~ V_161 ;
if ( V_136 -> V_162 == V_163 )
V_155 |= ( 1 << 16 ) ;
}
F_19 ( V_7 -> V_31 , V_29 ) ;
V_7 -> V_142 -> V_143 ( V_7 , V_155 , 4 ) ;
}
static void F_46 ( struct V_98 * V_99 )
{
struct V_6 * V_7 = V_99 -> V_7 ;
struct V_108 * V_109 = V_7 -> V_18 ;
struct V_135 * V_136 = & V_109 -> V_139 [ V_99 -> V_140 ] ;
V_136 -> V_159 = V_136 -> V_151 = 0 ;
F_54 ( & V_136 -> V_152 , F_53 , ( unsigned long ) V_99 ) ;
if ( V_136 -> V_162 )
V_99 -> V_29 |= V_150 ;
}
int F_55 ( struct V_85 * V_17 )
{
struct V_15 * V_16 = V_17 -> V_18 ;
void T_1 * V_1 = V_16 -> V_1 ;
T_2 V_27 ;
V_27 = F_2 ( V_1 + V_32 ) ;
if ( ( V_27 & V_45 ) || ( V_27 & V_164 ) )
return - V_37 ;
F_3 ( V_27 | V_164 , V_1 + V_32 ) ;
return 0 ;
}
static T_3 F_56 ( struct V_6 * V_7 , T_2 V_165 ,
T_3 V_43 )
{
struct V_15 * V_16 = V_7 -> V_17 -> V_18 ;
struct V_108 * V_109 = V_7 -> V_18 ;
void T_1 * V_1 = V_16 -> V_1 ;
T_2 V_27 ;
T_2 V_166 [] = { 0 , 0 } ;
unsigned long V_29 ;
int V_140 ;
struct V_135 * V_136 ;
V_140 = ( V_165 & V_167 ) >> 8 ;
if ( V_140 < V_168 )
V_136 = & V_109 -> V_139 [ V_140 ] ;
else
return - V_37 ;
F_6 ( V_7 ) ;
F_18 ( V_7 -> V_31 , V_29 ) ;
V_27 = F_2 ( V_1 + V_32 ) ;
if ( V_27 & V_45 ) {
F_19 ( V_7 -> V_31 , V_29 ) ;
F_8 ( V_7 ) ;
return - V_46 ;
}
if ( V_16 -> V_35 & V_169 ) {
V_166 [ 0 ] |= ( 4 << 8 ) ;
V_166 [ 1 ] = ( ( V_165 & ~ V_170 ) | V_7 -> V_158 ) ;
F_3 ( V_166 [ 0 ] , V_1 + V_16 -> V_26 ) ;
F_3 ( V_166 [ 1 ] , V_1 + V_16 -> V_26 + 4 ) ;
F_3 ( V_27 | V_45 , V_1 + V_32 ) ;
}
V_136 -> V_144 = V_165 ;
F_19 ( V_7 -> V_31 , V_29 ) ;
F_8 ( V_7 ) ;
return V_43 ;
}
static T_3 F_57 ( struct V_6 * V_7 , char * V_12 )
{
struct V_108 * V_109 = V_7 -> V_18 ;
struct V_98 * V_99 ;
struct V_135 * V_136 ;
int V_137 = 0 ;
F_45 (link, ap, EDGE) {
V_136 = & V_109 -> V_139 [ V_99 -> V_140 ] ;
V_137 += sprintf ( V_12 , L_28 , V_136 -> V_144 ) ;
}
return V_137 ;
}
static T_3 F_58 ( struct V_6 * V_7 , const char * V_12 ,
T_4 V_43 )
{
unsigned int V_165 ;
int V_140 ;
struct V_108 * V_109 = V_7 -> V_18 ;
struct V_135 * V_136 ;
if ( F_59 ( V_12 , 0 , & V_165 ) < 0 )
return - V_37 ;
V_140 = ( V_165 & V_167 ) >> 8 ;
if ( V_140 < V_168 )
V_136 = & V_109 -> V_139 [ V_140 ] ;
else
return - V_37 ;
if ( V_136 -> V_162 )
V_165 &= ~ V_161 ;
return V_7 -> V_142 -> V_143 ( V_7 , V_165 , V_43 ) ;
}
static T_3 F_60 ( struct V_171 * V_8 , enum V_172 V_100 )
{
struct V_98 * V_99 = V_8 -> V_99 ;
struct V_6 * V_7 = V_99 -> V_7 ;
struct V_108 * V_109 = V_7 -> V_18 ;
struct V_135 * V_136 = & V_109 -> V_139 [ V_99 -> V_140 ] ;
T_2 V_173 = V_136 -> V_144 ;
if ( V_100 == V_174 ) {
V_99 -> V_29 &= ~ ( V_150 ) ;
V_173 &= V_175 ;
V_173 |= ( V_7 -> V_158 | ( V_99 -> V_140 << 8 ) ) ;
V_7 -> V_142 -> V_143 ( V_7 , V_173 , 4 ) ;
} else {
V_99 -> V_29 |= V_150 ;
if ( V_100 == V_163 ) {
V_173 &= V_175 ;
V_173 |= ( V_7 -> V_158 | ( V_99 -> V_140 << 8 ) ) ;
V_173 |= V_160 ;
V_7 -> V_142 -> V_143 ( V_7 , V_173 , 4 ) ;
}
}
V_136 -> V_162 = V_100 ;
return 0 ;
}
static T_3 F_61 ( struct V_171 * V_8 , char * V_12 )
{
struct V_98 * V_99 = V_8 -> V_99 ;
struct V_6 * V_7 = V_99 -> V_7 ;
struct V_108 * V_109 = V_7 -> V_18 ;
struct V_135 * V_136 = & V_109 -> V_139 [ V_99 -> V_140 ] ;
return sprintf ( V_12 , L_29 , V_136 -> V_162 ) ;
}
static void F_62 ( struct V_9 * V_8 , struct V_6 * V_7 ,
int V_158 , void T_1 * V_1 ,
void T_1 * V_22 )
{
struct V_15 * V_16 = V_7 -> V_17 -> V_18 ;
const char * V_146 = NULL ;
int V_137 ;
T_2 V_3 ;
V_137 = F_47 ( V_7 , & V_146 ) ;
if ( V_137 )
F_26 ( V_8 , L_30 , V_146 , V_137 ) ;
V_3 = F_2 ( V_22 + V_93 ) ;
F_63 ( L_31 , V_3 ) ;
F_3 ( V_3 , V_22 + V_93 ) ;
V_3 = F_2 ( V_22 + V_176 ) ;
F_63 ( L_32 , V_3 ) ;
if ( V_3 )
F_3 ( V_3 , V_22 + V_176 ) ;
F_3 ( 1 << V_158 , V_1 + V_177 ) ;
V_3 = F_2 ( V_22 + V_24 ) ;
if ( ( V_3 & V_178 ) && ( V_16 -> V_19 & V_179 ) )
V_7 -> V_180 |= V_181 ;
}
void F_64 ( struct V_85 * V_17 )
{
struct V_15 * V_16 = V_17 -> V_18 ;
void T_1 * V_1 = V_16 -> V_1 ;
int V_2 ;
void T_1 * V_22 ;
T_2 V_3 ;
for ( V_2 = 0 ; V_2 < V_17 -> V_182 ; V_2 ++ ) {
struct V_6 * V_7 = V_17 -> V_183 [ V_2 ] ;
V_22 = F_16 ( V_7 ) ;
if ( F_65 ( V_7 ) )
continue;
F_62 ( V_17 -> V_8 , V_7 , V_2 , V_1 , V_22 ) ;
}
V_3 = F_2 ( V_1 + V_4 ) ;
F_63 ( L_33 , V_3 ) ;
F_3 ( V_3 | V_184 , V_1 + V_4 ) ;
V_3 = F_2 ( V_1 + V_4 ) ;
F_63 ( L_33 , V_3 ) ;
}
static void F_66 ( struct V_171 * V_8 )
{
struct V_15 * V_16 = V_8 -> V_99 -> V_7 -> V_17 -> V_18 ;
if ( V_16 -> V_29 & V_185 ) {
V_8 -> V_186 = 255 ;
F_67 ( V_8 ,
L_34 ) ;
}
}
unsigned int F_68 ( struct V_6 * V_7 )
{
void T_1 * V_22 = F_16 ( V_7 ) ;
struct V_187 V_188 ;
T_2 V_3 ;
V_3 = F_2 ( V_22 + V_189 ) ;
V_188 . V_190 = ( V_3 >> 24 ) & 0xff ;
V_188 . V_191 = ( V_3 >> 16 ) & 0xff ;
V_188 . V_192 = ( V_3 >> 8 ) & 0xff ;
V_188 . V_193 = ( V_3 ) & 0xff ;
return F_69 ( & V_188 ) ;
}
void F_70 ( struct V_108 * V_109 , unsigned int V_194 ,
T_2 V_195 )
{
T_5 V_196 ;
V_196 = V_109 -> V_196 + V_194 * V_197 ;
V_109 -> V_198 [ V_194 ] . V_195 = F_71 ( V_195 ) ;
V_109 -> V_198 [ V_194 ] . V_199 = 0 ;
V_109 -> V_198 [ V_194 ] . V_200 = F_71 ( V_196 & 0xffffffff ) ;
V_109 -> V_198 [ V_194 ] . V_201 = F_71 ( ( V_196 >> 16 ) >> 16 ) ;
}
int F_72 ( struct V_6 * V_7 )
{
void T_1 * V_22 = F_16 ( V_7 ) ;
struct V_15 * V_16 = V_7 -> V_17 -> V_18 ;
T_6 V_199 = F_2 ( V_22 + V_202 ) & 0xFF ;
T_2 V_3 ;
int V_203 , V_137 ;
V_137 = F_33 ( V_7 ) ;
if ( V_137 )
goto V_204;
V_203 = V_199 & ( V_205 | V_206 ) ;
if ( ! V_203 && ! F_73 ( V_7 ) ) {
V_137 = 0 ;
goto V_204;
}
if ( ! ( V_16 -> V_19 & V_207 ) ) {
V_137 = - V_208 ;
goto V_204;
}
V_3 = F_2 ( V_22 + V_24 ) ;
V_3 |= V_209 ;
F_3 ( V_3 , V_22 + V_24 ) ;
V_137 = 0 ;
V_3 = F_36 ( V_7 , V_22 + V_24 ,
V_209 , V_209 , 1 , 500 ) ;
if ( V_3 & V_209 )
V_137 = - V_106 ;
V_204:
V_16 -> V_81 ( V_7 ) ;
return V_137 ;
}
static int F_74 ( struct V_6 * V_7 , int V_140 ,
struct V_187 * V_188 , int V_210 , T_7 V_29 ,
unsigned long V_211 )
{
const T_2 V_212 = 5 ;
struct V_108 * V_109 = V_7 -> V_18 ;
void T_1 * V_22 = F_16 ( V_7 ) ;
T_6 * V_213 = V_109 -> V_214 ;
T_2 V_3 ;
F_75 ( V_188 , V_140 , V_210 , V_213 ) ;
F_70 ( V_109 , 0 , V_212 | V_29 | ( V_140 << 12 ) ) ;
if ( V_109 -> V_215 && V_109 -> V_216 != V_140 ) {
V_3 = F_2 ( V_22 + V_217 ) ;
V_3 &= ~ ( V_218 | V_219 ) ;
V_3 |= V_140 << V_220 ;
F_3 ( V_3 , V_22 + V_217 ) ;
V_109 -> V_216 = V_140 ;
}
F_3 ( 1 , V_22 + V_221 ) ;
if ( V_211 ) {
V_3 = F_36 ( V_7 , V_22 + V_221 ,
0x1 , 0x1 , 1 , V_211 ) ;
if ( V_3 & 0x1 ) {
F_72 ( V_7 ) ;
return - V_46 ;
}
} else
F_2 ( V_22 + V_221 ) ;
return 0 ;
}
int F_76 ( struct V_98 * V_99 , unsigned int * V_222 ,
int V_140 , unsigned long V_223 ,
int (* F_77)( struct V_98 * V_99 ) )
{
struct V_6 * V_7 = V_99 -> V_7 ;
struct V_15 * V_16 = V_7 -> V_17 -> V_18 ;
struct V_108 * V_109 = V_7 -> V_18 ;
const char * V_224 = NULL ;
unsigned long V_225 , V_226 ;
struct V_187 V_188 ;
bool V_227 = false ;
int V_137 ;
F_78 ( L_35 ) ;
V_137 = F_72 ( V_7 ) ;
if ( V_137 && V_137 != - V_208 )
F_79 ( V_99 , L_36 , V_137 ) ;
if ( ! F_80 ( V_99 ) && V_109 -> V_215 ) {
F_81 ( V_7 ) ;
V_227 = true ;
}
F_82 ( V_99 -> V_9 , & V_188 ) ;
V_226 = 0 ;
V_225 = V_153 ;
if ( F_83 ( V_223 , V_225 ) )
V_226 = F_84 ( V_223 - V_225 ) ;
V_188 . V_228 |= V_229 ;
if ( F_74 ( V_7 , V_140 , & V_188 , 0 ,
V_230 | V_231 , V_226 ) ) {
V_137 = - V_106 ;
V_224 = L_37 ;
goto V_232;
}
F_41 ( V_7 , 1 ) ;
V_188 . V_228 &= ~ V_229 ;
F_74 ( V_7 , V_140 , & V_188 , 0 , 0 , 0 ) ;
V_137 = F_85 ( V_99 , V_223 , F_77 ) ;
if ( V_137 == - V_46 && V_16 -> V_29 & V_233 ) {
F_86 ( V_99 , L_38 ) ;
* V_222 = V_234 ;
} else if ( V_137 ) {
V_224 = L_39 ;
goto V_232;
} else
* V_222 = F_68 ( V_7 ) ;
if ( V_227 )
F_87 ( V_7 ) ;
F_78 ( L_40 , * V_222 ) ;
return 0 ;
V_232:
F_88 ( V_99 , L_41 , V_224 ) ;
return V_137 ;
}
int F_89 ( struct V_98 * V_99 )
{
void T_1 * V_22 = F_16 ( V_99 -> V_7 ) ;
T_6 V_199 = F_2 ( V_22 + V_202 ) & 0xFF ;
return F_90 ( V_199 ) ;
}
static int F_91 ( struct V_98 * V_99 , unsigned int * V_222 ,
unsigned long V_223 )
{
int V_140 = F_92 ( V_99 ) ;
F_78 ( L_35 ) ;
return F_76 ( V_99 , V_222 , V_140 , V_223 , F_89 ) ;
}
static int F_93 ( struct V_98 * V_99 )
{
void T_1 * V_22 = F_16 ( V_99 -> V_7 ) ;
T_6 V_199 = F_2 ( V_22 + V_202 ) & 0xFF ;
T_2 V_235 = F_2 ( V_22 + V_176 ) ;
if ( V_235 & V_236 )
return - V_106 ;
return F_90 ( V_199 ) ;
}
static int F_94 ( struct V_98 * V_99 , unsigned int * V_222 ,
unsigned long V_223 )
{
struct V_6 * V_7 = V_99 -> V_7 ;
void T_1 * V_22 = F_16 ( V_7 ) ;
int V_140 = F_92 ( V_99 ) ;
int V_137 ;
T_2 V_237 ;
F_78 ( L_35 ) ;
V_137 = F_76 ( V_99 , V_222 , V_140 , V_223 ,
F_93 ) ;
if ( V_137 == - V_106 ) {
V_237 = F_2 ( V_22 + V_176 ) ;
if ( V_237 & V_236 ) {
F_79 ( V_99 ,
L_42
L_43 ) ;
V_137 = F_76 ( V_99 , V_222 , 0 , V_223 ,
F_89 ) ;
}
}
return V_137 ;
}
int F_95 ( struct V_98 * V_99 , unsigned int * V_222 ,
unsigned long V_223 , bool * V_238 )
{
const unsigned long * V_239 = F_96 ( & V_99 -> V_240 ) ;
struct V_6 * V_7 = V_99 -> V_7 ;
struct V_108 * V_109 = V_7 -> V_18 ;
struct V_15 * V_16 = V_7 -> V_17 -> V_18 ;
T_6 * V_241 = V_109 -> V_242 + V_243 ;
struct V_187 V_188 ;
int V_137 ;
F_78 ( L_35 ) ;
F_33 ( V_7 ) ;
F_82 ( V_99 -> V_9 , & V_188 ) ;
V_188 . V_244 = V_205 ;
F_75 ( & V_188 , 0 , 0 , V_241 ) ;
V_137 = F_97 ( V_99 , V_239 , V_223 , V_238 ,
F_89 ) ;
V_16 -> V_81 ( V_7 ) ;
if ( * V_238 )
* V_222 = F_68 ( V_7 ) ;
F_78 ( L_44 , V_137 , * V_222 ) ;
return V_137 ;
}
static int F_98 ( struct V_98 * V_99 , unsigned int * V_222 ,
unsigned long V_223 )
{
bool V_238 ;
return F_95 ( V_99 , V_222 , V_223 , & V_238 ) ;
}
static void F_99 ( struct V_98 * V_99 , unsigned int * V_222 )
{
struct V_6 * V_7 = V_99 -> V_7 ;
void T_1 * V_22 = F_16 ( V_7 ) ;
T_2 V_245 , V_3 ;
F_100 ( V_99 , V_222 ) ;
V_245 = V_3 = F_2 ( V_22 + V_24 ) ;
if ( * V_222 == V_246 )
V_245 |= V_247 ;
else
V_245 &= ~ V_247 ;
if ( V_245 != V_3 ) {
F_3 ( V_245 , V_22 + V_24 ) ;
F_2 ( V_22 + V_24 ) ;
}
}
static unsigned int F_101 ( struct V_248 * V_249 , void * V_214 )
{
struct V_250 * V_251 ;
struct V_252 * V_252 = V_214 + V_253 ;
unsigned int V_254 ;
F_63 ( L_35 ) ;
F_102 (qc->sg, sg, qc->n_elem, si) {
T_5 V_255 = F_103 ( V_251 ) ;
T_2 V_256 = F_104 ( V_251 ) ;
V_252 [ V_254 ] . V_255 = F_71 ( V_255 & 0xffffffff ) ;
V_252 [ V_254 ] . V_257 = F_71 ( ( V_255 >> 16 ) >> 16 ) ;
V_252 [ V_254 ] . V_258 = F_71 ( V_256 - 1 ) ;
}
return V_254 ;
}
static int F_105 ( struct V_248 * V_249 )
{
struct V_6 * V_7 = V_249 -> V_7 ;
struct V_108 * V_109 = V_7 -> V_18 ;
if ( ! F_73 ( V_7 ) || V_109 -> V_215 )
return F_106 ( V_249 ) ;
else
return F_107 ( V_249 ) ;
}
static void F_108 ( struct V_248 * V_249 )
{
struct V_6 * V_7 = V_249 -> V_7 ;
struct V_108 * V_109 = V_7 -> V_18 ;
int V_259 = F_109 ( V_249 -> V_188 . V_260 ) ;
void * V_214 ;
T_2 V_195 ;
const T_2 V_212 = 5 ;
unsigned int V_261 ;
V_214 = V_109 -> V_214 + V_249 -> V_194 * V_197 ;
F_75 ( & V_249 -> V_188 , V_249 -> V_8 -> V_99 -> V_140 , 1 , V_214 ) ;
if ( V_259 ) {
memset ( V_214 + V_262 , 0 , 32 ) ;
memcpy ( V_214 + V_262 , V_249 -> V_263 , V_249 -> V_8 -> V_264 ) ;
}
V_261 = 0 ;
if ( V_249 -> V_29 & V_265 )
V_261 = F_101 ( V_249 , V_214 ) ;
V_195 = V_212 | V_261 << 16 | ( V_249 -> V_8 -> V_99 -> V_140 << 12 ) ;
if ( V_249 -> V_188 . V_29 & V_266 )
V_195 |= V_267 ;
if ( V_259 )
V_195 |= V_268 | V_269 ;
F_70 ( V_109 , V_249 -> V_194 , V_195 ) ;
}
static void F_110 ( struct V_6 * V_7 )
{
struct V_108 * V_109 = V_7 -> V_18 ;
void T_1 * V_22 = F_16 ( V_7 ) ;
T_2 V_270 = F_2 ( V_22 + V_217 ) ;
int V_271 = 3 ;
F_78 ( L_35 ) ;
F_111 ( ! V_109 -> V_215 ) ;
F_3 ( V_270 | V_219 , V_22 + V_217 ) ;
V_270 = F_2 ( V_22 + V_217 ) ;
while ( ( V_270 & V_219 ) && V_271 -- ) {
F_112 ( 1 ) ;
V_270 = F_2 ( V_22 + V_217 ) ;
}
if ( V_270 & V_219 )
F_35 ( V_7 -> V_17 -> V_8 , L_45 ) ;
}
static void F_113 ( struct V_6 * V_7 , T_2 V_272 )
{
struct V_15 * V_16 = V_7 -> V_17 -> V_18 ;
struct V_108 * V_109 = V_7 -> V_18 ;
struct V_273 * V_274 = & V_7 -> V_99 . V_275 ;
struct V_98 * V_99 = NULL ;
struct V_248 * V_276 ;
struct V_273 * V_277 ;
bool V_278 = false ;
T_2 V_279 ;
if ( V_109 -> V_215 ) {
void T_1 * V_22 = F_16 ( V_7 ) ;
T_2 V_270 = F_2 ( V_22 + V_217 ) ;
int V_140 = V_270 >> V_280 ;
if ( ( V_270 & V_281 ) && ( V_140 < V_7 -> V_282 ) ) {
V_99 = & V_7 -> V_283 [ V_140 ] ;
V_278 = true ;
}
} else
F_45 (link, ap, EDGE)
if ( F_114 ( V_99 ) )
break;
if ( ! V_99 )
V_99 = & V_7 -> V_99 ;
V_276 = F_115 ( V_7 , V_99 -> V_284 ) ;
V_277 = & V_99 -> V_275 ;
F_116 ( V_274 ) ;
F_117 ( V_274 , L_46 , V_272 ) ;
F_31 ( & V_7 -> V_99 , V_92 , & V_279 ) ;
F_32 ( & V_7 -> V_99 , V_92 , V_279 ) ;
V_274 -> V_279 |= V_279 ;
if ( V_16 -> V_29 & V_285 )
V_272 &= ~ V_286 ;
if ( V_272 & V_287 ) {
if ( V_276 )
V_276 -> V_288 |= V_289 ;
else
V_277 -> V_288 |= V_289 ;
if ( V_16 -> V_29 & V_290 )
V_274 -> V_279 &= ~ V_291 ;
}
if ( V_272 & V_292 ) {
T_2 * V_293 = V_109 -> V_242 + V_294 ;
V_277 -> V_288 |= V_295 ;
V_277 -> V_296 |= V_297 ;
F_117 ( V_277 ,
L_47 ,
V_293 [ 0 ] , V_293 [ 1 ] , V_293 [ 2 ] , V_293 [ 3 ] ) ;
}
if ( F_73 ( V_7 ) && ( V_272 & V_236 ) ) {
V_277 -> V_288 |= V_295 ;
V_277 -> V_296 |= V_297 ;
F_117 ( V_277 , L_48 ) ;
}
if ( V_272 & ( V_298 | V_299 ) ) {
V_274 -> V_288 |= V_300 ;
V_274 -> V_296 |= V_297 ;
F_117 ( V_274 , L_49 ) ;
}
if ( V_272 & V_286 ) {
if ( V_278 )
V_277 -> V_288 |= V_289 ;
else {
V_274 -> V_288 |= V_301 ;
V_274 -> V_296 |= V_297 ;
}
F_117 ( V_274 , L_50 ) ;
}
if ( V_272 & ( V_302 | V_127 ) ) {
F_118 ( V_274 ) ;
F_117 ( V_274 , L_51 ,
V_272 & V_302 ?
L_52 : L_53 ) ;
}
if ( V_272 & V_303 )
F_119 ( V_7 ) ;
else if ( V_278 ) {
F_120 ( V_99 ) ;
F_110 ( V_7 ) ;
} else
F_121 ( V_7 ) ;
}
static void F_122 ( struct V_6 * V_7 ,
void T_1 * V_22 , T_2 V_199 )
{
struct V_273 * V_304 = & V_7 -> V_99 . V_275 ;
struct V_108 * V_109 = V_7 -> V_18 ;
struct V_15 * V_16 = V_7 -> V_17 -> V_18 ;
int V_305 = ! ! ( V_7 -> V_180 & V_306 ) ;
T_2 V_307 = 0 ;
int V_137 ;
if ( F_123 ( V_305 ) )
V_199 &= ~ V_236 ;
if ( F_124 ( & V_7 -> V_99 ) ) {
V_199 &= ~ V_127 ;
F_32 ( & V_7 -> V_99 , V_92 , V_308 ) ;
}
if ( F_123 ( V_199 & V_309 ) ) {
F_113 ( V_7 , V_199 ) ;
return;
}
if ( V_199 & V_310 ) {
if ( V_16 -> V_19 & V_67 )
F_125 ( V_7 ) ;
else {
if ( V_109 -> V_215 )
F_126 ( 1 ) ;
else {
const T_8 * V_311 = V_109 -> V_242 + V_312 ;
T_2 V_313 = F_127 ( V_311 [ 0 ] ) ;
if ( V_313 & ( 1 << 15 ) )
F_125 ( V_7 ) ;
}
}
}
if ( V_109 -> V_215 ) {
if ( V_7 -> V_307 ) {
V_307 = F_2 ( V_22 + V_95 ) ;
V_307 |= F_2 ( V_22 + V_221 ) ;
}
} else {
if ( V_7 -> V_307 && V_109 -> V_314 -> V_315 )
V_307 = F_2 ( V_22 + V_95 ) ;
else
V_307 = F_2 ( V_22 + V_221 ) ;
}
V_137 = F_128 ( V_7 , V_307 ) ;
if ( F_123 ( V_137 < 0 && ! V_305 ) ) {
V_304 -> V_288 |= V_295 ;
V_304 -> V_296 |= V_297 ;
F_119 ( V_7 ) ;
}
}
static void F_129 ( struct V_6 * V_7 )
{
void T_1 * V_22 = F_16 ( V_7 ) ;
T_2 V_199 ;
V_199 = F_2 ( V_22 + V_176 ) ;
F_3 ( V_199 , V_22 + V_176 ) ;
F_122 ( V_7 , V_22 , V_199 ) ;
}
static T_9 F_130 ( int V_316 , void * V_317 )
{
struct V_6 * V_7 = V_317 ;
void T_1 * V_22 = F_16 ( V_7 ) ;
T_2 V_199 ;
F_63 ( L_35 ) ;
V_199 = F_2 ( V_22 + V_176 ) ;
F_3 ( V_199 , V_22 + V_176 ) ;
F_131 ( V_7 -> V_31 ) ;
F_122 ( V_7 , V_22 , V_199 ) ;
F_132 ( V_7 -> V_31 ) ;
F_63 ( L_54 ) ;
return V_318 ;
}
T_2 F_133 ( struct V_85 * V_17 , T_2 V_319 )
{
unsigned int V_2 , V_320 = 0 ;
for ( V_2 = 0 ; V_2 < V_17 -> V_182 ; V_2 ++ ) {
struct V_6 * V_7 ;
if ( ! ( V_319 & ( 1 << V_2 ) ) )
continue;
V_7 = V_17 -> V_183 [ V_2 ] ;
if ( V_7 ) {
F_129 ( V_7 ) ;
F_63 ( L_55 , V_2 ) ;
} else {
F_63 ( L_56 , V_2 ) ;
if ( F_134 () )
F_26 ( V_17 -> V_8 ,
L_57 , V_2 ) ;
}
V_320 = 1 ;
}
return V_320 ;
}
static T_9 V_84 ( int V_316 , void * V_317 )
{
struct V_85 * V_17 = V_317 ;
struct V_15 * V_16 ;
unsigned int V_137 = 0 ;
void T_1 * V_1 ;
T_2 V_272 , V_319 ;
F_63 ( L_35 ) ;
V_16 = V_17 -> V_18 ;
V_1 = V_16 -> V_1 ;
V_272 = F_2 ( V_1 + V_177 ) ;
if ( ! V_272 )
return V_321 ;
V_319 = V_272 & V_16 -> V_52 ;
F_131 ( & V_17 -> V_31 ) ;
V_137 = F_133 ( V_17 , V_319 ) ;
F_3 ( V_272 , V_1 + V_177 ) ;
F_132 ( & V_17 -> V_31 ) ;
F_63 ( L_54 ) ;
return F_135 ( V_137 ) ;
}
unsigned int F_136 ( struct V_248 * V_249 )
{
struct V_6 * V_7 = V_249 -> V_7 ;
void T_1 * V_22 = F_16 ( V_7 ) ;
struct V_108 * V_109 = V_7 -> V_18 ;
V_109 -> V_314 = V_249 -> V_8 -> V_99 ;
if ( F_137 ( V_249 -> V_188 . V_260 ) )
F_3 ( 1 << V_249 -> V_194 , V_22 + V_95 ) ;
if ( V_109 -> V_215 && V_109 -> V_216 != V_249 -> V_8 -> V_99 -> V_140 ) {
T_2 V_270 = F_2 ( V_22 + V_217 ) ;
V_270 &= ~ ( V_218 | V_219 ) ;
V_270 |= V_249 -> V_8 -> V_99 -> V_140 << V_220 ;
F_3 ( V_270 , V_22 + V_217 ) ;
V_109 -> V_216 = V_249 -> V_8 -> V_99 -> V_140 ;
}
F_3 ( 1 << V_249 -> V_194 , V_22 + V_221 ) ;
F_49 ( V_249 -> V_8 -> V_99 ) ;
return 0 ;
}
static bool F_138 ( struct V_248 * V_249 )
{
struct V_108 * V_109 = V_249 -> V_7 -> V_18 ;
T_6 * V_242 = V_109 -> V_242 ;
if ( V_109 -> V_215 )
V_242 += V_249 -> V_8 -> V_99 -> V_140 * V_322 ;
if ( V_249 -> V_188 . V_260 == V_323 && V_249 -> V_324 == V_325 &&
! ( V_249 -> V_29 & V_326 ) ) {
F_139 ( V_242 + V_327 , & V_249 -> V_328 ) ;
V_249 -> V_328 . V_244 = ( V_242 + V_327 ) [ 15 ] ;
} else
F_139 ( V_242 + V_243 , & V_249 -> V_328 ) ;
return true ;
}
static void F_140 ( struct V_6 * V_7 )
{
void T_1 * V_22 = F_16 ( V_7 ) ;
F_3 ( 0 , V_22 + V_128 ) ;
}
static void F_141 ( struct V_6 * V_7 )
{
struct V_15 * V_16 = V_7 -> V_17 -> V_18 ;
void T_1 * V_1 = V_16 -> V_1 ;
void T_1 * V_22 = F_16 ( V_7 ) ;
T_2 V_3 ;
struct V_108 * V_109 = V_7 -> V_18 ;
V_3 = F_2 ( V_22 + V_176 ) ;
F_3 ( V_3 , V_22 + V_176 ) ;
F_3 ( 1 << V_7 -> V_158 , V_1 + V_177 ) ;
F_3 ( V_109 -> V_126 , V_22 + V_128 ) ;
}
void F_142 ( struct V_6 * V_7 )
{
struct V_15 * V_16 = V_7 -> V_17 -> V_18 ;
if ( ! ( V_7 -> V_180 & V_329 ) ) {
F_33 ( V_7 ) ;
V_16 -> V_81 ( V_7 ) ;
}
F_143 ( V_7 ) ;
if ( ! F_144 ( V_7 -> V_99 . V_9 ) )
F_33 ( V_7 ) ;
}
static void F_145 ( struct V_248 * V_249 )
{
struct V_6 * V_7 = V_249 -> V_7 ;
if ( V_249 -> V_29 & V_326 )
F_72 ( V_7 ) ;
}
static void F_42 ( struct V_6 * V_7 , bool V_330 )
{
struct V_15 * V_16 = V_7 -> V_17 -> V_18 ;
void T_1 * V_22 = F_16 ( V_7 ) ;
struct V_171 * V_8 = V_7 -> V_99 . V_9 ;
T_2 V_331 , V_332 , V_333 , V_334 , V_335 ;
int V_137 ;
unsigned int V_288 ;
V_331 = F_2 ( V_22 + V_336 ) ;
if ( ! ( V_331 & V_337 ) ) {
F_25 ( V_7 -> V_17 -> V_8 , L_58 ) ;
return;
}
if ( ! V_330 ) {
if ( V_331 & V_338 ) {
F_3 ( V_331 & ~ V_338 ,
V_22 + V_336 ) ;
V_288 = F_146 ( V_8 ,
V_339 ,
V_340 ) ;
if ( V_288 && V_288 != V_289 )
F_147 ( V_8 , L_59 ) ;
}
return;
}
if ( V_331 & V_338 )
return;
V_137 = F_33 ( V_7 ) ;
if ( V_137 )
return;
V_332 = ( V_331 & V_341 ) >> V_342 ;
V_333 = V_343 / ( V_332 + 1 ) ;
if ( V_333 > 0x3ff )
V_333 = 0x3ff ;
if ( V_8 -> V_344 [ V_345 ] &
V_346 ) {
V_334 = V_8 -> V_344 [ V_347 ] &
V_348 ;
if ( ! V_334 )
V_334 = 10 ;
V_335 = V_8 -> V_344 [ V_349 ] ;
if ( ! V_335 )
V_335 = 20 ;
} else {
V_334 = 10 ;
V_335 = 20 ;
}
V_331 |= ( ( V_333 << V_350 ) |
( V_334 << V_351 ) |
( V_335 << V_352 ) |
V_338 ) ;
F_3 ( V_331 , V_22 + V_336 ) ;
V_16 -> V_81 ( V_7 ) ;
V_288 = F_146 ( V_8 ,
V_353 ,
V_340 ) ;
if ( V_288 && V_288 != V_289 )
F_147 ( V_8 , L_60 ) ;
}
static void F_87 ( struct V_6 * V_7 )
{
struct V_15 * V_16 = V_7 -> V_17 -> V_18 ;
struct V_108 * V_109 = V_7 -> V_18 ;
void T_1 * V_22 = F_16 ( V_7 ) ;
T_2 V_270 ;
int V_137 ;
if ( ! V_109 -> V_354 )
return;
V_270 = F_2 ( V_22 + V_217 ) ;
if ( V_270 & V_355 ) {
V_109 -> V_215 = true ;
V_109 -> V_216 = - 1 ;
return;
}
V_137 = F_33 ( V_7 ) ;
if ( V_137 )
return;
F_3 ( V_270 | V_355 , V_22 + V_217 ) ;
V_270 = F_2 ( V_22 + V_217 ) ;
if ( V_270 & V_355 ) {
F_25 ( V_7 -> V_17 -> V_8 , L_61 ) ;
V_109 -> V_215 = true ;
V_109 -> V_216 = - 1 ;
} else
F_35 ( V_7 -> V_17 -> V_8 , L_62 ) ;
V_16 -> V_81 ( V_7 ) ;
}
static void F_81 ( struct V_6 * V_7 )
{
struct V_15 * V_16 = V_7 -> V_17 -> V_18 ;
struct V_108 * V_109 = V_7 -> V_18 ;
void T_1 * V_22 = F_16 ( V_7 ) ;
T_2 V_270 ;
int V_137 ;
if ( ! V_109 -> V_354 )
return;
V_270 = F_2 ( V_22 + V_217 ) ;
if ( ( V_270 & V_355 ) == 0 ) {
V_109 -> V_215 = false ;
return;
}
V_137 = F_33 ( V_7 ) ;
if ( V_137 )
return;
F_3 ( V_270 & ~ V_355 , V_22 + V_217 ) ;
V_270 = F_2 ( V_22 + V_217 ) ;
if ( V_270 & V_355 )
F_35 ( V_7 -> V_17 -> V_8 , L_63 ) ;
else {
F_25 ( V_7 -> V_17 -> V_8 , L_64 ) ;
V_109 -> V_215 = false ;
}
V_16 -> V_81 ( V_7 ) ;
}
static void F_148 ( struct V_6 * V_7 )
{
void T_1 * V_22 = F_16 ( V_7 ) ;
struct V_108 * V_109 = V_7 -> V_18 ;
T_2 V_118 ;
V_118 = F_2 ( V_22 + V_24 ) ;
V_118 |= V_356 ;
F_3 ( V_118 , V_22 + V_24 ) ;
F_87 ( V_7 ) ;
V_109 -> V_126 |= V_236 ;
if ( ! ( V_7 -> V_180 & V_329 ) )
F_3 ( V_109 -> V_126 , V_22 + V_128 ) ;
}
static void F_149 ( struct V_6 * V_7 )
{
void T_1 * V_22 = F_16 ( V_7 ) ;
struct V_108 * V_109 = V_7 -> V_18 ;
T_2 V_118 ;
F_81 ( V_7 ) ;
V_118 = F_2 ( V_22 + V_24 ) ;
V_118 &= ~ V_356 ;
F_3 ( V_118 , V_22 + V_24 ) ;
V_109 -> V_126 &= ~ V_236 ;
if ( ! ( V_7 -> V_180 & V_329 ) )
F_3 ( V_109 -> V_126 , V_22 + V_128 ) ;
}
int F_150 ( struct V_6 * V_7 )
{
F_6 ( V_7 ) ;
F_39 ( V_7 ) ;
F_44 ( V_7 ) ;
if ( F_73 ( V_7 ) )
F_148 ( V_7 ) ;
else
F_149 ( V_7 ) ;
return 0 ;
}
static int F_151 ( struct V_6 * V_7 , T_10 V_357 )
{
const char * V_146 = NULL ;
int V_137 ;
V_137 = F_47 ( V_7 , & V_146 ) ;
if ( V_137 == 0 )
F_43 ( V_7 ) ;
else {
F_152 ( V_7 , L_30 , V_146 , V_137 ) ;
F_119 ( V_7 ) ;
}
F_8 ( V_7 ) ;
return V_137 ;
}
static int F_153 ( struct V_6 * V_7 )
{
struct V_15 * V_16 = V_7 -> V_17 -> V_18 ;
struct V_9 * V_8 = V_7 -> V_17 -> V_8 ;
struct V_108 * V_109 ;
void * V_358 ;
T_5 V_359 ;
T_4 V_360 , V_361 ;
V_109 = F_154 ( V_8 , sizeof( * V_109 ) , V_362 ) ;
if ( ! V_109 )
return - V_363 ;
if ( V_7 -> V_17 -> V_182 > 1 ) {
V_109 -> V_364 = F_154 ( V_8 , 8 , V_362 ) ;
if ( ! V_109 -> V_364 ) {
F_155 ( V_8 , V_109 ) ;
return - V_363 ;
}
snprintf ( V_109 -> V_364 , 8 ,
L_65 , F_156 ( V_8 ) , V_7 -> V_158 ) ;
}
if ( ( V_16 -> V_19 & V_72 ) && F_157 ( V_7 ) ) {
void T_1 * V_22 = F_16 ( V_7 ) ;
T_2 V_118 = F_2 ( V_22 + V_24 ) ;
if ( V_118 & V_365 )
V_109 -> V_354 = true ;
else if ( V_16 -> V_29 & V_73 ) {
F_25 ( V_8 , L_66 ,
V_7 -> V_158 ) ;
V_109 -> V_354 = true ;
} else
F_26 ( V_8 , L_67 ,
V_7 -> V_158 ) ;
}
if ( V_109 -> V_354 ) {
V_360 = V_366 ;
V_361 = V_322 * 16 ;
} else {
V_360 = V_367 ;
V_361 = V_322 ;
}
V_358 = F_158 ( V_8 , V_360 , & V_359 , V_362 ) ;
if ( ! V_358 )
return - V_363 ;
memset ( V_358 , 0 , V_360 ) ;
V_109 -> V_198 = V_358 ;
V_109 -> V_110 = V_359 ;
V_358 += V_368 ;
V_359 += V_368 ;
V_109 -> V_242 = V_358 ;
V_109 -> V_113 = V_359 ;
V_358 += V_361 ;
V_359 += V_361 ;
V_109 -> V_214 = V_358 ;
V_109 -> V_196 = V_359 ;
V_109 -> V_126 = V_369 ;
if ( V_16 -> V_29 & V_370 ) {
F_159 ( & V_109 -> V_31 ) ;
V_7 -> V_31 = & V_109 -> V_31 ;
}
V_7 -> V_18 = V_109 ;
return F_150 ( V_7 ) ;
}
static void F_160 ( struct V_6 * V_7 )
{
const char * V_146 = NULL ;
struct V_15 * V_16 = V_7 -> V_17 -> V_18 ;
void T_1 * V_371 = V_16 -> V_1 ;
int V_137 ;
V_137 = F_47 ( V_7 , & V_146 ) ;
if ( V_137 )
F_21 ( V_7 , L_30 , V_146 , V_137 ) ;
F_3 ( 1 << V_7 -> V_158 , V_371 + V_177 ) ;
}
void F_161 ( struct V_85 * V_17 , const char * V_372 )
{
struct V_15 * V_16 = V_17 -> V_18 ;
T_2 V_51 , V_19 , V_20 , V_373 , V_374 ;
const char * V_375 ;
V_51 = V_16 -> V_21 ;
V_19 = V_16 -> V_19 ;
V_20 = V_16 -> V_20 ;
V_373 = V_16 -> V_52 ;
V_374 = ( V_19 >> 20 ) & 0xf ;
if ( V_374 == 1 )
V_375 = L_68 ;
else if ( V_374 == 2 )
V_375 = L_69 ;
else if ( V_374 == 3 )
V_375 = L_70 ;
else
V_375 = L_71 ;
F_25 ( V_17 -> V_8 ,
L_72
L_73
,
( V_51 >> 24 ) & 0xff ,
( V_51 >> 16 ) & 0xff ,
( V_51 >> 8 ) & 0xff ,
V_51 & 0xff ,
( ( V_19 >> 8 ) & 0x1f ) + 1 ,
( V_19 & 0x1f ) + 1 ,
V_375 ,
V_373 ,
V_372 ) ;
F_25 ( V_17 -> V_8 ,
L_74
L_75
L_75
L_75
L_76
,
V_19 & V_60 ? L_77 : L_6 ,
V_19 & V_62 ? L_78 : L_6 ,
V_19 & V_67 ? L_79 : L_6 ,
V_19 & V_376 ? L_80 : L_6 ,
V_19 & V_120 ? L_81 : L_6 ,
V_19 & V_75 ? L_82 : L_6 ,
V_19 & V_377 ? L_5 : L_6 ,
V_19 & V_207 ? L_83 : L_6 ,
V_19 & V_378 ? L_84 : L_6 ,
V_19 & V_65 ? L_85 : L_6 ,
V_19 & V_72 ? L_86 : L_6 ,
V_19 & V_379 ? L_87 : L_6 ,
V_19 & V_380 ? L_88 : L_6 ,
V_19 & V_381 ? L_89 : L_6 ,
V_19 & V_382 ? L_90 : L_6 ,
V_19 & V_383 ? L_91 : L_6 ,
V_19 & V_179 ? L_92 : L_6 ,
V_20 & V_384 ? L_93 : L_6 ,
V_20 & V_71 ? L_94 : L_6 ,
V_20 & V_69 ? L_95 : L_6 ,
V_20 & V_385 ? L_96 : L_6 ,
V_20 & V_386 ? L_97 : L_6 ,
V_20 & V_387 ? L_98 : L_6
) ;
}
void F_162 ( struct V_15 * V_16 ,
struct V_388 * V_389 )
{
T_6 V_390 ;
void T_1 * V_1 = V_16 -> V_1 ;
T_2 V_26 = F_2 ( V_1 + V_391 ) ;
T_2 V_27 = F_2 ( V_1 + V_32 ) ;
if ( ! V_392 || ! ( V_16 -> V_19 & V_383 ) )
return;
V_390 = ( V_27 & V_393 ) >> 16 ;
if ( V_390 ) {
V_16 -> V_26 = ( ( V_26 >> 16 ) * 4 ) ;
V_16 -> V_41 = ( ( V_26 & 0xff ) * 4 ) ;
V_16 -> V_35 = V_390 ;
V_389 -> V_29 |= V_33 ;
if ( ! ( V_27 & V_394 ) )
V_389 -> V_29 |= V_145 ;
}
}
static int F_163 ( struct V_85 * V_17 ,
struct V_395 * V_396 )
{
struct V_15 * V_16 = V_17 -> V_18 ;
int V_2 , V_137 ;
V_137 = F_164 ( V_17 ) ;
if ( V_137 )
return V_137 ;
for ( V_2 = 0 ; V_2 < V_17 -> V_182 ; V_2 ++ ) {
struct V_108 * V_109 = V_17 -> V_183 [ V_2 ] -> V_18 ;
int V_316 = V_16 -> V_397 ( V_17 , V_2 ) ;
if ( ! V_109 ) {
F_165 ( V_316 ) ;
continue;
}
V_137 = F_166 ( V_17 -> V_8 , V_316 , F_130 ,
0 , V_109 -> V_364 , V_17 -> V_183 [ V_2 ] ) ;
if ( V_137 )
return V_137 ;
F_167 ( V_17 -> V_183 [ V_2 ] , L_99 , V_316 ) ;
}
return F_168 ( V_17 , V_396 ) ;
}
int F_169 ( struct V_85 * V_17 , struct V_395 * V_396 )
{
struct V_15 * V_16 = V_17 -> V_18 ;
int V_316 = V_16 -> V_316 ;
int V_137 ;
if ( V_16 -> V_29 & V_370 ) {
if ( V_16 -> V_83 )
F_26 ( V_17 -> V_8 ,
L_100 ) ;
if ( ! V_16 -> V_397 ) {
F_35 ( V_17 -> V_8 ,
L_101 ) ;
return - V_106 ;
}
V_137 = F_163 ( V_17 , V_396 ) ;
} else {
V_137 = F_170 ( V_17 , V_316 , V_16 -> V_83 ,
V_398 , V_396 ) ;
}
return V_137 ;
}
