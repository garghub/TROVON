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
if ( V_3 -> V_39 . V_40 && V_3 -> V_39 . V_41 )
return V_37 ;
else {
F_14 ( V_6 ) ;
return V_37 ;
}
return V_37 ;
}
static int F_15 ( struct V_5 * V_6 , struct V_38 * V_28 )
{
unsigned char V_42 [ 36 ] = {
0x00 , 0x80 , 0x02 , 0x00 , 0x1F , 0x00 , 0x00 , 0x00 , 0x55 ,
0x53 , 0x42 , 0x32 , 0x2E , 0x30 , 0x20 , 0x20 , 0x43 , 0x61 ,
0x72 , 0x64 , 0x52 , 0x65 , 0x61 , 0x64 , 0x65 , 0x72 , 0x20 ,
0x20 , 0x20 , 0x20 , 0x20 , 0x20 , 0x30 , 0x31 , 0x30 , 0x30 } ;
F_16 ( V_42 , 36 , V_28 ) ;
return V_37 ;
}
static int F_17 ( struct V_5 * V_6 , struct V_38 * V_28 )
{
struct V_2 * V_3 = (struct V_2 * ) V_6 -> V_1 ;
unsigned char V_43 [ 12 ] = {
0x0b , 0x00 , 0x00 , 0x08 , 0x00 , 0x00 ,
0x71 , 0xc0 , 0x00 , 0x00 , 0x02 , 0x00 } ;
unsigned char V_44 [ 12 ] = {
0x0b , 0x00 , 0x80 , 0x08 , 0x00 , 0x00 ,
0x71 , 0xc0 , 0x00 , 0x00 , 0x02 , 0x00 } ;
if ( V_3 -> V_39 . V_45 )
F_16 ( V_44 , 12 , V_28 ) ;
else
F_16 ( V_43 , 12 , V_28 ) ;
return V_37 ;
}
static int F_18 ( struct V_5 * V_6 , struct V_38 * V_28 )
{
T_2 V_46 ;
T_2 V_47 ;
unsigned int V_48 = 0 ;
unsigned char V_8 [ 8 ] ;
struct V_49 * V_50 = NULL ;
struct V_2 * V_3 = (struct V_2 * ) V_6 -> V_1 ;
F_5 ( V_6 , L_5 ) ;
if ( V_3 -> V_39 . V_51 ) {
V_47 = 0x200 ;
if ( V_3 -> V_39 . V_52 )
V_46 = V_3 -> V_53 - 1 ;
else
V_46 = ( V_3 -> V_53 + 1 ) * 1024 - 1 ;
} else {
V_47 = 1 << ( V_3 -> V_54 ) ;
V_46 = V_3 -> V_55 * ( V_3 -> V_56 + 1 )
* ( 1 << ( V_3 -> V_57 + 2 ) ) - 1 ;
}
V_3 -> V_46 = V_46 ;
F_5 ( V_6 , L_6 , V_47 ) ;
F_5 ( V_6 , L_7 , V_46 ) ;
V_8 [ 0 ] = ( V_46 >> 24 ) & 0xff ;
V_8 [ 1 ] = ( V_46 >> 16 ) & 0xff ;
V_8 [ 2 ] = ( V_46 >> 8 ) & 0xff ;
V_8 [ 3 ] = ( V_46 >> 0 ) & 0xff ;
V_8 [ 4 ] = ( V_47 >> 24 ) & 0xff ;
V_8 [ 5 ] = ( V_47 >> 16 ) & 0xff ;
V_8 [ 6 ] = ( V_47 >> 8 ) & 0xff ;
V_8 [ 7 ] = ( V_47 >> 0 ) & 0xff ;
F_19 ( V_8 , 8 , V_28 , & V_50 , & V_48 , V_58 ) ;
return V_37 ;
}
static int F_20 ( struct V_5 * V_6 , struct V_38 * V_28 )
{
int V_15 ;
unsigned char * V_59 = V_28 -> V_60 ;
struct V_10 * V_11 = (struct V_10 * ) V_6 -> V_12 ;
struct V_2 * V_3 = (struct V_2 * ) V_6 -> V_1 ;
T_2 V_61 = ( ( V_59 [ 2 ] << 24 ) & 0xff000000 ) | ( ( V_59 [ 3 ] << 16 ) & 0x00ff0000 ) |
( ( V_59 [ 4 ] << 8 ) & 0x0000ff00 ) | ( ( V_59 [ 5 ] << 0 ) & 0x000000ff ) ;
T_3 V_62 = ( ( V_59 [ 7 ] << 8 ) & 0xff00 ) | ( ( V_59 [ 8 ] << 0 ) & 0x00ff ) ;
T_2 V_63 = V_61 * 0x200 ;
T_2 V_64 = V_62 * 0x200 ;
if ( V_61 > V_3 -> V_46 )
return V_24 ;
V_15 = F_21 ( V_6 , V_65 ) ;
if ( V_15 != V_23 ) {
F_5 ( V_6 , L_8 ) ;
return V_24 ;
}
if ( V_3 -> V_39 . V_51 )
V_63 = V_61 ;
memset ( V_11 , 0 , sizeof( struct V_10 ) ) ;
V_11 -> V_66 = F_22 ( V_67 ) ;
V_11 -> V_20 = V_64 ;
V_11 -> V_68 = V_69 ;
V_11 -> V_70 [ 0 ] = 0xF1 ;
V_11 -> V_70 [ 5 ] = ( unsigned char ) ( V_63 ) ;
V_11 -> V_70 [ 4 ] = ( unsigned char ) ( V_63 >> 8 ) ;
V_11 -> V_70 [ 3 ] = ( unsigned char ) ( V_63 >> 16 ) ;
V_11 -> V_70 [ 2 ] = ( unsigned char ) ( V_63 >> 24 ) ;
V_15 = F_3 ( V_6 , V_26 , F_23 ( V_28 ) , 1 ) ;
return V_15 ;
}
static int F_24 ( struct V_5 * V_6 , struct V_38 * V_28 )
{
int V_15 ;
unsigned char * V_59 = V_28 -> V_60 ;
struct V_10 * V_11 = (struct V_10 * ) V_6 -> V_12 ;
struct V_2 * V_3 = (struct V_2 * ) V_6 -> V_1 ;
T_2 V_61 = ( ( V_59 [ 2 ] << 24 ) & 0xff000000 ) | ( ( V_59 [ 3 ] << 16 ) & 0x00ff0000 ) |
( ( V_59 [ 4 ] << 8 ) & 0x0000ff00 ) | ( ( V_59 [ 5 ] << 0 ) & 0x000000ff ) ;
T_3 V_62 = ( ( V_59 [ 7 ] << 8 ) & 0xff00 ) | ( ( V_59 [ 8 ] << 0 ) & 0x00ff ) ;
T_2 V_63 = V_61 * 0x200 ;
T_2 V_64 = V_62 * 0x200 ;
if ( V_61 > V_3 -> V_46 )
return V_24 ;
V_15 = F_21 ( V_6 , V_65 ) ;
if ( V_15 != V_23 ) {
F_5 ( V_6 , L_8 ) ;
return V_24 ;
}
if ( V_3 -> V_39 . V_51 )
V_63 = V_61 ;
memset ( V_11 , 0 , sizeof( struct V_10 ) ) ;
V_11 -> V_66 = F_22 ( V_67 ) ;
V_11 -> V_20 = V_64 ;
V_11 -> V_68 = 0x00 ;
V_11 -> V_70 [ 0 ] = 0xF0 ;
V_11 -> V_70 [ 5 ] = ( unsigned char ) ( V_63 ) ;
V_11 -> V_70 [ 4 ] = ( unsigned char ) ( V_63 >> 8 ) ;
V_11 -> V_70 [ 3 ] = ( unsigned char ) ( V_63 >> 16 ) ;
V_11 -> V_70 [ 2 ] = ( unsigned char ) ( V_63 >> 24 ) ;
V_15 = F_3 ( V_6 , V_71 , F_23 ( V_28 ) , 1 ) ;
return V_15 ;
}
static int F_25 ( struct V_5 * V_6 , T_3 V_72 , T_3 V_73 )
{
struct V_2 * V_3 = (struct V_2 * ) V_6 -> V_1 ;
if ( ( V_72 >= V_3 -> V_74 . V_75 ) || ( V_73 >= V_3 -> V_74 . V_76 ) )
return ( T_2 ) - 1 ;
V_3 -> V_74 . V_77 [ V_73 ] = V_72 ;
V_3 -> V_74 . V_78 [ V_72 ] = V_73 ;
return 0 ;
}
static int F_26 ( struct V_5 * V_6 , T_3 V_73 , T_3 V_79 )
{
struct V_2 * V_3 = (struct V_2 * ) V_6 -> V_1 ;
if ( V_73 >= V_3 -> V_74 . V_76 )
return ( T_2 ) - 1 ;
V_3 -> V_74 . V_77 [ V_73 ] = V_79 ;
return 0 ;
}
static int F_27 ( struct V_5 * V_6 , T_3 V_73 )
{
return F_26 ( V_6 , V_73 , V_80 ) ;
}
static int F_28 ( struct V_5 * V_6 , T_3 V_73 )
{
return F_26 ( V_6 , V_73 , V_81 ) ;
}
static int F_29 ( struct V_5 * V_6 )
{
struct V_2 * V_3 = (struct V_2 * ) V_6 -> V_1 ;
F_2 ( V_3 -> V_74 . V_77 ) ;
V_3 -> V_74 . V_77 = NULL ;
F_2 ( V_3 -> V_74 . V_78 ) ;
V_3 -> V_74 . V_78 = NULL ;
return 0 ;
}
static int F_30 ( struct V_5 * V_6 )
{
T_2 V_82 ;
struct V_2 * V_3 = (struct V_2 * ) V_6 -> V_1 ;
V_3 -> V_74 . V_77 = F_31 ( V_3 -> V_74 . V_76 * sizeof( T_3 ) , V_83 ) ;
V_3 -> V_74 . V_78 = F_31 ( V_3 -> V_74 . V_75 * sizeof( T_3 ) , V_83 ) ;
if ( ( V_3 -> V_74 . V_77 == NULL ) || ( V_3 -> V_74 . V_78 == NULL ) ) {
F_29 ( V_6 ) ;
return ( T_2 ) - 1 ;
}
for ( V_82 = 0 ; V_82 < V_3 -> V_74 . V_76 ; V_82 ++ )
V_3 -> V_74 . V_77 [ V_82 ] = V_84 ;
for ( V_82 = 0 ; V_82 < V_3 -> V_74 . V_75 ; V_82 ++ )
V_3 -> V_74 . V_78 [ V_82 ] = V_84 ;
return 0 ;
}
static void F_32 ( struct V_5 * V_6 )
{
int V_82 ;
struct V_2 * V_3 = (struct V_2 * ) V_6 -> V_1 ;
V_3 -> V_74 . V_85 = ( T_3 ) - 1 ;
F_33 ( V_3 ) ;
if ( V_3 -> V_74 . V_86 )
memset ( V_3 -> V_74 . V_86 , 0xff , V_3 -> V_74 . V_87 * V_3 -> V_74 . V_88 ) ;
if ( V_3 -> V_74 . V_89 ) {
for ( V_82 = 0 ; V_82 < V_3 -> V_74 . V_87 ; V_82 ++ ) {
V_3 -> V_74 . V_89 [ V_82 ] . V_90 = V_91 ;
V_3 -> V_74 . V_89 [ V_82 ] . V_92 = V_93 ;
V_3 -> V_74 . V_89 [ V_82 ] . V_94 = V_95 ;
V_3 -> V_74 . V_89 [ V_82 ] . V_96 = V_84 ;
}
}
}
static int F_34 ( struct V_5 * V_6 , T_3 V_97 )
{
T_2 V_98 , V_99 ;
struct V_2 * V_3 = (struct V_2 * ) V_6 -> V_1 ;
V_98 = V_97 + V_100 ;
for ( V_99 = 0 ; V_97 < V_98 ; V_97 ++ ) {
switch ( V_3 -> V_74 . V_77 [ V_97 ] ) {
case V_84 :
case V_101 :
V_99 ++ ;
default:
break;
}
}
return V_99 ;
}
static int F_35 ( struct V_5 * V_6 , T_2 V_102 ,
T_1 V_103 , T_2 * V_104 , struct V_105 * V_106 )
{
struct V_10 * V_11 = (struct V_10 * ) V_6 -> V_12 ;
struct V_2 * V_3 = (struct V_2 * ) V_6 -> V_1 ;
T_1 * V_4 = V_3 -> V_4 ;
int V_15 ;
T_2 V_61 = V_102 * 0x20 + V_103 ;
V_15 = F_21 ( V_6 , V_107 ) ;
if ( V_15 != V_23 )
return V_24 ;
memset ( V_11 , 0 , sizeof( struct V_10 ) ) ;
V_11 -> V_66 = F_22 ( V_67 ) ;
V_11 -> V_20 = 0x200 ;
V_11 -> V_68 = V_69 ;
V_11 -> V_70 [ 0 ] = 0xF1 ;
V_11 -> V_70 [ 1 ] = 0x02 ;
V_11 -> V_70 [ 5 ] = ( unsigned char ) ( V_61 ) ;
V_11 -> V_70 [ 4 ] = ( unsigned char ) ( V_61 >> 8 ) ;
V_11 -> V_70 [ 3 ] = ( unsigned char ) ( V_61 >> 16 ) ;
V_11 -> V_70 [ 2 ] = ( unsigned char ) ( V_61 >> 24 ) ;
V_15 = F_3 ( V_6 , V_26 , V_104 , 0 ) ;
if ( V_15 != V_23 )
return V_24 ;
memset ( V_11 , 0 , sizeof( struct V_10 ) ) ;
V_11 -> V_66 = F_22 ( V_67 ) ;
V_11 -> V_20 = 0x4 ;
V_11 -> V_68 = V_69 ;
V_11 -> V_70 [ 0 ] = 0xF1 ;
V_11 -> V_70 [ 1 ] = 0x03 ;
V_11 -> V_70 [ 5 ] = ( unsigned char ) ( V_103 ) ;
V_11 -> V_70 [ 4 ] = ( unsigned char ) ( V_102 ) ;
V_11 -> V_70 [ 3 ] = ( unsigned char ) ( V_102 >> 8 ) ;
V_11 -> V_70 [ 2 ] = ( unsigned char ) ( V_102 >> 16 ) ;
V_11 -> V_70 [ 6 ] = 0x01 ;
V_15 = F_3 ( V_6 , V_26 , V_4 , 0 ) ;
if ( V_15 != V_23 )
return V_24 ;
V_106 -> V_108 = 0 ;
V_106 -> V_109 = 0x80 ;
V_106 -> V_110 = 0x10 ;
V_106 -> V_90 = 0x00 ;
V_106 -> V_92 = V_4 [ 0 ] ;
V_106 -> V_94 = V_4 [ 1 ] ;
V_106 -> V_96 = F_36 ( V_4 [ 2 ] , V_4 [ 3 ] ) ;
return V_37 ;
}
static int F_37 ( struct V_5 * V_6 , T_3 V_97 , T_1 * V_111 )
{
struct V_112 * V_113 ;
struct V_114 * V_115 ;
T_2 V_82 , V_15 ;
T_1 V_116 ;
T_1 * V_117 ;
struct V_105 V_118 ;
struct V_2 * V_3 = (struct V_2 * ) V_6 -> V_1 ;
V_117 = F_31 ( V_119 , V_83 ) ;
if ( V_117 == NULL )
return ( T_2 ) - 1 ;
V_15 = ( T_2 ) - 1 ;
V_115 = & ( ( (struct V_120 * ) V_111 ) -> V_121 ) ;
if ( ( V_115 -> V_122 != V_123 ) ||
( F_38 ( V_115 -> V_124 ) != V_125 ) ||
( ( V_115 -> V_126 & V_127 ) == V_128 ) ||
( V_115 -> V_129 != V_130 ) ||
( V_115 -> V_131 != V_132 ) ||
( V_115 -> V_133 != V_134 ) ||
( V_115 -> V_135 != V_136 ) )
goto exit;
switch ( V_3 -> V_74 . V_137 = V_115 -> V_138 ) {
case V_139 :
F_39 ( V_3 , V_140 ) ;
break;
case V_141 :
F_40 ( V_3 , V_140 ) ;
break;
case V_142 :
default:
goto exit;
}
V_3 -> V_74 . V_143 = F_38 ( V_115 -> V_144 ) ;
V_3 -> V_74 . V_76 = F_38 ( V_115 -> V_145 ) ;
V_3 -> V_74 . V_75 = F_38 ( V_115 -> V_146 ) - 2 ;
V_3 -> V_74 . V_87 = V_3 -> V_74 . V_143 * V_147 / V_119 ;
V_3 -> V_74 . V_148 = V_3 -> V_74 . V_76 / V_100 ;
V_3 -> V_149 = F_38 ( V_115 -> V_150 ) ;
if ( F_30 ( V_6 ) )
goto exit;
F_28 ( V_6 , V_97 ) ;
V_113 = & ( ( (struct V_120 * ) V_111 ) -> V_151 ) ;
for ( V_82 = 0 ; V_82 < V_152 ; V_82 ++ ) {
T_2 V_153 , V_154 ;
V_153 = F_41 ( V_113 -> V_155 [ V_82 ] . V_156 ) ;
if ( V_153 == 0xffffff )
continue;
V_154 = F_41 ( V_113 -> V_155 [ V_82 ] . V_157 ) ;
if ( V_154 == 0 )
continue;
if ( V_153 + V_119 + V_154 > V_3 -> V_74 . V_143 * ( T_2 ) V_147 )
continue;
if ( V_82 == 0 ) {
T_1 V_158 = 0 ;
T_3 V_73 ;
if ( V_113 -> V_155 [ V_82 ] . V_159 != V_160 )
goto exit;
while ( V_154 > 0 ) {
V_116 = ( T_1 ) ( V_153 / V_119 + 1 ) ;
if ( V_116 != V_158 ) {
switch ( F_35 ( V_6 , V_97 , V_116 , ( T_2 * ) V_117 , & V_118 ) ) {
case V_161 :
break;
case V_162 :
case V_163 :
case V_164 :
default:
goto exit;
}
V_158 = V_116 ;
}
V_73 = F_38 ( * ( T_3 * ) ( V_117 + ( V_153 % V_119 ) ) ) ;
if ( V_73 < 0x0fff )
F_27 ( V_6 , V_73 ) ;
V_153 += 2 ;
V_154 -= 2 ;
}
} else if ( V_82 == 1 ) {
struct V_165 * V_166 ;
if ( V_113 -> V_155 [ V_82 ] . V_159 != V_167 )
goto exit;
switch ( F_35 ( V_6 , V_97 , ( T_1 ) ( V_153 / V_119 + 1 ) , ( T_2 * ) V_117 , & V_118 ) ) {
case V_161 :
break;
case V_162 :
case V_163 :
case V_164 :
default:
goto exit;
}
V_166 = & ( (struct V_168 * ) ( V_117 + ( V_153 % V_119 ) ) ) -> V_166 . V_166 ;
if ( F_42 ( V_166 -> V_169 ) != V_170 )
goto exit;
V_3 -> V_74 . V_88 = F_42 ( V_166 -> V_171 ) ;
if ( V_3 -> V_74 . V_88 != V_119 )
goto exit;
}
}
V_15 = 0 ;
exit:
if ( V_15 )
F_29 ( V_6 ) ;
F_2 ( V_117 ) ;
V_15 = 0 ;
return V_15 ;
}
static void F_43 ( struct V_5 * V_6 )
{
struct V_2 * V_3 = (struct V_2 * ) V_6 -> V_1 ;
V_3 -> V_74 . V_85 = ( T_3 ) - 1 ;
F_33 ( V_3 ) ;
if ( V_3 -> V_74 . V_86 ) {
F_2 ( V_3 -> V_74 . V_86 ) ;
V_3 -> V_74 . V_86 = NULL ;
}
if ( V_3 -> V_74 . V_89 ) {
F_2 ( V_3 -> V_74 . V_89 ) ;
V_3 -> V_74 . V_89 = NULL ;
}
}
static void F_44 ( struct V_5 * V_6 )
{
struct V_2 * V_3 = (struct V_2 * ) V_6 -> V_1 ;
F_43 ( V_6 ) ;
F_29 ( V_6 ) ;
V_3 -> V_74 . V_172 = 0 ;
V_3 -> V_74 . V_88 = 0 ;
V_3 -> V_74 . V_173 = 0 ;
V_3 -> V_74 . V_137 = 0 ;
V_3 -> V_74 . V_143 = 0 ;
V_3 -> V_74 . V_87 = 0 ;
V_3 -> V_74 . V_76 = 0 ;
V_3 -> V_74 . V_75 = 0 ;
}
static int F_45 ( struct V_5 * V_6 )
{
struct V_2 * V_3 = (struct V_2 * ) V_6 -> V_1 ;
V_3 -> V_74 . V_85 = ( T_3 ) - 1 ;
V_3 -> V_74 . V_86 = F_31 ( V_3 -> V_74 . V_87 * V_3 -> V_74 . V_88 , V_83 ) ;
V_3 -> V_74 . V_89 = F_31 ( V_3 -> V_74 . V_87 * sizeof( struct V_105 ) , V_83 ) ;
if ( ( V_3 -> V_74 . V_86 == NULL ) || ( V_3 -> V_74 . V_89 == NULL ) ) {
F_43 ( V_6 ) ;
return ( T_2 ) - 1 ;
}
F_32 ( V_6 ) ;
return 0 ;
}
static int F_46 ( struct V_5 * V_6 , T_3 V_72 , T_3 V_73 )
{
struct V_2 * V_3 = (struct V_2 * ) V_6 -> V_1 ;
if ( V_72 == V_84 )
return 0 ;
if ( ( V_72 >= V_3 -> V_74 . V_75 ) ||
( V_73 >= V_3 -> V_74 . V_76 ) )
return ( T_2 ) - 1 ;
V_3 -> V_74 . V_77 [ V_73 ] = V_72 ;
V_3 -> V_74 . V_78 [ V_72 ] = V_73 ;
return 0 ;
}
static int F_47 ( struct V_5 * V_6 , T_3 V_174 , T_3 V_175 ,
T_3 V_102 , T_1 V_103 , unsigned char * V_8 , T_3 V_176 )
{
struct V_10 * V_11 = (struct V_10 * ) V_6 -> V_12 ;
int V_15 ;
V_15 = F_21 ( V_6 , V_107 ) ;
if ( V_15 != V_23 )
return V_24 ;
memset ( V_11 , 0 , sizeof( struct V_10 ) ) ;
V_11 -> V_66 = F_22 ( V_67 ) ;
V_11 -> V_20 = 0x200 * V_176 ;
V_11 -> V_68 = 0x00 ;
V_11 -> V_70 [ 0 ] = 0xF0 ;
V_11 -> V_70 [ 1 ] = 0x08 ;
V_11 -> V_70 [ 4 ] = ( unsigned char ) ( V_174 ) ;
V_11 -> V_70 [ 3 ] = ( unsigned char ) ( V_174 >> 8 ) ;
V_11 -> V_70 [ 2 ] = 0 ;
V_11 -> V_70 [ 7 ] = ( unsigned char ) ( V_175 ) ;
V_11 -> V_70 [ 6 ] = ( unsigned char ) ( V_175 >> 8 ) ;
V_11 -> V_70 [ 5 ] = 0 ;
V_11 -> V_70 [ 9 ] = ( unsigned char ) ( V_102 ) ;
V_11 -> V_70 [ 8 ] = ( unsigned char ) ( V_102 >> 8 ) ;
V_11 -> V_70 [ 10 ] = V_103 ;
V_15 = F_3 ( V_6 , V_71 , V_8 , 0 ) ;
if ( V_15 != V_23 )
return V_24 ;
return V_37 ;
}
static int F_48 ( struct V_5 * V_6 , T_2 V_102 )
{
struct V_10 * V_11 = (struct V_10 * ) V_6 -> V_12 ;
int V_15 ;
T_2 V_61 = V_102 ;
V_15 = F_21 ( V_6 , V_107 ) ;
if ( V_15 != V_23 )
return V_24 ;
memset ( V_11 , 0 , sizeof( struct V_10 ) ) ;
V_11 -> V_66 = F_22 ( V_67 ) ;
V_11 -> V_20 = 0x200 ;
V_11 -> V_68 = V_69 ;
V_11 -> V_70 [ 0 ] = 0xF2 ;
V_11 -> V_70 [ 1 ] = 0x06 ;
V_11 -> V_70 [ 4 ] = ( unsigned char ) ( V_61 ) ;
V_11 -> V_70 [ 3 ] = ( unsigned char ) ( V_61 >> 8 ) ;
V_11 -> V_70 [ 2 ] = ( unsigned char ) ( V_61 >> 16 ) ;
V_15 = F_3 ( V_6 , V_26 , NULL , 0 ) ;
if ( V_15 != V_23 )
return V_24 ;
return V_37 ;
}
static int F_49 ( struct V_5 * V_6 , T_3 V_97 )
{
unsigned char * V_104 = NULL ;
T_3 V_15 = V_161 ;
T_3 V_177 , V_178 = 0 ;
struct V_105 V_179 ;
struct V_2 * V_3 = (struct V_2 * ) V_6 -> V_1 ;
V_104 = F_31 ( V_119 , V_83 ) ;
if ( V_104 == NULL ) {
V_15 = V_180 ;
goto exit;
}
F_35 ( V_6 , V_97 , 1 , ( T_2 * ) V_104 , & V_179 ) ;
do {
V_177 = F_38 ( V_104 [ V_178 ] ) ;
if ( V_177 == V_84 )
break;
if ( V_177 == V_3 -> V_74 . V_78 [ 0 ] ) {
V_15 = V_163 ;
break;
}
V_178 ++ ;
} while ( 1 );
exit:
F_2 ( V_104 ) ;
return V_15 ;
}
static int F_50 ( struct V_5 * V_6 , T_3 V_73 )
{
T_3 log ;
struct V_2 * V_3 = (struct V_2 * ) V_6 -> V_1 ;
if ( V_73 >= V_3 -> V_74 . V_76 )
return ( T_2 ) - 1 ;
log = V_3 -> V_74 . V_77 [ V_73 ] ;
if ( log < V_3 -> V_74 . V_75 )
V_3 -> V_74 . V_78 [ log ] = V_84 ;
if ( V_3 -> V_74 . V_77 [ V_73 ] != V_80 )
V_3 -> V_74 . V_77 [ V_73 ] = V_181 ;
return 0 ;
}
static int F_51 ( struct V_5 * V_6 , T_2 V_102 ,
T_1 V_103 , T_1 V_182 )
{
struct V_10 * V_11 = (struct V_10 * ) V_6 -> V_12 ;
int V_15 ;
V_15 = F_21 ( V_6 , V_107 ) ;
if ( V_15 != V_23 )
return V_24 ;
memset ( V_11 , 0 , sizeof( struct V_10 ) ) ;
V_11 -> V_66 = F_22 ( V_67 ) ;
V_11 -> V_20 = 0x4 ;
V_11 -> V_68 = V_69 ;
V_11 -> V_70 [ 0 ] = 0xF2 ;
V_11 -> V_70 [ 1 ] = 0x05 ;
V_11 -> V_70 [ 5 ] = ( unsigned char ) ( V_103 ) ;
V_11 -> V_70 [ 4 ] = ( unsigned char ) ( V_102 ) ;
V_11 -> V_70 [ 3 ] = ( unsigned char ) ( V_102 >> 8 ) ;
V_11 -> V_70 [ 2 ] = ( unsigned char ) ( V_102 >> 16 ) ;
V_11 -> V_70 [ 6 ] = V_182 ;
V_11 -> V_70 [ 7 ] = 0xFF ;
V_11 -> V_70 [ 8 ] = 0xFF ;
V_11 -> V_70 [ 9 ] = 0xFF ;
V_15 = F_3 ( V_6 , V_26 , NULL , 0 ) ;
if ( V_15 != V_23 )
return V_24 ;
return V_37 ;
}
static int F_52 ( struct V_5 * V_6 , T_3 V_73 )
{
struct V_2 * V_3 = (struct V_2 * ) V_6 -> V_1 ;
if ( V_73 >= V_3 -> V_74 . V_76 )
return V_164 ;
F_50 ( V_6 , V_73 ) ;
if ( F_53 ( V_3 ) )
return F_51 ( V_6 , V_73 , 0 , ( T_1 ) ( ~ V_183 & V_184 ) ) ;
return V_161 ;
}
static int F_54 ( struct V_5 * V_6 , T_3 V_73 )
{
T_3 log ;
struct V_2 * V_3 = (struct V_2 * ) V_6 -> V_1 ;
if ( V_73 >= V_3 -> V_74 . V_76 )
return V_164 ;
log = V_3 -> V_74 . V_77 [ V_73 ] ;
if ( log < V_3 -> V_74 . V_75 )
V_3 -> V_74 . V_78 [ log ] = V_84 ;
V_3 -> V_74 . V_77 [ V_73 ] = V_84 ;
if ( F_53 ( V_3 ) ) {
switch ( F_48 ( V_6 , V_73 ) ) {
case V_161 :
V_3 -> V_74 . V_77 [ V_73 ] = V_101 ;
return V_161 ;
case V_185 :
case V_186 :
F_52 ( V_6 , V_73 ) ;
return V_185 ;
case V_164 :
default:
F_39 ( V_3 , V_140 ) ;
F_50 ( V_6 , V_73 ) ;
return V_164 ;
}
}
F_50 ( V_6 , V_73 ) ;
return V_161 ;
}
static int F_55 ( struct V_5 * V_6 , T_2 V_97 ,
T_1 V_103 , struct V_105 * V_106 )
{
struct V_10 * V_11 = (struct V_10 * ) V_6 -> V_12 ;
struct V_2 * V_3 = (struct V_2 * ) V_6 -> V_1 ;
T_1 * V_4 = V_3 -> V_4 ;
int V_15 ;
memset ( V_11 , 0 , sizeof( struct V_10 ) ) ;
V_11 -> V_66 = F_22 ( V_67 ) ;
V_11 -> V_20 = 0x4 ;
V_11 -> V_68 = V_69 ;
V_11 -> V_70 [ 0 ] = 0xF1 ;
V_11 -> V_70 [ 1 ] = 0x03 ;
V_11 -> V_70 [ 5 ] = ( unsigned char ) ( V_103 ) ;
V_11 -> V_70 [ 4 ] = ( unsigned char ) ( V_97 ) ;
V_11 -> V_70 [ 3 ] = ( unsigned char ) ( V_97 >> 8 ) ;
V_11 -> V_70 [ 2 ] = ( unsigned char ) ( V_97 >> 16 ) ;
V_11 -> V_70 [ 6 ] = 0x01 ;
V_15 = F_3 ( V_6 , V_26 , V_4 , 0 ) ;
if ( V_15 != V_23 )
return V_24 ;
V_106 -> V_108 = 0 ;
V_106 -> V_109 = 0x80 ;
V_106 -> V_110 = 0x10 ;
V_106 -> V_90 = 0x00 ;
V_106 -> V_92 = V_4 [ 0 ] ;
V_106 -> V_94 = V_4 [ 1 ] ;
V_106 -> V_96 = F_36 ( V_4 [ 2 ] , V_4 [ 3 ] ) ;
return V_37 ;
}
static int F_56 ( struct V_5 * V_6 , T_3 V_73 )
{
T_3 V_177 ;
struct V_105 V_179 ;
struct V_2 * V_3 = (struct V_2 * ) V_6 -> V_1 ;
if ( V_73 >= V_3 -> V_74 . V_76 )
return V_187 ;
for ( V_177 = V_73 + 1 ; V_177 != V_73 ; V_177 ++ ) {
if ( ( V_177 & V_188 ) == 0 )
V_177 -= V_100 ;
if ( V_3 -> V_74 . V_77 [ V_177 ] == V_101 ) {
return V_177 ;
} else if ( V_3 -> V_74 . V_77 [ V_177 ] == V_84 ) {
switch ( F_55 ( V_6 , V_177 , 0 , & V_179 ) ) {
case V_161 :
case V_189 :
break;
case V_190 :
return V_190 ;
case V_186 :
return V_187 ;
case V_163 :
default:
F_50 ( V_6 , V_177 ) ;
continue;
}
if ( ( V_179 . V_92 & V_183 ) != V_191 ) {
F_50 ( V_6 , V_177 ) ;
continue;
}
switch ( F_54 ( V_6 , V_177 ) ) {
case V_161 :
return V_177 ;
case V_164 :
return V_187 ;
case V_185 :
default:
F_52 ( V_6 , V_177 ) ;
break;
}
}
}
return V_187 ;
}
static int F_57 ( struct V_5 * V_6 , T_3 V_72 )
{
T_3 V_73 ;
struct V_2 * V_3 = (struct V_2 * ) V_6 -> V_1 ;
V_73 = F_58 ( V_3 , V_72 ) ;
if ( V_73 >= V_187 ) {
if ( V_72 >= V_3 -> V_74 . V_75 )
return V_187 ;
V_73 = ( V_72 + V_192 ) / V_193 ;
V_73 *= V_100 ;
V_73 += V_100 - 1 ;
}
return F_56 ( V_6 , V_73 ) ;
}
static int F_59 ( struct V_5 * V_6 , struct V_38 * V_28 )
{
struct V_2 * V_3 = (struct V_2 * ) ( V_6 -> V_1 ) ;
if ( V_3 -> V_194 . V_40 && V_3 -> V_194 . V_41 ) {
return V_37 ;
} else {
F_60 ( V_6 ) ;
return V_37 ;
}
return V_37 ;
}
static int F_61 ( struct V_5 * V_6 , struct V_38 * V_28 )
{
unsigned char V_42 [ 36 ] = {
0x00 , 0x80 , 0x02 , 0x00 , 0x1F , 0x00 , 0x00 , 0x00 , 0x55 ,
0x53 , 0x42 , 0x32 , 0x2E , 0x30 , 0x20 , 0x20 , 0x43 , 0x61 ,
0x72 , 0x64 , 0x52 , 0x65 , 0x61 , 0x64 , 0x65 , 0x72 , 0x20 ,
0x20 , 0x20 , 0x20 , 0x20 , 0x20 , 0x30 , 0x31 , 0x30 , 0x30 } ;
F_16 ( V_42 , 36 , V_28 ) ;
return V_37 ;
}
static int F_62 ( struct V_5 * V_6 , struct V_38 * V_28 )
{
struct V_2 * V_3 = (struct V_2 * ) V_6 -> V_1 ;
unsigned char V_43 [ 12 ] = {
0x0b , 0x00 , 0x00 , 0x08 , 0x00 , 0x00 ,
0x71 , 0xc0 , 0x00 , 0x00 , 0x02 , 0x00 } ;
unsigned char V_44 [ 12 ] = {
0x0b , 0x00 , 0x80 , 0x08 , 0x00 , 0x00 ,
0x71 , 0xc0 , 0x00 , 0x00 , 0x02 , 0x00 } ;
if ( V_3 -> V_194 . V_45 )
F_16 ( V_44 , 12 , V_28 ) ;
else
F_16 ( V_43 , 12 , V_28 ) ;
return V_37 ;
}
static int F_63 ( struct V_5 * V_6 , struct V_38 * V_28 )
{
T_2 V_46 ;
T_3 V_47 ;
unsigned int V_48 = 0 ;
unsigned char V_8 [ 8 ] ;
struct V_49 * V_50 = NULL ;
struct V_2 * V_3 = (struct V_2 * ) V_6 -> V_1 ;
F_5 ( V_6 , L_9 ) ;
V_47 = 0x200 ;
if ( V_3 -> V_194 . V_195 )
V_46 = V_3 -> V_196 - 1 ;
else
V_46 = V_3 -> V_74 . V_75 * V_3 -> V_74 . V_143 * 2 - 1 ;
V_3 -> V_46 = V_46 ;
F_5 ( V_6 , L_6 , V_47 ) ;
F_5 ( V_6 , L_7 , V_46 ) ;
V_8 [ 0 ] = ( V_46 >> 24 ) & 0xff ;
V_8 [ 1 ] = ( V_46 >> 16 ) & 0xff ;
V_8 [ 2 ] = ( V_46 >> 8 ) & 0xff ;
V_8 [ 3 ] = ( V_46 >> 0 ) & 0xff ;
V_8 [ 4 ] = ( V_47 >> 24 ) & 0xff ;
V_8 [ 5 ] = ( V_47 >> 16 ) & 0xff ;
V_8 [ 6 ] = ( V_47 >> 8 ) & 0xff ;
V_8 [ 7 ] = ( V_47 >> 0 ) & 0xff ;
F_19 ( V_8 , 8 , V_28 , & V_50 , & V_48 , V_58 ) ;
return V_37 ;
}
static void F_64 ( T_3 V_97 , T_3 * V_197 , T_3 * V_198 )
{
V_97 /= V_100 ;
if ( V_97 ) {
* V_197 = V_199 + ( V_97 - 1 ) * V_193 ;
* V_198 = * V_197 + V_193 ;
} else {
* V_197 = 0 ;
* V_198 = V_199 ;
}
}
static int F_65 ( struct V_5 * V_6 , T_2 V_97 ,
T_1 V_103 , T_1 V_62 , void * V_8 )
{
struct V_10 * V_11 = (struct V_10 * ) V_6 -> V_12 ;
int V_15 ;
memset ( V_11 , 0 , sizeof( struct V_10 ) ) ;
V_11 -> V_66 = F_22 ( V_67 ) ;
V_11 -> V_20 = 0x4 * V_62 ;
V_11 -> V_68 = V_69 ;
V_11 -> V_70 [ 0 ] = 0xF1 ;
V_11 -> V_70 [ 1 ] = 0x03 ;
V_11 -> V_70 [ 5 ] = ( unsigned char ) ( V_103 ) ;
V_11 -> V_70 [ 4 ] = ( unsigned char ) ( V_97 ) ;
V_11 -> V_70 [ 3 ] = ( unsigned char ) ( V_97 >> 8 ) ;
V_11 -> V_70 [ 2 ] = ( unsigned char ) ( V_97 >> 16 ) ;
V_11 -> V_70 [ 6 ] = V_62 ;
V_15 = F_3 ( V_6 , V_26 , V_8 , 0 ) ;
if ( V_15 != V_23 )
return V_24 ;
return V_37 ;
}
static int F_66 ( struct V_5 * V_6 , T_3 V_200 )
{
T_3 V_97 , V_201 , V_82 ;
T_3 V_197 , V_198 ;
struct V_105 V_179 ;
T_2 V_202 = 0 , V_178 = 0 ;
struct V_2 * V_3 = (struct V_2 * ) V_6 -> V_1 ;
T_1 * V_4 = V_3 -> V_4 ;
for ( V_97 = 0 ; V_97 < V_3 -> V_74 . V_76 ; ) {
F_64 ( V_97 , & V_197 , & V_198 ) ;
for ( V_82 = 0 ; V_82 < V_100 ; V_82 ++ , V_97 ++ ) {
switch ( F_67 ( V_3 , V_97 ) ) {
case V_164 :
continue;
default:
break;
}
if ( V_202 == V_97 ) {
F_65 ( V_6 , V_97 , 0 , 0x80 ,
V_4 ) ;
V_202 += 0x80 ;
}
V_178 = ( V_97 % 0x80 ) * 4 ;
V_179 . V_92 = V_4 [ V_178 ] ;
V_179 . V_94 = V_4 [ V_178 + 1 ] ;
V_179 . V_96 = F_36 ( V_4 [ V_178 + 2 ] ,
V_4 [ V_178 + 3 ] ) ;
if ( ( V_179 . V_92 & V_183 ) != V_191 ) {
F_50 ( V_6 , V_97 ) ;
continue;
}
if ( ( V_179 . V_94 & V_203 ) == V_204 ) {
F_54 ( V_6 , V_97 ) ;
continue;
}
if ( V_179 . V_96 != V_84 ) {
if ( ( V_179 . V_96 < V_197 ) || ( V_198 <= V_179 . V_96 ) ) {
F_54 ( V_6 , V_97 ) ;
continue;
}
V_201 = F_58 ( V_3 , V_179 . V_96 ) ;
if ( V_201 != V_84 ) {
if ( V_179 . V_96 == 0 ) {
F_25 ( V_6 , V_179 . V_96 , V_97 ) ;
if ( F_49 ( V_6 , V_200 ) ) {
F_25 ( V_6 , V_179 . V_96 , V_201 ) ;
continue;
}
}
F_55 ( V_6 , V_201 , 0 , & V_179 ) ;
if ( ( V_179 . V_92 & V_205 ) == V_206 ) {
F_54 ( V_6 , V_97 ) ;
continue;
} else {
F_54 ( V_6 , V_201 ) ;
}
}
F_25 ( V_6 , V_179 . V_96 , V_97 ) ;
}
}
}
return V_161 ;
}
static int F_68 ( struct V_5 * V_6 , struct V_38 * V_28 )
{
int V_15 ;
unsigned char * V_59 = V_28 -> V_60 ;
struct V_10 * V_11 = (struct V_10 * ) V_6 -> V_12 ;
struct V_2 * V_3 = (struct V_2 * ) V_6 -> V_1 ;
T_2 V_61 = ( ( V_59 [ 2 ] << 24 ) & 0xff000000 ) | ( ( V_59 [ 3 ] << 16 ) & 0x00ff0000 ) |
( ( V_59 [ 4 ] << 8 ) & 0x0000ff00 ) | ( ( V_59 [ 5 ] << 0 ) & 0x000000ff ) ;
T_3 V_62 = ( ( V_59 [ 7 ] << 8 ) & 0xff00 ) | ( ( V_59 [ 8 ] << 0 ) & 0x00ff ) ;
T_2 V_64 = V_62 * 0x200 ;
if ( V_61 > V_3 -> V_46 )
return V_24 ;
if ( V_3 -> V_194 . V_195 ) {
V_15 = F_21 ( V_6 , V_207 ) ;
if ( V_15 != V_23 ) {
F_5 ( V_6 , L_10 ) ;
return V_24 ;
}
memset ( V_11 , 0 , sizeof( struct V_10 ) ) ;
V_11 -> V_66 = F_22 ( V_67 ) ;
V_11 -> V_20 = V_64 ;
V_11 -> V_68 = V_69 ;
V_11 -> V_70 [ 0 ] = 0xF1 ;
V_11 -> V_70 [ 1 ] = 0x02 ;
V_11 -> V_70 [ 5 ] = ( unsigned char ) ( V_61 ) ;
V_11 -> V_70 [ 4 ] = ( unsigned char ) ( V_61 >> 8 ) ;
V_11 -> V_70 [ 3 ] = ( unsigned char ) ( V_61 >> 16 ) ;
V_11 -> V_70 [ 2 ] = ( unsigned char ) ( V_61 >> 24 ) ;
V_15 = F_3 ( V_6 , V_26 , F_23 ( V_28 ) , 1 ) ;
} else {
void * V_8 ;
int V_48 = 0 ;
T_3 V_73 , V_72 ;
T_1 V_103 ;
T_3 V_176 ;
T_2 V_208 ;
V_8 = F_31 ( V_64 , V_83 ) ;
if ( V_8 == NULL )
return V_24 ;
V_15 = F_21 ( V_6 , V_107 ) ;
if ( V_15 != V_23 ) {
F_69 ( L_11 ) ;
V_15 = V_24 ;
goto exit;
}
V_72 = ( T_3 ) ( V_61 / V_3 -> V_74 . V_87 ) ;
V_103 = ( T_1 ) ( V_61 % V_3 -> V_74 . V_87 ) ;
while ( 1 ) {
if ( V_62 > ( V_3 -> V_74 . V_87 - V_103 ) )
V_176 = V_3 -> V_74 . V_87 - V_103 ;
else
V_176 = V_62 ;
V_73 = F_58 ( V_3 , V_72 ) ;
V_208 = V_73 * 0x20 + V_103 ;
memset ( V_11 , 0 , sizeof( struct V_10 ) ) ;
V_11 -> V_66 = F_22 ( V_67 ) ;
V_11 -> V_20 = 0x200 * V_176 ;
V_11 -> V_68 = V_69 ;
V_11 -> V_70 [ 0 ] = 0xF1 ;
V_11 -> V_70 [ 1 ] = 0x02 ;
V_11 -> V_70 [ 5 ] = ( unsigned char ) ( V_208 ) ;
V_11 -> V_70 [ 4 ] = ( unsigned char ) ( V_208 >> 8 ) ;
V_11 -> V_70 [ 3 ] = ( unsigned char ) ( V_208 >> 16 ) ;
V_11 -> V_70 [ 2 ] = ( unsigned char ) ( V_208 >> 24 ) ;
V_15 = F_3 ( V_6 , V_26 , V_8 + V_48 , 0 ) ;
if ( V_15 != V_23 ) {
F_69 ( L_12 , V_15 ) ;
V_15 = V_24 ;
goto exit;
}
V_62 -= V_176 ;
if ( V_62 <= 0 )
break;
V_72 ++ ;
V_103 = 0 ;
V_48 += V_119 * V_176 ;
}
F_16 ( V_8 , V_64 , V_28 ) ;
exit:
F_2 ( V_8 ) ;
}
return V_15 ;
}
static int F_70 ( struct V_5 * V_6 , struct V_38 * V_28 )
{
int V_15 ;
struct V_10 * V_11 = (struct V_10 * ) V_6 -> V_12 ;
unsigned char * V_59 = V_28 -> V_60 ;
struct V_2 * V_3 = (struct V_2 * ) V_6 -> V_1 ;
T_2 V_61 = ( ( V_59 [ 2 ] << 24 ) & 0xff000000 ) |
( ( V_59 [ 3 ] << 16 ) & 0x00ff0000 ) |
( ( V_59 [ 4 ] << 8 ) & 0x0000ff00 ) |
( ( V_59 [ 5 ] << 0 ) & 0x000000ff ) ;
T_3 V_62 = ( ( V_59 [ 7 ] << 8 ) & 0xff00 ) | ( ( V_59 [ 8 ] << 0 ) & 0x00ff ) ;
T_2 V_64 = V_62 * 0x200 ;
if ( V_61 > V_3 -> V_46 )
return V_24 ;
if ( V_3 -> V_194 . V_195 ) {
V_15 = F_21 ( V_6 , V_207 ) ;
if ( V_15 != V_23 ) {
F_69 ( L_13 ) ;
return V_24 ;
}
memset ( V_11 , 0 , sizeof( struct V_10 ) ) ;
V_11 -> V_66 = F_22 ( V_67 ) ;
V_11 -> V_20 = V_64 ;
V_11 -> V_68 = 0x00 ;
V_11 -> V_70 [ 0 ] = 0xF0 ;
V_11 -> V_70 [ 1 ] = 0x04 ;
V_11 -> V_70 [ 5 ] = ( unsigned char ) ( V_61 ) ;
V_11 -> V_70 [ 4 ] = ( unsigned char ) ( V_61 >> 8 ) ;
V_11 -> V_70 [ 3 ] = ( unsigned char ) ( V_61 >> 16 ) ;
V_11 -> V_70 [ 2 ] = ( unsigned char ) ( V_61 >> 24 ) ;
V_15 = F_3 ( V_6 , V_71 , F_23 ( V_28 ) , 1 ) ;
} else {
void * V_8 ;
int V_48 = 0 ;
T_3 V_102 ;
T_1 V_103 ;
T_3 V_176 , V_174 , V_175 ;
V_8 = F_31 ( V_64 , V_83 ) ;
if ( V_8 == NULL )
return V_24 ;
F_16 ( V_8 , V_64 , V_28 ) ;
V_15 = F_21 ( V_6 , V_107 ) ;
if ( V_15 != V_23 ) {
F_69 ( L_11 ) ;
V_15 = V_24 ;
goto exit;
}
V_102 = ( T_3 ) ( V_61 / V_3 -> V_74 . V_87 ) ;
V_103 = ( T_1 ) ( V_61 % V_3 -> V_74 . V_87 ) ;
while ( 1 ) {
if ( V_62 > ( V_3 -> V_74 . V_87 - V_103 ) )
V_176 = V_3 -> V_74 . V_87 - V_103 ;
else
V_176 = V_62 ;
V_174 = F_58 ( V_3 , V_102 ) ;
V_175 = F_57 ( V_6 , V_102 ) ;
V_15 = F_47 ( V_6 , V_174 , V_175 , V_102 , V_103 , V_8 + V_48 , V_176 ) ;
if ( V_15 != V_23 ) {
F_69 ( L_14 , V_15 ) ;
V_15 = V_24 ;
goto exit;
}
V_3 -> V_74 . V_77 [ V_174 ] = V_101 ;
F_46 ( V_6 , V_102 , V_175 ) ;
V_62 -= V_176 ;
if ( V_62 <= 0 )
break;
V_102 ++ ;
V_103 = 0 ;
V_48 += V_119 * V_176 ;
}
exit:
F_2 ( V_8 ) ;
}
return V_15 ;
}
static int F_71 ( struct V_5 * V_6 , T_3 V_178 , void * V_8 )
{
struct V_10 * V_11 = (struct V_10 * ) V_6 -> V_12 ;
int V_15 ;
memset ( V_11 , 0 , sizeof( struct V_10 ) ) ;
V_11 -> V_66 = F_22 ( V_67 ) ;
V_11 -> V_20 = 0x01 ;
V_11 -> V_68 = V_69 ;
V_11 -> V_70 [ 0 ] = 0xED ;
V_11 -> V_70 [ 2 ] = ( unsigned char ) ( V_178 >> 8 ) ;
V_11 -> V_70 [ 3 ] = ( unsigned char ) V_178 ;
V_15 = F_3 ( V_6 , V_26 , V_8 , 0 ) ;
return V_15 ;
}
static int F_72 ( struct V_5 * V_6 , T_1 * V_8 )
{
T_3 V_209 ;
T_2 V_210 ;
struct V_2 * V_3 = (struct V_2 * ) V_6 -> V_1 ;
V_210 = * ( T_2 * ) & V_8 [ 0x18 ] ;
V_3 -> V_54 = ( T_1 ) ( ( V_210 >> 8 ) & 0x0f ) ;
V_209 = ( T_3 ) V_210 ;
V_210 = * ( T_2 * ) ( & V_8 [ 0x14 ] ) ;
if ( V_3 -> V_39 . V_51 && ! V_3 -> V_39 . V_52 )
V_3 -> V_53 = ( V_210 >> 8 ) & 0x3fffff ;
V_3 -> V_56 = ( ( V_209 & 0x03 ) << 10 ) | ( T_3 ) ( V_210 >> 22 ) ;
V_3 -> V_57 = ( T_1 ) ( V_210 >> 7 ) & 0x07 ;
if ( V_3 -> V_39 . V_51 && V_3 -> V_39 . V_52 )
V_3 -> V_53 = * ( T_2 * ) ( & V_8 [ 0x100 ] ) ;
if ( V_3 -> V_54 > V_211 ) {
V_3 -> V_55 = 1 << ( V_3 -> V_54 - V_211 ) ;
V_3 -> V_54 = V_211 ;
} else {
V_3 -> V_55 = 1 ;
}
return V_37 ;
}
static int F_21 ( struct V_5 * V_6 , unsigned char V_212 )
{
int V_213 ;
char * V_214 = NULL ;
unsigned char * V_8 = NULL ;
const struct V_215 * V_216 = NULL ;
int V_15 = V_24 ;
struct V_10 * V_11 = (struct V_10 * ) V_6 -> V_12 ;
struct V_2 * V_3 = (struct V_2 * ) V_6 -> V_1 ;
if ( V_3 -> V_217 == V_212 )
return V_37 ;
switch ( V_212 ) {
case V_218 :
F_5 ( V_6 , L_15 ) ;
V_214 = V_219 ;
break;
case V_220 :
F_5 ( V_6 , L_16 ) ;
V_214 = V_221 ;
break;
case V_65 :
F_5 ( V_6 , L_17 ) ;
V_214 = V_222 ;
break;
case V_223 :
F_5 ( V_6 , L_18 ) ;
V_214 = V_224 ;
break;
case V_207 :
F_5 ( V_6 , L_19 ) ;
V_214 = V_225 ;
break;
case V_107 :
F_5 ( V_6 , L_20 ) ;
V_214 = V_226 ;
break;
default:
F_5 ( V_6 , L_21 ) ;
goto V_227;
}
V_213 = F_73 ( & V_216 , V_214 , & V_6 -> V_228 -> V_229 ) ;
if ( V_213 ) {
F_5 ( V_6 , L_22 , V_214 ) ;
goto V_227;
}
V_8 = F_74 ( V_216 -> V_230 , V_216 -> V_231 , V_83 ) ;
if ( V_8 == NULL )
goto V_227;
memset ( V_11 , 0 , sizeof( struct V_10 ) ) ;
V_11 -> V_66 = F_22 ( V_67 ) ;
V_11 -> V_20 = V_216 -> V_231 ;
V_11 -> V_68 = 0x00 ;
V_11 -> V_70 [ 0 ] = 0xEF ;
V_15 = F_3 ( V_6 , V_71 , V_8 , 0 ) ;
V_3 -> V_217 = V_212 ;
F_2 ( V_8 ) ;
V_227:
F_75 ( V_216 ) ;
return V_15 ;
}
static int F_76 ( struct V_5 * V_6 )
{
T_2 V_15 ;
T_3 V_232 ;
unsigned char * V_233 = NULL , * V_234 = NULL ;
struct V_105 V_179 ;
T_3 V_200 , V_235 ;
T_2 V_236 ;
struct V_2 * V_3 = (struct V_2 * ) V_6 -> V_1 ;
F_77 ( V_237 L_23 ) ;
F_44 ( V_6 ) ;
V_233 = F_31 ( V_119 , V_83 ) ;
V_234 = F_31 ( V_119 , V_83 ) ;
if ( ( V_233 == NULL ) || ( V_234 == NULL ) ) {
V_15 = V_180 ;
goto exit;
}
V_200 = V_235 = V_84 ;
V_236 = 0 ;
for ( V_232 = 0 ; V_232 < V_238 + 2 ; V_232 ++ ) {
switch ( F_35 ( V_6 , V_232 , 0 , ( T_2 * ) V_233 , & V_179 ) ) {
case V_161 :
break;
case V_186 :
break;
case V_164 :
default:
continue;
}
if ( ( V_179 . V_92 & V_183 ) == V_239 )
continue;
if ( ( ( V_179 . V_94 & V_240 ) == V_241 ) ||
( F_38 ( ( (struct V_120 * ) V_233 ) -> V_242 . V_243 ) != V_244 ) ||
( F_38 ( ( (struct V_120 * ) V_233 ) -> V_242 . V_245 ) != V_246 ) ||
( ( (struct V_120 * ) V_233 ) -> V_242 . V_247 != V_248 ) )
continue;
if ( V_200 != V_84 ) {
V_235 = V_232 ;
break;
}
V_200 = V_232 ;
memcpy ( V_234 , V_233 , V_119 ) ;
if ( V_179 . V_90 & ( V_249 | V_250 | V_251 ) )
V_236 = 1 ;
}
if ( V_200 == V_84 ) {
V_15 = V_164 ;
goto exit;
}
if ( ( V_179 . V_110 & V_252 ) == V_253 )
F_39 ( V_3 , V_254 ) ;
V_15 = V_164 ;
if ( V_236 == 0 )
V_15 = F_37 ( V_6 , V_200 , V_234 ) ;
if ( V_15 && ( V_235 != V_84 ) )
V_15 = F_37 ( V_6 , V_235 , V_233 ) ;
if ( V_15 ) {
V_15 = V_164 ;
goto exit;
}
for ( V_232 = 0 ; V_232 < V_200 ; V_232 ++ )
V_3 -> V_74 . V_77 [ V_232 ] = V_80 ;
V_3 -> V_74 . V_77 [ V_200 ] = V_81 ;
if ( V_235 != V_84 ) {
for ( V_232 = V_200 + 1 ; V_232 < V_235 ; V_232 ++ )
V_3 -> V_74 . V_77 [ V_232 ] = V_80 ;
V_3 -> V_74 . V_77 [ V_235 ] = V_81 ;
}
V_15 = F_66 ( V_6 , V_200 ) ;
if ( V_15 )
goto exit;
for ( V_232 = V_100 ;
V_232 < V_3 -> V_74 . V_76 ;
V_232 += V_100 ) {
if ( F_34 ( V_6 , V_232 ) == 0 ) {
F_39 ( V_3 , V_254 ) ;
break;
}
}
if ( F_45 ( V_6 ) ) {
V_15 = V_180 ;
goto exit;
}
V_15 = V_161 ;
exit:
F_2 ( V_234 ) ;
F_2 ( V_233 ) ;
F_77 ( V_237 L_24 ) ;
return V_15 ;
}
static int F_60 ( struct V_5 * V_6 )
{
struct V_10 * V_11 = (struct V_10 * ) V_6 -> V_12 ;
int V_15 ;
T_3 V_255 , V_256 ;
struct V_2 * V_3 = (struct V_2 * ) V_6 -> V_1 ;
T_1 * V_4 = V_3 -> V_4 ;
F_77 ( V_237 L_25 ) ;
V_15 = F_21 ( V_6 , V_223 ) ;
if ( V_15 != V_23 ) {
F_77 ( V_257 L_26 ) ;
return V_24 ;
}
memset ( V_11 , 0 , sizeof( struct V_10 ) ) ;
V_11 -> V_66 = F_22 ( V_67 ) ;
V_11 -> V_20 = 0x200 ;
V_11 -> V_68 = V_69 ;
V_11 -> V_70 [ 0 ] = 0xF1 ;
V_11 -> V_70 [ 1 ] = 0x01 ;
V_15 = F_3 ( V_6 , V_26 , V_4 , 0 ) ;
if ( V_15 != V_23 ) {
F_77 ( V_257 L_27 ) ;
return V_24 ;
}
V_3 -> V_194 = * (struct V_258 * ) V_4 ;
if ( V_3 -> V_194 . V_40 && V_3 -> V_194 . V_41 ) {
F_77 ( V_237 L_28 , V_3 -> V_194 . V_40 ) ;
F_77 ( V_237 L_29 , V_3 -> V_194 . V_41 ) ;
F_77 ( V_237 L_30 , V_3 -> V_194 . V_195 ) ;
F_77 ( V_237 L_31 , V_3 -> V_194 . V_259 ) ;
F_77 ( V_237 L_32 , V_3 -> V_194 . V_45 ) ;
if ( V_3 -> V_194 . V_195 ) {
V_255 = ( V_4 [ 6 ] << 8 ) | V_4 [ 7 ] ;
V_256 = ( V_4 [ 10 ] << 8 ) | V_4 [ 11 ] ;
V_3 -> V_196 = V_255 * V_256 ;
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
static int F_14 ( struct V_5 * V_6 )
{
int V_15 ;
struct V_10 * V_11 = (struct V_10 * ) V_6 -> V_12 ;
struct V_2 * V_3 = (struct V_2 * ) V_6 -> V_1 ;
T_1 * V_4 = V_3 -> V_4 ;
F_5 ( V_6 , L_35 ) ;
V_15 = F_21 ( V_6 , V_218 ) ;
if ( V_15 != V_23 ) {
F_5 ( V_6 , L_36 ) ;
return V_24 ;
}
memset ( V_11 , 0 , sizeof( struct V_10 ) ) ;
V_11 -> V_66 = F_22 ( V_67 ) ;
V_11 -> V_68 = V_69 ;
V_11 -> V_70 [ 0 ] = 0xF2 ;
V_15 = F_3 ( V_6 , V_26 , NULL , 0 ) ;
if ( V_15 != V_23 ) {
F_5 ( V_6 , L_37 ) ;
return V_24 ;
}
V_15 = F_21 ( V_6 , V_220 ) ;
if ( V_15 != V_23 ) {
F_5 ( V_6 , L_38 ) ;
return V_24 ;
}
memset ( V_11 , 0 , sizeof( struct V_10 ) ) ;
V_11 -> V_66 = F_22 ( V_67 ) ;
V_11 -> V_20 = 0x200 ;
V_11 -> V_68 = V_69 ;
V_11 -> V_70 [ 0 ] = 0xF1 ;
V_15 = F_3 ( V_6 , V_26 , V_4 , 0 ) ;
if ( V_15 != V_23 ) {
F_5 ( V_6 , L_37 ) ;
return V_24 ;
}
V_3 -> V_39 = * (struct V_260 * ) V_4 ;
if ( V_3 -> V_39 . V_40 && V_3 -> V_39 . V_41 ) {
struct V_260 * V_261 = & V_3 -> V_39 ;
F_72 ( V_6 , V_4 ) ;
F_5 ( V_6 , L_28 , V_261 -> V_40 ) ;
F_5 ( V_6 , L_29 , V_261 -> V_41 ) ;
F_5 ( V_6 , L_39 , V_261 -> V_52 ) ;
F_5 ( V_6 , L_40 , V_261 -> V_51 ) ;
F_5 ( V_6 , L_41 , V_261 -> V_262 ) ;
F_5 ( V_6 , L_42 , V_261 -> V_45 ) ;
} else {
F_5 ( V_6 , L_43 , V_4 [ 0 ] ) ;
return V_24 ;
}
return V_37 ;
}
static int F_78 ( struct V_5 * V_6 )
{
int V_15 ;
T_1 V_263 ;
struct V_2 * V_3 = (struct V_2 * ) ( V_6 -> V_1 ) ;
T_1 * V_4 = V_3 -> V_4 ;
V_15 = F_71 ( V_6 , V_264 , V_4 ) ;
if ( V_15 != V_23 )
return V_24 ;
V_263 = V_4 [ 0 ] ;
if ( V_263 & 0x01 ) {
if ( ! V_3 -> V_39 . V_41 ) {
V_15 = F_14 ( V_6 ) ;
if ( V_15 != V_23 )
return V_24 ;
}
}
if ( V_263 & 0x02 ) {
if ( ! V_3 -> V_194 . V_41 ) {
V_15 = F_60 ( V_6 ) ;
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
V_3 -> V_265 = V_266 ;
switch ( V_28 -> V_60 [ 0 ] ) {
case V_267 :
V_15 = F_13 ( V_6 , V_28 ) ;
break;
case V_268 :
V_15 = F_15 ( V_6 , V_28 ) ;
break;
case V_269 :
V_15 = F_17 ( V_6 , V_28 ) ;
break;
case V_270 :
V_15 = F_18 ( V_6 , V_28 ) ;
break;
case V_271 :
V_15 = F_20 ( V_6 , V_28 ) ;
break;
case V_272 :
V_15 = F_24 ( V_6 , V_28 ) ;
break;
default:
V_3 -> V_265 = V_273 ;
V_15 = V_274 ;
break;
}
return V_15 ;
}
static int F_80 ( struct V_5 * V_6 , struct V_38 * V_28 )
{
int V_15 ;
struct V_2 * V_3 = (struct V_2 * ) V_6 -> V_1 ;
V_3 -> V_265 = V_266 ;
switch ( V_28 -> V_60 [ 0 ] ) {
case V_267 :
V_15 = F_59 ( V_6 , V_28 ) ;
break;
case V_268 :
V_15 = F_61 ( V_6 , V_28 ) ;
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
V_3 -> V_265 = V_273 ;
V_15 = V_274 ;
break;
}
return V_15 ;
}
static int F_81 ( struct V_38 * V_28 , struct V_5 * V_6 )
{
int V_15 = 0 ;
struct V_2 * V_3 = (struct V_2 * ) ( V_6 -> V_1 ) ;
F_10 ( V_28 , 0 ) ;
if ( F_82 ( ! ( V_3 -> V_39 . V_41 || V_3 -> V_194 . V_41 ) ) ) {
V_15 = F_78 ( V_6 ) ;
} else {
if ( V_3 -> V_39 . V_41 )
V_15 = F_79 ( V_6 , V_28 ) ;
if ( V_3 -> V_194 . V_41 )
V_15 = F_80 ( V_6 , V_28 ) ;
}
return 0 ;
}
static int F_83 ( struct V_275 * V_276 ,
const struct V_277 * V_278 )
{
int V_15 ;
T_1 V_263 ;
struct V_5 * V_6 ;
struct V_2 * V_3 ;
V_15 = F_84 ( & V_6 , V_276 , V_278 ,
( V_278 - V_279 ) + V_280 ,
& V_281 ) ;
if ( V_15 )
return V_15 ;
V_6 -> V_1 = F_85 ( sizeof( struct V_2 ) , V_83 ) ;
if ( ! V_6 -> V_1 )
return - V_282 ;
V_6 -> V_283 = F_1 ;
V_3 = (struct V_2 * ) ( V_6 -> V_1 ) ;
V_3 -> V_4 = F_31 ( 512 , V_83 ) ;
if ( ! V_3 -> V_4 ) {
F_2 ( V_6 -> V_1 ) ;
return - V_282 ;
}
V_6 -> V_284 = L_44 ;
V_6 -> V_285 = F_81 ;
V_6 -> V_286 = 0 ;
V_15 = F_86 ( V_6 ) ;
if ( V_15 )
return V_15 ;
V_15 = F_71 ( V_6 , V_264 , V_3 -> V_4 ) ;
if ( V_15 != V_23 ) {
F_87 ( V_276 ) ;
return V_24 ;
}
V_263 = V_3 -> V_4 [ 0 ] ;
if ( ! ( V_263 & 0x01 ) ) {
F_69 ( L_45
L_46 ) ;
}
return V_15 ;
}
static int F_88 ( struct V_275 * V_287 )
{
T_1 V_288 = 0 ;
struct V_5 * V_6 = F_89 ( V_287 ) ;
struct V_2 * V_3 = (struct V_2 * ) ( V_6 -> V_1 ) ;
F_90 ( & V_6 -> V_289 ) ;
if ( V_6 -> V_290 )
( V_6 -> V_290 ) ( V_6 , V_291 ) ;
F_91 ( & V_6 -> V_289 ) ;
V_3 -> V_292 = true ;
V_3 -> V_39 = * (struct V_260 * ) & V_288 ;
V_3 -> V_194 = * (struct V_258 * ) & V_288 ;
V_3 -> V_293 = * (struct V_294 * ) & V_288 ;
return 0 ;
}
static int F_92 ( struct V_275 * V_287 )
{
T_1 V_288 = 0 ;
struct V_5 * V_6 = F_89 ( V_287 ) ;
struct V_2 * V_3 = (struct V_2 * ) ( V_6 -> V_1 ) ;
F_93 ( V_287 ) ;
V_3 -> V_292 = true ;
V_3 -> V_39 = * (struct V_260 * ) & V_288 ;
V_3 -> V_194 = * (struct V_258 * ) & V_288 ;
V_3 -> V_293 = * (struct V_294 * ) & V_288 ;
return 0 ;
}
