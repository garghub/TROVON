static bool F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
if ( ! F_2 ( V_5 , & V_2 -> V_6 ) )
return false ;
F_3 ( & V_2 -> V_7 ) ;
if ( V_4 -> V_8 == V_9 )
return true ;
F_4 ( V_4 -> V_10 , V_2 -> V_11 , false ) ;
return true ;
}
static void F_5 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
bool V_12 ;
V_12 = F_1 ( V_2 ) ;
if ( ! V_12 )
return;
F_6 ( V_4 -> V_13 , 0 ) ;
}
static int F_7 ( struct V_1 * V_2 ,
enum V_14 V_15 )
{
F_8 ( V_16 , L_1 , V_17 , V_15 ) ;
if ( ! V_15 ) {
V_2 -> V_18 = V_19 ;
} else if ( V_15 & V_20 ) {
V_2 -> V_18 = V_21 ;
} else if ( V_15 & V_22 ) {
V_2 -> V_18 = V_23 ;
} else {
F_9 ( L_2 , V_17 , V_15 ) ;
return - V_24 ;
}
return 0 ;
}
static int F_10 ( struct V_1 * V_2 ,
enum V_25 V_26 )
{
F_8 ( V_16 , L_3 , V_17 , V_26 ) ;
switch ( V_26 ) {
case V_27 :
V_2 -> V_28 = V_29 ;
break;
case V_30 :
V_2 -> V_28 = V_31 ;
break;
case V_32 :
V_2 -> V_28 = V_33 ;
break;
case V_34 :
V_2 -> V_28 = V_29 | V_31 ;
break;
default:
F_9 ( L_4 , V_17 , V_26 ) ;
return - V_24 ;
}
return 0 ;
}
static int F_11 ( struct V_1 * V_2 , T_1 V_35 , bool V_36 )
{
T_2 * V_37 = V_36 ? & V_2 -> V_38 : & V_2 -> V_39 ;
T_2 * V_40 = V_36 ? & V_2 -> V_41 :
& V_2 -> V_42 ;
F_8 ( V_16 , L_5 ,
V_17 , V_35 , V_36 ) ;
switch ( V_35 ) {
case 0 :
* V_37 = V_43 ;
* V_40 = 0 ;
break;
case V_44 :
* V_37 = V_45 ;
* V_40 = 5 ;
break;
case V_46 :
* V_37 = V_45 ;
* V_40 = 13 ;
break;
case V_47 :
* V_37 = V_48 ;
* V_40 = 0 ;
break;
case V_49 :
* V_37 = V_50 ;
* V_40 = 0 ;
break;
case V_51 :
* V_37 = V_52 ;
* V_40 = 0 ;
break;
default:
F_9 ( L_6 , V_35 ) ;
return - V_24 ;
}
return 0 ;
}
static void F_12 ( struct V_1 * V_2 , T_1 V_53 )
{
F_8 ( V_16 , L_3 , V_17 , V_53 ) ;
if ( V_53 == V_54 ) {
if ( V_2 -> V_18 == V_23 )
V_2 -> V_18 = V_55 ;
else if ( V_2 -> V_18 == V_21 )
V_2 -> V_18 = V_56 ;
} else if ( V_53 == 0x00409600 ) {
if ( V_2 -> V_18 == V_23 )
V_2 -> V_18 = V_57 ;
else if ( V_2 -> V_18 == V_21 )
V_2 -> V_18 = V_58 ;
} else if ( V_53 != V_59 ) {
V_2 -> V_18 = V_19 ;
}
}
static bool F_13 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
if ( ! F_14 ( V_60 , & V_4 -> V_61 ) ) {
F_9 ( L_7 ) ;
return false ;
}
if ( ! F_14 ( V_62 , & V_2 -> V_6 ) ) {
F_9 ( L_8 ) ;
return false ;
}
return true ;
}
static bool F_15 ( const T_2 * V_63 )
{
return V_63 [ 0 ] == V_64 && V_63 [ 1 ] >= 4 &&
V_63 [ 2 ] == 0x00 && V_63 [ 3 ] == 0x50 &&
V_63 [ 4 ] == 0xf2 && V_63 [ 5 ] == 0x01 ;
}
static bool F_16 ( const T_2 * V_63 )
{
return V_63 [ 0 ] == V_65 ;
}
static bool F_17 ( const T_2 * V_63 )
{
return ( V_63 [ 0 ] == V_64 &&
V_63 [ 1 ] >= 4 &&
V_63 [ 2 ] == 0x00 && V_63 [ 3 ] == 0x50 && V_63 [ 4 ] == 0xf2 &&
V_63 [ 5 ] == 0x04 ) ;
}
static int F_18 ( struct V_1 * V_2 , const T_2 * V_66 ,
T_3 V_67 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
const T_2 * V_63 ;
T_2 * V_68 = NULL ;
T_3 V_69 = 0 ;
int V_70 ;
V_4 -> V_71 &= ~ V_72 ;
if ( V_66 && V_67 ) {
V_68 = F_19 ( V_67 , V_73 ) ;
if ( V_68 == NULL )
return - V_74 ;
V_63 = V_66 ;
while ( V_63 + 1 < V_66 + V_67 ) {
if ( V_63 + 2 + V_63 [ 1 ] > V_66 + V_67 )
break;
if ( ! ( F_15 ( V_63 ) || F_16 ( V_63 ) ) ) {
memcpy ( V_68 + V_69 , V_63 , 2 + V_63 [ 1 ] ) ;
V_69 += 2 + V_63 [ 1 ] ;
}
if ( F_17 ( V_63 ) )
V_4 -> V_71 |= V_72 ;
V_63 += 2 + V_63 [ 1 ] ;
}
}
V_70 = F_20 ( V_4 -> V_10 , V_2 -> V_11 ,
V_75 , V_68 , V_69 ) ;
F_21 ( V_68 ) ;
return V_70 ;
}
static int F_22 ( enum V_76 type , T_2 * V_77 )
{
switch ( type ) {
case V_78 :
case V_79 :
* V_77 = V_80 ;
break;
case V_81 :
* V_77 = V_82 ;
break;
case V_83 :
case V_84 :
* V_77 = V_85 ;
break;
default:
F_9 ( L_9 , type ) ;
return - V_24 ;
}
return 0 ;
}
static bool F_23 ( struct V_3 * V_4 , enum V_76 type ,
T_2 * V_86 , T_2 * V_77 )
{
int V_87 ;
if ( F_22 ( type , V_77 ) )
return false ;
if ( V_4 -> V_88 || ( ( type == V_81 ) &&
V_4 -> V_89 ) )
return false ;
if ( type == V_78 ||
type == V_83 || type == V_81 ) {
for ( V_87 = 0 ; V_87 < V_4 -> V_90 ; V_87 ++ ) {
if ( ( V_4 -> V_91 ) & F_24 ( V_87 ) ) {
* V_86 = V_87 ;
return true ;
}
}
}
if ( type == V_79 ||
type == V_84 ) {
for ( V_87 = V_4 -> V_92 ; V_87 < V_4 -> V_90 ; V_87 ++ ) {
if ( ( V_4 -> V_91 ) & F_24 ( V_87 ) ) {
* V_86 = V_87 ;
return true ;
}
}
}
return false ;
}
static bool F_25 ( struct V_3 * V_4 )
{
return V_4 -> V_93 [ F_26 ( V_4 -> V_10 ) ] == 0 ;
}
static void F_27 ( struct V_1 * V_2 ,
bool V_94 )
{
int V_95 ;
if ( F_28 ( ! F_14 ( V_60 , & V_2 -> V_4 -> V_61 ) ) )
return;
if ( V_2 -> V_77 != V_80 )
return;
if ( ! F_14 ( V_96 ,
V_2 -> V_4 -> V_97 ) )
return;
F_8 ( V_16 , L_10 ,
V_94 ? L_11 : L_12 ) ;
V_95 = F_29 ( V_2 -> V_4 -> V_10 ,
V_2 -> V_11 , V_94 ) ;
if ( V_95 )
F_9 ( L_13 ,
V_94 ? L_11 : L_12 , V_95 ) ;
}
static int F_30 ( struct V_13 * V_13 , struct V_98 * V_99 ,
struct V_100 * V_101 )
{
struct V_3 * V_4 = F_31 ( V_99 ) ;
struct V_1 * V_2 = F_32 ( V_99 ) ;
int V_102 ;
T_2 V_103 = ( V_4 -> V_104 ) ? V_105 : V_106 ;
T_4 V_107 ;
F_5 ( V_2 ) ;
V_2 -> V_108 = V_109 ;
if ( ! F_13 ( V_2 ) )
return - V_110 ;
if ( F_14 ( V_111 , & V_4 -> V_61 ) ) {
F_9 ( L_14 ) ;
return - V_112 ;
}
if ( F_14 ( V_113 , & V_4 -> V_61 ) &&
( ( V_101 -> V_114 && V_101 -> V_114 -> V_115 == 0 ) ||
( V_101 -> V_116 && F_33 ( V_101 -> V_116 ) ) ) ) {
F_9 ( L_15 ) ;
return - V_117 ;
}
if ( F_34 ( & V_4 -> V_118 ) ) {
F_9 ( L_16 ) ;
return - V_119 ;
}
if ( F_14 ( V_111 , & V_4 -> V_61 ) ) {
F_9 ( L_17 ) ;
F_35 ( & V_4 -> V_118 ) ;
return - V_112 ;
}
if ( V_4 -> V_93 [ F_26 ( V_4 -> V_10 ) ] ) {
F_36 ( V_4 -> V_120 ,
F_25 ( V_4 ) ,
V_121 ) ;
if ( F_37 ( V_122 ) ) {
F_9 ( L_18 ) ;
F_35 ( & V_4 -> V_118 ) ;
return - V_123 ;
}
}
V_102 = F_18 ( V_2 , V_101 -> V_124 , V_101 -> V_125 ) ;
if ( V_102 ) {
F_35 ( & V_4 -> V_118 ) ;
return V_102 ;
}
if ( V_101 -> V_124 == NULL || V_101 -> V_125 == 0 )
V_4 -> V_71 &= ~ V_72 ;
if ( F_14 ( V_126 , & V_2 -> V_6 ) &&
V_2 -> V_127 == V_101 -> V_127 &&
! memcmp ( V_2 -> V_128 , V_101 -> V_128 , V_2 -> V_127 ) ) {
V_2 -> V_129 = true ;
V_102 = F_38 ( V_4 -> V_10 , V_2 -> V_11 ,
V_2 -> V_130 ,
V_2 -> V_131 ) ;
F_35 ( & V_4 -> V_118 ) ;
if ( V_102 ) {
F_9 ( L_19 ) ;
return - V_110 ;
}
return 0 ;
} else if ( V_2 -> V_127 == V_101 -> V_127 &&
! memcmp ( V_2 -> V_128 , V_101 -> V_128 , V_2 -> V_127 ) ) {
F_39 ( V_2 ) ;
}
memset ( V_2 -> V_128 , 0 , sizeof( V_2 -> V_128 ) ) ;
V_2 -> V_127 = V_101 -> V_127 ;
memcpy ( V_2 -> V_128 , V_101 -> V_128 , V_101 -> V_127 ) ;
if ( V_101 -> V_114 )
V_2 -> V_131 = V_101 -> V_114 -> V_115 ;
memset ( V_2 -> V_130 , 0 , sizeof( V_2 -> V_130 ) ) ;
if ( V_101 -> V_116 && ! F_40 ( V_101 -> V_116 ) )
memcpy ( V_2 -> V_130 , V_101 -> V_116 , sizeof( V_2 -> V_130 ) ) ;
F_7 ( V_2 , V_101 -> V_132 . V_133 ) ;
V_102 = F_10 ( V_2 , V_101 -> V_26 ) ;
if ( V_102 ) {
F_35 ( & V_4 -> V_118 ) ;
return V_102 ;
}
if ( V_101 -> V_132 . V_134 )
F_11 ( V_2 , V_101 -> V_132 . V_135 [ 0 ] , true ) ;
else
F_11 ( V_2 , 0 , true ) ;
F_11 ( V_2 , V_101 -> V_132 . V_136 , false ) ;
if ( V_101 -> V_132 . V_137 )
F_12 ( V_2 , V_101 -> V_132 . V_138 [ 0 ] ) ;
if ( ( V_101 -> V_139 ) &&
( V_2 -> V_18 == V_19 ) &&
( V_2 -> V_38 == V_45 ) ) {
struct V_140 * V_141 = NULL ;
if ( V_101 -> V_142 > V_143 ) {
F_9 ( L_20 ,
V_101 -> V_142 ) ;
F_35 ( & V_4 -> V_118 ) ;
return - V_144 ;
}
V_141 = & V_2 -> V_145 [ V_101 -> V_142 ] ;
V_141 -> V_139 = V_101 -> V_139 ;
memcpy ( V_141 -> V_141 , V_101 -> V_141 , V_141 -> V_139 ) ;
V_141 -> V_35 = V_2 -> V_38 ;
V_2 -> V_146 = V_101 -> V_142 ;
F_41 ( V_4 -> V_10 , V_2 -> V_11 , V_101 -> V_142 ,
V_2 -> V_38 ,
V_147 | V_148 ,
V_141 -> V_139 ,
NULL , 0 ,
V_141 -> V_141 , V_149 , NULL ,
V_150 ) ;
}
if ( ! V_4 -> V_151 ) {
F_42 ( V_152 , & V_2 -> V_6 ) ;
if ( F_43 ( V_4 -> V_10 , V_2 -> V_11 ,
V_153 , 0 ) != 0 ) {
F_9 ( L_21 ) ;
F_35 ( & V_4 -> V_118 ) ;
return - V_110 ;
}
}
V_2 -> V_77 = V_2 -> V_154 ;
F_27 ( V_2 , true ) ;
if ( V_2 -> V_155 . V_156 == V_79 )
V_103 = V_157 ;
F_8 ( V_16 ,
L_22
L_23
L_24 ,
V_17 ,
V_2 -> V_18 , V_2 -> V_28 , V_2 -> V_38 ,
V_2 -> V_41 , V_2 -> V_39 ,
V_2 -> V_42 , V_2 -> V_131 ) ;
V_2 -> V_129 = 0 ;
if ( V_2 -> V_77 == V_80 ) {
V_107 = F_44 ( T_4 , V_2 -> V_158 ,
V_159 ) ;
V_102 = F_45 ( V_4 -> V_10 , V_2 -> V_11 ,
V_107 ,
0 ) ;
if ( V_102 ) {
F_9 ( L_25 ) ;
F_35 ( & V_4 -> V_118 ) ;
return V_102 ;
}
}
V_102 = F_46 ( V_4 -> V_10 , V_2 -> V_11 , V_2 -> V_77 ,
V_2 -> V_28 , V_2 -> V_18 ,
V_2 -> V_38 ,
V_2 -> V_41 ,
V_2 -> V_39 , V_2 -> V_42 ,
V_2 -> V_127 , V_2 -> V_128 ,
V_2 -> V_130 , V_2 -> V_131 ,
V_4 -> V_71 , V_103 ) ;
if ( V_101 -> V_160 == 0 ) {
V_101 -> V_160 = 0xffff ;
} else if ( V_101 -> V_160 == - 1 ) {
V_101 -> V_160 = V_161 ;
}
F_47 ( V_4 -> V_10 , V_2 -> V_11 , 0 , 0 ,
V_101 -> V_160 , 0 , 0 , 0 , 3 , 0 , 0 , 0 ) ;
F_35 ( & V_4 -> V_118 ) ;
if ( V_102 == - V_117 ) {
memset ( V_2 -> V_128 , 0 , sizeof( V_2 -> V_128 ) ) ;
V_2 -> V_127 = 0 ;
F_9 ( L_26 ) ;
return - V_144 ;
} else if ( V_102 ) {
F_9 ( L_27 ) ;
return - V_110 ;
}
if ( ( ! ( V_4 -> V_71 & V_162 ) ) &&
( ( V_2 -> V_18 == V_55 ) ||
( V_2 -> V_18 == V_56 ) ) ) {
F_48 ( & V_2 -> V_163 ,
V_164 + F_49 ( V_165 ) ) ;
}
V_4 -> V_71 &= ~ V_162 ;
F_50 ( V_166 , & V_2 -> V_6 ) ;
return 0 ;
}
static struct V_167 *
F_51 ( struct V_1 * V_2 ,
enum V_168 V_77 ,
const T_2 * V_116 ,
struct V_169 * V_170 ,
const T_2 * V_171 ,
T_3 V_172 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_167 * V_173 ;
T_4 V_174 ;
enum V_175 V_176 ;
T_2 * V_124 ;
if ( V_77 & V_82 ) {
V_174 = V_177 ;
V_176 = V_178 ;
} else {
V_174 = V_179 ;
V_176 = V_180 ;
}
V_173 = F_52 ( V_4 -> V_13 , V_170 , V_116 ,
V_2 -> V_128 , V_2 -> V_127 ,
V_176 , V_181 ) ;
if ( V_173 == NULL ) {
V_124 = F_19 ( 2 + V_2 -> V_127 + V_172 , V_73 ) ;
if ( V_124 == NULL )
return NULL ;
V_124 [ 0 ] = V_182 ;
V_124 [ 1 ] = V_2 -> V_127 ;
memcpy ( V_124 + 2 , V_2 -> V_128 , V_2 -> V_127 ) ;
memcpy ( V_124 + 2 + V_2 -> V_127 , V_171 , V_172 ) ;
V_173 = F_53 ( V_4 -> V_13 , V_170 ,
V_183 ,
V_116 , 0 , V_174 , 100 ,
V_124 , 2 + V_2 -> V_127 + V_172 ,
0 , V_73 ) ;
if ( V_173 )
F_8 ( V_16 ,
L_28 , V_116 ) ;
F_21 ( V_124 ) ;
} else {
F_8 ( V_16 , L_29 ) ;
}
return V_173 ;
}
void F_54 ( struct V_1 * V_2 , T_4 V_114 ,
T_2 * V_116 , T_4 V_184 ,
T_4 V_185 ,
enum V_168 V_77 ,
T_2 V_172 , T_2 V_186 ,
T_2 V_187 , T_2 * V_188 )
{
struct V_169 * V_170 ;
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_167 * V_173 ;
T_2 V_189 = sizeof( T_4 ) + sizeof( T_4 ) ;
T_2 V_190 = sizeof( T_4 ) + sizeof( T_4 ) + sizeof( T_4 ) ;
T_2 * V_191 = V_188 + V_172 + V_189 ;
T_2 * V_192 = V_188 + V_172 + V_186 +
V_190 ;
V_186 -= V_189 ;
V_187 -= V_190 ;
V_2 -> V_193 = V_185 ;
F_42 ( V_194 , & V_2 -> V_6 ) ;
if ( V_77 & V_82 ) {
if ( V_2 -> V_155 . V_156 != V_81 ) {
F_8 ( V_16 ,
L_30 , V_17 ) ;
return;
}
}
if ( V_77 & V_80 ) {
if ( V_2 -> V_155 . V_156 != V_78 &&
V_2 -> V_155 . V_156 != V_79 ) {
F_8 ( V_16 ,
L_31 , V_17 ) ;
return;
}
}
V_170 = F_55 ( V_4 -> V_13 , ( int ) V_114 ) ;
V_173 = F_51 ( V_2 , V_77 , V_116 , V_170 ,
V_188 , V_172 ) ;
if ( ! V_173 ) {
F_9 ( L_32 ) ;
return;
}
if ( V_77 & V_82 ) {
F_8 ( V_16 , L_33 ,
V_77 & V_195 ? L_34 : L_35 ) ;
F_56 ( V_2 -> V_196 , V_116 , V_170 , V_73 ) ;
F_57 ( V_4 -> V_13 , V_173 ) ;
return;
}
if ( V_2 -> V_108 == V_109 ) {
V_2 -> V_108 = V_197 ;
F_58 ( V_2 -> V_196 , V_116 ,
V_191 , V_186 ,
V_192 , V_187 ,
V_198 , V_73 ) ;
F_57 ( V_4 -> V_13 , V_173 ) ;
} else if ( V_2 -> V_108 == V_197 ) {
struct V_199 V_200 = {
. V_173 = V_173 ,
. V_201 = V_191 ,
. V_202 = V_186 ,
. V_203 = V_192 ,
. V_204 = V_187 ,
} ;
F_59 ( V_2 -> V_196 , & V_200 , V_73 ) ;
}
}
static int F_60 ( struct V_13 * V_13 ,
struct V_98 * V_99 , T_4 V_205 )
{
struct V_3 * V_4 = F_31 ( V_99 ) ;
struct V_1 * V_2 = F_32 ( V_99 ) ;
F_8 ( V_16 , L_36 , V_17 ,
V_205 ) ;
F_5 ( V_2 ) ;
if ( ! F_13 ( V_2 ) )
return - V_110 ;
if ( F_14 ( V_111 , & V_4 -> V_61 ) ) {
F_9 ( L_17 ) ;
return - V_112 ;
}
if ( F_34 ( & V_4 -> V_118 ) ) {
F_9 ( L_16 ) ;
return - V_119 ;
}
V_2 -> V_129 = 0 ;
F_39 ( V_2 ) ;
memset ( V_2 -> V_128 , 0 , sizeof( V_2 -> V_128 ) ) ;
V_2 -> V_127 = 0 ;
if ( ! F_14 ( V_113 , & V_4 -> V_61 ) )
memset ( V_2 -> V_130 , 0 , sizeof( V_2 -> V_130 ) ) ;
F_35 ( & V_4 -> V_118 ) ;
return 0 ;
}
void F_61 ( struct V_1 * V_2 , T_2 V_206 ,
T_2 * V_116 , T_2 V_187 ,
T_2 * V_188 , T_4 V_207 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
if ( V_2 -> V_208 ) {
struct V_209 V_210 = {
. V_211 = true ,
} ;
F_62 ( V_2 -> V_208 , & V_210 ) ;
V_2 -> V_208 = NULL ;
}
if ( V_2 -> V_77 & V_82 ) {
if ( V_2 -> V_155 . V_156 != V_81 )
F_8 ( V_16 ,
L_30 , V_17 ) ;
return;
}
if ( V_2 -> V_77 & V_80 ) {
if ( V_2 -> V_155 . V_156 != V_78 &&
V_2 -> V_155 . V_156 != V_79 ) {
F_8 ( V_16 ,
L_31 , V_17 ) ;
return;
}
}
F_42 ( V_166 , & V_2 -> V_6 ) ;
if ( V_2 -> V_108 == V_109 ) {
F_58 ( V_2 -> V_196 ,
V_116 , NULL , 0 ,
NULL , 0 ,
V_212 ,
V_73 ) ;
} else if ( V_2 -> V_108 == V_197 ) {
F_63 ( V_2 -> V_196 , V_207 ,
NULL , 0 , false , V_73 ) ;
}
V_2 -> V_108 = V_213 ;
if ( V_206 != V_214 )
F_64 ( V_4 -> V_10 , V_2 -> V_11 ) ;
}
static int F_65 ( struct V_3 * V_4 ,
struct V_1 * V_2 ,
struct V_215 * V_216 , int V_217 ,
struct V_218 * V_219 ,
int V_220 )
{
T_2 V_87 , V_221 , V_222 , V_223 = false ;
struct V_224 V_225 [ V_226 ] ;
memset ( V_225 , 0 , sizeof( V_225 ) ) ;
if ( V_217 > V_226 ||
V_220 > V_226 )
return - V_117 ;
for ( V_87 = 0 ; V_87 < V_217 ; V_87 ++ ) {
memcpy ( V_225 [ V_87 ] . V_128 . V_128 ,
V_216 [ V_87 ] . V_128 ,
V_216 [ V_87 ] . V_127 ) ;
V_225 [ V_87 ] . V_128 . V_127 = V_216 [ V_87 ] . V_127 ;
if ( V_216 [ V_87 ] . V_127 )
V_225 [ V_87 ] . V_61 = V_227 ;
else
V_225 [ V_87 ] . V_61 = V_228 ;
if ( V_220 == 0 )
V_225 [ V_87 ] . V_61 |= V_229 ;
}
V_222 = V_87 ;
for ( V_87 = 0 ; V_87 < V_220 ; V_87 ++ ) {
V_223 = false ;
for ( V_221 = 0 ; V_221 < V_217 ; V_221 ++ ) {
if ( ( V_219 [ V_87 ] . V_128 . V_127 ==
V_225 [ V_221 ] . V_128 . V_127 ) &&
( ! memcmp ( V_225 [ V_221 ] . V_128 . V_128 ,
V_219 [ V_87 ] . V_128 . V_128 ,
V_219 [ V_87 ] . V_128 . V_127 ) ) ) {
V_225 [ V_221 ] . V_61 |= V_229 ;
V_223 = true ;
break;
}
}
if ( V_223 )
continue;
if ( V_222 >= V_226 )
continue;
V_225 [ V_222 ] . V_128 . V_127 =
V_219 [ V_87 ] . V_128 . V_127 ;
memcpy ( V_225 [ V_222 ] . V_128 . V_128 ,
V_219 [ V_87 ] . V_128 . V_128 ,
V_219 [ V_87 ] . V_128 . V_127 ) ;
V_225 [ V_222 ] . V_61 |= V_229 ;
V_222 ++ ;
}
for ( V_87 = 0 ; V_87 < V_222 ; V_87 ++ ) {
F_66 ( V_4 -> V_10 , V_2 -> V_11 , V_87 ,
V_225 [ V_87 ] . V_61 ,
V_225 [ V_87 ] . V_128 . V_127 ,
V_225 [ V_87 ] . V_128 . V_128 ) ;
}
for ( V_87 = V_222 ; V_87 < V_226 ; V_87 ++ ) {
F_66 ( V_4 -> V_10 , V_2 -> V_11 , V_87 ,
V_230 , 0 , NULL ) ;
}
return 0 ;
}
static int F_67 ( struct V_13 * V_13 ,
struct V_231 * V_232 )
{
struct V_1 * V_2 = F_68 ( V_232 -> V_155 ) ;
struct V_3 * V_4 = F_31 ( V_2 -> V_196 ) ;
T_5 V_233 = 0 ;
T_4 * V_234 = NULL ;
int V_70 = 0 ;
T_1 V_235 = 0 ;
if ( ! F_13 ( V_2 ) )
return - V_110 ;
F_5 ( V_2 ) ;
if ( ! V_4 -> V_151 ) {
F_42 ( V_152 , & V_2 -> V_6 ) ;
V_70 = F_43 ( V_4 -> V_10 , V_2 -> V_11 ,
V_153 , 0 ) ;
if ( V_70 ) {
F_9 ( L_21 ) ;
return V_70 ;
}
}
V_70 = F_65 ( V_4 , V_2 , V_232 -> V_216 ,
V_232 -> V_217 , NULL , 0 ) ;
if ( V_70 < 0 )
return V_70 ;
V_70 = F_20 ( V_4 -> V_10 , V_2 -> V_11 ,
V_236 ,
V_232 -> V_124 , V_232 -> V_125 ) ;
if ( V_70 ) {
F_9 ( L_37 ) ;
return V_70 ;
}
if ( V_232 -> V_233 > 0 &&
V_232 -> V_233 <= V_237 ) {
T_2 V_87 ;
V_233 = V_232 -> V_233 ;
V_234 = F_69 ( V_233 * sizeof( T_4 ) , V_73 ) ;
if ( V_234 == NULL ) {
F_70 ( L_38 ) ;
V_233 = 0 ;
}
for ( V_87 = 0 ; V_87 < V_233 ; V_87 ++ )
V_234 [ V_87 ] = V_232 -> V_234 [ V_87 ] -> V_115 ;
}
if ( F_14 ( V_126 , & V_2 -> V_6 ) )
V_235 = 1 ;
V_2 -> V_208 = V_232 ;
V_70 = F_71 ( V_4 -> V_10 , V_2 -> V_11 ,
V_238 , V_235 ,
false , 0 ,
V_239 ,
V_233 , V_234 ,
V_232 -> V_240 ,
V_232 -> V_241 ) ;
if ( V_70 ) {
F_9 ( L_39 , V_70 ) ;
V_2 -> V_208 = NULL ;
}
F_21 ( V_234 ) ;
return V_70 ;
}
void F_72 ( struct V_1 * V_2 , bool V_211 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_209 V_210 = {
. V_211 = V_211 ,
} ;
int V_87 ;
F_8 ( V_16 , L_40 , V_17 ,
V_211 ? L_41 : L_42 ) ;
if ( ! V_2 -> V_208 )
return;
if ( V_211 )
goto V_242;
if ( V_2 -> V_208 -> V_217 && V_2 -> V_208 -> V_216 [ 0 ] . V_127 ) {
for ( V_87 = 0 ; V_87 < V_2 -> V_208 -> V_217 ; V_87 ++ ) {
F_66 ( V_4 -> V_10 , V_2 -> V_11 ,
V_87 + 1 , V_230 ,
0 , NULL ) ;
}
}
V_242:
F_62 ( V_2 -> V_208 , & V_210 ) ;
V_2 -> V_208 = NULL ;
}
void F_73 ( struct V_1 * V_2 , int V_243 ,
enum V_244 V_245 )
{
struct V_246 V_247 ;
F_8 ( V_16 ,
L_43 ,
V_2 -> V_77 , V_243 , V_245 ) ;
F_74 ( & V_247 ,
F_55 ( V_2 -> V_4 -> V_13 , V_243 ) ,
( V_245 == V_248 &&
V_249 . V_250 . V_251 ) ?
V_252 : V_253 ) ;
F_75 ( & V_2 -> V_155 . V_254 ) ;
F_76 ( V_2 -> V_196 , & V_247 ) ;
F_77 ( & V_2 -> V_155 . V_254 ) ;
}
static int F_78 ( struct V_13 * V_13 , struct V_98 * V_196 ,
T_2 V_255 , bool V_256 ,
const T_2 * V_257 ,
struct V_258 * V_259 )
{
struct V_3 * V_4 = F_31 ( V_196 ) ;
struct V_1 * V_2 = F_32 ( V_196 ) ;
struct V_140 * V_141 = NULL ;
int V_260 ;
T_2 V_261 ;
T_2 V_262 ;
if ( ! F_13 ( V_2 ) )
return - V_110 ;
if ( V_259 -> V_35 == V_263 ) {
if ( V_259 -> V_139 != V_264 )
return - V_117 ;
return F_79 ( V_4 -> V_10 , V_2 -> V_11 ,
V_259 -> V_141 ) ;
}
if ( V_255 > V_143 ) {
F_8 ( V_16 ,
L_44 , V_17 ,
V_255 ) ;
return - V_144 ;
}
V_141 = & V_2 -> V_145 [ V_255 ] ;
memset ( V_141 , 0 , sizeof( struct V_140 ) ) ;
if ( V_256 )
V_261 = V_265 ;
else
V_261 = V_147 ;
V_260 = V_259 -> V_260 ;
if ( V_259 -> V_35 == V_51 &&
V_260 > V_266 ) {
V_260 = V_266 ;
}
if ( V_259 -> V_139 > V_267 ||
V_260 > sizeof( V_141 -> V_268 ) )
return - V_117 ;
V_141 -> V_139 = V_259 -> V_139 ;
memcpy ( V_141 -> V_141 , V_259 -> V_141 , V_141 -> V_139 ) ;
V_141 -> V_260 = V_260 ;
memcpy ( V_141 -> V_268 , V_259 -> V_268 , V_141 -> V_260 ) ;
V_141 -> V_35 = V_259 -> V_35 ;
switch ( V_141 -> V_35 ) {
case V_44 :
case V_46 :
V_262 = V_45 ;
break;
case V_47 :
V_262 = V_48 ;
break;
case V_49 :
V_262 = V_50 ;
break;
case V_51 :
V_262 = V_52 ;
break;
default:
return - V_24 ;
}
if ( ( ( V_2 -> V_18 == V_55 ) ||
( V_2 -> V_18 == V_56 ) ) &&
( V_261 & V_147 ) )
F_80 ( & V_2 -> V_163 ) ;
F_8 ( V_16 ,
L_45 ,
V_17 , V_255 , V_141 -> V_139 , V_262 ,
V_261 , V_141 -> V_260 ) ;
if ( V_2 -> V_77 == V_85 && ! V_256 &&
( V_262 == V_48 || V_262 == V_50 ||
V_262 == V_52 ) ) {
V_4 -> V_269 . V_270 = true ;
V_4 -> V_269 . V_255 = V_255 ;
V_4 -> V_269 . V_262 = V_262 ;
V_4 -> V_269 . V_139 = V_141 -> V_139 ;
memcpy ( V_4 -> V_269 . V_141 , V_141 -> V_141 , V_141 -> V_139 ) ;
if ( ! F_14 ( V_126 , & V_2 -> V_6 ) ) {
F_8 ( V_16 ,
L_46 ) ;
return 0 ;
}
}
if ( V_2 -> V_154 == V_85 && V_262 == V_45 &&
! F_14 ( V_126 , & V_2 -> V_6 ) ) {
F_8 ( V_16 ,
L_47 ) ;
V_2 -> V_271 [ V_255 ] . V_139 = V_141 -> V_139 ;
memcpy ( V_2 -> V_271 [ V_255 ] . V_141 , V_141 -> V_141 ,
V_141 -> V_139 ) ;
return 0 ;
}
return F_41 ( V_4 -> V_10 , V_2 -> V_11 , V_255 ,
V_262 , V_261 , V_141 -> V_139 ,
V_141 -> V_268 , V_141 -> V_260 , V_141 -> V_141 ,
V_149 ,
( T_2 * ) V_257 , V_272 ) ;
}
static int F_81 ( struct V_13 * V_13 , struct V_98 * V_196 ,
T_2 V_255 , bool V_256 ,
const T_2 * V_257 )
{
struct V_3 * V_4 = F_31 ( V_196 ) ;
struct V_1 * V_2 = F_32 ( V_196 ) ;
F_8 ( V_16 , L_48 , V_17 , V_255 ) ;
if ( ! F_13 ( V_2 ) )
return - V_110 ;
if ( V_255 > V_143 ) {
F_8 ( V_16 ,
L_44 , V_17 ,
V_255 ) ;
return - V_144 ;
}
if ( ! V_2 -> V_145 [ V_255 ] . V_139 ) {
F_8 ( V_16 ,
L_49 , V_17 , V_255 ) ;
return 0 ;
}
V_2 -> V_145 [ V_255 ] . V_139 = 0 ;
return F_82 ( V_4 -> V_10 , V_2 -> V_11 , V_255 ) ;
}
static int F_83 ( struct V_13 * V_13 , struct V_98 * V_196 ,
T_2 V_255 , bool V_256 ,
const T_2 * V_257 , void * V_273 ,
void (* F_84) ( void * V_273 ,
struct V_258 * ) )
{
struct V_1 * V_2 = F_32 ( V_196 ) ;
struct V_140 * V_141 = NULL ;
struct V_258 V_259 ;
F_8 ( V_16 , L_48 , V_17 , V_255 ) ;
if ( ! F_13 ( V_2 ) )
return - V_110 ;
if ( V_255 > V_143 ) {
F_8 ( V_16 ,
L_44 , V_17 ,
V_255 ) ;
return - V_144 ;
}
V_141 = & V_2 -> V_145 [ V_255 ] ;
memset ( & V_259 , 0 , sizeof( V_259 ) ) ;
V_259 . V_35 = V_141 -> V_35 ;
V_259 . V_139 = V_141 -> V_139 ;
V_259 . V_260 = V_141 -> V_260 ;
V_259 . V_268 = V_141 -> V_268 ;
V_259 . V_141 = V_141 -> V_141 ;
F_84 ( V_273 , & V_259 ) ;
return V_141 -> V_139 ? 0 : - V_144 ;
}
static int F_85 ( struct V_13 * V_13 ,
struct V_98 * V_196 ,
T_2 V_255 , bool V_274 ,
bool V_275 )
{
struct V_3 * V_4 = F_31 ( V_196 ) ;
struct V_1 * V_2 = F_32 ( V_196 ) ;
struct V_140 * V_141 = NULL ;
T_2 V_261 ;
enum V_276 V_262 = V_43 ;
F_8 ( V_16 , L_48 , V_17 , V_255 ) ;
if ( ! F_13 ( V_2 ) )
return - V_110 ;
if ( V_255 > V_143 ) {
F_8 ( V_16 ,
L_44 ,
V_17 , V_255 ) ;
return - V_144 ;
}
if ( ! V_2 -> V_145 [ V_255 ] . V_139 ) {
F_8 ( V_16 , L_50 ,
V_17 , V_255 ) ;
return - V_117 ;
}
V_2 -> V_146 = V_255 ;
V_141 = & V_2 -> V_145 [ V_2 -> V_146 ] ;
V_261 = V_147 ;
if ( V_2 -> V_38 == V_45 )
V_261 |= V_148 ;
if ( V_274 )
V_262 = V_2 -> V_38 ;
if ( V_275 )
V_262 = V_2 -> V_39 ;
if ( V_2 -> V_154 == V_85 && ! F_14 ( V_126 , & V_2 -> V_6 ) )
return 0 ;
return F_41 ( V_4 -> V_10 , V_2 -> V_11 ,
V_2 -> V_146 ,
V_262 , V_261 ,
V_141 -> V_139 , V_141 -> V_268 , V_141 -> V_260 ,
V_141 -> V_141 ,
V_149 , NULL ,
V_272 ) ;
}
void F_86 ( struct V_1 * V_2 , T_2 V_277 ,
bool V_278 )
{
F_8 ( V_16 ,
L_51 , V_17 , V_277 , V_278 ) ;
F_87 ( V_2 -> V_196 , V_2 -> V_116 ,
( V_278 ? V_279 :
V_280 ) , V_277 , NULL ,
V_73 ) ;
}
static int F_88 ( struct V_13 * V_13 , T_1 V_281 )
{
struct V_3 * V_4 = (struct V_3 * ) F_89 ( V_13 ) ;
struct V_1 * V_2 ;
int V_70 ;
F_8 ( V_16 , L_52 , V_17 ,
V_281 ) ;
V_2 = F_90 ( V_4 ) ;
if ( ! V_2 )
return - V_110 ;
if ( ! F_13 ( V_2 ) )
return - V_110 ;
if ( V_281 & V_282 ) {
V_70 = F_91 ( V_4 -> V_10 , V_13 -> V_283 ) ;
if ( V_70 != 0 ) {
F_9 ( L_53 ) ;
return - V_110 ;
}
}
return 0 ;
}
static int F_92 ( struct V_13 * V_13 ,
struct V_284 * V_155 ,
enum V_285 type ,
int V_286 )
{
struct V_3 * V_4 = (struct V_3 * ) F_89 ( V_13 ) ;
struct V_1 * V_2 ;
int V_287 = F_93 ( V_286 ) ;
F_8 ( V_16 , L_54 , V_17 ,
type , V_287 ) ;
V_2 = F_90 ( V_4 ) ;
if ( ! V_2 )
return - V_110 ;
if ( ! F_13 ( V_2 ) )
return - V_110 ;
switch ( type ) {
case V_288 :
return 0 ;
case V_289 :
V_4 -> V_290 = V_287 ;
break;
default:
F_8 ( V_16 , L_55 ,
V_17 , type ) ;
return - V_291 ;
}
F_94 ( V_4 -> V_10 , V_2 -> V_11 , V_287 ) ;
return 0 ;
}
static int F_95 ( struct V_13 * V_13 ,
struct V_284 * V_155 ,
int * V_287 )
{
struct V_3 * V_4 = (struct V_3 * ) F_89 ( V_13 ) ;
struct V_1 * V_2 ;
V_2 = F_90 ( V_4 ) ;
if ( ! V_2 )
return - V_110 ;
if ( ! F_13 ( V_2 ) )
return - V_110 ;
if ( F_14 ( V_126 , & V_2 -> V_6 ) ) {
V_4 -> V_290 = 255 ;
if ( F_96 ( V_4 -> V_10 , V_2 -> V_11 ) != 0 ) {
F_9 ( L_56 ) ;
return - V_110 ;
}
F_36 ( V_4 -> V_120 , V_4 -> V_290 != 255 ,
5 * V_292 ) ;
if ( F_37 ( V_122 ) ) {
F_9 ( L_57 ) ;
return - V_123 ;
}
}
* V_287 = V_4 -> V_290 ;
return 0 ;
}
static int F_97 ( struct V_13 * V_13 ,
struct V_98 * V_99 ,
bool V_293 , int V_294 )
{
struct V_3 * V_4 = F_31 ( V_99 ) ;
struct V_295 V_245 ;
struct V_1 * V_2 = F_32 ( V_99 ) ;
F_8 ( V_16 , L_58 ,
V_17 , V_293 , V_294 ) ;
if ( ! F_13 ( V_2 ) )
return - V_110 ;
if ( V_293 ) {
F_8 ( V_16 , L_59 , V_17 ) ;
V_245 . V_296 = V_297 ;
} else {
F_8 ( V_16 , L_60 , V_17 ) ;
V_245 . V_296 = V_298 ;
}
if ( F_98 ( V_4 -> V_10 , V_2 -> V_11 ,
V_245 . V_296 ) != 0 ) {
F_9 ( L_61 ) ;
return - V_110 ;
}
return 0 ;
}
static struct V_284 * F_99 ( struct V_13 * V_13 ,
const char * V_299 ,
unsigned char V_300 ,
enum V_76 type ,
struct V_301 * V_259 )
{
struct V_3 * V_4 = F_89 ( V_13 ) ;
struct V_284 * V_155 ;
T_2 V_86 , V_77 ;
if ( V_4 -> V_89 == V_4 -> V_90 ) {
F_9 ( L_62 ) ;
return F_100 ( - V_117 ) ;
}
if ( ! F_23 ( V_4 , type , & V_86 , & V_77 ) ) {
F_9 ( L_63 ) ;
return F_100 ( - V_117 ) ;
}
V_155 = F_101 ( V_4 , V_299 , V_300 , type , V_86 , V_77 ) ;
if ( ! V_155 )
return F_100 ( - V_74 ) ;
V_4 -> V_89 ++ ;
return V_155 ;
}
static int F_102 ( struct V_13 * V_13 ,
struct V_284 * V_155 )
{
struct V_3 * V_4 = F_89 ( V_13 ) ;
struct V_1 * V_2 = F_32 ( V_155 -> V_302 ) ;
F_103 ( & V_4 -> V_303 ) ;
F_104 ( & V_2 -> V_304 ) ;
F_105 ( & V_4 -> V_303 ) ;
F_106 ( V_2 , F_14 ( V_60 , & V_4 -> V_61 ) ) ;
F_107 () ;
F_108 ( V_2 ) ;
F_109 () ;
return 0 ;
}
static int F_110 ( struct V_13 * V_13 ,
struct V_98 * V_196 ,
enum V_76 type ,
struct V_301 * V_259 )
{
struct V_1 * V_2 = F_32 ( V_196 ) ;
int V_87 ;
F_8 ( V_16 , L_64 , V_17 , type ) ;
if ( ! F_14 ( V_305 ,
V_2 -> V_4 -> V_97 ) &&
( type == V_79 ||
type == V_84 ) ) {
if ( V_2 -> V_4 -> V_90 == 1 ) {
if ( V_2 -> V_11 != 0 )
return - V_117 ;
else
goto V_306;
}
for ( V_87 = V_2 -> V_4 -> V_92 ; V_87 < V_2 -> V_4 -> V_90 ; V_87 ++ ) {
if ( V_87 == V_2 -> V_11 )
break;
}
if ( V_87 == V_2 -> V_4 -> V_90 ) {
F_9 ( L_65 ) ;
return - V_117 ;
}
}
F_27 ( V_2 , false ) ;
V_306:
switch ( type ) {
case V_78 :
case V_79 :
V_2 -> V_154 = V_80 ;
break;
case V_81 :
V_2 -> V_154 = V_82 ;
break;
case V_83 :
case V_84 :
V_2 -> V_154 = V_85 ;
break;
default:
F_9 ( L_9 , type ) ;
return - V_291 ;
}
V_2 -> V_155 . V_156 = type ;
return 0 ;
}
static int F_111 ( struct V_13 * V_13 ,
struct V_98 * V_99 ,
struct V_307 * V_308 )
{
struct V_3 * V_4 = F_31 ( V_99 ) ;
struct V_1 * V_2 = F_32 ( V_99 ) ;
int V_102 ;
if ( ! F_13 ( V_2 ) )
return - V_110 ;
V_2 -> V_127 = V_308 -> V_127 ;
memcpy ( V_2 -> V_128 , V_308 -> V_128 , V_2 -> V_127 ) ;
if ( V_308 -> V_247 . V_170 )
V_2 -> V_131 = V_308 -> V_247 . V_170 -> V_115 ;
if ( V_308 -> V_309 ) {
return - V_291 ;
}
memset ( V_2 -> V_130 , 0 , sizeof( V_2 -> V_130 ) ) ;
if ( V_308 -> V_116 && ! F_40 ( V_308 -> V_116 ) )
memcpy ( V_2 -> V_130 , V_308 -> V_116 ,
sizeof( V_2 -> V_130 ) ) ;
F_7 ( V_2 , 0 ) ;
V_102 = F_10 ( V_2 , V_27 ) ;
if ( V_102 )
return V_102 ;
if ( V_308 -> V_310 ) {
F_11 ( V_2 , V_44 , true ) ;
F_11 ( V_2 , V_44 , false ) ;
} else {
F_11 ( V_2 , 0 , true ) ;
F_11 ( V_2 , 0 , false ) ;
}
V_2 -> V_77 = V_2 -> V_154 ;
F_8 ( V_16 ,
L_22
L_23
L_24 ,
V_17 ,
V_2 -> V_18 , V_2 -> V_28 , V_2 -> V_38 ,
V_2 -> V_41 , V_2 -> V_39 ,
V_2 -> V_42 , V_2 -> V_131 ) ;
V_102 = F_46 ( V_4 -> V_10 , V_2 -> V_11 , V_2 -> V_77 ,
V_2 -> V_28 , V_2 -> V_18 ,
V_2 -> V_38 ,
V_2 -> V_41 ,
V_2 -> V_39 , V_2 -> V_42 ,
V_2 -> V_127 , V_2 -> V_128 ,
V_2 -> V_130 , V_2 -> V_131 ,
V_4 -> V_71 , V_106 ) ;
F_50 ( V_166 , & V_2 -> V_6 ) ;
return 0 ;
}
static int F_112 ( struct V_13 * V_13 ,
struct V_98 * V_99 )
{
struct V_1 * V_2 = F_32 ( V_99 ) ;
if ( ! F_13 ( V_2 ) )
return - V_110 ;
F_39 ( V_2 ) ;
memset ( V_2 -> V_128 , 0 , sizeof( V_2 -> V_128 ) ) ;
V_2 -> V_127 = 0 ;
return 0 ;
}
static bool F_113 ( T_6 V_311 )
{
static const T_6 V_312 [] = { 1000 , 2000 , 5500 , 11000 ,
6000 , 9000 , 12000 , 18000 , 24000 ,
36000 , 48000 , 54000
} ;
T_2 V_87 ;
for ( V_87 = 0 ; V_87 < F_114 ( V_312 ) ; V_87 ++ )
if ( V_311 == V_312 [ V_87 ] )
return true ;
return false ;
}
static bool F_115 ( T_6 V_311 , T_2 * V_313 , bool * V_314 )
{
static const T_6 V_315 [] = { 6500 , 13000 , 19500 , 26000 , 39000 ,
52000 , 58500 , 65000 , 72200
} ;
T_2 V_87 ;
for ( V_87 = 0 ; V_87 < F_114 ( V_315 ) ; V_87 ++ ) {
if ( V_311 == V_315 [ V_87 ] ) {
if ( V_87 == F_114 ( V_315 ) - 1 )
* V_314 = true ;
else
* V_314 = false ;
* V_313 = V_87 ;
return true ;
}
}
return false ;
}
static bool F_116 ( T_6 V_311 , T_2 * V_313 , bool * V_314 )
{
static const T_6 V_316 [] = { 13500 , 27000 , 40500 , 54000 ,
81000 , 108000 , 121500 , 135000 ,
150000
} ;
T_2 V_87 ;
for ( V_87 = 0 ; V_87 < F_114 ( V_316 ) ; V_87 ++ ) {
if ( V_311 == V_316 [ V_87 ] ) {
if ( V_87 == F_114 ( V_316 ) - 1 )
* V_314 = true ;
else
* V_314 = false ;
* V_313 = V_87 ;
return true ;
}
}
return false ;
}
static int F_117 ( struct V_13 * V_13 , struct V_98 * V_99 ,
const T_2 * V_317 , struct V_318 * V_319 )
{
struct V_3 * V_4 = F_31 ( V_99 ) ;
struct V_1 * V_2 = F_32 ( V_99 ) ;
long V_320 ;
bool V_314 ;
T_6 V_311 ;
int V_70 ;
T_2 V_313 ;
if ( memcmp ( V_317 , V_2 -> V_116 , V_321 ) != 0 )
return - V_144 ;
if ( F_34 ( & V_4 -> V_118 ) )
return - V_112 ;
F_50 ( V_322 , & V_2 -> V_6 ) ;
V_70 = F_118 ( V_4 -> V_10 , V_2 -> V_11 ) ;
if ( V_70 != 0 ) {
F_35 ( & V_4 -> V_118 ) ;
return - V_110 ;
}
V_320 = F_36 ( V_4 -> V_120 ,
! F_14 ( V_322 ,
& V_2 -> V_6 ) ,
V_121 ) ;
F_35 ( & V_4 -> V_118 ) ;
if ( V_320 == 0 )
return - V_323 ;
else if ( V_320 < 0 )
return V_320 ;
if ( V_2 -> V_324 . V_325 ) {
V_319 -> V_326 = V_2 -> V_324 . V_325 ;
V_319 -> V_327 |= F_24 ( V_328 ) ;
V_319 -> V_329 = V_2 -> V_324 . V_330 ;
V_319 -> V_327 |= F_24 ( V_331 ) ;
}
if ( V_2 -> V_324 . V_332 ) {
V_319 -> V_333 = V_2 -> V_324 . V_332 ;
V_319 -> V_327 |= F_24 ( V_334 ) ;
V_319 -> V_335 = V_2 -> V_324 . V_336 ;
V_319 -> V_327 |= F_24 ( V_337 ) ;
}
V_319 -> signal = V_2 -> V_324 . V_338 ;
V_319 -> V_327 |= F_24 ( V_339 ) ;
V_311 = V_2 -> V_324 . V_340 ;
if ( F_113 ( V_311 ) ) {
V_319 -> V_341 . V_312 = V_311 / 100 ;
} else if ( F_115 ( V_311 , & V_313 , & V_314 ) ) {
if ( V_314 ) {
V_319 -> V_341 . V_6 |= V_342 ;
V_319 -> V_341 . V_313 = V_313 - 1 ;
} else {
V_319 -> V_341 . V_313 = V_313 ;
}
V_319 -> V_341 . V_6 |= V_343 ;
V_319 -> V_341 . V_344 = V_345 ;
} else if ( F_116 ( V_311 , & V_313 , & V_314 ) ) {
if ( V_314 ) {
V_319 -> V_341 . V_6 |= V_342 ;
V_319 -> V_341 . V_313 = V_313 - 1 ;
} else {
V_319 -> V_341 . V_313 = V_313 ;
}
V_319 -> V_341 . V_344 = V_346 ;
V_319 -> V_341 . V_6 |= V_343 ;
} else {
F_8 ( V_16 ,
L_66 , V_311 ) ;
F_119 ( V_4 , V_347 ) ;
return 0 ;
}
V_319 -> V_327 |= F_24 ( V_348 ) ;
if ( F_14 ( V_126 , & V_2 -> V_6 ) &&
F_14 ( V_194 , & V_2 -> V_6 ) &&
V_2 -> V_77 == V_80 ) {
V_319 -> V_327 |= F_24 ( V_349 ) ;
V_319 -> V_350 . V_6 = 0 ;
V_319 -> V_350 . V_351 = V_2 -> V_352 ;
V_319 -> V_350 . V_353 = V_2 -> V_193 ;
}
return 0 ;
}
static int F_120 ( struct V_13 * V_13 , struct V_98 * V_302 ,
struct V_354 * V_355 )
{
struct V_3 * V_4 = F_31 ( V_302 ) ;
struct V_1 * V_2 = F_32 ( V_302 ) ;
return F_121 ( V_4 -> V_10 , V_2 -> V_11 , V_355 -> V_116 ,
V_355 -> V_356 , true ) ;
}
static int F_122 ( struct V_13 * V_13 , struct V_98 * V_302 ,
struct V_354 * V_355 )
{
struct V_3 * V_4 = F_31 ( V_302 ) ;
struct V_1 * V_2 = F_32 ( V_302 ) ;
return F_121 ( V_4 -> V_10 , V_2 -> V_11 , V_355 -> V_116 ,
V_355 -> V_356 , false ) ;
}
static int F_123 ( struct V_13 * V_13 , struct V_98 * V_302 )
{
struct V_3 * V_4 = F_31 ( V_302 ) ;
struct V_1 * V_2 = F_32 ( V_302 ) ;
if ( F_14 ( V_126 , & V_2 -> V_6 ) )
return F_121 ( V_4 -> V_10 , V_2 -> V_11 ,
V_2 -> V_116 , NULL , false ) ;
return 0 ;
}
static int F_124 ( struct V_3 * V_4 , struct V_1 * V_2 ,
struct V_357 * V_358 , T_1 * V_359 )
{
int V_70 , V_63 ;
T_2 V_360 [ V_361 ] ;
T_4 V_87 ;
for ( V_87 = 0 ; V_87 < V_358 -> V_362 ; V_87 ++ ) {
memset ( & V_360 , 0 , sizeof( V_360 ) ) ;
for ( V_63 = 0 ; V_63 < V_358 -> V_363 [ V_87 ] . V_364 ; V_63 ++ ) {
if ( V_358 -> V_363 [ V_87 ] . V_360 [ V_63 / 8 ] & ( 0x1 << ( V_63 % 8 ) ) )
V_360 [ V_63 ] = 0xFF ;
}
V_70 = F_125 ( V_4 -> V_10 ,
V_2 -> V_11 , V_365 ,
V_358 -> V_363 [ V_87 ] . V_364 ,
0 ,
V_358 -> V_363 [ V_87 ] . V_366 , V_360 ) ;
if ( V_70 )
return V_70 ;
}
if ( V_358 -> V_367 )
* V_359 |= V_368 ;
if ( V_358 -> V_369 )
* V_359 |= V_370 ;
if ( V_358 -> V_371 )
* V_359 |= V_372 ;
if ( V_358 -> V_373 )
* V_359 |= V_374 ;
if ( V_358 -> V_375 )
* V_359 |= V_376 ;
return 0 ;
}
static int F_126 ( struct V_3 * V_4 , struct V_1 * V_2 )
{
static const T_2 V_377 [] = { 0x00 , 0x00 , 0x00 ,
0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 ,
0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 ,
0x00 , 0x08 } ;
static const T_2 V_378 [] = { 0x01 , 0x00 , 0x00 ,
0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 ,
0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 ,
0x00 , 0x7f } ;
T_2 V_379 = 0 ;
static const T_2 V_380 [] = { 0x08 , 0x06 } ;
static const T_2 V_381 [] = { 0xff , 0xff } ;
T_2 V_382 = 20 ;
static const T_2 V_383 [] = { 0xe0 , 0x00 , 0x00 , 0xf8 } ;
static const T_2 V_384 [] = { 0xf0 , 0x00 , 0x00 , 0xf8 } ;
T_2 V_385 = 38 ;
static const T_2 V_386 [] = { 0xff , 0xff , 0xff , 0xff ,
0xff , 0xff , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 ,
0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x08 , 0x00 ,
0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 ,
0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 ,
0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x43 } ;
static const T_2 V_387 [] = { 0xff , 0xff , 0xff , 0xff ,
0xff , 0xff , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 ,
0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0xff , 0xff ,
0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 ,
0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 ,
0x00 , 0x00 , 0x00 , 0x00 , 0xff , 0xff } ;
T_2 V_388 = 0 ;
int V_70 ;
V_70 = F_125 ( V_4 -> V_10 ,
V_2 -> V_11 , V_365 ,
sizeof( V_377 ) , V_379 ,
V_377 , V_378 ) ;
if ( V_70 ) {
F_9 ( L_67 ) ;
return V_70 ;
}
V_70 = F_125 ( V_4 -> V_10 ,
V_2 -> V_11 , V_365 ,
sizeof( V_380 ) , V_382 ,
V_380 , V_381 ) ;
if ( V_70 ) {
F_9 ( L_68 ) ;
return V_70 ;
}
V_70 = F_125 ( V_4 -> V_10 ,
V_2 -> V_11 , V_365 ,
sizeof( V_383 ) , V_385 ,
V_383 , V_384 ) ;
if ( V_70 ) {
F_9 ( L_69 ) ;
return V_70 ;
}
V_70 = F_125 ( V_4 -> V_10 ,
V_2 -> V_11 , V_365 ,
sizeof( V_386 ) , V_388 ,
V_386 , V_387 ) ;
if ( V_70 ) {
F_9 ( L_70 ) ;
return V_70 ;
}
return 0 ;
}
static int F_127 ( struct V_3 * V_4 , struct V_1 * V_2 )
{
struct V_98 * V_196 = V_2 -> V_196 ;
static const T_2 V_383 [] = { 0xe0 , 0x00 , 0x00 , 0xf8 } ;
static const T_2 V_384 [] = { 0xf0 , 0x00 , 0x00 , 0xf8 } ;
T_2 V_385 = 38 ;
T_2 V_389 [ V_321 ] ;
int V_70 ;
F_128 ( V_389 ) ;
V_70 = F_125 ( V_4 -> V_10 ,
V_2 -> V_11 , V_365 ,
V_321 , 0 , V_196 -> V_390 ,
V_389 ) ;
if ( V_70 ) {
F_9 ( L_71 ) ;
return V_70 ;
}
if ( ( V_196 -> V_6 & V_391 ) ||
( V_196 -> V_6 & V_392 && F_129 ( V_196 ) > 0 ) ) {
V_70 = F_125 ( V_4 -> V_10 ,
V_2 -> V_11 , V_365 ,
sizeof( V_383 ) , V_385 ,
V_383 , V_384 ) ;
if ( V_70 ) {
F_9 ( L_69 ) ;
return V_70 ;
}
}
return 0 ;
}
static int F_130 ( struct V_1 * V_2 )
{
return F_14 ( V_393 , & V_2 -> V_6 ) ;
}
static bool F_131 ( struct V_3 * V_4 )
{
return ! V_4 -> V_93 [ V_4 -> V_394 ] ;
}
static int F_132 ( struct V_3 * V_4 , struct V_1 * V_2 )
{
int V_70 , V_320 ;
F_42 ( V_393 , & V_2 -> V_6 ) ;
V_70 = F_133 ( V_4 -> V_10 , V_2 -> V_11 ,
V_395 ) ;
if ( V_70 )
return V_70 ;
V_320 = F_36 ( V_4 -> V_120 ,
F_130 ( V_2 ) ,
V_121 ) ;
if ( V_320 == 0 ) {
F_70 ( L_72 ) ;
V_70 = - V_323 ;
} else if ( V_320 < 0 ) {
F_70 ( L_73 ,
V_320 ) ;
V_70 = V_320 ;
}
if ( V_4 -> V_93 [ V_4 -> V_394 ] ) {
V_320 = F_36 ( V_4 -> V_120 ,
F_131 ( V_4 ) ,
V_121 ) ;
if ( V_320 == 0 ) {
F_70 ( L_74 ) ;
V_70 = - V_323 ;
} else if ( V_320 < 0 ) {
F_70 ( L_75 , V_320 ) ;
V_70 = V_320 ;
}
}
return V_70 ;
}
static int F_134 ( struct V_1 * V_2 ,
struct V_357 * V_358 , T_1 * V_359 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_396 * V_397 ;
struct V_398 * V_399 ;
int V_70 ;
T_4 V_87 , V_400 ;
T_7 V_401 [ V_402 ] ;
T_2 V_403 = 0 ;
if ( ! F_14 ( V_404 , & V_2 -> V_6 ) &&
F_14 ( V_405 ,
V_4 -> V_97 ) ) {
V_70 = F_135 ( V_2 -> V_4 -> V_10 ,
V_2 -> V_11 , false ) ;
if ( V_70 )
return V_70 ;
}
for ( V_87 = 0 ; V_87 < V_406 ; V_87 ++ )
F_136 ( V_4 -> V_10 , V_2 -> V_11 ,
V_365 , V_87 ) ;
if ( V_358 )
V_70 = F_124 ( V_4 , V_2 , V_358 , V_359 ) ;
else if ( V_2 -> V_77 == V_85 )
V_70 = F_126 ( V_4 , V_2 ) ;
else
V_70 = F_127 ( V_4 , V_2 ) ;
if ( V_70 )
return V_70 ;
F_137 ( V_2 -> V_196 ) ;
if ( V_2 -> V_77 != V_85 ) {
V_70 = F_45 ( V_4 -> V_10 , V_2 -> V_11 ,
V_159 ,
0 ) ;
if ( V_70 )
return V_70 ;
V_400 = V_159 * 15 ;
if ( V_400 > V_407 )
V_400 = V_407 ;
V_70 = F_138 ( V_4 -> V_10 , V_2 -> V_11 ,
V_400 , 0 ) ;
if ( V_70 )
return V_70 ;
V_70 = F_47 ( V_4 -> V_10 , V_2 -> V_11 ,
0xFFFF , 0 , 0xFFFF , 0 , 0 , 0 ,
0 , 0 , 0 , 0 ) ;
if ( V_70 )
return V_70 ;
}
V_397 = F_139 ( V_2 -> V_196 ) ;
if ( ! V_397 )
return 0 ;
V_399 = V_397 -> V_408 ;
memset ( & V_401 , 0 , sizeof( V_401 ) ) ;
while ( V_403 < V_402 && V_399 ) {
V_401 [ V_403 ] = V_399 -> V_409 ;
V_399 = V_399 -> V_410 ;
V_403 ++ ;
}
if ( V_399 ) {
F_9 ( L_76 ) ;
return - V_117 ;
}
V_70 = F_140 ( V_4 -> V_10 , V_2 -> V_11 , V_401 [ 0 ] , V_401 [ 1 ] ) ;
if ( V_70 ) {
F_9 ( L_77 ) ;
return V_70 ;
}
return V_70 ;
}
static int F_141 ( struct V_3 * V_4 , struct V_357 * V_358 )
{
struct V_1 * V_411 , * V_2 ;
int V_70 = 0 ;
T_1 V_359 = 0 ;
bool V_412 = false ;
V_411 = F_90 ( V_4 ) ;
if ( F_28 ( ! V_411 ) ||
! F_13 ( V_411 ) )
return - V_110 ;
if ( V_358 && ( V_358 -> V_362 > V_406 ) )
return - V_117 ;
F_103 ( & V_4 -> V_303 ) ;
F_142 (vif, &ar->vif_list, list) {
if ( ! F_14 ( V_126 , & V_2 -> V_6 ) ||
! F_13 ( V_2 ) )
continue;
V_412 = true ;
V_70 = F_134 ( V_2 , V_358 , & V_359 ) ;
if ( V_70 )
break;
}
F_105 ( & V_4 -> V_303 ) ;
if ( ! V_412 )
return - V_413 ;
else if ( V_70 )
return V_70 ;
V_4 -> V_8 = V_414 ;
V_70 = F_143 ( V_4 -> V_10 , V_411 -> V_11 ,
V_415 ,
V_359 ,
V_416 ) ;
if ( V_70 )
return V_70 ;
return F_132 ( V_4 , V_411 ) ;
}
static int F_144 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
int V_70 ;
if ( V_2 -> V_77 != V_85 ) {
V_70 = F_47 ( V_4 -> V_10 , V_2 -> V_11 ,
0 , 0 , 0 , 0 , 0 , 0 , 3 , 0 , 0 , 0 ) ;
if ( V_70 )
return V_70 ;
V_70 = F_45 ( V_4 -> V_10 , V_2 -> V_11 ,
V_2 -> V_158 , 0 ) ;
if ( V_70 )
return V_70 ;
V_70 = F_138 ( V_4 -> V_10 , V_2 -> V_11 ,
V_2 -> V_417 , 0 ) ;
if ( V_70 )
return V_70 ;
}
if ( ! F_14 ( V_418 , & V_2 -> V_6 ) &&
F_14 ( V_405 ,
V_4 -> V_97 ) ) {
V_70 = F_135 ( V_2 -> V_4 -> V_10 ,
V_2 -> V_11 , true ) ;
if ( V_70 )
return V_70 ;
}
F_145 ( V_2 -> V_196 ) ;
return 0 ;
}
static int F_146 ( struct V_3 * V_4 )
{
struct V_1 * V_2 ;
int V_70 ;
V_2 = F_90 ( V_4 ) ;
if ( F_28 ( ! V_2 ) ||
! F_13 ( V_2 ) )
return - V_110 ;
V_4 -> V_8 = V_419 ;
V_70 = F_133 ( V_4 -> V_10 , V_2 -> V_11 ,
V_420 ) ;
if ( V_70 ) {
F_70 ( L_78 ,
V_70 ) ;
goto V_421;
}
F_103 ( & V_4 -> V_303 ) ;
F_142 (vif, &ar->vif_list, list) {
if ( ! F_14 ( V_126 , & V_2 -> V_6 ) ||
! F_13 ( V_2 ) )
continue;
V_70 = F_144 ( V_2 ) ;
if ( V_70 )
break;
}
F_105 ( & V_4 -> V_303 ) ;
if ( V_70 )
goto V_421;
V_4 -> V_8 = V_422 ;
return 0 ;
V_421:
V_4 -> V_8 = V_423 ;
return V_70 ;
}
static int F_147 ( struct V_3 * V_4 )
{
struct V_1 * V_2 ;
int V_70 ;
V_2 = F_90 ( V_4 ) ;
if ( ! V_2 )
return - V_110 ;
if ( ! F_14 ( V_60 , & V_4 -> V_61 ) ) {
F_9 ( L_79 ) ;
return - V_110 ;
}
F_148 ( V_4 ) ;
V_4 -> V_10 -> V_424 = V_4 -> V_10 -> V_296 ;
V_70 = F_98 ( V_4 -> V_10 , 0 , V_297 ) ;
if ( V_70 )
return V_70 ;
V_70 = F_143 ( V_4 -> V_10 , V_2 -> V_11 ,
V_425 ,
0 , 0 ) ;
if ( V_70 )
return V_70 ;
F_149 ( V_4 ) ;
V_70 = F_132 ( V_4 , V_2 ) ;
if ( V_70 )
return V_70 ;
return 0 ;
}
static int F_150 ( struct V_3 * V_4 )
{
struct V_1 * V_2 ;
int V_70 ;
V_2 = F_90 ( V_4 ) ;
if ( ! V_2 )
return - V_110 ;
if ( V_4 -> V_10 -> V_296 != V_4 -> V_10 -> V_424 ) {
V_70 = F_98 ( V_4 -> V_10 , 0 ,
V_4 -> V_10 -> V_424 ) ;
if ( V_70 )
return V_70 ;
}
V_70 = F_133 ( V_4 -> V_10 , V_2 -> V_11 ,
V_420 ) ;
if ( V_70 )
return V_70 ;
V_4 -> V_8 = V_422 ;
V_70 = F_47 ( V_4 -> V_10 , V_2 -> V_11 ,
0 , 0 , 0 , 0 , 0 , 0 , 3 , 0 , 0 , 0 ) ;
if ( V_70 )
return V_70 ;
return 0 ;
}
int F_151 ( struct V_3 * V_4 ,
enum V_426 V_245 ,
struct V_357 * V_358 )
{
struct V_1 * V_2 ;
enum V_427 V_428 ;
int V_70 ;
switch ( V_245 ) {
case V_429 :
F_8 ( V_430 , L_80 ) ;
F_149 ( V_4 ) ;
V_428 = V_4 -> V_8 ;
V_70 = F_141 ( V_4 , V_358 ) ;
if ( V_70 ) {
V_4 -> V_8 = V_428 ;
return V_70 ;
}
V_4 -> V_8 = V_423 ;
break;
case V_431 :
F_8 ( V_430 , L_81 ) ;
V_70 = F_147 ( V_4 ) ;
if ( V_70 ) {
F_9 ( L_82 , V_70 ) ;
return V_70 ;
}
V_4 -> V_8 = V_432 ;
break;
case V_433 :
F_148 ( V_4 ) ;
if ( V_4 -> V_8 == V_434 ) {
F_8 ( V_430 ,
L_83 ) ;
break;
}
F_8 ( V_430 , L_84 ) ;
V_70 = F_152 ( V_4 ) ;
if ( V_70 ) {
F_70 ( L_85 ,
V_70 ) ;
}
V_4 -> V_8 = V_435 ;
break;
default:
break;
}
F_142 (vif, &ar->vif_list, list)
F_72 ( V_2 , true ) ;
return 0 ;
}
int F_153 ( struct V_3 * V_4 )
{
int V_70 ;
switch ( V_4 -> V_8 ) {
case V_423 :
F_8 ( V_430 , L_86 ) ;
V_70 = F_146 ( V_4 ) ;
if ( V_70 ) {
F_70 ( L_87 , V_70 ) ;
return V_70 ;
}
break;
case V_432 :
F_8 ( V_430 , L_88 ) ;
V_70 = F_150 ( V_4 ) ;
if ( V_70 ) {
F_70 ( L_89 , V_70 ) ;
return V_70 ;
}
break;
case V_435 :
F_8 ( V_430 , L_90 ) ;
V_70 = F_154 ( V_4 ) ;
if ( V_70 ) {
F_70 ( L_91 , V_70 ) ;
return V_70 ;
}
break;
default:
break;
}
return 0 ;
}
static int F_155 ( struct V_13 * V_13 ,
struct V_357 * V_358 )
{
struct V_3 * V_4 = F_89 ( V_13 ) ;
F_156 ( V_4 ) ;
return F_157 ( V_4 , V_358 ) ;
}
static int F_158 ( struct V_13 * V_13 )
{
struct V_3 * V_4 = F_89 ( V_13 ) ;
int V_95 ;
V_95 = F_159 ( V_4 ) ;
if ( V_95 )
return V_95 ;
F_160 ( V_4 ) ;
return 0 ;
}
void F_161 ( struct V_3 * V_4 )
{
if ( V_4 -> V_8 == V_414 )
return;
if ( V_4 -> V_8 == V_423 )
F_153 ( V_4 ) ;
}
void F_161 ( struct V_3 * V_4 )
{
}
static int F_162 ( struct V_1 * V_2 , enum V_436 V_437 ,
bool V_438 )
{
struct V_439 * V_440 = & V_2 -> V_440 [ V_437 ] ;
if ( V_440 -> V_438 == V_438 )
return 0 ;
if ( V_438 ) {
V_440 -> V_438 = true ;
V_440 -> V_441 = ( V_437 == V_442 ) ?
V_443 : V_444 ;
V_440 -> V_445 = V_446 ;
} else
memset ( V_440 , 0 , sizeof( * V_440 ) ) ;
return F_163 ( V_2 -> V_4 -> V_10 , V_2 -> V_11 ,
V_437 , V_440 ) ;
}
static int F_164 ( struct V_1 * V_2 )
{
struct V_13 * V_13 = V_2 -> V_4 -> V_13 ;
int V_437 , V_70 = 0 ;
for ( V_437 = 0 ; V_437 < V_447 ; V_437 ++ ) {
if ( ! V_13 -> V_448 [ V_437 ] )
continue;
V_70 = F_162 ( V_2 , V_437 ,
V_13 -> V_448 [ V_437 ] -> V_250 . V_251 ) ;
if ( V_70 )
return V_70 ;
}
return V_70 ;
}
static bool F_165 ( const T_2 * V_63 )
{
return V_63 [ 0 ] == V_64 && V_63 [ 1 ] >= 4 &&
V_63 [ 2 ] == 0x50 && V_63 [ 3 ] == 0x6f &&
V_63 [ 4 ] == 0x9a && V_63 [ 5 ] == 0x09 ;
}
static int F_166 ( struct V_1 * V_2 ,
const T_2 * V_66 , T_3 V_67 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
const T_2 * V_63 ;
T_2 * V_68 = NULL ;
T_3 V_69 = 0 ;
int V_70 ;
if ( V_66 && V_67 ) {
V_68 = F_19 ( V_67 , V_73 ) ;
if ( V_68 == NULL )
return - V_74 ;
V_63 = V_66 ;
while ( V_63 + 1 < V_66 + V_67 ) {
if ( V_63 + 2 + V_63 [ 1 ] > V_66 + V_67 )
break;
if ( ! F_165 ( V_63 ) ) {
memcpy ( V_68 + V_69 , V_63 , 2 + V_63 [ 1 ] ) ;
V_69 += 2 + V_63 [ 1 ] ;
}
V_63 += 2 + V_63 [ 1 ] ;
}
}
V_70 = F_20 ( V_4 -> V_10 , V_2 -> V_11 ,
V_449 , V_68 , V_69 ) ;
F_21 ( V_68 ) ;
return V_70 ;
}
static int F_167 ( struct V_1 * V_2 ,
struct V_450 * V_210 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
int V_451 ;
V_451 = F_20 ( V_4 -> V_10 , V_2 -> V_11 ,
V_452 ,
V_210 -> V_453 ,
V_210 -> V_454 ) ;
if ( V_451 )
return V_451 ;
V_451 = F_166 ( V_2 , V_210 -> V_455 ,
V_210 -> V_456 ) ;
if ( V_451 )
return V_451 ;
V_451 = F_20 ( V_4 -> V_10 , V_2 -> V_11 ,
V_457 ,
V_210 -> V_458 ,
V_210 -> V_459 ) ;
if ( V_451 )
return V_451 ;
return 0 ;
}
static int F_168 ( struct V_450 * V_460 ,
T_2 * V_461 )
{
const T_2 * V_462 ;
T_3 V_463 ;
T_4 V_464 ;
if ( ! V_460 -> V_465 )
return - V_117 ;
V_462 = F_169 ( V_65 , V_460 -> V_465 , V_460 -> V_466 ) ;
if ( ! V_462 )
return - V_117 ;
V_463 = * ( V_462 + 1 ) ;
V_462 += 2 ;
if ( V_463 < 2 )
return - V_117 ;
V_462 += 2 ;
V_463 -= 2 ;
if ( V_463 < 4 )
return 0 ;
V_462 += 4 ;
V_463 -= 4 ;
if ( V_463 < 2 )
return 0 ;
V_464 = F_170 ( V_462 ) ;
V_462 += ( 2 + V_464 * 4 ) ;
V_463 -= ( 2 + V_464 * 4 ) ;
if ( V_463 < 2 )
return 0 ;
V_464 = F_170 ( V_462 ) ;
V_462 += ( 2 + V_464 * 4 ) ;
V_463 -= ( 2 + V_464 * 4 ) ;
if ( V_463 < 2 )
return 0 ;
memcpy ( V_461 , V_462 , 2 ) ;
return 0 ;
}
static int F_171 ( struct V_13 * V_13 , struct V_98 * V_99 ,
struct V_467 * V_210 )
{
struct V_3 * V_4 = F_31 ( V_99 ) ;
struct V_1 * V_2 = F_32 ( V_99 ) ;
struct V_468 * V_469 ;
bool V_470 = false ;
T_2 * V_66 ;
int V_67 ;
struct V_471 V_472 ;
int V_451 ;
int V_87 , V_70 ;
T_4 V_461 = 0 ;
int V_473 = 0 ;
F_8 ( V_16 , L_92 , V_17 ) ;
if ( ! F_13 ( V_2 ) )
return - V_110 ;
if ( V_2 -> V_154 != V_85 )
return - V_291 ;
V_451 = F_167 ( V_2 , & V_210 -> V_460 ) ;
V_4 -> V_269 . V_270 = false ;
V_70 = F_172 ( V_4 -> V_10 , V_2 -> V_11 ,
V_210 -> V_353 ) ;
if ( V_70 )
F_70 ( L_93 , V_70 ) ;
V_70 = F_173 ( V_4 -> V_10 , V_2 -> V_11 ,
V_210 -> V_351 ) ;
if ( V_70 )
F_70 ( L_94 , V_70 ) ;
if ( V_210 -> V_460 . V_474 == NULL )
return - V_117 ;
V_469 = (struct V_468 * ) V_210 -> V_460 . V_474 ;
V_66 = V_469 -> V_475 . V_460 . V_476 ;
if ( V_66 > V_210 -> V_460 . V_474 + V_210 -> V_460 . V_477 )
return - V_117 ;
V_67 = V_210 -> V_460 . V_474 + V_210 -> V_460 . V_477 - V_66 ;
if ( V_210 -> V_128 == NULL )
return - V_117 ;
memcpy ( V_2 -> V_128 , V_210 -> V_128 , V_210 -> V_127 ) ;
V_2 -> V_127 = V_210 -> V_127 ;
if ( V_210 -> V_478 != V_479 )
V_470 = true ;
V_451 = F_174 ( V_4 -> V_10 , V_2 -> V_11 , V_470 ) ;
if ( V_451 )
return V_451 ;
V_70 = F_10 ( V_2 , V_210 -> V_26 ) ;
if ( V_70 )
return V_70 ;
memset ( & V_472 , 0 , sizeof( V_472 ) ) ;
for ( V_87 = 0 ; V_87 < V_210 -> V_132 . V_137 ; V_87 ++ ) {
switch ( V_210 -> V_132 . V_138 [ V_87 ] ) {
case V_59 :
if ( V_210 -> V_132 . V_133 & V_22 )
V_472 . V_18 |= V_23 ;
if ( V_210 -> V_132 . V_133 & V_20 )
V_472 . V_18 |= V_21 ;
break;
case V_54 :
if ( V_210 -> V_132 . V_133 & V_22 )
V_472 . V_18 |= V_55 ;
if ( V_210 -> V_132 . V_133 & V_20 )
V_472 . V_18 |= V_56 ;
break;
}
}
if ( V_472 . V_18 == 0 )
V_472 . V_18 = V_19 ;
V_2 -> V_18 = V_472 . V_18 ;
for ( V_87 = 0 ; V_87 < V_210 -> V_132 . V_134 ; V_87 ++ ) {
switch ( V_210 -> V_132 . V_135 [ V_87 ] ) {
case V_44 :
case V_46 :
V_472 . V_480 |= V_45 ;
break;
case V_47 :
V_472 . V_480 |= V_48 ;
break;
case V_49 :
V_472 . V_480 |= V_50 ;
break;
case V_51 :
V_472 . V_480 |= V_52 ;
break;
}
}
if ( V_472 . V_480 == 0 ) {
V_472 . V_480 = V_43 ;
F_11 ( V_2 , 0 , true ) ;
} else if ( V_210 -> V_132 . V_134 == 1 ) {
F_11 ( V_2 , V_210 -> V_132 . V_135 [ 0 ] , true ) ;
}
switch ( V_210 -> V_132 . V_136 ) {
case V_44 :
case V_46 :
V_472 . V_481 = V_45 ;
break;
case V_47 :
V_472 . V_481 = V_48 ;
break;
case V_49 :
V_472 . V_481 = V_50 ;
break;
case V_51 :
V_472 . V_481 = V_52 ;
break;
default:
V_472 . V_481 = V_43 ;
break;
}
F_11 ( V_2 , V_210 -> V_132 . V_136 , false ) ;
V_472 . V_77 = V_85 ;
V_2 -> V_77 = V_2 -> V_154 ;
V_472 . V_127 = V_2 -> V_127 ;
memcpy ( V_472 . V_128 , V_2 -> V_128 , V_2 -> V_127 ) ;
V_472 . V_28 = V_2 -> V_28 ;
V_472 . V_482 = F_175 ( V_210 -> V_247 . V_170 -> V_115 ) ;
V_451 = F_176 ( V_4 -> V_10 , V_2 -> V_11 , true ) ;
if ( V_451 < 0 )
return V_451 ;
if ( V_2 -> V_155 . V_156 == V_84 ) {
V_472 . V_103 = V_483 ;
} else {
V_472 . V_103 = V_106 ;
}
if ( V_210 -> V_473 ) {
V_473 = V_210 -> V_473 ;
if ( F_14 ( V_484 ,
V_4 -> V_97 ) )
V_473 = F_177 ( V_473 ,
60 ) ;
V_451 = F_178 ( V_4 -> V_10 , V_2 -> V_11 ,
V_473 ) ;
if ( V_451 < 0 )
return V_451 ;
}
if ( F_162 ( V_2 , V_210 -> V_247 . V_170 -> V_437 ,
F_179 ( & V_210 -> V_247 )
!= V_253 ) )
return - V_110 ;
if ( ! F_168 ( & V_210 -> V_460 , ( T_2 * ) & V_461 ) &&
F_14 ( V_485 ,
V_4 -> V_97 ) ) {
V_451 = F_180 ( V_4 -> V_10 , V_2 -> V_11 ,
V_65 , V_486 ,
( const T_2 * ) & V_461 ,
sizeof( V_461 ) ) ;
V_2 -> V_461 = V_461 ;
if ( V_451 < 0 )
return V_451 ;
}
memcpy ( & V_2 -> V_487 , & V_472 , sizeof( V_472 ) ) ;
V_451 = F_181 ( V_4 -> V_10 , V_2 -> V_11 , & V_472 ) ;
if ( V_451 < 0 )
return V_451 ;
return 0 ;
}
static int F_182 ( struct V_13 * V_13 , struct V_98 * V_99 ,
struct V_450 * V_460 )
{
struct V_1 * V_2 = F_32 ( V_99 ) ;
if ( ! F_13 ( V_2 ) )
return - V_110 ;
if ( V_2 -> V_154 != V_85 )
return - V_291 ;
return F_167 ( V_2 , V_460 ) ;
}
static int F_183 ( struct V_13 * V_13 , struct V_98 * V_99 )
{
struct V_3 * V_4 = F_31 ( V_99 ) ;
struct V_1 * V_2 = F_32 ( V_99 ) ;
if ( V_2 -> V_77 != V_85 )
return - V_291 ;
if ( ! F_14 ( V_126 , & V_2 -> V_6 ) )
return - V_413 ;
F_64 ( V_4 -> V_10 , V_2 -> V_11 ) ;
F_42 ( V_126 , & V_2 -> V_6 ) ;
F_184 ( V_2 -> V_196 ) ;
return F_164 ( V_2 ) ;
}
static int F_185 ( struct V_13 * V_13 , struct V_98 * V_99 ,
struct V_488 * V_259 )
{
struct V_3 * V_4 = F_31 ( V_99 ) ;
struct V_1 * V_2 = F_32 ( V_99 ) ;
const T_2 * V_489 = V_259 -> V_317 ? V_259 -> V_317 : V_490 ;
return F_186 ( V_4 -> V_10 , V_2 -> V_11 , V_491 ,
V_489 , V_492 ) ;
}
static int F_187 ( struct V_13 * V_13 , struct V_98 * V_99 ,
const T_2 * V_317 ,
struct V_493 * V_259 )
{
struct V_3 * V_4 = F_31 ( V_99 ) ;
struct V_1 * V_2 = F_32 ( V_99 ) ;
int V_95 ;
if ( V_2 -> V_77 != V_85 )
return - V_291 ;
V_95 = F_188 ( V_13 , V_259 ,
V_494 ) ;
if ( V_95 )
return V_95 ;
if ( V_259 -> V_495 & F_24 ( V_496 ) )
return F_186 ( V_4 -> V_10 , V_2 -> V_11 ,
V_497 , V_317 , 0 ) ;
return F_186 ( V_4 -> V_10 , V_2 -> V_11 ,
V_498 , V_317 , 0 ) ;
}
static int F_189 ( struct V_13 * V_13 ,
struct V_284 * V_155 ,
struct V_169 * V_170 ,
unsigned int V_499 ,
T_8 * V_273 )
{
struct V_1 * V_2 = F_68 ( V_155 ) ;
struct V_3 * V_4 = F_31 ( V_2 -> V_196 ) ;
T_1 V_500 ;
V_500 = ++ V_2 -> V_501 ;
if ( V_500 == 0 ) {
V_500 = ++ V_2 -> V_501 ;
}
* V_273 = V_500 ;
return F_190 ( V_4 -> V_10 , V_2 -> V_11 ,
V_170 -> V_115 , V_499 ) ;
}
static int F_191 ( struct V_13 * V_13 ,
struct V_284 * V_155 ,
T_8 V_273 )
{
struct V_1 * V_2 = F_68 ( V_155 ) ;
struct V_3 * V_4 = F_31 ( V_2 -> V_196 ) ;
if ( V_273 != V_2 -> V_501 )
return - V_144 ;
V_2 -> V_502 = V_273 ;
return F_192 ( V_4 -> V_10 , V_2 -> V_11 ) ;
}
static int F_193 ( struct V_1 * V_2 ,
const T_2 * V_68 , T_3 V_69 ,
unsigned int V_243 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
const T_2 * V_63 ;
T_2 * V_104 ;
int V_503 ;
int V_70 ;
const struct V_468 * V_469 ;
V_469 = ( const struct V_468 * ) V_68 ;
V_104 = F_19 ( V_69 , V_73 ) ;
if ( V_104 == NULL )
return - V_74 ;
V_503 = 0 ;
V_63 = V_469 -> V_475 . V_504 . V_476 ;
while ( V_63 + 1 < V_68 + V_69 ) {
if ( V_63 + 2 + V_63 [ 1 ] > V_68 + V_69 )
break;
if ( F_165 ( V_63 ) ) {
memcpy ( V_104 + V_503 , V_63 , 2 + V_63 [ 1 ] ) ;
V_503 += 2 + V_63 [ 1 ] ;
}
V_63 += 2 + V_63 [ 1 ] ;
}
V_70 = F_194 ( V_4 -> V_10 , V_2 -> V_11 , V_243 ,
V_469 -> V_505 , V_104 , V_503 ) ;
F_21 ( V_104 ) ;
return V_70 ;
}
static bool F_195 ( struct V_1 * V_2 ,
T_1 V_500 ,
T_1 V_243 ,
T_1 V_506 ,
const T_2 * V_68 ,
T_3 V_69 ,
bool * V_507 ,
bool V_240 )
{
struct V_468 * V_469 ;
struct V_508 * V_509 ;
bool V_510 = false ;
struct V_511 * V_512 ;
T_3 V_513 ;
struct V_3 * V_4 = V_2 -> V_4 ;
V_469 = (struct V_468 * ) V_68 ;
if ( F_196 ( V_469 -> V_505 ) )
return false ;
V_509 = F_197 ( V_2 , V_469 -> V_505 ) ;
if ( ! V_509 )
return false ;
if ( V_509 -> V_514 & V_515 ) {
if ( ! ( V_509 -> V_514 & V_516 ) ) {
V_513 = V_69 + sizeof( struct V_511 ) ;
V_512 = F_19 ( V_513 , V_73 ) ;
if ( ! V_512 )
return false ;
F_198 ( & V_512 -> V_304 ) ;
V_512 -> V_500 = V_500 ;
V_512 -> V_243 = V_243 ;
V_512 -> V_506 = V_506 ;
V_512 -> V_69 = V_69 ;
V_512 -> V_240 = V_240 ;
memcpy ( V_512 -> V_68 , V_68 , V_69 ) ;
F_103 ( & V_509 -> V_517 ) ;
V_510 = F_199 ( & V_509 -> V_518 ) &&
( V_509 -> V_519 == 0 ) ;
F_200 ( & V_512 -> V_304 , & V_509 -> V_520 ) ;
V_509 -> V_519 ++ ;
F_105 ( & V_509 -> V_517 ) ;
if ( V_510 )
F_201 ( V_4 -> V_10 , V_2 -> V_11 ,
V_509 -> V_521 , 1 ) ;
return true ;
}
F_103 ( & V_509 -> V_517 ) ;
if ( ! F_199 ( & V_509 -> V_518 ) || ( V_509 -> V_519 != 0 ) )
* V_507 = true ;
F_105 ( & V_509 -> V_517 ) ;
}
return false ;
}
static bool F_202 ( const T_2 * V_68 , T_3 V_69 )
{
const struct V_468 * V_469 ;
V_469 = ( const struct V_468 * ) V_68 ;
if ( V_68 + V_69 >= & V_469 -> V_475 . V_504 . V_476 [ 1 ] &&
( V_469 -> V_475 . V_504 . V_476 [ 1 ] > V_522 ) ) {
return true ;
}
return false ;
}
static int F_203 ( struct V_13 * V_13 , struct V_284 * V_155 ,
struct V_523 * V_259 , T_8 * V_273 )
{
struct V_1 * V_2 = F_68 ( V_155 ) ;
struct V_3 * V_4 = F_31 ( V_2 -> V_196 ) ;
struct V_169 * V_170 = V_259 -> V_170 ;
const T_2 * V_68 = V_259 -> V_68 ;
T_3 V_69 = V_259 -> V_69 ;
unsigned int V_506 = V_259 -> V_506 ;
bool V_240 = V_259 -> V_240 ;
T_1 V_500 , V_243 ;
const struct V_468 * V_469 ;
bool V_507 , V_524 ;
V_243 = V_2 -> V_131 ;
if ( V_170 )
V_243 = V_170 -> V_115 ;
if ( F_28 ( V_243 == 0 ) )
return - V_117 ;
V_469 = ( const struct V_468 * ) V_68 ;
if ( V_2 -> V_77 == V_85 && F_14 ( V_126 , & V_2 -> V_6 ) &&
F_204 ( V_469 -> V_525 ) &&
F_202 ( V_68 , V_69 ) ) {
* V_273 = 0 ;
return F_193 ( V_2 , V_68 , V_69 , V_243 ) ;
}
V_500 = V_2 -> V_526 ++ ;
if ( V_500 == 0 ) {
V_500 = V_2 -> V_526 ++ ;
}
* V_273 = V_500 ;
if ( V_2 -> V_77 == V_85 ) {
V_524 = F_195 ( V_2 , V_500 , V_243 , V_506 , V_68 , V_69 ,
& V_507 , V_240 ) ;
if ( V_524 )
return 0 ;
}
return F_205 ( V_4 -> V_10 , V_2 -> V_11 , V_500 , V_243 ,
V_506 , V_68 , V_69 , V_240 ) ;
}
static int F_206 ( struct V_13 * V_13 ,
T_1 * V_527 , T_1 * V_528 )
{
struct V_3 * V_4 = F_89 ( V_13 ) ;
* V_527 = V_4 -> V_529 . V_527 ;
* V_528 = V_4 -> V_529 . V_528 ;
return 0 ;
}
static void F_207 ( struct V_13 * V_13 ,
struct V_284 * V_155 ,
T_4 V_530 , bool V_531 )
{
struct V_1 * V_2 = F_68 ( V_155 ) ;
F_8 ( V_16 , L_95 ,
V_17 , V_530 , V_531 ) ;
if ( V_530 == V_532 ) {
V_2 -> V_533 = V_531 ;
}
}
static int F_208 ( struct V_13 * V_13 ,
struct V_98 * V_99 ,
struct V_534 * V_232 )
{
struct V_3 * V_4 = F_31 ( V_99 ) ;
struct V_1 * V_2 = F_32 ( V_99 ) ;
T_4 V_107 ;
int V_70 , V_535 ;
int V_536 = V_232 -> V_536 ;
if ( V_536 == 1 && ! V_232 -> V_537 [ 0 ] . V_128 . V_127 )
V_536 = 0 ;
if ( V_4 -> V_8 != V_422 )
return - V_110 ;
if ( V_2 -> V_108 != V_213 )
return - V_112 ;
F_72 ( V_2 , true ) ;
V_70 = F_65 ( V_4 , V_2 , V_232 -> V_216 ,
V_232 -> V_217 ,
V_232 -> V_537 ,
V_536 ) ;
if ( V_70 < 0 )
return V_70 ;
if ( ! V_536 ) {
V_70 = F_43 ( V_4 -> V_10 , V_2 -> V_11 ,
V_153 , 0 ) ;
if ( V_70 < 0 )
return V_70 ;
} else {
V_70 = F_43 ( V_4 -> V_10 , V_2 -> V_11 ,
V_538 , 0 ) ;
if ( V_70 < 0 )
return V_70 ;
}
if ( F_14 ( V_539 ,
V_4 -> V_97 ) ) {
if ( V_232 -> V_540 <= V_541 )
V_535 = 0 ;
else if ( V_232 -> V_540 < - 127 )
V_535 = - 127 ;
else
V_535 = V_232 -> V_540 ;
V_70 = F_209 ( V_4 -> V_10 , V_2 -> V_11 ,
V_535 ) ;
if ( V_70 ) {
F_9 ( L_96 ) ;
return V_70 ;
}
}
V_107 = F_44 ( T_4 , 1 , V_232 -> V_542 [ 0 ] . V_107 ) ;
F_47 ( V_4 -> V_10 , V_2 -> V_11 ,
V_107 , V_107 ,
V_2 -> V_160 , 0 , 0 , 0 , 3 , 0 , 0 , 0 ) ;
V_70 = F_20 ( V_4 -> V_10 , V_2 -> V_11 ,
V_236 ,
V_232 -> V_124 , V_232 -> V_125 ) ;
if ( V_70 ) {
F_70 ( L_97 ,
V_70 ) ;
return V_70 ;
}
V_70 = F_4 ( V_4 -> V_10 , V_2 -> V_11 , true ) ;
if ( V_70 )
return V_70 ;
F_50 ( V_5 , & V_2 -> V_6 ) ;
return 0 ;
}
static int F_210 ( struct V_13 * V_13 ,
struct V_98 * V_99 , T_8 V_543 )
{
struct V_1 * V_2 = F_32 ( V_99 ) ;
bool V_12 ;
V_12 = F_1 ( V_2 ) ;
if ( ! V_12 )
return - V_110 ;
return 0 ;
}
static int F_211 ( struct V_13 * V_13 ,
struct V_98 * V_99 ,
const T_2 * V_489 ,
const struct V_544 * V_360 )
{
struct V_3 * V_4 = F_31 ( V_99 ) ;
struct V_1 * V_2 = F_32 ( V_99 ) ;
return F_212 ( V_4 -> V_10 , V_2 -> V_11 ,
V_360 ) ;
}
static int F_213 ( struct V_13 * V_13 ,
struct V_98 * V_99 ,
T_1 V_311 , T_1 V_545 , T_1 V_546 )
{
struct V_3 * V_4 = F_31 ( V_99 ) ;
struct V_1 * V_2 = F_32 ( V_99 ) ;
if ( V_2 -> V_77 != V_80 ||
! F_14 ( V_547 , V_4 -> V_97 ) )
return - V_291 ;
if ( V_2 -> V_108 != V_197 )
return - V_413 ;
V_2 -> V_548 = V_546 ;
return F_214 ( V_4 -> V_10 , V_2 -> V_11 ,
V_311 , V_545 , V_546 ) ;
}
void F_215 ( struct V_1 * V_2 )
{
F_5 ( V_2 ) ;
switch ( V_2 -> V_108 ) {
case V_213 :
break;
case V_109 :
F_58 ( V_2 -> V_196 , V_2 -> V_116 , NULL , 0 ,
NULL , 0 ,
V_212 ,
V_73 ) ;
break;
case V_197 :
F_63 ( V_2 -> V_196 , 0 , NULL , 0 , true , V_73 ) ;
break;
}
if ( V_2 -> V_4 -> V_8 != V_9 &&
( F_14 ( V_126 , & V_2 -> V_6 ) ||
F_14 ( V_166 , & V_2 -> V_6 ) ) )
F_64 ( V_2 -> V_4 -> V_10 , V_2 -> V_11 ) ;
V_2 -> V_108 = V_213 ;
F_42 ( V_126 , & V_2 -> V_6 ) ;
F_42 ( V_166 , & V_2 -> V_6 ) ;
F_137 ( V_2 -> V_196 ) ;
F_184 ( V_2 -> V_196 ) ;
if ( V_2 -> V_4 -> V_8 != V_9 &&
F_47 ( V_2 -> V_4 -> V_10 , V_2 -> V_11 , 0xFFFF ,
0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 ) != 0 )
F_70 ( L_98 ) ;
F_72 ( V_2 , true ) ;
}
void F_148 ( struct V_3 * V_4 )
{
struct V_1 * V_2 ;
V_2 = F_90 ( V_4 ) ;
if ( ! V_2 && V_4 -> V_8 != V_9 ) {
V_4 -> V_10 -> V_424 = V_4 -> V_10 -> V_296 ;
if ( F_98 ( V_4 -> V_10 , 0 , V_297 ) != 0 )
F_70 ( L_99 ) ;
return;
}
F_142 (vif, &ar->vif_list, list)
F_215 ( V_2 ) ;
}
static void F_216 ( struct V_13 * V_13 ,
struct V_549 * V_232 )
{
struct V_3 * V_4 = F_89 ( V_13 ) ;
T_1 V_241 [ V_447 ] ;
int V_70 , V_87 ;
F_8 ( V_16 ,
L_100 ,
V_232 -> V_550 [ 0 ] , V_232 -> V_550 [ 1 ] ,
V_232 -> V_551 ? L_101 : L_42 ,
V_232 -> V_552 ? L_102 : L_42 ,
V_232 -> V_553 , V_232 -> V_554 ) ;
if ( V_232 -> V_554 != V_555 )
return;
V_70 = F_217 ( V_4 -> V_10 , V_232 -> V_550 ) ;
if ( V_70 ) {
F_9 ( L_103 , V_70 ) ;
return;
}
for ( V_87 = 0 ; V_87 < V_447 ; V_87 ++ )
if ( V_13 -> V_448 [ V_87 ] )
V_241 [ V_87 ] = ( 1 << V_13 -> V_448 [ V_87 ] -> V_556 ) - 1 ;
V_70 = F_71 ( V_4 -> V_10 , 0 , V_238 , false ,
false , 0 , V_239 ,
0 , NULL , false , V_241 ) ;
if ( V_70 ) {
F_9 ( L_104 ,
V_70 ) ;
return;
}
}
static int F_218 ( struct V_1 * V_2 )
{
V_2 -> V_557 = F_219 ( V_2 ) ;
if ( ! V_2 -> V_557 ) {
F_9 ( L_105 ) ;
return - V_74 ;
}
F_220 ( & V_2 -> V_163 , V_558 ,
( unsigned long ) V_2 -> V_196 ) ;
F_220 ( & V_2 -> V_7 , V_559 ,
( unsigned long ) V_2 ) ;
F_50 ( V_560 , & V_2 -> V_6 ) ;
F_221 ( & V_2 -> V_561 ) ;
F_198 ( & V_2 -> V_562 ) ;
return 0 ;
}
void F_106 ( struct V_1 * V_2 , bool V_563 )
{
static T_2 V_564 [] = { 0xff , 0xff , 0xff , 0xff , 0xff , 0xff } ;
bool V_565 ;
F_137 ( V_2 -> V_196 ) ;
F_42 ( V_62 , & V_2 -> V_6 ) ;
if ( V_563 ) {
V_565 = F_14 ( V_126 , & V_2 -> V_6 ) ||
F_14 ( V_166 , & V_2 -> V_6 ) ;
F_39 ( V_2 ) ;
F_80 ( & V_2 -> V_163 ) ;
if ( V_565 )
F_222 ( V_2 , V_214 ,
( V_2 -> V_77 & V_85 ) ?
V_564 : V_2 -> V_116 ,
0 , NULL , 0 ) ;
}
if ( V_2 -> V_208 ) {
struct V_209 V_210 = {
. V_211 = true ,
} ;
F_62 ( V_2 -> V_208 , & V_210 ) ;
V_2 -> V_208 = NULL ;
}
F_27 ( V_2 , false ) ;
}
void F_108 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_566 * V_562 , * V_567 ;
F_223 ( V_2 -> V_557 ) ;
V_4 -> V_91 |= F_24 ( V_2 -> V_11 ) ;
if ( V_2 -> V_77 == V_82 )
V_4 -> V_88 = false ;
F_224 (mc_filter, tmp, &vif->mc_filter, list) {
F_104 ( & V_562 -> V_304 ) ;
F_21 ( V_562 ) ;
}
F_225 ( V_2 -> V_196 ) ;
V_4 -> V_89 -- ;
}
static int F_226 ( struct V_98 * V_99 , int V_568 )
{
int V_569 = 0 ;
if ( V_568 == V_570 )
V_569 += V_571 ;
if ( V_569 == 0 )
return - V_291 ;
return V_569 ;
}
static void F_227 ( struct V_98 * V_99 ,
struct V_572 * V_573 ,
T_8 * V_574 )
{
struct V_1 * V_2 = F_32 ( V_99 ) ;
struct V_3 * V_4 = V_2 -> V_4 ;
int V_87 = 0 ;
struct V_324 * V_575 ;
memset ( V_574 , 0 , sizeof( T_8 ) * V_571 ) ;
F_228 ( V_4 , V_2 ) ;
V_575 = & V_2 -> V_324 ;
V_574 [ V_87 ++ ] = V_575 -> V_576 + V_575 -> V_577 ;
V_574 [ V_87 ++ ] = V_575 -> V_578 + V_575 -> V_579 ;
V_574 [ V_87 ++ ] = V_575 -> V_580 + V_575 -> V_581 ;
V_574 [ V_87 ++ ] = V_575 -> V_582 + V_575 -> V_583 ;
V_574 [ V_87 ++ ] = V_575 -> V_576 ;
V_574 [ V_87 ++ ] = V_575 -> V_577 ;
V_574 [ V_87 ++ ] = V_575 -> V_578 ;
V_574 [ V_87 ++ ] = V_575 -> V_579 ;
V_574 [ V_87 ++ ] = V_575 -> V_584 ;
V_574 [ V_87 ++ ] = V_575 -> V_585 ;
V_574 [ V_87 ++ ] = V_575 -> V_586 ;
V_574 [ V_87 ++ ] = V_575 -> V_587 ;
V_574 [ V_87 ++ ] = V_575 -> V_588 ;
V_574 [ V_87 ++ ] = V_575 -> V_589 ;
V_574 [ V_87 ++ ] = V_575 -> V_590 ;
V_574 [ V_87 ++ ] = V_575 -> V_580 ;
V_574 [ V_87 ++ ] = V_575 -> V_591 ;
V_574 [ V_87 ++ ] = V_575 -> V_581 ;
V_574 [ V_87 ++ ] = V_575 -> V_582 ;
V_574 [ V_87 ++ ] = V_575 -> V_583 ;
V_574 [ V_87 ++ ] = V_575 -> V_592 ;
V_574 [ V_87 ++ ] = V_575 -> V_593 ;
V_574 [ V_87 ++ ] = V_575 -> V_594 ;
V_574 [ V_87 ++ ] = V_575 -> V_595 ;
V_574 [ V_87 ++ ] = V_575 -> V_596 ;
V_574 [ V_87 ++ ] = V_575 -> V_597 ;
V_574 [ V_87 ++ ] = V_575 -> V_598 ;
V_574 [ V_87 ++ ] = V_575 -> V_599 ;
V_574 [ V_87 ++ ] = V_575 -> V_600 ;
V_574 [ V_87 ++ ] = V_575 -> V_601 ;
V_574 [ V_87 ++ ] = V_575 -> V_602 ;
V_574 [ V_87 ++ ] = V_575 -> V_603 ;
V_574 [ V_87 ++ ] = V_575 -> V_604 ;
V_574 [ V_87 ++ ] = V_575 -> V_605 ;
V_574 [ V_87 ++ ] = V_575 -> V_606 ;
V_574 [ V_87 ++ ] = V_575 -> V_607 ;
V_574 [ V_87 ++ ] = V_575 -> V_608 ;
if ( V_87 != V_571 ) {
F_229 ( 1 ) ;
F_9 ( L_106 ,
V_87 , ( int ) V_571 ) ;
}
}
static void F_230 ( struct V_98 * V_99 , T_1 V_568 , T_2 * V_574 )
{
int V_609 = 0 ;
if ( V_568 == V_570 ) {
V_609 = sizeof( V_610 ) ;
memcpy ( V_574 , V_610 , V_609 ) ;
}
}
struct V_284 * F_101 ( struct V_3 * V_4 , const char * V_299 ,
unsigned char V_300 ,
enum V_76 type ,
T_2 V_11 , T_2 V_77 )
{
struct V_98 * V_196 ;
struct V_1 * V_2 ;
V_196 = F_231 ( sizeof( * V_2 ) , V_299 , V_300 , V_611 ) ;
if ( ! V_196 )
return NULL ;
V_2 = F_32 ( V_196 ) ;
V_196 -> V_612 = & V_2 -> V_155 ;
V_2 -> V_155 . V_13 = V_4 -> V_13 ;
V_2 -> V_4 = V_4 ;
V_2 -> V_196 = V_196 ;
F_232 ( V_196 , F_233 ( V_2 -> V_155 . V_13 ) ) ;
V_2 -> V_155 . V_302 = V_196 ;
V_2 -> V_155 . V_156 = type ;
V_2 -> V_11 = V_11 ;
V_2 -> V_77 = V_77 ;
V_2 -> V_154 = V_77 ;
V_2 -> V_158 = V_613 ;
V_2 -> V_417 = V_614 ;
V_2 -> V_160 = 0 ;
V_2 -> V_440 [ V_442 ] . V_438 = true ;
V_2 -> V_440 [ V_615 ] . V_438 = true ;
memcpy ( V_196 -> V_390 , V_4 -> V_257 , V_321 ) ;
if ( V_11 != 0 ) {
V_196 -> V_390 [ 0 ] = ( V_196 -> V_390 [ 0 ] ^ ( 1 << V_11 ) ) |
0x2 ;
if ( F_14 ( V_616 ,
V_4 -> V_97 ) )
V_196 -> V_390 [ 4 ] ^= 0x80 ;
}
F_234 ( V_196 ) ;
F_235 ( V_2 ) ;
if ( F_218 ( V_2 ) )
goto V_95;
F_236 ( V_196 , & V_617 ) ;
if ( F_237 ( V_196 ) )
goto V_95;
V_4 -> V_91 &= ~ F_24 ( V_11 ) ;
V_2 -> V_108 = V_213 ;
F_50 ( V_62 , & V_2 -> V_6 ) ;
V_4 -> V_618 = V_619 ;
if ( type == V_81 )
V_4 -> V_88 = true ;
F_103 ( & V_4 -> V_303 ) ;
F_200 ( & V_2 -> V_304 , & V_4 -> V_620 ) ;
F_105 ( & V_4 -> V_303 ) ;
return & V_2 -> V_155 ;
V_95:
F_223 ( V_2 -> V_557 ) ;
F_238 ( V_196 ) ;
return NULL ;
}
int F_239 ( struct V_3 * V_4 )
{
struct V_13 * V_13 = V_4 -> V_13 ;
bool V_621 = false , V_622 = false , V_623 = false ;
int V_70 ;
V_13 -> V_624 = V_625 ;
V_13 -> V_626 = 5000 ;
F_240 ( V_13 , V_4 -> V_99 ) ;
V_13 -> V_627 = F_24 ( V_78 ) |
F_24 ( V_81 ) |
F_24 ( V_83 ) ;
if ( V_4 -> V_104 ) {
V_13 -> V_627 |= F_24 ( V_84 ) |
F_24 ( V_79 ) ;
}
if ( F_241 ( V_628 ) &&
F_14 ( V_629 , V_4 -> V_97 ) ) {
V_13 -> V_630 = F_216 ;
V_4 -> V_13 -> V_631 |= V_632 ;
}
V_13 -> V_633 = V_226 ;
if ( F_14 ( V_634 ,
V_4 -> V_97 ) )
V_13 -> V_635 = V_226 ;
V_13 -> V_636 = 1000 ;
switch ( V_4 -> V_529 . V_637 ) {
case V_638 :
V_623 = true ;
case V_639 :
V_622 = true ;
break;
case V_640 :
V_623 = true ;
case V_641 :
V_621 = true ;
break;
case V_642 :
V_623 = true ;
case V_643 :
V_621 = true ;
V_622 = true ;
break;
default:
F_9 ( L_107 ) ;
return - V_117 ;
}
if ( ! ( V_623 &&
F_14 ( V_485 ,
V_4 -> V_97 ) ) ) {
V_249 . V_250 . V_637 = 0 ;
V_249 . V_250 . V_251 = false ;
V_644 . V_250 . V_637 = 0 ;
V_644 . V_250 . V_251 = false ;
if ( V_623 )
F_9 ( L_108 ) ;
}
if ( F_14 ( V_645 ,
V_4 -> V_97 ) ) {
V_249 . V_250 . V_313 . V_646 [ 0 ] = 0xff ;
V_644 . V_250 . V_313 . V_646 [ 0 ] = 0xff ;
V_249 . V_250 . V_313 . V_646 [ 1 ] = 0xff ;
V_644 . V_250 . V_313 . V_646 [ 1 ] = 0xff ;
V_4 -> V_529 . V_527 = 0x3 ;
V_4 -> V_529 . V_528 = 0x3 ;
} else {
V_249 . V_250 . V_313 . V_646 [ 0 ] = 0xff ;
V_644 . V_250 . V_313 . V_646 [ 0 ] = 0xff ;
V_4 -> V_529 . V_527 = 1 ;
V_4 -> V_529 . V_528 = 1 ;
}
V_13 -> V_647 = V_4 -> V_529 . V_527 ;
V_13 -> V_648 = V_4 -> V_529 . V_528 ;
if ( V_621 )
V_13 -> V_448 [ V_442 ] = & V_249 ;
if ( V_622 )
V_13 -> V_448 [ V_615 ] = & V_644 ;
V_13 -> V_649 = V_650 ;
V_13 -> V_651 = V_651 ;
V_13 -> V_652 = F_114 ( V_651 ) ;
#ifdef F_242
V_13 -> V_653 = & V_654 ;
#endif
V_13 -> V_655 = V_226 ;
V_4 -> V_13 -> V_6 |= V_656 |
V_657 |
V_658 |
V_659 ;
if ( F_14 ( V_660 , V_4 -> V_97 ) )
V_4 -> V_13 -> V_661 = 1 ;
if ( F_14 ( V_662 ,
V_4 -> V_97 ) )
V_4 -> V_13 -> V_631 |= V_663 ;
V_4 -> V_13 -> V_664 =
V_665 |
V_666 |
V_667 ;
V_70 = F_243 ( V_13 ) ;
if ( V_70 < 0 ) {
F_9 ( L_109 ) ;
return V_70 ;
}
V_4 -> V_668 = true ;
return 0 ;
}
void F_244 ( struct V_3 * V_4 )
{
F_245 ( V_4 -> V_13 ) ;
V_4 -> V_668 = false ;
}
struct V_3 * F_246 ( void )
{
struct V_3 * V_4 ;
struct V_13 * V_13 ;
V_13 = F_247 ( & V_669 , sizeof( struct V_3 ) ) ;
if ( ! V_13 ) {
F_9 ( L_110 ) ;
return NULL ;
}
V_4 = F_89 ( V_13 ) ;
V_4 -> V_13 = V_13 ;
return V_4 ;
}
void F_248 ( struct V_3 * V_4 )
{
int V_87 ;
for ( V_87 = 0 ; V_87 < V_670 ; V_87 ++ )
F_21 ( V_4 -> V_671 [ V_87 ] . V_672 ) ;
F_249 ( V_4 -> V_13 ) ;
}
