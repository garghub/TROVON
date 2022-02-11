static inline unsigned F_1 ( unsigned V_1 )
{
switch ( V_1 ) {
case 0 :
return V_2 ;
case 1 :
return V_3 ;
default:
break;
}
F_2 () ;
return V_2 ;
}
static void F_3 ( struct V_4 * V_5 , T_1 V_6 , int V_7 )
{
if ( V_5 -> V_8 )
F_4 ( V_6 , V_5 -> V_8 + V_7 ) ;
F_5 ( V_6 , V_5 -> V_9 + V_7 ) ;
}
static void F_6 ( struct V_4 * V_5 , T_2 V_6 , int V_7 )
{
if ( V_5 -> V_8 )
F_7 ( V_6 , V_5 -> V_8 + V_7 ) ;
F_8 ( V_6 , V_5 -> V_9 + V_7 ) ;
}
static void F_9 ( struct V_4 * V_5 , T_3 V_6 , int V_7 )
{
if ( V_5 -> V_8 )
F_10 ( V_6 , V_5 -> V_8 + V_7 ) ;
F_11 ( V_6 , V_5 -> V_9 + V_7 ) ;
}
static T_1 F_12 ( struct V_4 * V_5 , int V_7 )
{
if ( V_5 -> V_8 )
return F_13 ( V_5 -> V_8 + V_7 ) ;
return F_14 ( V_5 -> V_9 + V_7 ) ;
}
static T_2 F_15 ( struct V_4 * V_5 , int V_7 )
{
if ( V_5 -> V_8 )
return F_16 ( V_5 -> V_8 + V_7 ) ;
return F_17 ( V_5 -> V_9 + V_7 ) ;
}
static T_3 F_18 ( struct V_4 * V_5 , int V_7 )
{
if ( V_5 -> V_8 )
return F_19 ( V_5 -> V_8 + V_7 ) ;
return F_20 ( V_5 -> V_9 + V_7 ) ;
}
static void F_21 ( struct V_4 * V_5 ,
T_1 V_6 , int V_7 )
{
unsigned V_10 ;
switch ( V_7 ) {
case V_11 :
V_10 = V_12 ;
break;
case V_13 :
V_10 = V_14 ;
break;
case V_15 :
V_10 = V_16 ;
break;
case V_17 :
V_10 = V_18 ;
break;
case V_19 :
V_10 = V_20 ;
break;
case F_22 ( 0 ) :
V_10 = V_21 ;
break;
case F_22 ( 1 ) :
V_10 = V_22 ;
break;
case F_23 ( 0 ) :
V_10 = V_23 ;
break;
case F_23 ( 1 ) :
V_10 = V_24 ;
break;
default:
F_24 ( V_5 -> V_25 ,
L_1 ,
V_26 , V_7 ) ;
return;
}
F_3 ( V_5 , V_6 , V_10 ) ;
}
static void F_25 ( struct V_4 * V_5 ,
T_2 V_6 , int V_7 )
{
unsigned V_10 ;
switch ( V_7 ) {
case V_27 :
V_10 = V_28 ;
break;
case V_29 :
V_10 = V_30 ;
break;
case V_31 :
V_10 = V_32 ;
break;
case V_33 :
V_10 = V_34 ;
break;
case V_35 :
V_10 = V_36 ;
break;
case V_37 :
V_10 = V_38 ;
break;
case V_39 :
V_10 = V_40 ;
break;
case V_41 :
V_10 = V_42 ;
break;
case V_43 :
F_3 ( V_5 , V_6 , V_44 ) ;
return;
case V_45 :
F_3 ( V_5 , V_6 , V_46 ) ;
return;
case V_47 :
V_10 = V_48 ;
break;
case V_49 :
V_10 = V_50 ;
break;
case V_51 :
V_10 = V_52 ;
break;
case V_53 :
V_10 = V_54 ;
break;
case V_55 :
V_10 = V_56 ;
break;
case V_57 :
V_10 = V_58 ;
break;
case V_59 :
V_10 = V_60 ;
break;
case V_61 :
V_10 = V_62 ;
break;
case V_63 :
V_10 = V_64 ;
break;
case V_65 :
V_10 = V_66 ;
break;
case V_67 :
V_10 = V_68 ;
break;
case V_69 :
V_10 = V_70 ;
break;
case V_71 :
V_10 = V_72 ;
break;
case V_73 :
V_10 = V_74 ;
break;
case V_75 :
V_10 = V_76 ;
break;
case V_77 :
F_26 ( V_5 -> V_25 ,
L_2 ,
V_26 , V_7 ) ;
return;
case F_27 ( 0 ) :
V_10 = V_78 ;
break;
case F_27 ( 1 ) :
V_10 = V_79 ;
break;
case F_28 ( 0 ) :
V_10 = V_80 ;
break;
case F_28 ( 1 ) :
V_10 = V_81 ;
break;
case F_29 ( 0 ) :
V_10 = V_82 ;
break;
case F_29 ( 1 ) :
V_10 = V_83 ;
break;
case F_30 ( 0 ) :
V_10 = V_84 ;
break;
case F_30 ( 1 ) :
V_10 = V_85 ;
break;
case V_86 :
V_10 = V_87 ;
break;
case V_88 :
V_10 = V_89 ;
break;
case V_90 :
V_10 = V_91 ;
break;
case V_92 :
V_10 = V_93 ;
break;
case V_94 :
V_10 = V_95 ;
break;
case V_96 :
V_10 = V_97 ;
break;
case V_98 :
V_10 = V_99 ;
break;
case V_100 :
V_10 = V_101 ;
break;
case V_102 :
V_10 = V_103 ;
break;
case V_104 :
V_10 = V_105 ;
break;
default:
F_24 ( V_5 -> V_25 ,
L_1 ,
V_26 , V_7 ) ;
return;
}
F_6 ( V_5 , V_6 , V_10 ) ;
}
static T_1 F_31 ( struct V_4 * V_5 , int V_7 )
{
unsigned V_10 ;
switch ( V_7 ) {
case F_32 ( 0 ) :
V_10 = V_106 ;
break;
case F_32 ( 1 ) :
V_10 = V_107 ;
break;
case F_33 ( 0 ) :
V_10 = V_108 ;
break;
case F_33 ( 1 ) :
V_10 = V_109 ;
break;
default:
F_24 ( V_5 -> V_25 ,
L_1 ,
V_26 , V_7 ) ;
return 0 ;
}
return F_12 ( V_5 , V_10 ) ;
}
static T_2 F_34 ( struct V_4 * V_5 , int V_7 )
{
unsigned V_10 ;
switch ( V_7 ) {
case V_110 :
V_10 = V_111 ;
break;
case V_112 :
V_10 = V_113 ;
break;
case V_114 :
V_10 = V_115 ;
break;
case V_116 :
return F_18 ( V_5 , V_117 ) ;
case V_118 :
V_10 = V_119 ;
break;
case V_120 :
V_10 = V_121 ;
break;
case V_122 :
V_10 = V_123 ;
break;
default:
F_24 ( V_5 -> V_25 ,
L_1 ,
V_26 , V_7 ) ;
return 0 ;
}
return F_15 ( V_5 , V_10 ) ;
}
static void F_35 ( struct V_4 * V_5 , T_2 V_6 , int V_7 )
{
struct V_124 * V_125 = V_5 -> V_126 ;
unsigned long V_127 ;
if ( V_125 -> V_128 ) {
F_25 ( V_5 , V_6 , V_7 ) ;
} else {
F_36 ( & V_125 -> V_129 , V_127 ) ;
if ( ! V_125 -> V_130 && V_7 < 8 ) {
F_6 ( V_5 , V_6 , V_7 * 2 ) ;
} else {
F_6 ( V_5 , V_7 , V_131 ) ;
F_6 ( V_5 , V_6 , V_132 ) ;
}
F_37 ( & V_125 -> V_129 , V_127 ) ;
}
}
static void F_38 ( struct V_4 * V_5 , T_1 V_6 , int V_7 )
{
struct V_124 * V_125 = V_5 -> V_126 ;
if ( V_125 -> V_128 ) {
F_21 ( V_5 , V_6 , V_7 ) ;
} else {
F_35 ( V_5 , V_6 >> 16 , V_7 ) ;
F_35 ( V_5 , V_6 & 0xffff , V_7 + 1 ) ;
}
}
static T_2 F_39 ( struct V_4 * V_5 , int V_7 )
{
struct V_124 * V_125 = V_5 -> V_126 ;
unsigned long V_127 ;
T_2 V_133 ;
if ( V_125 -> V_128 ) {
V_133 = F_34 ( V_5 , V_7 ) ;
} else {
F_36 ( & V_125 -> V_129 , V_127 ) ;
if ( ! V_125 -> V_130 && V_7 < 8 ) {
V_133 = F_15 ( V_5 , V_7 * 2 ) ;
} else {
F_6 ( V_5 , V_7 , V_131 ) ;
V_133 = F_15 ( V_5 , V_132 ) ;
}
F_37 ( & V_125 -> V_129 , V_127 ) ;
}
return V_133 ;
}
static T_1 F_40 ( struct V_4 * V_5 , int V_7 )
{
struct V_124 * V_125 = V_5 -> V_126 ;
T_1 V_133 ;
if ( V_125 -> V_128 ) {
V_133 = F_31 ( V_5 , V_7 ) ;
} else {
V_133 = F_39 ( V_5 , V_7 ) << 16 ;
V_133 |= F_39 ( V_5 , V_7 + 1 ) ;
}
return V_133 ;
}
static inline void F_41 ( struct V_4 * V_5 , int V_7 ,
unsigned V_134 , unsigned V_135 )
{
struct V_124 * V_125 = V_5 -> V_126 ;
unsigned long V_127 ;
F_36 ( & V_125 -> V_136 , V_127 ) ;
switch ( V_7 ) {
case V_88 :
V_125 -> V_137 &= ~ V_134 ;
V_125 -> V_137 |= V_135 & V_134 ;
F_35 ( V_5 , V_125 -> V_137 ,
V_88 ) ;
break;
case V_92 :
V_125 -> V_138 &= ~ V_134 ;
V_125 -> V_138 |= V_135 & V_134 ;
F_35 ( V_5 , V_125 -> V_138 ,
V_92 ) ;
break;
case V_96 :
V_125 -> V_139 &= ~ V_134 ;
V_125 -> V_139 |= V_135 & V_134 ;
F_35 ( V_5 , V_125 -> V_139 ,
V_96 ) ;
break;
case V_140 :
V_125 -> V_141 &= ~ V_134 ;
V_125 -> V_141 |= V_135 & V_134 ;
F_9 ( V_5 , V_125 -> V_141 , V_140 ) ;
break;
case V_142 :
V_125 -> V_143 &= ~ V_134 ;
V_125 -> V_143 |= V_135 & V_134 ;
F_9 ( V_5 , V_125 -> V_143 , V_142 ) ;
break;
default:
F_42 ( V_5 -> V_25 ,
L_3 , V_26 , V_7 ) ;
break;
}
F_43 () ;
F_37 ( & V_125 -> V_136 , V_127 ) ;
}
static inline void F_44 ( struct V_4 * V_5 , int V_144 )
{
unsigned V_145 ;
if ( V_144 >= 0 )
V_145 =
( F_45 ( V_144 ) <<
V_146 ) & V_147 ;
else
V_145 = 0 ;
F_41 ( V_5 , V_140 , V_147 , V_145 ) ;
}
static inline void F_46 ( struct V_4 * V_5 , int V_144 )
{
unsigned V_145 ;
if ( V_144 >= 0 )
V_145 =
( F_45 ( V_144 ) <<
V_148 ) & V_149 ;
else
V_145 = 0 ;
F_41 ( V_5 , V_140 , V_149 , V_145 ) ;
}
static inline void F_47 ( struct V_4 * V_5 ,
unsigned V_150 ,
int V_151 )
{
unsigned V_145 ;
if ( V_151 >= 0 )
V_145 = F_48 ( V_150 , V_151 ) ;
else
V_145 = 0 ;
F_41 ( V_5 , V_142 , F_49 ( V_150 ) ,
V_145 ) ;
}
static inline void F_50 ( struct V_4 * V_5 ,
int V_151 )
{
struct V_124 * V_125 = V_5 -> V_126 ;
unsigned long V_127 ;
F_36 ( & V_125 -> V_136 , V_127 ) ;
V_125 -> V_152 &= ~ V_153 ;
if ( V_151 >= 0 ) {
V_125 -> V_152 |=
( F_45 ( V_151 ) <<
V_154 ) & V_153 ;
}
F_9 ( V_5 , V_125 -> V_152 , V_155 ) ;
F_43 () ;
F_37 ( & V_125 -> V_136 , V_127 ) ;
}
static int F_51 ( struct V_4 * V_5 )
{
struct V_124 * V_125 = V_5 -> V_126 ;
unsigned long V_127 ;
F_36 ( & V_125 -> V_156 , V_127 ) ;
F_52 ( V_125 -> V_157 ) ;
V_125 -> V_157 =
F_53 ( V_125 -> V_130 , V_125 -> V_158 ) ;
if ( V_125 -> V_157 == NULL ) {
F_37 ( & V_125 -> V_156 , V_127 ) ;
F_42 ( V_5 -> V_25 ,
L_4 ) ;
return - V_159 ;
}
V_125 -> V_157 -> V_160 = V_161 ;
F_44 ( V_5 , V_125 -> V_157 -> V_144 ) ;
F_37 ( & V_125 -> V_156 , V_127 ) ;
return 0 ;
}
static int F_54 ( struct V_4 * V_5 )
{
struct V_124 * V_125 = V_5 -> V_126 ;
unsigned long V_127 ;
F_36 ( & V_125 -> V_156 , V_127 ) ;
F_52 ( V_125 -> V_162 ) ;
V_125 -> V_162 =
F_53 ( V_125 -> V_130 , V_125 -> V_163 ) ;
if ( V_125 -> V_162 == NULL ) {
F_37 ( & V_125 -> V_156 , V_127 ) ;
F_42 ( V_5 -> V_25 ,
L_5 ) ;
return - V_159 ;
}
V_125 -> V_162 -> V_160 = V_164 ;
F_46 ( V_5 , V_125 -> V_162 -> V_144 ) ;
F_37 ( & V_125 -> V_156 , V_127 ) ;
return 0 ;
}
static int F_55 ( struct V_4 * V_5 ,
unsigned V_150 ,
enum V_165 V_166 )
{
struct V_124 * V_125 = V_5 -> V_126 ;
unsigned long V_127 ;
struct V_151 * V_167 ;
F_52 ( V_150 >= V_168 ) ;
F_36 ( & V_125 -> V_156 , V_127 ) ;
F_52 ( V_125 -> V_169 -> V_170 [ V_150 ] . V_167 ) ;
V_167 =
F_53 ( V_125 -> V_130 ,
V_125 -> V_171 [ V_150 ] ) ;
if ( V_167 == NULL ) {
F_37 ( & V_125 -> V_156 , V_127 ) ;
F_42 ( V_5 -> V_25 ,
L_6 ) ;
return - V_159 ;
}
V_167 -> V_160 = V_166 ;
F_56 ( & V_125 -> V_169 -> V_170 [ V_150 ] ,
V_167 ) ;
F_47 ( V_5 , V_150 , V_167 -> V_144 ) ;
F_37 ( & V_125 -> V_156 , V_127 ) ;
return 0 ;
}
static int F_57 ( struct V_4 * V_5 )
{
#ifdef F_58
struct V_124 * V_125 = V_5 -> V_126 ;
unsigned long V_127 ;
F_36 ( & V_125 -> V_156 , V_127 ) ;
F_52 ( V_125 -> V_172 ) ;
V_125 -> V_172 =
F_53 ( V_125 -> V_130 , V_125 -> V_173 ) ;
if ( V_125 -> V_172 == NULL ) {
F_37 ( & V_125 -> V_156 , V_127 ) ;
F_42 ( V_5 -> V_25 ,
L_7 ) ;
return - V_159 ;
}
V_125 -> V_172 -> V_160 = V_164 ;
F_50 ( V_5 , V_125 -> V_172 -> V_144 ) ;
F_37 ( & V_125 -> V_156 , V_127 ) ;
#endif
return 0 ;
}
static void F_59 ( struct V_4 * V_5 )
{
#ifdef F_58
struct V_124 * V_125 = V_5 -> V_126 ;
unsigned long V_127 ;
F_36 ( & V_125 -> V_156 , V_127 ) ;
if ( V_125 -> V_157 ) {
F_44 ( V_5 , - 1 ) ;
F_60 ( V_125 -> V_157 ) ;
V_125 -> V_157 = NULL ;
}
F_37 ( & V_125 -> V_156 , V_127 ) ;
#endif
}
static void F_61 ( struct V_4 * V_5 )
{
#ifdef F_58
struct V_124 * V_125 = V_5 -> V_126 ;
unsigned long V_127 ;
F_36 ( & V_125 -> V_156 , V_127 ) ;
if ( V_125 -> V_162 ) {
F_46 ( V_5 , - 1 ) ;
F_60 ( V_125 -> V_162 ) ;
V_125 -> V_162 = NULL ;
}
F_37 ( & V_125 -> V_156 , V_127 ) ;
#endif
}
static void F_62 ( struct V_4 * V_5 ,
unsigned V_150 )
{
struct V_124 * V_125 = V_5 -> V_126 ;
unsigned long V_127 ;
F_52 ( V_150 >= V_168 ) ;
F_36 ( & V_125 -> V_156 , V_127 ) ;
if ( V_125 -> V_169 -> V_170 [ V_150 ] . V_167 ) {
struct V_151 * V_167 =
V_125 -> V_169 -> V_170 [ V_150 ] . V_167 ;
F_47 ( V_5 , V_150 , - 1 ) ;
F_56 ( & V_125 ->
V_169 -> V_170 [ V_150 ] ,
NULL ) ;
F_60 ( V_167 ) ;
}
F_37 ( & V_125 -> V_156 , V_127 ) ;
}
static void F_63 ( struct V_4 * V_5 )
{
#ifdef F_58
struct V_124 * V_125 = V_5 -> V_126 ;
unsigned long V_127 ;
F_36 ( & V_125 -> V_156 , V_127 ) ;
if ( V_125 -> V_172 ) {
F_50 ( V_5 , - 1 ) ;
F_60 ( V_125 -> V_172 ) ;
V_125 -> V_172 = NULL ;
}
F_37 ( & V_125 -> V_156 , V_127 ) ;
#endif
}
static void F_64 ( struct V_4 * V_5 ,
unsigned V_150 , short V_174 )
{
struct V_124 * V_125 = V_5 -> V_126 ;
T_2 V_133 = 0 ;
int V_7 ;
if ( V_125 -> V_128 || V_150 > 1 )
return;
if ( V_150 == 0 ) {
V_7 = V_175 ;
if ( V_174 )
V_133 = V_176 ;
} else {
V_7 = V_177 ;
if ( V_174 )
V_133 = V_178 ;
}
F_35 ( V_5 , V_133 , V_7 ) ;
}
static void F_65 ( struct V_4 * V_5 )
{
struct V_124 * V_125 = V_5 -> V_126 ;
static const int V_179 = 10000 ;
int V_180 ;
if ( V_125 -> V_181 ) {
F_3 ( V_5 , 0x10 , V_182 ) ;
F_3 ( V_5 , 0x00 , V_182 ) ;
for ( V_180 = 0 ; V_180 < V_179 ; V_180 ++ ) {
if ( ! ( F_12 ( V_5 , V_183 ) & 0x10 ) )
break;
F_66 ( 1 ) ;
}
if ( V_180 == V_179 )
F_42 ( V_5 -> V_25 , L_8 ) ;
} else {
F_35 ( V_5 , 1 , V_27 ) ;
if ( V_125 -> V_184 ) {
F_9 ( V_5 , 0 , F_67 ( 0 ) ) ;
F_9 ( V_5 , 1 , F_67 ( 0 ) ) ;
#if 0
ni_stc_writew(dev, AI_CONVERT_Pulse,
AI_Command_1_Register);
ni_stc_writew(dev, AI_CONVERT_Pulse,
AI_Command_1_Register);
ni_stc_writew(dev, AI_CONVERT_Pulse,
AI_Command_1_Register);
#endif
}
}
}
static inline void F_68 ( struct V_4 * V_5 , T_2 V_6 ,
int V_185 )
{
struct V_124 * V_125 = V_5 -> V_126 ;
unsigned long V_127 ;
F_36 ( & V_125 -> V_129 , V_127 ) ;
F_6 ( V_5 , V_185 , V_186 ) ;
F_6 ( V_5 , V_6 , V_187 ) ;
F_37 ( & V_125 -> V_129 , V_127 ) ;
}
static inline void F_69 ( struct V_4 * V_5 , T_1 V_6 ,
int V_185 )
{
struct V_124 * V_125 = V_5 -> V_126 ;
unsigned long V_127 ;
F_36 ( & V_125 -> V_129 , V_127 ) ;
F_6 ( V_5 , V_185 , V_186 ) ;
F_3 ( V_5 , V_6 , V_187 ) ;
F_37 ( & V_125 -> V_129 , V_127 ) ;
}
static inline unsigned short F_70 ( struct V_4 * V_5 , int V_185 )
{
struct V_124 * V_125 = V_5 -> V_126 ;
unsigned long V_127 ;
unsigned short V_6 ;
F_36 ( & V_125 -> V_129 , V_127 ) ;
F_6 ( V_5 , V_185 , V_186 ) ;
V_6 = F_15 ( V_5 , V_187 ) ;
F_37 ( & V_125 -> V_129 , V_127 ) ;
return V_6 ;
}
static inline void F_71 ( struct V_4 * V_5 , int V_7 ,
unsigned V_188 , unsigned V_189 )
{
unsigned V_135 ;
if ( V_189 )
V_135 = V_188 ;
else
V_135 = 0 ;
F_41 ( V_5 , V_7 , V_188 , V_135 ) ;
}
static void F_72 ( struct V_4 * V_5 )
{
struct V_124 * V_125 = V_5 -> V_126 ;
struct V_190 * V_191 = V_5 -> V_192 ;
unsigned long V_127 ;
F_36 ( & V_125 -> V_156 , V_127 ) ;
if ( V_125 -> V_157 )
F_73 ( V_125 -> V_157 , V_191 ) ;
F_37 ( & V_125 -> V_156 , V_127 ) ;
}
static int F_74 ( struct V_4 * V_5 )
{
struct V_124 * V_125 = V_5 -> V_126 ;
int V_180 ;
static const int V_179 = 10000 ;
unsigned long V_127 ;
int V_193 = 0 ;
F_36 ( & V_125 -> V_156 , V_127 ) ;
if ( V_125 -> V_157 ) {
for ( V_180 = 0 ; V_180 < V_179 ; V_180 ++ ) {
if ( ( F_39 ( V_5 , V_110 ) &
V_194 )
&& F_75 ( V_125 -> V_157 ) ==
0 )
break;
F_66 ( 5 ) ;
}
if ( V_180 == V_179 ) {
F_42 ( V_5 -> V_25 , L_9 , V_26 ) ;
F_42 ( V_5 -> V_25 ,
L_10 ,
F_75 ( V_125 -> V_157 ) ,
F_39 ( V_5 , V_110 ) ) ;
V_193 = - 1 ;
}
}
F_37 ( & V_125 -> V_156 , V_127 ) ;
F_72 ( V_5 ) ;
return V_193 ;
}
static void F_76 ( struct V_195 * V_130 ,
struct V_4 * V_5 )
{
struct V_124 * V_125 = V_5 -> V_126 ;
struct V_190 * V_191 = V_5 -> V_196 ;
unsigned long V_127 ;
F_36 ( & V_125 -> V_156 , V_127 ) ;
if ( V_125 -> V_162 )
F_77 ( V_125 -> V_162 , V_191 ) ;
F_37 ( & V_125 -> V_156 , V_127 ) ;
}
static int F_78 ( struct V_4 * V_5 )
{
static const int V_179 = 10000 ;
int V_180 ;
for ( V_180 = 0 ; V_180 < V_179 ; V_180 ++ ) {
unsigned short V_197 ;
V_197 = F_39 ( V_5 , V_112 ) ;
if ( V_197 & V_198 )
break;
F_66 ( 10 ) ;
}
if ( V_180 == V_179 ) {
F_42 ( V_5 -> V_25 , L_11 ) ;
return - V_199 ;
}
return 0 ;
}
static void F_79 ( struct V_4 * V_5 ,
struct V_190 * V_191 , int V_200 )
{
struct V_124 * V_125 = V_5 -> V_126 ;
int V_180 ;
unsigned short V_201 ;
T_4 V_202 ;
for ( V_180 = 0 ; V_180 < V_200 ; V_180 ++ ) {
F_80 ( V_191 , & V_201 , 1 ) ;
if ( V_125 -> V_203 ) {
V_202 = V_201 & 0xffff ;
if ( ! V_125 -> V_204 ) {
F_80 ( V_191 , & V_201 , 1 ) ;
V_180 ++ ;
V_202 |= ( V_201 << 16 ) & 0xffff0000 ;
}
F_3 ( V_5 , V_202 , V_205 ) ;
} else {
F_6 ( V_5 , V_201 , V_206 ) ;
}
}
}
static int F_81 ( struct V_4 * V_5 ,
struct V_190 * V_191 )
{
const struct V_207 * V_208 = V_5 -> V_209 ;
unsigned int V_210 ;
unsigned int V_211 ;
V_210 = F_82 ( V_191 ) ;
if ( V_210 == 0 ) {
V_191 -> V_212 -> V_213 |= V_214 ;
return 0 ;
}
V_211 = F_83 ( V_191 , V_210 ) ;
if ( V_211 > V_208 -> V_215 / 2 )
V_211 = V_208 -> V_215 / 2 ;
F_79 ( V_5 , V_191 , V_211 ) ;
return 1 ;
}
static int F_84 ( struct V_4 * V_5 ,
struct V_190 * V_191 )
{
const struct V_207 * V_208 = V_5 -> V_209 ;
struct V_124 * V_125 = V_5 -> V_126 ;
unsigned int V_210 ;
unsigned int V_211 ;
F_35 ( V_5 , 1 , V_75 ) ;
if ( V_125 -> V_203 )
F_69 ( V_5 , 0x6 , V_216 ) ;
V_210 = F_82 ( V_191 ) ;
if ( V_210 == 0 )
return 0 ;
V_211 = F_83 ( V_191 , V_210 ) ;
if ( V_211 > V_208 -> V_215 )
V_211 = V_208 -> V_215 ;
F_79 ( V_5 , V_191 , V_211 ) ;
return V_211 ;
}
static void F_85 ( struct V_4 * V_5 ,
struct V_190 * V_191 , int V_200 )
{
struct V_124 * V_125 = V_5 -> V_126 ;
struct V_217 * V_212 = V_191 -> V_212 ;
T_4 V_218 ;
unsigned short V_6 ;
int V_180 ;
if ( V_125 -> V_219 ) {
for ( V_180 = 0 ; V_180 < V_200 / 2 ; V_180 ++ ) {
V_218 = F_12 ( V_5 , V_220 ) ;
V_6 = ( V_218 >> 16 ) & 0xffff ;
F_86 ( V_191 , & V_6 , 1 ) ;
V_6 = V_218 & 0xffff ;
F_86 ( V_191 , & V_6 , 1 ) ;
}
if ( V_200 % 2 ) {
V_218 = F_12 ( V_5 , V_220 ) ;
V_6 = V_218 & 0xffff ;
F_86 ( V_191 , & V_6 , 1 ) ;
}
} else if ( V_125 -> V_181 ) {
for ( V_180 = 0 ; V_180 < V_200 / 2 ; V_180 ++ ) {
V_218 = F_12 ( V_5 , V_221 ) ;
V_6 = ( V_218 >> 16 ) & 0xffff ;
F_86 ( V_191 , & V_6 , 1 ) ;
V_6 = V_218 & 0xffff ;
F_86 ( V_191 , & V_6 , 1 ) ;
}
if ( V_200 % 2 ) {
F_3 ( V_5 , 0x01 , V_182 ) ;
V_218 = F_12 ( V_5 , V_221 ) ;
V_6 = ( V_218 >> 16 ) & 0xffff ;
F_86 ( V_191 , & V_6 , 1 ) ;
}
} else {
if ( V_200 > sizeof( V_125 -> V_222 ) /
sizeof( V_125 -> V_222 [ 0 ] ) ) {
F_42 ( V_5 -> V_25 ,
L_12 ) ;
V_212 -> V_213 |= V_223 ;
return;
}
for ( V_180 = 0 ; V_180 < V_200 ; V_180 ++ ) {
V_125 -> V_222 [ V_180 ] =
F_15 ( V_5 , V_224 ) ;
}
F_86 ( V_191 , V_125 -> V_222 , V_200 ) ;
}
}
static void F_87 ( struct V_4 * V_5 )
{
const struct V_207 * V_208 = V_5 -> V_209 ;
struct V_190 * V_191 = V_5 -> V_192 ;
int V_200 ;
V_200 = V_208 -> V_225 / 2 ;
F_85 ( V_5 , V_191 , V_200 ) ;
}
static void F_88 ( struct V_4 * V_5 )
{
struct V_124 * V_125 = V_5 -> V_126 ;
struct V_190 * V_191 = V_5 -> V_192 ;
T_4 V_218 ;
unsigned short V_6 ;
unsigned short V_226 ;
int V_180 ;
if ( V_125 -> V_219 ) {
while ( ( F_39 ( V_5 , V_110 ) &
V_194 ) == 0 ) {
V_218 = F_12 ( V_5 , V_220 ) ;
V_6 = V_218 >> 16 ;
F_86 ( V_191 , & V_6 , 1 ) ;
V_6 = V_218 & 0xffff ;
F_86 ( V_191 , & V_6 , 1 ) ;
}
} else if ( V_125 -> V_181 ) {
V_180 = 0 ;
while ( F_12 ( V_5 , V_183 ) & 0x04 ) {
V_218 = F_12 ( V_5 , V_221 ) ;
V_6 = V_218 >> 16 ;
F_86 ( V_191 , & V_6 , 1 ) ;
V_6 = V_218 & 0xffff ;
F_86 ( V_191 , & V_6 , 1 ) ;
V_180 += 2 ;
}
if ( F_12 ( V_5 , V_183 ) & 0x01 ) {
F_3 ( V_5 , 0x01 , V_182 ) ;
V_218 = F_12 ( V_5 , V_221 ) ;
V_6 = ( V_218 >> 16 ) & 0xffff ;
F_86 ( V_191 , & V_6 , 1 ) ;
}
} else {
V_226 = F_39 ( V_5 , V_110 ) &
V_194 ;
while ( V_226 == 0 ) {
for ( V_180 = 0 ;
V_180 <
sizeof( V_125 -> V_222 ) /
sizeof( V_125 -> V_222 [ 0 ] ) ; V_180 ++ ) {
V_226 = F_39 ( V_5 ,
V_110 ) &
V_194 ;
if ( V_226 )
break;
V_125 -> V_222 [ V_180 ] =
F_15 ( V_5 , V_224 ) ;
}
F_86 ( V_191 , V_125 -> V_222 , V_180 ) ;
}
}
}
static void F_89 ( struct V_4 * V_5 )
{
struct V_124 * V_125 = V_5 -> V_126 ;
struct V_190 * V_191 = V_5 -> V_192 ;
unsigned short V_6 ;
T_4 V_218 ;
if ( ! V_125 -> V_219 )
return;
if ( F_18 ( V_5 , V_227 ) & 0x80 ) {
V_218 = F_12 ( V_5 , V_220 ) ;
V_6 = ( V_218 & 0xffff ) ;
F_86 ( V_191 , & V_6 , 1 ) ;
}
}
static void F_90 ( struct V_4 * V_5 )
{
struct V_124 * V_125 = V_5 -> V_126 ;
struct V_190 * V_191 = V_5 -> V_192 ;
unsigned short V_6 ;
T_4 V_218 ;
if ( ! V_125 -> V_181 )
return;
if ( F_12 ( V_5 , V_183 ) & 0x01 ) {
F_3 ( V_5 , 0x01 , V_182 ) ;
V_218 = F_12 ( V_5 , V_221 ) ;
V_6 = ( V_218 >> 16 ) & 0xffff ;
F_86 ( V_191 , & V_6 , 1 ) ;
}
}
static void F_91 ( struct V_4 * V_5 )
{
struct V_190 * V_191 = V_5 -> V_192 ;
#ifdef F_58
F_74 ( V_5 ) ;
#endif
F_88 ( V_5 ) ;
F_89 ( V_5 ) ;
F_90 ( V_5 ) ;
V_191 -> V_212 -> V_213 |= V_228 ;
}
static void F_92 ( struct V_4 * V_5 , struct V_190 * V_191 )
{
struct V_124 * V_125 = V_5 -> V_126 ;
if ( V_125 -> V_229 == V_230 ) {
#ifdef F_58
static const int V_179 = 10 ;
int V_180 ;
for ( V_180 = 0 ; V_180 < V_179 ; V_180 ++ ) {
F_72 ( V_5 ) ;
if ( ( V_191 -> V_212 -> V_213 & V_231 ) )
break;
F_66 ( 1 ) ;
}
#else
F_88 ( V_5 ) ;
V_191 -> V_212 -> V_213 |= V_231 ;
#endif
}
if ( ( V_125 -> V_232 & V_233 ) )
F_91 ( V_5 ) ;
}
static void F_93 ( struct V_4 * V_5 ,
unsigned short V_1 )
{
#ifdef F_58
struct V_124 * V_125 = V_5 -> V_126 ;
struct V_190 * V_191 ;
V_191 = & V_5 -> V_234 [ F_1 ( V_1 ) ] ;
F_94 ( & V_125 -> V_169 -> V_170 [ V_1 ] ,
V_191 ) ;
F_95 ( V_5 , V_191 ) ;
#endif
}
static void F_96 ( struct V_4 * V_5 , unsigned short V_235 )
{
unsigned short V_236 = 0 ;
if ( V_235 & V_237 )
V_236 |= V_238 ;
if ( V_235 & V_239 )
V_236 |= V_240 ;
if ( V_235 & V_241 )
V_236 |= V_242 ;
if ( V_235 & V_243 )
V_236 |= V_244 ;
if ( V_236 )
F_35 ( V_5 , V_236 , V_86 ) ;
}
static void F_97 ( struct V_4 * V_5 , unsigned short V_245 ,
unsigned V_246 )
{
struct V_190 * V_191 = V_5 -> V_192 ;
struct V_247 * V_248 = & V_191 -> V_212 -> V_248 ;
if ( V_191 -> type == V_249 )
return;
#ifdef F_58
if ( V_246 & V_250 )
F_72 ( V_5 ) ;
if ( V_246 & ~ ( V_251 | V_250 | V_252 | V_253 |
V_254 | V_255 | V_256 | V_257 |
V_258 | V_259 | V_260 ) ) {
F_42 ( V_5 -> V_25 ,
L_13 ,
V_246 ) ;
V_191 -> V_212 -> V_213 |= V_223 ;
}
#endif
if ( V_245 & ( V_261 | V_262 | V_263 |
V_237 | V_239 ) ) {
if ( V_245 == 0xffff ) {
F_42 ( V_5 -> V_25 , L_14 ) ;
if ( F_98 ( V_191 ) ) {
V_191 -> V_212 -> V_213 |= V_223 ;
F_95 ( V_5 , V_191 ) ;
}
return;
}
if ( V_245 & ( V_261 | V_262 |
V_263 ) ) {
F_42 ( V_5 -> V_25 , L_15 ,
V_245 ) ;
F_91 ( V_5 ) ;
V_191 -> V_212 -> V_213 |= V_223 ;
if ( V_245 & ( V_261 | V_262 ) )
V_191 -> V_212 -> V_213 |= V_214 ;
F_95 ( V_5 , V_191 ) ;
return;
}
if ( V_245 & V_237 ) {
if ( V_248 -> V_264 == V_265 )
F_91 ( V_5 ) ;
}
}
#ifndef F_58
if ( V_245 & V_266 ) {
int V_180 ;
static const int V_179 = 10 ;
for ( V_180 = 0 ; V_180 < V_179 ; ++ V_180 ) {
F_87 ( V_5 ) ;
if ( ( F_39 ( V_5 , V_110 ) &
V_266 ) == 0 )
break;
}
}
#endif
if ( ( V_245 & V_243 ) )
F_92 ( V_5 , V_191 ) ;
F_95 ( V_5 , V_191 ) ;
}
static void F_99 ( struct V_4 * V_5 , unsigned short V_197 )
{
unsigned short V_236 = 0 ;
if ( V_197 & V_267 )
V_236 |= V_268 ;
if ( V_197 & V_269 )
V_236 |= V_270 ;
if ( V_197 & V_271 )
V_236 |= V_272 ;
if ( V_197 & V_273 )
V_236 |= V_274 ;
if ( V_197 & V_275 )
V_236 |= V_276 ;
if ( V_197 & V_277 )
V_236 |= V_278 ;
if ( V_197 & V_279 )
V_236 |= V_280 ;
if ( V_236 )
F_35 ( V_5 , V_236 , V_90 ) ;
}
static void F_100 ( struct V_4 * V_5 ,
unsigned short V_197 , unsigned V_281 )
{
struct V_190 * V_191 = V_5 -> V_196 ;
#ifdef F_58
if ( V_281 & V_250 ) {
struct V_124 * V_125 = V_5 -> V_126 ;
F_76 ( V_125 -> V_130 , V_5 ) ;
}
if ( V_281 & ~ ( V_251 | V_250 | V_252 | V_253 |
V_254 | V_255 | V_256 | V_257 |
V_258 | V_259 | V_260 ) ) {
F_42 ( V_5 -> V_25 ,
L_16 ,
V_281 ) ;
V_191 -> V_212 -> V_213 |= V_223 ;
}
#endif
if ( V_197 == 0xffff )
return;
if ( V_197 & V_269 ) {
F_42 ( V_5 -> V_25 ,
L_17 ,
V_197 , F_39 ( V_5 , V_114 ) ) ;
V_191 -> V_212 -> V_213 |= V_214 ;
}
if ( V_197 & V_267 )
V_191 -> V_212 -> V_213 |= V_228 ;
#ifndef F_58
if ( V_197 & V_282 ) {
int V_283 ;
V_283 = F_81 ( V_5 , V_191 ) ;
if ( ! V_283 ) {
F_42 ( V_5 -> V_25 , L_18 ) ;
F_71 ( V_5 , V_92 ,
V_284 |
V_285 , 0 ) ;
V_191 -> V_212 -> V_213 |= V_214 ;
}
}
#endif
F_95 ( V_5 , V_191 ) ;
}
static void F_101 ( struct V_4 * V_5 , struct V_190 * V_191 ,
void * V_6 , unsigned int V_286 ,
unsigned int V_287 )
{
struct V_124 * V_125 = V_5 -> V_126 ;
struct V_217 * V_212 = V_191 -> V_212 ;
struct V_247 * V_248 = & V_212 -> V_248 ;
unsigned int V_211 = F_83 ( V_191 , V_286 ) ;
unsigned short * V_288 = V_6 ;
unsigned int * V_289 = V_6 ;
unsigned int V_180 ;
for ( V_180 = 0 ; V_180 < V_211 ; V_180 ++ ) {
#ifdef F_58
if ( V_191 -> V_290 & V_291 )
V_289 [ V_180 ] = F_102 ( V_289 [ V_180 ] ) ;
else
V_288 [ V_180 ] = F_103 ( V_288 [ V_180 ] ) ;
#endif
if ( V_191 -> V_290 & V_291 )
V_289 [ V_180 ] += V_125 -> V_292 [ V_287 ] ;
else
V_288 [ V_180 ] += V_125 -> V_292 [ V_287 ] ;
V_287 ++ ;
V_287 %= V_248 -> V_293 ;
}
}
static int F_104 ( struct V_4 * V_5 )
{
struct V_124 * V_125 = V_5 -> V_126 ;
struct V_190 * V_191 = V_5 -> V_192 ;
int V_193 ;
unsigned long V_127 ;
V_193 = F_51 ( V_5 ) ;
if ( V_193 )
return V_193 ;
F_105 ( V_191 , V_191 -> V_212 -> V_294 ) ;
F_36 ( & V_125 -> V_156 , V_127 ) ;
if ( V_125 -> V_157 == NULL ) {
F_37 ( & V_125 -> V_156 , V_127 ) ;
return - V_295 ;
}
if ( V_125 -> V_219 || V_125 -> V_181 )
F_106 ( V_125 -> V_157 , 32 , 16 ) ;
else if ( V_125 -> V_296 )
F_106 ( V_125 -> V_157 , 32 , 32 ) ;
else
F_106 ( V_125 -> V_157 , 16 , 16 ) ;
F_107 ( V_125 -> V_157 ) ;
F_37 ( & V_125 -> V_156 , V_127 ) ;
return 0 ;
}
static int F_108 ( struct V_4 * V_5 )
{
struct V_124 * V_125 = V_5 -> V_126 ;
struct V_190 * V_191 = V_5 -> V_196 ;
int V_193 ;
unsigned long V_127 ;
V_193 = F_54 ( V_5 ) ;
if ( V_193 )
return V_193 ;
F_109 ( V_191 , V_191 -> V_212 -> V_294 ) ;
F_36 ( & V_125 -> V_156 , V_127 ) ;
if ( V_125 -> V_162 ) {
if ( V_125 -> V_219 || V_125 -> V_297 ) {
F_106 ( V_125 -> V_162 , 32 , 32 ) ;
} else {
F_106 ( V_125 -> V_162 , 16 , 32 ) ;
}
F_107 ( V_125 -> V_162 ) ;
} else
V_193 = - V_295 ;
F_37 ( & V_125 -> V_156 , V_127 ) ;
return V_193 ;
}
static int F_110 ( struct V_4 * V_5 , struct V_190 * V_191 )
{
struct V_124 * V_125 = V_5 -> V_126 ;
F_59 ( V_5 ) ;
F_35 ( V_5 , V_298 | V_299 ,
V_98 ) ;
F_71 ( V_5 , V_88 ,
V_300 | V_301 |
V_302 | V_303 |
V_304 | V_305 |
V_306 , 0 ) ;
F_65 ( V_5 ) ;
if ( ! V_125 -> V_181 )
F_9 ( V_5 , 0 , V_307 ) ;
F_35 ( V_5 , V_308 , V_29 ) ;
F_35 ( V_5 , V_309 | V_310
,
V_33 ) ;
F_35 ( V_5 , 0x0000 , V_35 ) ;
F_35 ( V_5 , ( 0 << 6 ) | 0x0000 , V_37 ) ;
if ( V_125 -> V_219 ) {
F_35 ( V_5 ,
V_311 |
V_312 |
V_313 ,
V_41 ) ;
F_35 ( V_5 ,
F_111 ( 3 ) |
F_112 ( 0 ) |
F_113 ( 2 ) |
F_114 ( 3 ) |
F_115
( V_314 ) ,
V_39 ) ;
} else if ( V_125 -> V_181 ) {
F_35 ( V_5 , V_311 |
V_312 |
V_313 ,
V_41 ) ;
F_35 ( V_5 ,
F_111 ( 3 ) |
F_112 ( 0 ) |
F_113 ( 2 ) |
F_114 ( 3 ) |
F_115
( V_315 ) ,
V_39 ) ;
} else {
unsigned V_316 ;
F_35 ( V_5 ,
V_311 |
V_312 |
V_317 |
V_313 ,
V_41 ) ;
V_316 =
F_111 ( 3 ) |
F_112 ( 0 ) |
F_113 ( 2 ) |
F_114 ( 3 ) ;
if ( V_125 -> V_318 )
V_316 |=
F_115
( V_314 ) ;
else
V_316 |=
F_115
( V_315 ) ;
F_35 ( V_5 , V_316 ,
V_39 ) ;
}
F_35 ( V_5 ,
V_319 |
V_242 |
V_320 |
V_240 |
V_238 |
V_321 |
V_244 ,
V_86 ) ;
F_35 ( V_5 , V_322 , V_98 ) ;
return 0 ;
}
static int F_116 ( struct V_4 * V_5 , struct V_190 * V_191 )
{
unsigned long V_127 ;
int V_323 ;
F_36 ( & V_5 -> V_324 , V_127 ) ;
#ifndef F_58
F_88 ( V_5 ) ;
#else
F_72 ( V_5 ) ;
#endif
V_323 = F_117 ( V_191 ) ;
F_37 ( & V_5 -> V_324 , V_127 ) ;
return V_323 ;
}
static void F_118 ( struct V_4 * V_5 )
{
int V_180 ;
F_35 ( V_5 , V_325 , V_29 ) ;
for ( V_180 = 0 ; V_180 < V_326 ; ++ V_180 ) {
if ( ! ( F_39 ( V_5 , V_110 ) &
V_194 ) ) {
F_35 ( V_5 , 1 , V_27 ) ;
return;
}
F_66 ( 1 ) ;
}
F_42 ( V_5 -> V_25 , L_19 ) ;
}
static void F_119 ( struct V_4 * V_5 ,
unsigned int V_327 ,
unsigned int * V_328 )
{
const struct V_207 * V_208 = V_5 -> V_209 ;
struct V_124 * V_125 = V_5 -> V_126 ;
unsigned int V_329 , V_330 , V_331 ;
unsigned int V_180 ;
unsigned int V_332 ;
unsigned V_333 ;
F_35 ( V_5 , 1 , V_73 ) ;
if ( ( V_328 [ 0 ] & V_334 ) ) {
unsigned V_335 ;
V_329 = F_120 ( V_328 [ 0 ] ) ;
V_330 = F_121 ( V_328 [ 0 ] ) ;
V_333 = V_336 [ V_208 -> V_337 ] [ V_330 ] ;
V_332 = ( ( V_328 [ 0 ] & V_338 ) != 0 ) ;
V_335 = V_339 ;
V_335 |= V_329 ;
V_335 |=
( V_125 -> V_340 ) &
( V_341 |
V_342 |
V_343 |
V_344 ) ;
V_335 |= F_122 ( V_333 ) ;
if ( V_332 )
V_335 |= V_345 ;
V_335 |= V_346 ;
F_3 ( V_5 , V_335 , V_347 ) ;
} else {
F_3 ( V_5 , 0 , V_347 ) ;
}
for ( V_180 = 0 ; V_180 < V_327 ; V_180 ++ ) {
unsigned V_348 = 0 ;
V_329 = F_120 ( V_328 [ V_180 ] ) ;
V_331 = F_123 ( V_328 [ V_180 ] ) ;
V_330 = F_121 ( V_328 [ V_180 ] ) ;
V_332 = ( ( V_328 [ V_180 ] & V_338 ) != 0 ) ;
V_333 = V_336 [ V_208 -> V_337 ] [ V_330 ] ;
V_125 -> V_292 [ V_180 ] = 0 ;
switch ( V_331 ) {
case V_349 :
V_348 |=
V_350 ;
break;
case V_351 :
V_348 |=
V_352 ;
break;
case V_353 :
V_348 |=
V_354 ;
break;
case V_355 :
break;
}
V_348 |= F_124 ( V_329 ) ;
V_348 |=
F_125 ( V_208 -> V_356 , V_329 ) ;
V_348 |= F_126 ( V_333 ) ;
if ( V_180 == V_327 - 1 )
V_348 |= V_357 ;
if ( V_332 )
V_348 |= V_358 ;
V_348 |= V_359 ;
F_6 ( V_5 , V_348 , V_360 ) ;
}
F_118 ( V_5 ) ;
}
static void F_127 ( struct V_4 * V_5 ,
struct V_190 * V_191 ,
unsigned int V_327 , unsigned int * V_328 )
{
const struct V_207 * V_208 = V_5 -> V_209 ;
struct V_124 * V_125 = V_5 -> V_126 ;
unsigned int V_10 = ( V_191 -> V_361 + 1 ) >> 1 ;
unsigned int V_329 , V_330 , V_331 ;
unsigned int V_180 ;
unsigned int V_362 , V_363 ;
unsigned int V_332 ;
if ( V_125 -> V_128 ) {
F_119 ( V_5 , V_327 , V_328 ) ;
return;
}
if ( V_327 == 1 && ! V_125 -> V_219 && ! V_125 -> V_181 ) {
if ( V_125 -> V_364
&& V_125 -> V_365 == V_328 [ 0 ] ) {
return;
}
V_125 -> V_364 = 1 ;
V_125 -> V_365 = V_328 [ 0 ] ;
} else {
V_125 -> V_364 = 0 ;
}
F_35 ( V_5 , 1 , V_73 ) ;
if ( V_125 -> V_181 ) {
if ( ( V_328 [ 0 ] & V_334 )
&& ! V_125 -> V_366 ) {
F_6 ( V_5 , V_125 -> V_340 |
V_367 ,
V_368 ) ;
F_6 ( V_5 , V_125 -> V_340 ,
V_368 ) ;
V_125 -> V_366 = 1 ;
F_128 ( 100 ) ;
} else if ( ! ( V_328 [ 0 ] & V_334 )
&& V_125 -> V_366 ) {
F_6 ( V_5 , V_125 -> V_340 |
V_369 ,
V_368 ) ;
F_6 ( V_5 , V_125 -> V_340 ,
V_368 ) ;
V_125 -> V_366 = 0 ;
F_128 ( 100 ) ;
}
}
for ( V_180 = 0 ; V_180 < V_327 ; V_180 ++ ) {
if ( ! V_125 -> V_181 && ( V_328 [ V_180 ] & V_334 ) )
V_329 = V_125 -> V_340 ;
else
V_329 = F_120 ( V_328 [ V_180 ] ) ;
V_331 = F_123 ( V_328 [ V_180 ] ) ;
V_330 = F_121 ( V_328 [ V_180 ] ) ;
V_332 = ( ( V_328 [ V_180 ] & V_338 ) != 0 ) ;
V_330 = V_336 [ V_208 -> V_337 ] [ V_330 ] ;
if ( V_125 -> V_219 )
V_125 -> V_292 [ V_180 ] = V_10 ;
else
V_125 -> V_292 [ V_180 ] = ( V_330 & 0x100 ) ? 0 : V_10 ;
V_362 = 0 ;
if ( ( V_328 [ V_180 ] & V_334 ) ) {
if ( V_125 -> V_219 )
F_6 ( V_5 , F_120 ( V_328 [ V_180 ] ) & 0x0003 ,
V_370 ) ;
} else {
if ( V_125 -> V_219 )
V_331 = V_349 ;
else if ( V_125 -> V_181 )
V_331 = V_355 ;
switch ( V_331 ) {
case V_349 :
V_362 |= V_371 ;
break;
case V_351 :
V_362 |= V_372 ;
break;
case V_353 :
V_362 |= V_373 ;
break;
case V_355 :
break;
}
}
V_362 |= F_129 ( V_329 ) ;
F_6 ( V_5 , V_362 , V_374 ) ;
if ( ! V_125 -> V_181 ) {
V_363 = V_330 ;
if ( V_180 == V_327 - 1 )
V_363 |= V_375 ;
if ( V_332 )
V_363 |= V_376 ;
F_6 ( V_5 , V_363 , V_377 ) ;
}
}
if ( ! V_125 -> V_219 && ! V_125 -> V_181 )
F_118 ( V_5 ) ;
}
static int F_130 ( struct V_4 * V_5 ,
struct V_190 * V_191 ,
struct V_378 * V_379 ,
unsigned int * V_6 )
{
struct V_124 * V_125 = V_5 -> V_126 ;
unsigned int V_380 = ( V_191 -> V_361 + 1 ) >> 1 ;
int V_180 , V_200 ;
unsigned V_381 ;
unsigned int V_201 ;
unsigned long V_218 ;
F_127 ( V_5 , V_191 , 1 , & V_379 -> V_382 ) ;
F_65 ( V_5 ) ;
V_381 = V_125 -> V_292 [ 0 ] ;
if ( V_125 -> V_219 ) {
for ( V_200 = 0 ; V_200 < V_383 ; V_200 ++ ) {
F_35 ( V_5 , V_325 ,
V_29 ) ;
F_66 ( 1 ) ;
}
for ( V_200 = 0 ; V_200 < V_379 -> V_200 ; V_200 ++ ) {
F_35 ( V_5 , V_325 ,
V_29 ) ;
V_201 = 0 ;
for ( V_180 = 0 ; V_180 < V_326 ; V_180 ++ ) {
if ( F_18 ( V_5 , V_227 ) & 0x80 ) {
V_201 = F_12 ( V_5 , V_220 ) ;
V_201 >>= 16 ;
V_201 &= 0xffff ;
break;
}
if ( ! ( F_39 ( V_5 , V_110 ) &
V_194 ) ) {
V_201 = F_12 ( V_5 , V_220 ) ;
V_201 &= 0xffff ;
break;
}
}
if ( V_180 == V_326 ) {
F_42 ( V_5 -> V_25 , L_20 ,
V_26 ) ;
return - V_384 ;
}
V_201 += V_381 ;
V_6 [ V_200 ] = V_201 ;
}
} else if ( V_125 -> V_181 ) {
for ( V_200 = 0 ; V_200 < V_379 -> V_200 ; V_200 ++ ) {
F_35 ( V_5 , V_325 ,
V_29 ) ;
V_218 = 0 ;
for ( V_180 = 0 ; V_180 < V_326 ; V_180 ++ ) {
if ( F_12 ( V_5 , V_183 ) & 0x01 ) {
F_3 ( V_5 , 0x01 ,
V_182 ) ;
V_218 = F_12 ( V_5 , V_221 ) ;
break;
}
}
if ( V_180 == V_326 ) {
F_42 ( V_5 -> V_25 , L_20 ,
V_26 ) ;
return - V_384 ;
}
V_6 [ V_200 ] = ( ( ( V_218 >> 16 ) & 0xFFFF ) + V_381 ) & 0xFFFF ;
}
} else {
for ( V_200 = 0 ; V_200 < V_379 -> V_200 ; V_200 ++ ) {
F_35 ( V_5 , V_325 ,
V_29 ) ;
for ( V_180 = 0 ; V_180 < V_326 ; V_180 ++ ) {
if ( ! ( F_39 ( V_5 , V_110 ) &
V_194 ) )
break;
}
if ( V_180 == V_326 ) {
F_42 ( V_5 -> V_25 , L_20 ,
V_26 ) ;
return - V_384 ;
}
if ( V_125 -> V_128 ) {
V_218 = F_12 ( V_5 , V_385 ) ;
V_218 &= V_380 ;
V_6 [ V_200 ] = V_218 ;
} else {
V_201 = F_15 ( V_5 , V_224 ) ;
V_201 += V_381 ;
V_6 [ V_200 ] = V_201 ;
}
}
}
return V_379 -> V_200 ;
}
static int F_131 ( const struct V_4 * V_5 , unsigned V_386 ,
unsigned int V_127 )
{
struct V_124 * V_125 = V_5 -> V_126 ;
int V_387 ;
switch ( V_127 & V_388 ) {
case V_389 :
default:
V_387 = ( V_386 + V_125 -> V_390 / 2 ) / V_125 -> V_390 ;
break;
case V_391 :
V_387 = ( V_386 ) / V_125 -> V_390 ;
break;
case V_392 :
V_387 = ( V_386 + V_125 -> V_390 - 1 ) / V_125 -> V_390 ;
break;
}
return V_387 - 1 ;
}
static unsigned F_132 ( const struct V_4 * V_5 , int V_393 )
{
struct V_124 * V_125 = V_5 -> V_126 ;
return V_125 -> V_390 * ( V_393 + 1 ) ;
}
static unsigned F_133 ( struct V_4 * V_5 ,
unsigned V_394 )
{
const struct V_207 * V_208 = V_5 -> V_209 ;
struct V_124 * V_125 = V_5 -> V_126 ;
if ( V_125 -> V_219 || V_125 -> V_181 )
return V_208 -> V_395 ;
return V_208 -> V_395 * V_394 ;
}
static int F_134 ( struct V_4 * V_5 , struct V_190 * V_191 ,
struct V_247 * V_248 )
{
const struct V_207 * V_208 = V_5 -> V_209 ;
struct V_124 * V_125 = V_5 -> V_126 ;
int V_396 = 0 ;
unsigned int V_397 ;
unsigned int V_398 ;
V_396 |= F_135 ( & V_248 -> V_399 ,
V_400 | V_401 | V_402 ) ;
V_396 |= F_135 ( & V_248 -> V_403 ,
V_404 | V_402 ) ;
V_398 = V_404 | V_402 ;
if ( V_125 -> V_219 || V_125 -> V_181 )
V_398 |= V_400 ;
V_396 |= F_135 ( & V_248 -> V_405 , V_398 ) ;
V_396 |= F_135 ( & V_248 -> V_406 , V_265 ) ;
V_396 |= F_135 ( & V_248 -> V_264 , V_265 | V_407 ) ;
if ( V_396 )
return 1 ;
V_396 |= F_136 ( V_248 -> V_399 ) ;
V_396 |= F_136 ( V_248 -> V_403 ) ;
V_396 |= F_136 ( V_248 -> V_405 ) ;
V_396 |= F_136 ( V_248 -> V_264 ) ;
if ( V_396 )
return 2 ;
switch ( V_248 -> V_399 ) {
case V_400 :
case V_401 :
V_396 |= F_137 ( & V_248 -> V_408 , 0 ) ;
break;
case V_402 :
V_397 = F_120 ( V_248 -> V_408 ) ;
if ( V_397 > 16 )
V_397 = 16 ;
V_397 |= ( V_248 -> V_408 & ( V_409 | V_410 ) ) ;
V_396 |= F_137 ( & V_248 -> V_408 , V_397 ) ;
break;
}
if ( V_248 -> V_403 == V_404 ) {
V_396 |= F_138 ( & V_248 -> V_411 ,
F_133 ( V_5 , V_248 -> V_293 ) ) ;
V_396 |= F_139 ( & V_248 -> V_411 ,
V_125 -> V_390 * 0xffffff ) ;
} else if ( V_248 -> V_403 == V_402 ) {
unsigned int V_397 = F_120 ( V_248 -> V_411 ) ;
if ( V_397 > 16 )
V_397 = 16 ;
V_397 |= ( V_248 -> V_411 & ( V_409 | V_410 ) ) ;
V_396 |= F_137 ( & V_248 -> V_411 , V_397 ) ;
} else {
V_396 |= F_137 ( & V_248 -> V_411 , 0 ) ;
}
if ( V_248 -> V_405 == V_404 ) {
if ( V_125 -> V_219 || V_125 -> V_181 ) {
V_396 |= F_137 ( & V_248 -> V_412 , 0 ) ;
} else {
V_396 |= F_138 ( & V_248 -> V_412 ,
V_208 -> V_395 ) ;
V_396 |= F_139 ( & V_248 -> V_412 ,
V_125 -> V_390 * 0xffff ) ;
}
} else if ( V_248 -> V_405 == V_402 ) {
unsigned int V_397 = F_120 ( V_248 -> V_412 ) ;
if ( V_397 > 16 )
V_397 = 16 ;
V_397 |= ( V_248 -> V_412 & ( V_338 | V_409 ) ) ;
V_396 |= F_137 ( & V_248 -> V_412 , V_397 ) ;
} else if ( V_248 -> V_405 == V_400 ) {
V_396 |= F_137 ( & V_248 -> V_412 , 0 ) ;
}
V_396 |= F_137 ( & V_248 -> V_413 , V_248 -> V_293 ) ;
if ( V_248 -> V_264 == V_265 ) {
unsigned int V_414 = 0x01000000 ;
if ( V_125 -> V_219 )
V_414 -= V_383 ;
V_396 |= F_139 ( & V_248 -> V_415 , V_414 ) ;
V_396 |= F_138 ( & V_248 -> V_415 , 1 ) ;
} else {
V_396 |= F_137 ( & V_248 -> V_415 , 0 ) ;
}
if ( V_396 )
return 3 ;
if ( V_248 -> V_403 == V_404 ) {
V_397 = V_248 -> V_411 ;
V_248 -> V_411 =
F_132 ( V_5 , F_131 ( V_5 ,
V_248 -> V_411 ,
V_248 -> V_127 ) ) ;
if ( V_397 != V_248 -> V_411 )
V_396 ++ ;
}
if ( V_248 -> V_405 == V_404 ) {
if ( ! V_125 -> V_219 && ! V_125 -> V_181 ) {
V_397 = V_248 -> V_412 ;
V_248 -> V_412 =
F_132 ( V_5 , F_131 ( V_5 ,
V_248 -> V_412 ,
V_248 -> V_127 ) ) ;
if ( V_397 != V_248 -> V_412 )
V_396 ++ ;
if ( V_248 -> V_403 == V_404 &&
V_248 -> V_411 <
V_248 -> V_412 * V_248 -> V_413 ) {
V_248 -> V_411 =
V_248 -> V_412 * V_248 -> V_413 ;
V_396 ++ ;
}
}
}
if ( V_396 )
return 4 ;
return 0 ;
}
static int F_140 ( struct V_4 * V_5 ,
struct V_190 * V_191 ,
unsigned int V_416 )
{
struct V_124 * V_125 = V_5 -> V_126 ;
struct V_247 * V_248 = & V_191 -> V_212 -> V_248 ;
if ( V_416 != V_248 -> V_408 )
return - V_417 ;
F_35 ( V_5 , V_418 | V_125 -> V_232 ,
V_31 ) ;
V_191 -> V_212 -> V_419 = NULL ;
return 1 ;
}
static int F_141 ( struct V_4 * V_5 , struct V_190 * V_191 )
{
struct V_124 * V_125 = V_5 -> V_126 ;
const struct V_247 * V_248 = & V_191 -> V_212 -> V_248 ;
int V_393 ;
int V_420 = 0 ;
int V_421 = 0 ;
int V_422 = 0 ;
unsigned int V_423 ;
int V_424 = 0 ;
if ( V_5 -> V_425 == 0 ) {
F_42 ( V_5 -> V_25 , L_21 ) ;
return - V_295 ;
}
F_65 ( V_5 ) ;
F_127 ( V_5 , V_191 , V_248 -> V_293 , V_248 -> V_426 ) ;
F_35 ( V_5 , V_298 , V_98 ) ;
V_125 -> V_427 &= ~ V_428 ;
F_35 ( V_5 , V_125 -> V_427 ,
V_51 ) ;
switch ( V_248 -> V_399 ) {
case V_401 :
case V_400 :
F_35 ( V_5 ,
F_142 ( 0 ) |
V_429 | V_430 |
F_143 ( 0 ) ,
V_49 ) ;
break;
case V_402 :
{
int V_329 = F_120 ( V_248 -> V_408 ) ;
unsigned int V_188 = F_142 ( 0 ) |
V_429 | F_143 ( V_329 + 1 ) ;
if ( V_248 -> V_408 & V_409 )
V_188 |= V_431 ;
if ( V_248 -> V_408 & V_410 )
V_188 |= V_430 ;
F_35 ( V_5 , V_188 , V_49 ) ;
break;
}
}
V_421 &= ~ V_432 ;
V_421 &= ~ V_433 ;
V_421 &= ~ V_434 ;
F_35 ( V_5 , V_421 , V_35 ) ;
if ( V_248 -> V_293 == 1 || V_125 -> V_219 || V_125 -> V_181 ) {
V_422 |= V_435 ;
V_422 |= F_144 ( 31 ) ;
V_422 |= V_436 ;
} else {
V_422 |= F_144 ( 19 ) ;
}
F_35 ( V_5 , V_422 , V_47 ) ;
V_125 -> V_232 = 0 ;
switch ( V_248 -> V_264 ) {
case V_265 :
V_423 = V_248 -> V_415 - 1 ;
if ( V_125 -> V_219 ) {
V_423 += V_383 ;
}
F_38 ( V_5 , V_423 , V_11 ) ;
V_420 |= V_309 | V_310 | V_437 ;
F_35 ( V_5 , V_420 , V_33 ) ;
F_35 ( V_5 , V_438 , V_29 ) ;
if ( V_423 == 0 ) {
V_125 -> V_232 |= V_233 ;
V_424 |= V_304 ;
if ( V_248 -> V_293 > 1 )
V_422 |=
V_435 | V_439 ;
}
break;
case V_407 :
F_38 ( V_5 , 0 , V_11 ) ;
V_420 |= V_309 | V_310 | V_440 ;
F_35 ( V_5 , V_420 , V_33 ) ;
F_35 ( V_5 , V_438 , V_29 ) ;
break;
}
switch ( V_248 -> V_403 ) {
case V_404 :
V_422 |= V_441 | V_442 ;
F_35 ( V_5 , V_422 ,
V_47 ) ;
V_421 |= F_145 ( 0 ) ;
V_421 &= ~ V_443 ;
F_35 ( V_5 , V_421 , V_35 ) ;
V_393 = F_131 ( V_5 , V_248 -> V_411 ,
V_389 ) ;
F_38 ( V_5 , V_393 , V_13 ) ;
F_35 ( V_5 , V_444 , V_29 ) ;
break;
case V_402 :
if ( V_248 -> V_411 & V_410 )
V_422 |= V_441 ;
if ( V_248 -> V_411 & V_409 )
V_422 |= V_445 ;
if ( V_248 -> V_403 != V_248 -> V_405 ||
( V_248 -> V_411 & ~ V_410 ) !=
( V_248 -> V_412 & ~ V_410 ) )
V_422 |= V_442 ;
V_422 |=
F_146 ( 1 + F_120 ( V_248 -> V_411 ) ) ;
F_35 ( V_5 , V_422 ,
V_47 ) ;
break;
}
switch ( V_248 -> V_405 ) {
case V_404 :
case V_400 :
if ( V_248 -> V_412 == 0 || V_248 -> V_405 == V_400 )
V_393 = 1 ;
else
V_393 = F_131 ( V_5 , V_248 -> V_412 ,
V_389 ) ;
F_35 ( V_5 , 1 , V_43 ) ;
F_35 ( V_5 , V_393 , V_45 ) ;
V_421 &= ~ V_446 ;
V_421 |= V_447 ;
F_35 ( V_5 , V_421 , V_35 ) ;
F_35 ( V_5 , V_448 , V_29 ) ;
V_421 |= V_447 ;
V_421 |= V_446 ;
F_35 ( V_5 , V_421 , V_35 ) ;
break;
case V_402 :
V_420 |= F_147 ( 1 + V_248 -> V_412 ) ;
if ( ( V_248 -> V_412 & V_409 ) == 0 )
V_420 |= V_449 ;
F_35 ( V_5 , V_420 , V_33 ) ;
V_421 |= V_450 | V_451 ;
F_35 ( V_5 , V_421 , V_35 ) ;
break;
}
if ( V_5 -> V_425 ) {
V_424 |= V_305 |
V_300 ;
#ifndef F_58
V_424 |= V_306 ;
#endif
if ( V_248 -> V_127 & V_452
|| ( V_125 -> V_232 & V_233 ) ) {
V_125 -> V_229 = V_230 ;
} else {
V_125 -> V_229 = V_453 ;
}
switch ( V_125 -> V_229 ) {
case V_453 :
#ifdef F_58
F_35 ( V_5 , V_454 ,
V_37 ) ;
#else
F_35 ( V_5 , V_455 ,
V_37 ) ;
#endif
break;
case V_456 :
F_35 ( V_5 , V_457 ,
V_37 ) ;
break;
case V_230 :
#ifdef F_58
F_35 ( V_5 , V_457 ,
V_37 ) ;
#else
F_35 ( V_5 , V_455 ,
V_37 ) ;
#endif
V_424 |= V_304 ;
break;
default:
break;
}
F_35 ( V_5 ,
V_321 |
V_244 |
V_242 |
V_320 |
V_240 |
V_238 |
V_319 ,
V_86 ) ;
F_71 ( V_5 , V_88 ,
V_424 , 1 ) ;
} else {
F_71 ( V_5 , V_88 , ~ 0 , 0 ) ;
}
F_35 ( V_5 , V_322 , V_98 ) ;
switch ( V_248 -> V_403 ) {
case V_404 :
F_35 ( V_5 ,
V_458 | V_459 | V_460 | V_461 ,
V_29 ) ;
break;
case V_402 :
F_35 ( V_5 ,
V_458 | V_459 | V_460 | V_461 ,
V_29 ) ;
break;
}
#ifdef F_58
{
int V_193 = F_104 ( V_5 ) ;
if ( V_193 )
return V_193 ;
}
#endif
if ( V_248 -> V_399 == V_400 ) {
F_35 ( V_5 , V_418 | V_125 -> V_232 ,
V_31 ) ;
V_191 -> V_212 -> V_419 = NULL ;
} else if ( V_248 -> V_399 == V_402 ) {
V_191 -> V_212 -> V_419 = NULL ;
} else {
V_191 -> V_212 -> V_419 = F_140 ;
}
return 0 ;
}
static int F_148 ( struct V_4 * V_5 ,
struct V_190 * V_191 ,
struct V_378 * V_379 , unsigned int * V_6 )
{
struct V_124 * V_125 = V_5 -> V_126 ;
if ( V_379 -> V_200 < 1 )
return - V_417 ;
switch ( V_6 [ 0 ] ) {
case V_462 :
if ( V_125 -> V_128 ) {
if ( V_6 [ 1 ] & ~ ( V_341 |
V_342 |
V_343 |
V_344 ) ) {
return - V_417 ;
}
V_125 -> V_340 = V_6 [ 1 ] ;
} else if ( V_125 -> V_181 ) {
unsigned int V_463 ;
V_463 = V_6 [ 1 ] & 0xf ;
V_125 -> V_340 = V_463 ;
F_6 ( V_5 , V_463 , V_368 ) ;
} else {
unsigned int V_463 ;
unsigned int V_464 ;
V_463 = V_6 [ 1 ] & 0xf ;
V_464 = ( V_6 [ 1 ] >> 4 ) & 0xff ;
if ( V_463 >= 8 )
return - V_417 ;
V_125 -> V_340 = V_463 ;
if ( V_125 -> V_219 ) {
F_9 ( V_5 , V_464 ,
V_465 ) ;
}
}
return 2 ;
default:
break;
}
return - V_417 ;
}
static void F_149 ( struct V_4 * V_5 , struct V_190 * V_191 ,
void * V_6 , unsigned int V_286 ,
unsigned int V_287 )
{
struct V_247 * V_248 = & V_191 -> V_212 -> V_248 ;
unsigned int V_211 = F_83 ( V_191 , V_286 ) ;
unsigned short * V_288 = V_6 ;
unsigned int V_180 ;
for ( V_180 = 0 ; V_180 < V_211 ; V_180 ++ ) {
unsigned int V_330 = F_121 ( V_248 -> V_426 [ V_287 ] ) ;
unsigned short V_133 = V_288 [ V_180 ] ;
if ( F_150 ( V_191 , V_330 ) )
V_133 = F_151 ( V_191 , V_133 ) ;
#ifdef F_58
V_133 = F_152 ( V_133 ) ;
#endif
V_288 [ V_180 ] = V_133 ;
V_287 ++ ;
V_287 %= V_248 -> V_293 ;
}
}
static int F_153 ( struct V_4 * V_5 ,
struct V_190 * V_191 ,
unsigned int V_382 [] ,
unsigned int V_466 , int V_467 )
{
struct V_124 * V_125 = V_5 -> V_126 ;
unsigned int V_330 ;
unsigned int V_329 ;
unsigned int V_468 ;
int V_180 ;
int V_469 = 0 ;
if ( V_467 ) {
for ( V_180 = 0 ; V_180 < V_191 -> V_327 ; ++ V_180 ) {
V_125 -> V_470 [ V_180 ] &= ~ V_471 ;
F_9 ( V_5 , V_125 -> V_470 [ V_180 ] ,
F_154 ( V_180 ) ) ;
F_9 ( V_5 , 0xf , F_155 ( V_180 ) ) ;
}
}
for ( V_180 = 0 ; V_180 < V_466 ; V_180 ++ ) {
const struct V_472 * V_473 ;
V_329 = F_120 ( V_382 [ V_180 ] ) ;
V_330 = F_121 ( V_382 [ V_180 ] ) ;
V_473 = V_191 -> V_474 -> V_330 + V_330 ;
V_469 = 0 ;
V_468 = 0 ;
switch ( V_473 -> V_475 - V_473 -> V_476 ) {
case 20000000 :
V_468 |= V_477 ;
F_9 ( V_5 , 0 ,
F_156 ( V_329 ) ) ;
break;
case 10000000 :
V_468 |= V_478 ;
F_9 ( V_5 , 0 ,
F_156 ( V_329 ) ) ;
break;
case 4000000 :
V_468 |= V_477 ;
F_9 ( V_5 , V_479 ,
F_156 ( V_329 ) ) ;
break;
case 2000000 :
V_468 |= V_478 ;
F_9 ( V_5 , V_479 ,
F_156 ( V_329 ) ) ;
break;
default:
F_42 ( V_5 -> V_25 ,
L_22 ,
V_26 ) ;
break;
}
switch ( V_473 -> V_475 + V_473 -> V_476 ) {
case 0 :
V_468 |= V_480 ;
break;
case 10000000 :
V_468 |= V_481 ;
break;
default:
F_42 ( V_5 -> V_25 ,
L_23 ,
V_26 ) ;
break;
}
if ( V_467 )
V_468 |= V_471 ;
F_9 ( V_5 , V_468 , F_154 ( V_329 ) ) ;
V_125 -> V_470 [ V_329 ] = V_468 ;
F_9 ( V_5 , V_180 , F_155 ( V_329 ) ) ;
}
return V_469 ;
}
static int F_157 ( struct V_4 * V_5 ,
struct V_190 * V_191 ,
unsigned int V_382 [] ,
unsigned int V_466 )
{
struct V_124 * V_125 = V_5 -> V_126 ;
unsigned int V_330 ;
unsigned int V_329 ;
unsigned int V_468 ;
int V_180 ;
int V_469 = 0 ;
for ( V_180 = 0 ; V_180 < V_466 ; V_180 ++ ) {
V_329 = F_120 ( V_382 [ V_180 ] ) ;
V_330 = F_121 ( V_382 [ V_180 ] ) ;
V_468 = F_158 ( V_329 ) ;
if ( F_150 ( V_191 , V_330 ) ) {
V_468 |= V_482 ;
V_469 = ( V_191 -> V_361 + 1 ) >> 1 ;
} else {
V_469 = 0 ;
}
if ( F_159 ( V_191 , V_330 ) )
V_468 |= V_483 ;
if ( V_382 [ V_180 ] & V_484 )
V_468 |= V_485 ;
V_468 |= ( F_123 ( V_382 [ V_180 ] ) ==
V_355 ) ? V_486 : 0 ;
F_6 ( V_5 , V_468 , V_487 ) ;
V_125 -> V_470 [ V_329 ] = V_468 ;
}
return V_469 ;
}
static int F_160 ( struct V_4 * V_5 ,
struct V_190 * V_191 ,
unsigned int V_382 [] , unsigned int V_466 ,
int V_467 )
{
struct V_124 * V_125 = V_5 -> V_126 ;
if ( V_125 -> V_128 )
return F_153 ( V_5 , V_191 , V_382 , V_466 ,
V_467 ) ;
else
return F_157 ( V_5 , V_191 , V_382 , V_466 ) ;
}
static int F_161 ( struct V_4 * V_5 ,
struct V_190 * V_191 ,
struct V_378 * V_379 ,
unsigned int * V_6 )
{
struct V_124 * V_125 = V_5 -> V_126 ;
unsigned int V_329 = F_120 ( V_379 -> V_382 ) ;
unsigned int V_330 = F_121 ( V_379 -> V_382 ) ;
int V_7 ;
int V_180 ;
if ( V_125 -> V_203 ) {
F_68 ( V_5 , 1 << V_329 , V_488 ) ;
V_7 = F_162 ( V_329 ) ;
} else if ( V_125 -> V_128 ) {
V_7 = F_163 ( V_329 ) ;
} else {
V_7 = ( V_329 ) ? V_489 : V_490 ;
}
F_160 ( V_5 , V_191 , & V_379 -> V_382 , 1 , 0 ) ;
for ( V_180 = 0 ; V_180 < V_379 -> V_200 ; V_180 ++ ) {
unsigned int V_133 = V_6 [ V_180 ] ;
V_191 -> V_491 [ V_329 ] = V_133 ;
if ( V_125 -> V_203 ) {
V_133 = F_151 ( V_191 , V_133 ) ;
F_68 ( V_5 , V_133 , V_7 ) ;
} else if ( V_125 -> V_128 ) {
F_6 ( V_5 , V_133 , V_7 ) ;
} else {
if ( F_150 ( V_191 , V_330 ) )
V_133 = F_151 ( V_191 , V_133 ) ;
F_6 ( V_5 , V_133 , V_7 ) ;
}
}
return V_379 -> V_200 ;
}
static int F_164 ( struct V_4 * V_5 ,
struct V_190 * V_191 ,
struct V_378 * V_379 , unsigned int * V_6 )
{
const struct V_207 * V_208 = V_5 -> V_209 ;
struct V_124 * V_125 = V_5 -> V_126 ;
unsigned int V_210 ;
switch ( V_6 [ 0 ] ) {
case V_492 :
switch ( V_6 [ 1 ] ) {
case V_164 :
V_210 = F_165 ( V_191 ,
V_208 -> V_215 ) ;
V_6 [ 2 ] = 1 + V_210 ;
if ( V_125 -> V_130 )
V_6 [ 2 ] += V_125 -> V_130 -> V_493 ;
break;
case V_161 :
V_6 [ 2 ] = 0 ;
break;
default:
return - V_417 ;
}
return 0 ;
default:
break;
}
return - V_417 ;
}
static int F_166 ( struct V_4 * V_5 ,
struct V_190 * V_191 ,
unsigned int V_416 )
{
struct V_124 * V_125 = V_5 -> V_126 ;
struct V_247 * V_248 = & V_191 -> V_212 -> V_248 ;
int V_283 ;
int V_494 ;
int V_180 ;
static const int V_179 = 1000 ;
if ( V_416 != V_248 -> V_408 )
return - V_417 ;
V_191 -> V_212 -> V_419 = NULL ;
F_71 ( V_5 , V_92 ,
V_284 | V_285 , 0 ) ;
V_494 = V_285 ;
#ifdef F_58
F_35 ( V_5 , 1 , V_75 ) ;
if ( V_125 -> V_203 )
F_69 ( V_5 , 0x6 , V_216 ) ;
V_283 = F_108 ( V_5 ) ;
if ( V_283 )
return V_283 ;
V_283 = F_78 ( V_5 ) ;
if ( V_283 < 0 )
return V_283 ;
#else
V_283 = F_84 ( V_5 , V_191 ) ;
if ( V_283 == 0 )
return - V_199 ;
V_494 |= V_284 ;
#endif
F_35 ( V_5 , V_125 -> V_495 | V_496 ,
V_61 ) ;
F_35 ( V_5 , V_125 -> V_495 , V_61 ) ;
for ( V_180 = 0 ; V_180 < V_179 ; V_180 ++ ) {
F_66 ( 1 ) ;
if ( ( F_39 ( V_5 , V_120 ) &
V_497 ) == 0 )
break;
}
if ( V_180 == V_179 ) {
F_42 ( V_5 -> V_25 ,
L_24 ) ;
return - V_295 ;
}
F_35 ( V_5 , V_270 , V_90 ) ;
F_71 ( V_5 , V_92 , V_494 , 1 ) ;
F_35 ( V_5 , V_125 -> V_498 |
V_499 | V_500 | V_501 |
V_502 | V_503 ,
V_53 ) ;
F_35 ( V_5 , V_125 -> V_504 | V_505 ,
V_55 ) ;
return 0 ;
}
static int F_167 ( struct V_4 * V_5 , struct V_190 * V_191 )
{
const struct V_207 * V_208 = V_5 -> V_209 ;
struct V_124 * V_125 = V_5 -> V_126 ;
const struct V_247 * V_248 = & V_191 -> V_212 -> V_248 ;
int V_188 ;
int V_180 ;
unsigned V_506 ;
if ( V_5 -> V_425 == 0 ) {
F_42 ( V_5 -> V_25 , L_21 ) ;
return - V_295 ;
}
F_35 ( V_5 , V_507 , V_98 ) ;
F_35 ( V_5 , V_508 , V_53 ) ;
if ( V_125 -> V_203 ) {
F_68 ( V_5 , V_509 , V_510 ) ;
V_188 = 0 ;
for ( V_180 = 0 ; V_180 < V_248 -> V_293 ; V_180 ++ ) {
int V_329 ;
V_329 = F_120 ( V_248 -> V_426 [ V_180 ] ) ;
V_188 |= 1 << V_329 ;
F_68 ( V_5 , V_329 , V_511 ) ;
}
F_68 ( V_5 , V_188 , V_512 ) ;
}
F_160 ( V_5 , V_191 , V_248 -> V_426 , V_248 -> V_293 , 1 ) ;
if ( V_248 -> V_264 == V_407 ) {
V_125 -> V_513 |= V_514 ;
V_125 -> V_513 &= ~ V_515 ;
} else {
V_125 -> V_513 &= ~ V_514 ;
V_125 -> V_513 |= V_515 ;
}
F_35 ( V_5 , V_125 -> V_513 , V_57 ) ;
switch ( V_248 -> V_399 ) {
case V_401 :
case V_400 :
V_125 -> V_516 &=
~ ( V_517 | F_168 ( - 1 ) ) ;
V_125 -> V_516 |= V_518 | V_519 ;
F_35 ( V_5 , V_125 -> V_516 ,
V_69 ) ;
break;
case V_402 :
V_125 -> V_516 =
F_168 ( F_120 ( V_248 -> V_408 ) + 1 ) ;
if ( V_248 -> V_408 & V_409 )
V_125 -> V_516 |= V_517 ;
if ( V_248 -> V_408 & V_410 )
V_125 -> V_516 |= V_518 ;
F_35 ( V_5 , V_125 -> V_516 ,
V_69 ) ;
break;
default:
F_2 () ;
break;
}
V_125 -> V_495 &= ~ V_520 ;
F_35 ( V_5 , V_125 -> V_495 , V_61 ) ;
F_35 ( V_5 , V_125 -> V_513 , V_57 ) ;
V_125 -> V_521 &= ~ V_522 ;
F_35 ( V_5 , V_125 -> V_521 , V_59 ) ;
if ( V_248 -> V_264 == V_407 )
F_38 ( V_5 , 0xffffff , V_15 ) ;
else
F_38 ( V_5 , 0 , V_15 ) ;
F_35 ( V_5 , V_523 , V_53 ) ;
V_125 -> V_521 &= ~ V_524 ;
F_35 ( V_5 , V_125 -> V_521 , V_59 ) ;
switch ( V_248 -> V_264 ) {
case V_265 :
if ( V_125 -> V_128 ) {
F_38 ( V_5 , V_248 -> V_415 - 1 ,
V_17 ) ;
F_35 ( V_5 , V_525 , V_53 ) ;
} else {
F_38 ( V_5 , V_248 -> V_415 ,
V_17 ) ;
F_35 ( V_5 , V_525 , V_53 ) ;
F_38 ( V_5 , V_248 -> V_415 - 1 ,
V_17 ) ;
}
break;
case V_407 :
F_38 ( V_5 , 0xffffff , V_17 ) ;
F_35 ( V_5 , V_525 , V_53 ) ;
F_38 ( V_5 , 0xffffff , V_17 ) ;
break;
default:
F_38 ( V_5 , 0 , V_17 ) ;
F_35 ( V_5 , V_525 , V_53 ) ;
F_38 ( V_5 , V_248 -> V_415 , V_17 ) ;
}
V_125 -> V_513 &=
~ ( F_169 ( 0x1f ) | V_526 |
F_170 ( 0x1f ) | V_527 ) ;
switch ( V_248 -> V_403 ) {
case V_404 :
V_125 -> V_504 &= ~ V_528 ;
V_506 =
F_131 ( V_5 , V_248 -> V_411 ,
V_389 ) ;
F_38 ( V_5 , 1 , V_19 ) ;
F_35 ( V_5 , V_529 , V_53 ) ;
F_38 ( V_5 , V_506 , V_19 ) ;
break;
case V_402 :
V_125 -> V_513 |=
F_170 ( V_248 -> V_411 ) ;
if ( V_248 -> V_411 & V_409 )
V_125 -> V_513 |= V_527 ;
V_125 -> V_504 |= V_528 ;
break;
default:
F_2 () ;
break;
}
F_35 ( V_5 , V_125 -> V_504 , V_55 ) ;
F_35 ( V_5 , V_125 -> V_513 , V_57 ) ;
V_125 -> V_521 &=
~ ( F_171 ( 3 ) | V_530 ) ;
F_35 ( V_5 , V_125 -> V_521 , V_59 ) ;
if ( V_248 -> V_413 > 1 ) {
V_125 -> V_513 |= V_531 ;
F_35 ( V_5 ,
F_172 ( V_248 -> V_413 - 1 ) |
F_173 ( V_532 ) ,
V_63 ) ;
} else {
unsigned V_188 ;
V_125 -> V_513 &= ~ V_531 ;
V_188 = F_173 ( V_532 ) ;
if ( V_125 -> V_128 || V_125 -> V_203 ) {
V_188 |= F_172 ( 0 ) ;
} else {
V_188 |=
F_172 ( F_120 ( V_248 -> V_426 [ 0 ] ) ) ;
}
F_35 ( V_5 , V_188 , V_63 ) ;
}
F_35 ( V_5 , V_125 -> V_513 , V_57 ) ;
F_35 ( V_5 , V_503 | V_502 ,
V_53 ) ;
V_125 -> V_495 |= V_533 ;
F_35 ( V_5 , V_125 -> V_495 , V_61 ) ;
V_125 -> V_521 &= ~ V_534 ;
#ifdef F_58
V_125 -> V_521 |= V_535 ;
#else
V_125 -> V_521 |= V_536 ;
#endif
V_125 -> V_521 &= ~ V_537 ;
F_35 ( V_5 , V_125 -> V_521 , V_59 ) ;
V_188 = V_538 | V_539 |
V_540 ;
if ( V_208 -> V_215 )
V_188 |= V_541 ;
else
V_188 |= V_542 ;
#if 0
if (devpriv->is_m_series)
bits |= AO_Number_Of_DAC_Packages;
#endif
F_35 ( V_5 , V_188 , V_65 ) ;
F_35 ( V_5 , V_543 , V_67 ) ;
F_35 ( V_5 , V_544 , V_98 ) ;
if ( V_248 -> V_264 == V_265 ) {
F_35 ( V_5 , V_268 ,
V_90 ) ;
F_71 ( V_5 , V_92 ,
V_545 , 1 ) ;
}
V_191 -> V_212 -> V_419 = F_166 ;
return 0 ;
}
static int F_174 ( struct V_4 * V_5 , struct V_190 * V_191 ,
struct V_247 * V_248 )
{
const struct V_207 * V_208 = V_5 -> V_209 ;
struct V_124 * V_125 = V_5 -> V_126 ;
int V_396 = 0 ;
unsigned int V_397 ;
V_396 |= F_135 ( & V_248 -> V_399 , V_401 | V_402 ) ;
V_396 |= F_135 ( & V_248 -> V_403 ,
V_404 | V_402 ) ;
V_396 |= F_135 ( & V_248 -> V_405 , V_400 ) ;
V_396 |= F_135 ( & V_248 -> V_406 , V_265 ) ;
V_396 |= F_135 ( & V_248 -> V_264 , V_265 | V_407 ) ;
if ( V_396 )
return 1 ;
V_396 |= F_136 ( V_248 -> V_399 ) ;
V_396 |= F_136 ( V_248 -> V_403 ) ;
V_396 |= F_136 ( V_248 -> V_264 ) ;
if ( V_396 )
return 2 ;
switch ( V_248 -> V_399 ) {
case V_401 :
V_396 |= F_137 ( & V_248 -> V_408 , 0 ) ;
break;
case V_402 :
V_397 = F_120 ( V_248 -> V_408 ) ;
if ( V_397 > 18 )
V_397 = 18 ;
V_397 |= ( V_248 -> V_408 & ( V_409 | V_410 ) ) ;
V_396 |= F_137 ( & V_248 -> V_408 , V_397 ) ;
break;
}
if ( V_248 -> V_403 == V_404 ) {
V_396 |= F_138 ( & V_248 -> V_411 ,
V_208 -> V_546 ) ;
V_396 |= F_139 ( & V_248 -> V_411 ,
V_125 -> V_390 * 0xffffff ) ;
}
V_396 |= F_137 ( & V_248 -> V_412 , 0 ) ;
V_396 |= F_137 ( & V_248 -> V_413 , V_248 -> V_293 ) ;
if ( V_248 -> V_264 == V_265 )
V_396 |= F_139 ( & V_248 -> V_415 , 0x00ffffff ) ;
else
V_396 |= F_137 ( & V_248 -> V_415 , 0 ) ;
if ( V_396 )
return 3 ;
if ( V_248 -> V_403 == V_404 ) {
V_397 = V_248 -> V_411 ;
V_248 -> V_411 =
F_132 ( V_5 , F_131 ( V_5 ,
V_248 -> V_411 ,
V_248 -> V_127 ) ) ;
if ( V_397 != V_248 -> V_411 )
V_396 ++ ;
}
if ( V_396 )
return 4 ;
return 0 ;
}
static int F_175 ( struct V_4 * V_5 , struct V_190 * V_191 )
{
struct V_124 * V_125 = V_5 -> V_126 ;
F_61 ( V_5 ) ;
F_35 ( V_5 , V_507 , V_98 ) ;
F_35 ( V_5 , V_508 , V_53 ) ;
F_71 ( V_5 , V_92 , ~ 0 , 0 ) ;
F_35 ( V_5 , V_538 , V_65 ) ;
F_35 ( V_5 , 0x3f98 , V_90 ) ;
F_35 ( V_5 , V_538 | V_539 |
V_540 , V_65 ) ;
F_35 ( V_5 , 0 , V_63 ) ;
F_35 ( V_5 , 0 , V_67 ) ;
V_125 -> V_498 = 0 ;
F_35 ( V_5 , V_125 -> V_498 , V_53 ) ;
V_125 -> V_504 = 0 ;
F_35 ( V_5 , V_125 -> V_504 , V_55 ) ;
V_125 -> V_513 = 0 ;
F_35 ( V_5 , V_125 -> V_513 , V_57 ) ;
V_125 -> V_521 = 0 ;
F_35 ( V_5 , V_125 -> V_521 , V_59 ) ;
if ( V_125 -> V_128 )
V_125 -> V_495 = V_547 ;
else
V_125 -> V_495 = 0 ;
F_35 ( V_5 , V_125 -> V_495 , V_61 ) ;
V_125 -> V_516 = 0 ;
F_35 ( V_5 , V_125 -> V_516 ,
V_69 ) ;
if ( V_125 -> V_203 ) {
unsigned V_548 = 0 ;
unsigned V_180 ;
for ( V_180 = 0 ; V_180 < V_191 -> V_327 ; ++ V_180 )
V_548 |= 1 << V_180 ;
F_68 ( V_5 , V_548 , V_488 ) ;
F_68 ( V_5 , V_509 , V_510 ) ;
}
F_35 ( V_5 , V_544 , V_98 ) ;
return 0 ;
}
static int F_176 ( struct V_4 * V_5 ,
struct V_190 * V_191 ,
struct V_378 * V_379 ,
unsigned int * V_6 )
{
struct V_124 * V_125 = V_5 -> V_126 ;
int V_283 ;
V_283 = F_177 ( V_5 , V_191 , V_379 , V_6 , 0 ) ;
if ( V_283 )
return V_283 ;
V_125 -> V_549 &= ~ V_550 ;
V_125 -> V_549 |= F_178 ( V_191 -> V_551 ) ;
F_35 ( V_5 , V_125 -> V_549 , V_77 ) ;
return V_379 -> V_200 ;
}
static int F_179 ( struct V_4 * V_5 ,
struct V_190 * V_191 ,
struct V_378 * V_379 ,
unsigned int * V_6 )
{
struct V_124 * V_125 = V_5 -> V_126 ;
if ( ( V_6 [ 0 ] & ( V_552 | V_553 ) ) && V_125 -> V_554 )
return - V_159 ;
if ( F_180 ( V_191 , V_6 ) ) {
V_125 -> V_555 &= ~ V_556 ;
V_125 -> V_555 |= F_181 ( V_191 -> V_557 ) ;
F_35 ( V_5 , V_125 -> V_555 , V_558 ) ;
}
V_6 [ 1 ] = F_39 ( V_5 , V_559 ) ;
return V_379 -> V_200 ;
}
static int F_182 ( struct V_4 * V_5 ,
struct V_190 * V_191 ,
struct V_378 * V_379 ,
unsigned int * V_6 )
{
int V_283 ;
V_283 = F_177 ( V_5 , V_191 , V_379 , V_6 , 0 ) ;
if ( V_283 )
return V_283 ;
F_3 ( V_5 , V_191 -> V_551 , V_560 ) ;
return V_379 -> V_200 ;
}
static int F_183 ( struct V_4 * V_5 ,
struct V_190 * V_191 ,
struct V_378 * V_379 ,
unsigned int * V_6 )
{
if ( F_180 ( V_191 , V_6 ) )
F_3 ( V_5 , V_191 -> V_557 , V_561 ) ;
V_6 [ 1 ] = F_12 ( V_5 , V_562 ) ;
return V_379 -> V_200 ;
}
static int F_184 ( struct V_4 * V_5 ,
struct V_190 * V_191 ,
struct V_247 * V_248 )
{
int V_180 ;
for ( V_180 = 0 ; V_180 < V_248 -> V_293 ; ++ V_180 ) {
unsigned int V_329 = F_120 ( V_248 -> V_426 [ V_180 ] ) ;
if ( V_329 != V_180 )
return - V_417 ;
}
return 0 ;
}
static int F_185 ( struct V_4 * V_5 ,
struct V_190 * V_191 , struct V_247 * V_248 )
{
int V_396 = 0 ;
int V_397 ;
V_396 |= F_135 ( & V_248 -> V_399 , V_401 ) ;
V_396 |= F_135 ( & V_248 -> V_403 , V_402 ) ;
V_396 |= F_135 ( & V_248 -> V_405 , V_400 ) ;
V_396 |= F_135 ( & V_248 -> V_406 , V_265 ) ;
V_396 |= F_135 ( & V_248 -> V_264 , V_407 ) ;
if ( V_396 )
return 1 ;
V_396 |= F_137 ( & V_248 -> V_408 , 0 ) ;
V_397 = V_248 -> V_411 ;
V_397 &= F_186 ( V_563 , 0 , 0 , V_409 ) ;
if ( V_397 != V_248 -> V_411 )
V_396 |= - V_417 ;
V_396 |= F_137 ( & V_248 -> V_412 , 0 ) ;
V_396 |= F_137 ( & V_248 -> V_413 , V_248 -> V_293 ) ;
V_396 |= F_137 ( & V_248 -> V_415 , 0 ) ;
if ( V_396 )
return 3 ;
if ( V_248 -> V_426 && V_248 -> V_293 > 0 )
V_396 |= F_184 ( V_5 , V_191 , V_248 ) ;
if ( V_396 )
return 5 ;
return 0 ;
}
static int F_187 ( struct V_4 * V_5 ,
struct V_190 * V_191 ,
unsigned int V_416 )
{
struct V_247 * V_248 = & V_191 -> V_212 -> V_248 ;
const unsigned V_179 = 1000 ;
int V_193 = 0 ;
unsigned V_180 ;
#ifdef F_58
struct V_124 * V_125 = V_5 -> V_126 ;
unsigned long V_127 ;
#endif
if ( V_416 != V_248 -> V_408 )
return - V_417 ;
V_191 -> V_212 -> V_419 = NULL ;
F_109 ( V_191 , V_191 -> V_212 -> V_294 ) ;
#ifdef F_58
F_36 ( & V_125 -> V_156 , V_127 ) ;
if ( V_125 -> V_172 ) {
F_106 ( V_125 -> V_172 , 32 , 32 ) ;
F_107 ( V_125 -> V_172 ) ;
} else {
F_42 ( V_5 -> V_25 , L_25 ) ;
V_193 = - V_295 ;
}
F_37 ( & V_125 -> V_156 , V_127 ) ;
if ( V_193 < 0 )
return V_193 ;
#endif
for ( V_180 = 0 ; V_180 < V_179 ; ++ V_180 ) {
if ( F_12 ( V_5 , V_564 ) & V_565 )
break;
F_66 ( 10 ) ;
}
if ( V_180 == V_179 ) {
F_42 ( V_5 -> V_25 , L_26 ) ;
V_191 -> V_566 ( V_5 , V_191 ) ;
return - V_295 ;
}
F_3 ( V_5 , V_567 | V_568 |
V_569 ,
V_570 ) ;
return V_193 ;
}
static int F_188 ( struct V_4 * V_5 , struct V_190 * V_191 )
{
const struct V_247 * V_248 = & V_191 -> V_212 -> V_248 ;
unsigned V_571 = V_572 | V_573 ;
int V_193 ;
F_3 ( V_5 , V_574 , V_570 ) ;
switch ( V_248 -> V_403 ) {
case V_402 :
V_571 |=
F_120 ( V_248 -> V_411 ) &
V_563 ;
break;
default:
F_2 () ;
break;
}
if ( V_248 -> V_411 & V_409 )
V_571 |= V_575 ;
F_3 ( V_5 , V_571 , V_576 ) ;
if ( V_191 -> V_551 ) {
F_3 ( V_5 , V_191 -> V_557 , V_577 ) ;
F_3 ( V_5 , V_578 , V_570 ) ;
F_3 ( V_5 , V_191 -> V_551 , V_579 ) ;
} else {
F_42 ( V_5 -> V_25 ,
L_27 ) ;
return - V_295 ;
}
V_193 = F_57 ( V_5 ) ;
if ( V_193 < 0 )
return V_193 ;
V_191 -> V_212 -> V_419 = F_187 ;
return 0 ;
}
static int F_189 ( struct V_4 * V_5 , struct V_190 * V_191 )
{
F_3 ( V_5 , V_580 | V_581 |
V_582 |
V_583 ,
V_570 ) ;
F_3 ( V_5 , 0 , V_579 ) ;
F_63 ( V_5 ) ;
return 0 ;
}
static void F_190 ( struct V_4 * V_5 )
{
struct V_124 * V_125 = V_5 -> V_126 ;
unsigned V_584 ;
struct V_190 * V_191 = & V_5 -> V_234 [ V_585 ] ;
#ifdef F_58
unsigned long V_127 ;
#endif
if ( ! V_125 -> V_128 )
return;
#ifdef F_58
F_36 ( & V_125 -> V_156 , V_127 ) ;
if ( V_125 -> V_172 ) {
unsigned V_586 =
F_191 ( V_125 -> V_172 ) ;
if ( V_586 & V_250 ) {
F_4 ( V_587 ,
V_125 -> V_130 -> V_588 +
F_192 ( V_125 -> V_172 -> V_144 ) ) ;
}
F_77 ( V_125 -> V_172 , V_191 ) ;
}
F_37 ( & V_125 -> V_156 , V_127 ) ;
#endif
V_584 = F_12 ( V_5 , V_564 ) ;
if ( V_584 & ( V_589 | V_590 ) ) {
F_3 ( V_5 , V_591 ,
V_570 ) ;
V_191 -> V_212 -> V_213 |= V_214 ;
}
if ( V_584 & V_592 ) {
F_3 ( V_5 , V_582 ,
V_570 ) ;
}
F_95 ( V_5 , V_191 ) ;
}
static int F_193 ( struct V_4 * V_5 ,
struct V_190 * V_191 ,
unsigned char V_593 ,
unsigned char * V_594 )
{
struct V_124 * V_125 = V_5 -> V_126 ;
unsigned int V_595 ;
int V_396 = 0 , V_323 = 20 ;
V_125 -> V_555 &= ~ V_596 ;
V_125 -> V_555 |= F_194 ( V_593 ) ;
F_35 ( V_5 , V_125 -> V_555 , V_558 ) ;
V_595 = F_39 ( V_5 , V_118 ) ;
if ( V_595 & V_597 ) {
V_396 = - V_159 ;
goto Error;
}
V_125 -> V_549 |= V_598 ;
F_35 ( V_5 , V_125 -> V_549 , V_77 ) ;
V_125 -> V_549 &= ~ V_598 ;
while ( ( V_595 = F_39 ( V_5 , V_118 ) ) &
V_597 ) {
F_66 ( ( V_125 -> V_554 + 999 ) / 1000 ) ;
if ( -- V_323 < 0 ) {
F_42 ( V_5 -> V_25 ,
L_28 ,
V_26 ) ;
V_396 = - V_384 ;
goto Error;
}
}
F_66 ( ( V_125 -> V_554 + 999 ) / 1000 ) ;
if ( V_594 != NULL )
* V_594 = F_39 ( V_5 , V_116 ) ;
Error:
F_35 ( V_5 , V_125 -> V_549 , V_77 ) ;
return V_396 ;
}
static int F_195 ( struct V_4 * V_5 ,
struct V_190 * V_191 ,
unsigned char V_593 ,
unsigned char * V_594 )
{
struct V_124 * V_125 = V_5 -> V_126 ;
unsigned char V_380 , V_599 = 0 ;
F_66 ( ( V_125 -> V_554 + 999 ) / 1000 ) ;
for ( V_380 = 0x80 ; V_380 ; V_380 >>= 1 ) {
V_125 -> V_555 &= ~ V_553 ;
if ( V_593 & V_380 )
V_125 -> V_555 |= V_553 ;
F_35 ( V_5 , V_125 -> V_555 , V_558 ) ;
V_125 -> V_549 |= V_600 ;
F_35 ( V_5 , V_125 -> V_549 , V_77 ) ;
F_66 ( ( V_125 -> V_554 + 999 ) / 2000 ) ;
V_125 -> V_549 &= ~ V_600 ;
F_35 ( V_5 , V_125 -> V_549 , V_77 ) ;
F_66 ( ( V_125 -> V_554 + 999 ) / 2000 ) ;
if ( F_39 ( V_5 , V_559 ) & V_552 )
V_599 |= V_380 ;
}
if ( V_594 )
* V_594 = V_599 ;
return 0 ;
}
static int F_196 ( struct V_4 * V_5 ,
struct V_190 * V_191 ,
struct V_378 * V_379 ,
unsigned int * V_6 )
{
struct V_124 * V_125 = V_5 -> V_126 ;
int V_396 = V_379 -> V_200 ;
unsigned char V_601 , V_602 = 0 ;
if ( V_379 -> V_200 != 2 )
return - V_417 ;
switch ( V_6 [ 0 ] ) {
case V_603 :
V_125 -> V_604 = 1 ;
V_125 -> V_549 |= V_605 ;
if ( V_6 [ 1 ] == V_606 ) {
V_125 -> V_604 = 0 ;
V_125 -> V_549 &= ~ ( V_605 |
V_600 ) ;
V_6 [ 1 ] = V_606 ;
V_125 -> V_554 = V_6 [ 1 ] ;
} else if ( V_6 [ 1 ] <= V_607 ) {
V_125 -> V_549 &= ~ V_608 ;
V_125 -> V_609 |= V_610 ;
V_125 -> V_609 &= ~ V_611 ;
V_6 [ 1 ] = V_607 ;
V_125 -> V_554 = V_6 [ 1 ] ;
} else if ( V_6 [ 1 ] <= V_612 ) {
V_125 -> V_549 &= ~ V_608 ;
V_125 -> V_609 |= V_610 |
V_611 ;
V_6 [ 1 ] = V_612 ;
V_125 -> V_554 = V_6 [ 1 ] ;
} else if ( V_6 [ 1 ] <= V_613 ) {
V_125 -> V_549 |= V_608 ;
V_125 -> V_609 |= V_610 |
V_611 ;
V_6 [ 1 ] = V_613 ;
V_125 -> V_554 = V_6 [ 1 ] ;
} else {
V_125 -> V_549 &= ~ ( V_605 |
V_600 ) ;
V_125 -> V_604 = 0 ;
V_6 [ 1 ] = ( V_6 [ 1 ] / 1000 ) * 1000 ;
V_125 -> V_554 = V_6 [ 1 ] ;
}
F_35 ( V_5 , V_125 -> V_549 , V_77 ) ;
F_35 ( V_5 , V_125 -> V_609 ,
V_71 ) ;
return 1 ;
break;
case V_614 :
if ( V_125 -> V_554 == 0 )
return - V_417 ;
V_601 = V_6 [ 1 ] & 0xFF ;
if ( V_125 -> V_604 ) {
V_396 = F_193 ( V_5 , V_191 , V_601 ,
& V_602 ) ;
} else if ( V_125 -> V_554 > 0 ) {
V_396 = F_195 ( V_5 , V_191 , V_601 ,
& V_602 ) ;
} else {
F_42 ( V_5 -> V_25 , L_29 ,
V_26 ) ;
return - V_417 ;
}
if ( V_396 < 0 )
return V_396 ;
V_6 [ 1 ] = V_602 & 0xFF ;
return V_379 -> V_200 ;
break;
default:
return - V_417 ;
}
}
static void F_197 ( struct V_4 * V_5 , struct V_190 * V_191 )
{
int V_180 ;
for ( V_180 = 0 ; V_180 < V_191 -> V_327 ; V_180 ++ ) {
F_68 ( V_5 , F_158 ( V_180 ) | 0x0 ,
V_615 ) ;
}
F_68 ( V_5 , 0x0 , V_616 ) ;
}
static unsigned F_198 ( enum V_617 V_7 )
{
unsigned V_618 ;
switch ( V_7 ) {
case V_619 :
V_618 = F_27 ( 0 ) ;
break;
case V_620 :
V_618 = F_27 ( 1 ) ;
break;
case V_621 :
V_618 = F_28 ( 0 ) ;
break;
case V_622 :
V_618 = F_28 ( 1 ) ;
break;
case V_623 :
V_618 = F_32 ( 0 ) ;
break;
case V_624 :
V_618 = F_32 ( 1 ) ;
break;
case V_625 :
V_618 = F_33 ( 0 ) ;
break;
case V_626 :
V_618 = F_33 ( 1 ) ;
break;
case V_627 :
V_618 = F_30 ( 0 ) ;
break;
case V_628 :
V_618 = F_30 ( 1 ) ;
break;
case V_629 :
V_618 = F_22 ( 0 ) ;
break;
case V_630 :
V_618 = F_22 ( 1 ) ;
break;
case V_631 :
V_618 = F_23 ( 0 ) ;
break;
case V_632 :
V_618 = F_23 ( 1 ) ;
break;
case V_633 :
V_618 = F_29 ( 0 ) ;
break;
case V_634 :
V_618 = F_29 ( 1 ) ;
break;
case V_635 :
V_618 = V_122 ;
break;
case V_636 :
V_618 = V_98 ;
break;
case V_637 :
V_618 = V_118 ;
break;
case V_638 :
V_618 = V_120 ;
break;
case V_639 :
V_618 = V_86 ;
break;
case V_640 :
V_618 = V_90 ;
break;
case V_641 :
V_618 = V_110 ;
break;
case V_642 :
V_618 = V_112 ;
break;
case V_643 :
V_618 = V_88 ;
break;
case V_644 :
V_618 = V_92 ;
break;
default:
F_199 ( L_30 ,
V_26 , V_7 ) ;
F_2 () ;
return 0 ;
}
return V_618 ;
}
static void F_200 ( struct V_645 * V_646 , unsigned V_188 ,
enum V_617 V_7 )
{
struct V_4 * V_5 = V_646 -> V_169 -> V_5 ;
unsigned V_618 ;
static const unsigned V_647 = V_648 | V_649 ;
static const unsigned V_650 =
V_651 | V_652 ;
static const unsigned V_653 =
V_654 | V_655 ;
switch ( V_7 ) {
case V_656 :
F_6 ( V_5 , V_188 , V_657 ) ;
break;
case V_658 :
F_6 ( V_5 , V_188 , V_659 ) ;
break;
case V_660 :
F_6 ( V_5 , V_188 , V_661 ) ;
break;
case V_662 :
F_6 ( V_5 , V_188 , V_663 ) ;
break;
case V_664 :
F_6 ( V_5 , V_188 , V_665 ) ;
break;
case V_666 :
F_6 ( V_5 , V_188 , V_667 ) ;
break;
case V_668 :
F_6 ( V_5 , V_188 , V_669 ) ;
break;
case V_670 :
F_6 ( V_5 , V_188 , V_671 ) ;
break;
case V_629 :
case V_630 :
case V_631 :
case V_632 :
V_618 = F_198 ( V_7 ) ;
F_38 ( V_5 , V_188 , V_618 ) ;
break;
case V_643 :
F_52 ( V_188 & ~ V_650 ) ;
F_41 ( V_5 , V_88 ,
V_650 , V_188 ) ;
break;
case V_644 :
F_52 ( V_188 & ~ V_653 ) ;
F_41 ( V_5 , V_92 ,
V_653 , V_188 ) ;
break;
case V_636 :
F_52 ( V_188 & ~ V_647 ) ;
default:
V_618 = F_198 ( V_7 ) ;
F_35 ( V_5 , V_188 , V_618 ) ;
}
}
static unsigned F_201 ( struct V_645 * V_646 ,
enum V_617 V_7 )
{
struct V_4 * V_5 = V_646 -> V_169 -> V_5 ;
unsigned V_618 ;
switch ( V_7 ) {
case V_672 :
return F_15 ( V_5 , V_673 ) ;
case V_674 :
return F_15 ( V_5 , V_675 ) ;
case V_623 :
case V_624 :
case V_625 :
case V_626 :
V_618 = F_198 ( V_7 ) ;
return F_40 ( V_5 , V_618 ) ;
default:
V_618 = F_198 ( V_7 ) ;
return F_39 ( V_5 , V_618 ) ;
}
return 0 ;
}
static int F_202 ( struct V_4 * V_5 ,
struct V_190 * V_191 ,
struct V_378 * V_379 ,
unsigned int * V_6 )
{
struct V_124 * V_125 = V_5 -> V_126 ;
unsigned int V_133 = V_125 -> V_609 & V_676 ;
int V_180 ;
for ( V_180 = 0 ; V_180 < V_379 -> V_200 ; V_180 ++ )
V_6 [ V_180 ] = V_133 ;
return V_379 -> V_200 ;
}
static int F_203 ( struct V_4 * V_5 ,
struct V_190 * V_191 ,
struct V_378 * V_379 ,
unsigned int * V_6 )
{
struct V_124 * V_125 = V_5 -> V_126 ;
if ( V_379 -> V_200 ) {
V_125 -> V_609 &= ~ V_677 ;
F_35 ( V_5 , V_125 -> V_609 ,
V_71 ) ;
V_125 -> V_609 &= ~ V_676 ;
V_125 -> V_609 |= F_204 ( V_6 [ V_379 -> V_200 - 1 ] ) ;
V_125 -> V_609 |= V_677 ;
F_35 ( V_5 , V_125 -> V_609 ,
V_71 ) ;
}
return V_379 -> V_200 ;
}
static int F_205 ( struct V_4 * V_5 ,
struct V_190 * V_191 ,
struct V_378 * V_379 ,
unsigned int * V_6 )
{
struct V_124 * V_125 = V_5 -> V_126 ;
switch ( V_6 [ 0 ] ) {
case V_678 :
switch ( V_6 [ 1 ] ) {
case V_679 :
V_125 -> V_609 &= ~ V_680 ;
break;
case V_681 :
V_125 -> V_609 |= V_680 ;
break;
default:
return - V_417 ;
}
F_35 ( V_5 , V_125 -> V_609 ,
V_71 ) ;
break;
case V_682 :
if ( V_125 -> V_609 & V_680 ) {
V_6 [ 1 ] = V_681 ;
V_6 [ 2 ] = V_683 ;
} else {
V_6 [ 1 ] = V_679 ;
V_6 [ 2 ] = V_684 * 2 ;
}
break;
default:
return - V_417 ;
}
return V_379 -> V_200 ;
}
static int F_206 ( struct V_4 * V_5 ,
int V_160 , int V_685 , int V_6 , unsigned long V_9 )
{
if ( V_160 ) {
F_9 ( V_5 , V_6 , V_9 + 2 * V_685 ) ;
return 0 ;
}
return F_18 ( V_5 , V_9 + 2 * V_685 ) ;
}
static int F_207 ( struct V_4 * V_5 , unsigned int * V_6 )
{
struct V_124 * V_125 = V_5 -> V_126 ;
V_6 [ 1 ] = V_125 -> V_686 * V_125 -> V_390 ;
V_6 [ 2 ] = V_125 -> V_687 * V_125 -> V_390 ;
return 3 ;
}
static int F_208 ( struct V_4 * V_5 ,
struct V_190 * V_191 ,
struct V_378 * V_379 ,
unsigned int * V_6 )
{
struct V_124 * V_125 = V_5 -> V_126 ;
unsigned V_688 , V_689 ;
switch ( V_6 [ 0 ] ) {
case V_690 :
switch ( V_6 [ 1 ] ) {
case V_389 :
V_688 =
( V_6 [ 2 ] +
V_125 -> V_390 / 2 ) / V_125 -> V_390 ;
break;
case V_391 :
V_688 = V_6 [ 2 ] / V_125 -> V_390 ;
break;
case V_392 :
V_688 =
( V_6 [ 2 ] + V_125 -> V_390 -
1 ) / V_125 -> V_390 ;
break;
default:
return - V_417 ;
}
switch ( V_6 [ 3 ] ) {
case V_389 :
V_689 =
( V_6 [ 4 ] +
V_125 -> V_390 / 2 ) / V_125 -> V_390 ;
break;
case V_391 :
V_689 = V_6 [ 4 ] / V_125 -> V_390 ;
break;
case V_392 :
V_689 =
( V_6 [ 4 ] + V_125 -> V_390 -
1 ) / V_125 -> V_390 ;
break;
default:
return - V_417 ;
}
if ( V_688 * V_125 -> V_390 != V_6 [ 2 ] ||
V_689 * V_125 -> V_390 != V_6 [ 4 ] ) {
V_6 [ 2 ] = V_688 * V_125 -> V_390 ;
V_6 [ 4 ] = V_689 * V_125 -> V_390 ;
return - V_691 ;
}
F_3 ( V_5 , F_209 ( V_688 ) |
F_210 ( V_689 ) ,
V_692 ) ;
V_125 -> V_686 = V_688 ;
V_125 -> V_687 = V_689 ;
return 5 ;
case V_693 :
return F_207 ( V_5 , V_6 ) ;
default:
return - V_417 ;
}
return 0 ;
}
static int F_211 ( struct V_4 * V_5 ,
struct V_190 * V_191 ,
struct V_378 * V_379 ,
unsigned int * V_6 )
{
struct V_124 * V_125 = V_5 -> V_126 ;
unsigned V_688 , V_689 ;
switch ( V_6 [ 0 ] ) {
case V_690 :
switch ( V_6 [ 1 ] ) {
case V_389 :
V_688 =
( V_6 [ 2 ] +
V_125 -> V_390 / 2 ) / V_125 -> V_390 ;
break;
case V_391 :
V_688 = V_6 [ 2 ] / V_125 -> V_390 ;
break;
case V_392 :
V_688 =
( V_6 [ 2 ] + V_125 -> V_390 -
1 ) / V_125 -> V_390 ;
break;
default:
return - V_417 ;
}
switch ( V_6 [ 3 ] ) {
case V_389 :
V_689 =
( V_6 [ 4 ] +
V_125 -> V_390 / 2 ) / V_125 -> V_390 ;
break;
case V_391 :
V_689 = V_6 [ 4 ] / V_125 -> V_390 ;
break;
case V_392 :
V_689 =
( V_6 [ 4 ] + V_125 -> V_390 -
1 ) / V_125 -> V_390 ;
break;
default:
return - V_417 ;
}
if ( V_688 * V_125 -> V_390 != V_6 [ 2 ] ||
V_689 * V_125 -> V_390 != V_6 [ 4 ] ) {
V_6 [ 2 ] = V_688 * V_125 -> V_390 ;
V_6 [ 4 ] = V_689 * V_125 -> V_390 ;
return - V_691 ;
}
F_3 ( V_5 , V_688 , V_694 ) ;
V_125 -> V_686 = V_688 ;
F_3 ( V_5 , V_689 , V_695 ) ;
V_125 -> V_687 = V_689 ;
return 5 ;
case V_693 :
return F_207 ( V_5 , V_6 ) ;
default:
return - V_417 ;
}
return 0 ;
}
static int F_212 ( int V_185 , int V_133 , int * V_696 )
{
V_185 ++ ;
* V_696 = ( ( V_185 & 0x1 ) << 11 ) |
( ( V_185 & 0x2 ) << 9 ) |
( ( V_185 & 0x4 ) << 7 ) | ( ( V_185 & 0x8 ) << 5 ) | ( V_133 & 0xff ) ;
return 12 ;
}
static int F_213 ( int V_185 , int V_133 , int * V_696 )
{
* V_696 = ( ( V_185 & 0x7 ) << 8 ) | ( V_133 & 0xff ) ;
return 11 ;
}
static int F_214 ( int V_185 , int V_133 , int * V_696 )
{
* V_696 = V_133 & 0xfff ;
return 12 ;
}
static int F_215 ( int V_185 , int V_133 , int * V_696 )
{
* V_696 = ( V_133 & 0xfff ) | ( V_185 ? 0xc000 : 0xa000 ) ;
return 16 ;
}
static int F_216 ( int V_185 , int V_133 , int * V_696 )
{
* V_696 = ( ( V_185 & 0xf ) << 8 ) | ( V_133 & 0xff ) ;
return 12 ;
}
static int F_217 ( int V_185 , int V_133 , int * V_696 )
{
* V_696 = ( ( V_185 + 1 ) << 8 ) | ( V_133 & 0xff ) ;
return 12 ;
}
static void F_218 ( struct V_4 * V_5 , int V_185 , int V_133 )
{
const struct V_207 * V_208 = V_5 -> V_209 ;
struct V_124 * V_125 = V_5 -> V_126 ;
unsigned int V_697 = 0 , V_188 = 0 , V_698 , V_696 = 0 ;
int V_180 ;
int type ;
if ( V_125 -> V_699 [ V_185 ] == V_133 )
return;
V_125 -> V_699 [ V_185 ] = V_133 ;
for ( V_180 = 0 ; V_180 < 3 ; V_180 ++ ) {
type = V_208 -> V_700 [ V_180 ] ;
if ( type == V_701 )
break;
if ( V_185 < V_699 [ type ] . V_466 ) {
V_188 = V_699 [ type ] . F_219 ( V_185 , V_133 , & V_696 ) ;
V_697 = F_220 ( V_180 ) ;
break;
}
V_185 -= V_699 [ type ] . V_466 ;
}
for ( V_698 = 1 << ( V_188 - 1 ) ; V_698 ; V_698 >>= 1 ) {
F_9 ( V_5 , ( ( V_698 & V_696 ) ? 0x02 : 0 ) , V_702 ) ;
F_66 ( 1 ) ;
F_9 ( V_5 , 1 | ( ( V_698 & V_696 ) ? 0x02 : 0 ) ,
V_702 ) ;
F_66 ( 1 ) ;
}
F_9 ( V_5 , V_697 , V_702 ) ;
F_66 ( 1 ) ;
F_9 ( V_5 , 0 , V_702 ) ;
}
static int F_221 ( struct V_4 * V_5 ,
struct V_190 * V_191 ,
struct V_378 * V_379 ,
unsigned int * V_6 )
{
F_218 ( V_5 , F_120 ( V_379 -> V_382 ) , V_6 [ 0 ] ) ;
return 1 ;
}
static int F_222 ( struct V_4 * V_5 ,
struct V_190 * V_191 ,
struct V_378 * V_379 ,
unsigned int * V_6 )
{
struct V_124 * V_125 = V_5 -> V_126 ;
V_6 [ 0 ] = V_125 -> V_699 [ F_120 ( V_379 -> V_382 ) ] ;
return 1 ;
}
static void F_223 ( struct V_4 * V_5 , struct V_190 * V_191 )
{
const struct V_207 * V_208 = V_5 -> V_209 ;
struct V_124 * V_125 = V_5 -> V_126 ;
int V_180 , V_703 ;
int V_704 ;
int V_466 = 0 ;
int V_705 ;
int V_706 = 0 ;
int type ;
int V_329 ;
type = V_208 -> V_700 [ 0 ] ;
if ( type == V_701 )
return;
V_705 = V_699 [ type ] . V_705 ;
for ( V_180 = 0 ; V_180 < 3 ; V_180 ++ ) {
type = V_208 -> V_700 [ V_180 ] ;
if ( type == V_701 )
break;
if ( V_699 [ type ] . V_705 != V_705 )
V_706 = 1 ;
V_466 += V_699 [ type ] . V_466 ;
}
V_704 = V_180 ;
V_191 -> V_327 = V_466 ;
if ( V_706 ) {
unsigned int * V_707 ;
if ( V_466 > V_708 )
F_42 ( V_5 -> V_25 ,
L_31 ) ;
V_191 -> V_707 = V_707 = V_125 -> V_709 ;
V_329 = 0 ;
for ( V_180 = 0 ; V_180 < V_704 ; V_180 ++ ) {
type = V_208 -> V_700 [ V_180 ] ;
for ( V_703 = 0 ; V_703 < V_699 [ type ] . V_466 ; V_703 ++ ) {
V_707 [ V_329 ] =
( 1 << V_699 [ type ] . V_705 ) - 1 ;
V_329 ++ ;
}
}
for ( V_329 = 0 ; V_329 < V_191 -> V_327 ; V_329 ++ )
F_218 ( V_5 , V_180 , V_191 -> V_707 [ V_180 ] / 2 ) ;
} else {
type = V_208 -> V_700 [ 0 ] ;
V_191 -> V_361 = ( 1 << V_699 [ type ] . V_705 ) - 1 ;
for ( V_329 = 0 ; V_329 < V_191 -> V_327 ; V_329 ++ )
F_218 ( V_5 , V_180 , V_191 -> V_361 / 2 ) ;
}
}
static int F_224 ( struct V_4 * V_5 , int V_185 )
{
int V_698 ;
int V_696 ;
V_696 = 0x0300 | ( ( V_185 & 0x100 ) << 3 ) | ( V_185 & 0xff ) ;
F_9 ( V_5 , 0x04 , V_702 ) ;
for ( V_698 = 0x8000 ; V_698 ; V_698 >>= 1 ) {
F_9 ( V_5 , 0x04 | ( ( V_698 & V_696 ) ? 0x02 : 0 ) ,
V_702 ) ;
F_9 ( V_5 , 0x05 | ( ( V_698 & V_696 ) ? 0x02 : 0 ) ,
V_702 ) ;
}
V_696 = 0 ;
for ( V_698 = 0x80 ; V_698 ; V_698 >>= 1 ) {
F_9 ( V_5 , 0x04 , V_702 ) ;
F_9 ( V_5 , 0x05 , V_702 ) ;
V_696 |= ( ( F_18 ( V_5 , V_227 ) & V_710 ) ? V_698 : 0 ) ;
}
F_9 ( V_5 , 0x00 , V_702 ) ;
return V_696 ;
}
static int F_225 ( struct V_4 * V_5 ,
struct V_190 * V_191 ,
struct V_378 * V_379 ,
unsigned int * V_6 )
{
V_6 [ 0 ] = F_224 ( V_5 , F_120 ( V_379 -> V_382 ) ) ;
return 1 ;
}
static int F_226 ( struct V_4 * V_5 ,
struct V_190 * V_191 ,
struct V_378 * V_379 ,
unsigned int * V_6 )
{
struct V_124 * V_125 = V_5 -> V_126 ;
V_6 [ 0 ] = V_125 -> V_711 [ F_120 ( V_379 -> V_382 ) ] ;
return 1 ;
}
static unsigned F_227 ( struct V_4 * V_5 ,
unsigned V_329 )
{
switch ( V_329 ) {
case 0 :
return V_712 ;
case 1 :
return V_713 ;
case 2 :
return V_714 ;
case 3 :
return V_715 ;
case 4 :
return V_716 ;
case 5 :
return V_717 ;
case 6 :
return V_718 ;
case 7 :
return V_719 ;
case 8 :
return V_720 ;
case 9 :
return V_721 ;
default:
F_42 ( V_5 -> V_25 ,
L_32 , V_26 ) ;
break;
}
return 0 ;
}
static int F_228 ( struct V_4 * V_5 ,
unsigned V_329 , unsigned V_722 )
{
if ( V_722 != F_227 ( V_5 , V_329 ) )
return - V_417 ;
return 2 ;
}
static unsigned F_229 ( struct V_4 * V_5 ,
unsigned V_329 )
{
struct V_124 * V_125 = V_5 -> V_126 ;
const unsigned V_723 = V_329 / 3 ;
return F_230 ( V_329 ,
V_125 -> V_724 [ V_723 ] ) ;
}
static int F_231 ( struct V_4 * V_5 ,
unsigned V_329 , unsigned V_722 )
{
struct V_124 * V_125 = V_5 -> V_126 ;
unsigned V_725 ;
unsigned V_723 ;
if ( ( V_722 & 0x1f ) != V_722 )
return - V_417 ;
V_725 = 1 + V_329 / 3 ;
V_723 = V_725 - 1 ;
V_125 -> V_724 [ V_723 ] &=
~ F_232 ( V_329 ) ;
V_125 -> V_724 [ V_723 ] |=
F_233 ( V_329 , V_722 ) ;
F_6 ( V_5 , V_125 -> V_724 [ V_723 ] ,
F_234 ( V_725 ) ) ;
return 2 ;
}
static unsigned F_235 ( struct V_4 * V_5 , unsigned V_329 )
{
struct V_124 * V_125 = V_5 -> V_126 ;
return ( V_125 -> V_128 )
? F_229 ( V_5 , V_329 )
: F_227 ( V_5 , V_329 ) ;
}
static int F_236 ( struct V_4 * V_5 , unsigned V_329 ,
unsigned V_722 )
{
struct V_124 * V_125 = V_5 -> V_126 ;
return ( V_125 -> V_128 )
? F_231 ( V_5 , V_329 , V_722 )
: F_228 ( V_5 , V_329 , V_722 ) ;
}
static int F_237 ( struct V_4 * V_5 ,
unsigned V_726 ,
enum V_727 V_728 )
{
struct V_124 * V_125 = V_5 -> V_126 ;
unsigned V_188 ;
if ( ! V_125 -> V_128 )
return - V_729 ;
V_188 = F_12 ( V_5 , V_730 ) ;
V_188 &= ~ F_238 ( V_726 ) ;
V_188 |= F_239 ( V_726 , V_728 ) ;
F_3 ( V_5 , V_188 , V_730 ) ;
return 0 ;
}
static int F_240 ( struct V_4 * V_5 ,
struct V_190 * V_191 ,
struct V_378 * V_379 ,
unsigned int * V_6 )
{
struct V_124 * V_125 = V_5 -> V_126 ;
unsigned int V_329 ;
if ( V_379 -> V_200 < 1 )
return - V_417 ;
V_329 = F_120 ( V_379 -> V_382 ) ;
switch ( V_6 [ 0 ] ) {
case V_164 :
F_71 ( V_5 , V_96 , 1 << V_329 , 1 ) ;
break;
case V_161 :
F_71 ( V_5 , V_96 , 1 << V_329 , 0 ) ;
break;
case V_731 :
V_6 [ 1 ] =
( V_125 -> V_139 & ( 1 << V_329 ) ) ?
V_164 : V_161 ;
return 0 ;
case V_732 :
return F_236 ( V_5 , V_329 , V_6 [ 1 ] ) ;
case V_733 :
V_6 [ 1 ] = F_235 ( V_5 , V_329 ) ;
break;
case V_734 :
return F_237 ( V_5 , V_329 , V_6 [ 1 ] ) ;
default:
return - V_417 ;
}
return 0 ;
}
static int F_241 ( struct V_4 * V_5 ,
struct V_190 * V_191 ,
struct V_378 * V_379 ,
unsigned int * V_6 )
{
struct V_124 * V_125 = V_5 -> V_126 ;
if ( ! V_125 -> V_128 )
return - V_729 ;
if ( F_180 ( V_191 , V_6 ) )
F_6 ( V_5 , V_191 -> V_557 , V_735 ) ;
V_6 [ 1 ] = F_15 ( V_5 , V_736 ) ;
return V_379 -> V_200 ;
}
static int F_242 ( struct V_4 * V_5 )
{
unsigned short V_245 ;
const int V_179 = V_737 ;
int V_180 ;
for ( V_180 = 0 ; V_180 < V_179 ; V_180 ++ ) {
V_245 = F_70 ( V_5 , V_738 ) ;
if ( ( V_245 & V_739 ) == 0 )
break;
F_243 ( V_740 ) ;
if ( F_244 ( 1 ) )
return - V_295 ;
}
if ( V_180 == V_179 ) {
F_42 ( V_5 -> V_25 , L_20 , V_26 ) ;
return - V_384 ;
}
return 0 ;
}
static void F_245 ( struct V_4 * V_5 , unsigned short V_189 )
{
static const int V_179 = 100 ;
int V_180 ;
F_68 ( V_5 , V_189 , V_741 ) ;
for ( V_180 = 0 ; V_180 < V_179 ; V_180 ++ ) {
if ( ( F_70 ( V_5 , V_738 ) & V_739 ) )
break;
F_66 ( 1 ) ;
}
if ( V_180 == V_179 )
F_42 ( V_5 -> V_25 ,
L_33 ) ;
}
static int F_246 ( struct V_4 * V_5 ,
unsigned short * V_6 )
{
int V_193 ;
unsigned short V_245 ;
F_245 ( V_5 , V_742 | V_743 ) ;
V_193 = F_242 ( V_5 ) ;
if ( V_193 ) {
F_42 ( V_5 -> V_25 ,
L_34 ) ;
return - V_384 ;
}
V_245 = F_70 ( V_5 , V_738 ) ;
if ( V_245 & V_744 ) {
F_42 ( V_5 -> V_25 ,
L_35 ) ;
return - V_295 ;
}
if ( V_245 & V_745 ) {
F_42 ( V_5 -> V_25 ,
L_36 ) ;
}
if ( V_6 ) {
* V_6 = F_70 ( V_5 , V_746 ) ;
* V_6 ^= ( 1 << 15 ) ;
}
return 0 ;
}
static int F_247 ( struct V_4 * V_5 ,
struct V_190 * V_191 ,
struct V_378 * V_379 ,
unsigned int * V_6 )
{
int V_200 , V_193 ;
unsigned short V_747 ;
unsigned int V_748 ;
const unsigned int V_749 = 0x1000 ;
if ( V_379 -> V_382 & V_334 )
V_748 = V_749 ;
else
V_748 = F_120 ( V_379 -> V_382 ) ;
F_68 ( V_5 , V_748 , V_750 ) ;
for ( V_200 = 0 ; V_200 < V_379 -> V_200 ; V_200 ++ ) {
V_193 = F_246 ( V_5 , & V_747 ) ;
if ( V_193 < 0 )
return V_193 ;
V_6 [ V_200 ] = V_747 ;
}
return V_379 -> V_200 ;
}
static void F_248 ( struct V_4 * V_5 , unsigned int V_189 ,
unsigned int V_751 )
{
F_68 ( V_5 , ( ( V_189 >> 16 ) & 0xff ) ,
V_752 ) ;
F_68 ( V_5 , ( V_189 & 0xffff ) ,
V_753 ) ;
V_751 &= V_754 ;
F_245 ( V_5 , V_742 | V_751 ) ;
if ( F_242 ( V_5 ) )
F_42 ( V_5 -> V_25 ,
L_37 , V_26 ) ;
}
static int F_249 ( struct V_4 * V_5 )
{
unsigned int V_348 =
V_755 | V_756 ;
#if 1
F_248 ( V_5 , V_348 | V_757 ,
V_758 ) ;
F_246 ( V_5 , NULL ) ;
#else
F_248 ( V_5 , 0x400000 , V_759 ) ;
F_248 ( V_5 , V_348 | V_760 ,
V_758 ) ;
if ( F_242 ( V_5 ) )
F_42 ( V_5 -> V_25 ,
L_37 , V_26 ) ;
#endif
return 0 ;
}
static int F_250 ( unsigned V_761 ,
unsigned * V_762 ,
unsigned * V_763 ,
unsigned * V_764 )
{
unsigned div ;
unsigned V_765 = 1 ;
static const unsigned V_766 = 0x10 ;
unsigned V_767 ;
unsigned V_768 = 1 ;
static const unsigned V_769 = 0x100 ;
static const unsigned V_770 = 1000 ;
const unsigned V_771 = V_761 * V_770 ;
static const unsigned V_772 = 12500 ;
static const unsigned V_773 = 4 ;
int V_774 = 0 ;
for ( div = 1 ; div <= V_766 ; ++ div ) {
for ( V_767 = 1 ; V_767 <= V_769 ; ++ V_767 ) {
unsigned V_775 =
( V_771 * div ) / V_767 ;
if ( abs ( V_775 - V_772 ) <
abs ( V_774 - V_772 ) ) {
V_774 = V_775 ;
V_765 = div ;
V_768 = V_767 ;
}
}
}
if ( V_774 == 0 )
return - V_295 ;
* V_762 = V_765 ;
* V_763 = V_768 ;
* V_764 =
( V_774 * V_773 +
( V_770 / 2 ) ) / V_770 ;
return 0 ;
}
static int F_251 ( struct V_4 * V_5 ,
unsigned V_722 , unsigned V_776 )
{
struct V_124 * V_125 = V_5 -> V_126 ;
static const unsigned V_777 = 50 ;
static const unsigned V_778 = 1000 ;
static const unsigned V_179 = 1000 ;
unsigned V_779 ;
unsigned V_762 ;
unsigned V_763 ;
unsigned V_180 ;
int V_193 ;
if ( V_722 == V_780 )
V_776 = 100 ;
if ( V_776 < V_777 || V_776 > V_778 ) {
F_42 ( V_5 -> V_25 ,
L_38 ,
V_26 , V_777 , V_778 ) ;
return - V_417 ;
}
V_125 -> V_781 &= ~ V_782 ;
F_35 ( V_5 , V_125 -> V_781 ,
V_104 ) ;
V_779 =
V_783 | V_784 ;
V_125 -> V_785 |=
V_786 | V_787 ;
V_125 -> V_785 &= ~ V_788 ;
switch ( V_722 ) {
case V_789 :
V_125 -> V_785 |=
V_790 ;
break;
case V_780 :
V_125 -> V_785 |=
V_791 ;
break;
default:
{
unsigned V_792 ;
static const unsigned V_793 = 7 ;
for ( V_792 = 0 ; V_792 <= V_793 ;
++ V_792 ) {
if ( V_722 ==
F_252 ( V_792 ) ) {
V_125 -> V_785 |=
F_253
( V_792 ) ;
break;
}
}
if ( V_792 > V_793 )
return - V_417 ;
}
break;
}
V_193 = F_250 ( V_776 ,
& V_762 ,
& V_763 ,
& V_125 -> V_390 ) ;
if ( V_193 < 0 ) {
F_42 ( V_5 -> V_25 ,
L_39 , V_26 ) ;
return V_193 ;
}
F_6 ( V_5 , V_125 -> V_785 , V_794 ) ;
V_779 |=
F_254 ( V_762 ) |
F_255 ( V_763 ) ;
F_6 ( V_5 , V_779 , V_795 ) ;
V_125 -> V_796 = V_722 ;
for ( V_180 = 0 ; V_180 < V_179 ; ++ V_180 ) {
if ( F_15 ( V_5 , V_797 ) & V_798 )
break;
F_66 ( 1 ) ;
}
if ( V_180 == V_179 ) {
F_42 ( V_5 -> V_25 ,
L_40 ,
V_26 , V_722 , V_776 ) ;
return - V_799 ;
}
return 3 ;
}
static int F_256 ( struct V_4 * V_5 ,
unsigned V_722 , unsigned V_776 )
{
struct V_124 * V_125 = V_5 -> V_126 ;
if ( V_722 == V_800 ) {
V_125 -> V_781 &= ~ V_782 ;
F_35 ( V_5 , V_125 -> V_781 ,
V_104 ) ;
V_125 -> V_390 = V_684 ;
if ( V_125 -> V_128 ) {
V_125 -> V_785 &=
~ ( V_786 |
V_787 ) ;
F_6 ( V_5 , V_125 -> V_785 ,
V_794 ) ;
F_6 ( V_5 , 0 , V_795 ) ;
}
V_125 -> V_796 = V_722 ;
} else {
if ( V_125 -> V_128 ) {
return F_251 ( V_5 , V_722 ,
V_776 ) ;
} else {
if ( V_722 == V_801 ) {
V_125 -> V_781 |=
V_782 ;
F_35 ( V_5 ,
V_125 -> V_781 ,
V_104 ) ;
if ( V_776 == 0 ) {
F_42 ( V_5 -> V_25 ,
L_41 ,
V_26 ) ;
return - V_417 ;
}
V_125 -> V_390 = V_776 ;
V_125 -> V_796 = V_722 ;
} else
return - V_417 ;
}
}
return 3 ;
}
static unsigned F_257 ( struct V_4 * V_5 )
{
struct V_124 * V_125 = V_5 -> V_126 ;
return ( V_125 -> V_128 ) ? 8 : 7 ;
}
static int F_258 ( struct V_4 * V_5 ,
unsigned V_329 , unsigned V_722 )
{
struct V_124 * V_125 = V_5 -> V_126 ;
if ( V_329 >= F_257 ( V_5 ) ) {
if ( V_329 == V_802 ) {
if ( V_722 == V_803 )
return 1 ;
F_42 ( V_5 -> V_25 ,
L_42 ,
V_26 , V_329 , V_802 ) ;
return 0 ;
}
return 0 ;
}
switch ( V_722 ) {
case V_804 :
case V_805 :
case V_806 :
case V_807 :
case V_808 :
case V_809 :
case V_810 :
case V_811 :
case V_812 :
return 1 ;
case V_803 :
return ( V_125 -> V_128 ) ? 1 : 0 ;
default:
return 0 ;
}
}
static int F_259 ( struct V_4 * V_5 ,
unsigned V_329 , unsigned V_722 )
{
struct V_124 * V_125 = V_5 -> V_126 ;
if ( F_258 ( V_5 , V_329 , V_722 ) == 0 )
return - V_417 ;
if ( V_329 < 4 ) {
V_125 -> V_813 &= ~ F_260 ( V_329 ) ;
V_125 -> V_813 |=
F_261 ( V_329 , V_722 ) ;
F_35 ( V_5 , V_125 -> V_813 ,
V_100 ) ;
} else if ( V_329 < 8 ) {
V_125 -> V_814 &= ~ F_260 ( V_329 ) ;
V_125 -> V_814 |=
F_261 ( V_329 , V_722 ) ;
F_35 ( V_5 , V_125 -> V_814 ,
V_102 ) ;
}
return 2 ;
}
static unsigned F_262 ( struct V_4 * V_5 , unsigned V_329 )
{
struct V_124 * V_125 = V_5 -> V_126 ;
if ( V_329 < 4 ) {
return F_263 ( V_329 ,
V_125 -> V_813 ) ;
} else if ( V_329 < F_257 ( V_5 ) ) {
return F_263 ( V_329 ,
V_125 -> V_814 ) ;
} else {
if ( V_329 == V_802 )
return V_803 ;
F_42 ( V_5 -> V_25 , L_43 ,
V_26 ) ;
return 0 ;
}
}
static int F_264 ( struct V_4 * V_5 ,
struct V_190 * V_191 ,
struct V_378 * V_379 ,
unsigned int * V_6 )
{
struct V_124 * V_125 = V_5 -> V_126 ;
unsigned int V_329 = F_120 ( V_379 -> V_382 ) ;
switch ( V_6 [ 0 ] ) {
case V_815 :
if ( V_329 < F_257 ( V_5 ) ) {
V_125 -> V_781 |=
F_265 ( V_329 , V_125 -> V_128 ) ;
} else if ( V_329 == V_802 ) {
V_125 -> V_781 |=
V_816 ;
}
F_35 ( V_5 , V_125 -> V_781 ,
V_104 ) ;
break;
case V_817 :
if ( V_329 < F_257 ( V_5 ) ) {
V_125 -> V_781 &=
~ F_265 ( V_329 , V_125 -> V_128 ) ;
} else if ( V_329 == V_802 ) {
V_125 -> V_781 &=
~ V_816 ;
}
F_35 ( V_5 , V_125 -> V_781 ,
V_104 ) ;
break;
case V_731 :
if ( V_329 < F_257 ( V_5 ) ) {
V_6 [ 1 ] =
( V_125 -> V_781 &
F_265 ( V_329 , V_125 -> V_128 ) )
? V_815
: V_817 ;
} else if ( V_329 == V_802 ) {
V_6 [ 1 ] =
( V_125 -> V_781 &
V_816 )
? V_815 : V_817 ;
}
return 2 ;
case V_678 :
return F_256 ( V_5 , V_6 [ 1 ] , V_6 [ 2 ] ) ;
case V_682 :
V_6 [ 1 ] = V_125 -> V_796 ;
V_6 [ 2 ] = V_125 -> V_390 ;
return 3 ;
case V_732 :
return F_259 ( V_5 , V_329 , V_6 [ 1 ] ) ;
case V_733 :
V_6 [ 1 ] = F_262 ( V_5 , V_329 ) ;
return 2 ;
default:
return - V_417 ;
}
return 1 ;
}
static int F_266 ( struct V_4 * V_5 ,
struct V_190 * V_191 ,
struct V_378 * V_379 ,
unsigned int * V_6 )
{
V_6 [ 1 ] = 0 ;
return V_379 -> V_200 ;
}
static void F_267 ( struct V_4 * V_5 )
{
struct V_124 * V_125 = V_5 -> V_126 ;
V_125 -> V_785 = V_818 ;
if ( F_256 ( V_5 , V_800 , 0 ) < 0 )
F_42 ( V_5 -> V_25 , L_44 ) ;
V_125 -> V_813 =
F_261 ( 0 ,
V_804 ) |
F_261 ( 1 ,
V_805 ) |
F_261 ( 2 ,
V_806 ) |
F_261 ( 3 , V_807 ) ;
F_35 ( V_5 , V_125 -> V_813 ,
V_100 ) ;
V_125 -> V_814 =
F_261 ( 4 ,
V_808 ) |
F_261 ( 5 ,
V_809 ) |
F_261 ( 6 , V_810 ) ;
if ( V_125 -> V_128 )
V_125 -> V_814 |=
F_261 ( 7 , V_803 ) ;
F_35 ( V_5 , V_125 -> V_814 ,
V_102 ) ;
}
static int F_268 ( struct V_4 * V_5 , struct V_190 * V_191 )
{
struct V_645 * V_646 = V_191 -> V_126 ;
int V_193 ;
V_193 = F_55 ( V_5 , V_646 -> V_1 ,
V_161 ) ;
if ( V_193 ) {
F_42 ( V_5 -> V_25 ,
L_45 ) ;
return V_193 ;
}
F_269 ( V_646 ) ;
F_64 ( V_5 , V_646 -> V_1 , 1 ) ;
return F_270 ( V_5 , V_191 ) ;
}
static int F_271 ( struct V_4 * V_5 , struct V_190 * V_191 )
{
struct V_645 * V_646 = V_191 -> V_126 ;
int V_193 ;
V_193 = F_272 ( V_646 ) ;
F_64 ( V_5 , V_646 -> V_1 , 0 ) ;
F_62 ( V_5 , V_646 -> V_1 ) ;
return V_193 ;
}
static T_5 F_273 ( int V_425 , void * V_201 )
{
struct V_4 * V_5 = V_201 ;
unsigned short V_235 ;
unsigned short V_197 ;
unsigned int V_246 = 0 ;
unsigned int V_281 = 0 ;
unsigned long V_127 ;
#ifdef F_58
struct V_124 * V_125 = V_5 -> V_126 ;
struct V_195 * V_130 = V_125 -> V_130 ;
#endif
if ( ! V_5 -> V_819 )
return V_820 ;
F_274 () ;
F_36 ( & V_5 -> V_324 , V_127 ) ;
V_235 = F_39 ( V_5 , V_110 ) ;
V_197 = F_39 ( V_5 , V_112 ) ;
#ifdef F_58
if ( V_130 ) {
struct V_124 * V_125 = V_5 -> V_126 ;
unsigned long V_821 ;
F_36 ( & V_125 -> V_156 , V_821 ) ;
if ( V_125 -> V_157 ) {
V_246 = F_191 ( V_125 -> V_157 ) ;
if ( V_246 & V_250 )
F_4 ( V_587 ,
V_125 -> V_130 -> V_588 +
F_192 ( V_125 ->
V_157 -> V_144 ) ) ;
}
if ( V_125 -> V_162 ) {
V_281 = F_191 ( V_125 -> V_162 ) ;
if ( V_281 & V_250 )
F_4 ( V_587 ,
V_130 -> V_588 +
F_192 ( V_125 ->
V_162 -> V_144 ) ) ;
}
F_37 ( & V_125 -> V_156 , V_821 ) ;
}
#endif
F_96 ( V_5 , V_235 ) ;
F_99 ( V_5 , V_197 ) ;
if ( ( V_235 & V_822 ) || ( V_246 & V_251 ) )
F_97 ( V_5 , V_235 , V_246 ) ;
if ( ( V_197 & V_823 ) || ( V_281 & V_251 ) )
F_100 ( V_5 , V_197 , V_281 ) ;
F_93 ( V_5 , 0 ) ;
F_93 ( V_5 , 1 ) ;
F_190 ( V_5 ) ;
F_37 ( & V_5 -> V_324 , V_127 ) ;
return V_824 ;
}
static int F_275 ( struct V_4 * V_5 )
{
struct V_124 * V_125 ;
V_125 = F_276 ( V_5 , sizeof( * V_125 ) ) ;
if ( ! V_125 )
return - V_825 ;
F_277 ( & V_125 -> V_129 ) ;
F_277 ( & V_125 -> V_136 ) ;
F_277 ( & V_125 -> V_156 ) ;
return 0 ;
}
static int F_278 ( struct V_4 * V_5 ,
unsigned V_826 , unsigned V_827 )
{
const struct V_207 * V_208 = V_5 -> V_209 ;
struct V_124 * V_125 = V_5 -> V_126 ;
struct V_190 * V_191 ;
int V_283 ;
int V_180 ;
if ( V_208 -> V_828 > V_829 ) {
F_42 ( V_5 -> V_25 , L_46 ) ;
return - V_417 ;
}
V_125 -> V_609 = V_830 |
V_610 |
V_831 |
V_832 ;
if ( ! V_125 -> V_203 ) {
V_125 -> V_609 |= ( V_833 |
V_834 ) ;
}
F_35 ( V_5 , V_125 -> V_609 , V_71 ) ;
V_283 = F_279 ( V_5 , V_835 ) ;
if ( V_283 )
return V_283 ;
V_191 = & V_5 -> V_234 [ V_836 ] ;
if ( V_208 -> V_837 ) {
V_191 -> type = V_838 ;
V_191 -> V_290 = V_839 | V_840 | V_841 ;
if ( ! V_125 -> V_219 )
V_191 -> V_290 |= V_842 | V_843 | V_844 ;
if ( V_208 -> V_845 > 0xffff )
V_191 -> V_290 |= V_291 ;
if ( V_125 -> V_128 )
V_191 -> V_290 |= V_846 ;
V_191 -> V_327 = V_208 -> V_837 ;
V_191 -> V_361 = V_208 -> V_845 ;
V_191 -> V_474 = V_847 [ V_208 -> V_337 ] ;
V_191 -> V_848 = F_130 ;
V_191 -> V_849 = F_148 ;
if ( V_5 -> V_425 ) {
V_5 -> V_192 = V_191 ;
V_191 -> V_290 |= V_850 ;
V_191 -> V_851 = 512 ;
V_191 -> V_852 = F_134 ;
V_191 -> V_853 = F_141 ;
V_191 -> V_566 = F_110 ;
V_191 -> V_854 = F_116 ;
V_191 -> V_855 = F_101 ;
if ( V_125 -> V_130 )
V_191 -> V_856 = V_857 ;
}
F_110 ( V_5 , V_191 ) ;
} else {
V_191 -> type = V_249 ;
}
V_191 = & V_5 -> V_234 [ V_858 ] ;
if ( V_208 -> V_828 ) {
V_191 -> type = V_859 ;
V_191 -> V_290 = V_860 | V_861 | V_842 ;
if ( V_125 -> V_128 )
V_191 -> V_290 |= V_846 ;
V_191 -> V_327 = V_208 -> V_828 ;
V_191 -> V_361 = V_208 -> V_862 ;
V_191 -> V_474 = V_208 -> V_863 ;
V_191 -> V_849 = F_164 ;
V_191 -> V_864 = F_161 ;
V_283 = F_280 ( V_191 ) ;
if ( V_283 )
return V_283 ;
if ( V_5 -> V_425 && ( V_208 -> V_215 || V_125 -> V_130 ) ) {
V_5 -> V_196 = V_191 ;
V_191 -> V_290 |= V_865 ;
V_191 -> V_851 = V_191 -> V_327 ;
V_191 -> V_852 = F_174 ;
V_191 -> V_853 = F_167 ;
V_191 -> V_566 = F_175 ;
if ( ! V_125 -> V_128 )
V_191 -> V_855 = F_149 ;
if ( V_125 -> V_130 )
V_191 -> V_856 = V_866 ;
}
if ( V_125 -> V_867 )
F_197 ( V_5 , V_191 ) ;
F_175 ( V_5 , V_191 ) ;
} else {
V_191 -> type = V_249 ;
}
V_191 = & V_5 -> V_234 [ V_585 ] ;
V_191 -> type = V_868 ;
V_191 -> V_290 = V_860 | V_839 ;
V_191 -> V_327 = V_208 -> V_869 ? 32 : 8 ;
V_191 -> V_361 = 1 ;
V_191 -> V_474 = & V_870 ;
if ( V_125 -> V_128 ) {
V_191 -> V_290 |= V_291 ;
V_191 -> V_871 = F_183 ;
V_191 -> V_849 = F_182 ;
if ( V_5 -> V_425 ) {
V_191 -> V_290 |= V_865 ;
V_191 -> V_851 = V_191 -> V_327 ;
V_191 -> V_852 = F_185 ;
V_191 -> V_853 = F_188 ;
V_191 -> V_566 = F_189 ;
V_191 -> V_856 = V_872 ;
}
F_3 ( V_5 , V_574 | V_873 ,
V_570 ) ;
F_3 ( V_5 , V_191 -> V_551 , V_560 ) ;
} else {
V_191 -> V_871 = F_179 ;
V_191 -> V_849 = F_176 ;
V_125 -> V_549 = F_178 ( V_191 -> V_551 ) ;
F_6 ( V_5 , V_125 -> V_549 , V_77 ) ;
}
V_191 = & V_5 -> V_234 [ V_874 ] ;
if ( V_208 -> V_875 ) {
V_283 = F_281 ( V_5 , V_191 , F_206 , V_876 ) ;
if ( V_283 )
return V_283 ;
} else {
V_191 -> type = V_249 ;
}
V_191 = & V_5 -> V_234 [ V_877 ] ;
V_191 -> type = V_249 ;
V_191 = & V_5 -> V_234 [ V_878 ] ;
V_191 -> type = V_879 ;
V_191 -> V_290 = V_880 ;
V_191 -> V_327 = 1 ;
V_191 -> V_361 = 0 ;
if ( V_125 -> V_128 ) {
V_191 -> V_849 = F_208 ;
F_3 ( V_5 , 0x0 , V_692 ) ;
} else if ( V_125 -> V_181 ) {
V_191 -> V_849 = F_211 ;
} else {
V_191 -> V_290 |= V_860 ;
V_191 -> V_848 = F_222 ;
V_191 -> V_864 = F_221 ;
F_223 ( V_5 , V_191 ) ;
}
V_191 = & V_5 -> V_234 [ V_881 ] ;
V_191 -> type = V_882 ;
V_191 -> V_290 = V_839 | V_880 ;
V_191 -> V_361 = 0xff ;
if ( V_125 -> V_128 ) {
V_191 -> V_327 = V_883 ;
V_191 -> V_848 = F_226 ;
} else {
V_191 -> V_327 = 512 ;
V_191 -> V_848 = F_225 ;
}
V_191 = & V_5 -> V_234 [ V_884 ] ;
V_191 -> type = V_868 ;
V_191 -> V_290 = V_839 | V_860 | V_880 ;
V_191 -> V_361 = 1 ;
if ( V_125 -> V_128 ) {
V_191 -> V_327 = 16 ;
V_191 -> V_871 = F_241 ;
F_6 ( V_5 , V_191 -> V_557 , V_735 ) ;
for ( V_180 = 0 ; V_180 < V_885 ; ++ V_180 ) {
F_6 ( V_5 , V_125 -> V_724 [ V_180 ] ,
F_234 ( V_180 + 1 ) ) ;
}
} else {
V_191 -> V_327 = 10 ;
}
V_191 -> V_849 = F_240 ;
F_71 ( V_5 , V_96 , ~ 0 , 0 ) ;
V_191 = & V_5 -> V_234 [ V_886 ] ;
if ( V_125 -> V_867 ) {
V_191 -> type = V_838 ;
V_191 -> V_290 = V_839 | V_840 | V_880 ;
V_191 -> V_327 = V_208 -> V_828 ;
V_191 -> V_361 = ( 1 << 16 ) - 1 ;
V_191 -> V_474 = & V_887 ;
V_191 -> V_848 = F_247 ;
V_191 -> V_849 = NULL ;
F_249 ( V_5 ) ;
} else {
V_191 -> type = V_249 ;
}
V_191 = & V_5 -> V_234 [ V_888 ] ;
V_191 -> type = V_889 ;
V_191 -> V_290 = V_839 | V_860 | V_880 ;
V_191 -> V_327 = 1 ;
V_191 -> V_361 = 0xff ;
V_191 -> V_849 = F_196 ;
V_125 -> V_554 = 0 ;
V_125 -> V_604 = 0 ;
V_191 = & V_5 -> V_234 [ V_890 ] ;
V_191 -> type = V_868 ;
V_191 -> V_290 = V_839 | V_860 | V_880 ;
V_191 -> V_327 = 8 ;
V_191 -> V_361 = 1 ;
V_191 -> V_871 = F_266 ;
V_191 -> V_849 = F_264 ;
F_267 ( V_5 ) ;
V_125 -> V_169 = F_282 ( V_5 ,
F_200 ,
F_201 ,
( V_125 -> V_128 )
? V_891
: V_892 ,
V_168 ) ;
if ( ! V_125 -> V_169 )
return - V_825 ;
for ( V_180 = 0 ; V_180 < V_168 ; ++ V_180 ) {
struct V_645 * V_893 = & V_125 -> V_169 -> V_170 [ V_180 ] ;
V_893 -> V_894 = 0 ;
V_893 -> V_1 = V_180 ;
F_283 ( V_893 ) ;
V_191 = & V_5 -> V_234 [ F_1 ( V_180 ) ] ;
V_191 -> type = V_895 ;
V_191 -> V_290 = V_839 | V_860 | V_291 ;
V_191 -> V_327 = 3 ;
V_191 -> V_361 = ( V_125 -> V_128 ) ? 0xffffffff
: 0x00ffffff ;
V_191 -> V_848 = V_896 ;
V_191 -> V_864 = V_896 ;
V_191 -> V_849 = V_897 ;
#ifdef F_58
if ( V_5 -> V_425 && V_125 -> V_130 ) {
V_191 -> V_290 |= V_850 ;
V_191 -> V_851 = 1 ;
V_191 -> V_852 = V_898 ;
V_191 -> V_853 = F_268 ;
V_191 -> V_566 = F_271 ;
V_191 -> V_856 = V_872 ;
}
#endif
V_191 -> V_126 = V_893 ;
}
V_191 = & V_5 -> V_234 [ V_899 ] ;
V_191 -> type = V_895 ;
V_191 -> V_290 = V_839 | V_860 ;
V_191 -> V_327 = 1 ;
V_191 -> V_361 = 0xf ;
V_191 -> V_848 = F_202 ;
V_191 -> V_864 = F_203 ;
V_191 -> V_849 = F_205 ;
if ( V_5 -> V_425 ) {
F_35 ( V_5 ,
( V_827 ? V_900 : 0 ) |
( V_901 & 0 ) |
V_902 | V_903 |
F_284 ( V_826 ) |
F_285 ( V_826 ) ,
V_94 ) ;
}
F_9 ( V_5 , V_125 -> V_141 , V_140 ) ;
F_9 ( V_5 , V_125 -> V_143 , V_142 ) ;
if ( V_125 -> V_203 ) {
F_9 ( V_5 , 0 , V_904 ) ;
} else if ( V_125 -> V_128 ) {
int V_144 ;
for ( V_144 = 0 ; V_144 < V_208 -> V_828 ; ++ V_144 ) {
F_9 ( V_5 , 0xf ,
F_155 ( V_144 ) ) ;
F_9 ( V_5 , 0x0 ,
F_156 ( V_144 ) ) ;
}
F_9 ( V_5 , 0x0 , V_905 ) ;
}
return 0 ;
}
static void F_286 ( struct V_4 * V_5 )
{
struct V_124 * V_125 = V_5 -> V_126 ;
if ( V_125 ) {
if ( V_125 -> V_169 )
F_287 ( V_125 -> V_169 ) ;
}
}
