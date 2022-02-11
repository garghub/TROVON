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
switch ( V_13 ) {
case V_14 :
case V_15 :
case V_16 :
case V_17 :
case V_18 :
case V_19 :
case V_20 :
case V_21 :
case V_22 :
case V_23 :
case V_24 :
return TRUE ;
}
return FALSE ;
}
static T_1
F_4 ( T_2 V_25 ,
union V_26 * V_27 , int * V_28 , T_3 * * V_29 )
{
T_4 V_30 [ V_31 ] ;
T_4 V_32 ;
T_5 V_33 ;
if ( ! F_5 ( V_25 , V_30 , V_31 , V_28 , V_29 ) )
return FALSE ;
V_32 = V_30 [ V_34 ] ;
V_33 = F_6 ( & V_30 [ V_35 ] ) ;
switch ( V_30 [ V_36 ] & 0x0F ) {
case 0x01 :
V_27 -> V_37 . V_38 = V_39 ;
V_27 -> V_37 . type = V_40 ;
break;
case 0x02 :
V_27 -> V_37 . V_38 = V_39 ;
V_27 -> V_37 . type = V_41 ;
break;
case 0x05 :
V_27 -> V_37 . V_38 = V_39 ;
V_27 -> V_37 . type = V_42 ;
break;
case 0x06 :
V_27 -> V_37 . V_38 = V_43 ;
V_27 -> V_37 . type = V_44 ;
break;
case 0x03 :
V_27 -> V_37 . V_38 = V_39 ;
V_27 -> V_37 . type = V_44 ;
break;
case 0x04 :
V_27 -> V_37 . V_38 = V_39 ;
V_27 -> V_37 . type = V_44 ;
break;
default:
if ( V_32 == 0 && V_33 == 5 )
V_27 -> V_37 . V_38 = V_43 ;
else
V_27 -> V_37 . V_38 = V_39 ;
V_27 -> V_37 . type = V_44 ;
break;
}
V_27 -> V_37 . V_45 = V_46 ;
V_27 -> V_37 . V_32 = V_32 ;
V_27 -> V_37 . V_33 = V_33 ;
V_27 -> V_37 . V_47 = ( V_30 [ V_36 ] & 0x80 ) ? 0 : 1 ;
V_27 -> V_37 . V_48 = 0 ;
V_27 -> V_37 . V_49 = 0 ;
V_27 -> V_37 . V_50 = 0 ;
V_27 -> V_37 . V_51 = 0 ;
V_27 -> V_37 . V_52 = 0 ;
return TRUE ;
}
static T_1
F_7 ( T_2 V_25 ,
union V_26 * V_27 , int * V_28 , T_3 * * V_29 )
{
T_4 V_30 [ V_53 ] ;
T_4 V_32 ;
T_5 V_33 ;
if ( ! F_5 ( V_25 , V_30 , V_53 , V_28 , V_29 ) )
return FALSE ;
V_32 = V_30 [ V_54 ] ;
V_33 = F_6 ( & V_30 [ V_55 ] ) ;
V_27 -> V_37 . V_32 = V_32 ;
V_27 -> V_37 . V_33 = V_33 ;
V_27 -> V_37 . V_47 = ( V_30 [ V_56 ] & 0x80 ) ? 0 : 1 ;
V_27 -> V_37 . V_48 = 0 ;
V_27 -> V_37 . V_49 = 0 ;
V_27 -> V_37 . V_50 = 0 ;
V_27 -> V_37 . V_51 = 0 ;
V_27 -> V_37 . V_52 = 0 ;
return TRUE ;
}
static T_1
F_8 ( T_2 V_25 ,
union V_26 * V_27 , int * V_28 , T_3 * * V_29 )
{
T_4 V_57 [ V_58 ] ;
if ( F_9 ( V_25 , - V_58 , V_59 , V_28 ) == - 1 )
{
* V_28 = F_10 ( V_25 , V_29 ) ;
if ( * V_28 == 0 )
* V_28 = V_60 ;
return FALSE ;
}
if ( ! F_5 ( V_25 , V_57 , V_58 , V_28 , V_29 ) )
return FALSE ;
memcpy ( V_27 -> V_61 . V_62 , V_57 , V_58 ) ;
return TRUE ;
}
static T_1
F_11 ( T_2 V_25 , union V_26 * V_27 ,
int * V_28 , T_3 * * V_29 )
{
T_4 V_63 [ V_64 ] ;
if ( ! F_5 ( V_25 , V_63 , V_64 , V_28 , V_29 ) )
return FALSE ;
if ( F_6 ( & V_63 [ V_65 ] ) != 0x0017 ) {
* V_28 = V_66 ;
if ( V_29 != NULL )
* V_29 = F_12 ( L_1 ) ;
return FALSE ;
}
V_27 -> V_67 . V_68 = F_6 ( & V_63 [ V_69 ] ) ;
return TRUE ;
}
static T_1
F_13 ( T_2 V_25 , union V_26 * V_27 , int * V_28 , T_3 * * V_29 )
{
T_4 V_70 [ V_71 ] ;
if ( ! F_5 ( V_25 , V_70 , V_71 , V_28 , V_29 ) )
return FALSE ;
V_27 -> V_72 . V_73 = V_70 [ V_74 ] ;
V_27 -> V_72 . V_75 = V_70 [ V_76 ] ;
V_27 -> V_72 . V_77 = F_6 ( & V_70 [ V_78 ] ) ;
return TRUE ;
}
static T_1
F_14 ( T_2 V_25 , union V_26 * V_27 ,
int * V_28 , T_3 * * V_29 )
{
T_4 V_79 [ V_80 ] ;
if ( ! F_5 ( V_25 , V_79 , V_80 , V_28 , V_29 ) )
return FALSE ;
if ( F_6 ( & V_79 [ V_81 ] ) != V_82 ) {
* V_28 = V_66 ;
if ( V_29 != NULL )
* V_29 = F_12 ( L_2 ) ;
return FALSE ;
}
V_27 -> V_83 . V_68 = F_6 ( & V_79 [ V_84 ] ) ;
V_27 -> V_83 . V_85 = ! ! V_79 [ V_86 + 0 ] ;
return TRUE ;
}
static T_1
F_15 ( T_2 V_25 , union V_26 * V_27 , int * V_28 , T_3 * * V_29 )
{
T_4 V_87 [ V_88 ] ;
if ( ! F_5 ( V_25 , V_87 , V_88 , V_28 , V_29 ) )
return FALSE ;
V_27 -> V_89 . V_90 = V_87 [ V_91 ] ;
V_27 -> V_89 . V_92 = V_87 [ V_93 ] ;
V_27 -> V_89 . V_94 = V_87 [ V_95 ] ;
V_27 -> V_89 . V_96 = V_87 [ V_97 ] ;
V_27 -> V_89 . V_98 = V_87 [ V_99 ] ;
return TRUE ;
}
static void
F_16 ( struct V_100 * V_57 , T_4 * V_101 )
{
T_6 V_102 ;
T_5 V_103 ;
struct V_104 * V_105 ;
V_102 = V_57 -> V_106 ;
if ( V_102 > V_57 -> V_107 )
V_102 = V_57 -> V_107 ;
if ( V_102 < V_108 ) {
return;
}
V_103 = F_6 ( & V_101 [ V_109 ] ) ;
if ( V_103 != V_110 && V_103 != V_111 ) {
return;
}
V_105 = (struct V_104 * ) ( void * ) ( V_101 + V_108 ) ;
if ( V_102 < V_108 + sizeof( V_105 -> V_112 ) ) {
return;
}
F_17 ( ( T_4 * ) & V_105 -> V_112 ) ;
}
static void
F_18 ( struct V_100 * V_57 , T_4 * V_101 ,
T_1 V_113 )
{
T_6 V_102 ;
struct V_114 * V_115 ;
struct V_116 * V_117 ;
T_7 V_118 , V_2 ;
V_102 = V_57 -> V_106 ;
if ( V_102 > V_57 -> V_107 )
V_102 = V_57 -> V_107 ;
V_115 = (struct V_114 * ) ( void * ) V_101 ;
F_19 ( & V_115 -> V_119 ) ;
F_20 ( & V_115 -> V_120 ) ;
F_19 ( & V_115 -> V_121 ) ;
F_21 ( & V_115 -> V_122 ) ;
F_21 ( & V_115 -> V_123 ) ;
F_21 ( & V_115 -> V_124 ) ;
F_21 ( & V_115 -> V_125 ) ;
if ( V_115 -> V_126 == V_127 ) {
F_21 ( & V_115 -> V_128 . V_129 . V_130 ) ;
F_21 ( & V_115 -> V_128 . V_129 . V_131 ) ;
}
if ( V_113 ) {
F_21 ( & V_115 -> V_132 ) ;
F_21 ( & V_115 -> V_133 ) ;
F_21 ( & V_115 -> V_134 ) ;
F_21 ( & V_115 -> V_135 ) ;
}
if ( V_115 -> V_126 == V_127 ) {
if ( V_113 ) {
V_117 = (struct V_116 * ) ( void * ) ( V_101 + 64 ) ;
} else {
V_117 = (struct V_116 * ) ( void * ) ( V_101 + 48 ) ;
}
V_118 = V_115 -> V_128 . V_129 . V_131 ;
for ( V_2 = 0 ; V_2 < V_118 ; V_2 ++ ) {
F_21 ( & V_117 -> V_136 ) ;
F_21 ( & V_117 -> V_137 ) ;
F_21 ( & V_117 -> V_138 ) ;
F_21 ( & V_117 -> V_139 ) ;
V_117 ++ ;
}
}
}
static void
F_22 ( struct V_100 * V_57 , T_4 * V_101 )
{
T_6 V_102 ;
T_4 * V_140 ;
struct V_141 * V_142 ;
struct V_143 * V_144 ;
T_6 V_145 ;
V_102 = V_57 -> V_106 ;
if ( V_102 > V_57 -> V_107 )
V_102 = V_57 -> V_107 ;
if ( V_102 < sizeof( struct V_141 ) ) {
return;
}
V_140 = V_101 ;
V_142 = (struct V_141 * ) V_101 ;
if ( V_142 -> V_146 != 0 ) {
return;
}
V_102 -= ( T_6 ) sizeof( struct V_141 ) ;
V_140 += sizeof( struct V_141 ) ;
while ( V_102 >= sizeof( struct V_143 ) ) {
V_144 = (struct V_143 * ) V_140 ;
F_23 ( ( T_4 * ) & V_144 -> V_147 ) ;
F_23 ( ( T_4 * ) & V_144 -> V_148 ) ;
V_145 = V_144 -> V_148 ;
if ( V_145 % 4 != 0 )
V_145 += 4 - V_145 % 4 ;
if ( V_145 < sizeof( struct V_143 ) ) {
return;
}
if ( V_102 < V_145 ) {
return;
}
V_102 -= V_145 ;
V_140 += V_145 ;
}
}
static T_1
F_24 ( T_2 V_25 ,
union V_26 * V_27 , int * V_28 , T_3 * * V_29 )
{
struct V_149 V_57 ;
if ( ! F_5 ( V_25 , & V_57 , sizeof ( struct V_149 ) ,
V_28 , V_29 ) )
return FALSE ;
V_27 -> V_150 . V_73 = ( ( F_25 ( V_57 . V_151 ) & V_152 ) == 0 ) ? TRUE : FALSE ;
return TRUE ;
}
static T_1
F_26 ( T_2 V_25 ,
union V_26 * V_27 , int * V_28 , T_3 * * V_29 )
{
struct V_153 V_57 ;
if ( ! F_5 ( V_25 , & V_57 , sizeof ( struct V_153 ) ,
V_28 , V_29 ) )
return FALSE ;
V_27 -> V_154 . V_155 = F_27 ( V_57 . V_155 ) ;
V_27 -> V_154 . V_156 = F_27 ( V_57 . V_156 ) ;
return TRUE ;
}
static T_1
F_28 ( T_2 V_25 ,
union V_26 * V_27 , int * V_28 , T_3 * * V_29 )
{
T_4 V_57 [ V_157 ] ;
if ( ! F_5 ( V_25 , V_57 , V_157 , V_28 , V_29 ) )
return FALSE ;
V_27 -> V_158 . V_159 = V_57 [ V_160 ] ;
V_27 -> V_158 . V_48 = V_57 [ V_161 ] ;
return TRUE ;
}
static T_1
F_29 ( T_2 V_25 ,
union V_26 * V_27 , int * V_28 , T_3 * * V_29 )
{
struct V_162 V_57 ;
if ( ! F_5 ( V_25 , & V_57 , sizeof ( struct V_162 ) ,
V_28 , V_29 ) )
return FALSE ;
V_27 -> V_150 . V_73 = ( V_57 . V_151 == V_163 ) ? TRUE : FALSE ;
return TRUE ;
}
static T_1
F_30 ( T_2 V_25 , struct V_100 * V_164 ,
union V_26 * V_27 , int * V_28 , T_3 * * V_29 )
{
T_4 V_165 [ sizeof( struct V_166 ) ] ;
if ( ! F_5 ( V_25 , V_165 , sizeof( struct V_166 ) , V_28 , V_29 ) )
return FALSE ;
V_27 -> erf . V_57 . V_167 = F_31 ( & V_165 [ 0 ] ) ;
V_27 -> erf . V_57 . type = V_165 [ 8 ] ;
V_27 -> erf . V_57 . V_48 = V_165 [ 9 ] ;
V_27 -> erf . V_57 . V_168 = F_6 ( & V_165 [ 10 ] ) ;
V_27 -> erf . V_57 . V_169 = F_6 ( & V_165 [ 12 ] ) ;
V_27 -> erf . V_57 . V_170 = F_6 ( & V_165 [ 14 ] ) ;
if ( V_164 ) {
T_8 V_167 = V_27 -> erf . V_57 . V_167 ;
V_164 -> V_167 . V_171 = ( V_172 ) ( V_167 >> 32 ) ;
V_167 = ( ( V_167 & 0xffffffff ) * 1000 * 1000 * 1000 ) ;
V_167 += ( V_167 & 0x80000000 ) << 1 ;
V_164 -> V_167 . V_173 = ( ( V_172 ) ( V_167 >> 32 ) ) ;
if ( V_164 -> V_167 . V_173 >= 1000000000 ) {
V_164 -> V_167 . V_173 -= 1000000000 ;
V_164 -> V_167 . V_171 += 1 ;
}
}
return TRUE ;
}
static T_1
F_32 ( T_2 V_25 , union V_26 * V_27 ,
int * V_28 , T_3 * * V_29 , T_6 * V_174 )
{
T_4 V_175 [ 8 ] ;
T_8 V_176 ;
int V_2 = 0 , V_177 = sizeof( V_27 -> erf . V_178 ) / sizeof( struct V_179 ) ;
T_4 type ;
* V_174 = 0 ;
if ( V_27 -> erf . V_57 . type & 0x80 ) {
do{
if ( ! F_5 ( V_25 , V_175 , 8 , V_28 , V_29 ) )
return FALSE ;
type = V_175 [ 0 ] ;
V_176 = F_33 ( V_175 ) ;
if ( V_2 < V_177 )
memcpy ( & V_27 -> erf . V_178 [ V_2 ] . V_180 , & V_176 , sizeof( V_176 ) ) ;
* V_174 += 8 ;
V_2 ++ ;
} while ( type & 0x80 );
}
return TRUE ;
}
static T_1
F_34 ( T_2 V_25 , union V_26 * V_27 ,
int * V_28 , T_3 * * V_29 , T_6 * V_174 )
{
T_4 V_181 [ sizeof( union V_181 ) ] ;
* V_174 = 0 ;
switch( V_27 -> erf . V_57 . type & 0x7F ) {
case V_182 :
case V_183 :
case V_184 :
case V_185 :
case V_186 :
case V_187 :
case V_188 :
if ( ! F_5 ( V_25 , V_181 , sizeof( V_189 ) , V_28 , V_29 ) )
return FALSE ;
V_27 -> erf . V_190 . V_191 = F_35 ( & V_181 [ 0 ] ) ;
* V_174 = sizeof( V_189 ) ;
break;
case V_192 :
if ( ! F_5 ( V_25 , V_181 , sizeof( V_193 ) , V_28 , V_29 ) )
return FALSE ;
V_27 -> erf . V_190 . V_194 = F_35 ( & V_181 [ 0 ] ) ;
* V_174 = sizeof( V_193 ) ;
break;
case V_195 :
case V_196 :
case V_197 :
case V_198 :
if ( ! F_5 ( V_25 , V_181 , sizeof( V_199 ) , V_28 , V_29 ) )
return FALSE ;
memcpy ( & V_27 -> erf . V_190 . V_200 , V_181 , sizeof V_27 -> erf . V_190 . V_200 ) ;
* V_174 = sizeof( V_199 ) ;
break;
default:
break;
}
return TRUE ;
}
static T_1
F_36 ( T_2 V_25 , union V_26 * V_27 , int * V_28 , T_3 * * V_29 )
{
struct V_201 V_202 ;
if ( ! F_5 ( V_25 , & V_202 , sizeof ( V_202 ) , V_28 , V_29 ) )
return FALSE ;
V_27 -> V_203 . V_204 = V_202 . V_205 & 0x80 ? 1 : 0 ;
V_27 -> V_203 . V_205 = V_202 . V_205 & 0x7f ;
V_27 -> V_203 . V_48 = F_35 ( & V_202 . V_48 ) ;
return TRUE ;
}
int
F_37 ( T_2 V_25 , int V_206 , int V_13 ,
T_6 V_102 , T_1 V_207 ,
struct V_100 * V_57 , int * V_28 , T_3 * * V_29 )
{
int V_208 = 0 ;
T_6 V_145 ;
switch ( V_13 ) {
case V_14 :
if ( V_206 == V_209 ) {
if ( V_207 && V_102 < V_53 ) {
* V_28 = V_66 ;
* V_29 = F_38 ( L_3 ,
V_102 ) ;
return - 1 ;
}
if ( ! F_7 ( V_25 ,
& V_57 -> V_27 , V_28 , V_29 ) )
return - 1 ;
V_208 = V_53 ;
} else {
if ( V_207 && V_102 < V_31 ) {
* V_28 = V_66 ;
* V_29 = F_38 ( L_4 ,
V_102 ) ;
return - 1 ;
}
if ( ! F_4 ( V_25 ,
& V_57 -> V_27 , V_28 , V_29 ) )
return - 1 ;
V_208 = V_31 ;
}
break;
case V_210 :
if ( V_206 == V_209 ) {
if ( ! F_8 ( V_25 , & V_57 -> V_27 , V_28 , V_29 ) )
return - 1 ;
}
V_57 -> V_27 . V_211 . V_212 = - 1 ;
break;
case V_213 :
case V_214 :
case V_215 :
case V_216 :
memset ( & V_57 -> V_27 . V_217 , 0 , sizeof( V_57 -> V_27 . V_217 ) ) ;
V_57 -> V_27 . V_217 . V_212 = - 1 ;
V_57 -> V_27 . V_217 . V_218 = FALSE ;
V_57 -> V_27 . V_217 . V_219 = FALSE ;
break;
case V_15 :
if ( V_207 && V_102 < V_64 ) {
* V_28 = V_66 ;
* V_29 = F_38 ( L_5 ,
V_102 ) ;
return - 1 ;
}
if ( ! F_11 ( V_25 , & V_57 -> V_27 ,
V_28 , V_29 ) )
return - 1 ;
V_208 = V_64 ;
break;
case V_16 :
if ( V_207 && V_102 < V_71 ) {
* V_28 = V_66 ;
* V_29 = F_38 ( L_6 ,
V_102 ) ;
return - 1 ;
}
if ( ! F_13 ( V_25 , & V_57 -> V_27 ,
V_28 , V_29 ) )
return - 1 ;
V_208 = V_71 ;
break;
case V_17 :
if ( V_207 && V_102 < V_80 ) {
* V_28 = V_66 ;
* V_29 = F_38 ( L_7 ,
V_102 ) ;
return - 1 ;
}
if ( ! F_14 ( V_25 , & V_57 -> V_27 ,
V_28 , V_29 ) )
return - 1 ;
V_208 = V_80 ;
break;
case V_18 :
if ( V_207 && V_102 < V_88 ) {
* V_28 = V_66 ;
* V_29 = F_38 ( L_8 ,
V_102 ) ;
return - 1 ;
}
if ( ! F_15 ( V_25 , & V_57 -> V_27 ,
V_28 , V_29 ) )
return - 1 ;
V_208 = V_88 ;
break;
case V_220 :
V_57 -> V_27 . V_150 . V_73 = FALSE ;
break;
case V_19 :
if ( V_207 &&
V_102 < sizeof ( struct V_149 ) ) {
* V_28 = V_66 ;
* V_29 = F_38 ( L_9 ,
V_102 ) ;
return - 1 ;
}
if ( ! F_24 ( V_25 ,
& V_57 -> V_27 , V_28 , V_29 ) )
return - 1 ;
V_208 = ( int ) sizeof ( struct V_149 ) ;
break;
case V_20 :
if ( V_207 &&
V_102 < sizeof ( struct V_153 ) ) {
* V_28 = V_66 ;
* V_29 = F_38 ( L_10 ,
V_102 ) ;
return - 1 ;
}
if ( ! F_26 ( V_25 ,
& V_57 -> V_27 , V_28 , V_29 ) )
return - 1 ;
V_208 = ( int ) sizeof ( struct V_153 ) ;
break;
case V_21 :
if ( V_207 && V_102 < V_157 ) {
* V_28 = V_66 ;
* V_29 = F_12 ( L_11 ) ;
return - 1 ;
}
if ( ! F_28 ( V_25 , & V_57 -> V_27 , V_28 , V_29 ) )
return - 1 ;
V_208 = V_157 ;
break;
case V_22 :
if ( V_207 &&
V_102 < sizeof ( struct V_162 ) ) {
* V_28 = V_66 ;
* V_29 = F_38 ( L_12 ,
V_102 ) ;
return - 1 ;
}
if ( ! F_29 ( V_25 ,
& V_57 -> V_27 , V_28 , V_29 ) )
return - 1 ;
V_208 = ( int ) sizeof ( struct V_162 ) ;
break;
case V_23 :
if ( V_207 &&
V_102 < sizeof( struct V_166 ) ) {
* V_28 = V_66 ;
* V_29 = F_38 ( L_13 ,
V_102 ) ;
return - 1 ;
}
if ( ! F_30 ( V_25 , V_57 , & V_57 -> V_27 ,
V_28 , V_29 ) )
return - 1 ;
V_208 = ( int ) sizeof( struct V_166 ) ;
if ( ! F_32 ( V_25 , & V_57 -> V_27 , V_28 , V_29 ,
& V_145 ) )
return - 1 ;
V_208 += V_145 ;
if ( ! F_34 ( V_25 , & V_57 -> V_27 , V_28 , V_29 ,
& V_145 ) )
return - 1 ;
V_208 += V_145 ;
if ( V_207 &&
V_102 < ( T_6 ) V_208 ) {
* V_28 = V_66 ;
* V_29 = F_38 ( L_14 ,
V_102 , V_208 ) ;
return - 1 ;
}
break;
case V_24 :
if ( V_207 &&
V_102 < sizeof ( struct V_201 ) ) {
* V_28 = V_66 ;
* V_29 = F_38 ( L_15 ,
V_102 ) ;
return - 1 ;
}
if ( ! F_36 ( V_25 , & V_57 -> V_27 ,
V_28 , V_29 ) )
return - 1 ;
V_208 = ( int ) sizeof ( struct V_201 ) ;
break;
}
return V_208 ;
}
void
F_39 ( int V_206 , int V_13 ,
struct V_100 * V_57 , T_4 * V_101 , T_1 V_221 , int V_212 )
{
switch ( V_13 ) {
case V_14 :
if ( V_206 == V_209 ) {
F_40 ( V_57 , V_101 ) ;
} else {
if ( V_57 -> V_27 . V_37 . type == V_40 )
F_41 ( V_57 , V_101 ) ;
}
break;
case V_210 :
V_57 -> V_27 . V_211 . V_212 = V_212 ;
break;
case V_222 :
if ( V_221 )
F_16 ( V_57 , V_101 ) ;
break;
case V_223 :
if ( V_221 )
F_18 ( V_57 , V_101 , FALSE ) ;
break;
case V_224 :
if ( V_221 )
F_18 ( V_57 , V_101 , TRUE ) ;
break;
case V_225 :
V_57 -> V_27 . V_211 . V_212 = 4 ;
break;
case V_226 :
if ( V_221 )
F_22 ( V_57 , V_101 ) ;
break;
case V_23 :
V_57 -> V_107 = V_57 -> V_27 . erf . V_57 . V_170 ;
V_57 -> V_106 = F_42 ( V_57 -> V_107 , V_57 -> V_106 ) ;
break;
default:
break;
}
}
int
F_43 ( int V_1 , const union V_26 * V_27 )
{
int V_227 ;
switch ( V_1 ) {
case V_14 :
V_227 = V_31 ;
break;
case V_15 :
V_227 = V_64 ;
break;
case V_16 :
V_227 = V_71 ;
break;
case V_17 :
V_227 = V_80 ;
break;
case V_18 :
V_227 = V_88 ;
break;
case V_23 :
V_227 = ( int ) sizeof ( struct V_166 ) ;
switch ( V_27 -> erf . V_57 . type & 0x7F ) {
case V_182 :
case V_183 :
case V_184 :
case V_185 :
case V_186 :
case V_187 :
case V_188 :
V_227 += ( int ) sizeof( struct V_228 ) ;
break;
case V_192 :
V_227 += ( int ) sizeof( struct V_229 ) ;
break;
case V_195 :
case V_196 :
case V_197 :
case V_198 :
V_227 += ( int ) sizeof( struct V_230 ) ;
break;
default:
break;
}
if ( V_27 -> erf . V_57 . type & 0x80 ) {
int V_2 = 0 , V_177 = sizeof( V_27 -> erf . V_178 ) / sizeof( struct V_179 ) ;
T_4 V_175 [ 8 ] ;
T_4 type ;
do {
F_44 ( V_175 , V_27 -> erf . V_178 [ V_2 ] . V_180 ) ;
type = V_175 [ 0 ] ;
V_227 += 8 ;
V_2 ++ ;
} while ( type & 0x80 && V_2 < V_177 );
}
break;
case V_24 :
V_227 = ( int ) sizeof ( struct V_201 ) ;
break;
case V_19 :
V_227 = ( int ) sizeof ( struct V_149 ) ;
break;
case V_22 :
V_227 = ( int ) sizeof ( struct V_162 ) ;
break;
case V_20 :
V_227 = ( int ) sizeof ( struct V_153 ) ;
break;
default:
V_227 = 0 ;
break;
}
return V_227 ;
}
T_1
F_45 ( T_9 * V_231 , int V_1 , const union V_26 * V_27 ,
int * V_28 )
{
T_4 V_232 [ V_31 ] ;
T_4 V_233 [ V_64 ] ;
T_4 V_234 [ V_80 ] ;
T_4 V_70 [ V_71 ] ;
T_4 V_235 [ V_88 ] ;
T_4 V_165 [ sizeof( struct V_236 ) ] ;
T_4 V_181 [ sizeof( union V_181 ) ] ;
struct V_201 V_202 ;
struct V_149 V_237 ;
struct V_153 V_238 ;
struct V_162 V_239 ;
T_10 V_145 ;
T_10 V_240 = 0 ;
switch ( V_1 ) {
case V_14 :
V_232 [ V_36 ] =
( V_27 -> V_37 . V_47 == 0 ) ? 0x80 : 0x00 ;
switch ( V_27 -> V_37 . V_38 ) {
case V_43 :
V_232 [ V_36 ] |= 0x06 ;
break;
case V_39 :
switch ( V_27 -> V_37 . type ) {
case V_40 :
V_232 [ V_36 ] |= 0x01 ;
break;
case V_41 :
V_232 [ V_36 ] |= 0x02 ;
break;
case V_42 :
V_232 [ V_36 ] |= 0x05 ;
break;
}
break;
}
V_232 [ V_34 ] = ( T_4 ) V_27 -> V_37 . V_32 ;
F_46 ( & V_232 [ V_35 ] , V_27 -> V_37 . V_33 ) ;
if ( ! F_47 ( V_231 , V_232 , sizeof( V_232 ) , V_28 ) )
return FALSE ;
V_231 -> V_241 += sizeof( V_232 ) ;
break;
case V_15 :
memset ( V_233 , 0 , sizeof( V_233 ) ) ;
F_46 ( & V_233 [ V_69 ] ,
V_27 -> V_67 . V_68 ) ;
F_46 ( & V_233 [ V_65 ] , 0x0017 ) ;
if ( ! F_47 ( V_231 , V_233 , sizeof( V_233 ) , V_28 ) )
return FALSE ;
V_231 -> V_241 += sizeof( V_233 ) ;
break;
case V_16 :
memset ( & V_70 , 0 , sizeof( V_70 ) ) ;
V_70 [ V_74 ] = V_27 -> V_72 . V_73 ;
V_70 [ V_76 ] = V_27 -> V_72 . V_75 ;
F_46 ( & V_70 [ V_78 ] ,
V_27 -> V_72 . V_77 ) ;
if ( ! F_47 ( V_231 , V_70 , sizeof( V_70 ) , V_28 ) )
return FALSE ;
V_231 -> V_241 += sizeof( V_70 ) ;
break;
case V_17 :
memset ( & V_234 , 0 , sizeof( V_234 ) ) ;
F_46 ( & V_234 [ V_84 ] ,
V_27 -> V_83 . V_68 ) ;
F_46 ( & V_234 [ V_81 ] , V_82 ) ;
V_234 [ V_86 + 0 ] =
V_27 -> V_83 . V_85 ? 0x01 : 0x00 ;
if ( ! F_47 ( V_231 , V_234 , sizeof( V_234 ) , V_28 ) )
return FALSE ;
V_231 -> V_241 += sizeof( V_234 ) ;
break;
case V_18 :
memset ( & V_235 , 0 , sizeof( V_235 ) ) ;
V_235 [ V_91 ] = V_27 -> V_89 . V_90 ;
V_235 [ V_93 ] = V_27 -> V_89 . V_92 ;
V_235 [ V_95 ] = V_27 -> V_89 . V_94 ;
V_235 [ V_97 ] = V_27 -> V_89 . V_96 ;
V_235 [ V_99 ] = V_27 -> V_89 . V_98 ;
if ( ! F_47 ( V_231 , V_235 , sizeof( V_235 ) , V_28 ) )
return FALSE ;
V_231 -> V_241 += sizeof( V_235 ) ;
break;
case V_23 :
memset ( & V_165 , 0 , sizeof( V_165 ) ) ;
F_48 ( & V_165 [ 0 ] , V_27 -> erf . V_57 . V_167 ) ;
V_165 [ 8 ] = V_27 -> erf . V_57 . type ;
V_165 [ 9 ] = V_27 -> erf . V_57 . V_48 ;
F_46 ( & V_165 [ 10 ] ,
F_42 ( V_27 -> erf . V_57 . V_168 , V_27 -> erf . V_57 . V_170 + F_43 ( V_23 , V_27 ) ) ) ;
F_46 ( & V_165 [ 12 ] , V_27 -> erf . V_57 . V_169 ) ;
F_46 ( & V_165 [ 14 ] , V_27 -> erf . V_57 . V_170 ) ;
V_145 = sizeof( struct V_166 ) ;
switch( V_27 -> erf . V_57 . type & 0x7F ) {
case V_182 :
case V_183 :
case V_184 :
case V_185 :
case V_186 :
case V_187 :
case V_188 :
F_49 ( & V_181 [ 0 ] , V_27 -> erf . V_190 . V_191 ) ;
V_240 += ( int ) sizeof( struct V_228 ) ;
break;
case V_192 :
F_49 ( & V_181 [ 0 ] , V_27 -> erf . V_190 . V_194 ) ;
V_240 += ( int ) sizeof( struct V_229 ) ;
break;
case V_195 :
case V_196 :
case V_197 :
case V_198 :
memcpy ( & V_181 [ 0 ] , & V_27 -> erf . V_190 . V_200 , sizeof V_27 -> erf . V_190 . V_200 ) ;
V_240 += ( int ) sizeof( struct V_230 ) ;
break;
default:
break;
}
if ( ! F_47 ( V_231 , V_165 , V_145 , V_28 ) )
return FALSE ;
V_231 -> V_241 += V_145 ;
if ( V_27 -> erf . V_57 . type & 0x80 ) {
int V_2 = 0 , V_177 = sizeof( V_27 -> erf . V_178 ) / sizeof( struct V_179 ) ;
T_4 V_175 [ 8 ] ;
T_4 type ;
do {
F_44 ( V_175 , V_27 -> erf . V_178 [ V_2 ] . V_180 ) ;
type = V_175 [ 0 ] ;
if( V_2 == V_177 - 1 )
V_175 [ 0 ] = V_175 [ 0 ] & 0x7F ;
if ( ! F_47 ( V_231 , V_175 , 8 , V_28 ) )
return FALSE ;
V_231 -> V_241 += 8 ;
V_2 ++ ;
} while ( type & 0x80 && V_2 < V_177 );
}
if( ! F_47 ( V_231 , V_181 , V_240 , V_28 ) )
return FALSE ;
V_231 -> V_241 += V_240 ;
break;
case V_24 :
memset ( & V_202 , 0 , sizeof( V_202 ) ) ;
V_202 . V_205 = V_27 -> V_203 . V_205 |
( V_27 -> V_203 . V_204 ? 0x80 : 0x00 ) ;
F_49 ( ( T_4 * ) & V_202 . V_48 , V_27 -> V_203 . V_48 ) ;
if ( ! F_47 ( V_231 , & V_202 , sizeof( V_202 ) , V_28 ) )
return FALSE ;
V_231 -> V_241 += sizeof( V_202 ) ;
break;
case V_19 :
V_237 . V_151 = F_50 ( V_27 -> V_150 . V_73 ? V_242 : V_152 ) ;
if ( ! F_47 ( V_231 , & V_237 , sizeof V_237 , V_28 ) )
return FALSE ;
V_231 -> V_241 += sizeof V_237 ;
break;
case V_20 :
V_238 . V_155 = F_51 ( V_27 -> V_154 . V_155 ) ;
V_238 . V_156 = F_51 ( V_27 -> V_154 . V_156 ) ;
if ( ! F_47 ( V_231 , & V_238 , sizeof V_238 , V_28 ) )
return FALSE ;
V_231 -> V_241 += sizeof V_238 ;
break;
case V_22 :
V_239 . V_151 = ( V_27 -> V_150 . V_73 ? V_163 : V_243 ) ;
if ( ! F_47 ( V_231 , & V_239 , sizeof V_239 , V_28 ) )
return FALSE ;
V_231 -> V_241 += sizeof V_239 ;
break;
}
return TRUE ;
}
