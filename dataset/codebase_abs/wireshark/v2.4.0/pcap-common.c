int
F_1 ( int V_1 )
{
unsigned int V_2 ;
for ( V_2 = 0 ; V_2 < V_3 ; V_2 ++ ) {
if ( V_4 [ V_2 ] . V_5 == V_1 )
return V_4 [ V_2 ] . V_6 ;
}
return V_7 ;
}
int
F_2 ( int V_1 )
{
unsigned int V_2 ;
switch ( V_1 ) {
case V_8 :
case V_9 :
return 10 ;
case V_10 :
return 10 ;
case V_11 :
return 107 ;
case V_12 :
return 105 ;
}
for ( V_2 = 0 ; V_2 < V_3 ; V_2 ++ ) {
if ( V_4 [ V_2 ] . V_6 == V_1 )
return V_4 [ V_2 ] . V_5 ;
}
return - 1 ;
}
T_1
F_3 ( int V_13 )
{
if ( V_13 == V_14 )
return V_15 ;
else
return V_16 ;
}
T_2
F_4 ( int V_13 )
{
switch ( V_13 ) {
case V_17 :
case V_18 :
case V_19 :
case V_20 :
case V_21 :
case V_22 :
case V_23 :
case V_24 :
case V_25 :
case V_26 :
case V_27 :
return TRUE ;
}
return FALSE ;
}
static T_2
F_5 ( T_3 V_28 ,
union V_29 * V_30 , int * V_31 , T_4 * * V_32 )
{
T_5 V_33 [ V_34 ] ;
T_5 V_35 ;
T_6 V_36 ;
if ( ! F_6 ( V_28 , V_33 , V_34 , V_31 , V_32 ) )
return FALSE ;
V_35 = V_33 [ V_37 ] ;
V_36 = F_7 ( & V_33 [ V_38 ] ) ;
switch ( V_33 [ V_39 ] & 0x0F ) {
case 0x01 :
V_30 -> V_40 . V_41 = V_42 ;
V_30 -> V_40 . type = V_43 ;
break;
case 0x02 :
V_30 -> V_40 . V_41 = V_42 ;
V_30 -> V_40 . type = V_44 ;
break;
case 0x05 :
V_30 -> V_40 . V_41 = V_42 ;
V_30 -> V_40 . type = V_45 ;
break;
case 0x06 :
V_30 -> V_40 . V_41 = V_46 ;
V_30 -> V_40 . type = V_47 ;
break;
case 0x03 :
V_30 -> V_40 . V_41 = V_42 ;
V_30 -> V_40 . type = V_47 ;
break;
case 0x04 :
V_30 -> V_40 . V_41 = V_42 ;
V_30 -> V_40 . type = V_47 ;
break;
default:
if ( V_35 == 0 && V_36 == 5 )
V_30 -> V_40 . V_41 = V_46 ;
else
V_30 -> V_40 . V_41 = V_42 ;
V_30 -> V_40 . type = V_47 ;
break;
}
V_30 -> V_40 . V_48 = V_49 ;
V_30 -> V_40 . V_35 = V_35 ;
V_30 -> V_40 . V_36 = V_36 ;
V_30 -> V_40 . V_50 = ( V_33 [ V_39 ] & 0x80 ) ? 0 : 1 ;
V_30 -> V_40 . V_51 = 0 ;
V_30 -> V_40 . V_52 = 0 ;
V_30 -> V_40 . V_53 = 0 ;
V_30 -> V_40 . V_54 = 0 ;
V_30 -> V_40 . V_55 = 0 ;
return TRUE ;
}
static T_2
F_8 ( T_3 V_28 ,
union V_29 * V_30 , int * V_31 , T_4 * * V_32 )
{
T_5 V_33 [ V_56 ] ;
T_5 V_35 ;
T_6 V_36 ;
if ( ! F_6 ( V_28 , V_33 , V_56 , V_31 , V_32 ) )
return FALSE ;
V_35 = V_33 [ V_57 ] ;
V_36 = F_7 ( & V_33 [ V_58 ] ) ;
V_30 -> V_40 . V_35 = V_35 ;
V_30 -> V_40 . V_36 = V_36 ;
V_30 -> V_40 . V_50 = ( V_33 [ V_59 ] & 0x80 ) ? 0 : 1 ;
V_30 -> V_40 . V_51 = 0 ;
V_30 -> V_40 . V_52 = 0 ;
V_30 -> V_40 . V_53 = 0 ;
V_30 -> V_40 . V_54 = 0 ;
V_30 -> V_40 . V_55 = 0 ;
return TRUE ;
}
static T_2
F_9 ( T_3 V_28 ,
union V_29 * V_30 , int * V_31 , T_4 * * V_32 )
{
T_5 V_60 [ V_61 ] ;
if ( F_10 ( V_28 , - V_61 , V_62 , V_31 ) == - 1 )
{
* V_31 = F_11 ( V_28 , V_32 ) ;
if ( * V_31 == 0 )
* V_31 = V_63 ;
return FALSE ;
}
if ( ! F_6 ( V_28 , V_60 , V_61 , V_31 , V_32 ) )
return FALSE ;
memcpy ( V_30 -> V_64 . V_65 , V_60 , V_61 ) ;
return TRUE ;
}
static T_2
F_12 ( T_3 V_28 , union V_29 * V_30 ,
int * V_31 , T_4 * * V_32 )
{
T_5 V_66 [ V_67 ] ;
if ( ! F_6 ( V_28 , V_66 , V_67 , V_31 , V_32 ) )
return FALSE ;
if ( F_7 ( & V_66 [ V_68 ] ) != 0x0017 ) {
* V_31 = V_69 ;
if ( V_32 != NULL )
* V_32 = F_13 ( L_1 ) ;
return FALSE ;
}
V_30 -> V_70 . V_71 = F_7 ( & V_66 [ V_72 ] ) ;
return TRUE ;
}
static T_2
F_14 ( T_3 V_28 , union V_29 * V_30 , int * V_31 , T_4 * * V_32 )
{
T_5 V_73 [ V_74 ] ;
if ( ! F_6 ( V_28 , V_73 , V_74 , V_31 , V_32 ) )
return FALSE ;
V_30 -> V_75 . V_76 = V_73 [ V_77 ] ;
V_30 -> V_75 . V_78 = V_73 [ V_79 ] ;
V_30 -> V_75 . V_80 = F_7 ( & V_73 [ V_81 ] ) ;
return TRUE ;
}
static T_2
F_15 ( T_3 V_28 , union V_29 * V_30 ,
int * V_31 , T_4 * * V_32 )
{
T_5 V_82 [ V_83 ] ;
if ( ! F_6 ( V_28 , V_82 , V_83 , V_31 , V_32 ) )
return FALSE ;
if ( F_7 ( & V_82 [ V_84 ] ) != V_85 ) {
* V_31 = V_69 ;
if ( V_32 != NULL )
* V_32 = F_13 ( L_2 ) ;
return FALSE ;
}
V_30 -> V_86 . V_71 = F_7 ( & V_82 [ V_87 ] ) ;
V_30 -> V_86 . V_88 = ! ! V_82 [ V_89 + 0 ] ;
return TRUE ;
}
static T_2
F_16 ( T_3 V_28 , union V_29 * V_30 , int * V_31 , T_4 * * V_32 )
{
T_5 V_90 [ V_91 ] ;
if ( ! F_6 ( V_28 , V_90 , V_91 , V_31 , V_32 ) )
return FALSE ;
V_30 -> V_92 . V_93 = V_90 [ V_94 ] ;
V_30 -> V_92 . V_95 = V_90 [ V_96 ] ;
V_30 -> V_92 . V_97 = V_90 [ V_98 ] ;
V_30 -> V_92 . V_99 = V_90 [ V_100 ] ;
V_30 -> V_92 . V_101 = V_90 [ V_102 ] ;
return TRUE ;
}
static void
F_17 ( struct V_103 * V_60 , T_5 * V_104 )
{
T_1 V_105 ;
T_6 V_106 ;
struct V_107 * V_108 ;
V_105 = V_60 -> V_109 ;
if ( V_105 > V_60 -> V_110 )
V_105 = V_60 -> V_110 ;
if ( V_105 < V_111 ) {
return;
}
V_106 = F_7 ( & V_104 [ V_112 ] ) ;
if ( V_106 != V_113 && V_106 != V_114 ) {
return;
}
V_108 = (struct V_107 * ) ( void * ) ( V_104 + V_111 ) ;
if ( V_105 < V_111 + sizeof( V_108 -> V_115 ) ) {
return;
}
F_18 ( ( T_5 * ) & V_108 -> V_115 ) ;
}
static void
F_19 ( struct V_103 * V_60 , T_5 * V_104 ,
T_2 V_116 )
{
T_1 V_105 ;
struct V_117 * V_118 ;
struct V_119 * V_120 ;
T_7 V_121 , V_2 ;
V_105 = V_60 -> V_109 ;
if ( V_105 > V_60 -> V_110 )
V_105 = V_60 -> V_110 ;
V_118 = (struct V_117 * ) ( void * ) V_104 ;
F_20 ( & V_118 -> V_122 ) ;
F_21 ( & V_118 -> V_123 ) ;
F_20 ( & V_118 -> V_124 ) ;
F_22 ( & V_118 -> V_125 ) ;
F_22 ( & V_118 -> V_126 ) ;
F_22 ( & V_118 -> V_127 ) ;
F_22 ( & V_118 -> V_128 ) ;
if ( V_118 -> V_129 == V_130 ) {
F_22 ( & V_118 -> V_131 . V_132 . V_133 ) ;
F_22 ( & V_118 -> V_131 . V_132 . V_134 ) ;
}
if ( V_116 ) {
F_22 ( & V_118 -> V_135 ) ;
F_22 ( & V_118 -> V_136 ) ;
F_22 ( & V_118 -> V_137 ) ;
F_22 ( & V_118 -> V_138 ) ;
}
if ( V_118 -> V_129 == V_130 ) {
if ( V_116 ) {
V_120 = (struct V_119 * ) ( void * ) ( V_104 + 64 ) ;
} else {
V_120 = (struct V_119 * ) ( void * ) ( V_104 + 48 ) ;
}
V_121 = V_118 -> V_131 . V_132 . V_134 ;
for ( V_2 = 0 ; V_2 < V_121 ; V_2 ++ ) {
F_22 ( & V_120 -> V_139 ) ;
F_22 ( & V_120 -> V_140 ) ;
F_22 ( & V_120 -> V_141 ) ;
F_22 ( & V_120 -> V_142 ) ;
V_120 ++ ;
}
}
}
static void
F_23 ( struct V_103 * V_60 , T_5 * V_104 )
{
T_1 V_105 ;
T_5 * V_143 ;
struct V_144 * V_145 ;
struct V_146 * V_147 ;
T_1 V_148 ;
V_105 = V_60 -> V_109 ;
if ( V_105 > V_60 -> V_110 )
V_105 = V_60 -> V_110 ;
if ( V_105 < sizeof( struct V_144 ) ) {
return;
}
V_143 = V_104 ;
V_145 = (struct V_144 * ) V_104 ;
if ( V_145 -> V_149 != 0 ) {
return;
}
V_105 -= ( T_1 ) sizeof( struct V_144 ) ;
V_143 += sizeof( struct V_144 ) ;
while ( V_105 >= sizeof( struct V_146 ) ) {
V_147 = (struct V_146 * ) V_143 ;
F_24 ( ( T_5 * ) & V_147 -> V_150 ) ;
F_24 ( ( T_5 * ) & V_147 -> V_151 ) ;
V_148 = V_147 -> V_151 ;
if ( V_148 % 4 != 0 )
V_148 += 4 - V_148 % 4 ;
if ( V_148 < sizeof( struct V_146 ) ) {
return;
}
if ( V_105 < V_148 ) {
return;
}
V_105 -= V_148 ;
V_143 += V_148 ;
}
}
static T_2
F_25 ( T_3 V_28 ,
union V_29 * V_30 , int * V_31 , T_4 * * V_32 )
{
struct V_152 V_60 ;
if ( ! F_6 ( V_28 , & V_60 , sizeof ( struct V_152 ) ,
V_31 , V_32 ) )
return FALSE ;
V_30 -> V_153 . V_76 = ( ( F_26 ( V_60 . V_154 ) & V_155 ) == 0 ) ? TRUE : FALSE ;
return TRUE ;
}
static T_2
F_27 ( T_3 V_28 ,
union V_29 * V_30 , int * V_31 , T_4 * * V_32 )
{
struct V_156 V_60 ;
if ( ! F_6 ( V_28 , & V_60 , sizeof ( struct V_156 ) ,
V_31 , V_32 ) )
return FALSE ;
V_30 -> V_157 . V_158 = F_28 ( V_60 . V_158 ) ;
V_30 -> V_157 . V_159 = F_28 ( V_60 . V_159 ) ;
return TRUE ;
}
static T_2
F_29 ( T_3 V_28 ,
union V_29 * V_30 , int * V_31 , T_4 * * V_32 )
{
T_5 V_60 [ V_160 ] ;
if ( ! F_6 ( V_28 , V_60 , V_160 , V_31 , V_32 ) )
return FALSE ;
V_30 -> V_161 . V_162 = V_60 [ V_163 ] ;
V_30 -> V_161 . V_51 = V_60 [ V_164 ] ;
return TRUE ;
}
static T_2
F_30 ( T_3 V_28 ,
union V_29 * V_30 , int * V_31 , T_4 * * V_32 )
{
struct V_165 V_60 ;
if ( ! F_6 ( V_28 , & V_60 , sizeof ( struct V_165 ) ,
V_31 , V_32 ) )
return FALSE ;
V_30 -> V_153 . V_76 = ( V_60 . V_154 == V_166 ) ? TRUE : FALSE ;
return TRUE ;
}
static T_2
F_31 ( T_3 V_28 , struct V_103 * V_167 ,
union V_29 * V_30 , int * V_31 , T_4 * * V_32 )
{
T_5 V_168 [ sizeof( struct V_169 ) ] ;
if ( ! F_6 ( V_28 , V_168 , sizeof( struct V_169 ) , V_31 , V_32 ) )
return FALSE ;
V_30 -> erf . V_60 . V_170 = F_32 ( & V_168 [ 0 ] ) ;
V_30 -> erf . V_60 . type = V_168 [ 8 ] ;
V_30 -> erf . V_60 . V_51 = V_168 [ 9 ] ;
V_30 -> erf . V_60 . V_171 = F_7 ( & V_168 [ 10 ] ) ;
V_30 -> erf . V_60 . V_172 = F_7 ( & V_168 [ 12 ] ) ;
V_30 -> erf . V_60 . V_173 = F_7 ( & V_168 [ 14 ] ) ;
if ( V_167 ) {
T_8 V_170 = V_30 -> erf . V_60 . V_170 ;
V_167 -> V_170 . V_174 = ( V_175 ) ( V_170 >> 32 ) ;
V_170 = ( ( V_170 & 0xffffffff ) * 1000 * 1000 * 1000 ) ;
V_170 += ( V_170 & 0x80000000 ) << 1 ;
V_167 -> V_170 . V_176 = ( ( V_175 ) ( V_170 >> 32 ) ) ;
if ( V_167 -> V_170 . V_176 >= 1000000000 ) {
V_167 -> V_170 . V_176 -= 1000000000 ;
V_167 -> V_170 . V_174 += 1 ;
}
}
return TRUE ;
}
static T_2
F_33 ( T_3 V_28 , union V_29 * V_30 ,
int * V_31 , T_4 * * V_32 , T_1 * V_177 )
{
T_5 V_178 [ 8 ] ;
T_8 V_179 ;
int V_2 = 0 , V_180 = sizeof( V_30 -> erf . V_181 ) / sizeof( struct V_182 ) ;
T_5 type ;
* V_177 = 0 ;
if ( V_30 -> erf . V_60 . type & 0x80 ) {
do{
if ( ! F_6 ( V_28 , V_178 , 8 , V_31 , V_32 ) )
return FALSE ;
type = V_178 [ 0 ] ;
V_179 = F_34 ( V_178 ) ;
if ( V_2 < V_180 )
memcpy ( & V_30 -> erf . V_181 [ V_2 ] . V_183 , & V_179 , sizeof( V_179 ) ) ;
* V_177 += 8 ;
V_2 ++ ;
} while ( type & 0x80 );
}
return TRUE ;
}
static T_2
F_35 ( T_3 V_28 , union V_29 * V_30 ,
int * V_31 , T_4 * * V_32 , T_1 * V_177 )
{
T_5 V_184 [ sizeof( union V_184 ) ] ;
* V_177 = 0 ;
switch( V_30 -> erf . V_60 . type & 0x7F ) {
case V_185 :
case V_186 :
case V_187 :
case V_188 :
case V_189 :
case V_190 :
case V_191 :
if ( ! F_6 ( V_28 , V_184 , sizeof( V_192 ) , V_31 , V_32 ) )
return FALSE ;
V_30 -> erf . V_193 . V_194 = F_36 ( & V_184 [ 0 ] ) ;
* V_177 = sizeof( V_192 ) ;
break;
case V_195 :
if ( ! F_6 ( V_28 , V_184 , sizeof( V_196 ) , V_31 , V_32 ) )
return FALSE ;
V_30 -> erf . V_193 . V_197 = F_36 ( & V_184 [ 0 ] ) ;
* V_177 = sizeof( V_196 ) ;
break;
case V_198 :
case V_199 :
case V_200 :
case V_201 :
if ( ! F_6 ( V_28 , V_184 , sizeof( V_202 ) , V_31 , V_32 ) )
return FALSE ;
memcpy ( & V_30 -> erf . V_193 . V_203 , V_184 , sizeof V_30 -> erf . V_193 . V_203 ) ;
* V_177 = sizeof( V_202 ) ;
break;
default:
break;
}
return TRUE ;
}
static T_2
F_37 ( T_3 V_28 , union V_29 * V_30 , int * V_31 , T_4 * * V_32 )
{
struct V_204 V_205 ;
if ( ! F_6 ( V_28 , & V_205 , sizeof ( V_205 ) , V_31 , V_32 ) )
return FALSE ;
V_30 -> V_206 . V_207 = V_205 . V_208 & 0x80 ? 1 : 0 ;
V_30 -> V_206 . V_208 = V_205 . V_208 & 0x7f ;
V_30 -> V_206 . V_51 = F_36 ( & V_205 . V_51 ) ;
return TRUE ;
}
int
F_38 ( T_3 V_28 , int V_209 , int V_13 ,
T_1 V_105 , T_2 V_210 ,
struct V_103 * V_60 , int * V_31 , T_4 * * V_32 )
{
int V_211 = 0 ;
T_1 V_148 ;
switch ( V_13 ) {
case V_17 :
if ( V_209 == V_212 ) {
if ( V_210 && V_105 < V_56 ) {
* V_31 = V_69 ;
* V_32 = F_39 ( L_3 ,
V_105 ) ;
return - 1 ;
}
if ( ! F_8 ( V_28 ,
& V_60 -> V_30 , V_31 , V_32 ) )
return - 1 ;
V_211 = V_56 ;
} else {
if ( V_210 && V_105 < V_34 ) {
* V_31 = V_69 ;
* V_32 = F_39 ( L_4 ,
V_105 ) ;
return - 1 ;
}
if ( ! F_5 ( V_28 ,
& V_60 -> V_30 , V_31 , V_32 ) )
return - 1 ;
V_211 = V_34 ;
}
break;
case V_213 :
if ( V_209 == V_212 ) {
if ( ! F_9 ( V_28 , & V_60 -> V_30 , V_31 , V_32 ) )
return - 1 ;
}
V_60 -> V_30 . V_214 . V_215 = - 1 ;
break;
case V_216 :
case V_217 :
case V_218 :
case V_219 :
memset ( & V_60 -> V_30 . V_220 , 0 , sizeof( V_60 -> V_30 . V_220 ) ) ;
V_60 -> V_30 . V_220 . V_215 = - 1 ;
V_60 -> V_30 . V_220 . V_221 = FALSE ;
V_60 -> V_30 . V_220 . V_222 = FALSE ;
break;
case V_18 :
if ( V_210 && V_105 < V_67 ) {
* V_31 = V_69 ;
* V_32 = F_39 ( L_5 ,
V_105 ) ;
return - 1 ;
}
if ( ! F_12 ( V_28 , & V_60 -> V_30 ,
V_31 , V_32 ) )
return - 1 ;
V_211 = V_67 ;
break;
case V_19 :
if ( V_210 && V_105 < V_74 ) {
* V_31 = V_69 ;
* V_32 = F_39 ( L_6 ,
V_105 ) ;
return - 1 ;
}
if ( ! F_14 ( V_28 , & V_60 -> V_30 ,
V_31 , V_32 ) )
return - 1 ;
V_211 = V_74 ;
break;
case V_20 :
if ( V_210 && V_105 < V_83 ) {
* V_31 = V_69 ;
* V_32 = F_39 ( L_7 ,
V_105 ) ;
return - 1 ;
}
if ( ! F_15 ( V_28 , & V_60 -> V_30 ,
V_31 , V_32 ) )
return - 1 ;
V_211 = V_83 ;
break;
case V_21 :
if ( V_210 && V_105 < V_91 ) {
* V_31 = V_69 ;
* V_32 = F_39 ( L_8 ,
V_105 ) ;
return - 1 ;
}
if ( ! F_16 ( V_28 , & V_60 -> V_30 ,
V_31 , V_32 ) )
return - 1 ;
V_211 = V_91 ;
break;
case V_223 :
V_60 -> V_30 . V_153 . V_76 = FALSE ;
break;
case V_22 :
if ( V_210 &&
V_105 < sizeof ( struct V_152 ) ) {
* V_31 = V_69 ;
* V_32 = F_39 ( L_9 ,
V_105 ) ;
return - 1 ;
}
if ( ! F_25 ( V_28 ,
& V_60 -> V_30 , V_31 , V_32 ) )
return - 1 ;
V_211 = ( int ) sizeof ( struct V_152 ) ;
break;
case V_23 :
if ( V_210 &&
V_105 < sizeof ( struct V_156 ) ) {
* V_31 = V_69 ;
* V_32 = F_39 ( L_10 ,
V_105 ) ;
return - 1 ;
}
if ( ! F_27 ( V_28 ,
& V_60 -> V_30 , V_31 , V_32 ) )
return - 1 ;
V_211 = ( int ) sizeof ( struct V_156 ) ;
break;
case V_24 :
if ( V_210 && V_105 < V_160 ) {
* V_31 = V_69 ;
* V_32 = F_13 ( L_11 ) ;
return - 1 ;
}
if ( ! F_29 ( V_28 , & V_60 -> V_30 , V_31 , V_32 ) )
return - 1 ;
V_211 = V_160 ;
break;
case V_25 :
if ( V_210 &&
V_105 < sizeof ( struct V_165 ) ) {
* V_31 = V_69 ;
* V_32 = F_39 ( L_12 ,
V_105 ) ;
return - 1 ;
}
if ( ! F_30 ( V_28 ,
& V_60 -> V_30 , V_31 , V_32 ) )
return - 1 ;
V_211 = ( int ) sizeof ( struct V_165 ) ;
break;
case V_26 :
if ( V_210 &&
V_105 < sizeof( struct V_169 ) ) {
* V_31 = V_69 ;
* V_32 = F_39 ( L_13 ,
V_105 ) ;
return - 1 ;
}
if ( ! F_31 ( V_28 , V_60 , & V_60 -> V_30 ,
V_31 , V_32 ) )
return - 1 ;
V_211 = ( int ) sizeof( struct V_169 ) ;
if ( ! F_33 ( V_28 , & V_60 -> V_30 , V_31 , V_32 ,
& V_148 ) )
return - 1 ;
V_211 += V_148 ;
if ( ! F_35 ( V_28 , & V_60 -> V_30 , V_31 , V_32 ,
& V_148 ) )
return - 1 ;
V_211 += V_148 ;
if ( V_210 &&
V_105 < ( T_1 ) V_211 ) {
* V_31 = V_69 ;
* V_32 = F_39 ( L_14 ,
V_105 , V_211 ) ;
return - 1 ;
}
break;
case V_27 :
if ( V_210 &&
V_105 < sizeof ( struct V_204 ) ) {
* V_31 = V_69 ;
* V_32 = F_39 ( L_15 ,
V_105 ) ;
return - 1 ;
}
if ( ! F_37 ( V_28 , & V_60 -> V_30 ,
V_31 , V_32 ) )
return - 1 ;
V_211 = ( int ) sizeof ( struct V_204 ) ;
break;
}
return V_211 ;
}
void
F_40 ( int V_209 , int V_13 ,
struct V_103 * V_60 , T_5 * V_104 , T_2 V_224 , int V_215 )
{
switch ( V_13 ) {
case V_17 :
if ( V_209 == V_212 ) {
F_41 ( V_60 , V_104 ) ;
} else {
if ( V_60 -> V_30 . V_40 . type == V_43 )
F_42 ( V_60 , V_104 ) ;
}
break;
case V_213 :
V_60 -> V_30 . V_214 . V_215 = V_215 ;
break;
case V_225 :
if ( V_224 )
F_17 ( V_60 , V_104 ) ;
break;
case V_226 :
if ( V_224 )
F_19 ( V_60 , V_104 , FALSE ) ;
break;
case V_227 :
if ( V_224 )
F_19 ( V_60 , V_104 , TRUE ) ;
break;
case V_228 :
V_60 -> V_30 . V_214 . V_215 = 4 ;
break;
case V_229 :
if ( V_224 )
F_23 ( V_60 , V_104 ) ;
break;
case V_26 :
V_60 -> V_110 = V_60 -> V_30 . erf . V_60 . V_173 ;
V_60 -> V_109 = F_43 ( V_60 -> V_110 , V_60 -> V_109 ) ;
break;
default:
break;
}
}
int
F_44 ( int V_1 , const union V_29 * V_30 )
{
int V_230 ;
switch ( V_1 ) {
case V_17 :
V_230 = V_34 ;
break;
case V_18 :
V_230 = V_67 ;
break;
case V_19 :
V_230 = V_74 ;
break;
case V_20 :
V_230 = V_83 ;
break;
case V_21 :
V_230 = V_91 ;
break;
case V_26 :
V_230 = ( int ) sizeof ( struct V_169 ) ;
switch ( V_30 -> erf . V_60 . type & 0x7F ) {
case V_185 :
case V_186 :
case V_187 :
case V_188 :
case V_189 :
case V_190 :
case V_191 :
V_230 += ( int ) sizeof( struct V_231 ) ;
break;
case V_195 :
V_230 += ( int ) sizeof( struct V_232 ) ;
break;
case V_198 :
case V_199 :
case V_200 :
case V_201 :
V_230 += ( int ) sizeof( struct V_233 ) ;
break;
default:
break;
}
if ( V_30 -> erf . V_60 . type & 0x80 ) {
int V_2 = 0 , V_180 = sizeof( V_30 -> erf . V_181 ) / sizeof( struct V_182 ) ;
T_5 V_178 [ 8 ] ;
T_5 type ;
do {
F_45 ( V_178 , V_30 -> erf . V_181 [ V_2 ] . V_183 ) ;
type = V_178 [ 0 ] ;
V_230 += 8 ;
V_2 ++ ;
} while ( type & 0x80 && V_2 < V_180 );
}
break;
case V_27 :
V_230 = ( int ) sizeof ( struct V_204 ) ;
break;
case V_22 :
V_230 = ( int ) sizeof ( struct V_152 ) ;
break;
case V_25 :
V_230 = ( int ) sizeof ( struct V_165 ) ;
break;
case V_23 :
V_230 = ( int ) sizeof ( struct V_156 ) ;
break;
default:
V_230 = 0 ;
break;
}
return V_230 ;
}
T_2
F_46 ( T_9 * V_234 , int V_1 , const union V_29 * V_30 ,
int * V_31 )
{
T_5 V_235 [ V_34 ] ;
T_5 V_236 [ V_67 ] ;
T_5 V_237 [ V_83 ] ;
T_5 V_73 [ V_74 ] ;
T_5 V_238 [ V_91 ] ;
T_5 V_168 [ sizeof( struct V_239 ) ] ;
T_5 V_184 [ sizeof( union V_184 ) ] ;
struct V_204 V_205 ;
struct V_152 V_240 ;
struct V_156 V_241 ;
struct V_165 V_242 ;
T_10 V_148 ;
T_10 V_243 = 0 ;
switch ( V_1 ) {
case V_17 :
V_235 [ V_39 ] =
( V_30 -> V_40 . V_50 == 0 ) ? 0x80 : 0x00 ;
switch ( V_30 -> V_40 . V_41 ) {
case V_46 :
V_235 [ V_39 ] |= 0x06 ;
break;
case V_42 :
switch ( V_30 -> V_40 . type ) {
case V_43 :
V_235 [ V_39 ] |= 0x01 ;
break;
case V_44 :
V_235 [ V_39 ] |= 0x02 ;
break;
case V_45 :
V_235 [ V_39 ] |= 0x05 ;
break;
}
break;
}
V_235 [ V_37 ] = ( T_5 ) V_30 -> V_40 . V_35 ;
F_47 ( & V_235 [ V_38 ] , V_30 -> V_40 . V_36 ) ;
if ( ! F_48 ( V_234 , V_235 , sizeof( V_235 ) , V_31 ) )
return FALSE ;
V_234 -> V_244 += sizeof( V_235 ) ;
break;
case V_18 :
memset ( V_236 , 0 , sizeof( V_236 ) ) ;
F_47 ( & V_236 [ V_72 ] ,
V_30 -> V_70 . V_71 ) ;
F_47 ( & V_236 [ V_68 ] , 0x0017 ) ;
if ( ! F_48 ( V_234 , V_236 , sizeof( V_236 ) , V_31 ) )
return FALSE ;
V_234 -> V_244 += sizeof( V_236 ) ;
break;
case V_19 :
memset ( & V_73 , 0 , sizeof( V_73 ) ) ;
V_73 [ V_77 ] = V_30 -> V_75 . V_76 ;
V_73 [ V_79 ] = V_30 -> V_75 . V_78 ;
F_47 ( & V_73 [ V_81 ] ,
V_30 -> V_75 . V_80 ) ;
if ( ! F_48 ( V_234 , V_73 , sizeof( V_73 ) , V_31 ) )
return FALSE ;
V_234 -> V_244 += sizeof( V_73 ) ;
break;
case V_20 :
memset ( & V_237 , 0 , sizeof( V_237 ) ) ;
F_47 ( & V_237 [ V_87 ] ,
V_30 -> V_86 . V_71 ) ;
F_47 ( & V_237 [ V_84 ] , V_85 ) ;
V_237 [ V_89 + 0 ] =
V_30 -> V_86 . V_88 ? 0x01 : 0x00 ;
if ( ! F_48 ( V_234 , V_237 , sizeof( V_237 ) , V_31 ) )
return FALSE ;
V_234 -> V_244 += sizeof( V_237 ) ;
break;
case V_21 :
memset ( & V_238 , 0 , sizeof( V_238 ) ) ;
V_238 [ V_94 ] = V_30 -> V_92 . V_93 ;
V_238 [ V_96 ] = V_30 -> V_92 . V_95 ;
V_238 [ V_98 ] = V_30 -> V_92 . V_97 ;
V_238 [ V_100 ] = V_30 -> V_92 . V_99 ;
V_238 [ V_102 ] = V_30 -> V_92 . V_101 ;
if ( ! F_48 ( V_234 , V_238 , sizeof( V_238 ) , V_31 ) )
return FALSE ;
V_234 -> V_244 += sizeof( V_238 ) ;
break;
case V_26 :
memset ( & V_168 , 0 , sizeof( V_168 ) ) ;
F_49 ( & V_168 [ 0 ] , V_30 -> erf . V_60 . V_170 ) ;
V_168 [ 8 ] = V_30 -> erf . V_60 . type ;
V_168 [ 9 ] = V_30 -> erf . V_60 . V_51 ;
F_47 ( & V_168 [ 10 ] ,
F_43 ( V_30 -> erf . V_60 . V_171 , V_30 -> erf . V_60 . V_173 + F_44 ( V_26 , V_30 ) ) ) ;
F_47 ( & V_168 [ 12 ] , V_30 -> erf . V_60 . V_172 ) ;
F_47 ( & V_168 [ 14 ] , V_30 -> erf . V_60 . V_173 ) ;
V_148 = sizeof( struct V_169 ) ;
switch( V_30 -> erf . V_60 . type & 0x7F ) {
case V_185 :
case V_186 :
case V_187 :
case V_188 :
case V_189 :
case V_190 :
case V_191 :
F_50 ( & V_184 [ 0 ] , V_30 -> erf . V_193 . V_194 ) ;
V_243 += ( int ) sizeof( struct V_231 ) ;
break;
case V_195 :
F_50 ( & V_184 [ 0 ] , V_30 -> erf . V_193 . V_197 ) ;
V_243 += ( int ) sizeof( struct V_232 ) ;
break;
case V_198 :
case V_199 :
case V_200 :
case V_201 :
memcpy ( & V_184 [ 0 ] , & V_30 -> erf . V_193 . V_203 , sizeof V_30 -> erf . V_193 . V_203 ) ;
V_243 += ( int ) sizeof( struct V_233 ) ;
break;
default:
break;
}
if ( ! F_48 ( V_234 , V_168 , V_148 , V_31 ) )
return FALSE ;
V_234 -> V_244 += V_148 ;
if ( V_30 -> erf . V_60 . type & 0x80 ) {
int V_2 = 0 , V_180 = sizeof( V_30 -> erf . V_181 ) / sizeof( struct V_182 ) ;
T_5 V_178 [ 8 ] ;
T_5 type ;
do {
F_45 ( V_178 , V_30 -> erf . V_181 [ V_2 ] . V_183 ) ;
type = V_178 [ 0 ] ;
if( V_2 == V_180 - 1 )
V_178 [ 0 ] = V_178 [ 0 ] & 0x7F ;
if ( ! F_48 ( V_234 , V_178 , 8 , V_31 ) )
return FALSE ;
V_234 -> V_244 += 8 ;
V_2 ++ ;
} while ( type & 0x80 && V_2 < V_180 );
}
if( ! F_48 ( V_234 , V_184 , V_243 , V_31 ) )
return FALSE ;
V_234 -> V_244 += V_243 ;
break;
case V_27 :
memset ( & V_205 , 0 , sizeof( V_205 ) ) ;
V_205 . V_208 = V_30 -> V_206 . V_208 |
( V_30 -> V_206 . V_207 ? 0x80 : 0x00 ) ;
F_50 ( ( T_5 * ) & V_205 . V_51 , V_30 -> V_206 . V_51 ) ;
if ( ! F_48 ( V_234 , & V_205 , sizeof( V_205 ) , V_31 ) )
return FALSE ;
V_234 -> V_244 += sizeof( V_205 ) ;
break;
case V_22 :
V_240 . V_154 = F_51 ( V_30 -> V_153 . V_76 ? V_245 : V_155 ) ;
if ( ! F_48 ( V_234 , & V_240 , sizeof V_240 , V_31 ) )
return FALSE ;
V_234 -> V_244 += sizeof V_240 ;
break;
case V_23 :
V_241 . V_158 = F_52 ( V_30 -> V_157 . V_158 ) ;
V_241 . V_159 = F_52 ( V_30 -> V_157 . V_159 ) ;
if ( ! F_48 ( V_234 , & V_241 , sizeof V_241 , V_31 ) )
return FALSE ;
V_234 -> V_244 += sizeof V_241 ;
break;
case V_25 :
V_242 . V_154 = ( V_30 -> V_153 . V_76 ? V_166 : V_246 ) ;
if ( ! F_48 ( V_234 , & V_242 , sizeof V_242 , V_31 ) )
return FALSE ;
V_234 -> V_244 += sizeof V_242 ;
break;
}
return TRUE ;
}
