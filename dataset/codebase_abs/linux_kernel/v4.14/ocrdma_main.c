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
V_14 -> V_18 = V_19 ;
if ( F_5 ( V_2 ) )
V_14 -> V_18 |= V_20 ;
V_17 = F_6 ( V_12 , V_10 , & V_16 ) ;
if ( V_17 )
return V_17 ;
V_14 -> V_21 = V_16 . V_21 ;
V_14 -> V_22 = V_16 . V_22 ;
V_14 -> V_23 = V_24 ;
return 0 ;
}
static void F_7 ( struct V_8 * V_9 , char * V_25 )
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
V_2 -> V_12 . V_69 = V_70 ;
V_2 -> V_12 . V_71 = V_72 ;
V_2 -> V_12 . V_73 = V_74 ;
V_2 -> V_12 . V_75 = V_76 ;
V_2 -> V_12 . V_77 = V_78 ;
V_2 -> V_12 . V_79 = V_80 ;
V_2 -> V_12 . V_81 = F_2 ;
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
V_2 -> V_12 . V_132 = V_133 ;
V_2 -> V_12 . V_2 . V_134 = & V_2 -> V_5 . V_135 -> V_2 ;
V_2 -> V_12 . V_136 = V_137 ;
V_2 -> V_12 . V_138 = F_3 ;
V_2 -> V_12 . F_7 = F_7 ;
if ( F_12 ( V_2 ) == V_139 ) {
V_2 -> V_12 . V_38 |=
F_11 ( V_140 ) |
F_11 ( V_141 ) |
F_11 ( V_142 ) |
F_11 ( V_143 ) |
F_11 ( V_144 ) ;
V_2 -> V_12 . V_145 = V_146 ;
V_2 -> V_12 . V_147 = V_148 ;
V_2 -> V_12 . V_149 = V_150 ;
V_2 -> V_12 . V_151 = V_152 ;
V_2 -> V_12 . V_153 = V_154 ;
}
return F_13 ( & V_2 -> V_12 , NULL ) ;
}
static int F_14 ( struct V_1 * V_2 )
{
F_15 ( & V_2 -> V_155 ) ;
V_2 -> V_156 = F_16 ( sizeof( struct V_157 * ) *
V_158 , V_159 ) ;
if ( ! V_2 -> V_156 )
goto V_160;
if ( V_2 -> V_16 . V_161 ) {
V_2 -> V_162 = F_16 ( sizeof( struct V_163 * ) *
V_164 , V_159 ) ;
if ( ! V_2 -> V_162 )
goto V_160;
}
V_2 -> V_165 = F_16 ( sizeof( V_166 ) * V_167 , V_159 ) ;
if ( V_2 -> V_165 == NULL )
goto V_160;
F_17 ( V_2 ) ;
if ( ! F_18 ( V_2 ) ) {
F_19 ( L_3 , V_168 ) ;
goto V_160;
}
F_20 ( & V_2 -> V_169 . V_170 ) ;
F_20 ( & V_2 -> V_171 ) ;
return 0 ;
V_160:
F_19 ( L_4 , V_168 , V_2 -> V_172 ) ;
return - V_173 ;
}
static void F_21 ( struct V_1 * V_2 )
{
F_22 ( V_2 ) ;
F_23 ( V_2 -> V_165 ) ;
F_23 ( V_2 -> V_162 ) ;
F_23 ( V_2 -> V_156 ) ;
}
static T_2 F_24 ( struct V_9 * V_9 , struct V_174 * V_16 ,
char * V_175 )
{
struct V_1 * V_2 = F_25 ( V_9 ) ;
return F_26 ( V_175 , V_176 , L_5 , V_2 -> V_5 . V_135 -> V_177 ) ;
}
static T_2 F_27 ( struct V_9 * V_9 ,
struct V_174 * V_16 , char * V_175 )
{
struct V_1 * V_2 = F_25 ( V_9 ) ;
return F_26 ( V_175 , V_176 , L_6 , & V_2 -> V_178 [ 0 ] ) ;
}
static void F_28 ( struct V_1 * V_2 )
{
int V_179 ;
for ( V_179 = 0 ; V_179 < F_29 ( V_180 ) ; V_179 ++ )
F_30 ( & V_2 -> V_12 . V_2 , V_180 [ V_179 ] ) ;
}
static struct V_1 * F_31 ( struct V_181 * V_182 )
{
int V_183 = 0 , V_179 ;
T_1 V_184 = 0 ;
struct V_1 * V_2 ;
V_2 = (struct V_1 * ) F_32 ( sizeof( struct V_1 ) ) ;
if ( ! V_2 ) {
F_19 ( L_7 ) ;
return NULL ;
}
V_2 -> V_185 = F_16 ( sizeof( struct V_186 ) , V_159 ) ;
if ( ! V_2 -> V_185 )
goto V_187;
memcpy ( & V_2 -> V_5 , V_182 , sizeof( * V_182 ) ) ;
V_2 -> V_172 = F_33 ( & V_188 , NULL , 0 , 0 , V_159 ) ;
if ( V_2 -> V_172 < 0 )
goto V_187;
V_183 = F_34 ( V_2 ) ;
if ( V_183 )
goto V_189;
V_183 = F_14 ( V_2 ) ;
if ( V_183 )
goto V_160;
F_35 ( V_2 ) ;
V_183 = F_8 ( V_2 ) ;
if ( V_183 )
goto V_160;
V_183 = F_36 ( V_2 , NULL , & V_184 ) ;
if ( ! V_183 )
F_37 ( V_2 , V_184 ) ;
for ( V_179 = 0 ; V_179 < F_29 ( V_180 ) ; V_179 ++ )
if ( F_38 ( & V_2 -> V_12 . V_2 , V_180 [ V_179 ] ) )
goto V_190;
F_39 ( V_2 ) ;
F_40 ( & V_2 -> V_191 , V_192 ) ;
F_41 ( & V_2 -> V_191 , F_42 ( 1000 ) ) ;
F_43 ( L_8 ,
F_44 ( & V_2 -> V_5 . V_135 -> V_2 ) , F_45 ( V_2 ) ,
F_46 ( V_2 ) , V_2 -> V_178 ,
V_2 -> V_193 ) ;
F_43 ( L_9 ,
F_44 ( & V_2 -> V_5 . V_135 -> V_2 ) , V_2 -> V_172 ) ;
return V_2 ;
V_190:
F_28 ( V_2 ) ;
V_160:
F_21 ( V_2 ) ;
F_47 ( V_2 ) ;
V_189:
F_48 ( & V_188 , V_2 -> V_172 ) ;
V_187:
F_23 ( V_2 -> V_185 ) ;
F_49 ( & V_2 -> V_12 ) ;
F_19 ( L_10 , V_168 , V_183 ) ;
return NULL ;
}
static void F_50 ( struct V_1 * V_2 )
{
F_48 ( & V_188 , V_2 -> V_172 ) ;
F_23 ( V_2 -> V_185 ) ;
F_49 ( & V_2 -> V_12 ) ;
}
static void F_51 ( struct V_1 * V_2 )
{
F_52 ( & V_2 -> V_191 ) ;
F_28 ( V_2 ) ;
F_53 ( & V_2 -> V_12 ) ;
F_54 ( V_2 ) ;
F_21 ( V_2 ) ;
F_47 ( V_2 ) ;
F_50 ( V_2 ) ;
}
static int F_55 ( struct V_1 * V_2 )
{
struct V_194 V_195 ;
V_195 . V_196 = V_197 ;
V_195 . V_198 . V_10 = 1 ;
V_195 . V_9 = & V_2 -> V_12 ;
F_56 ( & V_195 ) ;
return 0 ;
}
static int F_57 ( struct V_1 * V_2 )
{
struct V_194 V_199 ;
V_199 . V_196 = V_200 ;
V_199 . V_198 . V_10 = 1 ;
V_199 . V_9 = & V_2 -> V_12 ;
F_56 ( & V_199 ) ;
return 0 ;
}
static void F_58 ( struct V_1 * V_2 )
{
F_57 ( V_2 ) ;
F_51 ( V_2 ) ;
}
static void F_59 ( struct V_1 * V_2 , T_3 V_196 )
{
switch ( V_196 ) {
case V_201 :
F_58 ( V_2 ) ;
break;
default:
break;
}
}
void F_37 ( struct V_1 * V_2 , T_1 V_184 )
{
if ( ! ( V_2 -> V_202 & V_203 ) ) {
V_2 -> V_202 |= V_203 ;
if ( ! V_184 )
return;
}
if ( ! V_184 )
F_57 ( V_2 ) ;
else
F_55 ( V_2 ) ;
}
static int T_4 F_60 ( void )
{
int V_183 ;
F_61 () ;
V_183 = F_62 ( & V_204 ) ;
if ( V_183 )
goto V_205;
return 0 ;
V_205:
return V_183 ;
}
static void T_5 F_63 ( void )
{
F_64 ( & V_204 ) ;
F_65 () ;
F_66 ( & V_188 ) ;
}
