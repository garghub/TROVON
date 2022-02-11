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
V_12 , V_13 , V_2 , true ) ;
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
V_9 -> V_48 = V_9 -> V_40 ;
V_9 -> V_49 = V_7 -> V_35 ;
V_9 -> V_50 = V_14 ;
F_11 ( V_2 ) -> V_51 = 0 ;
if ( V_22 )
F_11 ( V_2 ) -> V_51 = V_22 -> V_31 . V_52 ;
F_12 ( V_2 , V_53 ) ;
V_20 = F_13 ( & V_54 , V_2 ) ;
if ( V_20 != 0 )
goto V_55;
V_19 = F_14 ( V_17 , V_19 , V_12 , V_13 ,
V_9 -> V_34 , V_9 -> V_49 , V_2 ) ;
if ( F_8 ( V_19 ) ) {
V_20 = F_9 ( V_19 ) ;
V_19 = NULL ;
goto V_55;
}
F_15 ( V_2 , & V_19 -> V_56 ) ;
V_11 -> V_57 = F_16 ( V_9 -> V_40 ,
V_9 -> V_50 ,
V_9 -> V_34 ,
V_9 -> V_49 ) ;
V_9 -> V_58 = V_11 -> V_57 ^ V_59 ;
V_20 = F_17 ( V_2 ) ;
V_19 = NULL ;
if ( V_20 != 0 )
goto V_55;
V_60:
return V_20 ;
V_55:
F_12 ( V_2 , V_61 ) ;
F_10 ( V_19 ) ;
V_2 -> V_62 = 0 ;
V_9 -> V_49 = 0 ;
goto V_60;
}
static inline void F_18 ( struct V_1 * V_2 ,
const struct V_63 * V_64 ,
T_3 V_65 )
{
struct V_66 * V_56 ;
const struct V_8 * V_9 = F_2 ( V_2 ) ;
const struct V_10 * V_11 = F_3 ( V_2 ) ;
if ( V_2 -> V_67 == V_68 )
return;
if ( ( V_56 = F_19 ( V_2 , 0 ) ) == NULL )
return;
V_56 -> V_69 -> V_70 ( V_56 , V_65 ) ;
if ( V_65 < F_20 ( V_56 ) && F_21 ( V_2 , V_56 ) )
V_2 -> V_71 = V_72 ;
V_65 = F_20 ( V_56 ) ;
if ( V_9 -> V_73 != V_74 &&
F_11 ( V_2 ) -> V_75 > V_65 ) {
F_22 ( V_2 , V_65 ) ;
F_23 ( V_2 , V_11 -> V_76 , V_77 ) ;
}
}
static void F_24 ( struct V_78 * V_79 , T_3 V_80 )
{
const struct V_63 * V_64 = (struct V_63 * ) V_79 -> V_81 ;
const T_4 V_82 = V_64 -> V_83 << 2 ;
const struct V_84 * V_85 = (struct V_84 * ) ( V_79 -> V_81 + V_82 ) ;
struct V_10 * V_11 ;
struct V_8 * V_9 ;
const int type = F_25 ( V_79 ) -> type ;
const int V_86 = F_25 ( V_79 ) -> V_86 ;
struct V_1 * V_2 ;
T_5 V_87 ;
int V_20 ;
struct V_88 * V_88 = F_26 ( V_79 -> V_89 ) ;
if ( V_79 -> V_90 < V_82 + sizeof( * V_85 ) ||
V_79 -> V_90 < V_82 + F_27 ( V_85 ) ) {
F_28 ( V_88 , V_91 ) ;
return;
}
V_2 = F_29 ( V_88 , & V_92 ,
V_64 -> V_14 , V_85 -> V_93 ,
V_64 -> V_47 , V_85 -> V_94 , F_30 ( V_79 ) ) ;
if ( V_2 == NULL ) {
F_28 ( V_88 , V_91 ) ;
return;
}
if ( V_2 -> V_67 == V_95 ) {
F_31 ( F_32 ( V_2 ) ) ;
return;
}
F_33 ( V_2 ) ;
if ( F_5 ( V_2 ) )
F_34 ( V_88 , V_96 ) ;
if ( V_2 -> V_67 == V_61 )
goto V_60;
V_11 = F_3 ( V_2 ) ;
V_87 = F_35 ( V_85 ) ;
if ( ( 1 << V_2 -> V_67 ) & ~ ( V_97 | V_98 ) &&
! F_36 ( V_87 , V_11 -> V_99 , V_11 -> V_100 ) ) {
F_34 ( V_88 , V_101 ) ;
goto V_60;
}
switch ( type ) {
case V_102 :
goto V_60;
case V_103 :
V_20 = V_104 ;
break;
case V_105 :
if ( V_86 > V_106 )
goto V_60;
if ( V_86 == V_107 ) {
if ( ! F_5 ( V_2 ) )
F_18 ( V_2 , V_64 , V_80 ) ;
goto V_60;
}
V_20 = V_108 [ V_86 ] . V_109 ;
break;
case V_110 :
V_20 = V_111 ;
break;
default:
goto V_60;
}
switch ( V_2 -> V_67 ) {
struct V_112 * V_113 , * * V_114 ;
case V_68 :
if ( F_5 ( V_2 ) )
goto V_60;
V_113 = F_37 ( V_2 , & V_114 , V_85 -> V_93 ,
V_64 -> V_14 , V_64 -> V_47 ) ;
if ( ! V_113 )
goto V_60;
F_38 ( V_113 -> V_2 ) ;
if ( V_87 != F_39 ( V_113 ) -> V_115 ) {
F_34 ( V_88 , V_101 ) ;
goto V_60;
}
F_40 ( V_2 , V_113 , V_114 ) ;
goto V_60;
case V_53 :
case V_116 :
if ( ! F_5 ( V_2 ) ) {
F_41 ( V_117 ) ;
V_2 -> V_118 = V_20 ;
V_2 -> V_119 ( V_2 ) ;
F_42 ( V_2 ) ;
} else
V_2 -> V_71 = V_20 ;
goto V_60;
}
V_9 = F_2 ( V_2 ) ;
if ( ! F_5 ( V_2 ) && V_9 -> V_120 ) {
V_2 -> V_118 = V_20 ;
V_2 -> V_119 ( V_2 ) ;
} else
V_2 -> V_71 = V_20 ;
V_60:
F_43 ( V_2 ) ;
F_44 ( V_2 ) ;
}
static inline T_6 F_45 ( struct V_78 * V_79 ,
T_2 V_121 , T_2 V_56 )
{
return F_46 ( V_121 , V_56 , V_79 -> V_90 , V_42 , V_79 -> V_122 ) ;
}
void F_47 ( struct V_1 * V_2 , struct V_78 * V_79 )
{
const struct V_8 * V_9 = F_2 ( V_2 ) ;
struct V_84 * V_85 = V_84 ( V_79 ) ;
F_48 ( V_79 ) ;
V_85 -> V_123 = F_45 ( V_79 ,
V_9 -> V_40 ,
V_9 -> V_50 ) ;
}
static inline T_7 F_49 ( const struct V_78 * V_79 )
{
return F_16 ( F_50 ( V_79 ) -> V_14 ,
F_50 ( V_79 ) -> V_47 ,
V_84 ( V_79 ) -> V_93 ,
V_84 ( V_79 ) -> V_94 ) ;
}
struct V_1 * F_51 ( struct V_1 * V_2 , struct V_78 * V_79 ,
struct V_112 * V_113 ,
struct V_66 * V_56 )
{
struct V_124 * V_125 ;
struct V_8 * V_126 ;
struct V_1 * V_127 ;
if ( F_52 ( V_2 ) )
goto V_128;
V_127 = F_53 ( V_2 , V_113 , V_79 ) ;
if ( V_127 == NULL )
goto V_129;
V_126 = F_2 ( V_127 ) ;
V_125 = F_54 ( V_113 ) ;
V_126 -> V_50 = V_125 -> V_130 ;
V_126 -> V_48 = V_125 -> V_131 ;
V_126 -> V_40 = V_125 -> V_131 ;
V_126 -> V_22 = V_125 -> V_31 ;
V_125 -> V_31 = NULL ;
V_126 -> V_132 = F_30 ( V_79 ) ;
V_126 -> V_133 = F_50 ( V_79 ) -> V_134 ;
V_126 -> V_58 = V_59 ;
if ( V_56 == NULL && ( V_56 = F_55 ( V_2 , V_127 , V_113 ) ) == NULL )
goto V_135;
F_15 ( V_127 , V_56 ) ;
F_22 ( V_127 , F_20 ( V_56 ) ) ;
if ( F_56 ( V_2 , V_127 ) < 0 )
goto V_135;
F_57 ( V_127 , NULL ) ;
return V_127 ;
V_128:
F_34 ( F_58 ( V_2 ) , V_136 ) ;
V_129:
F_59 ( V_56 ) ;
exit:
F_34 ( F_58 ( V_2 ) , V_137 ) ;
return NULL ;
V_135:
F_43 ( V_127 ) ;
F_44 ( V_127 ) ;
goto exit;
}
static struct V_1 * F_60 ( struct V_1 * V_2 , struct V_78 * V_79 )
{
const struct V_84 * V_85 = V_84 ( V_79 ) ;
const struct V_63 * V_64 = F_50 ( V_79 ) ;
struct V_1 * V_138 ;
struct V_112 * * V_114 ;
struct V_112 * V_113 = F_37 ( V_2 , & V_114 ,
V_85 -> V_94 ,
V_64 -> V_47 , V_64 -> V_14 ) ;
if ( V_113 != NULL )
return F_61 ( V_2 , V_79 , V_113 , V_114 ) ;
V_138 = F_62 ( F_58 ( V_2 ) , & V_92 ,
V_64 -> V_47 , V_85 -> V_94 ,
V_64 -> V_14 , V_85 -> V_93 ,
F_30 ( V_79 ) ) ;
if ( V_138 != NULL ) {
if ( V_138 -> V_67 != V_95 ) {
F_33 ( V_138 ) ;
return V_138 ;
}
F_31 ( F_32 ( V_138 ) ) ;
return NULL ;
}
return V_2 ;
}
static struct V_66 * F_63 ( struct V_88 * V_88 , struct V_1 * V_2 ,
struct V_78 * V_79 )
{
struct V_18 * V_19 ;
const struct V_63 * V_64 = F_50 ( V_79 ) ;
struct V_16 V_17 = {
. V_139 = F_64 ( V_79 ) -> V_140 ,
. V_14 = V_64 -> V_47 ,
. V_47 = V_64 -> V_14 ,
. V_141 = F_7 ( V_2 ) ,
. V_142 = V_2 -> V_143 ,
. V_144 = V_84 ( V_79 ) -> V_93 ,
. V_145 = V_84 ( V_79 ) -> V_94 ,
} ;
F_65 ( V_79 , F_66 ( & V_17 ) ) ;
V_19 = F_67 ( V_88 , & V_17 , V_2 ) ;
if ( F_8 ( V_19 ) ) {
F_68 ( V_88 , V_146 ) ;
return NULL ;
}
return & V_19 -> V_56 ;
}
static int F_69 ( struct V_1 * V_2 , struct V_112 * V_113 ,
struct V_147 * V_148 )
{
int V_20 = - 1 ;
struct V_78 * V_79 ;
struct V_66 * V_56 ;
struct V_16 V_17 ;
V_56 = F_70 ( V_2 , & V_17 , V_113 ) ;
if ( V_56 == NULL )
goto V_60;
V_79 = F_71 ( V_2 , V_56 , V_113 ) ;
if ( V_79 != NULL ) {
const struct V_124 * V_125 = F_54 ( V_113 ) ;
struct V_84 * V_85 = V_84 ( V_79 ) ;
V_85 -> V_123 = F_45 ( V_79 , V_125 -> V_131 ,
V_125 -> V_130 ) ;
V_20 = F_72 ( V_79 , V_2 , V_125 -> V_131 ,
V_125 -> V_130 ,
V_125 -> V_31 ) ;
V_20 = F_73 ( V_20 ) ;
}
V_60:
F_59 ( V_56 ) ;
return V_20 ;
}
static void F_74 ( struct V_1 * V_2 , struct V_78 * V_149 )
{
int V_20 ;
const struct V_63 * V_150 ;
struct V_78 * V_79 ;
struct V_66 * V_56 ;
struct V_88 * V_88 = F_26 ( F_75 ( V_149 ) -> V_89 ) ;
struct V_1 * V_151 = V_88 -> V_152 . V_153 ;
if ( V_84 ( V_149 ) -> V_154 == V_155 )
return;
if ( F_64 ( V_149 ) -> V_156 != V_157 )
return;
V_56 = F_63 ( V_88 , V_151 , V_149 ) ;
if ( V_56 == NULL )
return;
V_79 = F_76 ( V_151 , V_149 ) ;
if ( V_79 == NULL )
goto V_60;
V_150 = F_50 ( V_149 ) ;
V_84 ( V_79 ) -> V_123 = F_45 ( V_79 , V_150 -> V_47 ,
V_150 -> V_14 ) ;
F_77 ( V_79 , F_78 ( V_56 ) ) ;
F_33 ( V_151 ) ;
V_20 = F_72 ( V_79 , V_151 ,
V_150 -> V_14 , V_150 -> V_47 , NULL ) ;
F_43 ( V_151 ) ;
if ( F_73 ( V_20 ) == 0 ) {
F_41 ( V_158 ) ;
F_41 ( V_159 ) ;
}
V_60:
F_59 ( V_56 ) ;
}
static void F_79 ( struct V_112 * V_113 )
{
F_80 ( & F_39 ( V_113 ) -> V_160 ) ;
F_81 ( F_54 ( V_113 ) -> V_31 ) ;
}
int F_82 ( struct V_1 * V_2 , struct V_78 * V_79 )
{
struct V_124 * V_125 ;
struct V_112 * V_113 ;
struct V_161 * V_162 ;
const T_2 V_163 = F_83 ( V_79 ) -> V_164 ;
struct V_165 * V_166 = F_84 ( V_79 ) ;
if ( F_64 ( V_79 ) -> V_43 & ( V_45 | V_44 ) )
return 0 ;
if ( F_85 ( V_2 , V_163 ) ) {
V_166 -> V_167 = V_168 ;
goto V_169;
}
V_166 -> V_167 = V_170 ;
if ( F_86 ( V_2 ) )
goto V_169;
if ( F_52 ( V_2 ) && F_87 ( V_2 ) > 1 )
goto V_169;
V_113 = F_88 ( & V_171 ) ;
if ( V_113 == NULL )
goto V_169;
if ( F_89 ( V_113 , F_3 ( V_2 ) , V_79 ) )
goto V_172;
V_162 = F_39 ( V_113 ) ;
if ( F_90 ( V_2 , V_162 , V_79 ) )
goto V_172;
if ( F_91 ( V_2 , V_79 , V_113 ) )
goto V_172;
V_125 = F_54 ( V_113 ) ;
V_125 -> V_131 = F_50 ( V_79 ) -> V_14 ;
V_125 -> V_130 = F_50 ( V_79 ) -> V_47 ;
V_162 -> V_173 = V_166 -> V_174 ;
V_162 -> V_115 = F_49 ( V_79 ) ;
V_162 -> V_175 = V_163 ;
if ( F_69 ( V_2 , V_113 , NULL ) )
goto V_172;
F_92 ( V_2 , V_113 , V_176 ) ;
return 0 ;
V_172:
F_93 ( V_113 ) ;
V_169:
F_41 ( V_117 ) ;
return - 1 ;
}
int F_94 ( struct V_1 * V_2 , struct V_78 * V_79 )
{
struct V_84 * V_85 = V_84 ( V_79 ) ;
if ( V_2 -> V_67 == V_177 ) {
if ( F_95 ( V_2 , V_79 , V_85 , V_79 -> V_90 ) )
goto V_178;
return 0 ;
}
if ( V_2 -> V_67 == V_68 ) {
struct V_1 * V_138 = F_60 ( V_2 , V_79 ) ;
if ( V_138 == NULL )
goto V_179;
if ( V_138 != V_2 ) {
if ( F_96 ( V_2 , V_138 , V_79 ) )
goto V_178;
return 0 ;
}
}
if ( F_97 ( V_2 , V_79 , V_85 , V_79 -> V_90 ) )
goto V_178;
return 0 ;
V_178:
F_74 ( V_2 , V_79 ) ;
V_179:
F_98 ( V_79 ) ;
return 0 ;
}
int F_99 ( struct V_78 * V_79 )
{
const struct V_84 * V_85 ;
unsigned int V_180 ;
if ( V_79 -> V_181 != V_182 )
return 1 ;
if ( ! F_100 ( V_79 , sizeof( struct V_84 ) ) ) {
F_101 ( L_1 ) ;
return 1 ;
}
V_85 = V_84 ( V_79 ) ;
if ( V_85 -> V_154 >= V_183 ) {
F_101 ( L_2 ) ;
return 1 ;
}
if ( V_85 -> V_184 < F_102 ( V_79 ) / sizeof( T_3 ) ) {
F_101 ( L_3 , V_85 -> V_184 ) ;
return 1 ;
}
if ( ! F_100 ( V_79 , V_85 -> V_184 * sizeof( T_3 ) ) ) {
F_101 ( L_4 , V_85 -> V_184 ) ;
return 1 ;
}
if ( ( V_85 -> V_154 < V_185 ||
V_85 -> V_154 > V_186 ) && V_85 -> V_187 == 0 ) {
F_101 ( L_5 ,
F_103 ( V_85 -> V_154 ) ) ;
return 1 ;
}
V_180 = F_104 ( V_79 ) ;
if ( V_180 > V_79 -> V_90 ) {
F_101 ( L_6 ,
V_85 -> V_188 , V_79 -> V_90 ) ;
return 1 ;
}
V_79 -> V_122 = F_105 ( V_79 , 0 , V_180 , 0 ) ;
return 0 ;
}
static int F_106 ( struct V_78 * V_79 )
{
const struct V_84 * V_85 ;
const struct V_63 * V_64 ;
struct V_1 * V_2 ;
int V_189 ;
if ( F_99 ( V_79 ) )
goto V_190;
V_64 = F_50 ( V_79 ) ;
if ( F_45 ( V_79 , V_64 -> V_47 , V_64 -> V_14 ) ) {
F_101 ( L_7 ) ;
goto V_190;
}
V_85 = V_84 ( V_79 ) ;
F_84 ( V_79 ) -> V_174 = F_35 ( V_85 ) ;
F_84 ( V_79 ) -> V_191 = V_85 -> V_154 ;
F_107 ( L_8 ,
F_103 ( V_85 -> V_154 ) ,
& V_64 -> V_47 , F_108 ( V_85 -> V_94 ) ,
& V_64 -> V_14 , F_108 ( V_85 -> V_93 ) ,
( unsigned long long ) F_84 ( V_79 ) -> V_174 ) ;
if ( F_109 ( V_79 ) ) {
F_84 ( V_79 ) -> V_192 = V_193 ;
F_110 ( L_9 ) ;
} else {
F_84 ( V_79 ) -> V_192 = F_111 ( V_79 ) ;
F_110 ( L_10 , ( unsigned long long )
F_84 ( V_79 ) -> V_192 ) ;
}
V_2 = F_112 ( & V_92 , V_79 ,
V_85 -> V_94 , V_85 -> V_93 ) ;
if ( V_2 == NULL ) {
F_107 ( L_11
L_12 ) ;
goto V_194;
}
if ( V_2 -> V_67 == V_95 ) {
F_107 ( L_13 ) ;
F_31 ( F_32 ( V_2 ) ) ;
goto V_194;
}
V_189 = F_3 ( V_2 ) -> V_195 ;
if ( V_85 -> V_188 && ( V_189 == 0 || V_85 -> V_188 < V_189 ) ) {
F_107 ( L_14 ,
V_85 -> V_188 , V_189 ) ;
goto V_196;
}
if ( ! F_113 ( V_2 , V_197 , V_79 ) )
goto V_196;
F_114 ( V_79 ) ;
return F_115 ( V_2 , V_79 , 1 ) ;
V_194:
if ( ! F_113 ( NULL , V_197 , V_79 ) )
goto V_190;
if ( V_85 -> V_154 != V_155 ) {
F_84 ( V_79 ) -> V_167 =
V_198 ;
F_74 ( V_2 , V_79 ) ;
}
V_190:
F_98 ( V_79 ) ;
return 0 ;
V_196:
F_44 ( V_2 ) ;
goto V_190;
}
static int F_116 ( struct V_1 * V_2 )
{
static T_8 V_199 ;
int V_20 = F_117 ( V_2 , V_199 ) ;
if ( V_20 == 0 ) {
if ( F_118 ( ! V_199 ) )
V_199 = 1 ;
F_11 ( V_2 ) -> V_200 = & V_201 ;
}
return V_20 ;
}
static int T_9 F_119 ( struct V_88 * V_88 )
{
if ( V_92 . V_202 == NULL )
return - V_203 ;
return F_120 ( & V_88 -> V_152 . V_153 , V_204 ,
V_205 , V_42 , V_88 ) ;
}
static void T_10 F_121 ( struct V_88 * V_88 )
{
F_122 ( V_88 -> V_152 . V_153 ) ;
}
static int T_11 F_123 ( void )
{
int V_20 = F_124 ( & V_206 , 1 ) ;
if ( V_20 != 0 )
goto V_60;
V_20 = F_125 ( & V_207 , V_42 ) ;
if ( V_20 != 0 )
goto V_208;
F_126 ( & V_209 ) ;
V_20 = F_127 ( & V_210 ) ;
if ( V_20 )
goto V_211;
V_60:
return V_20 ;
V_211:
F_128 ( & V_209 ) ;
F_129 ( & V_207 , V_42 ) ;
V_208:
F_130 ( & V_206 ) ;
goto V_60;
}
static void T_12 F_131 ( void )
{
F_132 ( & V_210 ) ;
F_128 ( & V_209 ) ;
F_129 ( & V_207 , V_42 ) ;
F_130 ( & V_206 ) ;
}
