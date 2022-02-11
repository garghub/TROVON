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
T_2 V_46 ;
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
V_8 -> V_67 = V_68 ;
V_8 -> V_69 [ 0 ] = 0xF1 ;
V_8 -> V_69 [ 5 ] = ( unsigned char ) ( V_62 ) ;
V_8 -> V_69 [ 4 ] = ( unsigned char ) ( V_62 >> 8 ) ;
V_8 -> V_69 [ 3 ] = ( unsigned char ) ( V_62 >> 16 ) ;
V_8 -> V_69 [ 2 ] = ( unsigned char ) ( V_62 >> 24 ) ;
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
V_8 -> V_69 [ 0 ] = 0xF0 ;
V_8 -> V_69 [ 5 ] = ( unsigned char ) ( V_62 ) ;
V_8 -> V_69 [ 4 ] = ( unsigned char ) ( V_62 >> 8 ) ;
V_8 -> V_69 [ 3 ] = ( unsigned char ) ( V_62 >> 16 ) ;
V_8 -> V_69 [ 2 ] = ( unsigned char ) ( V_62 >> 24 ) ;
V_12 = F_2 ( V_3 , V_70 , F_22 ( V_25 ) , 1 ) ;
return V_12 ;
}
static int F_24 ( struct V_2 * V_3 , T_3 V_71 , T_3 V_72 )
{
struct V_36 * V_37 = (struct V_36 * ) V_3 -> V_1 ;
if ( ( V_71 >= V_37 -> V_73 . V_74 ) || ( V_72 >= V_37 -> V_73 . V_75 ) )
return ( T_2 ) - 1 ;
V_37 -> V_73 . V_76 [ V_72 ] = V_71 ;
V_37 -> V_73 . V_77 [ V_71 ] = V_72 ;
return 0 ;
}
static int F_25 ( struct V_2 * V_3 , T_3 V_72 , T_3 V_78 )
{
struct V_36 * V_37 = (struct V_36 * ) V_3 -> V_1 ;
if ( V_72 >= V_37 -> V_73 . V_75 )
return ( T_2 ) - 1 ;
V_37 -> V_73 . V_76 [ V_72 ] = V_78 ;
return 0 ;
}
static int F_26 ( struct V_2 * V_3 , T_3 V_72 )
{
return F_25 ( V_3 , V_72 , V_79 ) ;
}
static int F_27 ( struct V_2 * V_3 , T_3 V_72 )
{
return F_25 ( V_3 , V_72 , V_80 ) ;
}
static int F_28 ( struct V_2 * V_3 )
{
struct V_36 * V_37 = (struct V_36 * ) V_3 -> V_1 ;
F_29 ( V_37 -> V_73 . V_76 ) ;
V_37 -> V_73 . V_76 = NULL ;
F_29 ( V_37 -> V_73 . V_77 ) ;
V_37 -> V_73 . V_77 = NULL ;
return 0 ;
}
static int F_30 ( struct V_2 * V_3 )
{
T_2 V_81 ;
struct V_36 * V_37 = (struct V_36 * ) V_3 -> V_1 ;
V_37 -> V_73 . V_76 = F_31 ( V_37 -> V_73 . V_75 * sizeof( T_3 ) , V_82 ) ;
V_37 -> V_73 . V_77 = F_31 ( V_37 -> V_73 . V_74 * sizeof( T_3 ) , V_82 ) ;
if ( ( V_37 -> V_73 . V_76 == NULL ) || ( V_37 -> V_73 . V_77 == NULL ) ) {
F_28 ( V_3 ) ;
return ( T_2 ) - 1 ;
}
for ( V_81 = 0 ; V_81 < V_37 -> V_73 . V_75 ; V_81 ++ )
V_37 -> V_73 . V_76 [ V_81 ] = V_83 ;
for ( V_81 = 0 ; V_81 < V_37 -> V_73 . V_74 ; V_81 ++ )
V_37 -> V_73 . V_77 [ V_81 ] = V_83 ;
return 0 ;
}
static void F_32 ( struct V_2 * V_3 )
{
int V_81 ;
struct V_36 * V_37 = (struct V_36 * ) V_3 -> V_1 ;
V_37 -> V_73 . V_84 = ( T_3 ) - 1 ;
F_33 ( V_37 ) ;
if ( V_37 -> V_73 . V_85 )
memset ( V_37 -> V_73 . V_85 , 0xff , V_37 -> V_73 . V_86 * V_37 -> V_73 . V_87 ) ;
if ( V_37 -> V_73 . V_88 ) {
for ( V_81 = 0 ; V_81 < V_37 -> V_73 . V_86 ; V_81 ++ ) {
V_37 -> V_73 . V_88 [ V_81 ] . V_89 = V_90 ;
V_37 -> V_73 . V_88 [ V_81 ] . V_91 = V_92 ;
V_37 -> V_73 . V_88 [ V_81 ] . V_93 = V_94 ;
V_37 -> V_73 . V_88 [ V_81 ] . V_95 = V_83 ;
}
}
}
static int F_34 ( struct V_2 * V_3 , T_3 V_96 )
{
T_2 V_97 , V_98 ;
struct V_36 * V_37 = (struct V_36 * ) V_3 -> V_1 ;
V_97 = V_96 + V_99 ;
for ( V_98 = 0 ; V_96 < V_97 ; V_96 ++ ) {
switch ( V_37 -> V_73 . V_76 [ V_96 ] ) {
case V_83 :
case V_100 :
V_98 ++ ;
default:
break;
}
}
return V_98 ;
}
static int F_35 ( struct V_2 * V_3 , T_2 V_101 ,
T_1 V_102 , T_2 * V_103 , struct V_104 * V_105 )
{
struct V_7 * V_8 = (struct V_7 * ) V_3 -> V_9 ;
int V_12 ;
T_1 V_106 [ 4 ] ;
T_2 V_60 = V_101 * 0x20 + V_102 ;
V_12 = F_20 ( V_3 , V_107 ) ;
if ( V_12 != V_20 )
return V_21 ;
memset ( V_8 , 0 , sizeof( struct V_7 ) ) ;
V_8 -> V_65 = F_21 ( V_66 ) ;
V_8 -> V_17 = 0x200 ;
V_8 -> V_67 = V_68 ;
V_8 -> V_69 [ 0 ] = 0xF1 ;
V_8 -> V_69 [ 1 ] = 0x02 ;
V_8 -> V_69 [ 5 ] = ( unsigned char ) ( V_60 ) ;
V_8 -> V_69 [ 4 ] = ( unsigned char ) ( V_60 >> 8 ) ;
V_8 -> V_69 [ 3 ] = ( unsigned char ) ( V_60 >> 16 ) ;
V_8 -> V_69 [ 2 ] = ( unsigned char ) ( V_60 >> 24 ) ;
V_12 = F_2 ( V_3 , V_23 , V_103 , 0 ) ;
if ( V_12 != V_20 )
return V_21 ;
memset ( V_8 , 0 , sizeof( struct V_7 ) ) ;
V_8 -> V_65 = F_21 ( V_66 ) ;
V_8 -> V_17 = 0x4 ;
V_8 -> V_67 = V_68 ;
V_8 -> V_69 [ 0 ] = 0xF1 ;
V_8 -> V_69 [ 1 ] = 0x03 ;
V_8 -> V_69 [ 5 ] = ( unsigned char ) ( V_102 ) ;
V_8 -> V_69 [ 4 ] = ( unsigned char ) ( V_101 ) ;
V_8 -> V_69 [ 3 ] = ( unsigned char ) ( V_101 >> 8 ) ;
V_8 -> V_69 [ 2 ] = ( unsigned char ) ( V_101 >> 16 ) ;
V_8 -> V_69 [ 6 ] = 0x01 ;
V_12 = F_2 ( V_3 , V_23 , & V_106 , 0 ) ;
if ( V_12 != V_20 )
return V_21 ;
V_105 -> V_108 = 0 ;
V_105 -> V_109 = 0x80 ;
V_105 -> V_110 = 0x10 ;
V_105 -> V_89 = 0x00 ;
V_105 -> V_91 = V_106 [ 0 ] ;
V_105 -> V_93 = V_106 [ 1 ] ;
V_105 -> V_95 = F_36 ( V_106 [ 2 ] , V_106 [ 3 ] ) ;
return V_34 ;
}
static int F_37 ( struct V_2 * V_3 , T_3 V_96 , T_1 * V_111 )
{
struct V_112 * V_113 ;
struct V_114 * V_115 ;
T_2 V_81 , V_12 ;
T_1 V_116 ;
T_1 * V_117 ;
struct V_104 V_118 ;
struct V_36 * V_37 = (struct V_36 * ) V_3 -> V_1 ;
V_117 = F_31 ( V_119 , V_82 ) ;
if ( V_117 == NULL )
return ( T_2 ) - 1 ;
V_12 = ( T_2 ) - 1 ;
V_115 = & ( ( (struct V_120 * ) V_111 ) -> V_121 ) ;
if ( ( V_115 -> V_122 != V_123 ) ||
( F_38 ( V_115 -> V_124 ) != V_125 ) ||
( ( V_115 -> V_126 & V_127 ) == V_128 ) ||
( V_115 -> V_129 != V_130 ) ||
( V_115 -> V_131 != V_132 ) ||
( V_115 -> V_133 != V_134 ) ||
( V_115 -> V_135 != V_136 ) )
goto exit;
switch ( V_37 -> V_73 . V_137 = V_115 -> V_138 ) {
case V_139 :
F_39 ( V_37 , V_140 ) ;
break;
case V_141 :
F_40 ( V_37 , V_140 ) ;
break;
case V_142 :
default:
goto exit;
}
V_37 -> V_73 . V_143 = F_38 ( V_115 -> V_144 ) ;
V_37 -> V_73 . V_75 = F_38 ( V_115 -> V_145 ) ;
V_37 -> V_73 . V_74 = F_38 ( V_115 -> V_146 ) - 2 ;
V_37 -> V_73 . V_86 = V_37 -> V_73 . V_143 * V_147 / V_119 ;
V_37 -> V_73 . V_148 = V_37 -> V_73 . V_75 / V_99 ;
V_37 -> V_149 = F_38 ( V_115 -> V_150 ) ;
if ( F_30 ( V_3 ) )
goto exit;
F_27 ( V_3 , V_96 ) ;
V_113 = & ( ( (struct V_120 * ) V_111 ) -> V_151 ) ;
for ( V_81 = 0 ; V_81 < V_152 ; V_81 ++ ) {
T_2 V_153 , V_154 ;
V_153 = F_41 ( V_113 -> V_155 [ V_81 ] . V_156 ) ;
if ( V_153 == 0xffffff )
continue;
V_154 = F_41 ( V_113 -> V_155 [ V_81 ] . V_157 ) ;
if ( V_154 == 0 )
continue;
if ( V_153 + V_119 + V_154 > V_37 -> V_73 . V_143 * ( T_2 ) V_147 )
continue;
if ( V_81 == 0 ) {
T_1 V_158 = 0 ;
T_3 V_72 ;
if ( V_113 -> V_155 [ V_81 ] . V_159 != V_160 )
goto exit;
while ( V_154 > 0 ) {
V_116 = ( T_1 ) ( V_153 / V_119 + 1 ) ;
if ( V_116 != V_158 ) {
switch ( F_35 ( V_3 , V_96 , V_116 , ( T_2 * ) V_117 , & V_118 ) ) {
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
V_72 = F_38 ( * ( T_3 * ) ( V_117 + ( V_153 % V_119 ) ) ) ;
if ( V_72 < 0x0fff )
F_26 ( V_3 , V_72 ) ;
V_153 += 2 ;
V_154 -= 2 ;
}
} else if ( V_81 == 1 ) {
struct V_165 * V_166 ;
if ( V_113 -> V_155 [ V_81 ] . V_159 != V_167 )
goto exit;
switch ( F_35 ( V_3 , V_96 , ( T_1 ) ( V_153 / V_119 + 1 ) , ( T_2 * ) V_117 , & V_118 ) ) {
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
V_37 -> V_73 . V_87 = F_42 ( V_166 -> V_171 ) ;
if ( V_37 -> V_73 . V_87 != V_119 )
goto exit;
}
}
V_12 = 0 ;
exit:
if ( V_12 )
F_28 ( V_3 ) ;
F_29 ( V_117 ) ;
V_12 = 0 ;
return V_12 ;
}
static void F_43 ( struct V_2 * V_3 )
{
struct V_36 * V_37 = (struct V_36 * ) V_3 -> V_1 ;
V_37 -> V_73 . V_84 = ( T_3 ) - 1 ;
F_33 ( V_37 ) ;
if ( V_37 -> V_73 . V_85 ) {
F_29 ( ( T_1 * ) ( V_37 -> V_73 . V_85 ) ) ;
V_37 -> V_73 . V_85 = NULL ;
}
if ( V_37 -> V_73 . V_88 ) {
F_29 ( ( T_1 * ) ( V_37 -> V_73 . V_88 ) ) ;
V_37 -> V_73 . V_88 = NULL ;
}
}
static void F_44 ( struct V_2 * V_3 )
{
struct V_36 * V_37 = (struct V_36 * ) V_3 -> V_1 ;
F_43 ( V_3 ) ;
F_28 ( V_3 ) ;
V_37 -> V_73 . V_172 = 0 ;
V_37 -> V_73 . V_87 = 0 ;
V_37 -> V_73 . V_173 = 0 ;
V_37 -> V_73 . V_137 = 0 ;
V_37 -> V_73 . V_143 = 0 ;
V_37 -> V_73 . V_86 = 0 ;
V_37 -> V_73 . V_75 = 0 ;
V_37 -> V_73 . V_74 = 0 ;
}
static int F_45 ( struct V_2 * V_3 )
{
struct V_36 * V_37 = (struct V_36 * ) V_3 -> V_1 ;
V_37 -> V_73 . V_84 = ( T_3 ) - 1 ;
V_37 -> V_73 . V_85 = F_31 ( V_37 -> V_73 . V_86 * V_37 -> V_73 . V_87 , V_82 ) ;
V_37 -> V_73 . V_88 = F_31 ( V_37 -> V_73 . V_86 * sizeof( struct V_104 ) , V_82 ) ;
if ( ( V_37 -> V_73 . V_85 == NULL ) || ( V_37 -> V_73 . V_88 == NULL ) ) {
F_43 ( V_3 ) ;
return ( T_2 ) - 1 ;
}
F_32 ( V_3 ) ;
return 0 ;
}
static int F_46 ( struct V_2 * V_3 , T_3 V_71 , T_3 V_72 )
{
struct V_36 * V_37 = (struct V_36 * ) V_3 -> V_1 ;
if ( V_71 == V_83 )
return 0 ;
if ( ( V_71 >= V_37 -> V_73 . V_74 ) ||
( V_72 >= V_37 -> V_73 . V_75 ) )
return ( T_2 ) - 1 ;
V_37 -> V_73 . V_76 [ V_72 ] = V_71 ;
V_37 -> V_73 . V_77 [ V_71 ] = V_72 ;
return 0 ;
}
static int F_47 ( struct V_2 * V_3 , T_3 V_174 , T_3 V_175 ,
T_3 V_101 , T_1 V_102 , unsigned char * V_5 , T_3 V_176 )
{
struct V_7 * V_8 = (struct V_7 * ) V_3 -> V_9 ;
int V_12 ;
V_12 = F_20 ( V_3 , V_107 ) ;
if ( V_12 != V_20 )
return V_21 ;
memset ( V_8 , 0 , sizeof( struct V_7 ) ) ;
V_8 -> V_65 = F_21 ( V_66 ) ;
V_8 -> V_17 = 0x200 * V_176 ;
V_8 -> V_67 = 0x00 ;
V_8 -> V_69 [ 0 ] = 0xF0 ;
V_8 -> V_69 [ 1 ] = 0x08 ;
V_8 -> V_69 [ 4 ] = ( unsigned char ) ( V_174 ) ;
V_8 -> V_69 [ 3 ] = ( unsigned char ) ( V_174 >> 8 ) ;
V_8 -> V_69 [ 2 ] = 0 ;
V_8 -> V_69 [ 7 ] = ( unsigned char ) ( V_175 ) ;
V_8 -> V_69 [ 6 ] = ( unsigned char ) ( V_175 >> 8 ) ;
V_8 -> V_69 [ 5 ] = 0 ;
V_8 -> V_69 [ 9 ] = ( unsigned char ) ( V_101 ) ;
V_8 -> V_69 [ 8 ] = ( unsigned char ) ( V_101 >> 8 ) ;
V_8 -> V_69 [ 10 ] = V_102 ;
V_12 = F_2 ( V_3 , V_70 , V_5 , 0 ) ;
if ( V_12 != V_20 )
return V_21 ;
return V_34 ;
}
static int F_48 ( struct V_2 * V_3 , T_2 V_101 )
{
struct V_7 * V_8 = (struct V_7 * ) V_3 -> V_9 ;
int V_12 ;
T_2 V_60 = V_101 ;
V_12 = F_20 ( V_3 , V_107 ) ;
if ( V_12 != V_20 )
return V_21 ;
memset ( V_8 , 0 , sizeof( struct V_7 ) ) ;
V_8 -> V_65 = F_21 ( V_66 ) ;
V_8 -> V_17 = 0x200 ;
V_8 -> V_67 = V_68 ;
V_8 -> V_69 [ 0 ] = 0xF2 ;
V_8 -> V_69 [ 1 ] = 0x06 ;
V_8 -> V_69 [ 4 ] = ( unsigned char ) ( V_60 ) ;
V_8 -> V_69 [ 3 ] = ( unsigned char ) ( V_60 >> 8 ) ;
V_8 -> V_69 [ 2 ] = ( unsigned char ) ( V_60 >> 16 ) ;
V_12 = F_2 ( V_3 , V_23 , NULL , 0 ) ;
if ( V_12 != V_20 )
return V_21 ;
return V_34 ;
}
static int F_49 ( struct V_2 * V_3 , T_3 V_96 )
{
unsigned char * V_103 = NULL ;
T_3 V_12 = V_161 ;
T_3 V_177 , V_178 = 0 ;
struct V_104 V_179 ;
struct V_36 * V_37 = (struct V_36 * ) V_3 -> V_1 ;
V_103 = F_31 ( V_119 , V_82 ) ;
if ( V_103 == NULL ) {
V_12 = V_180 ;
goto exit;
}
F_35 ( V_3 , V_96 , 1 , ( T_2 * ) V_103 , & V_179 ) ;
do {
V_177 = F_38 ( V_103 [ V_178 ] ) ;
if ( V_177 == V_83 )
break;
if ( V_177 == V_37 -> V_73 . V_77 [ 0 ] ) {
V_12 = V_163 ;
break;
}
V_178 ++ ;
} while ( 1 );
exit:
F_29 ( V_103 ) ;
return V_12 ;
}
static int F_50 ( struct V_2 * V_3 , T_3 V_72 )
{
T_3 log ;
struct V_36 * V_37 = (struct V_36 * ) V_3 -> V_1 ;
if ( V_72 >= V_37 -> V_73 . V_75 )
return ( T_2 ) - 1 ;
log = V_37 -> V_73 . V_76 [ V_72 ] ;
if ( log < V_37 -> V_73 . V_74 )
V_37 -> V_73 . V_77 [ log ] = V_83 ;
if ( V_37 -> V_73 . V_76 [ V_72 ] != V_79 )
V_37 -> V_73 . V_76 [ V_72 ] = V_181 ;
return 0 ;
}
static int F_51 ( struct V_2 * V_3 , T_2 V_101 ,
T_1 V_102 , T_1 V_182 )
{
struct V_7 * V_8 = (struct V_7 * ) V_3 -> V_9 ;
int V_12 ;
V_12 = F_20 ( V_3 , V_107 ) ;
if ( V_12 != V_20 )
return V_21 ;
memset ( V_8 , 0 , sizeof( struct V_7 ) ) ;
V_8 -> V_65 = F_21 ( V_66 ) ;
V_8 -> V_17 = 0x4 ;
V_8 -> V_67 = V_68 ;
V_8 -> V_69 [ 0 ] = 0xF2 ;
V_8 -> V_69 [ 1 ] = 0x05 ;
V_8 -> V_69 [ 5 ] = ( unsigned char ) ( V_102 ) ;
V_8 -> V_69 [ 4 ] = ( unsigned char ) ( V_101 ) ;
V_8 -> V_69 [ 3 ] = ( unsigned char ) ( V_101 >> 8 ) ;
V_8 -> V_69 [ 2 ] = ( unsigned char ) ( V_101 >> 16 ) ;
V_8 -> V_69 [ 6 ] = V_182 ;
V_8 -> V_69 [ 7 ] = 0xFF ;
V_8 -> V_69 [ 8 ] = 0xFF ;
V_8 -> V_69 [ 9 ] = 0xFF ;
V_12 = F_2 ( V_3 , V_23 , NULL , 0 ) ;
if ( V_12 != V_20 )
return V_21 ;
return V_34 ;
}
static int F_52 ( struct V_2 * V_3 , T_3 V_72 )
{
struct V_36 * V_37 = (struct V_36 * ) V_3 -> V_1 ;
if ( V_72 >= V_37 -> V_73 . V_75 )
return V_164 ;
F_50 ( V_3 , V_72 ) ;
if ( F_53 ( V_37 ) )
return F_51 ( V_3 , V_72 , 0 , ( T_1 ) ( ~ V_183 & V_184 ) ) ;
return V_161 ;
}
static int F_54 ( struct V_2 * V_3 , T_3 V_72 )
{
T_3 log ;
struct V_36 * V_37 = (struct V_36 * ) V_3 -> V_1 ;
if ( V_72 >= V_37 -> V_73 . V_75 )
return V_164 ;
log = V_37 -> V_73 . V_76 [ V_72 ] ;
if ( log < V_37 -> V_73 . V_74 )
V_37 -> V_73 . V_77 [ log ] = V_83 ;
V_37 -> V_73 . V_76 [ V_72 ] = V_83 ;
if ( F_53 ( V_37 ) ) {
switch ( F_48 ( V_3 , V_72 ) ) {
case V_161 :
V_37 -> V_73 . V_76 [ V_72 ] = V_100 ;
return V_161 ;
case V_185 :
case V_186 :
F_52 ( V_3 , V_72 ) ;
return V_185 ;
case V_164 :
default:
F_39 ( V_37 , V_140 ) ;
F_50 ( V_3 , V_72 ) ;
return V_164 ;
}
}
F_50 ( V_3 , V_72 ) ;
return V_161 ;
}
static int F_55 ( struct V_2 * V_3 , T_2 V_96 ,
T_1 V_102 , struct V_104 * V_105 )
{
struct V_7 * V_8 = (struct V_7 * ) V_3 -> V_9 ;
int V_12 ;
T_1 V_106 [ 4 ] ;
memset ( V_8 , 0 , sizeof( struct V_7 ) ) ;
V_8 -> V_65 = F_21 ( V_66 ) ;
V_8 -> V_17 = 0x4 ;
V_8 -> V_67 = V_68 ;
V_8 -> V_69 [ 0 ] = 0xF1 ;
V_8 -> V_69 [ 1 ] = 0x03 ;
V_8 -> V_69 [ 5 ] = ( unsigned char ) ( V_102 ) ;
V_8 -> V_69 [ 4 ] = ( unsigned char ) ( V_96 ) ;
V_8 -> V_69 [ 3 ] = ( unsigned char ) ( V_96 >> 8 ) ;
V_8 -> V_69 [ 2 ] = ( unsigned char ) ( V_96 >> 16 ) ;
V_8 -> V_69 [ 6 ] = 0x01 ;
V_12 = F_2 ( V_3 , V_23 , & V_106 , 0 ) ;
if ( V_12 != V_20 )
return V_21 ;
V_105 -> V_108 = 0 ;
V_105 -> V_109 = 0x80 ;
V_105 -> V_110 = 0x10 ;
V_105 -> V_89 = 0x00 ;
V_105 -> V_91 = V_106 [ 0 ] ;
V_105 -> V_93 = V_106 [ 1 ] ;
V_105 -> V_95 = F_36 ( V_106 [ 2 ] , V_106 [ 3 ] ) ;
return V_34 ;
}
static int F_56 ( struct V_2 * V_3 , T_3 V_72 )
{
T_3 V_187 ;
T_3 V_177 ;
struct V_104 V_179 ;
struct V_36 * V_37 = (struct V_36 * ) V_3 -> V_1 ;
if ( V_72 >= V_37 -> V_73 . V_75 )
return V_188 ;
for ( V_177 = V_72 + 1 ; V_177 != V_72 ; V_177 ++ ) {
if ( ( V_177 & V_189 ) == 0 )
V_177 -= V_99 ;
V_187 = V_37 -> V_73 . V_76 [ V_177 ] ;
if ( V_37 -> V_73 . V_76 [ V_177 ] == V_100 ) {
return V_177 ;
} else if ( V_37 -> V_73 . V_76 [ V_177 ] == V_83 ) {
switch ( F_55 ( V_3 , V_177 , 0 , & V_179 ) ) {
case V_161 :
case V_190 :
break;
case V_191 :
return V_191 ;
case V_186 :
return V_188 ;
case V_163 :
default:
F_50 ( V_3 , V_177 ) ;
continue;
}
if ( ( V_179 . V_91 & V_183 ) != V_192 ) {
F_50 ( V_3 , V_177 ) ;
continue;
}
switch ( F_54 ( V_3 , V_177 ) ) {
case V_161 :
return V_177 ;
case V_164 :
return V_188 ;
case V_185 :
default:
F_52 ( V_3 , V_177 ) ;
break;
}
}
}
return V_188 ;
}
static int F_57 ( struct V_2 * V_3 , T_3 V_71 )
{
T_3 V_72 ;
struct V_36 * V_37 = (struct V_36 * ) V_3 -> V_1 ;
V_72 = F_58 ( V_37 , V_71 ) ;
if ( V_72 >= V_188 ) {
if ( V_71 >= V_37 -> V_73 . V_74 )
return V_188 ;
V_72 = ( V_71 + V_193 ) / V_194 ;
V_72 *= V_99 ;
V_72 += V_99 - 1 ;
}
return F_56 ( V_3 , V_72 ) ;
}
static int F_59 ( struct V_2 * V_3 , struct V_35 * V_25 )
{
struct V_36 * V_37 = (struct V_36 * ) ( V_3 -> V_1 ) ;
if ( V_37 -> V_195 . V_39 && V_37 -> V_195 . V_40 ) {
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
if ( V_37 -> V_195 . V_44 )
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
if ( V_37 -> V_195 . V_196 )
V_45 = V_37 -> V_197 - 1 ;
else
V_45 = V_37 -> V_73 . V_74 * V_37 -> V_73 . V_143 * 2 - 1 ;
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
static void F_64 ( T_3 V_96 , T_3 * V_198 , T_3 * V_199 )
{
V_96 /= V_99 ;
if ( V_96 ) {
* V_198 = V_200 + ( V_96 - 1 ) * V_194 ;
* V_199 = * V_198 + V_194 ;
} else {
* V_198 = 0 ;
* V_199 = V_200 ;
}
}
static int F_65 ( struct V_2 * V_3 , T_2 V_96 ,
T_1 V_102 , T_1 V_61 , void * V_5 )
{
struct V_7 * V_8 = (struct V_7 * ) V_3 -> V_9 ;
int V_12 ;
memset ( V_8 , 0 , sizeof( struct V_7 ) ) ;
V_8 -> V_65 = F_21 ( V_66 ) ;
V_8 -> V_17 = 0x4 * V_61 ;
V_8 -> V_67 = V_68 ;
V_8 -> V_69 [ 0 ] = 0xF1 ;
V_8 -> V_69 [ 1 ] = 0x03 ;
V_8 -> V_69 [ 5 ] = ( unsigned char ) ( V_102 ) ;
V_8 -> V_69 [ 4 ] = ( unsigned char ) ( V_96 ) ;
V_8 -> V_69 [ 3 ] = ( unsigned char ) ( V_96 >> 8 ) ;
V_8 -> V_69 [ 2 ] = ( unsigned char ) ( V_96 >> 16 ) ;
V_8 -> V_69 [ 6 ] = V_61 ;
V_12 = F_2 ( V_3 , V_23 , V_5 , 0 ) ;
if ( V_12 != V_20 )
return V_21 ;
return V_34 ;
}
static int F_66 ( struct V_2 * V_3 , T_3 V_201 )
{
T_3 V_96 , V_202 , V_81 ;
T_3 V_198 , V_199 ;
struct V_104 V_179 ;
T_1 V_5 [ 0x200 ] ;
T_2 V_203 = 0 , V_178 = 0 ;
struct V_36 * V_37 = (struct V_36 * ) V_3 -> V_1 ;
for ( V_96 = 0 ; V_96 < V_37 -> V_73 . V_75 ; ) {
F_64 ( V_96 , & V_198 , & V_199 ) ;
for ( V_81 = 0 ; V_81 < V_99 ; V_81 ++ , V_96 ++ ) {
switch ( F_67 ( V_37 , V_96 ) ) {
case V_164 :
continue;
default:
break;
}
if ( V_203 == V_96 ) {
F_65 ( V_3 , V_96 , 0 , 0x80 , & V_5 ) ;
V_203 += 0x80 ;
}
V_178 = ( V_96 % 0x80 ) * 4 ;
V_179 . V_91 = V_5 [ V_178 ] ;
V_179 . V_93 = V_5 [ V_178 + 1 ] ;
V_179 . V_95 = F_36 ( V_5 [ V_178 + 2 ] , V_5 [ V_178 + 3 ] ) ;
if ( ( V_179 . V_91 & V_183 ) != V_192 ) {
F_50 ( V_3 , V_96 ) ;
continue;
}
if ( ( V_179 . V_93 & V_204 ) == V_205 ) {
F_54 ( V_3 , V_96 ) ;
continue;
}
if ( V_179 . V_95 != V_83 ) {
if ( ( V_179 . V_95 < V_198 ) || ( V_199 <= V_179 . V_95 ) ) {
F_54 ( V_3 , V_96 ) ;
continue;
}
V_202 = F_58 ( V_37 , V_179 . V_95 ) ;
if ( V_202 != V_83 ) {
if ( V_179 . V_95 == 0 ) {
F_24 ( V_3 , V_179 . V_95 , V_96 ) ;
if ( F_49 ( V_3 , V_201 ) ) {
F_24 ( V_3 , V_179 . V_95 , V_202 ) ;
continue;
}
}
F_55 ( V_3 , V_202 , 0 , & V_179 ) ;
if ( ( V_179 . V_91 & V_206 ) == V_207 ) {
F_54 ( V_3 , V_96 ) ;
continue;
} else {
F_54 ( V_3 , V_202 ) ;
}
}
F_24 ( V_3 , V_179 . V_95 , V_96 ) ;
}
}
}
return V_161 ;
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
if ( V_37 -> V_195 . V_196 ) {
V_12 = F_20 ( V_3 , V_208 ) ;
if ( V_12 != V_20 ) {
F_4 ( L_10 ) ;
return V_21 ;
}
memset ( V_8 , 0 , sizeof( struct V_7 ) ) ;
V_8 -> V_65 = F_21 ( V_66 ) ;
V_8 -> V_17 = V_63 ;
V_8 -> V_67 = V_68 ;
V_8 -> V_69 [ 0 ] = 0xF1 ;
V_8 -> V_69 [ 1 ] = 0x02 ;
V_8 -> V_69 [ 5 ] = ( unsigned char ) ( V_60 ) ;
V_8 -> V_69 [ 4 ] = ( unsigned char ) ( V_60 >> 8 ) ;
V_8 -> V_69 [ 3 ] = ( unsigned char ) ( V_60 >> 16 ) ;
V_8 -> V_69 [ 2 ] = ( unsigned char ) ( V_60 >> 24 ) ;
V_12 = F_2 ( V_3 , V_23 , F_22 ( V_25 ) , 1 ) ;
} else {
void * V_5 ;
int V_47 = 0 ;
T_3 V_72 , V_71 ;
T_1 V_102 ;
T_3 V_176 ;
T_2 V_209 ;
V_5 = F_31 ( V_63 , V_82 ) ;
if ( V_5 == NULL )
return V_21 ;
V_12 = F_20 ( V_3 , V_107 ) ;
if ( V_12 != V_20 ) {
F_69 ( L_11 ) ;
V_12 = V_21 ;
goto exit;
}
V_71 = ( T_3 ) ( V_60 / V_37 -> V_73 . V_86 ) ;
V_102 = ( T_1 ) ( V_60 % V_37 -> V_73 . V_86 ) ;
while ( 1 ) {
if ( V_61 > ( V_37 -> V_73 . V_86 - V_102 ) )
V_176 = V_37 -> V_73 . V_86 - V_102 ;
else
V_176 = V_61 ;
V_72 = F_58 ( V_37 , V_71 ) ;
V_209 = V_72 * 0x20 + V_102 ;
memset ( V_8 , 0 , sizeof( struct V_7 ) ) ;
V_8 -> V_65 = F_21 ( V_66 ) ;
V_8 -> V_17 = 0x200 * V_176 ;
V_8 -> V_67 = V_68 ;
V_8 -> V_69 [ 0 ] = 0xF1 ;
V_8 -> V_69 [ 1 ] = 0x02 ;
V_8 -> V_69 [ 5 ] = ( unsigned char ) ( V_209 ) ;
V_8 -> V_69 [ 4 ] = ( unsigned char ) ( V_209 >> 8 ) ;
V_8 -> V_69 [ 3 ] = ( unsigned char ) ( V_209 >> 16 ) ;
V_8 -> V_69 [ 2 ] = ( unsigned char ) ( V_209 >> 24 ) ;
V_12 = F_2 ( V_3 , V_23 , V_5 + V_47 , 0 ) ;
if ( V_12 != V_20 ) {
F_69 ( L_12 , V_12 ) ;
V_12 = V_21 ;
goto exit;
}
V_61 -= V_176 ;
if ( V_61 <= 0 )
break;
V_71 ++ ;
V_102 = 0 ;
V_47 += V_119 * V_176 ;
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
if ( V_37 -> V_195 . V_196 ) {
V_12 = F_20 ( V_3 , V_208 ) ;
if ( V_12 != V_20 ) {
F_69 ( L_13 ) ;
return V_21 ;
}
memset ( V_8 , 0 , sizeof( struct V_7 ) ) ;
V_8 -> V_65 = F_21 ( V_66 ) ;
V_8 -> V_17 = V_63 ;
V_8 -> V_67 = 0x00 ;
V_8 -> V_69 [ 0 ] = 0xF0 ;
V_8 -> V_69 [ 1 ] = 0x04 ;
V_8 -> V_69 [ 5 ] = ( unsigned char ) ( V_60 ) ;
V_8 -> V_69 [ 4 ] = ( unsigned char ) ( V_60 >> 8 ) ;
V_8 -> V_69 [ 3 ] = ( unsigned char ) ( V_60 >> 16 ) ;
V_8 -> V_69 [ 2 ] = ( unsigned char ) ( V_60 >> 24 ) ;
V_12 = F_2 ( V_3 , V_70 , F_22 ( V_25 ) , 1 ) ;
} else {
void * V_5 ;
int V_47 = 0 ;
T_3 V_101 ;
T_1 V_102 ;
T_3 V_176 , V_174 , V_175 ;
V_5 = F_31 ( V_63 , V_82 ) ;
if ( V_5 == NULL )
return V_21 ;
F_15 ( V_5 , V_63 , V_25 ) ;
V_12 = F_20 ( V_3 , V_107 ) ;
if ( V_12 != V_20 ) {
F_69 ( L_11 ) ;
V_12 = V_21 ;
goto exit;
}
V_101 = ( T_3 ) ( V_60 / V_37 -> V_73 . V_86 ) ;
V_102 = ( T_1 ) ( V_60 % V_37 -> V_73 . V_86 ) ;
while ( 1 ) {
if ( V_61 > ( V_37 -> V_73 . V_86 - V_102 ) )
V_176 = V_37 -> V_73 . V_86 - V_102 ;
else
V_176 = V_61 ;
V_174 = F_58 ( V_37 , V_101 ) ;
V_175 = F_57 ( V_3 , V_101 ) ;
V_12 = F_47 ( V_3 , V_174 , V_175 , V_101 , V_102 , V_5 + V_47 , V_176 ) ;
if ( V_12 != V_20 ) {
F_69 ( L_14 , V_12 ) ;
V_12 = V_21 ;
goto exit;
}
V_37 -> V_73 . V_76 [ V_174 ] = V_100 ;
F_46 ( V_3 , V_101 , V_175 ) ;
V_61 -= V_176 ;
if ( V_61 <= 0 )
break;
V_101 ++ ;
V_102 = 0 ;
V_47 += V_119 * V_176 ;
}
exit:
F_29 ( V_5 ) ;
}
return V_12 ;
}
static int F_71 ( struct V_2 * V_3 , T_3 V_178 , void * V_5 )
{
struct V_7 * V_8 = (struct V_7 * ) V_3 -> V_9 ;
int V_12 ;
memset ( V_8 , 0 , sizeof( struct V_7 ) ) ;
V_8 -> V_65 = F_21 ( V_66 ) ;
V_8 -> V_17 = 0x01 ;
V_8 -> V_67 = V_68 ;
V_8 -> V_69 [ 0 ] = 0xED ;
V_8 -> V_69 [ 2 ] = ( unsigned char ) ( V_178 >> 8 ) ;
V_8 -> V_69 [ 3 ] = ( unsigned char ) V_178 ;
V_12 = F_2 ( V_3 , V_23 , V_5 , 0 ) ;
return V_12 ;
}
static int F_72 ( struct V_2 * V_3 , T_1 * V_5 )
{
T_3 V_210 ;
T_2 V_211 ;
struct V_36 * V_37 = (struct V_36 * ) V_3 -> V_1 ;
V_211 = * ( T_2 * ) & V_5 [ 0x18 ] ;
V_37 -> V_53 = ( T_1 ) ( ( V_211 >> 8 ) & 0x0f ) ;
V_210 = ( T_3 ) V_211 ;
V_211 = * ( T_2 * ) ( & V_5 [ 0x14 ] ) ;
if ( V_37 -> V_38 . V_50 && ! V_37 -> V_38 . V_51 )
V_37 -> V_52 = ( V_211 >> 8 ) & 0x3fffff ;
V_37 -> V_55 = ( ( V_210 & 0x03 ) << 10 ) | ( T_3 ) ( V_211 >> 22 ) ;
V_37 -> V_56 = ( T_1 ) ( V_211 >> 7 ) & 0x07 ;
if ( V_37 -> V_38 . V_50 && V_37 -> V_38 . V_51 )
V_37 -> V_52 = * ( T_2 * ) ( & V_5 [ 0x100 ] ) ;
if ( V_37 -> V_53 > V_212 ) {
V_37 -> V_54 = 1 << ( V_37 -> V_53 - V_212 ) ;
V_37 -> V_53 = V_212 ;
} else {
V_37 -> V_54 = 1 ;
}
return V_34 ;
}
static int F_20 ( struct V_2 * V_3 , unsigned char V_213 )
{
int V_214 ;
char * V_215 = NULL ;
unsigned char * V_5 = NULL ;
const struct V_216 * V_217 = NULL ;
int V_12 = V_21 ;
struct V_7 * V_8 = (struct V_7 * ) V_3 -> V_9 ;
struct V_36 * V_37 = (struct V_36 * ) V_3 -> V_1 ;
if ( V_37 -> V_218 == V_213 )
return V_34 ;
switch ( V_213 ) {
case V_219 :
F_4 ( L_15 ) ;
V_215 = L_16 ;
break;
case V_220 :
F_4 ( L_17 ) ;
V_215 = L_18 ;
break;
case V_64 :
F_4 ( L_19 ) ;
V_215 = L_20 ;
break;
case V_221 :
F_4 ( L_21 ) ;
V_215 = L_22 ;
break;
case V_208 :
F_4 ( L_23 ) ;
V_215 = L_24 ;
break;
case V_107 :
F_4 ( L_25 ) ;
V_215 = L_26 ;
break;
default:
F_4 ( L_27 ) ;
goto V_222;
}
V_214 = F_73 ( & V_217 , V_215 , & V_3 -> V_223 -> V_224 ) ;
if ( V_214 ) {
F_4 ( L_28 , V_215 ) ;
goto V_222;
}
V_5 = F_31 ( V_217 -> V_225 , V_82 ) ;
if ( V_5 == NULL ) {
F_4 ( L_29 ) ;
goto V_222;
}
memcpy ( V_5 , V_217 -> V_226 , V_217 -> V_225 ) ;
memset ( V_8 , 0 , sizeof( struct V_7 ) ) ;
V_8 -> V_65 = F_21 ( V_66 ) ;
V_8 -> V_17 = V_217 -> V_225 ;
V_8 -> V_67 = 0x00 ;
V_8 -> V_69 [ 0 ] = 0xEF ;
V_12 = F_2 ( V_3 , V_70 , V_5 , 0 ) ;
V_37 -> V_218 = V_213 ;
F_29 ( V_5 ) ;
V_222:
F_74 ( V_217 ) ;
return V_12 ;
}
static int F_75 ( struct V_2 * V_3 )
{
T_2 V_12 ;
T_3 V_227 ;
unsigned char * V_228 = NULL , * V_229 = NULL ;
struct V_104 V_179 ;
T_3 V_201 , V_230 ;
T_2 V_231 ;
struct V_36 * V_37 = (struct V_36 * ) V_3 -> V_1 ;
F_76 ( V_232 L_30 ) ;
F_44 ( V_3 ) ;
V_228 = F_31 ( V_119 , V_82 ) ;
V_229 = F_31 ( V_119 , V_82 ) ;
if ( ( V_228 == NULL ) || ( V_229 == NULL ) ) {
V_12 = V_180 ;
goto exit;
}
V_201 = V_230 = V_83 ;
V_231 = 0 ;
for ( V_227 = 0 ; V_227 < V_233 + 2 ; V_227 ++ ) {
switch ( F_35 ( V_3 , V_227 , 0 , ( T_2 * ) V_228 , & V_179 ) ) {
case V_161 :
break;
case V_186 :
break;
case V_164 :
default:
continue;
}
if ( ( V_179 . V_91 & V_183 ) == V_234 )
continue;
if ( ( ( V_179 . V_93 & V_235 ) == V_236 ) ||
( F_38 ( ( (struct V_120 * ) V_228 ) -> V_237 . V_238 ) != V_239 ) ||
( F_38 ( ( (struct V_120 * ) V_228 ) -> V_237 . V_240 ) != V_241 ) ||
( ( (struct V_120 * ) V_228 ) -> V_237 . V_242 != V_243 ) )
continue;
if ( V_201 != V_83 ) {
V_230 = V_227 ;
break;
}
V_201 = V_227 ;
memcpy ( V_229 , V_228 , V_119 ) ;
if ( V_179 . V_89 & ( V_244 | V_245 | V_246 ) )
V_231 = 1 ;
}
if ( V_201 == V_83 ) {
V_12 = V_164 ;
goto exit;
}
if ( ( V_179 . V_110 & V_247 ) == V_248 )
F_39 ( V_37 , V_249 ) ;
V_12 = V_164 ;
if ( V_231 == 0 )
V_12 = F_37 ( V_3 , V_201 , V_229 ) ;
if ( V_12 && ( V_230 != V_83 ) )
V_12 = F_37 ( V_3 , V_230 , V_228 ) ;
if ( V_12 ) {
V_12 = V_164 ;
goto exit;
}
for ( V_227 = 0 ; V_227 < V_201 ; V_227 ++ )
V_37 -> V_73 . V_76 [ V_227 ] = V_79 ;
V_37 -> V_73 . V_76 [ V_201 ] = V_80 ;
if ( V_230 != V_83 ) {
for ( V_227 = V_201 + 1 ; V_227 < V_230 ; V_227 ++ )
V_37 -> V_73 . V_76 [ V_227 ] = V_79 ;
V_37 -> V_73 . V_76 [ V_230 ] = V_80 ;
}
V_12 = F_66 ( V_3 , V_201 ) ;
if ( V_12 )
goto exit;
for ( V_227 = V_99 ;
V_227 < V_37 -> V_73 . V_75 ;
V_227 += V_99 ) {
if ( F_34 ( V_3 , V_227 ) == 0 ) {
F_39 ( V_37 , V_249 ) ;
break;
}
}
if ( F_45 ( V_3 ) ) {
V_12 = V_180 ;
goto exit;
}
V_12 = V_161 ;
exit:
F_29 ( V_229 ) ;
F_29 ( V_228 ) ;
F_76 ( V_232 L_31 ) ;
return V_12 ;
}
static int F_60 ( struct V_2 * V_3 )
{
struct V_7 * V_8 = (struct V_7 * ) V_3 -> V_9 ;
int V_12 ;
T_1 V_5 [ 0x200 ] ;
T_3 V_250 , V_251 ;
struct V_36 * V_37 = (struct V_36 * ) V_3 -> V_1 ;
F_76 ( V_232 L_32 ) ;
V_12 = F_20 ( V_3 , V_221 ) ;
if ( V_12 != V_20 ) {
F_76 ( V_252 L_33 ) ;
return V_21 ;
}
memset ( V_8 , 0 , sizeof( struct V_7 ) ) ;
V_8 -> V_65 = F_21 ( V_66 ) ;
V_8 -> V_17 = 0x200 ;
V_8 -> V_67 = V_68 ;
V_8 -> V_69 [ 0 ] = 0xF1 ;
V_8 -> V_69 [ 1 ] = 0x01 ;
V_12 = F_2 ( V_3 , V_23 , & V_5 , 0 ) ;
if ( V_12 != V_20 ) {
F_76 ( V_252 L_34 ) ;
return V_21 ;
}
V_37 -> V_195 = * (struct V_253 * ) & V_5 [ 0 ] ;
if ( V_37 -> V_195 . V_39 && V_37 -> V_195 . V_40 ) {
F_76 ( V_232 L_35 , V_37 -> V_195 . V_39 ) ;
F_76 ( V_232 L_36 , V_37 -> V_195 . V_40 ) ;
F_76 ( V_232 L_37 , V_37 -> V_195 . V_196 ) ;
F_76 ( V_232 L_38 , V_37 -> V_195 . V_254 ) ;
F_76 ( V_232 L_39 , V_37 -> V_195 . V_44 ) ;
if ( V_37 -> V_195 . V_196 ) {
V_250 = ( V_5 [ 6 ] << 8 ) | V_5 [ 7 ] ;
V_251 = ( V_5 [ 10 ] << 8 ) | V_5 [ 11 ] ;
V_37 -> V_197 = V_250 * V_251 ;
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
V_12 = F_20 ( V_3 , V_219 ) ;
if ( V_12 != V_20 ) {
F_4 ( L_43 ) ;
return V_21 ;
}
memset ( V_8 , 0 , sizeof( struct V_7 ) ) ;
V_8 -> V_65 = F_21 ( V_66 ) ;
V_8 -> V_67 = V_68 ;
V_8 -> V_69 [ 0 ] = 0xF2 ;
V_12 = F_2 ( V_3 , V_23 , NULL , 0 ) ;
if ( V_12 != V_20 ) {
F_4 ( L_44 ) ;
return V_21 ;
}
V_12 = F_20 ( V_3 , V_220 ) ;
if ( V_12 != V_20 ) {
F_4 ( L_45 ) ;
return V_21 ;
}
memset ( V_8 , 0 , sizeof( struct V_7 ) ) ;
V_8 -> V_65 = F_21 ( V_66 ) ;
V_8 -> V_17 = 0x200 ;
V_8 -> V_67 = V_68 ;
V_8 -> V_69 [ 0 ] = 0xF1 ;
V_12 = F_2 ( V_3 , V_23 , & V_5 , 0 ) ;
if ( V_12 != V_20 ) {
F_4 ( L_44 ) ;
return V_21 ;
}
V_37 -> V_38 = * (struct V_255 * ) & V_5 [ 0 ] ;
if ( V_37 -> V_38 . V_39 && V_37 -> V_38 . V_40 ) {
F_72 ( V_3 , ( unsigned char * ) & V_5 ) ;
F_4 ( L_35 , V_37 -> V_38 . V_39 ) ;
F_4 ( L_36 , V_37 -> V_38 . V_40 ) ;
F_4 ( L_46 , V_37 -> V_38 . V_51 ) ;
F_4 ( L_47 , V_37 -> V_38 . V_50 ) ;
F_4 ( L_48 , V_37 -> V_38 . V_256 ) ;
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
T_1 V_257 = 0 ;
struct V_36 * V_37 = (struct V_36 * ) ( V_3 -> V_1 ) ;
V_12 = F_71 ( V_3 , V_258 , & V_257 ) ;
if ( V_12 != V_20 )
return V_21 ;
if ( V_257 & 0x01 ) {
if ( ! V_37 -> V_38 . V_40 ) {
V_12 = F_13 ( V_3 ) ;
if ( V_12 != V_20 )
return V_21 ;
}
}
if ( V_257 & 0x02 ) {
if ( ! V_37 -> V_195 . V_40 ) {
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
V_37 -> V_259 = V_260 ;
switch ( V_25 -> V_59 [ 0 ] ) {
case V_261 :
V_12 = F_12 ( V_3 , V_25 ) ;
break;
case V_262 :
V_12 = F_14 ( V_3 , V_25 ) ;
break;
case V_263 :
V_12 = F_16 ( V_3 , V_25 ) ;
break;
case V_264 :
V_12 = F_17 ( V_3 , V_25 ) ;
break;
case V_265 :
V_12 = F_19 ( V_3 , V_25 ) ;
break;
case V_266 :
V_12 = F_23 ( V_3 , V_25 ) ;
break;
default:
V_37 -> V_259 = V_267 ;
V_12 = V_268 ;
break;
}
return V_12 ;
}
static int F_79 ( struct V_2 * V_3 , struct V_35 * V_25 )
{
int V_12 ;
struct V_36 * V_37 = (struct V_36 * ) V_3 -> V_1 ;
V_37 -> V_259 = V_260 ;
switch ( V_25 -> V_59 [ 0 ] ) {
case V_261 :
V_12 = F_59 ( V_3 , V_25 ) ;
break;
case V_262 :
V_12 = F_61 ( V_3 , V_25 ) ;
break;
case V_263 :
V_12 = F_62 ( V_3 , V_25 ) ;
break;
case V_264 :
V_12 = F_63 ( V_3 , V_25 ) ;
break;
case V_265 :
V_12 = F_68 ( V_3 , V_25 ) ;
break;
case V_266 :
V_12 = F_70 ( V_3 , V_25 ) ;
break;
default:
V_37 -> V_259 = V_267 ;
V_12 = V_268 ;
break;
}
return V_12 ;
}
static int F_80 ( struct V_35 * V_25 , struct V_2 * V_3 )
{
int V_12 = 0 ;
struct V_36 * V_37 = (struct V_36 * ) ( V_3 -> V_1 ) ;
F_9 ( V_25 , 0 ) ;
if ( F_81 ( ! ( V_37 -> V_38 . V_40 || V_37 -> V_195 . V_40 ) ) ) {
V_12 = F_77 ( V_3 ) ;
} else {
if ( V_37 -> V_38 . V_40 )
V_12 = F_78 ( V_3 , V_25 ) ;
if ( V_37 -> V_195 . V_40 )
V_12 = F_79 ( V_3 , V_25 ) ;
}
return 0 ;
}
static int F_82 ( struct V_269 * V_270 ,
const struct V_271 * V_272 )
{
int V_12 ;
T_1 V_257 = 0 ;
struct V_2 * V_3 ;
V_12 = F_83 ( & V_3 , V_270 , V_272 ,
( V_272 - V_273 ) + V_274 ) ;
if ( V_12 )
return V_12 ;
if ( ! V_3 -> V_1 ) {
V_3 -> V_1 = F_84 ( sizeof( struct V_36 ) , V_82 ) ;
if ( ! V_3 -> V_1 )
return - V_275 ;
V_3 -> V_276 = F_1 ;
}
V_3 -> V_277 = L_51 ;
V_3 -> V_278 = F_80 ;
V_3 -> V_279 = 0 ;
V_12 = F_85 ( V_3 ) ;
if ( V_12 )
return V_12 ;
V_12 = F_71 ( V_3 , V_258 , & V_257 ) ;
if ( V_12 != V_20 ) {
F_86 ( V_270 ) ;
return V_21 ;
}
if ( ! ( V_257 & 0x01 ) ) {
F_69 ( L_52
L_53 ) ;
}
return V_12 ;
}
static int F_87 ( struct V_269 * V_280 )
{
T_1 V_281 = 0 ;
struct V_2 * V_3 = F_88 ( V_280 ) ;
struct V_36 * V_37 = (struct V_36 * ) ( V_3 -> V_1 ) ;
F_89 ( & V_3 -> V_282 ) ;
F_4 ( L_54 , V_283 ) ;
if ( V_3 -> V_284 )
( V_3 -> V_284 ) ( V_3 , V_285 ) ;
F_90 ( & V_3 -> V_282 ) ;
V_37 -> V_286 = true ;
V_37 -> V_38 = * (struct V_255 * ) & V_281 ;
V_37 -> V_195 = * (struct V_253 * ) & V_281 ;
V_37 -> V_287 = * (struct V_288 * ) & V_281 ;
return 0 ;
}
static int F_91 ( struct V_269 * V_280 )
{
T_1 V_281 = 0 ;
struct V_2 * V_3 = F_88 ( V_280 ) ;
struct V_36 * V_37 = (struct V_36 * ) ( V_3 -> V_1 ) ;
F_4 ( L_54 , V_283 ) ;
F_92 ( V_280 ) ;
V_37 -> V_286 = true ;
V_37 -> V_38 = * (struct V_255 * ) & V_281 ;
V_37 -> V_195 = * (struct V_253 * ) & V_281 ;
V_37 -> V_287 = * (struct V_288 * ) & V_281 ;
return 0 ;
}
