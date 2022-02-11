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
V_9 = ( V_4 -> V_16 & V_21 ) ?
F_4 ( V_4 ) : V_4 ;
V_2 -> V_22 = V_9 ;
F_5 () ;
F_6 (real_dev, ha) {
if ( ( V_8 -> type == V_23 ) &&
( F_7 ( V_8 -> V_24 ) ) ) {
memcpy ( V_6 -> V_25 , V_8 -> V_24 , V_11 ) ;
V_6 -> V_26 = 1 ;
break;
}
}
F_8 () ;
if ( ! V_6 -> V_26 )
memcpy ( V_6 -> V_25 , V_4 -> V_27 , V_4 -> V_28 ) ;
memcpy ( V_10 , ( T_1 [ 6 ] ) V_29 , V_11 ) ;
F_9 ( V_4 , V_10 ) ;
if ( V_6 -> V_26 )
F_9 ( V_4 , V_6 -> V_25 ) ;
if ( V_6 -> V_30 == V_31 ) {
F_10 ( V_4 , V_32 ) ;
F_10 ( V_4 , V_33 ) ;
} else
F_10 ( V_4 , V_34 ) ;
V_2 -> V_35 . V_36 = V_37 ;
V_2 -> V_35 . type = F_11 ( V_38 ) ;
V_2 -> V_35 . V_39 = V_4 ;
F_12 ( & V_2 -> V_35 ) ;
V_2 -> V_40 . V_36 = V_41 ;
V_2 -> V_40 . type = F_11 ( V_42 ) ;
V_2 -> V_40 . V_39 = V_4 ;
F_12 ( & V_2 -> V_40 ) ;
if ( V_4 != V_9 ) {
V_2 -> V_43 . V_36 = V_44 ;
V_2 -> V_43 . type = F_11 ( V_42 ) ;
V_2 -> V_43 . V_39 = V_9 ;
F_12 ( & V_2 -> V_43 ) ;
}
return 0 ;
}
static struct V_1 * F_13 ( struct V_3 * V_4 ,
enum V_45 V_46 )
{
struct V_47 * V_48 ;
struct V_5 * V_49 ;
struct V_1 * V_2 ;
int V_50 ;
int V_51 ;
if ( ! F_14 ( V_52 ) ) {
F_3 ( V_4 ,
L_4 ) ;
V_2 = F_15 ( - V_53 ) ;
goto V_54;
}
V_50 = sizeof( struct V_5 ) + sizeof( struct V_1 ) ;
V_48 = F_16 ( & V_4 -> V_39 , & V_55 ,
V_50 ) ;
if ( ! V_48 ) {
F_17 ( L_5 ) ;
V_2 = F_15 ( - V_56 ) ;
goto V_57;
}
V_49 = F_18 ( V_48 ) ;
V_49 -> V_58 = V_48 ;
V_2 = F_19 ( V_49 ) ;
F_20 ( V_4 ) ;
F_21 ( V_49 , V_46 ) ;
V_49 -> V_59 = V_60 ;
V_49 -> V_61 = V_62 ;
V_49 -> V_63 = V_64 ;
V_51 = F_1 ( V_2 , V_4 ) ;
if ( V_51 ) {
F_22 ( V_49 ) ;
F_23 ( V_48 ) ;
F_24 ( V_4 ) ;
V_2 = F_15 ( V_51 ) ;
goto V_57;
}
goto V_54;
V_57:
F_25 ( V_52 ) ;
V_54:
return V_2 ;
}
static void F_26 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
T_1 V_10 [ V_11 ] ;
const struct V_12 * V_13 ;
F_27 ( & V_2 -> V_35 ) ;
F_27 ( & V_2 -> V_40 ) ;
if ( V_4 != V_2 -> V_22 )
F_27 ( & V_2 -> V_43 ) ;
F_28 () ;
memcpy ( V_10 , ( T_1 [ 6 ] ) V_29 , V_11 ) ;
F_29 ( V_4 , V_10 ) ;
if ( V_6 -> V_26 )
F_29 ( V_4 , V_6 -> V_25 ) ;
if ( V_6 -> V_30 == V_31 ) {
F_30 ( V_4 , V_32 ) ;
F_30 ( V_4 , V_33 ) ;
} else
F_30 ( V_4 , V_34 ) ;
V_13 = V_4 -> V_14 ;
if ( V_13 -> V_65 ) {
if ( V_13 -> V_65 ( V_4 ) )
F_3 ( V_4 , L_6
L_2 ) ;
}
V_2 -> V_66 = 1 ;
}
static void F_31 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
F_32 () ;
if ( ! V_2 -> V_66 )
F_26 ( V_2 ) ;
F_33 () ;
F_22 ( V_6 ) ;
F_34 ( V_6 -> V_67 -> V_68 ) ;
F_24 ( V_4 ) ;
F_25 ( V_52 ) ;
}
static int V_41 ( struct V_69 * V_70 , struct V_3 * V_4 ,
struct V_71 * V_72 ,
struct V_3 * V_73 )
{
struct V_1 * V_2 ;
struct V_5 * V_49 ;
V_2 = F_35 ( V_72 , struct V_1 , V_40 ) ;
V_49 = F_2 ( V_2 ) ;
F_36 ( V_49 , V_70 ) ;
return 0 ;
}
static int V_44 ( struct V_69 * V_70 , struct V_3 * V_4 ,
struct V_71 * V_72 ,
struct V_3 * V_73 )
{
struct V_1 * V_2 ;
struct V_5 * V_49 ;
V_2 = F_35 ( V_72 , struct V_1 , V_43 ) ;
V_49 = F_2 ( V_2 ) ;
F_36 ( V_49 , V_70 ) ;
return 0 ;
}
static void F_37 ( struct V_74 * V_75 , struct V_69 * V_70 )
{
if ( V_75 -> V_76 . V_77 )
F_38 ( V_75 -> V_78 , V_70 ) ;
else if ( F_39 ( V_70 ) )
F_38 ( V_75 -> V_78 , V_70 ) ;
}
static void V_60 ( struct V_5 * V_6 , struct V_69 * V_70 )
{
struct V_1 * V_2 = F_40 ( V_6 ) ;
struct V_79 {
struct V_80 V_81 ;
struct V_82 V_6 ;
} V_83 * V_84 ;
V_84 = (struct V_79 * ) V_70 -> V_85 ;
if ( V_84 -> V_6 . V_86 == F_41 ( V_87 ) &&
V_2 -> V_22 != V_2 -> V_4 )
V_70 -> V_39 = V_2 -> V_22 ;
else
V_70 -> V_39 = V_2 -> V_4 ;
F_37 ( F_42 ( V_6 -> V_67 ) , V_70 ) ;
}
static void V_62 ( struct V_88 * V_78 , T_1 * V_24 )
{
struct V_74 * V_75 = F_42 ( V_78 ) ;
struct V_1 * V_2 = V_75 -> V_89 ;
if ( ! F_43 ( V_75 -> V_90 ) )
F_29 ( V_2 -> V_4 , V_75 -> V_90 ) ;
if ( ! F_43 ( V_24 ) )
F_9 ( V_2 -> V_4 , V_24 ) ;
memcpy ( V_75 -> V_90 , V_24 , V_11 ) ;
}
static T_1 * V_64 ( struct V_88 * V_78 )
{
struct V_74 * V_75 = F_42 ( V_78 ) ;
return V_75 -> V_90 ;
}
static int F_44 ( struct V_88 * V_78 )
{
V_78 -> V_91 = 0 ;
V_78 -> V_92 = 0 ;
V_78 -> V_93 = 3 ;
V_78 -> V_94 = 3 ;
V_78 -> V_95 = 2 * 1000 ;
V_78 -> V_96 = 2 * 2 * 1000 ;
V_78 -> V_97 = ( V_98 | V_99 |
V_100 | V_101 ) ;
V_78 -> V_102 = 1 ;
F_45 ( V_78 ) ;
F_46 ( V_78 ) ;
V_78 -> V_103 = 0 ;
V_78 -> V_104 = 0 ;
V_78 -> V_105 = 0 ;
V_78 -> V_106 = 0 ;
V_78 -> V_107 = 0 ;
return 0 ;
}
static void F_47 ( struct V_88 * V_78 ,
struct V_3 * V_4 )
{
F_48 ( & V_78 -> V_108 ) ;
if ( V_4 -> V_109 & V_110 )
V_78 -> V_111 = 1 ;
else
V_78 -> V_111 = 0 ;
if ( V_4 -> V_109 & V_112 ) {
V_78 -> V_103 = 1 ;
F_3 ( V_4 , L_7 ) ;
} else {
V_78 -> V_103 = 0 ;
}
if ( V_4 -> V_109 & V_113 ) {
V_78 -> V_104 = 1 ;
V_78 -> V_107 = V_4 -> V_114 ;
F_3 ( V_4 , L_8 ,
V_78 -> V_107 ) ;
} else {
V_78 -> V_104 = 0 ;
V_78 -> V_107 = 0 ;
}
if ( V_4 -> V_115 ) {
V_78 -> V_105 = 1 ;
V_78 -> V_106 = V_4 -> V_115 ;
F_3 ( V_4 , L_9 ,
V_78 -> V_106 ) ;
} else {
V_78 -> V_105 = 0 ;
V_78 -> V_106 = 0 ;
}
F_49 ( & V_78 -> V_108 ) ;
}
static int F_50 ( struct V_88 * V_78 , struct V_3 * V_4 )
{
T_2 V_116 ;
T_3 V_117 , V_118 ;
struct V_1 * V_2 ;
struct V_5 * V_49 ;
struct V_74 * V_75 ;
V_75 = F_42 ( V_78 ) ;
V_2 = V_75 -> V_89 ;
V_49 = F_2 ( V_2 ) ;
if ( V_4 -> V_16 & V_21 )
V_78 -> V_119 = F_51 ( V_4 ) ;
else
V_78 -> V_119 = 0 ;
V_116 = V_4 -> V_120 ;
if ( V_4 -> V_109 & V_121 ) {
V_116 = V_122 ;
F_3 ( V_4 , L_10 , V_116 ) ;
}
V_116 -= ( sizeof( struct V_123 ) + sizeof( struct V_124 ) ) ;
if ( F_52 ( V_78 , V_116 ) )
return - V_125 ;
F_47 ( V_78 , V_4 ) ;
F_53 ( & V_75 -> V_76 ) ;
V_75 -> V_126 = 0 ;
F_54 ( & V_75 -> V_127 , V_128 , ( unsigned long ) V_78 ) ;
F_55 ( V_78 ) ;
if ( ! V_78 -> V_129 ) {
if ( F_56 ( V_4 , & V_117 , V_130 ) )
V_117 = F_57 ( V_49 -> V_25 , 1 , 0 ) ;
F_58 ( V_78 , V_117 ) ;
if ( F_56 ( V_4 , & V_118 , V_131 ) )
V_118 = F_57 ( V_49 -> V_25 ,
2 , 0 ) ;
F_59 ( V_78 , V_118 ) ;
}
return 0 ;
}
static int F_60 ( struct V_88 * V_78 , struct V_132 * V_39 )
{
int V_133 = 0 ;
V_78 -> V_68 -> V_134 = V_135 ;
V_78 -> V_68 -> V_136 = V_137 ;
V_78 -> V_68 -> V_138 = 0 ;
V_78 -> V_68 -> V_139 = V_140 ;
if ( V_78 -> V_129 )
V_78 -> V_68 -> V_141 = V_142 ;
else
V_78 -> V_68 -> V_141 = V_143 ;
V_133 = F_61 ( V_78 -> V_68 , V_39 ) ;
if ( V_133 ) {
F_3 ( F_62 ( V_78 ) , L_11
L_12 ) ;
return V_133 ;
}
if ( ! V_78 -> V_129 )
F_63 ( V_78 -> V_68 ) = V_144 ;
snprintf ( F_64 ( V_78 -> V_68 ) , V_145 ,
L_13 , V_146 , V_147 ,
F_62 ( V_78 ) -> V_148 ) ;
return 0 ;
}
static void F_65 ( struct V_88 * V_78 , struct V_3 * V_4 )
{
struct V_1 * V_2 ;
struct V_74 * V_75 ;
struct V_3 * V_22 ;
int V_133 ;
V_75 = F_42 ( V_78 ) ;
V_2 = V_75 -> V_89 ;
V_22 = V_2 -> V_22 ;
if ( V_78 -> V_129 )
return;
if ( V_22 -> V_14 -> V_149 ) {
struct V_150 * V_151 ;
V_151 = F_66 ( sizeof( * V_151 ) , V_152 ) ;
if ( ! V_151 )
return;
V_133 = V_22 -> V_14 -> V_149 ( V_22 ,
V_151 ) ;
if ( V_133 ) {
F_67 ( V_153 L_14
L_15 ) ;
return;
}
snprintf ( F_68 ( V_78 -> V_68 ) ,
V_154 ,
L_16 ,
V_151 -> V_155 ) ;
snprintf ( F_69 ( V_78 -> V_68 ) ,
V_154 ,
L_16 ,
V_151 -> V_156 ) ;
snprintf ( F_70 ( V_78 -> V_68 ) ,
V_145 ,
L_16 ,
V_151 -> V_157 ) ;
snprintf ( F_71 ( V_78 -> V_68 ) ,
V_145 ,
L_16 ,
V_151 -> V_158 ) ;
snprintf ( F_72 ( V_78 -> V_68 ) ,
V_159 ,
L_16 ,
V_151 -> V_160 ) ;
snprintf ( F_73 ( V_78 -> V_68 ) ,
V_159 ,
L_16 ,
V_151 -> V_161 ) ;
snprintf ( F_74 ( V_78 -> V_68 ) ,
V_159 ,
L_16 ,
V_151 -> V_162 ) ;
snprintf ( F_75 ( V_78 -> V_68 ) ,
V_159 ,
L_16 ,
V_151 -> V_163 ) ;
V_78 -> V_164 = 1 ;
F_76 ( V_151 ) ;
} else {
V_78 -> V_164 = 0 ;
F_67 ( V_153 L_17 ) ;
}
}
static bool F_77 ( struct V_165 * V_166 )
{
struct V_167 * V_168 = F_78 ( V_166 ) ;
struct V_169 * V_170 ;
if ( F_79 ( F_80 ( V_166 ) ) &&
( F_80 ( V_166 ) -> V_171 > V_172 ) )
return true ;
else if ( ( F_80 ( V_166 ) == NULL ) &&
( V_168 -> V_173 == V_174 ) &&
( F_41 ( V_168 -> V_175 ) == V_176 ) ) {
V_170 = F_81 ( V_166 , sizeof( * V_170 ) ) ;
if ( ( V_170 -> V_177 & V_178 ) &&
( F_82 ( V_170 -> V_179 ) > V_172 ) )
return true ;
}
return false ;
}
static inline int F_83 ( struct V_88 * V_78 )
{
struct V_74 * V_75 = F_42 ( V_78 ) ;
struct V_1 * V_2 = V_75 -> V_89 ;
struct V_1 * V_180 = NULL ;
struct V_3 * V_181 , * V_182 ;
T_4 V_183 = V_184 ;
T_4 V_185 = V_186 ;
if ( ! V_78 -> V_105 || ! V_78 -> V_106 ||
( V_78 -> V_106 >= V_185 ) ) {
V_78 -> V_106 = 0 ;
goto V_187;
}
if ( V_2 -> V_4 -> V_16 & V_21 )
V_182 = F_4 ( V_2 -> V_4 ) ;
else
V_182 = V_2 -> V_4 ;
F_84 (oldfcoe, &fcoe_hostlist, list) {
if ( V_180 -> V_4 -> V_16 & V_21 )
V_181 = F_4 ( V_180 -> V_4 ) ;
else
V_181 = V_180 -> V_4 ;
if ( V_182 == V_181 ) {
V_2 -> V_188 = V_180 -> V_188 ;
break;
}
}
if ( V_2 -> V_188 ) {
if ( ! F_85 ( V_78 , V_2 -> V_188 , F_77 ) ) {
F_67 ( V_189 L_18
L_19 ,
V_2 -> V_188 , V_2 -> V_4 -> V_148 ) ;
return - V_56 ;
}
} else {
V_2 -> V_188 = F_86 ( V_78 , V_190 ,
V_184 , V_78 -> V_106 ,
F_77 ) ;
if ( ! V_2 -> V_188 ) {
F_67 ( V_189 L_20
L_21 ,
V_2 -> V_4 -> V_148 ) ;
return - V_56 ;
}
}
V_183 += V_78 -> V_106 + 1 ;
V_187:
if ( ! F_86 ( V_78 , V_190 , V_183 , V_185 , NULL ) ) {
F_67 ( V_189 L_22
L_23 , V_2 -> V_4 -> V_148 ) ;
return - V_56 ;
}
return 0 ;
}
static void F_87 ( struct V_88 * V_78 )
{
struct V_74 * V_75 = F_42 ( V_78 ) ;
struct V_1 * V_2 = V_75 -> V_89 ;
struct V_3 * V_4 = V_2 -> V_4 ;
F_3 ( V_4 , L_24 ) ;
F_88 ( V_78 ) ;
F_89 ( V_78 ) ;
F_90 ( & V_75 -> V_127 ) ;
F_91 ( V_78 ) ;
F_32 () ;
if ( ! F_43 ( V_75 -> V_90 ) )
F_29 ( V_4 , V_75 -> V_90 ) ;
if ( V_78 -> V_129 )
F_28 () ;
else
F_26 ( V_2 ) ;
F_33 () ;
F_92 ( V_78 ) ;
F_93 ( V_78 -> V_68 ) ;
F_94 ( V_78 -> V_68 ) ;
F_95 ( V_78 ) ;
F_96 ( V_78 ) ;
F_97 ( V_78 ) ;
if ( V_78 -> V_129 )
F_34 ( V_78 -> V_68 ) ;
}
static int F_98 ( struct V_88 * V_78 , T_4 V_191 ,
struct V_192 * V_193 , unsigned int V_194 )
{
struct V_3 * V_4 = F_62 ( V_78 ) ;
if ( V_4 -> V_14 -> V_195 )
return V_4 -> V_14 -> V_195 ( V_4 ,
V_191 , V_193 ,
V_194 ) ;
return 0 ;
}
static int F_99 ( struct V_88 * V_78 , T_4 V_191 ,
struct V_192 * V_193 , unsigned int V_194 )
{
struct V_3 * V_4 = F_62 ( V_78 ) ;
if ( V_4 -> V_14 -> V_196 )
return V_4 -> V_14 -> V_196 ( V_4 , V_191 ,
V_193 , V_194 ) ;
return 0 ;
}
static int F_100 ( struct V_88 * V_78 , T_4 V_191 )
{
struct V_3 * V_4 = F_62 ( V_78 ) ;
if ( V_4 -> V_14 -> V_197 )
return V_4 -> V_14 -> V_197 ( V_4 , V_191 ) ;
return 0 ;
}
static struct V_88 * F_101 ( struct V_1 * V_2 ,
struct V_132 * V_198 , int V_199 )
{
struct V_5 * V_49 = F_2 ( V_2 ) ;
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_88 * V_78 , * V_200 ;
struct V_74 * V_75 ;
struct V_201 * V_202 ;
int V_133 ;
struct V_203 * V_129 = F_102 ( V_198 ) ;
F_3 ( V_4 , L_25 ) ;
if ( ! V_199 )
V_78 = F_103 ( & V_204 , sizeof( * V_75 ) ) ;
else
V_78 = F_104 ( V_129 , sizeof( * V_75 ) ) ;
if ( ! V_78 ) {
F_3 ( V_4 , L_26 ) ;
V_133 = - V_56 ;
goto V_54;
}
V_75 = F_42 ( V_78 ) ;
V_75 -> V_78 = V_78 ;
V_75 -> V_89 = V_2 ;
V_75 -> V_205 = F_62 ;
V_75 -> V_206 = V_207 ;
V_75 -> V_208 = V_209 ;
F_105 ( & V_75 -> V_210 , V_211 ) ;
F_106 ( V_78 ) ;
V_133 = F_44 ( V_78 ) ;
if ( V_133 ) {
F_3 ( V_4 , L_27
L_28 ) ;
goto V_212;
}
if ( V_199 ) {
F_3 ( V_4 , L_29
L_30 ,
V_129 -> V_213 , V_129 -> V_214 ) ;
F_58 ( V_78 , V_129 -> V_213 ) ;
F_59 ( V_78 , V_129 -> V_214 ) ;
}
V_133 = F_50 ( V_78 , V_4 ) ;
if ( V_133 ) {
F_3 ( V_4 , L_31
L_28 ) ;
goto V_215;
}
V_133 = F_60 ( V_78 , V_198 ) ;
if ( V_133 ) {
F_3 ( V_4 , L_32
L_28 ) ;
goto V_215;
}
V_133 = F_107 ( V_78 , V_49 , & V_216 , 1 ) ;
if ( V_133 ) {
F_3 ( V_4 , L_33
L_28 ) ;
goto V_215;
}
F_65 ( V_78 , V_4 ) ;
if ( ! V_199 )
V_133 = F_83 ( V_78 ) ;
else {
V_202 = F_108 ( V_129 ) ;
V_200 = F_109 ( V_202 ) ;
V_133 = F_110 ( V_200 , V_78 ) ;
}
if ( V_133 ) {
F_3 ( V_4 , L_34 ) ;
goto V_215;
}
return V_78 ;
V_215:
F_96 ( V_78 ) ;
V_212:
F_111 ( V_78 ) ;
F_34 ( V_78 -> V_68 ) ;
V_54:
return F_15 ( V_133 ) ;
}
static int T_5 F_112 ( void )
{
V_143 =
F_113 ( & V_217 ) ;
V_142 =
F_113 ( & V_218 ) ;
if ( ! V_143 ) {
F_67 ( V_189 L_35 ) ;
return - V_219 ;
}
return 0 ;
}
static int T_6 F_114 ( void )
{
F_115 ( V_143 ) ;
F_115 ( V_142 ) ;
V_143 = NULL ;
V_142 = NULL ;
return 0 ;
}
static void F_116 ( unsigned int V_220 )
{
struct V_221 * V_222 ;
struct V_223 * V_224 ;
V_224 = F_117 ( & V_225 , V_220 ) ;
F_118 ( & V_224 -> V_226 . V_227 ) ;
V_222 = V_224 -> V_228 ;
V_224 -> V_228 = NULL ;
V_224 -> V_229 = 0 ;
F_119 ( & V_224 -> V_226 . V_227 ) ;
if ( V_222 )
F_120 ( V_222 ) ;
F_121 ( & V_224 -> V_230 ) ;
}
static inline unsigned int F_122 ( void )
{
static unsigned int V_231 ;
V_231 = F_123 ( V_231 , V_232 ) ;
if ( V_231 >= V_233 )
V_231 = F_124 ( V_232 ) ;
return V_231 ;
}
static int V_37 ( struct V_69 * V_70 , struct V_3 * V_4 ,
struct V_71 * V_72 , struct V_3 * V_234 )
{
struct V_88 * V_78 ;
struct V_235 * V_236 ;
struct V_5 * V_49 ;
struct V_1 * V_2 ;
struct V_167 * V_168 ;
struct V_223 * V_237 ;
struct V_80 * V_238 ;
unsigned int V_220 ;
V_2 = F_35 ( V_72 , struct V_1 , V_35 ) ;
V_49 = F_2 ( V_2 ) ;
V_78 = V_49 -> V_67 ;
if ( F_125 ( ! V_78 ) ) {
F_3 ( V_4 , L_36 ) ;
goto V_239;
}
if ( ! V_78 -> V_91 )
goto V_239;
F_3 ( V_4 ,
L_37 ,
V_70 -> V_240 , V_70 -> V_171 , V_70 -> V_241 , V_70 -> V_85 ,
F_126 ( V_70 ) , F_127 ( V_70 ) ,
V_70 -> V_242 , V_70 -> V_39 ? V_70 -> V_39 -> V_148 : L_38 ) ;
V_70 = F_128 ( V_70 , V_243 ) ;
if ( V_70 == NULL )
return V_244 ;
V_238 = F_129 ( V_70 ) ;
if ( F_130 ( V_49 ) &&
! F_131 ( V_238 -> V_245 , V_49 -> V_246 ) ) {
F_3 ( V_4 , L_39 ,
V_238 -> V_245 ) ;
goto V_51;
}
if ( F_125 ( ( V_70 -> V_240 < V_247 ) ||
! F_132 ( V_70 , V_248 ) ) )
goto V_51;
F_133 ( V_70 , sizeof( struct V_123 ) ) ;
V_168 = (struct V_167 * ) F_134 ( V_70 ) ;
if ( F_135 ( & V_238 -> V_249 [ 3 ] ) != F_135 ( V_168 -> V_250 ) ) {
F_3 ( V_4 , L_40 ,
V_238 -> V_249 ) ;
goto V_51;
}
V_236 = F_136 ( V_70 ) ;
V_236 -> V_251 = V_78 ;
if ( F_135 ( V_168 -> V_252 ) & V_253 )
V_220 = F_41 ( V_168 -> V_254 ) & V_255 ;
else {
if ( F_41 ( V_168 -> V_175 ) == V_176 )
V_220 = F_122 () ;
else
V_220 = F_41 ( V_168 -> V_175 ) & V_255 ;
}
if ( V_220 >= V_233 )
goto V_51;
V_237 = & F_137 ( V_225 , V_220 ) ;
F_138 ( & V_237 -> V_226 . V_227 ) ;
F_139 ( & V_237 -> V_226 , V_70 ) ;
F_140 ( V_220 , & V_237 -> V_230 ) ;
F_141 ( & V_237 -> V_226 . V_227 ) ;
return V_256 ;
V_51:
F_117 ( V_78 -> V_257 , F_142 () ) -> V_258 ++ ;
F_143 () ;
V_239:
F_144 ( V_70 ) ;
return V_244 ;
}
static int F_145 ( struct V_69 * V_70 , int V_259 )
{
struct V_223 * V_237 ;
int V_133 ;
V_237 = & F_146 ( V_225 ) ;
V_133 = F_147 ( V_70 , V_259 , V_237 ) ;
F_148 ( V_225 ) ;
return V_133 ;
}
static int F_149 ( struct V_88 * V_78 , struct V_165 * V_166 )
{
int V_260 ;
T_2 V_261 ;
struct V_80 * V_238 ;
struct V_124 * V_262 ;
struct V_69 * V_70 ;
struct V_263 * V_257 ;
struct V_167 * V_168 ;
unsigned int V_264 ;
unsigned int V_259 ;
unsigned int V_265 ;
struct V_74 * V_75 = F_42 ( V_78 ) ;
struct V_1 * V_2 = V_75 -> V_89 ;
struct V_5 * V_49 = F_2 ( V_2 ) ;
T_1 V_266 , V_267 ;
struct V_123 * V_268 ;
F_150 ( ( F_151 ( V_166 ) % sizeof( T_2 ) ) != 0 ) ;
V_168 = F_78 ( V_166 ) ;
V_70 = F_152 ( V_166 ) ;
V_260 = V_70 -> V_240 / V_269 ;
if ( ! V_78 -> V_91 ) {
F_144 ( V_70 ) ;
return 0 ;
}
if ( F_125 ( V_168 -> V_270 == V_271 ) &&
F_153 ( V_49 , V_78 , V_70 ) )
return 0 ;
V_266 = F_154 ( V_166 ) ;
V_267 = F_155 ( V_166 ) ;
V_265 = sizeof( struct V_80 ) ;
V_264 = sizeof( struct V_123 ) ;
V_259 = sizeof( struct V_124 ) ;
V_260 = ( V_70 -> V_240 - V_259 + sizeof( V_261 ) ) / V_269 ;
if ( F_156 ( V_78 -> V_103 ) ) {
V_70 -> V_272 = V_273 ;
V_70 -> V_274 = F_157 ( V_70 ) ;
V_70 -> V_275 = V_70 -> V_240 ;
V_261 = 0 ;
} else {
V_70 -> V_272 = V_276 ;
V_261 = F_158 ( V_166 ) ;
}
if ( F_159 ( V_70 ) ) {
T_7 * V_277 ;
if ( F_145 ( V_70 , V_259 ) ) {
F_144 ( V_70 ) ;
return - V_56 ;
}
V_277 = & F_160 ( V_70 ) -> V_278 [ F_160 ( V_70 ) -> V_279 - 1 ] ;
V_262 = F_161 ( F_162 ( V_277 ) )
+ V_277 -> V_280 ;
} else {
V_262 = (struct V_124 * ) F_163 ( V_70 , V_259 ) ;
}
memset ( V_262 , 0 , sizeof( * V_262 ) ) ;
V_262 -> V_281 = V_267 ;
V_262 -> V_282 = F_164 ( ~ V_261 ) ;
if ( F_159 ( V_70 ) ) {
F_165 ( V_262 ) ;
V_262 = NULL ;
}
F_166 ( V_70 , V_265 + V_264 ) ;
F_167 ( V_70 ) ;
F_168 ( V_70 ) ;
V_70 -> V_283 = V_265 ;
V_70 -> V_284 = F_11 ( V_38 ) ;
V_70 -> V_285 = V_2 -> V_285 ;
if ( V_2 -> V_4 -> V_16 & V_21 &&
V_2 -> V_22 -> V_109 & V_286 ) {
V_70 -> V_39 = V_2 -> V_22 ;
F_169 ( V_70 , F_11 ( V_287 ) ,
F_51 ( V_2 -> V_4 ) ) ;
} else
V_70 -> V_39 = V_2 -> V_4 ;
V_238 = F_129 ( V_70 ) ;
V_238 -> V_288 = F_11 ( V_38 ) ;
memcpy ( V_238 -> V_249 , V_49 -> V_246 , V_11 ) ;
if ( V_49 -> V_289 )
memcpy ( V_238 -> V_249 + 3 , V_168 -> V_250 , 3 ) ;
if ( F_125 ( V_49 -> V_290 != V_176 ) )
memcpy ( V_238 -> V_245 , V_49 -> V_25 , V_11 ) ;
else
memcpy ( V_238 -> V_245 , V_75 -> V_90 , V_11 ) ;
V_268 = (struct V_123 * ) ( V_238 + 1 ) ;
memset ( V_268 , 0 , sizeof( * V_268 ) ) ;
if ( V_291 )
F_170 ( V_268 , V_291 ) ;
V_268 -> V_292 = V_266 ;
if ( V_78 -> V_104 && F_171 ( V_166 ) ) {
F_160 ( V_70 ) -> V_293 = V_294 ;
F_160 ( V_70 ) -> V_295 = F_171 ( V_166 ) ;
} else {
F_160 ( V_70 ) -> V_293 = 0 ;
F_160 ( V_70 ) -> V_295 = 0 ;
}
V_257 = F_117 ( V_78 -> V_257 , F_142 () ) ;
V_257 -> V_296 ++ ;
V_257 -> V_297 += V_260 ;
F_143 () ;
V_251 ( V_166 ) = V_78 ;
F_37 ( V_75 , V_70 ) ;
return 0 ;
}
static inline int F_172 ( struct V_88 * V_78 ,
struct V_165 * V_166 )
{
struct V_5 * V_49 ;
struct V_1 * V_2 ;
struct V_167 * V_168 ;
struct V_69 * V_70 = (struct V_69 * ) V_166 ;
struct V_263 * V_257 ;
if ( V_78 -> V_103 && V_70 -> V_272 == V_298 )
F_173 ( V_166 ) &= ~ V_299 ;
else
F_173 ( V_166 ) |= V_299 ;
V_168 = (struct V_167 * ) F_134 ( V_70 ) ;
V_168 = F_78 ( V_166 ) ;
if ( V_168 -> V_173 == V_300 && V_168 -> V_270 == V_301 )
return 0 ;
V_2 = ( (struct V_74 * ) F_42 ( V_78 ) ) -> V_89 ;
V_49 = F_2 ( V_2 ) ;
if ( F_130 ( V_49 ) && F_174 ( V_166 ) == V_302 &&
F_135 ( V_168 -> V_303 ) == V_304 ) {
F_17 ( L_41 ) ;
return - V_125 ;
}
if ( ! ( F_173 ( V_166 ) & V_299 ) ||
F_175 ( F_176 ( V_166 ) ) == ~ F_177 ( ~ 0 , V_70 -> V_85 , V_70 -> V_240 ) ) {
F_173 ( V_166 ) &= ~ V_299 ;
return 0 ;
}
V_257 = F_117 ( V_78 -> V_257 , F_142 () ) ;
V_257 -> V_305 ++ ;
if ( V_257 -> V_305 < 5 )
F_67 ( V_306 L_42 ) ;
F_143 () ;
return - V_125 ;
}
static void F_178 ( struct V_69 * V_70 )
{
T_2 F_151 ;
struct V_88 * V_78 ;
struct V_235 * V_236 ;
struct V_263 * V_257 ;
struct V_124 V_222 ;
struct V_165 * V_166 ;
struct V_74 * V_75 ;
struct V_123 * V_268 ;
V_236 = F_136 ( V_70 ) ;
V_78 = V_236 -> V_251 ;
if ( F_125 ( ! V_78 ) ) {
F_3 ( V_70 -> V_39 , L_43 ) ;
F_144 ( V_70 ) ;
return;
}
F_3 ( V_70 -> V_39 ,
L_37 ,
V_70 -> V_240 , V_70 -> V_171 ,
V_70 -> V_241 , V_70 -> V_85 , F_126 ( V_70 ) ,
F_127 ( V_70 ) , V_70 -> V_242 ,
V_70 -> V_39 ? V_70 -> V_39 -> V_148 : L_38 ) ;
V_75 = F_42 ( V_78 ) ;
F_179 ( V_70 ) ;
V_268 = (struct V_123 * ) F_180 ( V_70 ) ;
V_257 = F_117 ( V_78 -> V_257 , F_142 () ) ;
if ( F_125 ( F_181 ( V_268 ) != V_291 ) ) {
if ( V_257 -> V_258 < 5 )
F_67 ( V_306 L_44
L_45
L_46
L_47
L_48 , F_181 ( V_268 ) ,
V_291 ) ;
goto V_307;
}
F_182 ( V_70 , sizeof( struct V_123 ) ) ;
F_151 = V_70 -> V_240 - sizeof( struct V_124 ) ;
V_257 -> V_308 ++ ;
V_257 -> V_309 += F_151 / V_269 ;
V_166 = (struct V_165 * ) V_70 ;
F_183 ( V_166 ) ;
V_251 ( V_166 ) = V_78 ;
F_154 ( V_166 ) = V_268 -> V_292 ;
if ( F_184 ( V_70 , F_151 , & V_222 , sizeof( V_222 ) ) )
goto V_307;
F_155 ( V_166 ) = V_222 . V_281 ;
F_176 ( V_166 ) = V_222 . V_282 ;
if ( F_185 ( V_70 , F_151 ) )
goto V_307;
if ( ! F_172 ( V_78 , V_166 ) ) {
F_143 () ;
F_186 ( V_78 , V_166 ) ;
return;
}
V_307:
V_257 -> V_258 ++ ;
F_143 () ;
F_144 ( V_70 ) ;
}
static void F_187 ( struct V_310 * V_230 )
{
struct V_223 * V_224 ;
struct V_69 * V_70 ;
struct V_311 V_312 ;
V_224 = F_35 ( V_230 , struct V_223 , V_230 ) ;
F_53 ( & V_312 ) ;
F_118 ( & V_224 -> V_226 . V_227 ) ;
F_188 ( & V_224 -> V_226 , & V_312 ) ;
F_119 ( & V_224 -> V_226 . V_227 ) ;
if ( ! F_189 ( & V_312 ) )
return;
while ( ( V_70 = F_190 ( & V_312 ) ) )
F_178 ( V_70 ) ;
}
static void F_191 ( void )
{
F_192 ( & V_313 ) ;
F_193 ( & V_314 ) ;
}
static void F_194 ( void )
{
F_195 ( & V_313 ) ;
F_196 ( & V_314 ) ;
}
static struct V_1 *
F_197 ( struct V_3 * V_4 )
{
struct V_1 * V_2 ;
struct V_3 * V_9 ;
F_84 (fcoe, &fcoe_hostlist, list) {
if ( V_2 -> V_4 -> V_16 & V_21 )
V_9 = F_4 ( V_2 -> V_4 ) ;
else
V_9 = V_2 -> V_4 ;
if ( V_4 == V_9 )
return V_2 ;
}
return NULL ;
}
static int F_198 ( struct V_315 * V_316 ,
T_8 V_317 , void * V_318 )
{
struct V_319 * V_320 = V_318 ;
struct V_5 * V_49 ;
struct V_1 * V_2 ;
struct V_3 * V_4 ;
int V_321 ;
if ( V_320 -> V_322 . V_323 != V_324 )
return V_325 ;
V_4 = F_199 ( & V_326 , V_320 -> V_327 ) ;
if ( ! V_4 )
return V_325 ;
V_2 = F_197 ( V_4 ) ;
F_24 ( V_4 ) ;
if ( ! V_2 )
return V_325 ;
V_49 = F_2 ( V_2 ) ;
if ( V_320 -> V_328 & V_329 )
V_321 = F_200 ( V_320 -> V_322 . V_285 ) - 1 ;
else
V_321 = V_320 -> V_322 . V_285 ;
if ( V_321 < 0 )
return V_325 ;
if ( V_320 -> V_322 . V_284 == V_42 ||
V_320 -> V_322 . V_284 == V_38 )
V_49 -> V_285 = V_321 ;
if ( V_320 -> V_322 . V_284 == V_38 )
V_2 -> V_285 = V_321 ;
return V_325 ;
}
static int F_201 ( struct V_315 * V_316 ,
T_8 V_317 , void * V_318 )
{
struct V_47 * V_58 ;
struct V_88 * V_78 = NULL ;
struct V_3 * V_4 = F_202 ( V_318 ) ;
struct V_5 * V_49 ;
struct V_1 * V_2 ;
struct V_74 * V_75 ;
struct V_263 * V_257 ;
T_2 V_330 = 1 ;
T_2 V_116 ;
int V_133 = V_325 ;
F_84 (fcoe, &fcoe_hostlist, list) {
if ( V_2 -> V_4 == V_4 ) {
V_49 = F_2 ( V_2 ) ;
V_78 = V_49 -> V_67 ;
break;
}
}
if ( ! V_78 ) {
V_133 = V_331 ;
goto V_54;
}
switch ( V_317 ) {
case V_332 :
case V_333 :
V_330 = 0 ;
break;
case V_334 :
case V_335 :
break;
case V_336 :
if ( V_4 -> V_109 & V_121 )
break;
V_116 = V_4 -> V_120 - ( sizeof( struct V_123 ) +
sizeof( struct V_124 ) ) ;
if ( V_116 >= V_337 )
F_52 ( V_78 , V_116 ) ;
break;
case V_338 :
break;
case V_339 :
F_203 ( & V_2 -> V_340 ) ;
V_75 = F_42 ( V_49 -> V_67 ) ;
F_204 ( V_341 , & V_75 -> V_210 ) ;
goto V_54;
break;
case V_342 :
F_47 ( V_78 , V_4 ) ;
break;
default:
F_3 ( V_4 , L_49
L_50 , V_317 ) ;
}
F_55 ( V_78 ) ;
V_58 = F_205 ( V_49 ) ;
if ( V_330 && ! F_206 ( V_78 ) ) {
switch ( V_58 -> V_343 ) {
case V_344 :
F_207 ( L_51 ) ;
break;
case V_345 :
case V_346 :
F_208 ( V_49 ) ;
} ;
} else if ( F_209 ( V_49 ) ) {
switch ( V_58 -> V_343 ) {
case V_344 :
F_207 ( L_52 ) ;
break;
case V_345 :
case V_346 :
V_257 = F_117 ( V_78 -> V_257 , F_142 () ) ;
V_257 -> V_347 ++ ;
F_143 () ;
F_91 ( V_78 ) ;
} ;
}
V_54:
return V_133 ;
}
static int F_210 ( struct V_3 * V_4 )
{
struct V_5 * V_49 ;
struct V_1 * V_2 ;
int V_133 = 0 ;
F_48 ( & V_348 ) ;
F_32 () ;
V_2 = F_211 ( V_4 ) ;
F_33 () ;
if ( V_2 ) {
V_49 = F_2 ( V_2 ) ;
F_209 ( V_49 ) ;
F_91 ( V_49 -> V_67 ) ;
} else
V_133 = - V_219 ;
F_49 ( & V_348 ) ;
return V_133 ;
}
static int F_212 ( struct V_3 * V_4 )
{
struct V_5 * V_49 ;
struct V_1 * V_2 ;
int V_133 = 0 ;
F_48 ( & V_348 ) ;
F_32 () ;
V_2 = F_211 ( V_4 ) ;
F_33 () ;
if ( ! V_2 ) {
V_133 = - V_219 ;
goto V_54;
}
V_49 = F_2 ( V_2 ) ;
if ( ! F_206 ( V_49 -> V_67 ) )
F_208 ( V_49 ) ;
V_54:
F_49 ( & V_348 ) ;
return V_133 ;
}
static int F_213 ( struct V_47 * V_58 )
{
struct V_5 * V_49 = F_18 ( V_58 ) ;
struct V_88 * V_78 = V_49 -> V_67 ;
struct V_3 * V_4 = F_62 ( V_78 ) ;
switch ( V_58 -> V_343 ) {
case V_345 :
return F_212 ( V_4 ) ;
case V_344 :
return F_210 ( V_4 ) ;
case V_346 :
default:
return - V_349 ;
} ;
}
static void F_214 ( struct V_47 * V_48 )
{
struct V_5 * V_49 = F_18 ( V_48 ) ;
struct V_1 * V_2 = F_19 ( V_49 ) ;
if ( V_48 -> V_30 == V_350 &&
V_49 -> V_30 != V_31 ) {
F_30 ( V_2 -> V_4 , V_34 ) ;
F_10 ( V_2 -> V_4 , V_32 ) ;
F_10 ( V_2 -> V_4 , V_33 ) ;
} else if ( V_49 -> V_30 != V_351 ) {
F_30 ( V_2 -> V_4 , V_32 ) ;
F_30 ( V_2 -> V_4 , V_33 ) ;
F_10 ( V_2 -> V_4 , V_34 ) ;
}
F_215 ( V_48 ) ;
}
static int F_216 ( struct V_3 * V_4 )
{
struct V_5 * V_49 ;
struct V_1 * V_2 ;
struct V_88 * V_78 ;
struct V_74 * V_75 ;
int V_133 = 0 ;
F_48 ( & V_348 ) ;
F_32 () ;
V_2 = F_211 ( V_4 ) ;
if ( ! V_2 ) {
V_133 = - V_219 ;
goto V_352;
}
V_49 = F_2 ( V_2 ) ;
V_78 = V_49 -> V_67 ;
V_75 = F_42 ( V_78 ) ;
F_203 ( & V_2 -> V_340 ) ;
F_204 ( V_341 , & V_75 -> V_210 ) ;
V_352:
F_33 () ;
F_49 ( & V_348 ) ;
return V_133 ;
}
static void V_211 ( struct V_310 * V_230 )
{
struct V_47 * V_58 ;
struct V_5 * V_49 ;
struct V_74 * V_75 ;
struct V_1 * V_2 ;
struct V_201 * V_202 ;
struct V_353 * V_354 ;
unsigned long V_18 ;
struct V_203 * V_129 ;
struct V_203 * V_355 ;
V_75 = F_35 ( V_230 , struct V_74 , V_210 ) ;
V_202 = V_75 -> V_78 -> V_68 ;
V_354 = F_217 ( V_202 ) ;
F_218 ( V_202 -> V_356 , V_18 ) ;
F_219 (vport, next_vport, &fc_host->vports, peers) {
if ( V_129 -> V_18 & ( V_357 | V_358 ) ) {
continue;
} else {
V_129 -> V_18 |= V_359 ;
F_204 ( F_220 ( V_202 ) ,
& V_129 -> V_360 ) ;
}
}
F_221 ( V_202 -> V_356 , V_18 ) ;
F_222 ( F_220 ( V_202 ) ) ;
F_48 ( & V_348 ) ;
V_2 = V_75 -> V_89 ;
V_49 = F_2 ( V_2 ) ;
V_58 = F_205 ( V_49 ) ;
F_87 ( V_75 -> V_78 ) ;
F_31 ( V_2 ) ;
F_49 ( & V_348 ) ;
F_23 ( V_58 ) ;
}
static bool F_223 ( struct V_3 * V_4 )
{
return true ;
}
static void F_224 ( struct V_1 * V_2 )
{
#ifdef F_225
int V_328 ;
T_1 V_361 , V_362 ;
struct V_3 * V_4 = V_2 -> V_22 ;
struct V_5 * V_49 = F_2 ( V_2 ) ;
struct V_363 V_322 = {
. V_285 = 0 ,
. V_284 = V_38
} ;
if ( V_4 && V_4 -> V_364 && V_4 -> V_364 -> V_365 ) {
V_328 = V_4 -> V_364 -> V_365 ( V_4 ) ;
if ( V_328 & V_366 ) {
V_322 . V_323 = V_367 ;
V_362 = F_226 ( V_4 , & V_322 ) ;
V_322 . V_284 = V_42 ;
V_361 = F_226 ( V_4 , & V_322 ) ;
} else {
V_322 . V_323 = V_324 ;
V_362 = F_227 ( V_4 , & V_322 ) ;
V_322 . V_284 = V_42 ;
V_361 = F_227 ( V_4 , & V_322 ) ;
}
V_2 -> V_285 = F_200 ( V_362 ) ? F_200 ( V_362 ) - 1 : 0 ;
V_49 -> V_285 = F_200 ( V_361 ) ? F_200 ( V_361 ) - 1 : V_2 -> V_285 ;
}
#endif
}
static int F_228 ( struct V_3 * V_4 , enum V_46 V_46 ,
enum V_368 V_369 )
{
int V_133 = 0 ;
struct V_47 * V_48 ;
struct V_5 * V_49 ;
struct V_1 * V_2 ;
struct V_88 * V_78 ;
F_48 ( & V_348 ) ;
F_32 () ;
if ( F_229 ( V_4 ) ) {
V_133 = - V_370 ;
goto V_352;
}
V_2 = F_13 ( V_4 , V_46 ) ;
if ( F_230 ( V_2 ) ) {
V_133 = F_231 ( V_2 ) ;
goto V_352;
}
V_49 = F_2 ( V_2 ) ;
V_48 = F_205 ( V_49 ) ;
V_78 = F_101 ( V_2 , & V_48 -> V_39 , 0 ) ;
if ( F_230 ( V_78 ) ) {
F_67 ( V_189 L_53 ,
V_4 -> V_148 ) ;
V_133 = - V_371 ;
F_33 () ;
F_31 ( V_2 ) ;
F_49 ( & V_348 ) ;
F_23 ( V_48 ) ;
goto V_54;
}
V_49 -> V_67 = V_78 ;
F_224 ( V_2 ) ;
V_78 -> V_372 = V_373 ;
F_232 ( V_78 ) ;
if ( V_369 == V_374 )
V_48 -> V_343 = V_345 ;
else
V_48 -> V_343 = V_344 ;
if ( V_369 == V_374 &&
! F_206 ( V_78 ) ) {
F_33 () ;
F_208 ( V_49 ) ;
F_49 ( & V_348 ) ;
return V_133 ;
}
V_352:
F_33 () ;
F_49 ( & V_348 ) ;
V_54:
return V_133 ;
}
static int F_233 ( struct V_3 * V_4 , enum V_46 V_46 )
{
return F_228 ( V_4 , V_46 , V_374 ) ;
}
static int F_234 ( struct V_3 * V_4 )
{
return F_228 ( V_4 , V_351 ,
V_375 ) ;
}
static int F_206 ( struct V_88 * V_78 )
{
struct V_3 * V_4 = F_62 ( V_78 ) ;
if ( F_235 ( V_4 ) )
return 0 ;
return - 1 ;
}
static void F_92 ( struct V_88 * V_78 )
{
struct V_223 * V_376 ;
unsigned int V_220 ;
F_236 (cpu) {
V_376 = & F_137 ( V_225 , V_220 ) ;
F_121 ( & V_376 -> V_230 ) ;
}
}
static int F_237 ( struct V_201 * V_202 )
{
struct V_88 * V_78 = F_109 ( V_202 ) ;
struct V_74 * V_75 = F_42 ( V_78 ) ;
struct V_1 * V_2 = V_75 -> V_89 ;
struct V_5 * V_49 = F_2 ( V_2 ) ;
struct V_47 * V_58 = F_205 ( V_49 ) ;
F_209 ( V_49 ) ;
F_91 ( V_49 -> V_67 ) ;
if ( V_58 -> V_343 != V_344 &&
! F_206 ( V_49 -> V_67 ) )
F_208 ( V_49 ) ;
return 0 ;
}
static struct V_1 *
F_211 ( const struct V_3 * V_4 )
{
struct V_1 * V_2 ;
F_84 (fcoe, &fcoe_hostlist, list) {
if ( V_2 -> V_4 == V_4 )
return V_2 ;
}
return NULL ;
}
static struct V_88 * F_229 ( const struct V_3 * V_4 )
{
struct V_5 * V_49 ;
struct V_1 * V_2 ;
V_2 = F_211 ( V_4 ) ;
V_49 = F_2 ( V_2 ) ;
return ( V_2 ) ? V_49 -> V_67 : NULL ;
}
static int F_106 ( const struct V_88 * V_78 )
{
struct V_1 * V_2 ;
struct V_74 * V_75 ;
V_2 = F_211 ( F_62 ( V_78 ) ) ;
if ( ! V_2 ) {
V_75 = F_42 ( V_78 ) ;
V_2 = V_75 -> V_89 ;
F_238 ( & V_2 -> V_340 , & V_377 ) ;
}
return 0 ;
}
static void F_111 ( const struct V_88 * V_78 )
{
struct V_1 * V_2 ;
struct V_74 * V_75 ;
V_75 = F_42 ( V_78 ) ;
V_2 = V_75 -> V_89 ;
F_203 ( & V_2 -> V_340 ) ;
return;
}
static int T_5 F_239 ( void )
{
struct V_223 * V_224 ;
unsigned int V_220 ;
int V_133 = 0 ;
V_341 = F_240 ( L_54 , 0 , 0 ) ;
if ( ! V_341 )
return - V_56 ;
V_133 = F_241 ( & V_378 ) ;
if ( V_133 ) {
F_67 ( V_189 L_55
L_56 ) ;
goto V_379;
}
F_48 ( & V_348 ) ;
F_236 (cpu) {
V_224 = F_117 ( & V_225 , V_220 ) ;
F_105 ( & V_224 -> V_230 , F_187 ) ;
F_53 ( & V_224 -> V_226 ) ;
}
F_191 () ;
V_133 = F_112 () ;
if ( V_133 )
goto V_380;
F_49 ( & V_348 ) ;
return 0 ;
V_380:
F_49 ( & V_348 ) ;
V_379:
F_242 ( V_341 ) ;
return V_133 ;
}
static void T_6 F_243 ( void )
{
struct V_1 * V_2 , * V_312 ;
struct V_5 * V_49 ;
struct V_74 * V_75 ;
unsigned int V_220 ;
F_48 ( & V_348 ) ;
F_194 () ;
F_32 () ;
F_219 (fcoe, tmp, &fcoe_hostlist, list) {
V_49 = F_2 ( V_2 ) ;
V_75 = F_42 ( V_49 -> V_67 ) ;
F_111 ( V_75 -> V_78 ) ;
F_204 ( V_341 , & V_75 -> V_210 ) ;
}
F_33 () ;
F_236 (cpu)
F_116 ( V_220 ) ;
F_49 ( & V_348 ) ;
F_242 ( V_341 ) ;
F_114 () ;
F_244 ( & V_378 ) ;
}
static void F_245 ( struct V_381 * V_382 , struct V_165 * V_166 , void * V_383 )
{
struct V_5 * V_6 = V_383 ;
struct V_384 * V_385 = F_246 ( V_382 ) ;
struct V_88 * V_78 = V_385 -> V_67 ;
T_1 * V_386 ;
if ( F_230 ( V_166 ) )
goto V_387;
V_386 = F_247 ( V_166 ) -> V_388 ;
if ( F_43 ( V_386 ) )
F_248 ( V_6 , V_78 , V_166 ) ;
if ( ! F_43 ( V_386 ) )
V_62 ( V_78 , V_386 ) ;
V_387:
F_249 ( V_382 , V_166 , V_78 ) ;
}
static void F_250 ( struct V_381 * V_382 , struct V_165 * V_166 , void * V_383 )
{
struct V_88 * V_78 = V_383 ;
static T_1 V_389 [ V_11 ] = { 0 } ;
if ( ! F_230 ( V_166 ) )
V_62 ( V_78 , V_389 ) ;
F_251 ( V_382 , V_166 , V_78 ) ;
}
static struct V_381 * F_252 ( struct V_88 * V_78 , T_2 V_390 ,
struct V_165 * V_166 , unsigned int V_391 ,
void (* F_253)( struct V_381 * ,
struct V_165 * ,
void * ) ,
void * V_383 , T_2 V_392 )
{
struct V_74 * V_75 = F_42 ( V_78 ) ;
struct V_1 * V_2 = V_75 -> V_89 ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_167 * V_168 = F_78 ( V_166 ) ;
switch ( V_391 ) {
case V_393 :
case V_394 :
if ( V_78 -> V_395 )
break;
return F_254 ( V_78 , V_390 , V_166 , V_391 , F_245 ,
V_6 , V_392 ) ;
case V_302 :
if ( F_135 ( V_168 -> V_250 ) != V_304 )
break;
return F_254 ( V_78 , V_390 , V_166 , V_391 , F_250 ,
V_78 , V_392 ) ;
}
return F_254 ( V_78 , V_390 , V_166 , V_391 , F_253 , V_383 , V_392 ) ;
}
static int F_255 ( struct V_203 * V_129 , bool V_396 )
{
struct V_201 * V_202 = F_108 ( V_129 ) ;
struct V_88 * V_200 = F_109 ( V_202 ) ;
struct V_74 * V_75 = F_42 ( V_200 ) ;
struct V_1 * V_2 = V_75 -> V_89 ;
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_88 * V_397 ;
int V_133 ;
char V_398 [ 32 ] ;
V_133 = F_256 ( V_129 ) ;
if ( V_133 ) {
F_257 ( V_129 -> V_214 , V_398 , sizeof( V_398 ) ) ;
F_67 ( V_189 L_57
L_58 ,
V_398 ) ;
return V_133 ;
}
F_48 ( & V_348 ) ;
F_32 () ;
V_397 = F_101 ( V_2 , & V_129 -> V_39 , 1 ) ;
F_33 () ;
F_49 ( & V_348 ) ;
if ( F_230 ( V_397 ) ) {
F_67 ( V_189 L_59 ,
V_4 -> V_148 ) ;
return - V_371 ;
}
if ( V_396 ) {
F_258 ( V_129 , V_399 ) ;
} else {
V_397 -> V_372 = V_373 ;
F_232 ( V_397 ) ;
F_259 ( V_397 ) ;
}
return 0 ;
}
static int F_260 ( struct V_203 * V_129 )
{
struct V_201 * V_202 = F_108 ( V_129 ) ;
struct V_88 * V_200 = F_109 ( V_202 ) ;
struct V_88 * V_397 = V_129 -> V_400 ;
F_48 ( & V_200 -> V_108 ) ;
F_203 ( & V_397 -> V_340 ) ;
F_49 ( & V_200 -> V_108 ) ;
F_48 ( & V_348 ) ;
F_87 ( V_397 ) ;
F_49 ( & V_348 ) ;
return 0 ;
}
static int F_261 ( struct V_203 * V_129 , bool V_401 )
{
struct V_88 * V_78 = V_129 -> V_400 ;
if ( V_401 ) {
F_258 ( V_129 , V_399 ) ;
F_88 ( V_78 ) ;
} else {
V_78 -> V_372 = V_373 ;
F_232 ( V_78 ) ;
F_259 ( V_78 ) ;
}
return 0 ;
}
static void F_262 ( struct V_203 * V_129 )
{
struct V_88 * V_78 = V_129 -> V_400 ;
struct V_165 * V_166 ;
T_9 V_240 ;
snprintf ( F_64 ( V_78 -> V_68 ) , V_145 ,
L_60 , V_146 , V_147 ,
F_62 ( V_78 ) -> V_148 , V_129 -> V_402 ) ;
if ( V_78 -> V_403 != V_404 )
return;
V_240 = F_263 ( F_64 ( V_78 -> V_68 ) , 255 ) ;
V_166 = F_264 ( V_78 ,
sizeof( struct V_405 ) +
sizeof( struct V_406 ) + V_240 ) ;
if ( ! V_166 )
return;
V_78 -> V_407 . V_408 ( V_78 , V_409 , V_166 , V_410 ,
NULL , NULL , 3 * V_78 -> V_96 ) ;
}
static void F_265 ( struct V_411 * V_412 )
{
struct V_47 * V_48 =
F_266 ( V_412 ) ;
struct V_5 * V_49 = F_18 ( V_48 ) ;
struct V_1 * V_2 = F_19 ( V_49 ) ;
V_412 -> V_413 = F_51 ( V_2 -> V_4 ) ;
}
static void F_267 ( struct V_88 * V_78 ,
T_2 V_414 , struct V_165 * V_166 )
{
struct V_74 * V_75 = F_42 ( V_78 ) ;
struct V_1 * V_2 = V_75 -> V_89 ;
struct V_5 * V_49 = F_2 ( V_2 ) ;
if ( V_166 && F_174 ( V_166 ) == V_393 )
F_248 ( V_49 , V_78 , V_166 ) ;
}
