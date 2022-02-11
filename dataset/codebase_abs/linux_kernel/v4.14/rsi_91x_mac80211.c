bool F_1 ( struct V_1 * V_2 )
{
if ( ( ( V_2 -> V_3 . V_4 == V_5 ) ||
( V_2 -> V_3 . V_4 == V_6 ) ) &&
( ! V_2 -> V_3 . V_7 ) )
return true ;
else
return false ;
}
static void F_2 ( struct V_8 * V_9 , int V_10 )
{
struct V_11 * V_12 = & V_9 -> V_12 [ V_10 ] ;
void * V_13 = NULL ;
if ( V_10 == V_14 ) {
V_13 = F_3 ( sizeof( V_15 ) , V_16 ) ;
memcpy ( V_13 ,
V_15 ,
sizeof( V_15 ) ) ;
V_12 -> V_10 = V_14 ;
V_12 -> V_17 = F_4 ( V_15 ) ;
V_12 -> V_18 = V_19 ;
V_12 -> V_20 = F_4 ( V_19 ) ;
} else {
V_13 = F_3 ( sizeof( V_21 ) , V_16 ) ;
memcpy ( V_13 ,
V_21 ,
sizeof( V_21 ) ) ;
V_12 -> V_10 = V_22 ;
V_12 -> V_17 = F_4 ( V_21 ) ;
V_12 -> V_18 = & V_19 [ 4 ] ;
V_12 -> V_20 = F_4 ( V_19 ) - 4 ;
}
V_12 -> V_13 = V_13 ;
memset ( & V_12 -> V_23 , 0 , sizeof( struct V_24 ) ) ;
V_12 -> V_23 . V_25 = true ;
V_12 -> V_23 . V_26 = ( V_27 |
V_28 |
V_29 ) ;
V_12 -> V_23 . V_30 = V_31 ;
V_12 -> V_23 . V_32 = V_33 ;
V_12 -> V_23 . V_34 . V_35 [ 0 ] = 0xff ;
V_12 -> V_23 . V_34 . V_36 = V_37 ;
}
void F_5 ( struct V_8 * V_9 )
{
struct V_38 * V_39 = V_9 -> V_39 ;
enum V_40 V_10 ;
if ( V_39 ) {
F_6 ( V_39 ) ;
F_7 ( V_39 ) ;
F_8 ( V_39 ) ;
}
for ( V_10 = 0 ; V_10 < V_41 ; V_10 ++ ) {
struct V_11 * V_42 =
& V_9 -> V_12 [ V_10 ] ;
F_9 ( V_42 -> V_13 ) ;
}
#ifdef F_10
F_11 ( V_9 ) ;
F_9 ( V_9 -> V_43 ) ;
#endif
}
void F_12 ( struct V_8 * V_9 ,
struct V_44 * V_45 ,
int V_46 )
{
struct V_47 * V_48 = F_13 ( V_45 ) ;
struct V_49 * V_36 ;
if ( ! V_9 -> V_39 ) {
F_14 ( V_50 , L_1 ) ;
return;
}
if ( ! V_46 )
V_48 -> V_51 |= V_52 ;
V_36 = (struct V_49 * ) V_48 -> V_53 ;
F_15 ( V_45 , V_36 -> V_54 ) ;
memset ( V_48 -> V_53 , 0 , V_55 ) ;
F_16 ( V_9 -> V_39 , V_45 ) ;
}
static void F_17 ( struct V_38 * V_39 ,
struct V_56 * V_57 ,
struct V_44 * V_45 )
{
struct V_8 * V_9 = V_39 -> V_58 ;
struct V_1 * V_2 = V_9 -> V_58 ;
F_18 ( V_2 , V_45 ) ;
}
static int F_19 ( struct V_38 * V_39 )
{
struct V_8 * V_9 = V_39 -> V_58 ;
struct V_1 * V_2 = V_9 -> V_58 ;
F_14 ( V_50 , L_2 ) ;
F_20 ( & V_2 -> V_59 ) ;
V_2 -> V_60 = false ;
F_21 ( V_39 -> V_61 ) ;
F_22 ( V_2 , 0 ) ;
F_23 ( & V_2 -> V_59 ) ;
return 0 ;
}
static void F_24 ( struct V_38 * V_39 )
{
struct V_8 * V_9 = V_39 -> V_58 ;
struct V_1 * V_2 = V_9 -> V_58 ;
F_14 ( V_50 , L_3 ) ;
F_20 ( & V_2 -> V_59 ) ;
V_2 -> V_60 = true ;
F_25 ( V_39 -> V_61 ) ;
F_22 ( V_2 , 0xffff ) ;
F_23 ( & V_2 -> V_59 ) ;
}
static int F_26 ( struct V_38 * V_39 ,
struct V_62 * V_63 )
{
struct V_8 * V_9 = V_39 -> V_58 ;
struct V_1 * V_2 = V_9 -> V_58 ;
enum V_64 V_65 ;
int V_66 = - V_67 ;
V_63 -> V_68 |= V_69 ;
F_20 ( & V_2 -> V_59 ) ;
if ( V_9 -> V_70 > 1 ) {
F_23 ( & V_2 -> V_59 ) ;
return - V_67 ;
}
switch ( V_63 -> type ) {
case V_71 :
F_14 ( V_72 , L_4 ) ;
V_65 = V_73 ;
break;
case V_74 :
F_14 ( V_72 , L_5 ) ;
V_65 = V_75 ;
break;
default:
F_14 ( V_50 ,
L_6 , V_76 ,
V_63 -> type ) ;
goto V_77;
}
V_9 -> V_78 [ V_9 -> V_70 ++ ] = V_63 ;
V_66 = F_27 ( V_2 , V_65 , V_2 -> V_79 ,
0 , V_80 ) ;
if ( V_66 ) {
F_14 ( V_50 , L_7 ) ;
goto V_77;
}
if ( V_63 -> type == V_74 ) {
int V_81 ;
F_22 ( V_2 , V_82 ) ;
V_2 -> V_83 = V_84 ;
for ( V_81 = 0 ; V_81 < V_2 -> V_85 ; V_81 ++ )
V_2 -> V_86 [ V_81 ] . V_87 = NULL ;
}
V_77:
F_23 ( & V_2 -> V_59 ) ;
return V_66 ;
}
static void F_28 ( struct V_38 * V_39 ,
struct V_62 * V_63 )
{
struct V_8 * V_9 = V_39 -> V_58 ;
struct V_1 * V_2 = V_9 -> V_58 ;
enum V_64 V_64 ;
F_14 ( V_72 , L_8 ) ;
F_20 ( & V_2 -> V_59 ) ;
if ( V_9 -> V_70 <= 0 ) {
F_23 ( & V_2 -> V_59 ) ;
return;
}
switch ( V_63 -> type ) {
case V_71 :
V_64 = V_73 ;
break;
case V_74 :
V_64 = V_75 ;
break;
default:
F_23 ( & V_2 -> V_59 ) ;
return;
}
F_27 ( V_2 , V_64 , V_63 -> V_88 ,
0 , V_89 ) ;
V_9 -> V_70 -- ;
if ( ! memcmp ( V_9 -> V_78 [ 0 ] , V_63 , sizeof( struct V_62 ) ) )
V_9 -> V_78 [ 0 ] = NULL ;
F_23 ( & V_2 -> V_59 ) ;
}
static int F_29 ( struct V_38 * V_39 )
{
struct V_8 * V_9 = V_39 -> V_58 ;
struct V_1 * V_2 = V_9 -> V_58 ;
int V_46 = - V_67 ;
struct V_90 * V_91 = V_39 -> V_92 . V_93 . V_94 ;
T_1 V_95 = V_91 -> V_96 ;
struct V_97 * V_98 = & V_9 -> V_78 [ 0 ] -> V_99 ;
F_14 ( V_72 ,
L_9 ,
V_76 , V_91 -> V_100 ,
V_91 -> V_51 , V_95 ) ;
if ( V_98 -> V_101 ) {
if ( ! V_2 -> V_102 &&
( F_30 ( V_9 ) != V_95 ) ) {
F_14 ( V_72 , L_10 , V_95 ) ;
if ( ! F_31 ( V_2 , true ) )
V_2 -> V_102 = true ;
}
}
V_46 = F_32 ( V_2 ) ;
if ( ! V_46 )
V_46 = F_33 ( V_9 -> V_58 , V_91 ) ;
if ( V_98 -> V_101 ) {
if ( V_2 -> V_102 &&
( F_30 ( V_9 ) == V_95 ) ) {
F_14 ( V_72 , L_11 , V_95 ) ;
if ( ! F_31 ( V_2 , false ) )
V_2 -> V_102 = false ;
}
} else {
if ( V_2 -> V_102 ) {
F_14 ( V_72 , L_11 , V_95 ) ;
if ( ! F_31 ( V_2 , false ) )
V_2 -> V_102 = false ;
}
}
return V_46 ;
}
static int F_34 ( struct V_38 * V_39 )
{
struct V_8 * V_9 = V_39 -> V_58 ;
struct V_1 * V_2 = V_9 -> V_58 ;
struct V_103 * V_92 = & V_39 -> V_92 ;
if ( V_9 -> V_70 <= 0 ) {
F_14 ( V_50 , L_12 , V_76 ) ;
return - V_104 ;
}
F_14 ( V_72 ,
L_13 , V_76 , V_92 -> V_105 ) ;
if ( V_92 -> V_105 == V_2 -> V_106 )
return 0 ;
V_2 -> V_106 = V_92 -> V_105 ;
return F_35 ( V_2 ) ;
}
static int F_36 ( struct V_38 * V_39 ,
T_2 V_107 )
{
struct V_8 * V_9 = V_39 -> V_58 ;
struct V_1 * V_2 = V_9 -> V_58 ;
struct V_62 * V_63 = V_9 -> V_78 [ 0 ] ;
struct V_103 * V_92 = & V_39 -> V_92 ;
int V_46 = - V_67 ;
F_20 ( & V_2 -> V_59 ) ;
if ( V_107 & V_108 )
V_46 = F_29 ( V_39 ) ;
if ( V_107 & V_109 ) {
F_14 ( V_72 , L_14 , V_76 ) ;
V_46 = F_34 ( V_39 ) ;
}
if ( ( V_107 & V_110 ) &&
( V_63 -> type == V_71 ) ) {
unsigned long V_51 ;
F_37 ( & V_9 -> V_111 , V_51 ) ;
if ( V_92 -> V_51 & V_112 )
F_38 ( V_9 ) ;
else
F_39 ( V_9 ) ;
F_40 ( & V_9 -> V_111 , V_51 ) ;
}
if ( V_107 & V_113 ) {
F_14 ( V_72 , L_15 ) ;
if ( ( V_2 -> V_114 ) <= V_115 ) {
F_14 ( V_72 ,
L_16 , V_76 ) ;
V_46 = F_41 ( V_2 ) ;
}
}
F_23 ( & V_2 -> V_59 ) ;
return V_46 ;
}
T_1 F_30 ( struct V_8 * V_9 )
{
struct V_62 * V_63 = V_9 -> V_78 [ 0 ] ;
if ( V_63 ) {
struct V_97 * V_98 = & V_63 -> V_99 ;
struct V_90 * V_95 = V_98 -> V_93 . V_94 ;
return V_95 -> V_96 ;
}
return 0 ;
}
static void F_42 ( struct V_38 * V_39 ,
struct V_62 * V_63 ,
struct V_97 * V_99 ,
T_2 V_107 )
{
struct V_8 * V_9 = V_39 -> V_58 ;
struct V_1 * V_2 = V_9 -> V_58 ;
struct V_97 * V_98 = & V_63 -> V_99 ;
struct V_103 * V_92 = & V_39 -> V_92 ;
T_1 V_116 = 0 ;
F_20 ( & V_2 -> V_59 ) ;
if ( V_107 & V_117 ) {
F_14 ( V_72 , L_17 ,
V_76 , V_99 -> V_101 ) ;
if ( V_99 -> V_101 ) {
V_116 = ( V_118 |
V_119 |
V_120 ) ;
F_22 ( V_2 , V_116 ) ;
}
F_43 ( V_2 ,
V_73 ,
V_99 -> V_101 ,
V_99 -> V_121 ,
V_99 -> V_122 ,
V_99 -> V_123 ,
NULL , 0 ) ;
V_9 -> V_124 . V_125 = V_98 -> V_126 ;
V_9 -> V_124 . V_127 = V_92 -> V_127 ;
if ( V_98 -> V_101 ) {
if ( V_2 -> V_128 ) {
F_14 ( V_72 , L_18 ) ;
F_44 ( V_9 ) ;
}
} else {
V_2 -> V_128 = 0 ;
}
}
if ( V_107 & V_129 ) {
V_2 -> V_130 . V_131 = 0 ;
V_2 -> V_130 . V_132 = V_99 -> V_133 ;
V_2 -> V_130 . V_134 = V_99 -> V_135 ;
F_14 ( V_72 , L_19 ,
V_2 -> V_130 . V_132 ,
V_2 -> V_130 . V_134 ) ;
}
if ( ( V_107 & V_136 ) &&
( V_63 -> type == V_74 ) ) {
if ( V_98 -> V_137 ) {
F_14 ( V_72 , L_20 ) ;
V_2 -> V_138 = 1 ;
} else {
F_14 ( V_72 , L_21 ) ;
V_2 -> V_138 = 0 ;
}
}
F_23 ( & V_2 -> V_59 ) ;
}
static void F_45 ( struct V_38 * V_39 ,
T_2 V_139 ,
T_2 * V_140 ,
T_3 V_141 )
{
* V_140 &= V_142 ;
}
static int F_46 ( struct V_38 * V_39 ,
struct V_62 * V_63 , T_1 V_143 ,
const struct V_144 * V_145 )
{
struct V_8 * V_9 = V_39 -> V_58 ;
struct V_1 * V_2 = V_9 -> V_58 ;
T_4 V_146 = 0 ;
if ( V_143 >= V_147 )
return 0 ;
F_14 ( V_72 ,
L_22 ,
V_76 , V_143 , V_145 -> V_148 ,
V_145 -> V_149 , V_145 -> V_150 , V_145 -> V_151 ) ;
F_20 ( & V_2 -> V_59 ) ;
switch ( V_143 ) {
case V_152 :
V_146 = V_153 ;
break;
case V_154 :
V_146 = V_155 ;
break;
case V_156 :
V_146 = V_157 ;
break;
case V_158 :
V_146 = V_159 ;
break;
default:
V_146 = V_157 ;
break;
}
memcpy ( & V_2 -> V_160 [ V_146 ] ,
V_145 ,
sizeof( struct V_144 ) ) ;
if ( V_145 -> V_161 )
V_2 -> V_128 |= V_146 ;
else
V_2 -> V_128 &= ( ~ V_146 ) ;
F_23 ( & V_2 -> V_59 ) ;
return 0 ;
}
static int F_47 ( struct V_38 * V_39 ,
struct V_62 * V_63 ,
struct V_162 * V_163 ,
struct V_164 * V_87 )
{
struct V_8 * V_9 = V_39 -> V_58 ;
struct V_165 * V_166 = NULL ;
int V_46 ;
T_4 V_167 ;
T_5 V_168 = 0 ;
if ( V_163 -> V_51 & V_169 )
V_167 = V_170 ;
else
V_167 = V_171 ;
F_14 ( V_50 , L_23 ,
V_76 , V_163 -> V_172 , V_167 , V_163 -> V_173 ) ;
if ( V_63 -> type == V_74 ) {
if ( V_87 ) {
V_166 = F_48 ( V_9 -> V_58 , V_87 -> V_88 ) ;
if ( V_166 )
V_168 = V_166 -> V_168 ;
}
V_9 -> V_58 -> V_163 = V_163 ;
} else {
if ( ( V_163 -> V_172 == V_5 ) ||
( V_163 -> V_172 == V_6 ) ) {
V_46 = F_49 ( V_9 -> V_58 ,
V_163 -> V_163 ,
V_163 -> V_173 ,
V_170 ,
V_163 -> V_174 ,
V_163 -> V_172 ,
V_168 ) ;
if ( V_46 )
return V_46 ;
}
}
return F_49 ( V_9 -> V_58 ,
V_163 -> V_163 ,
V_163 -> V_173 ,
V_167 ,
V_163 -> V_174 ,
V_163 -> V_172 ,
V_168 ) ;
}
static int F_50 ( struct V_38 * V_39 ,
enum V_175 V_176 ,
struct V_62 * V_63 ,
struct V_164 * V_87 ,
struct V_162 * V_163 )
{
struct V_8 * V_9 = V_39 -> V_58 ;
struct V_1 * V_2 = V_9 -> V_58 ;
struct V_177 * V_3 = & V_2 -> V_3 ;
int V_46 ;
F_20 ( & V_2 -> V_59 ) ;
switch ( V_176 ) {
case V_178 :
V_3 -> V_179 = true ;
V_46 = F_47 ( V_39 , V_63 , V_163 , V_87 ) ;
if ( V_46 ) {
F_23 ( & V_2 -> V_59 ) ;
return V_46 ;
}
if ( V_163 -> V_51 & V_169 )
V_3 -> V_7 = V_163 -> V_172 ;
else
V_3 -> V_4 = V_163 -> V_172 ;
V_163 -> V_180 = V_163 -> V_174 ;
V_163 -> V_51 |= V_181 ;
F_14 ( V_50 , L_24 , V_76 ) ;
break;
case V_182 :
if ( V_63 -> type == V_71 )
V_3 -> V_179 = false ;
F_14 ( V_50 , L_25 , V_76 ) ;
memset ( V_163 , 0 , sizeof( struct V_162 ) ) ;
V_46 = F_47 ( V_39 , V_63 , V_163 , V_87 ) ;
break;
default:
V_46 = - V_67 ;
break;
}
F_23 ( & V_2 -> V_59 ) ;
return V_46 ;
}
static int F_51 ( struct V_38 * V_39 ,
struct V_62 * V_63 ,
struct V_183 * V_145 )
{
int V_46 = - V_67 ;
struct V_8 * V_9 = V_39 -> V_58 ;
struct V_1 * V_2 = V_9 -> V_58 ;
struct V_165 * V_166 = NULL ;
T_1 V_184 = 0 , V_185 = 0 ;
T_4 V_186 = 0 ;
struct V_164 * V_87 = V_145 -> V_87 ;
T_4 V_168 = 0 ;
enum V_187 V_188 = V_145 -> V_188 ;
T_1 V_189 = V_145 -> V_189 ;
T_1 * V_190 = & V_145 -> V_190 ;
T_4 V_191 = V_145 -> V_191 ;
for ( V_186 = 0 ; V_186 < V_192 ; V_186 ++ ) {
if ( V_63 == V_9 -> V_78 [ V_186 ] )
break;
}
F_20 ( & V_2 -> V_59 ) ;
if ( V_190 != NULL )
V_184 = * V_190 ;
if ( V_63 -> type == V_74 ) {
V_166 = F_48 ( V_2 , V_87 -> V_88 ) ;
if ( ! V_166 ) {
F_14 ( V_50 , L_26 ) ;
V_46 = 0 ;
goto V_193;
}
V_168 = V_166 -> V_168 ;
}
F_14 ( V_72 ,
L_27 ,
V_76 , V_189 , V_184 , V_191 , V_168 ) ;
switch ( V_188 ) {
case V_194 :
V_46 = F_52 ( V_2 ,
V_189 ,
V_184 ,
V_191 ,
V_195 ,
V_168 ) ;
break;
case V_196 :
V_46 = F_52 ( V_2 ,
V_189 ,
0 ,
V_191 ,
V_197 ,
V_168 ) ;
break;
case V_198 :
if ( V_63 -> type == V_71 )
V_2 -> V_199 [ V_186 ] . V_185 = V_184 ;
else if ( V_63 -> type == V_74 )
V_166 -> V_185 [ V_189 ] = V_184 ;
F_53 ( V_63 , V_87 -> V_88 , V_189 ) ;
V_46 = 0 ;
break;
case V_200 :
case V_201 :
case V_202 :
V_46 = F_52 ( V_2 ,
V_189 ,
V_184 ,
V_191 ,
V_203 ,
V_168 ) ;
if ( ! V_46 )
F_54 ( V_63 , V_87 -> V_88 , V_189 ) ;
break;
case V_204 :
if ( V_63 -> type == V_71 )
V_185 = V_2 -> V_199 [ V_186 ] . V_185 ;
else if ( V_63 -> type == V_74 )
V_185 = V_166 -> V_185 [ V_189 ] ;
V_46 = F_52 ( V_2 ,
V_189 ,
V_185 ,
V_191 ,
V_205 ,
V_168 ) ;
break;
default:
F_14 ( V_50 , L_28 , V_76 ) ;
break;
}
V_193:
F_23 ( & V_2 -> V_59 ) ;
return V_46 ;
}
static int F_55 ( struct V_38 * V_39 ,
T_2 V_206 )
{
struct V_8 * V_9 = V_39 -> V_58 ;
struct V_1 * V_2 = V_9 -> V_58 ;
F_20 ( & V_2 -> V_59 ) ;
V_2 -> V_114 = V_206 ;
F_23 ( & V_2 -> V_59 ) ;
return 0 ;
}
static int F_56 ( struct V_38 * V_39 ,
struct V_62 * V_63 ,
const struct V_207 * V_208 )
{
struct V_8 * V_9 = V_39 -> V_58 ;
struct V_1 * V_2 = V_9 -> V_58 ;
enum V_40 V_10 = V_39 -> V_92 . V_93 . V_94 -> V_10 ;
F_20 ( & V_2 -> V_59 ) ;
V_2 -> V_209 [ V_10 ] = 0 ;
if ( V_208 -> V_57 [ V_10 ] . V_210 == 0xfff ) {
V_2 -> V_209 [ V_10 ] =
( V_208 -> V_57 [ V_10 ] . V_211 [ 0 ] << 12 ) ;
} else {
V_2 -> V_209 [ V_10 ] =
V_208 -> V_57 [ V_10 ] . V_210 ;
}
F_23 ( & V_2 -> V_59 ) ;
return 0 ;
}
static void F_57 ( struct V_1 * V_2 ,
T_4 * V_121 ,
T_6 V_212 )
{
struct V_8 * V_9 = V_2 -> V_58 ;
T_6 V_213 = V_2 -> V_130 . V_131 ;
int V_214 = V_2 -> V_130 . V_132 ;
T_2 V_215 = V_2 -> V_130 . V_134 ;
enum V_216 V_217 ;
if ( V_212 < V_214 && ( V_213 == 0 || V_212 < ( V_213 - V_215 ) ) )
V_217 = V_218 ;
else if ( V_212 > V_214 &&
( V_213 == 0 || V_212 > ( V_213 + V_215 ) ) )
V_217 = V_219 ;
else
return;
V_2 -> V_130 . V_131 = V_212 ;
F_14 ( V_72 , L_29 , V_217 ) ;
F_58 ( V_9 -> V_78 [ 0 ] , V_217 , V_212 , V_16 ) ;
return;
}
static void F_59 ( struct V_38 * V_39 ,
struct V_44 * V_45 ,
struct V_1 * V_2 ,
struct V_220 * V_221 )
{
struct V_97 * V_98 = & V_2 -> V_58 -> V_78 [ 0 ] -> V_99 ;
struct V_47 * V_48 = F_13 ( V_45 ) ;
struct V_49 * V_222 = (struct V_49 * ) V_48 -> V_53 ;
struct V_223 * V_224 ;
char V_212 = V_222 -> V_212 ;
T_4 V_225 = 0 ;
T_4 V_95 = V_222 -> V_95 ;
T_7 V_226 ;
V_224 = ( (struct V_223 * ) ( V_45 -> V_227 ) ) ;
V_225 = F_60 ( V_224 -> V_228 ) ;
memset ( V_48 , 0 , sizeof( struct V_47 ) ) ;
V_221 -> signal = - ( V_212 ) ;
V_221 -> V_10 = V_2 -> V_10 ;
V_226 = F_61 ( V_95 , V_221 -> V_10 ) ;
if ( V_226 )
V_221 -> V_226 = V_226 ;
if ( F_62 ( V_224 -> V_228 ) ) {
if ( F_1 ( V_2 ) ) {
memmove ( V_45 -> V_227 + 4 , V_45 -> V_227 , V_225 ) ;
F_15 ( V_45 , 4 ) ;
} else {
memmove ( V_45 -> V_227 + 8 , V_45 -> V_227 , V_225 ) ;
F_15 ( V_45 , 8 ) ;
V_221 -> V_229 |= V_230 ;
}
V_221 -> V_229 |= V_231 ;
V_221 -> V_229 |= V_232 ;
}
if ( V_98 -> V_101 && ! ( memcmp ( V_98 -> V_121 , V_224 -> V_233 , V_234 ) ) ) {
if ( F_63 ( V_224 -> V_228 ) )
F_57 ( V_2 , V_224 -> V_233 , V_221 -> signal ) ;
}
return;
}
void F_64 ( struct V_1 * V_2 ,
struct V_44 * V_45 )
{
struct V_8 * V_9 = V_2 -> V_58 ;
struct V_38 * V_39 = V_9 -> V_39 ;
struct V_220 * V_235 = F_65 ( V_45 ) ;
if ( ( V_2 -> V_60 ) || ( ! V_9 -> V_70 ) ) {
F_66 ( V_45 ) ;
return;
}
F_59 ( V_39 , V_45 , V_2 , V_235 ) ;
F_67 ( V_39 , V_45 ) ;
}
static void F_68 ( struct V_38 * V_39 ,
struct V_164 * V_87 ,
struct V_1 * V_2 )
{
T_4 V_10 = V_39 -> V_92 . V_93 . V_94 -> V_10 ;
T_4 V_186 ;
T_2 V_236 ;
bool V_237 = false ;
V_2 -> V_238 [ V_10 ] = V_87 -> V_239 [ V_10 ] ;
V_236 = ( V_2 -> V_209 [ V_10 ] & V_87 -> V_239 [ V_10 ] ) ;
if ( V_236 & 0xfff ) {
for ( V_186 = 0 ; V_186 < F_4 ( V_19 ) ; V_186 ++ ) {
if ( V_236 & F_69 ( V_186 ) ) {
V_2 -> V_83 = V_19 [ V_186 ] . V_96 ;
V_237 = true ;
break;
}
}
}
V_2 -> V_199 [ 0 ] . V_240 = V_87 -> V_23 . V_25 ;
if ( ( V_2 -> V_199 [ 0 ] . V_240 ) && ( V_236 >> 12 ) ) {
for ( V_186 = 0 ; V_186 < F_4 ( V_241 ) ; V_186 ++ ) {
if ( ( V_236 >> 12 ) & F_69 ( V_186 ) ) {
V_2 -> V_83 = V_241 [ V_186 ] ;
V_237 = true ;
break;
}
}
}
if ( ! V_237 )
V_2 -> V_83 = 0xffff ;
}
static int F_70 ( struct V_38 * V_39 ,
struct V_62 * V_63 ,
struct V_164 * V_87 )
{
struct V_8 * V_9 = V_39 -> V_58 ;
struct V_1 * V_2 = V_9 -> V_58 ;
bool V_242 = false ;
struct V_165 * V_166 ;
int V_46 = 0 ;
F_14 ( V_72 , L_30 , V_87 -> V_88 ) ;
F_20 ( & V_2 -> V_59 ) ;
if ( V_63 -> type == V_74 ) {
T_4 V_243 ;
int V_244 = - 1 ;
int V_245 = - 1 ;
if ( V_2 -> V_246 >= V_2 -> V_85 ) {
F_14 ( V_50 , L_31 ) ;
V_46 = - V_67 ;
goto V_193;
}
for ( V_243 = 0 ; V_243 < V_2 -> V_85 ; V_243 ++ ) {
V_166 = & V_2 -> V_86 [ V_243 ] ;
if ( ! V_166 -> V_87 ) {
if ( V_245 < 0 )
V_245 = V_243 ;
continue;
}
if ( ! memcmp ( V_166 -> V_87 -> V_88 , V_87 -> V_88 , V_234 ) ) {
F_14 ( V_72 , L_32 ) ;
V_244 = V_243 ;
V_242 = true ;
break;
}
}
if ( ! V_242 ) {
if ( V_245 >= 0 )
V_244 = V_245 ;
}
if ( V_244 < 0 ) {
F_14 ( V_50 ,
L_33 ,
V_76 ) ;
V_46 = - V_104 ;
goto V_193;
}
V_166 = & V_2 -> V_86 [ V_244 ] ;
V_166 -> V_87 = V_87 ;
V_166 -> V_168 = V_244 ;
for ( V_243 = 0 ; V_243 < V_247 ; V_243 ++ )
V_166 -> V_248 [ V_243 ] = false ;
for ( V_243 = 0 ; V_243 < V_247 ; V_243 ++ )
V_166 -> V_185 [ V_243 ] = 0 ;
if ( ! V_242 ) {
F_14 ( V_72 , L_34 ) ;
F_14 ( V_72 , L_35 ) ;
F_43 ( V_2 , V_75 , 1 , V_87 -> V_88 ,
V_87 -> V_249 , V_87 -> V_123 , V_87 , V_244 ) ;
if ( V_2 -> V_163 ) {
struct V_162 * V_163 = V_2 -> V_163 ;
if ( ( V_163 -> V_172 == V_5 ) ||
( V_163 -> V_172 == V_6 ) )
F_49 ( V_9 -> V_58 ,
V_163 -> V_163 ,
V_163 -> V_173 ,
V_170 ,
V_163 -> V_174 ,
V_163 -> V_172 ,
V_244 ) ;
}
V_2 -> V_246 ++ ;
}
}
if ( V_63 -> type == V_71 ) {
F_68 ( V_39 , V_87 , V_2 ) ;
if ( V_87 -> V_23 . V_25 ) {
V_2 -> V_199 [ 0 ] . V_240 = true ;
V_2 -> V_238 [ V_14 ] =
V_87 -> V_239 [ V_14 ] ;
if ( ( V_87 -> V_23 . V_26 & V_28 ) ||
( V_87 -> V_23 . V_26 & V_29 ) )
V_2 -> V_199 [ 0 ] . V_250 = true ;
F_71 ( V_87 , 0 , 0 ) ;
}
}
V_193:
F_23 ( & V_2 -> V_59 ) ;
return V_46 ;
}
static int F_72 ( struct V_38 * V_39 ,
struct V_62 * V_63 ,
struct V_164 * V_87 )
{
struct V_8 * V_9 = V_39 -> V_58 ;
struct V_1 * V_2 = V_9 -> V_58 ;
struct V_97 * V_98 = & V_63 -> V_99 ;
struct V_165 * V_166 ;
F_14 ( V_72 , L_36 , V_87 -> V_88 ) ;
F_20 ( & V_2 -> V_59 ) ;
if ( V_63 -> type == V_74 ) {
T_4 V_244 , V_243 ;
F_14 ( V_72 , L_35 ) ;
for ( V_244 = 0 ; V_244 < V_2 -> V_85 ; V_244 ++ ) {
V_166 = & V_2 -> V_86 [ V_244 ] ;
if ( ! V_166 -> V_87 )
continue;
if ( ! memcmp ( V_166 -> V_87 -> V_88 , V_87 -> V_88 , V_234 ) ) {
F_43 ( V_2 , V_75 , 0 ,
V_87 -> V_88 , V_87 -> V_249 ,
V_87 -> V_123 , V_87 , V_244 ) ;
V_166 -> V_87 = NULL ;
V_166 -> V_168 = - 1 ;
for ( V_243 = 0 ; V_243 < V_247 ; V_243 ++ )
V_166 -> V_248 [ V_243 ] = false ;
if ( V_2 -> V_246 > 0 )
V_2 -> V_246 -- ;
break;
}
}
if ( V_244 >= V_2 -> V_85 )
F_14 ( V_50 , L_37 , V_76 ) ;
}
if ( V_63 -> type == V_71 ) {
memcpy ( ( T_4 * ) V_98 -> V_121 , ( T_4 * ) V_87 -> V_88 , V_234 ) ;
V_98 -> V_122 = V_87 -> V_249 ;
V_2 -> V_238 [ V_14 ] = 0 ;
V_2 -> V_238 [ V_22 ] = 0 ;
V_2 -> V_83 = 0xffff ;
V_2 -> V_199 [ 0 ] . V_240 = false ;
V_2 -> V_199 [ 0 ] . V_250 = false ;
V_2 -> V_199 [ 0 ] . V_185 = 0 ;
V_2 -> V_3 . V_7 = 0 ;
V_2 -> V_3 . V_4 = 0 ;
if ( ! V_2 -> V_60 )
F_22 ( V_2 , 0 ) ;
}
F_23 ( & V_2 -> V_59 ) ;
return 0 ;
}
static int F_73 ( struct V_38 * V_39 ,
T_2 V_251 , T_2 V_252 )
{
struct V_8 * V_9 = V_39 -> V_58 ;
struct V_1 * V_2 = V_9 -> V_58 ;
T_4 V_253 = 0 ;
if ( V_251 > 1 || V_252 > 1 ) {
F_14 ( V_50 ,
L_38 ,
V_251 , V_252 ) ;
F_14 ( V_50 ,
L_39 ) ;
return - V_104 ;
}
F_14 ( V_72 , L_40 ,
V_76 , V_251 , V_252 ) ;
F_20 ( & V_2 -> V_59 ) ;
V_253 = V_251 ? V_254 : V_255 ;
if ( V_2 -> V_256 != V_253 )
if ( F_74 ( V_2 , V_253 ) )
goto V_257;
F_14 ( V_72 , L_41 ,
V_251 ? L_42 : L_43 ) ;
V_2 -> V_256 = V_253 ;
F_23 ( & V_2 -> V_59 ) ;
return 0 ;
V_257:
F_14 ( V_50 , L_44 , V_76 ) ;
F_23 ( & V_2 -> V_59 ) ;
return - V_104 ;
}
static int F_75 ( struct V_38 * V_39 ,
T_2 * V_251 , T_2 * V_252 )
{
struct V_8 * V_9 = V_39 -> V_58 ;
struct V_1 * V_2 = V_9 -> V_58 ;
F_20 ( & V_2 -> V_59 ) ;
* V_251 = ( V_2 -> V_256 == V_254 ) ? 1 : 0 ;
* V_252 = 0 ;
F_23 ( & V_2 -> V_59 ) ;
return 0 ;
}
static int F_76 ( enum V_258 V_259 )
{
switch ( V_259 ) {
case V_260 :
return V_261 ;
case V_262 :
return V_263 ;
case V_264 :
return V_265 ;
case V_266 :
return V_267 ;
}
return V_267 ;
}
static void F_77 ( struct V_61 * V_61 ,
struct V_268 * V_269 )
{
struct V_11 * V_42 ;
struct V_90 * V_270 ;
struct V_38 * V_39 = F_78 ( V_61 ) ;
struct V_8 * V_9 = V_39 -> V_58 ;
struct V_1 * V_2 = V_9 -> V_58 ;
int V_81 ;
F_20 ( & V_2 -> V_59 ) ;
F_14 ( V_72 , L_45 ,
V_269 -> V_271 , V_269 -> V_272 ) ;
if ( V_2 -> V_273 > 1 ) {
V_42 = V_61 -> V_274 [ V_22 ] ;
for ( V_81 = 0 ; V_81 < V_42 -> V_17 ; V_81 ++ ) {
V_270 = & V_42 -> V_13 [ V_81 ] ;
if ( V_270 -> V_51 & V_275 )
continue;
if ( V_270 -> V_51 & V_276 )
V_270 -> V_51 |= V_277 ;
}
}
V_9 -> V_272 = F_76 ( V_269 -> V_272 ) ;
F_14 ( V_72 , L_46 , V_9 -> V_272 ) ;
V_9 -> V_278 [ 0 ] = V_269 -> V_271 [ 0 ] ;
V_9 -> V_278 [ 1 ] = V_269 -> V_271 [ 1 ] ;
F_23 ( & V_2 -> V_59 ) ;
}
static void F_79 ( struct V_38 * V_39 )
{
struct V_8 * V_9 = V_39 -> V_58 ;
struct V_1 * V_2 = V_9 -> V_58 ;
F_20 ( & V_2 -> V_59 ) ;
if ( V_2 -> V_279 != V_280 )
F_80 ( V_39 -> V_61 , true ) ;
else
F_80 ( V_39 -> V_61 , false ) ;
F_23 ( & V_2 -> V_59 ) ;
}
int F_81 ( struct V_1 * V_2 )
{
int V_46 = 0 ;
struct V_38 * V_39 = NULL ;
struct V_61 * V_61 = NULL ;
struct V_8 * V_9 = V_2 -> V_58 ;
T_4 V_281 [ V_234 ] = { 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x3 } ;
F_14 ( V_282 , L_47 , V_76 ) ;
V_39 = F_82 ( sizeof( struct V_8 ) , & V_283 ) ;
if ( ! V_39 ) {
F_14 ( V_50 , L_48 , V_76 ) ;
return - V_284 ;
}
V_61 = V_39 -> V_61 ;
F_83 ( V_39 , V_9 -> V_285 ) ;
V_39 -> V_58 = V_9 ;
V_9 -> V_39 = V_39 ;
F_84 ( V_39 , V_286 ) ;
F_84 ( V_39 , V_287 ) ;
F_84 ( V_39 , V_288 ) ;
F_84 ( V_39 , V_289 ) ;
F_84 ( V_39 , V_290 ) ;
V_39 -> V_291 = V_292 ;
V_39 -> V_293 = V_294 ;
V_39 -> V_295 = 1 ;
V_39 -> V_296 = V_297 ;
V_39 -> V_298 = V_299 ;
V_39 -> V_300 = V_301 ;
V_39 -> V_302 = 6 ;
F_2 ( V_9 , V_14 ) ;
F_2 ( V_9 , V_22 ) ;
V_39 -> V_303 = L_49 ;
F_85 ( V_39 , V_2 -> V_79 ) ;
F_86 ( V_39 -> V_61 -> V_281 , V_281 ) ;
V_61 -> V_304 = F_69 ( V_71 ) |
F_69 ( V_74 ) ;
V_61 -> V_305 = V_306 ;
V_61 -> V_307 = V_308 ;
V_61 -> V_309 = V_310 ;
V_61 -> V_311 = V_312 ;
V_61 -> V_114 = V_115 ;
V_61 -> V_51 = 0 ;
V_61 -> V_313 = 1 ;
V_61 -> V_314 = 1 ;
V_61 -> V_274 [ V_14 ] =
& V_9 -> V_12 [ V_14 ] ;
V_61 -> V_274 [ V_22 ] =
& V_9 -> V_12 [ V_22 ] ;
V_61 -> V_315 = V_316 [ V_2 -> V_317 - 1 ] ;
V_2 -> V_85 = V_61 -> V_315 ;
F_14 ( V_50 , L_50 , V_2 -> V_85 ) ;
V_39 -> V_318 = sizeof( struct V_165 ) ;
V_61 -> V_51 = V_319 ;
V_61 -> V_51 |= V_320 ;
V_61 -> V_321 |= V_322 ;
V_61 -> V_323 = F_77 ;
F_87 ( V_61 , V_324 ) ;
V_46 = F_88 ( V_39 ) ;
if ( V_46 )
return V_46 ;
return F_89 ( V_9 ) ;
}
