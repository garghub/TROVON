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
F_4 () ;
F_5 (real_dev, ha) {
if ( ( V_9 -> type == V_23 ) &&
( F_6 ( V_9 -> V_24 ) ) ) {
memcpy ( V_6 -> V_25 , V_9 -> V_24 , V_12 ) ;
V_6 -> V_26 = 1 ;
break;
}
}
F_7 () ;
if ( ! V_6 -> V_26 )
memcpy ( V_6 -> V_25 , V_4 -> V_27 , V_4 -> V_28 ) ;
memcpy ( V_11 , ( T_1 [ 6 ] ) V_29 , V_12 ) ;
F_8 ( V_4 , V_11 ) ;
if ( V_6 -> V_26 )
F_8 ( V_4 , V_6 -> V_25 ) ;
if ( V_6 -> V_30 == V_31 ) {
F_9 ( V_4 , V_32 ) ;
F_9 ( V_4 , V_33 ) ;
} else
F_9 ( V_4 , V_34 ) ;
V_2 -> V_35 . V_36 = V_37 ;
V_2 -> V_35 . type = F_10 ( V_38 ) ;
V_2 -> V_35 . V_39 = V_4 ;
F_11 ( & V_2 -> V_35 ) ;
V_2 -> V_40 . V_36 = V_41 ;
V_2 -> V_40 . type = F_12 ( V_42 ) ;
V_2 -> V_40 . V_39 = V_4 ;
F_11 ( & V_2 -> V_40 ) ;
return 0 ;
}
static struct V_1 * F_13 ( struct V_3 * V_4 ,
enum V_43 V_44 )
{
struct V_1 * V_2 ;
int V_45 ;
if ( ! F_14 ( V_46 ) ) {
F_2 ( V_4 ,
L_4 ) ;
V_2 = F_15 ( - V_47 ) ;
goto V_48;
}
V_2 = F_16 ( sizeof( * V_2 ) , V_49 ) ;
if ( ! V_2 ) {
F_2 ( V_4 , L_5 ) ;
V_2 = F_15 ( - V_50 ) ;
goto V_51;
}
F_17 ( V_4 ) ;
F_18 ( & V_2 -> V_52 ) ;
F_19 ( & V_2 -> V_7 , V_44 ) ;
V_2 -> V_7 . V_53 = V_54 ;
V_2 -> V_7 . V_55 = V_56 ;
V_2 -> V_7 . V_57 = V_58 ;
V_45 = F_1 ( V_2 , V_4 ) ;
if ( V_45 ) {
F_20 ( & V_2 -> V_7 ) ;
F_21 ( V_2 ) ;
F_22 ( V_4 ) ;
V_2 = F_15 ( V_45 ) ;
goto V_51;
}
goto V_48;
V_51:
F_23 ( V_46 ) ;
V_48:
return V_2 ;
}
static void F_24 ( struct V_52 * V_52 )
{
struct V_1 * V_2 ;
struct V_3 * V_4 ;
V_2 = F_25 ( V_52 , struct V_1 , V_52 ) ;
V_4 = V_2 -> V_4 ;
F_20 ( & V_2 -> V_7 ) ;
F_21 ( V_2 ) ;
F_22 ( V_4 ) ;
F_23 ( V_46 ) ;
}
static inline void F_26 ( struct V_1 * V_2 )
{
F_27 ( & V_2 -> V_52 ) ;
}
static inline void F_28 ( struct V_1 * V_2 )
{
F_29 ( & V_2 -> V_52 , F_24 ) ;
}
void F_30 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_5 * V_6 = & V_2 -> V_7 ;
T_1 V_11 [ V_12 ] ;
const struct V_13 * V_14 ;
F_31 () ;
F_32 ( & V_2 -> V_35 ) ;
F_32 ( & V_2 -> V_40 ) ;
F_33 () ;
memcpy ( V_11 , ( T_1 [ 6 ] ) V_29 , V_12 ) ;
F_34 ( V_4 , V_11 ) ;
if ( V_6 -> V_26 )
F_34 ( V_4 , V_6 -> V_25 ) ;
if ( V_6 -> V_30 == V_31 ) {
F_35 ( V_4 , V_32 ) ;
F_35 ( V_4 , V_33 ) ;
} else
F_35 ( V_4 , V_34 ) ;
V_14 = V_4 -> V_15 ;
if ( V_14 -> V_59 ) {
if ( V_14 -> V_59 ( V_4 ) )
F_2 ( V_4 , L_6
L_2 ) ;
}
F_36 () ;
F_28 ( V_2 ) ;
}
static int V_41 ( struct V_60 * V_61 , struct V_3 * V_4 ,
struct V_62 * V_63 ,
struct V_3 * V_64 )
{
struct V_1 * V_2 ;
V_2 = F_25 ( V_63 , struct V_1 , V_40 ) ;
F_37 ( & V_2 -> V_7 , V_61 ) ;
return 0 ;
}
static void F_38 ( struct V_65 * V_66 , struct V_60 * V_61 )
{
if ( V_66 -> V_67 . V_68 )
F_39 ( V_66 -> V_69 , V_61 ) ;
else if ( F_40 ( V_61 ) )
F_39 ( V_66 -> V_69 , V_61 ) ;
}
static void V_54 ( struct V_5 * V_6 , struct V_60 * V_61 )
{
V_61 -> V_39 = F_41 ( V_6 ) -> V_4 ;
F_38 ( F_42 ( V_6 -> V_70 ) , V_61 ) ;
}
static void V_56 ( struct V_71 * V_69 , T_1 * V_24 )
{
struct V_65 * V_66 = F_42 ( V_69 ) ;
struct V_1 * V_2 = V_66 -> V_72 ;
F_31 () ;
if ( ! F_43 ( V_66 -> V_73 ) )
F_34 ( V_2 -> V_4 , V_66 -> V_73 ) ;
if ( ! F_43 ( V_24 ) )
F_8 ( V_2 -> V_4 , V_24 ) ;
memcpy ( V_66 -> V_73 , V_24 , V_12 ) ;
F_36 () ;
}
static T_1 * V_58 ( struct V_71 * V_69 )
{
struct V_65 * V_66 = F_42 ( V_69 ) ;
return V_66 -> V_73 ;
}
static int F_44 ( struct V_71 * V_69 )
{
V_69 -> V_74 = 0 ;
V_69 -> V_75 = 0 ;
V_69 -> V_76 = 3 ;
V_69 -> V_77 = 3 ;
V_69 -> V_78 = 2 * 1000 ;
V_69 -> V_79 = 2 * 2 * 1000 ;
V_69 -> V_80 = ( V_81 | V_82 |
V_83 | V_84 ) ;
V_69 -> V_85 = 1 ;
F_45 ( V_69 ) ;
F_46 ( V_69 ) ;
V_69 -> V_86 = 0 ;
V_69 -> V_87 = 0 ;
V_69 -> V_88 = 0 ;
V_69 -> V_89 = 0 ;
V_69 -> V_90 = 0 ;
return 0 ;
}
static int F_47 ( struct V_3 * V_4 , T_2 * V_91 , int type )
{
const struct V_13 * V_14 = V_4 -> V_15 ;
if ( V_14 -> V_92 )
return V_14 -> V_92 ( V_4 , V_91 , type ) ;
return - V_93 ;
}
static void F_48 ( struct V_71 * V_69 ,
struct V_3 * V_4 )
{
F_49 ( & V_69 -> V_94 ) ;
if ( V_4 -> V_95 & V_96 )
V_69 -> V_97 = 1 ;
else
V_69 -> V_97 = 0 ;
if ( V_4 -> V_95 & V_98 ) {
V_69 -> V_86 = 1 ;
F_2 ( V_4 , L_7 ) ;
} else {
V_69 -> V_86 = 0 ;
}
if ( V_4 -> V_95 & V_99 ) {
V_69 -> V_87 = 1 ;
V_69 -> V_90 = V_4 -> V_100 ;
F_2 ( V_4 , L_8 ,
V_69 -> V_90 ) ;
} else {
V_69 -> V_87 = 0 ;
V_69 -> V_90 = 0 ;
}
if ( V_4 -> V_101 ) {
V_69 -> V_88 = 1 ;
V_69 -> V_89 = V_4 -> V_101 ;
F_2 ( V_4 , L_9 ,
V_69 -> V_89 ) ;
} else {
V_69 -> V_88 = 0 ;
V_69 -> V_89 = 0 ;
}
F_50 ( & V_69 -> V_94 ) ;
}
static int F_51 ( struct V_71 * V_69 , struct V_3 * V_4 )
{
T_3 V_102 ;
T_2 V_103 , V_104 ;
struct V_1 * V_2 ;
struct V_65 * V_66 ;
V_66 = F_42 ( V_69 ) ;
V_2 = V_66 -> V_72 ;
V_102 = V_4 -> V_105 ;
if ( V_4 -> V_95 & V_106 ) {
V_102 = V_107 ;
F_2 ( V_4 , L_10 , V_102 ) ;
}
V_102 -= ( sizeof( struct V_108 ) + sizeof( struct V_109 ) ) ;
if ( F_52 ( V_69 , V_102 ) )
return - V_93 ;
F_48 ( V_69 , V_4 ) ;
F_53 ( & V_66 -> V_67 ) ;
V_66 -> V_110 = 0 ;
F_54 ( & V_66 -> V_111 , V_112 , ( unsigned long ) V_69 ) ;
F_55 ( V_69 ) ;
if ( ! V_69 -> V_113 ) {
if ( F_47 ( V_4 , & V_103 , V_114 ) )
V_103 = F_56 ( V_2 -> V_7 . V_25 , 1 , 0 ) ;
F_57 ( V_69 , V_103 ) ;
if ( F_47 ( V_4 , & V_104 , V_115 ) )
V_104 = F_56 ( V_2 -> V_7 . V_25 ,
2 , 0 ) ;
F_58 ( V_69 , V_104 ) ;
}
return 0 ;
}
static int F_59 ( struct V_71 * V_69 , struct V_116 * V_39 )
{
int V_117 = 0 ;
V_69 -> V_118 -> V_119 = V_120 ;
V_69 -> V_118 -> V_121 = V_122 ;
V_69 -> V_118 -> V_123 = 0 ;
V_69 -> V_118 -> V_124 = V_125 ;
if ( V_69 -> V_113 )
V_69 -> V_118 -> V_126 = V_127 ;
else
V_69 -> V_118 -> V_126 = V_128 ;
V_117 = F_60 ( V_69 -> V_118 , V_39 ) ;
if ( V_117 ) {
F_2 ( F_61 ( V_69 ) , L_11
L_12 ) ;
return V_117 ;
}
if ( ! V_69 -> V_113 )
F_62 ( V_69 -> V_118 ) = V_129 ;
snprintf ( F_63 ( V_69 -> V_118 ) , V_130 ,
L_13 , V_131 , V_132 ,
F_61 ( V_69 ) -> V_133 ) ;
return 0 ;
}
bool F_64 ( struct V_134 * V_135 )
{
struct V_136 * V_137 = F_65 ( V_135 ) ;
struct V_138 * V_139 ;
if ( F_66 ( F_67 ( V_135 ) ) &&
( F_67 ( V_135 ) -> V_140 > V_141 ) )
return true ;
else if ( ! ( F_68 ( V_137 -> V_142 ) & V_143 ) ) {
V_139 = F_69 ( V_135 , sizeof( * V_139 ) ) ;
if ( F_70 ( V_137 -> V_144 ) == V_145 &&
V_139 && ( F_71 ( V_139 -> V_146 ) > V_141 ) &&
( V_139 -> V_147 & V_148 ) )
return true ;
}
return false ;
}
static inline int F_72 ( struct V_71 * V_69 )
{
struct V_65 * V_66 = F_42 ( V_69 ) ;
struct V_1 * V_2 = V_66 -> V_72 ;
struct V_1 * V_149 = NULL ;
struct V_3 * V_150 , * V_151 ;
T_4 V_152 = V_153 ;
T_4 V_154 = V_155 ;
if ( ! V_69 -> V_88 || ! V_69 -> V_89 ||
( V_69 -> V_89 >= V_154 ) ) {
V_69 -> V_89 = 0 ;
goto V_156;
}
if ( V_2 -> V_4 -> V_17 & V_22 )
V_151 = F_3 ( V_2 -> V_4 ) ;
else
V_151 = V_2 -> V_4 ;
F_73 (oldfcoe, &fcoe_hostlist, list) {
if ( V_149 -> V_4 -> V_17 & V_22 )
V_150 = F_3 ( V_149 -> V_4 ) ;
else
V_150 = V_149 -> V_4 ;
if ( V_151 == V_150 ) {
V_2 -> V_157 = V_149 -> V_157 ;
break;
}
}
if ( V_2 -> V_157 ) {
if ( ! F_74 ( V_69 , V_2 -> V_157 , F_64 ) ) {
F_75 ( V_158 L_14
L_15 ,
V_2 -> V_157 , V_2 -> V_4 -> V_133 ) ;
return - V_50 ;
}
} else {
V_2 -> V_157 = F_76 ( V_69 , V_159 ,
V_153 , V_69 -> V_89 ,
F_64 ) ;
if ( ! V_2 -> V_157 ) {
F_75 ( V_158 L_16
L_17 ,
V_2 -> V_4 -> V_133 ) ;
return - V_50 ;
}
}
V_152 += V_69 -> V_89 + 1 ;
V_156:
if ( ! F_76 ( V_69 , V_159 , V_152 , V_154 , NULL ) ) {
F_75 ( V_158 L_18
L_19 , V_2 -> V_4 -> V_133 ) ;
return - V_50 ;
}
return 0 ;
}
static void F_77 ( struct V_71 * V_69 )
{
struct V_65 * V_66 = F_42 ( V_69 ) ;
struct V_1 * V_2 = V_66 -> V_72 ;
struct V_3 * V_4 = V_2 -> V_4 ;
F_2 ( V_4 , L_20 ) ;
F_78 ( V_69 ) ;
F_79 ( V_69 ) ;
F_80 ( & V_66 -> V_111 ) ;
F_81 ( V_69 ) ;
F_31 () ;
if ( ! F_43 ( V_66 -> V_73 ) )
F_34 ( V_4 , V_66 -> V_73 ) ;
F_36 () ;
F_28 ( V_2 ) ;
F_82 ( V_69 ) ;
F_83 ( V_69 -> V_118 ) ;
F_84 ( V_69 -> V_118 ) ;
F_85 ( V_69 ) ;
F_86 ( V_69 ) ;
F_87 ( V_69 ) ;
F_88 ( V_69 -> V_118 ) ;
}
static int F_89 ( struct V_71 * V_69 , T_4 V_160 ,
struct V_161 * V_162 , unsigned int V_163 )
{
struct V_3 * V_4 = F_61 ( V_69 ) ;
if ( V_4 -> V_15 -> V_164 )
return V_4 -> V_15 -> V_164 ( V_4 ,
V_160 , V_162 ,
V_163 ) ;
return 0 ;
}
static int F_90 ( struct V_71 * V_69 , T_4 V_160 ,
struct V_161 * V_162 , unsigned int V_163 )
{
struct V_3 * V_4 = F_61 ( V_69 ) ;
if ( V_4 -> V_15 -> V_165 )
return V_4 -> V_15 -> V_165 ( V_4 , V_160 ,
V_162 , V_163 ) ;
return 0 ;
}
static int F_91 ( struct V_71 * V_69 , T_4 V_160 )
{
struct V_3 * V_4 = F_61 ( V_69 ) ;
if ( V_4 -> V_15 -> V_166 )
return V_4 -> V_15 -> V_166 ( V_4 , V_160 ) ;
return 0 ;
}
static struct V_71 * F_92 ( struct V_1 * V_2 ,
struct V_116 * V_167 , int V_168 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_71 * V_69 , * V_169 ;
struct V_65 * V_66 ;
struct V_170 * V_171 ;
int V_117 ;
struct V_172 * V_113 = F_93 ( V_167 ) ;
F_2 ( V_4 , L_21 ) ;
if ( ! V_168 )
V_69 = F_94 ( & V_173 , sizeof( * V_66 ) ) ;
else
V_69 = F_95 ( V_113 , sizeof( * V_66 ) ) ;
if ( ! V_69 ) {
F_2 ( V_4 , L_22 ) ;
V_117 = - V_50 ;
goto V_48;
}
V_66 = F_42 ( V_69 ) ;
V_66 -> V_69 = V_69 ;
V_66 -> V_72 = V_2 ;
V_66 -> V_174 = V_175 ;
V_66 -> V_176 = V_177 ;
F_96 ( & V_66 -> V_178 , V_179 ) ;
V_117 = F_44 ( V_69 ) ;
if ( V_117 ) {
F_2 ( V_4 , L_23
L_24 ) ;
goto V_180;
}
if ( V_168 ) {
F_2 ( V_4 , L_25
L_26 ,
V_113 -> V_181 , V_113 -> V_182 ) ;
F_57 ( V_69 , V_113 -> V_181 ) ;
F_58 ( V_69 , V_113 -> V_182 ) ;
}
V_117 = F_51 ( V_69 , V_4 ) ;
if ( V_117 ) {
F_2 ( V_4 , L_27
L_24 ) ;
goto V_183;
}
V_117 = F_59 ( V_69 , V_167 ) ;
if ( V_117 ) {
F_2 ( V_4 , L_28
L_24 ) ;
goto V_183;
}
V_117 = F_97 ( V_69 , & V_2 -> V_7 , & V_184 , 1 ) ;
if ( V_117 ) {
F_2 ( V_4 , L_29
L_24 ) ;
goto V_183;
}
if ( ! V_168 )
V_117 = F_72 ( V_69 ) ;
else {
V_171 = F_98 ( V_113 ) ;
V_169 = F_99 ( V_171 ) ;
V_117 = F_100 ( V_169 , V_69 ) ;
}
if ( V_117 ) {
F_2 ( V_4 , L_30 ) ;
goto V_183;
}
F_26 ( V_2 ) ;
return V_69 ;
V_183:
F_86 ( V_69 ) ;
V_180:
F_88 ( V_69 -> V_118 ) ;
V_48:
return F_15 ( V_117 ) ;
}
static int T_5 F_101 ( void )
{
V_128 =
F_102 ( & V_185 ) ;
V_127 =
F_102 ( & V_186 ) ;
if ( ! V_128 ) {
F_75 ( V_158 L_31 ) ;
return - V_187 ;
}
return 0 ;
}
int T_6 F_103 ( void )
{
F_104 ( V_128 ) ;
F_104 ( V_127 ) ;
V_128 = NULL ;
V_127 = NULL ;
return 0 ;
}
static void F_105 ( unsigned int V_188 )
{
struct V_189 * V_190 ;
struct V_191 * V_192 ;
V_190 = & F_106 ( V_193 , V_188 ) ;
V_192 = F_107 ( V_194 ,
( void * ) V_190 , L_32 , V_188 ) ;
if ( F_108 ( ! F_109 ( V_192 ) ) ) {
F_110 ( V_192 , V_188 ) ;
F_111 ( V_192 ) ;
F_112 ( & V_190 -> V_195 . V_196 ) ;
V_190 -> V_192 = V_192 ;
F_113 ( & V_190 -> V_195 . V_196 ) ;
}
}
static void F_114 ( unsigned int V_188 )
{
struct V_189 * V_190 ;
struct V_191 * V_192 ;
struct V_197 * V_198 ;
struct V_60 * V_61 ;
#ifdef F_115
struct V_189 * V_199 ;
unsigned V_200 = F_116 () ;
#endif
F_117 ( L_33 , V_188 ) ;
V_190 = & F_106 ( V_193 , V_188 ) ;
F_112 ( & V_190 -> V_195 . V_196 ) ;
V_192 = V_190 -> V_192 ;
V_190 -> V_192 = NULL ;
V_198 = V_190 -> V_201 ;
V_190 -> V_201 = NULL ;
V_190 -> V_202 = 0 ;
F_113 ( & V_190 -> V_195 . V_196 ) ;
#ifdef F_115
if ( V_188 != V_200 ) {
V_199 = & F_106 ( V_193 , V_200 ) ;
F_112 ( & V_199 -> V_195 . V_196 ) ;
if ( V_199 -> V_192 ) {
F_117 ( L_34 ,
V_188 , V_200 ) ;
while ( ( V_61 = F_118 ( & V_190 -> V_195 ) ) != NULL )
F_119 ( & V_199 -> V_195 , V_61 ) ;
F_113 ( & V_199 -> V_195 . V_196 ) ;
} else {
while ( ( V_61 = F_118 ( & V_190 -> V_195 ) ) != NULL )
F_120 ( V_61 ) ;
F_113 ( & V_199 -> V_195 . V_196 ) ;
}
} else {
F_112 ( & V_190 -> V_195 . V_196 ) ;
while ( ( V_61 = F_118 ( & V_190 -> V_195 ) ) != NULL )
F_120 ( V_61 ) ;
F_113 ( & V_190 -> V_195 . V_196 ) ;
}
F_121 () ;
#else
F_112 ( & V_190 -> V_195 . V_196 ) ;
while ( ( V_61 = F_118 ( & V_190 -> V_195 ) ) != NULL )
F_120 ( V_61 ) ;
F_113 ( & V_190 -> V_195 . V_196 ) ;
#endif
if ( V_192 )
F_122 ( V_192 ) ;
if ( V_198 )
F_123 ( V_198 ) ;
}
static int F_124 ( struct V_203 * V_204 ,
unsigned long V_205 , void * V_206 )
{
unsigned V_188 = ( unsigned long ) V_206 ;
switch ( V_205 ) {
case V_207 :
case V_208 :
F_117 ( L_35 , V_188 ) ;
F_105 ( V_188 ) ;
break;
case V_209 :
case V_210 :
F_117 ( L_36 , V_188 ) ;
F_114 ( V_188 ) ;
break;
default:
break;
}
return V_211 ;
}
static inline unsigned int F_125 ( void )
{
static unsigned int V_212 ;
V_212 = F_126 ( V_212 , V_213 ) ;
if ( V_212 >= V_214 )
V_212 = F_127 ( V_213 ) ;
return V_212 ;
}
int V_37 ( struct V_60 * V_61 , struct V_3 * V_4 ,
struct V_62 * V_63 , struct V_3 * V_215 )
{
struct V_71 * V_69 ;
struct V_216 * V_217 ;
struct V_1 * V_2 ;
struct V_136 * V_137 ;
struct V_189 * V_218 ;
struct V_219 * V_220 ;
unsigned int V_188 ;
V_2 = F_25 ( V_63 , struct V_1 , V_35 ) ;
V_69 = V_2 -> V_7 . V_70 ;
if ( F_128 ( ! V_69 ) ) {
F_2 ( V_4 , L_37 ) ;
goto V_221;
}
if ( ! V_69 -> V_74 )
goto V_221;
F_2 ( V_4 , L_38
L_39 ,
V_61 -> V_222 , V_61 -> V_140 , V_61 -> V_223 , V_61 -> V_224 ,
F_129 ( V_61 ) , F_130 ( V_61 ) ,
V_61 -> V_225 , V_61 -> V_39 ? V_61 -> V_39 -> V_133 : L_40 ) ;
V_220 = F_131 ( V_61 ) ;
if ( F_132 ( & V_2 -> V_7 ) &&
F_133 ( V_220 -> V_226 , V_2 -> V_7 . V_227 ) ) {
F_2 ( V_4 , L_41 ,
V_220 -> V_226 ) ;
goto V_45;
}
if ( F_128 ( ( V_61 -> V_222 < V_228 ) ||
! F_134 ( V_61 , V_229 ) ) )
goto V_45;
F_135 ( V_61 , sizeof( struct V_108 ) ) ;
V_137 = (struct V_136 * ) F_136 ( V_61 ) ;
if ( F_68 ( & V_220 -> V_230 [ 3 ] ) != F_68 ( V_137 -> V_231 ) ) {
F_2 ( V_4 , L_42 ,
V_220 -> V_230 ) ;
goto V_45;
}
V_217 = F_137 ( V_61 ) ;
V_217 -> V_232 = V_69 ;
if ( F_68 ( V_137 -> V_142 ) & V_143 )
V_188 = F_70 ( V_137 -> V_233 ) & V_234 ;
else {
if ( F_70 ( V_137 -> V_144 ) == V_145 )
V_188 = F_125 () ;
else
V_188 = F_70 ( V_137 -> V_144 ) & V_234 ;
}
if ( V_188 >= V_214 )
goto V_45;
V_218 = & F_106 ( V_193 , V_188 ) ;
F_112 ( & V_218 -> V_195 . V_196 ) ;
if ( F_128 ( ! V_218 -> V_192 ) ) {
F_2 ( V_4 , L_43
L_44
L_45 ) ;
F_113 ( & V_218 -> V_195 . V_196 ) ;
V_188 = F_127 ( V_213 ) ;
V_218 = & F_106 ( V_193 , V_188 ) ;
F_112 ( & V_218 -> V_195 . V_196 ) ;
if ( ! V_218 -> V_192 ) {
F_113 ( & V_218 -> V_195 . V_196 ) ;
goto V_45;
}
}
if ( V_137 -> V_235 == V_236 &&
V_188 == F_138 () &&
F_139 ( & V_218 -> V_195 ) ) {
F_113 ( & V_218 -> V_195 . V_196 ) ;
F_140 ( V_61 ) ;
} else {
F_119 ( & V_218 -> V_195 , V_61 ) ;
if ( V_218 -> V_195 . V_68 == 1 )
F_111 ( V_218 -> V_192 ) ;
F_113 ( & V_218 -> V_195 . V_196 ) ;
}
return 0 ;
V_45:
F_141 ( V_69 -> V_237 , F_116 () ) -> V_238 ++ ;
F_121 () ;
V_221:
F_120 ( V_61 ) ;
return - 1 ;
}
static int F_142 ( struct V_60 * V_61 , int V_239 )
{
struct V_189 * V_218 ;
int V_117 ;
V_218 = & F_143 ( V_193 ) ;
V_117 = F_144 ( V_61 , V_239 , V_218 ) ;
F_145 ( V_193 ) ;
return V_117 ;
}
int F_146 ( struct V_71 * V_69 , struct V_134 * V_135 )
{
int V_240 ;
T_3 V_241 ;
struct V_219 * V_220 ;
struct V_109 * V_242 ;
struct V_60 * V_61 ;
struct V_243 * V_244 ;
struct V_136 * V_137 ;
unsigned int V_245 ;
unsigned int V_239 ;
unsigned int V_246 ;
struct V_65 * V_66 = F_42 ( V_69 ) ;
struct V_1 * V_2 = V_66 -> V_72 ;
T_1 V_247 , V_248 ;
struct V_108 * V_249 ;
F_147 ( ( F_148 ( V_135 ) % sizeof( T_3 ) ) != 0 ) ;
V_137 = F_65 ( V_135 ) ;
V_61 = F_149 ( V_135 ) ;
V_240 = V_61 -> V_222 / V_250 ;
if ( ! V_69 -> V_74 ) {
F_120 ( V_61 ) ;
return 0 ;
}
if ( F_128 ( V_137 -> V_235 == V_251 ) &&
F_150 ( & V_2 -> V_7 , V_69 , V_61 ) )
return 0 ;
V_247 = F_151 ( V_135 ) ;
V_248 = F_152 ( V_135 ) ;
V_246 = sizeof( struct V_219 ) ;
V_245 = sizeof( struct V_108 ) ;
V_239 = sizeof( struct V_109 ) ;
V_240 = ( V_61 -> V_222 - V_239 + sizeof( V_241 ) ) / V_250 ;
if ( F_108 ( V_69 -> V_86 ) ) {
V_61 -> V_252 = V_253 ;
V_61 -> V_254 = F_153 ( V_61 ) ;
V_61 -> V_255 = V_61 -> V_222 ;
V_241 = 0 ;
} else {
V_61 -> V_252 = V_256 ;
V_241 = F_154 ( V_135 ) ;
}
if ( F_155 ( V_61 ) ) {
T_7 * V_257 ;
if ( F_142 ( V_61 , V_239 ) ) {
F_120 ( V_61 ) ;
return - V_50 ;
}
V_257 = & F_156 ( V_61 ) -> V_258 [ F_156 ( V_61 ) -> V_259 - 1 ] ;
V_242 = F_157 ( V_257 -> V_197 , V_260 )
+ V_257 -> V_261 ;
} else {
V_242 = (struct V_109 * ) F_158 ( V_61 , V_239 ) ;
}
memset ( V_242 , 0 , sizeof( * V_242 ) ) ;
V_242 -> V_262 = V_248 ;
V_242 -> V_263 = F_159 ( ~ V_241 ) ;
if ( F_155 ( V_61 ) ) {
F_160 ( V_242 , V_260 ) ;
V_242 = NULL ;
}
F_161 ( V_61 , V_246 + V_245 ) ;
F_162 ( V_61 ) ;
F_163 ( V_61 ) ;
V_61 -> V_264 = V_246 ;
V_61 -> V_265 = F_12 ( V_38 ) ;
V_61 -> V_39 = V_2 -> V_4 ;
V_220 = F_131 ( V_61 ) ;
V_220 -> V_266 = F_12 ( V_38 ) ;
memcpy ( V_220 -> V_230 , V_2 -> V_7 . V_227 , V_12 ) ;
if ( V_2 -> V_7 . V_267 )
memcpy ( V_220 -> V_230 + 3 , V_137 -> V_231 , 3 ) ;
if ( F_128 ( V_2 -> V_7 . V_268 != V_145 ) )
memcpy ( V_220 -> V_226 , V_2 -> V_7 . V_25 , V_12 ) ;
else
memcpy ( V_220 -> V_226 , V_66 -> V_73 , V_12 ) ;
V_249 = (struct V_108 * ) ( V_220 + 1 ) ;
memset ( V_249 , 0 , sizeof( * V_249 ) ) ;
if ( V_269 )
F_164 ( V_249 , V_269 ) ;
V_249 -> V_270 = V_247 ;
if ( V_69 -> V_87 && F_165 ( V_135 ) ) {
F_156 ( V_61 ) -> V_271 = V_272 ;
F_156 ( V_61 ) -> V_273 = F_165 ( V_135 ) ;
} else {
F_156 ( V_61 ) -> V_271 = 0 ;
F_156 ( V_61 ) -> V_273 = 0 ;
}
V_244 = F_141 ( V_69 -> V_237 , F_116 () ) ;
V_244 -> V_274 ++ ;
V_244 -> V_275 += V_240 ;
F_121 () ;
V_232 ( V_135 ) = V_69 ;
F_38 ( V_66 , V_61 ) ;
return 0 ;
}
static void F_166 ( struct V_60 * V_61 )
{
F_167 ( & V_276 ) ;
}
static inline int F_168 ( struct V_71 * V_69 ,
struct V_134 * V_135 )
{
struct V_1 * V_2 ;
struct V_136 * V_137 ;
struct V_60 * V_61 = (struct V_60 * ) V_135 ;
struct V_243 * V_244 ;
if ( V_69 -> V_86 && V_61 -> V_252 == V_277 )
F_169 ( V_135 ) &= ~ V_278 ;
else
F_169 ( V_135 ) |= V_278 ;
V_137 = (struct V_136 * ) F_136 ( V_61 ) ;
V_137 = F_65 ( V_135 ) ;
if ( V_137 -> V_279 == V_280 && V_137 -> V_235 == V_236 )
return 0 ;
V_2 = ( (struct V_65 * ) F_42 ( V_69 ) ) -> V_72 ;
if ( F_132 ( & V_2 -> V_7 ) && F_170 ( V_135 ) == V_281 &&
F_68 ( V_137 -> V_282 ) == V_283 ) {
F_117 ( L_46 ) ;
return - V_93 ;
}
if ( ! ( F_169 ( V_135 ) & V_278 ) ||
F_171 ( F_172 ( V_135 ) ) == ~ F_173 ( ~ 0 , V_61 -> V_224 , V_61 -> V_222 ) ) {
F_169 ( V_135 ) &= ~ V_278 ;
return 0 ;
}
V_244 = F_141 ( V_69 -> V_237 , F_116 () ) ;
V_244 -> V_284 ++ ;
if ( V_244 -> V_284 < 5 )
F_75 ( V_285 L_47 ) ;
return - V_93 ;
}
static void F_140 ( struct V_60 * V_61 )
{
T_3 F_148 ;
struct V_71 * V_69 ;
struct V_216 * V_217 ;
struct V_243 * V_244 ;
struct V_109 V_198 ;
struct V_134 * V_135 ;
struct V_65 * V_66 ;
struct V_108 * V_249 ;
V_217 = F_137 ( V_61 ) ;
V_69 = V_217 -> V_232 ;
if ( F_128 ( ! V_69 ) ) {
if ( V_61 -> V_286 != F_166 )
F_2 ( V_61 -> V_39 , L_48 ) ;
F_120 ( V_61 ) ;
return;
}
F_2 ( V_61 -> V_39 , L_49
L_50 ,
V_61 -> V_222 , V_61 -> V_140 ,
V_61 -> V_223 , V_61 -> V_224 , F_129 ( V_61 ) ,
F_130 ( V_61 ) , V_61 -> V_225 ,
V_61 -> V_39 ? V_61 -> V_39 -> V_133 : L_40 ) ;
V_66 = F_42 ( V_69 ) ;
if ( F_155 ( V_61 ) )
F_174 ( V_61 ) ;
V_249 = (struct V_108 * ) F_175 ( V_61 ) ;
V_244 = F_141 ( V_69 -> V_237 , F_116 () ) ;
if ( F_128 ( F_176 ( V_249 ) != V_269 ) ) {
if ( V_244 -> V_238 < 5 )
F_75 ( V_285 L_51
L_52
L_53
L_54
L_55 , F_176 ( V_249 ) ,
V_269 ) ;
goto V_287;
}
F_177 ( V_61 , sizeof( struct V_108 ) ) ;
F_148 = V_61 -> V_222 - sizeof( struct V_109 ) ;
V_244 -> V_288 ++ ;
V_244 -> V_289 += F_148 / V_250 ;
V_135 = (struct V_134 * ) V_61 ;
F_178 ( V_135 ) ;
V_232 ( V_135 ) = V_69 ;
F_151 ( V_135 ) = V_249 -> V_270 ;
if ( F_179 ( V_61 , F_148 , & V_198 , sizeof( V_198 ) ) )
goto V_287;
F_152 ( V_135 ) = V_198 . V_262 ;
F_172 ( V_135 ) = V_198 . V_263 ;
if ( F_180 ( V_61 , F_148 ) )
goto V_287;
if ( ! F_168 ( V_69 , V_135 ) ) {
F_121 () ;
F_181 ( V_69 , V_135 ) ;
return;
}
V_287:
V_244 -> V_238 ++ ;
F_121 () ;
F_120 ( V_61 ) ;
}
int V_194 ( void * V_290 )
{
struct V_189 * V_190 = V_290 ;
struct V_60 * V_61 ;
F_182 ( V_291 , - 20 ) ;
while ( ! F_183 () ) {
F_112 ( & V_190 -> V_195 . V_196 ) ;
while ( ( V_61 = F_118 ( & V_190 -> V_195 ) ) == NULL ) {
F_184 ( V_292 ) ;
F_113 ( & V_190 -> V_195 . V_196 ) ;
F_185 () ;
F_184 ( V_293 ) ;
if ( F_183 () )
return 0 ;
F_112 ( & V_190 -> V_195 . V_196 ) ;
}
F_113 ( & V_190 -> V_195 . V_196 ) ;
F_140 ( V_61 ) ;
}
return 0 ;
}
static void F_186 ( void )
{
F_187 ( & V_294 ) ;
}
static void F_188 ( void )
{
F_189 ( & V_294 ) ;
}
static int F_190 ( struct V_203 * V_295 ,
T_8 V_296 , void * V_297 )
{
struct V_71 * V_69 = NULL ;
struct V_3 * V_4 = V_297 ;
struct V_1 * V_2 ;
struct V_65 * V_66 ;
struct V_243 * V_244 ;
T_3 V_298 = 1 ;
T_3 V_102 ;
int V_117 = V_211 ;
F_73 (fcoe, &fcoe_hostlist, list) {
if ( V_2 -> V_4 == V_4 ) {
V_69 = V_2 -> V_7 . V_70 ;
break;
}
}
if ( ! V_69 ) {
V_117 = V_299 ;
goto V_48;
}
switch ( V_296 ) {
case V_300 :
case V_301 :
V_298 = 0 ;
break;
case V_302 :
case V_303 :
break;
case V_304 :
if ( V_4 -> V_95 & V_106 )
break;
V_102 = V_4 -> V_105 - ( sizeof( struct V_108 ) +
sizeof( struct V_109 ) ) ;
if ( V_102 >= V_305 )
F_52 ( V_69 , V_102 ) ;
break;
case V_306 :
break;
case V_307 :
F_191 ( & V_2 -> V_308 ) ;
V_66 = F_42 ( V_2 -> V_7 . V_70 ) ;
F_192 ( V_309 , & V_66 -> V_178 ) ;
goto V_48;
break;
case V_310 :
F_48 ( V_69 , V_4 ) ;
break;
default:
F_2 ( V_4 , L_56
L_57 , V_296 ) ;
}
F_55 ( V_69 ) ;
if ( V_298 && ! F_193 ( V_69 ) )
F_194 ( & V_2 -> V_7 ) ;
else if ( F_195 ( & V_2 -> V_7 ) ) {
V_244 = F_141 ( V_69 -> V_237 , F_116 () ) ;
V_244 -> V_311 ++ ;
F_121 () ;
F_81 ( V_69 ) ;
}
V_48:
return V_117 ;
}
static int F_196 ( struct V_3 * V_4 )
{
struct V_1 * V_2 ;
int V_117 = 0 ;
F_49 ( & V_312 ) ;
F_31 () ;
V_2 = F_197 ( V_4 ) ;
F_36 () ;
if ( V_2 ) {
F_195 ( & V_2 -> V_7 ) ;
F_81 ( V_2 -> V_7 . V_70 ) ;
} else
V_117 = - V_187 ;
F_50 ( & V_312 ) ;
return V_117 ;
}
static int F_198 ( struct V_3 * V_4 )
{
struct V_1 * V_2 ;
int V_117 = 0 ;
F_49 ( & V_312 ) ;
F_31 () ;
V_2 = F_197 ( V_4 ) ;
F_36 () ;
if ( ! V_2 )
V_117 = - V_187 ;
else if ( ! F_193 ( V_2 -> V_7 . V_70 ) )
F_194 ( & V_2 -> V_7 ) ;
F_50 ( & V_312 ) ;
return V_117 ;
}
static int F_199 ( struct V_3 * V_4 )
{
struct V_1 * V_2 ;
struct V_71 * V_69 ;
struct V_65 * V_66 ;
int V_117 = 0 ;
F_49 ( & V_312 ) ;
F_31 () ;
V_2 = F_197 ( V_4 ) ;
if ( ! V_2 ) {
V_117 = - V_187 ;
goto V_313;
}
V_69 = V_2 -> V_7 . V_70 ;
V_66 = F_42 ( V_69 ) ;
F_191 ( & V_2 -> V_308 ) ;
F_192 ( V_309 , & V_66 -> V_178 ) ;
V_313:
F_36 () ;
F_50 ( & V_312 ) ;
return V_117 ;
}
static void V_179 ( struct V_314 * V_315 )
{
struct V_65 * V_66 ;
struct V_1 * V_2 ;
int V_168 = 0 ;
V_66 = F_25 ( V_315 , struct V_65 , V_178 ) ;
F_49 ( & V_312 ) ;
V_168 = V_66 -> V_69 -> V_113 ? 1 : 0 ;
V_2 = V_66 -> V_72 ;
F_77 ( V_66 -> V_69 ) ;
if ( ! V_168 )
F_30 ( V_2 ) ;
F_50 ( & V_312 ) ;
}
static bool F_200 ( struct V_3 * V_4 )
{
return true ;
}
static int F_201 ( struct V_3 * V_4 , enum V_43 V_44 )
{
int V_117 = 0 ;
struct V_1 * V_2 ;
struct V_71 * V_69 ;
F_49 ( & V_312 ) ;
F_31 () ;
if ( F_202 ( V_4 ) ) {
V_117 = - V_316 ;
goto V_313;
}
V_2 = F_13 ( V_4 , V_44 ) ;
if ( F_109 ( V_2 ) ) {
V_117 = F_203 ( V_2 ) ;
goto V_313;
}
V_69 = F_92 ( V_2 , & V_4 -> V_39 , 0 ) ;
if ( F_109 ( V_69 ) ) {
F_75 ( V_158 L_58 ,
V_4 -> V_133 ) ;
V_117 = - V_317 ;
F_36 () ;
F_30 ( V_2 ) ;
goto V_318;
}
V_2 -> V_7 . V_70 = V_69 ;
F_204 ( V_69 ) ;
V_69 -> V_319 = V_320 ;
F_205 ( V_69 ) ;
if ( ! F_193 ( V_69 ) )
F_194 ( & V_2 -> V_7 ) ;
V_313:
F_36 () ;
V_318:
F_50 ( & V_312 ) ;
return V_117 ;
}
int F_55 ( struct V_71 * V_69 )
{
struct V_3 * V_4 = F_61 ( V_69 ) ;
struct V_321 V_322 ;
if ( ! F_206 ( V_4 , & V_322 ) ) {
V_69 -> V_323 &=
~ ( V_324 | V_325 ) ;
if ( V_322 . V_326 & ( V_327 |
V_328 ) )
V_69 -> V_323 |= V_324 ;
if ( V_322 . V_326 & V_329 )
V_69 -> V_323 |=
V_325 ;
switch ( F_207 ( & V_322 ) ) {
case V_330 :
V_69 -> V_331 = V_324 ;
break;
case V_332 :
V_69 -> V_331 = V_325 ;
break;
}
return 0 ;
}
return - 1 ;
}
int F_193 ( struct V_71 * V_69 )
{
struct V_3 * V_4 = F_61 ( V_69 ) ;
if ( F_208 ( V_4 ) )
return 0 ;
return - 1 ;
}
void F_82 ( struct V_71 * V_69 )
{
struct V_189 * V_333 ;
struct V_216 * V_217 ;
struct V_334 * V_308 ;
struct V_60 * V_61 , * V_335 ;
struct V_60 * V_223 ;
unsigned int V_188 ;
F_209 (cpu) {
V_333 = & F_106 ( V_193 , V_188 ) ;
F_112 ( & V_333 -> V_195 . V_196 ) ;
V_308 = & V_333 -> V_195 ;
V_223 = V_308 -> V_335 ;
for ( V_61 = V_223 ; V_61 != (struct V_60 * ) V_308 ;
V_61 = V_335 ) {
V_335 = V_61 -> V_335 ;
V_217 = F_137 ( V_61 ) ;
if ( V_217 -> V_232 == V_69 ) {
F_210 ( V_61 , V_308 ) ;
F_120 ( V_61 ) ;
}
}
if ( ! V_333 -> V_192 || ! F_211 ( V_188 ) ) {
F_113 ( & V_333 -> V_195 . V_196 ) ;
continue;
}
V_61 = F_212 ( 0 ) ;
if ( ! V_61 ) {
F_113 ( & V_333 -> V_195 . V_196 ) ;
continue;
}
V_61 -> V_286 = F_166 ;
F_119 ( & V_333 -> V_195 , V_61 ) ;
if ( V_333 -> V_195 . V_68 == 1 )
F_111 ( V_333 -> V_192 ) ;
F_113 ( & V_333 -> V_195 . V_196 ) ;
F_213 ( & V_276 ) ;
}
}
int F_214 ( struct V_170 * V_171 )
{
struct V_71 * V_69 = F_99 ( V_171 ) ;
struct V_65 * V_66 = F_42 ( V_69 ) ;
struct V_1 * V_2 = V_66 -> V_72 ;
F_195 ( & V_2 -> V_7 ) ;
F_81 ( V_2 -> V_7 . V_70 ) ;
if ( ! F_193 ( V_2 -> V_7 . V_70 ) )
F_194 ( & V_2 -> V_7 ) ;
return 0 ;
}
static struct V_1 *
F_197 ( const struct V_3 * V_4 )
{
struct V_1 * V_2 ;
F_73 (fcoe, &fcoe_hostlist, list) {
if ( V_2 -> V_4 == V_4 )
return V_2 ;
}
return NULL ;
}
static struct V_71 * F_202 ( const struct V_3 * V_4 )
{
struct V_1 * V_2 ;
V_2 = F_197 ( V_4 ) ;
return ( V_2 ) ? V_2 -> V_7 . V_70 : NULL ;
}
static int F_204 ( const struct V_71 * V_69 )
{
struct V_1 * V_2 ;
struct V_65 * V_66 ;
V_2 = F_197 ( F_61 ( V_69 ) ) ;
if ( ! V_2 ) {
V_66 = F_42 ( V_69 ) ;
V_2 = V_66 -> V_72 ;
F_215 ( & V_2 -> V_308 , & V_336 ) ;
}
return 0 ;
}
static int T_5 F_216 ( void )
{
struct V_189 * V_190 ;
unsigned int V_188 ;
int V_117 = 0 ;
V_309 = F_217 ( L_59 , 0 , 0 ) ;
if ( ! V_309 )
return - V_50 ;
V_117 = F_218 ( & V_337 ) ;
if ( V_117 ) {
F_75 ( V_158 L_60
L_61 ) ;
return V_117 ;
}
F_49 ( & V_312 ) ;
F_209 (cpu) {
V_190 = & F_106 ( V_193 , V_188 ) ;
F_53 ( & V_190 -> V_195 ) ;
}
F_219 (cpu)
F_105 ( V_188 ) ;
V_117 = F_220 ( & V_338 ) ;
if ( V_117 )
goto V_339;
F_186 () ;
V_117 = F_101 () ;
if ( V_117 )
goto V_339;
F_50 ( & V_312 ) ;
return 0 ;
V_339:
F_219 (cpu) {
F_114 ( V_188 ) ;
}
F_50 ( & V_312 ) ;
F_221 ( V_309 ) ;
return V_117 ;
}
static void T_6 F_222 ( void )
{
struct V_1 * V_2 , * V_340 ;
struct V_65 * V_66 ;
unsigned int V_188 ;
F_49 ( & V_312 ) ;
F_188 () ;
F_31 () ;
F_223 (fcoe, tmp, &fcoe_hostlist, list) {
F_191 ( & V_2 -> V_308 ) ;
V_66 = F_42 ( V_2 -> V_7 . V_70 ) ;
F_192 ( V_309 , & V_66 -> V_178 ) ;
}
F_36 () ;
F_224 ( & V_338 ) ;
F_219 (cpu)
F_114 ( V_188 ) ;
F_50 ( & V_312 ) ;
F_221 ( V_309 ) ;
F_103 () ;
F_225 ( & V_337 ) ;
}
static void F_226 ( struct V_341 * V_342 , struct V_134 * V_135 , void * V_290 )
{
struct V_5 * V_6 = V_290 ;
struct V_343 * V_344 = F_227 ( V_342 ) ;
struct V_71 * V_69 = V_344 -> V_70 ;
T_1 * V_345 ;
if ( F_109 ( V_135 ) )
goto V_346;
V_345 = F_228 ( V_135 ) -> V_347 ;
if ( F_43 ( V_345 ) ) {
if ( F_229 ( V_6 , V_69 , V_135 ) ) {
F_230 ( V_135 ) ;
return;
}
}
V_56 ( V_69 , V_345 ) ;
V_346:
F_231 ( V_342 , V_135 , V_69 ) ;
}
static void F_232 ( struct V_341 * V_342 , struct V_134 * V_135 , void * V_290 )
{
struct V_71 * V_69 = V_290 ;
static T_1 V_348 [ V_12 ] = { 0 } ;
if ( ! F_109 ( V_135 ) )
V_56 ( V_69 , V_348 ) ;
F_233 ( V_342 , V_135 , V_69 ) ;
}
static struct V_341 * F_234 ( struct V_71 * V_69 , T_3 V_349 ,
struct V_134 * V_135 , unsigned int V_350 ,
void (* F_235)( struct V_341 * ,
struct V_134 * ,
void * ) ,
void * V_290 , T_3 V_351 )
{
struct V_65 * V_66 = F_42 ( V_69 ) ;
struct V_1 * V_2 = V_66 -> V_72 ;
struct V_5 * V_6 = & V_2 -> V_7 ;
struct V_136 * V_137 = F_65 ( V_135 ) ;
switch ( V_350 ) {
case V_352 :
case V_353 :
if ( V_69 -> V_354 )
break;
return F_236 ( V_69 , V_349 , V_135 , V_350 , F_226 ,
V_6 , V_351 ) ;
case V_281 :
if ( F_68 ( V_137 -> V_231 ) != V_283 )
break;
return F_236 ( V_69 , V_349 , V_135 , V_350 , F_232 ,
V_69 , V_351 ) ;
}
return F_236 ( V_69 , V_349 , V_135 , V_350 , F_235 , V_290 , V_351 ) ;
}
static int F_237 ( struct V_172 * V_113 , bool V_355 )
{
struct V_170 * V_171 = F_98 ( V_113 ) ;
struct V_71 * V_169 = F_99 ( V_171 ) ;
struct V_65 * V_66 = F_42 ( V_169 ) ;
struct V_1 * V_2 = V_66 -> V_72 ;
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_71 * V_356 ;
int V_117 ;
char V_357 [ 32 ] ;
V_117 = F_238 ( V_113 ) ;
if ( V_117 ) {
F_239 ( V_113 -> V_182 , V_357 , sizeof( V_357 ) ) ;
F_75 ( V_158 L_62
L_63 ,
V_357 ) ;
return V_117 ;
}
F_49 ( & V_312 ) ;
V_356 = F_92 ( V_2 , & V_113 -> V_39 , 1 ) ;
F_50 ( & V_312 ) ;
if ( F_109 ( V_356 ) ) {
F_75 ( V_158 L_64 ,
V_4 -> V_133 ) ;
return - V_317 ;
}
if ( V_355 ) {
F_240 ( V_113 , V_358 ) ;
} else {
V_356 -> V_319 = V_320 ;
F_205 ( V_356 ) ;
F_241 ( V_356 ) ;
}
return 0 ;
}
static int F_242 ( struct V_172 * V_113 )
{
struct V_170 * V_171 = F_98 ( V_113 ) ;
struct V_71 * V_169 = F_99 ( V_171 ) ;
struct V_71 * V_356 = V_113 -> V_359 ;
struct V_65 * V_66 = F_42 ( V_356 ) ;
F_49 ( & V_169 -> V_94 ) ;
F_191 ( & V_356 -> V_308 ) ;
F_50 ( & V_169 -> V_94 ) ;
F_192 ( V_309 , & V_66 -> V_178 ) ;
return 0 ;
}
static int F_243 ( struct V_172 * V_113 , bool V_360 )
{
struct V_71 * V_69 = V_113 -> V_359 ;
if ( V_360 ) {
F_240 ( V_113 , V_358 ) ;
F_78 ( V_69 ) ;
} else {
V_69 -> V_319 = V_320 ;
F_205 ( V_69 ) ;
F_241 ( V_69 ) ;
}
return 0 ;
}
static void F_244 ( struct V_172 * V_113 )
{
struct V_71 * V_69 = V_113 -> V_359 ;
struct V_134 * V_135 ;
T_9 V_222 ;
snprintf ( F_63 ( V_69 -> V_118 ) , V_130 ,
L_65 , V_131 , V_132 ,
F_61 ( V_69 ) -> V_133 , V_113 -> V_361 ) ;
if ( V_69 -> V_362 != V_363 )
return;
V_222 = F_245 ( F_63 ( V_69 -> V_118 ) , 255 ) ;
V_135 = F_246 ( V_69 ,
sizeof( struct V_364 ) +
sizeof( struct V_365 ) + V_222 ) ;
if ( ! V_135 )
return;
V_69 -> V_366 . V_367 ( V_69 , V_368 , V_135 , V_369 ,
NULL , NULL , 3 * V_69 -> V_79 ) ;
}
static void F_247 ( struct V_71 * V_69 ,
struct V_370 * V_371 )
{
unsigned int V_188 ;
T_3 V_372 , V_373 , V_374 ;
struct V_243 * V_375 ;
struct V_376 * V_377 ;
struct V_378 V_379 ;
struct V_3 * V_4 = F_61 ( V_69 ) ;
V_372 = 0 ;
V_373 = 0 ;
V_374 = 0 ;
V_377 = (struct V_376 * ) V_371 ;
memset ( V_377 , 0 , sizeof( * V_377 ) ) ;
F_209 (cpu) {
V_375 = F_141 ( V_69 -> V_237 , V_188 ) ;
V_372 += V_375 -> V_311 ;
V_373 += V_375 -> V_380 ;
V_374 += V_375 -> V_381 ;
}
V_377 -> V_382 = F_248 ( V_372 ) ;
V_377 -> V_383 = F_248 ( V_373 ) ;
V_377 -> V_384 = F_248 ( V_374 ) ;
V_377 -> V_385 = F_248 ( F_249 ( V_4 , & V_379 ) -> V_386 ) ;
}
static void F_250 ( struct V_71 * V_69 ,
T_3 V_387 , struct V_134 * V_135 )
{
struct V_65 * V_66 = F_42 ( V_69 ) ;
struct V_1 * V_2 = V_66 -> V_72 ;
if ( V_135 && F_170 ( V_135 ) == V_352 )
F_229 ( & V_2 -> V_7 , V_69 , V_135 ) ;
}
static int F_238 ( struct V_172 * V_113 )
{
struct V_170 * V_171 = F_98 ( V_113 ) ;
struct V_71 * V_169 = F_99 ( V_171 ) ;
struct V_71 * V_356 ;
int V_117 = 0 ;
char V_357 [ 32 ] ;
F_49 ( & V_169 -> V_94 ) ;
F_239 ( V_113 -> V_182 , V_357 , sizeof( V_357 ) ) ;
if ( ! memcmp ( & V_169 -> V_104 , & V_113 -> V_182 , sizeof( T_2 ) ) ) {
F_117 ( L_66
L_67 , V_357 ) ;
V_117 = - V_93 ;
goto V_48;
}
F_73 (vn_port, &n_port->vports, list) {
if ( ! memcmp ( & V_356 -> V_104 , & V_113 -> V_182 , sizeof( T_2 ) ) ) {
F_117 ( L_68
L_69 , V_357 ) ;
V_117 = - V_93 ;
break;
}
}
V_48:
F_50 ( & V_169 -> V_94 ) ;
return V_117 ;
}
