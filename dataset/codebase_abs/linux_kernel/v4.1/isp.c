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
! ( V_164 -> V_18 & V_171 ) ) {
F_65 ( V_166 , - V_169 ) ;
F_65 ( V_167 , - V_168 ) ;
return 0 ;
}
if ( V_165 == V_170 &&
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
enum V_172 V_173 )
{
struct V_1 * V_2 = V_103 -> V_135 -> V_2 ;
struct V_147 * V_111 ;
struct V_174 * V_175 ;
struct V_154 * V_110 ;
unsigned long V_18 ;
int V_155 ;
if ( V_103 -> V_176 & V_2 -> V_177 )
return - V_178 ;
F_12 ( & V_103 -> V_19 , V_18 ) ;
V_103 -> V_179 &= ~ ( V_180 | V_181 ) ;
F_13 ( & V_103 -> V_19 , V_18 ) ;
V_103 -> V_182 = false ;
V_111 = & V_103 -> V_135 -> V_183 . V_111 ;
while ( 1 ) {
V_175 = & V_111 -> V_184 [ 0 ] ;
if ( ! ( V_175 -> V_18 & V_185 ) )
break;
V_175 = F_71 ( V_175 ) ;
if ( V_175 == NULL ||
F_60 ( V_175 -> V_111 ) != V_156 )
break;
V_111 = V_175 -> V_111 ;
V_110 = F_62 ( V_111 ) ;
V_155 = F_63 ( V_110 , V_183 , V_186 , V_173 ) ;
if ( V_155 < 0 && V_155 != - V_159 )
return V_155 ;
if ( V_110 == & V_2 -> V_96 . V_110 ) {
F_63 ( & V_2 -> V_125 . V_110 , V_183 ,
V_186 , V_173 ) ;
F_63 ( & V_2 -> V_123 . V_110 , V_183 ,
V_186 , V_173 ) ;
F_63 ( & V_2 -> V_97 . V_110 , V_183 ,
V_186 , V_173 ) ;
V_103 -> V_182 = true ;
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
unsigned long V_187 = V_188 + V_189 ;
while ( ! F_80 ( V_188 , V_187 ) ) {
if ( ! F_79 ( V_2 ) )
return 0 ;
}
return 1 ;
}
static int F_81 ( struct V_102 * V_103 )
{
struct V_1 * V_2 = V_103 -> V_135 -> V_2 ;
struct V_147 * V_111 ;
struct V_174 * V_175 ;
struct V_154 * V_110 ;
int V_190 = 0 ;
int V_155 ;
V_111 = & V_103 -> V_135 -> V_183 . V_111 ;
while ( 1 ) {
V_175 = & V_111 -> V_184 [ 0 ] ;
if ( ! ( V_175 -> V_18 & V_185 ) )
break;
V_175 = F_71 ( V_175 ) ;
if ( V_175 == NULL ||
F_60 ( V_175 -> V_111 ) != V_156 )
break;
V_111 = V_175 -> V_111 ;
V_110 = F_62 ( V_111 ) ;
if ( V_110 == & V_2 -> V_96 . V_110 ) {
F_63 ( & V_2 -> V_125 . V_110 ,
V_183 , V_186 , 0 ) ;
F_63 ( & V_2 -> V_123 . V_110 ,
V_183 , V_186 , 0 ) ;
F_63 ( & V_2 -> V_97 . V_110 ,
V_183 , V_186 , 0 ) ;
}
V_155 = F_63 ( V_110 , V_183 , V_186 , 0 ) ;
if ( V_110 == & V_2 -> V_121 . V_110 )
V_155 |= F_78 ( V_2 , F_72 ) ;
else if ( V_110 == & V_2 -> V_116 . V_110 )
V_155 |= F_78 ( V_2 , F_74 ) ;
else if ( V_110 == & V_2 -> V_96 . V_110 )
V_155 |= F_78 ( V_2 , F_76 ) ;
if ( V_155 ) {
F_82 ( V_2 -> V_24 , L_42 , V_110 -> V_40 ) ;
V_2 -> V_191 = true ;
if ( V_110 == & V_2 -> V_116 . V_110 )
V_2 -> V_177 |= 1U << V_110 -> V_111 . V_8 ;
V_190 = - V_192 ;
}
}
return V_190 ;
}
int F_83 ( struct V_102 * V_103 ,
enum V_172 V_179 )
{
int V_155 ;
if ( V_179 == V_193 )
V_155 = F_81 ( V_103 ) ;
else
V_155 = F_70 ( V_103 , V_179 ) ;
if ( V_155 == 0 || V_179 == V_193 )
V_103 -> V_194 = V_179 ;
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
int V_195 = V_103 -> V_194 == V_196 ;
F_87 ( V_103 -> V_135 , ! V_195 ) ;
if ( V_195 )
F_87 ( V_103 -> V_74 , 0 ) ;
F_70 ( V_103 , V_103 -> V_194 ) ;
}
static void F_88 ( struct V_102 * V_103 )
{
F_81 ( V_103 ) ;
}
static int F_89 ( struct V_147 * V_197 )
{
struct V_102 * V_103 ;
struct V_174 * V_175 ;
if ( ! V_197 -> V_103 )
return 0 ;
V_103 = F_44 ( V_197 ) ;
if ( V_103 -> V_194 == V_193 )
return 0 ;
V_175 = F_71 ( & V_103 -> V_135 -> V_175 ) ;
return V_175 -> V_111 == V_197 ;
}
static void F_90 ( struct V_147 * V_197 )
{
if ( F_89 ( V_197 ) )
F_88 ( F_44 ( V_197 ) ) ;
}
static void F_91 ( struct V_147 * V_197 )
{
if ( F_89 ( V_197 ) )
F_86 ( F_44 ( V_197 ) ) ;
}
static int F_92 ( struct V_1 * V_2 )
{
unsigned long V_187 ;
F_93 ( & V_2 -> V_125 ) ;
F_93 ( & V_2 -> V_123 ) ;
F_93 ( & V_2 -> V_97 ) ;
F_90 ( & V_2 -> V_121 . V_110 . V_111 ) ;
F_90 ( & V_2 -> V_116 . V_110 . V_111 ) ;
F_90 ( & V_2 -> V_96 . V_110 . V_111 ) ;
F_90 ( & V_2 -> V_113 . V_110 . V_111 ) ;
F_90 ( & V_2 -> V_109 . V_110 . V_111 ) ;
V_187 = V_188 + V_189 ;
while ( F_77 ( & V_2 -> V_123 )
|| F_77 ( & V_2 -> V_125 )
|| F_77 ( & V_2 -> V_97 )
|| F_75 ( & V_2 -> V_116 )
|| F_73 ( & V_2 -> V_121 )
|| F_38 ( & V_2 -> V_96 ) ) {
if ( F_80 ( V_188 , V_187 ) ) {
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
unsigned long V_187 = 0 ;
F_2 ( V_2 ,
F_3 ( V_2 , V_3 , V_68 )
| V_198 ,
V_3 , V_68 ) ;
while ( ! ( F_3 ( V_2 , V_3 ,
V_199 ) & 0x1 ) ) {
if ( V_187 ++ > 10000 ) {
F_98 ( V_2 -> V_24 , L_44 ) ;
return - V_192 ;
}
F_99 ( 1 ) ;
}
V_2 -> V_191 = false ;
V_2 -> V_177 = 0 ;
return 0 ;
}
static void
F_100 ( struct V_1 * V_2 , struct V_200 * V_201 )
{
struct V_200 * V_202 = V_201 ;
for (; V_202 -> V_203 != V_204 ; V_202 ++ )
V_202 -> V_205 = F_3 ( V_2 , V_202 -> V_206 , V_202 -> V_203 ) ;
}
static void
F_101 ( struct V_1 * V_2 , struct V_200 * V_201 )
{
struct V_200 * V_202 = V_201 ;
for (; V_202 -> V_203 != V_204 ; V_202 ++ )
F_2 ( V_2 , V_202 -> V_205 , V_202 -> V_206 , V_202 -> V_203 ) ;
}
static void F_102 ( struct V_1 * V_2 )
{
F_100 ( V_2 , V_207 ) ;
F_103 ( V_2 -> V_24 ) ;
}
static void F_104 ( struct V_1 * V_2 )
{
F_101 ( V_2 , V_207 ) ;
F_105 ( V_2 -> V_24 ) ;
F_106 ( V_2 ) ;
F_107 ( V_2 ) ;
}
void F_108 ( struct V_1 * V_2 , enum V_208 V_209 )
{
T_1 V_210 = 0 ;
V_2 -> V_211 |= V_209 ;
if ( V_2 -> V_211 & V_212 )
V_210 |= V_213 ;
if ( V_2 -> V_211 & V_214 )
V_210 |= V_215 ;
if ( V_2 -> V_211 & V_216 )
V_210 |= V_217 ;
if ( V_2 -> V_211 & V_218 )
V_210 |= V_219 ;
if ( V_2 -> V_211 & V_220 )
V_210 |= V_221 ;
if ( V_2 -> V_211 & V_222 )
V_210 |= V_223 ;
F_109 ( V_2 , V_3 , V_72 , V_210 ) ;
}
void F_110 ( struct V_1 * V_2 , enum V_208 V_209 )
{
T_1 V_210 = 0 ;
V_2 -> V_211 &= ~ V_209 ;
if ( ! ( V_2 -> V_211 & V_212 ) )
V_210 |= V_213 ;
if ( ! ( V_2 -> V_211 & V_214 ) )
V_210 |= V_215 ;
if ( ! ( V_2 -> V_211 & V_216 ) )
V_210 |= V_217 ;
if ( ! ( V_2 -> V_211 & V_218 ) )
V_210 |= V_219 ;
if ( ! ( V_2 -> V_211 & V_220 ) )
V_210 |= V_221 ;
if ( ! ( V_2 -> V_211 & V_222 ) )
V_210 |= V_223 ;
F_111 ( V_2 , V_3 , V_72 , V_210 ) ;
}
int F_112 ( struct V_147 * V_197 , T_3 * V_224 ,
T_4 * V_225 )
{
struct V_102 * V_103 = F_44 ( V_197 ) ;
if ( V_103 -> V_194 == V_193 ||
( V_103 -> V_194 == V_196 &&
! F_113 ( V_103 ) ) )
return 0 ;
F_40 ( V_225 , 1 ) ;
F_114 () ;
if ( F_89 ( V_197 ) ) {
struct V_226 * V_183 = V_103 -> V_135 ;
unsigned long V_18 ;
F_12 ( & V_183 -> V_227 , V_18 ) ;
if ( V_183 -> V_228 & V_229 ) {
F_13 ( & V_183 -> V_227 , V_18 ) ;
F_40 ( V_225 , 0 ) ;
F_114 () ;
return 0 ;
}
F_13 ( & V_183 -> V_227 , V_18 ) ;
if ( ! F_115 ( * V_224 , ! F_116 ( V_225 ) ,
F_117 ( 1000 ) ) ) {
F_40 ( V_225 , 0 ) ;
F_114 () ;
return - V_192 ;
}
}
return 0 ;
}
int F_118 ( T_3 * V_224 ,
T_4 * V_225 )
{
if ( F_119 ( V_225 , 1 , 0 ) ) {
F_120 ( V_224 ) ;
return 1 ;
}
return 0 ;
}
static void F_121 ( struct V_1 * V_2 )
{
T_1 V_26 = 0 ;
if ( V_2 -> V_230 &
( V_231 | V_232 ) )
V_26 |= V_233 ;
if ( V_2 -> V_230 & V_234 )
V_26 |= V_235 ;
if ( V_2 -> V_230 & V_236 )
V_26 |= V_237 ;
if ( V_2 -> V_230 & V_238 )
V_26 |= V_239 | V_240 ;
if ( V_2 -> V_230 & V_241 )
V_26 |= V_242 | V_243 ;
F_5 ( V_2 , V_3 , V_72 ,
V_244 , V_26 ) ;
}
void F_122 ( struct V_1 * V_2 ,
enum V_245 V_209 )
{
V_2 -> V_230 |= V_209 ;
F_121 ( V_2 ) ;
}
void F_123 ( struct V_1 * V_2 ,
enum V_245 V_209 )
{
V_2 -> V_230 &= ~ V_209 ;
F_121 ( V_2 ) ;
}
static int F_124 ( struct V_1 * V_2 )
{
int V_246 ;
unsigned long V_22 ;
V_246 = F_125 ( V_2 -> clock [ V_247 ] ) ;
if ( V_246 ) {
F_126 ( V_2 -> V_24 , L_45 ) ;
goto V_248;
}
V_246 = F_127 ( V_2 -> clock [ V_249 ] , V_250 ) ;
if ( V_246 ) {
F_126 ( V_2 -> V_24 , L_46 ) ;
goto V_251;
}
V_246 = F_125 ( V_2 -> clock [ V_249 ] ) ;
if ( V_246 ) {
F_126 ( V_2 -> V_24 , L_47 ) ;
goto V_251;
}
V_22 = F_128 ( V_2 -> clock [ V_249 ] ) ;
if ( V_22 != V_250 )
F_129 ( V_2 -> V_24 , L_48
L_49
L_50 , V_250 , V_22 ) ;
V_246 = F_125 ( V_2 -> clock [ V_252 ] ) ;
if ( V_246 ) {
F_126 ( V_2 -> V_24 , L_51 ) ;
goto V_253;
}
return 0 ;
V_253:
F_130 ( V_2 -> clock [ V_249 ] ) ;
V_251:
F_130 ( V_2 -> clock [ V_247 ] ) ;
V_248:
return V_246 ;
}
static void F_131 ( struct V_1 * V_2 )
{
F_130 ( V_2 -> clock [ V_247 ] ) ;
F_130 ( V_2 -> clock [ V_249 ] ) ;
F_130 ( V_2 -> clock [ V_252 ] ) ;
}
static int F_132 ( struct V_1 * V_2 )
{
struct V_26 * V_26 ;
unsigned int V_38 ;
for ( V_38 = 0 ; V_38 < F_22 ( V_254 ) ; ++ V_38 ) {
V_26 = F_133 ( V_2 -> V_24 , V_254 [ V_38 ] ) ;
if ( F_27 ( V_26 ) ) {
F_126 ( V_2 -> V_24 , L_52 , V_254 [ V_38 ] ) ;
return F_28 ( V_26 ) ;
}
V_2 -> clock [ V_38 ] = V_26 ;
}
return 0 ;
}
static struct V_1 * F_134 ( struct V_1 * V_2 , bool V_46 )
{
struct V_1 * V_255 = V_2 ;
if ( V_2 == NULL )
return NULL ;
F_67 ( & V_2 -> V_256 ) ;
if ( V_2 -> V_257 > 0 )
goto V_258;
if ( F_124 ( V_2 ) < 0 ) {
V_255 = NULL ;
goto V_258;
}
if ( V_2 -> V_259 )
F_104 ( V_2 ) ;
if ( V_46 )
F_33 ( V_2 ) ;
V_258:
if ( V_255 != NULL )
V_2 -> V_257 ++ ;
F_68 ( & V_2 -> V_256 ) ;
return V_255 ;
}
struct V_1 * F_8 ( struct V_1 * V_2 )
{
return F_134 ( V_2 , true ) ;
}
static void F_135 ( struct V_1 * V_2 , bool V_260 )
{
if ( V_2 == NULL )
return;
F_67 ( & V_2 -> V_256 ) ;
F_136 ( V_2 -> V_257 == 0 ) ;
if ( -- V_2 -> V_257 == 0 ) {
F_34 ( V_2 ) ;
if ( V_260 ) {
F_102 ( V_2 ) ;
V_2 -> V_259 = 1 ;
}
if ( V_2 -> V_177 || V_2 -> V_191 )
F_97 ( V_2 ) ;
F_131 ( V_2 ) ;
}
F_68 ( & V_2 -> V_256 ) ;
}
void F_10 ( struct V_1 * V_2 )
{
F_135 ( V_2 , true ) ;
}
void F_137 ( struct V_1 * V_2 )
{
F_20 ( V_2 -> V_24 , L_53 ) ;
F_138 ( V_2 , V_261 ) ;
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
F_139 ( V_2 , V_276 ) ;
F_139 ( V_2 , V_277 ) ;
F_20 ( V_2 -> V_24 , L_54 ) ;
}
static int F_140 ( struct V_101 * V_24 )
{
struct V_1 * V_2 = F_141 ( V_24 ) ;
int V_278 ;
F_64 ( F_142 ( & V_2 -> V_256 ) ) ;
if ( V_2 -> V_257 == 0 )
return 0 ;
V_278 = F_92 ( V_2 ) ;
F_34 ( V_2 ) ;
F_102 ( V_2 ) ;
if ( V_278 )
F_97 ( V_2 ) ;
return 0 ;
}
static int F_143 ( struct V_101 * V_24 )
{
struct V_1 * V_2 = F_141 ( V_24 ) ;
F_64 ( F_142 ( & V_2 -> V_256 ) ) ;
if ( V_2 -> V_257 )
F_131 ( V_2 ) ;
return 0 ;
}
static int F_144 ( struct V_101 * V_24 )
{
struct V_1 * V_2 = F_141 ( V_24 ) ;
if ( V_2 -> V_257 == 0 )
return 0 ;
return F_124 ( V_2 ) ;
}
static void F_145 ( struct V_101 * V_24 )
{
struct V_1 * V_2 = F_141 ( V_24 ) ;
if ( V_2 -> V_257 == 0 )
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
F_153 ( & V_2 -> V_279 ) ;
F_154 ( & V_2 -> V_280 ) ;
}
static struct V_154 *
F_155 ( struct V_1 * V_2 ,
struct V_281 * V_282 )
{
struct V_283 * V_284 ;
struct V_154 * V_285 ;
if ( V_282 -> V_286 == NULL )
return NULL ;
V_284 = F_156 ( V_282 -> V_287 ) ;
if ( V_284 == NULL ) {
F_126 ( V_2 -> V_24 ,
L_55 ,
V_25 , V_282 -> V_287 ,
V_282 -> V_286 -> type ) ;
return NULL ;
}
V_285 = F_157 ( & V_2 -> V_279 , V_284 ,
V_282 -> V_286 , NULL ) ;
if ( V_285 == NULL ) {
F_126 ( V_2 -> V_24 , L_56 ,
V_25 , V_282 -> V_286 -> type ) ;
return NULL ;
}
return V_285 ;
}
static int F_158 (
struct V_1 * V_2 , struct V_147 * V_111 ,
enum V_288 V_289 )
{
struct V_147 * V_74 ;
unsigned int V_18 ;
unsigned int V_175 ;
unsigned int V_38 ;
switch ( V_289 ) {
case V_290 :
V_74 = & V_2 -> V_96 . V_110 . V_111 ;
V_175 = V_291 ;
V_18 = 0 ;
break;
case V_292 :
V_74 = & V_2 -> V_113 . V_110 . V_111 ;
V_175 = V_293 ;
V_18 = V_294 | V_171 ;
break;
case V_295 :
case V_296 :
V_74 = & V_2 -> V_109 . V_110 . V_111 ;
V_175 = V_297 ;
V_18 = 0 ;
break;
case V_298 :
V_74 = & V_2 -> V_299 . V_110 . V_111 ;
V_175 = V_293 ;
V_18 = V_294 | V_171 ;
break;
default:
F_126 ( V_2 -> V_24 , L_57 , V_25 ,
V_289 ) ;
return - V_39 ;
}
if ( ! V_74 -> V_300 ) {
F_126 ( V_2 -> V_24 , L_58 , V_111 -> V_40 ,
V_289 ) ;
return - V_39 ;
}
for ( V_38 = 0 ; V_38 < V_111 -> V_300 ; V_38 ++ ) {
if ( V_111 -> V_184 [ V_38 ] . V_18 & V_301 )
break;
}
if ( V_38 == V_111 -> V_300 ) {
F_126 ( V_2 -> V_24 , L_59 ,
V_25 ) ;
return - V_39 ;
}
return F_159 ( V_111 , V_38 , V_74 , V_175 , V_18 ) ;
}
static int F_160 ( struct V_1 * V_2 )
{
struct V_302 * V_303 = V_2 -> V_303 ;
struct V_281 * V_282 ;
int V_155 ;
V_2 -> V_280 . V_24 = V_2 -> V_24 ;
F_161 ( V_2 -> V_280 . V_304 , L_60 ,
sizeof( V_2 -> V_280 . V_304 ) ) ;
V_2 -> V_280 . V_305 = V_2 -> V_65 ;
V_2 -> V_280 . V_306 = F_69 ;
V_155 = F_162 ( & V_2 -> V_280 ) ;
if ( V_155 < 0 ) {
F_126 ( V_2 -> V_24 , L_61 ,
V_25 , V_155 ) ;
return V_155 ;
}
V_2 -> V_279 . V_307 = & V_2 -> V_280 ;
V_155 = F_163 ( V_2 -> V_24 , & V_2 -> V_279 ) ;
if ( V_155 < 0 ) {
F_126 ( V_2 -> V_24 , L_62 ,
V_25 , V_155 ) ;
goto V_308;
}
V_155 = F_164 ( & V_2 -> V_109 , & V_2 -> V_279 ) ;
if ( V_155 < 0 )
goto V_308;
V_155 = F_165 ( & V_2 -> V_113 , & V_2 -> V_279 ) ;
if ( V_155 < 0 )
goto V_308;
V_155 = F_166 ( & V_2 -> V_96 , & V_2 -> V_279 ) ;
if ( V_155 < 0 )
goto V_308;
V_155 = F_167 ( & V_2 -> V_116 ,
& V_2 -> V_279 ) ;
if ( V_155 < 0 )
goto V_308;
V_155 = F_168 ( & V_2 -> V_121 , & V_2 -> V_279 ) ;
if ( V_155 < 0 )
goto V_308;
V_155 = F_169 ( & V_2 -> V_125 , & V_2 -> V_279 ) ;
if ( V_155 < 0 )
goto V_308;
V_155 = F_169 ( & V_2 -> V_123 , & V_2 -> V_279 ) ;
if ( V_155 < 0 )
goto V_308;
V_155 = F_169 ( & V_2 -> V_97 , & V_2 -> V_279 ) ;
if ( V_155 < 0 )
goto V_308;
if ( V_2 -> V_24 -> V_35 )
return 0 ;
for ( V_282 = V_303 ? V_303 -> V_309 : NULL ;
V_282 && V_282 -> V_286 ; V_282 ++ ) {
struct V_154 * V_285 ;
V_285 = F_155 ( V_2 , V_282 ) ;
if ( ! V_285 || ! V_282 -> V_310 )
continue;
V_285 -> V_311 = V_282 -> V_310 ;
V_155 = F_158 ( V_2 , & V_285 -> V_111 ,
V_282 -> V_310 -> V_289 ) ;
if ( V_155 < 0 )
goto V_308;
}
V_155 = F_170 ( & V_2 -> V_279 ) ;
V_308:
if ( V_155 < 0 ) {
F_146 ( V_2 ) ;
F_171 ( & V_2 -> V_312 ) ;
}
return V_155 ;
}
static void F_172 ( struct V_1 * V_2 )
{
F_173 ( V_2 ) ;
F_174 ( V_2 ) ;
F_175 ( V_2 ) ;
F_176 ( V_2 ) ;
F_177 ( V_2 ) ;
F_178 ( V_2 ) ;
F_179 ( V_2 ) ;
F_180 ( V_2 ) ;
}
static int F_181 ( struct V_1 * V_2 )
{
int V_155 ;
V_155 = F_182 ( V_2 ) ;
if ( V_155 < 0 ) {
F_126 ( V_2 -> V_24 , L_63 ) ;
goto V_313;
}
V_155 = F_183 ( V_2 ) ;
if ( V_155 < 0 ) {
F_126 ( V_2 -> V_24 , L_64 ) ;
goto V_314;
}
V_155 = F_184 ( V_2 ) ;
if ( V_155 < 0 ) {
F_126 ( V_2 -> V_24 , L_65 ) ;
goto V_315;
}
V_155 = F_185 ( V_2 ) ;
if ( V_155 < 0 ) {
F_126 ( V_2 -> V_24 , L_66 ) ;
goto V_316;
}
V_155 = F_186 ( V_2 ) ;
if ( V_155 < 0 ) {
F_126 ( V_2 -> V_24 , L_67 ) ;
goto V_317;
}
V_155 = F_187 ( V_2 ) ;
if ( V_155 < 0 ) {
F_126 ( V_2 -> V_24 , L_68 ) ;
goto V_318;
}
V_155 = F_188 ( V_2 ) ;
if ( V_155 < 0 ) {
F_126 ( V_2 -> V_24 , L_69 ) ;
goto V_319;
}
V_155 = F_189 ( V_2 ) ;
if ( V_155 < 0 ) {
F_126 ( V_2 -> V_24 , L_70 ) ;
goto V_320;
}
V_155 = F_190 ( V_2 ) ;
if ( V_155 < 0 ) {
F_126 ( V_2 -> V_24 , L_71 ) ;
goto V_321;
}
V_155 = F_159 (
& V_2 -> V_113 . V_110 . V_111 , V_322 ,
& V_2 -> V_96 . V_110 . V_111 , V_291 , 0 ) ;
if ( V_155 < 0 )
goto V_323;
V_155 = F_159 (
& V_2 -> V_109 . V_110 . V_111 , V_324 ,
& V_2 -> V_96 . V_110 . V_111 , V_291 , 0 ) ;
if ( V_155 < 0 )
goto V_323;
V_155 = F_159 (
& V_2 -> V_96 . V_110 . V_111 , V_325 ,
& V_2 -> V_116 . V_110 . V_111 , V_326 , 0 ) ;
if ( V_155 < 0 )
goto V_323;
V_155 = F_159 (
& V_2 -> V_96 . V_110 . V_111 , V_327 ,
& V_2 -> V_121 . V_110 . V_111 , V_328 , 0 ) ;
if ( V_155 < 0 )
goto V_323;
V_155 = F_159 (
& V_2 -> V_116 . V_110 . V_111 , V_329 ,
& V_2 -> V_121 . V_110 . V_111 , V_328 , 0 ) ;
if ( V_155 < 0 )
goto V_323;
V_155 = F_159 (
& V_2 -> V_96 . V_110 . V_111 , V_325 ,
& V_2 -> V_125 . V_110 . V_111 , 0 ,
V_171 | V_294 ) ;
if ( V_155 < 0 )
goto V_323;
V_155 = F_159 (
& V_2 -> V_96 . V_110 . V_111 , V_325 ,
& V_2 -> V_123 . V_110 . V_111 , 0 ,
V_171 | V_294 ) ;
if ( V_155 < 0 )
goto V_323;
V_155 = F_159 (
& V_2 -> V_96 . V_110 . V_111 , V_325 ,
& V_2 -> V_97 . V_110 . V_111 , 0 ,
V_171 | V_294 ) ;
if ( V_155 < 0 )
goto V_323;
return 0 ;
V_323:
F_174 ( V_2 ) ;
V_321:
F_173 ( V_2 ) ;
V_320:
F_175 ( V_2 ) ;
V_319:
F_176 ( V_2 ) ;
V_318:
F_177 ( V_2 ) ;
V_317:
F_178 ( V_2 ) ;
V_316:
F_179 ( V_2 ) ;
V_315:
F_180 ( V_2 ) ;
V_314:
V_313:
return V_155 ;
}
static void F_191 ( struct V_1 * V_2 )
{
F_192 ( V_2 -> V_330 ) ;
V_2 -> V_330 = NULL ;
F_193 ( V_2 -> V_24 ) ;
}
static int F_194 ( struct V_1 * V_2 )
{
struct V_331 * V_330 ;
struct V_332 * V_333 ;
int V_155 ;
V_333 = F_195 () ;
if ( F_27 ( V_333 ) ) {
F_126 ( V_2 -> V_24 , L_72 ) ;
return F_28 ( V_333 ) ;
}
V_155 = F_196 ( V_333 , V_2 -> V_24 ) ;
F_197 ( V_333 ) ;
if ( V_155 < 0 ) {
F_126 ( V_2 -> V_24 , L_73 ) ;
return V_155 ;
}
V_330 = F_198 ( & V_334 , V_335 , V_336 ) ;
if ( F_27 ( V_330 ) ) {
F_126 ( V_2 -> V_24 , L_74 ) ;
V_155 = F_28 ( V_330 ) ;
goto error;
}
V_2 -> V_330 = V_330 ;
V_155 = F_199 ( V_2 -> V_24 , V_330 ) ;
if ( V_155 < 0 ) {
F_126 ( V_2 -> V_24 , L_75 ) ;
goto error;
}
return 0 ;
error:
F_191 ( V_2 ) ;
return V_155 ;
}
static int F_200 ( struct V_337 * V_338 )
{
struct V_1 * V_2 = F_201 ( V_338 ) ;
F_171 ( & V_2 -> V_312 ) ;
F_146 ( V_2 ) ;
F_172 ( V_2 ) ;
F_30 ( V_2 ) ;
F_134 ( V_2 , false ) ;
F_191 ( V_2 ) ;
F_135 ( V_2 , false ) ;
return 0 ;
}
static int F_202 ( struct V_101 * V_24 , struct V_33 * V_339 ,
struct V_340 * V_341 )
{
struct V_342 * V_343 = & V_341 -> V_310 ;
struct V_344 V_345 ;
unsigned int V_38 ;
F_203 ( V_339 , & V_345 ) ;
F_20 ( V_24 , L_76 , V_339 -> V_346 ,
V_345 . V_347 . V_348 ) ;
switch ( V_345 . V_347 . V_348 ) {
case V_349 :
V_343 -> V_289 = V_290 ;
V_343 -> V_310 . V_350 . V_88 =
V_345 . V_310 . V_350 . V_351 ;
V_343 -> V_310 . V_350 . V_86 =
! ! ( V_345 . V_310 . V_350 . V_18
& V_352 ) ;
V_343 -> V_310 . V_350 . V_353 =
! ! ( V_345 . V_310 . V_350 . V_18 & V_354 ) ;
V_343 -> V_310 . V_350 . V_355 =
! ! ( V_345 . V_310 . V_350 . V_18 & V_356 ) ;
V_343 -> V_310 . V_350 . V_357 =
! ! ( V_345 . V_310 . V_350 . V_18 & V_358 ) ;
V_343 -> V_310 . V_350 . V_359 =
! ! ( V_345 . V_310 . V_350 . V_18 & V_360 ) ;
break;
case V_361 :
case V_362 :
switch ( V_345 . V_347 . V_348 ) {
case V_361 :
V_343 -> V_289 = V_298 ;
break;
case V_362 :
V_343 -> V_289 = V_292 ;
break;
}
V_343 -> V_310 . V_363 . V_364 . V_26 . V_365 = V_345 . V_310 . V_366 . V_367 ;
V_343 -> V_310 . V_363 . V_364 . V_26 . V_368 =
V_345 . V_310 . V_366 . V_369 [ 0 ] ;
F_20 ( V_24 , L_77 ,
V_343 -> V_310 . V_363 . V_364 . V_26 . V_368 ,
V_343 -> V_310 . V_363 . V_364 . V_26 . V_365 ) ;
for ( V_38 = 0 ; V_38 < V_370 ; V_38 ++ ) {
V_343 -> V_310 . V_363 . V_364 . V_29 [ V_38 ] . V_365 =
V_345 . V_310 . V_366 . V_371 [ V_38 ] ;
V_343 -> V_310 . V_363 . V_364 . V_29 [ V_38 ] . V_368 =
V_345 . V_310 . V_366 . V_369 [ V_38 + 1 ] ;
F_20 ( V_24 , L_78 , V_38 ,
V_343 -> V_310 . V_363 . V_364 . V_29 [ V_38 ] . V_368 ,
V_343 -> V_310 . V_363 . V_364 . V_29 [ V_38 ] . V_365 ) ;
}
V_343 -> V_310 . V_363 . V_372 = 1 ;
break;
default:
F_129 ( V_24 , L_79 , V_339 -> V_346 ,
V_345 . V_347 . V_348 ) ;
break;
}
return 0 ;
}
static int F_204 ( struct V_101 * V_24 ,
struct V_373 * V_312 )
{
struct V_33 * V_339 = NULL ;
V_312 -> V_309 = F_205 (
V_24 , V_374 , sizeof( * V_312 -> V_309 ) , V_375 ) ;
if ( ! V_312 -> V_309 )
return - V_376 ;
while ( V_312 -> V_377 < V_374 &&
( V_339 = F_206 ( V_24 -> V_35 , V_339 ) ) ) {
struct V_340 * V_341 ;
V_341 = F_207 ( V_24 , sizeof( * V_341 ) , V_375 ) ;
if ( ! V_341 ) {
F_208 ( V_339 ) ;
return - V_376 ;
}
V_312 -> V_309 [ V_312 -> V_377 ] = & V_341 -> V_378 ;
if ( F_202 ( V_24 , V_339 , V_341 ) ) {
F_208 ( V_339 ) ;
return - V_39 ;
}
V_341 -> V_378 . V_379 . V_380 . V_339 = F_209 ( V_339 ) ;
F_208 ( V_339 ) ;
if ( ! V_341 -> V_378 . V_379 . V_380 . V_339 ) {
F_129 ( V_24 , L_80 ) ;
return - V_39 ;
}
V_341 -> V_378 . V_381 = V_382 ;
V_312 -> V_377 ++ ;
}
return V_312 -> V_377 ;
}
static int F_210 ( struct V_373 * V_383 ,
struct V_154 * V_110 ,
struct V_384 * V_378 )
{
struct V_1 * V_2 = F_211 ( V_383 , struct V_1 ,
V_312 ) ;
struct V_340 * V_341 =
F_211 ( V_378 , struct V_340 , V_378 ) ;
int V_155 ;
V_155 = F_158 ( V_2 , & V_110 -> V_111 , V_341 -> V_310 . V_289 ) ;
if ( V_155 < 0 )
return V_155 ;
V_341 -> V_285 = V_110 ;
V_341 -> V_285 -> V_311 = & V_341 -> V_310 ;
return V_155 ;
}
static int F_212 ( struct V_373 * V_383 )
{
struct V_1 * V_2 = F_211 ( V_383 , struct V_1 ,
V_312 ) ;
return F_170 ( & V_2 -> V_279 ) ;
}
static int F_213 ( struct V_337 * V_338 )
{
struct V_1 * V_2 ;
struct V_385 * V_386 ;
int V_155 ;
int V_38 , V_387 ;
V_2 = F_207 ( & V_338 -> V_24 , sizeof( * V_2 ) , V_375 ) ;
if ( ! V_2 ) {
F_126 ( & V_338 -> V_24 , L_81 ) ;
return - V_376 ;
}
if ( F_214 ( V_388 ) && V_338 -> V_24 . V_35 ) {
V_155 = F_215 ( V_338 -> V_24 . V_35 , L_82 ,
& V_2 -> V_389 ) ;
if ( V_155 )
return V_155 ;
V_2 -> V_390 = F_216 ( V_338 -> V_24 . V_35 ,
L_83 ) ;
if ( F_27 ( V_2 -> V_390 ) )
return F_28 ( V_2 -> V_390 ) ;
V_155 = F_217 ( V_338 -> V_24 . V_35 , L_83 , 1 ,
& V_2 -> V_391 ) ;
if ( V_155 )
return V_155 ;
V_155 = F_204 ( & V_338 -> V_24 , & V_2 -> V_312 ) ;
if ( V_155 < 0 )
return V_155 ;
V_155 = F_218 ( & V_2 -> V_279 ,
& V_2 -> V_312 ) ;
if ( V_155 )
return V_155 ;
} else {
V_2 -> V_303 = V_338 -> V_24 . V_392 ;
V_2 -> V_390 = F_219 ( L_84 ) ;
if ( F_27 ( V_2 -> V_390 ) )
return F_28 ( V_2 -> V_390 ) ;
F_129 ( & V_338 -> V_24 ,
L_85 ) ;
}
V_2 -> V_69 = V_69 ;
F_220 ( & V_2 -> V_256 ) ;
F_25 ( & V_2 -> V_393 ) ;
V_2 -> V_24 = & V_338 -> V_24 ;
V_2 -> V_257 = 0 ;
V_155 = F_221 ( V_2 -> V_24 , F_222 ( 32 ) ) ;
if ( V_155 )
goto error;
F_223 ( V_338 , V_2 ) ;
V_2 -> V_394 . V_395 = F_224 ( & V_338 -> V_24 , L_86 ) ;
V_2 -> V_396 . V_395 = F_224 ( & V_338 -> V_24 , L_87 ) ;
for ( V_38 = 0 ; V_38 < 2 ; V_38 ++ ) {
unsigned int V_397 = V_38 ? V_398 : 0 ;
V_386 = F_225 ( V_338 , V_399 , V_38 ) ;
V_2 -> V_400 [ V_397 ] =
F_226 ( V_2 -> V_24 , V_386 ) ;
if ( F_27 ( V_2 -> V_400 [ V_397 ] ) )
return F_28 ( V_2 -> V_400 [ V_397 ] ) ;
}
V_155 = F_132 ( V_2 ) ;
if ( V_155 < 0 )
goto error;
V_155 = F_227 ( V_2 -> clock [ V_247 ] ) ;
if ( V_155 < 0 )
goto error;
V_2 -> V_65 = F_3 ( V_2 , V_3 , V_4 ) ;
F_82 ( V_2 -> V_24 , L_88 ,
( V_2 -> V_65 & 0xf0 ) >> 4 , V_2 -> V_65 & 0x0f ) ;
F_228 ( V_2 -> clock [ V_247 ] ) ;
if ( F_134 ( V_2 , false ) == NULL ) {
V_155 = - V_401 ;
goto error;
}
V_155 = F_97 ( V_2 ) ;
if ( V_155 < 0 )
goto V_402;
V_155 = F_24 ( V_2 ) ;
if ( V_155 < 0 )
goto V_402;
for ( V_387 = 0 ; V_387 < F_22 ( V_403 ) ; V_387 ++ )
if ( V_2 -> V_65 == V_403 [ V_387 ] . V_404 )
break;
if ( V_387 == F_22 ( V_403 ) ) {
F_126 ( V_2 -> V_24 , L_89 ,
( V_2 -> V_65 & 0xf0 ) >> 4 , V_2 -> V_65 & 0xf ) ;
V_155 = - V_401 ;
goto V_402;
}
if ( ! F_214 ( V_388 ) || ! V_338 -> V_24 . V_35 ) {
V_2 -> V_391 = V_403 [ V_387 ] . V_391 ;
V_2 -> V_389 = V_403 [ V_387 ] . V_389 ;
}
for ( V_38 = 1 ; V_38 < V_398 ; V_38 ++ )
V_2 -> V_400 [ V_38 ] =
V_2 -> V_400 [ 0 ] + V_403 [ V_387 ] . V_405 [ V_38 ] ;
for ( V_38 = V_406 ; V_38 < V_407 ; V_38 ++ )
V_2 -> V_400 [ V_38 ] =
V_2 -> V_400 [ V_398 ]
+ V_403 [ V_387 ] . V_405 [ V_38 ] ;
V_2 -> V_408 =
V_386 -> V_409 + V_403 [ V_387 ] . V_405 [ V_410 ] ;
V_155 = F_194 ( V_2 ) ;
if ( V_155 < 0 ) {
F_126 ( & V_338 -> V_24 , L_90 ) ;
goto V_402;
}
V_2 -> V_411 = F_229 ( V_338 , 0 ) ;
if ( V_2 -> V_411 <= 0 ) {
F_126 ( V_2 -> V_24 , L_91 ) ;
V_155 = - V_401 ;
goto V_412;
}
if ( F_230 ( V_2 -> V_24 , V_2 -> V_411 , F_46 , V_413 ,
L_92 , V_2 ) ) {
F_126 ( V_2 -> V_24 , L_93 ) ;
V_155 = - V_39 ;
goto V_412;
}
V_155 = F_181 ( V_2 ) ;
if ( V_155 < 0 )
goto V_412;
V_2 -> V_312 . V_414 = F_210 ;
V_2 -> V_312 . V_415 = F_212 ;
V_155 = F_160 ( V_2 ) ;
if ( V_155 < 0 )
goto V_416;
F_35 ( V_2 , 1 ) ;
F_10 ( V_2 ) ;
return 0 ;
V_416:
F_172 ( V_2 ) ;
V_412:
F_191 ( V_2 ) ;
V_402:
F_30 ( V_2 ) ;
F_135 ( V_2 , false ) ;
error:
F_231 ( & V_2 -> V_256 ) ;
return V_155 ;
}
