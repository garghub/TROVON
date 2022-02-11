static void F_1 ( void * V_1 )
{
if ( ! V_1 )
return;
}
static int F_2 ( struct V_2 * V_3 , T_1 V_4 , void * V_5 , int V_6 )
{
struct V_7 * V_8 = (struct V_7 * ) V_3 -> V_9 ;
struct V_10 * V_11 = (struct V_10 * ) V_3 -> V_9 ;
int V_12 ;
unsigned int V_13 ;
unsigned int V_14 = 0 , V_15 = 0 ;
unsigned int V_16 = V_8 -> V_17 ;
V_12 = F_3 ( V_3 , V_3 -> V_18 ,
V_8 , V_19 , NULL ) ;
if ( V_12 != V_20 ) {
F_4 ( L_1 ) ;
return V_21 ;
}
if ( V_5 ) {
unsigned int V_22 = V_4 ;
if ( V_4 == V_23 )
V_22 = V_3 -> V_24 ;
else
V_22 = V_3 -> V_18 ;
if ( V_6 ) {
V_12 = F_5 ( V_3 , V_22 , V_3 -> V_25 ) ;
} else {
V_12 = F_6 ( V_3 , V_22 , V_5 ,
V_16 , 0 , & V_15 ) ;
}
if ( V_12 != V_20 ) {
F_4 ( L_2 ) ;
return V_21 ;
}
}
V_12 = F_3 ( V_3 , V_3 -> V_24 , V_11 ,
V_26 , & V_14 ) ;
if ( V_12 == V_27 && V_14 == 0 ) {
F_4 ( L_3 ) ;
V_12 = F_3 ( V_3 , V_3 -> V_24 ,
V_11 , V_26 , & V_14 ) ;
}
if ( V_12 == V_28 ) {
F_4 ( L_4 ) ;
V_12 = F_3 ( V_3 , V_3 -> V_24 ,
V_11 , V_26 , NULL ) ;
}
if ( V_12 != V_20 )
return V_21 ;
V_13 = F_7 ( V_11 -> V_29 ) ;
if ( V_13 && ! ( V_3 -> V_30 & V_31 ) ) {
V_13 = F_8 ( V_13 , V_16 ) ;
if ( V_3 -> V_25 != NULL )
F_9 ( V_3 -> V_25 , F_10 ( F_11 ( V_3 -> V_25 ) ,
( int ) V_13 ) ) ;
}
if ( V_11 -> V_32 != V_33 )
return V_21 ;
return V_34 ;
}
static int F_12 ( struct V_2 * V_3 , struct V_35 * V_25 )
{
struct V_36 * V_37 = (struct V_36 * ) V_3 -> V_1 ;
if ( V_37 -> V_38 . V_39 && V_37 -> V_38 . V_40 )
return V_34 ;
else {
F_13 ( V_3 ) ;
return V_34 ;
}
return V_34 ;
}
static int F_14 ( struct V_2 * V_3 , struct V_35 * V_25 )
{
unsigned char V_41 [ 36 ] = {
0x00 , 0x80 , 0x02 , 0x00 , 0x1F , 0x00 , 0x00 , 0x00 , 0x55 ,
0x53 , 0x42 , 0x32 , 0x2E , 0x30 , 0x20 , 0x20 , 0x43 , 0x61 ,
0x72 , 0x64 , 0x52 , 0x65 , 0x61 , 0x64 , 0x65 , 0x72 , 0x20 ,
0x20 , 0x20 , 0x20 , 0x20 , 0x20 , 0x30 , 0x31 , 0x30 , 0x30 } ;
F_15 ( V_41 , 36 , V_25 ) ;
return V_34 ;
}
static int F_16 ( struct V_2 * V_3 , struct V_35 * V_25 )
{
struct V_36 * V_37 = (struct V_36 * ) V_3 -> V_1 ;
unsigned char V_42 [ 12 ] = {
0x0b , 0x00 , 0x00 , 0x08 , 0x00 , 0x00 ,
0x71 , 0xc0 , 0x00 , 0x00 , 0x02 , 0x00 } ;
unsigned char V_43 [ 12 ] = {
0x0b , 0x00 , 0x80 , 0x08 , 0x00 , 0x00 ,
0x71 , 0xc0 , 0x00 , 0x00 , 0x02 , 0x00 } ;
if ( V_37 -> V_38 . V_44 )
F_15 ( V_43 , 12 , V_25 ) ;
else
F_15 ( V_42 , 12 , V_25 ) ;
return V_34 ;
}
static int F_17 ( struct V_2 * V_3 , struct V_35 * V_25 )
{
T_2 V_45 ;
T_3 V_46 ;
unsigned int V_47 = 0 ;
unsigned char V_5 [ 8 ] ;
struct V_48 * V_49 = NULL ;
struct V_36 * V_37 = (struct V_36 * ) V_3 -> V_1 ;
F_4 ( L_5 ) ;
if ( V_37 -> V_38 . V_50 ) {
V_46 = 0x200 ;
if ( V_37 -> V_38 . V_51 )
V_45 = V_37 -> V_52 - 1 ;
else
V_45 = ( V_37 -> V_52 + 1 ) * 1024 - 1 ;
} else {
V_46 = 1 << ( V_37 -> V_53 ) ;
V_45 = V_37 -> V_54 * ( V_37 -> V_55 + 1 )
* ( 1 << ( V_37 -> V_56 + 2 ) ) - 1 ;
}
V_37 -> V_45 = V_45 ;
F_4 ( L_6 , V_46 ) ;
F_4 ( L_7 , V_45 ) ;
V_5 [ 0 ] = ( V_45 >> 24 ) & 0xff ;
V_5 [ 1 ] = ( V_45 >> 16 ) & 0xff ;
V_5 [ 2 ] = ( V_45 >> 8 ) & 0xff ;
V_5 [ 3 ] = ( V_45 >> 0 ) & 0xff ;
V_5 [ 4 ] = ( V_46 >> 24 ) & 0xff ;
V_5 [ 5 ] = ( V_46 >> 16 ) & 0xff ;
V_5 [ 6 ] = ( V_46 >> 8 ) & 0xff ;
V_5 [ 7 ] = ( V_46 >> 0 ) & 0xff ;
F_18 ( V_5 , 8 , V_25 , & V_49 , & V_47 , V_57 ) ;
return V_34 ;
}
static int F_19 ( struct V_2 * V_3 , struct V_35 * V_25 )
{
int V_12 ;
unsigned char * V_58 = V_25 -> V_59 ;
struct V_7 * V_8 = (struct V_7 * ) V_3 -> V_9 ;
struct V_36 * V_37 = (struct V_36 * ) V_3 -> V_1 ;
T_2 V_60 = ( ( V_58 [ 2 ] << 24 ) & 0xff000000 ) | ( ( V_58 [ 3 ] << 16 ) & 0x00ff0000 ) |
( ( V_58 [ 4 ] << 8 ) & 0x0000ff00 ) | ( ( V_58 [ 5 ] << 0 ) & 0x000000ff ) ;
T_3 V_61 = ( ( V_58 [ 7 ] << 8 ) & 0xff00 ) | ( ( V_58 [ 8 ] << 0 ) & 0x00ff ) ;
T_2 V_62 = V_60 * 0x200 ;
T_2 V_63 = V_61 * 0x200 ;
if ( V_60 > V_37 -> V_45 )
return V_21 ;
V_12 = F_20 ( V_3 , V_64 ) ;
if ( V_12 != V_20 ) {
F_4 ( L_8 ) ;
return V_21 ;
}
if ( V_37 -> V_38 . V_50 )
V_62 = V_60 ;
memset ( V_8 , 0 , sizeof( struct V_7 ) ) ;
V_8 -> V_65 = F_21 ( V_66 ) ;
V_8 -> V_17 = V_63 ;
V_8 -> V_67 = 0x80 ;
V_8 -> V_68 [ 0 ] = 0xF1 ;
V_8 -> V_68 [ 5 ] = ( unsigned char ) ( V_62 ) ;
V_8 -> V_68 [ 4 ] = ( unsigned char ) ( V_62 >> 8 ) ;
V_8 -> V_68 [ 3 ] = ( unsigned char ) ( V_62 >> 16 ) ;
V_8 -> V_68 [ 2 ] = ( unsigned char ) ( V_62 >> 24 ) ;
V_12 = F_2 ( V_3 , V_23 , F_22 ( V_25 ) , 1 ) ;
return V_12 ;
}
static int F_23 ( struct V_2 * V_3 , struct V_35 * V_25 )
{
int V_12 ;
unsigned char * V_58 = V_25 -> V_59 ;
struct V_7 * V_8 = (struct V_7 * ) V_3 -> V_9 ;
struct V_36 * V_37 = (struct V_36 * ) V_3 -> V_1 ;
T_2 V_60 = ( ( V_58 [ 2 ] << 24 ) & 0xff000000 ) | ( ( V_58 [ 3 ] << 16 ) & 0x00ff0000 ) |
( ( V_58 [ 4 ] << 8 ) & 0x0000ff00 ) | ( ( V_58 [ 5 ] << 0 ) & 0x000000ff ) ;
T_3 V_61 = ( ( V_58 [ 7 ] << 8 ) & 0xff00 ) | ( ( V_58 [ 8 ] << 0 ) & 0x00ff ) ;
T_2 V_62 = V_60 * 0x200 ;
T_2 V_63 = V_61 * 0x200 ;
if ( V_60 > V_37 -> V_45 )
return V_21 ;
V_12 = F_20 ( V_3 , V_64 ) ;
if ( V_12 != V_20 ) {
F_4 ( L_8 ) ;
return V_21 ;
}
if ( V_37 -> V_38 . V_50 )
V_62 = V_60 ;
memset ( V_8 , 0 , sizeof( struct V_7 ) ) ;
V_8 -> V_65 = F_21 ( V_66 ) ;
V_8 -> V_17 = V_63 ;
V_8 -> V_67 = 0x00 ;
V_8 -> V_68 [ 0 ] = 0xF0 ;
V_8 -> V_68 [ 5 ] = ( unsigned char ) ( V_62 ) ;
V_8 -> V_68 [ 4 ] = ( unsigned char ) ( V_62 >> 8 ) ;
V_8 -> V_68 [ 3 ] = ( unsigned char ) ( V_62 >> 16 ) ;
V_8 -> V_68 [ 2 ] = ( unsigned char ) ( V_62 >> 24 ) ;
V_12 = F_2 ( V_3 , V_69 , F_22 ( V_25 ) , 1 ) ;
return V_12 ;
}
static int F_24 ( struct V_2 * V_3 , T_3 V_70 , T_3 V_71 )
{
struct V_36 * V_37 = (struct V_36 * ) V_3 -> V_1 ;
if ( ( V_70 >= V_37 -> V_72 . V_73 ) || ( V_71 >= V_37 -> V_72 . V_74 ) )
return ( T_2 ) - 1 ;
V_37 -> V_72 . V_75 [ V_71 ] = V_70 ;
V_37 -> V_72 . V_76 [ V_70 ] = V_71 ;
return 0 ;
}
static int F_25 ( struct V_2 * V_3 , T_3 V_71 , T_3 V_77 )
{
struct V_36 * V_37 = (struct V_36 * ) V_3 -> V_1 ;
if ( V_71 >= V_37 -> V_72 . V_74 )
return ( T_2 ) - 1 ;
V_37 -> V_72 . V_75 [ V_71 ] = V_77 ;
return 0 ;
}
static int F_26 ( struct V_2 * V_3 , T_3 V_71 )
{
return F_25 ( V_3 , V_71 , V_78 ) ;
}
static int F_27 ( struct V_2 * V_3 , T_3 V_71 )
{
return F_25 ( V_3 , V_71 , V_79 ) ;
}
static int F_28 ( struct V_2 * V_3 )
{
struct V_36 * V_37 = (struct V_36 * ) V_3 -> V_1 ;
F_29 ( V_37 -> V_72 . V_75 ) ;
V_37 -> V_72 . V_75 = NULL ;
F_29 ( V_37 -> V_72 . V_76 ) ;
V_37 -> V_72 . V_76 = NULL ;
return 0 ;
}
int F_30 ( struct V_2 * V_3 )
{
T_2 V_80 ;
struct V_36 * V_37 = (struct V_36 * ) V_3 -> V_1 ;
V_37 -> V_72 . V_75 = F_31 ( V_37 -> V_72 . V_74 * sizeof( T_3 ) , V_81 ) ;
V_37 -> V_72 . V_76 = F_31 ( V_37 -> V_72 . V_73 * sizeof( T_3 ) , V_81 ) ;
if ( ( V_37 -> V_72 . V_75 == NULL ) || ( V_37 -> V_72 . V_76 == NULL ) ) {
F_28 ( V_3 ) ;
return ( T_2 ) - 1 ;
}
for ( V_80 = 0 ; V_80 < V_37 -> V_72 . V_74 ; V_80 ++ )
V_37 -> V_72 . V_75 [ V_80 ] = V_82 ;
for ( V_80 = 0 ; V_80 < V_37 -> V_72 . V_73 ; V_80 ++ )
V_37 -> V_72 . V_76 [ V_80 ] = V_82 ;
return 0 ;
}
static void F_32 ( struct V_2 * V_3 )
{
int V_80 ;
struct V_36 * V_37 = (struct V_36 * ) V_3 -> V_1 ;
V_37 -> V_72 . V_83 = ( T_3 ) - 1 ;
F_33 ( V_37 ) ;
if ( V_37 -> V_72 . V_84 )
memset ( V_37 -> V_72 . V_84 , 0xff , V_37 -> V_72 . V_85 * V_37 -> V_72 . V_86 ) ;
if ( V_37 -> V_72 . V_87 ) {
for ( V_80 = 0 ; V_80 < V_37 -> V_72 . V_85 ; V_80 ++ ) {
V_37 -> V_72 . V_87 [ V_80 ] . V_88 = V_89 ;
V_37 -> V_72 . V_87 [ V_80 ] . V_90 = V_91 ;
V_37 -> V_72 . V_87 [ V_80 ] . V_92 = V_93 ;
V_37 -> V_72 . V_87 [ V_80 ] . V_94 = V_82 ;
}
}
}
static int F_34 ( struct V_2 * V_3 , T_3 V_95 )
{
T_2 V_96 , V_97 ;
struct V_36 * V_37 = (struct V_36 * ) V_3 -> V_1 ;
V_96 = V_95 + V_98 ;
for ( V_97 = 0 ; V_95 < V_96 ; V_95 ++ ) {
switch ( V_37 -> V_72 . V_75 [ V_95 ] ) {
case V_82 :
case V_99 :
V_97 ++ ;
default:
break;
}
}
return V_97 ;
}
static int F_35 ( struct V_2 * V_3 , T_2 V_100 ,
T_1 V_101 , T_2 * V_102 , struct V_103 * V_104 )
{
struct V_7 * V_8 = (struct V_7 * ) V_3 -> V_9 ;
int V_12 ;
T_1 V_105 [ 4 ] ;
T_2 V_60 = V_100 * 0x20 + V_101 ;
V_12 = F_20 ( V_3 , V_106 ) ;
if ( V_12 != V_20 )
return V_21 ;
memset ( V_8 , 0 , sizeof( struct V_7 ) ) ;
V_8 -> V_65 = F_21 ( V_66 ) ;
V_8 -> V_17 = 0x200 ;
V_8 -> V_67 = 0x80 ;
V_8 -> V_68 [ 0 ] = 0xF1 ;
V_8 -> V_68 [ 1 ] = 0x02 ;
V_8 -> V_68 [ 5 ] = ( unsigned char ) ( V_60 ) ;
V_8 -> V_68 [ 4 ] = ( unsigned char ) ( V_60 >> 8 ) ;
V_8 -> V_68 [ 3 ] = ( unsigned char ) ( V_60 >> 16 ) ;
V_8 -> V_68 [ 2 ] = ( unsigned char ) ( V_60 >> 24 ) ;
V_12 = F_2 ( V_3 , V_23 , V_102 , 0 ) ;
if ( V_12 != V_20 )
return V_21 ;
memset ( V_8 , 0 , sizeof( struct V_7 ) ) ;
V_8 -> V_65 = F_21 ( V_66 ) ;
V_8 -> V_17 = 0x4 ;
V_8 -> V_67 = 0x80 ;
V_8 -> V_68 [ 0 ] = 0xF1 ;
V_8 -> V_68 [ 1 ] = 0x03 ;
V_8 -> V_68 [ 5 ] = ( unsigned char ) ( V_101 ) ;
V_8 -> V_68 [ 4 ] = ( unsigned char ) ( V_100 ) ;
V_8 -> V_68 [ 3 ] = ( unsigned char ) ( V_100 >> 8 ) ;
V_8 -> V_68 [ 2 ] = ( unsigned char ) ( V_100 >> 16 ) ;
V_8 -> V_68 [ 6 ] = 0x01 ;
V_12 = F_2 ( V_3 , V_23 , & V_105 , 0 ) ;
if ( V_12 != V_20 )
return V_21 ;
V_104 -> V_107 = 0 ;
V_104 -> V_108 = 0x80 ;
V_104 -> V_109 = 0x10 ;
V_104 -> V_88 = 0x00 ;
V_104 -> V_90 = V_105 [ 0 ] ;
V_104 -> V_92 = V_105 [ 1 ] ;
V_104 -> V_94 = F_36 ( V_105 [ 2 ] , V_105 [ 3 ] ) ;
return V_34 ;
}
static int F_37 ( struct V_2 * V_3 , T_3 V_95 , T_1 * V_110 )
{
struct V_111 * V_112 ;
struct V_113 * V_114 ;
T_2 V_80 , V_12 ;
T_1 V_115 ;
T_1 * V_116 ;
struct V_103 V_117 ;
struct V_36 * V_37 = (struct V_36 * ) V_3 -> V_1 ;
V_116 = F_31 ( V_118 , V_81 ) ;
if ( V_116 == NULL )
return ( T_2 ) - 1 ;
V_12 = ( T_2 ) - 1 ;
V_114 = & ( ( (struct V_119 * ) V_110 ) -> V_120 ) ;
if ( ( V_114 -> V_121 != V_122 ) ||
( F_38 ( V_114 -> V_123 ) != V_124 ) ||
( ( V_114 -> V_125 & V_126 ) == V_127 ) ||
( V_114 -> V_128 != V_129 ) ||
( V_114 -> V_130 != V_131 ) ||
( V_114 -> V_132 != V_133 ) ||
( V_114 -> V_134 != V_135 ) )
goto exit;
switch ( V_37 -> V_72 . V_136 = V_114 -> V_137 ) {
case V_138 :
F_39 ( V_37 , V_139 ) ;
break;
case V_140 :
F_40 ( V_37 , V_139 ) ;
break;
case V_141 :
default:
goto exit;
}
V_37 -> V_72 . V_142 = F_38 ( V_114 -> V_143 ) ;
V_37 -> V_72 . V_74 = F_38 ( V_114 -> V_144 ) ;
V_37 -> V_72 . V_73 = F_38 ( V_114 -> V_145 ) - 2 ;
V_37 -> V_72 . V_85 = V_37 -> V_72 . V_142 * V_146 / V_118 ;
V_37 -> V_72 . V_147 = V_37 -> V_72 . V_74 / V_98 ;
V_37 -> V_148 = F_38 ( V_114 -> V_149 ) ;
if ( F_30 ( V_3 ) )
goto exit;
F_27 ( V_3 , V_95 ) ;
V_112 = & ( ( (struct V_119 * ) V_110 ) -> V_150 ) ;
for ( V_80 = 0 ; V_80 < V_151 ; V_80 ++ ) {
T_2 V_152 , V_153 ;
V_152 = F_41 ( V_112 -> V_154 [ V_80 ] . V_155 ) ;
if ( V_152 == 0xffffff )
continue;
V_153 = F_41 ( V_112 -> V_154 [ V_80 ] . V_156 ) ;
if ( V_153 == 0 )
continue;
if ( V_152 + V_118 + V_153 > V_37 -> V_72 . V_142 * ( T_2 ) V_146 )
continue;
if ( V_80 == 0 ) {
T_1 V_157 = 0 ;
T_3 V_71 ;
if ( V_112 -> V_154 [ V_80 ] . V_158 != V_159 )
goto exit;
while ( V_153 > 0 ) {
V_115 = ( T_1 ) ( V_152 / V_118 + 1 ) ;
if ( V_115 != V_157 ) {
switch ( F_35 ( V_3 , V_95 , V_115 , ( T_2 * ) V_116 , & V_117 ) ) {
case V_160 :
break;
case V_161 :
case V_162 :
case V_163 :
default:
goto exit;
}
V_157 = V_115 ;
}
V_71 = F_38 ( * ( T_3 * ) ( V_116 + ( V_152 % V_118 ) ) ) ;
if ( V_71 < 0x0fff )
F_26 ( V_3 , V_71 ) ;
V_152 += 2 ;
V_153 -= 2 ;
}
} else if ( V_80 == 1 ) {
struct V_164 * V_165 ;
if ( V_112 -> V_154 [ V_80 ] . V_158 != V_166 )
goto exit;
switch ( F_35 ( V_3 , V_95 , ( T_1 ) ( V_152 / V_118 + 1 ) , ( T_2 * ) V_116 , & V_117 ) ) {
case V_160 :
break;
case V_161 :
case V_162 :
case V_163 :
default:
goto exit;
}
V_165 = & ( (struct V_167 * ) ( V_116 + ( V_152 % V_118 ) ) ) -> V_165 . V_165 ;
if ( F_42 ( V_165 -> V_168 ) != V_169 )
goto exit;
V_37 -> V_72 . V_86 = F_42 ( V_165 -> V_170 ) ;
if ( V_37 -> V_72 . V_86 != V_118 )
goto exit;
}
}
V_12 = 0 ;
exit:
if ( V_12 )
F_28 ( V_3 ) ;
F_29 ( V_116 ) ;
V_12 = 0 ;
return V_12 ;
}
static void F_43 ( struct V_2 * V_3 )
{
struct V_36 * V_37 = (struct V_36 * ) V_3 -> V_1 ;
V_37 -> V_72 . V_83 = ( T_3 ) - 1 ;
F_33 ( V_37 ) ;
if ( V_37 -> V_72 . V_84 ) {
F_29 ( ( T_1 * ) ( V_37 -> V_72 . V_84 ) ) ;
V_37 -> V_72 . V_84 = NULL ;
}
if ( V_37 -> V_72 . V_87 ) {
F_29 ( ( T_1 * ) ( V_37 -> V_72 . V_87 ) ) ;
V_37 -> V_72 . V_87 = NULL ;
}
}
static void F_44 ( struct V_2 * V_3 )
{
struct V_36 * V_37 = (struct V_36 * ) V_3 -> V_1 ;
F_43 ( V_3 ) ;
F_28 ( V_3 ) ;
V_37 -> V_72 . V_171 = 0 ;
V_37 -> V_72 . V_86 = 0 ;
V_37 -> V_72 . V_172 = 0 ;
V_37 -> V_72 . V_136 = 0 ;
V_37 -> V_72 . V_142 = 0 ;
V_37 -> V_72 . V_85 = 0 ;
V_37 -> V_72 . V_74 = 0 ;
V_37 -> V_72 . V_73 = 0 ;
}
static int F_45 ( struct V_2 * V_3 )
{
struct V_36 * V_37 = (struct V_36 * ) V_3 -> V_1 ;
V_37 -> V_72 . V_83 = ( T_3 ) - 1 ;
V_37 -> V_72 . V_84 = F_31 ( V_37 -> V_72 . V_85 * V_37 -> V_72 . V_86 , V_81 ) ;
V_37 -> V_72 . V_87 = F_31 ( V_37 -> V_72 . V_85 * sizeof( struct V_103 ) , V_81 ) ;
if ( ( V_37 -> V_72 . V_84 == NULL ) || ( V_37 -> V_72 . V_87 == NULL ) ) {
F_43 ( V_3 ) ;
return ( T_2 ) - 1 ;
}
F_32 ( V_3 ) ;
return 0 ;
}
static int F_46 ( struct V_2 * V_3 , T_3 V_70 , T_3 V_71 )
{
struct V_36 * V_37 = (struct V_36 * ) V_3 -> V_1 ;
if ( V_70 == V_82 )
return 0 ;
if ( ( V_70 >= V_37 -> V_72 . V_73 ) ||
( V_71 >= V_37 -> V_72 . V_74 ) )
return ( T_2 ) - 1 ;
V_37 -> V_72 . V_75 [ V_71 ] = V_70 ;
V_37 -> V_72 . V_76 [ V_70 ] = V_71 ;
return 0 ;
}
static int F_47 ( struct V_2 * V_3 , T_3 V_173 , T_3 V_174 ,
T_3 V_100 , T_1 V_101 , unsigned char * V_5 , T_3 V_175 )
{
struct V_7 * V_8 = (struct V_7 * ) V_3 -> V_9 ;
int V_12 ;
V_12 = F_20 ( V_3 , V_106 ) ;
if ( V_12 != V_20 )
return V_21 ;
memset ( V_8 , 0 , sizeof( struct V_7 ) ) ;
V_8 -> V_65 = F_21 ( V_66 ) ;
V_8 -> V_17 = 0x200 * V_175 ;
V_8 -> V_67 = 0x00 ;
V_8 -> V_68 [ 0 ] = 0xF0 ;
V_8 -> V_68 [ 1 ] = 0x08 ;
V_8 -> V_68 [ 4 ] = ( unsigned char ) ( V_173 ) ;
V_8 -> V_68 [ 3 ] = ( unsigned char ) ( V_173 >> 8 ) ;
V_8 -> V_68 [ 2 ] = 0 ;
V_8 -> V_68 [ 7 ] = ( unsigned char ) ( V_174 ) ;
V_8 -> V_68 [ 6 ] = ( unsigned char ) ( V_174 >> 8 ) ;
V_8 -> V_68 [ 5 ] = 0 ;
V_8 -> V_68 [ 9 ] = ( unsigned char ) ( V_100 ) ;
V_8 -> V_68 [ 8 ] = ( unsigned char ) ( V_100 >> 8 ) ;
V_8 -> V_68 [ 10 ] = V_101 ;
V_12 = F_2 ( V_3 , V_69 , V_5 , 0 ) ;
if ( V_12 != V_20 )
return V_21 ;
return V_34 ;
}
static int F_48 ( struct V_2 * V_3 , T_2 V_100 )
{
struct V_7 * V_8 = (struct V_7 * ) V_3 -> V_9 ;
int V_12 ;
T_2 V_60 = V_100 ;
V_12 = F_20 ( V_3 , V_106 ) ;
if ( V_12 != V_20 )
return V_21 ;
memset ( V_8 , 0 , sizeof( struct V_7 ) ) ;
V_8 -> V_65 = F_21 ( V_66 ) ;
V_8 -> V_17 = 0x200 ;
V_8 -> V_67 = 0x80 ;
V_8 -> V_68 [ 0 ] = 0xF2 ;
V_8 -> V_68 [ 1 ] = 0x06 ;
V_8 -> V_68 [ 4 ] = ( unsigned char ) ( V_60 ) ;
V_8 -> V_68 [ 3 ] = ( unsigned char ) ( V_60 >> 8 ) ;
V_8 -> V_68 [ 2 ] = ( unsigned char ) ( V_60 >> 16 ) ;
V_12 = F_2 ( V_3 , V_23 , NULL , 0 ) ;
if ( V_12 != V_20 )
return V_21 ;
return V_34 ;
}
static int F_49 ( struct V_2 * V_3 , T_3 V_95 )
{
unsigned char * V_102 = NULL ;
T_3 V_12 = V_160 ;
T_3 V_176 , V_177 = 0 ;
struct V_103 V_178 ;
struct V_36 * V_37 = (struct V_36 * ) V_3 -> V_1 ;
V_102 = F_31 ( V_118 , V_81 ) ;
if ( V_102 == NULL ) {
V_12 = V_179 ;
goto exit;
}
F_35 ( V_3 , V_95 , 1 , ( T_2 * ) V_102 , & V_178 ) ;
do {
V_176 = F_38 ( V_102 [ V_177 ] ) ;
if ( V_176 == V_82 )
break;
if ( V_176 == V_37 -> V_72 . V_76 [ 0 ] ) {
V_12 = V_162 ;
break;
}
V_177 ++ ;
} while ( 1 );
exit:
F_29 ( V_102 ) ;
return V_12 ;
}
static int F_50 ( struct V_2 * V_3 , T_3 V_71 )
{
T_3 log ;
struct V_36 * V_37 = (struct V_36 * ) V_3 -> V_1 ;
if ( V_71 >= V_37 -> V_72 . V_74 )
return ( T_2 ) - 1 ;
log = V_37 -> V_72 . V_75 [ V_71 ] ;
if ( log < V_37 -> V_72 . V_73 )
V_37 -> V_72 . V_76 [ log ] = V_82 ;
if ( V_37 -> V_72 . V_75 [ V_71 ] != V_78 )
V_37 -> V_72 . V_75 [ V_71 ] = V_180 ;
return 0 ;
}
static int F_51 ( struct V_2 * V_3 , T_2 V_100 ,
T_1 V_101 , T_1 V_181 )
{
struct V_7 * V_8 = (struct V_7 * ) V_3 -> V_9 ;
int V_12 ;
V_12 = F_20 ( V_3 , V_106 ) ;
if ( V_12 != V_20 )
return V_21 ;
memset ( V_8 , 0 , sizeof( struct V_7 ) ) ;
V_8 -> V_65 = F_21 ( V_66 ) ;
V_8 -> V_17 = 0x4 ;
V_8 -> V_67 = 0x80 ;
V_8 -> V_68 [ 0 ] = 0xF2 ;
V_8 -> V_68 [ 1 ] = 0x05 ;
V_8 -> V_68 [ 5 ] = ( unsigned char ) ( V_101 ) ;
V_8 -> V_68 [ 4 ] = ( unsigned char ) ( V_100 ) ;
V_8 -> V_68 [ 3 ] = ( unsigned char ) ( V_100 >> 8 ) ;
V_8 -> V_68 [ 2 ] = ( unsigned char ) ( V_100 >> 16 ) ;
V_8 -> V_68 [ 6 ] = V_181 ;
V_8 -> V_68 [ 7 ] = 0xFF ;
V_8 -> V_68 [ 8 ] = 0xFF ;
V_8 -> V_68 [ 9 ] = 0xFF ;
V_12 = F_2 ( V_3 , V_23 , NULL , 0 ) ;
if ( V_12 != V_20 )
return V_21 ;
return V_34 ;
}
static int F_52 ( struct V_2 * V_3 , T_3 V_71 )
{
struct V_36 * V_37 = (struct V_36 * ) V_3 -> V_1 ;
if ( V_71 >= V_37 -> V_72 . V_74 )
return V_163 ;
F_50 ( V_3 , V_71 ) ;
if ( F_53 ( V_37 ) )
return F_51 ( V_3 , V_71 , 0 , ( T_1 ) ( ~ V_182 & V_183 ) ) ;
return V_160 ;
}
static int F_54 ( struct V_2 * V_3 , T_3 V_71 )
{
T_3 log ;
struct V_36 * V_37 = (struct V_36 * ) V_3 -> V_1 ;
if ( V_71 >= V_37 -> V_72 . V_74 )
return V_163 ;
log = V_37 -> V_72 . V_75 [ V_71 ] ;
if ( log < V_37 -> V_72 . V_73 )
V_37 -> V_72 . V_76 [ log ] = V_82 ;
V_37 -> V_72 . V_75 [ V_71 ] = V_82 ;
if ( F_53 ( V_37 ) ) {
switch ( F_48 ( V_3 , V_71 ) ) {
case V_160 :
V_37 -> V_72 . V_75 [ V_71 ] = V_99 ;
return V_160 ;
case V_184 :
case V_185 :
F_52 ( V_3 , V_71 ) ;
return V_184 ;
case V_163 :
default:
F_39 ( V_37 , V_139 ) ;
F_50 ( V_3 , V_71 ) ;
return V_163 ;
}
}
F_50 ( V_3 , V_71 ) ;
return V_160 ;
}
static int F_55 ( struct V_2 * V_3 , T_2 V_95 ,
T_1 V_101 , struct V_103 * V_104 )
{
struct V_7 * V_8 = (struct V_7 * ) V_3 -> V_9 ;
int V_12 ;
T_1 V_105 [ 4 ] ;
memset ( V_8 , 0 , sizeof( struct V_7 ) ) ;
V_8 -> V_65 = F_21 ( V_66 ) ;
V_8 -> V_17 = 0x4 ;
V_8 -> V_67 = 0x80 ;
V_8 -> V_68 [ 0 ] = 0xF1 ;
V_8 -> V_68 [ 1 ] = 0x03 ;
V_8 -> V_68 [ 5 ] = ( unsigned char ) ( V_101 ) ;
V_8 -> V_68 [ 4 ] = ( unsigned char ) ( V_95 ) ;
V_8 -> V_68 [ 3 ] = ( unsigned char ) ( V_95 >> 8 ) ;
V_8 -> V_68 [ 2 ] = ( unsigned char ) ( V_95 >> 16 ) ;
V_8 -> V_68 [ 6 ] = 0x01 ;
V_12 = F_2 ( V_3 , V_23 , & V_105 , 0 ) ;
if ( V_12 != V_20 )
return V_21 ;
V_104 -> V_107 = 0 ;
V_104 -> V_108 = 0x80 ;
V_104 -> V_109 = 0x10 ;
V_104 -> V_88 = 0x00 ;
V_104 -> V_90 = V_105 [ 0 ] ;
V_104 -> V_92 = V_105 [ 1 ] ;
V_104 -> V_94 = F_36 ( V_105 [ 2 ] , V_105 [ 3 ] ) ;
return V_34 ;
}
static int F_56 ( struct V_2 * V_3 , T_3 V_71 )
{
T_3 V_186 ;
T_3 V_176 ;
struct V_103 V_178 ;
struct V_36 * V_37 = (struct V_36 * ) V_3 -> V_1 ;
if ( V_71 >= V_37 -> V_72 . V_74 )
return V_187 ;
for ( V_176 = V_71 + 1 ; V_176 != V_71 ; V_176 ++ ) {
if ( ( V_176 & V_188 ) == 0 )
V_176 -= V_98 ;
V_186 = V_37 -> V_72 . V_75 [ V_176 ] ;
if ( V_37 -> V_72 . V_75 [ V_176 ] == V_99 ) {
return V_176 ;
} else if ( V_37 -> V_72 . V_75 [ V_176 ] == V_82 ) {
switch ( F_55 ( V_3 , V_176 , 0 , & V_178 ) ) {
case V_160 :
case V_189 :
break;
case V_190 :
return V_190 ;
case V_185 :
return V_187 ;
case V_162 :
default:
F_50 ( V_3 , V_176 ) ;
continue;
}
if ( ( V_178 . V_90 & V_182 ) != V_191 ) {
F_50 ( V_3 , V_176 ) ;
continue;
}
switch ( F_54 ( V_3 , V_176 ) ) {
case V_160 :
return V_176 ;
case V_163 :
return V_187 ;
case V_184 :
default:
F_52 ( V_3 , V_176 ) ;
break;
}
}
}
return V_187 ;
}
static int F_57 ( struct V_2 * V_3 , T_3 V_70 )
{
T_3 V_71 ;
struct V_36 * V_37 = (struct V_36 * ) V_3 -> V_1 ;
V_71 = F_58 ( V_37 , V_70 ) ;
if ( V_71 >= V_187 ) {
if ( V_70 >= V_37 -> V_72 . V_73 )
return V_187 ;
V_71 = ( V_70 + V_192 ) / V_193 ;
V_71 *= V_98 ;
V_71 += V_98 - 1 ;
}
return F_56 ( V_3 , V_71 ) ;
}
static int F_59 ( struct V_2 * V_3 , struct V_35 * V_25 )
{
struct V_36 * V_37 = (struct V_36 * ) ( V_3 -> V_1 ) ;
if ( V_37 -> V_194 . V_39 && V_37 -> V_194 . V_40 ) {
return V_34 ;
} else {
F_60 ( V_3 ) ;
return V_34 ;
}
return V_34 ;
}
static int F_61 ( struct V_2 * V_3 , struct V_35 * V_25 )
{
unsigned char V_41 [ 36 ] = {
0x00 , 0x80 , 0x02 , 0x00 , 0x1F , 0x00 , 0x00 , 0x00 , 0x55 ,
0x53 , 0x42 , 0x32 , 0x2E , 0x30 , 0x20 , 0x20 , 0x43 , 0x61 ,
0x72 , 0x64 , 0x52 , 0x65 , 0x61 , 0x64 , 0x65 , 0x72 , 0x20 ,
0x20 , 0x20 , 0x20 , 0x20 , 0x20 , 0x30 , 0x31 , 0x30 , 0x30 } ;
F_15 ( V_41 , 36 , V_25 ) ;
return V_34 ;
}
static int F_62 ( struct V_2 * V_3 , struct V_35 * V_25 )
{
struct V_36 * V_37 = (struct V_36 * ) V_3 -> V_1 ;
unsigned char V_42 [ 12 ] = {
0x0b , 0x00 , 0x00 , 0x08 , 0x00 , 0x00 ,
0x71 , 0xc0 , 0x00 , 0x00 , 0x02 , 0x00 } ;
unsigned char V_43 [ 12 ] = {
0x0b , 0x00 , 0x80 , 0x08 , 0x00 , 0x00 ,
0x71 , 0xc0 , 0x00 , 0x00 , 0x02 , 0x00 } ;
if ( V_37 -> V_194 . V_44 )
F_15 ( V_43 , 12 , V_25 ) ;
else
F_15 ( V_42 , 12 , V_25 ) ;
return V_34 ;
}
static int F_63 ( struct V_2 * V_3 , struct V_35 * V_25 )
{
T_2 V_45 ;
T_3 V_46 ;
unsigned int V_47 = 0 ;
unsigned char V_5 [ 8 ] ;
struct V_48 * V_49 = NULL ;
struct V_36 * V_37 = (struct V_36 * ) V_3 -> V_1 ;
F_4 ( L_9 ) ;
V_46 = 0x200 ;
if ( V_37 -> V_194 . V_195 )
V_45 = V_37 -> V_196 - 1 ;
else
V_45 = V_37 -> V_72 . V_73 * V_37 -> V_72 . V_142 * 2 - 1 ;
V_37 -> V_45 = V_45 ;
F_4 ( L_6 , V_46 ) ;
F_4 ( L_7 , V_45 ) ;
V_5 [ 0 ] = ( V_45 >> 24 ) & 0xff ;
V_5 [ 1 ] = ( V_45 >> 16 ) & 0xff ;
V_5 [ 2 ] = ( V_45 >> 8 ) & 0xff ;
V_5 [ 3 ] = ( V_45 >> 0 ) & 0xff ;
V_5 [ 4 ] = ( V_46 >> 24 ) & 0xff ;
V_5 [ 5 ] = ( V_46 >> 16 ) & 0xff ;
V_5 [ 6 ] = ( V_46 >> 8 ) & 0xff ;
V_5 [ 7 ] = ( V_46 >> 0 ) & 0xff ;
F_18 ( V_5 , 8 , V_25 , & V_49 , & V_47 , V_57 ) ;
return V_34 ;
}
static void F_64 ( T_3 V_95 , T_3 * V_197 , T_3 * V_198 )
{
V_95 /= V_98 ;
if ( V_95 ) {
* V_197 = V_199 + ( V_95 - 1 ) * V_193 ;
* V_198 = * V_197 + V_193 ;
} else {
* V_197 = 0 ;
* V_198 = V_199 ;
}
}
static int F_65 ( struct V_2 * V_3 , T_2 V_95 ,
T_1 V_101 , T_1 V_61 , void * V_5 )
{
struct V_7 * V_8 = (struct V_7 * ) V_3 -> V_9 ;
int V_12 ;
memset ( V_8 , 0 , sizeof( struct V_7 ) ) ;
V_8 -> V_65 = F_21 ( V_66 ) ;
V_8 -> V_17 = 0x4 * V_61 ;
V_8 -> V_67 = 0x80 ;
V_8 -> V_68 [ 0 ] = 0xF1 ;
V_8 -> V_68 [ 1 ] = 0x03 ;
V_8 -> V_68 [ 5 ] = ( unsigned char ) ( V_101 ) ;
V_8 -> V_68 [ 4 ] = ( unsigned char ) ( V_95 ) ;
V_8 -> V_68 [ 3 ] = ( unsigned char ) ( V_95 >> 8 ) ;
V_8 -> V_68 [ 2 ] = ( unsigned char ) ( V_95 >> 16 ) ;
V_8 -> V_68 [ 6 ] = V_61 ;
V_12 = F_2 ( V_3 , V_23 , V_5 , 0 ) ;
if ( V_12 != V_20 )
return V_21 ;
return V_34 ;
}
static int F_66 ( struct V_2 * V_3 , T_3 V_200 )
{
T_3 V_95 , V_201 , V_80 ;
T_3 V_197 , V_198 ;
struct V_103 V_178 ;
T_1 V_5 [ 0x200 ] ;
T_2 V_202 = 0 , V_177 = 0 ;
struct V_36 * V_37 = (struct V_36 * ) V_3 -> V_1 ;
for ( V_95 = 0 ; V_95 < V_37 -> V_72 . V_74 ; ) {
F_64 ( V_95 , & V_197 , & V_198 ) ;
for ( V_80 = 0 ; V_80 < V_98 ; V_80 ++ , V_95 ++ ) {
switch ( F_67 ( V_37 , V_95 ) ) {
case V_163 :
continue;
default:
break;
}
if ( V_202 == V_95 ) {
F_65 ( V_3 , V_95 , 0 , 0x80 , & V_5 ) ;
V_202 += 0x80 ;
}
V_177 = ( V_95 % 0x80 ) * 4 ;
V_178 . V_90 = V_5 [ V_177 ] ;
V_178 . V_92 = V_5 [ V_177 + 1 ] ;
V_178 . V_94 = F_36 ( V_5 [ V_177 + 2 ] , V_5 [ V_177 + 3 ] ) ;
if ( ( V_178 . V_90 & V_182 ) != V_191 ) {
F_50 ( V_3 , V_95 ) ;
continue;
}
if ( ( V_178 . V_92 & V_203 ) == V_204 ) {
F_54 ( V_3 , V_95 ) ;
continue;
}
if ( V_178 . V_94 != V_82 ) {
if ( ( V_178 . V_94 < V_197 ) || ( V_198 <= V_178 . V_94 ) ) {
F_54 ( V_3 , V_95 ) ;
continue;
}
V_201 = F_58 ( V_37 , V_178 . V_94 ) ;
if ( V_201 != V_82 ) {
if ( V_178 . V_94 == 0 ) {
F_24 ( V_3 , V_178 . V_94 , V_95 ) ;
if ( F_49 ( V_3 , V_200 ) ) {
F_24 ( V_3 , V_178 . V_94 , V_201 ) ;
continue;
}
}
F_55 ( V_3 , V_201 , 0 , & V_178 ) ;
if ( ( V_178 . V_90 & V_205 ) == V_206 ) {
F_54 ( V_3 , V_95 ) ;
continue;
} else {
F_54 ( V_3 , V_201 ) ;
}
}
F_24 ( V_3 , V_178 . V_94 , V_95 ) ;
}
}
}
return V_160 ;
}
static int F_68 ( struct V_2 * V_3 , struct V_35 * V_25 )
{
int V_12 ;
unsigned char * V_58 = V_25 -> V_59 ;
struct V_7 * V_8 = (struct V_7 * ) V_3 -> V_9 ;
struct V_36 * V_37 = (struct V_36 * ) V_3 -> V_1 ;
T_2 V_60 = ( ( V_58 [ 2 ] << 24 ) & 0xff000000 ) | ( ( V_58 [ 3 ] << 16 ) & 0x00ff0000 ) |
( ( V_58 [ 4 ] << 8 ) & 0x0000ff00 ) | ( ( V_58 [ 5 ] << 0 ) & 0x000000ff ) ;
T_3 V_61 = ( ( V_58 [ 7 ] << 8 ) & 0xff00 ) | ( ( V_58 [ 8 ] << 0 ) & 0x00ff ) ;
T_2 V_63 = V_61 * 0x200 ;
if ( V_60 > V_37 -> V_45 )
return V_21 ;
if ( V_37 -> V_194 . V_195 ) {
V_12 = F_20 ( V_3 , V_207 ) ;
if ( V_12 != V_20 ) {
F_4 ( L_10 ) ;
return V_21 ;
}
memset ( V_8 , 0 , sizeof( struct V_7 ) ) ;
V_8 -> V_65 = F_21 ( V_66 ) ;
V_8 -> V_17 = V_63 ;
V_8 -> V_67 = 0x80 ;
V_8 -> V_68 [ 0 ] = 0xF1 ;
V_8 -> V_68 [ 1 ] = 0x02 ;
V_8 -> V_68 [ 5 ] = ( unsigned char ) ( V_60 ) ;
V_8 -> V_68 [ 4 ] = ( unsigned char ) ( V_60 >> 8 ) ;
V_8 -> V_68 [ 3 ] = ( unsigned char ) ( V_60 >> 16 ) ;
V_8 -> V_68 [ 2 ] = ( unsigned char ) ( V_60 >> 24 ) ;
V_12 = F_2 ( V_3 , V_23 , F_22 ( V_25 ) , 1 ) ;
} else {
void * V_5 ;
int V_47 = 0 ;
T_3 V_71 , V_70 ;
T_1 V_101 ;
T_3 V_175 ;
T_2 V_208 ;
V_5 = F_31 ( V_63 , V_81 ) ;
if ( V_5 == NULL )
return V_21 ;
V_12 = F_20 ( V_3 , V_106 ) ;
if ( V_12 != V_20 ) {
F_69 ( L_11 ) ;
V_12 = V_21 ;
goto exit;
}
V_70 = ( T_3 ) ( V_60 / V_37 -> V_72 . V_85 ) ;
V_101 = ( T_1 ) ( V_60 % V_37 -> V_72 . V_85 ) ;
while ( 1 ) {
if ( V_61 > ( V_37 -> V_72 . V_85 - V_101 ) )
V_175 = V_37 -> V_72 . V_85 - V_101 ;
else
V_175 = V_61 ;
V_71 = F_58 ( V_37 , V_70 ) ;
V_208 = V_71 * 0x20 + V_101 ;
memset ( V_8 , 0 , sizeof( struct V_7 ) ) ;
V_8 -> V_65 = F_21 ( V_66 ) ;
V_8 -> V_17 = 0x200 * V_175 ;
V_8 -> V_67 = 0x80 ;
V_8 -> V_68 [ 0 ] = 0xF1 ;
V_8 -> V_68 [ 1 ] = 0x02 ;
V_8 -> V_68 [ 5 ] = ( unsigned char ) ( V_208 ) ;
V_8 -> V_68 [ 4 ] = ( unsigned char ) ( V_208 >> 8 ) ;
V_8 -> V_68 [ 3 ] = ( unsigned char ) ( V_208 >> 16 ) ;
V_8 -> V_68 [ 2 ] = ( unsigned char ) ( V_208 >> 24 ) ;
V_12 = F_2 ( V_3 , V_23 , V_5 + V_47 , 0 ) ;
if ( V_12 != V_20 ) {
F_69 ( L_12 , V_12 ) ;
V_12 = V_21 ;
goto exit;
}
V_61 -= V_175 ;
if ( V_61 <= 0 )
break;
V_70 ++ ;
V_101 = 0 ;
V_47 += V_118 * V_175 ;
}
F_15 ( V_5 , V_63 , V_25 ) ;
exit:
F_29 ( V_5 ) ;
}
return V_12 ;
}
static int F_70 ( struct V_2 * V_3 , struct V_35 * V_25 )
{
int V_12 ;
struct V_7 * V_8 = (struct V_7 * ) V_3 -> V_9 ;
unsigned char * V_58 = V_25 -> V_59 ;
struct V_36 * V_37 = (struct V_36 * ) V_3 -> V_1 ;
T_2 V_60 = ( ( V_58 [ 2 ] << 24 ) & 0xff000000 ) |
( ( V_58 [ 3 ] << 16 ) & 0x00ff0000 ) |
( ( V_58 [ 4 ] << 8 ) & 0x0000ff00 ) |
( ( V_58 [ 5 ] << 0 ) & 0x000000ff ) ;
T_3 V_61 = ( ( V_58 [ 7 ] << 8 ) & 0xff00 ) | ( ( V_58 [ 8 ] << 0 ) & 0x00ff ) ;
T_2 V_63 = V_61 * 0x200 ;
if ( V_60 > V_37 -> V_45 )
return V_21 ;
if ( V_37 -> V_194 . V_195 ) {
V_12 = F_20 ( V_3 , V_207 ) ;
if ( V_12 != V_20 ) {
F_69 ( L_13 ) ;
return V_21 ;
}
memset ( V_8 , 0 , sizeof( struct V_7 ) ) ;
V_8 -> V_65 = F_21 ( V_66 ) ;
V_8 -> V_17 = V_63 ;
V_8 -> V_67 = 0x00 ;
V_8 -> V_68 [ 0 ] = 0xF0 ;
V_8 -> V_68 [ 1 ] = 0x04 ;
V_8 -> V_68 [ 5 ] = ( unsigned char ) ( V_60 ) ;
V_8 -> V_68 [ 4 ] = ( unsigned char ) ( V_60 >> 8 ) ;
V_8 -> V_68 [ 3 ] = ( unsigned char ) ( V_60 >> 16 ) ;
V_8 -> V_68 [ 2 ] = ( unsigned char ) ( V_60 >> 24 ) ;
V_12 = F_2 ( V_3 , V_69 , F_22 ( V_25 ) , 1 ) ;
} else {
void * V_5 ;
int V_47 = 0 ;
T_3 V_100 ;
T_1 V_101 ;
T_3 V_175 , V_173 , V_174 ;
V_5 = F_31 ( V_63 , V_81 ) ;
if ( V_5 == NULL )
return V_21 ;
F_15 ( V_5 , V_63 , V_25 ) ;
V_12 = F_20 ( V_3 , V_106 ) ;
if ( V_12 != V_20 ) {
F_69 ( L_11 ) ;
V_12 = V_21 ;
goto exit;
}
V_100 = ( T_3 ) ( V_60 / V_37 -> V_72 . V_85 ) ;
V_101 = ( T_1 ) ( V_60 % V_37 -> V_72 . V_85 ) ;
while ( 1 ) {
if ( V_61 > ( V_37 -> V_72 . V_85 - V_101 ) )
V_175 = V_37 -> V_72 . V_85 - V_101 ;
else
V_175 = V_61 ;
V_173 = F_58 ( V_37 , V_100 ) ;
V_174 = F_57 ( V_3 , V_100 ) ;
V_12 = F_47 ( V_3 , V_173 , V_174 , V_100 , V_101 , V_5 + V_47 , V_175 ) ;
if ( V_12 != V_20 ) {
F_69 ( L_14 , V_12 ) ;
V_12 = V_21 ;
goto exit;
}
V_37 -> V_72 . V_75 [ V_173 ] = V_99 ;
F_46 ( V_3 , V_100 , V_174 ) ;
V_61 -= V_175 ;
if ( V_61 <= 0 )
break;
V_100 ++ ;
V_101 = 0 ;
V_47 += V_118 * V_175 ;
}
exit:
F_29 ( V_5 ) ;
}
return V_12 ;
}
static int F_71 ( struct V_2 * V_3 , T_3 V_177 , void * V_5 )
{
struct V_7 * V_8 = (struct V_7 * ) V_3 -> V_9 ;
int V_12 ;
memset ( V_8 , 0 , sizeof( struct V_7 ) ) ;
V_8 -> V_65 = F_21 ( V_66 ) ;
V_8 -> V_17 = 0x01 ;
V_8 -> V_67 = 0x80 ;
V_8 -> V_68 [ 0 ] = 0xED ;
V_8 -> V_68 [ 2 ] = ( unsigned char ) ( V_177 >> 8 ) ;
V_8 -> V_68 [ 3 ] = ( unsigned char ) V_177 ;
V_12 = F_2 ( V_3 , V_23 , V_5 , 0 ) ;
return V_12 ;
}
static int F_72 ( struct V_2 * V_3 , T_1 * V_5 )
{
T_3 V_209 ;
T_2 V_210 ;
struct V_36 * V_37 = (struct V_36 * ) V_3 -> V_1 ;
V_210 = * ( T_2 * ) & V_5 [ 0x18 ] ;
V_37 -> V_53 = ( T_1 ) ( ( V_210 >> 8 ) & 0x0f ) ;
V_209 = ( T_3 ) V_210 ;
V_210 = * ( T_2 * ) ( & V_5 [ 0x14 ] ) ;
if ( V_37 -> V_38 . V_50 && ! V_37 -> V_38 . V_51 )
V_37 -> V_52 = ( V_210 >> 8 ) & 0x3fffff ;
V_37 -> V_55 = ( ( V_209 & 0x03 ) << 10 ) | ( T_3 ) ( V_210 >> 22 ) ;
V_37 -> V_56 = ( T_1 ) ( V_210 >> 7 ) & 0x07 ;
if ( V_37 -> V_38 . V_50 && V_37 -> V_38 . V_51 )
V_37 -> V_52 = * ( T_2 * ) ( & V_5 [ 0x100 ] ) ;
if ( V_37 -> V_53 > V_211 ) {
V_37 -> V_54 = 1 << ( V_37 -> V_53 - V_211 ) ;
V_37 -> V_53 = V_211 ;
} else {
V_37 -> V_54 = 1 ;
}
return V_34 ;
}
static int F_20 ( struct V_2 * V_3 , unsigned char V_212 )
{
int V_213 ;
char * V_214 = NULL ;
unsigned char * V_5 = NULL ;
const struct V_215 * V_216 = NULL ;
int V_12 = V_21 ;
struct V_7 * V_8 = (struct V_7 * ) V_3 -> V_9 ;
struct V_36 * V_37 = (struct V_36 * ) V_3 -> V_1 ;
if ( V_37 -> V_217 == V_212 )
return V_34 ;
switch ( V_212 ) {
case V_218 :
F_4 ( L_15 ) ;
V_214 = L_16 ;
break;
case V_219 :
F_4 ( L_17 ) ;
V_214 = L_18 ;
break;
case V_64 :
F_4 ( L_19 ) ;
V_214 = L_20 ;
break;
case V_220 :
F_4 ( L_21 ) ;
V_214 = L_22 ;
break;
case V_207 :
F_4 ( L_23 ) ;
V_214 = L_24 ;
break;
case V_106 :
F_4 ( L_25 ) ;
V_214 = L_26 ;
break;
default:
F_4 ( L_27 ) ;
goto V_221;
}
V_213 = F_73 ( & V_216 , V_214 , & V_3 -> V_222 -> V_223 ) ;
if ( V_213 ) {
F_4 ( L_28 , V_214 ) ;
goto V_221;
}
V_5 = F_31 ( V_216 -> V_224 , V_81 ) ;
if ( V_5 == NULL ) {
F_4 ( L_29 ) ;
goto V_221;
}
memcpy ( V_5 , V_216 -> V_225 , V_216 -> V_224 ) ;
memset ( V_8 , 0 , sizeof( struct V_7 ) ) ;
V_8 -> V_65 = F_21 ( V_66 ) ;
V_8 -> V_17 = V_216 -> V_224 ;
V_8 -> V_67 = 0x00 ;
V_8 -> V_68 [ 0 ] = 0xEF ;
V_12 = F_2 ( V_3 , V_69 , V_5 , 0 ) ;
V_37 -> V_217 = V_212 ;
F_29 ( V_5 ) ;
V_221:
if ( V_216 != NULL ) {
F_74 ( V_216 ) ;
V_216 = NULL ;
}
return V_12 ;
}
static int F_75 ( struct V_2 * V_3 )
{
T_2 V_12 ;
T_3 V_226 ;
unsigned char * V_227 = NULL , * V_228 = NULL ;
struct V_103 V_178 ;
T_3 V_200 , V_229 ;
T_2 V_230 ;
struct V_36 * V_37 = (struct V_36 * ) V_3 -> V_1 ;
F_76 ( V_231 L_30 ) ;
F_44 ( V_3 ) ;
V_227 = F_31 ( V_118 , V_81 ) ;
V_228 = F_31 ( V_118 , V_81 ) ;
if ( ( V_227 == NULL ) || ( V_228 == NULL ) ) {
V_12 = V_179 ;
goto exit;
}
V_200 = V_229 = V_82 ;
V_230 = 0 ;
for ( V_226 = 0 ; V_226 < V_232 + 2 ; V_226 ++ ) {
switch ( F_35 ( V_3 , V_226 , 0 , ( T_2 * ) V_227 , & V_178 ) ) {
case V_160 :
break;
case V_185 :
break;
case V_163 :
default:
continue;
}
if ( ( V_178 . V_90 & V_182 ) == V_233 )
continue;
if ( ( ( V_178 . V_92 & V_234 ) == V_235 ) ||
( F_38 ( ( (struct V_119 * ) V_227 ) -> V_236 . V_237 ) != V_238 ) ||
( F_38 ( ( (struct V_119 * ) V_227 ) -> V_236 . V_239 ) != V_240 ) ||
( ( (struct V_119 * ) V_227 ) -> V_236 . V_241 != V_242 ) )
continue;
if ( V_200 != V_82 ) {
V_229 = V_226 ;
break;
}
V_200 = V_226 ;
memcpy ( V_228 , V_227 , V_118 ) ;
if ( V_178 . V_88 & ( V_243 | V_244 | V_245 ) )
V_230 = 1 ;
}
if ( V_200 == V_82 ) {
V_12 = V_163 ;
goto exit;
}
if ( ( V_178 . V_109 & V_246 ) == V_247 )
F_39 ( V_37 , V_248 ) ;
V_12 = V_163 ;
if ( V_230 == 0 )
V_12 = F_37 ( V_3 , V_200 , V_228 ) ;
if ( V_12 && ( V_229 != V_82 ) )
V_12 = F_37 ( V_3 , V_229 , V_227 ) ;
if ( V_12 ) {
V_12 = V_163 ;
goto exit;
}
for ( V_226 = 0 ; V_226 < V_200 ; V_226 ++ )
V_37 -> V_72 . V_75 [ V_226 ] = V_78 ;
V_37 -> V_72 . V_75 [ V_200 ] = V_79 ;
if ( V_229 != V_82 ) {
for ( V_226 = V_200 + 1 ; V_226 < V_229 ; V_226 ++ )
V_37 -> V_72 . V_75 [ V_226 ] = V_78 ;
V_37 -> V_72 . V_75 [ V_229 ] = V_79 ;
}
V_12 = F_66 ( V_3 , V_200 ) ;
if ( V_12 )
goto exit;
for ( V_226 = V_98 ;
V_226 < V_37 -> V_72 . V_74 ;
V_226 += V_98 ) {
if ( F_34 ( V_3 , V_226 ) == 0 ) {
F_39 ( V_37 , V_248 ) ;
break;
}
}
if ( F_45 ( V_3 ) ) {
V_12 = V_179 ;
goto exit;
}
V_12 = V_160 ;
exit:
F_29 ( V_228 ) ;
F_29 ( V_227 ) ;
F_76 ( V_231 L_31 ) ;
return V_12 ;
}
static int F_60 ( struct V_2 * V_3 )
{
struct V_7 * V_8 = (struct V_7 * ) V_3 -> V_9 ;
int V_12 ;
T_1 V_5 [ 0x200 ] ;
T_3 V_249 , V_250 ;
struct V_36 * V_37 = (struct V_36 * ) V_3 -> V_1 ;
F_76 ( V_231 L_32 ) ;
V_12 = F_20 ( V_3 , V_220 ) ;
if ( V_12 != V_20 ) {
F_76 ( V_251 L_33 ) ;
return V_21 ;
}
memset ( V_8 , 0 , sizeof( struct V_7 ) ) ;
V_8 -> V_65 = F_21 ( V_66 ) ;
V_8 -> V_17 = 0x200 ;
V_8 -> V_67 = 0x80 ;
V_8 -> V_68 [ 0 ] = 0xF1 ;
V_8 -> V_68 [ 1 ] = 0x01 ;
V_12 = F_2 ( V_3 , V_23 , & V_5 , 0 ) ;
if ( V_12 != V_20 ) {
F_76 ( V_251 L_34 ) ;
return V_21 ;
}
V_37 -> V_194 = * (struct V_252 * ) & V_5 [ 0 ] ;
if ( V_37 -> V_194 . V_39 && V_37 -> V_194 . V_40 ) {
F_76 ( V_231 L_35 , V_37 -> V_194 . V_39 ) ;
F_76 ( V_231 L_36 , V_37 -> V_194 . V_40 ) ;
F_76 ( V_231 L_37 , V_37 -> V_194 . V_195 ) ;
F_76 ( V_231 L_38 , V_37 -> V_194 . V_253 ) ;
F_76 ( V_231 L_39 , V_37 -> V_194 . V_44 ) ;
if ( V_37 -> V_194 . V_195 ) {
V_249 = ( V_5 [ 6 ] << 8 ) | V_5 [ 7 ] ;
V_250 = ( V_5 [ 10 ] << 8 ) | V_5 [ 11 ] ;
V_37 -> V_196 = V_249 * V_250 ;
} else {
F_75 ( V_3 ) ;
}
F_4 ( L_40 ) ;
} else {
F_4 ( L_41 , V_5 [ 0 ] ) ;
return V_21 ;
}
return V_34 ;
}
static int F_13 ( struct V_2 * V_3 )
{
int V_12 ;
T_1 V_5 [ 0x200 ] ;
struct V_7 * V_8 = (struct V_7 * ) V_3 -> V_9 ;
struct V_36 * V_37 = (struct V_36 * ) V_3 -> V_1 ;
F_4 ( L_42 ) ;
V_12 = F_20 ( V_3 , V_218 ) ;
if ( V_12 != V_20 ) {
F_4 ( L_43 ) ;
return V_21 ;
}
memset ( V_8 , 0 , sizeof( struct V_7 ) ) ;
V_8 -> V_65 = F_21 ( V_66 ) ;
V_8 -> V_67 = 0x80 ;
V_8 -> V_68 [ 0 ] = 0xF2 ;
V_12 = F_2 ( V_3 , V_23 , NULL , 0 ) ;
if ( V_12 != V_20 ) {
F_4 ( L_44 ) ;
return V_21 ;
}
V_12 = F_20 ( V_3 , V_219 ) ;
if ( V_12 != V_20 ) {
F_4 ( L_45 ) ;
return V_21 ;
}
memset ( V_8 , 0 , sizeof( struct V_7 ) ) ;
V_8 -> V_65 = F_21 ( V_66 ) ;
V_8 -> V_17 = 0x200 ;
V_8 -> V_67 = 0x80 ;
V_8 -> V_68 [ 0 ] = 0xF1 ;
V_12 = F_2 ( V_3 , V_23 , & V_5 , 0 ) ;
if ( V_12 != V_20 ) {
F_4 ( L_44 ) ;
return V_21 ;
}
V_37 -> V_38 = * (struct V_254 * ) & V_5 [ 0 ] ;
if ( V_37 -> V_38 . V_39 && V_37 -> V_38 . V_40 ) {
F_72 ( V_3 , ( unsigned char * ) & V_5 ) ;
F_4 ( L_35 , V_37 -> V_38 . V_39 ) ;
F_4 ( L_36 , V_37 -> V_38 . V_40 ) ;
F_4 ( L_46 , V_37 -> V_38 . V_51 ) ;
F_4 ( L_47 , V_37 -> V_38 . V_50 ) ;
F_4 ( L_48 , V_37 -> V_38 . V_255 ) ;
F_4 ( L_49 , V_37 -> V_38 . V_44 ) ;
} else {
F_4 ( L_50 , V_5 [ 0 ] ) ;
return V_21 ;
}
return V_34 ;
}
static int F_77 ( struct V_2 * V_3 )
{
int V_12 ;
T_1 V_256 = 0 ;
struct V_36 * V_37 = (struct V_36 * ) ( V_3 -> V_1 ) ;
V_12 = F_71 ( V_3 , V_257 , & V_256 ) ;
if ( V_12 != V_20 )
return V_21 ;
if ( V_256 & 0x01 ) {
if ( ! V_37 -> V_38 . V_40 ) {
V_12 = F_13 ( V_3 ) ;
if ( V_12 != V_20 )
return V_21 ;
}
}
if ( V_256 & 0x02 ) {
if ( ! V_37 -> V_194 . V_40 ) {
V_12 = F_60 ( V_3 ) ;
if ( V_12 != V_20 )
return V_21 ;
}
}
return V_12 ;
}
static int F_78 ( struct V_2 * V_3 , struct V_35 * V_25 )
{
int V_12 ;
struct V_36 * V_37 = (struct V_36 * ) V_3 -> V_1 ;
V_37 -> V_258 = V_259 ;
switch ( V_25 -> V_59 [ 0 ] ) {
case V_260 :
V_12 = F_12 ( V_3 , V_25 ) ;
break;
case V_261 :
V_12 = F_14 ( V_3 , V_25 ) ;
break;
case V_262 :
V_12 = F_16 ( V_3 , V_25 ) ;
break;
case V_263 :
V_12 = F_17 ( V_3 , V_25 ) ;
break;
case V_264 :
V_12 = F_19 ( V_3 , V_25 ) ;
break;
case V_265 :
V_12 = F_23 ( V_3 , V_25 ) ;
break;
default:
V_37 -> V_258 = V_266 ;
V_12 = V_267 ;
break;
}
return V_12 ;
}
int F_79 ( struct V_2 * V_3 , struct V_35 * V_25 )
{
int V_12 ;
struct V_36 * V_37 = (struct V_36 * ) V_3 -> V_1 ;
V_37 -> V_258 = V_259 ;
switch ( V_25 -> V_59 [ 0 ] ) {
case V_260 :
V_12 = F_59 ( V_3 , V_25 ) ;
break;
case V_261 :
V_12 = F_61 ( V_3 , V_25 ) ;
break;
case V_262 :
V_12 = F_62 ( V_3 , V_25 ) ;
break;
case V_263 :
V_12 = F_63 ( V_3 , V_25 ) ;
break;
case V_264 :
V_12 = F_68 ( V_3 , V_25 ) ;
break;
case V_265 :
V_12 = F_70 ( V_3 , V_25 ) ;
break;
default:
V_37 -> V_258 = V_266 ;
V_12 = V_267 ;
break;
}
return V_12 ;
}
static int F_80 ( struct V_35 * V_25 , struct V_2 * V_3 )
{
int V_12 = 0 ;
struct V_36 * V_37 = (struct V_36 * ) ( V_3 -> V_1 ) ;
F_9 ( V_25 , 0 ) ;
if ( F_81 ( ! ( V_37 -> V_38 . V_40 || V_37 -> V_194 . V_40 ) ) ) {
V_12 = F_77 ( V_3 ) ;
} else {
if ( V_37 -> V_38 . V_40 )
V_12 = F_78 ( V_3 , V_25 ) ;
if ( V_37 -> V_194 . V_40 )
V_12 = F_79 ( V_3 , V_25 ) ;
}
return 0 ;
}
static int F_82 ( struct V_268 * V_269 ,
const struct V_270 * V_271 )
{
int V_12 ;
T_1 V_256 = 0 ;
struct V_2 * V_3 ;
V_12 = F_83 ( & V_3 , V_269 , V_271 ,
( V_271 - V_272 ) + V_273 ) ;
if ( V_12 )
return V_12 ;
if ( ! V_3 -> V_1 ) {
V_3 -> V_1 = F_84 ( sizeof( struct V_36 ) , V_81 ) ;
if ( ! V_3 -> V_1 )
return - V_274 ;
V_3 -> V_275 = F_1 ;
}
V_3 -> V_276 = L_51 ;
V_3 -> V_277 = F_80 ;
V_3 -> V_278 = 0 ;
V_12 = F_85 ( V_3 ) ;
if ( V_12 )
return V_12 ;
V_12 = F_71 ( V_3 , V_257 , & V_256 ) ;
if ( V_12 != V_20 ) {
F_86 ( V_269 ) ;
return V_21 ;
}
if ( ! ( V_256 & 0x01 ) ) {
F_69 ( L_52
L_53 ) ;
}
return V_12 ;
}
static int F_87 ( struct V_268 * V_279 )
{
T_1 V_280 = 0 ;
struct V_2 * V_3 = F_88 ( V_279 ) ;
struct V_36 * V_37 = (struct V_36 * ) ( V_3 -> V_1 ) ;
F_89 ( & V_3 -> V_281 ) ;
F_4 ( L_54 , V_282 ) ;
if ( V_3 -> V_283 )
( V_3 -> V_283 ) ( V_3 , V_284 ) ;
F_90 ( & V_3 -> V_281 ) ;
V_37 -> V_285 = true ;
V_37 -> V_38 = * (struct V_254 * ) & V_280 ;
V_37 -> V_194 = * (struct V_252 * ) & V_280 ;
V_37 -> V_286 = * (struct V_287 * ) & V_280 ;
return 0 ;
}
static int F_91 ( struct V_268 * V_279 )
{
T_1 V_280 = 0 ;
struct V_2 * V_3 = F_88 ( V_279 ) ;
struct V_36 * V_37 = (struct V_36 * ) ( V_3 -> V_1 ) ;
F_4 ( L_54 , V_282 ) ;
F_92 ( V_279 ) ;
V_37 -> V_285 = true ;
V_37 -> V_38 = * (struct V_254 * ) & V_280 ;
V_37 -> V_194 = * (struct V_252 * ) & V_280 ;
V_37 -> V_286 = * (struct V_287 * ) & V_280 ;
return 0 ;
}
static int T_4 F_93 ( void )
{
return F_94 ( & V_288 ) ;
}
static void T_5 F_95 ( void )
{
F_96 ( & V_288 ) ;
}
