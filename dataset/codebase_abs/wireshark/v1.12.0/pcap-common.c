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
F_3 ( int V_1 ) {
if (
( V_1 == V_13 ) ||
( V_1 == V_14 ) ||
( V_1 == V_15 ) ||
( V_1 == V_16 ) ||
( V_1 == V_17 ) ||
( V_1 == V_18 ) ||
( V_1 == V_19 ) ||
( V_1 == V_20 ) ||
( V_1 == V_21 ) ||
( V_1 == V_22 )
) {
return TRUE ;
}
return FALSE ;
}
static T_1
F_4 ( T_2 V_23 ,
union V_24 * V_25 , int * V_26 , T_3 * * V_27 )
{
T_4 V_28 [ V_29 ] ;
int V_30 ;
T_4 V_31 ;
T_5 V_32 ;
V_33 = V_34 ;
V_30 = F_5 ( V_28 , V_29 , V_23 ) ;
if ( V_30 != V_29 ) {
* V_26 = F_6 ( V_23 , V_27 ) ;
if ( * V_26 == 0 )
* V_26 = V_35 ;
return FALSE ;
}
V_31 = V_28 [ V_36 ] ;
V_32 = F_7 ( & V_28 [ V_37 ] ) ;
switch ( V_28 [ V_38 ] & 0x0F ) {
case 0x01 :
V_25 -> V_39 . V_40 = V_41 ;
V_25 -> V_39 . type = V_42 ;
break;
case 0x02 :
V_25 -> V_39 . V_40 = V_41 ;
V_25 -> V_39 . type = V_43 ;
break;
case 0x05 :
V_25 -> V_39 . V_40 = V_41 ;
V_25 -> V_39 . type = V_44 ;
break;
case 0x06 :
V_25 -> V_39 . V_40 = V_45 ;
V_25 -> V_39 . type = V_46 ;
break;
case 0x03 :
V_25 -> V_39 . V_40 = V_41 ;
V_25 -> V_39 . type = V_46 ;
break;
case 0x04 :
V_25 -> V_39 . V_40 = V_41 ;
V_25 -> V_39 . type = V_46 ;
break;
default:
if ( V_31 == 0 && V_32 == 5 )
V_25 -> V_39 . V_40 = V_45 ;
else
V_25 -> V_39 . V_40 = V_41 ;
V_25 -> V_39 . type = V_46 ;
break;
}
V_25 -> V_39 . V_47 = V_48 ;
V_25 -> V_39 . V_31 = V_31 ;
V_25 -> V_39 . V_32 = V_32 ;
V_25 -> V_39 . V_49 = ( V_28 [ V_38 ] & 0x80 ) ? 0 : 1 ;
V_25 -> V_39 . V_50 = 0 ;
V_25 -> V_39 . V_51 = 0 ;
V_25 -> V_39 . V_52 = 0 ;
V_25 -> V_39 . V_53 = 0 ;
V_25 -> V_39 . V_54 = 0 ;
return TRUE ;
}
static T_1
F_8 ( T_2 V_23 ,
union V_24 * V_25 , int * V_26 , T_3 * * V_27 )
{
T_4 V_28 [ V_55 ] ;
int V_30 ;
T_4 V_31 ;
T_5 V_32 ;
V_33 = V_34 ;
V_30 = F_5 ( V_28 , V_55 , V_23 ) ;
if ( V_30 != V_55 ) {
* V_26 = F_6 ( V_23 , V_27 ) ;
if ( * V_26 == 0 )
* V_26 = V_35 ;
return FALSE ;
}
V_31 = V_28 [ V_56 ] ;
V_32 = F_7 ( & V_28 [ V_57 ] ) ;
V_25 -> V_39 . V_31 = V_31 ;
V_25 -> V_39 . V_32 = V_32 ;
V_25 -> V_39 . V_49 = ( V_28 [ V_58 ] & 0x80 ) ? 0 : 1 ;
V_25 -> V_39 . V_50 = 0 ;
V_25 -> V_39 . V_51 = 0 ;
V_25 -> V_39 . V_52 = 0 ;
V_25 -> V_39 . V_53 = 0 ;
V_25 -> V_39 . V_54 = 0 ;
return TRUE ;
}
static T_1
F_9 ( T_2 V_23 ,
union V_24 * V_25 , int * V_26 , T_3 * * V_27 )
{
T_4 V_59 [ V_60 ] ;
int V_30 ;
V_33 = V_34 ;
if ( F_10 ( V_23 , - V_60 , V_61 , V_26 ) == - 1 )
{
* V_26 = F_6 ( V_23 , V_27 ) ;
if ( * V_26 == 0 )
* V_26 = V_35 ;
return FALSE ;
}
V_30 = F_5 ( V_59 , V_60 , V_23 ) ;
if ( V_30 != V_60 ) {
* V_26 = F_6 ( V_23 , V_27 ) ;
if ( * V_26 == 0 )
* V_26 = V_35 ;
return FALSE ;
}
memcpy ( V_25 -> V_62 . V_63 , V_59 , V_60 ) ;
return TRUE ;
}
static T_1
F_11 ( T_2 V_23 , union V_24 * V_25 ,
int * V_26 , T_3 * * V_27 )
{
T_4 V_64 [ V_65 ] ;
int V_30 ;
V_33 = V_34 ;
V_30 = F_5 ( V_64 , V_65 , V_23 ) ;
if ( V_30 != V_65 ) {
* V_26 = F_6 ( V_23 , V_27 ) ;
if ( * V_26 == 0 )
* V_26 = V_35 ;
return FALSE ;
}
if ( F_7 ( & V_64 [ V_66 ] ) != 0x0017 ) {
* V_26 = V_67 ;
if ( V_27 != NULL )
* V_27 = F_12 ( L_1 ) ;
return FALSE ;
}
V_25 -> V_68 . V_69 = F_7 ( & V_64 [ V_70 ] ) ;
return TRUE ;
}
static T_1
F_13 ( T_2 V_23 , union V_24 * V_25 , int * V_26 , T_3 * * V_27 )
{
T_4 V_71 [ V_72 ] ;
int V_30 ;
V_33 = V_34 ;
V_30 = F_5 ( V_71 , V_72 , V_23 ) ;
if ( V_30 != V_72 ) {
* V_26 = F_6 ( V_23 , V_27 ) ;
if ( * V_26 == 0 )
* V_26 = V_35 ;
return FALSE ;
}
V_25 -> V_73 . V_74 = V_71 [ V_75 ] ;
V_25 -> V_73 . V_76 = V_71 [ V_77 ] ;
V_25 -> V_73 . V_78 = F_7 ( & V_71 [ V_79 ] ) ;
return TRUE ;
}
static T_1
F_14 ( T_2 V_23 , union V_24 * V_25 ,
int * V_26 , T_3 * * V_27 )
{
T_4 V_80 [ V_81 ] ;
int V_30 ;
V_33 = V_34 ;
V_30 = F_5 ( V_80 , V_81 , V_23 ) ;
if ( V_30 != V_81 ) {
* V_26 = F_6 ( V_23 , V_27 ) ;
if ( * V_26 == 0 )
* V_26 = V_35 ;
return FALSE ;
}
if ( F_7 ( & V_80 [ V_82 ] ) != V_83 ) {
* V_26 = V_67 ;
if ( V_27 != NULL )
* V_27 = F_12 ( L_2 ) ;
return FALSE ;
}
V_25 -> V_84 . V_69 = F_7 ( & V_80 [ V_85 ] ) ;
V_25 -> V_84 . V_86 = ! ! V_80 [ V_87 + 0 ] ;
return TRUE ;
}
static T_1
F_15 ( T_2 V_23 , union V_24 * V_25 , int * V_26 , T_3 * * V_27 )
{
T_4 V_88 [ V_89 ] ;
int V_30 ;
V_33 = V_34 ;
V_30 = F_5 ( V_88 , V_89 , V_23 ) ;
if ( V_30 != V_89 ) {
* V_26 = F_6 ( V_23 , V_27 ) ;
if ( * V_26 == 0 )
* V_26 = V_35 ;
return FALSE ;
}
V_25 -> V_90 . V_91 = V_88 [ V_92 ] ;
V_25 -> V_90 . V_93 = V_88 [ V_94 ] ;
V_25 -> V_90 . V_95 = V_88 [ V_96 ] ;
V_25 -> V_90 . V_97 = V_88 [ V_98 ] ;
V_25 -> V_90 . V_99 = V_88 [ V_100 ] ;
return TRUE ;
}
static void
F_16 ( struct V_101 * V_59 , T_4 * V_102 ,
T_1 V_103 )
{
T_6 V_104 ;
struct V_105 * V_106 ;
struct V_107 * V_108 ;
T_7 V_109 , V_2 ;
V_104 = V_59 -> V_110 ;
if ( V_104 > V_59 -> V_111 )
V_104 = V_59 -> V_111 ;
V_106 = (struct V_105 * ) ( void * ) V_102 ;
F_17 ( & V_106 -> V_112 ) ;
F_18 ( & V_106 -> V_113 ) ;
F_17 ( & V_106 -> V_114 ) ;
F_19 ( & V_106 -> V_115 ) ;
F_19 ( & V_106 -> V_116 ) ;
F_19 ( & V_106 -> V_117 ) ;
F_19 ( & V_106 -> V_118 ) ;
if ( V_106 -> V_119 == V_120 ) {
F_19 ( & V_106 -> V_121 . V_122 . V_123 ) ;
F_19 ( & V_106 -> V_121 . V_122 . V_124 ) ;
}
if ( V_103 ) {
F_19 ( & V_106 -> V_125 ) ;
F_19 ( & V_106 -> V_126 ) ;
F_19 ( & V_106 -> V_127 ) ;
F_19 ( & V_106 -> V_128 ) ;
}
if ( V_106 -> V_119 == V_120 ) {
if ( V_103 ) {
V_108 = (struct V_107 * ) ( void * ) ( V_102 + 64 ) ;
} else {
V_108 = (struct V_107 * ) ( void * ) ( V_102 + 48 ) ;
}
V_109 = V_106 -> V_121 . V_122 . V_124 ;
for ( V_2 = 0 ; V_2 < V_109 ; V_2 ++ ) {
F_19 ( & V_108 -> V_129 ) ;
F_19 ( & V_108 -> V_130 ) ;
F_19 ( & V_108 -> V_131 ) ;
F_19 ( & V_108 -> V_132 ) ;
V_108 ++ ;
}
}
}
static void
F_20 ( struct V_101 * V_59 , T_4 * V_102 )
{
T_6 V_104 ;
T_4 * V_133 ;
struct V_134 * V_135 ;
struct V_136 * V_137 ;
T_6 V_138 ;
V_104 = V_59 -> V_110 ;
if ( V_104 > V_59 -> V_111 )
V_104 = V_59 -> V_111 ;
if ( V_104 < sizeof( struct V_134 ) ) {
return;
}
V_133 = V_102 ;
V_135 = (struct V_134 * ) V_102 ;
if ( ! ( V_135 -> V_139 ) == 0 ) {
return;
}
V_104 -= ( T_6 ) sizeof( struct V_134 ) ;
V_133 += sizeof( struct V_134 ) ;
while ( V_104 >= sizeof( struct V_136 ) ) {
V_137 = (struct V_136 * ) V_133 ;
F_21 ( ( T_4 * ) & V_137 -> V_140 ) ;
F_21 ( ( T_4 * ) & V_137 -> V_141 ) ;
V_138 = V_137 -> V_141 ;
if ( V_138 % 4 != 0 )
V_138 += 4 - V_138 % 4 ;
if ( V_138 < sizeof( struct V_136 ) ) {
return;
}
if ( V_104 < V_138 ) {
return;
}
V_104 -= V_138 ;
V_133 += V_138 ;
}
}
static T_1
F_22 ( T_2 V_23 ,
union V_24 * V_25 , int * V_26 , T_3 * * V_27 )
{
int V_30 ;
struct V_142 V_59 ;
V_33 = V_34 ;
V_30 = F_5 ( & V_59 ,
sizeof ( struct V_142 ) , V_23 ) ;
if ( V_30 != sizeof ( struct V_142 ) ) {
* V_26 = F_6 ( V_23 , V_27 ) ;
if ( * V_26 == 0 )
* V_26 = V_35 ;
return FALSE ;
}
V_25 -> V_143 . V_74 = ( ( F_23 ( V_59 . V_144 ) & V_145 ) == 0 ) ? TRUE : FALSE ;
return TRUE ;
}
static T_1
F_24 ( T_2 V_23 ,
union V_24 * V_25 , int * V_26 , T_3 * * V_27 )
{
int V_30 ;
struct V_146 V_59 ;
V_33 = V_34 ;
V_30 = F_5 ( & V_59 ,
sizeof ( struct V_146 ) , V_23 ) ;
if ( V_30 != sizeof ( struct V_146 ) ) {
* V_26 = F_6 ( V_23 , V_27 ) ;
if ( * V_26 == 0 )
* V_26 = V_35 ;
return FALSE ;
}
V_25 -> V_147 . V_148 = F_25 ( V_59 . V_148 ) ;
V_25 -> V_147 . V_149 = F_25 ( V_59 . V_149 ) ;
return TRUE ;
}
static T_1
F_26 ( T_2 V_23 ,
union V_24 * V_25 , int * V_26 , T_3 * * V_27 )
{
int V_30 ;
T_4 V_59 [ V_150 ] ;
V_33 = V_34 ;
V_30 = F_5 ( V_59 , V_150 , V_23 ) ;
if ( V_30 != V_150 ) {
* V_26 = F_6 ( V_23 , V_27 ) ;
if ( * V_26 == 0 )
* V_26 = V_35 ;
return FALSE ;
}
V_25 -> V_151 . V_152 = V_59 [ V_153 ] ;
V_25 -> V_151 . V_50 = V_59 [ V_154 ] ;
return TRUE ;
}
static T_1
F_27 ( T_2 V_23 ,
union V_24 * V_25 , int * V_26 , T_3 * * V_27 )
{
int V_30 ;
struct V_155 V_59 ;
V_33 = V_34 ;
V_30 = F_5 ( & V_59 ,
sizeof ( struct V_155 ) , V_23 ) ;
if ( V_30 != sizeof ( struct V_155 ) ) {
* V_26 = F_6 ( V_23 , V_27 ) ;
if ( * V_26 == 0 )
* V_26 = V_35 ;
return FALSE ;
}
V_25 -> V_143 . V_74 = ( V_59 . V_144 == V_156 ) ? TRUE : FALSE ;
return TRUE ;
}
static T_1
F_28 ( T_2 V_23 , struct V_101 * V_157 ,
union V_24 * V_25 , int * V_26 , T_3 * * V_27 )
{
T_4 V_158 [ sizeof( struct V_159 ) ] ;
int V_30 ;
V_33 = V_34 ;
V_30 = F_5 ( V_158 , sizeof( struct V_159 ) , V_23 ) ;
if ( V_30 != sizeof( struct V_159 ) ) {
* V_26 = F_6 ( V_23 , V_27 ) ;
if ( * V_26 == 0 )
* V_26 = V_35 ;
return FALSE ;
}
V_25 -> erf . V_59 . V_160 = F_29 ( & V_158 [ 0 ] ) ;
V_25 -> erf . V_59 . type = V_158 [ 8 ] ;
V_25 -> erf . V_59 . V_50 = V_158 [ 9 ] ;
V_25 -> erf . V_59 . V_161 = F_7 ( & V_158 [ 10 ] ) ;
V_25 -> erf . V_59 . V_162 = F_7 ( & V_158 [ 12 ] ) ;
V_25 -> erf . V_59 . V_163 = F_7 ( & V_158 [ 14 ] ) ;
if ( V_157 ) {
T_8 V_160 = V_25 -> erf . V_59 . V_160 ;
V_157 -> V_160 . V_164 = ( V_165 ) ( V_160 >> 32 ) ;
V_160 = ( ( V_160 & 0xffffffff ) * 1000 * 1000 * 1000 ) ;
V_160 += ( V_160 & 0x80000000 ) << 1 ;
V_157 -> V_160 . V_166 = ( ( V_165 ) ( V_160 >> 32 ) ) ;
if ( V_157 -> V_160 . V_166 >= 1000000000 ) {
V_157 -> V_160 . V_166 -= 1000000000 ;
V_157 -> V_160 . V_164 += 1 ;
}
}
return TRUE ;
}
static T_1
F_30 ( T_2 V_23 , union V_24 * V_25 ,
int * V_26 , T_3 * * V_27 , T_6 * V_167 )
{
int V_30 = 0 ;
T_4 V_168 [ 8 ] ;
T_8 V_169 ;
int V_2 = 0 , V_170 = sizeof( V_25 -> erf . V_171 ) / sizeof( struct V_172 ) ;
T_4 type ;
* V_167 = 0 ;
if ( V_25 -> erf . V_59 . type & 0x80 ) {
do{
V_33 = V_34 ;
V_30 = F_5 ( V_168 , 8 , V_23 ) ;
if ( V_30 != 8 ) {
* V_26 = F_6 ( V_23 , V_27 ) ;
if ( * V_26 == 0 )
* V_26 = V_35 ;
return FALSE ;
}
type = V_168 [ 0 ] ;
V_169 = F_31 ( V_168 ) ;
if ( V_2 < V_170 )
memcpy ( & V_25 -> erf . V_171 [ V_2 ] . V_173 , & V_169 , sizeof( V_169 ) ) ;
* V_167 += 8 ;
V_2 ++ ;
} while ( type & 0x80 );
}
return TRUE ;
}
static T_1
F_32 ( T_2 V_23 , union V_24 * V_25 ,
int * V_26 , T_3 * * V_27 , T_6 * V_167 )
{
T_4 V_174 [ sizeof( union V_174 ) ] ;
int V_30 ;
* V_167 = 0 ;
switch( V_25 -> erf . V_59 . type & 0x7F ) {
case V_175 :
case V_176 :
case V_177 :
case V_178 :
case V_179 :
case V_180 :
case V_181 :
V_33 = V_34 ;
V_30 = F_5 ( V_174 , sizeof( V_182 ) , V_23 ) ;
if ( V_30 != sizeof( V_182 ) ) {
* V_26 = F_6 ( V_23 , V_27 ) ;
if ( * V_26 == 0 )
* V_26 = V_35 ;
return FALSE ;
}
V_25 -> erf . V_183 . V_184 = F_33 ( & V_174 [ 0 ] ) ;
* V_167 = sizeof( V_182 ) ;
break;
case V_185 :
case V_186 :
case V_187 :
V_33 = V_34 ;
V_30 = F_5 ( V_174 , sizeof( V_188 ) , V_23 ) ;
if ( V_30 != sizeof( V_188 ) ) {
* V_26 = F_6 ( V_23 , V_27 ) ;
if ( * V_26 == 0 )
* V_26 = V_35 ;
return FALSE ;
}
V_25 -> erf . V_183 . V_189 = F_7 ( & V_174 [ 0 ] ) ;
* V_167 = sizeof( V_188 ) ;
break;
default:
break;
}
return TRUE ;
}
static T_1
F_34 ( T_2 V_23 , union V_24 * V_25 , int * V_26 , T_3 * * V_27 )
{
struct V_190 V_191 ;
int V_30 ;
V_33 = V_34 ;
V_30 = F_5 ( & V_191 , sizeof ( V_191 ) , V_23 ) ;
if ( V_30 != sizeof ( V_191 ) ) {
* V_26 = F_6 ( V_23 , V_27 ) ;
if ( * V_26 == 0 )
* V_26 = V_35 ;
return FALSE ;
}
V_25 -> V_192 . V_193 = V_191 . V_194 & 0x80 ? 1 : 0 ;
V_25 -> V_192 . V_194 = V_191 . V_194 & 0x7f ;
V_25 -> V_192 . V_50 = F_33 ( & V_191 . V_50 ) ;
return TRUE ;
}
int
F_35 ( T_2 V_23 , int V_195 , int V_196 ,
T_6 V_104 , T_1 V_197 ,
struct V_101 * V_59 , int * V_26 , T_3 * * V_27 )
{
int V_198 = 0 ;
T_6 V_138 ;
switch ( V_196 ) {
case V_13 :
if ( V_195 == V_199 ) {
if ( V_197 && V_104 < V_55 ) {
* V_26 = V_67 ;
* V_27 = F_36 ( L_3 ,
V_104 ) ;
return - 1 ;
}
if ( ! F_8 ( V_23 ,
& V_59 -> V_25 , V_26 , V_27 ) )
return - 1 ;
V_198 = V_55 ;
} else {
if ( V_197 && V_104 < V_29 ) {
* V_26 = V_67 ;
* V_27 = F_36 ( L_4 ,
V_104 ) ;
return - 1 ;
}
if ( ! F_4 ( V_23 ,
& V_59 -> V_25 , V_26 , V_27 ) )
return - 1 ;
V_198 = V_29 ;
}
break;
case V_200 :
if ( V_195 == V_199 ) {
if ( ! F_9 ( V_23 , & V_59 -> V_25 , V_26 , V_27 ) )
return - 1 ;
}
V_59 -> V_25 . V_201 . V_202 = - 1 ;
break;
case V_203 :
case V_204 :
case V_205 :
case V_206 :
V_59 -> V_25 . V_207 . V_202 = - 1 ;
V_59 -> V_25 . V_207 . V_208 = FALSE ;
V_59 -> V_25 . V_207 . V_49 = 0 ;
V_59 -> V_25 . V_207 . V_209 = 0 ;
V_59 -> V_25 . V_207 . V_210 = 0 ;
break;
case V_14 :
if ( V_197 && V_104 < V_65 ) {
* V_26 = V_67 ;
* V_27 = F_36 ( L_5 ,
V_104 ) ;
return - 1 ;
}
if ( ! F_11 ( V_23 , & V_59 -> V_25 ,
V_26 , V_27 ) )
return - 1 ;
V_198 = V_65 ;
break;
case V_15 :
if ( V_197 && V_104 < V_72 ) {
* V_26 = V_67 ;
* V_27 = F_36 ( L_6 ,
V_104 ) ;
return - 1 ;
}
if ( ! F_13 ( V_23 , & V_59 -> V_25 ,
V_26 , V_27 ) )
return - 1 ;
V_198 = V_72 ;
break;
case V_16 :
if ( V_197 && V_104 < V_81 ) {
* V_26 = V_67 ;
* V_27 = F_36 ( L_7 ,
V_104 ) ;
return - 1 ;
}
if ( ! F_14 ( V_23 , & V_59 -> V_25 ,
V_26 , V_27 ) )
return - 1 ;
V_198 = V_81 ;
break;
case V_17 :
if ( V_197 && V_104 < V_89 ) {
* V_26 = V_67 ;
* V_27 = F_36 ( L_8 ,
V_104 ) ;
return - 1 ;
}
if ( ! F_15 ( V_23 , & V_59 -> V_25 ,
V_26 , V_27 ) )
return - 1 ;
V_198 = V_89 ;
break;
case V_211 :
V_59 -> V_25 . V_143 . V_74 = FALSE ;
break;
case V_20 :
if ( V_197 &&
V_104 < sizeof ( struct V_142 ) ) {
* V_26 = V_67 ;
* V_27 = F_36 ( L_9 ,
V_104 ) ;
return - 1 ;
}
if ( ! F_22 ( V_23 ,
& V_59 -> V_25 , V_26 , V_27 ) )
return - 1 ;
V_198 = ( int ) sizeof ( struct V_142 ) ;
break;
case V_21 :
if ( V_197 &&
V_104 < sizeof ( struct V_146 ) ) {
* V_26 = V_67 ;
* V_27 = F_36 ( L_10 ,
V_104 ) ;
return - 1 ;
}
if ( ! F_24 ( V_23 ,
& V_59 -> V_25 , V_26 , V_27 ) )
return - 1 ;
V_198 = ( int ) sizeof ( struct V_146 ) ;
break;
case V_212 :
if ( V_197 && V_104 < V_150 ) {
* V_26 = V_67 ;
* V_27 = F_36 ( L_11 ) ;
return - 1 ;
}
if ( ! F_26 ( V_23 , & V_59 -> V_25 , V_26 , V_27 ) )
return - 1 ;
V_198 = V_150 ;
break;
case V_22 :
if ( V_197 &&
V_104 < sizeof ( struct V_155 ) ) {
* V_26 = V_67 ;
* V_27 = F_36 ( L_12 ,
V_104 ) ;
return - 1 ;
}
if ( ! F_27 ( V_23 ,
& V_59 -> V_25 , V_26 , V_27 ) )
return - 1 ;
V_198 = ( int ) sizeof ( struct V_155 ) ;
break;
case V_18 :
if ( V_197 &&
V_104 < sizeof( struct V_159 ) ) {
* V_26 = V_67 ;
* V_27 = F_36 ( L_13 ,
V_104 ) ;
return - 1 ;
}
if ( ! F_28 ( V_23 , V_59 , & V_59 -> V_25 ,
V_26 , V_27 ) )
return - 1 ;
V_198 = ( int ) sizeof( struct V_159 ) ;
if ( ! F_30 ( V_23 , & V_59 -> V_25 , V_26 , V_27 ,
& V_138 ) )
return - 1 ;
V_198 += V_138 ;
if ( ! F_32 ( V_23 , & V_59 -> V_25 , V_26 , V_27 ,
& V_138 ) )
return - 1 ;
V_198 += V_138 ;
if ( V_197 &&
V_104 < ( T_6 ) V_198 ) {
* V_26 = V_67 ;
* V_27 = F_36 ( L_14 ,
V_104 , V_198 ) ;
return - 1 ;
}
break;
case V_19 :
if ( V_197 &&
V_104 < sizeof ( struct V_190 ) ) {
* V_26 = V_67 ;
* V_27 = F_36 ( L_15 ,
V_104 ) ;
return - 1 ;
}
if ( ! F_34 ( V_23 , & V_59 -> V_25 ,
V_26 , V_27 ) )
return - 1 ;
V_198 = ( int ) sizeof ( struct V_190 ) ;
break;
}
return V_198 ;
}
void
F_37 ( int V_195 , int V_196 ,
struct V_101 * V_59 , T_4 * V_102 , T_1 V_213 , int V_202 )
{
switch ( V_196 ) {
case V_13 :
if ( V_195 == V_199 ) {
F_38 ( V_59 , V_102 ) ;
} else {
if ( V_59 -> V_25 . V_39 . type == V_42 )
F_39 ( V_59 , V_102 ) ;
}
break;
case V_200 :
V_59 -> V_25 . V_201 . V_202 = V_202 ;
break;
case V_214 :
if ( V_213 )
F_16 ( V_59 , V_102 , FALSE ) ;
break;
case V_215 :
if ( V_213 )
F_16 ( V_59 , V_102 , TRUE ) ;
break;
case V_216 :
V_59 -> V_25 . V_201 . V_202 = 4 ;
break;
case V_217 :
if ( V_213 )
F_20 ( V_59 , V_102 ) ;
break;
default:
break;
}
}
int
F_40 ( int V_1 , const union V_24 * V_25 )
{
int V_218 ;
switch ( V_1 ) {
case V_13 :
V_218 = V_29 ;
break;
case V_14 :
V_218 = V_65 ;
break;
case V_15 :
V_218 = V_72 ;
break;
case V_16 :
V_218 = V_81 ;
break;
case V_17 :
V_218 = V_89 ;
break;
case V_18 :
V_218 = ( int ) sizeof ( struct V_159 ) ;
switch ( V_25 -> erf . V_59 . type & 0x7F ) {
case V_175 :
case V_176 :
case V_177 :
case V_178 :
case V_179 :
case V_180 :
case V_181 :
V_218 += ( int ) sizeof( struct V_219 ) ;
break;
case V_185 :
case V_186 :
case V_187 :
V_218 += ( int ) sizeof( struct V_220 ) ;
break;
default:
break;
}
if ( V_25 -> erf . V_59 . type & 0x80 ) {
int V_2 = 0 , V_170 = sizeof( V_25 -> erf . V_171 ) / sizeof( struct V_172 ) ;
T_4 V_168 [ 8 ] ;
T_4 type ;
do {
F_41 ( V_168 , V_25 -> erf . V_171 [ V_2 ] . V_173 ) ;
type = V_168 [ 0 ] ;
V_218 += 8 ;
V_2 ++ ;
} while ( type & 0x80 && V_2 < V_170 );
}
break;
case V_19 :
V_218 = ( int ) sizeof ( struct V_190 ) ;
break;
case V_20 :
V_218 = ( int ) sizeof ( struct V_142 ) ;
break;
case V_22 :
V_218 = ( int ) sizeof ( struct V_155 ) ;
break;
case V_21 :
V_218 = ( int ) sizeof ( struct V_146 ) ;
break;
default:
V_218 = 0 ;
break;
}
return V_218 ;
}
T_1
F_42 ( T_9 * V_221 , int V_1 , const union V_24 * V_25 ,
int * V_26 )
{
T_4 V_222 [ V_29 ] ;
T_4 V_223 [ V_65 ] ;
T_4 V_224 [ V_81 ] ;
T_4 V_71 [ V_72 ] ;
T_4 V_225 [ V_89 ] ;
T_4 V_158 [ sizeof( struct V_226 ) ] ;
struct V_190 V_191 ;
struct V_142 V_227 ;
struct V_146 V_228 ;
struct V_155 V_229 ;
T_10 V_138 ;
switch ( V_1 ) {
case V_13 :
V_222 [ V_38 ] =
( V_25 -> V_39 . V_49 == 0 ) ? 0x80 : 0x00 ;
switch ( V_25 -> V_39 . V_40 ) {
case V_45 :
V_222 [ V_38 ] |= 0x06 ;
break;
case V_41 :
switch ( V_25 -> V_39 . type ) {
case V_42 :
V_222 [ V_38 ] |= 0x01 ;
break;
case V_43 :
V_222 [ V_38 ] |= 0x02 ;
break;
case V_44 :
V_222 [ V_38 ] |= 0x05 ;
break;
}
break;
}
V_222 [ V_36 ] = ( T_4 ) V_25 -> V_39 . V_31 ;
F_43 ( & V_222 [ V_37 ] , V_25 -> V_39 . V_32 ) ;
if ( ! F_44 ( V_221 , V_222 , sizeof( V_222 ) , V_26 ) )
return FALSE ;
V_221 -> V_230 += sizeof( V_222 ) ;
break;
case V_14 :
memset ( V_223 , 0 , sizeof( V_223 ) ) ;
F_43 ( & V_223 [ V_70 ] ,
V_25 -> V_68 . V_69 ) ;
F_43 ( & V_223 [ V_66 ] , 0x0017 ) ;
if ( ! F_44 ( V_221 , V_223 , sizeof( V_223 ) , V_26 ) )
return FALSE ;
V_221 -> V_230 += sizeof( V_223 ) ;
break;
case V_15 :
memset ( & V_71 , 0 , sizeof( V_71 ) ) ;
V_71 [ V_75 ] = V_25 -> V_73 . V_74 ;
V_71 [ V_77 ] = V_25 -> V_73 . V_76 ;
F_43 ( & V_71 [ V_79 ] ,
V_25 -> V_73 . V_78 ) ;
if ( ! F_44 ( V_221 , V_71 , sizeof( V_71 ) , V_26 ) )
return FALSE ;
V_221 -> V_230 += sizeof( V_71 ) ;
break;
case V_16 :
memset ( & V_224 , 0 , sizeof( V_224 ) ) ;
F_43 ( & V_224 [ V_85 ] ,
V_25 -> V_84 . V_69 ) ;
F_43 ( & V_224 [ V_82 ] , V_83 ) ;
V_224 [ V_87 + 0 ] =
V_25 -> V_84 . V_86 ? 0x01 : 0x00 ;
if ( ! F_44 ( V_221 , V_224 , sizeof( V_224 ) , V_26 ) )
return FALSE ;
V_221 -> V_230 += sizeof( V_224 ) ;
break;
case V_17 :
memset ( & V_225 , 0 , sizeof( V_225 ) ) ;
V_225 [ V_92 ] = V_25 -> V_90 . V_91 ;
V_225 [ V_94 ] = V_25 -> V_90 . V_93 ;
V_225 [ V_96 ] = V_25 -> V_90 . V_95 ;
V_225 [ V_98 ] = V_25 -> V_90 . V_97 ;
V_225 [ V_100 ] = V_25 -> V_90 . V_99 ;
if ( ! F_44 ( V_221 , V_225 , sizeof( V_225 ) , V_26 ) )
return FALSE ;
V_221 -> V_230 += sizeof( V_225 ) ;
break;
case V_18 :
memset ( & V_158 , 0 , sizeof( V_158 ) ) ;
F_45 ( & V_158 [ 0 ] , V_25 -> erf . V_59 . V_160 ) ;
V_158 [ 8 ] = V_25 -> erf . V_59 . type ;
V_158 [ 9 ] = V_25 -> erf . V_59 . V_50 ;
F_43 ( & V_158 [ 10 ] , V_25 -> erf . V_59 . V_161 ) ;
F_43 ( & V_158 [ 12 ] , V_25 -> erf . V_59 . V_162 ) ;
F_43 ( & V_158 [ 14 ] , V_25 -> erf . V_59 . V_163 ) ;
V_138 = sizeof( struct V_159 ) ;
switch( V_25 -> erf . V_59 . type & 0x7F ) {
case V_175 :
case V_176 :
case V_177 :
case V_178 :
case V_179 :
case V_180 :
case V_181 :
F_46 ( & V_158 [ 16 ] , V_25 -> erf . V_183 . V_184 ) ;
V_138 += ( int ) sizeof( struct V_219 ) ;
break;
case V_185 :
case V_186 :
case V_187 :
F_43 ( & V_158 [ 16 ] , V_25 -> erf . V_183 . V_189 ) ;
V_138 += ( int ) sizeof( struct V_220 ) ;
break;
default:
break;
}
if ( ! F_44 ( V_221 , V_158 , V_138 , V_26 ) )
return FALSE ;
V_221 -> V_230 += V_138 ;
if ( V_25 -> erf . V_59 . type & 0x80 ) {
int V_2 = 0 , V_170 = sizeof( V_25 -> erf . V_171 ) / sizeof( struct V_172 ) ;
T_4 V_168 [ 8 ] ;
T_4 type ;
do {
F_41 ( V_168 , V_25 -> erf . V_171 [ V_2 ] . V_173 ) ;
type = V_168 [ 0 ] ;
if ( ! F_44 ( V_221 , V_168 , 8 , V_26 ) )
return FALSE ;
V_221 -> V_230 += 8 ;
V_2 ++ ;
} while ( type & 0x80 && V_2 < V_170 );
}
break;
case V_19 :
memset ( & V_191 , 0 , sizeof( V_191 ) ) ;
V_191 . V_194 = V_25 -> V_192 . V_194 |
( V_25 -> V_192 . V_193 ? 0x80 : 0x00 ) ;
F_46 ( ( T_4 * ) & V_191 . V_50 , V_25 -> V_192 . V_50 ) ;
if ( ! F_44 ( V_221 , & V_191 , sizeof( V_191 ) , V_26 ) )
return FALSE ;
V_221 -> V_230 += sizeof( V_191 ) ;
break;
case V_20 :
V_227 . V_144 = F_47 ( V_25 -> V_143 . V_74 ? V_231 : V_145 ) ;
if ( ! F_44 ( V_221 , & V_227 , sizeof V_227 , V_26 ) )
return FALSE ;
V_221 -> V_230 += sizeof V_227 ;
break;
case V_21 :
V_228 . V_148 = F_48 ( V_25 -> V_147 . V_148 ) ;
V_228 . V_149 = F_48 ( V_25 -> V_147 . V_149 ) ;
if ( ! F_44 ( V_221 , & V_228 , sizeof V_228 , V_26 ) )
return FALSE ;
V_221 -> V_230 += sizeof V_228 ;
break;
case V_22 :
V_229 . V_144 = ( V_25 -> V_143 . V_74 ? V_156 : V_232 ) ;
if ( ! F_44 ( V_221 , & V_229 , sizeof V_229 , V_26 ) )
return FALSE ;
V_221 -> V_230 += sizeof V_229 ;
break;
}
return TRUE ;
}
