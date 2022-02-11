static void F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
unsigned long V_4 ;
F_2 ( & V_2 -> V_5 , V_4 ) ;
V_2 -> V_6 ( V_2 , V_7 , V_3 ) ;
V_2 -> V_8 ( V_2 , V_9 ) ;
F_3 ( & V_2 -> V_5 , V_4 ) ;
}
static int F_4 ( struct V_1 * V_2 )
{
return ( V_2 -> V_8 ( V_2 , V_10 ) == 0xFF ) ;
}
static int F_5 ( struct V_11 * V_12 )
{
struct V_1 * V_2 = F_6 ( V_12 ) ;
if ( V_2 -> V_13 && F_4 ( V_2 ) ) {
F_7 ( V_12 , L_1 ) ;
return 0 ;
}
return - 1 ;
}
static void F_8 ( struct V_11 * V_12 )
{
struct V_1 * V_2 = F_6 ( V_12 ) ;
unsigned char V_14 = V_2 -> V_8 ( V_2 , V_10 ) ;
int V_15 ;
V_2 -> V_6 ( V_2 , V_16 , V_17 ) ;
for ( V_15 = 0 ; V_15 < 100 ; V_15 ++ ) {
if ( V_14 & V_18 ) {
V_2 -> V_19 . V_20 = V_21 ;
return;
}
V_2 -> V_6 ( V_2 , V_10 , V_18 ) ;
F_9 ( 10 ) ;
V_14 = V_2 -> V_8 ( V_2 , V_10 ) ;
}
F_7 ( V_12 , L_2 ) ;
}
static void F_10 ( struct V_11 * V_12 )
{
struct V_1 * V_2 = F_6 ( V_12 ) ;
unsigned char V_14 = V_2 -> V_8 ( V_2 , V_10 ) ;
T_1 V_22 = 0x00 ;
int V_15 ;
for ( V_15 = 0 ; V_15 < 100 ; V_15 ++ ) {
if ( ( V_14 & V_18 ) == 0 ) {
V_2 -> V_19 . V_20 = V_23 ;
if ( V_2 -> V_19 . V_24 & V_25 )
V_2 -> V_6 ( V_2 , V_16 , V_26 ) ;
else
V_2 -> V_6 ( V_2 , V_16 ,
V_26 & ~ V_27 ) ;
return;
}
if ( V_2 -> V_19 . V_24 & V_28 )
V_22 |= V_29 ;
if ( V_2 -> V_19 . V_24 & V_30 )
V_22 |= V_31 ;
V_2 -> V_6 ( V_2 , V_10 , V_22 ) ;
F_9 ( 10 ) ;
V_14 = V_2 -> V_8 ( V_2 , V_10 ) ;
}
F_7 ( V_12 , L_3 ) ;
}
static void F_11 ( struct V_11 * V_12 )
{
struct V_1 * V_2 = F_6 ( V_12 ) ;
V_2 -> V_6 ( V_2 , V_32 , V_2 -> V_33 | V_34 ) ;
V_2 -> V_6 ( V_2 , V_35 , 0x00 ) ;
V_2 -> V_6 ( V_2 , V_36 , 0x00 ) ;
V_2 -> V_6 ( V_2 , V_37 , 0x00 ) ;
V_2 -> V_6 ( V_2 , V_38 , 0x00 ) ;
V_2 -> V_6 ( V_2 , V_39 , 0xFF ) ;
V_2 -> V_6 ( V_2 , V_40 , 0xFF ) ;
V_2 -> V_6 ( V_2 , V_41 , 0xFF ) ;
V_2 -> V_6 ( V_2 , V_42 , 0xFF ) ;
V_2 -> V_6 ( V_2 , V_43 , V_2 -> V_44 | V_45 ) ;
}
static void F_12 ( struct V_11 * V_12 )
{
struct V_1 * V_2 = F_6 ( V_12 ) ;
if ( V_2 -> V_19 . V_20 != V_21 )
F_8 ( V_12 ) ;
if ( ! ( V_2 -> V_8 ( V_2 , V_32 ) & V_34 ) )
F_11 ( V_12 ) ;
V_2 -> V_6 ( V_2 , V_46 , 0x0 ) ;
V_2 -> V_6 ( V_2 , V_47 , 0x0 ) ;
V_2 -> V_8 ( V_2 , V_48 ) ;
V_2 -> V_8 ( V_2 , V_49 ) ;
F_10 ( V_12 ) ;
}
static int F_13 ( struct V_11 * V_12 , enum V_50 V_51 )
{
switch ( V_51 ) {
case V_52 :
F_12 ( V_12 ) ;
if ( F_14 ( V_12 ) )
F_15 ( V_12 ) ;
break;
default:
return - V_53 ;
}
return 0 ;
}
static int F_16 ( struct V_11 * V_12 )
{
struct V_1 * V_2 = F_6 ( V_12 ) ;
struct V_54 * V_55 = & V_2 -> V_19 . V_56 ;
T_1 V_57 , V_58 ;
V_57 = ( ( V_55 -> V_59 - 1 ) & 0x3f ) | ( ( ( V_55 -> V_60 - 1 ) & 0x3 ) << 6 ) ;
V_58 = ( ( V_55 -> V_61 + V_55 -> V_62 - 1 ) & 0xf ) |
( ( ( V_55 -> V_63 - 1 ) & 0x7 ) << 4 ) ;
if ( V_2 -> V_19 . V_24 & V_64 )
V_58 |= 0x80 ;
F_17 ( V_12 , L_4 , V_57 , V_58 ) ;
V_2 -> V_6 ( V_2 , V_65 , V_57 ) ;
V_2 -> V_6 ( V_2 , V_66 , V_58 ) ;
return 0 ;
}
static int F_18 ( const struct V_11 * V_12 ,
struct V_67 * V_68 )
{
struct V_1 * V_2 = F_6 ( V_12 ) ;
V_68 -> V_69 = V_2 -> V_8 ( V_2 , V_46 ) ;
V_68 -> V_70 = V_2 -> V_8 ( V_2 , V_47 ) ;
return 0 ;
}
static T_2 F_19 ( struct V_71 * V_72 ,
struct V_11 * V_12 )
{
struct V_1 * V_2 = F_6 ( V_12 ) ;
struct V_73 * V_74 = (struct V_73 * ) V_72 -> V_75 ;
T_3 V_76 ;
T_3 V_77 ;
T_4 V_78 ;
T_3 V_79 ;
T_1 V_80 = 0x00 ;
int V_15 ;
if ( F_20 ( V_12 , V_72 ) )
return V_81 ;
F_21 ( V_12 ) ;
V_76 = V_77 = V_74 -> V_82 ;
V_78 = V_74 -> V_83 ;
if ( V_78 & V_84 )
V_76 |= V_85 ;
if ( V_78 & V_86 ) {
V_76 |= V_87 ;
V_79 = V_88 ;
V_2 -> V_6 ( V_2 , V_89 , V_76 ) ;
V_2 -> V_6 ( V_2 , V_90 , ( V_78 & 0x1fe00000 ) >> 21 ) ;
V_2 -> V_6 ( V_2 , V_91 , ( V_78 & 0x001fe000 ) >> 13 ) ;
V_2 -> V_6 ( V_2 , V_92 , ( V_78 & 0x00001fe0 ) >> 5 ) ;
V_2 -> V_6 ( V_2 , V_93 , ( V_78 & 0x0000001f ) << 3 ) ;
} else {
V_79 = V_94 ;
V_2 -> V_6 ( V_2 , V_89 , V_76 ) ;
V_2 -> V_6 ( V_2 , V_90 , ( V_78 & 0x000007f8 ) >> 3 ) ;
V_2 -> V_6 ( V_2 , V_91 , ( V_78 & 0x00000007 ) << 5 ) ;
}
for ( V_15 = 0 ; V_15 < V_77 ; V_15 ++ )
V_2 -> V_6 ( V_2 , V_79 ++ , V_74 -> V_75 [ V_15 ] ) ;
F_22 ( V_72 , V_12 , 0 ) ;
if ( V_2 -> V_19 . V_24 & V_95 )
V_80 |= V_96 ;
if ( V_2 -> V_19 . V_24 & V_97 )
V_80 |= V_98 ;
else
V_80 |= V_99 ;
F_1 ( V_2 , V_80 ) ;
return V_81 ;
}
static void F_23 ( struct V_11 * V_12 )
{
struct V_1 * V_2 = F_6 ( V_12 ) ;
struct V_100 * V_101 = & V_12 -> V_101 ;
struct V_73 * V_74 ;
struct V_71 * V_72 ;
T_3 V_76 ;
T_3 V_79 ;
T_4 V_78 ;
int V_15 ;
V_72 = F_24 ( V_12 , & V_74 ) ;
if ( V_72 == NULL )
return;
V_76 = V_2 -> V_8 ( V_2 , V_89 ) ;
if ( V_76 & V_87 ) {
V_79 = V_88 ;
V_78 = ( V_2 -> V_8 ( V_2 , V_90 ) << 21 )
| ( V_2 -> V_8 ( V_2 , V_91 ) << 13 )
| ( V_2 -> V_8 ( V_2 , V_92 ) << 5 )
| ( V_2 -> V_8 ( V_2 , V_93 ) >> 3 ) ;
V_78 |= V_86 ;
} else {
V_79 = V_94 ;
V_78 = ( V_2 -> V_8 ( V_2 , V_90 ) << 3 )
| ( V_2 -> V_8 ( V_2 , V_91 ) >> 5 ) ;
}
V_74 -> V_82 = F_25 ( V_76 & 0x0F ) ;
if ( V_76 & V_85 ) {
V_78 |= V_84 ;
} else {
for ( V_15 = 0 ; V_15 < V_74 -> V_82 ; V_15 ++ )
V_74 -> V_75 [ V_15 ] = V_2 -> V_8 ( V_2 , V_79 ++ ) ;
}
V_74 -> V_83 = V_78 ;
F_1 ( V_2 , V_102 ) ;
V_101 -> V_103 ++ ;
V_101 -> V_104 += V_74 -> V_82 ;
F_26 ( V_72 ) ;
F_27 ( V_12 , V_105 ) ;
}
static int F_28 ( struct V_11 * V_12 , T_3 V_106 , T_3 V_14 )
{
struct V_1 * V_2 = F_6 ( V_12 ) ;
struct V_100 * V_101 = & V_12 -> V_101 ;
struct V_73 * V_74 ;
struct V_71 * V_72 ;
enum V_107 V_20 = V_2 -> V_19 . V_20 ;
enum V_107 V_108 , V_109 ;
unsigned int V_70 , V_69 ;
T_3 V_110 , V_111 ;
V_72 = F_29 ( V_12 , & V_74 ) ;
if ( V_72 == NULL )
return - V_112 ;
V_69 = V_2 -> V_8 ( V_2 , V_46 ) ;
V_70 = V_2 -> V_8 ( V_2 , V_47 ) ;
V_74 -> V_75 [ 6 ] = V_69 ;
V_74 -> V_75 [ 7 ] = V_70 ;
if ( V_106 & V_113 ) {
F_30 ( V_12 , L_5 ) ;
V_74 -> V_83 |= V_114 ;
V_74 -> V_75 [ 1 ] = V_115 ;
V_101 -> V_116 ++ ;
V_101 -> V_117 ++ ;
F_1 ( V_2 , V_118 ) ;
}
if ( V_106 & V_119 ) {
F_30 ( V_12 , L_6 ) ;
if ( V_14 & V_120 )
V_20 = V_121 ;
else if ( V_14 & V_122 )
V_20 = V_123 ;
else
V_20 = V_23 ;
}
if ( V_106 & V_27 ) {
V_2 -> V_19 . V_124 . V_125 ++ ;
V_101 -> V_117 ++ ;
V_110 = V_2 -> V_8 ( V_2 , V_48 ) ;
V_74 -> V_83 |= V_126 | V_127 ;
switch ( V_110 & V_128 ) {
case V_129 :
V_74 -> V_75 [ 2 ] |= V_130 ;
break;
case V_131 :
V_74 -> V_75 [ 2 ] |= V_132 ;
break;
case V_133 :
V_74 -> V_75 [ 2 ] |= V_134 ;
break;
default:
break;
}
V_74 -> V_75 [ 3 ] = V_110 & V_135 ;
if ( ( V_110 & V_136 ) == 0 )
V_74 -> V_75 [ 2 ] |= V_137 ;
}
if ( V_106 & V_138 ) {
F_30 ( V_12 , L_7 ) ;
if ( V_20 == V_139 )
V_20 = V_123 ;
else
V_20 = V_139 ;
}
if ( V_106 & V_140 ) {
F_30 ( V_12 , L_8 ) ;
V_111 = V_2 -> V_8 ( V_2 , V_141 ) ;
V_2 -> V_19 . V_124 . V_142 ++ ;
V_101 -> V_143 ++ ;
V_74 -> V_83 |= V_144 ;
V_74 -> V_75 [ 0 ] = V_111 & 0x1f ;
}
if ( V_20 != V_2 -> V_19 . V_20 ) {
V_109 = V_69 >= V_70 ? V_20 : 0 ;
V_108 = V_69 <= V_70 ? V_20 : 0 ;
F_31 ( V_12 , V_74 , V_109 , V_108 ) ;
if( V_20 == V_121 )
F_32 ( V_12 ) ;
}
V_101 -> V_103 ++ ;
V_101 -> V_104 += V_74 -> V_82 ;
F_26 ( V_72 ) ;
return 0 ;
}
T_5 F_33 ( int V_145 , void * V_146 )
{
struct V_11 * V_12 = (struct V_11 * ) V_146 ;
struct V_1 * V_2 = F_6 ( V_12 ) ;
struct V_100 * V_101 = & V_12 -> V_101 ;
T_3 V_106 , V_14 ;
int V_147 = 0 ;
if ( V_2 -> V_148 )
V_2 -> V_148 ( V_2 ) ;
if ( V_2 -> V_8 ( V_2 , V_16 ) == V_17 )
goto V_149;
while ( ( V_106 = V_2 -> V_8 ( V_2 , V_49 ) ) &&
( V_147 < V_150 ) ) {
V_14 = V_2 -> V_8 ( V_2 , V_9 ) ;
if ( V_14 == 0xFF && F_4 ( V_2 ) )
goto V_149;
if ( V_106 & V_151 )
F_34 ( V_12 , L_9 ) ;
if ( V_106 & V_152 ) {
if ( V_2 -> V_19 . V_24 & V_95 &&
! ( V_14 & V_153 ) ) {
V_101 -> V_143 ++ ;
F_35 ( V_12 , 0 ) ;
} else {
V_101 -> V_154 +=
V_2 -> V_8 ( V_2 , V_89 ) & 0xf ;
V_101 -> V_155 ++ ;
F_36 ( V_12 , 0 ) ;
}
F_15 ( V_12 ) ;
F_27 ( V_12 , V_156 ) ;
}
if ( V_106 & V_157 ) {
while ( V_14 & V_158 ) {
F_23 ( V_12 ) ;
V_14 = V_2 -> V_8 ( V_2 , V_9 ) ;
if ( V_14 == 0xFF && F_4 ( V_2 ) )
goto V_149;
}
}
if ( V_106 & ( V_113 | V_119 | V_27 | V_138 | V_140 ) ) {
if ( F_28 ( V_12 , V_106 , V_14 ) )
break;
}
V_147 ++ ;
}
V_149:
if ( V_2 -> V_159 )
V_2 -> V_159 ( V_2 ) ;
if ( V_147 >= V_150 )
F_30 ( V_12 , L_10 , V_147 ) ;
return ( V_147 ) ? V_160 : V_161 ;
}
static int F_37 ( struct V_11 * V_12 )
{
struct V_1 * V_2 = F_6 ( V_12 ) ;
int V_162 ;
F_8 ( V_12 ) ;
V_162 = F_38 ( V_12 ) ;
if ( V_162 )
return V_162 ;
if ( ! ( V_2 -> V_4 & V_163 ) ) {
V_162 = F_39 ( V_12 -> V_145 , F_33 , V_2 -> V_164 ,
V_12 -> V_165 , ( void * ) V_12 ) ;
if ( V_162 ) {
F_40 ( V_12 ) ;
return - V_166 ;
}
}
F_12 ( V_12 ) ;
F_27 ( V_12 , V_167 ) ;
F_41 ( V_12 ) ;
return 0 ;
}
static int F_42 ( struct V_11 * V_12 )
{
struct V_1 * V_2 = F_6 ( V_12 ) ;
F_21 ( V_12 ) ;
F_8 ( V_12 ) ;
if ( ! ( V_2 -> V_4 & V_163 ) )
F_43 ( V_12 -> V_145 , ( void * ) V_12 ) ;
F_40 ( V_12 ) ;
F_27 ( V_12 , V_168 ) ;
return 0 ;
}
struct V_11 * F_44 ( int V_169 )
{
struct V_11 * V_12 ;
struct V_1 * V_2 ;
V_12 = F_45 ( sizeof( struct V_1 ) + V_169 ,
V_170 ) ;
if ( ! V_12 )
return NULL ;
V_2 = F_6 ( V_12 ) ;
V_2 -> V_12 = V_12 ;
V_2 -> V_19 . V_171 = & V_172 ;
V_2 -> V_19 . V_173 = F_16 ;
V_2 -> V_19 . V_174 = F_13 ;
V_2 -> V_19 . V_175 = F_18 ;
V_2 -> V_19 . V_176 = V_97 |
V_28 |
V_64 |
V_95 |
V_25 |
V_30 ;
F_46 ( & V_2 -> V_5 ) ;
if ( V_169 )
V_2 -> V_2 = ( void * ) V_2 + sizeof( struct V_1 ) ;
return V_12 ;
}
void F_47 ( struct V_11 * V_12 )
{
F_48 ( V_12 ) ;
}
int F_49 ( struct V_11 * V_12 )
{
int V_177 ;
if ( ! F_5 ( V_12 ) )
return - V_178 ;
V_12 -> V_4 |= V_179 ;
V_12 -> V_180 = & V_181 ;
F_8 ( V_12 ) ;
F_11 ( V_12 ) ;
V_177 = F_50 ( V_12 ) ;
if ( ! V_177 )
F_51 ( V_12 ) ;
return V_177 ;
}
void F_52 ( struct V_11 * V_12 )
{
F_8 ( V_12 ) ;
F_53 ( V_12 ) ;
}
static T_6 int F_54 ( void )
{
F_55 ( V_182 L_11 , V_183 ) ;
return 0 ;
}
static T_7 void F_56 ( void )
{
F_55 ( V_182 L_12 , V_183 ) ;
}
