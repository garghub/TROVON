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
if ( F_7 ( V_14 ) != V_16 -> V_18 ) {
V_4 -> V_19 = 1 ;
V_4 -> V_20 = 0 ;
V_17 = false ;
}
case V_21 :
default:
break;
}
return V_17 ;
}
static int F_8 ( const struct V_1 * V_2 ,
const struct V_22 * V_23 )
{
struct V_5 * V_6 = F_9 ( V_2 , V_23 ) ;
struct V_12 * V_12 = F_10 ( V_23 -> V_24 ) ;
F_3 ( V_12 ==
F_11 ( V_2 , V_23 ) -> V_25 -> V_26 -> V_27 -> V_28 ) ;
V_6 -> V_29 . V_30 . V_31 = F_12 ( V_12 -> V_32 ) ;
return 0 ;
}
static void F_13 ( const struct V_1 * V_2 , const struct V_22 * V_23 )
{
struct V_3 * V_4 = V_23 -> V_33 ;
struct V_34 * V_35 = V_4 -> V_36 ;
struct V_15 * V_16 = F_11 ( V_2 , V_23 ) ;
F_14 ( V_2 , V_35 , F_15 ( V_35 ) ) ;
F_16 ( V_37 , V_38
L_1 ,
F_17 ( F_18 ( & V_35 -> V_39 ) ) ,
V_4 -> V_40 , V_4 -> V_41 ,
V_16 -> V_18 , V_4 -> V_42 ) ;
if ( V_4 -> V_42 == 1 ) {
int V_17 ;
V_17 = F_19 ( F_10 ( V_35 ) ) ;
if ( V_17 == 0 ) {
V_4 -> V_42 = 0 ;
V_4 -> V_19 = 1 ;
V_4 -> V_41 = 1 ;
} else {
V_4 -> V_42 = 1 ;
V_4 -> V_19 = 0 ;
V_4 -> V_41 = 0 ;
V_4 -> V_43 = V_17 ;
}
}
if ( ! V_4 -> V_40 && V_4 -> V_41 ) {
T_1 V_44 = 0 ;
F_20 ( F_10 ( V_35 ) , & V_44 ) ;
V_4 -> V_19 = V_16 -> V_18 != V_44 ;
if ( V_4 -> V_19 ) {
F_16 ( V_37 ,
V_38 L_2 ,
F_17 ( F_18 ( & V_35 -> V_39 ) ) ,
V_16 -> V_18 , V_44 ) ;
F_5 ( F_10 ( V_35 ) ) -> V_45 &=
~ V_46 ;
}
}
}
static void F_21 ( const struct V_1 * V_2 ,
const struct V_22 * V_23 )
{
struct V_3 * V_4 = V_23 -> V_33 ;
struct V_47 * V_48 = V_4 -> V_29 . V_49 . V_50 ;
F_14 ( V_2 , V_4 -> V_36 , F_15 ( V_4 -> V_36 ) ) ;
if ( V_48 != NULL ) {
F_22 ( & V_48 -> V_51 , L_3 , V_4 ) ;
F_23 ( V_2 , V_48 ) ;
V_4 -> V_29 . V_49 . V_50 = NULL ;
}
F_13 ( V_2 , V_23 ) ;
}
static enum V_52 F_24 ( struct V_53 * V_54 )
{
if ( ( V_54 -> V_55 & V_56 ) && ( V_54 -> V_55 & V_57 ) )
return V_58 ;
return V_59 ;
}
static int F_25 ( const struct V_1 * V_2 ,
struct V_15 * V_6 , struct V_3 * V_4 )
{
struct V_60 * V_61 = F_26 ( V_2 ) ;
struct V_62 * V_63 = V_64 -> V_63 ;
struct V_53 * V_54 ;
struct V_65 * V_66 = & V_61 -> V_67 ;
T_2 V_68 ;
unsigned long V_69 ;
T_3 V_70 ;
int V_71 ;
struct V_72 V_73 ;
struct V_74 V_75 ;
F_3 ( V_4 -> V_7 == V_8 || V_4 -> V_7 == V_9 ) ;
if ( ! F_1 ( V_2 , V_4 ) )
return 0 ;
if ( V_6 -> V_76 == NULL )
return 0 ;
if ( V_63 == NULL )
return 0 ;
F_27 (iov, i, *(vio->cui_iter)) {
V_69 = ( unsigned long ) V_75 . V_77 ;
V_70 = V_75 . V_78 ;
if ( V_70 == 0 )
continue;
V_70 += V_69 & ( ~ V_79 ) ;
V_69 &= V_79 ;
F_28 ( & V_63 -> V_80 ) ;
while ( ( V_54 = F_29 ( V_63 , V_69 , V_70 ) ) != NULL ) {
struct V_12 * V_12 = V_54 -> V_81 -> V_27 -> V_28 ;
int V_82 = V_83 ;
if ( F_30 ( V_54 -> V_81 ) ) {
V_82 = V_84 ;
}
F_31 ( & V_68 , V_54 , V_69 , V_70 ) ;
V_66 -> V_85 = F_24 ( V_54 ) ;
V_66 -> V_86 = F_5 ( V_12 ) -> V_87 ;
V_66 -> V_88 = F_32 ( V_66 -> V_86 ,
V_68 . V_89 . V_90 ) ;
V_66 -> V_91 = F_32 ( V_66 -> V_86 ,
V_68 . V_89 . V_92 ) ;
V_66 -> V_93 = V_82 ;
V_71 = F_33 ( V_2 , V_4 , V_66 ) ;
F_16 ( V_37 , L_4 ,
V_66 -> V_85 , V_66 -> V_88 ,
V_66 -> V_91 ) ;
if ( V_71 < 0 ) {
F_34 ( & V_63 -> V_80 ) ;
return V_71 ;
}
if ( V_54 -> V_94 - V_69 >= V_70 )
break;
V_70 -= V_54 -> V_94 - V_69 ;
V_69 = V_54 -> V_94 ;
}
F_34 ( & V_63 -> V_80 ) ;
}
return 0 ;
}
static int F_35 ( const struct V_1 * V_2 , struct V_3 * V_4 ,
enum V_52 V_95 , T_4 V_90 , T_4 V_92 )
{
struct V_15 * V_16 = F_6 ( V_2 ) ;
int V_71 ;
int V_96 = 0 ;
F_3 ( V_4 -> V_7 == V_8 || V_4 -> V_7 == V_9 ) ;
F_36 ( V_2 , V_16 , V_4 ) ;
if ( V_4 -> V_29 . V_97 . V_98 )
V_96 |= V_99 ;
V_71 = F_25 ( V_2 , V_16 , V_4 ) ;
if ( V_71 == 0 )
V_71 = F_37 ( V_2 , V_4 , V_96 , V_95 , V_90 , V_92 ) ;
return V_71 ;
}
static int F_38 ( const struct V_1 * V_2 ,
const struct V_22 * V_23 )
{
struct V_3 * V_4 = V_23 -> V_33 ;
struct V_13 * V_14 = F_5 ( F_10 ( V_4 -> V_36 ) ) ;
int V_71 ;
if ( V_14 -> V_100 )
V_71 = F_35 ( V_2 , V_4 , V_59 ,
V_4 -> V_29 . V_101 . V_102 . V_103 ,
V_4 -> V_29 . V_101 . V_102 . V_103 +
V_4 -> V_29 . V_101 . V_102 . V_104 - 1 ) ;
else
V_71 = 0 ;
return V_71 ;
}
static int F_39 ( const struct V_1 * V_2 ,
const struct V_22 * V_23 )
{
struct V_3 * V_4 = V_23 -> V_33 ;
struct V_5 * V_6 = F_9 ( V_2 , V_23 ) ;
return F_40
( V_2 , V_4 , 0 , F_24 ( V_6 -> V_29 . V_30 . V_105 ) ,
V_4 -> V_29 . V_49 . V_106 , V_4 -> V_29 . V_49 . V_106 ) ;
}
static int F_41 ( const struct V_1 * V_2 ,
const struct V_22 * V_23 )
{
struct V_3 * V_4 = V_23 -> V_33 ;
T_4 V_90 ;
T_4 V_92 ;
if ( V_4 -> V_29 . V_107 . V_108 ) {
V_90 = 0 ;
V_92 = V_109 ;
} else {
V_90 = V_4 -> V_29 . V_107 . V_110 . V_103 ;
V_92 = V_90 + V_4 -> V_29 . V_107 . V_110 . V_104 - 1 ;
}
return F_35 ( V_2 , V_4 , V_58 , V_90 , V_92 ) ;
}
static int F_42 ( const struct V_1 * V_2 ,
const struct V_22 * V_23 )
{
return 0 ;
}
static int F_43 ( const struct V_1 * V_2 ,
const struct V_22 * V_23 )
{
struct V_15 * V_16 = F_6 ( V_2 ) ;
struct V_3 * V_4 = V_23 -> V_33 ;
T_5 V_111 ;
T_1 V_112 = 0 ;
if ( F_44 ( V_4 ) ) {
V_111 = V_4 -> V_29 . V_113 . V_114 . V_115 ;
if ( V_111 == 0 )
V_112 = V_116 ;
} else {
if ( ( V_4 -> V_29 . V_113 . V_114 . V_117 >=
V_4 -> V_29 . V_113 . V_114 . V_118 ) ||
( V_4 -> V_29 . V_113 . V_114 . V_119 >=
V_4 -> V_29 . V_113 . V_114 . V_118 ) )
return 0 ;
V_111 = 0 ;
}
V_16 -> V_29 . V_120 . V_121 = V_122 ;
return F_37 ( V_2 , V_4 , V_112 , V_58 ,
V_111 , V_109 ) ;
}
static int F_45 ( struct V_12 * V_12 , T_6 V_123 )
{
int V_71 ;
F_46 ( V_12 ) ;
V_71 = F_47 ( V_12 , V_123 ) ;
if ( V_71 < 0 ) {
F_48 ( V_12 ) ;
return V_71 ;
}
F_49 ( V_12 , V_123 ) ;
F_48 ( V_12 ) ;
return V_71 ;
}
static int F_50 ( const struct V_1 * V_2 ,
const struct V_22 * V_23 ,
struct V_12 * V_12 , T_4 V_123 )
{
F_51 ( V_12 ) ;
return 0 ;
}
static int F_52 ( const struct V_1 * V_2 ,
const struct V_22 * V_23 )
{
struct V_3 * V_4 = V_23 -> V_33 ;
struct V_34 * V_35 = V_4 -> V_36 ;
struct V_124 * V_125 = F_53 ( V_2 ) ;
int V_71 ;
unsigned V_126 = V_127 ;
F_54 ( V_35 ) ;
V_125 -> V_128 = V_4 -> V_29 . V_113 . V_114 . V_118 ;
if ( V_4 -> V_29 . V_113 . V_129 & V_130 ) {
V_125 -> V_131 = V_4 -> V_29 . V_113 . V_114 . V_119 ;
V_126 |= V_132 ;
}
if ( V_4 -> V_29 . V_113 . V_129 & V_133 ) {
V_125 -> V_134 = V_4 -> V_29 . V_113 . V_114 . V_117 ;
V_126 |= V_135 ;
}
V_71 = F_55 ( V_2 , V_35 , V_125 , V_126 ) ;
F_56 ( V_35 ) ;
return V_71 ;
}
static int F_57 ( const struct V_1 * V_2 ,
const struct V_22 * V_23 )
{
struct V_3 * V_4 = V_23 -> V_33 ;
struct V_12 * V_12 = F_10 ( V_4 -> V_36 ) ;
int V_71 = 0 ;
F_58 ( & V_12 -> V_136 ) ;
if ( F_44 ( V_4 ) )
V_71 = F_50 ( V_2 , V_23 , V_12 ,
V_4 -> V_29 . V_113 . V_114 . V_115 ) ;
if ( V_71 == 0 )
V_71 = F_52 ( V_2 , V_23 ) ;
return V_71 ;
}
static void F_59 ( const struct V_1 * V_2 ,
const struct V_22 * V_23 )
{
struct V_3 * V_4 = V_23 -> V_33 ;
struct V_12 * V_12 = F_10 ( V_4 -> V_36 ) ;
if ( F_44 ( V_4 ) ) {
F_45 ( V_12 , V_4 -> V_29 . V_113 . V_114 . V_115 ) ;
F_60 ( V_12 ) ;
}
F_61 ( & V_12 -> V_136 ) ;
}
static void F_62 ( const struct V_1 * V_2 ,
const struct V_22 * V_23 )
{
F_13 ( V_2 , V_23 ) ;
}
static int F_63 ( const struct V_1 * V_2 ,
const struct V_22 * V_23 )
{
struct V_5 * V_6 = F_9 ( V_2 , V_23 ) ;
struct V_15 * V_16 = F_11 ( V_2 , V_23 ) ;
struct V_3 * V_4 = V_23 -> V_33 ;
struct V_34 * V_35 = V_4 -> V_36 ;
struct V_12 * V_12 = F_10 ( V_35 ) ;
struct V_137 * V_138 = & V_6 -> V_139 ;
struct V_140 * V_140 = V_16 -> V_25 -> V_26 ;
int V_71 ;
T_4 V_141 = V_4 -> V_29 . V_101 . V_102 . V_103 ;
long V_142 = V_4 -> V_29 . V_101 . V_102 . V_104 ;
long V_143 = V_16 -> V_144 ;
int V_145 = 0 ;
F_14 ( V_2 , V_35 , F_15 ( V_35 ) ) ;
F_16 ( V_37 , L_5 , V_141 , V_141 + V_142 ) ;
if ( ! F_4 ( V_2 , V_4 , V_12 ) )
return 0 ;
V_71 = F_64 ( V_2 , V_35 , V_4 , V_141 , V_143 , & V_145 ) ;
if ( V_71 != 0 )
return V_71 ;
else if ( V_145 != 0 )
goto V_146;
F_65 ( V_147 , V_2 , & V_35 -> V_39 ,
L_6 ,
V_12 -> V_148 , V_142 , V_141 , F_66 ( V_12 ) ) ;
V_16 -> V_25 -> V_26 -> V_149 . V_150 = 0 ;
if ( ! V_6 -> V_151 ) {
V_6 -> V_151 = 1 ;
V_138 -> V_152 = F_32 ( V_35 , V_141 ) ;
V_138 -> V_153 = F_32 ( V_35 , V_143 + V_154 - 1 ) ;
F_67 ( V_140 , V_138 ) ;
}
F_68 ( V_140 ) ;
switch ( V_6 -> V_10 ) {
case V_11 :
F_3 ( V_16 -> V_155 -> V_156 == V_141 ) ;
V_71 = F_69 ( V_16 -> V_155 , V_16 -> V_76 ) ;
break;
case V_157 :
V_71 = F_70 ( V_140 , & V_141 ,
V_6 -> V_29 . V_158 . V_159 , V_142 ,
V_6 -> V_29 . V_158 . V_160 ) ;
V_4 -> V_20 = 0 ;
break;
default:
F_71 ( L_7 , V_6 -> V_10 ) ;
F_72 () ;
}
V_146:
if ( V_71 >= 0 ) {
if ( V_71 < V_142 )
V_4 -> V_20 = 0 ;
V_4 -> V_161 += V_71 ;
F_73 ( F_74 ( V_12 ) , V_64 -> V_162 ,
V_16 -> V_25 , V_141 , V_71 , V_163 ) ;
V_71 = 0 ;
}
return V_71 ;
}
static void F_75 ( const struct V_1 * V_2 , const struct V_22 * V_23 )
{
struct V_5 * V_6 = F_9 ( V_2 , V_23 ) ;
struct V_15 * V_16 = F_11 ( V_2 , V_23 ) ;
if ( V_6 -> V_151 )
F_76 ( V_16 -> V_25 -> V_26 , & V_6 -> V_139 ) ;
F_13 ( V_2 , V_23 ) ;
}
static int F_77 ( const struct V_1 * V_2 ,
const struct V_22 * V_23 )
{
struct V_15 * V_16 = F_11 ( V_2 , V_23 ) ;
struct V_3 * V_4 = V_23 -> V_33 ;
struct V_34 * V_35 = V_4 -> V_36 ;
struct V_12 * V_12 = F_10 ( V_35 ) ;
T_3 V_71 = 0 ;
T_4 V_141 = V_4 -> V_29 . V_107 . V_110 . V_103 ;
T_6 V_142 = V_4 -> V_29 . V_107 . V_110 . V_104 ;
if ( ! F_4 ( V_2 , V_4 , V_12 ) )
return 0 ;
if ( F_78 ( V_4 ) ) {
V_141 = V_4 -> V_29 . V_107 . V_110 . V_103 = F_66 ( V_12 ) ;
V_16 -> V_155 -> V_156 = V_141 ;
} else {
F_3 ( V_16 -> V_155 -> V_156 == V_141 ) ;
}
F_16 ( V_37 , L_8 , V_141 , V_141 + ( long long ) V_142 ) ;
if ( V_16 -> V_76 == NULL )
V_71 = 0 ;
else
V_71 = F_79 ( V_16 -> V_155 , V_16 -> V_76 ) ;
if ( V_71 > 0 ) {
if ( V_71 < V_142 )
V_4 -> V_20 = 0 ;
V_4 -> V_161 += V_71 ;
F_73 ( F_74 ( V_12 ) , V_64 -> V_162 ,
V_16 -> V_25 , V_141 , V_71 , V_164 ) ;
V_71 = 0 ;
}
return V_71 ;
}
static int F_80 ( struct V_165 * V_166 )
{
struct V_167 * V_168 = V_166 -> V_30 . V_169 ;
V_166 -> V_30 . V_170 = F_81 ( V_166 -> V_105 , V_168 ) ;
V_166 -> V_30 . V_171 = 1 ;
if ( V_168 -> V_48 ) {
F_16 ( V_172 ,
L_9 ,
V_168 -> V_48 , V_168 -> V_48 -> V_173 , V_168 -> V_48 -> V_174 ,
( long ) V_168 -> V_48 -> V_82 , F_82 ( V_168 -> V_48 ) ,
F_83 ( V_168 -> V_48 ) , V_168 -> V_175 ) ;
if ( F_84 ( ! ( V_166 -> V_30 . V_170 & V_176 ) ) ) {
F_85 ( V_168 -> V_48 ) ;
V_166 -> V_30 . V_170 |= V_176 ;
}
V_166 -> V_177 = V_168 -> V_48 ;
return 0 ;
}
if ( V_166 -> V_30 . V_170 & V_178 ) {
F_16 ( V_172 , L_10 , V_168 -> V_175 ) ;
return - V_179 ;
}
if ( V_166 -> V_30 . V_170 & V_180 ) {
F_16 ( V_172 , L_11 , V_168 -> V_175 ) ;
return - V_181 ;
}
if ( V_166 -> V_30 . V_170 & V_182 )
return - V_183 ;
F_71 ( L_12 , V_166 -> V_30 . V_170 ) ;
return - V_184 ;
}
static int F_86 ( const struct V_1 * V_2 ,
const struct V_22 * V_23 )
{
struct V_5 * V_6 = F_9 ( V_2 , V_23 ) ;
struct V_3 * V_4 = V_23 -> V_33 ;
struct V_34 * V_35 = V_4 -> V_36 ;
struct V_12 * V_12 = F_10 ( V_35 ) ;
struct V_185 * V_186 = & V_4 -> V_29 . V_49 ;
struct V_165 * V_166 = & V_6 -> V_29 . V_30 ;
T_4 V_187 ;
int V_71 = 0 ;
struct V_48 * V_188 = NULL ;
struct V_47 * V_48 ;
T_4 V_123 ;
T_7 V_189 ;
if ( V_186 -> V_190 &&
F_12 ( V_12 -> V_32 ) != V_6 -> V_29 . V_30 . V_31 )
F_87 ( L_13 V_38
L_14 ,
F_17 ( F_18 ( & V_35 -> V_39 ) ) ) ;
V_187 = F_88 ( V_35 , V_186 -> V_106 + 1 ) - 1 ;
F_3 ( F_32 ( V_35 , V_187 ) == V_186 -> V_106 ) ;
V_71 = F_64 ( V_2 , V_35 , V_4 , 0 , V_187 + 1 , NULL ) ;
if ( V_71 != 0 )
return V_71 ;
if ( V_186 -> V_191 ) {
F_3 ( V_166 -> V_177 != NULL ) ;
F_85 ( V_166 -> V_177 ) ;
} else {
V_71 = F_80 ( V_166 ) ;
if ( V_71 != 0 )
return V_71 ;
}
V_188 = V_166 -> V_177 ;
F_3 ( F_89 ( V_188 ) ) ;
if ( F_90 ( V_192 ) )
F_91 ( V_188 ) ;
V_123 = F_66 ( V_12 ) ;
if ( F_84 ( ( V_188 -> V_173 != V_12 -> V_193 ) ||
( F_92 ( V_188 ) > V_123 ) ) ) {
F_16 ( V_172 , L_15 ) ;
V_71 = + 1 ;
goto V_146;
}
if ( V_186 -> V_191 ) {
T_7 V_194 ;
V_194 = F_32 ( V_35 , V_123 - 1 ) ;
if ( V_194 < V_186 -> V_106 ) {
F_16 ( V_172 ,
L_16
L_17 ,
V_188 -> V_173 , V_186 -> V_106 , V_194 ) ;
V_71 = - V_195 ;
goto V_146;
}
}
V_48 = F_93 ( V_2 , V_35 , V_186 -> V_106 , V_188 , V_196 ) ;
if ( F_94 ( V_48 ) ) {
V_71 = F_95 ( V_48 ) ;
goto V_146;
}
if ( V_186 -> V_191 ) {
F_96 ( V_188 ) ;
if ( F_97 ( V_188 ) ) {
struct V_197 * V_198 ;
F_98 ( V_2 , V_4 , V_48 ) ;
V_198 = F_99 ( F_100 ( V_48 , & V_199 ) ) ;
F_101 ( F_102 ( V_35 ) , V_198 ) ;
V_71 = F_103 ( V_2 , V_4 , V_48 , V_200 ) ;
F_3 ( F_104 ( V_48 , V_4 ) ) ;
V_188 = NULL ;
if ( V_71 < 0 ) {
F_105 ( V_2 , V_4 , V_48 ) ;
F_106 ( V_2 , V_4 , V_48 ) ;
F_107 ( V_2 , V_4 , V_48 ) ;
F_23 ( V_2 , V_48 ) ;
if ( V_71 == - V_201 )
V_71 = - V_202 ;
goto V_146;
} else
F_107 ( V_2 , V_4 , V_48 ) ;
}
}
V_189 = F_32 ( V_35 , V_123 - 1 ) ;
F_3 ( ! V_186 -> V_191 || V_186 -> V_106 <= V_189 ) ;
if ( V_186 -> V_106 == V_189 )
V_186 -> V_203 = V_123 - F_88 ( V_35 , V_186 -> V_106 ) ;
else
V_186 -> V_203 = F_108 ( V_35 ) ;
F_109 ( & V_48 -> V_51 , L_3 , V_4 ) ;
V_186 -> V_50 = V_48 ;
V_146:
if ( V_188 != NULL )
F_110 ( V_188 ) ;
V_166 -> V_30 . V_170 &= ~ V_176 ;
return V_71 ;
}
static int F_111 ( const struct V_1 * V_2 ,
const struct V_22 * V_23 )
{
return 0 ;
}
static int F_112 ( const struct V_1 * V_2 ,
const struct V_22 * V_23 ,
const struct V_204 * V_205 )
{
struct V_3 * V_4 = V_23 -> V_33 ;
struct V_34 * V_35 = V_205 -> V_206 ;
struct V_197 * V_198 = F_99 ( V_205 ) ;
struct V_47 * V_48 = V_205 -> V_207 ;
struct V_12 * V_12 = F_10 ( V_35 ) ;
struct V_208 * V_209 = F_74 ( V_12 ) ;
struct V_210 * V_211 = F_11 ( V_2 , V_23 ) -> V_25 ;
struct V_212 * V_213 = & V_211 -> V_214 ;
struct V_48 * V_188 = V_198 -> V_215 ;
struct V_216 * V_217 = & V_4 -> V_218 ;
int V_17 ;
F_14 ( V_2 , V_35 , F_15 ( V_35 ) ) ;
F_3 ( V_205 -> V_206 == V_35 ) ;
if ( V_209 -> V_219 . V_220 &&
V_209 -> V_219 . V_221 )
F_113 ( V_209 , V_12 , V_213 , V_48 -> V_222 ,
V_198 -> V_223 ) ;
V_17 = F_114 ( V_2 , V_4 , V_48 ) ;
if ( V_17 != - V_224 ) {
F_115 ( V_225 , V_2 , V_48 , L_18 ,
V_17 == - V_195 ? L_19 :
L_20 , V_17 ) ;
if ( V_17 != - V_195 )
return V_17 ;
}
if ( V_198 -> V_223 ) {
V_198 -> V_226 = 1 ;
F_116 ( V_2 , V_48 , 1 ) ;
}
F_117 ( V_217 , V_48 ) ;
if ( V_209 -> V_219 . V_220 &&
V_209 -> V_219 . V_221 )
F_118 ( V_2 , V_4 , V_213 ,
V_188 -> V_173 , & V_217 -> V_227 , V_211 -> V_228 ) ;
return 0 ;
}
static int F_119 ( const struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_47 * V_48 , struct V_197 * V_198 ,
enum V_229 V_230 )
{
struct V_216 * V_217 ;
int V_71 ;
F_3 ( V_4 -> V_7 == V_8 || V_4 -> V_7 == V_9 ) ;
V_217 = & V_4 -> V_218 ;
F_120 ( V_217 , V_48 ) ;
V_71 = F_121 ( V_2 , V_4 , V_230 , V_217 , 0 ) ;
F_3 ( F_104 ( V_48 , V_4 ) ) ;
if ( V_230 == V_231 )
F_122 ( V_2 , V_4 , & V_217 -> V_227 ) ;
F_123 ( V_2 , V_217 ) ;
return V_71 ;
}
static int F_124 ( const struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_34 * V_35 , struct V_47 * V_232 ,
struct V_197 * V_198 ,
unsigned V_233 , unsigned V_234 )
{
struct V_124 * V_125 = F_53 ( V_2 ) ;
T_4 V_187 = F_88 ( V_35 , V_232 -> V_222 ) ;
int V_71 ;
F_54 ( V_35 ) ;
V_71 = F_125 ( V_2 , V_35 , V_125 ) ;
F_56 ( V_35 ) ;
if ( V_71 == 0 ) {
if ( V_125 -> V_235 <= V_187 ) {
char * V_236 = F_126 ( V_198 -> V_215 ) ;
memset ( V_236 , 0 , F_108 ( V_35 ) ) ;
F_127 ( V_236 ) ;
} else if ( V_198 -> V_223 )
V_198 -> V_226 = 1 ;
else
V_71 = F_119 ( V_2 , V_4 , V_232 , V_198 , V_231 ) ;
if ( V_71 == 0 )
F_116 ( V_2 , V_232 , 1 ) ;
}
return V_71 ;
}
static int F_128 ( const struct V_1 * V_2 ,
const struct V_22 * V_23 ,
const struct V_204 * V_205 ,
unsigned V_233 , unsigned V_234 )
{
struct V_34 * V_35 = V_205 -> V_206 ;
struct V_197 * V_198 = F_99 ( V_205 ) ;
struct V_47 * V_232 = V_205 -> V_207 ;
struct V_48 * V_188 = V_198 -> V_215 ;
int V_71 ;
F_129 ( F_130 ( V_2 , V_232 ) ) ;
F_3 ( V_188 -> V_173 -> V_237 == F_10 ( V_35 ) ) ;
V_71 = 0 ;
F_115 ( V_172 , V_2 , V_232 , L_21 , V_233 , V_234 ) ;
if ( ! F_131 ( V_188 ) ) {
if ( V_233 == 0 && V_234 == V_154 ) {
F_115 ( V_172 , V_2 , V_232 , L_22 ) ;
F_132 ( V_48 , 0x11 ) ;
} else
V_71 = F_124 ( V_2 , V_23 -> V_33 , V_35 ,
V_232 , V_198 , V_233 , V_234 ) ;
} else
F_115 ( V_172 , V_2 , V_232 , L_23 ) ;
return V_71 ;
}
static int F_133 ( const struct V_1 * V_2 ,
const struct V_22 * V_23 ,
const struct V_204 * V_205 ,
unsigned V_233 , unsigned V_234 )
{
struct V_34 * V_35 = V_205 -> V_206 ;
struct V_3 * V_4 = V_23 -> V_33 ;
struct V_197 * V_198 = F_99 ( V_205 ) ;
struct V_47 * V_232 = V_205 -> V_207 ;
struct V_12 * V_12 = F_10 ( V_35 ) ;
struct V_208 * V_209 = F_74 ( V_12 ) ;
struct V_13 * V_14 = F_5 ( V_12 ) ;
struct V_48 * V_188 = V_198 -> V_215 ;
int V_71 ;
int V_238 ;
T_4 V_123 ;
F_129 ( F_130 ( V_2 , V_232 ) ) ;
F_3 ( V_188 -> V_173 -> V_237 == V_12 ) ;
F_65 ( V_147 , V_2 , & V_35 -> V_39 , L_24 ) ;
F_115 ( V_172 , V_2 , V_232 , L_25 , V_233 , V_234 ) ;
if ( ! F_134 ( V_188 ) ) {
V_238 = V_239 ;
V_71 = F_103 ( V_2 , V_4 , V_232 , V_200 ) ;
if ( V_71 == 0 ) {
F_97 ( V_188 ) ;
F_101 ( F_102 ( V_35 ) , V_198 ) ;
} else if ( V_71 == - V_201 ) {
T_7 V_194 = F_66 ( V_12 ) >> V_240 ;
bool V_241 = true ;
if ( V_194 > V_232 -> V_222 ) {
V_234 = V_154 ;
V_241 = false ;
} else if ( V_194 == V_232 -> V_222 ) {
int V_242 = F_66 ( V_12 ) & ~ V_79 ;
if ( V_234 < V_242 )
V_234 = V_242 ;
}
if ( V_241 )
F_135 ( V_2 , V_232 , 0 , V_234 ) ;
V_71 = F_119 ( V_2 , V_4 , V_232 , V_198 , V_200 ) ;
if ( V_71 )
F_71 ( L_26 ,
V_232 -> V_222 , V_12 , V_71 ) ;
}
} else {
V_238 = V_243 ;
V_71 = 0 ;
}
F_136 ( V_209 , V_238 , 1 ) ;
if ( V_71 == 0 ) {
F_137 ( & V_14 -> V_244 ) ;
V_14 -> V_45 |= V_245 ;
F_138 ( & V_14 -> V_244 ) ;
}
V_123 = F_88 ( V_35 , V_232 -> V_222 ) + V_234 ;
F_46 ( V_12 ) ;
if ( V_71 == 0 ) {
if ( V_123 > F_66 ( V_12 ) ) {
F_139 ( V_12 , V_123 ) ;
F_16 ( V_37 , V_38 L_27 ,
F_17 ( F_18 ( & V_35 -> V_39 ) ) ,
( unsigned long ) V_123 ) ;
}
F_116 ( V_2 , V_232 , 1 ) ;
} else {
if ( V_123 > F_66 ( V_12 ) )
F_106 ( V_2 , V_4 , V_232 ) ;
}
F_48 ( V_12 ) ;
return V_71 ;
}
int F_140 ( const struct V_1 * V_2 , struct V_34 * V_35 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_15 * V_16 = F_6 ( V_2 ) ;
struct V_12 * V_12 = F_10 ( V_35 ) ;
int V_71 ;
F_14 ( V_2 , V_35 , F_15 ( V_35 ) ) ;
F_16 ( V_37 , V_38
L_1 ,
F_17 ( F_18 ( & V_35 -> V_39 ) ) ,
V_4 -> V_40 , V_4 -> V_41 ,
V_16 -> V_18 , V_4 -> V_42 ) ;
F_141 ( V_16 , V_246 ) ;
F_142 ( V_4 , & V_16 -> V_246 , V_35 , & V_247 ) ;
V_6 -> V_151 = 0 ;
V_71 = 0 ;
if ( V_4 -> V_7 == V_8 || V_4 -> V_7 == V_9 ) {
T_6 V_70 ;
struct V_13 * V_14 = F_5 ( V_12 ) ;
V_70 = V_4 -> V_29 . V_97 . V_104 ;
if ( V_70 == 0 )
V_71 = 1 ;
else
V_16 -> V_144 = V_70 ;
F_143 ( V_14 -> V_248 ) ;
} else if ( V_4 -> V_7 == V_249 ) {
if ( ! F_44 ( V_4 ) )
V_4 -> V_250 = V_251 ;
}
if ( V_4 -> V_7 == V_252 && ! V_4 -> V_41 )
V_4 -> V_40 = 1 ;
if ( V_71 == 0 && ! V_4 -> V_40 ) {
V_71 = F_20 ( V_12 , & V_16 -> V_18 ) ;
if ( V_71 == - V_253 )
V_71 = 0 ;
if ( V_71 < 0 )
F_71 ( L_28 V_38 L_29 ,
F_144 ( V_12 -> V_254 , NULL , 0 ) ,
F_17 ( F_18 ( & V_35 -> V_39 ) ) , V_71 ) ;
}
return V_71 ;
}
static struct V_5 * F_9 ( const struct V_1 * V_2 ,
const struct V_22 * V_205 )
{
F_11 ( V_2 , V_205 ) ;
return F_2 ( V_2 ) ;
}
