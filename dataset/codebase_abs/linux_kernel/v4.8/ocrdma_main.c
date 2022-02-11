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
static enum V_7 F_2 ( struct V_8 * V_9 ,
T_1 V_10 )
{
return V_11 ;
}
static int F_3 ( struct V_8 * V_12 , T_1 V_10 ,
struct V_13 * V_14 )
{
struct V_15 V_16 ;
struct V_1 * V_2 ;
int V_17 ;
V_2 = F_4 ( V_12 ) ;
V_17 = F_5 ( V_12 , V_10 , & V_16 ) ;
if ( V_17 )
return V_17 ;
V_14 -> V_18 = V_16 . V_18 ;
V_14 -> V_19 = V_16 . V_19 ;
V_14 -> V_20 = V_21 ;
if ( F_6 ( V_2 ) )
V_14 -> V_20 |= V_22 ;
V_14 -> V_23 = V_24 ;
return 0 ;
}
static void F_7 ( struct V_8 * V_9 , char * V_25 ,
T_2 V_26 )
{
struct V_1 * V_2 = F_4 ( V_9 ) ;
snprintf ( V_25 , V_26 , L_1 , & V_2 -> V_16 . V_27 [ 0 ] ) ;
}
static int F_8 ( struct V_1 * V_2 )
{
F_9 ( V_2 -> V_12 . V_28 , L_2 , V_29 ) ;
F_1 ( V_2 , ( T_1 * ) & V_2 -> V_12 . V_30 ) ;
memcpy ( V_2 -> V_12 . V_31 , V_32 ,
sizeof( V_32 ) ) ;
V_2 -> V_12 . V_33 = V_34 ;
V_2 -> V_12 . V_35 = V_36 ;
V_2 -> V_12 . V_37 =
F_10 ( V_38 ) |
F_10 ( V_39 ) |
F_10 ( V_40 ) |
F_10 ( V_41 ) |
F_10 ( V_42 ) |
F_10 ( V_43 ) |
F_10 ( V_44 ) |
F_10 ( V_45 ) |
F_10 ( V_46 ) |
F_10 ( V_47 ) |
F_10 ( V_48 ) |
F_10 ( V_49 ) |
F_10 ( V_50 ) |
F_10 ( V_51 ) |
F_10 ( V_52 ) |
F_10 ( V_53 ) |
F_10 ( V_54 ) |
F_10 ( V_55 ) |
F_10 ( V_56 ) ;
V_2 -> V_12 . V_37 |=
F_10 ( V_57 ) |
F_10 ( V_58 ) |
F_10 ( V_59 ) |
F_10 ( V_60 ) ;
V_2 -> V_12 . V_61 = V_62 ;
V_2 -> V_12 . V_63 = 1 ;
V_2 -> V_12 . V_64 = V_2 -> V_65 ;
V_2 -> V_12 . V_66 = V_67 ;
V_2 -> V_12 . V_68 = F_5 ;
V_2 -> V_12 . V_69 = V_70 ;
V_2 -> V_12 . V_71 = V_72 ;
V_2 -> V_12 . V_73 = V_74 ;
V_2 -> V_12 . V_75 = V_76 ;
V_2 -> V_12 . V_77 = V_78 ;
V_2 -> V_12 . V_79 = F_2 ;
V_2 -> V_12 . V_80 = V_81 ;
V_2 -> V_12 . V_82 = V_83 ;
V_2 -> V_12 . V_84 = V_85 ;
V_2 -> V_12 . V_86 = V_87 ;
V_2 -> V_12 . V_88 = V_89 ;
V_2 -> V_12 . V_90 = V_91 ;
V_2 -> V_12 . V_92 = V_93 ;
V_2 -> V_12 . V_94 = V_95 ;
V_2 -> V_12 . V_96 = V_97 ;
V_2 -> V_12 . V_98 = V_99 ;
V_2 -> V_12 . V_100 = V_101 ;
V_2 -> V_12 . V_102 = V_103 ;
V_2 -> V_12 . V_104 = V_105 ;
V_2 -> V_12 . V_106 = V_107 ;
V_2 -> V_12 . V_108 = V_109 ;
V_2 -> V_12 . V_110 = V_111 ;
V_2 -> V_12 . V_112 = V_113 ;
V_2 -> V_12 . V_114 = V_115 ;
V_2 -> V_12 . V_116 = V_117 ;
V_2 -> V_12 . V_118 = V_119 ;
V_2 -> V_12 . V_120 = V_121 ;
V_2 -> V_12 . V_122 = V_123 ;
V_2 -> V_12 . V_124 = V_125 ;
V_2 -> V_12 . V_126 = V_127 ;
V_2 -> V_12 . V_128 = V_129 ;
V_2 -> V_12 . V_130 = V_131 ;
V_2 -> V_12 . V_132 = & V_2 -> V_5 . V_133 -> V_2 ;
V_2 -> V_12 . V_134 = V_135 ;
V_2 -> V_12 . V_136 = F_3 ;
V_2 -> V_12 . F_7 = F_7 ;
if ( F_11 ( V_2 ) == V_137 ) {
V_2 -> V_12 . V_37 |=
F_10 ( V_138 ) |
F_10 ( V_139 ) |
F_10 ( V_140 ) |
F_10 ( V_141 ) |
F_10 ( V_142 ) ;
V_2 -> V_12 . V_143 = V_144 ;
V_2 -> V_12 . V_145 = V_146 ;
V_2 -> V_12 . V_147 = V_148 ;
V_2 -> V_12 . V_149 = V_150 ;
V_2 -> V_12 . V_151 = V_152 ;
}
return F_12 ( & V_2 -> V_12 , NULL ) ;
}
static int F_13 ( struct V_1 * V_2 )
{
F_14 ( & V_2 -> V_153 ) ;
V_2 -> V_154 = F_15 ( sizeof( struct V_155 * ) *
V_156 , V_157 ) ;
if ( ! V_2 -> V_154 )
goto V_158;
if ( V_2 -> V_16 . V_159 ) {
V_2 -> V_160 = F_15 ( sizeof( struct V_161 * ) *
V_162 , V_157 ) ;
if ( ! V_2 -> V_160 )
goto V_158;
}
V_2 -> V_163 = F_15 ( sizeof( V_164 ) * V_165 , V_157 ) ;
if ( V_2 -> V_163 == NULL )
goto V_158;
F_16 ( V_2 ) ;
if ( ! F_17 ( V_2 ) ) {
F_18 ( L_3 , V_166 ) ;
goto V_158;
}
F_19 ( & V_2 -> V_167 . V_168 ) ;
F_19 ( & V_2 -> V_169 ) ;
return 0 ;
V_158:
F_18 ( L_4 , V_166 , V_2 -> V_170 ) ;
return - V_171 ;
}
static void F_20 ( struct V_1 * V_2 )
{
F_21 ( V_2 ) ;
F_22 ( V_2 -> V_163 ) ;
F_22 ( V_2 -> V_160 ) ;
F_22 ( V_2 -> V_154 ) ;
}
static T_3 F_23 ( struct V_9 * V_9 , struct V_172 * V_16 ,
char * V_173 )
{
struct V_1 * V_2 = F_24 ( V_9 ) ;
return F_25 ( V_173 , V_174 , L_5 , V_2 -> V_5 . V_133 -> V_175 ) ;
}
static T_3 F_26 ( struct V_9 * V_9 ,
struct V_172 * V_16 , char * V_173 )
{
struct V_1 * V_2 = F_24 ( V_9 ) ;
return F_25 ( V_173 , V_174 , L_6 , & V_2 -> V_176 [ 0 ] ) ;
}
static void F_27 ( struct V_1 * V_2 )
{
int V_177 ;
for ( V_177 = 0 ; V_177 < F_28 ( V_178 ) ; V_177 ++ )
F_29 ( & V_2 -> V_12 . V_2 , V_178 [ V_177 ] ) ;
}
static struct V_1 * F_30 ( struct V_179 * V_180 )
{
int V_181 = 0 , V_177 ;
T_1 V_182 = 0 ;
struct V_1 * V_2 ;
V_2 = (struct V_1 * ) F_31 ( sizeof( struct V_1 ) ) ;
if ( ! V_2 ) {
F_18 ( L_7 ) ;
return NULL ;
}
V_2 -> V_183 = F_15 ( sizeof( struct V_184 ) , V_157 ) ;
if ( ! V_2 -> V_183 )
goto V_185;
memcpy ( & V_2 -> V_5 , V_180 , sizeof( * V_180 ) ) ;
V_2 -> V_170 = F_32 ( & V_186 , NULL , 0 , 0 , V_157 ) ;
if ( V_2 -> V_170 < 0 )
goto V_185;
V_181 = F_33 ( V_2 ) ;
if ( V_181 )
goto V_187;
V_181 = F_13 ( V_2 ) ;
if ( V_181 )
goto V_158;
F_34 ( V_2 ) ;
V_181 = F_8 ( V_2 ) ;
if ( V_181 )
goto V_158;
V_181 = F_35 ( V_2 , NULL , & V_182 ) ;
if ( ! V_181 )
F_36 ( V_2 , V_182 ) ;
for ( V_177 = 0 ; V_177 < F_28 ( V_178 ) ; V_177 ++ )
if ( F_37 ( & V_2 -> V_12 . V_2 , V_178 [ V_177 ] ) )
goto V_188;
F_38 ( V_2 ) ;
F_39 ( & V_2 -> V_189 , V_190 ) ;
F_40 ( & V_2 -> V_189 , F_41 ( 1000 ) ) ;
F_42 ( L_8 ,
F_43 ( & V_2 -> V_5 . V_133 -> V_2 ) , F_44 ( V_2 ) ,
F_45 ( V_2 ) , V_2 -> V_176 ,
V_2 -> V_191 ) ;
F_42 ( L_9 ,
F_43 ( & V_2 -> V_5 . V_133 -> V_2 ) , V_2 -> V_170 ) ;
return V_2 ;
V_188:
F_27 ( V_2 ) ;
V_158:
F_20 ( V_2 ) ;
F_46 ( V_2 ) ;
V_187:
F_47 ( & V_186 , V_2 -> V_170 ) ;
V_185:
F_22 ( V_2 -> V_183 ) ;
F_48 ( & V_2 -> V_12 ) ;
F_18 ( L_10 , V_166 , V_181 ) ;
return NULL ;
}
static void F_49 ( struct V_1 * V_2 )
{
F_47 ( & V_186 , V_2 -> V_170 ) ;
F_22 ( V_2 -> V_183 ) ;
F_48 ( & V_2 -> V_12 ) ;
}
static void F_50 ( struct V_1 * V_2 )
{
F_51 ( & V_2 -> V_189 ) ;
F_27 ( V_2 ) ;
F_52 ( & V_2 -> V_12 ) ;
F_53 ( V_2 ) ;
F_20 ( V_2 ) ;
F_46 ( V_2 ) ;
F_49 ( V_2 ) ;
}
static int F_54 ( struct V_1 * V_2 )
{
struct V_192 V_193 ;
V_193 . V_194 = V_195 ;
V_193 . V_196 . V_10 = 1 ;
V_193 . V_9 = & V_2 -> V_12 ;
F_55 ( & V_193 ) ;
return 0 ;
}
static int F_56 ( struct V_1 * V_2 )
{
struct V_192 V_197 ;
V_197 . V_194 = V_198 ;
V_197 . V_196 . V_10 = 1 ;
V_197 . V_9 = & V_2 -> V_12 ;
F_55 ( & V_197 ) ;
return 0 ;
}
static void F_57 ( struct V_1 * V_2 )
{
F_56 ( V_2 ) ;
F_50 ( V_2 ) ;
}
static void F_58 ( struct V_1 * V_2 , T_4 V_194 )
{
switch ( V_194 ) {
case V_199 :
F_57 ( V_2 ) ;
break;
default:
break;
}
}
void F_36 ( struct V_1 * V_2 , T_1 V_182 )
{
if ( ! ( V_2 -> V_200 & V_201 ) ) {
V_2 -> V_200 |= V_201 ;
if ( ! V_182 )
return;
}
if ( ! V_182 )
F_56 ( V_2 ) ;
else
F_54 ( V_2 ) ;
}
static int T_5 F_59 ( void )
{
int V_181 ;
F_60 () ;
V_181 = F_61 ( & V_202 ) ;
if ( V_181 )
goto V_203;
return 0 ;
V_203:
return V_181 ;
}
static void T_6 F_62 ( void )
{
F_63 ( & V_202 ) ;
F_64 () ;
F_65 ( & V_186 ) ;
}
