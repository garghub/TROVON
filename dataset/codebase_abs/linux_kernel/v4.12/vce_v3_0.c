static T_1 F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
T_2 V_5 ;
F_2 ( & V_4 -> V_6 ) ;
if ( V_4 -> V_7 . V_8 == 0 ||
V_4 -> V_7 . V_8 == V_9 )
F_3 ( V_10 , F_4 ( 0 ) ) ;
else if ( V_4 -> V_7 . V_8 == V_11 )
F_3 ( V_10 , F_4 ( 1 ) ) ;
if ( V_2 == & V_4 -> V_7 . V_2 [ 0 ] )
V_5 = F_5 ( V_12 ) ;
else if ( V_2 == & V_4 -> V_7 . V_2 [ 1 ] )
V_5 = F_5 ( V_13 ) ;
else
V_5 = F_5 ( V_14 ) ;
F_3 ( V_10 , V_15 ) ;
F_6 ( & V_4 -> V_6 ) ;
return V_5 ;
}
static T_1 F_7 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
T_2 V_5 ;
F_2 ( & V_4 -> V_6 ) ;
if ( V_4 -> V_7 . V_8 == 0 ||
V_4 -> V_7 . V_8 == V_9 )
F_3 ( V_10 , F_4 ( 0 ) ) ;
else if ( V_4 -> V_7 . V_8 == V_11 )
F_3 ( V_10 , F_4 ( 1 ) ) ;
if ( V_2 == & V_4 -> V_7 . V_2 [ 0 ] )
V_5 = F_5 ( V_16 ) ;
else if ( V_2 == & V_4 -> V_7 . V_2 [ 1 ] )
V_5 = F_5 ( V_17 ) ;
else
V_5 = F_5 ( V_18 ) ;
F_3 ( V_10 , V_15 ) ;
F_6 ( & V_4 -> V_6 ) ;
return V_5 ;
}
static void F_8 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
F_2 ( & V_4 -> V_6 ) ;
if ( V_4 -> V_7 . V_8 == 0 ||
V_4 -> V_7 . V_8 == V_9 )
F_3 ( V_10 , F_4 ( 0 ) ) ;
else if ( V_4 -> V_7 . V_8 == V_11 )
F_3 ( V_10 , F_4 ( 1 ) ) ;
if ( V_2 == & V_4 -> V_7 . V_2 [ 0 ] )
F_3 ( V_16 , F_9 ( V_2 -> V_19 ) ) ;
else if ( V_2 == & V_4 -> V_7 . V_2 [ 1 ] )
F_3 ( V_17 , F_9 ( V_2 -> V_19 ) ) ;
else
F_3 ( V_18 , F_9 ( V_2 -> V_19 ) ) ;
F_3 ( V_10 , V_15 ) ;
F_6 ( & V_4 -> V_6 ) ;
}
static void F_10 ( struct V_3 * V_4 , bool V_20 )
{
F_11 ( V_21 , V_22 , V_20 ? 1 : 0 ) ;
}
static void F_12 ( struct V_3 * V_4 ,
bool V_23 )
{
T_2 V_24 ;
F_10 ( V_4 , true ) ;
if ( ! V_23 ) {
V_24 = F_5 ( V_25 ) ;
V_24 |= 0x1ff ;
V_24 &= ~ 0xef0000 ;
F_3 ( V_25 , V_24 ) ;
V_24 = F_5 ( V_26 ) ;
V_24 |= 0x3ff000 ;
V_24 &= ~ 0xffc00000 ;
F_3 ( V_26 , V_24 ) ;
V_24 = F_5 ( V_27 ) ;
V_24 |= 0x2 ;
V_24 &= ~ 0x00010000 ;
F_3 ( V_27 , V_24 ) ;
V_24 = F_5 ( V_28 ) ;
V_24 |= 0x37f ;
F_3 ( V_28 , V_24 ) ;
V_24 = F_5 ( V_29 ) ;
V_24 |= V_30 |
V_31 |
V_32 |
0x8 ;
F_3 ( V_29 , V_24 ) ;
} else {
V_24 = F_5 ( V_25 ) ;
V_24 &= ~ 0x80010 ;
V_24 |= 0xe70008 ;
F_3 ( V_25 , V_24 ) ;
V_24 = F_5 ( V_26 ) ;
V_24 |= 0xffc00000 ;
F_3 ( V_26 , V_24 ) ;
V_24 = F_5 ( V_27 ) ;
V_24 |= 0x10000 ;
F_3 ( V_27 , V_24 ) ;
V_24 = F_5 ( V_28 ) ;
V_24 &= ~ 0x3ff ;
F_3 ( V_28 , V_24 ) ;
V_24 = F_5 ( V_29 ) ;
V_24 &= ~ ( V_30 |
V_31 |
V_32 |
0x8 ) ;
F_3 ( V_29 , V_24 ) ;
}
F_10 ( V_4 , false ) ;
}
static int F_13 ( struct V_3 * V_4 )
{
int V_33 , V_34 ;
for ( V_33 = 0 ; V_33 < 10 ; ++ V_33 ) {
for ( V_34 = 0 ; V_34 < 100 ; ++ V_34 ) {
T_3 V_35 = F_5 ( V_36 ) ;
if ( V_35 & V_37 )
return 0 ;
F_14 ( 10 ) ;
}
F_15 ( L_1 ) ;
F_11 ( V_38 , V_39 , 1 ) ;
F_14 ( 10 ) ;
F_11 ( V_38 , V_39 , 0 ) ;
F_14 ( 10 ) ;
}
return - V_40 ;
}
static int F_16 ( struct V_3 * V_4 )
{
struct V_1 * V_2 ;
int V_41 , V_42 ;
F_2 ( & V_4 -> V_6 ) ;
for ( V_41 = 0 ; V_41 < 2 ; ++ V_41 ) {
if ( V_4 -> V_7 . V_8 & ( 1 << V_41 ) )
continue;
F_3 ( V_10 , F_4 ( V_41 ) ) ;
if ( V_41 != 1 || V_4 -> V_7 . V_8 == V_11 ) {
V_2 = & V_4 -> V_7 . V_2 [ 0 ] ;
F_3 ( V_12 , F_9 ( V_2 -> V_19 ) ) ;
F_3 ( V_16 , F_9 ( V_2 -> V_19 ) ) ;
F_3 ( V_43 , V_2 -> V_44 ) ;
F_3 ( V_45 , F_17 ( V_2 -> V_44 ) ) ;
F_3 ( V_46 , V_2 -> V_47 / 4 ) ;
V_2 = & V_4 -> V_7 . V_2 [ 1 ] ;
F_3 ( V_13 , F_9 ( V_2 -> V_19 ) ) ;
F_3 ( V_17 , F_9 ( V_2 -> V_19 ) ) ;
F_3 ( V_48 , V_2 -> V_44 ) ;
F_3 ( V_49 , F_17 ( V_2 -> V_44 ) ) ;
F_3 ( V_50 , V_2 -> V_47 / 4 ) ;
V_2 = & V_4 -> V_7 . V_2 [ 2 ] ;
F_3 ( V_14 , F_9 ( V_2 -> V_19 ) ) ;
F_3 ( V_18 , F_9 ( V_2 -> V_19 ) ) ;
F_3 ( V_51 , V_2 -> V_44 ) ;
F_3 ( V_52 , F_17 ( V_2 -> V_44 ) ) ;
F_3 ( V_53 , V_2 -> V_47 / 4 ) ;
}
F_18 ( V_4 , V_41 ) ;
F_11 ( V_54 , V_55 , 1 ) ;
if ( V_4 -> V_56 >= V_57 )
F_19 ( V_58 , 1 , ~ 0x200001 ) ;
else
F_11 ( V_59 , V_60 , 1 ) ;
F_11 ( V_38 , V_39 , 0 ) ;
F_14 ( 100 ) ;
V_42 = F_13 ( V_4 ) ;
F_11 ( V_54 , V_55 , 0 ) ;
if ( V_42 ) {
F_15 ( L_2 ) ;
F_6 ( & V_4 -> V_6 ) ;
return V_42 ;
}
}
F_3 ( V_10 , V_15 ) ;
F_6 ( & V_4 -> V_6 ) ;
return 0 ;
}
static int F_20 ( struct V_3 * V_4 )
{
int V_41 ;
F_2 ( & V_4 -> V_6 ) ;
for ( V_41 = 0 ; V_41 < 2 ; ++ V_41 ) {
if ( V_4 -> V_7 . V_8 & ( 1 << V_41 ) )
continue;
F_3 ( V_10 , F_4 ( V_41 ) ) ;
if ( V_4 -> V_56 >= V_57 )
F_19 ( V_58 , 0 , ~ 0x200001 ) ;
else
F_11 ( V_59 , V_60 , 0 ) ;
F_11 ( V_38 , V_39 , 1 ) ;
F_3 ( V_36 , 0 ) ;
}
F_3 ( V_10 , V_15 ) ;
F_6 ( & V_4 -> V_6 ) ;
return 0 ;
}
static unsigned F_21 ( struct V_3 * V_4 )
{
T_2 V_61 ;
if ( ( V_4 -> V_56 == V_62 ) ||
( V_4 -> V_56 == V_57 ) ||
( V_4 -> V_56 == V_63 ) ||
( V_4 -> V_56 == V_64 ) ||
( V_4 -> V_56 == V_65 ) )
return V_9 ;
if ( V_4 -> V_66 & V_67 )
V_61 = ( F_22 ( V_68 ) &
V_69 ) >>
V_70 ;
else
V_61 = ( F_22 ( V_71 ) &
V_72 ) >>
V_73 ;
switch ( V_61 ) {
case 1 :
return V_11 ;
case 2 :
return V_9 ;
case 3 :
return V_11 | V_9 ;
default:
return 0 ;
}
}
static int F_23 ( void * V_74 )
{
struct V_3 * V_4 = (struct V_3 * ) V_74 ;
V_4 -> V_7 . V_8 = F_21 ( V_4 ) ;
if ( ( V_4 -> V_7 . V_8 &
( V_11 | V_9 ) ) ==
( V_11 | V_9 ) )
return - V_75 ;
V_4 -> V_7 . V_76 = 3 ;
F_24 ( V_4 ) ;
F_25 ( V_4 ) ;
return 0 ;
}
static int F_26 ( void * V_74 )
{
struct V_3 * V_4 = (struct V_3 * ) V_74 ;
struct V_1 * V_2 ;
int V_42 , V_33 ;
V_42 = F_27 ( V_4 , V_77 , 167 , & V_4 -> V_7 . V_78 ) ;
if ( V_42 )
return V_42 ;
V_42 = F_28 ( V_4 , V_79 +
( V_80 + V_81 ) * 2 ) ;
if ( V_42 )
return V_42 ;
if ( V_4 -> V_7 . V_82 < V_83 )
V_4 -> V_7 . V_76 = 2 ;
V_42 = F_29 ( V_4 ) ;
if ( V_42 )
return V_42 ;
for ( V_33 = 0 ; V_33 < V_4 -> V_7 . V_76 ; V_33 ++ ) {
V_2 = & V_4 -> V_7 . V_2 [ V_33 ] ;
sprintf ( V_2 -> V_84 , L_3 , V_33 ) ;
V_42 = F_30 ( V_4 , V_2 , 512 , & V_4 -> V_7 . V_78 , 0 ) ;
if ( V_42 )
return V_42 ;
}
return V_42 ;
}
static int F_31 ( void * V_74 )
{
int V_42 ;
struct V_3 * V_4 = (struct V_3 * ) V_74 ;
V_42 = F_32 ( V_4 ) ;
if ( V_42 )
return V_42 ;
return F_33 ( V_4 ) ;
}
static int F_34 ( void * V_74 )
{
int V_42 , V_33 ;
struct V_3 * V_4 = (struct V_3 * ) V_74 ;
F_10 ( V_4 , true ) ;
if ( ! ( V_4 -> V_66 & V_67 ) )
F_35 ( V_4 , 10000 , 10000 ) ;
for ( V_33 = 0 ; V_33 < V_4 -> V_7 . V_76 ; V_33 ++ )
V_4 -> V_7 . V_2 [ V_33 ] . V_85 = false ;
for ( V_33 = 0 ; V_33 < V_4 -> V_7 . V_76 ; V_33 ++ ) {
V_42 = F_36 ( & V_4 -> V_7 . V_2 [ V_33 ] ) ;
if ( V_42 )
return V_42 ;
else
V_4 -> V_7 . V_2 [ V_33 ] . V_85 = true ;
}
F_37 ( L_4 ) ;
return 0 ;
}
static int F_38 ( void * V_74 )
{
int V_42 ;
struct V_3 * V_4 = (struct V_3 * ) V_74 ;
V_42 = F_39 ( V_74 ) ;
if ( V_42 )
return V_42 ;
F_20 ( V_4 ) ;
return F_40 ( V_4 , V_86 ) ;
}
static int F_41 ( void * V_74 )
{
int V_42 ;
struct V_3 * V_4 = (struct V_3 * ) V_74 ;
V_42 = F_38 ( V_4 ) ;
if ( V_42 )
return V_42 ;
return F_32 ( V_4 ) ;
}
static int F_42 ( void * V_74 )
{
int V_42 ;
struct V_3 * V_4 = (struct V_3 * ) V_74 ;
V_42 = F_29 ( V_4 ) ;
if ( V_42 )
return V_42 ;
return F_34 ( V_4 ) ;
}
static void F_18 ( struct V_3 * V_4 , int V_41 )
{
T_3 V_87 , V_88 ;
F_19 ( V_89 , 0 , ~ ( 1 << 16 ) ) ;
F_19 ( V_26 , 0x1FF000 , ~ 0xFF9FF000 ) ;
F_19 ( V_28 , 0x3F , ~ 0x3F ) ;
F_3 ( V_25 , 0x1FF ) ;
F_3 ( V_90 , 0x00398000 ) ;
F_19 ( V_91 , 0x0 , ~ 0x1 ) ;
F_3 ( V_92 , 0 ) ;
F_3 ( V_93 , 0 ) ;
F_3 ( V_94 , 0 ) ;
F_43 ( V_58 , 0x00100000 ) ;
if ( V_4 -> V_56 >= V_57 ) {
F_3 ( V_95 , ( V_4 -> V_7 . V_44 >> 8 ) ) ;
F_3 ( V_96 , ( V_4 -> V_7 . V_44 >> 8 ) ) ;
F_3 ( V_97 , ( V_4 -> V_7 . V_44 >> 8 ) ) ;
} else
F_3 ( V_98 , ( V_4 -> V_7 . V_44 >> 8 ) ) ;
V_87 = V_99 ;
V_88 = V_79 ;
F_3 ( V_100 , V_87 & 0x7fffffff ) ;
F_3 ( V_101 , V_88 ) ;
if ( V_41 == 0 ) {
V_87 += V_88 ;
V_88 = V_80 ;
F_3 ( V_102 , V_87 & 0x7fffffff ) ;
F_3 ( V_103 , V_88 ) ;
V_87 += V_88 ;
V_88 = V_81 ;
F_3 ( V_104 , V_87 & 0x7fffffff ) ;
F_3 ( V_105 , V_88 ) ;
} else {
V_87 += V_88 + V_80 + V_81 ;
V_88 = V_80 ;
F_3 ( V_102 , V_87 & 0xfffffff ) ;
F_3 ( V_103 , V_88 ) ;
V_87 += V_88 ;
V_88 = V_81 ;
F_3 ( V_104 , V_87 & 0xfffffff ) ;
F_3 ( V_105 , V_88 ) ;
}
F_19 ( V_106 , 0x0 , ~ 0x100 ) ;
F_11 ( V_107 , V_108 , 1 ) ;
}
static bool F_44 ( void * V_74 )
{
struct V_3 * V_4 = (struct V_3 * ) V_74 ;
T_2 V_109 = 0 ;
V_109 |= ( V_4 -> V_7 . V_8 & V_11 ) ? 0 : V_110 ;
V_109 |= ( V_4 -> V_7 . V_8 & V_9 ) ? 0 : V_111 ;
return ! ( F_5 ( V_112 ) & V_109 ) ;
}
static int F_39 ( void * V_74 )
{
unsigned V_33 ;
struct V_3 * V_4 = (struct V_3 * ) V_74 ;
for ( V_33 = 0 ; V_33 < V_4 -> V_113 ; V_33 ++ )
if ( F_44 ( V_74 ) )
return 0 ;
return - V_40 ;
}
static bool F_45 ( void * V_74 )
{
struct V_3 * V_4 = (struct V_3 * ) V_74 ;
T_2 V_114 = 0 ;
F_2 ( & V_4 -> V_6 ) ;
F_3 ( V_10 , F_4 ( 0 ) ) ;
if ( F_5 ( V_36 ) & V_115 ) {
V_114 = F_46 ( V_114 , V_116 , V_117 , 1 ) ;
V_114 = F_46 ( V_114 , V_116 , V_118 , 1 ) ;
}
F_3 ( V_10 , F_4 ( 1 ) ) ;
if ( F_5 ( V_36 ) & V_115 ) {
V_114 = F_46 ( V_114 , V_116 , V_117 , 1 ) ;
V_114 = F_46 ( V_114 , V_116 , V_118 , 1 ) ;
}
F_3 ( V_10 , F_4 ( 0 ) ) ;
F_6 ( & V_4 -> V_6 ) ;
if ( V_114 ) {
V_4 -> V_7 . V_114 = V_114 ;
return true ;
} else {
V_4 -> V_7 . V_114 = 0 ;
return false ;
}
}
static int F_47 ( void * V_74 )
{
struct V_3 * V_4 = (struct V_3 * ) V_74 ;
T_2 V_114 ;
if ( ! V_4 -> V_7 . V_114 )
return 0 ;
V_114 = V_4 -> V_7 . V_114 ;
if ( V_114 ) {
T_2 V_61 ;
V_61 = F_5 ( V_119 ) ;
V_61 |= V_114 ;
F_48 ( V_4 -> V_120 , L_5 , V_61 ) ;
F_3 ( V_119 , V_61 ) ;
V_61 = F_5 ( V_119 ) ;
F_49 ( 50 ) ;
V_61 &= ~ V_114 ;
F_3 ( V_119 , V_61 ) ;
V_61 = F_5 ( V_119 ) ;
F_49 ( 50 ) ;
}
return 0 ;
}
static int F_50 ( void * V_74 )
{
struct V_3 * V_4 = (struct V_3 * ) V_74 ;
if ( ! V_4 -> V_7 . V_114 )
return 0 ;
F_14 ( 5 ) ;
return F_41 ( V_4 ) ;
}
static int F_51 ( void * V_74 )
{
struct V_3 * V_4 = (struct V_3 * ) V_74 ;
if ( ! V_4 -> V_7 . V_114 )
return 0 ;
F_14 ( 5 ) ;
return F_42 ( V_4 ) ;
}
static int F_52 ( struct V_3 * V_4 ,
struct V_121 * V_122 ,
unsigned type ,
enum V_123 V_124 )
{
T_3 V_125 = 0 ;
if ( V_124 == V_126 )
V_125 |= V_127 ;
F_19 ( V_128 , V_125 , ~ V_127 ) ;
return 0 ;
}
static int F_53 ( struct V_3 * V_4 ,
struct V_121 * V_122 ,
struct V_129 * V_130 )
{
F_54 ( L_6 ) ;
F_11 ( V_131 , V_132 , 1 ) ;
switch ( V_130 -> V_133 [ 0 ] ) {
case 0 :
case 1 :
case 2 :
F_55 ( & V_4 -> V_7 . V_2 [ V_130 -> V_133 [ 0 ] ] ) ;
break;
default:
F_15 ( L_7 ,
V_130 -> V_134 , V_130 -> V_133 [ 0 ] ) ;
break;
}
return 0 ;
}
static int F_40 ( void * V_74 ,
enum V_135 V_124 )
{
struct V_3 * V_4 = (struct V_3 * ) V_74 ;
bool V_136 = ( V_124 == V_86 ) ? true : false ;
int V_33 ;
if ( ! ( V_4 -> V_137 & V_138 ) )
return 0 ;
F_2 ( & V_4 -> V_6 ) ;
for ( V_33 = 0 ; V_33 < 2 ; V_33 ++ ) {
if ( V_4 -> V_7 . V_8 & ( 1 << V_33 ) )
continue;
F_3 ( V_10 , F_4 ( V_33 ) ) ;
if ( ! V_136 ) {
T_3 V_24 = F_5 ( V_89 ) ;
V_24 &= ~ ( 0xf | 0xff0 ) ;
V_24 |= ( ( 0x0 << 0 ) | ( 0x04 << 4 ) ) ;
F_3 ( V_89 , V_24 ) ;
V_24 = F_5 ( V_26 ) ;
V_24 &= ~ ( 0xf | 0xff0 ) ;
V_24 |= ( ( 0x0 << 0 ) | ( 0x04 << 4 ) ) ;
F_3 ( V_26 , V_24 ) ;
}
F_12 ( V_4 , V_136 ) ;
}
F_3 ( V_10 , V_15 ) ;
F_6 ( & V_4 -> V_6 ) ;
return 0 ;
}
static int F_56 ( void * V_74 ,
enum V_139 V_124 )
{
struct V_3 * V_4 = (struct V_3 * ) V_74 ;
int V_140 = 0 ;
if ( V_124 == V_141 ) {
V_140 = F_20 ( V_4 ) ;
if ( V_140 )
goto V_142;
} else {
V_140 = F_16 ( V_4 ) ;
if ( V_140 )
goto V_142;
}
V_142:
return V_140 ;
}
static void F_57 ( void * V_74 , T_2 * V_66 )
{
struct V_3 * V_4 = (struct V_3 * ) V_74 ;
int V_24 ;
F_2 ( & V_4 -> V_143 . V_144 ) ;
if ( V_4 -> V_66 & V_67 )
V_24 = F_22 ( V_145 ) ;
else
V_24 = F_22 ( V_146 ) ;
if ( V_24 & V_147 ) {
F_37 ( L_8 ) ;
goto V_142;
}
F_11 ( V_148 , V_149 , 0 ) ;
V_24 = F_5 ( V_89 ) ;
if ( V_24 & ( 0x04 << 4 ) )
* V_66 |= V_138 ;
V_142:
F_6 ( & V_4 -> V_143 . V_144 ) ;
}
static void F_58 ( struct V_1 * V_2 ,
struct V_150 * V_151 , unsigned int V_152 , bool V_153 )
{
F_59 ( V_2 , V_154 ) ;
F_59 ( V_2 , V_152 ) ;
F_59 ( V_2 , F_9 ( V_151 -> V_44 ) ) ;
F_59 ( V_2 , F_17 ( V_151 -> V_44 ) ) ;
F_59 ( V_2 , V_151 -> V_155 ) ;
}
static void F_60 ( struct V_1 * V_2 ,
unsigned int V_152 , T_1 V_156 )
{
F_59 ( V_2 , V_157 ) ;
F_59 ( V_2 , V_152 ) ;
F_59 ( V_2 , V_156 >> 12 ) ;
F_59 ( V_2 , V_158 ) ;
F_59 ( V_2 , V_152 ) ;
F_59 ( V_2 , V_159 ) ;
}
static void F_61 ( struct V_1 * V_2 )
{
T_3 V_160 = V_2 -> V_161 . V_162 ;
T_1 V_163 = V_2 -> V_161 . V_44 ;
F_59 ( V_2 , V_164 ) ;
F_59 ( V_2 , F_9 ( V_163 ) ) ;
F_59 ( V_2 , F_17 ( V_163 ) ) ;
F_59 ( V_2 , V_160 ) ;
}
static void F_24 ( struct V_3 * V_4 )
{
int V_33 ;
if ( V_4 -> V_56 >= V_57 ) {
for ( V_33 = 0 ; V_33 < V_4 -> V_7 . V_76 ; V_33 ++ )
V_4 -> V_7 . V_2 [ V_33 ] . V_165 = & V_166 ;
F_37 ( L_9 ) ;
} else {
for ( V_33 = 0 ; V_33 < V_4 -> V_7 . V_76 ; V_33 ++ )
V_4 -> V_7 . V_2 [ V_33 ] . V_165 = & V_167 ;
F_37 ( L_10 ) ;
}
}
static void F_25 ( struct V_3 * V_4 )
{
V_4 -> V_7 . V_78 . V_168 = 1 ;
V_4 -> V_7 . V_78 . V_165 = & V_169 ;
}
