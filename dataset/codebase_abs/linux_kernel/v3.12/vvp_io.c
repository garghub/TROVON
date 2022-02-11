int F_1 ( const struct V_1 * V_2 , const struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
F_3 ( V_4 -> V_7 == V_8 || V_4 -> V_7 == V_9 ) ;
return V_6 -> V_10 == V_11 ;
}
static bool F_4 ( const struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_12 * V_12 )
{
struct V_13 * V_14 = F_5 ( V_12 ) ;
struct V_15 * V_16 = F_6 ( V_2 ) ;
bool V_17 = true ;
switch ( V_4 -> V_7 ) {
case V_8 :
case V_9 :
if ( V_14 -> V_18 != V_16 -> V_19 ) {
V_4 -> V_20 = 1 ;
V_4 -> V_21 = 0 ;
V_17 = false ;
}
case V_22 :
default:
break;
}
return V_17 ;
}
static int F_7 ( const struct V_1 * V_2 ,
const struct V_23 * V_24 )
{
struct V_5 * V_6 = F_8 ( V_2 , V_24 ) ;
struct V_12 * V_12 = F_9 ( V_24 -> V_25 ) ;
F_3 ( V_12 ==
F_10 ( V_2 , V_24 ) -> V_26 -> V_27 -> V_28 -> V_29 ) ;
V_6 -> V_30 . V_31 . V_32 = F_11 ( V_12 -> V_33 ) ;
return 0 ;
}
static void F_12 ( const struct V_1 * V_2 , const struct V_23 * V_24 )
{
struct V_3 * V_4 = V_24 -> V_34 ;
struct V_35 * V_36 = V_4 -> V_37 ;
struct V_15 * V_16 = F_10 ( V_2 , V_24 ) ;
F_13 ( V_2 , V_36 , F_14 ( V_36 ) ) ;
F_15 ( V_38 , L_1 ,
V_4 -> V_39 , V_4 -> V_40 , V_16 -> V_19 ) ;
if ( ! V_4 -> V_39 && V_4 -> V_40 ) {
T_1 V_41 = 0 ;
F_16 ( F_9 ( V_36 ) , & V_41 ) ;
V_4 -> V_20 = V_16 -> V_19 != V_41 ;
if ( V_4 -> V_20 )
F_15 ( V_38 , L_2 ,
V_16 -> V_19 , V_41 ) ;
}
}
static void F_17 ( const struct V_1 * V_2 ,
const struct V_23 * V_24 )
{
struct V_3 * V_4 = V_24 -> V_34 ;
struct V_42 * V_43 = V_4 -> V_30 . V_44 . V_45 ;
F_13 ( V_2 , V_4 -> V_37 , F_14 ( V_4 -> V_37 ) ) ;
if ( V_43 != NULL ) {
F_18 ( & V_43 -> V_46 , L_3 , V_4 ) ;
F_19 ( V_2 , V_43 ) ;
V_4 -> V_30 . V_44 . V_45 = NULL ;
}
F_12 ( V_2 , V_24 ) ;
}
enum V_47 F_20 ( struct V_48 * V_49 )
{
if ( ( V_49 -> V_50 & V_51 ) && ( V_49 -> V_50 & V_52 ) )
return V_53 ;
return V_54 ;
}
static int F_21 ( const struct V_1 * V_2 ,
struct V_15 * V_6 , struct V_3 * V_4 )
{
struct V_55 * V_56 = F_22 ( V_2 ) ;
struct V_57 * V_58 = V_59 -> V_58 ;
struct V_48 * V_49 ;
struct V_60 * V_61 = & V_56 -> V_62 ;
T_2 V_63 ;
unsigned long V_64 ;
unsigned long V_65 ;
T_3 V_66 ;
int V_67 ;
F_3 ( V_4 -> V_7 == V_8 || V_4 -> V_7 == V_9 ) ;
if ( ! F_1 ( V_2 , V_4 ) )
return 0 ;
if ( V_6 -> V_68 == NULL )
return 0 ;
if ( V_58 == NULL )
return 0 ;
for ( V_65 = 0 ; V_65 < V_6 -> V_69 ; V_65 ++ ) {
const struct V_70 * V_71 = & V_6 -> V_68 [ V_65 ] ;
V_64 = ( unsigned long ) V_71 -> V_72 ;
V_66 = V_71 -> V_73 ;
if ( V_66 == 0 )
continue;
V_66 += V_64 & ( ~ V_74 ) ;
V_64 &= V_74 ;
F_23 ( & V_58 -> V_75 ) ;
while( ( V_49 = F_24 ( V_58 , V_64 , V_66 ) ) != NULL ) {
struct V_12 * V_12 = V_49 -> V_76 -> V_28 -> V_29 ;
int V_77 = V_78 ;
if ( F_25 ( V_49 -> V_76 ) ) {
V_77 = V_79 ;
}
F_26 ( & V_63 , V_49 , V_64 , V_66 ) ;
V_61 -> V_80 = F_20 ( V_49 ) ;
V_61 -> V_81 = F_5 ( V_12 ) -> V_82 ;
V_61 -> V_83 = F_27 ( V_61 -> V_81 ,
V_63 . V_84 . V_85 ) ;
V_61 -> V_86 = F_27 ( V_61 -> V_81 ,
V_63 . V_84 . V_87 ) ;
V_61 -> V_88 = V_77 ;
V_67 = F_28 ( V_2 , V_4 , V_61 ) ;
F_15 ( V_38 , L_4 ,
V_61 -> V_80 , V_61 -> V_83 ,
V_61 -> V_86 ) ;
if ( V_67 < 0 )
return V_67 ;
if ( V_49 -> V_89 - V_64 >= V_66 )
break;
V_66 -= V_49 -> V_89 - V_64 ;
V_64 = V_49 -> V_89 ;
}
F_29 ( & V_58 -> V_75 ) ;
}
return 0 ;
}
static int F_30 ( const struct V_1 * V_2 , struct V_3 * V_4 ,
enum V_47 V_90 , T_4 V_85 , T_4 V_87 )
{
struct V_15 * V_16 = F_6 ( V_2 ) ;
int V_67 ;
int V_91 = 0 ;
F_3 ( V_4 -> V_7 == V_8 || V_4 -> V_7 == V_9 ) ;
F_31 ( V_2 , V_16 , V_4 ) ;
if ( V_4 -> V_30 . V_92 . V_93 )
V_91 |= V_94 ;
V_67 = F_21 ( V_2 , V_16 , V_4 ) ;
if ( V_67 == 0 )
V_67 = F_32 ( V_2 , V_4 , V_91 , V_90 , V_85 , V_87 ) ;
return V_67 ;
}
static int F_33 ( const struct V_1 * V_2 ,
const struct V_23 * V_24 )
{
struct V_3 * V_4 = V_24 -> V_34 ;
struct V_13 * V_14 = F_5 ( F_9 ( V_4 -> V_37 ) ) ;
int V_67 ;
if ( V_14 -> V_95 )
V_67 = F_30 ( V_2 , V_4 , V_54 ,
V_4 -> V_30 . V_96 . V_97 . V_98 ,
V_4 -> V_30 . V_96 . V_97 . V_98 +
V_4 -> V_30 . V_96 . V_97 . V_99 - 1 ) ;
else
V_67 = 0 ;
return V_67 ;
}
static int F_34 ( const struct V_1 * V_2 ,
const struct V_23 * V_24 )
{
struct V_3 * V_4 = V_24 -> V_34 ;
struct V_5 * V_6 = F_8 ( V_2 , V_24 ) ;
return F_35
( V_2 , V_4 , 0 , F_20 ( V_6 -> V_30 . V_31 . V_100 ) ,
V_4 -> V_30 . V_44 . V_101 , V_4 -> V_30 . V_44 . V_101 ) ;
}
static int F_36 ( const struct V_1 * V_2 ,
const struct V_23 * V_24 )
{
struct V_3 * V_4 = V_24 -> V_34 ;
T_4 V_85 ;
T_4 V_87 ;
if ( V_4 -> V_30 . V_102 . V_103 ) {
V_85 = 0 ;
V_87 = V_104 ;
} else {
V_85 = V_4 -> V_30 . V_102 . V_105 . V_98 ;
V_87 = V_85 + V_4 -> V_30 . V_102 . V_105 . V_99 - 1 ;
}
return F_30 ( V_2 , V_4 , V_53 , V_85 , V_87 ) ;
}
static int F_37 ( const struct V_1 * V_2 ,
const struct V_23 * V_24 )
{
return 0 ;
}
static int F_38 ( const struct V_1 * V_2 ,
const struct V_23 * V_24 )
{
struct V_15 * V_16 = F_6 ( V_2 ) ;
struct V_3 * V_4 = V_24 -> V_34 ;
T_5 V_106 ;
T_1 V_107 = 0 ;
if ( F_39 ( V_4 ) ) {
V_106 = V_4 -> V_30 . V_108 . V_109 . V_110 ;
if ( V_106 == 0 )
V_107 = V_111 ;
} else {
if ( ( V_4 -> V_30 . V_108 . V_109 . V_112 >=
V_4 -> V_30 . V_108 . V_109 . V_113 ) ||
( V_4 -> V_30 . V_108 . V_109 . V_114 >=
V_4 -> V_30 . V_108 . V_109 . V_113 ) )
return 0 ;
V_106 = 0 ;
}
V_16 -> V_30 . V_115 . V_116 = V_117 ;
return F_32 ( V_2 , V_4 , V_107 , V_53 ,
V_106 , V_104 ) ;
}
static int F_40 ( struct V_12 * V_12 , T_6 V_118 )
{
int V_67 ;
F_41 ( V_12 ) ;
V_67 = F_42 ( V_12 , V_118 ) ;
if ( V_67 < 0 ) {
F_43 ( V_12 ) ;
return V_67 ;
}
F_44 ( V_12 , V_118 ) ;
F_43 ( V_12 ) ;
return V_67 ;
}
static int F_45 ( const struct V_1 * V_2 ,
const struct V_23 * V_24 ,
struct V_12 * V_12 , T_4 V_118 )
{
F_46 ( V_12 ) ;
return 0 ;
}
static int F_47 ( const struct V_1 * V_2 ,
const struct V_23 * V_24 )
{
struct V_3 * V_4 = V_24 -> V_34 ;
struct V_35 * V_36 = V_4 -> V_37 ;
struct V_119 * V_120 = F_48 ( V_2 ) ;
int V_67 ;
unsigned V_121 = V_122 ;
F_49 ( V_36 ) ;
V_120 -> V_123 = V_4 -> V_30 . V_108 . V_109 . V_113 ;
if ( V_4 -> V_30 . V_108 . V_124 & V_125 ) {
V_120 -> V_126 = V_4 -> V_30 . V_108 . V_109 . V_114 ;
V_121 |= V_127 ;
}
if ( V_4 -> V_30 . V_108 . V_124 & V_128 ) {
V_120 -> V_129 = V_4 -> V_30 . V_108 . V_109 . V_112 ;
V_121 |= V_130 ;
}
V_67 = F_50 ( V_2 , V_36 , V_120 , V_121 ) ;
F_51 ( V_36 ) ;
return V_67 ;
}
static int F_52 ( const struct V_1 * V_2 ,
const struct V_23 * V_24 )
{
struct V_3 * V_4 = V_24 -> V_34 ;
struct V_12 * V_12 = F_9 ( V_4 -> V_37 ) ;
int V_67 = 0 ;
F_53 ( & V_12 -> V_131 ) ;
if ( F_39 ( V_4 ) )
V_67 = F_45 ( V_2 , V_24 , V_12 ,
V_4 -> V_30 . V_108 . V_109 . V_110 ) ;
if ( V_67 == 0 )
V_67 = F_47 ( V_2 , V_24 ) ;
return V_67 ;
}
static void F_54 ( const struct V_1 * V_2 ,
const struct V_23 * V_24 )
{
struct V_3 * V_4 = V_24 -> V_34 ;
struct V_12 * V_12 = F_9 ( V_4 -> V_37 ) ;
if ( F_39 ( V_4 ) ) {
F_40 ( V_12 , V_4 -> V_30 . V_108 . V_109 . V_110 ) ;
F_55 ( V_12 ) ;
}
F_56 ( & V_12 -> V_131 ) ;
}
static void F_57 ( const struct V_1 * V_2 ,
const struct V_23 * V_24 )
{
F_12 ( V_2 , V_24 ) ;
}
static T_3 F_58 ( struct V_132 * V_132 ,
struct V_15 * V_6 , T_4 * V_133 )
{
return F_59 ( V_6 -> V_134 , V_6 -> V_68 ,
V_6 -> V_69 , * V_133 ) ;
}
static T_3 F_60 ( struct V_132 * V_132 ,
struct V_15 * V_6 , T_4 * V_133 )
{
return F_61 ( V_6 -> V_134 , V_6 -> V_68 ,
V_6 -> V_69 , * V_133 ) ;
}
static int F_62 ( const struct V_1 * V_2 ,
const struct V_23 * V_24 )
{
struct V_5 * V_6 = F_8 ( V_2 , V_24 ) ;
struct V_15 * V_16 = F_10 ( V_2 , V_24 ) ;
struct V_3 * V_4 = V_24 -> V_34 ;
struct V_35 * V_36 = V_4 -> V_37 ;
struct V_12 * V_12 = F_9 ( V_36 ) ;
struct V_135 * V_136 = & V_6 -> V_137 ;
struct V_132 * V_132 = V_16 -> V_26 -> V_27 ;
int V_67 ;
T_4 V_138 = V_4 -> V_30 . V_96 . V_97 . V_98 ;
long V_139 = V_4 -> V_30 . V_96 . V_97 . V_99 ;
long V_140 = V_16 -> V_141 ;
int V_142 = 0 ;
F_13 ( V_2 , V_36 , F_14 ( V_36 ) ) ;
F_15 ( V_38 , L_5 , V_138 , V_138 + V_139 ) ;
if ( ! F_4 ( V_2 , V_4 , V_12 ) )
return 0 ;
V_67 = F_63 ( V_2 , V_36 , V_4 , V_138 , V_140 , & V_142 ) ;
if ( V_67 != 0 )
return V_67 ;
else if ( V_142 != 0 )
goto V_143;
F_64 ( V_144 , V_2 , & V_36 -> V_145 ,
L_6 ,
V_12 -> V_146 , V_139 , V_138 , F_65 ( V_12 ) ) ;
V_16 -> V_26 -> V_27 -> V_147 . V_148 = 0 ;
if ( ! V_6 -> V_149 ) {
V_6 -> V_149 = 1 ;
V_136 -> V_150 = F_27 ( V_36 , V_138 ) ;
V_136 -> V_151 = F_27 ( V_36 , V_140 + V_152 - 1 ) ;
F_66 ( V_132 , V_136 ) ;
}
F_67 ( V_132 ) ;
switch ( V_6 -> V_10 ) {
case V_11 :
V_67 = F_58 ( V_132 , V_16 , & V_138 ) ;
break;
case V_153 :
V_67 = F_68 ( V_132 , & V_138 ,
V_6 -> V_30 . V_154 . V_155 , V_139 ,
V_6 -> V_30 . V_154 . V_156 ) ;
V_4 -> V_21 = 0 ;
break;
default:
F_69 ( L_7 , V_6 -> V_10 ) ;
F_70 () ;
}
V_143:
if ( V_67 >= 0 ) {
if ( V_67 < V_139 )
V_4 -> V_21 = 0 ;
V_4 -> V_157 += V_67 ;
F_71 ( F_72 ( V_12 ) , V_59 -> V_158 ,
V_16 -> V_26 , V_138 , V_67 , V_159 ) ;
V_67 = 0 ;
}
return V_67 ;
}
static void F_73 ( const struct V_1 * V_2 , const struct V_23 * V_24 )
{
struct V_5 * V_6 = F_8 ( V_2 , V_24 ) ;
struct V_15 * V_16 = F_10 ( V_2 , V_24 ) ;
if ( V_6 -> V_149 )
F_74 ( V_16 -> V_26 -> V_27 , & V_6 -> V_137 ) ;
F_12 ( V_2 , V_24 ) ;
}
static int F_75 ( const struct V_1 * V_2 ,
const struct V_23 * V_24 )
{
struct V_15 * V_16 = F_10 ( V_2 , V_24 ) ;
struct V_3 * V_4 = V_24 -> V_34 ;
struct V_35 * V_36 = V_4 -> V_37 ;
struct V_12 * V_12 = F_9 ( V_36 ) ;
struct V_132 * V_132 = V_16 -> V_26 -> V_27 ;
T_3 V_67 = 0 ;
T_4 V_138 = V_4 -> V_30 . V_102 . V_105 . V_98 ;
T_6 V_139 = V_4 -> V_30 . V_102 . V_105 . V_99 ;
if ( ! F_4 ( V_2 , V_4 , V_12 ) )
return 0 ;
if ( F_76 ( V_4 ) ) {
V_138 = V_4 -> V_30 . V_102 . V_105 . V_98 = F_65 ( V_12 ) ;
V_16 -> V_134 -> V_160 = V_138 ;
}
F_15 ( V_38 , L_8 , V_138 , V_138 + ( long long ) V_139 ) ;
if ( V_16 -> V_68 == NULL )
V_67 = 0 ;
else
V_67 = F_60 ( V_132 , V_16 , & V_138 ) ;
if ( V_67 > 0 ) {
if ( V_67 < V_139 )
V_4 -> V_21 = 0 ;
V_4 -> V_157 += V_67 ;
F_71 ( F_72 ( V_12 ) , V_59 -> V_158 ,
V_16 -> V_26 , V_138 , V_67 , V_161 ) ;
V_67 = 0 ;
}
return V_67 ;
}
static int F_77 ( struct V_162 * V_163 )
{
struct V_164 * V_165 = V_163 -> V_31 . V_166 ;
V_163 -> V_31 . V_167 = F_78 ( V_163 -> V_100 , V_165 ) ;
if ( V_165 -> V_43 ) {
F_79 ( V_168 , V_165 -> V_43 , L_9 ,
V_165 -> V_169 ) ;
if ( F_80 ( ! ( V_163 -> V_31 . V_167 & V_170 ) ) ) {
F_81 ( V_165 -> V_43 ) ;
V_163 -> V_31 . V_167 &= V_170 ;
}
V_163 -> V_171 = V_165 -> V_43 ;
return 0 ;
}
if ( V_163 -> V_31 . V_167 & V_172 ) {
F_15 ( V_168 , L_10 , V_165 -> V_169 ) ;
return - V_173 ;
}
if ( V_163 -> V_31 . V_167 & V_174 ) {
F_15 ( V_168 , L_11 , V_165 -> V_169 ) ;
return - V_175 ;
}
if ( V_163 -> V_31 . V_167 & V_176 )
return - V_177 ;
F_69 ( L_12 , V_163 -> V_31 . V_167 ) ;
return - V_178 ;
}
static int F_82 ( const struct V_1 * V_2 ,
const struct V_23 * V_24 )
{
struct V_5 * V_6 = F_8 ( V_2 , V_24 ) ;
struct V_3 * V_4 = V_24 -> V_34 ;
struct V_35 * V_36 = V_4 -> V_37 ;
struct V_12 * V_12 = F_9 ( V_36 ) ;
struct V_179 * V_180 = & V_4 -> V_30 . V_44 ;
struct V_162 * V_163 = & V_6 -> V_30 . V_31 ;
T_4 V_181 ;
int V_67 = 0 ;
struct V_43 * V_182 = NULL ;
struct V_42 * V_43 ;
T_4 V_118 ;
T_7 V_183 ;
if ( V_180 -> V_184 &&
F_11 ( V_12 -> V_33 ) != V_6 -> V_30 . V_31 . V_32 )
F_83 ( L_13 V_185
L_14 ,
F_84 ( F_85 ( & V_36 -> V_145 ) ) ) ;
V_181 = F_86 ( V_36 , V_180 -> V_101 + 1 ) - 1 ;
F_3 ( F_27 ( V_36 , V_181 ) == V_180 -> V_101 ) ;
V_67 = F_63 ( V_2 , V_36 , V_4 , 0 , V_181 + 1 , NULL ) ;
if ( V_67 != 0 )
return V_67 ;
if ( V_180 -> V_186 ) {
F_3 ( V_163 -> V_171 != NULL ) ;
F_81 ( V_163 -> V_171 ) ;
} else {
V_67 = F_77 ( V_163 ) ;
if ( V_67 != 0 )
return V_67 ;
}
V_182 = V_163 -> V_171 ;
F_3 ( F_87 ( V_182 ) ) ;
if ( F_88 ( V_187 ) )
F_89 ( V_182 ) ;
V_118 = F_65 ( V_12 ) ;
if ( F_80 ( ( V_182 -> V_188 != V_12 -> V_189 ) ||
( F_90 ( V_182 ) > V_118 ) ) ) {
F_15 ( V_168 , L_15 ) ;
GOTO ( V_143 , V_67 = + 1 ) ;
}
if ( V_180 -> V_186 ) {
T_7 V_190 ;
V_190 = F_27 ( V_36 , V_118 - 1 ) ;
if ( V_190 < V_180 -> V_101 ) {
F_15 ( V_168 ,
L_16
L_17 ,
V_182 -> V_188 , V_180 -> V_101 , V_190 ) ;
GOTO ( V_143 , V_67 = - V_191 ) ;
}
}
V_43 = F_91 ( V_2 , V_36 , V_180 -> V_101 , V_182 , V_192 ) ;
if ( F_92 ( V_43 ) )
GOTO ( V_143 , V_67 = F_93 ( V_43 ) ) ;
if ( V_180 -> V_186 ) {
F_94 ( V_182 ) ;
if ( F_95 ( V_182 ) ) {
struct V_193 * V_194 ;
F_96 ( V_2 , V_4 , V_43 ) ;
V_194 = F_97 ( F_98 ( V_43 , & V_195 ) ) ;
F_99 ( F_100 ( V_36 ) , V_194 ) ;
V_67 = F_101 ( V_2 , V_4 , V_43 , V_196 ) ;
F_3 ( F_102 ( V_43 , V_4 ) ) ;
V_182 = NULL ;
if ( V_67 < 0 ) {
F_103 ( V_2 , V_4 , V_43 ) ;
F_104 ( V_2 , V_4 , V_43 ) ;
F_105 ( V_2 , V_4 , V_43 ) ;
F_19 ( V_2 , V_43 ) ;
if ( V_67 == - V_197 )
V_67 = - V_198 ;
GOTO ( V_143 , V_67 ) ;
} else
F_105 ( V_2 , V_4 , V_43 ) ;
}
}
V_183 = F_27 ( V_36 , V_118 - 1 ) ;
F_3 ( ! V_180 -> V_186 || V_180 -> V_101 <= V_183 ) ;
if ( V_180 -> V_101 == V_183 )
V_180 -> V_199 = V_118 - F_86 ( V_36 , V_180 -> V_101 ) ;
else
V_180 -> V_199 = F_106 ( V_36 ) ;
F_107 ( & V_43 -> V_46 , L_3 , V_4 ) ;
V_180 -> V_45 = V_43 ;
V_143:
if ( V_182 != NULL )
F_108 ( V_182 ) ;
V_163 -> V_31 . V_167 &= ~ V_170 ;
return V_67 ;
}
static int F_109 ( const struct V_1 * V_2 ,
const struct V_23 * V_24 )
{
return 0 ;
}
static int F_110 ( const struct V_1 * V_2 ,
const struct V_23 * V_24 ,
const struct V_200 * V_201 )
{
struct V_3 * V_4 = V_24 -> V_34 ;
struct V_35 * V_36 = V_201 -> V_202 ;
struct V_193 * V_194 = F_97 ( V_201 ) ;
struct V_42 * V_43 = V_201 -> V_203 ;
struct V_12 * V_12 = F_9 ( V_36 ) ;
struct V_204 * V_205 = F_72 ( V_12 ) ;
struct V_206 * V_207 = F_10 ( V_2 , V_24 ) -> V_26 ;
struct V_208 * V_209 = & V_207 -> V_210 ;
struct V_43 * V_182 = V_194 -> V_211 ;
struct V_212 * V_213 = & V_4 -> V_214 ;
int V_17 ;
F_13 ( V_2 , V_36 , F_14 ( V_36 ) ) ;
F_3 ( V_201 -> V_202 == V_36 ) ;
if ( V_205 -> V_215 . V_216 &&
V_205 -> V_215 . V_217 )
F_111 ( V_205 , V_12 , V_209 , V_43 -> V_218 ,
V_194 -> V_219 ) ;
V_17 = F_112 ( V_2 , V_4 , V_43 ) ;
if ( V_17 != - V_220 ) {
F_113 ( V_221 , V_2 , V_43 , L_18 ,
V_17 == - V_191 ? L_19 :
L_20 , V_17 ) ;
if ( V_17 != - V_191 )
return V_17 ;
}
if ( V_194 -> V_219 ) {
V_194 -> V_222 = 1 ;
F_114 ( V_2 , V_43 , 1 ) ;
}
F_115 ( V_213 , V_43 ) ;
if ( V_205 -> V_215 . V_216 &&
V_205 -> V_215 . V_217 )
F_116 ( V_2 , V_4 , V_209 ,
V_182 -> V_188 , & V_213 -> V_223 , V_207 -> V_224 ) ;
return 0 ;
}
static int F_117 ( const struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_42 * V_43 , struct V_193 * V_194 ,
enum V_225 V_226 )
{
struct V_212 * V_213 ;
int V_67 ;
F_3 ( V_4 -> V_7 == V_8 || V_4 -> V_7 == V_9 ) ;
V_213 = & V_4 -> V_214 ;
F_118 ( V_213 , V_43 ) ;
V_67 = F_119 ( V_2 , V_4 , V_226 , V_213 , 0 ) ;
F_3 ( F_102 ( V_43 , V_4 ) ) ;
if ( V_226 == V_227 )
F_120 ( V_2 , V_4 , & V_213 -> V_223 ) ;
F_121 ( V_2 , V_213 ) ;
return V_67 ;
}
static int F_122 ( const struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_35 * V_36 , struct V_42 * V_228 ,
struct V_193 * V_194 ,
unsigned V_229 , unsigned V_230 )
{
struct V_119 * V_120 = F_48 ( V_2 ) ;
T_4 V_181 = F_86 ( V_36 , V_228 -> V_218 ) ;
int V_67 ;
F_49 ( V_36 ) ;
V_67 = F_123 ( V_2 , V_36 , V_120 ) ;
F_51 ( V_36 ) ;
if ( V_67 == 0 ) {
if ( V_120 -> V_231 <= V_181 ) {
char * V_232 = F_124 ( V_194 -> V_211 ) ;
memset ( V_232 , 0 , F_106 ( V_36 ) ) ;
F_125 ( V_232 ) ;
} else if ( V_194 -> V_219 )
V_194 -> V_222 = 1 ;
else
V_67 = F_117 ( V_2 , V_4 , V_228 , V_194 , V_227 ) ;
if ( V_67 == 0 )
F_114 ( V_2 , V_228 , 1 ) ;
}
return V_67 ;
}
static int F_126 ( const struct V_1 * V_2 ,
const struct V_23 * V_24 ,
const struct V_200 * V_201 ,
unsigned V_229 , unsigned V_230 )
{
struct V_35 * V_36 = V_201 -> V_202 ;
struct V_193 * V_194 = F_97 ( V_201 ) ;
struct V_42 * V_228 = V_201 -> V_203 ;
struct V_43 * V_182 = V_194 -> V_211 ;
int V_67 ;
F_127 ( F_128 ( V_2 , V_228 ) ) ;
F_3 ( V_182 -> V_188 -> V_233 == F_9 ( V_36 ) ) ;
V_67 = 0 ;
F_113 ( V_168 , V_2 , V_228 , L_21 , V_229 , V_230 ) ;
if ( ! F_129 ( V_182 ) ) {
if ( V_229 == 0 && V_230 == V_152 ) {
F_113 ( V_168 , V_2 , V_228 , L_22 ) ;
F_130 ( V_43 , 0x11 ) ;
} else
V_67 = F_122 ( V_2 , V_24 -> V_34 , V_36 ,
V_228 , V_194 , V_229 , V_230 ) ;
} else
F_113 ( V_168 , V_2 , V_228 , L_23 ) ;
return V_67 ;
}
static int F_131 ( const struct V_1 * V_2 ,
const struct V_23 * V_24 ,
const struct V_200 * V_201 ,
unsigned V_229 , unsigned V_230 )
{
struct V_35 * V_36 = V_201 -> V_202 ;
struct V_3 * V_4 = V_24 -> V_34 ;
struct V_193 * V_194 = F_97 ( V_201 ) ;
struct V_42 * V_228 = V_201 -> V_203 ;
struct V_12 * V_12 = F_9 ( V_36 ) ;
struct V_204 * V_205 = F_72 ( V_12 ) ;
struct V_13 * V_14 = F_5 ( V_12 ) ;
struct V_43 * V_182 = V_194 -> V_211 ;
int V_67 ;
int V_234 ;
T_4 V_118 ;
F_127 ( F_128 ( V_2 , V_228 ) ) ;
F_3 ( V_182 -> V_188 -> V_233 == V_12 ) ;
F_64 ( V_144 , V_2 , & V_36 -> V_145 , L_24 ) ;
F_113 ( V_168 , V_2 , V_228 , L_25 , V_229 , V_230 ) ;
if ( ! F_132 ( V_182 ) ) {
V_234 = V_235 ;
V_67 = F_101 ( V_2 , V_4 , V_228 , V_196 ) ;
if ( V_67 == 0 ) {
F_95 ( V_182 ) ;
F_99 ( F_100 ( V_36 ) , V_194 ) ;
} else if ( V_67 == - V_197 ) {
T_7 V_190 = F_65 ( V_12 ) >> V_236 ;
bool V_237 = true ;
if ( V_190 > V_228 -> V_218 ) {
V_230 = V_152 ;
V_237 = false ;
} else if ( V_190 == V_228 -> V_218 ) {
int V_238 = F_65 ( V_12 ) & ~ V_74 ;
if ( V_230 < V_238 )
V_230 = V_238 ;
}
if ( V_237 )
F_133 ( V_2 , V_228 , 0 , V_230 ) ;
V_67 = F_117 ( V_2 , V_4 , V_228 , V_194 , V_196 ) ;
if ( V_67 )
F_69 ( L_26 ,
V_228 -> V_218 , V_12 , V_67 ) ;
}
} else {
V_234 = V_239 ;
V_67 = 0 ;
}
F_134 ( V_205 , V_234 , 1 ) ;
if ( V_67 == 0 ) {
F_135 ( & V_14 -> V_240 ) ;
V_14 -> V_241 |= V_242 ;
F_136 ( & V_14 -> V_240 ) ;
}
V_118 = F_86 ( V_36 , V_228 -> V_218 ) + V_230 ;
F_41 ( V_12 ) ;
if ( V_67 == 0 ) {
if ( V_118 > F_65 ( V_12 ) ) {
F_137 ( V_12 , V_118 ) ;
F_15 ( V_38 , V_185 L_27 ,
F_84 ( F_85 ( & V_36 -> V_145 ) ) ,
( unsigned long ) V_118 ) ;
}
F_114 ( V_2 , V_228 , 1 ) ;
} else {
if ( V_118 > F_65 ( V_12 ) )
F_104 ( V_2 , V_4 , V_228 ) ;
}
F_43 ( V_12 ) ;
return V_67 ;
}
int F_138 ( const struct V_1 * V_2 , struct V_35 * V_36 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_15 * V_16 = F_6 ( V_2 ) ;
struct V_12 * V_12 = F_9 ( V_36 ) ;
int V_67 ;
F_13 ( V_2 , V_36 , F_14 ( V_36 ) ) ;
F_139 ( V_16 , V_243 ) ;
F_140 ( V_4 , & V_16 -> V_243 , V_36 , & V_244 ) ;
V_6 -> V_149 = 0 ;
V_67 = 0 ;
if ( V_4 -> V_7 == V_8 || V_4 -> V_7 == V_9 ) {
T_6 V_66 ;
struct V_13 * V_14 = F_5 ( V_12 ) ;
V_66 = V_4 -> V_30 . V_92 . V_99 ;
if ( V_66 == 0 )
V_67 = 1 ;
else {
V_16 -> V_141 = V_66 ;
V_16 -> V_245 = 0 ;
}
F_141 ( V_14 -> V_246 ) ;
} else if ( V_4 -> V_7 == V_247 ) {
if ( ! F_39 ( V_4 ) )
V_4 -> V_248 = V_249 ;
}
if ( V_4 -> V_7 == V_250 && ! V_4 -> V_40 )
V_4 -> V_39 = 1 ;
if ( V_67 == 0 && ! V_4 -> V_39 ) {
V_67 = F_16 ( V_12 , & V_16 -> V_19 ) ;
if ( V_67 == - V_251 )
V_67 = 0 ;
if ( V_67 < 0 )
F_69 ( L_28 V_185 L_29 ,
F_142 ( V_12 -> V_252 , NULL , 0 ) ,
F_84 ( F_85 ( & V_36 -> V_145 ) ) , V_67 ) ;
}
return V_67 ;
}
static struct V_5 * F_8 ( const struct V_1 * V_2 ,
const struct V_23 * V_201 )
{
F_10 ( V_2 , V_201 ) ;
return F_2 ( V_2 ) ;
}
