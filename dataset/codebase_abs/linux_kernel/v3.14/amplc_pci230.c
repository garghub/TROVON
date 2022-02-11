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
struct V_55 * V_56 , struct V_57 * V_58 ,
unsigned int * V_8 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
unsigned int V_59 , V_24 ;
unsigned int V_16 , V_60 , V_61 ;
unsigned int V_62 ;
unsigned int V_63 ;
unsigned short V_64 , V_65 ;
V_16 = F_26 ( V_58 -> V_66 ) ;
V_60 = F_27 ( V_58 -> V_66 ) ;
V_61 = F_28 ( V_58 -> V_66 ) ;
if ( V_61 == V_67 ) {
if ( V_16 >= V_56 -> V_68 / 2 ) {
F_29 ( V_2 -> V_69 ,
L_1 ,
V_70 , ( V_56 -> V_68 / 2 ) - 1 ) ;
return - V_71 ;
}
}
V_64 = V_72 | V_73 ;
F_20 ( V_6 -> V_51 + V_52 , 0 , 2 , V_74 ) ;
V_6 -> V_12 = V_75 [ V_60 ] ;
if ( V_61 == V_67 ) {
V_62 = V_16 * 2 ;
if ( V_6 -> V_76 == 0 ) {
V_65 = 3 << V_62 ;
} else {
V_65 = 1 << V_62 ;
}
V_64 |= V_77 ;
} else {
V_65 = 1 << V_16 ;
V_62 = V_16 & ~ 1 ;
V_64 |= V_78 ;
}
V_6 -> V_79 = ( V_6 -> V_79 & ~ ( 3 << V_62 ) )
| ( V_80 [ V_60 ] << V_62 ) ;
if ( V_6 -> V_12 )
V_64 |= V_81 ;
else
V_64 |= V_82 ;
F_6 ( V_65 , V_2 -> V_9 + V_83 ) ;
F_6 ( V_6 -> V_79 , V_2 -> V_9 + V_84 ) ;
V_6 -> V_64 = V_64 ;
F_6 ( V_64 | V_85 , V_2 -> V_9 + V_86 ) ;
for ( V_59 = 0 ; V_59 < V_58 -> V_59 ; V_59 ++ ) {
F_20 ( V_6 -> V_51 + V_52 , 0 , 2 ,
V_74 ) ;
F_20 ( V_6 -> V_51 + V_52 , 0 , 2 ,
V_54 ) ;
#define F_30 100
for ( V_24 = 0 ; V_24 < F_30 ; V_24 ++ ) {
V_63 = F_3 ( V_2 -> V_9 + V_86 ) ;
if ( ! ( V_63 & V_87 ) )
break;
F_31 ( 1 ) ;
}
if ( V_24 == F_30 ) {
F_32 ( V_2 -> V_69 , L_2 ) ;
return - V_88 ;
}
V_8 [ V_59 ] = F_1 ( V_2 ) ;
}
return V_59 ;
}
static int F_33 ( struct V_1 * V_2 ,
struct V_55 * V_56 , struct V_57 * V_58 ,
unsigned int * V_8 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
int V_24 ;
int V_16 , V_60 ;
V_16 = F_26 ( V_58 -> V_66 ) ;
V_60 = F_27 ( V_58 -> V_66 ) ;
V_6 -> V_14 = V_89 [ V_60 ] ;
F_6 ( V_60 , V_2 -> V_9 + V_90 ) ;
for ( V_24 = 0 ; V_24 < V_58 -> V_59 ; V_24 ++ ) {
F_5 ( V_2 , V_8 [ V_24 ] , V_16 ) ;
}
return V_24 ;
}
static int F_34 ( struct V_1 * V_2 ,
struct V_55 * V_56 , struct V_57 * V_58 ,
unsigned int * V_8 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
int V_24 ;
int V_16 = F_26 ( V_58 -> V_66 ) ;
for ( V_24 = 0 ; V_24 < V_58 -> V_59 ; V_24 ++ )
V_8 [ V_24 ] = V_6 -> V_17 [ V_16 ] ;
return V_24 ;
}
static int F_35 ( struct V_1 * V_2 ,
struct V_55 * V_56 , struct V_91 * V_92 )
{
const struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = V_2 -> V_7 ;
int V_93 = 0 ;
unsigned int V_94 ;
V_93 |= F_36 ( & V_92 -> V_95 , V_96 ) ;
V_94 = V_97 | V_96 ;
if ( ( V_4 -> V_98 > 0 ) && ( V_6 -> V_76 >= 2 ) ) {
V_94 |= V_99 ;
}
V_93 |= F_36 ( & V_92 -> V_100 , V_94 ) ;
V_93 |= F_36 ( & V_92 -> V_101 , V_102 ) ;
V_93 |= F_36 ( & V_92 -> V_103 , V_104 ) ;
V_93 |= F_36 ( & V_92 -> V_105 , V_104 | V_106 ) ;
if ( V_93 )
return 1 ;
V_93 |= F_37 ( V_92 -> V_100 ) ;
V_93 |= F_37 ( V_92 -> V_105 ) ;
if ( V_93 )
return 2 ;
V_93 |= F_38 ( & V_92 -> V_107 , 0 ) ;
#define F_39 8000
#define F_40 4294967295u
switch ( V_92 -> V_100 ) {
case V_97 :
V_93 |= F_41 ( & V_92 -> V_108 ,
F_39 ) ;
V_93 |= F_42 ( & V_92 -> V_108 ,
F_40 ) ;
break;
case V_99 :
if ( ( V_92 -> V_108 & ~ V_109 ) != 0 ) {
V_92 -> V_108 = F_43 ( V_92 -> V_108 , 0 ,
~ V_109 ) ;
V_93 |= - V_71 ;
}
if ( ( V_92 -> V_108
& ( V_109 & ~ ( V_110 | V_111 ) ) ) != 0 ) {
V_92 -> V_108 = F_43 ( V_92 -> V_108 , 0 ,
V_109 &
~ ( V_110 | V_111 ) ) ;
V_93 |= - V_71 ;
}
break;
default:
V_93 |= F_38 ( & V_92 -> V_108 , 0 ) ;
break;
}
V_93 |= F_38 ( & V_92 -> V_112 , V_92 -> V_113 ) ;
if ( V_92 -> V_105 == V_106 )
V_93 |= F_38 ( & V_92 -> V_114 , 0 ) ;
if ( V_93 )
return 3 ;
if ( V_92 -> V_100 == V_97 ) {
V_94 = V_92 -> V_108 ;
F_18 ( & V_92 -> V_108 ,
V_92 -> V_115 & V_37 ) ;
if ( V_94 != V_92 -> V_108 )
V_93 ++ ;
}
if ( V_93 )
return 4 ;
if ( V_92 -> V_116 && V_92 -> V_113 > 0 ) {
enum {
V_117 = ( 1 << 0 ) ,
V_118 = ( 1 << 1 )
};
unsigned int V_119 ;
unsigned int V_59 ;
unsigned int V_16 , V_120 ;
unsigned int V_60 , V_121 ;
V_120 = F_26 ( V_92 -> V_116 [ 0 ] ) ;
V_121 = F_27 ( V_92 -> V_116 [ 0 ] ) ;
V_119 = 0 ;
for ( V_59 = 1 ; V_59 < V_92 -> V_113 ; V_59 ++ ) {
V_16 = F_26 ( V_92 -> V_116 [ V_59 ] ) ;
V_60 = F_27 ( V_92 -> V_116 [ V_59 ] ) ;
if ( V_16 < V_120 )
V_119 |= V_117 ;
if ( V_60 != V_121 )
V_119 |= V_118 ;
V_120 = V_16 ;
}
if ( V_119 != 0 ) {
V_93 ++ ;
if ( ( V_119 & V_117 ) != 0 ) {
F_29 ( V_2 -> V_69 ,
L_3 ,
V_70 ) ;
}
if ( ( V_119 & V_118 ) != 0 ) {
F_29 ( V_2 -> V_69 ,
L_4 ,
V_70 ) ;
}
}
}
if ( V_93 )
return 5 ;
return 0 ;
}
static void F_44 ( struct V_1 * V_2 ,
struct V_55 * V_56 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
unsigned long V_27 ;
unsigned char V_122 ;
int V_123 ;
struct V_91 * V_92 ;
F_9 ( & V_6 -> V_124 , V_27 ) ;
V_123 = F_45 ( V_125 , & V_6 -> V_126 ) ;
F_10 ( & V_6 -> V_124 , V_27 ) ;
if ( ! V_123 )
return;
V_92 = & V_56 -> V_127 -> V_92 ;
if ( V_92 -> V_100 == V_97 ) {
F_24 ( V_2 , 1 ) ;
}
if ( V_6 -> V_76 < 2 ) {
V_122 = V_128 ;
} else {
V_122 = V_129 ;
}
F_9 ( & V_6 -> V_130 , V_27 ) ;
V_6 -> V_131 &= ~ V_122 ;
while ( V_6 -> V_132 && V_6 -> V_133 != V_134 ) {
F_10 ( & V_6 -> V_130 , V_27 ) ;
F_9 ( & V_6 -> V_130 , V_27 ) ;
}
if ( V_6 -> V_135 != V_6 -> V_131 ) {
V_6 -> V_135 = V_6 -> V_131 ;
F_21 ( V_6 -> V_135 , V_6 -> V_51 + V_136 ) ;
}
F_10 ( & V_6 -> V_130 , V_27 ) ;
if ( V_6 -> V_76 >= 2 ) {
V_6 -> V_137 &= V_138 ;
F_6 ( V_6 -> V_137 | V_139
| V_140 ,
V_2 -> V_9 + V_90 ) ;
}
F_14 ( V_2 , V_141 ) ;
}
static void F_46 ( struct V_1 * V_2 ,
struct V_55 * V_56 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
unsigned short V_8 ;
int V_24 , V_142 ;
struct V_143 * V_127 = V_56 -> V_127 ;
struct V_91 * V_92 = & V_127 -> V_92 ;
if ( ! V_6 -> V_144 && ( V_6 -> V_145 == 0 ) )
return;
for ( V_24 = 0 ; V_24 < V_92 -> V_113 ; V_24 ++ ) {
V_142 = F_47 ( V_56 -> V_127 , & V_8 ) ;
if ( V_142 == 0 ) {
V_56 -> V_127 -> V_146 |= V_147 ;
F_44 ( V_2 , V_56 ) ;
F_48 ( V_2 , L_5 ) ;
return;
}
F_5 ( V_2 , V_8 , F_26 ( V_92 -> V_116 [ V_24 ] ) ) ;
}
V_127 -> V_146 |= V_148 | V_149 ;
if ( ! V_6 -> V_144 ) {
V_6 -> V_145 -- ;
if ( V_6 -> V_145 == 0 ) {
V_127 -> V_146 |= V_150 ;
F_44 ( V_2 , V_56 ) ;
}
}
}
static int F_49 ( struct V_1 * V_2 ,
struct V_55 * V_56 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_143 * V_127 = V_56 -> V_127 ;
struct V_91 * V_92 = & V_127 -> V_92 ;
unsigned int V_151 ;
unsigned int V_152 ;
unsigned short V_153 ;
unsigned int V_24 , V_59 ;
unsigned int V_154 ;
unsigned int V_146 = 0 ;
int V_155 ;
V_153 = F_3 ( V_2 -> V_9 + V_90 ) ;
V_154 = V_92 -> V_113 * sizeof( short ) ;
V_151 = F_50 ( V_127 ) / V_154 ;
if ( ! V_6 -> V_144 ) {
if ( V_151 > V_6 -> V_145 )
V_151 = V_6 -> V_145 ;
if ( V_6 -> V_145 == 0 ) {
V_146 |= V_150 ;
}
}
if ( V_146 == 0 ) {
if ( ( V_153 & V_156 ) != 0 ) {
F_48 ( V_2 , L_6 ) ;
V_146 |= V_147 | V_157 ;
}
if ( ( V_151 == 0 )
&& ( ( V_153 & V_158 ) == 0 ) ) {
F_48 ( V_2 , L_5 ) ;
V_146 |= V_147 | V_157 ;
}
}
if ( V_146 == 0 ) {
if ( ( V_153 & V_159 ) != 0 )
V_152 = V_160 ;
else if ( ( V_153 & V_158 ) != 0 )
V_152 = V_161 ;
else if ( ( V_153 & V_162 ) != 0 )
V_152 = V_163 ;
else
V_152 = V_164 ;
V_152 /= V_92 -> V_113 ;
if ( V_151 > V_152 )
V_151 = V_152 ;
for ( V_59 = 0 ; V_59 < V_151 ; V_59 ++ ) {
for ( V_24 = 0 ; V_24 < V_92 -> V_113 ; V_24 ++ ) {
unsigned short V_13 ;
F_47 ( V_127 , & V_13 ) ;
F_7 ( V_2 , V_13 ,
F_26 ( V_92 -> V_116 [ V_24 ] ) ) ;
}
}
V_146 |= V_149 | V_148 ;
if ( ! V_6 -> V_144 ) {
V_6 -> V_145 -= V_151 ;
if ( V_6 -> V_145 == 0 ) {
V_6 -> V_137 = ( V_6 -> V_137
&
~ V_165 )
| V_166 ;
F_6 ( V_6 -> V_137 ,
V_2 -> V_9 + V_90 ) ;
}
}
V_153 = F_3 ( V_2 -> V_9 + V_90 ) ;
if ( ( V_153 & V_156 ) != 0 ) {
F_48 ( V_2 , L_6 ) ;
V_146 |= V_147 | V_157 ;
}
}
if ( ( V_146 & ( V_150 | V_157 | V_147 ) )
!= 0 ) {
F_44 ( V_2 , V_56 ) ;
V_155 = 0 ;
} else {
V_155 = 1 ;
}
V_127 -> V_146 |= V_146 ;
return V_155 ;
}
static int F_51 ( struct V_1 * V_2 ,
struct V_55 * V_56 ,
unsigned int V_167 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
unsigned long V_27 ;
if ( V_167 != 0 )
return - V_71 ;
F_9 ( & V_6 -> V_124 , V_27 ) ;
if ( F_52 ( V_125 , & V_6 -> V_126 ) ) {
if ( V_6 -> V_76 < 2 ) {
F_10 ( & V_6 -> V_124 ,
V_27 ) ;
F_46 ( V_2 , V_56 ) ;
F_53 ( V_2 , V_56 ) ;
} else {
F_3 ( V_2 -> V_9 + V_168 ) ;
F_10 ( & V_6 -> V_124 ,
V_27 ) ;
}
F_31 ( 8 ) ;
} else {
F_10 ( & V_6 -> V_124 , V_27 ) ;
}
return 1 ;
}
static void F_54 ( struct V_1 * V_2 ,
struct V_55 * V_56 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_143 * V_127 = V_56 -> V_127 ;
struct V_91 * V_92 = & V_127 -> V_92 ;
unsigned long V_27 ;
F_55 ( V_125 , & V_6 -> V_126 ) ;
if ( ! V_6 -> V_144 && ( V_6 -> V_145 == 0 ) ) {
V_127 -> V_146 |= V_150 ;
F_44 ( V_2 , V_56 ) ;
F_53 ( V_2 , V_56 ) ;
} else {
if ( V_6 -> V_76 >= 2 ) {
unsigned short V_169 ;
int V_170 ;
V_170 = F_49 ( V_2 , V_56 ) ;
F_53 ( V_2 , V_56 ) ;
if ( ! V_170 ) {
return;
}
switch ( V_92 -> V_100 ) {
case V_97 :
V_169 = V_171 ;
break;
case V_99 :
if ( ( V_92 -> V_108 & V_111 ) == 0 ) {
V_169 = V_172 ;
} else {
V_169 = V_173 ;
}
break;
case V_96 :
V_169 = V_174 ;
break;
default:
V_169 = V_175 ;
break;
}
V_6 -> V_137 = ( V_6 -> V_137
& ~ V_176 ) |
V_169 ;
F_6 ( V_6 -> V_137 , V_2 -> V_9 + V_90 ) ;
}
switch ( V_92 -> V_100 ) {
case V_97 :
if ( V_6 -> V_76 < 2 ) {
F_9 ( & V_6 -> V_130 ,
V_27 ) ;
V_6 -> V_131 |= V_128 ;
V_6 -> V_135 |= V_128 ;
F_21 ( V_6 -> V_135 ,
V_6 -> V_51 + V_136 ) ;
F_10 ( & V_6 -> V_130 ,
V_27 ) ;
}
F_21 ( F_56 ( 1 , V_177 ) ,
V_6 -> V_51 + V_178 ) ;
break;
case V_96 :
V_127 -> V_179 = F_51 ;
break;
}
if ( V_6 -> V_76 >= 2 ) {
F_9 ( & V_6 -> V_130 , V_27 ) ;
V_6 -> V_131 |= V_129 ;
V_6 -> V_135 |= V_129 ;
F_21 ( V_6 -> V_135 , V_6 -> V_51 + V_136 ) ;
F_10 ( & V_6 -> V_130 ,
V_27 ) ;
}
}
}
static int F_57 ( struct V_1 * V_2 ,
struct V_55 * V_56 ,
unsigned int V_167 )
{
if ( V_167 != 0 )
return - V_71 ;
V_56 -> V_127 -> V_179 = NULL ;
F_54 ( V_2 , V_56 ) ;
return 1 ;
}
static int F_58 ( struct V_1 * V_2 , struct V_55 * V_56 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
unsigned short V_137 ;
unsigned int V_60 ;
struct V_91 * V_92 = & V_56 -> V_127 -> V_92 ;
if ( V_92 -> V_100 == V_97 ) {
if ( ! F_11 ( V_2 , V_180 , V_141 ) )
return - V_181 ;
}
if ( V_92 -> V_105 == V_104 ) {
V_6 -> V_145 = V_92 -> V_114 ;
V_6 -> V_144 = 0 ;
} else {
V_6 -> V_145 = 0 ;
V_6 -> V_144 = 1 ;
}
V_60 = F_27 ( V_92 -> V_116 [ 0 ] ) ;
V_6 -> V_14 = V_89 [ V_60 ] ;
V_137 = V_6 -> V_14 ? V_182 : V_183 ;
if ( V_6 -> V_76 >= 2 ) {
unsigned short V_184 ;
unsigned int V_24 ;
V_184 = 0 ;
for ( V_24 = 0 ; V_24 < V_92 -> V_113 ; V_24 ++ )
V_184 |= 1 << F_26 ( V_92 -> V_116 [ V_24 ] ) ;
F_6 ( V_184 , V_2 -> V_9 + V_185 ) ;
V_137 |= V_186 | V_139
| V_140
| V_175 | V_187 ;
}
F_6 ( V_137 , V_2 -> V_9 + V_90 ) ;
V_6 -> V_137 = V_137
& ~ ( V_139 | V_140 ) ;
if ( V_92 -> V_100 == V_97 ) {
F_21 ( F_56 ( 1 , V_188 ) ,
V_6 -> V_51 + V_178 ) ;
F_19 ( V_2 , 1 , V_189 ,
V_92 -> V_108 ,
V_92 -> V_115 & V_37 ) ;
}
V_56 -> V_127 -> V_179 = F_57 ;
return 0 ;
}
static int F_59 ( struct V_1 * V_2 ,
struct V_55 * V_56 )
{
F_44 ( V_2 , V_56 ) ;
return 0 ;
}
static int F_60 ( struct V_91 * V_92 )
{
unsigned int V_190 , V_113 ;
int V_93 = 0 ;
V_113 = V_92 -> V_113 ;
if ( V_92 -> V_113 == 0 )
V_113 = 1 ;
V_190 = V_113 * V_92 -> V_191 ;
if ( ( V_190 < V_113 )
|| ( V_190 < V_92 -> V_191 ) ) {
V_190 = V_41 ;
V_93 ++ ;
}
if ( V_92 -> V_108 < V_190 ) {
V_92 -> V_108 = V_190 ;
V_93 ++ ;
}
return ! V_93 ;
}
static int F_61 ( struct V_1 * V_2 ,
struct V_55 * V_56 , struct V_91 * V_92 )
{
const struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = V_2 -> V_7 ;
int V_93 = 0 ;
unsigned int V_94 ;
V_93 |= F_36 ( & V_92 -> V_95 , V_102 | V_96 ) ;
V_94 = V_192 | V_97 | V_96 ;
if ( ( V_4 -> V_193 ) || ( V_4 -> V_98 > 0 ) ) {
V_94 |= V_99 ;
}
V_93 |= F_36 ( & V_92 -> V_100 , V_94 ) ;
V_93 |= F_36 ( & V_92 -> V_101 ,
V_97 | V_96 | V_99 ) ;
V_93 |= F_36 ( & V_92 -> V_103 , V_104 ) ;
V_93 |= F_36 ( & V_92 -> V_105 , V_104 | V_106 ) ;
if ( V_93 )
return 1 ;
V_93 |= F_37 ( V_92 -> V_95 ) ;
V_93 |= F_37 ( V_92 -> V_100 ) ;
V_93 |= F_37 ( V_92 -> V_101 ) ;
V_93 |= F_37 ( V_92 -> V_105 ) ;
if ( ( V_92 -> V_100 != V_192 )
&& ( V_92 -> V_101 != V_97 ) )
V_93 |= - V_71 ;
if ( V_93 )
return 2 ;
V_93 |= F_38 ( & V_92 -> V_107 , 0 ) ;
#define F_62 3200
#define F_63 8000
#define F_64 4000
#define F_65 4294967295u
if ( V_92 -> V_101 == V_97 ) {
unsigned int V_194 ;
if ( V_6 -> V_76 == 0 ) {
if ( V_92 -> V_116 && ( V_92 -> V_113 > 0 ) ) {
if ( F_28 ( V_92 -> V_116 [ 0 ] ) == V_67 )
V_194 = F_63 ;
else
V_194 = F_62 ;
} else {
V_194 = F_62 ;
}
} else {
V_194 = F_64 ;
}
V_93 |= F_41 ( & V_92 -> V_191 ,
V_194 ) ;
V_93 |= F_42 ( & V_92 -> V_191 ,
F_65 ) ;
} else if ( V_92 -> V_101 == V_99 ) {
if ( ( V_92 -> V_191 & V_109 ) != 0 ) {
if ( ( V_92 -> V_191 & ~ V_109 ) != 0 ) {
V_92 -> V_191 = F_43 ( V_92 -> V_191 , 0 ,
~ V_109 ) ;
V_93 |= - V_71 ;
}
if ( ( V_92 -> V_191 & ( V_109 & ~ V_111 ) )
!= V_110 ) {
V_92 -> V_191 = F_43 ( V_92 -> V_107 ,
( V_110 | 0 ) ,
V_109 &
~ V_111 ) ;
V_93 |= - V_71 ;
}
} else {
V_93 |= F_42 ( & V_92 -> V_191 , 1 ) ;
}
} else {
V_93 |= F_38 ( & V_92 -> V_191 , 0 ) ;
}
V_93 |= F_38 ( & V_92 -> V_112 , V_92 -> V_113 ) ;
if ( V_92 -> V_105 == V_106 )
V_93 |= F_38 ( & V_92 -> V_114 , 0 ) ;
if ( V_92 -> V_100 == V_99 ) {
if ( ( V_92 -> V_108 & ~ V_109 ) != 0 ) {
V_92 -> V_108 = F_43 ( V_92 -> V_108 , 0 ,
~ V_109 ) ;
V_93 |= - V_71 ;
}
if ( ( V_92 -> V_108 & V_109 & ~ V_110 ) != 0 ) {
V_92 -> V_108 = F_43 ( V_92 -> V_108 , 0 ,
V_109 & ~ V_110 ) ;
V_93 |= - V_71 ;
}
} else if ( V_92 -> V_100 == V_97 ) {
if ( ! F_60 ( V_92 ) )
V_93 |= - V_71 ;
} else {
V_93 |= F_38 ( & V_92 -> V_108 , 0 ) ;
}
if ( V_93 )
return 3 ;
if ( V_92 -> V_101 == V_97 ) {
V_94 = V_92 -> V_191 ;
F_18 ( & V_92 -> V_191 ,
V_92 -> V_115 & V_37 ) ;
if ( V_94 != V_92 -> V_191 )
V_93 ++ ;
}
if ( V_92 -> V_100 == V_97 ) {
V_94 = V_92 -> V_108 ;
F_18 ( & V_92 -> V_108 ,
V_92 -> V_115 & V_37 ) ;
if ( ! F_60 ( V_92 ) ) {
F_18 ( & V_92 -> V_108 ,
V_40 ) ;
F_60 ( V_92 ) ;
}
if ( V_94 != V_92 -> V_108 )
V_93 ++ ;
}
if ( V_93 )
return 4 ;
if ( V_92 -> V_116 && V_92 -> V_113 > 0 ) {
enum {
V_117 = 1 << 0 ,
V_195 = 1 << 1 ,
V_196 = 1 << 2 ,
V_197 = 1 << 3 ,
V_198 = 1 << 4 ,
V_199 = 1 << 5
};
unsigned int V_119 ;
unsigned int V_16 , V_120 ;
unsigned int V_60 , V_200 ;
unsigned int V_201 , V_202 ;
unsigned int V_61 , V_203 ;
unsigned int V_204 ;
unsigned int V_59 ;
V_204 = 0 ;
V_119 = 0 ;
V_120 = V_203 = V_200 = V_202 = 0 ;
for ( V_59 = 0 ; V_59 < V_92 -> V_113 ; V_59 ++ ) {
V_16 = F_26 ( V_92 -> V_116 [ V_59 ] ) ;
V_60 = F_27 ( V_92 -> V_116 [ V_59 ] ) ;
V_61 = F_28 ( V_92 -> V_116 [ V_59 ] ) ;
V_201 = V_75 [ V_60 ] ;
if ( ( V_61 == V_67 )
&& ( V_16 >= ( V_56 -> V_68 / 2 ) ) ) {
V_119 |= V_198 ;
}
if ( V_59 > 0 ) {
if ( ( V_16 <= V_120 )
&& ( V_204 == 0 ) ) {
V_204 = V_59 ;
}
if ( ( V_204 > 0 )
&& ( V_92 -> V_116 [ V_59 ] !=
V_92 -> V_116 [ V_59 % V_204 ] ) ) {
V_119 |= V_117 ;
}
if ( V_61 != V_203 )
V_119 |= V_197 ;
if ( V_201 != V_202 )
V_119 |= V_196 ;
if ( ( V_61 != V_67 )
&& ( ( ( V_16 ^ V_120 ) & ~ 1 ) == 0 )
&& ( V_60 != V_200 ) ) {
V_119 |= V_195 ;
}
}
V_120 = V_16 ;
V_200 = V_60 ;
V_203 = V_61 ;
V_202 = V_201 ;
}
if ( V_204 == 0 ) {
V_204 = V_59 ;
}
if ( ( V_59 % V_204 ) != 0 )
V_119 |= V_117 ;
if ( ( V_6 -> V_76 > 0 ) && ( V_6 -> V_76 < 4 ) ) {
if ( ( V_204 > 1 )
&& ( F_26 ( V_92 -> V_116 [ 0 ] ) != 0 ) ) {
V_119 |= V_199 ;
}
}
if ( V_119 != 0 ) {
V_93 ++ ;
if ( ( V_119 & V_117 ) != 0 ) {
F_29 ( V_2 -> V_69 ,
L_7 ,
V_70 ) ;
}
if ( ( V_119 & V_195 ) != 0 ) {
F_29 ( V_2 -> V_69 ,
L_8 ,
V_70 ) ;
}
if ( ( V_119 & V_196 ) != 0 ) {
F_29 ( V_2 -> V_69 ,
L_9 ,
V_70 ) ;
}
if ( ( V_119 & V_197 ) != 0 ) {
F_29 ( V_2 -> V_69 ,
L_10 ,
V_70 ) ;
}
if ( ( V_119 & V_198 ) != 0 ) {
F_29 ( V_2 -> V_69 ,
L_1 ,
V_70 , ( V_56 -> V_68 / 2 ) - 1 ) ;
}
if ( ( V_119 & V_199 ) != 0 ) {
F_66 ( V_2 -> V_69 ,
L_11 ,
V_6 -> V_76 ) ;
}
}
}
if ( V_93 )
return 5 ;
return 0 ;
}
static void F_67 ( struct V_1 * V_2 ,
struct V_55 * V_56 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_91 * V_92 = & V_56 -> V_127 -> V_92 ;
unsigned int V_205 = V_92 -> V_112 ;
unsigned int V_206 ;
unsigned short V_207 ;
unsigned short V_64 ;
if ( ( V_92 -> V_115 & V_208 ) != 0 ) {
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
if ( ( V_206 > 1 ) && ( V_6 -> V_76 > 0 ) ) {
if ( V_6 -> V_214 != V_206 ) {
V_6 -> V_214 = V_206 ;
F_6 ( V_206 , V_2 -> V_9 + V_215 ) ;
}
V_207 = V_216 ;
} else {
V_207 = V_217 ;
}
}
V_64 = ( V_6 -> V_64 & ~ V_218 ) | V_207 ;
if ( V_64 != V_6 -> V_64 ) {
V_6 -> V_64 = V_64 ;
F_6 ( V_64 , V_2 -> V_9 + V_86 ) ;
}
}
static int F_68 ( struct V_1 * V_2 ,
struct V_55 * V_56 ,
unsigned int V_167 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
unsigned long V_27 ;
if ( V_167 != 0 )
return - V_71 ;
F_9 ( & V_6 -> V_219 , V_27 ) ;
if ( F_52 ( V_220 , & V_6 -> V_126 ) ) {
unsigned int V_221 ;
F_20 ( V_6 -> V_51 + V_52 , 0 , 2 ,
V_74 ) ;
F_20 ( V_6 -> V_51 + V_52 , 0 , 2 ,
V_54 ) ;
if ( ( ( V_6 -> V_64 & V_222 )
== V_77 )
&& ( V_6 -> V_76 == 0 ) ) {
V_221 = 8 ;
} else {
V_221 = 4 ;
}
F_10 ( & V_6 -> V_219 , V_27 ) ;
F_31 ( V_221 ) ;
} else {
F_10 ( & V_6 -> V_219 , V_27 ) ;
}
return 1 ;
}
static int F_69 ( struct V_1 * V_2 ,
struct V_55 * V_56 ,
unsigned int V_167 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
unsigned long V_27 ;
unsigned char V_223 ;
if ( V_167 != 0 )
return - V_71 ;
F_9 ( & V_6 -> V_219 , V_27 ) ;
if ( F_52 ( V_220 , & V_6 -> V_126 ) ) {
V_223 = F_56 ( 0 , V_188 ) ;
F_21 ( V_223 , V_6 -> V_51 + V_178 ) ;
V_223 = F_56 ( 0 , V_177 ) ;
F_21 ( V_223 , V_6 -> V_51 + V_178 ) ;
}
F_10 ( & V_6 -> V_219 , V_27 ) ;
return 1 ;
}
static void F_70 ( struct V_1 * V_2 ,
struct V_55 * V_56 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
unsigned long V_27 ;
struct V_91 * V_92 ;
int V_123 ;
F_9 ( & V_6 -> V_219 , V_27 ) ;
V_123 = F_45 ( V_220 , & V_6 -> V_126 ) ;
F_10 ( & V_6 -> V_219 , V_27 ) ;
if ( ! V_123 )
return;
V_92 = & V_56 -> V_127 -> V_92 ;
if ( V_92 -> V_101 == V_97 ) {
F_24 ( V_2 , 2 ) ;
}
if ( V_92 -> V_100 != V_192 ) {
F_24 ( V_2 , 0 ) ;
}
F_9 ( & V_6 -> V_130 , V_27 ) ;
V_6 -> V_131 &= ~ V_224 ;
while ( V_6 -> V_132 && V_6 -> V_133 != V_134 ) {
F_10 ( & V_6 -> V_130 , V_27 ) ;
F_9 ( & V_6 -> V_130 , V_27 ) ;
}
if ( V_6 -> V_135 != V_6 -> V_131 ) {
V_6 -> V_135 = V_6 -> V_131 ;
F_21 ( V_6 -> V_135 , V_6 -> V_51 + V_136 ) ;
}
F_10 ( & V_6 -> V_130 , V_27 ) ;
V_6 -> V_64 = ( V_6 -> V_64 & ( V_225
| V_222 ) ) |
V_226 ;
F_6 ( V_6 -> V_64 | V_85 ,
V_2 -> V_9 + V_86 ) ;
F_14 ( V_2 , V_227 ) ;
}
static void F_71 ( struct V_1 * V_2 ,
struct V_55 * V_56 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
unsigned long V_27 ;
unsigned short V_228 ;
struct V_143 * V_127 = V_56 -> V_127 ;
struct V_91 * V_92 = & V_127 -> V_92 ;
F_55 ( V_220 , & V_6 -> V_126 ) ;
if ( ! V_6 -> V_210 && ( V_6 -> V_211 == 0 ) ) {
V_127 -> V_146 |= V_150 ;
F_70 ( V_2 , V_56 ) ;
F_53 ( V_2 , V_56 ) ;
} else {
F_9 ( & V_6 -> V_130 , V_27 ) ;
V_6 -> V_131 |= V_224 ;
V_6 -> V_135 |= V_224 ;
F_21 ( V_6 -> V_135 , V_6 -> V_51 + V_136 ) ;
F_10 ( & V_6 -> V_130 , V_27 ) ;
switch ( V_92 -> V_101 ) {
default:
V_228 = V_226 ;
break;
case V_97 :
V_228 = V_72 ;
break;
case V_99 :
if ( ( V_92 -> V_191 & V_110 ) != 0 ) {
if ( ( V_92 -> V_191 & V_111 ) == 0 ) {
V_228 = V_229 ;
} else {
V_228 = V_230 ;
}
} else {
if ( V_92 -> V_191 != 0 ) {
V_228 = V_229 ;
} else {
V_228 = V_230 ;
}
}
break;
case V_96 :
V_228 = V_72 ;
break;
}
V_6 -> V_64 = ( V_6 -> V_64 & ~ V_231 )
| V_228 ;
F_6 ( V_6 -> V_64 , V_2 -> V_9 + V_86 ) ;
if ( V_92 -> V_101 == V_96 )
V_127 -> V_179 = F_68 ;
F_67 ( V_2 , V_56 ) ;
if ( V_92 -> V_101 == V_97 ) {
unsigned char V_223 ;
if ( V_92 -> V_100 != V_192 ) {
V_223 = F_56 ( 2 , V_232 ) ;
} else {
V_223 = F_56 ( 2 , V_177 ) ;
}
F_21 ( V_223 , V_6 -> V_51 + V_178 ) ;
if ( V_92 -> V_100 != V_192 ) {
switch ( V_92 -> V_100 ) {
default:
V_223 = F_56 ( 0 , V_177 ) ;
break;
case V_99 :
V_223 = F_56 ( 0 , V_233 ) ;
break;
case V_97 :
V_223 = F_56 ( 0 , V_232 ) ;
break;
case V_96 :
V_223 = F_56 ( 0 , V_177 ) ;
break;
}
F_21 ( V_223 , V_6 -> V_51 + V_178 ) ;
switch ( V_92 -> V_100 ) {
case V_97 :
V_223 = F_56 ( 1 , V_177 ) ;
F_21 ( V_223 , V_6 -> V_51
+ V_178 ) ;
break;
case V_96 :
V_127 -> V_179 =
F_69 ;
break;
}
}
} else if ( V_92 -> V_101 != V_96 ) {
F_13 ( V_2 , V_234 , V_227 ) ;
}
}
}
static int F_72 ( struct V_1 * V_2 ,
struct V_55 * V_56 ,
unsigned int V_167 )
{
if ( V_167 != 0 )
return - V_71 ;
V_56 -> V_127 -> V_179 = NULL ;
F_71 ( V_2 , V_56 ) ;
return 1 ;
}
static void F_73 ( struct V_1 * V_2 ,
struct V_55 * V_56 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
unsigned int V_146 = 0 ;
unsigned int V_235 ;
unsigned int V_24 ;
unsigned int V_236 ;
unsigned int V_237 ;
struct V_143 * V_127 = V_56 -> V_127 ;
unsigned int V_205 = V_127 -> V_92 . V_112 ;
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
V_235 = F_3 ( V_2 -> V_9 + V_86 ) ;
if ( ( V_235 & V_238 ) != 0 ) {
F_48 ( V_2 , L_12 ) ;
V_146 |= V_147 | V_157 ;
break;
} else if ( ( V_235 & V_87 ) != 0 ) {
break;
} else if ( ( V_235 & V_239 ) != 0 ) {
V_237 = V_212 ;
} else {
if ( V_6 -> V_76 > 0 ) {
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
if ( F_74 ( V_127 , F_1 ( V_2 ) ) == 0 ) {
V_146 |= V_157 | V_147 ;
F_48 ( V_2 , L_13 ) ;
break;
}
V_237 -- ;
V_6 -> V_209 ++ ;
if ( V_6 -> V_209 == V_205 ) {
V_6 -> V_209 = 0 ;
V_6 -> V_211 -- ;
V_127 -> V_146 |= V_149 ;
}
}
if ( ! V_6 -> V_210 && ( V_6 -> V_211 == 0 ) ) {
V_146 |= V_150 ;
} else {
V_146 |= V_148 ;
}
V_127 -> V_146 |= V_146 ;
if ( ( V_127 -> V_146 & ( V_150 | V_157 |
V_147 ) ) != 0 ) {
F_70 ( V_2 , V_56 ) ;
} else {
F_67 ( V_2 , V_56 ) ;
}
}
static int F_75 ( struct V_1 * V_2 , struct V_55 * V_56 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
unsigned int V_24 , V_16 , V_60 , V_241 ;
unsigned int V_21 ;
unsigned short V_64 , V_65 ;
unsigned char V_223 ;
struct V_143 * V_127 = V_56 -> V_127 ;
struct V_91 * V_92 = & V_127 -> V_92 ;
V_21 = 0 ;
V_21 |= ( 1U << V_234 ) ;
if ( V_92 -> V_100 != V_192 ) {
V_21 |= ( 1U << V_242 ) ;
if ( V_92 -> V_100 == V_97 ) {
V_21 |= ( 1U << V_180 ) ;
}
}
if ( ! F_8 ( V_2 , V_21 , V_227 ) )
return - V_181 ;
if ( V_92 -> V_105 == V_104 ) {
V_6 -> V_211 = V_92 -> V_114 ;
V_6 -> V_210 = 0 ;
} else {
V_6 -> V_211 = 0 ;
V_6 -> V_210 = 1 ;
}
V_6 -> V_209 = 0 ;
V_64 = V_73 ;
V_65 = 0 ;
if ( F_28 ( V_92 -> V_116 [ 0 ] ) == V_67 ) {
V_241 = 1 ;
V_64 |= V_77 ;
} else {
V_241 = 0 ;
V_64 |= V_78 ;
}
V_60 = F_27 ( V_92 -> V_116 [ 0 ] ) ;
V_6 -> V_12 = V_75 [ V_60 ] ;
if ( V_6 -> V_12 )
V_64 |= V_81 ;
else
V_64 |= V_82 ;
for ( V_24 = 0 ; V_24 < V_92 -> V_113 ; V_24 ++ ) {
unsigned int V_62 ;
V_16 = F_26 ( V_92 -> V_116 [ V_24 ] ) ;
V_60 = F_27 ( V_92 -> V_116 [ V_24 ] ) ;
if ( V_241 ) {
V_62 = 2 * V_16 ;
if ( V_6 -> V_76 == 0 ) {
V_65 |= 3 << V_62 ;
} else {
V_65 |= 1 << V_62 ;
}
} else {
V_62 = ( V_16 & ~ 1 ) ;
V_65 |= 1 << V_16 ;
}
V_6 -> V_79 = ( V_6 -> V_79 & ~ ( 3 << V_62 ) )
| ( V_80 [ V_60 ] << V_62 ) ;
}
F_6 ( V_65 , V_2 -> V_9 + V_83 ) ;
F_6 ( V_6 -> V_79 , V_2 -> V_9 + V_84 ) ;
F_20 ( V_6 -> V_51 + V_52 , 0 , 2 , V_54 ) ;
V_64 |= V_243 | V_72 ;
V_6 -> V_64 = V_64 ;
F_6 ( V_64 | V_85 , V_2 -> V_9 + V_86 ) ;
F_31 ( 25 ) ;
F_6 ( V_64 | V_85 , V_2 -> V_9 + V_86 ) ;
if ( V_92 -> V_101 == V_97 ) {
V_223 = F_56 ( 2 , V_188 ) ;
F_21 ( V_223 , V_6 -> V_51 + V_178 ) ;
F_19 ( V_2 , 2 , V_189 , V_92 -> V_191 ,
V_92 -> V_115 & V_37 ) ;
if ( V_92 -> V_100 != V_192 ) {
V_223 = F_56 ( 0 , V_177 ) ;
F_21 ( V_223 , V_6 -> V_51 + V_178 ) ;
F_19 ( V_2 , 0 , V_54 ,
( ( T_1 ) V_92 -> V_191
* V_92 -> V_112 ) ,
V_40 ) ;
if ( V_92 -> V_100 == V_97 ) {
V_223 = F_56 ( 1 , V_188 ) ;
F_21 ( V_223 , V_6 -> V_51 + V_178 ) ;
F_19 ( V_2 , 1 , V_189 ,
V_92 -> V_108 ,
V_92 ->
V_115 &
V_37 ) ;
}
}
}
if ( V_92 -> V_95 == V_96 ) {
V_56 -> V_127 -> V_179 = F_72 ;
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
F_9 ( & V_6 -> V_130 , V_27 ) ;
V_247 = V_6 -> V_131 & V_246 ;
V_6 -> V_135 = V_6 -> V_131 & ~ V_246 ;
F_21 ( V_6 -> V_135 , V_6 -> V_51 + V_136 ) ;
V_6 -> V_132 = 1 ;
V_6 -> V_133 = V_134 ;
F_10 ( & V_6 -> V_130 , V_27 ) ;
if ( ( V_247 & V_128 ) != 0 ) {
V_56 = V_2 -> V_251 ;
F_46 ( V_2 , V_56 ) ;
F_53 ( V_2 , V_56 ) ;
}
if ( ( V_247 & V_129 ) != 0 ) {
V_56 = V_2 -> V_251 ;
F_49 ( V_2 , V_56 ) ;
F_53 ( V_2 , V_56 ) ;
}
if ( ( V_247 & V_224 ) != 0 ) {
V_56 = V_2 -> V_252 ;
F_73 ( V_2 , V_56 ) ;
F_53 ( V_2 , V_56 ) ;
}
F_9 ( & V_6 -> V_130 , V_27 ) ;
if ( V_6 -> V_135 != V_6 -> V_131 ) {
V_6 -> V_135 = V_6 -> V_131 ;
F_21 ( V_6 -> V_135 , V_6 -> V_51 + V_136 ) ;
}
V_6 -> V_132 = 0 ;
F_10 ( & V_6 -> V_130 , V_27 ) ;
return V_253 ;
}
static bool F_79 ( const struct V_3 * V_254 ,
struct V_255 * V_255 )
{
if ( V_254 -> V_256 != V_255 -> V_257 )
return false ;
if ( V_254 -> V_98 == 0 )
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
F_32 ( V_2 -> V_69 ,
L_14 ,
V_261 , V_263 ) ;
return NULL ;
}
static int F_86 ( struct V_1 * V_2 )
{
struct V_5 * V_6 ;
V_6 = F_87 ( V_2 , sizeof( * V_6 ) ) ;
if ( ! V_6 )
return - V_271 ;
F_88 ( & V_6 -> V_130 ) ;
F_88 ( & V_6 -> V_28 ) ;
F_88 ( & V_6 -> V_219 ) ;
F_88 ( & V_6 -> V_124 ) ;
return 0 ;
}
static int F_89 ( struct V_1 * V_2 ,
struct V_255 * V_255 )
{
const struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_55 * V_56 ;
unsigned long V_51 , V_272 ;
int V_273 ;
F_90 ( V_2 , & V_255 -> V_2 ) ;
V_2 -> V_274 = V_4 -> V_275 ;
V_273 = F_91 ( V_2 ) ;
if ( V_273 )
return V_273 ;
V_51 = F_92 ( V_255 , 2 ) ;
V_272 = F_92 ( V_255 , 3 ) ;
F_29 ( V_2 -> V_69 ,
L_15 ,
V_2 -> V_274 , V_51 , V_272 ) ;
V_6 -> V_51 = V_51 ;
V_2 -> V_9 = V_272 ;
V_6 -> V_137 = F_3 ( V_2 -> V_9 + V_90 ) & V_138 ;
if ( F_80 ( V_255 , 3 ) >= 32 ) {
unsigned short V_276 = 0 ;
V_6 -> V_76 = F_3 ( V_2 -> V_9 + V_277 ) ;
if ( V_6 -> V_76 < V_4 -> V_98 ) {
F_32 ( V_2 -> V_69 ,
L_16 ,
V_2 -> V_274 , V_6 -> V_76 ,
V_4 -> V_98 ) ;
return - V_278 ;
}
if ( V_6 -> V_76 > 0 ) {
if ( ! V_4 -> V_193 ) {
V_276 |= V_279 ;
}
if ( ( V_4 -> V_280 > 0 )
&& ( V_6 -> V_76 >= 2 ) ) {
V_276 |= V_281 ;
}
}
F_6 ( V_276 , V_2 -> V_9 + V_282 ) ;
if ( ( V_276 & V_281 ) != 0 ) {
F_6 ( V_6 -> V_137 | V_186
| V_139 ,
V_2 -> V_9 + V_90 ) ;
F_6 ( 0 , V_2 -> V_9 + V_185 ) ;
F_6 ( V_6 -> V_137 , V_2 -> V_9 + V_90 ) ;
}
}
F_21 ( 0 , V_6 -> V_51 + V_136 ) ;
V_6 -> V_79 = 0 ;
V_6 -> V_64 = V_226 | V_78
| V_81 ;
F_6 ( 1 << 0 , V_2 -> V_9 + V_83 ) ;
F_6 ( V_6 -> V_79 , V_2 -> V_9 + V_84 ) ;
F_6 ( V_6 -> V_64 | V_85 ,
V_2 -> V_9 + V_86 ) ;
if ( V_255 -> V_244 ) {
V_273 = F_93 ( V_255 -> V_244 , F_77 , V_283 ,
V_2 -> V_274 , V_2 ) ;
if ( V_273 == 0 )
V_2 -> V_244 = V_255 -> V_244 ;
}
V_273 = F_94 ( V_2 , 3 ) ;
if ( V_273 )
return V_273 ;
V_56 = & V_2 -> V_284 [ 0 ] ;
V_56 -> type = V_285 ;
V_56 -> V_286 = V_287 | V_288 | V_289 ;
V_56 -> V_68 = V_4 -> V_290 ;
V_56 -> V_291 = ( 1 << V_4 -> V_11 ) - 1 ;
V_56 -> V_292 = & V_293 ;
V_56 -> V_294 = & F_25 ;
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
V_56 -> V_68 = V_4 -> V_280 ;
V_56 -> V_291 = ( 1 << V_4 -> V_15 ) - 1 ;
V_56 -> V_292 = & V_302 ;
V_56 -> V_303 = & F_33 ;
V_56 -> V_294 = & F_34 ;
V_56 -> V_295 = V_4 -> V_280 ;
if ( V_2 -> V_244 ) {
V_2 -> V_251 = V_56 ;
V_56 -> V_286 |= V_304 ;
V_56 -> V_297 = & F_58 ;
V_56 -> V_298 = & F_35 ;
V_56 -> V_299 = F_59 ;
}
} else {
V_56 -> type = V_305 ;
}
V_56 = & V_2 -> V_284 [ 2 ] ;
if ( V_4 -> V_193 ) {
V_273 = F_95 ( V_2 , V_56 , NULL ,
( V_6 -> V_51 + V_306 ) ) ;
if ( V_273 < 0 )
return V_273 ;
} else {
V_56 -> type = V_305 ;
}
F_66 ( V_2 -> V_69 , L_17 ) ;
return 1 ;
}
static int F_96 ( struct V_1 * V_2 , struct V_259 * V_260 )
{
const struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_255 * V_255 ;
int V_273 ;
F_66 ( V_2 -> V_69 , L_18 ,
V_4 -> V_275 , V_260 -> V_262 [ 0 ] , V_260 -> V_262 [ 1 ] ) ;
V_273 = F_86 ( V_2 ) ;
if ( V_273 )
return V_273 ;
V_255 = F_83 ( V_2 , V_260 ) ;
if ( ! V_255 )
return - V_278 ;
return F_89 ( V_2 , V_255 ) ;
}
static int F_97 ( struct V_1 * V_2 ,
unsigned long V_307 )
{
struct V_255 * V_255 = F_98 ( V_2 ) ;
int V_273 ;
F_66 ( V_2 -> V_69 , L_19 ,
F_99 ( V_255 ) ) ;
V_273 = F_86 ( V_2 ) ;
if ( V_273 )
return V_273 ;
V_2 -> V_270 = F_81 ( V_255 ) ;
if ( V_2 -> V_270 == NULL ) {
F_32 ( V_2 -> V_69 ,
L_20 ) ;
return - V_71 ;
}
F_100 ( V_255 ) ;
return F_89 ( V_2 , V_255 ) ;
}
static void F_101 ( struct V_1 * V_2 )
{
struct V_255 * V_308 = F_98 ( V_2 ) ;
if ( V_2 -> V_244 )
F_102 ( V_2 -> V_244 , V_2 ) ;
F_103 ( V_2 ) ;
if ( V_308 )
F_104 ( V_308 ) ;
}
static int F_105 ( struct V_255 * V_2 ,
const struct V_309 * V_256 )
{
return F_106 ( V_2 , & V_310 ,
V_256 -> V_311 ) ;
}
