static T_1 F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
if ( V_2 == & V_4 -> V_5 . V_2 [ 0 ] )
return F_2 ( F_3 ( V_6 , 0 , V_7 ) ) ;
else if ( V_2 == & V_4 -> V_5 . V_2 [ 1 ] )
return F_2 ( F_3 ( V_6 , 0 , V_8 ) ) ;
else
return F_2 ( F_3 ( V_6 , 0 , V_9 ) ) ;
}
static T_1 F_4 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
if ( V_2 -> V_10 )
return V_4 -> V_11 . V_11 [ V_2 -> V_12 ] ;
if ( V_2 == & V_4 -> V_5 . V_2 [ 0 ] )
return F_2 ( F_3 ( V_6 , 0 , V_13 ) ) ;
else if ( V_2 == & V_4 -> V_5 . V_2 [ 1 ] )
return F_2 ( F_3 ( V_6 , 0 , V_14 ) ) ;
else
return F_2 ( F_3 ( V_6 , 0 , V_15 ) ) ;
}
static void F_5 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
if ( V_2 -> V_10 ) {
V_4 -> V_11 . V_11 [ V_2 -> V_12 ] = F_6 ( V_2 -> V_16 ) ;
F_7 ( V_2 -> V_17 , F_6 ( V_2 -> V_16 ) ) ;
return;
}
if ( V_2 == & V_4 -> V_5 . V_2 [ 0 ] )
F_8 ( F_3 ( V_6 , 0 , V_13 ) ,
F_6 ( V_2 -> V_16 ) ) ;
else if ( V_2 == & V_4 -> V_5 . V_2 [ 1 ] )
F_8 ( F_3 ( V_6 , 0 , V_14 ) ,
F_6 ( V_2 -> V_16 ) ) ;
else
F_8 ( F_3 ( V_6 , 0 , V_15 ) ,
F_6 ( V_2 -> V_16 ) ) ;
}
static int F_9 ( struct V_3 * V_4 )
{
int V_18 , V_19 ;
for ( V_18 = 0 ; V_18 < 10 ; ++ V_18 ) {
for ( V_19 = 0 ; V_19 < 100 ; ++ V_19 ) {
T_2 V_20 =
F_2 ( F_3 ( V_6 , 0 , V_21 ) ) ;
if ( V_20 & V_22 )
return 0 ;
F_10 ( 10 ) ;
}
F_11 ( L_1 ) ;
F_12 ( F_3 ( V_6 , 0 , V_23 ) ,
V_24 ,
~ V_24 ) ;
F_10 ( 10 ) ;
F_12 ( F_3 ( V_6 , 0 , V_23 ) , 0 ,
~ V_24 ) ;
F_10 ( 10 ) ;
}
return - V_25 ;
}
static int F_13 ( struct V_3 * V_4 ,
struct V_26 * V_27 )
{
T_2 V_28 = 0 , V_29 ;
T_1 V_30 = V_27 -> V_31 ;
struct V_32 * V_33 = (struct V_32 * ) V_27 -> V_34 ;
T_2 V_35 ;
V_35 = V_33 -> V_36 + V_33 -> V_37 + V_33 -> V_38 ;
F_8 ( F_3 ( V_6 , 0 , V_39 ) , F_6 ( V_30 ) ) ;
F_8 ( F_3 ( V_6 , 0 , V_40 ) , F_14 ( V_30 ) ) ;
V_28 = F_2 ( F_3 ( V_6 , 0 , V_41 ) ) ;
V_28 &= ~ V_42 ;
V_28 |= ( 0 << V_43 ) ;
F_8 ( F_3 ( V_6 , 0 , V_41 ) , V_28 ) ;
F_8 ( F_3 ( V_6 , 0 , V_44 ) , V_35 ) ;
F_8 ( F_3 ( V_6 , 0 , V_45 ) , 0 ) ;
F_8 ( F_3 ( V_6 , 0 , V_46 ) , 0x10000001 ) ;
V_28 = F_2 ( F_3 ( V_6 , 0 , V_45 ) ) ;
V_29 = 1000 ;
while ( ( V_28 & 0x10000002 ) != 0x10000002 ) {
F_15 ( 10 ) ;
V_28 = F_2 ( F_3 ( V_6 , 0 , V_45 ) ) ;
V_29 -- ;
if ( ! V_29 )
break;
}
if ( ! V_29 ) {
F_16 ( V_4 -> V_47 , L_2 , V_28 ) ;
return - V_48 ;
}
return 0 ;
}
static int F_17 ( struct V_3 * V_4 )
{
struct V_1 * V_2 ;
T_2 V_49 , V_35 ;
T_2 V_50 = 0 ;
struct V_51 V_52 = { { 0 } } ;
struct V_53 V_54 = { { 0 } } ;
struct V_55 V_56 = { { 0 } } ;
struct V_57 V_58 = { { 0 } } ;
T_2 * V_59 = V_4 -> V_60 . V_61 . V_34 ;
struct V_32 * V_33 = (struct V_32 * ) V_59 ;
V_52 . V_62 . V_63 = V_64 ;
V_54 . V_62 . V_63 = V_65 ;
V_56 . V_62 . V_63 = V_66 ;
V_58 . V_62 . V_63 = V_67 ;
if ( V_33 -> V_68 == 0 && V_33 -> V_37 == 0 ) {
V_33 -> V_69 = V_70 ;
V_33 -> V_36 = sizeof( struct V_32 ) >> 2 ;
if ( V_33 -> V_71 == 0 && V_33 -> V_38 == 0 )
V_33 -> V_68 = V_33 -> V_36 ;
else
V_33 -> V_68 = V_33 -> V_38 + V_33 -> V_71 ;
V_59 += V_33 -> V_68 ;
V_2 = & V_4 -> V_5 . V_2 [ 0 ] ;
F_18 ( F_3 ( V_6 , 0 , V_72 ) ,
F_6 ( V_2 -> V_31 ) ) ;
F_18 ( F_3 ( V_6 , 0 , V_73 ) ,
F_14 ( V_2 -> V_31 ) ) ;
F_18 ( F_3 ( V_6 , 0 , V_74 ) ,
V_2 -> V_75 / 4 ) ;
F_18 ( F_3 ( V_6 , 0 , V_76 ) , 0x398000 ) ;
F_19 ( F_3 ( V_6 , 0 , V_77 ) , ~ 0x1 , 0 ) ;
F_18 ( F_3 ( V_6 , 0 , V_78 ) , 0 ) ;
F_18 ( F_3 ( V_6 , 0 , V_79 ) , 0 ) ;
F_18 ( F_3 ( V_6 , 0 , V_80 ) , 0 ) ;
if ( V_4 -> V_81 . V_82 == V_83 ) {
F_18 ( F_3 ( V_6 , 0 , V_84 ) ,
V_4 -> V_81 . V_85 [ V_86 ] . V_87 >> 8 ) ;
F_18 ( F_3 ( V_6 , 0 , V_88 ) ,
V_4 -> V_81 . V_85 [ V_86 ] . V_87 >> 8 ) ;
F_18 ( F_3 ( V_6 , 0 , V_89 ) ,
V_4 -> V_81 . V_85 [ V_86 ] . V_87 >> 8 ) ;
} else {
F_18 ( F_3 ( V_6 , 0 , V_84 ) ,
V_4 -> V_5 . V_31 >> 8 ) ;
F_18 ( F_3 ( V_6 , 0 , V_88 ) ,
V_4 -> V_5 . V_31 >> 8 ) ;
F_18 ( F_3 ( V_6 , 0 , V_89 ) ,
V_4 -> V_5 . V_31 >> 8 ) ;
}
V_49 = V_90 ;
V_35 = V_91 ;
F_18 ( F_3 ( V_6 , 0 , V_92 ) ,
V_49 & 0x7FFFFFFF ) ;
F_18 ( F_3 ( V_6 , 0 , V_93 ) , V_35 ) ;
V_49 += V_35 ;
V_35 = V_94 ;
F_18 ( F_3 ( V_6 , 0 , V_95 ) ,
V_49 & 0x7FFFFFFF ) ;
F_18 ( F_3 ( V_6 , 0 , V_96 ) , V_35 ) ;
V_49 += V_35 ;
V_35 = V_97 ;
F_18 ( F_3 ( V_6 , 0 , V_98 ) ,
V_49 & 0x7FFFFFFF ) ;
F_18 ( F_3 ( V_6 , 0 , V_99 ) , V_35 ) ;
F_19 ( F_3 ( V_6 , 0 , V_100 ) , ~ 0x100 , 0 ) ;
F_19 ( F_3 ( V_6 , 0 , V_101 ) ,
0xffffffff , V_102 ) ;
F_19 ( F_3 ( V_6 , 0 , V_21 ) ,
V_103 , ~ V_103 ) ;
F_19 ( F_3 ( V_6 , 0 , V_104 ) ,
~ 0x200001 , V_105 ) ;
F_19 ( F_3 ( V_6 , 0 , V_23 ) ,
~ V_24 , 0 ) ;
F_20 ( F_3 ( V_6 , 0 , V_21 ) ,
V_22 ,
V_22 ) ;
F_19 ( F_3 ( V_6 , 0 , V_21 ) ,
~ V_103 , 0 ) ;
memcpy ( ( void * ) V_59 , & V_58 , sizeof( struct V_57 ) ) ;
V_50 += sizeof( struct V_57 ) / 4 ;
V_33 -> V_37 = V_50 ;
return F_13 ( V_4 , & V_4 -> V_60 . V_61 ) ;
}
return - V_106 ;
}
static int F_21 ( struct V_3 * V_4 )
{
struct V_1 * V_2 ;
int V_107 ;
V_2 = & V_4 -> V_5 . V_2 [ 0 ] ;
F_8 ( F_3 ( V_6 , 0 , V_7 ) , F_6 ( V_2 -> V_16 ) ) ;
F_8 ( F_3 ( V_6 , 0 , V_13 ) , F_6 ( V_2 -> V_16 ) ) ;
F_8 ( F_3 ( V_6 , 0 , V_72 ) , V_2 -> V_31 ) ;
F_8 ( F_3 ( V_6 , 0 , V_73 ) , F_14 ( V_2 -> V_31 ) ) ;
F_8 ( F_3 ( V_6 , 0 , V_74 ) , V_2 -> V_75 / 4 ) ;
V_2 = & V_4 -> V_5 . V_2 [ 1 ] ;
F_8 ( F_3 ( V_6 , 0 , V_8 ) , F_6 ( V_2 -> V_16 ) ) ;
F_8 ( F_3 ( V_6 , 0 , V_14 ) , F_6 ( V_2 -> V_16 ) ) ;
F_8 ( F_3 ( V_6 , 0 , V_108 ) , V_2 -> V_31 ) ;
F_8 ( F_3 ( V_6 , 0 , V_109 ) , F_14 ( V_2 -> V_31 ) ) ;
F_8 ( F_3 ( V_6 , 0 , V_110 ) , V_2 -> V_75 / 4 ) ;
V_2 = & V_4 -> V_5 . V_2 [ 2 ] ;
F_8 ( F_3 ( V_6 , 0 , V_9 ) , F_6 ( V_2 -> V_16 ) ) ;
F_8 ( F_3 ( V_6 , 0 , V_15 ) , F_6 ( V_2 -> V_16 ) ) ;
F_8 ( F_3 ( V_6 , 0 , V_111 ) , V_2 -> V_31 ) ;
F_8 ( F_3 ( V_6 , 0 , V_112 ) , F_14 ( V_2 -> V_31 ) ) ;
F_8 ( F_3 ( V_6 , 0 , V_113 ) , V_2 -> V_75 / 4 ) ;
F_22 ( V_4 ) ;
F_12 ( F_3 ( V_6 , 0 , V_21 ) , V_103 ,
~ V_103 ) ;
F_12 ( F_3 ( V_6 , 0 , V_104 ) , 1 , ~ 0x200001 ) ;
F_12 ( F_3 ( V_6 , 0 , V_23 ) , 0 ,
~ V_24 ) ;
F_10 ( 100 ) ;
V_107 = F_9 ( V_4 ) ;
F_12 ( F_3 ( V_6 , 0 , V_21 ) , 0 , ~ V_103 ) ;
if ( V_107 ) {
F_11 ( L_3 ) ;
return V_107 ;
}
return 0 ;
}
static int F_23 ( struct V_3 * V_4 )
{
F_12 ( F_3 ( V_6 , 0 , V_104 ) , 0 , ~ 0x200001 ) ;
F_12 ( F_3 ( V_6 , 0 , V_23 ) ,
V_24 ,
~ V_24 ) ;
F_12 ( F_3 ( V_6 , 0 , V_21 ) , 0 , ~ V_103 ) ;
return 0 ;
}
static int F_24 ( void * V_114 )
{
struct V_3 * V_4 = (struct V_3 * ) V_114 ;
if ( F_25 ( V_4 ) )
V_4 -> V_5 . V_115 = 1 ;
else
V_4 -> V_5 . V_115 = 3 ;
F_26 ( V_4 ) ;
F_27 ( V_4 ) ;
return 0 ;
}
static int F_28 ( void * V_114 )
{
struct V_3 * V_4 = (struct V_3 * ) V_114 ;
struct V_1 * V_2 ;
unsigned V_35 ;
int V_107 , V_18 ;
V_107 = F_29 ( V_4 , V_116 , 167 , & V_4 -> V_5 . V_117 ) ;
if ( V_107 )
return V_107 ;
V_35 = ( V_94 + V_97 ) * 2 ;
if ( V_4 -> V_81 . V_82 != V_83 )
V_35 += V_91 ;
V_107 = F_30 ( V_4 , V_35 ) ;
if ( V_107 )
return V_107 ;
if ( V_4 -> V_81 . V_82 == V_83 ) {
const struct V_118 * V_119 ;
V_119 = ( const struct V_118 * ) V_4 -> V_5 . V_120 -> V_28 ;
V_4 -> V_81 . V_85 [ V_86 ] . V_121 = V_86 ;
V_4 -> V_81 . V_85 [ V_86 ] . V_120 = V_4 -> V_5 . V_120 ;
V_4 -> V_81 . V_122 +=
F_31 ( F_32 ( V_119 -> V_123 ) , V_124 ) ;
F_33 ( L_4 ) ;
}
if ( V_4 -> V_81 . V_82 != V_83 ) {
V_107 = F_34 ( V_4 ) ;
if ( V_107 )
return V_107 ;
}
for ( V_18 = 0 ; V_18 < V_4 -> V_5 . V_115 ; V_18 ++ ) {
V_2 = & V_4 -> V_5 . V_2 [ V_18 ] ;
sprintf ( V_2 -> V_125 , L_5 , V_18 ) ;
if ( F_25 ( V_4 ) ) {
V_2 -> V_10 = true ;
if ( V_18 == 0 )
V_2 -> V_17 = V_126 * 2 ;
else if ( V_18 == 1 )
V_2 -> V_17 = V_127 * 2 ;
else
V_2 -> V_17 = V_127 * 2 + 1 ;
}
V_107 = F_35 ( V_4 , V_2 , 512 , & V_4 -> V_5 . V_117 , 0 ) ;
if ( V_107 )
return V_107 ;
}
V_107 = F_36 ( V_4 ) ;
if ( V_107 )
return V_107 ;
return V_107 ;
}
static int F_37 ( void * V_114 )
{
int V_107 ;
struct V_3 * V_4 = (struct V_3 * ) V_114 ;
F_38 ( V_4 ) ;
V_107 = F_39 ( V_4 ) ;
if ( V_107 )
return V_107 ;
return F_40 ( V_4 ) ;
}
static int F_41 ( void * V_114 )
{
int V_107 , V_18 ;
struct V_3 * V_4 = (struct V_3 * ) V_114 ;
if ( F_25 ( V_4 ) )
V_107 = F_17 ( V_4 ) ;
else
V_107 = F_21 ( V_4 ) ;
if ( V_107 )
return V_107 ;
for ( V_18 = 0 ; V_18 < V_4 -> V_5 . V_115 ; V_18 ++ )
V_4 -> V_5 . V_2 [ V_18 ] . V_128 = false ;
for ( V_18 = 0 ; V_18 < V_4 -> V_5 . V_115 ; V_18 ++ ) {
V_107 = F_42 ( & V_4 -> V_5 . V_2 [ V_18 ] ) ;
if ( V_107 )
return V_107 ;
else
V_4 -> V_5 . V_2 [ V_18 ] . V_128 = true ;
}
F_33 ( L_6 ) ;
return 0 ;
}
static int F_43 ( void * V_114 )
{
struct V_3 * V_4 = (struct V_3 * ) V_114 ;
int V_18 ;
F_23 ( V_4 ) ;
for ( V_18 = 0 ; V_18 < V_4 -> V_5 . V_115 ; V_18 ++ )
V_4 -> V_5 . V_2 [ V_18 ] . V_128 = false ;
return 0 ;
}
static int F_44 ( void * V_114 )
{
int V_107 ;
struct V_3 * V_4 = (struct V_3 * ) V_114 ;
V_107 = F_43 ( V_4 ) ;
if ( V_107 )
return V_107 ;
return F_39 ( V_4 ) ;
}
static int F_45 ( void * V_114 )
{
int V_107 ;
struct V_3 * V_4 = (struct V_3 * ) V_114 ;
V_107 = F_34 ( V_4 ) ;
if ( V_107 )
return V_107 ;
return F_41 ( V_4 ) ;
}
static void F_22 ( struct V_3 * V_4 )
{
T_2 V_49 , V_35 ;
F_12 ( F_3 ( V_6 , 0 , V_129 ) , 0 , ~ ( 1 << 16 ) ) ;
F_12 ( F_3 ( V_6 , 0 , V_130 ) , 0x1FF000 , ~ 0xFF9FF000 ) ;
F_12 ( F_3 ( V_6 , 0 , V_131 ) , 0x3F , ~ 0x3F ) ;
F_8 ( F_3 ( V_6 , 0 , V_132 ) , 0x1FF ) ;
F_8 ( F_3 ( V_6 , 0 , V_76 ) , 0x00398000 ) ;
F_12 ( F_3 ( V_6 , 0 , V_77 ) , 0x0 , ~ 0x1 ) ;
F_8 ( F_3 ( V_6 , 0 , V_78 ) , 0 ) ;
F_8 ( F_3 ( V_6 , 0 , V_79 ) , 0 ) ;
F_8 ( F_3 ( V_6 , 0 , V_80 ) , 0 ) ;
if ( V_4 -> V_81 . V_82 == V_83 ) {
F_8 ( F_3 ( V_6 , 0 , V_84 ) ,
( V_4 -> V_81 . V_85 [ V_86 ] . V_87 >> 8 ) ) ;
F_8 ( F_3 ( V_6 , 0 , V_133 ) ,
( V_4 -> V_81 . V_85 [ V_86 ] . V_87 >> 40 ) & 0xff ) ;
} else {
F_8 ( F_3 ( V_6 , 0 , V_84 ) ,
( V_4 -> V_5 . V_31 >> 8 ) ) ;
F_8 ( F_3 ( V_6 , 0 , V_133 ) ,
( V_4 -> V_5 . V_31 >> 40 ) & 0xff ) ;
}
V_49 = V_90 ;
V_35 = V_91 ;
F_8 ( F_3 ( V_6 , 0 , V_92 ) , V_49 & ~ 0x0f000000 ) ;
F_8 ( F_3 ( V_6 , 0 , V_93 ) , V_35 ) ;
F_8 ( F_3 ( V_6 , 0 , V_88 ) , ( V_4 -> V_5 . V_31 >> 8 ) ) ;
F_8 ( F_3 ( V_6 , 0 , V_134 ) , ( V_4 -> V_5 . V_31 >> 40 ) & 0xff ) ;
V_49 = ( V_4 -> V_81 . V_82 != V_83 ) ? V_49 + V_35 : 0 ;
V_35 = V_94 ;
F_8 ( F_3 ( V_6 , 0 , V_95 ) , ( V_49 & ~ 0x0f000000 ) | ( 1 << 24 ) ) ;
F_8 ( F_3 ( V_6 , 0 , V_96 ) , V_35 ) ;
F_8 ( F_3 ( V_6 , 0 , V_89 ) , ( V_4 -> V_5 . V_31 >> 8 ) ) ;
F_8 ( F_3 ( V_6 , 0 , V_135 ) , ( V_4 -> V_5 . V_31 >> 40 ) & 0xff ) ;
V_49 += V_35 ;
V_35 = V_97 ;
F_8 ( F_3 ( V_6 , 0 , V_98 ) , ( V_49 & ~ 0x0f000000 ) | ( 2 << 24 ) ) ;
F_8 ( F_3 ( V_6 , 0 , V_99 ) , V_35 ) ;
F_12 ( F_3 ( V_6 , 0 , V_100 ) , 0x0 , ~ 0x100 ) ;
F_12 ( F_3 ( V_6 , 0 , V_101 ) ,
V_102 ,
~ V_102 ) ;
}
static int F_46 ( void * V_114 ,
enum V_136 V_137 )
{
return 0 ;
}
static void F_47 ( struct V_1 * V_2 ,
struct V_138 * V_139 , unsigned int V_140 , bool V_141 )
{
F_48 ( V_2 , V_142 ) ;
F_48 ( V_2 , V_140 ) ;
F_48 ( V_2 , F_6 ( V_139 -> V_31 ) ) ;
F_48 ( V_2 , F_14 ( V_139 -> V_31 ) ) ;
F_48 ( V_2 , V_139 -> V_143 ) ;
}
static void F_49 ( struct V_1 * V_2 , T_3 V_30 ,
T_3 V_144 , unsigned V_145 )
{
F_50 ( V_145 & V_146 ) ;
F_48 ( V_2 , V_147 ) ;
F_48 ( V_2 , V_30 ) ;
F_48 ( V_2 , F_14 ( V_30 ) ) ;
F_48 ( V_2 , V_144 ) ;
F_48 ( V_2 , V_148 ) ;
}
static void F_51 ( struct V_1 * V_2 )
{
F_48 ( V_2 , V_149 ) ;
}
static void F_52 ( struct V_1 * V_2 ,
unsigned int V_140 , T_1 V_150 )
{
struct V_151 * V_152 = & V_2 -> V_4 -> V_153 [ V_2 -> V_154 -> V_153 ] ;
T_2 V_155 = V_2 -> V_4 -> V_156 . V_157 -> V_158 ( V_140 ) ;
unsigned V_159 = V_2 -> V_160 ;
V_150 = V_150 | 0x1 ;
F_53 ( V_150 & 0xFFFF00000000003EULL ) ;
F_48 ( V_2 , V_161 ) ;
F_48 ( V_2 , ( V_152 -> V_162 + V_140 * 2 ) << 2 ) ;
F_48 ( V_2 , F_14 ( V_150 ) ) ;
F_48 ( V_2 , V_161 ) ;
F_48 ( V_2 , ( V_152 -> V_163 + V_140 * 2 ) << 2 ) ;
F_48 ( V_2 , F_6 ( V_150 ) ) ;
F_48 ( V_2 , V_164 ) ;
F_48 ( V_2 , ( V_152 -> V_163 + V_140 * 2 ) << 2 ) ;
F_48 ( V_2 , 0xffffffff ) ;
F_48 ( V_2 , F_6 ( V_150 ) ) ;
F_48 ( V_2 , V_161 ) ;
F_48 ( V_2 , ( V_152 -> V_165 + V_159 ) << 2 ) ;
F_48 ( V_2 , V_155 ) ;
F_48 ( V_2 , V_164 ) ;
F_48 ( V_2 , ( V_152 -> V_166 + V_159 ) << 2 ) ;
F_48 ( V_2 , 1 << V_140 ) ;
F_48 ( V_2 , 1 << V_140 ) ;
}
static int F_54 ( struct V_3 * V_4 ,
struct V_167 * V_168 ,
unsigned type ,
enum V_169 V_137 )
{
T_2 V_170 = 0 ;
if ( V_137 == V_171 )
V_170 |= V_102 ;
F_12 ( F_3 ( V_6 , 0 , V_101 ) , V_170 ,
~ V_102 ) ;
return 0 ;
}
static int F_55 ( struct V_3 * V_4 ,
struct V_167 * V_168 ,
struct V_172 * V_173 )
{
F_56 ( L_7 ) ;
F_12 ( F_3 ( V_6 , 0 , V_174 ) ,
V_175 ,
~ V_175 ) ;
switch ( V_173 -> V_176 [ 0 ] ) {
case 0 :
case 1 :
case 2 :
F_57 ( & V_4 -> V_5 . V_2 [ V_173 -> V_176 [ 0 ] ] ) ;
break;
default:
F_11 ( L_8 ,
V_173 -> V_177 , V_173 -> V_176 [ 0 ] ) ;
break;
}
return 0 ;
}
static void F_26 ( struct V_3 * V_4 )
{
int V_18 ;
for ( V_18 = 0 ; V_18 < V_4 -> V_5 . V_115 ; V_18 ++ )
V_4 -> V_5 . V_2 [ V_18 ] . V_154 = & V_178 ;
F_33 ( L_9 ) ;
}
static void F_27 ( struct V_3 * V_4 )
{
V_4 -> V_5 . V_117 . V_179 = 1 ;
V_4 -> V_5 . V_117 . V_154 = & V_180 ;
}
