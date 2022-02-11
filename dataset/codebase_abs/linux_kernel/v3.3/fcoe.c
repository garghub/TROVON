static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = & V_2 -> V_7 ;
struct V_8 * V_9 ;
struct V_3 * V_10 ;
T_1 V_11 [ V_12 ] ;
const struct V_13 * V_14 ;
V_2 -> V_4 = V_4 ;
V_14 = V_4 -> V_15 ;
if ( V_14 -> V_16 ) {
if ( V_14 -> V_16 ( V_4 ) )
F_2 ( V_4 , L_1
L_2 ) ;
}
if ( V_4 -> V_17 & V_18 && V_4 -> V_19 & V_20 ) {
F_2 ( V_4 , L_3 ) ;
return - V_21 ;
}
V_10 = ( V_4 -> V_17 & V_22 ) ?
F_3 ( V_4 ) : V_4 ;
V_2 -> V_23 = V_10 ;
F_4 () ;
F_5 (real_dev, ha) {
if ( ( V_9 -> type == V_24 ) &&
( F_6 ( V_9 -> V_25 ) ) ) {
memcpy ( V_6 -> V_26 , V_9 -> V_25 , V_12 ) ;
V_6 -> V_27 = 1 ;
break;
}
}
F_7 () ;
if ( ! V_6 -> V_27 )
memcpy ( V_6 -> V_26 , V_4 -> V_28 , V_4 -> V_29 ) ;
memcpy ( V_11 , ( T_1 [ 6 ] ) V_30 , V_12 ) ;
F_8 ( V_4 , V_11 ) ;
if ( V_6 -> V_27 )
F_8 ( V_4 , V_6 -> V_26 ) ;
if ( V_6 -> V_31 == V_32 ) {
F_9 ( V_4 , V_33 ) ;
F_9 ( V_4 , V_34 ) ;
} else
F_9 ( V_4 , V_35 ) ;
V_2 -> V_36 . V_37 = V_38 ;
V_2 -> V_36 . type = F_10 ( V_39 ) ;
V_2 -> V_36 . V_40 = V_4 ;
F_11 ( & V_2 -> V_36 ) ;
V_2 -> V_41 . V_37 = V_42 ;
V_2 -> V_41 . type = F_12 ( V_43 ) ;
V_2 -> V_41 . V_40 = V_4 ;
F_11 ( & V_2 -> V_41 ) ;
return 0 ;
}
static struct V_1 * F_13 ( struct V_3 * V_4 ,
enum V_44 V_45 )
{
struct V_1 * V_2 ;
int V_46 ;
if ( ! F_14 ( V_47 ) ) {
F_2 ( V_4 ,
L_4 ) ;
V_2 = F_15 ( - V_48 ) ;
goto V_49;
}
V_2 = F_16 ( sizeof( * V_2 ) , V_50 ) ;
if ( ! V_2 ) {
F_2 ( V_4 , L_5 ) ;
V_2 = F_15 ( - V_51 ) ;
goto V_52;
}
F_17 ( V_4 ) ;
F_18 ( & V_2 -> V_53 ) ;
F_19 ( & V_2 -> V_7 , V_45 ) ;
V_2 -> V_7 . V_54 = V_55 ;
V_2 -> V_7 . V_56 = V_57 ;
V_2 -> V_7 . V_58 = V_59 ;
V_46 = F_1 ( V_2 , V_4 ) ;
if ( V_46 ) {
F_20 ( & V_2 -> V_7 ) ;
F_21 ( V_2 ) ;
F_22 ( V_4 ) ;
V_2 = F_15 ( V_46 ) ;
goto V_52;
}
goto V_49;
V_52:
F_23 ( V_47 ) ;
V_49:
return V_2 ;
}
static void F_24 ( struct V_53 * V_53 )
{
struct V_1 * V_2 ;
struct V_3 * V_4 ;
V_2 = F_25 ( V_53 , struct V_1 , V_53 ) ;
V_4 = V_2 -> V_4 ;
F_20 ( & V_2 -> V_7 ) ;
F_21 ( V_2 ) ;
F_22 ( V_4 ) ;
F_23 ( V_47 ) ;
}
static inline void F_26 ( struct V_1 * V_2 )
{
F_27 ( & V_2 -> V_53 ) ;
}
static inline void F_28 ( struct V_1 * V_2 )
{
F_29 ( & V_2 -> V_53 , F_24 ) ;
}
static void F_30 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_5 * V_6 = & V_2 -> V_7 ;
T_1 V_11 [ V_12 ] ;
const struct V_13 * V_14 ;
F_31 () ;
F_32 ( & V_2 -> V_36 ) ;
F_32 ( & V_2 -> V_41 ) ;
F_33 () ;
memcpy ( V_11 , ( T_1 [ 6 ] ) V_30 , V_12 ) ;
F_34 ( V_4 , V_11 ) ;
if ( V_6 -> V_27 )
F_34 ( V_4 , V_6 -> V_26 ) ;
if ( V_6 -> V_31 == V_32 ) {
F_35 ( V_4 , V_33 ) ;
F_35 ( V_4 , V_34 ) ;
} else
F_35 ( V_4 , V_35 ) ;
V_14 = V_4 -> V_15 ;
if ( V_14 -> V_60 ) {
if ( V_14 -> V_60 ( V_4 ) )
F_2 ( V_4 , L_6
L_2 ) ;
}
F_36 () ;
F_28 ( V_2 ) ;
}
static int V_42 ( struct V_61 * V_62 , struct V_3 * V_4 ,
struct V_63 * V_64 ,
struct V_3 * V_65 )
{
struct V_1 * V_2 ;
V_2 = F_25 ( V_64 , struct V_1 , V_41 ) ;
F_37 ( & V_2 -> V_7 , V_62 ) ;
return 0 ;
}
static void F_38 ( struct V_66 * V_67 , struct V_61 * V_62 )
{
if ( V_67 -> V_68 . V_69 )
F_39 ( V_67 -> V_70 , V_62 ) ;
else if ( F_40 ( V_62 ) )
F_39 ( V_67 -> V_70 , V_62 ) ;
}
static void V_55 ( struct V_5 * V_6 , struct V_61 * V_62 )
{
V_62 -> V_40 = F_41 ( V_6 ) -> V_4 ;
F_38 ( F_42 ( V_6 -> V_71 ) , V_62 ) ;
}
static void V_57 ( struct V_72 * V_70 , T_1 * V_25 )
{
struct V_66 * V_67 = F_42 ( V_70 ) ;
struct V_1 * V_2 = V_67 -> V_73 ;
F_31 () ;
if ( ! F_43 ( V_67 -> V_74 ) )
F_34 ( V_2 -> V_4 , V_67 -> V_74 ) ;
if ( ! F_43 ( V_25 ) )
F_8 ( V_2 -> V_4 , V_25 ) ;
memcpy ( V_67 -> V_74 , V_25 , V_12 ) ;
F_36 () ;
}
static T_1 * V_59 ( struct V_72 * V_70 )
{
struct V_66 * V_67 = F_42 ( V_70 ) ;
return V_67 -> V_74 ;
}
static int F_44 ( struct V_72 * V_70 )
{
V_70 -> V_75 = 0 ;
V_70 -> V_76 = 0 ;
V_70 -> V_77 = 3 ;
V_70 -> V_78 = 3 ;
V_70 -> V_79 = 2 * 1000 ;
V_70 -> V_80 = 2 * 2 * 1000 ;
V_70 -> V_81 = ( V_82 | V_83 |
V_84 | V_85 ) ;
V_70 -> V_86 = 1 ;
F_45 ( V_70 ) ;
F_46 ( V_70 ) ;
V_70 -> V_87 = 0 ;
V_70 -> V_88 = 0 ;
V_70 -> V_89 = 0 ;
V_70 -> V_90 = 0 ;
V_70 -> V_91 = 0 ;
return 0 ;
}
static void F_47 ( struct V_72 * V_70 ,
struct V_3 * V_4 )
{
F_48 ( & V_70 -> V_92 ) ;
if ( V_4 -> V_93 & V_94 )
V_70 -> V_95 = 1 ;
else
V_70 -> V_95 = 0 ;
if ( V_4 -> V_93 & V_96 ) {
V_70 -> V_87 = 1 ;
F_2 ( V_4 , L_7 ) ;
} else {
V_70 -> V_87 = 0 ;
}
if ( V_4 -> V_93 & V_97 ) {
V_70 -> V_88 = 1 ;
V_70 -> V_91 = V_4 -> V_98 ;
F_2 ( V_4 , L_8 ,
V_70 -> V_91 ) ;
} else {
V_70 -> V_88 = 0 ;
V_70 -> V_91 = 0 ;
}
if ( V_4 -> V_99 ) {
V_70 -> V_89 = 1 ;
V_70 -> V_90 = V_4 -> V_99 ;
F_2 ( V_4 , L_9 ,
V_70 -> V_90 ) ;
} else {
V_70 -> V_89 = 0 ;
V_70 -> V_90 = 0 ;
}
F_49 ( & V_70 -> V_92 ) ;
}
static int F_50 ( struct V_72 * V_70 , struct V_3 * V_4 )
{
T_2 V_100 ;
T_3 V_101 , V_102 ;
struct V_1 * V_2 ;
struct V_66 * V_67 ;
V_67 = F_42 ( V_70 ) ;
V_2 = V_67 -> V_73 ;
V_100 = V_4 -> V_103 ;
if ( V_4 -> V_93 & V_104 ) {
V_100 = V_105 ;
F_2 ( V_4 , L_10 , V_100 ) ;
}
V_100 -= ( sizeof( struct V_106 ) + sizeof( struct V_107 ) ) ;
if ( F_51 ( V_70 , V_100 ) )
return - V_108 ;
F_47 ( V_70 , V_4 ) ;
F_52 ( & V_67 -> V_68 ) ;
V_67 -> V_109 = 0 ;
F_53 ( & V_67 -> V_110 , V_111 , ( unsigned long ) V_70 ) ;
F_54 ( V_70 ) ;
if ( ! V_70 -> V_112 ) {
if ( F_55 ( V_4 , & V_101 , V_113 ) )
V_101 = F_56 ( V_2 -> V_7 . V_26 , 1 , 0 ) ;
F_57 ( V_70 , V_101 ) ;
if ( F_55 ( V_4 , & V_102 , V_114 ) )
V_102 = F_56 ( V_2 -> V_7 . V_26 ,
2 , 0 ) ;
F_58 ( V_70 , V_102 ) ;
}
return 0 ;
}
static int F_59 ( struct V_72 * V_70 , struct V_115 * V_40 )
{
int V_116 = 0 ;
V_70 -> V_117 -> V_118 = V_119 ;
V_70 -> V_117 -> V_120 = V_121 ;
V_70 -> V_117 -> V_122 = 0 ;
V_70 -> V_117 -> V_123 = V_124 ;
if ( V_70 -> V_112 )
V_70 -> V_117 -> V_125 = V_126 ;
else
V_70 -> V_117 -> V_125 = V_127 ;
V_116 = F_60 ( V_70 -> V_117 , V_40 ) ;
if ( V_116 ) {
F_2 ( F_61 ( V_70 ) , L_11
L_12 ) ;
return V_116 ;
}
if ( ! V_70 -> V_112 )
F_62 ( V_70 -> V_117 ) = V_128 ;
snprintf ( F_63 ( V_70 -> V_117 ) , V_129 ,
L_13 , V_130 , V_131 ,
F_61 ( V_70 ) -> V_132 ) ;
return 0 ;
}
static bool F_64 ( struct V_133 * V_134 )
{
struct V_135 * V_136 = F_65 ( V_134 ) ;
struct V_137 * V_138 ;
if ( F_66 ( F_67 ( V_134 ) ) &&
( F_67 ( V_134 ) -> V_139 > V_140 ) )
return true ;
else if ( ( F_67 ( V_134 ) == NULL ) &&
( V_136 -> V_141 == V_142 ) &&
( F_68 ( V_136 -> V_143 ) == V_144 ) ) {
V_138 = F_69 ( V_134 , sizeof( * V_138 ) ) ;
if ( ( V_138 -> V_145 & V_146 ) &&
( F_70 ( V_138 -> V_147 ) > V_140 ) )
return true ;
}
return false ;
}
static inline int F_71 ( struct V_72 * V_70 )
{
struct V_66 * V_67 = F_42 ( V_70 ) ;
struct V_1 * V_2 = V_67 -> V_73 ;
struct V_1 * V_148 = NULL ;
struct V_3 * V_149 , * V_150 ;
T_4 V_151 = V_152 ;
T_4 V_153 = V_154 ;
if ( ! V_70 -> V_89 || ! V_70 -> V_90 ||
( V_70 -> V_90 >= V_153 ) ) {
V_70 -> V_90 = 0 ;
goto V_155;
}
if ( V_2 -> V_4 -> V_17 & V_22 )
V_150 = F_3 ( V_2 -> V_4 ) ;
else
V_150 = V_2 -> V_4 ;
F_72 (oldfcoe, &fcoe_hostlist, list) {
if ( V_148 -> V_4 -> V_17 & V_22 )
V_149 = F_3 ( V_148 -> V_4 ) ;
else
V_149 = V_148 -> V_4 ;
if ( V_150 == V_149 ) {
V_2 -> V_156 = V_148 -> V_156 ;
break;
}
}
if ( V_2 -> V_156 ) {
if ( ! F_73 ( V_70 , V_2 -> V_156 , F_64 ) ) {
F_74 ( V_157 L_14
L_15 ,
V_2 -> V_156 , V_2 -> V_4 -> V_132 ) ;
return - V_51 ;
}
} else {
V_2 -> V_156 = F_75 ( V_70 , V_158 ,
V_152 , V_70 -> V_90 ,
F_64 ) ;
if ( ! V_2 -> V_156 ) {
F_74 ( V_157 L_16
L_17 ,
V_2 -> V_4 -> V_132 ) ;
return - V_51 ;
}
}
V_151 += V_70 -> V_90 + 1 ;
V_155:
if ( ! F_75 ( V_70 , V_158 , V_151 , V_153 , NULL ) ) {
F_74 ( V_157 L_18
L_19 , V_2 -> V_4 -> V_132 ) ;
return - V_51 ;
}
return 0 ;
}
static void F_76 ( struct V_72 * V_70 )
{
struct V_66 * V_67 = F_42 ( V_70 ) ;
struct V_1 * V_2 = V_67 -> V_73 ;
struct V_3 * V_4 = V_2 -> V_4 ;
F_2 ( V_4 , L_20 ) ;
F_77 ( V_70 ) ;
F_78 ( V_70 ) ;
F_79 ( & V_67 -> V_110 ) ;
F_80 ( V_70 ) ;
F_31 () ;
if ( ! F_43 ( V_67 -> V_74 ) )
F_34 ( V_4 , V_67 -> V_74 ) ;
F_36 () ;
F_28 ( V_2 ) ;
F_81 ( V_70 ) ;
F_82 ( V_70 -> V_117 ) ;
F_83 ( V_70 -> V_117 ) ;
F_84 ( V_70 ) ;
F_85 ( V_70 ) ;
F_86 ( V_70 ) ;
F_87 ( V_70 -> V_117 ) ;
}
static int F_88 ( struct V_72 * V_70 , T_4 V_159 ,
struct V_160 * V_161 , unsigned int V_162 )
{
struct V_3 * V_4 = F_61 ( V_70 ) ;
if ( V_4 -> V_15 -> V_163 )
return V_4 -> V_15 -> V_163 ( V_4 ,
V_159 , V_161 ,
V_162 ) ;
return 0 ;
}
static int F_89 ( struct V_72 * V_70 , T_4 V_159 ,
struct V_160 * V_161 , unsigned int V_162 )
{
struct V_3 * V_4 = F_61 ( V_70 ) ;
if ( V_4 -> V_15 -> V_164 )
return V_4 -> V_15 -> V_164 ( V_4 , V_159 ,
V_161 , V_162 ) ;
return 0 ;
}
static int F_90 ( struct V_72 * V_70 , T_4 V_159 )
{
struct V_3 * V_4 = F_61 ( V_70 ) ;
if ( V_4 -> V_15 -> V_165 )
return V_4 -> V_15 -> V_165 ( V_4 , V_159 ) ;
return 0 ;
}
static struct V_72 * F_91 ( struct V_1 * V_2 ,
struct V_115 * V_166 , int V_167 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_72 * V_70 , * V_168 ;
struct V_66 * V_67 ;
struct V_169 * V_170 ;
int V_116 ;
struct V_171 * V_112 = F_92 ( V_166 ) ;
F_2 ( V_4 , L_21 ) ;
if ( ! V_167 )
V_70 = F_93 ( & V_172 , sizeof( * V_67 ) ) ;
else
V_70 = F_94 ( V_112 , sizeof( * V_67 ) ) ;
if ( ! V_70 ) {
F_2 ( V_4 , L_22 ) ;
V_116 = - V_51 ;
goto V_49;
}
V_67 = F_42 ( V_70 ) ;
V_67 -> V_70 = V_70 ;
V_67 -> V_73 = V_2 ;
V_67 -> V_173 = V_174 ;
V_67 -> V_175 = V_176 ;
F_95 ( & V_67 -> V_177 , V_178 ) ;
V_116 = F_44 ( V_70 ) ;
if ( V_116 ) {
F_2 ( V_4 , L_23
L_24 ) ;
goto V_179;
}
if ( V_167 ) {
F_2 ( V_4 , L_25
L_26 ,
V_112 -> V_180 , V_112 -> V_181 ) ;
F_57 ( V_70 , V_112 -> V_180 ) ;
F_58 ( V_70 , V_112 -> V_181 ) ;
}
V_116 = F_50 ( V_70 , V_4 ) ;
if ( V_116 ) {
F_2 ( V_4 , L_27
L_24 ) ;
goto V_182;
}
V_116 = F_59 ( V_70 , V_166 ) ;
if ( V_116 ) {
F_2 ( V_4 , L_28
L_24 ) ;
goto V_182;
}
V_116 = F_96 ( V_70 , & V_2 -> V_7 , & V_183 , 1 ) ;
if ( V_116 ) {
F_2 ( V_4 , L_29
L_24 ) ;
goto V_182;
}
if ( ! V_167 )
V_116 = F_71 ( V_70 ) ;
else {
V_170 = F_97 ( V_112 ) ;
V_168 = F_98 ( V_170 ) ;
V_116 = F_99 ( V_168 , V_70 ) ;
}
if ( V_116 ) {
F_2 ( V_4 , L_30 ) ;
goto V_182;
}
F_26 ( V_2 ) ;
return V_70 ;
V_182:
F_85 ( V_70 ) ;
V_179:
F_87 ( V_70 -> V_117 ) ;
V_49:
return F_15 ( V_116 ) ;
}
static int T_5 F_100 ( void )
{
V_127 =
F_101 ( & V_184 ) ;
V_126 =
F_101 ( & V_185 ) ;
if ( ! V_127 ) {
F_74 ( V_157 L_31 ) ;
return - V_186 ;
}
return 0 ;
}
static int T_6 F_102 ( void )
{
F_103 ( V_127 ) ;
F_103 ( V_126 ) ;
V_127 = NULL ;
V_126 = NULL ;
return 0 ;
}
static void F_104 ( unsigned int V_187 )
{
struct V_188 * V_189 ;
struct V_190 * V_191 ;
V_189 = & F_105 ( V_192 , V_187 ) ;
V_191 = F_106 ( V_193 ,
( void * ) V_189 , F_107 ( V_187 ) ,
L_32 , V_187 ) ;
if ( F_108 ( ! F_109 ( V_191 ) ) ) {
F_110 ( V_191 , V_187 ) ;
F_111 ( V_191 ) ;
F_112 ( & V_189 -> V_194 . V_195 ) ;
V_189 -> V_191 = V_191 ;
F_113 ( & V_189 -> V_194 . V_195 ) ;
}
}
static void F_114 ( unsigned int V_187 )
{
struct V_188 * V_189 ;
struct V_190 * V_191 ;
struct V_196 * V_197 ;
struct V_61 * V_62 ;
#ifdef F_115
struct V_188 * V_198 ;
unsigned V_199 = F_116 () ;
#endif
F_117 ( L_33 , V_187 ) ;
V_189 = & F_105 ( V_192 , V_187 ) ;
F_112 ( & V_189 -> V_194 . V_195 ) ;
V_191 = V_189 -> V_191 ;
V_189 -> V_191 = NULL ;
V_197 = V_189 -> V_200 ;
V_189 -> V_200 = NULL ;
V_189 -> V_201 = 0 ;
F_113 ( & V_189 -> V_194 . V_195 ) ;
#ifdef F_115
if ( V_187 != V_199 ) {
V_198 = & F_105 ( V_192 , V_199 ) ;
F_112 ( & V_198 -> V_194 . V_195 ) ;
if ( V_198 -> V_191 ) {
F_117 ( L_34 ,
V_187 , V_199 ) ;
while ( ( V_62 = F_118 ( & V_189 -> V_194 ) ) != NULL )
F_119 ( & V_198 -> V_194 , V_62 ) ;
F_113 ( & V_198 -> V_194 . V_195 ) ;
} else {
while ( ( V_62 = F_118 ( & V_189 -> V_194 ) ) != NULL )
F_120 ( V_62 ) ;
F_113 ( & V_198 -> V_194 . V_195 ) ;
}
} else {
F_112 ( & V_189 -> V_194 . V_195 ) ;
while ( ( V_62 = F_118 ( & V_189 -> V_194 ) ) != NULL )
F_120 ( V_62 ) ;
F_113 ( & V_189 -> V_194 . V_195 ) ;
}
F_121 () ;
#else
F_112 ( & V_189 -> V_194 . V_195 ) ;
while ( ( V_62 = F_118 ( & V_189 -> V_194 ) ) != NULL )
F_120 ( V_62 ) ;
F_113 ( & V_189 -> V_194 . V_195 ) ;
#endif
if ( V_191 )
F_122 ( V_191 ) ;
if ( V_197 )
F_123 ( V_197 ) ;
}
static int F_124 ( struct V_202 * V_203 ,
unsigned long V_204 , void * V_205 )
{
unsigned V_187 = ( unsigned long ) V_205 ;
switch ( V_204 ) {
case V_206 :
case V_207 :
F_117 ( L_35 , V_187 ) ;
F_104 ( V_187 ) ;
break;
case V_208 :
case V_209 :
F_117 ( L_36 , V_187 ) ;
F_114 ( V_187 ) ;
break;
default:
break;
}
return V_210 ;
}
static inline unsigned int F_125 ( void )
{
static unsigned int V_211 ;
V_211 = F_126 ( V_211 , V_212 ) ;
if ( V_211 >= V_213 )
V_211 = F_127 ( V_212 ) ;
return V_211 ;
}
static int V_38 ( struct V_61 * V_62 , struct V_3 * V_4 ,
struct V_63 * V_64 , struct V_3 * V_214 )
{
struct V_72 * V_70 ;
struct V_215 * V_216 ;
struct V_1 * V_2 ;
struct V_135 * V_136 ;
struct V_188 * V_217 ;
struct V_218 * V_219 ;
unsigned int V_187 ;
V_2 = F_25 ( V_64 , struct V_1 , V_36 ) ;
V_70 = V_2 -> V_7 . V_71 ;
if ( F_128 ( ! V_70 ) ) {
F_2 ( V_4 , L_37 ) ;
goto V_220;
}
if ( ! V_70 -> V_75 )
goto V_220;
F_2 ( V_4 , L_38
L_39 ,
V_62 -> V_221 , V_62 -> V_139 , V_62 -> V_222 , V_62 -> V_223 ,
F_129 ( V_62 ) , F_130 ( V_62 ) ,
V_62 -> V_224 , V_62 -> V_40 ? V_62 -> V_40 -> V_132 : L_40 ) ;
V_219 = F_131 ( V_62 ) ;
if ( F_132 ( & V_2 -> V_7 ) &&
F_133 ( V_219 -> V_225 , V_2 -> V_7 . V_226 ) ) {
F_2 ( V_4 , L_41 ,
V_219 -> V_225 ) ;
goto V_46;
}
if ( F_128 ( ( V_62 -> V_221 < V_227 ) ||
! F_134 ( V_62 , V_228 ) ) )
goto V_46;
F_135 ( V_62 , sizeof( struct V_106 ) ) ;
V_136 = (struct V_135 * ) F_136 ( V_62 ) ;
if ( F_137 ( & V_219 -> V_229 [ 3 ] ) != F_137 ( V_136 -> V_230 ) ) {
F_2 ( V_4 , L_42 ,
V_219 -> V_229 ) ;
goto V_46;
}
V_216 = F_138 ( V_62 ) ;
V_216 -> V_231 = V_70 ;
if ( F_137 ( V_136 -> V_232 ) & V_233 )
V_187 = F_68 ( V_136 -> V_234 ) & V_235 ;
else {
if ( F_68 ( V_136 -> V_143 ) == V_144 )
V_187 = F_125 () ;
else
V_187 = F_68 ( V_136 -> V_143 ) & V_235 ;
}
if ( V_187 >= V_213 )
goto V_46;
V_217 = & F_105 ( V_192 , V_187 ) ;
F_112 ( & V_217 -> V_194 . V_195 ) ;
if ( F_128 ( ! V_217 -> V_191 ) ) {
F_2 ( V_4 , L_43
L_44
L_45 ) ;
F_113 ( & V_217 -> V_194 . V_195 ) ;
V_187 = F_127 ( V_212 ) ;
V_217 = & F_105 ( V_192 , V_187 ) ;
F_112 ( & V_217 -> V_194 . V_195 ) ;
if ( ! V_217 -> V_191 ) {
F_113 ( & V_217 -> V_194 . V_195 ) ;
goto V_46;
}
}
if ( V_136 -> V_236 == V_237 &&
V_187 == F_139 () &&
F_140 ( & V_217 -> V_194 ) ) {
F_113 ( & V_217 -> V_194 . V_195 ) ;
F_141 ( V_62 ) ;
} else {
F_119 ( & V_217 -> V_194 , V_62 ) ;
if ( V_217 -> V_194 . V_69 == 1 )
F_111 ( V_217 -> V_191 ) ;
F_113 ( & V_217 -> V_194 . V_195 ) ;
}
return 0 ;
V_46:
F_142 ( V_70 -> V_238 , F_116 () ) -> V_239 ++ ;
F_121 () ;
V_220:
F_120 ( V_62 ) ;
return - 1 ;
}
static int F_143 ( struct V_61 * V_62 , int V_240 )
{
struct V_188 * V_217 ;
int V_116 ;
V_217 = & F_144 ( V_192 ) ;
V_116 = F_145 ( V_62 , V_240 , V_217 ) ;
F_146 ( V_192 ) ;
return V_116 ;
}
static int F_147 ( struct V_72 * V_70 , struct V_133 * V_134 )
{
int V_241 ;
T_2 V_242 ;
struct V_218 * V_219 ;
struct V_107 * V_243 ;
struct V_61 * V_62 ;
struct V_244 * V_245 ;
struct V_135 * V_136 ;
unsigned int V_246 ;
unsigned int V_240 ;
unsigned int V_247 ;
struct V_66 * V_67 = F_42 ( V_70 ) ;
struct V_1 * V_2 = V_67 -> V_73 ;
T_1 V_248 , V_249 ;
struct V_106 * V_250 ;
F_148 ( ( F_149 ( V_134 ) % sizeof( T_2 ) ) != 0 ) ;
V_136 = F_65 ( V_134 ) ;
V_62 = F_150 ( V_134 ) ;
V_241 = V_62 -> V_221 / V_251 ;
if ( ! V_70 -> V_75 ) {
F_120 ( V_62 ) ;
return 0 ;
}
if ( F_128 ( V_136 -> V_236 == V_252 ) &&
F_151 ( & V_2 -> V_7 , V_70 , V_62 ) )
return 0 ;
V_248 = F_152 ( V_134 ) ;
V_249 = F_153 ( V_134 ) ;
V_247 = sizeof( struct V_218 ) ;
V_246 = sizeof( struct V_106 ) ;
V_240 = sizeof( struct V_107 ) ;
V_241 = ( V_62 -> V_221 - V_240 + sizeof( V_242 ) ) / V_251 ;
if ( F_108 ( V_70 -> V_87 ) ) {
V_62 -> V_253 = V_254 ;
V_62 -> V_255 = F_154 ( V_62 ) ;
V_62 -> V_256 = V_62 -> V_221 ;
V_242 = 0 ;
} else {
V_62 -> V_253 = V_257 ;
V_242 = F_155 ( V_134 ) ;
}
if ( F_156 ( V_62 ) ) {
T_7 * V_258 ;
if ( F_143 ( V_62 , V_240 ) ) {
F_120 ( V_62 ) ;
return - V_51 ;
}
V_258 = & F_157 ( V_62 ) -> V_259 [ F_157 ( V_62 ) -> V_260 - 1 ] ;
V_243 = F_158 ( F_159 ( V_258 ) , V_261 )
+ V_258 -> V_262 ;
} else {
V_243 = (struct V_107 * ) F_160 ( V_62 , V_240 ) ;
}
memset ( V_243 , 0 , sizeof( * V_243 ) ) ;
V_243 -> V_263 = V_249 ;
V_243 -> V_264 = F_161 ( ~ V_242 ) ;
if ( F_156 ( V_62 ) ) {
F_162 ( V_243 , V_261 ) ;
V_243 = NULL ;
}
F_163 ( V_62 , V_247 + V_246 ) ;
F_164 ( V_62 ) ;
F_165 ( V_62 ) ;
V_62 -> V_265 = V_247 ;
V_62 -> V_266 = F_12 ( V_39 ) ;
V_62 -> V_267 = V_67 -> V_267 ;
if ( V_2 -> V_4 -> V_17 & V_22 &&
V_2 -> V_23 -> V_93 & V_268 ) {
V_62 -> V_269 = V_270 |
F_166 ( V_2 -> V_4 ) ;
V_62 -> V_40 = V_2 -> V_23 ;
} else
V_62 -> V_40 = V_2 -> V_4 ;
V_219 = F_131 ( V_62 ) ;
V_219 -> V_271 = F_12 ( V_39 ) ;
memcpy ( V_219 -> V_229 , V_2 -> V_7 . V_226 , V_12 ) ;
if ( V_2 -> V_7 . V_272 )
memcpy ( V_219 -> V_229 + 3 , V_136 -> V_230 , 3 ) ;
if ( F_128 ( V_2 -> V_7 . V_273 != V_144 ) )
memcpy ( V_219 -> V_225 , V_2 -> V_7 . V_26 , V_12 ) ;
else
memcpy ( V_219 -> V_225 , V_67 -> V_74 , V_12 ) ;
V_250 = (struct V_106 * ) ( V_219 + 1 ) ;
memset ( V_250 , 0 , sizeof( * V_250 ) ) ;
if ( V_274 )
F_167 ( V_250 , V_274 ) ;
V_250 -> V_275 = V_248 ;
if ( V_70 -> V_88 && F_168 ( V_134 ) ) {
F_157 ( V_62 ) -> V_276 = V_277 ;
F_157 ( V_62 ) -> V_278 = F_168 ( V_134 ) ;
} else {
F_157 ( V_62 ) -> V_276 = 0 ;
F_157 ( V_62 ) -> V_278 = 0 ;
}
V_245 = F_142 ( V_70 -> V_238 , F_116 () ) ;
V_245 -> V_279 ++ ;
V_245 -> V_280 += V_241 ;
F_121 () ;
V_231 ( V_134 ) = V_70 ;
F_38 ( V_67 , V_62 ) ;
return 0 ;
}
static void F_169 ( struct V_61 * V_62 )
{
F_170 ( & V_281 ) ;
}
static inline int F_171 ( struct V_72 * V_70 ,
struct V_133 * V_134 )
{
struct V_1 * V_2 ;
struct V_135 * V_136 ;
struct V_61 * V_62 = (struct V_61 * ) V_134 ;
struct V_244 * V_245 ;
if ( V_70 -> V_87 && V_62 -> V_253 == V_282 )
F_172 ( V_134 ) &= ~ V_283 ;
else
F_172 ( V_134 ) |= V_283 ;
V_136 = (struct V_135 * ) F_136 ( V_62 ) ;
V_136 = F_65 ( V_134 ) ;
if ( V_136 -> V_141 == V_284 && V_136 -> V_236 == V_237 )
return 0 ;
V_2 = ( (struct V_66 * ) F_42 ( V_70 ) ) -> V_73 ;
if ( F_132 ( & V_2 -> V_7 ) && F_173 ( V_134 ) == V_285 &&
F_137 ( V_136 -> V_286 ) == V_287 ) {
F_117 ( L_46 ) ;
return - V_108 ;
}
if ( ! ( F_172 ( V_134 ) & V_283 ) ||
F_174 ( F_175 ( V_134 ) ) == ~ F_176 ( ~ 0 , V_62 -> V_223 , V_62 -> V_221 ) ) {
F_172 ( V_134 ) &= ~ V_283 ;
return 0 ;
}
V_245 = F_142 ( V_70 -> V_238 , F_116 () ) ;
V_245 -> V_288 ++ ;
if ( V_245 -> V_288 < 5 )
F_74 ( V_289 L_47 ) ;
F_121 () ;
return - V_108 ;
}
static void F_141 ( struct V_61 * V_62 )
{
T_2 F_149 ;
struct V_72 * V_70 ;
struct V_215 * V_216 ;
struct V_244 * V_245 ;
struct V_107 V_197 ;
struct V_133 * V_134 ;
struct V_66 * V_67 ;
struct V_106 * V_250 ;
V_216 = F_138 ( V_62 ) ;
V_70 = V_216 -> V_231 ;
if ( F_128 ( ! V_70 ) ) {
if ( V_62 -> V_290 != F_169 )
F_2 ( V_62 -> V_40 , L_48 ) ;
F_120 ( V_62 ) ;
return;
}
F_2 ( V_62 -> V_40 , L_49
L_50 ,
V_62 -> V_221 , V_62 -> V_139 ,
V_62 -> V_222 , V_62 -> V_223 , F_129 ( V_62 ) ,
F_130 ( V_62 ) , V_62 -> V_224 ,
V_62 -> V_40 ? V_62 -> V_40 -> V_132 : L_40 ) ;
V_67 = F_42 ( V_70 ) ;
F_177 ( V_62 ) ;
V_250 = (struct V_106 * ) F_178 ( V_62 ) ;
V_245 = F_142 ( V_70 -> V_238 , F_116 () ) ;
if ( F_128 ( F_179 ( V_250 ) != V_274 ) ) {
if ( V_245 -> V_239 < 5 )
F_74 ( V_289 L_51
L_52
L_53
L_54
L_55 , F_179 ( V_250 ) ,
V_274 ) ;
goto V_291;
}
F_180 ( V_62 , sizeof( struct V_106 ) ) ;
F_149 = V_62 -> V_221 - sizeof( struct V_107 ) ;
V_245 -> V_292 ++ ;
V_245 -> V_293 += F_149 / V_251 ;
V_134 = (struct V_133 * ) V_62 ;
F_181 ( V_134 ) ;
V_231 ( V_134 ) = V_70 ;
F_152 ( V_134 ) = V_250 -> V_275 ;
if ( F_182 ( V_62 , F_149 , & V_197 , sizeof( V_197 ) ) )
goto V_291;
F_153 ( V_134 ) = V_197 . V_263 ;
F_175 ( V_134 ) = V_197 . V_264 ;
if ( F_183 ( V_62 , F_149 ) )
goto V_291;
if ( ! F_171 ( V_70 , V_134 ) ) {
F_121 () ;
F_184 ( V_70 , V_134 ) ;
return;
}
V_291:
V_245 -> V_239 ++ ;
F_121 () ;
F_120 ( V_62 ) ;
}
static int V_193 ( void * V_294 )
{
struct V_188 * V_189 = V_294 ;
struct V_61 * V_62 ;
F_185 ( V_295 , - 20 ) ;
while ( ! F_186 () ) {
F_112 ( & V_189 -> V_194 . V_195 ) ;
while ( ( V_62 = F_118 ( & V_189 -> V_194 ) ) == NULL ) {
F_187 ( V_296 ) ;
F_113 ( & V_189 -> V_194 . V_195 ) ;
F_188 () ;
F_187 ( V_297 ) ;
if ( F_186 () )
return 0 ;
F_112 ( & V_189 -> V_194 . V_195 ) ;
}
F_113 ( & V_189 -> V_194 . V_195 ) ;
F_141 ( V_62 ) ;
}
return 0 ;
}
static void F_189 ( void )
{
F_190 ( & V_298 ) ;
F_191 ( & V_299 ) ;
}
static void F_192 ( void )
{
F_193 ( & V_298 ) ;
F_194 ( & V_299 ) ;
}
static struct V_1 *
F_195 ( struct V_3 * V_4 )
{
struct V_1 * V_2 ;
struct V_3 * V_10 ;
F_72 (fcoe, &fcoe_hostlist, list) {
if ( V_2 -> V_4 -> V_17 & V_22 )
V_10 = F_3 ( V_2 -> V_4 ) ;
else
V_10 = V_2 -> V_4 ;
if ( V_4 == V_10 )
return V_2 ;
}
return NULL ;
}
static int F_196 ( struct V_202 * V_300 ,
T_8 V_301 , void * V_302 )
{
struct V_303 * V_304 = V_302 ;
struct V_1 * V_2 ;
struct V_3 * V_4 ;
struct V_66 * V_67 ;
int V_305 ;
if ( V_304 -> V_306 . V_307 != V_308 )
return V_210 ;
V_4 = F_197 ( & V_309 , V_304 -> V_310 ) ;
if ( ! V_4 )
return V_210 ;
V_2 = F_195 ( V_4 ) ;
F_22 ( V_4 ) ;
if ( ! V_2 )
return V_210 ;
if ( V_304 -> V_311 & V_312 )
V_305 = F_198 ( V_304 -> V_306 . V_267 ) - 1 ;
else
V_305 = V_304 -> V_306 . V_267 ;
if ( V_305 < 0 )
return V_210 ;
if ( V_304 -> V_306 . V_266 == V_43 ||
V_304 -> V_306 . V_266 == V_39 )
V_2 -> V_7 . V_267 = V_305 ;
if ( V_304 -> V_306 . V_266 == V_39 ) {
V_67 = F_42 ( V_2 -> V_7 . V_71 ) ;
V_67 -> V_267 = V_305 ;
}
return V_210 ;
}
static int F_199 ( struct V_202 * V_300 ,
T_8 V_301 , void * V_302 )
{
struct V_72 * V_70 = NULL ;
struct V_3 * V_4 = V_302 ;
struct V_1 * V_2 ;
struct V_66 * V_67 ;
struct V_244 * V_245 ;
T_2 V_313 = 1 ;
T_2 V_100 ;
int V_116 = V_210 ;
F_72 (fcoe, &fcoe_hostlist, list) {
if ( V_2 -> V_4 == V_4 ) {
V_70 = V_2 -> V_7 . V_71 ;
break;
}
}
if ( ! V_70 ) {
V_116 = V_314 ;
goto V_49;
}
switch ( V_301 ) {
case V_315 :
case V_316 :
V_313 = 0 ;
break;
case V_317 :
case V_318 :
break;
case V_319 :
if ( V_4 -> V_93 & V_104 )
break;
V_100 = V_4 -> V_103 - ( sizeof( struct V_106 ) +
sizeof( struct V_107 ) ) ;
if ( V_100 >= V_320 )
F_51 ( V_70 , V_100 ) ;
break;
case V_321 :
break;
case V_322 :
F_200 ( & V_2 -> V_323 ) ;
V_67 = F_42 ( V_2 -> V_7 . V_71 ) ;
F_201 ( V_324 , & V_67 -> V_177 ) ;
goto V_49;
break;
case V_325 :
F_47 ( V_70 , V_4 ) ;
break;
default:
F_2 ( V_4 , L_56
L_57 , V_301 ) ;
}
F_54 ( V_70 ) ;
if ( V_313 && ! F_202 ( V_70 ) )
F_203 ( & V_2 -> V_7 ) ;
else if ( F_204 ( & V_2 -> V_7 ) ) {
V_245 = F_142 ( V_70 -> V_238 , F_116 () ) ;
V_245 -> V_326 ++ ;
F_121 () ;
F_80 ( V_70 ) ;
}
V_49:
return V_116 ;
}
static int F_205 ( struct V_3 * V_4 )
{
struct V_1 * V_2 ;
int V_116 = 0 ;
F_48 ( & V_327 ) ;
F_31 () ;
V_2 = F_206 ( V_4 ) ;
F_36 () ;
if ( V_2 ) {
F_204 ( & V_2 -> V_7 ) ;
F_80 ( V_2 -> V_7 . V_71 ) ;
} else
V_116 = - V_186 ;
F_49 ( & V_327 ) ;
return V_116 ;
}
static int F_207 ( struct V_3 * V_4 )
{
struct V_1 * V_2 ;
int V_116 = 0 ;
F_48 ( & V_327 ) ;
F_31 () ;
V_2 = F_206 ( V_4 ) ;
F_36 () ;
if ( ! V_2 )
V_116 = - V_186 ;
else if ( ! F_202 ( V_2 -> V_7 . V_71 ) )
F_203 ( & V_2 -> V_7 ) ;
F_49 ( & V_327 ) ;
return V_116 ;
}
static int F_208 ( struct V_3 * V_4 )
{
struct V_1 * V_2 ;
struct V_72 * V_70 ;
struct V_66 * V_67 ;
int V_116 = 0 ;
F_48 ( & V_327 ) ;
F_31 () ;
V_2 = F_206 ( V_4 ) ;
if ( ! V_2 ) {
V_116 = - V_186 ;
goto V_328;
}
V_70 = V_2 -> V_7 . V_71 ;
V_67 = F_42 ( V_70 ) ;
F_200 ( & V_2 -> V_323 ) ;
F_201 ( V_324 , & V_67 -> V_177 ) ;
V_328:
F_36 () ;
F_49 ( & V_327 ) ;
return V_116 ;
}
static void V_178 ( struct V_329 * V_330 )
{
struct V_66 * V_67 ;
struct V_1 * V_2 ;
int V_167 = 0 ;
V_67 = F_25 ( V_330 , struct V_66 , V_177 ) ;
F_48 ( & V_327 ) ;
V_167 = V_67 -> V_70 -> V_112 ? 1 : 0 ;
V_2 = V_67 -> V_73 ;
F_76 ( V_67 -> V_70 ) ;
if ( ! V_167 )
F_30 ( V_2 ) ;
F_49 ( & V_327 ) ;
}
static bool F_209 ( struct V_3 * V_4 )
{
return true ;
}
static void F_210 ( struct V_1 * V_2 )
{
#ifdef F_211
int V_311 ;
T_1 V_331 , V_332 ;
struct V_3 * V_4 = V_2 -> V_23 ;
struct V_66 * V_67 = F_42 ( V_2 -> V_7 . V_71 ) ;
struct V_333 V_306 = {
. V_267 = 0 ,
. V_266 = V_39
} ;
if ( V_4 && V_4 -> V_334 && V_4 -> V_334 -> V_335 ) {
V_311 = V_4 -> V_334 -> V_335 ( V_4 ) ;
if ( V_311 & V_336 ) {
V_306 . V_307 = V_337 ;
V_332 = F_212 ( V_4 , & V_306 ) ;
V_306 . V_266 = V_43 ;
V_331 = F_212 ( V_4 , & V_306 ) ;
} else {
V_306 . V_307 = V_308 ;
V_332 = F_213 ( V_4 , & V_306 ) ;
V_306 . V_266 = V_43 ;
V_331 = F_213 ( V_4 , & V_306 ) ;
}
V_67 -> V_267 = F_198 ( V_332 ) ? F_198 ( V_332 ) - 1 : 0 ;
V_2 -> V_7 . V_267 = F_198 ( V_331 ) ? F_198 ( V_331 ) - 1 : V_67 -> V_267 ;
}
#endif
}
static int F_214 ( struct V_3 * V_4 , enum V_44 V_45 )
{
int V_116 = 0 ;
struct V_1 * V_2 ;
struct V_72 * V_70 ;
F_48 ( & V_327 ) ;
F_31 () ;
if ( F_215 ( V_4 ) ) {
V_116 = - V_338 ;
goto V_328;
}
V_2 = F_13 ( V_4 , V_45 ) ;
if ( F_109 ( V_2 ) ) {
V_116 = F_216 ( V_2 ) ;
goto V_328;
}
V_70 = F_91 ( V_2 , & V_4 -> V_40 , 0 ) ;
if ( F_109 ( V_70 ) ) {
F_74 ( V_157 L_58 ,
V_4 -> V_132 ) ;
V_116 = - V_339 ;
F_36 () ;
F_30 ( V_2 ) ;
goto V_340;
}
V_2 -> V_7 . V_71 = V_70 ;
F_210 ( V_2 ) ;
F_217 ( V_70 ) ;
V_70 -> V_341 = V_342 ;
F_218 ( V_70 ) ;
if ( ! F_202 ( V_70 ) )
F_203 ( & V_2 -> V_7 ) ;
V_328:
F_36 () ;
V_340:
F_49 ( & V_327 ) ;
return V_116 ;
}
static int F_54 ( struct V_72 * V_70 )
{
struct V_3 * V_4 = F_61 ( V_70 ) ;
struct V_343 V_344 ;
if ( ! F_219 ( V_4 , & V_344 ) ) {
V_70 -> V_345 &=
~ ( V_346 | V_347 ) ;
if ( V_344 . V_348 & ( V_349 |
V_350 ) )
V_70 -> V_345 |= V_346 ;
if ( V_344 . V_348 & V_351 )
V_70 -> V_345 |=
V_347 ;
switch ( F_220 ( & V_344 ) ) {
case V_352 :
V_70 -> V_353 = V_346 ;
break;
case V_354 :
V_70 -> V_353 = V_347 ;
break;
}
return 0 ;
}
return - 1 ;
}
static int F_202 ( struct V_72 * V_70 )
{
struct V_3 * V_4 = F_61 ( V_70 ) ;
if ( F_221 ( V_4 ) )
return 0 ;
return - 1 ;
}
static void F_81 ( struct V_72 * V_70 )
{
struct V_188 * V_355 ;
struct V_215 * V_216 ;
struct V_356 * V_323 ;
struct V_61 * V_62 , * V_357 ;
struct V_61 * V_222 ;
unsigned int V_187 ;
F_222 (cpu) {
V_355 = & F_105 ( V_192 , V_187 ) ;
F_112 ( & V_355 -> V_194 . V_195 ) ;
V_323 = & V_355 -> V_194 ;
V_222 = V_323 -> V_357 ;
for ( V_62 = V_222 ; V_62 != (struct V_61 * ) V_323 ;
V_62 = V_357 ) {
V_357 = V_62 -> V_357 ;
V_216 = F_138 ( V_62 ) ;
if ( V_216 -> V_231 == V_70 ) {
F_223 ( V_62 , V_323 ) ;
F_120 ( V_62 ) ;
}
}
if ( ! V_355 -> V_191 || ! F_224 ( V_187 ) ) {
F_113 ( & V_355 -> V_194 . V_195 ) ;
continue;
}
V_62 = F_225 ( 0 ) ;
if ( ! V_62 ) {
F_113 ( & V_355 -> V_194 . V_195 ) ;
continue;
}
V_62 -> V_290 = F_169 ;
F_119 ( & V_355 -> V_194 , V_62 ) ;
if ( V_355 -> V_194 . V_69 == 1 )
F_111 ( V_355 -> V_191 ) ;
F_113 ( & V_355 -> V_194 . V_195 ) ;
F_226 ( & V_281 ) ;
}
}
static int F_227 ( struct V_169 * V_170 )
{
struct V_72 * V_70 = F_98 ( V_170 ) ;
struct V_66 * V_67 = F_42 ( V_70 ) ;
struct V_1 * V_2 = V_67 -> V_73 ;
F_204 ( & V_2 -> V_7 ) ;
F_80 ( V_2 -> V_7 . V_71 ) ;
if ( ! F_202 ( V_2 -> V_7 . V_71 ) )
F_203 ( & V_2 -> V_7 ) ;
return 0 ;
}
static struct V_1 *
F_206 ( const struct V_3 * V_4 )
{
struct V_1 * V_2 ;
F_72 (fcoe, &fcoe_hostlist, list) {
if ( V_2 -> V_4 == V_4 )
return V_2 ;
}
return NULL ;
}
static struct V_72 * F_215 ( const struct V_3 * V_4 )
{
struct V_1 * V_2 ;
V_2 = F_206 ( V_4 ) ;
return ( V_2 ) ? V_2 -> V_7 . V_71 : NULL ;
}
static int F_217 ( const struct V_72 * V_70 )
{
struct V_1 * V_2 ;
struct V_66 * V_67 ;
V_2 = F_206 ( F_61 ( V_70 ) ) ;
if ( ! V_2 ) {
V_67 = F_42 ( V_70 ) ;
V_2 = V_67 -> V_73 ;
F_228 ( & V_2 -> V_323 , & V_358 ) ;
}
return 0 ;
}
static int T_5 F_229 ( void )
{
struct V_188 * V_189 ;
unsigned int V_187 ;
int V_116 = 0 ;
V_324 = F_230 ( L_59 , 0 , 0 ) ;
if ( ! V_324 )
return - V_51 ;
V_116 = F_231 ( & V_359 ) ;
if ( V_116 ) {
F_74 ( V_157 L_60
L_61 ) ;
return V_116 ;
}
F_48 ( & V_327 ) ;
F_222 (cpu) {
V_189 = & F_105 ( V_192 , V_187 ) ;
F_52 ( & V_189 -> V_194 ) ;
}
F_232 (cpu)
F_104 ( V_187 ) ;
V_116 = F_233 ( & V_360 ) ;
if ( V_116 )
goto V_361;
F_189 () ;
V_116 = F_100 () ;
if ( V_116 )
goto V_361;
F_49 ( & V_327 ) ;
return 0 ;
V_361:
F_232 (cpu) {
F_114 ( V_187 ) ;
}
F_49 ( & V_327 ) ;
F_234 ( V_324 ) ;
return V_116 ;
}
static void T_6 F_235 ( void )
{
struct V_1 * V_2 , * V_362 ;
struct V_66 * V_67 ;
unsigned int V_187 ;
F_48 ( & V_327 ) ;
F_192 () ;
F_31 () ;
F_236 (fcoe, tmp, &fcoe_hostlist, list) {
F_200 ( & V_2 -> V_323 ) ;
V_67 = F_42 ( V_2 -> V_7 . V_71 ) ;
F_201 ( V_324 , & V_67 -> V_177 ) ;
}
F_36 () ;
F_237 ( & V_360 ) ;
F_232 (cpu)
F_114 ( V_187 ) ;
F_49 ( & V_327 ) ;
F_234 ( V_324 ) ;
F_102 () ;
F_238 ( & V_359 ) ;
}
static void F_239 ( struct V_363 * V_364 , struct V_133 * V_134 , void * V_294 )
{
struct V_5 * V_6 = V_294 ;
struct V_365 * V_366 = F_240 ( V_364 ) ;
struct V_72 * V_70 = V_366 -> V_71 ;
T_1 * V_367 ;
if ( F_109 ( V_134 ) )
goto V_368;
V_367 = F_241 ( V_134 ) -> V_369 ;
if ( F_43 ( V_367 ) )
F_242 ( V_6 , V_70 , V_134 ) ;
if ( ! F_43 ( V_367 ) )
V_57 ( V_70 , V_367 ) ;
V_368:
F_243 ( V_364 , V_134 , V_70 ) ;
}
static void F_244 ( struct V_363 * V_364 , struct V_133 * V_134 , void * V_294 )
{
struct V_72 * V_70 = V_294 ;
static T_1 V_370 [ V_12 ] = { 0 } ;
if ( ! F_109 ( V_134 ) )
V_57 ( V_70 , V_370 ) ;
F_245 ( V_364 , V_134 , V_70 ) ;
}
static struct V_363 * F_246 ( struct V_72 * V_70 , T_2 V_371 ,
struct V_133 * V_134 , unsigned int V_372 ,
void (* F_247)( struct V_363 * ,
struct V_133 * ,
void * ) ,
void * V_294 , T_2 V_373 )
{
struct V_66 * V_67 = F_42 ( V_70 ) ;
struct V_1 * V_2 = V_67 -> V_73 ;
struct V_5 * V_6 = & V_2 -> V_7 ;
struct V_135 * V_136 = F_65 ( V_134 ) ;
switch ( V_372 ) {
case V_374 :
case V_375 :
if ( V_70 -> V_376 )
break;
return F_248 ( V_70 , V_371 , V_134 , V_372 , F_239 ,
V_6 , V_373 ) ;
case V_285 :
if ( F_137 ( V_136 -> V_230 ) != V_287 )
break;
return F_248 ( V_70 , V_371 , V_134 , V_372 , F_244 ,
V_70 , V_373 ) ;
}
return F_248 ( V_70 , V_371 , V_134 , V_372 , F_247 , V_294 , V_373 ) ;
}
static int F_249 ( struct V_171 * V_112 , bool V_377 )
{
struct V_169 * V_170 = F_97 ( V_112 ) ;
struct V_72 * V_168 = F_98 ( V_170 ) ;
struct V_66 * V_67 = F_42 ( V_168 ) ;
struct V_1 * V_2 = V_67 -> V_73 ;
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_72 * V_378 ;
int V_116 ;
char V_379 [ 32 ] ;
V_116 = F_250 ( V_112 ) ;
if ( V_116 ) {
F_251 ( V_112 -> V_181 , V_379 , sizeof( V_379 ) ) ;
F_74 ( V_157 L_62
L_63 ,
V_379 ) ;
return V_116 ;
}
F_48 ( & V_327 ) ;
F_31 () ;
V_378 = F_91 ( V_2 , & V_112 -> V_40 , 1 ) ;
F_36 () ;
F_49 ( & V_327 ) ;
if ( F_109 ( V_378 ) ) {
F_74 ( V_157 L_64 ,
V_4 -> V_132 ) ;
return - V_339 ;
}
if ( V_377 ) {
F_252 ( V_112 , V_380 ) ;
} else {
V_378 -> V_341 = V_342 ;
F_218 ( V_378 ) ;
F_253 ( V_378 ) ;
}
return 0 ;
}
static int F_254 ( struct V_171 * V_112 )
{
struct V_169 * V_170 = F_97 ( V_112 ) ;
struct V_72 * V_168 = F_98 ( V_170 ) ;
struct V_72 * V_378 = V_112 -> V_381 ;
struct V_66 * V_67 = F_42 ( V_378 ) ;
F_48 ( & V_168 -> V_92 ) ;
F_200 ( & V_378 -> V_323 ) ;
F_49 ( & V_168 -> V_92 ) ;
F_201 ( V_324 , & V_67 -> V_177 ) ;
return 0 ;
}
static int F_255 ( struct V_171 * V_112 , bool V_382 )
{
struct V_72 * V_70 = V_112 -> V_381 ;
if ( V_382 ) {
F_252 ( V_112 , V_380 ) ;
F_77 ( V_70 ) ;
} else {
V_70 -> V_341 = V_342 ;
F_218 ( V_70 ) ;
F_253 ( V_70 ) ;
}
return 0 ;
}
static void F_256 ( struct V_171 * V_112 )
{
struct V_72 * V_70 = V_112 -> V_381 ;
struct V_133 * V_134 ;
T_9 V_221 ;
snprintf ( F_63 ( V_70 -> V_117 ) , V_129 ,
L_65 , V_130 , V_131 ,
F_61 ( V_70 ) -> V_132 , V_112 -> V_383 ) ;
if ( V_70 -> V_384 != V_385 )
return;
V_221 = F_257 ( F_63 ( V_70 -> V_117 ) , 255 ) ;
V_134 = F_258 ( V_70 ,
sizeof( struct V_386 ) +
sizeof( struct V_387 ) + V_221 ) ;
if ( ! V_134 )
return;
V_70 -> V_388 . V_389 ( V_70 , V_390 , V_134 , V_391 ,
NULL , NULL , 3 * V_70 -> V_80 ) ;
}
static void F_259 ( struct V_72 * V_70 ,
struct V_392 * V_393 )
{
struct V_3 * V_4 = F_61 ( V_70 ) ;
F_260 ( V_70 , V_393 , V_4 ) ;
}
static void F_261 ( struct V_72 * V_70 ,
T_2 V_394 , struct V_133 * V_134 )
{
struct V_66 * V_67 = F_42 ( V_70 ) ;
struct V_1 * V_2 = V_67 -> V_73 ;
if ( V_134 && F_173 ( V_134 ) == V_374 )
F_242 ( & V_2 -> V_7 , V_70 , V_134 ) ;
}
