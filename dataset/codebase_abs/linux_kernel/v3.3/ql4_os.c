static T_1 F_1 ( int V_1 , int V_2 )
{
switch ( V_1 ) {
case V_3 :
switch ( V_2 ) {
case V_4 :
case V_5 :
case V_6 :
return V_7 ;
default:
return 0 ;
}
case V_8 :
switch ( V_2 ) {
case V_9 :
case V_10 :
case V_11 :
case V_12 :
case V_13 :
case V_14 :
case V_15 :
case V_16 :
case V_17 :
case V_18 :
case V_19 :
case V_20 :
case V_21 :
return V_7 ;
default:
return 0 ;
}
case V_22 :
switch ( V_2 ) {
case V_23 :
case V_24 :
case V_25 :
case V_26 :
case V_27 :
case V_28 :
case V_29 :
case V_30 :
case V_31 :
case V_32 :
case V_33 :
case V_34 :
case V_35 :
case V_36 :
case V_37 :
return V_7 ;
default:
return 0 ;
}
}
return 0 ;
}
static int F_2 ( struct V_38 * V_39 ,
enum V_40 V_1 ,
int V_2 , char * V_41 )
{
struct V_42 * V_43 = F_3 ( V_39 ) ;
struct V_44 * V_45 = F_4 ( V_43 ) ;
int V_46 = - V_47 ;
if ( V_1 != V_22 )
return - V_47 ;
switch ( V_2 ) {
case V_23 :
V_46 = sprintf ( V_41 , L_1 , & V_45 -> V_48 . V_49 ) ;
break;
case V_24 :
V_46 = sprintf ( V_41 , L_1 , & V_45 -> V_48 . V_50 ) ;
break;
case V_25 :
V_46 = sprintf ( V_41 , L_1 , & V_45 -> V_48 . V_51 ) ;
break;
case V_27 :
if ( V_39 -> V_52 == V_53 )
V_46 = sprintf ( V_41 , L_2 ,
( V_45 -> V_48 . V_54 &
V_55 ) ?
L_3 : L_4 ) ;
else if ( V_39 -> V_52 == V_56 )
V_46 = sprintf ( V_41 , L_2 ,
( V_45 -> V_48 . V_57 &
V_58 ) ?
L_3 : L_4 ) ;
break;
case V_26 :
V_46 = sprintf ( V_41 , L_2 ,
( V_45 -> V_48 . V_59 & V_60 ) ?
L_5 : L_6 ) ;
break;
case V_29 :
if ( V_39 -> V_61 == 0 )
V_46 = sprintf ( V_41 , L_7 , & V_45 -> V_48 . V_62 ) ;
if ( V_39 -> V_61 == 1 )
V_46 = sprintf ( V_41 , L_7 , & V_45 -> V_48 . V_63 ) ;
break;
case V_28 :
V_46 = sprintf ( V_41 , L_7 ,
& V_45 -> V_48 . V_64 ) ;
break;
case V_30 :
V_46 = sprintf ( V_41 , L_7 ,
& V_45 -> V_48 . V_65 ) ;
break;
case V_31 :
V_46 = sprintf ( V_41 , L_2 ,
( V_45 -> V_48 . V_66 &
V_67 ) ?
L_8 : L_6 ) ;
break;
case V_32 :
V_46 = sprintf ( V_41 , L_2 ,
( V_45 -> V_48 . V_66 &
V_68 ) ?
L_9 : L_6 ) ;
break;
case V_33 :
if ( V_39 -> V_52 == V_53 )
V_46 = sprintf ( V_41 , L_10 ,
( V_45 -> V_48 . V_69 &
V_70 ) ) ;
else if ( V_39 -> V_52 == V_56 )
V_46 = sprintf ( V_41 , L_10 ,
( V_45 -> V_48 . V_71 &
V_70 ) ) ;
break;
case V_34 :
if ( V_39 -> V_52 == V_53 )
V_46 = sprintf ( V_41 , L_10 ,
( ( V_45 -> V_48 . V_69 >> 13 ) &
V_72 ) ) ;
else if ( V_39 -> V_52 == V_56 )
V_46 = sprintf ( V_41 , L_10 ,
( ( V_45 -> V_48 . V_71 >> 13 ) &
V_72 ) ) ;
break;
case V_35 :
if ( V_39 -> V_52 == V_53 )
V_46 = sprintf ( V_41 , L_2 ,
( V_45 -> V_48 . V_54 &
V_73 ) ?
L_3 : L_4 ) ;
else if ( V_39 -> V_52 == V_56 )
V_46 = sprintf ( V_41 , L_2 ,
( V_45 -> V_48 . V_57 &
V_74 ) ?
L_3 : L_4 ) ;
break;
case V_36 :
V_46 = sprintf ( V_41 , L_10 , V_45 -> V_48 . V_75 ) ;
break;
case V_37 :
if ( V_39 -> V_52 == V_53 )
V_46 = sprintf ( V_41 , L_10 , V_45 -> V_48 . V_76 ) ;
else if ( V_39 -> V_52 == V_56 )
V_46 = sprintf ( V_41 , L_10 , V_45 -> V_48 . V_77 ) ;
break;
default:
V_46 = - V_47 ;
}
return V_46 ;
}
static struct V_78 *
F_5 ( struct V_42 * V_43 , struct V_79 * V_80 ,
int V_81 )
{
int V_82 ;
struct V_78 * V_83 ;
struct V_84 * V_85 ;
struct V_44 * V_45 ;
struct V_86 * V_87 ;
struct V_88 * V_89 ;
F_6 ( F_7 ( V_90 L_11 , V_91 ) ) ;
if ( ! V_43 ) {
V_82 = - V_92 ;
F_7 ( V_93 L_12 ,
V_91 ) ;
return F_8 ( V_82 ) ;
}
V_45 = F_9 ( V_43 ) ;
V_83 = F_10 ( sizeof( struct V_84 ) ) ;
if ( ! V_83 ) {
V_82 = - V_94 ;
return F_8 ( V_82 ) ;
}
V_85 = V_83 -> V_95 ;
memset ( V_85 , 0 , sizeof( struct V_84 ) ) ;
if ( V_80 -> V_96 == V_97 ) {
memcpy ( & V_85 -> V_80 , V_80 , sizeof( struct V_86 ) ) ;
V_87 = (struct V_86 * ) & V_85 -> V_80 ;
F_6 ( F_11 ( V_90 , V_45 , L_13 , V_91 ,
( char * ) & V_87 -> V_98 ) ) ;
} else if ( V_80 -> V_96 == V_99 ) {
memcpy ( & V_85 -> V_80 , V_80 ,
sizeof( struct V_88 ) ) ;
V_89 = (struct V_88 * ) & V_85 -> V_80 ;
F_6 ( F_11 ( V_90 , V_45 , L_14 , V_91 ,
( char * ) & V_89 -> V_100 ) ) ;
}
V_85 -> V_101 = V_43 ;
return V_83 ;
}
static int F_12 ( struct V_78 * V_83 , int V_102 )
{
struct V_84 * V_85 ;
struct V_44 * V_45 ;
int V_82 = 0 ;
F_6 ( F_7 ( V_90 L_11 , V_91 ) ) ;
V_85 = V_83 -> V_95 ;
V_45 = F_4 ( V_85 -> V_101 ) ;
if ( F_13 ( V_45 ) && ! F_14 ( V_103 , & V_45 -> V_104 ) )
V_82 = 1 ;
return V_82 ;
}
static void F_15 ( struct V_78 * V_83 )
{
F_6 ( F_7 ( V_90 L_11 , V_91 ) ) ;
F_16 ( V_83 ) ;
}
static int F_17 ( struct V_78 * V_83 ,
enum V_105 V_2 ,
char * V_41 )
{
struct V_84 * V_85 = V_83 -> V_95 ;
struct V_79 * V_80 ;
F_6 ( F_7 ( V_90 L_11 , V_91 ) ) ;
switch ( V_2 ) {
case V_12 :
case V_11 :
if ( ! V_85 )
return - V_106 ;
V_80 = (struct V_79 * ) & V_85 -> V_80 ;
if ( ! V_80 )
return - V_106 ;
return F_18 ( (struct V_107 * )
& V_85 -> V_80 , V_2 , V_41 ) ;
default:
return - V_47 ;
}
}
static void F_19 ( struct V_108 * V_109 ,
struct V_110 * V_111 )
{
struct V_112 * V_113 ;
struct V_114 * V_115 ;
struct V_116 * V_116 ;
struct V_44 * V_45 ;
struct V_117 * V_117 ;
int V_118 ;
int V_82 ;
T_2 V_119 ;
F_6 ( F_7 ( V_90 L_11 , V_91 ) ) ;
V_115 = F_20 ( V_109 ) ;
V_113 = V_115 -> V_95 ;
V_116 = V_113 -> V_95 ;
V_45 = V_116 -> V_45 ;
V_118 = F_21 ( sizeof( struct V_117 ) ) ;
V_117 = F_22 ( & V_45 -> V_120 -> V_121 , V_118 ,
& V_119 , V_122 ) ;
if ( ! V_117 ) {
F_11 ( V_93 , V_45 ,
L_15 ) ;
goto V_123;
}
V_82 = F_23 ( V_45 , V_116 -> V_124 , V_118 ,
V_119 ) ;
if ( V_82 != V_125 ) {
F_11 ( V_93 , V_45 ,
L_16 ) ;
goto V_126;
}
V_111 -> V_127 = F_24 ( V_117 -> V_128 ) ;
V_111 -> V_129 = F_24 ( V_117 -> V_130 ) ;
V_111 -> V_131 = F_25 ( V_117 -> V_132 ) ;
V_111 -> V_133 = F_25 ( V_117 -> V_134 ) ;
V_111 -> V_135 = F_25 ( V_117 -> V_136 ) ;
V_111 -> V_137 = F_25 ( V_117 -> V_138 ) ;
V_111 -> V_139 = F_25 ( V_117 -> V_140 ) ;
V_111 -> V_141 = F_25 ( V_117 -> V_142 ) ;
V_111 -> V_143 = F_25 ( V_117 -> V_144 ) ;
V_111 -> V_145 = F_25 ( V_117 -> V_146 ) ;
V_111 -> V_147 = F_25 ( V_117 -> V_148 ) ;
V_111 -> V_149 = F_25 ( V_117 -> V_150 ) ;
V_111 -> V_151 = F_25 ( V_117 -> V_152 ) ;
V_111 -> V_153 = F_25 ( V_117 -> V_154 ) ;
V_111 -> V_155 = F_25 ( V_117 -> V_156 ) ;
V_111 -> V_157 =
F_25 ( V_117 -> V_158 ) ;
V_111 -> V_159 = F_25 ( V_117 -> V_160 ) ;
V_111 -> V_161 = F_25 ( V_117 -> V_162 ) ;
V_111 -> V_163 = F_25 ( V_117 -> V_164 ) ;
V_126:
F_26 ( & V_45 -> V_120 -> V_121 , V_118 , V_117 ,
V_119 ) ;
V_123:
return;
}
static enum V_165 F_27 ( struct V_166 * V_167 )
{
struct V_114 * V_168 ;
struct V_112 * V_113 ;
unsigned long V_104 ;
enum V_165 V_82 = V_169 ;
V_168 = F_28 ( F_29 ( V_167 -> V_170 ) ) ;
V_113 = V_168 -> V_95 ;
F_30 ( & V_168 -> V_171 , V_104 ) ;
if ( V_168 -> V_172 == V_173 )
V_82 = V_174 ;
F_31 ( & V_168 -> V_171 , V_104 ) ;
return V_82 ;
}
static int F_32 ( struct V_42 * V_43 ,
enum V_175 V_2 , char * V_41 )
{
struct V_44 * V_45 = F_4 ( V_43 ) ;
int V_46 ;
switch ( V_2 ) {
case V_4 :
V_46 = F_33 ( V_41 , V_45 -> V_176 , V_177 ) ;
break;
case V_5 :
V_46 = sprintf ( V_41 , L_1 , & V_45 -> V_48 . V_49 ) ;
break;
case V_6 :
V_46 = sprintf ( V_41 , L_2 , V_45 -> V_178 ) ;
break;
default:
return - V_47 ;
}
return V_46 ;
}
static void F_34 ( struct V_44 * V_45 )
{
if ( V_45 -> V_179 )
return;
V_45 -> V_179 = F_35 ( V_45 -> V_101 ,
& V_180 ,
V_53 , 0 , 0 ) ;
if ( ! V_45 -> V_179 )
F_11 ( V_93 , V_45 , L_17
L_18 ) ;
}
static void F_36 ( struct V_44 * V_45 )
{
if ( ! V_45 -> V_181 )
V_45 -> V_181 = F_35 ( V_45 -> V_101 ,
& V_180 ,
V_56 , 0 ,
0 ) ;
if ( ! V_45 -> V_181 )
F_11 ( V_93 , V_45 , L_19
L_18 ) ;
if ( ! V_45 -> V_182 )
V_45 -> V_182 = F_35 ( V_45 -> V_101 ,
& V_180 ,
V_56 , 1 ,
0 ) ;
if ( ! V_45 -> V_182 )
F_11 ( V_93 , V_45 , L_19
L_20 ) ;
}
static void F_37 ( struct V_44 * V_45 )
{
if ( V_45 -> V_48 . V_54 & V_55 )
F_34 ( V_45 ) ;
if ( V_45 -> V_48 . V_57 & V_58 )
F_36 ( V_45 ) ;
}
static void F_38 ( struct V_44 * V_45 )
{
if ( V_45 -> V_179 ) {
F_39 ( V_45 -> V_179 ) ;
V_45 -> V_179 = NULL ;
}
}
static void F_40 ( struct V_44 * V_45 )
{
if ( V_45 -> V_181 ) {
F_39 ( V_45 -> V_181 ) ;
V_45 -> V_181 = NULL ;
}
if ( V_45 -> V_182 ) {
F_39 ( V_45 -> V_182 ) ;
V_45 -> V_182 = NULL ;
}
}
static void F_41 ( struct V_44 * V_45 )
{
F_38 ( V_45 ) ;
F_40 ( V_45 ) ;
}
static void F_42 ( struct V_44 * V_45 ,
struct V_183 * V_184 ,
struct V_185 * V_186 )
{
switch ( V_184 -> V_2 ) {
case V_29 :
if ( V_184 -> V_61 & 0x1 )
memcpy ( V_186 -> V_63 , V_184 -> V_187 ,
sizeof( V_186 -> V_63 ) ) ;
else
memcpy ( V_186 -> V_62 , V_184 -> V_187 ,
sizeof( V_186 -> V_62 ) ) ;
break;
case V_28 :
if ( V_184 -> V_61 & 0x1 )
break;
memcpy ( V_186 -> V_188 , & V_184 -> V_187 [ 8 ] ,
sizeof( V_186 -> V_188 ) ) ;
break;
case V_30 :
if ( V_184 -> V_61 & 0x1 )
break;
memcpy ( V_186 -> V_189 , V_184 -> V_187 ,
sizeof( V_186 -> V_189 ) ) ;
break;
case V_31 :
if ( V_184 -> V_61 & 0x1 )
break;
if ( V_184 -> V_187 [ 0 ] == V_190 )
V_186 -> V_191 &=
F_43 (
~ V_67 ) ;
else if ( V_184 -> V_187 [ 0 ] == V_192 )
V_186 -> V_191 |=
F_43 (
V_67 ) ;
else
F_11 ( V_93 , V_45 , L_21
L_22 ) ;
break;
case V_32 :
if ( V_184 -> V_61 & 0x1 )
break;
if ( V_184 -> V_187 [ 0 ] ==
V_193 )
V_186 -> V_191 |= F_43 (
V_68 ) ;
else if ( V_184 -> V_187 [ 0 ] ==
V_194 )
V_186 -> V_191 &= F_43 (
~ V_68 ) ;
else
F_11 ( V_93 , V_45 , L_21
L_23 ) ;
break;
case V_195 :
if ( V_184 -> V_61 & 0x1 )
break;
if ( V_184 -> V_187 [ 0 ] == V_196 )
memset ( V_186 -> V_189 , 0 ,
sizeof( V_186 -> V_189 ) ) ;
break;
case V_27 :
if ( V_184 -> V_187 [ 0 ] == V_197 ) {
V_186 -> V_198 |=
F_43 ( V_58 ) ;
F_36 ( V_45 ) ;
} else {
V_186 -> V_198 &=
F_43 ( ~ V_58 &
0xFFFF ) ;
F_40 ( V_45 ) ;
}
break;
case V_199 :
if ( V_184 -> V_46 != sizeof( V_186 -> V_71 ) )
break;
V_186 -> V_71 =
F_44 ( * ( V_200 * ) V_184 -> V_187 ) ;
break;
case V_35 :
if ( V_184 -> V_187 [ 0 ] == V_201 )
V_186 -> V_198 |=
F_43 ( V_74 ) ;
else
V_186 -> V_198 &=
F_43 ( ~ V_74 ) ;
break;
case V_36 :
V_186 -> V_75 =
F_43 ( * ( V_200 * ) V_184 -> V_187 ) ;
break;
case V_37 :
if ( V_184 -> V_61 & 0x1 )
break;
V_186 -> V_77 =
F_43 ( * ( V_200 * ) V_184 -> V_187 ) ;
break;
default:
F_11 ( V_93 , V_45 , L_24 ,
V_184 -> V_2 ) ;
break;
}
}
static void F_45 ( struct V_44 * V_45 ,
struct V_183 * V_184 ,
struct V_185 * V_186 )
{
switch ( V_184 -> V_2 ) {
case V_23 :
memcpy ( V_186 -> V_202 , V_184 -> V_187 ,
sizeof( V_186 -> V_202 ) ) ;
break;
case V_24 :
memcpy ( V_186 -> V_203 , V_184 -> V_187 ,
sizeof( V_186 -> V_203 ) ) ;
break;
case V_25 :
memcpy ( V_186 -> V_204 , V_184 -> V_187 ,
sizeof( V_186 -> V_204 ) ) ;
break;
case V_26 :
if ( V_184 -> V_187 [ 0 ] == V_205 )
V_186 -> V_206 |=
F_43 ( V_60 ) ;
else if ( V_184 -> V_187 [ 0 ] == V_207 )
V_186 -> V_206 &=
F_43 ( ~ V_60 ) ;
else
F_11 ( V_93 , V_45 , L_25 ) ;
break;
case V_27 :
if ( V_184 -> V_187 [ 0 ] == V_197 ) {
V_186 -> V_208 |=
F_43 ( V_55 ) ;
F_34 ( V_45 ) ;
} else {
V_186 -> V_208 &=
F_43 ( ~ V_55 &
0xFFFF ) ;
F_38 ( V_45 ) ;
}
break;
case V_199 :
if ( V_184 -> V_46 != sizeof( V_186 -> V_69 ) )
break;
V_186 -> V_69 =
F_44 ( * ( V_200 * ) V_184 -> V_187 ) ;
break;
case V_35 :
if ( V_184 -> V_187 [ 0 ] == V_201 )
V_186 -> V_208 |=
F_43 ( V_73 ) ;
else
V_186 -> V_208 &=
F_43 ( ~ V_73 ) ;
break;
case V_36 :
V_186 -> V_75 =
F_43 ( * ( V_200 * ) V_184 -> V_187 ) ;
break;
case V_37 :
V_186 -> V_76 =
F_43 ( * ( V_200 * ) V_184 -> V_187 ) ;
break;
default:
F_11 ( V_93 , V_45 , L_26 ,
V_184 -> V_2 ) ;
break;
}
}
static void
F_46 ( struct V_185 * V_186 )
{
struct V_209 * V_210 ;
V_210 = (struct V_209 * ) V_186 ;
memset ( V_210 -> V_211 , 0 , sizeof( V_210 -> V_211 ) ) ;
memset ( V_210 -> V_212 , 0 , sizeof( V_210 -> V_212 ) ) ;
memset ( V_210 -> V_213 , 0 , sizeof( V_210 -> V_213 ) ) ;
memset ( V_210 -> V_214 , 0 , sizeof( V_210 -> V_214 ) ) ;
memset ( V_210 -> V_215 , 0 , sizeof( V_210 -> V_215 ) ) ;
memset ( V_210 -> V_216 , 0 , sizeof( V_210 -> V_216 ) ) ;
memset ( V_210 -> V_217 , 0 , sizeof( V_210 -> V_217 ) ) ;
memset ( V_210 -> V_218 , 0 , sizeof( V_210 -> V_218 ) ) ;
memset ( V_210 -> V_219 , 0 , sizeof( V_210 -> V_219 ) ) ;
memset ( V_210 -> V_220 , 0 , sizeof( V_210 -> V_220 ) ) ;
memset ( V_210 -> V_221 , 0 , sizeof( V_210 -> V_221 ) ) ;
memset ( V_210 -> V_222 , 0 , sizeof( V_210 -> V_222 ) ) ;
memset ( V_210 -> V_223 , 0 , sizeof( V_210 -> V_223 ) ) ;
memset ( V_210 -> V_224 , 0 , sizeof( V_210 -> V_224 ) ) ;
memset ( V_210 -> V_225 , 0 , sizeof( V_210 -> V_225 ) ) ;
}
static int
F_47 ( struct V_42 * V_43 , void * V_226 , T_3 V_46 )
{
struct V_44 * V_45 = F_4 ( V_43 ) ;
int V_227 = 0 ;
struct V_183 * V_184 = NULL ;
struct V_185 * V_186 = NULL ;
T_2 V_228 ;
T_3 V_229 [ V_230 ] ;
T_3 V_231 [ V_230 ] ;
T_3 V_232 = V_46 ;
struct V_233 * V_234 ;
V_186 = F_22 ( & V_45 -> V_120 -> V_121 ,
sizeof( struct V_185 ) ,
& V_228 , V_122 ) ;
if ( ! V_186 ) {
F_11 ( V_93 , V_45 , L_27 ,
V_91 ) ;
return - V_94 ;
}
memset ( V_186 , 0 , sizeof( struct V_185 ) ) ;
memset ( & V_229 , 0 , sizeof( V_229 ) ) ;
memset ( & V_231 , 0 , sizeof( V_231 ) ) ;
if ( F_48 ( V_45 , & V_229 [ 0 ] , & V_231 [ 0 ] , V_228 ) ) {
F_11 ( V_93 , V_45 , L_28 , V_91 ) ;
V_227 = - V_235 ;
goto V_236;
}
F_49 (attr, data, len, rem) {
V_184 = F_50 ( V_234 ) ;
if ( V_184 -> V_1 != V_22 )
continue;
switch ( V_184 -> V_52 ) {
case V_53 :
switch ( V_184 -> V_61 ) {
case 0 :
F_45 ( V_45 , V_184 , V_186 ) ;
break;
default:
F_11 ( V_93 , V_45 , L_29
L_30 ,
V_184 -> V_61 ) ;
break;
}
break;
case V_56 :
switch ( V_184 -> V_61 ) {
case 0 :
case 1 :
F_42 ( V_45 , V_184 , V_186 ) ;
break;
default:
F_11 ( V_93 , V_45 , L_31
L_30 ,
V_184 -> V_61 ) ;
break;
}
break;
default:
F_11 ( V_93 , V_45 , L_32 ) ;
break;
}
}
V_186 -> V_237 = F_51 ( 0x11BEAD5A ) ;
V_227 = F_52 ( V_45 , V_228 , V_238 ,
sizeof( struct V_185 ) ,
V_239 ) ;
if ( V_227 != V_125 ) {
F_11 ( V_93 , V_45 , L_33 ,
V_91 ) ;
V_227 = - V_235 ;
goto V_236;
}
V_227 = F_53 ( V_45 ) ;
if ( V_227 != V_125 ) {
F_11 ( V_93 , V_45 , L_34 ,
V_91 ) ;
V_227 = - V_235 ;
goto V_236;
}
F_54 ( & V_45 -> V_240 ,
V_241 * V_242 ) ;
F_46 ( V_186 ) ;
V_227 = F_55 ( V_45 , & V_229 [ 0 ] , & V_231 [ 0 ] , V_228 ) ;
if ( V_227 != V_125 ) {
F_11 ( V_93 , V_45 , L_35 ,
V_91 ) ;
V_227 = - V_235 ;
goto V_236;
}
memset ( V_186 , 0 , sizeof( struct V_185 ) ) ;
F_56 ( V_45 , & V_229 [ 0 ] , & V_231 [ 0 ] , V_186 ,
V_228 ) ;
V_236:
F_26 ( & V_45 -> V_120 -> V_121 , sizeof( struct V_185 ) ,
V_186 , V_228 ) ;
return V_227 ;
}
static int F_57 ( struct V_108 * V_109 ,
enum V_105 V_2 , char * V_41 )
{
struct V_243 * V_244 ;
struct V_245 * V_245 ;
struct V_79 * V_80 ;
int V_46 = 0 ;
V_244 = V_109 -> V_95 ;
V_245 = V_244 -> V_95 ;
V_80 = & V_245 -> V_85 -> V_80 ;
switch ( V_2 ) {
case V_12 :
case V_11 :
return F_18 ( (struct V_107 * )
V_80 , V_2 , V_41 ) ;
default:
return F_58 ( V_109 , V_2 , V_41 ) ;
}
return V_46 ;
}
int F_59 ( struct V_44 * V_45 , V_200 * V_246 )
{
T_3 V_247 = 0 ;
V_200 V_248 ;
int V_82 ;
V_249:
V_248 = F_60 ( V_45 -> V_250 , V_251 ) ;
if ( V_248 >= V_251 ) {
F_6 ( F_11 ( V_90 , V_45 ,
L_36 ) ) ;
V_82 = V_252 ;
goto V_253;
}
if ( F_61 ( V_248 , V_45 -> V_250 ) )
goto V_249;
F_6 ( F_11 ( V_90 , V_45 ,
L_37 , V_248 ) ) ;
V_82 = F_62 ( V_45 , V_248 , & V_247 ) ;
if ( V_82 == V_252 ) {
if ( V_247 == V_254 ) {
F_11 ( V_90 , V_45 ,
L_38 ,
V_248 ) ;
goto V_249;
}
F_6 ( F_11 ( V_90 , V_45 ,
L_39 ) ) ;
}
* V_246 = V_248 ;
V_253:
return V_82 ;
}
static int F_63 ( struct V_44 * V_45 ,
struct V_116 * V_116 ,
char * V_255 ,
char * V_256 )
{
T_4 V_257 [ V_258 ] ;
char V_259 [ V_260 ] ;
int V_261 = V_125 , V_82 = 0 ;
if ( V_116 -> V_262 . V_263 & V_264 ) {
V_82 = F_64 ( V_256 , strlen ( V_256 ) , V_257 ,
'\0' , NULL ) ;
if ( V_82 == 0 ) {
V_261 = V_252 ;
goto V_265;
}
V_82 = sprintf ( V_259 , L_40 , V_257 ) ;
} else {
V_82 = F_65 ( V_256 , strlen ( V_256 ) , V_257 ,
'\0' , NULL ) ;
if ( V_82 == 0 ) {
V_261 = V_252 ;
goto V_265;
}
V_82 = sprintf ( V_259 , L_41 , V_257 ) ;
}
if ( strcmp ( V_255 , V_259 ) )
V_261 = V_252 ;
V_265:
return V_261 ;
}
static int F_66 ( struct V_44 * V_45 ,
struct V_108 * V_109 )
{
int V_266 = 0 , V_267 , V_227 ;
struct V_114 * V_115 = F_20 ( V_109 ) ;
struct V_112 * V_113 , * V_268 ;
struct V_243 * V_244 , * V_269 ;
struct V_116 * V_116 ;
V_113 = V_115 -> V_95 ;
V_244 = V_109 -> V_95 ;
if ( V_113 -> V_270 == NULL ||
V_244 -> V_271 == NULL ||
V_244 -> V_272 == 0 )
return V_252 ;
V_267 = F_67 ( V_45 ) ? V_273 :
V_274 ;
for ( V_266 = 0 ; V_266 < V_267 ; V_266 ++ ) {
V_116 = F_68 ( V_45 , V_266 ) ;
if ( V_116 == NULL )
continue;
if ( V_116 -> V_275 != V_276 )
continue;
V_268 = V_116 -> V_113 -> V_95 ;
V_269 = V_116 -> V_244 -> V_95 ;
if ( V_268 -> V_270 == NULL ||
V_269 -> V_271 == NULL ||
V_269 -> V_272 == 0 )
continue;
F_6 ( F_11 ( V_90 , V_45 ,
L_42 ,
V_268 -> V_270 ,
V_113 -> V_270 ) ) ;
F_6 ( F_11 ( V_90 , V_45 ,
L_43 ,
V_269 -> V_271 ,
V_244 -> V_271 ) ) ;
F_6 ( F_11 ( V_90 , V_45 ,
L_44 ,
V_269 -> V_272 ,
V_244 -> V_272 ) ) ;
if ( strcmp ( V_268 -> V_270 , V_113 -> V_270 ) )
continue;
V_227 = F_63 ( V_45 , V_116 ,
V_269 -> V_271 ,
V_244 -> V_271 ) ;
if ( V_227 == V_252 )
continue;
if ( V_269 -> V_272 != V_244 -> V_272 )
continue;
break;
}
if ( V_266 == V_267 )
return V_252 ;
F_6 ( F_11 ( V_90 , V_45 ,
L_45 ) ) ;
return V_125 ;
}
static struct V_114 *
F_69 ( struct V_78 * V_83 ,
V_200 V_277 , V_200 V_278 ,
T_3 V_279 )
{
struct V_114 * V_115 ;
struct V_44 * V_45 ;
struct V_84 * V_85 ;
struct V_116 * V_116 ;
V_200 V_246 ;
struct V_112 * V_113 ;
struct V_79 * V_80 ;
int V_82 ;
F_6 ( F_7 ( V_90 L_11 , V_91 ) ) ;
if ( ! V_83 ) {
F_7 ( V_93 L_46 ) ;
return NULL ;
}
V_85 = V_83 -> V_95 ;
V_80 = (struct V_79 * ) & V_85 -> V_80 ;
V_45 = F_4 ( V_85 -> V_101 ) ;
V_82 = F_59 ( V_45 , & V_246 ) ;
if ( V_82 == V_252 )
return NULL ;
V_115 = F_70 ( & V_180 , V_85 -> V_101 ,
V_277 , sizeof( struct V_116 ) ,
sizeof( struct V_280 ) ,
V_279 , V_246 ) ;
if ( ! V_115 )
return NULL ;
V_113 = V_115 -> V_95 ;
V_116 = V_113 -> V_95 ;
V_116 -> V_124 = V_246 ;
V_116 -> V_281 = V_282 ;
V_116 -> V_45 = V_45 ;
V_116 -> V_113 = V_115 ;
V_116 -> V_283 = V_284 ;
V_116 -> V_285 = V_286 ;
V_115 -> V_287 = V_288 ;
V_45 -> V_289 [ V_116 -> V_124 ] = V_116 ;
V_45 -> V_290 ++ ;
return V_115 ;
}
static void F_71 ( struct V_114 * V_115 )
{
struct V_112 * V_113 ;
struct V_116 * V_116 ;
struct V_44 * V_45 ;
unsigned long V_104 ;
F_6 ( F_7 ( V_90 L_11 , V_91 ) ) ;
V_113 = V_115 -> V_95 ;
V_116 = V_113 -> V_95 ;
V_45 = V_116 -> V_45 ;
F_72 ( V_45 , V_116 -> V_124 ) ;
F_30 ( & V_45 -> V_291 , V_104 ) ;
F_73 ( V_45 , V_116 ) ;
F_31 ( & V_45 -> V_291 , V_104 ) ;
F_74 ( V_115 ) ;
}
static struct V_108 *
F_75 ( struct V_114 * V_115 , T_3 V_292 )
{
struct V_108 * V_109 ;
struct V_112 * V_113 ;
struct V_116 * V_116 ;
F_6 ( F_7 ( V_90 L_11 , V_91 ) ) ;
V_109 = F_76 ( V_115 , sizeof( struct V_245 ) ,
V_292 ) ;
if ( ! V_109 )
return NULL ;
V_113 = V_115 -> V_95 ;
V_116 = V_113 -> V_95 ;
V_116 -> V_244 = V_109 ;
return V_109 ;
}
static int F_77 ( struct V_114 * V_293 ,
struct V_108 * V_109 ,
T_5 V_294 , int V_295 )
{
struct V_243 * V_244 ;
struct V_245 * V_245 ;
struct V_78 * V_83 ;
F_6 ( F_7 ( V_90 L_11 , V_91 ) ) ;
if ( F_78 ( V_293 , V_109 , V_295 ) )
return - V_296 ;
V_83 = F_79 ( V_294 ) ;
V_244 = V_109 -> V_95 ;
V_245 = V_244 -> V_95 ;
V_245 -> V_85 = V_83 -> V_95 ;
return 0 ;
}
static int F_80 ( struct V_108 * V_109 )
{
struct V_114 * V_115 = F_20 ( V_109 ) ;
struct V_112 * V_113 ;
struct V_116 * V_116 ;
struct V_44 * V_45 ;
struct V_297 * V_262 = NULL ;
T_2 V_298 ;
T_3 V_247 = 0 ;
int V_82 = 0 ;
int V_261 = V_125 ;
F_6 ( F_7 ( V_90 L_11 , V_91 ) ) ;
V_113 = V_115 -> V_95 ;
V_116 = V_113 -> V_95 ;
V_45 = V_116 -> V_45 ;
V_82 = F_66 ( V_45 , V_109 ) ;
if ( V_82 == V_125 ) {
F_11 ( V_90 , V_45 ,
L_47 ) ;
V_82 = - V_299 ;
goto V_300;
}
V_262 = F_22 ( & V_45 -> V_120 -> V_121 , sizeof( * V_262 ) ,
& V_298 , V_122 ) ;
if ( ! V_262 ) {
F_11 ( V_93 , V_45 ,
L_48 , V_91 ) ;
V_82 = - V_94 ;
goto V_300;
}
V_82 = F_81 ( V_45 , V_116 , V_109 , & V_247 ) ;
if ( V_82 ) {
if ( V_247 )
if ( V_116 -> V_281 ==
V_301 ) {
V_116 -> V_283 ( V_116 -> V_113 ) ;
goto V_302;
}
F_11 ( V_93 , V_45 , L_49 ,
V_91 , V_116 -> V_124 ) ;
goto V_300;
}
V_261 = F_82 ( V_45 , V_116 -> V_124 ) ;
if ( V_261 == V_252 ) {
F_11 ( V_93 , V_45 , L_50 , V_91 ,
V_113 -> V_270 ) ;
V_82 = - V_296 ;
goto V_300;
}
if ( V_116 -> V_281 == V_282 )
V_116 -> V_281 = V_303 ;
F_6 ( F_7 ( V_90 L_51 , V_91 ,
V_116 -> V_281 ) ) ;
V_302:
V_82 = 0 ;
V_300:
if ( V_262 )
F_26 ( & V_45 -> V_120 -> V_121 , sizeof( * V_262 ) ,
V_262 , V_298 ) ;
return V_82 ;
}
static void F_83 ( struct V_108 * V_109 )
{
struct V_114 * V_115 = F_20 ( V_109 ) ;
struct V_112 * V_113 ;
struct V_44 * V_45 ;
struct V_116 * V_116 ;
int V_263 ;
F_6 ( F_7 ( V_90 L_11 , V_91 ) ) ;
V_113 = V_115 -> V_95 ;
V_116 = V_113 -> V_95 ;
V_45 = V_116 -> V_45 ;
V_263 = V_304 ;
if ( F_84 ( V_45 , V_116 , V_263 ) == V_252 )
F_11 ( V_93 , V_45 , L_52 , V_91 ) ;
}
static void F_85 ( struct V_305 * V_306 )
{
struct V_280 * V_307 ;
struct V_44 * V_45 ;
struct V_308 * V_309 ;
struct V_310 * V_311 ;
struct V_312 * V_313 ;
T_4 * V_226 ;
T_3 V_314 ;
struct V_243 * V_244 ;
int V_315 ;
T_6 V_316 ;
V_307 = F_86 ( V_306 , struct V_280 , V_317 ) ;
V_45 = V_307 -> V_45 ;
V_311 = V_307 -> V_311 ;
V_309 = & V_307 -> V_309 ;
V_315 = sizeof( struct V_312 ) ;
F_87 ( F_7 ( V_90 L_53 ) ) ;
F_87 ( F_88 ( V_309 , 64 ) ) ;
F_87 ( F_7 ( V_90 L_54 ) ) ;
F_87 ( F_88 ( V_307 -> V_318 , 64 ) ) ;
V_244 = V_311 -> V_244 ;
switch ( V_309 -> V_319 ) {
case V_320 :
V_313 = (struct V_312 * ) V_307 -> V_318 ;
V_316 = V_309 -> V_321 ;
V_313 -> V_316 = V_316 ;
V_226 = V_307 -> V_318 + V_315 ;
V_314 = V_307 -> V_322 - V_315 ;
F_89 ( V_244 , V_313 , V_226 , V_314 ) ;
break;
default:
F_11 ( V_93 , V_45 , L_55 ,
V_309 -> V_319 ) ;
break;
}
return;
}
static int F_90 ( struct V_310 * V_311 , T_4 V_323 )
{
struct V_280 * V_307 ;
struct V_112 * V_113 ;
struct V_116 * V_116 ;
struct V_44 * V_45 ;
int V_315 ;
V_113 = V_311 -> V_244 -> V_168 ;
V_116 = V_113 -> V_95 ;
V_45 = V_116 -> V_45 ;
V_307 = V_311 -> V_95 ;
memset ( V_307 , 0 , sizeof( struct V_280 ) ) ;
if ( V_311 -> V_167 ) {
F_11 ( V_90 , V_45 ,
L_56 , V_91 ) ;
return - V_296 ;
}
V_315 = sizeof( struct V_312 ) ;
V_307 -> V_45 = V_45 ;
V_307 -> V_311 = V_311 ;
if ( V_311 -> V_324 ) {
V_307 -> V_325 = F_91 ( & V_45 -> V_120 -> V_121 , V_311 -> V_226 ,
V_311 -> V_324 ,
V_326 ) ;
}
F_6 ( F_11 ( V_90 , V_45 , L_57 ,
V_91 , V_311 -> V_244 -> V_327 , V_315 ) ) ;
V_307 -> V_322 = V_311 -> V_244 -> V_327 + V_315 ;
V_307 -> V_318 = F_22 ( & V_45 -> V_120 -> V_121 ,
V_307 -> V_322 ,
& V_307 -> V_328 ,
V_329 ) ;
if ( ! V_307 -> V_318 )
goto V_330;
V_307 -> V_331 = V_311 -> V_324 + V_315 ;
V_307 -> V_332 = F_22 ( & V_45 -> V_120 -> V_121 ,
V_307 -> V_331 ,
& V_307 -> V_333 ,
V_329 ) ;
if ( ! V_307 -> V_332 )
goto V_330;
V_311 -> V_313 = V_307 -> V_332 ;
F_92 ( & V_307 -> V_317 , F_85 ) ;
return 0 ;
V_330:
if ( V_307 -> V_318 )
F_26 ( & V_45 -> V_120 -> V_121 , V_307 -> V_322 ,
V_307 -> V_318 , V_307 -> V_328 ) ;
if ( V_307 -> V_332 )
F_26 ( & V_45 -> V_120 -> V_121 , V_307 -> V_331 ,
V_307 -> V_332 , V_307 -> V_333 ) ;
return - V_94 ;
}
static void F_93 ( struct V_310 * V_311 )
{
struct V_280 * V_307 ;
struct V_112 * V_113 ;
struct V_116 * V_116 ;
struct V_44 * V_45 ;
int V_315 ;
V_315 = sizeof( struct V_312 ) ;
V_113 = V_311 -> V_244 -> V_168 ;
V_116 = V_113 -> V_95 ;
V_45 = V_116 -> V_45 ;
V_307 = V_311 -> V_95 ;
if ( V_311 -> V_324 ) {
F_94 ( & V_45 -> V_120 -> V_121 , V_307 -> V_325 ,
V_311 -> V_324 , V_326 ) ;
}
F_6 ( F_11 ( V_90 , V_45 , L_57 ,
V_91 , V_311 -> V_244 -> V_327 , V_315 ) ) ;
F_26 ( & V_45 -> V_120 -> V_121 , V_307 -> V_322 ,
V_307 -> V_318 , V_307 -> V_328 ) ;
F_26 ( & V_45 -> V_120 -> V_121 , V_307 -> V_331 ,
V_307 -> V_332 , V_307 -> V_333 ) ;
return;
}
static int F_95 ( struct V_310 * V_311 )
{
struct V_166 * V_167 = V_311 -> V_167 ;
struct V_112 * V_113 = V_311 -> V_244 -> V_168 ;
struct V_116 * V_116 = V_113 -> V_95 ;
struct V_44 * V_45 = V_116 -> V_45 ;
if ( ! V_167 )
return F_96 ( V_311 ) ;
F_11 ( V_90 , V_45 , L_58 ,
V_91 ) ;
return - V_47 ;
}
static void F_97 ( struct V_44 * V_45 ,
struct V_297 * V_262 ,
struct V_114 * V_115 ,
struct V_108 * V_109 )
{
int V_334 = 0 ;
struct V_112 * V_113 ;
struct V_243 * V_244 ;
char V_335 [ V_260 ] ;
V_200 V_263 = 0 ;
V_113 = V_115 -> V_95 ;
V_244 = V_109 -> V_95 ;
V_244 -> V_327 = V_336 *
F_98 ( V_262 -> V_337 ) ;
V_244 -> V_338 = V_336 *
F_98 ( V_262 -> V_339 ) ;
V_113 -> V_340 =
( V_341 & F_98 ( V_262 -> V_342 ) ) ;
V_113 -> V_343 = F_98 ( V_262 -> V_344 ) ;
V_113 -> V_345 = ( V_346 & F_98 ( V_262 -> V_342 ) ) ;
V_113 -> V_347 = V_336 *
F_98 ( V_262 -> V_348 ) ;
V_113 -> V_349 = V_336 *
F_98 ( V_262 -> V_350 ) ;
V_113 -> V_351 = F_98 ( V_262 -> V_352 ) ;
V_113 -> V_353 = F_98 ( V_262 -> V_354 ) ;
V_244 -> V_272 = F_98 ( V_262 -> V_355 ) ;
V_113 -> V_356 = F_25 ( V_262 -> V_357 ) ;
V_263 = F_98 ( V_262 -> V_263 ) ;
if ( V_263 & V_264 )
sprintf ( V_335 , L_40 , V_262 -> V_335 ) ;
else
sprintf ( V_335 , L_41 , V_262 -> V_335 ) ;
F_99 ( V_109 , V_13 ,
( char * ) V_262 -> V_358 , V_334 ) ;
F_99 ( V_109 , V_359 ,
( char * ) V_45 -> V_178 , V_334 ) ;
F_99 ( V_109 , V_9 ,
( char * ) V_335 , V_334 ) ;
}
void F_100 ( struct V_44 * V_45 ,
struct V_116 * V_116 )
{
struct V_114 * V_115 ;
struct V_108 * V_109 ;
T_3 V_360 ;
T_2 V_298 ;
struct V_297 * V_262 ;
V_262 = F_22 ( & V_45 -> V_120 -> V_121 , sizeof( * V_262 ) ,
& V_298 , V_122 ) ;
if ( ! V_262 ) {
F_11 ( V_93 , V_45 ,
L_48 , V_91 ) ;
goto V_361;
}
if ( F_101 ( V_45 , V_116 -> V_124 , V_262 ,
V_298 , NULL , NULL , & V_360 ,
NULL , NULL , NULL ) == V_252 ) {
F_6 ( F_11 ( V_93 , V_45 , L_59
L_60 ,
V_45 -> V_362 , V_91 ,
V_116 -> V_124 ) ) ;
goto V_361;
}
V_115 = V_116 -> V_113 ;
V_109 = V_116 -> V_244 ;
F_97 ( V_45 , V_262 , V_115 , V_109 ) ;
V_361:
if ( V_262 )
F_26 ( & V_45 -> V_120 -> V_121 , sizeof( * V_262 ) ,
V_262 , V_298 ) ;
}
void F_102 ( struct V_44 * V_45 ,
struct V_116 * V_116 )
{
struct V_114 * V_115 ;
struct V_108 * V_109 ;
struct V_112 * V_113 ;
struct V_243 * V_244 ;
T_3 V_360 ;
T_2 V_298 ;
struct V_297 * V_262 ;
V_262 = F_22 ( & V_45 -> V_120 -> V_121 , sizeof( * V_262 ) ,
& V_298 , V_122 ) ;
if ( ! V_262 ) {
F_11 ( V_93 , V_45 ,
L_48 , V_91 ) ;
goto V_363;
}
if ( F_101 ( V_45 , V_116 -> V_124 , V_262 ,
V_298 , NULL , NULL , & V_360 ,
NULL , NULL , NULL ) == V_252 ) {
F_6 ( F_11 ( V_93 , V_45 , L_59
L_60 ,
V_45 -> V_362 , V_91 ,
V_116 -> V_124 ) ) ;
goto V_363;
}
V_115 = V_116 -> V_113 ;
V_113 = V_115 -> V_95 ;
V_109 = V_116 -> V_244 ;
V_244 = V_109 -> V_95 ;
V_116 -> V_364 =
( F_98 ( V_262 -> V_365 ) > V_366 ) &&
( F_98 ( V_262 -> V_365 ) < V_366 * 10 ) ?
F_98 ( V_262 -> V_365 ) : V_366 ;
V_116 -> V_367 =
F_98 ( V_262 -> V_352 ) ;
V_244 -> V_327 = V_336 *
F_98 ( V_262 -> V_337 ) ;
V_244 -> V_338 = V_336 *
F_98 ( V_262 -> V_339 ) ;
V_113 -> V_340 =
( V_341 & F_98 ( V_262 -> V_342 ) ) ;
V_113 -> V_343 = F_98 ( V_262 -> V_344 ) ;
V_113 -> V_345 = ( V_346 & F_98 ( V_262 -> V_342 ) ) ;
V_113 -> V_347 = V_336 *
F_98 ( V_262 -> V_348 ) ;
V_113 -> V_349 = V_336 *
F_98 ( V_262 -> V_350 ) ;
V_113 -> V_351 = F_98 ( V_262 -> V_352 ) ;
V_113 -> V_353 = F_98 ( V_262 -> V_354 ) ;
V_113 -> V_356 = F_25 ( V_262 -> V_357 ) ;
memcpy ( V_113 -> V_368 , V_45 -> V_178 ,
F_103 ( sizeof( V_45 -> V_178 ) , sizeof( V_113 -> V_368 ) ) ) ;
V_363:
if ( V_262 )
F_26 ( & V_45 -> V_120 -> V_121 , sizeof( * V_262 ) ,
V_262 , V_298 ) ;
}
static void F_104 ( struct V_44 * V_45 , void * V_369 ,
unsigned long V_370 )
{
F_105 ( F_7 ( L_61 ,
V_91 , V_45 -> V_101 -> V_362 ) ) ;
F_106 ( & V_45 -> V_371 ) ;
V_45 -> V_371 . V_372 = V_373 + V_370 * V_242 ;
V_45 -> V_371 . V_226 = ( unsigned long ) V_45 ;
V_45 -> V_371 . V_374 = ( void (*) ( unsigned long ) ) V_369 ;
F_107 ( & V_45 -> V_371 ) ;
V_45 -> V_375 = 1 ;
}
static void F_108 ( struct V_44 * V_45 )
{
F_109 ( & V_45 -> V_371 ) ;
V_45 -> V_375 = 0 ;
}
void F_110 ( struct V_114 * V_293 )
{
F_111 ( V_293 ) ;
}
void F_112 ( struct V_44 * V_45 )
{
F_113 ( V_45 -> V_101 , F_110 ) ;
}
static struct V_376 * F_114 ( struct V_44 * V_45 ,
struct V_116 * V_116 ,
struct V_166 * V_377 )
{
struct V_376 * V_376 ;
V_376 = F_115 ( V_45 -> V_378 , V_329 ) ;
if ( ! V_376 )
return V_376 ;
F_116 ( & V_376 -> V_379 ) ;
V_376 -> V_45 = V_45 ;
V_376 -> V_380 = V_116 ;
V_376 -> V_377 = V_377 ;
V_376 -> V_104 = 0 ;
F_117 ( V_377 ) = ( void * ) V_376 ;
return V_376 ;
}
static void F_118 ( struct V_44 * V_45 , struct V_376 * V_376 )
{
struct V_166 * V_377 = V_376 -> V_377 ;
if ( V_376 -> V_104 & V_381 ) {
F_119 ( V_377 ) ;
V_376 -> V_104 &= ~ V_381 ;
}
F_117 ( V_377 ) = NULL ;
}
void F_120 ( struct V_382 * V_383 )
{
struct V_376 * V_376 = F_86 ( V_383 , struct V_376 , V_379 ) ;
struct V_166 * V_377 = V_376 -> V_377 ;
struct V_44 * V_45 = V_376 -> V_45 ;
F_118 ( V_45 , V_376 ) ;
F_121 ( V_376 , V_45 -> V_378 ) ;
V_377 -> V_384 ( V_377 ) ;
}
static int F_122 ( struct V_42 * V_101 , struct V_166 * V_377 )
{
struct V_44 * V_45 = F_4 ( V_101 ) ;
struct V_116 * V_116 = V_377 -> V_170 -> V_385 ;
struct V_114 * V_113 = V_116 -> V_113 ;
struct V_376 * V_376 ;
int V_227 ;
if ( F_14 ( V_386 , & V_45 -> V_104 ) ) {
if ( F_14 ( V_387 , & V_45 -> V_104 ) )
V_377 -> V_388 = V_389 << 16 ;
else
V_377 -> V_388 = V_390 << 16 ;
goto V_391;
}
if ( ! V_113 ) {
V_377 -> V_388 = V_392 << 16 ;
goto V_391;
}
V_227 = F_123 ( V_113 ) ;
if ( V_227 ) {
V_377 -> V_388 = V_227 ;
goto V_391;
}
if ( F_14 ( V_393 , & V_45 -> V_394 ) ||
F_14 ( V_395 , & V_45 -> V_394 ) ||
F_14 ( V_396 , & V_45 -> V_394 ) ||
F_14 ( V_397 , & V_45 -> V_394 ) ||
F_14 ( V_398 , & V_45 -> V_394 ) ||
! F_14 ( V_399 , & V_45 -> V_104 ) ||
! F_14 ( V_400 , & V_45 -> V_104 ) ||
F_14 ( V_401 , & V_45 -> V_394 ) )
goto V_402;
V_376 = F_114 ( V_45 , V_116 , V_377 ) ;
if ( ! V_376 )
goto V_402;
V_227 = F_124 ( V_45 , V_376 ) ;
if ( V_227 != V_125 )
goto V_403;
return 0 ;
V_403:
F_118 ( V_45 , V_376 ) ;
F_121 ( V_376 , V_45 -> V_378 ) ;
V_402:
return V_404 ;
V_391:
V_377 -> V_384 ( V_377 ) ;
return 0 ;
}
static void F_125 ( struct V_44 * V_45 )
{
if ( V_45 -> V_405 )
F_26 ( & V_45 -> V_120 -> V_121 , V_45 -> V_406 , V_45 -> V_405 ,
V_45 -> V_407 ) ;
V_45 -> V_406 = 0 ;
V_45 -> V_405 = NULL ;
V_45 -> V_407 = 0 ;
V_45 -> V_408 = NULL ;
V_45 -> V_409 = 0 ;
V_45 -> V_410 = NULL ;
V_45 -> V_411 = 0 ;
V_45 -> V_412 = NULL ;
V_45 -> V_413 = 0 ;
if ( V_45 -> V_378 )
F_126 ( V_45 -> V_378 ) ;
V_45 -> V_378 = NULL ;
if ( V_45 -> V_414 )
F_127 ( V_45 -> V_414 ) ;
if ( V_45 -> V_415 )
F_128 ( V_45 -> V_415 ) ;
V_45 -> V_415 = NULL ;
if ( V_45 -> V_416 )
F_127 ( V_45 -> V_416 ) ;
if ( F_129 ( V_45 ) ) {
if ( V_45 -> V_417 )
F_130 (
(struct V_418 V_419 * ) V_45 -> V_417 ) ;
} else if ( V_45 -> V_420 )
F_130 ( V_45 -> V_420 ) ;
F_131 ( V_45 -> V_120 ) ;
}
static int F_132 ( struct V_44 * V_45 )
{
unsigned long V_421 ;
V_45 -> V_406 = ( ( V_422 * V_423 ) +
( V_424 * V_423 ) +
sizeof( struct V_412 ) +
V_425 +
( V_426 - 1 ) ) & ~ ( V_426 - 1 ) ;
V_45 -> V_405 = F_22 ( & V_45 -> V_120 -> V_121 , V_45 -> V_406 ,
& V_45 -> V_407 , V_122 ) ;
if ( V_45 -> V_405 == NULL ) {
F_11 ( V_427 , V_45 ,
L_62 ) ;
goto V_428;
}
memset ( V_45 -> V_405 , 0 , V_45 -> V_406 ) ;
V_421 = 0 ;
if ( ( unsigned long ) V_45 -> V_407 & ( V_425 - 1 ) )
V_421 = V_425 - ( ( unsigned long ) V_45 -> V_407 &
( V_425 - 1 ) ) ;
V_45 -> V_409 = V_45 -> V_407 + V_421 ;
V_45 -> V_408 = (struct V_429 * ) ( V_45 -> V_405 + V_421 ) ;
V_45 -> V_411 = V_45 -> V_407 + V_421 +
( V_422 * V_423 ) ;
V_45 -> V_410 = (struct V_429 * ) ( V_45 -> V_405 + V_421 +
( V_422 *
V_423 ) ) ;
V_45 -> V_413 = V_45 -> V_407 + V_421 +
( V_422 * V_423 ) +
( V_424 * V_423 ) ;
V_45 -> V_412 = (struct V_412 * ) ( V_45 -> V_405 + V_421 +
( V_422 *
V_423 ) +
( V_424 *
V_423 ) ) ;
V_45 -> V_378 = F_133 ( V_430 , V_431 ,
V_432 , V_433 ) ;
if ( V_45 -> V_378 == NULL ) {
F_11 ( V_427 , V_45 ,
L_63 ) ;
goto V_428;
}
V_45 -> V_414 = F_134 ( L_64 , & V_45 -> V_120 -> V_121 ,
V_434 , 8 , 0 ) ;
if ( V_45 -> V_414 == NULL ) {
F_11 ( V_427 , V_45 ,
L_65 , V_91 ) ;
goto V_428;
}
V_45 -> V_416 = F_134 ( L_66 , & V_45 -> V_120 -> V_121 ,
V_435 , 8 , 0 ) ;
if ( V_45 -> V_416 == NULL ) {
F_11 ( V_427 , V_45 ,
L_67 ,
V_91 ) ;
goto V_428;
}
return V_125 ;
V_428:
F_125 ( V_45 ) ;
return V_252 ;
}
static int F_135 ( struct V_44 * V_45 )
{
T_3 V_436 , V_437 , V_438 ;
int V_261 = V_125 ;
V_436 = F_136 ( V_45 , V_439 ) ;
V_437 = F_137 ( V_436 ) ;
V_438 = F_138 ( V_436 ) ;
if ( V_437 == V_440 ) {
F_11 ( V_427 , V_45 , L_68
L_69
L_70 , V_438 ) ;
V_261 = V_252 ;
} else if ( V_437 == V_441 ) {
if ( V_45 -> V_442 == V_443 )
F_11 ( V_427 , V_45 , L_71
L_72
L_73 , V_438 ) ;
} else {
if ( V_45 -> V_442 == V_441 )
F_11 ( V_90 , V_45 , L_74
L_75 ,
V_438 ) ;
}
V_45 -> V_442 = V_437 ;
return V_261 ;
}
static int F_139 ( struct V_44 * V_45 )
{
T_3 V_444 ;
int V_261 = V_125 ;
V_444 = F_136 ( V_45 , V_445 ) ;
if ( V_444 == 0xffffffff ) {
F_6 ( F_7 ( V_427 L_76
L_77 ,
V_45 -> V_362 , V_91 ) ) ;
return V_261 ;
}
if ( V_45 -> V_444 == V_444 ) {
V_45 -> V_446 ++ ;
if ( V_45 -> V_446 == 2 ) {
V_45 -> V_446 = 0 ;
F_11 ( V_90 , V_45 ,
L_78
L_79
L_80
L_81
L_82 ,
V_45 -> V_362 , V_91 ,
F_136 ( V_45 ,
V_447 ) ,
F_136 ( V_45 ,
V_448 ) ,
F_136 ( V_45 , V_449 +
0x3c ) ,
F_136 ( V_45 , V_450 +
0x3c ) ,
F_136 ( V_45 , V_451 +
0x3c ) ,
F_136 ( V_45 , V_452 +
0x3c ) ,
F_136 ( V_45 , V_453 +
0x3c ) ) ;
V_261 = V_252 ;
}
} else
V_45 -> V_446 = 0 ;
V_45 -> V_444 = V_444 ;
return V_261 ;
}
void F_140 ( struct V_44 * V_45 )
{
T_3 V_454 , V_455 ;
if ( ! ( F_14 ( V_395 , & V_45 -> V_394 ) ||
F_14 ( V_396 , & V_45 -> V_394 ) ||
F_14 ( V_456 , & V_45 -> V_394 ) ) ) {
V_454 = F_136 ( V_45 , V_457 ) ;
if ( F_135 ( V_45 ) ) {
F_11 ( V_90 , V_45 , L_83
L_84 ) ;
F_141 ( V_45 , V_458 + 0x98 ,
V_459 |
V_460 ) ;
F_142 ( V_397 , & V_45 -> V_394 ) ;
F_143 ( V_45 ) ;
} else if ( V_454 == V_461 &&
! F_14 ( V_396 , & V_45 -> V_394 ) ) {
if ( ! V_462 ) {
F_11 ( V_90 , V_45 , L_85
L_86 , V_91 ) ;
F_142 ( V_396 , & V_45 -> V_394 ) ;
F_143 ( V_45 ) ;
}
} else if ( V_454 == V_463 &&
! F_14 ( V_398 , & V_45 -> V_394 ) ) {
F_11 ( V_90 , V_45 , L_87 ,
V_91 ) ;
F_142 ( V_398 , & V_45 -> V_394 ) ;
F_143 ( V_45 ) ;
} else {
if ( F_139 ( V_45 ) ) {
F_11 ( V_90 , V_45 , L_83
L_84 ) ;
F_141 ( V_45 , V_458 + 0x98 ,
V_459 |
V_460 ) ;
V_455 = F_136 ( V_45 ,
V_447 ) ;
if ( F_144 ( F_145 ( V_455 ) ) == 0x67 )
F_11 ( V_93 , V_45 , L_88
L_89
L_90
L_91 ,
V_91 ) ;
if ( V_455 & V_464 )
F_142 ( V_397 ,
& V_45 -> V_394 ) ;
else {
F_11 ( V_90 , V_45 , L_92
L_93 , V_91 ) ;
F_142 ( V_396 , & V_45 -> V_394 ) ;
}
F_146 ( V_45 ) ;
F_143 ( V_45 ) ;
}
}
}
}
static void F_147 ( struct V_114 * V_115 )
{
struct V_112 * V_113 ;
struct V_116 * V_116 ;
struct V_44 * V_45 ;
V_113 = V_115 -> V_95 ;
V_116 = V_113 -> V_95 ;
V_45 = V_116 -> V_45 ;
if ( ! ( V_116 -> V_275 == V_276 ) )
return;
if ( F_13 ( V_45 ) && ! F_14 ( V_465 , & V_116 -> V_104 ) &&
! F_148 ( V_115 ) ) {
if ( F_149 ( & V_116 -> V_466 ) !=
V_467 ) {
if ( F_149 ( & V_116 -> V_466 ) ==
0 ) {
F_150 ( & V_116 -> V_466 ,
V_467 ) ;
F_142 ( V_468 , & V_45 -> V_394 ) ;
F_142 ( V_465 , & V_116 -> V_104 ) ;
F_6 ( F_11 ( V_90 , V_45 ,
L_94 ,
V_91 , V_116 -> V_124 ) ) ;
} else
F_151 ( & V_116 -> V_466 ) ;
}
}
if ( F_149 ( & V_116 -> V_469 ) &&
( F_152 ( & V_116 -> V_469 ) != 0 ) ) {
if ( ! F_148 ( V_115 ) ) {
F_153 ( & V_116 -> V_470 ) ;
F_6 ( F_11 ( V_90 , V_45 ,
L_95
L_96 , V_91 ,
V_116 -> V_124 ,
F_149 ( & V_116 -> V_470 ) ,
V_116 -> V_367 + 4 ) ) ;
F_142 ( V_468 , & V_45 -> V_394 ) ;
F_150 ( & V_116 -> V_466 ,
V_116 -> V_367 + 4 ) ;
}
}
}
static void F_154 ( struct V_44 * V_45 )
{
int V_471 = 0 ;
V_200 V_472 ;
F_113 ( V_45 -> V_101 , F_147 ) ;
if ( F_14 ( V_386 , & V_45 -> V_104 ) ) {
F_155 ( & V_45 -> V_371 , V_373 + V_242 ) ;
return;
}
if ( ! F_156 ( V_45 -> V_120 ) )
F_157 ( V_45 -> V_120 , V_473 , & V_472 ) ;
if ( F_129 ( V_45 ) ) {
F_140 ( V_45 ) ;
}
if ( ! F_129 ( V_45 ) ) {
if ( V_45 -> V_474 & V_475 &&
V_45 -> V_476 != 0 ) {
V_45 -> V_446 ++ ;
if ( V_45 -> V_446 >
V_45 -> V_476 + 2 )
F_142 ( V_396 , & V_45 -> V_394 ) ;
}
}
if ( V_471 ||
F_14 ( V_396 , & V_45 -> V_394 ) ||
F_14 ( V_456 , & V_45 -> V_394 ) ||
F_14 ( V_468 , & V_45 -> V_394 ) ||
F_14 ( V_401 , & V_45 -> V_394 ) ||
F_14 ( V_393 , & V_45 -> V_394 ) ||
F_14 ( V_477 , & V_45 -> V_394 ) ||
F_14 ( V_478 , & V_45 -> V_394 ) ||
F_14 ( V_397 , & V_45 -> V_394 ) ||
F_14 ( V_398 , & V_45 -> V_394 ) ||
F_14 ( V_479 , & V_45 -> V_394 ) ) {
F_6 ( F_7 ( L_97
L_98 ,
V_45 -> V_362 , V_91 , V_45 -> V_394 ) ) ;
F_143 ( V_45 ) ;
}
F_155 ( & V_45 -> V_371 , V_373 + V_242 ) ;
F_6 ( V_45 -> V_480 ++ ) ;
}
static int F_158 ( struct V_44 * V_45 )
{
T_3 V_481 = 0 ;
unsigned long V_104 ;
struct V_166 * V_377 ;
unsigned long V_482 = V_373 + ( V_483 * V_242 ) ;
F_6 ( F_11 ( V_90 , V_45 , L_99
L_100 , V_483 ) ) ;
while ( ! F_159 ( V_373 , V_482 ) ) {
F_30 ( & V_45 -> V_291 , V_104 ) ;
for ( V_481 = 0 ; V_481 < V_45 -> V_101 -> V_484 ; V_481 ++ ) {
V_377 = F_160 ( V_45 -> V_101 , V_481 ) ;
if ( V_377 != NULL && F_117 ( V_377 ) )
break;
}
F_31 ( & V_45 -> V_291 , V_104 ) ;
if ( V_481 == V_45 -> V_101 -> V_484 )
return V_125 ;
F_161 ( 1000 ) ;
}
return V_252 ;
}
int F_162 ( struct V_44 * V_45 )
{
T_3 V_485 ;
unsigned long V_104 = 0 ;
F_6 ( F_7 ( V_93 L_101 , V_45 -> V_362 , V_91 ) ) ;
if ( F_163 ( V_45 ) != V_125 )
return V_252 ;
F_30 ( & V_45 -> V_291 , V_104 ) ;
V_485 = F_164 ( & V_45 -> V_420 -> V_485 ) ;
if ( ( V_485 & V_486 ) != 0 )
F_165 ( F_166 ( V_486 ) , & V_45 -> V_420 -> V_485 ) ;
F_165 ( F_166 ( V_487 ) , & V_45 -> V_420 -> V_485 ) ;
F_167 ( & V_45 -> V_420 -> V_485 ) ;
F_31 ( & V_45 -> V_291 , V_104 ) ;
return V_125 ;
}
int F_168 ( struct V_44 * V_45 )
{
T_3 V_488 ;
unsigned long V_104 = 0 ;
int V_261 ;
T_3 V_485 ;
V_261 = F_162 ( V_45 ) ;
if ( V_261 != V_125 )
return V_261 ;
V_261 = V_252 ;
V_488 = V_489 ;
do {
F_30 ( & V_45 -> V_291 , V_104 ) ;
V_485 = F_164 ( & V_45 -> V_420 -> V_485 ) ;
F_31 ( & V_45 -> V_291 , V_104 ) ;
if ( ( V_485 & V_490 ) == 0 )
break;
F_161 ( 1000 ) ;
} while ( ( -- V_488 ) );
if ( ( V_485 & V_490 ) != 0 ) {
F_6 ( F_7 ( V_427
L_102
L_103 ,
V_45 -> V_362 ) ) ;
F_30 ( & V_45 -> V_291 , V_104 ) ;
F_165 ( F_166 ( V_490 ) , & V_45 -> V_420 -> V_485 ) ;
F_167 ( & V_45 -> V_420 -> V_485 ) ;
F_31 ( & V_45 -> V_291 , V_104 ) ;
}
V_488 = V_491 ;
do {
F_30 ( & V_45 -> V_291 , V_104 ) ;
V_485 = F_164 ( & V_45 -> V_420 -> V_485 ) ;
F_31 ( & V_45 -> V_291 , V_104 ) ;
if ( ( V_485 & V_487 ) == 0 ) {
V_261 = V_125 ;
break;
}
F_161 ( 1000 ) ;
} while ( ( -- V_488 ) );
F_30 ( & V_45 -> V_291 , V_104 ) ;
V_485 = F_164 ( & V_45 -> V_420 -> V_485 ) ;
if ( ( V_485 & V_486 ) != 0 ) {
F_165 ( F_166 ( V_486 ) , & V_45 -> V_420 -> V_485 ) ;
F_167 ( & V_45 -> V_420 -> V_485 ) ;
}
F_31 ( & V_45 -> V_291 , V_104 ) ;
if ( V_488 == 0 ) {
F_30 ( & V_45 -> V_291 , V_104 ) ;
F_165 ( F_166 ( V_492 ) , & V_45 -> V_420 -> V_485 ) ;
F_167 ( & V_45 -> V_420 -> V_485 ) ;
F_31 ( & V_45 -> V_291 , V_104 ) ;
V_488 = V_491 ;
do {
F_30 ( & V_45 -> V_291 , V_104 ) ;
V_485 = F_164 ( & V_45 -> V_420 -> V_485 ) ;
F_31 ( & V_45 -> V_291 , V_104 ) ;
if ( ( V_485 & V_492 ) == 0 ) {
V_261 = V_125 ;
break;
}
F_161 ( 1000 ) ;
} while ( ( -- V_488 ) );
}
return V_261 ;
}
static void F_169 ( struct V_44 * V_45 , int V_493 )
{
struct V_376 * V_376 ;
int V_494 ;
unsigned long V_104 ;
F_30 ( & V_45 -> V_291 , V_104 ) ;
for ( V_494 = 0 ; V_494 < V_45 -> V_101 -> V_484 ; V_494 ++ ) {
V_376 = F_170 ( V_45 , V_494 ) ;
if ( V_376 != NULL ) {
V_376 -> V_377 -> V_388 = V_493 ;
F_171 ( & V_376 -> V_379 , F_120 ) ;
}
}
F_31 ( & V_45 -> V_291 , V_104 ) ;
}
void F_172 ( struct V_44 * V_45 )
{
F_173 ( V_399 , & V_45 -> V_104 ) ;
F_11 ( V_90 , V_45 , L_104 ) ;
F_169 ( V_45 , V_389 << 16 ) ;
F_112 ( V_45 ) ;
F_173 ( V_495 , & V_45 -> V_104 ) ;
}
static void F_174 ( struct V_114 * V_293 )
{
struct V_112 * V_113 ;
struct V_116 * V_116 ;
V_113 = V_293 -> V_95 ;
V_116 = V_113 -> V_95 ;
V_116 -> V_281 = V_496 ;
if ( V_116 -> V_275 == V_276 )
F_111 ( V_116 -> V_113 ) ;
else
F_175 ( V_293 -> V_95 ,
V_497 ) ;
}
static int F_176 ( struct V_44 * V_45 )
{
int V_261 = V_252 ;
T_4 V_498 = 0 ;
T_3 V_454 ;
unsigned long V_499 ;
F_177 ( V_45 -> V_101 ) ;
F_173 ( V_399 , & V_45 -> V_104 ) ;
F_173 ( V_400 , & V_45 -> V_104 ) ;
F_6 ( F_11 ( V_90 , V_45 , L_105 , V_91 ) ) ;
F_142 ( V_395 , & V_45 -> V_394 ) ;
F_113 ( V_45 -> V_101 , F_174 ) ;
if ( F_14 ( V_396 , & V_45 -> V_394 ) )
V_498 = 1 ;
if ( F_14 ( V_393 , & V_45 -> V_394 ) ) {
V_261 = V_125 ;
goto V_500;
}
if ( F_129 ( V_45 ) && ! V_498 &&
F_14 ( V_401 , & V_45 -> V_394 ) ) {
F_6 ( F_11 ( V_90 , V_45 ,
L_106 ,
V_45 -> V_362 , V_91 ) ) ;
V_261 = V_45 -> V_501 -> V_502 ( V_45 ) ;
if ( V_261 == V_125 ) {
if ( ! F_14 ( V_503 , & V_45 -> V_104 ) )
F_158 ( V_45 ) ;
V_45 -> V_501 -> V_504 ( V_45 ) ;
F_178 ( V_45 , V_505 ) ;
F_169 ( V_45 , V_506 << 16 ) ;
} else {
V_498 = 1 ;
F_173 ( V_401 , & V_45 -> V_394 ) ;
F_142 ( V_396 , & V_45 -> V_394 ) ;
}
}
if ( ! F_129 ( V_45 ) || V_498 ) {
if ( ! F_129 ( V_45 ) )
goto V_507;
if ( F_14 ( V_503 , & V_45 -> V_104 ) )
goto V_507;
V_499 = V_373 + ( V_508 * V_242 ) ;
while ( F_179 ( V_373 , V_499 ) ) {
if ( F_139 ( V_45 ) ) {
F_146 ( V_45 ) ;
break;
}
F_180 ( V_509 ) ;
F_181 ( V_242 ) ;
}
if ( ! F_14 ( V_503 , & V_45 -> V_104 ) )
F_158 ( V_45 ) ;
V_507:
F_178 ( V_45 , V_505 ) ;
F_169 ( V_45 , V_506 << 16 ) ;
F_6 ( F_11 ( V_90 , V_45 ,
L_107 ,
V_45 -> V_362 , V_91 ) ) ;
V_261 = V_45 -> V_501 -> V_498 ( V_45 ) ;
}
F_178 ( V_45 , V_505 ) ;
V_500:
if ( V_261 == V_125 ) {
if ( ! F_129 ( V_45 ) && ( V_45 -> V_510 == 3 ) )
F_182 ( 6 ) ;
V_261 = F_183 ( V_45 , V_511 ) ;
}
if ( ! F_14 ( V_399 , & V_45 -> V_104 ) &&
! F_14 ( V_393 , & V_45 -> V_394 ) ) {
if ( F_129 ( V_45 ) ) {
F_184 ( V_45 ) ;
V_454 = F_136 ( V_45 , V_457 ) ;
F_185 ( V_45 ) ;
if ( V_454 == V_512 ) {
F_11 ( V_90 , V_45 , L_108
L_109
L_110 , V_91 ) ;
F_172 ( V_45 ) ;
F_173 ( V_456 , & V_45 -> V_394 ) ;
F_173 ( V_396 , & V_45 -> V_394 ) ;
F_173 ( V_401 ,
& V_45 -> V_394 ) ;
V_261 = V_252 ;
goto V_513;
}
}
if ( ! F_14 ( V_456 , & V_45 -> V_394 ) ) {
V_45 -> V_514 = V_515 ;
F_6 ( F_7 ( L_111
L_112 , V_45 -> V_362 ,
V_45 -> V_514 ) ) ;
F_142 ( V_456 , & V_45 -> V_394 ) ;
V_261 = V_252 ;
} else {
if ( V_45 -> V_514 > 0 ) {
V_45 -> V_514 -- ;
F_6 ( F_7 ( L_113
L_114 ,
V_45 -> V_362 ,
V_45 -> V_514 ) ) ;
V_261 = V_252 ;
}
if ( V_45 -> V_514 == 0 ) {
F_6 ( F_7 ( L_115
L_116 ,
V_45 -> V_362 ) ) ;
F_172 ( V_45 ) ;
F_173 ( V_456 , & V_45 -> V_394 ) ;
F_173 ( V_396 , & V_45 -> V_394 ) ;
F_173 ( V_401 ,
& V_45 -> V_394 ) ;
V_261 = V_252 ;
}
}
} else {
F_173 ( V_396 , & V_45 -> V_394 ) ;
F_173 ( V_401 , & V_45 -> V_394 ) ;
F_173 ( V_456 , & V_45 -> V_394 ) ;
}
V_513:
V_45 -> V_516 ++ ;
if ( F_14 ( V_399 , & V_45 -> V_104 ) )
V_45 -> V_501 -> V_517 ( V_45 ) ;
F_186 ( V_45 -> V_101 ) ;
F_173 ( V_395 , & V_45 -> V_394 ) ;
F_6 ( F_7 ( L_117 , V_45 -> V_362 ,
V_261 == V_252 ? L_118 : L_119 ) ) ;
return V_261 ;
}
static void F_187 ( struct V_114 * V_293 )
{
struct V_112 * V_113 ;
struct V_116 * V_116 ;
struct V_44 * V_45 ;
V_113 = V_293 -> V_95 ;
V_116 = V_113 -> V_95 ;
V_45 = V_116 -> V_45 ;
if ( ! F_148 ( V_293 ) ) {
if ( V_116 -> V_281 == V_301 ) {
F_11 ( V_90 , V_45 , L_120
L_121 , V_45 -> V_362 , V_91 ,
V_116 -> V_124 ) ;
F_188 ( V_116 -> V_113 ) ;
} else {
if ( V_116 -> V_275 == V_276 ) {
if ( ! F_14 ( V_465 , & V_116 -> V_104 ) )
F_189 ( V_116 ) ;
} else
F_175 ( V_293 -> V_95 ,
V_497 ) ;
}
}
}
int F_190 ( struct V_114 * V_293 )
{
struct V_112 * V_113 ;
struct V_116 * V_116 ;
struct V_44 * V_45 ;
V_113 = V_293 -> V_95 ;
V_116 = V_113 -> V_95 ;
V_45 = V_116 -> V_45 ;
F_11 ( V_90 , V_45 , L_120
L_121 , V_45 -> V_362 , V_91 ,
V_116 -> V_124 ) ;
F_188 ( V_116 -> V_113 ) ;
if ( F_14 ( V_399 , & V_45 -> V_104 ) ) {
F_11 ( V_90 , V_45 , L_120
L_122 , V_45 -> V_362 , V_91 ,
V_116 -> V_124 ) ;
F_191 ( V_45 -> V_101 , & V_116 -> V_113 -> V_518 ) ;
}
return V_125 ;
}
int V_284 ( struct V_114 * V_293 )
{
struct V_112 * V_113 ;
struct V_116 * V_116 ;
struct V_44 * V_45 ;
V_113 = V_293 -> V_95 ;
V_116 = V_113 -> V_95 ;
V_45 = V_116 -> V_45 ;
F_11 ( V_90 , V_45 , L_120
L_123 , V_45 -> V_362 , V_91 ,
V_116 -> V_124 ) ;
F_192 ( V_116 -> V_244 ) ;
F_193 ( V_116 -> V_244 ,
V_519 ) ;
return V_125 ;
}
static void F_194 ( struct V_44 * V_45 )
{
F_113 ( V_45 -> V_101 , F_187 ) ;
}
static void F_195 ( struct V_114 * V_115 )
{
V_200 V_469 ;
struct V_112 * V_113 ;
struct V_116 * V_116 ;
struct V_44 * V_45 ;
V_113 = V_115 -> V_95 ;
V_116 = V_113 -> V_95 ;
V_45 = V_116 -> V_45 ;
V_469 = F_196 ( V_116 -> V_364 ,
( V_200 ) V_520 ) ;
F_150 ( & V_116 -> V_469 , V_469 ) ;
F_6 ( F_11 ( V_90 , V_45 ,
L_124 , V_45 -> V_362 ,
V_116 -> V_124 , V_469 ) ) ;
F_197 ( V_115 ) ;
}
static void F_198 ( struct V_114 * V_115 )
{
struct V_112 * V_113 ;
struct V_116 * V_116 ;
struct V_44 * V_45 ;
V_113 = V_115 -> V_95 ;
V_116 = V_113 -> V_95 ;
V_45 = V_116 -> V_45 ;
if ( ! ( V_116 -> V_275 == V_276 ) )
return;
if ( F_199 ( V_465 , & V_116 -> V_104 ) &&
! F_148 ( V_115 ) ) {
F_6 ( F_11 ( V_90 , V_45 ,
L_125 ) ) ;
F_195 ( V_115 ) ;
}
}
void F_143 ( struct V_44 * V_45 )
{
if ( V_45 -> V_521 )
F_200 ( V_45 -> V_521 , & V_45 -> V_522 ) ;
}
static void F_201 ( struct V_305 * V_523 )
{
struct V_44 * V_45 =
F_86 ( V_523 , struct V_44 , V_522 ) ;
int V_261 = V_252 ;
F_6 (printk(L_126
L_127,
ha->host_no, __func__, ha->flags, ha->dpc_flags))
if ( ! F_14 ( V_495 , & V_45 -> V_104 ) )
return;
if ( F_14 ( V_386 , & V_45 -> V_104 ) ) {
F_6 ( F_7 ( V_90 L_128 ,
V_45 -> V_362 , V_91 , V_45 -> V_104 ) ) ;
return;
}
if ( F_129 ( V_45 ) ) {
if ( F_14 ( V_397 , & V_45 -> V_394 ) ) {
F_184 ( V_45 ) ;
F_141 ( V_45 , V_457 ,
V_512 ) ;
F_185 ( V_45 ) ;
F_11 ( V_90 , V_45 , L_129 ) ;
F_202 ( V_45 ) ;
}
if ( F_199 ( V_398 , & V_45 -> V_394 ) ) {
F_203 ( V_45 ) ;
}
}
if ( ! F_14 ( V_395 , & V_45 -> V_394 ) &&
( F_14 ( V_396 , & V_45 -> V_394 ) ||
F_14 ( V_393 , & V_45 -> V_394 ) ||
F_14 ( V_401 , & V_45 -> V_394 ) ) ) {
if ( V_462 ) {
F_6 ( F_7 ( L_130 ,
V_45 -> V_362 , V_91 ) ) ;
F_173 ( V_396 , & V_45 -> V_394 ) ;
F_173 ( V_393 , & V_45 -> V_394 ) ;
F_173 ( V_401 , & V_45 -> V_394 ) ;
goto V_524;
}
if ( F_14 ( V_401 , & V_45 -> V_394 ) ||
F_14 ( V_396 , & V_45 -> V_394 ) )
F_176 ( V_45 ) ;
if ( F_14 ( V_393 , & V_45 -> V_394 ) ) {
T_4 V_525 = V_489 ;
while ( ( F_164 ( & V_45 -> V_420 -> V_485 ) &
( V_487 | V_492 ) ) != 0 ) {
if ( -- V_525 == 0 )
break;
F_161 ( 1000 ) ;
}
if ( V_525 == 0 )
F_6 ( F_7 ( L_131
L_132 ,
V_45 -> V_362 , V_91 ) ) ;
F_169 ( V_45 , V_506 << 16 ) ;
if ( F_163 ( V_45 ) == V_125 ) {
F_178 ( V_45 , V_505 ) ;
V_261 = F_176 ( V_45 ) ;
}
F_173 ( V_393 , & V_45 -> V_394 ) ;
if ( V_261 == V_125 )
V_45 -> V_501 -> V_517 ( V_45 ) ;
}
}
V_524:
if ( F_199 ( V_479 , & V_45 -> V_394 ) )
F_178 ( V_45 , V_526 ) ;
if ( F_199 ( V_477 , & V_45 -> V_394 ) )
F_204 ( V_45 ) ;
if ( F_13 ( V_45 ) &&
F_199 ( V_468 , & V_45 -> V_394 ) ) {
F_113 ( V_45 -> V_101 , F_198 ) ;
}
if ( F_199 ( V_478 , & V_45 -> V_394 ) ) {
if ( ! F_14 ( V_400 , & V_45 -> V_104 ) ) {
F_112 ( V_45 ) ;
} else {
if ( F_199 ( V_103 , & V_45 -> V_104 ) ) {
F_205 ( V_45 , V_45 -> V_527 ) ;
F_113 ( V_45 -> V_101 ,
F_197 ) ;
} else
F_194 ( V_45 ) ;
}
}
}
static void F_206 ( struct V_44 * V_45 )
{
F_169 ( V_45 , V_389 << 16 ) ;
if ( F_14 ( V_528 , & V_45 -> V_104 ) ) {
V_45 -> V_501 -> V_504 ( V_45 ) ;
}
if ( V_45 -> V_375 )
F_108 ( V_45 ) ;
if ( V_45 -> V_521 )
F_207 ( V_45 -> V_521 ) ;
if ( V_45 -> V_529 )
F_207 ( V_45 -> V_529 ) ;
V_45 -> V_501 -> V_502 ( V_45 ) ;
if ( F_129 ( V_45 ) ) {
F_184 ( V_45 ) ;
F_208 ( V_45 ) ;
F_185 ( V_45 ) ;
}
if ( F_199 ( V_530 , & V_45 -> V_104 ) )
F_209 ( V_45 ) ;
F_125 ( V_45 ) ;
}
int F_210 ( struct V_44 * V_45 )
{
int V_261 = 0 ;
T_4 V_531 ;
unsigned long V_532 , V_533 , V_534 , V_535 ;
struct V_536 * V_120 = V_45 -> V_120 ;
V_261 = F_211 ( V_120 , V_537 ) ;
if ( V_261 ) {
F_7 ( V_427
L_133
L_134 , V_45 -> V_362 , F_212 ( V_120 ) , V_261 ) ;
goto V_538;
}
F_213 ( V_120 , V_539 , & V_531 ) ;
F_6 ( F_7 ( V_90 L_135 ,
V_91 , V_531 ) ) ;
V_45 -> V_531 = V_531 ;
V_532 = F_214 ( V_120 , 0 ) ;
V_533 = F_215 ( V_120 , 0 ) ;
F_6 ( F_7 ( V_90 L_136 ,
V_91 , V_532 , V_533 ) ) ;
V_45 -> V_417 = ( unsigned long ) F_216 ( V_532 , V_533 ) ;
if ( ! V_45 -> V_417 ) {
F_7 ( V_93
L_137 , F_212 ( V_120 ) ) ;
F_131 ( V_45 -> V_120 ) ;
goto V_538;
}
V_45 -> V_540 =
(struct V_418 V_419 * ) ( ( T_4 * ) V_45 -> V_417 +
0xbc000 + ( V_45 -> V_120 -> V_541 << 11 ) ) ;
V_534 = F_214 ( V_120 , 4 ) ;
V_535 = F_215 ( V_120 , 4 ) ;
V_45 -> V_542 = ( V_45 -> V_120 -> V_541 == 4 ? V_543 :
V_544 ) ;
return 0 ;
V_538:
return - V_94 ;
}
int F_217 ( struct V_44 * V_45 )
{
unsigned long V_545 , V_546 , V_547 ;
unsigned long V_548 , V_549 , V_550 ;
V_545 = F_214 ( V_45 -> V_120 , 0 ) ;
V_546 = F_215 ( V_45 -> V_120 , 0 ) ;
V_547 = F_218 ( V_45 -> V_120 , 0 ) ;
if ( V_547 & V_551 ) {
if ( V_546 < V_552 ) {
F_11 ( V_427 , V_45 ,
L_138 ) ;
V_545 = 0 ;
}
} else {
F_11 ( V_427 , V_45 , L_139 ) ;
V_545 = 0 ;
}
V_548 = F_214 ( V_45 -> V_120 , 1 ) ;
V_549 = F_215 ( V_45 -> V_120 , 1 ) ;
V_550 = F_218 ( V_45 -> V_120 , 1 ) ;
if ( ! ( V_550 & V_553 ) ) {
F_11 ( V_93 , V_45 ,
L_140 ) ;
goto V_538;
}
if ( V_549 < V_552 ) {
F_11 ( V_93 , V_45 ,
L_141 ) ;
goto V_538;
}
if ( F_211 ( V_45 -> V_120 , V_537 ) ) {
F_11 ( V_427 , V_45 ,
L_142 ) ;
goto V_538;
}
V_45 -> V_554 = V_545 ;
V_45 -> V_555 = V_546 ;
V_45 -> V_420 = F_216 ( V_548 , V_552 ) ;
if ( ! V_45 -> V_420 ) {
F_11 ( V_93 , V_45 ,
L_143 ) ;
goto V_538;
}
return 0 ;
V_538:
return - V_94 ;
}
V_200 F_219 ( struct V_44 * V_45 )
{
return ( V_200 ) F_25 ( V_45 -> V_412 -> V_556 ) ;
}
V_200 F_220 ( struct V_44 * V_45 )
{
return ( V_200 ) F_25 ( F_167 ( & V_45 -> V_540 -> V_556 ) ) ;
}
V_200 F_221 ( struct V_44 * V_45 )
{
return ( V_200 ) F_25 ( V_45 -> V_412 -> V_557 ) ;
}
V_200 F_222 ( struct V_44 * V_45 )
{
return ( V_200 ) F_25 ( F_167 ( & V_45 -> V_540 -> V_557 ) ) ;
}
static T_7 F_223 ( void * V_226 , int type , char * V_41 )
{
struct V_44 * V_45 = V_226 ;
char * V_558 = V_41 ;
int V_559 ;
switch ( type ) {
case V_560 :
V_559 = sprintf ( V_558 , L_10 , V_561 ) ;
break;
case V_562 :
V_559 = sprintf ( V_558 , L_144 ) ;
break;
case V_563 :
V_559 = F_33 ( V_558 , V_45 -> V_176 ,
V_177 ) ;
break;
default:
V_559 = - V_47 ;
break;
}
return V_559 ;
}
static T_1 F_224 ( void * V_226 , int type )
{
int V_559 ;
switch ( type ) {
case V_560 :
case V_563 :
case V_562 :
V_559 = V_7 ;
break;
default:
V_559 = 0 ;
break;
}
return V_559 ;
}
static T_7 F_225 ( void * V_226 , int type , char * V_41 )
{
struct V_44 * V_45 = V_226 ;
char * V_558 = V_41 ;
int V_559 ;
switch ( type ) {
case V_564 :
V_559 = sprintf ( V_558 , L_2 , V_45 -> V_178 ) ;
break;
default:
V_559 = - V_47 ;
break;
}
return V_559 ;
}
static T_1 F_226 ( void * V_226 , int type )
{
int V_559 ;
switch ( type ) {
case V_564 :
V_559 = V_7 ;
break;
default:
V_559 = 0 ;
break;
}
return V_559 ;
}
static T_7
F_227 ( struct V_565 * V_566 , int type ,
char * V_41 )
{
struct V_567 * V_568 = & V_566 -> V_569 [ 0 ] ;
char * V_558 = V_41 ;
int V_559 ;
switch ( type ) {
case V_570 :
V_559 = sprintf ( V_41 , L_2 , ( char * ) & V_566 -> V_571 ) ;
break;
case V_572 :
if ( V_566 -> V_569 [ 0 ] . V_573 . V_574 == 0x1 )
V_559 = sprintf ( V_41 , L_1 ,
& V_568 -> V_573 . V_49 ) ;
else
V_559 = sprintf ( V_558 , L_7 ,
& V_568 -> V_573 . V_49 ) ;
break;
case V_575 :
V_559 = sprintf ( V_558 , L_10 , V_568 -> V_576 ) ;
break;
case V_577 :
V_559 = sprintf ( V_558 , L_145 ,
V_568 -> V_578 . V_579 ,
( char * ) & V_568 -> V_578 . V_580 ) ;
break;
case V_581 :
V_559 = sprintf ( V_558 , L_145 ,
V_568 -> V_578 . V_582 ,
( char * ) & V_568 -> V_578 . V_583 ) ;
break;
case V_584 :
V_559 = sprintf ( V_558 , L_145 ,
V_568 -> V_578 . V_585 ,
( char * ) & V_568 -> V_578 . V_586 ) ;
break;
case V_587 :
V_559 = sprintf ( V_558 , L_145 ,
V_568 -> V_578 . V_588 ,
( char * ) & V_568 -> V_578 . V_589 ) ;
break;
case V_590 :
V_559 = sprintf ( V_558 , L_10 , V_561 ) ;
break;
case V_591 :
V_559 = sprintf ( V_558 , L_144 ) ;
break;
default:
V_559 = - V_47 ;
break;
}
return V_559 ;
}
static T_7 F_228 ( void * V_226 , int type , char * V_41 )
{
struct V_44 * V_45 = V_226 ;
struct V_565 * V_566 = & ( V_45 -> V_592 . V_593 ) ;
return F_227 ( V_566 , type , V_41 ) ;
}
static T_7 F_229 ( void * V_226 , int type , char * V_41 )
{
struct V_44 * V_45 = V_226 ;
struct V_565 * V_566 = & ( V_45 -> V_592 . V_594 ) ;
return F_227 ( V_566 , type , V_41 ) ;
}
static T_1 F_230 ( void * V_226 , int type )
{
int V_559 ;
switch ( type ) {
case V_570 :
case V_572 :
case V_575 :
case V_577 :
case V_581 :
case V_584 :
case V_587 :
case V_591 :
case V_590 :
V_559 = V_7 ;
break;
default:
V_559 = 0 ;
break;
}
return V_559 ;
}
static void F_231 ( void * V_226 )
{
struct V_44 * V_45 = V_226 ;
F_232 ( V_45 -> V_101 ) ;
}
static int F_233 ( struct V_44 * V_45 , V_200 V_246 [] )
{
T_2 V_595 ;
T_3 V_87 , V_596 , V_597 ;
T_3 V_598 ;
V_200 V_599 ;
T_4 V_600 ;
T_4 * V_41 = NULL ;
T_8 V_601 = 13 * sizeof( T_4 ) ;
int V_82 = V_125 ;
V_599 = F_234 ( V_45 -> V_120 -> V_541 ) ;
F_11 ( V_90 , V_45 , L_146 ,
V_91 , V_45 -> V_120 -> V_170 , V_599 ) ;
if ( F_67 ( V_45 ) ) {
if ( V_599 == 1 ) {
V_87 = V_602 ;
V_596 = V_603 ;
V_597 = V_604 ;
} else if ( V_599 == 3 ) {
V_87 = V_605 ;
V_596 = V_606 ;
V_597 = V_607 ;
} else {
V_82 = V_252 ;
goto V_608;
}
V_600 = F_235 ( V_45 , V_87 ) ;
if ( ! ( V_600 & 0x07 ) ) {
F_6 ( F_11 ( V_93 , V_45 ,
L_147 ,
V_91 , V_600 ) ) ;
V_82 = V_252 ;
goto V_608;
}
V_600 = F_235 ( V_45 , V_596 ) ;
if ( V_600 & V_609 )
V_246 [ 0 ] = ( V_600 & 0x7f ) ;
V_600 = F_235 ( V_45 , V_597 ) ;
if ( V_600 & V_609 )
V_246 [ 1 ] = ( V_600 & 0x7f ) ;
} else if ( F_129 ( V_45 ) ) {
V_41 = F_22 ( & V_45 -> V_120 -> V_121 , V_601 ,
& V_595 , V_122 ) ;
if ( ! V_41 ) {
F_6 ( F_11 ( V_93 , V_45 ,
L_48 ,
V_91 ) ) ;
V_82 = V_252 ;
goto V_608;
}
if ( V_45 -> V_610 == 0 )
V_598 = V_611 ;
else if ( V_45 -> V_610 == 1 )
V_598 = V_612 ;
else {
V_82 = V_252 ;
goto V_613;
}
V_87 = V_614 + ( V_45 -> V_615 . V_616 * 4 ) +
V_598 ;
if ( F_236 ( V_45 , V_595 , V_87 ,
13 * sizeof( T_4 ) ) != V_125 ) {
F_6 ( F_11 ( V_93 , V_45 , L_148
L_149 , V_45 -> V_362 , V_91 ) ) ;
V_82 = V_252 ;
goto V_613;
}
if ( ! ( V_41 [ 1 ] & 0x07 ) ) {
F_6 ( F_11 ( V_90 , V_45 ,
L_150 ,
V_41 [ 1 ] ) ) ;
V_82 = V_252 ;
goto V_613;
}
if ( V_41 [ 2 ] & V_609 )
V_246 [ 0 ] = V_41 [ 2 ] & 0x7f ;
if ( V_41 [ 11 ] & V_609 )
V_246 [ 1 ] = V_41 [ 11 ] & 0x7f ;
} else {
V_82 = V_252 ;
goto V_608;
}
F_6 ( F_11 ( V_90 , V_45 , L_151
L_152 , V_91 , V_246 [ 0 ] ,
V_246 [ 1 ] ) ) ;
V_45 -> V_617 = V_246 [ 0 ] ;
V_45 -> V_618 = V_246 [ 1 ] ;
V_613:
F_26 ( & V_45 -> V_120 -> V_121 , V_601 , V_41 , V_595 ) ;
V_608:
return V_82 ;
}
static int F_237 ( struct V_44 * V_45 , char * V_619 ,
char * V_620 )
{
int V_494 , V_82 = - V_296 ;
int V_621 = 0 ;
struct V_622 * V_623 ;
if ( F_129 ( V_45 ) )
V_621 = ( V_45 -> V_615 . V_624 / 2 ) /
sizeof( struct V_622 ) ;
else
V_621 = V_625 ;
if ( ! V_45 -> V_415 ) {
F_11 ( V_93 , V_45 , L_153 ) ;
return V_82 ;
}
F_238 ( & V_45 -> V_626 ) ;
for ( V_494 = 0 ; V_494 < V_621 ; V_494 ++ ) {
V_623 = (struct V_622 * ) V_45 -> V_415 + V_494 ;
if ( V_623 -> V_237 !=
F_239 ( V_627 ) ) {
continue;
}
if ( V_623 -> V_104 & V_609 )
continue;
if ( ! ( V_623 -> V_104 & V_628 ) )
continue;
strncpy ( V_620 , V_623 -> V_629 , V_630 ) ;
strncpy ( V_619 , V_623 -> V_631 , V_632 ) ;
V_82 = 0 ;
break;
}
F_240 ( & V_45 -> V_626 ) ;
return V_82 ;
}
static int F_241 ( struct V_44 * V_45 ,
struct V_565 * V_566 ,
V_200 V_246 )
{
struct V_567 * V_568 = & V_566 -> V_569 [ 0 ] ;
struct V_297 * V_262 ;
T_2 V_298 ;
V_200 V_266 ;
V_200 V_263 ;
int V_82 = V_125 ;
V_262 = F_22 ( & V_45 -> V_120 -> V_121 , sizeof( * V_262 ) ,
& V_298 , V_122 ) ;
if ( ! V_262 ) {
F_6 ( F_11 ( V_93 , V_45 ,
L_154 ,
V_91 ) ) ;
V_82 = V_252 ;
return V_82 ;
}
if ( F_242 ( V_45 , V_262 ,
V_298 , V_246 ) ) {
F_6 ( F_11 ( V_93 , V_45 ,
L_155 , V_91 ) ) ;
V_82 = V_252 ;
goto V_633;
}
memcpy ( V_566 -> V_571 , V_262 -> V_358 ,
F_103 ( sizeof( V_566 -> V_571 ) ,
sizeof( V_262 -> V_358 ) ) ) ;
V_263 = F_98 ( V_262 -> V_263 ) ;
if ( V_263 & V_264 ) {
memcpy ( & V_568 -> V_573 . V_49 ,
& V_262 -> V_335 [ 0 ] , V_258 ) ;
} else {
V_568 -> V_573 . V_574 = 0x1 ;
memcpy ( & V_568 -> V_573 . V_49 ,
& V_262 -> V_335 [ 0 ] , V_634 ) ;
}
V_568 -> V_576 = F_98 ( V_262 -> V_355 ) ;
V_266 = F_243 ( V_262 -> V_635 ) ;
if ( V_609 & F_98 ( V_262 -> V_342 ) ) {
F_6 ( F_11 ( V_90 , V_45 , L_156 ) ) ;
V_82 = F_244 ( V_45 , ( char * ) & V_568 -> V_578 .
V_580 ,
( char * ) & V_568 -> V_578 . V_583 ,
V_266 ) ;
if ( V_82 ) {
F_11 ( V_93 , V_45 , L_157 ) ;
V_82 = V_252 ;
goto V_633;
}
V_568 -> V_578 . V_579 = V_632 ;
V_568 -> V_578 . V_582 = V_630 ;
}
if ( V_636 & F_98 ( V_262 -> V_342 ) ) {
F_6 ( F_11 ( V_90 , V_45 , L_158 ) ) ;
V_82 = F_237 ( V_45 ,
( char * ) & V_568 -> V_578 . V_586 ,
( char * ) & V_568 -> V_578 . V_589 ) ;
if ( V_82 ) {
F_11 ( V_93 , V_45 , L_159 ) ;
V_82 = V_252 ;
goto V_633;
}
V_568 -> V_578 . V_585 = V_632 ;
V_568 -> V_578 . V_588 = V_630 ;
}
V_633:
F_26 ( & V_45 -> V_120 -> V_121 , sizeof( * V_262 ) ,
V_262 , V_298 ) ;
return V_82 ;
}
static int F_245 ( struct V_44 * V_45 )
{
V_200 V_246 [ 2 ] ;
int V_82 = V_252 ;
int V_227 ;
memset ( V_246 , 0 , sizeof( V_246 ) ) ;
V_246 [ 0 ] = 0xffff ;
V_246 [ 1 ] = 0xffff ;
V_82 = F_233 ( V_45 , V_246 ) ;
if ( V_82 != V_125 ) {
F_6 ( F_11 ( V_93 , V_45 ,
L_160 , V_91 ) ) ;
return V_82 ;
}
if ( V_637 )
return V_125 ;
if ( V_246 [ 0 ] == 0xffff )
goto V_638;
V_227 = F_241 ( V_45 , & ( V_45 -> V_592 . V_593 ) ,
V_246 [ 0 ] ) ;
if ( V_227 != V_125 ) {
F_6 ( F_11 ( V_93 , V_45 , L_161
L_162 , V_91 ) ) ;
} else
V_82 = V_125 ;
V_638:
if ( V_246 [ 1 ] == 0xffff )
goto V_639;
V_227 = F_241 ( V_45 , & ( V_45 -> V_592 . V_594 ) ,
V_246 [ 1 ] ) ;
if ( V_227 != V_125 ) {
F_6 ( F_11 ( V_93 , V_45 , L_161
L_163 , V_91 ) ) ;
} else
V_82 = V_125 ;
V_639:
return V_82 ;
}
static int F_246 ( struct V_44 * V_45 )
{
struct V_640 * V_641 ;
if ( F_245 ( V_45 ) != V_125 )
return V_252 ;
if ( V_637 ) {
F_11 ( V_90 , V_45 ,
L_164
L_165 , V_91 ) ;
return V_125 ;
}
V_45 -> V_642 = F_247 ( V_45 -> V_101 -> V_362 ) ;
if ( ! V_45 -> V_642 )
goto V_643;
if ( ! F_248 ( V_45 -> V_101 ) )
goto V_643;
V_641 = F_249 ( V_45 -> V_642 , 0 , V_45 ,
F_228 ,
F_230 ,
F_231 ) ;
if ( ! V_641 )
goto V_644;
if ( ! F_248 ( V_45 -> V_101 ) )
goto V_643;
V_641 = F_249 ( V_45 -> V_642 , 1 , V_45 ,
F_229 ,
F_230 ,
F_231 ) ;
if ( ! V_641 )
goto V_644;
if ( ! F_248 ( V_45 -> V_101 ) )
goto V_643;
V_641 = F_250 ( V_45 -> V_642 , 0 , V_45 ,
F_225 ,
F_226 ,
F_231 ) ;
if ( ! V_641 )
goto V_644;
if ( ! F_248 ( V_45 -> V_101 ) )
goto V_643;
V_641 = F_251 ( V_45 -> V_642 , 0 , V_45 ,
F_223 ,
F_224 ,
F_231 ) ;
if ( ! V_641 )
goto V_644;
return V_125 ;
V_644:
F_232 ( V_45 -> V_101 ) ;
V_643:
F_252 ( V_45 -> V_642 ) ;
return - V_94 ;
}
static void F_253 ( struct V_44 * V_45 )
{
int V_227 = 0 ;
T_4 * V_645 = NULL ;
T_3 V_598 ;
T_2 V_646 ;
T_3 V_647 = 0 ;
if ( F_67 ( V_45 ) )
V_647 = V_625 *
sizeof( struct V_622 ) ;
else
V_647 = V_45 -> V_615 . V_624 / 2 ;
V_645 = F_22 ( & V_45 -> V_120 -> V_121 , V_647 ,
& V_646 , V_122 ) ;
if ( ! V_645 ) {
F_11 ( V_93 , V_45 , L_166 ) ;
return;
}
if ( F_67 ( V_45 ) )
V_598 = V_648 ;
else {
V_598 = V_614 + ( V_45 -> V_615 . V_649 << 2 ) ;
if ( V_45 -> V_610 == 1 )
V_598 += V_647 ;
}
V_227 = F_236 ( V_45 , V_646 , V_598 , V_647 ) ;
if ( V_227 != V_125 )
goto V_650;
if ( V_45 -> V_415 == NULL )
V_45 -> V_415 = F_254 ( V_647 ) ;
if ( V_45 -> V_415 == NULL ) {
F_11 ( V_93 , V_45 , L_167 ) ;
goto V_650;
}
memcpy ( V_45 -> V_415 , V_645 , V_647 ) ;
V_650:
F_26 ( & V_45 -> V_120 -> V_121 , V_647 ,
V_645 , V_646 ) ;
}
static void F_255 ( struct V_116 * V_116 ,
struct V_651 * V_652 )
{
struct V_44 * V_45 ;
struct V_114 * V_115 ;
struct V_108 * V_109 ;
struct V_112 * V_113 ;
struct V_243 * V_244 ;
F_6 ( F_7 ( V_90 L_11 , V_91 ) ) ;
V_45 = V_116 -> V_45 ;
V_115 = V_116 -> V_113 ;
V_113 = V_115 -> V_95 ;
V_109 = V_116 -> V_244 ;
V_244 = V_109 -> V_95 ;
V_652 -> V_356 = V_113 -> V_356 ;
V_652 -> V_355 = V_244 -> V_272 ;
strncpy ( V_652 -> V_358 , V_113 -> V_270 , V_653 ) ;
strncpy ( V_652 -> V_335 , V_244 -> V_271 , V_260 ) ;
}
static void F_256 ( struct V_297 * V_262 ,
struct V_651 * V_652 )
{
V_200 V_263 = 0 ;
V_652 -> V_356 = F_25 ( V_262 -> V_357 ) ;
memcpy ( & V_652 -> V_358 [ 0 ] , & V_262 -> V_358 [ 0 ] ,
F_103 ( sizeof( V_652 -> V_358 ) , sizeof( V_262 -> V_358 ) ) ) ;
V_263 = F_98 ( V_262 -> V_263 ) ;
if ( V_263 & V_264 )
sprintf ( V_652 -> V_335 , L_40 , V_262 -> V_335 ) ;
else
sprintf ( V_652 -> V_335 , L_41 , V_262 -> V_335 ) ;
V_652 -> V_355 = F_98 ( V_262 -> V_355 ) ;
}
static int F_257 ( struct V_44 * V_45 ,
struct V_651 * V_654 ,
struct V_651 * V_655 )
{
if ( strcmp ( V_654 -> V_358 , V_655 -> V_358 ) )
return V_252 ;
if ( strcmp ( V_654 -> V_335 , V_655 -> V_335 ) )
return V_252 ;
if ( V_654 -> V_355 != V_655 -> V_355 )
return V_252 ;
F_6 ( F_11 ( V_90 , V_45 ,
L_168 ,
V_654 -> V_355 , V_654 -> V_356 , V_654 -> V_335 ,
V_654 -> V_358 , V_655 -> V_355 , V_655 -> V_356 ,
V_655 -> V_335 , V_655 -> V_358 ) ) ;
return V_125 ;
}
static int F_258 ( struct V_44 * V_45 ,
struct V_297 * V_262 )
{
struct V_116 * V_116 ;
struct V_651 * V_656 = NULL ;
struct V_651 * V_657 = NULL ;
int V_266 ;
int V_82 = V_252 ;
V_656 = F_259 ( sizeof( * V_656 ) ) ;
if ( ! V_656 ) {
F_6 ( F_11 ( V_427 , V_45 ,
L_169 ) ) ;
V_82 = V_125 ;
goto V_658;
}
V_657 = F_259 ( sizeof( * V_657 ) ) ;
if ( ! V_657 ) {
F_6 ( F_11 ( V_427 , V_45 ,
L_169 ) ) ;
V_82 = V_125 ;
goto V_658;
}
F_256 ( V_262 , V_656 ) ;
for ( V_266 = 0 ; V_266 < V_251 ; V_266 ++ ) {
V_116 = F_68 ( V_45 , V_266 ) ;
if ( V_116 == NULL )
continue;
F_255 ( V_116 , V_657 ) ;
if ( ! F_257 ( V_45 , V_656 , V_657 ) ) {
V_82 = V_125 ;
goto V_658;
}
}
V_658:
if ( V_656 )
F_128 ( V_656 ) ;
if ( V_657 )
F_128 ( V_657 ) ;
return V_82 ;
}
static int F_260 ( struct V_44 * V_45 ,
struct V_659 * V_660 ,
struct V_297 * V_262 )
{
struct V_661 * V_662 , * V_663 ;
struct V_651 * V_656 = NULL ;
struct V_651 * V_657 = NULL ;
int V_82 = V_252 ;
V_656 = F_259 ( sizeof( * V_656 ) ) ;
if ( ! V_656 ) {
F_6 ( F_11 ( V_427 , V_45 ,
L_169 ) ) ;
V_82 = V_125 ;
goto V_658;
}
V_657 = F_259 ( sizeof( * V_657 ) ) ;
if ( ! V_657 ) {
F_6 ( F_11 ( V_427 , V_45 ,
L_169 ) ) ;
V_82 = V_125 ;
goto V_658;
}
F_256 ( V_262 , V_656 ) ;
F_261 (nt_ddb_idx, nt_ddb_idx_tmp, list_nt, list) {
F_256 ( & V_662 -> V_664 , V_657 ) ;
if ( ! F_257 ( V_45 , V_656 , V_657 ) ) {
V_82 = V_125 ;
goto V_658;
}
}
V_658:
if ( V_656 )
F_128 ( V_656 ) ;
if ( V_657 )
F_128 ( V_657 ) ;
return V_82 ;
}
static void F_262 ( struct V_659 * V_665 )
{
struct V_661 * V_666 , * V_667 ;
F_261 (ddb_idx, ddb_idx_tmp, list_ddb, list) {
F_263 ( & V_666 -> V_668 ) ;
F_128 ( V_666 ) ;
}
}
static struct V_78 * F_264 ( struct V_44 * V_45 ,
struct V_297 * V_262 )
{
struct V_78 * V_83 ;
struct V_86 * V_87 ;
struct V_88 * V_89 ;
struct V_79 * V_80 ;
char * V_669 ;
V_80 = F_254 ( sizeof( * V_80 ) ) ;
if ( ! V_80 )
return NULL ;
if ( V_262 -> V_263 & V_264 ) {
V_80 -> V_96 = V_99 ;
V_89 = (struct V_88 * ) V_80 ;
V_669 = ( char * ) & V_89 -> V_100 ;
memcpy ( V_669 , V_262 -> V_335 , V_258 ) ;
V_89 -> V_670 = F_265 ( F_98 ( V_262 -> V_355 ) ) ;
} else {
V_80 -> V_96 = V_97 ;
V_87 = (struct V_86 * ) V_80 ;
V_669 = ( char * ) & V_87 -> V_98 ;
memcpy ( V_669 , V_262 -> V_335 , V_634 ) ;
V_87 -> V_671 = F_265 ( F_98 ( V_262 -> V_355 ) ) ;
}
V_83 = F_5 ( V_45 -> V_101 , V_80 , 0 ) ;
F_128 ( V_80 ) ;
return V_83 ;
}
static int F_266 ( struct V_44 * V_45 , V_200 V_266 )
{
if ( V_637 )
return V_125 ;
if ( V_266 == V_45 -> V_617 || V_266 == V_45 -> V_618 )
return V_252 ;
return V_125 ;
}
static void F_267 ( struct V_44 * V_45 ,
struct V_116 * V_116 )
{
V_200 V_365 ;
V_116 -> V_275 = V_276 ;
V_116 -> V_124 = V_467 ;
V_116 -> V_281 = V_282 ;
V_116 -> V_45 = V_45 ;
V_116 -> V_283 = F_190 ;
V_116 -> V_285 = V_672 ;
F_150 ( & V_116 -> V_466 , V_467 ) ;
F_150 ( & V_116 -> V_469 , 0 ) ;
F_150 ( & V_116 -> V_470 , 0 ) ;
V_365 = F_98 ( V_116 -> V_262 . V_365 ) ;
V_116 -> V_364 =
( V_365 > V_366 ) && ( V_365 < V_366 * 10 ) ?
V_365 : V_366 ;
V_116 -> V_367 =
F_98 ( V_116 -> V_262 . V_352 ) ;
}
static void F_268 ( struct V_44 * V_45 )
{
T_3 V_266 = 0 ;
T_3 V_673 [ V_674 ] = { 0 , 1 , 2 , 3 } ;
T_3 V_309 [ V_230 ] ;
T_3 V_675 ;
unsigned long V_482 ;
int V_82 ;
V_482 = V_373 + ( V_242 * V_676 ) ;
do {
for ( V_266 = 0 ; V_266 < V_674 ; V_266 ++ ) {
if ( V_673 [ V_266 ] == - 1 )
continue;
V_82 = F_269 ( V_45 , 0 , V_673 [ V_266 ] , V_309 ) ;
if ( V_82 == V_252 ) {
V_673 [ V_266 ] = - 1 ;
continue;
}
V_675 = ( V_309 [ 1 ] & V_677 ) >> V_678 ;
F_6 ( F_11 ( V_90 , V_45 ,
L_170 ,
V_673 [ V_266 ] , V_675 ) ) ;
if ( V_675 == V_679 ||
V_675 == V_680 ||
V_675 == V_681 ||
V_675 == V_682 ||
V_675 == V_683 )
V_673 [ V_266 ] = - 1 ;
}
if ( ( V_673 [ 0 ] == - 1 ) &&
( V_673 [ 1 ] == - 1 ) &&
( V_673 [ 2 ] == - 1 ) &&
( V_673 [ 3 ] == - 1 ) )
break;
F_270 ( V_242 ) ;
} while ( F_271 ( V_482 , V_373 ) );
}
static void F_272 ( struct V_44 * V_45 ,
struct V_659 * V_684 )
{
struct V_661 * V_685 ;
int V_267 ;
int V_686 ;
struct V_297 * V_262 ;
T_2 V_687 ;
int V_82 ;
T_3 V_266 = 0 , V_688 = 0 ;
T_3 V_172 = 0 , V_689 = 0 ;
V_200 V_690 = 0 ;
V_262 = F_273 ( V_45 -> V_416 , V_122 ,
& V_687 ) ;
if ( V_262 == NULL ) {
F_6 ( F_11 ( V_93 , V_45 , L_171 ) ) ;
goto V_691;
}
V_267 = F_67 ( V_45 ) ? V_273 :
V_274 ;
V_686 = sizeof( struct V_661 ) ;
for ( V_266 = 0 ; V_266 < V_267 ; V_266 = V_688 ) {
V_82 = F_101 ( V_45 , V_266 , V_262 , V_687 ,
NULL , & V_688 , & V_172 ,
& V_689 , NULL , & V_690 ) ;
if ( V_82 == V_252 )
break;
if ( strlen ( ( char * ) V_262 -> V_358 ) != 0 )
goto V_692;
V_685 = F_259 ( V_686 ) ;
if ( ! V_685 )
break;
V_685 -> V_693 = V_266 ;
F_274 ( & V_685 -> V_668 , V_684 ) ;
V_692:
if ( V_688 == 0 )
break;
}
V_691:
if ( V_262 )
F_275 ( V_45 -> V_416 , V_262 , V_687 ) ;
}
static void F_276 ( struct V_44 * V_45 ,
struct V_659 * V_665 )
{
struct V_661 * V_666 , * V_667 ;
T_3 V_688 = 0 ;
T_3 V_172 = 0 , V_689 = 0 ;
int V_82 ;
F_261 (ddb_idx, ddb_idx_tmp, list_ddb, list) {
V_82 = F_101 ( V_45 , V_666 -> V_693 ,
NULL , 0 , NULL , & V_688 , & V_172 ,
& V_689 , NULL , NULL ) ;
if ( V_82 == V_252 )
continue;
if ( V_172 == V_282 ||
V_172 == V_496 ) {
F_263 ( & V_666 -> V_668 ) ;
F_128 ( V_666 ) ;
}
}
}
static int F_277 ( struct V_44 * V_45 ,
struct V_297 * V_262 ,
int V_527 )
{
struct V_114 * V_115 ;
struct V_112 * V_113 ;
struct V_108 * V_109 ;
struct V_78 * V_83 ;
V_200 V_277 = 32 ;
V_200 V_690 = 0 ;
T_3 V_279 = 0 ;
int V_82 = V_125 ;
struct V_116 * V_116 = NULL ;
V_115 = F_70 ( & V_180 , V_45 -> V_101 ,
V_277 , sizeof( struct V_116 ) ,
sizeof( struct V_280 ) ,
V_279 , V_467 ) ;
if ( ! V_115 ) {
V_82 = V_252 ;
goto V_694;
}
F_278 ( V_180 . V_695 ) ;
V_113 = V_115 -> V_95 ;
V_116 = V_113 -> V_95 ;
V_116 -> V_113 = V_115 ;
V_115 -> V_287 = V_288 ;
memcpy ( & V_116 -> V_262 , V_262 ,
sizeof( struct V_297 ) ) ;
F_267 ( V_45 , V_116 ) ;
V_109 = F_76 ( V_115 , sizeof( struct V_245 ) , V_690 ) ;
if ( ! V_109 ) {
V_82 = V_252 ;
goto V_694;
}
V_116 -> V_244 = V_109 ;
V_83 = F_264 ( V_45 , V_262 ) ;
if ( V_83 ) {
V_83 -> V_244 = V_109 ;
V_109 -> V_83 = V_83 ;
} else {
F_6 ( F_11 ( V_93 , V_45 , L_172 ) ) ;
V_82 = V_252 ;
goto V_694;
}
F_97 ( V_45 , V_262 , V_115 , V_109 ) ;
if ( V_527 == V_511 ) {
F_111 ( V_115 ) ;
F_142 ( V_468 , & V_45 -> V_394 ) ;
F_142 ( V_465 , & V_116 -> V_104 ) ;
}
V_694:
return V_82 ;
}
static void F_279 ( struct V_44 * V_45 ,
struct V_659 * V_660 , int V_527 )
{
struct V_297 * V_262 ;
T_2 V_687 ;
int V_267 ;
int V_686 ;
int V_82 ;
T_3 V_266 = 0 , V_688 = 0 ;
T_3 V_172 = 0 , V_689 = 0 ;
V_200 V_690 = 0 ;
struct V_661 * V_662 ;
V_262 = F_273 ( V_45 -> V_416 , V_122 ,
& V_687 ) ;
if ( V_262 == NULL ) {
F_6 ( F_11 ( V_93 , V_45 , L_171 ) ) ;
goto V_696;
}
V_267 = F_67 ( V_45 ) ? V_273 :
V_274 ;
V_686 = sizeof( struct V_661 ) ;
for ( V_266 = 0 ; V_266 < V_267 ; V_266 = V_688 ) {
V_82 = F_101 ( V_45 , V_266 , V_262 , V_687 ,
NULL , & V_688 , & V_172 ,
& V_689 , NULL , & V_690 ) ;
if ( V_82 == V_252 )
break;
if ( F_266 ( V_45 , V_266 ) != V_125 )
goto V_697;
if ( strlen ( ( char * ) V_262 -> V_358 ) == 0 )
goto V_697;
if ( ! ( V_172 == V_282 ||
V_172 == V_496 ) )
goto V_697;
F_6 ( F_11 ( V_90 , V_45 ,
L_173 , V_266 ) ) ;
if ( V_527 == V_698 ) {
V_662 = F_254 ( V_686 ) ;
if ( ! V_662 )
break;
V_662 -> V_693 = V_266 ;
memcpy ( & V_662 -> V_664 , V_262 ,
sizeof( struct V_297 ) ) ;
if ( F_260 ( V_45 , V_660 ,
V_262 ) == V_125 ) {
F_128 ( V_662 ) ;
goto V_697;
}
F_274 ( & V_662 -> V_668 , V_660 ) ;
} else if ( V_527 == V_511 ) {
if ( F_258 ( V_45 , V_262 ) ==
V_125 )
goto V_697;
}
V_82 = F_277 ( V_45 , V_262 , V_527 ) ;
if ( V_82 == V_252 )
goto V_696;
V_697:
if ( V_688 == 0 )
break;
}
V_696:
if ( V_262 )
F_275 ( V_45 -> V_416 , V_262 , V_687 ) ;
}
void F_205 ( struct V_44 * V_45 , int V_527 )
{
V_200 V_699 = 0 ;
struct V_659 V_684 , V_660 ;
struct V_661 * V_685 , * V_700 ;
unsigned long V_482 ;
if ( ! F_14 ( V_400 , & V_45 -> V_104 ) ) {
F_142 ( V_103 , & V_45 -> V_104 ) ;
V_45 -> V_527 = V_527 ;
return;
}
F_280 ( & V_684 ) ;
F_280 ( & V_660 ) ;
F_272 ( V_45 , & V_684 ) ;
F_268 ( V_45 ) ;
F_261 (st_ddb_idx, st_ddb_idx_tmp, &list_st, list) {
F_82 ( V_45 , V_685 -> V_693 ) ;
}
V_699 = ( ( V_45 -> V_365 > V_366 ) &&
( V_45 -> V_365 < V_366 * 10 ) ?
V_45 -> V_365 : V_366 ) ;
F_6 ( F_11 ( V_90 , V_45 ,
L_174 , V_699 ) ) ;
V_482 = V_373 + ( V_242 * V_699 ) ;
do {
if ( F_281 ( & V_684 ) )
break;
F_276 ( V_45 , & V_684 ) ;
F_270 ( V_242 / 10 ) ;
} while ( F_271 ( V_482 , V_373 ) );
F_262 ( & V_684 ) ;
F_279 ( V_45 , & V_660 , V_527 ) ;
F_262 ( & V_660 ) ;
F_282 ( V_45 ) ;
}
static int T_9 F_283 ( struct V_536 * V_120 ,
const struct V_701 * V_702 )
{
int V_82 = - V_703 , V_261 ;
struct V_42 * V_101 ;
struct V_44 * V_45 ;
T_4 V_704 = 0 ;
char V_41 [ 34 ] ;
struct V_705 * V_706 ;
T_3 V_454 ;
if ( F_284 ( V_120 ) )
return - 1 ;
V_101 = F_285 ( & V_707 , sizeof( * V_45 ) , 0 ) ;
if ( V_101 == NULL ) {
F_7 ( V_427
L_175 ) ;
goto V_708;
}
V_45 = F_4 ( V_101 ) ;
memset ( V_45 , 0 , sizeof( * V_45 ) ) ;
V_45 -> V_120 = V_120 ;
V_45 -> V_101 = V_101 ;
V_45 -> V_362 = V_101 -> V_362 ;
F_286 ( V_120 ) ;
if ( F_129 ( V_45 ) ) {
V_45 -> V_501 = & V_709 ;
F_287 ( & V_45 -> V_710 ) ;
V_45 -> V_711 = - 1 ;
V_45 -> V_712 = - 1 ;
V_45 -> V_713 = 255 ;
V_45 -> V_599 = F_234 ( V_45 -> V_120 -> V_541 ) ;
V_706 = & V_714 [ V_45 -> V_599 ] ;
V_45 -> V_706 . V_715 = V_706 -> V_715 ;
V_45 -> V_706 . V_716 =
V_706 -> V_716 ;
V_45 -> V_706 . V_717 = V_706 -> V_717 ;
V_45 -> V_706 . V_718 = V_706 -> V_718 ;
} else {
V_45 -> V_501 = & V_719 ;
}
if ( F_129 ( V_45 ) )
V_120 -> V_720 = 1 ;
V_82 = V_45 -> V_501 -> V_721 ( V_45 ) ;
if ( V_82 )
goto V_722;
F_11 ( V_90 , V_45 , L_176 ,
V_120 -> V_170 , V_120 -> V_723 , V_45 -> V_420 ) ;
F_288 ( V_45 ) ;
F_280 ( & V_45 -> V_724 ) ;
F_289 ( & V_45 -> V_725 ) ;
F_289 ( & V_45 -> V_626 ) ;
F_290 ( & V_45 -> V_726 ) ;
F_290 ( & V_45 -> V_240 ) ;
F_291 ( & V_45 -> V_291 ) ;
if ( F_132 ( V_45 ) ) {
F_11 ( V_427 , V_45 ,
L_177 ) ;
V_82 = - V_94 ;
goto V_727;
}
V_101 -> V_728 = 3 ;
V_101 -> V_729 = 0 ;
V_101 -> V_730 = V_731 - 1 ;
V_101 -> V_732 = V_733 ;
V_101 -> V_734 = V_735 ;
V_101 -> V_484 = V_736 ;
V_101 -> V_737 = V_738 ;
V_82 = F_292 ( V_101 , V_736 ) ;
if ( V_82 ) {
F_11 ( V_427 , V_45 ,
L_178 , V_91 ) ;
goto V_727;
}
F_293 ( V_120 , V_45 ) ;
V_82 = F_294 ( V_101 , & V_120 -> V_121 ) ;
if ( V_82 )
goto V_727;
if ( F_129 ( V_45 ) )
( void ) F_295 ( V_45 ) ;
V_261 = F_183 ( V_45 , V_698 ) ;
while ( ( ! F_14 ( V_399 , & V_45 -> V_104 ) ) &&
V_704 ++ < V_739 ) {
if ( F_129 ( V_45 ) ) {
F_184 ( V_45 ) ;
V_454 = F_136 ( V_45 , V_457 ) ;
F_185 ( V_45 ) ;
if ( V_454 == V_512 ) {
F_11 ( V_427 , V_45 , L_108
L_179 ,
V_91 ) ;
break;
}
}
F_6 ( F_7 ( L_180
L_181 , V_91 , V_704 ) ) ;
if ( V_45 -> V_501 -> V_498 ( V_45 ) == V_252 )
continue;
V_261 = F_183 ( V_45 , V_698 ) ;
}
if ( ! F_14 ( V_399 , & V_45 -> V_104 ) ) {
F_11 ( V_427 , V_45 , L_182 ) ;
if ( F_129 ( V_45 ) && V_462 ) {
F_6 ( F_7 ( V_93 L_183 ) ) ;
F_184 ( V_45 ) ;
F_141 ( V_45 , V_457 ,
V_512 ) ;
F_185 ( V_45 ) ;
}
V_82 = - V_703 ;
goto V_740;
}
F_6 ( F_7 ( L_184
L_185 , V_91 ) ) ;
sprintf ( V_41 , L_186 , V_45 -> V_362 ) ;
V_45 -> V_521 = F_296 ( V_41 ) ;
if ( ! V_45 -> V_521 ) {
F_11 ( V_427 , V_45 , L_187 ) ;
V_82 = - V_703 ;
goto V_740;
}
F_92 ( & V_45 -> V_522 , F_201 ) ;
sprintf ( V_41 , L_188 , V_45 -> V_362 ) ;
V_45 -> V_529 = F_297 ( V_41 , V_741 , 1 ) ;
if ( ! V_45 -> V_529 ) {
F_11 ( V_427 , V_45 , L_189 ) ;
V_82 = - V_703 ;
goto V_740;
}
if ( ! F_129 ( V_45 ) ) {
V_82 = F_298 ( V_45 ) ;
if ( V_82 ) {
F_11 ( V_427 , V_45 , L_190
L_191 , V_120 -> V_723 ) ;
goto V_740;
}
}
F_299 ( V_45 -> V_120 ) ;
V_45 -> V_501 -> V_517 ( V_45 ) ;
F_104 ( V_45 , F_154 , 1 ) ;
F_142 ( V_495 , & V_45 -> V_104 ) ;
F_7 ( V_90
L_192
L_193 ,
V_742 , V_45 -> V_120 -> V_170 , F_212 ( V_45 -> V_120 ) ,
V_45 -> V_362 , V_45 -> V_743 [ 0 ] , V_45 -> V_743 [ 1 ] ,
V_45 -> V_744 , V_45 -> V_745 ) ;
if ( F_246 ( V_45 ) )
F_11 ( V_93 , V_45 , L_194 ,
V_91 ) ;
F_205 ( V_45 , V_698 ) ;
F_113 ( V_45 -> V_101 , F_197 ) ;
F_253 ( V_45 ) ;
F_37 ( V_45 ) ;
return 0 ;
V_740:
F_300 ( V_45 -> V_101 ) ;
V_727:
F_206 ( V_45 ) ;
V_722:
F_301 ( V_120 ) ;
F_232 ( V_45 -> V_101 ) ;
V_708:
F_302 ( V_120 ) ;
return V_82 ;
}
static void F_303 ( struct V_44 * V_45 )
{
struct V_44 * V_746 = NULL ;
struct V_536 * V_747 = NULL ;
int V_748 = V_749 ;
if ( F_234 ( V_45 -> V_120 -> V_541 ) & V_750 )
V_748 = V_751 ;
V_747 =
F_304 ( F_305 ( V_45 -> V_120 -> V_752 ) ,
V_45 -> V_120 -> V_752 -> V_753 , F_306 ( F_307 ( V_45 -> V_120 -> V_541 ) ,
V_748 ) ) ;
if ( V_747 ) {
if ( F_149 ( & V_747 -> V_754 ) ) {
V_746 = F_308 ( V_747 ) ;
if ( V_746 ) {
F_142 ( V_755 , & V_746 -> V_104 ) ;
F_6 ( F_11 ( V_90 , V_45 , L_195
L_196 , V_91 ,
F_309 ( & V_746 -> V_120 -> V_121 ) ) ) ;
}
}
F_310 ( V_747 ) ;
}
}
static void F_311 ( struct V_44 * V_45 )
{
struct V_116 * V_116 ;
int V_263 ;
int V_266 ;
for ( V_266 = 0 ; V_266 < V_251 ; V_266 ++ ) {
V_116 = F_68 ( V_45 , V_266 ) ;
if ( ( V_116 != NULL ) &&
( V_116 -> V_275 == V_276 ) ) {
V_263 = V_304 ;
if ( F_84 ( V_45 , V_116 , V_263 )
== V_252 )
F_11 ( V_93 , V_45 , L_52 ,
V_91 ) ;
F_72 ( V_45 , V_116 -> V_124 ) ;
F_312 ( V_180 . V_695 ) ;
F_16 ( V_116 -> V_244 -> V_83 ) ;
F_73 ( V_45 , V_116 ) ;
F_74 ( V_116 -> V_113 ) ;
}
}
}
static void T_10 F_313 ( struct V_536 * V_120 )
{
struct V_44 * V_45 ;
V_45 = F_308 ( V_120 ) ;
if ( ! F_129 ( V_45 ) )
F_303 ( V_45 ) ;
F_41 ( V_45 ) ;
if ( ( ! V_637 ) && V_45 -> V_642 )
F_252 ( V_45 -> V_642 ) ;
F_311 ( V_45 ) ;
F_300 ( V_45 -> V_101 ) ;
F_206 ( V_45 ) ;
F_232 ( V_45 -> V_101 ) ;
F_301 ( V_120 ) ;
F_302 ( V_120 ) ;
F_293 ( V_120 , NULL ) ;
}
static void F_288 ( struct V_44 * V_45 )
{
int V_756 ;
if ( F_314 ( V_45 -> V_120 , F_315 ( 64 ) ) == 0 ) {
if ( F_316 ( V_45 -> V_120 , F_315 ( 64 ) ) ) {
F_317 ( & V_45 -> V_120 -> V_121 ,
L_197
L_198 ) ;
V_756 = F_316 ( V_45 -> V_120 ,
F_315 ( 32 ) ) ;
}
} else
V_756 = F_314 ( V_45 -> V_120 , F_315 ( 32 ) ) ;
}
static int F_318 ( struct V_757 * V_758 )
{
struct V_114 * V_115 ;
struct V_112 * V_113 ;
struct V_116 * V_380 ;
int V_759 = V_760 ;
V_115 = F_28 ( V_758 -> V_761 ) ;
V_113 = V_115 -> V_95 ;
V_380 = V_113 -> V_95 ;
V_758 -> V_385 = V_380 ;
V_758 -> V_762 = 1 ;
if ( V_763 != 0 && V_763 <= 0xffffU )
V_759 = V_763 ;
F_319 ( V_758 , V_759 ) ;
return 0 ;
}
static int F_320 ( struct V_757 * V_758 )
{
V_758 -> V_762 = 1 ;
return 0 ;
}
static void F_321 ( struct V_757 * V_758 )
{
F_322 ( V_758 , 1 ) ;
}
struct V_376 * F_170 ( struct V_44 * V_45 ,
T_3 V_481 )
{
struct V_376 * V_376 = NULL ;
struct V_166 * V_377 = NULL ;
V_377 = F_160 ( V_45 -> V_101 , V_481 ) ;
if ( ! V_377 )
return V_376 ;
V_376 = (struct V_376 * ) F_117 ( V_377 ) ;
if ( ! V_376 )
return V_376 ;
if ( V_376 -> V_104 & V_381 ) {
V_45 -> V_764 += V_376 -> V_765 ;
V_45 -> V_765 -= V_376 -> V_765 ;
if ( V_376 -> V_377 )
V_376 -> V_377 -> V_766 =
( unsigned char * ) ( unsigned long ) V_736 ;
}
return V_376 ;
}
static int F_323 ( struct V_44 * V_45 ,
struct V_166 * V_377 )
{
int V_767 = 0 ;
struct V_376 * V_768 ;
T_3 V_488 = V_769 ;
int V_82 = V_770 ;
if ( F_324 ( F_156 ( V_45 -> V_120 ) ) ||
( F_14 ( V_386 , & V_45 -> V_104 ) ) ) {
F_11 ( V_427 , V_45 , L_199 ,
V_45 -> V_362 , V_91 ) ;
return V_82 ;
}
do {
V_768 = (struct V_376 * ) F_117 ( V_377 ) ;
if ( V_768 == NULL ) {
V_767 ++ ;
break;
}
F_161 ( 2000 ) ;
} while ( V_488 -- );
return V_767 ;
}
static int F_325 ( struct V_44 * V_45 )
{
unsigned long V_771 ;
V_771 = V_373 + ( V_772 * V_242 ) ;
while ( F_179 ( V_373 , V_771 ) ) {
if ( F_13 ( V_45 ) )
return V_125 ;
F_161 ( 2000 ) ;
}
return V_252 ;
}
static int F_326 ( struct V_44 * V_45 ,
struct F_29 * V_773 ,
struct V_757 * V_758 )
{
int V_774 ;
int V_261 = 0 ;
struct V_166 * V_377 ;
for ( V_774 = 0 ; V_774 < V_45 -> V_101 -> V_484 ; V_774 ++ ) {
V_377 = F_160 ( V_45 -> V_101 , V_774 ) ;
if ( V_377 && V_773 == F_29 ( V_377 -> V_170 ) &&
( ! V_758 || V_758 == V_377 -> V_170 ) ) {
if ( ! F_323 ( V_45 , V_377 ) ) {
V_261 ++ ;
break;
}
}
}
return V_261 ;
}
static int F_327 ( struct V_166 * V_377 )
{
struct V_44 * V_45 = F_4 ( V_377 -> V_170 -> V_101 ) ;
unsigned int V_775 = V_377 -> V_170 -> V_775 ;
unsigned int V_776 = V_377 -> V_170 -> V_776 ;
unsigned long V_104 ;
struct V_376 * V_376 = NULL ;
int V_82 = V_770 ;
int V_499 = 0 ;
F_11 ( V_90 , V_45 ,
L_200 ,
V_45 -> V_362 , V_775 , V_776 , V_377 ) ;
F_30 ( & V_45 -> V_291 , V_104 ) ;
V_376 = (struct V_376 * ) F_117 ( V_377 ) ;
if ( ! V_376 ) {
F_31 ( & V_45 -> V_291 , V_104 ) ;
return V_770 ;
}
F_328 ( & V_376 -> V_379 ) ;
F_31 ( & V_45 -> V_291 , V_104 ) ;
if ( F_329 ( V_45 , V_376 ) != V_125 ) {
F_87 ( F_7 ( L_201 ,
V_45 -> V_362 , V_775 , V_776 ) ) ;
V_82 = V_777 ;
} else {
F_87 ( F_7 ( L_202 ,
V_45 -> V_362 , V_775 , V_776 ) ) ;
V_499 = 1 ;
}
F_171 ( & V_376 -> V_379 , F_120 ) ;
if ( V_499 ) {
if ( ! F_323 ( V_45 , V_377 ) ) {
F_6 ( F_7 ( L_203 ,
V_45 -> V_362 , V_775 , V_776 ) ) ;
V_82 = V_777 ;
}
}
F_11 ( V_90 , V_45 ,
L_204 ,
V_45 -> V_362 , V_775 , V_776 , ( V_82 == V_770 ) ? L_205 : L_206 ) ;
return V_82 ;
}
static int F_330 ( struct V_166 * V_377 )
{
struct V_44 * V_45 = F_4 ( V_377 -> V_170 -> V_101 ) ;
struct V_116 * V_116 = V_377 -> V_170 -> V_385 ;
int V_82 = V_777 , V_778 ;
if ( ! V_116 )
return V_82 ;
V_82 = F_331 ( V_377 ) ;
if ( V_82 )
return V_82 ;
V_82 = V_777 ;
F_11 ( V_90 , V_45 ,
L_207 , V_45 -> V_362 ,
V_377 -> V_170 -> V_779 , V_377 -> V_170 -> V_775 , V_377 -> V_170 -> V_776 ) ;
F_6 ( F_7 ( V_90
L_208
L_209 , V_45 -> V_362 ,
V_377 , V_373 , V_377 -> V_780 -> V_781 / V_242 ,
V_45 -> V_394 , V_377 -> V_388 , V_377 -> V_782 ) ) ;
V_778 = F_332 ( V_45 , V_116 , V_377 -> V_170 -> V_776 ) ;
if ( V_778 != V_125 ) {
F_11 ( V_90 , V_45 , L_210 , V_778 ) ;
goto V_783;
}
if ( F_326 ( V_45 , F_29 ( V_377 -> V_170 ) ,
V_377 -> V_170 ) ) {
F_11 ( V_90 , V_45 ,
L_211
L_212 ) ;
goto V_783;
}
if ( F_333 ( V_45 , V_116 , V_377 -> V_170 -> V_776 ,
V_784 ) != V_125 )
goto V_783;
F_11 ( V_90 , V_45 ,
L_213 ,
V_45 -> V_362 , V_377 -> V_170 -> V_779 , V_377 -> V_170 -> V_775 ,
V_377 -> V_170 -> V_776 ) ;
V_82 = V_770 ;
V_783:
return V_82 ;
}
static int F_334 ( struct V_166 * V_377 )
{
struct V_44 * V_45 = F_4 ( V_377 -> V_170 -> V_101 ) ;
struct V_116 * V_116 = V_377 -> V_170 -> V_385 ;
int V_778 , V_82 ;
if ( ! V_116 )
return V_777 ;
V_82 = F_331 ( V_377 ) ;
if ( V_82 )
return V_82 ;
F_335 ( V_90 , F_29 ( V_377 -> V_170 ) ,
L_214 ) ;
F_6 ( F_7 ( V_90
L_215
L_216 ,
V_45 -> V_362 , V_377 , V_373 , V_377 -> V_780 -> V_781 / V_242 ,
V_45 -> V_394 , V_377 -> V_388 , V_377 -> V_782 ) ) ;
V_778 = F_336 ( V_45 , V_116 ) ;
if ( V_778 != V_125 ) {
F_335 ( V_90 , F_29 ( V_377 -> V_170 ) ,
L_217 ) ;
return V_777 ;
}
if ( F_326 ( V_45 , F_29 ( V_377 -> V_170 ) ,
NULL ) ) {
F_335 ( V_90 , F_29 ( V_377 -> V_170 ) ,
L_218
L_219 ) ;
return V_777 ;
}
if ( F_333 ( V_45 , V_116 , V_377 -> V_170 -> V_776 ,
V_785 ) != V_125 ) {
F_335 ( V_90 , F_29 ( V_377 -> V_170 ) ,
L_218
L_220 ) ;
return V_777 ;
}
F_335 ( V_90 , F_29 ( V_377 -> V_170 ) ,
L_221 ) ;
return V_770 ;
}
static int F_337 ( struct V_42 * V_43 )
{
if ( V_43 -> V_786 == V_787 )
return 1 ;
return 0 ;
}
static int F_338 ( struct V_166 * V_377 )
{
int V_788 = V_777 ;
struct V_44 * V_45 ;
V_45 = F_4 ( V_377 -> V_170 -> V_101 ) ;
if ( V_462 ) {
F_6 ( F_7 ( L_130 ,
V_45 -> V_362 , V_91 ) ) ;
if ( F_337 ( V_377 -> V_170 -> V_101 ) )
F_169 ( V_45 , V_789 << 16 ) ;
return V_777 ;
}
F_11 ( V_90 , V_45 ,
L_222 , V_45 -> V_362 ,
V_377 -> V_170 -> V_779 , V_377 -> V_170 -> V_775 , V_377 -> V_170 -> V_776 ) ;
if ( F_325 ( V_45 ) != V_125 ) {
F_6 ( F_7 ( L_223
L_224 , V_45 -> V_362 , V_377 -> V_170 -> V_779 ,
V_91 ) ) ;
return V_777 ;
}
if ( ! F_14 ( V_396 , & V_45 -> V_394 ) ) {
if ( F_129 ( V_45 ) )
F_142 ( V_401 , & V_45 -> V_394 ) ;
else
F_142 ( V_396 , & V_45 -> V_394 ) ;
}
if ( F_176 ( V_45 ) == V_125 )
V_788 = V_770 ;
F_11 ( V_90 , V_45 , L_225 ,
V_788 == V_777 ? L_118 : L_119 ) ;
return V_788 ;
}
static int F_339 ( struct V_44 * V_45 )
{
T_3 V_229 [ V_230 ] ;
T_3 V_231 [ V_230 ] ;
struct V_209 * V_210 = NULL ;
T_3 V_790 = sizeof( struct V_209 ) ;
int V_227 = V_125 ;
T_2 V_791 ;
V_210 = F_22 ( & V_45 -> V_120 -> V_121 ,
sizeof( struct V_209 ) ,
& V_791 , V_122 ) ;
if ( ! V_210 ) {
F_11 ( V_93 , V_45 , L_226 ,
V_91 ) ;
V_227 = - V_94 ;
goto V_792;
}
memset ( V_210 , 0 , V_790 ) ;
V_227 = F_340 ( V_45 , V_791 , V_793 , V_790 ) ;
if ( V_227 != V_125 ) {
V_227 = - V_235 ;
goto V_794;
}
V_227 = F_53 ( V_45 ) ;
if ( V_227 != V_125 ) {
V_227 = - V_235 ;
goto V_794;
}
F_54 ( & V_45 -> V_240 ,
V_241 * V_242 ) ;
V_227 = F_55 ( V_45 , & V_229 [ 0 ] , & V_231 [ 0 ] , V_791 ) ;
if ( V_227 != V_125 ) {
V_227 = - V_235 ;
goto V_794;
}
V_794:
F_26 ( & V_45 -> V_120 -> V_121 , sizeof( struct V_209 ) ,
V_210 , V_791 ) ;
V_792:
F_6 ( F_11 ( V_90 , V_45 , L_227 , V_91 ,
V_227 == V_125 ? L_119 : L_118 ) ) ;
return V_227 ;
}
static int F_341 ( struct V_42 * V_43 , int V_795 )
{
struct V_44 * V_45 = F_4 ( V_43 ) ;
int V_227 = V_125 ;
if ( V_462 ) {
F_6 ( F_11 ( V_90 , V_45 , L_228 ,
V_91 ) ) ;
V_227 = - V_796 ;
goto V_797;
}
V_227 = F_325 ( V_45 ) ;
if ( V_227 != V_125 ) {
F_6 ( F_11 ( V_90 , V_45 , L_229
L_230 , V_91 ) ) ;
V_227 = - V_235 ;
goto V_797;
}
if ( F_14 ( V_396 , & V_45 -> V_394 ) )
goto V_798;
switch ( V_795 ) {
case V_799 :
F_142 ( V_396 , & V_45 -> V_394 ) ;
break;
case V_800 :
if ( ! F_14 ( V_396 , & V_45 -> V_394 ) ) {
if ( F_129 ( V_45 ) )
F_142 ( V_401 ,
& V_45 -> V_394 ) ;
else {
V_227 = F_339 ( V_45 ) ;
goto V_797;
}
}
break;
}
V_798:
V_227 = F_176 ( V_45 ) ;
if ( V_227 != V_125 ) {
F_6 ( F_11 ( V_90 , V_45 , L_231 ,
V_91 ) ) ;
V_227 = - V_235 ;
}
V_797:
return V_227 ;
}
static T_11
F_342 ( struct V_536 * V_120 , T_12 V_172 )
{
struct V_44 * V_45 = F_308 ( V_120 ) ;
F_11 ( V_427 , V_45 , L_232 ,
V_45 -> V_362 , V_91 , V_172 ) ;
if ( ! F_343 ( V_45 ) )
return V_801 ;
switch ( V_172 ) {
case V_802 :
F_173 ( V_386 , & V_45 -> V_104 ) ;
return V_803 ;
case V_804 :
F_142 ( V_386 , & V_45 -> V_104 ) ;
F_146 ( V_45 ) ;
F_209 ( V_45 ) ;
F_302 ( V_120 ) ;
F_169 ( V_45 , V_506 << 16 ) ;
return V_805 ;
case V_806 :
F_142 ( V_386 , & V_45 -> V_104 ) ;
F_142 ( V_387 , & V_45 -> V_104 ) ;
F_169 ( V_45 , V_389 << 16 ) ;
return V_807 ;
}
return V_805 ;
}
static T_11
F_344 ( struct V_536 * V_120 )
{
struct V_44 * V_45 = F_308 ( V_120 ) ;
if ( ! F_343 ( V_45 ) )
return V_801 ;
return V_808 ;
}
static T_3 F_345 ( struct V_44 * V_45 )
{
T_3 V_227 = V_252 ;
T_3 V_82 = 0 ;
int V_748 ;
struct V_536 * V_747 = NULL ;
F_11 ( V_427 , V_45 , L_233 , V_45 -> V_362 , V_91 ) ;
F_142 ( V_395 , & V_45 -> V_394 ) ;
if ( F_14 ( V_399 , & V_45 -> V_104 ) ) {
F_173 ( V_399 , & V_45 -> V_104 ) ;
F_173 ( V_400 , & V_45 -> V_104 ) ;
F_113 ( V_45 -> V_101 , F_174 ) ;
F_178 ( V_45 , V_505 ) ;
}
V_748 = F_234 ( V_45 -> V_120 -> V_541 ) ;
while ( V_748 > 0 ) {
V_748 -- ;
F_11 ( V_90 , V_45 , L_234
L_235 , V_45 -> V_362 , V_91 , V_748 ) ;
V_747 =
F_304 ( F_305 ( V_45 -> V_120 -> V_752 ) ,
V_45 -> V_120 -> V_752 -> V_753 , F_306 ( F_307 ( V_45 -> V_120 -> V_541 ) ,
V_748 ) ) ;
if ( ! V_747 )
continue;
if ( F_149 ( & V_747 -> V_754 ) ) {
F_11 ( V_90 , V_45 , L_236
L_237 , V_45 -> V_362 ,
V_91 , V_748 ) ;
F_310 ( V_747 ) ;
break;
}
F_310 ( V_747 ) ;
}
if ( ! V_748 ) {
F_11 ( V_90 , V_45 , L_238
L_239 , V_45 -> V_362 , V_91 ,
V_45 -> V_120 -> V_541 ) ;
F_184 ( V_45 ) ;
F_141 ( V_45 , V_457 ,
V_809 ) ;
F_141 ( V_45 , V_810 ,
V_811 ) ;
F_185 ( V_45 ) ;
F_173 ( V_503 , & V_45 -> V_104 ) ;
V_227 = F_183 ( V_45 , V_511 ) ;
F_184 ( V_45 ) ;
if ( V_227 != V_125 ) {
F_11 ( V_90 , V_45 , L_240
L_241 , V_45 -> V_362 , V_91 ) ;
F_208 ( V_45 ) ;
F_141 ( V_45 , V_457 ,
V_512 ) ;
} else {
F_11 ( V_90 , V_45 , L_240
L_242 , V_45 -> V_362 , V_91 ) ;
F_141 ( V_45 , V_457 ,
V_812 ) ;
F_141 ( V_45 , V_813 , 0 ) ;
F_346 ( V_45 ) ;
V_82 = F_298 ( V_45 ) ;
if ( V_82 ) {
F_11 ( V_427 , V_45 , L_243
L_244 ,
V_45 -> V_120 -> V_723 ) ;
V_227 = V_252 ;
} else {
V_45 -> V_501 -> V_517 ( V_45 ) ;
V_227 = V_125 ;
}
}
F_185 ( V_45 ) ;
} else {
F_11 ( V_90 , V_45 , L_245
L_246 , V_45 -> V_362 , V_91 ,
V_45 -> V_120 -> V_541 ) ;
if ( ( F_136 ( V_45 , V_457 ) ==
V_812 ) ) {
F_173 ( V_503 , & V_45 -> V_104 ) ;
V_227 = F_183 ( V_45 , V_511 ) ;
if ( V_227 == V_125 ) {
V_82 = F_298 ( V_45 ) ;
if ( V_82 ) {
F_11 ( V_427 , V_45 , L_247
L_248
L_249 , V_45 -> V_120 -> V_723 ) ;
V_227 = V_252 ;
} else {
V_45 -> V_501 -> V_517 ( V_45 ) ;
V_227 = V_125 ;
}
}
F_184 ( V_45 ) ;
F_346 ( V_45 ) ;
F_185 ( V_45 ) ;
}
}
F_173 ( V_395 , & V_45 -> V_394 ) ;
return V_227 ;
}
static T_11
F_347 ( struct V_536 * V_120 )
{
T_11 V_82 = V_807 ;
struct V_44 * V_45 = F_308 ( V_120 ) ;
int V_559 ;
F_11 ( V_427 , V_45 , L_250 ,
V_45 -> V_362 , V_91 ) ;
if ( ! F_343 ( V_45 ) )
return V_801 ;
F_348 ( V_120 ) ;
F_299 ( V_120 ) ;
V_559 = F_284 ( V_120 ) ;
if ( V_559 ) {
F_11 ( V_427 , V_45 , L_251
L_252 , V_45 -> V_362 , V_91 ) ;
goto V_814;
}
V_45 -> V_501 -> V_504 ( V_45 ) ;
if ( F_129 ( V_45 ) ) {
if ( F_345 ( V_45 ) == V_125 ) {
V_82 = V_808 ;
goto V_814;
} else
goto V_814;
}
V_814:
F_11 ( V_427 , V_45 , L_253
L_252 , V_45 -> V_362 , V_91 , V_82 ) ;
return V_82 ;
}
static void
F_349 ( struct V_536 * V_120 )
{
struct V_44 * V_45 = F_308 ( V_120 ) ;
int V_82 ;
F_11 ( V_427 , V_45 , L_254 ,
V_45 -> V_362 , V_91 ) ;
V_82 = F_325 ( V_45 ) ;
if ( V_82 != V_125 ) {
F_11 ( V_93 , V_45 , L_255
L_256 , V_45 -> V_362 ,
V_91 ) ;
}
F_350 ( V_120 ) ;
F_173 ( V_386 , & V_45 -> V_104 ) ;
}
static int T_13 F_351 ( void )
{
int V_82 ;
V_433 = F_352 ( L_257 , sizeof( struct V_376 ) , 0 ,
V_815 , NULL ) ;
if ( V_433 == NULL ) {
F_7 ( V_93
L_258
L_259 , V_537 ) ;
V_82 = - V_94 ;
goto V_816;
}
strcpy ( V_742 , V_817 ) ;
if ( V_818 )
strcat ( V_742 , L_260 ) ;
V_738 =
F_353 ( & V_180 ) ;
if ( ! V_738 ) {
V_82 = - V_703 ;
goto V_819;
}
V_82 = F_354 ( & V_820 ) ;
if ( V_82 )
goto V_821;
F_7 ( V_90 L_261 ) ;
return 0 ;
V_821:
F_355 ( & V_180 ) ;
V_819:
F_356 ( V_433 ) ;
V_816:
return V_82 ;
}
static void T_14 F_357 ( void )
{
F_358 ( & V_820 ) ;
F_355 ( & V_180 ) ;
F_356 ( V_433 ) ;
}
