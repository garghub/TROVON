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
const struct V_219 * V_220 = V_5 -> V_221 ;
int V_200 ;
V_200 = F_83 ( V_191 ) ;
if ( V_200 == 0 ) {
V_191 -> V_202 -> V_217 |= V_218 ;
return 0 ;
}
V_200 /= sizeof( short ) ;
if ( V_200 > V_220 -> V_222 / 2 )
V_200 = V_220 -> V_222 / 2 ;
F_79 ( V_5 , V_191 , V_200 ) ;
V_191 -> V_202 -> V_217 |= V_223 ;
return 1 ;
}
static int F_84 ( struct V_4 * V_5 ,
struct V_190 * V_191 )
{
const struct V_219 * V_220 = V_5 -> V_221 ;
struct V_124 * V_125 = V_5 -> V_126 ;
int V_200 ;
F_35 ( V_5 , 1 , V_75 ) ;
if ( V_125 -> V_212 )
F_69 ( V_5 , 0x6 , V_224 ) ;
V_200 = F_83 ( V_191 ) ;
if ( V_200 == 0 )
return 0 ;
V_200 /= sizeof( short ) ;
if ( V_200 > V_220 -> V_222 )
V_200 = V_220 -> V_222 ;
F_79 ( V_5 , V_191 , V_200 ) ;
return V_200 ;
}
static void F_85 ( struct V_4 * V_5 ,
struct V_190 * V_191 , int V_200 )
{
struct V_124 * V_125 = V_5 -> V_126 ;
struct V_201 * V_202 = V_191 -> V_202 ;
int V_180 ;
if ( V_125 -> V_225 ) {
unsigned short V_6 [ 2 ] ;
T_4 V_226 ;
for ( V_180 = 0 ; V_180 < V_200 / 2 ; V_180 ++ ) {
V_226 = F_12 ( V_5 , V_227 ) ;
V_6 [ 0 ] = ( V_226 >> 16 ) & 0xffff ;
V_6 [ 1 ] = V_226 & 0xffff ;
F_86 ( V_191 , V_6 , sizeof( V_6 ) ) ;
}
if ( V_200 % 2 ) {
V_226 = F_12 ( V_5 , V_227 ) ;
V_6 [ 0 ] = V_226 & 0xffff ;
F_87 ( V_191 , V_6 [ 0 ] ) ;
}
} else if ( V_125 -> V_181 ) {
unsigned short V_6 [ 2 ] ;
T_4 V_226 ;
for ( V_180 = 0 ; V_180 < V_200 / 2 ; V_180 ++ ) {
V_226 = F_12 ( V_5 , V_228 ) ;
V_6 [ 0 ] = ( V_226 >> 16 ) & 0xffff ;
V_6 [ 1 ] = V_226 & 0xffff ;
F_86 ( V_191 , V_6 , sizeof( V_6 ) ) ;
}
if ( V_200 % 2 ) {
F_3 ( V_5 , 0x01 , V_182 ) ;
V_226 = F_12 ( V_5 , V_228 ) ;
V_6 [ 0 ] = ( V_226 >> 16 ) & 0xffff ;
F_87 ( V_191 , V_6 [ 0 ] ) ;
}
} else {
if ( V_200 > sizeof( V_125 -> V_229 ) /
sizeof( V_125 -> V_229 [ 0 ] ) ) {
F_42 ( V_5 -> V_25 ,
L_12 ) ;
V_202 -> V_217 |= V_230 ;
return;
}
for ( V_180 = 0 ; V_180 < V_200 ; V_180 ++ ) {
V_125 -> V_229 [ V_180 ] =
F_15 ( V_5 , V_231 ) ;
}
F_86 ( V_191 , V_125 -> V_229 ,
V_200 *
sizeof( V_125 -> V_229 [ 0 ] ) ) ;
}
}
static void F_88 ( struct V_4 * V_5 )
{
const struct V_219 * V_220 = V_5 -> V_221 ;
struct V_190 * V_191 = V_5 -> V_192 ;
int V_200 ;
V_200 = V_220 -> V_232 / 2 ;
F_85 ( V_5 , V_191 , V_200 ) ;
}
static void F_89 ( struct V_4 * V_5 )
{
struct V_124 * V_125 = V_5 -> V_126 ;
struct V_190 * V_191 = V_5 -> V_192 ;
unsigned short V_6 [ 2 ] ;
T_4 V_226 ;
unsigned short V_233 ;
int V_180 ;
if ( V_125 -> V_225 ) {
while ( ( F_39 ( V_5 , V_110 ) &
V_194 ) == 0 ) {
V_226 = F_12 ( V_5 , V_227 ) ;
V_6 [ 0 ] = ( V_226 >> 16 ) ;
V_6 [ 1 ] = ( V_226 & 0xffff ) ;
F_86 ( V_191 , V_6 , sizeof( V_6 ) ) ;
}
} else if ( V_125 -> V_181 ) {
V_180 = 0 ;
while ( F_12 ( V_5 , V_183 ) & 0x04 ) {
V_226 = F_12 ( V_5 , V_228 ) ;
V_6 [ 0 ] = ( V_226 >> 16 ) ;
V_6 [ 1 ] = ( V_226 & 0xffff ) ;
F_86 ( V_191 , V_6 , sizeof( V_6 ) ) ;
V_180 += 2 ;
}
if ( F_12 ( V_5 , V_183 ) & 0x01 ) {
F_3 ( V_5 , 0x01 , V_182 ) ;
V_226 = F_12 ( V_5 , V_228 ) ;
V_6 [ 0 ] = ( V_226 >> 16 ) & 0xffff ;
F_87 ( V_191 , V_6 [ 0 ] ) ;
}
} else {
V_233 = F_39 ( V_5 , V_110 ) &
V_194 ;
while ( V_233 == 0 ) {
for ( V_180 = 0 ;
V_180 <
sizeof( V_125 -> V_229 ) /
sizeof( V_125 -> V_229 [ 0 ] ) ; V_180 ++ ) {
V_233 = F_39 ( V_5 ,
V_110 ) &
V_194 ;
if ( V_233 )
break;
V_125 -> V_229 [ V_180 ] =
F_15 ( V_5 , V_231 ) ;
}
F_86 ( V_191 , V_125 -> V_229 ,
V_180 *
sizeof( V_125 ->
V_229 [ 0 ] ) ) ;
}
}
}
static void F_90 ( struct V_4 * V_5 )
{
struct V_124 * V_125 = V_5 -> V_126 ;
struct V_190 * V_191 = V_5 -> V_192 ;
unsigned short V_6 ;
T_4 V_226 ;
if ( ! V_125 -> V_225 )
return;
if ( F_18 ( V_5 , V_234 ) & 0x80 ) {
V_226 = F_12 ( V_5 , V_227 ) ;
V_6 = ( V_226 & 0xffff ) ;
F_87 ( V_191 , V_6 ) ;
}
}
static void F_91 ( struct V_4 * V_5 )
{
struct V_124 * V_125 = V_5 -> V_126 ;
struct V_190 * V_191 = V_5 -> V_192 ;
unsigned short V_6 ;
T_4 V_226 ;
if ( ! V_125 -> V_181 )
return;
if ( F_12 ( V_5 , V_183 ) & 0x01 ) {
F_3 ( V_5 , 0x01 , V_182 ) ;
V_226 = F_12 ( V_5 , V_228 ) ;
V_6 = ( V_226 >> 16 ) & 0xffff ;
F_87 ( V_191 , V_6 ) ;
}
}
static void F_92 ( struct V_4 * V_5 )
{
struct V_190 * V_191 = V_5 -> V_192 ;
#ifdef F_58
F_74 ( V_5 ) ;
#endif
F_89 ( V_5 ) ;
F_90 ( V_5 ) ;
F_91 ( V_5 ) ;
V_191 -> V_202 -> V_217 |= V_235 ;
}
static void F_93 ( struct V_4 * V_5 , struct V_190 * V_191 )
{
struct V_124 * V_125 = V_5 -> V_126 ;
if ( V_125 -> V_236 == V_237 ) {
#ifdef F_58
static const int V_179 = 10 ;
int V_180 ;
for ( V_180 = 0 ; V_180 < V_179 ; V_180 ++ ) {
F_72 ( V_5 ) ;
if ( ( V_191 -> V_202 -> V_217 & V_238 ) )
break;
F_66 ( 1 ) ;
}
#else
F_89 ( V_5 ) ;
V_191 -> V_202 -> V_217 |= V_238 ;
#endif
}
if ( ( V_125 -> V_239 & V_240 ) )
F_92 ( V_5 ) ;
}
static void F_94 ( struct V_4 * V_5 ,
unsigned short V_1 )
{
#ifdef F_58
struct V_124 * V_125 = V_5 -> V_126 ;
struct V_190 * V_191 ;
V_191 = & V_5 -> V_241 [ F_1 ( V_1 ) ] ;
F_95 ( & V_125 -> V_169 -> V_170 [ V_1 ] ,
V_191 ) ;
F_96 ( V_5 , V_191 ) ;
#endif
}
static void F_97 ( struct V_4 * V_5 , unsigned short V_242 )
{
unsigned short V_243 = 0 ;
if ( V_242 & V_244 )
V_243 |= V_245 ;
if ( V_242 & V_246 )
V_243 |= V_247 ;
if ( V_242 & V_248 )
V_243 |= V_249 ;
if ( V_242 & V_250 )
V_243 |= V_251 ;
if ( V_243 )
F_35 ( V_5 , V_243 , V_86 ) ;
}
static void F_98 ( struct V_4 * V_5 , unsigned short V_252 ,
unsigned V_253 )
{
struct V_190 * V_191 = V_5 -> V_192 ;
struct V_203 * V_204 = & V_191 -> V_202 -> V_204 ;
if ( V_191 -> type == V_254 )
return;
#ifdef F_58
if ( V_253 & V_255 )
F_72 ( V_5 ) ;
if ( V_253 & ~ ( V_256 | V_255 | V_257 | V_258 |
V_259 | V_260 | V_261 | V_262 |
V_263 | V_264 | V_265 ) ) {
F_42 ( V_5 -> V_25 ,
L_13 ,
V_253 ) ;
V_191 -> V_202 -> V_217 |= V_230 | V_235 ;
}
#endif
if ( V_252 & ( V_266 | V_267 | V_268 |
V_244 | V_246 ) ) {
if ( V_252 == 0xffff ) {
F_42 ( V_5 -> V_25 , L_14 ) ;
if ( F_99 ( V_191 ) ) {
V_191 -> V_202 -> V_217 |=
V_230 | V_235 ;
F_96 ( V_5 , V_191 ) ;
}
return;
}
if ( V_252 & ( V_266 | V_267 |
V_268 ) ) {
F_42 ( V_5 -> V_25 , L_15 ,
V_252 ) ;
F_92 ( V_5 ) ;
V_191 -> V_202 -> V_217 |= V_230 ;
if ( V_252 & ( V_266 | V_267 ) )
V_191 -> V_202 -> V_217 |= V_218 ;
F_96 ( V_5 , V_191 ) ;
return;
}
if ( V_252 & V_244 ) {
if ( V_204 -> V_269 == V_270 )
F_92 ( V_5 ) ;
}
}
#ifndef F_58
if ( V_252 & V_271 ) {
int V_180 ;
static const int V_179 = 10 ;
for ( V_180 = 0 ; V_180 < V_179 ; ++ V_180 ) {
F_88 ( V_5 ) ;
if ( ( F_39 ( V_5 , V_110 ) &
V_271 ) == 0 )
break;
}
}
#endif
if ( ( V_252 & V_250 ) )
F_93 ( V_5 , V_191 ) ;
F_96 ( V_5 , V_191 ) ;
}
static void F_100 ( struct V_4 * V_5 , unsigned short V_197 )
{
unsigned short V_243 = 0 ;
if ( V_197 & V_272 )
V_243 |= V_273 ;
if ( V_197 & V_274 )
V_243 |= V_275 ;
if ( V_197 & V_276 )
V_243 |= V_277 ;
if ( V_197 & V_278 )
V_243 |= V_279 ;
if ( V_197 & V_280 )
V_243 |= V_281 ;
if ( V_197 & V_282 )
V_243 |= V_283 ;
if ( V_197 & V_284 )
V_243 |= V_285 ;
if ( V_243 )
F_35 ( V_5 , V_243 , V_90 ) ;
}
static void F_101 ( struct V_4 * V_5 ,
unsigned short V_197 , unsigned V_286 )
{
struct V_190 * V_191 = V_5 -> V_196 ;
#ifdef F_58
if ( V_286 & V_255 ) {
struct V_124 * V_125 = V_5 -> V_126 ;
F_76 ( V_125 -> V_130 , V_5 ) ;
}
if ( V_286 & ~ ( V_256 | V_255 | V_257 | V_258 |
V_259 | V_260 | V_261 | V_262 |
V_263 | V_264 | V_265 ) ) {
F_42 ( V_5 -> V_25 ,
L_16 ,
V_286 ) ;
V_191 -> V_202 -> V_217 |= V_235 | V_230 ;
}
#endif
if ( V_197 == 0xffff )
return;
if ( V_197 & V_274 ) {
F_42 ( V_5 -> V_25 ,
L_17 ,
V_197 , F_39 ( V_5 , V_114 ) ) ;
V_191 -> V_202 -> V_217 |= V_218 ;
}
if ( V_197 & V_272 )
V_191 -> V_202 -> V_217 |= V_235 ;
#ifndef F_58
if ( V_197 & V_287 ) {
int V_288 ;
V_288 = F_82 ( V_5 , V_191 ) ;
if ( ! V_288 ) {
F_42 ( V_5 -> V_25 , L_18 ) ;
F_71 ( V_5 , V_92 ,
V_289 |
V_290 , 0 ) ;
V_191 -> V_202 -> V_217 |= V_218 ;
}
}
#endif
F_96 ( V_5 , V_191 ) ;
}
static void F_102 ( struct V_4 * V_5 , struct V_190 * V_191 ,
void * V_6 , unsigned int V_291 ,
unsigned int V_292 )
{
struct V_124 * V_125 = V_5 -> V_126 ;
struct V_201 * V_202 = V_191 -> V_202 ;
struct V_203 * V_204 = & V_202 -> V_204 ;
unsigned int V_293 = V_291 / F_103 ( V_191 ) ;
unsigned short * V_294 = V_6 ;
unsigned int * V_295 = V_6 ;
unsigned int V_180 ;
for ( V_180 = 0 ; V_180 < V_293 ; V_180 ++ ) {
#ifdef F_58
if ( V_191 -> V_296 & V_297 )
V_295 [ V_180 ] = F_104 ( V_295 [ V_180 ] ) ;
else
V_294 [ V_180 ] = F_105 ( V_294 [ V_180 ] ) ;
#endif
if ( V_191 -> V_296 & V_297 )
V_295 [ V_180 ] += V_125 -> V_298 [ V_292 ] ;
else
V_294 [ V_180 ] += V_125 -> V_298 [ V_292 ] ;
V_292 ++ ;
V_292 %= V_204 -> V_216 ;
}
}
static int F_106 ( struct V_4 * V_5 )
{
struct V_124 * V_125 = V_5 -> V_126 ;
struct V_190 * V_191 = V_5 -> V_192 ;
int V_193 ;
unsigned long V_127 ;
V_193 = F_51 ( V_5 ) ;
if ( V_193 )
return V_193 ;
F_107 ( V_191 , V_191 -> V_202 -> V_299 ) ;
F_36 ( & V_125 -> V_156 , V_127 ) ;
if ( V_125 -> V_157 == NULL ) {
F_37 ( & V_125 -> V_156 , V_127 ) ;
return - V_300 ;
}
if ( V_125 -> V_225 || V_125 -> V_181 )
F_108 ( V_125 -> V_157 , 32 , 16 ) ;
else if ( V_125 -> V_301 )
F_108 ( V_125 -> V_157 , 32 , 32 ) ;
else
F_108 ( V_125 -> V_157 , 16 , 16 ) ;
F_109 ( V_125 -> V_157 ) ;
F_37 ( & V_125 -> V_156 , V_127 ) ;
return 0 ;
}
static int F_110 ( struct V_4 * V_5 )
{
struct V_124 * V_125 = V_5 -> V_126 ;
struct V_190 * V_191 = V_5 -> V_196 ;
int V_193 ;
unsigned long V_127 ;
V_193 = F_54 ( V_5 ) ;
if ( V_193 )
return V_193 ;
F_111 ( V_191 , V_191 -> V_202 -> V_299 ) ;
F_36 ( & V_125 -> V_156 , V_127 ) ;
if ( V_125 -> V_162 ) {
if ( V_125 -> V_225 || V_125 -> V_302 ) {
F_108 ( V_125 -> V_162 , 32 , 32 ) ;
} else {
F_108 ( V_125 -> V_162 , 16 , 32 ) ;
}
F_109 ( V_125 -> V_162 ) ;
} else
V_193 = - V_300 ;
F_37 ( & V_125 -> V_156 , V_127 ) ;
return V_193 ;
}
static int F_112 ( struct V_4 * V_5 , struct V_190 * V_191 )
{
struct V_124 * V_125 = V_5 -> V_126 ;
F_59 ( V_5 ) ;
F_35 ( V_5 , V_303 | V_304 ,
V_98 ) ;
F_71 ( V_5 , V_88 ,
V_305 | V_306 |
V_307 | V_308 |
V_309 | V_310 |
V_311 , 0 ) ;
F_65 ( V_5 ) ;
if ( ! V_125 -> V_181 )
F_9 ( V_5 , 0 , V_312 ) ;
F_35 ( V_5 , V_313 , V_29 ) ;
F_35 ( V_5 , V_314 | V_315
,
V_33 ) ;
F_35 ( V_5 , 0x0000 , V_35 ) ;
F_35 ( V_5 , ( 0 << 6 ) | 0x0000 , V_37 ) ;
if ( V_125 -> V_225 ) {
F_35 ( V_5 ,
V_316 |
V_317 |
V_318 ,
V_41 ) ;
F_35 ( V_5 ,
F_113 ( 3 ) |
F_114 ( 0 ) |
F_115 ( 2 ) |
F_116 ( 3 ) |
F_117
( V_319 ) ,
V_39 ) ;
} else if ( V_125 -> V_181 ) {
F_35 ( V_5 , V_316 |
V_317 |
V_318 ,
V_41 ) ;
F_35 ( V_5 ,
F_113 ( 3 ) |
F_114 ( 0 ) |
F_115 ( 2 ) |
F_116 ( 3 ) |
F_117
( V_320 ) ,
V_39 ) ;
} else {
unsigned V_321 ;
F_35 ( V_5 ,
V_316 |
V_317 |
V_322 |
V_318 ,
V_41 ) ;
V_321 =
F_113 ( 3 ) |
F_114 ( 0 ) |
F_115 ( 2 ) |
F_116 ( 3 ) ;
if ( V_125 -> V_323 )
V_321 |=
F_117
( V_319 ) ;
else
V_321 |=
F_117
( V_320 ) ;
F_35 ( V_5 , V_321 ,
V_39 ) ;
}
F_35 ( V_5 ,
V_324 |
V_249 |
V_325 |
V_247 |
V_245 |
V_326 |
V_251 ,
V_86 ) ;
F_35 ( V_5 , V_327 , V_98 ) ;
return 0 ;
}
static int F_118 ( struct V_4 * V_5 , struct V_190 * V_191 )
{
unsigned long V_127 ;
int V_328 ;
F_36 ( & V_5 -> V_329 , V_127 ) ;
#ifndef F_58
F_89 ( V_5 ) ;
#else
F_72 ( V_5 ) ;
#endif
V_328 = F_119 ( V_191 ) ;
F_37 ( & V_5 -> V_329 , V_127 ) ;
return V_328 ;
}
static void F_120 ( struct V_4 * V_5 )
{
int V_180 ;
F_35 ( V_5 , V_330 , V_29 ) ;
for ( V_180 = 0 ; V_180 < V_331 ; ++ V_180 ) {
if ( ! ( F_39 ( V_5 , V_110 ) &
V_194 ) ) {
F_35 ( V_5 , 1 , V_27 ) ;
return;
}
F_66 ( 1 ) ;
}
F_42 ( V_5 -> V_25 , L_19 ) ;
}
static void F_121 ( struct V_4 * V_5 ,
unsigned int V_332 ,
unsigned int * V_333 )
{
const struct V_219 * V_220 = V_5 -> V_221 ;
struct V_124 * V_125 = V_5 -> V_126 ;
unsigned int V_205 , V_208 , V_334 ;
unsigned int V_180 ;
unsigned int V_335 ;
unsigned V_336 ;
F_35 ( V_5 , 1 , V_73 ) ;
if ( ( V_333 [ 0 ] & V_337 ) ) {
unsigned V_338 ;
V_205 = F_122 ( V_333 [ 0 ] ) ;
V_208 = F_81 ( V_333 [ 0 ] ) ;
V_336 = V_339 [ V_220 -> V_340 ] [ V_208 ] ;
V_335 = ( ( V_333 [ 0 ] & V_341 ) != 0 ) ;
V_338 = V_342 ;
V_338 |= V_205 ;
V_338 |=
( V_125 -> V_343 ) &
( V_344 |
V_345 |
V_346 |
V_347 ) ;
V_338 |= F_123 ( V_336 ) ;
if ( V_335 )
V_338 |= V_348 ;
V_338 |= V_349 ;
F_3 ( V_5 , V_338 , V_350 ) ;
} else {
F_3 ( V_5 , 0 , V_350 ) ;
}
for ( V_180 = 0 ; V_180 < V_332 ; V_180 ++ ) {
unsigned V_351 = 0 ;
V_205 = F_122 ( V_333 [ V_180 ] ) ;
V_334 = F_124 ( V_333 [ V_180 ] ) ;
V_208 = F_81 ( V_333 [ V_180 ] ) ;
V_335 = ( ( V_333 [ V_180 ] & V_341 ) != 0 ) ;
V_336 = V_339 [ V_220 -> V_340 ] [ V_208 ] ;
V_125 -> V_298 [ V_180 ] = 0 ;
switch ( V_334 ) {
case V_352 :
V_351 |=
V_353 ;
break;
case V_354 :
V_351 |=
V_355 ;
break;
case V_356 :
V_351 |=
V_357 ;
break;
case V_358 :
break;
}
V_351 |= F_125 ( V_205 ) ;
V_351 |=
F_126 ( V_220 -> V_359 , V_205 ) ;
V_351 |= F_127 ( V_336 ) ;
if ( V_180 == V_332 - 1 )
V_351 |= V_360 ;
if ( V_335 )
V_351 |= V_361 ;
V_351 |= V_362 ;
F_6 ( V_5 , V_351 , V_363 ) ;
}
F_120 ( V_5 ) ;
}
static void F_128 ( struct V_4 * V_5 ,
struct V_190 * V_191 ,
unsigned int V_332 , unsigned int * V_333 )
{
const struct V_219 * V_220 = V_5 -> V_221 ;
struct V_124 * V_125 = V_5 -> V_126 ;
unsigned int V_10 = ( V_191 -> V_364 + 1 ) >> 1 ;
unsigned int V_205 , V_208 , V_334 ;
unsigned int V_180 ;
unsigned int V_365 , V_366 ;
unsigned int V_335 ;
if ( V_125 -> V_128 ) {
F_121 ( V_5 , V_332 , V_333 ) ;
return;
}
if ( V_332 == 1 && ! V_125 -> V_225 && ! V_125 -> V_181 ) {
if ( V_125 -> V_367
&& V_125 -> V_368 == V_333 [ 0 ] ) {
return;
}
V_125 -> V_367 = 1 ;
V_125 -> V_368 = V_333 [ 0 ] ;
} else {
V_125 -> V_367 = 0 ;
}
F_35 ( V_5 , 1 , V_73 ) ;
if ( V_125 -> V_181 ) {
if ( ( V_333 [ 0 ] & V_337 )
&& ! V_125 -> V_369 ) {
F_6 ( V_5 , V_125 -> V_343 |
V_370 ,
V_371 ) ;
F_6 ( V_5 , V_125 -> V_343 ,
V_371 ) ;
V_125 -> V_369 = 1 ;
F_129 ( 100 ) ;
} else if ( ! ( V_333 [ 0 ] & V_337 )
&& V_125 -> V_369 ) {
F_6 ( V_5 , V_125 -> V_343 |
V_372 ,
V_371 ) ;
F_6 ( V_5 , V_125 -> V_343 ,
V_371 ) ;
V_125 -> V_369 = 0 ;
F_129 ( 100 ) ;
}
}
for ( V_180 = 0 ; V_180 < V_332 ; V_180 ++ ) {
if ( ! V_125 -> V_181 && ( V_333 [ V_180 ] & V_337 ) )
V_205 = V_125 -> V_343 ;
else
V_205 = F_122 ( V_333 [ V_180 ] ) ;
V_334 = F_124 ( V_333 [ V_180 ] ) ;
V_208 = F_81 ( V_333 [ V_180 ] ) ;
V_335 = ( ( V_333 [ V_180 ] & V_341 ) != 0 ) ;
V_208 = V_339 [ V_220 -> V_340 ] [ V_208 ] ;
if ( V_125 -> V_225 )
V_125 -> V_298 [ V_180 ] = V_10 ;
else
V_125 -> V_298 [ V_180 ] = ( V_208 & 0x100 ) ? 0 : V_10 ;
V_365 = 0 ;
if ( ( V_333 [ V_180 ] & V_337 ) ) {
if ( V_125 -> V_225 )
F_6 ( V_5 , F_122 ( V_333 [ V_180 ] ) & 0x0003 ,
V_373 ) ;
} else {
if ( V_125 -> V_225 )
V_334 = V_352 ;
else if ( V_125 -> V_181 )
V_334 = V_358 ;
switch ( V_334 ) {
case V_352 :
V_365 |= V_374 ;
break;
case V_354 :
V_365 |= V_375 ;
break;
case V_356 :
V_365 |= V_376 ;
break;
case V_358 :
break;
}
}
V_365 |= F_130 ( V_205 ) ;
F_6 ( V_5 , V_365 , V_377 ) ;
if ( ! V_125 -> V_181 ) {
V_366 = V_208 ;
if ( V_180 == V_332 - 1 )
V_366 |= V_378 ;
if ( V_335 )
V_366 |= V_379 ;
F_6 ( V_5 , V_366 , V_380 ) ;
}
}
if ( ! V_125 -> V_225 && ! V_125 -> V_181 )
F_120 ( V_5 ) ;
}
static int F_131 ( struct V_4 * V_5 ,
struct V_190 * V_191 ,
struct V_381 * V_382 ,
unsigned int * V_6 )
{
struct V_124 * V_125 = V_5 -> V_126 ;
unsigned int V_383 = ( V_191 -> V_364 + 1 ) >> 1 ;
int V_180 , V_200 ;
unsigned V_384 ;
unsigned int V_206 ;
unsigned long V_226 ;
F_128 ( V_5 , V_191 , 1 , & V_382 -> V_385 ) ;
F_65 ( V_5 ) ;
V_384 = V_125 -> V_298 [ 0 ] ;
if ( V_125 -> V_225 ) {
for ( V_200 = 0 ; V_200 < V_386 ; V_200 ++ ) {
F_35 ( V_5 , V_330 ,
V_29 ) ;
F_66 ( 1 ) ;
}
for ( V_200 = 0 ; V_200 < V_382 -> V_200 ; V_200 ++ ) {
F_35 ( V_5 , V_330 ,
V_29 ) ;
V_206 = 0 ;
for ( V_180 = 0 ; V_180 < V_331 ; V_180 ++ ) {
if ( F_18 ( V_5 , V_234 ) & 0x80 ) {
V_206 = F_12 ( V_5 , V_227 ) ;
V_206 >>= 16 ;
V_206 &= 0xffff ;
break;
}
if ( ! ( F_39 ( V_5 , V_110 ) &
V_194 ) ) {
V_206 = F_12 ( V_5 , V_227 ) ;
V_206 &= 0xffff ;
break;
}
}
if ( V_180 == V_331 ) {
F_42 ( V_5 -> V_25 , L_20 ,
V_26 ) ;
return - V_387 ;
}
V_206 += V_384 ;
V_6 [ V_200 ] = V_206 ;
}
} else if ( V_125 -> V_181 ) {
for ( V_200 = 0 ; V_200 < V_382 -> V_200 ; V_200 ++ ) {
F_35 ( V_5 , V_330 ,
V_29 ) ;
V_226 = 0 ;
for ( V_180 = 0 ; V_180 < V_331 ; V_180 ++ ) {
if ( F_12 ( V_5 , V_183 ) & 0x01 ) {
F_3 ( V_5 , 0x01 ,
V_182 ) ;
V_226 = F_12 ( V_5 , V_228 ) ;
break;
}
}
if ( V_180 == V_331 ) {
F_42 ( V_5 -> V_25 , L_20 ,
V_26 ) ;
return - V_387 ;
}
V_6 [ V_200 ] = ( ( ( V_226 >> 16 ) & 0xFFFF ) + V_384 ) & 0xFFFF ;
}
} else {
for ( V_200 = 0 ; V_200 < V_382 -> V_200 ; V_200 ++ ) {
F_35 ( V_5 , V_330 ,
V_29 ) ;
for ( V_180 = 0 ; V_180 < V_331 ; V_180 ++ ) {
if ( ! ( F_39 ( V_5 , V_110 ) &
V_194 ) )
break;
}
if ( V_180 == V_331 ) {
F_42 ( V_5 -> V_25 , L_20 ,
V_26 ) ;
return - V_387 ;
}
if ( V_125 -> V_128 ) {
V_226 = F_12 ( V_5 , V_388 ) ;
V_226 &= V_383 ;
V_6 [ V_200 ] = V_226 ;
} else {
V_206 = F_15 ( V_5 , V_231 ) ;
V_206 += V_384 ;
V_6 [ V_200 ] = V_206 ;
}
}
}
return V_382 -> V_200 ;
}
static int F_132 ( const struct V_4 * V_5 , unsigned V_389 ,
unsigned int V_127 )
{
struct V_124 * V_125 = V_5 -> V_126 ;
int V_390 ;
switch ( V_127 & V_391 ) {
case V_392 :
default:
V_390 = ( V_389 + V_125 -> V_393 / 2 ) / V_125 -> V_393 ;
break;
case V_394 :
V_390 = ( V_389 ) / V_125 -> V_393 ;
break;
case V_395 :
V_390 = ( V_389 + V_125 -> V_393 - 1 ) / V_125 -> V_393 ;
break;
}
return V_390 - 1 ;
}
static unsigned F_133 ( const struct V_4 * V_5 , int V_396 )
{
struct V_124 * V_125 = V_5 -> V_126 ;
return V_125 -> V_393 * ( V_396 + 1 ) ;
}
static unsigned F_134 ( struct V_4 * V_5 ,
unsigned V_397 )
{
const struct V_219 * V_220 = V_5 -> V_221 ;
struct V_124 * V_125 = V_5 -> V_126 ;
if ( V_125 -> V_225 || V_125 -> V_181 )
return V_220 -> V_398 ;
return V_220 -> V_398 * V_397 ;
}
static int F_135 ( struct V_4 * V_5 , struct V_190 * V_191 ,
struct V_203 * V_204 )
{
const struct V_219 * V_220 = V_5 -> V_221 ;
struct V_124 * V_125 = V_5 -> V_126 ;
int V_209 = 0 ;
unsigned int V_399 ;
unsigned int V_400 ;
if ( ( V_204 -> V_127 & V_401 ) )
V_204 -> V_127 &= ~ V_401 ;
V_209 |= F_136 ( & V_204 -> V_402 ,
V_403 | V_404 | V_405 ) ;
V_209 |= F_136 ( & V_204 -> V_406 ,
V_407 | V_405 ) ;
V_400 = V_407 | V_405 ;
if ( V_125 -> V_225 || V_125 -> V_181 )
V_400 |= V_403 ;
V_209 |= F_136 ( & V_204 -> V_408 , V_400 ) ;
V_209 |= F_136 ( & V_204 -> V_409 , V_270 ) ;
V_209 |= F_136 ( & V_204 -> V_269 , V_270 | V_410 ) ;
if ( V_209 )
return 1 ;
V_209 |= F_137 ( V_204 -> V_402 ) ;
V_209 |= F_137 ( V_204 -> V_406 ) ;
V_209 |= F_137 ( V_204 -> V_408 ) ;
V_209 |= F_137 ( V_204 -> V_269 ) ;
if ( V_209 )
return 2 ;
switch ( V_204 -> V_402 ) {
case V_403 :
case V_404 :
V_209 |= F_138 ( & V_204 -> V_411 , 0 ) ;
break;
case V_405 :
V_399 = F_122 ( V_204 -> V_411 ) ;
if ( V_399 > 16 )
V_399 = 16 ;
V_399 |= ( V_204 -> V_411 & ( V_412 | V_413 ) ) ;
V_209 |= F_138 ( & V_204 -> V_411 , V_399 ) ;
break;
}
if ( V_204 -> V_406 == V_407 ) {
V_209 |= F_139 ( & V_204 -> V_414 ,
F_134 ( V_5 , V_204 -> V_216 ) ) ;
V_209 |= F_140 ( & V_204 -> V_414 ,
V_125 -> V_393 * 0xffffff ) ;
} else if ( V_204 -> V_406 == V_405 ) {
unsigned int V_399 = F_122 ( V_204 -> V_414 ) ;
if ( V_399 > 16 )
V_399 = 16 ;
V_399 |= ( V_204 -> V_414 & ( V_412 | V_413 ) ) ;
V_209 |= F_138 ( & V_204 -> V_414 , V_399 ) ;
} else {
V_209 |= F_138 ( & V_204 -> V_414 , 0 ) ;
}
if ( V_204 -> V_408 == V_407 ) {
if ( V_125 -> V_225 || V_125 -> V_181 ) {
V_209 |= F_138 ( & V_204 -> V_415 , 0 ) ;
} else {
V_209 |= F_139 ( & V_204 -> V_415 ,
V_220 -> V_398 ) ;
V_209 |= F_140 ( & V_204 -> V_415 ,
V_125 -> V_393 * 0xffff ) ;
}
} else if ( V_204 -> V_408 == V_405 ) {
unsigned int V_399 = F_122 ( V_204 -> V_415 ) ;
if ( V_399 > 16 )
V_399 = 16 ;
V_399 |= ( V_204 -> V_415 & ( V_341 | V_412 ) ) ;
V_209 |= F_138 ( & V_204 -> V_415 , V_399 ) ;
} else if ( V_204 -> V_408 == V_403 ) {
V_209 |= F_138 ( & V_204 -> V_415 , 0 ) ;
}
V_209 |= F_138 ( & V_204 -> V_416 , V_204 -> V_216 ) ;
if ( V_204 -> V_269 == V_270 ) {
unsigned int V_417 = 0x01000000 ;
if ( V_125 -> V_225 )
V_417 -= V_386 ;
V_209 |= F_140 ( & V_204 -> V_418 , V_417 ) ;
V_209 |= F_139 ( & V_204 -> V_418 , 1 ) ;
} else {
V_209 |= F_138 ( & V_204 -> V_418 , 0 ) ;
}
if ( V_209 )
return 3 ;
if ( V_204 -> V_406 == V_407 ) {
V_399 = V_204 -> V_414 ;
V_204 -> V_414 =
F_133 ( V_5 , F_132 ( V_5 ,
V_204 -> V_414 ,
V_204 -> V_127 ) ) ;
if ( V_399 != V_204 -> V_414 )
V_209 ++ ;
}
if ( V_204 -> V_408 == V_407 ) {
if ( ! V_125 -> V_225 && ! V_125 -> V_181 ) {
V_399 = V_204 -> V_415 ;
V_204 -> V_415 =
F_133 ( V_5 , F_132 ( V_5 ,
V_204 -> V_415 ,
V_204 -> V_127 ) ) ;
if ( V_399 != V_204 -> V_415 )
V_209 ++ ;
if ( V_204 -> V_406 == V_407 &&
V_204 -> V_414 <
V_204 -> V_415 * V_204 -> V_416 ) {
V_204 -> V_414 =
V_204 -> V_415 * V_204 -> V_416 ;
V_209 ++ ;
}
}
}
if ( V_209 )
return 4 ;
return 0 ;
}
static int F_141 ( struct V_4 * V_5 ,
struct V_190 * V_191 ,
unsigned int V_419 )
{
struct V_124 * V_125 = V_5 -> V_126 ;
struct V_203 * V_204 = & V_191 -> V_202 -> V_204 ;
if ( V_419 != V_204 -> V_411 )
return - V_420 ;
F_35 ( V_5 , V_421 | V_125 -> V_239 ,
V_31 ) ;
V_191 -> V_202 -> V_422 = NULL ;
return 1 ;
}
static int F_142 ( struct V_4 * V_5 , struct V_190 * V_191 )
{
struct V_124 * V_125 = V_5 -> V_126 ;
const struct V_203 * V_204 = & V_191 -> V_202 -> V_204 ;
int V_396 ;
int V_423 = 0 ;
int V_424 = 0 ;
int V_425 = 0 ;
unsigned int V_426 ;
int V_427 = 0 ;
if ( V_5 -> V_428 == 0 ) {
F_42 ( V_5 -> V_25 , L_21 ) ;
return - V_300 ;
}
F_65 ( V_5 ) ;
F_128 ( V_5 , V_191 , V_204 -> V_216 , V_204 -> V_211 ) ;
F_35 ( V_5 , V_303 , V_98 ) ;
V_125 -> V_429 &= ~ V_430 ;
F_35 ( V_5 , V_125 -> V_429 ,
V_51 ) ;
switch ( V_204 -> V_402 ) {
case V_404 :
case V_403 :
F_35 ( V_5 ,
F_143 ( 0 ) |
V_431 | V_432 |
F_144 ( 0 ) ,
V_49 ) ;
break;
case V_405 :
{
int V_205 = F_122 ( V_204 -> V_411 ) ;
unsigned int V_188 = F_143 ( 0 ) |
V_431 | F_144 ( V_205 + 1 ) ;
if ( V_204 -> V_411 & V_412 )
V_188 |= V_433 ;
if ( V_204 -> V_411 & V_413 )
V_188 |= V_432 ;
F_35 ( V_5 , V_188 , V_49 ) ;
break;
}
}
V_424 &= ~ V_434 ;
V_424 &= ~ V_435 ;
V_424 &= ~ V_436 ;
F_35 ( V_5 , V_424 , V_35 ) ;
if ( V_204 -> V_216 == 1 || V_125 -> V_225 || V_125 -> V_181 ) {
V_425 |= V_437 ;
V_425 |= F_145 ( 31 ) ;
V_425 |= V_438 ;
} else {
V_425 |= F_145 ( 19 ) ;
}
F_35 ( V_5 , V_425 , V_47 ) ;
V_125 -> V_239 = 0 ;
switch ( V_204 -> V_269 ) {
case V_270 :
V_426 = V_204 -> V_418 - 1 ;
if ( V_125 -> V_225 ) {
V_426 += V_386 ;
}
F_38 ( V_5 , V_426 , V_11 ) ;
V_423 |= V_314 | V_315 | V_439 ;
F_35 ( V_5 , V_423 , V_33 ) ;
F_35 ( V_5 , V_440 , V_29 ) ;
if ( V_426 == 0 ) {
V_125 -> V_239 |= V_240 ;
V_427 |= V_309 ;
if ( V_204 -> V_216 > 1 )
V_425 |=
V_437 | V_441 ;
}
break;
case V_410 :
F_38 ( V_5 , 0 , V_11 ) ;
V_423 |= V_314 | V_315 | V_442 ;
F_35 ( V_5 , V_423 , V_33 ) ;
F_35 ( V_5 , V_440 , V_29 ) ;
break;
}
switch ( V_204 -> V_406 ) {
case V_407 :
V_425 |= V_443 | V_444 ;
F_35 ( V_5 , V_425 ,
V_47 ) ;
V_424 |= F_146 ( 0 ) ;
V_424 &= ~ V_445 ;
F_35 ( V_5 , V_424 , V_35 ) ;
V_396 = F_132 ( V_5 , V_204 -> V_414 ,
V_392 ) ;
F_38 ( V_5 , V_396 , V_13 ) ;
F_35 ( V_5 , V_446 , V_29 ) ;
break;
case V_405 :
if ( V_204 -> V_414 & V_413 )
V_425 |= V_443 ;
if ( V_204 -> V_414 & V_412 )
V_425 |= V_447 ;
if ( V_204 -> V_406 != V_204 -> V_408 ||
( V_204 -> V_414 & ~ V_413 ) !=
( V_204 -> V_415 & ~ V_413 ) )
V_425 |= V_444 ;
V_425 |=
F_147 ( 1 + F_122 ( V_204 -> V_414 ) ) ;
F_35 ( V_5 , V_425 ,
V_47 ) ;
break;
}
switch ( V_204 -> V_408 ) {
case V_407 :
case V_403 :
if ( V_204 -> V_415 == 0 || V_204 -> V_408 == V_403 )
V_396 = 1 ;
else
V_396 = F_132 ( V_5 , V_204 -> V_415 ,
V_392 ) ;
F_35 ( V_5 , 1 , V_43 ) ;
F_35 ( V_5 , V_396 , V_45 ) ;
V_424 &= ~ V_448 ;
V_424 |= V_449 ;
F_35 ( V_5 , V_424 , V_35 ) ;
F_35 ( V_5 , V_450 , V_29 ) ;
V_424 |= V_449 ;
V_424 |= V_448 ;
F_35 ( V_5 , V_424 , V_35 ) ;
break;
case V_405 :
V_423 |= F_148 ( 1 + V_204 -> V_415 ) ;
if ( ( V_204 -> V_415 & V_412 ) == 0 )
V_423 |= V_451 ;
F_35 ( V_5 , V_423 , V_33 ) ;
V_424 |= V_452 | V_453 ;
F_35 ( V_5 , V_424 , V_35 ) ;
break;
}
if ( V_5 -> V_428 ) {
V_427 |= V_310 |
V_305 ;
#ifndef F_58
V_427 |= V_311 ;
#endif
if ( V_204 -> V_127 & V_454
|| ( V_125 -> V_239 & V_240 ) ) {
V_125 -> V_236 = V_237 ;
} else {
V_125 -> V_236 = V_455 ;
}
switch ( V_125 -> V_236 ) {
case V_455 :
#ifdef F_58
F_35 ( V_5 , V_456 ,
V_37 ) ;
#else
F_35 ( V_5 , V_457 ,
V_37 ) ;
#endif
break;
case V_458 :
F_35 ( V_5 , V_459 ,
V_37 ) ;
break;
case V_237 :
#ifdef F_58
F_35 ( V_5 , V_459 ,
V_37 ) ;
#else
F_35 ( V_5 , V_457 ,
V_37 ) ;
#endif
V_427 |= V_309 ;
break;
default:
break;
}
F_35 ( V_5 ,
V_326 |
V_251 |
V_249 |
V_325 |
V_247 |
V_245 |
V_324 ,
V_86 ) ;
F_71 ( V_5 , V_88 ,
V_427 , 1 ) ;
} else {
F_71 ( V_5 , V_88 , ~ 0 , 0 ) ;
}
F_35 ( V_5 , V_327 , V_98 ) ;
switch ( V_204 -> V_406 ) {
case V_407 :
F_35 ( V_5 ,
V_460 | V_461 | V_462 | V_463 ,
V_29 ) ;
break;
case V_405 :
F_35 ( V_5 ,
V_460 | V_461 | V_462 | V_463 ,
V_29 ) ;
break;
}
#ifdef F_58
{
int V_193 = F_106 ( V_5 ) ;
if ( V_193 )
return V_193 ;
}
#endif
if ( V_204 -> V_402 == V_403 ) {
F_35 ( V_5 , V_421 | V_125 -> V_239 ,
V_31 ) ;
V_191 -> V_202 -> V_422 = NULL ;
} else if ( V_204 -> V_402 == V_405 ) {
V_191 -> V_202 -> V_422 = NULL ;
} else {
V_191 -> V_202 -> V_422 = F_141 ;
}
return 0 ;
}
static int F_149 ( struct V_4 * V_5 ,
struct V_190 * V_191 ,
struct V_381 * V_382 , unsigned int * V_6 )
{
struct V_124 * V_125 = V_5 -> V_126 ;
if ( V_382 -> V_200 < 1 )
return - V_420 ;
switch ( V_6 [ 0 ] ) {
case V_464 :
if ( V_125 -> V_128 ) {
if ( V_6 [ 1 ] & ~ ( V_344 |
V_345 |
V_346 |
V_347 ) ) {
return - V_420 ;
}
V_125 -> V_343 = V_6 [ 1 ] ;
} else if ( V_125 -> V_181 ) {
unsigned int V_465 ;
V_465 = V_6 [ 1 ] & 0xf ;
V_125 -> V_343 = V_465 ;
F_6 ( V_5 , V_465 , V_371 ) ;
} else {
unsigned int V_465 ;
unsigned int V_466 ;
V_465 = V_6 [ 1 ] & 0xf ;
V_466 = ( V_6 [ 1 ] >> 4 ) & 0xff ;
if ( V_465 >= 8 )
return - V_420 ;
V_125 -> V_343 = V_465 ;
if ( V_125 -> V_225 ) {
F_9 ( V_5 , V_466 ,
V_467 ) ;
}
}
return 2 ;
default:
break;
}
return - V_420 ;
}
static void F_150 ( struct V_4 * V_5 , struct V_190 * V_191 ,
void * V_6 , unsigned int V_291 ,
unsigned int V_292 )
{
struct V_203 * V_204 = & V_191 -> V_202 -> V_204 ;
unsigned int V_293 = V_291 / F_103 ( V_191 ) ;
unsigned short * V_294 = V_6 ;
unsigned int V_180 ;
for ( V_180 = 0 ; V_180 < V_293 ; V_180 ++ ) {
unsigned int V_208 = F_81 ( V_204 -> V_211 [ V_292 ] ) ;
unsigned short V_133 = V_294 [ V_180 ] ;
if ( F_151 ( V_191 , V_208 ) )
V_133 = F_152 ( V_191 , V_133 ) ;
#ifdef F_58
V_133 = F_153 ( V_133 ) ;
#endif
V_294 [ V_180 ] = V_133 ;
V_292 ++ ;
V_292 %= V_204 -> V_216 ;
}
}
static int F_154 ( struct V_4 * V_5 ,
struct V_190 * V_191 ,
unsigned int V_385 [] ,
unsigned int V_468 , int V_469 )
{
struct V_124 * V_125 = V_5 -> V_126 ;
unsigned int V_208 ;
unsigned int V_205 ;
unsigned int V_470 ;
int V_180 ;
int V_471 = 0 ;
if ( V_469 ) {
for ( V_180 = 0 ; V_180 < V_191 -> V_332 ; ++ V_180 ) {
V_125 -> V_472 [ V_180 ] &= ~ V_473 ;
F_9 ( V_5 , V_125 -> V_472 [ V_180 ] ,
F_155 ( V_180 ) ) ;
F_9 ( V_5 , 0xf , F_156 ( V_180 ) ) ;
}
}
for ( V_180 = 0 ; V_180 < V_468 ; V_180 ++ ) {
const struct V_474 * V_475 ;
V_205 = F_122 ( V_385 [ V_180 ] ) ;
V_208 = F_81 ( V_385 [ V_180 ] ) ;
V_475 = V_191 -> V_476 -> V_208 + V_208 ;
V_471 = 0 ;
V_470 = 0 ;
switch ( V_475 -> V_477 - V_475 -> V_478 ) {
case 20000000 :
V_470 |= V_479 ;
F_9 ( V_5 , 0 ,
F_157 ( V_205 ) ) ;
break;
case 10000000 :
V_470 |= V_480 ;
F_9 ( V_5 , 0 ,
F_157 ( V_205 ) ) ;
break;
case 4000000 :
V_470 |= V_479 ;
F_9 ( V_5 , V_481 ,
F_157 ( V_205 ) ) ;
break;
case 2000000 :
V_470 |= V_480 ;
F_9 ( V_5 , V_481 ,
F_157 ( V_205 ) ) ;
break;
default:
F_42 ( V_5 -> V_25 ,
L_22 ,
V_26 ) ;
break;
}
switch ( V_475 -> V_477 + V_475 -> V_478 ) {
case 0 :
V_470 |= V_482 ;
break;
case 10000000 :
V_470 |= V_483 ;
break;
default:
F_42 ( V_5 -> V_25 ,
L_23 ,
V_26 ) ;
break;
}
if ( V_469 )
V_470 |= V_473 ;
F_9 ( V_5 , V_470 , F_155 ( V_205 ) ) ;
V_125 -> V_472 [ V_205 ] = V_470 ;
F_9 ( V_5 , V_180 , F_156 ( V_205 ) ) ;
}
return V_471 ;
}
static int F_158 ( struct V_4 * V_5 ,
struct V_190 * V_191 ,
unsigned int V_385 [] ,
unsigned int V_468 )
{
struct V_124 * V_125 = V_5 -> V_126 ;
unsigned int V_208 ;
unsigned int V_205 ;
unsigned int V_470 ;
int V_180 ;
int V_471 = 0 ;
for ( V_180 = 0 ; V_180 < V_468 ; V_180 ++ ) {
V_205 = F_122 ( V_385 [ V_180 ] ) ;
V_208 = F_81 ( V_385 [ V_180 ] ) ;
V_470 = F_159 ( V_205 ) ;
if ( F_151 ( V_191 , V_208 ) ) {
V_470 |= V_484 ;
V_471 = ( V_191 -> V_364 + 1 ) >> 1 ;
} else {
V_471 = 0 ;
}
if ( F_160 ( V_191 , V_208 ) )
V_470 |= V_485 ;
if ( V_385 [ V_180 ] & V_486 )
V_470 |= V_487 ;
V_470 |= ( F_124 ( V_385 [ V_180 ] ) ==
V_358 ) ? V_488 : 0 ;
F_6 ( V_5 , V_470 , V_489 ) ;
V_125 -> V_472 [ V_205 ] = V_470 ;
}
return V_471 ;
}
static int F_161 ( struct V_4 * V_5 ,
struct V_190 * V_191 ,
unsigned int V_385 [] , unsigned int V_468 ,
int V_469 )
{
struct V_124 * V_125 = V_5 -> V_126 ;
if ( V_125 -> V_128 )
return F_154 ( V_5 , V_191 , V_385 , V_468 ,
V_469 ) ;
else
return F_158 ( V_5 , V_191 , V_385 , V_468 ) ;
}
static int F_162 ( struct V_4 * V_5 ,
struct V_190 * V_191 ,
struct V_381 * V_382 ,
unsigned int * V_6 )
{
struct V_124 * V_125 = V_5 -> V_126 ;
unsigned int V_205 = F_122 ( V_382 -> V_385 ) ;
unsigned int V_208 = F_81 ( V_382 -> V_385 ) ;
int V_7 ;
int V_180 ;
if ( V_125 -> V_212 ) {
F_68 ( V_5 , 1 << V_205 , V_490 ) ;
V_7 = F_163 ( V_205 ) ;
} else if ( V_125 -> V_128 ) {
V_7 = F_164 ( V_205 ) ;
} else {
V_7 = ( V_205 ) ? V_491 : V_492 ;
}
F_161 ( V_5 , V_191 , & V_382 -> V_385 , 1 , 0 ) ;
for ( V_180 = 0 ; V_180 < V_382 -> V_200 ; V_180 ++ ) {
unsigned int V_133 = V_6 [ V_180 ] ;
V_191 -> V_493 [ V_205 ] = V_133 ;
if ( V_125 -> V_212 ) {
V_133 = F_152 ( V_191 , V_133 ) ;
F_68 ( V_5 , V_133 , V_7 ) ;
} else if ( V_125 -> V_128 ) {
F_6 ( V_5 , V_133 , V_7 ) ;
} else {
if ( F_151 ( V_191 , V_208 ) )
V_133 = F_152 ( V_191 , V_133 ) ;
F_6 ( V_5 , V_133 , V_7 ) ;
}
}
return V_382 -> V_200 ;
}
static int F_165 ( struct V_4 * V_5 ,
struct V_190 * V_191 ,
struct V_381 * V_382 , unsigned int * V_6 )
{
const struct V_219 * V_220 = V_5 -> V_221 ;
struct V_124 * V_125 = V_5 -> V_126 ;
switch ( V_6 [ 0 ] ) {
case V_494 :
switch ( V_6 [ 1 ] ) {
case V_164 :
V_6 [ 2 ] = 1 + V_220 -> V_222 * sizeof( short ) ;
if ( V_125 -> V_130 )
V_6 [ 2 ] += V_125 -> V_130 -> V_495 ;
break;
case V_161 :
V_6 [ 2 ] = 0 ;
break;
default:
return - V_420 ;
}
return 0 ;
default:
break;
}
return - V_420 ;
}
static int F_166 ( struct V_4 * V_5 ,
struct V_190 * V_191 ,
unsigned int V_419 )
{
struct V_124 * V_125 = V_5 -> V_126 ;
struct V_203 * V_204 = & V_191 -> V_202 -> V_204 ;
int V_288 ;
int V_496 ;
int V_180 ;
static const int V_179 = 1000 ;
if ( V_419 != V_204 -> V_411 )
return - V_420 ;
V_191 -> V_202 -> V_422 = NULL ;
F_71 ( V_5 , V_92 ,
V_289 | V_290 , 0 ) ;
V_496 = V_290 ;
#ifdef F_58
F_35 ( V_5 , 1 , V_75 ) ;
if ( V_125 -> V_212 )
F_69 ( V_5 , 0x6 , V_224 ) ;
V_288 = F_110 ( V_5 ) ;
if ( V_288 )
return V_288 ;
V_288 = F_78 ( V_5 ) ;
if ( V_288 < 0 )
return V_288 ;
#else
V_288 = F_84 ( V_5 , V_191 ) ;
if ( V_288 == 0 )
return - V_199 ;
V_496 |= V_289 ;
#endif
F_35 ( V_5 , V_125 -> V_497 | V_498 ,
V_61 ) ;
F_35 ( V_5 , V_125 -> V_497 , V_61 ) ;
for ( V_180 = 0 ; V_180 < V_179 ; V_180 ++ ) {
F_66 ( 1 ) ;
if ( ( F_39 ( V_5 , V_120 ) &
V_499 ) == 0 )
break;
}
if ( V_180 == V_179 ) {
F_42 ( V_5 -> V_25 ,
L_24 ) ;
return - V_300 ;
}
F_35 ( V_5 , V_275 , V_90 ) ;
F_71 ( V_5 , V_92 , V_496 , 1 ) ;
F_35 ( V_5 , V_125 -> V_500 |
V_501 | V_502 | V_503 |
V_504 | V_505 ,
V_53 ) ;
F_35 ( V_5 , V_125 -> V_506 | V_507 ,
V_55 ) ;
return 0 ;
}
static int F_167 ( struct V_4 * V_5 , struct V_190 * V_191 )
{
const struct V_219 * V_220 = V_5 -> V_221 ;
struct V_124 * V_125 = V_5 -> V_126 ;
const struct V_203 * V_204 = & V_191 -> V_202 -> V_204 ;
int V_188 ;
int V_180 ;
unsigned V_508 ;
if ( V_5 -> V_428 == 0 ) {
F_42 ( V_5 -> V_25 , L_21 ) ;
return - V_300 ;
}
F_35 ( V_5 , V_509 , V_98 ) ;
F_35 ( V_5 , V_510 , V_53 ) ;
if ( V_125 -> V_212 ) {
F_68 ( V_5 , V_511 , V_512 ) ;
V_188 = 0 ;
for ( V_180 = 0 ; V_180 < V_204 -> V_216 ; V_180 ++ ) {
int V_205 ;
V_205 = F_122 ( V_204 -> V_211 [ V_180 ] ) ;
V_188 |= 1 << V_205 ;
F_68 ( V_5 , V_205 , V_513 ) ;
}
F_68 ( V_5 , V_188 , V_514 ) ;
}
F_161 ( V_5 , V_191 , V_204 -> V_211 , V_204 -> V_216 , 1 ) ;
if ( V_204 -> V_269 == V_410 ) {
V_125 -> V_515 |= V_516 ;
V_125 -> V_515 &= ~ V_517 ;
} else {
V_125 -> V_515 &= ~ V_516 ;
V_125 -> V_515 |= V_517 ;
}
F_35 ( V_5 , V_125 -> V_515 , V_57 ) ;
switch ( V_204 -> V_402 ) {
case V_404 :
case V_403 :
V_125 -> V_518 &=
~ ( V_519 | F_168 ( - 1 ) ) ;
V_125 -> V_518 |= V_520 | V_521 ;
F_35 ( V_5 , V_125 -> V_518 ,
V_69 ) ;
break;
case V_405 :
V_125 -> V_518 =
F_168 ( F_122 ( V_204 -> V_411 ) + 1 ) ;
if ( V_204 -> V_411 & V_412 )
V_125 -> V_518 |= V_519 ;
if ( V_204 -> V_411 & V_413 )
V_125 -> V_518 |= V_520 ;
F_35 ( V_5 , V_125 -> V_518 ,
V_69 ) ;
break;
default:
F_2 () ;
break;
}
V_125 -> V_497 &= ~ V_522 ;
F_35 ( V_5 , V_125 -> V_497 , V_61 ) ;
F_35 ( V_5 , V_125 -> V_515 , V_57 ) ;
V_125 -> V_523 &= ~ V_524 ;
F_35 ( V_5 , V_125 -> V_523 , V_59 ) ;
if ( V_204 -> V_269 == V_410 )
F_38 ( V_5 , 0xffffff , V_15 ) ;
else
F_38 ( V_5 , 0 , V_15 ) ;
F_35 ( V_5 , V_525 , V_53 ) ;
V_125 -> V_523 &= ~ V_526 ;
F_35 ( V_5 , V_125 -> V_523 , V_59 ) ;
switch ( V_204 -> V_269 ) {
case V_270 :
if ( V_125 -> V_128 ) {
F_38 ( V_5 , V_204 -> V_418 - 1 ,
V_17 ) ;
F_35 ( V_5 , V_527 , V_53 ) ;
} else {
F_38 ( V_5 , V_204 -> V_418 ,
V_17 ) ;
F_35 ( V_5 , V_527 , V_53 ) ;
F_38 ( V_5 , V_204 -> V_418 - 1 ,
V_17 ) ;
}
break;
case V_410 :
F_38 ( V_5 , 0xffffff , V_17 ) ;
F_35 ( V_5 , V_527 , V_53 ) ;
F_38 ( V_5 , 0xffffff , V_17 ) ;
break;
default:
F_38 ( V_5 , 0 , V_17 ) ;
F_35 ( V_5 , V_527 , V_53 ) ;
F_38 ( V_5 , V_204 -> V_418 , V_17 ) ;
}
V_125 -> V_515 &=
~ ( F_169 ( 0x1f ) | V_528 |
F_170 ( 0x1f ) | V_529 ) ;
switch ( V_204 -> V_406 ) {
case V_407 :
V_125 -> V_506 &= ~ V_530 ;
V_508 =
F_132 ( V_5 , V_204 -> V_414 ,
V_392 ) ;
F_38 ( V_5 , 1 , V_19 ) ;
F_35 ( V_5 , V_531 , V_53 ) ;
F_38 ( V_5 , V_508 , V_19 ) ;
break;
case V_405 :
V_125 -> V_515 |=
F_170 ( V_204 -> V_414 ) ;
if ( V_204 -> V_414 & V_412 )
V_125 -> V_515 |= V_529 ;
V_125 -> V_506 |= V_530 ;
break;
default:
F_2 () ;
break;
}
F_35 ( V_5 , V_125 -> V_506 , V_55 ) ;
F_35 ( V_5 , V_125 -> V_515 , V_57 ) ;
V_125 -> V_523 &=
~ ( F_171 ( 3 ) | V_532 ) ;
F_35 ( V_5 , V_125 -> V_523 , V_59 ) ;
if ( V_204 -> V_416 > 1 ) {
V_125 -> V_515 |= V_533 ;
F_35 ( V_5 ,
F_172 ( V_204 -> V_416 - 1 ) |
F_173 ( V_534 ) ,
V_63 ) ;
} else {
unsigned V_188 ;
V_125 -> V_515 &= ~ V_533 ;
V_188 = F_173 ( V_534 ) ;
if ( V_125 -> V_128 || V_125 -> V_212 ) {
V_188 |= F_172 ( 0 ) ;
} else {
V_188 |=
F_172 ( F_122 ( V_204 -> V_211 [ 0 ] ) ) ;
}
F_35 ( V_5 , V_188 , V_63 ) ;
}
F_35 ( V_5 , V_125 -> V_515 , V_57 ) ;
F_35 ( V_5 , V_505 | V_504 ,
V_53 ) ;
V_125 -> V_497 |= V_535 ;
F_35 ( V_5 , V_125 -> V_497 , V_61 ) ;
V_125 -> V_523 &= ~ V_536 ;
#ifdef F_58
V_125 -> V_523 |= V_537 ;
#else
V_125 -> V_523 |= V_538 ;
#endif
V_125 -> V_523 &= ~ V_539 ;
F_35 ( V_5 , V_125 -> V_523 , V_59 ) ;
V_188 = V_540 | V_541 |
V_542 ;
if ( V_220 -> V_222 )
V_188 |= V_543 ;
else
V_188 |= V_544 ;
#if 0
if (devpriv->is_m_series)
bits |= AO_Number_Of_DAC_Packages;
#endif
F_35 ( V_5 , V_188 , V_65 ) ;
F_35 ( V_5 , V_545 , V_67 ) ;
F_35 ( V_5 , V_546 , V_98 ) ;
if ( V_204 -> V_269 == V_270 ) {
F_35 ( V_5 , V_273 ,
V_90 ) ;
F_71 ( V_5 , V_92 ,
V_547 , 1 ) ;
}
V_191 -> V_202 -> V_422 = F_166 ;
return 0 ;
}
static int F_174 ( struct V_4 * V_5 , struct V_190 * V_191 ,
struct V_203 * V_204 )
{
const struct V_219 * V_220 = V_5 -> V_221 ;
struct V_124 * V_125 = V_5 -> V_126 ;
int V_209 = 0 ;
unsigned int V_399 ;
if ( ( V_204 -> V_127 & V_401 ) == 0 )
V_204 -> V_127 |= V_401 ;
V_209 |= F_136 ( & V_204 -> V_402 , V_404 | V_405 ) ;
V_209 |= F_136 ( & V_204 -> V_406 ,
V_407 | V_405 ) ;
V_209 |= F_136 ( & V_204 -> V_408 , V_403 ) ;
V_209 |= F_136 ( & V_204 -> V_409 , V_270 ) ;
V_209 |= F_136 ( & V_204 -> V_269 , V_270 | V_410 ) ;
if ( V_209 )
return 1 ;
V_209 |= F_137 ( V_204 -> V_402 ) ;
V_209 |= F_137 ( V_204 -> V_406 ) ;
V_209 |= F_137 ( V_204 -> V_269 ) ;
if ( V_209 )
return 2 ;
switch ( V_204 -> V_402 ) {
case V_404 :
V_209 |= F_138 ( & V_204 -> V_411 , 0 ) ;
break;
case V_405 :
V_399 = F_122 ( V_204 -> V_411 ) ;
if ( V_399 > 18 )
V_399 = 18 ;
V_399 |= ( V_204 -> V_411 & ( V_412 | V_413 ) ) ;
V_209 |= F_138 ( & V_204 -> V_411 , V_399 ) ;
break;
}
if ( V_204 -> V_406 == V_407 ) {
V_209 |= F_139 ( & V_204 -> V_414 ,
V_220 -> V_548 ) ;
V_209 |= F_140 ( & V_204 -> V_414 ,
V_125 -> V_393 * 0xffffff ) ;
}
V_209 |= F_138 ( & V_204 -> V_415 , 0 ) ;
V_209 |= F_138 ( & V_204 -> V_416 , V_204 -> V_216 ) ;
if ( V_204 -> V_269 == V_270 )
V_209 |= F_140 ( & V_204 -> V_418 , 0x00ffffff ) ;
else
V_209 |= F_138 ( & V_204 -> V_418 , 0 ) ;
if ( V_209 )
return 3 ;
if ( V_204 -> V_406 == V_407 ) {
V_399 = V_204 -> V_414 ;
V_204 -> V_414 =
F_133 ( V_5 , F_132 ( V_5 ,
V_204 -> V_414 ,
V_204 -> V_127 ) ) ;
if ( V_399 != V_204 -> V_414 )
V_209 ++ ;
}
if ( V_209 )
return 4 ;
return 0 ;
}
static int F_175 ( struct V_4 * V_5 , struct V_190 * V_191 )
{
struct V_124 * V_125 = V_5 -> V_126 ;
F_61 ( V_5 ) ;
F_35 ( V_5 , V_509 , V_98 ) ;
F_35 ( V_5 , V_510 , V_53 ) ;
F_71 ( V_5 , V_92 , ~ 0 , 0 ) ;
F_35 ( V_5 , V_540 , V_65 ) ;
F_35 ( V_5 , 0x3f98 , V_90 ) ;
F_35 ( V_5 , V_540 | V_541 |
V_542 , V_65 ) ;
F_35 ( V_5 , 0 , V_63 ) ;
F_35 ( V_5 , 0 , V_67 ) ;
V_125 -> V_500 = 0 ;
F_35 ( V_5 , V_125 -> V_500 , V_53 ) ;
V_125 -> V_506 = 0 ;
F_35 ( V_5 , V_125 -> V_506 , V_55 ) ;
V_125 -> V_515 = 0 ;
F_35 ( V_5 , V_125 -> V_515 , V_57 ) ;
V_125 -> V_523 = 0 ;
F_35 ( V_5 , V_125 -> V_523 , V_59 ) ;
if ( V_125 -> V_128 )
V_125 -> V_497 = V_549 ;
else
V_125 -> V_497 = 0 ;
F_35 ( V_5 , V_125 -> V_497 , V_61 ) ;
V_125 -> V_518 = 0 ;
F_35 ( V_5 , V_125 -> V_518 ,
V_69 ) ;
if ( V_125 -> V_212 ) {
unsigned V_550 = 0 ;
unsigned V_180 ;
for ( V_180 = 0 ; V_180 < V_191 -> V_332 ; ++ V_180 )
V_550 |= 1 << V_180 ;
F_68 ( V_5 , V_550 , V_490 ) ;
F_68 ( V_5 , V_511 , V_512 ) ;
}
F_35 ( V_5 , V_546 , V_98 ) ;
return 0 ;
}
static int F_176 ( struct V_4 * V_5 ,
struct V_190 * V_191 ,
struct V_381 * V_382 ,
unsigned int * V_6 )
{
struct V_124 * V_125 = V_5 -> V_126 ;
int V_288 ;
V_288 = F_177 ( V_5 , V_191 , V_382 , V_6 , 0 ) ;
if ( V_288 )
return V_288 ;
V_125 -> V_551 &= ~ V_552 ;
V_125 -> V_551 |= F_178 ( V_191 -> V_553 ) ;
F_35 ( V_5 , V_125 -> V_551 , V_77 ) ;
return V_382 -> V_200 ;
}
static int F_179 ( struct V_4 * V_5 ,
struct V_190 * V_191 ,
struct V_381 * V_382 ,
unsigned int * V_6 )
{
struct V_124 * V_125 = V_5 -> V_126 ;
if ( ( V_6 [ 0 ] & ( V_554 | V_555 ) ) && V_125 -> V_556 )
return - V_159 ;
if ( F_180 ( V_191 , V_6 ) ) {
V_125 -> V_557 &= ~ V_558 ;
V_125 -> V_557 |= F_181 ( V_191 -> V_559 ) ;
F_35 ( V_5 , V_125 -> V_557 , V_560 ) ;
}
V_6 [ 1 ] = F_39 ( V_5 , V_561 ) ;
return V_382 -> V_200 ;
}
static int F_182 ( struct V_4 * V_5 ,
struct V_190 * V_191 ,
struct V_381 * V_382 ,
unsigned int * V_6 )
{
int V_288 ;
V_288 = F_177 ( V_5 , V_191 , V_382 , V_6 , 0 ) ;
if ( V_288 )
return V_288 ;
F_3 ( V_5 , V_191 -> V_553 , V_562 ) ;
return V_382 -> V_200 ;
}
static int F_183 ( struct V_4 * V_5 ,
struct V_190 * V_191 ,
struct V_381 * V_382 ,
unsigned int * V_6 )
{
if ( F_180 ( V_191 , V_6 ) )
F_3 ( V_5 , V_191 -> V_559 , V_563 ) ;
V_6 [ 1 ] = F_12 ( V_5 , V_564 ) ;
return V_382 -> V_200 ;
}
static int F_184 ( struct V_4 * V_5 ,
struct V_190 * V_191 ,
struct V_203 * V_204 )
{
int V_180 ;
for ( V_180 = 0 ; V_180 < V_204 -> V_216 ; ++ V_180 ) {
unsigned int V_205 = F_122 ( V_204 -> V_211 [ V_180 ] ) ;
if ( V_205 != V_180 )
return - V_420 ;
}
return 0 ;
}
static int F_185 ( struct V_4 * V_5 ,
struct V_190 * V_191 , struct V_203 * V_204 )
{
int V_209 = 0 ;
int V_399 ;
V_209 |= F_136 ( & V_204 -> V_402 , V_404 ) ;
V_209 |= F_136 ( & V_204 -> V_406 , V_405 ) ;
V_209 |= F_136 ( & V_204 -> V_408 , V_403 ) ;
V_209 |= F_136 ( & V_204 -> V_409 , V_270 ) ;
V_209 |= F_136 ( & V_204 -> V_269 , V_410 ) ;
if ( V_209 )
return 1 ;
if ( V_209 )
return 2 ;
V_209 |= F_138 ( & V_204 -> V_411 , 0 ) ;
V_399 = V_204 -> V_414 ;
V_399 &= F_186 ( V_565 , 0 , 0 , V_412 ) ;
if ( V_399 != V_204 -> V_414 )
V_209 |= - V_420 ;
V_209 |= F_138 ( & V_204 -> V_415 , 0 ) ;
V_209 |= F_138 ( & V_204 -> V_416 , V_204 -> V_216 ) ;
V_209 |= F_138 ( & V_204 -> V_418 , 0 ) ;
if ( V_209 )
return 3 ;
if ( V_204 -> V_211 && V_204 -> V_216 > 0 )
V_209 |= F_184 ( V_5 , V_191 , V_204 ) ;
if ( V_209 )
return 5 ;
return 0 ;
}
static int F_187 ( struct V_4 * V_5 ,
struct V_190 * V_191 ,
unsigned int V_419 )
{
struct V_203 * V_204 = & V_191 -> V_202 -> V_204 ;
const unsigned V_179 = 1000 ;
int V_193 = 0 ;
unsigned V_180 ;
#ifdef F_58
struct V_124 * V_125 = V_5 -> V_126 ;
unsigned long V_127 ;
#endif
if ( V_419 != V_204 -> V_411 )
return - V_420 ;
V_191 -> V_202 -> V_422 = NULL ;
F_111 ( V_191 , V_191 -> V_202 -> V_299 ) ;
#ifdef F_58
F_36 ( & V_125 -> V_156 , V_127 ) ;
if ( V_125 -> V_172 ) {
F_108 ( V_125 -> V_172 , 32 , 32 ) ;
F_109 ( V_125 -> V_172 ) ;
} else {
F_42 ( V_5 -> V_25 , L_25 ) ;
V_193 = - V_300 ;
}
F_37 ( & V_125 -> V_156 , V_127 ) ;
if ( V_193 < 0 )
return V_193 ;
#endif
for ( V_180 = 0 ; V_180 < V_179 ; ++ V_180 ) {
if ( F_12 ( V_5 , V_566 ) & V_567 )
break;
F_66 ( 10 ) ;
}
if ( V_180 == V_179 ) {
F_42 ( V_5 -> V_25 , L_26 ) ;
V_191 -> V_568 ( V_5 , V_191 ) ;
return - V_300 ;
}
F_3 ( V_5 , V_569 | V_570 |
V_571 ,
V_572 ) ;
return V_193 ;
}
static int F_188 ( struct V_4 * V_5 , struct V_190 * V_191 )
{
const struct V_203 * V_204 = & V_191 -> V_202 -> V_204 ;
unsigned V_573 = V_574 | V_575 ;
int V_193 ;
F_3 ( V_5 , V_576 , V_572 ) ;
switch ( V_204 -> V_406 ) {
case V_405 :
V_573 |=
F_122 ( V_204 -> V_414 ) &
V_565 ;
break;
default:
F_2 () ;
break;
}
if ( V_204 -> V_414 & V_412 )
V_573 |= V_577 ;
F_3 ( V_5 , V_573 , V_578 ) ;
if ( V_191 -> V_553 ) {
F_3 ( V_5 , V_191 -> V_559 , V_579 ) ;
F_3 ( V_5 , V_580 , V_572 ) ;
F_3 ( V_5 , V_191 -> V_553 , V_581 ) ;
} else {
F_42 ( V_5 -> V_25 ,
L_27 ) ;
return - V_300 ;
}
V_193 = F_57 ( V_5 ) ;
if ( V_193 < 0 )
return V_193 ;
V_191 -> V_202 -> V_422 = F_187 ;
return 0 ;
}
static int F_189 ( struct V_4 * V_5 , struct V_190 * V_191 )
{
F_3 ( V_5 , V_582 | V_583 |
V_584 |
V_585 ,
V_572 ) ;
F_3 ( V_5 , 0 , V_581 ) ;
F_63 ( V_5 ) ;
return 0 ;
}
static void F_190 ( struct V_4 * V_5 )
{
struct V_124 * V_125 = V_5 -> V_126 ;
unsigned V_586 ;
struct V_190 * V_191 = & V_5 -> V_241 [ V_587 ] ;
#ifdef F_58
unsigned long V_127 ;
#endif
if ( ! V_125 -> V_128 )
return;
#ifdef F_58
F_36 ( & V_125 -> V_156 , V_127 ) ;
if ( V_125 -> V_172 ) {
unsigned V_588 =
F_191 ( V_125 -> V_172 ) ;
if ( V_588 & V_255 ) {
F_4 ( V_589 ,
V_125 -> V_130 -> V_590 +
F_192 ( V_125 -> V_172 -> V_144 ) ) ;
}
F_77 ( V_125 -> V_172 , V_191 ) ;
}
F_37 ( & V_125 -> V_156 , V_127 ) ;
#endif
V_586 = F_12 ( V_5 , V_566 ) ;
if ( V_586 & ( V_591 | V_592 ) ) {
F_3 ( V_5 , V_593 ,
V_572 ) ;
V_191 -> V_202 -> V_217 |= V_218 ;
}
if ( V_586 & V_594 ) {
F_3 ( V_5 , V_584 ,
V_572 ) ;
}
F_96 ( V_5 , V_191 ) ;
}
static int F_193 ( struct V_4 * V_5 ,
struct V_190 * V_191 ,
unsigned char V_595 ,
unsigned char * V_596 )
{
struct V_124 * V_125 = V_5 -> V_126 ;
unsigned int V_597 ;
int V_209 = 0 , V_328 = 20 ;
V_125 -> V_557 &= ~ V_598 ;
V_125 -> V_557 |= F_194 ( V_595 ) ;
F_35 ( V_5 , V_125 -> V_557 , V_560 ) ;
V_597 = F_39 ( V_5 , V_118 ) ;
if ( V_597 & V_599 ) {
V_209 = - V_159 ;
goto Error;
}
V_125 -> V_551 |= V_600 ;
F_35 ( V_5 , V_125 -> V_551 , V_77 ) ;
V_125 -> V_551 &= ~ V_600 ;
while ( ( V_597 = F_39 ( V_5 , V_118 ) ) &
V_599 ) {
F_66 ( ( V_125 -> V_556 + 999 ) / 1000 ) ;
if ( -- V_328 < 0 ) {
F_42 ( V_5 -> V_25 ,
L_28 ,
V_26 ) ;
V_209 = - V_387 ;
goto Error;
}
}
F_66 ( ( V_125 -> V_556 + 999 ) / 1000 ) ;
if ( V_596 != NULL )
* V_596 = F_39 ( V_5 , V_116 ) ;
Error:
F_35 ( V_5 , V_125 -> V_551 , V_77 ) ;
return V_209 ;
}
static int F_195 ( struct V_4 * V_5 ,
struct V_190 * V_191 ,
unsigned char V_595 ,
unsigned char * V_596 )
{
struct V_124 * V_125 = V_5 -> V_126 ;
unsigned char V_383 , V_601 = 0 ;
F_66 ( ( V_125 -> V_556 + 999 ) / 1000 ) ;
for ( V_383 = 0x80 ; V_383 ; V_383 >>= 1 ) {
V_125 -> V_557 &= ~ V_555 ;
if ( V_595 & V_383 )
V_125 -> V_557 |= V_555 ;
F_35 ( V_5 , V_125 -> V_557 , V_560 ) ;
V_125 -> V_551 |= V_602 ;
F_35 ( V_5 , V_125 -> V_551 , V_77 ) ;
F_66 ( ( V_125 -> V_556 + 999 ) / 2000 ) ;
V_125 -> V_551 &= ~ V_602 ;
F_35 ( V_5 , V_125 -> V_551 , V_77 ) ;
F_66 ( ( V_125 -> V_556 + 999 ) / 2000 ) ;
if ( F_39 ( V_5 , V_561 ) & V_554 )
V_601 |= V_383 ;
}
if ( V_596 )
* V_596 = V_601 ;
return 0 ;
}
static int F_196 ( struct V_4 * V_5 ,
struct V_190 * V_191 ,
struct V_381 * V_382 ,
unsigned int * V_6 )
{
struct V_124 * V_125 = V_5 -> V_126 ;
int V_209 = V_382 -> V_200 ;
unsigned char V_603 , V_604 = 0 ;
if ( V_382 -> V_200 != 2 )
return - V_420 ;
switch ( V_6 [ 0 ] ) {
case V_605 :
V_125 -> V_606 = 1 ;
V_125 -> V_551 |= V_607 ;
if ( V_6 [ 1 ] == V_608 ) {
V_125 -> V_606 = 0 ;
V_125 -> V_551 &= ~ ( V_607 |
V_602 ) ;
V_6 [ 1 ] = V_608 ;
V_125 -> V_556 = V_6 [ 1 ] ;
} else if ( V_6 [ 1 ] <= V_609 ) {
V_125 -> V_551 &= ~ V_610 ;
V_125 -> V_611 |= V_612 ;
V_125 -> V_611 &= ~ V_613 ;
V_6 [ 1 ] = V_609 ;
V_125 -> V_556 = V_6 [ 1 ] ;
} else if ( V_6 [ 1 ] <= V_614 ) {
V_125 -> V_551 &= ~ V_610 ;
V_125 -> V_611 |= V_612 |
V_613 ;
V_6 [ 1 ] = V_614 ;
V_125 -> V_556 = V_6 [ 1 ] ;
} else if ( V_6 [ 1 ] <= V_615 ) {
V_125 -> V_551 |= V_610 ;
V_125 -> V_611 |= V_612 |
V_613 ;
V_6 [ 1 ] = V_615 ;
V_125 -> V_556 = V_6 [ 1 ] ;
} else {
V_125 -> V_551 &= ~ ( V_607 |
V_602 ) ;
V_125 -> V_606 = 0 ;
V_6 [ 1 ] = ( V_6 [ 1 ] / 1000 ) * 1000 ;
V_125 -> V_556 = V_6 [ 1 ] ;
}
F_35 ( V_5 , V_125 -> V_551 , V_77 ) ;
F_35 ( V_5 , V_125 -> V_611 ,
V_71 ) ;
return 1 ;
break;
case V_616 :
if ( V_125 -> V_556 == 0 )
return - V_420 ;
V_603 = V_6 [ 1 ] & 0xFF ;
if ( V_125 -> V_606 ) {
V_209 = F_193 ( V_5 , V_191 , V_603 ,
& V_604 ) ;
} else if ( V_125 -> V_556 > 0 ) {
V_209 = F_195 ( V_5 , V_191 , V_603 ,
& V_604 ) ;
} else {
F_42 ( V_5 -> V_25 , L_29 ,
V_26 ) ;
return - V_420 ;
}
if ( V_209 < 0 )
return V_209 ;
V_6 [ 1 ] = V_604 & 0xFF ;
return V_382 -> V_200 ;
break;
default:
return - V_420 ;
}
}
static void F_197 ( struct V_4 * V_5 , struct V_190 * V_191 )
{
int V_180 ;
for ( V_180 = 0 ; V_180 < V_191 -> V_332 ; V_180 ++ ) {
F_68 ( V_5 , F_159 ( V_180 ) | 0x0 ,
V_617 ) ;
}
F_68 ( V_5 , 0x0 , V_618 ) ;
}
static unsigned F_198 ( enum V_619 V_7 )
{
unsigned V_620 ;
switch ( V_7 ) {
case V_621 :
V_620 = F_27 ( 0 ) ;
break;
case V_622 :
V_620 = F_27 ( 1 ) ;
break;
case V_623 :
V_620 = F_28 ( 0 ) ;
break;
case V_624 :
V_620 = F_28 ( 1 ) ;
break;
case V_625 :
V_620 = F_32 ( 0 ) ;
break;
case V_626 :
V_620 = F_32 ( 1 ) ;
break;
case V_627 :
V_620 = F_33 ( 0 ) ;
break;
case V_628 :
V_620 = F_33 ( 1 ) ;
break;
case V_629 :
V_620 = F_30 ( 0 ) ;
break;
case V_630 :
V_620 = F_30 ( 1 ) ;
break;
case V_631 :
V_620 = F_22 ( 0 ) ;
break;
case V_632 :
V_620 = F_22 ( 1 ) ;
break;
case V_633 :
V_620 = F_23 ( 0 ) ;
break;
case V_634 :
V_620 = F_23 ( 1 ) ;
break;
case V_635 :
V_620 = F_29 ( 0 ) ;
break;
case V_636 :
V_620 = F_29 ( 1 ) ;
break;
case V_637 :
V_620 = V_122 ;
break;
case V_638 :
V_620 = V_98 ;
break;
case V_639 :
V_620 = V_118 ;
break;
case V_640 :
V_620 = V_120 ;
break;
case V_641 :
V_620 = V_86 ;
break;
case V_642 :
V_620 = V_90 ;
break;
case V_643 :
V_620 = V_110 ;
break;
case V_644 :
V_620 = V_112 ;
break;
case V_645 :
V_620 = V_88 ;
break;
case V_646 :
V_620 = V_92 ;
break;
default:
F_199 ( L_30 ,
V_26 , V_7 ) ;
F_2 () ;
return 0 ;
}
return V_620 ;
}
static void F_200 ( struct V_647 * V_648 , unsigned V_188 ,
enum V_619 V_7 )
{
struct V_4 * V_5 = V_648 -> V_169 -> V_5 ;
unsigned V_620 ;
static const unsigned V_649 = V_650 | V_651 ;
static const unsigned V_652 =
V_653 | V_654 ;
static const unsigned V_655 =
V_656 | V_657 ;
switch ( V_7 ) {
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
case V_672 :
F_6 ( V_5 , V_188 , V_673 ) ;
break;
case V_631 :
case V_632 :
case V_633 :
case V_634 :
V_620 = F_198 ( V_7 ) ;
F_38 ( V_5 , V_188 , V_620 ) ;
break;
case V_645 :
F_52 ( V_188 & ~ V_652 ) ;
F_41 ( V_5 , V_88 ,
V_652 , V_188 ) ;
break;
case V_646 :
F_52 ( V_188 & ~ V_655 ) ;
F_41 ( V_5 , V_92 ,
V_655 , V_188 ) ;
break;
case V_638 :
F_52 ( V_188 & ~ V_649 ) ;
default:
V_620 = F_198 ( V_7 ) ;
F_35 ( V_5 , V_188 , V_620 ) ;
}
}
static unsigned F_201 ( struct V_647 * V_648 ,
enum V_619 V_7 )
{
struct V_4 * V_5 = V_648 -> V_169 -> V_5 ;
unsigned V_620 ;
switch ( V_7 ) {
case V_674 :
return F_15 ( V_5 , V_675 ) ;
case V_676 :
return F_15 ( V_5 , V_677 ) ;
case V_625 :
case V_626 :
case V_627 :
case V_628 :
V_620 = F_198 ( V_7 ) ;
return F_40 ( V_5 , V_620 ) ;
default:
V_620 = F_198 ( V_7 ) ;
return F_39 ( V_5 , V_620 ) ;
}
return 0 ;
}
static int F_202 ( struct V_4 * V_5 ,
struct V_190 * V_191 ,
struct V_381 * V_382 ,
unsigned int * V_6 )
{
struct V_124 * V_125 = V_5 -> V_126 ;
unsigned int V_133 = V_125 -> V_611 & V_678 ;
int V_180 ;
for ( V_180 = 0 ; V_180 < V_382 -> V_200 ; V_180 ++ )
V_6 [ V_180 ] = V_133 ;
return V_382 -> V_200 ;
}
static int F_203 ( struct V_4 * V_5 ,
struct V_190 * V_191 ,
struct V_381 * V_382 ,
unsigned int * V_6 )
{
struct V_124 * V_125 = V_5 -> V_126 ;
if ( V_382 -> V_200 ) {
V_125 -> V_611 &= ~ V_679 ;
F_35 ( V_5 , V_125 -> V_611 ,
V_71 ) ;
V_125 -> V_611 &= ~ V_678 ;
V_125 -> V_611 |= F_204 ( V_6 [ V_382 -> V_200 - 1 ] ) ;
V_125 -> V_611 |= V_679 ;
F_35 ( V_5 , V_125 -> V_611 ,
V_71 ) ;
}
return V_382 -> V_200 ;
}
static int F_205 ( struct V_4 * V_5 ,
struct V_190 * V_191 ,
struct V_381 * V_382 ,
unsigned int * V_6 )
{
struct V_124 * V_125 = V_5 -> V_126 ;
switch ( V_6 [ 0 ] ) {
case V_680 :
switch ( V_6 [ 1 ] ) {
case V_681 :
V_125 -> V_611 &= ~ V_682 ;
break;
case V_683 :
V_125 -> V_611 |= V_682 ;
break;
default:
return - V_420 ;
}
F_35 ( V_5 , V_125 -> V_611 ,
V_71 ) ;
break;
case V_684 :
if ( V_125 -> V_611 & V_682 ) {
V_6 [ 1 ] = V_683 ;
V_6 [ 2 ] = V_685 ;
} else {
V_6 [ 1 ] = V_681 ;
V_6 [ 2 ] = V_686 * 2 ;
}
break;
default:
return - V_420 ;
}
return V_382 -> V_200 ;
}
static int F_206 ( struct V_4 * V_5 ,
int V_160 , int V_687 , int V_6 , unsigned long V_9 )
{
if ( V_160 ) {
F_9 ( V_5 , V_6 , V_9 + 2 * V_687 ) ;
return 0 ;
}
return F_18 ( V_5 , V_9 + 2 * V_687 ) ;
}
static int F_207 ( struct V_4 * V_5 , unsigned int * V_6 )
{
struct V_124 * V_125 = V_5 -> V_126 ;
V_6 [ 1 ] = V_125 -> V_688 * V_125 -> V_393 ;
V_6 [ 2 ] = V_125 -> V_689 * V_125 -> V_393 ;
return 3 ;
}
static int F_208 ( struct V_4 * V_5 ,
struct V_190 * V_191 ,
struct V_381 * V_382 ,
unsigned int * V_6 )
{
struct V_124 * V_125 = V_5 -> V_126 ;
unsigned V_690 , V_691 ;
switch ( V_6 [ 0 ] ) {
case V_692 :
switch ( V_6 [ 1 ] ) {
case V_392 :
V_690 =
( V_6 [ 2 ] +
V_125 -> V_393 / 2 ) / V_125 -> V_393 ;
break;
case V_394 :
V_690 = V_6 [ 2 ] / V_125 -> V_393 ;
break;
case V_395 :
V_690 =
( V_6 [ 2 ] + V_125 -> V_393 -
1 ) / V_125 -> V_393 ;
break;
default:
return - V_420 ;
}
switch ( V_6 [ 3 ] ) {
case V_392 :
V_691 =
( V_6 [ 4 ] +
V_125 -> V_393 / 2 ) / V_125 -> V_393 ;
break;
case V_394 :
V_691 = V_6 [ 4 ] / V_125 -> V_393 ;
break;
case V_395 :
V_691 =
( V_6 [ 4 ] + V_125 -> V_393 -
1 ) / V_125 -> V_393 ;
break;
default:
return - V_420 ;
}
if ( V_690 * V_125 -> V_393 != V_6 [ 2 ] ||
V_691 * V_125 -> V_393 != V_6 [ 4 ] ) {
V_6 [ 2 ] = V_690 * V_125 -> V_393 ;
V_6 [ 4 ] = V_691 * V_125 -> V_393 ;
return - V_693 ;
}
F_3 ( V_5 , F_209 ( V_690 ) |
F_210 ( V_691 ) ,
V_694 ) ;
V_125 -> V_688 = V_690 ;
V_125 -> V_689 = V_691 ;
return 5 ;
case V_695 :
return F_207 ( V_5 , V_6 ) ;
default:
return - V_420 ;
}
return 0 ;
}
static int F_211 ( struct V_4 * V_5 ,
struct V_190 * V_191 ,
struct V_381 * V_382 ,
unsigned int * V_6 )
{
struct V_124 * V_125 = V_5 -> V_126 ;
unsigned V_690 , V_691 ;
switch ( V_6 [ 0 ] ) {
case V_692 :
switch ( V_6 [ 1 ] ) {
case V_392 :
V_690 =
( V_6 [ 2 ] +
V_125 -> V_393 / 2 ) / V_125 -> V_393 ;
break;
case V_394 :
V_690 = V_6 [ 2 ] / V_125 -> V_393 ;
break;
case V_395 :
V_690 =
( V_6 [ 2 ] + V_125 -> V_393 -
1 ) / V_125 -> V_393 ;
break;
default:
return - V_420 ;
}
switch ( V_6 [ 3 ] ) {
case V_392 :
V_691 =
( V_6 [ 4 ] +
V_125 -> V_393 / 2 ) / V_125 -> V_393 ;
break;
case V_394 :
V_691 = V_6 [ 4 ] / V_125 -> V_393 ;
break;
case V_395 :
V_691 =
( V_6 [ 4 ] + V_125 -> V_393 -
1 ) / V_125 -> V_393 ;
break;
default:
return - V_420 ;
}
if ( V_690 * V_125 -> V_393 != V_6 [ 2 ] ||
V_691 * V_125 -> V_393 != V_6 [ 4 ] ) {
V_6 [ 2 ] = V_690 * V_125 -> V_393 ;
V_6 [ 4 ] = V_691 * V_125 -> V_393 ;
return - V_693 ;
}
F_3 ( V_5 , V_690 , V_696 ) ;
V_125 -> V_688 = V_690 ;
F_3 ( V_5 , V_691 , V_697 ) ;
V_125 -> V_689 = V_691 ;
return 5 ;
case V_695 :
return F_207 ( V_5 , V_6 ) ;
default:
return - V_420 ;
}
return 0 ;
}
static int F_212 ( int V_185 , int V_133 , int * V_698 )
{
V_185 ++ ;
* V_698 = ( ( V_185 & 0x1 ) << 11 ) |
( ( V_185 & 0x2 ) << 9 ) |
( ( V_185 & 0x4 ) << 7 ) | ( ( V_185 & 0x8 ) << 5 ) | ( V_133 & 0xff ) ;
return 12 ;
}
static int F_213 ( int V_185 , int V_133 , int * V_698 )
{
* V_698 = ( ( V_185 & 0x7 ) << 8 ) | ( V_133 & 0xff ) ;
return 11 ;
}
static int F_214 ( int V_185 , int V_133 , int * V_698 )
{
* V_698 = V_133 & 0xfff ;
return 12 ;
}
static int F_215 ( int V_185 , int V_133 , int * V_698 )
{
* V_698 = ( V_133 & 0xfff ) | ( V_185 ? 0xc000 : 0xa000 ) ;
return 16 ;
}
static int F_216 ( int V_185 , int V_133 , int * V_698 )
{
* V_698 = ( ( V_185 & 0xf ) << 8 ) | ( V_133 & 0xff ) ;
return 12 ;
}
static int F_217 ( int V_185 , int V_133 , int * V_698 )
{
* V_698 = ( ( V_185 + 1 ) << 8 ) | ( V_133 & 0xff ) ;
return 12 ;
}
static void F_218 ( struct V_4 * V_5 , int V_185 , int V_133 )
{
const struct V_219 * V_220 = V_5 -> V_221 ;
struct V_124 * V_125 = V_5 -> V_126 ;
unsigned int V_699 = 0 , V_188 = 0 , V_700 , V_698 = 0 ;
int V_180 ;
int type ;
if ( V_125 -> V_701 [ V_185 ] == V_133 )
return;
V_125 -> V_701 [ V_185 ] = V_133 ;
for ( V_180 = 0 ; V_180 < 3 ; V_180 ++ ) {
type = V_220 -> V_702 [ V_180 ] ;
if ( type == V_703 )
break;
if ( V_185 < V_701 [ type ] . V_468 ) {
V_188 = V_701 [ type ] . F_219 ( V_185 , V_133 , & V_698 ) ;
V_699 = F_220 ( V_180 ) ;
break;
}
V_185 -= V_701 [ type ] . V_468 ;
}
for ( V_700 = 1 << ( V_188 - 1 ) ; V_700 ; V_700 >>= 1 ) {
F_9 ( V_5 , ( ( V_700 & V_698 ) ? 0x02 : 0 ) , V_704 ) ;
F_66 ( 1 ) ;
F_9 ( V_5 , 1 | ( ( V_700 & V_698 ) ? 0x02 : 0 ) ,
V_704 ) ;
F_66 ( 1 ) ;
}
F_9 ( V_5 , V_699 , V_704 ) ;
F_66 ( 1 ) ;
F_9 ( V_5 , 0 , V_704 ) ;
}
static int F_221 ( struct V_4 * V_5 ,
struct V_190 * V_191 ,
struct V_381 * V_382 ,
unsigned int * V_6 )
{
F_218 ( V_5 , F_122 ( V_382 -> V_385 ) , V_6 [ 0 ] ) ;
return 1 ;
}
static int F_222 ( struct V_4 * V_5 ,
struct V_190 * V_191 ,
struct V_381 * V_382 ,
unsigned int * V_6 )
{
struct V_124 * V_125 = V_5 -> V_126 ;
V_6 [ 0 ] = V_125 -> V_701 [ F_122 ( V_382 -> V_385 ) ] ;
return 1 ;
}
static void F_223 ( struct V_4 * V_5 , struct V_190 * V_191 )
{
const struct V_219 * V_220 = V_5 -> V_221 ;
struct V_124 * V_125 = V_5 -> V_126 ;
int V_180 , V_705 ;
int V_706 ;
int V_468 = 0 ;
int V_707 ;
int V_708 = 0 ;
int type ;
int V_205 ;
type = V_220 -> V_702 [ 0 ] ;
if ( type == V_703 )
return;
V_707 = V_701 [ type ] . V_707 ;
for ( V_180 = 0 ; V_180 < 3 ; V_180 ++ ) {
type = V_220 -> V_702 [ V_180 ] ;
if ( type == V_703 )
break;
if ( V_701 [ type ] . V_707 != V_707 )
V_708 = 1 ;
V_468 += V_701 [ type ] . V_468 ;
}
V_706 = V_180 ;
V_191 -> V_332 = V_468 ;
if ( V_708 ) {
unsigned int * V_709 ;
if ( V_468 > V_710 )
F_42 ( V_5 -> V_25 ,
L_31 ) ;
V_191 -> V_709 = V_709 = V_125 -> V_711 ;
V_205 = 0 ;
for ( V_180 = 0 ; V_180 < V_706 ; V_180 ++ ) {
type = V_220 -> V_702 [ V_180 ] ;
for ( V_705 = 0 ; V_705 < V_701 [ type ] . V_468 ; V_705 ++ ) {
V_709 [ V_205 ] =
( 1 << V_701 [ type ] . V_707 ) - 1 ;
V_205 ++ ;
}
}
for ( V_205 = 0 ; V_205 < V_191 -> V_332 ; V_205 ++ )
F_218 ( V_5 , V_180 , V_191 -> V_709 [ V_180 ] / 2 ) ;
} else {
type = V_220 -> V_702 [ 0 ] ;
V_191 -> V_364 = ( 1 << V_701 [ type ] . V_707 ) - 1 ;
for ( V_205 = 0 ; V_205 < V_191 -> V_332 ; V_205 ++ )
F_218 ( V_5 , V_180 , V_191 -> V_364 / 2 ) ;
}
}
static int F_224 ( struct V_4 * V_5 , int V_185 )
{
int V_700 ;
int V_698 ;
V_698 = 0x0300 | ( ( V_185 & 0x100 ) << 3 ) | ( V_185 & 0xff ) ;
F_9 ( V_5 , 0x04 , V_704 ) ;
for ( V_700 = 0x8000 ; V_700 ; V_700 >>= 1 ) {
F_9 ( V_5 , 0x04 | ( ( V_700 & V_698 ) ? 0x02 : 0 ) ,
V_704 ) ;
F_9 ( V_5 , 0x05 | ( ( V_700 & V_698 ) ? 0x02 : 0 ) ,
V_704 ) ;
}
V_698 = 0 ;
for ( V_700 = 0x80 ; V_700 ; V_700 >>= 1 ) {
F_9 ( V_5 , 0x04 , V_704 ) ;
F_9 ( V_5 , 0x05 , V_704 ) ;
V_698 |= ( ( F_18 ( V_5 , V_234 ) & V_712 ) ? V_700 : 0 ) ;
}
F_9 ( V_5 , 0x00 , V_704 ) ;
return V_698 ;
}
static int F_225 ( struct V_4 * V_5 ,
struct V_190 * V_191 ,
struct V_381 * V_382 ,
unsigned int * V_6 )
{
V_6 [ 0 ] = F_224 ( V_5 , F_122 ( V_382 -> V_385 ) ) ;
return 1 ;
}
static int F_226 ( struct V_4 * V_5 ,
struct V_190 * V_191 ,
struct V_381 * V_382 ,
unsigned int * V_6 )
{
struct V_124 * V_125 = V_5 -> V_126 ;
V_6 [ 0 ] = V_125 -> V_713 [ F_122 ( V_382 -> V_385 ) ] ;
return 1 ;
}
static unsigned F_227 ( struct V_4 * V_5 ,
unsigned V_205 )
{
switch ( V_205 ) {
case 0 :
return V_714 ;
case 1 :
return V_715 ;
case 2 :
return V_716 ;
case 3 :
return V_717 ;
case 4 :
return V_718 ;
case 5 :
return V_719 ;
case 6 :
return V_720 ;
case 7 :
return V_721 ;
case 8 :
return V_722 ;
case 9 :
return V_723 ;
default:
F_42 ( V_5 -> V_25 ,
L_32 , V_26 ) ;
break;
}
return 0 ;
}
static int F_228 ( struct V_4 * V_5 ,
unsigned V_205 , unsigned V_724 )
{
if ( V_724 != F_227 ( V_5 , V_205 ) )
return - V_420 ;
return 2 ;
}
static unsigned F_229 ( struct V_4 * V_5 ,
unsigned V_205 )
{
struct V_124 * V_125 = V_5 -> V_126 ;
const unsigned V_725 = V_205 / 3 ;
return F_230 ( V_205 ,
V_125 -> V_726 [ V_725 ] ) ;
}
static int F_231 ( struct V_4 * V_5 ,
unsigned V_205 , unsigned V_724 )
{
struct V_124 * V_125 = V_5 -> V_126 ;
unsigned V_727 ;
unsigned V_725 ;
if ( ( V_724 & 0x1f ) != V_724 )
return - V_420 ;
V_727 = 1 + V_205 / 3 ;
V_725 = V_727 - 1 ;
V_125 -> V_726 [ V_725 ] &=
~ F_232 ( V_205 ) ;
V_125 -> V_726 [ V_725 ] |=
F_233 ( V_205 , V_724 ) ;
F_6 ( V_5 , V_125 -> V_726 [ V_725 ] ,
F_234 ( V_727 ) ) ;
return 2 ;
}
static unsigned F_235 ( struct V_4 * V_5 , unsigned V_205 )
{
struct V_124 * V_125 = V_5 -> V_126 ;
return ( V_125 -> V_128 )
? F_229 ( V_5 , V_205 )
: F_227 ( V_5 , V_205 ) ;
}
static int F_236 ( struct V_4 * V_5 , unsigned V_205 ,
unsigned V_724 )
{
struct V_124 * V_125 = V_5 -> V_126 ;
return ( V_125 -> V_128 )
? F_231 ( V_5 , V_205 , V_724 )
: F_228 ( V_5 , V_205 , V_724 ) ;
}
static int F_237 ( struct V_4 * V_5 ,
unsigned V_728 ,
enum V_729 V_730 )
{
struct V_124 * V_125 = V_5 -> V_126 ;
unsigned V_188 ;
if ( ! V_125 -> V_128 )
return - V_731 ;
V_188 = F_12 ( V_5 , V_732 ) ;
V_188 &= ~ F_238 ( V_728 ) ;
V_188 |= F_239 ( V_728 , V_730 ) ;
F_3 ( V_5 , V_188 , V_732 ) ;
return 0 ;
}
static int F_240 ( struct V_4 * V_5 ,
struct V_190 * V_191 ,
struct V_381 * V_382 ,
unsigned int * V_6 )
{
struct V_124 * V_125 = V_5 -> V_126 ;
unsigned int V_205 ;
if ( V_382 -> V_200 < 1 )
return - V_420 ;
V_205 = F_122 ( V_382 -> V_385 ) ;
switch ( V_6 [ 0 ] ) {
case V_164 :
F_71 ( V_5 , V_96 , 1 << V_205 , 1 ) ;
break;
case V_161 :
F_71 ( V_5 , V_96 , 1 << V_205 , 0 ) ;
break;
case V_733 :
V_6 [ 1 ] =
( V_125 -> V_139 & ( 1 << V_205 ) ) ?
V_164 : V_161 ;
return 0 ;
case V_734 :
return F_236 ( V_5 , V_205 , V_6 [ 1 ] ) ;
case V_735 :
V_6 [ 1 ] = F_235 ( V_5 , V_205 ) ;
break;
case V_736 :
return F_237 ( V_5 , V_205 , V_6 [ 1 ] ) ;
default:
return - V_420 ;
}
return 0 ;
}
static int F_241 ( struct V_4 * V_5 ,
struct V_190 * V_191 ,
struct V_381 * V_382 ,
unsigned int * V_6 )
{
struct V_124 * V_125 = V_5 -> V_126 ;
if ( ! V_125 -> V_128 )
return - V_731 ;
if ( F_180 ( V_191 , V_6 ) )
F_6 ( V_5 , V_191 -> V_559 , V_737 ) ;
V_6 [ 1 ] = F_15 ( V_5 , V_738 ) ;
return V_382 -> V_200 ;
}
static int F_242 ( struct V_4 * V_5 )
{
unsigned short V_252 ;
const int V_179 = V_739 ;
int V_180 ;
for ( V_180 = 0 ; V_180 < V_179 ; V_180 ++ ) {
V_252 = F_70 ( V_5 , V_740 ) ;
if ( ( V_252 & V_741 ) == 0 )
break;
F_243 ( V_742 ) ;
if ( F_244 ( 1 ) )
return - V_300 ;
}
if ( V_180 == V_179 ) {
F_42 ( V_5 -> V_25 , L_20 , V_26 ) ;
return - V_387 ;
}
return 0 ;
}
static void F_245 ( struct V_4 * V_5 , unsigned short V_189 )
{
static const int V_179 = 100 ;
int V_180 ;
F_68 ( V_5 , V_189 , V_743 ) ;
for ( V_180 = 0 ; V_180 < V_179 ; V_180 ++ ) {
if ( ( F_70 ( V_5 , V_740 ) & V_741 ) )
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
unsigned short V_252 ;
F_245 ( V_5 , V_744 | V_745 ) ;
V_193 = F_242 ( V_5 ) ;
if ( V_193 ) {
F_42 ( V_5 -> V_25 ,
L_34 ) ;
return - V_387 ;
}
V_252 = F_70 ( V_5 , V_740 ) ;
if ( V_252 & V_746 ) {
F_42 ( V_5 -> V_25 ,
L_35 ) ;
return - V_300 ;
}
if ( V_252 & V_747 ) {
F_42 ( V_5 -> V_25 ,
L_36 ) ;
}
if ( V_6 ) {
* V_6 = F_70 ( V_5 , V_748 ) ;
* V_6 ^= ( 1 << 15 ) ;
}
return 0 ;
}
static int F_247 ( struct V_4 * V_5 ,
struct V_190 * V_191 ,
struct V_381 * V_382 ,
unsigned int * V_6 )
{
int V_200 , V_193 ;
unsigned short V_749 ;
unsigned int V_750 ;
const unsigned int V_751 = 0x1000 ;
if ( V_382 -> V_385 & V_337 )
V_750 = V_751 ;
else
V_750 = F_122 ( V_382 -> V_385 ) ;
F_68 ( V_5 , V_750 , V_752 ) ;
for ( V_200 = 0 ; V_200 < V_382 -> V_200 ; V_200 ++ ) {
V_193 = F_246 ( V_5 , & V_749 ) ;
if ( V_193 < 0 )
return V_193 ;
V_6 [ V_200 ] = V_749 ;
}
return V_382 -> V_200 ;
}
static void F_248 ( struct V_4 * V_5 , unsigned int V_189 ,
unsigned int V_753 )
{
F_68 ( V_5 , ( ( V_189 >> 16 ) & 0xff ) ,
V_754 ) ;
F_68 ( V_5 , ( V_189 & 0xffff ) ,
V_755 ) ;
V_753 &= V_756 ;
F_245 ( V_5 , V_744 | V_753 ) ;
if ( F_242 ( V_5 ) )
F_42 ( V_5 -> V_25 ,
L_37 , V_26 ) ;
}
static int F_249 ( struct V_4 * V_5 )
{
unsigned int V_351 =
V_757 | V_758 ;
#if 1
F_248 ( V_5 , V_351 | V_759 ,
V_760 ) ;
F_246 ( V_5 , NULL ) ;
#else
F_248 ( V_5 , 0x400000 , V_761 ) ;
F_248 ( V_5 , V_351 | V_762 ,
V_760 ) ;
if ( F_242 ( V_5 ) )
F_42 ( V_5 -> V_25 ,
L_37 , V_26 ) ;
#endif
return 0 ;
}
static int F_250 ( unsigned V_763 ,
unsigned * V_764 ,
unsigned * V_765 ,
unsigned * V_766 )
{
unsigned div ;
unsigned V_767 = 1 ;
static const unsigned V_768 = 0x10 ;
unsigned V_769 ;
unsigned V_770 = 1 ;
static const unsigned V_771 = 0x100 ;
static const unsigned V_772 = 1000 ;
const unsigned V_773 = V_763 * V_772 ;
static const unsigned V_774 = 12500 ;
static const unsigned V_775 = 4 ;
int V_776 = 0 ;
for ( div = 1 ; div <= V_768 ; ++ div ) {
for ( V_769 = 1 ; V_769 <= V_771 ; ++ V_769 ) {
unsigned V_777 =
( V_773 * div ) / V_769 ;
if ( abs ( V_777 - V_774 ) <
abs ( V_776 - V_774 ) ) {
V_776 = V_777 ;
V_767 = div ;
V_770 = V_769 ;
}
}
}
if ( V_776 == 0 )
return - V_300 ;
* V_764 = V_767 ;
* V_765 = V_770 ;
* V_766 =
( V_776 * V_775 +
( V_772 / 2 ) ) / V_772 ;
return 0 ;
}
static int F_251 ( struct V_4 * V_5 ,
unsigned V_724 , unsigned V_778 )
{
struct V_124 * V_125 = V_5 -> V_126 ;
static const unsigned V_779 = 50 ;
static const unsigned V_780 = 1000 ;
static const unsigned V_179 = 1000 ;
unsigned V_781 ;
unsigned V_764 ;
unsigned V_765 ;
unsigned V_180 ;
int V_193 ;
if ( V_724 == V_782 )
V_778 = 100 ;
if ( V_778 < V_779 || V_778 > V_780 ) {
F_42 ( V_5 -> V_25 ,
L_38 ,
V_26 , V_779 , V_780 ) ;
return - V_420 ;
}
V_125 -> V_783 &= ~ V_784 ;
F_35 ( V_5 , V_125 -> V_783 ,
V_104 ) ;
V_781 =
V_785 | V_786 ;
V_125 -> V_787 |=
V_788 | V_789 ;
V_125 -> V_787 &= ~ V_790 ;
switch ( V_724 ) {
case V_791 :
V_125 -> V_787 |=
V_792 ;
break;
case V_782 :
V_125 -> V_787 |=
V_793 ;
break;
default:
{
unsigned V_794 ;
static const unsigned V_795 = 7 ;
for ( V_794 = 0 ; V_794 <= V_795 ;
++ V_794 ) {
if ( V_724 ==
F_252 ( V_794 ) ) {
V_125 -> V_787 |=
F_253
( V_794 ) ;
break;
}
}
if ( V_794 > V_795 )
return - V_420 ;
}
break;
}
V_193 = F_250 ( V_778 ,
& V_764 ,
& V_765 ,
& V_125 -> V_393 ) ;
if ( V_193 < 0 ) {
F_42 ( V_5 -> V_25 ,
L_39 , V_26 ) ;
return V_193 ;
}
F_6 ( V_5 , V_125 -> V_787 , V_796 ) ;
V_781 |=
F_254 ( V_764 ) |
F_255 ( V_765 ) ;
F_6 ( V_5 , V_781 , V_797 ) ;
V_125 -> V_798 = V_724 ;
for ( V_180 = 0 ; V_180 < V_179 ; ++ V_180 ) {
if ( F_15 ( V_5 , V_799 ) & V_800 )
break;
F_66 ( 1 ) ;
}
if ( V_180 == V_179 ) {
F_42 ( V_5 -> V_25 ,
L_40 ,
V_26 , V_724 , V_778 ) ;
return - V_801 ;
}
return 3 ;
}
static int F_256 ( struct V_4 * V_5 ,
unsigned V_724 , unsigned V_778 )
{
struct V_124 * V_125 = V_5 -> V_126 ;
if ( V_724 == V_802 ) {
V_125 -> V_783 &= ~ V_784 ;
F_35 ( V_5 , V_125 -> V_783 ,
V_104 ) ;
V_125 -> V_393 = V_686 ;
if ( V_125 -> V_128 ) {
V_125 -> V_787 &=
~ ( V_788 |
V_789 ) ;
F_6 ( V_5 , V_125 -> V_787 ,
V_796 ) ;
F_6 ( V_5 , 0 , V_797 ) ;
}
V_125 -> V_798 = V_724 ;
} else {
if ( V_125 -> V_128 ) {
return F_251 ( V_5 , V_724 ,
V_778 ) ;
} else {
if ( V_724 == V_803 ) {
V_125 -> V_783 |=
V_784 ;
F_35 ( V_5 ,
V_125 -> V_783 ,
V_104 ) ;
if ( V_778 == 0 ) {
F_42 ( V_5 -> V_25 ,
L_41 ,
V_26 ) ;
return - V_420 ;
}
V_125 -> V_393 = V_778 ;
V_125 -> V_798 = V_724 ;
} else
return - V_420 ;
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
unsigned V_205 , unsigned V_724 )
{
struct V_124 * V_125 = V_5 -> V_126 ;
if ( V_205 >= F_257 ( V_5 ) ) {
if ( V_205 == V_804 ) {
if ( V_724 == V_805 )
return 1 ;
F_42 ( V_5 -> V_25 ,
L_42 ,
V_26 , V_205 , V_804 ) ;
return 0 ;
}
return 0 ;
}
switch ( V_724 ) {
case V_806 :
case V_807 :
case V_808 :
case V_809 :
case V_810 :
case V_811 :
case V_812 :
case V_813 :
case V_814 :
return 1 ;
case V_805 :
return ( V_125 -> V_128 ) ? 1 : 0 ;
default:
return 0 ;
}
}
static int F_259 ( struct V_4 * V_5 ,
unsigned V_205 , unsigned V_724 )
{
struct V_124 * V_125 = V_5 -> V_126 ;
if ( F_258 ( V_5 , V_205 , V_724 ) == 0 )
return - V_420 ;
if ( V_205 < 4 ) {
V_125 -> V_815 &= ~ F_260 ( V_205 ) ;
V_125 -> V_815 |=
F_261 ( V_205 , V_724 ) ;
F_35 ( V_5 , V_125 -> V_815 ,
V_100 ) ;
} else if ( V_205 < 8 ) {
V_125 -> V_816 &= ~ F_260 ( V_205 ) ;
V_125 -> V_816 |=
F_261 ( V_205 , V_724 ) ;
F_35 ( V_5 , V_125 -> V_816 ,
V_102 ) ;
}
return 2 ;
}
static unsigned F_262 ( struct V_4 * V_5 , unsigned V_205 )
{
struct V_124 * V_125 = V_5 -> V_126 ;
if ( V_205 < 4 ) {
return F_263 ( V_205 ,
V_125 -> V_815 ) ;
} else if ( V_205 < F_257 ( V_5 ) ) {
return F_263 ( V_205 ,
V_125 -> V_816 ) ;
} else {
if ( V_205 == V_804 )
return V_805 ;
F_42 ( V_5 -> V_25 , L_43 ,
V_26 ) ;
return 0 ;
}
}
static int F_264 ( struct V_4 * V_5 ,
struct V_190 * V_191 ,
struct V_381 * V_382 ,
unsigned int * V_6 )
{
struct V_124 * V_125 = V_5 -> V_126 ;
unsigned int V_205 = F_122 ( V_382 -> V_385 ) ;
switch ( V_6 [ 0 ] ) {
case V_817 :
if ( V_205 < F_257 ( V_5 ) ) {
V_125 -> V_783 |=
F_265 ( V_205 , V_125 -> V_128 ) ;
} else if ( V_205 == V_804 ) {
V_125 -> V_783 |=
V_818 ;
}
F_35 ( V_5 , V_125 -> V_783 ,
V_104 ) ;
break;
case V_819 :
if ( V_205 < F_257 ( V_5 ) ) {
V_125 -> V_783 &=
~ F_265 ( V_205 , V_125 -> V_128 ) ;
} else if ( V_205 == V_804 ) {
V_125 -> V_783 &=
~ V_818 ;
}
F_35 ( V_5 , V_125 -> V_783 ,
V_104 ) ;
break;
case V_733 :
if ( V_205 < F_257 ( V_5 ) ) {
V_6 [ 1 ] =
( V_125 -> V_783 &
F_265 ( V_205 , V_125 -> V_128 ) )
? V_817
: V_819 ;
} else if ( V_205 == V_804 ) {
V_6 [ 1 ] =
( V_125 -> V_783 &
V_818 )
? V_817 : V_819 ;
}
return 2 ;
case V_680 :
return F_256 ( V_5 , V_6 [ 1 ] , V_6 [ 2 ] ) ;
case V_684 :
V_6 [ 1 ] = V_125 -> V_798 ;
V_6 [ 2 ] = V_125 -> V_393 ;
return 3 ;
case V_734 :
return F_259 ( V_5 , V_205 , V_6 [ 1 ] ) ;
case V_735 :
V_6 [ 1 ] = F_262 ( V_5 , V_205 ) ;
return 2 ;
default:
return - V_420 ;
}
return 1 ;
}
static int F_266 ( struct V_4 * V_5 ,
struct V_190 * V_191 ,
struct V_381 * V_382 ,
unsigned int * V_6 )
{
V_6 [ 1 ] = 0 ;
return V_382 -> V_200 ;
}
static void F_267 ( struct V_4 * V_5 )
{
struct V_124 * V_125 = V_5 -> V_126 ;
V_125 -> V_787 = V_820 ;
if ( F_256 ( V_5 , V_802 , 0 ) < 0 )
F_42 ( V_5 -> V_25 , L_44 ) ;
V_125 -> V_815 =
F_261 ( 0 ,
V_806 ) |
F_261 ( 1 ,
V_807 ) |
F_261 ( 2 ,
V_808 ) |
F_261 ( 3 , V_809 ) ;
F_35 ( V_5 , V_125 -> V_815 ,
V_100 ) ;
V_125 -> V_816 =
F_261 ( 4 ,
V_810 ) |
F_261 ( 5 ,
V_811 ) |
F_261 ( 6 , V_812 ) ;
if ( V_125 -> V_128 )
V_125 -> V_816 |=
F_261 ( 7 , V_805 ) ;
F_35 ( V_5 , V_125 -> V_816 ,
V_102 ) ;
}
static int F_268 ( struct V_4 * V_5 , struct V_190 * V_191 )
{
struct V_647 * V_648 = V_191 -> V_126 ;
int V_193 ;
V_193 = F_55 ( V_5 , V_648 -> V_1 ,
V_161 ) ;
if ( V_193 ) {
F_42 ( V_5 -> V_25 ,
L_45 ) ;
return V_193 ;
}
F_269 ( V_648 ) ;
F_64 ( V_5 , V_648 -> V_1 , 1 ) ;
return F_270 ( V_5 , V_191 ) ;
}
static int F_271 ( struct V_4 * V_5 , struct V_190 * V_191 )
{
struct V_647 * V_648 = V_191 -> V_126 ;
int V_193 ;
V_193 = F_272 ( V_648 ) ;
F_64 ( V_5 , V_648 -> V_1 , 0 ) ;
F_62 ( V_5 , V_648 -> V_1 ) ;
return V_193 ;
}
static T_5 F_273 ( int V_428 , void * V_206 )
{
struct V_4 * V_5 = V_206 ;
unsigned short V_242 ;
unsigned short V_197 ;
unsigned int V_253 = 0 ;
unsigned int V_286 = 0 ;
unsigned long V_127 ;
#ifdef F_58
struct V_124 * V_125 = V_5 -> V_126 ;
struct V_195 * V_130 = V_125 -> V_130 ;
#endif
if ( ! V_5 -> V_821 )
return V_822 ;
F_274 () ;
F_36 ( & V_5 -> V_329 , V_127 ) ;
V_242 = F_39 ( V_5 , V_110 ) ;
V_197 = F_39 ( V_5 , V_112 ) ;
#ifdef F_58
if ( V_130 ) {
struct V_124 * V_125 = V_5 -> V_126 ;
unsigned long V_823 ;
F_36 ( & V_125 -> V_156 , V_823 ) ;
if ( V_125 -> V_157 ) {
V_253 = F_191 ( V_125 -> V_157 ) ;
if ( V_253 & V_255 )
F_4 ( V_589 ,
V_125 -> V_130 -> V_590 +
F_192 ( V_125 ->
V_157 -> V_144 ) ) ;
}
if ( V_125 -> V_162 ) {
V_286 = F_191 ( V_125 -> V_162 ) ;
if ( V_286 & V_255 )
F_4 ( V_589 ,
V_130 -> V_590 +
F_192 ( V_125 ->
V_162 -> V_144 ) ) ;
}
F_37 ( & V_125 -> V_156 , V_823 ) ;
}
#endif
F_97 ( V_5 , V_242 ) ;
F_100 ( V_5 , V_197 ) ;
if ( ( V_242 & V_824 ) || ( V_253 & V_256 ) )
F_98 ( V_5 , V_242 , V_253 ) ;
if ( ( V_197 & V_825 ) || ( V_286 & V_256 ) )
F_101 ( V_5 , V_197 , V_286 ) ;
F_94 ( V_5 , 0 ) ;
F_94 ( V_5 , 1 ) ;
F_190 ( V_5 ) ;
F_37 ( & V_5 -> V_329 , V_127 ) ;
return V_826 ;
}
static int F_275 ( struct V_4 * V_5 )
{
struct V_124 * V_125 ;
V_125 = F_276 ( V_5 , sizeof( * V_125 ) ) ;
if ( ! V_125 )
return - V_827 ;
F_277 ( & V_125 -> V_129 ) ;
F_277 ( & V_125 -> V_136 ) ;
F_277 ( & V_125 -> V_156 ) ;
return 0 ;
}
static int F_278 ( struct V_4 * V_5 ,
unsigned V_828 , unsigned V_829 )
{
const struct V_219 * V_220 = V_5 -> V_221 ;
struct V_124 * V_125 = V_5 -> V_126 ;
struct V_190 * V_191 ;
int V_288 ;
int V_180 ;
if ( V_220 -> V_830 > V_831 ) {
F_42 ( V_5 -> V_25 , L_46 ) ;
return - V_420 ;
}
V_125 -> V_611 = V_832 |
V_612 |
V_833 |
V_834 ;
if ( ! V_125 -> V_212 ) {
V_125 -> V_611 |= ( V_835 |
V_836 ) ;
}
F_35 ( V_5 , V_125 -> V_611 , V_71 ) ;
V_288 = F_279 ( V_5 , V_837 ) ;
if ( V_288 )
return V_288 ;
V_191 = & V_5 -> V_241 [ V_838 ] ;
if ( V_220 -> V_839 ) {
V_191 -> type = V_840 ;
V_191 -> V_296 = V_841 | V_842 | V_843 ;
if ( ! V_125 -> V_225 )
V_191 -> V_296 |= V_844 | V_845 | V_846 ;
if ( V_220 -> V_847 > 0xffff )
V_191 -> V_296 |= V_297 ;
if ( V_125 -> V_128 )
V_191 -> V_296 |= V_848 ;
V_191 -> V_332 = V_220 -> V_839 ;
V_191 -> V_364 = V_220 -> V_847 ;
V_191 -> V_476 = V_849 [ V_220 -> V_340 ] ;
V_191 -> V_850 = F_131 ;
V_191 -> V_851 = F_149 ;
if ( V_5 -> V_428 ) {
V_5 -> V_192 = V_191 ;
V_191 -> V_296 |= V_852 ;
V_191 -> V_853 = 512 ;
V_191 -> V_854 = F_135 ;
V_191 -> V_855 = F_142 ;
V_191 -> V_568 = F_112 ;
V_191 -> V_856 = F_118 ;
V_191 -> V_857 = F_102 ;
if ( V_125 -> V_130 )
V_191 -> V_858 = V_859 ;
}
F_112 ( V_5 , V_191 ) ;
} else {
V_191 -> type = V_254 ;
}
V_191 = & V_5 -> V_241 [ V_860 ] ;
if ( V_220 -> V_830 ) {
V_191 -> type = V_861 ;
V_191 -> V_296 = V_862 | V_863 | V_844 ;
if ( V_125 -> V_128 )
V_191 -> V_296 |= V_848 ;
V_191 -> V_332 = V_220 -> V_830 ;
V_191 -> V_364 = V_220 -> V_864 ;
V_191 -> V_476 = V_220 -> V_865 ;
V_191 -> V_851 = F_165 ;
V_191 -> V_866 = F_162 ;
V_191 -> V_850 = V_867 ;
V_288 = F_280 ( V_191 ) ;
if ( V_288 )
return V_288 ;
if ( V_5 -> V_428 && ( V_220 -> V_222 || V_125 -> V_130 ) ) {
V_5 -> V_196 = V_191 ;
V_191 -> V_296 |= V_868 ;
V_191 -> V_853 = V_191 -> V_332 ;
V_191 -> V_854 = F_174 ;
V_191 -> V_855 = F_167 ;
V_191 -> V_568 = F_175 ;
if ( ! V_125 -> V_128 )
V_191 -> V_857 = F_150 ;
if ( V_125 -> V_130 )
V_191 -> V_858 = V_869 ;
}
if ( V_125 -> V_870 )
F_197 ( V_5 , V_191 ) ;
F_175 ( V_5 , V_191 ) ;
} else {
V_191 -> type = V_254 ;
}
V_191 = & V_5 -> V_241 [ V_587 ] ;
V_191 -> type = V_871 ;
V_191 -> V_296 = V_862 | V_841 ;
V_191 -> V_332 = V_220 -> V_872 ? 32 : 8 ;
V_191 -> V_364 = 1 ;
V_191 -> V_476 = & V_873 ;
if ( V_125 -> V_128 ) {
V_191 -> V_296 |= V_297 ;
V_191 -> V_874 = F_183 ;
V_191 -> V_851 = F_182 ;
if ( V_5 -> V_428 ) {
V_191 -> V_296 |= V_868 ;
V_191 -> V_853 = V_191 -> V_332 ;
V_191 -> V_854 = F_185 ;
V_191 -> V_855 = F_188 ;
V_191 -> V_568 = F_189 ;
V_191 -> V_858 = V_875 ;
}
F_3 ( V_5 , V_576 | V_876 ,
V_572 ) ;
F_3 ( V_5 , V_191 -> V_553 , V_562 ) ;
} else {
V_191 -> V_874 = F_179 ;
V_191 -> V_851 = F_176 ;
V_125 -> V_551 = F_178 ( V_191 -> V_553 ) ;
F_6 ( V_5 , V_125 -> V_551 , V_77 ) ;
}
V_191 = & V_5 -> V_241 [ V_877 ] ;
if ( V_220 -> V_878 ) {
V_288 = F_281 ( V_5 , V_191 , F_206 , V_879 ) ;
if ( V_288 )
return V_288 ;
} else {
V_191 -> type = V_254 ;
}
V_191 = & V_5 -> V_241 [ V_880 ] ;
V_191 -> type = V_254 ;
V_191 = & V_5 -> V_241 [ V_881 ] ;
V_191 -> type = V_882 ;
V_191 -> V_296 = V_883 ;
V_191 -> V_332 = 1 ;
V_191 -> V_364 = 0 ;
if ( V_125 -> V_128 ) {
V_191 -> V_851 = F_208 ;
F_3 ( V_5 , 0x0 , V_694 ) ;
} else if ( V_125 -> V_181 ) {
V_191 -> V_851 = F_211 ;
} else {
V_191 -> V_296 |= V_862 ;
V_191 -> V_850 = F_222 ;
V_191 -> V_866 = F_221 ;
F_223 ( V_5 , V_191 ) ;
}
V_191 = & V_5 -> V_241 [ V_884 ] ;
V_191 -> type = V_885 ;
V_191 -> V_296 = V_841 | V_883 ;
V_191 -> V_364 = 0xff ;
if ( V_125 -> V_128 ) {
V_191 -> V_332 = V_886 ;
V_191 -> V_850 = F_226 ;
} else {
V_191 -> V_332 = 512 ;
V_191 -> V_850 = F_225 ;
}
V_191 = & V_5 -> V_241 [ V_887 ] ;
V_191 -> type = V_871 ;
V_191 -> V_296 = V_841 | V_862 | V_883 ;
V_191 -> V_364 = 1 ;
if ( V_125 -> V_128 ) {
V_191 -> V_332 = 16 ;
V_191 -> V_874 = F_241 ;
F_6 ( V_5 , V_191 -> V_559 , V_737 ) ;
for ( V_180 = 0 ; V_180 < V_888 ; ++ V_180 ) {
F_6 ( V_5 , V_125 -> V_726 [ V_180 ] ,
F_234 ( V_180 + 1 ) ) ;
}
} else {
V_191 -> V_332 = 10 ;
}
V_191 -> V_851 = F_240 ;
F_71 ( V_5 , V_96 , ~ 0 , 0 ) ;
V_191 = & V_5 -> V_241 [ V_889 ] ;
if ( V_125 -> V_870 ) {
V_191 -> type = V_840 ;
V_191 -> V_296 = V_841 | V_842 | V_883 ;
V_191 -> V_332 = V_220 -> V_830 ;
V_191 -> V_364 = ( 1 << 16 ) - 1 ;
V_191 -> V_476 = & V_890 ;
V_191 -> V_850 = F_247 ;
V_191 -> V_851 = NULL ;
F_249 ( V_5 ) ;
} else {
V_191 -> type = V_254 ;
}
V_191 = & V_5 -> V_241 [ V_891 ] ;
V_191 -> type = V_892 ;
V_191 -> V_296 = V_841 | V_862 | V_883 ;
V_191 -> V_332 = 1 ;
V_191 -> V_364 = 0xff ;
V_191 -> V_851 = F_196 ;
V_125 -> V_556 = 0 ;
V_125 -> V_606 = 0 ;
V_191 = & V_5 -> V_241 [ V_893 ] ;
V_191 -> type = V_871 ;
V_191 -> V_296 = V_841 | V_862 | V_883 ;
V_191 -> V_332 = 8 ;
V_191 -> V_364 = 1 ;
V_191 -> V_874 = F_266 ;
V_191 -> V_851 = F_264 ;
F_267 ( V_5 ) ;
V_125 -> V_169 = F_282 ( V_5 ,
F_200 ,
F_201 ,
( V_125 -> V_128 )
? V_894
: V_895 ,
V_168 ) ;
if ( ! V_125 -> V_169 )
return - V_827 ;
for ( V_180 = 0 ; V_180 < V_168 ; ++ V_180 ) {
struct V_647 * V_896 = & V_125 -> V_169 -> V_170 [ V_180 ] ;
V_896 -> V_897 = 0 ;
V_896 -> V_1 = V_180 ;
F_283 ( V_896 ) ;
V_191 = & V_5 -> V_241 [ F_1 ( V_180 ) ] ;
V_191 -> type = V_898 ;
V_191 -> V_296 = V_841 | V_862 | V_297 ;
V_191 -> V_332 = 3 ;
V_191 -> V_364 = ( V_125 -> V_128 ) ? 0xffffffff
: 0x00ffffff ;
V_191 -> V_850 = V_899 ;
V_191 -> V_866 = V_899 ;
V_191 -> V_851 = V_900 ;
#ifdef F_58
if ( V_5 -> V_428 && V_125 -> V_130 ) {
V_191 -> V_296 |= V_852 ;
V_191 -> V_853 = 1 ;
V_191 -> V_854 = V_901 ;
V_191 -> V_855 = F_268 ;
V_191 -> V_568 = F_271 ;
V_191 -> V_858 = V_875 ;
}
#endif
V_191 -> V_126 = V_896 ;
}
V_191 = & V_5 -> V_241 [ V_902 ] ;
V_191 -> type = V_898 ;
V_191 -> V_296 = V_841 | V_862 ;
V_191 -> V_332 = 1 ;
V_191 -> V_364 = 0xf ;
V_191 -> V_850 = F_202 ;
V_191 -> V_866 = F_203 ;
V_191 -> V_851 = F_205 ;
if ( V_5 -> V_428 ) {
F_35 ( V_5 ,
( V_829 ? V_903 : 0 ) |
( V_904 & 0 ) |
V_905 | V_906 |
F_284 ( V_828 ) |
F_285 ( V_828 ) ,
V_94 ) ;
}
F_9 ( V_5 , V_125 -> V_141 , V_140 ) ;
F_9 ( V_5 , V_125 -> V_143 , V_142 ) ;
if ( V_125 -> V_212 ) {
F_9 ( V_5 , 0 , V_907 ) ;
} else if ( V_125 -> V_128 ) {
int V_144 ;
for ( V_144 = 0 ; V_144 < V_220 -> V_830 ; ++ V_144 ) {
F_9 ( V_5 , 0xf ,
F_156 ( V_144 ) ) ;
F_9 ( V_5 , 0x0 ,
F_157 ( V_144 ) ) ;
}
F_9 ( V_5 , 0x0 , V_908 ) ;
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
