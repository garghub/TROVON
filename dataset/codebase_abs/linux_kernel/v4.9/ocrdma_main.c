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
F_10 ( sizeof( V_31 ) > V_32 ) ;
memcpy ( V_2 -> V_12 . V_33 , V_31 ,
sizeof( V_31 ) ) ;
V_2 -> V_12 . V_34 = V_35 ;
V_2 -> V_12 . V_36 = V_37 ;
V_2 -> V_12 . V_38 =
F_11 ( V_39 ) |
F_11 ( V_40 ) |
F_11 ( V_41 ) |
F_11 ( V_42 ) |
F_11 ( V_43 ) |
F_11 ( V_44 ) |
F_11 ( V_45 ) |
F_11 ( V_46 ) |
F_11 ( V_47 ) |
F_11 ( V_48 ) |
F_11 ( V_49 ) |
F_11 ( V_50 ) |
F_11 ( V_51 ) |
F_11 ( V_52 ) |
F_11 ( V_53 ) |
F_11 ( V_54 ) |
F_11 ( V_55 ) |
F_11 ( V_56 ) |
F_11 ( V_57 ) ;
V_2 -> V_12 . V_38 |=
F_11 ( V_58 ) |
F_11 ( V_59 ) |
F_11 ( V_60 ) |
F_11 ( V_61 ) ;
V_2 -> V_12 . V_62 = V_63 ;
V_2 -> V_12 . V_64 = 1 ;
V_2 -> V_12 . V_65 = V_2 -> V_66 ;
V_2 -> V_12 . V_67 = V_68 ;
V_2 -> V_12 . V_69 = F_5 ;
V_2 -> V_12 . V_70 = V_71 ;
V_2 -> V_12 . V_72 = V_73 ;
V_2 -> V_12 . V_74 = V_75 ;
V_2 -> V_12 . V_76 = V_77 ;
V_2 -> V_12 . V_78 = V_79 ;
V_2 -> V_12 . V_80 = F_2 ;
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
V_2 -> V_12 . V_129 = V_130 ;
V_2 -> V_12 . V_131 = V_132 ;
V_2 -> V_12 . V_133 = & V_2 -> V_5 . V_134 -> V_2 ;
V_2 -> V_12 . V_135 = V_136 ;
V_2 -> V_12 . V_137 = F_3 ;
V_2 -> V_12 . F_7 = F_7 ;
if ( F_12 ( V_2 ) == V_138 ) {
V_2 -> V_12 . V_38 |=
F_11 ( V_139 ) |
F_11 ( V_140 ) |
F_11 ( V_141 ) |
F_11 ( V_142 ) |
F_11 ( V_143 ) ;
V_2 -> V_12 . V_144 = V_145 ;
V_2 -> V_12 . V_146 = V_147 ;
V_2 -> V_12 . V_148 = V_149 ;
V_2 -> V_12 . V_150 = V_151 ;
V_2 -> V_12 . V_152 = V_153 ;
}
return F_13 ( & V_2 -> V_12 , NULL ) ;
}
static int F_14 ( struct V_1 * V_2 )
{
F_15 ( & V_2 -> V_154 ) ;
V_2 -> V_155 = F_16 ( sizeof( struct V_156 * ) *
V_157 , V_158 ) ;
if ( ! V_2 -> V_155 )
goto V_159;
if ( V_2 -> V_16 . V_160 ) {
V_2 -> V_161 = F_16 ( sizeof( struct V_162 * ) *
V_163 , V_158 ) ;
if ( ! V_2 -> V_161 )
goto V_159;
}
V_2 -> V_164 = F_16 ( sizeof( V_165 ) * V_166 , V_158 ) ;
if ( V_2 -> V_164 == NULL )
goto V_159;
F_17 ( V_2 ) ;
if ( ! F_18 ( V_2 ) ) {
F_19 ( L_3 , V_167 ) ;
goto V_159;
}
F_20 ( & V_2 -> V_168 . V_169 ) ;
F_20 ( & V_2 -> V_170 ) ;
return 0 ;
V_159:
F_19 ( L_4 , V_167 , V_2 -> V_171 ) ;
return - V_172 ;
}
static void F_21 ( struct V_1 * V_2 )
{
F_22 ( V_2 ) ;
F_23 ( V_2 -> V_164 ) ;
F_23 ( V_2 -> V_161 ) ;
F_23 ( V_2 -> V_155 ) ;
}
static T_3 F_24 ( struct V_9 * V_9 , struct V_173 * V_16 ,
char * V_174 )
{
struct V_1 * V_2 = F_25 ( V_9 ) ;
return F_26 ( V_174 , V_175 , L_5 , V_2 -> V_5 . V_134 -> V_176 ) ;
}
static T_3 F_27 ( struct V_9 * V_9 ,
struct V_173 * V_16 , char * V_174 )
{
struct V_1 * V_2 = F_25 ( V_9 ) ;
return F_26 ( V_174 , V_175 , L_6 , & V_2 -> V_177 [ 0 ] ) ;
}
static void F_28 ( struct V_1 * V_2 )
{
int V_178 ;
for ( V_178 = 0 ; V_178 < F_29 ( V_179 ) ; V_178 ++ )
F_30 ( & V_2 -> V_12 . V_2 , V_179 [ V_178 ] ) ;
}
static struct V_1 * F_31 ( struct V_180 * V_181 )
{
int V_182 = 0 , V_178 ;
T_1 V_183 = 0 ;
struct V_1 * V_2 ;
V_2 = (struct V_1 * ) F_32 ( sizeof( struct V_1 ) ) ;
if ( ! V_2 ) {
F_19 ( L_7 ) ;
return NULL ;
}
V_2 -> V_184 = F_16 ( sizeof( struct V_185 ) , V_158 ) ;
if ( ! V_2 -> V_184 )
goto V_186;
memcpy ( & V_2 -> V_5 , V_181 , sizeof( * V_181 ) ) ;
V_2 -> V_171 = F_33 ( & V_187 , NULL , 0 , 0 , V_158 ) ;
if ( V_2 -> V_171 < 0 )
goto V_186;
V_182 = F_34 ( V_2 ) ;
if ( V_182 )
goto V_188;
V_182 = F_14 ( V_2 ) ;
if ( V_182 )
goto V_159;
F_35 ( V_2 ) ;
V_182 = F_8 ( V_2 ) ;
if ( V_182 )
goto V_159;
V_182 = F_36 ( V_2 , NULL , & V_183 ) ;
if ( ! V_182 )
F_37 ( V_2 , V_183 ) ;
for ( V_178 = 0 ; V_178 < F_29 ( V_179 ) ; V_178 ++ )
if ( F_38 ( & V_2 -> V_12 . V_2 , V_179 [ V_178 ] ) )
goto V_189;
F_39 ( V_2 ) ;
F_40 ( & V_2 -> V_190 , V_191 ) ;
F_41 ( & V_2 -> V_190 , F_42 ( 1000 ) ) ;
F_43 ( L_8 ,
F_44 ( & V_2 -> V_5 . V_134 -> V_2 ) , F_45 ( V_2 ) ,
F_46 ( V_2 ) , V_2 -> V_177 ,
V_2 -> V_192 ) ;
F_43 ( L_9 ,
F_44 ( & V_2 -> V_5 . V_134 -> V_2 ) , V_2 -> V_171 ) ;
return V_2 ;
V_189:
F_28 ( V_2 ) ;
V_159:
F_21 ( V_2 ) ;
F_47 ( V_2 ) ;
V_188:
F_48 ( & V_187 , V_2 -> V_171 ) ;
V_186:
F_23 ( V_2 -> V_184 ) ;
F_49 ( & V_2 -> V_12 ) ;
F_19 ( L_10 , V_167 , V_182 ) ;
return NULL ;
}
static void F_50 ( struct V_1 * V_2 )
{
F_48 ( & V_187 , V_2 -> V_171 ) ;
F_23 ( V_2 -> V_184 ) ;
F_49 ( & V_2 -> V_12 ) ;
}
static void F_51 ( struct V_1 * V_2 )
{
F_52 ( & V_2 -> V_190 ) ;
F_28 ( V_2 ) ;
F_53 ( & V_2 -> V_12 ) ;
F_54 ( V_2 ) ;
F_21 ( V_2 ) ;
F_47 ( V_2 ) ;
F_50 ( V_2 ) ;
}
static int F_55 ( struct V_1 * V_2 )
{
struct V_193 V_194 ;
V_194 . V_195 = V_196 ;
V_194 . V_197 . V_10 = 1 ;
V_194 . V_9 = & V_2 -> V_12 ;
F_56 ( & V_194 ) ;
return 0 ;
}
static int F_57 ( struct V_1 * V_2 )
{
struct V_193 V_198 ;
V_198 . V_195 = V_199 ;
V_198 . V_197 . V_10 = 1 ;
V_198 . V_9 = & V_2 -> V_12 ;
F_56 ( & V_198 ) ;
return 0 ;
}
static void F_58 ( struct V_1 * V_2 )
{
F_57 ( V_2 ) ;
F_51 ( V_2 ) ;
}
static void F_59 ( struct V_1 * V_2 , T_4 V_195 )
{
switch ( V_195 ) {
case V_200 :
F_58 ( V_2 ) ;
break;
default:
break;
}
}
void F_37 ( struct V_1 * V_2 , T_1 V_183 )
{
if ( ! ( V_2 -> V_201 & V_202 ) ) {
V_2 -> V_201 |= V_202 ;
if ( ! V_183 )
return;
}
if ( ! V_183 )
F_57 ( V_2 ) ;
else
F_55 ( V_2 ) ;
}
static int T_5 F_60 ( void )
{
int V_182 ;
F_61 () ;
V_182 = F_62 ( & V_203 ) ;
if ( V_182 )
goto V_204;
return 0 ;
V_204:
return V_182 ;
}
static void T_6 F_63 ( void )
{
F_64 ( & V_203 ) ;
F_65 () ;
F_66 ( & V_187 ) ;
}
