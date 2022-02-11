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
F_18 ( & V_2 -> V_7 , V_45 ) ;
V_2 -> V_7 . V_53 = V_54 ;
V_2 -> V_7 . V_55 = V_56 ;
V_2 -> V_7 . V_57 = V_58 ;
V_46 = F_1 ( V_2 , V_4 ) ;
if ( V_46 ) {
F_19 ( & V_2 -> V_7 ) ;
F_20 ( V_2 ) ;
F_21 ( V_4 ) ;
V_2 = F_15 ( V_46 ) ;
goto V_52;
}
goto V_49;
V_52:
F_22 ( V_47 ) ;
V_49:
return V_2 ;
}
static void F_23 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_5 * V_6 = & V_2 -> V_7 ;
T_1 V_11 [ V_12 ] ;
const struct V_13 * V_14 ;
F_24 () ;
F_25 ( & V_2 -> V_36 ) ;
F_25 ( & V_2 -> V_41 ) ;
F_26 () ;
memcpy ( V_11 , ( T_1 [ 6 ] ) V_30 , V_12 ) ;
F_27 ( V_4 , V_11 ) ;
if ( V_6 -> V_27 )
F_27 ( V_4 , V_6 -> V_26 ) ;
if ( V_6 -> V_31 == V_32 ) {
F_28 ( V_4 , V_33 ) ;
F_28 ( V_4 , V_34 ) ;
} else
F_28 ( V_4 , V_35 ) ;
V_14 = V_4 -> V_15 ;
if ( V_14 -> V_59 ) {
if ( V_14 -> V_59 ( V_4 ) )
F_2 ( V_4 , L_6
L_2 ) ;
}
F_29 () ;
F_19 ( V_6 ) ;
F_20 ( V_2 ) ;
F_21 ( V_4 ) ;
F_22 ( V_47 ) ;
}
static int V_42 ( struct V_60 * V_61 , struct V_3 * V_4 ,
struct V_62 * V_63 ,
struct V_3 * V_64 )
{
struct V_1 * V_2 ;
V_2 = F_30 ( V_63 , struct V_1 , V_41 ) ;
F_31 ( & V_2 -> V_7 , V_61 ) ;
return 0 ;
}
static void F_32 ( struct V_65 * V_66 , struct V_60 * V_61 )
{
if ( V_66 -> V_67 . V_68 )
F_33 ( V_66 -> V_69 , V_61 ) ;
else if ( F_34 ( V_61 ) )
F_33 ( V_66 -> V_69 , V_61 ) ;
}
static void V_54 ( struct V_5 * V_6 , struct V_60 * V_61 )
{
V_61 -> V_40 = F_35 ( V_6 ) -> V_4 ;
F_32 ( F_36 ( V_6 -> V_70 ) , V_61 ) ;
}
static void V_56 ( struct V_71 * V_69 , T_1 * V_25 )
{
struct V_65 * V_66 = F_36 ( V_69 ) ;
struct V_1 * V_2 = V_66 -> V_72 ;
F_24 () ;
if ( ! F_37 ( V_66 -> V_73 ) )
F_27 ( V_2 -> V_4 , V_66 -> V_73 ) ;
if ( ! F_37 ( V_25 ) )
F_8 ( V_2 -> V_4 , V_25 ) ;
memcpy ( V_66 -> V_73 , V_25 , V_12 ) ;
F_29 () ;
}
static T_1 * V_58 ( struct V_71 * V_69 )
{
struct V_65 * V_66 = F_36 ( V_69 ) ;
return V_66 -> V_73 ;
}
static int F_38 ( struct V_71 * V_69 )
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
F_39 ( V_69 ) ;
F_40 ( V_69 ) ;
V_69 -> V_86 = 0 ;
V_69 -> V_87 = 0 ;
V_69 -> V_88 = 0 ;
V_69 -> V_89 = 0 ;
V_69 -> V_90 = 0 ;
return 0 ;
}
static void F_41 ( struct V_71 * V_69 ,
struct V_3 * V_4 )
{
F_42 ( & V_69 -> V_91 ) ;
if ( V_4 -> V_92 & V_93 )
V_69 -> V_94 = 1 ;
else
V_69 -> V_94 = 0 ;
if ( V_4 -> V_92 & V_95 ) {
V_69 -> V_86 = 1 ;
F_2 ( V_4 , L_7 ) ;
} else {
V_69 -> V_86 = 0 ;
}
if ( V_4 -> V_92 & V_96 ) {
V_69 -> V_87 = 1 ;
V_69 -> V_90 = V_4 -> V_97 ;
F_2 ( V_4 , L_8 ,
V_69 -> V_90 ) ;
} else {
V_69 -> V_87 = 0 ;
V_69 -> V_90 = 0 ;
}
if ( V_4 -> V_98 ) {
V_69 -> V_88 = 1 ;
V_69 -> V_89 = V_4 -> V_98 ;
F_2 ( V_4 , L_9 ,
V_69 -> V_89 ) ;
} else {
V_69 -> V_88 = 0 ;
V_69 -> V_89 = 0 ;
}
F_43 ( & V_69 -> V_91 ) ;
}
static int F_44 ( struct V_71 * V_69 , struct V_3 * V_4 )
{
T_2 V_99 ;
T_3 V_100 , V_101 ;
struct V_1 * V_2 ;
struct V_65 * V_66 ;
V_66 = F_36 ( V_69 ) ;
V_2 = V_66 -> V_72 ;
V_99 = V_4 -> V_102 ;
if ( V_4 -> V_92 & V_103 ) {
V_99 = V_104 ;
F_2 ( V_4 , L_10 , V_99 ) ;
}
V_99 -= ( sizeof( struct V_105 ) + sizeof( struct V_106 ) ) ;
if ( F_45 ( V_69 , V_99 ) )
return - V_107 ;
F_41 ( V_69 , V_4 ) ;
F_46 ( & V_66 -> V_67 ) ;
V_66 -> V_108 = 0 ;
F_47 ( & V_66 -> V_109 , V_110 , ( unsigned long ) V_69 ) ;
F_48 ( V_69 ) ;
if ( ! V_69 -> V_111 ) {
if ( F_49 ( V_4 , & V_100 , V_112 ) )
V_100 = F_50 ( V_2 -> V_7 . V_26 , 1 , 0 ) ;
F_51 ( V_69 , V_100 ) ;
if ( F_49 ( V_4 , & V_101 , V_113 ) )
V_101 = F_50 ( V_2 -> V_7 . V_26 ,
2 , 0 ) ;
F_52 ( V_69 , V_101 ) ;
}
return 0 ;
}
static int F_53 ( struct V_71 * V_69 , struct V_114 * V_40 )
{
int V_115 = 0 ;
V_69 -> V_116 -> V_117 = V_118 ;
V_69 -> V_116 -> V_119 = V_120 ;
V_69 -> V_116 -> V_121 = 0 ;
V_69 -> V_116 -> V_122 = V_123 ;
if ( V_69 -> V_111 )
V_69 -> V_116 -> V_124 = V_125 ;
else
V_69 -> V_116 -> V_124 = V_126 ;
V_115 = F_54 ( V_69 -> V_116 , V_40 ) ;
if ( V_115 ) {
F_2 ( F_55 ( V_69 ) , L_11
L_12 ) ;
return V_115 ;
}
if ( ! V_69 -> V_111 )
F_56 ( V_69 -> V_116 ) = V_127 ;
snprintf ( F_57 ( V_69 -> V_116 ) , V_128 ,
L_13 , V_129 , V_130 ,
F_55 ( V_69 ) -> V_131 ) ;
return 0 ;
}
static void F_58 ( struct V_71 * V_69 , struct V_3 * V_4 )
{
struct V_1 * V_2 ;
struct V_65 * V_66 ;
struct V_3 * V_23 ;
int V_115 ;
struct V_132 V_133 ;
V_66 = F_36 ( V_69 ) ;
V_2 = V_66 -> V_72 ;
V_23 = V_2 -> V_23 ;
if ( ! V_23 )
return;
if ( V_69 -> V_111 )
return;
if ( V_23 -> V_15 -> V_134 ) {
memset ( & V_133 , 0 , sizeof( V_133 ) ) ;
V_115 = V_23 -> V_15 -> V_134 ( V_23 ,
& V_133 ) ;
if ( V_115 ) {
F_59 ( V_135 L_14
L_15 ) ;
return;
}
snprintf ( F_60 ( V_69 -> V_116 ) ,
V_136 ,
L_16 ,
V_133 . V_137 ) ;
snprintf ( F_61 ( V_69 -> V_116 ) ,
V_136 ,
L_16 ,
V_133 . V_138 ) ;
snprintf ( F_62 ( V_69 -> V_116 ) ,
V_128 ,
L_16 ,
V_133 . V_139 ) ;
snprintf ( F_63 ( V_69 -> V_116 ) ,
V_128 ,
L_16 ,
V_133 . V_140 ) ;
snprintf ( F_64 ( V_69 -> V_116 ) ,
V_141 ,
L_16 ,
V_133 . V_142 ) ;
snprintf ( F_65 ( V_69 -> V_116 ) ,
V_141 ,
L_16 ,
V_133 . V_143 ) ;
snprintf ( F_66 ( V_69 -> V_116 ) ,
V_141 ,
L_16 ,
V_133 . V_144 ) ;
snprintf ( F_67 ( V_69 -> V_116 ) ,
V_141 ,
L_16 ,
V_133 . V_145 ) ;
V_69 -> V_146 = 1 ;
} else {
V_69 -> V_146 = 0 ;
F_59 ( V_135 L_17 ) ;
}
}
static bool F_68 ( struct V_147 * V_148 )
{
struct V_149 * V_150 = F_69 ( V_148 ) ;
struct V_151 * V_152 ;
if ( F_70 ( F_71 ( V_148 ) ) &&
( F_71 ( V_148 ) -> V_153 > V_154 ) )
return true ;
else if ( ( F_71 ( V_148 ) == NULL ) &&
( V_150 -> V_155 == V_156 ) &&
( F_72 ( V_150 -> V_157 ) == V_158 ) ) {
V_152 = F_73 ( V_148 , sizeof( * V_152 ) ) ;
if ( ( V_152 -> V_159 & V_160 ) &&
( F_74 ( V_152 -> V_161 ) > V_154 ) )
return true ;
}
return false ;
}
static inline int F_75 ( struct V_71 * V_69 )
{
struct V_65 * V_66 = F_36 ( V_69 ) ;
struct V_1 * V_2 = V_66 -> V_72 ;
struct V_1 * V_162 = NULL ;
struct V_3 * V_163 , * V_164 ;
T_4 V_165 = V_166 ;
T_4 V_167 = V_168 ;
if ( ! V_69 -> V_88 || ! V_69 -> V_89 ||
( V_69 -> V_89 >= V_167 ) ) {
V_69 -> V_89 = 0 ;
goto V_169;
}
if ( V_2 -> V_4 -> V_17 & V_22 )
V_164 = F_3 ( V_2 -> V_4 ) ;
else
V_164 = V_2 -> V_4 ;
F_76 (oldfcoe, &fcoe_hostlist, list) {
if ( V_162 -> V_4 -> V_17 & V_22 )
V_163 = F_3 ( V_162 -> V_4 ) ;
else
V_163 = V_162 -> V_4 ;
if ( V_164 == V_163 ) {
V_2 -> V_170 = V_162 -> V_170 ;
break;
}
}
if ( V_2 -> V_170 ) {
if ( ! F_77 ( V_69 , V_2 -> V_170 , F_68 ) ) {
F_59 ( V_171 L_18
L_19 ,
V_2 -> V_170 , V_2 -> V_4 -> V_131 ) ;
return - V_51 ;
}
} else {
V_2 -> V_170 = F_78 ( V_69 , V_172 ,
V_166 , V_69 -> V_89 ,
F_68 ) ;
if ( ! V_2 -> V_170 ) {
F_59 ( V_171 L_20
L_21 ,
V_2 -> V_4 -> V_131 ) ;
return - V_51 ;
}
}
V_165 += V_69 -> V_89 + 1 ;
V_169:
if ( ! F_78 ( V_69 , V_172 , V_165 , V_167 , NULL ) ) {
F_59 ( V_171 L_22
L_23 , V_2 -> V_4 -> V_131 ) ;
return - V_51 ;
}
return 0 ;
}
static void F_79 ( struct V_71 * V_69 )
{
struct V_65 * V_66 = F_36 ( V_69 ) ;
struct V_1 * V_2 = V_66 -> V_72 ;
struct V_3 * V_4 = V_2 -> V_4 ;
F_2 ( V_4 , L_24 ) ;
F_80 ( V_69 ) ;
F_81 ( V_69 ) ;
F_82 ( & V_66 -> V_109 ) ;
F_83 ( V_69 ) ;
F_24 () ;
if ( ! F_37 ( V_66 -> V_73 ) )
F_27 ( V_4 , V_66 -> V_73 ) ;
F_29 () ;
F_84 ( V_69 ) ;
F_85 ( V_69 -> V_116 ) ;
F_86 ( V_69 -> V_116 ) ;
F_87 ( V_69 ) ;
F_88 ( V_69 ) ;
F_89 ( V_69 ) ;
F_90 ( V_69 -> V_116 ) ;
}
static int F_91 ( struct V_71 * V_69 , T_4 V_173 ,
struct V_174 * V_175 , unsigned int V_176 )
{
struct V_3 * V_4 = F_55 ( V_69 ) ;
if ( V_4 -> V_15 -> V_177 )
return V_4 -> V_15 -> V_177 ( V_4 ,
V_173 , V_175 ,
V_176 ) ;
return 0 ;
}
static int F_92 ( struct V_71 * V_69 , T_4 V_173 ,
struct V_174 * V_175 , unsigned int V_176 )
{
struct V_3 * V_4 = F_55 ( V_69 ) ;
if ( V_4 -> V_15 -> V_178 )
return V_4 -> V_15 -> V_178 ( V_4 , V_173 ,
V_175 , V_176 ) ;
return 0 ;
}
static int F_93 ( struct V_71 * V_69 , T_4 V_173 )
{
struct V_3 * V_4 = F_55 ( V_69 ) ;
if ( V_4 -> V_15 -> V_179 )
return V_4 -> V_15 -> V_179 ( V_4 , V_173 ) ;
return 0 ;
}
static struct V_71 * F_94 ( struct V_1 * V_2 ,
struct V_114 * V_180 , int V_181 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_71 * V_69 , * V_182 ;
struct V_65 * V_66 ;
struct V_183 * V_184 ;
int V_115 ;
struct V_185 * V_111 = F_95 ( V_180 ) ;
F_2 ( V_4 , L_25 ) ;
if ( ! V_181 )
V_69 = F_96 ( & V_186 , sizeof( * V_66 ) ) ;
else
V_69 = F_97 ( V_111 , sizeof( * V_66 ) ) ;
if ( ! V_69 ) {
F_2 ( V_4 , L_26 ) ;
V_115 = - V_51 ;
goto V_49;
}
V_66 = F_36 ( V_69 ) ;
V_66 -> V_69 = V_69 ;
V_66 -> V_72 = V_2 ;
V_66 -> V_187 = V_188 ;
V_66 -> V_189 = V_190 ;
F_98 ( & V_66 -> V_191 , V_192 ) ;
V_115 = F_38 ( V_69 ) ;
if ( V_115 ) {
F_2 ( V_4 , L_27
L_28 ) ;
goto V_193;
}
if ( V_181 ) {
F_2 ( V_4 , L_29
L_30 ,
V_111 -> V_194 , V_111 -> V_195 ) ;
F_51 ( V_69 , V_111 -> V_194 ) ;
F_52 ( V_69 , V_111 -> V_195 ) ;
}
V_115 = F_44 ( V_69 , V_4 ) ;
if ( V_115 ) {
F_2 ( V_4 , L_31
L_28 ) ;
goto V_196;
}
V_115 = F_53 ( V_69 , V_180 ) ;
if ( V_115 ) {
F_2 ( V_4 , L_32
L_28 ) ;
goto V_196;
}
V_115 = F_99 ( V_69 , & V_2 -> V_7 , & V_197 , 1 ) ;
if ( V_115 ) {
F_2 ( V_4 , L_33
L_28 ) ;
goto V_196;
}
F_58 ( V_69 , V_4 ) ;
if ( ! V_181 )
V_115 = F_75 ( V_69 ) ;
else {
V_184 = F_100 ( V_111 ) ;
V_182 = F_101 ( V_184 ) ;
V_115 = F_102 ( V_182 , V_69 ) ;
}
if ( V_115 ) {
F_2 ( V_4 , L_34 ) ;
goto V_196;
}
return V_69 ;
V_196:
F_88 ( V_69 ) ;
V_193:
F_90 ( V_69 -> V_116 ) ;
V_49:
return F_15 ( V_115 ) ;
}
static int T_5 F_103 ( void )
{
V_126 =
F_104 ( & V_198 ) ;
V_125 =
F_104 ( & V_199 ) ;
if ( ! V_126 ) {
F_59 ( V_171 L_35 ) ;
return - V_200 ;
}
return 0 ;
}
static int T_6 F_105 ( void )
{
F_106 ( V_126 ) ;
F_106 ( V_125 ) ;
V_126 = NULL ;
V_125 = NULL ;
return 0 ;
}
static void F_107 ( unsigned int V_201 )
{
struct V_202 * V_203 ;
struct V_204 * V_205 ;
V_203 = & F_108 ( V_206 , V_201 ) ;
V_205 = F_109 ( V_207 ,
( void * ) V_203 , F_110 ( V_201 ) ,
L_36 , V_201 ) ;
if ( F_111 ( ! F_112 ( V_205 ) ) ) {
F_113 ( V_205 , V_201 ) ;
F_114 ( V_205 ) ;
F_115 ( & V_203 -> V_208 . V_209 ) ;
V_203 -> V_205 = V_205 ;
F_116 ( & V_203 -> V_208 . V_209 ) ;
}
}
static void F_117 ( unsigned int V_201 )
{
struct V_202 * V_203 ;
struct V_204 * V_205 ;
struct V_210 * V_211 ;
struct V_60 * V_61 ;
#ifdef F_118
struct V_202 * V_212 ;
unsigned V_213 = F_119 () ;
#endif
F_120 ( L_37 , V_201 ) ;
V_203 = & F_108 ( V_206 , V_201 ) ;
F_115 ( & V_203 -> V_208 . V_209 ) ;
V_205 = V_203 -> V_205 ;
V_203 -> V_205 = NULL ;
V_211 = V_203 -> V_214 ;
V_203 -> V_214 = NULL ;
V_203 -> V_215 = 0 ;
F_116 ( & V_203 -> V_208 . V_209 ) ;
#ifdef F_118
if ( V_201 != V_213 ) {
V_212 = & F_108 ( V_206 , V_213 ) ;
F_115 ( & V_212 -> V_208 . V_209 ) ;
if ( V_212 -> V_205 ) {
F_120 ( L_38 ,
V_201 , V_213 ) ;
while ( ( V_61 = F_121 ( & V_203 -> V_208 ) ) != NULL )
F_122 ( & V_212 -> V_208 , V_61 ) ;
F_116 ( & V_212 -> V_208 . V_209 ) ;
} else {
while ( ( V_61 = F_121 ( & V_203 -> V_208 ) ) != NULL )
F_123 ( V_61 ) ;
F_116 ( & V_212 -> V_208 . V_209 ) ;
}
} else {
F_115 ( & V_203 -> V_208 . V_209 ) ;
while ( ( V_61 = F_121 ( & V_203 -> V_208 ) ) != NULL )
F_123 ( V_61 ) ;
F_116 ( & V_203 -> V_208 . V_209 ) ;
}
F_124 () ;
#else
F_115 ( & V_203 -> V_208 . V_209 ) ;
while ( ( V_61 = F_121 ( & V_203 -> V_208 ) ) != NULL )
F_123 ( V_61 ) ;
F_116 ( & V_203 -> V_208 . V_209 ) ;
#endif
if ( V_205 )
F_125 ( V_205 ) ;
if ( V_211 )
F_126 ( V_211 ) ;
}
static int F_127 ( struct V_216 * V_217 ,
unsigned long V_218 , void * V_219 )
{
unsigned V_201 = ( unsigned long ) V_219 ;
switch ( V_218 ) {
case V_220 :
case V_221 :
F_120 ( L_39 , V_201 ) ;
F_107 ( V_201 ) ;
break;
case V_222 :
case V_223 :
F_120 ( L_40 , V_201 ) ;
F_117 ( V_201 ) ;
break;
default:
break;
}
return V_224 ;
}
static inline unsigned int F_128 ( void )
{
static unsigned int V_225 ;
V_225 = F_129 ( V_225 , V_226 ) ;
if ( V_225 >= V_227 )
V_225 = F_130 ( V_226 ) ;
return V_225 ;
}
static int V_38 ( struct V_60 * V_61 , struct V_3 * V_4 ,
struct V_62 * V_63 , struct V_3 * V_228 )
{
struct V_71 * V_69 ;
struct V_229 * V_230 ;
struct V_1 * V_2 ;
struct V_149 * V_150 ;
struct V_202 * V_231 ;
struct V_232 * V_233 ;
unsigned int V_201 ;
V_2 = F_30 ( V_63 , struct V_1 , V_36 ) ;
V_69 = V_2 -> V_7 . V_70 ;
if ( F_131 ( ! V_69 ) ) {
F_2 ( V_4 , L_41 ) ;
goto V_234;
}
if ( ! V_69 -> V_74 )
goto V_234;
F_2 ( V_4 , L_42
L_43 ,
V_61 -> V_235 , V_61 -> V_153 , V_61 -> V_236 , V_61 -> V_237 ,
F_132 ( V_61 ) , F_133 ( V_61 ) ,
V_61 -> V_238 , V_61 -> V_40 ? V_61 -> V_40 -> V_131 : L_44 ) ;
V_233 = F_134 ( V_61 ) ;
if ( F_135 ( & V_2 -> V_7 ) &&
F_136 ( V_233 -> V_239 , V_2 -> V_7 . V_240 ) ) {
F_2 ( V_4 , L_45 ,
V_233 -> V_239 ) ;
goto V_46;
}
if ( F_131 ( ( V_61 -> V_235 < V_241 ) ||
! F_137 ( V_61 , V_242 ) ) )
goto V_46;
F_138 ( V_61 , sizeof( struct V_105 ) ) ;
V_150 = (struct V_149 * ) F_139 ( V_61 ) ;
if ( F_140 ( & V_233 -> V_243 [ 3 ] ) != F_140 ( V_150 -> V_244 ) ) {
F_2 ( V_4 , L_46 ,
V_233 -> V_243 ) ;
goto V_46;
}
V_230 = F_141 ( V_61 ) ;
V_230 -> V_245 = V_69 ;
if ( F_140 ( V_150 -> V_246 ) & V_247 )
V_201 = F_72 ( V_150 -> V_248 ) & V_249 ;
else {
if ( F_72 ( V_150 -> V_157 ) == V_158 )
V_201 = F_128 () ;
else
V_201 = F_72 ( V_150 -> V_157 ) & V_249 ;
}
if ( V_201 >= V_227 )
goto V_46;
V_231 = & F_108 ( V_206 , V_201 ) ;
F_142 ( & V_231 -> V_208 . V_209 ) ;
if ( F_131 ( ! V_231 -> V_205 ) ) {
F_2 ( V_4 , L_47
L_48
L_49 ) ;
F_143 ( & V_231 -> V_208 . V_209 ) ;
V_201 = F_130 ( V_226 ) ;
V_231 = & F_108 ( V_206 , V_201 ) ;
F_142 ( & V_231 -> V_208 . V_209 ) ;
if ( ! V_231 -> V_205 ) {
F_143 ( & V_231 -> V_208 . V_209 ) ;
goto V_46;
}
}
F_122 ( & V_231 -> V_208 , V_61 ) ;
if ( V_231 -> V_205 -> V_250 == V_251 )
F_114 ( V_231 -> V_205 ) ;
F_143 ( & V_231 -> V_208 . V_209 ) ;
return 0 ;
V_46:
F_144 ( V_69 -> V_252 , F_119 () ) -> V_253 ++ ;
F_124 () ;
V_234:
F_123 ( V_61 ) ;
return - 1 ;
}
static int F_145 ( struct V_60 * V_61 , int V_254 )
{
struct V_202 * V_231 ;
int V_115 ;
V_231 = & F_146 ( V_206 ) ;
V_115 = F_147 ( V_61 , V_254 , V_231 ) ;
F_148 ( V_206 ) ;
return V_115 ;
}
static int F_149 ( struct V_71 * V_69 , struct V_147 * V_148 )
{
int V_255 ;
T_2 V_256 ;
struct V_232 * V_233 ;
struct V_106 * V_257 ;
struct V_60 * V_61 ;
struct V_258 * V_259 ;
struct V_149 * V_150 ;
unsigned int V_260 ;
unsigned int V_254 ;
unsigned int V_261 ;
struct V_65 * V_66 = F_36 ( V_69 ) ;
struct V_1 * V_2 = V_66 -> V_72 ;
T_1 V_262 , V_263 ;
struct V_105 * V_264 ;
F_150 ( ( F_151 ( V_148 ) % sizeof( T_2 ) ) != 0 ) ;
V_150 = F_69 ( V_148 ) ;
V_61 = F_152 ( V_148 ) ;
V_255 = V_61 -> V_235 / V_265 ;
if ( ! V_69 -> V_74 ) {
F_123 ( V_61 ) ;
return 0 ;
}
if ( F_131 ( V_150 -> V_266 == V_267 ) &&
F_153 ( & V_2 -> V_7 , V_69 , V_61 ) )
return 0 ;
V_262 = F_154 ( V_148 ) ;
V_263 = F_155 ( V_148 ) ;
V_261 = sizeof( struct V_232 ) ;
V_260 = sizeof( struct V_105 ) ;
V_254 = sizeof( struct V_106 ) ;
V_255 = ( V_61 -> V_235 - V_254 + sizeof( V_256 ) ) / V_265 ;
if ( F_111 ( V_69 -> V_86 ) ) {
V_61 -> V_268 = V_269 ;
V_61 -> V_270 = F_156 ( V_61 ) ;
V_61 -> V_271 = V_61 -> V_235 ;
V_256 = 0 ;
} else {
V_61 -> V_268 = V_272 ;
V_256 = F_157 ( V_148 ) ;
}
if ( F_158 ( V_61 ) ) {
T_7 * V_273 ;
if ( F_145 ( V_61 , V_254 ) ) {
F_123 ( V_61 ) ;
return - V_51 ;
}
V_273 = & F_159 ( V_61 ) -> V_274 [ F_159 ( V_61 ) -> V_275 - 1 ] ;
V_257 = F_160 ( F_161 ( V_273 ) )
+ V_273 -> V_276 ;
} else {
V_257 = (struct V_106 * ) F_162 ( V_61 , V_254 ) ;
}
memset ( V_257 , 0 , sizeof( * V_257 ) ) ;
V_257 -> V_277 = V_263 ;
V_257 -> V_278 = F_163 ( ~ V_256 ) ;
if ( F_158 ( V_61 ) ) {
F_164 ( V_257 ) ;
V_257 = NULL ;
}
F_165 ( V_61 , V_261 + V_260 ) ;
F_166 ( V_61 ) ;
F_167 ( V_61 ) ;
V_61 -> V_279 = V_261 ;
V_61 -> V_280 = F_12 ( V_39 ) ;
V_61 -> V_281 = V_66 -> V_281 ;
if ( V_2 -> V_4 -> V_17 & V_22 &&
V_2 -> V_23 -> V_92 & V_282 ) {
V_61 -> V_283 = V_284 |
F_168 ( V_2 -> V_4 ) ;
V_61 -> V_40 = V_2 -> V_23 ;
} else
V_61 -> V_40 = V_2 -> V_4 ;
V_233 = F_134 ( V_61 ) ;
V_233 -> V_285 = F_12 ( V_39 ) ;
memcpy ( V_233 -> V_243 , V_2 -> V_7 . V_240 , V_12 ) ;
if ( V_2 -> V_7 . V_286 )
memcpy ( V_233 -> V_243 + 3 , V_150 -> V_244 , 3 ) ;
if ( F_131 ( V_2 -> V_7 . V_287 != V_158 ) )
memcpy ( V_233 -> V_239 , V_2 -> V_7 . V_26 , V_12 ) ;
else
memcpy ( V_233 -> V_239 , V_66 -> V_73 , V_12 ) ;
V_264 = (struct V_105 * ) ( V_233 + 1 ) ;
memset ( V_264 , 0 , sizeof( * V_264 ) ) ;
if ( V_288 )
F_169 ( V_264 , V_288 ) ;
V_264 -> V_289 = V_262 ;
if ( V_69 -> V_87 && F_170 ( V_148 ) ) {
F_159 ( V_61 ) -> V_290 = V_291 ;
F_159 ( V_61 ) -> V_292 = F_170 ( V_148 ) ;
} else {
F_159 ( V_61 ) -> V_290 = 0 ;
F_159 ( V_61 ) -> V_292 = 0 ;
}
V_259 = F_144 ( V_69 -> V_252 , F_119 () ) ;
V_259 -> V_293 ++ ;
V_259 -> V_294 += V_255 ;
F_124 () ;
V_245 ( V_148 ) = V_69 ;
F_32 ( V_66 , V_61 ) ;
return 0 ;
}
static void F_171 ( struct V_60 * V_61 )
{
F_172 ( & V_295 ) ;
}
static inline int F_173 ( struct V_71 * V_69 ,
struct V_147 * V_148 )
{
struct V_1 * V_2 ;
struct V_149 * V_150 ;
struct V_60 * V_61 = (struct V_60 * ) V_148 ;
struct V_258 * V_259 ;
if ( V_69 -> V_86 && V_61 -> V_268 == V_269 )
F_174 ( V_148 ) &= ~ V_296 ;
else
F_174 ( V_148 ) |= V_296 ;
V_150 = (struct V_149 * ) F_139 ( V_61 ) ;
V_150 = F_69 ( V_148 ) ;
if ( V_150 -> V_155 == V_297 && V_150 -> V_266 == V_298 )
return 0 ;
V_2 = ( (struct V_65 * ) F_36 ( V_69 ) ) -> V_72 ;
if ( F_135 ( & V_2 -> V_7 ) && F_175 ( V_148 ) == V_299 &&
F_140 ( V_150 -> V_300 ) == V_301 ) {
F_120 ( L_50 ) ;
return - V_107 ;
}
if ( ! ( F_174 ( V_148 ) & V_296 ) ||
F_176 ( F_177 ( V_148 ) ) == ~ F_178 ( ~ 0 , V_61 -> V_237 , V_61 -> V_235 ) ) {
F_174 ( V_148 ) &= ~ V_296 ;
return 0 ;
}
V_259 = F_144 ( V_69 -> V_252 , F_119 () ) ;
V_259 -> V_302 ++ ;
if ( V_259 -> V_302 < 5 )
F_59 ( V_303 L_51 ) ;
F_124 () ;
return - V_107 ;
}
static void F_179 ( struct V_60 * V_61 )
{
T_2 F_151 ;
struct V_71 * V_69 ;
struct V_229 * V_230 ;
struct V_258 * V_259 ;
struct V_106 V_211 ;
struct V_147 * V_148 ;
struct V_65 * V_66 ;
struct V_105 * V_264 ;
V_230 = F_141 ( V_61 ) ;
V_69 = V_230 -> V_245 ;
if ( F_131 ( ! V_69 ) ) {
if ( V_61 -> V_304 != F_171 )
F_2 ( V_61 -> V_40 , L_52 ) ;
F_123 ( V_61 ) ;
return;
}
F_2 ( V_61 -> V_40 , L_53
L_54 ,
V_61 -> V_235 , V_61 -> V_153 ,
V_61 -> V_236 , V_61 -> V_237 , F_132 ( V_61 ) ,
F_133 ( V_61 ) , V_61 -> V_238 ,
V_61 -> V_40 ? V_61 -> V_40 -> V_131 : L_44 ) ;
V_66 = F_36 ( V_69 ) ;
F_180 ( V_61 ) ;
V_264 = (struct V_105 * ) F_181 ( V_61 ) ;
V_259 = F_144 ( V_69 -> V_252 , F_119 () ) ;
if ( F_131 ( F_182 ( V_264 ) != V_288 ) ) {
if ( V_259 -> V_253 < 5 )
F_59 ( V_303 L_55
L_56
L_57
L_58
L_59 , F_182 ( V_264 ) ,
V_288 ) ;
goto V_305;
}
F_183 ( V_61 , sizeof( struct V_105 ) ) ;
F_151 = V_61 -> V_235 - sizeof( struct V_106 ) ;
V_259 -> V_306 ++ ;
V_259 -> V_307 += F_151 / V_265 ;
V_148 = (struct V_147 * ) V_61 ;
F_184 ( V_148 ) ;
V_245 ( V_148 ) = V_69 ;
F_154 ( V_148 ) = V_264 -> V_289 ;
if ( F_185 ( V_61 , F_151 , & V_211 , sizeof( V_211 ) ) )
goto V_305;
F_155 ( V_148 ) = V_211 . V_277 ;
F_177 ( V_148 ) = V_211 . V_278 ;
if ( F_186 ( V_61 , F_151 ) )
goto V_305;
if ( ! F_173 ( V_69 , V_148 ) ) {
F_124 () ;
F_187 ( V_69 , V_148 ) ;
return;
}
V_305:
V_259 -> V_253 ++ ;
F_124 () ;
F_123 ( V_61 ) ;
}
static int V_207 ( void * V_308 )
{
struct V_202 * V_203 = V_308 ;
struct V_60 * V_61 ;
struct V_309 V_310 ;
F_46 ( & V_310 ) ;
F_188 ( V_311 , - 20 ) ;
while ( ! F_189 () ) {
F_115 ( & V_203 -> V_208 . V_209 ) ;
F_190 ( & V_203 -> V_208 , & V_310 ) ;
F_116 ( & V_203 -> V_208 . V_209 ) ;
while ( ( V_61 = F_121 ( & V_310 ) ) != NULL )
F_179 ( V_61 ) ;
F_115 ( & V_203 -> V_208 . V_209 ) ;
if ( ! F_191 ( & V_203 -> V_208 ) ) {
F_192 ( V_251 ) ;
F_116 ( & V_203 -> V_208 . V_209 ) ;
F_193 () ;
F_192 ( V_312 ) ;
} else
F_116 ( & V_203 -> V_208 . V_209 ) ;
}
return 0 ;
}
static void F_194 ( void )
{
F_195 ( & V_313 ) ;
F_196 ( & V_314 ) ;
}
static void F_197 ( void )
{
F_198 ( & V_313 ) ;
F_199 ( & V_314 ) ;
}
static struct V_1 *
F_200 ( struct V_3 * V_4 )
{
struct V_1 * V_2 ;
struct V_3 * V_10 ;
F_76 (fcoe, &fcoe_hostlist, list) {
if ( V_2 -> V_4 -> V_17 & V_22 )
V_10 = F_3 ( V_2 -> V_4 ) ;
else
V_10 = V_2 -> V_4 ;
if ( V_4 == V_10 )
return V_2 ;
}
return NULL ;
}
static int F_201 ( struct V_216 * V_315 ,
T_8 V_316 , void * V_317 )
{
struct V_318 * V_319 = V_317 ;
struct V_1 * V_2 ;
struct V_3 * V_4 ;
struct V_65 * V_66 ;
int V_320 ;
if ( V_319 -> V_321 . V_322 != V_323 )
return V_224 ;
V_4 = F_202 ( & V_324 , V_319 -> V_325 ) ;
if ( ! V_4 )
return V_224 ;
V_2 = F_200 ( V_4 ) ;
F_21 ( V_4 ) ;
if ( ! V_2 )
return V_224 ;
if ( V_319 -> V_326 & V_327 )
V_320 = F_203 ( V_319 -> V_321 . V_281 ) - 1 ;
else
V_320 = V_319 -> V_321 . V_281 ;
if ( V_320 < 0 )
return V_224 ;
if ( V_319 -> V_321 . V_280 == V_43 ||
V_319 -> V_321 . V_280 == V_39 )
V_2 -> V_7 . V_281 = V_320 ;
if ( V_319 -> V_321 . V_280 == V_39 ) {
V_66 = F_36 ( V_2 -> V_7 . V_70 ) ;
V_66 -> V_281 = V_320 ;
}
return V_224 ;
}
static int F_204 ( struct V_216 * V_315 ,
T_8 V_316 , void * V_317 )
{
struct V_71 * V_69 = NULL ;
struct V_3 * V_4 = V_317 ;
struct V_1 * V_2 ;
struct V_65 * V_66 ;
struct V_258 * V_259 ;
T_2 V_328 = 1 ;
T_2 V_99 ;
int V_115 = V_224 ;
F_76 (fcoe, &fcoe_hostlist, list) {
if ( V_2 -> V_4 == V_4 ) {
V_69 = V_2 -> V_7 . V_70 ;
break;
}
}
if ( ! V_69 ) {
V_115 = V_329 ;
goto V_49;
}
switch ( V_316 ) {
case V_330 :
case V_331 :
V_328 = 0 ;
break;
case V_332 :
case V_333 :
break;
case V_334 :
if ( V_4 -> V_92 & V_103 )
break;
V_99 = V_4 -> V_102 - ( sizeof( struct V_105 ) +
sizeof( struct V_106 ) ) ;
if ( V_99 >= V_335 )
F_45 ( V_69 , V_99 ) ;
break;
case V_336 :
break;
case V_337 :
F_205 ( & V_2 -> V_338 ) ;
V_66 = F_36 ( V_2 -> V_7 . V_70 ) ;
F_206 ( V_339 , & V_66 -> V_191 ) ;
goto V_49;
break;
case V_340 :
F_41 ( V_69 , V_4 ) ;
break;
default:
F_2 ( V_4 , L_60
L_61 , V_316 ) ;
}
F_48 ( V_69 ) ;
if ( V_328 && ! F_207 ( V_69 ) )
F_208 ( & V_2 -> V_7 ) ;
else if ( F_209 ( & V_2 -> V_7 ) ) {
V_259 = F_144 ( V_69 -> V_252 , F_119 () ) ;
V_259 -> V_341 ++ ;
F_124 () ;
F_83 ( V_69 ) ;
}
V_49:
return V_115 ;
}
static int F_210 ( struct V_3 * V_4 )
{
struct V_1 * V_2 ;
int V_115 = 0 ;
F_42 ( & V_342 ) ;
F_24 () ;
V_2 = F_211 ( V_4 ) ;
F_29 () ;
if ( V_2 ) {
F_209 ( & V_2 -> V_7 ) ;
F_83 ( V_2 -> V_7 . V_70 ) ;
} else
V_115 = - V_200 ;
F_43 ( & V_342 ) ;
return V_115 ;
}
static int F_212 ( struct V_3 * V_4 )
{
struct V_1 * V_2 ;
int V_115 = 0 ;
F_42 ( & V_342 ) ;
F_24 () ;
V_2 = F_211 ( V_4 ) ;
F_29 () ;
if ( ! V_2 )
V_115 = - V_200 ;
else if ( ! F_207 ( V_2 -> V_7 . V_70 ) )
F_208 ( & V_2 -> V_7 ) ;
F_43 ( & V_342 ) ;
return V_115 ;
}
static int F_213 ( struct V_3 * V_4 )
{
struct V_1 * V_2 ;
struct V_71 * V_69 ;
struct V_65 * V_66 ;
int V_115 = 0 ;
F_42 ( & V_342 ) ;
F_24 () ;
V_2 = F_211 ( V_4 ) ;
if ( ! V_2 ) {
V_115 = - V_200 ;
goto V_343;
}
V_69 = V_2 -> V_7 . V_70 ;
V_66 = F_36 ( V_69 ) ;
F_205 ( & V_2 -> V_338 ) ;
F_206 ( V_339 , & V_66 -> V_191 ) ;
V_343:
F_29 () ;
F_43 ( & V_342 ) ;
return V_115 ;
}
static void V_192 ( struct V_344 * V_345 )
{
struct V_65 * V_66 ;
struct V_1 * V_2 ;
V_66 = F_30 ( V_345 , struct V_65 , V_191 ) ;
F_42 ( & V_342 ) ;
V_2 = V_66 -> V_72 ;
F_79 ( V_66 -> V_69 ) ;
F_23 ( V_2 ) ;
F_43 ( & V_342 ) ;
}
static bool F_214 ( struct V_3 * V_4 )
{
return true ;
}
static void F_215 ( struct V_1 * V_2 )
{
#ifdef F_216
int V_326 ;
T_1 V_346 , V_347 ;
struct V_3 * V_4 = V_2 -> V_23 ;
struct V_65 * V_66 = F_36 ( V_2 -> V_7 . V_70 ) ;
struct V_348 V_321 = {
. V_281 = 0 ,
. V_280 = V_39
} ;
if ( V_4 && V_4 -> V_349 && V_4 -> V_349 -> V_350 ) {
V_326 = V_4 -> V_349 -> V_350 ( V_4 ) ;
if ( V_326 & V_351 ) {
V_321 . V_322 = V_352 ;
V_347 = F_217 ( V_4 , & V_321 ) ;
V_321 . V_280 = V_43 ;
V_346 = F_217 ( V_4 , & V_321 ) ;
} else {
V_321 . V_322 = V_323 ;
V_347 = F_218 ( V_4 , & V_321 ) ;
V_321 . V_280 = V_43 ;
V_346 = F_218 ( V_4 , & V_321 ) ;
}
V_66 -> V_281 = F_203 ( V_347 ) ? F_203 ( V_347 ) - 1 : 0 ;
V_2 -> V_7 . V_281 = F_203 ( V_346 ) ? F_203 ( V_346 ) - 1 : V_66 -> V_281 ;
}
#endif
}
static int F_219 ( struct V_3 * V_4 , enum V_44 V_45 )
{
int V_115 = 0 ;
struct V_1 * V_2 ;
struct V_71 * V_69 ;
F_42 ( & V_342 ) ;
F_24 () ;
if ( F_220 ( V_4 ) ) {
V_115 = - V_353 ;
goto V_343;
}
V_2 = F_13 ( V_4 , V_45 ) ;
if ( F_112 ( V_2 ) ) {
V_115 = F_221 ( V_2 ) ;
goto V_343;
}
V_69 = F_94 ( V_2 , & V_4 -> V_40 , 0 ) ;
if ( F_112 ( V_69 ) ) {
F_59 ( V_171 L_62 ,
V_4 -> V_131 ) ;
V_115 = - V_354 ;
F_29 () ;
F_23 ( V_2 ) ;
goto V_355;
}
V_2 -> V_7 . V_70 = V_69 ;
F_215 ( V_2 ) ;
F_222 ( V_69 ) ;
V_69 -> V_356 = V_357 ;
F_223 ( V_69 ) ;
if ( ! F_207 ( V_69 ) ) {
F_29 () ;
F_208 ( & V_2 -> V_7 ) ;
F_43 ( & V_342 ) ;
return V_115 ;
}
V_343:
F_29 () ;
V_355:
F_43 ( & V_342 ) ;
return V_115 ;
}
static int F_48 ( struct V_71 * V_69 )
{
struct V_3 * V_4 = F_55 ( V_69 ) ;
struct V_358 V_359 ;
if ( ! F_224 ( V_4 , & V_359 ) ) {
V_69 -> V_360 &=
~ ( V_361 | V_362 ) ;
if ( V_359 . V_363 & ( V_364 |
V_365 ) )
V_69 -> V_360 |= V_361 ;
if ( V_359 . V_363 & V_366 )
V_69 -> V_360 |=
V_362 ;
switch ( F_225 ( & V_359 ) ) {
case V_367 :
V_69 -> V_368 = V_361 ;
break;
case V_369 :
V_69 -> V_368 = V_362 ;
break;
}
return 0 ;
}
return - 1 ;
}
static int F_207 ( struct V_71 * V_69 )
{
struct V_3 * V_4 = F_55 ( V_69 ) ;
if ( F_226 ( V_4 ) )
return 0 ;
return - 1 ;
}
static void F_84 ( struct V_71 * V_69 )
{
struct V_202 * V_370 ;
struct V_60 * V_61 ;
unsigned int V_201 ;
F_227 (cpu) {
V_370 = & F_108 ( V_206 , V_201 ) ;
if ( ! V_370 -> V_205 || ! F_228 ( V_201 ) )
continue;
V_61 = F_229 ( 0 ) ;
if ( ! V_61 ) {
F_116 ( & V_370 -> V_208 . V_209 ) ;
continue;
}
V_61 -> V_304 = F_171 ;
F_115 ( & V_370 -> V_208 . V_209 ) ;
F_122 ( & V_370 -> V_208 , V_61 ) ;
if ( V_370 -> V_208 . V_68 == 1 )
F_114 ( V_370 -> V_205 ) ;
F_116 ( & V_370 -> V_208 . V_209 ) ;
F_230 ( & V_295 ) ;
}
}
static int F_231 ( struct V_183 * V_184 )
{
struct V_71 * V_69 = F_101 ( V_184 ) ;
struct V_65 * V_66 = F_36 ( V_69 ) ;
struct V_1 * V_2 = V_66 -> V_72 ;
F_209 ( & V_2 -> V_7 ) ;
F_83 ( V_2 -> V_7 . V_70 ) ;
if ( ! F_207 ( V_2 -> V_7 . V_70 ) )
F_208 ( & V_2 -> V_7 ) ;
return 0 ;
}
static struct V_1 *
F_211 ( const struct V_3 * V_4 )
{
struct V_1 * V_2 ;
F_76 (fcoe, &fcoe_hostlist, list) {
if ( V_2 -> V_4 == V_4 )
return V_2 ;
}
return NULL ;
}
static struct V_71 * F_220 ( const struct V_3 * V_4 )
{
struct V_1 * V_2 ;
V_2 = F_211 ( V_4 ) ;
return ( V_2 ) ? V_2 -> V_7 . V_70 : NULL ;
}
static int F_222 ( const struct V_71 * V_69 )
{
struct V_1 * V_2 ;
struct V_65 * V_66 ;
V_2 = F_211 ( F_55 ( V_69 ) ) ;
if ( ! V_2 ) {
V_66 = F_36 ( V_69 ) ;
V_2 = V_66 -> V_72 ;
F_232 ( & V_2 -> V_338 , & V_371 ) ;
}
return 0 ;
}
static int T_5 F_233 ( void )
{
struct V_202 * V_203 ;
unsigned int V_201 ;
int V_115 = 0 ;
V_339 = F_234 ( L_63 , 0 , 0 ) ;
if ( ! V_339 )
return - V_51 ;
V_115 = F_235 ( & V_372 ) ;
if ( V_115 ) {
F_59 ( V_171 L_64
L_65 ) ;
return V_115 ;
}
F_42 ( & V_342 ) ;
F_227 (cpu) {
V_203 = & F_108 ( V_206 , V_201 ) ;
F_46 ( & V_203 -> V_208 ) ;
}
F_236 (cpu)
F_107 ( V_201 ) ;
V_115 = F_237 ( & V_373 ) ;
if ( V_115 )
goto V_374;
F_194 () ;
V_115 = F_103 () ;
if ( V_115 )
goto V_374;
F_43 ( & V_342 ) ;
return 0 ;
V_374:
F_236 (cpu) {
F_117 ( V_201 ) ;
}
F_43 ( & V_342 ) ;
F_238 ( V_339 ) ;
return V_115 ;
}
static void T_6 F_239 ( void )
{
struct V_1 * V_2 , * V_310 ;
struct V_65 * V_66 ;
unsigned int V_201 ;
F_42 ( & V_342 ) ;
F_197 () ;
F_24 () ;
F_240 (fcoe, tmp, &fcoe_hostlist, list) {
F_205 ( & V_2 -> V_338 ) ;
V_66 = F_36 ( V_2 -> V_7 . V_70 ) ;
F_206 ( V_339 , & V_66 -> V_191 ) ;
}
F_29 () ;
F_241 ( & V_373 ) ;
F_236 (cpu)
F_117 ( V_201 ) ;
F_43 ( & V_342 ) ;
F_238 ( V_339 ) ;
F_105 () ;
F_242 ( & V_372 ) ;
}
static void F_243 ( struct V_375 * V_376 , struct V_147 * V_148 , void * V_308 )
{
struct V_5 * V_6 = V_308 ;
struct V_377 * V_378 = F_244 ( V_376 ) ;
struct V_71 * V_69 = V_378 -> V_70 ;
T_1 * V_379 ;
if ( F_112 ( V_148 ) )
goto V_380;
V_379 = F_245 ( V_148 ) -> V_381 ;
if ( F_37 ( V_379 ) )
F_246 ( V_6 , V_69 , V_148 ) ;
if ( ! F_37 ( V_379 ) )
V_56 ( V_69 , V_379 ) ;
V_380:
F_247 ( V_376 , V_148 , V_69 ) ;
}
static void F_248 ( struct V_375 * V_376 , struct V_147 * V_148 , void * V_308 )
{
struct V_71 * V_69 = V_308 ;
static T_1 V_382 [ V_12 ] = { 0 } ;
if ( ! F_112 ( V_148 ) )
V_56 ( V_69 , V_382 ) ;
F_249 ( V_376 , V_148 , V_69 ) ;
}
static struct V_375 * F_250 ( struct V_71 * V_69 , T_2 V_383 ,
struct V_147 * V_148 , unsigned int V_384 ,
void (* F_251)( struct V_375 * ,
struct V_147 * ,
void * ) ,
void * V_308 , T_2 V_385 )
{
struct V_65 * V_66 = F_36 ( V_69 ) ;
struct V_1 * V_2 = V_66 -> V_72 ;
struct V_5 * V_6 = & V_2 -> V_7 ;
struct V_149 * V_150 = F_69 ( V_148 ) ;
switch ( V_384 ) {
case V_386 :
case V_387 :
if ( V_69 -> V_388 )
break;
return F_252 ( V_69 , V_383 , V_148 , V_384 , F_243 ,
V_6 , V_385 ) ;
case V_299 :
if ( F_140 ( V_150 -> V_244 ) != V_301 )
break;
return F_252 ( V_69 , V_383 , V_148 , V_384 , F_248 ,
V_69 , V_385 ) ;
}
return F_252 ( V_69 , V_383 , V_148 , V_384 , F_251 , V_308 , V_385 ) ;
}
static int F_253 ( struct V_185 * V_111 , bool V_389 )
{
struct V_183 * V_184 = F_100 ( V_111 ) ;
struct V_71 * V_182 = F_101 ( V_184 ) ;
struct V_65 * V_66 = F_36 ( V_182 ) ;
struct V_1 * V_2 = V_66 -> V_72 ;
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_71 * V_390 ;
int V_115 ;
char V_391 [ 32 ] ;
V_115 = F_254 ( V_111 ) ;
if ( V_115 ) {
F_255 ( V_111 -> V_195 , V_391 , sizeof( V_391 ) ) ;
F_59 ( V_171 L_66
L_67 ,
V_391 ) ;
return V_115 ;
}
F_42 ( & V_342 ) ;
F_24 () ;
V_390 = F_94 ( V_2 , & V_111 -> V_40 , 1 ) ;
F_29 () ;
F_43 ( & V_342 ) ;
if ( F_112 ( V_390 ) ) {
F_59 ( V_171 L_68 ,
V_4 -> V_131 ) ;
return - V_354 ;
}
if ( V_389 ) {
F_256 ( V_111 , V_392 ) ;
} else {
V_390 -> V_356 = V_357 ;
F_223 ( V_390 ) ;
F_257 ( V_390 ) ;
}
return 0 ;
}
static int F_258 ( struct V_185 * V_111 )
{
struct V_183 * V_184 = F_100 ( V_111 ) ;
struct V_71 * V_182 = F_101 ( V_184 ) ;
struct V_71 * V_390 = V_111 -> V_393 ;
F_42 ( & V_182 -> V_91 ) ;
F_205 ( & V_390 -> V_338 ) ;
F_43 ( & V_182 -> V_91 ) ;
F_42 ( & V_342 ) ;
F_79 ( V_390 ) ;
F_43 ( & V_342 ) ;
return 0 ;
}
static int F_259 ( struct V_185 * V_111 , bool V_394 )
{
struct V_71 * V_69 = V_111 -> V_393 ;
if ( V_394 ) {
F_256 ( V_111 , V_392 ) ;
F_80 ( V_69 ) ;
} else {
V_69 -> V_356 = V_357 ;
F_223 ( V_69 ) ;
F_257 ( V_69 ) ;
}
return 0 ;
}
static void F_260 ( struct V_185 * V_111 )
{
struct V_71 * V_69 = V_111 -> V_393 ;
struct V_147 * V_148 ;
T_9 V_235 ;
snprintf ( F_57 ( V_69 -> V_116 ) , V_128 ,
L_69 , V_129 , V_130 ,
F_55 ( V_69 ) -> V_131 , V_111 -> V_395 ) ;
if ( V_69 -> V_250 != V_396 )
return;
V_235 = F_261 ( F_57 ( V_69 -> V_116 ) , 255 ) ;
V_148 = F_262 ( V_69 ,
sizeof( struct V_397 ) +
sizeof( struct V_398 ) + V_235 ) ;
if ( ! V_148 )
return;
V_69 -> V_399 . V_400 ( V_69 , V_401 , V_148 , V_402 ,
NULL , NULL , 3 * V_69 -> V_79 ) ;
}
static void F_263 ( struct V_71 * V_69 ,
struct V_403 * V_404 )
{
struct V_3 * V_4 = F_55 ( V_69 ) ;
F_264 ( V_69 , V_404 , V_4 ) ;
}
static void F_265 ( struct V_71 * V_69 ,
T_2 V_405 , struct V_147 * V_148 )
{
struct V_65 * V_66 = F_36 ( V_69 ) ;
struct V_1 * V_2 = V_66 -> V_72 ;
if ( V_148 && F_175 ( V_148 ) == V_386 )
F_246 ( & V_2 -> V_7 , V_69 , V_148 ) ;
}
