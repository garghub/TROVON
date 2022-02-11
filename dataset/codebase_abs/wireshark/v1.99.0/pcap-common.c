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
T_4 V_30 ;
T_5 V_31 ;
V_32 = V_33 ;
if ( ! F_5 ( V_23 , V_28 , V_29 , V_26 , V_27 ) )
return FALSE ;
V_30 = V_28 [ V_34 ] ;
V_31 = F_6 ( & V_28 [ V_35 ] ) ;
switch ( V_28 [ V_36 ] & 0x0F ) {
case 0x01 :
V_25 -> V_37 . V_38 = V_39 ;
V_25 -> V_37 . type = V_40 ;
break;
case 0x02 :
V_25 -> V_37 . V_38 = V_39 ;
V_25 -> V_37 . type = V_41 ;
break;
case 0x05 :
V_25 -> V_37 . V_38 = V_39 ;
V_25 -> V_37 . type = V_42 ;
break;
case 0x06 :
V_25 -> V_37 . V_38 = V_43 ;
V_25 -> V_37 . type = V_44 ;
break;
case 0x03 :
V_25 -> V_37 . V_38 = V_39 ;
V_25 -> V_37 . type = V_44 ;
break;
case 0x04 :
V_25 -> V_37 . V_38 = V_39 ;
V_25 -> V_37 . type = V_44 ;
break;
default:
if ( V_30 == 0 && V_31 == 5 )
V_25 -> V_37 . V_38 = V_43 ;
else
V_25 -> V_37 . V_38 = V_39 ;
V_25 -> V_37 . type = V_44 ;
break;
}
V_25 -> V_37 . V_45 = V_46 ;
V_25 -> V_37 . V_30 = V_30 ;
V_25 -> V_37 . V_31 = V_31 ;
V_25 -> V_37 . V_47 = ( V_28 [ V_36 ] & 0x80 ) ? 0 : 1 ;
V_25 -> V_37 . V_48 = 0 ;
V_25 -> V_37 . V_49 = 0 ;
V_25 -> V_37 . V_50 = 0 ;
V_25 -> V_37 . V_51 = 0 ;
V_25 -> V_37 . V_52 = 0 ;
return TRUE ;
}
static T_1
F_7 ( T_2 V_23 ,
union V_24 * V_25 , int * V_26 , T_3 * * V_27 )
{
T_4 V_28 [ V_53 ] ;
T_4 V_30 ;
T_5 V_31 ;
V_32 = V_33 ;
if ( ! F_5 ( V_23 , V_28 , V_53 , V_26 , V_27 ) )
return FALSE ;
V_30 = V_28 [ V_54 ] ;
V_31 = F_6 ( & V_28 [ V_55 ] ) ;
V_25 -> V_37 . V_30 = V_30 ;
V_25 -> V_37 . V_31 = V_31 ;
V_25 -> V_37 . V_47 = ( V_28 [ V_56 ] & 0x80 ) ? 0 : 1 ;
V_25 -> V_37 . V_48 = 0 ;
V_25 -> V_37 . V_49 = 0 ;
V_25 -> V_37 . V_50 = 0 ;
V_25 -> V_37 . V_51 = 0 ;
V_25 -> V_37 . V_52 = 0 ;
return TRUE ;
}
static T_1
F_8 ( T_2 V_23 ,
union V_24 * V_25 , int * V_26 , T_3 * * V_27 )
{
T_4 V_57 [ V_58 ] ;
V_32 = V_33 ;
if ( F_9 ( V_23 , - V_58 , V_59 , V_26 ) == - 1 )
{
* V_26 = F_10 ( V_23 , V_27 ) ;
if ( * V_26 == 0 )
* V_26 = V_60 ;
return FALSE ;
}
if ( ! F_5 ( V_23 , V_57 , V_58 , V_26 , V_27 ) )
return FALSE ;
memcpy ( V_25 -> V_61 . V_62 , V_57 , V_58 ) ;
return TRUE ;
}
static T_1
F_11 ( T_2 V_23 , union V_24 * V_25 ,
int * V_26 , T_3 * * V_27 )
{
T_4 V_63 [ V_64 ] ;
V_32 = V_33 ;
if ( ! F_5 ( V_23 , V_63 , V_64 , V_26 , V_27 ) )
return FALSE ;
if ( F_6 ( & V_63 [ V_65 ] ) != 0x0017 ) {
* V_26 = V_66 ;
if ( V_27 != NULL )
* V_27 = F_12 ( L_1 ) ;
return FALSE ;
}
V_25 -> V_67 . V_68 = F_6 ( & V_63 [ V_69 ] ) ;
return TRUE ;
}
static T_1
F_13 ( T_2 V_23 , union V_24 * V_25 , int * V_26 , T_3 * * V_27 )
{
T_4 V_70 [ V_71 ] ;
V_32 = V_33 ;
if ( ! F_5 ( V_23 , V_70 , V_71 , V_26 , V_27 ) )
return FALSE ;
V_25 -> V_72 . V_73 = V_70 [ V_74 ] ;
V_25 -> V_72 . V_75 = V_70 [ V_76 ] ;
V_25 -> V_72 . V_77 = F_6 ( & V_70 [ V_78 ] ) ;
return TRUE ;
}
static T_1
F_14 ( T_2 V_23 , union V_24 * V_25 ,
int * V_26 , T_3 * * V_27 )
{
T_4 V_79 [ V_80 ] ;
V_32 = V_33 ;
if ( ! F_5 ( V_23 , V_79 , V_80 , V_26 , V_27 ) )
return FALSE ;
if ( F_6 ( & V_79 [ V_81 ] ) != V_82 ) {
* V_26 = V_66 ;
if ( V_27 != NULL )
* V_27 = F_12 ( L_2 ) ;
return FALSE ;
}
V_25 -> V_83 . V_68 = F_6 ( & V_79 [ V_84 ] ) ;
V_25 -> V_83 . V_85 = ! ! V_79 [ V_86 + 0 ] ;
return TRUE ;
}
static T_1
F_15 ( T_2 V_23 , union V_24 * V_25 , int * V_26 , T_3 * * V_27 )
{
T_4 V_87 [ V_88 ] ;
V_32 = V_33 ;
if ( ! F_5 ( V_23 , V_87 , V_88 , V_26 , V_27 ) )
return FALSE ;
V_25 -> V_89 . V_90 = V_87 [ V_91 ] ;
V_25 -> V_89 . V_92 = V_87 [ V_93 ] ;
V_25 -> V_89 . V_94 = V_87 [ V_95 ] ;
V_25 -> V_89 . V_96 = V_87 [ V_97 ] ;
V_25 -> V_89 . V_98 = V_87 [ V_99 ] ;
return TRUE ;
}
static void
F_16 ( struct V_100 * V_57 , T_4 * V_101 ,
T_1 V_102 )
{
T_6 V_103 ;
struct V_104 * V_105 ;
struct V_106 * V_107 ;
T_7 V_108 , V_2 ;
V_103 = V_57 -> V_109 ;
if ( V_103 > V_57 -> V_110 )
V_103 = V_57 -> V_110 ;
V_105 = (struct V_104 * ) ( void * ) V_101 ;
F_17 ( & V_105 -> V_111 ) ;
F_18 ( & V_105 -> V_112 ) ;
F_17 ( & V_105 -> V_113 ) ;
F_19 ( & V_105 -> V_114 ) ;
F_19 ( & V_105 -> V_115 ) ;
F_19 ( & V_105 -> V_116 ) ;
F_19 ( & V_105 -> V_117 ) ;
if ( V_105 -> V_118 == V_119 ) {
F_19 ( & V_105 -> V_120 . V_121 . V_122 ) ;
F_19 ( & V_105 -> V_120 . V_121 . V_123 ) ;
}
if ( V_102 ) {
F_19 ( & V_105 -> V_124 ) ;
F_19 ( & V_105 -> V_125 ) ;
F_19 ( & V_105 -> V_126 ) ;
F_19 ( & V_105 -> V_127 ) ;
}
if ( V_105 -> V_118 == V_119 ) {
if ( V_102 ) {
V_107 = (struct V_106 * ) ( void * ) ( V_101 + 64 ) ;
} else {
V_107 = (struct V_106 * ) ( void * ) ( V_101 + 48 ) ;
}
V_108 = V_105 -> V_120 . V_121 . V_123 ;
for ( V_2 = 0 ; V_2 < V_108 ; V_2 ++ ) {
F_19 ( & V_107 -> V_128 ) ;
F_19 ( & V_107 -> V_129 ) ;
F_19 ( & V_107 -> V_130 ) ;
F_19 ( & V_107 -> V_131 ) ;
V_107 ++ ;
}
}
}
static void
F_20 ( struct V_100 * V_57 , T_4 * V_101 )
{
T_6 V_103 ;
T_4 * V_132 ;
struct V_133 * V_134 ;
struct V_135 * V_136 ;
T_6 V_137 ;
V_103 = V_57 -> V_109 ;
if ( V_103 > V_57 -> V_110 )
V_103 = V_57 -> V_110 ;
if ( V_103 < sizeof( struct V_133 ) ) {
return;
}
V_132 = V_101 ;
V_134 = (struct V_133 * ) V_101 ;
if ( ! ( V_134 -> V_138 ) == 0 ) {
return;
}
V_103 -= ( T_6 ) sizeof( struct V_133 ) ;
V_132 += sizeof( struct V_133 ) ;
while ( V_103 >= sizeof( struct V_135 ) ) {
V_136 = (struct V_135 * ) V_132 ;
F_21 ( ( T_4 * ) & V_136 -> V_139 ) ;
F_21 ( ( T_4 * ) & V_136 -> V_140 ) ;
V_137 = V_136 -> V_140 ;
if ( V_137 % 4 != 0 )
V_137 += 4 - V_137 % 4 ;
if ( V_137 < sizeof( struct V_135 ) ) {
return;
}
if ( V_103 < V_137 ) {
return;
}
V_103 -= V_137 ;
V_132 += V_137 ;
}
}
static T_1
F_22 ( T_2 V_23 ,
union V_24 * V_25 , int * V_26 , T_3 * * V_27 )
{
struct V_141 V_57 ;
V_32 = V_33 ;
if ( ! F_5 ( V_23 , & V_57 , sizeof ( struct V_141 ) ,
V_26 , V_27 ) )
return FALSE ;
V_25 -> V_142 . V_73 = ( ( F_23 ( V_57 . V_143 ) & V_144 ) == 0 ) ? TRUE : FALSE ;
return TRUE ;
}
static T_1
F_24 ( T_2 V_23 ,
union V_24 * V_25 , int * V_26 , T_3 * * V_27 )
{
struct V_145 V_57 ;
V_32 = V_33 ;
if ( ! F_5 ( V_23 , & V_57 , sizeof ( struct V_145 ) ,
V_26 , V_27 ) )
return FALSE ;
V_25 -> V_146 . V_147 = F_25 ( V_57 . V_147 ) ;
V_25 -> V_146 . V_148 = F_25 ( V_57 . V_148 ) ;
return TRUE ;
}
static T_1
F_26 ( T_2 V_23 ,
union V_24 * V_25 , int * V_26 , T_3 * * V_27 )
{
T_4 V_57 [ V_149 ] ;
V_32 = V_33 ;
if ( ! F_5 ( V_23 , V_57 , V_149 , V_26 , V_27 ) )
return FALSE ;
V_25 -> V_150 . V_151 = V_57 [ V_152 ] ;
V_25 -> V_150 . V_48 = V_57 [ V_153 ] ;
return TRUE ;
}
static T_1
F_27 ( T_2 V_23 ,
union V_24 * V_25 , int * V_26 , T_3 * * V_27 )
{
struct V_154 V_57 ;
V_32 = V_33 ;
if ( ! F_5 ( V_23 , & V_57 , sizeof ( struct V_154 ) ,
V_26 , V_27 ) )
return FALSE ;
V_25 -> V_142 . V_73 = ( V_57 . V_143 == V_155 ) ? TRUE : FALSE ;
return TRUE ;
}
static T_1
F_28 ( T_2 V_23 , struct V_100 * V_156 ,
union V_24 * V_25 , int * V_26 , T_3 * * V_27 )
{
T_4 V_157 [ sizeof( struct V_158 ) ] ;
V_32 = V_33 ;
if ( ! F_5 ( V_23 , V_157 , sizeof( struct V_158 ) , V_26 , V_27 ) )
return FALSE ;
V_25 -> erf . V_57 . V_159 = F_29 ( & V_157 [ 0 ] ) ;
V_25 -> erf . V_57 . type = V_157 [ 8 ] ;
V_25 -> erf . V_57 . V_48 = V_157 [ 9 ] ;
V_25 -> erf . V_57 . V_160 = F_6 ( & V_157 [ 10 ] ) ;
V_25 -> erf . V_57 . V_161 = F_6 ( & V_157 [ 12 ] ) ;
V_25 -> erf . V_57 . V_162 = F_6 ( & V_157 [ 14 ] ) ;
if ( V_156 ) {
T_8 V_159 = V_25 -> erf . V_57 . V_159 ;
V_156 -> V_159 . V_163 = ( V_164 ) ( V_159 >> 32 ) ;
V_159 = ( ( V_159 & 0xffffffff ) * 1000 * 1000 * 1000 ) ;
V_159 += ( V_159 & 0x80000000 ) << 1 ;
V_156 -> V_159 . V_165 = ( ( V_164 ) ( V_159 >> 32 ) ) ;
if ( V_156 -> V_159 . V_165 >= 1000000000 ) {
V_156 -> V_159 . V_165 -= 1000000000 ;
V_156 -> V_159 . V_163 += 1 ;
}
}
return TRUE ;
}
static T_1
F_30 ( T_2 V_23 , union V_24 * V_25 ,
int * V_26 , T_3 * * V_27 , T_6 * V_166 )
{
T_4 V_167 [ 8 ] ;
T_8 V_168 ;
int V_2 = 0 , V_169 = sizeof( V_25 -> erf . V_170 ) / sizeof( struct V_171 ) ;
T_4 type ;
* V_166 = 0 ;
if ( V_25 -> erf . V_57 . type & 0x80 ) {
do{
V_32 = V_33 ;
if ( ! F_5 ( V_23 , V_167 , 8 , V_26 , V_27 ) )
return FALSE ;
type = V_167 [ 0 ] ;
V_168 = F_31 ( V_167 ) ;
if ( V_2 < V_169 )
memcpy ( & V_25 -> erf . V_170 [ V_2 ] . V_172 , & V_168 , sizeof( V_168 ) ) ;
* V_166 += 8 ;
V_2 ++ ;
} while ( type & 0x80 );
}
return TRUE ;
}
static T_1
F_32 ( T_2 V_23 , union V_24 * V_25 ,
int * V_26 , T_3 * * V_27 , T_6 * V_166 )
{
T_4 V_173 [ sizeof( union V_173 ) ] ;
* V_166 = 0 ;
switch( V_25 -> erf . V_57 . type & 0x7F ) {
case V_174 :
case V_175 :
case V_176 :
case V_177 :
case V_178 :
case V_179 :
case V_180 :
V_32 = V_33 ;
if ( ! F_5 ( V_23 , V_173 , sizeof( V_181 ) , V_26 , V_27 ) )
return FALSE ;
V_25 -> erf . V_182 . V_183 = F_33 ( & V_173 [ 0 ] ) ;
* V_166 = sizeof( V_181 ) ;
break;
case V_184 :
case V_185 :
case V_186 :
V_32 = V_33 ;
if ( ! F_5 ( V_23 , V_173 , sizeof( V_187 ) , V_26 , V_27 ) )
return FALSE ;
V_25 -> erf . V_182 . V_188 = F_6 ( & V_173 [ 0 ] ) ;
* V_166 = sizeof( V_187 ) ;
break;
default:
break;
}
return TRUE ;
}
static T_1
F_34 ( T_2 V_23 , union V_24 * V_25 , int * V_26 , T_3 * * V_27 )
{
struct V_189 V_190 ;
V_32 = V_33 ;
if ( ! F_5 ( V_23 , & V_190 , sizeof ( V_190 ) , V_26 , V_27 ) )
return FALSE ;
V_25 -> V_191 . V_192 = V_190 . V_193 & 0x80 ? 1 : 0 ;
V_25 -> V_191 . V_193 = V_190 . V_193 & 0x7f ;
V_25 -> V_191 . V_48 = F_33 ( & V_190 . V_48 ) ;
return TRUE ;
}
int
F_35 ( T_2 V_23 , int V_194 , int V_195 ,
T_6 V_103 , T_1 V_196 ,
struct V_100 * V_57 , int * V_26 , T_3 * * V_27 )
{
int V_197 = 0 ;
T_6 V_137 ;
switch ( V_195 ) {
case V_13 :
if ( V_194 == V_198 ) {
if ( V_196 && V_103 < V_53 ) {
* V_26 = V_66 ;
* V_27 = F_36 ( L_3 ,
V_103 ) ;
return - 1 ;
}
if ( ! F_7 ( V_23 ,
& V_57 -> V_25 , V_26 , V_27 ) )
return - 1 ;
V_197 = V_53 ;
} else {
if ( V_196 && V_103 < V_29 ) {
* V_26 = V_66 ;
* V_27 = F_36 ( L_4 ,
V_103 ) ;
return - 1 ;
}
if ( ! F_4 ( V_23 ,
& V_57 -> V_25 , V_26 , V_27 ) )
return - 1 ;
V_197 = V_29 ;
}
break;
case V_199 :
if ( V_194 == V_198 ) {
if ( ! F_8 ( V_23 , & V_57 -> V_25 , V_26 , V_27 ) )
return - 1 ;
}
V_57 -> V_25 . V_200 . V_201 = - 1 ;
break;
case V_202 :
case V_203 :
case V_204 :
case V_205 :
V_57 -> V_25 . V_206 . V_201 = - 1 ;
V_57 -> V_25 . V_206 . V_207 = FALSE ;
V_57 -> V_25 . V_206 . V_47 = 0 ;
V_57 -> V_25 . V_206 . V_208 = 0 ;
V_57 -> V_25 . V_206 . V_209 = 0 ;
break;
case V_14 :
if ( V_196 && V_103 < V_64 ) {
* V_26 = V_66 ;
* V_27 = F_36 ( L_5 ,
V_103 ) ;
return - 1 ;
}
if ( ! F_11 ( V_23 , & V_57 -> V_25 ,
V_26 , V_27 ) )
return - 1 ;
V_197 = V_64 ;
break;
case V_15 :
if ( V_196 && V_103 < V_71 ) {
* V_26 = V_66 ;
* V_27 = F_36 ( L_6 ,
V_103 ) ;
return - 1 ;
}
if ( ! F_13 ( V_23 , & V_57 -> V_25 ,
V_26 , V_27 ) )
return - 1 ;
V_197 = V_71 ;
break;
case V_16 :
if ( V_196 && V_103 < V_80 ) {
* V_26 = V_66 ;
* V_27 = F_36 ( L_7 ,
V_103 ) ;
return - 1 ;
}
if ( ! F_14 ( V_23 , & V_57 -> V_25 ,
V_26 , V_27 ) )
return - 1 ;
V_197 = V_80 ;
break;
case V_17 :
if ( V_196 && V_103 < V_88 ) {
* V_26 = V_66 ;
* V_27 = F_36 ( L_8 ,
V_103 ) ;
return - 1 ;
}
if ( ! F_15 ( V_23 , & V_57 -> V_25 ,
V_26 , V_27 ) )
return - 1 ;
V_197 = V_88 ;
break;
case V_210 :
V_57 -> V_25 . V_142 . V_73 = FALSE ;
break;
case V_20 :
if ( V_196 &&
V_103 < sizeof ( struct V_141 ) ) {
* V_26 = V_66 ;
* V_27 = F_36 ( L_9 ,
V_103 ) ;
return - 1 ;
}
if ( ! F_22 ( V_23 ,
& V_57 -> V_25 , V_26 , V_27 ) )
return - 1 ;
V_197 = ( int ) sizeof ( struct V_141 ) ;
break;
case V_21 :
if ( V_196 &&
V_103 < sizeof ( struct V_145 ) ) {
* V_26 = V_66 ;
* V_27 = F_36 ( L_10 ,
V_103 ) ;
return - 1 ;
}
if ( ! F_24 ( V_23 ,
& V_57 -> V_25 , V_26 , V_27 ) )
return - 1 ;
V_197 = ( int ) sizeof ( struct V_145 ) ;
break;
case V_211 :
if ( V_196 && V_103 < V_149 ) {
* V_26 = V_66 ;
* V_27 = F_36 ( L_11 ) ;
return - 1 ;
}
if ( ! F_26 ( V_23 , & V_57 -> V_25 , V_26 , V_27 ) )
return - 1 ;
V_197 = V_149 ;
break;
case V_22 :
if ( V_196 &&
V_103 < sizeof ( struct V_154 ) ) {
* V_26 = V_66 ;
* V_27 = F_36 ( L_12 ,
V_103 ) ;
return - 1 ;
}
if ( ! F_27 ( V_23 ,
& V_57 -> V_25 , V_26 , V_27 ) )
return - 1 ;
V_197 = ( int ) sizeof ( struct V_154 ) ;
break;
case V_18 :
if ( V_196 &&
V_103 < sizeof( struct V_158 ) ) {
* V_26 = V_66 ;
* V_27 = F_36 ( L_13 ,
V_103 ) ;
return - 1 ;
}
if ( ! F_28 ( V_23 , V_57 , & V_57 -> V_25 ,
V_26 , V_27 ) )
return - 1 ;
V_197 = ( int ) sizeof( struct V_158 ) ;
if ( ! F_30 ( V_23 , & V_57 -> V_25 , V_26 , V_27 ,
& V_137 ) )
return - 1 ;
V_197 += V_137 ;
if ( ! F_32 ( V_23 , & V_57 -> V_25 , V_26 , V_27 ,
& V_137 ) )
return - 1 ;
V_197 += V_137 ;
if ( V_196 &&
V_103 < ( T_6 ) V_197 ) {
* V_26 = V_66 ;
* V_27 = F_36 ( L_14 ,
V_103 , V_197 ) ;
return - 1 ;
}
break;
case V_19 :
if ( V_196 &&
V_103 < sizeof ( struct V_189 ) ) {
* V_26 = V_66 ;
* V_27 = F_36 ( L_15 ,
V_103 ) ;
return - 1 ;
}
if ( ! F_34 ( V_23 , & V_57 -> V_25 ,
V_26 , V_27 ) )
return - 1 ;
V_197 = ( int ) sizeof ( struct V_189 ) ;
break;
}
return V_197 ;
}
void
F_37 ( int V_194 , int V_195 ,
struct V_100 * V_57 , T_4 * V_101 , T_1 V_212 , int V_201 )
{
switch ( V_195 ) {
case V_13 :
if ( V_194 == V_198 ) {
F_38 ( V_57 , V_101 ) ;
} else {
if ( V_57 -> V_25 . V_37 . type == V_40 )
F_39 ( V_57 , V_101 ) ;
}
break;
case V_199 :
V_57 -> V_25 . V_200 . V_201 = V_201 ;
break;
case V_213 :
if ( V_212 )
F_16 ( V_57 , V_101 , FALSE ) ;
break;
case V_214 :
if ( V_212 )
F_16 ( V_57 , V_101 , TRUE ) ;
break;
case V_215 :
V_57 -> V_25 . V_200 . V_201 = 4 ;
break;
case V_216 :
if ( V_212 )
F_20 ( V_57 , V_101 ) ;
break;
default:
break;
}
}
int
F_40 ( int V_1 , const union V_24 * V_25 )
{
int V_217 ;
switch ( V_1 ) {
case V_13 :
V_217 = V_29 ;
break;
case V_14 :
V_217 = V_64 ;
break;
case V_15 :
V_217 = V_71 ;
break;
case V_16 :
V_217 = V_80 ;
break;
case V_17 :
V_217 = V_88 ;
break;
case V_18 :
V_217 = ( int ) sizeof ( struct V_158 ) ;
switch ( V_25 -> erf . V_57 . type & 0x7F ) {
case V_174 :
case V_175 :
case V_176 :
case V_177 :
case V_178 :
case V_179 :
case V_180 :
V_217 += ( int ) sizeof( struct V_218 ) ;
break;
case V_184 :
case V_185 :
case V_186 :
V_217 += ( int ) sizeof( struct V_219 ) ;
break;
default:
break;
}
if ( V_25 -> erf . V_57 . type & 0x80 ) {
int V_2 = 0 , V_169 = sizeof( V_25 -> erf . V_170 ) / sizeof( struct V_171 ) ;
T_4 V_167 [ 8 ] ;
T_4 type ;
do {
F_41 ( V_167 , V_25 -> erf . V_170 [ V_2 ] . V_172 ) ;
type = V_167 [ 0 ] ;
V_217 += 8 ;
V_2 ++ ;
} while ( type & 0x80 && V_2 < V_169 );
}
break;
case V_19 :
V_217 = ( int ) sizeof ( struct V_189 ) ;
break;
case V_20 :
V_217 = ( int ) sizeof ( struct V_141 ) ;
break;
case V_22 :
V_217 = ( int ) sizeof ( struct V_154 ) ;
break;
case V_21 :
V_217 = ( int ) sizeof ( struct V_145 ) ;
break;
default:
V_217 = 0 ;
break;
}
return V_217 ;
}
T_1
F_42 ( T_9 * V_220 , int V_1 , const union V_24 * V_25 ,
int * V_26 )
{
T_4 V_221 [ V_29 ] ;
T_4 V_222 [ V_64 ] ;
T_4 V_223 [ V_80 ] ;
T_4 V_70 [ V_71 ] ;
T_4 V_224 [ V_88 ] ;
T_4 V_157 [ sizeof( struct V_225 ) ] ;
struct V_189 V_190 ;
struct V_141 V_226 ;
struct V_145 V_227 ;
struct V_154 V_228 ;
T_10 V_137 ;
switch ( V_1 ) {
case V_13 :
V_221 [ V_36 ] =
( V_25 -> V_37 . V_47 == 0 ) ? 0x80 : 0x00 ;
switch ( V_25 -> V_37 . V_38 ) {
case V_43 :
V_221 [ V_36 ] |= 0x06 ;
break;
case V_39 :
switch ( V_25 -> V_37 . type ) {
case V_40 :
V_221 [ V_36 ] |= 0x01 ;
break;
case V_41 :
V_221 [ V_36 ] |= 0x02 ;
break;
case V_42 :
V_221 [ V_36 ] |= 0x05 ;
break;
}
break;
}
V_221 [ V_34 ] = ( T_4 ) V_25 -> V_37 . V_30 ;
F_43 ( & V_221 [ V_35 ] , V_25 -> V_37 . V_31 ) ;
if ( ! F_44 ( V_220 , V_221 , sizeof( V_221 ) , V_26 ) )
return FALSE ;
V_220 -> V_229 += sizeof( V_221 ) ;
break;
case V_14 :
memset ( V_222 , 0 , sizeof( V_222 ) ) ;
F_43 ( & V_222 [ V_69 ] ,
V_25 -> V_67 . V_68 ) ;
F_43 ( & V_222 [ V_65 ] , 0x0017 ) ;
if ( ! F_44 ( V_220 , V_222 , sizeof( V_222 ) , V_26 ) )
return FALSE ;
V_220 -> V_229 += sizeof( V_222 ) ;
break;
case V_15 :
memset ( & V_70 , 0 , sizeof( V_70 ) ) ;
V_70 [ V_74 ] = V_25 -> V_72 . V_73 ;
V_70 [ V_76 ] = V_25 -> V_72 . V_75 ;
F_43 ( & V_70 [ V_78 ] ,
V_25 -> V_72 . V_77 ) ;
if ( ! F_44 ( V_220 , V_70 , sizeof( V_70 ) , V_26 ) )
return FALSE ;
V_220 -> V_229 += sizeof( V_70 ) ;
break;
case V_16 :
memset ( & V_223 , 0 , sizeof( V_223 ) ) ;
F_43 ( & V_223 [ V_84 ] ,
V_25 -> V_83 . V_68 ) ;
F_43 ( & V_223 [ V_81 ] , V_82 ) ;
V_223 [ V_86 + 0 ] =
V_25 -> V_83 . V_85 ? 0x01 : 0x00 ;
if ( ! F_44 ( V_220 , V_223 , sizeof( V_223 ) , V_26 ) )
return FALSE ;
V_220 -> V_229 += sizeof( V_223 ) ;
break;
case V_17 :
memset ( & V_224 , 0 , sizeof( V_224 ) ) ;
V_224 [ V_91 ] = V_25 -> V_89 . V_90 ;
V_224 [ V_93 ] = V_25 -> V_89 . V_92 ;
V_224 [ V_95 ] = V_25 -> V_89 . V_94 ;
V_224 [ V_97 ] = V_25 -> V_89 . V_96 ;
V_224 [ V_99 ] = V_25 -> V_89 . V_98 ;
if ( ! F_44 ( V_220 , V_224 , sizeof( V_224 ) , V_26 ) )
return FALSE ;
V_220 -> V_229 += sizeof( V_224 ) ;
break;
case V_18 :
memset ( & V_157 , 0 , sizeof( V_157 ) ) ;
F_45 ( & V_157 [ 0 ] , V_25 -> erf . V_57 . V_159 ) ;
V_157 [ 8 ] = V_25 -> erf . V_57 . type ;
V_157 [ 9 ] = V_25 -> erf . V_57 . V_48 ;
F_43 ( & V_157 [ 10 ] , V_25 -> erf . V_57 . V_160 ) ;
F_43 ( & V_157 [ 12 ] , V_25 -> erf . V_57 . V_161 ) ;
F_43 ( & V_157 [ 14 ] , V_25 -> erf . V_57 . V_162 ) ;
V_137 = sizeof( struct V_158 ) ;
switch( V_25 -> erf . V_57 . type & 0x7F ) {
case V_174 :
case V_175 :
case V_176 :
case V_177 :
case V_178 :
case V_179 :
case V_180 :
F_46 ( & V_157 [ 16 ] , V_25 -> erf . V_182 . V_183 ) ;
V_137 += ( int ) sizeof( struct V_218 ) ;
break;
case V_184 :
case V_185 :
case V_186 :
F_43 ( & V_157 [ 16 ] , V_25 -> erf . V_182 . V_188 ) ;
V_137 += ( int ) sizeof( struct V_219 ) ;
break;
default:
break;
}
if ( ! F_44 ( V_220 , V_157 , V_137 , V_26 ) )
return FALSE ;
V_220 -> V_229 += V_137 ;
if ( V_25 -> erf . V_57 . type & 0x80 ) {
int V_2 = 0 , V_169 = sizeof( V_25 -> erf . V_170 ) / sizeof( struct V_171 ) ;
T_4 V_167 [ 8 ] ;
T_4 type ;
do {
F_41 ( V_167 , V_25 -> erf . V_170 [ V_2 ] . V_172 ) ;
type = V_167 [ 0 ] ;
if ( ! F_44 ( V_220 , V_167 , 8 , V_26 ) )
return FALSE ;
V_220 -> V_229 += 8 ;
V_2 ++ ;
} while ( type & 0x80 && V_2 < V_169 );
}
break;
case V_19 :
memset ( & V_190 , 0 , sizeof( V_190 ) ) ;
V_190 . V_193 = V_25 -> V_191 . V_193 |
( V_25 -> V_191 . V_192 ? 0x80 : 0x00 ) ;
F_46 ( ( T_4 * ) & V_190 . V_48 , V_25 -> V_191 . V_48 ) ;
if ( ! F_44 ( V_220 , & V_190 , sizeof( V_190 ) , V_26 ) )
return FALSE ;
V_220 -> V_229 += sizeof( V_190 ) ;
break;
case V_20 :
V_226 . V_143 = F_47 ( V_25 -> V_142 . V_73 ? V_230 : V_144 ) ;
if ( ! F_44 ( V_220 , & V_226 , sizeof V_226 , V_26 ) )
return FALSE ;
V_220 -> V_229 += sizeof V_226 ;
break;
case V_21 :
V_227 . V_147 = F_48 ( V_25 -> V_146 . V_147 ) ;
V_227 . V_148 = F_48 ( V_25 -> V_146 . V_148 ) ;
if ( ! F_44 ( V_220 , & V_227 , sizeof V_227 , V_26 ) )
return FALSE ;
V_220 -> V_229 += sizeof V_227 ;
break;
case V_22 :
V_228 . V_143 = ( V_25 -> V_142 . V_73 ? V_155 : V_231 ) ;
if ( ! F_44 ( V_220 , & V_228 , sizeof V_228 , V_26 ) )
return FALSE ;
V_220 -> V_229 += sizeof V_228 ;
break;
}
return TRUE ;
}
