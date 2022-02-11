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
F_7 ( V_14 L_1 ,
V_15 , V_12 -> V_16 ) ;
return 0 ;
}
return - 1 ;
}
static void F_8 ( struct V_11 * V_12 )
{
struct V_1 * V_2 = F_6 ( V_12 ) ;
unsigned char V_17 = V_2 -> V_8 ( V_2 , V_10 ) ;
int V_18 ;
V_2 -> V_6 ( V_2 , V_19 , V_20 ) ;
for ( V_18 = 0 ; V_18 < 100 ; V_18 ++ ) {
if ( V_17 & V_21 ) {
V_2 -> V_22 . V_23 = V_24 ;
return;
}
V_2 -> V_6 ( V_2 , V_10 , V_21 ) ;
F_9 ( 10 ) ;
V_17 = V_2 -> V_8 ( V_2 , V_10 ) ;
}
F_10 ( V_12 , L_2 ) ;
}
static void F_11 ( struct V_11 * V_12 )
{
struct V_1 * V_2 = F_6 ( V_12 ) ;
unsigned char V_17 = V_2 -> V_8 ( V_2 , V_10 ) ;
int V_18 ;
for ( V_18 = 0 ; V_18 < 100 ; V_18 ++ ) {
if ( ( V_17 & V_21 ) == 0 ) {
V_2 -> V_22 . V_23 = V_25 ;
if ( V_2 -> V_22 . V_26 & V_27 )
V_2 -> V_6 ( V_2 , V_19 , V_28 ) ;
else
V_2 -> V_6 ( V_2 , V_19 ,
V_28 & ~ V_29 ) ;
return;
}
if ( V_2 -> V_22 . V_26 & V_30 )
V_2 -> V_6 ( V_2 , V_10 , V_31 ) ;
else
V_2 -> V_6 ( V_2 , V_10 , 0x00 ) ;
F_9 ( 10 ) ;
V_17 = V_2 -> V_8 ( V_2 , V_10 ) ;
}
F_10 ( V_12 , L_3 ) ;
}
static void F_12 ( struct V_11 * V_12 )
{
struct V_1 * V_2 = F_6 ( V_12 ) ;
if ( V_2 -> V_22 . V_23 != V_24 )
F_8 ( V_12 ) ;
V_2 -> V_6 ( V_2 , V_32 , 0x0 ) ;
V_2 -> V_6 ( V_2 , V_33 , 0x0 ) ;
V_2 -> V_8 ( V_2 , V_34 ) ;
F_11 ( V_12 ) ;
}
static int F_13 ( struct V_11 * V_12 , enum V_35 V_36 )
{
struct V_1 * V_2 = F_6 ( V_12 ) ;
if ( ! V_2 -> V_37 )
return - V_38 ;
switch ( V_36 ) {
case V_39 :
F_12 ( V_12 ) ;
if ( F_14 ( V_12 ) )
F_15 ( V_12 ) ;
break;
default:
return - V_40 ;
}
return 0 ;
}
static int F_16 ( struct V_11 * V_12 )
{
struct V_1 * V_2 = F_6 ( V_12 ) ;
struct V_41 * V_42 = & V_2 -> V_22 . V_43 ;
T_1 V_44 , V_45 ;
V_44 = ( ( V_42 -> V_46 - 1 ) & 0x3f ) | ( ( ( V_42 -> V_47 - 1 ) & 0x3 ) << 6 ) ;
V_45 = ( ( V_42 -> V_48 + V_42 -> V_49 - 1 ) & 0xf ) |
( ( ( V_42 -> V_50 - 1 ) & 0x7 ) << 4 ) ;
if ( V_2 -> V_22 . V_26 & V_51 )
V_45 |= 0x80 ;
F_17 ( V_12 , L_4 , V_44 , V_45 ) ;
V_2 -> V_6 ( V_2 , V_52 , V_44 ) ;
V_2 -> V_6 ( V_2 , V_53 , V_45 ) ;
return 0 ;
}
static int F_18 ( const struct V_11 * V_12 ,
struct V_54 * V_55 )
{
struct V_1 * V_2 = F_6 ( V_12 ) ;
V_55 -> V_56 = V_2 -> V_8 ( V_2 , V_32 ) ;
V_55 -> V_57 = V_2 -> V_8 ( V_2 , V_33 ) ;
return 0 ;
}
static void F_19 ( struct V_11 * V_12 )
{
struct V_1 * V_2 = F_6 ( V_12 ) ;
V_2 -> V_6 ( V_2 , V_58 , V_2 -> V_59 | V_60 ) ;
V_2 -> V_6 ( V_2 , V_61 , 0x00 ) ;
V_2 -> V_6 ( V_2 , V_62 , 0x00 ) ;
V_2 -> V_6 ( V_2 , V_63 , 0x00 ) ;
V_2 -> V_6 ( V_2 , V_64 , 0x00 ) ;
V_2 -> V_6 ( V_2 , V_65 , 0xFF ) ;
V_2 -> V_6 ( V_2 , V_66 , 0xFF ) ;
V_2 -> V_6 ( V_2 , V_67 , 0xFF ) ;
V_2 -> V_6 ( V_2 , V_68 , 0xFF ) ;
V_2 -> V_6 ( V_2 , V_69 , V_2 -> V_70 | V_71 ) ;
}
static T_2 F_20 ( struct V_72 * V_73 ,
struct V_11 * V_12 )
{
struct V_1 * V_2 = F_6 ( V_12 ) ;
struct V_74 * V_75 = (struct V_74 * ) V_73 -> V_76 ;
T_3 V_77 ;
T_3 V_78 ;
T_4 V_79 ;
T_3 V_80 ;
int V_18 ;
if ( F_21 ( V_12 , V_73 ) )
return V_81 ;
F_22 ( V_12 ) ;
V_77 = V_78 = V_75 -> V_82 ;
V_79 = V_75 -> V_83 ;
if ( V_79 & V_84 )
V_77 |= V_85 ;
if ( V_79 & V_86 ) {
V_77 |= V_87 ;
V_80 = V_88 ;
V_2 -> V_6 ( V_2 , V_89 , V_77 ) ;
V_2 -> V_6 ( V_2 , V_90 , ( V_79 & 0x1fe00000 ) >> ( 5 + 16 ) ) ;
V_2 -> V_6 ( V_2 , V_91 , ( V_79 & 0x001fe000 ) >> ( 5 + 8 ) ) ;
V_2 -> V_6 ( V_2 , V_92 , ( V_79 & 0x00001fe0 ) >> 5 ) ;
V_2 -> V_6 ( V_2 , V_93 , ( V_79 & 0x0000001f ) << 3 ) ;
} else {
V_80 = V_94 ;
V_2 -> V_6 ( V_2 , V_89 , V_77 ) ;
V_2 -> V_6 ( V_2 , V_90 , ( V_79 & 0x000007f8 ) >> 3 ) ;
V_2 -> V_6 ( V_2 , V_91 , ( V_79 & 0x00000007 ) << 5 ) ;
}
for ( V_18 = 0 ; V_18 < V_78 ; V_18 ++ )
V_2 -> V_6 ( V_2 , V_80 ++ , V_75 -> V_76 [ V_18 ] ) ;
F_23 ( V_73 , V_12 , 0 ) ;
if ( V_2 -> V_22 . V_26 & V_95 )
F_1 ( V_2 , V_96 | V_97 ) ;
else
F_1 ( V_2 , V_96 ) ;
return V_81 ;
}
static void F_24 ( struct V_11 * V_12 )
{
struct V_1 * V_2 = F_6 ( V_12 ) ;
struct V_98 * V_99 = & V_12 -> V_99 ;
struct V_74 * V_75 ;
struct V_72 * V_73 ;
T_3 V_77 ;
T_3 V_80 ;
T_4 V_79 ;
int V_18 ;
V_73 = F_25 ( V_12 , & V_75 ) ;
if ( V_73 == NULL )
return;
V_77 = V_2 -> V_8 ( V_2 , V_89 ) ;
if ( V_77 & V_87 ) {
V_80 = V_88 ;
V_79 = ( V_2 -> V_8 ( V_2 , V_90 ) << ( 5 + 16 ) )
| ( V_2 -> V_8 ( V_2 , V_91 ) << ( 5 + 8 ) )
| ( V_2 -> V_8 ( V_2 , V_92 ) << 5 )
| ( V_2 -> V_8 ( V_2 , V_93 ) >> 3 ) ;
V_79 |= V_86 ;
} else {
V_80 = V_94 ;
V_79 = ( V_2 -> V_8 ( V_2 , V_90 ) << 3 )
| ( V_2 -> V_8 ( V_2 , V_91 ) >> 5 ) ;
}
V_75 -> V_82 = F_26 ( V_77 & 0x0F ) ;
if ( V_77 & V_85 ) {
V_79 |= V_84 ;
} else {
for ( V_18 = 0 ; V_18 < V_75 -> V_82 ; V_18 ++ )
V_75 -> V_76 [ V_18 ] = V_2 -> V_8 ( V_2 , V_80 ++ ) ;
}
V_75 -> V_83 = V_79 ;
F_1 ( V_2 , V_100 ) ;
F_27 ( V_73 ) ;
V_99 -> V_101 ++ ;
V_99 -> V_102 += V_75 -> V_82 ;
}
static int F_28 ( struct V_11 * V_12 , T_3 V_103 , T_3 V_17 )
{
struct V_1 * V_2 = F_6 ( V_12 ) ;
struct V_98 * V_99 = & V_12 -> V_99 ;
struct V_74 * V_75 ;
struct V_72 * V_73 ;
enum V_104 V_23 = V_2 -> V_22 . V_23 ;
T_3 V_105 , V_106 ;
V_73 = F_29 ( V_12 , & V_75 ) ;
if ( V_73 == NULL )
return - V_107 ;
if ( V_103 & V_108 ) {
F_30 ( V_12 , L_5 ) ;
V_75 -> V_83 |= V_109 ;
V_75 -> V_76 [ 1 ] = V_110 ;
V_99 -> V_111 ++ ;
V_99 -> V_112 ++ ;
F_1 ( V_2 , V_113 ) ;
}
if ( V_103 & V_114 ) {
F_30 ( V_12 , L_6 ) ;
if ( V_17 & V_115 ) {
V_23 = V_116 ;
V_75 -> V_83 |= V_117 ;
F_31 ( V_12 ) ;
} else if ( V_17 & V_118 ) {
V_23 = V_119 ;
} else
V_23 = V_25 ;
}
if ( V_103 & V_29 ) {
V_2 -> V_22 . V_120 . V_121 ++ ;
V_99 -> V_112 ++ ;
V_105 = V_2 -> V_8 ( V_2 , V_34 ) ;
V_75 -> V_83 |= V_122 | V_123 ;
switch ( V_105 & V_124 ) {
case V_125 :
V_75 -> V_76 [ 2 ] |= V_126 ;
break;
case V_127 :
V_75 -> V_76 [ 2 ] |= V_128 ;
break;
case V_129 :
V_75 -> V_76 [ 2 ] |= V_130 ;
break;
default:
V_75 -> V_76 [ 2 ] |= V_131 ;
V_75 -> V_76 [ 3 ] = V_105 & V_132 ;
break;
}
if ( ( V_105 & V_133 ) == 0 )
V_75 -> V_76 [ 2 ] |= V_134 ;
}
if ( V_103 & V_135 ) {
F_30 ( V_12 , L_7 ) ;
if ( V_17 & V_118 )
V_23 = V_136 ;
else
V_23 = V_25 ;
}
if ( V_103 & V_137 ) {
F_30 ( V_12 , L_8 ) ;
V_106 = V_2 -> V_8 ( V_2 , V_138 ) ;
V_2 -> V_22 . V_120 . V_139 ++ ;
V_99 -> V_140 ++ ;
V_75 -> V_83 |= V_141 ;
V_75 -> V_76 [ 0 ] = V_106 & 0x1f ;
}
if ( V_23 != V_2 -> V_22 . V_23 && ( V_23 == V_119 ||
V_23 == V_136 ) ) {
T_3 V_57 = V_2 -> V_8 ( V_2 , V_33 ) ;
T_3 V_56 = V_2 -> V_8 ( V_2 , V_32 ) ;
V_75 -> V_83 |= V_109 ;
if ( V_23 == V_119 ) {
V_2 -> V_22 . V_120 . V_142 ++ ;
V_75 -> V_76 [ 1 ] = ( V_56 > V_57 ) ?
V_143 :
V_144 ;
} else {
V_2 -> V_22 . V_120 . V_145 ++ ;
V_75 -> V_76 [ 1 ] = ( V_56 > V_57 ) ?
V_146 :
V_147 ;
}
V_75 -> V_76 [ 6 ] = V_56 ;
V_75 -> V_76 [ 7 ] = V_57 ;
}
V_2 -> V_22 . V_23 = V_23 ;
F_27 ( V_73 ) ;
V_99 -> V_101 ++ ;
V_99 -> V_102 += V_75 -> V_82 ;
return 0 ;
}
T_5 F_32 ( int V_148 , void * V_149 )
{
struct V_11 * V_12 = (struct V_11 * ) V_149 ;
struct V_1 * V_2 = F_6 ( V_12 ) ;
struct V_98 * V_99 = & V_12 -> V_99 ;
T_3 V_103 , V_17 ;
int V_150 = 0 ;
if ( V_2 -> V_8 ( V_2 , V_19 ) == V_20 )
return V_151 ;
if ( V_2 -> V_152 )
V_2 -> V_152 ( V_2 ) ;
while ( ( V_103 = V_2 -> V_8 ( V_2 , V_153 ) ) && ( V_150 < V_154 ) ) {
V_150 ++ ;
V_17 = V_2 -> V_8 ( V_2 , V_9 ) ;
if ( V_17 == 0xFF && F_4 ( V_2 ) )
return V_151 ;
if ( V_103 & V_155 )
F_33 ( V_12 , L_9 ) ;
if ( V_103 & V_156 ) {
if ( V_2 -> V_22 . V_26 & V_95 &&
! ( V_17 & V_157 ) ) {
V_99 -> V_140 ++ ;
F_34 ( V_12 , 0 ) ;
} else {
V_99 -> V_158 +=
V_2 -> V_8 ( V_2 , V_89 ) & 0xf ;
V_99 -> V_159 ++ ;
F_35 ( V_12 , 0 ) ;
}
F_15 ( V_12 ) ;
}
if ( V_103 & V_160 ) {
while ( V_17 & V_161 ) {
F_24 ( V_12 ) ;
V_17 = V_2 -> V_8 ( V_2 , V_9 ) ;
if ( V_17 == 0xFF && F_4 ( V_2 ) )
return V_151 ;
}
}
if ( V_103 & ( V_108 | V_114 | V_29 | V_135 | V_137 ) ) {
if ( F_28 ( V_12 , V_103 , V_17 ) )
break;
}
}
if ( V_2 -> V_162 )
V_2 -> V_162 ( V_2 ) ;
if ( V_150 >= V_154 )
F_30 ( V_12 , L_10 , V_150 ) ;
return ( V_150 ) ? V_163 : V_151 ;
}
static int F_36 ( struct V_11 * V_12 )
{
struct V_1 * V_2 = F_6 ( V_12 ) ;
int V_164 ;
F_8 ( V_12 ) ;
V_164 = F_37 ( V_12 ) ;
if ( V_164 )
return V_164 ;
if ( ! ( V_2 -> V_4 & V_165 ) ) {
V_164 = F_38 ( V_12 -> V_148 , F_32 , V_2 -> V_166 ,
V_12 -> V_167 , ( void * ) V_12 ) ;
if ( V_164 ) {
F_39 ( V_12 ) ;
return - V_168 ;
}
}
F_12 ( V_12 ) ;
V_2 -> V_37 = V_169 ;
F_40 ( V_12 ) ;
return 0 ;
}
static int F_41 ( struct V_11 * V_12 )
{
struct V_1 * V_2 = F_6 ( V_12 ) ;
F_22 ( V_12 ) ;
F_8 ( V_12 ) ;
if ( ! ( V_2 -> V_4 & V_165 ) )
F_42 ( V_12 -> V_148 , ( void * ) V_12 ) ;
F_39 ( V_12 ) ;
V_2 -> V_37 = 0 ;
return 0 ;
}
struct V_11 * F_43 ( int V_170 )
{
struct V_11 * V_12 ;
struct V_1 * V_2 ;
V_12 = F_44 ( sizeof( struct V_1 ) + V_170 ,
V_171 ) ;
if ( ! V_12 )
return NULL ;
V_2 = F_6 ( V_12 ) ;
V_2 -> V_12 = V_12 ;
V_2 -> V_22 . V_172 = & V_173 ;
V_2 -> V_22 . V_174 = F_16 ;
V_2 -> V_22 . V_175 = F_13 ;
V_2 -> V_22 . V_176 = F_18 ;
V_2 -> V_22 . V_177 = V_51 |
V_27 | V_30 |
V_95 ;
F_45 ( & V_2 -> V_5 ) ;
if ( V_170 )
V_2 -> V_2 = ( void * ) V_2 + sizeof( struct V_1 ) ;
return V_12 ;
}
void F_46 ( struct V_11 * V_12 )
{
F_47 ( V_12 ) ;
}
int F_48 ( struct V_11 * V_12 )
{
if ( ! F_5 ( V_12 ) )
return - V_178 ;
V_12 -> V_4 |= V_179 ;
V_12 -> V_180 = & V_181 ;
F_8 ( V_12 ) ;
F_19 ( V_12 ) ;
return F_49 ( V_12 ) ;
}
void F_50 ( struct V_11 * V_12 )
{
F_8 ( V_12 ) ;
F_51 ( V_12 ) ;
}
static T_6 int F_52 ( void )
{
F_7 ( V_14 L_11 , V_15 ) ;
return 0 ;
}
static T_7 void F_53 ( void )
{
F_7 ( V_14 L_12 , V_15 ) ;
}
