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
int V_15 ;
for ( V_15 = 0 ; V_15 < 100 ; V_15 ++ ) {
if ( ( V_14 & V_18 ) == 0 ) {
V_2 -> V_19 . V_20 = V_22 ;
if ( V_2 -> V_19 . V_23 & V_24 )
V_2 -> V_6 ( V_2 , V_16 , V_25 ) ;
else
V_2 -> V_6 ( V_2 , V_16 ,
V_25 & ~ V_26 ) ;
return;
}
if ( V_2 -> V_19 . V_23 & V_27 )
V_2 -> V_6 ( V_2 , V_10 , V_28 ) ;
else
V_2 -> V_6 ( V_2 , V_10 , 0x00 ) ;
F_9 ( 10 ) ;
V_14 = V_2 -> V_8 ( V_2 , V_10 ) ;
}
F_7 ( V_12 , L_3 ) ;
}
static void F_11 ( struct V_11 * V_12 )
{
struct V_1 * V_2 = F_6 ( V_12 ) ;
if ( V_2 -> V_19 . V_20 != V_21 )
F_8 ( V_12 ) ;
V_2 -> V_6 ( V_2 , V_29 , 0x0 ) ;
V_2 -> V_6 ( V_2 , V_30 , 0x0 ) ;
V_2 -> V_8 ( V_2 , V_31 ) ;
F_10 ( V_12 ) ;
}
static int F_12 ( struct V_11 * V_12 , enum V_32 V_33 )
{
switch ( V_33 ) {
case V_34 :
F_11 ( V_12 ) ;
if ( F_13 ( V_12 ) )
F_14 ( V_12 ) ;
break;
default:
return - V_35 ;
}
return 0 ;
}
static int F_15 ( struct V_11 * V_12 )
{
struct V_1 * V_2 = F_6 ( V_12 ) ;
struct V_36 * V_37 = & V_2 -> V_19 . V_38 ;
T_1 V_39 , V_40 ;
V_39 = ( ( V_37 -> V_41 - 1 ) & 0x3f ) | ( ( ( V_37 -> V_42 - 1 ) & 0x3 ) << 6 ) ;
V_40 = ( ( V_37 -> V_43 + V_37 -> V_44 - 1 ) & 0xf ) |
( ( ( V_37 -> V_45 - 1 ) & 0x7 ) << 4 ) ;
if ( V_2 -> V_19 . V_23 & V_46 )
V_40 |= 0x80 ;
F_16 ( V_12 , L_4 , V_39 , V_40 ) ;
V_2 -> V_6 ( V_2 , V_47 , V_39 ) ;
V_2 -> V_6 ( V_2 , V_48 , V_40 ) ;
return 0 ;
}
static int F_17 ( const struct V_11 * V_12 ,
struct V_49 * V_50 )
{
struct V_1 * V_2 = F_6 ( V_12 ) ;
V_50 -> V_51 = V_2 -> V_8 ( V_2 , V_29 ) ;
V_50 -> V_52 = V_2 -> V_8 ( V_2 , V_30 ) ;
return 0 ;
}
static void F_18 ( struct V_11 * V_12 )
{
struct V_1 * V_2 = F_6 ( V_12 ) ;
V_2 -> V_6 ( V_2 , V_53 , V_2 -> V_54 | V_55 ) ;
V_2 -> V_6 ( V_2 , V_56 , 0x00 ) ;
V_2 -> V_6 ( V_2 , V_57 , 0x00 ) ;
V_2 -> V_6 ( V_2 , V_58 , 0x00 ) ;
V_2 -> V_6 ( V_2 , V_59 , 0x00 ) ;
V_2 -> V_6 ( V_2 , V_60 , 0xFF ) ;
V_2 -> V_6 ( V_2 , V_61 , 0xFF ) ;
V_2 -> V_6 ( V_2 , V_62 , 0xFF ) ;
V_2 -> V_6 ( V_2 , V_63 , 0xFF ) ;
V_2 -> V_6 ( V_2 , V_64 , V_2 -> V_65 | V_66 ) ;
}
static T_2 F_19 ( struct V_67 * V_68 ,
struct V_11 * V_12 )
{
struct V_1 * V_2 = F_6 ( V_12 ) ;
struct V_69 * V_70 = (struct V_69 * ) V_68 -> V_71 ;
T_3 V_72 ;
T_3 V_73 ;
T_4 V_74 ;
T_3 V_75 ;
int V_15 ;
if ( F_20 ( V_12 , V_68 ) )
return V_76 ;
F_21 ( V_12 ) ;
V_72 = V_73 = V_70 -> V_77 ;
V_74 = V_70 -> V_78 ;
if ( V_74 & V_79 )
V_72 |= V_80 ;
if ( V_74 & V_81 ) {
V_72 |= V_82 ;
V_75 = V_83 ;
V_2 -> V_6 ( V_2 , V_84 , V_72 ) ;
V_2 -> V_6 ( V_2 , V_85 , ( V_74 & 0x1fe00000 ) >> 21 ) ;
V_2 -> V_6 ( V_2 , V_86 , ( V_74 & 0x001fe000 ) >> 13 ) ;
V_2 -> V_6 ( V_2 , V_87 , ( V_74 & 0x00001fe0 ) >> 5 ) ;
V_2 -> V_6 ( V_2 , V_88 , ( V_74 & 0x0000001f ) << 3 ) ;
} else {
V_75 = V_89 ;
V_2 -> V_6 ( V_2 , V_84 , V_72 ) ;
V_2 -> V_6 ( V_2 , V_85 , ( V_74 & 0x000007f8 ) >> 3 ) ;
V_2 -> V_6 ( V_2 , V_86 , ( V_74 & 0x00000007 ) << 5 ) ;
}
for ( V_15 = 0 ; V_15 < V_73 ; V_15 ++ )
V_2 -> V_6 ( V_2 , V_75 ++ , V_70 -> V_71 [ V_15 ] ) ;
F_22 ( V_68 , V_12 , 0 ) ;
if ( V_2 -> V_19 . V_23 & V_90 )
F_1 ( V_2 , V_91 | V_92 ) ;
else
F_1 ( V_2 , V_91 ) ;
return V_76 ;
}
static void F_23 ( struct V_11 * V_12 )
{
struct V_1 * V_2 = F_6 ( V_12 ) ;
struct V_93 * V_94 = & V_12 -> V_94 ;
struct V_69 * V_70 ;
struct V_67 * V_68 ;
T_3 V_72 ;
T_3 V_75 ;
T_4 V_74 ;
int V_15 ;
V_68 = F_24 ( V_12 , & V_70 ) ;
if ( V_68 == NULL )
return;
V_72 = V_2 -> V_8 ( V_2 , V_84 ) ;
if ( V_72 & V_82 ) {
V_75 = V_83 ;
V_74 = ( V_2 -> V_8 ( V_2 , V_85 ) << 21 )
| ( V_2 -> V_8 ( V_2 , V_86 ) << 13 )
| ( V_2 -> V_8 ( V_2 , V_87 ) << 5 )
| ( V_2 -> V_8 ( V_2 , V_88 ) >> 3 ) ;
V_74 |= V_81 ;
} else {
V_75 = V_89 ;
V_74 = ( V_2 -> V_8 ( V_2 , V_85 ) << 3 )
| ( V_2 -> V_8 ( V_2 , V_86 ) >> 5 ) ;
}
V_70 -> V_77 = F_25 ( V_72 & 0x0F ) ;
if ( V_72 & V_80 ) {
V_74 |= V_79 ;
} else {
for ( V_15 = 0 ; V_15 < V_70 -> V_77 ; V_15 ++ )
V_70 -> V_71 [ V_15 ] = V_2 -> V_8 ( V_2 , V_75 ++ ) ;
}
V_70 -> V_78 = V_74 ;
F_1 ( V_2 , V_95 ) ;
F_26 ( V_68 ) ;
V_94 -> V_96 ++ ;
V_94 -> V_97 += V_70 -> V_77 ;
F_27 ( V_12 , V_98 ) ;
}
static int F_28 ( struct V_11 * V_12 , T_3 V_99 , T_3 V_14 )
{
struct V_1 * V_2 = F_6 ( V_12 ) ;
struct V_93 * V_94 = & V_12 -> V_94 ;
struct V_69 * V_70 ;
struct V_67 * V_68 ;
enum V_100 V_20 = V_2 -> V_19 . V_20 ;
T_3 V_101 , V_102 ;
V_68 = F_29 ( V_12 , & V_70 ) ;
if ( V_68 == NULL )
return - V_103 ;
if ( V_99 & V_104 ) {
F_30 ( V_12 , L_5 ) ;
V_70 -> V_78 |= V_105 ;
V_70 -> V_71 [ 1 ] = V_106 ;
V_94 -> V_107 ++ ;
V_94 -> V_108 ++ ;
F_1 ( V_2 , V_109 ) ;
}
if ( V_99 & V_110 ) {
F_30 ( V_12 , L_6 ) ;
if ( V_14 & V_111 ) {
V_20 = V_112 ;
V_70 -> V_78 |= V_113 ;
F_31 ( V_12 ) ;
} else if ( V_14 & V_114 ) {
V_20 = V_115 ;
} else
V_20 = V_22 ;
}
if ( V_99 & V_26 ) {
V_2 -> V_19 . V_116 . V_117 ++ ;
V_94 -> V_108 ++ ;
V_101 = V_2 -> V_8 ( V_2 , V_31 ) ;
V_70 -> V_78 |= V_118 | V_119 ;
switch ( V_101 & V_120 ) {
case V_121 :
V_70 -> V_71 [ 2 ] |= V_122 ;
break;
case V_123 :
V_70 -> V_71 [ 2 ] |= V_124 ;
break;
case V_125 :
V_70 -> V_71 [ 2 ] |= V_126 ;
break;
default:
V_70 -> V_71 [ 2 ] |= V_127 ;
V_70 -> V_71 [ 3 ] = V_101 & V_128 ;
break;
}
if ( ( V_101 & V_129 ) == 0 )
V_70 -> V_71 [ 2 ] |= V_130 ;
}
if ( V_99 & V_131 ) {
F_30 ( V_12 , L_7 ) ;
if ( V_14 & V_114 )
V_20 = V_132 ;
else
V_20 = V_22 ;
}
if ( V_99 & V_133 ) {
F_30 ( V_12 , L_8 ) ;
V_102 = V_2 -> V_8 ( V_2 , V_134 ) ;
V_2 -> V_19 . V_116 . V_135 ++ ;
V_94 -> V_136 ++ ;
V_70 -> V_78 |= V_137 ;
V_70 -> V_71 [ 0 ] = V_102 & 0x1f ;
}
if ( V_20 != V_2 -> V_19 . V_20 && ( V_20 == V_115 ||
V_20 == V_132 ) ) {
T_3 V_52 = V_2 -> V_8 ( V_2 , V_30 ) ;
T_3 V_51 = V_2 -> V_8 ( V_2 , V_29 ) ;
V_70 -> V_78 |= V_105 ;
if ( V_20 == V_115 ) {
V_2 -> V_19 . V_116 . V_138 ++ ;
V_70 -> V_71 [ 1 ] = ( V_51 > V_52 ) ?
V_139 :
V_140 ;
} else {
V_2 -> V_19 . V_116 . V_141 ++ ;
V_70 -> V_71 [ 1 ] = ( V_51 > V_52 ) ?
V_142 :
V_143 ;
}
V_70 -> V_71 [ 6 ] = V_51 ;
V_70 -> V_71 [ 7 ] = V_52 ;
}
V_2 -> V_19 . V_20 = V_20 ;
F_26 ( V_68 ) ;
V_94 -> V_96 ++ ;
V_94 -> V_97 += V_70 -> V_77 ;
return 0 ;
}
T_5 F_32 ( int V_144 , void * V_145 )
{
struct V_11 * V_12 = (struct V_11 * ) V_145 ;
struct V_1 * V_2 = F_6 ( V_12 ) ;
struct V_93 * V_94 = & V_12 -> V_94 ;
T_3 V_99 , V_14 ;
int V_146 = 0 ;
if ( V_2 -> V_147 )
V_2 -> V_147 ( V_2 ) ;
if ( V_2 -> V_8 ( V_2 , V_16 ) == V_17 )
goto V_148;
while ( ( V_99 = V_2 -> V_8 ( V_2 , V_149 ) ) &&
( V_146 < V_150 ) ) {
V_14 = V_2 -> V_8 ( V_2 , V_9 ) ;
if ( V_14 == 0xFF && F_4 ( V_2 ) )
goto V_148;
if ( V_99 & V_151 )
F_33 ( V_12 , L_9 ) ;
if ( V_99 & V_152 ) {
if ( V_2 -> V_19 . V_23 & V_90 &&
! ( V_14 & V_153 ) ) {
V_94 -> V_136 ++ ;
F_34 ( V_12 , 0 ) ;
} else {
V_94 -> V_154 +=
V_2 -> V_8 ( V_2 , V_84 ) & 0xf ;
V_94 -> V_155 ++ ;
F_35 ( V_12 , 0 ) ;
}
F_14 ( V_12 ) ;
F_27 ( V_12 , V_156 ) ;
}
if ( V_99 & V_157 ) {
while ( V_14 & V_158 ) {
F_23 ( V_12 ) ;
V_14 = V_2 -> V_8 ( V_2 , V_9 ) ;
if ( V_14 == 0xFF && F_4 ( V_2 ) )
goto V_148;
}
}
if ( V_99 & ( V_104 | V_110 | V_26 | V_131 | V_133 ) ) {
if ( F_28 ( V_12 , V_99 , V_14 ) )
break;
}
V_146 ++ ;
}
V_148:
if ( V_2 -> V_159 )
V_2 -> V_159 ( V_2 ) ;
if ( V_146 >= V_150 )
F_30 ( V_12 , L_10 , V_146 ) ;
return ( V_146 ) ? V_160 : V_161 ;
}
static int F_36 ( struct V_11 * V_12 )
{
struct V_1 * V_2 = F_6 ( V_12 ) ;
int V_162 ;
F_8 ( V_12 ) ;
V_162 = F_37 ( V_12 ) ;
if ( V_162 )
return V_162 ;
if ( ! ( V_2 -> V_4 & V_163 ) ) {
V_162 = F_38 ( V_12 -> V_144 , F_32 , V_2 -> V_164 ,
V_12 -> V_165 , ( void * ) V_12 ) ;
if ( V_162 ) {
F_39 ( V_12 ) ;
return - V_166 ;
}
}
F_11 ( V_12 ) ;
F_27 ( V_12 , V_167 ) ;
F_40 ( V_12 ) ;
return 0 ;
}
static int F_41 ( struct V_11 * V_12 )
{
struct V_1 * V_2 = F_6 ( V_12 ) ;
F_21 ( V_12 ) ;
F_8 ( V_12 ) ;
if ( ! ( V_2 -> V_4 & V_163 ) )
F_42 ( V_12 -> V_144 , ( void * ) V_12 ) ;
F_39 ( V_12 ) ;
F_27 ( V_12 , V_168 ) ;
return 0 ;
}
struct V_11 * F_43 ( int V_169 )
{
struct V_11 * V_12 ;
struct V_1 * V_2 ;
V_12 = F_44 ( sizeof( struct V_1 ) + V_169 ,
V_170 ) ;
if ( ! V_12 )
return NULL ;
V_2 = F_6 ( V_12 ) ;
V_2 -> V_12 = V_12 ;
V_2 -> V_19 . V_171 = & V_172 ;
V_2 -> V_19 . V_173 = F_15 ;
V_2 -> V_19 . V_174 = F_12 ;
V_2 -> V_19 . V_175 = F_17 ;
V_2 -> V_19 . V_176 = V_46 |
V_24 | V_27 |
V_90 ;
F_45 ( & V_2 -> V_5 ) ;
if ( V_169 )
V_2 -> V_2 = ( void * ) V_2 + sizeof( struct V_1 ) ;
return V_12 ;
}
void F_46 ( struct V_11 * V_12 )
{
F_47 ( V_12 ) ;
}
int F_48 ( struct V_11 * V_12 )
{
int V_177 ;
if ( ! F_5 ( V_12 ) )
return - V_178 ;
V_12 -> V_4 |= V_179 ;
V_12 -> V_180 = & V_181 ;
F_8 ( V_12 ) ;
F_18 ( V_12 ) ;
V_177 = F_49 ( V_12 ) ;
if ( ! V_177 )
F_50 ( V_12 ) ;
return V_177 ;
}
void F_51 ( struct V_11 * V_12 )
{
F_8 ( V_12 ) ;
F_52 ( V_12 ) ;
}
static T_6 int F_53 ( void )
{
F_54 ( V_182 L_11 , V_183 ) ;
return 0 ;
}
static T_7 void F_55 ( void )
{
F_54 ( V_182 L_12 , V_183 ) ;
}
