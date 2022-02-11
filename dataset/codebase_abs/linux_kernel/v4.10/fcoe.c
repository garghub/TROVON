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
if ( F_41 ( V_84 -> V_81 . V_86 ) == V_42 &&
F_41 ( V_84 -> V_6 . V_87 ) == V_88 &&
V_2 -> V_22 != V_2 -> V_4 )
V_70 -> V_39 = V_2 -> V_22 ;
else
V_70 -> V_39 = V_2 -> V_4 ;
F_37 ( F_42 ( V_6 -> V_67 ) , V_70 ) ;
}
static void V_62 ( struct V_89 * V_78 , T_1 * V_24 )
{
struct V_74 * V_75 = F_42 ( V_78 ) ;
struct V_1 * V_2 = V_75 -> V_90 ;
if ( ! F_43 ( V_75 -> V_91 ) )
F_29 ( V_2 -> V_4 , V_75 -> V_91 ) ;
if ( ! F_43 ( V_24 ) )
F_9 ( V_2 -> V_4 , V_24 ) ;
memcpy ( V_75 -> V_91 , V_24 , V_11 ) ;
}
static T_1 * V_64 ( struct V_89 * V_78 )
{
struct V_74 * V_75 = F_42 ( V_78 ) ;
return V_75 -> V_91 ;
}
static int F_44 ( struct V_89 * V_78 )
{
V_78 -> V_92 = 0 ;
V_78 -> V_93 = 0 ;
V_78 -> V_94 = 3 ;
V_78 -> V_95 = 3 ;
V_78 -> V_96 = V_97 ;
V_78 -> V_98 = V_99 ;
V_78 -> V_100 = ( V_101 | V_102 |
V_103 | V_104 ) ;
V_78 -> V_105 = 1 ;
F_45 ( V_78 ) ;
F_46 ( V_78 ) ;
V_78 -> V_106 = 0 ;
V_78 -> V_107 = 0 ;
V_78 -> V_108 = 0 ;
V_78 -> V_109 = 0 ;
V_78 -> V_110 = 0 ;
return 0 ;
}
static void F_47 ( struct V_89 * V_78 ,
struct V_3 * V_4 )
{
F_48 ( & V_78 -> V_111 ) ;
if ( V_4 -> V_112 & V_113 )
V_78 -> V_114 = 1 ;
else
V_78 -> V_114 = 0 ;
if ( V_4 -> V_112 & V_115 ) {
V_78 -> V_106 = 1 ;
F_3 ( V_4 , L_7 ) ;
} else {
V_78 -> V_106 = 0 ;
}
if ( V_4 -> V_112 & V_116 ) {
V_78 -> V_107 = 1 ;
V_78 -> V_110 = V_4 -> V_117 ;
F_3 ( V_4 , L_8 ,
V_78 -> V_110 ) ;
} else {
V_78 -> V_107 = 0 ;
V_78 -> V_110 = 0 ;
}
if ( V_4 -> V_118 ) {
V_78 -> V_108 = 1 ;
V_78 -> V_109 = V_4 -> V_118 ;
F_3 ( V_4 , L_9 ,
V_78 -> V_109 ) ;
} else {
V_78 -> V_108 = 0 ;
V_78 -> V_109 = 0 ;
}
F_49 ( & V_78 -> V_111 ) ;
}
static int F_50 ( struct V_89 * V_78 , struct V_3 * V_4 )
{
T_2 V_119 ;
T_3 V_120 , V_121 ;
struct V_1 * V_2 ;
struct V_5 * V_49 ;
struct V_74 * V_75 ;
V_75 = F_42 ( V_78 ) ;
V_2 = V_75 -> V_90 ;
V_49 = F_2 ( V_2 ) ;
if ( V_4 -> V_16 & V_21 )
V_78 -> V_122 = F_51 ( V_4 ) ;
else
V_78 -> V_122 = 0 ;
V_119 = V_4 -> V_123 ;
if ( V_4 -> V_112 & V_124 ) {
V_119 = V_125 ;
F_3 ( V_4 , L_10 , V_119 ) ;
}
V_119 -= ( sizeof( struct V_126 ) + sizeof( struct V_127 ) ) ;
if ( F_52 ( V_78 , V_119 ) )
return - V_128 ;
F_47 ( V_78 , V_4 ) ;
F_53 ( & V_75 -> V_76 ) ;
V_75 -> V_129 = 0 ;
F_54 ( & V_75 -> V_130 , V_131 , ( unsigned long ) V_78 ) ;
F_55 ( V_78 ) ;
if ( ! V_78 -> V_132 ) {
if ( F_56 ( V_4 , & V_120 , V_133 ) )
V_120 = F_57 ( V_49 -> V_25 , 1 , 0 ) ;
F_58 ( V_78 , V_120 ) ;
if ( F_56 ( V_4 , & V_121 , V_134 ) )
V_121 = F_57 ( V_49 -> V_25 ,
2 , 0 ) ;
F_59 ( V_78 , V_121 ) ;
}
return 0 ;
}
static int F_60 ( struct V_89 * V_78 , struct V_135 * V_39 )
{
int V_136 = 0 ;
V_78 -> V_68 -> V_137 = V_138 ;
V_78 -> V_68 -> V_139 = V_140 ;
V_78 -> V_68 -> V_141 = 0 ;
V_78 -> V_68 -> V_142 = V_143 ;
if ( V_78 -> V_132 )
V_78 -> V_68 -> V_144 = V_145 ;
else
V_78 -> V_68 -> V_144 = V_146 ;
V_136 = F_61 ( V_78 -> V_68 , V_39 ) ;
if ( V_136 ) {
F_3 ( F_62 ( V_78 ) , L_11
L_12 ) ;
return V_136 ;
}
if ( ! V_78 -> V_132 )
F_63 ( V_78 -> V_68 ) = V_147 ;
snprintf ( F_64 ( V_78 -> V_68 ) , V_148 ,
L_13 , V_149 , V_150 ,
F_62 ( V_78 ) -> V_151 ) ;
return 0 ;
}
static void F_65 ( struct V_89 * V_78 , struct V_3 * V_4 )
{
struct V_1 * V_2 ;
struct V_74 * V_75 ;
struct V_3 * V_22 ;
int V_136 ;
V_75 = F_42 ( V_78 ) ;
V_2 = V_75 -> V_90 ;
V_22 = V_2 -> V_22 ;
if ( V_78 -> V_132 )
return;
if ( V_22 -> V_14 -> V_152 ) {
struct V_153 * V_154 ;
V_154 = F_66 ( sizeof( * V_154 ) , V_155 ) ;
if ( ! V_154 )
return;
V_136 = V_22 -> V_14 -> V_152 ( V_22 ,
V_154 ) ;
if ( V_136 ) {
F_67 ( V_156 L_14
L_15 ) ;
return;
}
snprintf ( F_68 ( V_78 -> V_68 ) ,
V_157 ,
L_16 ,
V_154 -> V_158 ) ;
snprintf ( F_69 ( V_78 -> V_68 ) ,
V_157 ,
L_16 ,
V_154 -> V_159 ) ;
snprintf ( F_70 ( V_78 -> V_68 ) ,
V_148 ,
L_16 ,
V_154 -> V_160 ) ;
snprintf ( F_71 ( V_78 -> V_68 ) ,
V_148 ,
L_16 ,
V_154 -> V_161 ) ;
snprintf ( F_72 ( V_78 -> V_68 ) ,
V_162 ,
L_16 ,
V_154 -> V_163 ) ;
snprintf ( F_73 ( V_78 -> V_68 ) ,
V_162 ,
L_16 ,
V_154 -> V_164 ) ;
snprintf ( F_74 ( V_78 -> V_68 ) ,
V_162 ,
L_16 ,
V_154 -> V_165 ) ;
snprintf ( F_75 ( V_78 -> V_68 ) ,
V_162 ,
L_16 ,
V_154 -> V_166 ) ;
V_78 -> V_167 = 1 ;
F_76 ( V_154 ) ;
} else {
V_78 -> V_167 = 0 ;
F_67 ( V_156 L_17 ) ;
}
}
static bool F_77 ( struct V_168 * V_169 )
{
struct V_170 * V_171 = F_78 ( V_169 ) ;
struct V_172 * V_173 ;
if ( F_79 ( F_80 ( V_169 ) ) &&
( F_80 ( V_169 ) -> V_174 > V_175 ) )
return true ;
else if ( ( F_80 ( V_169 ) == NULL ) &&
( V_171 -> V_176 == V_177 ) &&
( F_41 ( V_171 -> V_178 ) == V_179 ) ) {
V_173 = F_81 ( V_169 , sizeof( * V_173 ) ) ;
if ( ( V_173 -> V_180 & V_181 ) &&
( F_82 ( V_173 -> V_182 ) > V_175 ) )
return true ;
}
return false ;
}
static inline int F_83 ( struct V_89 * V_78 )
{
struct V_74 * V_75 = F_42 ( V_78 ) ;
struct V_1 * V_2 = V_75 -> V_90 ;
struct V_1 * V_183 = NULL ;
struct V_3 * V_184 , * V_185 ;
T_4 V_186 = V_187 ;
T_4 V_188 = V_189 ;
if ( ! V_78 -> V_108 || ! V_78 -> V_109 ||
( V_78 -> V_109 >= V_188 ) ) {
V_78 -> V_109 = 0 ;
goto V_190;
}
if ( V_2 -> V_4 -> V_16 & V_21 )
V_185 = F_4 ( V_2 -> V_4 ) ;
else
V_185 = V_2 -> V_4 ;
F_84 (oldfcoe, &fcoe_hostlist, list) {
if ( V_183 -> V_4 -> V_16 & V_21 )
V_184 = F_4 ( V_183 -> V_4 ) ;
else
V_184 = V_183 -> V_4 ;
if ( V_185 == V_184 ) {
V_2 -> V_191 = V_183 -> V_191 ;
break;
}
}
if ( V_2 -> V_191 ) {
if ( ! F_85 ( V_78 , V_2 -> V_191 , F_77 ) ) {
F_67 ( V_192 L_18
L_19 ,
V_2 -> V_191 , V_2 -> V_4 -> V_151 ) ;
return - V_56 ;
}
} else {
V_2 -> V_191 = F_86 ( V_78 , V_193 ,
V_187 , V_78 -> V_109 ,
F_77 ) ;
if ( ! V_2 -> V_191 ) {
F_67 ( V_192 L_20
L_21 ,
V_2 -> V_4 -> V_151 ) ;
return - V_56 ;
}
}
V_186 += V_78 -> V_109 + 1 ;
V_190:
if ( ! F_86 ( V_78 , V_193 , V_186 , V_188 , NULL ) ) {
F_67 ( V_192 L_22
L_23 , V_2 -> V_4 -> V_151 ) ;
return - V_56 ;
}
return 0 ;
}
static void F_87 ( struct V_89 * V_78 )
{
struct V_74 * V_75 = F_42 ( V_78 ) ;
struct V_1 * V_2 = V_75 -> V_90 ;
struct V_3 * V_4 = V_2 -> V_4 ;
F_3 ( V_4 , L_24 ) ;
F_88 ( V_78 ) ;
F_89 ( V_78 ) ;
F_90 ( & V_75 -> V_130 ) ;
F_91 ( V_78 ) ;
F_32 () ;
if ( ! F_43 ( V_75 -> V_91 ) )
F_29 ( V_4 , V_75 -> V_91 ) ;
if ( V_78 -> V_132 )
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
if ( V_78 -> V_132 )
F_34 ( V_78 -> V_68 ) ;
}
static int F_98 ( struct V_89 * V_78 , T_4 V_194 ,
struct V_195 * V_196 , unsigned int V_197 )
{
struct V_3 * V_4 = F_62 ( V_78 ) ;
if ( V_4 -> V_14 -> V_198 )
return V_4 -> V_14 -> V_198 ( V_4 ,
V_194 , V_196 ,
V_197 ) ;
return 0 ;
}
static int F_99 ( struct V_89 * V_78 , T_4 V_194 ,
struct V_195 * V_196 , unsigned int V_197 )
{
struct V_3 * V_4 = F_62 ( V_78 ) ;
if ( V_4 -> V_14 -> V_199 )
return V_4 -> V_14 -> V_199 ( V_4 , V_194 ,
V_196 , V_197 ) ;
return 0 ;
}
static int F_100 ( struct V_89 * V_78 , T_4 V_194 )
{
struct V_3 * V_4 = F_62 ( V_78 ) ;
if ( V_4 -> V_14 -> V_200 )
return V_4 -> V_14 -> V_200 ( V_4 , V_194 ) ;
return 0 ;
}
static struct V_89 * F_101 ( struct V_1 * V_2 ,
struct V_135 * V_201 , int V_202 )
{
struct V_5 * V_49 = F_2 ( V_2 ) ;
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_89 * V_78 , * V_203 ;
struct V_74 * V_75 ;
struct V_204 * V_205 ;
int V_136 ;
struct V_206 * V_132 = F_102 ( V_201 ) ;
F_3 ( V_4 , L_25 ) ;
if ( ! V_202 )
V_78 = F_103 ( & V_207 , sizeof( * V_75 ) ) ;
else
V_78 = F_104 ( V_132 , sizeof( * V_75 ) ) ;
if ( ! V_78 ) {
F_3 ( V_4 , L_26 ) ;
V_136 = - V_56 ;
goto V_54;
}
V_75 = F_42 ( V_78 ) ;
V_75 -> V_78 = V_78 ;
V_75 -> V_90 = V_2 ;
V_75 -> V_208 = F_62 ;
V_75 -> V_209 = V_210 ;
V_75 -> V_211 = V_212 ;
F_105 ( & V_75 -> V_213 , V_214 ) ;
F_106 ( V_78 ) ;
V_136 = F_44 ( V_78 ) ;
if ( V_136 ) {
F_3 ( V_4 , L_27
L_28 ) ;
goto V_215;
}
if ( V_202 ) {
F_3 ( V_4 , L_29
L_30 ,
V_132 -> V_216 , V_132 -> V_217 ) ;
F_58 ( V_78 , V_132 -> V_216 ) ;
F_59 ( V_78 , V_132 -> V_217 ) ;
}
V_136 = F_50 ( V_78 , V_4 ) ;
if ( V_136 ) {
F_3 ( V_4 , L_31
L_28 ) ;
goto V_218;
}
V_136 = F_60 ( V_78 , V_201 ) ;
if ( V_136 ) {
F_3 ( V_4 , L_32
L_28 ) ;
goto V_218;
}
V_136 = F_107 ( V_78 , V_49 , & V_219 , 1 ) ;
if ( V_136 ) {
F_3 ( V_4 , L_33
L_28 ) ;
goto V_218;
}
F_65 ( V_78 , V_4 ) ;
if ( ! V_202 )
V_136 = F_83 ( V_78 ) ;
else {
V_205 = F_108 ( V_132 ) ;
V_203 = F_109 ( V_205 ) ;
V_136 = F_110 ( V_203 , V_78 ) ;
}
if ( V_136 ) {
F_3 ( V_4 , L_34 ) ;
goto V_218;
}
return V_78 ;
V_218:
F_96 ( V_78 ) ;
V_215:
F_111 ( V_78 ) ;
F_34 ( V_78 -> V_68 ) ;
V_54:
return F_15 ( V_136 ) ;
}
static int T_5 F_112 ( void )
{
V_146 =
F_113 ( & V_220 ) ;
V_145 =
F_113 ( & V_221 ) ;
if ( ! V_146 ) {
F_67 ( V_192 L_35 ) ;
return - V_222 ;
}
return 0 ;
}
static int T_6 F_114 ( void )
{
F_115 ( V_146 ) ;
F_115 ( V_145 ) ;
V_146 = NULL ;
V_145 = NULL ;
return 0 ;
}
static void F_116 ( unsigned int V_223 )
{
struct V_224 * V_225 ;
struct V_226 * V_227 ;
V_227 = F_117 ( & V_228 , V_223 ) ;
F_118 ( & V_227 -> V_229 . V_230 ) ;
V_225 = V_227 -> V_231 ;
V_227 -> V_231 = NULL ;
V_227 -> V_232 = 0 ;
F_119 ( & V_227 -> V_229 . V_230 ) ;
if ( V_225 )
F_120 ( V_225 ) ;
F_121 ( & V_227 -> V_233 ) ;
}
static inline unsigned int F_122 ( void )
{
static unsigned int V_234 ;
V_234 = F_123 ( V_234 , V_235 ) ;
if ( V_234 >= V_236 )
V_234 = F_124 ( V_235 ) ;
return V_234 ;
}
static int V_37 ( struct V_69 * V_70 , struct V_3 * V_4 ,
struct V_71 * V_72 , struct V_3 * V_237 )
{
struct V_89 * V_78 ;
struct V_238 * V_239 ;
struct V_5 * V_49 ;
struct V_1 * V_2 ;
struct V_170 * V_171 ;
struct V_226 * V_240 ;
struct V_80 * V_241 ;
unsigned int V_223 ;
V_2 = F_35 ( V_72 , struct V_1 , V_35 ) ;
V_49 = F_2 ( V_2 ) ;
V_78 = V_49 -> V_67 ;
if ( F_125 ( ! V_78 ) ) {
F_3 ( V_4 , L_36 ) ;
goto V_242;
}
if ( ! V_78 -> V_92 )
goto V_242;
F_3 ( V_4 ,
L_37 ,
V_70 -> V_243 , V_70 -> V_174 , V_70 -> V_244 , V_70 -> V_85 ,
F_126 ( V_70 ) , F_127 ( V_70 ) ,
V_70 -> V_245 , V_70 -> V_39 ? V_70 -> V_39 -> V_151 : L_38 ) ;
V_70 = F_128 ( V_70 , V_246 ) ;
if ( V_70 == NULL )
return V_247 ;
V_241 = F_129 ( V_70 ) ;
if ( F_130 ( V_49 ) &&
! F_131 ( V_241 -> V_248 , V_49 -> V_249 ) ) {
F_3 ( V_4 , L_39 ,
V_241 -> V_248 ) ;
goto V_51;
}
if ( F_125 ( ( V_70 -> V_243 < V_250 ) ||
! F_132 ( V_70 , V_251 ) ) )
goto V_51;
F_133 ( V_70 , sizeof( struct V_126 ) ) ;
V_171 = (struct V_170 * ) F_134 ( V_70 ) ;
if ( F_135 ( & V_241 -> V_252 [ 3 ] ) != F_135 ( V_171 -> V_253 ) ) {
F_3 ( V_4 , L_40 ,
V_241 -> V_252 ) ;
goto V_51;
}
V_239 = F_136 ( V_70 ) ;
V_239 -> V_254 = V_78 ;
if ( F_135 ( V_171 -> V_255 ) & V_256 )
V_223 = F_41 ( V_171 -> V_257 ) & V_258 ;
else {
if ( F_41 ( V_171 -> V_178 ) == V_179 )
V_223 = F_122 () ;
else
V_223 = F_41 ( V_171 -> V_178 ) & V_258 ;
}
if ( V_223 >= V_236 )
goto V_51;
V_240 = & F_137 ( V_228 , V_223 ) ;
F_138 ( & V_240 -> V_229 . V_230 ) ;
F_139 ( & V_240 -> V_229 , V_70 ) ;
F_140 ( V_223 , & V_240 -> V_233 ) ;
F_141 ( & V_240 -> V_229 . V_230 ) ;
return V_259 ;
V_51:
F_117 ( V_78 -> V_260 , F_142 () ) -> V_261 ++ ;
F_143 () ;
V_242:
F_144 ( V_70 ) ;
return V_247 ;
}
static int F_145 ( struct V_69 * V_70 , int V_262 )
{
struct V_226 * V_240 ;
int V_136 ;
V_240 = & F_146 ( V_228 ) ;
V_136 = F_147 ( V_70 , V_262 , V_240 ) ;
F_148 ( V_228 ) ;
return V_136 ;
}
static int F_149 ( struct V_89 * V_78 , struct V_168 * V_169 )
{
int V_263 ;
T_2 V_264 ;
struct V_80 * V_241 ;
struct V_127 * V_265 ;
struct V_69 * V_70 ;
struct V_266 * V_260 ;
struct V_170 * V_171 ;
unsigned int V_267 ;
unsigned int V_262 ;
unsigned int V_268 ;
struct V_74 * V_75 = F_42 ( V_78 ) ;
struct V_1 * V_2 = V_75 -> V_90 ;
struct V_5 * V_49 = F_2 ( V_2 ) ;
T_1 V_269 , V_270 ;
struct V_126 * V_271 ;
F_150 ( ( F_151 ( V_169 ) % sizeof( T_2 ) ) != 0 ) ;
V_171 = F_78 ( V_169 ) ;
V_70 = F_152 ( V_169 ) ;
V_263 = V_70 -> V_243 / V_272 ;
if ( ! V_78 -> V_92 ) {
F_144 ( V_70 ) ;
return 0 ;
}
if ( F_125 ( V_171 -> V_273 == V_274 ) &&
F_153 ( V_49 , V_78 , V_70 ) )
return 0 ;
V_269 = F_154 ( V_169 ) ;
V_270 = F_155 ( V_169 ) ;
V_268 = sizeof( struct V_80 ) ;
V_267 = sizeof( struct V_126 ) ;
V_262 = sizeof( struct V_127 ) ;
V_263 = ( V_70 -> V_243 - V_262 + sizeof( V_264 ) ) / V_272 ;
if ( F_156 ( V_78 -> V_106 ) ) {
V_70 -> V_275 = V_276 ;
V_70 -> V_277 = F_157 ( V_70 ) ;
V_70 -> V_278 = V_70 -> V_243 ;
V_264 = 0 ;
} else {
V_70 -> V_275 = V_279 ;
V_264 = F_158 ( V_169 ) ;
}
if ( F_159 ( V_70 ) ) {
T_7 * V_280 ;
if ( F_145 ( V_70 , V_262 ) ) {
F_144 ( V_70 ) ;
return - V_56 ;
}
V_280 = & F_160 ( V_70 ) -> V_281 [ F_160 ( V_70 ) -> V_282 - 1 ] ;
V_265 = F_161 ( F_162 ( V_280 ) )
+ V_280 -> V_283 ;
} else {
V_265 = (struct V_127 * ) F_163 ( V_70 , V_262 ) ;
}
memset ( V_265 , 0 , sizeof( * V_265 ) ) ;
V_265 -> V_284 = V_270 ;
V_265 -> V_285 = F_164 ( ~ V_264 ) ;
if ( F_159 ( V_70 ) ) {
F_165 ( V_265 ) ;
V_265 = NULL ;
}
F_166 ( V_70 , V_268 + V_267 ) ;
F_167 ( V_70 ) ;
F_168 ( V_70 ) ;
V_70 -> V_286 = V_268 ;
V_70 -> V_287 = F_11 ( V_38 ) ;
V_70 -> V_288 = V_2 -> V_288 ;
if ( V_2 -> V_4 -> V_16 & V_21 &&
V_2 -> V_22 -> V_112 & V_289 ) {
V_70 -> V_39 = V_2 -> V_22 ;
F_169 ( V_70 , F_11 ( V_290 ) ,
F_51 ( V_2 -> V_4 ) ) ;
} else
V_70 -> V_39 = V_2 -> V_4 ;
V_241 = F_129 ( V_70 ) ;
V_241 -> V_86 = F_11 ( V_38 ) ;
memcpy ( V_241 -> V_252 , V_49 -> V_249 , V_11 ) ;
if ( V_49 -> V_291 )
memcpy ( V_241 -> V_252 + 3 , V_171 -> V_253 , 3 ) ;
if ( F_125 ( V_49 -> V_292 != V_179 ) )
memcpy ( V_241 -> V_248 , V_49 -> V_25 , V_11 ) ;
else
memcpy ( V_241 -> V_248 , V_75 -> V_91 , V_11 ) ;
V_271 = (struct V_126 * ) ( V_241 + 1 ) ;
memset ( V_271 , 0 , sizeof( * V_271 ) ) ;
if ( V_293 )
F_170 ( V_271 , V_293 ) ;
V_271 -> V_294 = V_269 ;
if ( V_78 -> V_107 && F_171 ( V_169 ) ) {
F_160 ( V_70 ) -> V_295 = V_296 ;
F_160 ( V_70 ) -> V_297 = F_171 ( V_169 ) ;
} else {
F_160 ( V_70 ) -> V_295 = 0 ;
F_160 ( V_70 ) -> V_297 = 0 ;
}
V_260 = F_117 ( V_78 -> V_260 , F_142 () ) ;
V_260 -> V_298 ++ ;
V_260 -> V_299 += V_263 ;
F_143 () ;
V_254 ( V_169 ) = V_78 ;
F_37 ( V_75 , V_70 ) ;
return 0 ;
}
static inline int F_172 ( struct V_89 * V_78 ,
struct V_168 * V_169 )
{
struct V_5 * V_49 ;
struct V_1 * V_2 ;
struct V_170 * V_171 ;
struct V_69 * V_70 = (struct V_69 * ) V_169 ;
struct V_266 * V_260 ;
if ( V_78 -> V_106 && V_70 -> V_275 == V_300 )
F_173 ( V_169 ) &= ~ V_301 ;
else
F_173 ( V_169 ) |= V_301 ;
V_171 = (struct V_170 * ) F_134 ( V_70 ) ;
V_171 = F_78 ( V_169 ) ;
if ( V_171 -> V_176 == V_302 && V_171 -> V_273 == V_303 )
return 0 ;
V_2 = ( (struct V_74 * ) F_42 ( V_78 ) ) -> V_90 ;
V_49 = F_2 ( V_2 ) ;
if ( F_130 ( V_49 ) && F_174 ( V_169 ) == V_304 &&
F_135 ( V_171 -> V_305 ) == V_306 ) {
F_17 ( L_41 ) ;
return - V_128 ;
}
if ( ! ( F_173 ( V_169 ) & V_301 ) ||
F_175 ( F_176 ( V_169 ) ) == ~ F_177 ( ~ 0 , V_70 -> V_85 , V_70 -> V_243 ) ) {
F_173 ( V_169 ) &= ~ V_301 ;
return 0 ;
}
V_260 = F_117 ( V_78 -> V_260 , F_142 () ) ;
V_260 -> V_307 ++ ;
if ( V_260 -> V_307 < 5 )
F_67 ( V_308 L_42 ) ;
F_143 () ;
return - V_128 ;
}
static void F_178 ( struct V_69 * V_70 )
{
T_2 F_151 ;
struct V_89 * V_78 ;
struct V_238 * V_239 ;
struct V_266 * V_260 ;
struct V_127 V_225 ;
struct V_168 * V_169 ;
struct V_74 * V_75 ;
struct V_126 * V_271 ;
V_239 = F_136 ( V_70 ) ;
V_78 = V_239 -> V_254 ;
if ( F_125 ( ! V_78 ) ) {
F_3 ( V_70 -> V_39 , L_43 ) ;
F_144 ( V_70 ) ;
return;
}
F_3 ( V_70 -> V_39 ,
L_37 ,
V_70 -> V_243 , V_70 -> V_174 ,
V_70 -> V_244 , V_70 -> V_85 , F_126 ( V_70 ) ,
F_127 ( V_70 ) , V_70 -> V_245 ,
V_70 -> V_39 ? V_70 -> V_39 -> V_151 : L_38 ) ;
V_75 = F_42 ( V_78 ) ;
F_179 ( V_70 ) ;
V_271 = (struct V_126 * ) F_180 ( V_70 ) ;
V_260 = F_117 ( V_78 -> V_260 , F_142 () ) ;
if ( F_125 ( F_181 ( V_271 ) != V_293 ) ) {
if ( V_260 -> V_261 < 5 )
F_67 ( V_308 L_44
L_45
L_46
L_47
L_48 , F_181 ( V_271 ) ,
V_293 ) ;
goto V_309;
}
F_182 ( V_70 , sizeof( struct V_126 ) ) ;
F_151 = V_70 -> V_243 - sizeof( struct V_127 ) ;
V_260 -> V_310 ++ ;
V_260 -> V_311 += F_151 / V_272 ;
V_169 = (struct V_168 * ) V_70 ;
F_183 ( V_169 ) ;
V_254 ( V_169 ) = V_78 ;
F_154 ( V_169 ) = V_271 -> V_294 ;
if ( F_184 ( V_70 , F_151 , & V_225 , sizeof( V_225 ) ) )
goto V_309;
F_155 ( V_169 ) = V_225 . V_284 ;
F_176 ( V_169 ) = V_225 . V_285 ;
if ( F_185 ( V_70 , F_151 ) )
goto V_309;
if ( ! F_172 ( V_78 , V_169 ) ) {
F_143 () ;
F_186 ( V_78 , V_169 ) ;
return;
}
V_309:
V_260 -> V_261 ++ ;
F_143 () ;
F_144 ( V_70 ) ;
}
static void F_187 ( struct V_312 * V_233 )
{
struct V_226 * V_227 ;
struct V_69 * V_70 ;
struct V_313 V_314 ;
V_227 = F_35 ( V_233 , struct V_226 , V_233 ) ;
F_53 ( & V_314 ) ;
F_118 ( & V_227 -> V_229 . V_230 ) ;
F_188 ( & V_227 -> V_229 , & V_314 ) ;
F_119 ( & V_227 -> V_229 . V_230 ) ;
if ( ! F_189 ( & V_314 ) )
return;
while ( ( V_70 = F_190 ( & V_314 ) ) )
F_178 ( V_70 ) ;
}
static void F_191 ( void )
{
F_192 ( & V_315 ) ;
F_193 ( & V_316 ) ;
}
static void F_194 ( void )
{
F_195 ( & V_315 ) ;
F_196 ( & V_316 ) ;
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
static int F_198 ( struct V_317 * V_318 ,
T_8 V_319 , void * V_320 )
{
struct V_321 * V_322 = V_320 ;
struct V_5 * V_49 ;
struct V_1 * V_2 ;
struct V_3 * V_4 ;
int V_323 ;
if ( V_322 -> V_324 . V_325 != V_326 )
return V_327 ;
V_4 = F_199 ( & V_328 , V_322 -> V_329 ) ;
if ( ! V_4 )
return V_327 ;
V_2 = F_197 ( V_4 ) ;
F_24 ( V_4 ) ;
if ( ! V_2 )
return V_327 ;
V_49 = F_2 ( V_2 ) ;
if ( V_322 -> V_330 & V_331 )
V_323 = F_200 ( V_322 -> V_324 . V_288 ) - 1 ;
else
V_323 = V_322 -> V_324 . V_288 ;
if ( V_323 < 0 )
return V_327 ;
if ( V_322 -> V_324 . V_287 == V_42 ||
V_322 -> V_324 . V_287 == V_38 )
V_49 -> V_288 = V_323 ;
if ( V_322 -> V_324 . V_287 == V_38 )
V_2 -> V_288 = V_323 ;
return V_327 ;
}
static int F_201 ( struct V_317 * V_318 ,
T_8 V_319 , void * V_320 )
{
struct V_47 * V_58 ;
struct V_89 * V_78 = NULL ;
struct V_3 * V_4 = F_202 ( V_320 ) ;
struct V_5 * V_49 ;
struct V_1 * V_2 ;
struct V_74 * V_75 ;
struct V_266 * V_260 ;
T_2 V_332 = 1 ;
T_2 V_119 ;
int V_136 = V_327 ;
F_84 (fcoe, &fcoe_hostlist, list) {
if ( V_2 -> V_4 == V_4 ) {
V_49 = F_2 ( V_2 ) ;
V_78 = V_49 -> V_67 ;
break;
}
}
if ( ! V_78 ) {
V_136 = V_333 ;
goto V_54;
}
switch ( V_319 ) {
case V_334 :
case V_335 :
V_332 = 0 ;
break;
case V_336 :
case V_337 :
break;
case V_338 :
if ( V_4 -> V_112 & V_124 )
break;
V_119 = V_4 -> V_123 - ( sizeof( struct V_126 ) +
sizeof( struct V_127 ) ) ;
if ( V_119 >= V_339 )
F_52 ( V_78 , V_119 ) ;
break;
case V_340 :
break;
case V_341 :
F_203 ( & V_2 -> V_342 ) ;
V_75 = F_42 ( V_49 -> V_67 ) ;
F_204 ( V_343 , & V_75 -> V_213 ) ;
goto V_54;
break;
case V_344 :
F_47 ( V_78 , V_4 ) ;
break;
default:
F_3 ( V_4 , L_49
L_50 , V_319 ) ;
}
F_55 ( V_78 ) ;
V_58 = F_205 ( V_49 ) ;
if ( V_332 && ! F_206 ( V_78 ) ) {
switch ( V_58 -> V_345 ) {
case V_346 :
F_207 ( L_51 ) ;
break;
case V_347 :
case V_348 :
F_208 ( V_49 ) ;
} ;
} else if ( F_209 ( V_49 ) ) {
switch ( V_58 -> V_345 ) {
case V_346 :
F_207 ( L_52 ) ;
break;
case V_347 :
case V_348 :
V_260 = F_117 ( V_78 -> V_260 , F_142 () ) ;
V_260 -> V_349 ++ ;
F_143 () ;
F_91 ( V_78 ) ;
} ;
}
V_54:
return V_136 ;
}
static int F_210 ( struct V_3 * V_4 )
{
struct V_5 * V_49 ;
struct V_1 * V_2 ;
int V_136 = 0 ;
F_48 ( & V_350 ) ;
F_32 () ;
V_2 = F_211 ( V_4 ) ;
F_33 () ;
if ( V_2 ) {
V_49 = F_2 ( V_2 ) ;
F_209 ( V_49 ) ;
F_91 ( V_49 -> V_67 ) ;
} else
V_136 = - V_222 ;
F_49 ( & V_350 ) ;
return V_136 ;
}
static int F_212 ( struct V_3 * V_4 )
{
struct V_5 * V_49 ;
struct V_1 * V_2 ;
int V_136 = 0 ;
F_48 ( & V_350 ) ;
F_32 () ;
V_2 = F_211 ( V_4 ) ;
F_33 () ;
if ( ! V_2 ) {
V_136 = - V_222 ;
goto V_54;
}
V_49 = F_2 ( V_2 ) ;
if ( ! F_206 ( V_49 -> V_67 ) )
F_208 ( V_49 ) ;
V_54:
F_49 ( & V_350 ) ;
return V_136 ;
}
static int F_213 ( struct V_47 * V_58 )
{
struct V_5 * V_49 = F_18 ( V_58 ) ;
struct V_89 * V_78 = V_49 -> V_67 ;
struct V_3 * V_4 = F_62 ( V_78 ) ;
switch ( V_58 -> V_345 ) {
case V_347 :
return F_212 ( V_4 ) ;
case V_346 :
return F_210 ( V_4 ) ;
case V_348 :
default:
return - V_351 ;
} ;
}
static void F_214 ( struct V_47 * V_48 )
{
struct V_5 * V_49 = F_18 ( V_48 ) ;
struct V_1 * V_2 = F_19 ( V_49 ) ;
if ( V_48 -> V_30 == V_352 &&
V_49 -> V_30 != V_31 ) {
F_30 ( V_2 -> V_4 , V_34 ) ;
F_10 ( V_2 -> V_4 , V_32 ) ;
F_10 ( V_2 -> V_4 , V_33 ) ;
} else if ( V_49 -> V_30 != V_353 ) {
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
struct V_89 * V_78 ;
struct V_74 * V_75 ;
int V_136 = 0 ;
F_48 ( & V_350 ) ;
F_32 () ;
V_2 = F_211 ( V_4 ) ;
if ( ! V_2 ) {
V_136 = - V_222 ;
goto V_354;
}
V_49 = F_2 ( V_2 ) ;
V_78 = V_49 -> V_67 ;
V_75 = F_42 ( V_78 ) ;
F_203 ( & V_2 -> V_342 ) ;
F_204 ( V_343 , & V_75 -> V_213 ) ;
V_354:
F_33 () ;
F_49 ( & V_350 ) ;
return V_136 ;
}
static void V_214 ( struct V_312 * V_233 )
{
struct V_47 * V_58 ;
struct V_5 * V_49 ;
struct V_74 * V_75 ;
struct V_1 * V_2 ;
struct V_204 * V_205 ;
struct V_355 * V_356 ;
unsigned long V_18 ;
struct V_206 * V_132 ;
struct V_206 * V_357 ;
V_75 = F_35 ( V_233 , struct V_74 , V_213 ) ;
V_205 = V_75 -> V_78 -> V_68 ;
V_356 = F_217 ( V_205 ) ;
F_218 ( V_205 -> V_358 , V_18 ) ;
F_219 (vport, next_vport, &fc_host->vports, peers) {
if ( V_132 -> V_18 & ( V_359 | V_360 ) ) {
continue;
} else {
V_132 -> V_18 |= V_361 ;
F_204 ( F_220 ( V_205 ) ,
& V_132 -> V_362 ) ;
}
}
F_221 ( V_205 -> V_358 , V_18 ) ;
F_222 ( F_220 ( V_205 ) ) ;
F_48 ( & V_350 ) ;
V_2 = V_75 -> V_90 ;
V_49 = F_2 ( V_2 ) ;
V_58 = F_205 ( V_49 ) ;
F_87 ( V_75 -> V_78 ) ;
F_31 ( V_2 ) ;
F_49 ( & V_350 ) ;
F_23 ( V_58 ) ;
}
static bool F_223 ( struct V_3 * V_4 )
{
return true ;
}
static void F_224 ( struct V_1 * V_2 )
{
int V_363 = V_364 ;
int V_365 = V_366 ;
struct V_5 * V_49 = F_2 ( V_2 ) ;
#ifdef F_225
int V_330 ;
T_1 V_367 , V_368 ;
struct V_3 * V_4 = V_2 -> V_22 ;
struct V_369 V_324 = {
. V_288 = 0 ,
. V_287 = V_38
} ;
if ( V_4 && V_4 -> V_370 && V_4 -> V_370 -> V_371 ) {
V_330 = V_4 -> V_370 -> V_371 ( V_4 ) ;
if ( V_330 & V_372 ) {
V_324 . V_325 = V_373 ;
V_368 = F_226 ( V_4 , & V_324 ) ;
V_324 . V_287 = V_42 ;
V_367 = F_226 ( V_4 , & V_324 ) ;
} else {
V_324 . V_325 = V_326 ;
V_368 = F_227 ( V_4 , & V_324 ) ;
V_324 . V_287 = V_42 ;
V_367 = F_227 ( V_4 , & V_324 ) ;
}
V_365 = F_200 ( V_368 ) ? F_200 ( V_368 ) - 1 : 0 ;
V_363 = F_200 ( V_367 ) ? F_200 ( V_367 ) - 1 : V_365 ;
}
#endif
V_2 -> V_288 = V_365 ;
V_49 -> V_288 = V_363 ;
}
static int F_228 ( struct V_3 * V_4 , enum V_46 V_46 ,
enum V_374 V_375 )
{
int V_136 = 0 ;
struct V_47 * V_48 ;
struct V_5 * V_49 ;
struct V_1 * V_2 ;
struct V_89 * V_78 ;
F_48 ( & V_350 ) ;
F_32 () ;
if ( F_229 ( V_4 ) ) {
V_136 = - V_376 ;
goto V_354;
}
V_2 = F_13 ( V_4 , V_46 ) ;
if ( F_230 ( V_2 ) ) {
V_136 = F_231 ( V_2 ) ;
goto V_354;
}
V_49 = F_2 ( V_2 ) ;
V_48 = F_205 ( V_49 ) ;
V_78 = F_101 ( V_2 , & V_48 -> V_39 , 0 ) ;
if ( F_230 ( V_78 ) ) {
F_67 ( V_192 L_53 ,
V_4 -> V_151 ) ;
V_136 = - V_377 ;
F_33 () ;
F_31 ( V_2 ) ;
F_49 ( & V_350 ) ;
F_23 ( V_48 ) ;
goto V_54;
}
V_49 -> V_67 = V_78 ;
F_224 ( V_2 ) ;
V_78 -> V_378 = V_379 ;
F_232 ( V_78 ) ;
if ( V_375 == V_380 )
V_48 -> V_345 = V_347 ;
else
V_48 -> V_345 = V_346 ;
if ( V_375 == V_380 &&
! F_206 ( V_78 ) ) {
F_33 () ;
F_208 ( V_49 ) ;
F_49 ( & V_350 ) ;
return V_136 ;
}
V_354:
F_33 () ;
F_49 ( & V_350 ) ;
V_54:
return V_136 ;
}
static int F_233 ( struct V_3 * V_4 , enum V_46 V_46 )
{
return F_228 ( V_4 , V_46 , V_380 ) ;
}
static int F_234 ( struct V_3 * V_4 )
{
return F_228 ( V_4 , V_353 ,
V_381 ) ;
}
static int F_206 ( struct V_89 * V_78 )
{
struct V_3 * V_4 = F_62 ( V_78 ) ;
if ( F_235 ( V_4 ) )
return 0 ;
return - 1 ;
}
static void F_92 ( struct V_89 * V_78 )
{
struct V_226 * V_382 ;
unsigned int V_223 ;
F_236 (cpu) {
V_382 = & F_137 ( V_228 , V_223 ) ;
F_121 ( & V_382 -> V_233 ) ;
}
}
static int F_237 ( struct V_204 * V_205 )
{
struct V_89 * V_78 = F_109 ( V_205 ) ;
struct V_74 * V_75 = F_42 ( V_78 ) ;
struct V_1 * V_2 = V_75 -> V_90 ;
struct V_5 * V_49 = F_2 ( V_2 ) ;
struct V_47 * V_58 = F_205 ( V_49 ) ;
F_209 ( V_49 ) ;
F_91 ( V_49 -> V_67 ) ;
if ( V_58 -> V_345 != V_346 &&
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
static struct V_89 * F_229 ( const struct V_3 * V_4 )
{
struct V_5 * V_49 ;
struct V_1 * V_2 ;
V_2 = F_211 ( V_4 ) ;
V_49 = F_2 ( V_2 ) ;
return ( V_2 ) ? V_49 -> V_67 : NULL ;
}
static int F_106 ( const struct V_89 * V_78 )
{
struct V_1 * V_2 ;
struct V_74 * V_75 ;
V_2 = F_211 ( F_62 ( V_78 ) ) ;
if ( ! V_2 ) {
V_75 = F_42 ( V_78 ) ;
V_2 = V_75 -> V_90 ;
F_238 ( & V_2 -> V_342 , & V_383 ) ;
}
return 0 ;
}
static void F_111 ( const struct V_89 * V_78 )
{
struct V_1 * V_2 ;
struct V_74 * V_75 ;
V_75 = F_42 ( V_78 ) ;
V_2 = V_75 -> V_90 ;
F_203 ( & V_2 -> V_342 ) ;
return;
}
static int T_5 F_239 ( void )
{
struct V_226 * V_227 ;
unsigned int V_223 ;
int V_136 = 0 ;
V_343 = F_240 ( L_54 , 0 , 0 ) ;
if ( ! V_343 )
return - V_56 ;
V_136 = F_241 ( & V_384 ) ;
if ( V_136 ) {
F_67 ( V_192 L_55
L_56 ) ;
goto V_385;
}
F_48 ( & V_350 ) ;
F_236 (cpu) {
V_227 = F_117 ( & V_228 , V_223 ) ;
F_105 ( & V_227 -> V_233 , F_187 ) ;
F_53 ( & V_227 -> V_229 ) ;
}
F_191 () ;
V_136 = F_112 () ;
if ( V_136 )
goto V_386;
F_49 ( & V_350 ) ;
return 0 ;
V_386:
F_49 ( & V_350 ) ;
V_385:
F_242 ( V_343 ) ;
return V_136 ;
}
static void T_6 F_243 ( void )
{
struct V_1 * V_2 , * V_314 ;
struct V_5 * V_49 ;
struct V_74 * V_75 ;
unsigned int V_223 ;
F_48 ( & V_350 ) ;
F_194 () ;
F_32 () ;
F_219 (fcoe, tmp, &fcoe_hostlist, list) {
V_49 = F_2 ( V_2 ) ;
V_75 = F_42 ( V_49 -> V_67 ) ;
F_111 ( V_75 -> V_78 ) ;
F_204 ( V_343 , & V_75 -> V_213 ) ;
}
F_33 () ;
F_236 (cpu)
F_116 ( V_223 ) ;
F_49 ( & V_350 ) ;
F_242 ( V_343 ) ;
F_114 () ;
F_244 ( & V_384 ) ;
}
static void F_245 ( struct V_387 * V_388 , struct V_168 * V_169 , void * V_389 )
{
struct V_5 * V_6 = V_389 ;
struct V_390 * V_391 = F_246 ( V_388 ) ;
struct V_89 * V_78 = V_391 -> V_67 ;
T_1 * V_392 ;
if ( F_230 ( V_169 ) )
goto V_393;
V_392 = F_247 ( V_169 ) -> V_394 ;
if ( F_43 ( V_392 ) )
F_248 ( V_6 , V_78 , V_169 ) ;
if ( ! F_43 ( V_392 ) )
V_62 ( V_78 , V_392 ) ;
V_393:
F_249 ( V_388 , V_169 , V_78 ) ;
}
static void F_250 ( struct V_387 * V_388 , struct V_168 * V_169 , void * V_389 )
{
struct V_89 * V_78 = V_389 ;
static T_1 V_395 [ V_11 ] = { 0 } ;
if ( ! F_230 ( V_169 ) )
V_62 ( V_78 , V_395 ) ;
F_251 ( V_388 , V_169 , V_78 ) ;
}
static struct V_387 * F_252 ( struct V_89 * V_78 , T_2 V_396 ,
struct V_168 * V_169 , unsigned int V_397 ,
void (* F_253)( struct V_387 * ,
struct V_168 * ,
void * ) ,
void * V_389 , T_2 V_398 )
{
struct V_74 * V_75 = F_42 ( V_78 ) ;
struct V_1 * V_2 = V_75 -> V_90 ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_170 * V_171 = F_78 ( V_169 ) ;
switch ( V_397 ) {
case V_399 :
case V_400 :
if ( V_78 -> V_401 )
break;
return F_254 ( V_78 , V_396 , V_169 , V_397 , F_245 ,
V_6 , V_398 ) ;
case V_304 :
if ( F_135 ( V_171 -> V_253 ) != V_306 )
break;
return F_254 ( V_78 , V_396 , V_169 , V_397 , F_250 ,
V_78 , V_398 ) ;
}
return F_254 ( V_78 , V_396 , V_169 , V_397 , F_253 , V_389 , V_398 ) ;
}
static int F_255 ( struct V_206 * V_132 , bool V_402 )
{
struct V_204 * V_205 = F_108 ( V_132 ) ;
struct V_89 * V_203 = F_109 ( V_205 ) ;
struct V_74 * V_75 = F_42 ( V_203 ) ;
struct V_1 * V_2 = V_75 -> V_90 ;
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_89 * V_403 ;
int V_136 ;
char V_404 [ 32 ] ;
V_136 = F_256 ( V_132 ) ;
if ( V_136 ) {
F_257 ( V_132 -> V_217 , V_404 , sizeof( V_404 ) ) ;
F_67 ( V_192 L_57
L_58 ,
V_404 ) ;
return V_136 ;
}
F_48 ( & V_350 ) ;
F_32 () ;
V_403 = F_101 ( V_2 , & V_132 -> V_39 , 1 ) ;
F_33 () ;
F_49 ( & V_350 ) ;
if ( F_230 ( V_403 ) ) {
F_67 ( V_192 L_59 ,
V_4 -> V_151 ) ;
return - V_377 ;
}
if ( V_402 ) {
F_258 ( V_132 , V_405 ) ;
} else {
V_403 -> V_378 = V_379 ;
F_232 ( V_403 ) ;
F_259 ( V_403 ) ;
}
return 0 ;
}
static int F_260 ( struct V_206 * V_132 )
{
struct V_204 * V_205 = F_108 ( V_132 ) ;
struct V_89 * V_203 = F_109 ( V_205 ) ;
struct V_89 * V_403 = V_132 -> V_406 ;
F_48 ( & V_203 -> V_111 ) ;
F_203 ( & V_403 -> V_342 ) ;
F_49 ( & V_203 -> V_111 ) ;
F_48 ( & V_350 ) ;
F_87 ( V_403 ) ;
F_49 ( & V_350 ) ;
return 0 ;
}
static int F_261 ( struct V_206 * V_132 , bool V_407 )
{
struct V_89 * V_78 = V_132 -> V_406 ;
if ( V_407 ) {
F_258 ( V_132 , V_405 ) ;
F_88 ( V_78 ) ;
} else {
V_78 -> V_378 = V_379 ;
F_232 ( V_78 ) ;
F_259 ( V_78 ) ;
}
return 0 ;
}
static void F_262 ( struct V_206 * V_132 )
{
struct V_89 * V_78 = V_132 -> V_406 ;
struct V_168 * V_169 ;
T_9 V_243 ;
snprintf ( F_64 ( V_78 -> V_68 ) , V_148 ,
L_60 , V_149 , V_150 ,
F_62 ( V_78 ) -> V_151 , V_132 -> V_408 ) ;
if ( V_78 -> V_409 != V_410 )
return;
V_243 = F_263 ( F_64 ( V_78 -> V_68 ) , 255 ) ;
V_169 = F_264 ( V_78 ,
sizeof( struct V_411 ) +
sizeof( struct V_412 ) + V_243 ) ;
if ( ! V_169 )
return;
V_78 -> V_413 . V_414 ( V_78 , V_415 , V_169 , V_416 ,
NULL , NULL , 3 * V_78 -> V_98 ) ;
}
static void F_265 ( struct V_417 * V_418 )
{
struct V_47 * V_48 =
F_266 ( V_418 ) ;
struct V_5 * V_49 = F_18 ( V_48 ) ;
struct V_1 * V_2 = F_19 ( V_49 ) ;
V_418 -> V_419 = F_51 ( V_2 -> V_4 ) ;
}
static void F_267 ( struct V_89 * V_78 ,
T_2 V_420 , struct V_168 * V_169 )
{
struct V_74 * V_75 = F_42 ( V_78 ) ;
struct V_1 * V_2 = V_75 -> V_90 ;
struct V_5 * V_49 = F_2 ( V_2 ) ;
if ( V_169 && F_174 ( V_169 ) == V_399 )
F_248 ( V_49 , V_78 , V_169 ) ;
}
