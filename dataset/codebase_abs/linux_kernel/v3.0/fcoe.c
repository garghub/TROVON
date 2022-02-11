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
struct V_59 * V_60 = F_31 ( V_2 -> V_7 . V_61 ) ;
F_2 ( V_4 , L_6 ) ;
F_32 ( V_2 -> V_7 . V_61 ) ;
F_33 ( V_2 -> V_7 . V_61 ) ;
F_34 ( & V_60 -> V_62 ) ;
F_35 ( V_2 -> V_7 . V_61 ) ;
F_36 ( & V_2 -> V_35 ) ;
F_36 ( & V_2 -> V_40 ) ;
F_37 () ;
memcpy ( V_11 , ( T_1 [ 6 ] ) V_29 , V_12 ) ;
F_38 ( V_4 , V_11 ) ;
if ( V_6 -> V_26 )
F_38 ( V_4 , V_6 -> V_25 ) ;
if ( V_6 -> V_30 == V_31 ) {
F_39 ( V_4 , V_32 ) ;
F_39 ( V_4 , V_33 ) ;
} else
F_39 ( V_4 , V_34 ) ;
if ( ! F_40 ( V_60 -> V_63 ) )
F_38 ( V_4 , V_60 -> V_63 ) ;
V_14 = V_4 -> V_15 ;
if ( V_14 -> V_64 ) {
if ( V_14 -> V_64 ( V_4 ) )
F_2 ( V_4 , L_7
L_2 ) ;
}
F_28 ( V_2 ) ;
}
static int V_41 ( struct V_65 * V_66 , struct V_3 * V_4 ,
struct V_67 * V_68 ,
struct V_3 * V_69 )
{
struct V_1 * V_2 ;
V_2 = F_25 ( V_68 , struct V_1 , V_40 ) ;
F_41 ( & V_2 -> V_7 , V_66 ) ;
return 0 ;
}
static void V_54 ( struct V_5 * V_6 , struct V_65 * V_66 )
{
V_66 -> V_39 = F_42 ( V_6 ) -> V_4 ;
F_43 ( V_66 ) ;
}
static void V_56 ( struct V_70 * V_71 , T_1 * V_24 )
{
struct V_59 * V_60 = F_31 ( V_71 ) ;
struct V_1 * V_2 = V_60 -> V_72 ;
F_44 () ;
if ( ! F_40 ( V_60 -> V_63 ) )
F_38 ( V_2 -> V_4 , V_60 -> V_63 ) ;
if ( ! F_40 ( V_24 ) )
F_8 ( V_2 -> V_4 , V_24 ) ;
memcpy ( V_60 -> V_63 , V_24 , V_12 ) ;
F_45 () ;
}
static T_1 * V_58 ( struct V_70 * V_71 )
{
struct V_59 * V_60 = F_31 ( V_71 ) ;
return V_60 -> V_63 ;
}
static int F_46 ( struct V_70 * V_71 )
{
V_71 -> V_73 = 0 ;
V_71 -> V_74 = 0 ;
V_71 -> V_75 = 3 ;
V_71 -> V_76 = 3 ;
V_71 -> V_77 = 2 * 1000 ;
V_71 -> V_78 = 2 * 2 * 1000 ;
V_71 -> V_79 = ( V_80 | V_81 |
V_82 | V_83 ) ;
V_71 -> V_84 = 1 ;
F_47 ( V_71 ) ;
F_48 ( V_71 ) ;
V_71 -> V_85 = 0 ;
V_71 -> V_86 = 0 ;
V_71 -> V_87 = 0 ;
V_71 -> V_88 = 0 ;
V_71 -> V_89 = 0 ;
return 0 ;
}
static int F_49 ( struct V_3 * V_4 , T_2 * V_90 , int type )
{
const struct V_13 * V_14 = V_4 -> V_15 ;
if ( V_14 -> V_91 )
return V_14 -> V_91 ( V_4 , V_90 , type ) ;
return - V_92 ;
}
static void F_50 ( struct V_70 * V_71 ,
struct V_3 * V_4 )
{
F_51 ( & V_71 -> V_93 ) ;
if ( V_4 -> V_94 & V_95 )
V_71 -> V_96 = 1 ;
else
V_71 -> V_96 = 0 ;
if ( V_4 -> V_94 & V_97 ) {
V_71 -> V_85 = 1 ;
F_2 ( V_4 , L_8 ) ;
} else {
V_71 -> V_85 = 0 ;
}
if ( V_4 -> V_94 & V_98 ) {
V_71 -> V_86 = 1 ;
V_71 -> V_89 = V_4 -> V_99 ;
F_2 ( V_4 , L_9 ,
V_71 -> V_89 ) ;
} else {
V_71 -> V_86 = 0 ;
V_71 -> V_89 = 0 ;
}
if ( V_4 -> V_100 ) {
V_71 -> V_87 = 1 ;
V_71 -> V_88 = V_4 -> V_100 ;
F_2 ( V_4 , L_10 ,
V_71 -> V_88 ) ;
} else {
V_71 -> V_87 = 0 ;
V_71 -> V_88 = 0 ;
}
F_52 ( & V_71 -> V_93 ) ;
}
static int F_53 ( struct V_70 * V_71 , struct V_3 * V_4 )
{
T_3 V_101 ;
T_2 V_102 , V_103 ;
struct V_1 * V_2 ;
struct V_59 * V_60 ;
V_60 = F_31 ( V_71 ) ;
V_2 = V_60 -> V_72 ;
V_101 = V_4 -> V_104 ;
if ( V_4 -> V_94 & V_105 ) {
V_101 = V_106 ;
F_2 ( V_4 , L_11 , V_101 ) ;
}
V_101 -= ( sizeof( struct V_107 ) + sizeof( struct V_108 ) ) ;
if ( F_54 ( V_71 , V_101 ) )
return - V_92 ;
F_50 ( V_71 , V_4 ) ;
F_55 ( & V_60 -> V_109 ) ;
V_60 -> V_110 = 0 ;
F_56 ( & V_60 -> V_62 , V_111 , ( unsigned long ) V_71 ) ;
F_57 ( V_71 ) ;
if ( ! V_71 -> V_112 ) {
if ( F_49 ( V_4 , & V_102 , V_113 ) )
V_102 = F_58 ( V_2 -> V_7 . V_25 , 1 , 0 ) ;
F_59 ( V_71 , V_102 ) ;
if ( F_49 ( V_4 , & V_103 , V_114 ) )
V_103 = F_58 ( V_2 -> V_7 . V_25 ,
2 , 0 ) ;
F_60 ( V_71 , V_103 ) ;
}
return 0 ;
}
static int F_61 ( struct V_70 * V_71 , struct V_115 * V_39 )
{
int V_116 = 0 ;
V_71 -> V_117 -> V_118 = V_119 ;
V_71 -> V_117 -> V_120 = V_121 ;
V_71 -> V_117 -> V_122 = 0 ;
V_71 -> V_117 -> V_123 = V_124 ;
if ( V_71 -> V_112 )
V_71 -> V_117 -> V_125 = V_126 ;
else
V_71 -> V_117 -> V_125 = V_127 ;
V_116 = F_62 ( V_71 -> V_117 , V_39 ) ;
if ( V_116 ) {
F_2 ( F_63 ( V_71 ) , L_12
L_13 ) ;
return V_116 ;
}
if ( ! V_71 -> V_112 )
F_64 ( V_71 -> V_117 ) = V_128 ;
snprintf ( F_65 ( V_71 -> V_117 ) , V_129 ,
L_14 , V_130 , V_131 ,
F_63 ( V_71 ) -> V_132 ) ;
return 0 ;
}
bool F_66 ( struct V_133 * V_134 )
{
return F_67 ( F_68 ( V_134 ) ) &&
( F_68 ( V_134 ) -> V_135 > V_136 ) ;
}
static inline int F_69 ( struct V_70 * V_71 )
{
struct V_59 * V_60 = F_31 ( V_71 ) ;
struct V_1 * V_2 = V_60 -> V_72 ;
struct V_1 * V_137 = NULL ;
struct V_3 * V_138 , * V_139 ;
T_4 V_140 = V_141 ;
T_4 V_142 = V_143 ;
if ( ! V_71 -> V_87 || ! V_71 -> V_88 ||
( V_71 -> V_88 >= V_142 ) ) {
V_71 -> V_88 = 0 ;
goto V_144;
}
if ( V_2 -> V_4 -> V_17 & V_22 )
V_139 = F_3 ( V_2 -> V_4 ) ;
else
V_139 = V_2 -> V_4 ;
F_70 (oldfcoe, &fcoe_hostlist, list) {
if ( V_137 -> V_4 -> V_17 & V_22 )
V_138 = F_3 ( V_137 -> V_4 ) ;
else
V_138 = V_137 -> V_4 ;
if ( V_139 == V_138 ) {
V_2 -> V_145 = V_137 -> V_145 ;
break;
}
}
if ( V_2 -> V_145 ) {
if ( ! F_71 ( V_71 , V_2 -> V_145 , F_66 ) ) {
F_72 ( V_146 L_15
L_16 ,
V_2 -> V_145 , V_2 -> V_4 -> V_132 ) ;
return - V_50 ;
}
} else {
V_2 -> V_145 = F_73 ( V_71 , V_147 ,
V_141 , V_71 -> V_88 ,
F_66 ) ;
if ( ! V_2 -> V_145 ) {
F_72 ( V_146 L_17
L_18 ,
V_2 -> V_4 -> V_132 ) ;
return - V_50 ;
}
}
V_140 += V_71 -> V_88 + 1 ;
V_144:
if ( ! F_73 ( V_71 , V_147 , V_140 , V_142 , NULL ) ) {
F_72 ( V_146 L_19
L_20 , V_2 -> V_4 -> V_132 ) ;
return - V_50 ;
}
return 0 ;
}
static void F_74 ( struct V_70 * V_71 )
{
F_75 ( V_71 ) ;
F_76 ( V_71 -> V_117 ) ;
F_77 ( V_71 -> V_117 ) ;
F_78 ( V_71 ) ;
F_79 ( V_71 ) ;
F_80 ( V_71 ) ;
F_81 ( V_71 -> V_117 ) ;
}
static int F_82 ( struct V_70 * V_71 , T_4 V_148 ,
struct V_149 * V_150 , unsigned int V_151 )
{
struct V_3 * V_4 = F_63 ( V_71 ) ;
if ( V_4 -> V_15 -> V_152 )
return V_4 -> V_15 -> V_152 ( V_4 ,
V_148 , V_150 ,
V_151 ) ;
return 0 ;
}
static int F_83 ( struct V_70 * V_71 , T_4 V_148 )
{
struct V_3 * V_4 = F_63 ( V_71 ) ;
if ( V_4 -> V_15 -> V_153 )
return V_4 -> V_15 -> V_153 ( V_4 , V_148 ) ;
return 0 ;
}
static struct V_70 * F_84 ( struct V_1 * V_2 ,
struct V_115 * V_154 , int V_155 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_70 * V_71 , * V_156 ;
struct V_59 * V_60 ;
struct V_157 * V_158 ;
int V_116 ;
struct V_159 * V_112 = F_85 ( V_154 ) ;
F_2 ( V_4 , L_21 ) ;
if ( ! V_155 )
V_71 = F_86 ( & V_160 , sizeof( * V_60 ) ) ;
else
V_71 = F_87 ( V_112 , sizeof( * V_60 ) ) ;
if ( ! V_71 ) {
F_2 ( V_4 , L_22 ) ;
V_116 = - V_50 ;
goto V_48;
}
V_60 = F_31 ( V_71 ) ;
V_60 -> V_71 = V_71 ;
V_60 -> V_72 = V_2 ;
V_60 -> V_161 = V_162 ;
V_60 -> V_163 = V_164 ;
F_88 ( & V_60 -> V_165 , V_166 ) ;
V_116 = F_46 ( V_71 ) ;
if ( V_116 ) {
F_2 ( V_4 , L_23
L_24 ) ;
goto V_167;
}
if ( V_155 ) {
F_2 ( V_4 , L_25
L_26 ,
V_112 -> V_168 , V_112 -> V_169 ) ;
F_59 ( V_71 , V_112 -> V_168 ) ;
F_60 ( V_71 , V_112 -> V_169 ) ;
}
V_116 = F_53 ( V_71 , V_4 ) ;
if ( V_116 ) {
F_2 ( V_4 , L_27
L_24 ) ;
goto V_170;
}
V_116 = F_61 ( V_71 , V_154 ) ;
if ( V_116 ) {
F_2 ( V_4 , L_28
L_24 ) ;
goto V_170;
}
V_116 = F_89 ( V_71 , & V_2 -> V_7 , & V_171 , 1 ) ;
if ( V_116 ) {
F_2 ( V_4 , L_29
L_24 ) ;
goto V_170;
}
if ( ! V_155 )
V_116 = F_69 ( V_71 ) ;
else {
V_158 = F_90 ( V_112 ) ;
V_156 = F_91 ( V_158 ) ;
V_116 = F_92 ( V_156 , V_71 ) ;
}
if ( V_116 ) {
F_2 ( V_4 , L_30 ) ;
goto V_170;
}
F_26 ( V_2 ) ;
return V_71 ;
V_170:
F_79 ( V_71 ) ;
V_167:
F_81 ( V_71 -> V_117 ) ;
V_48:
return F_15 ( V_116 ) ;
}
static int T_5 F_93 ( void )
{
V_127 =
F_94 ( & V_172 ) ;
V_126 =
F_94 ( & V_173 ) ;
if ( ! V_127 ) {
F_72 ( V_146 L_31 ) ;
return - V_174 ;
}
return 0 ;
}
int T_6 F_95 ( void )
{
F_96 ( V_127 ) ;
F_96 ( V_126 ) ;
V_127 = NULL ;
V_126 = NULL ;
return 0 ;
}
static void F_97 ( unsigned int V_175 )
{
struct V_176 * V_177 ;
struct V_178 * V_179 ;
V_177 = & F_98 ( V_180 , V_175 ) ;
V_179 = F_99 ( V_181 ,
( void * ) V_177 , L_32 , V_175 ) ;
if ( F_100 ( ! F_101 ( V_179 ) ) ) {
F_102 ( V_179 , V_175 ) ;
F_103 ( V_179 ) ;
F_104 ( & V_177 -> V_182 . V_183 ) ;
V_177 -> V_179 = V_179 ;
F_105 ( & V_177 -> V_182 . V_183 ) ;
}
}
static void F_106 ( unsigned int V_175 )
{
struct V_176 * V_177 ;
struct V_178 * V_179 ;
struct V_184 * V_185 ;
struct V_65 * V_66 ;
#ifdef F_107
struct V_176 * V_186 ;
unsigned V_187 = F_108 () ;
#endif
F_109 ( L_33 , V_175 ) ;
V_177 = & F_98 ( V_180 , V_175 ) ;
F_104 ( & V_177 -> V_182 . V_183 ) ;
V_179 = V_177 -> V_179 ;
V_177 -> V_179 = NULL ;
V_185 = V_177 -> V_188 ;
V_177 -> V_188 = NULL ;
V_177 -> V_189 = 0 ;
F_105 ( & V_177 -> V_182 . V_183 ) ;
#ifdef F_107
if ( V_175 != V_187 ) {
V_186 = & F_98 ( V_180 , V_187 ) ;
F_104 ( & V_186 -> V_182 . V_183 ) ;
if ( V_186 -> V_179 ) {
F_109 ( L_34 ,
V_175 , V_187 ) ;
while ( ( V_66 = F_110 ( & V_177 -> V_182 ) ) != NULL )
F_111 ( & V_186 -> V_182 , V_66 ) ;
F_105 ( & V_186 -> V_182 . V_183 ) ;
} else {
while ( ( V_66 = F_110 ( & V_177 -> V_182 ) ) != NULL )
F_112 ( V_66 ) ;
F_105 ( & V_186 -> V_182 . V_183 ) ;
}
} else {
F_104 ( & V_177 -> V_182 . V_183 ) ;
while ( ( V_66 = F_110 ( & V_177 -> V_182 ) ) != NULL )
F_112 ( V_66 ) ;
F_105 ( & V_177 -> V_182 . V_183 ) ;
}
F_113 () ;
#else
F_104 ( & V_177 -> V_182 . V_183 ) ;
while ( ( V_66 = F_110 ( & V_177 -> V_182 ) ) != NULL )
F_112 ( V_66 ) ;
F_105 ( & V_177 -> V_182 . V_183 ) ;
#endif
if ( V_179 )
F_114 ( V_179 ) ;
if ( V_185 )
F_115 ( V_185 ) ;
}
static int F_116 ( struct V_190 * V_191 ,
unsigned long V_192 , void * V_193 )
{
unsigned V_175 = ( unsigned long ) V_193 ;
switch ( V_192 ) {
case V_194 :
case V_195 :
F_109 ( L_35 , V_175 ) ;
F_97 ( V_175 ) ;
break;
case V_196 :
case V_197 :
F_109 ( L_36 , V_175 ) ;
F_106 ( V_175 ) ;
break;
default:
break;
}
return V_198 ;
}
int V_37 ( struct V_65 * V_66 , struct V_3 * V_4 ,
struct V_67 * V_68 , struct V_3 * V_199 )
{
struct V_70 * V_71 ;
struct V_200 * V_201 ;
struct V_1 * V_2 ;
struct V_202 * V_203 ;
struct V_176 * V_204 ;
struct V_205 * V_206 ;
unsigned int V_175 ;
V_2 = F_25 ( V_68 , struct V_1 , V_35 ) ;
V_71 = V_2 -> V_7 . V_61 ;
if ( F_117 ( ! V_71 ) ) {
F_2 ( V_4 , L_37 ) ;
goto V_207;
}
if ( ! V_71 -> V_73 )
goto V_207;
F_2 ( V_4 , L_38
L_39 ,
V_66 -> V_208 , V_66 -> V_135 , V_66 -> V_209 , V_66 -> V_210 ,
F_118 ( V_66 ) , F_119 ( V_66 ) ,
V_66 -> V_211 , V_66 -> V_39 ? V_66 -> V_39 -> V_132 : L_40 ) ;
V_206 = F_120 ( V_66 ) ;
if ( F_121 ( & V_2 -> V_7 ) &&
F_122 ( V_206 -> V_212 , V_2 -> V_7 . V_213 ) ) {
F_2 ( V_4 , L_41 ,
V_206 -> V_212 ) ;
goto V_45;
}
if ( F_117 ( ( V_66 -> V_208 < V_214 ) ||
! F_123 ( V_66 , V_215 ) ) )
goto V_45;
F_124 ( V_66 , sizeof( struct V_107 ) ) ;
V_203 = (struct V_202 * ) F_125 ( V_66 ) ;
if ( F_126 ( & V_206 -> V_216 [ 3 ] ) != F_126 ( V_203 -> V_217 ) ) {
F_2 ( V_4 , L_42 ,
V_206 -> V_216 ) ;
goto V_45;
}
V_201 = F_127 ( V_66 ) ;
V_201 -> V_218 = V_71 ;
V_201 -> V_68 = V_68 ;
if ( F_126 ( V_203 -> V_219 ) & V_220 )
V_175 = F_128 ( V_203 -> V_221 ) & V_222 ;
else
V_175 = F_129 () ;
V_204 = & F_98 ( V_180 , V_175 ) ;
F_104 ( & V_204 -> V_182 . V_183 ) ;
if ( F_117 ( ! V_204 -> V_179 ) ) {
F_2 ( V_4 , L_43
L_44
L_45 ) ;
F_105 ( & V_204 -> V_182 . V_183 ) ;
V_175 = F_130 ( V_223 ) ;
V_204 = & F_98 ( V_180 , V_175 ) ;
F_104 ( & V_204 -> V_182 . V_183 ) ;
if ( ! V_204 -> V_179 ) {
F_105 ( & V_204 -> V_182 . V_183 ) ;
goto V_45;
}
}
if ( V_203 -> V_224 == V_225 &&
V_175 == F_129 () &&
F_131 ( & V_204 -> V_182 ) ) {
F_105 ( & V_204 -> V_182 . V_183 ) ;
F_132 ( V_66 ) ;
} else {
F_111 ( & V_204 -> V_182 , V_66 ) ;
if ( V_204 -> V_182 . V_226 == 1 )
F_103 ( V_204 -> V_179 ) ;
F_105 ( & V_204 -> V_182 . V_183 ) ;
}
return 0 ;
V_45:
F_133 ( V_71 -> V_227 , F_108 () ) -> V_228 ++ ;
F_113 () ;
V_207:
F_112 ( V_66 ) ;
return - 1 ;
}
static int F_134 ( struct V_65 * V_66 , int V_229 )
{
struct V_176 * V_204 ;
int V_116 ;
V_204 = & F_135 ( V_180 ) ;
V_116 = F_136 ( V_66 , V_229 , V_204 ) ;
F_137 ( V_180 ) ;
return V_116 ;
}
int F_138 ( struct V_70 * V_71 , struct V_133 * V_134 )
{
int V_230 ;
T_3 V_231 ;
struct V_205 * V_206 ;
struct V_108 * V_232 ;
struct V_65 * V_66 ;
struct V_233 * V_234 ;
struct V_202 * V_203 ;
unsigned int V_235 ;
unsigned int V_229 ;
unsigned int V_236 ;
struct V_59 * V_60 = F_31 ( V_71 ) ;
struct V_1 * V_2 = V_60 -> V_72 ;
T_1 V_237 , V_238 ;
struct V_107 * V_239 ;
F_139 ( ( F_140 ( V_134 ) % sizeof( T_3 ) ) != 0 ) ;
V_203 = F_141 ( V_134 ) ;
V_66 = F_142 ( V_134 ) ;
V_230 = V_66 -> V_208 / V_240 ;
if ( ! V_71 -> V_73 ) {
F_112 ( V_66 ) ;
return 0 ;
}
if ( F_117 ( V_203 -> V_224 == V_241 ) &&
F_143 ( & V_2 -> V_7 , V_71 , V_66 ) )
return 0 ;
V_237 = F_144 ( V_134 ) ;
V_238 = F_145 ( V_134 ) ;
V_236 = sizeof( struct V_205 ) ;
V_235 = sizeof( struct V_107 ) ;
V_229 = sizeof( struct V_108 ) ;
V_230 = ( V_66 -> V_208 - V_229 + sizeof( V_231 ) ) / V_240 ;
if ( F_100 ( V_71 -> V_85 ) ) {
V_66 -> V_242 = V_243 ;
V_66 -> V_244 = F_146 ( V_66 ) ;
V_66 -> V_245 = V_66 -> V_208 ;
V_231 = 0 ;
} else {
V_66 -> V_242 = V_246 ;
V_231 = F_147 ( V_134 ) ;
}
if ( F_148 ( V_66 ) ) {
T_7 * V_247 ;
if ( F_134 ( V_66 , V_229 ) ) {
F_112 ( V_66 ) ;
return - V_50 ;
}
V_247 = & F_149 ( V_66 ) -> V_248 [ F_149 ( V_66 ) -> V_249 - 1 ] ;
V_232 = F_150 ( V_247 -> V_184 , V_250 )
+ V_247 -> V_251 ;
} else {
V_232 = (struct V_108 * ) F_151 ( V_66 , V_229 ) ;
}
memset ( V_232 , 0 , sizeof( * V_232 ) ) ;
V_232 -> V_252 = V_238 ;
V_232 -> V_253 = F_152 ( ~ V_231 ) ;
if ( F_148 ( V_66 ) ) {
F_153 ( V_232 , V_250 ) ;
V_232 = NULL ;
}
F_154 ( V_66 , V_236 + V_235 ) ;
F_155 ( V_66 ) ;
F_156 ( V_66 ) ;
V_66 -> V_254 = V_236 ;
V_66 -> V_255 = F_12 ( V_38 ) ;
V_66 -> V_39 = V_2 -> V_4 ;
V_206 = F_120 ( V_66 ) ;
V_206 -> V_256 = F_12 ( V_38 ) ;
memcpy ( V_206 -> V_216 , V_2 -> V_7 . V_213 , V_12 ) ;
if ( V_2 -> V_7 . V_257 )
memcpy ( V_206 -> V_216 + 3 , V_203 -> V_217 , 3 ) ;
if ( F_117 ( V_2 -> V_7 . V_258 != V_259 ) )
memcpy ( V_206 -> V_212 , V_2 -> V_7 . V_25 , V_12 ) ;
else
memcpy ( V_206 -> V_212 , V_60 -> V_63 , V_12 ) ;
V_239 = (struct V_107 * ) ( V_206 + 1 ) ;
memset ( V_239 , 0 , sizeof( * V_239 ) ) ;
if ( V_260 )
F_157 ( V_239 , V_260 ) ;
V_239 -> V_261 = V_237 ;
if ( V_71 -> V_86 && F_158 ( V_134 ) ) {
F_149 ( V_66 ) -> V_262 = V_263 ;
F_149 ( V_66 ) -> V_264 = F_158 ( V_134 ) ;
} else {
F_149 ( V_66 ) -> V_262 = 0 ;
F_149 ( V_66 ) -> V_264 = 0 ;
}
V_234 = F_133 ( V_71 -> V_227 , F_108 () ) ;
V_234 -> V_265 ++ ;
V_234 -> V_266 += V_230 ;
F_113 () ;
V_218 ( V_134 ) = V_71 ;
if ( V_60 -> V_109 . V_226 )
F_159 ( V_71 , V_66 ) ;
else if ( F_160 ( V_66 ) )
F_159 ( V_71 , V_66 ) ;
return 0 ;
}
static void F_161 ( struct V_65 * V_66 )
{
F_162 ( & V_267 ) ;
}
static inline int F_163 ( struct V_70 * V_71 ,
struct V_133 * V_134 )
{
struct V_1 * V_2 ;
struct V_202 * V_203 ;
struct V_65 * V_66 = (struct V_65 * ) V_134 ;
struct V_233 * V_234 ;
if ( V_71 -> V_85 && V_66 -> V_242 == V_268 )
F_164 ( V_134 ) &= ~ V_269 ;
else
F_164 ( V_134 ) |= V_269 ;
V_203 = (struct V_202 * ) F_125 ( V_66 ) ;
V_203 = F_141 ( V_134 ) ;
if ( V_203 -> V_270 == V_271 && V_203 -> V_224 == V_225 )
return 0 ;
V_2 = ( (struct V_59 * ) F_31 ( V_71 ) ) -> V_72 ;
if ( F_121 ( & V_2 -> V_7 ) && F_165 ( V_134 ) == V_272 &&
F_126 ( V_203 -> V_273 ) == V_274 ) {
F_109 ( L_46 ) ;
return - V_92 ;
}
if ( ! ( F_164 ( V_134 ) & V_269 ) ||
F_166 ( F_167 ( V_134 ) ) == ~ F_168 ( ~ 0 , V_66 -> V_210 , V_66 -> V_208 ) ) {
F_164 ( V_134 ) &= ~ V_269 ;
return 0 ;
}
V_234 = F_133 ( V_71 -> V_227 , F_108 () ) ;
V_234 -> V_275 ++ ;
if ( V_234 -> V_275 < 5 )
F_72 ( V_276 L_47 ) ;
return - V_92 ;
}
static void F_132 ( struct V_65 * V_66 )
{
T_3 F_140 ;
struct V_70 * V_71 ;
struct V_200 * V_201 ;
struct V_233 * V_234 ;
struct V_108 V_185 ;
struct V_133 * V_134 ;
struct V_59 * V_60 ;
struct V_107 * V_239 ;
V_201 = F_127 ( V_66 ) ;
V_71 = V_201 -> V_218 ;
if ( F_117 ( ! V_71 ) ) {
if ( V_66 -> V_277 != F_161 )
F_2 ( V_66 -> V_39 , L_48 ) ;
F_112 ( V_66 ) ;
return;
}
F_2 ( V_66 -> V_39 , L_49
L_50 ,
V_66 -> V_208 , V_66 -> V_135 ,
V_66 -> V_209 , V_66 -> V_210 , F_118 ( V_66 ) ,
F_119 ( V_66 ) , V_66 -> V_211 ,
V_66 -> V_39 ? V_66 -> V_39 -> V_132 : L_40 ) ;
V_60 = F_31 ( V_71 ) ;
if ( F_148 ( V_66 ) )
F_169 ( V_66 ) ;
V_239 = (struct V_107 * ) F_170 ( V_66 ) ;
V_234 = F_133 ( V_71 -> V_227 , F_108 () ) ;
if ( F_117 ( F_171 ( V_239 ) != V_260 ) ) {
if ( V_234 -> V_228 < 5 )
F_72 ( V_276 L_51
L_52
L_53
L_54
L_55 , F_171 ( V_239 ) ,
V_260 ) ;
goto V_278;
}
F_172 ( V_66 , sizeof( struct V_107 ) ) ;
F_140 = V_66 -> V_208 - sizeof( struct V_108 ) ;
V_234 -> V_279 ++ ;
V_234 -> V_280 += F_140 / V_240 ;
V_134 = (struct V_133 * ) V_66 ;
F_173 ( V_134 ) ;
V_218 ( V_134 ) = V_71 ;
F_144 ( V_134 ) = V_239 -> V_261 ;
if ( F_174 ( V_66 , F_140 , & V_185 , sizeof( V_185 ) ) )
goto V_278;
F_145 ( V_134 ) = V_185 . V_252 ;
F_167 ( V_134 ) = V_185 . V_253 ;
if ( F_175 ( V_66 , F_140 ) )
goto V_278;
if ( ! F_163 ( V_71 , V_134 ) ) {
F_113 () ;
F_176 ( V_71 , V_134 ) ;
return;
}
V_278:
V_234 -> V_228 ++ ;
F_113 () ;
F_112 ( V_66 ) ;
}
int V_181 ( void * V_281 )
{
struct V_176 * V_177 = V_281 ;
struct V_65 * V_66 ;
F_177 ( V_282 , - 20 ) ;
while ( ! F_178 () ) {
F_104 ( & V_177 -> V_182 . V_183 ) ;
while ( ( V_66 = F_110 ( & V_177 -> V_182 ) ) == NULL ) {
F_179 ( V_283 ) ;
F_105 ( & V_177 -> V_182 . V_183 ) ;
F_180 () ;
F_179 ( V_284 ) ;
if ( F_178 () )
return 0 ;
F_104 ( & V_177 -> V_182 . V_183 ) ;
}
F_105 ( & V_177 -> V_182 . V_183 ) ;
F_132 ( V_66 ) ;
}
return 0 ;
}
static void F_181 ( void )
{
F_182 ( & V_285 ) ;
}
static void F_183 ( void )
{
F_184 ( & V_285 ) ;
}
static int F_185 ( struct V_190 * V_286 ,
T_8 V_287 , void * V_288 )
{
struct V_70 * V_71 = NULL ;
struct V_3 * V_4 = V_288 ;
struct V_1 * V_2 ;
struct V_59 * V_60 ;
struct V_233 * V_234 ;
T_3 V_289 = 1 ;
T_3 V_101 ;
int V_116 = V_198 ;
F_70 (fcoe, &fcoe_hostlist, list) {
if ( V_2 -> V_4 == V_4 ) {
V_71 = V_2 -> V_7 . V_61 ;
break;
}
}
if ( ! V_71 ) {
V_116 = V_290 ;
goto V_48;
}
switch ( V_287 ) {
case V_291 :
case V_292 :
V_289 = 0 ;
break;
case V_293 :
case V_294 :
break;
case V_295 :
if ( V_4 -> V_94 & V_105 )
break;
V_101 = V_4 -> V_104 - ( sizeof( struct V_107 ) +
sizeof( struct V_108 ) ) ;
if ( V_101 >= V_296 )
F_54 ( V_71 , V_101 ) ;
break;
case V_297 :
break;
case V_298 :
F_186 ( & V_2 -> V_299 ) ;
V_60 = F_31 ( V_2 -> V_7 . V_61 ) ;
F_30 ( V_2 ) ;
F_187 ( V_300 , & V_60 -> V_165 ) ;
goto V_48;
break;
case V_301 :
F_50 ( V_71 , V_4 ) ;
break;
default:
F_2 ( V_4 , L_56
L_57 , V_287 ) ;
}
F_57 ( V_71 ) ;
if ( V_289 && ! F_188 ( V_71 ) )
F_189 ( & V_2 -> V_7 ) ;
else if ( F_190 ( & V_2 -> V_7 ) ) {
V_234 = F_133 ( V_71 -> V_227 , F_108 () ) ;
V_234 -> V_302 ++ ;
F_113 () ;
F_35 ( V_71 ) ;
}
V_48:
return V_116 ;
}
static int F_191 ( struct V_3 * V_4 )
{
struct V_1 * V_2 ;
int V_116 = 0 ;
F_51 ( & V_303 ) ;
F_44 () ;
V_2 = F_192 ( V_4 ) ;
F_45 () ;
if ( V_2 ) {
F_190 ( & V_2 -> V_7 ) ;
F_35 ( V_2 -> V_7 . V_61 ) ;
} else
V_116 = - V_174 ;
F_52 ( & V_303 ) ;
return V_116 ;
}
static int F_193 ( struct V_3 * V_4 )
{
struct V_1 * V_2 ;
int V_116 = 0 ;
F_51 ( & V_303 ) ;
F_44 () ;
V_2 = F_192 ( V_4 ) ;
F_45 () ;
if ( ! V_2 )
V_116 = - V_174 ;
else if ( ! F_188 ( V_2 -> V_7 . V_61 ) )
F_189 ( & V_2 -> V_7 ) ;
F_52 ( & V_303 ) ;
return V_116 ;
}
static int F_194 ( struct V_3 * V_4 )
{
struct V_1 * V_2 ;
struct V_70 * V_71 ;
int V_116 = 0 ;
F_51 ( & V_303 ) ;
F_44 () ;
V_2 = F_192 ( V_4 ) ;
if ( ! V_2 ) {
F_45 () ;
V_116 = - V_174 ;
goto V_304;
}
V_71 = V_2 -> V_7 . V_61 ;
F_186 ( & V_2 -> V_299 ) ;
F_30 ( V_2 ) ;
F_45 () ;
F_74 ( V_71 ) ;
V_304:
F_52 ( & V_303 ) ;
return V_116 ;
}
static void V_166 ( struct V_305 * V_306 )
{
struct V_59 * V_60 ;
V_60 = F_25 ( V_306 , struct V_59 , V_165 ) ;
F_51 ( & V_303 ) ;
F_74 ( V_60 -> V_71 ) ;
F_52 ( & V_303 ) ;
}
static bool F_195 ( struct V_3 * V_4 )
{
return true ;
}
static int F_196 ( struct V_3 * V_4 , enum V_43 V_44 )
{
int V_116 ;
struct V_1 * V_2 ;
struct V_70 * V_71 ;
F_51 ( & V_303 ) ;
F_44 () ;
if ( F_197 ( V_4 ) ) {
V_116 = - V_307 ;
goto V_304;
}
V_2 = F_13 ( V_4 , V_44 ) ;
if ( F_101 ( V_2 ) ) {
V_116 = F_198 ( V_2 ) ;
goto V_304;
}
V_71 = F_84 ( V_2 , & V_4 -> V_39 , 0 ) ;
if ( F_101 ( V_71 ) ) {
F_72 ( V_146 L_58 ,
V_4 -> V_132 ) ;
V_116 = - V_308 ;
F_30 ( V_2 ) ;
goto V_309;
}
V_2 -> V_7 . V_61 = V_71 ;
F_199 ( V_71 ) ;
V_71 -> V_310 = V_311 ;
F_200 ( V_71 ) ;
if ( ! F_188 ( V_71 ) )
F_189 ( & V_2 -> V_7 ) ;
F_28 ( V_2 ) ;
F_45 () ;
F_52 ( & V_303 ) ;
return 0 ;
V_309:
F_28 ( V_2 ) ;
V_304:
F_45 () ;
F_52 ( & V_303 ) ;
return V_116 ;
}
int F_57 ( struct V_70 * V_71 )
{
struct V_3 * V_4 = F_63 ( V_71 ) ;
struct V_312 V_313 ;
if ( ! F_201 ( V_4 , & V_313 ) ) {
V_71 -> V_314 &=
~ ( V_315 | V_316 ) ;
if ( V_313 . V_317 & ( V_318 |
V_319 ) )
V_71 -> V_314 |= V_315 ;
if ( V_313 . V_317 & V_320 )
V_71 -> V_314 |=
V_316 ;
switch ( F_202 ( & V_313 ) ) {
case V_321 :
V_71 -> V_322 = V_315 ;
break;
case V_323 :
V_71 -> V_322 = V_316 ;
break;
}
return 0 ;
}
return - 1 ;
}
int F_188 ( struct V_70 * V_71 )
{
struct V_3 * V_4 = F_63 ( V_71 ) ;
if ( F_203 ( V_4 ) )
return 0 ;
return - 1 ;
}
void F_75 ( struct V_70 * V_71 )
{
struct V_176 * V_324 ;
struct V_200 * V_201 ;
struct V_325 * V_299 ;
struct V_65 * V_66 , * V_326 ;
struct V_65 * V_209 ;
unsigned int V_175 ;
F_204 (cpu) {
V_324 = & F_98 ( V_180 , V_175 ) ;
F_104 ( & V_324 -> V_182 . V_183 ) ;
V_299 = & V_324 -> V_182 ;
V_209 = V_299 -> V_326 ;
for ( V_66 = V_209 ; V_66 != (struct V_65 * ) V_299 ;
V_66 = V_326 ) {
V_326 = V_66 -> V_326 ;
V_201 = F_127 ( V_66 ) ;
if ( V_201 -> V_218 == V_71 ) {
F_205 ( V_66 , V_299 ) ;
F_112 ( V_66 ) ;
}
}
if ( ! V_324 -> V_179 || ! F_206 ( V_175 ) ) {
F_105 ( & V_324 -> V_182 . V_183 ) ;
continue;
}
V_66 = F_207 ( 0 ) ;
if ( ! V_66 ) {
F_105 ( & V_324 -> V_182 . V_183 ) ;
continue;
}
V_66 -> V_277 = F_161 ;
F_111 ( & V_324 -> V_182 , V_66 ) ;
if ( V_324 -> V_182 . V_226 == 1 )
F_103 ( V_324 -> V_179 ) ;
F_105 ( & V_324 -> V_182 . V_183 ) ;
F_208 ( & V_267 ) ;
}
}
int F_209 ( struct V_157 * V_158 )
{
struct V_70 * V_71 = F_91 ( V_158 ) ;
struct V_59 * V_60 = F_31 ( V_71 ) ;
struct V_1 * V_2 = V_60 -> V_72 ;
F_190 ( & V_2 -> V_7 ) ;
F_35 ( V_2 -> V_7 . V_61 ) ;
if ( ! F_188 ( V_2 -> V_7 . V_61 ) )
F_189 ( & V_2 -> V_7 ) ;
return 0 ;
}
static struct V_1 *
F_192 ( const struct V_3 * V_4 )
{
struct V_1 * V_2 ;
F_70 (fcoe, &fcoe_hostlist, list) {
if ( V_2 -> V_4 == V_4 )
return V_2 ;
}
return NULL ;
}
static struct V_70 * F_197 ( const struct V_3 * V_4 )
{
struct V_1 * V_2 ;
V_2 = F_192 ( V_4 ) ;
return ( V_2 ) ? V_2 -> V_7 . V_61 : NULL ;
}
static int F_199 ( const struct V_70 * V_71 )
{
struct V_1 * V_2 ;
struct V_59 * V_60 ;
V_2 = F_192 ( F_63 ( V_71 ) ) ;
if ( ! V_2 ) {
V_60 = F_31 ( V_71 ) ;
V_2 = V_60 -> V_72 ;
F_210 ( & V_2 -> V_299 , & V_327 ) ;
}
return 0 ;
}
static int T_5 F_211 ( void )
{
struct V_176 * V_177 ;
unsigned int V_175 ;
int V_116 = 0 ;
V_300 = F_212 ( L_59 , 0 , 0 ) ;
if ( ! V_300 )
return - V_50 ;
V_116 = F_213 ( & V_328 ) ;
if ( V_116 ) {
F_72 ( V_146 L_60
L_61 ) ;
return V_116 ;
}
F_51 ( & V_303 ) ;
F_204 (cpu) {
V_177 = & F_98 ( V_180 , V_175 ) ;
F_55 ( & V_177 -> V_182 ) ;
}
F_214 (cpu)
F_97 ( V_175 ) ;
V_116 = F_215 ( & V_329 ) ;
if ( V_116 )
goto V_309;
F_181 () ;
V_116 = F_93 () ;
if ( V_116 )
goto V_309;
F_52 ( & V_303 ) ;
return 0 ;
V_309:
F_214 (cpu) {
F_106 ( V_175 ) ;
}
F_52 ( & V_303 ) ;
F_216 ( V_300 ) ;
return V_116 ;
}
static void T_6 F_217 ( void )
{
struct V_1 * V_2 , * V_330 ;
struct V_59 * V_60 ;
unsigned int V_175 ;
F_51 ( & V_303 ) ;
F_183 () ;
F_44 () ;
F_218 (fcoe, tmp, &fcoe_hostlist, list) {
F_186 ( & V_2 -> V_299 ) ;
V_60 = F_31 ( V_2 -> V_7 . V_61 ) ;
F_30 ( V_2 ) ;
F_187 ( V_300 , & V_60 -> V_165 ) ;
}
F_45 () ;
F_219 ( & V_329 ) ;
F_214 (cpu)
F_106 ( V_175 ) ;
F_52 ( & V_303 ) ;
F_216 ( V_300 ) ;
F_95 () ;
F_220 ( & V_328 ) ;
}
static void F_221 ( struct V_331 * V_332 , struct V_133 * V_134 , void * V_281 )
{
struct V_5 * V_6 = V_281 ;
struct V_333 * V_334 = F_222 ( V_332 ) ;
struct V_70 * V_71 = V_334 -> V_61 ;
T_1 * V_335 ;
if ( F_101 ( V_134 ) )
goto V_336;
V_335 = F_223 ( V_134 ) -> V_337 ;
if ( F_40 ( V_335 ) ) {
if ( F_224 ( V_6 , V_71 , V_134 ) ) {
F_225 ( V_134 ) ;
return;
}
}
V_56 ( V_71 , V_335 ) ;
V_336:
F_226 ( V_332 , V_134 , V_71 ) ;
}
static void F_227 ( struct V_331 * V_332 , struct V_133 * V_134 , void * V_281 )
{
struct V_70 * V_71 = V_281 ;
static T_1 V_338 [ V_12 ] = { 0 } ;
if ( ! F_101 ( V_134 ) )
V_56 ( V_71 , V_338 ) ;
F_228 ( V_332 , V_134 , V_71 ) ;
}
static struct V_331 * F_229 ( struct V_70 * V_71 , T_3 V_339 ,
struct V_133 * V_134 , unsigned int V_340 ,
void (* F_230)( struct V_331 * ,
struct V_133 * ,
void * ) ,
void * V_281 , T_3 V_341 )
{
struct V_59 * V_60 = F_31 ( V_71 ) ;
struct V_1 * V_2 = V_60 -> V_72 ;
struct V_5 * V_6 = & V_2 -> V_7 ;
struct V_202 * V_203 = F_141 ( V_134 ) ;
switch ( V_340 ) {
case V_342 :
case V_343 :
if ( V_71 -> V_344 )
break;
return F_231 ( V_71 , V_339 , V_134 , V_340 , F_221 ,
V_6 , V_341 ) ;
case V_272 :
if ( F_126 ( V_203 -> V_217 ) != V_274 )
break;
return F_231 ( V_71 , V_339 , V_134 , V_340 , F_227 ,
V_71 , V_341 ) ;
}
return F_231 ( V_71 , V_339 , V_134 , V_340 , F_230 , V_281 , V_341 ) ;
}
static int F_232 ( struct V_159 * V_112 , bool V_345 )
{
struct V_157 * V_158 = F_90 ( V_112 ) ;
struct V_70 * V_156 = F_91 ( V_158 ) ;
struct V_59 * V_60 = F_31 ( V_156 ) ;
struct V_1 * V_2 = V_60 -> V_72 ;
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_70 * V_346 ;
int V_116 ;
char V_347 [ 32 ] ;
V_116 = F_233 ( V_112 ) ;
if ( V_116 ) {
F_234 ( V_112 -> V_169 , V_347 , sizeof( V_347 ) ) ;
F_72 ( V_146 L_62
L_63 ,
V_347 ) ;
return V_116 ;
}
F_51 ( & V_303 ) ;
V_346 = F_84 ( V_2 , & V_112 -> V_39 , 1 ) ;
F_52 ( & V_303 ) ;
if ( F_101 ( V_346 ) ) {
F_72 ( V_146 L_64 ,
V_4 -> V_132 ) ;
return - V_308 ;
}
if ( V_345 ) {
F_235 ( V_112 , V_348 ) ;
} else {
V_346 -> V_310 = V_311 ;
F_200 ( V_346 ) ;
F_236 ( V_346 ) ;
}
return 0 ;
}
static int F_237 ( struct V_159 * V_112 )
{
struct V_157 * V_158 = F_90 ( V_112 ) ;
struct V_70 * V_156 = F_91 ( V_158 ) ;
struct V_70 * V_346 = V_112 -> V_349 ;
struct V_59 * V_60 = F_31 ( V_346 ) ;
F_51 ( & V_156 -> V_93 ) ;
F_186 ( & V_346 -> V_299 ) ;
F_52 ( & V_156 -> V_93 ) ;
F_187 ( V_300 , & V_60 -> V_165 ) ;
return 0 ;
}
static int F_238 ( struct V_159 * V_112 , bool V_350 )
{
struct V_70 * V_71 = V_112 -> V_349 ;
if ( V_350 ) {
F_235 ( V_112 , V_348 ) ;
F_32 ( V_71 ) ;
} else {
V_71 -> V_310 = V_311 ;
F_200 ( V_71 ) ;
F_236 ( V_71 ) ;
}
return 0 ;
}
static void F_239 ( struct V_159 * V_112 )
{
struct V_70 * V_71 = V_112 -> V_349 ;
struct V_133 * V_134 ;
T_9 V_208 ;
snprintf ( F_65 ( V_71 -> V_117 ) , V_129 ,
L_65 , V_130 , V_131 ,
F_63 ( V_71 ) -> V_132 , V_112 -> V_351 ) ;
if ( V_71 -> V_352 != V_353 )
return;
V_208 = F_240 ( F_65 ( V_71 -> V_117 ) , 255 ) ;
V_134 = F_241 ( V_71 ,
sizeof( struct V_354 ) +
sizeof( struct V_355 ) + V_208 ) ;
if ( ! V_134 )
return;
V_71 -> V_356 . V_357 ( V_71 , V_358 , V_134 , V_359 ,
NULL , NULL , 3 * V_71 -> V_78 ) ;
}
static void F_242 ( struct V_70 * V_71 ,
struct V_360 * V_361 )
{
unsigned int V_175 ;
T_3 V_362 , V_363 , V_364 ;
struct V_233 * V_365 ;
struct V_366 * V_367 ;
struct V_368 V_369 ;
struct V_3 * V_4 = F_63 ( V_71 ) ;
V_362 = 0 ;
V_363 = 0 ;
V_364 = 0 ;
V_367 = (struct V_366 * ) V_361 ;
memset ( V_367 , 0 , sizeof( * V_367 ) ) ;
F_204 (cpu) {
V_365 = F_133 ( V_71 -> V_227 , V_175 ) ;
V_362 += V_365 -> V_302 ;
V_363 += V_365 -> V_370 ;
V_364 += V_365 -> V_371 ;
}
V_367 -> V_372 = F_243 ( V_362 ) ;
V_367 -> V_373 = F_243 ( V_363 ) ;
V_367 -> V_374 = F_243 ( V_364 ) ;
V_367 -> V_375 = F_243 ( F_244 ( V_4 , & V_369 ) -> V_376 ) ;
}
static void F_245 ( struct V_70 * V_71 ,
T_3 V_377 , struct V_133 * V_134 )
{
struct V_59 * V_60 = F_31 ( V_71 ) ;
struct V_1 * V_2 = V_60 -> V_72 ;
if ( V_134 && F_165 ( V_134 ) == V_342 )
F_224 ( & V_2 -> V_7 , V_71 , V_134 ) ;
}
static int F_233 ( struct V_159 * V_112 )
{
struct V_157 * V_158 = F_90 ( V_112 ) ;
struct V_70 * V_156 = F_91 ( V_158 ) ;
struct V_70 * V_346 ;
int V_116 = 0 ;
char V_347 [ 32 ] ;
F_51 ( & V_156 -> V_93 ) ;
F_234 ( V_112 -> V_169 , V_347 , sizeof( V_347 ) ) ;
if ( ! memcmp ( & V_156 -> V_103 , & V_112 -> V_169 , sizeof( T_2 ) ) ) {
F_109 ( L_66
L_67 , V_347 ) ;
V_116 = - V_92 ;
goto V_48;
}
F_70 (vn_port, &n_port->vports, list) {
if ( ! memcmp ( & V_346 -> V_103 , & V_112 -> V_169 , sizeof( T_2 ) ) ) {
F_109 ( L_68
L_69 , V_347 ) ;
V_116 = - V_92 ;
break;
}
}
V_48:
F_52 ( & V_156 -> V_93 ) ;
return V_116 ;
}
