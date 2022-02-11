static unsigned int F_1 ( unsigned int V_1 , unsigned int V_2 )
{
return ( ( V_1 & 3 ) << 3 ) | ( V_2 & 7 ) ;
}
static unsigned int F_2 ( unsigned int V_1 , unsigned int V_2 )
{
return ( ( V_1 & 3 ) << 3 ) | ( V_2 & 7 ) ;
}
static void
F_3 ( struct V_3 * V_4 , int V_1 , int V_5 ,
unsigned int V_6 )
{
const struct V_7 * V_8 = V_4 -> V_9 ;
struct V_10 * V_11 = V_4 -> V_12 ;
unsigned short V_13 ;
F_4 ( 1 << V_1 , V_4 -> V_14 + V_15 ) ;
V_11 -> V_16 = F_5 ( V_11 -> V_16 , V_8 -> V_17 [ V_5 ] ,
V_18 |
V_19 ) ;
F_4 ( V_11 -> V_16 | V_20 ,
V_4 -> V_14 + V_21 ) ;
V_13 = ( unsigned short ) V_6 << ( 16 - V_8 -> V_22 ) ;
if ( ( V_11 -> V_16 & V_18 ) ==
V_23 ) {
V_13 ^= 0x8000 ;
}
F_4 ( V_13 , V_4 -> V_14 + V_24 ) ;
F_6 ( V_4 -> V_14 + V_25 ) ;
}
static int F_7 ( struct V_3 * V_4 ,
struct V_26 * V_27 ,
struct V_28 * V_29 ,
unsigned int * V_6 )
{
unsigned int V_1 = F_8 ( V_29 -> V_30 ) ;
unsigned int V_5 = F_9 ( V_29 -> V_30 ) ;
unsigned int V_31 = V_27 -> V_32 [ V_1 ] ;
int V_33 ;
for ( V_33 = 0 ; V_33 < V_29 -> V_34 ; V_33 ++ ) {
V_31 = V_6 [ V_33 ] ;
F_3 ( V_4 , V_1 , V_5 , V_31 ) ;
}
V_27 -> V_32 [ V_1 ] = V_31 ;
return V_29 -> V_34 ;
}
static void F_10 ( struct V_3 * V_4 ,
struct V_26 * V_27 )
{
struct V_10 * V_11 = V_4 -> V_12 ;
unsigned long V_35 ;
if ( ! F_11 ( V_36 , & V_11 -> V_37 ) )
return;
F_12 ( & V_11 -> V_38 , V_35 ) ;
V_11 -> V_39 = 0 ;
F_13 ( 0 , V_11 -> V_40 + V_41 ) ;
while ( V_11 -> V_42 && V_11 -> V_43 != V_44 ) {
F_14 ( & V_11 -> V_38 , V_35 ) ;
F_12 ( & V_11 -> V_38 , V_35 ) ;
}
F_14 ( & V_11 -> V_38 , V_35 ) ;
F_4 ( 0 , V_4 -> V_14 + V_15 ) ;
V_11 -> V_16 =
F_5 ( V_11 -> V_16 ,
V_45 | V_46 ,
V_47 | V_48 ) ;
F_4 ( V_11 -> V_16 | V_20 ,
V_4 -> V_14 + V_21 ) ;
}
static void F_15 ( struct V_3 * V_4 ,
struct V_26 * V_27 )
{
struct V_10 * V_11 = V_4 -> V_12 ;
struct V_49 * V_50 = & V_27 -> V_51 -> V_50 ;
unsigned long V_35 ;
F_16 ( V_36 , & V_11 -> V_37 ) ;
F_12 ( & V_11 -> V_38 , V_35 ) ;
if ( V_50 -> V_52 == V_53 )
V_11 -> V_39 = V_54 | V_55 ;
else
V_11 -> V_39 = V_55 ;
F_13 ( V_11 -> V_39 , V_11 -> V_40 + V_41 ) ;
F_14 ( & V_11 -> V_38 , V_35 ) ;
}
static void F_17 ( struct V_3 * V_4 ,
struct V_26 * V_27 )
{
struct V_10 * V_11 = V_4 -> V_12 ;
struct V_49 * V_50 = & V_27 -> V_51 -> V_50 ;
unsigned int V_56 = F_18 ( V_27 , 0 ) ;
unsigned int V_57 ;
unsigned short V_58 ;
unsigned int V_33 , V_34 ;
V_58 = F_6 ( V_4 -> V_14 + V_21 ) ;
switch ( V_58 & V_59 ) {
case V_60 :
V_57 = V_61 ;
if ( V_50 -> V_52 == V_62 &&
V_27 -> V_51 -> V_63 >= V_50 -> V_64 ) {
V_27 -> V_51 -> V_65 |= V_66 ;
F_19 ( V_4 , V_27 ) ;
return;
}
break;
case V_67 :
V_57 = V_68 ;
break;
case V_69 :
V_57 = V_70 ;
break;
default:
V_57 = V_71 ;
break;
}
if ( V_57 >= V_68 ) {
if ( V_56 == 0 ) {
F_20 ( V_4 -> V_72 , L_1 ) ;
V_27 -> V_51 -> V_65 |= V_73 ;
}
}
V_57 /= V_50 -> V_74 ;
if ( V_56 > V_57 )
V_56 = V_57 ;
for ( V_34 = 0 ; V_34 < V_56 ; V_34 ++ ) {
F_21 ( V_27 , & V_11 -> V_75 [ 0 ] ,
V_50 -> V_74 ) ;
for ( V_33 = 0 ; V_33 < V_50 -> V_74 ; V_33 ++ ) {
F_4 ( V_11 -> V_75 [ V_11 -> V_76 [ V_33 ] ] ,
V_4 -> V_14 + V_24 ) ;
}
}
if ( V_50 -> V_52 == V_62 &&
V_27 -> V_51 -> V_63 >= V_50 -> V_64 ) {
V_11 -> V_16 = F_5 ( V_11 -> V_16 ,
V_46 ,
V_48 ) ;
F_4 ( V_11 -> V_16 , V_4 -> V_14 + V_21 ) ;
}
if ( ( V_11 -> V_16 & V_47 ) ==
V_77 ) {
unsigned short V_78 ;
if ( V_50 -> V_79 == V_80 ) {
V_78 = V_81 ;
} else {
if ( V_50 -> V_82 & V_83 )
V_78 = V_84 ;
else
V_78 = V_85 ;
}
V_11 -> V_16 =
F_5 ( V_11 -> V_16 , V_78 , V_47 ) ;
F_4 ( V_11 -> V_16 , V_4 -> V_14 + V_21 ) ;
}
F_19 ( V_4 , V_27 ) ;
}
static int F_22 ( struct V_3 * V_4 ,
struct V_26 * V_27 ,
unsigned int V_86 )
{
struct V_49 * V_50 = & V_27 -> V_51 -> V_50 ;
if ( V_86 != V_50 -> V_87 )
return - V_88 ;
V_27 -> V_51 -> V_89 = NULL ;
F_15 ( V_4 , V_27 ) ;
return 1 ;
}
static int F_23 ( struct V_3 * V_4 ,
struct V_26 * V_27 ,
struct V_49 * V_50 )
{
const struct V_7 * V_8 = V_4 -> V_9 ;
unsigned int V_90 ;
unsigned int V_91 = 0 ;
int V_33 ;
V_90 = V_8 -> V_92 [ F_9 ( V_50 -> V_93 [ 0 ] ) ] ;
for ( V_33 = 0 ; V_33 < V_50 -> V_74 ; V_33 ++ ) {
unsigned int V_1 = F_8 ( V_50 -> V_93 [ V_33 ] ) ;
if ( V_91 & ( 1 << V_1 ) ) {
F_24 ( V_4 -> V_72 ,
L_2 ,
V_94 ) ;
return - V_88 ;
}
V_91 |= 1 << V_1 ;
if ( V_8 -> V_92 [ F_9 ( V_50 -> V_93 [ V_33 ] ) ] !=
V_90 ) {
F_24 ( V_4 -> V_72 ,
L_3 ,
V_94 ) ;
return - V_88 ;
}
}
return 0 ;
}
static int
F_25 ( struct V_3 * V_4 , struct V_26 * V_27 ,
struct V_49 * V_50 )
{
int V_95 = 0 ;
unsigned int V_96 ;
V_95 |= F_26 ( & V_50 -> V_97 , V_98 | V_53 ) ;
V_95 |= F_26 ( & V_50 -> V_79 ,
V_53 | V_80 ) ;
V_95 |= F_26 ( & V_50 -> V_99 , V_100 ) ;
V_95 |= F_26 ( & V_50 -> V_101 , V_62 ) ;
V_95 |= F_26 ( & V_50 -> V_52 ,
V_62 | V_53 | V_102 ) ;
if ( V_95 )
return 1 ;
V_95 |= F_27 ( V_50 -> V_97 ) ;
V_95 |= F_27 ( V_50 -> V_79 ) ;
V_95 |= F_27 ( V_50 -> V_52 ) ;
V_96 = 0 ;
if ( V_50 -> V_97 & V_53 )
V_96 ++ ;
if ( V_50 -> V_79 & V_53 )
V_96 ++ ;
if ( V_50 -> V_52 & V_53 )
V_96 ++ ;
if ( V_96 > 1 )
V_95 |= - V_88 ;
if ( V_95 )
return 2 ;
switch ( V_50 -> V_97 ) {
case V_98 :
V_95 |= F_28 ( & V_50 -> V_87 , 0 ) ;
break;
case V_53 :
if ( V_50 -> V_87 & ~ V_103 ) {
V_50 -> V_87 =
F_5 ( V_50 -> V_87 , 0 , ~ V_103 ) ;
V_95 |= - V_88 ;
}
if ( V_50 -> V_87 & V_103 & ~ V_104 ) {
V_50 -> V_87 = F_5 ( V_50 -> V_87 , 0 ,
V_103 & ~ V_104 ) ;
V_95 |= - V_88 ;
}
break;
}
switch ( V_50 -> V_79 ) {
case V_80 :
V_95 |= F_29 ( & V_50 -> V_82 ,
V_105 ) ;
V_96 = V_50 -> V_74 * V_106 ;
if ( V_96 < V_107 )
V_96 = V_107 ;
V_95 |= F_30 ( & V_50 -> V_82 , V_96 ) ;
break;
case V_53 :
if ( V_50 -> V_82 & ~ V_103 ) {
V_50 -> V_82 =
F_5 ( V_50 -> V_82 , 0 , ~ V_103 ) ;
V_95 |= - V_88 ;
}
if ( V_50 -> V_82 & V_103 &
~ ( V_104 | V_83 ) ) {
V_50 -> V_82 =
F_5 ( V_50 -> V_82 , 0 ,
V_103 & ~ ( V_104 | V_83 ) ) ;
V_95 |= - V_88 ;
}
break;
}
V_95 |= F_28 ( & V_50 -> V_108 , 0 ) ;
V_95 |= F_28 ( & V_50 -> V_109 ,
V_50 -> V_74 ) ;
switch ( V_50 -> V_52 ) {
case V_62 :
V_95 |= F_30 ( & V_50 -> V_64 , 1 ) ;
break;
case V_53 :
if ( V_50 -> V_64 & ~ V_103 ) {
V_50 -> V_64 =
F_5 ( V_50 -> V_64 , 0 , ~ V_103 ) ;
V_95 |= - V_88 ;
}
if ( V_50 -> V_64 & V_103 & ~ V_104 ) {
V_50 -> V_64 =
F_5 ( V_50 -> V_64 , 0 , V_103 & ~ V_104 ) ;
}
break;
case V_102 :
V_95 |= F_28 ( & V_50 -> V_64 , 0 ) ;
break;
}
if ( V_95 )
return 3 ;
if ( V_50 -> V_79 == V_80 ) {
V_96 = V_50 -> V_82 ;
F_31 ( V_4 -> V_110 , & V_96 , V_50 -> V_35 ) ;
V_95 |= F_28 ( & V_50 -> V_82 , V_96 ) ;
}
if ( V_95 )
return 4 ;
if ( V_50 -> V_93 && V_50 -> V_74 > 0 )
V_95 |= F_23 ( V_4 , V_27 , V_50 ) ;
if ( V_95 )
return 5 ;
return 0 ;
}
static void F_32 ( struct V_3 * V_4 ,
struct V_26 * V_27 )
{
struct V_10 * V_11 = V_4 -> V_12 ;
F_13 ( F_2 ( 0 , V_111 ) , V_11 -> V_40 + V_112 ) ;
F_13 ( F_2 ( 2 , V_111 ) , V_11 -> V_40 + V_112 ) ;
F_13 ( F_1 ( 2 , V_113 ) ,
V_11 -> V_40 + V_114 ) ;
F_13 ( F_1 ( 0 , V_115 ) ,
V_11 -> V_40 + V_114 ) ;
F_33 ( V_4 -> V_110 , 2 , 0 , false ) ;
}
static int F_34 ( struct V_3 * V_4 , struct V_26 * V_27 )
{
const struct V_7 * V_8 = V_4 -> V_9 ;
struct V_10 * V_11 = V_4 -> V_12 ;
struct V_49 * V_50 = & V_27 -> V_51 -> V_50 ;
int V_5 ;
unsigned int V_33 , V_116 ;
unsigned int V_117 ;
unsigned int V_118 ;
unsigned long V_35 ;
if ( ! V_50 -> V_93 || V_50 -> V_74 == 0 )
return - V_88 ;
V_11 -> V_119 = 0 ;
for ( V_33 = 0 ; V_33 < V_50 -> V_74 ; V_33 ++ ) {
V_117 = F_8 ( V_50 -> V_93 [ V_33 ] ) ;
V_11 -> V_119 |= 1U << V_117 ;
V_118 = 0 ;
for ( V_116 = 0 ; V_116 < V_50 -> V_74 ; V_116 ++ ) {
if ( F_8 ( V_50 -> V_93 [ V_116 ] ) < V_117 )
V_118 ++ ;
}
V_11 -> V_76 [ V_118 ] = V_33 ;
}
F_4 ( V_11 -> V_119 , V_4 -> V_14 + V_15 ) ;
V_5 = F_9 ( V_50 -> V_93 [ 0 ] ) ;
V_11 -> V_16 =
F_5 ( V_11 -> V_16 ,
V_8 -> V_17 [ V_5 ] | V_77 |
V_120 ,
V_18 | V_19 |
V_47 | V_48 ) ;
F_4 ( V_11 -> V_16 | V_20 ,
V_4 -> V_14 + V_21 ) ;
if ( V_50 -> V_79 == V_80 ) {
F_35 ( V_4 -> V_110 ) ;
F_32 ( V_4 , V_27 ) ;
}
F_12 ( & V_11 -> V_38 , V_35 ) ;
if ( V_50 -> V_97 == V_98 ) {
V_27 -> V_51 -> V_89 = F_22 ;
} else {
V_11 -> V_39 |= V_54 ;
F_13 ( V_11 -> V_39 , V_11 -> V_40 + V_41 ) ;
}
F_14 ( & V_11 -> V_38 , V_35 ) ;
return 0 ;
}
static int F_36 ( struct V_3 * V_4 ,
struct V_26 * V_27 )
{
F_10 ( V_4 , V_27 ) ;
return 0 ;
}
static void
F_37 ( struct V_3 * V_4 , struct V_26 * V_27 ,
void * V_6 , unsigned int V_121 , unsigned int V_122 )
{
const struct V_7 * V_8 = V_4 -> V_9 ;
struct V_49 * V_50 = & V_27 -> V_51 -> V_50 ;
unsigned short * V_123 = V_6 ;
unsigned int V_124 = V_121 / sizeof( * V_123 ) ;
unsigned int V_125 ;
unsigned int V_126 ;
unsigned int V_33 ;
V_126 = 16 - V_8 -> V_22 ;
if ( ( V_8 -> V_17 [ F_9 ( V_50 -> V_93 [ 0 ] ) ] &
V_18 ) == V_127 ) {
V_125 = 0 ;
} else {
V_125 = 32768 ;
}
for ( V_33 = 0 ; V_33 < V_124 ; V_33 ++ )
V_123 [ V_33 ] = ( V_123 [ V_33 ] << V_126 ) - V_125 ;
}
static T_1 F_38 ( int V_128 , void * V_129 )
{
struct V_3 * V_4 = V_129 ;
struct V_10 * V_11 = V_4 -> V_12 ;
struct V_26 * V_27 = V_4 -> V_130 ;
struct V_49 * V_50 ;
unsigned char V_131 , V_132 ;
unsigned char V_133 ;
int V_134 = 0 ;
unsigned long V_35 ;
V_131 = F_39 ( V_11 -> V_40 + V_41 ) & 0x3F ;
if ( V_131 ) {
V_134 = 1 ;
F_12 ( & V_11 -> V_38 , V_35 ) ;
V_132 = V_11 -> V_39 & V_131 ;
V_133 = V_11 -> V_39 & ~ V_131 ;
F_13 ( V_133 , V_11 -> V_40 + V_41 ) ;
V_11 -> V_42 = 1 ;
V_11 -> V_43 = V_44 ;
F_14 ( & V_11 -> V_38 , V_35 ) ;
if ( V_132 ) {
V_50 = & V_27 -> V_51 -> V_50 ;
if ( V_132 & V_54 ) {
V_11 -> V_39 &= ~ V_54 ;
if ( V_50 -> V_97 == V_53 )
F_15 ( V_4 , V_27 ) ;
else if ( V_50 -> V_52 == V_53 )
F_10 ( V_4 , V_27 ) ;
}
if ( V_132 & V_55 )
F_17 ( V_4 , V_27 ) ;
}
F_12 ( & V_11 -> V_38 , V_35 ) ;
if ( V_133 != V_11 -> V_39 ) {
F_13 ( V_11 -> V_39 ,
V_11 -> V_40 + V_41 ) ;
}
V_11 -> V_42 = 0 ;
F_14 ( & V_11 -> V_38 , V_35 ) ;
}
return F_40 ( V_134 ) ;
}
static int
F_41 ( struct V_3 * V_4 , unsigned long V_135 )
{
struct V_136 * V_136 = F_42 ( V_4 ) ;
const struct V_7 * V_8 = NULL ;
struct V_10 * V_11 ;
struct V_26 * V_27 ;
unsigned int V_128 ;
int V_137 ;
if ( V_135 < F_43 ( V_138 ) )
V_8 = & V_138 [ V_135 ] ;
if ( ! V_8 || ! V_8 -> V_139 ) {
F_20 ( V_4 -> V_72 ,
L_4 ) ;
return - V_88 ;
}
V_4 -> V_9 = V_8 ;
V_4 -> V_140 = V_8 -> V_139 ;
F_44 ( V_4 -> V_72 , L_5 ,
F_45 ( V_136 ) , V_4 -> V_140 ) ;
V_11 = F_46 ( V_4 , sizeof( * V_11 ) ) ;
if ( ! V_11 )
return - V_141 ;
V_137 = F_47 ( V_4 ) ;
if ( V_137 )
return V_137 ;
F_48 ( & V_11 -> V_38 ) ;
V_11 -> V_40 = F_49 ( V_136 , 2 ) ;
V_4 -> V_14 = F_49 ( V_136 , 3 ) ;
V_128 = V_136 -> V_128 ;
V_11 -> V_75 = F_50 ( V_8 -> V_142 ,
sizeof( V_11 -> V_75 [ 0 ] ) ,
V_143 ) ;
if ( ! V_11 -> V_75 )
return - V_141 ;
V_11 -> V_76 =
F_50 ( V_8 -> V_142 ,
sizeof( V_11 -> V_76 [ 0 ] ) ,
V_143 ) ;
if ( ! V_11 -> V_76 )
return - V_141 ;
V_11 -> V_39 = 0 ;
F_13 ( 0 , V_11 -> V_40 + V_41 ) ;
F_4 ( V_144 , V_4 -> V_14 + V_21 ) ;
F_4 ( 0 , V_4 -> V_14 + V_15 ) ;
F_4 ( 0 , V_4 -> V_14 + V_145 ) ;
V_11 -> V_16 = V_45 | V_23 |
V_146 | V_46 ;
F_4 ( V_11 -> V_16 | V_20 ,
V_4 -> V_14 + V_21 ) ;
V_4 -> V_110 = F_51 ( V_11 -> V_40 + V_147 ,
V_148 , V_149 , 0 ) ;
if ( ! V_4 -> V_110 )
return - V_141 ;
V_137 = F_52 ( V_4 , 1 ) ;
if ( V_137 )
return V_137 ;
V_27 = & V_4 -> V_150 [ 0 ] ;
V_27 -> type = V_151 ;
V_27 -> V_152 = V_153 | V_154 | V_155 ;
V_27 -> V_156 = V_8 -> V_142 ;
V_27 -> V_157 = ( 1 << V_8 -> V_22 ) - 1 ;
V_27 -> V_158 = V_8 -> V_159 ;
V_27 -> V_160 = F_7 ;
V_27 -> V_161 = V_27 -> V_156 ;
V_4 -> V_130 = V_27 ;
V_27 -> V_162 = F_34 ;
V_27 -> V_163 = F_25 ;
V_27 -> V_164 = F_36 ;
V_27 -> V_165 = F_37 ;
V_137 = F_53 ( V_27 ) ;
if ( V_137 )
return V_137 ;
if ( V_128 ) {
V_137 = F_54 ( V_128 , F_38 , V_166 ,
V_4 -> V_140 , V_4 ) ;
if ( V_137 < 0 ) {
F_20 ( V_4 -> V_72 ,
L_6 , V_128 ) ;
return V_137 ;
}
V_4 -> V_128 = V_128 ;
}
return 0 ;
}
static void F_55 ( struct V_3 * V_4 )
{
struct V_10 * V_11 = V_4 -> V_12 ;
F_56 ( V_4 ) ;
if ( V_11 ) {
F_57 ( V_11 -> V_75 ) ;
F_57 ( V_11 -> V_76 ) ;
}
}
static int F_58 ( struct V_136 * V_4 ,
const struct V_167 * V_168 )
{
return F_59 ( V_4 , & V_169 ,
V_168 -> V_170 ) ;
}
