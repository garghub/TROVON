static void
F_1 ( struct V_1 * V_2 , int V_3 , int V_4 ,
unsigned int V_5 )
{
const struct V_6 * V_7 = V_2 -> V_8 ;
struct V_9 * V_10 = V_2 -> V_11 ;
unsigned short V_12 ;
F_2 ( 1 << V_3 , V_2 -> V_13 + V_14 ) ;
V_10 -> V_15 = F_3 ( V_10 -> V_15 , V_7 -> V_16 [ V_4 ] ,
V_17 |
V_18 ) ;
F_2 ( V_10 -> V_15 | V_19 ,
V_2 -> V_13 + V_20 ) ;
V_12 = ( unsigned short ) V_5 << ( 16 - V_7 -> V_21 ) ;
if ( ( V_10 -> V_15 & V_17 ) ==
V_22 ) {
V_12 ^= 0x8000 ;
}
F_2 ( V_12 , V_2 -> V_13 + V_23 ) ;
F_4 ( V_2 -> V_13 + V_24 ) ;
}
static int F_5 ( struct V_1 * V_2 ,
struct V_25 * V_26 ,
struct V_27 * V_28 ,
unsigned int * V_5 )
{
unsigned int V_3 = F_6 ( V_28 -> V_29 ) ;
unsigned int V_4 = F_7 ( V_28 -> V_29 ) ;
unsigned int V_30 = V_26 -> V_31 [ V_3 ] ;
int V_32 ;
for ( V_32 = 0 ; V_32 < V_28 -> V_33 ; V_32 ++ ) {
V_30 = V_5 [ V_32 ] ;
F_1 ( V_2 , V_3 , V_4 , V_30 ) ;
}
V_26 -> V_31 [ V_3 ] = V_30 ;
return V_28 -> V_33 ;
}
static void F_8 ( struct V_1 * V_2 ,
struct V_25 * V_26 )
{
struct V_9 * V_10 = V_2 -> V_11 ;
unsigned long V_34 ;
if ( ! F_9 ( V_35 , & V_10 -> V_36 ) )
return;
F_10 ( & V_10 -> V_37 , V_34 ) ;
V_10 -> V_38 = 0 ;
F_11 ( 0 , V_10 -> V_39 + V_40 ) ;
while ( V_10 -> V_41 && V_10 -> V_42 != V_43 ) {
F_12 ( & V_10 -> V_37 , V_34 ) ;
F_10 ( & V_10 -> V_37 , V_34 ) ;
}
F_12 ( & V_10 -> V_37 , V_34 ) ;
F_2 ( 0 , V_2 -> V_13 + V_14 ) ;
V_10 -> V_15 =
F_3 ( V_10 -> V_15 ,
V_44 | V_45 ,
V_46 | V_47 ) ;
F_2 ( V_10 -> V_15 | V_19 ,
V_2 -> V_13 + V_20 ) ;
}
static void F_13 ( struct V_1 * V_2 ,
struct V_25 * V_26 )
{
struct V_9 * V_10 = V_2 -> V_11 ;
struct V_48 * V_49 = & V_26 -> V_50 -> V_49 ;
unsigned long V_34 ;
F_14 ( V_35 , & V_10 -> V_36 ) ;
F_10 ( & V_10 -> V_37 , V_34 ) ;
if ( V_49 -> V_51 == V_52 )
V_10 -> V_38 = V_53 | V_54 ;
else
V_10 -> V_38 = V_54 ;
F_11 ( V_10 -> V_38 , V_10 -> V_39 + V_40 ) ;
F_12 ( & V_10 -> V_37 , V_34 ) ;
}
static void F_15 ( struct V_1 * V_2 ,
struct V_25 * V_26 )
{
struct V_9 * V_10 = V_2 -> V_11 ;
struct V_48 * V_49 = & V_26 -> V_50 -> V_49 ;
unsigned int V_55 = F_16 ( V_26 , 0 ) ;
unsigned int V_56 ;
unsigned short V_57 ;
unsigned int V_32 , V_33 ;
V_57 = F_4 ( V_2 -> V_13 + V_20 ) ;
switch ( V_57 & V_58 ) {
case V_59 :
V_56 = V_60 ;
if ( V_49 -> V_51 == V_61 &&
V_26 -> V_50 -> V_62 >= V_49 -> V_63 ) {
V_26 -> V_50 -> V_64 |= V_65 ;
F_17 ( V_2 , V_26 ) ;
return;
}
break;
case V_66 :
V_56 = V_67 ;
break;
case V_68 :
V_56 = V_69 ;
break;
default:
V_56 = V_70 ;
break;
}
if ( V_56 >= V_67 ) {
if ( V_55 == 0 ) {
F_18 ( V_2 -> V_71 , L_1 ) ;
V_26 -> V_50 -> V_64 |= V_72 ;
}
}
V_56 /= V_49 -> V_73 ;
if ( V_55 > V_56 )
V_55 = V_56 ;
for ( V_33 = 0 ; V_33 < V_55 ; V_33 ++ ) {
F_19 ( V_26 , & V_10 -> V_74 [ 0 ] ,
V_49 -> V_73 ) ;
for ( V_32 = 0 ; V_32 < V_49 -> V_73 ; V_32 ++ ) {
F_2 ( V_10 -> V_74 [ V_10 -> V_75 [ V_32 ] ] ,
V_2 -> V_13 + V_23 ) ;
}
}
if ( V_49 -> V_51 == V_61 &&
V_26 -> V_50 -> V_62 >= V_49 -> V_63 ) {
V_10 -> V_15 = F_3 ( V_10 -> V_15 ,
V_45 ,
V_47 ) ;
F_2 ( V_10 -> V_15 , V_2 -> V_13 + V_20 ) ;
}
if ( ( V_10 -> V_15 & V_46 ) ==
V_76 ) {
unsigned short V_77 ;
if ( V_49 -> V_78 == V_79 ) {
V_77 = V_80 ;
} else {
if ( V_49 -> V_81 & V_82 )
V_77 = V_83 ;
else
V_77 = V_84 ;
}
V_10 -> V_15 =
F_3 ( V_10 -> V_15 , V_77 , V_46 ) ;
F_2 ( V_10 -> V_15 , V_2 -> V_13 + V_20 ) ;
}
F_17 ( V_2 , V_26 ) ;
}
static int F_20 ( struct V_1 * V_2 ,
struct V_25 * V_26 ,
unsigned int V_85 )
{
struct V_48 * V_49 = & V_26 -> V_50 -> V_49 ;
if ( V_85 != V_49 -> V_86 )
return - V_87 ;
V_26 -> V_50 -> V_88 = NULL ;
F_13 ( V_2 , V_26 ) ;
return 1 ;
}
static int F_21 ( struct V_1 * V_2 ,
struct V_25 * V_26 ,
struct V_48 * V_49 )
{
const struct V_6 * V_7 = V_2 -> V_8 ;
unsigned int V_89 ;
unsigned int V_90 = 0 ;
int V_32 ;
V_89 = V_7 -> V_91 [ F_7 ( V_49 -> V_92 [ 0 ] ) ] ;
for ( V_32 = 0 ; V_32 < V_49 -> V_73 ; V_32 ++ ) {
unsigned int V_3 = F_6 ( V_49 -> V_92 [ V_32 ] ) ;
if ( V_90 & ( 1 << V_3 ) ) {
F_22 ( V_2 -> V_71 ,
L_2 ,
V_93 ) ;
return - V_87 ;
}
V_90 |= 1 << V_3 ;
if ( V_7 -> V_91 [ F_7 ( V_49 -> V_92 [ V_32 ] ) ] !=
V_89 ) {
F_22 ( V_2 -> V_71 ,
L_3 ,
V_93 ) ;
return - V_87 ;
}
}
return 0 ;
}
static int
F_23 ( struct V_1 * V_2 , struct V_25 * V_26 ,
struct V_48 * V_49 )
{
int V_94 = 0 ;
unsigned int V_95 ;
V_94 |= F_24 ( & V_49 -> V_96 , V_97 | V_52 ) ;
V_94 |= F_24 ( & V_49 -> V_78 ,
V_52 | V_79 ) ;
V_94 |= F_24 ( & V_49 -> V_98 , V_99 ) ;
V_94 |= F_24 ( & V_49 -> V_100 , V_61 ) ;
V_94 |= F_24 ( & V_49 -> V_51 ,
V_61 | V_52 | V_101 ) ;
if ( V_94 )
return 1 ;
V_94 |= F_25 ( V_49 -> V_96 ) ;
V_94 |= F_25 ( V_49 -> V_78 ) ;
V_94 |= F_25 ( V_49 -> V_51 ) ;
V_95 = 0 ;
if ( V_49 -> V_96 & V_52 )
V_95 ++ ;
if ( V_49 -> V_78 & V_52 )
V_95 ++ ;
if ( V_49 -> V_51 & V_52 )
V_95 ++ ;
if ( V_95 > 1 )
V_94 |= - V_87 ;
if ( V_94 )
return 2 ;
switch ( V_49 -> V_96 ) {
case V_97 :
V_94 |= F_26 ( & V_49 -> V_86 , 0 ) ;
break;
case V_52 :
if ( V_49 -> V_86 & ~ V_102 ) {
V_49 -> V_86 =
F_3 ( V_49 -> V_86 , 0 , ~ V_102 ) ;
V_94 |= - V_87 ;
}
if ( V_49 -> V_86 & V_102 & ~ V_103 ) {
V_49 -> V_86 = F_3 ( V_49 -> V_86 , 0 ,
V_102 & ~ V_103 ) ;
V_94 |= - V_87 ;
}
break;
}
switch ( V_49 -> V_78 ) {
case V_79 :
V_94 |= F_27 ( & V_49 -> V_81 ,
V_104 ) ;
V_95 = V_49 -> V_73 * V_105 ;
if ( V_95 < V_106 )
V_95 = V_106 ;
V_94 |= F_28 ( & V_49 -> V_81 , V_95 ) ;
break;
case V_52 :
if ( V_49 -> V_81 & ~ V_102 ) {
V_49 -> V_81 =
F_3 ( V_49 -> V_81 , 0 , ~ V_102 ) ;
V_94 |= - V_87 ;
}
if ( V_49 -> V_81 & V_102 &
~ ( V_103 | V_82 ) ) {
V_49 -> V_81 =
F_3 ( V_49 -> V_81 , 0 ,
V_102 & ~ ( V_103 | V_82 ) ) ;
V_94 |= - V_87 ;
}
break;
}
V_94 |= F_26 ( & V_49 -> V_107 , 0 ) ;
V_94 |= F_26 ( & V_49 -> V_108 ,
V_49 -> V_73 ) ;
switch ( V_49 -> V_51 ) {
case V_61 :
V_94 |= F_28 ( & V_49 -> V_63 , 1 ) ;
break;
case V_52 :
if ( V_49 -> V_63 & ~ V_102 ) {
V_49 -> V_63 =
F_3 ( V_49 -> V_63 , 0 , ~ V_102 ) ;
V_94 |= - V_87 ;
}
if ( V_49 -> V_63 & V_102 & ~ V_103 ) {
V_49 -> V_63 =
F_3 ( V_49 -> V_63 , 0 , V_102 & ~ V_103 ) ;
}
break;
case V_101 :
V_94 |= F_26 ( & V_49 -> V_63 , 0 ) ;
break;
}
if ( V_94 )
return 3 ;
if ( V_49 -> V_78 == V_79 ) {
V_95 = V_49 -> V_81 ;
F_29 ( V_2 -> V_109 , & V_95 , V_49 -> V_34 ) ;
V_94 |= F_26 ( & V_49 -> V_81 , V_95 ) ;
}
if ( V_94 )
return 4 ;
if ( V_49 -> V_92 && V_49 -> V_73 > 0 )
V_94 |= F_21 ( V_2 , V_26 , V_49 ) ;
if ( V_94 )
return 5 ;
return 0 ;
}
static void F_30 ( struct V_1 * V_2 ,
struct V_25 * V_26 )
{
struct V_9 * V_10 = V_2 -> V_11 ;
F_11 ( F_31 ( 0 , V_110 ) , V_10 -> V_39 + V_111 ) ;
F_11 ( F_31 ( 2 , V_110 ) , V_10 -> V_39 + V_111 ) ;
F_11 ( F_32 ( 2 , V_112 ) , V_10 -> V_39 + V_113 ) ;
F_11 ( F_32 ( 0 , V_114 ) , V_10 -> V_39 + V_113 ) ;
F_33 ( V_2 -> V_109 , 2 , 0 , false ) ;
}
static int F_34 ( struct V_1 * V_2 , struct V_25 * V_26 )
{
const struct V_6 * V_7 = V_2 -> V_8 ;
struct V_9 * V_10 = V_2 -> V_11 ;
struct V_48 * V_49 = & V_26 -> V_50 -> V_49 ;
int V_4 ;
unsigned int V_32 , V_115 ;
unsigned int V_116 ;
unsigned int V_117 ;
unsigned long V_34 ;
if ( ! V_49 -> V_92 || V_49 -> V_73 == 0 )
return - V_87 ;
V_10 -> V_118 = 0 ;
for ( V_32 = 0 ; V_32 < V_49 -> V_73 ; V_32 ++ ) {
V_116 = F_6 ( V_49 -> V_92 [ V_32 ] ) ;
V_10 -> V_118 |= 1U << V_116 ;
V_117 = 0 ;
for ( V_115 = 0 ; V_115 < V_49 -> V_73 ; V_115 ++ ) {
if ( F_6 ( V_49 -> V_92 [ V_115 ] ) < V_116 )
V_117 ++ ;
}
V_10 -> V_75 [ V_117 ] = V_32 ;
}
F_2 ( V_10 -> V_118 , V_2 -> V_13 + V_14 ) ;
V_4 = F_7 ( V_49 -> V_92 [ 0 ] ) ;
V_10 -> V_15 =
F_3 ( V_10 -> V_15 ,
V_7 -> V_16 [ V_4 ] | V_76 |
V_119 ,
V_17 | V_18 |
V_46 | V_47 ) ;
F_2 ( V_10 -> V_15 | V_19 ,
V_2 -> V_13 + V_20 ) ;
if ( V_49 -> V_78 == V_79 ) {
F_35 ( V_2 -> V_109 ) ;
F_30 ( V_2 , V_26 ) ;
}
F_10 ( & V_10 -> V_37 , V_34 ) ;
if ( V_49 -> V_96 == V_97 ) {
V_26 -> V_50 -> V_88 = F_20 ;
} else {
V_10 -> V_38 |= V_53 ;
F_11 ( V_10 -> V_38 , V_10 -> V_39 + V_40 ) ;
}
F_12 ( & V_10 -> V_37 , V_34 ) ;
return 0 ;
}
static int F_36 ( struct V_1 * V_2 ,
struct V_25 * V_26 )
{
F_8 ( V_2 , V_26 ) ;
return 0 ;
}
static void
F_37 ( struct V_1 * V_2 , struct V_25 * V_26 ,
void * V_5 , unsigned int V_120 , unsigned int V_121 )
{
const struct V_6 * V_7 = V_2 -> V_8 ;
struct V_48 * V_49 = & V_26 -> V_50 -> V_49 ;
unsigned short * V_122 = V_5 ;
unsigned int V_123 = V_120 / sizeof( * V_122 ) ;
unsigned int V_124 ;
unsigned int V_125 ;
unsigned int V_32 ;
V_125 = 16 - V_7 -> V_21 ;
if ( ( V_7 -> V_16 [ F_7 ( V_49 -> V_92 [ 0 ] ) ] &
V_17 ) == V_126 ) {
V_124 = 0 ;
} else {
V_124 = 32768 ;
}
for ( V_32 = 0 ; V_32 < V_123 ; V_32 ++ )
V_122 [ V_32 ] = ( V_122 [ V_32 ] << V_125 ) - V_124 ;
}
static T_1 F_38 ( int V_127 , void * V_128 )
{
struct V_1 * V_2 = V_128 ;
struct V_9 * V_10 = V_2 -> V_11 ;
struct V_25 * V_26 = V_2 -> V_129 ;
struct V_48 * V_49 ;
unsigned char V_130 , V_131 ;
unsigned char V_132 ;
int V_133 = 0 ;
unsigned long V_34 ;
V_130 = F_39 ( V_10 -> V_39 + V_40 ) & 0x3F ;
if ( V_130 ) {
V_133 = 1 ;
F_10 ( & V_10 -> V_37 , V_34 ) ;
V_131 = V_10 -> V_38 & V_130 ;
V_132 = V_10 -> V_38 & ~ V_130 ;
F_11 ( V_132 , V_10 -> V_39 + V_40 ) ;
V_10 -> V_41 = 1 ;
V_10 -> V_42 = V_43 ;
F_12 ( & V_10 -> V_37 , V_34 ) ;
if ( V_131 ) {
V_49 = & V_26 -> V_50 -> V_49 ;
if ( V_131 & V_53 ) {
V_10 -> V_38 &= ~ V_53 ;
if ( V_49 -> V_96 == V_52 )
F_13 ( V_2 , V_26 ) ;
else if ( V_49 -> V_51 == V_52 )
F_8 ( V_2 , V_26 ) ;
}
if ( V_131 & V_54 )
F_15 ( V_2 , V_26 ) ;
}
F_10 ( & V_10 -> V_37 , V_34 ) ;
if ( V_132 != V_10 -> V_38 ) {
F_11 ( V_10 -> V_38 ,
V_10 -> V_39 + V_40 ) ;
}
V_10 -> V_41 = 0 ;
F_12 ( & V_10 -> V_37 , V_34 ) ;
}
return F_40 ( V_133 ) ;
}
static int
F_41 ( struct V_1 * V_2 , unsigned long V_134 )
{
struct V_135 * V_135 = F_42 ( V_2 ) ;
const struct V_6 * V_7 = NULL ;
struct V_9 * V_10 ;
struct V_25 * V_26 ;
unsigned int V_127 ;
int V_136 ;
if ( V_134 < F_43 ( V_137 ) )
V_7 = & V_137 [ V_134 ] ;
if ( ! V_7 || ! V_7 -> V_138 ) {
F_18 ( V_2 -> V_71 ,
L_4 ) ;
return - V_87 ;
}
V_2 -> V_8 = V_7 ;
V_2 -> V_139 = V_7 -> V_138 ;
F_44 ( V_2 -> V_71 , L_5 ,
F_45 ( V_135 ) , V_2 -> V_139 ) ;
V_10 = F_46 ( V_2 , sizeof( * V_10 ) ) ;
if ( ! V_10 )
return - V_140 ;
V_136 = F_47 ( V_2 ) ;
if ( V_136 )
return V_136 ;
F_48 ( & V_10 -> V_37 ) ;
V_10 -> V_39 = F_49 ( V_135 , 2 ) ;
V_2 -> V_13 = F_49 ( V_135 , 3 ) ;
V_127 = V_135 -> V_127 ;
V_10 -> V_74 = F_50 ( V_7 -> V_141 ,
sizeof( V_10 -> V_74 [ 0 ] ) ,
V_142 ) ;
if ( ! V_10 -> V_74 )
return - V_140 ;
V_10 -> V_75 =
F_50 ( V_7 -> V_141 ,
sizeof( V_10 -> V_75 [ 0 ] ) ,
V_142 ) ;
if ( ! V_10 -> V_75 )
return - V_140 ;
V_10 -> V_38 = 0 ;
F_11 ( 0 , V_10 -> V_39 + V_40 ) ;
F_2 ( V_143 , V_2 -> V_13 + V_20 ) ;
F_2 ( 0 , V_2 -> V_13 + V_14 ) ;
F_2 ( 0 , V_2 -> V_13 + V_144 ) ;
V_10 -> V_15 = V_44 | V_22 |
V_145 | V_45 ;
F_2 ( V_10 -> V_15 | V_19 ,
V_2 -> V_13 + V_20 ) ;
V_2 -> V_109 = F_51 ( V_10 -> V_39 + V_146 ,
V_147 , V_148 , 0 ) ;
if ( ! V_2 -> V_109 )
return - V_140 ;
V_136 = F_52 ( V_2 , 1 ) ;
if ( V_136 )
return V_136 ;
V_26 = & V_2 -> V_149 [ 0 ] ;
V_26 -> type = V_150 ;
V_26 -> V_151 = V_152 | V_153 | V_154 ;
V_26 -> V_155 = V_7 -> V_141 ;
V_26 -> V_156 = ( 1 << V_7 -> V_21 ) - 1 ;
V_26 -> V_157 = V_7 -> V_158 ;
V_26 -> V_159 = F_5 ;
V_26 -> V_160 = V_26 -> V_155 ;
V_2 -> V_129 = V_26 ;
V_26 -> V_161 = F_34 ;
V_26 -> V_162 = F_23 ;
V_26 -> V_163 = F_36 ;
V_26 -> V_164 = F_37 ;
V_136 = F_53 ( V_26 ) ;
if ( V_136 )
return V_136 ;
if ( V_127 ) {
V_136 = F_54 ( V_127 , F_38 , V_165 ,
V_2 -> V_139 , V_2 ) ;
if ( V_136 < 0 ) {
F_18 ( V_2 -> V_71 ,
L_6 , V_127 ) ;
return V_136 ;
}
V_2 -> V_127 = V_127 ;
}
return 0 ;
}
static void F_55 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = V_2 -> V_11 ;
F_56 ( V_2 ) ;
if ( V_10 ) {
F_57 ( V_10 -> V_74 ) ;
F_57 ( V_10 -> V_75 ) ;
}
}
static int F_58 ( struct V_135 * V_2 ,
const struct V_166 * V_167 )
{
return F_59 ( V_2 , & V_168 ,
V_167 -> V_169 ) ;
}
