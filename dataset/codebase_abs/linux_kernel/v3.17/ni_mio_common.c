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
if ( V_144 >= 0 ) {
V_145 =
( F_45 ( V_144 ) <<
V_146 ) & V_147 ;
} else {
V_145 = 0 ;
}
F_41 ( V_5 , V_140 , V_147 , V_145 ) ;
}
static inline void F_46 ( struct V_4 * V_5 , int V_144 )
{
unsigned V_145 ;
if ( V_144 >= 0 ) {
V_145 =
( F_45 ( V_144 ) <<
V_148 ) & V_149 ;
} else {
V_145 = 0 ;
}
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
struct V_201 * V_202 = V_191 -> V_202 ;
struct V_203 * V_204 = & V_202 -> V_204 ;
int V_205 ;
int V_180 ;
unsigned short V_206 ;
T_4 V_207 ;
int V_208 ;
int V_209 = 1 ;
V_205 = V_202 -> V_210 ;
for ( V_180 = 0 ; V_180 < V_200 ; V_180 ++ ) {
V_209 &= F_80 ( V_191 , & V_206 ) ;
if ( V_209 == 0 )
break;
V_208 = F_81 ( V_204 -> V_211 [ V_205 ] ) ;
if ( V_125 -> V_212 ) {
V_207 = V_206 & 0xffff ;
if ( ! V_125 -> V_213 ) {
V_209 &= F_80 ( V_191 , & V_206 ) ;
if ( V_209 == 0 )
break;
V_205 ++ ;
V_180 ++ ;
V_207 |= ( V_206 << 16 ) & 0xffff0000 ;
}
F_3 ( V_5 , V_207 , V_214 ) ;
} else {
F_6 ( V_5 , V_206 , V_215 ) ;
}
V_205 ++ ;
V_205 %= V_204 -> V_216 ;
}
V_202 -> V_210 = V_205 ;
if ( V_209 == 0 )
V_202 -> V_217 |= V_218 ;
}
static int F_82 ( struct V_4 * V_5 ,
struct V_190 * V_191 )
{
const struct V_219 * V_220 = F_83 ( V_5 ) ;
int V_200 ;
V_200 = F_84 ( V_191 ) ;
if ( V_200 == 0 ) {
V_191 -> V_202 -> V_217 |= V_218 ;
return 0 ;
}
V_200 /= sizeof( short ) ;
if ( V_200 > V_220 -> V_221 / 2 )
V_200 = V_220 -> V_221 / 2 ;
F_79 ( V_5 , V_191 , V_200 ) ;
V_191 -> V_202 -> V_217 |= V_222 ;
return 1 ;
}
static int F_85 ( struct V_4 * V_5 ,
struct V_190 * V_191 )
{
const struct V_219 * V_220 = F_83 ( V_5 ) ;
struct V_124 * V_125 = V_5 -> V_126 ;
int V_200 ;
F_35 ( V_5 , 1 , V_75 ) ;
if ( V_125 -> V_212 )
F_69 ( V_5 , 0x6 , V_223 ) ;
V_200 = F_84 ( V_191 ) ;
if ( V_200 == 0 )
return 0 ;
V_200 /= sizeof( short ) ;
if ( V_200 > V_220 -> V_221 )
V_200 = V_220 -> V_221 ;
F_79 ( V_5 , V_191 , V_200 ) ;
return V_200 ;
}
static void F_86 ( struct V_4 * V_5 ,
struct V_190 * V_191 , int V_200 )
{
struct V_124 * V_125 = V_5 -> V_126 ;
struct V_201 * V_202 = V_191 -> V_202 ;
int V_180 ;
if ( V_125 -> V_224 ) {
unsigned short V_6 [ 2 ] ;
T_4 V_225 ;
for ( V_180 = 0 ; V_180 < V_200 / 2 ; V_180 ++ ) {
V_225 = F_12 ( V_5 , V_226 ) ;
V_6 [ 0 ] = ( V_225 >> 16 ) & 0xffff ;
V_6 [ 1 ] = V_225 & 0xffff ;
F_87 ( V_191 , V_6 , sizeof( V_6 ) ) ;
}
if ( V_200 % 2 ) {
V_225 = F_12 ( V_5 , V_226 ) ;
V_6 [ 0 ] = V_225 & 0xffff ;
F_88 ( V_191 , V_6 [ 0 ] ) ;
}
} else if ( V_125 -> V_181 ) {
unsigned short V_6 [ 2 ] ;
T_4 V_225 ;
for ( V_180 = 0 ; V_180 < V_200 / 2 ; V_180 ++ ) {
V_225 = F_12 ( V_5 , V_227 ) ;
V_6 [ 0 ] = ( V_225 >> 16 ) & 0xffff ;
V_6 [ 1 ] = V_225 & 0xffff ;
F_87 ( V_191 , V_6 , sizeof( V_6 ) ) ;
}
if ( V_200 % 2 ) {
F_3 ( V_5 , 0x01 , V_182 ) ;
V_225 = F_12 ( V_5 , V_227 ) ;
V_6 [ 0 ] = ( V_225 >> 16 ) & 0xffff ;
F_88 ( V_191 , V_6 [ 0 ] ) ;
}
} else {
if ( V_200 > sizeof( V_125 -> V_228 ) /
sizeof( V_125 -> V_228 [ 0 ] ) ) {
F_42 ( V_5 -> V_25 ,
L_12 ) ;
V_202 -> V_217 |= V_229 ;
return;
}
for ( V_180 = 0 ; V_180 < V_200 ; V_180 ++ ) {
V_125 -> V_228 [ V_180 ] =
F_15 ( V_5 , V_230 ) ;
}
F_87 ( V_191 , V_125 -> V_228 ,
V_200 *
sizeof( V_125 -> V_228 [ 0 ] ) ) ;
}
}
static void F_89 ( struct V_4 * V_5 )
{
const struct V_219 * V_220 = F_83 ( V_5 ) ;
struct V_190 * V_191 = V_5 -> V_192 ;
int V_200 ;
V_200 = V_220 -> V_231 / 2 ;
F_86 ( V_5 , V_191 , V_200 ) ;
}
static void F_90 ( struct V_4 * V_5 )
{
struct V_124 * V_125 = V_5 -> V_126 ;
struct V_190 * V_191 = V_5 -> V_192 ;
unsigned short V_6 [ 2 ] ;
T_4 V_225 ;
unsigned short V_232 ;
int V_180 ;
if ( V_125 -> V_224 ) {
while ( ( F_39 ( V_5 , V_110 ) &
V_194 ) == 0 ) {
V_225 = F_12 ( V_5 , V_226 ) ;
V_6 [ 0 ] = ( V_225 >> 16 ) ;
V_6 [ 1 ] = ( V_225 & 0xffff ) ;
F_87 ( V_191 , V_6 , sizeof( V_6 ) ) ;
}
} else if ( V_125 -> V_181 ) {
V_180 = 0 ;
while ( F_12 ( V_5 , V_183 ) & 0x04 ) {
V_225 = F_12 ( V_5 , V_227 ) ;
V_6 [ 0 ] = ( V_225 >> 16 ) ;
V_6 [ 1 ] = ( V_225 & 0xffff ) ;
F_87 ( V_191 , V_6 , sizeof( V_6 ) ) ;
V_180 += 2 ;
}
if ( F_12 ( V_5 , V_183 ) & 0x01 ) {
F_3 ( V_5 , 0x01 , V_182 ) ;
V_225 = F_12 ( V_5 , V_227 ) ;
V_6 [ 0 ] = ( V_225 >> 16 ) & 0xffff ;
F_88 ( V_191 , V_6 [ 0 ] ) ;
}
} else {
V_232 = F_39 ( V_5 , V_110 ) &
V_194 ;
while ( V_232 == 0 ) {
for ( V_180 = 0 ;
V_180 <
sizeof( V_125 -> V_228 ) /
sizeof( V_125 -> V_228 [ 0 ] ) ; V_180 ++ ) {
V_232 = F_39 ( V_5 ,
V_110 ) &
V_194 ;
if ( V_232 )
break;
V_125 -> V_228 [ V_180 ] =
F_15 ( V_5 , V_230 ) ;
}
F_87 ( V_191 , V_125 -> V_228 ,
V_180 *
sizeof( V_125 ->
V_228 [ 0 ] ) ) ;
}
}
}
static void F_91 ( struct V_4 * V_5 )
{
struct V_124 * V_125 = V_5 -> V_126 ;
struct V_190 * V_191 = V_5 -> V_192 ;
unsigned short V_6 ;
T_4 V_225 ;
if ( ! V_125 -> V_224 )
return;
if ( F_18 ( V_5 , V_233 ) & 0x80 ) {
V_225 = F_12 ( V_5 , V_226 ) ;
V_6 = ( V_225 & 0xffff ) ;
F_88 ( V_191 , V_6 ) ;
}
}
static void F_92 ( struct V_4 * V_5 )
{
struct V_124 * V_125 = V_5 -> V_126 ;
struct V_190 * V_191 = V_5 -> V_192 ;
unsigned short V_6 ;
T_4 V_225 ;
if ( ! V_125 -> V_181 )
return;
if ( F_12 ( V_5 , V_183 ) & 0x01 ) {
F_3 ( V_5 , 0x01 , V_182 ) ;
V_225 = F_12 ( V_5 , V_227 ) ;
V_6 = ( V_225 >> 16 ) & 0xffff ;
F_88 ( V_191 , V_6 ) ;
}
}
static void F_93 ( struct V_4 * V_5 )
{
struct V_190 * V_191 = V_5 -> V_192 ;
#ifdef F_58
F_74 ( V_5 ) ;
#endif
F_90 ( V_5 ) ;
F_91 ( V_5 ) ;
F_92 ( V_5 ) ;
V_191 -> V_202 -> V_217 |= V_234 ;
}
static void F_94 ( struct V_4 * V_5 , struct V_190 * V_191 )
{
struct V_124 * V_125 = V_5 -> V_126 ;
if ( V_125 -> V_235 == V_236 ) {
#ifdef F_58
static const int V_179 = 10 ;
int V_180 ;
for ( V_180 = 0 ; V_180 < V_179 ; V_180 ++ ) {
F_72 ( V_5 ) ;
if ( ( V_191 -> V_202 -> V_217 & V_237 ) )
break;
F_66 ( 1 ) ;
}
#else
F_90 ( V_5 ) ;
V_191 -> V_202 -> V_217 |= V_237 ;
#endif
}
if ( ( V_125 -> V_238 & V_239 ) )
F_93 ( V_5 ) ;
}
static void F_95 ( struct V_4 * V_5 ,
unsigned short V_1 )
{
#ifdef F_58
struct V_124 * V_125 = V_5 -> V_126 ;
struct V_190 * V_191 ;
V_191 = & V_5 -> V_240 [ F_1 ( V_1 ) ] ;
F_96 ( & V_125 -> V_169 -> V_170 [ V_1 ] ,
V_191 ) ;
F_97 ( V_5 , V_191 ) ;
#endif
}
static void F_98 ( struct V_4 * V_5 , unsigned short V_241 )
{
unsigned short V_242 = 0 ;
if ( V_241 & V_243 )
V_242 |= V_244 ;
if ( V_241 & V_245 )
V_242 |= V_246 ;
if ( V_241 & V_247 )
V_242 |= V_248 ;
if ( V_241 & V_249 )
V_242 |= V_250 ;
if ( V_242 )
F_35 ( V_5 , V_242 , V_86 ) ;
}
static void F_99 ( struct V_4 * V_5 , unsigned short V_251 ,
unsigned V_252 )
{
struct V_190 * V_191 = V_5 -> V_192 ;
struct V_203 * V_204 = & V_191 -> V_202 -> V_204 ;
if ( V_191 -> type == V_253 )
return;
#ifdef F_58
if ( V_252 & V_254 )
F_72 ( V_5 ) ;
if ( V_252 & ~ ( V_255 | V_254 | V_256 | V_257 |
V_258 | V_259 | V_260 | V_261 |
V_262 | V_263 | V_264 ) ) {
F_42 ( V_5 -> V_25 ,
L_13 ,
V_252 ) ;
V_191 -> V_202 -> V_217 |= V_229 | V_234 ;
}
#endif
if ( V_251 & ( V_265 | V_266 | V_267 |
V_243 | V_245 ) ) {
if ( V_251 == 0xffff ) {
F_42 ( V_5 -> V_25 , L_14 ) ;
if ( F_100 ( V_191 ) ) {
V_191 -> V_202 -> V_217 |=
V_229 | V_234 ;
F_97 ( V_5 , V_191 ) ;
}
return;
}
if ( V_251 & ( V_265 | V_266 |
V_267 ) ) {
F_42 ( V_5 -> V_25 , L_15 ,
V_251 ) ;
F_93 ( V_5 ) ;
V_191 -> V_202 -> V_217 |= V_229 ;
if ( V_251 & ( V_265 | V_266 ) )
V_191 -> V_202 -> V_217 |= V_218 ;
F_97 ( V_5 , V_191 ) ;
return;
}
if ( V_251 & V_243 ) {
if ( V_204 -> V_268 == V_269 )
F_93 ( V_5 ) ;
}
}
#ifndef F_58
if ( V_251 & V_270 ) {
int V_180 ;
static const int V_179 = 10 ;
for ( V_180 = 0 ; V_180 < V_179 ; ++ V_180 ) {
F_89 ( V_5 ) ;
if ( ( F_39 ( V_5 , V_110 ) &
V_270 ) == 0 )
break;
}
}
#endif
if ( ( V_251 & V_249 ) )
F_94 ( V_5 , V_191 ) ;
F_97 ( V_5 , V_191 ) ;
}
static void F_101 ( struct V_4 * V_5 , unsigned short V_197 )
{
unsigned short V_242 = 0 ;
if ( V_197 & V_271 )
V_242 |= V_272 ;
if ( V_197 & V_273 )
V_242 |= V_274 ;
if ( V_197 & V_275 )
V_242 |= V_276 ;
if ( V_197 & V_277 )
V_242 |= V_278 ;
if ( V_197 & V_279 )
V_242 |= V_280 ;
if ( V_197 & V_281 )
V_242 |= V_282 ;
if ( V_197 & V_283 )
V_242 |= V_284 ;
if ( V_242 )
F_35 ( V_5 , V_242 , V_90 ) ;
}
static void F_102 ( struct V_4 * V_5 ,
unsigned short V_197 , unsigned V_285 )
{
struct V_190 * V_191 = V_5 -> V_196 ;
#ifdef F_58
if ( V_285 & V_254 ) {
struct V_124 * V_125 = V_5 -> V_126 ;
F_76 ( V_125 -> V_130 , V_5 ) ;
}
if ( V_285 & ~ ( V_255 | V_254 | V_256 | V_257 |
V_258 | V_259 | V_260 | V_261 |
V_262 | V_263 | V_264 ) ) {
F_42 ( V_5 -> V_25 ,
L_16 ,
V_285 ) ;
V_191 -> V_202 -> V_217 |= V_234 | V_229 ;
}
#endif
if ( V_197 == 0xffff )
return;
if ( V_197 & V_273 ) {
F_42 ( V_5 -> V_25 ,
L_17 ,
V_197 , F_39 ( V_5 , V_114 ) ) ;
V_191 -> V_202 -> V_217 |= V_218 ;
}
if ( V_197 & V_271 )
V_191 -> V_202 -> V_217 |= V_234 ;
#ifndef F_58
if ( V_197 & V_286 ) {
int V_287 ;
V_287 = F_82 ( V_5 , V_191 ) ;
if ( ! V_287 ) {
F_42 ( V_5 -> V_25 , L_18 ) ;
F_71 ( V_5 , V_92 ,
V_288 |
V_289 , 0 ) ;
V_191 -> V_202 -> V_217 |= V_218 ;
}
}
#endif
F_97 ( V_5 , V_191 ) ;
}
static void F_103 ( struct V_4 * V_5 , struct V_190 * V_191 ,
void * V_6 , unsigned int V_290 ,
unsigned int V_291 )
{
struct V_124 * V_125 = V_5 -> V_126 ;
struct V_201 * V_202 = V_191 -> V_202 ;
struct V_203 * V_204 = & V_202 -> V_204 ;
unsigned int V_292 = V_290 / F_104 ( V_191 ) ;
unsigned short * V_293 = V_6 ;
unsigned int * V_294 = V_6 ;
unsigned int V_180 ;
for ( V_180 = 0 ; V_180 < V_292 ; V_180 ++ ) {
#ifdef F_58
if ( V_191 -> V_295 & V_296 )
V_294 [ V_180 ] = F_105 ( V_294 [ V_180 ] ) ;
else
V_293 [ V_180 ] = F_106 ( V_293 [ V_180 ] ) ;
#endif
if ( V_191 -> V_295 & V_296 )
V_294 [ V_180 ] += V_125 -> V_297 [ V_291 ] ;
else
V_293 [ V_180 ] += V_125 -> V_297 [ V_291 ] ;
V_291 ++ ;
V_291 %= V_204 -> V_216 ;
}
}
static int F_107 ( struct V_4 * V_5 )
{
struct V_124 * V_125 = V_5 -> V_126 ;
struct V_190 * V_191 = V_5 -> V_192 ;
int V_193 ;
unsigned long V_127 ;
V_193 = F_51 ( V_5 ) ;
if ( V_193 )
return V_193 ;
F_108 ( V_191 , V_191 -> V_202 -> V_298 ) ;
F_36 ( & V_125 -> V_156 , V_127 ) ;
if ( V_125 -> V_157 == NULL ) {
F_37 ( & V_125 -> V_156 , V_127 ) ;
return - V_299 ;
}
if ( V_125 -> V_224 || V_125 -> V_181 )
F_109 ( V_125 -> V_157 , 32 , 16 ) ;
else if ( V_125 -> V_300 )
F_109 ( V_125 -> V_157 , 32 , 32 ) ;
else
F_109 ( V_125 -> V_157 , 16 , 16 ) ;
F_110 ( V_125 -> V_157 ) ;
F_37 ( & V_125 -> V_156 , V_127 ) ;
return 0 ;
}
static int F_111 ( struct V_4 * V_5 )
{
struct V_124 * V_125 = V_5 -> V_126 ;
struct V_190 * V_191 = V_5 -> V_196 ;
int V_193 ;
unsigned long V_127 ;
V_193 = F_54 ( V_5 ) ;
if ( V_193 )
return V_193 ;
F_112 ( V_191 , V_191 -> V_202 -> V_298 ) ;
F_36 ( & V_125 -> V_156 , V_127 ) ;
if ( V_125 -> V_162 ) {
if ( V_125 -> V_224 || V_125 -> V_301 ) {
F_109 ( V_125 -> V_162 , 32 , 32 ) ;
} else {
F_109 ( V_125 -> V_162 , 16 , 32 ) ;
}
F_110 ( V_125 -> V_162 ) ;
} else
V_193 = - V_299 ;
F_37 ( & V_125 -> V_156 , V_127 ) ;
return V_193 ;
}
static int F_113 ( struct V_4 * V_5 , struct V_190 * V_191 )
{
struct V_124 * V_125 = V_5 -> V_126 ;
F_59 ( V_5 ) ;
F_35 ( V_5 , V_302 | V_303 ,
V_98 ) ;
F_71 ( V_5 , V_88 ,
V_304 | V_305 |
V_306 | V_307 |
V_308 | V_309 |
V_310 , 0 ) ;
F_65 ( V_5 ) ;
if ( ! V_125 -> V_181 )
F_9 ( V_5 , 0 , V_311 ) ;
F_35 ( V_5 , V_312 , V_29 ) ;
F_35 ( V_5 , V_313 | V_314
,
V_33 ) ;
F_35 ( V_5 , 0x0000 , V_35 ) ;
F_35 ( V_5 , ( 0 << 6 ) | 0x0000 , V_37 ) ;
if ( V_125 -> V_224 ) {
F_35 ( V_5 ,
V_315 |
V_316 |
V_317 ,
V_41 ) ;
F_35 ( V_5 ,
F_114 ( 3 ) |
F_115 ( 0 ) |
F_116 ( 2 ) |
F_117 ( 3 ) |
F_118
( V_318 ) ,
V_39 ) ;
} else if ( V_125 -> V_181 ) {
F_35 ( V_5 , V_315 |
V_316 |
V_317 ,
V_41 ) ;
F_35 ( V_5 ,
F_114 ( 3 ) |
F_115 ( 0 ) |
F_116 ( 2 ) |
F_117 ( 3 ) |
F_118
( V_319 ) ,
V_39 ) ;
} else {
unsigned V_320 ;
F_35 ( V_5 ,
V_315 |
V_316 |
V_321 |
V_317 ,
V_41 ) ;
V_320 =
F_114 ( 3 ) |
F_115 ( 0 ) |
F_116 ( 2 ) |
F_117 ( 3 ) ;
if ( V_125 -> V_322 )
V_320 |=
F_118
( V_318 ) ;
else
V_320 |=
F_118
( V_319 ) ;
F_35 ( V_5 , V_320 ,
V_39 ) ;
}
F_35 ( V_5 ,
V_323 |
V_248 |
V_324 |
V_246 |
V_244 |
V_325 |
V_250 ,
V_86 ) ;
F_35 ( V_5 , V_326 , V_98 ) ;
return 0 ;
}
static int F_119 ( struct V_4 * V_5 , struct V_190 * V_191 )
{
unsigned long V_127 ;
int V_327 ;
F_36 ( & V_5 -> V_328 , V_127 ) ;
#ifndef F_58
F_90 ( V_5 ) ;
#else
F_72 ( V_5 ) ;
#endif
V_327 = F_120 ( V_191 ) ;
F_37 ( & V_5 -> V_328 , V_127 ) ;
return V_327 ;
}
static void F_121 ( struct V_4 * V_5 )
{
int V_180 ;
F_35 ( V_5 , V_329 , V_29 ) ;
for ( V_180 = 0 ; V_180 < V_330 ; ++ V_180 ) {
if ( ! ( F_39 ( V_5 , V_110 ) &
V_194 ) ) {
F_35 ( V_5 , 1 , V_27 ) ;
return;
}
F_66 ( 1 ) ;
}
F_42 ( V_5 -> V_25 , L_19 ) ;
}
static void F_122 ( struct V_4 * V_5 ,
unsigned int V_331 ,
unsigned int * V_332 )
{
const struct V_219 * V_220 = F_83 ( V_5 ) ;
struct V_124 * V_125 = V_5 -> V_126 ;
unsigned int V_205 , V_208 , V_333 ;
unsigned int V_180 ;
unsigned int V_334 ;
unsigned V_335 ;
F_35 ( V_5 , 1 , V_73 ) ;
if ( ( V_332 [ 0 ] & V_336 ) ) {
unsigned V_337 ;
V_205 = F_123 ( V_332 [ 0 ] ) ;
V_208 = F_81 ( V_332 [ 0 ] ) ;
V_335 = V_338 [ V_220 -> V_339 ] [ V_208 ] ;
V_334 = ( ( V_332 [ 0 ] & V_340 ) != 0 ) ;
V_337 = V_341 ;
V_337 |= V_205 ;
V_337 |=
( V_125 -> V_342 ) &
( V_343 |
V_344 |
V_345 |
V_346 ) ;
V_337 |= F_124 ( V_335 ) ;
if ( V_334 )
V_337 |= V_347 ;
V_337 |= V_348 ;
F_3 ( V_5 , V_337 , V_349 ) ;
} else {
F_3 ( V_5 , 0 , V_349 ) ;
}
for ( V_180 = 0 ; V_180 < V_331 ; V_180 ++ ) {
unsigned V_350 = 0 ;
V_205 = F_123 ( V_332 [ V_180 ] ) ;
V_333 = F_125 ( V_332 [ V_180 ] ) ;
V_208 = F_81 ( V_332 [ V_180 ] ) ;
V_334 = ( ( V_332 [ V_180 ] & V_340 ) != 0 ) ;
V_335 = V_338 [ V_220 -> V_339 ] [ V_208 ] ;
V_125 -> V_297 [ V_180 ] = 0 ;
switch ( V_333 ) {
case V_351 :
V_350 |=
V_352 ;
break;
case V_353 :
V_350 |=
V_354 ;
break;
case V_355 :
V_350 |=
V_356 ;
break;
case V_357 :
break;
}
V_350 |= F_126 ( V_205 ) ;
V_350 |=
F_127 ( V_220 -> V_358 , V_205 ) ;
V_350 |= F_128 ( V_335 ) ;
if ( V_180 == V_331 - 1 )
V_350 |= V_359 ;
if ( V_334 )
V_350 |= V_360 ;
V_350 |= V_361 ;
F_6 ( V_5 , V_350 , V_362 ) ;
}
F_121 ( V_5 ) ;
}
static void F_129 ( struct V_4 * V_5 ,
struct V_190 * V_191 ,
unsigned int V_331 , unsigned int * V_332 )
{
const struct V_219 * V_220 = F_83 ( V_5 ) ;
struct V_124 * V_125 = V_5 -> V_126 ;
unsigned int V_10 = ( V_191 -> V_363 + 1 ) >> 1 ;
unsigned int V_205 , V_208 , V_333 ;
unsigned int V_180 ;
unsigned int V_364 , V_365 ;
unsigned int V_334 ;
if ( V_125 -> V_128 ) {
F_122 ( V_5 , V_331 , V_332 ) ;
return;
}
if ( V_331 == 1 && ! V_125 -> V_224 && ! V_125 -> V_181 ) {
if ( V_125 -> V_366
&& V_125 -> V_367 == V_332 [ 0 ] ) {
return;
}
V_125 -> V_366 = 1 ;
V_125 -> V_367 = V_332 [ 0 ] ;
} else {
V_125 -> V_366 = 0 ;
}
F_35 ( V_5 , 1 , V_73 ) ;
if ( V_125 -> V_181 ) {
if ( ( V_332 [ 0 ] & V_336 )
&& ! V_125 -> V_368 ) {
F_6 ( V_5 , V_125 -> V_342 |
V_369 ,
V_370 ) ;
F_6 ( V_5 , V_125 -> V_342 ,
V_370 ) ;
V_125 -> V_368 = 1 ;
F_130 ( 100 ) ;
} else if ( ! ( V_332 [ 0 ] & V_336 )
&& V_125 -> V_368 ) {
F_6 ( V_5 , V_125 -> V_342 |
V_371 ,
V_370 ) ;
F_6 ( V_5 , V_125 -> V_342 ,
V_370 ) ;
V_125 -> V_368 = 0 ;
F_130 ( 100 ) ;
}
}
for ( V_180 = 0 ; V_180 < V_331 ; V_180 ++ ) {
if ( ! V_125 -> V_181 && ( V_332 [ V_180 ] & V_336 ) )
V_205 = V_125 -> V_342 ;
else
V_205 = F_123 ( V_332 [ V_180 ] ) ;
V_333 = F_125 ( V_332 [ V_180 ] ) ;
V_208 = F_81 ( V_332 [ V_180 ] ) ;
V_334 = ( ( V_332 [ V_180 ] & V_340 ) != 0 ) ;
V_208 = V_338 [ V_220 -> V_339 ] [ V_208 ] ;
if ( V_125 -> V_224 )
V_125 -> V_297 [ V_180 ] = V_10 ;
else
V_125 -> V_297 [ V_180 ] = ( V_208 & 0x100 ) ? 0 : V_10 ;
V_364 = 0 ;
if ( ( V_332 [ V_180 ] & V_336 ) ) {
if ( V_125 -> V_224 )
F_6 ( V_5 , F_123 ( V_332 [ V_180 ] ) & 0x0003 ,
V_372 ) ;
} else {
if ( V_125 -> V_224 )
V_333 = V_351 ;
else if ( V_125 -> V_181 )
V_333 = V_357 ;
switch ( V_333 ) {
case V_351 :
V_364 |= V_373 ;
break;
case V_353 :
V_364 |= V_374 ;
break;
case V_355 :
V_364 |= V_375 ;
break;
case V_357 :
break;
}
}
V_364 |= F_131 ( V_205 ) ;
F_6 ( V_5 , V_364 , V_376 ) ;
if ( ! V_125 -> V_181 ) {
V_365 = V_208 ;
if ( V_180 == V_331 - 1 )
V_365 |= V_377 ;
if ( V_334 )
V_365 |= V_378 ;
F_6 ( V_5 , V_365 , V_379 ) ;
}
}
if ( ! V_125 -> V_224 && ! V_125 -> V_181 )
F_121 ( V_5 ) ;
}
static int F_132 ( struct V_4 * V_5 ,
struct V_190 * V_191 ,
struct V_380 * V_381 ,
unsigned int * V_6 )
{
struct V_124 * V_125 = V_5 -> V_126 ;
unsigned int V_382 = ( V_191 -> V_363 + 1 ) >> 1 ;
int V_180 , V_200 ;
unsigned V_383 ;
unsigned short V_206 ;
unsigned long V_225 ;
F_129 ( V_5 , V_191 , 1 , & V_381 -> V_384 ) ;
F_65 ( V_5 ) ;
V_383 = V_125 -> V_297 [ 0 ] ;
if ( V_125 -> V_224 ) {
for ( V_200 = 0 ; V_200 < V_385 ; V_200 ++ ) {
F_35 ( V_5 , V_329 ,
V_29 ) ;
F_66 ( 1 ) ;
}
for ( V_200 = 0 ; V_200 < V_381 -> V_200 ; V_200 ++ ) {
F_35 ( V_5 , V_329 ,
V_29 ) ;
V_206 = 0 ;
for ( V_180 = 0 ; V_180 < V_330 ; V_180 ++ ) {
if ( F_18 ( V_5 , V_233 ) & 0x80 ) {
V_206 = F_12 ( V_5 , V_226 ) ;
V_206 >>= 16 ;
V_206 &= 0xffff ;
break;
}
if ( ! ( F_39 ( V_5 , V_110 ) &
V_194 ) ) {
V_206 = F_12 ( V_5 , V_226 ) ;
V_206 &= 0xffff ;
break;
}
}
if ( V_180 == V_330 ) {
F_42 ( V_5 -> V_25 , L_20 ,
V_26 ) ;
return - V_386 ;
}
V_206 += V_383 ;
V_6 [ V_200 ] = V_206 ;
}
} else if ( V_125 -> V_181 ) {
for ( V_200 = 0 ; V_200 < V_381 -> V_200 ; V_200 ++ ) {
F_35 ( V_5 , V_329 ,
V_29 ) ;
V_225 = 0 ;
for ( V_180 = 0 ; V_180 < V_330 ; V_180 ++ ) {
if ( F_12 ( V_5 , V_183 ) & 0x01 ) {
F_3 ( V_5 , 0x01 ,
V_182 ) ;
V_225 = F_12 ( V_5 , V_227 ) ;
break;
}
}
if ( V_180 == V_330 ) {
F_42 ( V_5 -> V_25 , L_20 ,
V_26 ) ;
return - V_386 ;
}
V_6 [ V_200 ] = ( ( ( V_225 >> 16 ) & 0xFFFF ) + V_383 ) & 0xFFFF ;
}
} else {
for ( V_200 = 0 ; V_200 < V_381 -> V_200 ; V_200 ++ ) {
F_35 ( V_5 , V_329 ,
V_29 ) ;
for ( V_180 = 0 ; V_180 < V_330 ; V_180 ++ ) {
if ( ! ( F_39 ( V_5 , V_110 ) &
V_194 ) )
break;
}
if ( V_180 == V_330 ) {
F_42 ( V_5 -> V_25 , L_20 ,
V_26 ) ;
return - V_386 ;
}
if ( V_125 -> V_128 ) {
V_225 = F_12 ( V_5 , V_387 ) ;
V_225 &= V_382 ;
V_6 [ V_200 ] = V_225 ;
} else {
V_206 = F_15 ( V_5 , V_230 ) ;
V_206 += V_383 ;
V_6 [ V_200 ] = V_206 ;
}
}
}
return V_381 -> V_200 ;
}
static int F_133 ( const struct V_4 * V_5 , unsigned V_388 ,
unsigned int V_127 )
{
struct V_124 * V_125 = V_5 -> V_126 ;
int V_389 ;
switch ( V_127 & V_390 ) {
case V_391 :
default:
V_389 = ( V_388 + V_125 -> V_392 / 2 ) / V_125 -> V_392 ;
break;
case V_393 :
V_389 = ( V_388 ) / V_125 -> V_392 ;
break;
case V_394 :
V_389 = ( V_388 + V_125 -> V_392 - 1 ) / V_125 -> V_392 ;
break;
}
return V_389 - 1 ;
}
static unsigned F_134 ( const struct V_4 * V_5 , int V_395 )
{
struct V_124 * V_125 = V_5 -> V_126 ;
return V_125 -> V_392 * ( V_395 + 1 ) ;
}
static unsigned F_135 ( struct V_4 * V_5 ,
unsigned V_396 )
{
const struct V_219 * V_220 = F_83 ( V_5 ) ;
struct V_124 * V_125 = V_5 -> V_126 ;
if ( V_125 -> V_224 || V_125 -> V_181 )
return V_220 -> V_397 ;
return V_220 -> V_397 * V_396 ;
}
static int F_136 ( struct V_4 * V_5 , struct V_190 * V_191 ,
struct V_203 * V_204 )
{
const struct V_219 * V_220 = F_83 ( V_5 ) ;
struct V_124 * V_125 = V_5 -> V_126 ;
int V_209 = 0 ;
unsigned int V_398 ;
unsigned int V_399 ;
if ( ( V_204 -> V_127 & V_400 ) )
V_204 -> V_127 &= ~ V_400 ;
V_209 |= F_137 ( & V_204 -> V_401 ,
V_402 | V_403 | V_404 ) ;
V_209 |= F_137 ( & V_204 -> V_405 ,
V_406 | V_404 ) ;
V_399 = V_406 | V_404 ;
if ( V_125 -> V_224 || V_125 -> V_181 )
V_399 |= V_402 ;
V_209 |= F_137 ( & V_204 -> V_407 , V_399 ) ;
V_209 |= F_137 ( & V_204 -> V_408 , V_269 ) ;
V_209 |= F_137 ( & V_204 -> V_268 , V_269 | V_409 ) ;
if ( V_209 )
return 1 ;
V_209 |= F_138 ( V_204 -> V_401 ) ;
V_209 |= F_138 ( V_204 -> V_405 ) ;
V_209 |= F_138 ( V_204 -> V_407 ) ;
V_209 |= F_138 ( V_204 -> V_268 ) ;
if ( V_209 )
return 2 ;
switch ( V_204 -> V_401 ) {
case V_402 :
case V_403 :
V_209 |= F_139 ( & V_204 -> V_410 , 0 ) ;
break;
case V_404 :
V_398 = F_123 ( V_204 -> V_410 ) ;
if ( V_398 > 16 )
V_398 = 16 ;
V_398 |= ( V_204 -> V_410 & ( V_411 | V_412 ) ) ;
V_209 |= F_139 ( & V_204 -> V_410 , V_398 ) ;
break;
}
if ( V_204 -> V_405 == V_406 ) {
V_209 |= F_140 ( & V_204 -> V_413 ,
F_135 ( V_5 , V_204 -> V_216 ) ) ;
V_209 |= F_141 ( & V_204 -> V_413 ,
V_125 -> V_392 * 0xffffff ) ;
} else if ( V_204 -> V_405 == V_404 ) {
unsigned int V_398 = F_123 ( V_204 -> V_413 ) ;
if ( V_398 > 16 )
V_398 = 16 ;
V_398 |= ( V_204 -> V_413 & ( V_411 | V_412 ) ) ;
V_209 |= F_139 ( & V_204 -> V_413 , V_398 ) ;
} else {
V_209 |= F_139 ( & V_204 -> V_413 , 0 ) ;
}
if ( V_204 -> V_407 == V_406 ) {
if ( V_125 -> V_224 || V_125 -> V_181 ) {
V_209 |= F_139 ( & V_204 -> V_414 , 0 ) ;
} else {
V_209 |= F_140 ( & V_204 -> V_414 ,
V_220 -> V_397 ) ;
V_209 |= F_141 ( & V_204 -> V_414 ,
V_125 -> V_392 * 0xffff ) ;
}
} else if ( V_204 -> V_407 == V_404 ) {
unsigned int V_398 = F_123 ( V_204 -> V_414 ) ;
if ( V_398 > 16 )
V_398 = 16 ;
V_398 |= ( V_204 -> V_414 & ( V_340 | V_411 ) ) ;
V_209 |= F_139 ( & V_204 -> V_414 , V_398 ) ;
} else if ( V_204 -> V_407 == V_402 ) {
V_209 |= F_139 ( & V_204 -> V_414 , 0 ) ;
}
V_209 |= F_139 ( & V_204 -> V_415 , V_204 -> V_216 ) ;
if ( V_204 -> V_268 == V_269 ) {
unsigned int V_416 = 0x01000000 ;
if ( V_125 -> V_224 )
V_416 -= V_385 ;
V_209 |= F_141 ( & V_204 -> V_417 , V_416 ) ;
V_209 |= F_140 ( & V_204 -> V_417 , 1 ) ;
} else {
V_209 |= F_139 ( & V_204 -> V_417 , 0 ) ;
}
if ( V_209 )
return 3 ;
if ( V_204 -> V_405 == V_406 ) {
V_398 = V_204 -> V_413 ;
V_204 -> V_413 =
F_134 ( V_5 , F_133 ( V_5 ,
V_204 -> V_413 ,
V_204 -> V_127 ) ) ;
if ( V_398 != V_204 -> V_413 )
V_209 ++ ;
}
if ( V_204 -> V_407 == V_406 ) {
if ( ! V_125 -> V_224 && ! V_125 -> V_181 ) {
V_398 = V_204 -> V_414 ;
V_204 -> V_414 =
F_134 ( V_5 , F_133 ( V_5 ,
V_204 -> V_414 ,
V_204 -> V_127 ) ) ;
if ( V_398 != V_204 -> V_414 )
V_209 ++ ;
if ( V_204 -> V_405 == V_406 &&
V_204 -> V_413 <
V_204 -> V_414 * V_204 -> V_415 ) {
V_204 -> V_413 =
V_204 -> V_414 * V_204 -> V_415 ;
V_209 ++ ;
}
}
}
if ( V_209 )
return 4 ;
return 0 ;
}
static int F_142 ( struct V_4 * V_5 ,
struct V_190 * V_191 ,
unsigned int V_418 )
{
struct V_124 * V_125 = V_5 -> V_126 ;
struct V_203 * V_204 = & V_191 -> V_202 -> V_204 ;
if ( V_418 != V_204 -> V_410 )
return - V_419 ;
F_35 ( V_5 , V_420 | V_125 -> V_238 ,
V_31 ) ;
V_191 -> V_202 -> V_421 = NULL ;
return 1 ;
}
static int F_143 ( struct V_4 * V_5 , struct V_190 * V_191 )
{
struct V_124 * V_125 = V_5 -> V_126 ;
const struct V_203 * V_204 = & V_191 -> V_202 -> V_204 ;
int V_395 ;
int V_422 = 0 ;
int V_423 = 0 ;
int V_424 = 0 ;
unsigned int V_425 ;
int V_426 = 0 ;
if ( V_5 -> V_427 == 0 ) {
F_42 ( V_5 -> V_25 , L_21 ) ;
return - V_299 ;
}
F_65 ( V_5 ) ;
F_129 ( V_5 , V_191 , V_204 -> V_216 , V_204 -> V_211 ) ;
F_35 ( V_5 , V_302 , V_98 ) ;
V_125 -> V_428 &= ~ V_429 ;
F_35 ( V_5 , V_125 -> V_428 ,
V_51 ) ;
switch ( V_204 -> V_401 ) {
case V_403 :
case V_402 :
F_35 ( V_5 ,
F_144 ( 0 ) |
V_430 | V_431 |
F_145 ( 0 ) ,
V_49 ) ;
break;
case V_404 :
{
int V_205 = F_123 ( V_204 -> V_410 ) ;
unsigned int V_188 = F_144 ( 0 ) |
V_430 | F_145 ( V_205 + 1 ) ;
if ( V_204 -> V_410 & V_411 )
V_188 |= V_432 ;
if ( V_204 -> V_410 & V_412 )
V_188 |= V_431 ;
F_35 ( V_5 , V_188 , V_49 ) ;
break;
}
}
V_423 &= ~ V_433 ;
V_423 &= ~ V_434 ;
V_423 &= ~ V_435 ;
F_35 ( V_5 , V_423 , V_35 ) ;
if ( V_204 -> V_216 == 1 || V_125 -> V_224 || V_125 -> V_181 ) {
V_424 |= V_436 ;
V_424 |= F_146 ( 31 ) ;
V_424 |= V_437 ;
} else {
V_424 |= F_146 ( 19 ) ;
}
F_35 ( V_5 , V_424 , V_47 ) ;
V_125 -> V_238 = 0 ;
switch ( V_204 -> V_268 ) {
case V_269 :
V_425 = V_204 -> V_417 - 1 ;
if ( V_125 -> V_224 ) {
V_425 += V_385 ;
}
F_38 ( V_5 , V_425 , V_11 ) ;
V_422 |= V_313 | V_314 | V_438 ;
F_35 ( V_5 , V_422 , V_33 ) ;
F_35 ( V_5 , V_439 , V_29 ) ;
if ( V_425 == 0 ) {
V_125 -> V_238 |= V_239 ;
V_426 |= V_308 ;
if ( V_204 -> V_216 > 1 )
V_424 |=
V_436 | V_440 ;
}
break;
case V_409 :
F_38 ( V_5 , 0 , V_11 ) ;
V_422 |= V_313 | V_314 | V_441 ;
F_35 ( V_5 , V_422 , V_33 ) ;
F_35 ( V_5 , V_439 , V_29 ) ;
break;
}
switch ( V_204 -> V_405 ) {
case V_406 :
V_424 |= V_442 | V_443 ;
F_35 ( V_5 , V_424 ,
V_47 ) ;
V_423 |= F_147 ( 0 ) ;
V_423 &= ~ V_444 ;
F_35 ( V_5 , V_423 , V_35 ) ;
V_395 = F_133 ( V_5 , V_204 -> V_413 ,
V_391 ) ;
F_38 ( V_5 , V_395 , V_13 ) ;
F_35 ( V_5 , V_445 , V_29 ) ;
break;
case V_404 :
if ( V_204 -> V_413 & V_412 )
V_424 |= V_442 ;
if ( V_204 -> V_413 & V_411 )
V_424 |= V_446 ;
if ( V_204 -> V_405 != V_204 -> V_407 ||
( V_204 -> V_413 & ~ V_412 ) !=
( V_204 -> V_414 & ~ V_412 ) )
V_424 |= V_443 ;
V_424 |=
F_148 ( 1 + F_123 ( V_204 -> V_413 ) ) ;
F_35 ( V_5 , V_424 ,
V_47 ) ;
break;
}
switch ( V_204 -> V_407 ) {
case V_406 :
case V_402 :
if ( V_204 -> V_414 == 0 || V_204 -> V_407 == V_402 )
V_395 = 1 ;
else
V_395 = F_133 ( V_5 , V_204 -> V_414 ,
V_391 ) ;
F_35 ( V_5 , 1 , V_43 ) ;
F_35 ( V_5 , V_395 , V_45 ) ;
V_423 &= ~ V_447 ;
V_423 |= V_448 ;
F_35 ( V_5 , V_423 , V_35 ) ;
F_35 ( V_5 , V_449 , V_29 ) ;
V_423 |= V_448 ;
V_423 |= V_447 ;
F_35 ( V_5 , V_423 , V_35 ) ;
break;
case V_404 :
V_422 |= F_149 ( 1 + V_204 -> V_414 ) ;
if ( ( V_204 -> V_414 & V_411 ) == 0 )
V_422 |= V_450 ;
F_35 ( V_5 , V_422 , V_33 ) ;
V_423 |= V_451 | V_452 ;
F_35 ( V_5 , V_423 , V_35 ) ;
break;
}
if ( V_5 -> V_427 ) {
V_426 |= V_309 |
V_304 ;
#ifndef F_58
V_426 |= V_310 ;
#endif
if ( V_204 -> V_127 & V_453
|| ( V_125 -> V_238 & V_239 ) ) {
V_125 -> V_235 = V_236 ;
} else {
V_125 -> V_235 = V_454 ;
}
switch ( V_125 -> V_235 ) {
case V_454 :
#ifdef F_58
F_35 ( V_5 , V_455 ,
V_37 ) ;
#else
F_35 ( V_5 , V_456 ,
V_37 ) ;
#endif
break;
case V_457 :
F_35 ( V_5 , V_458 ,
V_37 ) ;
break;
case V_236 :
#ifdef F_58
F_35 ( V_5 , V_458 ,
V_37 ) ;
#else
F_35 ( V_5 , V_456 ,
V_37 ) ;
#endif
V_426 |= V_308 ;
break;
default:
break;
}
F_35 ( V_5 ,
V_325 |
V_250 |
V_248 |
V_324 |
V_246 |
V_244 |
V_323 ,
V_86 ) ;
F_71 ( V_5 , V_88 ,
V_426 , 1 ) ;
} else {
F_71 ( V_5 , V_88 , ~ 0 , 0 ) ;
}
F_35 ( V_5 , V_326 , V_98 ) ;
switch ( V_204 -> V_405 ) {
case V_406 :
F_35 ( V_5 ,
V_459 | V_460 | V_461 | V_462 ,
V_29 ) ;
break;
case V_404 :
F_35 ( V_5 ,
V_459 | V_460 | V_461 | V_462 ,
V_29 ) ;
break;
}
#ifdef F_58
{
int V_193 = F_107 ( V_5 ) ;
if ( V_193 )
return V_193 ;
}
#endif
if ( V_204 -> V_401 == V_402 ) {
F_35 ( V_5 , V_420 | V_125 -> V_238 ,
V_31 ) ;
V_191 -> V_202 -> V_421 = NULL ;
} else if ( V_204 -> V_401 == V_404 ) {
V_191 -> V_202 -> V_421 = NULL ;
} else {
V_191 -> V_202 -> V_421 = F_142 ;
}
return 0 ;
}
static int F_150 ( struct V_4 * V_5 ,
struct V_190 * V_191 ,
struct V_380 * V_381 , unsigned int * V_6 )
{
struct V_124 * V_125 = V_5 -> V_126 ;
if ( V_381 -> V_200 < 1 )
return - V_419 ;
switch ( V_6 [ 0 ] ) {
case V_463 :
if ( V_125 -> V_128 ) {
if ( V_6 [ 1 ] & ~ ( V_343 |
V_344 |
V_345 |
V_346 ) ) {
return - V_419 ;
}
V_125 -> V_342 = V_6 [ 1 ] ;
} else if ( V_125 -> V_181 ) {
unsigned int V_464 ;
V_464 = V_6 [ 1 ] & 0xf ;
if ( V_464 > 0xF )
return - V_419 ;
V_125 -> V_342 = V_464 ;
F_6 ( V_5 , V_464 , V_370 ) ;
} else {
unsigned int V_464 ;
unsigned int V_465 ;
V_464 = V_6 [ 1 ] & 0xf ;
V_465 = ( V_6 [ 1 ] >> 4 ) & 0xff ;
if ( V_464 >= 8 )
return - V_419 ;
V_125 -> V_342 = V_464 ;
if ( V_125 -> V_224 ) {
F_9 ( V_5 , V_465 ,
V_466 ) ;
}
}
return 2 ;
default:
break;
}
return - V_419 ;
}
static void F_151 ( struct V_4 * V_5 , struct V_190 * V_191 ,
void * V_6 , unsigned int V_290 ,
unsigned int V_291 )
{
struct V_203 * V_204 = & V_191 -> V_202 -> V_204 ;
unsigned int V_292 = V_290 / F_104 ( V_191 ) ;
unsigned short * V_293 = V_6 ;
unsigned int V_180 ;
for ( V_180 = 0 ; V_180 < V_292 ; V_180 ++ ) {
unsigned int V_208 = F_81 ( V_204 -> V_211 [ V_291 ] ) ;
unsigned short V_133 = V_293 [ V_180 ] ;
if ( F_152 ( V_191 , V_208 ) )
V_133 = F_153 ( V_191 , V_133 ) ;
#ifdef F_58
V_133 = F_154 ( V_133 ) ;
#endif
V_293 [ V_180 ] = V_133 ;
V_291 ++ ;
V_291 %= V_204 -> V_216 ;
}
}
static int F_155 ( struct V_4 * V_5 ,
struct V_190 * V_191 ,
unsigned int V_384 [] ,
unsigned int V_467 , int V_468 )
{
struct V_124 * V_125 = V_5 -> V_126 ;
unsigned int V_208 ;
unsigned int V_205 ;
unsigned int V_469 ;
int V_180 ;
int V_470 = 0 ;
if ( V_468 ) {
for ( V_180 = 0 ; V_180 < V_191 -> V_331 ; ++ V_180 ) {
V_125 -> V_471 [ V_180 ] &= ~ V_472 ;
F_9 ( V_5 , V_125 -> V_471 [ V_180 ] ,
F_156 ( V_180 ) ) ;
F_9 ( V_5 , 0xf , F_157 ( V_180 ) ) ;
}
}
for ( V_180 = 0 ; V_180 < V_467 ; V_180 ++ ) {
const struct V_473 * V_474 ;
V_205 = F_123 ( V_384 [ V_180 ] ) ;
V_208 = F_81 ( V_384 [ V_180 ] ) ;
V_474 = V_191 -> V_475 -> V_208 + V_208 ;
V_470 = 0 ;
V_469 = 0 ;
switch ( V_474 -> V_476 - V_474 -> V_477 ) {
case 20000000 :
V_469 |= V_478 ;
F_9 ( V_5 , 0 ,
F_158 ( V_205 ) ) ;
break;
case 10000000 :
V_469 |= V_479 ;
F_9 ( V_5 , 0 ,
F_158 ( V_205 ) ) ;
break;
case 4000000 :
V_469 |= V_478 ;
F_9 ( V_5 , V_480 ,
F_158 ( V_205 ) ) ;
break;
case 2000000 :
V_469 |= V_479 ;
F_9 ( V_5 , V_480 ,
F_158 ( V_205 ) ) ;
break;
default:
F_42 ( V_5 -> V_25 ,
L_22 ,
V_26 ) ;
break;
}
switch ( V_474 -> V_476 + V_474 -> V_477 ) {
case 0 :
V_469 |= V_481 ;
break;
case 10000000 :
V_469 |= V_482 ;
break;
default:
F_42 ( V_5 -> V_25 ,
L_23 ,
V_26 ) ;
break;
}
if ( V_468 )
V_469 |= V_472 ;
F_9 ( V_5 , V_469 , F_156 ( V_205 ) ) ;
V_125 -> V_471 [ V_205 ] = V_469 ;
F_9 ( V_5 , V_180 , F_157 ( V_205 ) ) ;
}
return V_470 ;
}
static int F_159 ( struct V_4 * V_5 ,
struct V_190 * V_191 ,
unsigned int V_384 [] ,
unsigned int V_467 )
{
struct V_124 * V_125 = V_5 -> V_126 ;
unsigned int V_208 ;
unsigned int V_205 ;
unsigned int V_469 ;
int V_180 ;
int V_470 = 0 ;
for ( V_180 = 0 ; V_180 < V_467 ; V_180 ++ ) {
V_205 = F_123 ( V_384 [ V_180 ] ) ;
V_208 = F_81 ( V_384 [ V_180 ] ) ;
V_469 = F_160 ( V_205 ) ;
if ( F_152 ( V_191 , V_208 ) ) {
V_469 |= V_483 ;
V_470 = ( V_191 -> V_363 + 1 ) >> 1 ;
} else {
V_470 = 0 ;
}
if ( F_161 ( V_191 , V_208 ) )
V_469 |= V_484 ;
if ( V_384 [ V_180 ] & V_485 )
V_469 |= V_486 ;
V_469 |= ( F_125 ( V_384 [ V_180 ] ) ==
V_357 ) ? V_487 : 0 ;
F_6 ( V_5 , V_469 , V_488 ) ;
V_125 -> V_471 [ V_205 ] = V_469 ;
}
return V_470 ;
}
static int F_162 ( struct V_4 * V_5 ,
struct V_190 * V_191 ,
unsigned int V_384 [] , unsigned int V_467 ,
int V_468 )
{
struct V_124 * V_125 = V_5 -> V_126 ;
if ( V_125 -> V_128 )
return F_155 ( V_5 , V_191 , V_384 , V_467 ,
V_468 ) ;
else
return F_159 ( V_5 , V_191 , V_384 , V_467 ) ;
}
static int F_163 ( struct V_4 * V_5 ,
struct V_190 * V_191 ,
struct V_380 * V_381 ,
unsigned int * V_6 )
{
struct V_124 * V_125 = V_5 -> V_126 ;
unsigned int V_205 = F_123 ( V_381 -> V_384 ) ;
int V_180 ;
for ( V_180 = 0 ; V_180 < V_381 -> V_200 ; V_180 ++ )
V_6 [ V_180 ] = V_125 -> V_489 [ V_205 ] ;
return V_381 -> V_200 ;
}
static int F_164 ( struct V_4 * V_5 ,
struct V_190 * V_191 ,
struct V_380 * V_381 ,
unsigned int * V_6 )
{
struct V_124 * V_125 = V_5 -> V_126 ;
unsigned int V_205 = F_123 ( V_381 -> V_384 ) ;
unsigned int V_208 = F_81 ( V_381 -> V_384 ) ;
int V_7 ;
int V_180 ;
if ( V_125 -> V_212 ) {
F_68 ( V_5 , 1 << V_205 , V_490 ) ;
V_7 = F_165 ( V_205 ) ;
} else if ( V_125 -> V_128 ) {
V_7 = F_166 ( V_205 ) ;
} else {
V_7 = ( V_205 ) ? V_491 : V_492 ;
}
F_162 ( V_5 , V_191 , & V_381 -> V_384 , 1 , 0 ) ;
for ( V_180 = 0 ; V_180 < V_381 -> V_200 ; V_180 ++ ) {
unsigned int V_133 = V_6 [ V_180 ] ;
V_125 -> V_489 [ V_205 ] = V_133 ;
if ( V_125 -> V_212 ) {
V_133 = F_153 ( V_191 , V_133 ) ;
F_68 ( V_5 , V_133 , V_7 ) ;
} else if ( V_125 -> V_128 ) {
F_6 ( V_5 , V_133 , V_7 ) ;
} else {
if ( F_152 ( V_191 , V_208 ) )
V_133 = F_153 ( V_191 , V_133 ) ;
F_6 ( V_5 , V_133 , V_7 ) ;
}
}
return V_381 -> V_200 ;
}
static int F_167 ( struct V_4 * V_5 ,
struct V_190 * V_191 ,
struct V_380 * V_381 , unsigned int * V_6 )
{
const struct V_219 * V_220 = F_83 ( V_5 ) ;
struct V_124 * V_125 = V_5 -> V_126 ;
switch ( V_6 [ 0 ] ) {
case V_493 :
switch ( V_6 [ 1 ] ) {
case V_164 :
V_6 [ 2 ] = 1 + V_220 -> V_221 * sizeof( short ) ;
if ( V_125 -> V_130 )
V_6 [ 2 ] += V_125 -> V_130 -> V_494 ;
break;
case V_161 :
V_6 [ 2 ] = 0 ;
break;
default:
return - V_419 ;
}
return 0 ;
default:
break;
}
return - V_419 ;
}
static int F_168 ( struct V_4 * V_5 ,
struct V_190 * V_191 ,
unsigned int V_418 )
{
struct V_124 * V_125 = V_5 -> V_126 ;
struct V_203 * V_204 = & V_191 -> V_202 -> V_204 ;
int V_287 ;
int V_495 ;
int V_180 ;
static const int V_179 = 1000 ;
if ( V_418 != V_204 -> V_410 )
return - V_419 ;
V_191 -> V_202 -> V_421 = NULL ;
F_71 ( V_5 , V_92 ,
V_288 | V_289 , 0 ) ;
V_495 = V_289 ;
#ifdef F_58
F_35 ( V_5 , 1 , V_75 ) ;
if ( V_125 -> V_212 )
F_69 ( V_5 , 0x6 , V_223 ) ;
V_287 = F_111 ( V_5 ) ;
if ( V_287 )
return V_287 ;
V_287 = F_78 ( V_5 ) ;
if ( V_287 < 0 )
return V_287 ;
#else
V_287 = F_85 ( V_5 , V_191 ) ;
if ( V_287 == 0 )
return - V_199 ;
V_495 |= V_288 ;
#endif
F_35 ( V_5 , V_125 -> V_496 | V_497 ,
V_61 ) ;
F_35 ( V_5 , V_125 -> V_496 , V_61 ) ;
for ( V_180 = 0 ; V_180 < V_179 ; V_180 ++ ) {
F_66 ( 1 ) ;
if ( ( F_39 ( V_5 , V_120 ) &
V_498 ) == 0 )
break;
}
if ( V_180 == V_179 ) {
F_42 ( V_5 -> V_25 ,
L_24 ) ;
return - V_299 ;
}
F_35 ( V_5 , V_274 , V_90 ) ;
F_71 ( V_5 , V_92 , V_495 , 1 ) ;
F_35 ( V_5 , V_125 -> V_499 |
V_500 | V_501 | V_502 |
V_503 | V_504 ,
V_53 ) ;
F_35 ( V_5 , V_125 -> V_505 | V_506 ,
V_55 ) ;
return 0 ;
}
static int F_169 ( struct V_4 * V_5 , struct V_190 * V_191 )
{
const struct V_219 * V_220 = F_83 ( V_5 ) ;
struct V_124 * V_125 = V_5 -> V_126 ;
const struct V_203 * V_204 = & V_191 -> V_202 -> V_204 ;
int V_188 ;
int V_180 ;
unsigned V_507 ;
if ( V_5 -> V_427 == 0 ) {
F_42 ( V_5 -> V_25 , L_21 ) ;
return - V_299 ;
}
F_35 ( V_5 , V_508 , V_98 ) ;
F_35 ( V_5 , V_509 , V_53 ) ;
if ( V_125 -> V_212 ) {
F_68 ( V_5 , V_510 , V_511 ) ;
V_188 = 0 ;
for ( V_180 = 0 ; V_180 < V_204 -> V_216 ; V_180 ++ ) {
int V_205 ;
V_205 = F_123 ( V_204 -> V_211 [ V_180 ] ) ;
V_188 |= 1 << V_205 ;
F_68 ( V_5 , V_205 , V_512 ) ;
}
F_68 ( V_5 , V_188 , V_513 ) ;
}
F_162 ( V_5 , V_191 , V_204 -> V_211 , V_204 -> V_216 , 1 ) ;
if ( V_204 -> V_268 == V_409 ) {
V_125 -> V_514 |= V_515 ;
V_125 -> V_514 &= ~ V_516 ;
} else {
V_125 -> V_514 &= ~ V_515 ;
V_125 -> V_514 |= V_516 ;
}
F_35 ( V_5 , V_125 -> V_514 , V_57 ) ;
switch ( V_204 -> V_401 ) {
case V_403 :
case V_402 :
V_125 -> V_517 &=
~ ( V_518 | F_170 ( - 1 ) ) ;
V_125 -> V_517 |= V_519 | V_520 ;
F_35 ( V_5 , V_125 -> V_517 ,
V_69 ) ;
break;
case V_404 :
V_125 -> V_517 =
F_170 ( F_123 ( V_204 -> V_410 ) + 1 ) ;
if ( V_204 -> V_410 & V_411 )
V_125 -> V_517 |= V_518 ;
if ( V_204 -> V_410 & V_412 )
V_125 -> V_517 |= V_519 ;
F_35 ( V_5 , V_125 -> V_517 ,
V_69 ) ;
break;
default:
F_2 () ;
break;
}
V_125 -> V_496 &= ~ V_521 ;
F_35 ( V_5 , V_125 -> V_496 , V_61 ) ;
F_35 ( V_5 , V_125 -> V_514 , V_57 ) ;
V_125 -> V_522 &= ~ V_523 ;
F_35 ( V_5 , V_125 -> V_522 , V_59 ) ;
if ( V_204 -> V_268 == V_409 )
F_38 ( V_5 , 0xffffff , V_15 ) ;
else
F_38 ( V_5 , 0 , V_15 ) ;
F_35 ( V_5 , V_524 , V_53 ) ;
V_125 -> V_522 &= ~ V_525 ;
F_35 ( V_5 , V_125 -> V_522 , V_59 ) ;
switch ( V_204 -> V_268 ) {
case V_269 :
if ( V_125 -> V_128 ) {
F_38 ( V_5 , V_204 -> V_417 - 1 ,
V_17 ) ;
F_35 ( V_5 , V_526 , V_53 ) ;
} else {
F_38 ( V_5 , V_204 -> V_417 ,
V_17 ) ;
F_35 ( V_5 , V_526 , V_53 ) ;
F_38 ( V_5 , V_204 -> V_417 - 1 ,
V_17 ) ;
}
break;
case V_409 :
F_38 ( V_5 , 0xffffff , V_17 ) ;
F_35 ( V_5 , V_526 , V_53 ) ;
F_38 ( V_5 , 0xffffff , V_17 ) ;
break;
default:
F_38 ( V_5 , 0 , V_17 ) ;
F_35 ( V_5 , V_526 , V_53 ) ;
F_38 ( V_5 , V_204 -> V_417 , V_17 ) ;
}
V_125 -> V_514 &=
~ ( F_171 ( 0x1f ) | V_527 |
F_172 ( 0x1f ) | V_528 ) ;
switch ( V_204 -> V_405 ) {
case V_406 :
V_125 -> V_505 &= ~ V_529 ;
V_507 =
F_133 ( V_5 , V_204 -> V_413 ,
V_391 ) ;
F_38 ( V_5 , 1 , V_19 ) ;
F_35 ( V_5 , V_530 , V_53 ) ;
F_38 ( V_5 , V_507 , V_19 ) ;
break;
case V_404 :
V_125 -> V_514 |=
F_172 ( V_204 -> V_413 ) ;
if ( V_204 -> V_413 & V_411 )
V_125 -> V_514 |= V_528 ;
V_125 -> V_505 |= V_529 ;
break;
default:
F_2 () ;
break;
}
F_35 ( V_5 , V_125 -> V_505 , V_55 ) ;
F_35 ( V_5 , V_125 -> V_514 , V_57 ) ;
V_125 -> V_522 &=
~ ( F_173 ( 3 ) | V_531 ) ;
F_35 ( V_5 , V_125 -> V_522 , V_59 ) ;
if ( V_204 -> V_415 > 1 ) {
V_125 -> V_514 |= V_532 ;
F_35 ( V_5 ,
F_174 ( V_204 -> V_415 - 1 ) |
F_175 ( V_533 ) ,
V_63 ) ;
} else {
unsigned V_188 ;
V_125 -> V_514 &= ~ V_532 ;
V_188 = F_175 ( V_533 ) ;
if ( V_125 -> V_128 || V_125 -> V_212 ) {
V_188 |= F_174 ( 0 ) ;
} else {
V_188 |=
F_174 ( F_123 ( V_204 -> V_211 [ 0 ] ) ) ;
}
F_35 ( V_5 , V_188 , V_63 ) ;
}
F_35 ( V_5 , V_125 -> V_514 , V_57 ) ;
F_35 ( V_5 , V_504 | V_503 ,
V_53 ) ;
V_125 -> V_496 |= V_534 ;
F_35 ( V_5 , V_125 -> V_496 , V_61 ) ;
V_125 -> V_522 &= ~ V_535 ;
#ifdef F_58
V_125 -> V_522 |= V_536 ;
#else
V_125 -> V_522 |= V_537 ;
#endif
V_125 -> V_522 &= ~ V_538 ;
F_35 ( V_5 , V_125 -> V_522 , V_59 ) ;
V_188 = V_539 | V_540 |
V_541 ;
if ( V_220 -> V_221 )
V_188 |= V_542 ;
else
V_188 |= V_543 ;
#if 0
if (devpriv->is_m_series)
bits |= AO_Number_Of_DAC_Packages;
#endif
F_35 ( V_5 , V_188 , V_65 ) ;
F_35 ( V_5 , V_544 , V_67 ) ;
F_35 ( V_5 , V_545 , V_98 ) ;
if ( V_204 -> V_268 == V_269 ) {
F_35 ( V_5 , V_272 ,
V_90 ) ;
F_71 ( V_5 , V_92 ,
V_546 , 1 ) ;
}
V_191 -> V_202 -> V_421 = F_168 ;
return 0 ;
}
static int F_176 ( struct V_4 * V_5 , struct V_190 * V_191 ,
struct V_203 * V_204 )
{
const struct V_219 * V_220 = F_83 ( V_5 ) ;
struct V_124 * V_125 = V_5 -> V_126 ;
int V_209 = 0 ;
unsigned int V_398 ;
if ( ( V_204 -> V_127 & V_400 ) == 0 )
V_204 -> V_127 |= V_400 ;
V_209 |= F_137 ( & V_204 -> V_401 , V_403 | V_404 ) ;
V_209 |= F_137 ( & V_204 -> V_405 ,
V_406 | V_404 ) ;
V_209 |= F_137 ( & V_204 -> V_407 , V_402 ) ;
V_209 |= F_137 ( & V_204 -> V_408 , V_269 ) ;
V_209 |= F_137 ( & V_204 -> V_268 , V_269 | V_409 ) ;
if ( V_209 )
return 1 ;
V_209 |= F_138 ( V_204 -> V_401 ) ;
V_209 |= F_138 ( V_204 -> V_405 ) ;
V_209 |= F_138 ( V_204 -> V_268 ) ;
if ( V_209 )
return 2 ;
switch ( V_204 -> V_401 ) {
case V_403 :
V_209 |= F_139 ( & V_204 -> V_410 , 0 ) ;
break;
case V_404 :
V_398 = F_123 ( V_204 -> V_410 ) ;
if ( V_398 > 18 )
V_398 = 18 ;
V_398 |= ( V_204 -> V_410 & ( V_411 | V_412 ) ) ;
V_209 |= F_139 ( & V_204 -> V_410 , V_398 ) ;
break;
}
if ( V_204 -> V_405 == V_406 ) {
V_209 |= F_140 ( & V_204 -> V_413 ,
V_220 -> V_547 ) ;
V_209 |= F_141 ( & V_204 -> V_413 ,
V_125 -> V_392 * 0xffffff ) ;
}
V_209 |= F_139 ( & V_204 -> V_414 , 0 ) ;
V_209 |= F_139 ( & V_204 -> V_415 , V_204 -> V_216 ) ;
if ( V_204 -> V_268 == V_269 )
V_209 |= F_141 ( & V_204 -> V_417 , 0x00ffffff ) ;
else
V_209 |= F_139 ( & V_204 -> V_417 , 0 ) ;
if ( V_209 )
return 3 ;
if ( V_204 -> V_405 == V_406 ) {
V_398 = V_204 -> V_413 ;
V_204 -> V_413 =
F_134 ( V_5 , F_133 ( V_5 ,
V_204 -> V_413 ,
V_204 -> V_127 ) ) ;
if ( V_398 != V_204 -> V_413 )
V_209 ++ ;
}
if ( V_209 )
return 4 ;
return 0 ;
}
static int F_177 ( struct V_4 * V_5 , struct V_190 * V_191 )
{
struct V_124 * V_125 = V_5 -> V_126 ;
F_61 ( V_5 ) ;
F_35 ( V_5 , V_508 , V_98 ) ;
F_35 ( V_5 , V_509 , V_53 ) ;
F_71 ( V_5 , V_92 , ~ 0 , 0 ) ;
F_35 ( V_5 , V_539 , V_65 ) ;
F_35 ( V_5 , 0x3f98 , V_90 ) ;
F_35 ( V_5 , V_539 | V_540 |
V_541 , V_65 ) ;
F_35 ( V_5 , 0 , V_63 ) ;
F_35 ( V_5 , 0 , V_67 ) ;
V_125 -> V_499 = 0 ;
F_35 ( V_5 , V_125 -> V_499 , V_53 ) ;
V_125 -> V_505 = 0 ;
F_35 ( V_5 , V_125 -> V_505 , V_55 ) ;
V_125 -> V_514 = 0 ;
F_35 ( V_5 , V_125 -> V_514 , V_57 ) ;
V_125 -> V_522 = 0 ;
F_35 ( V_5 , V_125 -> V_522 , V_59 ) ;
if ( V_125 -> V_128 )
V_125 -> V_496 = V_548 ;
else
V_125 -> V_496 = 0 ;
F_35 ( V_5 , V_125 -> V_496 , V_61 ) ;
V_125 -> V_517 = 0 ;
F_35 ( V_5 , V_125 -> V_517 ,
V_69 ) ;
if ( V_125 -> V_212 ) {
unsigned V_549 = 0 ;
unsigned V_180 ;
for ( V_180 = 0 ; V_180 < V_191 -> V_331 ; ++ V_180 )
V_549 |= 1 << V_180 ;
F_68 ( V_5 , V_549 , V_490 ) ;
F_68 ( V_5 , V_510 , V_511 ) ;
}
F_35 ( V_5 , V_545 , V_98 ) ;
return 0 ;
}
static int F_178 ( struct V_4 * V_5 ,
struct V_190 * V_191 ,
struct V_380 * V_381 ,
unsigned int * V_6 )
{
struct V_124 * V_125 = V_5 -> V_126 ;
int V_287 ;
V_287 = F_179 ( V_5 , V_191 , V_381 , V_6 , 0 ) ;
if ( V_287 )
return V_287 ;
V_125 -> V_550 &= ~ V_551 ;
V_125 -> V_550 |= F_180 ( V_191 -> V_552 ) ;
F_35 ( V_5 , V_125 -> V_550 , V_77 ) ;
return V_381 -> V_200 ;
}
static int F_181 ( struct V_4 * V_5 ,
struct V_190 * V_191 ,
struct V_380 * V_381 ,
unsigned int * V_6 )
{
struct V_124 * V_125 = V_5 -> V_126 ;
if ( ( V_6 [ 0 ] & ( V_553 | V_554 ) ) && V_125 -> V_555 )
return - V_159 ;
if ( F_182 ( V_191 , V_6 ) ) {
V_125 -> V_556 &= ~ V_557 ;
V_125 -> V_556 |= F_183 ( V_191 -> V_558 ) ;
F_35 ( V_5 , V_125 -> V_556 , V_559 ) ;
}
V_6 [ 1 ] = F_39 ( V_5 , V_560 ) ;
return V_381 -> V_200 ;
}
static int F_184 ( struct V_4 * V_5 ,
struct V_190 * V_191 ,
struct V_380 * V_381 ,
unsigned int * V_6 )
{
int V_287 ;
V_287 = F_179 ( V_5 , V_191 , V_381 , V_6 , 0 ) ;
if ( V_287 )
return V_287 ;
F_3 ( V_5 , V_191 -> V_552 , V_561 ) ;
return V_381 -> V_200 ;
}
static int F_185 ( struct V_4 * V_5 ,
struct V_190 * V_191 ,
struct V_380 * V_381 ,
unsigned int * V_6 )
{
if ( F_182 ( V_191 , V_6 ) )
F_3 ( V_5 , V_191 -> V_558 , V_562 ) ;
V_6 [ 1 ] = F_12 ( V_5 , V_563 ) ;
return V_381 -> V_200 ;
}
static int F_186 ( struct V_4 * V_5 ,
struct V_190 * V_191 ,
struct V_203 * V_204 )
{
int V_180 ;
for ( V_180 = 0 ; V_180 < V_204 -> V_216 ; ++ V_180 ) {
unsigned int V_205 = F_123 ( V_204 -> V_211 [ V_180 ] ) ;
if ( V_205 != V_180 )
return - V_419 ;
}
return 0 ;
}
static int F_187 ( struct V_4 * V_5 ,
struct V_190 * V_191 , struct V_203 * V_204 )
{
int V_209 = 0 ;
int V_398 ;
V_209 |= F_137 ( & V_204 -> V_401 , V_403 ) ;
V_209 |= F_137 ( & V_204 -> V_405 , V_404 ) ;
V_209 |= F_137 ( & V_204 -> V_407 , V_402 ) ;
V_209 |= F_137 ( & V_204 -> V_408 , V_269 ) ;
V_209 |= F_137 ( & V_204 -> V_268 , V_409 ) ;
if ( V_209 )
return 1 ;
if ( V_209 )
return 2 ;
V_209 |= F_139 ( & V_204 -> V_410 , 0 ) ;
V_398 = V_204 -> V_413 ;
V_398 &= F_188 ( V_564 , 0 , 0 , V_411 ) ;
if ( V_398 != V_204 -> V_413 )
V_209 |= - V_419 ;
V_209 |= F_139 ( & V_204 -> V_414 , 0 ) ;
V_209 |= F_139 ( & V_204 -> V_415 , V_204 -> V_216 ) ;
V_209 |= F_139 ( & V_204 -> V_417 , 0 ) ;
if ( V_209 )
return 3 ;
if ( V_209 )
return 4 ;
if ( V_204 -> V_211 && V_204 -> V_216 > 0 )
V_209 |= F_186 ( V_5 , V_191 , V_204 ) ;
if ( V_209 )
return 5 ;
return 0 ;
}
static int F_189 ( struct V_4 * V_5 ,
struct V_190 * V_191 ,
unsigned int V_418 )
{
struct V_203 * V_204 = & V_191 -> V_202 -> V_204 ;
const unsigned V_179 = 1000 ;
int V_193 = 0 ;
unsigned V_180 ;
#ifdef F_58
struct V_124 * V_125 = V_5 -> V_126 ;
unsigned long V_127 ;
#endif
if ( V_418 != V_204 -> V_410 )
return - V_419 ;
V_191 -> V_202 -> V_421 = NULL ;
F_112 ( V_191 , V_191 -> V_202 -> V_298 ) ;
#ifdef F_58
F_36 ( & V_125 -> V_156 , V_127 ) ;
if ( V_125 -> V_172 ) {
F_109 ( V_125 -> V_172 , 32 , 32 ) ;
F_110 ( V_125 -> V_172 ) ;
} else {
F_42 ( V_5 -> V_25 , L_25 ) ;
V_193 = - V_299 ;
}
F_37 ( & V_125 -> V_156 , V_127 ) ;
if ( V_193 < 0 )
return V_193 ;
#endif
for ( V_180 = 0 ; V_180 < V_179 ; ++ V_180 ) {
if ( F_12 ( V_5 , V_565 ) & V_566 )
break;
F_66 ( 10 ) ;
}
if ( V_180 == V_179 ) {
F_42 ( V_5 -> V_25 , L_26 ) ;
V_191 -> V_567 ( V_5 , V_191 ) ;
return - V_299 ;
}
F_3 ( V_5 , V_568 | V_569 |
V_570 ,
V_571 ) ;
return V_193 ;
}
static int F_190 ( struct V_4 * V_5 , struct V_190 * V_191 )
{
const struct V_203 * V_204 = & V_191 -> V_202 -> V_204 ;
unsigned V_572 = V_573 | V_574 ;
int V_193 ;
F_3 ( V_5 , V_575 , V_571 ) ;
switch ( V_204 -> V_405 ) {
case V_404 :
V_572 |=
F_123 ( V_204 -> V_413 ) &
V_564 ;
break;
default:
F_2 () ;
break;
}
if ( V_204 -> V_413 & V_411 )
V_572 |= V_576 ;
F_3 ( V_5 , V_572 , V_577 ) ;
if ( V_191 -> V_552 ) {
F_3 ( V_5 , V_191 -> V_558 , V_578 ) ;
F_3 ( V_5 , V_579 , V_571 ) ;
F_3 ( V_5 , V_191 -> V_552 , V_580 ) ;
} else {
F_42 ( V_5 -> V_25 ,
L_27 ) ;
return - V_299 ;
}
V_193 = F_57 ( V_5 ) ;
if ( V_193 < 0 )
return V_193 ;
V_191 -> V_202 -> V_421 = F_189 ;
return 0 ;
}
static int F_191 ( struct V_4 * V_5 , struct V_190 * V_191 )
{
F_3 ( V_5 , V_581 | V_582 |
V_583 |
V_584 ,
V_571 ) ;
F_3 ( V_5 , 0 , V_580 ) ;
F_63 ( V_5 ) ;
return 0 ;
}
static void F_192 ( struct V_4 * V_5 )
{
struct V_124 * V_125 = V_5 -> V_126 ;
unsigned V_585 ;
struct V_190 * V_191 = & V_5 -> V_240 [ V_586 ] ;
#ifdef F_58
unsigned long V_127 ;
#endif
if ( ! V_125 -> V_128 )
return;
#ifdef F_58
F_36 ( & V_125 -> V_156 , V_127 ) ;
if ( V_125 -> V_172 ) {
unsigned V_587 =
F_193 ( V_125 -> V_172 ) ;
if ( V_587 & V_254 ) {
F_4 ( V_588 ,
V_125 -> V_130 -> V_589 +
F_194 ( V_125 -> V_172 -> V_144 ) ) ;
}
F_77 ( V_125 -> V_172 , V_191 ) ;
}
F_37 ( & V_125 -> V_156 , V_127 ) ;
#endif
V_585 = F_12 ( V_5 , V_565 ) ;
if ( V_585 & ( V_590 | V_591 ) ) {
F_3 ( V_5 , V_592 ,
V_571 ) ;
V_191 -> V_202 -> V_217 |= V_218 ;
}
if ( V_585 & V_593 ) {
F_3 ( V_5 , V_583 ,
V_571 ) ;
}
F_97 ( V_5 , V_191 ) ;
}
static int F_195 ( struct V_4 * V_5 ,
struct V_190 * V_191 ,
unsigned char V_594 ,
unsigned char * V_595 )
{
struct V_124 * V_125 = V_5 -> V_126 ;
unsigned int V_596 ;
int V_209 = 0 , V_327 = 20 ;
V_125 -> V_556 &= ~ V_597 ;
V_125 -> V_556 |= F_196 ( V_594 ) ;
F_35 ( V_5 , V_125 -> V_556 , V_559 ) ;
V_596 = F_39 ( V_5 , V_118 ) ;
if ( V_596 & V_598 ) {
V_209 = - V_159 ;
goto Error;
}
V_125 -> V_550 |= V_599 ;
F_35 ( V_5 , V_125 -> V_550 , V_77 ) ;
V_125 -> V_550 &= ~ V_599 ;
while ( ( V_596 = F_39 ( V_5 , V_118 ) ) &
V_598 ) {
F_66 ( ( V_125 -> V_555 + 999 ) / 1000 ) ;
if ( -- V_327 < 0 ) {
F_42 ( V_5 -> V_25 ,
L_28 ,
V_26 ) ;
V_209 = - V_386 ;
goto Error;
}
}
F_66 ( ( V_125 -> V_555 + 999 ) / 1000 ) ;
if ( V_595 != NULL )
* V_595 = F_39 ( V_5 , V_116 ) ;
Error:
F_35 ( V_5 , V_125 -> V_550 , V_77 ) ;
return V_209 ;
}
static int F_197 ( struct V_4 * V_5 ,
struct V_190 * V_191 ,
unsigned char V_594 ,
unsigned char * V_595 )
{
struct V_124 * V_125 = V_5 -> V_126 ;
unsigned char V_382 , V_600 = 0 ;
F_66 ( ( V_125 -> V_555 + 999 ) / 1000 ) ;
for ( V_382 = 0x80 ; V_382 ; V_382 >>= 1 ) {
V_125 -> V_556 &= ~ V_554 ;
if ( V_594 & V_382 )
V_125 -> V_556 |= V_554 ;
F_35 ( V_5 , V_125 -> V_556 , V_559 ) ;
V_125 -> V_550 |= V_601 ;
F_35 ( V_5 , V_125 -> V_550 , V_77 ) ;
F_66 ( ( V_125 -> V_555 + 999 ) / 2000 ) ;
V_125 -> V_550 &= ~ V_601 ;
F_35 ( V_5 , V_125 -> V_550 , V_77 ) ;
F_66 ( ( V_125 -> V_555 + 999 ) / 2000 ) ;
if ( F_39 ( V_5 , V_560 ) & V_553 )
V_600 |= V_382 ;
}
if ( V_595 )
* V_595 = V_600 ;
return 0 ;
}
static int F_198 ( struct V_4 * V_5 ,
struct V_190 * V_191 ,
struct V_380 * V_381 ,
unsigned int * V_6 )
{
struct V_124 * V_125 = V_5 -> V_126 ;
int V_209 = V_381 -> V_200 ;
unsigned char V_602 , V_603 = 0 ;
if ( V_381 -> V_200 != 2 )
return - V_419 ;
switch ( V_6 [ 0 ] ) {
case V_604 :
V_125 -> V_605 = 1 ;
V_125 -> V_550 |= V_606 ;
if ( V_6 [ 1 ] == V_607 ) {
V_125 -> V_605 = 0 ;
V_125 -> V_550 &= ~ ( V_606 |
V_601 ) ;
V_6 [ 1 ] = V_607 ;
V_125 -> V_555 = V_6 [ 1 ] ;
} else if ( V_6 [ 1 ] <= V_608 ) {
V_125 -> V_550 &= ~ V_609 ;
V_125 -> V_610 |= V_611 ;
V_125 -> V_610 &= ~ V_612 ;
V_6 [ 1 ] = V_608 ;
V_125 -> V_555 = V_6 [ 1 ] ;
} else if ( V_6 [ 1 ] <= V_613 ) {
V_125 -> V_550 &= ~ V_609 ;
V_125 -> V_610 |= V_611 |
V_612 ;
V_6 [ 1 ] = V_613 ;
V_125 -> V_555 = V_6 [ 1 ] ;
} else if ( V_6 [ 1 ] <= V_614 ) {
V_125 -> V_550 |= V_609 ;
V_125 -> V_610 |= V_611 |
V_612 ;
V_6 [ 1 ] = V_614 ;
V_125 -> V_555 = V_6 [ 1 ] ;
} else {
V_125 -> V_550 &= ~ ( V_606 |
V_601 ) ;
V_125 -> V_605 = 0 ;
V_6 [ 1 ] = ( V_6 [ 1 ] / 1000 ) * 1000 ;
V_125 -> V_555 = V_6 [ 1 ] ;
}
F_35 ( V_5 , V_125 -> V_550 , V_77 ) ;
F_35 ( V_5 , V_125 -> V_610 ,
V_71 ) ;
return 1 ;
break;
case V_615 :
if ( V_125 -> V_555 == 0 )
return - V_419 ;
V_602 = V_6 [ 1 ] & 0xFF ;
if ( V_125 -> V_605 ) {
V_209 = F_195 ( V_5 , V_191 , V_602 ,
& V_603 ) ;
} else if ( V_125 -> V_555 > 0 ) {
V_209 = F_197 ( V_5 , V_191 , V_602 ,
& V_603 ) ;
} else {
F_42 ( V_5 -> V_25 , L_29 ,
V_26 ) ;
return - V_419 ;
}
if ( V_209 < 0 )
return V_209 ;
V_6 [ 1 ] = V_603 & 0xFF ;
return V_381 -> V_200 ;
break;
default:
return - V_419 ;
}
}
static void F_199 ( struct V_4 * V_5 , struct V_190 * V_191 )
{
int V_180 ;
for ( V_180 = 0 ; V_180 < V_191 -> V_331 ; V_180 ++ ) {
F_68 ( V_5 , F_160 ( V_180 ) | 0x0 ,
V_616 ) ;
}
F_68 ( V_5 , 0x0 , V_617 ) ;
}
static unsigned F_200 ( enum V_618 V_7 )
{
unsigned V_619 ;
switch ( V_7 ) {
case V_620 :
V_619 = F_27 ( 0 ) ;
break;
case V_621 :
V_619 = F_27 ( 1 ) ;
break;
case V_622 :
V_619 = F_28 ( 0 ) ;
break;
case V_623 :
V_619 = F_28 ( 1 ) ;
break;
case V_624 :
V_619 = F_32 ( 0 ) ;
break;
case V_625 :
V_619 = F_32 ( 1 ) ;
break;
case V_626 :
V_619 = F_33 ( 0 ) ;
break;
case V_627 :
V_619 = F_33 ( 1 ) ;
break;
case V_628 :
V_619 = F_30 ( 0 ) ;
break;
case V_629 :
V_619 = F_30 ( 1 ) ;
break;
case V_630 :
V_619 = F_22 ( 0 ) ;
break;
case V_631 :
V_619 = F_22 ( 1 ) ;
break;
case V_632 :
V_619 = F_23 ( 0 ) ;
break;
case V_633 :
V_619 = F_23 ( 1 ) ;
break;
case V_634 :
V_619 = F_29 ( 0 ) ;
break;
case V_635 :
V_619 = F_29 ( 1 ) ;
break;
case V_636 :
V_619 = V_122 ;
break;
case V_637 :
V_619 = V_98 ;
break;
case V_638 :
V_619 = V_118 ;
break;
case V_639 :
V_619 = V_120 ;
break;
case V_640 :
V_619 = V_86 ;
break;
case V_641 :
V_619 = V_90 ;
break;
case V_642 :
V_619 = V_110 ;
break;
case V_643 :
V_619 = V_112 ;
break;
case V_644 :
V_619 = V_88 ;
break;
case V_645 :
V_619 = V_92 ;
break;
default:
F_201 ( L_30 ,
V_26 , V_7 ) ;
F_2 () ;
return 0 ;
}
return V_619 ;
}
static void F_202 ( struct V_646 * V_647 , unsigned V_188 ,
enum V_618 V_7 )
{
struct V_4 * V_5 = V_647 -> V_169 -> V_5 ;
unsigned V_619 ;
static const unsigned V_648 = V_649 | V_650 ;
static const unsigned V_651 =
V_652 | V_653 ;
static const unsigned V_654 =
V_655 | V_656 ;
switch ( V_7 ) {
case V_657 :
F_6 ( V_5 , V_188 , V_658 ) ;
break;
case V_659 :
F_6 ( V_5 , V_188 , V_660 ) ;
break;
case V_661 :
F_6 ( V_5 , V_188 , V_662 ) ;
break;
case V_663 :
F_6 ( V_5 , V_188 , V_664 ) ;
break;
case V_665 :
F_6 ( V_5 , V_188 , V_666 ) ;
break;
case V_667 :
F_6 ( V_5 , V_188 , V_668 ) ;
break;
case V_669 :
F_6 ( V_5 , V_188 , V_670 ) ;
break;
case V_671 :
F_6 ( V_5 , V_188 , V_672 ) ;
break;
case V_630 :
case V_631 :
case V_632 :
case V_633 :
V_619 = F_200 ( V_7 ) ;
F_38 ( V_5 , V_188 , V_619 ) ;
break;
case V_644 :
F_52 ( V_188 & ~ V_651 ) ;
F_41 ( V_5 , V_88 ,
V_651 , V_188 ) ;
break;
case V_645 :
F_52 ( V_188 & ~ V_654 ) ;
F_41 ( V_5 , V_92 ,
V_654 , V_188 ) ;
break;
case V_637 :
F_52 ( V_188 & ~ V_648 ) ;
default:
V_619 = F_200 ( V_7 ) ;
F_35 ( V_5 , V_188 , V_619 ) ;
}
}
static unsigned F_203 ( struct V_646 * V_647 ,
enum V_618 V_7 )
{
struct V_4 * V_5 = V_647 -> V_169 -> V_5 ;
unsigned V_619 ;
switch ( V_7 ) {
case V_673 :
return F_15 ( V_5 , V_674 ) ;
case V_675 :
return F_15 ( V_5 , V_676 ) ;
case V_624 :
case V_625 :
case V_626 :
case V_627 :
V_619 = F_200 ( V_7 ) ;
return F_40 ( V_5 , V_619 ) ;
default:
V_619 = F_200 ( V_7 ) ;
return F_39 ( V_5 , V_619 ) ;
}
return 0 ;
}
static int F_204 ( struct V_4 * V_5 ,
struct V_190 * V_191 ,
struct V_380 * V_381 ,
unsigned int * V_6 )
{
struct V_124 * V_125 = V_5 -> V_126 ;
unsigned int V_133 = V_125 -> V_610 & V_677 ;
int V_180 ;
for ( V_180 = 0 ; V_180 < V_381 -> V_200 ; V_180 ++ )
V_6 [ V_180 ] = V_133 ;
return V_381 -> V_200 ;
}
static int F_205 ( struct V_4 * V_5 ,
struct V_190 * V_191 ,
struct V_380 * V_381 ,
unsigned int * V_6 )
{
struct V_124 * V_125 = V_5 -> V_126 ;
if ( V_381 -> V_200 ) {
V_125 -> V_610 &= ~ V_678 ;
F_35 ( V_5 , V_125 -> V_610 ,
V_71 ) ;
V_125 -> V_610 &= ~ V_677 ;
V_125 -> V_610 |= F_206 ( V_6 [ V_381 -> V_200 - 1 ] ) ;
V_125 -> V_610 |= V_678 ;
F_35 ( V_5 , V_125 -> V_610 ,
V_71 ) ;
}
return V_381 -> V_200 ;
}
static int F_207 ( struct V_4 * V_5 ,
struct V_190 * V_191 ,
struct V_380 * V_381 ,
unsigned int * V_6 )
{
struct V_124 * V_125 = V_5 -> V_126 ;
switch ( V_6 [ 0 ] ) {
case V_679 :
switch ( V_6 [ 1 ] ) {
case V_680 :
V_125 -> V_610 &= ~ V_681 ;
break;
case V_682 :
V_125 -> V_610 |= V_681 ;
break;
default:
return - V_419 ;
}
F_35 ( V_5 , V_125 -> V_610 ,
V_71 ) ;
break;
case V_683 :
if ( V_125 -> V_610 & V_681 ) {
V_6 [ 1 ] = V_682 ;
V_6 [ 2 ] = V_684 ;
} else {
V_6 [ 1 ] = V_680 ;
V_6 [ 2 ] = V_685 * 2 ;
}
break;
default:
return - V_419 ;
}
return V_381 -> V_200 ;
}
static int F_208 ( int V_160 , int V_686 , int V_6 , unsigned long V_687 )
{
struct V_4 * V_5 = (struct V_4 * ) V_687 ;
if ( V_160 ) {
F_9 ( V_5 , V_6 , V_688 + 2 * V_686 ) ;
return 0 ;
}
return F_18 ( V_5 , V_688 + 2 * V_686 ) ;
}
static int F_209 ( struct V_4 * V_5 , unsigned int * V_6 )
{
struct V_124 * V_125 = V_5 -> V_126 ;
V_6 [ 1 ] = V_125 -> V_689 * V_125 -> V_392 ;
V_6 [ 2 ] = V_125 -> V_690 * V_125 -> V_392 ;
return 3 ;
}
static int F_210 ( struct V_4 * V_5 ,
struct V_190 * V_191 ,
struct V_380 * V_381 ,
unsigned int * V_6 )
{
struct V_124 * V_125 = V_5 -> V_126 ;
unsigned V_691 , V_692 ;
switch ( V_6 [ 0 ] ) {
case V_693 :
switch ( V_6 [ 1 ] ) {
case V_391 :
V_691 =
( V_6 [ 2 ] +
V_125 -> V_392 / 2 ) / V_125 -> V_392 ;
break;
case V_393 :
V_691 = V_6 [ 2 ] / V_125 -> V_392 ;
break;
case V_394 :
V_691 =
( V_6 [ 2 ] + V_125 -> V_392 -
1 ) / V_125 -> V_392 ;
break;
default:
return - V_419 ;
}
switch ( V_6 [ 3 ] ) {
case V_391 :
V_692 =
( V_6 [ 4 ] +
V_125 -> V_392 / 2 ) / V_125 -> V_392 ;
break;
case V_393 :
V_692 = V_6 [ 4 ] / V_125 -> V_392 ;
break;
case V_394 :
V_692 =
( V_6 [ 4 ] + V_125 -> V_392 -
1 ) / V_125 -> V_392 ;
break;
default:
return - V_419 ;
}
if ( V_691 * V_125 -> V_392 != V_6 [ 2 ] ||
V_692 * V_125 -> V_392 != V_6 [ 4 ] ) {
V_6 [ 2 ] = V_691 * V_125 -> V_392 ;
V_6 [ 4 ] = V_692 * V_125 -> V_392 ;
return - V_694 ;
}
F_3 ( V_5 , F_211 ( V_691 ) |
F_212 ( V_692 ) ,
V_695 ) ;
V_125 -> V_689 = V_691 ;
V_125 -> V_690 = V_692 ;
return 5 ;
case V_696 :
return F_209 ( V_5 , V_6 ) ;
default:
return - V_419 ;
}
return 0 ;
}
static int F_213 ( struct V_4 * V_5 ,
struct V_190 * V_191 ,
struct V_380 * V_381 ,
unsigned int * V_6 )
{
struct V_124 * V_125 = V_5 -> V_126 ;
unsigned V_691 , V_692 ;
switch ( V_6 [ 0 ] ) {
case V_693 :
switch ( V_6 [ 1 ] ) {
case V_391 :
V_691 =
( V_6 [ 2 ] +
V_125 -> V_392 / 2 ) / V_125 -> V_392 ;
break;
case V_393 :
V_691 = V_6 [ 2 ] / V_125 -> V_392 ;
break;
case V_394 :
V_691 =
( V_6 [ 2 ] + V_125 -> V_392 -
1 ) / V_125 -> V_392 ;
break;
default:
return - V_419 ;
}
switch ( V_6 [ 3 ] ) {
case V_391 :
V_692 =
( V_6 [ 4 ] +
V_125 -> V_392 / 2 ) / V_125 -> V_392 ;
break;
case V_393 :
V_692 = V_6 [ 4 ] / V_125 -> V_392 ;
break;
case V_394 :
V_692 =
( V_6 [ 4 ] + V_125 -> V_392 -
1 ) / V_125 -> V_392 ;
break;
default:
return - V_419 ;
}
if ( V_691 * V_125 -> V_392 != V_6 [ 2 ] ||
V_692 * V_125 -> V_392 != V_6 [ 4 ] ) {
V_6 [ 2 ] = V_691 * V_125 -> V_392 ;
V_6 [ 4 ] = V_692 * V_125 -> V_392 ;
return - V_694 ;
}
F_3 ( V_5 , V_691 , V_697 ) ;
V_125 -> V_689 = V_691 ;
F_3 ( V_5 , V_692 , V_698 ) ;
V_125 -> V_690 = V_692 ;
return 5 ;
case V_696 :
return F_209 ( V_5 , V_6 ) ;
default:
return - V_419 ;
}
return 0 ;
}
static int F_214 ( int V_185 , int V_133 , int * V_699 )
{
V_185 ++ ;
* V_699 = ( ( V_185 & 0x1 ) << 11 ) |
( ( V_185 & 0x2 ) << 9 ) |
( ( V_185 & 0x4 ) << 7 ) | ( ( V_185 & 0x8 ) << 5 ) | ( V_133 & 0xff ) ;
return 12 ;
}
static int F_215 ( int V_185 , int V_133 , int * V_699 )
{
* V_699 = ( ( V_185 & 0x7 ) << 8 ) | ( V_133 & 0xff ) ;
return 11 ;
}
static int F_216 ( int V_185 , int V_133 , int * V_699 )
{
* V_699 = V_133 & 0xfff ;
return 12 ;
}
static int F_217 ( int V_185 , int V_133 , int * V_699 )
{
* V_699 = ( V_133 & 0xfff ) | ( V_185 ? 0xc000 : 0xa000 ) ;
return 16 ;
}
static int F_218 ( int V_185 , int V_133 , int * V_699 )
{
* V_699 = ( ( V_185 & 0xf ) << 8 ) | ( V_133 & 0xff ) ;
return 12 ;
}
static int F_219 ( int V_185 , int V_133 , int * V_699 )
{
* V_699 = ( ( V_185 + 1 ) << 8 ) | ( V_133 & 0xff ) ;
return 12 ;
}
static void F_220 ( struct V_4 * V_5 , int V_185 , int V_133 )
{
const struct V_219 * V_220 = F_83 ( V_5 ) ;
struct V_124 * V_125 = V_5 -> V_126 ;
unsigned int V_700 = 0 , V_188 = 0 , V_701 , V_699 = 0 ;
int V_180 ;
int type ;
if ( V_125 -> V_702 [ V_185 ] == V_133 )
return;
V_125 -> V_702 [ V_185 ] = V_133 ;
for ( V_180 = 0 ; V_180 < 3 ; V_180 ++ ) {
type = V_220 -> V_703 [ V_180 ] ;
if ( type == V_704 )
break;
if ( V_185 < V_702 [ type ] . V_467 ) {
V_188 = V_702 [ type ] . F_221 ( V_185 , V_133 , & V_699 ) ;
V_700 = F_222 ( V_180 ) ;
break;
}
V_185 -= V_702 [ type ] . V_467 ;
}
for ( V_701 = 1 << ( V_188 - 1 ) ; V_701 ; V_701 >>= 1 ) {
F_9 ( V_5 , ( ( V_701 & V_699 ) ? 0x02 : 0 ) , V_705 ) ;
F_66 ( 1 ) ;
F_9 ( V_5 , 1 | ( ( V_701 & V_699 ) ? 0x02 : 0 ) ,
V_705 ) ;
F_66 ( 1 ) ;
}
F_9 ( V_5 , V_700 , V_705 ) ;
F_66 ( 1 ) ;
F_9 ( V_5 , 0 , V_705 ) ;
}
static int F_223 ( struct V_4 * V_5 ,
struct V_190 * V_191 ,
struct V_380 * V_381 ,
unsigned int * V_6 )
{
F_220 ( V_5 , F_123 ( V_381 -> V_384 ) , V_6 [ 0 ] ) ;
return 1 ;
}
static int F_224 ( struct V_4 * V_5 ,
struct V_190 * V_191 ,
struct V_380 * V_381 ,
unsigned int * V_6 )
{
struct V_124 * V_125 = V_5 -> V_126 ;
V_6 [ 0 ] = V_125 -> V_702 [ F_123 ( V_381 -> V_384 ) ] ;
return 1 ;
}
static void F_225 ( struct V_4 * V_5 , struct V_190 * V_191 )
{
const struct V_219 * V_220 = F_83 ( V_5 ) ;
struct V_124 * V_125 = V_5 -> V_126 ;
int V_180 , V_706 ;
int V_707 ;
int V_467 = 0 ;
int V_708 ;
int V_709 = 0 ;
int type ;
int V_205 ;
type = V_220 -> V_703 [ 0 ] ;
if ( type == V_704 )
return;
V_708 = V_702 [ type ] . V_708 ;
for ( V_180 = 0 ; V_180 < 3 ; V_180 ++ ) {
type = V_220 -> V_703 [ V_180 ] ;
if ( type == V_704 )
break;
if ( V_702 [ type ] . V_708 != V_708 )
V_709 = 1 ;
V_467 += V_702 [ type ] . V_467 ;
}
V_707 = V_180 ;
V_191 -> V_331 = V_467 ;
if ( V_709 ) {
unsigned int * V_710 ;
if ( V_467 > V_711 )
F_42 ( V_5 -> V_25 ,
L_31 ) ;
V_191 -> V_710 = V_710 = V_125 -> V_712 ;
V_205 = 0 ;
for ( V_180 = 0 ; V_180 < V_707 ; V_180 ++ ) {
type = V_220 -> V_703 [ V_180 ] ;
for ( V_706 = 0 ; V_706 < V_702 [ type ] . V_467 ; V_706 ++ ) {
V_710 [ V_205 ] =
( 1 << V_702 [ type ] . V_708 ) - 1 ;
V_205 ++ ;
}
}
for ( V_205 = 0 ; V_205 < V_191 -> V_331 ; V_205 ++ )
F_220 ( V_5 , V_180 , V_191 -> V_710 [ V_180 ] / 2 ) ;
} else {
type = V_220 -> V_703 [ 0 ] ;
V_191 -> V_363 = ( 1 << V_702 [ type ] . V_708 ) - 1 ;
for ( V_205 = 0 ; V_205 < V_191 -> V_331 ; V_205 ++ )
F_220 ( V_5 , V_180 , V_191 -> V_363 / 2 ) ;
}
}
static int F_226 ( struct V_4 * V_5 , int V_185 )
{
int V_701 ;
int V_699 ;
V_699 = 0x0300 | ( ( V_185 & 0x100 ) << 3 ) | ( V_185 & 0xff ) ;
F_9 ( V_5 , 0x04 , V_705 ) ;
for ( V_701 = 0x8000 ; V_701 ; V_701 >>= 1 ) {
F_9 ( V_5 , 0x04 | ( ( V_701 & V_699 ) ? 0x02 : 0 ) ,
V_705 ) ;
F_9 ( V_5 , 0x05 | ( ( V_701 & V_699 ) ? 0x02 : 0 ) ,
V_705 ) ;
}
V_699 = 0 ;
for ( V_701 = 0x80 ; V_701 ; V_701 >>= 1 ) {
F_9 ( V_5 , 0x04 , V_705 ) ;
F_9 ( V_5 , 0x05 , V_705 ) ;
V_699 |= ( ( F_18 ( V_5 , V_233 ) & V_713 ) ? V_701 : 0 ) ;
}
F_9 ( V_5 , 0x00 , V_705 ) ;
return V_699 ;
}
static int F_227 ( struct V_4 * V_5 ,
struct V_190 * V_191 ,
struct V_380 * V_381 ,
unsigned int * V_6 )
{
V_6 [ 0 ] = F_226 ( V_5 , F_123 ( V_381 -> V_384 ) ) ;
return 1 ;
}
static int F_228 ( struct V_4 * V_5 ,
struct V_190 * V_191 ,
struct V_380 * V_381 ,
unsigned int * V_6 )
{
struct V_124 * V_125 = V_5 -> V_126 ;
V_6 [ 0 ] = V_125 -> V_714 [ F_123 ( V_381 -> V_384 ) ] ;
return 1 ;
}
static unsigned F_229 ( struct V_4 * V_5 ,
unsigned V_205 )
{
switch ( V_205 ) {
case 0 :
return V_715 ;
case 1 :
return V_716 ;
case 2 :
return V_717 ;
case 3 :
return V_718 ;
case 4 :
return V_719 ;
case 5 :
return V_720 ;
case 6 :
return V_721 ;
case 7 :
return V_722 ;
case 8 :
return V_723 ;
case 9 :
return V_724 ;
default:
F_42 ( V_5 -> V_25 ,
L_32 , V_26 ) ;
break;
}
return 0 ;
}
static int F_230 ( struct V_4 * V_5 ,
unsigned V_205 , unsigned V_725 )
{
if ( V_725 != F_229 ( V_5 , V_205 ) )
return - V_419 ;
return 2 ;
}
static unsigned F_231 ( struct V_4 * V_5 ,
unsigned V_205 )
{
struct V_124 * V_125 = V_5 -> V_126 ;
const unsigned V_726 = V_205 / 3 ;
return F_232 ( V_205 ,
V_125 -> V_727 [ V_726 ] ) ;
}
static int F_233 ( struct V_4 * V_5 ,
unsigned V_205 , unsigned V_725 )
{
struct V_124 * V_125 = V_5 -> V_126 ;
unsigned V_728 ;
unsigned V_726 ;
if ( ( V_725 & 0x1f ) != V_725 )
return - V_419 ;
V_728 = 1 + V_205 / 3 ;
V_726 = V_728 - 1 ;
V_125 -> V_727 [ V_726 ] &=
~ F_234 ( V_205 ) ;
V_125 -> V_727 [ V_726 ] |=
F_235 ( V_205 , V_725 ) ;
F_6 ( V_5 , V_125 -> V_727 [ V_726 ] ,
F_236 ( V_728 ) ) ;
return 2 ;
}
static unsigned F_237 ( struct V_4 * V_5 , unsigned V_205 )
{
struct V_124 * V_125 = V_5 -> V_126 ;
return ( V_125 -> V_128 )
? F_231 ( V_5 , V_205 )
: F_229 ( V_5 , V_205 ) ;
}
static int F_238 ( struct V_4 * V_5 , unsigned V_205 ,
unsigned V_725 )
{
struct V_124 * V_125 = V_5 -> V_126 ;
return ( V_125 -> V_128 )
? F_233 ( V_5 , V_205 , V_725 )
: F_230 ( V_5 , V_205 , V_725 ) ;
}
static int F_239 ( struct V_4 * V_5 ,
unsigned V_729 ,
enum V_730 V_731 )
{
struct V_124 * V_125 = V_5 -> V_126 ;
unsigned V_188 ;
if ( ! V_125 -> V_128 )
return - V_732 ;
V_188 = F_12 ( V_5 , V_733 ) ;
V_188 &= ~ F_240 ( V_729 ) ;
V_188 |= F_241 ( V_729 , V_731 ) ;
F_3 ( V_5 , V_188 , V_733 ) ;
return 0 ;
}
static int F_242 ( struct V_4 * V_5 ,
struct V_190 * V_191 ,
struct V_380 * V_381 ,
unsigned int * V_6 )
{
struct V_124 * V_125 = V_5 -> V_126 ;
unsigned int V_205 ;
if ( V_381 -> V_200 < 1 )
return - V_419 ;
V_205 = F_123 ( V_381 -> V_384 ) ;
switch ( V_6 [ 0 ] ) {
case V_164 :
F_71 ( V_5 , V_96 , 1 << V_205 , 1 ) ;
break;
case V_161 :
F_71 ( V_5 , V_96 , 1 << V_205 , 0 ) ;
break;
case V_734 :
V_6 [ 1 ] =
( V_125 -> V_139 & ( 1 << V_205 ) ) ?
V_164 : V_161 ;
return 0 ;
case V_735 :
return F_238 ( V_5 , V_205 , V_6 [ 1 ] ) ;
case V_736 :
V_6 [ 1 ] = F_237 ( V_5 , V_205 ) ;
break;
case V_737 :
return F_239 ( V_5 , V_205 , V_6 [ 1 ] ) ;
default:
return - V_419 ;
}
return 0 ;
}
static int F_243 ( struct V_4 * V_5 ,
struct V_190 * V_191 ,
struct V_380 * V_381 ,
unsigned int * V_6 )
{
struct V_124 * V_125 = V_5 -> V_126 ;
if ( ! V_125 -> V_128 )
return - V_732 ;
if ( F_182 ( V_191 , V_6 ) )
F_6 ( V_5 , V_191 -> V_558 , V_738 ) ;
V_6 [ 1 ] = F_15 ( V_5 , V_739 ) ;
return V_381 -> V_200 ;
}
static int F_244 ( struct V_4 * V_5 )
{
unsigned short V_251 ;
const int V_179 = V_740 ;
int V_180 ;
for ( V_180 = 0 ; V_180 < V_179 ; V_180 ++ ) {
V_251 = F_70 ( V_5 , V_741 ) ;
if ( ( V_251 & V_742 ) == 0 )
break;
F_245 ( V_743 ) ;
if ( F_246 ( 1 ) )
return - V_299 ;
}
if ( V_180 == V_179 ) {
F_42 ( V_5 -> V_25 , L_20 , V_26 ) ;
return - V_386 ;
}
return 0 ;
}
static void F_247 ( struct V_4 * V_5 , unsigned short V_189 )
{
static const int V_179 = 100 ;
int V_180 ;
F_68 ( V_5 , V_189 , V_744 ) ;
for ( V_180 = 0 ; V_180 < V_179 ; V_180 ++ ) {
if ( ( F_70 ( V_5 , V_741 ) & V_742 ) )
break;
F_66 ( 1 ) ;
}
if ( V_180 == V_179 )
F_42 ( V_5 -> V_25 ,
L_33 ) ;
}
static int F_248 ( struct V_4 * V_5 ,
unsigned short * V_6 )
{
int V_193 ;
unsigned short V_251 ;
F_247 ( V_5 , V_745 | V_746 ) ;
V_193 = F_244 ( V_5 ) ;
if ( V_193 ) {
F_42 ( V_5 -> V_25 ,
L_34 ) ;
return - V_386 ;
}
V_251 = F_70 ( V_5 , V_741 ) ;
if ( V_251 & V_747 ) {
F_42 ( V_5 -> V_25 ,
L_35 ) ;
return - V_299 ;
}
if ( V_251 & V_748 ) {
F_42 ( V_5 -> V_25 ,
L_36 ) ;
}
if ( V_6 ) {
* V_6 = F_70 ( V_5 , V_749 ) ;
* V_6 ^= ( 1 << 15 ) ;
}
return 0 ;
}
static int F_249 ( struct V_4 * V_5 ,
struct V_190 * V_191 ,
struct V_380 * V_381 ,
unsigned int * V_6 )
{
int V_200 , V_193 ;
unsigned short V_750 ;
unsigned int V_751 ;
const unsigned int V_752 = 0x1000 ;
if ( V_381 -> V_384 & V_336 )
V_751 = V_752 ;
else
V_751 = F_123 ( V_381 -> V_384 ) ;
F_68 ( V_5 , V_751 , V_753 ) ;
for ( V_200 = 0 ; V_200 < V_381 -> V_200 ; V_200 ++ ) {
V_193 = F_248 ( V_5 , & V_750 ) ;
if ( V_193 < 0 )
return V_193 ;
V_6 [ V_200 ] = V_750 ;
}
return V_381 -> V_200 ;
}
static void F_250 ( struct V_4 * V_5 , unsigned int V_189 ,
unsigned int V_754 )
{
F_68 ( V_5 , ( ( V_189 >> 16 ) & 0xff ) ,
V_755 ) ;
F_68 ( V_5 , ( V_189 & 0xffff ) ,
V_756 ) ;
V_754 &= V_757 ;
F_247 ( V_5 , V_745 | V_754 ) ;
if ( F_244 ( V_5 ) )
F_42 ( V_5 -> V_25 ,
L_37 , V_26 ) ;
}
static int F_251 ( struct V_4 * V_5 )
{
unsigned int V_350 =
V_758 | V_759 ;
#if 1
F_250 ( V_5 , V_350 | V_760 ,
V_761 ) ;
F_248 ( V_5 , NULL ) ;
#else
F_250 ( V_5 , 0x400000 , V_762 ) ;
F_250 ( V_5 , V_350 | V_763 ,
V_761 ) ;
if ( F_244 ( V_5 ) )
F_42 ( V_5 -> V_25 ,
L_37 , V_26 ) ;
#endif
return 0 ;
}
static int F_252 ( unsigned V_764 ,
unsigned * V_765 ,
unsigned * V_766 ,
unsigned * V_767 )
{
unsigned div ;
unsigned V_768 = 1 ;
static const unsigned V_769 = 0x10 ;
unsigned V_770 ;
unsigned V_771 = 1 ;
static const unsigned V_772 = 0x100 ;
static const unsigned V_773 = 1000 ;
const unsigned V_774 = V_764 * V_773 ;
static const unsigned V_775 = 12500 ;
static const unsigned V_776 = 4 ;
int V_777 = 0 ;
for ( div = 1 ; div <= V_769 ; ++ div ) {
for ( V_770 = 1 ; V_770 <= V_772 ; ++ V_770 ) {
unsigned V_778 =
( V_774 * div ) / V_770 ;
if ( abs ( V_778 - V_775 ) <
abs ( V_777 - V_775 ) ) {
V_777 = V_778 ;
V_768 = div ;
V_771 = V_770 ;
}
}
}
if ( V_777 == 0 )
return - V_299 ;
* V_765 = V_768 ;
* V_766 = V_771 ;
* V_767 =
( V_777 * V_776 +
( V_773 / 2 ) ) / V_773 ;
return 0 ;
}
static int F_253 ( struct V_4 * V_5 ,
unsigned V_725 , unsigned V_779 )
{
struct V_124 * V_125 = V_5 -> V_126 ;
static const unsigned V_780 = 50 ;
static const unsigned V_781 = 1000 ;
static const unsigned V_179 = 1000 ;
unsigned V_782 ;
unsigned V_765 ;
unsigned V_766 ;
unsigned V_180 ;
int V_193 ;
if ( V_725 == V_783 )
V_779 = 100 ;
if ( V_779 < V_780 || V_779 > V_781 ) {
F_42 ( V_5 -> V_25 ,
L_38 ,
V_26 , V_780 , V_781 ) ;
return - V_419 ;
}
V_125 -> V_784 &= ~ V_785 ;
F_35 ( V_5 , V_125 -> V_784 ,
V_104 ) ;
V_782 =
V_786 | V_787 ;
V_125 -> V_788 |=
V_789 | V_790 ;
V_125 -> V_788 &= ~ V_791 ;
switch ( V_725 ) {
case V_792 :
V_125 -> V_788 |=
V_793 ;
break;
case V_783 :
V_125 -> V_788 |=
V_794 ;
break;
default:
{
unsigned V_795 ;
static const unsigned V_796 = 7 ;
for ( V_795 = 0 ; V_795 <= V_796 ;
++ V_795 ) {
if ( V_725 ==
F_254 ( V_795 ) ) {
V_125 -> V_788 |=
F_255
( V_795 ) ;
break;
}
}
if ( V_795 > V_796 )
return - V_419 ;
}
break;
}
V_193 = F_252 ( V_779 ,
& V_765 ,
& V_766 ,
& V_125 -> V_392 ) ;
if ( V_193 < 0 ) {
F_42 ( V_5 -> V_25 ,
L_39 , V_26 ) ;
return V_193 ;
}
F_6 ( V_5 , V_125 -> V_788 , V_797 ) ;
V_782 |=
F_256 ( V_765 ) |
F_257 ( V_766 ) ;
F_6 ( V_5 , V_782 , V_798 ) ;
V_125 -> V_799 = V_725 ;
for ( V_180 = 0 ; V_180 < V_179 ; ++ V_180 ) {
if ( F_15 ( V_5 , V_800 ) & V_801 )
break;
F_66 ( 1 ) ;
}
if ( V_180 == V_179 ) {
F_42 ( V_5 -> V_25 ,
L_40 ,
V_26 , V_725 , V_779 ) ;
return - V_802 ;
}
return 3 ;
}
static int F_258 ( struct V_4 * V_5 ,
unsigned V_725 , unsigned V_779 )
{
struct V_124 * V_125 = V_5 -> V_126 ;
if ( V_725 == V_803 ) {
V_125 -> V_784 &= ~ V_785 ;
F_35 ( V_5 , V_125 -> V_784 ,
V_104 ) ;
V_125 -> V_392 = V_685 ;
if ( V_125 -> V_128 ) {
V_125 -> V_788 &=
~ ( V_789 |
V_790 ) ;
F_6 ( V_5 , V_125 -> V_788 ,
V_797 ) ;
F_6 ( V_5 , 0 , V_798 ) ;
}
V_125 -> V_799 = V_725 ;
} else {
if ( V_125 -> V_128 ) {
return F_253 ( V_5 , V_725 ,
V_779 ) ;
} else {
if ( V_725 == V_804 ) {
V_125 -> V_784 |=
V_785 ;
F_35 ( V_5 ,
V_125 -> V_784 ,
V_104 ) ;
if ( V_779 == 0 ) {
F_42 ( V_5 -> V_25 ,
L_41 ,
V_26 ) ;
return - V_419 ;
}
V_125 -> V_392 = V_779 ;
V_125 -> V_799 = V_725 ;
} else
return - V_419 ;
}
}
return 3 ;
}
static unsigned F_259 ( struct V_4 * V_5 )
{
struct V_124 * V_125 = V_5 -> V_126 ;
return ( V_125 -> V_128 ) ? 8 : 7 ;
}
static int F_260 ( struct V_4 * V_5 ,
unsigned V_205 , unsigned V_725 )
{
struct V_124 * V_125 = V_5 -> V_126 ;
if ( V_205 >= F_259 ( V_5 ) ) {
if ( V_205 == V_805 ) {
if ( V_725 == V_806 )
return 1 ;
F_42 ( V_5 -> V_25 ,
L_42 ,
V_26 , V_205 , V_805 ) ;
return 0 ;
}
return 0 ;
}
switch ( V_725 ) {
case V_807 :
case V_808 :
case V_809 :
case V_810 :
case V_811 :
case V_812 :
case V_813 :
case V_814 :
case V_815 :
return 1 ;
case V_806 :
return ( V_125 -> V_128 ) ? 1 : 0 ;
default:
return 0 ;
}
}
static int F_261 ( struct V_4 * V_5 ,
unsigned V_205 , unsigned V_725 )
{
struct V_124 * V_125 = V_5 -> V_126 ;
if ( F_260 ( V_5 , V_205 , V_725 ) == 0 )
return - V_419 ;
if ( V_205 < 4 ) {
V_125 -> V_816 &= ~ F_262 ( V_205 ) ;
V_125 -> V_816 |=
F_263 ( V_205 , V_725 ) ;
F_35 ( V_5 , V_125 -> V_816 ,
V_100 ) ;
} else if ( V_205 < 8 ) {
V_125 -> V_817 &= ~ F_262 ( V_205 ) ;
V_125 -> V_817 |=
F_263 ( V_205 , V_725 ) ;
F_35 ( V_5 , V_125 -> V_817 ,
V_102 ) ;
}
return 2 ;
}
static unsigned F_264 ( struct V_4 * V_5 , unsigned V_205 )
{
struct V_124 * V_125 = V_5 -> V_126 ;
if ( V_205 < 4 ) {
return F_265 ( V_205 ,
V_125 -> V_816 ) ;
} else if ( V_205 < F_259 ( V_5 ) ) {
return F_265 ( V_205 ,
V_125 -> V_817 ) ;
} else {
if ( V_205 == V_805 )
return V_806 ;
F_42 ( V_5 -> V_25 , L_43 ,
V_26 ) ;
return 0 ;
}
}
static int F_266 ( struct V_4 * V_5 ,
struct V_190 * V_191 ,
struct V_380 * V_381 ,
unsigned int * V_6 )
{
struct V_124 * V_125 = V_5 -> V_126 ;
unsigned int V_205 = F_123 ( V_381 -> V_384 ) ;
switch ( V_6 [ 0 ] ) {
case V_818 :
if ( V_205 < F_259 ( V_5 ) ) {
V_125 -> V_784 |=
F_267 ( V_205 , V_125 -> V_128 ) ;
} else if ( V_205 == V_805 ) {
V_125 -> V_784 |=
V_819 ;
}
F_35 ( V_5 , V_125 -> V_784 ,
V_104 ) ;
break;
case V_820 :
if ( V_205 < F_259 ( V_5 ) ) {
V_125 -> V_784 &=
~ F_267 ( V_205 , V_125 -> V_128 ) ;
} else if ( V_205 == V_805 ) {
V_125 -> V_784 &=
~ V_819 ;
}
F_35 ( V_5 , V_125 -> V_784 ,
V_104 ) ;
break;
case V_734 :
if ( V_205 < F_259 ( V_5 ) ) {
V_6 [ 1 ] =
( V_125 -> V_784 &
F_267 ( V_205 , V_125 -> V_128 ) )
? V_818
: V_820 ;
} else if ( V_205 == V_805 ) {
V_6 [ 1 ] =
( V_125 -> V_784 &
V_819 )
? V_818 : V_820 ;
}
return 2 ;
case V_679 :
return F_258 ( V_5 , V_6 [ 1 ] , V_6 [ 2 ] ) ;
case V_683 :
V_6 [ 1 ] = V_125 -> V_799 ;
V_6 [ 2 ] = V_125 -> V_392 ;
return 3 ;
case V_735 :
return F_261 ( V_5 , V_205 , V_6 [ 1 ] ) ;
case V_736 :
V_6 [ 1 ] = F_264 ( V_5 , V_205 ) ;
return 2 ;
default:
return - V_419 ;
}
return 1 ;
}
static int F_268 ( struct V_4 * V_5 ,
struct V_190 * V_191 ,
struct V_380 * V_381 ,
unsigned int * V_6 )
{
V_6 [ 1 ] = 0 ;
return V_381 -> V_200 ;
}
static void F_269 ( struct V_4 * V_5 )
{
struct V_124 * V_125 = V_5 -> V_126 ;
V_125 -> V_788 = V_821 ;
if ( F_258 ( V_5 , V_803 , 0 ) < 0 )
F_42 ( V_5 -> V_25 , L_44 ) ;
V_125 -> V_816 =
F_263 ( 0 ,
V_807 ) |
F_263 ( 1 ,
V_808 ) |
F_263 ( 2 ,
V_809 ) |
F_263 ( 3 , V_810 ) ;
F_35 ( V_5 , V_125 -> V_816 ,
V_100 ) ;
V_125 -> V_817 =
F_263 ( 4 ,
V_811 ) |
F_263 ( 5 ,
V_812 ) |
F_263 ( 6 , V_813 ) ;
if ( V_125 -> V_128 )
V_125 -> V_817 |=
F_263 ( 7 , V_806 ) ;
F_35 ( V_5 , V_125 -> V_817 ,
V_102 ) ;
}
static int F_270 ( struct V_4 * V_5 , struct V_190 * V_191 )
{
struct V_646 * V_647 = V_191 -> V_126 ;
int V_193 ;
V_193 = F_55 ( V_5 , V_647 -> V_1 ,
V_161 ) ;
if ( V_193 ) {
F_42 ( V_5 -> V_25 ,
L_45 ) ;
return V_193 ;
}
F_271 ( V_647 ) ;
F_64 ( V_5 , V_647 -> V_1 , 1 ) ;
return F_272 ( V_5 , V_191 ) ;
}
static int F_273 ( struct V_4 * V_5 , struct V_190 * V_191 )
{
struct V_646 * V_647 = V_191 -> V_126 ;
int V_193 ;
V_193 = F_274 ( V_647 ) ;
F_64 ( V_5 , V_647 -> V_1 , 0 ) ;
F_62 ( V_5 , V_647 -> V_1 ) ;
return V_193 ;
}
static T_5 F_275 ( int V_427 , void * V_206 )
{
struct V_4 * V_5 = V_206 ;
unsigned short V_241 ;
unsigned short V_197 ;
unsigned int V_252 = 0 ;
unsigned int V_285 = 0 ;
unsigned long V_127 ;
#ifdef F_58
struct V_124 * V_125 = V_5 -> V_126 ;
struct V_195 * V_130 = V_125 -> V_130 ;
#endif
if ( ! V_5 -> V_822 )
return V_823 ;
F_276 () ;
F_36 ( & V_5 -> V_328 , V_127 ) ;
V_241 = F_39 ( V_5 , V_110 ) ;
V_197 = F_39 ( V_5 , V_112 ) ;
#ifdef F_58
if ( V_130 ) {
struct V_124 * V_125 = V_5 -> V_126 ;
unsigned long V_824 ;
F_36 ( & V_125 -> V_156 , V_824 ) ;
if ( V_125 -> V_157 ) {
V_252 = F_193 ( V_125 -> V_157 ) ;
if ( V_252 & V_254 )
F_4 ( V_588 ,
V_125 -> V_130 -> V_589 +
F_194 ( V_125 ->
V_157 -> V_144 ) ) ;
}
if ( V_125 -> V_162 ) {
V_285 = F_193 ( V_125 -> V_162 ) ;
if ( V_285 & V_254 )
F_4 ( V_588 ,
V_130 -> V_589 +
F_194 ( V_125 ->
V_162 -> V_144 ) ) ;
}
F_37 ( & V_125 -> V_156 , V_824 ) ;
}
#endif
F_98 ( V_5 , V_241 ) ;
F_101 ( V_5 , V_197 ) ;
if ( ( V_241 & V_825 ) || ( V_252 & V_255 ) )
F_99 ( V_5 , V_241 , V_252 ) ;
if ( ( V_197 & V_826 ) || ( V_285 & V_255 ) )
F_102 ( V_5 , V_197 , V_285 ) ;
F_95 ( V_5 , 0 ) ;
F_95 ( V_5 , 1 ) ;
F_192 ( V_5 ) ;
F_37 ( & V_5 -> V_328 , V_127 ) ;
return V_827 ;
}
static int F_277 ( struct V_4 * V_5 )
{
struct V_124 * V_125 ;
V_125 = F_278 ( V_5 , sizeof( * V_125 ) ) ;
if ( ! V_125 )
return - V_828 ;
F_279 ( & V_125 -> V_129 ) ;
F_279 ( & V_125 -> V_136 ) ;
F_279 ( & V_125 -> V_156 ) ;
return 0 ;
}
static int F_280 ( struct V_4 * V_5 ,
unsigned V_829 , unsigned V_830 )
{
const struct V_219 * V_220 = F_83 ( V_5 ) ;
struct V_124 * V_125 = V_5 -> V_126 ;
struct V_190 * V_191 ;
int V_287 ;
int V_180 ;
if ( V_220 -> V_831 > V_832 ) {
F_42 ( V_5 -> V_25 , L_46 ) ;
return - V_419 ;
}
V_125 -> V_610 = V_833 |
V_611 |
V_834 |
V_835 ;
if ( ! V_125 -> V_212 ) {
V_125 -> V_610 |= ( V_836 |
V_837 ) ;
}
F_35 ( V_5 , V_125 -> V_610 , V_71 ) ;
V_287 = F_281 ( V_5 , V_838 ) ;
if ( V_287 )
return V_287 ;
V_191 = & V_5 -> V_240 [ V_839 ] ;
if ( V_220 -> V_840 ) {
V_191 -> type = V_841 ;
V_191 -> V_295 = V_842 | V_843 | V_844 ;
if ( ! V_125 -> V_224 )
V_191 -> V_295 |= V_845 | V_846 | V_847 ;
if ( V_220 -> V_848 > 0xffff )
V_191 -> V_295 |= V_296 ;
if ( V_125 -> V_128 )
V_191 -> V_295 |= V_849 ;
V_191 -> V_331 = V_220 -> V_840 ;
V_191 -> V_363 = V_220 -> V_848 ;
V_191 -> V_475 = V_850 [ V_220 -> V_339 ] ;
V_191 -> V_851 = F_132 ;
V_191 -> V_852 = F_150 ;
if ( V_5 -> V_427 ) {
V_5 -> V_192 = V_191 ;
V_191 -> V_295 |= V_853 ;
V_191 -> V_854 = 512 ;
V_191 -> V_855 = F_136 ;
V_191 -> V_856 = F_143 ;
V_191 -> V_567 = F_113 ;
V_191 -> V_857 = F_119 ;
V_191 -> V_858 = F_103 ;
if ( V_125 -> V_130 )
V_191 -> V_859 = V_860 ;
}
F_113 ( V_5 , V_191 ) ;
} else {
V_191 -> type = V_253 ;
}
V_191 = & V_5 -> V_240 [ V_861 ] ;
if ( V_220 -> V_831 ) {
V_191 -> type = V_862 ;
V_191 -> V_295 = V_863 | V_864 | V_845 ;
if ( V_125 -> V_128 )
V_191 -> V_295 |= V_849 ;
V_191 -> V_331 = V_220 -> V_831 ;
V_191 -> V_363 = V_220 -> V_865 ;
V_191 -> V_475 = V_220 -> V_866 ;
V_191 -> V_851 = F_163 ;
V_191 -> V_867 = F_164 ;
V_191 -> V_852 = F_167 ;
if ( V_5 -> V_427 && ( V_220 -> V_221 || V_125 -> V_130 ) ) {
V_5 -> V_196 = V_191 ;
V_191 -> V_295 |= V_868 ;
V_191 -> V_854 = V_191 -> V_331 ;
V_191 -> V_855 = F_176 ;
V_191 -> V_856 = F_169 ;
V_191 -> V_567 = F_177 ;
if ( ! V_125 -> V_128 )
V_191 -> V_858 = F_151 ;
if ( V_125 -> V_130 )
V_191 -> V_859 = V_869 ;
}
if ( V_125 -> V_870 )
F_199 ( V_5 , V_191 ) ;
F_177 ( V_5 , V_191 ) ;
} else {
V_191 -> type = V_253 ;
}
V_191 = & V_5 -> V_240 [ V_586 ] ;
V_191 -> type = V_871 ;
V_191 -> V_295 = V_863 | V_842 ;
V_191 -> V_331 = V_220 -> V_872 ? 32 : 8 ;
V_191 -> V_363 = 1 ;
V_191 -> V_475 = & V_873 ;
if ( V_125 -> V_128 ) {
V_191 -> V_295 |= V_296 ;
V_191 -> V_874 = F_185 ;
V_191 -> V_852 = F_184 ;
if ( V_5 -> V_427 ) {
V_191 -> V_295 |= V_868 ;
V_191 -> V_854 = V_191 -> V_331 ;
V_191 -> V_855 = F_187 ;
V_191 -> V_856 = F_190 ;
V_191 -> V_567 = F_191 ;
V_191 -> V_859 = V_875 ;
}
F_3 ( V_5 , V_575 | V_876 ,
V_571 ) ;
F_3 ( V_5 , V_191 -> V_552 , V_561 ) ;
} else {
V_191 -> V_874 = F_181 ;
V_191 -> V_852 = F_178 ;
V_125 -> V_550 = F_180 ( V_191 -> V_552 ) ;
F_6 ( V_5 , V_125 -> V_550 , V_77 ) ;
}
V_191 = & V_5 -> V_240 [ V_877 ] ;
if ( V_220 -> V_878 ) {
V_287 = F_282 ( V_5 , V_191 , F_208 ,
( unsigned long ) V_5 ) ;
if ( V_287 )
return V_287 ;
} else {
V_191 -> type = V_253 ;
}
V_191 = & V_5 -> V_240 [ V_879 ] ;
V_191 -> type = V_253 ;
V_191 = & V_5 -> V_240 [ V_880 ] ;
V_191 -> type = V_881 ;
V_191 -> V_295 = V_882 ;
V_191 -> V_331 = 1 ;
V_191 -> V_363 = 0 ;
if ( V_125 -> V_128 ) {
V_191 -> V_852 = F_210 ;
F_3 ( V_5 , 0x0 , V_695 ) ;
} else if ( V_125 -> V_181 ) {
V_191 -> V_852 = F_213 ;
} else {
V_191 -> V_295 |= V_863 ;
V_191 -> V_851 = F_224 ;
V_191 -> V_867 = F_223 ;
F_225 ( V_5 , V_191 ) ;
}
V_191 = & V_5 -> V_240 [ V_883 ] ;
V_191 -> type = V_884 ;
V_191 -> V_295 = V_842 | V_882 ;
V_191 -> V_363 = 0xff ;
if ( V_125 -> V_128 ) {
V_191 -> V_331 = V_885 ;
V_191 -> V_851 = F_228 ;
} else {
V_191 -> V_331 = 512 ;
V_191 -> V_851 = F_227 ;
}
V_191 = & V_5 -> V_240 [ V_886 ] ;
V_191 -> type = V_871 ;
V_191 -> V_295 = V_842 | V_863 | V_882 ;
V_191 -> V_363 = 1 ;
if ( V_125 -> V_128 ) {
V_191 -> V_331 = 16 ;
V_191 -> V_874 = F_243 ;
F_6 ( V_5 , V_191 -> V_558 , V_738 ) ;
for ( V_180 = 0 ; V_180 < V_887 ; ++ V_180 ) {
F_6 ( V_5 , V_125 -> V_727 [ V_180 ] ,
F_236 ( V_180 + 1 ) ) ;
}
} else {
V_191 -> V_331 = 10 ;
}
V_191 -> V_852 = F_242 ;
F_71 ( V_5 , V_96 , ~ 0 , 0 ) ;
V_191 = & V_5 -> V_240 [ V_888 ] ;
if ( V_125 -> V_870 ) {
V_191 -> type = V_841 ;
V_191 -> V_295 = V_842 | V_843 | V_882 ;
V_191 -> V_331 = V_220 -> V_831 ;
V_191 -> V_363 = ( 1 << 16 ) - 1 ;
V_191 -> V_475 = & V_889 ;
V_191 -> V_851 = F_249 ;
V_191 -> V_852 = NULL ;
F_251 ( V_5 ) ;
} else {
V_191 -> type = V_253 ;
}
V_191 = & V_5 -> V_240 [ V_890 ] ;
V_191 -> type = V_891 ;
V_191 -> V_295 = V_842 | V_863 | V_882 ;
V_191 -> V_331 = 1 ;
V_191 -> V_363 = 0xff ;
V_191 -> V_852 = F_198 ;
V_125 -> V_555 = 0 ;
V_125 -> V_605 = 0 ;
V_191 = & V_5 -> V_240 [ V_892 ] ;
V_191 -> type = V_871 ;
V_191 -> V_295 = V_842 | V_863 | V_882 ;
V_191 -> V_331 = 8 ;
V_191 -> V_363 = 1 ;
V_191 -> V_874 = F_268 ;
V_191 -> V_852 = F_266 ;
F_269 ( V_5 ) ;
V_125 -> V_169 = F_283 ( V_5 ,
F_202 ,
F_203 ,
( V_125 -> V_128 )
? V_893
: V_894 ,
V_168 ) ;
if ( ! V_125 -> V_169 )
return - V_828 ;
for ( V_180 = 0 ; V_180 < V_168 ; ++ V_180 ) {
struct V_646 * V_895 = & V_125 -> V_169 -> V_170 [ V_180 ] ;
V_895 -> V_896 = 0 ;
V_895 -> V_1 = V_180 ;
F_284 ( V_895 ) ;
V_191 = & V_5 -> V_240 [ F_1 ( V_180 ) ] ;
V_191 -> type = V_897 ;
V_191 -> V_295 = V_842 | V_863 | V_296 ;
V_191 -> V_331 = 3 ;
V_191 -> V_363 = ( V_125 -> V_128 ) ? 0xffffffff
: 0x00ffffff ;
V_191 -> V_851 = V_898 ;
V_191 -> V_867 = V_898 ;
V_191 -> V_852 = V_899 ;
#ifdef F_58
if ( V_5 -> V_427 && V_125 -> V_130 ) {
V_191 -> V_295 |= V_853 ;
V_191 -> V_854 = 1 ;
V_191 -> V_855 = V_900 ;
V_191 -> V_856 = F_270 ;
V_191 -> V_567 = F_273 ;
V_191 -> V_859 = V_875 ;
}
#endif
V_191 -> V_126 = V_895 ;
}
V_191 = & V_5 -> V_240 [ V_901 ] ;
V_191 -> type = V_897 ;
V_191 -> V_295 = V_842 | V_863 ;
V_191 -> V_331 = 1 ;
V_191 -> V_363 = 0xf ;
V_191 -> V_851 = F_204 ;
V_191 -> V_867 = F_205 ;
V_191 -> V_852 = F_207 ;
if ( V_5 -> V_427 ) {
F_35 ( V_5 ,
( V_830 ? V_902 : 0 ) |
( V_903 & 0 ) |
V_904 | V_905 |
F_285 ( V_829 ) |
F_286 ( V_829 ) ,
V_94 ) ;
}
F_9 ( V_5 , V_125 -> V_141 , V_140 ) ;
F_9 ( V_5 , V_125 -> V_143 , V_142 ) ;
if ( V_125 -> V_212 ) {
F_9 ( V_5 , 0 , V_906 ) ;
} else if ( V_125 -> V_128 ) {
int V_144 ;
for ( V_144 = 0 ; V_144 < V_220 -> V_831 ; ++ V_144 ) {
F_9 ( V_5 , 0xf ,
F_157 ( V_144 ) ) ;
F_9 ( V_5 , 0x0 ,
F_158 ( V_144 ) ) ;
}
F_9 ( V_5 , 0x0 , V_907 ) ;
}
return 0 ;
}
static void F_287 ( struct V_4 * V_5 )
{
struct V_124 * V_125 = V_5 -> V_126 ;
if ( V_125 ) {
if ( V_125 -> V_169 )
F_288 ( V_125 -> V_169 ) ;
}
}
