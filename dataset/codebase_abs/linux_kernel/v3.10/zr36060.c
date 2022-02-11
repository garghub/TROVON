static T_1
F_1 ( struct V_1 * V_2 ,
T_2 V_3 )
{
T_1 V_4 = 0 ;
if ( V_2 -> V_5 -> V_6 -> V_7 )
V_4 = ( V_2 -> V_5 -> V_6 -> V_7 ( V_2 -> V_5 ,
V_3 ) ) & 0xff ;
else
F_2 ( 1 ,
V_8 L_1 ,
V_2 -> V_9 ) ;
return V_4 ;
}
static void
F_3 ( struct V_1 * V_2 ,
T_2 V_3 ,
T_1 V_4 )
{
F_2 ( 4 , L_2 , V_4 , V_3 ) ;
if ( V_2 -> V_5 -> V_6 -> V_10 )
V_2 -> V_5 -> V_6 -> V_10 ( V_2 -> V_5 , V_3 , V_4 ) ;
else
F_2 ( 1 ,
V_8
L_3 ,
V_2 -> V_9 ) ;
}
static T_1
F_4 ( struct V_1 * V_2 )
{
V_2 -> V_11 = F_1 ( V_2 , V_12 ) ;
F_1 ( V_2 , 0 ) ;
return V_2 -> V_11 ;
}
static T_2
F_5 ( struct V_1 * V_2 )
{
V_2 -> V_13 = ( F_1 ( V_2 , V_14 ) << 8 ) |
( F_1 ( V_2 , V_15 ) & 0xFF ) ;
F_1 ( V_2 , 0 ) ;
return V_2 -> V_13 ;
}
static void
F_6 ( struct V_1 * V_2 )
{
int V_16 = 0 ;
while ( F_4 ( V_2 ) & V_17 ) {
F_7 ( 1 ) ;
if ( V_16 ++ > 200000 ) {
F_2 ( 1 ,
L_4 ,
V_2 -> V_9 , V_2 -> V_11 ) ;
break;
}
}
}
static int
F_8 ( struct V_1 * V_2 )
{
if ( ( F_1 ( V_2 , V_18 ) != 0x33 ) &&
( F_1 ( V_2 , V_19 ) != 0x01 ) ) {
F_2 ( 1 ,
V_8
L_5 ,
V_2 -> V_9 ) ;
return - V_20 ;
}
F_6 ( V_2 ) ;
if ( V_2 -> V_11 & V_17 ) {
F_2 ( 1 ,
V_8
L_6 ,
V_2 -> V_9 ) ;
return - V_21 ;
}
return 0 ;
}
static int
F_9 ( struct V_1 * V_2 ,
T_2 V_22 ,
T_2 V_23 ,
const char * V_24 )
{
int V_16 = 0 ;
F_2 ( 4 , L_7 , V_2 -> V_9 ,
V_22 , V_23 ) ;
while ( V_16 < V_23 ) {
F_3 ( V_2 , V_22 ++ , V_24 [ V_16 ++ ] ) ;
}
return V_16 ;
}
static int
F_10 ( struct V_1 * V_2 )
{
char V_25 [ 34 ] ;
int V_16 ;
F_2 ( 3 , L_8 , V_2 -> V_9 ,
V_2 -> V_26 , V_2 -> V_27 , V_28 ) ;
V_25 [ 0 ] = 0xff ;
V_25 [ 1 ] = 0xc0 ;
V_25 [ 2 ] = 0x00 ;
V_25 [ 3 ] = ( 3 * V_28 ) + 8 ;
V_25 [ 4 ] = V_29 ;
V_25 [ 5 ] = ( V_2 -> V_27 ) >> 8 ;
V_25 [ 6 ] = ( V_2 -> V_27 ) & 0xff ;
V_25 [ 7 ] = ( V_2 -> V_26 ) >> 8 ;
V_25 [ 8 ] = ( V_2 -> V_26 ) & 0xff ;
V_25 [ 9 ] = V_28 ;
for ( V_16 = 0 ; V_16 < V_28 ; V_16 ++ ) {
V_25 [ 10 + ( V_16 * 3 ) ] = V_16 ;
V_25 [ 11 + ( V_16 * 3 ) ] = ( V_2 -> V_30 [ V_16 ] << 4 ) |
( V_2 -> V_31 [ V_16 ] ) ;
V_25 [ 12 + ( V_16 * 3 ) ] = V_32 [ V_16 ] ;
}
return F_9 ( V_2 , V_33 ,
( 3 * V_28 ) + 10 , V_25 ) ;
}
static int
F_11 ( struct V_1 * V_2 )
{
char V_34 [ 16 ] ;
int V_16 ;
F_2 ( 3 , L_9 , V_2 -> V_9 ) ;
V_34 [ 0 ] = 0xff ;
V_34 [ 1 ] = 0xda ;
V_34 [ 2 ] = 0x00 ;
V_34 [ 3 ] = 2 + 1 + ( 2 * V_28 ) + 3 ;
V_34 [ 4 ] = V_28 ;
for ( V_16 = 0 ; V_16 < V_28 ; V_16 ++ ) {
V_34 [ 5 + ( V_16 * 2 ) ] = V_16 ;
V_34 [ 6 + ( V_16 * 2 ) ] = ( V_35 [ V_16 ] << 4 ) |
V_36 [ V_16 ] ;
}
V_34 [ 2 + 1 + ( 2 * V_28 ) + 2 ] = 00 ;
V_34 [ 2 + 1 + ( 2 * V_28 ) + 3 ] = 0x3f ;
V_34 [ 2 + 1 + ( 2 * V_28 ) + 4 ] = 00 ;
return F_9 ( V_2 , V_37 ,
4 + 1 + ( 2 * V_28 ) + 3 ,
V_34 ) ;
}
static int
F_12 ( struct V_1 * V_2 )
{
char V_38 [ 6 ] ;
F_2 ( 3 , L_10 , V_2 -> V_9 ) ;
V_38 [ 0 ] = 0xff ;
V_38 [ 1 ] = 0xdd ;
V_38 [ 2 ] = 0x00 ;
V_38 [ 3 ] = 0x04 ;
V_38 [ 4 ] = ( V_2 -> V_39 ) >> 8 ;
V_38 [ 5 ] = ( V_2 -> V_39 ) & 0xff ;
return F_9 ( V_2 , V_40 , 6 , V_38 ) ;
}
static void
F_13 ( struct V_1 * V_2 )
{
int V_41 = 0 ;
long V_42 , V_43 ;
if ( V_2 -> V_44 == V_45 ) {
F_2 ( 2 , L_11 , V_2 -> V_9 ) ;
F_3 ( V_2 , V_46 , V_47 ) ;
F_3 ( V_2 , V_48 , V_49 ) ;
F_3 ( V_2 , V_50 ,
V_51 | V_52 |
V_53 ) ;
F_3 ( V_2 , V_54 , 0x00 ) ;
F_3 ( V_2 , V_55 , 0x00 ) ;
F_3 ( V_2 , V_56 , 0x00 ) ;
F_3 ( V_2 , V_57 , 0 ) ;
F_3 ( V_2 , V_14 , V_2 -> V_13 >> 8 ) ;
F_3 ( V_2 , V_15 , V_2 -> V_13 & 0xff ) ;
F_3 ( V_2 , V_58 , 0xff ) ;
F_3 ( V_2 , V_59 , 0xff ) ;
F_3 ( V_2 , V_60 , 0xff ) ;
V_41 += F_10 ( V_2 ) ;
V_41 += F_11 ( V_2 ) ;
V_41 += F_12 ( V_2 ) ;
V_41 +=
F_9 ( V_2 , V_61 , sizeof( V_62 ) ,
V_62 ) ;
V_41 +=
F_9 ( V_2 , V_63 , sizeof( V_64 ) ,
V_64 ) ;
F_3 ( V_2 , V_65 , 0xff ) ;
F_3 ( V_2 , V_65 + 1 , 0xe0 + V_2 -> V_66 . V_67 ) ;
F_3 ( V_2 , V_65 + 2 , 0x00 ) ;
F_3 ( V_2 , V_65 + 3 , V_2 -> V_66 . V_23 + 2 ) ;
V_41 += F_9 ( V_2 , V_65 + 4 , 60 ,
V_2 -> V_66 . V_24 ) + 4 ;
F_3 ( V_2 , V_68 , 0xff ) ;
F_3 ( V_2 , V_68 + 1 , 0xfe ) ;
F_3 ( V_2 , V_68 + 2 , 0x00 ) ;
F_3 ( V_2 , V_68 + 3 , V_2 -> V_69 . V_23 + 2 ) ;
V_41 += F_9 ( V_2 , V_68 + 4 , 60 ,
V_2 -> V_69 . V_24 ) + 4 ;
V_41 = V_2 -> V_70 - V_41 ;
V_42 = V_41 << 3 ;
V_43 = V_42 >> 16 ;
F_2 ( 3 ,
L_12 ,
V_2 -> V_9 , V_41 , V_2 -> V_70 , V_42 , V_43 ) ;
F_3 ( V_2 , V_71 , V_43 >> 8 ) ;
F_3 ( V_2 , V_72 , V_43 & 0xff ) ;
V_43 = V_42 & 0xffff ;
F_3 ( V_2 , V_73 , V_43 >> 8 ) ;
F_3 ( V_2 , V_74 , V_43 & 0xff ) ;
V_42 -= V_42 >> 7 ;
V_42 -= ( ( V_42 * 5 ) >> 6 ) ;
V_43 = V_42 >> 16 ;
F_2 ( 3 , L_13 ,
V_2 -> V_9 , V_42 , V_43 ) ;
F_3 ( V_2 , V_75 , V_43 >> 8 ) ;
F_3 ( V_2 , V_76 , V_43 & 0xff ) ;
V_43 = V_42 & 0xffff ;
F_3 ( V_2 , V_77 , V_43 >> 8 ) ;
F_3 ( V_2 , V_78 , V_43 & 0xff ) ;
F_3 ( V_2 , V_79 ,
V_80 | V_81 |
( ( V_2 -> V_69 . V_23 > 0 ) ? V_82 : 0 ) |
( ( V_2 -> V_66 . V_23 > 0 ) ? V_83 : 0 ) ) ;
F_3 ( V_2 , V_84 , V_85 ) ;
} else {
F_2 ( 2 , L_14 , V_2 -> V_9 ) ;
F_3 ( V_2 , V_46 , V_47 ) ;
F_3 ( V_2 , V_48 , V_49 ) ;
F_3 ( V_2 , V_50 , 0 ) ;
F_3 ( V_2 , V_54 , 0x00 ) ;
F_3 ( V_2 , V_55 , 0x00 ) ;
F_3 ( V_2 , V_56 , 0x00 ) ;
F_3 ( V_2 , V_57 , 0 ) ;
F_3 ( V_2 , V_79 , 0 ) ;
F_9 ( V_2 , V_63 , sizeof( V_64 ) ,
V_64 ) ;
F_3 ( V_2 , V_84 , V_85 ) ;
}
F_3 ( V_2 , V_46 ,
V_47 | V_86 ) ;
F_6 ( V_2 ) ;
F_2 ( 2 , L_15 , V_2 -> V_9 ,
V_2 -> V_11 ) ;
if ( V_2 -> V_11 & V_17 ) {
F_2 ( 1 , V_8 L_16 , V_2 -> V_9 ) ;
return;
}
}
static int
F_14 ( struct V_87 * V_5 ,
int V_44 )
{
struct V_1 * V_2 = (struct V_1 * ) V_5 -> V_24 ;
F_2 ( 2 , L_17 , V_2 -> V_9 , V_44 ) ;
if ( ( V_44 != V_88 ) && ( V_44 != V_45 ) )
return - V_89 ;
V_2 -> V_44 = V_44 ;
F_13 ( V_2 ) ;
return 0 ;
}
static int
F_15 ( struct V_87 * V_5 ,
struct V_90 * V_91 ,
struct V_92 * V_93 ,
struct V_94 * V_95 )
{
struct V_1 * V_2 = (struct V_1 * ) V_5 -> V_24 ;
T_3 V_3 ;
int V_96 ;
F_2 ( 2 , L_18 , V_2 -> V_9 ,
V_93 -> V_97 , V_93 -> V_98 , V_93 -> V_26 , V_93 -> V_27 , V_93 -> V_99 ) ;
V_2 -> V_26 = V_93 -> V_26 / ( V_93 -> V_99 & 0xff ) ;
V_2 -> V_27 = V_93 -> V_27 / ( V_93 -> V_99 >> 8 ) ;
F_3 ( V_2 , V_46 , V_47 ) ;
V_3 = ( ! V_95 -> V_100 ? V_101 : 0 )
| ( ! V_95 -> V_102 ? V_103 : 0 )
| ( V_95 -> V_104 ? V_105 : 0 )
| ( V_95 -> V_106 ? V_107 : 0 )
| ( V_95 -> V_108 ? V_109 : 0 )
| ( V_95 -> V_110 ? V_111 : 0 )
| ( V_95 -> V_112 ? V_113 : 0 )
| ( V_95 -> V_114 ? V_115 : 0 ) ;
F_3 ( V_2 , V_116 , V_3 ) ;
V_3 = 0 ;
switch ( V_93 -> V_99 & 0xff ) {
default:
case 1 :
break;
case 2 :
V_3 |= V_117 ;
break;
case 4 :
V_3 |= V_118 ;
break;
}
switch ( V_93 -> V_99 >> 8 ) {
default:
case 1 :
break;
case 2 :
V_3 |= V_119 ;
break;
}
F_3 ( V_2 , V_120 , V_3 ) ;
F_3 ( V_2 , V_121 , 0x00 ) ;
F_3 ( V_2 , V_122 , 0x80 ) ;
F_3 ( V_2 , V_123 , 0x80 ) ;
V_3 = V_91 -> V_124 - 1 ;
F_3 ( V_2 , V_125 , ( V_3 >> 8 ) & 0xff ) ;
F_3 ( V_2 , V_126 , ( V_3 >> 0 ) & 0xff ) ;
V_3 = V_91 -> V_127 - 1 ;
F_3 ( V_2 , V_128 , ( V_3 >> 8 ) & 0xff ) ;
F_3 ( V_2 , V_129 , ( V_3 >> 0 ) & 0xff ) ;
V_3 = 6 - 1 ;
F_3 ( V_2 , V_130 , V_3 ) ;
V_3 = 68 ;
F_3 ( V_2 , V_131 , V_3 ) ;
V_3 = V_91 -> V_132 - 1 ;
F_3 ( V_2 , V_133 , V_3 ) ;
V_3 += V_91 -> V_134 / 2 ;
F_3 ( V_2 , V_135 , ( V_3 >> 8 ) & 0xff ) ;
F_3 ( V_2 , V_136 , ( V_3 >> 0 ) & 0xff ) ;
V_3 = V_91 -> V_137 - 1 ;
F_3 ( V_2 , V_138 , V_3 ) ;
V_3 += V_91 -> V_139 ;
F_3 ( V_2 , V_140 , ( V_3 >> 8 ) & 0xff ) ;
F_3 ( V_2 , V_141 , ( V_3 >> 0 ) & 0xff ) ;
V_3 = V_93 -> V_98 + V_91 -> V_132 ;
F_3 ( V_2 , V_142 , ( V_3 >> 8 ) & 0xff ) ;
F_3 ( V_2 , V_143 , ( V_3 >> 0 ) & 0xff ) ;
V_3 += V_93 -> V_27 ;
F_3 ( V_2 , V_144 , ( V_3 >> 8 ) & 0xff ) ;
F_3 ( V_2 , V_145 , ( V_3 >> 0 ) & 0xff ) ;
V_3 = V_93 -> V_97 + V_91 -> V_137 ;
F_3 ( V_2 , V_146 , ( V_3 >> 8 ) & 0xff ) ;
F_3 ( V_2 , V_147 , ( V_3 >> 0 ) & 0xff ) ;
V_3 += V_93 -> V_26 ;
F_3 ( V_2 , V_148 , ( V_3 >> 8 ) & 0xff ) ;
F_3 ( V_2 , V_149 , ( V_3 >> 0 ) & 0xff ) ;
V_3 = V_91 -> V_132 - 4 ;
F_3 ( V_2 , V_150 , ( V_3 >> 8 ) & 0xff ) ;
F_3 ( V_2 , V_151 , ( V_3 >> 0 ) & 0xff ) ;
V_3 += V_91 -> V_134 / 2 + 8 ;
F_3 ( V_2 , V_152 , ( V_3 >> 8 ) & 0xff ) ;
F_3 ( V_2 , V_153 , ( V_3 >> 0 ) & 0xff ) ;
V_3 = V_91 -> V_137 - 4 ;
F_3 ( V_2 , V_154 , ( V_3 >> 8 ) & 0xff ) ;
F_3 ( V_2 , V_155 , ( V_3 >> 0 ) & 0xff ) ;
V_3 += V_91 -> V_139 + 8 ;
F_3 ( V_2 , V_156 , ( V_3 >> 8 ) & 0xff ) ;
F_3 ( V_2 , V_157 , ( V_3 >> 0 ) & 0xff ) ;
V_96 = V_2 -> V_26 * V_2 -> V_27 ;
V_96 = V_96 * 16 ;
V_96 = V_96 * V_93 -> V_158 / ( V_159 ? 400 : 200 ) ;
if ( V_96 < 8192 )
V_96 = 8192 ;
if ( V_96 > V_2 -> V_160 * 7 )
V_96 = V_2 -> V_160 * 7 ;
V_2 -> V_70 = V_96 >> 3 ;
V_3 = V_2 -> V_161 ;
F_3 ( V_2 , V_162 , V_3 ) ;
return 0 ;
}
static int
F_16 ( struct V_87 * V_5 ,
int type ,
int V_96 ,
void * V_24 )
{
struct V_1 * V_2 = (struct V_1 * ) V_5 -> V_24 ;
int * V_163 = ( int * ) V_24 ;
F_2 ( 2 , L_19 , V_2 -> V_9 , type ,
V_96 ) ;
switch ( type ) {
case V_164 :
if ( V_96 != sizeof( int ) )
return - V_165 ;
F_4 ( V_2 ) ;
* V_163 = V_2 -> V_11 ;
break;
case V_166 :
if ( V_96 != sizeof( int ) )
return - V_165 ;
* V_163 = V_167 ;
break;
case V_168 :
if ( V_96 != sizeof( int ) )
return - V_165 ;
if ( * V_163 != V_167 )
return - V_89 ;
return 0 ;
case V_169 :
case V_170 :
return 0 ;
case V_171 :
return - V_20 ;
case V_172 :
if ( V_96 != sizeof( int ) )
return - V_165 ;
* V_163 = V_2 -> V_160 ;
break;
case V_173 :
if ( V_96 != sizeof( int ) )
return - V_165 ;
V_2 -> V_160 = * V_163 ;
V_2 -> V_70 = ( V_2 -> V_160 * 6 ) >> 3 ;
break;
case V_174 :
if ( V_96 != sizeof( int ) )
return - V_165 ;
* V_163 = F_5 ( V_2 ) ;
break;
case V_175 :
if ( V_96 != sizeof( int ) )
return - V_165 ;
V_2 -> V_13 = * V_163 ;
break;
case V_176 : {
struct V_177 * V_66 = V_24 ;
if ( V_96 != sizeof( struct V_177 ) )
return - V_165 ;
* V_66 = V_2 -> V_66 ;
break;
}
case V_178 : {
struct V_177 * V_66 = V_24 ;
if ( V_96 != sizeof( struct V_177 ) )
return - V_165 ;
V_2 -> V_66 = * V_66 ;
break;
}
case V_179 : {
struct V_180 * V_69 = V_24 ;
if ( V_96 != sizeof( struct V_180 ) )
return - V_165 ;
* V_69 = V_2 -> V_69 ;
break;
}
case V_181 : {
struct V_180 * V_69 = V_24 ;
if ( V_96 != sizeof( struct V_180 ) )
return - V_165 ;
V_2 -> V_69 = * V_69 ;
break;
}
default:
return - V_89 ;
}
return V_96 ;
}
static int
F_17 ( struct V_87 * V_5 )
{
struct V_1 * V_2 = V_5 -> V_24 ;
if ( V_2 ) {
F_2 ( 1 , L_20 , V_2 -> V_9 ,
V_2 -> V_182 ) ;
F_18 ( V_2 ) ;
V_5 -> V_24 = NULL ;
V_183 -- ;
return 0 ;
}
return - V_165 ;
}
static int
F_19 ( struct V_87 * V_5 )
{
struct V_1 * V_2 ;
int V_184 ;
F_2 ( 2 , L_21 ,
V_183 ) ;
if ( V_183 == V_185 ) {
F_2 ( 1 ,
V_8 L_22 ) ;
return - V_186 ;
}
V_5 -> V_24 = V_2 = F_20 ( sizeof( struct V_1 ) , V_187 ) ;
if ( NULL == V_2 ) {
F_2 ( 1 , V_8 L_23 ) ;
return - V_188 ;
}
snprintf ( V_2 -> V_9 , sizeof( V_2 -> V_9 ) , L_24 ,
V_183 ) ;
V_2 -> V_182 = V_183 ++ ;
V_2 -> V_5 = V_5 ;
V_184 = F_8 ( V_2 ) ;
if ( V_184 < 0 ) {
F_17 ( V_5 ) ;
return V_184 ;
}
memcpy ( V_2 -> V_30 , V_189 , 8 ) ;
memcpy ( V_2 -> V_31 , V_190 , 8 ) ;
V_2 -> V_191 = 0 ;
V_2 -> V_44 = V_45 ;
V_2 -> V_26 = 384 ;
V_2 -> V_27 = 288 ;
V_2 -> V_160 = 16000 ;
V_2 -> V_70 = ( V_2 -> V_160 * 6 ) >> 3 ;
V_2 -> V_161 = 240 ;
V_2 -> V_13 = 0x100 ;
V_2 -> V_39 = 1 ;
V_2 -> V_69 . V_23 = 0 ;
V_2 -> V_66 . V_67 = 0 ;
V_2 -> V_66 . V_23 = 0 ;
F_13 ( V_2 ) ;
F_2 ( 1 , V_192 L_25 ,
V_2 -> V_9 ) ;
return 0 ;
}
static int T_4
F_21 ( void )
{
V_183 = 0 ;
return F_22 ( & V_193 ) ;
}
static void T_5
F_23 ( void )
{
if ( V_183 ) {
F_2 ( 1 ,
L_26 ,
V_183 ) ;
}
F_24 ( & V_193 ) ;
}
