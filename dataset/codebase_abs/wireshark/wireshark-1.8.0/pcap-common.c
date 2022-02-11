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
static T_1
F_3 ( T_2 V_13 ,
union V_14 * V_15 , int * V_16 , T_3 * * V_17 )
{
T_4 V_18 [ V_19 ] ;
int V_20 ;
T_4 V_21 ;
T_5 V_22 ;
V_23 = V_24 ;
V_20 = F_4 ( V_18 , V_19 , V_13 ) ;
if ( V_20 != V_19 ) {
* V_16 = F_5 ( V_13 , V_17 ) ;
if ( * V_16 == 0 )
* V_16 = V_25 ;
return FALSE ;
}
V_21 = V_18 [ V_26 ] ;
V_22 = F_6 ( & V_18 [ V_27 ] ) ;
switch ( V_18 [ V_28 ] & 0x0F ) {
case 0x01 :
V_15 -> V_29 . V_30 = V_31 ;
V_15 -> V_29 . type = V_32 ;
break;
case 0x02 :
V_15 -> V_29 . V_30 = V_31 ;
V_15 -> V_29 . type = V_33 ;
break;
case 0x05 :
V_15 -> V_29 . V_30 = V_31 ;
V_15 -> V_29 . type = V_34 ;
break;
case 0x06 :
V_15 -> V_29 . V_30 = V_35 ;
V_15 -> V_29 . type = V_36 ;
break;
case 0x03 :
V_15 -> V_29 . V_30 = V_31 ;
V_15 -> V_29 . type = V_36 ;
break;
case 0x04 :
V_15 -> V_29 . V_30 = V_31 ;
V_15 -> V_29 . type = V_36 ;
break;
default:
if ( V_21 == 0 && V_22 == 5 )
V_15 -> V_29 . V_30 = V_35 ;
else
V_15 -> V_29 . V_30 = V_31 ;
V_15 -> V_29 . type = V_36 ;
break;
}
V_15 -> V_29 . V_37 = V_38 ;
V_15 -> V_29 . V_21 = V_21 ;
V_15 -> V_29 . V_22 = V_22 ;
V_15 -> V_29 . V_39 = ( V_18 [ V_28 ] & 0x80 ) ? 0 : 1 ;
V_15 -> V_29 . V_40 = 0 ;
V_15 -> V_29 . V_41 = 0 ;
V_15 -> V_29 . V_42 = 0 ;
V_15 -> V_29 . V_43 = 0 ;
V_15 -> V_29 . V_44 = 0 ;
return TRUE ;
}
static T_1
F_7 ( T_2 V_13 ,
union V_14 * V_15 , int * V_16 , T_3 * * V_17 )
{
T_4 V_18 [ V_45 ] ;
int V_20 ;
T_4 V_21 ;
T_5 V_22 ;
V_23 = V_24 ;
V_20 = F_4 ( V_18 , V_45 , V_13 ) ;
if ( V_20 != V_45 ) {
* V_16 = F_5 ( V_13 , V_17 ) ;
if ( * V_16 == 0 )
* V_16 = V_25 ;
return FALSE ;
}
V_21 = V_18 [ V_46 ] ;
V_22 = F_6 ( & V_18 [ V_47 ] ) ;
V_15 -> V_29 . V_21 = V_21 ;
V_15 -> V_29 . V_22 = V_22 ;
V_15 -> V_29 . V_39 = ( V_18 [ V_48 ] & 0x80 ) ? 0 : 1 ;
V_15 -> V_29 . V_40 = 0 ;
V_15 -> V_29 . V_41 = 0 ;
V_15 -> V_29 . V_42 = 0 ;
V_15 -> V_29 . V_43 = 0 ;
V_15 -> V_29 . V_44 = 0 ;
return TRUE ;
}
static T_1
F_8 ( T_2 V_13 , union V_14 * V_15 ,
int * V_16 , T_3 * * V_17 )
{
T_4 V_49 [ V_50 ] ;
int V_20 ;
V_23 = V_24 ;
V_20 = F_4 ( V_49 , V_50 , V_13 ) ;
if ( V_20 != V_50 ) {
* V_16 = F_5 ( V_13 , V_17 ) ;
if ( * V_16 == 0 )
* V_16 = V_25 ;
return FALSE ;
}
if ( F_6 ( & V_49 [ V_51 ] ) != 0x0017 ) {
* V_16 = V_52 ;
if ( V_17 != NULL )
* V_17 = F_9 ( L_1 ) ;
return FALSE ;
}
V_15 -> V_53 . V_54 = F_6 ( & V_49 [ V_55 ] ) ;
return TRUE ;
}
static T_1
F_10 ( T_2 V_13 , union V_14 * V_15 , int * V_16 , T_3 * * V_17 )
{
T_4 V_56 [ V_57 ] ;
int V_20 ;
V_23 = V_24 ;
V_20 = F_4 ( V_56 , V_57 , V_13 ) ;
if ( V_20 != V_57 ) {
* V_16 = F_5 ( V_13 , V_17 ) ;
if ( * V_16 == 0 )
* V_16 = V_25 ;
return FALSE ;
}
V_15 -> V_58 . V_59 = V_56 [ V_60 ] ;
V_15 -> V_58 . V_61 = V_56 [ V_62 ] ;
V_15 -> V_58 . V_63 = F_6 ( & V_56 [ V_64 ] ) ;
return TRUE ;
}
static T_1
F_11 ( T_2 V_13 , union V_14 * V_15 ,
int * V_16 , T_3 * * V_17 )
{
T_4 V_65 [ V_66 ] ;
int V_20 ;
V_23 = V_24 ;
V_20 = F_4 ( V_65 , V_66 , V_13 ) ;
if ( V_20 != V_66 ) {
* V_16 = F_5 ( V_13 , V_17 ) ;
if ( * V_16 == 0 )
* V_16 = V_25 ;
return FALSE ;
}
if ( F_6 ( & V_65 [ V_67 ] ) != V_68 ) {
* V_16 = V_52 ;
if ( V_17 != NULL )
* V_17 = F_9 ( L_2 ) ;
return FALSE ;
}
V_15 -> V_69 . V_54 = F_6 ( & V_65 [ V_70 ] ) ;
V_15 -> V_69 . V_71 = ! ! V_65 [ V_72 + 0 ] ;
return TRUE ;
}
static T_1
F_12 ( T_2 V_13 , union V_14 * V_15 , int * V_16 , T_3 * * V_17 )
{
T_4 V_73 [ V_74 ] ;
int V_20 ;
V_23 = V_24 ;
V_20 = F_4 ( V_73 , V_74 , V_13 ) ;
if ( V_20 != V_74 ) {
* V_16 = F_5 ( V_13 , V_17 ) ;
if ( * V_16 == 0 )
* V_16 = V_25 ;
return FALSE ;
}
V_15 -> V_75 . V_76 = V_73 [ V_77 ] ;
V_15 -> V_75 . V_78 = V_73 [ V_79 ] ;
V_15 -> V_75 . V_80 = V_73 [ V_81 ] ;
V_15 -> V_75 . V_82 = V_73 [ V_83 ] ;
V_15 -> V_75 . V_84 = V_73 [ V_85 ] ;
return TRUE ;
}
static void
F_13 ( T_6 V_86 , T_1 V_87 ,
T_1 V_88 , T_4 * V_89 )
{
struct V_90 * V_91 ;
struct V_92 * V_93 ;
T_7 V_94 , V_2 ;
if ( V_87 ) {
V_91 = (struct V_90 * ) ( void * ) V_89 ;
if ( V_86 < F_14 ( V_91 , & V_91 -> V_95 ) )
return;
F_15 ( ( T_4 * ) & V_91 -> V_95 ) ;
if ( V_86 < F_14 ( V_91 , & V_91 -> V_96 ) )
return;
F_16 ( ( T_4 * ) & V_91 -> V_96 ) ;
if ( V_86 < F_14 ( V_91 , & V_91 -> V_97 ) )
return;
F_15 ( ( T_4 * ) & V_91 -> V_97 ) ;
if ( V_86 < F_14 ( V_91 , & V_91 -> V_98 ) )
return;
F_17 ( ( T_4 * ) & V_91 -> V_98 ) ;
if ( V_86 < F_14 ( V_91 , & V_91 -> V_99 ) )
return;
F_17 ( ( T_4 * ) & V_91 -> V_99 ) ;
if ( V_86 < F_14 ( V_91 , & V_91 -> V_100 ) )
return;
F_17 ( ( T_4 * ) & V_91 -> V_100 ) ;
if ( V_86 < F_14 ( V_91 , & V_91 -> V_101 ) )
return;
F_17 ( ( T_4 * ) & V_91 -> V_101 ) ;
if ( V_91 -> V_102 == V_103 ) {
if ( V_86 < F_14 ( V_91 , & V_91 -> V_104 . V_105 . V_106 ) )
return;
F_17 ( ( T_4 * ) & V_91 -> V_104 . V_105 . V_106 ) ;
if ( V_86 < F_14 ( V_91 , & V_91 -> V_104 . V_105 . V_107 ) )
return;
F_17 ( ( T_4 * ) & V_91 -> V_104 . V_105 . V_107 ) ;
}
if ( V_88 ) {
if ( V_86 < F_14 ( V_91 , & V_91 -> V_108 ) )
return;
F_17 ( ( T_4 * ) & V_91 -> V_108 ) ;
if ( V_86 < F_14 ( V_91 , & V_91 -> V_109 ) )
return;
F_17 ( ( T_4 * ) & V_91 -> V_109 ) ;
if ( V_86 < F_14 ( V_91 , & V_91 -> V_110 ) )
return;
F_17 ( ( T_4 * ) & V_91 -> V_110 ) ;
if ( V_86 < F_14 ( V_91 , & V_91 -> V_111 ) )
return;
F_17 ( ( T_4 * ) & V_91 -> V_111 ) ;
}
if ( V_91 -> V_102 == V_103 ) {
if ( V_88 ) {
V_93 = (struct V_92 * ) ( void * ) ( V_89 + 64 ) ;
} else {
V_93 = (struct V_92 * ) ( void * ) ( V_89 + 48 ) ;
}
V_94 = V_91 -> V_104 . V_105 . V_107 ;
for ( V_2 = 0 ; V_2 < V_94 ; V_2 ++ ) {
if ( V_86 < F_14 ( V_91 , & V_93 -> V_112 ) )
return;
F_17 ( ( T_4 * ) & V_93 -> V_112 ) ;
if ( V_86 < F_14 ( V_91 , & V_93 -> V_113 ) )
return;
F_17 ( ( T_4 * ) & V_93 -> V_113 ) ;
if ( V_86 < F_14 ( V_91 , & V_93 -> V_114 ) )
return;
F_17 ( ( T_4 * ) & V_93 -> V_114 ) ;
if ( V_86 < F_14 ( V_91 , & V_93 -> V_115 ) )
return;
F_17 ( ( T_4 * ) & V_93 -> V_115 ) ;
V_93 ++ ;
}
}
}
}
static T_1
F_18 ( T_2 V_13 ,
union V_14 * V_15 , int * V_16 , T_3 * * V_17 )
{
int V_20 ;
struct V_116 V_91 ;
V_23 = V_24 ;
V_20 = F_4 ( & V_91 ,
sizeof ( struct V_116 ) , V_13 ) ;
if ( V_20 != sizeof ( struct V_116 ) ) {
* V_16 = F_5 ( V_13 , V_17 ) ;
if ( * V_16 == 0 )
* V_16 = V_25 ;
return FALSE ;
}
V_15 -> V_117 . V_59 = ( ( F_19 ( V_91 . V_118 ) & V_119 ) == 0 ) ? TRUE : FALSE ;
return TRUE ;
}
static T_1
F_20 ( T_2 V_13 ,
union V_14 * V_15 , int * V_16 , T_3 * * V_17 )
{
int V_20 ;
T_4 V_91 [ V_120 ] ;
V_23 = V_24 ;
V_20 = F_4 ( V_91 , V_120 , V_13 ) ;
if ( V_20 != V_120 ) {
* V_16 = F_5 ( V_13 , V_17 ) ;
if ( * V_16 == 0 )
* V_16 = V_25 ;
return FALSE ;
}
V_15 -> V_121 . V_122 = V_91 [ V_123 ] ;
V_15 -> V_121 . V_40 = V_91 [ V_124 ] ;
return TRUE ;
}
static T_1
F_21 ( T_2 V_13 ,
union V_14 * V_15 , int * V_16 , T_3 * * V_17 )
{
int V_20 ;
struct V_125 V_91 ;
V_23 = V_24 ;
V_20 = F_4 ( & V_91 ,
sizeof ( struct V_125 ) , V_13 ) ;
if ( V_20 != sizeof ( struct V_125 ) ) {
* V_16 = F_5 ( V_13 , V_17 ) ;
if ( * V_16 == 0 )
* V_16 = V_25 ;
return FALSE ;
}
V_15 -> V_117 . V_59 = ( V_91 . V_118 == V_126 ) ? TRUE : FALSE ;
return TRUE ;
}
static T_1
F_22 ( T_2 V_13 , struct V_127 * V_128 ,
union V_14 * V_15 , int * V_16 , T_3 * * V_17 )
{
T_4 V_129 [ sizeof( struct V_130 ) ] ;
int V_20 ;
V_23 = V_24 ;
V_20 = F_4 ( V_129 , sizeof( struct V_130 ) , V_13 ) ;
if ( V_20 != sizeof( struct V_130 ) ) {
* V_16 = F_5 ( V_13 , V_17 ) ;
if ( * V_16 == 0 )
* V_16 = V_25 ;
return FALSE ;
}
V_15 -> erf . V_91 . V_131 = F_23 ( & V_129 [ 0 ] ) ;
V_15 -> erf . V_91 . type = V_129 [ 8 ] ;
V_15 -> erf . V_91 . V_40 = V_129 [ 9 ] ;
V_15 -> erf . V_91 . V_132 = F_6 ( & V_129 [ 10 ] ) ;
V_15 -> erf . V_91 . V_133 = F_6 ( & V_129 [ 12 ] ) ;
V_15 -> erf . V_91 . V_134 = F_6 ( & V_129 [ 14 ] ) ;
if ( V_128 ) {
T_8 V_131 = V_15 -> erf . V_91 . V_131 ;
V_128 -> V_131 . V_135 = ( V_136 ) ( V_131 >> 32 ) ;
V_131 = ( ( V_131 & 0xffffffff ) * 1000 * 1000 * 1000 ) ;
V_131 += ( V_131 & 0x80000000 ) << 1 ;
V_128 -> V_131 . V_137 = ( ( V_136 ) ( V_131 >> 32 ) ) ;
if ( V_128 -> V_131 . V_137 >= 1000000000 ) {
V_128 -> V_131 . V_137 -= 1000000000 ;
V_128 -> V_131 . V_135 += 1 ;
}
}
return TRUE ;
}
static T_1
F_24 ( T_2 V_13 , union V_14 * V_15 ,
int * V_16 , T_3 * * V_17 , T_6 * V_138 )
{
int V_20 = 0 ;
T_4 V_139 [ 8 ] ;
T_8 V_140 ;
int V_2 = 0 , V_141 = sizeof( V_15 -> erf . V_142 ) / sizeof( struct V_143 ) ;
T_4 type ;
* V_138 = 0 ;
if ( V_15 -> erf . V_91 . type & 0x80 ) {
do{
V_23 = V_24 ;
V_20 = F_4 ( V_139 , 8 , V_13 ) ;
if ( V_20 != 8 ) {
* V_16 = F_5 ( V_13 , V_17 ) ;
if ( * V_16 == 0 )
* V_16 = V_25 ;
return FALSE ;
}
type = V_139 [ 0 ] ;
V_140 = F_25 ( V_139 ) ;
if ( V_2 < V_141 )
memcpy ( & V_15 -> erf . V_142 [ V_2 ] . V_144 , & V_140 , sizeof( V_140 ) ) ;
* V_138 += 8 ;
V_2 ++ ;
} while ( type & 0x80 );
}
return TRUE ;
}
static T_1
F_26 ( T_2 V_13 , union V_14 * V_15 ,
int * V_16 , T_3 * * V_17 , T_6 * V_138 )
{
T_4 V_145 [ sizeof( union V_145 ) ] ;
int V_20 ;
* V_138 = 0 ;
switch( V_15 -> erf . V_91 . type & 0x7F ) {
case V_146 :
case V_147 :
case V_148 :
case V_149 :
case V_150 :
case V_151 :
case V_152 :
V_23 = V_24 ;
V_20 = F_4 ( V_145 , sizeof( V_153 ) , V_13 ) ;
if ( V_20 != sizeof( V_153 ) ) {
* V_16 = F_5 ( V_13 , V_17 ) ;
if ( * V_16 == 0 )
* V_16 = V_25 ;
return FALSE ;
}
V_15 -> erf . V_154 . V_155 = F_27 ( & V_145 [ 0 ] ) ;
* V_138 = sizeof( V_153 ) ;
break;
case V_156 :
case V_157 :
case V_158 :
V_23 = V_24 ;
V_20 = F_4 ( V_145 , sizeof( V_159 ) , V_13 ) ;
if ( V_20 != sizeof( V_159 ) ) {
* V_16 = F_5 ( V_13 , V_17 ) ;
if ( * V_16 == 0 )
* V_16 = V_25 ;
return FALSE ;
}
V_15 -> erf . V_154 . V_160 = F_6 ( & V_145 [ 0 ] ) ;
* V_138 = sizeof( V_159 ) ;
break;
default:
break;
}
return TRUE ;
}
static T_1
F_28 ( T_2 V_13 , union V_14 * V_15 , int * V_16 , T_3 * * V_17 )
{
struct V_161 V_162 ;
int V_20 ;
V_23 = V_24 ;
V_20 = F_4 ( & V_162 , sizeof ( V_162 ) , V_13 ) ;
if ( V_20 != sizeof ( V_162 ) ) {
* V_16 = F_5 ( V_13 , V_17 ) ;
if ( * V_16 == 0 )
* V_16 = V_25 ;
return FALSE ;
}
V_15 -> V_163 . V_164 = V_162 . V_165 & 0x80 ? 1 : 0 ;
V_15 -> V_163 . V_165 = V_162 . V_165 & 0x7f ;
V_15 -> V_163 . V_40 = F_27 ( & V_162 . V_40 ) ;
return TRUE ;
}
int
F_29 ( T_2 V_13 , int V_166 , int V_167 ,
T_6 V_86 , T_1 V_168 , struct V_127 * V_91 ,
union V_14 * V_15 , int * V_16 , T_3 * * V_17 )
{
int V_169 = 0 ;
T_6 V_170 ;
switch ( V_167 ) {
case V_171 :
if ( V_166 == V_172 ) {
if ( V_168 && V_86 < V_45 ) {
* V_16 = V_52 ;
* V_17 = F_30 ( L_3 ,
V_86 ) ;
return - 1 ;
}
if ( ! F_7 ( V_13 ,
V_15 , V_16 , V_17 ) )
return - 1 ;
V_169 = V_45 ;
} else {
if ( V_168 && V_86 < V_19 ) {
* V_16 = V_52 ;
* V_17 = F_30 ( L_4 ,
V_86 ) ;
return - 1 ;
}
if ( ! F_3 ( V_13 ,
V_15 , V_16 , V_17 ) )
return - 1 ;
V_169 = V_19 ;
}
break;
case V_173 :
V_15 -> V_174 . V_175 = - 1 ;
break;
case V_176 :
case V_177 :
case V_178 :
case V_179 :
V_15 -> V_180 . V_175 = - 1 ;
V_15 -> V_180 . V_39 = 0 ;
V_15 -> V_180 . V_181 = 0 ;
V_15 -> V_180 . V_182 = 0 ;
break;
case V_183 :
if ( V_168 && V_86 < V_50 ) {
* V_16 = V_52 ;
* V_17 = F_30 ( L_5 ,
V_86 ) ;
return - 1 ;
}
if ( ! F_8 ( V_13 , V_15 ,
V_16 , V_17 ) )
return - 1 ;
V_169 = V_50 ;
break;
case V_184 :
if ( V_168 && V_86 < V_57 ) {
* V_16 = V_52 ;
* V_17 = F_30 ( L_6 ,
V_86 ) ;
return - 1 ;
}
if ( ! F_10 ( V_13 , V_15 ,
V_16 , V_17 ) )
return - 1 ;
V_169 = V_57 ;
break;
case V_185 :
if ( V_168 && V_86 < V_66 ) {
* V_16 = V_52 ;
* V_17 = F_30 ( L_7 ,
V_86 ) ;
return - 1 ;
}
if ( ! F_11 ( V_13 , V_15 ,
V_16 , V_17 ) )
return - 1 ;
V_169 = V_66 ;
break;
case V_186 :
if ( V_168 && V_86 < V_74 ) {
* V_16 = V_52 ;
* V_17 = F_30 ( L_8 ,
V_86 ) ;
return - 1 ;
}
if ( ! F_12 ( V_13 , V_15 ,
V_16 , V_17 ) )
return - 1 ;
V_169 = V_74 ;
break;
case V_187 :
V_15 -> V_117 . V_59 = FALSE ;
break;
case V_188 :
if ( V_168 &&
V_86 < sizeof ( struct V_116 ) ) {
* V_16 = V_52 ;
* V_17 = F_30 ( L_9 ,
V_86 ) ;
return - 1 ;
}
if ( ! F_18 ( V_13 ,
V_15 , V_16 , V_17 ) )
return - 1 ;
V_169 = ( int ) sizeof ( struct V_116 ) ;
break;
case V_189 :
if ( V_168 && V_86 < V_120 ) {
* V_16 = V_52 ;
* V_17 = F_30 ( L_10 ) ;
return - 1 ;
}
if ( ! F_20 ( V_13 , V_15 , V_16 , V_17 ) )
return - 1 ;
V_169 = V_120 ;
break;
case V_190 :
if ( V_168 &&
V_86 < sizeof ( struct V_125 ) ) {
* V_16 = V_52 ;
* V_17 = F_30 ( L_11 ,
V_86 ) ;
return - 1 ;
}
if ( ! F_21 ( V_13 ,
V_15 , V_16 , V_17 ) )
return - 1 ;
V_169 = ( int ) sizeof ( struct V_125 ) ;
break;
case V_191 :
if ( V_168 &&
V_86 < sizeof( struct V_130 ) ) {
* V_16 = V_52 ;
* V_17 = F_30 ( L_12 ,
V_86 ) ;
return - 1 ;
}
if ( ! F_22 ( V_13 , V_91 , V_15 ,
V_16 , V_17 ) )
return - 1 ;
V_169 = ( int ) sizeof( struct V_130 ) ;
if ( ! F_24 ( V_13 , V_15 , V_16 , V_17 ,
& V_170 ) )
return - 1 ;
V_169 += V_170 ;
if ( ! F_26 ( V_13 , V_15 , V_16 , V_17 ,
& V_170 ) )
return - 1 ;
V_169 += V_170 ;
if ( V_168 &&
V_86 < ( T_6 ) V_169 ) {
* V_16 = V_52 ;
* V_17 = F_30 ( L_13 ,
V_86 , V_169 ) ;
return - 1 ;
}
break;
case V_192 :
if ( V_168 &&
V_86 < sizeof ( struct V_161 ) ) {
* V_16 = V_52 ;
* V_17 = F_30 ( L_14 ,
V_86 ) ;
return - 1 ;
}
if ( ! F_28 ( V_13 , V_15 ,
V_16 , V_17 ) )
return - 1 ;
V_169 = ( int ) sizeof ( struct V_161 ) ;
break;
}
return V_169 ;
}
void
F_31 ( int V_166 , int V_167 ,
union V_14 * V_15 ,
T_4 * V_89 , T_6 V_86 , T_1 V_193 , int V_175 )
{
switch ( V_167 ) {
case V_171 :
if ( V_166 == V_172 ) {
F_32 ( V_89 , V_86 , V_15 ) ;
} else {
if ( V_15 -> V_29 . type == V_32 )
F_33 ( V_89 , V_86 ,
V_15 ) ;
}
break;
case V_173 :
V_15 -> V_174 . V_175 = V_175 ;
break;
case V_194 :
F_13 ( V_86 ,
V_193 , FALSE , V_89 ) ;
break;
case V_195 :
F_13 ( V_86 ,
V_193 , TRUE , V_89 ) ;
break;
case V_196 :
V_15 -> V_174 . V_175 = 4 ;
break;
default:
break;
}
}
int
F_34 ( int V_1 , const union V_14 * V_15 )
{
int V_197 ;
switch ( V_1 ) {
case V_171 :
V_197 = V_19 ;
break;
case V_183 :
V_197 = V_50 ;
break;
case V_184 :
V_197 = V_57 ;
break;
case V_185 :
V_197 = V_66 ;
break;
case V_186 :
V_197 = V_74 ;
break;
case V_191 :
V_197 = ( int ) sizeof ( struct V_130 ) ;
switch ( V_15 -> erf . V_91 . type & 0x7F ) {
case V_146 :
case V_147 :
case V_148 :
case V_149 :
case V_150 :
case V_151 :
case V_152 :
V_197 += ( int ) sizeof( struct V_198 ) ;
break;
case V_156 :
case V_157 :
case V_158 :
V_197 += ( int ) sizeof( struct V_199 ) ;
break;
default:
break;
}
if ( V_15 -> erf . V_91 . type & 0x80 ) {
int V_2 = 0 , V_141 = sizeof( V_15 -> erf . V_142 ) / sizeof( struct V_143 ) ;
T_4 V_139 [ 8 ] ;
T_4 type ;
do {
F_35 ( V_139 , V_15 -> erf . V_142 [ V_2 ] . V_144 ) ;
type = V_139 [ 0 ] ;
V_197 += 8 ;
V_2 ++ ;
} while ( type & 0x80 && V_2 < V_141 );
}
break;
case V_192 :
V_197 = ( int ) sizeof ( struct V_161 ) ;
break;
case V_188 :
V_197 = ( int ) sizeof ( struct V_116 ) ;
break;
case V_190 :
V_197 = ( int ) sizeof ( struct V_125 ) ;
break;
default:
V_197 = 0 ;
break;
}
return V_197 ;
}
T_1
F_36 ( T_9 * V_200 , int V_1 , const union V_14 * V_15 ,
int * V_16 )
{
T_4 V_201 [ V_19 ] ;
T_4 V_202 [ V_50 ] ;
T_4 V_203 [ V_66 ] ;
T_4 V_56 [ V_57 ] ;
T_4 V_204 [ V_74 ] ;
T_4 V_129 [ sizeof( struct V_205 ) ] ;
struct V_161 V_162 ;
struct V_116 V_206 ;
struct V_125 V_207 ;
T_10 V_170 ;
switch ( V_1 ) {
case V_171 :
V_201 [ V_28 ] =
( V_15 -> V_29 . V_39 == 0 ) ? 0x80 : 0x00 ;
switch ( V_15 -> V_29 . V_30 ) {
case V_35 :
V_201 [ V_28 ] |= 0x06 ;
break;
case V_31 :
switch ( V_15 -> V_29 . type ) {
case V_32 :
V_201 [ V_28 ] |= 0x01 ;
break;
case V_33 :
V_201 [ V_28 ] |= 0x02 ;
break;
case V_34 :
V_201 [ V_28 ] |= 0x05 ;
break;
}
break;
}
V_201 [ V_26 ] = ( T_4 ) V_15 -> V_29 . V_21 ;
F_37 ( & V_201 [ V_27 ] , V_15 -> V_29 . V_22 ) ;
if ( ! F_38 ( V_200 , V_201 , sizeof( V_201 ) , V_16 ) )
return FALSE ;
V_200 -> V_208 += sizeof( V_201 ) ;
break;
case V_183 :
memset ( V_202 , 0 , sizeof( V_202 ) ) ;
F_37 ( & V_202 [ V_55 ] ,
V_15 -> V_53 . V_54 ) ;
F_37 ( & V_202 [ V_51 ] , 0x0017 ) ;
if ( ! F_38 ( V_200 , V_202 , sizeof( V_202 ) , V_16 ) )
return FALSE ;
V_200 -> V_208 += sizeof( V_202 ) ;
break;
case V_184 :
memset ( & V_56 , 0 , sizeof( V_56 ) ) ;
V_56 [ V_60 ] = V_15 -> V_58 . V_59 ;
V_56 [ V_62 ] = V_15 -> V_58 . V_61 ;
F_37 ( & V_56 [ V_64 ] ,
V_15 -> V_58 . V_63 ) ;
if ( ! F_38 ( V_200 , V_56 , sizeof( V_56 ) , V_16 ) )
return FALSE ;
V_200 -> V_208 += sizeof( V_56 ) ;
break;
case V_185 :
memset ( & V_203 , 0 , sizeof( V_203 ) ) ;
F_37 ( & V_203 [ V_70 ] ,
V_15 -> V_69 . V_54 ) ;
F_37 ( & V_203 [ V_67 ] , V_68 ) ;
V_203 [ V_72 + 0 ] =
V_15 -> V_69 . V_71 ? 0x01 : 0x00 ;
if ( ! F_38 ( V_200 , V_203 , sizeof( V_203 ) , V_16 ) )
return FALSE ;
V_200 -> V_208 += sizeof( V_203 ) ;
break;
case V_186 :
memset ( & V_204 , 0 , sizeof( V_204 ) ) ;
V_204 [ V_77 ] = V_15 -> V_75 . V_76 ;
V_204 [ V_79 ] = V_15 -> V_75 . V_78 ;
V_204 [ V_81 ] = V_15 -> V_75 . V_80 ;
V_204 [ V_83 ] = V_15 -> V_75 . V_82 ;
V_204 [ V_85 ] = V_15 -> V_75 . V_84 ;
if ( ! F_38 ( V_200 , V_204 , sizeof( V_204 ) , V_16 ) )
return FALSE ;
V_200 -> V_208 += sizeof( V_204 ) ;
break;
case V_191 :
memset ( & V_129 , 0 , sizeof( V_129 ) ) ;
F_39 ( & V_129 [ 0 ] , V_15 -> erf . V_91 . V_131 ) ;
V_129 [ 8 ] = V_15 -> erf . V_91 . type ;
V_129 [ 9 ] = V_15 -> erf . V_91 . V_40 ;
F_37 ( & V_129 [ 10 ] , V_15 -> erf . V_91 . V_132 ) ;
F_37 ( & V_129 [ 12 ] , V_15 -> erf . V_91 . V_133 ) ;
F_37 ( & V_129 [ 14 ] , V_15 -> erf . V_91 . V_134 ) ;
V_170 = sizeof( struct V_130 ) ;
switch( V_15 -> erf . V_91 . type & 0x7F ) {
case V_146 :
case V_147 :
case V_148 :
case V_149 :
case V_150 :
case V_151 :
case V_152 :
F_40 ( & V_129 [ 16 ] , V_15 -> erf . V_154 . V_155 ) ;
V_170 += ( int ) sizeof( struct V_198 ) ;
break;
case V_156 :
case V_157 :
case V_158 :
F_37 ( & V_129 [ 16 ] , V_15 -> erf . V_154 . V_160 ) ;
V_170 += ( int ) sizeof( struct V_199 ) ;
break;
default:
break;
}
if ( ! F_38 ( V_200 , V_129 , V_170 , V_16 ) )
return FALSE ;
V_200 -> V_208 += V_170 ;
if ( V_15 -> erf . V_91 . type & 0x80 ) {
int V_2 = 0 , V_141 = sizeof( V_15 -> erf . V_142 ) / sizeof( struct V_143 ) ;
T_4 V_139 [ 8 ] ;
T_4 type ;
do {
F_35 ( V_139 , V_15 -> erf . V_142 [ V_2 ] . V_144 ) ;
type = V_139 [ 0 ] ;
if ( ! F_38 ( V_200 , V_139 , 8 , V_16 ) )
return FALSE ;
V_200 -> V_208 += 8 ;
V_2 ++ ;
} while ( type & 0x80 && V_2 < V_141 );
}
break;
case V_192 :
memset ( & V_162 , 0 , sizeof( V_162 ) ) ;
V_162 . V_165 = V_15 -> V_163 . V_165 |
( V_15 -> V_163 . V_164 ? 0x80 : 0x00 ) ;
F_40 ( ( T_4 * ) & V_162 . V_40 , V_15 -> V_163 . V_40 ) ;
if ( ! F_38 ( V_200 , & V_162 , sizeof( V_162 ) , V_16 ) )
return FALSE ;
V_200 -> V_208 += sizeof( V_162 ) ;
break;
case V_188 :
V_206 . V_118 = F_41 ( V_15 -> V_117 . V_59 ? V_209 : V_119 ) ;
if ( ! F_38 ( V_200 , & V_206 , sizeof V_206 , V_16 ) )
return FALSE ;
V_200 -> V_208 += sizeof V_206 ;
break;
case V_190 :
V_207 . V_118 = ( V_15 -> V_117 . V_59 ? V_126 : V_210 ) ;
if ( ! F_38 ( V_200 , & V_207 , sizeof V_207 , V_16 ) )
return FALSE ;
V_200 -> V_208 += sizeof V_207 ;
break;
}
return TRUE ;
}
