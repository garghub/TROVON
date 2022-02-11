static T_1 F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
if ( V_2 == & V_4 -> V_5 . V_2 [ 0 ] )
return F_2 ( V_6 ) ;
else if ( V_2 == & V_4 -> V_5 . V_2 [ 1 ] )
return F_2 ( V_7 ) ;
else
return F_2 ( V_8 ) ;
}
static T_1 F_3 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
if ( V_2 == & V_4 -> V_5 . V_2 [ 0 ] )
return F_2 ( V_9 ) ;
else if ( V_2 == & V_4 -> V_5 . V_2 [ 1 ] )
return F_2 ( V_10 ) ;
else
return F_2 ( V_11 ) ;
}
static void F_4 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
if ( V_2 == & V_4 -> V_5 . V_2 [ 0 ] )
F_5 ( V_9 , V_2 -> V_12 ) ;
else if ( V_2 == & V_4 -> V_5 . V_2 [ 1 ] )
F_5 ( V_10 , V_2 -> V_12 ) ;
else
F_5 ( V_11 , V_2 -> V_12 ) ;
}
static void F_6 ( struct V_3 * V_4 , bool V_13 )
{
F_7 ( V_14 , V_15 , V_13 ? 1 : 0 ) ;
}
static void F_8 ( struct V_3 * V_4 ,
bool V_16 )
{
T_2 V_17 ;
F_6 ( V_4 , true ) ;
if ( V_16 ) {
V_17 = F_2 ( V_18 ) ;
V_17 |= 0x1ff ;
V_17 &= ~ 0xef0000 ;
F_5 ( V_18 , V_17 ) ;
V_17 = F_2 ( V_19 ) ;
V_17 |= 0x3ff000 ;
V_17 &= ~ 0xffc00000 ;
F_5 ( V_19 , V_17 ) ;
V_17 = F_2 ( V_20 ) ;
V_17 |= 0x2 ;
V_17 &= ~ 0x00010000 ;
F_5 ( V_20 , V_17 ) ;
V_17 = F_2 ( V_21 ) ;
V_17 |= 0x37f ;
F_5 ( V_21 , V_17 ) ;
V_17 = F_2 ( V_22 ) ;
V_17 |= V_23 |
V_24 |
V_25 |
0x8 ;
F_5 ( V_22 , V_17 ) ;
} else {
V_17 = F_2 ( V_18 ) ;
V_17 &= ~ 0x80010 ;
V_17 |= 0xe70008 ;
F_5 ( V_18 , V_17 ) ;
V_17 = F_2 ( V_19 ) ;
V_17 |= 0xffc00000 ;
F_5 ( V_19 , V_17 ) ;
V_17 = F_2 ( V_20 ) ;
V_17 |= 0x10000 ;
F_5 ( V_20 , V_17 ) ;
V_17 = F_2 ( V_21 ) ;
V_17 &= ~ 0xffc00000 ;
F_5 ( V_21 , V_17 ) ;
V_17 = F_2 ( V_22 ) ;
V_17 &= ~ ( V_23 |
V_24 |
V_25 |
0x8 ) ;
F_5 ( V_22 , V_17 ) ;
}
F_6 ( V_4 , false ) ;
}
static int F_9 ( struct V_3 * V_4 )
{
int V_26 , V_27 ;
for ( V_26 = 0 ; V_26 < 10 ; ++ V_26 ) {
for ( V_27 = 0 ; V_27 < 100 ; ++ V_27 ) {
T_1 V_28 = F_2 ( V_29 ) ;
if ( V_28 & V_30 )
return 0 ;
F_10 ( 10 ) ;
}
F_11 ( L_1 ) ;
F_7 ( V_31 , V_32 , 1 ) ;
F_10 ( 10 ) ;
F_7 ( V_31 , V_32 , 0 ) ;
F_10 ( 10 ) ;
}
return - V_33 ;
}
static int F_12 ( struct V_3 * V_4 )
{
struct V_1 * V_2 ;
int V_34 , V_35 ;
V_2 = & V_4 -> V_5 . V_2 [ 0 ] ;
F_5 ( V_6 , V_2 -> V_12 ) ;
F_5 ( V_9 , V_2 -> V_12 ) ;
F_5 ( V_36 , V_2 -> V_37 ) ;
F_5 ( V_38 , F_13 ( V_2 -> V_37 ) ) ;
F_5 ( V_39 , V_2 -> V_40 / 4 ) ;
V_2 = & V_4 -> V_5 . V_2 [ 1 ] ;
F_5 ( V_7 , V_2 -> V_12 ) ;
F_5 ( V_10 , V_2 -> V_12 ) ;
F_5 ( V_41 , V_2 -> V_37 ) ;
F_5 ( V_42 , F_13 ( V_2 -> V_37 ) ) ;
F_5 ( V_43 , V_2 -> V_40 / 4 ) ;
V_2 = & V_4 -> V_5 . V_2 [ 2 ] ;
F_5 ( V_8 , V_2 -> V_12 ) ;
F_5 ( V_11 , V_2 -> V_12 ) ;
F_5 ( V_44 , V_2 -> V_37 ) ;
F_5 ( V_45 , F_13 ( V_2 -> V_37 ) ) ;
F_5 ( V_46 , V_2 -> V_40 / 4 ) ;
F_14 ( & V_4 -> V_47 ) ;
for ( V_34 = 0 ; V_34 < 2 ; ++ V_34 ) {
if ( V_4 -> V_5 . V_48 & ( 1 << V_34 ) )
continue;
F_7 ( V_49 , V_50 , V_34 ) ;
F_15 ( V_4 , V_34 ) ;
F_7 ( V_51 , V_52 , 1 ) ;
if ( V_4 -> V_53 >= V_54 )
F_16 ( V_55 , 1 , ~ 0x200001 ) ;
else
F_7 ( V_56 , V_57 , 1 ) ;
F_7 ( V_31 , V_32 , 0 ) ;
F_10 ( 100 ) ;
V_35 = F_9 ( V_4 ) ;
F_7 ( V_51 , V_52 , 0 ) ;
if ( V_35 ) {
F_11 ( L_2 ) ;
F_17 ( & V_4 -> V_47 ) ;
return V_35 ;
}
}
F_7 ( V_49 , V_50 , 0 ) ;
F_17 ( & V_4 -> V_47 ) ;
return 0 ;
}
static int F_18 ( struct V_3 * V_4 )
{
int V_34 ;
F_14 ( & V_4 -> V_47 ) ;
for ( V_34 = 0 ; V_34 < 2 ; ++ V_34 ) {
if ( V_4 -> V_5 . V_48 & ( 1 << V_34 ) )
continue;
F_7 ( V_49 , V_50 , V_34 ) ;
if ( V_4 -> V_53 >= V_54 )
F_16 ( V_55 , 0 , ~ 0x200001 ) ;
else
F_7 ( V_56 , V_57 , 0 ) ;
F_7 ( V_31 , V_32 , 1 ) ;
F_7 ( V_51 , V_52 , 0 ) ;
if ( V_4 -> V_58 & V_59 )
F_8 ( V_4 , false ) ;
}
F_7 ( V_49 , V_50 , 0 ) ;
F_17 ( & V_4 -> V_47 ) ;
return 0 ;
}
static unsigned F_19 ( struct V_3 * V_4 )
{
T_2 V_60 ;
if ( ( V_4 -> V_53 == V_61 ) ||
( V_4 -> V_53 == V_54 ) ||
( V_4 -> V_53 == V_62 ) ||
( V_4 -> V_53 == V_63 ) )
return V_64 ;
if ( V_4 -> V_65 & V_66 )
V_60 = ( F_20 ( V_67 ) &
V_68 ) >>
V_69 ;
else
V_60 = ( F_20 ( V_70 ) &
V_71 ) >>
V_72 ;
switch ( V_60 ) {
case 1 :
return V_73 ;
case 2 :
return V_64 ;
case 3 :
return V_73 | V_64 ;
default:
return 0 ;
}
}
static int F_21 ( void * V_74 )
{
struct V_3 * V_4 = (struct V_3 * ) V_74 ;
V_4 -> V_5 . V_48 = F_19 ( V_4 ) ;
if ( ( V_4 -> V_5 . V_48 &
( V_73 | V_64 ) ) ==
( V_73 | V_64 ) )
return - V_75 ;
V_4 -> V_5 . V_76 = 3 ;
F_22 ( V_4 ) ;
F_23 ( V_4 ) ;
return 0 ;
}
static int F_24 ( void * V_74 )
{
struct V_3 * V_4 = (struct V_3 * ) V_74 ;
struct V_1 * V_2 ;
int V_35 , V_26 ;
V_35 = F_25 ( V_4 , 167 , & V_4 -> V_5 . V_77 ) ;
if ( V_35 )
return V_35 ;
V_35 = F_26 ( V_4 , V_78 +
( V_79 + V_80 ) * 2 ) ;
if ( V_35 )
return V_35 ;
if ( V_4 -> V_5 . V_81 < V_82 )
V_4 -> V_5 . V_76 = 2 ;
V_35 = F_27 ( V_4 ) ;
if ( V_35 )
return V_35 ;
for ( V_26 = 0 ; V_26 < V_4 -> V_5 . V_76 ; V_26 ++ ) {
V_2 = & V_4 -> V_5 . V_2 [ V_26 ] ;
sprintf ( V_2 -> V_83 , L_3 , V_26 ) ;
V_35 = F_28 ( V_4 , V_2 , 512 , V_84 , 0xf ,
& V_4 -> V_5 . V_77 , 0 , V_85 ) ;
if ( V_35 )
return V_35 ;
}
return V_35 ;
}
static int F_29 ( void * V_74 )
{
int V_35 ;
struct V_3 * V_4 = (struct V_3 * ) V_74 ;
V_35 = F_30 ( V_4 ) ;
if ( V_35 )
return V_35 ;
V_35 = F_31 ( V_4 ) ;
if ( V_35 )
return V_35 ;
return V_35 ;
}
static int F_32 ( void * V_74 )
{
int V_35 , V_26 ;
struct V_3 * V_4 = (struct V_3 * ) V_74 ;
V_35 = F_12 ( V_4 ) ;
if ( V_35 )
return V_35 ;
for ( V_26 = 0 ; V_26 < V_4 -> V_5 . V_76 ; V_26 ++ )
V_4 -> V_5 . V_2 [ V_26 ] . V_86 = false ;
for ( V_26 = 0 ; V_26 < V_4 -> V_5 . V_76 ; V_26 ++ ) {
V_35 = F_33 ( & V_4 -> V_5 . V_2 [ V_26 ] ) ;
if ( V_35 )
return V_35 ;
else
V_4 -> V_5 . V_2 [ V_26 ] . V_86 = true ;
}
F_34 ( L_4 ) ;
return 0 ;
}
static int F_35 ( void * V_74 )
{
int V_35 ;
struct V_3 * V_4 = (struct V_3 * ) V_74 ;
V_35 = F_36 ( V_74 ) ;
if ( V_35 )
return V_35 ;
return F_18 ( V_4 ) ;
}
static int F_37 ( void * V_74 )
{
int V_35 ;
struct V_3 * V_4 = (struct V_3 * ) V_74 ;
V_35 = F_35 ( V_4 ) ;
if ( V_35 )
return V_35 ;
V_35 = F_30 ( V_4 ) ;
if ( V_35 )
return V_35 ;
return V_35 ;
}
static int F_38 ( void * V_74 )
{
int V_35 ;
struct V_3 * V_4 = (struct V_3 * ) V_74 ;
V_35 = F_27 ( V_4 ) ;
if ( V_35 )
return V_35 ;
V_35 = F_32 ( V_4 ) ;
if ( V_35 )
return V_35 ;
return V_35 ;
}
static void F_15 ( struct V_3 * V_4 , int V_34 )
{
T_1 V_87 , V_88 ;
F_16 ( V_89 , 0 , ~ ( 1 << 16 ) ) ;
F_16 ( V_19 , 0x1FF000 , ~ 0xFF9FF000 ) ;
F_16 ( V_21 , 0x3F , ~ 0x3F ) ;
F_5 ( V_18 , 0x1FF ) ;
F_5 ( V_90 , 0x00398000 ) ;
F_16 ( V_91 , 0x0 , ~ 0x1 ) ;
F_5 ( V_92 , 0 ) ;
F_5 ( V_93 , 0 ) ;
F_5 ( V_94 , 0 ) ;
if ( V_4 -> V_53 >= V_54 ) {
F_5 ( V_95 , ( V_4 -> V_5 . V_37 >> 8 ) ) ;
F_5 ( V_96 , ( V_4 -> V_5 . V_37 >> 8 ) ) ;
F_5 ( V_97 , ( V_4 -> V_5 . V_37 >> 8 ) ) ;
} else
F_5 ( V_98 , ( V_4 -> V_5 . V_37 >> 8 ) ) ;
V_87 = V_99 ;
V_88 = V_78 ;
F_5 ( V_100 , V_87 & 0x7fffffff ) ;
F_5 ( V_101 , V_88 ) ;
if ( V_34 == 0 ) {
V_87 += V_88 ;
V_88 = V_79 ;
F_5 ( V_102 , V_87 & 0x7fffffff ) ;
F_5 ( V_103 , V_88 ) ;
V_87 += V_88 ;
V_88 = V_80 ;
F_5 ( V_104 , V_87 & 0x7fffffff ) ;
F_5 ( V_105 , V_88 ) ;
} else {
V_87 += V_88 + V_79 + V_80 ;
V_88 = V_79 ;
F_5 ( V_102 , V_87 & 0xfffffff ) ;
F_5 ( V_103 , V_88 ) ;
V_87 += V_88 ;
V_88 = V_80 ;
F_5 ( V_104 , V_87 & 0xfffffff ) ;
F_5 ( V_105 , V_88 ) ;
}
F_16 ( V_106 , 0x0 , ~ 0x100 ) ;
F_7 ( V_107 , V_108 , 1 ) ;
}
static bool F_39 ( void * V_74 )
{
struct V_3 * V_4 = (struct V_3 * ) V_74 ;
T_2 V_109 = 0 ;
V_109 |= ( V_4 -> V_5 . V_48 & V_73 ) ? 0 : V_110 ;
V_109 |= ( V_4 -> V_5 . V_48 & V_64 ) ? 0 : V_111 ;
return ! ( F_2 ( V_112 ) & V_109 ) ;
}
static int F_36 ( void * V_74 )
{
unsigned V_26 ;
struct V_3 * V_4 = (struct V_3 * ) V_74 ;
for ( V_26 = 0 ; V_26 < V_4 -> V_113 ; V_26 ++ )
if ( F_39 ( V_74 ) )
return 0 ;
return - V_33 ;
}
static bool F_40 ( void * V_74 )
{
struct V_3 * V_4 = (struct V_3 * ) V_74 ;
T_2 V_114 = 0 ;
F_14 ( & V_4 -> V_47 ) ;
F_7 ( V_49 , V_115 , 0 ) ;
if ( F_2 ( V_29 ) & V_116 ) {
V_114 = F_41 ( V_114 , V_117 , V_118 , 1 ) ;
V_114 = F_41 ( V_114 , V_117 , V_119 , 1 ) ;
}
F_7 ( V_49 , V_115 , 0x10 ) ;
if ( F_2 ( V_29 ) & V_116 ) {
V_114 = F_41 ( V_114 , V_117 , V_118 , 1 ) ;
V_114 = F_41 ( V_114 , V_117 , V_119 , 1 ) ;
}
F_7 ( V_49 , V_115 , 0 ) ;
F_17 ( & V_4 -> V_47 ) ;
if ( V_114 ) {
V_4 -> V_5 . V_114 = V_114 ;
return true ;
} else {
V_4 -> V_5 . V_114 = 0 ;
return false ;
}
}
static int F_42 ( void * V_74 )
{
struct V_3 * V_4 = (struct V_3 * ) V_74 ;
T_2 V_114 ;
if ( ! V_4 -> V_5 . V_114 )
return 0 ;
V_114 = V_4 -> V_5 . V_114 ;
if ( V_114 ) {
T_2 V_60 ;
V_60 = F_2 ( V_120 ) ;
V_60 |= V_114 ;
F_43 ( V_4 -> V_121 , L_5 , V_60 ) ;
F_5 ( V_120 , V_60 ) ;
V_60 = F_2 ( V_120 ) ;
F_44 ( 50 ) ;
V_60 &= ~ V_114 ;
F_5 ( V_120 , V_60 ) ;
V_60 = F_2 ( V_120 ) ;
F_44 ( 50 ) ;
}
return 0 ;
}
static int F_45 ( void * V_74 )
{
struct V_3 * V_4 = (struct V_3 * ) V_74 ;
if ( ! V_4 -> V_5 . V_114 )
return 0 ;
F_10 ( 5 ) ;
return F_37 ( V_4 ) ;
}
static int F_46 ( void * V_74 )
{
struct V_3 * V_4 = (struct V_3 * ) V_74 ;
if ( ! V_4 -> V_5 . V_114 )
return 0 ;
F_10 ( 5 ) ;
return F_38 ( V_4 ) ;
}
static int F_47 ( struct V_3 * V_4 ,
struct V_122 * V_123 ,
unsigned type ,
enum V_124 V_125 )
{
T_1 V_126 = 0 ;
if ( V_125 == V_127 )
V_126 |= V_128 ;
F_16 ( V_129 , V_126 , ~ V_128 ) ;
return 0 ;
}
static int F_48 ( struct V_3 * V_4 ,
struct V_122 * V_123 ,
struct V_130 * V_131 )
{
F_49 ( L_6 ) ;
F_7 ( V_132 , V_133 , 1 ) ;
switch ( V_131 -> V_134 ) {
case 0 :
case 1 :
case 2 :
F_50 ( & V_4 -> V_5 . V_2 [ V_131 -> V_134 ] ) ;
break;
default:
F_11 ( L_7 ,
V_131 -> V_135 , V_131 -> V_134 ) ;
break;
}
return 0 ;
}
static void F_51 ( struct V_3 * V_4 , bool V_136 )
{
T_2 V_60 = F_20 ( V_137 ) ;
if ( V_136 )
V_60 |= V_138 ;
else
V_60 &= ~ V_138 ;
F_52 ( V_137 , V_60 ) ;
}
static int F_53 ( void * V_74 ,
enum V_139 V_125 )
{
struct V_3 * V_4 = (struct V_3 * ) V_74 ;
bool V_136 = ( V_125 == V_140 ) ? true : false ;
int V_26 ;
if ( ( V_4 -> V_53 == V_62 ) ||
( V_4 -> V_53 == V_141 ) ||
( V_4 -> V_53 == V_61 ) )
F_51 ( V_4 , V_136 ) ;
if ( ! ( V_4 -> V_58 & V_59 ) )
return 0 ;
F_14 ( & V_4 -> V_47 ) ;
for ( V_26 = 0 ; V_26 < 2 ; V_26 ++ ) {
if ( V_4 -> V_5 . V_48 & ( 1 << V_26 ) )
continue;
F_7 ( V_49 , V_50 , V_26 ) ;
if ( V_136 ) {
T_1 V_17 = F_2 ( V_89 ) ;
V_17 &= ~ ( 0xf | 0xff0 ) ;
V_17 |= ( ( 0x0 << 0 ) | ( 0x04 << 4 ) ) ;
F_5 ( V_89 , V_17 ) ;
V_17 = F_2 ( V_19 ) ;
V_17 &= ~ ( 0xf | 0xff0 ) ;
V_17 |= ( ( 0x0 << 0 ) | ( 0x04 << 4 ) ) ;
F_5 ( V_19 , V_17 ) ;
}
F_8 ( V_4 , V_136 ) ;
}
F_7 ( V_49 , V_50 , 0 ) ;
F_17 ( & V_4 -> V_47 ) ;
return 0 ;
}
static int F_54 ( void * V_74 ,
enum V_142 V_125 )
{
struct V_3 * V_4 = (struct V_3 * ) V_74 ;
if ( ! ( V_4 -> V_143 & V_144 ) )
return 0 ;
if ( V_125 == V_145 )
return 0 ;
else
return F_12 ( V_4 ) ;
}
static void F_55 ( struct V_1 * V_2 ,
struct V_146 * V_147 , unsigned int V_148 , bool V_149 )
{
F_56 ( V_2 , V_150 ) ;
F_56 ( V_2 , V_148 ) ;
F_56 ( V_2 , F_57 ( V_147 -> V_37 ) ) ;
F_56 ( V_2 , F_13 ( V_147 -> V_37 ) ) ;
F_56 ( V_2 , V_147 -> V_151 ) ;
}
static void F_58 ( struct V_1 * V_2 ,
unsigned int V_148 , T_3 V_152 )
{
F_56 ( V_2 , V_153 ) ;
F_56 ( V_2 , V_148 ) ;
F_56 ( V_2 , V_152 >> 12 ) ;
F_56 ( V_2 , V_154 ) ;
F_56 ( V_2 , V_148 ) ;
F_56 ( V_2 , V_155 ) ;
}
static void F_59 ( struct V_1 * V_2 )
{
T_1 V_156 = V_2 -> V_157 . V_158 ;
T_3 V_159 = V_2 -> V_157 . V_37 ;
F_56 ( V_2 , V_160 ) ;
F_56 ( V_2 , F_57 ( V_159 ) ) ;
F_56 ( V_2 , F_13 ( V_159 ) ) ;
F_56 ( V_2 , V_156 ) ;
}
static unsigned F_60 ( struct V_1 * V_2 )
{
return
5 ;
}
static unsigned F_61 ( struct V_1 * V_2 )
{
return
4 +
6 ;
}
static unsigned F_62 ( struct V_1 * V_2 )
{
return
6 +
4 +
6 + 6 ;
}
static void F_22 ( struct V_3 * V_4 )
{
int V_26 ;
if ( V_4 -> V_53 >= V_54 ) {
for ( V_26 = 0 ; V_26 < V_4 -> V_5 . V_76 ; V_26 ++ )
V_4 -> V_5 . V_2 [ V_26 ] . V_161 = & V_162 ;
F_34 ( L_8 ) ;
} else {
for ( V_26 = 0 ; V_26 < V_4 -> V_5 . V_76 ; V_26 ++ )
V_4 -> V_5 . V_2 [ V_26 ] . V_161 = & V_163 ;
F_34 ( L_9 ) ;
}
}
static void F_23 ( struct V_3 * V_4 )
{
V_4 -> V_5 . V_77 . V_164 = 1 ;
V_4 -> V_5 . V_77 . V_161 = & V_165 ;
}
