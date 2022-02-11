static unsigned short F_1 ( struct V_1 * V_2 )
{
const struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = V_2 -> V_7 ;
unsigned short V_8 ;
V_8 = F_3 ( V_2 -> V_9 + V_10 ) ;
V_8 = V_8 >> ( 16 - V_4 -> V_11 ) ;
if ( V_6 -> V_12 )
V_8 ^= 1 << ( V_4 -> V_11 - 1 ) ;
return V_8 ;
}
static inline unsigned short F_4 ( struct V_1 * V_2 ,
unsigned short V_13 )
{
const struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = V_2 -> V_7 ;
if ( V_6 -> V_14 )
V_13 ^= 1 << ( V_4 -> V_15 - 1 ) ;
V_13 <<= ( 16 - V_4 -> V_15 ) ;
return V_13 ;
}
static inline void F_5 ( struct V_1 * V_2 ,
unsigned short V_13 ,
unsigned int V_16 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
V_6 -> V_17 [ V_16 ] = V_13 ;
F_6 ( F_4 ( V_2 , V_13 ) , V_2 -> V_9 + ( ( ( V_16 ) == 0 )
? V_18
:
V_19 ) ) ;
}
static inline void F_7 ( struct V_1 * V_2 ,
unsigned short V_13 , unsigned int V_16 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
V_6 -> V_17 [ V_16 ] = V_13 ;
F_6 ( F_4 ( V_2 , V_13 ) ,
V_2 -> V_9 + V_20 ) ;
}
static int F_8 ( struct V_1 * V_2 , unsigned int V_21 ,
unsigned char V_22 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
int V_23 ;
unsigned int V_24 ;
unsigned int V_25 ;
unsigned int V_26 ;
unsigned long V_27 ;
V_23 = 1 ;
V_26 = 0 ;
F_9 ( & V_6 -> V_28 , V_27 ) ;
for ( V_25 = 1 , V_24 = 0 ; ( V_24 < V_29 )
&& ( V_21 != 0 ) ; V_25 <<= 1 , V_24 ++ ) {
if ( ( V_21 & V_25 ) != 0 ) {
V_21 &= ~ V_25 ;
if ( V_6 -> V_30 [ V_24 ] == V_31 ) {
V_6 -> V_30 [ V_24 ] = V_22 ;
V_26 |= V_25 ;
} else if ( V_6 -> V_30 [ V_24 ] != V_22 ) {
for ( V_25 = 1 , V_24 = 0 ; V_26 != 0 ; V_25 <<= 1 , V_24 ++ ) {
if ( ( V_26 & V_25 ) != 0 ) {
V_6 -> V_30 [ V_24 ]
= V_31 ;
V_26 &= ~ V_25 ;
}
}
V_23 = 0 ;
break;
}
}
}
F_10 ( & V_6 -> V_28 , V_27 ) ;
return V_23 ;
}
static inline int F_11 ( struct V_1 * V_2 ,
unsigned int V_32 , unsigned char V_22 )
{
return F_8 ( V_2 , ( 1U << V_32 ) , V_22 ) ;
}
static void F_12 ( struct V_1 * V_2 , unsigned int V_21 ,
unsigned char V_22 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
unsigned int V_24 ;
unsigned int V_25 ;
unsigned long V_27 ;
F_9 ( & V_6 -> V_28 , V_27 ) ;
for ( V_25 = 1 , V_24 = 0 ; ( V_24 < V_29 )
&& ( V_21 != 0 ) ; V_25 <<= 1 , V_24 ++ ) {
if ( ( V_21 & V_25 ) != 0 ) {
V_21 &= ~ V_25 ;
if ( V_6 -> V_30 [ V_24 ] == V_22 )
V_6 -> V_30 [ V_24 ] = V_31 ;
}
}
F_10 ( & V_6 -> V_28 , V_27 ) ;
}
static inline void F_13 ( struct V_1 * V_2 ,
unsigned int V_32 , unsigned char V_22 )
{
F_12 ( V_2 , ( 1U << V_32 ) , V_22 ) ;
}
static inline void F_14 ( struct V_1 * V_2 ,
unsigned char V_22 )
{
F_12 ( V_2 , ( 1U << V_29 ) - 1 , V_22 ) ;
}
static unsigned int F_15 ( T_1 V_33 , unsigned int V_34 ,
unsigned int V_35 )
{
T_1 div ;
unsigned int V_36 ;
div = V_33 ;
V_36 = F_16 ( div , V_34 ) ;
V_35 &= V_37 ;
switch ( V_35 ) {
default:
case V_38 :
div += ( V_36 + ( V_34 / 2 ) ) / V_34 ;
break;
case V_39 :
break;
case V_40 :
div += ( V_36 + V_34 - 1 ) / V_34 ;
break;
}
return div > V_41 ? V_41 : ( unsigned int ) div ;
}
static unsigned int F_17 ( T_1 V_33 , unsigned int * V_42 ,
unsigned int V_35 )
{
unsigned int V_43 , V_44 ;
for ( V_43 = V_45 ; ; V_43 ++ ) {
V_44 = F_15 ( V_33 , V_46 [ V_43 ] , V_35 ) ;
if ( ( V_44 <= 65536 ) || ( V_43 == V_47 ) )
break;
}
* V_42 = V_44 ;
return V_43 ;
}
static void F_18 ( unsigned int * V_33 , unsigned int V_48 )
{
unsigned int V_42 ;
unsigned int V_43 ;
V_43 = F_17 ( * V_33 , & V_42 , V_48 ) ;
* V_33 = V_42 * V_46 [ V_43 ] ;
return;
}
static void F_19 ( struct V_1 * V_2 , unsigned int V_49 ,
unsigned int V_50 , T_1 V_33 ,
unsigned int V_48 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
unsigned int V_43 ;
unsigned int V_42 ;
F_20 ( V_6 -> V_51 + V_52 , 0 , V_49 , V_50 ) ;
V_43 = F_17 ( V_33 , & V_42 , V_48 ) ;
F_21 ( F_22 ( V_49 , V_43 ) , V_6 -> V_51 + V_53 ) ;
if ( V_42 >= 65536 )
V_42 = 0 ;
F_23 ( V_6 -> V_51 + V_52 , 0 , V_49 , V_42 ) ;
}
static void F_24 ( struct V_1 * V_2 , unsigned int V_49 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
F_20 ( V_6 -> V_51 + V_52 , 0 , V_49 ,
V_54 ) ;
}
static int F_25 ( struct V_1 * V_2 ,
struct V_55 * V_56 ,
struct V_57 * V_58 ,
unsigned long V_59 )
{
unsigned int V_60 ;
V_60 = F_3 ( V_2 -> V_9 + V_61 ) ;
if ( ( V_60 & V_62 ) == 0 )
return 0 ;
return - V_63 ;
}
static int F_26 ( struct V_1 * V_2 ,
struct V_55 * V_56 , struct V_57 * V_58 ,
unsigned int * V_8 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
unsigned int V_64 ;
unsigned int V_16 , V_65 , V_66 ;
unsigned int V_67 ;
unsigned short V_68 , V_69 ;
int V_70 ;
V_16 = F_27 ( V_58 -> V_71 ) ;
V_65 = F_28 ( V_58 -> V_71 ) ;
V_66 = F_29 ( V_58 -> V_71 ) ;
if ( V_66 == V_72 ) {
if ( V_16 >= V_56 -> V_73 / 2 ) {
F_30 ( V_2 -> V_74 ,
L_1 ,
V_75 , ( V_56 -> V_73 / 2 ) - 1 ) ;
return - V_76 ;
}
}
V_68 = V_77 | V_78 ;
F_20 ( V_6 -> V_51 + V_52 , 0 , 2 , V_79 ) ;
V_6 -> V_12 = V_80 [ V_65 ] ;
if ( V_66 == V_72 ) {
V_67 = V_16 * 2 ;
if ( V_6 -> V_81 == 0 ) {
V_69 = 3 << V_67 ;
} else {
V_69 = 1 << V_67 ;
}
V_68 |= V_82 ;
} else {
V_69 = 1 << V_16 ;
V_67 = V_16 & ~ 1 ;
V_68 |= V_83 ;
}
V_6 -> V_84 = ( V_6 -> V_84 & ~ ( 3 << V_67 ) )
| ( V_85 [ V_65 ] << V_67 ) ;
if ( V_6 -> V_12 )
V_68 |= V_86 ;
else
V_68 |= V_87 ;
F_6 ( V_69 , V_2 -> V_9 + V_88 ) ;
F_6 ( V_6 -> V_84 , V_2 -> V_9 + V_89 ) ;
V_6 -> V_68 = V_68 ;
F_6 ( V_68 | V_90 , V_2 -> V_9 + V_61 ) ;
for ( V_64 = 0 ; V_64 < V_58 -> V_64 ; V_64 ++ ) {
F_20 ( V_6 -> V_51 + V_52 , 0 , 2 ,
V_79 ) ;
F_20 ( V_6 -> V_51 + V_52 , 0 , 2 ,
V_54 ) ;
V_70 = F_31 ( V_2 , V_56 , V_58 , F_25 , 0 ) ;
if ( V_70 )
return V_70 ;
V_8 [ V_64 ] = F_1 ( V_2 ) ;
}
return V_64 ;
}
static int F_32 ( struct V_1 * V_2 ,
struct V_55 * V_56 , struct V_57 * V_58 ,
unsigned int * V_8 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
int V_24 ;
int V_16 , V_65 ;
V_16 = F_27 ( V_58 -> V_71 ) ;
V_65 = F_28 ( V_58 -> V_71 ) ;
V_6 -> V_14 = V_91 [ V_65 ] ;
F_6 ( V_65 , V_2 -> V_9 + V_92 ) ;
for ( V_24 = 0 ; V_24 < V_58 -> V_64 ; V_24 ++ ) {
F_5 ( V_2 , V_8 [ V_24 ] , V_16 ) ;
}
return V_24 ;
}
static int F_33 ( struct V_1 * V_2 ,
struct V_55 * V_56 , struct V_57 * V_58 ,
unsigned int * V_8 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
int V_24 ;
int V_16 = F_27 ( V_58 -> V_71 ) ;
for ( V_24 = 0 ; V_24 < V_58 -> V_64 ; V_24 ++ )
V_8 [ V_24 ] = V_6 -> V_17 [ V_16 ] ;
return V_24 ;
}
static int F_34 ( struct V_1 * V_2 ,
struct V_55 * V_56 ,
struct V_93 * V_94 )
{
unsigned int V_95 = F_27 ( V_94 -> V_96 [ 0 ] ) ;
unsigned int V_97 = F_28 ( V_94 -> V_96 [ 0 ] ) ;
int V_24 ;
for ( V_24 = 1 ; V_24 < V_94 -> V_98 ; V_24 ++ ) {
unsigned int V_16 = F_27 ( V_94 -> V_96 [ V_24 ] ) ;
unsigned int V_65 = F_28 ( V_94 -> V_96 [ V_24 ] ) ;
if ( V_16 < V_95 ) {
F_30 ( V_2 -> V_74 ,
L_2 ,
V_75 ) ;
return - V_76 ;
}
if ( V_65 != V_97 ) {
F_30 ( V_2 -> V_74 ,
L_3 ,
V_75 ) ;
return - V_76 ;
}
V_95 = V_16 ;
}
return 0 ;
}
static int F_35 ( struct V_1 * V_2 ,
struct V_55 * V_56 , struct V_93 * V_94 )
{
const struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = V_2 -> V_7 ;
int V_99 = 0 ;
unsigned int V_100 ;
V_99 |= F_36 ( & V_94 -> V_101 , V_102 ) ;
V_100 = V_103 | V_102 ;
if ( ( V_4 -> V_104 > 0 ) && ( V_6 -> V_81 >= 2 ) ) {
V_100 |= V_105 ;
}
V_99 |= F_36 ( & V_94 -> V_106 , V_100 ) ;
V_99 |= F_36 ( & V_94 -> V_107 , V_108 ) ;
V_99 |= F_36 ( & V_94 -> V_109 , V_110 ) ;
V_99 |= F_36 ( & V_94 -> V_111 , V_110 | V_112 ) ;
if ( V_99 )
return 1 ;
V_99 |= F_37 ( V_94 -> V_106 ) ;
V_99 |= F_37 ( V_94 -> V_111 ) ;
if ( V_99 )
return 2 ;
V_99 |= F_38 ( & V_94 -> V_113 , 0 ) ;
#define F_39 8000
#define F_40 4294967295u
switch ( V_94 -> V_106 ) {
case V_103 :
V_99 |= F_41 ( & V_94 -> V_114 ,
F_39 ) ;
V_99 |= F_42 ( & V_94 -> V_114 ,
F_40 ) ;
break;
case V_105 :
if ( ( V_94 -> V_114 & ~ V_115 ) != 0 ) {
V_94 -> V_114 = F_43 ( V_94 -> V_114 , 0 ,
~ V_115 ) ;
V_99 |= - V_76 ;
}
if ( ( V_94 -> V_114
& ( V_115 & ~ ( V_116 | V_117 ) ) ) != 0 ) {
V_94 -> V_114 = F_43 ( V_94 -> V_114 , 0 ,
V_115 &
~ ( V_116 | V_117 ) ) ;
V_99 |= - V_76 ;
}
break;
default:
V_99 |= F_38 ( & V_94 -> V_114 , 0 ) ;
break;
}
V_99 |= F_38 ( & V_94 -> V_118 , V_94 -> V_98 ) ;
if ( V_94 -> V_111 == V_112 )
V_99 |= F_38 ( & V_94 -> V_119 , 0 ) ;
if ( V_99 )
return 3 ;
if ( V_94 -> V_106 == V_103 ) {
V_100 = V_94 -> V_114 ;
F_18 ( & V_94 -> V_114 ,
V_94 -> V_120 & V_37 ) ;
if ( V_100 != V_94 -> V_114 )
V_99 ++ ;
}
if ( V_99 )
return 4 ;
if ( V_94 -> V_96 && V_94 -> V_98 > 0 )
V_99 |= F_34 ( V_2 , V_56 , V_94 ) ;
if ( V_99 )
return 5 ;
return 0 ;
}
static void F_44 ( struct V_1 * V_2 ,
struct V_55 * V_56 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
unsigned long V_27 ;
unsigned char V_121 ;
int V_122 ;
struct V_93 * V_94 ;
F_9 ( & V_6 -> V_123 , V_27 ) ;
V_122 = F_45 ( V_124 , & V_6 -> V_125 ) ;
F_10 ( & V_6 -> V_123 , V_27 ) ;
if ( ! V_122 )
return;
V_94 = & V_56 -> V_126 -> V_94 ;
if ( V_94 -> V_106 == V_103 ) {
F_24 ( V_2 , 1 ) ;
}
if ( V_6 -> V_81 < 2 ) {
V_121 = V_127 ;
} else {
V_121 = V_128 ;
}
F_9 ( & V_6 -> V_129 , V_27 ) ;
V_6 -> V_130 &= ~ V_121 ;
while ( V_6 -> V_131 && V_6 -> V_132 != V_133 ) {
F_10 ( & V_6 -> V_129 , V_27 ) ;
F_9 ( & V_6 -> V_129 , V_27 ) ;
}
if ( V_6 -> V_134 != V_6 -> V_130 ) {
V_6 -> V_134 = V_6 -> V_130 ;
F_21 ( V_6 -> V_134 , V_6 -> V_51 + V_135 ) ;
}
F_10 ( & V_6 -> V_129 , V_27 ) ;
if ( V_6 -> V_81 >= 2 ) {
V_6 -> V_136 &= V_137 ;
F_6 ( V_6 -> V_136 | V_138
| V_139 ,
V_2 -> V_9 + V_92 ) ;
}
F_14 ( V_2 , V_140 ) ;
}
static void F_46 ( struct V_1 * V_2 ,
struct V_55 * V_56 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
unsigned short V_8 ;
int V_24 , V_70 ;
struct V_141 * V_126 = V_56 -> V_126 ;
struct V_93 * V_94 = & V_126 -> V_94 ;
if ( V_94 -> V_111 == V_110 && V_6 -> V_142 == 0 )
return;
for ( V_24 = 0 ; V_24 < V_94 -> V_98 ; V_24 ++ ) {
V_70 = F_47 ( V_56 , & V_8 ) ;
if ( V_70 == 0 ) {
V_56 -> V_126 -> V_143 |= V_144 ;
F_44 ( V_2 , V_56 ) ;
F_48 ( V_2 , L_4 ) ;
return;
}
F_5 ( V_2 , V_8 , F_27 ( V_94 -> V_96 [ V_24 ] ) ) ;
}
V_126 -> V_143 |= V_145 | V_146 ;
if ( V_94 -> V_111 == V_110 ) {
V_6 -> V_142 -- ;
if ( V_6 -> V_142 == 0 ) {
V_126 -> V_143 |= V_147 ;
F_44 ( V_2 , V_56 ) ;
}
}
}
static int F_49 ( struct V_1 * V_2 ,
struct V_55 * V_56 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_141 * V_126 = V_56 -> V_126 ;
struct V_93 * V_94 = & V_126 -> V_94 ;
unsigned int V_148 ;
unsigned int V_149 ;
unsigned short V_150 ;
unsigned int V_24 , V_64 ;
unsigned int V_143 = 0 ;
int V_151 ;
V_150 = F_3 ( V_2 -> V_9 + V_92 ) ;
V_148 = F_50 ( V_56 ) / F_51 ( V_56 ) ;
if ( V_94 -> V_111 == V_110 ) {
if ( V_148 > V_6 -> V_142 )
V_148 = V_6 -> V_142 ;
if ( V_6 -> V_142 == 0 ) {
V_143 |= V_147 ;
}
}
if ( V_143 == 0 ) {
if ( ( V_150 & V_152 ) != 0 ) {
F_48 ( V_2 , L_5 ) ;
V_143 |= V_144 | V_153 ;
}
if ( ( V_148 == 0 )
&& ( ( V_150 & V_154 ) == 0 ) ) {
F_48 ( V_2 , L_4 ) ;
V_143 |= V_144 | V_153 ;
}
}
if ( V_143 == 0 ) {
if ( ( V_150 & V_155 ) != 0 )
V_149 = V_156 ;
else if ( ( V_150 & V_154 ) != 0 )
V_149 = V_157 ;
else if ( ( V_150 & V_158 ) != 0 )
V_149 = V_159 ;
else
V_149 = V_160 ;
V_149 /= V_94 -> V_98 ;
if ( V_148 > V_149 )
V_148 = V_149 ;
for ( V_64 = 0 ; V_64 < V_148 ; V_64 ++ ) {
for ( V_24 = 0 ; V_24 < V_94 -> V_98 ; V_24 ++ ) {
unsigned short V_13 ;
F_47 ( V_56 , & V_13 ) ;
F_7 ( V_2 , V_13 ,
F_27 ( V_94 -> V_96 [ V_24 ] ) ) ;
}
}
V_143 |= V_146 | V_145 ;
if ( V_94 -> V_111 == V_110 ) {
V_6 -> V_142 -= V_148 ;
if ( V_6 -> V_142 == 0 ) {
V_6 -> V_136 = ( V_6 -> V_136
&
~ V_161 )
| V_162 ;
F_6 ( V_6 -> V_136 ,
V_2 -> V_9 + V_92 ) ;
}
}
V_150 = F_3 ( V_2 -> V_9 + V_92 ) ;
if ( ( V_150 & V_152 ) != 0 ) {
F_48 ( V_2 , L_5 ) ;
V_143 |= V_144 | V_153 ;
}
}
if ( ( V_143 & ( V_147 | V_153 | V_144 ) )
!= 0 ) {
F_44 ( V_2 , V_56 ) ;
V_151 = 0 ;
} else {
V_151 = 1 ;
}
V_126 -> V_143 |= V_143 ;
return V_151 ;
}
static int F_52 ( struct V_1 * V_2 ,
struct V_55 * V_56 ,
unsigned int V_163 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
unsigned long V_27 ;
if ( V_163 != 0 )
return - V_76 ;
F_9 ( & V_6 -> V_123 , V_27 ) ;
if ( F_53 ( V_124 , & V_6 -> V_125 ) ) {
if ( V_6 -> V_81 < 2 ) {
F_10 ( & V_6 -> V_123 ,
V_27 ) ;
F_46 ( V_2 , V_56 ) ;
F_54 ( V_2 , V_56 ) ;
} else {
F_3 ( V_2 -> V_9 + V_164 ) ;
F_10 ( & V_6 -> V_123 ,
V_27 ) ;
}
F_55 ( 8 ) ;
} else {
F_10 ( & V_6 -> V_123 , V_27 ) ;
}
return 1 ;
}
static void F_56 ( struct V_1 * V_2 ,
struct V_55 * V_56 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_141 * V_126 = V_56 -> V_126 ;
struct V_93 * V_94 = & V_126 -> V_94 ;
unsigned long V_27 ;
F_57 ( V_124 , & V_6 -> V_125 ) ;
if ( V_94 -> V_111 == V_110 && V_6 -> V_142 == 0 ) {
V_126 -> V_143 |= V_147 ;
F_44 ( V_2 , V_56 ) ;
F_54 ( V_2 , V_56 ) ;
} else {
if ( V_6 -> V_81 >= 2 ) {
unsigned short V_165 ;
int V_166 ;
V_166 = F_49 ( V_2 , V_56 ) ;
F_54 ( V_2 , V_56 ) ;
if ( ! V_166 ) {
return;
}
switch ( V_94 -> V_106 ) {
case V_103 :
V_165 = V_167 ;
break;
case V_105 :
if ( ( V_94 -> V_114 & V_117 ) == 0 ) {
V_165 = V_168 ;
} else {
V_165 = V_169 ;
}
break;
case V_102 :
V_165 = V_170 ;
break;
default:
V_165 = V_171 ;
break;
}
V_6 -> V_136 = ( V_6 -> V_136
& ~ V_172 ) |
V_165 ;
F_6 ( V_6 -> V_136 , V_2 -> V_9 + V_92 ) ;
}
switch ( V_94 -> V_106 ) {
case V_103 :
if ( V_6 -> V_81 < 2 ) {
F_9 ( & V_6 -> V_129 ,
V_27 ) ;
V_6 -> V_130 |= V_127 ;
V_6 -> V_134 |= V_127 ;
F_21 ( V_6 -> V_134 ,
V_6 -> V_51 + V_135 ) ;
F_10 ( & V_6 -> V_129 ,
V_27 ) ;
}
F_21 ( F_58 ( 1 , V_173 ) ,
V_6 -> V_51 + V_174 ) ;
break;
case V_102 :
V_126 -> V_175 = F_52 ;
break;
}
if ( V_6 -> V_81 >= 2 ) {
F_9 ( & V_6 -> V_129 , V_27 ) ;
V_6 -> V_130 |= V_128 ;
V_6 -> V_134 |= V_128 ;
F_21 ( V_6 -> V_134 , V_6 -> V_51 + V_135 ) ;
F_10 ( & V_6 -> V_129 ,
V_27 ) ;
}
}
}
static int F_59 ( struct V_1 * V_2 ,
struct V_55 * V_56 ,
unsigned int V_163 )
{
struct V_93 * V_94 = & V_56 -> V_126 -> V_94 ;
if ( V_163 != V_94 -> V_101 )
return - V_76 ;
V_56 -> V_126 -> V_175 = NULL ;
F_56 ( V_2 , V_56 ) ;
return 1 ;
}
static int F_60 ( struct V_1 * V_2 , struct V_55 * V_56 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
unsigned short V_136 ;
unsigned int V_65 ;
struct V_93 * V_94 = & V_56 -> V_126 -> V_94 ;
if ( V_94 -> V_106 == V_103 ) {
if ( ! F_11 ( V_2 , V_176 , V_140 ) )
return - V_63 ;
}
if ( V_94 -> V_111 == V_110 )
V_6 -> V_142 = V_94 -> V_119 ;
else
V_6 -> V_142 = 0 ;
V_65 = F_28 ( V_94 -> V_96 [ 0 ] ) ;
V_6 -> V_14 = V_91 [ V_65 ] ;
V_136 = V_6 -> V_14 ? V_177 : V_178 ;
if ( V_6 -> V_81 >= 2 ) {
unsigned short V_179 ;
unsigned int V_24 ;
V_179 = 0 ;
for ( V_24 = 0 ; V_24 < V_94 -> V_98 ; V_24 ++ )
V_179 |= 1 << F_27 ( V_94 -> V_96 [ V_24 ] ) ;
F_6 ( V_179 , V_2 -> V_9 + V_180 ) ;
V_136 |= V_181 | V_138
| V_139
| V_171 | V_182 ;
}
F_6 ( V_136 , V_2 -> V_9 + V_92 ) ;
V_6 -> V_136 = V_136
& ~ ( V_138 | V_139 ) ;
if ( V_94 -> V_106 == V_103 ) {
F_21 ( F_58 ( 1 , V_183 ) ,
V_6 -> V_51 + V_174 ) ;
F_19 ( V_2 , 1 , V_184 ,
V_94 -> V_114 ,
V_94 -> V_120 & V_37 ) ;
}
V_56 -> V_126 -> V_175 = F_59 ;
return 0 ;
}
static int F_61 ( struct V_1 * V_2 ,
struct V_55 * V_56 )
{
F_44 ( V_2 , V_56 ) ;
return 0 ;
}
static int F_62 ( struct V_93 * V_94 )
{
unsigned int V_185 , V_98 ;
int V_99 = 0 ;
V_98 = V_94 -> V_98 ;
if ( V_94 -> V_98 == 0 )
V_98 = 1 ;
V_185 = V_98 * V_94 -> V_186 ;
if ( ( V_185 < V_98 )
|| ( V_185 < V_94 -> V_186 ) ) {
V_185 = V_41 ;
V_99 ++ ;
}
if ( V_94 -> V_114 < V_185 ) {
V_94 -> V_114 = V_185 ;
V_99 ++ ;
}
return ! V_99 ;
}
static int F_63 ( struct V_1 * V_2 ,
struct V_55 * V_56 ,
struct V_93 * V_94 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
unsigned int V_187 = ( V_56 -> V_73 / 2 ) - 1 ;
unsigned int V_95 = 0 ;
unsigned int V_188 = 0 ;
unsigned int V_189 = 0 ;
unsigned int V_190 = 0 ;
unsigned int V_191 = 0 ;
int V_24 ;
for ( V_24 = 0 ; V_24 < V_94 -> V_98 ; V_24 ++ ) {
unsigned int V_71 = V_94 -> V_96 [ V_24 ] ;
unsigned int V_16 = F_27 ( V_71 ) ;
unsigned int V_65 = F_28 ( V_71 ) ;
unsigned int V_66 = F_29 ( V_71 ) ;
unsigned int V_192 = V_80 [ V_65 ] ;
if ( V_66 == V_72 && V_16 >= V_187 ) {
F_30 ( V_2 -> V_74 ,
L_1 ,
V_75 , V_187 ) ;
return - V_76 ;
}
if ( V_24 > 0 ) {
if ( V_16 <= V_95 && V_191 == 0 )
V_191 = V_24 ;
if ( V_191 > 0 &&
V_94 -> V_96 [ V_24 % V_191 ] != V_71 ) {
F_30 ( V_2 -> V_74 ,
L_6 ,
V_75 ) ;
return - V_76 ;
}
if ( V_66 != V_189 ) {
F_30 ( V_2 -> V_74 ,
L_7 ,
V_75 ) ;
return - V_76 ;
}
if ( V_192 != V_190 ) {
F_30 ( V_2 -> V_74 ,
L_8 ,
V_75 ) ;
return - V_76 ;
}
if ( V_66 != V_72 && V_65 != V_188 &&
( ( V_16 ^ V_95 ) & ~ 1 ) == 0 ) {
F_30 ( V_2 -> V_74 ,
L_9 ,
V_75 ) ;
return - V_76 ;
}
}
V_95 = V_16 ;
V_188 = V_65 ;
V_189 = V_66 ;
V_190 = V_192 ;
}
if ( V_191 == 0 )
V_191 = V_94 -> V_98 ;
if ( ( V_94 -> V_98 % V_191 ) != 0 ) {
F_30 ( V_2 -> V_74 ,
L_10 , V_75 ) ;
return - V_76 ;
}
if ( V_6 -> V_81 > 0 && V_6 -> V_81 < 4 ) {
if ( V_191 > 1 && F_27 ( V_94 -> V_96 [ 0 ] ) != 0 ) {
F_64 ( V_2 -> V_74 ,
L_11 ,
V_6 -> V_81 ) ;
return - V_76 ;
}
}
return 0 ;
}
static int F_65 ( struct V_1 * V_2 ,
struct V_55 * V_56 , struct V_93 * V_94 )
{
const struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = V_2 -> V_7 ;
int V_99 = 0 ;
unsigned int V_100 ;
V_99 |= F_36 ( & V_94 -> V_101 , V_108 | V_102 ) ;
V_100 = V_193 | V_103 | V_102 ;
if ( ( V_4 -> V_194 ) || ( V_4 -> V_104 > 0 ) ) {
V_100 |= V_105 ;
}
V_99 |= F_36 ( & V_94 -> V_106 , V_100 ) ;
V_99 |= F_36 ( & V_94 -> V_107 ,
V_103 | V_102 | V_105 ) ;
V_99 |= F_36 ( & V_94 -> V_109 , V_110 ) ;
V_99 |= F_36 ( & V_94 -> V_111 , V_110 | V_112 ) ;
if ( V_99 )
return 1 ;
V_99 |= F_37 ( V_94 -> V_101 ) ;
V_99 |= F_37 ( V_94 -> V_106 ) ;
V_99 |= F_37 ( V_94 -> V_107 ) ;
V_99 |= F_37 ( V_94 -> V_111 ) ;
if ( ( V_94 -> V_106 != V_193 )
&& ( V_94 -> V_107 != V_103 ) )
V_99 |= - V_76 ;
if ( V_99 )
return 2 ;
V_99 |= F_38 ( & V_94 -> V_113 , 0 ) ;
#define F_66 3200
#define F_67 8000
#define F_68 4000
#define F_69 4294967295u
if ( V_94 -> V_107 == V_103 ) {
unsigned int V_195 ;
if ( V_6 -> V_81 == 0 ) {
if ( V_94 -> V_96 && ( V_94 -> V_98 > 0 ) ) {
if ( F_29 ( V_94 -> V_96 [ 0 ] ) == V_72 )
V_195 = F_67 ;
else
V_195 = F_66 ;
} else {
V_195 = F_66 ;
}
} else {
V_195 = F_68 ;
}
V_99 |= F_41 ( & V_94 -> V_186 ,
V_195 ) ;
V_99 |= F_42 ( & V_94 -> V_186 ,
F_69 ) ;
} else if ( V_94 -> V_107 == V_105 ) {
if ( ( V_94 -> V_186 & V_115 ) != 0 ) {
if ( ( V_94 -> V_186 & ~ V_115 ) != 0 ) {
V_94 -> V_186 = F_43 ( V_94 -> V_186 , 0 ,
~ V_115 ) ;
V_99 |= - V_76 ;
}
if ( ( V_94 -> V_186 & ( V_115 & ~ V_117 ) )
!= V_116 ) {
V_94 -> V_186 = F_43 ( V_94 -> V_113 ,
( V_116 | 0 ) ,
V_115 &
~ V_117 ) ;
V_99 |= - V_76 ;
}
} else {
V_99 |= F_42 ( & V_94 -> V_186 , 1 ) ;
}
} else {
V_99 |= F_38 ( & V_94 -> V_186 , 0 ) ;
}
V_99 |= F_38 ( & V_94 -> V_118 , V_94 -> V_98 ) ;
if ( V_94 -> V_111 == V_112 )
V_99 |= F_38 ( & V_94 -> V_119 , 0 ) ;
if ( V_94 -> V_106 == V_105 ) {
if ( ( V_94 -> V_114 & ~ V_115 ) != 0 ) {
V_94 -> V_114 = F_43 ( V_94 -> V_114 , 0 ,
~ V_115 ) ;
V_99 |= - V_76 ;
}
if ( ( V_94 -> V_114 & V_115 & ~ V_116 ) != 0 ) {
V_94 -> V_114 = F_43 ( V_94 -> V_114 , 0 ,
V_115 & ~ V_116 ) ;
V_99 |= - V_76 ;
}
} else if ( V_94 -> V_106 == V_103 ) {
if ( ! F_62 ( V_94 ) )
V_99 |= - V_76 ;
} else {
V_99 |= F_38 ( & V_94 -> V_114 , 0 ) ;
}
if ( V_99 )
return 3 ;
if ( V_94 -> V_107 == V_103 ) {
V_100 = V_94 -> V_186 ;
F_18 ( & V_94 -> V_186 ,
V_94 -> V_120 & V_37 ) ;
if ( V_100 != V_94 -> V_186 )
V_99 ++ ;
}
if ( V_94 -> V_106 == V_103 ) {
V_100 = V_94 -> V_114 ;
F_18 ( & V_94 -> V_114 ,
V_94 -> V_120 & V_37 ) ;
if ( ! F_62 ( V_94 ) ) {
F_18 ( & V_94 -> V_114 ,
V_40 ) ;
F_62 ( V_94 ) ;
}
if ( V_100 != V_94 -> V_114 )
V_99 ++ ;
}
if ( V_99 )
return 4 ;
if ( V_94 -> V_96 && V_94 -> V_98 > 0 )
V_99 |= F_63 ( V_2 , V_56 , V_94 ) ;
if ( V_99 )
return 5 ;
return 0 ;
}
static void F_70 ( struct V_1 * V_2 ,
struct V_55 * V_56 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_93 * V_94 = & V_56 -> V_126 -> V_94 ;
unsigned int V_196 = V_94 -> V_118 ;
unsigned int V_197 ;
unsigned short V_198 ;
unsigned short V_68 ;
if ( ( V_94 -> V_120 & V_199 ) != 0 ) {
V_197 = V_196 - V_6 -> V_200 ;
} else {
if ( V_94 -> V_111 != V_110 ||
V_6 -> V_201 >= V_202 ||
V_196 >= V_202 ) {
V_197 = V_202 ;
} else {
V_197 = ( V_6 -> V_201 * V_196 )
- V_6 -> V_200 ;
}
}
if ( V_197 >= V_202 ) {
V_198 = V_203 ;
} else {
if ( ( V_197 > 1 ) && ( V_6 -> V_81 > 0 ) ) {
if ( V_6 -> V_204 != V_197 ) {
V_6 -> V_204 = V_197 ;
F_6 ( V_197 , V_2 -> V_9 + V_205 ) ;
}
V_198 = V_206 ;
} else {
V_198 = V_207 ;
}
}
V_68 = ( V_6 -> V_68 & ~ V_208 ) | V_198 ;
if ( V_68 != V_6 -> V_68 ) {
V_6 -> V_68 = V_68 ;
F_6 ( V_68 , V_2 -> V_9 + V_61 ) ;
}
}
static int F_71 ( struct V_1 * V_2 ,
struct V_55 * V_56 ,
unsigned int V_163 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
unsigned long V_27 ;
if ( V_163 != 0 )
return - V_76 ;
F_9 ( & V_6 -> V_209 , V_27 ) ;
if ( F_53 ( V_210 , & V_6 -> V_125 ) ) {
unsigned int V_211 ;
F_20 ( V_6 -> V_51 + V_52 , 0 , 2 ,
V_79 ) ;
F_20 ( V_6 -> V_51 + V_52 , 0 , 2 ,
V_54 ) ;
if ( ( ( V_6 -> V_68 & V_212 )
== V_82 )
&& ( V_6 -> V_81 == 0 ) ) {
V_211 = 8 ;
} else {
V_211 = 4 ;
}
F_10 ( & V_6 -> V_209 , V_27 ) ;
F_55 ( V_211 ) ;
} else {
F_10 ( & V_6 -> V_209 , V_27 ) ;
}
return 1 ;
}
static int F_72 ( struct V_1 * V_2 ,
struct V_55 * V_56 ,
unsigned int V_163 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
unsigned long V_27 ;
unsigned char V_213 ;
if ( V_163 != 0 )
return - V_76 ;
F_9 ( & V_6 -> V_209 , V_27 ) ;
if ( F_53 ( V_210 , & V_6 -> V_125 ) ) {
V_213 = F_58 ( 0 , V_183 ) ;
F_21 ( V_213 , V_6 -> V_51 + V_174 ) ;
V_213 = F_58 ( 0 , V_173 ) ;
F_21 ( V_213 , V_6 -> V_51 + V_174 ) ;
}
F_10 ( & V_6 -> V_209 , V_27 ) ;
return 1 ;
}
static void F_73 ( struct V_1 * V_2 ,
struct V_55 * V_56 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
unsigned long V_27 ;
struct V_93 * V_94 ;
int V_122 ;
F_9 ( & V_6 -> V_209 , V_27 ) ;
V_122 = F_45 ( V_210 , & V_6 -> V_125 ) ;
F_10 ( & V_6 -> V_209 , V_27 ) ;
if ( ! V_122 )
return;
V_94 = & V_56 -> V_126 -> V_94 ;
if ( V_94 -> V_107 == V_103 ) {
F_24 ( V_2 , 2 ) ;
}
if ( V_94 -> V_106 != V_193 ) {
F_24 ( V_2 , 0 ) ;
}
F_9 ( & V_6 -> V_129 , V_27 ) ;
V_6 -> V_130 &= ~ V_214 ;
while ( V_6 -> V_131 && V_6 -> V_132 != V_133 ) {
F_10 ( & V_6 -> V_129 , V_27 ) ;
F_9 ( & V_6 -> V_129 , V_27 ) ;
}
if ( V_6 -> V_134 != V_6 -> V_130 ) {
V_6 -> V_134 = V_6 -> V_130 ;
F_21 ( V_6 -> V_134 , V_6 -> V_51 + V_135 ) ;
}
F_10 ( & V_6 -> V_129 , V_27 ) ;
V_6 -> V_68 = ( V_6 -> V_68 & ( V_215
| V_212 ) ) |
V_216 ;
F_6 ( V_6 -> V_68 | V_90 ,
V_2 -> V_9 + V_61 ) ;
F_14 ( V_2 , V_217 ) ;
}
static void F_74 ( struct V_1 * V_2 ,
struct V_55 * V_56 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
unsigned long V_27 ;
unsigned short V_218 ;
struct V_141 * V_126 = V_56 -> V_126 ;
struct V_93 * V_94 = & V_126 -> V_94 ;
F_57 ( V_210 , & V_6 -> V_125 ) ;
if ( V_94 -> V_111 == V_110 && V_6 -> V_201 == 0 ) {
V_126 -> V_143 |= V_147 ;
F_73 ( V_2 , V_56 ) ;
F_54 ( V_2 , V_56 ) ;
} else {
F_9 ( & V_6 -> V_129 , V_27 ) ;
V_6 -> V_130 |= V_214 ;
V_6 -> V_134 |= V_214 ;
F_21 ( V_6 -> V_134 , V_6 -> V_51 + V_135 ) ;
F_10 ( & V_6 -> V_129 , V_27 ) ;
switch ( V_94 -> V_107 ) {
default:
V_218 = V_216 ;
break;
case V_103 :
V_218 = V_77 ;
break;
case V_105 :
if ( ( V_94 -> V_186 & V_116 ) != 0 ) {
if ( ( V_94 -> V_186 & V_117 ) == 0 ) {
V_218 = V_219 ;
} else {
V_218 = V_220 ;
}
} else {
if ( V_94 -> V_186 != 0 ) {
V_218 = V_219 ;
} else {
V_218 = V_220 ;
}
}
break;
case V_102 :
V_218 = V_77 ;
break;
}
V_6 -> V_68 = ( V_6 -> V_68 & ~ V_221 )
| V_218 ;
F_6 ( V_6 -> V_68 , V_2 -> V_9 + V_61 ) ;
if ( V_94 -> V_107 == V_102 )
V_126 -> V_175 = F_71 ;
F_70 ( V_2 , V_56 ) ;
if ( V_94 -> V_107 == V_103 ) {
unsigned char V_213 ;
if ( V_94 -> V_106 != V_193 ) {
V_213 = F_58 ( 2 , V_222 ) ;
} else {
V_213 = F_58 ( 2 , V_173 ) ;
}
F_21 ( V_213 , V_6 -> V_51 + V_174 ) ;
if ( V_94 -> V_106 != V_193 ) {
switch ( V_94 -> V_106 ) {
default:
V_213 = F_58 ( 0 , V_173 ) ;
break;
case V_105 :
V_213 = F_58 ( 0 , V_223 ) ;
break;
case V_103 :
V_213 = F_58 ( 0 , V_222 ) ;
break;
case V_102 :
V_213 = F_58 ( 0 , V_173 ) ;
break;
}
F_21 ( V_213 , V_6 -> V_51 + V_174 ) ;
switch ( V_94 -> V_106 ) {
case V_103 :
V_213 = F_58 ( 1 , V_173 ) ;
F_21 ( V_213 , V_6 -> V_51
+ V_174 ) ;
break;
case V_102 :
V_126 -> V_175 =
F_72 ;
break;
}
}
} else if ( V_94 -> V_107 != V_102 ) {
F_13 ( V_2 , V_224 , V_217 ) ;
}
}
}
static int F_75 ( struct V_1 * V_2 ,
struct V_55 * V_56 ,
unsigned int V_163 )
{
struct V_93 * V_94 = & V_56 -> V_126 -> V_94 ;
if ( V_163 != V_94 -> V_113 )
return - V_76 ;
V_56 -> V_126 -> V_175 = NULL ;
F_74 ( V_2 , V_56 ) ;
return 1 ;
}
static void F_76 ( struct V_1 * V_2 ,
struct V_55 * V_56 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_141 * V_126 = V_56 -> V_126 ;
struct V_93 * V_94 = & V_126 -> V_94 ;
unsigned int V_196 = V_94 -> V_118 ;
unsigned int V_143 = 0 ;
unsigned int V_225 ;
unsigned int V_24 ;
unsigned int V_226 ;
unsigned int V_227 ;
if ( V_94 -> V_111 != V_110 ) {
V_226 = V_202 ;
} else if ( V_6 -> V_201 == 0 ) {
V_226 = 0 ;
} else if ( ( V_6 -> V_201 > V_202 )
|| ( V_196 > V_202 ) ) {
V_226 = V_202 ;
} else {
V_226 = ( V_6 -> V_201 * V_196 )
- V_6 -> V_200 ;
if ( V_226 > V_202 )
V_226 = V_202 ;
}
if ( V_226 == 0 )
return;
V_227 = 0 ;
for ( V_24 = 0 ; V_24 < V_226 ; V_24 ++ ) {
if ( V_227 == 0 ) {
V_225 = F_3 ( V_2 -> V_9 + V_61 ) ;
if ( ( V_225 & V_228 ) != 0 ) {
F_48 ( V_2 , L_12 ) ;
V_143 |= V_144 | V_153 ;
break;
} else if ( ( V_225 & V_62 ) != 0 ) {
break;
} else if ( ( V_225 & V_229 ) != 0 ) {
V_227 = V_202 ;
} else {
if ( V_6 -> V_81 > 0 ) {
V_227 = F_3 ( V_2 -> V_9
+ V_230 ) ;
if ( V_227 == 0 ) {
break;
}
} else {
V_227 = 1 ;
}
}
}
if ( F_77 ( V_56 , F_1 ( V_2 ) ) == 0 ) {
V_143 |= V_153 | V_144 ;
F_48 ( V_2 , L_13 ) ;
break;
}
V_227 -- ;
V_6 -> V_200 ++ ;
if ( V_6 -> V_200 == V_196 ) {
V_6 -> V_200 = 0 ;
V_6 -> V_201 -- ;
V_126 -> V_143 |= V_146 ;
}
}
if ( V_94 -> V_111 == V_110 && V_6 -> V_201 == 0 ) {
V_143 |= V_147 ;
} else {
V_143 |= V_145 ;
}
V_126 -> V_143 |= V_143 ;
if ( ( V_126 -> V_143 & ( V_147 | V_153 |
V_144 ) ) != 0 ) {
F_73 ( V_2 , V_56 ) ;
} else {
F_70 ( V_2 , V_56 ) ;
}
}
static int F_78 ( struct V_1 * V_2 , struct V_55 * V_56 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
unsigned int V_24 , V_16 , V_65 , V_231 ;
unsigned int V_21 ;
unsigned short V_68 , V_69 ;
unsigned char V_213 ;
struct V_141 * V_126 = V_56 -> V_126 ;
struct V_93 * V_94 = & V_126 -> V_94 ;
V_21 = 0 ;
V_21 |= ( 1U << V_224 ) ;
if ( V_94 -> V_106 != V_193 ) {
V_21 |= ( 1U << V_232 ) ;
if ( V_94 -> V_106 == V_103 ) {
V_21 |= ( 1U << V_176 ) ;
}
}
if ( ! F_8 ( V_2 , V_21 , V_217 ) )
return - V_63 ;
if ( V_94 -> V_111 == V_110 )
V_6 -> V_201 = V_94 -> V_119 ;
else
V_6 -> V_201 = 0 ;
V_6 -> V_200 = 0 ;
V_68 = V_78 ;
V_69 = 0 ;
if ( F_29 ( V_94 -> V_96 [ 0 ] ) == V_72 ) {
V_231 = 1 ;
V_68 |= V_82 ;
} else {
V_231 = 0 ;
V_68 |= V_83 ;
}
V_65 = F_28 ( V_94 -> V_96 [ 0 ] ) ;
V_6 -> V_12 = V_80 [ V_65 ] ;
if ( V_6 -> V_12 )
V_68 |= V_86 ;
else
V_68 |= V_87 ;
for ( V_24 = 0 ; V_24 < V_94 -> V_98 ; V_24 ++ ) {
unsigned int V_67 ;
V_16 = F_27 ( V_94 -> V_96 [ V_24 ] ) ;
V_65 = F_28 ( V_94 -> V_96 [ V_24 ] ) ;
if ( V_231 ) {
V_67 = 2 * V_16 ;
if ( V_6 -> V_81 == 0 ) {
V_69 |= 3 << V_67 ;
} else {
V_69 |= 1 << V_67 ;
}
} else {
V_67 = ( V_16 & ~ 1 ) ;
V_69 |= 1 << V_16 ;
}
V_6 -> V_84 = ( V_6 -> V_84 & ~ ( 3 << V_67 ) )
| ( V_85 [ V_65 ] << V_67 ) ;
}
F_6 ( V_69 , V_2 -> V_9 + V_88 ) ;
F_6 ( V_6 -> V_84 , V_2 -> V_9 + V_89 ) ;
F_20 ( V_6 -> V_51 + V_52 , 0 , 2 , V_54 ) ;
V_68 |= V_233 | V_77 ;
V_6 -> V_68 = V_68 ;
F_6 ( V_68 | V_90 , V_2 -> V_9 + V_61 ) ;
F_55 ( 25 ) ;
F_6 ( V_68 | V_90 , V_2 -> V_9 + V_61 ) ;
if ( V_94 -> V_107 == V_103 ) {
V_213 = F_58 ( 2 , V_183 ) ;
F_21 ( V_213 , V_6 -> V_51 + V_174 ) ;
F_19 ( V_2 , 2 , V_184 , V_94 -> V_186 ,
V_94 -> V_120 & V_37 ) ;
if ( V_94 -> V_106 != V_193 ) {
V_213 = F_58 ( 0 , V_173 ) ;
F_21 ( V_213 , V_6 -> V_51 + V_174 ) ;
F_19 ( V_2 , 0 , V_54 ,
( ( T_1 ) V_94 -> V_186
* V_94 -> V_118 ) ,
V_40 ) ;
if ( V_94 -> V_106 == V_103 ) {
V_213 = F_58 ( 1 , V_183 ) ;
F_21 ( V_213 , V_6 -> V_51 + V_174 ) ;
F_19 ( V_2 , 1 , V_184 ,
V_94 -> V_114 ,
V_94 ->
V_120 &
V_37 ) ;
}
}
}
if ( V_94 -> V_101 == V_102 )
V_56 -> V_126 -> V_175 = F_75 ;
else
F_74 ( V_2 , V_56 ) ;
return 0 ;
}
static int F_79 ( struct V_1 * V_2 ,
struct V_55 * V_56 )
{
F_73 ( V_2 , V_56 ) ;
return 0 ;
}
static T_2 F_80 ( int V_234 , void * V_235 )
{
unsigned char V_236 , V_237 ;
struct V_1 * V_2 = (struct V_1 * ) V_235 ;
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_55 * V_56 ;
unsigned long V_27 ;
V_236 = F_81 ( V_6 -> V_51 + V_238 ) ;
if ( V_236 == V_239 )
return V_240 ;
F_9 ( & V_6 -> V_129 , V_27 ) ;
V_237 = V_6 -> V_130 & V_236 ;
V_6 -> V_134 = V_6 -> V_130 & ~ V_236 ;
F_21 ( V_6 -> V_134 , V_6 -> V_51 + V_135 ) ;
V_6 -> V_131 = 1 ;
V_6 -> V_132 = V_133 ;
F_10 ( & V_6 -> V_129 , V_27 ) ;
if ( ( V_237 & V_127 ) != 0 ) {
V_56 = V_2 -> V_241 ;
F_46 ( V_2 , V_56 ) ;
F_54 ( V_2 , V_56 ) ;
}
if ( ( V_237 & V_128 ) != 0 ) {
V_56 = V_2 -> V_241 ;
F_49 ( V_2 , V_56 ) ;
F_54 ( V_2 , V_56 ) ;
}
if ( ( V_237 & V_214 ) != 0 ) {
V_56 = V_2 -> V_242 ;
F_76 ( V_2 , V_56 ) ;
F_54 ( V_2 , V_56 ) ;
}
F_9 ( & V_6 -> V_129 , V_27 ) ;
if ( V_6 -> V_134 != V_6 -> V_130 ) {
V_6 -> V_134 = V_6 -> V_130 ;
F_21 ( V_6 -> V_134 , V_6 -> V_51 + V_135 ) ;
}
V_6 -> V_131 = 0 ;
F_10 ( & V_6 -> V_129 , V_27 ) ;
return V_243 ;
}
static bool F_82 ( const struct V_3 * V_244 ,
struct V_245 * V_245 )
{
if ( V_244 -> V_246 != V_245 -> V_247 )
return false ;
if ( V_244 -> V_104 == 0 )
return true ;
if ( F_83 ( V_245 , 3 ) < 32 )
return false ;
return true ;
}
static const struct V_3 * F_84 ( struct V_245 * V_245 )
{
unsigned int V_24 ;
for ( V_24 = 0 ; V_24 < F_85 ( V_248 ) ; V_24 ++ )
if ( F_82 ( & V_248 [ V_24 ] , V_245 ) )
return & V_248 [ V_24 ] ;
return NULL ;
}
static struct V_245 * F_86 ( struct V_1 * V_2 ,
struct V_249 * V_250 )
{
const struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_245 * V_245 = NULL ;
int V_251 = V_250 -> V_252 [ 0 ] ;
int V_253 = V_250 -> V_252 [ 1 ] ;
F_87 (pci_dev) {
if ( V_245 -> V_254 != V_255 )
continue;
if ( ( V_251 || V_253 ) &&
( V_251 != V_245 -> V_251 -> V_256 ||
V_253 != F_88 ( V_245 -> V_257 ) ) )
continue;
if ( V_4 -> V_246 == V_258 ) {
const struct V_3 * V_259 ;
V_259 = F_84 ( V_245 ) ;
if ( V_259 == NULL )
continue;
V_2 -> V_260 = V_259 ;
} else {
if ( ! F_82 ( V_4 , V_245 ) )
continue;
}
return V_245 ;
}
F_89 ( V_2 -> V_74 ,
L_14 ,
V_251 , V_253 ) ;
return NULL ;
}
static int F_90 ( struct V_1 * V_2 )
{
struct V_5 * V_6 ;
V_6 = F_91 ( V_2 , sizeof( * V_6 ) ) ;
if ( ! V_6 )
return - V_261 ;
F_92 ( & V_6 -> V_129 ) ;
F_92 ( & V_6 -> V_28 ) ;
F_92 ( & V_6 -> V_209 ) ;
F_92 ( & V_6 -> V_123 ) ;
return 0 ;
}
static int F_93 ( struct V_1 * V_2 ,
struct V_245 * V_245 )
{
const struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_55 * V_56 ;
unsigned long V_51 , V_262 ;
int V_263 ;
F_94 ( V_2 , & V_245 -> V_2 ) ;
V_2 -> V_264 = V_4 -> V_265 ;
V_263 = F_95 ( V_2 ) ;
if ( V_263 )
return V_263 ;
V_51 = F_96 ( V_245 , 2 ) ;
V_262 = F_96 ( V_245 , 3 ) ;
F_30 ( V_2 -> V_74 ,
L_15 ,
V_2 -> V_264 , V_51 , V_262 ) ;
V_6 -> V_51 = V_51 ;
V_2 -> V_9 = V_262 ;
V_6 -> V_136 = F_3 ( V_2 -> V_9 + V_92 ) & V_137 ;
if ( F_83 ( V_245 , 3 ) >= 32 ) {
unsigned short V_266 = 0 ;
V_6 -> V_81 = F_3 ( V_2 -> V_9 + V_267 ) ;
if ( V_6 -> V_81 < V_4 -> V_104 ) {
F_89 ( V_2 -> V_74 ,
L_16 ,
V_2 -> V_264 , V_6 -> V_81 ,
V_4 -> V_104 ) ;
return - V_268 ;
}
if ( V_6 -> V_81 > 0 ) {
if ( ! V_4 -> V_194 ) {
V_266 |= V_269 ;
}
if ( ( V_4 -> V_270 > 0 )
&& ( V_6 -> V_81 >= 2 ) ) {
V_266 |= V_271 ;
}
}
F_6 ( V_266 , V_2 -> V_9 + V_272 ) ;
if ( ( V_266 & V_271 ) != 0 ) {
F_6 ( V_6 -> V_136 | V_181
| V_138 ,
V_2 -> V_9 + V_92 ) ;
F_6 ( 0 , V_2 -> V_9 + V_180 ) ;
F_6 ( V_6 -> V_136 , V_2 -> V_9 + V_92 ) ;
}
}
F_21 ( 0 , V_6 -> V_51 + V_135 ) ;
V_6 -> V_84 = 0 ;
V_6 -> V_68 = V_216 | V_83
| V_86 ;
F_6 ( 1 << 0 , V_2 -> V_9 + V_88 ) ;
F_6 ( V_6 -> V_84 , V_2 -> V_9 + V_89 ) ;
F_6 ( V_6 -> V_68 | V_90 ,
V_2 -> V_9 + V_61 ) ;
if ( V_245 -> V_234 ) {
V_263 = F_97 ( V_245 -> V_234 , F_80 , V_273 ,
V_2 -> V_264 , V_2 ) ;
if ( V_263 == 0 )
V_2 -> V_234 = V_245 -> V_234 ;
}
V_263 = F_98 ( V_2 , 3 ) ;
if ( V_263 )
return V_263 ;
V_56 = & V_2 -> V_274 [ 0 ] ;
V_56 -> type = V_275 ;
V_56 -> V_276 = V_277 | V_278 | V_279 ;
V_56 -> V_73 = V_4 -> V_280 ;
V_56 -> V_281 = ( 1 << V_4 -> V_11 ) - 1 ;
V_56 -> V_282 = & V_283 ;
V_56 -> V_284 = & F_26 ;
V_56 -> V_285 = 256 ;
if ( V_2 -> V_234 ) {
V_2 -> V_242 = V_56 ;
V_56 -> V_276 |= V_286 ;
V_56 -> V_287 = & F_78 ;
V_56 -> V_288 = & F_65 ;
V_56 -> V_289 = F_79 ;
}
V_56 = & V_2 -> V_274 [ 1 ] ;
if ( V_4 -> V_270 > 0 ) {
V_56 -> type = V_290 ;
V_56 -> V_276 = V_291 | V_279 ;
V_56 -> V_73 = V_4 -> V_270 ;
V_56 -> V_281 = ( 1 << V_4 -> V_15 ) - 1 ;
V_56 -> V_282 = & V_292 ;
V_56 -> V_293 = & F_32 ;
V_56 -> V_284 = & F_33 ;
V_56 -> V_285 = V_4 -> V_270 ;
if ( V_2 -> V_234 ) {
V_2 -> V_241 = V_56 ;
V_56 -> V_276 |= V_294 ;
V_56 -> V_287 = & F_60 ;
V_56 -> V_288 = & F_35 ;
V_56 -> V_289 = F_61 ;
}
} else {
V_56 -> type = V_295 ;
}
V_56 = & V_2 -> V_274 [ 2 ] ;
if ( V_4 -> V_194 ) {
V_263 = F_99 ( V_2 , V_56 , NULL ,
V_6 -> V_51 + V_296 ) ;
if ( V_263 )
return V_263 ;
} else {
V_56 -> type = V_295 ;
}
return 0 ;
}
static int F_100 ( struct V_1 * V_2 , struct V_249 * V_250 )
{
const struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_245 * V_245 ;
int V_263 ;
F_64 ( V_2 -> V_74 , L_17 ,
V_4 -> V_265 , V_250 -> V_252 [ 0 ] , V_250 -> V_252 [ 1 ] ) ;
V_263 = F_90 ( V_2 ) ;
if ( V_263 )
return V_263 ;
V_245 = F_86 ( V_2 , V_250 ) ;
if ( ! V_245 )
return - V_268 ;
return F_93 ( V_2 , V_245 ) ;
}
static int F_101 ( struct V_1 * V_2 ,
unsigned long V_297 )
{
struct V_245 * V_245 = F_102 ( V_2 ) ;
int V_263 ;
F_64 ( V_2 -> V_74 , L_18 ,
F_103 ( V_245 ) ) ;
V_263 = F_90 ( V_2 ) ;
if ( V_263 )
return V_263 ;
V_2 -> V_260 = F_84 ( V_245 ) ;
if ( V_2 -> V_260 == NULL ) {
F_89 ( V_2 -> V_74 ,
L_19 ) ;
return - V_76 ;
}
F_104 ( V_245 ) ;
return F_93 ( V_2 , V_245 ) ;
}
static void F_105 ( struct V_1 * V_2 )
{
struct V_245 * V_298 = F_102 ( V_2 ) ;
if ( V_2 -> V_234 )
F_106 ( V_2 -> V_234 , V_2 ) ;
F_107 ( V_2 ) ;
if ( V_298 )
F_108 ( V_298 ) ;
}
static int F_109 ( struct V_245 * V_2 ,
const struct V_299 * V_246 )
{
return F_110 ( V_2 , & V_300 ,
V_246 -> V_301 ) ;
}
