static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 ;
struct V_3 * V_9 ;
T_1 V_10 [ V_11 ] ;
const struct V_12 * V_13 ;
V_2 -> V_4 = V_4 ;
V_13 = V_4 -> V_14 ;
if ( V_13 -> V_15 ) {
if ( V_13 -> V_15 ( V_4 ) )
F_3 ( V_4 , L_1
L_2 ) ;
}
if ( V_4 -> V_16 & V_17 && V_4 -> V_18 & V_19 ) {
F_3 ( V_4 , L_3 ) ;
return - V_20 ;
}
V_9 = F_4 ( V_4 ) ? F_5 ( V_4 ) : V_4 ;
V_2 -> V_21 = V_9 ;
F_6 () ;
F_7 (real_dev, ha) {
if ( ( V_8 -> type == V_22 ) &&
( F_8 ( V_8 -> V_23 ) ) ) {
memcpy ( V_6 -> V_24 , V_8 -> V_23 , V_11 ) ;
V_6 -> V_25 = 1 ;
break;
}
}
F_9 () ;
if ( ! V_6 -> V_25 )
memcpy ( V_6 -> V_24 , V_4 -> V_26 , V_4 -> V_27 ) ;
memcpy ( V_10 , ( T_1 [ 6 ] ) V_28 , V_11 ) ;
F_10 ( V_4 , V_10 ) ;
if ( V_6 -> V_25 )
F_10 ( V_4 , V_6 -> V_24 ) ;
if ( V_6 -> V_29 == V_30 ) {
F_11 ( V_4 , V_31 ) ;
F_11 ( V_4 , V_32 ) ;
} else
F_11 ( V_4 , V_33 ) ;
V_2 -> V_34 . V_35 = V_36 ;
V_2 -> V_34 . type = F_12 ( V_37 ) ;
V_2 -> V_34 . V_38 = V_4 ;
F_13 ( & V_2 -> V_34 ) ;
V_2 -> V_39 . V_35 = V_40 ;
V_2 -> V_39 . type = F_12 ( V_41 ) ;
V_2 -> V_39 . V_38 = V_4 ;
F_13 ( & V_2 -> V_39 ) ;
if ( V_4 != V_9 ) {
V_2 -> V_42 . V_35 = V_43 ;
V_2 -> V_42 . type = F_12 ( V_41 ) ;
V_2 -> V_42 . V_38 = V_9 ;
F_13 ( & V_2 -> V_42 ) ;
}
return 0 ;
}
static struct V_1 * F_14 ( struct V_3 * V_4 ,
enum V_44 V_45 )
{
struct V_46 * V_47 ;
struct V_5 * V_48 ;
struct V_1 * V_2 ;
int V_49 ;
int V_50 ;
if ( ! F_15 ( V_51 ) ) {
F_3 ( V_4 ,
L_4 ) ;
V_2 = F_16 ( - V_52 ) ;
goto V_53;
}
V_49 = sizeof( struct V_5 ) + sizeof( struct V_1 ) ;
V_47 = F_17 ( & V_4 -> V_38 , & V_54 ,
V_49 ) ;
if ( ! V_47 ) {
F_18 ( L_5 ) ;
V_2 = F_16 ( - V_55 ) ;
goto V_56;
}
V_48 = F_19 ( V_47 ) ;
V_48 -> V_57 = V_47 ;
V_2 = F_20 ( V_48 ) ;
F_21 ( V_4 ) ;
F_22 ( V_48 , V_45 ) ;
V_48 -> V_58 = V_59 ;
V_48 -> V_60 = V_61 ;
V_48 -> V_62 = V_63 ;
V_50 = F_1 ( V_2 , V_4 ) ;
if ( V_50 ) {
F_23 ( V_48 ) ;
F_24 ( V_47 ) ;
F_25 ( V_4 ) ;
V_2 = F_16 ( V_50 ) ;
goto V_56;
}
goto V_53;
V_56:
F_26 ( V_51 ) ;
V_53:
return V_2 ;
}
static void F_27 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
T_1 V_10 [ V_11 ] ;
const struct V_12 * V_13 ;
F_28 ( & V_2 -> V_34 ) ;
F_28 ( & V_2 -> V_39 ) ;
if ( V_4 != V_2 -> V_21 )
F_28 ( & V_2 -> V_42 ) ;
F_29 () ;
memcpy ( V_10 , ( T_1 [ 6 ] ) V_28 , V_11 ) ;
F_30 ( V_4 , V_10 ) ;
if ( V_6 -> V_25 )
F_30 ( V_4 , V_6 -> V_24 ) ;
if ( V_6 -> V_29 == V_30 ) {
F_31 ( V_4 , V_31 ) ;
F_31 ( V_4 , V_32 ) ;
} else
F_31 ( V_4 , V_33 ) ;
V_13 = V_4 -> V_14 ;
if ( V_13 -> V_64 ) {
if ( V_13 -> V_64 ( V_4 ) )
F_3 ( V_4 , L_6
L_2 ) ;
}
V_2 -> V_65 = 1 ;
}
static void F_32 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
F_33 () ;
if ( ! V_2 -> V_65 )
F_27 ( V_2 ) ;
F_34 () ;
F_23 ( V_6 ) ;
F_35 ( V_6 -> V_66 -> V_67 ) ;
F_25 ( V_4 ) ;
F_26 ( V_51 ) ;
}
static int V_40 ( struct V_68 * V_69 , struct V_3 * V_4 ,
struct V_70 * V_71 ,
struct V_3 * V_72 )
{
struct V_1 * V_2 ;
struct V_5 * V_48 ;
V_2 = F_36 ( V_71 , struct V_1 , V_39 ) ;
V_48 = F_2 ( V_2 ) ;
F_37 ( V_48 , V_69 ) ;
return 0 ;
}
static int V_43 ( struct V_68 * V_69 , struct V_3 * V_4 ,
struct V_70 * V_71 ,
struct V_3 * V_72 )
{
struct V_1 * V_2 ;
struct V_5 * V_48 ;
V_2 = F_36 ( V_71 , struct V_1 , V_42 ) ;
V_48 = F_2 ( V_2 ) ;
F_37 ( V_48 , V_69 ) ;
return 0 ;
}
static void F_38 ( struct V_73 * V_74 , struct V_68 * V_69 )
{
if ( V_74 -> V_75 . V_76 )
F_39 ( V_74 -> V_77 , V_69 ) ;
else if ( F_40 ( V_69 ) )
F_39 ( V_74 -> V_77 , V_69 ) ;
}
static void V_59 ( struct V_5 * V_6 , struct V_68 * V_69 )
{
struct V_1 * V_2 = F_41 ( V_6 ) ;
struct V_78 {
struct V_79 V_80 ;
struct V_81 V_6 ;
} V_82 * V_83 ;
V_83 = (struct V_78 * ) V_69 -> V_84 ;
if ( F_42 ( V_83 -> V_80 . V_85 ) == V_41 &&
F_42 ( V_83 -> V_6 . V_86 ) == V_87 &&
V_2 -> V_21 != V_2 -> V_4 )
V_69 -> V_38 = V_2 -> V_21 ;
else
V_69 -> V_38 = V_2 -> V_4 ;
F_38 ( F_43 ( V_6 -> V_66 ) , V_69 ) ;
}
static void V_61 ( struct V_88 * V_77 , T_1 * V_23 )
{
struct V_73 * V_74 = F_43 ( V_77 ) ;
struct V_1 * V_2 = V_74 -> V_89 ;
if ( ! F_44 ( V_74 -> V_90 ) )
F_30 ( V_2 -> V_4 , V_74 -> V_90 ) ;
if ( ! F_44 ( V_23 ) )
F_10 ( V_2 -> V_4 , V_23 ) ;
memcpy ( V_74 -> V_90 , V_23 , V_11 ) ;
}
static T_1 * V_63 ( struct V_88 * V_77 )
{
struct V_73 * V_74 = F_43 ( V_77 ) ;
return V_74 -> V_90 ;
}
static int F_45 ( struct V_88 * V_77 )
{
V_77 -> V_91 = 0 ;
V_77 -> V_92 = 0 ;
V_77 -> V_93 = 3 ;
V_77 -> V_94 = 3 ;
V_77 -> V_95 = V_96 ;
V_77 -> V_97 = V_98 ;
V_77 -> V_99 = ( V_100 | V_101 |
V_102 | V_103 ) ;
V_77 -> V_104 = 1 ;
F_46 ( V_77 ) ;
F_47 ( V_77 ) ;
V_77 -> V_105 = 0 ;
V_77 -> V_106 = 0 ;
V_77 -> V_107 = 0 ;
V_77 -> V_108 = 0 ;
V_77 -> V_109 = 0 ;
return 0 ;
}
static void F_48 ( struct V_88 * V_77 ,
struct V_3 * V_4 )
{
F_49 ( & V_77 -> V_110 ) ;
if ( V_4 -> V_111 & V_112 )
V_77 -> V_113 = 1 ;
else
V_77 -> V_113 = 0 ;
if ( V_4 -> V_111 & V_114 ) {
V_77 -> V_105 = 1 ;
F_3 ( V_4 , L_7 ) ;
} else {
V_77 -> V_105 = 0 ;
}
if ( V_4 -> V_111 & V_115 ) {
V_77 -> V_106 = 1 ;
V_77 -> V_109 = V_4 -> V_116 ;
F_3 ( V_4 , L_8 ,
V_77 -> V_109 ) ;
} else {
V_77 -> V_106 = 0 ;
V_77 -> V_109 = 0 ;
}
if ( V_4 -> V_117 ) {
V_77 -> V_107 = 1 ;
V_77 -> V_108 = V_4 -> V_117 ;
F_3 ( V_4 , L_9 ,
V_77 -> V_108 ) ;
} else {
V_77 -> V_107 = 0 ;
V_77 -> V_108 = 0 ;
}
F_50 ( & V_77 -> V_110 ) ;
}
static int F_51 ( struct V_88 * V_77 , struct V_3 * V_4 )
{
T_2 V_118 ;
T_3 V_119 , V_120 ;
struct V_1 * V_2 ;
struct V_5 * V_48 ;
struct V_73 * V_74 ;
V_74 = F_43 ( V_77 ) ;
V_2 = V_74 -> V_89 ;
V_48 = F_2 ( V_2 ) ;
if ( F_4 ( V_4 ) )
V_77 -> V_121 = F_52 ( V_4 ) ;
else
V_77 -> V_121 = 0 ;
V_118 = V_4 -> V_122 ;
if ( V_4 -> V_111 & V_123 ) {
V_118 = V_124 ;
F_3 ( V_4 , L_10 , V_118 ) ;
}
V_118 -= ( sizeof( struct V_125 ) + sizeof( struct V_126 ) ) ;
if ( F_53 ( V_77 , V_118 ) )
return - V_127 ;
F_48 ( V_77 , V_4 ) ;
F_54 ( & V_74 -> V_75 ) ;
V_74 -> V_128 = 0 ;
F_55 ( & V_74 -> V_129 , V_130 , ( unsigned long ) V_77 ) ;
F_56 ( V_77 ) ;
if ( ! V_77 -> V_131 ) {
if ( F_57 ( V_4 , & V_119 , V_132 ) )
V_119 = F_58 ( V_48 -> V_24 , 1 , 0 ) ;
F_59 ( V_77 , V_119 ) ;
if ( F_57 ( V_4 , & V_120 , V_133 ) )
V_120 = F_58 ( V_48 -> V_24 ,
2 , 0 ) ;
F_60 ( V_77 , V_120 ) ;
}
return 0 ;
}
static int F_61 ( struct V_88 * V_77 , struct V_134 * V_38 )
{
int V_135 = 0 ;
V_77 -> V_67 -> V_136 = V_137 ;
V_77 -> V_67 -> V_138 = V_139 ;
V_77 -> V_67 -> V_140 = 0 ;
V_77 -> V_67 -> V_141 = V_142 ;
if ( V_77 -> V_131 )
V_77 -> V_67 -> V_143 = V_144 ;
else
V_77 -> V_67 -> V_143 = V_145 ;
V_135 = F_62 ( V_77 -> V_67 , V_38 ) ;
if ( V_135 ) {
F_3 ( F_63 ( V_77 ) , L_11
L_12 ) ;
return V_135 ;
}
if ( ! V_77 -> V_131 )
F_64 ( V_77 -> V_67 ) = V_146 ;
snprintf ( F_65 ( V_77 -> V_67 ) , V_147 ,
L_13 , V_148 , V_149 ,
F_63 ( V_77 ) -> V_150 ) ;
return 0 ;
}
static void F_66 ( struct V_88 * V_77 , struct V_3 * V_4 )
{
struct V_1 * V_2 ;
struct V_73 * V_74 ;
struct V_3 * V_21 ;
int V_135 ;
V_74 = F_43 ( V_77 ) ;
V_2 = V_74 -> V_89 ;
V_21 = V_2 -> V_21 ;
if ( V_77 -> V_131 )
return;
if ( V_21 -> V_14 -> V_151 ) {
struct V_152 * V_153 ;
V_153 = F_67 ( sizeof( * V_153 ) , V_154 ) ;
if ( ! V_153 )
return;
V_135 = V_21 -> V_14 -> V_151 ( V_21 ,
V_153 ) ;
if ( V_135 ) {
F_68 ( V_155 L_14
L_15 ) ;
return;
}
snprintf ( F_69 ( V_77 -> V_67 ) ,
V_156 ,
L_16 ,
V_153 -> V_157 ) ;
snprintf ( F_70 ( V_77 -> V_67 ) ,
V_156 ,
L_16 ,
V_153 -> V_158 ) ;
snprintf ( F_71 ( V_77 -> V_67 ) ,
V_147 ,
L_16 ,
V_153 -> V_159 ) ;
snprintf ( F_72 ( V_77 -> V_67 ) ,
V_147 ,
L_16 ,
V_153 -> V_160 ) ;
snprintf ( F_73 ( V_77 -> V_67 ) ,
V_161 ,
L_16 ,
V_153 -> V_162 ) ;
snprintf ( F_74 ( V_77 -> V_67 ) ,
V_161 ,
L_16 ,
V_153 -> V_163 ) ;
snprintf ( F_75 ( V_77 -> V_67 ) ,
V_161 ,
L_16 ,
V_153 -> V_164 ) ;
snprintf ( F_76 ( V_77 -> V_67 ) ,
V_161 ,
L_16 ,
V_153 -> V_165 ) ;
V_77 -> V_166 = 1 ;
F_77 ( V_153 ) ;
} else {
V_77 -> V_166 = 0 ;
F_68 ( V_155 L_17 ) ;
}
}
static bool F_78 ( struct V_167 * V_168 )
{
struct V_169 * V_170 = F_79 ( V_168 ) ;
struct V_171 * V_172 ;
if ( F_80 ( F_81 ( V_168 ) ) &&
( F_81 ( V_168 ) -> V_173 > V_174 ) )
return true ;
else if ( ( F_81 ( V_168 ) == NULL ) &&
( V_170 -> V_175 == V_176 ) &&
( F_42 ( V_170 -> V_177 ) == V_178 ) ) {
V_172 = F_82 ( V_168 , sizeof( * V_172 ) ) ;
if ( ( V_172 -> V_179 & V_180 ) &&
( F_83 ( V_172 -> V_181 ) > V_174 ) )
return true ;
}
return false ;
}
static inline int F_84 ( struct V_88 * V_77 )
{
struct V_73 * V_74 = F_43 ( V_77 ) ;
struct V_1 * V_2 = V_74 -> V_89 ;
struct V_1 * V_182 = NULL ;
struct V_3 * V_183 , * V_184 ;
T_4 V_185 = V_186 ;
T_4 V_187 = V_188 ;
if ( ! V_77 -> V_107 || ! V_77 -> V_108 ||
( V_77 -> V_108 >= V_187 ) ) {
V_77 -> V_108 = 0 ;
goto V_189;
}
if ( F_4 ( V_2 -> V_4 ) )
V_184 = F_5 ( V_2 -> V_4 ) ;
else
V_184 = V_2 -> V_4 ;
F_85 (oldfcoe, &fcoe_hostlist, list) {
if ( F_4 ( V_182 -> V_4 ) )
V_183 = F_5 ( V_182 -> V_4 ) ;
else
V_183 = V_182 -> V_4 ;
if ( V_184 == V_183 ) {
V_2 -> V_190 = V_182 -> V_190 ;
break;
}
}
if ( V_2 -> V_190 ) {
if ( ! F_86 ( V_77 , V_2 -> V_190 , F_78 ) ) {
F_68 ( V_191 L_18
L_19 ,
V_2 -> V_190 , V_2 -> V_4 -> V_150 ) ;
return - V_55 ;
}
} else {
V_2 -> V_190 = F_87 ( V_77 , V_192 ,
V_186 , V_77 -> V_108 ,
F_78 ) ;
if ( ! V_2 -> V_190 ) {
F_68 ( V_191 L_20
L_21 ,
V_2 -> V_4 -> V_150 ) ;
return - V_55 ;
}
}
V_185 += V_77 -> V_108 + 1 ;
V_189:
if ( ! F_87 ( V_77 , V_192 , V_185 , V_187 , NULL ) ) {
F_68 ( V_191 L_22
L_23 , V_2 -> V_4 -> V_150 ) ;
return - V_55 ;
}
return 0 ;
}
static void F_88 ( struct V_88 * V_77 )
{
struct V_73 * V_74 = F_43 ( V_77 ) ;
struct V_1 * V_2 = V_74 -> V_89 ;
struct V_3 * V_4 = V_2 -> V_4 ;
F_3 ( V_4 , L_24 ) ;
F_89 ( V_77 ) ;
F_90 ( V_77 ) ;
F_91 ( & V_74 -> V_129 ) ;
F_92 ( V_77 ) ;
F_33 () ;
if ( ! F_44 ( V_74 -> V_90 ) )
F_30 ( V_4 , V_74 -> V_90 ) ;
if ( V_77 -> V_131 )
F_29 () ;
else
F_27 ( V_2 ) ;
F_34 () ;
F_93 ( V_77 ) ;
F_94 ( V_77 -> V_67 ) ;
F_95 ( V_77 -> V_67 ) ;
F_96 ( V_77 ) ;
F_97 ( V_77 ) ;
F_98 ( V_77 ) ;
if ( V_77 -> V_131 )
F_35 ( V_77 -> V_67 ) ;
}
static int F_99 ( struct V_88 * V_77 , T_4 V_193 ,
struct V_194 * V_195 , unsigned int V_196 )
{
struct V_3 * V_4 = F_63 ( V_77 ) ;
if ( V_4 -> V_14 -> V_197 )
return V_4 -> V_14 -> V_197 ( V_4 ,
V_193 , V_195 ,
V_196 ) ;
return 0 ;
}
static int F_100 ( struct V_88 * V_77 , T_4 V_193 ,
struct V_194 * V_195 , unsigned int V_196 )
{
struct V_3 * V_4 = F_63 ( V_77 ) ;
if ( V_4 -> V_14 -> V_198 )
return V_4 -> V_14 -> V_198 ( V_4 , V_193 ,
V_195 , V_196 ) ;
return 0 ;
}
static int F_101 ( struct V_88 * V_77 , T_4 V_193 )
{
struct V_3 * V_4 = F_63 ( V_77 ) ;
if ( V_4 -> V_14 -> V_199 )
return V_4 -> V_14 -> V_199 ( V_4 , V_193 ) ;
return 0 ;
}
static struct V_88 * F_102 ( struct V_1 * V_2 ,
struct V_134 * V_200 , int V_201 )
{
struct V_5 * V_48 = F_2 ( V_2 ) ;
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_88 * V_77 , * V_202 ;
struct V_73 * V_74 ;
struct V_203 * V_204 ;
int V_135 ;
struct V_205 * V_131 = F_103 ( V_200 ) ;
F_3 ( V_4 , L_25 ) ;
if ( ! V_201 )
V_77 = F_104 ( & V_206 , sizeof( * V_74 ) ) ;
else
V_77 = F_105 ( V_131 , sizeof( * V_74 ) ) ;
if ( ! V_77 ) {
F_3 ( V_4 , L_26 ) ;
V_135 = - V_55 ;
goto V_53;
}
V_74 = F_43 ( V_77 ) ;
V_74 -> V_77 = V_77 ;
V_74 -> V_89 = V_2 ;
V_74 -> V_207 = F_63 ;
V_74 -> V_208 = V_209 ;
V_74 -> V_210 = V_211 ;
F_106 ( & V_74 -> V_212 , V_213 ) ;
F_107 ( V_77 ) ;
V_135 = F_45 ( V_77 ) ;
if ( V_135 ) {
F_3 ( V_4 , L_27
L_28 ) ;
goto V_214;
}
if ( V_201 ) {
F_3 ( V_4 , L_29
L_30 ,
V_131 -> V_215 , V_131 -> V_216 ) ;
F_59 ( V_77 , V_131 -> V_215 ) ;
F_60 ( V_77 , V_131 -> V_216 ) ;
}
V_135 = F_51 ( V_77 , V_4 ) ;
if ( V_135 ) {
F_3 ( V_4 , L_31
L_28 ) ;
goto V_217;
}
V_135 = F_61 ( V_77 , V_200 ) ;
if ( V_135 ) {
F_3 ( V_4 , L_32
L_28 ) ;
goto V_217;
}
V_135 = F_108 ( V_77 , V_48 , & V_218 , 1 ) ;
if ( V_135 ) {
F_3 ( V_4 , L_33
L_28 ) ;
goto V_217;
}
F_66 ( V_77 , V_4 ) ;
if ( ! V_201 )
V_135 = F_84 ( V_77 ) ;
else {
V_204 = F_109 ( V_131 ) ;
V_202 = F_110 ( V_204 ) ;
V_135 = F_111 ( V_202 , V_77 ) ;
}
if ( V_135 ) {
F_3 ( V_4 , L_34 ) ;
goto V_217;
}
return V_77 ;
V_217:
F_97 ( V_77 ) ;
V_214:
F_112 ( V_77 ) ;
F_35 ( V_77 -> V_67 ) ;
V_53:
return F_16 ( V_135 ) ;
}
static int T_5 F_113 ( void )
{
V_145 =
F_114 ( & V_219 ) ;
V_144 =
F_114 ( & V_220 ) ;
if ( ! V_145 ) {
F_68 ( V_191 L_35 ) ;
return - V_221 ;
}
return 0 ;
}
static int T_6 F_115 ( void )
{
F_116 ( V_145 ) ;
F_116 ( V_144 ) ;
V_145 = NULL ;
V_144 = NULL ;
return 0 ;
}
static void F_117 ( unsigned int V_222 )
{
struct V_223 * V_224 ;
struct V_225 * V_226 ;
V_226 = F_118 ( & V_227 , V_222 ) ;
F_119 ( & V_226 -> V_228 . V_229 ) ;
V_224 = V_226 -> V_230 ;
V_226 -> V_230 = NULL ;
V_226 -> V_231 = 0 ;
F_120 ( & V_226 -> V_228 . V_229 ) ;
if ( V_224 )
F_121 ( V_224 ) ;
F_122 ( & V_226 -> V_232 ) ;
}
static inline unsigned int F_123 ( void )
{
static unsigned int V_233 ;
V_233 = F_124 ( V_233 , V_234 ) ;
if ( V_233 >= V_235 )
V_233 = F_125 ( V_234 ) ;
return V_233 ;
}
static int V_36 ( struct V_68 * V_69 , struct V_3 * V_4 ,
struct V_70 * V_71 , struct V_3 * V_236 )
{
struct V_88 * V_77 ;
struct V_237 * V_238 ;
struct V_5 * V_48 ;
struct V_1 * V_2 ;
struct V_169 * V_170 ;
struct V_225 * V_239 ;
struct V_79 * V_240 ;
unsigned int V_222 ;
V_2 = F_36 ( V_71 , struct V_1 , V_34 ) ;
V_48 = F_2 ( V_2 ) ;
V_77 = V_48 -> V_66 ;
if ( F_126 ( ! V_77 ) ) {
F_3 ( V_4 , L_36 ) ;
goto V_241;
}
if ( ! V_77 -> V_91 )
goto V_241;
F_3 ( V_4 ,
L_37 ,
V_69 -> V_242 , V_69 -> V_173 , V_69 -> V_243 , V_69 -> V_84 ,
F_127 ( V_69 ) , F_128 ( V_69 ) ,
V_69 -> V_244 , V_69 -> V_38 ? V_69 -> V_38 -> V_150 : L_38 ) ;
V_69 = F_129 ( V_69 , V_245 ) ;
if ( V_69 == NULL )
return V_246 ;
V_240 = F_130 ( V_69 ) ;
if ( F_131 ( V_48 ) &&
! F_132 ( V_240 -> V_247 , V_48 -> V_248 ) ) {
F_3 ( V_4 , L_39 ,
V_240 -> V_247 ) ;
goto V_50;
}
if ( F_126 ( ( V_69 -> V_242 < V_249 ) ||
! F_133 ( V_69 , V_250 ) ) )
goto V_50;
F_134 ( V_69 , sizeof( struct V_125 ) ) ;
V_170 = (struct V_169 * ) F_135 ( V_69 ) ;
if ( F_136 ( & V_240 -> V_251 [ 3 ] ) != F_136 ( V_170 -> V_252 ) ) {
F_3 ( V_4 , L_40 ,
V_240 -> V_251 ) ;
goto V_50;
}
V_238 = F_137 ( V_69 ) ;
V_238 -> V_253 = V_77 ;
if ( F_136 ( V_170 -> V_254 ) & V_255 )
V_222 = F_42 ( V_170 -> V_256 ) & V_257 ;
else {
if ( F_42 ( V_170 -> V_177 ) == V_178 )
V_222 = F_123 () ;
else
V_222 = F_42 ( V_170 -> V_177 ) & V_257 ;
}
if ( V_222 >= V_235 )
goto V_50;
V_239 = & F_138 ( V_227 , V_222 ) ;
F_139 ( & V_239 -> V_228 . V_229 ) ;
F_140 ( & V_239 -> V_228 , V_69 ) ;
F_141 ( V_222 , & V_239 -> V_232 ) ;
F_142 ( & V_239 -> V_228 . V_229 ) ;
return V_258 ;
V_50:
F_118 ( V_77 -> V_259 , F_143 () ) -> V_260 ++ ;
F_144 () ;
V_241:
F_145 ( V_69 ) ;
return V_246 ;
}
static int F_146 ( struct V_68 * V_69 , int V_261 )
{
struct V_225 * V_239 ;
int V_135 ;
V_239 = & F_147 ( V_227 ) ;
V_135 = F_148 ( V_69 , V_261 , V_239 ) ;
F_149 ( V_227 ) ;
return V_135 ;
}
static int F_150 ( struct V_88 * V_77 , struct V_167 * V_168 )
{
int V_262 ;
T_2 V_263 ;
struct V_79 * V_240 ;
struct V_126 * V_264 ;
struct V_68 * V_69 ;
struct V_265 * V_259 ;
struct V_169 * V_170 ;
unsigned int V_266 ;
unsigned int V_261 ;
unsigned int V_267 ;
struct V_73 * V_74 = F_43 ( V_77 ) ;
struct V_1 * V_2 = V_74 -> V_89 ;
struct V_5 * V_48 = F_2 ( V_2 ) ;
T_1 V_268 , V_269 ;
struct V_125 * V_270 ;
F_151 ( ( F_152 ( V_168 ) % sizeof( T_2 ) ) != 0 ) ;
V_170 = F_79 ( V_168 ) ;
V_69 = F_153 ( V_168 ) ;
V_262 = V_69 -> V_242 / V_271 ;
if ( ! V_77 -> V_91 ) {
F_145 ( V_69 ) ;
return 0 ;
}
if ( F_126 ( V_170 -> V_272 == V_273 ) &&
F_154 ( V_48 , V_77 , V_69 ) )
return 0 ;
V_268 = F_155 ( V_168 ) ;
V_269 = F_156 ( V_168 ) ;
V_267 = sizeof( struct V_79 ) ;
V_266 = sizeof( struct V_125 ) ;
V_261 = sizeof( struct V_126 ) ;
V_262 = ( V_69 -> V_242 - V_261 + sizeof( V_263 ) ) / V_271 ;
if ( F_157 ( V_77 -> V_105 ) ) {
V_69 -> V_274 = V_275 ;
V_69 -> V_276 = F_158 ( V_69 ) ;
V_69 -> V_277 = V_69 -> V_242 ;
V_263 = 0 ;
} else {
V_69 -> V_274 = V_278 ;
V_263 = F_159 ( V_168 ) ;
}
if ( F_160 ( V_69 ) ) {
T_7 * V_279 ;
if ( F_146 ( V_69 , V_261 ) ) {
F_145 ( V_69 ) ;
return - V_55 ;
}
V_279 = & F_161 ( V_69 ) -> V_280 [ F_161 ( V_69 ) -> V_281 - 1 ] ;
V_264 = F_162 ( F_163 ( V_279 ) )
+ V_279 -> V_282 ;
} else {
V_264 = (struct V_126 * ) F_164 ( V_69 , V_261 ) ;
}
memset ( V_264 , 0 , sizeof( * V_264 ) ) ;
V_264 -> V_283 = V_269 ;
V_264 -> V_284 = F_165 ( ~ V_263 ) ;
if ( F_160 ( V_69 ) ) {
F_166 ( V_264 ) ;
V_264 = NULL ;
}
F_167 ( V_69 , V_267 + V_266 ) ;
F_168 ( V_69 ) ;
F_169 ( V_69 ) ;
V_69 -> V_285 = V_267 ;
V_69 -> V_286 = F_12 ( V_37 ) ;
V_69 -> V_287 = V_2 -> V_287 ;
if ( F_4 ( V_2 -> V_4 ) &&
V_2 -> V_21 -> V_111 & V_288 ) {
V_69 -> V_38 = V_2 -> V_21 ;
F_170 ( V_69 , F_12 ( V_289 ) ,
F_52 ( V_2 -> V_4 ) ) ;
} else
V_69 -> V_38 = V_2 -> V_4 ;
V_240 = F_130 ( V_69 ) ;
V_240 -> V_85 = F_12 ( V_37 ) ;
memcpy ( V_240 -> V_251 , V_48 -> V_248 , V_11 ) ;
if ( V_48 -> V_290 )
memcpy ( V_240 -> V_251 + 3 , V_170 -> V_252 , 3 ) ;
if ( F_126 ( V_48 -> V_291 != V_178 ) )
memcpy ( V_240 -> V_247 , V_48 -> V_24 , V_11 ) ;
else
memcpy ( V_240 -> V_247 , V_74 -> V_90 , V_11 ) ;
V_270 = (struct V_125 * ) ( V_240 + 1 ) ;
memset ( V_270 , 0 , sizeof( * V_270 ) ) ;
if ( V_292 )
F_171 ( V_270 , V_292 ) ;
V_270 -> V_293 = V_268 ;
if ( V_77 -> V_106 && F_172 ( V_168 ) ) {
F_161 ( V_69 ) -> V_294 = V_295 ;
F_161 ( V_69 ) -> V_296 = F_172 ( V_168 ) ;
} else {
F_161 ( V_69 ) -> V_294 = 0 ;
F_161 ( V_69 ) -> V_296 = 0 ;
}
V_259 = F_118 ( V_77 -> V_259 , F_143 () ) ;
V_259 -> V_297 ++ ;
V_259 -> V_298 += V_262 ;
F_144 () ;
V_253 ( V_168 ) = V_77 ;
F_38 ( V_74 , V_69 ) ;
return 0 ;
}
static inline int F_173 ( struct V_88 * V_77 ,
struct V_167 * V_168 )
{
struct V_5 * V_48 ;
struct V_1 * V_2 ;
struct V_169 * V_170 ;
struct V_68 * V_69 = (struct V_68 * ) V_168 ;
struct V_265 * V_259 ;
if ( V_77 -> V_105 && V_69 -> V_274 == V_299 )
F_174 ( V_168 ) &= ~ V_300 ;
else
F_174 ( V_168 ) |= V_300 ;
V_170 = (struct V_169 * ) F_135 ( V_69 ) ;
V_170 = F_79 ( V_168 ) ;
if ( V_170 -> V_175 == V_301 && V_170 -> V_272 == V_302 )
return 0 ;
V_2 = ( (struct V_73 * ) F_43 ( V_77 ) ) -> V_89 ;
V_48 = F_2 ( V_2 ) ;
if ( F_131 ( V_48 ) && F_175 ( V_168 ) == V_303 &&
F_136 ( V_170 -> V_304 ) == V_305 ) {
F_18 ( L_41 ) ;
return - V_127 ;
}
if ( ! ( F_174 ( V_168 ) & V_300 ) ||
F_176 ( F_177 ( V_168 ) ) == ~ F_178 ( ~ 0 , V_69 -> V_84 , V_69 -> V_242 ) ) {
F_174 ( V_168 ) &= ~ V_300 ;
return 0 ;
}
V_259 = F_118 ( V_77 -> V_259 , F_143 () ) ;
V_259 -> V_306 ++ ;
if ( V_259 -> V_306 < 5 )
F_68 ( V_307 L_42 ) ;
F_144 () ;
return - V_127 ;
}
static void F_179 ( struct V_68 * V_69 )
{
T_2 F_152 ;
struct V_88 * V_77 ;
struct V_237 * V_238 ;
struct V_265 * V_259 ;
struct V_126 V_224 ;
struct V_167 * V_168 ;
struct V_73 * V_74 ;
struct V_125 * V_270 ;
V_238 = F_137 ( V_69 ) ;
V_77 = V_238 -> V_253 ;
if ( F_126 ( ! V_77 ) ) {
F_3 ( V_69 -> V_38 , L_43 ) ;
F_145 ( V_69 ) ;
return;
}
F_3 ( V_69 -> V_38 ,
L_37 ,
V_69 -> V_242 , V_69 -> V_173 ,
V_69 -> V_243 , V_69 -> V_84 , F_127 ( V_69 ) ,
F_128 ( V_69 ) , V_69 -> V_244 ,
V_69 -> V_38 ? V_69 -> V_38 -> V_150 : L_38 ) ;
V_74 = F_43 ( V_77 ) ;
F_180 ( V_69 ) ;
V_270 = (struct V_125 * ) F_181 ( V_69 ) ;
V_259 = F_118 ( V_77 -> V_259 , F_143 () ) ;
if ( F_126 ( F_182 ( V_270 ) != V_292 ) ) {
if ( V_259 -> V_260 < 5 )
F_68 ( V_307 L_44
L_45
L_46
L_47
L_48 , F_182 ( V_270 ) ,
V_292 ) ;
goto V_308;
}
F_183 ( V_69 , sizeof( struct V_125 ) ) ;
F_152 = V_69 -> V_242 - sizeof( struct V_126 ) ;
V_259 -> V_309 ++ ;
V_259 -> V_310 += F_152 / V_271 ;
V_168 = (struct V_167 * ) V_69 ;
F_184 ( V_168 ) ;
V_253 ( V_168 ) = V_77 ;
F_155 ( V_168 ) = V_270 -> V_293 ;
if ( F_185 ( V_69 , F_152 , & V_224 , sizeof( V_224 ) ) )
goto V_308;
F_156 ( V_168 ) = V_224 . V_283 ;
F_177 ( V_168 ) = V_224 . V_284 ;
if ( F_186 ( V_69 , F_152 ) )
goto V_308;
if ( ! F_173 ( V_77 , V_168 ) ) {
F_144 () ;
F_187 ( V_77 , V_168 ) ;
return;
}
V_308:
V_259 -> V_260 ++ ;
F_144 () ;
F_145 ( V_69 ) ;
}
static void F_188 ( struct V_311 * V_232 )
{
struct V_225 * V_226 ;
struct V_68 * V_69 ;
struct V_312 V_313 ;
V_226 = F_36 ( V_232 , struct V_225 , V_232 ) ;
F_54 ( & V_313 ) ;
F_119 ( & V_226 -> V_228 . V_229 ) ;
F_189 ( & V_226 -> V_228 , & V_313 ) ;
F_120 ( & V_226 -> V_228 . V_229 ) ;
if ( ! F_190 ( & V_313 ) )
return;
while ( ( V_69 = F_191 ( & V_313 ) ) )
F_179 ( V_69 ) ;
}
static void F_192 ( void )
{
F_193 ( & V_314 ) ;
F_194 ( & V_315 ) ;
}
static void F_195 ( void )
{
F_196 ( & V_314 ) ;
F_197 ( & V_315 ) ;
}
static struct V_1 *
F_198 ( struct V_3 * V_4 )
{
struct V_1 * V_2 ;
struct V_3 * V_9 ;
F_85 (fcoe, &fcoe_hostlist, list) {
if ( F_4 ( V_2 -> V_4 ) )
V_9 = F_5 ( V_2 -> V_4 ) ;
else
V_9 = V_2 -> V_4 ;
if ( V_4 == V_9 )
return V_2 ;
}
return NULL ;
}
static int F_199 ( struct V_316 * V_317 ,
T_8 V_318 , void * V_319 )
{
struct V_320 * V_321 = V_319 ;
struct V_5 * V_48 ;
struct V_1 * V_2 ;
struct V_3 * V_4 ;
int V_322 ;
if ( V_321 -> V_323 . V_324 != V_325 )
return V_326 ;
V_4 = F_200 ( & V_327 , V_321 -> V_328 ) ;
if ( ! V_4 )
return V_326 ;
V_2 = F_198 ( V_4 ) ;
F_25 ( V_4 ) ;
if ( ! V_2 )
return V_326 ;
V_48 = F_2 ( V_2 ) ;
if ( V_321 -> V_329 & V_330 )
V_322 = F_201 ( V_321 -> V_323 . V_287 ) - 1 ;
else
V_322 = V_321 -> V_323 . V_287 ;
if ( V_322 < 0 )
return V_326 ;
if ( V_321 -> V_323 . V_286 == V_41 ||
V_321 -> V_323 . V_286 == V_37 )
V_48 -> V_287 = V_322 ;
if ( V_321 -> V_323 . V_286 == V_37 )
V_2 -> V_287 = V_322 ;
return V_326 ;
}
static int F_202 ( struct V_316 * V_317 ,
T_8 V_318 , void * V_319 )
{
struct V_46 * V_57 ;
struct V_88 * V_77 = NULL ;
struct V_3 * V_4 = F_203 ( V_319 ) ;
struct V_5 * V_48 ;
struct V_1 * V_2 ;
struct V_73 * V_74 ;
struct V_265 * V_259 ;
T_2 V_331 = 1 ;
T_2 V_118 ;
int V_135 = V_326 ;
F_85 (fcoe, &fcoe_hostlist, list) {
if ( V_2 -> V_4 == V_4 ) {
V_48 = F_2 ( V_2 ) ;
V_77 = V_48 -> V_66 ;
break;
}
}
if ( ! V_77 ) {
V_135 = V_332 ;
goto V_53;
}
switch ( V_318 ) {
case V_333 :
case V_334 :
V_331 = 0 ;
break;
case V_335 :
case V_336 :
break;
case V_337 :
if ( V_4 -> V_111 & V_123 )
break;
V_118 = V_4 -> V_122 - ( sizeof( struct V_125 ) +
sizeof( struct V_126 ) ) ;
if ( V_118 >= V_338 )
F_53 ( V_77 , V_118 ) ;
break;
case V_339 :
break;
case V_340 :
F_204 ( & V_2 -> V_341 ) ;
V_74 = F_43 ( V_48 -> V_66 ) ;
F_205 ( V_342 , & V_74 -> V_212 ) ;
goto V_53;
break;
case V_343 :
F_48 ( V_77 , V_4 ) ;
break;
default:
F_3 ( V_4 , L_49
L_50 , V_318 ) ;
}
F_56 ( V_77 ) ;
V_57 = F_206 ( V_48 ) ;
if ( V_331 && ! F_207 ( V_77 ) ) {
switch ( V_57 -> V_344 ) {
case V_345 :
F_208 ( L_51 ) ;
break;
case V_346 :
case V_347 :
F_209 ( V_48 ) ;
} ;
} else if ( F_210 ( V_48 ) ) {
switch ( V_57 -> V_344 ) {
case V_345 :
F_208 ( L_52 ) ;
break;
case V_346 :
case V_347 :
V_259 = F_118 ( V_77 -> V_259 , F_143 () ) ;
V_259 -> V_348 ++ ;
F_144 () ;
F_92 ( V_77 ) ;
} ;
}
V_53:
return V_135 ;
}
static int F_211 ( struct V_3 * V_4 )
{
struct V_5 * V_48 ;
struct V_1 * V_2 ;
int V_135 = 0 ;
F_49 ( & V_349 ) ;
F_33 () ;
V_2 = F_212 ( V_4 ) ;
F_34 () ;
if ( V_2 ) {
V_48 = F_2 ( V_2 ) ;
F_210 ( V_48 ) ;
F_92 ( V_48 -> V_66 ) ;
} else
V_135 = - V_221 ;
F_50 ( & V_349 ) ;
return V_135 ;
}
static int F_213 ( struct V_3 * V_4 )
{
struct V_5 * V_48 ;
struct V_1 * V_2 ;
int V_135 = 0 ;
F_49 ( & V_349 ) ;
F_33 () ;
V_2 = F_212 ( V_4 ) ;
F_34 () ;
if ( ! V_2 ) {
V_135 = - V_221 ;
goto V_53;
}
V_48 = F_2 ( V_2 ) ;
if ( ! F_207 ( V_48 -> V_66 ) )
F_209 ( V_48 ) ;
V_53:
F_50 ( & V_349 ) ;
return V_135 ;
}
static int F_214 ( struct V_46 * V_57 )
{
struct V_5 * V_48 = F_19 ( V_57 ) ;
struct V_88 * V_77 = V_48 -> V_66 ;
struct V_3 * V_4 = F_63 ( V_77 ) ;
switch ( V_57 -> V_344 ) {
case V_346 :
return F_213 ( V_4 ) ;
case V_345 :
return F_211 ( V_4 ) ;
case V_347 :
default:
return - V_350 ;
} ;
}
static void F_215 ( struct V_46 * V_47 )
{
struct V_5 * V_48 = F_19 ( V_47 ) ;
struct V_1 * V_2 = F_20 ( V_48 ) ;
if ( V_47 -> V_29 == V_351 &&
V_48 -> V_29 != V_30 ) {
F_31 ( V_2 -> V_4 , V_33 ) ;
F_11 ( V_2 -> V_4 , V_31 ) ;
F_11 ( V_2 -> V_4 , V_32 ) ;
} else if ( V_48 -> V_29 != V_352 ) {
F_31 ( V_2 -> V_4 , V_31 ) ;
F_31 ( V_2 -> V_4 , V_32 ) ;
F_11 ( V_2 -> V_4 , V_33 ) ;
}
F_216 ( V_47 ) ;
}
static int F_217 ( struct V_3 * V_4 )
{
struct V_5 * V_48 ;
struct V_1 * V_2 ;
struct V_88 * V_77 ;
struct V_73 * V_74 ;
int V_135 = 0 ;
F_49 ( & V_349 ) ;
F_33 () ;
V_2 = F_212 ( V_4 ) ;
if ( ! V_2 ) {
V_135 = - V_221 ;
goto V_353;
}
V_48 = F_2 ( V_2 ) ;
V_77 = V_48 -> V_66 ;
V_74 = F_43 ( V_77 ) ;
F_204 ( & V_2 -> V_341 ) ;
F_205 ( V_342 , & V_74 -> V_212 ) ;
V_353:
F_34 () ;
F_50 ( & V_349 ) ;
return V_135 ;
}
static void V_213 ( struct V_311 * V_232 )
{
struct V_46 * V_57 ;
struct V_5 * V_48 ;
struct V_73 * V_74 ;
struct V_1 * V_2 ;
struct V_203 * V_204 ;
struct V_354 * V_355 ;
unsigned long V_18 ;
struct V_205 * V_131 ;
struct V_205 * V_356 ;
V_74 = F_36 ( V_232 , struct V_73 , V_212 ) ;
V_204 = V_74 -> V_77 -> V_67 ;
V_355 = F_218 ( V_204 ) ;
F_219 ( V_204 -> V_357 , V_18 ) ;
F_220 (vport, next_vport, &fc_host->vports, peers) {
if ( V_131 -> V_18 & ( V_358 | V_359 ) ) {
continue;
} else {
V_131 -> V_18 |= V_360 ;
F_205 ( F_221 ( V_204 ) ,
& V_131 -> V_361 ) ;
}
}
F_222 ( V_204 -> V_357 , V_18 ) ;
F_223 ( F_221 ( V_204 ) ) ;
F_49 ( & V_349 ) ;
V_2 = V_74 -> V_89 ;
V_48 = F_2 ( V_2 ) ;
V_57 = F_206 ( V_48 ) ;
F_88 ( V_74 -> V_77 ) ;
F_32 ( V_2 ) ;
F_50 ( & V_349 ) ;
F_24 ( V_57 ) ;
}
static bool F_224 ( struct V_3 * V_4 )
{
return true ;
}
static void F_225 ( struct V_1 * V_2 )
{
int V_362 = V_363 ;
int V_364 = V_365 ;
struct V_5 * V_48 = F_2 ( V_2 ) ;
#ifdef F_226
int V_329 ;
T_1 V_366 , V_367 ;
struct V_3 * V_4 = V_2 -> V_21 ;
struct V_368 V_323 = {
. V_287 = 0 ,
. V_286 = V_37
} ;
if ( V_4 && V_4 -> V_369 && V_4 -> V_369 -> V_370 ) {
V_329 = V_4 -> V_369 -> V_370 ( V_4 ) ;
if ( V_329 & V_371 ) {
V_323 . V_324 = V_372 ;
V_367 = F_227 ( V_4 , & V_323 ) ;
V_323 . V_286 = V_41 ;
V_366 = F_227 ( V_4 , & V_323 ) ;
} else {
V_323 . V_324 = V_325 ;
V_367 = F_228 ( V_4 , & V_323 ) ;
V_323 . V_286 = V_41 ;
V_366 = F_228 ( V_4 , & V_323 ) ;
}
V_364 = F_201 ( V_367 ) ? F_201 ( V_367 ) - 1 : 0 ;
V_362 = F_201 ( V_366 ) ? F_201 ( V_366 ) - 1 : V_364 ;
}
#endif
V_2 -> V_287 = V_364 ;
V_48 -> V_287 = V_362 ;
}
static int F_229 ( struct V_3 * V_4 , enum V_45 V_45 ,
enum V_373 V_374 )
{
int V_135 = 0 ;
struct V_46 * V_47 ;
struct V_5 * V_48 ;
struct V_1 * V_2 ;
struct V_88 * V_77 ;
F_49 ( & V_349 ) ;
F_33 () ;
if ( F_230 ( V_4 ) ) {
V_135 = - V_375 ;
goto V_353;
}
V_2 = F_14 ( V_4 , V_45 ) ;
if ( F_231 ( V_2 ) ) {
V_135 = F_232 ( V_2 ) ;
goto V_353;
}
V_48 = F_2 ( V_2 ) ;
V_47 = F_206 ( V_48 ) ;
V_77 = F_102 ( V_2 , & V_47 -> V_38 , 0 ) ;
if ( F_231 ( V_77 ) ) {
F_68 ( V_191 L_53 ,
V_4 -> V_150 ) ;
V_135 = - V_376 ;
F_34 () ;
F_32 ( V_2 ) ;
F_50 ( & V_349 ) ;
F_24 ( V_47 ) ;
goto V_53;
}
V_48 -> V_66 = V_77 ;
F_225 ( V_2 ) ;
V_77 -> V_377 = V_378 ;
F_233 ( V_77 ) ;
if ( V_374 == V_379 )
V_47 -> V_344 = V_346 ;
else
V_47 -> V_344 = V_345 ;
if ( V_374 == V_379 &&
! F_207 ( V_77 ) ) {
F_34 () ;
F_209 ( V_48 ) ;
F_50 ( & V_349 ) ;
return V_135 ;
}
V_353:
F_34 () ;
F_50 ( & V_349 ) ;
V_53:
return V_135 ;
}
static int F_234 ( struct V_3 * V_4 , enum V_45 V_45 )
{
return F_229 ( V_4 , V_45 , V_379 ) ;
}
static int F_235 ( struct V_3 * V_4 )
{
return F_229 ( V_4 , V_352 ,
V_380 ) ;
}
static int F_207 ( struct V_88 * V_77 )
{
struct V_3 * V_4 = F_63 ( V_77 ) ;
if ( F_236 ( V_4 ) )
return 0 ;
return - 1 ;
}
static void F_93 ( struct V_88 * V_77 )
{
struct V_225 * V_381 ;
unsigned int V_222 ;
F_237 (cpu) {
V_381 = & F_138 ( V_227 , V_222 ) ;
F_122 ( & V_381 -> V_232 ) ;
}
}
static int F_238 ( struct V_203 * V_204 )
{
struct V_88 * V_77 = F_110 ( V_204 ) ;
struct V_73 * V_74 = F_43 ( V_77 ) ;
struct V_1 * V_2 = V_74 -> V_89 ;
struct V_5 * V_48 = F_2 ( V_2 ) ;
struct V_46 * V_57 = F_206 ( V_48 ) ;
F_210 ( V_48 ) ;
F_92 ( V_48 -> V_66 ) ;
if ( V_57 -> V_344 != V_345 &&
! F_207 ( V_48 -> V_66 ) )
F_209 ( V_48 ) ;
return 0 ;
}
static struct V_1 *
F_212 ( const struct V_3 * V_4 )
{
struct V_1 * V_2 ;
F_85 (fcoe, &fcoe_hostlist, list) {
if ( V_2 -> V_4 == V_4 )
return V_2 ;
}
return NULL ;
}
static struct V_88 * F_230 ( const struct V_3 * V_4 )
{
struct V_5 * V_48 ;
struct V_1 * V_2 ;
V_2 = F_212 ( V_4 ) ;
V_48 = F_2 ( V_2 ) ;
return ( V_2 ) ? V_48 -> V_66 : NULL ;
}
static int F_107 ( const struct V_88 * V_77 )
{
struct V_1 * V_2 ;
struct V_73 * V_74 ;
V_2 = F_212 ( F_63 ( V_77 ) ) ;
if ( ! V_2 ) {
V_74 = F_43 ( V_77 ) ;
V_2 = V_74 -> V_89 ;
F_239 ( & V_2 -> V_341 , & V_382 ) ;
}
return 0 ;
}
static void F_112 ( const struct V_88 * V_77 )
{
struct V_1 * V_2 ;
struct V_73 * V_74 ;
V_74 = F_43 ( V_77 ) ;
V_2 = V_74 -> V_89 ;
F_204 ( & V_2 -> V_341 ) ;
return;
}
static int T_5 F_240 ( void )
{
struct V_225 * V_226 ;
unsigned int V_222 ;
int V_135 = 0 ;
V_342 = F_241 ( L_54 , 0 , 0 ) ;
if ( ! V_342 )
return - V_55 ;
V_135 = F_242 ( & V_383 ) ;
if ( V_135 ) {
F_68 ( V_191 L_55
L_56 ) ;
goto V_384;
}
F_49 ( & V_349 ) ;
F_237 (cpu) {
V_226 = F_118 ( & V_227 , V_222 ) ;
F_106 ( & V_226 -> V_232 , F_188 ) ;
F_54 ( & V_226 -> V_228 ) ;
}
F_192 () ;
V_135 = F_113 () ;
if ( V_135 )
goto V_385;
F_50 ( & V_349 ) ;
return 0 ;
V_385:
F_50 ( & V_349 ) ;
V_384:
F_243 ( V_342 ) ;
return V_135 ;
}
static void T_6 F_244 ( void )
{
struct V_1 * V_2 , * V_313 ;
struct V_5 * V_48 ;
struct V_73 * V_74 ;
unsigned int V_222 ;
F_49 ( & V_349 ) ;
F_195 () ;
F_33 () ;
F_220 (fcoe, tmp, &fcoe_hostlist, list) {
V_48 = F_2 ( V_2 ) ;
V_74 = F_43 ( V_48 -> V_66 ) ;
F_112 ( V_74 -> V_77 ) ;
F_205 ( V_342 , & V_74 -> V_212 ) ;
}
F_34 () ;
F_237 (cpu)
F_117 ( V_222 ) ;
F_50 ( & V_349 ) ;
F_243 ( V_342 ) ;
F_115 () ;
F_245 ( & V_383 ) ;
}
static void F_246 ( struct V_386 * V_387 , struct V_167 * V_168 , void * V_388 )
{
struct V_5 * V_6 = V_388 ;
struct V_389 * V_390 = F_247 ( V_387 ) ;
struct V_88 * V_77 = V_390 -> V_66 ;
T_1 * V_391 ;
if ( F_231 ( V_168 ) )
goto V_392;
V_391 = F_248 ( V_168 ) -> V_393 ;
if ( F_44 ( V_391 ) )
F_249 ( V_6 , V_77 , V_168 ) ;
if ( ! F_44 ( V_391 ) )
V_61 ( V_77 , V_391 ) ;
V_392:
F_250 ( V_387 , V_168 , V_77 ) ;
}
static void F_251 ( struct V_386 * V_387 , struct V_167 * V_168 , void * V_388 )
{
struct V_88 * V_77 = V_388 ;
static T_1 V_394 [ V_11 ] = { 0 } ;
if ( ! F_231 ( V_168 ) )
V_61 ( V_77 , V_394 ) ;
F_252 ( V_387 , V_168 , V_77 ) ;
}
static struct V_386 * F_253 ( struct V_88 * V_77 , T_2 V_395 ,
struct V_167 * V_168 , unsigned int V_396 ,
void (* F_254)( struct V_386 * ,
struct V_167 * ,
void * ) ,
void * V_388 , T_2 V_397 )
{
struct V_73 * V_74 = F_43 ( V_77 ) ;
struct V_1 * V_2 = V_74 -> V_89 ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_169 * V_170 = F_79 ( V_168 ) ;
switch ( V_396 ) {
case V_398 :
case V_399 :
if ( V_77 -> V_400 )
break;
return F_255 ( V_77 , V_395 , V_168 , V_396 , F_246 ,
V_6 , V_397 ) ;
case V_303 :
if ( F_136 ( V_170 -> V_252 ) != V_305 )
break;
return F_255 ( V_77 , V_395 , V_168 , V_396 , F_251 ,
V_77 , V_397 ) ;
}
return F_255 ( V_77 , V_395 , V_168 , V_396 , F_254 , V_388 , V_397 ) ;
}
static int F_256 ( struct V_205 * V_131 , bool V_401 )
{
struct V_203 * V_204 = F_109 ( V_131 ) ;
struct V_88 * V_202 = F_110 ( V_204 ) ;
struct V_73 * V_74 = F_43 ( V_202 ) ;
struct V_1 * V_2 = V_74 -> V_89 ;
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_88 * V_402 ;
int V_135 ;
char V_403 [ 32 ] ;
V_135 = F_257 ( V_131 ) ;
if ( V_135 ) {
F_258 ( V_131 -> V_216 , V_403 , sizeof( V_403 ) ) ;
F_68 ( V_191 L_57
L_58 ,
V_403 ) ;
return V_135 ;
}
F_49 ( & V_349 ) ;
F_33 () ;
V_402 = F_102 ( V_2 , & V_131 -> V_38 , 1 ) ;
F_34 () ;
F_50 ( & V_349 ) ;
if ( F_231 ( V_402 ) ) {
F_68 ( V_191 L_59 ,
V_4 -> V_150 ) ;
return - V_376 ;
}
if ( V_401 ) {
F_259 ( V_131 , V_404 ) ;
} else {
V_402 -> V_377 = V_378 ;
F_233 ( V_402 ) ;
F_260 ( V_402 ) ;
}
return 0 ;
}
static int F_261 ( struct V_205 * V_131 )
{
struct V_203 * V_204 = F_109 ( V_131 ) ;
struct V_88 * V_202 = F_110 ( V_204 ) ;
struct V_88 * V_402 = V_131 -> V_405 ;
F_49 ( & V_202 -> V_110 ) ;
F_204 ( & V_402 -> V_341 ) ;
F_50 ( & V_202 -> V_110 ) ;
F_49 ( & V_349 ) ;
F_88 ( V_402 ) ;
F_50 ( & V_349 ) ;
return 0 ;
}
static int F_262 ( struct V_205 * V_131 , bool V_406 )
{
struct V_88 * V_77 = V_131 -> V_405 ;
if ( V_406 ) {
F_259 ( V_131 , V_404 ) ;
F_89 ( V_77 ) ;
} else {
V_77 -> V_377 = V_378 ;
F_233 ( V_77 ) ;
F_260 ( V_77 ) ;
}
return 0 ;
}
static void F_263 ( struct V_205 * V_131 )
{
struct V_88 * V_77 = V_131 -> V_405 ;
struct V_167 * V_168 ;
T_9 V_242 ;
snprintf ( F_65 ( V_77 -> V_67 ) , V_147 ,
L_60 , V_148 , V_149 ,
F_63 ( V_77 ) -> V_150 , V_131 -> V_407 ) ;
if ( V_77 -> V_408 != V_409 )
return;
V_242 = F_264 ( F_65 ( V_77 -> V_67 ) , 255 ) ;
V_168 = F_265 ( V_77 ,
sizeof( struct V_410 ) +
sizeof( struct V_411 ) + V_242 ) ;
if ( ! V_168 )
return;
V_77 -> V_412 . V_413 ( V_77 , V_414 , V_168 , V_415 ,
NULL , NULL , 3 * V_77 -> V_97 ) ;
}
static void F_266 ( struct V_416 * V_417 )
{
struct V_46 * V_47 =
F_267 ( V_417 ) ;
struct V_5 * V_48 = F_19 ( V_47 ) ;
struct V_1 * V_2 = F_20 ( V_48 ) ;
V_417 -> V_418 = F_52 ( V_2 -> V_4 ) ;
}
static void F_268 ( struct V_88 * V_77 ,
T_2 V_419 , struct V_167 * V_168 )
{
struct V_73 * V_74 = F_43 ( V_77 ) ;
struct V_1 * V_2 = V_74 -> V_89 ;
struct V_5 * V_48 = F_2 ( V_2 ) ;
if ( V_168 && F_175 ( V_168 ) == V_398 )
F_249 ( V_48 , V_77 , V_168 ) ;
}
