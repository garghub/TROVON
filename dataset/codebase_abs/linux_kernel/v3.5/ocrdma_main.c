static int F_1 ( void )
{
int V_1 = 0 ;
if ( ! F_2 ( & V_2 , V_3 ) )
return - 1 ;
if ( F_3 ( & V_2 , NULL , & V_1 ) )
return - 1 ;
return V_1 ;
}
void F_4 ( struct V_4 * V_5 , T_1 * V_6 )
{
T_1 V_7 [ 6 ] ;
memcpy ( & V_7 [ 0 ] , & V_5 -> V_8 . V_7 [ 0 ] , V_9 ) ;
V_6 [ 0 ] = V_7 [ 0 ] ^ 2 ;
V_6 [ 1 ] = V_7 [ 1 ] ;
V_6 [ 2 ] = V_7 [ 2 ] ;
V_6 [ 3 ] = 0xff ;
V_6 [ 4 ] = 0xfe ;
V_6 [ 5 ] = V_7 [ 3 ] ;
V_6 [ 6 ] = V_7 [ 4 ] ;
V_6 [ 7 ] = V_7 [ 5 ] ;
}
static void F_5 ( union V_10 * V_11 , unsigned char * V_7 ,
bool V_12 , T_2 V_13 )
{
V_11 -> V_14 . V_15 = F_6 ( 0xfe80000000000000LL ) ;
V_11 -> V_16 [ 8 ] = V_7 [ 0 ] ^ 2 ;
V_11 -> V_16 [ 9 ] = V_7 [ 1 ] ;
V_11 -> V_16 [ 10 ] = V_7 [ 2 ] ;
if ( V_12 ) {
V_11 -> V_16 [ 11 ] = V_13 >> 8 ;
V_11 -> V_16 [ 12 ] = V_13 & 0xff ;
} else {
V_11 -> V_16 [ 11 ] = 0xff ;
V_11 -> V_16 [ 12 ] = 0xfe ;
}
V_11 -> V_16 [ 13 ] = V_7 [ 3 ] ;
V_11 -> V_16 [ 14 ] = V_7 [ 4 ] ;
V_11 -> V_16 [ 15 ] = V_7 [ 5 ] ;
}
static bool F_7 ( struct V_4 * V_5 , unsigned char * V_7 ,
bool V_12 , T_2 V_13 )
{
int V_17 ;
union V_10 V_18 ;
unsigned long V_19 ;
memset ( & V_20 , 0 , sizeof( union V_10 ) ) ;
F_5 ( & V_18 , V_7 , V_12 , V_13 ) ;
F_8 ( & V_5 -> V_21 , V_19 ) ;
for ( V_17 = 0 ; V_17 < V_22 ; V_17 ++ ) {
if ( ! memcmp ( & V_5 -> V_23 [ V_17 ] , & V_20 ,
sizeof( union V_10 ) ) ) {
memcpy ( & V_5 -> V_23 [ V_17 ] , & V_18 ,
sizeof( union V_10 ) ) ;
F_9 ( & V_5 -> V_21 , V_19 ) ;
return true ;
} else if ( ! memcmp ( & V_5 -> V_23 [ V_17 ] , & V_18 ,
sizeof( union V_10 ) ) ) {
F_9 ( & V_5 -> V_21 , V_19 ) ;
return false ;
}
}
F_9 ( & V_5 -> V_21 , V_19 ) ;
return false ;
}
static bool F_10 ( struct V_4 * V_5 , unsigned char * V_7 ,
bool V_12 , T_2 V_13 )
{
int V_24 = false ;
int V_17 ;
union V_10 V_11 ;
unsigned long V_19 ;
F_5 ( & V_11 , V_7 , V_12 , V_13 ) ;
F_8 ( & V_5 -> V_21 , V_19 ) ;
for ( V_17 = 1 ; V_17 < V_22 ; V_17 ++ ) {
if ( ! memcmp ( & V_5 -> V_23 [ V_17 ] , & V_11 , sizeof( union V_10 ) ) ) {
memset ( & V_5 -> V_23 [ V_17 ] , 0 , sizeof( union V_10 ) ) ;
V_24 = true ;
break;
}
}
F_9 ( & V_5 -> V_21 , V_19 ) ;
return V_24 ;
}
static void F_11 ( struct V_4 * V_5 )
{
union V_10 * V_11 = & V_5 -> V_23 [ 0 ] ;
V_11 -> V_14 . V_15 = F_6 ( 0xfe80000000000000LL ) ;
F_4 ( V_5 , & V_11 -> V_16 [ 8 ] ) ;
}
static void F_12 ( struct V_4 * V_5 )
{
struct V_25 * V_26 , * V_27 ;
T_2 V_13 ;
bool V_12 ;
V_26 = V_5 -> V_8 . V_26 ;
F_13 () ;
F_14 (&init_net, tmp) {
if ( V_26 == V_27 || F_15 ( V_27 ) == V_26 ) {
if ( ! F_16 ( V_27 ) || ! F_17 ( V_27 ) )
continue;
if ( V_26 != V_27 ) {
V_13 = F_18 ( V_27 ) ;
V_12 = true ;
} else {
V_12 = false ;
V_13 = 0 ;
V_27 = V_26 ;
}
F_7 ( V_5 , V_27 -> V_28 , V_12 , V_13 ) ;
}
}
F_19 () ;
}
static void F_12 ( struct V_4 * V_5 )
{
}
static int F_20 ( struct V_4 * V_5 )
{
F_11 ( V_5 ) ;
F_12 ( V_5 ) ;
return 0 ;
}
static int F_21 ( struct V_29 * V_30 ,
unsigned long V_31 , void * V_32 )
{
struct V_33 * V_34 = (struct V_33 * ) V_32 ;
struct V_25 * V_35 = V_34 -> V_36 -> V_5 ;
struct V_25 * V_26 = NULL ;
struct V_37 V_38 ;
struct V_4 * V_5 ;
bool V_24 = false ;
bool V_39 = false ;
bool V_12 = false ;
T_2 V_40 = 0 ;
V_26 = F_15 ( V_35 ) ;
if ( V_26 != V_35 ) {
V_12 = true ;
V_40 = F_18 ( V_35 ) ;
}
F_13 () ;
F_22 (dev, &ocrdma_dev_list, entry) {
if ( V_5 -> V_8 . V_26 == V_26 ) {
V_24 = true ;
break;
}
}
F_19 () ;
if ( ! V_24 )
return V_41 ;
if ( ! F_23 ( (struct V_42 * ) & V_34 -> V_43 ) )
return V_41 ;
F_24 ( & V_5 -> V_44 ) ;
switch ( V_31 ) {
case V_45 :
V_39 = F_7 ( V_5 , V_26 -> V_28 , V_12 , V_40 ) ;
break;
case V_46 :
V_39 = F_10 ( V_5 , V_26 -> V_28 , V_12 , V_40 ) ;
break;
default:
break;
}
if ( V_39 ) {
V_38 . V_47 = & V_5 -> V_48 ;
V_38 . V_49 . V_50 = 1 ;
V_38 . V_31 = V_51 ;
F_25 ( & V_38 ) ;
}
F_26 ( & V_5 -> V_44 ) ;
return V_52 ;
}
static enum V_53 F_27 ( struct V_54 * V_47 ,
T_1 V_50 )
{
return V_55 ;
}
static int F_28 ( struct V_4 * V_5 )
{
F_29 ( V_5 -> V_48 . V_56 , L_1 , V_57 ) ;
F_4 ( V_5 , ( T_1 * ) & V_5 -> V_48 . V_58 ) ;
memcpy ( V_5 -> V_48 . V_59 , V_60 ,
sizeof( V_60 ) ) ;
V_5 -> V_48 . V_61 = V_62 ;
V_5 -> V_48 . V_63 =
F_30 ( V_64 ) |
F_30 ( V_65 ) |
F_30 ( V_66 ) |
F_30 ( V_67 ) |
F_30 ( V_68 ) |
F_30 ( V_69 ) |
F_30 ( V_70 ) |
F_30 ( V_71 ) |
F_30 ( V_72 ) |
F_30 ( V_73 ) |
F_30 ( V_74 ) |
F_30 ( V_75 ) |
F_30 ( V_76 ) |
F_30 ( V_77 ) |
F_30 ( V_78 ) |
F_30 ( V_79 ) |
F_30 ( V_80 ) |
F_30 ( V_81 ) |
F_30 ( V_82 ) ;
V_5 -> V_48 . V_63 |=
F_30 ( V_83 ) |
F_30 ( V_84 ) |
F_30 ( V_85 ) |
F_30 ( V_86 ) ;
V_5 -> V_48 . V_87 = V_88 ;
V_5 -> V_48 . V_89 = 1 ;
V_5 -> V_48 . V_90 = 1 ;
V_5 -> V_48 . V_91 = V_92 ;
V_5 -> V_48 . V_93 = V_94 ;
V_5 -> V_48 . V_95 = V_96 ;
V_5 -> V_48 . V_97 = V_98 ;
V_5 -> V_48 . V_99 = F_27 ;
V_5 -> V_48 . V_100 = V_101 ;
V_5 -> V_48 . V_102 = V_103 ;
V_5 -> V_48 . V_104 = V_105 ;
V_5 -> V_48 . V_106 = V_107 ;
V_5 -> V_48 . V_108 = V_109 ;
V_5 -> V_48 . V_110 = V_111 ;
V_5 -> V_48 . V_112 = V_113 ;
V_5 -> V_48 . V_114 = V_115 ;
V_5 -> V_48 . V_116 = V_117 ;
V_5 -> V_48 . V_118 = V_119 ;
V_5 -> V_48 . V_120 = V_121 ;
V_5 -> V_48 . V_122 = V_123 ;
V_5 -> V_48 . V_124 = V_125 ;
V_5 -> V_48 . V_126 = V_127 ;
V_5 -> V_48 . V_128 = V_129 ;
V_5 -> V_48 . V_130 = V_131 ;
V_5 -> V_48 . V_132 = V_133 ;
V_5 -> V_48 . V_134 = V_135 ;
V_5 -> V_48 . V_136 = V_137 ;
V_5 -> V_48 . V_138 = V_139 ;
V_5 -> V_48 . V_140 = V_141 ;
V_5 -> V_48 . V_142 = V_143 ;
V_5 -> V_48 . V_144 = V_145 ;
V_5 -> V_48 . V_146 = V_147 ;
V_5 -> V_48 . V_148 = & V_5 -> V_8 . V_149 -> V_5 ;
V_5 -> V_48 . V_150 = V_151 ;
if ( V_5 -> V_8 . V_152 == V_153 ) {
V_5 -> V_48 . V_63 |=
F_30 ( V_154 ) |
F_30 ( V_155 ) |
F_30 ( V_156 ) |
F_30 ( V_157 ) |
F_30 ( V_158 ) ;
V_5 -> V_48 . V_159 = V_160 ;
V_5 -> V_48 . V_161 = V_162 ;
V_5 -> V_48 . V_163 = V_164 ;
V_5 -> V_48 . V_165 = V_166 ;
V_5 -> V_48 . V_167 = V_168 ;
}
return F_31 ( & V_5 -> V_48 , NULL ) ;
}
static int F_32 ( struct V_4 * V_5 )
{
F_33 ( & V_5 -> V_44 ) ;
V_5 -> V_23 = F_34 ( sizeof( union V_10 ) *
V_22 , V_3 ) ;
if ( ! V_5 -> V_23 )
goto V_169;
F_35 ( & V_5 -> V_21 ) ;
V_5 -> V_170 = F_34 ( sizeof( struct V_171 * ) *
V_172 , V_3 ) ;
if ( ! V_5 -> V_170 )
goto V_169;
if ( V_5 -> V_173 . V_174 ) {
V_5 -> V_175 = F_34 ( sizeof( struct V_176 * ) *
V_177 , V_3 ) ;
if ( ! V_5 -> V_175 )
goto V_169;
}
F_35 ( & V_5 -> V_178 . V_179 ) ;
F_35 ( & V_5 -> V_180 ) ;
return 0 ;
V_169:
F_36 ( L_2 , V_181 , V_5 -> V_182 ) ;
return - V_183 ;
}
static void F_37 ( struct V_4 * V_5 )
{
F_38 ( V_5 -> V_175 ) ;
F_38 ( V_5 -> V_170 ) ;
F_38 ( V_5 -> V_23 ) ;
}
static struct V_4 * F_39 ( struct V_184 * V_185 )
{
int V_186 = 0 ;
struct V_4 * V_5 ;
V_5 = (struct V_4 * ) F_40 ( sizeof( struct V_4 ) ) ;
if ( ! V_5 ) {
F_36 ( L_3 ) ;
return NULL ;
}
V_5 -> V_187 = F_34 ( sizeof( struct V_188 ) , V_3 ) ;
if ( ! V_5 -> V_187 )
goto V_189;
memcpy ( & V_5 -> V_8 , V_185 , sizeof( * V_185 ) ) ;
V_5 -> V_182 = F_1 () ;
if ( V_5 -> V_182 < 0 )
goto V_189;
V_186 = F_41 ( V_5 ) ;
if ( V_186 )
goto V_190;
V_186 = F_32 ( V_5 ) ;
if ( V_186 )
goto V_169;
V_186 = F_20 ( V_5 ) ;
if ( V_186 )
goto V_169;
V_186 = F_28 ( V_5 ) ;
if ( V_186 )
goto V_169;
F_42 ( & V_191 ) ;
F_43 ( & V_5 -> V_192 , & V_193 ) ;
F_44 ( & V_191 ) ;
return V_5 ;
V_169:
F_37 ( V_5 ) ;
F_45 ( V_5 ) ;
V_190:
F_46 ( & V_2 , V_5 -> V_182 ) ;
V_189:
F_38 ( V_5 -> V_187 ) ;
F_47 ( & V_5 -> V_48 ) ;
F_36 ( L_4 , V_181 , V_186 ) ;
return NULL ;
}
static void F_48 ( struct V_194 * V_195 )
{
struct V_4 * V_5 = F_49 ( V_195 , struct V_4 , V_195 ) ;
F_37 ( V_5 ) ;
F_45 ( V_5 ) ;
F_46 ( & V_2 , V_5 -> V_182 ) ;
F_38 ( V_5 -> V_187 ) ;
F_47 ( & V_5 -> V_48 ) ;
}
static void F_50 ( struct V_4 * V_5 )
{
F_51 ( & V_5 -> V_48 ) ;
F_42 ( & V_191 ) ;
F_52 ( & V_5 -> V_192 ) ;
F_44 ( & V_191 ) ;
F_53 ( & V_5 -> V_195 , F_48 ) ;
}
static int F_54 ( struct V_4 * V_5 )
{
struct V_37 V_196 ;
V_196 . V_31 = V_197 ;
V_196 . V_49 . V_50 = 1 ;
V_196 . V_47 = & V_5 -> V_48 ;
F_25 ( & V_196 ) ;
return 0 ;
}
static int F_55 ( struct V_4 * V_5 )
{
int V_17 ;
struct V_176 * V_198 , * * V_199 ;
struct V_37 V_200 ;
struct V_201 V_202 ;
int V_203 = V_204 ;
V_202 . V_205 = V_206 ;
F_24 ( & V_5 -> V_44 ) ;
if ( V_5 -> V_175 ) {
V_199 = V_5 -> V_175 ;
for ( V_17 = 0 ; V_17 < V_177 ; V_17 ++ ) {
V_198 = V_199 [ V_17 ] ;
if ( V_198 ) {
F_56 ( & V_198 -> V_207 , & V_202 , V_203 ) ;
V_200 . V_31 = V_208 ;
V_200 . V_49 . V_198 = & V_198 -> V_207 ;
V_200 . V_47 = & V_5 -> V_48 ;
F_25 ( & V_200 ) ;
}
}
}
F_26 ( & V_5 -> V_44 ) ;
V_200 . V_31 = V_209 ;
V_200 . V_49 . V_50 = 1 ;
V_200 . V_47 = & V_5 -> V_48 ;
F_25 ( & V_200 ) ;
return 0 ;
}
static void F_57 ( struct V_4 * V_5 , T_3 V_31 )
{
switch ( V_31 ) {
case V_210 :
F_54 ( V_5 ) ;
break;
case V_211 :
F_55 ( V_5 ) ;
break;
} ;
}
static void F_58 ( void )
{
#if F_59 ( V_212 ) || F_59 ( V_213 )
F_60 ( & V_214 ) ;
#endif
}
static int T_4 F_61 ( void )
{
int V_186 ;
#if F_59 ( V_212 ) || F_59 ( V_213 )
V_186 = F_62 ( & V_214 ) ;
if ( V_186 )
return V_186 ;
#endif
V_186 = F_63 ( & V_215 ) ;
if ( V_186 )
F_58 () ;
return V_186 ;
}
static void T_5 F_64 ( void )
{
F_65 ( & V_215 ) ;
F_58 () ;
}
