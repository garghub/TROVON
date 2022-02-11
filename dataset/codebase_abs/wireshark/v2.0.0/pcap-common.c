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
if ( ! F_5 ( V_23 , V_28 , V_29 , V_26 , V_27 ) )
return FALSE ;
V_30 = V_28 [ V_32 ] ;
V_31 = F_6 ( & V_28 [ V_33 ] ) ;
switch ( V_28 [ V_34 ] & 0x0F ) {
case 0x01 :
V_25 -> V_35 . V_36 = V_37 ;
V_25 -> V_35 . type = V_38 ;
break;
case 0x02 :
V_25 -> V_35 . V_36 = V_37 ;
V_25 -> V_35 . type = V_39 ;
break;
case 0x05 :
V_25 -> V_35 . V_36 = V_37 ;
V_25 -> V_35 . type = V_40 ;
break;
case 0x06 :
V_25 -> V_35 . V_36 = V_41 ;
V_25 -> V_35 . type = V_42 ;
break;
case 0x03 :
V_25 -> V_35 . V_36 = V_37 ;
V_25 -> V_35 . type = V_42 ;
break;
case 0x04 :
V_25 -> V_35 . V_36 = V_37 ;
V_25 -> V_35 . type = V_42 ;
break;
default:
if ( V_30 == 0 && V_31 == 5 )
V_25 -> V_35 . V_36 = V_41 ;
else
V_25 -> V_35 . V_36 = V_37 ;
V_25 -> V_35 . type = V_42 ;
break;
}
V_25 -> V_35 . V_43 = V_44 ;
V_25 -> V_35 . V_30 = V_30 ;
V_25 -> V_35 . V_31 = V_31 ;
V_25 -> V_35 . V_45 = ( V_28 [ V_34 ] & 0x80 ) ? 0 : 1 ;
V_25 -> V_35 . V_46 = 0 ;
V_25 -> V_35 . V_47 = 0 ;
V_25 -> V_35 . V_48 = 0 ;
V_25 -> V_35 . V_49 = 0 ;
V_25 -> V_35 . V_50 = 0 ;
return TRUE ;
}
static T_1
F_7 ( T_2 V_23 ,
union V_24 * V_25 , int * V_26 , T_3 * * V_27 )
{
T_4 V_28 [ V_51 ] ;
T_4 V_30 ;
T_5 V_31 ;
if ( ! F_5 ( V_23 , V_28 , V_51 , V_26 , V_27 ) )
return FALSE ;
V_30 = V_28 [ V_52 ] ;
V_31 = F_6 ( & V_28 [ V_53 ] ) ;
V_25 -> V_35 . V_30 = V_30 ;
V_25 -> V_35 . V_31 = V_31 ;
V_25 -> V_35 . V_45 = ( V_28 [ V_54 ] & 0x80 ) ? 0 : 1 ;
V_25 -> V_35 . V_46 = 0 ;
V_25 -> V_35 . V_47 = 0 ;
V_25 -> V_35 . V_48 = 0 ;
V_25 -> V_35 . V_49 = 0 ;
V_25 -> V_35 . V_50 = 0 ;
return TRUE ;
}
static T_1
F_8 ( T_2 V_23 ,
union V_24 * V_25 , int * V_26 , T_3 * * V_27 )
{
T_4 V_55 [ V_56 ] ;
if ( F_9 ( V_23 , - V_56 , V_57 , V_26 ) == - 1 )
{
* V_26 = F_10 ( V_23 , V_27 ) ;
if ( * V_26 == 0 )
* V_26 = V_58 ;
return FALSE ;
}
if ( ! F_5 ( V_23 , V_55 , V_56 , V_26 , V_27 ) )
return FALSE ;
memcpy ( V_25 -> V_59 . V_60 , V_55 , V_56 ) ;
return TRUE ;
}
static T_1
F_11 ( T_2 V_23 , union V_24 * V_25 ,
int * V_26 , T_3 * * V_27 )
{
T_4 V_61 [ V_62 ] ;
if ( ! F_5 ( V_23 , V_61 , V_62 , V_26 , V_27 ) )
return FALSE ;
if ( F_6 ( & V_61 [ V_63 ] ) != 0x0017 ) {
* V_26 = V_64 ;
if ( V_27 != NULL )
* V_27 = F_12 ( L_1 ) ;
return FALSE ;
}
V_25 -> V_65 . V_66 = F_6 ( & V_61 [ V_67 ] ) ;
return TRUE ;
}
static T_1
F_13 ( T_2 V_23 , union V_24 * V_25 , int * V_26 , T_3 * * V_27 )
{
T_4 V_68 [ V_69 ] ;
if ( ! F_5 ( V_23 , V_68 , V_69 , V_26 , V_27 ) )
return FALSE ;
V_25 -> V_70 . V_71 = V_68 [ V_72 ] ;
V_25 -> V_70 . V_73 = V_68 [ V_74 ] ;
V_25 -> V_70 . V_75 = F_6 ( & V_68 [ V_76 ] ) ;
return TRUE ;
}
static T_1
F_14 ( T_2 V_23 , union V_24 * V_25 ,
int * V_26 , T_3 * * V_27 )
{
T_4 V_77 [ V_78 ] ;
if ( ! F_5 ( V_23 , V_77 , V_78 , V_26 , V_27 ) )
return FALSE ;
if ( F_6 ( & V_77 [ V_79 ] ) != V_80 ) {
* V_26 = V_64 ;
if ( V_27 != NULL )
* V_27 = F_12 ( L_2 ) ;
return FALSE ;
}
V_25 -> V_81 . V_66 = F_6 ( & V_77 [ V_82 ] ) ;
V_25 -> V_81 . V_83 = ! ! V_77 [ V_84 + 0 ] ;
return TRUE ;
}
static T_1
F_15 ( T_2 V_23 , union V_24 * V_25 , int * V_26 , T_3 * * V_27 )
{
T_4 V_85 [ V_86 ] ;
if ( ! F_5 ( V_23 , V_85 , V_86 , V_26 , V_27 ) )
return FALSE ;
V_25 -> V_87 . V_88 = V_85 [ V_89 ] ;
V_25 -> V_87 . V_90 = V_85 [ V_91 ] ;
V_25 -> V_87 . V_92 = V_85 [ V_93 ] ;
V_25 -> V_87 . V_94 = V_85 [ V_95 ] ;
V_25 -> V_87 . V_96 = V_85 [ V_97 ] ;
return TRUE ;
}
static void
F_16 ( struct V_98 * V_55 , T_4 * V_99 ,
T_1 V_100 )
{
T_6 V_101 ;
struct V_102 * V_103 ;
struct V_104 * V_105 ;
T_7 V_106 , V_2 ;
V_101 = V_55 -> V_107 ;
if ( V_101 > V_55 -> V_108 )
V_101 = V_55 -> V_108 ;
V_103 = (struct V_102 * ) ( void * ) V_99 ;
F_17 ( & V_103 -> V_109 ) ;
F_18 ( & V_103 -> V_110 ) ;
F_17 ( & V_103 -> V_111 ) ;
F_19 ( & V_103 -> V_112 ) ;
F_19 ( & V_103 -> V_113 ) ;
F_19 ( & V_103 -> V_114 ) ;
F_19 ( & V_103 -> V_115 ) ;
if ( V_103 -> V_116 == V_117 ) {
F_19 ( & V_103 -> V_118 . V_119 . V_120 ) ;
F_19 ( & V_103 -> V_118 . V_119 . V_121 ) ;
}
if ( V_100 ) {
F_19 ( & V_103 -> V_122 ) ;
F_19 ( & V_103 -> V_123 ) ;
F_19 ( & V_103 -> V_124 ) ;
F_19 ( & V_103 -> V_125 ) ;
}
if ( V_103 -> V_116 == V_117 ) {
if ( V_100 ) {
V_105 = (struct V_104 * ) ( void * ) ( V_99 + 64 ) ;
} else {
V_105 = (struct V_104 * ) ( void * ) ( V_99 + 48 ) ;
}
V_106 = V_103 -> V_118 . V_119 . V_121 ;
for ( V_2 = 0 ; V_2 < V_106 ; V_2 ++ ) {
F_19 ( & V_105 -> V_126 ) ;
F_19 ( & V_105 -> V_127 ) ;
F_19 ( & V_105 -> V_128 ) ;
F_19 ( & V_105 -> V_129 ) ;
V_105 ++ ;
}
}
}
static void
F_20 ( struct V_98 * V_55 , T_4 * V_99 )
{
T_6 V_101 ;
T_4 * V_130 ;
struct V_131 * V_132 ;
struct V_133 * V_134 ;
T_6 V_135 ;
V_101 = V_55 -> V_107 ;
if ( V_101 > V_55 -> V_108 )
V_101 = V_55 -> V_108 ;
if ( V_101 < sizeof( struct V_131 ) ) {
return;
}
V_130 = V_99 ;
V_132 = (struct V_131 * ) V_99 ;
if ( V_132 -> V_136 != 0 ) {
return;
}
V_101 -= ( T_6 ) sizeof( struct V_131 ) ;
V_130 += sizeof( struct V_131 ) ;
while ( V_101 >= sizeof( struct V_133 ) ) {
V_134 = (struct V_133 * ) V_130 ;
F_21 ( ( T_4 * ) & V_134 -> V_137 ) ;
F_21 ( ( T_4 * ) & V_134 -> V_138 ) ;
V_135 = V_134 -> V_138 ;
if ( V_135 % 4 != 0 )
V_135 += 4 - V_135 % 4 ;
if ( V_135 < sizeof( struct V_133 ) ) {
return;
}
if ( V_101 < V_135 ) {
return;
}
V_101 -= V_135 ;
V_130 += V_135 ;
}
}
static T_1
F_22 ( T_2 V_23 ,
union V_24 * V_25 , int * V_26 , T_3 * * V_27 )
{
struct V_139 V_55 ;
if ( ! F_5 ( V_23 , & V_55 , sizeof ( struct V_139 ) ,
V_26 , V_27 ) )
return FALSE ;
V_25 -> V_140 . V_71 = ( ( F_23 ( V_55 . V_141 ) & V_142 ) == 0 ) ? TRUE : FALSE ;
return TRUE ;
}
static T_1
F_24 ( T_2 V_23 ,
union V_24 * V_25 , int * V_26 , T_3 * * V_27 )
{
struct V_143 V_55 ;
if ( ! F_5 ( V_23 , & V_55 , sizeof ( struct V_143 ) ,
V_26 , V_27 ) )
return FALSE ;
V_25 -> V_144 . V_145 = F_25 ( V_55 . V_145 ) ;
V_25 -> V_144 . V_146 = F_25 ( V_55 . V_146 ) ;
return TRUE ;
}
static T_1
F_26 ( T_2 V_23 ,
union V_24 * V_25 , int * V_26 , T_3 * * V_27 )
{
T_4 V_55 [ V_147 ] ;
if ( ! F_5 ( V_23 , V_55 , V_147 , V_26 , V_27 ) )
return FALSE ;
V_25 -> V_148 . V_149 = V_55 [ V_150 ] ;
V_25 -> V_148 . V_46 = V_55 [ V_151 ] ;
return TRUE ;
}
static T_1
F_27 ( T_2 V_23 ,
union V_24 * V_25 , int * V_26 , T_3 * * V_27 )
{
struct V_152 V_55 ;
if ( ! F_5 ( V_23 , & V_55 , sizeof ( struct V_152 ) ,
V_26 , V_27 ) )
return FALSE ;
V_25 -> V_140 . V_71 = ( V_55 . V_141 == V_153 ) ? TRUE : FALSE ;
return TRUE ;
}
static T_1
F_28 ( T_2 V_23 , struct V_98 * V_154 ,
union V_24 * V_25 , int * V_26 , T_3 * * V_27 )
{
T_4 V_155 [ sizeof( struct V_156 ) ] ;
if ( ! F_5 ( V_23 , V_155 , sizeof( struct V_156 ) , V_26 , V_27 ) )
return FALSE ;
V_25 -> erf . V_55 . V_157 = F_29 ( & V_155 [ 0 ] ) ;
V_25 -> erf . V_55 . type = V_155 [ 8 ] ;
V_25 -> erf . V_55 . V_46 = V_155 [ 9 ] ;
V_25 -> erf . V_55 . V_158 = F_6 ( & V_155 [ 10 ] ) ;
V_25 -> erf . V_55 . V_159 = F_6 ( & V_155 [ 12 ] ) ;
V_25 -> erf . V_55 . V_160 = F_6 ( & V_155 [ 14 ] ) ;
if ( V_154 ) {
T_8 V_157 = V_25 -> erf . V_55 . V_157 ;
V_154 -> V_157 . V_161 = ( V_162 ) ( V_157 >> 32 ) ;
V_157 = ( ( V_157 & 0xffffffff ) * 1000 * 1000 * 1000 ) ;
V_157 += ( V_157 & 0x80000000 ) << 1 ;
V_154 -> V_157 . V_163 = ( ( V_162 ) ( V_157 >> 32 ) ) ;
if ( V_154 -> V_157 . V_163 >= 1000000000 ) {
V_154 -> V_157 . V_163 -= 1000000000 ;
V_154 -> V_157 . V_161 += 1 ;
}
}
return TRUE ;
}
static T_1
F_30 ( T_2 V_23 , union V_24 * V_25 ,
int * V_26 , T_3 * * V_27 , T_6 * V_164 )
{
T_4 V_165 [ 8 ] ;
T_8 V_166 ;
int V_2 = 0 , V_167 = sizeof( V_25 -> erf . V_168 ) / sizeof( struct V_169 ) ;
T_4 type ;
* V_164 = 0 ;
if ( V_25 -> erf . V_55 . type & 0x80 ) {
do{
if ( ! F_5 ( V_23 , V_165 , 8 , V_26 , V_27 ) )
return FALSE ;
type = V_165 [ 0 ] ;
V_166 = F_31 ( V_165 ) ;
if ( V_2 < V_167 )
memcpy ( & V_25 -> erf . V_168 [ V_2 ] . V_170 , & V_166 , sizeof( V_166 ) ) ;
* V_164 += 8 ;
V_2 ++ ;
} while ( type & 0x80 );
}
return TRUE ;
}
static T_1
F_32 ( T_2 V_23 , union V_24 * V_25 ,
int * V_26 , T_3 * * V_27 , T_6 * V_164 )
{
T_4 V_171 [ sizeof( union V_171 ) ] ;
* V_164 = 0 ;
switch( V_25 -> erf . V_55 . type & 0x7F ) {
case V_172 :
case V_173 :
case V_174 :
case V_175 :
case V_176 :
case V_177 :
case V_178 :
if ( ! F_5 ( V_23 , V_171 , sizeof( V_179 ) , V_26 , V_27 ) )
return FALSE ;
V_25 -> erf . V_180 . V_181 = F_33 ( & V_171 [ 0 ] ) ;
* V_164 = sizeof( V_179 ) ;
break;
case V_182 :
case V_183 :
case V_184 :
if ( ! F_5 ( V_23 , V_171 , sizeof( V_185 ) , V_26 , V_27 ) )
return FALSE ;
V_25 -> erf . V_180 . V_186 = F_6 ( & V_171 [ 0 ] ) ;
* V_164 = sizeof( V_185 ) ;
break;
default:
break;
}
return TRUE ;
}
static T_1
F_34 ( T_2 V_23 , union V_24 * V_25 , int * V_26 , T_3 * * V_27 )
{
struct V_187 V_188 ;
if ( ! F_5 ( V_23 , & V_188 , sizeof ( V_188 ) , V_26 , V_27 ) )
return FALSE ;
V_25 -> V_189 . V_190 = V_188 . V_191 & 0x80 ? 1 : 0 ;
V_25 -> V_189 . V_191 = V_188 . V_191 & 0x7f ;
V_25 -> V_189 . V_46 = F_33 ( & V_188 . V_46 ) ;
return TRUE ;
}
int
F_35 ( T_2 V_23 , int V_192 , int V_193 ,
T_6 V_101 , T_1 V_194 ,
struct V_98 * V_55 , int * V_26 , T_3 * * V_27 )
{
int V_195 = 0 ;
T_6 V_135 ;
V_55 -> V_196 = V_193 ;
switch ( V_193 ) {
case V_13 :
if ( V_192 == V_197 ) {
if ( V_194 && V_101 < V_51 ) {
* V_26 = V_64 ;
* V_27 = F_36 ( L_3 ,
V_101 ) ;
return - 1 ;
}
if ( ! F_7 ( V_23 ,
& V_55 -> V_25 , V_26 , V_27 ) )
return - 1 ;
V_195 = V_51 ;
} else {
if ( V_194 && V_101 < V_29 ) {
* V_26 = V_64 ;
* V_27 = F_36 ( L_4 ,
V_101 ) ;
return - 1 ;
}
if ( ! F_4 ( V_23 ,
& V_55 -> V_25 , V_26 , V_27 ) )
return - 1 ;
V_195 = V_29 ;
}
break;
case V_198 :
if ( V_192 == V_197 ) {
if ( ! F_8 ( V_23 , & V_55 -> V_25 , V_26 , V_27 ) )
return - 1 ;
}
V_55 -> V_25 . V_199 . V_200 = - 1 ;
break;
case V_201 :
case V_202 :
case V_203 :
case V_204 :
V_55 -> V_25 . V_205 . V_200 = - 1 ;
V_55 -> V_25 . V_205 . V_206 = FALSE ;
V_55 -> V_25 . V_205 . V_207 = FALSE ;
V_55 -> V_25 . V_205 . V_208 = 0 ;
break;
case V_14 :
if ( V_194 && V_101 < V_62 ) {
* V_26 = V_64 ;
* V_27 = F_36 ( L_5 ,
V_101 ) ;
return - 1 ;
}
if ( ! F_11 ( V_23 , & V_55 -> V_25 ,
V_26 , V_27 ) )
return - 1 ;
V_195 = V_62 ;
break;
case V_15 :
if ( V_194 && V_101 < V_69 ) {
* V_26 = V_64 ;
* V_27 = F_36 ( L_6 ,
V_101 ) ;
return - 1 ;
}
if ( ! F_13 ( V_23 , & V_55 -> V_25 ,
V_26 , V_27 ) )
return - 1 ;
V_195 = V_69 ;
break;
case V_16 :
if ( V_194 && V_101 < V_78 ) {
* V_26 = V_64 ;
* V_27 = F_36 ( L_7 ,
V_101 ) ;
return - 1 ;
}
if ( ! F_14 ( V_23 , & V_55 -> V_25 ,
V_26 , V_27 ) )
return - 1 ;
V_195 = V_78 ;
break;
case V_17 :
if ( V_194 && V_101 < V_86 ) {
* V_26 = V_64 ;
* V_27 = F_36 ( L_8 ,
V_101 ) ;
return - 1 ;
}
if ( ! F_15 ( V_23 , & V_55 -> V_25 ,
V_26 , V_27 ) )
return - 1 ;
V_195 = V_86 ;
break;
case V_209 :
V_55 -> V_25 . V_140 . V_71 = FALSE ;
break;
case V_20 :
if ( V_194 &&
V_101 < sizeof ( struct V_139 ) ) {
* V_26 = V_64 ;
* V_27 = F_36 ( L_9 ,
V_101 ) ;
return - 1 ;
}
if ( ! F_22 ( V_23 ,
& V_55 -> V_25 , V_26 , V_27 ) )
return - 1 ;
V_195 = ( int ) sizeof ( struct V_139 ) ;
break;
case V_21 :
if ( V_194 &&
V_101 < sizeof ( struct V_143 ) ) {
* V_26 = V_64 ;
* V_27 = F_36 ( L_10 ,
V_101 ) ;
return - 1 ;
}
if ( ! F_24 ( V_23 ,
& V_55 -> V_25 , V_26 , V_27 ) )
return - 1 ;
V_195 = ( int ) sizeof ( struct V_143 ) ;
break;
case V_210 :
if ( V_194 && V_101 < V_147 ) {
* V_26 = V_64 ;
* V_27 = F_36 ( L_11 ) ;
return - 1 ;
}
if ( ! F_26 ( V_23 , & V_55 -> V_25 , V_26 , V_27 ) )
return - 1 ;
V_195 = V_147 ;
break;
case V_22 :
if ( V_194 &&
V_101 < sizeof ( struct V_152 ) ) {
* V_26 = V_64 ;
* V_27 = F_36 ( L_12 ,
V_101 ) ;
return - 1 ;
}
if ( ! F_27 ( V_23 ,
& V_55 -> V_25 , V_26 , V_27 ) )
return - 1 ;
V_195 = ( int ) sizeof ( struct V_152 ) ;
break;
case V_18 :
if ( V_194 &&
V_101 < sizeof( struct V_156 ) ) {
* V_26 = V_64 ;
* V_27 = F_36 ( L_13 ,
V_101 ) ;
return - 1 ;
}
if ( ! F_28 ( V_23 , V_55 , & V_55 -> V_25 ,
V_26 , V_27 ) )
return - 1 ;
V_195 = ( int ) sizeof( struct V_156 ) ;
if ( ! F_30 ( V_23 , & V_55 -> V_25 , V_26 , V_27 ,
& V_135 ) )
return - 1 ;
V_195 += V_135 ;
if ( ! F_32 ( V_23 , & V_55 -> V_25 , V_26 , V_27 ,
& V_135 ) )
return - 1 ;
V_195 += V_135 ;
if ( V_194 &&
V_101 < ( T_6 ) V_195 ) {
* V_26 = V_64 ;
* V_27 = F_36 ( L_14 ,
V_101 , V_195 ) ;
return - 1 ;
}
break;
case V_19 :
if ( V_194 &&
V_101 < sizeof ( struct V_187 ) ) {
* V_26 = V_64 ;
* V_27 = F_36 ( L_15 ,
V_101 ) ;
return - 1 ;
}
if ( ! F_34 ( V_23 , & V_55 -> V_25 ,
V_26 , V_27 ) )
return - 1 ;
V_195 = ( int ) sizeof ( struct V_187 ) ;
break;
}
return V_195 ;
}
void
F_37 ( int V_192 , int V_193 ,
struct V_98 * V_55 , T_4 * V_99 , T_1 V_211 , int V_200 )
{
switch ( V_193 ) {
case V_13 :
if ( V_192 == V_197 ) {
F_38 ( V_55 , V_99 ) ;
} else {
if ( V_55 -> V_25 . V_35 . type == V_38 )
F_39 ( V_55 , V_99 ) ;
}
break;
case V_198 :
V_55 -> V_25 . V_199 . V_200 = V_200 ;
break;
case V_212 :
if ( V_211 )
F_16 ( V_55 , V_99 , FALSE ) ;
break;
case V_213 :
if ( V_211 )
F_16 ( V_55 , V_99 , TRUE ) ;
break;
case V_214 :
V_55 -> V_25 . V_199 . V_200 = 4 ;
break;
case V_215 :
if ( V_211 )
F_20 ( V_55 , V_99 ) ;
break;
default:
break;
}
}
int
F_40 ( int V_1 , const union V_24 * V_25 )
{
int V_216 ;
switch ( V_1 ) {
case V_13 :
V_216 = V_29 ;
break;
case V_14 :
V_216 = V_62 ;
break;
case V_15 :
V_216 = V_69 ;
break;
case V_16 :
V_216 = V_78 ;
break;
case V_17 :
V_216 = V_86 ;
break;
case V_18 :
V_216 = ( int ) sizeof ( struct V_156 ) ;
switch ( V_25 -> erf . V_55 . type & 0x7F ) {
case V_172 :
case V_173 :
case V_174 :
case V_175 :
case V_176 :
case V_177 :
case V_178 :
V_216 += ( int ) sizeof( struct V_217 ) ;
break;
case V_182 :
case V_183 :
case V_184 :
V_216 += ( int ) sizeof( struct V_218 ) ;
break;
default:
break;
}
if ( V_25 -> erf . V_55 . type & 0x80 ) {
int V_2 = 0 , V_167 = sizeof( V_25 -> erf . V_168 ) / sizeof( struct V_169 ) ;
T_4 V_165 [ 8 ] ;
T_4 type ;
do {
F_41 ( V_165 , V_25 -> erf . V_168 [ V_2 ] . V_170 ) ;
type = V_165 [ 0 ] ;
V_216 += 8 ;
V_2 ++ ;
} while ( type & 0x80 && V_2 < V_167 );
}
break;
case V_19 :
V_216 = ( int ) sizeof ( struct V_187 ) ;
break;
case V_20 :
V_216 = ( int ) sizeof ( struct V_139 ) ;
break;
case V_22 :
V_216 = ( int ) sizeof ( struct V_152 ) ;
break;
case V_21 :
V_216 = ( int ) sizeof ( struct V_143 ) ;
break;
default:
V_216 = 0 ;
break;
}
return V_216 ;
}
T_1
F_42 ( T_9 * V_219 , int V_1 , const union V_24 * V_25 ,
int * V_26 )
{
T_4 V_220 [ V_29 ] ;
T_4 V_221 [ V_62 ] ;
T_4 V_222 [ V_78 ] ;
T_4 V_68 [ V_69 ] ;
T_4 V_223 [ V_86 ] ;
T_4 V_155 [ sizeof( struct V_224 ) ] ;
struct V_187 V_188 ;
struct V_139 V_225 ;
struct V_143 V_226 ;
struct V_152 V_227 ;
T_10 V_135 ;
switch ( V_1 ) {
case V_13 :
V_220 [ V_34 ] =
( V_25 -> V_35 . V_45 == 0 ) ? 0x80 : 0x00 ;
switch ( V_25 -> V_35 . V_36 ) {
case V_41 :
V_220 [ V_34 ] |= 0x06 ;
break;
case V_37 :
switch ( V_25 -> V_35 . type ) {
case V_38 :
V_220 [ V_34 ] |= 0x01 ;
break;
case V_39 :
V_220 [ V_34 ] |= 0x02 ;
break;
case V_40 :
V_220 [ V_34 ] |= 0x05 ;
break;
}
break;
}
V_220 [ V_32 ] = ( T_4 ) V_25 -> V_35 . V_30 ;
F_43 ( & V_220 [ V_33 ] , V_25 -> V_35 . V_31 ) ;
if ( ! F_44 ( V_219 , V_220 , sizeof( V_220 ) , V_26 ) )
return FALSE ;
V_219 -> V_228 += sizeof( V_220 ) ;
break;
case V_14 :
memset ( V_221 , 0 , sizeof( V_221 ) ) ;
F_43 ( & V_221 [ V_67 ] ,
V_25 -> V_65 . V_66 ) ;
F_43 ( & V_221 [ V_63 ] , 0x0017 ) ;
if ( ! F_44 ( V_219 , V_221 , sizeof( V_221 ) , V_26 ) )
return FALSE ;
V_219 -> V_228 += sizeof( V_221 ) ;
break;
case V_15 :
memset ( & V_68 , 0 , sizeof( V_68 ) ) ;
V_68 [ V_72 ] = V_25 -> V_70 . V_71 ;
V_68 [ V_74 ] = V_25 -> V_70 . V_73 ;
F_43 ( & V_68 [ V_76 ] ,
V_25 -> V_70 . V_75 ) ;
if ( ! F_44 ( V_219 , V_68 , sizeof( V_68 ) , V_26 ) )
return FALSE ;
V_219 -> V_228 += sizeof( V_68 ) ;
break;
case V_16 :
memset ( & V_222 , 0 , sizeof( V_222 ) ) ;
F_43 ( & V_222 [ V_82 ] ,
V_25 -> V_81 . V_66 ) ;
F_43 ( & V_222 [ V_79 ] , V_80 ) ;
V_222 [ V_84 + 0 ] =
V_25 -> V_81 . V_83 ? 0x01 : 0x00 ;
if ( ! F_44 ( V_219 , V_222 , sizeof( V_222 ) , V_26 ) )
return FALSE ;
V_219 -> V_228 += sizeof( V_222 ) ;
break;
case V_17 :
memset ( & V_223 , 0 , sizeof( V_223 ) ) ;
V_223 [ V_89 ] = V_25 -> V_87 . V_88 ;
V_223 [ V_91 ] = V_25 -> V_87 . V_90 ;
V_223 [ V_93 ] = V_25 -> V_87 . V_92 ;
V_223 [ V_95 ] = V_25 -> V_87 . V_94 ;
V_223 [ V_97 ] = V_25 -> V_87 . V_96 ;
if ( ! F_44 ( V_219 , V_223 , sizeof( V_223 ) , V_26 ) )
return FALSE ;
V_219 -> V_228 += sizeof( V_223 ) ;
break;
case V_18 :
memset ( & V_155 , 0 , sizeof( V_155 ) ) ;
F_45 ( & V_155 [ 0 ] , V_25 -> erf . V_55 . V_157 ) ;
V_155 [ 8 ] = V_25 -> erf . V_55 . type ;
V_155 [ 9 ] = V_25 -> erf . V_55 . V_46 ;
F_43 ( & V_155 [ 10 ] , V_25 -> erf . V_55 . V_158 ) ;
F_43 ( & V_155 [ 12 ] , V_25 -> erf . V_55 . V_159 ) ;
F_43 ( & V_155 [ 14 ] , V_25 -> erf . V_55 . V_160 ) ;
V_135 = sizeof( struct V_156 ) ;
switch( V_25 -> erf . V_55 . type & 0x7F ) {
case V_172 :
case V_173 :
case V_174 :
case V_175 :
case V_176 :
case V_177 :
case V_178 :
F_46 ( & V_155 [ 16 ] , V_25 -> erf . V_180 . V_181 ) ;
V_135 += ( int ) sizeof( struct V_217 ) ;
break;
case V_182 :
case V_183 :
case V_184 :
F_43 ( & V_155 [ 16 ] , V_25 -> erf . V_180 . V_186 ) ;
V_135 += ( int ) sizeof( struct V_218 ) ;
break;
default:
break;
}
if ( ! F_44 ( V_219 , V_155 , V_135 , V_26 ) )
return FALSE ;
V_219 -> V_228 += V_135 ;
if ( V_25 -> erf . V_55 . type & 0x80 ) {
int V_2 = 0 , V_167 = sizeof( V_25 -> erf . V_168 ) / sizeof( struct V_169 ) ;
T_4 V_165 [ 8 ] ;
T_4 type ;
do {
F_41 ( V_165 , V_25 -> erf . V_168 [ V_2 ] . V_170 ) ;
type = V_165 [ 0 ] ;
if ( ! F_44 ( V_219 , V_165 , 8 , V_26 ) )
return FALSE ;
V_219 -> V_228 += 8 ;
V_2 ++ ;
} while ( type & 0x80 && V_2 < V_167 );
}
break;
case V_19 :
memset ( & V_188 , 0 , sizeof( V_188 ) ) ;
V_188 . V_191 = V_25 -> V_189 . V_191 |
( V_25 -> V_189 . V_190 ? 0x80 : 0x00 ) ;
F_46 ( ( T_4 * ) & V_188 . V_46 , V_25 -> V_189 . V_46 ) ;
if ( ! F_44 ( V_219 , & V_188 , sizeof( V_188 ) , V_26 ) )
return FALSE ;
V_219 -> V_228 += sizeof( V_188 ) ;
break;
case V_20 :
V_225 . V_141 = F_47 ( V_25 -> V_140 . V_71 ? V_229 : V_142 ) ;
if ( ! F_44 ( V_219 , & V_225 , sizeof V_225 , V_26 ) )
return FALSE ;
V_219 -> V_228 += sizeof V_225 ;
break;
case V_21 :
V_226 . V_145 = F_48 ( V_25 -> V_144 . V_145 ) ;
V_226 . V_146 = F_48 ( V_25 -> V_144 . V_146 ) ;
if ( ! F_44 ( V_219 , & V_226 , sizeof V_226 , V_26 ) )
return FALSE ;
V_219 -> V_228 += sizeof V_226 ;
break;
case V_22 :
V_227 . V_141 = ( V_25 -> V_140 . V_71 ? V_153 : V_230 ) ;
if ( ! F_44 ( V_219 , & V_227 , sizeof V_227 , V_26 ) )
return FALSE ;
V_219 -> V_228 += sizeof V_227 ;
break;
}
return TRUE ;
}
