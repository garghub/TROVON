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
V_68 ;
F_3 ( V_4 -> V_7 == V_8 || V_4 -> V_7 == V_9 ) ;
if ( ! F_1 ( V_2 , V_4 ) )
RETURN ( 0 ) ;
if ( V_6 -> V_69 == NULL )
RETURN ( 0 ) ;
if ( V_58 == NULL )
RETURN ( 0 ) ;
for ( V_65 = 0 ; V_65 < V_6 -> V_70 ; V_65 ++ ) {
const struct V_71 * V_72 = & V_6 -> V_69 [ V_65 ] ;
V_64 = ( unsigned long ) V_72 -> V_73 ;
V_66 = V_72 -> V_74 ;
if ( V_66 == 0 )
continue;
V_66 += V_64 & ( ~ V_75 ) ;
V_64 &= V_75 ;
F_23 ( & V_58 -> V_76 ) ;
while( ( V_49 = F_24 ( V_58 , V_64 , V_66 ) ) != NULL ) {
struct V_12 * V_12 = V_49 -> V_77 -> V_28 -> V_29 ;
int V_78 = V_79 ;
if ( F_25 ( V_49 -> V_77 ) ) {
V_78 = V_80 ;
}
F_26 ( & V_63 , V_49 , V_64 , V_66 ) ;
V_61 -> V_81 = F_20 ( V_49 ) ;
V_61 -> V_82 = F_5 ( V_12 ) -> V_83 ;
V_61 -> V_84 = F_27 ( V_61 -> V_82 ,
V_63 . V_85 . V_86 ) ;
V_61 -> V_87 = F_27 ( V_61 -> V_82 ,
V_63 . V_85 . V_88 ) ;
V_61 -> V_89 = V_78 ;
V_67 = F_28 ( V_2 , V_4 , V_61 ) ;
F_15 ( V_38 , L_4 ,
V_61 -> V_81 , V_61 -> V_84 ,
V_61 -> V_87 ) ;
if ( V_67 < 0 )
RETURN ( V_67 ) ;
if ( V_49 -> V_90 - V_64 >= V_66 )
break;
V_66 -= V_49 -> V_90 - V_64 ;
V_64 = V_49 -> V_90 ;
}
F_29 ( & V_58 -> V_76 ) ;
}
RETURN ( 0 ) ;
}
static int F_30 ( const struct V_1 * V_2 , struct V_3 * V_4 ,
enum V_47 V_91 , T_4 V_86 , T_4 V_88 )
{
struct V_15 * V_16 = F_6 ( V_2 ) ;
int V_67 ;
int V_92 = 0 ;
F_3 ( V_4 -> V_7 == V_8 || V_4 -> V_7 == V_9 ) ;
V_68 ;
F_31 ( V_2 , V_16 , V_4 ) ;
if ( V_4 -> V_30 . V_93 . V_94 )
V_92 |= V_95 ;
V_67 = F_21 ( V_2 , V_16 , V_4 ) ;
if ( V_67 == 0 )
V_67 = F_32 ( V_2 , V_4 , V_92 , V_91 , V_86 , V_88 ) ;
RETURN ( V_67 ) ;
}
static int F_33 ( const struct V_1 * V_2 ,
const struct V_23 * V_24 )
{
struct V_3 * V_4 = V_24 -> V_34 ;
struct V_13 * V_14 = F_5 ( F_9 ( V_4 -> V_37 ) ) ;
int V_67 ;
V_68 ;
if ( V_14 -> V_96 )
V_67 = F_30 ( V_2 , V_4 , V_54 ,
V_4 -> V_30 . V_97 . V_98 . V_99 ,
V_4 -> V_30 . V_97 . V_98 . V_99 +
V_4 -> V_30 . V_97 . V_98 . V_100 - 1 ) ;
else
V_67 = 0 ;
RETURN ( V_67 ) ;
}
static int F_34 ( const struct V_1 * V_2 ,
const struct V_23 * V_24 )
{
struct V_3 * V_4 = V_24 -> V_34 ;
struct V_5 * V_6 = F_8 ( V_2 , V_24 ) ;
return F_35
( V_2 , V_4 , 0 , F_20 ( V_6 -> V_30 . V_31 . V_101 ) ,
V_4 -> V_30 . V_44 . V_102 , V_4 -> V_30 . V_44 . V_102 ) ;
}
static int F_36 ( const struct V_1 * V_2 ,
const struct V_23 * V_24 )
{
struct V_3 * V_4 = V_24 -> V_34 ;
T_4 V_86 ;
T_4 V_88 ;
if ( V_4 -> V_30 . V_103 . V_104 ) {
V_86 = 0 ;
V_88 = V_105 ;
} else {
V_86 = V_4 -> V_30 . V_103 . V_106 . V_99 ;
V_88 = V_86 + V_4 -> V_30 . V_103 . V_106 . V_100 - 1 ;
}
return F_30 ( V_2 , V_4 , V_53 , V_86 , V_88 ) ;
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
T_5 V_107 ;
T_1 V_108 = 0 ;
if ( F_39 ( V_4 ) ) {
V_107 = V_4 -> V_30 . V_109 . V_110 . V_111 ;
if ( V_107 == 0 )
V_108 = V_112 ;
} else {
if ( ( V_4 -> V_30 . V_109 . V_110 . V_113 >=
V_4 -> V_30 . V_109 . V_110 . V_114 ) ||
( V_4 -> V_30 . V_109 . V_110 . V_115 >=
V_4 -> V_30 . V_109 . V_110 . V_114 ) )
return 0 ;
V_107 = 0 ;
}
V_16 -> V_30 . V_116 . V_117 = V_118 ;
return F_32 ( V_2 , V_4 , V_108 , V_53 ,
V_107 , V_105 ) ;
}
static int F_40 ( struct V_12 * V_12 , T_6 V_119 )
{
int V_67 ;
F_41 ( V_12 ) ;
V_67 = F_42 ( V_12 , V_119 ) ;
if ( V_67 < 0 ) {
F_43 ( V_12 ) ;
return V_67 ;
}
F_44 ( V_12 , V_119 ) ;
F_43 ( V_12 ) ;
return V_67 ;
}
static int F_45 ( const struct V_1 * V_2 ,
const struct V_23 * V_24 ,
struct V_12 * V_12 , T_4 V_119 )
{
F_46 ( V_12 ) ;
return 0 ;
}
static int F_47 ( const struct V_1 * V_2 ,
const struct V_23 * V_24 )
{
struct V_3 * V_4 = V_24 -> V_34 ;
struct V_35 * V_36 = V_4 -> V_37 ;
struct V_120 * V_121 = F_48 ( V_2 ) ;
int V_67 ;
unsigned V_122 = V_123 ;
F_49 ( V_36 ) ;
V_121 -> V_124 = V_4 -> V_30 . V_109 . V_110 . V_114 ;
if ( V_4 -> V_30 . V_109 . V_125 & V_126 ) {
V_121 -> V_127 = V_4 -> V_30 . V_109 . V_110 . V_115 ;
V_122 |= V_128 ;
}
if ( V_4 -> V_30 . V_109 . V_125 & V_129 ) {
V_121 -> V_130 = V_4 -> V_30 . V_109 . V_110 . V_113 ;
V_122 |= V_131 ;
}
V_67 = F_50 ( V_2 , V_36 , V_121 , V_122 ) ;
F_51 ( V_36 ) ;
return V_67 ;
}
static int F_52 ( const struct V_1 * V_2 ,
const struct V_23 * V_24 )
{
struct V_3 * V_4 = V_24 -> V_34 ;
struct V_12 * V_12 = F_9 ( V_4 -> V_37 ) ;
F_53 ( & V_12 -> V_132 ) ;
if ( F_39 ( V_4 ) )
return F_45 ( V_2 , V_24 , V_12 ,
V_4 -> V_30 . V_109 . V_110 . V_111 ) ;
else
return F_47 ( V_2 , V_24 ) ;
}
static void F_54 ( const struct V_1 * V_2 ,
const struct V_23 * V_24 )
{
struct V_3 * V_4 = V_24 -> V_34 ;
struct V_12 * V_12 = F_9 ( V_4 -> V_37 ) ;
if ( F_39 ( V_4 ) ) {
F_40 ( V_12 , V_4 -> V_30 . V_109 . V_110 . V_111 ) ;
F_55 ( V_12 ) ;
}
F_56 ( & V_12 -> V_132 ) ;
}
static void F_57 ( const struct V_1 * V_2 ,
const struct V_23 * V_24 )
{
F_12 ( V_2 , V_24 ) ;
}
static T_3 F_58 ( struct V_133 * V_133 ,
struct V_15 * V_6 , T_4 * V_134 )
{
return F_59 ( V_6 -> V_135 , V_6 -> V_69 ,
V_6 -> V_70 , * V_134 ) ;
}
static T_3 F_60 ( struct V_133 * V_133 ,
struct V_15 * V_6 , T_4 * V_134 )
{
return F_61 ( V_6 -> V_135 , V_6 -> V_69 ,
V_6 -> V_70 , * V_134 ) ;
}
static int F_62 ( const struct V_1 * V_2 ,
const struct V_23 * V_24 )
{
struct V_5 * V_6 = F_8 ( V_2 , V_24 ) ;
struct V_15 * V_16 = F_10 ( V_2 , V_24 ) ;
struct V_3 * V_4 = V_24 -> V_34 ;
struct V_35 * V_36 = V_4 -> V_37 ;
struct V_12 * V_12 = F_9 ( V_36 ) ;
struct V_136 * V_137 = & V_6 -> V_138 ;
struct V_133 * V_133 = V_16 -> V_26 -> V_27 ;
int V_67 ;
T_4 V_139 = V_4 -> V_30 . V_97 . V_98 . V_99 ;
long V_140 = V_4 -> V_30 . V_97 . V_98 . V_100 ;
long V_141 = V_16 -> V_142 ;
int V_143 = 0 ;
F_13 ( V_2 , V_36 , F_14 ( V_36 ) ) ;
F_15 ( V_38 , L_5 , V_139 , V_139 + V_140 ) ;
if ( ! F_4 ( V_2 , V_4 , V_12 ) )
return 0 ;
V_67 = F_63 ( V_2 , V_36 , V_4 , V_139 , V_141 , & V_143 ) ;
if ( V_67 != 0 )
return V_67 ;
else if ( V_143 != 0 )
goto V_144;
F_64 ( V_145 , V_2 , & V_36 -> V_146 ,
L_6 ,
V_12 -> V_147 , V_140 , V_139 , F_65 ( V_12 ) ) ;
V_16 -> V_26 -> V_27 -> V_148 . V_149 = 0 ;
if ( ! V_6 -> V_150 ) {
V_6 -> V_150 = 1 ;
V_137 -> V_151 = F_27 ( V_36 , V_139 ) ;
V_137 -> V_152 = F_27 ( V_36 , V_141 + V_153 - 1 ) ;
F_66 ( V_133 , V_137 ) ;
}
F_67 ( V_133 ) ;
switch ( V_6 -> V_10 ) {
case V_11 :
V_67 = F_58 ( V_133 , V_16 , & V_139 ) ;
break;
case V_154 :
V_67 = F_68 ( V_133 , & V_139 ,
V_6 -> V_30 . V_155 . V_156 , V_140 ,
V_6 -> V_30 . V_155 . V_157 ) ;
V_4 -> V_21 = 0 ;
break;
default:
F_69 ( L_7 , V_6 -> V_10 ) ;
F_70 () ;
}
V_144:
if ( V_67 >= 0 ) {
if ( V_67 < V_140 )
V_4 -> V_21 = 0 ;
V_4 -> V_158 += V_67 ;
F_71 ( F_72 ( V_12 ) , V_59 -> V_159 ,
V_16 -> V_26 , V_139 , V_67 , 0 ) ;
V_67 = 0 ;
}
return V_67 ;
}
static void F_73 ( const struct V_1 * V_2 , const struct V_23 * V_24 )
{
struct V_5 * V_6 = F_8 ( V_2 , V_24 ) ;
struct V_15 * V_16 = F_10 ( V_2 , V_24 ) ;
if ( V_6 -> V_150 )
F_74 ( V_16 -> V_26 -> V_27 , & V_6 -> V_138 ) ;
F_12 ( V_2 , V_24 ) ;
}
static int F_75 ( const struct V_1 * V_2 ,
const struct V_23 * V_24 )
{
struct V_15 * V_16 = F_10 ( V_2 , V_24 ) ;
struct V_3 * V_4 = V_24 -> V_34 ;
struct V_35 * V_36 = V_4 -> V_37 ;
struct V_12 * V_12 = F_9 ( V_36 ) ;
struct V_133 * V_133 = V_16 -> V_26 -> V_27 ;
T_3 V_67 = 0 ;
T_4 V_139 = V_4 -> V_30 . V_103 . V_106 . V_99 ;
T_6 V_140 = V_4 -> V_30 . V_103 . V_106 . V_100 ;
V_68 ;
if ( ! F_4 ( V_2 , V_4 , V_12 ) )
return 0 ;
if ( F_76 ( V_4 ) ) {
V_139 = V_4 -> V_30 . V_103 . V_106 . V_99 = F_65 ( V_12 ) ;
V_16 -> V_135 -> V_160 = V_139 ;
}
F_15 ( V_38 , L_8 , V_139 , V_139 + ( long long ) V_140 ) ;
if ( V_16 -> V_69 == NULL )
V_67 = 0 ;
else
V_67 = F_60 ( V_133 , V_16 , & V_139 ) ;
if ( V_67 > 0 ) {
if ( V_67 < V_140 )
V_4 -> V_21 = 0 ;
V_4 -> V_158 += V_67 ;
F_71 ( F_72 ( V_12 ) , V_59 -> V_159 ,
V_16 -> V_26 , V_139 , V_67 , 0 ) ;
V_67 = 0 ;
}
RETURN ( V_67 ) ;
}
static int F_77 ( struct V_161 * V_162 )
{
struct V_163 * V_164 = V_162 -> V_31 . V_165 ;
V_162 -> V_31 . V_166 = F_78 ( V_162 -> V_101 , V_164 ) ;
if ( V_164 -> V_43 ) {
F_79 ( V_167 , V_164 -> V_43 , L_9 ,
V_164 -> V_168 ) ;
if ( F_80 ( ! ( V_162 -> V_31 . V_166 & V_169 ) ) ) {
F_81 ( V_164 -> V_43 ) ;
V_162 -> V_31 . V_166 &= V_169 ;
}
V_162 -> V_170 = V_164 -> V_43 ;
return 0 ;
}
if ( V_162 -> V_31 . V_166 & V_171 ) {
F_15 ( V_167 , L_10 , V_164 -> V_168 ) ;
return - V_172 ;
}
if ( V_162 -> V_31 . V_166 & V_173 ) {
F_15 ( V_167 , L_11 , V_164 -> V_168 ) ;
return - V_174 ;
}
if ( V_162 -> V_31 . V_166 & V_175 )
return - V_176 ;
F_69 ( L_12 , V_162 -> V_31 . V_166 ) ;
return - V_177 ;
}
static int F_82 ( const struct V_1 * V_2 ,
const struct V_23 * V_24 )
{
struct V_5 * V_6 = F_8 ( V_2 , V_24 ) ;
struct V_3 * V_4 = V_24 -> V_34 ;
struct V_35 * V_36 = V_4 -> V_37 ;
struct V_12 * V_12 = F_9 ( V_36 ) ;
struct V_178 * V_179 = & V_4 -> V_30 . V_44 ;
struct V_161 * V_162 = & V_6 -> V_30 . V_31 ;
T_4 V_180 ;
int V_67 = 0 ;
struct V_43 * V_181 = NULL ;
struct V_42 * V_43 ;
T_4 V_119 ;
T_7 V_182 ;
if ( V_179 -> V_183 &&
F_11 ( V_12 -> V_33 ) != V_6 -> V_30 . V_31 . V_32 )
F_83 ( L_13 V_184
L_14 ,
F_84 ( F_85 ( & V_36 -> V_146 ) ) ) ;
V_180 = F_86 ( V_36 , V_179 -> V_102 + 1 ) - 1 ;
F_3 ( F_27 ( V_36 , V_180 ) == V_179 -> V_102 ) ;
V_67 = F_63 ( V_2 , V_36 , V_4 , 0 , V_180 + 1 , NULL ) ;
if ( V_67 != 0 )
return V_67 ;
if ( V_179 -> V_185 ) {
F_3 ( V_162 -> V_170 != NULL ) ;
F_81 ( V_162 -> V_170 ) ;
} else {
V_67 = F_77 ( V_162 ) ;
if ( V_67 != 0 )
return V_67 ;
}
V_181 = V_162 -> V_170 ;
F_3 ( F_87 ( V_181 ) ) ;
if ( F_88 ( V_186 ) )
F_89 ( V_181 ) ;
V_119 = F_65 ( V_12 ) ;
if ( F_80 ( ( V_181 -> V_187 != V_12 -> V_188 ) ||
( F_90 ( V_181 ) > V_119 ) ) ) {
F_15 ( V_167 , L_15 ) ;
GOTO ( V_144 , V_67 = + 1 ) ;
}
if ( V_179 -> V_185 ) {
T_7 V_189 ;
V_189 = F_27 ( V_36 , V_119 - 1 ) ;
if ( V_189 < V_179 -> V_102 ) {
F_15 ( V_167 ,
L_16
L_17 ,
V_181 -> V_187 , V_179 -> V_102 , V_189 ) ;
GOTO ( V_144 , V_67 = - V_190 ) ;
}
}
V_43 = F_91 ( V_2 , V_36 , V_179 -> V_102 , V_181 , V_191 ) ;
if ( F_92 ( V_43 ) )
GOTO ( V_144 , V_67 = F_93 ( V_43 ) ) ;
if ( V_179 -> V_185 ) {
F_94 ( V_181 ) ;
if ( F_95 ( V_181 ) ) {
struct V_192 * V_193 ;
F_96 ( V_2 , V_4 , V_43 ) ;
V_193 = F_97 ( F_98 ( V_43 , & V_194 ) ) ;
F_99 ( F_100 ( V_36 ) , V_193 ) ;
V_67 = F_101 ( V_2 , V_4 , V_43 , V_195 ) ;
F_3 ( F_102 ( V_43 , V_4 ) ) ;
V_181 = NULL ;
if ( V_67 < 0 ) {
F_103 ( V_2 , V_4 , V_43 ) ;
F_104 ( V_2 , V_4 , V_43 ) ;
F_105 ( V_2 , V_4 , V_43 ) ;
F_19 ( V_2 , V_43 ) ;
if ( V_67 == - V_196 )
V_67 = - V_197 ;
GOTO ( V_144 , V_67 ) ;
} else
F_105 ( V_2 , V_4 , V_43 ) ;
}
}
V_182 = F_27 ( V_36 , V_119 - 1 ) ;
F_3 ( ! V_179 -> V_185 || V_179 -> V_102 <= V_182 ) ;
if ( V_179 -> V_102 == V_182 )
V_179 -> V_198 = V_119 - F_86 ( V_36 , V_179 -> V_102 ) ;
else
V_179 -> V_198 = F_106 ( V_36 ) ;
F_107 ( & V_43 -> V_46 , L_3 , V_4 ) ;
V_179 -> V_45 = V_43 ;
EXIT ;
V_144:
if ( V_181 != NULL )
F_108 ( V_181 ) ;
V_162 -> V_31 . V_166 &= ~ V_169 ;
return V_67 ;
}
static int F_109 ( const struct V_1 * V_2 ,
const struct V_23 * V_24 )
{
return 0 ;
}
static int F_110 ( const struct V_1 * V_2 ,
const struct V_23 * V_24 ,
const struct V_199 * V_200 )
{
struct V_3 * V_4 = V_24 -> V_34 ;
struct V_35 * V_36 = V_200 -> V_201 ;
struct V_192 * V_193 = F_97 ( V_200 ) ;
struct V_42 * V_43 = V_200 -> V_202 ;
struct V_12 * V_12 = F_9 ( V_36 ) ;
struct V_203 * V_204 = F_72 ( V_12 ) ;
struct V_205 * V_206 = F_10 ( V_2 , V_24 ) -> V_26 ;
struct V_207 * V_208 = & V_206 -> V_209 ;
struct V_43 * V_181 = V_193 -> V_210 ;
struct V_211 * V_212 = & V_4 -> V_213 ;
int V_17 ;
F_13 ( V_2 , V_36 , F_14 ( V_36 ) ) ;
F_3 ( V_200 -> V_201 == V_36 ) ;
V_68 ;
if ( V_204 -> V_214 . V_215 &&
V_204 -> V_214 . V_216 )
F_111 ( V_204 , V_12 , V_208 , V_43 -> V_217 ,
V_193 -> V_218 ) ;
V_17 = F_112 ( V_2 , V_4 , V_43 ) ;
if ( V_17 != - V_219 ) {
F_113 ( V_220 , V_2 , V_43 , L_18 ,
V_17 == - V_190 ? L_19 :
L_20 , V_17 ) ;
if ( V_17 != - V_190 )
RETURN ( V_17 ) ;
}
if ( V_193 -> V_218 ) {
V_193 -> V_221 = 1 ;
F_114 ( V_2 , V_43 , 1 ) ;
}
F_115 ( V_212 , V_43 ) ;
if ( V_204 -> V_214 . V_215 &&
V_204 -> V_214 . V_216 )
F_116 ( V_2 , V_4 , V_208 ,
V_181 -> V_187 , & V_212 -> V_222 , V_206 -> V_223 ) ;
RETURN ( 0 ) ;
}
static int F_117 ( const struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_42 * V_43 , struct V_192 * V_193 ,
enum V_224 V_225 )
{
struct V_211 * V_212 ;
int V_67 ;
F_3 ( V_4 -> V_7 == V_8 || V_4 -> V_7 == V_9 ) ;
V_212 = & V_4 -> V_213 ;
F_118 ( V_212 , V_43 ) ;
V_67 = F_119 ( V_2 , V_4 , V_225 , V_212 , 0 ) ;
F_3 ( F_102 ( V_43 , V_4 ) ) ;
if ( V_225 == V_226 )
F_120 ( V_2 , V_4 , & V_212 -> V_222 ) ;
F_121 ( V_2 , V_212 ) ;
return V_67 ;
}
static int F_122 ( const struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_35 * V_36 , struct V_42 * V_227 ,
struct V_192 * V_193 ,
unsigned V_228 , unsigned V_229 )
{
struct V_120 * V_121 = F_48 ( V_2 ) ;
T_4 V_180 = F_86 ( V_36 , V_227 -> V_217 ) ;
int V_67 ;
F_49 ( V_36 ) ;
V_67 = F_123 ( V_2 , V_36 , V_121 ) ;
F_51 ( V_36 ) ;
if ( V_67 == 0 ) {
if ( V_121 -> V_230 <= V_180 ) {
char * V_231 = F_124 ( V_193 -> V_210 , V_232 ) ;
memset ( V_231 , 0 , F_106 ( V_36 ) ) ;
F_125 ( V_231 , V_232 ) ;
} else if ( V_193 -> V_218 )
V_193 -> V_221 = 1 ;
else
V_67 = F_117 ( V_2 , V_4 , V_227 , V_193 , V_226 ) ;
if ( V_67 == 0 )
F_114 ( V_2 , V_227 , 1 ) ;
}
return V_67 ;
}
static int F_126 ( const struct V_1 * V_2 ,
const struct V_23 * V_24 ,
const struct V_199 * V_200 ,
unsigned V_228 , unsigned V_229 )
{
struct V_35 * V_36 = V_200 -> V_201 ;
struct V_192 * V_193 = F_97 ( V_200 ) ;
struct V_42 * V_227 = V_200 -> V_202 ;
struct V_43 * V_181 = V_193 -> V_210 ;
int V_67 ;
V_68 ;
F_127 ( F_128 ( V_2 , V_227 ) ) ;
F_3 ( V_181 -> V_187 -> V_233 == F_9 ( V_36 ) ) ;
V_67 = 0 ;
F_113 ( V_167 , V_2 , V_227 , L_21 , V_228 , V_229 ) ;
if ( ! F_129 ( V_181 ) ) {
if ( V_228 == 0 && V_229 == V_153 ) {
F_113 ( V_167 , V_2 , V_227 , L_22 ) ;
F_130 ( V_43 , 0x11 ) ;
} else
V_67 = F_122 ( V_2 , V_24 -> V_34 , V_36 ,
V_227 , V_193 , V_228 , V_229 ) ;
} else
F_113 ( V_167 , V_2 , V_227 , L_23 ) ;
RETURN ( V_67 ) ;
}
static int F_131 ( const struct V_1 * V_2 ,
const struct V_23 * V_24 ,
const struct V_199 * V_200 ,
unsigned V_228 , unsigned V_229 )
{
struct V_35 * V_36 = V_200 -> V_201 ;
struct V_3 * V_4 = V_24 -> V_34 ;
struct V_192 * V_193 = F_97 ( V_200 ) ;
struct V_42 * V_227 = V_200 -> V_202 ;
struct V_12 * V_12 = F_9 ( V_36 ) ;
struct V_203 * V_204 = F_72 ( V_12 ) ;
struct V_13 * V_14 = F_5 ( V_12 ) ;
struct V_43 * V_181 = V_193 -> V_210 ;
int V_67 ;
int V_234 ;
T_4 V_119 ;
V_68 ;
F_127 ( F_128 ( V_2 , V_227 ) ) ;
F_3 ( V_181 -> V_187 -> V_233 == V_12 ) ;
F_64 ( V_145 , V_2 , & V_36 -> V_146 , L_24 ) ;
F_113 ( V_167 , V_2 , V_227 , L_25 , V_228 , V_229 ) ;
if ( ! F_132 ( V_181 ) ) {
V_234 = V_235 ;
V_67 = F_101 ( V_2 , V_4 , V_227 , V_195 ) ;
if ( V_67 == 0 ) {
F_95 ( V_181 ) ;
F_99 ( F_100 ( V_36 ) , V_193 ) ;
} else if ( V_67 == - V_196 ) {
T_7 V_189 = F_65 ( V_12 ) >> V_236 ;
bool V_237 = true ;
if ( V_189 > V_227 -> V_217 ) {
V_229 = V_153 ;
V_237 = false ;
} else if ( V_189 == V_227 -> V_217 ) {
int V_238 = F_65 ( V_12 ) & ~ V_75 ;
if ( V_229 < V_238 )
V_229 = V_238 ;
}
if ( V_237 )
F_133 ( V_2 , V_227 , 0 , V_229 ) ;
V_67 = F_117 ( V_2 , V_4 , V_227 , V_193 , V_195 ) ;
if ( V_67 )
F_69 ( L_26 ,
V_227 -> V_217 , V_12 , V_67 ) ;
}
} else {
V_234 = V_239 ;
V_67 = 0 ;
}
F_134 ( V_204 , V_234 , 1 ) ;
if ( V_67 == 0 ) {
F_135 ( & V_14 -> V_240 ) ;
V_14 -> V_241 |= V_242 ;
F_136 ( & V_14 -> V_240 ) ;
}
V_119 = F_86 ( V_36 , V_227 -> V_217 ) + V_229 ;
F_41 ( V_12 ) ;
if ( V_67 == 0 ) {
if ( V_119 > F_65 ( V_12 ) ) {
F_137 ( V_12 , V_119 ) ;
F_15 ( V_38 , V_184 L_27 ,
F_84 ( F_85 ( & V_36 -> V_146 ) ) ,
( unsigned long ) V_119 ) ;
}
F_114 ( V_2 , V_227 , 1 ) ;
} else {
if ( V_119 > F_65 ( V_12 ) )
F_104 ( V_2 , V_4 , V_227 ) ;
}
F_43 ( V_12 ) ;
RETURN ( V_67 ) ;
}
int F_138 ( const struct V_1 * V_2 , struct V_35 * V_36 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_15 * V_16 = F_6 ( V_2 ) ;
struct V_12 * V_12 = F_9 ( V_36 ) ;
int V_67 ;
F_13 ( V_2 , V_36 , F_14 ( V_36 ) ) ;
V_68 ;
F_139 ( V_16 , V_243 ) ;
F_140 ( V_4 , & V_16 -> V_243 , V_36 , & V_244 ) ;
V_6 -> V_150 = 0 ;
V_67 = 0 ;
if ( V_4 -> V_7 == V_8 || V_4 -> V_7 == V_9 ) {
T_6 V_66 ;
struct V_13 * V_14 = F_5 ( V_12 ) ;
V_66 = V_4 -> V_30 . V_93 . V_100 ;
if ( V_66 == 0 )
V_67 = 1 ;
else {
V_16 -> V_142 = V_66 ;
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
F_69 ( L_28 V_184 L_29 ,
F_142 ( V_12 -> V_252 , NULL , 0 ) ,
F_84 ( F_85 ( & V_36 -> V_146 ) ) , V_67 ) ;
}
RETURN ( V_67 ) ;
}
static struct V_5 * F_8 ( const struct V_1 * V_2 ,
const struct V_23 * V_200 )
{
F_10 ( V_2 , V_200 ) ;
return F_2 ( V_2 ) ;
}
