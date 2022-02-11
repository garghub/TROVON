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
static void F_2 ( union V_7 * V_8 , unsigned char * V_4 ,
bool V_9 , T_2 V_10 )
{
V_8 -> V_11 . V_12 = F_3 ( 0xfe80000000000000LL ) ;
V_8 -> V_13 [ 8 ] = V_4 [ 0 ] ^ 2 ;
V_8 -> V_13 [ 9 ] = V_4 [ 1 ] ;
V_8 -> V_13 [ 10 ] = V_4 [ 2 ] ;
if ( V_9 ) {
V_8 -> V_13 [ 11 ] = V_10 >> 8 ;
V_8 -> V_13 [ 12 ] = V_10 & 0xff ;
} else {
V_8 -> V_13 [ 11 ] = 0xff ;
V_8 -> V_13 [ 12 ] = 0xfe ;
}
V_8 -> V_13 [ 13 ] = V_4 [ 3 ] ;
V_8 -> V_13 [ 14 ] = V_4 [ 4 ] ;
V_8 -> V_13 [ 15 ] = V_4 [ 5 ] ;
}
static bool F_4 ( struct V_1 * V_2 , unsigned char * V_4 ,
bool V_9 , T_2 V_10 )
{
int V_14 ;
union V_7 V_15 ;
unsigned long V_16 ;
memset ( & V_17 , 0 , sizeof( union V_7 ) ) ;
F_2 ( & V_15 , V_4 , V_9 , V_10 ) ;
F_5 ( & V_2 -> V_18 , V_16 ) ;
for ( V_14 = 0 ; V_14 < V_19 ; V_14 ++ ) {
if ( ! memcmp ( & V_2 -> V_20 [ V_14 ] , & V_17 ,
sizeof( union V_7 ) ) ) {
memcpy ( & V_2 -> V_20 [ V_14 ] , & V_15 ,
sizeof( union V_7 ) ) ;
F_6 ( & V_2 -> V_18 , V_16 ) ;
return true ;
} else if ( ! memcmp ( & V_2 -> V_20 [ V_14 ] , & V_15 ,
sizeof( union V_7 ) ) ) {
F_6 ( & V_2 -> V_18 , V_16 ) ;
return false ;
}
}
F_6 ( & V_2 -> V_18 , V_16 ) ;
return false ;
}
static bool F_7 ( struct V_1 * V_2 , unsigned char * V_4 ,
bool V_9 , T_2 V_10 )
{
int V_21 = false ;
int V_14 ;
union V_7 V_8 ;
unsigned long V_16 ;
F_2 ( & V_8 , V_4 , V_9 , V_10 ) ;
F_5 ( & V_2 -> V_18 , V_16 ) ;
for ( V_14 = 1 ; V_14 < V_19 ; V_14 ++ ) {
if ( ! memcmp ( & V_2 -> V_20 [ V_14 ] , & V_8 , sizeof( union V_7 ) ) ) {
memset ( & V_2 -> V_20 [ V_14 ] , 0 , sizeof( union V_7 ) ) ;
V_21 = true ;
break;
}
}
F_6 ( & V_2 -> V_18 , V_16 ) ;
return V_21 ;
}
static void F_8 ( struct V_1 * V_2 )
{
union V_7 * V_8 = & V_2 -> V_20 [ 0 ] ;
V_8 -> V_11 . V_12 = F_3 ( 0xfe80000000000000LL ) ;
F_1 ( V_2 , & V_8 -> V_13 [ 8 ] ) ;
}
static void F_9 ( struct V_1 * V_2 )
{
struct V_22 * V_23 , * V_24 ;
T_2 V_10 ;
bool V_9 ;
V_23 = V_2 -> V_5 . V_23 ;
F_10 () ;
F_11 (&init_net, tmp) {
if ( V_23 == V_24 || F_12 ( V_24 ) == V_23 ) {
if ( ! F_13 ( V_24 ) || ! F_14 ( V_24 ) )
continue;
if ( V_23 != V_24 ) {
V_10 = F_15 ( V_24 ) ;
V_9 = true ;
} else {
V_9 = false ;
V_10 = 0 ;
V_24 = V_23 ;
}
F_4 ( V_2 , V_24 -> V_25 , V_9 , V_10 ) ;
}
}
F_16 () ;
}
static void F_9 ( struct V_1 * V_2 )
{
}
static int F_17 ( struct V_1 * V_2 )
{
F_8 ( V_2 ) ;
F_9 ( V_2 ) ;
return 0 ;
}
static int F_18 ( struct V_26 * V_27 ,
unsigned long V_28 , void * V_29 )
{
struct V_30 * V_31 = (struct V_30 * ) V_29 ;
struct V_22 * V_23 = V_31 -> V_32 -> V_2 ;
struct V_33 V_34 ;
struct V_1 * V_2 ;
bool V_21 = false ;
bool V_35 = false ;
bool V_9 = false ;
T_2 V_36 = 0 ;
V_9 = V_23 -> V_37 & V_38 ;
if ( V_9 ) {
V_36 = F_15 ( V_23 ) ;
V_23 = F_12 ( V_23 ) ;
}
F_10 () ;
F_19 (dev, &ocrdma_dev_list, entry) {
if ( V_2 -> V_5 . V_23 == V_23 ) {
V_21 = true ;
break;
}
}
F_16 () ;
if ( ! V_21 )
return V_39 ;
if ( ! F_20 ( (struct V_40 * ) & V_31 -> V_41 ) )
return V_39 ;
F_21 ( & V_2 -> V_42 ) ;
switch ( V_28 ) {
case V_43 :
V_35 = F_4 ( V_2 , V_23 -> V_25 , V_9 , V_36 ) ;
break;
case V_44 :
V_35 = F_7 ( V_2 , V_23 -> V_25 , V_9 , V_36 ) ;
break;
default:
break;
}
if ( V_35 ) {
V_34 . V_45 = & V_2 -> V_46 ;
V_34 . V_47 . V_48 = 1 ;
V_34 . V_28 = V_49 ;
F_22 ( & V_34 ) ;
}
F_23 ( & V_2 -> V_42 ) ;
return V_50 ;
}
static enum V_51 F_24 ( struct V_52 * V_45 ,
T_1 V_48 )
{
return V_53 ;
}
static int F_25 ( struct V_1 * V_2 )
{
F_26 ( V_2 -> V_46 . V_54 , L_1 , V_55 ) ;
F_1 ( V_2 , ( T_1 * ) & V_2 -> V_46 . V_56 ) ;
memcpy ( V_2 -> V_46 . V_57 , V_58 ,
sizeof( V_58 ) ) ;
V_2 -> V_46 . V_59 = V_60 ;
V_2 -> V_46 . V_61 =
F_27 ( V_62 ) |
F_27 ( V_63 ) |
F_27 ( V_64 ) |
F_27 ( V_65 ) |
F_27 ( V_66 ) |
F_27 ( V_67 ) |
F_27 ( V_68 ) |
F_27 ( V_69 ) |
F_27 ( V_70 ) |
F_27 ( V_71 ) |
F_27 ( V_72 ) |
F_27 ( V_73 ) |
F_27 ( V_74 ) |
F_27 ( V_75 ) |
F_27 ( V_76 ) |
F_27 ( V_77 ) |
F_27 ( V_78 ) |
F_27 ( V_79 ) |
F_27 ( V_80 ) ;
V_2 -> V_46 . V_61 |=
F_27 ( V_81 ) |
F_27 ( V_82 ) |
F_27 ( V_83 ) |
F_27 ( V_84 ) ;
V_2 -> V_46 . V_85 = V_86 ;
V_2 -> V_46 . V_87 = 1 ;
V_2 -> V_46 . V_88 = 1 ;
V_2 -> V_46 . V_89 = V_90 ;
V_2 -> V_46 . V_91 = V_92 ;
V_2 -> V_46 . V_93 = V_94 ;
V_2 -> V_46 . V_95 = V_96 ;
V_2 -> V_46 . V_97 = F_24 ;
V_2 -> V_46 . V_98 = V_99 ;
V_2 -> V_46 . V_100 = V_101 ;
V_2 -> V_46 . V_102 = V_103 ;
V_2 -> V_46 . V_104 = V_105 ;
V_2 -> V_46 . V_106 = V_107 ;
V_2 -> V_46 . V_108 = V_109 ;
V_2 -> V_46 . V_110 = V_111 ;
V_2 -> V_46 . V_112 = V_113 ;
V_2 -> V_46 . V_114 = V_115 ;
V_2 -> V_46 . V_116 = V_117 ;
V_2 -> V_46 . V_118 = V_119 ;
V_2 -> V_46 . V_120 = V_121 ;
V_2 -> V_46 . V_122 = V_123 ;
V_2 -> V_46 . V_124 = V_125 ;
V_2 -> V_46 . V_126 = V_127 ;
V_2 -> V_46 . V_128 = V_129 ;
V_2 -> V_46 . V_130 = V_131 ;
V_2 -> V_46 . V_132 = V_133 ;
V_2 -> V_46 . V_134 = V_135 ;
V_2 -> V_46 . V_136 = V_137 ;
V_2 -> V_46 . V_138 = V_139 ;
V_2 -> V_46 . V_140 = V_141 ;
V_2 -> V_46 . V_142 = V_143 ;
V_2 -> V_46 . V_144 = V_145 ;
V_2 -> V_46 . V_146 = & V_2 -> V_5 . V_147 -> V_2 ;
V_2 -> V_46 . V_148 = V_149 ;
if ( V_2 -> V_5 . V_150 == V_151 ) {
V_2 -> V_46 . V_61 |=
F_27 ( V_152 ) |
F_27 ( V_153 ) |
F_27 ( V_154 ) |
F_27 ( V_155 ) |
F_27 ( V_156 ) ;
V_2 -> V_46 . V_157 = V_158 ;
V_2 -> V_46 . V_159 = V_160 ;
V_2 -> V_46 . V_161 = V_162 ;
V_2 -> V_46 . V_163 = V_164 ;
V_2 -> V_46 . V_165 = V_166 ;
}
return F_28 ( & V_2 -> V_46 , NULL ) ;
}
static int F_29 ( struct V_1 * V_2 )
{
F_30 ( & V_2 -> V_42 ) ;
V_2 -> V_20 = F_31 ( sizeof( union V_7 ) *
V_19 , V_167 ) ;
if ( ! V_2 -> V_20 )
goto V_168;
F_32 ( & V_2 -> V_18 ) ;
V_2 -> V_169 = F_31 ( sizeof( struct V_170 * ) *
V_171 , V_167 ) ;
if ( ! V_2 -> V_169 )
goto V_168;
if ( V_2 -> V_172 . V_173 ) {
V_2 -> V_174 = F_31 ( sizeof( struct V_175 * ) *
V_176 , V_167 ) ;
if ( ! V_2 -> V_174 )
goto V_168;
}
F_32 ( & V_2 -> V_177 . V_178 ) ;
F_32 ( & V_2 -> V_179 ) ;
return 0 ;
V_168:
F_33 ( L_2 , V_180 , V_2 -> V_181 ) ;
return - V_182 ;
}
static void F_34 ( struct V_1 * V_2 )
{
F_35 ( V_2 -> V_174 ) ;
F_35 ( V_2 -> V_169 ) ;
F_35 ( V_2 -> V_20 ) ;
}
static struct V_1 * F_36 ( struct V_183 * V_184 )
{
int V_185 = 0 ;
struct V_1 * V_2 ;
V_2 = (struct V_1 * ) F_37 ( sizeof( struct V_1 ) ) ;
if ( ! V_2 ) {
F_33 ( L_3 ) ;
return NULL ;
}
V_2 -> V_186 = F_31 ( sizeof( struct V_187 ) , V_167 ) ;
if ( ! V_2 -> V_186 )
goto V_188;
memcpy ( & V_2 -> V_5 , V_184 , sizeof( * V_184 ) ) ;
V_2 -> V_181 = F_38 ( & V_189 , NULL , 0 , 0 , V_167 ) ;
if ( V_2 -> V_181 < 0 )
goto V_188;
V_185 = F_39 ( V_2 ) ;
if ( V_185 )
goto V_190;
V_185 = F_29 ( V_2 ) ;
if ( V_185 )
goto V_168;
V_185 = F_17 ( V_2 ) ;
if ( V_185 )
goto V_168;
V_185 = F_25 ( V_2 ) ;
if ( V_185 )
goto V_168;
F_40 ( & V_191 ) ;
F_41 ( & V_2 -> V_192 , & V_193 ) ;
F_42 ( & V_191 ) ;
return V_2 ;
V_168:
F_34 ( V_2 ) ;
F_43 ( V_2 ) ;
V_190:
F_44 ( & V_189 , V_2 -> V_181 ) ;
V_188:
F_35 ( V_2 -> V_186 ) ;
F_45 ( & V_2 -> V_46 ) ;
F_33 ( L_4 , V_180 , V_185 ) ;
return NULL ;
}
static void F_46 ( struct V_194 * V_195 )
{
struct V_1 * V_2 = F_47 ( V_195 , struct V_1 , V_195 ) ;
F_34 ( V_2 ) ;
F_43 ( V_2 ) ;
F_44 ( & V_189 , V_2 -> V_181 ) ;
F_35 ( V_2 -> V_186 ) ;
F_45 ( & V_2 -> V_46 ) ;
}
static void F_48 ( struct V_1 * V_2 )
{
F_49 ( & V_2 -> V_46 ) ;
F_40 ( & V_191 ) ;
F_50 ( & V_2 -> V_192 ) ;
F_42 ( & V_191 ) ;
F_51 ( & V_2 -> V_195 , F_46 ) ;
}
static int F_52 ( struct V_1 * V_2 )
{
struct V_33 V_196 ;
V_196 . V_28 = V_197 ;
V_196 . V_47 . V_48 = 1 ;
V_196 . V_45 = & V_2 -> V_46 ;
F_22 ( & V_196 ) ;
return 0 ;
}
static int F_53 ( struct V_1 * V_2 )
{
int V_14 ;
struct V_175 * V_198 , * * V_199 ;
struct V_33 V_200 ;
struct V_201 V_202 ;
int V_203 = V_204 ;
V_202 . V_205 = V_206 ;
F_21 ( & V_2 -> V_42 ) ;
if ( V_2 -> V_174 ) {
V_199 = V_2 -> V_174 ;
for ( V_14 = 0 ; V_14 < V_176 ; V_14 ++ ) {
V_198 = V_199 [ V_14 ] ;
if ( V_198 ) {
F_54 ( & V_198 -> V_207 , & V_202 , V_203 ) ;
V_200 . V_28 = V_208 ;
V_200 . V_47 . V_198 = & V_198 -> V_207 ;
V_200 . V_45 = & V_2 -> V_46 ;
F_22 ( & V_200 ) ;
}
}
}
F_23 ( & V_2 -> V_42 ) ;
V_200 . V_28 = V_209 ;
V_200 . V_47 . V_48 = 1 ;
V_200 . V_45 = & V_2 -> V_46 ;
F_22 ( & V_200 ) ;
return 0 ;
}
static void F_55 ( struct V_1 * V_2 , T_3 V_28 )
{
switch ( V_28 ) {
case V_210 :
F_52 ( V_2 ) ;
break;
case V_211 :
F_53 ( V_2 ) ;
break;
} ;
}
static void F_56 ( void )
{
#if F_57 ( V_212 )
F_58 ( & V_213 ) ;
#endif
}
static int T_4 F_59 ( void )
{
int V_185 ;
#if F_57 ( V_212 )
V_185 = F_60 ( & V_213 ) ;
if ( V_185 )
return V_185 ;
#endif
V_185 = F_61 ( & V_214 ) ;
if ( V_185 )
F_56 () ;
return V_185 ;
}
static void T_5 F_62 ( void )
{
F_63 ( & V_214 ) ;
F_56 () ;
}
