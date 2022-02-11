static void F_1 ( void * V_1 )
{
struct V_2 * V_3 = (struct V_2 * ) V_1 ;
if ( ! V_1 )
return;
F_2 ( V_3 -> V_4 ) ;
}
static int F_3 ( struct V_5 * V_6 , T_1 V_7 , void * V_8 , int V_9 )
{
struct V_10 * V_11 = (struct V_10 * ) V_6 -> V_12 ;
struct V_13 * V_14 = (struct V_13 * ) V_6 -> V_12 ;
int V_15 ;
unsigned int V_16 ;
unsigned int V_17 = 0 , V_18 = 0 ;
unsigned int V_19 = V_11 -> V_20 ;
V_15 = F_4 ( V_6 , V_6 -> V_21 ,
V_11 , V_22 , NULL ) ;
if ( V_15 != V_23 ) {
F_5 ( V_6 , L_1 ) ;
return V_24 ;
}
if ( V_8 ) {
unsigned int V_25 = V_7 ;
if ( V_7 == V_26 )
V_25 = V_6 -> V_27 ;
else
V_25 = V_6 -> V_21 ;
if ( V_9 ) {
V_15 = F_6 ( V_6 , V_25 , V_6 -> V_28 ) ;
} else {
V_15 = F_7 ( V_6 , V_25 , V_8 ,
V_19 , 0 , & V_18 ) ;
}
if ( V_15 != V_23 ) {
F_5 ( V_6 , L_2 ) ;
return V_24 ;
}
}
V_15 = F_4 ( V_6 , V_6 -> V_27 , V_14 ,
V_29 , & V_17 ) ;
if ( V_15 == V_30 && V_17 == 0 ) {
F_5 ( V_6 , L_3 ) ;
V_15 = F_4 ( V_6 , V_6 -> V_27 ,
V_14 , V_29 , & V_17 ) ;
}
if ( V_15 == V_31 ) {
F_5 ( V_6 , L_4 ) ;
V_15 = F_4 ( V_6 , V_6 -> V_27 ,
V_14 , V_29 , NULL ) ;
}
if ( V_15 != V_23 )
return V_24 ;
V_16 = F_8 ( V_14 -> V_32 ) ;
if ( V_16 && ! ( V_6 -> V_33 & V_34 ) ) {
V_16 = F_9 ( V_16 , V_19 ) ;
if ( V_6 -> V_28 != NULL )
F_10 ( V_6 -> V_28 , F_11 ( F_12 ( V_6 -> V_28 ) ,
( int ) V_16 ) ) ;
}
if ( V_14 -> V_35 != V_36 )
return V_24 ;
return V_37 ;
}
static int F_13 ( struct V_5 * V_6 , struct V_38 * V_28 )
{
struct V_2 * V_3 = (struct V_2 * ) V_6 -> V_1 ;
unsigned char V_8 [ 18 ] ;
memset ( V_8 , 0 , 18 ) ;
V_8 [ 0 ] = 0x70 ;
V_8 [ 2 ] = V_3 -> V_39 >> 16 ;
V_8 [ 7 ] = 10 ;
V_8 [ 12 ] = V_3 -> V_39 >> 8 ;
V_8 [ 13 ] = V_3 -> V_39 ;
F_14 ( V_8 , sizeof( V_8 ) , V_28 ) ;
return V_37 ;
}
static int F_15 ( struct V_5 * V_6 , struct V_38 * V_28 )
{
unsigned char V_40 [ 36 ] = {
0x00 , 0x00 , 0x02 , 0x00 , 0x1F , 0x00 , 0x00 , 0x00 , 0x55 ,
0x53 , 0x42 , 0x32 , 0x2E , 0x30 , 0x20 , 0x20 , 0x43 , 0x61 ,
0x72 , 0x64 , 0x52 , 0x65 , 0x61 , 0x64 , 0x65 , 0x72 , 0x20 ,
0x20 , 0x20 , 0x20 , 0x20 , 0x20 , 0x30 , 0x31 , 0x30 , 0x30 } ;
F_14 ( V_40 , 36 , V_28 ) ;
return V_37 ;
}
static int F_16 ( struct V_5 * V_6 , struct V_38 * V_28 )
{
struct V_2 * V_3 = (struct V_2 * ) V_6 -> V_1 ;
if ( V_3 -> V_41 . V_42 && V_3 -> V_41 . V_43 )
return V_37 ;
else {
F_17 ( V_6 ) ;
return V_37 ;
}
return V_37 ;
}
static int F_18 ( struct V_5 * V_6 , struct V_38 * V_28 )
{
struct V_2 * V_3 = (struct V_2 * ) V_6 -> V_1 ;
unsigned char V_44 [ 12 ] = {
0x0b , 0x00 , 0x00 , 0x08 , 0x00 , 0x00 ,
0x71 , 0xc0 , 0x00 , 0x00 , 0x02 , 0x00 } ;
unsigned char V_45 [ 12 ] = {
0x0b , 0x00 , 0x80 , 0x08 , 0x00 , 0x00 ,
0x71 , 0xc0 , 0x00 , 0x00 , 0x02 , 0x00 } ;
if ( V_3 -> V_41 . V_46 )
F_14 ( V_45 , 12 , V_28 ) ;
else
F_14 ( V_44 , 12 , V_28 ) ;
return V_37 ;
}
static int F_19 ( struct V_5 * V_6 , struct V_38 * V_28 )
{
T_2 V_47 ;
T_2 V_48 ;
unsigned int V_49 = 0 ;
unsigned char V_8 [ 8 ] ;
struct V_50 * V_51 = NULL ;
struct V_2 * V_3 = (struct V_2 * ) V_6 -> V_1 ;
F_5 ( V_6 , L_5 ) ;
if ( V_3 -> V_41 . V_52 ) {
V_48 = 0x200 ;
if ( V_3 -> V_41 . V_53 )
V_47 = V_3 -> V_54 - 1 ;
else
V_47 = ( V_3 -> V_54 + 1 ) * 1024 - 1 ;
} else {
V_48 = 1 << ( V_3 -> V_55 ) ;
V_47 = V_3 -> V_56 * ( V_3 -> V_57 + 1 )
* ( 1 << ( V_3 -> V_58 + 2 ) ) - 1 ;
}
V_3 -> V_47 = V_47 ;
F_5 ( V_6 , L_6 , V_48 ) ;
F_5 ( V_6 , L_7 , V_47 ) ;
V_8 [ 0 ] = ( V_47 >> 24 ) & 0xff ;
V_8 [ 1 ] = ( V_47 >> 16 ) & 0xff ;
V_8 [ 2 ] = ( V_47 >> 8 ) & 0xff ;
V_8 [ 3 ] = ( V_47 >> 0 ) & 0xff ;
V_8 [ 4 ] = ( V_48 >> 24 ) & 0xff ;
V_8 [ 5 ] = ( V_48 >> 16 ) & 0xff ;
V_8 [ 6 ] = ( V_48 >> 8 ) & 0xff ;
V_8 [ 7 ] = ( V_48 >> 0 ) & 0xff ;
F_20 ( V_8 , 8 , V_28 , & V_51 , & V_49 , V_59 ) ;
return V_37 ;
}
static int F_21 ( struct V_5 * V_6 , struct V_38 * V_28 )
{
int V_15 ;
unsigned char * V_60 = V_28 -> V_61 ;
struct V_10 * V_11 = (struct V_10 * ) V_6 -> V_12 ;
struct V_2 * V_3 = (struct V_2 * ) V_6 -> V_1 ;
T_2 V_62 = ( ( V_60 [ 2 ] << 24 ) & 0xff000000 ) | ( ( V_60 [ 3 ] << 16 ) & 0x00ff0000 ) |
( ( V_60 [ 4 ] << 8 ) & 0x0000ff00 ) | ( ( V_60 [ 5 ] << 0 ) & 0x000000ff ) ;
T_3 V_63 = ( ( V_60 [ 7 ] << 8 ) & 0xff00 ) | ( ( V_60 [ 8 ] << 0 ) & 0x00ff ) ;
T_2 V_64 = V_62 * 0x200 ;
T_2 V_65 = V_63 * 0x200 ;
if ( V_62 > V_3 -> V_47 )
return V_24 ;
V_15 = F_22 ( V_6 , V_66 ) ;
if ( V_15 != V_23 ) {
F_5 ( V_6 , L_8 ) ;
return V_24 ;
}
if ( V_3 -> V_41 . V_52 )
V_64 = V_62 ;
memset ( V_11 , 0 , sizeof( struct V_10 ) ) ;
V_11 -> V_67 = F_23 ( V_68 ) ;
V_11 -> V_20 = V_65 ;
V_11 -> V_69 = V_70 ;
V_11 -> V_71 [ 0 ] = 0xF1 ;
V_11 -> V_71 [ 5 ] = ( unsigned char ) ( V_64 ) ;
V_11 -> V_71 [ 4 ] = ( unsigned char ) ( V_64 >> 8 ) ;
V_11 -> V_71 [ 3 ] = ( unsigned char ) ( V_64 >> 16 ) ;
V_11 -> V_71 [ 2 ] = ( unsigned char ) ( V_64 >> 24 ) ;
V_15 = F_3 ( V_6 , V_26 , F_24 ( V_28 ) , 1 ) ;
return V_15 ;
}
static int F_25 ( struct V_5 * V_6 , struct V_38 * V_28 )
{
int V_15 ;
unsigned char * V_60 = V_28 -> V_61 ;
struct V_10 * V_11 = (struct V_10 * ) V_6 -> V_12 ;
struct V_2 * V_3 = (struct V_2 * ) V_6 -> V_1 ;
T_2 V_62 = ( ( V_60 [ 2 ] << 24 ) & 0xff000000 ) | ( ( V_60 [ 3 ] << 16 ) & 0x00ff0000 ) |
( ( V_60 [ 4 ] << 8 ) & 0x0000ff00 ) | ( ( V_60 [ 5 ] << 0 ) & 0x000000ff ) ;
T_3 V_63 = ( ( V_60 [ 7 ] << 8 ) & 0xff00 ) | ( ( V_60 [ 8 ] << 0 ) & 0x00ff ) ;
T_2 V_64 = V_62 * 0x200 ;
T_2 V_65 = V_63 * 0x200 ;
if ( V_62 > V_3 -> V_47 )
return V_24 ;
V_15 = F_22 ( V_6 , V_66 ) ;
if ( V_15 != V_23 ) {
F_5 ( V_6 , L_8 ) ;
return V_24 ;
}
if ( V_3 -> V_41 . V_52 )
V_64 = V_62 ;
memset ( V_11 , 0 , sizeof( struct V_10 ) ) ;
V_11 -> V_67 = F_23 ( V_68 ) ;
V_11 -> V_20 = V_65 ;
V_11 -> V_69 = 0x00 ;
V_11 -> V_71 [ 0 ] = 0xF0 ;
V_11 -> V_71 [ 5 ] = ( unsigned char ) ( V_64 ) ;
V_11 -> V_71 [ 4 ] = ( unsigned char ) ( V_64 >> 8 ) ;
V_11 -> V_71 [ 3 ] = ( unsigned char ) ( V_64 >> 16 ) ;
V_11 -> V_71 [ 2 ] = ( unsigned char ) ( V_64 >> 24 ) ;
V_15 = F_3 ( V_6 , V_72 , F_24 ( V_28 ) , 1 ) ;
return V_15 ;
}
static int F_26 ( struct V_5 * V_6 , T_3 V_73 , T_3 V_74 )
{
struct V_2 * V_3 = (struct V_2 * ) V_6 -> V_1 ;
if ( ( V_73 >= V_3 -> V_75 . V_76 ) || ( V_74 >= V_3 -> V_75 . V_77 ) )
return ( T_2 ) - 1 ;
V_3 -> V_75 . V_78 [ V_74 ] = V_73 ;
V_3 -> V_75 . V_79 [ V_73 ] = V_74 ;
return 0 ;
}
static int F_27 ( struct V_5 * V_6 , T_3 V_74 , T_3 V_80 )
{
struct V_2 * V_3 = (struct V_2 * ) V_6 -> V_1 ;
if ( V_74 >= V_3 -> V_75 . V_77 )
return ( T_2 ) - 1 ;
V_3 -> V_75 . V_78 [ V_74 ] = V_80 ;
return 0 ;
}
static int F_28 ( struct V_5 * V_6 , T_3 V_74 )
{
return F_27 ( V_6 , V_74 , V_81 ) ;
}
static int F_29 ( struct V_5 * V_6 , T_3 V_74 )
{
return F_27 ( V_6 , V_74 , V_82 ) ;
}
static int F_30 ( struct V_5 * V_6 )
{
struct V_2 * V_3 = (struct V_2 * ) V_6 -> V_1 ;
F_2 ( V_3 -> V_75 . V_78 ) ;
V_3 -> V_75 . V_78 = NULL ;
F_2 ( V_3 -> V_75 . V_79 ) ;
V_3 -> V_75 . V_79 = NULL ;
return 0 ;
}
static int F_31 ( struct V_5 * V_6 )
{
T_2 V_83 ;
struct V_2 * V_3 = (struct V_2 * ) V_6 -> V_1 ;
V_3 -> V_75 . V_78 = F_32 ( V_3 -> V_75 . V_77 * sizeof( T_3 ) , V_84 ) ;
V_3 -> V_75 . V_79 = F_32 ( V_3 -> V_75 . V_76 * sizeof( T_3 ) , V_84 ) ;
if ( ( V_3 -> V_75 . V_78 == NULL ) || ( V_3 -> V_75 . V_79 == NULL ) ) {
F_30 ( V_6 ) ;
return ( T_2 ) - 1 ;
}
for ( V_83 = 0 ; V_83 < V_3 -> V_75 . V_77 ; V_83 ++ )
V_3 -> V_75 . V_78 [ V_83 ] = V_85 ;
for ( V_83 = 0 ; V_83 < V_3 -> V_75 . V_76 ; V_83 ++ )
V_3 -> V_75 . V_79 [ V_83 ] = V_85 ;
return 0 ;
}
static void F_33 ( struct V_5 * V_6 )
{
int V_83 ;
struct V_2 * V_3 = (struct V_2 * ) V_6 -> V_1 ;
V_3 -> V_75 . V_86 = ( T_3 ) - 1 ;
F_34 ( V_3 ) ;
if ( V_3 -> V_75 . V_87 )
memset ( V_3 -> V_75 . V_87 , 0xff , V_3 -> V_75 . V_88 * V_3 -> V_75 . V_89 ) ;
if ( V_3 -> V_75 . V_90 ) {
for ( V_83 = 0 ; V_83 < V_3 -> V_75 . V_88 ; V_83 ++ ) {
V_3 -> V_75 . V_90 [ V_83 ] . V_91 = V_92 ;
V_3 -> V_75 . V_90 [ V_83 ] . V_93 = V_94 ;
V_3 -> V_75 . V_90 [ V_83 ] . V_95 = V_96 ;
V_3 -> V_75 . V_90 [ V_83 ] . V_97 = V_85 ;
}
}
}
static int F_35 ( struct V_5 * V_6 , T_3 V_98 )
{
T_2 V_99 , V_100 ;
struct V_2 * V_3 = (struct V_2 * ) V_6 -> V_1 ;
V_99 = V_98 + V_101 ;
for ( V_100 = 0 ; V_98 < V_99 ; V_98 ++ ) {
switch ( V_3 -> V_75 . V_78 [ V_98 ] ) {
case V_85 :
case V_102 :
V_100 ++ ;
default:
break;
}
}
return V_100 ;
}
static int F_36 ( struct V_5 * V_6 , T_2 V_103 ,
T_1 V_104 , T_2 * V_105 , struct V_106 * V_107 )
{
struct V_10 * V_11 = (struct V_10 * ) V_6 -> V_12 ;
struct V_2 * V_3 = (struct V_2 * ) V_6 -> V_1 ;
T_1 * V_4 = V_3 -> V_4 ;
int V_15 ;
T_2 V_62 = V_103 * 0x20 + V_104 ;
V_15 = F_22 ( V_6 , V_108 ) ;
if ( V_15 != V_23 )
return V_24 ;
memset ( V_11 , 0 , sizeof( struct V_10 ) ) ;
V_11 -> V_67 = F_23 ( V_68 ) ;
V_11 -> V_20 = 0x200 ;
V_11 -> V_69 = V_70 ;
V_11 -> V_71 [ 0 ] = 0xF1 ;
V_11 -> V_71 [ 1 ] = 0x02 ;
V_11 -> V_71 [ 5 ] = ( unsigned char ) ( V_62 ) ;
V_11 -> V_71 [ 4 ] = ( unsigned char ) ( V_62 >> 8 ) ;
V_11 -> V_71 [ 3 ] = ( unsigned char ) ( V_62 >> 16 ) ;
V_11 -> V_71 [ 2 ] = ( unsigned char ) ( V_62 >> 24 ) ;
V_15 = F_3 ( V_6 , V_26 , V_105 , 0 ) ;
if ( V_15 != V_23 )
return V_24 ;
memset ( V_11 , 0 , sizeof( struct V_10 ) ) ;
V_11 -> V_67 = F_23 ( V_68 ) ;
V_11 -> V_20 = 0x4 ;
V_11 -> V_69 = V_70 ;
V_11 -> V_71 [ 0 ] = 0xF1 ;
V_11 -> V_71 [ 1 ] = 0x03 ;
V_11 -> V_71 [ 5 ] = ( unsigned char ) ( V_104 ) ;
V_11 -> V_71 [ 4 ] = ( unsigned char ) ( V_103 ) ;
V_11 -> V_71 [ 3 ] = ( unsigned char ) ( V_103 >> 8 ) ;
V_11 -> V_71 [ 2 ] = ( unsigned char ) ( V_103 >> 16 ) ;
V_11 -> V_71 [ 6 ] = 0x01 ;
V_15 = F_3 ( V_6 , V_26 , V_4 , 0 ) ;
if ( V_15 != V_23 )
return V_24 ;
V_107 -> V_109 = 0 ;
V_107 -> V_110 = 0x80 ;
V_107 -> V_111 = 0x10 ;
V_107 -> V_91 = 0x00 ;
V_107 -> V_93 = V_4 [ 0 ] ;
V_107 -> V_95 = V_4 [ 1 ] ;
V_107 -> V_97 = F_37 ( V_4 [ 2 ] , V_4 [ 3 ] ) ;
return V_37 ;
}
static int F_38 ( struct V_5 * V_6 , T_3 V_98 , T_1 * V_112 )
{
struct V_113 * V_114 ;
struct V_115 * V_116 ;
T_2 V_83 , V_15 ;
T_1 V_117 ;
T_1 * V_118 ;
struct V_106 V_119 ;
struct V_2 * V_3 = (struct V_2 * ) V_6 -> V_1 ;
V_118 = F_32 ( V_120 , V_84 ) ;
if ( V_118 == NULL )
return ( T_2 ) - 1 ;
V_15 = ( T_2 ) - 1 ;
V_116 = & ( ( (struct V_121 * ) V_112 ) -> V_122 ) ;
if ( ( V_116 -> V_123 != V_124 ) ||
( F_39 ( V_116 -> V_125 ) != V_126 ) ||
( ( V_116 -> V_127 & V_128 ) == V_129 ) ||
( V_116 -> V_130 != V_131 ) ||
( V_116 -> V_132 != V_133 ) ||
( V_116 -> V_134 != V_135 ) ||
( V_116 -> V_136 != V_137 ) )
goto exit;
switch ( V_3 -> V_75 . V_138 = V_116 -> V_139 ) {
case V_140 :
F_40 ( V_3 , V_141 ) ;
break;
case V_142 :
F_41 ( V_3 , V_141 ) ;
break;
case V_143 :
default:
goto exit;
}
V_3 -> V_75 . V_144 = F_39 ( V_116 -> V_145 ) ;
V_3 -> V_75 . V_77 = F_39 ( V_116 -> V_146 ) ;
V_3 -> V_75 . V_76 = F_39 ( V_116 -> V_147 ) - 2 ;
V_3 -> V_75 . V_88 = V_3 -> V_75 . V_144 * V_148 / V_120 ;
V_3 -> V_75 . V_149 = V_3 -> V_75 . V_77 / V_101 ;
V_3 -> V_150 = F_39 ( V_116 -> V_151 ) ;
if ( F_31 ( V_6 ) )
goto exit;
F_29 ( V_6 , V_98 ) ;
V_114 = & ( ( (struct V_121 * ) V_112 ) -> V_152 ) ;
for ( V_83 = 0 ; V_83 < V_153 ; V_83 ++ ) {
T_2 V_154 , V_155 ;
V_154 = F_42 ( V_114 -> V_156 [ V_83 ] . V_157 ) ;
if ( V_154 == 0xffffff )
continue;
V_155 = F_42 ( V_114 -> V_156 [ V_83 ] . V_158 ) ;
if ( V_155 == 0 )
continue;
if ( V_154 + V_120 + V_155 > V_3 -> V_75 . V_144 * ( T_2 ) V_148 )
continue;
if ( V_83 == 0 ) {
T_1 V_159 = 0 ;
T_3 V_74 ;
if ( V_114 -> V_156 [ V_83 ] . V_160 != V_161 )
goto exit;
while ( V_155 > 0 ) {
V_117 = ( T_1 ) ( V_154 / V_120 + 1 ) ;
if ( V_117 != V_159 ) {
switch ( F_36 ( V_6 , V_98 , V_117 , ( T_2 * ) V_118 , & V_119 ) ) {
case V_162 :
break;
case V_163 :
case V_164 :
case V_165 :
default:
goto exit;
}
V_159 = V_117 ;
}
V_74 = F_39 ( * ( T_3 * ) ( V_118 + ( V_154 % V_120 ) ) ) ;
if ( V_74 < 0x0fff )
F_28 ( V_6 , V_74 ) ;
V_154 += 2 ;
V_155 -= 2 ;
}
} else if ( V_83 == 1 ) {
struct V_166 * V_167 ;
if ( V_114 -> V_156 [ V_83 ] . V_160 != V_168 )
goto exit;
switch ( F_36 ( V_6 , V_98 , ( T_1 ) ( V_154 / V_120 + 1 ) , ( T_2 * ) V_118 , & V_119 ) ) {
case V_162 :
break;
case V_163 :
case V_164 :
case V_165 :
default:
goto exit;
}
V_167 = & ( (struct V_169 * ) ( V_118 + ( V_154 % V_120 ) ) ) -> V_167 . V_167 ;
if ( F_43 ( V_167 -> V_170 ) != V_171 )
goto exit;
V_3 -> V_75 . V_89 = F_43 ( V_167 -> V_172 ) ;
if ( V_3 -> V_75 . V_89 != V_120 )
goto exit;
}
}
V_15 = 0 ;
exit:
if ( V_15 )
F_30 ( V_6 ) ;
F_2 ( V_118 ) ;
V_15 = 0 ;
return V_15 ;
}
static void F_44 ( struct V_5 * V_6 )
{
struct V_2 * V_3 = (struct V_2 * ) V_6 -> V_1 ;
V_3 -> V_75 . V_86 = ( T_3 ) - 1 ;
F_34 ( V_3 ) ;
if ( V_3 -> V_75 . V_87 ) {
F_2 ( V_3 -> V_75 . V_87 ) ;
V_3 -> V_75 . V_87 = NULL ;
}
if ( V_3 -> V_75 . V_90 ) {
F_2 ( V_3 -> V_75 . V_90 ) ;
V_3 -> V_75 . V_90 = NULL ;
}
}
static void F_45 ( struct V_5 * V_6 )
{
struct V_2 * V_3 = (struct V_2 * ) V_6 -> V_1 ;
F_44 ( V_6 ) ;
F_30 ( V_6 ) ;
V_3 -> V_75 . V_173 = 0 ;
V_3 -> V_75 . V_89 = 0 ;
V_3 -> V_75 . V_174 = 0 ;
V_3 -> V_75 . V_138 = 0 ;
V_3 -> V_75 . V_144 = 0 ;
V_3 -> V_75 . V_88 = 0 ;
V_3 -> V_75 . V_77 = 0 ;
V_3 -> V_75 . V_76 = 0 ;
}
static int F_46 ( struct V_5 * V_6 )
{
struct V_2 * V_3 = (struct V_2 * ) V_6 -> V_1 ;
V_3 -> V_75 . V_86 = ( T_3 ) - 1 ;
V_3 -> V_75 . V_87 = F_32 ( V_3 -> V_75 . V_88 * V_3 -> V_75 . V_89 , V_84 ) ;
V_3 -> V_75 . V_90 = F_32 ( V_3 -> V_75 . V_88 * sizeof( struct V_106 ) , V_84 ) ;
if ( ( V_3 -> V_75 . V_87 == NULL ) || ( V_3 -> V_75 . V_90 == NULL ) ) {
F_44 ( V_6 ) ;
return ( T_2 ) - 1 ;
}
F_33 ( V_6 ) ;
return 0 ;
}
static int F_47 ( struct V_5 * V_6 , T_3 V_73 , T_3 V_74 )
{
struct V_2 * V_3 = (struct V_2 * ) V_6 -> V_1 ;
if ( V_73 == V_85 )
return 0 ;
if ( ( V_73 >= V_3 -> V_75 . V_76 ) ||
( V_74 >= V_3 -> V_75 . V_77 ) )
return ( T_2 ) - 1 ;
V_3 -> V_75 . V_78 [ V_74 ] = V_73 ;
V_3 -> V_75 . V_79 [ V_73 ] = V_74 ;
return 0 ;
}
static int F_48 ( struct V_5 * V_6 , T_3 V_175 , T_3 V_176 ,
T_3 V_103 , T_1 V_104 , unsigned char * V_8 , T_3 V_177 )
{
struct V_10 * V_11 = (struct V_10 * ) V_6 -> V_12 ;
int V_15 ;
V_15 = F_22 ( V_6 , V_108 ) ;
if ( V_15 != V_23 )
return V_24 ;
memset ( V_11 , 0 , sizeof( struct V_10 ) ) ;
V_11 -> V_67 = F_23 ( V_68 ) ;
V_11 -> V_20 = 0x200 * V_177 ;
V_11 -> V_69 = 0x00 ;
V_11 -> V_71 [ 0 ] = 0xF0 ;
V_11 -> V_71 [ 1 ] = 0x08 ;
V_11 -> V_71 [ 4 ] = ( unsigned char ) ( V_175 ) ;
V_11 -> V_71 [ 3 ] = ( unsigned char ) ( V_175 >> 8 ) ;
V_11 -> V_71 [ 2 ] = 0 ;
V_11 -> V_71 [ 7 ] = ( unsigned char ) ( V_176 ) ;
V_11 -> V_71 [ 6 ] = ( unsigned char ) ( V_176 >> 8 ) ;
V_11 -> V_71 [ 5 ] = 0 ;
V_11 -> V_71 [ 9 ] = ( unsigned char ) ( V_103 ) ;
V_11 -> V_71 [ 8 ] = ( unsigned char ) ( V_103 >> 8 ) ;
V_11 -> V_71 [ 10 ] = V_104 ;
V_15 = F_3 ( V_6 , V_72 , V_8 , 0 ) ;
if ( V_15 != V_23 )
return V_24 ;
return V_37 ;
}
static int F_49 ( struct V_5 * V_6 , T_2 V_103 )
{
struct V_10 * V_11 = (struct V_10 * ) V_6 -> V_12 ;
int V_15 ;
T_2 V_62 = V_103 ;
V_15 = F_22 ( V_6 , V_108 ) ;
if ( V_15 != V_23 )
return V_24 ;
memset ( V_11 , 0 , sizeof( struct V_10 ) ) ;
V_11 -> V_67 = F_23 ( V_68 ) ;
V_11 -> V_20 = 0x200 ;
V_11 -> V_69 = V_70 ;
V_11 -> V_71 [ 0 ] = 0xF2 ;
V_11 -> V_71 [ 1 ] = 0x06 ;
V_11 -> V_71 [ 4 ] = ( unsigned char ) ( V_62 ) ;
V_11 -> V_71 [ 3 ] = ( unsigned char ) ( V_62 >> 8 ) ;
V_11 -> V_71 [ 2 ] = ( unsigned char ) ( V_62 >> 16 ) ;
V_15 = F_3 ( V_6 , V_26 , NULL , 0 ) ;
if ( V_15 != V_23 )
return V_24 ;
return V_37 ;
}
static int F_50 ( struct V_5 * V_6 , T_3 V_98 )
{
unsigned char * V_105 = NULL ;
T_3 V_15 = V_162 ;
T_3 V_178 , V_179 = 0 ;
struct V_106 V_180 ;
struct V_2 * V_3 = (struct V_2 * ) V_6 -> V_1 ;
V_105 = F_32 ( V_120 , V_84 ) ;
if ( V_105 == NULL ) {
V_15 = V_181 ;
goto exit;
}
F_36 ( V_6 , V_98 , 1 , ( T_2 * ) V_105 , & V_180 ) ;
do {
V_178 = F_39 ( V_105 [ V_179 ] ) ;
if ( V_178 == V_85 )
break;
if ( V_178 == V_3 -> V_75 . V_79 [ 0 ] ) {
V_15 = V_164 ;
break;
}
V_179 ++ ;
} while ( 1 );
exit:
F_2 ( V_105 ) ;
return V_15 ;
}
static int F_51 ( struct V_5 * V_6 , T_3 V_74 )
{
T_3 log ;
struct V_2 * V_3 = (struct V_2 * ) V_6 -> V_1 ;
if ( V_74 >= V_3 -> V_75 . V_77 )
return ( T_2 ) - 1 ;
log = V_3 -> V_75 . V_78 [ V_74 ] ;
if ( log < V_3 -> V_75 . V_76 )
V_3 -> V_75 . V_79 [ log ] = V_85 ;
if ( V_3 -> V_75 . V_78 [ V_74 ] != V_81 )
V_3 -> V_75 . V_78 [ V_74 ] = V_182 ;
return 0 ;
}
static int F_52 ( struct V_5 * V_6 , T_2 V_103 ,
T_1 V_104 , T_1 V_183 )
{
struct V_10 * V_11 = (struct V_10 * ) V_6 -> V_12 ;
int V_15 ;
V_15 = F_22 ( V_6 , V_108 ) ;
if ( V_15 != V_23 )
return V_24 ;
memset ( V_11 , 0 , sizeof( struct V_10 ) ) ;
V_11 -> V_67 = F_23 ( V_68 ) ;
V_11 -> V_20 = 0x4 ;
V_11 -> V_69 = V_70 ;
V_11 -> V_71 [ 0 ] = 0xF2 ;
V_11 -> V_71 [ 1 ] = 0x05 ;
V_11 -> V_71 [ 5 ] = ( unsigned char ) ( V_104 ) ;
V_11 -> V_71 [ 4 ] = ( unsigned char ) ( V_103 ) ;
V_11 -> V_71 [ 3 ] = ( unsigned char ) ( V_103 >> 8 ) ;
V_11 -> V_71 [ 2 ] = ( unsigned char ) ( V_103 >> 16 ) ;
V_11 -> V_71 [ 6 ] = V_183 ;
V_11 -> V_71 [ 7 ] = 0xFF ;
V_11 -> V_71 [ 8 ] = 0xFF ;
V_11 -> V_71 [ 9 ] = 0xFF ;
V_15 = F_3 ( V_6 , V_26 , NULL , 0 ) ;
if ( V_15 != V_23 )
return V_24 ;
return V_37 ;
}
static int F_53 ( struct V_5 * V_6 , T_3 V_74 )
{
struct V_2 * V_3 = (struct V_2 * ) V_6 -> V_1 ;
if ( V_74 >= V_3 -> V_75 . V_77 )
return V_165 ;
F_51 ( V_6 , V_74 ) ;
if ( F_54 ( V_3 ) )
return F_52 ( V_6 , V_74 , 0 , ( T_1 ) ( ~ V_184 & V_185 ) ) ;
return V_162 ;
}
static int F_55 ( struct V_5 * V_6 , T_3 V_74 )
{
T_3 log ;
struct V_2 * V_3 = (struct V_2 * ) V_6 -> V_1 ;
if ( V_74 >= V_3 -> V_75 . V_77 )
return V_165 ;
log = V_3 -> V_75 . V_78 [ V_74 ] ;
if ( log < V_3 -> V_75 . V_76 )
V_3 -> V_75 . V_79 [ log ] = V_85 ;
V_3 -> V_75 . V_78 [ V_74 ] = V_85 ;
if ( F_54 ( V_3 ) ) {
switch ( F_49 ( V_6 , V_74 ) ) {
case V_162 :
V_3 -> V_75 . V_78 [ V_74 ] = V_102 ;
return V_162 ;
case V_186 :
case V_187 :
F_53 ( V_6 , V_74 ) ;
return V_186 ;
case V_165 :
default:
F_40 ( V_3 , V_141 ) ;
F_51 ( V_6 , V_74 ) ;
return V_165 ;
}
}
F_51 ( V_6 , V_74 ) ;
return V_162 ;
}
static int F_56 ( struct V_5 * V_6 , T_2 V_98 ,
T_1 V_104 , struct V_106 * V_107 )
{
struct V_10 * V_11 = (struct V_10 * ) V_6 -> V_12 ;
struct V_2 * V_3 = (struct V_2 * ) V_6 -> V_1 ;
T_1 * V_4 = V_3 -> V_4 ;
int V_15 ;
memset ( V_11 , 0 , sizeof( struct V_10 ) ) ;
V_11 -> V_67 = F_23 ( V_68 ) ;
V_11 -> V_20 = 0x4 ;
V_11 -> V_69 = V_70 ;
V_11 -> V_71 [ 0 ] = 0xF1 ;
V_11 -> V_71 [ 1 ] = 0x03 ;
V_11 -> V_71 [ 5 ] = ( unsigned char ) ( V_104 ) ;
V_11 -> V_71 [ 4 ] = ( unsigned char ) ( V_98 ) ;
V_11 -> V_71 [ 3 ] = ( unsigned char ) ( V_98 >> 8 ) ;
V_11 -> V_71 [ 2 ] = ( unsigned char ) ( V_98 >> 16 ) ;
V_11 -> V_71 [ 6 ] = 0x01 ;
V_15 = F_3 ( V_6 , V_26 , V_4 , 0 ) ;
if ( V_15 != V_23 )
return V_24 ;
V_107 -> V_109 = 0 ;
V_107 -> V_110 = 0x80 ;
V_107 -> V_111 = 0x10 ;
V_107 -> V_91 = 0x00 ;
V_107 -> V_93 = V_4 [ 0 ] ;
V_107 -> V_95 = V_4 [ 1 ] ;
V_107 -> V_97 = F_37 ( V_4 [ 2 ] , V_4 [ 3 ] ) ;
return V_37 ;
}
static int F_57 ( struct V_5 * V_6 , T_3 V_74 )
{
T_3 V_178 ;
struct V_106 V_180 ;
struct V_2 * V_3 = (struct V_2 * ) V_6 -> V_1 ;
if ( V_74 >= V_3 -> V_75 . V_77 )
return V_188 ;
for ( V_178 = V_74 + 1 ; V_178 != V_74 ; V_178 ++ ) {
if ( ( V_178 & V_189 ) == 0 )
V_178 -= V_101 ;
if ( V_3 -> V_75 . V_78 [ V_178 ] == V_102 ) {
return V_178 ;
} else if ( V_3 -> V_75 . V_78 [ V_178 ] == V_85 ) {
switch ( F_56 ( V_6 , V_178 , 0 , & V_180 ) ) {
case V_162 :
case V_190 :
break;
case V_191 :
return V_191 ;
case V_187 :
return V_188 ;
case V_164 :
default:
F_51 ( V_6 , V_178 ) ;
continue;
}
if ( ( V_180 . V_93 & V_184 ) != V_192 ) {
F_51 ( V_6 , V_178 ) ;
continue;
}
switch ( F_55 ( V_6 , V_178 ) ) {
case V_162 :
return V_178 ;
case V_165 :
return V_188 ;
case V_186 :
default:
F_53 ( V_6 , V_178 ) ;
break;
}
}
}
return V_188 ;
}
static int F_58 ( struct V_5 * V_6 , T_3 V_73 )
{
T_3 V_74 ;
struct V_2 * V_3 = (struct V_2 * ) V_6 -> V_1 ;
V_74 = F_59 ( V_3 , V_73 ) ;
if ( V_74 >= V_188 ) {
if ( V_73 >= V_3 -> V_75 . V_76 )
return V_188 ;
V_74 = ( V_73 + V_193 ) / V_194 ;
V_74 *= V_101 ;
V_74 += V_101 - 1 ;
}
return F_57 ( V_6 , V_74 ) ;
}
static int F_60 ( struct V_5 * V_6 , struct V_38 * V_28 )
{
struct V_2 * V_3 = (struct V_2 * ) ( V_6 -> V_1 ) ;
if ( V_3 -> V_195 . V_42 && V_3 -> V_195 . V_43 ) {
return V_37 ;
} else {
F_61 ( V_6 ) ;
return V_37 ;
}
return V_37 ;
}
static int F_62 ( struct V_5 * V_6 , struct V_38 * V_28 )
{
struct V_2 * V_3 = (struct V_2 * ) V_6 -> V_1 ;
unsigned char V_44 [ 12 ] = {
0x0b , 0x00 , 0x00 , 0x08 , 0x00 , 0x00 ,
0x71 , 0xc0 , 0x00 , 0x00 , 0x02 , 0x00 } ;
unsigned char V_45 [ 12 ] = {
0x0b , 0x00 , 0x80 , 0x08 , 0x00 , 0x00 ,
0x71 , 0xc0 , 0x00 , 0x00 , 0x02 , 0x00 } ;
if ( V_3 -> V_195 . V_46 )
F_14 ( V_45 , 12 , V_28 ) ;
else
F_14 ( V_44 , 12 , V_28 ) ;
return V_37 ;
}
static int F_63 ( struct V_5 * V_6 , struct V_38 * V_28 )
{
T_2 V_47 ;
T_3 V_48 ;
unsigned int V_49 = 0 ;
unsigned char V_8 [ 8 ] ;
struct V_50 * V_51 = NULL ;
struct V_2 * V_3 = (struct V_2 * ) V_6 -> V_1 ;
F_5 ( V_6 , L_9 ) ;
V_48 = 0x200 ;
if ( V_3 -> V_195 . V_196 )
V_47 = V_3 -> V_197 - 1 ;
else
V_47 = V_3 -> V_75 . V_76 * V_3 -> V_75 . V_144 * 2 - 1 ;
V_3 -> V_47 = V_47 ;
F_5 ( V_6 , L_6 , V_48 ) ;
F_5 ( V_6 , L_7 , V_47 ) ;
V_8 [ 0 ] = ( V_47 >> 24 ) & 0xff ;
V_8 [ 1 ] = ( V_47 >> 16 ) & 0xff ;
V_8 [ 2 ] = ( V_47 >> 8 ) & 0xff ;
V_8 [ 3 ] = ( V_47 >> 0 ) & 0xff ;
V_8 [ 4 ] = ( V_48 >> 24 ) & 0xff ;
V_8 [ 5 ] = ( V_48 >> 16 ) & 0xff ;
V_8 [ 6 ] = ( V_48 >> 8 ) & 0xff ;
V_8 [ 7 ] = ( V_48 >> 0 ) & 0xff ;
F_20 ( V_8 , 8 , V_28 , & V_51 , & V_49 , V_59 ) ;
return V_37 ;
}
static void F_64 ( T_3 V_98 , T_3 * V_198 , T_3 * V_199 )
{
V_98 /= V_101 ;
if ( V_98 ) {
* V_198 = V_200 + ( V_98 - 1 ) * V_194 ;
* V_199 = * V_198 + V_194 ;
} else {
* V_198 = 0 ;
* V_199 = V_200 ;
}
}
static int F_65 ( struct V_5 * V_6 , T_2 V_98 ,
T_1 V_104 , T_1 V_63 , void * V_8 )
{
struct V_10 * V_11 = (struct V_10 * ) V_6 -> V_12 ;
int V_15 ;
memset ( V_11 , 0 , sizeof( struct V_10 ) ) ;
V_11 -> V_67 = F_23 ( V_68 ) ;
V_11 -> V_20 = 0x4 * V_63 ;
V_11 -> V_69 = V_70 ;
V_11 -> V_71 [ 0 ] = 0xF1 ;
V_11 -> V_71 [ 1 ] = 0x03 ;
V_11 -> V_71 [ 5 ] = ( unsigned char ) ( V_104 ) ;
V_11 -> V_71 [ 4 ] = ( unsigned char ) ( V_98 ) ;
V_11 -> V_71 [ 3 ] = ( unsigned char ) ( V_98 >> 8 ) ;
V_11 -> V_71 [ 2 ] = ( unsigned char ) ( V_98 >> 16 ) ;
V_11 -> V_71 [ 6 ] = V_63 ;
V_15 = F_3 ( V_6 , V_26 , V_8 , 0 ) ;
if ( V_15 != V_23 )
return V_24 ;
return V_37 ;
}
static int F_66 ( struct V_5 * V_6 , T_3 V_201 )
{
T_3 V_98 , V_202 , V_83 ;
T_3 V_198 , V_199 ;
struct V_106 V_180 ;
T_2 V_203 = 0 , V_179 = 0 ;
struct V_2 * V_3 = (struct V_2 * ) V_6 -> V_1 ;
T_1 * V_4 = V_3 -> V_4 ;
for ( V_98 = 0 ; V_98 < V_3 -> V_75 . V_77 ; ) {
F_64 ( V_98 , & V_198 , & V_199 ) ;
for ( V_83 = 0 ; V_83 < V_101 ; V_83 ++ , V_98 ++ ) {
switch ( F_67 ( V_3 , V_98 ) ) {
case V_165 :
continue;
default:
break;
}
if ( V_203 == V_98 ) {
F_65 ( V_6 , V_98 , 0 , 0x80 ,
V_4 ) ;
V_203 += 0x80 ;
}
V_179 = ( V_98 % 0x80 ) * 4 ;
V_180 . V_93 = V_4 [ V_179 ] ;
V_180 . V_95 = V_4 [ V_179 + 1 ] ;
V_180 . V_97 = F_37 ( V_4 [ V_179 + 2 ] ,
V_4 [ V_179 + 3 ] ) ;
if ( ( V_180 . V_93 & V_184 ) != V_192 ) {
F_51 ( V_6 , V_98 ) ;
continue;
}
if ( ( V_180 . V_95 & V_204 ) == V_205 ) {
F_55 ( V_6 , V_98 ) ;
continue;
}
if ( V_180 . V_97 != V_85 ) {
if ( ( V_180 . V_97 < V_198 ) || ( V_199 <= V_180 . V_97 ) ) {
F_55 ( V_6 , V_98 ) ;
continue;
}
V_202 = F_59 ( V_3 , V_180 . V_97 ) ;
if ( V_202 != V_85 ) {
if ( V_180 . V_97 == 0 ) {
F_26 ( V_6 , V_180 . V_97 , V_98 ) ;
if ( F_50 ( V_6 , V_201 ) ) {
F_26 ( V_6 , V_180 . V_97 , V_202 ) ;
continue;
}
}
F_56 ( V_6 , V_202 , 0 , & V_180 ) ;
if ( ( V_180 . V_93 & V_206 ) == V_207 ) {
F_55 ( V_6 , V_98 ) ;
continue;
} else {
F_55 ( V_6 , V_202 ) ;
}
}
F_26 ( V_6 , V_180 . V_97 , V_98 ) ;
}
}
}
return V_162 ;
}
static int F_68 ( struct V_5 * V_6 , struct V_38 * V_28 )
{
int V_15 ;
unsigned char * V_60 = V_28 -> V_61 ;
struct V_10 * V_11 = (struct V_10 * ) V_6 -> V_12 ;
struct V_2 * V_3 = (struct V_2 * ) V_6 -> V_1 ;
T_2 V_62 = ( ( V_60 [ 2 ] << 24 ) & 0xff000000 ) | ( ( V_60 [ 3 ] << 16 ) & 0x00ff0000 ) |
( ( V_60 [ 4 ] << 8 ) & 0x0000ff00 ) | ( ( V_60 [ 5 ] << 0 ) & 0x000000ff ) ;
T_3 V_63 = ( ( V_60 [ 7 ] << 8 ) & 0xff00 ) | ( ( V_60 [ 8 ] << 0 ) & 0x00ff ) ;
T_2 V_65 = V_63 * 0x200 ;
if ( V_62 > V_3 -> V_47 )
return V_24 ;
if ( V_3 -> V_195 . V_196 ) {
V_15 = F_22 ( V_6 , V_208 ) ;
if ( V_15 != V_23 ) {
F_5 ( V_6 , L_10 ) ;
return V_24 ;
}
memset ( V_11 , 0 , sizeof( struct V_10 ) ) ;
V_11 -> V_67 = F_23 ( V_68 ) ;
V_11 -> V_20 = V_65 ;
V_11 -> V_69 = V_70 ;
V_11 -> V_71 [ 0 ] = 0xF1 ;
V_11 -> V_71 [ 1 ] = 0x02 ;
V_11 -> V_71 [ 5 ] = ( unsigned char ) ( V_62 ) ;
V_11 -> V_71 [ 4 ] = ( unsigned char ) ( V_62 >> 8 ) ;
V_11 -> V_71 [ 3 ] = ( unsigned char ) ( V_62 >> 16 ) ;
V_11 -> V_71 [ 2 ] = ( unsigned char ) ( V_62 >> 24 ) ;
V_15 = F_3 ( V_6 , V_26 , F_24 ( V_28 ) , 1 ) ;
} else {
void * V_8 ;
int V_49 = 0 ;
T_3 V_74 , V_73 ;
T_1 V_104 ;
T_3 V_177 ;
T_2 V_209 ;
V_8 = F_32 ( V_65 , V_84 ) ;
if ( V_8 == NULL )
return V_24 ;
V_15 = F_22 ( V_6 , V_108 ) ;
if ( V_15 != V_23 ) {
F_69 ( L_11 ) ;
V_15 = V_24 ;
goto exit;
}
V_73 = ( T_3 ) ( V_62 / V_3 -> V_75 . V_88 ) ;
V_104 = ( T_1 ) ( V_62 % V_3 -> V_75 . V_88 ) ;
while ( 1 ) {
if ( V_63 > ( V_3 -> V_75 . V_88 - V_104 ) )
V_177 = V_3 -> V_75 . V_88 - V_104 ;
else
V_177 = V_63 ;
V_74 = F_59 ( V_3 , V_73 ) ;
V_209 = V_74 * 0x20 + V_104 ;
memset ( V_11 , 0 , sizeof( struct V_10 ) ) ;
V_11 -> V_67 = F_23 ( V_68 ) ;
V_11 -> V_20 = 0x200 * V_177 ;
V_11 -> V_69 = V_70 ;
V_11 -> V_71 [ 0 ] = 0xF1 ;
V_11 -> V_71 [ 1 ] = 0x02 ;
V_11 -> V_71 [ 5 ] = ( unsigned char ) ( V_209 ) ;
V_11 -> V_71 [ 4 ] = ( unsigned char ) ( V_209 >> 8 ) ;
V_11 -> V_71 [ 3 ] = ( unsigned char ) ( V_209 >> 16 ) ;
V_11 -> V_71 [ 2 ] = ( unsigned char ) ( V_209 >> 24 ) ;
V_15 = F_3 ( V_6 , V_26 , V_8 + V_49 , 0 ) ;
if ( V_15 != V_23 ) {
F_69 ( L_12 , V_15 ) ;
V_15 = V_24 ;
goto exit;
}
V_63 -= V_177 ;
if ( V_63 <= 0 )
break;
V_73 ++ ;
V_104 = 0 ;
V_49 += V_120 * V_177 ;
}
F_14 ( V_8 , V_65 , V_28 ) ;
exit:
F_2 ( V_8 ) ;
}
return V_15 ;
}
static int F_70 ( struct V_5 * V_6 , struct V_38 * V_28 )
{
int V_15 ;
struct V_10 * V_11 = (struct V_10 * ) V_6 -> V_12 ;
unsigned char * V_60 = V_28 -> V_61 ;
struct V_2 * V_3 = (struct V_2 * ) V_6 -> V_1 ;
T_2 V_62 = ( ( V_60 [ 2 ] << 24 ) & 0xff000000 ) |
( ( V_60 [ 3 ] << 16 ) & 0x00ff0000 ) |
( ( V_60 [ 4 ] << 8 ) & 0x0000ff00 ) |
( ( V_60 [ 5 ] << 0 ) & 0x000000ff ) ;
T_3 V_63 = ( ( V_60 [ 7 ] << 8 ) & 0xff00 ) | ( ( V_60 [ 8 ] << 0 ) & 0x00ff ) ;
T_2 V_65 = V_63 * 0x200 ;
if ( V_62 > V_3 -> V_47 )
return V_24 ;
if ( V_3 -> V_195 . V_196 ) {
V_15 = F_22 ( V_6 , V_208 ) ;
if ( V_15 != V_23 ) {
F_69 ( L_13 ) ;
return V_24 ;
}
memset ( V_11 , 0 , sizeof( struct V_10 ) ) ;
V_11 -> V_67 = F_23 ( V_68 ) ;
V_11 -> V_20 = V_65 ;
V_11 -> V_69 = 0x00 ;
V_11 -> V_71 [ 0 ] = 0xF0 ;
V_11 -> V_71 [ 1 ] = 0x04 ;
V_11 -> V_71 [ 5 ] = ( unsigned char ) ( V_62 ) ;
V_11 -> V_71 [ 4 ] = ( unsigned char ) ( V_62 >> 8 ) ;
V_11 -> V_71 [ 3 ] = ( unsigned char ) ( V_62 >> 16 ) ;
V_11 -> V_71 [ 2 ] = ( unsigned char ) ( V_62 >> 24 ) ;
V_15 = F_3 ( V_6 , V_72 , F_24 ( V_28 ) , 1 ) ;
} else {
void * V_8 ;
int V_49 = 0 ;
T_3 V_103 ;
T_1 V_104 ;
T_3 V_177 , V_175 , V_176 ;
V_8 = F_32 ( V_65 , V_84 ) ;
if ( V_8 == NULL )
return V_24 ;
F_14 ( V_8 , V_65 , V_28 ) ;
V_15 = F_22 ( V_6 , V_108 ) ;
if ( V_15 != V_23 ) {
F_69 ( L_11 ) ;
V_15 = V_24 ;
goto exit;
}
V_103 = ( T_3 ) ( V_62 / V_3 -> V_75 . V_88 ) ;
V_104 = ( T_1 ) ( V_62 % V_3 -> V_75 . V_88 ) ;
while ( 1 ) {
if ( V_63 > ( V_3 -> V_75 . V_88 - V_104 ) )
V_177 = V_3 -> V_75 . V_88 - V_104 ;
else
V_177 = V_63 ;
V_175 = F_59 ( V_3 , V_103 ) ;
V_176 = F_58 ( V_6 , V_103 ) ;
V_15 = F_48 ( V_6 , V_175 , V_176 , V_103 , V_104 , V_8 + V_49 , V_177 ) ;
if ( V_15 != V_23 ) {
F_69 ( L_14 , V_15 ) ;
V_15 = V_24 ;
goto exit;
}
V_3 -> V_75 . V_78 [ V_175 ] = V_102 ;
F_47 ( V_6 , V_103 , V_176 ) ;
V_63 -= V_177 ;
if ( V_63 <= 0 )
break;
V_103 ++ ;
V_104 = 0 ;
V_49 += V_120 * V_177 ;
}
exit:
F_2 ( V_8 ) ;
}
return V_15 ;
}
static int F_71 ( struct V_5 * V_6 , T_3 V_179 , void * V_8 )
{
struct V_10 * V_11 = (struct V_10 * ) V_6 -> V_12 ;
int V_15 ;
memset ( V_11 , 0 , sizeof( struct V_10 ) ) ;
V_11 -> V_67 = F_23 ( V_68 ) ;
V_11 -> V_20 = 0x01 ;
V_11 -> V_69 = V_70 ;
V_11 -> V_71 [ 0 ] = 0xED ;
V_11 -> V_71 [ 2 ] = ( unsigned char ) ( V_179 >> 8 ) ;
V_11 -> V_71 [ 3 ] = ( unsigned char ) V_179 ;
V_15 = F_3 ( V_6 , V_26 , V_8 , 0 ) ;
return V_15 ;
}
static int F_72 ( struct V_5 * V_6 , T_1 * V_8 )
{
T_3 V_210 ;
T_2 V_211 ;
struct V_2 * V_3 = (struct V_2 * ) V_6 -> V_1 ;
V_211 = * ( T_2 * ) & V_8 [ 0x18 ] ;
V_3 -> V_55 = ( T_1 ) ( ( V_211 >> 8 ) & 0x0f ) ;
V_210 = ( T_3 ) V_211 ;
V_211 = * ( T_2 * ) ( & V_8 [ 0x14 ] ) ;
if ( V_3 -> V_41 . V_52 && ! V_3 -> V_41 . V_53 )
V_3 -> V_54 = ( V_211 >> 8 ) & 0x3fffff ;
V_3 -> V_57 = ( ( V_210 & 0x03 ) << 10 ) | ( T_3 ) ( V_211 >> 22 ) ;
V_3 -> V_58 = ( T_1 ) ( V_211 >> 7 ) & 0x07 ;
if ( V_3 -> V_41 . V_52 && V_3 -> V_41 . V_53 )
V_3 -> V_54 = * ( T_2 * ) ( & V_8 [ 0x100 ] ) ;
if ( V_3 -> V_55 > V_212 ) {
V_3 -> V_56 = 1 << ( V_3 -> V_55 - V_212 ) ;
V_3 -> V_55 = V_212 ;
} else {
V_3 -> V_56 = 1 ;
}
return V_37 ;
}
static int F_22 ( struct V_5 * V_6 , unsigned char V_213 )
{
int V_214 ;
char * V_215 = NULL ;
unsigned char * V_8 = NULL ;
const struct V_216 * V_217 = NULL ;
int V_15 = V_24 ;
struct V_10 * V_11 = (struct V_10 * ) V_6 -> V_12 ;
struct V_2 * V_3 = (struct V_2 * ) V_6 -> V_1 ;
if ( V_3 -> V_218 == V_213 )
return V_37 ;
switch ( V_213 ) {
case V_219 :
F_5 ( V_6 , L_15 ) ;
V_215 = V_220 ;
break;
case V_221 :
F_5 ( V_6 , L_16 ) ;
V_215 = V_222 ;
break;
case V_66 :
F_5 ( V_6 , L_17 ) ;
V_215 = V_223 ;
break;
case V_224 :
F_5 ( V_6 , L_18 ) ;
V_215 = V_225 ;
break;
case V_208 :
F_5 ( V_6 , L_19 ) ;
V_215 = V_226 ;
break;
case V_108 :
F_5 ( V_6 , L_20 ) ;
V_215 = V_227 ;
break;
default:
F_5 ( V_6 , L_21 ) ;
goto V_228;
}
V_214 = F_73 ( & V_217 , V_215 , & V_6 -> V_229 -> V_230 ) ;
if ( V_214 ) {
F_5 ( V_6 , L_22 , V_215 ) ;
goto V_228;
}
V_8 = F_74 ( V_217 -> V_231 , V_217 -> V_232 , V_84 ) ;
if ( V_8 == NULL )
goto V_228;
memset ( V_11 , 0 , sizeof( struct V_10 ) ) ;
V_11 -> V_67 = F_23 ( V_68 ) ;
V_11 -> V_20 = V_217 -> V_232 ;
V_11 -> V_69 = 0x00 ;
V_11 -> V_71 [ 0 ] = 0xEF ;
V_15 = F_3 ( V_6 , V_72 , V_8 , 0 ) ;
if ( V_6 -> V_28 != NULL )
F_10 ( V_6 -> V_28 , 0 ) ;
V_3 -> V_218 = V_213 ;
F_2 ( V_8 ) ;
V_228:
F_75 ( V_217 ) ;
return V_15 ;
}
static int F_76 ( struct V_5 * V_6 )
{
T_2 V_15 ;
T_3 V_233 ;
unsigned char * V_234 = NULL , * V_235 = NULL ;
struct V_106 V_180 ;
T_3 V_201 , V_236 ;
T_2 V_237 ;
struct V_2 * V_3 = (struct V_2 * ) V_6 -> V_1 ;
F_77 ( V_238 L_23 ) ;
F_45 ( V_6 ) ;
V_234 = F_32 ( V_120 , V_84 ) ;
V_235 = F_32 ( V_120 , V_84 ) ;
if ( ( V_234 == NULL ) || ( V_235 == NULL ) ) {
V_15 = V_181 ;
goto exit;
}
V_201 = V_236 = V_85 ;
V_237 = 0 ;
for ( V_233 = 0 ; V_233 < V_239 + 2 ; V_233 ++ ) {
switch ( F_36 ( V_6 , V_233 , 0 , ( T_2 * ) V_234 , & V_180 ) ) {
case V_162 :
break;
case V_187 :
break;
case V_165 :
default:
continue;
}
if ( ( V_180 . V_93 & V_184 ) == V_240 )
continue;
if ( ( ( V_180 . V_95 & V_241 ) == V_242 ) ||
( F_39 ( ( (struct V_121 * ) V_234 ) -> V_243 . V_244 ) != V_245 ) ||
( F_39 ( ( (struct V_121 * ) V_234 ) -> V_243 . V_246 ) != V_247 ) ||
( ( (struct V_121 * ) V_234 ) -> V_243 . V_248 != V_249 ) )
continue;
if ( V_201 != V_85 ) {
V_236 = V_233 ;
break;
}
V_201 = V_233 ;
memcpy ( V_235 , V_234 , V_120 ) ;
if ( V_180 . V_91 & ( V_250 | V_251 | V_252 ) )
V_237 = 1 ;
}
if ( V_201 == V_85 ) {
V_15 = V_165 ;
goto exit;
}
if ( ( V_180 . V_111 & V_253 ) == V_254 )
F_40 ( V_3 , V_255 ) ;
V_15 = V_165 ;
if ( V_237 == 0 )
V_15 = F_38 ( V_6 , V_201 , V_235 ) ;
if ( V_15 && ( V_236 != V_85 ) )
V_15 = F_38 ( V_6 , V_236 , V_234 ) ;
if ( V_15 ) {
V_15 = V_165 ;
goto exit;
}
for ( V_233 = 0 ; V_233 < V_201 ; V_233 ++ )
V_3 -> V_75 . V_78 [ V_233 ] = V_81 ;
V_3 -> V_75 . V_78 [ V_201 ] = V_82 ;
if ( V_236 != V_85 ) {
for ( V_233 = V_201 + 1 ; V_233 < V_236 ; V_233 ++ )
V_3 -> V_75 . V_78 [ V_233 ] = V_81 ;
V_3 -> V_75 . V_78 [ V_236 ] = V_82 ;
}
V_15 = F_66 ( V_6 , V_201 ) ;
if ( V_15 )
goto exit;
for ( V_233 = V_101 ;
V_233 < V_3 -> V_75 . V_77 ;
V_233 += V_101 ) {
if ( F_35 ( V_6 , V_233 ) == 0 ) {
F_40 ( V_3 , V_255 ) ;
break;
}
}
if ( F_46 ( V_6 ) ) {
V_15 = V_181 ;
goto exit;
}
V_15 = V_162 ;
exit:
F_2 ( V_235 ) ;
F_2 ( V_234 ) ;
F_77 ( V_238 L_24 ) ;
return V_15 ;
}
static int F_61 ( struct V_5 * V_6 )
{
struct V_10 * V_11 = (struct V_10 * ) V_6 -> V_12 ;
int V_15 ;
T_3 V_256 , V_257 ;
struct V_2 * V_3 = (struct V_2 * ) V_6 -> V_1 ;
T_1 * V_4 = V_3 -> V_4 ;
F_77 ( V_238 L_25 ) ;
V_15 = F_22 ( V_6 , V_224 ) ;
if ( V_15 != V_23 ) {
F_77 ( V_258 L_26 ) ;
return V_24 ;
}
memset ( V_11 , 0 , sizeof( struct V_10 ) ) ;
V_11 -> V_67 = F_23 ( V_68 ) ;
V_11 -> V_20 = 0x200 ;
V_11 -> V_69 = V_70 ;
V_11 -> V_71 [ 0 ] = 0xF1 ;
V_11 -> V_71 [ 1 ] = 0x01 ;
V_15 = F_3 ( V_6 , V_26 , V_4 , 0 ) ;
if ( V_15 != V_23 ) {
F_77 ( V_258 L_27 ) ;
return V_24 ;
}
V_3 -> V_195 = * (struct V_259 * ) V_4 ;
if ( V_3 -> V_195 . V_42 && V_3 -> V_195 . V_43 ) {
F_77 ( V_238 L_28 , V_3 -> V_195 . V_42 ) ;
F_77 ( V_238 L_29 , V_3 -> V_195 . V_43 ) ;
F_77 ( V_238 L_30 , V_3 -> V_195 . V_196 ) ;
F_77 ( V_238 L_31 , V_3 -> V_195 . V_260 ) ;
F_77 ( V_238 L_32 , V_3 -> V_195 . V_46 ) ;
if ( V_3 -> V_195 . V_196 ) {
V_256 = ( V_4 [ 6 ] << 8 ) | V_4 [ 7 ] ;
V_257 = ( V_4 [ 10 ] << 8 ) | V_4 [ 11 ] ;
V_3 -> V_197 = V_256 * V_257 ;
} else {
F_76 ( V_6 ) ;
}
F_5 ( V_6 , L_33 ) ;
} else {
F_5 ( V_6 , L_34 , V_4 [ 0 ] ) ;
return V_24 ;
}
return V_37 ;
}
static int F_17 ( struct V_5 * V_6 )
{
int V_15 ;
struct V_10 * V_11 = (struct V_10 * ) V_6 -> V_12 ;
struct V_2 * V_3 = (struct V_2 * ) V_6 -> V_1 ;
T_1 * V_4 = V_3 -> V_4 ;
F_5 ( V_6 , L_35 ) ;
V_15 = F_22 ( V_6 , V_219 ) ;
if ( V_15 != V_23 ) {
F_5 ( V_6 , L_36 ) ;
return V_24 ;
}
memset ( V_11 , 0 , sizeof( struct V_10 ) ) ;
V_11 -> V_67 = F_23 ( V_68 ) ;
V_11 -> V_69 = V_70 ;
V_11 -> V_71 [ 0 ] = 0xF2 ;
V_15 = F_3 ( V_6 , V_26 , NULL , 0 ) ;
if ( V_15 != V_23 ) {
F_5 ( V_6 , L_37 ) ;
return V_24 ;
}
V_15 = F_22 ( V_6 , V_221 ) ;
if ( V_15 != V_23 ) {
F_5 ( V_6 , L_38 ) ;
return V_24 ;
}
memset ( V_11 , 0 , sizeof( struct V_10 ) ) ;
V_11 -> V_67 = F_23 ( V_68 ) ;
V_11 -> V_20 = 0x200 ;
V_11 -> V_69 = V_70 ;
V_11 -> V_71 [ 0 ] = 0xF1 ;
V_15 = F_3 ( V_6 , V_26 , V_4 , 0 ) ;
if ( V_15 != V_23 ) {
F_5 ( V_6 , L_37 ) ;
return V_24 ;
}
V_3 -> V_41 = * (struct V_261 * ) V_4 ;
if ( V_3 -> V_41 . V_42 && V_3 -> V_41 . V_43 ) {
struct V_261 * V_262 = & V_3 -> V_41 ;
F_72 ( V_6 , V_4 ) ;
F_5 ( V_6 , L_28 , V_262 -> V_42 ) ;
F_5 ( V_6 , L_29 , V_262 -> V_43 ) ;
F_5 ( V_6 , L_39 , V_262 -> V_53 ) ;
F_5 ( V_6 , L_40 , V_262 -> V_52 ) ;
F_5 ( V_6 , L_41 , V_262 -> V_263 ) ;
F_5 ( V_6 , L_42 , V_262 -> V_46 ) ;
} else {
F_5 ( V_6 , L_43 , V_4 [ 0 ] ) ;
return V_24 ;
}
return V_37 ;
}
static int F_78 ( struct V_5 * V_6 )
{
int V_15 ;
T_1 V_264 ;
struct V_2 * V_3 = (struct V_2 * ) ( V_6 -> V_1 ) ;
T_1 * V_4 = V_3 -> V_4 ;
V_15 = F_71 ( V_6 , V_265 , V_4 ) ;
if ( V_15 != V_23 )
return V_24 ;
V_264 = V_4 [ 0 ] ;
if ( V_264 & 0x01 ) {
if ( ! V_3 -> V_41 . V_43 ) {
V_15 = F_17 ( V_6 ) ;
if ( V_15 != V_23 )
return V_24 ;
}
}
if ( V_264 & 0x02 ) {
if ( ! V_3 -> V_195 . V_43 ) {
V_15 = F_61 ( V_6 ) ;
if ( V_15 != V_23 )
return V_24 ;
}
}
return V_15 ;
}
static int F_79 ( struct V_5 * V_6 , struct V_38 * V_28 )
{
int V_15 ;
struct V_2 * V_3 = (struct V_2 * ) V_6 -> V_1 ;
switch ( V_28 -> V_61 [ 0 ] ) {
case V_266 :
V_15 = F_16 ( V_6 , V_28 ) ;
break;
case V_267 :
V_15 = F_13 ( V_6 , V_28 ) ;
break;
case V_268 :
V_15 = F_15 ( V_6 , V_28 ) ;
break;
case V_269 :
V_15 = F_18 ( V_6 , V_28 ) ;
break;
case V_270 :
V_15 = F_19 ( V_6 , V_28 ) ;
break;
case V_271 :
V_15 = F_21 ( V_6 , V_28 ) ;
break;
case V_272 :
V_15 = F_25 ( V_6 , V_28 ) ;
break;
default:
V_3 -> V_39 = V_273 ;
V_15 = V_274 ;
break;
}
if ( V_15 == V_37 )
V_3 -> V_39 = V_275 ;
return V_15 ;
}
static int F_80 ( struct V_5 * V_6 , struct V_38 * V_28 )
{
int V_15 ;
struct V_2 * V_3 = (struct V_2 * ) V_6 -> V_1 ;
switch ( V_28 -> V_61 [ 0 ] ) {
case V_266 :
V_15 = F_60 ( V_6 , V_28 ) ;
break;
case V_267 :
V_15 = F_13 ( V_6 , V_28 ) ;
break;
case V_268 :
V_15 = F_15 ( V_6 , V_28 ) ;
break;
case V_269 :
V_15 = F_62 ( V_6 , V_28 ) ;
break;
case V_270 :
V_15 = F_63 ( V_6 , V_28 ) ;
break;
case V_271 :
V_15 = F_68 ( V_6 , V_28 ) ;
break;
case V_272 :
V_15 = F_70 ( V_6 , V_28 ) ;
break;
default:
V_3 -> V_39 = V_273 ;
V_15 = V_274 ;
break;
}
if ( V_15 == V_37 )
V_3 -> V_39 = V_275 ;
return V_15 ;
}
static int F_81 ( struct V_38 * V_28 , struct V_5 * V_6 )
{
int V_15 = V_23 ;
struct V_2 * V_3 = (struct V_2 * ) ( V_6 -> V_1 ) ;
F_10 ( V_28 , 0 ) ;
if ( F_82 ( ! ( V_3 -> V_41 . V_43 || V_3 -> V_195 . V_43 ) ) )
V_15 = F_78 ( V_6 ) ;
if ( V_15 == V_23 ) {
V_15 = V_24 ;
if ( V_3 -> V_41 . V_43 )
V_15 = F_79 ( V_6 , V_28 ) ;
if ( V_3 -> V_195 . V_43 )
V_15 = F_80 ( V_6 , V_28 ) ;
}
return V_15 ;
}
static int F_83 ( struct V_276 * V_277 ,
const struct V_278 * V_279 )
{
int V_15 ;
T_1 V_264 ;
struct V_5 * V_6 ;
struct V_2 * V_3 ;
V_15 = F_84 ( & V_6 , V_277 , V_279 ,
( V_279 - V_280 ) + V_281 ,
& V_282 ) ;
if ( V_15 )
return V_15 ;
V_6 -> V_1 = F_85 ( sizeof( struct V_2 ) , V_84 ) ;
if ( ! V_6 -> V_1 )
return - V_283 ;
V_6 -> V_284 = F_1 ;
V_3 = (struct V_2 * ) ( V_6 -> V_1 ) ;
V_3 -> V_4 = F_32 ( 512 , V_84 ) ;
if ( ! V_3 -> V_4 ) {
F_2 ( V_6 -> V_1 ) ;
return - V_283 ;
}
V_6 -> V_285 = L_44 ;
V_6 -> V_286 = F_81 ;
V_6 -> V_287 = 0 ;
V_15 = F_86 ( V_6 ) ;
if ( V_15 )
return V_15 ;
V_15 = F_71 ( V_6 , V_265 , V_3 -> V_4 ) ;
if ( V_15 != V_23 ) {
F_87 ( V_277 ) ;
return V_24 ;
}
V_264 = V_3 -> V_4 [ 0 ] ;
if ( ! ( V_264 & 0x01 ) ) {
F_69 ( L_45
L_46 ) ;
}
return V_15 ;
}
static int F_88 ( struct V_276 * V_288 )
{
T_1 V_289 = 0 ;
struct V_5 * V_6 = F_89 ( V_288 ) ;
struct V_2 * V_3 = (struct V_2 * ) ( V_6 -> V_1 ) ;
F_90 ( & V_6 -> V_290 ) ;
if ( V_6 -> V_291 )
( V_6 -> V_291 ) ( V_6 , V_292 ) ;
F_91 ( & V_6 -> V_290 ) ;
V_3 -> V_293 = true ;
V_3 -> V_41 = * (struct V_261 * ) & V_289 ;
V_3 -> V_195 = * (struct V_259 * ) & V_289 ;
V_3 -> V_294 = * (struct V_295 * ) & V_289 ;
return 0 ;
}
static int F_92 ( struct V_276 * V_288 )
{
T_1 V_289 = 0 ;
struct V_5 * V_6 = F_89 ( V_288 ) ;
struct V_2 * V_3 = (struct V_2 * ) ( V_6 -> V_1 ) ;
F_93 ( V_288 ) ;
V_3 -> V_293 = true ;
V_3 -> V_41 = * (struct V_261 * ) & V_289 ;
V_3 -> V_195 = * (struct V_259 * ) & V_289 ;
V_3 -> V_294 = * (struct V_295 * ) & V_289 ;
return 0 ;
}
