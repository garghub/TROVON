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
return 0 ;
}
static struct V_1 * F_13 ( struct V_3 * V_4 ,
enum V_43 V_44 )
{
struct V_45 * V_46 ;
struct V_5 * V_47 ;
struct V_1 * V_2 ;
int V_48 ;
int V_49 ;
if ( ! F_14 ( V_50 ) ) {
F_3 ( V_4 ,
L_4 ) ;
V_2 = F_15 ( - V_51 ) ;
goto V_52;
}
V_48 = sizeof( struct V_5 ) + sizeof( struct V_1 ) ;
V_46 = F_16 ( & V_4 -> V_39 , & V_53 ,
V_48 ) ;
if ( ! V_46 ) {
F_17 ( L_5 ) ;
V_2 = F_15 ( - V_54 ) ;
goto V_55;
}
V_47 = F_18 ( V_46 ) ;
V_47 -> V_56 = V_46 ;
V_2 = F_19 ( V_47 ) ;
F_20 ( V_4 ) ;
F_21 ( V_47 , V_44 ) ;
V_47 -> V_57 = V_58 ;
V_47 -> V_59 = V_60 ;
V_47 -> V_61 = V_62 ;
V_49 = F_1 ( V_2 , V_4 ) ;
if ( V_49 ) {
F_22 ( V_47 ) ;
F_23 ( V_46 ) ;
F_24 ( V_4 ) ;
V_2 = F_15 ( V_49 ) ;
goto V_55;
}
goto V_52;
V_55:
F_25 ( V_50 ) ;
V_52:
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
if ( V_13 -> V_63 ) {
if ( V_13 -> V_63 ( V_4 ) )
F_3 ( V_4 , L_6
L_2 ) ;
}
V_2 -> V_64 = 1 ;
}
static void F_31 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
F_32 () ;
if ( ! V_2 -> V_64 )
F_26 ( V_2 ) ;
F_33 () ;
F_22 ( V_6 ) ;
F_34 ( V_6 -> V_65 -> V_66 ) ;
F_24 ( V_4 ) ;
F_25 ( V_50 ) ;
}
static int V_41 ( struct V_67 * V_68 , struct V_3 * V_4 ,
struct V_69 * V_70 ,
struct V_3 * V_71 )
{
struct V_1 * V_2 ;
struct V_5 * V_47 ;
V_2 = F_35 ( V_70 , struct V_1 , V_40 ) ;
V_47 = F_2 ( V_2 ) ;
F_36 ( V_47 , V_68 ) ;
return 0 ;
}
static void F_37 ( struct V_72 * V_73 , struct V_67 * V_68 )
{
if ( V_73 -> V_74 . V_75 )
F_38 ( V_73 -> V_76 , V_68 ) ;
else if ( F_39 ( V_68 ) )
F_38 ( V_73 -> V_76 , V_68 ) ;
}
static void V_58 ( struct V_5 * V_6 , struct V_67 * V_68 )
{
V_68 -> V_39 = F_40 ( V_6 ) -> V_4 ;
F_37 ( F_41 ( V_6 -> V_65 ) , V_68 ) ;
}
static void V_60 ( struct V_77 * V_76 , T_1 * V_24 )
{
struct V_72 * V_73 = F_41 ( V_76 ) ;
struct V_1 * V_2 = V_73 -> V_78 ;
if ( ! F_42 ( V_73 -> V_79 ) )
F_29 ( V_2 -> V_4 , V_73 -> V_79 ) ;
if ( ! F_42 ( V_24 ) )
F_9 ( V_2 -> V_4 , V_24 ) ;
memcpy ( V_73 -> V_79 , V_24 , V_11 ) ;
}
static T_1 * V_62 ( struct V_77 * V_76 )
{
struct V_72 * V_73 = F_41 ( V_76 ) ;
return V_73 -> V_79 ;
}
static int F_43 ( struct V_77 * V_76 )
{
V_76 -> V_80 = 0 ;
V_76 -> V_81 = 0 ;
V_76 -> V_82 = 3 ;
V_76 -> V_83 = 3 ;
V_76 -> V_84 = 2 * 1000 ;
V_76 -> V_85 = 2 * 2 * 1000 ;
V_76 -> V_86 = ( V_87 | V_88 |
V_89 | V_90 ) ;
V_76 -> V_91 = 1 ;
F_44 ( V_76 ) ;
F_45 ( V_76 ) ;
V_76 -> V_92 = 0 ;
V_76 -> V_93 = 0 ;
V_76 -> V_94 = 0 ;
V_76 -> V_95 = 0 ;
V_76 -> V_96 = 0 ;
return 0 ;
}
static void F_46 ( struct V_77 * V_76 ,
struct V_3 * V_4 )
{
F_47 ( & V_76 -> V_97 ) ;
if ( V_4 -> V_98 & V_99 )
V_76 -> V_100 = 1 ;
else
V_76 -> V_100 = 0 ;
if ( V_4 -> V_98 & V_101 ) {
V_76 -> V_92 = 1 ;
F_3 ( V_4 , L_7 ) ;
} else {
V_76 -> V_92 = 0 ;
}
if ( V_4 -> V_98 & V_102 ) {
V_76 -> V_93 = 1 ;
V_76 -> V_96 = V_4 -> V_103 ;
F_3 ( V_4 , L_8 ,
V_76 -> V_96 ) ;
} else {
V_76 -> V_93 = 0 ;
V_76 -> V_96 = 0 ;
}
if ( V_4 -> V_104 ) {
V_76 -> V_94 = 1 ;
V_76 -> V_95 = V_4 -> V_104 ;
F_3 ( V_4 , L_9 ,
V_76 -> V_95 ) ;
} else {
V_76 -> V_94 = 0 ;
V_76 -> V_95 = 0 ;
}
F_48 ( & V_76 -> V_97 ) ;
}
static int F_49 ( struct V_77 * V_76 , struct V_3 * V_4 )
{
T_2 V_105 ;
T_3 V_106 , V_107 ;
struct V_1 * V_2 ;
struct V_5 * V_47 ;
struct V_72 * V_73 ;
V_73 = F_41 ( V_76 ) ;
V_2 = V_73 -> V_78 ;
V_47 = F_2 ( V_2 ) ;
V_105 = V_4 -> V_108 ;
if ( V_4 -> V_98 & V_109 ) {
V_105 = V_110 ;
F_3 ( V_4 , L_10 , V_105 ) ;
}
V_105 -= ( sizeof( struct V_111 ) + sizeof( struct V_112 ) ) ;
if ( F_50 ( V_76 , V_105 ) )
return - V_113 ;
F_46 ( V_76 , V_4 ) ;
F_51 ( & V_73 -> V_74 ) ;
V_73 -> V_114 = 0 ;
F_52 ( & V_73 -> V_115 , V_116 , ( unsigned long ) V_76 ) ;
F_53 ( V_76 ) ;
if ( ! V_76 -> V_117 ) {
if ( F_54 ( V_4 , & V_106 , V_118 ) )
V_106 = F_55 ( V_47 -> V_25 , 1 , 0 ) ;
F_56 ( V_76 , V_106 ) ;
if ( F_54 ( V_4 , & V_107 , V_119 ) )
V_107 = F_55 ( V_47 -> V_25 ,
2 , 0 ) ;
F_57 ( V_76 , V_107 ) ;
}
return 0 ;
}
static int F_58 ( struct V_77 * V_76 , struct V_120 * V_39 )
{
int V_121 = 0 ;
V_76 -> V_66 -> V_122 = V_123 ;
V_76 -> V_66 -> V_124 = V_125 ;
V_76 -> V_66 -> V_126 = 0 ;
V_76 -> V_66 -> V_127 = V_128 ;
if ( V_76 -> V_117 )
V_76 -> V_66 -> V_129 = V_130 ;
else
V_76 -> V_66 -> V_129 = V_131 ;
V_121 = F_59 ( V_76 -> V_66 , V_39 ) ;
if ( V_121 ) {
F_3 ( F_60 ( V_76 ) , L_11
L_12 ) ;
return V_121 ;
}
if ( ! V_76 -> V_117 )
F_61 ( V_76 -> V_66 ) = V_132 ;
snprintf ( F_62 ( V_76 -> V_66 ) , V_133 ,
L_13 , V_134 , V_135 ,
F_60 ( V_76 ) -> V_136 ) ;
return 0 ;
}
static void F_63 ( struct V_77 * V_76 , struct V_3 * V_4 )
{
struct V_1 * V_2 ;
struct V_72 * V_73 ;
struct V_3 * V_22 ;
int V_121 ;
V_73 = F_41 ( V_76 ) ;
V_2 = V_73 -> V_78 ;
V_22 = V_2 -> V_22 ;
if ( ! V_22 )
return;
if ( V_76 -> V_117 )
return;
if ( V_22 -> V_14 -> V_137 ) {
struct V_138 * V_139 ;
V_139 = F_64 ( sizeof( * V_139 ) , V_140 ) ;
if ( ! V_139 )
return;
V_121 = V_22 -> V_14 -> V_137 ( V_22 ,
V_139 ) ;
if ( V_121 ) {
F_65 ( V_141 L_14
L_15 ) ;
return;
}
snprintf ( F_66 ( V_76 -> V_66 ) ,
V_142 ,
L_16 ,
V_139 -> V_143 ) ;
snprintf ( F_67 ( V_76 -> V_66 ) ,
V_142 ,
L_16 ,
V_139 -> V_144 ) ;
snprintf ( F_68 ( V_76 -> V_66 ) ,
V_133 ,
L_16 ,
V_139 -> V_145 ) ;
snprintf ( F_69 ( V_76 -> V_66 ) ,
V_133 ,
L_16 ,
V_139 -> V_146 ) ;
snprintf ( F_70 ( V_76 -> V_66 ) ,
V_147 ,
L_16 ,
V_139 -> V_148 ) ;
snprintf ( F_71 ( V_76 -> V_66 ) ,
V_147 ,
L_16 ,
V_139 -> V_149 ) ;
snprintf ( F_72 ( V_76 -> V_66 ) ,
V_147 ,
L_16 ,
V_139 -> V_150 ) ;
snprintf ( F_73 ( V_76 -> V_66 ) ,
V_147 ,
L_16 ,
V_139 -> V_151 ) ;
V_76 -> V_152 = 1 ;
F_74 ( V_139 ) ;
} else {
V_76 -> V_152 = 0 ;
F_65 ( V_141 L_17 ) ;
}
}
static bool F_75 ( struct V_153 * V_154 )
{
struct V_155 * V_156 = F_76 ( V_154 ) ;
struct V_157 * V_158 ;
if ( F_77 ( F_78 ( V_154 ) ) &&
( F_78 ( V_154 ) -> V_159 > V_160 ) )
return true ;
else if ( ( F_78 ( V_154 ) == NULL ) &&
( V_156 -> V_161 == V_162 ) &&
( F_79 ( V_156 -> V_163 ) == V_164 ) ) {
V_158 = F_80 ( V_154 , sizeof( * V_158 ) ) ;
if ( ( V_158 -> V_165 & V_166 ) &&
( F_81 ( V_158 -> V_167 ) > V_160 ) )
return true ;
}
return false ;
}
static inline int F_82 ( struct V_77 * V_76 )
{
struct V_72 * V_73 = F_41 ( V_76 ) ;
struct V_1 * V_2 = V_73 -> V_78 ;
struct V_1 * V_168 = NULL ;
struct V_3 * V_169 , * V_170 ;
T_4 V_171 = V_172 ;
T_4 V_173 = V_174 ;
if ( ! V_76 -> V_94 || ! V_76 -> V_95 ||
( V_76 -> V_95 >= V_173 ) ) {
V_76 -> V_95 = 0 ;
goto V_175;
}
if ( V_2 -> V_4 -> V_16 & V_21 )
V_170 = F_4 ( V_2 -> V_4 ) ;
else
V_170 = V_2 -> V_4 ;
F_83 (oldfcoe, &fcoe_hostlist, list) {
if ( V_168 -> V_4 -> V_16 & V_21 )
V_169 = F_4 ( V_168 -> V_4 ) ;
else
V_169 = V_168 -> V_4 ;
if ( V_170 == V_169 ) {
V_2 -> V_176 = V_168 -> V_176 ;
break;
}
}
if ( V_2 -> V_176 ) {
if ( ! F_84 ( V_76 , V_2 -> V_176 , F_75 ) ) {
F_65 ( V_177 L_18
L_19 ,
V_2 -> V_176 , V_2 -> V_4 -> V_136 ) ;
return - V_54 ;
}
} else {
V_2 -> V_176 = F_85 ( V_76 , V_178 ,
V_172 , V_76 -> V_95 ,
F_75 ) ;
if ( ! V_2 -> V_176 ) {
F_65 ( V_177 L_20
L_21 ,
V_2 -> V_4 -> V_136 ) ;
return - V_54 ;
}
}
V_171 += V_76 -> V_95 + 1 ;
V_175:
if ( ! F_85 ( V_76 , V_178 , V_171 , V_173 , NULL ) ) {
F_65 ( V_177 L_22
L_23 , V_2 -> V_4 -> V_136 ) ;
return - V_54 ;
}
return 0 ;
}
static void F_86 ( struct V_77 * V_76 )
{
struct V_72 * V_73 = F_41 ( V_76 ) ;
struct V_1 * V_2 = V_73 -> V_78 ;
struct V_3 * V_4 = V_2 -> V_4 ;
F_3 ( V_4 , L_24 ) ;
F_87 ( V_76 ) ;
F_88 ( V_76 ) ;
F_89 ( & V_73 -> V_115 ) ;
F_90 ( V_76 ) ;
F_32 () ;
if ( ! F_42 ( V_73 -> V_79 ) )
F_29 ( V_4 , V_73 -> V_79 ) ;
if ( V_76 -> V_117 )
F_28 () ;
else
F_26 ( V_2 ) ;
F_33 () ;
F_91 ( V_76 ) ;
F_92 ( V_76 -> V_66 ) ;
F_93 ( V_76 -> V_66 ) ;
F_94 ( V_76 ) ;
F_95 ( V_76 ) ;
F_96 ( V_76 ) ;
if ( V_76 -> V_117 )
F_34 ( V_76 -> V_66 ) ;
}
static int F_97 ( struct V_77 * V_76 , T_4 V_179 ,
struct V_180 * V_181 , unsigned int V_182 )
{
struct V_3 * V_4 = F_60 ( V_76 ) ;
if ( V_4 -> V_14 -> V_183 )
return V_4 -> V_14 -> V_183 ( V_4 ,
V_179 , V_181 ,
V_182 ) ;
return 0 ;
}
static int F_98 ( struct V_77 * V_76 , T_4 V_179 ,
struct V_180 * V_181 , unsigned int V_182 )
{
struct V_3 * V_4 = F_60 ( V_76 ) ;
if ( V_4 -> V_14 -> V_184 )
return V_4 -> V_14 -> V_184 ( V_4 , V_179 ,
V_181 , V_182 ) ;
return 0 ;
}
static int F_99 ( struct V_77 * V_76 , T_4 V_179 )
{
struct V_3 * V_4 = F_60 ( V_76 ) ;
if ( V_4 -> V_14 -> V_185 )
return V_4 -> V_14 -> V_185 ( V_4 , V_179 ) ;
return 0 ;
}
static struct V_77 * F_100 ( struct V_1 * V_2 ,
struct V_120 * V_186 , int V_187 )
{
struct V_5 * V_47 = F_2 ( V_2 ) ;
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_77 * V_76 , * V_188 ;
struct V_72 * V_73 ;
struct V_189 * V_190 ;
int V_121 ;
struct V_191 * V_117 = F_101 ( V_186 ) ;
F_3 ( V_4 , L_25 ) ;
if ( ! V_187 )
V_76 = F_102 ( & V_192 , sizeof( * V_73 ) ) ;
else
V_76 = F_103 ( V_117 , sizeof( * V_73 ) ) ;
if ( ! V_76 ) {
F_3 ( V_4 , L_26 ) ;
V_121 = - V_54 ;
goto V_52;
}
V_73 = F_41 ( V_76 ) ;
V_73 -> V_76 = V_76 ;
V_73 -> V_78 = V_2 ;
V_73 -> V_193 = F_60 ;
V_73 -> V_194 = V_195 ;
V_73 -> V_196 = V_197 ;
F_104 ( & V_73 -> V_198 , V_199 ) ;
F_105 ( V_76 ) ;
V_121 = F_43 ( V_76 ) ;
if ( V_121 ) {
F_3 ( V_4 , L_27
L_28 ) ;
goto V_200;
}
if ( V_187 ) {
F_3 ( V_4 , L_29
L_30 ,
V_117 -> V_201 , V_117 -> V_202 ) ;
F_56 ( V_76 , V_117 -> V_201 ) ;
F_57 ( V_76 , V_117 -> V_202 ) ;
}
V_121 = F_49 ( V_76 , V_4 ) ;
if ( V_121 ) {
F_3 ( V_4 , L_31
L_28 ) ;
goto V_203;
}
V_121 = F_58 ( V_76 , V_186 ) ;
if ( V_121 ) {
F_3 ( V_4 , L_32
L_28 ) ;
goto V_203;
}
V_121 = F_106 ( V_76 , V_47 , & V_204 , 1 ) ;
if ( V_121 ) {
F_3 ( V_4 , L_33
L_28 ) ;
goto V_203;
}
F_63 ( V_76 , V_4 ) ;
if ( ! V_187 )
V_121 = F_82 ( V_76 ) ;
else {
V_190 = F_107 ( V_117 ) ;
V_188 = F_108 ( V_190 ) ;
V_121 = F_109 ( V_188 , V_76 ) ;
}
if ( V_121 ) {
F_3 ( V_4 , L_34 ) ;
goto V_203;
}
return V_76 ;
V_203:
F_95 ( V_76 ) ;
V_200:
F_110 ( V_76 ) ;
F_34 ( V_76 -> V_66 ) ;
V_52:
return F_15 ( V_121 ) ;
}
static int T_5 F_111 ( void )
{
V_131 =
F_112 ( & V_205 ) ;
V_130 =
F_112 ( & V_206 ) ;
if ( ! V_131 ) {
F_65 ( V_177 L_35 ) ;
return - V_207 ;
}
return 0 ;
}
static int T_6 F_113 ( void )
{
F_114 ( V_131 ) ;
F_114 ( V_130 ) ;
V_131 = NULL ;
V_130 = NULL ;
return 0 ;
}
static void F_115 ( unsigned int V_208 )
{
struct V_209 * V_210 ;
struct V_211 * V_212 ;
V_210 = & F_116 ( V_213 , V_208 ) ;
V_212 = F_117 ( V_214 ,
( void * ) V_210 , F_118 ( V_208 ) ,
L_36 , V_208 ) ;
if ( F_119 ( ! F_120 ( V_212 ) ) ) {
F_121 ( V_212 , V_208 ) ;
F_122 ( V_212 ) ;
F_123 ( & V_210 -> V_215 . V_216 ) ;
V_210 -> V_212 = V_212 ;
F_124 ( & V_210 -> V_215 . V_216 ) ;
}
}
static void F_125 ( unsigned int V_208 )
{
struct V_209 * V_210 ;
struct V_211 * V_212 ;
struct V_217 * V_218 ;
struct V_67 * V_68 ;
#ifdef F_126
struct V_209 * V_219 ;
unsigned V_220 = F_127 () ;
#endif
F_17 ( L_37 , V_208 ) ;
V_210 = & F_116 ( V_213 , V_208 ) ;
F_123 ( & V_210 -> V_215 . V_216 ) ;
V_212 = V_210 -> V_212 ;
V_210 -> V_212 = NULL ;
V_218 = V_210 -> V_221 ;
V_210 -> V_221 = NULL ;
V_210 -> V_222 = 0 ;
F_124 ( & V_210 -> V_215 . V_216 ) ;
#ifdef F_126
if ( V_208 != V_220 ) {
V_219 = & F_116 ( V_213 , V_220 ) ;
F_123 ( & V_219 -> V_215 . V_216 ) ;
if ( V_219 -> V_212 ) {
F_17 ( L_38 ,
V_208 , V_220 ) ;
while ( ( V_68 = F_128 ( & V_210 -> V_215 ) ) != NULL )
F_129 ( & V_219 -> V_215 , V_68 ) ;
F_124 ( & V_219 -> V_215 . V_216 ) ;
} else {
while ( ( V_68 = F_128 ( & V_210 -> V_215 ) ) != NULL )
F_130 ( V_68 ) ;
F_124 ( & V_219 -> V_215 . V_216 ) ;
}
} else {
F_123 ( & V_210 -> V_215 . V_216 ) ;
while ( ( V_68 = F_128 ( & V_210 -> V_215 ) ) != NULL )
F_130 ( V_68 ) ;
F_124 ( & V_210 -> V_215 . V_216 ) ;
}
F_131 () ;
#else
F_123 ( & V_210 -> V_215 . V_216 ) ;
while ( ( V_68 = F_128 ( & V_210 -> V_215 ) ) != NULL )
F_130 ( V_68 ) ;
F_124 ( & V_210 -> V_215 . V_216 ) ;
#endif
if ( V_212 )
F_132 ( V_212 ) ;
if ( V_218 )
F_133 ( V_218 ) ;
}
static int F_134 ( struct V_223 * V_224 ,
unsigned long V_225 , void * V_226 )
{
unsigned V_208 = ( unsigned long ) V_226 ;
switch ( V_225 ) {
case V_227 :
case V_228 :
F_17 ( L_39 , V_208 ) ;
F_115 ( V_208 ) ;
break;
case V_229 :
case V_230 :
F_17 ( L_40 , V_208 ) ;
F_125 ( V_208 ) ;
break;
default:
break;
}
return V_231 ;
}
static inline unsigned int F_135 ( void )
{
static unsigned int V_232 ;
V_232 = F_136 ( V_232 , V_233 ) ;
if ( V_232 >= V_234 )
V_232 = F_137 ( V_233 ) ;
return V_232 ;
}
static int V_37 ( struct V_67 * V_68 , struct V_3 * V_4 ,
struct V_69 * V_70 , struct V_3 * V_235 )
{
struct V_77 * V_76 ;
struct V_236 * V_237 ;
struct V_5 * V_47 ;
struct V_1 * V_2 ;
struct V_155 * V_156 ;
struct V_209 * V_238 ;
struct V_239 * V_240 ;
unsigned int V_208 ;
V_2 = F_35 ( V_70 , struct V_1 , V_35 ) ;
V_47 = F_2 ( V_2 ) ;
V_76 = V_47 -> V_65 ;
if ( F_138 ( ! V_76 ) ) {
F_3 ( V_4 , L_41 ) ;
goto V_241;
}
if ( ! V_76 -> V_80 )
goto V_241;
F_3 ( V_4 ,
L_42 ,
V_68 -> V_242 , V_68 -> V_159 , V_68 -> V_243 , V_68 -> V_244 ,
F_139 ( V_68 ) , F_140 ( V_68 ) ,
V_68 -> V_245 , V_68 -> V_39 ? V_68 -> V_39 -> V_136 : L_43 ) ;
V_68 = F_141 ( V_68 , V_246 ) ;
if ( V_68 == NULL )
return V_247 ;
V_240 = F_142 ( V_68 ) ;
if ( F_143 ( V_47 ) &&
! F_144 ( V_240 -> V_248 , V_47 -> V_249 ) ) {
F_3 ( V_4 , L_44 ,
V_240 -> V_248 ) ;
goto V_49;
}
if ( F_138 ( ( V_68 -> V_242 < V_250 ) ||
! F_145 ( V_68 , V_251 ) ) )
goto V_49;
F_146 ( V_68 , sizeof( struct V_111 ) ) ;
V_156 = (struct V_155 * ) F_147 ( V_68 ) ;
if ( F_148 ( & V_240 -> V_252 [ 3 ] ) != F_148 ( V_156 -> V_253 ) ) {
F_3 ( V_4 , L_45 ,
V_240 -> V_252 ) ;
goto V_49;
}
V_237 = F_149 ( V_68 ) ;
V_237 -> V_254 = V_76 ;
if ( F_148 ( V_156 -> V_255 ) & V_256 )
V_208 = F_79 ( V_156 -> V_257 ) & V_258 ;
else {
if ( F_79 ( V_156 -> V_163 ) == V_164 )
V_208 = F_135 () ;
else
V_208 = F_79 ( V_156 -> V_163 ) & V_258 ;
}
if ( V_208 >= V_234 )
goto V_49;
V_238 = & F_116 ( V_213 , V_208 ) ;
F_150 ( & V_238 -> V_215 . V_216 ) ;
if ( F_138 ( ! V_238 -> V_212 ) ) {
F_3 ( V_4 , L_46
L_47
L_48 ) ;
F_151 ( & V_238 -> V_215 . V_216 ) ;
V_208 = F_137 ( V_233 ) ;
V_238 = & F_116 ( V_213 , V_208 ) ;
F_150 ( & V_238 -> V_215 . V_216 ) ;
if ( ! V_238 -> V_212 ) {
F_151 ( & V_238 -> V_215 . V_216 ) ;
goto V_49;
}
}
F_129 ( & V_238 -> V_215 , V_68 ) ;
if ( V_238 -> V_212 -> V_259 == V_260 )
F_122 ( V_238 -> V_212 ) ;
F_151 ( & V_238 -> V_215 . V_216 ) ;
return V_261 ;
V_49:
F_152 ( V_76 -> V_262 , F_127 () ) -> V_263 ++ ;
F_131 () ;
V_241:
F_130 ( V_68 ) ;
return V_247 ;
}
static int F_153 ( struct V_67 * V_68 , int V_264 )
{
struct V_209 * V_238 ;
int V_121 ;
V_238 = & F_154 ( V_213 ) ;
V_121 = F_155 ( V_68 , V_264 , V_238 ) ;
F_156 ( V_213 ) ;
return V_121 ;
}
static int F_157 ( struct V_77 * V_76 , struct V_153 * V_154 )
{
int V_265 ;
T_2 V_266 ;
struct V_239 * V_240 ;
struct V_112 * V_267 ;
struct V_67 * V_68 ;
struct V_268 * V_262 ;
struct V_155 * V_156 ;
unsigned int V_269 ;
unsigned int V_264 ;
unsigned int V_270 ;
struct V_72 * V_73 = F_41 ( V_76 ) ;
struct V_1 * V_2 = V_73 -> V_78 ;
struct V_5 * V_47 = F_2 ( V_2 ) ;
T_1 V_271 , V_272 ;
struct V_111 * V_273 ;
F_158 ( ( F_159 ( V_154 ) % sizeof( T_2 ) ) != 0 ) ;
V_156 = F_76 ( V_154 ) ;
V_68 = F_160 ( V_154 ) ;
V_265 = V_68 -> V_242 / V_274 ;
if ( ! V_76 -> V_80 ) {
F_130 ( V_68 ) ;
return 0 ;
}
if ( F_138 ( V_156 -> V_275 == V_276 ) &&
F_161 ( V_47 , V_76 , V_68 ) )
return 0 ;
V_271 = F_162 ( V_154 ) ;
V_272 = F_163 ( V_154 ) ;
V_270 = sizeof( struct V_239 ) ;
V_269 = sizeof( struct V_111 ) ;
V_264 = sizeof( struct V_112 ) ;
V_265 = ( V_68 -> V_242 - V_264 + sizeof( V_266 ) ) / V_274 ;
if ( F_119 ( V_76 -> V_92 ) ) {
V_68 -> V_277 = V_278 ;
V_68 -> V_279 = F_164 ( V_68 ) ;
V_68 -> V_280 = V_68 -> V_242 ;
V_266 = 0 ;
} else {
V_68 -> V_277 = V_281 ;
V_266 = F_165 ( V_154 ) ;
}
if ( F_166 ( V_68 ) ) {
T_7 * V_282 ;
if ( F_153 ( V_68 , V_264 ) ) {
F_130 ( V_68 ) ;
return - V_54 ;
}
V_282 = & F_167 ( V_68 ) -> V_283 [ F_167 ( V_68 ) -> V_284 - 1 ] ;
V_267 = F_168 ( F_169 ( V_282 ) )
+ V_282 -> V_285 ;
} else {
V_267 = (struct V_112 * ) F_170 ( V_68 , V_264 ) ;
}
memset ( V_267 , 0 , sizeof( * V_267 ) ) ;
V_267 -> V_286 = V_272 ;
V_267 -> V_287 = F_171 ( ~ V_266 ) ;
if ( F_166 ( V_68 ) ) {
F_172 ( V_267 ) ;
V_267 = NULL ;
}
F_173 ( V_68 , V_270 + V_269 ) ;
F_174 ( V_68 ) ;
F_175 ( V_68 ) ;
V_68 -> V_288 = V_270 ;
V_68 -> V_289 = F_11 ( V_38 ) ;
V_68 -> V_290 = V_2 -> V_290 ;
if ( V_2 -> V_4 -> V_16 & V_21 &&
V_2 -> V_22 -> V_98 & V_291 ) {
V_68 -> V_39 = V_2 -> V_22 ;
F_176 ( V_68 , F_11 ( V_292 ) ,
F_177 ( V_2 -> V_4 ) ) ;
} else
V_68 -> V_39 = V_2 -> V_4 ;
V_240 = F_142 ( V_68 ) ;
V_240 -> V_293 = F_11 ( V_38 ) ;
memcpy ( V_240 -> V_252 , V_47 -> V_249 , V_11 ) ;
if ( V_47 -> V_294 )
memcpy ( V_240 -> V_252 + 3 , V_156 -> V_253 , 3 ) ;
if ( F_138 ( V_47 -> V_295 != V_164 ) )
memcpy ( V_240 -> V_248 , V_47 -> V_25 , V_11 ) ;
else
memcpy ( V_240 -> V_248 , V_73 -> V_79 , V_11 ) ;
V_273 = (struct V_111 * ) ( V_240 + 1 ) ;
memset ( V_273 , 0 , sizeof( * V_273 ) ) ;
if ( V_296 )
F_178 ( V_273 , V_296 ) ;
V_273 -> V_297 = V_271 ;
if ( V_76 -> V_93 && F_179 ( V_154 ) ) {
F_167 ( V_68 ) -> V_298 = V_299 ;
F_167 ( V_68 ) -> V_300 = F_179 ( V_154 ) ;
} else {
F_167 ( V_68 ) -> V_298 = 0 ;
F_167 ( V_68 ) -> V_300 = 0 ;
}
V_262 = F_152 ( V_76 -> V_262 , F_127 () ) ;
V_262 -> V_301 ++ ;
V_262 -> V_302 += V_265 ;
F_131 () ;
V_254 ( V_154 ) = V_76 ;
F_37 ( V_73 , V_68 ) ;
return 0 ;
}
static void F_180 ( struct V_67 * V_68 )
{
F_181 ( & V_303 ) ;
}
static inline int F_182 ( struct V_77 * V_76 ,
struct V_153 * V_154 )
{
struct V_5 * V_47 ;
struct V_1 * V_2 ;
struct V_155 * V_156 ;
struct V_67 * V_68 = (struct V_67 * ) V_154 ;
struct V_268 * V_262 ;
if ( V_76 -> V_92 && V_68 -> V_277 == V_278 )
F_183 ( V_154 ) &= ~ V_304 ;
else
F_183 ( V_154 ) |= V_304 ;
V_156 = (struct V_155 * ) F_147 ( V_68 ) ;
V_156 = F_76 ( V_154 ) ;
if ( V_156 -> V_161 == V_305 && V_156 -> V_275 == V_306 )
return 0 ;
V_2 = ( (struct V_72 * ) F_41 ( V_76 ) ) -> V_78 ;
V_47 = F_2 ( V_2 ) ;
if ( F_143 ( V_47 ) && F_184 ( V_154 ) == V_307 &&
F_148 ( V_156 -> V_308 ) == V_309 ) {
F_17 ( L_49 ) ;
return - V_113 ;
}
if ( ! ( F_183 ( V_154 ) & V_304 ) ||
F_185 ( F_186 ( V_154 ) ) == ~ F_187 ( ~ 0 , V_68 -> V_244 , V_68 -> V_242 ) ) {
F_183 ( V_154 ) &= ~ V_304 ;
return 0 ;
}
V_262 = F_152 ( V_76 -> V_262 , F_127 () ) ;
V_262 -> V_310 ++ ;
if ( V_262 -> V_310 < 5 )
F_65 ( V_311 L_50 ) ;
F_131 () ;
return - V_113 ;
}
static void F_188 ( struct V_67 * V_68 )
{
T_2 F_159 ;
struct V_77 * V_76 ;
struct V_236 * V_237 ;
struct V_268 * V_262 ;
struct V_112 V_218 ;
struct V_153 * V_154 ;
struct V_72 * V_73 ;
struct V_111 * V_273 ;
V_237 = F_149 ( V_68 ) ;
V_76 = V_237 -> V_254 ;
if ( F_138 ( ! V_76 ) ) {
if ( V_68 -> V_312 != F_180 )
F_3 ( V_68 -> V_39 , L_51 ) ;
F_130 ( V_68 ) ;
return;
}
F_3 ( V_68 -> V_39 ,
L_42 ,
V_68 -> V_242 , V_68 -> V_159 ,
V_68 -> V_243 , V_68 -> V_244 , F_139 ( V_68 ) ,
F_140 ( V_68 ) , V_68 -> V_245 ,
V_68 -> V_39 ? V_68 -> V_39 -> V_136 : L_43 ) ;
V_73 = F_41 ( V_76 ) ;
F_189 ( V_68 ) ;
V_273 = (struct V_111 * ) F_190 ( V_68 ) ;
V_262 = F_152 ( V_76 -> V_262 , F_127 () ) ;
if ( F_138 ( F_191 ( V_273 ) != V_296 ) ) {
if ( V_262 -> V_263 < 5 )
F_65 ( V_311 L_52
L_53
L_54
L_55
L_56 , F_191 ( V_273 ) ,
V_296 ) ;
goto V_313;
}
F_192 ( V_68 , sizeof( struct V_111 ) ) ;
F_159 = V_68 -> V_242 - sizeof( struct V_112 ) ;
V_262 -> V_314 ++ ;
V_262 -> V_315 += F_159 / V_274 ;
V_154 = (struct V_153 * ) V_68 ;
F_193 ( V_154 ) ;
V_254 ( V_154 ) = V_76 ;
F_162 ( V_154 ) = V_273 -> V_297 ;
if ( F_194 ( V_68 , F_159 , & V_218 , sizeof( V_218 ) ) )
goto V_313;
F_163 ( V_154 ) = V_218 . V_286 ;
F_186 ( V_154 ) = V_218 . V_287 ;
if ( F_195 ( V_68 , F_159 ) )
goto V_313;
if ( ! F_182 ( V_76 , V_154 ) ) {
F_131 () ;
F_196 ( V_76 , V_154 ) ;
return;
}
V_313:
V_262 -> V_263 ++ ;
F_131 () ;
F_130 ( V_68 ) ;
}
static int V_214 ( void * V_316 )
{
struct V_209 * V_210 = V_316 ;
struct V_67 * V_68 ;
struct V_317 V_318 ;
F_51 ( & V_318 ) ;
F_197 ( V_319 , V_320 ) ;
V_321:
while ( ! F_198 () ) {
F_123 ( & V_210 -> V_215 . V_216 ) ;
F_199 ( & V_210 -> V_215 , & V_318 ) ;
if ( ! F_200 ( & V_318 ) ) {
F_201 ( V_260 ) ;
F_124 ( & V_210 -> V_215 . V_216 ) ;
F_202 () ;
goto V_321;
}
F_124 ( & V_210 -> V_215 . V_216 ) ;
while ( ( V_68 = F_128 ( & V_318 ) ) != NULL )
F_188 ( V_68 ) ;
}
return 0 ;
}
static void F_203 ( void )
{
F_204 ( & V_322 ) ;
F_205 ( & V_323 ) ;
}
static void F_206 ( void )
{
F_207 ( & V_322 ) ;
F_208 ( & V_323 ) ;
}
static struct V_1 *
F_209 ( struct V_3 * V_4 )
{
struct V_1 * V_2 ;
struct V_3 * V_9 ;
F_83 (fcoe, &fcoe_hostlist, list) {
if ( V_2 -> V_4 -> V_16 & V_21 )
V_9 = F_4 ( V_2 -> V_4 ) ;
else
V_9 = V_2 -> V_4 ;
if ( V_4 == V_9 )
return V_2 ;
}
return NULL ;
}
static int F_210 ( struct V_223 * V_324 ,
T_8 V_325 , void * V_326 )
{
struct V_327 * V_328 = V_326 ;
struct V_5 * V_47 ;
struct V_1 * V_2 ;
struct V_3 * V_4 ;
int V_329 ;
if ( V_328 -> V_330 . V_331 != V_332 )
return V_231 ;
V_4 = F_211 ( & V_333 , V_328 -> V_334 ) ;
if ( ! V_4 )
return V_231 ;
V_2 = F_209 ( V_4 ) ;
F_24 ( V_4 ) ;
if ( ! V_2 )
return V_231 ;
V_47 = F_2 ( V_2 ) ;
if ( V_328 -> V_335 & V_336 )
V_329 = F_212 ( V_328 -> V_330 . V_290 ) - 1 ;
else
V_329 = V_328 -> V_330 . V_290 ;
if ( V_329 < 0 )
return V_231 ;
if ( V_328 -> V_330 . V_289 == V_42 ||
V_328 -> V_330 . V_289 == V_38 )
V_47 -> V_290 = V_329 ;
if ( V_328 -> V_330 . V_289 == V_38 )
V_2 -> V_290 = V_329 ;
return V_231 ;
}
static int F_213 ( struct V_223 * V_324 ,
T_8 V_325 , void * V_326 )
{
struct V_45 * V_56 ;
struct V_77 * V_76 = NULL ;
struct V_3 * V_4 = F_214 ( V_326 ) ;
struct V_5 * V_47 ;
struct V_1 * V_2 ;
struct V_72 * V_73 ;
struct V_268 * V_262 ;
T_2 V_337 = 1 ;
T_2 V_105 ;
int V_121 = V_231 ;
F_83 (fcoe, &fcoe_hostlist, list) {
if ( V_2 -> V_4 == V_4 ) {
V_47 = F_2 ( V_2 ) ;
V_76 = V_47 -> V_65 ;
break;
}
}
if ( ! V_76 ) {
V_121 = V_338 ;
goto V_52;
}
switch ( V_325 ) {
case V_339 :
case V_340 :
V_337 = 0 ;
break;
case V_341 :
case V_342 :
break;
case V_343 :
if ( V_4 -> V_98 & V_109 )
break;
V_105 = V_4 -> V_108 - ( sizeof( struct V_111 ) +
sizeof( struct V_112 ) ) ;
if ( V_105 >= V_344 )
F_50 ( V_76 , V_105 ) ;
break;
case V_345 :
break;
case V_346 :
F_215 ( & V_2 -> V_347 ) ;
V_73 = F_41 ( V_47 -> V_65 ) ;
F_216 ( V_348 , & V_73 -> V_198 ) ;
goto V_52;
break;
case V_349 :
F_46 ( V_76 , V_4 ) ;
break;
default:
F_3 ( V_4 , L_57
L_58 , V_325 ) ;
}
F_53 ( V_76 ) ;
V_56 = F_217 ( V_47 ) ;
if ( V_337 && ! F_218 ( V_76 ) ) {
switch ( V_56 -> V_350 ) {
case V_351 :
F_219 ( L_59 ) ;
break;
case V_352 :
case V_353 :
F_220 ( V_47 ) ;
} ;
} else if ( F_221 ( V_47 ) ) {
switch ( V_56 -> V_350 ) {
case V_351 :
F_219 ( L_60 ) ;
break;
case V_352 :
case V_353 :
V_262 = F_152 ( V_76 -> V_262 , F_127 () ) ;
V_262 -> V_354 ++ ;
F_131 () ;
F_90 ( V_76 ) ;
} ;
}
V_52:
return V_121 ;
}
static int F_222 ( struct V_3 * V_4 )
{
struct V_5 * V_47 ;
struct V_1 * V_2 ;
int V_121 = 0 ;
F_47 ( & V_355 ) ;
F_32 () ;
V_2 = F_223 ( V_4 ) ;
F_33 () ;
if ( V_2 ) {
V_47 = F_2 ( V_2 ) ;
F_221 ( V_47 ) ;
F_90 ( V_47 -> V_65 ) ;
} else
V_121 = - V_207 ;
F_48 ( & V_355 ) ;
return V_121 ;
}
static int F_224 ( struct V_3 * V_4 )
{
struct V_5 * V_47 ;
struct V_1 * V_2 ;
int V_121 = 0 ;
F_47 ( & V_355 ) ;
F_32 () ;
V_2 = F_223 ( V_4 ) ;
F_33 () ;
if ( ! V_2 ) {
V_121 = - V_207 ;
goto V_52;
}
V_47 = F_2 ( V_2 ) ;
if ( ! F_218 ( V_47 -> V_65 ) )
F_220 ( V_47 ) ;
V_52:
F_48 ( & V_355 ) ;
return V_121 ;
}
static int F_225 ( struct V_45 * V_56 )
{
struct V_5 * V_47 = F_18 ( V_56 ) ;
struct V_77 * V_76 = V_47 -> V_65 ;
struct V_3 * V_4 = F_60 ( V_76 ) ;
switch ( V_56 -> V_350 ) {
case V_352 :
return F_224 ( V_4 ) ;
case V_351 :
return F_222 ( V_4 ) ;
case V_353 :
default:
return - V_356 ;
} ;
}
static int F_226 ( struct V_3 * V_4 )
{
struct V_5 * V_47 ;
struct V_1 * V_2 ;
struct V_77 * V_76 ;
struct V_72 * V_73 ;
int V_121 = 0 ;
F_47 ( & V_355 ) ;
F_32 () ;
V_2 = F_223 ( V_4 ) ;
if ( ! V_2 ) {
V_121 = - V_207 ;
goto V_357;
}
V_47 = F_2 ( V_2 ) ;
V_76 = V_47 -> V_65 ;
V_73 = F_41 ( V_76 ) ;
F_215 ( & V_2 -> V_347 ) ;
F_216 ( V_348 , & V_73 -> V_198 ) ;
V_357:
F_33 () ;
F_48 ( & V_355 ) ;
return V_121 ;
}
static void V_199 ( struct V_358 * V_359 )
{
struct V_45 * V_56 ;
struct V_5 * V_47 ;
struct V_72 * V_73 ;
struct V_1 * V_2 ;
struct V_189 * V_190 ;
struct V_360 * V_361 ;
unsigned long V_18 ;
struct V_191 * V_117 ;
struct V_191 * V_362 ;
V_73 = F_35 ( V_359 , struct V_72 , V_198 ) ;
V_190 = V_73 -> V_76 -> V_66 ;
V_361 = F_227 ( V_190 ) ;
F_228 ( V_190 -> V_363 , V_18 ) ;
F_229 (vport, next_vport, &fc_host->vports, peers) {
if ( V_117 -> V_18 & ( V_364 | V_365 ) ) {
continue;
} else {
V_117 -> V_18 |= V_366 ;
F_216 ( F_230 ( V_190 ) ,
& V_117 -> V_367 ) ;
}
}
F_231 ( V_190 -> V_363 , V_18 ) ;
F_232 ( F_230 ( V_190 ) ) ;
F_47 ( & V_355 ) ;
V_2 = V_73 -> V_78 ;
V_47 = F_2 ( V_2 ) ;
V_56 = F_217 ( V_47 ) ;
F_86 ( V_73 -> V_76 ) ;
F_31 ( V_2 ) ;
F_48 ( & V_355 ) ;
F_23 ( V_56 ) ;
}
static bool F_233 ( struct V_3 * V_4 )
{
return true ;
}
static void F_234 ( struct V_1 * V_2 )
{
#ifdef F_235
int V_335 ;
T_1 V_368 , V_369 ;
struct V_3 * V_4 = V_2 -> V_22 ;
struct V_5 * V_47 = F_2 ( V_2 ) ;
struct V_370 V_330 = {
. V_290 = 0 ,
. V_289 = V_38
} ;
if ( V_4 && V_4 -> V_371 && V_4 -> V_371 -> V_372 ) {
V_335 = V_4 -> V_371 -> V_372 ( V_4 ) ;
if ( V_335 & V_373 ) {
V_330 . V_331 = V_374 ;
V_369 = F_236 ( V_4 , & V_330 ) ;
V_330 . V_289 = V_42 ;
V_368 = F_236 ( V_4 , & V_330 ) ;
} else {
V_330 . V_331 = V_332 ;
V_369 = F_237 ( V_4 , & V_330 ) ;
V_330 . V_289 = V_42 ;
V_368 = F_237 ( V_4 , & V_330 ) ;
}
V_2 -> V_290 = F_212 ( V_369 ) ? F_212 ( V_369 ) - 1 : 0 ;
V_47 -> V_290 = F_212 ( V_368 ) ? F_212 ( V_368 ) - 1 : V_2 -> V_290 ;
}
#endif
}
static int F_238 ( struct V_3 * V_4 , enum V_43 V_44 ,
enum V_375 V_376 )
{
int V_121 = 0 ;
struct V_45 * V_46 ;
struct V_5 * V_47 ;
struct V_1 * V_2 ;
struct V_77 * V_76 ;
F_47 ( & V_355 ) ;
F_32 () ;
if ( F_239 ( V_4 ) ) {
V_121 = - V_377 ;
goto V_357;
}
V_2 = F_13 ( V_4 , V_44 ) ;
if ( F_120 ( V_2 ) ) {
V_121 = F_240 ( V_2 ) ;
goto V_357;
}
V_47 = F_2 ( V_2 ) ;
V_46 = F_217 ( V_47 ) ;
V_76 = F_100 ( V_2 , & V_46 -> V_39 , 0 ) ;
if ( F_120 ( V_76 ) ) {
F_65 ( V_177 L_61 ,
V_4 -> V_136 ) ;
V_121 = - V_378 ;
F_33 () ;
F_31 ( V_2 ) ;
F_48 ( & V_355 ) ;
F_23 ( V_46 ) ;
goto V_52;
}
V_47 -> V_65 = V_76 ;
F_234 ( V_2 ) ;
V_76 -> V_379 = V_380 ;
F_241 ( V_76 ) ;
if ( V_376 == V_381 )
V_46 -> V_350 = V_352 ;
else
V_46 -> V_350 = V_351 ;
if ( V_376 == V_381 &&
! F_218 ( V_76 ) ) {
F_33 () ;
F_220 ( V_47 ) ;
F_48 ( & V_355 ) ;
return V_121 ;
}
V_357:
F_33 () ;
F_48 ( & V_355 ) ;
V_52:
return V_121 ;
}
static int F_242 ( struct V_3 * V_4 , enum V_43 V_44 )
{
return F_238 ( V_4 , V_44 , V_381 ) ;
}
static int F_243 ( struct V_3 * V_4 )
{
return F_238 ( V_4 , V_382 ,
V_383 ) ;
}
static int F_218 ( struct V_77 * V_76 )
{
struct V_3 * V_4 = F_60 ( V_76 ) ;
if ( F_244 ( V_4 ) )
return 0 ;
return - 1 ;
}
static void F_91 ( struct V_77 * V_76 )
{
struct V_209 * V_384 ;
struct V_67 * V_68 ;
unsigned int V_208 ;
F_245 (cpu) {
V_384 = & F_116 ( V_213 , V_208 ) ;
if ( ! V_384 -> V_212 || ! F_246 ( V_208 ) )
continue;
V_68 = F_247 ( 0 ) ;
if ( ! V_68 )
continue;
V_68 -> V_312 = F_180 ;
F_123 ( & V_384 -> V_215 . V_216 ) ;
F_129 ( & V_384 -> V_215 , V_68 ) ;
if ( V_384 -> V_215 . V_75 == 1 )
F_122 ( V_384 -> V_212 ) ;
F_124 ( & V_384 -> V_215 . V_216 ) ;
F_248 ( & V_303 ) ;
}
}
static int F_249 ( struct V_189 * V_190 )
{
struct V_77 * V_76 = F_108 ( V_190 ) ;
struct V_72 * V_73 = F_41 ( V_76 ) ;
struct V_1 * V_2 = V_73 -> V_78 ;
struct V_5 * V_47 = F_2 ( V_2 ) ;
struct V_45 * V_56 = F_217 ( V_47 ) ;
F_221 ( V_47 ) ;
F_90 ( V_47 -> V_65 ) ;
if ( V_56 -> V_350 != V_351 &&
! F_218 ( V_47 -> V_65 ) )
F_220 ( V_47 ) ;
return 0 ;
}
static struct V_1 *
F_223 ( const struct V_3 * V_4 )
{
struct V_1 * V_2 ;
F_83 (fcoe, &fcoe_hostlist, list) {
if ( V_2 -> V_4 == V_4 )
return V_2 ;
}
return NULL ;
}
static struct V_77 * F_239 ( const struct V_3 * V_4 )
{
struct V_5 * V_47 ;
struct V_1 * V_2 ;
V_2 = F_223 ( V_4 ) ;
V_47 = F_2 ( V_2 ) ;
return ( V_2 ) ? V_47 -> V_65 : NULL ;
}
static int F_105 ( const struct V_77 * V_76 )
{
struct V_1 * V_2 ;
struct V_72 * V_73 ;
V_2 = F_223 ( F_60 ( V_76 ) ) ;
if ( ! V_2 ) {
V_73 = F_41 ( V_76 ) ;
V_2 = V_73 -> V_78 ;
F_250 ( & V_2 -> V_347 , & V_385 ) ;
}
return 0 ;
}
static void F_110 ( const struct V_77 * V_76 )
{
struct V_1 * V_2 ;
struct V_72 * V_73 ;
V_73 = F_41 ( V_76 ) ;
V_2 = V_73 -> V_78 ;
F_215 ( & V_2 -> V_347 ) ;
return;
}
static int T_5 F_251 ( void )
{
struct V_209 * V_210 ;
unsigned int V_208 ;
int V_121 = 0 ;
V_348 = F_252 ( L_62 , 0 , 0 ) ;
if ( ! V_348 )
return - V_54 ;
V_121 = F_253 ( & V_386 ) ;
if ( V_121 ) {
F_65 ( V_177 L_63
L_64 ) ;
return V_121 ;
}
F_47 ( & V_355 ) ;
F_245 (cpu) {
V_210 = & F_116 ( V_213 , V_208 ) ;
F_51 ( & V_210 -> V_215 ) ;
}
F_254 () ;
F_255 (cpu)
F_115 ( V_208 ) ;
V_121 = F_256 ( & V_387 ) ;
if ( V_121 )
goto V_388;
F_257 () ;
F_203 () ;
V_121 = F_111 () ;
if ( V_121 )
goto V_388;
F_48 ( & V_355 ) ;
return 0 ;
V_388:
F_255 (cpu) {
F_125 ( V_208 ) ;
}
F_257 () ;
F_48 ( & V_355 ) ;
F_258 ( V_348 ) ;
return V_121 ;
}
static void T_6 F_259 ( void )
{
struct V_1 * V_2 , * V_318 ;
struct V_5 * V_47 ;
struct V_72 * V_73 ;
unsigned int V_208 ;
F_47 ( & V_355 ) ;
F_206 () ;
F_32 () ;
F_229 (fcoe, tmp, &fcoe_hostlist, list) {
V_47 = F_2 ( V_2 ) ;
V_73 = F_41 ( V_47 -> V_65 ) ;
F_110 ( V_73 -> V_76 ) ;
F_216 ( V_348 , & V_73 -> V_198 ) ;
}
F_33 () ;
F_254 () ;
F_255 (cpu)
F_125 ( V_208 ) ;
F_260 ( & V_387 ) ;
F_257 () ;
F_48 ( & V_355 ) ;
F_258 ( V_348 ) ;
F_113 () ;
F_261 ( & V_386 ) ;
}
static void F_262 ( struct V_389 * V_390 , struct V_153 * V_154 , void * V_316 )
{
struct V_5 * V_6 = V_316 ;
struct V_391 * V_392 = F_263 ( V_390 ) ;
struct V_77 * V_76 = V_392 -> V_65 ;
T_1 * V_393 ;
if ( F_120 ( V_154 ) )
goto V_394;
V_393 = F_264 ( V_154 ) -> V_395 ;
if ( F_42 ( V_393 ) )
F_265 ( V_6 , V_76 , V_154 ) ;
if ( ! F_42 ( V_393 ) )
V_60 ( V_76 , V_393 ) ;
V_394:
F_266 ( V_390 , V_154 , V_76 ) ;
}
static void F_267 ( struct V_389 * V_390 , struct V_153 * V_154 , void * V_316 )
{
struct V_77 * V_76 = V_316 ;
static T_1 V_396 [ V_11 ] = { 0 } ;
if ( ! F_120 ( V_154 ) )
V_60 ( V_76 , V_396 ) ;
F_268 ( V_390 , V_154 , V_76 ) ;
}
static struct V_389 * F_269 ( struct V_77 * V_76 , T_2 V_397 ,
struct V_153 * V_154 , unsigned int V_398 ,
void (* F_270)( struct V_389 * ,
struct V_153 * ,
void * ) ,
void * V_316 , T_2 V_399 )
{
struct V_72 * V_73 = F_41 ( V_76 ) ;
struct V_1 * V_2 = V_73 -> V_78 ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_155 * V_156 = F_76 ( V_154 ) ;
switch ( V_398 ) {
case V_400 :
case V_401 :
if ( V_76 -> V_402 )
break;
return F_271 ( V_76 , V_397 , V_154 , V_398 , F_262 ,
V_6 , V_399 ) ;
case V_307 :
if ( F_148 ( V_156 -> V_253 ) != V_309 )
break;
return F_271 ( V_76 , V_397 , V_154 , V_398 , F_267 ,
V_76 , V_399 ) ;
}
return F_271 ( V_76 , V_397 , V_154 , V_398 , F_270 , V_316 , V_399 ) ;
}
static int F_272 ( struct V_191 * V_117 , bool V_403 )
{
struct V_189 * V_190 = F_107 ( V_117 ) ;
struct V_77 * V_188 = F_108 ( V_190 ) ;
struct V_72 * V_73 = F_41 ( V_188 ) ;
struct V_1 * V_2 = V_73 -> V_78 ;
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_77 * V_404 ;
int V_121 ;
char V_405 [ 32 ] ;
V_121 = F_273 ( V_117 ) ;
if ( V_121 ) {
F_274 ( V_117 -> V_202 , V_405 , sizeof( V_405 ) ) ;
F_65 ( V_177 L_65
L_66 ,
V_405 ) ;
return V_121 ;
}
F_47 ( & V_355 ) ;
F_32 () ;
V_404 = F_100 ( V_2 , & V_117 -> V_39 , 1 ) ;
F_33 () ;
F_48 ( & V_355 ) ;
if ( F_120 ( V_404 ) ) {
F_65 ( V_177 L_67 ,
V_4 -> V_136 ) ;
return - V_378 ;
}
if ( V_403 ) {
F_275 ( V_117 , V_406 ) ;
} else {
V_404 -> V_379 = V_380 ;
F_241 ( V_404 ) ;
F_276 ( V_404 ) ;
}
return 0 ;
}
static int F_277 ( struct V_191 * V_117 )
{
struct V_189 * V_190 = F_107 ( V_117 ) ;
struct V_77 * V_188 = F_108 ( V_190 ) ;
struct V_77 * V_404 = V_117 -> V_407 ;
F_47 ( & V_188 -> V_97 ) ;
F_215 ( & V_404 -> V_347 ) ;
F_48 ( & V_188 -> V_97 ) ;
F_47 ( & V_355 ) ;
F_86 ( V_404 ) ;
F_48 ( & V_355 ) ;
return 0 ;
}
static int F_278 ( struct V_191 * V_117 , bool V_408 )
{
struct V_77 * V_76 = V_117 -> V_407 ;
if ( V_408 ) {
F_275 ( V_117 , V_406 ) ;
F_87 ( V_76 ) ;
} else {
V_76 -> V_379 = V_380 ;
F_241 ( V_76 ) ;
F_276 ( V_76 ) ;
}
return 0 ;
}
static void F_279 ( struct V_191 * V_117 )
{
struct V_77 * V_76 = V_117 -> V_407 ;
struct V_153 * V_154 ;
T_9 V_242 ;
snprintf ( F_62 ( V_76 -> V_66 ) , V_133 ,
L_68 , V_134 , V_135 ,
F_60 ( V_76 ) -> V_136 , V_117 -> V_409 ) ;
if ( V_76 -> V_259 != V_410 )
return;
V_242 = F_280 ( F_62 ( V_76 -> V_66 ) , 255 ) ;
V_154 = F_281 ( V_76 ,
sizeof( struct V_411 ) +
sizeof( struct V_412 ) + V_242 ) ;
if ( ! V_154 )
return;
V_76 -> V_413 . V_414 ( V_76 , V_415 , V_154 , V_416 ,
NULL , NULL , 3 * V_76 -> V_85 ) ;
}
static void F_282 ( struct V_417 * V_418 )
{
struct V_45 * V_46 =
F_283 ( V_418 ) ;
struct V_5 * V_47 = F_18 ( V_46 ) ;
struct V_1 * V_2 = F_19 ( V_47 ) ;
V_418 -> V_419 = F_177 ( V_2 -> V_4 ) ;
}
static void F_284 ( struct V_77 * V_76 ,
T_2 V_420 , struct V_153 * V_154 )
{
struct V_72 * V_73 = F_41 ( V_76 ) ;
struct V_1 * V_2 = V_73 -> V_78 ;
struct V_5 * V_47 = F_2 ( V_2 ) ;
if ( V_154 && F_184 ( V_154 ) == V_400 )
F_265 ( V_47 , V_76 , V_154 ) ;
}
