void F_1 ( struct V_1 * V_2 )
{
F_2 ( V_2 , 0 , V_3 , V_4 ) ;
F_3 ( V_2 , V_3 , V_4 ) ;
}
static void F_4 ( struct V_5 * V_6 , T_1 V_7 )
{
switch ( V_6 -> V_8 ) {
case V_9 :
F_5 ( V_6 -> V_2 , V_3 , V_10 ,
V_11 ,
V_7 << V_12 ) ;
break;
case V_13 :
F_5 ( V_6 -> V_2 , V_3 , V_10 ,
V_14 ,
V_7 << V_15 ) ;
break;
}
}
static int F_6 ( struct V_16 * V_17 )
{
struct V_5 * V_6 = F_7 ( V_17 ) ;
F_8 ( V_6 -> V_2 ) ;
return 0 ;
}
static void F_9 ( struct V_16 * V_17 )
{
struct V_5 * V_6 = F_7 ( V_17 ) ;
F_10 ( V_6 -> V_2 ) ;
}
static int F_11 ( struct V_16 * V_17 )
{
struct V_5 * V_6 = F_7 ( V_17 ) ;
unsigned long V_18 ;
F_12 ( & V_6 -> V_19 , V_18 ) ;
F_4 ( V_6 , V_6 -> V_7 ) ;
V_6 -> V_20 = true ;
F_13 ( & V_6 -> V_19 , V_18 ) ;
return 0 ;
}
static void F_14 ( struct V_16 * V_17 )
{
struct V_5 * V_6 = F_7 ( V_17 ) ;
unsigned long V_18 ;
F_12 ( & V_6 -> V_19 , V_18 ) ;
F_4 ( V_6 , 0 ) ;
V_6 -> V_20 = false ;
F_13 ( & V_6 -> V_19 , V_18 ) ;
}
static unsigned long F_15 ( struct V_16 * V_17 ,
unsigned long V_21 )
{
struct V_5 * V_6 = F_7 ( V_17 ) ;
return V_21 / V_6 -> V_7 ;
}
static T_1 F_16 ( unsigned long * V_22 , unsigned long V_21 )
{
T_1 V_7 ;
if ( * V_22 >= V_21 ) {
* V_22 = V_21 ;
return V_23 ;
}
if ( * V_22 == 0 )
* V_22 = 1 ;
V_7 = F_17 ( V_21 , * V_22 ) ;
if ( V_7 >= V_23 )
V_7 = V_23 - 1 ;
* V_22 = V_21 / V_7 ;
return V_7 ;
}
static long F_18 ( struct V_16 * V_17 , unsigned long V_22 ,
unsigned long * V_21 )
{
F_16 ( & V_22 , * V_21 ) ;
return V_22 ;
}
static int F_19 ( struct V_16 * V_17 , unsigned long V_22 ,
unsigned long V_21 )
{
struct V_5 * V_6 = F_7 ( V_17 ) ;
unsigned long V_18 ;
T_1 V_7 ;
V_7 = F_16 ( & V_22 , V_21 ) ;
F_12 ( & V_6 -> V_19 , V_18 ) ;
V_6 -> V_7 = V_7 ;
if ( V_6 -> V_20 )
F_4 ( V_6 , V_7 ) ;
F_13 ( & V_6 -> V_19 , V_18 ) ;
F_20 ( V_6 -> V_2 -> V_24 , L_1 ,
V_25 , V_6 -> V_8 == V_9 ? 'a' : 'b' , V_22 , V_7 ) ;
return 0 ;
}
static struct V_26 * F_21 ( struct V_27 * V_28 , void * V_29 )
{
unsigned int V_30 = V_28 -> args [ 0 ] ;
struct V_1 * V_2 = V_29 ;
if ( V_30 >= F_22 ( V_2 -> V_31 ) )
return F_23 ( - V_32 ) ;
return V_2 -> V_31 [ V_30 ] . V_26 ;
}
static int F_24 ( struct V_1 * V_2 )
{
struct V_33 * V_34 = V_2 -> V_24 -> V_35 ;
struct V_36 V_37 ;
unsigned int V_38 ;
for ( V_38 = 0 ; V_38 < F_22 ( V_2 -> V_31 ) ; ++ V_38 )
V_2 -> V_31 [ V_38 ] . V_26 = F_23 ( - V_39 ) ;
for ( V_38 = 0 ; V_38 < F_22 ( V_2 -> V_31 ) ; ++ V_38 ) {
struct V_5 * V_6 = & V_2 -> V_31 [ V_38 ] ;
V_6 -> V_2 = V_2 ;
V_6 -> V_8 = V_38 == 0 ? V_9 : V_13 ;
V_6 -> V_7 = 1 ;
F_25 ( & V_6 -> V_19 ) ;
V_37 . V_40 = V_38 == 0 ? L_2 : L_3 ;
V_37 . V_41 = & V_42 ;
V_37 . V_43 = & V_44 ;
V_37 . V_45 = 1 ;
V_6 -> V_17 . V_37 = & V_37 ;
V_6 -> V_26 = F_26 ( NULL , & V_6 -> V_17 ) ;
if ( F_27 ( V_6 -> V_26 ) )
return F_28 ( V_6 -> V_26 ) ;
}
if ( V_34 )
F_29 ( V_34 , F_21 , V_2 ) ;
return 0 ;
}
static void F_30 ( struct V_1 * V_2 )
{
struct V_33 * V_34 = V_2 -> V_24 -> V_35 ;
unsigned int V_38 ;
if ( V_34 )
F_31 ( V_34 ) ;
for ( V_38 = 0 ; V_38 < F_22 ( V_2 -> V_31 ) ; ++ V_38 ) {
struct V_5 * V_6 = & V_2 -> V_31 [ V_38 ] ;
if ( ! F_27 ( V_6 -> V_26 ) )
F_32 ( V_6 -> V_26 ) ;
}
}
static void F_33 ( struct V_1 * V_2 )
{
static const T_1 V_46 = V_47
| V_48
| V_49
| V_50
| V_51
| V_52
| V_53
| V_54
| V_55
| V_56
| V_57
| V_58 ;
F_2 ( V_2 , V_46 , V_3 , V_59 ) ;
F_2 ( V_2 , V_46 , V_3 , V_60 ) ;
}
static void F_34 ( struct V_1 * V_2 )
{
F_2 ( V_2 , 0 , V_3 , V_60 ) ;
}
static void F_35 ( struct V_1 * V_2 , int V_61 )
{
F_2 ( V_2 ,
( ( V_61 ? V_62 :
V_63 ) <<
V_64 ) |
( ( V_2 -> V_65 == V_66 ) ?
V_67 : 0 ) ,
V_3 , V_68 ) ;
F_2 ( V_2 ,
( V_2 -> V_69 ? V_70 : 0 ) |
V_71 ,
V_3 , V_72 ) ;
}
void F_36 ( struct V_1 * V_2 ,
enum V_73 V_74 ,
const struct V_75 * V_76 ,
unsigned int V_77 , unsigned int V_78 )
{
T_1 V_79 ;
V_79 = F_3 ( V_2 , V_3 , V_72 ) ;
V_79 &= ~ V_80 ;
V_79 &= ~ V_81 ;
V_79 &= ~ V_82 ;
V_79 &= ~ V_83 ;
V_79 |= V_78 ;
switch ( V_74 ) {
case V_84 :
V_79 |= V_85 ;
V_79 |= V_76 -> V_86 << V_87 ;
V_77 += V_76 -> V_88 * 2 ;
break;
case V_89 :
V_79 |= V_90 ;
break;
case V_91 :
V_79 |= V_92 ;
break;
case V_93 :
V_79 |= V_94 ;
break;
default:
return;
}
V_79 |= ( ( V_77 / 2 ) << V_95 ) & V_80 ;
F_2 ( V_2 , V_79 , V_3 , V_72 ) ;
}
void F_37 ( struct V_1 * V_2 )
{
if ( F_38 ( & V_2 -> V_96 ) ||
F_39 ( & V_2 -> V_97 ) ) {
F_40 ( & V_2 -> V_97 . V_98 , 1 ) ;
F_20 ( V_2 -> V_24 , L_4
L_5 ) ;
}
}
static inline void F_41 ( struct V_1 * V_2 , T_1 V_99 )
{
static const char * V_40 [] = {
L_6 ,
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
} ;
int V_38 ;
F_20 ( V_2 -> V_24 , L_38 ) ;
for ( V_38 = 0 ; V_38 < F_22 ( V_40 ) ; V_38 ++ ) {
if ( ( 1 << V_38 ) & V_99 )
F_42 ( V_100 L_39 , V_40 [ V_38 ] ) ;
}
F_42 ( V_100 L_40 ) ;
}
static void F_43 ( struct V_1 * V_2 )
{
struct V_101 * V_24 = V_2 -> V_24 ;
struct V_102 * V_103 ;
T_1 V_104 ;
V_104 = F_3 ( V_2 , V_105 , V_106 ) ;
F_2 ( V_2 , V_104 , V_105 , V_106 ) ;
V_104 &= ~ V_107 ;
if ( V_104 )
F_20 ( V_24 , L_41 , V_104 ) ;
if ( V_104 & V_108 ) {
V_103 = F_44 ( & V_2 -> V_109 . V_110 . V_111 ) ;
if ( V_103 != NULL )
V_103 -> error = true ;
}
if ( V_104 & V_112 ) {
V_103 = F_44 ( & V_2 -> V_113 . V_110 . V_111 ) ;
if ( V_103 != NULL )
V_103 -> error = true ;
}
if ( V_104 & V_114 ) {
V_103 = F_44 ( & V_2 -> V_96 . V_110 . V_111 ) ;
if ( V_103 != NULL )
V_103 -> error = true ;
}
if ( V_104 & V_115 ) {
V_103 = F_44 ( & V_2 -> V_116 . V_110 . V_111 ) ;
if ( V_103 != NULL )
V_103 -> error = true ;
}
if ( V_104 & ( V_117
| V_118
| V_119
| V_120 ) ) {
V_103 = F_44 ( & V_2 -> V_121 . V_110 . V_111 ) ;
if ( V_103 != NULL )
V_103 -> error = true ;
}
if ( V_104 & V_122 )
F_45 ( & V_2 -> V_123 ) ;
if ( V_104 & V_124 )
F_45 ( & V_2 -> V_125 ) ;
}
static T_2 F_46 ( int V_46 , void * V_126 )
{
static const T_1 V_127 = V_128 |
V_129 |
V_130 |
V_131 |
V_132 ;
struct V_1 * V_2 = V_126 ;
T_1 V_99 ;
V_99 = F_3 ( V_2 , V_3 , V_59 ) ;
F_2 ( V_2 , V_99 , V_3 , V_59 ) ;
F_43 ( V_2 ) ;
if ( V_99 & V_133 )
F_47 ( & V_2 -> V_113 ) ;
if ( V_99 & V_134 )
F_48 ( & V_2 -> V_109 ) ;
if ( V_99 & V_130 ) {
if ( V_2 -> V_96 . V_135 & V_136 )
F_49 ( & V_2 -> V_116 ) ;
if ( V_2 -> V_96 . V_135 & V_137 )
F_50 ( & V_2 -> V_121 ) ;
F_51 ( & V_2 -> V_125 ) ;
F_51 ( & V_2 -> V_123 ) ;
F_51 ( & V_2 -> V_97 ) ;
}
if ( V_99 & V_127 )
F_52 ( & V_2 -> V_96 , V_99 & V_127 ) ;
if ( V_99 & V_138 ) {
if ( V_2 -> V_116 . V_135 & V_139 )
F_50 ( & V_2 -> V_121 ) ;
F_53 ( & V_2 -> V_116 ) ;
}
if ( V_99 & V_140 )
F_54 ( & V_2 -> V_121 ) ;
if ( V_99 & V_141 )
F_55 ( & V_2 -> V_125 ) ;
if ( V_99 & V_142 )
F_55 ( & V_2 -> V_123 ) ;
if ( V_99 & V_143 )
F_55 ( & V_2 -> V_97 ) ;
F_1 ( V_2 ) ;
#if F_56 ( V_144 ) && F_56 ( V_145 )
F_41 ( V_2 , V_99 ) ;
#endif
return V_146 ;
}
static int F_57 ( struct V_147 * V_111 )
{
struct V_148 V_149 ;
int V_150 = 0 ;
F_58 ( & V_149 , V_111 ) ;
while ( ( V_111 = F_59 ( & V_149 ) ) ) {
if ( F_60 ( V_111 ) == V_151 )
V_150 += V_111 -> V_152 ;
}
return V_150 ;
}
static int F_61 ( struct V_147 * V_111 , int V_153 )
{
struct V_154 * V_110 ;
int V_155 ;
V_110 = F_60 ( V_111 ) == V_156
? F_62 ( V_111 ) : NULL ;
if ( V_111 -> V_152 == 0 && V_153 > 0 && V_110 != NULL ) {
V_155 = F_63 ( V_110 , V_157 , V_158 , 1 ) ;
if ( V_155 < 0 && V_155 != - V_159 )
return V_155 ;
}
V_111 -> V_152 += V_153 ;
F_64 ( V_111 -> V_152 < 0 ) ;
if ( V_111 -> V_152 == 0 && V_153 < 0 && V_110 != NULL )
F_63 ( V_110 , V_157 , V_158 , 0 ) ;
return 0 ;
}
static int F_65 ( struct V_147 * V_111 , int V_153 )
{
struct V_148 V_149 ;
struct V_147 * V_160 = V_111 ;
int V_155 = 0 ;
if ( ! V_153 )
return 0 ;
F_58 ( & V_149 , V_111 ) ;
while ( ! V_155 && ( V_111 = F_59 ( & V_149 ) ) )
if ( F_60 ( V_111 ) != V_151 )
V_155 = F_61 ( V_111 , V_153 ) ;
if ( ! V_155 )
return 0 ;
F_58 ( & V_149 , V_160 ) ;
while ( ( V_160 = F_59 ( & V_149 ) )
&& V_160 != V_111 )
if ( F_60 ( V_160 ) != V_151 )
F_61 ( V_160 , - V_153 ) ;
return V_155 ;
}
int F_66 ( struct V_147 * V_111 , int V_150 )
{
int V_153 = V_150 ? 1 : - 1 ;
int V_155 ;
F_67 ( & V_111 -> V_161 -> V_162 ) ;
V_111 -> V_152 += V_153 ;
F_64 ( V_111 -> V_152 < 0 ) ;
V_155 = F_65 ( V_111 , V_153 ) ;
if ( V_155 < 0 )
V_111 -> V_152 -= V_153 ;
F_68 ( & V_111 -> V_161 -> V_162 ) ;
return V_155 ;
}
static int F_69 ( struct V_163 * V_164 , T_1 V_18 ,
unsigned int V_165 )
{
struct V_147 * V_166 = V_164 -> V_166 -> V_111 ;
struct V_147 * V_167 = V_164 -> V_167 -> V_111 ;
int V_168 = F_57 ( V_166 ) ;
int V_169 = F_57 ( V_167 ) ;
int V_155 ;
if ( V_165 == V_170 &&
! ( V_18 & V_171 ) ) {
F_65 ( V_166 , - V_169 ) ;
F_65 ( V_167 , - V_168 ) ;
return 0 ;
}
if ( V_165 == V_172 &&
( V_18 & V_171 ) ) {
V_155 = F_65 ( V_166 , V_169 ) ;
if ( V_155 < 0 )
return V_155 ;
V_155 = F_65 ( V_167 , V_168 ) ;
if ( V_155 < 0 )
F_65 ( V_166 , - V_169 ) ;
return V_155 ;
}
return 0 ;
}
static int F_70 ( struct V_102 * V_103 ,
enum V_173 V_174 )
{
struct V_1 * V_2 = V_103 -> V_135 -> V_2 ;
struct V_147 * V_111 ;
struct V_175 * V_176 ;
struct V_154 * V_110 ;
unsigned long V_18 ;
int V_155 ;
if ( V_103 -> V_177 & V_2 -> V_178 )
return - V_179 ;
F_12 ( & V_103 -> V_19 , V_18 ) ;
V_103 -> V_180 &= ~ ( V_181 | V_182 ) ;
F_13 ( & V_103 -> V_19 , V_18 ) ;
V_103 -> V_183 = false ;
V_111 = & V_103 -> V_135 -> V_184 . V_111 ;
while ( 1 ) {
V_176 = & V_111 -> V_185 [ 0 ] ;
if ( ! ( V_176 -> V_18 & V_186 ) )
break;
V_176 = F_71 ( V_176 ) ;
if ( V_176 == NULL ||
F_60 ( V_176 -> V_111 ) != V_156 )
break;
V_111 = V_176 -> V_111 ;
V_110 = F_62 ( V_111 ) ;
V_155 = F_63 ( V_110 , V_184 , V_187 , V_174 ) ;
if ( V_155 < 0 && V_155 != - V_159 )
return V_155 ;
if ( V_110 == & V_2 -> V_96 . V_110 ) {
F_63 ( & V_2 -> V_125 . V_110 , V_184 ,
V_187 , V_174 ) ;
F_63 ( & V_2 -> V_123 . V_110 , V_184 ,
V_187 , V_174 ) ;
F_63 ( & V_2 -> V_97 . V_110 , V_184 ,
V_187 , V_174 ) ;
V_103 -> V_183 = true ;
}
}
return 0 ;
}
static int F_72 ( struct V_1 * V_2 )
{
return F_73 ( & V_2 -> V_121 ) ;
}
static int F_74 ( struct V_1 * V_2 )
{
return F_75 ( & V_2 -> V_116 ) ;
}
static int F_76 ( struct V_1 * V_2 )
{
return F_77 ( & V_2 -> V_123 )
|| F_77 ( & V_2 -> V_125 )
|| F_77 ( & V_2 -> V_97 )
|| F_38 ( & V_2 -> V_96 ) ;
}
static int F_78 ( struct V_1 * V_2 ,
int (* F_79)( struct V_1 * V_2 ) )
{
unsigned long V_188 = V_189 + V_190 ;
while ( ! F_80 ( V_189 , V_188 ) ) {
if ( ! F_79 ( V_2 ) )
return 0 ;
}
return 1 ;
}
static int F_81 ( struct V_102 * V_103 )
{
struct V_1 * V_2 = V_103 -> V_135 -> V_2 ;
struct V_147 * V_111 ;
struct V_175 * V_176 ;
struct V_154 * V_110 ;
int V_191 = 0 ;
int V_155 ;
V_111 = & V_103 -> V_135 -> V_184 . V_111 ;
while ( 1 ) {
V_176 = & V_111 -> V_185 [ 0 ] ;
if ( ! ( V_176 -> V_18 & V_186 ) )
break;
V_176 = F_71 ( V_176 ) ;
if ( V_176 == NULL ||
F_60 ( V_176 -> V_111 ) != V_156 )
break;
V_111 = V_176 -> V_111 ;
V_110 = F_62 ( V_111 ) ;
if ( V_110 == & V_2 -> V_96 . V_110 ) {
F_63 ( & V_2 -> V_125 . V_110 ,
V_184 , V_187 , 0 ) ;
F_63 ( & V_2 -> V_123 . V_110 ,
V_184 , V_187 , 0 ) ;
F_63 ( & V_2 -> V_97 . V_110 ,
V_184 , V_187 , 0 ) ;
}
V_155 = F_63 ( V_110 , V_184 , V_187 , 0 ) ;
if ( V_110 == & V_2 -> V_121 . V_110 )
V_155 |= F_78 ( V_2 , F_72 ) ;
else if ( V_110 == & V_2 -> V_116 . V_110 )
V_155 |= F_78 ( V_2 , F_74 ) ;
else if ( V_110 == & V_2 -> V_96 . V_110 )
V_155 |= F_78 ( V_2 , F_76 ) ;
if ( V_155 ) {
F_82 ( V_2 -> V_24 , L_42 , V_110 -> V_40 ) ;
V_2 -> V_192 = true ;
if ( V_110 == & V_2 -> V_116 . V_110 )
V_2 -> V_178 |= 1U << V_110 -> V_111 . V_8 ;
V_191 = - V_193 ;
}
}
return V_191 ;
}
int F_83 ( struct V_102 * V_103 ,
enum V_173 V_180 )
{
int V_155 ;
if ( V_180 == V_194 )
V_155 = F_81 ( V_103 ) ;
else
V_155 = F_70 ( V_103 , V_180 ) ;
if ( V_155 == 0 || V_180 == V_194 )
V_103 -> V_195 = V_180 ;
return V_155 ;
}
void F_84 ( struct V_102 * V_103 )
{
if ( V_103 -> V_74 )
F_85 ( V_103 -> V_74 ) ;
if ( V_103 -> V_135 )
F_85 ( V_103 -> V_135 ) ;
}
static void F_86 ( struct V_102 * V_103 )
{
int V_196 = V_103 -> V_195 == V_197 ;
F_87 ( V_103 -> V_135 , ! V_196 ) ;
if ( V_196 )
F_87 ( V_103 -> V_74 , 0 ) ;
F_70 ( V_103 , V_103 -> V_195 ) ;
}
static void F_88 ( struct V_102 * V_103 )
{
F_81 ( V_103 ) ;
}
static int F_89 ( struct V_147 * V_198 )
{
struct V_102 * V_103 ;
struct V_175 * V_176 ;
if ( ! V_198 -> V_103 )
return 0 ;
V_103 = F_44 ( V_198 ) ;
if ( V_103 -> V_195 == V_194 )
return 0 ;
V_176 = F_71 ( & V_103 -> V_135 -> V_176 ) ;
return V_176 -> V_111 == V_198 ;
}
static void F_90 ( struct V_147 * V_198 )
{
if ( F_89 ( V_198 ) )
F_88 ( F_44 ( V_198 ) ) ;
}
static void F_91 ( struct V_147 * V_198 )
{
if ( F_89 ( V_198 ) )
F_86 ( F_44 ( V_198 ) ) ;
}
static int F_92 ( struct V_1 * V_2 )
{
unsigned long V_188 ;
F_93 ( & V_2 -> V_125 ) ;
F_93 ( & V_2 -> V_123 ) ;
F_93 ( & V_2 -> V_97 ) ;
F_90 ( & V_2 -> V_121 . V_110 . V_111 ) ;
F_90 ( & V_2 -> V_116 . V_110 . V_111 ) ;
F_90 ( & V_2 -> V_96 . V_110 . V_111 ) ;
F_90 ( & V_2 -> V_113 . V_110 . V_111 ) ;
F_90 ( & V_2 -> V_109 . V_110 . V_111 ) ;
V_188 = V_189 + V_190 ;
while ( F_77 ( & V_2 -> V_123 )
|| F_77 ( & V_2 -> V_125 )
|| F_77 ( & V_2 -> V_97 )
|| F_75 ( & V_2 -> V_116 )
|| F_73 ( & V_2 -> V_121 )
|| F_38 ( & V_2 -> V_96 ) ) {
if ( F_80 ( V_189 , V_188 ) ) {
F_82 ( V_2 -> V_24 , L_43 ) ;
return 1 ;
}
F_94 ( 1 ) ;
}
return 0 ;
}
static void F_95 ( struct V_1 * V_2 )
{
F_96 ( & V_2 -> V_125 ) ;
F_96 ( & V_2 -> V_123 ) ;
F_96 ( & V_2 -> V_97 ) ;
F_91 ( & V_2 -> V_121 . V_110 . V_111 ) ;
F_91 ( & V_2 -> V_116 . V_110 . V_111 ) ;
F_91 ( & V_2 -> V_96 . V_110 . V_111 ) ;
F_91 ( & V_2 -> V_113 . V_110 . V_111 ) ;
F_91 ( & V_2 -> V_109 . V_110 . V_111 ) ;
}
static int F_97 ( struct V_1 * V_2 )
{
unsigned long V_188 = 0 ;
F_2 ( V_2 ,
F_3 ( V_2 , V_3 , V_68 )
| V_199 ,
V_3 , V_68 ) ;
while ( ! ( F_3 ( V_2 , V_3 ,
V_200 ) & 0x1 ) ) {
if ( V_188 ++ > 10000 ) {
F_98 ( V_2 -> V_24 , L_44 ) ;
return - V_193 ;
}
F_99 ( 1 ) ;
}
V_2 -> V_192 = false ;
V_2 -> V_178 = 0 ;
return 0 ;
}
static void
F_100 ( struct V_1 * V_2 , struct V_201 * V_202 )
{
struct V_201 * V_203 = V_202 ;
for (; V_203 -> V_204 != V_205 ; V_203 ++ )
V_203 -> V_206 = F_3 ( V_2 , V_203 -> V_207 , V_203 -> V_204 ) ;
}
static void
F_101 ( struct V_1 * V_2 , struct V_201 * V_202 )
{
struct V_201 * V_203 = V_202 ;
for (; V_203 -> V_204 != V_205 ; V_203 ++ )
F_2 ( V_2 , V_203 -> V_206 , V_203 -> V_207 , V_203 -> V_204 ) ;
}
static void F_102 ( struct V_1 * V_2 )
{
F_100 ( V_2 , V_208 ) ;
F_103 ( V_2 -> V_24 ) ;
}
static void F_104 ( struct V_1 * V_2 )
{
F_101 ( V_2 , V_208 ) ;
F_105 ( V_2 -> V_24 ) ;
F_106 ( V_2 ) ;
F_107 ( V_2 ) ;
}
void F_108 ( struct V_1 * V_2 , enum V_209 V_210 )
{
T_1 V_211 = 0 ;
V_2 -> V_212 |= V_210 ;
if ( V_2 -> V_212 & V_213 )
V_211 |= V_214 ;
if ( V_2 -> V_212 & V_215 )
V_211 |= V_216 ;
if ( V_2 -> V_212 & V_217 )
V_211 |= V_218 ;
if ( V_2 -> V_212 & V_219 )
V_211 |= V_220 ;
if ( V_2 -> V_212 & V_221 )
V_211 |= V_222 ;
if ( V_2 -> V_212 & V_223 )
V_211 |= V_224 ;
F_109 ( V_2 , V_3 , V_72 , V_211 ) ;
}
void F_110 ( struct V_1 * V_2 , enum V_209 V_210 )
{
T_1 V_211 = 0 ;
V_2 -> V_212 &= ~ V_210 ;
if ( ! ( V_2 -> V_212 & V_213 ) )
V_211 |= V_214 ;
if ( ! ( V_2 -> V_212 & V_215 ) )
V_211 |= V_216 ;
if ( ! ( V_2 -> V_212 & V_217 ) )
V_211 |= V_218 ;
if ( ! ( V_2 -> V_212 & V_219 ) )
V_211 |= V_220 ;
if ( ! ( V_2 -> V_212 & V_221 ) )
V_211 |= V_222 ;
if ( ! ( V_2 -> V_212 & V_223 ) )
V_211 |= V_224 ;
F_111 ( V_2 , V_3 , V_72 , V_211 ) ;
}
int F_112 ( struct V_147 * V_198 , T_3 * V_225 ,
T_4 * V_226 )
{
struct V_102 * V_103 = F_44 ( V_198 ) ;
if ( V_103 -> V_195 == V_194 ||
( V_103 -> V_195 == V_197 &&
! F_113 ( V_103 ) ) )
return 0 ;
F_40 ( V_226 , 1 ) ;
F_114 () ;
if ( F_89 ( V_198 ) ) {
struct V_227 * V_184 = V_103 -> V_135 ;
unsigned long V_18 ;
F_12 ( & V_184 -> V_228 , V_18 ) ;
if ( V_184 -> V_229 & V_230 ) {
F_13 ( & V_184 -> V_228 , V_18 ) ;
F_40 ( V_226 , 0 ) ;
F_114 () ;
return 0 ;
}
F_13 ( & V_184 -> V_228 , V_18 ) ;
if ( ! F_115 ( * V_225 , ! F_116 ( V_226 ) ,
F_117 ( 1000 ) ) ) {
F_40 ( V_226 , 0 ) ;
F_114 () ;
return - V_193 ;
}
}
return 0 ;
}
int F_118 ( T_3 * V_225 ,
T_4 * V_226 )
{
if ( F_119 ( V_226 , 1 , 0 ) ) {
F_120 ( V_225 ) ;
return 1 ;
}
return 0 ;
}
static void F_121 ( struct V_1 * V_2 )
{
T_1 V_26 = 0 ;
if ( V_2 -> V_231 &
( V_232 | V_233 ) )
V_26 |= V_234 ;
if ( V_2 -> V_231 & V_235 )
V_26 |= V_236 ;
if ( V_2 -> V_231 & V_237 )
V_26 |= V_238 ;
if ( V_2 -> V_231 & V_239 )
V_26 |= V_240 | V_241 ;
if ( V_2 -> V_231 & V_242 )
V_26 |= V_243 | V_244 ;
F_5 ( V_2 , V_3 , V_72 ,
V_245 , V_26 ) ;
}
void F_122 ( struct V_1 * V_2 ,
enum V_246 V_210 )
{
V_2 -> V_231 |= V_210 ;
F_121 ( V_2 ) ;
}
void F_123 ( struct V_1 * V_2 ,
enum V_246 V_210 )
{
V_2 -> V_231 &= ~ V_210 ;
F_121 ( V_2 ) ;
}
static int F_124 ( struct V_1 * V_2 )
{
int V_247 ;
unsigned long V_22 ;
V_247 = F_125 ( V_2 -> clock [ V_248 ] ) ;
if ( V_247 ) {
F_126 ( V_2 -> V_24 , L_45 ) ;
goto V_249;
}
V_247 = F_127 ( V_2 -> clock [ V_250 ] , V_251 ) ;
if ( V_247 ) {
F_126 ( V_2 -> V_24 , L_46 ) ;
goto V_252;
}
V_247 = F_125 ( V_2 -> clock [ V_250 ] ) ;
if ( V_247 ) {
F_126 ( V_2 -> V_24 , L_47 ) ;
goto V_252;
}
V_22 = F_128 ( V_2 -> clock [ V_250 ] ) ;
if ( V_22 != V_251 )
F_129 ( V_2 -> V_24 , L_48
L_49
L_50 , V_251 , V_22 ) ;
V_247 = F_125 ( V_2 -> clock [ V_253 ] ) ;
if ( V_247 ) {
F_126 ( V_2 -> V_24 , L_51 ) ;
goto V_254;
}
return 0 ;
V_254:
F_130 ( V_2 -> clock [ V_250 ] ) ;
V_252:
F_130 ( V_2 -> clock [ V_248 ] ) ;
V_249:
return V_247 ;
}
static void F_131 ( struct V_1 * V_2 )
{
F_130 ( V_2 -> clock [ V_248 ] ) ;
F_130 ( V_2 -> clock [ V_250 ] ) ;
F_130 ( V_2 -> clock [ V_253 ] ) ;
}
static int F_132 ( struct V_1 * V_2 )
{
struct V_26 * V_26 ;
unsigned int V_38 ;
for ( V_38 = 0 ; V_38 < F_22 ( V_255 ) ; ++ V_38 ) {
V_26 = F_133 ( V_2 -> V_24 , V_255 [ V_38 ] ) ;
if ( F_27 ( V_26 ) ) {
F_126 ( V_2 -> V_24 , L_52 , V_255 [ V_38 ] ) ;
return F_28 ( V_26 ) ;
}
V_2 -> clock [ V_38 ] = V_26 ;
}
return 0 ;
}
static struct V_1 * F_134 ( struct V_1 * V_2 , bool V_46 )
{
struct V_1 * V_256 = V_2 ;
if ( V_2 == NULL )
return NULL ;
F_67 ( & V_2 -> V_257 ) ;
if ( V_2 -> V_258 > 0 )
goto V_259;
if ( F_124 ( V_2 ) < 0 ) {
V_256 = NULL ;
goto V_259;
}
if ( V_2 -> V_260 )
F_104 ( V_2 ) ;
if ( V_46 )
F_33 ( V_2 ) ;
V_259:
if ( V_256 != NULL )
V_2 -> V_258 ++ ;
F_68 ( & V_2 -> V_257 ) ;
return V_256 ;
}
struct V_1 * F_8 ( struct V_1 * V_2 )
{
return F_134 ( V_2 , true ) ;
}
static void F_135 ( struct V_1 * V_2 , bool V_261 )
{
if ( V_2 == NULL )
return;
F_67 ( & V_2 -> V_257 ) ;
F_136 ( V_2 -> V_258 == 0 ) ;
if ( -- V_2 -> V_258 == 0 ) {
F_34 ( V_2 ) ;
if ( V_261 ) {
F_102 ( V_2 ) ;
V_2 -> V_260 = 1 ;
}
if ( V_2 -> V_178 || V_2 -> V_192 )
F_97 ( V_2 ) ;
F_131 ( V_2 ) ;
}
F_68 ( & V_2 -> V_257 ) ;
}
void F_10 ( struct V_1 * V_2 )
{
F_135 ( V_2 , true ) ;
}
void F_137 ( struct V_1 * V_2 )
{
F_20 ( V_2 -> V_24 , L_53 ) ;
F_138 ( V_2 , V_262 ) ;
F_138 ( V_2 , V_263 ) ;
F_138 ( V_2 , V_264 ) ;
F_138 ( V_2 , V_265 ) ;
F_138 ( V_2 , V_266 ) ;
F_138 ( V_2 , V_267 ) ;
F_138 ( V_2 , V_268 ) ;
F_138 ( V_2 , V_269 ) ;
F_138 ( V_2 , V_270 ) ;
F_138 ( V_2 , V_271 ) ;
F_138 ( V_2 , V_272 ) ;
F_138 ( V_2 , V_273 ) ;
F_138 ( V_2 , V_274 ) ;
F_138 ( V_2 , V_275 ) ;
F_138 ( V_2 , V_276 ) ;
F_139 ( V_2 , V_277 ) ;
F_139 ( V_2 , V_278 ) ;
F_20 ( V_2 -> V_24 , L_54 ) ;
}
static int F_140 ( struct V_101 * V_24 )
{
struct V_1 * V_2 = F_141 ( V_24 ) ;
int V_279 ;
F_64 ( F_142 ( & V_2 -> V_257 ) ) ;
if ( V_2 -> V_258 == 0 )
return 0 ;
V_279 = F_92 ( V_2 ) ;
F_34 ( V_2 ) ;
F_102 ( V_2 ) ;
if ( V_279 )
F_97 ( V_2 ) ;
return 0 ;
}
static int F_143 ( struct V_101 * V_24 )
{
struct V_1 * V_2 = F_141 ( V_24 ) ;
F_64 ( F_142 ( & V_2 -> V_257 ) ) ;
if ( V_2 -> V_258 )
F_131 ( V_2 ) ;
return 0 ;
}
static int F_144 ( struct V_101 * V_24 )
{
struct V_1 * V_2 = F_141 ( V_24 ) ;
if ( V_2 -> V_258 == 0 )
return 0 ;
return F_124 ( V_2 ) ;
}
static void F_145 ( struct V_101 * V_24 )
{
struct V_1 * V_2 = F_141 ( V_24 ) ;
if ( V_2 -> V_258 == 0 )
return;
F_104 ( V_2 ) ;
F_33 ( V_2 ) ;
F_95 ( V_2 ) ;
}
static void F_146 ( struct V_1 * V_2 )
{
F_147 ( & V_2 -> V_113 ) ;
F_148 ( & V_2 -> V_109 ) ;
F_149 ( & V_2 -> V_96 ) ;
F_150 ( & V_2 -> V_116 ) ;
F_151 ( & V_2 -> V_121 ) ;
F_152 ( & V_2 -> V_125 ) ;
F_152 ( & V_2 -> V_123 ) ;
F_152 ( & V_2 -> V_97 ) ;
F_153 ( & V_2 -> V_280 ) ;
F_154 ( & V_2 -> V_281 ) ;
}
static int F_155 (
struct V_1 * V_2 , struct V_147 * V_111 ,
enum V_282 V_283 )
{
struct V_147 * V_74 ;
unsigned int V_18 ;
unsigned int V_176 ;
unsigned int V_38 ;
switch ( V_283 ) {
case V_284 :
V_74 = & V_2 -> V_96 . V_110 . V_111 ;
V_176 = V_285 ;
V_18 = 0 ;
break;
case V_286 :
V_74 = & V_2 -> V_113 . V_110 . V_111 ;
V_176 = V_287 ;
V_18 = V_288 | V_171 ;
break;
case V_289 :
case V_290 :
V_74 = & V_2 -> V_109 . V_110 . V_111 ;
V_176 = V_291 ;
V_18 = 0 ;
break;
case V_292 :
V_74 = & V_2 -> V_293 . V_110 . V_111 ;
V_176 = V_287 ;
V_18 = V_288 | V_171 ;
break;
default:
F_126 ( V_2 -> V_24 , L_55 , V_25 ,
V_283 ) ;
return - V_39 ;
}
if ( ! V_74 -> V_294 ) {
F_126 ( V_2 -> V_24 , L_56 , V_111 -> V_40 ,
V_283 ) ;
return - V_39 ;
}
for ( V_38 = 0 ; V_38 < V_111 -> V_294 ; V_38 ++ ) {
if ( V_111 -> V_185 [ V_38 ] . V_18 & V_295 )
break;
}
if ( V_38 == V_111 -> V_294 ) {
F_126 ( V_2 -> V_24 , L_57 ,
V_25 ) ;
return - V_39 ;
}
return F_156 ( V_111 , V_38 , V_74 , V_176 , V_18 ) ;
}
static int F_157 ( struct V_1 * V_2 )
{
int V_155 ;
V_2 -> V_281 . V_24 = V_2 -> V_24 ;
F_158 ( V_2 -> V_281 . V_296 , L_58 ,
sizeof( V_2 -> V_281 . V_296 ) ) ;
V_2 -> V_281 . V_297 = V_2 -> V_65 ;
V_2 -> V_281 . V_298 = F_69 ;
V_155 = F_159 ( & V_2 -> V_281 ) ;
if ( V_155 < 0 ) {
F_126 ( V_2 -> V_24 , L_59 ,
V_25 , V_155 ) ;
return V_155 ;
}
V_2 -> V_280 . V_299 = & V_2 -> V_281 ;
V_155 = F_160 ( V_2 -> V_24 , & V_2 -> V_280 ) ;
if ( V_155 < 0 ) {
F_126 ( V_2 -> V_24 , L_60 ,
V_25 , V_155 ) ;
goto V_300;
}
V_155 = F_161 ( & V_2 -> V_109 , & V_2 -> V_280 ) ;
if ( V_155 < 0 )
goto V_300;
V_155 = F_162 ( & V_2 -> V_113 , & V_2 -> V_280 ) ;
if ( V_155 < 0 )
goto V_300;
V_155 = F_163 ( & V_2 -> V_96 , & V_2 -> V_280 ) ;
if ( V_155 < 0 )
goto V_300;
V_155 = F_164 ( & V_2 -> V_116 ,
& V_2 -> V_280 ) ;
if ( V_155 < 0 )
goto V_300;
V_155 = F_165 ( & V_2 -> V_121 , & V_2 -> V_280 ) ;
if ( V_155 < 0 )
goto V_300;
V_155 = F_166 ( & V_2 -> V_125 , & V_2 -> V_280 ) ;
if ( V_155 < 0 )
goto V_300;
V_155 = F_166 ( & V_2 -> V_123 , & V_2 -> V_280 ) ;
if ( V_155 < 0 )
goto V_300;
V_155 = F_166 ( & V_2 -> V_97 , & V_2 -> V_280 ) ;
if ( V_155 < 0 )
goto V_300;
V_300:
if ( V_155 < 0 )
F_146 ( V_2 ) ;
return V_155 ;
}
static void F_167 ( struct V_1 * V_2 )
{
F_168 ( V_2 ) ;
F_169 ( V_2 ) ;
F_170 ( V_2 ) ;
F_171 ( V_2 ) ;
F_172 ( V_2 ) ;
F_173 ( V_2 ) ;
F_174 ( V_2 ) ;
F_175 ( V_2 ) ;
}
static int F_176 ( struct V_1 * V_2 )
{
int V_155 ;
V_155 = F_177 ( V_2 ) ;
if ( V_155 < 0 ) {
F_126 ( V_2 -> V_24 , L_61 ) ;
goto V_301;
}
V_155 = F_178 ( V_2 ) ;
if ( V_155 < 0 ) {
F_126 ( V_2 -> V_24 , L_62 ) ;
goto V_302;
}
V_155 = F_179 ( V_2 ) ;
if ( V_155 < 0 ) {
F_126 ( V_2 -> V_24 , L_63 ) ;
goto V_303;
}
V_155 = F_180 ( V_2 ) ;
if ( V_155 < 0 ) {
F_126 ( V_2 -> V_24 , L_64 ) ;
goto V_304;
}
V_155 = F_181 ( V_2 ) ;
if ( V_155 < 0 ) {
F_126 ( V_2 -> V_24 , L_65 ) ;
goto V_305;
}
V_155 = F_182 ( V_2 ) ;
if ( V_155 < 0 ) {
F_126 ( V_2 -> V_24 , L_66 ) ;
goto V_306;
}
V_155 = F_183 ( V_2 ) ;
if ( V_155 < 0 ) {
F_126 ( V_2 -> V_24 , L_67 ) ;
goto V_307;
}
V_155 = F_184 ( V_2 ) ;
if ( V_155 < 0 ) {
F_126 ( V_2 -> V_24 , L_68 ) ;
goto V_308;
}
V_155 = F_185 ( V_2 ) ;
if ( V_155 < 0 ) {
F_126 ( V_2 -> V_24 , L_69 ) ;
goto V_309;
}
V_155 = F_156 (
& V_2 -> V_113 . V_110 . V_111 , V_310 ,
& V_2 -> V_96 . V_110 . V_111 , V_285 , 0 ) ;
if ( V_155 < 0 )
goto V_311;
V_155 = F_156 (
& V_2 -> V_109 . V_110 . V_111 , V_312 ,
& V_2 -> V_96 . V_110 . V_111 , V_285 , 0 ) ;
if ( V_155 < 0 )
goto V_311;
V_155 = F_156 (
& V_2 -> V_96 . V_110 . V_111 , V_313 ,
& V_2 -> V_116 . V_110 . V_111 , V_314 , 0 ) ;
if ( V_155 < 0 )
goto V_311;
V_155 = F_156 (
& V_2 -> V_96 . V_110 . V_111 , V_315 ,
& V_2 -> V_121 . V_110 . V_111 , V_316 , 0 ) ;
if ( V_155 < 0 )
goto V_311;
V_155 = F_156 (
& V_2 -> V_116 . V_110 . V_111 , V_317 ,
& V_2 -> V_121 . V_110 . V_111 , V_316 , 0 ) ;
if ( V_155 < 0 )
goto V_311;
V_155 = F_156 (
& V_2 -> V_96 . V_110 . V_111 , V_313 ,
& V_2 -> V_125 . V_110 . V_111 , 0 ,
V_171 | V_288 ) ;
if ( V_155 < 0 )
goto V_311;
V_155 = F_156 (
& V_2 -> V_96 . V_110 . V_111 , V_313 ,
& V_2 -> V_123 . V_110 . V_111 , 0 ,
V_171 | V_288 ) ;
if ( V_155 < 0 )
goto V_311;
V_155 = F_156 (
& V_2 -> V_96 . V_110 . V_111 , V_313 ,
& V_2 -> V_97 . V_110 . V_111 , 0 ,
V_171 | V_288 ) ;
if ( V_155 < 0 )
goto V_311;
return 0 ;
V_311:
F_169 ( V_2 ) ;
V_309:
F_168 ( V_2 ) ;
V_308:
F_170 ( V_2 ) ;
V_307:
F_171 ( V_2 ) ;
V_306:
F_172 ( V_2 ) ;
V_305:
F_173 ( V_2 ) ;
V_304:
F_174 ( V_2 ) ;
V_303:
F_175 ( V_2 ) ;
V_302:
V_301:
return V_155 ;
}
static void F_186 ( struct V_1 * V_2 )
{
F_187 ( V_2 -> V_318 ) ;
V_2 -> V_318 = NULL ;
F_188 ( V_2 -> V_24 ) ;
}
static int F_189 ( struct V_1 * V_2 )
{
struct V_319 * V_318 ;
struct V_320 * V_321 ;
int V_155 ;
V_321 = F_190 () ;
if ( F_27 ( V_321 ) ) {
F_126 ( V_2 -> V_24 , L_70 ) ;
return F_28 ( V_321 ) ;
}
V_155 = F_191 ( V_321 , V_2 -> V_24 ) ;
F_192 ( V_321 ) ;
if ( V_155 < 0 ) {
F_126 ( V_2 -> V_24 , L_71 ) ;
return V_155 ;
}
V_318 = F_193 ( & V_322 , V_323 , V_324 ) ;
if ( F_27 ( V_318 ) ) {
F_126 ( V_2 -> V_24 , L_72 ) ;
V_155 = F_28 ( V_318 ) ;
goto error;
}
V_2 -> V_318 = V_318 ;
V_155 = F_194 ( V_2 -> V_24 , V_318 ) ;
if ( V_155 < 0 ) {
F_126 ( V_2 -> V_24 , L_73 ) ;
goto error;
}
return 0 ;
error:
F_186 ( V_2 ) ;
return V_155 ;
}
static int F_195 ( struct V_325 * V_326 )
{
struct V_1 * V_2 = F_196 ( V_326 ) ;
F_197 ( & V_2 -> V_327 ) ;
F_146 ( V_2 ) ;
F_167 ( V_2 ) ;
F_30 ( V_2 ) ;
F_134 ( V_2 , false ) ;
F_186 ( V_2 ) ;
F_135 ( V_2 , false ) ;
return 0 ;
}
static int F_198 ( struct V_101 * V_24 , struct V_33 * V_328 ,
struct V_329 * V_330 )
{
struct V_331 * V_332 = & V_330 -> V_333 ;
struct V_334 V_335 ;
unsigned int V_38 ;
F_199 ( V_328 , & V_335 ) ;
F_20 ( V_24 , L_74 , V_328 -> V_336 ,
V_335 . V_337 . V_338 ) ;
switch ( V_335 . V_337 . V_338 ) {
case V_339 :
V_332 -> V_283 = V_284 ;
V_332 -> V_333 . V_340 . V_88 =
V_335 . V_333 . V_340 . V_341 ;
V_332 -> V_333 . V_340 . V_86 =
! ! ( V_335 . V_333 . V_340 . V_18
& V_342 ) ;
V_332 -> V_333 . V_340 . V_343 =
! ! ( V_335 . V_333 . V_340 . V_18 & V_344 ) ;
V_332 -> V_333 . V_340 . V_345 =
! ! ( V_335 . V_333 . V_340 . V_18 & V_346 ) ;
V_332 -> V_333 . V_340 . V_347 =
! ! ( V_335 . V_333 . V_340 . V_18 & V_348 ) ;
V_332 -> V_333 . V_340 . V_349 =
! ! ( V_335 . V_333 . V_340 . V_18 & V_350 ) ;
break;
case V_351 :
case V_352 :
switch ( V_335 . V_337 . V_338 ) {
case V_351 :
V_332 -> V_283 = V_292 ;
break;
case V_352 :
V_332 -> V_283 = V_286 ;
break;
}
V_332 -> V_333 . V_353 . V_354 . V_26 . V_355 = V_335 . V_333 . V_356 . V_357 ;
V_332 -> V_333 . V_353 . V_354 . V_26 . V_358 =
V_335 . V_333 . V_356 . V_359 [ 0 ] ;
F_20 ( V_24 , L_75 ,
V_332 -> V_333 . V_353 . V_354 . V_26 . V_358 ,
V_332 -> V_333 . V_353 . V_354 . V_26 . V_355 ) ;
for ( V_38 = 0 ; V_38 < V_360 ; V_38 ++ ) {
V_332 -> V_333 . V_353 . V_354 . V_29 [ V_38 ] . V_355 =
V_335 . V_333 . V_356 . V_361 [ V_38 ] ;
V_332 -> V_333 . V_353 . V_354 . V_29 [ V_38 ] . V_358 =
V_335 . V_333 . V_356 . V_359 [ V_38 + 1 ] ;
F_20 ( V_24 , L_76 , V_38 ,
V_332 -> V_333 . V_353 . V_354 . V_29 [ V_38 ] . V_358 ,
V_332 -> V_333 . V_353 . V_354 . V_29 [ V_38 ] . V_355 ) ;
}
V_332 -> V_333 . V_353 . V_362 = 1 ;
break;
default:
F_129 ( V_24 , L_77 , V_328 -> V_336 ,
V_335 . V_337 . V_338 ) ;
break;
}
return 0 ;
}
static int F_200 ( struct V_101 * V_24 ,
struct V_363 * V_327 )
{
struct V_33 * V_328 = NULL ;
V_327 -> V_364 = F_201 (
V_24 , V_365 , sizeof( * V_327 -> V_364 ) , V_366 ) ;
if ( ! V_327 -> V_364 )
return - V_367 ;
while ( V_327 -> V_368 < V_365 &&
( V_328 = F_202 ( V_24 -> V_35 , V_328 ) ) ) {
struct V_329 * V_330 ;
V_330 = F_203 ( V_24 , sizeof( * V_330 ) , V_366 ) ;
if ( ! V_330 ) {
F_204 ( V_328 ) ;
return - V_367 ;
}
V_327 -> V_364 [ V_327 -> V_368 ] = & V_330 -> V_369 ;
if ( F_198 ( V_24 , V_328 , V_330 ) ) {
F_204 ( V_328 ) ;
return - V_39 ;
}
V_330 -> V_369 . V_370 . V_371 . V_328 = F_205 ( V_328 ) ;
F_204 ( V_328 ) ;
if ( ! V_330 -> V_369 . V_370 . V_371 . V_328 ) {
F_129 ( V_24 , L_78 ) ;
return - V_39 ;
}
V_330 -> V_369 . V_372 = V_373 ;
V_327 -> V_368 ++ ;
}
return V_327 -> V_368 ;
}
static int F_206 ( struct V_363 * V_374 ,
struct V_154 * V_110 ,
struct V_375 * V_369 )
{
struct V_1 * V_2 = F_207 ( V_374 , struct V_1 ,
V_327 ) ;
struct V_329 * V_330 =
F_207 ( V_369 , struct V_329 , V_369 ) ;
int V_155 ;
V_155 = F_155 ( V_2 , & V_110 -> V_111 , V_330 -> V_333 . V_283 ) ;
if ( V_155 < 0 )
return V_155 ;
V_330 -> V_376 = V_110 ;
V_330 -> V_376 -> V_377 = & V_330 -> V_333 ;
return V_155 ;
}
static int F_208 ( struct V_363 * V_374 )
{
struct V_1 * V_2 = F_207 ( V_374 , struct V_1 ,
V_327 ) ;
return F_209 ( & V_2 -> V_280 ) ;
}
static int F_210 ( struct V_325 * V_326 )
{
struct V_1 * V_2 ;
struct V_378 * V_379 ;
int V_155 ;
int V_38 , V_380 ;
V_2 = F_203 ( & V_326 -> V_24 , sizeof( * V_2 ) , V_366 ) ;
if ( ! V_2 ) {
F_126 ( & V_326 -> V_24 , L_79 ) ;
return - V_367 ;
}
V_155 = F_211 ( V_326 -> V_24 . V_35 , L_80 ,
& V_2 -> V_381 ) ;
if ( V_155 )
return V_155 ;
V_2 -> V_382 = F_212 ( V_326 -> V_24 . V_35 ,
L_81 ) ;
if ( F_27 ( V_2 -> V_382 ) )
return F_28 ( V_2 -> V_382 ) ;
V_155 = F_213 ( V_326 -> V_24 . V_35 , L_81 , 1 ,
& V_2 -> V_383 ) ;
if ( V_155 )
return V_155 ;
V_155 = F_200 ( & V_326 -> V_24 , & V_2 -> V_327 ) ;
if ( V_155 < 0 )
return V_155 ;
V_2 -> V_69 = V_69 ;
F_214 ( & V_2 -> V_257 ) ;
F_25 ( & V_2 -> V_384 ) ;
V_2 -> V_24 = & V_326 -> V_24 ;
V_2 -> V_258 = 0 ;
V_155 = F_215 ( V_2 -> V_24 , F_216 ( 32 ) ) ;
if ( V_155 )
goto error;
F_217 ( V_326 , V_2 ) ;
V_2 -> V_385 . V_386 = F_218 ( & V_326 -> V_24 , L_82 ) ;
V_2 -> V_387 . V_386 = F_218 ( & V_326 -> V_24 , L_83 ) ;
for ( V_38 = 0 ; V_38 < 2 ; V_38 ++ ) {
unsigned int V_388 = V_38 ? V_389 : 0 ;
V_379 = F_219 ( V_326 , V_390 , V_38 ) ;
V_2 -> V_391 [ V_388 ] =
F_220 ( V_2 -> V_24 , V_379 ) ;
if ( F_27 ( V_2 -> V_391 [ V_388 ] ) )
return F_28 ( V_2 -> V_391 [ V_388 ] ) ;
}
V_155 = F_132 ( V_2 ) ;
if ( V_155 < 0 )
goto error;
V_155 = F_221 ( V_2 -> clock [ V_248 ] ) ;
if ( V_155 < 0 )
goto error;
V_2 -> V_65 = F_3 ( V_2 , V_3 , V_4 ) ;
F_82 ( V_2 -> V_24 , L_84 ,
( V_2 -> V_65 & 0xf0 ) >> 4 , V_2 -> V_65 & 0x0f ) ;
F_222 ( V_2 -> clock [ V_248 ] ) ;
if ( F_134 ( V_2 , false ) == NULL ) {
V_155 = - V_392 ;
goto error;
}
V_155 = F_97 ( V_2 ) ;
if ( V_155 < 0 )
goto V_393;
V_155 = F_24 ( V_2 ) ;
if ( V_155 < 0 )
goto V_393;
for ( V_380 = 0 ; V_380 < F_22 ( V_394 ) ; V_380 ++ )
if ( V_2 -> V_65 == V_394 [ V_380 ] . V_395 )
break;
if ( V_380 == F_22 ( V_394 ) ) {
F_126 ( V_2 -> V_24 , L_85 ,
( V_2 -> V_65 & 0xf0 ) >> 4 , V_2 -> V_65 & 0xf ) ;
V_155 = - V_392 ;
goto V_393;
}
for ( V_38 = 1 ; V_38 < V_389 ; V_38 ++ )
V_2 -> V_391 [ V_38 ] =
V_2 -> V_391 [ 0 ] + V_394 [ V_380 ] . V_396 [ V_38 ] ;
for ( V_38 = V_397 ; V_38 < V_398 ; V_38 ++ )
V_2 -> V_391 [ V_38 ] =
V_2 -> V_391 [ V_389 ]
+ V_394 [ V_380 ] . V_396 [ V_38 ] ;
V_2 -> V_399 =
V_379 -> V_400 + V_394 [ V_380 ] . V_396 [ V_401 ] ;
V_155 = F_189 ( V_2 ) ;
if ( V_155 < 0 ) {
F_126 ( & V_326 -> V_24 , L_86 ) ;
goto V_393;
}
V_2 -> V_402 = F_223 ( V_326 , 0 ) ;
if ( V_2 -> V_402 <= 0 ) {
F_126 ( V_2 -> V_24 , L_87 ) ;
V_155 = - V_392 ;
goto V_403;
}
if ( F_224 ( V_2 -> V_24 , V_2 -> V_402 , F_46 , V_404 ,
L_88 , V_2 ) ) {
F_126 ( V_2 -> V_24 , L_89 ) ;
V_155 = - V_39 ;
goto V_403;
}
V_155 = F_176 ( V_2 ) ;
if ( V_155 < 0 )
goto V_403;
V_155 = F_157 ( V_2 ) ;
if ( V_155 < 0 )
goto V_405;
V_2 -> V_327 . V_406 = F_206 ;
V_2 -> V_327 . V_407 = F_208 ;
V_155 = F_225 ( & V_2 -> V_280 , & V_2 -> V_327 ) ;
if ( V_155 )
goto V_408;
F_35 ( V_2 , 1 ) ;
F_10 ( V_2 ) ;
return 0 ;
V_408:
F_146 ( V_2 ) ;
V_405:
F_167 ( V_2 ) ;
V_403:
F_186 ( V_2 ) ;
V_393:
F_30 ( V_2 ) ;
F_135 ( V_2 , false ) ;
error:
F_226 ( & V_2 -> V_257 ) ;
return V_155 ;
}
