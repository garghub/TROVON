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
if ( ! F_23 ( V_10 ) ) {
struct V_48 * V_49 = F_27 ( V_10 , V_12 -> V_50 ) ;
if ( V_49 )
V_49 -> V_51 -> V_52 ( V_49 , V_10 , V_2 ) ;
}
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
V_30 = F_52 ( V_10 , V_2 , & V_70 , V_10 -> V_84 , V_21 , V_12 -> V_85 ) ;
F_47 () ;
V_30 = F_53 ( V_30 ) ;
}
V_81:
F_54 ( V_49 ) ;
return V_30 ;
}
static void F_55 ( struct V_63 * V_64 )
{
F_56 ( & F_57 ( V_64 ) -> V_86 ) ;
F_58 ( F_40 ( V_64 ) -> V_83 ) ;
F_59 ( F_40 ( V_64 ) -> V_87 ) ;
}
static void F_60 ( const struct V_9 * V_10 , struct V_1 * V_88 )
{
const struct V_25 * V_89 ;
struct V_1 * V_2 ;
struct V_69 V_70 ;
struct V_32 * V_32 = F_10 ( F_61 ( V_88 ) -> V_33 ) ;
struct V_9 * V_90 = V_32 -> V_91 . V_92 ;
struct V_48 * V_49 ;
if ( V_13 ( V_88 ) -> V_93 == V_94 )
return;
if ( ! F_62 ( V_88 ) )
return;
V_2 = F_63 ( V_90 , V_88 ) ;
if ( V_2 == NULL )
return;
V_89 = F_8 ( V_88 ) ;
V_13 ( V_2 ) -> V_15 = F_1 ( V_2 , & V_89 -> V_4 ,
& V_89 -> V_5 ) ;
memset ( & V_70 , 0 , sizeof( V_70 ) ) ;
V_70 . V_5 = V_89 -> V_4 ;
V_70 . V_4 = V_89 -> V_5 ;
V_70 . V_71 = V_7 ;
V_70 . V_75 = F_15 ( V_88 ) ;
V_70 . V_77 = V_13 ( V_2 ) -> V_18 ;
V_70 . V_79 = V_13 ( V_2 ) -> V_19 ;
F_64 ( V_88 , F_43 ( & V_70 ) ) ;
V_49 = F_48 ( V_90 , & V_70 , NULL ) ;
if ( ! F_49 ( V_49 ) ) {
F_65 ( V_2 , V_49 ) ;
F_52 ( V_90 , V_2 , & V_70 , 0 , NULL , 0 ) ;
F_66 ( V_95 ) ;
F_66 ( V_96 ) ;
return;
}
F_59 ( V_2 ) ;
}
static int F_67 ( struct V_9 * V_10 , struct V_1 * V_2 )
{
struct V_63 * V_64 ;
struct V_97 * V_98 ;
struct V_65 * V_66 ;
struct V_11 * V_12 = F_4 ( V_10 ) ;
const T_4 V_99 = F_68 ( V_2 ) -> V_100 ;
struct V_101 * V_102 = F_69 ( V_2 ) ;
if ( V_2 -> V_103 == F_41 ( V_104 ) )
return F_70 ( V_10 , V_2 ) ;
if ( ! F_62 ( V_2 ) )
return 0 ;
if ( F_71 ( V_10 , V_99 ) ) {
V_102 -> V_105 = V_106 ;
goto V_107;
}
V_102 -> V_105 = V_108 ;
if ( F_72 ( V_10 ) )
goto V_107;
if ( F_73 ( V_10 ) )
goto V_107;
V_64 = F_74 ( & V_109 , V_10 , true ) ;
if ( V_64 == NULL )
goto V_107;
if ( F_75 ( V_64 , F_25 ( V_10 ) , V_2 ) )
goto V_110;
V_98 = F_57 ( V_64 ) ;
if ( F_76 ( V_10 , V_98 , V_2 ) )
goto V_110;
if ( F_77 ( V_10 , V_2 , V_64 ) )
goto V_110;
V_66 = F_40 ( V_64 ) ;
V_66 -> V_72 = F_8 ( V_2 ) -> V_4 ;
V_66 -> V_73 = F_8 ( V_2 ) -> V_5 ;
V_66 -> V_111 = V_112 ;
if ( F_78 ( V_10 , V_2 , F_79 ( V_2 ) ) ||
V_12 -> V_113 . V_114 . V_115 || V_12 -> V_113 . V_114 . V_116 ||
V_12 -> V_113 . V_114 . V_117 || V_12 -> V_113 . V_114 . V_118 ) {
F_80 ( & V_2 -> V_119 ) ;
V_66 -> V_87 = V_2 ;
}
V_66 -> V_76 = V_10 -> V_120 ;
if ( ! V_10 -> V_120 &&
F_81 ( & V_66 -> V_72 ) & V_121 )
V_66 -> V_76 = F_15 ( V_2 ) ;
V_98 -> V_122 = V_102 -> V_123 ;
V_98 -> V_124 = V_98 -> V_122 ;
V_98 -> V_125 = F_6 ( V_2 ) ;
V_98 -> V_126 = V_98 -> V_125 ;
V_98 -> V_127 = V_99 ;
if ( F_39 ( V_10 , V_64 ) )
goto V_110;
F_82 ( V_10 , V_64 , V_128 ) ;
return 0 ;
V_110:
F_83 ( V_64 ) ;
V_107:
F_35 ( V_58 ) ;
return - 1 ;
}
static struct V_9 * F_84 ( const struct V_9 * V_10 ,
struct V_1 * V_2 ,
struct V_63 * V_64 ,
struct V_48 * V_49 ,
struct V_63 * V_129 ,
bool * V_130 )
{
struct V_65 * V_66 = F_40 ( V_64 ) ;
struct V_11 * V_131 ;
const struct V_11 * V_12 = F_4 ( V_10 ) ;
struct V_82 * V_21 ;
struct V_132 * V_133 ;
struct V_134 * V_135 ;
struct V_9 * V_136 ;
if ( V_2 -> V_103 == F_41 ( V_104 ) ) {
V_136 = F_85 ( V_10 , V_2 , V_64 , V_49 ,
V_129 , V_130 ) ;
if ( V_136 == NULL )
return NULL ;
V_135 = (struct V_134 * ) V_136 ;
V_133 = F_86 ( V_136 ) ;
V_133 -> V_137 = & V_135 -> V_138 ;
V_131 = F_4 ( V_136 ) ;
memcpy ( V_131 , V_12 , sizeof( struct V_11 ) ) ;
V_131 -> V_4 = V_136 -> V_139 ;
F_31 ( V_136 ) -> V_140 = & V_141 ;
V_136 -> V_142 = V_143 ;
V_131 -> V_144 = NULL ;
V_131 -> V_21 = NULL ;
V_131 -> V_145 = NULL ;
V_131 -> V_146 = NULL ;
V_131 -> V_147 = NULL ;
V_131 -> V_148 = F_15 ( V_2 ) ;
V_131 -> V_149 = F_8 ( V_2 ) -> V_150 ;
F_33 ( V_136 , F_31 ( V_136 ) -> V_55 ) ;
return V_136 ;
}
if ( F_73 ( V_10 ) )
goto V_151;
if ( ! V_49 ) {
struct V_69 V_70 ;
V_49 = F_87 ( V_10 , & V_70 , V_64 , V_7 ) ;
if ( ! V_49 )
goto V_41;
}
V_136 = F_88 ( V_10 , V_64 , V_2 ) ;
if ( V_136 == NULL )
goto V_152;
F_89 ( V_136 , V_49 , NULL , NULL ) ;
V_136 -> V_153 = V_49 -> V_33 -> V_154 & ~ ( V_155 |
V_156 ) ;
V_135 = (struct V_134 * ) V_136 ;
V_133 = F_86 ( V_136 ) ;
V_133 -> V_137 = & V_135 -> V_138 ;
V_131 = F_4 ( V_136 ) ;
memcpy ( V_131 , V_12 , sizeof( struct V_11 ) ) ;
V_136 -> V_16 = V_66 -> V_72 ;
V_131 -> V_4 = V_66 -> V_73 ;
V_136 -> V_139 = V_66 -> V_73 ;
V_136 -> V_120 = V_66 -> V_76 ;
V_133 -> V_157 = NULL ;
V_131 -> V_113 . V_158 = V_12 -> V_113 . V_158 ;
V_131 -> V_145 = NULL ;
V_131 -> V_146 = NULL ;
V_131 -> V_147 = NULL ;
V_131 -> V_144 = NULL ;
V_131 -> V_21 = NULL ;
V_131 -> V_148 = F_15 ( V_2 ) ;
V_131 -> V_149 = F_8 ( V_2 ) -> V_150 ;
V_21 = V_66 -> V_83 ;
if ( ! V_21 )
V_21 = F_46 ( V_12 -> V_21 ) ;
if ( V_21 ) {
V_21 = F_90 ( V_136 , V_21 ) ;
F_91 ( V_131 -> V_21 , V_21 ) ;
}
F_31 ( V_136 ) -> V_159 = 0 ;
if ( V_21 )
F_31 ( V_136 ) -> V_159 = V_21 -> V_160 +
V_21 -> V_161 ;
F_33 ( V_136 , F_32 ( V_49 ) ) ;
V_133 -> V_162 = V_133 -> V_163 = V_164 ;
V_133 -> V_165 = V_164 ;
if ( F_92 ( V_10 , V_136 ) < 0 ) {
F_93 ( V_136 ) ;
F_36 ( V_136 ) ;
goto V_41;
}
* V_130 = F_94 ( V_136 , F_95 ( V_129 ) ) ;
if ( * V_130 && V_66 -> V_87 ) {
V_131 -> V_144 = F_96 ( V_66 -> V_87 , V_166 ) ;
F_97 ( V_66 -> V_87 ) ;
V_66 -> V_87 = NULL ;
if ( V_131 -> V_144 )
F_98 ( V_131 -> V_144 , V_136 ) ;
}
return V_136 ;
V_151:
F_24 ( F_99 ( V_10 ) , V_167 ) ;
V_152:
F_54 ( V_49 ) ;
V_41:
F_24 ( F_99 ( V_10 ) , V_168 ) ;
return NULL ;
}
static int F_100 ( struct V_9 * V_10 , struct V_1 * V_2 )
{
struct V_11 * V_12 = F_4 ( V_10 ) ;
struct V_1 * V_169 = NULL ;
if ( V_2 -> V_103 == F_41 ( V_104 ) )
return V_143 ( V_10 , V_2 ) ;
if ( F_101 ( V_10 , V_2 ) )
goto V_170;
if ( V_12 -> V_113 . V_158 )
V_169 = F_96 ( V_2 , V_166 ) ;
if ( V_10 -> V_36 == V_171 ) {
if ( F_102 ( V_10 , V_2 , V_13 ( V_2 ) , V_2 -> V_6 ) )
goto V_172;
if ( V_169 ) {
F_103 ( V_169 ) ;
}
return 0 ;
}
if ( F_104 ( V_10 , V_2 , V_13 ( V_2 ) , V_2 -> V_6 ) )
goto V_172;
if ( V_169 ) {
F_103 ( V_169 ) ;
}
return 0 ;
V_172:
F_60 ( V_10 , V_2 ) ;
V_170:
if ( V_169 != NULL )
F_103 ( V_169 ) ;
F_59 ( V_2 ) ;
return 0 ;
}
static int F_105 ( struct V_1 * V_2 )
{
const struct V_13 * V_14 ;
bool V_173 ;
struct V_9 * V_10 ;
int V_174 ;
if ( F_106 ( V_2 ) )
goto V_175;
if ( F_1 ( V_2 , & F_8 ( V_2 ) -> V_4 ,
& F_8 ( V_2 ) -> V_5 ) ) {
F_107 ( L_1 ) ;
goto V_175;
}
V_14 = V_13 ( V_2 ) ;
F_69 ( V_2 ) -> V_123 = F_20 ( V_14 ) ;
F_69 ( V_2 ) -> V_176 = V_14 -> V_93 ;
if ( F_108 ( V_2 ) )
F_69 ( V_2 ) -> V_177 = V_178 ;
else
F_69 ( V_2 ) -> V_177 = F_109 ( V_2 ) ;
V_179:
V_10 = F_110 ( & V_34 , V_2 , F_111 ( V_14 ) ,
V_14 -> V_19 , V_14 -> V_18 ,
F_15 ( V_2 ) , & V_173 ) ;
if ( ! V_10 ) {
F_112 ( L_2
L_3 ) ;
goto V_180;
}
if ( V_10 -> V_36 == V_37 ) {
F_112 ( L_4 ) ;
F_18 ( F_19 ( V_10 ) ) ;
goto V_180;
}
if ( V_10 -> V_36 == V_38 ) {
struct V_63 * V_64 = F_113 ( V_10 ) ;
struct V_9 * V_181 ;
V_10 = V_64 -> V_182 ;
if ( F_114 ( V_10 -> V_36 != V_183 ) ) {
F_115 ( V_10 , V_64 ) ;
goto V_179;
}
F_116 ( V_10 ) ;
V_173 = true ;
V_181 = F_117 ( V_10 , V_2 , V_64 ) ;
if ( ! V_181 ) {
F_118 ( V_64 ) ;
goto V_184;
}
if ( V_181 == V_10 ) {
F_118 ( V_64 ) ;
} else if ( F_119 ( V_10 , V_181 , V_2 ) ) {
F_60 ( V_10 , V_2 ) ;
goto V_184;
} else {
F_38 ( V_10 ) ;
return 0 ;
}
}
V_174 = F_25 ( V_10 ) -> V_185 ;
if ( V_14 -> V_186 && ( V_174 == 0 || V_14 -> V_186 < V_174 ) ) {
F_112 ( L_5 ,
V_14 -> V_186 , V_174 ) ;
goto V_184;
}
if ( ! F_120 ( V_10 , V_187 , V_2 ) )
goto V_184;
return F_121 ( V_10 , V_2 , 1 , V_14 -> V_188 * 4 ,
V_173 ) ? - 1 : 0 ;
V_180:
if ( ! F_120 ( NULL , V_187 , V_2 ) )
goto V_175;
if ( V_14 -> V_93 != V_94 ) {
F_69 ( V_2 ) -> V_105 =
V_189 ;
F_60 ( V_10 , V_2 ) ;
}
V_175:
F_59 ( V_2 ) ;
return 0 ;
V_184:
if ( V_173 )
F_38 ( V_10 ) ;
goto V_175;
}
static int F_122 ( struct V_9 * V_10 , struct V_190 * V_191 ,
int V_192 )
{
struct V_193 * V_194 = (struct V_193 * ) V_191 ;
struct V_195 * V_196 = F_31 ( V_10 ) ;
struct V_132 * V_197 = F_86 ( V_10 ) ;
struct V_11 * V_12 = F_4 ( V_10 ) ;
struct V_28 * V_29 = F_25 ( V_10 ) ;
struct V_3 * V_4 = NULL , * V_67 , V_68 ;
struct V_82 * V_21 ;
struct V_69 V_70 ;
struct V_48 * V_49 ;
int V_198 ;
int V_30 ;
V_29 -> V_199 = V_200 ;
if ( V_192 < V_201 )
return - V_202 ;
if ( V_194 -> V_203 != V_112 )
return - V_204 ;
memset ( & V_70 , 0 , sizeof( V_70 ) ) ;
if ( V_12 -> V_205 ) {
V_70 . V_74 = V_194 -> V_206 & V_207 ;
F_123 ( V_70 . V_74 ) ;
if ( V_70 . V_74 & V_208 ) {
struct V_209 * V_74 ;
V_74 = F_124 ( V_10 , V_70 . V_74 ) ;
if ( V_74 == NULL )
return - V_202 ;
F_125 ( V_74 ) ;
}
}
if ( F_126 ( & V_194 -> V_210 ) )
V_194 -> V_210 . V_211 [ 15 ] = 1 ;
V_198 = F_81 ( & V_194 -> V_210 ) ;
if ( V_198 & V_212 )
return - V_213 ;
if ( V_198 & V_121 ) {
if ( V_192 >= sizeof( struct V_193 ) &&
V_194 -> V_214 ) {
if ( V_10 -> V_120 &&
V_10 -> V_120 != V_194 -> V_214 )
return - V_202 ;
V_10 -> V_120 = V_194 -> V_214 ;
}
if ( ! V_10 -> V_120 )
return - V_202 ;
}
V_10 -> V_16 = V_194 -> V_210 ;
V_12 -> V_215 = V_70 . V_74 ;
if ( V_198 == V_216 ) {
T_5 V_217 = V_196 -> V_159 ;
struct V_218 sin ;
F_127 ( V_10 , L_6 ) ;
if ( F_128 ( V_10 ) )
return - V_213 ;
sin . V_219 = V_220 ;
sin . V_221 = V_194 -> V_222 ;
sin . V_223 . V_224 = V_194 -> V_210 . V_17 [ 3 ] ;
V_196 -> V_140 = & V_141 ;
V_10 -> V_142 = V_143 ;
V_30 = F_129 ( V_10 , (struct V_190 * ) & sin , sizeof( sin ) ) ;
if ( V_30 ) {
V_196 -> V_159 = V_217 ;
V_196 -> V_140 = & V_225 ;
V_10 -> V_142 = F_100 ;
goto V_226;
}
V_12 -> V_4 = V_10 -> V_139 ;
return V_30 ;
}
if ( ! F_126 ( & V_10 -> V_139 ) )
V_4 = & V_10 -> V_139 ;
V_70 . V_71 = V_7 ;
V_70 . V_5 = V_10 -> V_16 ;
V_70 . V_4 = V_4 ? * V_4 : V_12 -> V_4 ;
V_70 . V_75 = V_10 -> V_120 ;
V_70 . V_77 = V_194 -> V_222 ;
V_70 . V_79 = V_197 -> V_227 ;
F_130 ( V_10 , F_43 ( & V_70 ) ) ;
V_21 = F_131 ( V_12 -> V_21 , F_132 ( V_10 ) ) ;
V_67 = F_45 ( & V_70 , V_21 , & V_68 ) ;
V_49 = F_48 ( V_10 , & V_70 , V_67 ) ;
if ( F_49 ( V_49 ) ) {
V_30 = F_50 ( V_49 ) ;
goto V_226;
}
if ( V_4 == NULL ) {
V_4 = & V_70 . V_4 ;
V_10 -> V_139 = * V_4 ;
}
V_12 -> V_4 = * V_4 ;
V_197 -> V_165 = V_164 ;
F_89 ( V_10 , V_49 , NULL , NULL ) ;
V_196 -> V_159 = 0 ;
if ( V_21 )
V_196 -> V_159 = V_21 -> V_161 + V_21 -> V_160 ;
V_197 -> V_228 = V_194 -> V_222 ;
F_133 ( V_10 , V_56 ) ;
V_30 = F_134 ( & V_229 , V_10 ) ;
if ( V_30 )
goto V_230;
V_29 -> V_231 = F_7 ( V_12 -> V_4 . V_17 ,
V_10 -> V_16 . V_17 ,
V_197 -> V_227 ,
V_197 -> V_228 ) ;
V_30 = F_135 ( V_10 ) ;
if ( V_30 )
goto V_230;
return 0 ;
V_230:
F_133 ( V_10 , V_40 ) ;
F_136 ( V_10 ) ;
V_226:
V_197 -> V_228 = 0 ;
V_10 -> V_153 = 0 ;
return V_30 ;
}
static int F_137 ( struct V_9 * V_10 )
{
static T_6 V_232 ;
int V_30 = F_138 ( V_10 , V_232 ) ;
if ( V_30 == 0 ) {
if ( F_114 ( ! V_232 ) )
V_232 = 1 ;
F_31 ( V_10 ) -> V_140 = & V_225 ;
}
return V_30 ;
}
static void F_139 ( struct V_9 * V_10 )
{
F_140 ( V_10 ) ;
F_141 ( V_10 ) ;
}
static int T_7 F_142 ( struct V_32 * V_32 )
{
if ( V_34 . V_233 == NULL )
return - V_234 ;
return F_143 ( & V_32 -> V_91 . V_92 , V_235 ,
V_236 , V_7 , V_32 ) ;
}
static void T_8 F_144 ( struct V_32 * V_32 )
{
F_145 ( V_32 -> V_91 . V_92 ) ;
}
static void T_8 F_146 ( struct V_237 * V_238 )
{
F_147 ( & V_34 , V_112 ) ;
}
static int T_9 F_148 ( void )
{
int V_30 = F_149 ( & V_239 , 1 ) ;
if ( V_30 != 0 )
goto V_41;
V_30 = F_150 ( & V_240 , V_7 ) ;
if ( V_30 != 0 )
goto V_241;
F_151 ( & V_242 ) ;
V_30 = F_152 ( & V_243 ) ;
if ( V_30 != 0 )
goto V_244;
V_41:
return V_30 ;
V_244:
F_153 ( & V_240 , V_7 ) ;
F_154 ( & V_242 ) ;
V_241:
F_155 ( & V_239 ) ;
goto V_41;
}
static void T_10 F_156 ( void )
{
F_157 ( & V_243 ) ;
F_153 ( & V_240 , V_7 ) ;
F_154 ( & V_242 ) ;
F_155 ( & V_239 ) ;
}
