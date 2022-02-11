static int F_1 ( struct V_1 * V_2 )
{
int V_3 ;
unsigned long V_4 ;
int V_5 ;
F_2 ( & V_2 -> V_6 , V_4 ) ;
F_3 ( V_7 , V_2 -> V_8 + V_9 ) ;
V_3 = F_4 ( V_2 -> V_8 + V_10 ) & 0x3 ;
F_5 ( & V_2 -> V_6 , V_4 ) ;
V_5 = V_11 - V_12 ;
switch ( V_3 ) {
case 0x0 :
if ( V_5 == V_13 ) {
F_6 ( V_2 -> V_14 , L_1 ) ;
return V_5 ;
}
if ( V_5 == V_15 ) {
F_6 ( V_2 -> V_14 , L_2 ) ;
return V_5 ;
}
F_6 ( V_2 -> V_14 , L_3 ) ;
return V_13 ;
break;
case 0x2 :
if ( V_5 == V_16 ) {
F_6 ( V_2 -> V_14 , L_4 ) ;
return V_5 ;
}
if ( V_5 == V_17 ) {
F_6 ( V_2 -> V_14 , L_5 ) ;
return V_5 ;
}
F_6 ( V_2 -> V_14 , L_6 ) ;
return V_16 ;
break;
case 0x3 :
if ( V_5 == V_18 ) {
F_6 ( V_2 -> V_14 , L_7 ) ;
return V_5 ;
}
if ( V_5 == V_19 ) {
F_6 ( V_2 -> V_14 , L_8 ) ;
return V_5 ;
}
if ( V_5 == V_20 ) {
F_6 ( V_2 -> V_14 , L_9 ) ;
return V_5 ;
}
F_6 ( V_2 -> V_14 , L_10 ) ;
return V_18 ;
break;
default:
F_6 ( V_2 -> V_14 ,
L_11 ,
V_3 ) ;
return V_5 ;
break;
}
return - 1 ;
}
static T_1 F_7 ( int V_21 , void * V_22 )
{
short V_23 ;
short V_24 = 0 ;
struct V_1 * V_2 = V_22 ;
struct V_25 * V_26 = V_2 -> V_27 ;
struct V_28 * V_29 = V_2 -> V_30 ;
struct V_31 * V_32 ;
int V_33 ;
unsigned long V_4 ;
static const int V_34 = 128 ;
int V_35 = 0 ;
int V_36 = 0 ;
V_33 = F_4 ( V_2 -> V_8 + V_37 ) ;
if ( ! ( V_33 & V_38 ) )
return V_39 ;
if ( ! ( V_2 -> V_40 ) )
return V_41 ;
V_32 = V_29 -> V_32 ;
F_2 ( & V_2 -> V_6 , V_4 ) ;
F_3 ( V_42 , V_2 -> V_8 + V_9 ) ;
V_33 = F_4 ( V_2 -> V_8 + V_43 ) & V_44 ;
if ( V_33 == 0 ) {
F_5 ( & V_2 -> V_6 , V_4 ) ;
return V_41 ;
}
for ( V_23 = 0 ; V_23 < V_34 ; V_23 ++ ) {
V_24 = F_4 ( V_2 -> V_8 + V_45 ) ;
V_24 += F_4 ( V_2 -> V_8 + V_46 ) << 8 ;
if ( V_11 -> V_47 == 12 ) {
V_35 = V_24 & V_48 ;
V_36 = V_24 & V_49 ;
if ( V_36 )
break;
} else {
V_35 = 0 ;
}
if ( V_35 )
break;
if ( V_11 -> V_47 == 12 )
V_24 = ( V_24 >> 4 ) & 0xfff ;
if ( V_26 -> V_50 > 0 || V_26 -> V_51 == 1 ) {
F_8 ( V_29 , V_24 ) ;
if ( V_26 -> V_50 > 0 )
V_26 -> V_50 -- ;
}
}
V_32 -> V_52 |= V_53 ;
if ( V_11 -> V_47 == 12 ) {
V_36 = V_24 & V_49 ;
} else {
V_36 = F_4 ( V_2 -> V_8 + V_9 ) & V_54 ;
}
if ( V_36 ) {
F_5 ( & V_2 -> V_6 , V_4 ) ;
F_9 ( V_2 , L_12 ) ;
F_10 ( V_2 , V_29 ) ;
V_32 -> V_52 |= V_55 | V_56 ;
F_11 ( V_2 , V_29 ) ;
V_32 -> V_52 = 0 ;
return V_41 ;
}
if ( V_26 -> V_50 > 0 || V_26 -> V_51 == 1 ) {
F_3 ( V_42 , V_2 -> V_8 + V_9 ) ;
F_3 ( V_57 | V_26 -> V_58 ,
V_2 -> V_8 + V_59 ) ;
F_5 ( & V_2 -> V_6 , V_4 ) ;
} else {
F_5 ( & V_2 -> V_6 , V_4 ) ;
F_12 ( V_2 ) ;
V_32 -> V_52 |= V_56 ;
}
F_11 ( V_2 , V_29 ) ;
V_32 -> V_52 = 0 ;
return V_41 ;
}
static int F_13 ( struct V_1 * V_2 , struct V_60 * V_61 )
{
struct V_25 * V_26 ;
struct V_28 * V_29 ;
unsigned long V_8 = V_61 -> V_62 [ 0 ] ;
unsigned int V_21 = V_61 -> V_62 [ 1 ] ;
unsigned long V_4 ;
int V_5 ;
int V_63 ;
F_14 ( V_2 -> V_14 , L_13 , V_8 ) ;
if ( V_21 )
F_6 ( V_2 -> V_14 , L_14 , V_21 ) ;
V_26 = F_15 ( sizeof( * V_26 ) , V_64 ) ;
if ( ! V_26 )
return - V_65 ;
V_2 -> V_27 = V_26 ;
if ( V_8 == 0 ) {
F_16 ( V_2 -> V_14 ,
L_15 ) ;
return - V_66 ;
}
if ( ! F_17 ( V_8 , V_67 , L_16 ) ) {
F_16 ( V_2 -> V_14 , L_17 ) ;
return - V_68 ;
}
V_2 -> V_8 = V_8 ;
V_5 = F_1 ( V_2 ) ;
if ( V_5 < 0 ) {
F_6 ( V_2 -> V_14 , L_18 ) ;
return - V_69 ;
}
V_2 -> V_70 = V_12 + V_5 ;
if ( V_21 == 1 || V_21 > 7 ) {
F_16 ( V_2 -> V_14 , L_19 ) ;
return - V_66 ;
}
if ( V_21 ) {
if ( F_18 ( V_21 , F_7 , 0 , L_16 , V_2 ) ) {
F_16 ( V_2 -> V_14 , L_20 ,
V_21 ) ;
return - V_66 ;
}
}
V_2 -> V_21 = V_21 ;
V_2 -> V_71 = V_11 -> V_72 ;
V_63 = F_19 ( V_2 , 3 ) ;
if ( V_63 )
return V_63 ;
V_29 = & V_2 -> V_73 [ 0 ] ;
V_2 -> V_30 = V_29 ;
V_29 -> type = V_74 ;
V_29 -> V_75 = V_76 | V_77 | V_78 ;
V_29 -> V_79 = 8 ;
V_29 -> V_80 = 8 ;
V_29 -> V_81 = ( 1 << V_11 -> V_47 ) - 1 ;
V_29 -> V_82 = V_11 -> V_83 ;
V_29 -> V_84 = V_85 ;
V_29 -> V_86 = V_87 ;
V_29 -> V_88 = V_89 ;
V_29 -> V_90 = F_10 ;
V_29 = & V_2 -> V_73 [ 1 ] ;
V_29 -> type = V_91 ;
V_29 -> V_75 = V_76 ;
V_29 -> V_79 = 3 ;
V_29 -> V_81 = 1 ;
V_29 -> V_82 = & V_92 ;
V_29 -> V_93 = V_94 ;
V_29 = & V_2 -> V_73 [ 2 ] ;
V_29 -> type = V_95 ;
V_29 -> V_75 = V_96 | V_76 ;
V_29 -> V_79 = 4 ;
V_29 -> V_81 = 1 ;
V_29 -> V_82 = & V_92 ;
V_29 -> V_93 = V_97 ;
F_12 ( V_2 ) ;
F_2 ( & V_2 -> V_6 , V_4 ) ;
F_3 ( V_42 , V_2 -> V_8 + V_9 ) ;
F_3 ( V_57 | V_26 -> V_58 , V_2 -> V_8 + V_59 ) ;
F_5 ( & V_2 -> V_6 , V_4 ) ;
return 0 ;
}
static void F_20 ( struct V_1 * V_2 )
{
if ( V_2 -> V_8 )
F_21 ( V_2 -> V_8 , V_67 ) ;
if ( V_2 -> V_21 )
F_22 ( V_2 -> V_21 , V_2 ) ;
}
static int F_10 ( struct V_1 * V_2 , struct V_28 * V_29 )
{
struct V_25 * V_26 = V_2 -> V_27 ;
V_26 -> V_51 = 0 ;
V_26 -> V_50 = 0 ;
F_12 ( V_2 ) ;
return 0 ;
}
static void F_23 ( struct V_1 * V_2 )
{
struct V_25 * V_26 = V_2 -> V_27 ;
unsigned long V_4 ;
F_2 ( & V_2 -> V_6 , V_4 ) ;
if ( V_11 -> V_47 == 16 )
F_3 ( V_98 , V_2 -> V_8 + V_9 ) ;
F_3 ( V_99 , V_2 -> V_8 + V_9 ) ;
F_3 ( V_100 , V_2 -> V_8 + V_101 ) ;
F_3 ( V_42 , V_2 -> V_8 + V_9 ) ;
F_3 ( V_57 | V_26 -> V_58 , V_2 -> V_8 + V_59 ) ;
F_5 ( & V_2 -> V_6 , V_4 ) ;
}
static void F_12 ( struct V_1 * V_2 )
{
unsigned long V_4 ;
F_2 ( & V_2 -> V_6 , V_4 ) ;
F_3 ( V_99 , V_2 -> V_8 + V_9 ) ;
F_3 ( 0x0 , V_2 -> V_8 + V_101 ) ;
F_5 ( & V_2 -> V_6 , V_4 ) ;
}
static int V_87 ( struct V_1 * V_2 ,
struct V_28 * V_29 ,
struct V_102 * V_103 )
{
struct V_25 * V_26 = V_2 -> V_27 ;
int V_104 = 0 ;
int V_105 ;
int V_106 , V_107 ;
int V_23 ;
V_104 |= F_24 ( & V_103 -> V_108 , V_109 | V_110 ) ;
V_104 |= F_24 ( & V_103 -> V_111 , V_112 ) ;
V_104 |= F_24 ( & V_103 -> V_113 , V_114 | V_110 ) ;
V_104 |= F_24 ( & V_103 -> V_115 , V_116 ) ;
V_104 |= F_24 ( & V_103 -> V_117 , V_116 | V_118 ) ;
if ( V_104 )
return 1 ;
V_104 |= F_25 ( V_103 -> V_108 ) ;
V_104 |= F_25 ( V_103 -> V_113 ) ;
V_104 |= F_25 ( V_103 -> V_117 ) ;
if ( V_104 )
return 2 ;
V_104 |= F_26 ( & V_103 -> V_119 , 0 ) ;
if ( V_103 -> V_113 == V_114 )
V_104 |= F_27 ( & V_103 -> V_120 ,
V_11 -> V_121 ) ;
V_104 |= F_27 ( & V_103 -> V_122 , 1 ) ;
V_104 |= F_26 ( & V_103 -> V_123 , V_103 -> V_122 ) ;
if ( V_103 -> V_117 == V_116 )
V_104 |= F_27 ( & V_103 -> V_124 , 1 ) ;
else
V_104 |= F_26 ( & V_103 -> V_124 , 0 ) ;
if ( V_104 )
return 3 ;
if ( V_103 -> V_113 == V_114 ) {
V_105 = V_103 -> V_120 ;
F_28 ( V_125 , & ( V_26 -> V_126 ) ,
& ( V_26 -> V_127 ) ,
& ( V_103 -> V_120 ) ,
V_103 -> V_128 & V_129 ) ;
if ( V_105 != V_103 -> V_120 )
V_104 ++ ;
}
if ( V_104 )
return 4 ;
if ( V_103 -> V_130 ) {
V_106 = F_29 ( V_103 -> V_130 [ 0 ] ) ;
V_107 = F_30 ( V_103 -> V_130 [ 0 ] ) ;
for ( V_23 = 1 ; V_23 < V_103 -> V_122 ; V_23 ++ ) {
if ( F_30 ( V_103 -> V_130 [ V_23 ] ) !=
( V_107 + V_23 ) % V_131 ) {
F_9 ( V_2 ,
L_21 ) ;
V_104 ++ ;
}
if ( F_29 ( V_103 -> V_130 [ V_23 ] ) != V_106 ) {
F_9 ( V_2 ,
L_22 ) ;
V_104 ++ ;
}
}
}
if ( V_104 )
return 5 ;
return 0 ;
}
static int V_85 ( struct V_1 * V_2 ,
struct V_28 * V_29 )
{
struct V_25 * V_26 = V_2 -> V_27 ;
int V_107 , V_132 , V_133 , V_106 ;
int V_134 ;
unsigned long V_4 ;
struct V_31 * V_32 = V_29 -> V_32 ;
if ( ! V_2 -> V_21 ) {
F_9 ( V_2 ,
L_23 ) ;
return - 1 ;
}
F_12 ( V_2 ) ;
V_107 = F_30 ( V_32 -> V_103 . V_130 [ 0 ] ) ;
V_132 = ( V_107 + V_32 -> V_103 . V_122 - 1 ) % 8 ;
V_133 = ( V_132 << 3 ) | V_107 ;
F_2 ( & V_2 -> V_6 , V_4 ) ;
F_3 ( V_135 , V_2 -> V_8 + V_9 ) ;
F_3 ( V_133 , V_2 -> V_8 + V_136 ) ;
F_5 ( & V_2 -> V_6 , V_4 ) ;
V_106 = F_29 ( V_32 -> V_103 . V_130 [ 0 ] ) ;
if ( V_11 -> V_47 == 12 && V_106 > 0 )
V_106 += 0x7 ;
V_106 &= 0xf ;
F_3 ( V_106 , V_2 -> V_8 + V_9 ) ;
switch ( V_32 -> V_103 . V_117 ) {
case V_116 :
V_26 -> V_50 = V_32 -> V_103 . V_124 * V_32 -> V_103 . V_122 ;
V_26 -> V_51 = 0 ;
break;
case V_118 :
V_26 -> V_51 = 1 ;
V_26 -> V_50 = 0 ;
break;
default:
break;
}
V_134 = 0 ;
V_134 |= V_137 | V_138 ;
if ( V_32 -> V_103 . V_108 == V_110 )
V_134 |= V_139 ;
switch ( V_32 -> V_103 . V_113 ) {
case V_114 :
V_134 |= V_140 | V_141 ;
F_28 ( V_125 , & ( V_26 -> V_126 ) ,
& ( V_26 -> V_127 ) ,
& ( V_32 -> V_103 . V_120 ) ,
V_32 -> V_103 .
V_128 & V_129 ) ;
if ( F_31 ( V_2 ) < 0 ) {
F_9 ( V_2 , L_24 ) ;
return - 1 ;
}
break;
case V_110 :
break;
default:
break;
}
F_2 ( & V_2 -> V_6 , V_4 ) ;
F_3 ( V_99 , V_2 -> V_8 + V_9 ) ;
F_3 ( V_134 , V_2 -> V_8 + V_101 ) ;
F_5 ( & V_2 -> V_6 , V_4 ) ;
V_32 -> V_52 = 0 ;
F_23 ( V_2 ) ;
return 0 ;
}
static int V_89 ( struct V_1 * V_2 ,
struct V_28 * V_29 , struct V_142 * V_143 ,
unsigned int * V_144 )
{
struct V_25 * V_26 = V_2 -> V_27 ;
int V_23 , V_145 ;
int V_146 ;
int V_147 ;
int V_148 , V_149 ;
int V_150 = 1000 ;
unsigned long V_4 ;
F_12 ( V_2 ) ;
V_146 = F_30 ( V_143 -> V_151 ) ;
F_2 ( & V_2 -> V_6 , V_4 ) ;
F_3 ( V_42 , V_2 -> V_8 + V_9 ) ;
F_3 ( V_146 | V_26 -> V_58 , V_2 -> V_8 + V_59 ) ;
F_5 ( & V_2 -> V_6 , V_4 ) ;
V_147 = F_29 ( V_143 -> V_151 ) ;
if ( V_11 -> V_47 == 12 && V_147 )
V_147 += 0x7 ;
V_147 &= 0xf ;
F_3 ( V_147 , V_2 -> V_8 + V_9 ) ;
F_32 ( 5 ) ;
for ( V_145 = 0 ; V_145 < V_143 -> V_145 ; V_145 ++ ) {
F_33 ( 0 , V_2 -> V_8 + V_46 ) ;
for ( V_23 = 0 ; V_23 < V_150 ; V_23 ++ ) {
if ( ! ( F_4 ( V_2 -> V_8 + V_37 ) & V_152 ) )
break;
}
if ( V_23 == V_150 ) {
F_9 ( V_2 , L_25 ) ;
return - V_153 ;
}
V_148 = F_4 ( V_2 -> V_8 + V_45 ) ;
V_149 = F_4 ( V_2 -> V_8 + V_46 ) ;
if ( V_11 -> V_47 == 12 ) {
V_144 [ V_145 ] = ( V_148 >> 4 ) & 0xff ;
V_144 [ V_145 ] |= ( V_149 << 4 ) ;
} else {
V_144 [ V_145 ] = ( V_149 << 8 ) | V_148 ;
}
}
return V_145 ;
}
static int V_94 ( struct V_1 * V_2 ,
struct V_28 * V_29 , struct V_142 * V_143 ,
unsigned int * V_144 )
{
unsigned int V_154 ;
V_154 = F_4 ( V_2 -> V_8 + V_37 ) >> 4 ;
V_154 &= 0x7 ;
V_144 [ 1 ] = V_154 ;
V_144 [ 0 ] = 0 ;
return V_143 -> V_145 ;
}
static int V_97 ( struct V_1 * V_2 ,
struct V_28 * V_29 , struct V_142 * V_143 ,
unsigned int * V_144 )
{
struct V_25 * V_26 = V_2 -> V_27 ;
int V_155 ;
unsigned long V_4 ;
V_144 [ 0 ] &= 0xf ;
V_155 = V_26 -> V_58 >> 4 ;
V_155 &= ~ V_144 [ 0 ] ;
V_155 |= V_144 [ 0 ] & V_144 [ 1 ] ;
V_26 -> V_58 = V_155 << 4 ;
F_2 ( & V_2 -> V_6 , V_4 ) ;
F_3 ( V_42 , V_2 -> V_8 + V_9 ) ;
F_3 ( V_26 -> V_58 | V_57 , V_2 -> V_8 + V_59 ) ;
F_5 ( & V_2 -> V_6 , V_4 ) ;
V_144 [ 1 ] = V_155 ;
return V_143 -> V_145 ;
}
static int F_31 ( struct V_1 * V_2 )
{
struct V_25 * V_26 = V_2 -> V_27 ;
int V_104 = 0 ;
if ( F_34 ( V_2 -> V_8 + V_156 , 0 , 1 , V_26 -> V_126 , 2 ) )
V_104 ++ ;
if ( F_34 ( V_2 -> V_8 + V_156 , 0 , 2 , V_26 -> V_127 , 2 ) )
V_104 ++ ;
if ( V_104 )
return - 1 ;
return 0 ;
}
