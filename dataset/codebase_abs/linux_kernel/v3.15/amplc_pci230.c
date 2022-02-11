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
struct V_55 * V_56 , struct V_93 * V_94 )
{
const struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = V_2 -> V_7 ;
int V_95 = 0 ;
unsigned int V_96 ;
V_95 |= F_35 ( & V_94 -> V_97 , V_98 ) ;
V_96 = V_99 | V_98 ;
if ( ( V_4 -> V_100 > 0 ) && ( V_6 -> V_81 >= 2 ) ) {
V_96 |= V_101 ;
}
V_95 |= F_35 ( & V_94 -> V_102 , V_96 ) ;
V_95 |= F_35 ( & V_94 -> V_103 , V_104 ) ;
V_95 |= F_35 ( & V_94 -> V_105 , V_106 ) ;
V_95 |= F_35 ( & V_94 -> V_107 , V_106 | V_108 ) ;
if ( V_95 )
return 1 ;
V_95 |= F_36 ( V_94 -> V_102 ) ;
V_95 |= F_36 ( V_94 -> V_107 ) ;
if ( V_95 )
return 2 ;
V_95 |= F_37 ( & V_94 -> V_109 , 0 ) ;
#define F_38 8000
#define F_39 4294967295u
switch ( V_94 -> V_102 ) {
case V_99 :
V_95 |= F_40 ( & V_94 -> V_110 ,
F_38 ) ;
V_95 |= F_41 ( & V_94 -> V_110 ,
F_39 ) ;
break;
case V_101 :
if ( ( V_94 -> V_110 & ~ V_111 ) != 0 ) {
V_94 -> V_110 = F_42 ( V_94 -> V_110 , 0 ,
~ V_111 ) ;
V_95 |= - V_76 ;
}
if ( ( V_94 -> V_110
& ( V_111 & ~ ( V_112 | V_113 ) ) ) != 0 ) {
V_94 -> V_110 = F_42 ( V_94 -> V_110 , 0 ,
V_111 &
~ ( V_112 | V_113 ) ) ;
V_95 |= - V_76 ;
}
break;
default:
V_95 |= F_37 ( & V_94 -> V_110 , 0 ) ;
break;
}
V_95 |= F_37 ( & V_94 -> V_114 , V_94 -> V_115 ) ;
if ( V_94 -> V_107 == V_108 )
V_95 |= F_37 ( & V_94 -> V_116 , 0 ) ;
if ( V_95 )
return 3 ;
if ( V_94 -> V_102 == V_99 ) {
V_96 = V_94 -> V_110 ;
F_18 ( & V_94 -> V_110 ,
V_94 -> V_117 & V_37 ) ;
if ( V_96 != V_94 -> V_110 )
V_95 ++ ;
}
if ( V_95 )
return 4 ;
if ( V_94 -> V_118 && V_94 -> V_115 > 0 ) {
enum {
V_119 = ( 1 << 0 ) ,
V_120 = ( 1 << 1 )
};
unsigned int V_121 ;
unsigned int V_64 ;
unsigned int V_16 , V_122 ;
unsigned int V_65 , V_123 ;
V_122 = F_27 ( V_94 -> V_118 [ 0 ] ) ;
V_123 = F_28 ( V_94 -> V_118 [ 0 ] ) ;
V_121 = 0 ;
for ( V_64 = 1 ; V_64 < V_94 -> V_115 ; V_64 ++ ) {
V_16 = F_27 ( V_94 -> V_118 [ V_64 ] ) ;
V_65 = F_28 ( V_94 -> V_118 [ V_64 ] ) ;
if ( V_16 < V_122 )
V_121 |= V_119 ;
if ( V_65 != V_123 )
V_121 |= V_120 ;
V_122 = V_16 ;
}
if ( V_121 != 0 ) {
V_95 ++ ;
if ( ( V_121 & V_119 ) != 0 ) {
F_30 ( V_2 -> V_74 ,
L_2 ,
V_75 ) ;
}
if ( ( V_121 & V_120 ) != 0 ) {
F_30 ( V_2 -> V_74 ,
L_3 ,
V_75 ) ;
}
}
}
if ( V_95 )
return 5 ;
return 0 ;
}
static void F_43 ( struct V_1 * V_2 ,
struct V_55 * V_56 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
unsigned long V_27 ;
unsigned char V_124 ;
int V_125 ;
struct V_93 * V_94 ;
F_9 ( & V_6 -> V_126 , V_27 ) ;
V_125 = F_44 ( V_127 , & V_6 -> V_128 ) ;
F_10 ( & V_6 -> V_126 , V_27 ) ;
if ( ! V_125 )
return;
V_94 = & V_56 -> V_129 -> V_94 ;
if ( V_94 -> V_102 == V_99 ) {
F_24 ( V_2 , 1 ) ;
}
if ( V_6 -> V_81 < 2 ) {
V_124 = V_130 ;
} else {
V_124 = V_131 ;
}
F_9 ( & V_6 -> V_132 , V_27 ) ;
V_6 -> V_133 &= ~ V_124 ;
while ( V_6 -> V_134 && V_6 -> V_135 != V_136 ) {
F_10 ( & V_6 -> V_132 , V_27 ) ;
F_9 ( & V_6 -> V_132 , V_27 ) ;
}
if ( V_6 -> V_137 != V_6 -> V_133 ) {
V_6 -> V_137 = V_6 -> V_133 ;
F_21 ( V_6 -> V_137 , V_6 -> V_51 + V_138 ) ;
}
F_10 ( & V_6 -> V_132 , V_27 ) ;
if ( V_6 -> V_81 >= 2 ) {
V_6 -> V_139 &= V_140 ;
F_6 ( V_6 -> V_139 | V_141
| V_142 ,
V_2 -> V_9 + V_92 ) ;
}
F_14 ( V_2 , V_143 ) ;
}
static void F_45 ( struct V_1 * V_2 ,
struct V_55 * V_56 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
unsigned short V_8 ;
int V_24 , V_70 ;
struct V_144 * V_129 = V_56 -> V_129 ;
struct V_93 * V_94 = & V_129 -> V_94 ;
if ( ! V_6 -> V_145 && ( V_6 -> V_146 == 0 ) )
return;
for ( V_24 = 0 ; V_24 < V_94 -> V_115 ; V_24 ++ ) {
V_70 = F_46 ( V_56 -> V_129 , & V_8 ) ;
if ( V_70 == 0 ) {
V_56 -> V_129 -> V_147 |= V_148 ;
F_43 ( V_2 , V_56 ) ;
F_47 ( V_2 , L_4 ) ;
return;
}
F_5 ( V_2 , V_8 , F_27 ( V_94 -> V_118 [ V_24 ] ) ) ;
}
V_129 -> V_147 |= V_149 | V_150 ;
if ( ! V_6 -> V_145 ) {
V_6 -> V_146 -- ;
if ( V_6 -> V_146 == 0 ) {
V_129 -> V_147 |= V_151 ;
F_43 ( V_2 , V_56 ) ;
}
}
}
static int F_48 ( struct V_1 * V_2 ,
struct V_55 * V_56 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_144 * V_129 = V_56 -> V_129 ;
struct V_93 * V_94 = & V_129 -> V_94 ;
unsigned int V_152 ;
unsigned int V_153 ;
unsigned short V_154 ;
unsigned int V_24 , V_64 ;
unsigned int V_155 ;
unsigned int V_147 = 0 ;
int V_156 ;
V_154 = F_3 ( V_2 -> V_9 + V_92 ) ;
V_155 = V_94 -> V_115 * sizeof( short ) ;
V_152 = F_49 ( V_129 ) / V_155 ;
if ( ! V_6 -> V_145 ) {
if ( V_152 > V_6 -> V_146 )
V_152 = V_6 -> V_146 ;
if ( V_6 -> V_146 == 0 ) {
V_147 |= V_151 ;
}
}
if ( V_147 == 0 ) {
if ( ( V_154 & V_157 ) != 0 ) {
F_47 ( V_2 , L_5 ) ;
V_147 |= V_148 | V_158 ;
}
if ( ( V_152 == 0 )
&& ( ( V_154 & V_159 ) == 0 ) ) {
F_47 ( V_2 , L_4 ) ;
V_147 |= V_148 | V_158 ;
}
}
if ( V_147 == 0 ) {
if ( ( V_154 & V_160 ) != 0 )
V_153 = V_161 ;
else if ( ( V_154 & V_159 ) != 0 )
V_153 = V_162 ;
else if ( ( V_154 & V_163 ) != 0 )
V_153 = V_164 ;
else
V_153 = V_165 ;
V_153 /= V_94 -> V_115 ;
if ( V_152 > V_153 )
V_152 = V_153 ;
for ( V_64 = 0 ; V_64 < V_152 ; V_64 ++ ) {
for ( V_24 = 0 ; V_24 < V_94 -> V_115 ; V_24 ++ ) {
unsigned short V_13 ;
F_46 ( V_129 , & V_13 ) ;
F_7 ( V_2 , V_13 ,
F_27 ( V_94 -> V_118 [ V_24 ] ) ) ;
}
}
V_147 |= V_150 | V_149 ;
if ( ! V_6 -> V_145 ) {
V_6 -> V_146 -= V_152 ;
if ( V_6 -> V_146 == 0 ) {
V_6 -> V_139 = ( V_6 -> V_139
&
~ V_166 )
| V_167 ;
F_6 ( V_6 -> V_139 ,
V_2 -> V_9 + V_92 ) ;
}
}
V_154 = F_3 ( V_2 -> V_9 + V_92 ) ;
if ( ( V_154 & V_157 ) != 0 ) {
F_47 ( V_2 , L_5 ) ;
V_147 |= V_148 | V_158 ;
}
}
if ( ( V_147 & ( V_151 | V_158 | V_148 ) )
!= 0 ) {
F_43 ( V_2 , V_56 ) ;
V_156 = 0 ;
} else {
V_156 = 1 ;
}
V_129 -> V_147 |= V_147 ;
return V_156 ;
}
static int F_50 ( struct V_1 * V_2 ,
struct V_55 * V_56 ,
unsigned int V_168 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
unsigned long V_27 ;
if ( V_168 != 0 )
return - V_76 ;
F_9 ( & V_6 -> V_126 , V_27 ) ;
if ( F_51 ( V_127 , & V_6 -> V_128 ) ) {
if ( V_6 -> V_81 < 2 ) {
F_10 ( & V_6 -> V_126 ,
V_27 ) ;
F_45 ( V_2 , V_56 ) ;
F_52 ( V_2 , V_56 ) ;
} else {
F_3 ( V_2 -> V_9 + V_169 ) ;
F_10 ( & V_6 -> V_126 ,
V_27 ) ;
}
F_53 ( 8 ) ;
} else {
F_10 ( & V_6 -> V_126 , V_27 ) ;
}
return 1 ;
}
static void F_54 ( struct V_1 * V_2 ,
struct V_55 * V_56 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_144 * V_129 = V_56 -> V_129 ;
struct V_93 * V_94 = & V_129 -> V_94 ;
unsigned long V_27 ;
F_55 ( V_127 , & V_6 -> V_128 ) ;
if ( ! V_6 -> V_145 && ( V_6 -> V_146 == 0 ) ) {
V_129 -> V_147 |= V_151 ;
F_43 ( V_2 , V_56 ) ;
F_52 ( V_2 , V_56 ) ;
} else {
if ( V_6 -> V_81 >= 2 ) {
unsigned short V_170 ;
int V_171 ;
V_171 = F_48 ( V_2 , V_56 ) ;
F_52 ( V_2 , V_56 ) ;
if ( ! V_171 ) {
return;
}
switch ( V_94 -> V_102 ) {
case V_99 :
V_170 = V_172 ;
break;
case V_101 :
if ( ( V_94 -> V_110 & V_113 ) == 0 ) {
V_170 = V_173 ;
} else {
V_170 = V_174 ;
}
break;
case V_98 :
V_170 = V_175 ;
break;
default:
V_170 = V_176 ;
break;
}
V_6 -> V_139 = ( V_6 -> V_139
& ~ V_177 ) |
V_170 ;
F_6 ( V_6 -> V_139 , V_2 -> V_9 + V_92 ) ;
}
switch ( V_94 -> V_102 ) {
case V_99 :
if ( V_6 -> V_81 < 2 ) {
F_9 ( & V_6 -> V_132 ,
V_27 ) ;
V_6 -> V_133 |= V_130 ;
V_6 -> V_137 |= V_130 ;
F_21 ( V_6 -> V_137 ,
V_6 -> V_51 + V_138 ) ;
F_10 ( & V_6 -> V_132 ,
V_27 ) ;
}
F_21 ( F_56 ( 1 , V_178 ) ,
V_6 -> V_51 + V_179 ) ;
break;
case V_98 :
V_129 -> V_180 = F_50 ;
break;
}
if ( V_6 -> V_81 >= 2 ) {
F_9 ( & V_6 -> V_132 , V_27 ) ;
V_6 -> V_133 |= V_131 ;
V_6 -> V_137 |= V_131 ;
F_21 ( V_6 -> V_137 , V_6 -> V_51 + V_138 ) ;
F_10 ( & V_6 -> V_132 ,
V_27 ) ;
}
}
}
static int F_57 ( struct V_1 * V_2 ,
struct V_55 * V_56 ,
unsigned int V_168 )
{
if ( V_168 != 0 )
return - V_76 ;
V_56 -> V_129 -> V_180 = NULL ;
F_54 ( V_2 , V_56 ) ;
return 1 ;
}
static int F_58 ( struct V_1 * V_2 , struct V_55 * V_56 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
unsigned short V_139 ;
unsigned int V_65 ;
struct V_93 * V_94 = & V_56 -> V_129 -> V_94 ;
if ( V_94 -> V_102 == V_99 ) {
if ( ! F_11 ( V_2 , V_181 , V_143 ) )
return - V_63 ;
}
if ( V_94 -> V_107 == V_106 ) {
V_6 -> V_146 = V_94 -> V_116 ;
V_6 -> V_145 = 0 ;
} else {
V_6 -> V_146 = 0 ;
V_6 -> V_145 = 1 ;
}
V_65 = F_28 ( V_94 -> V_118 [ 0 ] ) ;
V_6 -> V_14 = V_91 [ V_65 ] ;
V_139 = V_6 -> V_14 ? V_182 : V_183 ;
if ( V_6 -> V_81 >= 2 ) {
unsigned short V_184 ;
unsigned int V_24 ;
V_184 = 0 ;
for ( V_24 = 0 ; V_24 < V_94 -> V_115 ; V_24 ++ )
V_184 |= 1 << F_27 ( V_94 -> V_118 [ V_24 ] ) ;
F_6 ( V_184 , V_2 -> V_9 + V_185 ) ;
V_139 |= V_186 | V_141
| V_142
| V_176 | V_187 ;
}
F_6 ( V_139 , V_2 -> V_9 + V_92 ) ;
V_6 -> V_139 = V_139
& ~ ( V_141 | V_142 ) ;
if ( V_94 -> V_102 == V_99 ) {
F_21 ( F_56 ( 1 , V_188 ) ,
V_6 -> V_51 + V_179 ) ;
F_19 ( V_2 , 1 , V_189 ,
V_94 -> V_110 ,
V_94 -> V_117 & V_37 ) ;
}
V_56 -> V_129 -> V_180 = F_57 ;
return 0 ;
}
static int F_59 ( struct V_1 * V_2 ,
struct V_55 * V_56 )
{
F_43 ( V_2 , V_56 ) ;
return 0 ;
}
static int F_60 ( struct V_93 * V_94 )
{
unsigned int V_190 , V_115 ;
int V_95 = 0 ;
V_115 = V_94 -> V_115 ;
if ( V_94 -> V_115 == 0 )
V_115 = 1 ;
V_190 = V_115 * V_94 -> V_191 ;
if ( ( V_190 < V_115 )
|| ( V_190 < V_94 -> V_191 ) ) {
V_190 = V_41 ;
V_95 ++ ;
}
if ( V_94 -> V_110 < V_190 ) {
V_94 -> V_110 = V_190 ;
V_95 ++ ;
}
return ! V_95 ;
}
static int F_61 ( struct V_1 * V_2 ,
struct V_55 * V_56 , struct V_93 * V_94 )
{
const struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = V_2 -> V_7 ;
int V_95 = 0 ;
unsigned int V_96 ;
V_95 |= F_35 ( & V_94 -> V_97 , V_104 | V_98 ) ;
V_96 = V_192 | V_99 | V_98 ;
if ( ( V_4 -> V_193 ) || ( V_4 -> V_100 > 0 ) ) {
V_96 |= V_101 ;
}
V_95 |= F_35 ( & V_94 -> V_102 , V_96 ) ;
V_95 |= F_35 ( & V_94 -> V_103 ,
V_99 | V_98 | V_101 ) ;
V_95 |= F_35 ( & V_94 -> V_105 , V_106 ) ;
V_95 |= F_35 ( & V_94 -> V_107 , V_106 | V_108 ) ;
if ( V_95 )
return 1 ;
V_95 |= F_36 ( V_94 -> V_97 ) ;
V_95 |= F_36 ( V_94 -> V_102 ) ;
V_95 |= F_36 ( V_94 -> V_103 ) ;
V_95 |= F_36 ( V_94 -> V_107 ) ;
if ( ( V_94 -> V_102 != V_192 )
&& ( V_94 -> V_103 != V_99 ) )
V_95 |= - V_76 ;
if ( V_95 )
return 2 ;
V_95 |= F_37 ( & V_94 -> V_109 , 0 ) ;
#define F_62 3200
#define F_63 8000
#define F_64 4000
#define F_65 4294967295u
if ( V_94 -> V_103 == V_99 ) {
unsigned int V_194 ;
if ( V_6 -> V_81 == 0 ) {
if ( V_94 -> V_118 && ( V_94 -> V_115 > 0 ) ) {
if ( F_29 ( V_94 -> V_118 [ 0 ] ) == V_72 )
V_194 = F_63 ;
else
V_194 = F_62 ;
} else {
V_194 = F_62 ;
}
} else {
V_194 = F_64 ;
}
V_95 |= F_40 ( & V_94 -> V_191 ,
V_194 ) ;
V_95 |= F_41 ( & V_94 -> V_191 ,
F_65 ) ;
} else if ( V_94 -> V_103 == V_101 ) {
if ( ( V_94 -> V_191 & V_111 ) != 0 ) {
if ( ( V_94 -> V_191 & ~ V_111 ) != 0 ) {
V_94 -> V_191 = F_42 ( V_94 -> V_191 , 0 ,
~ V_111 ) ;
V_95 |= - V_76 ;
}
if ( ( V_94 -> V_191 & ( V_111 & ~ V_113 ) )
!= V_112 ) {
V_94 -> V_191 = F_42 ( V_94 -> V_109 ,
( V_112 | 0 ) ,
V_111 &
~ V_113 ) ;
V_95 |= - V_76 ;
}
} else {
V_95 |= F_41 ( & V_94 -> V_191 , 1 ) ;
}
} else {
V_95 |= F_37 ( & V_94 -> V_191 , 0 ) ;
}
V_95 |= F_37 ( & V_94 -> V_114 , V_94 -> V_115 ) ;
if ( V_94 -> V_107 == V_108 )
V_95 |= F_37 ( & V_94 -> V_116 , 0 ) ;
if ( V_94 -> V_102 == V_101 ) {
if ( ( V_94 -> V_110 & ~ V_111 ) != 0 ) {
V_94 -> V_110 = F_42 ( V_94 -> V_110 , 0 ,
~ V_111 ) ;
V_95 |= - V_76 ;
}
if ( ( V_94 -> V_110 & V_111 & ~ V_112 ) != 0 ) {
V_94 -> V_110 = F_42 ( V_94 -> V_110 , 0 ,
V_111 & ~ V_112 ) ;
V_95 |= - V_76 ;
}
} else if ( V_94 -> V_102 == V_99 ) {
if ( ! F_60 ( V_94 ) )
V_95 |= - V_76 ;
} else {
V_95 |= F_37 ( & V_94 -> V_110 , 0 ) ;
}
if ( V_95 )
return 3 ;
if ( V_94 -> V_103 == V_99 ) {
V_96 = V_94 -> V_191 ;
F_18 ( & V_94 -> V_191 ,
V_94 -> V_117 & V_37 ) ;
if ( V_96 != V_94 -> V_191 )
V_95 ++ ;
}
if ( V_94 -> V_102 == V_99 ) {
V_96 = V_94 -> V_110 ;
F_18 ( & V_94 -> V_110 ,
V_94 -> V_117 & V_37 ) ;
if ( ! F_60 ( V_94 ) ) {
F_18 ( & V_94 -> V_110 ,
V_40 ) ;
F_60 ( V_94 ) ;
}
if ( V_96 != V_94 -> V_110 )
V_95 ++ ;
}
if ( V_95 )
return 4 ;
if ( V_94 -> V_118 && V_94 -> V_115 > 0 ) {
enum {
V_119 = 1 << 0 ,
V_195 = 1 << 1 ,
V_196 = 1 << 2 ,
V_197 = 1 << 3 ,
V_198 = 1 << 4 ,
V_199 = 1 << 5
};
unsigned int V_121 ;
unsigned int V_16 , V_122 ;
unsigned int V_65 , V_200 ;
unsigned int V_201 , V_202 ;
unsigned int V_66 , V_203 ;
unsigned int V_204 ;
unsigned int V_64 ;
V_204 = 0 ;
V_121 = 0 ;
V_122 = V_203 = V_200 = V_202 = 0 ;
for ( V_64 = 0 ; V_64 < V_94 -> V_115 ; V_64 ++ ) {
V_16 = F_27 ( V_94 -> V_118 [ V_64 ] ) ;
V_65 = F_28 ( V_94 -> V_118 [ V_64 ] ) ;
V_66 = F_29 ( V_94 -> V_118 [ V_64 ] ) ;
V_201 = V_80 [ V_65 ] ;
if ( ( V_66 == V_72 )
&& ( V_16 >= ( V_56 -> V_73 / 2 ) ) ) {
V_121 |= V_198 ;
}
if ( V_64 > 0 ) {
if ( ( V_16 <= V_122 )
&& ( V_204 == 0 ) ) {
V_204 = V_64 ;
}
if ( ( V_204 > 0 )
&& ( V_94 -> V_118 [ V_64 ] !=
V_94 -> V_118 [ V_64 % V_204 ] ) ) {
V_121 |= V_119 ;
}
if ( V_66 != V_203 )
V_121 |= V_197 ;
if ( V_201 != V_202 )
V_121 |= V_196 ;
if ( ( V_66 != V_72 )
&& ( ( ( V_16 ^ V_122 ) & ~ 1 ) == 0 )
&& ( V_65 != V_200 ) ) {
V_121 |= V_195 ;
}
}
V_122 = V_16 ;
V_200 = V_65 ;
V_203 = V_66 ;
V_202 = V_201 ;
}
if ( V_204 == 0 ) {
V_204 = V_64 ;
}
if ( ( V_64 % V_204 ) != 0 )
V_121 |= V_119 ;
if ( ( V_6 -> V_81 > 0 ) && ( V_6 -> V_81 < 4 ) ) {
if ( ( V_204 > 1 )
&& ( F_27 ( V_94 -> V_118 [ 0 ] ) != 0 ) ) {
V_121 |= V_199 ;
}
}
if ( V_121 != 0 ) {
V_95 ++ ;
if ( ( V_121 & V_119 ) != 0 ) {
F_30 ( V_2 -> V_74 ,
L_6 ,
V_75 ) ;
}
if ( ( V_121 & V_195 ) != 0 ) {
F_30 ( V_2 -> V_74 ,
L_7 ,
V_75 ) ;
}
if ( ( V_121 & V_196 ) != 0 ) {
F_30 ( V_2 -> V_74 ,
L_8 ,
V_75 ) ;
}
if ( ( V_121 & V_197 ) != 0 ) {
F_30 ( V_2 -> V_74 ,
L_9 ,
V_75 ) ;
}
if ( ( V_121 & V_198 ) != 0 ) {
F_30 ( V_2 -> V_74 ,
L_1 ,
V_75 , ( V_56 -> V_73 / 2 ) - 1 ) ;
}
if ( ( V_121 & V_199 ) != 0 ) {
F_66 ( V_2 -> V_74 ,
L_10 ,
V_6 -> V_81 ) ;
}
}
}
if ( V_95 )
return 5 ;
return 0 ;
}
static void F_67 ( struct V_1 * V_2 ,
struct V_55 * V_56 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_93 * V_94 = & V_56 -> V_129 -> V_94 ;
unsigned int V_205 = V_94 -> V_114 ;
unsigned int V_206 ;
unsigned short V_207 ;
unsigned short V_68 ;
if ( ( V_94 -> V_117 & V_208 ) != 0 ) {
V_206 = V_205 - V_6 -> V_209 ;
} else {
if ( V_6 -> V_210
|| ( V_6 -> V_211 >= V_212 )
|| ( V_205 >= V_212 ) ) {
V_206 = V_212 ;
} else {
V_206 = ( V_6 -> V_211 * V_205 )
- V_6 -> V_209 ;
}
}
if ( V_206 >= V_212 ) {
V_207 = V_213 ;
} else {
if ( ( V_206 > 1 ) && ( V_6 -> V_81 > 0 ) ) {
if ( V_6 -> V_214 != V_206 ) {
V_6 -> V_214 = V_206 ;
F_6 ( V_206 , V_2 -> V_9 + V_215 ) ;
}
V_207 = V_216 ;
} else {
V_207 = V_217 ;
}
}
V_68 = ( V_6 -> V_68 & ~ V_218 ) | V_207 ;
if ( V_68 != V_6 -> V_68 ) {
V_6 -> V_68 = V_68 ;
F_6 ( V_68 , V_2 -> V_9 + V_61 ) ;
}
}
static int F_68 ( struct V_1 * V_2 ,
struct V_55 * V_56 ,
unsigned int V_168 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
unsigned long V_27 ;
if ( V_168 != 0 )
return - V_76 ;
F_9 ( & V_6 -> V_219 , V_27 ) ;
if ( F_51 ( V_220 , & V_6 -> V_128 ) ) {
unsigned int V_221 ;
F_20 ( V_6 -> V_51 + V_52 , 0 , 2 ,
V_79 ) ;
F_20 ( V_6 -> V_51 + V_52 , 0 , 2 ,
V_54 ) ;
if ( ( ( V_6 -> V_68 & V_222 )
== V_82 )
&& ( V_6 -> V_81 == 0 ) ) {
V_221 = 8 ;
} else {
V_221 = 4 ;
}
F_10 ( & V_6 -> V_219 , V_27 ) ;
F_53 ( V_221 ) ;
} else {
F_10 ( & V_6 -> V_219 , V_27 ) ;
}
return 1 ;
}
static int F_69 ( struct V_1 * V_2 ,
struct V_55 * V_56 ,
unsigned int V_168 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
unsigned long V_27 ;
unsigned char V_223 ;
if ( V_168 != 0 )
return - V_76 ;
F_9 ( & V_6 -> V_219 , V_27 ) ;
if ( F_51 ( V_220 , & V_6 -> V_128 ) ) {
V_223 = F_56 ( 0 , V_188 ) ;
F_21 ( V_223 , V_6 -> V_51 + V_179 ) ;
V_223 = F_56 ( 0 , V_178 ) ;
F_21 ( V_223 , V_6 -> V_51 + V_179 ) ;
}
F_10 ( & V_6 -> V_219 , V_27 ) ;
return 1 ;
}
static void F_70 ( struct V_1 * V_2 ,
struct V_55 * V_56 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
unsigned long V_27 ;
struct V_93 * V_94 ;
int V_125 ;
F_9 ( & V_6 -> V_219 , V_27 ) ;
V_125 = F_44 ( V_220 , & V_6 -> V_128 ) ;
F_10 ( & V_6 -> V_219 , V_27 ) ;
if ( ! V_125 )
return;
V_94 = & V_56 -> V_129 -> V_94 ;
if ( V_94 -> V_103 == V_99 ) {
F_24 ( V_2 , 2 ) ;
}
if ( V_94 -> V_102 != V_192 ) {
F_24 ( V_2 , 0 ) ;
}
F_9 ( & V_6 -> V_132 , V_27 ) ;
V_6 -> V_133 &= ~ V_224 ;
while ( V_6 -> V_134 && V_6 -> V_135 != V_136 ) {
F_10 ( & V_6 -> V_132 , V_27 ) ;
F_9 ( & V_6 -> V_132 , V_27 ) ;
}
if ( V_6 -> V_137 != V_6 -> V_133 ) {
V_6 -> V_137 = V_6 -> V_133 ;
F_21 ( V_6 -> V_137 , V_6 -> V_51 + V_138 ) ;
}
F_10 ( & V_6 -> V_132 , V_27 ) ;
V_6 -> V_68 = ( V_6 -> V_68 & ( V_225
| V_222 ) ) |
V_226 ;
F_6 ( V_6 -> V_68 | V_90 ,
V_2 -> V_9 + V_61 ) ;
F_14 ( V_2 , V_227 ) ;
}
static void F_71 ( struct V_1 * V_2 ,
struct V_55 * V_56 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
unsigned long V_27 ;
unsigned short V_228 ;
struct V_144 * V_129 = V_56 -> V_129 ;
struct V_93 * V_94 = & V_129 -> V_94 ;
F_55 ( V_220 , & V_6 -> V_128 ) ;
if ( ! V_6 -> V_210 && ( V_6 -> V_211 == 0 ) ) {
V_129 -> V_147 |= V_151 ;
F_70 ( V_2 , V_56 ) ;
F_52 ( V_2 , V_56 ) ;
} else {
F_9 ( & V_6 -> V_132 , V_27 ) ;
V_6 -> V_133 |= V_224 ;
V_6 -> V_137 |= V_224 ;
F_21 ( V_6 -> V_137 , V_6 -> V_51 + V_138 ) ;
F_10 ( & V_6 -> V_132 , V_27 ) ;
switch ( V_94 -> V_103 ) {
default:
V_228 = V_226 ;
break;
case V_99 :
V_228 = V_77 ;
break;
case V_101 :
if ( ( V_94 -> V_191 & V_112 ) != 0 ) {
if ( ( V_94 -> V_191 & V_113 ) == 0 ) {
V_228 = V_229 ;
} else {
V_228 = V_230 ;
}
} else {
if ( V_94 -> V_191 != 0 ) {
V_228 = V_229 ;
} else {
V_228 = V_230 ;
}
}
break;
case V_98 :
V_228 = V_77 ;
break;
}
V_6 -> V_68 = ( V_6 -> V_68 & ~ V_231 )
| V_228 ;
F_6 ( V_6 -> V_68 , V_2 -> V_9 + V_61 ) ;
if ( V_94 -> V_103 == V_98 )
V_129 -> V_180 = F_68 ;
F_67 ( V_2 , V_56 ) ;
if ( V_94 -> V_103 == V_99 ) {
unsigned char V_223 ;
if ( V_94 -> V_102 != V_192 ) {
V_223 = F_56 ( 2 , V_232 ) ;
} else {
V_223 = F_56 ( 2 , V_178 ) ;
}
F_21 ( V_223 , V_6 -> V_51 + V_179 ) ;
if ( V_94 -> V_102 != V_192 ) {
switch ( V_94 -> V_102 ) {
default:
V_223 = F_56 ( 0 , V_178 ) ;
break;
case V_101 :
V_223 = F_56 ( 0 , V_233 ) ;
break;
case V_99 :
V_223 = F_56 ( 0 , V_232 ) ;
break;
case V_98 :
V_223 = F_56 ( 0 , V_178 ) ;
break;
}
F_21 ( V_223 , V_6 -> V_51 + V_179 ) ;
switch ( V_94 -> V_102 ) {
case V_99 :
V_223 = F_56 ( 1 , V_178 ) ;
F_21 ( V_223 , V_6 -> V_51
+ V_179 ) ;
break;
case V_98 :
V_129 -> V_180 =
F_69 ;
break;
}
}
} else if ( V_94 -> V_103 != V_98 ) {
F_13 ( V_2 , V_234 , V_227 ) ;
}
}
}
static int F_72 ( struct V_1 * V_2 ,
struct V_55 * V_56 ,
unsigned int V_168 )
{
if ( V_168 != 0 )
return - V_76 ;
V_56 -> V_129 -> V_180 = NULL ;
F_71 ( V_2 , V_56 ) ;
return 1 ;
}
static void F_73 ( struct V_1 * V_2 ,
struct V_55 * V_56 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
unsigned int V_147 = 0 ;
unsigned int V_235 ;
unsigned int V_24 ;
unsigned int V_236 ;
unsigned int V_237 ;
struct V_144 * V_129 = V_56 -> V_129 ;
unsigned int V_205 = V_129 -> V_94 . V_114 ;
if ( V_6 -> V_210 ) {
V_236 = V_212 ;
} else if ( V_6 -> V_211 == 0 ) {
V_236 = 0 ;
} else if ( ( V_6 -> V_211 > V_212 )
|| ( V_205 > V_212 ) ) {
V_236 = V_212 ;
} else {
V_236 = ( V_6 -> V_211 * V_205 )
- V_6 -> V_209 ;
if ( V_236 > V_212 )
V_236 = V_212 ;
}
if ( V_236 == 0 )
return;
V_237 = 0 ;
for ( V_24 = 0 ; V_24 < V_236 ; V_24 ++ ) {
if ( V_237 == 0 ) {
V_235 = F_3 ( V_2 -> V_9 + V_61 ) ;
if ( ( V_235 & V_238 ) != 0 ) {
F_47 ( V_2 , L_11 ) ;
V_147 |= V_148 | V_158 ;
break;
} else if ( ( V_235 & V_62 ) != 0 ) {
break;
} else if ( ( V_235 & V_239 ) != 0 ) {
V_237 = V_212 ;
} else {
if ( V_6 -> V_81 > 0 ) {
V_237 = F_3 ( V_2 -> V_9
+ V_240 ) ;
if ( V_237 == 0 ) {
break;
}
} else {
V_237 = 1 ;
}
}
}
if ( F_74 ( V_129 , F_1 ( V_2 ) ) == 0 ) {
V_147 |= V_158 | V_148 ;
F_47 ( V_2 , L_12 ) ;
break;
}
V_237 -- ;
V_6 -> V_209 ++ ;
if ( V_6 -> V_209 == V_205 ) {
V_6 -> V_209 = 0 ;
V_6 -> V_211 -- ;
V_129 -> V_147 |= V_150 ;
}
}
if ( ! V_6 -> V_210 && ( V_6 -> V_211 == 0 ) ) {
V_147 |= V_151 ;
} else {
V_147 |= V_149 ;
}
V_129 -> V_147 |= V_147 ;
if ( ( V_129 -> V_147 & ( V_151 | V_158 |
V_148 ) ) != 0 ) {
F_70 ( V_2 , V_56 ) ;
} else {
F_67 ( V_2 , V_56 ) ;
}
}
static int F_75 ( struct V_1 * V_2 , struct V_55 * V_56 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
unsigned int V_24 , V_16 , V_65 , V_241 ;
unsigned int V_21 ;
unsigned short V_68 , V_69 ;
unsigned char V_223 ;
struct V_144 * V_129 = V_56 -> V_129 ;
struct V_93 * V_94 = & V_129 -> V_94 ;
V_21 = 0 ;
V_21 |= ( 1U << V_234 ) ;
if ( V_94 -> V_102 != V_192 ) {
V_21 |= ( 1U << V_242 ) ;
if ( V_94 -> V_102 == V_99 ) {
V_21 |= ( 1U << V_181 ) ;
}
}
if ( ! F_8 ( V_2 , V_21 , V_227 ) )
return - V_63 ;
if ( V_94 -> V_107 == V_106 ) {
V_6 -> V_211 = V_94 -> V_116 ;
V_6 -> V_210 = 0 ;
} else {
V_6 -> V_211 = 0 ;
V_6 -> V_210 = 1 ;
}
V_6 -> V_209 = 0 ;
V_68 = V_78 ;
V_69 = 0 ;
if ( F_29 ( V_94 -> V_118 [ 0 ] ) == V_72 ) {
V_241 = 1 ;
V_68 |= V_82 ;
} else {
V_241 = 0 ;
V_68 |= V_83 ;
}
V_65 = F_28 ( V_94 -> V_118 [ 0 ] ) ;
V_6 -> V_12 = V_80 [ V_65 ] ;
if ( V_6 -> V_12 )
V_68 |= V_86 ;
else
V_68 |= V_87 ;
for ( V_24 = 0 ; V_24 < V_94 -> V_115 ; V_24 ++ ) {
unsigned int V_67 ;
V_16 = F_27 ( V_94 -> V_118 [ V_24 ] ) ;
V_65 = F_28 ( V_94 -> V_118 [ V_24 ] ) ;
if ( V_241 ) {
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
V_68 |= V_243 | V_77 ;
V_6 -> V_68 = V_68 ;
F_6 ( V_68 | V_90 , V_2 -> V_9 + V_61 ) ;
F_53 ( 25 ) ;
F_6 ( V_68 | V_90 , V_2 -> V_9 + V_61 ) ;
if ( V_94 -> V_103 == V_99 ) {
V_223 = F_56 ( 2 , V_188 ) ;
F_21 ( V_223 , V_6 -> V_51 + V_179 ) ;
F_19 ( V_2 , 2 , V_189 , V_94 -> V_191 ,
V_94 -> V_117 & V_37 ) ;
if ( V_94 -> V_102 != V_192 ) {
V_223 = F_56 ( 0 , V_178 ) ;
F_21 ( V_223 , V_6 -> V_51 + V_179 ) ;
F_19 ( V_2 , 0 , V_54 ,
( ( T_1 ) V_94 -> V_191
* V_94 -> V_114 ) ,
V_40 ) ;
if ( V_94 -> V_102 == V_99 ) {
V_223 = F_56 ( 1 , V_188 ) ;
F_21 ( V_223 , V_6 -> V_51 + V_179 ) ;
F_19 ( V_2 , 1 , V_189 ,
V_94 -> V_110 ,
V_94 ->
V_117 &
V_37 ) ;
}
}
}
if ( V_94 -> V_97 == V_98 ) {
V_56 -> V_129 -> V_180 = F_72 ;
} else {
F_71 ( V_2 , V_56 ) ;
}
return 0 ;
}
static int F_76 ( struct V_1 * V_2 ,
struct V_55 * V_56 )
{
F_70 ( V_2 , V_56 ) ;
return 0 ;
}
static T_2 F_77 ( int V_244 , void * V_245 )
{
unsigned char V_246 , V_247 ;
struct V_1 * V_2 = (struct V_1 * ) V_245 ;
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_55 * V_56 ;
unsigned long V_27 ;
V_246 = F_78 ( V_6 -> V_51 + V_248 ) ;
if ( V_246 == V_249 )
return V_250 ;
F_9 ( & V_6 -> V_132 , V_27 ) ;
V_247 = V_6 -> V_133 & V_246 ;
V_6 -> V_137 = V_6 -> V_133 & ~ V_246 ;
F_21 ( V_6 -> V_137 , V_6 -> V_51 + V_138 ) ;
V_6 -> V_134 = 1 ;
V_6 -> V_135 = V_136 ;
F_10 ( & V_6 -> V_132 , V_27 ) ;
if ( ( V_247 & V_130 ) != 0 ) {
V_56 = V_2 -> V_251 ;
F_45 ( V_2 , V_56 ) ;
F_52 ( V_2 , V_56 ) ;
}
if ( ( V_247 & V_131 ) != 0 ) {
V_56 = V_2 -> V_251 ;
F_48 ( V_2 , V_56 ) ;
F_52 ( V_2 , V_56 ) ;
}
if ( ( V_247 & V_224 ) != 0 ) {
V_56 = V_2 -> V_252 ;
F_73 ( V_2 , V_56 ) ;
F_52 ( V_2 , V_56 ) ;
}
F_9 ( & V_6 -> V_132 , V_27 ) ;
if ( V_6 -> V_137 != V_6 -> V_133 ) {
V_6 -> V_137 = V_6 -> V_133 ;
F_21 ( V_6 -> V_137 , V_6 -> V_51 + V_138 ) ;
}
V_6 -> V_134 = 0 ;
F_10 ( & V_6 -> V_132 , V_27 ) ;
return V_253 ;
}
static bool F_79 ( const struct V_3 * V_254 ,
struct V_255 * V_255 )
{
if ( V_254 -> V_256 != V_255 -> V_257 )
return false ;
if ( V_254 -> V_100 == 0 )
return true ;
if ( F_80 ( V_255 , 3 ) < 32 )
return false ;
return true ;
}
static const struct V_3 * F_81 ( struct V_255 * V_255 )
{
unsigned int V_24 ;
for ( V_24 = 0 ; V_24 < F_82 ( V_258 ) ; V_24 ++ )
if ( F_79 ( & V_258 [ V_24 ] , V_255 ) )
return & V_258 [ V_24 ] ;
return NULL ;
}
static struct V_255 * F_83 ( struct V_1 * V_2 ,
struct V_259 * V_260 )
{
const struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_255 * V_255 = NULL ;
int V_261 = V_260 -> V_262 [ 0 ] ;
int V_263 = V_260 -> V_262 [ 1 ] ;
F_84 (pci_dev) {
if ( V_255 -> V_264 != V_265 )
continue;
if ( ( V_261 || V_263 ) &&
( V_261 != V_255 -> V_261 -> V_266 ||
V_263 != F_85 ( V_255 -> V_267 ) ) )
continue;
if ( V_4 -> V_256 == V_268 ) {
const struct V_3 * V_269 ;
V_269 = F_81 ( V_255 ) ;
if ( V_269 == NULL )
continue;
V_2 -> V_270 = V_269 ;
} else {
if ( ! F_79 ( V_4 , V_255 ) )
continue;
}
return V_255 ;
}
F_86 ( V_2 -> V_74 ,
L_13 ,
V_261 , V_263 ) ;
return NULL ;
}
static int F_87 ( struct V_1 * V_2 )
{
struct V_5 * V_6 ;
V_6 = F_88 ( V_2 , sizeof( * V_6 ) ) ;
if ( ! V_6 )
return - V_271 ;
F_89 ( & V_6 -> V_132 ) ;
F_89 ( & V_6 -> V_28 ) ;
F_89 ( & V_6 -> V_219 ) ;
F_89 ( & V_6 -> V_126 ) ;
return 0 ;
}
static int F_90 ( struct V_1 * V_2 ,
struct V_255 * V_255 )
{
const struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_55 * V_56 ;
unsigned long V_51 , V_272 ;
int V_273 ;
F_91 ( V_2 , & V_255 -> V_2 ) ;
V_2 -> V_274 = V_4 -> V_275 ;
V_273 = F_92 ( V_2 ) ;
if ( V_273 )
return V_273 ;
V_51 = F_93 ( V_255 , 2 ) ;
V_272 = F_93 ( V_255 , 3 ) ;
F_30 ( V_2 -> V_74 ,
L_14 ,
V_2 -> V_274 , V_51 , V_272 ) ;
V_6 -> V_51 = V_51 ;
V_2 -> V_9 = V_272 ;
V_6 -> V_139 = F_3 ( V_2 -> V_9 + V_92 ) & V_140 ;
if ( F_80 ( V_255 , 3 ) >= 32 ) {
unsigned short V_276 = 0 ;
V_6 -> V_81 = F_3 ( V_2 -> V_9 + V_277 ) ;
if ( V_6 -> V_81 < V_4 -> V_100 ) {
F_86 ( V_2 -> V_74 ,
L_15 ,
V_2 -> V_274 , V_6 -> V_81 ,
V_4 -> V_100 ) ;
return - V_278 ;
}
if ( V_6 -> V_81 > 0 ) {
if ( ! V_4 -> V_193 ) {
V_276 |= V_279 ;
}
if ( ( V_4 -> V_280 > 0 )
&& ( V_6 -> V_81 >= 2 ) ) {
V_276 |= V_281 ;
}
}
F_6 ( V_276 , V_2 -> V_9 + V_282 ) ;
if ( ( V_276 & V_281 ) != 0 ) {
F_6 ( V_6 -> V_139 | V_186
| V_141 ,
V_2 -> V_9 + V_92 ) ;
F_6 ( 0 , V_2 -> V_9 + V_185 ) ;
F_6 ( V_6 -> V_139 , V_2 -> V_9 + V_92 ) ;
}
}
F_21 ( 0 , V_6 -> V_51 + V_138 ) ;
V_6 -> V_84 = 0 ;
V_6 -> V_68 = V_226 | V_83
| V_86 ;
F_6 ( 1 << 0 , V_2 -> V_9 + V_88 ) ;
F_6 ( V_6 -> V_84 , V_2 -> V_9 + V_89 ) ;
F_6 ( V_6 -> V_68 | V_90 ,
V_2 -> V_9 + V_61 ) ;
if ( V_255 -> V_244 ) {
V_273 = F_94 ( V_255 -> V_244 , F_77 , V_283 ,
V_2 -> V_274 , V_2 ) ;
if ( V_273 == 0 )
V_2 -> V_244 = V_255 -> V_244 ;
}
V_273 = F_95 ( V_2 , 3 ) ;
if ( V_273 )
return V_273 ;
V_56 = & V_2 -> V_284 [ 0 ] ;
V_56 -> type = V_285 ;
V_56 -> V_286 = V_287 | V_288 | V_289 ;
V_56 -> V_73 = V_4 -> V_290 ;
V_56 -> V_291 = ( 1 << V_4 -> V_11 ) - 1 ;
V_56 -> V_292 = & V_293 ;
V_56 -> V_294 = & F_26 ;
V_56 -> V_295 = 256 ;
if ( V_2 -> V_244 ) {
V_2 -> V_252 = V_56 ;
V_56 -> V_286 |= V_296 ;
V_56 -> V_297 = & F_75 ;
V_56 -> V_298 = & F_61 ;
V_56 -> V_299 = F_76 ;
}
V_56 = & V_2 -> V_284 [ 1 ] ;
if ( V_4 -> V_280 > 0 ) {
V_56 -> type = V_300 ;
V_56 -> V_286 = V_301 | V_289 ;
V_56 -> V_73 = V_4 -> V_280 ;
V_56 -> V_291 = ( 1 << V_4 -> V_15 ) - 1 ;
V_56 -> V_292 = & V_302 ;
V_56 -> V_303 = & F_32 ;
V_56 -> V_294 = & F_33 ;
V_56 -> V_295 = V_4 -> V_280 ;
if ( V_2 -> V_244 ) {
V_2 -> V_251 = V_56 ;
V_56 -> V_286 |= V_304 ;
V_56 -> V_297 = & F_58 ;
V_56 -> V_298 = & F_34 ;
V_56 -> V_299 = F_59 ;
}
} else {
V_56 -> type = V_305 ;
}
V_56 = & V_2 -> V_284 [ 2 ] ;
if ( V_4 -> V_193 ) {
V_273 = F_96 ( V_2 , V_56 , NULL ,
V_6 -> V_51 + V_306 ) ;
if ( V_273 )
return V_273 ;
} else {
V_56 -> type = V_305 ;
}
return 0 ;
}
static int F_97 ( struct V_1 * V_2 , struct V_259 * V_260 )
{
const struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_255 * V_255 ;
int V_273 ;
F_66 ( V_2 -> V_74 , L_16 ,
V_4 -> V_275 , V_260 -> V_262 [ 0 ] , V_260 -> V_262 [ 1 ] ) ;
V_273 = F_87 ( V_2 ) ;
if ( V_273 )
return V_273 ;
V_255 = F_83 ( V_2 , V_260 ) ;
if ( ! V_255 )
return - V_278 ;
return F_90 ( V_2 , V_255 ) ;
}
static int F_98 ( struct V_1 * V_2 ,
unsigned long V_307 )
{
struct V_255 * V_255 = F_99 ( V_2 ) ;
int V_273 ;
F_66 ( V_2 -> V_74 , L_17 ,
F_100 ( V_255 ) ) ;
V_273 = F_87 ( V_2 ) ;
if ( V_273 )
return V_273 ;
V_2 -> V_270 = F_81 ( V_255 ) ;
if ( V_2 -> V_270 == NULL ) {
F_86 ( V_2 -> V_74 ,
L_18 ) ;
return - V_76 ;
}
F_101 ( V_255 ) ;
return F_90 ( V_2 , V_255 ) ;
}
static void F_102 ( struct V_1 * V_2 )
{
struct V_255 * V_308 = F_99 ( V_2 ) ;
if ( V_2 -> V_244 )
F_103 ( V_2 -> V_244 , V_2 ) ;
F_104 ( V_2 ) ;
if ( V_308 )
F_105 ( V_308 ) ;
}
static int F_106 ( struct V_255 * V_2 ,
const struct V_309 * V_256 )
{
return F_107 ( V_2 , & V_310 ,
V_256 -> V_311 ) ;
}
