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
F_15 ( V_38 , V_39
L_1 ,
F_16 ( F_17 ( & V_36 -> V_40 ) ) ,
V_4 -> V_41 , V_4 -> V_42 ,
V_16 -> V_19 , V_4 -> V_43 ) ;
if ( V_4 -> V_43 == 1 ) {
int V_17 ;
V_17 = F_18 ( F_9 ( V_36 ) ) ;
if ( V_17 == 0 ) {
V_4 -> V_43 = 0 ;
V_4 -> V_20 = 1 ;
V_4 -> V_42 = 1 ;
} else {
V_4 -> V_43 = 1 ;
V_4 -> V_20 = 0 ;
V_4 -> V_42 = 0 ;
V_4 -> V_44 = V_17 ;
}
}
if ( ! V_4 -> V_41 && V_4 -> V_42 ) {
T_1 V_45 = 0 ;
F_19 ( F_9 ( V_36 ) , & V_45 ) ;
V_4 -> V_20 = V_16 -> V_19 != V_45 ;
if ( V_4 -> V_20 ) {
F_15 ( V_38 ,
V_39 L_2 ,
F_16 ( F_17 ( & V_36 -> V_40 ) ) ,
V_16 -> V_19 , V_45 ) ;
F_5 ( F_9 ( V_36 ) ) -> V_46 &=
~ V_47 ;
}
}
}
static void F_20 ( const struct V_1 * V_2 ,
const struct V_23 * V_24 )
{
struct V_3 * V_4 = V_24 -> V_34 ;
struct V_48 * V_49 = V_4 -> V_30 . V_50 . V_51 ;
F_13 ( V_2 , V_4 -> V_37 , F_14 ( V_4 -> V_37 ) ) ;
if ( V_49 != NULL ) {
F_21 ( & V_49 -> V_52 , L_3 , V_4 ) ;
F_22 ( V_2 , V_49 ) ;
V_4 -> V_30 . V_50 . V_51 = NULL ;
}
F_12 ( V_2 , V_24 ) ;
}
enum V_53 F_23 ( struct V_54 * V_55 )
{
if ( ( V_55 -> V_56 & V_57 ) && ( V_55 -> V_56 & V_58 ) )
return V_59 ;
return V_60 ;
}
static int F_24 ( const struct V_1 * V_2 ,
struct V_15 * V_6 , struct V_3 * V_4 )
{
struct V_61 * V_62 = F_25 ( V_2 ) ;
struct V_63 * V_64 = V_65 -> V_64 ;
struct V_54 * V_55 ;
struct V_66 * V_67 = & V_62 -> V_68 ;
T_2 V_69 ;
unsigned long V_70 ;
unsigned long V_71 ;
T_3 V_72 ;
int V_73 ;
F_3 ( V_4 -> V_7 == V_8 || V_4 -> V_7 == V_9 ) ;
if ( ! F_1 ( V_2 , V_4 ) )
return 0 ;
if ( V_6 -> V_74 == NULL )
return 0 ;
if ( V_64 == NULL )
return 0 ;
for ( V_71 = 0 ; V_71 < V_6 -> V_75 ; V_71 ++ ) {
const struct V_76 * V_77 = & V_6 -> V_74 [ V_71 ] ;
V_70 = ( unsigned long ) V_77 -> V_78 ;
V_72 = V_77 -> V_79 ;
if ( V_72 == 0 )
continue;
V_72 += V_70 & ( ~ V_80 ) ;
V_70 &= V_80 ;
F_26 ( & V_64 -> V_81 ) ;
while( ( V_55 = F_27 ( V_64 , V_70 , V_72 ) ) != NULL ) {
struct V_12 * V_12 = V_55 -> V_82 -> V_28 -> V_29 ;
int V_83 = V_84 ;
if ( F_28 ( V_55 -> V_82 ) ) {
V_83 = V_85 ;
}
F_29 ( & V_69 , V_55 , V_70 , V_72 ) ;
V_67 -> V_86 = F_23 ( V_55 ) ;
V_67 -> V_87 = F_5 ( V_12 ) -> V_88 ;
V_67 -> V_89 = F_30 ( V_67 -> V_87 ,
V_69 . V_90 . V_91 ) ;
V_67 -> V_92 = F_30 ( V_67 -> V_87 ,
V_69 . V_90 . V_93 ) ;
V_67 -> V_94 = V_83 ;
V_73 = F_31 ( V_2 , V_4 , V_67 ) ;
F_15 ( V_38 , L_4 ,
V_67 -> V_86 , V_67 -> V_89 ,
V_67 -> V_92 ) ;
if ( V_73 < 0 )
return V_73 ;
if ( V_55 -> V_95 - V_70 >= V_72 )
break;
V_72 -= V_55 -> V_95 - V_70 ;
V_70 = V_55 -> V_95 ;
}
F_32 ( & V_64 -> V_81 ) ;
}
return 0 ;
}
static int F_33 ( const struct V_1 * V_2 , struct V_3 * V_4 ,
enum V_53 V_96 , T_4 V_91 , T_4 V_93 )
{
struct V_15 * V_16 = F_6 ( V_2 ) ;
int V_73 ;
int V_97 = 0 ;
F_3 ( V_4 -> V_7 == V_8 || V_4 -> V_7 == V_9 ) ;
F_34 ( V_2 , V_16 , V_4 ) ;
if ( V_4 -> V_30 . V_98 . V_99 )
V_97 |= V_100 ;
V_73 = F_24 ( V_2 , V_16 , V_4 ) ;
if ( V_73 == 0 )
V_73 = F_35 ( V_2 , V_4 , V_97 , V_96 , V_91 , V_93 ) ;
return V_73 ;
}
static int F_36 ( const struct V_1 * V_2 ,
const struct V_23 * V_24 )
{
struct V_3 * V_4 = V_24 -> V_34 ;
struct V_13 * V_14 = F_5 ( F_9 ( V_4 -> V_37 ) ) ;
int V_73 ;
if ( V_14 -> V_101 )
V_73 = F_33 ( V_2 , V_4 , V_60 ,
V_4 -> V_30 . V_102 . V_103 . V_104 ,
V_4 -> V_30 . V_102 . V_103 . V_104 +
V_4 -> V_30 . V_102 . V_103 . V_105 - 1 ) ;
else
V_73 = 0 ;
return V_73 ;
}
static int F_37 ( const struct V_1 * V_2 ,
const struct V_23 * V_24 )
{
struct V_3 * V_4 = V_24 -> V_34 ;
struct V_5 * V_6 = F_8 ( V_2 , V_24 ) ;
return F_38
( V_2 , V_4 , 0 , F_23 ( V_6 -> V_30 . V_31 . V_106 ) ,
V_4 -> V_30 . V_50 . V_107 , V_4 -> V_30 . V_50 . V_107 ) ;
}
static int F_39 ( const struct V_1 * V_2 ,
const struct V_23 * V_24 )
{
struct V_3 * V_4 = V_24 -> V_34 ;
T_4 V_91 ;
T_4 V_93 ;
if ( V_4 -> V_30 . V_108 . V_109 ) {
V_91 = 0 ;
V_93 = V_110 ;
} else {
V_91 = V_4 -> V_30 . V_108 . V_111 . V_104 ;
V_93 = V_91 + V_4 -> V_30 . V_108 . V_111 . V_105 - 1 ;
}
return F_33 ( V_2 , V_4 , V_59 , V_91 , V_93 ) ;
}
static int F_40 ( const struct V_1 * V_2 ,
const struct V_23 * V_24 )
{
return 0 ;
}
static int F_41 ( const struct V_1 * V_2 ,
const struct V_23 * V_24 )
{
struct V_15 * V_16 = F_6 ( V_2 ) ;
struct V_3 * V_4 = V_24 -> V_34 ;
T_5 V_112 ;
T_1 V_113 = 0 ;
if ( F_42 ( V_4 ) ) {
V_112 = V_4 -> V_30 . V_114 . V_115 . V_116 ;
if ( V_112 == 0 )
V_113 = V_117 ;
} else {
if ( ( V_4 -> V_30 . V_114 . V_115 . V_118 >=
V_4 -> V_30 . V_114 . V_115 . V_119 ) ||
( V_4 -> V_30 . V_114 . V_115 . V_120 >=
V_4 -> V_30 . V_114 . V_115 . V_119 ) )
return 0 ;
V_112 = 0 ;
}
V_16 -> V_30 . V_121 . V_122 = V_123 ;
return F_35 ( V_2 , V_4 , V_113 , V_59 ,
V_112 , V_110 ) ;
}
static int F_43 ( struct V_12 * V_12 , T_6 V_124 )
{
int V_73 ;
F_44 ( V_12 ) ;
V_73 = F_45 ( V_12 , V_124 ) ;
if ( V_73 < 0 ) {
F_46 ( V_12 ) ;
return V_73 ;
}
F_47 ( V_12 , V_124 ) ;
F_46 ( V_12 ) ;
return V_73 ;
}
static int F_48 ( const struct V_1 * V_2 ,
const struct V_23 * V_24 ,
struct V_12 * V_12 , T_4 V_124 )
{
F_49 ( V_12 ) ;
return 0 ;
}
static int F_50 ( const struct V_1 * V_2 ,
const struct V_23 * V_24 )
{
struct V_3 * V_4 = V_24 -> V_34 ;
struct V_35 * V_36 = V_4 -> V_37 ;
struct V_125 * V_126 = F_51 ( V_2 ) ;
int V_73 ;
unsigned V_127 = V_128 ;
F_52 ( V_36 ) ;
V_126 -> V_129 = V_4 -> V_30 . V_114 . V_115 . V_119 ;
if ( V_4 -> V_30 . V_114 . V_130 & V_131 ) {
V_126 -> V_132 = V_4 -> V_30 . V_114 . V_115 . V_120 ;
V_127 |= V_133 ;
}
if ( V_4 -> V_30 . V_114 . V_130 & V_134 ) {
V_126 -> V_135 = V_4 -> V_30 . V_114 . V_115 . V_118 ;
V_127 |= V_136 ;
}
V_73 = F_53 ( V_2 , V_36 , V_126 , V_127 ) ;
F_54 ( V_36 ) ;
return V_73 ;
}
static int F_55 ( const struct V_1 * V_2 ,
const struct V_23 * V_24 )
{
struct V_3 * V_4 = V_24 -> V_34 ;
struct V_12 * V_12 = F_9 ( V_4 -> V_37 ) ;
int V_73 = 0 ;
F_56 ( & V_12 -> V_137 ) ;
if ( F_42 ( V_4 ) )
V_73 = F_48 ( V_2 , V_24 , V_12 ,
V_4 -> V_30 . V_114 . V_115 . V_116 ) ;
if ( V_73 == 0 )
V_73 = F_50 ( V_2 , V_24 ) ;
return V_73 ;
}
static void F_57 ( const struct V_1 * V_2 ,
const struct V_23 * V_24 )
{
struct V_3 * V_4 = V_24 -> V_34 ;
struct V_12 * V_12 = F_9 ( V_4 -> V_37 ) ;
if ( F_42 ( V_4 ) ) {
F_43 ( V_12 , V_4 -> V_30 . V_114 . V_115 . V_116 ) ;
F_58 ( V_12 ) ;
}
F_59 ( & V_12 -> V_137 ) ;
}
static void F_60 ( const struct V_1 * V_2 ,
const struct V_23 * V_24 )
{
F_12 ( V_2 , V_24 ) ;
}
static T_3 F_61 ( struct V_138 * V_138 ,
struct V_15 * V_6 , T_4 * V_139 )
{
return F_62 ( V_6 -> V_140 , V_6 -> V_74 ,
V_6 -> V_75 , * V_139 ) ;
}
static T_3 F_63 ( struct V_138 * V_138 ,
struct V_15 * V_6 , T_4 * V_139 )
{
return F_64 ( V_6 -> V_140 , V_6 -> V_74 ,
V_6 -> V_75 , * V_139 ) ;
}
static int F_65 ( const struct V_1 * V_2 ,
const struct V_23 * V_24 )
{
struct V_5 * V_6 = F_8 ( V_2 , V_24 ) ;
struct V_15 * V_16 = F_10 ( V_2 , V_24 ) ;
struct V_3 * V_4 = V_24 -> V_34 ;
struct V_35 * V_36 = V_4 -> V_37 ;
struct V_12 * V_12 = F_9 ( V_36 ) ;
struct V_141 * V_142 = & V_6 -> V_143 ;
struct V_138 * V_138 = V_16 -> V_26 -> V_27 ;
int V_73 ;
T_4 V_144 = V_4 -> V_30 . V_102 . V_103 . V_104 ;
long V_145 = V_4 -> V_30 . V_102 . V_103 . V_105 ;
long V_146 = V_16 -> V_147 ;
int V_148 = 0 ;
F_13 ( V_2 , V_36 , F_14 ( V_36 ) ) ;
F_15 ( V_38 , L_5 , V_144 , V_144 + V_145 ) ;
if ( ! F_4 ( V_2 , V_4 , V_12 ) )
return 0 ;
V_73 = F_66 ( V_2 , V_36 , V_4 , V_144 , V_146 , & V_148 ) ;
if ( V_73 != 0 )
return V_73 ;
else if ( V_148 != 0 )
goto V_149;
F_67 ( V_150 , V_2 , & V_36 -> V_40 ,
L_6 ,
V_12 -> V_151 , V_145 , V_144 , F_68 ( V_12 ) ) ;
V_16 -> V_26 -> V_27 -> V_152 . V_153 = 0 ;
if ( ! V_6 -> V_154 ) {
V_6 -> V_154 = 1 ;
V_142 -> V_155 = F_30 ( V_36 , V_144 ) ;
V_142 -> V_156 = F_30 ( V_36 , V_146 + V_157 - 1 ) ;
F_69 ( V_138 , V_142 ) ;
}
F_70 ( V_138 ) ;
switch ( V_6 -> V_10 ) {
case V_11 :
V_73 = F_61 ( V_138 , V_16 , & V_144 ) ;
break;
case V_158 :
V_73 = F_71 ( V_138 , & V_144 ,
V_6 -> V_30 . V_159 . V_160 , V_145 ,
V_6 -> V_30 . V_159 . V_161 ) ;
V_4 -> V_21 = 0 ;
break;
default:
F_72 ( L_7 , V_6 -> V_10 ) ;
F_73 () ;
}
V_149:
if ( V_73 >= 0 ) {
if ( V_73 < V_145 )
V_4 -> V_21 = 0 ;
V_4 -> V_162 += V_73 ;
F_74 ( F_75 ( V_12 ) , V_65 -> V_163 ,
V_16 -> V_26 , V_144 , V_73 , V_164 ) ;
V_73 = 0 ;
}
return V_73 ;
}
static void F_76 ( const struct V_1 * V_2 , const struct V_23 * V_24 )
{
struct V_5 * V_6 = F_8 ( V_2 , V_24 ) ;
struct V_15 * V_16 = F_10 ( V_2 , V_24 ) ;
if ( V_6 -> V_154 )
F_77 ( V_16 -> V_26 -> V_27 , & V_6 -> V_143 ) ;
F_12 ( V_2 , V_24 ) ;
}
static int F_78 ( const struct V_1 * V_2 ,
const struct V_23 * V_24 )
{
struct V_15 * V_16 = F_10 ( V_2 , V_24 ) ;
struct V_3 * V_4 = V_24 -> V_34 ;
struct V_35 * V_36 = V_4 -> V_37 ;
struct V_12 * V_12 = F_9 ( V_36 ) ;
struct V_138 * V_138 = V_16 -> V_26 -> V_27 ;
T_3 V_73 = 0 ;
T_4 V_144 = V_4 -> V_30 . V_108 . V_111 . V_104 ;
T_6 V_145 = V_4 -> V_30 . V_108 . V_111 . V_105 ;
if ( ! F_4 ( V_2 , V_4 , V_12 ) )
return 0 ;
if ( F_79 ( V_4 ) ) {
V_144 = V_4 -> V_30 . V_108 . V_111 . V_104 = F_68 ( V_12 ) ;
V_16 -> V_140 -> V_165 = V_144 ;
}
F_15 ( V_38 , L_8 , V_144 , V_144 + ( long long ) V_145 ) ;
if ( V_16 -> V_74 == NULL )
V_73 = 0 ;
else
V_73 = F_63 ( V_138 , V_16 , & V_144 ) ;
if ( V_73 > 0 ) {
if ( V_73 < V_145 )
V_4 -> V_21 = 0 ;
V_4 -> V_162 += V_73 ;
F_74 ( F_75 ( V_12 ) , V_65 -> V_163 ,
V_16 -> V_26 , V_144 , V_73 , V_166 ) ;
V_73 = 0 ;
}
return V_73 ;
}
static int F_80 ( struct V_167 * V_168 )
{
struct V_169 * V_170 = V_168 -> V_31 . V_171 ;
V_168 -> V_31 . V_172 = F_81 ( V_168 -> V_106 , V_170 ) ;
if ( V_170 -> V_49 ) {
F_15 ( V_173 ,
L_9 ,
V_170 -> V_49 , V_170 -> V_49 -> V_174 , V_170 -> V_49 -> V_175 ,
( long ) V_170 -> V_49 -> V_83 , F_82 ( V_170 -> V_49 ) ,
F_83 ( V_170 -> V_49 ) , V_170 -> V_176 ) ;
if ( F_84 ( ! ( V_168 -> V_31 . V_172 & V_177 ) ) ) {
F_85 ( V_170 -> V_49 ) ;
V_168 -> V_31 . V_172 &= V_177 ;
}
V_168 -> V_178 = V_170 -> V_49 ;
return 0 ;
}
if ( V_168 -> V_31 . V_172 & V_179 ) {
F_15 ( V_173 , L_10 , V_170 -> V_176 ) ;
return - V_180 ;
}
if ( V_168 -> V_31 . V_172 & V_181 ) {
F_15 ( V_173 , L_11 , V_170 -> V_176 ) ;
return - V_182 ;
}
if ( V_168 -> V_31 . V_172 & V_183 )
return - V_184 ;
F_72 ( L_12 , V_168 -> V_31 . V_172 ) ;
return - V_185 ;
}
static int F_86 ( const struct V_1 * V_2 ,
const struct V_23 * V_24 )
{
struct V_5 * V_6 = F_8 ( V_2 , V_24 ) ;
struct V_3 * V_4 = V_24 -> V_34 ;
struct V_35 * V_36 = V_4 -> V_37 ;
struct V_12 * V_12 = F_9 ( V_36 ) ;
struct V_186 * V_187 = & V_4 -> V_30 . V_50 ;
struct V_167 * V_168 = & V_6 -> V_30 . V_31 ;
T_4 V_188 ;
int V_73 = 0 ;
struct V_49 * V_189 = NULL ;
struct V_48 * V_49 ;
T_4 V_124 ;
T_7 V_190 ;
if ( V_187 -> V_191 &&
F_11 ( V_12 -> V_33 ) != V_6 -> V_30 . V_31 . V_32 )
F_87 ( L_13 V_39
L_14 ,
F_16 ( F_17 ( & V_36 -> V_40 ) ) ) ;
V_188 = F_88 ( V_36 , V_187 -> V_107 + 1 ) - 1 ;
F_3 ( F_30 ( V_36 , V_188 ) == V_187 -> V_107 ) ;
V_73 = F_66 ( V_2 , V_36 , V_4 , 0 , V_188 + 1 , NULL ) ;
if ( V_73 != 0 )
return V_73 ;
if ( V_187 -> V_192 ) {
F_3 ( V_168 -> V_178 != NULL ) ;
F_85 ( V_168 -> V_178 ) ;
} else {
V_73 = F_80 ( V_168 ) ;
if ( V_73 != 0 )
return V_73 ;
}
V_189 = V_168 -> V_178 ;
F_3 ( F_89 ( V_189 ) ) ;
if ( F_90 ( V_193 ) )
F_91 ( V_189 ) ;
V_124 = F_68 ( V_12 ) ;
if ( F_84 ( ( V_189 -> V_174 != V_12 -> V_194 ) ||
( F_92 ( V_189 ) > V_124 ) ) ) {
F_15 ( V_173 , L_15 ) ;
GOTO ( V_149 , V_73 = + 1 ) ;
}
if ( V_187 -> V_192 ) {
T_7 V_195 ;
V_195 = F_30 ( V_36 , V_124 - 1 ) ;
if ( V_195 < V_187 -> V_107 ) {
F_15 ( V_173 ,
L_16
L_17 ,
V_189 -> V_174 , V_187 -> V_107 , V_195 ) ;
GOTO ( V_149 , V_73 = - V_196 ) ;
}
}
V_49 = F_93 ( V_2 , V_36 , V_187 -> V_107 , V_189 , V_197 ) ;
if ( F_94 ( V_49 ) )
GOTO ( V_149 , V_73 = F_95 ( V_49 ) ) ;
if ( V_187 -> V_192 ) {
F_96 ( V_189 ) ;
if ( F_97 ( V_189 ) ) {
struct V_198 * V_199 ;
F_98 ( V_2 , V_4 , V_49 ) ;
V_199 = F_99 ( F_100 ( V_49 , & V_200 ) ) ;
F_101 ( F_102 ( V_36 ) , V_199 ) ;
V_73 = F_103 ( V_2 , V_4 , V_49 , V_201 ) ;
F_3 ( F_104 ( V_49 , V_4 ) ) ;
V_189 = NULL ;
if ( V_73 < 0 ) {
F_105 ( V_2 , V_4 , V_49 ) ;
F_106 ( V_2 , V_4 , V_49 ) ;
F_107 ( V_2 , V_4 , V_49 ) ;
F_22 ( V_2 , V_49 ) ;
if ( V_73 == - V_202 )
V_73 = - V_203 ;
GOTO ( V_149 , V_73 ) ;
} else
F_107 ( V_2 , V_4 , V_49 ) ;
}
}
V_190 = F_30 ( V_36 , V_124 - 1 ) ;
F_3 ( ! V_187 -> V_192 || V_187 -> V_107 <= V_190 ) ;
if ( V_187 -> V_107 == V_190 )
V_187 -> V_204 = V_124 - F_88 ( V_36 , V_187 -> V_107 ) ;
else
V_187 -> V_204 = F_108 ( V_36 ) ;
F_109 ( & V_49 -> V_52 , L_3 , V_4 ) ;
V_187 -> V_51 = V_49 ;
V_149:
if ( V_189 != NULL )
F_110 ( V_189 ) ;
V_168 -> V_31 . V_172 &= ~ V_177 ;
return V_73 ;
}
static int F_111 ( const struct V_1 * V_2 ,
const struct V_23 * V_24 )
{
return 0 ;
}
static int F_112 ( const struct V_1 * V_2 ,
const struct V_23 * V_24 ,
const struct V_205 * V_206 )
{
struct V_3 * V_4 = V_24 -> V_34 ;
struct V_35 * V_36 = V_206 -> V_207 ;
struct V_198 * V_199 = F_99 ( V_206 ) ;
struct V_48 * V_49 = V_206 -> V_208 ;
struct V_12 * V_12 = F_9 ( V_36 ) ;
struct V_209 * V_210 = F_75 ( V_12 ) ;
struct V_211 * V_212 = F_10 ( V_2 , V_24 ) -> V_26 ;
struct V_213 * V_214 = & V_212 -> V_215 ;
struct V_49 * V_189 = V_199 -> V_216 ;
struct V_217 * V_218 = & V_4 -> V_219 ;
int V_17 ;
F_13 ( V_2 , V_36 , F_14 ( V_36 ) ) ;
F_3 ( V_206 -> V_207 == V_36 ) ;
if ( V_210 -> V_220 . V_221 &&
V_210 -> V_220 . V_222 )
F_113 ( V_210 , V_12 , V_214 , V_49 -> V_223 ,
V_199 -> V_224 ) ;
V_17 = F_114 ( V_2 , V_4 , V_49 ) ;
if ( V_17 != - V_225 ) {
F_115 ( V_226 , V_2 , V_49 , L_18 ,
V_17 == - V_196 ? L_19 :
L_20 , V_17 ) ;
if ( V_17 != - V_196 )
return V_17 ;
}
if ( V_199 -> V_224 ) {
V_199 -> V_227 = 1 ;
F_116 ( V_2 , V_49 , 1 ) ;
}
F_117 ( V_218 , V_49 ) ;
if ( V_210 -> V_220 . V_221 &&
V_210 -> V_220 . V_222 )
F_118 ( V_2 , V_4 , V_214 ,
V_189 -> V_174 , & V_218 -> V_228 , V_212 -> V_229 ) ;
return 0 ;
}
static int F_119 ( const struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_48 * V_49 , struct V_198 * V_199 ,
enum V_230 V_231 )
{
struct V_217 * V_218 ;
int V_73 ;
F_3 ( V_4 -> V_7 == V_8 || V_4 -> V_7 == V_9 ) ;
V_218 = & V_4 -> V_219 ;
F_120 ( V_218 , V_49 ) ;
V_73 = F_121 ( V_2 , V_4 , V_231 , V_218 , 0 ) ;
F_3 ( F_104 ( V_49 , V_4 ) ) ;
if ( V_231 == V_232 )
F_122 ( V_2 , V_4 , & V_218 -> V_228 ) ;
F_123 ( V_2 , V_218 ) ;
return V_73 ;
}
static int F_124 ( const struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_35 * V_36 , struct V_48 * V_233 ,
struct V_198 * V_199 ,
unsigned V_234 , unsigned V_235 )
{
struct V_125 * V_126 = F_51 ( V_2 ) ;
T_4 V_188 = F_88 ( V_36 , V_233 -> V_223 ) ;
int V_73 ;
F_52 ( V_36 ) ;
V_73 = F_125 ( V_2 , V_36 , V_126 ) ;
F_54 ( V_36 ) ;
if ( V_73 == 0 ) {
if ( V_126 -> V_236 <= V_188 ) {
char * V_237 = F_126 ( V_199 -> V_216 ) ;
memset ( V_237 , 0 , F_108 ( V_36 ) ) ;
F_127 ( V_237 ) ;
} else if ( V_199 -> V_224 )
V_199 -> V_227 = 1 ;
else
V_73 = F_119 ( V_2 , V_4 , V_233 , V_199 , V_232 ) ;
if ( V_73 == 0 )
F_116 ( V_2 , V_233 , 1 ) ;
}
return V_73 ;
}
static int F_128 ( const struct V_1 * V_2 ,
const struct V_23 * V_24 ,
const struct V_205 * V_206 ,
unsigned V_234 , unsigned V_235 )
{
struct V_35 * V_36 = V_206 -> V_207 ;
struct V_198 * V_199 = F_99 ( V_206 ) ;
struct V_48 * V_233 = V_206 -> V_208 ;
struct V_49 * V_189 = V_199 -> V_216 ;
int V_73 ;
F_129 ( F_130 ( V_2 , V_233 ) ) ;
F_3 ( V_189 -> V_174 -> V_238 == F_9 ( V_36 ) ) ;
V_73 = 0 ;
F_115 ( V_173 , V_2 , V_233 , L_21 , V_234 , V_235 ) ;
if ( ! F_131 ( V_189 ) ) {
if ( V_234 == 0 && V_235 == V_157 ) {
F_115 ( V_173 , V_2 , V_233 , L_22 ) ;
F_132 ( V_49 , 0x11 ) ;
} else
V_73 = F_124 ( V_2 , V_24 -> V_34 , V_36 ,
V_233 , V_199 , V_234 , V_235 ) ;
} else
F_115 ( V_173 , V_2 , V_233 , L_23 ) ;
return V_73 ;
}
static int F_133 ( const struct V_1 * V_2 ,
const struct V_23 * V_24 ,
const struct V_205 * V_206 ,
unsigned V_234 , unsigned V_235 )
{
struct V_35 * V_36 = V_206 -> V_207 ;
struct V_3 * V_4 = V_24 -> V_34 ;
struct V_198 * V_199 = F_99 ( V_206 ) ;
struct V_48 * V_233 = V_206 -> V_208 ;
struct V_12 * V_12 = F_9 ( V_36 ) ;
struct V_209 * V_210 = F_75 ( V_12 ) ;
struct V_13 * V_14 = F_5 ( V_12 ) ;
struct V_49 * V_189 = V_199 -> V_216 ;
int V_73 ;
int V_239 ;
T_4 V_124 ;
F_129 ( F_130 ( V_2 , V_233 ) ) ;
F_3 ( V_189 -> V_174 -> V_238 == V_12 ) ;
F_67 ( V_150 , V_2 , & V_36 -> V_40 , L_24 ) ;
F_115 ( V_173 , V_2 , V_233 , L_25 , V_234 , V_235 ) ;
if ( ! F_134 ( V_189 ) ) {
V_239 = V_240 ;
V_73 = F_103 ( V_2 , V_4 , V_233 , V_201 ) ;
if ( V_73 == 0 ) {
F_97 ( V_189 ) ;
F_101 ( F_102 ( V_36 ) , V_199 ) ;
} else if ( V_73 == - V_202 ) {
T_7 V_195 = F_68 ( V_12 ) >> V_241 ;
bool V_242 = true ;
if ( V_195 > V_233 -> V_223 ) {
V_235 = V_157 ;
V_242 = false ;
} else if ( V_195 == V_233 -> V_223 ) {
int V_243 = F_68 ( V_12 ) & ~ V_80 ;
if ( V_235 < V_243 )
V_235 = V_243 ;
}
if ( V_242 )
F_135 ( V_2 , V_233 , 0 , V_235 ) ;
V_73 = F_119 ( V_2 , V_4 , V_233 , V_199 , V_201 ) ;
if ( V_73 )
F_72 ( L_26 ,
V_233 -> V_223 , V_12 , V_73 ) ;
}
} else {
V_239 = V_244 ;
V_73 = 0 ;
}
F_136 ( V_210 , V_239 , 1 ) ;
if ( V_73 == 0 ) {
F_137 ( & V_14 -> V_245 ) ;
V_14 -> V_46 |= V_246 ;
F_138 ( & V_14 -> V_245 ) ;
}
V_124 = F_88 ( V_36 , V_233 -> V_223 ) + V_235 ;
F_44 ( V_12 ) ;
if ( V_73 == 0 ) {
if ( V_124 > F_68 ( V_12 ) ) {
F_139 ( V_12 , V_124 ) ;
F_15 ( V_38 , V_39 L_27 ,
F_16 ( F_17 ( & V_36 -> V_40 ) ) ,
( unsigned long ) V_124 ) ;
}
F_116 ( V_2 , V_233 , 1 ) ;
} else {
if ( V_124 > F_68 ( V_12 ) )
F_106 ( V_2 , V_4 , V_233 ) ;
}
F_46 ( V_12 ) ;
return V_73 ;
}
int F_140 ( const struct V_1 * V_2 , struct V_35 * V_36 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_15 * V_16 = F_6 ( V_2 ) ;
struct V_12 * V_12 = F_9 ( V_36 ) ;
int V_73 ;
F_13 ( V_2 , V_36 , F_14 ( V_36 ) ) ;
F_15 ( V_38 , V_39
L_1 ,
F_16 ( F_17 ( & V_36 -> V_40 ) ) ,
V_4 -> V_41 , V_4 -> V_42 ,
V_16 -> V_19 , V_4 -> V_43 ) ;
F_141 ( V_16 , V_247 ) ;
F_142 ( V_4 , & V_16 -> V_247 , V_36 , & V_248 ) ;
V_6 -> V_154 = 0 ;
V_73 = 0 ;
if ( V_4 -> V_7 == V_8 || V_4 -> V_7 == V_9 ) {
T_6 V_72 ;
struct V_13 * V_14 = F_5 ( V_12 ) ;
V_72 = V_4 -> V_30 . V_98 . V_105 ;
if ( V_72 == 0 )
V_73 = 1 ;
else {
V_16 -> V_147 = V_72 ;
V_16 -> V_249 = 0 ;
}
F_143 ( V_14 -> V_250 ) ;
} else if ( V_4 -> V_7 == V_251 ) {
if ( ! F_42 ( V_4 ) )
V_4 -> V_252 = V_253 ;
}
if ( V_4 -> V_7 == V_254 && ! V_4 -> V_42 )
V_4 -> V_41 = 1 ;
if ( V_73 == 0 && ! V_4 -> V_41 ) {
V_73 = F_19 ( V_12 , & V_16 -> V_19 ) ;
if ( V_73 == - V_255 )
V_73 = 0 ;
if ( V_73 < 0 )
F_72 ( L_28 V_39 L_29 ,
F_144 ( V_12 -> V_256 , NULL , 0 ) ,
F_16 ( F_17 ( & V_36 -> V_40 ) ) , V_73 ) ;
}
return V_73 ;
}
static struct V_5 * F_8 ( const struct V_1 * V_2 ,
const struct V_23 * V_206 )
{
F_10 ( V_2 , V_206 ) ;
return F_2 ( V_2 ) ;
}
