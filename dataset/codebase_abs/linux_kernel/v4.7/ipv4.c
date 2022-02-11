int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 , int V_5 )
{
const struct V_6 * V_7 = (struct V_6 * ) V_4 ;
struct V_8 * V_9 = F_2 ( V_2 ) ;
struct V_10 * V_11 = F_3 ( V_2 ) ;
T_1 V_12 , V_13 ;
T_2 V_14 , V_15 ;
struct V_16 * V_17 ;
struct V_18 * V_19 ;
int V_20 ;
struct V_21 * V_22 ;
V_11 -> V_23 = V_24 ;
if ( V_5 < sizeof( struct V_6 ) )
return - V_25 ;
if ( V_7 -> V_26 != V_27 )
return - V_28 ;
V_15 = V_14 = V_7 -> V_29 . V_30 ;
V_22 = F_4 ( V_9 -> V_22 ,
F_5 ( V_2 ) ) ;
if ( V_22 != NULL && V_22 -> V_31 . V_32 ) {
if ( V_14 == 0 )
return - V_25 ;
V_15 = V_22 -> V_31 . V_33 ;
}
V_12 = V_9 -> V_34 ;
V_13 = V_7 -> V_35 ;
V_17 = & V_9 -> V_36 . V_37 . V_38 . V_39 ;
V_19 = F_6 ( V_17 , V_15 , V_9 -> V_40 ,
F_7 ( V_2 ) , V_2 -> V_41 ,
V_42 ,
V_12 , V_13 , V_2 ) ;
if ( F_8 ( V_19 ) )
return F_9 ( V_19 ) ;
if ( V_19 -> V_43 & ( V_44 | V_45 ) ) {
F_10 ( V_19 ) ;
return - V_46 ;
}
if ( V_22 == NULL || ! V_22 -> V_31 . V_32 )
V_14 = V_17 -> V_14 ;
if ( V_9 -> V_40 == 0 )
V_9 -> V_40 = V_17 -> V_47 ;
F_11 ( V_2 , V_9 -> V_40 ) ;
V_9 -> V_48 = V_7 -> V_35 ;
F_12 ( V_2 , V_14 ) ;
F_13 ( V_2 ) -> V_49 = 0 ;
if ( V_22 )
F_13 ( V_2 ) -> V_49 = V_22 -> V_31 . V_50 ;
F_14 ( V_2 , V_51 ) ;
V_20 = F_15 ( & V_52 , V_2 ) ;
if ( V_20 != 0 )
goto V_53;
V_19 = F_16 ( V_17 , V_19 , V_12 , V_13 ,
V_9 -> V_34 , V_9 -> V_48 , V_2 ) ;
if ( F_8 ( V_19 ) ) {
V_20 = F_9 ( V_19 ) ;
V_19 = NULL ;
goto V_53;
}
F_17 ( V_2 , & V_19 -> V_54 ) ;
V_11 -> V_55 = F_18 ( V_9 -> V_40 ,
V_9 -> V_56 ,
V_9 -> V_34 ,
V_9 -> V_48 ) ;
V_9 -> V_57 = V_11 -> V_55 ^ V_58 ;
V_20 = F_19 ( V_2 ) ;
V_19 = NULL ;
if ( V_20 != 0 )
goto V_53;
V_59:
return V_20 ;
V_53:
F_14 ( V_2 , V_60 ) ;
F_10 ( V_19 ) ;
V_2 -> V_61 = 0 ;
V_9 -> V_48 = 0 ;
goto V_59;
}
static inline void F_20 ( struct V_1 * V_2 ,
const struct V_62 * V_63 ,
T_3 V_64 )
{
struct V_65 * V_54 ;
const struct V_8 * V_9 = F_2 ( V_2 ) ;
const struct V_10 * V_11 = F_3 ( V_2 ) ;
if ( V_2 -> V_66 == V_67 )
return;
V_54 = F_21 ( V_2 , V_64 ) ;
if ( ! V_54 )
return;
if ( V_64 < F_22 ( V_54 ) && F_23 ( V_2 , V_54 ) )
V_2 -> V_68 = V_69 ;
V_64 = F_22 ( V_54 ) ;
if ( V_9 -> V_70 != V_71 &&
F_24 ( V_2 ) &&
F_13 ( V_2 ) -> V_72 > V_64 ) {
F_25 ( V_2 , V_64 ) ;
F_26 ( V_2 , V_11 -> V_73 , V_74 ) ;
}
}
static void F_27 ( struct V_75 * V_76 , struct V_1 * V_2 )
{
struct V_65 * V_54 = F_28 ( V_2 , 0 ) ;
if ( V_54 )
V_54 -> V_77 -> V_78 ( V_54 , V_2 , V_76 ) ;
}
void F_29 ( struct V_1 * V_2 , T_4 V_79 )
{
struct V_80 * V_81 = F_30 ( V_2 ) ;
struct V_82 * V_82 = F_31 ( V_2 ) ;
if ( ! F_32 ( V_79 , F_33 ( V_81 ) -> V_83 , F_33 ( V_81 ) -> V_84 ) ) {
F_34 ( V_82 , V_85 ) ;
} else {
F_35 ( V_81 -> V_86 , V_81 ) ;
}
F_36 ( V_81 ) ;
}
static void F_37 ( struct V_75 * V_76 , T_3 V_87 )
{
const struct V_62 * V_63 = (struct V_62 * ) V_76 -> V_88 ;
const T_5 V_89 = V_63 -> V_90 << 2 ;
const struct V_91 * V_92 = (struct V_91 * ) ( V_76 -> V_88 + V_89 ) ;
struct V_10 * V_11 ;
struct V_8 * V_9 ;
const int type = F_38 ( V_76 ) -> type ;
const int V_93 = F_38 ( V_76 ) -> V_93 ;
struct V_1 * V_2 ;
T_6 V_79 ;
int V_20 ;
struct V_82 * V_82 = F_39 ( V_76 -> V_94 ) ;
if ( V_76 -> V_95 < V_89 + sizeof( * V_92 ) ||
V_76 -> V_95 < V_89 + F_40 ( V_92 ) ) {
F_41 ( V_82 , V_96 ) ;
return;
}
V_2 = F_42 ( V_82 , & V_97 ,
V_63 -> V_14 , V_92 -> V_98 ,
V_63 -> V_47 , F_43 ( V_92 -> V_99 ) ,
F_44 ( V_76 ) ) ;
if ( ! V_2 ) {
F_41 ( V_82 , V_96 ) ;
return;
}
if ( V_2 -> V_66 == V_100 ) {
F_45 ( F_46 ( V_2 ) ) ;
return;
}
V_79 = F_47 ( V_92 ) ;
if ( V_2 -> V_66 == V_101 )
return F_29 ( V_2 , V_79 ) ;
F_48 ( V_2 ) ;
if ( F_49 ( V_2 ) )
F_34 ( V_82 , V_102 ) ;
if ( V_2 -> V_66 == V_60 )
goto V_59;
V_11 = F_3 ( V_2 ) ;
if ( ( 1 << V_2 -> V_66 ) & ~ ( V_103 | V_104 ) &&
! F_32 ( V_79 , V_11 -> V_105 , V_11 -> V_106 ) ) {
F_34 ( V_82 , V_85 ) ;
goto V_59;
}
switch ( type ) {
case V_107 :
F_27 ( V_76 , V_2 ) ;
goto V_59;
case V_108 :
goto V_59;
case V_109 :
V_20 = V_110 ;
break;
case V_111 :
if ( V_93 > V_112 )
goto V_59;
if ( V_93 == V_113 ) {
if ( ! F_49 ( V_2 ) )
F_20 ( V_2 , V_63 , V_87 ) ;
goto V_59;
}
V_20 = V_114 [ V_93 ] . V_115 ;
break;
case V_116 :
V_20 = V_117 ;
break;
default:
goto V_59;
}
switch ( V_2 -> V_66 ) {
case V_51 :
case V_118 :
if ( ! F_49 ( V_2 ) ) {
F_50 ( V_119 ) ;
V_2 -> V_120 = V_20 ;
V_2 -> V_121 ( V_2 ) ;
F_51 ( V_2 ) ;
} else
V_2 -> V_68 = V_20 ;
goto V_59;
}
V_9 = F_2 ( V_2 ) ;
if ( ! F_49 ( V_2 ) && V_9 -> V_122 ) {
V_2 -> V_120 = V_20 ;
V_2 -> V_121 ( V_2 ) ;
} else
V_2 -> V_68 = V_20 ;
V_59:
F_52 ( V_2 ) ;
F_53 ( V_2 ) ;
}
static inline T_7 F_54 ( struct V_75 * V_76 ,
T_2 V_123 , T_2 V_54 )
{
return F_55 ( V_123 , V_54 , V_76 -> V_95 , V_42 , V_76 -> V_124 ) ;
}
void F_56 ( struct V_1 * V_2 , struct V_75 * V_76 )
{
const struct V_8 * V_9 = F_2 ( V_2 ) ;
struct V_91 * V_92 = V_91 ( V_76 ) ;
F_57 ( V_76 ) ;
V_92 -> V_125 = F_54 ( V_76 ,
V_9 -> V_40 ,
V_9 -> V_56 ) ;
}
static inline T_4 F_58 ( const struct V_75 * V_76 )
{
return F_18 ( F_59 ( V_76 ) -> V_14 ,
F_59 ( V_76 ) -> V_47 ,
V_91 ( V_76 ) -> V_98 ,
V_91 ( V_76 ) -> V_99 ) ;
}
struct V_1 * F_60 ( const struct V_1 * V_2 ,
struct V_75 * V_76 ,
struct V_80 * V_81 ,
struct V_65 * V_54 ,
struct V_80 * V_126 ,
bool * V_127 )
{
struct V_128 * V_129 ;
struct V_8 * V_130 ;
struct V_1 * V_131 ;
if ( F_61 ( V_2 ) )
goto V_132;
V_131 = F_62 ( V_2 , V_81 , V_76 ) ;
if ( V_131 == NULL )
goto V_133;
V_130 = F_2 ( V_131 ) ;
V_129 = F_63 ( V_81 ) ;
F_12 ( V_131 , V_129 -> V_134 ) ;
F_11 ( V_131 , V_129 -> V_135 ) ;
V_130 -> V_40 = V_129 -> V_135 ;
V_130 -> V_22 = V_129 -> V_31 ;
V_129 -> V_31 = NULL ;
V_130 -> V_136 = F_44 ( V_76 ) ;
V_130 -> V_137 = F_59 ( V_76 ) -> V_138 ;
V_130 -> V_57 = V_58 ;
if ( V_54 == NULL && ( V_54 = F_64 ( V_2 , V_131 , V_81 ) ) == NULL )
goto V_139;
F_17 ( V_131 , V_54 ) ;
F_25 ( V_131 , F_22 ( V_54 ) ) ;
if ( F_65 ( V_2 , V_131 ) < 0 )
goto V_139;
* V_127 = F_66 ( V_131 , F_67 ( V_126 ) ) ;
return V_131 ;
V_132:
F_34 ( F_31 ( V_2 ) , V_140 ) ;
V_133:
F_68 ( V_54 ) ;
exit:
F_34 ( F_31 ( V_2 ) , V_141 ) ;
return NULL ;
V_139:
F_69 ( V_131 ) ;
F_51 ( V_131 ) ;
goto exit;
}
static struct V_65 * F_70 ( struct V_82 * V_82 , struct V_1 * V_2 ,
struct V_75 * V_76 )
{
struct V_18 * V_19 ;
const struct V_62 * V_63 = F_59 ( V_76 ) ;
struct V_16 V_17 = {
. V_142 = F_44 ( V_76 ) ,
. V_14 = V_63 -> V_47 ,
. V_47 = V_63 -> V_14 ,
. V_143 = F_7 ( V_2 ) ,
. V_144 = V_2 -> V_145 ,
. V_146 = V_91 ( V_76 ) -> V_98 ,
. V_147 = V_91 ( V_76 ) -> V_99 ,
} ;
F_71 ( V_76 , F_72 ( & V_17 ) ) ;
V_19 = F_73 ( V_82 , & V_17 , V_2 ) ;
if ( F_8 ( V_19 ) ) {
F_74 ( V_82 , V_148 ) ;
return NULL ;
}
return & V_19 -> V_54 ;
}
static int F_75 ( const struct V_1 * V_2 , struct V_80 * V_81 )
{
int V_20 = - 1 ;
struct V_75 * V_76 ;
struct V_65 * V_54 ;
struct V_16 V_17 ;
V_54 = F_76 ( V_2 , & V_17 , V_81 ) ;
if ( V_54 == NULL )
goto V_59;
V_76 = F_77 ( V_2 , V_54 , V_81 ) ;
if ( V_76 != NULL ) {
const struct V_128 * V_129 = F_63 ( V_81 ) ;
struct V_91 * V_92 = V_91 ( V_76 ) ;
V_92 -> V_125 = F_54 ( V_76 , V_129 -> V_135 ,
V_129 -> V_134 ) ;
V_20 = F_78 ( V_76 , V_2 , V_129 -> V_135 ,
V_129 -> V_134 ,
V_129 -> V_31 ) ;
V_20 = F_79 ( V_20 ) ;
}
V_59:
F_68 ( V_54 ) ;
return V_20 ;
}
static void F_80 ( const struct V_1 * V_2 , struct V_75 * V_149 )
{
int V_20 ;
const struct V_62 * V_150 ;
struct V_75 * V_76 ;
struct V_65 * V_54 ;
struct V_82 * V_82 = F_39 ( F_81 ( V_149 ) -> V_94 ) ;
struct V_1 * V_151 = V_82 -> V_152 . V_153 ;
if ( V_91 ( V_149 ) -> V_154 == V_155 )
return;
if ( F_82 ( V_149 ) -> V_156 != V_157 )
return;
V_54 = F_70 ( V_82 , V_151 , V_149 ) ;
if ( V_54 == NULL )
return;
V_76 = F_83 ( V_151 , V_149 ) ;
if ( V_76 == NULL )
goto V_59;
V_150 = F_59 ( V_149 ) ;
V_91 ( V_76 ) -> V_125 = F_54 ( V_76 , V_150 -> V_47 ,
V_150 -> V_14 ) ;
F_84 ( V_76 , F_85 ( V_54 ) ) ;
F_86 () ;
F_48 ( V_151 ) ;
V_20 = F_78 ( V_76 , V_151 ,
V_150 -> V_14 , V_150 -> V_47 , NULL ) ;
F_52 ( V_151 ) ;
if ( F_79 ( V_20 ) == 0 ) {
F_50 ( V_158 ) ;
F_50 ( V_159 ) ;
}
F_87 () ;
V_59:
F_68 ( V_54 ) ;
}
static void F_88 ( struct V_80 * V_81 )
{
F_89 ( & F_33 ( V_81 ) -> V_160 ) ;
F_90 ( F_63 ( V_81 ) -> V_31 ) ;
}
void F_91 ( const struct V_80 * V_81 )
{
}
int F_92 ( struct V_1 * V_2 , struct V_75 * V_76 )
{
struct V_128 * V_129 ;
struct V_80 * V_81 ;
struct V_161 * V_162 ;
const T_2 V_163 = F_93 ( V_76 ) -> V_164 ;
struct V_165 * V_166 = F_94 ( V_76 ) ;
if ( F_82 ( V_76 ) -> V_43 & ( V_45 | V_44 ) )
return 0 ;
if ( F_95 ( V_2 , V_163 ) ) {
V_166 -> V_167 = V_168 ;
goto V_169;
}
V_166 -> V_167 = V_170 ;
if ( F_96 ( V_2 ) )
goto V_169;
if ( F_61 ( V_2 ) && F_97 ( V_2 ) > 1 )
goto V_169;
V_81 = F_98 ( & V_171 , V_2 , true ) ;
if ( V_81 == NULL )
goto V_169;
if ( F_99 ( V_81 , F_3 ( V_2 ) , V_76 ) )
goto V_172;
V_162 = F_33 ( V_81 ) ;
if ( F_100 ( V_2 , V_162 , V_76 ) )
goto V_172;
if ( F_101 ( V_2 , V_76 , V_81 ) )
goto V_172;
V_129 = F_63 ( V_81 ) ;
F_11 ( F_67 ( V_81 ) , F_59 ( V_76 ) -> V_14 ) ;
F_12 ( F_67 ( V_81 ) , F_59 ( V_76 ) -> V_47 ) ;
V_129 -> V_173 = V_27 ;
V_129 -> V_174 = V_2 -> V_41 ;
V_162 -> V_175 = V_166 -> V_176 ;
V_162 -> V_177 = V_162 -> V_175 ;
V_162 -> V_83 = F_58 ( V_76 ) ;
V_162 -> V_84 = V_162 -> V_83 ;
V_162 -> V_178 = V_163 ;
if ( F_75 ( V_2 , V_81 ) )
goto V_172;
F_102 ( V_2 , V_81 , V_179 ) ;
return 0 ;
V_172:
F_103 ( V_81 ) ;
V_169:
F_50 ( V_119 ) ;
return - 1 ;
}
int F_104 ( struct V_1 * V_2 , struct V_75 * V_76 )
{
struct V_91 * V_92 = V_91 ( V_76 ) ;
if ( V_2 -> V_66 == V_180 ) {
if ( F_105 ( V_2 , V_76 , V_92 , V_76 -> V_95 ) )
goto V_181;
return 0 ;
}
if ( F_106 ( V_2 , V_76 , V_92 , V_76 -> V_95 ) )
goto V_181;
return 0 ;
V_181:
F_80 ( V_2 , V_76 ) ;
F_107 ( V_76 ) ;
return 0 ;
}
int F_108 ( struct V_75 * V_76 )
{
const struct V_91 * V_92 ;
unsigned int V_182 ;
if ( V_76 -> V_183 != V_184 )
return 1 ;
if ( ! F_109 ( V_76 , sizeof( struct V_91 ) ) ) {
F_110 ( L_1 ) ;
return 1 ;
}
V_92 = V_91 ( V_76 ) ;
if ( V_92 -> V_154 >= V_185 ) {
F_110 ( L_2 ) ;
return 1 ;
}
if ( V_92 -> V_186 < F_111 ( V_76 ) / sizeof( T_3 ) ) {
F_110 ( L_3 , V_92 -> V_186 ) ;
return 1 ;
}
if ( ! F_109 ( V_76 , V_92 -> V_186 * sizeof( T_3 ) ) ) {
F_110 ( L_4 , V_92 -> V_186 ) ;
return 1 ;
}
if ( ( V_92 -> V_154 < V_187 ||
V_92 -> V_154 > V_188 ) && V_92 -> V_189 == 0 ) {
F_110 ( L_5 ,
F_112 ( V_92 -> V_154 ) ) ;
return 1 ;
}
V_182 = F_113 ( V_76 ) ;
if ( V_182 > V_76 -> V_95 ) {
F_110 ( L_6 ,
V_92 -> V_190 , V_76 -> V_95 ) ;
return 1 ;
}
V_76 -> V_124 = F_114 ( V_76 , 0 , V_182 , 0 ) ;
return 0 ;
}
static int F_115 ( struct V_75 * V_76 )
{
const struct V_91 * V_92 ;
const struct V_62 * V_63 ;
bool V_191 ;
struct V_1 * V_2 ;
int V_192 ;
if ( F_108 ( V_76 ) )
goto V_193;
V_63 = F_59 ( V_76 ) ;
if ( F_54 ( V_76 , V_63 -> V_47 , V_63 -> V_14 ) ) {
F_110 ( L_7 ) ;
goto V_193;
}
V_92 = V_91 ( V_76 ) ;
F_94 ( V_76 ) -> V_176 = F_47 ( V_92 ) ;
F_94 ( V_76 ) -> V_194 = V_92 -> V_154 ;
F_116 ( L_8 ,
F_112 ( V_92 -> V_154 ) ,
& V_63 -> V_47 , F_43 ( V_92 -> V_99 ) ,
& V_63 -> V_14 , F_43 ( V_92 -> V_98 ) ,
( unsigned long long ) F_94 ( V_76 ) -> V_176 ) ;
if ( F_117 ( V_76 ) ) {
F_94 ( V_76 ) -> V_195 = V_196 ;
F_118 ( L_9 ) ;
} else {
F_94 ( V_76 ) -> V_195 = F_119 ( V_76 ) ;
F_118 ( L_10 , ( unsigned long long )
F_94 ( V_76 ) -> V_195 ) ;
}
V_197:
V_2 = F_120 ( & V_97 , V_76 , F_121 ( V_92 ) ,
V_92 -> V_99 , V_92 -> V_98 , & V_191 ) ;
if ( ! V_2 ) {
F_116 ( L_11
L_12 ) ;
goto V_198;
}
if ( V_2 -> V_66 == V_100 ) {
F_116 ( L_13 ) ;
F_45 ( F_46 ( V_2 ) ) ;
goto V_198;
}
if ( V_2 -> V_66 == V_101 ) {
struct V_80 * V_81 = F_30 ( V_2 ) ;
struct V_1 * V_199 ;
V_2 = V_81 -> V_86 ;
if ( F_122 ( V_2 -> V_66 != V_67 ) ) {
F_123 ( V_2 , V_81 ) ;
goto V_197;
}
F_124 ( V_2 ) ;
V_191 = true ;
V_199 = F_125 ( V_2 , V_76 , V_81 ) ;
if ( ! V_199 ) {
F_36 ( V_81 ) ;
goto V_200;
}
if ( V_199 == V_2 ) {
F_36 ( V_81 ) ;
} else if ( F_126 ( V_2 , V_199 , V_76 ) ) {
F_80 ( V_2 , V_76 ) ;
goto V_200;
} else {
F_53 ( V_2 ) ;
return 0 ;
}
}
V_192 = F_3 ( V_2 ) -> V_201 ;
if ( V_92 -> V_190 && ( V_192 == 0 || V_92 -> V_190 < V_192 ) ) {
F_116 ( L_14 ,
V_92 -> V_190 , V_192 ) ;
goto V_200;
}
if ( ! F_127 ( V_2 , V_202 , V_76 ) )
goto V_200;
F_128 ( V_76 ) ;
return F_129 ( V_2 , V_76 , 1 , V_92 -> V_186 * 4 ) ;
V_198:
if ( ! F_127 ( NULL , V_202 , V_76 ) )
goto V_193;
if ( V_92 -> V_154 != V_155 ) {
F_94 ( V_76 ) -> V_167 =
V_203 ;
F_80 ( V_2 , V_76 ) ;
}
V_193:
F_107 ( V_76 ) ;
return 0 ;
V_200:
if ( V_191 )
F_53 ( V_2 ) ;
goto V_193;
}
static int F_130 ( struct V_1 * V_2 )
{
static T_8 V_204 ;
int V_20 = F_131 ( V_2 , V_204 ) ;
if ( V_20 == 0 ) {
if ( F_122 ( ! V_204 ) )
V_204 = 1 ;
F_13 ( V_2 ) -> V_205 = & V_206 ;
}
return V_20 ;
}
static int T_9 F_132 ( struct V_82 * V_82 )
{
if ( V_97 . V_207 == NULL )
return - V_208 ;
return F_133 ( & V_82 -> V_152 . V_153 , V_209 ,
V_210 , V_42 , V_82 ) ;
}
static void T_10 F_134 ( struct V_82 * V_82 )
{
F_135 ( V_82 -> V_152 . V_153 ) ;
}
static int T_11 F_136 ( void )
{
int V_20 = F_137 ( & V_211 , 1 ) ;
if ( V_20 != 0 )
goto V_59;
V_20 = F_138 ( & V_212 , V_42 ) ;
if ( V_20 != 0 )
goto V_213;
F_139 ( & V_214 ) ;
V_20 = F_140 ( & V_215 ) ;
if ( V_20 )
goto V_216;
V_59:
return V_20 ;
V_216:
F_141 ( & V_214 ) ;
F_142 ( & V_212 , V_42 ) ;
V_213:
F_143 ( & V_211 ) ;
goto V_59;
}
static void T_12 F_144 ( void )
{
F_145 ( & V_215 ) ;
F_141 ( & V_214 ) ;
F_142 ( & V_212 , V_42 ) ;
F_143 ( & V_211 ) ;
}
