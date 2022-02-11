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
F_22 ( V_86 , V_49 ,
F_23 ( V_88 , 4 ) ) ;
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
F_26 ( V_10 -> V_86 , V_47 ,
F_23 ( V_105 , 4 ) ) ;
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
V_29 -> V_36 = V_165 ;
break;
case V_168 :
V_29 -> V_36 = V_169 ;
break;
case V_170 :
V_29 -> V_36 = V_81 ;
break;
default:
return - V_54 ;
}
}
F_35 ( V_26 ) ;
return 0 ;
}
static T_5 F_37 ( struct V_25 * V_26 , T_6 V_171 ,
T_7 V_172 , const T_8 * V_173 )
{
int V_43 ;
V_43 = F_36 ( V_26 , 0 ) ;
if ( V_43 )
return V_43 ;
V_43 = F_24 ( V_26 , V_171 ) ;
if ( V_43 )
return V_43 ;
V_43 = F_25 ( V_26 , V_173 , V_172 ) ;
if ( V_43 )
return V_43 ;
return V_172 ;
}
static T_5 F_38 ( struct V_25 * V_26 , T_6 V_174 ,
T_7 V_172 , T_8 * V_173 )
{
int V_43 ;
V_43 = F_36 ( V_26 , 1 ) ;
if ( V_43 )
return V_43 ;
V_43 = F_18 ( V_26 , V_174 ) ;
if ( V_43 )
return V_43 ;
V_43 = F_19 ( V_26 , V_173 , V_172 ) ;
if ( V_43 )
return V_43 ;
return V_172 ;
}
static int F_39 ( struct V_25 * V_26 , T_6 V_175 )
{
int V_43 ;
V_43 = F_36 ( V_26 , 0 ) ;
if ( V_43 )
return V_43 ;
V_43 = V_26 -> V_176 ( V_26 , V_177 , NULL , 0 ) ;
if ( V_43 )
return V_43 ;
V_43 = F_17 ( V_26 , V_26 -> V_178 , V_175 ) ;
if ( V_43 )
return V_43 ;
return 0 ;
}
static int F_40 ( struct V_25 * V_26 , enum V_179 V_180 )
{
struct V_28 * V_29 = V_26 -> V_30 ;
struct V_9 * V_10 = V_29 -> V_10 ;
F_41 ( & V_10 -> V_181 ) ;
return 0 ;
}
static void F_42 ( struct V_25 * V_26 , enum V_179 V_180 )
{
struct V_28 * V_29 = V_26 -> V_30 ;
struct V_9 * V_10 = V_29 -> V_10 ;
F_43 ( & V_10 -> V_181 ) ;
}
static int F_44 ( struct V_25 * V_26 , T_4 V_27 , T_4 * V_173 , int V_172 )
{
int V_43 ;
V_43 = F_36 ( V_26 , 0 ) ;
if ( ! V_43 )
V_43 = F_15 ( V_26 , & V_27 , 1 , V_173 , V_172 ) ;
return V_43 ;
}
static int F_45 ( struct V_25 * V_26 , T_4 V_27 , T_4 * V_173 , int V_172 )
{
int V_43 ;
V_43 = F_36 ( V_26 , 0 ) ;
if ( ! V_43 )
V_43 = F_16 ( V_26 , V_27 , V_173 , V_172 ) ;
return V_43 ;
}
static int F_46 ( struct V_182 * V_41 ,
struct V_28 * V_29 ,
struct V_183 * V_184 )
{
if ( F_47 ( V_184 , L_9 , & V_29 -> V_163 ) ) {
F_12 ( & V_41 -> V_18 , L_10 ) ;
return - V_185 ;
}
if ( F_47 ( V_184 , L_11 , & V_29 -> V_136 ) ) {
F_12 ( & V_41 -> V_18 , L_12 ) ;
return - V_185 ;
}
if ( F_47 ( V_184 , L_13 , & V_29 -> V_139 ) ) {
F_12 ( & V_41 -> V_18 , L_14 ) ;
return - V_185 ;
}
if ( F_47 ( V_184 , L_15 , & V_29 -> V_137 ) ) {
F_12 ( & V_41 -> V_18 , L_16 ) ;
return - V_185 ;
}
if ( F_47 ( V_184 , L_17 , & V_29 -> V_138 ) ) {
F_12 ( & V_41 -> V_18 , L_18 ) ;
return - V_185 ;
}
if ( F_47 ( V_184 , L_19 , & V_29 -> V_159 ) ) {
F_12 ( & V_41 -> V_18 , L_20 ) ;
return - V_185 ;
}
return 0 ;
}
static int F_48 ( struct V_182 * V_41 )
{
struct V_183 * V_184 = V_41 -> V_18 . V_186 ;
struct V_9 * V_10 = F_49 ( V_41 ) ;
V_10 -> V_113 = F_50 ( V_184 , L_21 ) ;
if ( F_47 ( V_184 , L_22 , & V_10 -> V_187 ) ) {
F_12 ( & V_41 -> V_18 , L_23 ) ;
return - V_185 ;
}
if ( F_47 ( V_184 , L_24 , & V_10 -> V_96 ) ) {
F_12 ( & V_41 -> V_18 , L_25 ) ;
return - V_185 ;
}
if ( F_47 ( V_184 , L_26 ,
& V_10 -> V_188 ) ) {
F_12 ( & V_41 -> V_18 , L_27 ) ;
return - V_185 ;
}
return 0 ;
}
static void F_51 ( struct V_9 * V_10 )
{
F_34 ( V_10 , 0 ) ;
F_8 ( 0 , V_10 -> V_11 + V_189 ) ;
F_8 ( 0 , V_10 -> V_11 + V_91 ) ;
F_8 ( V_10 -> V_187 / 2 , V_10 -> V_11 + V_190 ) ;
F_8 ( V_10 -> V_188 ,
V_10 -> V_11 + V_191 ) ;
F_8 ( V_10 -> V_187 * V_10 -> V_96 / 2 ,
V_10 -> V_11 + V_192 ) ;
F_8 ( V_10 -> V_187 * V_10 -> V_96 / 8 ,
V_10 -> V_11 + V_193 ) ;
F_34 ( V_10 , 1 ) ;
}
static int F_52 ( struct V_9 * V_10 , struct V_183 * V_184 )
{
const struct V_194 V_195 = {
. V_2 = V_196 |
V_197 |
V_198 |
V_199 |
V_200 ,
} ;
struct V_182 * V_41 = V_10 -> V_41 ;
struct V_201 * V_18 = & V_41 -> V_18 ;
struct V_28 * V_29 ;
struct V_25 * V_26 ;
struct V_202 * V_121 ;
unsigned int V_112 ;
int V_203 , V_43 ;
F_53 (dev->of_node, np) {
V_43 = F_47 ( V_184 , L_28 , & V_112 ) ;
if ( V_43 ) {
F_12 ( V_18 , L_29 ) ;
goto V_204;
}
if ( V_112 >= V_205 ) {
V_43 = - V_54 ;
F_12 ( V_18 , L_30 , V_112 ) ;
goto V_204;
}
V_29 = & V_10 -> V_29 [ V_112 ] ;
V_29 -> V_10 = V_10 ;
V_29 -> V_112 = V_112 ;
V_43 = F_46 ( V_41 , V_29 , V_184 ) ;
if ( V_43 )
goto V_204;
V_26 = & V_29 -> V_26 ;
V_121 = & V_26 -> V_121 ;
V_121 -> V_30 = V_26 ;
V_26 -> V_18 = V_18 ;
F_54 ( V_26 , V_184 ) ;
V_26 -> V_30 = V_29 ;
V_26 -> V_206 = F_44 ;
V_26 -> V_176 = F_45 ;
V_26 -> V_164 = F_38 ;
V_26 -> V_207 = F_37 ;
V_26 -> V_208 = F_39 ;
V_26 -> V_209 = F_40 ;
V_26 -> V_210 = F_42 ;
V_121 -> V_211 = F_55 ( V_18 , V_212 , L_31 ,
F_56 ( V_18 ) , V_112 ) ;
if ( ! V_121 -> V_211 ) {
V_43 = - V_213 ;
goto V_204;
}
V_43 = F_57 ( V_26 , NULL , & V_195 ) ;
if ( V_43 )
goto V_204;
V_43 = F_58 ( V_121 , NULL , 0 ) ;
if ( V_43 )
goto V_204;
V_29 -> V_214 = true ;
}
return 0 ;
V_204:
for ( V_203 = 0 ; V_203 < V_205 ; V_203 ++ )
if ( V_10 -> V_29 [ V_203 ] . V_214 )
F_59 ( & V_10 -> V_29 [ V_203 ] . V_26 . V_121 ) ;
return V_43 ;
}
static int F_60 ( struct V_182 * V_41 )
{
struct V_183 * V_184 = V_41 -> V_18 . V_186 ;
struct V_201 * V_18 = & V_41 -> V_18 ;
struct V_9 * V_10 ;
struct V_215 * V_216 ;
struct V_215 * V_217 ;
int V_43 ;
int V_218 ;
V_10 = F_61 ( V_18 , sizeof( * V_10 ) , V_212 ) ;
if ( ! V_10 )
return - V_213 ;
F_62 ( & V_10 -> V_181 ) ;
V_10 -> V_41 = V_41 ;
F_63 ( V_41 , V_10 ) ;
V_43 = F_48 ( V_41 ) ;
if ( V_43 ) {
F_12 ( V_18 , L_32 ) ;
return - V_219 ;
}
V_10 -> V_220 = F_64 ( V_18 , NULL ) ;
if ( F_65 ( V_10 -> V_220 ) ) {
F_12 ( V_18 , L_33 ) ;
return F_66 ( V_10 -> V_220 ) ;
}
V_216 = F_67 ( V_41 , V_221 , 0 ) ;
V_10 -> V_11 = F_68 ( V_18 , V_216 ) ;
if ( F_65 ( V_10 -> V_11 ) ) {
F_12 ( V_18 , L_34 ) ;
return F_66 ( V_10 -> V_11 ) ;
}
V_217 = F_67 ( V_41 , V_221 , 1 ) ;
V_10 -> V_86 = F_68 ( V_18 , V_217 ) ;
if ( F_65 ( V_10 -> V_86 ) ) {
F_12 ( V_18 , L_35 ) ;
return F_66 ( V_10 -> V_86 ) ;
}
F_69 ( & V_10 -> V_23 ) ;
V_218 = F_70 ( V_41 , 0 ) ;
if ( V_218 < 0 ) {
F_12 ( V_18 , L_36 ) ;
return - V_185 ;
}
V_43 = F_71 ( V_10 -> V_220 ) ;
if ( V_43 ) {
F_12 ( V_18 , L_37 ) ;
return V_43 ;
}
V_10 -> V_129 = F_72 ( V_10 -> V_220 ) ;
V_43 = F_73 ( V_18 , V_218 , F_7 , 0 ,
V_41 -> V_211 , V_10 ) ;
if ( V_43 ) {
F_12 ( V_18 , L_38 ) ;
goto V_222;
}
F_11 ( V_10 ) ;
F_51 ( V_10 ) ;
V_10 -> V_161 = - 1 ;
V_10 -> V_135 = 0 ;
V_43 = F_52 ( V_10 , V_184 ) ;
if ( V_43 ) {
F_12 ( V_18 , L_39 , V_43 ) ;
goto V_223;
}
return V_43 ;
V_222:
F_34 ( V_10 , 0 ) ;
V_223:
F_74 ( V_10 -> V_220 ) ;
return V_43 ;
}
static int F_75 ( struct V_182 * V_41 )
{
struct V_9 * V_10 = F_49 ( V_41 ) ;
int V_203 ;
for ( V_203 = 0 ; V_203 < V_205 ; V_203 ++ )
if ( V_10 -> V_29 [ V_203 ] . V_214 )
F_59 ( & V_10 -> V_29 [ V_203 ] . V_26 . V_121 ) ;
F_34 ( V_10 , 0 ) ;
F_74 ( V_10 -> V_220 ) ;
return 0 ;
}
static int F_76 ( struct V_201 * V_18 )
{
struct V_9 * V_10 = F_77 ( V_18 ) ;
F_34 ( V_10 , 0 ) ;
return 0 ;
}
static int F_78 ( struct V_201 * V_18 )
{
struct V_9 * V_10 = F_77 ( V_18 ) ;
F_34 ( V_10 , 1 ) ;
return 0 ;
}
