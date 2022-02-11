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
V_2 -> V_40 . type = F_13 ( V_42 ) ;
V_2 -> V_40 . V_39 = V_4 ;
F_12 ( & V_2 -> V_40 ) ;
return 0 ;
}
static struct V_1 * F_14 ( struct V_3 * V_4 ,
enum V_43 V_44 )
{
struct V_45 * V_46 ;
struct V_5 * V_47 ;
struct V_1 * V_2 ;
int V_48 ;
int V_49 ;
if ( ! F_15 ( V_50 ) ) {
F_3 ( V_4 ,
L_4 ) ;
V_2 = F_16 ( - V_51 ) ;
goto V_52;
}
V_48 = sizeof( struct V_5 ) + sizeof( struct V_1 ) ;
V_46 = F_17 ( & V_4 -> V_39 , & V_53 ,
V_48 ) ;
if ( ! V_46 ) {
F_18 ( L_5 ) ;
V_2 = F_16 ( - V_54 ) ;
goto V_55;
}
V_47 = F_19 ( V_46 ) ;
V_2 = F_20 ( V_47 ) ;
F_21 ( V_4 ) ;
F_22 ( V_47 , V_44 ) ;
V_47 -> V_56 = V_57 ;
V_47 -> V_58 = V_59 ;
V_47 -> V_60 = V_61 ;
V_49 = F_1 ( V_2 , V_4 ) ;
if ( V_49 ) {
F_23 ( V_47 ) ;
F_24 ( V_46 ) ;
F_25 ( V_4 ) ;
V_2 = F_16 ( V_49 ) ;
goto V_55;
}
goto V_52;
V_55:
F_26 ( V_50 ) ;
V_52:
return V_2 ;
}
static void F_27 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
T_1 V_10 [ V_11 ] ;
const struct V_12 * V_13 ;
F_28 ( & V_2 -> V_35 ) ;
F_28 ( & V_2 -> V_40 ) ;
F_29 () ;
memcpy ( V_10 , ( T_1 [ 6 ] ) V_29 , V_11 ) ;
F_30 ( V_4 , V_10 ) ;
if ( V_6 -> V_26 )
F_30 ( V_4 , V_6 -> V_25 ) ;
if ( V_6 -> V_30 == V_31 ) {
F_31 ( V_4 , V_32 ) ;
F_31 ( V_4 , V_33 ) ;
} else
F_31 ( V_4 , V_34 ) ;
V_13 = V_4 -> V_14 ;
if ( V_13 -> V_62 ) {
if ( V_13 -> V_62 ( V_4 ) )
F_3 ( V_4 , L_6
L_2 ) ;
}
V_2 -> V_63 = 1 ;
}
static void F_32 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
F_33 () ;
if ( ! V_2 -> V_63 )
F_27 ( V_2 ) ;
F_34 () ;
F_23 ( V_6 ) ;
F_35 ( V_6 -> V_64 -> V_65 ) ;
F_25 ( V_4 ) ;
F_26 ( V_50 ) ;
}
static int V_41 ( struct V_66 * V_67 , struct V_3 * V_4 ,
struct V_68 * V_69 ,
struct V_3 * V_70 )
{
struct V_1 * V_2 ;
struct V_5 * V_47 ;
V_2 = F_36 ( V_69 , struct V_1 , V_40 ) ;
V_47 = F_2 ( V_2 ) ;
F_37 ( V_47 , V_67 ) ;
return 0 ;
}
static void F_38 ( struct V_71 * V_72 , struct V_66 * V_67 )
{
if ( V_72 -> V_73 . V_74 )
F_39 ( V_72 -> V_75 , V_67 ) ;
else if ( F_40 ( V_67 ) )
F_39 ( V_72 -> V_75 , V_67 ) ;
}
static void V_57 ( struct V_5 * V_6 , struct V_66 * V_67 )
{
V_67 -> V_39 = F_41 ( V_6 ) -> V_4 ;
F_38 ( F_42 ( V_6 -> V_64 ) , V_67 ) ;
}
static void V_59 ( struct V_76 * V_75 , T_1 * V_24 )
{
struct V_71 * V_72 = F_42 ( V_75 ) ;
struct V_1 * V_2 = V_72 -> V_77 ;
if ( ! F_43 ( V_72 -> V_78 ) )
F_30 ( V_2 -> V_4 , V_72 -> V_78 ) ;
if ( ! F_43 ( V_24 ) )
F_9 ( V_2 -> V_4 , V_24 ) ;
memcpy ( V_72 -> V_78 , V_24 , V_11 ) ;
}
static T_1 * V_61 ( struct V_76 * V_75 )
{
struct V_71 * V_72 = F_42 ( V_75 ) ;
return V_72 -> V_78 ;
}
static int F_44 ( struct V_76 * V_75 )
{
V_75 -> V_79 = 0 ;
V_75 -> V_80 = 0 ;
V_75 -> V_81 = 3 ;
V_75 -> V_82 = 3 ;
V_75 -> V_83 = 2 * 1000 ;
V_75 -> V_84 = 2 * 2 * 1000 ;
V_75 -> V_85 = ( V_86 | V_87 |
V_88 | V_89 ) ;
V_75 -> V_90 = 1 ;
F_45 ( V_75 ) ;
F_46 ( V_75 ) ;
V_75 -> V_91 = 0 ;
V_75 -> V_92 = 0 ;
V_75 -> V_93 = 0 ;
V_75 -> V_94 = 0 ;
V_75 -> V_95 = 0 ;
return 0 ;
}
static void F_47 ( struct V_76 * V_75 ,
struct V_3 * V_4 )
{
F_48 ( & V_75 -> V_96 ) ;
if ( V_4 -> V_97 & V_98 )
V_75 -> V_99 = 1 ;
else
V_75 -> V_99 = 0 ;
if ( V_4 -> V_97 & V_100 ) {
V_75 -> V_91 = 1 ;
F_3 ( V_4 , L_7 ) ;
} else {
V_75 -> V_91 = 0 ;
}
if ( V_4 -> V_97 & V_101 ) {
V_75 -> V_92 = 1 ;
V_75 -> V_95 = V_4 -> V_102 ;
F_3 ( V_4 , L_8 ,
V_75 -> V_95 ) ;
} else {
V_75 -> V_92 = 0 ;
V_75 -> V_95 = 0 ;
}
if ( V_4 -> V_103 ) {
V_75 -> V_93 = 1 ;
V_75 -> V_94 = V_4 -> V_103 ;
F_3 ( V_4 , L_9 ,
V_75 -> V_94 ) ;
} else {
V_75 -> V_93 = 0 ;
V_75 -> V_94 = 0 ;
}
F_49 ( & V_75 -> V_96 ) ;
}
static int F_50 ( struct V_76 * V_75 , struct V_3 * V_4 )
{
T_2 V_104 ;
T_3 V_105 , V_106 ;
struct V_1 * V_2 ;
struct V_5 * V_47 ;
struct V_71 * V_72 ;
V_72 = F_42 ( V_75 ) ;
V_2 = V_72 -> V_77 ;
V_47 = F_2 ( V_2 ) ;
V_104 = V_4 -> V_107 ;
if ( V_4 -> V_97 & V_108 ) {
V_104 = V_109 ;
F_3 ( V_4 , L_10 , V_104 ) ;
}
V_104 -= ( sizeof( struct V_110 ) + sizeof( struct V_111 ) ) ;
if ( F_51 ( V_75 , V_104 ) )
return - V_112 ;
F_47 ( V_75 , V_4 ) ;
F_52 ( & V_72 -> V_73 ) ;
V_72 -> V_113 = 0 ;
F_53 ( & V_72 -> V_114 , V_115 , ( unsigned long ) V_75 ) ;
F_54 ( V_75 ) ;
if ( ! V_75 -> V_116 ) {
if ( F_55 ( V_4 , & V_105 , V_117 ) )
V_105 = F_56 ( V_47 -> V_25 , 1 , 0 ) ;
F_57 ( V_75 , V_105 ) ;
if ( F_55 ( V_4 , & V_106 , V_118 ) )
V_106 = F_56 ( V_47 -> V_25 ,
2 , 0 ) ;
F_58 ( V_75 , V_106 ) ;
}
return 0 ;
}
static int F_59 ( struct V_76 * V_75 , struct V_119 * V_39 )
{
int V_120 = 0 ;
V_75 -> V_65 -> V_121 = V_122 ;
V_75 -> V_65 -> V_123 = V_124 ;
V_75 -> V_65 -> V_125 = 0 ;
V_75 -> V_65 -> V_126 = V_127 ;
if ( V_75 -> V_116 )
V_75 -> V_65 -> V_128 = V_129 ;
else
V_75 -> V_65 -> V_128 = V_130 ;
V_120 = F_60 ( V_75 -> V_65 , V_39 ) ;
if ( V_120 ) {
F_3 ( F_61 ( V_75 ) , L_11
L_12 ) ;
return V_120 ;
}
if ( ! V_75 -> V_116 )
F_62 ( V_75 -> V_65 ) = V_131 ;
snprintf ( F_63 ( V_75 -> V_65 ) , V_132 ,
L_13 , V_133 , V_134 ,
F_61 ( V_75 ) -> V_135 ) ;
return 0 ;
}
static void F_64 ( struct V_76 * V_75 , struct V_3 * V_4 )
{
struct V_1 * V_2 ;
struct V_71 * V_72 ;
struct V_3 * V_22 ;
int V_120 ;
V_72 = F_42 ( V_75 ) ;
V_2 = V_72 -> V_77 ;
V_22 = V_2 -> V_22 ;
if ( ! V_22 )
return;
if ( V_75 -> V_116 )
return;
if ( V_22 -> V_14 -> V_136 ) {
struct V_137 * V_138 ;
V_138 = F_65 ( sizeof( * V_138 ) , V_139 ) ;
if ( ! V_138 )
return;
V_120 = V_22 -> V_14 -> V_136 ( V_22 ,
V_138 ) ;
if ( V_120 ) {
F_66 ( V_140 L_14
L_15 ) ;
return;
}
snprintf ( F_67 ( V_75 -> V_65 ) ,
V_141 ,
L_16 ,
V_138 -> V_142 ) ;
snprintf ( F_68 ( V_75 -> V_65 ) ,
V_141 ,
L_16 ,
V_138 -> V_143 ) ;
snprintf ( F_69 ( V_75 -> V_65 ) ,
V_132 ,
L_16 ,
V_138 -> V_144 ) ;
snprintf ( F_70 ( V_75 -> V_65 ) ,
V_132 ,
L_16 ,
V_138 -> V_145 ) ;
snprintf ( F_71 ( V_75 -> V_65 ) ,
V_146 ,
L_16 ,
V_138 -> V_147 ) ;
snprintf ( F_72 ( V_75 -> V_65 ) ,
V_146 ,
L_16 ,
V_138 -> V_148 ) ;
snprintf ( F_73 ( V_75 -> V_65 ) ,
V_146 ,
L_16 ,
V_138 -> V_149 ) ;
snprintf ( F_74 ( V_75 -> V_65 ) ,
V_146 ,
L_16 ,
V_138 -> V_150 ) ;
V_75 -> V_151 = 1 ;
F_75 ( V_138 ) ;
} else {
V_75 -> V_151 = 0 ;
F_66 ( V_140 L_17 ) ;
}
}
static bool F_76 ( struct V_152 * V_153 )
{
struct V_154 * V_155 = F_77 ( V_153 ) ;
struct V_156 * V_157 ;
if ( F_78 ( F_79 ( V_153 ) ) &&
( F_79 ( V_153 ) -> V_158 > V_159 ) )
return true ;
else if ( ( F_79 ( V_153 ) == NULL ) &&
( V_155 -> V_160 == V_161 ) &&
( F_80 ( V_155 -> V_162 ) == V_163 ) ) {
V_157 = F_81 ( V_153 , sizeof( * V_157 ) ) ;
if ( ( V_157 -> V_164 & V_165 ) &&
( F_82 ( V_157 -> V_166 ) > V_159 ) )
return true ;
}
return false ;
}
static inline int F_83 ( struct V_76 * V_75 )
{
struct V_71 * V_72 = F_42 ( V_75 ) ;
struct V_1 * V_2 = V_72 -> V_77 ;
struct V_1 * V_167 = NULL ;
struct V_3 * V_168 , * V_169 ;
T_4 V_170 = V_171 ;
T_4 V_172 = V_173 ;
if ( ! V_75 -> V_93 || ! V_75 -> V_94 ||
( V_75 -> V_94 >= V_172 ) ) {
V_75 -> V_94 = 0 ;
goto V_174;
}
if ( V_2 -> V_4 -> V_16 & V_21 )
V_169 = F_4 ( V_2 -> V_4 ) ;
else
V_169 = V_2 -> V_4 ;
F_84 (oldfcoe, &fcoe_hostlist, list) {
if ( V_167 -> V_4 -> V_16 & V_21 )
V_168 = F_4 ( V_167 -> V_4 ) ;
else
V_168 = V_167 -> V_4 ;
if ( V_169 == V_168 ) {
V_2 -> V_175 = V_167 -> V_175 ;
break;
}
}
if ( V_2 -> V_175 ) {
if ( ! F_85 ( V_75 , V_2 -> V_175 , F_76 ) ) {
F_66 ( V_176 L_18
L_19 ,
V_2 -> V_175 , V_2 -> V_4 -> V_135 ) ;
return - V_54 ;
}
} else {
V_2 -> V_175 = F_86 ( V_75 , V_177 ,
V_171 , V_75 -> V_94 ,
F_76 ) ;
if ( ! V_2 -> V_175 ) {
F_66 ( V_176 L_20
L_21 ,
V_2 -> V_4 -> V_135 ) ;
return - V_54 ;
}
}
V_170 += V_75 -> V_94 + 1 ;
V_174:
if ( ! F_86 ( V_75 , V_177 , V_170 , V_172 , NULL ) ) {
F_66 ( V_176 L_22
L_23 , V_2 -> V_4 -> V_135 ) ;
return - V_54 ;
}
return 0 ;
}
static void F_87 ( struct V_76 * V_75 )
{
struct V_71 * V_72 = F_42 ( V_75 ) ;
struct V_1 * V_2 = V_72 -> V_77 ;
struct V_3 * V_4 = V_2 -> V_4 ;
F_3 ( V_4 , L_24 ) ;
F_88 ( V_75 ) ;
F_89 ( V_75 ) ;
F_90 ( & V_72 -> V_114 ) ;
F_91 ( V_75 ) ;
F_33 () ;
if ( ! F_43 ( V_72 -> V_78 ) )
F_30 ( V_4 , V_72 -> V_78 ) ;
if ( V_75 -> V_116 )
F_29 () ;
else
F_27 ( V_2 ) ;
F_34 () ;
F_92 ( V_75 ) ;
F_93 ( V_75 -> V_65 ) ;
F_94 ( V_75 -> V_65 ) ;
F_95 ( V_75 ) ;
F_96 ( V_75 ) ;
F_97 ( V_75 ) ;
if ( V_75 -> V_116 )
F_35 ( V_75 -> V_65 ) ;
}
static int F_98 ( struct V_76 * V_75 , T_4 V_178 ,
struct V_179 * V_180 , unsigned int V_181 )
{
struct V_3 * V_4 = F_61 ( V_75 ) ;
if ( V_4 -> V_14 -> V_182 )
return V_4 -> V_14 -> V_182 ( V_4 ,
V_178 , V_180 ,
V_181 ) ;
return 0 ;
}
static int F_99 ( struct V_76 * V_75 , T_4 V_178 ,
struct V_179 * V_180 , unsigned int V_181 )
{
struct V_3 * V_4 = F_61 ( V_75 ) ;
if ( V_4 -> V_14 -> V_183 )
return V_4 -> V_14 -> V_183 ( V_4 , V_178 ,
V_180 , V_181 ) ;
return 0 ;
}
static int F_100 ( struct V_76 * V_75 , T_4 V_178 )
{
struct V_3 * V_4 = F_61 ( V_75 ) ;
if ( V_4 -> V_14 -> V_184 )
return V_4 -> V_14 -> V_184 ( V_4 , V_178 ) ;
return 0 ;
}
static struct V_76 * F_101 ( struct V_1 * V_2 ,
struct V_119 * V_185 , int V_186 )
{
struct V_5 * V_47 = F_2 ( V_2 ) ;
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_76 * V_75 , * V_187 ;
struct V_71 * V_72 ;
struct V_188 * V_189 ;
int V_120 ;
struct V_190 * V_116 = F_102 ( V_185 ) ;
F_3 ( V_4 , L_25 ) ;
if ( ! V_186 )
V_75 = F_103 ( & V_191 , sizeof( * V_72 ) ) ;
else
V_75 = F_104 ( V_116 , sizeof( * V_72 ) ) ;
if ( ! V_75 ) {
F_3 ( V_4 , L_26 ) ;
V_120 = - V_54 ;
goto V_52;
}
V_72 = F_42 ( V_75 ) ;
V_72 -> V_75 = V_75 ;
V_72 -> V_77 = V_2 ;
V_72 -> V_192 = F_61 ;
V_72 -> V_193 = V_194 ;
V_72 -> V_195 = V_196 ;
F_105 ( & V_72 -> V_197 , V_198 ) ;
F_106 ( V_75 ) ;
V_120 = F_44 ( V_75 ) ;
if ( V_120 ) {
F_3 ( V_4 , L_27
L_28 ) ;
goto V_199;
}
if ( V_186 ) {
F_3 ( V_4 , L_29
L_30 ,
V_116 -> V_200 , V_116 -> V_201 ) ;
F_57 ( V_75 , V_116 -> V_200 ) ;
F_58 ( V_75 , V_116 -> V_201 ) ;
}
V_120 = F_50 ( V_75 , V_4 ) ;
if ( V_120 ) {
F_3 ( V_4 , L_31
L_28 ) ;
goto V_202;
}
V_120 = F_59 ( V_75 , V_185 ) ;
if ( V_120 ) {
F_3 ( V_4 , L_32
L_28 ) ;
goto V_202;
}
V_120 = F_107 ( V_75 , V_47 , & V_203 , 1 ) ;
if ( V_120 ) {
F_3 ( V_4 , L_33
L_28 ) ;
goto V_202;
}
F_64 ( V_75 , V_4 ) ;
if ( ! V_186 )
V_120 = F_83 ( V_75 ) ;
else {
V_189 = F_108 ( V_116 ) ;
V_187 = F_109 ( V_189 ) ;
V_120 = F_110 ( V_187 , V_75 ) ;
}
if ( V_120 ) {
F_3 ( V_4 , L_34 ) ;
goto V_202;
}
return V_75 ;
V_202:
F_96 ( V_75 ) ;
V_199:
F_111 ( V_75 ) ;
F_35 ( V_75 -> V_65 ) ;
V_52:
return F_16 ( V_120 ) ;
}
static int T_5 F_112 ( void )
{
V_130 =
F_113 ( & V_204 ) ;
V_129 =
F_113 ( & V_205 ) ;
if ( ! V_130 ) {
F_66 ( V_176 L_35 ) ;
return - V_206 ;
}
return 0 ;
}
static int T_6 F_114 ( void )
{
F_115 ( V_130 ) ;
F_115 ( V_129 ) ;
V_130 = NULL ;
V_129 = NULL ;
return 0 ;
}
static void F_116 ( unsigned int V_207 )
{
struct V_208 * V_209 ;
struct V_210 * V_211 ;
V_209 = & F_117 ( V_212 , V_207 ) ;
V_211 = F_118 ( V_213 ,
( void * ) V_209 , F_119 ( V_207 ) ,
L_36 , V_207 ) ;
if ( F_120 ( ! F_121 ( V_211 ) ) ) {
F_122 ( V_211 , V_207 ) ;
F_123 ( V_211 ) ;
F_124 ( & V_209 -> V_214 . V_215 ) ;
V_209 -> V_211 = V_211 ;
F_125 ( & V_209 -> V_214 . V_215 ) ;
}
}
static void F_126 ( unsigned int V_207 )
{
struct V_208 * V_209 ;
struct V_210 * V_211 ;
struct V_216 * V_217 ;
struct V_66 * V_67 ;
#ifdef F_127
struct V_208 * V_218 ;
unsigned V_219 = F_128 () ;
#endif
F_18 ( L_37 , V_207 ) ;
V_209 = & F_117 ( V_212 , V_207 ) ;
F_124 ( & V_209 -> V_214 . V_215 ) ;
V_211 = V_209 -> V_211 ;
V_209 -> V_211 = NULL ;
V_217 = V_209 -> V_220 ;
V_209 -> V_220 = NULL ;
V_209 -> V_221 = 0 ;
F_125 ( & V_209 -> V_214 . V_215 ) ;
#ifdef F_127
if ( V_207 != V_219 ) {
V_218 = & F_117 ( V_212 , V_219 ) ;
F_124 ( & V_218 -> V_214 . V_215 ) ;
if ( V_218 -> V_211 ) {
F_18 ( L_38 ,
V_207 , V_219 ) ;
while ( ( V_67 = F_129 ( & V_209 -> V_214 ) ) != NULL )
F_130 ( & V_218 -> V_214 , V_67 ) ;
F_125 ( & V_218 -> V_214 . V_215 ) ;
} else {
while ( ( V_67 = F_129 ( & V_209 -> V_214 ) ) != NULL )
F_131 ( V_67 ) ;
F_125 ( & V_218 -> V_214 . V_215 ) ;
}
} else {
F_124 ( & V_209 -> V_214 . V_215 ) ;
while ( ( V_67 = F_129 ( & V_209 -> V_214 ) ) != NULL )
F_131 ( V_67 ) ;
F_125 ( & V_209 -> V_214 . V_215 ) ;
}
F_132 () ;
#else
F_124 ( & V_209 -> V_214 . V_215 ) ;
while ( ( V_67 = F_129 ( & V_209 -> V_214 ) ) != NULL )
F_131 ( V_67 ) ;
F_125 ( & V_209 -> V_214 . V_215 ) ;
#endif
if ( V_211 )
F_133 ( V_211 ) ;
if ( V_217 )
F_134 ( V_217 ) ;
}
static int F_135 ( struct V_222 * V_223 ,
unsigned long V_224 , void * V_225 )
{
unsigned V_207 = ( unsigned long ) V_225 ;
switch ( V_224 ) {
case V_226 :
case V_227 :
F_18 ( L_39 , V_207 ) ;
F_116 ( V_207 ) ;
break;
case V_228 :
case V_229 :
F_18 ( L_40 , V_207 ) ;
F_126 ( V_207 ) ;
break;
default:
break;
}
return V_230 ;
}
static inline unsigned int F_136 ( void )
{
static unsigned int V_231 ;
V_231 = F_137 ( V_231 , V_232 ) ;
if ( V_231 >= V_233 )
V_231 = F_138 ( V_232 ) ;
return V_231 ;
}
static int V_37 ( struct V_66 * V_67 , struct V_3 * V_4 ,
struct V_68 * V_69 , struct V_3 * V_234 )
{
struct V_76 * V_75 ;
struct V_235 * V_236 ;
struct V_5 * V_47 ;
struct V_1 * V_2 ;
struct V_154 * V_155 ;
struct V_208 * V_237 ;
struct V_238 * V_239 ;
unsigned int V_207 ;
V_2 = F_36 ( V_69 , struct V_1 , V_35 ) ;
V_47 = F_2 ( V_2 ) ;
V_75 = V_47 -> V_64 ;
if ( F_139 ( ! V_75 ) ) {
F_3 ( V_4 , L_41 ) ;
goto V_240;
}
if ( ! V_75 -> V_79 )
goto V_240;
F_3 ( V_4 , L_42
L_43 ,
V_67 -> V_241 , V_67 -> V_158 , V_67 -> V_242 , V_67 -> V_243 ,
F_140 ( V_67 ) , F_141 ( V_67 ) ,
V_67 -> V_244 , V_67 -> V_39 ? V_67 -> V_39 -> V_135 : L_44 ) ;
V_239 = F_142 ( V_67 ) ;
if ( F_143 ( V_47 ) &&
F_144 ( V_239 -> V_245 , V_47 -> V_246 ) ) {
F_3 ( V_4 , L_45 ,
V_239 -> V_245 ) ;
goto V_49;
}
if ( F_139 ( ( V_67 -> V_241 < V_247 ) ||
! F_145 ( V_67 , V_248 ) ) )
goto V_49;
F_146 ( V_67 , sizeof( struct V_110 ) ) ;
V_155 = (struct V_154 * ) F_147 ( V_67 ) ;
if ( F_148 ( & V_239 -> V_249 [ 3 ] ) != F_148 ( V_155 -> V_250 ) ) {
F_3 ( V_4 , L_46 ,
V_239 -> V_249 ) ;
goto V_49;
}
V_236 = F_149 ( V_67 ) ;
V_236 -> V_251 = V_75 ;
if ( F_148 ( V_155 -> V_252 ) & V_253 )
V_207 = F_80 ( V_155 -> V_254 ) & V_255 ;
else {
if ( F_80 ( V_155 -> V_162 ) == V_163 )
V_207 = F_136 () ;
else
V_207 = F_80 ( V_155 -> V_162 ) & V_255 ;
}
if ( V_207 >= V_233 )
goto V_49;
V_237 = & F_117 ( V_212 , V_207 ) ;
F_150 ( & V_237 -> V_214 . V_215 ) ;
if ( F_139 ( ! V_237 -> V_211 ) ) {
F_3 ( V_4 , L_47
L_48
L_49 ) ;
F_151 ( & V_237 -> V_214 . V_215 ) ;
V_207 = F_138 ( V_232 ) ;
V_237 = & F_117 ( V_212 , V_207 ) ;
F_150 ( & V_237 -> V_214 . V_215 ) ;
if ( ! V_237 -> V_211 ) {
F_151 ( & V_237 -> V_214 . V_215 ) ;
goto V_49;
}
}
F_130 ( & V_237 -> V_214 , V_67 ) ;
if ( V_237 -> V_211 -> V_256 == V_257 )
F_123 ( V_237 -> V_211 ) ;
F_151 ( & V_237 -> V_214 . V_215 ) ;
return 0 ;
V_49:
F_152 ( V_75 -> V_258 , F_128 () ) -> V_259 ++ ;
F_132 () ;
V_240:
F_131 ( V_67 ) ;
return - 1 ;
}
static int F_153 ( struct V_66 * V_67 , int V_260 )
{
struct V_208 * V_237 ;
int V_120 ;
V_237 = & F_154 ( V_212 ) ;
V_120 = F_155 ( V_67 , V_260 , V_237 ) ;
F_156 ( V_212 ) ;
return V_120 ;
}
static int F_157 ( struct V_76 * V_75 , struct V_152 * V_153 )
{
int V_261 ;
T_2 V_262 ;
struct V_238 * V_239 ;
struct V_111 * V_263 ;
struct V_66 * V_67 ;
struct V_264 * V_258 ;
struct V_154 * V_155 ;
unsigned int V_265 ;
unsigned int V_260 ;
unsigned int V_266 ;
struct V_71 * V_72 = F_42 ( V_75 ) ;
struct V_1 * V_2 = V_72 -> V_77 ;
struct V_5 * V_47 = F_2 ( V_2 ) ;
T_1 V_267 , V_268 ;
struct V_110 * V_269 ;
F_158 ( ( F_159 ( V_153 ) % sizeof( T_2 ) ) != 0 ) ;
V_155 = F_77 ( V_153 ) ;
V_67 = F_160 ( V_153 ) ;
V_261 = V_67 -> V_241 / V_270 ;
if ( ! V_75 -> V_79 ) {
F_131 ( V_67 ) ;
return 0 ;
}
if ( F_139 ( V_155 -> V_271 == V_272 ) &&
F_161 ( V_47 , V_75 , V_67 ) )
return 0 ;
V_267 = F_162 ( V_153 ) ;
V_268 = F_163 ( V_153 ) ;
V_266 = sizeof( struct V_238 ) ;
V_265 = sizeof( struct V_110 ) ;
V_260 = sizeof( struct V_111 ) ;
V_261 = ( V_67 -> V_241 - V_260 + sizeof( V_262 ) ) / V_270 ;
if ( F_120 ( V_75 -> V_91 ) ) {
V_67 -> V_273 = V_274 ;
V_67 -> V_275 = F_164 ( V_67 ) ;
V_67 -> V_276 = V_67 -> V_241 ;
V_262 = 0 ;
} else {
V_67 -> V_273 = V_277 ;
V_262 = F_165 ( V_153 ) ;
}
if ( F_166 ( V_67 ) ) {
T_7 * V_278 ;
if ( F_153 ( V_67 , V_260 ) ) {
F_131 ( V_67 ) ;
return - V_54 ;
}
V_278 = & F_167 ( V_67 ) -> V_279 [ F_167 ( V_67 ) -> V_280 - 1 ] ;
V_263 = F_168 ( F_169 ( V_278 ) )
+ V_278 -> V_281 ;
} else {
V_263 = (struct V_111 * ) F_170 ( V_67 , V_260 ) ;
}
memset ( V_263 , 0 , sizeof( * V_263 ) ) ;
V_263 -> V_282 = V_268 ;
V_263 -> V_283 = F_171 ( ~ V_262 ) ;
if ( F_166 ( V_67 ) ) {
F_172 ( V_263 ) ;
V_263 = NULL ;
}
F_173 ( V_67 , V_266 + V_265 ) ;
F_174 ( V_67 ) ;
F_175 ( V_67 ) ;
V_67 -> V_284 = V_266 ;
V_67 -> V_285 = F_13 ( V_38 ) ;
V_67 -> V_286 = V_2 -> V_286 ;
if ( V_2 -> V_4 -> V_16 & V_21 &&
V_2 -> V_22 -> V_97 & V_287 ) {
V_67 -> V_39 = V_2 -> V_22 ;
V_67 = F_176 ( V_67 , F_13 ( V_288 ) ,
F_177 ( V_2 -> V_4 ) ) ;
if ( ! V_67 )
return - V_54 ;
} else
V_67 -> V_39 = V_2 -> V_4 ;
V_239 = F_142 ( V_67 ) ;
V_239 -> V_289 = F_13 ( V_38 ) ;
memcpy ( V_239 -> V_249 , V_47 -> V_246 , V_11 ) ;
if ( V_47 -> V_290 )
memcpy ( V_239 -> V_249 + 3 , V_155 -> V_250 , 3 ) ;
if ( F_139 ( V_47 -> V_291 != V_163 ) )
memcpy ( V_239 -> V_245 , V_47 -> V_25 , V_11 ) ;
else
memcpy ( V_239 -> V_245 , V_72 -> V_78 , V_11 ) ;
V_269 = (struct V_110 * ) ( V_239 + 1 ) ;
memset ( V_269 , 0 , sizeof( * V_269 ) ) ;
if ( V_292 )
F_178 ( V_269 , V_292 ) ;
V_269 -> V_293 = V_267 ;
if ( V_75 -> V_92 && F_179 ( V_153 ) ) {
F_167 ( V_67 ) -> V_294 = V_295 ;
F_167 ( V_67 ) -> V_296 = F_179 ( V_153 ) ;
} else {
F_167 ( V_67 ) -> V_294 = 0 ;
F_167 ( V_67 ) -> V_296 = 0 ;
}
V_258 = F_152 ( V_75 -> V_258 , F_128 () ) ;
V_258 -> V_297 ++ ;
V_258 -> V_298 += V_261 ;
F_132 () ;
V_251 ( V_153 ) = V_75 ;
F_38 ( V_72 , V_67 ) ;
return 0 ;
}
static void F_180 ( struct V_66 * V_67 )
{
F_181 ( & V_299 ) ;
}
static inline int F_182 ( struct V_76 * V_75 ,
struct V_152 * V_153 )
{
struct V_5 * V_47 ;
struct V_1 * V_2 ;
struct V_154 * V_155 ;
struct V_66 * V_67 = (struct V_66 * ) V_153 ;
struct V_264 * V_258 ;
if ( V_75 -> V_91 && V_67 -> V_273 == V_274 )
F_183 ( V_153 ) &= ~ V_300 ;
else
F_183 ( V_153 ) |= V_300 ;
V_155 = (struct V_154 * ) F_147 ( V_67 ) ;
V_155 = F_77 ( V_153 ) ;
if ( V_155 -> V_160 == V_301 && V_155 -> V_271 == V_302 )
return 0 ;
V_2 = ( (struct V_71 * ) F_42 ( V_75 ) ) -> V_77 ;
V_47 = F_2 ( V_2 ) ;
if ( F_143 ( V_47 ) && F_184 ( V_153 ) == V_303 &&
F_148 ( V_155 -> V_304 ) == V_305 ) {
F_18 ( L_50 ) ;
return - V_112 ;
}
if ( ! ( F_183 ( V_153 ) & V_300 ) ||
F_185 ( F_186 ( V_153 ) ) == ~ F_187 ( ~ 0 , V_67 -> V_243 , V_67 -> V_241 ) ) {
F_183 ( V_153 ) &= ~ V_300 ;
return 0 ;
}
V_258 = F_152 ( V_75 -> V_258 , F_128 () ) ;
V_258 -> V_306 ++ ;
if ( V_258 -> V_306 < 5 )
F_66 ( V_307 L_51 ) ;
F_132 () ;
return - V_112 ;
}
static void F_188 ( struct V_66 * V_67 )
{
T_2 F_159 ;
struct V_76 * V_75 ;
struct V_235 * V_236 ;
struct V_264 * V_258 ;
struct V_111 V_217 ;
struct V_152 * V_153 ;
struct V_71 * V_72 ;
struct V_110 * V_269 ;
V_236 = F_149 ( V_67 ) ;
V_75 = V_236 -> V_251 ;
if ( F_139 ( ! V_75 ) ) {
if ( V_67 -> V_308 != F_180 )
F_3 ( V_67 -> V_39 , L_52 ) ;
F_131 ( V_67 ) ;
return;
}
F_3 ( V_67 -> V_39 , L_53
L_54 ,
V_67 -> V_241 , V_67 -> V_158 ,
V_67 -> V_242 , V_67 -> V_243 , F_140 ( V_67 ) ,
F_141 ( V_67 ) , V_67 -> V_244 ,
V_67 -> V_39 ? V_67 -> V_39 -> V_135 : L_44 ) ;
V_72 = F_42 ( V_75 ) ;
F_189 ( V_67 ) ;
V_269 = (struct V_110 * ) F_190 ( V_67 ) ;
V_258 = F_152 ( V_75 -> V_258 , F_128 () ) ;
if ( F_139 ( F_191 ( V_269 ) != V_292 ) ) {
if ( V_258 -> V_259 < 5 )
F_66 ( V_307 L_55
L_56
L_57
L_58
L_59 , F_191 ( V_269 ) ,
V_292 ) ;
goto V_309;
}
F_192 ( V_67 , sizeof( struct V_110 ) ) ;
F_159 = V_67 -> V_241 - sizeof( struct V_111 ) ;
V_258 -> V_310 ++ ;
V_258 -> V_311 += F_159 / V_270 ;
V_153 = (struct V_152 * ) V_67 ;
F_193 ( V_153 ) ;
V_251 ( V_153 ) = V_75 ;
F_162 ( V_153 ) = V_269 -> V_293 ;
if ( F_194 ( V_67 , F_159 , & V_217 , sizeof( V_217 ) ) )
goto V_309;
F_163 ( V_153 ) = V_217 . V_282 ;
F_186 ( V_153 ) = V_217 . V_283 ;
if ( F_195 ( V_67 , F_159 ) )
goto V_309;
if ( ! F_182 ( V_75 , V_153 ) ) {
F_132 () ;
F_196 ( V_75 , V_153 ) ;
return;
}
V_309:
V_258 -> V_259 ++ ;
F_132 () ;
F_131 ( V_67 ) ;
}
static int V_213 ( void * V_312 )
{
struct V_208 * V_209 = V_312 ;
struct V_66 * V_67 ;
struct V_313 V_314 ;
F_52 ( & V_314 ) ;
F_197 ( V_315 , - 20 ) ;
V_316:
while ( ! F_198 () ) {
F_124 ( & V_209 -> V_214 . V_215 ) ;
F_199 ( & V_209 -> V_214 , & V_314 ) ;
if ( ! F_200 ( & V_314 ) ) {
F_201 ( V_257 ) ;
F_125 ( & V_209 -> V_214 . V_215 ) ;
F_202 () ;
F_201 ( V_317 ) ;
goto V_316;
}
F_125 ( & V_209 -> V_214 . V_215 ) ;
while ( ( V_67 = F_129 ( & V_314 ) ) != NULL )
F_188 ( V_67 ) ;
}
return 0 ;
}
static void F_203 ( void )
{
F_204 ( & V_318 ) ;
F_205 ( & V_319 ) ;
}
static void F_206 ( void )
{
F_207 ( & V_318 ) ;
F_208 ( & V_319 ) ;
}
static struct V_1 *
F_209 ( struct V_3 * V_4 )
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
static int F_210 ( struct V_222 * V_320 ,
T_8 V_321 , void * V_322 )
{
struct V_323 * V_324 = V_322 ;
struct V_5 * V_47 ;
struct V_1 * V_2 ;
struct V_3 * V_4 ;
int V_325 ;
if ( V_324 -> V_326 . V_327 != V_328 )
return V_230 ;
V_4 = F_211 ( & V_329 , V_324 -> V_330 ) ;
if ( ! V_4 )
return V_230 ;
V_2 = F_209 ( V_4 ) ;
F_25 ( V_4 ) ;
if ( ! V_2 )
return V_230 ;
V_47 = F_2 ( V_2 ) ;
if ( V_324 -> V_331 & V_332 )
V_325 = F_212 ( V_324 -> V_326 . V_286 ) - 1 ;
else
V_325 = V_324 -> V_326 . V_286 ;
if ( V_325 < 0 )
return V_230 ;
if ( V_324 -> V_326 . V_285 == V_42 ||
V_324 -> V_326 . V_285 == V_38 )
V_47 -> V_286 = V_325 ;
if ( V_324 -> V_326 . V_285 == V_38 )
V_2 -> V_286 = V_325 ;
return V_230 ;
}
static int F_213 ( struct V_222 * V_320 ,
T_8 V_321 , void * V_322 )
{
struct V_45 * V_333 ;
struct V_76 * V_75 = NULL ;
struct V_3 * V_4 = F_214 ( V_322 ) ;
struct V_5 * V_47 ;
struct V_1 * V_2 ;
struct V_71 * V_72 ;
struct V_264 * V_258 ;
T_2 V_334 = 1 ;
T_2 V_104 ;
int V_120 = V_230 ;
F_84 (fcoe, &fcoe_hostlist, list) {
if ( V_2 -> V_4 == V_4 ) {
V_47 = F_2 ( V_2 ) ;
V_75 = V_47 -> V_64 ;
break;
}
}
if ( ! V_75 ) {
V_120 = V_335 ;
goto V_52;
}
switch ( V_321 ) {
case V_336 :
case V_337 :
V_334 = 0 ;
break;
case V_338 :
case V_339 :
break;
case V_340 :
if ( V_4 -> V_97 & V_108 )
break;
V_104 = V_4 -> V_107 - ( sizeof( struct V_110 ) +
sizeof( struct V_111 ) ) ;
if ( V_104 >= V_341 )
F_51 ( V_75 , V_104 ) ;
break;
case V_342 :
break;
case V_343 :
F_215 ( & V_2 -> V_344 ) ;
V_72 = F_42 ( V_47 -> V_64 ) ;
F_216 ( V_345 , & V_72 -> V_197 ) ;
goto V_52;
break;
case V_346 :
F_47 ( V_75 , V_4 ) ;
break;
default:
F_3 ( V_4 , L_60
L_61 , V_321 ) ;
}
F_54 ( V_75 ) ;
V_333 = F_217 ( V_47 ) ;
if ( V_334 && ! F_218 ( V_75 ) ) {
switch ( V_333 -> V_347 ) {
case V_348 :
F_219 ( L_62 ) ;
break;
case V_349 :
case V_350 :
F_220 ( V_47 ) ;
} ;
} else if ( F_221 ( V_47 ) ) {
switch ( V_333 -> V_347 ) {
case V_348 :
F_219 ( L_63 ) ;
break;
case V_349 :
case V_350 :
V_258 = F_152 ( V_75 -> V_258 , F_128 () ) ;
V_258 -> V_351 ++ ;
F_132 () ;
F_91 ( V_75 ) ;
} ;
}
V_52:
return V_120 ;
}
static int F_222 ( struct V_3 * V_4 )
{
struct V_5 * V_47 ;
struct V_1 * V_2 ;
int V_120 = 0 ;
F_48 ( & V_352 ) ;
F_33 () ;
V_2 = F_223 ( V_4 ) ;
F_34 () ;
if ( V_2 ) {
V_47 = F_2 ( V_2 ) ;
F_221 ( V_47 ) ;
F_91 ( V_47 -> V_64 ) ;
} else
V_120 = - V_206 ;
F_49 ( & V_352 ) ;
return V_120 ;
}
static int F_224 ( struct V_3 * V_4 )
{
struct V_5 * V_47 ;
struct V_1 * V_2 ;
int V_120 = 0 ;
F_48 ( & V_352 ) ;
F_33 () ;
V_2 = F_223 ( V_4 ) ;
F_34 () ;
if ( ! V_2 ) {
V_120 = - V_206 ;
goto V_52;
}
V_47 = F_2 ( V_2 ) ;
if ( ! F_218 ( V_47 -> V_64 ) )
F_220 ( V_47 ) ;
V_52:
F_49 ( & V_352 ) ;
return V_120 ;
}
static int F_225 ( struct V_45 * V_333 )
{
struct V_5 * V_47 = F_19 ( V_333 ) ;
struct V_76 * V_75 = V_47 -> V_64 ;
struct V_3 * V_4 = F_61 ( V_75 ) ;
switch ( V_333 -> V_347 ) {
case V_349 :
return F_224 ( V_4 ) ;
case V_348 :
return F_222 ( V_4 ) ;
case V_350 :
default:
return - V_353 ;
} ;
}
static int F_226 ( struct V_3 * V_4 )
{
struct V_5 * V_47 ;
struct V_1 * V_2 ;
struct V_76 * V_75 ;
struct V_71 * V_72 ;
int V_120 = 0 ;
F_48 ( & V_352 ) ;
F_33 () ;
V_2 = F_223 ( V_4 ) ;
if ( ! V_2 ) {
V_120 = - V_206 ;
goto V_354;
}
V_47 = F_2 ( V_2 ) ;
V_75 = V_47 -> V_64 ;
V_72 = F_42 ( V_75 ) ;
F_215 ( & V_2 -> V_344 ) ;
F_216 ( V_345 , & V_72 -> V_197 ) ;
V_354:
F_34 () ;
F_49 ( & V_352 ) ;
return V_120 ;
}
static void V_198 ( struct V_355 * V_356 )
{
struct V_45 * V_333 ;
struct V_5 * V_47 ;
struct V_71 * V_72 ;
struct V_1 * V_2 ;
struct V_188 * V_189 ;
struct V_357 * V_358 ;
unsigned long V_18 ;
struct V_190 * V_116 ;
struct V_190 * V_359 ;
V_72 = F_36 ( V_356 , struct V_71 , V_197 ) ;
V_189 = V_72 -> V_75 -> V_65 ;
V_358 = F_227 ( V_189 ) ;
F_228 ( V_189 -> V_360 , V_18 ) ;
F_229 (vport, next_vport, &fc_host->vports, peers) {
if ( V_116 -> V_18 & ( V_361 | V_362 ) ) {
continue;
} else {
V_116 -> V_18 |= V_363 ;
F_216 ( F_230 ( V_189 ) ,
& V_116 -> V_364 ) ;
}
}
F_231 ( V_189 -> V_360 , V_18 ) ;
F_232 ( F_230 ( V_189 ) ) ;
F_48 ( & V_352 ) ;
V_2 = V_72 -> V_77 ;
V_47 = F_2 ( V_2 ) ;
V_333 = F_217 ( V_47 ) ;
F_87 ( V_72 -> V_75 ) ;
F_32 ( V_2 ) ;
F_49 ( & V_352 ) ;
F_24 ( V_333 ) ;
}
static bool F_233 ( struct V_3 * V_4 )
{
return true ;
}
static void F_234 ( struct V_1 * V_2 )
{
#ifdef F_235
int V_331 ;
T_1 V_365 , V_366 ;
struct V_3 * V_4 = V_2 -> V_22 ;
struct V_5 * V_47 = F_2 ( V_2 ) ;
struct V_367 V_326 = {
. V_286 = 0 ,
. V_285 = V_38
} ;
if ( V_4 && V_4 -> V_368 && V_4 -> V_368 -> V_369 ) {
V_331 = V_4 -> V_368 -> V_369 ( V_4 ) ;
if ( V_331 & V_370 ) {
V_326 . V_327 = V_371 ;
V_366 = F_236 ( V_4 , & V_326 ) ;
V_326 . V_285 = V_42 ;
V_365 = F_236 ( V_4 , & V_326 ) ;
} else {
V_326 . V_327 = V_328 ;
V_366 = F_237 ( V_4 , & V_326 ) ;
V_326 . V_285 = V_42 ;
V_365 = F_237 ( V_4 , & V_326 ) ;
}
V_2 -> V_286 = F_212 ( V_366 ) ? F_212 ( V_366 ) - 1 : 0 ;
V_47 -> V_286 = F_212 ( V_365 ) ? F_212 ( V_365 ) - 1 : V_2 -> V_286 ;
}
#endif
}
static int F_238 ( struct V_3 * V_4 , enum V_43 V_44 ,
enum V_372 V_373 )
{
int V_120 = 0 ;
struct V_45 * V_46 ;
struct V_5 * V_47 ;
struct V_1 * V_2 ;
struct V_76 * V_75 ;
F_48 ( & V_352 ) ;
F_33 () ;
if ( F_239 ( V_4 ) ) {
V_120 = - V_374 ;
goto V_354;
}
V_2 = F_14 ( V_4 , V_44 ) ;
if ( F_121 ( V_2 ) ) {
V_120 = F_240 ( V_2 ) ;
goto V_354;
}
V_47 = F_2 ( V_2 ) ;
V_46 = F_217 ( V_47 ) ;
V_75 = F_101 ( V_2 , & V_46 -> V_39 , 0 ) ;
if ( F_121 ( V_75 ) ) {
F_66 ( V_176 L_64 ,
V_4 -> V_135 ) ;
V_120 = - V_375 ;
F_34 () ;
F_32 ( V_2 ) ;
F_49 ( & V_352 ) ;
F_24 ( V_46 ) ;
goto V_52;
}
V_47 -> V_64 = V_75 ;
F_234 ( V_2 ) ;
V_75 -> V_376 = V_377 ;
F_241 ( V_75 ) ;
if ( V_373 == V_378 )
V_46 -> V_347 = V_349 ;
else
V_46 -> V_347 = V_348 ;
if ( V_373 == V_378 &&
! F_218 ( V_75 ) ) {
F_34 () ;
F_220 ( V_47 ) ;
F_49 ( & V_352 ) ;
return V_120 ;
}
V_354:
F_34 () ;
F_49 ( & V_352 ) ;
V_52:
return V_120 ;
}
static int F_242 ( struct V_3 * V_4 , enum V_43 V_44 )
{
return F_238 ( V_4 , V_44 , V_378 ) ;
}
static int F_243 ( struct V_3 * V_4 )
{
return F_238 ( V_4 , V_379 ,
V_380 ) ;
}
static int F_218 ( struct V_76 * V_75 )
{
struct V_3 * V_4 = F_61 ( V_75 ) ;
if ( F_244 ( V_4 ) )
return 0 ;
return - 1 ;
}
static void F_92 ( struct V_76 * V_75 )
{
struct V_208 * V_381 ;
struct V_66 * V_67 ;
unsigned int V_207 ;
F_245 (cpu) {
V_381 = & F_117 ( V_212 , V_207 ) ;
if ( ! V_381 -> V_211 || ! F_246 ( V_207 ) )
continue;
V_67 = F_247 ( 0 ) ;
if ( ! V_67 )
continue;
V_67 -> V_308 = F_180 ;
F_124 ( & V_381 -> V_214 . V_215 ) ;
F_130 ( & V_381 -> V_214 , V_67 ) ;
if ( V_381 -> V_214 . V_74 == 1 )
F_123 ( V_381 -> V_211 ) ;
F_125 ( & V_381 -> V_214 . V_215 ) ;
F_248 ( & V_299 ) ;
}
}
static int F_249 ( struct V_188 * V_189 )
{
struct V_76 * V_75 = F_109 ( V_189 ) ;
struct V_71 * V_72 = F_42 ( V_75 ) ;
struct V_1 * V_2 = V_72 -> V_77 ;
struct V_5 * V_47 = F_2 ( V_2 ) ;
struct V_45 * V_333 = F_217 ( V_47 ) ;
F_221 ( V_47 ) ;
F_91 ( V_47 -> V_64 ) ;
if ( V_333 -> V_347 != V_348 &&
! F_218 ( V_47 -> V_64 ) )
F_220 ( V_47 ) ;
return 0 ;
}
static struct V_1 *
F_223 ( const struct V_3 * V_4 )
{
struct V_1 * V_2 ;
F_84 (fcoe, &fcoe_hostlist, list) {
if ( V_2 -> V_4 == V_4 )
return V_2 ;
}
return NULL ;
}
static struct V_76 * F_239 ( const struct V_3 * V_4 )
{
struct V_5 * V_47 ;
struct V_1 * V_2 ;
V_2 = F_223 ( V_4 ) ;
V_47 = F_2 ( V_2 ) ;
return ( V_2 ) ? V_47 -> V_64 : NULL ;
}
static int F_106 ( const struct V_76 * V_75 )
{
struct V_1 * V_2 ;
struct V_71 * V_72 ;
V_2 = F_223 ( F_61 ( V_75 ) ) ;
if ( ! V_2 ) {
V_72 = F_42 ( V_75 ) ;
V_2 = V_72 -> V_77 ;
F_250 ( & V_2 -> V_344 , & V_382 ) ;
}
return 0 ;
}
static void F_111 ( const struct V_76 * V_75 )
{
struct V_1 * V_2 ;
struct V_71 * V_72 ;
V_72 = F_42 ( V_75 ) ;
V_2 = V_72 -> V_77 ;
F_215 ( & V_2 -> V_344 ) ;
return;
}
static int T_5 F_251 ( void )
{
struct V_208 * V_209 ;
unsigned int V_207 ;
int V_120 = 0 ;
V_345 = F_252 ( L_65 , 0 , 0 ) ;
if ( ! V_345 )
return - V_54 ;
V_120 = F_253 ( & V_383 ) ;
if ( V_120 ) {
F_66 ( V_176 L_66
L_67 ) ;
return V_120 ;
}
F_48 ( & V_352 ) ;
F_245 (cpu) {
V_209 = & F_117 ( V_212 , V_207 ) ;
F_52 ( & V_209 -> V_214 ) ;
}
F_254 (cpu)
F_116 ( V_207 ) ;
V_120 = F_255 ( & V_384 ) ;
if ( V_120 )
goto V_385;
F_203 () ;
V_120 = F_112 () ;
if ( V_120 )
goto V_385;
F_49 ( & V_352 ) ;
return 0 ;
V_385:
F_254 (cpu) {
F_126 ( V_207 ) ;
}
F_49 ( & V_352 ) ;
F_256 ( V_345 ) ;
return V_120 ;
}
static void T_6 F_257 ( void )
{
struct V_1 * V_2 , * V_314 ;
struct V_5 * V_47 ;
struct V_71 * V_72 ;
unsigned int V_207 ;
F_48 ( & V_352 ) ;
F_206 () ;
F_33 () ;
F_229 (fcoe, tmp, &fcoe_hostlist, list) {
V_47 = F_2 ( V_2 ) ;
V_72 = F_42 ( V_47 -> V_64 ) ;
F_111 ( V_72 -> V_75 ) ;
F_216 ( V_345 , & V_72 -> V_197 ) ;
}
F_34 () ;
F_258 ( & V_384 ) ;
F_254 (cpu)
F_126 ( V_207 ) ;
F_49 ( & V_352 ) ;
F_256 ( V_345 ) ;
F_114 () ;
F_259 ( & V_383 ) ;
}
static void F_260 ( struct V_386 * V_387 , struct V_152 * V_153 , void * V_312 )
{
struct V_5 * V_6 = V_312 ;
struct V_388 * V_389 = F_261 ( V_387 ) ;
struct V_76 * V_75 = V_389 -> V_64 ;
T_1 * V_390 ;
if ( F_121 ( V_153 ) )
goto V_391;
V_390 = F_262 ( V_153 ) -> V_392 ;
if ( F_43 ( V_390 ) )
F_263 ( V_6 , V_75 , V_153 ) ;
if ( ! F_43 ( V_390 ) )
V_59 ( V_75 , V_390 ) ;
V_391:
F_264 ( V_387 , V_153 , V_75 ) ;
}
static void F_265 ( struct V_386 * V_387 , struct V_152 * V_153 , void * V_312 )
{
struct V_76 * V_75 = V_312 ;
static T_1 V_393 [ V_11 ] = { 0 } ;
if ( ! F_121 ( V_153 ) )
V_59 ( V_75 , V_393 ) ;
F_266 ( V_387 , V_153 , V_75 ) ;
}
static struct V_386 * F_267 ( struct V_76 * V_75 , T_2 V_394 ,
struct V_152 * V_153 , unsigned int V_395 ,
void (* F_268)( struct V_386 * ,
struct V_152 * ,
void * ) ,
void * V_312 , T_2 V_396 )
{
struct V_71 * V_72 = F_42 ( V_75 ) ;
struct V_1 * V_2 = V_72 -> V_77 ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_154 * V_155 = F_77 ( V_153 ) ;
switch ( V_395 ) {
case V_397 :
case V_398 :
if ( V_75 -> V_399 )
break;
return F_269 ( V_75 , V_394 , V_153 , V_395 , F_260 ,
V_6 , V_396 ) ;
case V_303 :
if ( F_148 ( V_155 -> V_250 ) != V_305 )
break;
return F_269 ( V_75 , V_394 , V_153 , V_395 , F_265 ,
V_75 , V_396 ) ;
}
return F_269 ( V_75 , V_394 , V_153 , V_395 , F_268 , V_312 , V_396 ) ;
}
static int F_270 ( struct V_190 * V_116 , bool V_400 )
{
struct V_188 * V_189 = F_108 ( V_116 ) ;
struct V_76 * V_187 = F_109 ( V_189 ) ;
struct V_71 * V_72 = F_42 ( V_187 ) ;
struct V_1 * V_2 = V_72 -> V_77 ;
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_76 * V_401 ;
int V_120 ;
char V_402 [ 32 ] ;
V_120 = F_271 ( V_116 ) ;
if ( V_120 ) {
F_272 ( V_116 -> V_201 , V_402 , sizeof( V_402 ) ) ;
F_66 ( V_176 L_68
L_69 ,
V_402 ) ;
return V_120 ;
}
F_48 ( & V_352 ) ;
F_33 () ;
V_401 = F_101 ( V_2 , & V_116 -> V_39 , 1 ) ;
F_34 () ;
F_49 ( & V_352 ) ;
if ( F_121 ( V_401 ) ) {
F_66 ( V_176 L_70 ,
V_4 -> V_135 ) ;
return - V_375 ;
}
if ( V_400 ) {
F_273 ( V_116 , V_403 ) ;
} else {
V_401 -> V_376 = V_377 ;
F_241 ( V_401 ) ;
F_274 ( V_401 ) ;
}
return 0 ;
}
static int F_275 ( struct V_190 * V_116 )
{
struct V_188 * V_189 = F_108 ( V_116 ) ;
struct V_76 * V_187 = F_109 ( V_189 ) ;
struct V_76 * V_401 = V_116 -> V_404 ;
F_48 ( & V_187 -> V_96 ) ;
F_215 ( & V_401 -> V_344 ) ;
F_49 ( & V_187 -> V_96 ) ;
F_48 ( & V_352 ) ;
F_87 ( V_401 ) ;
F_49 ( & V_352 ) ;
return 0 ;
}
static int F_276 ( struct V_190 * V_116 , bool V_405 )
{
struct V_76 * V_75 = V_116 -> V_404 ;
if ( V_405 ) {
F_273 ( V_116 , V_403 ) ;
F_88 ( V_75 ) ;
} else {
V_75 -> V_376 = V_377 ;
F_241 ( V_75 ) ;
F_274 ( V_75 ) ;
}
return 0 ;
}
static void F_277 ( struct V_190 * V_116 )
{
struct V_76 * V_75 = V_116 -> V_404 ;
struct V_152 * V_153 ;
T_9 V_241 ;
snprintf ( F_63 ( V_75 -> V_65 ) , V_132 ,
L_71 , V_133 , V_134 ,
F_61 ( V_75 ) -> V_135 , V_116 -> V_406 ) ;
if ( V_75 -> V_256 != V_407 )
return;
V_241 = F_278 ( F_63 ( V_75 -> V_65 ) , 255 ) ;
V_153 = F_279 ( V_75 ,
sizeof( struct V_408 ) +
sizeof( struct V_409 ) + V_241 ) ;
if ( ! V_153 )
return;
V_75 -> V_410 . V_411 ( V_75 , V_412 , V_153 , V_413 ,
NULL , NULL , 3 * V_75 -> V_84 ) ;
}
static void F_280 ( struct V_414 * V_415 )
{
struct V_45 * V_46 =
F_281 ( V_415 ) ;
struct V_5 * V_47 = F_19 ( V_46 ) ;
struct V_1 * V_2 = F_20 ( V_47 ) ;
V_415 -> V_416 = F_177 ( V_2 -> V_4 ) ;
}
static void F_282 ( struct V_76 * V_75 ,
T_2 V_417 , struct V_152 * V_153 )
{
struct V_71 * V_72 = F_42 ( V_75 ) ;
struct V_1 * V_2 = V_72 -> V_77 ;
struct V_5 * V_47 = F_2 ( V_2 ) ;
if ( V_153 && F_184 ( V_153 ) == V_397 )
F_263 ( V_47 , V_75 , V_153 ) ;
}
