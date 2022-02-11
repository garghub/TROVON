static inline T_1 F_1 ( struct V_1 * V_2 ,
const struct V_3 * V_4 ,
const struct V_3 * V_5 )
{
return F_2 ( V_4 , V_5 , V_2 -> V_6 , V_7 , V_2 -> V_8 ) ;
}
static inline void F_3 ( struct V_9 * V_10 , struct V_1 * V_2 )
{
struct V_11 * V_12 = F_4 ( V_10 ) ;
struct V_13 * V_14 = V_13 ( V_2 ) ;
F_5 ( V_2 ) ;
V_14 -> V_15 = F_1 ( V_2 , & V_12 -> V_4 , & V_10 -> V_16 ) ;
}
static inline T_2 F_6 ( struct V_1 * V_2 )
{
return F_7 ( F_8 ( V_2 ) -> V_5 . V_17 ,
F_8 ( V_2 ) -> V_4 . V_17 ,
V_13 ( V_2 ) -> V_18 ,
V_13 ( V_2 ) -> V_19 ) ;
}
static void F_9 ( struct V_1 * V_2 , struct V_20 * V_21 ,
T_3 type , T_3 V_22 , int V_23 , T_4 V_24 )
{
const struct V_25 * V_26 = ( const struct V_25 * ) V_2 -> V_27 ;
const struct V_13 * V_14 ;
struct V_28 * V_29 ;
struct V_11 * V_12 ;
struct V_9 * V_10 ;
int V_30 ;
T_2 V_31 ;
struct V_32 * V_32 = F_10 ( V_2 -> V_33 ) ;
F_11 ( F_12 ( struct V_13 , V_19 ) > 8 ) ;
F_11 ( F_12 ( struct V_13 , V_18 ) > 8 ) ;
V_14 = (struct V_13 * ) ( V_2 -> V_27 + V_23 ) ;
V_10 = F_13 ( V_32 , & V_34 ,
& V_26 -> V_5 , V_14 -> V_18 ,
& V_26 -> V_4 , F_14 ( V_14 -> V_19 ) ,
F_15 ( V_2 ) ) ;
if ( ! V_10 ) {
F_16 ( V_32 , F_17 ( V_2 -> V_33 ) ,
V_35 ) ;
return;
}
if ( V_10 -> V_36 == V_37 ) {
F_18 ( F_19 ( V_10 ) ) ;
return;
}
V_31 = F_20 ( V_14 ) ;
if ( V_10 -> V_36 == V_38 )
return F_21 ( V_10 , V_31 ) ;
F_22 ( V_10 ) ;
if ( F_23 ( V_10 ) )
F_24 ( V_32 , V_39 ) ;
if ( V_10 -> V_36 == V_40 )
goto V_41;
V_29 = F_25 ( V_10 ) ;
if ( ( 1 << V_10 -> V_36 ) & ~ ( V_42 | V_43 ) &&
! F_26 ( V_31 , V_29 -> V_44 , V_29 -> V_45 ) ) {
F_24 ( V_32 , V_46 ) ;
goto V_41;
}
V_12 = F_4 ( V_10 ) ;
if ( type == V_47 ) {
struct V_48 * V_49 = F_27 ( V_10 , V_12 -> V_50 ) ;
if ( V_49 )
V_49 -> V_51 -> V_52 ( V_49 , V_10 , V_2 ) ;
goto V_41;
}
if ( type == V_53 ) {
struct V_48 * V_49 = NULL ;
if ( ! F_28 ( V_10 ) )
goto V_41;
if ( F_23 ( V_10 ) )
goto V_41;
if ( ( 1 << V_10 -> V_36 ) & ( V_43 | V_54 ) )
goto V_41;
V_49 = F_29 ( V_10 , F_30 ( V_24 ) ) ;
if ( ! V_49 )
goto V_41;
if ( F_31 ( V_10 ) -> V_55 > F_32 ( V_49 ) )
F_33 ( V_10 , F_32 ( V_49 ) ) ;
goto V_41;
}
F_34 ( type , V_22 , & V_30 ) ;
switch ( V_10 -> V_36 ) {
case V_56 :
case V_57 :
if ( ! F_23 ( V_10 ) ) {
F_35 ( V_58 ) ;
V_10 -> V_59 = V_30 ;
V_10 -> V_60 ( V_10 ) ;
F_36 ( V_10 ) ;
} else
V_10 -> V_61 = V_30 ;
goto V_41;
}
if ( ! F_23 ( V_10 ) && V_12 -> V_62 ) {
V_10 -> V_59 = V_30 ;
V_10 -> V_60 ( V_10 ) ;
} else
V_10 -> V_61 = V_30 ;
V_41:
F_37 ( V_10 ) ;
F_38 ( V_10 ) ;
}
static int F_39 ( const struct V_9 * V_10 , struct V_63 * V_64 )
{
struct V_65 * V_66 = F_40 ( V_64 ) ;
struct V_11 * V_12 = F_4 ( V_10 ) ;
struct V_1 * V_2 ;
struct V_3 * V_67 , V_68 ;
struct V_69 V_70 ;
int V_30 = - 1 ;
struct V_48 * V_49 ;
memset ( & V_70 , 0 , sizeof( V_70 ) ) ;
V_70 . V_71 = V_7 ;
V_70 . V_5 = V_66 -> V_72 ;
V_70 . V_4 = V_66 -> V_73 ;
V_70 . V_74 = 0 ;
V_70 . V_75 = V_66 -> V_76 ;
V_70 . V_77 = V_66 -> V_78 ;
V_70 . V_79 = F_41 ( V_66 -> V_80 ) ;
F_42 ( V_64 , F_43 ( & V_70 ) ) ;
F_44 () ;
V_67 = F_45 ( & V_70 , F_46 ( V_12 -> V_21 ) , & V_68 ) ;
F_47 () ;
V_49 = F_48 ( V_10 , & V_70 , V_67 ) ;
if ( F_49 ( V_49 ) ) {
V_30 = F_50 ( V_49 ) ;
V_49 = NULL ;
goto V_81;
}
V_2 = F_51 ( V_10 , V_49 , V_64 ) ;
if ( V_2 != NULL ) {
struct V_13 * V_14 = V_13 ( V_2 ) ;
struct V_82 * V_21 ;
V_14 -> V_15 = F_1 ( V_2 ,
& V_66 -> V_73 ,
& V_66 -> V_72 ) ;
V_70 . V_5 = V_66 -> V_72 ;
F_44 () ;
V_21 = V_66 -> V_83 ;
if ( ! V_21 )
V_21 = F_46 ( V_12 -> V_21 ) ;
V_30 = F_52 ( V_10 , V_2 , & V_70 , V_21 , V_12 -> V_84 ) ;
F_47 () ;
V_30 = F_53 ( V_30 ) ;
}
V_81:
F_54 ( V_49 ) ;
return V_30 ;
}
static void F_55 ( struct V_63 * V_64 )
{
F_56 ( & F_57 ( V_64 ) -> V_85 ) ;
F_58 ( F_40 ( V_64 ) -> V_83 ) ;
F_59 ( F_40 ( V_64 ) -> V_86 ) ;
}
static void F_60 ( const struct V_9 * V_10 , struct V_1 * V_87 )
{
const struct V_25 * V_88 ;
struct V_1 * V_2 ;
struct V_69 V_70 ;
struct V_32 * V_32 = F_10 ( F_61 ( V_87 ) -> V_33 ) ;
struct V_9 * V_89 = V_32 -> V_90 . V_91 ;
struct V_48 * V_49 ;
if ( V_13 ( V_87 ) -> V_92 == V_93 )
return;
if ( ! F_62 ( V_87 ) )
return;
V_2 = F_63 ( V_89 , V_87 ) ;
if ( V_2 == NULL )
return;
V_88 = F_8 ( V_87 ) ;
V_13 ( V_2 ) -> V_15 = F_1 ( V_2 , & V_88 -> V_4 ,
& V_88 -> V_5 ) ;
memset ( & V_70 , 0 , sizeof( V_70 ) ) ;
V_70 . V_5 = V_88 -> V_4 ;
V_70 . V_4 = V_88 -> V_5 ;
V_70 . V_71 = V_7 ;
V_70 . V_75 = F_15 ( V_87 ) ;
V_70 . V_77 = V_13 ( V_2 ) -> V_18 ;
V_70 . V_79 = V_13 ( V_2 ) -> V_19 ;
F_64 ( V_87 , F_43 ( & V_70 ) ) ;
V_49 = F_48 ( V_89 , & V_70 , NULL ) ;
if ( ! F_49 ( V_49 ) ) {
F_65 ( V_2 , V_49 ) ;
F_52 ( V_89 , V_2 , & V_70 , NULL , 0 ) ;
F_66 ( V_94 ) ;
F_66 ( V_95 ) ;
return;
}
F_59 ( V_2 ) ;
}
static int F_67 ( struct V_9 * V_10 , struct V_1 * V_2 )
{
struct V_63 * V_64 ;
struct V_96 * V_97 ;
struct V_65 * V_66 ;
struct V_11 * V_12 = F_4 ( V_10 ) ;
const T_4 V_98 = F_68 ( V_2 ) -> V_99 ;
struct V_100 * V_101 = F_69 ( V_2 ) ;
if ( V_2 -> V_102 == F_41 ( V_103 ) )
return F_70 ( V_10 , V_2 ) ;
if ( ! F_62 ( V_2 ) )
return 0 ;
if ( F_71 ( V_10 , V_98 ) ) {
V_101 -> V_104 = V_105 ;
goto V_106;
}
V_101 -> V_104 = V_107 ;
if ( F_72 ( V_10 ) )
goto V_106;
if ( F_73 ( V_10 ) && F_74 ( V_10 ) > 1 )
goto V_106;
V_64 = F_75 ( & V_108 , V_10 , true ) ;
if ( V_64 == NULL )
goto V_106;
if ( F_76 ( V_64 , F_25 ( V_10 ) , V_2 ) )
goto V_109;
V_97 = F_57 ( V_64 ) ;
if ( F_77 ( V_10 , V_97 , V_2 ) )
goto V_109;
if ( F_78 ( V_10 , V_2 , V_64 ) )
goto V_109;
V_66 = F_40 ( V_64 ) ;
V_66 -> V_72 = F_8 ( V_2 ) -> V_4 ;
V_66 -> V_73 = F_8 ( V_2 ) -> V_5 ;
V_66 -> V_110 = V_111 ;
if ( F_79 ( V_10 , V_2 , F_80 ( V_2 ) ) ||
V_12 -> V_112 . V_113 . V_114 || V_12 -> V_112 . V_113 . V_115 ||
V_12 -> V_112 . V_113 . V_116 || V_12 -> V_112 . V_113 . V_117 ) {
F_81 ( & V_2 -> V_118 ) ;
V_66 -> V_86 = V_2 ;
}
V_66 -> V_76 = V_10 -> V_119 ;
if ( ! V_10 -> V_119 &&
F_82 ( & V_66 -> V_72 ) & V_120 )
V_66 -> V_76 = F_15 ( V_2 ) ;
V_97 -> V_121 = V_101 -> V_122 ;
V_97 -> V_123 = V_97 -> V_121 ;
V_97 -> V_124 = F_6 ( V_2 ) ;
V_97 -> V_125 = V_97 -> V_124 ;
V_97 -> V_126 = V_98 ;
if ( F_39 ( V_10 , V_64 ) )
goto V_109;
F_83 ( V_10 , V_64 , V_127 ) ;
return 0 ;
V_109:
F_84 ( V_64 ) ;
V_106:
F_35 ( V_58 ) ;
return - 1 ;
}
static struct V_9 * F_85 ( const struct V_9 * V_10 ,
struct V_1 * V_2 ,
struct V_63 * V_64 ,
struct V_48 * V_49 ,
struct V_63 * V_128 ,
bool * V_129 )
{
struct V_65 * V_66 = F_40 ( V_64 ) ;
struct V_11 * V_130 ;
const struct V_11 * V_12 = F_4 ( V_10 ) ;
struct V_82 * V_21 ;
struct V_131 * V_132 ;
struct V_133 * V_134 ;
struct V_9 * V_135 ;
if ( V_2 -> V_102 == F_41 ( V_103 ) ) {
V_135 = F_86 ( V_10 , V_2 , V_64 , V_49 ,
V_128 , V_129 ) ;
if ( V_135 == NULL )
return NULL ;
V_134 = (struct V_133 * ) V_135 ;
V_132 = F_87 ( V_135 ) ;
V_132 -> V_136 = & V_134 -> V_137 ;
V_130 = F_4 ( V_135 ) ;
memcpy ( V_130 , V_12 , sizeof( struct V_11 ) ) ;
V_130 -> V_4 = V_135 -> V_138 ;
F_31 ( V_135 ) -> V_139 = & V_140 ;
V_135 -> V_141 = V_142 ;
V_130 -> V_143 = NULL ;
V_130 -> V_21 = NULL ;
V_130 -> V_144 = F_15 ( V_2 ) ;
V_130 -> V_145 = F_8 ( V_2 ) -> V_146 ;
F_33 ( V_135 , F_31 ( V_135 ) -> V_55 ) ;
return V_135 ;
}
if ( F_73 ( V_10 ) )
goto V_147;
if ( ! V_49 ) {
struct V_69 V_70 ;
V_49 = F_88 ( V_10 , & V_70 , V_64 , V_7 ) ;
if ( ! V_49 )
goto V_41;
}
V_135 = F_89 ( V_10 , V_64 , V_2 ) ;
if ( V_135 == NULL )
goto V_148;
F_90 ( V_135 , V_49 , NULL , NULL ) ;
V_135 -> V_149 = V_49 -> V_33 -> V_150 & ~ ( V_151 |
V_152 ) ;
V_134 = (struct V_133 * ) V_135 ;
V_132 = F_87 ( V_135 ) ;
V_132 -> V_136 = & V_134 -> V_137 ;
V_130 = F_4 ( V_135 ) ;
memcpy ( V_130 , V_12 , sizeof( struct V_11 ) ) ;
V_135 -> V_16 = V_66 -> V_72 ;
V_130 -> V_4 = V_66 -> V_73 ;
V_135 -> V_138 = V_66 -> V_73 ;
V_135 -> V_119 = V_66 -> V_76 ;
V_132 -> V_153 = NULL ;
V_130 -> V_112 . V_154 = V_12 -> V_112 . V_154 ;
V_130 -> V_143 = NULL ;
V_130 -> V_21 = NULL ;
V_130 -> V_144 = F_15 ( V_2 ) ;
V_130 -> V_145 = F_8 ( V_2 ) -> V_146 ;
V_21 = V_66 -> V_83 ;
if ( ! V_21 )
V_21 = F_46 ( V_12 -> V_21 ) ;
if ( V_21 ) {
V_21 = F_91 ( V_135 , V_21 ) ;
F_92 ( V_130 -> V_21 , V_21 ) ;
}
F_31 ( V_135 ) -> V_155 = 0 ;
if ( V_21 )
F_31 ( V_135 ) -> V_155 = V_21 -> V_156 +
V_21 -> V_157 ;
F_33 ( V_135 , F_32 ( V_49 ) ) ;
V_132 -> V_158 = V_132 -> V_159 = V_160 ;
V_132 -> V_161 = V_160 ;
if ( F_93 ( V_10 , V_135 ) < 0 ) {
F_94 ( V_135 ) ;
F_36 ( V_135 ) ;
goto V_41;
}
* V_129 = F_95 ( V_135 , F_96 ( V_128 ) ) ;
if ( * V_129 && V_66 -> V_86 ) {
V_130 -> V_143 = F_97 ( V_66 -> V_86 , V_162 ) ;
F_98 ( V_66 -> V_86 ) ;
V_66 -> V_86 = NULL ;
if ( V_130 -> V_143 )
F_99 ( V_130 -> V_143 , V_135 ) ;
}
return V_135 ;
V_147:
F_24 ( F_100 ( V_10 ) , V_163 ) ;
V_148:
F_54 ( V_49 ) ;
V_41:
F_24 ( F_100 ( V_10 ) , V_164 ) ;
return NULL ;
}
static int F_101 ( struct V_9 * V_10 , struct V_1 * V_2 )
{
struct V_11 * V_12 = F_4 ( V_10 ) ;
struct V_1 * V_165 = NULL ;
if ( V_2 -> V_102 == F_41 ( V_103 ) )
return V_142 ( V_10 , V_2 ) ;
if ( F_102 ( V_10 , V_2 ) )
goto V_166;
if ( V_12 -> V_112 . V_154 )
V_165 = F_97 ( V_2 , V_162 ) ;
if ( V_10 -> V_36 == V_167 ) {
if ( F_103 ( V_10 , V_2 , V_13 ( V_2 ) , V_2 -> V_6 ) )
goto V_168;
if ( V_165 ) {
F_104 ( V_165 ) ;
}
return 0 ;
}
if ( F_105 ( V_10 , V_2 , V_13 ( V_2 ) , V_2 -> V_6 ) )
goto V_168;
if ( V_165 ) {
F_104 ( V_165 ) ;
}
return 0 ;
V_168:
F_60 ( V_10 , V_2 ) ;
V_166:
if ( V_165 != NULL )
F_104 ( V_165 ) ;
F_59 ( V_2 ) ;
return 0 ;
}
static int F_106 ( struct V_1 * V_2 )
{
const struct V_13 * V_14 ;
bool V_169 ;
struct V_9 * V_10 ;
int V_170 ;
if ( F_107 ( V_2 ) )
goto V_171;
if ( F_1 ( V_2 , & F_8 ( V_2 ) -> V_4 ,
& F_8 ( V_2 ) -> V_5 ) ) {
F_108 ( L_1 ) ;
goto V_171;
}
V_14 = V_13 ( V_2 ) ;
F_69 ( V_2 ) -> V_122 = F_20 ( V_14 ) ;
F_69 ( V_2 ) -> V_172 = V_14 -> V_92 ;
if ( F_109 ( V_2 ) )
F_69 ( V_2 ) -> V_173 = V_174 ;
else
F_69 ( V_2 ) -> V_173 = F_110 ( V_2 ) ;
V_175:
V_10 = F_111 ( & V_34 , V_2 , F_112 ( V_14 ) ,
V_14 -> V_19 , V_14 -> V_18 ,
F_15 ( V_2 ) , & V_169 ) ;
if ( ! V_10 ) {
F_113 ( L_2
L_3 ) ;
goto V_176;
}
if ( V_10 -> V_36 == V_37 ) {
F_113 ( L_4 ) ;
F_18 ( F_19 ( V_10 ) ) ;
goto V_176;
}
if ( V_10 -> V_36 == V_38 ) {
struct V_63 * V_64 = F_114 ( V_10 ) ;
struct V_9 * V_177 ;
V_10 = V_64 -> V_178 ;
if ( F_115 ( V_10 -> V_36 != V_179 ) ) {
F_116 ( V_10 , V_64 ) ;
goto V_175;
}
F_117 ( V_10 ) ;
V_169 = true ;
V_177 = F_118 ( V_10 , V_2 , V_64 ) ;
if ( ! V_177 ) {
F_119 ( V_64 ) ;
goto V_180;
}
if ( V_177 == V_10 ) {
F_119 ( V_64 ) ;
} else if ( F_120 ( V_10 , V_177 , V_2 ) ) {
F_60 ( V_10 , V_2 ) ;
goto V_180;
} else {
F_38 ( V_10 ) ;
return 0 ;
}
}
V_170 = F_25 ( V_10 ) -> V_181 ;
if ( V_14 -> V_182 && ( V_170 == 0 || V_14 -> V_182 < V_170 ) ) {
F_113 ( L_5 ,
V_14 -> V_182 , V_170 ) ;
goto V_180;
}
if ( ! F_121 ( V_10 , V_183 , V_2 ) )
goto V_180;
return F_122 ( V_10 , V_2 , 1 , V_14 -> V_184 * 4 ,
V_169 ) ? - 1 : 0 ;
V_176:
if ( ! F_121 ( NULL , V_183 , V_2 ) )
goto V_171;
if ( V_14 -> V_92 != V_93 ) {
F_69 ( V_2 ) -> V_104 =
V_185 ;
F_60 ( V_10 , V_2 ) ;
}
V_171:
F_59 ( V_2 ) ;
return 0 ;
V_180:
if ( V_169 )
F_38 ( V_10 ) ;
goto V_171;
}
static int F_123 ( struct V_9 * V_10 , struct V_186 * V_187 ,
int V_188 )
{
struct V_189 * V_190 = (struct V_189 * ) V_187 ;
struct V_191 * V_192 = F_31 ( V_10 ) ;
struct V_131 * V_193 = F_87 ( V_10 ) ;
struct V_11 * V_12 = F_4 ( V_10 ) ;
struct V_28 * V_29 = F_25 ( V_10 ) ;
struct V_3 * V_4 = NULL , * V_67 , V_68 ;
struct V_82 * V_21 ;
struct V_69 V_70 ;
struct V_48 * V_49 ;
int V_194 ;
int V_30 ;
V_29 -> V_195 = V_196 ;
if ( V_188 < V_197 )
return - V_198 ;
if ( V_190 -> V_199 != V_111 )
return - V_200 ;
memset ( & V_70 , 0 , sizeof( V_70 ) ) ;
if ( V_12 -> V_201 ) {
V_70 . V_74 = V_190 -> V_202 & V_203 ;
F_124 ( V_70 . V_74 ) ;
if ( V_70 . V_74 & V_204 ) {
struct V_205 * V_74 ;
V_74 = F_125 ( V_10 , V_70 . V_74 ) ;
if ( V_74 == NULL )
return - V_198 ;
F_126 ( V_74 ) ;
}
}
if ( F_127 ( & V_190 -> V_206 ) )
V_190 -> V_206 . V_207 [ 15 ] = 1 ;
V_194 = F_82 ( & V_190 -> V_206 ) ;
if ( V_194 & V_208 )
return - V_209 ;
if ( V_194 & V_120 ) {
if ( V_188 >= sizeof( struct V_189 ) &&
V_190 -> V_210 ) {
if ( V_10 -> V_119 &&
V_10 -> V_119 != V_190 -> V_210 )
return - V_198 ;
V_10 -> V_119 = V_190 -> V_210 ;
}
if ( ! V_10 -> V_119 )
return - V_198 ;
}
V_10 -> V_16 = V_190 -> V_206 ;
V_12 -> V_211 = V_70 . V_74 ;
if ( V_194 == V_212 ) {
T_5 V_213 = V_192 -> V_155 ;
struct V_214 sin ;
F_128 ( V_10 , L_6 ) ;
if ( F_129 ( V_10 ) )
return - V_209 ;
sin . V_215 = V_216 ;
sin . V_217 = V_190 -> V_218 ;
sin . V_219 . V_220 = V_190 -> V_206 . V_17 [ 3 ] ;
V_192 -> V_139 = & V_140 ;
V_10 -> V_141 = V_142 ;
V_30 = F_130 ( V_10 , (struct V_186 * ) & sin , sizeof( sin ) ) ;
if ( V_30 ) {
V_192 -> V_155 = V_213 ;
V_192 -> V_139 = & V_221 ;
V_10 -> V_141 = F_101 ;
goto V_222;
}
V_12 -> V_4 = V_10 -> V_138 ;
return V_30 ;
}
if ( ! F_127 ( & V_10 -> V_138 ) )
V_4 = & V_10 -> V_138 ;
V_70 . V_71 = V_7 ;
V_70 . V_5 = V_10 -> V_16 ;
V_70 . V_4 = V_4 ? * V_4 : V_12 -> V_4 ;
V_70 . V_75 = V_10 -> V_119 ;
V_70 . V_77 = V_190 -> V_218 ;
V_70 . V_79 = V_193 -> V_223 ;
F_131 ( V_10 , F_43 ( & V_70 ) ) ;
V_21 = F_132 ( V_12 -> V_21 , F_133 ( V_10 ) ) ;
V_67 = F_45 ( & V_70 , V_21 , & V_68 ) ;
V_49 = F_48 ( V_10 , & V_70 , V_67 ) ;
if ( F_49 ( V_49 ) ) {
V_30 = F_50 ( V_49 ) ;
goto V_222;
}
if ( V_4 == NULL ) {
V_4 = & V_70 . V_4 ;
V_10 -> V_138 = * V_4 ;
}
V_12 -> V_4 = * V_4 ;
V_193 -> V_161 = V_160 ;
F_90 ( V_10 , V_49 , NULL , NULL ) ;
V_192 -> V_155 = 0 ;
if ( V_21 )
V_192 -> V_155 = V_21 -> V_157 + V_21 -> V_156 ;
V_193 -> V_224 = V_190 -> V_218 ;
F_134 ( V_10 , V_56 ) ;
V_30 = F_135 ( & V_225 , V_10 ) ;
if ( V_30 )
goto V_226;
V_29 -> V_227 = F_7 ( V_12 -> V_4 . V_17 ,
V_10 -> V_16 . V_17 ,
V_193 -> V_223 ,
V_193 -> V_224 ) ;
V_30 = F_136 ( V_10 ) ;
if ( V_30 )
goto V_226;
return 0 ;
V_226:
F_134 ( V_10 , V_40 ) ;
F_137 ( V_10 ) ;
V_222:
V_193 -> V_224 = 0 ;
V_10 -> V_149 = 0 ;
return V_30 ;
}
static int F_138 ( struct V_9 * V_10 )
{
static T_6 V_228 ;
int V_30 = F_139 ( V_10 , V_228 ) ;
if ( V_30 == 0 ) {
if ( F_115 ( ! V_228 ) )
V_228 = 1 ;
F_31 ( V_10 ) -> V_139 = & V_221 ;
}
return V_30 ;
}
static void F_140 ( struct V_9 * V_10 )
{
F_141 ( V_10 ) ;
F_142 ( V_10 ) ;
}
static int T_7 F_143 ( struct V_32 * V_32 )
{
if ( V_34 . V_229 == NULL )
return - V_230 ;
return F_144 ( & V_32 -> V_90 . V_91 , V_231 ,
V_232 , V_7 , V_32 ) ;
}
static void T_8 F_145 ( struct V_32 * V_32 )
{
F_146 ( V_32 -> V_90 . V_91 ) ;
}
static int T_9 F_147 ( void )
{
int V_30 = F_148 ( & V_233 , 1 ) ;
if ( V_30 != 0 )
goto V_41;
V_30 = F_149 ( & V_234 , V_7 ) ;
if ( V_30 != 0 )
goto V_235;
F_150 ( & V_236 ) ;
V_30 = F_151 ( & V_237 ) ;
if ( V_30 != 0 )
goto V_238;
V_41:
return V_30 ;
V_238:
F_152 ( & V_234 , V_7 ) ;
F_153 ( & V_236 ) ;
V_235:
F_154 ( & V_233 ) ;
goto V_41;
}
static void T_10 F_155 ( void )
{
F_156 ( & V_237 ) ;
F_152 ( & V_234 , V_7 ) ;
F_153 ( & V_236 ) ;
F_154 ( & V_233 ) ;
}
