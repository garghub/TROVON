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
static int F_7 ( struct V_1 * V_2 )
{
F_8 ( V_2 -> V_12 . V_25 , L_1 , V_26 ) ;
F_1 ( V_2 , ( T_1 * ) & V_2 -> V_12 . V_27 ) ;
memcpy ( V_2 -> V_12 . V_28 , V_29 ,
sizeof( V_29 ) ) ;
V_2 -> V_12 . V_30 = V_31 ;
V_2 -> V_12 . V_32 = V_33 ;
V_2 -> V_12 . V_34 =
F_9 ( V_35 ) |
F_9 ( V_36 ) |
F_9 ( V_37 ) |
F_9 ( V_38 ) |
F_9 ( V_39 ) |
F_9 ( V_40 ) |
F_9 ( V_41 ) |
F_9 ( V_42 ) |
F_9 ( V_43 ) |
F_9 ( V_44 ) |
F_9 ( V_45 ) |
F_9 ( V_46 ) |
F_9 ( V_47 ) |
F_9 ( V_48 ) |
F_9 ( V_49 ) |
F_9 ( V_50 ) |
F_9 ( V_51 ) |
F_9 ( V_52 ) |
F_9 ( V_53 ) ;
V_2 -> V_12 . V_34 |=
F_9 ( V_54 ) |
F_9 ( V_55 ) |
F_9 ( V_56 ) |
F_9 ( V_57 ) ;
V_2 -> V_12 . V_58 = V_59 ;
V_2 -> V_12 . V_60 = 1 ;
V_2 -> V_12 . V_61 = V_2 -> V_62 ;
V_2 -> V_12 . V_63 = V_64 ;
V_2 -> V_12 . V_65 = F_5 ;
V_2 -> V_12 . V_66 = V_67 ;
V_2 -> V_12 . V_68 = V_69 ;
V_2 -> V_12 . V_70 = V_71 ;
V_2 -> V_12 . V_72 = V_73 ;
V_2 -> V_12 . V_74 = V_75 ;
V_2 -> V_12 . V_76 = F_2 ;
V_2 -> V_12 . V_77 = V_78 ;
V_2 -> V_12 . V_79 = V_80 ;
V_2 -> V_12 . V_81 = V_82 ;
V_2 -> V_12 . V_83 = V_84 ;
V_2 -> V_12 . V_85 = V_86 ;
V_2 -> V_12 . V_87 = V_88 ;
V_2 -> V_12 . V_89 = V_90 ;
V_2 -> V_12 . V_91 = V_92 ;
V_2 -> V_12 . V_93 = V_94 ;
V_2 -> V_12 . V_95 = V_96 ;
V_2 -> V_12 . V_97 = V_98 ;
V_2 -> V_12 . V_99 = V_100 ;
V_2 -> V_12 . V_101 = V_102 ;
V_2 -> V_12 . V_103 = V_104 ;
V_2 -> V_12 . V_105 = V_106 ;
V_2 -> V_12 . V_107 = V_108 ;
V_2 -> V_12 . V_109 = V_110 ;
V_2 -> V_12 . V_111 = V_112 ;
V_2 -> V_12 . V_113 = V_114 ;
V_2 -> V_12 . V_115 = V_116 ;
V_2 -> V_12 . V_117 = V_118 ;
V_2 -> V_12 . V_119 = V_120 ;
V_2 -> V_12 . V_121 = V_122 ;
V_2 -> V_12 . V_123 = V_124 ;
V_2 -> V_12 . V_125 = V_126 ;
V_2 -> V_12 . V_127 = V_128 ;
V_2 -> V_12 . V_129 = & V_2 -> V_5 . V_130 -> V_2 ;
V_2 -> V_12 . V_131 = V_132 ;
V_2 -> V_12 . V_133 = F_3 ;
if ( F_10 ( V_2 ) == V_134 ) {
V_2 -> V_12 . V_34 |=
F_9 ( V_135 ) |
F_9 ( V_136 ) |
F_9 ( V_137 ) |
F_9 ( V_138 ) |
F_9 ( V_139 ) ;
V_2 -> V_12 . V_140 = V_141 ;
V_2 -> V_12 . V_142 = V_143 ;
V_2 -> V_12 . V_144 = V_145 ;
V_2 -> V_12 . V_146 = V_147 ;
V_2 -> V_12 . V_148 = V_149 ;
}
return F_11 ( & V_2 -> V_12 , NULL ) ;
}
static int F_12 ( struct V_1 * V_2 )
{
F_13 ( & V_2 -> V_150 ) ;
V_2 -> V_151 = F_14 ( sizeof( struct V_152 * ) *
V_153 , V_154 ) ;
if ( ! V_2 -> V_151 )
goto V_155;
if ( V_2 -> V_16 . V_156 ) {
V_2 -> V_157 = F_14 ( sizeof( struct V_158 * ) *
V_159 , V_154 ) ;
if ( ! V_2 -> V_157 )
goto V_155;
}
V_2 -> V_160 = F_14 ( sizeof( V_161 ) * V_162 , V_154 ) ;
if ( V_2 -> V_160 == NULL )
goto V_155;
F_15 ( V_2 ) ;
if ( ! F_16 ( V_2 ) ) {
F_17 ( L_2 , V_163 ) ;
goto V_155;
}
F_18 ( & V_2 -> V_164 . V_165 ) ;
F_18 ( & V_2 -> V_166 ) ;
return 0 ;
V_155:
F_17 ( L_3 , V_163 , V_2 -> V_167 ) ;
return - V_168 ;
}
static void F_19 ( struct V_1 * V_2 )
{
F_20 ( V_2 ) ;
F_21 ( V_2 -> V_160 ) ;
F_21 ( V_2 -> V_157 ) ;
F_21 ( V_2 -> V_151 ) ;
}
static T_2 F_22 ( struct V_9 * V_9 , struct V_169 * V_16 ,
char * V_170 )
{
struct V_1 * V_2 = F_23 ( V_9 ) ;
return F_24 ( V_170 , V_171 , L_4 , V_2 -> V_5 . V_130 -> V_172 ) ;
}
static T_2 F_25 ( struct V_9 * V_9 , struct V_169 * V_16 ,
char * V_170 )
{
struct V_1 * V_2 = F_23 ( V_9 ) ;
return F_24 ( V_170 , V_171 , L_5 , & V_2 -> V_16 . V_173 [ 0 ] ) ;
}
static T_2 F_26 ( struct V_9 * V_9 ,
struct V_169 * V_16 , char * V_170 )
{
struct V_1 * V_2 = F_23 ( V_9 ) ;
return F_24 ( V_170 , V_171 , L_5 , & V_2 -> V_174 [ 0 ] ) ;
}
static void F_27 ( struct V_1 * V_2 )
{
int V_175 ;
for ( V_175 = 0 ; V_175 < F_28 ( V_176 ) ; V_175 ++ )
F_29 ( & V_2 -> V_12 . V_2 , V_176 [ V_175 ] ) ;
}
static struct V_1 * F_30 ( struct V_177 * V_178 )
{
int V_179 = 0 , V_175 ;
T_1 V_180 = 0 ;
struct V_1 * V_2 ;
V_2 = (struct V_1 * ) F_31 ( sizeof( struct V_1 ) ) ;
if ( ! V_2 ) {
F_17 ( L_6 ) ;
return NULL ;
}
V_2 -> V_181 = F_14 ( sizeof( struct V_182 ) , V_154 ) ;
if ( ! V_2 -> V_181 )
goto V_183;
memcpy ( & V_2 -> V_5 , V_178 , sizeof( * V_178 ) ) ;
V_2 -> V_167 = F_32 ( & V_184 , NULL , 0 , 0 , V_154 ) ;
if ( V_2 -> V_167 < 0 )
goto V_183;
V_179 = F_33 ( V_2 ) ;
if ( V_179 )
goto V_185;
V_179 = F_12 ( V_2 ) ;
if ( V_179 )
goto V_155;
F_34 ( V_2 ) ;
V_179 = F_7 ( V_2 ) ;
if ( V_179 )
goto V_155;
V_179 = F_35 ( V_2 , NULL , & V_180 ) ;
if ( ! V_179 )
F_36 ( V_2 , V_180 ) ;
for ( V_175 = 0 ; V_175 < F_28 ( V_176 ) ; V_175 ++ )
if ( F_37 ( & V_2 -> V_12 . V_2 , V_176 [ V_175 ] ) )
goto V_186;
F_38 ( V_2 ) ;
F_39 ( & V_2 -> V_187 , V_188 ) ;
F_40 ( & V_2 -> V_187 , F_41 ( 1000 ) ) ;
F_42 ( L_7 ,
F_43 ( & V_2 -> V_5 . V_130 -> V_2 ) , F_44 ( V_2 ) ,
F_45 ( V_2 ) , V_2 -> V_174 ,
V_2 -> V_189 ) ;
F_42 ( L_8 ,
F_43 ( & V_2 -> V_5 . V_130 -> V_2 ) , V_2 -> V_167 ) ;
return V_2 ;
V_186:
F_27 ( V_2 ) ;
V_155:
F_19 ( V_2 ) ;
F_46 ( V_2 ) ;
V_185:
F_47 ( & V_184 , V_2 -> V_167 ) ;
V_183:
F_21 ( V_2 -> V_181 ) ;
F_48 ( & V_2 -> V_12 ) ;
F_17 ( L_9 , V_163 , V_179 ) ;
return NULL ;
}
static void F_49 ( struct V_1 * V_2 )
{
F_47 ( & V_184 , V_2 -> V_167 ) ;
F_21 ( V_2 -> V_181 ) ;
F_48 ( & V_2 -> V_12 ) ;
}
static void F_50 ( struct V_1 * V_2 )
{
F_51 ( & V_2 -> V_187 ) ;
F_27 ( V_2 ) ;
F_52 ( & V_2 -> V_12 ) ;
F_53 ( V_2 ) ;
F_19 ( V_2 ) ;
F_46 ( V_2 ) ;
F_49 ( V_2 ) ;
}
static int F_54 ( struct V_1 * V_2 )
{
struct V_190 V_191 ;
V_191 . V_192 = V_193 ;
V_191 . V_194 . V_10 = 1 ;
V_191 . V_9 = & V_2 -> V_12 ;
F_55 ( & V_191 ) ;
return 0 ;
}
static int F_56 ( struct V_1 * V_2 )
{
struct V_190 V_195 ;
V_195 . V_192 = V_196 ;
V_195 . V_194 . V_10 = 1 ;
V_195 . V_9 = & V_2 -> V_12 ;
F_55 ( & V_195 ) ;
return 0 ;
}
static void F_57 ( struct V_1 * V_2 )
{
F_56 ( V_2 ) ;
F_50 ( V_2 ) ;
}
static void F_58 ( struct V_1 * V_2 , T_3 V_192 )
{
switch ( V_192 ) {
case V_197 :
F_57 ( V_2 ) ;
break;
default:
break;
}
}
void F_36 ( struct V_1 * V_2 , T_1 V_180 )
{
if ( ! ( V_2 -> V_198 & V_199 ) ) {
V_2 -> V_198 |= V_199 ;
if ( ! V_180 )
return;
}
if ( ! V_180 )
F_56 ( V_2 ) ;
else
F_54 ( V_2 ) ;
}
static int T_4 F_59 ( void )
{
int V_179 ;
F_60 () ;
V_179 = F_61 ( & V_200 ) ;
if ( V_179 )
goto V_201;
return 0 ;
V_201:
return V_179 ;
}
static void T_5 F_62 ( void )
{
F_63 ( & V_200 ) ;
F_64 () ;
F_65 ( & V_184 ) ;
}
