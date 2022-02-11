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
if ( ! V_16 ) {
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
V_17 &= ~ 0x3ff ;
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
F_5 ( V_49 , F_15 ( V_34 ) ) ;
F_16 ( V_4 , V_34 ) ;
F_7 ( V_50 , V_51 , 1 ) ;
if ( V_4 -> V_52 >= V_53 )
F_17 ( V_54 , 1 , ~ 0x200001 ) ;
else
F_7 ( V_55 , V_56 , 1 ) ;
F_7 ( V_31 , V_32 , 0 ) ;
F_10 ( 100 ) ;
V_35 = F_9 ( V_4 ) ;
F_7 ( V_50 , V_51 , 0 ) ;
if ( V_35 ) {
F_11 ( L_2 ) ;
F_18 ( & V_4 -> V_47 ) ;
return V_35 ;
}
}
F_5 ( V_49 , V_57 ) ;
F_18 ( & V_4 -> V_47 ) ;
return 0 ;
}
static int F_19 ( struct V_3 * V_4 )
{
int V_34 ;
F_14 ( & V_4 -> V_47 ) ;
for ( V_34 = 0 ; V_34 < 2 ; ++ V_34 ) {
if ( V_4 -> V_5 . V_48 & ( 1 << V_34 ) )
continue;
F_5 ( V_49 , F_15 ( V_34 ) ) ;
if ( V_4 -> V_52 >= V_53 )
F_17 ( V_54 , 0 , ~ 0x200001 ) ;
else
F_7 ( V_55 , V_56 , 0 ) ;
F_7 ( V_31 , V_32 , 1 ) ;
F_7 ( V_50 , V_51 , 0 ) ;
if ( V_4 -> V_58 & V_59 )
F_8 ( V_4 , false ) ;
}
F_5 ( V_49 , V_57 ) ;
F_18 ( & V_4 -> V_47 ) ;
return 0 ;
}
static unsigned F_20 ( struct V_3 * V_4 )
{
T_2 V_60 ;
if ( ( V_4 -> V_52 == V_61 ) ||
( V_4 -> V_52 == V_53 ) ||
( V_4 -> V_52 == V_62 ) ||
( V_4 -> V_52 == V_63 ) ||
( V_4 -> V_52 == V_64 ) )
return V_65 ;
if ( V_4 -> V_66 & V_67 )
V_60 = ( F_21 ( V_68 ) &
V_69 ) >>
V_70 ;
else
V_60 = ( F_21 ( V_71 ) &
V_72 ) >>
V_73 ;
switch ( V_60 ) {
case 1 :
return V_74 ;
case 2 :
return V_65 ;
case 3 :
return V_74 | V_65 ;
default:
return 0 ;
}
}
static int F_22 ( void * V_75 )
{
struct V_3 * V_4 = (struct V_3 * ) V_75 ;
V_4 -> V_5 . V_48 = F_20 ( V_4 ) ;
if ( ( V_4 -> V_5 . V_48 &
( V_74 | V_65 ) ) ==
( V_74 | V_65 ) )
return - V_76 ;
V_4 -> V_5 . V_77 = 3 ;
F_23 ( V_4 ) ;
F_24 ( V_4 ) ;
return 0 ;
}
static int F_25 ( void * V_75 )
{
struct V_3 * V_4 = (struct V_3 * ) V_75 ;
struct V_1 * V_2 ;
int V_35 , V_26 ;
V_35 = F_26 ( V_4 , 167 , & V_4 -> V_5 . V_78 ) ;
if ( V_35 )
return V_35 ;
V_35 = F_27 ( V_4 , V_79 +
( V_80 + V_81 ) * 2 ) ;
if ( V_35 )
return V_35 ;
if ( V_4 -> V_5 . V_82 < V_83 )
V_4 -> V_5 . V_77 = 2 ;
V_35 = F_28 ( V_4 ) ;
if ( V_35 )
return V_35 ;
for ( V_26 = 0 ; V_26 < V_4 -> V_5 . V_77 ; V_26 ++ ) {
V_2 = & V_4 -> V_5 . V_2 [ V_26 ] ;
sprintf ( V_2 -> V_84 , L_3 , V_26 ) ;
V_35 = F_29 ( V_4 , V_2 , 512 , & V_4 -> V_5 . V_78 , 0 ) ;
if ( V_35 )
return V_35 ;
}
return V_35 ;
}
static int F_30 ( void * V_75 )
{
int V_35 ;
struct V_3 * V_4 = (struct V_3 * ) V_75 ;
V_35 = F_31 ( V_4 ) ;
if ( V_35 )
return V_35 ;
V_35 = F_32 ( V_4 ) ;
if ( V_35 )
return V_35 ;
return V_35 ;
}
static int F_33 ( void * V_75 )
{
int V_35 , V_26 ;
struct V_3 * V_4 = (struct V_3 * ) V_75 ;
V_35 = F_12 ( V_4 ) ;
if ( V_35 )
return V_35 ;
for ( V_26 = 0 ; V_26 < V_4 -> V_5 . V_77 ; V_26 ++ )
V_4 -> V_5 . V_2 [ V_26 ] . V_85 = false ;
for ( V_26 = 0 ; V_26 < V_4 -> V_5 . V_77 ; V_26 ++ ) {
V_35 = F_34 ( & V_4 -> V_5 . V_2 [ V_26 ] ) ;
if ( V_35 )
return V_35 ;
else
V_4 -> V_5 . V_2 [ V_26 ] . V_85 = true ;
}
F_35 ( L_4 ) ;
return 0 ;
}
static int F_36 ( void * V_75 )
{
int V_35 ;
struct V_3 * V_4 = (struct V_3 * ) V_75 ;
V_35 = F_37 ( V_75 ) ;
if ( V_35 )
return V_35 ;
return F_19 ( V_4 ) ;
}
static int F_38 ( void * V_75 )
{
int V_35 ;
struct V_3 * V_4 = (struct V_3 * ) V_75 ;
V_35 = F_36 ( V_4 ) ;
if ( V_35 )
return V_35 ;
V_35 = F_31 ( V_4 ) ;
if ( V_35 )
return V_35 ;
return V_35 ;
}
static int F_39 ( void * V_75 )
{
int V_35 ;
struct V_3 * V_4 = (struct V_3 * ) V_75 ;
V_35 = F_28 ( V_4 ) ;
if ( V_35 )
return V_35 ;
V_35 = F_33 ( V_4 ) ;
if ( V_35 )
return V_35 ;
return V_35 ;
}
static void F_16 ( struct V_3 * V_4 , int V_34 )
{
T_1 V_86 , V_87 ;
F_17 ( V_88 , 0 , ~ ( 1 << 16 ) ) ;
F_17 ( V_19 , 0x1FF000 , ~ 0xFF9FF000 ) ;
F_17 ( V_21 , 0x3F , ~ 0x3F ) ;
F_5 ( V_18 , 0x1FF ) ;
F_5 ( V_89 , 0x00398000 ) ;
F_17 ( V_90 , 0x0 , ~ 0x1 ) ;
F_5 ( V_91 , 0 ) ;
F_5 ( V_92 , 0 ) ;
F_5 ( V_93 , 0 ) ;
if ( V_4 -> V_52 >= V_53 ) {
F_5 ( V_94 , ( V_4 -> V_5 . V_37 >> 8 ) ) ;
F_5 ( V_95 , ( V_4 -> V_5 . V_37 >> 8 ) ) ;
F_5 ( V_96 , ( V_4 -> V_5 . V_37 >> 8 ) ) ;
} else
F_5 ( V_97 , ( V_4 -> V_5 . V_37 >> 8 ) ) ;
V_86 = V_98 ;
V_87 = V_79 ;
F_5 ( V_99 , V_86 & 0x7fffffff ) ;
F_5 ( V_100 , V_87 ) ;
if ( V_34 == 0 ) {
V_86 += V_87 ;
V_87 = V_80 ;
F_5 ( V_101 , V_86 & 0x7fffffff ) ;
F_5 ( V_102 , V_87 ) ;
V_86 += V_87 ;
V_87 = V_81 ;
F_5 ( V_103 , V_86 & 0x7fffffff ) ;
F_5 ( V_104 , V_87 ) ;
} else {
V_86 += V_87 + V_80 + V_81 ;
V_87 = V_80 ;
F_5 ( V_101 , V_86 & 0xfffffff ) ;
F_5 ( V_102 , V_87 ) ;
V_86 += V_87 ;
V_87 = V_81 ;
F_5 ( V_103 , V_86 & 0xfffffff ) ;
F_5 ( V_104 , V_87 ) ;
}
F_17 ( V_105 , 0x0 , ~ 0x100 ) ;
F_7 ( V_106 , V_107 , 1 ) ;
}
static bool F_40 ( void * V_75 )
{
struct V_3 * V_4 = (struct V_3 * ) V_75 ;
T_2 V_108 = 0 ;
V_108 |= ( V_4 -> V_5 . V_48 & V_74 ) ? 0 : V_109 ;
V_108 |= ( V_4 -> V_5 . V_48 & V_65 ) ? 0 : V_110 ;
return ! ( F_2 ( V_111 ) & V_108 ) ;
}
static int F_37 ( void * V_75 )
{
unsigned V_26 ;
struct V_3 * V_4 = (struct V_3 * ) V_75 ;
for ( V_26 = 0 ; V_26 < V_4 -> V_112 ; V_26 ++ )
if ( F_40 ( V_75 ) )
return 0 ;
return - V_33 ;
}
static bool F_41 ( void * V_75 )
{
struct V_3 * V_4 = (struct V_3 * ) V_75 ;
T_2 V_113 = 0 ;
F_14 ( & V_4 -> V_47 ) ;
F_5 ( V_49 , F_15 ( 0 ) ) ;
if ( F_2 ( V_29 ) & V_114 ) {
V_113 = F_42 ( V_113 , V_115 , V_116 , 1 ) ;
V_113 = F_42 ( V_113 , V_115 , V_117 , 1 ) ;
}
F_5 ( V_49 , F_15 ( 1 ) ) ;
if ( F_2 ( V_29 ) & V_114 ) {
V_113 = F_42 ( V_113 , V_115 , V_116 , 1 ) ;
V_113 = F_42 ( V_113 , V_115 , V_117 , 1 ) ;
}
F_5 ( V_49 , F_15 ( 0 ) ) ;
F_18 ( & V_4 -> V_47 ) ;
if ( V_113 ) {
V_4 -> V_5 . V_113 = V_113 ;
return true ;
} else {
V_4 -> V_5 . V_113 = 0 ;
return false ;
}
}
static int F_43 ( void * V_75 )
{
struct V_3 * V_4 = (struct V_3 * ) V_75 ;
T_2 V_113 ;
if ( ! V_4 -> V_5 . V_113 )
return 0 ;
V_113 = V_4 -> V_5 . V_113 ;
if ( V_113 ) {
T_2 V_60 ;
V_60 = F_2 ( V_118 ) ;
V_60 |= V_113 ;
F_44 ( V_4 -> V_119 , L_5 , V_60 ) ;
F_5 ( V_118 , V_60 ) ;
V_60 = F_2 ( V_118 ) ;
F_45 ( 50 ) ;
V_60 &= ~ V_113 ;
F_5 ( V_118 , V_60 ) ;
V_60 = F_2 ( V_118 ) ;
F_45 ( 50 ) ;
}
return 0 ;
}
static int F_46 ( void * V_75 )
{
struct V_3 * V_4 = (struct V_3 * ) V_75 ;
if ( ! V_4 -> V_5 . V_113 )
return 0 ;
F_10 ( 5 ) ;
return F_38 ( V_4 ) ;
}
static int F_47 ( void * V_75 )
{
struct V_3 * V_4 = (struct V_3 * ) V_75 ;
if ( ! V_4 -> V_5 . V_113 )
return 0 ;
F_10 ( 5 ) ;
return F_39 ( V_4 ) ;
}
static int F_48 ( struct V_3 * V_4 ,
struct V_120 * V_121 ,
unsigned type ,
enum V_122 V_123 )
{
T_1 V_124 = 0 ;
if ( V_123 == V_125 )
V_124 |= V_126 ;
F_17 ( V_127 , V_124 , ~ V_126 ) ;
return 0 ;
}
static int F_49 ( struct V_3 * V_4 ,
struct V_120 * V_121 ,
struct V_128 * V_129 )
{
F_50 ( L_6 ) ;
F_7 ( V_130 , V_131 , 1 ) ;
switch ( V_129 -> V_132 ) {
case 0 :
case 1 :
case 2 :
F_51 ( & V_4 -> V_5 . V_2 [ V_129 -> V_132 ] ) ;
break;
default:
F_11 ( L_7 ,
V_129 -> V_133 , V_129 -> V_132 ) ;
break;
}
return 0 ;
}
static void F_52 ( struct V_3 * V_4 , bool V_134 )
{
T_2 V_60 = F_21 ( V_135 ) ;
if ( V_134 )
V_60 |= V_136 ;
else
V_60 &= ~ V_136 ;
F_53 ( V_135 , V_60 ) ;
}
static int F_54 ( void * V_75 ,
enum V_137 V_123 )
{
struct V_3 * V_4 = (struct V_3 * ) V_75 ;
bool V_134 = ( V_123 == V_138 ) ? true : false ;
int V_26 ;
if ( ( V_4 -> V_52 == V_62 ) ||
( V_4 -> V_52 == V_139 ) ||
( V_4 -> V_52 == V_61 ) )
F_52 ( V_4 , V_134 ) ;
if ( ! ( V_4 -> V_58 & V_59 ) )
return 0 ;
F_14 ( & V_4 -> V_47 ) ;
for ( V_26 = 0 ; V_26 < 2 ; V_26 ++ ) {
if ( V_4 -> V_5 . V_48 & ( 1 << V_26 ) )
continue;
F_5 ( V_49 , F_15 ( V_26 ) ) ;
if ( V_134 ) {
T_1 V_17 = F_2 ( V_88 ) ;
V_17 &= ~ ( 0xf | 0xff0 ) ;
V_17 |= ( ( 0x0 << 0 ) | ( 0x04 << 4 ) ) ;
F_5 ( V_88 , V_17 ) ;
V_17 = F_2 ( V_19 ) ;
V_17 &= ~ ( 0xf | 0xff0 ) ;
V_17 |= ( ( 0x0 << 0 ) | ( 0x04 << 4 ) ) ;
F_5 ( V_19 , V_17 ) ;
}
F_8 ( V_4 , V_134 ) ;
}
F_5 ( V_49 , V_57 ) ;
F_18 ( & V_4 -> V_47 ) ;
return 0 ;
}
static int F_55 ( void * V_75 ,
enum V_140 V_123 )
{
struct V_3 * V_4 = (struct V_3 * ) V_75 ;
if ( ! ( V_4 -> V_141 & V_142 ) )
return 0 ;
if ( V_123 == V_143 )
return 0 ;
else
return F_12 ( V_4 ) ;
}
static void F_56 ( struct V_1 * V_2 ,
struct V_144 * V_145 , unsigned int V_146 , bool V_147 )
{
F_57 ( V_2 , V_148 ) ;
F_57 ( V_2 , V_146 ) ;
F_57 ( V_2 , F_58 ( V_145 -> V_37 ) ) ;
F_57 ( V_2 , F_13 ( V_145 -> V_37 ) ) ;
F_57 ( V_2 , V_145 -> V_149 ) ;
}
static void F_59 ( struct V_1 * V_2 ,
unsigned int V_146 , T_3 V_150 )
{
F_57 ( V_2 , V_151 ) ;
F_57 ( V_2 , V_146 ) ;
F_57 ( V_2 , V_150 >> 12 ) ;
F_57 ( V_2 , V_152 ) ;
F_57 ( V_2 , V_146 ) ;
F_57 ( V_2 , V_153 ) ;
}
static void F_60 ( struct V_1 * V_2 )
{
T_1 V_154 = V_2 -> V_155 . V_156 ;
T_3 V_157 = V_2 -> V_155 . V_37 ;
F_57 ( V_2 , V_158 ) ;
F_57 ( V_2 , F_58 ( V_157 ) ) ;
F_57 ( V_2 , F_13 ( V_157 ) ) ;
F_57 ( V_2 , V_154 ) ;
}
static void F_23 ( struct V_3 * V_4 )
{
int V_26 ;
if ( V_4 -> V_52 >= V_53 ) {
for ( V_26 = 0 ; V_26 < V_4 -> V_5 . V_77 ; V_26 ++ )
V_4 -> V_5 . V_2 [ V_26 ] . V_159 = & V_160 ;
F_35 ( L_8 ) ;
} else {
for ( V_26 = 0 ; V_26 < V_4 -> V_5 . V_77 ; V_26 ++ )
V_4 -> V_5 . V_2 [ V_26 ] . V_159 = & V_161 ;
F_35 ( L_9 ) ;
}
}
static void F_24 ( struct V_3 * V_4 )
{
V_4 -> V_5 . V_78 . V_162 = 1 ;
V_4 -> V_5 . V_78 . V_159 = & V_163 ;
}
