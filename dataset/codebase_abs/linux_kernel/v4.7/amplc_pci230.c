static inline unsigned int F_1 ( unsigned int V_1 ,
unsigned int V_2 )
{
return ( ( V_1 & 3 ) << 3 ) | ( V_2 & 7 ) ;
}
static unsigned short F_2 ( struct V_3 * V_4 )
{
const struct V_5 * V_6 = V_4 -> V_7 ;
struct V_8 * V_9 = V_4 -> V_10 ;
unsigned short V_11 ;
V_11 = F_3 ( V_9 -> V_12 + V_13 ) ;
if ( V_9 -> V_14 )
V_11 ^= 0x8000 ;
V_11 >>= ( 16 - V_6 -> V_15 ) ;
return V_11 ;
}
static unsigned short F_4 ( struct V_3 * V_4 ,
unsigned short V_16 )
{
const struct V_5 * V_6 = V_4 -> V_7 ;
struct V_8 * V_9 = V_4 -> V_10 ;
V_16 <<= ( 16 - V_6 -> V_17 ) ;
if ( V_9 -> V_18 )
V_16 ^= 0x8000 ;
return V_16 ;
}
static void F_5 ( struct V_3 * V_4 ,
unsigned short V_16 , unsigned int V_1 )
{
struct V_8 * V_9 = V_4 -> V_10 ;
F_6 ( F_4 ( V_4 , V_16 ) ,
V_9 -> V_12 + ( ( V_1 == 0 ) ? V_19 : V_20 ) ) ;
}
static void F_7 ( struct V_3 * V_4 ,
unsigned short V_16 , unsigned int V_1 )
{
struct V_8 * V_9 = V_4 -> V_10 ;
F_6 ( F_4 ( V_4 , V_16 ) ,
V_9 -> V_12 + V_21 ) ;
}
static bool F_8 ( struct V_3 * V_4 ,
unsigned char V_22 , unsigned int V_23 )
{
struct V_8 * V_9 = V_4 -> V_10 ;
unsigned int V_24 ;
unsigned long V_25 ;
F_9 ( & V_9 -> V_26 , V_25 ) ;
for ( V_24 = 0 ; V_24 < V_27 ; V_24 ++ ) {
if ( V_24 == V_23 )
continue;
if ( V_9 -> V_28 [ V_24 ] & V_22 ) {
F_10 ( & V_9 -> V_26 ,
V_25 ) ;
return false ;
}
}
V_9 -> V_28 [ V_23 ] |= V_22 ;
F_10 ( & V_9 -> V_26 , V_25 ) ;
return true ;
}
static void F_11 ( struct V_3 * V_4 ,
unsigned char V_22 , unsigned int V_23 )
{
struct V_8 * V_9 = V_4 -> V_10 ;
unsigned long V_25 ;
F_9 ( & V_9 -> V_26 , V_25 ) ;
V_9 -> V_28 [ V_23 ] &= ~ V_22 ;
F_10 ( & V_9 -> V_26 , V_25 ) ;
}
static void F_12 ( struct V_3 * V_4 ,
unsigned int V_23 )
{
F_11 ( V_4 , ( unsigned char ) ~ 0 , V_23 ) ;
}
static unsigned int F_13 ( T_1 V_29 , unsigned int V_30 ,
unsigned int V_31 )
{
T_1 div ;
unsigned int V_32 ;
div = V_29 ;
V_32 = F_14 ( div , V_30 ) ;
switch ( V_31 & V_33 ) {
default:
case V_34 :
div += F_15 ( V_32 , V_30 ) ;
break;
case V_35 :
break;
case V_36 :
div += F_16 ( V_32 , V_30 ) ;
break;
}
return div > V_37 ? V_37 : ( unsigned int ) div ;
}
static unsigned int F_17 ( T_1 V_29 , unsigned int * V_38 ,
unsigned int V_31 )
{
unsigned int V_39 , V_40 ;
for ( V_39 = V_41 ; ; V_39 ++ ) {
V_40 = F_13 ( V_29 , V_42 [ V_39 ] , V_31 ) ;
if ( V_40 <= 65536 || V_39 == V_43 )
break;
}
* V_38 = V_40 ;
return V_39 ;
}
static void F_18 ( unsigned int * V_29 , unsigned int V_31 )
{
unsigned int V_38 ;
unsigned int V_39 ;
V_39 = F_17 ( * V_29 , & V_38 , V_31 ) ;
* V_29 = V_38 * V_42 [ V_39 ] ;
}
static void F_19 ( struct V_3 * V_4 , unsigned int V_44 ,
unsigned int V_45 , T_1 V_29 ,
unsigned int V_31 )
{
unsigned int V_39 ;
unsigned int V_38 ;
F_20 ( V_4 -> V_46 , V_44 , V_45 ) ;
V_39 = F_17 ( V_29 , & V_38 , V_31 ) ;
F_21 ( F_22 ( V_44 , V_39 ) , V_4 -> V_47 + V_48 ) ;
if ( V_38 >= 65536 )
V_38 = 0 ;
F_23 ( V_4 -> V_46 , V_44 , V_38 ) ;
}
static void F_24 ( struct V_3 * V_4 , unsigned int V_44 )
{
F_20 ( V_4 -> V_46 , V_44 , V_49 ) ;
}
static int F_25 ( struct V_3 * V_4 ,
struct V_50 * V_51 ,
struct V_52 * V_53 ,
unsigned long V_54 )
{
struct V_8 * V_9 = V_4 -> V_10 ;
unsigned int V_55 ;
V_55 = F_3 ( V_9 -> V_12 + V_56 ) ;
if ( ( V_55 & V_57 ) == 0 )
return 0 ;
return - V_58 ;
}
static int F_26 ( struct V_3 * V_4 ,
struct V_50 * V_51 ,
struct V_52 * V_53 , unsigned int * V_11 )
{
struct V_8 * V_9 = V_4 -> V_10 ;
unsigned int V_59 ;
unsigned int V_1 , V_60 , V_61 ;
unsigned int V_62 ;
unsigned short V_63 , V_64 ;
int V_65 ;
V_1 = F_27 ( V_53 -> V_66 ) ;
V_60 = F_28 ( V_53 -> V_66 ) ;
V_61 = F_29 ( V_53 -> V_66 ) ;
if ( V_61 == V_67 ) {
if ( V_1 >= V_51 -> V_68 / 2 ) {
F_30 ( V_4 -> V_69 ,
L_1 ,
V_70 , ( V_51 -> V_68 / 2 ) - 1 ) ;
return - V_71 ;
}
}
V_63 = V_72 | V_73 ;
F_20 ( V_4 -> V_46 , 2 , V_74 ) ;
V_9 -> V_14 = F_31 ( V_51 , V_60 ) ;
if ( V_61 == V_67 ) {
V_62 = V_1 * 2 ;
if ( V_9 -> V_75 == 0 ) {
V_64 = 3 << V_62 ;
} else {
V_64 = 1 << V_62 ;
}
V_63 |= V_76 ;
} else {
V_64 = 1 << V_1 ;
V_62 = V_1 & ~ 1 ;
V_63 |= V_77 ;
}
V_9 -> V_78 = ( V_9 -> V_78 & ~ ( 3 << V_62 ) ) |
( V_79 [ V_60 ] << V_62 ) ;
if ( V_9 -> V_14 )
V_63 |= V_80 ;
else
V_63 |= V_81 ;
F_6 ( V_64 , V_9 -> V_12 + V_82 ) ;
F_6 ( V_9 -> V_78 , V_9 -> V_12 + V_83 ) ;
V_9 -> V_63 = V_63 ;
F_6 ( V_63 | V_84 , V_9 -> V_12 + V_56 ) ;
for ( V_59 = 0 ; V_59 < V_53 -> V_59 ; V_59 ++ ) {
F_20 ( V_4 -> V_46 , 2 , V_74 ) ;
F_20 ( V_4 -> V_46 , 2 , V_49 ) ;
V_65 = F_32 ( V_4 , V_51 , V_53 , F_25 , 0 ) ;
if ( V_65 )
return V_65 ;
V_11 [ V_59 ] = F_2 ( V_4 ) ;
}
return V_59 ;
}
static int F_33 ( struct V_3 * V_4 ,
struct V_50 * V_51 ,
struct V_52 * V_53 ,
unsigned int * V_11 )
{
struct V_8 * V_9 = V_4 -> V_10 ;
unsigned int V_1 = F_27 ( V_53 -> V_66 ) ;
unsigned int V_60 = F_28 ( V_53 -> V_66 ) ;
unsigned int V_85 = V_51 -> V_86 [ V_1 ] ;
int V_87 ;
V_9 -> V_18 = F_31 ( V_51 , V_60 ) ;
F_6 ( V_60 , V_9 -> V_12 + V_88 ) ;
for ( V_87 = 0 ; V_87 < V_53 -> V_59 ; V_87 ++ ) {
V_85 = V_11 [ V_87 ] ;
F_5 ( V_4 , V_85 , V_1 ) ;
}
V_51 -> V_86 [ V_1 ] = V_85 ;
return V_53 -> V_59 ;
}
static int F_34 ( struct V_3 * V_4 ,
struct V_50 * V_51 ,
struct V_89 * V_90 )
{
unsigned int V_91 = F_27 ( V_90 -> V_92 [ 0 ] ) ;
unsigned int V_93 = F_28 ( V_90 -> V_92 [ 0 ] ) ;
int V_87 ;
for ( V_87 = 1 ; V_87 < V_90 -> V_94 ; V_87 ++ ) {
unsigned int V_1 = F_27 ( V_90 -> V_92 [ V_87 ] ) ;
unsigned int V_60 = F_28 ( V_90 -> V_92 [ V_87 ] ) ;
if ( V_1 < V_91 ) {
F_30 ( V_4 -> V_69 ,
L_2 ,
V_70 ) ;
return - V_71 ;
}
if ( V_60 != V_93 ) {
F_30 ( V_4 -> V_69 ,
L_3 ,
V_70 ) ;
return - V_71 ;
}
V_91 = V_1 ;
}
return 0 ;
}
static int F_35 ( struct V_3 * V_4 ,
struct V_50 * V_51 , struct V_89 * V_90 )
{
const struct V_5 * V_6 = V_4 -> V_7 ;
struct V_8 * V_9 = V_4 -> V_10 ;
int V_95 = 0 ;
unsigned int V_96 ;
V_95 |= F_36 ( & V_90 -> V_97 , V_98 ) ;
V_96 = V_99 | V_98 ;
if ( V_6 -> V_100 > 0 && V_9 -> V_75 >= 2 ) {
V_96 |= V_101 ;
}
V_95 |= F_36 ( & V_90 -> V_102 , V_96 ) ;
V_95 |= F_36 ( & V_90 -> V_103 , V_104 ) ;
V_95 |= F_36 ( & V_90 -> V_105 , V_106 ) ;
V_95 |= F_36 ( & V_90 -> V_107 , V_106 | V_108 ) ;
if ( V_95 )
return 1 ;
V_95 |= F_37 ( V_90 -> V_102 ) ;
V_95 |= F_37 ( V_90 -> V_107 ) ;
if ( V_95 )
return 2 ;
V_95 |= F_38 ( & V_90 -> V_109 , 0 ) ;
#define F_39 8000
#define F_40 4294967295u
switch ( V_90 -> V_102 ) {
case V_99 :
V_95 |= F_41 ( & V_90 -> V_110 ,
F_39 ) ;
V_95 |= F_42 ( & V_90 -> V_110 ,
F_40 ) ;
break;
case V_101 :
if ( V_90 -> V_110 & ~ V_111 ) {
V_90 -> V_110 = F_43 ( V_90 -> V_110 , 0 ,
~ V_111 ) ;
V_95 |= - V_71 ;
}
if ( V_90 -> V_110 & V_111 &
~ ( V_112 | V_113 ) ) {
V_90 -> V_110 =
F_43 ( V_90 -> V_110 , 0 ,
V_111 & ~ ( V_112 | V_113 ) ) ;
V_95 |= - V_71 ;
}
break;
default:
V_95 |= F_38 ( & V_90 -> V_110 , 0 ) ;
break;
}
V_95 |= F_38 ( & V_90 -> V_114 ,
V_90 -> V_94 ) ;
if ( V_90 -> V_107 == V_106 )
V_95 |= F_41 ( & V_90 -> V_115 , 1 ) ;
else
V_95 |= F_38 ( & V_90 -> V_115 , 0 ) ;
if ( V_95 )
return 3 ;
if ( V_90 -> V_102 == V_99 ) {
V_96 = V_90 -> V_110 ;
F_18 ( & V_90 -> V_110 , V_90 -> V_31 ) ;
if ( V_96 != V_90 -> V_110 )
V_95 ++ ;
}
if ( V_95 )
return 4 ;
if ( V_90 -> V_92 && V_90 -> V_94 > 0 )
V_95 |= F_34 ( V_4 , V_51 , V_90 ) ;
if ( V_95 )
return 5 ;
return 0 ;
}
static void F_44 ( struct V_3 * V_4 ,
struct V_50 * V_51 )
{
struct V_8 * V_9 = V_4 -> V_10 ;
unsigned long V_25 ;
unsigned char V_116 ;
bool V_117 ;
struct V_89 * V_90 ;
F_9 ( & V_9 -> V_118 , V_25 ) ;
V_117 = V_9 -> V_119 ;
V_9 -> V_119 = false ;
F_10 ( & V_9 -> V_118 , V_25 ) ;
if ( ! V_117 )
return;
V_90 = & V_51 -> V_120 -> V_90 ;
if ( V_90 -> V_102 == V_99 ) {
F_24 ( V_4 , 1 ) ;
}
if ( V_9 -> V_75 < 2 ) {
V_116 = V_121 ;
} else {
V_116 = V_122 ;
}
F_9 ( & V_9 -> V_123 , V_25 ) ;
V_9 -> V_124 &= ~ V_116 ;
while ( V_9 -> V_125 && V_9 -> V_126 != V_127 ) {
F_10 ( & V_9 -> V_123 , V_25 ) ;
F_9 ( & V_9 -> V_123 , V_25 ) ;
}
F_21 ( V_9 -> V_124 , V_4 -> V_47 + V_128 ) ;
F_10 ( & V_9 -> V_123 , V_25 ) ;
if ( V_9 -> V_75 >= 2 ) {
V_9 -> V_129 &= V_130 ;
F_6 ( V_9 -> V_129 | V_131 |
V_132 ,
V_9 -> V_12 + V_88 ) ;
}
F_12 ( V_4 , V_133 ) ;
}
static void F_45 ( struct V_3 * V_4 ,
struct V_50 * V_51 )
{
struct V_134 * V_120 = V_51 -> V_120 ;
struct V_89 * V_90 = & V_120 -> V_90 ;
unsigned short V_11 ;
int V_87 ;
if ( V_90 -> V_107 == V_106 && V_120 -> V_135 >= V_90 -> V_115 )
return;
for ( V_87 = 0 ; V_87 < V_90 -> V_94 ; V_87 ++ ) {
unsigned int V_1 = F_27 ( V_90 -> V_92 [ V_87 ] ) ;
if ( ! F_46 ( V_51 , & V_11 , 1 ) ) {
V_120 -> V_136 |= V_137 ;
return;
}
F_5 ( V_4 , V_11 , V_1 ) ;
V_51 -> V_86 [ V_1 ] = V_11 ;
}
if ( V_90 -> V_107 == V_106 && V_120 -> V_135 >= V_90 -> V_115 )
V_120 -> V_136 |= V_138 ;
}
static bool F_47 ( struct V_3 * V_4 ,
struct V_50 * V_51 )
{
struct V_8 * V_9 = V_4 -> V_10 ;
struct V_134 * V_120 = V_51 -> V_120 ;
struct V_89 * V_90 = & V_120 -> V_90 ;
unsigned int V_139 = F_48 ( V_51 , 0 ) ;
unsigned int V_140 ;
unsigned short V_141 ;
unsigned int V_87 , V_59 ;
unsigned int V_136 = 0 ;
V_141 = F_3 ( V_9 -> V_12 + V_88 ) ;
if ( V_90 -> V_107 == V_106 && V_139 == 0 )
V_136 |= V_138 ;
if ( V_136 == 0 ) {
if ( V_141 & V_142 ) {
F_49 ( V_4 -> V_69 , L_4 ) ;
V_136 |= V_137 | V_143 ;
}
if ( V_139 == 0 &&
( V_141 & V_144 ) == 0 ) {
F_49 ( V_4 -> V_69 , L_5 ) ;
V_136 |= V_137 | V_143 ;
}
}
if ( V_136 == 0 ) {
if ( V_141 & V_145 )
V_140 = V_146 ;
else if ( V_141 & V_144 )
V_140 = V_147 ;
else if ( V_141 & V_148 )
V_140 = V_149 ;
else
V_140 = V_150 ;
V_140 /= V_90 -> V_94 ;
if ( V_139 > V_140 )
V_139 = V_140 ;
for ( V_59 = 0 ; V_59 < V_139 ; V_59 ++ ) {
for ( V_87 = 0 ; V_87 < V_90 -> V_94 ; V_87 ++ ) {
unsigned int V_1 = F_27 ( V_90 -> V_92 [ V_87 ] ) ;
unsigned short V_16 ;
F_46 ( V_51 , & V_16 , 1 ) ;
F_7 ( V_4 , V_16 , V_1 ) ;
V_51 -> V_86 [ V_1 ] = V_16 ;
}
}
if ( V_90 -> V_107 == V_106 &&
V_120 -> V_135 >= V_90 -> V_115 ) {
V_9 -> V_129 &= ~ V_151 ;
V_9 -> V_129 |= V_152 ;
F_6 ( V_9 -> V_129 , V_9 -> V_12 + V_88 ) ;
}
V_141 = F_3 ( V_9 -> V_12 + V_88 ) ;
if ( V_141 & V_142 ) {
F_49 ( V_4 -> V_69 , L_4 ) ;
V_136 |= V_137 | V_143 ;
}
}
V_120 -> V_136 |= V_136 ;
return ! ( V_120 -> V_136 & V_153 ) ;
}
static int F_50 ( struct V_3 * V_4 ,
struct V_50 * V_51 ,
unsigned int V_154 )
{
struct V_8 * V_9 = V_4 -> V_10 ;
unsigned long V_25 ;
if ( V_154 )
return - V_71 ;
F_9 ( & V_9 -> V_118 , V_25 ) ;
if ( ! V_9 -> V_119 ) {
F_10 ( & V_9 -> V_118 , V_25 ) ;
return 1 ;
}
if ( V_9 -> V_75 < 2 ) {
F_10 ( & V_9 -> V_118 , V_25 ) ;
F_45 ( V_4 , V_51 ) ;
F_51 ( V_4 , V_51 ) ;
} else {
F_3 ( V_9 -> V_12 + V_155 ) ;
F_10 ( & V_9 -> V_118 , V_25 ) ;
}
F_52 ( 8 ) ;
return 1 ;
}
static void F_53 ( struct V_3 * V_4 ,
struct V_50 * V_51 )
{
struct V_8 * V_9 = V_4 -> V_10 ;
struct V_134 * V_120 = V_51 -> V_120 ;
struct V_89 * V_90 = & V_120 -> V_90 ;
unsigned long V_25 ;
V_9 -> V_119 = true ;
if ( V_9 -> V_75 >= 2 ) {
unsigned short V_156 ;
bool V_157 ;
V_157 = F_47 ( V_4 , V_51 ) ;
F_51 ( V_4 , V_51 ) ;
if ( ! V_157 ) {
return;
}
switch ( V_90 -> V_102 ) {
case V_99 :
V_156 = V_158 ;
break;
case V_101 :
if ( ( V_90 -> V_110 & V_113 ) == 0 ) {
V_156 = V_159 ;
} else {
V_156 = V_160 ;
}
break;
case V_98 :
V_156 = V_161 ;
break;
default:
V_156 = V_162 ;
break;
}
V_9 -> V_129 =
( V_9 -> V_129 & ~ V_163 ) | V_156 ;
F_6 ( V_9 -> V_129 , V_9 -> V_12 + V_88 ) ;
}
switch ( V_90 -> V_102 ) {
case V_99 :
if ( V_9 -> V_75 < 2 ) {
F_9 ( & V_9 -> V_123 , V_25 ) ;
V_9 -> V_124 |= V_121 ;
F_21 ( V_9 -> V_124 , V_4 -> V_47 + V_128 ) ;
F_10 ( & V_9 -> V_123 ,
V_25 ) ;
}
F_21 ( F_1 ( 1 , V_164 ) ,
V_4 -> V_47 + V_165 ) ;
break;
case V_98 :
V_120 -> V_166 = F_50 ;
break;
}
if ( V_9 -> V_75 >= 2 ) {
F_9 ( & V_9 -> V_123 , V_25 ) ;
V_9 -> V_124 |= V_122 ;
F_21 ( V_9 -> V_124 , V_4 -> V_47 + V_128 ) ;
F_10 ( & V_9 -> V_123 , V_25 ) ;
}
}
static int F_54 ( struct V_3 * V_4 ,
struct V_50 * V_51 ,
unsigned int V_154 )
{
struct V_89 * V_90 = & V_51 -> V_120 -> V_90 ;
if ( V_154 != V_90 -> V_97 )
return - V_71 ;
V_51 -> V_120 -> V_166 = NULL ;
F_53 ( V_4 , V_51 ) ;
return 1 ;
}
static int F_55 ( struct V_3 * V_4 , struct V_50 * V_51 )
{
struct V_8 * V_9 = V_4 -> V_10 ;
unsigned short V_129 ;
unsigned int V_60 ;
struct V_89 * V_90 = & V_51 -> V_120 -> V_90 ;
if ( V_90 -> V_102 == V_99 ) {
if ( ! F_8 ( V_4 , V_167 , V_133 ) )
return - V_58 ;
}
V_60 = F_28 ( V_90 -> V_92 [ 0 ] ) ;
V_9 -> V_18 = F_31 ( V_51 , V_60 ) ;
V_129 = V_9 -> V_18 ? V_168 : V_169 ;
if ( V_9 -> V_75 >= 2 ) {
unsigned short V_170 ;
unsigned int V_87 ;
V_170 = 0 ;
for ( V_87 = 0 ; V_87 < V_90 -> V_94 ; V_87 ++ )
V_170 |= 1 << F_27 ( V_90 -> V_92 [ V_87 ] ) ;
F_6 ( V_170 , V_9 -> V_12 + V_171 ) ;
V_129 |= V_172 | V_131 |
V_132 |
V_162 | V_173 ;
}
F_6 ( V_129 , V_9 -> V_12 + V_88 ) ;
V_9 -> V_129 = V_129 & ~ ( V_131 |
V_132 ) ;
if ( V_90 -> V_102 == V_99 ) {
F_21 ( F_1 ( 1 , V_174 ) ,
V_4 -> V_47 + V_165 ) ;
F_19 ( V_4 , 1 , V_175 ,
V_90 -> V_110 ,
V_90 -> V_31 ) ;
}
V_51 -> V_120 -> V_166 = F_54 ;
return 0 ;
}
static int F_56 ( struct V_3 * V_4 ,
struct V_50 * V_51 )
{
F_44 ( V_4 , V_51 ) ;
return 0 ;
}
static int F_57 ( struct V_89 * V_90 )
{
unsigned int V_176 , V_94 ;
int V_95 = 0 ;
V_94 = V_90 -> V_94 ;
if ( V_90 -> V_94 == 0 )
V_94 = 1 ;
V_176 = V_94 * V_90 -> V_177 ;
if ( V_176 < V_94 ||
V_176 < V_90 -> V_177 ) {
V_176 = V_37 ;
V_95 ++ ;
}
if ( V_90 -> V_110 < V_176 ) {
V_90 -> V_110 = V_176 ;
V_95 ++ ;
}
return ! V_95 ;
}
static int F_58 ( struct V_3 * V_4 ,
struct V_50 * V_51 ,
struct V_89 * V_90 )
{
struct V_8 * V_9 = V_4 -> V_10 ;
unsigned int V_178 = ( V_51 -> V_68 / 2 ) - 1 ;
unsigned int V_91 = 0 ;
unsigned int V_179 = 0 ;
unsigned int V_180 = 0 ;
bool V_181 = false ;
unsigned int V_182 = 0 ;
int V_87 ;
for ( V_87 = 0 ; V_87 < V_90 -> V_94 ; V_87 ++ ) {
unsigned int V_66 = V_90 -> V_92 [ V_87 ] ;
unsigned int V_1 = F_27 ( V_66 ) ;
unsigned int V_60 = F_28 ( V_66 ) ;
unsigned int V_61 = F_29 ( V_66 ) ;
bool V_183 = F_31 ( V_51 , V_60 ) ;
if ( V_61 == V_67 && V_1 >= V_178 ) {
F_30 ( V_4 -> V_69 ,
L_1 ,
V_70 , V_178 ) ;
return - V_71 ;
}
if ( V_87 > 0 ) {
if ( V_1 <= V_91 && V_182 == 0 )
V_182 = V_87 ;
if ( V_182 > 0 &&
V_90 -> V_92 [ V_87 % V_182 ] != V_66 ) {
F_30 ( V_4 -> V_69 ,
L_6 ,
V_70 ) ;
return - V_71 ;
}
if ( V_61 != V_180 ) {
F_30 ( V_4 -> V_69 ,
L_7 ,
V_70 ) ;
return - V_71 ;
}
if ( V_183 != V_181 ) {
F_30 ( V_4 -> V_69 ,
L_8 ,
V_70 ) ;
return - V_71 ;
}
if ( V_61 != V_67 && V_60 != V_179 &&
( ( V_1 ^ V_91 ) & ~ 1 ) == 0 ) {
F_30 ( V_4 -> V_69 ,
L_9 ,
V_70 ) ;
return - V_71 ;
}
}
V_91 = V_1 ;
V_179 = V_60 ;
V_180 = V_61 ;
V_181 = V_183 ;
}
if ( V_182 == 0 )
V_182 = V_90 -> V_94 ;
if ( V_90 -> V_94 % V_182 ) {
F_30 ( V_4 -> V_69 ,
L_10 , V_70 ) ;
return - V_71 ;
}
if ( V_9 -> V_75 > 0 && V_9 -> V_75 < 4 ) {
if ( V_182 > 1 && F_27 ( V_90 -> V_92 [ 0 ] ) ) {
F_59 ( V_4 -> V_69 ,
L_11 ,
V_9 -> V_75 ) ;
return - V_71 ;
}
}
return 0 ;
}
static int F_60 ( struct V_3 * V_4 ,
struct V_50 * V_51 , struct V_89 * V_90 )
{
const struct V_5 * V_6 = V_4 -> V_7 ;
struct V_8 * V_9 = V_4 -> V_10 ;
int V_95 = 0 ;
unsigned int V_96 ;
V_95 |= F_36 ( & V_90 -> V_97 , V_104 | V_98 ) ;
V_96 = V_184 | V_99 | V_98 ;
if ( V_6 -> V_185 || V_6 -> V_100 > 0 ) {
V_96 |= V_101 ;
}
V_95 |= F_36 ( & V_90 -> V_102 , V_96 ) ;
V_95 |= F_36 ( & V_90 -> V_103 ,
V_99 | V_98 | V_101 ) ;
V_95 |= F_36 ( & V_90 -> V_105 , V_106 ) ;
V_95 |= F_36 ( & V_90 -> V_107 , V_106 | V_108 ) ;
if ( V_95 )
return 1 ;
V_95 |= F_37 ( V_90 -> V_97 ) ;
V_95 |= F_37 ( V_90 -> V_102 ) ;
V_95 |= F_37 ( V_90 -> V_103 ) ;
V_95 |= F_37 ( V_90 -> V_107 ) ;
if ( V_90 -> V_102 != V_184 &&
V_90 -> V_103 != V_99 )
V_95 |= - V_71 ;
if ( V_95 )
return 2 ;
V_95 |= F_38 ( & V_90 -> V_109 , 0 ) ;
#define F_61 3200
#define F_62 8000
#define F_63 4000
#define F_64 4294967295u
if ( V_90 -> V_103 == V_99 ) {
unsigned int V_186 ;
if ( V_9 -> V_75 == 0 ) {
if ( V_90 -> V_92 && V_90 -> V_94 > 0 ) {
if ( F_29 ( V_90 -> V_92 [ 0 ] ) == V_67 )
V_186 = F_62 ;
else
V_186 = F_61 ;
} else {
V_186 = F_61 ;
}
} else {
V_186 = F_63 ;
}
V_95 |= F_41 ( & V_90 -> V_177 ,
V_186 ) ;
V_95 |= F_42 ( & V_90 -> V_177 ,
F_64 ) ;
} else if ( V_90 -> V_103 == V_101 ) {
if ( V_90 -> V_177 & V_111 ) {
if ( V_90 -> V_177 & ~ V_111 ) {
V_90 -> V_177 = F_43 ( V_90 -> V_177 , 0 ,
~ V_111 ) ;
V_95 |= - V_71 ;
}
if ( ( V_90 -> V_177 & V_111 & ~ V_113 ) !=
V_112 ) {
V_90 -> V_177 =
F_43 ( V_90 -> V_109 , V_112 | 0 ,
V_111 & ~ V_113 ) ;
V_95 |= - V_71 ;
}
} else {
V_95 |= F_42 ( & V_90 -> V_177 ,
1 ) ;
}
} else {
V_95 |= F_38 ( & V_90 -> V_177 , 0 ) ;
}
V_95 |= F_38 ( & V_90 -> V_114 ,
V_90 -> V_94 ) ;
if ( V_90 -> V_107 == V_106 )
V_95 |= F_41 ( & V_90 -> V_115 , 1 ) ;
else
V_95 |= F_38 ( & V_90 -> V_115 , 0 ) ;
if ( V_90 -> V_102 == V_101 ) {
if ( V_90 -> V_110 & ~ V_111 ) {
V_90 -> V_110 = F_43 ( V_90 -> V_110 , 0 ,
~ V_111 ) ;
V_95 |= - V_71 ;
}
if ( V_90 -> V_110 & V_111 & ~ V_112 ) {
V_90 -> V_110 = F_43 ( V_90 -> V_110 , 0 ,
V_111 & ~ V_112 ) ;
V_95 |= - V_71 ;
}
} else if ( V_90 -> V_102 == V_99 ) {
if ( ! F_57 ( V_90 ) )
V_95 |= - V_71 ;
} else {
V_95 |= F_38 ( & V_90 -> V_110 , 0 ) ;
}
if ( V_95 )
return 3 ;
if ( V_90 -> V_103 == V_99 ) {
V_96 = V_90 -> V_177 ;
F_18 ( & V_90 -> V_177 , V_90 -> V_31 ) ;
if ( V_96 != V_90 -> V_177 )
V_95 ++ ;
}
if ( V_90 -> V_102 == V_99 ) {
V_96 = V_90 -> V_110 ;
F_18 ( & V_90 -> V_110 , V_90 -> V_31 ) ;
if ( ! F_57 ( V_90 ) ) {
F_18 ( & V_90 -> V_110 ,
V_36 ) ;
F_57 ( V_90 ) ;
}
if ( V_96 != V_90 -> V_110 )
V_95 ++ ;
}
if ( V_95 )
return 4 ;
if ( V_90 -> V_92 && V_90 -> V_94 > 0 )
V_95 |= F_58 ( V_4 , V_51 , V_90 ) ;
if ( V_95 )
return 5 ;
return 0 ;
}
static void F_65 ( struct V_3 * V_4 ,
struct V_50 * V_51 )
{
struct V_8 * V_9 = V_4 -> V_10 ;
struct V_89 * V_90 = & V_51 -> V_120 -> V_90 ;
unsigned int V_187 ;
unsigned short V_188 ;
unsigned short V_63 ;
if ( V_90 -> V_31 & V_189 )
V_187 = V_90 -> V_114 - V_51 -> V_120 -> V_190 ;
else
V_187 = F_66 ( V_51 , V_191 ) ;
if ( V_187 >= V_191 ) {
V_188 = V_192 ;
} else if ( V_187 > 1 && V_9 -> V_75 > 0 ) {
if ( V_9 -> V_193 != V_187 ) {
V_9 -> V_193 = V_187 ;
F_6 ( V_187 , V_9 -> V_12 + V_194 ) ;
}
V_188 = V_195 ;
} else {
V_188 = V_196 ;
}
V_63 = ( V_9 -> V_63 & ~ V_197 ) | V_188 ;
if ( V_63 != V_9 -> V_63 ) {
V_9 -> V_63 = V_63 ;
F_6 ( V_63 , V_9 -> V_12 + V_56 ) ;
}
}
static int F_67 ( struct V_3 * V_4 ,
struct V_50 * V_51 ,
unsigned int V_154 )
{
struct V_8 * V_9 = V_4 -> V_10 ;
unsigned long V_25 ;
unsigned int V_198 ;
if ( V_154 )
return - V_71 ;
F_9 ( & V_9 -> V_199 , V_25 ) ;
if ( ! V_9 -> V_200 ) {
F_10 ( & V_9 -> V_199 , V_25 ) ;
return 1 ;
}
F_20 ( V_4 -> V_46 , 2 , V_74 ) ;
F_20 ( V_4 -> V_46 , 2 , V_49 ) ;
if ( ( V_9 -> V_63 & V_201 ) == V_76 &&
V_9 -> V_75 == 0 ) {
V_198 = 8 ;
} else {
V_198 = 4 ;
}
F_10 ( & V_9 -> V_199 , V_25 ) ;
F_52 ( V_198 ) ;
return 1 ;
}
static int F_68 ( struct V_3 * V_4 ,
struct V_50 * V_51 ,
unsigned int V_154 )
{
struct V_8 * V_9 = V_4 -> V_10 ;
unsigned long V_25 ;
unsigned char V_202 ;
if ( V_154 )
return - V_71 ;
F_9 ( & V_9 -> V_199 , V_25 ) ;
if ( V_9 -> V_200 ) {
V_202 = F_1 ( 0 , V_174 ) ;
F_21 ( V_202 , V_4 -> V_47 + V_165 ) ;
V_202 = F_1 ( 0 , V_164 ) ;
F_21 ( V_202 , V_4 -> V_47 + V_165 ) ;
}
F_10 ( & V_9 -> V_199 , V_25 ) ;
return 1 ;
}
static void F_69 ( struct V_3 * V_4 ,
struct V_50 * V_51 )
{
struct V_8 * V_9 = V_4 -> V_10 ;
unsigned long V_25 ;
struct V_89 * V_90 ;
bool V_117 ;
F_9 ( & V_9 -> V_199 , V_25 ) ;
V_117 = V_9 -> V_200 ;
V_9 -> V_200 = false ;
F_10 ( & V_9 -> V_199 , V_25 ) ;
if ( ! V_117 )
return;
V_90 = & V_51 -> V_120 -> V_90 ;
if ( V_90 -> V_103 == V_99 ) {
F_24 ( V_4 , 2 ) ;
}
if ( V_90 -> V_102 != V_184 ) {
F_24 ( V_4 , 0 ) ;
}
F_9 ( & V_9 -> V_123 , V_25 ) ;
V_9 -> V_124 &= ~ V_203 ;
while ( V_9 -> V_125 && V_9 -> V_126 != V_127 ) {
F_10 ( & V_9 -> V_123 , V_25 ) ;
F_9 ( & V_9 -> V_123 , V_25 ) ;
}
F_21 ( V_9 -> V_124 , V_4 -> V_47 + V_128 ) ;
F_10 ( & V_9 -> V_123 , V_25 ) ;
V_9 -> V_63 =
( V_9 -> V_63 & ( V_204 | V_201 ) ) |
V_205 ;
F_6 ( V_9 -> V_63 | V_84 ,
V_9 -> V_12 + V_56 ) ;
F_12 ( V_4 , V_206 ) ;
}
static void F_70 ( struct V_3 * V_4 ,
struct V_50 * V_51 )
{
struct V_8 * V_9 = V_4 -> V_10 ;
unsigned long V_25 ;
unsigned short V_207 ;
struct V_134 * V_120 = V_51 -> V_120 ;
struct V_89 * V_90 = & V_120 -> V_90 ;
V_9 -> V_200 = true ;
F_9 ( & V_9 -> V_123 , V_25 ) ;
V_9 -> V_124 |= V_203 ;
F_21 ( V_9 -> V_124 , V_4 -> V_47 + V_128 ) ;
F_10 ( & V_9 -> V_123 , V_25 ) ;
switch ( V_90 -> V_103 ) {
default:
V_207 = V_205 ;
break;
case V_99 :
V_207 = V_72 ;
break;
case V_101 :
if ( V_90 -> V_177 & V_112 ) {
if ( ( V_90 -> V_177 & V_113 ) == 0 ) {
V_207 = V_208 ;
} else {
V_207 = V_209 ;
}
} else {
if ( V_90 -> V_177 ) {
V_207 = V_208 ;
} else {
V_207 = V_209 ;
}
}
break;
case V_98 :
V_207 = V_72 ;
break;
}
V_9 -> V_63 = ( V_9 -> V_63 & ~ V_210 ) | V_207 ;
F_6 ( V_9 -> V_63 , V_9 -> V_12 + V_56 ) ;
if ( V_90 -> V_103 == V_98 )
V_120 -> V_166 = F_67 ;
F_65 ( V_4 , V_51 ) ;
if ( V_90 -> V_103 == V_99 ) {
unsigned char V_202 ;
if ( V_90 -> V_102 != V_184 ) {
V_202 = F_1 ( 2 , V_211 ) ;
} else {
V_202 = F_1 ( 2 , V_164 ) ;
}
F_21 ( V_202 , V_4 -> V_47 + V_165 ) ;
if ( V_90 -> V_102 != V_184 ) {
switch ( V_90 -> V_102 ) {
default:
V_202 = F_1 ( 0 , V_164 ) ;
break;
case V_101 :
V_202 = F_1 ( 0 , V_212 ) ;
break;
case V_99 :
V_202 = F_1 ( 0 , V_211 ) ;
break;
case V_98 :
V_202 = F_1 ( 0 , V_164 ) ;
break;
}
F_21 ( V_202 , V_4 -> V_47 + V_165 ) ;
switch ( V_90 -> V_102 ) {
case V_99 :
V_202 = F_1 ( 1 , V_164 ) ;
F_21 ( V_202 , V_4 -> V_47 + V_165 ) ;
break;
case V_98 :
V_120 -> V_166 = F_68 ;
break;
}
}
} else if ( V_90 -> V_103 != V_98 ) {
F_11 ( V_4 , V_213 , V_206 ) ;
}
}
static int F_71 ( struct V_3 * V_4 ,
struct V_50 * V_51 ,
unsigned int V_154 )
{
struct V_89 * V_90 = & V_51 -> V_120 -> V_90 ;
if ( V_154 != V_90 -> V_109 )
return - V_71 ;
V_51 -> V_120 -> V_166 = NULL ;
F_70 ( V_4 , V_51 ) ;
return 1 ;
}
static void F_72 ( struct V_3 * V_4 ,
struct V_50 * V_51 )
{
struct V_8 * V_9 = V_4 -> V_10 ;
struct V_134 * V_120 = V_51 -> V_120 ;
struct V_89 * V_90 = & V_120 -> V_90 ;
unsigned int V_214 ;
unsigned int V_87 ;
unsigned int V_215 ;
unsigned int V_216 ;
unsigned short V_85 ;
V_215 = F_66 ( V_51 , V_191 ) ;
if ( V_215 == 0 )
return;
V_216 = 0 ;
for ( V_87 = 0 ; V_87 < V_215 ; V_87 ++ ) {
if ( V_216 == 0 ) {
V_214 = F_3 ( V_9 -> V_12 + V_56 ) ;
if ( V_214 & V_217 ) {
F_49 ( V_4 -> V_69 , L_12 ) ;
V_120 -> V_136 |= V_143 ;
break;
} else if ( V_214 & V_57 ) {
break;
} else if ( V_214 & V_218 ) {
V_216 = V_191 ;
} else if ( V_9 -> V_75 > 0 ) {
V_216 = F_3 ( V_9 -> V_12 +
V_219 ) ;
if ( V_216 == 0 )
break;
} else {
V_216 = 1 ;
}
}
V_85 = F_2 ( V_4 ) ;
if ( ! F_73 ( V_51 , & V_85 , 1 ) )
break;
V_216 -- ;
if ( V_90 -> V_107 == V_106 &&
V_120 -> V_135 >= V_90 -> V_115 ) {
V_120 -> V_136 |= V_138 ;
break;
}
}
if ( ! ( V_120 -> V_136 & V_153 ) )
F_65 ( V_4 , V_51 ) ;
}
static int F_74 ( struct V_3 * V_4 , struct V_50 * V_51 )
{
struct V_8 * V_9 = V_4 -> V_10 ;
unsigned int V_87 , V_1 , V_60 , V_220 ;
unsigned int V_22 ;
unsigned short V_63 , V_64 ;
unsigned char V_202 ;
struct V_134 * V_120 = V_51 -> V_120 ;
struct V_89 * V_90 = & V_120 -> V_90 ;
V_22 = 0 ;
V_22 |= V_213 ;
if ( V_90 -> V_102 != V_184 ) {
V_22 |= V_221 ;
if ( V_90 -> V_102 == V_99 ) {
V_22 |= V_167 ;
}
}
if ( ! F_8 ( V_4 , V_22 , V_206 ) )
return - V_58 ;
V_63 = V_73 ;
V_64 = 0 ;
if ( F_29 ( V_90 -> V_92 [ 0 ] ) == V_67 ) {
V_220 = 1 ;
V_63 |= V_76 ;
} else {
V_220 = 0 ;
V_63 |= V_77 ;
}
V_60 = F_28 ( V_90 -> V_92 [ 0 ] ) ;
V_9 -> V_14 = F_31 ( V_51 , V_60 ) ;
if ( V_9 -> V_14 )
V_63 |= V_80 ;
else
V_63 |= V_81 ;
for ( V_87 = 0 ; V_87 < V_90 -> V_94 ; V_87 ++ ) {
unsigned int V_62 ;
V_1 = F_27 ( V_90 -> V_92 [ V_87 ] ) ;
V_60 = F_28 ( V_90 -> V_92 [ V_87 ] ) ;
if ( V_220 ) {
V_62 = 2 * V_1 ;
if ( V_9 -> V_75 == 0 ) {
V_64 |= 3 << V_62 ;
} else {
V_64 |= 1 << V_62 ;
}
} else {
V_62 = V_1 & ~ 1 ;
V_64 |= 1 << V_1 ;
}
V_9 -> V_78 = ( V_9 -> V_78 & ~ ( 3 << V_62 ) ) |
( V_79 [ V_60 ] << V_62 ) ;
}
F_6 ( V_64 , V_9 -> V_12 + V_82 ) ;
F_6 ( V_9 -> V_78 , V_9 -> V_12 + V_83 ) ;
F_20 ( V_4 -> V_46 , 2 , V_49 ) ;
V_63 |= V_222 | V_72 ;
V_9 -> V_63 = V_63 ;
F_6 ( V_63 | V_84 , V_9 -> V_12 + V_56 ) ;
F_75 ( 25 , 100 ) ;
F_6 ( V_63 | V_84 , V_9 -> V_12 + V_56 ) ;
if ( V_90 -> V_103 == V_99 ) {
V_202 = F_1 ( 2 , V_174 ) ;
F_21 ( V_202 , V_4 -> V_47 + V_165 ) ;
F_19 ( V_4 , 2 , V_175 , V_90 -> V_177 ,
V_90 -> V_31 ) ;
if ( V_90 -> V_102 != V_184 ) {
V_202 = F_1 ( 0 , V_164 ) ;
F_21 ( V_202 , V_4 -> V_47 + V_165 ) ;
F_19 ( V_4 , 0 , V_49 ,
( ( T_1 ) V_90 -> V_177 *
V_90 -> V_114 ) ,
V_36 ) ;
if ( V_90 -> V_102 == V_99 ) {
V_202 = F_1 ( 1 , V_174 ) ;
F_21 ( V_202 , V_4 -> V_47 + V_165 ) ;
F_19 ( V_4 , 1 , V_175 ,
V_90 -> V_110 ,
V_90 -> V_31 ) ;
}
}
}
if ( V_90 -> V_97 == V_98 )
V_51 -> V_120 -> V_166 = F_71 ;
else
F_70 ( V_4 , V_51 ) ;
return 0 ;
}
static int F_76 ( struct V_3 * V_4 ,
struct V_50 * V_51 )
{
F_69 ( V_4 , V_51 ) ;
return 0 ;
}
static T_2 F_77 ( int V_223 , void * V_224 )
{
unsigned char V_225 , V_226 , V_227 ;
struct V_3 * V_4 = V_224 ;
struct V_8 * V_9 = V_4 -> V_10 ;
struct V_50 * V_228 = V_4 -> V_229 ;
struct V_50 * V_230 = V_4 -> V_231 ;
unsigned long V_25 ;
V_225 = F_78 ( V_4 -> V_47 + V_232 ) ;
if ( V_225 == V_233 )
return V_234 ;
F_9 ( & V_9 -> V_123 , V_25 ) ;
V_226 = V_9 -> V_124 & V_225 ;
V_227 = V_9 -> V_124 & ~ V_225 ;
F_21 ( V_227 , V_4 -> V_47 + V_128 ) ;
V_9 -> V_125 = true ;
V_9 -> V_126 = V_127 ;
F_10 ( & V_9 -> V_123 , V_25 ) ;
if ( V_226 & V_121 )
F_45 ( V_4 , V_228 ) ;
if ( V_226 & V_122 )
F_47 ( V_4 , V_228 ) ;
if ( V_226 & V_203 )
F_72 ( V_4 , V_230 ) ;
F_9 ( & V_9 -> V_123 , V_25 ) ;
if ( V_9 -> V_124 != V_227 )
F_21 ( V_9 -> V_124 , V_4 -> V_47 + V_128 ) ;
V_9 -> V_125 = false ;
F_10 ( & V_9 -> V_123 , V_25 ) ;
F_51 ( V_4 , V_228 ) ;
F_51 ( V_4 , V_230 ) ;
return V_235 ;
}
static bool F_79 ( const struct V_5 * V_6 ,
struct V_236 * V_236 )
{
if ( V_6 -> V_237 != V_236 -> V_238 )
return false ;
if ( V_6 -> V_100 == 0 )
return true ;
if ( F_80 ( V_236 , 3 ) < 32 )
return false ;
return true ;
}
static const struct V_5 * F_81 ( struct V_236 * V_236 )
{
unsigned int V_87 ;
for ( V_87 = 0 ; V_87 < F_82 ( V_239 ) ; V_87 ++ )
if ( F_79 ( & V_239 [ V_87 ] , V_236 ) )
return & V_239 [ V_87 ] ;
return NULL ;
}
static int F_83 ( struct V_3 * V_4 ,
unsigned long V_240 )
{
struct V_236 * V_236 = F_84 ( V_4 ) ;
const struct V_5 * V_6 ;
struct V_8 * V_9 ;
struct V_50 * V_51 ;
int V_241 ;
F_59 ( V_4 -> V_69 , L_13 ,
F_85 ( V_236 ) ) ;
V_9 = F_86 ( V_4 , sizeof( * V_9 ) ) ;
if ( ! V_9 )
return - V_242 ;
F_87 ( & V_9 -> V_123 ) ;
F_87 ( & V_9 -> V_26 ) ;
F_87 ( & V_9 -> V_199 ) ;
F_87 ( & V_9 -> V_118 ) ;
V_6 = F_81 ( V_236 ) ;
if ( ! V_6 ) {
F_49 ( V_4 -> V_69 ,
L_14 ) ;
return - V_71 ;
}
V_4 -> V_7 = V_6 ;
V_4 -> V_243 = V_6 -> V_244 ;
V_241 = F_88 ( V_4 ) ;
if ( V_241 )
return V_241 ;
V_4 -> V_47 = F_89 ( V_236 , 2 ) ;
V_9 -> V_12 = F_89 ( V_236 , 3 ) ;
F_30 ( V_4 -> V_69 ,
L_15 ,
V_4 -> V_243 , V_4 -> V_47 , V_9 -> V_12 ) ;
V_9 -> V_129 = F_3 ( V_9 -> V_12 + V_88 ) &
V_130 ;
if ( F_80 ( V_236 , 3 ) >= 32 ) {
unsigned short V_245 = 0 ;
V_9 -> V_75 = F_3 ( V_9 -> V_12 + V_246 ) ;
if ( V_9 -> V_75 < V_6 -> V_100 ) {
F_49 ( V_4 -> V_69 ,
L_16 ,
V_4 -> V_243 , V_9 -> V_75 ,
V_6 -> V_100 ) ;
return - V_247 ;
}
if ( V_9 -> V_75 > 0 ) {
if ( ! V_6 -> V_185 ) {
V_245 |= V_248 ;
}
if ( V_6 -> V_17 && V_9 -> V_75 >= 2 ) {
V_245 |= V_249 ;
}
}
F_6 ( V_245 , V_9 -> V_12 + V_250 ) ;
if ( V_245 & V_249 ) {
F_6 ( V_9 -> V_129 | V_172 |
V_131 ,
V_9 -> V_12 + V_88 ) ;
F_6 ( 0 , V_9 -> V_12 + V_171 ) ;
F_6 ( V_9 -> V_129 , V_9 -> V_12 + V_88 ) ;
}
}
F_21 ( 0 , V_4 -> V_47 + V_128 ) ;
V_9 -> V_78 = 0 ;
V_9 -> V_63 = V_205 | V_77 |
V_80 ;
F_6 ( 1 << 0 , V_9 -> V_12 + V_82 ) ;
F_6 ( V_9 -> V_78 , V_9 -> V_12 + V_83 ) ;
F_6 ( V_9 -> V_63 | V_84 ,
V_9 -> V_12 + V_56 ) ;
if ( V_236 -> V_223 ) {
V_241 = F_90 ( V_236 -> V_223 , F_77 , V_251 ,
V_4 -> V_243 , V_4 ) ;
if ( V_241 == 0 )
V_4 -> V_223 = V_236 -> V_223 ;
}
V_4 -> V_46 = F_91 ( V_4 -> V_47 + V_252 ,
0 , V_253 , 0 ) ;
if ( ! V_4 -> V_46 )
return - V_242 ;
V_241 = F_92 ( V_4 , 3 ) ;
if ( V_241 )
return V_241 ;
V_51 = & V_4 -> V_254 [ 0 ] ;
V_51 -> type = V_255 ;
V_51 -> V_256 = V_257 | V_258 | V_259 ;
V_51 -> V_68 = 16 ;
V_51 -> V_260 = ( 1 << V_6 -> V_15 ) - 1 ;
V_51 -> V_261 = & V_262 ;
V_51 -> V_263 = F_26 ;
V_51 -> V_264 = 256 ;
if ( V_4 -> V_223 ) {
V_4 -> V_231 = V_51 ;
V_51 -> V_256 |= V_265 ;
V_51 -> V_266 = F_74 ;
V_51 -> V_267 = F_60 ;
V_51 -> V_268 = F_76 ;
}
V_51 = & V_4 -> V_254 [ 1 ] ;
if ( V_6 -> V_17 ) {
V_51 -> type = V_269 ;
V_51 -> V_256 = V_270 | V_259 ;
V_51 -> V_68 = 2 ;
V_51 -> V_260 = ( 1 << V_6 -> V_17 ) - 1 ;
V_51 -> V_261 = & V_271 ;
V_51 -> V_272 = F_33 ;
V_51 -> V_264 = 2 ;
if ( V_4 -> V_223 ) {
V_4 -> V_229 = V_51 ;
V_51 -> V_256 |= V_273 ;
V_51 -> V_266 = F_55 ;
V_51 -> V_267 = F_35 ;
V_51 -> V_268 = F_56 ;
}
V_241 = F_93 ( V_51 ) ;
if ( V_241 )
return V_241 ;
} else {
V_51 -> type = V_274 ;
}
V_51 = & V_4 -> V_254 [ 2 ] ;
if ( V_6 -> V_185 ) {
V_241 = F_94 ( V_4 , V_51 , NULL , V_275 ) ;
if ( V_241 )
return V_241 ;
} else {
V_51 -> type = V_274 ;
}
return 0 ;
}
static int F_95 ( struct V_236 * V_4 ,
const struct V_276 * V_237 )
{
return F_96 ( V_4 , & V_277 ,
V_237 -> V_278 ) ;
}
