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
switch ( V_36 ) {
case V_37 :
F_12 ( V_12 ) ;
if ( F_14 ( V_12 ) )
F_15 ( V_12 ) ;
break;
default:
return - V_38 ;
}
return 0 ;
}
static int F_16 ( struct V_11 * V_12 )
{
struct V_1 * V_2 = F_6 ( V_12 ) ;
struct V_39 * V_40 = & V_2 -> V_22 . V_41 ;
T_1 V_42 , V_43 ;
V_42 = ( ( V_40 -> V_44 - 1 ) & 0x3f ) | ( ( ( V_40 -> V_45 - 1 ) & 0x3 ) << 6 ) ;
V_43 = ( ( V_40 -> V_46 + V_40 -> V_47 - 1 ) & 0xf ) |
( ( ( V_40 -> V_48 - 1 ) & 0x7 ) << 4 ) ;
if ( V_2 -> V_22 . V_26 & V_49 )
V_43 |= 0x80 ;
F_17 ( V_12 , L_4 , V_42 , V_43 ) ;
V_2 -> V_6 ( V_2 , V_50 , V_42 ) ;
V_2 -> V_6 ( V_2 , V_51 , V_43 ) ;
return 0 ;
}
static int F_18 ( const struct V_11 * V_12 ,
struct V_52 * V_53 )
{
struct V_1 * V_2 = F_6 ( V_12 ) ;
V_53 -> V_54 = V_2 -> V_8 ( V_2 , V_32 ) ;
V_53 -> V_55 = V_2 -> V_8 ( V_2 , V_33 ) ;
return 0 ;
}
static void F_19 ( struct V_11 * V_12 )
{
struct V_1 * V_2 = F_6 ( V_12 ) ;
V_2 -> V_6 ( V_2 , V_56 , V_2 -> V_57 | V_58 ) ;
V_2 -> V_6 ( V_2 , V_59 , 0x00 ) ;
V_2 -> V_6 ( V_2 , V_60 , 0x00 ) ;
V_2 -> V_6 ( V_2 , V_61 , 0x00 ) ;
V_2 -> V_6 ( V_2 , V_62 , 0x00 ) ;
V_2 -> V_6 ( V_2 , V_63 , 0xFF ) ;
V_2 -> V_6 ( V_2 , V_64 , 0xFF ) ;
V_2 -> V_6 ( V_2 , V_65 , 0xFF ) ;
V_2 -> V_6 ( V_2 , V_66 , 0xFF ) ;
V_2 -> V_6 ( V_2 , V_67 , V_2 -> V_68 | V_69 ) ;
}
static T_2 F_20 ( struct V_70 * V_71 ,
struct V_11 * V_12 )
{
struct V_1 * V_2 = F_6 ( V_12 ) ;
struct V_72 * V_73 = (struct V_72 * ) V_71 -> V_74 ;
T_3 V_75 ;
T_3 V_76 ;
T_4 V_77 ;
T_3 V_78 ;
int V_18 ;
if ( F_21 ( V_12 , V_71 ) )
return V_79 ;
F_22 ( V_12 ) ;
V_75 = V_76 = V_73 -> V_80 ;
V_77 = V_73 -> V_81 ;
if ( V_77 & V_82 )
V_75 |= V_83 ;
if ( V_77 & V_84 ) {
V_75 |= V_85 ;
V_78 = V_86 ;
V_2 -> V_6 ( V_2 , V_87 , V_75 ) ;
V_2 -> V_6 ( V_2 , V_88 , ( V_77 & 0x1fe00000 ) >> 21 ) ;
V_2 -> V_6 ( V_2 , V_89 , ( V_77 & 0x001fe000 ) >> 13 ) ;
V_2 -> V_6 ( V_2 , V_90 , ( V_77 & 0x00001fe0 ) >> 5 ) ;
V_2 -> V_6 ( V_2 , V_91 , ( V_77 & 0x0000001f ) << 3 ) ;
} else {
V_78 = V_92 ;
V_2 -> V_6 ( V_2 , V_87 , V_75 ) ;
V_2 -> V_6 ( V_2 , V_88 , ( V_77 & 0x000007f8 ) >> 3 ) ;
V_2 -> V_6 ( V_2 , V_89 , ( V_77 & 0x00000007 ) << 5 ) ;
}
for ( V_18 = 0 ; V_18 < V_76 ; V_18 ++ )
V_2 -> V_6 ( V_2 , V_78 ++ , V_73 -> V_74 [ V_18 ] ) ;
F_23 ( V_71 , V_12 , 0 ) ;
if ( V_2 -> V_22 . V_26 & V_93 )
F_1 ( V_2 , V_94 | V_95 ) ;
else
F_1 ( V_2 , V_94 ) ;
return V_79 ;
}
static void F_24 ( struct V_11 * V_12 )
{
struct V_1 * V_2 = F_6 ( V_12 ) ;
struct V_96 * V_97 = & V_12 -> V_97 ;
struct V_72 * V_73 ;
struct V_70 * V_71 ;
T_3 V_75 ;
T_3 V_78 ;
T_4 V_77 ;
int V_18 ;
V_71 = F_25 ( V_12 , & V_73 ) ;
if ( V_71 == NULL )
return;
V_75 = V_2 -> V_8 ( V_2 , V_87 ) ;
if ( V_75 & V_85 ) {
V_78 = V_86 ;
V_77 = ( V_2 -> V_8 ( V_2 , V_88 ) << 21 )
| ( V_2 -> V_8 ( V_2 , V_89 ) << 13 )
| ( V_2 -> V_8 ( V_2 , V_90 ) << 5 )
| ( V_2 -> V_8 ( V_2 , V_91 ) >> 3 ) ;
V_77 |= V_84 ;
} else {
V_78 = V_92 ;
V_77 = ( V_2 -> V_8 ( V_2 , V_88 ) << 3 )
| ( V_2 -> V_8 ( V_2 , V_89 ) >> 5 ) ;
}
V_73 -> V_80 = F_26 ( V_75 & 0x0F ) ;
if ( V_75 & V_83 ) {
V_77 |= V_82 ;
} else {
for ( V_18 = 0 ; V_18 < V_73 -> V_80 ; V_18 ++ )
V_73 -> V_74 [ V_18 ] = V_2 -> V_8 ( V_2 , V_78 ++ ) ;
}
V_73 -> V_81 = V_77 ;
F_1 ( V_2 , V_98 ) ;
F_27 ( V_71 ) ;
V_97 -> V_99 ++ ;
V_97 -> V_100 += V_73 -> V_80 ;
F_28 ( V_12 , V_101 ) ;
}
static int F_29 ( struct V_11 * V_12 , T_3 V_102 , T_3 V_17 )
{
struct V_1 * V_2 = F_6 ( V_12 ) ;
struct V_96 * V_97 = & V_12 -> V_97 ;
struct V_72 * V_73 ;
struct V_70 * V_71 ;
enum V_103 V_23 = V_2 -> V_22 . V_23 ;
T_3 V_104 , V_105 ;
V_71 = F_30 ( V_12 , & V_73 ) ;
if ( V_71 == NULL )
return - V_106 ;
if ( V_102 & V_107 ) {
F_31 ( V_12 , L_5 ) ;
V_73 -> V_81 |= V_108 ;
V_73 -> V_74 [ 1 ] = V_109 ;
V_97 -> V_110 ++ ;
V_97 -> V_111 ++ ;
F_1 ( V_2 , V_112 ) ;
}
if ( V_102 & V_113 ) {
F_31 ( V_12 , L_6 ) ;
if ( V_17 & V_114 ) {
V_23 = V_115 ;
V_73 -> V_81 |= V_116 ;
F_32 ( V_12 ) ;
} else if ( V_17 & V_117 ) {
V_23 = V_118 ;
} else
V_23 = V_25 ;
}
if ( V_102 & V_29 ) {
V_2 -> V_22 . V_119 . V_120 ++ ;
V_97 -> V_111 ++ ;
V_104 = V_2 -> V_8 ( V_2 , V_34 ) ;
V_73 -> V_81 |= V_121 | V_122 ;
switch ( V_104 & V_123 ) {
case V_124 :
V_73 -> V_74 [ 2 ] |= V_125 ;
break;
case V_126 :
V_73 -> V_74 [ 2 ] |= V_127 ;
break;
case V_128 :
V_73 -> V_74 [ 2 ] |= V_129 ;
break;
default:
V_73 -> V_74 [ 2 ] |= V_130 ;
V_73 -> V_74 [ 3 ] = V_104 & V_131 ;
break;
}
if ( ( V_104 & V_132 ) == 0 )
V_73 -> V_74 [ 2 ] |= V_133 ;
}
if ( V_102 & V_134 ) {
F_31 ( V_12 , L_7 ) ;
if ( V_17 & V_117 )
V_23 = V_135 ;
else
V_23 = V_25 ;
}
if ( V_102 & V_136 ) {
F_31 ( V_12 , L_8 ) ;
V_105 = V_2 -> V_8 ( V_2 , V_137 ) ;
V_2 -> V_22 . V_119 . V_138 ++ ;
V_97 -> V_139 ++ ;
V_73 -> V_81 |= V_140 ;
V_73 -> V_74 [ 0 ] = V_105 & 0x1f ;
}
if ( V_23 != V_2 -> V_22 . V_23 && ( V_23 == V_118 ||
V_23 == V_135 ) ) {
T_3 V_55 = V_2 -> V_8 ( V_2 , V_33 ) ;
T_3 V_54 = V_2 -> V_8 ( V_2 , V_32 ) ;
V_73 -> V_81 |= V_108 ;
if ( V_23 == V_118 ) {
V_2 -> V_22 . V_119 . V_141 ++ ;
V_73 -> V_74 [ 1 ] = ( V_54 > V_55 ) ?
V_142 :
V_143 ;
} else {
V_2 -> V_22 . V_119 . V_144 ++ ;
V_73 -> V_74 [ 1 ] = ( V_54 > V_55 ) ?
V_145 :
V_146 ;
}
V_73 -> V_74 [ 6 ] = V_54 ;
V_73 -> V_74 [ 7 ] = V_55 ;
}
V_2 -> V_22 . V_23 = V_23 ;
F_27 ( V_71 ) ;
V_97 -> V_99 ++ ;
V_97 -> V_100 += V_73 -> V_80 ;
return 0 ;
}
T_5 F_33 ( int V_147 , void * V_148 )
{
struct V_11 * V_12 = (struct V_11 * ) V_148 ;
struct V_1 * V_2 = F_6 ( V_12 ) ;
struct V_96 * V_97 = & V_12 -> V_97 ;
T_3 V_102 , V_17 ;
int V_149 = 0 ;
if ( V_2 -> V_8 ( V_2 , V_19 ) == V_20 )
return V_150 ;
if ( V_2 -> V_151 )
V_2 -> V_151 ( V_2 ) ;
while ( ( V_102 = V_2 -> V_8 ( V_2 , V_152 ) ) &&
( V_149 < V_153 ) ) {
V_149 ++ ;
V_17 = V_2 -> V_8 ( V_2 , V_9 ) ;
if ( V_17 == 0xFF && F_4 ( V_2 ) )
return V_150 ;
if ( V_102 & V_154 )
F_34 ( V_12 , L_9 ) ;
if ( V_102 & V_155 ) {
if ( V_2 -> V_22 . V_26 & V_93 &&
! ( V_17 & V_156 ) ) {
V_97 -> V_139 ++ ;
F_35 ( V_12 , 0 ) ;
} else {
V_97 -> V_157 +=
V_2 -> V_8 ( V_2 , V_87 ) & 0xf ;
V_97 -> V_158 ++ ;
F_36 ( V_12 , 0 ) ;
}
F_15 ( V_12 ) ;
F_28 ( V_12 , V_159 ) ;
}
if ( V_102 & V_160 ) {
while ( V_17 & V_161 ) {
F_24 ( V_12 ) ;
V_17 = V_2 -> V_8 ( V_2 , V_9 ) ;
if ( V_17 == 0xFF && F_4 ( V_2 ) )
return V_150 ;
}
}
if ( V_102 & ( V_107 | V_113 | V_29 | V_134 | V_136 ) ) {
if ( F_29 ( V_12 , V_102 , V_17 ) )
break;
}
}
if ( V_2 -> V_162 )
V_2 -> V_162 ( V_2 ) ;
if ( V_149 >= V_153 )
F_31 ( V_12 , L_10 , V_149 ) ;
return ( V_149 ) ? V_163 : V_150 ;
}
static int F_37 ( struct V_11 * V_12 )
{
struct V_1 * V_2 = F_6 ( V_12 ) ;
int V_164 ;
F_8 ( V_12 ) ;
V_164 = F_38 ( V_12 ) ;
if ( V_164 )
return V_164 ;
if ( ! ( V_2 -> V_4 & V_165 ) ) {
V_164 = F_39 ( V_12 -> V_147 , F_33 , V_2 -> V_166 ,
V_12 -> V_167 , ( void * ) V_12 ) ;
if ( V_164 ) {
F_40 ( V_12 ) ;
return - V_168 ;
}
}
F_12 ( V_12 ) ;
F_28 ( V_12 , V_169 ) ;
F_41 ( V_12 ) ;
return 0 ;
}
static int F_42 ( struct V_11 * V_12 )
{
struct V_1 * V_2 = F_6 ( V_12 ) ;
F_22 ( V_12 ) ;
F_8 ( V_12 ) ;
if ( ! ( V_2 -> V_4 & V_165 ) )
F_43 ( V_12 -> V_147 , ( void * ) V_12 ) ;
F_40 ( V_12 ) ;
F_28 ( V_12 , V_170 ) ;
return 0 ;
}
struct V_11 * F_44 ( int V_171 )
{
struct V_11 * V_12 ;
struct V_1 * V_2 ;
V_12 = F_45 ( sizeof( struct V_1 ) + V_171 ,
V_172 ) ;
if ( ! V_12 )
return NULL ;
V_2 = F_6 ( V_12 ) ;
V_2 -> V_12 = V_12 ;
V_2 -> V_22 . V_173 = & V_174 ;
V_2 -> V_22 . V_175 = F_16 ;
V_2 -> V_22 . V_176 = F_13 ;
V_2 -> V_22 . V_177 = F_18 ;
V_2 -> V_22 . V_178 = V_49 |
V_27 | V_30 |
V_93 ;
F_46 ( & V_2 -> V_5 ) ;
if ( V_171 )
V_2 -> V_2 = ( void * ) V_2 + sizeof( struct V_1 ) ;
return V_12 ;
}
void F_47 ( struct V_11 * V_12 )
{
F_48 ( V_12 ) ;
}
int F_49 ( struct V_11 * V_12 )
{
int V_179 ;
if ( ! F_5 ( V_12 ) )
return - V_180 ;
V_12 -> V_4 |= V_181 ;
V_12 -> V_182 = & V_183 ;
F_8 ( V_12 ) ;
F_19 ( V_12 ) ;
V_179 = F_50 ( V_12 ) ;
if ( ! V_179 )
F_51 ( V_12 ) ;
return V_179 ;
}
void F_52 ( struct V_11 * V_12 )
{
F_8 ( V_12 ) ;
F_53 ( V_12 ) ;
}
static T_6 int F_54 ( void )
{
F_7 ( V_14 L_11 , V_15 ) ;
return 0 ;
}
static T_7 void F_55 ( void )
{
F_7 ( V_14 L_12 , V_15 ) ;
}
