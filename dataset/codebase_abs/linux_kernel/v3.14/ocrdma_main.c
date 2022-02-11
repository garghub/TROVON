void F_1 ( struct V_1 * V_2 , T_1 * V_3 )
{
T_1 V_4 [ 6 ] ;
memcpy ( & V_4 [ 0 ] , & V_2 -> V_5 . V_4 [ 0 ] , V_6 ) ;
V_3 [ 0 ] = V_4 [ 0 ] ^ 2 ;
V_3 [ 1 ] = V_4 [ 1 ] ;
V_3 [ 2 ] = V_4 [ 2 ] ;
V_3 [ 3 ] = 0xff ;
V_3 [ 4 ] = 0xfe ;
V_3 [ 5 ] = V_4 [ 3 ] ;
V_3 [ 6 ] = V_4 [ 4 ] ;
V_3 [ 7 ] = V_4 [ 5 ] ;
}
static bool F_2 ( struct V_1 * V_2 , union V_7 * V_8 )
{
int V_9 ;
unsigned long V_10 ;
memset ( & V_11 , 0 , sizeof( union V_7 ) ) ;
F_3 ( & V_2 -> V_12 , V_10 ) ;
for ( V_9 = 0 ; V_9 < V_13 ; V_9 ++ ) {
if ( ! memcmp ( & V_2 -> V_14 [ V_9 ] , & V_11 ,
sizeof( union V_7 ) ) ) {
memcpy ( & V_2 -> V_14 [ V_9 ] , V_8 ,
sizeof( union V_7 ) ) ;
F_4 ( & V_2 -> V_12 , V_10 ) ;
return true ;
} else if ( ! memcmp ( & V_2 -> V_14 [ V_9 ] , V_8 ,
sizeof( union V_7 ) ) ) {
F_4 ( & V_2 -> V_12 , V_10 ) ;
return false ;
}
}
F_4 ( & V_2 -> V_12 , V_10 ) ;
return false ;
}
static bool F_5 ( struct V_1 * V_2 , union V_7 * V_15 )
{
int V_16 = false ;
int V_9 ;
unsigned long V_10 ;
F_3 ( & V_2 -> V_12 , V_10 ) ;
for ( V_9 = 1 ; V_9 < V_13 ; V_9 ++ ) {
if ( ! memcmp ( & V_2 -> V_14 [ V_9 ] , V_15 , sizeof( union V_7 ) ) ) {
memset ( & V_2 -> V_14 [ V_9 ] , 0 , sizeof( union V_7 ) ) ;
V_16 = true ;
break;
}
}
F_4 ( & V_2 -> V_12 , V_10 ) ;
return V_16 ;
}
static int F_6 ( unsigned long V_17 , struct V_18 * V_19 ,
union V_7 * V_20 )
{
struct V_21 V_22 ;
struct V_1 * V_2 ;
bool V_16 = false ;
bool V_23 = false ;
bool V_24 = false ;
V_24 = V_19 -> V_25 & V_26 ;
if ( V_24 )
V_19 = F_7 ( V_19 ) ;
F_8 () ;
F_9 (dev, &ocrdma_dev_list, entry) {
if ( V_2 -> V_5 . V_19 == V_19 ) {
V_16 = true ;
break;
}
}
F_10 () ;
if ( ! V_16 )
return V_27 ;
F_11 ( & V_2 -> V_28 ) ;
switch ( V_17 ) {
case V_29 :
V_23 = F_2 ( V_2 , V_20 ) ;
break;
case V_30 :
V_23 = F_5 ( V_2 , V_20 ) ;
break;
default:
break;
}
if ( V_23 ) {
V_22 . V_31 = & V_2 -> V_32 ;
V_22 . V_33 . V_34 = 1 ;
V_22 . V_17 = V_35 ;
F_12 ( & V_22 ) ;
}
F_13 ( & V_2 -> V_28 ) ;
return V_36 ;
}
static int F_14 ( struct V_37 * V_38 ,
unsigned long V_17 , void * V_39 )
{
struct V_40 * V_41 = V_39 ;
union V_7 V_20 ;
struct V_18 * V_19 = V_41 -> V_42 -> V_2 ;
F_15 ( V_41 -> V_43 , (struct V_44 * ) & V_20 ) ;
return F_6 ( V_17 , V_19 , & V_20 ) ;
}
static int F_16 ( struct V_37 * V_38 ,
unsigned long V_17 , void * V_39 )
{
struct V_45 * V_41 = (struct V_45 * ) V_39 ;
union V_7 * V_20 = (union V_7 * ) & V_41 -> V_46 ;
struct V_18 * V_19 = V_41 -> V_47 -> V_2 ;
return F_6 ( V_17 , V_19 , V_20 ) ;
}
static enum V_48 F_17 ( struct V_49 * V_31 ,
T_1 V_34 )
{
return V_50 ;
}
static int F_18 ( struct V_1 * V_2 )
{
F_19 ( V_2 -> V_32 . V_51 , L_1 , V_52 ) ;
F_1 ( V_2 , ( T_1 * ) & V_2 -> V_32 . V_53 ) ;
memcpy ( V_2 -> V_32 . V_54 , V_55 ,
sizeof( V_55 ) ) ;
V_2 -> V_32 . V_56 = V_57 ;
V_2 -> V_32 . V_58 = V_59 ;
V_2 -> V_32 . V_60 =
F_20 ( V_61 ) |
F_20 ( V_62 ) |
F_20 ( V_63 ) |
F_20 ( V_64 ) |
F_20 ( V_65 ) |
F_20 ( V_66 ) |
F_20 ( V_67 ) |
F_20 ( V_68 ) |
F_20 ( V_69 ) |
F_20 ( V_70 ) |
F_20 ( V_71 ) |
F_20 ( V_72 ) |
F_20 ( V_73 ) |
F_20 ( V_74 ) |
F_20 ( V_75 ) |
F_20 ( V_76 ) |
F_20 ( V_77 ) |
F_20 ( V_78 ) |
F_20 ( V_79 ) ;
V_2 -> V_32 . V_60 |=
F_20 ( V_80 ) |
F_20 ( V_81 ) |
F_20 ( V_82 ) |
F_20 ( V_83 ) ;
V_2 -> V_32 . V_84 = V_85 ;
V_2 -> V_32 . V_86 = 1 ;
V_2 -> V_32 . V_87 = 1 ;
V_2 -> V_32 . V_88 = V_89 ;
V_2 -> V_32 . V_90 = V_91 ;
V_2 -> V_32 . V_92 = V_93 ;
V_2 -> V_32 . V_94 = V_95 ;
V_2 -> V_32 . V_96 = F_17 ;
V_2 -> V_32 . V_97 = V_98 ;
V_2 -> V_32 . V_99 = V_100 ;
V_2 -> V_32 . V_101 = V_102 ;
V_2 -> V_32 . V_103 = V_104 ;
V_2 -> V_32 . V_105 = V_106 ;
V_2 -> V_32 . V_107 = V_108 ;
V_2 -> V_32 . V_109 = V_110 ;
V_2 -> V_32 . V_111 = V_112 ;
V_2 -> V_32 . V_113 = V_114 ;
V_2 -> V_32 . V_115 = V_116 ;
V_2 -> V_32 . V_117 = V_118 ;
V_2 -> V_32 . V_119 = V_120 ;
V_2 -> V_32 . V_121 = V_122 ;
V_2 -> V_32 . V_123 = V_124 ;
V_2 -> V_32 . V_125 = V_126 ;
V_2 -> V_32 . V_127 = V_128 ;
V_2 -> V_32 . V_129 = V_130 ;
V_2 -> V_32 . V_131 = V_132 ;
V_2 -> V_32 . V_133 = V_134 ;
V_2 -> V_32 . V_135 = V_136 ;
V_2 -> V_32 . V_137 = V_138 ;
V_2 -> V_32 . V_139 = V_140 ;
V_2 -> V_32 . V_141 = V_142 ;
V_2 -> V_32 . V_143 = V_144 ;
V_2 -> V_32 . V_145 = V_146 ;
V_2 -> V_32 . V_147 = V_148 ;
V_2 -> V_32 . V_149 = V_150 ;
V_2 -> V_32 . V_151 = V_152 ;
V_2 -> V_32 . V_153 = & V_2 -> V_5 . V_154 -> V_2 ;
V_2 -> V_32 . V_155 = V_156 ;
if ( V_2 -> V_5 . V_157 == V_158 ) {
V_2 -> V_32 . V_60 |=
F_20 ( V_159 ) |
F_20 ( V_160 ) |
F_20 ( V_161 ) |
F_20 ( V_162 ) |
F_20 ( V_163 ) ;
V_2 -> V_32 . V_164 = V_165 ;
V_2 -> V_32 . V_166 = V_167 ;
V_2 -> V_32 . V_168 = V_169 ;
V_2 -> V_32 . V_170 = V_171 ;
V_2 -> V_32 . V_172 = V_173 ;
}
return F_21 ( & V_2 -> V_32 , NULL ) ;
}
static int F_22 ( struct V_1 * V_2 )
{
F_23 ( & V_2 -> V_28 ) ;
V_2 -> V_14 = F_24 ( sizeof( union V_7 ) *
V_13 , V_174 ) ;
if ( ! V_2 -> V_14 )
goto V_175;
F_25 ( & V_2 -> V_12 ) ;
V_2 -> V_176 = F_24 ( sizeof( struct V_177 * ) *
V_178 , V_174 ) ;
if ( ! V_2 -> V_176 )
goto V_175;
if ( V_2 -> V_179 . V_180 ) {
V_2 -> V_181 = F_24 ( sizeof( struct V_182 * ) *
V_183 , V_174 ) ;
if ( ! V_2 -> V_181 )
goto V_175;
}
F_25 ( & V_2 -> V_184 . V_185 ) ;
F_25 ( & V_2 -> V_186 ) ;
return 0 ;
V_175:
F_26 ( L_2 , V_187 , V_2 -> V_188 ) ;
return - V_189 ;
}
static void F_27 ( struct V_1 * V_2 )
{
F_28 ( V_2 -> V_181 ) ;
F_28 ( V_2 -> V_176 ) ;
F_28 ( V_2 -> V_14 ) ;
}
static struct V_1 * F_29 ( struct V_190 * V_191 )
{
int V_192 = 0 ;
struct V_1 * V_2 ;
V_2 = (struct V_1 * ) F_30 ( sizeof( struct V_1 ) ) ;
if ( ! V_2 ) {
F_26 ( L_3 ) ;
return NULL ;
}
V_2 -> V_193 = F_24 ( sizeof( struct V_194 ) , V_174 ) ;
if ( ! V_2 -> V_193 )
goto V_195;
memcpy ( & V_2 -> V_5 , V_191 , sizeof( * V_191 ) ) ;
V_2 -> V_188 = F_31 ( & V_196 , NULL , 0 , 0 , V_174 ) ;
if ( V_2 -> V_188 < 0 )
goto V_195;
V_192 = F_32 ( V_2 ) ;
if ( V_192 )
goto V_197;
V_192 = F_22 ( V_2 ) ;
if ( V_192 )
goto V_175;
V_192 = F_18 ( V_2 ) ;
if ( V_192 )
goto V_175;
F_33 ( & V_198 ) ;
F_34 ( & V_2 -> V_199 , & V_200 ) ;
F_35 ( & V_198 ) ;
return V_2 ;
V_175:
F_27 ( V_2 ) ;
F_36 ( V_2 ) ;
V_197:
F_37 ( & V_196 , V_2 -> V_188 ) ;
V_195:
F_28 ( V_2 -> V_193 ) ;
F_38 ( & V_2 -> V_32 ) ;
F_26 ( L_4 , V_187 , V_192 ) ;
return NULL ;
}
static void F_39 ( struct V_201 * V_202 )
{
struct V_1 * V_2 = F_40 ( V_202 , struct V_1 , V_202 ) ;
F_37 ( & V_196 , V_2 -> V_188 ) ;
F_28 ( V_2 -> V_193 ) ;
F_38 ( & V_2 -> V_32 ) ;
}
static void F_41 ( struct V_1 * V_2 )
{
F_42 ( & V_2 -> V_32 ) ;
F_33 ( & V_198 ) ;
F_43 ( & V_2 -> V_199 ) ;
F_35 ( & V_198 ) ;
F_27 ( V_2 ) ;
F_36 ( V_2 ) ;
F_44 ( & V_2 -> V_202 , F_39 ) ;
}
static int F_45 ( struct V_1 * V_2 )
{
struct V_21 V_203 ;
V_203 . V_17 = V_204 ;
V_203 . V_33 . V_34 = 1 ;
V_203 . V_31 = & V_2 -> V_32 ;
F_12 ( & V_203 ) ;
return 0 ;
}
static int F_46 ( struct V_1 * V_2 )
{
int V_9 ;
struct V_182 * V_205 , * * V_206 ;
struct V_21 V_207 ;
struct V_208 V_209 ;
int V_210 = V_211 ;
V_209 . V_212 = V_213 ;
F_11 ( & V_2 -> V_28 ) ;
if ( V_2 -> V_181 ) {
V_206 = V_2 -> V_181 ;
for ( V_9 = 0 ; V_9 < V_183 ; V_9 ++ ) {
V_205 = V_206 [ V_9 ] ;
if ( V_205 ) {
F_47 ( & V_205 -> V_214 , & V_209 , V_210 ) ;
V_207 . V_17 = V_215 ;
V_207 . V_33 . V_205 = & V_205 -> V_214 ;
V_207 . V_31 = & V_2 -> V_32 ;
F_12 ( & V_207 ) ;
}
}
}
F_13 ( & V_2 -> V_28 ) ;
V_207 . V_17 = V_216 ;
V_207 . V_33 . V_34 = 1 ;
V_207 . V_31 = & V_2 -> V_32 ;
F_12 ( & V_207 ) ;
return 0 ;
}
static void F_48 ( struct V_1 * V_2 , T_2 V_17 )
{
switch ( V_17 ) {
case V_217 :
F_45 ( V_2 ) ;
break;
case V_218 :
F_46 ( V_2 ) ;
break;
}
}
static void F_49 ( void )
{
#if F_50 ( V_219 )
F_51 ( & V_220 ) ;
#endif
}
static int T_3 F_52 ( void )
{
int V_192 ;
V_192 = F_53 ( & V_221 ) ;
if ( V_192 )
return V_192 ;
#if F_50 ( V_219 )
V_192 = F_54 ( & V_220 ) ;
if ( V_192 )
return V_192 ;
#endif
V_192 = F_55 ( & V_222 ) ;
if ( V_192 )
F_49 () ;
return V_192 ;
}
static void T_4 F_56 ( void )
{
F_57 ( & V_222 ) ;
F_49 () ;
}
