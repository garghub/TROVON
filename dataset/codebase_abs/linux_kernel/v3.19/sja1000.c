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
F_10 ( V_12 ) ;
}
static int F_13 ( struct V_11 * V_12 , enum V_49 V_50 )
{
switch ( V_50 ) {
case V_51 :
F_12 ( V_12 ) ;
if ( F_14 ( V_12 ) )
F_15 ( V_12 ) ;
break;
default:
return - V_52 ;
}
return 0 ;
}
static int F_16 ( struct V_11 * V_12 )
{
struct V_1 * V_2 = F_6 ( V_12 ) ;
struct V_53 * V_54 = & V_2 -> V_19 . V_55 ;
T_1 V_56 , V_57 ;
V_56 = ( ( V_54 -> V_58 - 1 ) & 0x3f ) | ( ( ( V_54 -> V_59 - 1 ) & 0x3 ) << 6 ) ;
V_57 = ( ( V_54 -> V_60 + V_54 -> V_61 - 1 ) & 0xf ) |
( ( ( V_54 -> V_62 - 1 ) & 0x7 ) << 4 ) ;
if ( V_2 -> V_19 . V_24 & V_63 )
V_57 |= 0x80 ;
F_17 ( V_12 , L_4 , V_56 , V_57 ) ;
V_2 -> V_6 ( V_2 , V_64 , V_56 ) ;
V_2 -> V_6 ( V_2 , V_65 , V_57 ) ;
return 0 ;
}
static int F_18 ( const struct V_11 * V_12 ,
struct V_66 * V_67 )
{
struct V_1 * V_2 = F_6 ( V_12 ) ;
V_67 -> V_68 = V_2 -> V_8 ( V_2 , V_46 ) ;
V_67 -> V_69 = V_2 -> V_8 ( V_2 , V_47 ) ;
return 0 ;
}
static T_2 F_19 ( struct V_70 * V_71 ,
struct V_11 * V_12 )
{
struct V_1 * V_2 = F_6 ( V_12 ) ;
struct V_72 * V_73 = (struct V_72 * ) V_71 -> V_74 ;
T_3 V_75 ;
T_3 V_76 ;
T_4 V_77 ;
T_3 V_78 ;
T_1 V_79 = 0x00 ;
int V_15 ;
if ( F_20 ( V_12 , V_71 ) )
return V_80 ;
F_21 ( V_12 ) ;
V_75 = V_76 = V_73 -> V_81 ;
V_77 = V_73 -> V_82 ;
if ( V_77 & V_83 )
V_75 |= V_84 ;
if ( V_77 & V_85 ) {
V_75 |= V_86 ;
V_78 = V_87 ;
V_2 -> V_6 ( V_2 , V_88 , V_75 ) ;
V_2 -> V_6 ( V_2 , V_89 , ( V_77 & 0x1fe00000 ) >> 21 ) ;
V_2 -> V_6 ( V_2 , V_90 , ( V_77 & 0x001fe000 ) >> 13 ) ;
V_2 -> V_6 ( V_2 , V_91 , ( V_77 & 0x00001fe0 ) >> 5 ) ;
V_2 -> V_6 ( V_2 , V_92 , ( V_77 & 0x0000001f ) << 3 ) ;
} else {
V_78 = V_93 ;
V_2 -> V_6 ( V_2 , V_88 , V_75 ) ;
V_2 -> V_6 ( V_2 , V_89 , ( V_77 & 0x000007f8 ) >> 3 ) ;
V_2 -> V_6 ( V_2 , V_90 , ( V_77 & 0x00000007 ) << 5 ) ;
}
for ( V_15 = 0 ; V_15 < V_76 ; V_15 ++ )
V_2 -> V_6 ( V_2 , V_78 ++ , V_73 -> V_74 [ V_15 ] ) ;
F_22 ( V_71 , V_12 , 0 ) ;
if ( V_2 -> V_19 . V_24 & V_94 )
V_79 |= V_95 ;
if ( V_2 -> V_19 . V_24 & V_96 )
V_79 |= V_97 ;
else
V_79 |= V_98 ;
F_1 ( V_2 , V_79 ) ;
return V_80 ;
}
static void F_23 ( struct V_11 * V_12 )
{
struct V_1 * V_2 = F_6 ( V_12 ) ;
struct V_99 * V_100 = & V_12 -> V_100 ;
struct V_72 * V_73 ;
struct V_70 * V_71 ;
T_3 V_75 ;
T_3 V_78 ;
T_4 V_77 ;
int V_15 ;
V_71 = F_24 ( V_12 , & V_73 ) ;
if ( V_71 == NULL )
return;
V_75 = V_2 -> V_8 ( V_2 , V_88 ) ;
if ( V_75 & V_86 ) {
V_78 = V_87 ;
V_77 = ( V_2 -> V_8 ( V_2 , V_89 ) << 21 )
| ( V_2 -> V_8 ( V_2 , V_90 ) << 13 )
| ( V_2 -> V_8 ( V_2 , V_91 ) << 5 )
| ( V_2 -> V_8 ( V_2 , V_92 ) >> 3 ) ;
V_77 |= V_85 ;
} else {
V_78 = V_93 ;
V_77 = ( V_2 -> V_8 ( V_2 , V_89 ) << 3 )
| ( V_2 -> V_8 ( V_2 , V_90 ) >> 5 ) ;
}
V_73 -> V_81 = F_25 ( V_75 & 0x0F ) ;
if ( V_75 & V_84 ) {
V_77 |= V_83 ;
} else {
for ( V_15 = 0 ; V_15 < V_73 -> V_81 ; V_15 ++ )
V_73 -> V_74 [ V_15 ] = V_2 -> V_8 ( V_2 , V_78 ++ ) ;
}
V_73 -> V_82 = V_77 ;
F_1 ( V_2 , V_101 ) ;
F_26 ( V_71 ) ;
V_100 -> V_102 ++ ;
V_100 -> V_103 += V_73 -> V_81 ;
F_27 ( V_12 , V_104 ) ;
}
static int F_28 ( struct V_11 * V_12 , T_3 V_105 , T_3 V_14 )
{
struct V_1 * V_2 = F_6 ( V_12 ) ;
struct V_99 * V_100 = & V_12 -> V_100 ;
struct V_72 * V_73 ;
struct V_70 * V_71 ;
enum V_106 V_20 = V_2 -> V_19 . V_20 ;
enum V_106 V_107 , V_108 ;
unsigned int V_69 , V_68 ;
T_3 V_109 , V_110 ;
V_71 = F_29 ( V_12 , & V_73 ) ;
if ( V_71 == NULL )
return - V_111 ;
V_68 = V_2 -> V_8 ( V_2 , V_46 ) ;
V_69 = V_2 -> V_8 ( V_2 , V_47 ) ;
V_73 -> V_74 [ 6 ] = V_68 ;
V_73 -> V_74 [ 7 ] = V_69 ;
if ( V_105 & V_112 ) {
F_30 ( V_12 , L_5 ) ;
V_73 -> V_82 |= V_113 ;
V_73 -> V_74 [ 1 ] = V_114 ;
V_100 -> V_115 ++ ;
V_100 -> V_116 ++ ;
F_1 ( V_2 , V_117 ) ;
}
if ( V_105 & V_118 ) {
F_30 ( V_12 , L_6 ) ;
if ( V_14 & V_119 )
V_20 = V_120 ;
else if ( V_14 & V_121 )
V_20 = V_122 ;
else
V_20 = V_23 ;
}
if ( V_105 & V_27 ) {
V_2 -> V_19 . V_123 . V_124 ++ ;
V_100 -> V_116 ++ ;
V_109 = V_2 -> V_8 ( V_2 , V_48 ) ;
V_73 -> V_82 |= V_125 | V_126 ;
switch ( V_109 & V_127 ) {
case V_128 :
V_73 -> V_74 [ 2 ] |= V_129 ;
break;
case V_130 :
V_73 -> V_74 [ 2 ] |= V_131 ;
break;
case V_132 :
V_73 -> V_74 [ 2 ] |= V_133 ;
break;
default:
V_73 -> V_74 [ 2 ] |= V_134 ;
V_73 -> V_74 [ 3 ] = V_109 & V_135 ;
break;
}
if ( ( V_109 & V_136 ) == 0 )
V_73 -> V_74 [ 2 ] |= V_137 ;
}
if ( V_105 & V_138 ) {
F_30 ( V_12 , L_7 ) ;
if ( V_20 == V_139 )
V_20 = V_122 ;
else
V_20 = V_139 ;
}
if ( V_105 & V_140 ) {
F_30 ( V_12 , L_8 ) ;
V_110 = V_2 -> V_8 ( V_2 , V_141 ) ;
V_2 -> V_19 . V_123 . V_142 ++ ;
V_100 -> V_143 ++ ;
V_73 -> V_82 |= V_144 ;
V_73 -> V_74 [ 0 ] = V_110 & 0x1f ;
}
if ( V_20 != V_2 -> V_19 . V_20 ) {
V_108 = V_68 >= V_69 ? V_20 : 0 ;
V_107 = V_68 <= V_69 ? V_20 : 0 ;
F_31 ( V_12 , V_73 , V_108 , V_107 ) ;
if( V_20 == V_120 )
F_32 ( V_12 ) ;
}
F_26 ( V_71 ) ;
V_100 -> V_102 ++ ;
V_100 -> V_103 += V_73 -> V_81 ;
return 0 ;
}
T_5 F_33 ( int V_145 , void * V_146 )
{
struct V_11 * V_12 = (struct V_11 * ) V_146 ;
struct V_1 * V_2 = F_6 ( V_12 ) ;
struct V_99 * V_100 = & V_12 -> V_100 ;
T_3 V_105 , V_14 ;
int V_147 = 0 ;
if ( V_2 -> V_148 )
V_2 -> V_148 ( V_2 ) ;
if ( V_2 -> V_8 ( V_2 , V_16 ) == V_17 )
goto V_149;
while ( ( V_105 = V_2 -> V_8 ( V_2 , V_150 ) ) &&
( V_147 < V_151 ) ) {
V_14 = V_2 -> V_8 ( V_2 , V_9 ) ;
if ( V_14 == 0xFF && F_4 ( V_2 ) )
goto V_149;
if ( V_105 & V_152 )
F_34 ( V_12 , L_9 ) ;
if ( V_105 & V_153 ) {
if ( V_2 -> V_19 . V_24 & V_94 &&
! ( V_14 & V_154 ) ) {
V_100 -> V_143 ++ ;
F_35 ( V_12 , 0 ) ;
} else {
V_100 -> V_155 +=
V_2 -> V_8 ( V_2 , V_88 ) & 0xf ;
V_100 -> V_156 ++ ;
F_36 ( V_12 , 0 ) ;
}
F_15 ( V_12 ) ;
F_27 ( V_12 , V_157 ) ;
}
if ( V_105 & V_158 ) {
while ( V_14 & V_159 ) {
F_23 ( V_12 ) ;
V_14 = V_2 -> V_8 ( V_2 , V_9 ) ;
if ( V_14 == 0xFF && F_4 ( V_2 ) )
goto V_149;
}
}
if ( V_105 & ( V_112 | V_118 | V_27 | V_138 | V_140 ) ) {
if ( F_28 ( V_12 , V_105 , V_14 ) )
break;
}
V_147 ++ ;
}
V_149:
if ( V_2 -> V_160 )
V_2 -> V_160 ( V_2 ) ;
if ( V_147 >= V_151 )
F_30 ( V_12 , L_10 , V_147 ) ;
return ( V_147 ) ? V_161 : V_162 ;
}
static int F_37 ( struct V_11 * V_12 )
{
struct V_1 * V_2 = F_6 ( V_12 ) ;
int V_163 ;
F_8 ( V_12 ) ;
V_163 = F_38 ( V_12 ) ;
if ( V_163 )
return V_163 ;
if ( ! ( V_2 -> V_4 & V_164 ) ) {
V_163 = F_39 ( V_12 -> V_145 , F_33 , V_2 -> V_165 ,
V_12 -> V_166 , ( void * ) V_12 ) ;
if ( V_163 ) {
F_40 ( V_12 ) ;
return - V_167 ;
}
}
F_12 ( V_12 ) ;
F_27 ( V_12 , V_168 ) ;
F_41 ( V_12 ) ;
return 0 ;
}
static int F_42 ( struct V_11 * V_12 )
{
struct V_1 * V_2 = F_6 ( V_12 ) ;
F_21 ( V_12 ) ;
F_8 ( V_12 ) ;
if ( ! ( V_2 -> V_4 & V_164 ) )
F_43 ( V_12 -> V_145 , ( void * ) V_12 ) ;
F_40 ( V_12 ) ;
F_27 ( V_12 , V_169 ) ;
return 0 ;
}
struct V_11 * F_44 ( int V_170 )
{
struct V_11 * V_12 ;
struct V_1 * V_2 ;
V_12 = F_45 ( sizeof( struct V_1 ) + V_170 ,
V_171 ) ;
if ( ! V_12 )
return NULL ;
V_2 = F_6 ( V_12 ) ;
V_2 -> V_12 = V_12 ;
V_2 -> V_19 . V_172 = & V_173 ;
V_2 -> V_19 . V_174 = F_16 ;
V_2 -> V_19 . V_175 = F_13 ;
V_2 -> V_19 . V_176 = F_18 ;
V_2 -> V_19 . V_177 = V_96 |
V_28 |
V_63 |
V_94 |
V_25 |
V_30 ;
F_46 ( & V_2 -> V_5 ) ;
if ( V_170 )
V_2 -> V_2 = ( void * ) V_2 + sizeof( struct V_1 ) ;
return V_12 ;
}
void F_47 ( struct V_11 * V_12 )
{
F_48 ( V_12 ) ;
}
int F_49 ( struct V_11 * V_12 )
{
int V_178 ;
if ( ! F_5 ( V_12 ) )
return - V_179 ;
V_12 -> V_4 |= V_180 ;
V_12 -> V_181 = & V_182 ;
F_8 ( V_12 ) ;
F_11 ( V_12 ) ;
V_178 = F_50 ( V_12 ) ;
if ( ! V_178 )
F_51 ( V_12 ) ;
return V_178 ;
}
void F_52 ( struct V_11 * V_12 )
{
F_8 ( V_12 ) ;
F_53 ( V_12 ) ;
}
static T_6 int F_54 ( void )
{
F_55 ( V_183 L_11 , V_184 ) ;
return 0 ;
}
static T_7 void F_56 ( void )
{
F_55 ( V_183 L_12 , V_184 ) ;
}
