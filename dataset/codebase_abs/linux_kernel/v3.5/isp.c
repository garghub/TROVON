void F_1 ( struct V_1 * V_2 )
{
F_2 ( V_2 , 0 , V_3 , V_4 ) ;
F_3 ( V_2 , V_3 , V_4 ) ;
}
static void F_4 ( struct V_1 * V_2 )
{
static const T_1 V_5 = V_6
| V_7
| V_8
| V_9
| V_10
| V_11
| V_12
| V_13
| V_14
| V_15
| V_16
| V_17 ;
F_2 ( V_2 , V_5 , V_3 , V_18 ) ;
F_2 ( V_2 , V_5 , V_3 , V_19 ) ;
}
static void F_5 ( struct V_1 * V_2 )
{
F_2 ( V_2 , 0 , V_3 , V_19 ) ;
}
static T_1 F_6 ( struct V_1 * V_2 , T_1 V_20 , T_2 V_21 )
{
T_1 V_22 ;
T_1 V_23 ;
unsigned long V_24 ;
if ( ! F_7 ( V_2 ) )
return 0 ;
V_24 = F_8 ( V_2 -> clock [ V_25 ] ) ;
if ( V_20 >= V_24 ) {
V_22 = V_26 ;
V_23 = V_24 ;
} else if ( V_20 >= 2 ) {
V_22 = V_24 / V_20 ;
if ( V_22 >= V_26 )
V_22 = V_26 - 1 ;
V_23 = V_24 / V_22 ;
} else {
V_22 = V_20 ;
V_23 = 0 ;
}
switch ( V_21 ) {
case V_27 :
F_9 ( V_2 , V_3 , V_28 ,
V_29 ,
V_22 << V_30 ) ;
F_10 ( V_2 -> V_31 , L_1 ,
V_23 ) ;
break;
case V_32 :
F_9 ( V_2 , V_3 , V_28 ,
V_33 ,
V_22 << V_34 ) ;
F_10 ( V_2 -> V_31 , L_2 ,
V_23 ) ;
break;
case V_35 :
default:
F_11 ( V_2 ) ;
F_10 ( V_2 -> V_31 , L_3
L_4 ) ;
return - V_36 ;
}
if ( V_22 >= 2 && V_2 -> V_37 [ V_21 - 1 ] < 2 )
F_7 ( V_2 ) ;
else if ( V_22 < 2 && V_2 -> V_37 [ V_21 - 1 ] >= 2 )
F_11 ( V_2 ) ;
V_2 -> V_37 [ V_21 - 1 ] = V_22 ;
F_11 ( V_2 ) ;
return V_23 ;
}
static void F_12 ( struct V_1 * V_2 , int V_38 )
{
F_2 ( V_2 ,
( ( V_38 ? V_39 :
V_40 ) <<
V_41 ) |
( ( V_2 -> V_42 == V_43 ) ?
V_44 : 0 ) ,
V_3 , V_45 ) ;
if ( V_2 -> V_46 )
F_2 ( V_2 , V_47 , V_3 ,
V_48 ) ;
}
void F_13 ( struct V_1 * V_2 ,
enum V_49 V_50 ,
const struct V_51 * V_52 ,
unsigned int V_53 )
{
T_1 V_54 ;
V_54 = F_3 ( V_2 , V_3 , V_48 ) ;
V_54 &= ~ V_55 ;
V_54 &= ~ V_56 ;
V_54 &= ~ V_57 ;
V_54 &= ~ V_58 ;
switch ( V_50 ) {
case V_59 :
V_54 |= V_60 ;
V_54 |= V_52 -> V_61 << V_62 ;
V_54 |= V_52 -> V_63 << V_64 ;
V_53 += V_52 -> V_65 * 2 ;
break;
case V_66 :
V_54 |= V_67 ;
break;
case V_68 :
V_54 |= V_69 ;
break;
case V_70 :
V_54 |= V_71 ;
break;
default:
return;
}
V_54 |= ( ( V_53 / 2 ) << V_72 ) & V_55 ;
V_54 &= ~ V_73 ;
V_54 |= V_74 ;
F_2 ( V_2 , V_54 , V_3 , V_48 ) ;
}
void F_14 ( struct V_1 * V_2 )
{
if ( F_15 ( & V_2 -> V_75 ) ||
F_16 ( & V_2 -> V_76 ) ) {
F_17 ( & V_2 -> V_76 . V_77 , 1 ) ;
F_10 ( V_2 -> V_31 , L_5
L_6 ) ;
}
}
static inline void F_18 ( struct V_1 * V_2 , T_1 V_78 )
{
static const char * V_79 [] = {
L_7 ,
L_8 ,
L_9 ,
L_10 ,
L_11 ,
L_12 ,
L_13 ,
L_14 ,
L_15 ,
L_16 ,
L_17 ,
L_18 ,
L_19 ,
L_20 ,
L_21 ,
L_22 ,
L_23 ,
L_24 ,
L_25 ,
L_26 ,
L_27 ,
L_28 ,
L_29 ,
L_30 ,
L_31 ,
L_32 ,
L_33 ,
L_34 ,
L_35 ,
L_36 ,
L_37 ,
L_38 ,
} ;
int V_80 ;
F_10 ( V_2 -> V_31 , L_39 ) ;
for ( V_80 = 0 ; V_80 < F_19 ( V_79 ) ; V_80 ++ ) {
if ( ( 1 << V_80 ) & V_78 )
F_20 ( V_81 L_40 , V_79 [ V_80 ] ) ;
}
F_20 ( V_81 L_41 ) ;
}
static void F_21 ( struct V_1 * V_2 )
{
struct V_82 * V_31 = V_2 -> V_31 ;
struct V_83 * V_84 ;
T_1 V_85 ;
V_85 = F_3 ( V_2 , V_86 , V_87 ) ;
F_2 ( V_2 , V_85 , V_86 , V_87 ) ;
V_85 &= ~ V_88 ;
if ( V_85 )
F_10 ( V_31 , L_42 , V_85 ) ;
if ( V_85 & V_89 ) {
V_84 = F_22 ( & V_2 -> V_90 . V_91 . V_92 ) ;
if ( V_84 != NULL )
V_84 -> error = true ;
}
if ( V_85 & V_93 ) {
V_84 = F_22 ( & V_2 -> V_94 . V_91 . V_92 ) ;
if ( V_84 != NULL )
V_84 -> error = true ;
}
if ( V_85 & V_95 ) {
V_84 = F_22 ( & V_2 -> V_75 . V_91 . V_92 ) ;
if ( V_84 != NULL )
V_84 -> error = true ;
}
if ( V_85 & V_96 ) {
V_84 = F_22 ( & V_2 -> V_97 . V_91 . V_92 ) ;
if ( V_84 != NULL )
V_84 -> error = true ;
}
if ( V_85 & ( V_98
| V_99
| V_100
| V_101 ) ) {
V_84 = F_22 ( & V_2 -> V_102 . V_91 . V_92 ) ;
if ( V_84 != NULL )
V_84 -> error = true ;
}
if ( V_85 & V_103 )
F_23 ( & V_2 -> V_104 ) ;
if ( V_85 & V_105 )
F_23 ( & V_2 -> V_106 ) ;
}
static T_3 F_24 ( int V_5 , void * V_107 )
{
static const T_1 V_108 = V_109 |
V_110 |
V_111 |
V_112 |
V_113 ;
struct V_1 * V_2 = V_107 ;
T_1 V_78 ;
V_78 = F_3 ( V_2 , V_3 , V_18 ) ;
F_2 ( V_2 , V_78 , V_3 , V_18 ) ;
F_21 ( V_2 ) ;
if ( V_78 & V_114 )
F_25 ( & V_2 -> V_94 ) ;
if ( V_78 & V_115 )
F_26 ( & V_2 -> V_90 ) ;
if ( V_78 & V_111 ) {
if ( V_2 -> V_75 . V_116 & V_117 )
F_27 ( & V_2 -> V_97 ) ;
if ( V_2 -> V_75 . V_116 & V_118 )
F_28 ( & V_2 -> V_102 ) ;
F_29 ( & V_2 -> V_106 ) ;
F_29 ( & V_2 -> V_104 ) ;
F_29 ( & V_2 -> V_76 ) ;
}
if ( V_78 & V_108 )
F_30 ( & V_2 -> V_75 , V_78 & V_108 ) ;
if ( V_78 & V_119 ) {
if ( V_2 -> V_97 . V_116 & V_120 )
F_28 ( & V_2 -> V_102 ) ;
F_31 ( & V_2 -> V_97 ) ;
}
if ( V_78 & V_121 )
F_32 ( & V_2 -> V_102 ) ;
if ( V_78 & V_122 )
F_33 ( & V_2 -> V_106 ) ;
if ( V_78 & V_123 )
F_33 ( & V_2 -> V_104 ) ;
if ( V_78 & V_124 )
F_33 ( & V_2 -> V_76 ) ;
F_1 ( V_2 ) ;
#if F_34 ( V_125 ) && F_34 ( V_126 )
F_18 ( V_2 , V_78 ) ;
#endif
return V_127 ;
}
static int F_35 ( struct V_128 * V_92 )
{
struct V_129 V_130 ;
int V_131 = 0 ;
F_36 ( & V_130 , V_92 ) ;
while ( ( V_92 = F_37 ( & V_130 ) ) ) {
if ( F_38 ( V_92 ) == V_132 )
V_131 += V_92 -> V_133 ;
}
return V_131 ;
}
static int F_39 ( struct V_128 * V_92 , int V_134 )
{
struct V_135 * V_91 ;
int V_136 ;
V_91 = F_38 ( V_92 ) == V_137
? F_40 ( V_92 ) : NULL ;
if ( V_92 -> V_133 == 0 && V_134 > 0 && V_91 != NULL ) {
V_136 = F_41 ( V_91 , V_138 , V_139 , 1 ) ;
if ( V_136 < 0 && V_136 != - V_140 )
return V_136 ;
}
V_92 -> V_133 += V_134 ;
F_42 ( V_92 -> V_133 < 0 ) ;
if ( V_92 -> V_133 == 0 && V_134 < 0 && V_91 != NULL )
F_41 ( V_91 , V_138 , V_139 , 0 ) ;
return 0 ;
}
static int F_43 ( struct V_128 * V_92 , int V_134 )
{
struct V_129 V_130 ;
struct V_128 * V_141 = V_92 ;
int V_136 = 0 ;
if ( ! V_134 )
return 0 ;
F_36 ( & V_130 , V_92 ) ;
while ( ! V_136 && ( V_92 = F_37 ( & V_130 ) ) )
if ( F_38 ( V_92 ) != V_132 )
V_136 = F_39 ( V_92 , V_134 ) ;
if ( ! V_136 )
return 0 ;
F_36 ( & V_130 , V_141 ) ;
while ( ( V_141 = F_37 ( & V_130 ) )
&& V_141 != V_92 )
if ( F_38 ( V_141 ) != V_132 )
F_39 ( V_141 , - V_134 ) ;
return V_136 ;
}
int F_44 ( struct V_128 * V_92 , int V_131 )
{
int V_134 = V_131 ? 1 : - 1 ;
int V_136 ;
F_45 ( & V_92 -> V_142 -> V_143 ) ;
V_92 -> V_133 += V_134 ;
F_42 ( V_92 -> V_133 < 0 ) ;
V_136 = F_43 ( V_92 , V_134 ) ;
if ( V_136 < 0 )
V_92 -> V_133 -= V_134 ;
F_46 ( & V_92 -> V_142 -> V_143 ) ;
return V_136 ;
}
static int F_47 ( struct V_144 * V_145 ,
struct V_144 * V_146 , T_1 V_147 )
{
int V_148 = F_35 ( V_145 -> V_92 ) ;
int V_149 = F_35 ( V_146 -> V_92 ) ;
int V_136 ;
if ( ! ( V_147 & V_150 ) ) {
F_43 ( V_145 -> V_92 , - V_149 ) ;
F_43 ( V_146 -> V_92 , - V_148 ) ;
return 0 ;
}
V_136 = F_43 ( V_145 -> V_92 , V_149 ) ;
if ( V_136 < 0 )
return V_136 ;
V_136 = F_43 ( V_146 -> V_92 , V_148 ) ;
if ( V_136 < 0 )
F_43 ( V_145 -> V_92 , - V_149 ) ;
return V_136 ;
}
static int F_48 ( struct V_83 * V_84 ,
enum V_151 V_152 )
{
struct V_1 * V_2 = V_84 -> V_116 -> V_2 ;
struct V_128 * V_92 ;
struct V_144 * V_153 ;
struct V_135 * V_91 ;
unsigned long V_147 ;
int V_136 ;
if ( ( V_84 -> V_154 & V_2 -> V_155 ) &
( 1U << V_2 -> V_97 . V_91 . V_92 . V_156 ) )
return - V_157 ;
F_49 ( & V_84 -> V_158 , V_147 ) ;
V_84 -> V_159 &= ~ ( V_160 | V_161 ) ;
F_50 ( & V_84 -> V_158 , V_147 ) ;
V_84 -> V_162 = false ;
V_92 = & V_84 -> V_116 -> V_163 . V_92 ;
while ( 1 ) {
V_153 = & V_92 -> V_164 [ 0 ] ;
if ( ! ( V_153 -> V_147 & V_165 ) )
break;
V_153 = F_51 ( V_153 ) ;
if ( V_153 == NULL ||
F_38 ( V_153 -> V_92 ) != V_137 )
break;
V_92 = V_153 -> V_92 ;
V_91 = F_40 ( V_92 ) ;
V_136 = F_41 ( V_91 , V_163 , V_166 , V_152 ) ;
if ( V_136 < 0 && V_136 != - V_140 )
return V_136 ;
if ( V_91 == & V_2 -> V_75 . V_91 ) {
F_41 ( & V_2 -> V_106 . V_91 , V_163 ,
V_166 , V_152 ) ;
F_41 ( & V_2 -> V_104 . V_91 , V_163 ,
V_166 , V_152 ) ;
F_41 ( & V_2 -> V_76 . V_91 , V_163 ,
V_166 , V_152 ) ;
V_84 -> V_162 = true ;
}
}
return 0 ;
}
static int F_52 ( struct V_1 * V_2 )
{
return F_53 ( & V_2 -> V_102 ) ;
}
static int F_54 ( struct V_1 * V_2 )
{
return F_55 ( & V_2 -> V_97 ) ;
}
static int F_56 ( struct V_1 * V_2 )
{
return F_57 ( & V_2 -> V_104 )
|| F_57 ( & V_2 -> V_106 )
|| F_57 ( & V_2 -> V_76 )
|| F_15 ( & V_2 -> V_75 ) ;
}
static int F_58 ( struct V_1 * V_2 ,
int (* F_59)( struct V_1 * V_2 ) )
{
unsigned long V_167 = V_168 + V_169 ;
while ( ! F_60 ( V_168 , V_167 ) ) {
if ( ! F_59 ( V_2 ) )
return 0 ;
}
return 1 ;
}
static int F_61 ( struct V_83 * V_84 )
{
struct V_1 * V_2 = V_84 -> V_116 -> V_2 ;
struct V_128 * V_92 ;
struct V_144 * V_153 ;
struct V_135 * V_91 ;
int V_170 = 0 ;
int V_136 ;
V_92 = & V_84 -> V_116 -> V_163 . V_92 ;
while ( 1 ) {
V_153 = & V_92 -> V_164 [ 0 ] ;
if ( ! ( V_153 -> V_147 & V_165 ) )
break;
V_153 = F_51 ( V_153 ) ;
if ( V_153 == NULL ||
F_38 ( V_153 -> V_92 ) != V_137 )
break;
V_92 = V_153 -> V_92 ;
V_91 = F_40 ( V_92 ) ;
if ( V_91 == & V_2 -> V_75 . V_91 ) {
F_41 ( & V_2 -> V_106 . V_91 ,
V_163 , V_166 , 0 ) ;
F_41 ( & V_2 -> V_104 . V_91 ,
V_163 , V_166 , 0 ) ;
F_41 ( & V_2 -> V_76 . V_91 ,
V_163 , V_166 , 0 ) ;
}
F_41 ( V_91 , V_163 , V_166 , 0 ) ;
if ( V_91 == & V_2 -> V_102 . V_91 )
V_136 = F_58 ( V_2 , F_52 ) ;
else if ( V_91 == & V_2 -> V_97 . V_91 )
V_136 = F_58 ( V_2 , F_54 ) ;
else if ( V_91 == & V_2 -> V_75 . V_91 )
V_136 = F_58 ( V_2 , F_56 ) ;
else
V_136 = 0 ;
if ( V_136 ) {
F_62 ( V_2 -> V_31 , L_43 , V_91 -> V_79 ) ;
V_2 -> V_155 |= 1U << V_91 -> V_92 . V_156 ;
V_170 = - V_171 ;
}
}
return V_170 ;
}
int F_63 ( struct V_83 * V_84 ,
enum V_151 V_159 )
{
int V_136 ;
if ( V_159 == V_172 )
V_136 = F_61 ( V_84 ) ;
else
V_136 = F_48 ( V_84 , V_159 ) ;
if ( V_136 == 0 || V_159 == V_172 )
V_84 -> V_173 = V_159 ;
return V_136 ;
}
static void F_64 ( struct V_83 * V_84 )
{
int V_174 = V_84 -> V_173 == V_175 ;
F_65 ( V_84 -> V_116 , ! V_174 ) ;
if ( V_174 )
F_65 ( V_84 -> V_50 , 0 ) ;
F_48 ( V_84 , V_84 -> V_173 ) ;
}
static void F_66 ( struct V_83 * V_84 )
{
F_61 ( V_84 ) ;
}
static int F_67 ( struct V_128 * V_176 )
{
struct V_83 * V_84 ;
struct V_144 * V_153 ;
if ( ! V_176 -> V_84 )
return 0 ;
V_84 = F_22 ( V_176 ) ;
if ( V_84 -> V_173 == V_172 )
return 0 ;
V_153 = F_51 ( & V_84 -> V_116 -> V_153 ) ;
return V_153 -> V_92 == V_176 ;
}
static void F_68 ( struct V_128 * V_176 )
{
if ( F_67 ( V_176 ) )
F_66 ( F_22 ( V_176 ) ) ;
}
static void F_69 ( struct V_128 * V_176 )
{
if ( F_67 ( V_176 ) )
F_64 ( F_22 ( V_176 ) ) ;
}
static int F_70 ( struct V_1 * V_2 )
{
unsigned long V_167 ;
F_71 ( & V_2 -> V_106 ) ;
F_71 ( & V_2 -> V_104 ) ;
F_71 ( & V_2 -> V_76 ) ;
F_68 ( & V_2 -> V_102 . V_91 . V_92 ) ;
F_68 ( & V_2 -> V_97 . V_91 . V_92 ) ;
F_68 ( & V_2 -> V_75 . V_91 . V_92 ) ;
F_68 ( & V_2 -> V_94 . V_91 . V_92 ) ;
F_68 ( & V_2 -> V_90 . V_91 . V_92 ) ;
V_167 = V_168 + V_169 ;
while ( F_57 ( & V_2 -> V_104 )
|| F_57 ( & V_2 -> V_106 )
|| F_57 ( & V_2 -> V_76 )
|| F_55 ( & V_2 -> V_97 )
|| F_53 ( & V_2 -> V_102 )
|| F_15 ( & V_2 -> V_75 ) ) {
if ( F_60 ( V_168 , V_167 ) ) {
F_62 ( V_2 -> V_31 , L_44 ) ;
return 1 ;
}
F_72 ( 1 ) ;
}
return 0 ;
}
static void F_73 ( struct V_1 * V_2 )
{
F_74 ( & V_2 -> V_106 ) ;
F_74 ( & V_2 -> V_104 ) ;
F_74 ( & V_2 -> V_76 ) ;
F_69 ( & V_2 -> V_102 . V_91 . V_92 ) ;
F_69 ( & V_2 -> V_97 . V_91 . V_92 ) ;
F_69 ( & V_2 -> V_75 . V_91 . V_92 ) ;
F_69 ( & V_2 -> V_94 . V_91 . V_92 ) ;
F_69 ( & V_2 -> V_90 . V_91 . V_92 ) ;
}
static int F_75 ( struct V_1 * V_2 )
{
unsigned long V_167 = 0 ;
F_2 ( V_2 ,
F_3 ( V_2 , V_3 , V_45 )
| V_177 ,
V_3 , V_45 ) ;
while ( ! ( F_3 ( V_2 , V_3 ,
V_178 ) & 0x1 ) ) {
if ( V_167 ++ > 10000 ) {
F_76 ( V_2 -> V_31 , L_45 ) ;
return - V_171 ;
}
F_77 ( 1 ) ;
}
V_2 -> V_155 = 0 ;
return 0 ;
}
static void
F_78 ( struct V_1 * V_2 , struct V_179 * V_180 )
{
struct V_179 * V_181 = V_180 ;
for (; V_181 -> V_182 != V_183 ; V_181 ++ )
V_181 -> V_184 = F_3 ( V_2 , V_181 -> V_185 , V_181 -> V_182 ) ;
}
static void
F_79 ( struct V_1 * V_2 , struct V_179 * V_180 )
{
struct V_179 * V_181 = V_180 ;
for (; V_181 -> V_182 != V_183 ; V_181 ++ )
F_2 ( V_2 , V_181 -> V_184 , V_181 -> V_185 , V_181 -> V_182 ) ;
}
static void F_80 ( struct V_1 * V_2 )
{
F_78 ( V_2 , V_186 ) ;
F_81 ( V_2 -> V_31 ) ;
}
static void F_82 ( struct V_1 * V_2 )
{
F_79 ( V_2 , V_186 ) ;
F_83 ( V_2 -> V_31 ) ;
F_84 ( V_2 ) ;
F_85 ( V_2 ) ;
}
void F_86 ( struct V_1 * V_2 , enum V_187 V_188 )
{
T_1 V_189 = 0 ;
V_2 -> V_190 |= V_188 ;
if ( V_2 -> V_190 & V_191 )
V_189 |= V_192 ;
if ( V_2 -> V_190 & V_193 )
V_189 |= V_194 ;
if ( V_2 -> V_190 & V_195 )
V_189 |= V_196 ;
if ( V_2 -> V_190 & V_197 )
V_189 |= V_198 ;
if ( V_2 -> V_190 & V_199 )
V_189 |= V_200 ;
if ( V_2 -> V_190 & V_201 )
V_189 |= V_202 ;
F_87 ( V_2 , V_3 , V_48 , V_189 ) ;
}
void F_88 ( struct V_1 * V_2 , enum V_187 V_188 )
{
T_1 V_189 = 0 ;
V_2 -> V_190 &= ~ V_188 ;
if ( ! ( V_2 -> V_190 & V_191 ) )
V_189 |= V_192 ;
if ( ! ( V_2 -> V_190 & V_193 ) )
V_189 |= V_194 ;
if ( ! ( V_2 -> V_190 & V_195 ) )
V_189 |= V_196 ;
if ( ! ( V_2 -> V_190 & V_197 ) )
V_189 |= V_198 ;
if ( ! ( V_2 -> V_190 & V_199 ) )
V_189 |= V_200 ;
if ( ! ( V_2 -> V_190 & V_201 ) )
V_189 |= V_202 ;
F_89 ( V_2 , V_3 , V_48 , V_189 ) ;
}
int F_90 ( struct V_128 * V_176 , T_4 * V_203 ,
T_5 * V_204 )
{
struct V_83 * V_84 = F_22 ( V_176 ) ;
if ( V_84 -> V_173 == V_172 ||
( V_84 -> V_173 == V_175 &&
! F_91 ( V_84 ) ) )
return 0 ;
F_17 ( V_204 , 1 ) ;
F_92 () ;
if ( F_67 ( V_176 ) ) {
struct V_205 * V_163 = V_84 -> V_116 ;
unsigned long V_147 ;
F_49 ( & V_163 -> V_206 -> V_207 , V_147 ) ;
if ( V_163 -> V_208 & V_209 ) {
F_50 ( & V_163 -> V_206 -> V_207 , V_147 ) ;
F_17 ( V_204 , 0 ) ;
F_92 () ;
return 0 ;
}
F_50 ( & V_163 -> V_206 -> V_207 , V_147 ) ;
if ( ! F_93 ( * V_203 , ! F_94 ( V_204 ) ,
F_95 ( 1000 ) ) ) {
F_17 ( V_204 , 0 ) ;
F_92 () ;
return - V_171 ;
}
}
return 0 ;
}
int F_96 ( T_4 * V_203 ,
T_5 * V_204 )
{
if ( F_97 ( V_204 , 1 , 0 ) ) {
F_98 ( V_203 ) ;
return 1 ;
}
return 0 ;
}
static void F_99 ( struct V_1 * V_2 )
{
T_1 V_210 = 0 ;
if ( V_2 -> V_211 & V_212 )
V_210 |= V_213 ;
if ( V_2 -> V_211 & V_214 )
V_210 |= V_215 ;
if ( V_2 -> V_211 & V_216 )
V_210 |= V_217 ;
if ( V_2 -> V_211 & V_218 )
V_210 |= V_219 | V_220 ;
if ( V_2 -> V_211 & V_221 )
V_210 |= V_222 | V_223 ;
F_9 ( V_2 , V_3 , V_48 ,
V_224 , V_210 ) ;
}
void F_100 ( struct V_1 * V_2 ,
enum V_225 V_188 )
{
V_2 -> V_211 |= V_188 ;
F_99 ( V_2 ) ;
}
void F_101 ( struct V_1 * V_2 ,
enum V_225 V_188 )
{
V_2 -> V_211 &= ~ V_188 ;
F_99 ( V_2 ) ;
}
static int F_102 ( struct V_1 * V_2 )
{
int V_226 ;
unsigned long V_227 ;
int V_22 ;
if ( F_103 () )
V_22 = 1 ;
else
V_22 = 2 ;
V_226 = F_104 ( V_2 -> clock [ V_228 ] ) ;
if ( V_226 ) {
F_105 ( V_2 -> V_31 , L_46 ) ;
goto V_229;
}
V_226 = F_106 ( V_2 -> clock [ V_230 ] ,
V_231 / V_22 ) ;
if ( V_226 ) {
F_105 ( V_2 -> V_31 , L_47 ) ;
goto V_232;
}
V_226 = F_104 ( V_2 -> clock [ V_25 ] ) ;
if ( V_226 ) {
F_105 ( V_2 -> V_31 , L_48 ) ;
goto V_232;
}
V_227 = F_8 ( V_2 -> clock [ V_25 ] ) ;
if ( V_227 != V_231 )
F_107 ( V_2 -> V_31 , L_49
L_50
L_51 , V_231 , V_227 ) ;
V_226 = F_104 ( V_2 -> clock [ V_233 ] ) ;
if ( V_226 ) {
F_105 ( V_2 -> V_31 , L_52 ) ;
goto V_234;
}
return 0 ;
V_234:
F_108 ( V_2 -> clock [ V_25 ] ) ;
V_232:
F_108 ( V_2 -> clock [ V_228 ] ) ;
V_229:
return V_226 ;
}
static void F_109 ( struct V_1 * V_2 )
{
F_108 ( V_2 -> clock [ V_228 ] ) ;
F_108 ( V_2 -> clock [ V_25 ] ) ;
F_108 ( V_2 -> clock [ V_233 ] ) ;
}
static void F_110 ( struct V_1 * V_2 )
{
unsigned int V_80 ;
for ( V_80 = 0 ; V_80 < F_19 ( V_235 ) ; ++ V_80 ) {
if ( V_2 -> clock [ V_80 ] ) {
F_111 ( V_2 -> clock [ V_80 ] ) ;
V_2 -> clock [ V_80 ] = NULL ;
}
}
}
static int F_112 ( struct V_1 * V_2 )
{
struct V_210 * V_210 ;
unsigned int V_80 ;
for ( V_80 = 0 ; V_80 < F_19 ( V_235 ) ; ++ V_80 ) {
V_210 = F_113 ( V_2 -> V_31 , V_235 [ V_80 ] ) ;
if ( F_114 ( V_210 ) ) {
F_105 ( V_2 -> V_31 , L_53 , V_235 [ V_80 ] ) ;
F_110 ( V_2 ) ;
return F_115 ( V_210 ) ;
}
V_2 -> clock [ V_80 ] = V_210 ;
}
return 0 ;
}
struct V_1 * F_7 ( struct V_1 * V_2 )
{
struct V_1 * V_236 = V_2 ;
if ( V_2 == NULL )
return NULL ;
F_45 ( & V_2 -> V_237 ) ;
if ( V_2 -> V_238 > 0 )
goto V_239;
if ( F_102 ( V_2 ) < 0 ) {
V_236 = NULL ;
goto V_239;
}
if ( V_2 -> V_240 )
F_82 ( V_2 ) ;
else
V_2 -> V_240 = 1 ;
F_4 ( V_2 ) ;
V_239:
if ( V_236 != NULL )
V_2 -> V_238 ++ ;
F_46 ( & V_2 -> V_237 ) ;
return V_236 ;
}
void F_11 ( struct V_1 * V_2 )
{
if ( V_2 == NULL )
return;
F_45 ( & V_2 -> V_237 ) ;
F_116 ( V_2 -> V_238 == 0 ) ;
if ( -- V_2 -> V_238 == 0 ) {
F_5 ( V_2 ) ;
if ( V_2 -> V_241 )
F_80 ( V_2 ) ;
if ( V_2 -> V_155 )
F_75 ( V_2 ) ;
F_109 ( V_2 ) ;
}
F_46 ( & V_2 -> V_237 ) ;
}
void F_117 ( struct V_1 * V_2 )
{
F_10 ( V_2 -> V_31 , L_54 ) ;
F_118 ( V_2 , V_242 ) ;
F_118 ( V_2 , V_243 ) ;
F_118 ( V_2 , V_244 ) ;
F_118 ( V_2 , V_245 ) ;
F_118 ( V_2 , V_246 ) ;
F_118 ( V_2 , V_247 ) ;
F_118 ( V_2 , V_248 ) ;
F_118 ( V_2 , V_249 ) ;
F_118 ( V_2 , V_250 ) ;
F_118 ( V_2 , V_251 ) ;
F_118 ( V_2 , V_252 ) ;
F_118 ( V_2 , V_253 ) ;
F_118 ( V_2 , V_254 ) ;
F_118 ( V_2 , V_255 ) ;
F_118 ( V_2 , V_256 ) ;
F_119 ( V_2 , V_257 ) ;
F_119 ( V_2 , V_258 ) ;
F_10 ( V_2 -> V_31 , L_55 ) ;
}
static int F_120 ( struct V_82 * V_31 )
{
struct V_1 * V_2 = F_121 ( V_31 ) ;
int V_259 ;
F_42 ( F_122 ( & V_2 -> V_237 ) ) ;
if ( V_2 -> V_238 == 0 )
return 0 ;
V_259 = F_70 ( V_2 ) ;
F_5 ( V_2 ) ;
F_80 ( V_2 ) ;
if ( V_259 )
F_75 ( V_2 ) ;
return 0 ;
}
static int F_123 ( struct V_82 * V_31 )
{
struct V_1 * V_2 = F_121 ( V_31 ) ;
F_42 ( F_122 ( & V_2 -> V_237 ) ) ;
if ( V_2 -> V_238 )
F_109 ( V_2 ) ;
return 0 ;
}
static int F_124 ( struct V_82 * V_31 )
{
struct V_1 * V_2 = F_121 ( V_31 ) ;
if ( V_2 -> V_238 == 0 )
return 0 ;
return F_102 ( V_2 ) ;
}
static void F_125 ( struct V_82 * V_31 )
{
struct V_1 * V_2 = F_121 ( V_31 ) ;
if ( V_2 -> V_238 == 0 )
return;
F_82 ( V_2 ) ;
F_4 ( V_2 ) ;
F_73 ( V_2 ) ;
}
static void F_126 ( struct V_1 * V_2 )
{
F_127 ( & V_2 -> V_94 ) ;
F_128 ( & V_2 -> V_90 ) ;
F_129 ( & V_2 -> V_75 ) ;
F_130 ( & V_2 -> V_97 ) ;
F_131 ( & V_2 -> V_102 ) ;
F_132 ( & V_2 -> V_106 ) ;
F_132 ( & V_2 -> V_104 ) ;
F_132 ( & V_2 -> V_76 ) ;
F_133 ( & V_2 -> V_260 ) ;
F_134 ( & V_2 -> V_261 ) ;
}
static struct V_135 *
F_135 ( struct V_1 * V_2 ,
struct V_262 * V_263 )
{
struct V_135 * V_264 = NULL ;
unsigned int V_141 ;
if ( V_263 -> V_263 == NULL )
return NULL ;
for ( V_141 = 1 ; V_263 -> V_263 ; ++ V_263 , V_141 = 0 ) {
struct V_135 * V_91 ;
struct V_265 * V_266 ;
V_266 = F_136 ( V_263 -> V_267 ) ;
if ( V_266 == NULL ) {
F_20 ( V_268 L_56
L_57 , V_269 ,
V_263 -> V_267 ,
V_263 -> V_263 -> type ) ;
continue;
}
V_91 = F_137 ( & V_2 -> V_260 , V_266 ,
V_263 -> V_263 , NULL ) ;
if ( V_91 == NULL ) {
F_20 ( V_268 L_58 ,
V_269 , V_263 -> V_263 -> type ) ;
continue;
}
if ( V_141 )
V_264 = V_91 ;
}
return V_264 ;
}
static int F_138 ( struct V_1 * V_2 )
{
struct V_270 * V_52 = V_2 -> V_52 ;
struct V_271 * V_272 ;
int V_136 ;
V_2 -> V_261 . V_31 = V_2 -> V_31 ;
F_139 ( V_2 -> V_261 . V_273 , L_59 ,
sizeof( V_2 -> V_261 . V_273 ) ) ;
V_2 -> V_261 . V_274 = V_2 -> V_42 ;
V_2 -> V_261 . V_275 = F_47 ;
V_136 = F_140 ( & V_2 -> V_261 ) ;
if ( V_136 < 0 ) {
F_20 ( V_268 L_60 ,
V_269 , V_136 ) ;
return V_136 ;
}
V_2 -> V_260 . V_276 = & V_2 -> V_261 ;
V_136 = F_141 ( V_2 -> V_31 , & V_2 -> V_260 ) ;
if ( V_136 < 0 ) {
F_20 ( V_268 L_61 ,
V_269 , V_136 ) ;
goto V_277;
}
V_136 = F_142 ( & V_2 -> V_90 , & V_2 -> V_260 ) ;
if ( V_136 < 0 )
goto V_277;
V_136 = F_143 ( & V_2 -> V_94 , & V_2 -> V_260 ) ;
if ( V_136 < 0 )
goto V_277;
V_136 = F_144 ( & V_2 -> V_75 , & V_2 -> V_260 ) ;
if ( V_136 < 0 )
goto V_277;
V_136 = F_145 ( & V_2 -> V_97 ,
& V_2 -> V_260 ) ;
if ( V_136 < 0 )
goto V_277;
V_136 = F_146 ( & V_2 -> V_102 , & V_2 -> V_260 ) ;
if ( V_136 < 0 )
goto V_277;
V_136 = F_147 ( & V_2 -> V_106 , & V_2 -> V_260 ) ;
if ( V_136 < 0 )
goto V_277;
V_136 = F_147 ( & V_2 -> V_104 , & V_2 -> V_260 ) ;
if ( V_136 < 0 )
goto V_277;
V_136 = F_147 ( & V_2 -> V_76 , & V_2 -> V_260 ) ;
if ( V_136 < 0 )
goto V_277;
for ( V_272 = V_52 -> V_272 ; V_272 && V_272 -> V_272 ; ++ V_272 ) {
struct V_135 * V_264 ;
struct V_128 * V_50 ;
unsigned int V_147 ;
unsigned int V_153 ;
V_264 = F_135 ( V_2 , V_272 -> V_272 ) ;
if ( V_264 == NULL )
continue;
V_264 -> V_278 = V_272 ;
switch ( V_272 -> V_279 ) {
case V_280 :
V_50 = & V_2 -> V_75 . V_91 . V_92 ;
V_153 = V_281 ;
V_147 = 0 ;
break;
case V_282 :
V_50 = & V_2 -> V_94 . V_91 . V_92 ;
V_153 = V_283 ;
V_147 = V_284
| V_150 ;
break;
case V_285 :
case V_286 :
V_50 = & V_2 -> V_90 . V_91 . V_92 ;
V_153 = V_287 ;
V_147 = 0 ;
break;
case V_288 :
V_50 = & V_2 -> V_289 . V_91 . V_92 ;
V_153 = V_283 ;
V_147 = V_284
| V_150 ;
break;
default:
F_20 ( V_268 L_62 ,
V_269 , V_272 -> V_279 ) ;
V_136 = - V_36 ;
goto V_277;
}
V_136 = F_148 ( & V_264 -> V_92 , 0 , V_50 , V_153 ,
V_147 ) ;
if ( V_136 < 0 )
goto V_277;
}
V_136 = F_149 ( & V_2 -> V_260 ) ;
V_277:
if ( V_136 < 0 )
F_126 ( V_2 ) ;
return V_136 ;
}
static void F_150 ( struct V_1 * V_2 )
{
F_151 ( V_2 ) ;
F_152 ( V_2 ) ;
F_153 ( V_2 ) ;
F_154 ( V_2 ) ;
F_155 ( V_2 ) ;
F_156 ( V_2 ) ;
F_157 ( V_2 ) ;
F_158 ( V_2 ) ;
}
static int F_159 ( struct V_1 * V_2 )
{
int V_136 ;
V_136 = F_160 ( V_2 ) ;
if ( V_136 < 0 ) {
F_105 ( V_2 -> V_31 , L_63 ) ;
goto V_290;
}
V_136 = F_161 ( V_2 ) ;
if ( V_136 < 0 ) {
F_105 ( V_2 -> V_31 , L_64 ) ;
goto V_291;
}
V_136 = F_162 ( V_2 ) ;
if ( V_136 < 0 ) {
F_105 ( V_2 -> V_31 , L_65 ) ;
goto V_292;
}
V_136 = F_163 ( V_2 ) ;
if ( V_136 < 0 ) {
F_105 ( V_2 -> V_31 , L_66 ) ;
goto V_293;
}
V_136 = F_164 ( V_2 ) ;
if ( V_136 < 0 ) {
F_105 ( V_2 -> V_31 , L_67 ) ;
goto V_294;
}
V_136 = F_165 ( V_2 ) ;
if ( V_136 < 0 ) {
F_105 ( V_2 -> V_31 , L_68 ) ;
goto V_295;
}
V_136 = F_166 ( V_2 ) ;
if ( V_136 < 0 ) {
F_105 ( V_2 -> V_31 , L_69 ) ;
goto V_296;
}
V_136 = F_167 ( V_2 ) ;
if ( V_136 < 0 ) {
F_105 ( V_2 -> V_31 , L_70 ) ;
goto V_297;
}
V_136 = F_168 ( V_2 ) ;
if ( V_136 < 0 ) {
F_105 ( V_2 -> V_31 , L_71 ) ;
goto V_298;
}
V_136 = F_148 (
& V_2 -> V_94 . V_91 . V_92 , V_299 ,
& V_2 -> V_75 . V_91 . V_92 , V_281 , 0 ) ;
if ( V_136 < 0 )
goto V_300;
V_136 = F_148 (
& V_2 -> V_90 . V_91 . V_92 , V_301 ,
& V_2 -> V_75 . V_91 . V_92 , V_281 , 0 ) ;
if ( V_136 < 0 )
goto V_300;
V_136 = F_148 (
& V_2 -> V_75 . V_91 . V_92 , V_302 ,
& V_2 -> V_97 . V_91 . V_92 , V_303 , 0 ) ;
if ( V_136 < 0 )
goto V_300;
V_136 = F_148 (
& V_2 -> V_75 . V_91 . V_92 , V_304 ,
& V_2 -> V_102 . V_91 . V_92 , V_305 , 0 ) ;
if ( V_136 < 0 )
goto V_300;
V_136 = F_148 (
& V_2 -> V_97 . V_91 . V_92 , V_306 ,
& V_2 -> V_102 . V_91 . V_92 , V_305 , 0 ) ;
if ( V_136 < 0 )
goto V_300;
V_136 = F_148 (
& V_2 -> V_75 . V_91 . V_92 , V_302 ,
& V_2 -> V_106 . V_91 . V_92 , 0 ,
V_150 | V_284 ) ;
if ( V_136 < 0 )
goto V_300;
V_136 = F_148 (
& V_2 -> V_75 . V_91 . V_92 , V_302 ,
& V_2 -> V_104 . V_91 . V_92 , 0 ,
V_150 | V_284 ) ;
if ( V_136 < 0 )
goto V_300;
V_136 = F_148 (
& V_2 -> V_75 . V_91 . V_92 , V_302 ,
& V_2 -> V_76 . V_91 . V_92 , 0 ,
V_150 | V_284 ) ;
if ( V_136 < 0 )
goto V_300;
return 0 ;
V_300:
F_152 ( V_2 ) ;
V_298:
F_151 ( V_2 ) ;
V_297:
F_153 ( V_2 ) ;
V_296:
F_154 ( V_2 ) ;
V_295:
F_155 ( V_2 ) ;
V_294:
F_156 ( V_2 ) ;
V_293:
F_157 ( V_2 ) ;
V_292:
F_158 ( V_2 ) ;
V_291:
V_290:
return V_136 ;
}
static int T_6 F_169 ( struct V_307 * V_308 )
{
struct V_1 * V_2 = F_170 ( V_308 ) ;
int V_80 ;
F_126 ( V_2 ) ;
F_150 ( V_2 ) ;
F_7 ( V_2 ) ;
F_171 ( V_2 -> V_241 , & V_308 -> V_31 ) ;
F_172 ( V_2 -> V_241 ) ;
V_2 -> V_241 = NULL ;
F_11 ( V_2 ) ;
F_173 ( V_2 -> V_309 , V_2 ) ;
F_110 ( V_2 ) ;
for ( V_80 = 0 ; V_80 < V_310 ; V_80 ++ ) {
if ( V_2 -> V_311 [ V_80 ] ) {
F_174 ( V_2 -> V_311 [ V_80 ] ) ;
V_2 -> V_311 [ V_80 ] = NULL ;
}
if ( V_2 -> V_312 [ V_80 ] ) {
F_175 ( V_2 -> V_312 [ V_80 ] ,
V_2 -> V_313 [ V_80 ] ) ;
V_2 -> V_312 [ V_80 ] = 0 ;
}
}
F_176 ( V_2 -> V_314 . V_315 ) ;
F_176 ( V_2 -> V_316 . V_315 ) ;
F_177 ( V_2 ) ;
return 0 ;
}
static int F_178 ( struct V_307 * V_308 ,
struct V_1 * V_2 ,
enum V_317 V_188 )
{
struct V_318 * V_319 ;
V_319 = F_179 ( V_308 , V_320 , V_188 ) ;
if ( ! V_319 ) {
F_105 ( V_2 -> V_31 , L_72 ) ;
return - V_321 ;
}
if ( ! F_180 ( V_319 -> V_322 , F_181 ( V_319 ) , V_308 -> V_79 ) ) {
F_105 ( V_2 -> V_31 ,
L_73 ) ;
return - V_321 ;
}
V_2 -> V_312 [ V_188 ] = V_319 -> V_322 ;
V_2 -> V_313 [ V_188 ] = F_181 ( V_319 ) ;
V_2 -> V_311 [ V_188 ] = F_182 ( V_2 -> V_312 [ V_188 ] ,
V_2 -> V_313 [ V_188 ] ) ;
if ( ! V_2 -> V_311 [ V_188 ] ) {
F_105 ( V_2 -> V_31 , L_74 ) ;
return - V_321 ;
}
return 0 ;
}
static int T_7 F_183 ( struct V_307 * V_308 )
{
struct V_270 * V_52 = V_308 -> V_31 . V_323 ;
struct V_1 * V_2 ;
int V_136 ;
int V_80 , V_324 ;
if ( V_52 == NULL )
return - V_36 ;
V_2 = F_184 ( sizeof( * V_2 ) , V_325 ) ;
if ( ! V_2 ) {
F_105 ( & V_308 -> V_31 , L_75 ) ;
return - V_326 ;
}
V_2 -> V_46 = V_46 ;
V_2 -> V_327 . V_328 = F_6 ;
F_185 ( & V_2 -> V_237 ) ;
F_186 ( & V_2 -> V_329 ) ;
V_2 -> V_31 = & V_308 -> V_31 ;
V_2 -> V_52 = V_52 ;
V_2 -> V_238 = 0 ;
V_2 -> V_330 = F_187 ( 32 ) ;
V_2 -> V_31 -> V_331 = & V_2 -> V_330 ;
V_2 -> V_31 -> V_332 = F_187 ( 32 ) ;
F_188 ( V_308 , V_2 ) ;
V_2 -> V_314 . V_315 = F_189 ( & V_308 -> V_31 , L_76 ) ;
V_2 -> V_316 . V_315 = F_189 ( & V_308 -> V_31 , L_77 ) ;
V_136 = F_178 ( V_308 , V_2 , V_3 ) ;
if ( V_136 < 0 )
goto error;
V_136 = F_112 ( V_2 ) ;
if ( V_136 < 0 )
goto error;
if ( F_7 ( V_2 ) == NULL )
goto error;
V_136 = F_75 ( V_2 ) ;
if ( V_136 < 0 )
goto V_333;
V_2 -> V_42 = F_3 ( V_2 , V_3 , V_4 ) ;
F_62 ( V_2 -> V_31 , L_78 ,
( V_2 -> V_42 & 0xf0 ) >> 4 , V_2 -> V_42 & 0x0f ) ;
for ( V_324 = 0 ; V_324 < F_19 ( V_334 ) ; V_324 ++ )
if ( V_2 -> V_42 == V_334 [ V_324 ] . V_335 )
break;
if ( V_324 == F_19 ( V_334 ) ) {
F_105 ( V_2 -> V_31 , L_79 ,
( V_2 -> V_42 & 0xf0 ) >> 4 , V_2 -> V_42 & 0xf ) ;
V_136 = - V_321 ;
goto V_333;
}
for ( V_80 = 1 ; V_80 < V_310 ; V_80 ++ ) {
if ( V_334 [ V_324 ] . V_336 & 1 << V_80 ) {
V_136 = F_178 ( V_308 , V_2 , V_80 ) ;
if ( V_136 )
goto V_333;
}
}
V_2 -> V_241 = F_190 ( V_308 -> V_31 . V_337 ) ;
if ( ! V_2 -> V_241 ) {
F_105 ( V_2 -> V_31 , L_80 ) ;
V_136 = - V_326 ;
goto V_333;
}
V_136 = F_191 ( V_2 -> V_241 , & V_308 -> V_31 ) ;
if ( V_136 ) {
F_105 ( & V_308 -> V_31 , L_81 , V_136 ) ;
goto V_338;
}
V_2 -> V_309 = F_192 ( V_308 , 0 ) ;
if ( V_2 -> V_309 <= 0 ) {
F_105 ( V_2 -> V_31 , L_82 ) ;
V_136 = - V_321 ;
goto V_339;
}
if ( F_193 ( V_2 -> V_309 , F_24 , V_340 , L_83 , V_2 ) ) {
F_105 ( V_2 -> V_31 , L_84 ) ;
V_136 = - V_36 ;
goto V_339;
}
V_136 = F_159 ( V_2 ) ;
if ( V_136 < 0 )
goto V_341;
V_136 = F_138 ( V_2 ) ;
if ( V_136 < 0 )
goto V_342;
F_12 ( V_2 , 1 ) ;
F_11 ( V_2 ) ;
return 0 ;
V_342:
F_150 ( V_2 ) ;
V_341:
F_173 ( V_2 -> V_309 , V_2 ) ;
V_339:
F_171 ( V_2 -> V_241 , & V_308 -> V_31 ) ;
V_338:
F_172 ( V_2 -> V_241 ) ;
V_333:
F_11 ( V_2 ) ;
error:
F_110 ( V_2 ) ;
for ( V_80 = 0 ; V_80 < V_310 ; V_80 ++ ) {
if ( V_2 -> V_311 [ V_80 ] ) {
F_174 ( V_2 -> V_311 [ V_80 ] ) ;
V_2 -> V_311 [ V_80 ] = NULL ;
}
if ( V_2 -> V_312 [ V_80 ] ) {
F_175 ( V_2 -> V_312 [ V_80 ] ,
V_2 -> V_313 [ V_80 ] ) ;
V_2 -> V_312 [ V_80 ] = 0 ;
}
}
F_176 ( V_2 -> V_316 . V_315 ) ;
F_176 ( V_2 -> V_314 . V_315 ) ;
F_188 ( V_308 , NULL ) ;
F_194 ( & V_2 -> V_237 ) ;
F_177 ( V_2 ) ;
return V_136 ;
}
