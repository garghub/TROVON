static int F_1 ( void T_1 * V_1 , const T_2 V_2 , bool V_3 )
{
unsigned long V_4 = V_5 + F_2 ( V_6 ) ;
T_2 V_7 ;
while ( 1 ) {
V_7 = F_3 ( V_1 ) ;
if ( V_3 )
V_7 = ~ V_7 ;
V_7 &= V_2 ;
if ( V_7 == V_2 )
return 0 ;
if ( F_4 ( V_5 , V_4 ) )
return - V_8 ;
}
}
static bool F_5 ( struct V_9 * V_10 )
{
T_2 V_1 = F_3 ( V_10 -> V_11 + V_12 ) ;
return V_1 & ( 1 << V_13 ) ;
}
static T_2 F_6 ( struct V_9 * V_10 )
{
T_2 V_1 = F_3 ( V_10 -> V_11 + V_14 ) ;
V_1 >>= V_15 ;
return V_1 & V_16 ;
}
static T_3 F_7 ( int V_17 , void * V_18 )
{
struct V_9 * V_10 = V_18 ;
unsigned int V_19 ;
V_19 = F_3 ( V_10 -> V_11 + V_20 ) ;
F_8 ( V_19 , V_10 -> V_11 + V_20 ) ;
V_19 &= V_21 | V_22 ;
if ( V_19 )
F_9 ( & V_10 -> V_23 ) ;
return V_24 ;
}
static unsigned int F_10 ( struct V_25 * V_26 , const T_4 V_27 )
{
struct V_28 * V_29 = V_26 -> V_30 ;
T_2 V_31 = 0 ;
V_31 |= V_29 -> V_32 << V_33 ;
V_31 |= V_29 -> V_34 << V_35 ;
V_31 |= V_29 -> V_36 << V_37 ;
return V_31 ;
}
static int F_11 ( struct V_9 * V_10 )
{
const unsigned int V_38 = 3 ;
unsigned int V_39 = 0 ;
unsigned long V_40 ;
V_40 = V_5 + F_2 ( V_6 ) ;
while ( 1 ) {
if ( F_5 ( V_10 ) )
V_39 ++ ;
else
V_39 = 0 ;
if ( V_39 >= V_38 )
return 0 ;
if ( F_4 ( V_5 , V_40 ) ) {
F_12 ( & V_10 -> V_41 -> V_18 ,
L_1 ,
V_6 ) ;
return - V_8 ;
}
F_13 () ;
}
}
static int F_14 ( struct V_9 * V_10 , unsigned int V_1 )
{
void T_1 * V_42 = V_10 -> V_11 ;
int V_43 ;
F_8 ( V_1 , V_42 + V_44 ) ;
V_1 |= V_45 ;
F_8 ( V_1 , V_42 + V_44 ) ;
V_43 = F_1 ( V_42 + V_44 ,
V_46 , 1 ) ;
if ( V_43 ) {
F_12 ( & V_10 -> V_41 -> V_18 ,
L_2 ) ;
return V_43 ;
}
return F_11 ( V_10 ) ;
}
static int F_15 ( struct V_25 * V_26 ,
const T_4 * V_47 , const unsigned V_48 ,
T_4 * V_49 , const unsigned V_50 )
{
struct V_28 * V_29 = V_26 -> V_30 ;
struct V_9 * V_10 = V_29 -> V_10 ;
void T_1 * V_42 = V_10 -> V_11 ;
unsigned int V_31 ;
unsigned int V_1 ;
unsigned int V_51 ;
int V_52 ;
if ( ! V_50 || V_50 > V_53 || ! V_49 ) {
F_12 ( V_26 -> V_18 , L_3 ,
V_50 , V_49 ) ;
return - V_54 ;
}
V_1 = V_47 [ 0 ] << V_55 ;
V_31 = F_10 ( V_26 , V_47 [ 0 ] ) ;
F_8 ( V_31 , V_42 + V_56 ) ;
V_1 |= ( 0x1 << V_57 ) ;
V_1 |= ( ( ( V_50 - 1 ) & V_58 )
<< V_59 ) ;
V_52 = F_14 ( V_10 , V_1 ) ;
if ( V_52 )
return V_52 ;
V_1 = F_3 ( V_42 + V_60 ) ;
V_51 = ( V_50 > 4 ) ? 4 : V_50 ;
memcpy ( V_49 , & V_1 , V_51 ) ;
V_49 += V_51 ;
if ( V_50 > 4 ) {
V_1 = F_3 ( V_42 + V_61 ) ;
V_51 = V_50 - V_51 ;
memcpy ( V_49 , & V_1 , V_51 ) ;
}
return 0 ;
}
static int F_16 ( struct V_25 * V_26 , const T_4 V_27 ,
const T_4 * V_47 , const unsigned V_48 )
{
struct V_28 * V_29 = V_26 -> V_30 ;
struct V_9 * V_10 = V_29 -> V_10 ;
void T_1 * V_42 = V_10 -> V_11 ;
unsigned int V_1 ;
unsigned int V_62 ;
int V_43 ;
if ( V_48 > 4 || ( V_48 && ! V_47 ) ) {
F_12 ( V_26 -> V_18 ,
L_4 ,
V_48 , V_47 ) ;
return - V_54 ;
}
V_1 = V_27 << V_55 ;
if ( V_48 ) {
V_1 |= ( 0x1 << V_63 ) ;
V_1 |= ( ( V_48 - 1 ) & V_64 )
<< V_65 ;
V_62 = 0 ;
memcpy ( & V_62 , V_47 , V_48 ) ;
F_8 ( V_62 , V_42 + V_66 ) ;
}
V_43 = F_14 ( V_10 , V_1 ) ;
return V_43 ;
}
static int F_17 ( struct V_25 * V_26 ,
const T_4 V_27 , const unsigned int V_67 )
{
struct V_28 * V_29 = V_26 -> V_30 ;
struct V_9 * V_10 = V_29 -> V_10 ;
void T_1 * V_42 = V_10 -> V_11 ;
unsigned int V_1 ;
V_1 = V_27 << V_55 ;
V_1 |= ( 0x1 << V_68 ) ;
V_1 |= ( ( V_26 -> V_34 - 1 ) & V_69 )
<< V_70 ;
F_8 ( V_67 , V_42 + V_71 ) ;
return F_14 ( V_10 , V_1 ) ;
}
static int F_18 ( struct V_25 * V_26 ,
const unsigned int V_72 )
{
struct V_28 * V_29 = V_26 -> V_30 ;
struct V_9 * V_10 = V_29 -> V_10 ;
void T_1 * V_42 = V_10 -> V_11 ;
unsigned int V_73 = 0 ;
unsigned int V_1 ;
F_8 ( V_72 , V_42 + V_74 ) ;
V_1 = V_26 -> V_75 << V_76 ;
V_1 |= F_10 ( V_26 , V_26 -> V_75 ) ;
V_73 = V_26 -> V_77 ;
if ( V_73 > V_78 )
V_73 = V_78 ;
if ( V_73 / 8 ) {
V_1 |= ( 1 << V_79 ) ;
F_8 ( 0xFF , V_42 + V_80 ) ;
if ( V_29 -> V_32 != V_81 )
V_73 -= 8 ;
if ( V_73 )
V_1 |= ( V_73 & V_82 )
<< V_83 ;
}
F_8 ( V_1 , V_42 + V_56 ) ;
V_1 = F_3 ( V_42 + V_84 ) ;
V_1 &= ~ V_85 ;
V_1 |= ( V_26 -> V_34 - 1 ) ;
F_8 ( V_1 , V_42 + V_84 ) ;
return 0 ;
}
static int F_19 ( struct V_25 * V_26 ,
T_4 * V_49 , const unsigned V_50 )
{
struct V_28 * V_29 = V_26 -> V_30 ;
struct V_9 * V_10 = V_29 -> V_10 ;
void T_1 * V_42 = V_10 -> V_11 ;
void T_1 * V_86 = V_10 -> V_86 ;
unsigned int V_87 = V_50 ;
unsigned int V_88 = 0 ;
int V_43 = 0 ;
F_8 ( V_87 , V_42 + V_89 ) ;
F_8 ( V_90 , V_42 + V_20 ) ;
F_8 ( V_21 , V_42 + V_91 ) ;
F_20 ( & V_10 -> V_23 ) ;
F_8 ( V_92 ,
V_42 + V_93 ) ;
while ( V_87 > 0 ) {
V_43 = F_21 ( & V_10 -> V_23 ,
F_2
( V_94 ) ) ;
V_88 = F_6 ( V_10 ) ;
if ( ! V_43 && V_88 == 0 ) {
F_12 ( V_26 -> V_18 , L_5 ) ;
V_43 = - V_8 ;
goto V_95;
}
while ( V_88 != 0 ) {
V_88 *= V_10 -> V_96 ;
V_88 = V_88 > V_87 ?
V_87 : V_88 ;
F_22 ( V_86 , V_49 , F_23 ( V_88 , 4 ) ) ;
V_49 += V_88 ;
V_87 -= V_88 ;
V_88 = F_6 ( V_10 ) ;
}
if ( V_87 > 0 )
F_20 ( & V_10 -> V_23 ) ;
}
V_43 = F_1 ( V_42 + V_93 ,
V_97 , 0 ) ;
if ( V_43 ) {
F_12 ( V_26 -> V_18 ,
L_6 , V_43 ) ;
goto V_95;
}
F_8 ( 0 , V_42 + V_91 ) ;
F_8 ( V_97 , V_42 + V_93 ) ;
return 0 ;
V_95:
F_8 ( 0 , V_42 + V_91 ) ;
F_8 ( V_98 ,
V_42 + V_93 ) ;
return V_43 ;
}
static int F_24 ( struct V_25 * V_26 ,
const unsigned int V_99 )
{
unsigned int V_1 ;
struct V_28 * V_29 = V_26 -> V_30 ;
struct V_9 * V_10 = V_29 -> V_10 ;
void T_1 * V_42 = V_10 -> V_11 ;
V_1 = V_26 -> V_100 << V_101 ;
F_8 ( V_1 , V_42 + V_102 ) ;
V_1 = F_10 ( V_26 , V_26 -> V_100 ) ;
F_8 ( V_1 , V_42 + V_56 ) ;
F_8 ( V_99 , V_42 + V_103 ) ;
V_1 = F_3 ( V_42 + V_84 ) ;
V_1 &= ~ V_85 ;
V_1 |= ( V_26 -> V_34 - 1 ) ;
F_8 ( V_1 , V_42 + V_84 ) ;
return 0 ;
}
static int F_25 ( struct V_25 * V_26 ,
const T_4 * V_47 , const unsigned V_48 )
{
const unsigned int V_104 = V_26 -> V_104 ;
struct V_28 * V_29 = V_26 -> V_30 ;
struct V_9 * V_10 = V_29 -> V_10 ;
void T_1 * V_42 = V_10 -> V_11 ;
unsigned int V_87 = V_48 ;
unsigned int V_105 ;
int V_43 ;
F_8 ( V_87 , V_42 + V_106 ) ;
F_8 ( V_90 , V_42 + V_20 ) ;
F_8 ( V_22 , V_42 + V_91 ) ;
F_20 ( & V_10 -> V_23 ) ;
F_8 ( V_107 ,
V_42 + V_108 ) ;
while ( V_87 > 0 ) {
V_105 = V_87 > V_104 ? V_104 : V_87 ;
F_26 ( V_10 -> V_86 , V_47 , F_23 ( V_105 , 4 ) ) ;
V_43 = F_21 ( & V_10 -> V_23 ,
F_2
( V_6 ) ) ;
if ( ! V_43 ) {
F_12 ( V_26 -> V_18 , L_7 ) ;
V_43 = - V_8 ;
goto V_109;
}
V_47 += V_105 ;
V_87 -= V_105 ;
if ( V_87 > 0 )
F_20 ( & V_10 -> V_23 ) ;
}
V_43 = F_1 ( V_42 + V_108 ,
V_110 , 0 ) ;
if ( V_43 ) {
F_12 ( V_26 -> V_18 ,
L_8 , V_43 ) ;
goto V_109;
}
F_8 ( 0 , V_42 + V_91 ) ;
F_8 ( V_110 , V_42 + V_108 ) ;
F_11 ( V_10 ) ;
return 0 ;
V_109:
F_8 ( 0 , V_42 + V_91 ) ;
F_8 ( V_98 ,
V_42 + V_108 ) ;
return V_43 ;
}
static void F_27 ( struct V_25 * V_26 )
{
struct V_28 * V_29 = V_26 -> V_30 ;
struct V_9 * V_10 = V_29 -> V_10 ;
void T_1 * V_42 = V_10 -> V_11 ;
unsigned int V_111 = V_29 -> V_112 ;
unsigned int V_1 ;
V_1 = F_3 ( V_42 + V_12 ) ;
if ( V_10 -> V_113 ) {
V_1 |= V_114 ;
} else {
V_1 &= ~ V_114 ;
V_111 = 0xF & ~ ( 1 << V_111 ) ;
}
V_1 &= ~ ( V_115
<< V_116 ) ;
V_1 |= ( V_111 & V_115 )
<< V_116 ;
F_8 ( V_1 , V_42 + V_12 ) ;
}
static void F_28 ( struct V_25 * V_26 )
{
struct V_28 * V_29 = V_26 -> V_30 ;
struct V_9 * V_10 = V_29 -> V_10 ;
void T_1 * V_11 = V_10 -> V_11 ;
unsigned int V_1 ;
V_1 = F_3 ( V_11 + V_84 ) ;
V_1 &= ~ ( V_117 << V_118 ) ;
V_1 &= ~ ( V_119 << V_120 ) ;
V_1 &= ~ V_85 ;
V_1 |= ( V_26 -> V_104 << V_118 ) ;
V_1 |= ( F_29 ( V_26 -> V_121 . V_122 ) << V_120 ) ;
V_1 |= ( V_26 -> V_34 - 1 ) ;
F_8 ( V_1 , V_11 + V_84 ) ;
F_27 ( V_26 ) ;
V_10 -> V_123 = V_26 -> V_104 ;
V_10 -> V_124 = V_26 -> V_121 . V_122 ;
V_10 -> V_125 = V_26 -> V_34 ;
}
static unsigned int F_30 ( const unsigned int V_126 ,
const unsigned int V_127 )
{
unsigned int V_128 ;
V_128 = V_126 / 1000 ;
V_128 = F_23 ( V_128 * V_127 , 1000000 ) ;
return V_128 ;
}
static void F_31 ( struct V_25 * V_26 )
{
struct V_28 * V_29 = V_26 -> V_30 ;
struct V_9 * V_10 = V_29 -> V_10 ;
void T_1 * V_11 = V_10 -> V_11 ;
const unsigned int V_126 = V_10 -> V_129 ;
unsigned int V_130 , V_131 , V_132 , V_133 ;
unsigned int V_1 ;
unsigned int V_134 ;
V_134 = F_23 ( V_126 , V_10 -> V_135 ) ;
V_130 = F_30 ( V_126 , V_29 -> V_136 ) ;
if ( V_130 < V_134 )
V_130 = V_134 ;
V_131 = F_30 ( V_126 , V_29 -> V_137 ) ;
V_132 = F_30 ( V_126 , V_29 -> V_138 ) ;
V_133 = F_30 ( V_126 , V_29 -> V_139 ) ;
V_1 = ( V_130 & V_140 )
<< V_141 ;
V_1 |= ( V_131 & V_142 )
<< V_143 ;
V_1 |= ( V_132 & V_144 )
<< V_145 ;
V_1 |= ( V_133 & V_146 )
<< V_147 ;
F_8 ( V_1 , V_11 + V_148 ) ;
}
static void F_32 ( struct V_9 * V_10 )
{
const unsigned int V_126 = V_10 -> V_129 ;
void T_1 * V_42 = V_10 -> V_11 ;
T_2 V_1 , div ;
div = F_23 ( V_126 , 2 * V_10 -> V_135 ) - 1 ;
V_1 = F_3 ( V_42 + V_12 ) ;
V_1 &= ~ ( V_149 << V_150 ) ;
V_1 |= ( div & V_149 ) << V_150 ;
F_8 ( V_1 , V_42 + V_12 ) ;
}
static void F_33 ( struct V_9 * V_10 ,
const unsigned int V_151 ,
const unsigned int V_152 )
{
void T_1 * V_42 = V_10 -> V_11 ;
unsigned int V_1 ;
V_1 = F_3 ( V_42 + V_153 ) ;
if ( V_151 )
V_1 |= ( 1 << V_154 ) ;
else
V_1 &= ~ ( 1 << V_154 ) ;
V_1 &= ~ ( V_155
<< V_156 ) ;
V_1 |= ( V_152 & V_155 )
<< V_156 ;
F_8 ( V_1 , V_42 + V_153 ) ;
}
static void F_34 ( struct V_9 * V_10 , bool V_157 )
{
void T_1 * V_42 = V_10 -> V_11 ;
unsigned int V_1 ;
V_1 = F_3 ( V_42 + V_12 ) ;
if ( V_157 )
V_1 |= V_158 ;
else
V_1 &= ~ V_158 ;
F_8 ( V_1 , V_42 + V_12 ) ;
}
static void F_35 ( struct V_25 * V_26 )
{
struct V_28 * V_29 = V_26 -> V_30 ;
struct V_9 * V_10 = V_29 -> V_10 ;
const unsigned int V_135 = V_29 -> V_159 ;
int V_160 = ( V_10 -> V_161 != V_29 -> V_112 ) ;
int V_162 = ( V_10 -> V_135 != V_135 ) ;
if ( ( V_10 -> V_123 != V_26 -> V_104 ) ||
( V_10 -> V_124 != V_26 -> V_121 . V_122 ) ||
( V_10 -> V_125 != V_26 -> V_34 ) )
V_160 = 1 ;
if ( V_160 || V_162 )
F_34 ( V_10 , 0 ) ;
if ( V_160 ) {
V_10 -> V_161 = V_29 -> V_112 ;
F_28 ( V_26 ) ;
}
if ( V_162 ) {
V_10 -> V_135 = V_135 ;
F_32 ( V_10 ) ;
F_31 ( V_26 ) ;
F_33 ( V_10 , 1 , V_29 -> V_163 ) ;
}
if ( V_160 || V_162 )
F_34 ( V_10 , 1 ) ;
}
static int F_36 ( struct V_25 * V_26 , const int V_164 )
{
struct V_28 * V_29 = V_26 -> V_30 ;
V_29 -> V_32 = V_165 ;
V_29 -> V_34 = V_165 ;
V_29 -> V_36 = V_165 ;
if ( V_164 ) {
switch ( V_26 -> V_166 ) {
case V_167 :
case V_168 :
V_29 -> V_36 = V_165 ;
break;
case V_169 :
V_29 -> V_36 = V_170 ;
break;
case V_171 :
V_29 -> V_36 = V_81 ;
break;
default:
return - V_54 ;
}
}
F_35 ( V_26 ) ;
return 0 ;
}
static T_5 F_37 ( struct V_25 * V_26 , T_6 V_172 ,
T_7 V_173 , const T_8 * V_174 )
{
int V_43 ;
V_43 = F_36 ( V_26 , 0 ) ;
if ( V_43 )
return V_43 ;
V_43 = F_24 ( V_26 , V_172 ) ;
if ( V_43 )
return V_43 ;
V_43 = F_25 ( V_26 , V_174 , V_173 ) ;
if ( V_43 )
return V_43 ;
return ( V_43 < 0 ) ? V_43 : V_173 ;
}
static T_5 F_38 ( struct V_25 * V_26 , T_6 V_175 ,
T_7 V_173 , T_8 * V_174 )
{
int V_43 ;
V_43 = F_36 ( V_26 , 1 ) ;
if ( V_43 )
return V_43 ;
V_43 = F_18 ( V_26 , V_175 ) ;
if ( V_43 )
return V_43 ;
V_43 = F_19 ( V_26 , V_174 , V_173 ) ;
if ( V_43 )
return V_43 ;
return ( V_43 < 0 ) ? V_43 : V_173 ;
}
static int F_39 ( struct V_25 * V_26 , T_6 V_176 )
{
int V_43 ;
V_43 = F_36 ( V_26 , 0 ) ;
if ( V_43 )
return V_43 ;
V_43 = V_26 -> V_177 ( V_26 , V_178 , NULL , 0 ) ;
if ( V_43 )
return V_43 ;
V_43 = F_17 ( V_26 , V_26 -> V_179 , V_176 ) ;
if ( V_43 )
return V_43 ;
return 0 ;
}
static int F_40 ( struct V_25 * V_26 , enum V_180 V_181 )
{
struct V_28 * V_29 = V_26 -> V_30 ;
struct V_9 * V_10 = V_29 -> V_10 ;
F_41 ( & V_10 -> V_182 ) ;
return 0 ;
}
static void F_42 ( struct V_25 * V_26 , enum V_180 V_181 )
{
struct V_28 * V_29 = V_26 -> V_30 ;
struct V_9 * V_10 = V_29 -> V_10 ;
F_43 ( & V_10 -> V_182 ) ;
}
static int F_44 ( struct V_25 * V_26 , T_4 V_27 , T_4 * V_174 , int V_173 )
{
int V_43 ;
V_43 = F_36 ( V_26 , 0 ) ;
if ( ! V_43 )
V_43 = F_15 ( V_26 , & V_27 , 1 , V_174 , V_173 ) ;
return V_43 ;
}
static int F_45 ( struct V_25 * V_26 , T_4 V_27 , T_4 * V_174 , int V_173 )
{
int V_43 ;
V_43 = F_36 ( V_26 , 0 ) ;
if ( ! V_43 )
V_43 = F_16 ( V_26 , V_27 , V_174 , V_173 ) ;
return V_43 ;
}
static int F_46 ( struct V_183 * V_41 ,
struct V_28 * V_29 ,
struct V_184 * V_185 )
{
if ( F_47 ( V_185 , L_9 , & V_29 -> V_163 ) ) {
F_12 ( & V_41 -> V_18 , L_10 ) ;
return - V_186 ;
}
if ( F_47 ( V_185 , L_11 , & V_29 -> V_136 ) ) {
F_12 ( & V_41 -> V_18 , L_12 ) ;
return - V_186 ;
}
if ( F_47 ( V_185 , L_13 , & V_29 -> V_139 ) ) {
F_12 ( & V_41 -> V_18 , L_14 ) ;
return - V_186 ;
}
if ( F_47 ( V_185 , L_15 , & V_29 -> V_137 ) ) {
F_12 ( & V_41 -> V_18 , L_16 ) ;
return - V_186 ;
}
if ( F_47 ( V_185 , L_17 , & V_29 -> V_138 ) ) {
F_12 ( & V_41 -> V_18 , L_18 ) ;
return - V_186 ;
}
if ( F_47 ( V_185 , L_19 , & V_29 -> V_159 ) ) {
F_12 ( & V_41 -> V_18 , L_20 ) ;
return - V_186 ;
}
return 0 ;
}
static int F_48 ( struct V_183 * V_41 )
{
struct V_184 * V_185 = V_41 -> V_18 . V_187 ;
struct V_9 * V_10 = F_49 ( V_41 ) ;
V_10 -> V_113 = F_50 ( V_185 , L_21 ) ;
if ( F_47 ( V_185 , L_22 , & V_10 -> V_188 ) ) {
F_12 ( & V_41 -> V_18 , L_23 ) ;
return - V_186 ;
}
if ( F_47 ( V_185 , L_24 , & V_10 -> V_96 ) ) {
F_12 ( & V_41 -> V_18 , L_25 ) ;
return - V_186 ;
}
if ( F_47 ( V_185 , L_26 ,
& V_10 -> V_189 ) ) {
F_12 ( & V_41 -> V_18 , L_27 ) ;
return - V_186 ;
}
return 0 ;
}
static void F_51 ( struct V_9 * V_10 )
{
F_34 ( V_10 , 0 ) ;
F_8 ( 0 , V_10 -> V_11 + V_190 ) ;
F_8 ( 0 , V_10 -> V_11 + V_91 ) ;
F_8 ( V_10 -> V_188 / 2 , V_10 -> V_11 + V_191 ) ;
F_8 ( V_10 -> V_189 ,
V_10 -> V_11 + V_192 ) ;
F_8 ( V_10 -> V_188 * V_10 -> V_96 / 2 ,
V_10 -> V_11 + V_193 ) ;
F_8 ( V_10 -> V_188 * V_10 -> V_96 / 8 ,
V_10 -> V_11 + V_194 ) ;
F_34 ( V_10 , 1 ) ;
}
static int F_52 ( struct V_9 * V_10 , struct V_184 * V_185 )
{
struct V_183 * V_41 = V_10 -> V_41 ;
struct V_195 * V_18 = & V_41 -> V_18 ;
struct V_28 * V_29 ;
struct V_25 * V_26 ;
struct V_196 * V_121 ;
unsigned int V_112 ;
int V_197 , V_43 ;
F_53 (dev->of_node, np) {
V_43 = F_47 ( V_185 , L_28 , & V_112 ) ;
if ( V_43 ) {
F_12 ( V_18 , L_29 ) ;
goto V_198;
}
if ( V_112 >= V_199 ) {
V_43 = - V_54 ;
F_12 ( V_18 , L_30 , V_112 ) ;
goto V_198;
}
V_29 = & V_10 -> V_29 [ V_112 ] ;
V_29 -> V_10 = V_10 ;
V_29 -> V_112 = V_112 ;
V_43 = F_46 ( V_41 , V_29 , V_185 ) ;
if ( V_43 )
goto V_198;
V_26 = & V_29 -> V_26 ;
V_121 = & V_26 -> V_121 ;
V_121 -> V_30 = V_26 ;
V_26 -> V_18 = V_18 ;
F_54 ( V_26 , V_185 ) ;
V_26 -> V_30 = V_29 ;
V_26 -> V_200 = F_44 ;
V_26 -> V_177 = F_45 ;
V_26 -> V_164 = F_38 ;
V_26 -> V_201 = F_37 ;
V_26 -> V_202 = F_39 ;
V_26 -> V_203 = F_40 ;
V_26 -> V_204 = F_42 ;
V_121 -> V_205 = F_55 ( V_18 , V_206 , L_31 ,
F_56 ( V_18 ) , V_112 ) ;
if ( ! V_121 -> V_205 ) {
V_43 = - V_207 ;
goto V_198;
}
V_43 = F_57 ( V_26 , NULL , V_171 ) ;
if ( V_43 )
goto V_198;
V_43 = F_58 ( V_121 , NULL , 0 ) ;
if ( V_43 )
goto V_198;
V_29 -> V_208 = true ;
}
return 0 ;
V_198:
for ( V_197 = 0 ; V_197 < V_199 ; V_197 ++ )
if ( V_10 -> V_29 [ V_197 ] . V_208 )
F_59 ( & V_10 -> V_29 [ V_197 ] . V_26 . V_121 ) ;
return V_43 ;
}
static int F_60 ( struct V_183 * V_41 )
{
struct V_184 * V_185 = V_41 -> V_18 . V_187 ;
struct V_195 * V_18 = & V_41 -> V_18 ;
struct V_9 * V_10 ;
struct V_209 * V_210 ;
struct V_209 * V_211 ;
int V_43 ;
int V_212 ;
V_10 = F_61 ( V_18 , sizeof( * V_10 ) , V_206 ) ;
if ( ! V_10 )
return - V_207 ;
F_62 ( & V_10 -> V_182 ) ;
V_10 -> V_41 = V_41 ;
F_63 ( V_41 , V_10 ) ;
V_43 = F_48 ( V_41 ) ;
if ( V_43 ) {
F_12 ( V_18 , L_32 ) ;
return - V_213 ;
}
V_10 -> V_214 = F_64 ( V_18 , NULL ) ;
if ( F_65 ( V_10 -> V_214 ) ) {
F_12 ( V_18 , L_33 ) ;
return F_66 ( V_10 -> V_214 ) ;
}
V_210 = F_67 ( V_41 , V_215 , 0 ) ;
V_10 -> V_11 = F_68 ( V_18 , V_210 ) ;
if ( F_65 ( V_10 -> V_11 ) ) {
F_12 ( V_18 , L_34 ) ;
return F_66 ( V_10 -> V_11 ) ;
}
V_211 = F_67 ( V_41 , V_215 , 1 ) ;
V_10 -> V_86 = F_68 ( V_18 , V_211 ) ;
if ( F_65 ( V_10 -> V_86 ) ) {
F_12 ( V_18 , L_35 ) ;
return F_66 ( V_10 -> V_86 ) ;
}
F_69 ( & V_10 -> V_23 ) ;
V_212 = F_70 ( V_41 , 0 ) ;
if ( V_212 < 0 ) {
F_12 ( V_18 , L_36 ) ;
return - V_186 ;
}
V_43 = F_71 ( V_10 -> V_214 ) ;
if ( V_43 ) {
F_12 ( V_18 , L_37 ) ;
return V_43 ;
}
V_10 -> V_129 = F_72 ( V_10 -> V_214 ) ;
V_43 = F_73 ( V_18 , V_212 , F_7 , 0 ,
V_41 -> V_205 , V_10 ) ;
if ( V_43 ) {
F_12 ( V_18 , L_38 ) ;
goto V_216;
}
F_11 ( V_10 ) ;
F_51 ( V_10 ) ;
V_10 -> V_161 = - 1 ;
V_10 -> V_135 = 0 ;
V_43 = F_52 ( V_10 , V_185 ) ;
if ( V_43 ) {
F_12 ( V_18 , L_39 , V_43 ) ;
goto V_217;
}
return V_43 ;
V_216:
F_34 ( V_10 , 0 ) ;
V_217:
F_74 ( V_10 -> V_214 ) ;
return V_43 ;
}
static int F_75 ( struct V_183 * V_41 )
{
struct V_9 * V_10 = F_49 ( V_41 ) ;
int V_197 ;
for ( V_197 = 0 ; V_197 < V_199 ; V_197 ++ )
if ( V_10 -> V_29 [ V_197 ] . V_208 )
F_59 ( & V_10 -> V_29 [ V_197 ] . V_26 . V_121 ) ;
F_34 ( V_10 , 0 ) ;
F_74 ( V_10 -> V_214 ) ;
return 0 ;
}
static int F_76 ( struct V_195 * V_18 )
{
struct V_9 * V_10 = F_77 ( V_18 ) ;
F_34 ( V_10 , 0 ) ;
return 0 ;
}
static int F_78 ( struct V_195 * V_18 )
{
struct V_9 * V_10 = F_77 ( V_18 ) ;
F_34 ( V_10 , 1 ) ;
return 0 ;
}
