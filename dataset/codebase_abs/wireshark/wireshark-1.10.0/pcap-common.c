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
( V_1 == V_21 )
) {
return TRUE ;
}
return FALSE ;
}
static T_1
F_4 ( T_2 V_22 ,
union V_23 * V_24 , int * V_25 , T_3 * * V_26 )
{
T_4 V_27 [ V_28 ] ;
int V_29 ;
T_4 V_30 ;
T_5 V_31 ;
V_32 = V_33 ;
V_29 = F_5 ( V_27 , V_28 , V_22 ) ;
if ( V_29 != V_28 ) {
* V_25 = F_6 ( V_22 , V_26 ) ;
if ( * V_25 == 0 )
* V_25 = V_34 ;
return FALSE ;
}
V_30 = V_27 [ V_35 ] ;
V_31 = F_7 ( & V_27 [ V_36 ] ) ;
switch ( V_27 [ V_37 ] & 0x0F ) {
case 0x01 :
V_24 -> V_38 . V_39 = V_40 ;
V_24 -> V_38 . type = V_41 ;
break;
case 0x02 :
V_24 -> V_38 . V_39 = V_40 ;
V_24 -> V_38 . type = V_42 ;
break;
case 0x05 :
V_24 -> V_38 . V_39 = V_40 ;
V_24 -> V_38 . type = V_43 ;
break;
case 0x06 :
V_24 -> V_38 . V_39 = V_44 ;
V_24 -> V_38 . type = V_45 ;
break;
case 0x03 :
V_24 -> V_38 . V_39 = V_40 ;
V_24 -> V_38 . type = V_45 ;
break;
case 0x04 :
V_24 -> V_38 . V_39 = V_40 ;
V_24 -> V_38 . type = V_45 ;
break;
default:
if ( V_30 == 0 && V_31 == 5 )
V_24 -> V_38 . V_39 = V_44 ;
else
V_24 -> V_38 . V_39 = V_40 ;
V_24 -> V_38 . type = V_45 ;
break;
}
V_24 -> V_38 . V_46 = V_47 ;
V_24 -> V_38 . V_30 = V_30 ;
V_24 -> V_38 . V_31 = V_31 ;
V_24 -> V_38 . V_48 = ( V_27 [ V_37 ] & 0x80 ) ? 0 : 1 ;
V_24 -> V_38 . V_49 = 0 ;
V_24 -> V_38 . V_50 = 0 ;
V_24 -> V_38 . V_51 = 0 ;
V_24 -> V_38 . V_52 = 0 ;
V_24 -> V_38 . V_53 = 0 ;
return TRUE ;
}
static T_1
F_8 ( T_2 V_22 ,
union V_23 * V_24 , int * V_25 , T_3 * * V_26 )
{
T_4 V_27 [ V_54 ] ;
int V_29 ;
T_4 V_30 ;
T_5 V_31 ;
V_32 = V_33 ;
V_29 = F_5 ( V_27 , V_54 , V_22 ) ;
if ( V_29 != V_54 ) {
* V_25 = F_6 ( V_22 , V_26 ) ;
if ( * V_25 == 0 )
* V_25 = V_34 ;
return FALSE ;
}
V_30 = V_27 [ V_55 ] ;
V_31 = F_7 ( & V_27 [ V_56 ] ) ;
V_24 -> V_38 . V_30 = V_30 ;
V_24 -> V_38 . V_31 = V_31 ;
V_24 -> V_38 . V_48 = ( V_27 [ V_57 ] & 0x80 ) ? 0 : 1 ;
V_24 -> V_38 . V_49 = 0 ;
V_24 -> V_38 . V_50 = 0 ;
V_24 -> V_38 . V_51 = 0 ;
V_24 -> V_38 . V_52 = 0 ;
V_24 -> V_38 . V_53 = 0 ;
return TRUE ;
}
static T_1
F_9 ( T_2 V_22 ,
union V_23 * V_24 , int * V_25 , T_3 * * V_26 )
{
T_4 V_58 [ V_59 ] ;
int V_29 ;
V_32 = V_33 ;
if ( F_10 ( V_22 , - V_59 , V_60 , V_25 ) == - 1 )
{
* V_25 = F_6 ( V_22 , V_26 ) ;
if ( * V_25 == 0 )
* V_25 = V_34 ;
return FALSE ;
}
V_29 = F_5 ( V_58 , V_59 , V_22 ) ;
if ( V_29 != V_59 ) {
* V_25 = F_6 ( V_22 , V_26 ) ;
if ( * V_25 == 0 )
* V_25 = V_34 ;
return FALSE ;
}
memcpy ( V_24 -> V_61 . V_62 , V_58 , V_59 ) ;
return TRUE ;
}
static T_1
F_11 ( T_2 V_22 , union V_23 * V_24 ,
int * V_25 , T_3 * * V_26 )
{
T_4 V_63 [ V_64 ] ;
int V_29 ;
V_32 = V_33 ;
V_29 = F_5 ( V_63 , V_64 , V_22 ) ;
if ( V_29 != V_64 ) {
* V_25 = F_6 ( V_22 , V_26 ) ;
if ( * V_25 == 0 )
* V_25 = V_34 ;
return FALSE ;
}
if ( F_7 ( & V_63 [ V_65 ] ) != 0x0017 ) {
* V_25 = V_66 ;
if ( V_26 != NULL )
* V_26 = F_12 ( L_1 ) ;
return FALSE ;
}
V_24 -> V_67 . V_68 = F_7 ( & V_63 [ V_69 ] ) ;
return TRUE ;
}
static T_1
F_13 ( T_2 V_22 , union V_23 * V_24 , int * V_25 , T_3 * * V_26 )
{
T_4 V_70 [ V_71 ] ;
int V_29 ;
V_32 = V_33 ;
V_29 = F_5 ( V_70 , V_71 , V_22 ) ;
if ( V_29 != V_71 ) {
* V_25 = F_6 ( V_22 , V_26 ) ;
if ( * V_25 == 0 )
* V_25 = V_34 ;
return FALSE ;
}
V_24 -> V_72 . V_73 = V_70 [ V_74 ] ;
V_24 -> V_72 . V_75 = V_70 [ V_76 ] ;
V_24 -> V_72 . V_77 = F_7 ( & V_70 [ V_78 ] ) ;
return TRUE ;
}
static T_1
F_14 ( T_2 V_22 , union V_23 * V_24 ,
int * V_25 , T_3 * * V_26 )
{
T_4 V_79 [ V_80 ] ;
int V_29 ;
V_32 = V_33 ;
V_29 = F_5 ( V_79 , V_80 , V_22 ) ;
if ( V_29 != V_80 ) {
* V_25 = F_6 ( V_22 , V_26 ) ;
if ( * V_25 == 0 )
* V_25 = V_34 ;
return FALSE ;
}
if ( F_7 ( & V_79 [ V_81 ] ) != V_82 ) {
* V_25 = V_66 ;
if ( V_26 != NULL )
* V_26 = F_12 ( L_2 ) ;
return FALSE ;
}
V_24 -> V_83 . V_68 = F_7 ( & V_79 [ V_84 ] ) ;
V_24 -> V_83 . V_85 = ! ! V_79 [ V_86 + 0 ] ;
return TRUE ;
}
static T_1
F_15 ( T_2 V_22 , union V_23 * V_24 , int * V_25 , T_3 * * V_26 )
{
T_4 V_87 [ V_88 ] ;
int V_29 ;
V_32 = V_33 ;
V_29 = F_5 ( V_87 , V_88 , V_22 ) ;
if ( V_29 != V_88 ) {
* V_25 = F_6 ( V_22 , V_26 ) ;
if ( * V_25 == 0 )
* V_25 = V_34 ;
return FALSE ;
}
V_24 -> V_89 . V_90 = V_87 [ V_91 ] ;
V_24 -> V_89 . V_92 = V_87 [ V_93 ] ;
V_24 -> V_89 . V_94 = V_87 [ V_95 ] ;
V_24 -> V_89 . V_96 = V_87 [ V_97 ] ;
V_24 -> V_89 . V_98 = V_87 [ V_99 ] ;
return TRUE ;
}
static void
F_16 ( T_6 V_100 , T_1 V_101 ,
T_1 V_102 , T_4 * V_103 )
{
struct V_104 * V_58 ;
struct V_105 * V_106 ;
T_7 V_107 , V_2 ;
if ( V_101 ) {
V_58 = (struct V_104 * ) ( void * ) V_103 ;
if ( V_100 < F_17 ( V_58 , & V_58 -> V_108 ) )
return;
F_18 ( ( T_4 * ) & V_58 -> V_108 ) ;
if ( V_100 < F_17 ( V_58 , & V_58 -> V_109 ) )
return;
F_19 ( ( T_4 * ) & V_58 -> V_109 ) ;
if ( V_100 < F_17 ( V_58 , & V_58 -> V_110 ) )
return;
F_18 ( ( T_4 * ) & V_58 -> V_110 ) ;
if ( V_100 < F_17 ( V_58 , & V_58 -> V_111 ) )
return;
F_20 ( ( T_4 * ) & V_58 -> V_111 ) ;
if ( V_100 < F_17 ( V_58 , & V_58 -> V_112 ) )
return;
F_20 ( ( T_4 * ) & V_58 -> V_112 ) ;
if ( V_100 < F_17 ( V_58 , & V_58 -> V_113 ) )
return;
F_20 ( ( T_4 * ) & V_58 -> V_113 ) ;
if ( V_100 < F_17 ( V_58 , & V_58 -> V_114 ) )
return;
F_20 ( ( T_4 * ) & V_58 -> V_114 ) ;
if ( V_58 -> V_115 == V_116 ) {
if ( V_100 < F_17 ( V_58 , & V_58 -> V_117 . V_118 . V_119 ) )
return;
F_20 ( ( T_4 * ) & V_58 -> V_117 . V_118 . V_119 ) ;
if ( V_100 < F_17 ( V_58 , & V_58 -> V_117 . V_118 . V_120 ) )
return;
F_20 ( ( T_4 * ) & V_58 -> V_117 . V_118 . V_120 ) ;
}
if ( V_102 ) {
if ( V_100 < F_17 ( V_58 , & V_58 -> V_121 ) )
return;
F_20 ( ( T_4 * ) & V_58 -> V_121 ) ;
if ( V_100 < F_17 ( V_58 , & V_58 -> V_122 ) )
return;
F_20 ( ( T_4 * ) & V_58 -> V_122 ) ;
if ( V_100 < F_17 ( V_58 , & V_58 -> V_123 ) )
return;
F_20 ( ( T_4 * ) & V_58 -> V_123 ) ;
if ( V_100 < F_17 ( V_58 , & V_58 -> V_124 ) )
return;
F_20 ( ( T_4 * ) & V_58 -> V_124 ) ;
}
if ( V_58 -> V_115 == V_116 ) {
if ( V_102 ) {
V_106 = (struct V_105 * ) ( void * ) ( V_103 + 64 ) ;
} else {
V_106 = (struct V_105 * ) ( void * ) ( V_103 + 48 ) ;
}
V_107 = V_58 -> V_117 . V_118 . V_120 ;
for ( V_2 = 0 ; V_2 < V_107 ; V_2 ++ ) {
if ( V_100 < F_17 ( V_58 , & V_106 -> V_125 ) )
return;
F_20 ( ( T_4 * ) & V_106 -> V_125 ) ;
if ( V_100 < F_17 ( V_58 , & V_106 -> V_126 ) )
return;
F_20 ( ( T_4 * ) & V_106 -> V_126 ) ;
if ( V_100 < F_17 ( V_58 , & V_106 -> V_127 ) )
return;
F_20 ( ( T_4 * ) & V_106 -> V_127 ) ;
if ( V_100 < F_17 ( V_58 , & V_106 -> V_128 ) )
return;
F_20 ( ( T_4 * ) & V_106 -> V_128 ) ;
V_106 ++ ;
}
}
}
}
static T_1
F_21 ( T_2 V_22 ,
union V_23 * V_24 , int * V_25 , T_3 * * V_26 )
{
int V_29 ;
struct V_129 V_58 ;
V_32 = V_33 ;
V_29 = F_5 ( & V_58 ,
sizeof ( struct V_129 ) , V_22 ) ;
if ( V_29 != sizeof ( struct V_129 ) ) {
* V_25 = F_6 ( V_22 , V_26 ) ;
if ( * V_25 == 0 )
* V_25 = V_34 ;
return FALSE ;
}
V_24 -> V_130 . V_73 = ( ( F_22 ( V_58 . V_131 ) & V_132 ) == 0 ) ? TRUE : FALSE ;
return TRUE ;
}
static T_1
F_23 ( T_2 V_22 ,
union V_23 * V_24 , int * V_25 , T_3 * * V_26 )
{
int V_29 ;
T_4 V_58 [ V_133 ] ;
V_32 = V_33 ;
V_29 = F_5 ( V_58 , V_133 , V_22 ) ;
if ( V_29 != V_133 ) {
* V_25 = F_6 ( V_22 , V_26 ) ;
if ( * V_25 == 0 )
* V_25 = V_34 ;
return FALSE ;
}
V_24 -> V_134 . V_135 = V_58 [ V_136 ] ;
V_24 -> V_134 . V_49 = V_58 [ V_137 ] ;
return TRUE ;
}
static T_1
F_24 ( T_2 V_22 ,
union V_23 * V_24 , int * V_25 , T_3 * * V_26 )
{
int V_29 ;
struct V_138 V_58 ;
V_32 = V_33 ;
V_29 = F_5 ( & V_58 ,
sizeof ( struct V_138 ) , V_22 ) ;
if ( V_29 != sizeof ( struct V_138 ) ) {
* V_25 = F_6 ( V_22 , V_26 ) ;
if ( * V_25 == 0 )
* V_25 = V_34 ;
return FALSE ;
}
V_24 -> V_130 . V_73 = ( V_58 . V_131 == V_139 ) ? TRUE : FALSE ;
return TRUE ;
}
static T_1
F_25 ( T_2 V_22 , struct V_140 * V_141 ,
union V_23 * V_24 , int * V_25 , T_3 * * V_26 )
{
T_4 V_142 [ sizeof( struct V_143 ) ] ;
int V_29 ;
V_32 = V_33 ;
V_29 = F_5 ( V_142 , sizeof( struct V_143 ) , V_22 ) ;
if ( V_29 != sizeof( struct V_143 ) ) {
* V_25 = F_6 ( V_22 , V_26 ) ;
if ( * V_25 == 0 )
* V_25 = V_34 ;
return FALSE ;
}
V_24 -> erf . V_58 . V_144 = F_26 ( & V_142 [ 0 ] ) ;
V_24 -> erf . V_58 . type = V_142 [ 8 ] ;
V_24 -> erf . V_58 . V_49 = V_142 [ 9 ] ;
V_24 -> erf . V_58 . V_145 = F_7 ( & V_142 [ 10 ] ) ;
V_24 -> erf . V_58 . V_146 = F_7 ( & V_142 [ 12 ] ) ;
V_24 -> erf . V_58 . V_147 = F_7 ( & V_142 [ 14 ] ) ;
if ( V_141 ) {
T_8 V_144 = V_24 -> erf . V_58 . V_144 ;
V_141 -> V_144 . V_148 = ( V_149 ) ( V_144 >> 32 ) ;
V_144 = ( ( V_144 & 0xffffffff ) * 1000 * 1000 * 1000 ) ;
V_144 += ( V_144 & 0x80000000 ) << 1 ;
V_141 -> V_144 . V_150 = ( ( V_149 ) ( V_144 >> 32 ) ) ;
if ( V_141 -> V_144 . V_150 >= 1000000000 ) {
V_141 -> V_144 . V_150 -= 1000000000 ;
V_141 -> V_144 . V_148 += 1 ;
}
}
return TRUE ;
}
static T_1
F_27 ( T_2 V_22 , union V_23 * V_24 ,
int * V_25 , T_3 * * V_26 , T_6 * V_151 )
{
int V_29 = 0 ;
T_4 V_152 [ 8 ] ;
T_8 V_153 ;
int V_2 = 0 , V_154 = sizeof( V_24 -> erf . V_155 ) / sizeof( struct V_156 ) ;
T_4 type ;
* V_151 = 0 ;
if ( V_24 -> erf . V_58 . type & 0x80 ) {
do{
V_32 = V_33 ;
V_29 = F_5 ( V_152 , 8 , V_22 ) ;
if ( V_29 != 8 ) {
* V_25 = F_6 ( V_22 , V_26 ) ;
if ( * V_25 == 0 )
* V_25 = V_34 ;
return FALSE ;
}
type = V_152 [ 0 ] ;
V_153 = F_28 ( V_152 ) ;
if ( V_2 < V_154 )
memcpy ( & V_24 -> erf . V_155 [ V_2 ] . V_157 , & V_153 , sizeof( V_153 ) ) ;
* V_151 += 8 ;
V_2 ++ ;
} while ( type & 0x80 );
}
return TRUE ;
}
static T_1
F_29 ( T_2 V_22 , union V_23 * V_24 ,
int * V_25 , T_3 * * V_26 , T_6 * V_151 )
{
T_4 V_158 [ sizeof( union V_158 ) ] ;
int V_29 ;
* V_151 = 0 ;
switch( V_24 -> erf . V_58 . type & 0x7F ) {
case V_159 :
case V_160 :
case V_161 :
case V_162 :
case V_163 :
case V_164 :
case V_165 :
V_32 = V_33 ;
V_29 = F_5 ( V_158 , sizeof( V_166 ) , V_22 ) ;
if ( V_29 != sizeof( V_166 ) ) {
* V_25 = F_6 ( V_22 , V_26 ) ;
if ( * V_25 == 0 )
* V_25 = V_34 ;
return FALSE ;
}
V_24 -> erf . V_167 . V_168 = F_30 ( & V_158 [ 0 ] ) ;
* V_151 = sizeof( V_166 ) ;
break;
case V_169 :
case V_170 :
case V_171 :
V_32 = V_33 ;
V_29 = F_5 ( V_158 , sizeof( V_172 ) , V_22 ) ;
if ( V_29 != sizeof( V_172 ) ) {
* V_25 = F_6 ( V_22 , V_26 ) ;
if ( * V_25 == 0 )
* V_25 = V_34 ;
return FALSE ;
}
V_24 -> erf . V_167 . V_173 = F_7 ( & V_158 [ 0 ] ) ;
* V_151 = sizeof( V_172 ) ;
break;
default:
break;
}
return TRUE ;
}
static T_1
F_31 ( T_2 V_22 , union V_23 * V_24 , int * V_25 , T_3 * * V_26 )
{
struct V_174 V_175 ;
int V_29 ;
V_32 = V_33 ;
V_29 = F_5 ( & V_175 , sizeof ( V_175 ) , V_22 ) ;
if ( V_29 != sizeof ( V_175 ) ) {
* V_25 = F_6 ( V_22 , V_26 ) ;
if ( * V_25 == 0 )
* V_25 = V_34 ;
return FALSE ;
}
V_24 -> V_176 . V_177 = V_175 . V_178 & 0x80 ? 1 : 0 ;
V_24 -> V_176 . V_178 = V_175 . V_178 & 0x7f ;
V_24 -> V_176 . V_49 = F_30 ( & V_175 . V_49 ) ;
return TRUE ;
}
int
F_32 ( T_2 V_22 , int V_179 , int V_180 ,
T_6 V_100 , T_1 V_181 , struct V_140 * V_58 ,
union V_23 * V_24 , int * V_25 , T_3 * * V_26 )
{
int V_182 = 0 ;
T_6 V_183 ;
switch ( V_180 ) {
case V_13 :
if ( V_179 == V_184 ) {
if ( V_181 && V_100 < V_54 ) {
* V_25 = V_66 ;
* V_26 = F_33 ( L_3 ,
V_100 ) ;
return - 1 ;
}
if ( ! F_8 ( V_22 ,
V_24 , V_25 , V_26 ) )
return - 1 ;
V_182 = V_54 ;
} else {
if ( V_181 && V_100 < V_28 ) {
* V_25 = V_66 ;
* V_26 = F_33 ( L_4 ,
V_100 ) ;
return - 1 ;
}
if ( ! F_4 ( V_22 ,
V_24 , V_25 , V_26 ) )
return - 1 ;
V_182 = V_28 ;
}
break;
case V_185 :
if ( V_179 == V_184 ) {
if ( ! F_9 ( V_22 , V_24 , V_25 , V_26 ) )
return - 1 ;
}
V_24 -> V_186 . V_187 = - 1 ;
break;
case V_188 :
case V_189 :
case V_190 :
case V_191 :
V_24 -> V_192 . V_187 = - 1 ;
V_24 -> V_192 . V_193 = FALSE ;
V_24 -> V_192 . V_48 = 0 ;
V_24 -> V_192 . V_194 = 0 ;
V_24 -> V_192 . V_195 = 0 ;
break;
case V_14 :
if ( V_181 && V_100 < V_64 ) {
* V_25 = V_66 ;
* V_26 = F_33 ( L_5 ,
V_100 ) ;
return - 1 ;
}
if ( ! F_11 ( V_22 , V_24 ,
V_25 , V_26 ) )
return - 1 ;
V_182 = V_64 ;
break;
case V_15 :
if ( V_181 && V_100 < V_71 ) {
* V_25 = V_66 ;
* V_26 = F_33 ( L_6 ,
V_100 ) ;
return - 1 ;
}
if ( ! F_13 ( V_22 , V_24 ,
V_25 , V_26 ) )
return - 1 ;
V_182 = V_71 ;
break;
case V_16 :
if ( V_181 && V_100 < V_80 ) {
* V_25 = V_66 ;
* V_26 = F_33 ( L_7 ,
V_100 ) ;
return - 1 ;
}
if ( ! F_14 ( V_22 , V_24 ,
V_25 , V_26 ) )
return - 1 ;
V_182 = V_80 ;
break;
case V_17 :
if ( V_181 && V_100 < V_88 ) {
* V_25 = V_66 ;
* V_26 = F_33 ( L_8 ,
V_100 ) ;
return - 1 ;
}
if ( ! F_15 ( V_22 , V_24 ,
V_25 , V_26 ) )
return - 1 ;
V_182 = V_88 ;
break;
case V_196 :
V_24 -> V_130 . V_73 = FALSE ;
break;
case V_20 :
if ( V_181 &&
V_100 < sizeof ( struct V_129 ) ) {
* V_25 = V_66 ;
* V_26 = F_33 ( L_9 ,
V_100 ) ;
return - 1 ;
}
if ( ! F_21 ( V_22 ,
V_24 , V_25 , V_26 ) )
return - 1 ;
V_182 = ( int ) sizeof ( struct V_129 ) ;
break;
case V_197 :
if ( V_181 && V_100 < V_133 ) {
* V_25 = V_66 ;
* V_26 = F_33 ( L_10 ) ;
return - 1 ;
}
if ( ! F_23 ( V_22 , V_24 , V_25 , V_26 ) )
return - 1 ;
V_182 = V_133 ;
break;
case V_21 :
if ( V_181 &&
V_100 < sizeof ( struct V_138 ) ) {
* V_25 = V_66 ;
* V_26 = F_33 ( L_11 ,
V_100 ) ;
return - 1 ;
}
if ( ! F_24 ( V_22 ,
V_24 , V_25 , V_26 ) )
return - 1 ;
V_182 = ( int ) sizeof ( struct V_138 ) ;
break;
case V_18 :
if ( V_181 &&
V_100 < sizeof( struct V_143 ) ) {
* V_25 = V_66 ;
* V_26 = F_33 ( L_12 ,
V_100 ) ;
return - 1 ;
}
if ( ! F_25 ( V_22 , V_58 , V_24 ,
V_25 , V_26 ) )
return - 1 ;
V_182 = ( int ) sizeof( struct V_143 ) ;
if ( ! F_27 ( V_22 , V_24 , V_25 , V_26 ,
& V_183 ) )
return - 1 ;
V_182 += V_183 ;
if ( ! F_29 ( V_22 , V_24 , V_25 , V_26 ,
& V_183 ) )
return - 1 ;
V_182 += V_183 ;
if ( V_181 &&
V_100 < ( T_6 ) V_182 ) {
* V_25 = V_66 ;
* V_26 = F_33 ( L_13 ,
V_100 , V_182 ) ;
return - 1 ;
}
break;
case V_19 :
if ( V_181 &&
V_100 < sizeof ( struct V_174 ) ) {
* V_25 = V_66 ;
* V_26 = F_33 ( L_14 ,
V_100 ) ;
return - 1 ;
}
if ( ! F_31 ( V_22 , V_24 ,
V_25 , V_26 ) )
return - 1 ;
V_182 = ( int ) sizeof ( struct V_174 ) ;
break;
}
return V_182 ;
}
void
F_34 ( int V_179 , int V_180 ,
union V_23 * V_24 ,
T_4 * V_103 , T_6 V_100 , T_1 V_198 , int V_187 )
{
switch ( V_180 ) {
case V_13 :
if ( V_179 == V_184 ) {
F_35 ( V_103 , V_100 , V_24 ) ;
} else {
if ( V_24 -> V_38 . type == V_41 )
F_36 ( V_103 , V_100 ,
V_24 ) ;
}
break;
case V_185 :
V_24 -> V_186 . V_187 = V_187 ;
break;
case V_199 :
F_16 ( V_100 ,
V_198 , FALSE , V_103 ) ;
break;
case V_200 :
F_16 ( V_100 ,
V_198 , TRUE , V_103 ) ;
break;
case V_201 :
V_24 -> V_186 . V_187 = 4 ;
break;
default:
break;
}
}
int
F_37 ( int V_1 , const union V_23 * V_24 )
{
int V_202 ;
switch ( V_1 ) {
case V_13 :
V_202 = V_28 ;
break;
case V_14 :
V_202 = V_64 ;
break;
case V_15 :
V_202 = V_71 ;
break;
case V_16 :
V_202 = V_80 ;
break;
case V_17 :
V_202 = V_88 ;
break;
case V_18 :
V_202 = ( int ) sizeof ( struct V_143 ) ;
switch ( V_24 -> erf . V_58 . type & 0x7F ) {
case V_159 :
case V_160 :
case V_161 :
case V_162 :
case V_163 :
case V_164 :
case V_165 :
V_202 += ( int ) sizeof( struct V_203 ) ;
break;
case V_169 :
case V_170 :
case V_171 :
V_202 += ( int ) sizeof( struct V_204 ) ;
break;
default:
break;
}
if ( V_24 -> erf . V_58 . type & 0x80 ) {
int V_2 = 0 , V_154 = sizeof( V_24 -> erf . V_155 ) / sizeof( struct V_156 ) ;
T_4 V_152 [ 8 ] ;
T_4 type ;
do {
F_38 ( V_152 , V_24 -> erf . V_155 [ V_2 ] . V_157 ) ;
type = V_152 [ 0 ] ;
V_202 += 8 ;
V_2 ++ ;
} while ( type & 0x80 && V_2 < V_154 );
}
break;
case V_19 :
V_202 = ( int ) sizeof ( struct V_174 ) ;
break;
case V_20 :
V_202 = ( int ) sizeof ( struct V_129 ) ;
break;
case V_21 :
V_202 = ( int ) sizeof ( struct V_138 ) ;
break;
default:
V_202 = 0 ;
break;
}
return V_202 ;
}
T_1
F_39 ( T_9 * V_205 , int V_1 , const union V_23 * V_24 ,
int * V_25 )
{
T_4 V_206 [ V_28 ] ;
T_4 V_207 [ V_64 ] ;
T_4 V_208 [ V_80 ] ;
T_4 V_70 [ V_71 ] ;
T_4 V_209 [ V_88 ] ;
T_4 V_142 [ sizeof( struct V_210 ) ] ;
struct V_174 V_175 ;
struct V_129 V_211 ;
struct V_138 V_212 ;
T_10 V_183 ;
switch ( V_1 ) {
case V_13 :
V_206 [ V_37 ] =
( V_24 -> V_38 . V_48 == 0 ) ? 0x80 : 0x00 ;
switch ( V_24 -> V_38 . V_39 ) {
case V_44 :
V_206 [ V_37 ] |= 0x06 ;
break;
case V_40 :
switch ( V_24 -> V_38 . type ) {
case V_41 :
V_206 [ V_37 ] |= 0x01 ;
break;
case V_42 :
V_206 [ V_37 ] |= 0x02 ;
break;
case V_43 :
V_206 [ V_37 ] |= 0x05 ;
break;
}
break;
}
V_206 [ V_35 ] = ( T_4 ) V_24 -> V_38 . V_30 ;
F_40 ( & V_206 [ V_36 ] , V_24 -> V_38 . V_31 ) ;
if ( ! F_41 ( V_205 , V_206 , sizeof( V_206 ) , V_25 ) )
return FALSE ;
V_205 -> V_213 += sizeof( V_206 ) ;
break;
case V_14 :
memset ( V_207 , 0 , sizeof( V_207 ) ) ;
F_40 ( & V_207 [ V_69 ] ,
V_24 -> V_67 . V_68 ) ;
F_40 ( & V_207 [ V_65 ] , 0x0017 ) ;
if ( ! F_41 ( V_205 , V_207 , sizeof( V_207 ) , V_25 ) )
return FALSE ;
V_205 -> V_213 += sizeof( V_207 ) ;
break;
case V_15 :
memset ( & V_70 , 0 , sizeof( V_70 ) ) ;
V_70 [ V_74 ] = V_24 -> V_72 . V_73 ;
V_70 [ V_76 ] = V_24 -> V_72 . V_75 ;
F_40 ( & V_70 [ V_78 ] ,
V_24 -> V_72 . V_77 ) ;
if ( ! F_41 ( V_205 , V_70 , sizeof( V_70 ) , V_25 ) )
return FALSE ;
V_205 -> V_213 += sizeof( V_70 ) ;
break;
case V_16 :
memset ( & V_208 , 0 , sizeof( V_208 ) ) ;
F_40 ( & V_208 [ V_84 ] ,
V_24 -> V_83 . V_68 ) ;
F_40 ( & V_208 [ V_81 ] , V_82 ) ;
V_208 [ V_86 + 0 ] =
V_24 -> V_83 . V_85 ? 0x01 : 0x00 ;
if ( ! F_41 ( V_205 , V_208 , sizeof( V_208 ) , V_25 ) )
return FALSE ;
V_205 -> V_213 += sizeof( V_208 ) ;
break;
case V_17 :
memset ( & V_209 , 0 , sizeof( V_209 ) ) ;
V_209 [ V_91 ] = V_24 -> V_89 . V_90 ;
V_209 [ V_93 ] = V_24 -> V_89 . V_92 ;
V_209 [ V_95 ] = V_24 -> V_89 . V_94 ;
V_209 [ V_97 ] = V_24 -> V_89 . V_96 ;
V_209 [ V_99 ] = V_24 -> V_89 . V_98 ;
if ( ! F_41 ( V_205 , V_209 , sizeof( V_209 ) , V_25 ) )
return FALSE ;
V_205 -> V_213 += sizeof( V_209 ) ;
break;
case V_18 :
memset ( & V_142 , 0 , sizeof( V_142 ) ) ;
F_42 ( & V_142 [ 0 ] , V_24 -> erf . V_58 . V_144 ) ;
V_142 [ 8 ] = V_24 -> erf . V_58 . type ;
V_142 [ 9 ] = V_24 -> erf . V_58 . V_49 ;
F_40 ( & V_142 [ 10 ] , V_24 -> erf . V_58 . V_145 ) ;
F_40 ( & V_142 [ 12 ] , V_24 -> erf . V_58 . V_146 ) ;
F_40 ( & V_142 [ 14 ] , V_24 -> erf . V_58 . V_147 ) ;
V_183 = sizeof( struct V_143 ) ;
switch( V_24 -> erf . V_58 . type & 0x7F ) {
case V_159 :
case V_160 :
case V_161 :
case V_162 :
case V_163 :
case V_164 :
case V_165 :
F_43 ( & V_142 [ 16 ] , V_24 -> erf . V_167 . V_168 ) ;
V_183 += ( int ) sizeof( struct V_203 ) ;
break;
case V_169 :
case V_170 :
case V_171 :
F_40 ( & V_142 [ 16 ] , V_24 -> erf . V_167 . V_173 ) ;
V_183 += ( int ) sizeof( struct V_204 ) ;
break;
default:
break;
}
if ( ! F_41 ( V_205 , V_142 , V_183 , V_25 ) )
return FALSE ;
V_205 -> V_213 += V_183 ;
if ( V_24 -> erf . V_58 . type & 0x80 ) {
int V_2 = 0 , V_154 = sizeof( V_24 -> erf . V_155 ) / sizeof( struct V_156 ) ;
T_4 V_152 [ 8 ] ;
T_4 type ;
do {
F_38 ( V_152 , V_24 -> erf . V_155 [ V_2 ] . V_157 ) ;
type = V_152 [ 0 ] ;
if ( ! F_41 ( V_205 , V_152 , 8 , V_25 ) )
return FALSE ;
V_205 -> V_213 += 8 ;
V_2 ++ ;
} while ( type & 0x80 && V_2 < V_154 );
}
break;
case V_19 :
memset ( & V_175 , 0 , sizeof( V_175 ) ) ;
V_175 . V_178 = V_24 -> V_176 . V_178 |
( V_24 -> V_176 . V_177 ? 0x80 : 0x00 ) ;
F_43 ( ( T_4 * ) & V_175 . V_49 , V_24 -> V_176 . V_49 ) ;
if ( ! F_41 ( V_205 , & V_175 , sizeof( V_175 ) , V_25 ) )
return FALSE ;
V_205 -> V_213 += sizeof( V_175 ) ;
break;
case V_20 :
V_211 . V_131 = F_44 ( V_24 -> V_130 . V_73 ? V_214 : V_132 ) ;
if ( ! F_41 ( V_205 , & V_211 , sizeof V_211 , V_25 ) )
return FALSE ;
V_205 -> V_213 += sizeof V_211 ;
break;
case V_21 :
V_212 . V_131 = ( V_24 -> V_130 . V_73 ? V_139 : V_215 ) ;
if ( ! F_41 ( V_205 , & V_212 , sizeof V_212 , V_25 ) )
return FALSE ;
V_205 -> V_213 += sizeof V_212 ;
break;
}
return TRUE ;
}
