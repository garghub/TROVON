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
struct V_45 * V_46 = F_33 ( V_6 ) ;
F_34 () ;
if ( ! V_2 -> V_63 )
F_27 ( V_2 ) ;
F_35 () ;
F_23 ( V_6 ) ;
F_36 ( V_6 -> V_64 -> V_65 ) ;
F_24 ( V_46 ) ;
F_25 ( V_4 ) ;
F_26 ( V_50 ) ;
}
static int V_41 ( struct V_66 * V_67 , struct V_3 * V_4 ,
struct V_68 * V_69 ,
struct V_3 * V_70 )
{
struct V_1 * V_2 ;
struct V_5 * V_47 ;
V_2 = F_37 ( V_69 , struct V_1 , V_40 ) ;
V_47 = F_2 ( V_2 ) ;
F_38 ( V_47 , V_67 ) ;
return 0 ;
}
static void F_39 ( struct V_71 * V_72 , struct V_66 * V_67 )
{
if ( V_72 -> V_73 . V_74 )
F_40 ( V_72 -> V_75 , V_67 ) ;
else if ( F_41 ( V_67 ) )
F_40 ( V_72 -> V_75 , V_67 ) ;
}
static void V_57 ( struct V_5 * V_6 , struct V_66 * V_67 )
{
V_67 -> V_39 = F_42 ( V_6 ) -> V_4 ;
F_39 ( F_43 ( V_6 -> V_64 ) , V_67 ) ;
}
static void V_59 ( struct V_76 * V_75 , T_1 * V_24 )
{
struct V_71 * V_72 = F_43 ( V_75 ) ;
struct V_1 * V_2 = V_72 -> V_77 ;
if ( ! F_44 ( V_72 -> V_78 ) )
F_30 ( V_2 -> V_4 , V_72 -> V_78 ) ;
if ( ! F_44 ( V_24 ) )
F_9 ( V_2 -> V_4 , V_24 ) ;
memcpy ( V_72 -> V_78 , V_24 , V_11 ) ;
}
static T_1 * V_61 ( struct V_76 * V_75 )
{
struct V_71 * V_72 = F_43 ( V_75 ) ;
return V_72 -> V_78 ;
}
static int F_45 ( struct V_76 * V_75 )
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
F_46 ( V_75 ) ;
F_47 ( V_75 ) ;
V_75 -> V_91 = 0 ;
V_75 -> V_92 = 0 ;
V_75 -> V_93 = 0 ;
V_75 -> V_94 = 0 ;
V_75 -> V_95 = 0 ;
return 0 ;
}
static void F_48 ( struct V_76 * V_75 ,
struct V_3 * V_4 )
{
F_49 ( & V_75 -> V_96 ) ;
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
F_50 ( & V_75 -> V_96 ) ;
}
static int F_51 ( struct V_76 * V_75 , struct V_3 * V_4 )
{
T_2 V_104 ;
T_3 V_105 , V_106 ;
struct V_1 * V_2 ;
struct V_5 * V_47 ;
struct V_71 * V_72 ;
V_72 = F_43 ( V_75 ) ;
V_2 = V_72 -> V_77 ;
V_47 = F_2 ( V_2 ) ;
V_104 = V_4 -> V_107 ;
if ( V_4 -> V_97 & V_108 ) {
V_104 = V_109 ;
F_3 ( V_4 , L_10 , V_104 ) ;
}
V_104 -= ( sizeof( struct V_110 ) + sizeof( struct V_111 ) ) ;
if ( F_52 ( V_75 , V_104 ) )
return - V_112 ;
F_48 ( V_75 , V_4 ) ;
F_53 ( & V_72 -> V_73 ) ;
V_72 -> V_113 = 0 ;
F_54 ( & V_72 -> V_114 , V_115 , ( unsigned long ) V_75 ) ;
F_55 ( V_75 ) ;
if ( ! V_75 -> V_116 ) {
if ( F_56 ( V_4 , & V_105 , V_117 ) )
V_105 = F_57 ( V_47 -> V_25 , 1 , 0 ) ;
F_58 ( V_75 , V_105 ) ;
if ( F_56 ( V_4 , & V_106 , V_118 ) )
V_106 = F_57 ( V_47 -> V_25 ,
2 , 0 ) ;
F_59 ( V_75 , V_106 ) ;
}
return 0 ;
}
static int F_60 ( struct V_76 * V_75 , struct V_119 * V_39 )
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
V_120 = F_61 ( V_75 -> V_65 , V_39 ) ;
if ( V_120 ) {
F_3 ( F_62 ( V_75 ) , L_11
L_12 ) ;
return V_120 ;
}
if ( ! V_75 -> V_116 )
F_63 ( V_75 -> V_65 ) = V_131 ;
snprintf ( F_64 ( V_75 -> V_65 ) , V_132 ,
L_13 , V_133 , V_134 ,
F_62 ( V_75 ) -> V_135 ) ;
return 0 ;
}
static void F_65 ( struct V_76 * V_75 , struct V_3 * V_4 )
{
struct V_1 * V_2 ;
struct V_71 * V_72 ;
struct V_3 * V_22 ;
int V_120 ;
struct V_136 V_137 ;
V_72 = F_43 ( V_75 ) ;
V_2 = V_72 -> V_77 ;
V_22 = V_2 -> V_22 ;
if ( ! V_22 )
return;
if ( V_75 -> V_116 )
return;
if ( V_22 -> V_14 -> V_138 ) {
memset ( & V_137 , 0 , sizeof( V_137 ) ) ;
V_120 = V_22 -> V_14 -> V_138 ( V_22 ,
& V_137 ) ;
if ( V_120 ) {
F_66 ( V_139 L_14
L_15 ) ;
return;
}
snprintf ( F_67 ( V_75 -> V_65 ) ,
V_140 ,
L_16 ,
V_137 . V_141 ) ;
snprintf ( F_68 ( V_75 -> V_65 ) ,
V_140 ,
L_16 ,
V_137 . V_142 ) ;
snprintf ( F_69 ( V_75 -> V_65 ) ,
V_132 ,
L_16 ,
V_137 . V_143 ) ;
snprintf ( F_70 ( V_75 -> V_65 ) ,
V_132 ,
L_16 ,
V_137 . V_144 ) ;
snprintf ( F_71 ( V_75 -> V_65 ) ,
V_145 ,
L_16 ,
V_137 . V_146 ) ;
snprintf ( F_72 ( V_75 -> V_65 ) ,
V_145 ,
L_16 ,
V_137 . V_147 ) ;
snprintf ( F_73 ( V_75 -> V_65 ) ,
V_145 ,
L_16 ,
V_137 . V_148 ) ;
snprintf ( F_74 ( V_75 -> V_65 ) ,
V_145 ,
L_16 ,
V_137 . V_149 ) ;
V_75 -> V_150 = 1 ;
} else {
V_75 -> V_150 = 0 ;
F_66 ( V_139 L_17 ) ;
}
}
static bool F_75 ( struct V_151 * V_152 )
{
struct V_153 * V_154 = F_76 ( V_152 ) ;
struct V_155 * V_156 ;
if ( F_77 ( F_78 ( V_152 ) ) &&
( F_78 ( V_152 ) -> V_157 > V_158 ) )
return true ;
else if ( ( F_78 ( V_152 ) == NULL ) &&
( V_154 -> V_159 == V_160 ) &&
( F_79 ( V_154 -> V_161 ) == V_162 ) ) {
V_156 = F_80 ( V_152 , sizeof( * V_156 ) ) ;
if ( ( V_156 -> V_163 & V_164 ) &&
( F_81 ( V_156 -> V_165 ) > V_158 ) )
return true ;
}
return false ;
}
static inline int F_82 ( struct V_76 * V_75 )
{
struct V_71 * V_72 = F_43 ( V_75 ) ;
struct V_1 * V_2 = V_72 -> V_77 ;
struct V_1 * V_166 = NULL ;
struct V_3 * V_167 , * V_168 ;
T_4 V_169 = V_170 ;
T_4 V_171 = V_172 ;
if ( ! V_75 -> V_93 || ! V_75 -> V_94 ||
( V_75 -> V_94 >= V_171 ) ) {
V_75 -> V_94 = 0 ;
goto V_173;
}
if ( V_2 -> V_4 -> V_16 & V_21 )
V_168 = F_4 ( V_2 -> V_4 ) ;
else
V_168 = V_2 -> V_4 ;
F_83 (oldfcoe, &fcoe_hostlist, list) {
if ( V_166 -> V_4 -> V_16 & V_21 )
V_167 = F_4 ( V_166 -> V_4 ) ;
else
V_167 = V_166 -> V_4 ;
if ( V_168 == V_167 ) {
V_2 -> V_174 = V_166 -> V_174 ;
break;
}
}
if ( V_2 -> V_174 ) {
if ( ! F_84 ( V_75 , V_2 -> V_174 , F_75 ) ) {
F_66 ( V_175 L_18
L_19 ,
V_2 -> V_174 , V_2 -> V_4 -> V_135 ) ;
return - V_54 ;
}
} else {
V_2 -> V_174 = F_85 ( V_75 , V_176 ,
V_170 , V_75 -> V_94 ,
F_75 ) ;
if ( ! V_2 -> V_174 ) {
F_66 ( V_175 L_20
L_21 ,
V_2 -> V_4 -> V_135 ) ;
return - V_54 ;
}
}
V_169 += V_75 -> V_94 + 1 ;
V_173:
if ( ! F_85 ( V_75 , V_176 , V_169 , V_171 , NULL ) ) {
F_66 ( V_175 L_22
L_23 , V_2 -> V_4 -> V_135 ) ;
return - V_54 ;
}
return 0 ;
}
static void F_86 ( struct V_76 * V_75 )
{
struct V_71 * V_72 = F_43 ( V_75 ) ;
struct V_1 * V_2 = V_72 -> V_77 ;
struct V_3 * V_4 = V_2 -> V_4 ;
F_3 ( V_4 , L_24 ) ;
F_87 ( V_75 ) ;
F_88 ( V_75 ) ;
F_89 ( & V_72 -> V_114 ) ;
F_90 ( V_75 ) ;
F_34 () ;
if ( ! F_44 ( V_72 -> V_78 ) )
F_30 ( V_4 , V_72 -> V_78 ) ;
if ( V_75 -> V_116 )
F_29 () ;
else
F_27 ( V_2 ) ;
F_35 () ;
F_91 ( V_75 ) ;
F_92 ( V_75 -> V_65 ) ;
F_93 ( V_75 -> V_65 ) ;
F_94 ( V_75 ) ;
F_95 ( V_75 ) ;
F_96 ( V_75 ) ;
if ( V_75 -> V_116 )
F_36 ( V_75 -> V_65 ) ;
}
static int F_97 ( struct V_76 * V_75 , T_4 V_177 ,
struct V_178 * V_179 , unsigned int V_180 )
{
struct V_3 * V_4 = F_62 ( V_75 ) ;
if ( V_4 -> V_14 -> V_181 )
return V_4 -> V_14 -> V_181 ( V_4 ,
V_177 , V_179 ,
V_180 ) ;
return 0 ;
}
static int F_98 ( struct V_76 * V_75 , T_4 V_177 ,
struct V_178 * V_179 , unsigned int V_180 )
{
struct V_3 * V_4 = F_62 ( V_75 ) ;
if ( V_4 -> V_14 -> V_182 )
return V_4 -> V_14 -> V_182 ( V_4 , V_177 ,
V_179 , V_180 ) ;
return 0 ;
}
static int F_99 ( struct V_76 * V_75 , T_4 V_177 )
{
struct V_3 * V_4 = F_62 ( V_75 ) ;
if ( V_4 -> V_14 -> V_183 )
return V_4 -> V_14 -> V_183 ( V_4 , V_177 ) ;
return 0 ;
}
static struct V_76 * F_100 ( struct V_1 * V_2 ,
struct V_119 * V_184 , int V_185 )
{
struct V_5 * V_47 = F_2 ( V_2 ) ;
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_76 * V_75 , * V_186 ;
struct V_71 * V_72 ;
struct V_187 * V_188 ;
int V_120 ;
struct V_189 * V_116 = F_101 ( V_184 ) ;
F_3 ( V_4 , L_25 ) ;
if ( ! V_185 )
V_75 = F_102 ( & V_190 , sizeof( * V_72 ) ) ;
else
V_75 = F_103 ( V_116 , sizeof( * V_72 ) ) ;
if ( ! V_75 ) {
F_3 ( V_4 , L_26 ) ;
V_120 = - V_54 ;
goto V_52;
}
V_72 = F_43 ( V_75 ) ;
V_72 -> V_75 = V_75 ;
V_72 -> V_77 = V_2 ;
V_72 -> V_191 = V_192 ;
V_72 -> V_193 = V_194 ;
F_104 ( & V_72 -> V_195 , V_196 ) ;
V_120 = F_45 ( V_75 ) ;
if ( V_120 ) {
F_3 ( V_4 , L_27
L_28 ) ;
goto V_197;
}
if ( V_185 ) {
F_3 ( V_4 , L_29
L_30 ,
V_116 -> V_198 , V_116 -> V_199 ) ;
F_58 ( V_75 , V_116 -> V_198 ) ;
F_59 ( V_75 , V_116 -> V_199 ) ;
}
V_120 = F_51 ( V_75 , V_4 ) ;
if ( V_120 ) {
F_3 ( V_4 , L_31
L_28 ) ;
goto V_200;
}
V_120 = F_60 ( V_75 , V_184 ) ;
if ( V_120 ) {
F_3 ( V_4 , L_32
L_28 ) ;
goto V_200;
}
V_120 = F_105 ( V_75 , V_47 , & V_201 , 1 ) ;
if ( V_120 ) {
F_3 ( V_4 , L_33
L_28 ) ;
goto V_200;
}
F_65 ( V_75 , V_4 ) ;
if ( ! V_185 )
V_120 = F_82 ( V_75 ) ;
else {
V_188 = F_106 ( V_116 ) ;
V_186 = F_107 ( V_188 ) ;
V_120 = F_108 ( V_186 , V_75 ) ;
}
if ( V_120 ) {
F_3 ( V_4 , L_34 ) ;
goto V_200;
}
return V_75 ;
V_200:
F_95 ( V_75 ) ;
V_197:
F_36 ( V_75 -> V_65 ) ;
V_52:
return F_16 ( V_120 ) ;
}
static int T_5 F_109 ( void )
{
V_130 =
F_110 ( & V_202 ) ;
V_129 =
F_110 ( & V_203 ) ;
if ( ! V_130 ) {
F_66 ( V_175 L_35 ) ;
return - V_204 ;
}
return 0 ;
}
static int T_6 F_111 ( void )
{
F_112 ( V_130 ) ;
F_112 ( V_129 ) ;
V_130 = NULL ;
V_129 = NULL ;
return 0 ;
}
static void F_113 ( unsigned int V_205 )
{
struct V_206 * V_207 ;
struct V_208 * V_209 ;
V_207 = & F_114 ( V_210 , V_205 ) ;
V_209 = F_115 ( V_211 ,
( void * ) V_207 , F_116 ( V_205 ) ,
L_36 , V_205 ) ;
if ( F_117 ( ! F_118 ( V_209 ) ) ) {
F_119 ( V_209 , V_205 ) ;
F_120 ( V_209 ) ;
F_121 ( & V_207 -> V_212 . V_213 ) ;
V_207 -> V_209 = V_209 ;
F_122 ( & V_207 -> V_212 . V_213 ) ;
}
}
static void F_123 ( unsigned int V_205 )
{
struct V_206 * V_207 ;
struct V_208 * V_209 ;
struct V_214 * V_215 ;
struct V_66 * V_67 ;
#ifdef F_124
struct V_206 * V_216 ;
unsigned V_217 = F_125 () ;
#endif
F_18 ( L_37 , V_205 ) ;
V_207 = & F_114 ( V_210 , V_205 ) ;
F_121 ( & V_207 -> V_212 . V_213 ) ;
V_209 = V_207 -> V_209 ;
V_207 -> V_209 = NULL ;
V_215 = V_207 -> V_218 ;
V_207 -> V_218 = NULL ;
V_207 -> V_219 = 0 ;
F_122 ( & V_207 -> V_212 . V_213 ) ;
#ifdef F_124
if ( V_205 != V_217 ) {
V_216 = & F_114 ( V_210 , V_217 ) ;
F_121 ( & V_216 -> V_212 . V_213 ) ;
if ( V_216 -> V_209 ) {
F_18 ( L_38 ,
V_205 , V_217 ) ;
while ( ( V_67 = F_126 ( & V_207 -> V_212 ) ) != NULL )
F_127 ( & V_216 -> V_212 , V_67 ) ;
F_122 ( & V_216 -> V_212 . V_213 ) ;
} else {
while ( ( V_67 = F_126 ( & V_207 -> V_212 ) ) != NULL )
F_128 ( V_67 ) ;
F_122 ( & V_216 -> V_212 . V_213 ) ;
}
} else {
F_121 ( & V_207 -> V_212 . V_213 ) ;
while ( ( V_67 = F_126 ( & V_207 -> V_212 ) ) != NULL )
F_128 ( V_67 ) ;
F_122 ( & V_207 -> V_212 . V_213 ) ;
}
F_129 () ;
#else
F_121 ( & V_207 -> V_212 . V_213 ) ;
while ( ( V_67 = F_126 ( & V_207 -> V_212 ) ) != NULL )
F_128 ( V_67 ) ;
F_122 ( & V_207 -> V_212 . V_213 ) ;
#endif
if ( V_209 )
F_130 ( V_209 ) ;
if ( V_215 )
F_131 ( V_215 ) ;
}
static int F_132 ( struct V_220 * V_221 ,
unsigned long V_222 , void * V_223 )
{
unsigned V_205 = ( unsigned long ) V_223 ;
switch ( V_222 ) {
case V_224 :
case V_225 :
F_18 ( L_39 , V_205 ) ;
F_113 ( V_205 ) ;
break;
case V_226 :
case V_227 :
F_18 ( L_40 , V_205 ) ;
F_123 ( V_205 ) ;
break;
default:
break;
}
return V_228 ;
}
static inline unsigned int F_133 ( void )
{
static unsigned int V_229 ;
V_229 = F_134 ( V_229 , V_230 ) ;
if ( V_229 >= V_231 )
V_229 = F_135 ( V_230 ) ;
return V_229 ;
}
static int V_37 ( struct V_66 * V_67 , struct V_3 * V_4 ,
struct V_68 * V_69 , struct V_3 * V_232 )
{
struct V_76 * V_75 ;
struct V_233 * V_234 ;
struct V_5 * V_47 ;
struct V_1 * V_2 ;
struct V_153 * V_154 ;
struct V_206 * V_235 ;
struct V_236 * V_237 ;
unsigned int V_205 ;
V_2 = F_37 ( V_69 , struct V_1 , V_35 ) ;
V_47 = F_2 ( V_2 ) ;
V_75 = V_47 -> V_64 ;
if ( F_136 ( ! V_75 ) ) {
F_3 ( V_4 , L_41 ) ;
goto V_238;
}
if ( ! V_75 -> V_79 )
goto V_238;
F_3 ( V_4 , L_42
L_43 ,
V_67 -> V_239 , V_67 -> V_157 , V_67 -> V_240 , V_67 -> V_241 ,
F_137 ( V_67 ) , F_138 ( V_67 ) ,
V_67 -> V_242 , V_67 -> V_39 ? V_67 -> V_39 -> V_135 : L_44 ) ;
V_237 = F_139 ( V_67 ) ;
if ( F_140 ( V_47 ) &&
F_141 ( V_237 -> V_243 , V_47 -> V_244 ) ) {
F_3 ( V_4 , L_45 ,
V_237 -> V_243 ) ;
goto V_49;
}
if ( F_136 ( ( V_67 -> V_239 < V_245 ) ||
! F_142 ( V_67 , V_246 ) ) )
goto V_49;
F_143 ( V_67 , sizeof( struct V_110 ) ) ;
V_154 = (struct V_153 * ) F_144 ( V_67 ) ;
if ( F_145 ( & V_237 -> V_247 [ 3 ] ) != F_145 ( V_154 -> V_248 ) ) {
F_3 ( V_4 , L_46 ,
V_237 -> V_247 ) ;
goto V_49;
}
V_234 = F_146 ( V_67 ) ;
V_234 -> V_249 = V_75 ;
if ( F_145 ( V_154 -> V_250 ) & V_251 )
V_205 = F_79 ( V_154 -> V_252 ) & V_253 ;
else {
if ( F_79 ( V_154 -> V_161 ) == V_162 )
V_205 = F_133 () ;
else
V_205 = F_79 ( V_154 -> V_161 ) & V_253 ;
}
if ( V_205 >= V_231 )
goto V_49;
V_235 = & F_114 ( V_210 , V_205 ) ;
F_147 ( & V_235 -> V_212 . V_213 ) ;
if ( F_136 ( ! V_235 -> V_209 ) ) {
F_3 ( V_4 , L_47
L_48
L_49 ) ;
F_148 ( & V_235 -> V_212 . V_213 ) ;
V_205 = F_135 ( V_230 ) ;
V_235 = & F_114 ( V_210 , V_205 ) ;
F_147 ( & V_235 -> V_212 . V_213 ) ;
if ( ! V_235 -> V_209 ) {
F_148 ( & V_235 -> V_212 . V_213 ) ;
goto V_49;
}
}
F_127 ( & V_235 -> V_212 , V_67 ) ;
if ( V_235 -> V_209 -> V_254 == V_255 )
F_120 ( V_235 -> V_209 ) ;
F_148 ( & V_235 -> V_212 . V_213 ) ;
return 0 ;
V_49:
F_149 ( V_75 -> V_256 , F_125 () ) -> V_257 ++ ;
F_129 () ;
V_238:
F_128 ( V_67 ) ;
return - 1 ;
}
static int F_150 ( struct V_66 * V_67 , int V_258 )
{
struct V_206 * V_235 ;
int V_120 ;
V_235 = & F_151 ( V_210 ) ;
V_120 = F_152 ( V_67 , V_258 , V_235 ) ;
F_153 ( V_210 ) ;
return V_120 ;
}
static int F_154 ( struct V_76 * V_75 , struct V_151 * V_152 )
{
int V_259 ;
T_2 V_260 ;
struct V_236 * V_237 ;
struct V_111 * V_261 ;
struct V_66 * V_67 ;
struct V_262 * V_256 ;
struct V_153 * V_154 ;
unsigned int V_263 ;
unsigned int V_258 ;
unsigned int V_264 ;
struct V_71 * V_72 = F_43 ( V_75 ) ;
struct V_1 * V_2 = V_72 -> V_77 ;
struct V_5 * V_47 = F_2 ( V_2 ) ;
T_1 V_265 , V_266 ;
struct V_110 * V_267 ;
F_155 ( ( F_156 ( V_152 ) % sizeof( T_2 ) ) != 0 ) ;
V_154 = F_76 ( V_152 ) ;
V_67 = F_157 ( V_152 ) ;
V_259 = V_67 -> V_239 / V_268 ;
if ( ! V_75 -> V_79 ) {
F_128 ( V_67 ) ;
return 0 ;
}
if ( F_136 ( V_154 -> V_269 == V_270 ) &&
F_158 ( V_47 , V_75 , V_67 ) )
return 0 ;
V_265 = F_159 ( V_152 ) ;
V_266 = F_160 ( V_152 ) ;
V_264 = sizeof( struct V_236 ) ;
V_263 = sizeof( struct V_110 ) ;
V_258 = sizeof( struct V_111 ) ;
V_259 = ( V_67 -> V_239 - V_258 + sizeof( V_260 ) ) / V_268 ;
if ( F_117 ( V_75 -> V_91 ) ) {
V_67 -> V_271 = V_272 ;
V_67 -> V_273 = F_161 ( V_67 ) ;
V_67 -> V_274 = V_67 -> V_239 ;
V_260 = 0 ;
} else {
V_67 -> V_271 = V_275 ;
V_260 = F_162 ( V_152 ) ;
}
if ( F_163 ( V_67 ) ) {
T_7 * V_276 ;
if ( F_150 ( V_67 , V_258 ) ) {
F_128 ( V_67 ) ;
return - V_54 ;
}
V_276 = & F_164 ( V_67 ) -> V_277 [ F_164 ( V_67 ) -> V_278 - 1 ] ;
V_261 = F_165 ( F_166 ( V_276 ) )
+ V_276 -> V_279 ;
} else {
V_261 = (struct V_111 * ) F_167 ( V_67 , V_258 ) ;
}
memset ( V_261 , 0 , sizeof( * V_261 ) ) ;
V_261 -> V_280 = V_266 ;
V_261 -> V_281 = F_168 ( ~ V_260 ) ;
if ( F_163 ( V_67 ) ) {
F_169 ( V_261 ) ;
V_261 = NULL ;
}
F_170 ( V_67 , V_264 + V_263 ) ;
F_171 ( V_67 ) ;
F_172 ( V_67 ) ;
V_67 -> V_282 = V_264 ;
V_67 -> V_283 = F_13 ( V_38 ) ;
V_67 -> V_284 = V_72 -> V_284 ;
if ( V_2 -> V_4 -> V_16 & V_21 &&
V_2 -> V_22 -> V_97 & V_285 ) {
V_67 -> V_286 = V_287 |
F_173 ( V_2 -> V_4 ) ;
V_67 -> V_39 = V_2 -> V_22 ;
} else
V_67 -> V_39 = V_2 -> V_4 ;
V_237 = F_139 ( V_67 ) ;
V_237 -> V_288 = F_13 ( V_38 ) ;
memcpy ( V_237 -> V_247 , V_47 -> V_244 , V_11 ) ;
if ( V_47 -> V_289 )
memcpy ( V_237 -> V_247 + 3 , V_154 -> V_248 , 3 ) ;
if ( F_136 ( V_47 -> V_290 != V_162 ) )
memcpy ( V_237 -> V_243 , V_47 -> V_25 , V_11 ) ;
else
memcpy ( V_237 -> V_243 , V_72 -> V_78 , V_11 ) ;
V_267 = (struct V_110 * ) ( V_237 + 1 ) ;
memset ( V_267 , 0 , sizeof( * V_267 ) ) ;
if ( V_291 )
F_174 ( V_267 , V_291 ) ;
V_267 -> V_292 = V_265 ;
if ( V_75 -> V_92 && F_175 ( V_152 ) ) {
F_164 ( V_67 ) -> V_293 = V_294 ;
F_164 ( V_67 ) -> V_295 = F_175 ( V_152 ) ;
} else {
F_164 ( V_67 ) -> V_293 = 0 ;
F_164 ( V_67 ) -> V_295 = 0 ;
}
V_256 = F_149 ( V_75 -> V_256 , F_125 () ) ;
V_256 -> V_296 ++ ;
V_256 -> V_297 += V_259 ;
F_129 () ;
V_249 ( V_152 ) = V_75 ;
F_39 ( V_72 , V_67 ) ;
return 0 ;
}
static void F_176 ( struct V_66 * V_67 )
{
F_177 ( & V_298 ) ;
}
static inline int F_178 ( struct V_76 * V_75 ,
struct V_151 * V_152 )
{
struct V_5 * V_47 ;
struct V_1 * V_2 ;
struct V_153 * V_154 ;
struct V_66 * V_67 = (struct V_66 * ) V_152 ;
struct V_262 * V_256 ;
if ( V_75 -> V_91 && V_67 -> V_271 == V_272 )
F_179 ( V_152 ) &= ~ V_299 ;
else
F_179 ( V_152 ) |= V_299 ;
V_154 = (struct V_153 * ) F_144 ( V_67 ) ;
V_154 = F_76 ( V_152 ) ;
if ( V_154 -> V_159 == V_300 && V_154 -> V_269 == V_301 )
return 0 ;
V_2 = ( (struct V_71 * ) F_43 ( V_75 ) ) -> V_77 ;
V_47 = F_2 ( V_2 ) ;
if ( F_140 ( V_47 ) && F_180 ( V_152 ) == V_302 &&
F_145 ( V_154 -> V_303 ) == V_304 ) {
F_18 ( L_50 ) ;
return - V_112 ;
}
if ( ! ( F_179 ( V_152 ) & V_299 ) ||
F_181 ( F_182 ( V_152 ) ) == ~ F_183 ( ~ 0 , V_67 -> V_241 , V_67 -> V_239 ) ) {
F_179 ( V_152 ) &= ~ V_299 ;
return 0 ;
}
V_256 = F_149 ( V_75 -> V_256 , F_125 () ) ;
V_256 -> V_305 ++ ;
if ( V_256 -> V_305 < 5 )
F_66 ( V_306 L_51 ) ;
F_129 () ;
return - V_112 ;
}
static void F_184 ( struct V_66 * V_67 )
{
T_2 F_156 ;
struct V_76 * V_75 ;
struct V_233 * V_234 ;
struct V_262 * V_256 ;
struct V_111 V_215 ;
struct V_151 * V_152 ;
struct V_71 * V_72 ;
struct V_110 * V_267 ;
V_234 = F_146 ( V_67 ) ;
V_75 = V_234 -> V_249 ;
if ( F_136 ( ! V_75 ) ) {
if ( V_67 -> V_307 != F_176 )
F_3 ( V_67 -> V_39 , L_52 ) ;
F_128 ( V_67 ) ;
return;
}
F_3 ( V_67 -> V_39 , L_53
L_54 ,
V_67 -> V_239 , V_67 -> V_157 ,
V_67 -> V_240 , V_67 -> V_241 , F_137 ( V_67 ) ,
F_138 ( V_67 ) , V_67 -> V_242 ,
V_67 -> V_39 ? V_67 -> V_39 -> V_135 : L_44 ) ;
V_72 = F_43 ( V_75 ) ;
F_185 ( V_67 ) ;
V_267 = (struct V_110 * ) F_186 ( V_67 ) ;
V_256 = F_149 ( V_75 -> V_256 , F_125 () ) ;
if ( F_136 ( F_187 ( V_267 ) != V_291 ) ) {
if ( V_256 -> V_257 < 5 )
F_66 ( V_306 L_55
L_56
L_57
L_58
L_59 , F_187 ( V_267 ) ,
V_291 ) ;
goto V_308;
}
F_188 ( V_67 , sizeof( struct V_110 ) ) ;
F_156 = V_67 -> V_239 - sizeof( struct V_111 ) ;
V_256 -> V_309 ++ ;
V_256 -> V_310 += F_156 / V_268 ;
V_152 = (struct V_151 * ) V_67 ;
F_189 ( V_152 ) ;
V_249 ( V_152 ) = V_75 ;
F_159 ( V_152 ) = V_267 -> V_292 ;
if ( F_190 ( V_67 , F_156 , & V_215 , sizeof( V_215 ) ) )
goto V_308;
F_160 ( V_152 ) = V_215 . V_280 ;
F_182 ( V_152 ) = V_215 . V_281 ;
if ( F_191 ( V_67 , F_156 ) )
goto V_308;
if ( ! F_178 ( V_75 , V_152 ) ) {
F_129 () ;
F_192 ( V_75 , V_152 ) ;
return;
}
V_308:
V_256 -> V_257 ++ ;
F_129 () ;
F_128 ( V_67 ) ;
}
static int V_211 ( void * V_311 )
{
struct V_206 * V_207 = V_311 ;
struct V_66 * V_67 ;
struct V_312 V_313 ;
F_53 ( & V_313 ) ;
F_193 ( V_314 , - 20 ) ;
V_315:
while ( ! F_194 () ) {
F_121 ( & V_207 -> V_212 . V_213 ) ;
F_195 ( & V_207 -> V_212 , & V_313 ) ;
if ( ! F_196 ( & V_313 ) ) {
F_197 ( V_255 ) ;
F_122 ( & V_207 -> V_212 . V_213 ) ;
F_198 () ;
F_197 ( V_316 ) ;
goto V_315;
}
F_122 ( & V_207 -> V_212 . V_213 ) ;
while ( ( V_67 = F_126 ( & V_313 ) ) != NULL )
F_184 ( V_67 ) ;
}
return 0 ;
}
static void F_199 ( void )
{
F_200 ( & V_317 ) ;
F_201 ( & V_318 ) ;
}
static void F_202 ( void )
{
F_203 ( & V_317 ) ;
F_204 ( & V_318 ) ;
}
static struct V_1 *
F_205 ( struct V_3 * V_4 )
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
static int F_206 ( struct V_220 * V_319 ,
T_8 V_320 , void * V_321 )
{
struct V_322 * V_323 = V_321 ;
struct V_5 * V_47 ;
struct V_1 * V_2 ;
struct V_3 * V_4 ;
struct V_71 * V_72 ;
int V_324 ;
if ( V_323 -> V_325 . V_326 != V_327 )
return V_228 ;
V_4 = F_207 ( & V_328 , V_323 -> V_329 ) ;
if ( ! V_4 )
return V_228 ;
V_2 = F_205 ( V_4 ) ;
F_25 ( V_4 ) ;
if ( ! V_2 )
return V_228 ;
V_47 = F_2 ( V_2 ) ;
if ( V_323 -> V_330 & V_331 )
V_324 = F_208 ( V_323 -> V_325 . V_284 ) - 1 ;
else
V_324 = V_323 -> V_325 . V_284 ;
if ( V_324 < 0 )
return V_228 ;
if ( V_323 -> V_325 . V_283 == V_42 ||
V_323 -> V_325 . V_283 == V_38 )
V_47 -> V_284 = V_324 ;
if ( V_323 -> V_325 . V_283 == V_38 ) {
V_72 = F_43 ( V_47 -> V_64 ) ;
V_72 -> V_284 = V_324 ;
}
return V_228 ;
}
static int F_209 ( struct V_220 * V_319 ,
T_8 V_320 , void * V_321 )
{
struct V_76 * V_75 = NULL ;
struct V_3 * V_4 = V_321 ;
struct V_5 * V_47 ;
struct V_1 * V_2 ;
struct V_71 * V_72 ;
struct V_262 * V_256 ;
T_2 V_332 = 1 ;
T_2 V_104 ;
int V_120 = V_228 ;
F_83 (fcoe, &fcoe_hostlist, list) {
if ( V_2 -> V_4 == V_4 ) {
V_47 = F_2 ( V_2 ) ;
V_75 = V_47 -> V_64 ;
break;
}
}
if ( ! V_75 ) {
V_120 = V_333 ;
goto V_52;
}
switch ( V_320 ) {
case V_334 :
case V_335 :
V_332 = 0 ;
break;
case V_336 :
case V_337 :
break;
case V_338 :
if ( V_4 -> V_97 & V_108 )
break;
V_104 = V_4 -> V_107 - ( sizeof( struct V_110 ) +
sizeof( struct V_111 ) ) ;
if ( V_104 >= V_339 )
F_52 ( V_75 , V_104 ) ;
break;
case V_340 :
break;
case V_341 :
F_210 ( & V_2 -> V_342 ) ;
V_72 = F_43 ( V_47 -> V_64 ) ;
F_211 ( V_343 , & V_72 -> V_195 ) ;
goto V_52;
break;
case V_344 :
F_48 ( V_75 , V_4 ) ;
break;
default:
F_3 ( V_4 , L_60
L_61 , V_320 ) ;
}
F_55 ( V_75 ) ;
if ( V_332 && ! F_212 ( V_75 ) )
F_213 ( V_47 ) ;
else if ( F_214 ( V_47 ) ) {
V_256 = F_149 ( V_75 -> V_256 , F_125 () ) ;
V_256 -> V_345 ++ ;
F_129 () ;
F_90 ( V_75 ) ;
}
V_52:
return V_120 ;
}
static int F_215 ( struct V_3 * V_4 )
{
struct V_5 * V_47 ;
struct V_1 * V_2 ;
int V_120 = 0 ;
F_49 ( & V_346 ) ;
F_34 () ;
V_2 = F_216 ( V_4 ) ;
F_35 () ;
if ( V_2 ) {
V_47 = F_2 ( V_2 ) ;
F_214 ( V_47 ) ;
F_90 ( V_47 -> V_64 ) ;
} else
V_120 = - V_204 ;
F_50 ( & V_346 ) ;
return V_120 ;
}
static int F_217 ( struct V_3 * V_4 )
{
struct V_5 * V_47 ;
struct V_1 * V_2 ;
int V_120 = 0 ;
F_49 ( & V_346 ) ;
F_34 () ;
V_2 = F_216 ( V_4 ) ;
F_35 () ;
if ( ! V_2 ) {
V_120 = - V_204 ;
goto V_52;
}
V_47 = F_2 ( V_2 ) ;
if ( ! F_212 ( V_47 -> V_64 ) )
F_213 ( V_47 ) ;
V_52:
F_50 ( & V_346 ) ;
return V_120 ;
}
static int F_218 ( struct V_3 * V_4 )
{
struct V_5 * V_47 ;
struct V_1 * V_2 ;
struct V_76 * V_75 ;
struct V_71 * V_72 ;
int V_120 = 0 ;
F_49 ( & V_346 ) ;
F_34 () ;
V_2 = F_216 ( V_4 ) ;
if ( ! V_2 ) {
V_120 = - V_204 ;
goto V_347;
}
V_47 = F_2 ( V_2 ) ;
V_75 = V_47 -> V_64 ;
V_72 = F_43 ( V_75 ) ;
F_210 ( & V_2 -> V_342 ) ;
F_211 ( V_343 , & V_72 -> V_195 ) ;
V_347:
F_35 () ;
F_50 ( & V_346 ) ;
return V_120 ;
}
static void V_196 ( struct V_348 * V_349 )
{
struct V_71 * V_72 ;
struct V_1 * V_2 ;
V_72 = F_37 ( V_349 , struct V_71 , V_195 ) ;
F_49 ( & V_346 ) ;
V_2 = V_72 -> V_77 ;
F_86 ( V_72 -> V_75 ) ;
F_32 ( V_2 ) ;
F_50 ( & V_346 ) ;
}
static bool F_219 ( struct V_3 * V_4 )
{
return true ;
}
static void F_220 ( struct V_1 * V_2 )
{
#ifdef F_221
int V_330 ;
T_1 V_350 , V_351 ;
struct V_3 * V_4 = V_2 -> V_22 ;
struct V_5 * V_47 = F_2 ( V_2 ) ;
struct V_71 * V_72 = F_43 ( V_47 -> V_64 ) ;
struct V_352 V_325 = {
. V_284 = 0 ,
. V_283 = V_38
} ;
if ( V_4 && V_4 -> V_353 && V_4 -> V_353 -> V_354 ) {
V_330 = V_4 -> V_353 -> V_354 ( V_4 ) ;
if ( V_330 & V_355 ) {
V_325 . V_326 = V_356 ;
V_351 = F_222 ( V_4 , & V_325 ) ;
V_325 . V_283 = V_42 ;
V_350 = F_222 ( V_4 , & V_325 ) ;
} else {
V_325 . V_326 = V_327 ;
V_351 = F_223 ( V_4 , & V_325 ) ;
V_325 . V_283 = V_42 ;
V_350 = F_223 ( V_4 , & V_325 ) ;
}
V_72 -> V_284 = F_208 ( V_351 ) ? F_208 ( V_351 ) - 1 : 0 ;
V_47 -> V_284 = F_208 ( V_350 ) ? F_208 ( V_350 ) - 1 : V_72 -> V_284 ;
}
#endif
}
static int F_224 ( struct V_3 * V_4 , enum V_43 V_44 )
{
int V_120 = 0 ;
struct V_45 * V_46 ;
struct V_5 * V_47 ;
struct V_1 * V_2 ;
struct V_76 * V_75 ;
F_49 ( & V_346 ) ;
F_34 () ;
if ( F_225 ( V_4 ) ) {
V_120 = - V_357 ;
goto V_347;
}
V_2 = F_14 ( V_4 , V_44 ) ;
if ( F_118 ( V_2 ) ) {
V_120 = F_226 ( V_2 ) ;
goto V_347;
}
V_47 = F_2 ( V_2 ) ;
V_46 = F_33 ( V_47 ) ;
V_75 = F_100 ( V_2 , & V_46 -> V_39 , 0 ) ;
if ( F_118 ( V_75 ) ) {
F_66 ( V_175 L_62 ,
V_4 -> V_135 ) ;
V_120 = - V_358 ;
F_35 () ;
F_32 ( V_2 ) ;
goto V_359;
}
V_47 -> V_64 = V_75 ;
F_220 ( V_2 ) ;
F_227 ( V_75 ) ;
V_75 -> V_360 = V_361 ;
F_228 ( V_75 ) ;
if ( ! F_212 ( V_75 ) ) {
F_35 () ;
F_213 ( V_47 ) ;
F_50 ( & V_346 ) ;
return V_120 ;
}
V_347:
F_35 () ;
V_359:
F_50 ( & V_346 ) ;
return V_120 ;
}
static int F_55 ( struct V_76 * V_75 )
{
struct V_3 * V_4 = F_62 ( V_75 ) ;
struct V_362 V_363 ;
if ( ! F_229 ( V_4 , & V_363 ) ) {
V_75 -> V_364 &=
~ ( V_365 | V_366 ) ;
if ( V_363 . V_367 & ( V_368 |
V_369 ) )
V_75 -> V_364 |= V_365 ;
if ( V_363 . V_367 & V_370 )
V_75 -> V_364 |=
V_366 ;
switch ( F_230 ( & V_363 ) ) {
case V_371 :
V_75 -> V_372 = V_365 ;
break;
case V_373 :
V_75 -> V_372 = V_366 ;
break;
}
return 0 ;
}
return - 1 ;
}
static int F_212 ( struct V_76 * V_75 )
{
struct V_3 * V_4 = F_62 ( V_75 ) ;
if ( F_231 ( V_4 ) )
return 0 ;
return - 1 ;
}
static void F_91 ( struct V_76 * V_75 )
{
struct V_206 * V_374 ;
struct V_66 * V_67 ;
unsigned int V_205 ;
F_232 (cpu) {
V_374 = & F_114 ( V_210 , V_205 ) ;
if ( ! V_374 -> V_209 || ! F_233 ( V_205 ) )
continue;
V_67 = F_234 ( 0 ) ;
if ( ! V_67 )
continue;
V_67 -> V_307 = F_176 ;
F_121 ( & V_374 -> V_212 . V_213 ) ;
F_127 ( & V_374 -> V_212 , V_67 ) ;
if ( V_374 -> V_212 . V_74 == 1 )
F_120 ( V_374 -> V_209 ) ;
F_122 ( & V_374 -> V_212 . V_213 ) ;
F_235 ( & V_298 ) ;
}
}
static int F_236 ( struct V_187 * V_188 )
{
struct V_76 * V_75 = F_107 ( V_188 ) ;
struct V_71 * V_72 = F_43 ( V_75 ) ;
struct V_1 * V_2 = V_72 -> V_77 ;
struct V_5 * V_47 = F_2 ( V_2 ) ;
F_214 ( V_47 ) ;
F_90 ( V_47 -> V_64 ) ;
if ( ! F_212 ( V_47 -> V_64 ) )
F_213 ( V_47 ) ;
return 0 ;
}
static struct V_1 *
F_216 ( const struct V_3 * V_4 )
{
struct V_1 * V_2 ;
F_83 (fcoe, &fcoe_hostlist, list) {
if ( V_2 -> V_4 == V_4 )
return V_2 ;
}
return NULL ;
}
static struct V_76 * F_225 ( const struct V_3 * V_4 )
{
struct V_5 * V_47 ;
struct V_1 * V_2 ;
V_2 = F_216 ( V_4 ) ;
V_47 = F_2 ( V_2 ) ;
return ( V_2 ) ? V_47 -> V_64 : NULL ;
}
static int F_227 ( const struct V_76 * V_75 )
{
struct V_1 * V_2 ;
struct V_71 * V_72 ;
V_2 = F_216 ( F_62 ( V_75 ) ) ;
if ( ! V_2 ) {
V_72 = F_43 ( V_75 ) ;
V_2 = V_72 -> V_77 ;
F_237 ( & V_2 -> V_342 , & V_375 ) ;
}
return 0 ;
}
static int T_5 F_238 ( void )
{
struct V_206 * V_207 ;
unsigned int V_205 ;
int V_120 = 0 ;
V_343 = F_239 ( L_63 , 0 , 0 ) ;
if ( ! V_343 )
return - V_54 ;
V_120 = F_240 ( & V_376 ) ;
if ( V_120 ) {
F_66 ( V_175 L_64
L_65 ) ;
return V_120 ;
}
F_49 ( & V_346 ) ;
F_232 (cpu) {
V_207 = & F_114 ( V_210 , V_205 ) ;
F_53 ( & V_207 -> V_212 ) ;
}
F_241 (cpu)
F_113 ( V_205 ) ;
V_120 = F_242 ( & V_377 ) ;
if ( V_120 )
goto V_378;
F_199 () ;
V_120 = F_109 () ;
if ( V_120 )
goto V_378;
F_50 ( & V_346 ) ;
return 0 ;
V_378:
F_241 (cpu) {
F_123 ( V_205 ) ;
}
F_50 ( & V_346 ) ;
F_243 ( V_343 ) ;
return V_120 ;
}
static void T_6 F_244 ( void )
{
struct V_1 * V_2 , * V_313 ;
struct V_5 * V_47 ;
struct V_71 * V_72 ;
unsigned int V_205 ;
F_49 ( & V_346 ) ;
F_202 () ;
F_34 () ;
F_245 (fcoe, tmp, &fcoe_hostlist, list) {
F_210 ( & V_2 -> V_342 ) ;
V_47 = F_2 ( V_2 ) ;
V_72 = F_43 ( V_47 -> V_64 ) ;
F_211 ( V_343 , & V_72 -> V_195 ) ;
}
F_35 () ;
F_246 ( & V_377 ) ;
F_241 (cpu)
F_123 ( V_205 ) ;
F_50 ( & V_346 ) ;
F_243 ( V_343 ) ;
F_111 () ;
F_247 ( & V_376 ) ;
}
static void F_248 ( struct V_379 * V_380 , struct V_151 * V_152 , void * V_311 )
{
struct V_5 * V_6 = V_311 ;
struct V_381 * V_382 = F_249 ( V_380 ) ;
struct V_76 * V_75 = V_382 -> V_64 ;
T_1 * V_383 ;
if ( F_118 ( V_152 ) )
goto V_384;
V_383 = F_250 ( V_152 ) -> V_385 ;
if ( F_44 ( V_383 ) )
F_251 ( V_6 , V_75 , V_152 ) ;
if ( ! F_44 ( V_383 ) )
V_59 ( V_75 , V_383 ) ;
V_384:
F_252 ( V_380 , V_152 , V_75 ) ;
}
static void F_253 ( struct V_379 * V_380 , struct V_151 * V_152 , void * V_311 )
{
struct V_76 * V_75 = V_311 ;
static T_1 V_386 [ V_11 ] = { 0 } ;
if ( ! F_118 ( V_152 ) )
V_59 ( V_75 , V_386 ) ;
F_254 ( V_380 , V_152 , V_75 ) ;
}
static struct V_379 * F_255 ( struct V_76 * V_75 , T_2 V_387 ,
struct V_151 * V_152 , unsigned int V_388 ,
void (* F_256)( struct V_379 * ,
struct V_151 * ,
void * ) ,
void * V_311 , T_2 V_389 )
{
struct V_71 * V_72 = F_43 ( V_75 ) ;
struct V_1 * V_2 = V_72 -> V_77 ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_153 * V_154 = F_76 ( V_152 ) ;
switch ( V_388 ) {
case V_390 :
case V_391 :
if ( V_75 -> V_392 )
break;
return F_257 ( V_75 , V_387 , V_152 , V_388 , F_248 ,
V_6 , V_389 ) ;
case V_302 :
if ( F_145 ( V_154 -> V_248 ) != V_304 )
break;
return F_257 ( V_75 , V_387 , V_152 , V_388 , F_253 ,
V_75 , V_389 ) ;
}
return F_257 ( V_75 , V_387 , V_152 , V_388 , F_256 , V_311 , V_389 ) ;
}
static int F_258 ( struct V_189 * V_116 , bool V_393 )
{
struct V_187 * V_188 = F_106 ( V_116 ) ;
struct V_76 * V_186 = F_107 ( V_188 ) ;
struct V_71 * V_72 = F_43 ( V_186 ) ;
struct V_1 * V_2 = V_72 -> V_77 ;
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_76 * V_394 ;
int V_120 ;
char V_395 [ 32 ] ;
V_120 = F_259 ( V_116 ) ;
if ( V_120 ) {
F_260 ( V_116 -> V_199 , V_395 , sizeof( V_395 ) ) ;
F_66 ( V_175 L_66
L_67 ,
V_395 ) ;
return V_120 ;
}
F_49 ( & V_346 ) ;
F_34 () ;
V_394 = F_100 ( V_2 , & V_116 -> V_39 , 1 ) ;
F_35 () ;
F_50 ( & V_346 ) ;
if ( F_118 ( V_394 ) ) {
F_66 ( V_175 L_68 ,
V_4 -> V_135 ) ;
return - V_358 ;
}
if ( V_393 ) {
F_261 ( V_116 , V_396 ) ;
} else {
V_394 -> V_360 = V_361 ;
F_228 ( V_394 ) ;
F_262 ( V_394 ) ;
}
return 0 ;
}
static int F_263 ( struct V_189 * V_116 )
{
struct V_187 * V_188 = F_106 ( V_116 ) ;
struct V_76 * V_186 = F_107 ( V_188 ) ;
struct V_76 * V_394 = V_116 -> V_397 ;
F_49 ( & V_186 -> V_96 ) ;
F_210 ( & V_394 -> V_342 ) ;
F_50 ( & V_186 -> V_96 ) ;
F_49 ( & V_346 ) ;
F_86 ( V_394 ) ;
F_50 ( & V_346 ) ;
return 0 ;
}
static int F_264 ( struct V_189 * V_116 , bool V_398 )
{
struct V_76 * V_75 = V_116 -> V_397 ;
if ( V_398 ) {
F_261 ( V_116 , V_396 ) ;
F_87 ( V_75 ) ;
} else {
V_75 -> V_360 = V_361 ;
F_228 ( V_75 ) ;
F_262 ( V_75 ) ;
}
return 0 ;
}
static void F_265 ( struct V_189 * V_116 )
{
struct V_76 * V_75 = V_116 -> V_397 ;
struct V_151 * V_152 ;
T_9 V_239 ;
snprintf ( F_64 ( V_75 -> V_65 ) , V_132 ,
L_69 , V_133 , V_134 ,
F_62 ( V_75 ) -> V_135 , V_116 -> V_399 ) ;
if ( V_75 -> V_254 != V_400 )
return;
V_239 = F_266 ( F_64 ( V_75 -> V_65 ) , 255 ) ;
V_152 = F_267 ( V_75 ,
sizeof( struct V_401 ) +
sizeof( struct V_402 ) + V_239 ) ;
if ( ! V_152 )
return;
V_75 -> V_403 . V_404 ( V_75 , V_405 , V_152 , V_406 ,
NULL , NULL , 3 * V_75 -> V_84 ) ;
}
static void F_268 ( struct V_76 * V_75 ,
struct V_407 * V_408 )
{
struct V_3 * V_4 = F_62 ( V_75 ) ;
F_269 ( V_75 , V_408 , V_4 ) ;
}
static void F_270 ( struct V_45 * V_46 )
{
struct V_5 * V_6 = F_19 ( V_46 ) ;
struct V_3 * V_4 = F_62 ( V_6 -> V_64 ) ;
struct V_409 * V_410 ;
struct V_407 V_408 ;
F_269 ( V_6 -> V_64 , & V_408 , V_4 ) ;
V_410 = (struct V_409 * ) ( & V_408 ) ;
V_46 -> V_411 . V_412 =
F_81 ( V_410 -> V_412 ) ;
V_46 -> V_411 . V_413 =
F_81 ( V_410 -> V_413 ) ;
V_46 -> V_411 . V_414 =
F_81 ( V_410 -> V_414 ) ;
V_46 -> V_411 . V_415 =
F_81 ( V_410 -> V_415 ) ;
V_46 -> V_411 . V_416 =
F_81 ( V_410 -> V_416 ) ;
V_46 -> V_411 . V_417 =
F_81 ( V_410 -> V_417 ) ;
}
static void F_271 ( struct V_418 * V_419 )
{
struct V_45 * V_46 =
F_272 ( V_419 ) ;
struct V_5 * V_47 = F_19 ( V_46 ) ;
struct V_1 * V_2 = F_20 ( V_47 ) ;
V_419 -> V_420 = F_173 ( V_2 -> V_4 ) ;
}
static void F_273 ( struct V_76 * V_75 ,
T_2 V_421 , struct V_151 * V_152 )
{
struct V_71 * V_72 = F_43 ( V_75 ) ;
struct V_1 * V_2 = V_72 -> V_77 ;
struct V_5 * V_47 = F_2 ( V_2 ) ;
if ( V_152 && F_180 ( V_152 ) == V_390 )
F_251 ( V_47 , V_75 , V_152 ) ;
}
