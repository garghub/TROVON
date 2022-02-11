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
void F_30 ( struct V_1 * V_2 )
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
bool F_64 ( struct V_133 * V_134 )
{
struct V_135 * V_136 = F_65 ( V_134 ) ;
struct V_137 * V_138 ;
if ( F_66 ( F_67 ( V_134 ) ) &&
( F_67 ( V_134 ) -> V_139 > V_140 ) )
return true ;
else if ( ! ( F_68 ( V_136 -> V_141 ) & V_142 ) ) {
V_138 = F_69 ( V_134 , sizeof( * V_138 ) ) ;
if ( F_70 ( V_136 -> V_143 ) == V_144 &&
V_138 && ( F_71 ( V_138 -> V_145 ) > V_140 ) &&
( V_138 -> V_146 & V_147 ) )
return true ;
}
return false ;
}
static inline int F_72 ( struct V_72 * V_70 )
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
F_73 (oldfcoe, &fcoe_hostlist, list) {
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
if ( ! F_74 ( V_70 , V_2 -> V_156 , F_64 ) ) {
F_75 ( V_157 L_14
L_15 ,
V_2 -> V_156 , V_2 -> V_4 -> V_132 ) ;
return - V_51 ;
}
} else {
V_2 -> V_156 = F_76 ( V_70 , V_158 ,
V_152 , V_70 -> V_90 ,
F_64 ) ;
if ( ! V_2 -> V_156 ) {
F_75 ( V_157 L_16
L_17 ,
V_2 -> V_4 -> V_132 ) ;
return - V_51 ;
}
}
V_151 += V_70 -> V_90 + 1 ;
V_155:
if ( ! F_76 ( V_70 , V_158 , V_151 , V_153 , NULL ) ) {
F_75 ( V_157 L_18
L_19 , V_2 -> V_4 -> V_132 ) ;
return - V_51 ;
}
return 0 ;
}
static void F_77 ( struct V_72 * V_70 )
{
struct V_66 * V_67 = F_42 ( V_70 ) ;
struct V_1 * V_2 = V_67 -> V_73 ;
struct V_3 * V_4 = V_2 -> V_4 ;
F_2 ( V_4 , L_20 ) ;
F_78 ( V_70 ) ;
F_79 ( V_70 ) ;
F_80 ( & V_67 -> V_110 ) ;
F_81 ( V_70 ) ;
F_31 () ;
if ( ! F_43 ( V_67 -> V_74 ) )
F_34 ( V_4 , V_67 -> V_74 ) ;
F_36 () ;
F_28 ( V_2 ) ;
F_82 ( V_70 ) ;
F_83 ( V_70 -> V_117 ) ;
F_84 ( V_70 -> V_117 ) ;
F_85 ( V_70 ) ;
F_86 ( V_70 ) ;
F_87 ( V_70 ) ;
F_88 ( V_70 -> V_117 ) ;
}
static int F_89 ( struct V_72 * V_70 , T_4 V_159 ,
struct V_160 * V_161 , unsigned int V_162 )
{
struct V_3 * V_4 = F_61 ( V_70 ) ;
if ( V_4 -> V_15 -> V_163 )
return V_4 -> V_15 -> V_163 ( V_4 ,
V_159 , V_161 ,
V_162 ) ;
return 0 ;
}
static int F_90 ( struct V_72 * V_70 , T_4 V_159 ,
struct V_160 * V_161 , unsigned int V_162 )
{
struct V_3 * V_4 = F_61 ( V_70 ) ;
if ( V_4 -> V_15 -> V_164 )
return V_4 -> V_15 -> V_164 ( V_4 , V_159 ,
V_161 , V_162 ) ;
return 0 ;
}
static int F_91 ( struct V_72 * V_70 , T_4 V_159 )
{
struct V_3 * V_4 = F_61 ( V_70 ) ;
if ( V_4 -> V_15 -> V_165 )
return V_4 -> V_15 -> V_165 ( V_4 , V_159 ) ;
return 0 ;
}
static struct V_72 * F_92 ( struct V_1 * V_2 ,
struct V_115 * V_166 , int V_167 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_72 * V_70 , * V_168 ;
struct V_66 * V_67 ;
struct V_169 * V_170 ;
int V_116 ;
struct V_171 * V_112 = F_93 ( V_166 ) ;
F_2 ( V_4 , L_21 ) ;
if ( ! V_167 )
V_70 = F_94 ( & V_172 , sizeof( * V_67 ) ) ;
else
V_70 = F_95 ( V_112 , sizeof( * V_67 ) ) ;
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
F_96 ( & V_67 -> V_177 , V_178 ) ;
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
V_116 = F_97 ( V_70 , & V_2 -> V_7 , & V_183 , 1 ) ;
if ( V_116 ) {
F_2 ( V_4 , L_29
L_24 ) ;
goto V_182;
}
if ( ! V_167 )
V_116 = F_72 ( V_70 ) ;
else {
V_170 = F_98 ( V_112 ) ;
V_168 = F_99 ( V_170 ) ;
V_116 = F_100 ( V_168 , V_70 ) ;
}
if ( V_116 ) {
F_2 ( V_4 , L_30 ) ;
goto V_182;
}
F_26 ( V_2 ) ;
return V_70 ;
V_182:
F_86 ( V_70 ) ;
V_179:
F_88 ( V_70 -> V_117 ) ;
V_49:
return F_15 ( V_116 ) ;
}
static int T_5 F_101 ( void )
{
V_127 =
F_102 ( & V_184 ) ;
V_126 =
F_102 ( & V_185 ) ;
if ( ! V_127 ) {
F_75 ( V_157 L_31 ) ;
return - V_186 ;
}
return 0 ;
}
int T_6 F_103 ( void )
{
F_104 ( V_127 ) ;
F_104 ( V_126 ) ;
V_127 = NULL ;
V_126 = NULL ;
return 0 ;
}
static void F_105 ( unsigned int V_187 )
{
struct V_188 * V_189 ;
struct V_190 * V_191 ;
V_189 = & F_106 ( V_192 , V_187 ) ;
V_191 = F_107 ( V_193 ,
( void * ) V_189 , F_108 ( V_187 ) ,
L_32 , V_187 ) ;
if ( F_109 ( ! F_110 ( V_191 ) ) ) {
F_111 ( V_191 , V_187 ) ;
F_112 ( V_191 ) ;
F_113 ( & V_189 -> V_194 . V_195 ) ;
V_189 -> V_191 = V_191 ;
F_114 ( & V_189 -> V_194 . V_195 ) ;
}
}
static void F_115 ( unsigned int V_187 )
{
struct V_188 * V_189 ;
struct V_190 * V_191 ;
struct V_196 * V_197 ;
struct V_61 * V_62 ;
#ifdef F_116
struct V_188 * V_198 ;
unsigned V_199 = F_117 () ;
#endif
F_118 ( L_33 , V_187 ) ;
V_189 = & F_106 ( V_192 , V_187 ) ;
F_113 ( & V_189 -> V_194 . V_195 ) ;
V_191 = V_189 -> V_191 ;
V_189 -> V_191 = NULL ;
V_197 = V_189 -> V_200 ;
V_189 -> V_200 = NULL ;
V_189 -> V_201 = 0 ;
F_114 ( & V_189 -> V_194 . V_195 ) ;
#ifdef F_116
if ( V_187 != V_199 ) {
V_198 = & F_106 ( V_192 , V_199 ) ;
F_113 ( & V_198 -> V_194 . V_195 ) ;
if ( V_198 -> V_191 ) {
F_118 ( L_34 ,
V_187 , V_199 ) ;
while ( ( V_62 = F_119 ( & V_189 -> V_194 ) ) != NULL )
F_120 ( & V_198 -> V_194 , V_62 ) ;
F_114 ( & V_198 -> V_194 . V_195 ) ;
} else {
while ( ( V_62 = F_119 ( & V_189 -> V_194 ) ) != NULL )
F_121 ( V_62 ) ;
F_114 ( & V_198 -> V_194 . V_195 ) ;
}
} else {
F_113 ( & V_189 -> V_194 . V_195 ) ;
while ( ( V_62 = F_119 ( & V_189 -> V_194 ) ) != NULL )
F_121 ( V_62 ) ;
F_114 ( & V_189 -> V_194 . V_195 ) ;
}
F_122 () ;
#else
F_113 ( & V_189 -> V_194 . V_195 ) ;
while ( ( V_62 = F_119 ( & V_189 -> V_194 ) ) != NULL )
F_121 ( V_62 ) ;
F_114 ( & V_189 -> V_194 . V_195 ) ;
#endif
if ( V_191 )
F_123 ( V_191 ) ;
if ( V_197 )
F_124 ( V_197 ) ;
}
static int F_125 ( struct V_202 * V_203 ,
unsigned long V_204 , void * V_205 )
{
unsigned V_187 = ( unsigned long ) V_205 ;
switch ( V_204 ) {
case V_206 :
case V_207 :
F_118 ( L_35 , V_187 ) ;
F_105 ( V_187 ) ;
break;
case V_208 :
case V_209 :
F_118 ( L_36 , V_187 ) ;
F_115 ( V_187 ) ;
break;
default:
break;
}
return V_210 ;
}
static inline unsigned int F_126 ( void )
{
static unsigned int V_211 ;
V_211 = F_127 ( V_211 , V_212 ) ;
if ( V_211 >= V_213 )
V_211 = F_128 ( V_212 ) ;
return V_211 ;
}
int V_38 ( struct V_61 * V_62 , struct V_3 * V_4 ,
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
if ( F_129 ( ! V_70 ) ) {
F_2 ( V_4 , L_37 ) ;
goto V_220;
}
if ( ! V_70 -> V_75 )
goto V_220;
F_2 ( V_4 , L_38
L_39 ,
V_62 -> V_221 , V_62 -> V_139 , V_62 -> V_222 , V_62 -> V_223 ,
F_130 ( V_62 ) , F_131 ( V_62 ) ,
V_62 -> V_224 , V_62 -> V_40 ? V_62 -> V_40 -> V_132 : L_40 ) ;
V_219 = F_132 ( V_62 ) ;
if ( F_133 ( & V_2 -> V_7 ) &&
F_134 ( V_219 -> V_225 , V_2 -> V_7 . V_226 ) ) {
F_2 ( V_4 , L_41 ,
V_219 -> V_225 ) ;
goto V_46;
}
if ( F_129 ( ( V_62 -> V_221 < V_227 ) ||
! F_135 ( V_62 , V_228 ) ) )
goto V_46;
F_136 ( V_62 , sizeof( struct V_106 ) ) ;
V_136 = (struct V_135 * ) F_137 ( V_62 ) ;
if ( F_68 ( & V_219 -> V_229 [ 3 ] ) != F_68 ( V_136 -> V_230 ) ) {
F_2 ( V_4 , L_42 ,
V_219 -> V_229 ) ;
goto V_46;
}
V_216 = F_138 ( V_62 ) ;
V_216 -> V_231 = V_70 ;
if ( F_68 ( V_136 -> V_141 ) & V_142 )
V_187 = F_70 ( V_136 -> V_232 ) & V_233 ;
else {
if ( F_70 ( V_136 -> V_143 ) == V_144 )
V_187 = F_126 () ;
else
V_187 = F_70 ( V_136 -> V_143 ) & V_233 ;
}
if ( V_187 >= V_213 )
goto V_46;
V_217 = & F_106 ( V_192 , V_187 ) ;
F_113 ( & V_217 -> V_194 . V_195 ) ;
if ( F_129 ( ! V_217 -> V_191 ) ) {
F_2 ( V_4 , L_43
L_44
L_45 ) ;
F_114 ( & V_217 -> V_194 . V_195 ) ;
V_187 = F_128 ( V_212 ) ;
V_217 = & F_106 ( V_192 , V_187 ) ;
F_113 ( & V_217 -> V_194 . V_195 ) ;
if ( ! V_217 -> V_191 ) {
F_114 ( & V_217 -> V_194 . V_195 ) ;
goto V_46;
}
}
if ( V_136 -> V_234 == V_235 &&
V_187 == F_139 () &&
F_140 ( & V_217 -> V_194 ) ) {
F_114 ( & V_217 -> V_194 . V_195 ) ;
F_141 ( V_62 ) ;
} else {
F_120 ( & V_217 -> V_194 , V_62 ) ;
if ( V_217 -> V_194 . V_69 == 1 )
F_112 ( V_217 -> V_191 ) ;
F_114 ( & V_217 -> V_194 . V_195 ) ;
}
return 0 ;
V_46:
F_142 ( V_70 -> V_236 , F_117 () ) -> V_237 ++ ;
F_122 () ;
V_220:
F_121 ( V_62 ) ;
return - 1 ;
}
static int F_143 ( struct V_61 * V_62 , int V_238 )
{
struct V_188 * V_217 ;
int V_116 ;
V_217 = & F_144 ( V_192 ) ;
V_116 = F_145 ( V_62 , V_238 , V_217 ) ;
F_146 ( V_192 ) ;
return V_116 ;
}
int F_147 ( struct V_72 * V_70 , struct V_133 * V_134 )
{
int V_239 ;
T_2 V_240 ;
struct V_218 * V_219 ;
struct V_107 * V_241 ;
struct V_61 * V_62 ;
struct V_242 * V_243 ;
struct V_135 * V_136 ;
unsigned int V_244 ;
unsigned int V_238 ;
unsigned int V_245 ;
struct V_66 * V_67 = F_42 ( V_70 ) ;
struct V_1 * V_2 = V_67 -> V_73 ;
T_1 V_246 , V_247 ;
struct V_106 * V_248 ;
F_148 ( ( F_149 ( V_134 ) % sizeof( T_2 ) ) != 0 ) ;
V_136 = F_65 ( V_134 ) ;
V_62 = F_150 ( V_134 ) ;
V_239 = V_62 -> V_221 / V_249 ;
if ( ! V_70 -> V_75 ) {
F_121 ( V_62 ) ;
return 0 ;
}
if ( F_129 ( V_136 -> V_234 == V_250 ) &&
F_151 ( & V_2 -> V_7 , V_70 , V_62 ) )
return 0 ;
V_246 = F_152 ( V_134 ) ;
V_247 = F_153 ( V_134 ) ;
V_245 = sizeof( struct V_218 ) ;
V_244 = sizeof( struct V_106 ) ;
V_238 = sizeof( struct V_107 ) ;
V_239 = ( V_62 -> V_221 - V_238 + sizeof( V_240 ) ) / V_249 ;
if ( F_109 ( V_70 -> V_87 ) ) {
V_62 -> V_251 = V_252 ;
V_62 -> V_253 = F_154 ( V_62 ) ;
V_62 -> V_254 = V_62 -> V_221 ;
V_240 = 0 ;
} else {
V_62 -> V_251 = V_255 ;
V_240 = F_155 ( V_134 ) ;
}
if ( F_156 ( V_62 ) ) {
T_7 * V_256 ;
if ( F_143 ( V_62 , V_238 ) ) {
F_121 ( V_62 ) ;
return - V_51 ;
}
V_256 = & F_157 ( V_62 ) -> V_257 [ F_157 ( V_62 ) -> V_258 - 1 ] ;
V_241 = F_158 ( F_159 ( V_256 ) , V_259 )
+ V_256 -> V_260 ;
} else {
V_241 = (struct V_107 * ) F_160 ( V_62 , V_238 ) ;
}
memset ( V_241 , 0 , sizeof( * V_241 ) ) ;
V_241 -> V_261 = V_247 ;
V_241 -> V_262 = F_161 ( ~ V_240 ) ;
if ( F_156 ( V_62 ) ) {
F_162 ( V_241 , V_259 ) ;
V_241 = NULL ;
}
F_163 ( V_62 , V_245 + V_244 ) ;
F_164 ( V_62 ) ;
F_165 ( V_62 ) ;
V_62 -> V_263 = V_245 ;
V_62 -> V_264 = F_12 ( V_39 ) ;
V_62 -> V_265 = V_67 -> V_265 ;
if ( V_2 -> V_4 -> V_17 & V_22 &&
V_2 -> V_23 -> V_93 & V_266 ) {
V_62 -> V_267 = V_268 |
F_166 ( V_2 -> V_4 ) ;
V_62 -> V_40 = V_2 -> V_23 ;
} else
V_62 -> V_40 = V_2 -> V_4 ;
V_219 = F_132 ( V_62 ) ;
V_219 -> V_269 = F_12 ( V_39 ) ;
memcpy ( V_219 -> V_229 , V_2 -> V_7 . V_226 , V_12 ) ;
if ( V_2 -> V_7 . V_270 )
memcpy ( V_219 -> V_229 + 3 , V_136 -> V_230 , 3 ) ;
if ( F_129 ( V_2 -> V_7 . V_271 != V_144 ) )
memcpy ( V_219 -> V_225 , V_2 -> V_7 . V_26 , V_12 ) ;
else
memcpy ( V_219 -> V_225 , V_67 -> V_74 , V_12 ) ;
V_248 = (struct V_106 * ) ( V_219 + 1 ) ;
memset ( V_248 , 0 , sizeof( * V_248 ) ) ;
if ( V_272 )
F_167 ( V_248 , V_272 ) ;
V_248 -> V_273 = V_246 ;
if ( V_70 -> V_88 && F_168 ( V_134 ) ) {
F_157 ( V_62 ) -> V_274 = V_275 ;
F_157 ( V_62 ) -> V_276 = F_168 ( V_134 ) ;
} else {
F_157 ( V_62 ) -> V_274 = 0 ;
F_157 ( V_62 ) -> V_276 = 0 ;
}
V_243 = F_142 ( V_70 -> V_236 , F_117 () ) ;
V_243 -> V_277 ++ ;
V_243 -> V_278 += V_239 ;
F_122 () ;
V_231 ( V_134 ) = V_70 ;
F_38 ( V_67 , V_62 ) ;
return 0 ;
}
static void F_169 ( struct V_61 * V_62 )
{
F_170 ( & V_279 ) ;
}
static inline int F_171 ( struct V_72 * V_70 ,
struct V_133 * V_134 )
{
struct V_1 * V_2 ;
struct V_135 * V_136 ;
struct V_61 * V_62 = (struct V_61 * ) V_134 ;
struct V_242 * V_243 ;
if ( V_70 -> V_87 && V_62 -> V_251 == V_280 )
F_172 ( V_134 ) &= ~ V_281 ;
else
F_172 ( V_134 ) |= V_281 ;
V_136 = (struct V_135 * ) F_137 ( V_62 ) ;
V_136 = F_65 ( V_134 ) ;
if ( V_136 -> V_282 == V_283 && V_136 -> V_234 == V_235 )
return 0 ;
V_2 = ( (struct V_66 * ) F_42 ( V_70 ) ) -> V_73 ;
if ( F_133 ( & V_2 -> V_7 ) && F_173 ( V_134 ) == V_284 &&
F_68 ( V_136 -> V_285 ) == V_286 ) {
F_118 ( L_46 ) ;
return - V_108 ;
}
if ( ! ( F_172 ( V_134 ) & V_281 ) ||
F_174 ( F_175 ( V_134 ) ) == ~ F_176 ( ~ 0 , V_62 -> V_223 , V_62 -> V_221 ) ) {
F_172 ( V_134 ) &= ~ V_281 ;
return 0 ;
}
V_243 = F_142 ( V_70 -> V_236 , F_117 () ) ;
V_243 -> V_287 ++ ;
if ( V_243 -> V_287 < 5 )
F_75 ( V_288 L_47 ) ;
F_122 () ;
return - V_108 ;
}
static void F_141 ( struct V_61 * V_62 )
{
T_2 F_149 ;
struct V_72 * V_70 ;
struct V_215 * V_216 ;
struct V_242 * V_243 ;
struct V_107 V_197 ;
struct V_133 * V_134 ;
struct V_66 * V_67 ;
struct V_106 * V_248 ;
V_216 = F_138 ( V_62 ) ;
V_70 = V_216 -> V_231 ;
if ( F_129 ( ! V_70 ) ) {
if ( V_62 -> V_289 != F_169 )
F_2 ( V_62 -> V_40 , L_48 ) ;
F_121 ( V_62 ) ;
return;
}
F_2 ( V_62 -> V_40 , L_49
L_50 ,
V_62 -> V_221 , V_62 -> V_139 ,
V_62 -> V_222 , V_62 -> V_223 , F_130 ( V_62 ) ,
F_131 ( V_62 ) , V_62 -> V_224 ,
V_62 -> V_40 ? V_62 -> V_40 -> V_132 : L_40 ) ;
V_67 = F_42 ( V_70 ) ;
if ( F_156 ( V_62 ) )
F_177 ( V_62 ) ;
V_248 = (struct V_106 * ) F_178 ( V_62 ) ;
V_243 = F_142 ( V_70 -> V_236 , F_117 () ) ;
if ( F_129 ( F_179 ( V_248 ) != V_272 ) ) {
if ( V_243 -> V_237 < 5 )
F_75 ( V_288 L_51
L_52
L_53
L_54
L_55 , F_179 ( V_248 ) ,
V_272 ) ;
goto V_290;
}
F_180 ( V_62 , sizeof( struct V_106 ) ) ;
F_149 = V_62 -> V_221 - sizeof( struct V_107 ) ;
V_243 -> V_291 ++ ;
V_243 -> V_292 += F_149 / V_249 ;
V_134 = (struct V_133 * ) V_62 ;
F_181 ( V_134 ) ;
V_231 ( V_134 ) = V_70 ;
F_152 ( V_134 ) = V_248 -> V_273 ;
if ( F_182 ( V_62 , F_149 , & V_197 , sizeof( V_197 ) ) )
goto V_290;
F_153 ( V_134 ) = V_197 . V_261 ;
F_175 ( V_134 ) = V_197 . V_262 ;
if ( F_183 ( V_62 , F_149 ) )
goto V_290;
if ( ! F_171 ( V_70 , V_134 ) ) {
F_122 () ;
F_184 ( V_70 , V_134 ) ;
return;
}
V_290:
V_243 -> V_237 ++ ;
F_122 () ;
F_121 ( V_62 ) ;
}
int V_193 ( void * V_293 )
{
struct V_188 * V_189 = V_293 ;
struct V_61 * V_62 ;
F_185 ( V_294 , - 20 ) ;
while ( ! F_186 () ) {
F_113 ( & V_189 -> V_194 . V_195 ) ;
while ( ( V_62 = F_119 ( & V_189 -> V_194 ) ) == NULL ) {
F_187 ( V_295 ) ;
F_114 ( & V_189 -> V_194 . V_195 ) ;
F_188 () ;
F_187 ( V_296 ) ;
if ( F_186 () )
return 0 ;
F_113 ( & V_189 -> V_194 . V_195 ) ;
}
F_114 ( & V_189 -> V_194 . V_195 ) ;
F_141 ( V_62 ) ;
}
return 0 ;
}
static void F_189 ( void )
{
F_190 ( & V_297 ) ;
F_191 ( & V_298 ) ;
}
static void F_192 ( void )
{
F_193 ( & V_297 ) ;
F_194 ( & V_298 ) ;
}
static struct V_1 *
F_195 ( struct V_3 * V_4 )
{
struct V_1 * V_2 ;
struct V_3 * V_10 ;
F_73 (fcoe, &fcoe_hostlist, list) {
if ( V_2 -> V_4 -> V_17 & V_22 )
V_10 = F_3 ( V_2 -> V_4 ) ;
else
V_10 = V_2 -> V_4 ;
if ( V_4 == V_10 )
return V_2 ;
}
return NULL ;
}
static int F_196 ( struct V_202 * V_299 ,
T_8 V_300 , void * V_301 )
{
struct V_302 * V_303 = V_301 ;
struct V_1 * V_2 ;
struct V_3 * V_4 ;
struct V_66 * V_67 ;
int V_304 ;
if ( V_303 -> V_305 . V_306 != V_307 )
return V_210 ;
V_4 = F_197 ( & V_308 , V_303 -> V_309 ) ;
if ( ! V_4 )
return V_210 ;
V_2 = F_195 ( V_4 ) ;
F_22 ( V_4 ) ;
if ( ! V_2 )
return V_210 ;
if ( V_303 -> V_310 & V_311 )
V_304 = F_198 ( V_303 -> V_305 . V_265 ) - 1 ;
else
V_304 = V_303 -> V_305 . V_265 ;
if ( V_304 < 0 )
return V_210 ;
if ( V_303 -> V_305 . V_264 == V_43 ||
V_303 -> V_305 . V_264 == V_39 )
V_2 -> V_7 . V_265 = V_304 ;
if ( V_303 -> V_305 . V_264 == V_39 ) {
V_67 = F_42 ( V_2 -> V_7 . V_71 ) ;
V_67 -> V_265 = V_304 ;
}
return V_210 ;
}
static int F_199 ( struct V_202 * V_299 ,
T_8 V_300 , void * V_301 )
{
struct V_72 * V_70 = NULL ;
struct V_3 * V_4 = V_301 ;
struct V_1 * V_2 ;
struct V_66 * V_67 ;
struct V_242 * V_243 ;
T_2 V_312 = 1 ;
T_2 V_100 ;
int V_116 = V_210 ;
F_73 (fcoe, &fcoe_hostlist, list) {
if ( V_2 -> V_4 == V_4 ) {
V_70 = V_2 -> V_7 . V_71 ;
break;
}
}
if ( ! V_70 ) {
V_116 = V_313 ;
goto V_49;
}
switch ( V_300 ) {
case V_314 :
case V_315 :
V_312 = 0 ;
break;
case V_316 :
case V_317 :
break;
case V_318 :
if ( V_4 -> V_93 & V_104 )
break;
V_100 = V_4 -> V_103 - ( sizeof( struct V_106 ) +
sizeof( struct V_107 ) ) ;
if ( V_100 >= V_319 )
F_51 ( V_70 , V_100 ) ;
break;
case V_320 :
break;
case V_321 :
F_200 ( & V_2 -> V_322 ) ;
V_67 = F_42 ( V_2 -> V_7 . V_71 ) ;
F_201 ( V_323 , & V_67 -> V_177 ) ;
goto V_49;
break;
case V_324 :
F_47 ( V_70 , V_4 ) ;
break;
default:
F_2 ( V_4 , L_56
L_57 , V_300 ) ;
}
F_54 ( V_70 ) ;
if ( V_312 && ! F_202 ( V_70 ) )
F_203 ( & V_2 -> V_7 ) ;
else if ( F_204 ( & V_2 -> V_7 ) ) {
V_243 = F_142 ( V_70 -> V_236 , F_117 () ) ;
V_243 -> V_325 ++ ;
F_122 () ;
F_81 ( V_70 ) ;
}
V_49:
return V_116 ;
}
static int F_205 ( struct V_3 * V_4 )
{
struct V_1 * V_2 ;
int V_116 = 0 ;
F_48 ( & V_326 ) ;
F_31 () ;
V_2 = F_206 ( V_4 ) ;
F_36 () ;
if ( V_2 ) {
F_204 ( & V_2 -> V_7 ) ;
F_81 ( V_2 -> V_7 . V_71 ) ;
} else
V_116 = - V_186 ;
F_49 ( & V_326 ) ;
return V_116 ;
}
static int F_207 ( struct V_3 * V_4 )
{
struct V_1 * V_2 ;
int V_116 = 0 ;
F_48 ( & V_326 ) ;
F_31 () ;
V_2 = F_206 ( V_4 ) ;
F_36 () ;
if ( ! V_2 )
V_116 = - V_186 ;
else if ( ! F_202 ( V_2 -> V_7 . V_71 ) )
F_203 ( & V_2 -> V_7 ) ;
F_49 ( & V_326 ) ;
return V_116 ;
}
static int F_208 ( struct V_3 * V_4 )
{
struct V_1 * V_2 ;
struct V_72 * V_70 ;
struct V_66 * V_67 ;
int V_116 = 0 ;
F_48 ( & V_326 ) ;
F_31 () ;
V_2 = F_206 ( V_4 ) ;
if ( ! V_2 ) {
V_116 = - V_186 ;
goto V_327;
}
V_70 = V_2 -> V_7 . V_71 ;
V_67 = F_42 ( V_70 ) ;
F_200 ( & V_2 -> V_322 ) ;
F_201 ( V_323 , & V_67 -> V_177 ) ;
V_327:
F_36 () ;
F_49 ( & V_326 ) ;
return V_116 ;
}
static void V_178 ( struct V_328 * V_329 )
{
struct V_66 * V_67 ;
struct V_1 * V_2 ;
int V_167 = 0 ;
V_67 = F_25 ( V_329 , struct V_66 , V_177 ) ;
F_48 ( & V_326 ) ;
V_167 = V_67 -> V_70 -> V_112 ? 1 : 0 ;
V_2 = V_67 -> V_73 ;
F_77 ( V_67 -> V_70 ) ;
if ( ! V_167 )
F_30 ( V_2 ) ;
F_49 ( & V_326 ) ;
}
static bool F_209 ( struct V_3 * V_4 )
{
return true ;
}
static void F_210 ( struct V_1 * V_2 )
{
#ifdef F_211
int V_310 ;
T_1 V_330 , V_331 ;
struct V_3 * V_4 = V_2 -> V_23 ;
struct V_66 * V_67 = F_42 ( V_2 -> V_7 . V_71 ) ;
struct V_332 V_305 = {
. V_265 = 0 ,
. V_264 = V_39
} ;
if ( V_4 && V_4 -> V_333 && V_4 -> V_333 -> V_334 ) {
V_310 = V_4 -> V_333 -> V_334 ( V_4 ) ;
if ( V_310 & V_335 ) {
V_305 . V_306 = V_336 ;
V_331 = F_212 ( V_4 , & V_305 ) ;
V_305 . V_264 = V_43 ;
V_330 = F_212 ( V_4 , & V_305 ) ;
} else {
V_305 . V_306 = V_307 ;
V_331 = F_213 ( V_4 , & V_305 ) ;
V_305 . V_264 = V_43 ;
V_330 = F_213 ( V_4 , & V_305 ) ;
}
V_67 -> V_265 = F_198 ( V_331 ) ? F_198 ( V_331 ) - 1 : 0 ;
V_2 -> V_7 . V_265 = F_198 ( V_330 ) ? F_198 ( V_330 ) - 1 : V_67 -> V_265 ;
}
#endif
}
static int F_214 ( struct V_3 * V_4 , enum V_44 V_45 )
{
int V_116 = 0 ;
struct V_1 * V_2 ;
struct V_72 * V_70 ;
F_48 ( & V_326 ) ;
F_31 () ;
if ( F_215 ( V_4 ) ) {
V_116 = - V_337 ;
goto V_327;
}
V_2 = F_13 ( V_4 , V_45 ) ;
if ( F_110 ( V_2 ) ) {
V_116 = F_216 ( V_2 ) ;
goto V_327;
}
V_70 = F_92 ( V_2 , & V_4 -> V_40 , 0 ) ;
if ( F_110 ( V_70 ) ) {
F_75 ( V_157 L_58 ,
V_4 -> V_132 ) ;
V_116 = - V_338 ;
F_36 () ;
F_30 ( V_2 ) ;
goto V_339;
}
V_2 -> V_7 . V_71 = V_70 ;
F_210 ( V_2 ) ;
F_217 ( V_70 ) ;
V_70 -> V_340 = V_341 ;
F_218 ( V_70 ) ;
if ( ! F_202 ( V_70 ) )
F_203 ( & V_2 -> V_7 ) ;
V_327:
F_36 () ;
V_339:
F_49 ( & V_326 ) ;
return V_116 ;
}
int F_54 ( struct V_72 * V_70 )
{
struct V_3 * V_4 = F_61 ( V_70 ) ;
struct V_342 V_343 ;
if ( ! F_219 ( V_4 , & V_343 ) ) {
V_70 -> V_344 &=
~ ( V_345 | V_346 ) ;
if ( V_343 . V_347 & ( V_348 |
V_349 ) )
V_70 -> V_344 |= V_345 ;
if ( V_343 . V_347 & V_350 )
V_70 -> V_344 |=
V_346 ;
switch ( F_220 ( & V_343 ) ) {
case V_351 :
V_70 -> V_352 = V_345 ;
break;
case V_353 :
V_70 -> V_352 = V_346 ;
break;
}
return 0 ;
}
return - 1 ;
}
int F_202 ( struct V_72 * V_70 )
{
struct V_3 * V_4 = F_61 ( V_70 ) ;
if ( F_221 ( V_4 ) )
return 0 ;
return - 1 ;
}
void F_82 ( struct V_72 * V_70 )
{
struct V_188 * V_354 ;
struct V_215 * V_216 ;
struct V_355 * V_322 ;
struct V_61 * V_62 , * V_356 ;
struct V_61 * V_222 ;
unsigned int V_187 ;
F_222 (cpu) {
V_354 = & F_106 ( V_192 , V_187 ) ;
F_113 ( & V_354 -> V_194 . V_195 ) ;
V_322 = & V_354 -> V_194 ;
V_222 = V_322 -> V_356 ;
for ( V_62 = V_222 ; V_62 != (struct V_61 * ) V_322 ;
V_62 = V_356 ) {
V_356 = V_62 -> V_356 ;
V_216 = F_138 ( V_62 ) ;
if ( V_216 -> V_231 == V_70 ) {
F_223 ( V_62 , V_322 ) ;
F_121 ( V_62 ) ;
}
}
if ( ! V_354 -> V_191 || ! F_224 ( V_187 ) ) {
F_114 ( & V_354 -> V_194 . V_195 ) ;
continue;
}
V_62 = F_225 ( 0 ) ;
if ( ! V_62 ) {
F_114 ( & V_354 -> V_194 . V_195 ) ;
continue;
}
V_62 -> V_289 = F_169 ;
F_120 ( & V_354 -> V_194 , V_62 ) ;
if ( V_354 -> V_194 . V_69 == 1 )
F_112 ( V_354 -> V_191 ) ;
F_114 ( & V_354 -> V_194 . V_195 ) ;
F_226 ( & V_279 ) ;
}
}
int F_227 ( struct V_169 * V_170 )
{
struct V_72 * V_70 = F_99 ( V_170 ) ;
struct V_66 * V_67 = F_42 ( V_70 ) ;
struct V_1 * V_2 = V_67 -> V_73 ;
F_204 ( & V_2 -> V_7 ) ;
F_81 ( V_2 -> V_7 . V_71 ) ;
if ( ! F_202 ( V_2 -> V_7 . V_71 ) )
F_203 ( & V_2 -> V_7 ) ;
return 0 ;
}
static struct V_1 *
F_206 ( const struct V_3 * V_4 )
{
struct V_1 * V_2 ;
F_73 (fcoe, &fcoe_hostlist, list) {
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
F_228 ( & V_2 -> V_322 , & V_357 ) ;
}
return 0 ;
}
static int T_5 F_229 ( void )
{
struct V_188 * V_189 ;
unsigned int V_187 ;
int V_116 = 0 ;
V_323 = F_230 ( L_59 , 0 , 0 ) ;
if ( ! V_323 )
return - V_51 ;
V_116 = F_231 ( & V_358 ) ;
if ( V_116 ) {
F_75 ( V_157 L_60
L_61 ) ;
return V_116 ;
}
F_48 ( & V_326 ) ;
F_222 (cpu) {
V_189 = & F_106 ( V_192 , V_187 ) ;
F_52 ( & V_189 -> V_194 ) ;
}
F_232 (cpu)
F_105 ( V_187 ) ;
V_116 = F_233 ( & V_359 ) ;
if ( V_116 )
goto V_360;
F_189 () ;
V_116 = F_101 () ;
if ( V_116 )
goto V_360;
F_49 ( & V_326 ) ;
return 0 ;
V_360:
F_232 (cpu) {
F_115 ( V_187 ) ;
}
F_49 ( & V_326 ) ;
F_234 ( V_323 ) ;
return V_116 ;
}
static void T_6 F_235 ( void )
{
struct V_1 * V_2 , * V_361 ;
struct V_66 * V_67 ;
unsigned int V_187 ;
F_48 ( & V_326 ) ;
F_192 () ;
F_31 () ;
F_236 (fcoe, tmp, &fcoe_hostlist, list) {
F_200 ( & V_2 -> V_322 ) ;
V_67 = F_42 ( V_2 -> V_7 . V_71 ) ;
F_201 ( V_323 , & V_67 -> V_177 ) ;
}
F_36 () ;
F_237 ( & V_359 ) ;
F_232 (cpu)
F_115 ( V_187 ) ;
F_49 ( & V_326 ) ;
F_234 ( V_323 ) ;
F_103 () ;
F_238 ( & V_358 ) ;
}
static void F_239 ( struct V_362 * V_363 , struct V_133 * V_134 , void * V_293 )
{
struct V_5 * V_6 = V_293 ;
struct V_364 * V_365 = F_240 ( V_363 ) ;
struct V_72 * V_70 = V_365 -> V_71 ;
T_1 * V_366 ;
if ( F_110 ( V_134 ) )
goto V_367;
V_366 = F_241 ( V_134 ) -> V_368 ;
if ( F_43 ( V_366 ) )
F_242 ( V_6 , V_70 , V_134 ) ;
if ( ! F_43 ( V_366 ) )
V_57 ( V_70 , V_366 ) ;
V_367:
F_243 ( V_363 , V_134 , V_70 ) ;
}
static void F_244 ( struct V_362 * V_363 , struct V_133 * V_134 , void * V_293 )
{
struct V_72 * V_70 = V_293 ;
static T_1 V_369 [ V_12 ] = { 0 } ;
if ( ! F_110 ( V_134 ) )
V_57 ( V_70 , V_369 ) ;
F_245 ( V_363 , V_134 , V_70 ) ;
}
static struct V_362 * F_246 ( struct V_72 * V_70 , T_2 V_370 ,
struct V_133 * V_134 , unsigned int V_371 ,
void (* F_247)( struct V_362 * ,
struct V_133 * ,
void * ) ,
void * V_293 , T_2 V_372 )
{
struct V_66 * V_67 = F_42 ( V_70 ) ;
struct V_1 * V_2 = V_67 -> V_73 ;
struct V_5 * V_6 = & V_2 -> V_7 ;
struct V_135 * V_136 = F_65 ( V_134 ) ;
switch ( V_371 ) {
case V_373 :
case V_374 :
if ( V_70 -> V_375 )
break;
return F_248 ( V_70 , V_370 , V_134 , V_371 , F_239 ,
V_6 , V_372 ) ;
case V_284 :
if ( F_68 ( V_136 -> V_230 ) != V_286 )
break;
return F_248 ( V_70 , V_370 , V_134 , V_371 , F_244 ,
V_70 , V_372 ) ;
}
return F_248 ( V_70 , V_370 , V_134 , V_371 , F_247 , V_293 , V_372 ) ;
}
static int F_249 ( struct V_171 * V_112 , bool V_376 )
{
struct V_169 * V_170 = F_98 ( V_112 ) ;
struct V_72 * V_168 = F_99 ( V_170 ) ;
struct V_66 * V_67 = F_42 ( V_168 ) ;
struct V_1 * V_2 = V_67 -> V_73 ;
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_72 * V_377 ;
int V_116 ;
char V_378 [ 32 ] ;
V_116 = F_250 ( V_112 ) ;
if ( V_116 ) {
F_251 ( V_112 -> V_181 , V_378 , sizeof( V_378 ) ) ;
F_75 ( V_157 L_62
L_63 ,
V_378 ) ;
return V_116 ;
}
F_48 ( & V_326 ) ;
F_31 () ;
V_377 = F_92 ( V_2 , & V_112 -> V_40 , 1 ) ;
F_36 () ;
F_49 ( & V_326 ) ;
if ( F_110 ( V_377 ) ) {
F_75 ( V_157 L_64 ,
V_4 -> V_132 ) ;
return - V_338 ;
}
if ( V_376 ) {
F_252 ( V_112 , V_379 ) ;
} else {
V_377 -> V_340 = V_341 ;
F_218 ( V_377 ) ;
F_253 ( V_377 ) ;
}
return 0 ;
}
static int F_254 ( struct V_171 * V_112 )
{
struct V_169 * V_170 = F_98 ( V_112 ) ;
struct V_72 * V_168 = F_99 ( V_170 ) ;
struct V_72 * V_377 = V_112 -> V_380 ;
struct V_66 * V_67 = F_42 ( V_377 ) ;
F_48 ( & V_168 -> V_92 ) ;
F_200 ( & V_377 -> V_322 ) ;
F_49 ( & V_168 -> V_92 ) ;
F_201 ( V_323 , & V_67 -> V_177 ) ;
return 0 ;
}
static int F_255 ( struct V_171 * V_112 , bool V_381 )
{
struct V_72 * V_70 = V_112 -> V_380 ;
if ( V_381 ) {
F_252 ( V_112 , V_379 ) ;
F_78 ( V_70 ) ;
} else {
V_70 -> V_340 = V_341 ;
F_218 ( V_70 ) ;
F_253 ( V_70 ) ;
}
return 0 ;
}
static void F_256 ( struct V_171 * V_112 )
{
struct V_72 * V_70 = V_112 -> V_380 ;
struct V_133 * V_134 ;
T_9 V_221 ;
snprintf ( F_63 ( V_70 -> V_117 ) , V_129 ,
L_65 , V_130 , V_131 ,
F_61 ( V_70 ) -> V_132 , V_112 -> V_382 ) ;
if ( V_70 -> V_383 != V_384 )
return;
V_221 = F_257 ( F_63 ( V_70 -> V_117 ) , 255 ) ;
V_134 = F_258 ( V_70 ,
sizeof( struct V_385 ) +
sizeof( struct V_386 ) + V_221 ) ;
if ( ! V_134 )
return;
V_70 -> V_387 . V_388 ( V_70 , V_389 , V_134 , V_390 ,
NULL , NULL , 3 * V_70 -> V_80 ) ;
}
static void F_259 ( struct V_72 * V_70 ,
struct V_391 * V_392 )
{
struct V_3 * V_4 = F_61 ( V_70 ) ;
F_260 ( V_70 , V_392 , V_4 ) ;
}
static void F_261 ( struct V_72 * V_70 ,
T_2 V_393 , struct V_133 * V_134 )
{
struct V_66 * V_67 = F_42 ( V_70 ) ;
struct V_1 * V_2 = V_67 -> V_73 ;
if ( V_134 && F_173 ( V_134 ) == V_373 )
F_242 ( & V_2 -> V_7 , V_70 , V_134 ) ;
}
