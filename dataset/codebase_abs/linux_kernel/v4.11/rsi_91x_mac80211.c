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
memset ( V_48 -> V_49 , 0 , V_50 ) ;
if ( ! V_46 )
V_48 -> V_51 |= V_52 ;
F_14 ( V_9 -> V_39 , V_45 ) ;
}
static void F_15 ( struct V_38 * V_39 ,
struct V_53 * V_54 ,
struct V_44 * V_45 )
{
struct V_8 * V_9 = V_39 -> V_55 ;
struct V_1 * V_2 = V_9 -> V_55 ;
F_16 ( V_2 , V_45 ) ;
}
static int F_17 ( struct V_38 * V_39 )
{
struct V_8 * V_9 = V_39 -> V_55 ;
struct V_1 * V_2 = V_9 -> V_55 ;
F_18 ( & V_2 -> V_56 ) ;
V_2 -> V_57 = false ;
F_19 ( & V_2 -> V_56 ) ;
F_20 ( V_2 , 0 ) ;
return 0 ;
}
static void F_21 ( struct V_38 * V_39 )
{
struct V_8 * V_9 = V_39 -> V_55 ;
struct V_1 * V_2 = V_9 -> V_55 ;
F_18 ( & V_2 -> V_56 ) ;
V_2 -> V_57 = true ;
F_19 ( & V_2 -> V_56 ) ;
}
static int F_22 ( struct V_38 * V_39 ,
struct V_58 * V_59 )
{
struct V_8 * V_9 = V_39 -> V_55 ;
struct V_1 * V_2 = V_9 -> V_55 ;
int V_60 = - V_61 ;
F_18 ( & V_2 -> V_56 ) ;
switch ( V_59 -> type ) {
case V_62 :
if ( ! V_9 -> V_63 ) {
++ V_9 -> V_63 ;
V_9 -> V_64 [ 0 ] = V_59 ;
V_60 = F_23 ( V_2 ,
V_65 ,
V_66 ) ;
}
break;
default:
F_24 ( V_67 ,
L_1 , V_68 ,
V_59 -> type ) ;
}
F_19 ( & V_2 -> V_56 ) ;
return V_60 ;
}
static void F_25 ( struct V_38 * V_39 ,
struct V_58 * V_59 )
{
struct V_8 * V_9 = V_39 -> V_55 ;
struct V_1 * V_2 = V_9 -> V_55 ;
F_18 ( & V_2 -> V_56 ) ;
if ( V_59 -> type == V_62 ) {
V_9 -> V_63 -- ;
F_23 ( V_2 , V_65 , V_69 ) ;
}
if ( ! memcmp ( V_9 -> V_64 [ 0 ] , V_59 , sizeof( struct V_58 ) ) )
V_9 -> V_64 [ 0 ] = NULL ;
F_19 ( & V_2 -> V_56 ) ;
}
static int F_26 ( struct V_38 * V_39 )
{
struct V_8 * V_9 = V_39 -> V_55 ;
struct V_1 * V_2 = V_9 -> V_55 ;
int V_46 = - V_61 ;
struct V_70 * V_71 = V_39 -> V_72 . V_73 . V_74 ;
T_1 V_75 = V_71 -> V_76 ;
struct V_77 * V_78 = & V_9 -> V_64 [ 0 ] -> V_79 ;
F_24 ( V_80 ,
L_2 ,
V_68 , V_71 -> V_81 ,
V_71 -> V_51 , V_75 ) ;
if ( V_78 -> V_82 ) {
if ( ! V_2 -> V_83 &&
( F_27 ( V_9 ) != V_75 ) ) {
F_24 ( V_80 , L_3 , V_75 ) ;
if ( ! F_28 ( V_2 , true ) )
V_2 -> V_83 = true ;
}
}
V_46 = F_29 ( V_2 ) ;
if ( ! V_46 )
V_46 = F_30 ( V_9 -> V_55 , V_71 ) ;
if ( V_78 -> V_82 ) {
if ( V_2 -> V_83 &&
( F_27 ( V_9 ) == V_75 ) ) {
F_24 ( V_80 , L_4 , V_75 ) ;
if ( ! F_28 ( V_2 , false ) )
V_2 -> V_83 = false ;
}
} else {
if ( V_2 -> V_83 ) {
F_24 ( V_80 , L_4 , V_75 ) ;
if ( ! F_28 ( V_2 , false ) )
V_2 -> V_83 = false ;
}
}
return V_46 ;
}
static int F_31 ( struct V_38 * V_39 )
{
struct V_8 * V_9 = V_39 -> V_55 ;
struct V_1 * V_2 = V_9 -> V_55 ;
struct V_84 * V_72 = & V_39 -> V_72 ;
if ( V_9 -> V_63 <= 0 ) {
F_24 ( V_67 , L_5 , V_68 ) ;
return - V_85 ;
}
F_24 ( V_80 ,
L_6 , V_68 , V_72 -> V_86 ) ;
if ( V_72 -> V_86 == V_2 -> V_87 )
return 0 ;
V_2 -> V_87 = V_72 -> V_86 ;
return F_32 ( V_2 ) ;
}
static int F_33 ( struct V_38 * V_39 ,
T_2 V_88 )
{
struct V_8 * V_9 = V_39 -> V_55 ;
struct V_1 * V_2 = V_9 -> V_55 ;
int V_46 = - V_61 ;
F_18 ( & V_2 -> V_56 ) ;
if ( V_88 & V_89 )
V_46 = F_26 ( V_39 ) ;
if ( V_88 & V_90 ) {
F_24 ( V_80 , L_7 , V_68 ) ;
V_46 = F_31 ( V_39 ) ;
}
F_19 ( & V_2 -> V_56 ) ;
return V_46 ;
}
T_1 F_27 ( struct V_8 * V_9 )
{
struct V_58 * V_59 = V_9 -> V_64 [ 0 ] ;
if ( V_59 ) {
struct V_77 * V_78 = & V_59 -> V_79 ;
struct V_70 * V_75 = V_78 -> V_73 . V_74 ;
return V_75 -> V_76 ;
}
return 0 ;
}
static void F_34 ( struct V_38 * V_39 ,
struct V_58 * V_59 ,
struct V_77 * V_79 ,
T_2 V_88 )
{
struct V_8 * V_9 = V_39 -> V_55 ;
struct V_1 * V_2 = V_9 -> V_55 ;
T_1 V_91 = 0 ;
F_18 ( & V_2 -> V_56 ) ;
if ( V_88 & V_92 ) {
F_24 ( V_80 , L_8 ,
V_68 , V_79 -> V_82 ) ;
if ( V_79 -> V_82 ) {
V_91 = ( V_93 |
V_94 |
V_95 ) ;
F_20 ( V_2 , V_91 ) ;
}
F_35 ( V_2 ,
V_79 -> V_82 ,
V_79 -> V_96 ,
V_79 -> V_97 ,
V_79 -> V_98 ) ;
}
if ( V_88 & V_99 ) {
V_2 -> V_100 . V_101 = 0 ;
V_2 -> V_100 . V_102 = V_79 -> V_103 ;
V_2 -> V_100 . V_104 = V_79 -> V_105 ;
F_24 ( V_80 , L_9 ,
V_2 -> V_100 . V_102 ,
V_2 -> V_100 . V_104 ) ;
}
F_19 ( & V_2 -> V_56 ) ;
}
static void F_36 ( struct V_38 * V_39 ,
T_2 V_106 ,
T_2 * V_107 ,
T_3 V_108 )
{
* V_107 &= V_109 ;
}
static int F_37 ( struct V_38 * V_39 ,
struct V_58 * V_59 , T_1 V_110 ,
const struct V_111 * V_112 )
{
struct V_8 * V_9 = V_39 -> V_55 ;
struct V_1 * V_2 = V_9 -> V_55 ;
T_4 V_113 = 0 ;
if ( V_110 >= V_114 )
return 0 ;
F_24 ( V_80 ,
L_10 ,
V_68 , V_110 , V_112 -> V_115 ,
V_112 -> V_116 , V_112 -> V_117 , V_112 -> V_118 ) ;
F_18 ( & V_2 -> V_56 ) ;
switch ( V_110 ) {
case V_119 :
V_113 = V_120 ;
break;
case V_121 :
V_113 = V_122 ;
break;
case V_123 :
V_113 = V_124 ;
break;
case V_125 :
V_113 = V_126 ;
break;
default:
V_113 = V_124 ;
break;
}
memcpy ( & V_2 -> V_127 [ V_113 ] ,
V_112 ,
sizeof( struct V_111 ) ) ;
F_19 ( & V_2 -> V_56 ) ;
return 0 ;
}
static int F_38 ( struct V_38 * V_39 ,
struct V_58 * V_59 ,
struct V_128 * V_129 )
{
struct V_8 * V_9 = V_39 -> V_55 ;
int V_46 ;
T_4 V_130 ;
if ( V_129 -> V_51 & V_131 )
V_130 = V_132 ;
else
V_130 = V_133 ;
F_24 ( V_67 , L_11 ,
V_68 , V_129 -> V_134 , V_130 , V_129 -> V_135 ) ;
if ( ( V_129 -> V_134 == V_5 ) ||
( V_129 -> V_134 == V_6 ) ) {
V_46 = F_39 ( V_9 -> V_55 ,
V_129 -> V_129 ,
V_129 -> V_135 ,
V_132 ,
V_129 -> V_136 ,
V_129 -> V_134 ) ;
if ( V_46 )
return V_46 ;
}
return F_39 ( V_9 -> V_55 ,
V_129 -> V_129 ,
V_129 -> V_135 ,
V_130 ,
V_129 -> V_136 ,
V_129 -> V_134 ) ;
}
static int F_40 ( struct V_38 * V_39 ,
enum V_137 V_138 ,
struct V_58 * V_59 ,
struct V_139 * V_140 ,
struct V_128 * V_129 )
{
struct V_8 * V_9 = V_39 -> V_55 ;
struct V_1 * V_2 = V_9 -> V_55 ;
struct V_141 * V_3 = & V_2 -> V_3 ;
int V_46 ;
F_18 ( & V_2 -> V_56 ) ;
switch ( V_138 ) {
case V_142 :
V_3 -> V_143 = true ;
V_46 = F_38 ( V_39 , V_59 , V_129 ) ;
if ( V_46 ) {
F_19 ( & V_2 -> V_56 ) ;
return V_46 ;
}
if ( V_129 -> V_51 & V_131 )
V_3 -> V_7 = V_129 -> V_134 ;
else
V_3 -> V_4 = V_129 -> V_134 ;
V_129 -> V_144 = V_129 -> V_136 ;
V_129 -> V_51 |= V_145 ;
F_24 ( V_67 , L_12 , V_68 ) ;
break;
case V_146 :
V_3 -> V_143 = false ;
F_24 ( V_67 , L_13 , V_68 ) ;
memset ( V_129 , 0 , sizeof( struct V_128 ) ) ;
V_46 = F_38 ( V_39 , V_59 , V_129 ) ;
break;
default:
V_46 = - V_61 ;
break;
}
F_19 ( & V_2 -> V_56 ) ;
return V_46 ;
}
static int F_41 ( struct V_38 * V_39 ,
struct V_58 * V_59 ,
struct V_147 * V_112 )
{
int V_46 = - V_61 ;
struct V_8 * V_9 = V_39 -> V_55 ;
struct V_1 * V_2 = V_9 -> V_55 ;
T_1 V_148 = 0 ;
T_4 V_149 = 0 ;
struct V_139 * V_140 = V_112 -> V_140 ;
enum V_150 V_151 = V_112 -> V_151 ;
T_1 V_152 = V_112 -> V_152 ;
T_1 * V_153 = & V_112 -> V_153 ;
T_4 V_154 = V_112 -> V_154 ;
for ( V_149 = 0 ; V_149 < V_155 ; V_149 ++ ) {
if ( V_59 == V_9 -> V_64 [ V_149 ] )
break;
}
F_18 ( & V_2 -> V_56 ) ;
F_24 ( V_80 , L_14 , V_68 , V_151 ) ;
if ( V_153 != NULL )
V_148 = * V_153 ;
switch ( V_151 ) {
case V_156 :
V_46 = F_42 ( V_2 ,
V_152 ,
V_148 ,
V_154 ,
V_157 ) ;
break;
case V_158 :
V_46 = F_42 ( V_2 ,
V_152 ,
0 ,
V_154 ,
V_159 ) ;
break;
case V_160 :
V_2 -> V_161 [ V_149 ] . V_162 = V_148 ;
F_43 ( V_59 , V_140 -> V_163 , V_152 ) ;
V_46 = 0 ;
break;
case V_164 :
case V_165 :
case V_166 :
V_46 = F_42 ( V_2 ,
V_152 ,
V_148 ,
V_154 ,
V_167 ) ;
if ( ! V_46 )
F_44 ( V_59 , V_140 -> V_163 , V_152 ) ;
break;
case V_168 :
V_46 = F_42 ( V_2 ,
V_152 ,
V_2 -> V_161 [ V_149 ]
. V_162 ,
V_154 ,
V_169 ) ;
break;
default:
F_24 ( V_67 , L_15 , V_68 ) ;
break;
}
F_19 ( & V_2 -> V_56 ) ;
return V_46 ;
}
static int F_45 ( struct V_38 * V_39 ,
T_2 V_170 )
{
struct V_8 * V_9 = V_39 -> V_55 ;
struct V_1 * V_2 = V_9 -> V_55 ;
F_18 ( & V_2 -> V_56 ) ;
V_2 -> V_171 = V_170 ;
F_19 ( & V_2 -> V_56 ) ;
return 0 ;
}
static int F_46 ( struct V_38 * V_39 ,
struct V_58 * V_59 ,
const struct V_172 * V_173 )
{
struct V_8 * V_9 = V_39 -> V_55 ;
struct V_1 * V_2 = V_9 -> V_55 ;
enum V_40 V_10 = V_39 -> V_72 . V_73 . V_74 -> V_10 ;
F_18 ( & V_2 -> V_56 ) ;
V_2 -> V_174 [ V_10 ] = 0 ;
if ( V_173 -> V_54 [ V_10 ] . V_175 == 0xfff ) {
V_2 -> V_174 [ V_10 ] =
( V_173 -> V_54 [ V_10 ] . V_176 [ 0 ] << 12 ) ;
} else {
V_2 -> V_174 [ V_10 ] =
V_173 -> V_54 [ V_10 ] . V_175 ;
}
F_19 ( & V_2 -> V_56 ) ;
return 0 ;
}
static void F_47 ( struct V_1 * V_2 ,
T_4 * V_96 ,
T_5 V_177 )
{
struct V_8 * V_9 = V_2 -> V_55 ;
T_5 V_178 = V_2 -> V_100 . V_101 ;
int V_179 = V_2 -> V_100 . V_102 ;
T_2 V_180 = V_2 -> V_100 . V_104 ;
enum V_181 V_182 ;
if ( V_177 < V_179 && ( V_178 == 0 || V_177 < ( V_178 - V_180 ) ) )
V_182 = V_183 ;
else if ( V_177 > V_179 &&
( V_178 == 0 || V_177 > ( V_178 + V_180 ) ) )
V_182 = V_184 ;
else
return;
V_2 -> V_100 . V_101 = V_177 ;
F_24 ( V_80 , L_16 , V_182 ) ;
F_48 ( V_9 -> V_64 [ 0 ] , V_182 , V_177 , V_16 ) ;
return;
}
static void F_49 ( struct V_38 * V_39 ,
struct V_44 * V_45 ,
struct V_1 * V_2 ,
struct V_185 * V_186 )
{
struct V_77 * V_78 = & V_2 -> V_55 -> V_64 [ 0 ] -> V_79 ;
struct V_47 * V_48 = F_13 ( V_45 ) ;
struct V_187 * V_188 = (struct V_187 * ) V_48 -> V_49 ;
struct V_189 * V_190 ;
char V_177 = V_188 -> V_177 ;
T_4 V_191 = 0 ;
T_4 V_75 = V_188 -> V_75 ;
T_6 V_192 ;
V_190 = ( (struct V_189 * ) ( V_45 -> V_193 ) ) ;
V_191 = F_50 ( V_190 -> V_194 ) ;
memset ( V_48 , 0 , sizeof( struct V_47 ) ) ;
V_186 -> signal = - ( V_177 ) ;
V_186 -> V_10 = V_2 -> V_10 ;
V_192 = F_51 ( V_75 , V_186 -> V_10 ) ;
if ( V_192 )
V_186 -> V_192 = V_192 ;
if ( F_52 ( V_190 -> V_194 ) ) {
if ( F_1 ( V_2 ) ) {
memmove ( V_45 -> V_193 + 4 , V_45 -> V_193 , V_191 ) ;
F_53 ( V_45 , 4 ) ;
} else {
memmove ( V_45 -> V_193 + 8 , V_45 -> V_193 , V_191 ) ;
F_53 ( V_45 , 8 ) ;
V_186 -> V_195 |= V_196 ;
}
V_186 -> V_195 |= V_197 ;
V_186 -> V_195 |= V_198 ;
}
if ( V_78 -> V_82 && ! ( memcmp ( V_78 -> V_96 , V_190 -> V_199 , V_200 ) ) ) {
if ( F_54 ( V_190 -> V_194 ) )
F_47 ( V_2 , V_190 -> V_199 , V_186 -> signal ) ;
}
return;
}
void F_55 ( struct V_1 * V_2 ,
struct V_44 * V_45 )
{
struct V_8 * V_9 = V_2 -> V_55 ;
struct V_38 * V_39 = V_9 -> V_39 ;
struct V_185 * V_201 = F_56 ( V_45 ) ;
if ( ( V_2 -> V_57 ) || ( ! V_9 -> V_63 ) ) {
F_57 ( V_45 ) ;
return;
}
F_49 ( V_39 , V_45 , V_2 , V_201 ) ;
F_58 ( V_39 , V_45 ) ;
}
static void F_59 ( struct V_38 * V_39 ,
struct V_139 * V_140 ,
struct V_1 * V_2 )
{
T_4 V_10 = V_39 -> V_72 . V_73 . V_74 -> V_10 ;
T_4 V_149 ;
T_2 V_202 ;
bool V_203 = false ;
V_2 -> V_204 [ V_10 ] = V_140 -> V_205 [ V_10 ] ;
V_202 = ( V_2 -> V_174 [ V_10 ] & V_140 -> V_205 [ V_10 ] ) ;
if ( V_202 & 0xfff ) {
for ( V_149 = 0 ; V_149 < F_4 ( V_19 ) ; V_149 ++ ) {
if ( V_202 & F_60 ( V_149 ) ) {
V_2 -> V_206 = V_19 [ V_149 ] . V_76 ;
V_203 = true ;
break;
}
}
}
V_2 -> V_161 [ 0 ] . V_207 = V_140 -> V_23 . V_25 ;
if ( ( V_2 -> V_161 [ 0 ] . V_207 ) && ( V_202 >> 12 ) ) {
for ( V_149 = 0 ; V_149 < F_4 ( V_208 ) ; V_149 ++ ) {
if ( ( V_202 >> 12 ) & F_60 ( V_149 ) ) {
V_2 -> V_206 = V_208 [ V_149 ] ;
V_203 = true ;
break;
}
}
}
if ( ! V_203 )
V_2 -> V_206 = 0xffff ;
}
static int F_61 ( struct V_38 * V_39 ,
struct V_58 * V_59 ,
struct V_139 * V_140 )
{
struct V_8 * V_9 = V_39 -> V_55 ;
struct V_1 * V_2 = V_9 -> V_55 ;
F_18 ( & V_2 -> V_56 ) ;
F_59 ( V_39 , V_140 , V_2 ) ;
if ( ( V_140 -> V_23 . V_26 & V_28 ) ||
( V_140 -> V_23 . V_26 & V_29 ) ) {
V_2 -> V_161 [ 0 ] . V_209 = true ;
}
if ( V_140 -> V_23 . V_25 )
F_62 ( V_140 , 0 , 0 ) ;
F_19 ( & V_2 -> V_56 ) ;
return 0 ;
}
static int F_63 ( struct V_38 * V_39 ,
struct V_58 * V_59 ,
struct V_139 * V_140 )
{
struct V_8 * V_9 = V_39 -> V_55 ;
struct V_1 * V_2 = V_9 -> V_55 ;
F_18 ( & V_2 -> V_56 ) ;
V_2 -> V_204 [ V_14 ] = 0 ;
V_2 -> V_204 [ V_22 ] = 0 ;
V_2 -> V_206 = 0xffff ;
V_2 -> V_161 [ 0 ] . V_207 = false ;
V_2 -> V_161 [ 0 ] . V_209 = false ;
V_2 -> V_161 [ 0 ] . V_162 = 0 ;
V_2 -> V_3 . V_7 = 0 ;
V_2 -> V_3 . V_4 = 0 ;
F_20 ( V_2 , 0 ) ;
F_19 ( & V_2 -> V_56 ) ;
return 0 ;
}
static int F_64 ( struct V_38 * V_39 ,
T_2 V_210 , T_2 V_211 )
{
struct V_8 * V_9 = V_39 -> V_55 ;
struct V_1 * V_2 = V_9 -> V_55 ;
T_4 V_212 = 0 ;
if ( V_210 > 1 || V_211 > 1 ) {
F_24 ( V_67 ,
L_17 ,
V_210 , V_211 ) ;
F_24 ( V_67 ,
L_18 ) ;
return - V_85 ;
}
F_24 ( V_80 , L_19 ,
V_68 , V_210 , V_211 ) ;
F_18 ( & V_2 -> V_56 ) ;
V_212 = V_210 ? V_213 : V_214 ;
if ( V_2 -> V_215 != V_212 )
if ( F_65 ( V_2 , V_212 ) )
goto V_216;
F_24 ( V_80 , L_20 ,
V_210 ? L_21 : L_22 ) ;
V_2 -> V_215 = V_212 ;
F_19 ( & V_2 -> V_56 ) ;
return 0 ;
V_216:
F_24 ( V_67 , L_23 , V_68 ) ;
F_19 ( & V_2 -> V_56 ) ;
return - V_85 ;
}
static int F_66 ( struct V_38 * V_39 ,
T_2 * V_210 , T_2 * V_211 )
{
struct V_8 * V_9 = V_39 -> V_55 ;
struct V_1 * V_2 = V_9 -> V_55 ;
F_18 ( & V_2 -> V_56 ) ;
* V_210 = ( V_2 -> V_215 == V_213 ) ? 1 : 0 ;
* V_211 = 0 ;
F_19 ( & V_2 -> V_56 ) ;
return 0 ;
}
static void F_67 ( struct V_217 * V_217 ,
struct V_218 * V_219 )
{
struct V_11 * V_42 ;
struct V_70 * V_220 ;
struct V_38 * V_39 = F_68 ( V_217 ) ;
struct V_8 * V_9 = V_39 -> V_55 ;
int V_221 ;
V_42 = V_217 -> V_222 [ V_22 ] ;
for ( V_221 = 0 ; V_221 < V_42 -> V_17 ; V_221 ++ ) {
V_220 = & V_42 -> V_13 [ V_221 ] ;
if ( V_220 -> V_51 & V_223 )
continue;
if ( V_220 -> V_51 & V_224 )
V_220 -> V_51 |= V_225 ;
}
F_24 ( V_80 ,
L_24 ,
V_219 -> V_226 , V_219 -> V_227 ) ;
V_9 -> V_227 = V_219 -> V_227 ;
}
int F_69 ( struct V_1 * V_2 )
{
int V_46 = 0 ;
struct V_38 * V_39 = NULL ;
struct V_217 * V_217 = NULL ;
struct V_8 * V_9 = V_2 -> V_55 ;
T_4 V_228 [ V_200 ] = { 0x0 , 0x0 , 0x0 , 0x0 , 0x0 , 0x3 } ;
F_24 ( V_229 , L_25 , V_68 ) ;
V_39 = F_70 ( sizeof( struct V_8 ) , & V_230 ) ;
if ( ! V_39 ) {
F_24 ( V_67 , L_26 , V_68 ) ;
return - V_231 ;
}
V_217 = V_39 -> V_217 ;
F_71 ( V_39 , V_9 -> V_232 ) ;
V_39 -> V_55 = V_9 ;
V_9 -> V_39 = V_39 ;
F_72 ( V_39 , V_233 ) ;
F_72 ( V_39 , V_234 ) ;
F_72 ( V_39 , V_235 ) ;
V_39 -> V_236 = V_237 ;
V_39 -> V_238 = V_239 ;
V_39 -> V_240 = 1 ;
V_39 -> V_241 = V_242 ;
V_39 -> V_243 = 6 ;
F_2 ( V_9 , V_14 ) ;
F_2 ( V_9 , V_22 ) ;
V_39 -> V_244 = L_27 ;
F_73 ( V_39 , V_2 -> V_245 ) ;
F_74 ( V_39 -> V_217 -> V_228 , V_228 ) ;
V_217 -> V_246 = F_60 ( V_62 ) ;
V_217 -> V_247 = V_248 ;
V_217 -> V_249 = V_250 ;
V_217 -> V_251 = V_252 ;
V_217 -> V_253 = V_254 ;
V_217 -> V_171 = V_255 ;
V_217 -> V_51 = 0 ;
V_217 -> V_256 = 1 ;
V_217 -> V_257 = 1 ;
V_217 -> V_222 [ V_14 ] =
& V_9 -> V_12 [ V_14 ] ;
V_217 -> V_222 [ V_22 ] =
& V_9 -> V_12 [ V_22 ] ;
V_217 -> V_258 = F_67 ;
V_46 = F_75 ( V_39 ) ;
if ( V_46 )
return V_46 ;
return F_76 ( V_9 ) ;
}
