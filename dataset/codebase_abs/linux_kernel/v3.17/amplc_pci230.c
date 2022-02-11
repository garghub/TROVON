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
F_6 ( F_4 ( V_2 , V_13 ) ,
V_2 -> V_9 + ( ( ( V_16 ) == 0 ) ? V_18 : V_19 ) ) ;
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
for ( V_25 = 1 , V_24 = 0 ; ( V_24 < V_29 ) && V_21 ; V_25 <<= 1 , V_24 ++ ) {
if ( V_21 & V_25 ) {
V_21 &= ~ V_25 ;
if ( V_6 -> V_30 [ V_24 ] == V_31 ) {
V_6 -> V_30 [ V_24 ] = V_22 ;
V_26 |= V_25 ;
} else if ( V_6 -> V_30 [ V_24 ] != V_22 ) {
for ( V_25 = 1 , V_24 = 0 ; V_26 ; V_25 <<= 1 , V_24 ++ ) {
if ( V_26 & V_25 ) {
V_6 -> V_30 [ V_24 ] =
V_31 ;
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
for ( V_25 = 1 , V_24 = 0 ; ( V_24 < V_29 ) && V_21 ; V_25 <<= 1 , V_24 ++ ) {
if ( V_21 & V_25 ) {
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
switch ( V_35 & V_37 ) {
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
static void F_18 ( unsigned int * V_33 , unsigned int V_35 )
{
unsigned int V_42 ;
unsigned int V_43 ;
V_43 = F_17 ( * V_33 , & V_42 , V_35 ) ;
* V_33 = V_42 * V_46 [ V_43 ] ;
}
static void F_19 ( struct V_1 * V_2 , unsigned int V_48 ,
unsigned int V_49 , T_1 V_33 ,
unsigned int V_35 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
unsigned int V_43 ;
unsigned int V_42 ;
F_20 ( V_6 -> V_50 + V_51 , 0 , V_48 , V_49 ) ;
V_43 = F_17 ( V_33 , & V_42 , V_35 ) ;
F_21 ( F_22 ( V_48 , V_43 ) , V_6 -> V_50 + V_52 ) ;
if ( V_42 >= 65536 )
V_42 = 0 ;
F_23 ( V_6 -> V_50 + V_51 , 0 , V_48 , V_42 ) ;
}
static void F_24 ( struct V_1 * V_2 , unsigned int V_48 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
F_20 ( V_6 -> V_50 + V_51 , 0 , V_48 ,
V_53 ) ;
}
static int F_25 ( struct V_1 * V_2 ,
struct V_54 * V_55 ,
struct V_56 * V_57 ,
unsigned long V_58 )
{
unsigned int V_59 ;
V_59 = F_3 ( V_2 -> V_9 + V_60 ) ;
if ( ( V_59 & V_61 ) == 0 )
return 0 ;
return - V_62 ;
}
static int F_26 ( struct V_1 * V_2 ,
struct V_54 * V_55 , struct V_56 * V_57 ,
unsigned int * V_8 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
unsigned int V_63 ;
unsigned int V_16 , V_64 , V_65 ;
unsigned int V_66 ;
unsigned short V_67 , V_68 ;
int V_69 ;
V_16 = F_27 ( V_57 -> V_70 ) ;
V_64 = F_28 ( V_57 -> V_70 ) ;
V_65 = F_29 ( V_57 -> V_70 ) ;
if ( V_65 == V_71 ) {
if ( V_16 >= V_55 -> V_72 / 2 ) {
F_30 ( V_2 -> V_73 ,
L_1 ,
V_74 , ( V_55 -> V_72 / 2 ) - 1 ) ;
return - V_75 ;
}
}
V_67 = V_76 | V_77 ;
F_20 ( V_6 -> V_50 + V_51 , 0 , 2 , V_78 ) ;
V_6 -> V_12 = V_79 [ V_64 ] ;
if ( V_65 == V_71 ) {
V_66 = V_16 * 2 ;
if ( V_6 -> V_80 == 0 ) {
V_68 = 3 << V_66 ;
} else {
V_68 = 1 << V_66 ;
}
V_67 |= V_81 ;
} else {
V_68 = 1 << V_16 ;
V_66 = V_16 & ~ 1 ;
V_67 |= V_82 ;
}
V_6 -> V_83 = ( V_6 -> V_83 & ~ ( 3 << V_66 ) ) |
( V_84 [ V_64 ] << V_66 ) ;
if ( V_6 -> V_12 )
V_67 |= V_85 ;
else
V_67 |= V_86 ;
F_6 ( V_68 , V_2 -> V_9 + V_87 ) ;
F_6 ( V_6 -> V_83 , V_2 -> V_9 + V_88 ) ;
V_6 -> V_67 = V_67 ;
F_6 ( V_67 | V_89 , V_2 -> V_9 + V_60 ) ;
for ( V_63 = 0 ; V_63 < V_57 -> V_63 ; V_63 ++ ) {
F_20 ( V_6 -> V_50 + V_51 , 0 , 2 ,
V_78 ) ;
F_20 ( V_6 -> V_50 + V_51 , 0 , 2 ,
V_53 ) ;
V_69 = F_31 ( V_2 , V_55 , V_57 , F_25 , 0 ) ;
if ( V_69 )
return V_69 ;
V_8 [ V_63 ] = F_1 ( V_2 ) ;
}
return V_63 ;
}
static int F_32 ( struct V_1 * V_2 ,
struct V_54 * V_55 , struct V_56 * V_57 ,
unsigned int * V_8 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
int V_24 ;
int V_16 , V_64 ;
V_16 = F_27 ( V_57 -> V_70 ) ;
V_64 = F_28 ( V_57 -> V_70 ) ;
V_6 -> V_14 = V_90 [ V_64 ] ;
F_6 ( V_64 , V_2 -> V_9 + V_91 ) ;
for ( V_24 = 0 ; V_24 < V_57 -> V_63 ; V_24 ++ ) {
F_5 ( V_2 , V_8 [ V_24 ] , V_16 ) ;
}
return V_24 ;
}
static int F_33 ( struct V_1 * V_2 ,
struct V_54 * V_55 , struct V_56 * V_57 ,
unsigned int * V_8 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
int V_24 ;
int V_16 = F_27 ( V_57 -> V_70 ) ;
for ( V_24 = 0 ; V_24 < V_57 -> V_63 ; V_24 ++ )
V_8 [ V_24 ] = V_6 -> V_17 [ V_16 ] ;
return V_24 ;
}
static int F_34 ( struct V_1 * V_2 ,
struct V_54 * V_55 ,
struct V_92 * V_93 )
{
unsigned int V_94 = F_27 ( V_93 -> V_95 [ 0 ] ) ;
unsigned int V_96 = F_28 ( V_93 -> V_95 [ 0 ] ) ;
int V_24 ;
for ( V_24 = 1 ; V_24 < V_93 -> V_97 ; V_24 ++ ) {
unsigned int V_16 = F_27 ( V_93 -> V_95 [ V_24 ] ) ;
unsigned int V_64 = F_28 ( V_93 -> V_95 [ V_24 ] ) ;
if ( V_16 < V_94 ) {
F_30 ( V_2 -> V_73 ,
L_2 ,
V_74 ) ;
return - V_75 ;
}
if ( V_64 != V_96 ) {
F_30 ( V_2 -> V_73 ,
L_3 ,
V_74 ) ;
return - V_75 ;
}
V_94 = V_16 ;
}
return 0 ;
}
static int F_35 ( struct V_1 * V_2 ,
struct V_54 * V_55 , struct V_92 * V_93 )
{
const struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = V_2 -> V_7 ;
int V_98 = 0 ;
unsigned int V_99 ;
V_98 |= F_36 ( & V_93 -> V_100 , V_101 ) ;
V_99 = V_102 | V_101 ;
if ( ( V_4 -> V_103 > 0 ) && ( V_6 -> V_80 >= 2 ) ) {
V_99 |= V_104 ;
}
V_98 |= F_36 ( & V_93 -> V_105 , V_99 ) ;
V_98 |= F_36 ( & V_93 -> V_106 , V_107 ) ;
V_98 |= F_36 ( & V_93 -> V_108 , V_109 ) ;
V_98 |= F_36 ( & V_93 -> V_110 , V_109 | V_111 ) ;
if ( V_98 )
return 1 ;
V_98 |= F_37 ( V_93 -> V_105 ) ;
V_98 |= F_37 ( V_93 -> V_110 ) ;
if ( V_98 )
return 2 ;
V_98 |= F_38 ( & V_93 -> V_112 , 0 ) ;
#define F_39 8000
#define F_40 4294967295u
switch ( V_93 -> V_105 ) {
case V_102 :
V_98 |= F_41 ( & V_93 -> V_113 ,
F_39 ) ;
V_98 |= F_42 ( & V_93 -> V_113 ,
F_40 ) ;
break;
case V_104 :
if ( V_93 -> V_113 & ~ V_114 ) {
V_93 -> V_113 = F_43 ( V_93 -> V_113 , 0 ,
~ V_114 ) ;
V_98 |= - V_75 ;
}
if ( V_93 -> V_113 &
( V_114 & ~ ( V_115 | V_116 ) ) ) {
V_93 -> V_113 = F_43 ( V_93 -> V_113 , 0 ,
V_114 &
~ ( V_115 | V_116 ) ) ;
V_98 |= - V_75 ;
}
break;
default:
V_98 |= F_38 ( & V_93 -> V_113 , 0 ) ;
break;
}
V_98 |= F_38 ( & V_93 -> V_117 , V_93 -> V_97 ) ;
if ( V_93 -> V_110 == V_111 )
V_98 |= F_38 ( & V_93 -> V_118 , 0 ) ;
if ( V_98 )
return 3 ;
if ( V_93 -> V_105 == V_102 ) {
V_99 = V_93 -> V_113 ;
F_18 ( & V_93 -> V_113 , V_93 -> V_35 ) ;
if ( V_99 != V_93 -> V_113 )
V_98 ++ ;
}
if ( V_98 )
return 4 ;
if ( V_93 -> V_95 && V_93 -> V_97 > 0 )
V_98 |= F_34 ( V_2 , V_55 , V_93 ) ;
if ( V_98 )
return 5 ;
return 0 ;
}
static void F_44 ( struct V_1 * V_2 ,
struct V_54 * V_55 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
unsigned long V_27 ;
unsigned char V_119 ;
int V_120 ;
struct V_92 * V_93 ;
F_9 ( & V_6 -> V_121 , V_27 ) ;
V_120 = F_45 ( V_122 , & V_6 -> V_123 ) ;
F_10 ( & V_6 -> V_121 , V_27 ) ;
if ( ! V_120 )
return;
V_93 = & V_55 -> V_124 -> V_93 ;
if ( V_93 -> V_105 == V_102 ) {
F_24 ( V_2 , 1 ) ;
}
if ( V_6 -> V_80 < 2 ) {
V_119 = V_125 ;
} else {
V_119 = V_126 ;
}
F_9 ( & V_6 -> V_127 , V_27 ) ;
V_6 -> V_128 &= ~ V_119 ;
while ( V_6 -> V_129 && V_6 -> V_130 != V_131 ) {
F_10 ( & V_6 -> V_127 , V_27 ) ;
F_9 ( & V_6 -> V_127 , V_27 ) ;
}
if ( V_6 -> V_132 != V_6 -> V_128 ) {
V_6 -> V_132 = V_6 -> V_128 ;
F_21 ( V_6 -> V_132 , V_6 -> V_50 + V_133 ) ;
}
F_10 ( & V_6 -> V_127 , V_27 ) ;
if ( V_6 -> V_80 >= 2 ) {
V_6 -> V_134 &= V_135 ;
F_6 ( V_6 -> V_134 | V_136 |
V_137 ,
V_2 -> V_9 + V_91 ) ;
}
F_14 ( V_2 , V_138 ) ;
}
static void F_46 ( struct V_1 * V_2 ,
struct V_54 * V_55 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
unsigned short V_8 ;
int V_24 , V_69 ;
struct V_139 * V_124 = V_55 -> V_124 ;
struct V_92 * V_93 = & V_124 -> V_93 ;
if ( V_93 -> V_110 == V_109 && V_6 -> V_140 == 0 )
return;
for ( V_24 = 0 ; V_24 < V_93 -> V_97 ; V_24 ++ ) {
V_69 = F_47 ( V_55 , & V_8 ) ;
if ( V_69 == 0 ) {
V_55 -> V_124 -> V_141 |= V_142 ;
F_44 ( V_2 , V_55 ) ;
F_48 ( V_2 -> V_73 , L_4 ) ;
return;
}
F_5 ( V_2 , V_8 , F_27 ( V_93 -> V_95 [ V_24 ] ) ) ;
}
V_124 -> V_141 |= V_143 | V_144 ;
if ( V_93 -> V_110 == V_109 ) {
V_6 -> V_140 -- ;
if ( V_6 -> V_140 == 0 ) {
V_124 -> V_141 |= V_145 ;
F_44 ( V_2 , V_55 ) ;
}
}
}
static int F_49 ( struct V_1 * V_2 ,
struct V_54 * V_55 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_139 * V_124 = V_55 -> V_124 ;
struct V_92 * V_93 = & V_124 -> V_93 ;
unsigned int V_146 ;
unsigned int V_147 ;
unsigned short V_148 ;
unsigned int V_24 , V_63 ;
unsigned int V_141 = 0 ;
int V_149 ;
V_148 = F_3 ( V_2 -> V_9 + V_91 ) ;
V_146 = F_50 ( V_55 ) / F_51 ( V_55 ) ;
if ( V_93 -> V_110 == V_109 ) {
if ( V_146 > V_6 -> V_140 )
V_146 = V_6 -> V_140 ;
if ( V_6 -> V_140 == 0 ) {
V_141 |= V_145 ;
}
}
if ( V_141 == 0 ) {
if ( V_148 & V_150 ) {
F_48 ( V_2 -> V_73 , L_5 ) ;
V_141 |= V_142 | V_151 ;
}
if ( ( V_146 == 0 ) &&
( ( V_148 & V_152 ) == 0 ) ) {
F_48 ( V_2 -> V_73 , L_4 ) ;
V_141 |= V_142 | V_151 ;
}
}
if ( V_141 == 0 ) {
if ( V_148 & V_153 )
V_147 = V_154 ;
else if ( V_148 & V_152 )
V_147 = V_155 ;
else if ( V_148 & V_156 )
V_147 = V_157 ;
else
V_147 = V_158 ;
V_147 /= V_93 -> V_97 ;
if ( V_146 > V_147 )
V_146 = V_147 ;
for ( V_63 = 0 ; V_63 < V_146 ; V_63 ++ ) {
for ( V_24 = 0 ; V_24 < V_93 -> V_97 ; V_24 ++ ) {
unsigned short V_13 ;
F_47 ( V_55 , & V_13 ) ;
F_7 ( V_2 , V_13 ,
F_27 ( V_93 -> V_95 [ V_24 ] ) ) ;
}
}
V_141 |= V_144 | V_143 ;
if ( V_93 -> V_110 == V_109 ) {
V_6 -> V_140 -= V_146 ;
if ( V_6 -> V_140 == 0 ) {
V_6 -> V_134 =
( V_6 -> V_134 &
~ V_159 ) |
V_160 ;
F_6 ( V_6 -> V_134 ,
V_2 -> V_9 + V_91 ) ;
}
}
V_148 = F_3 ( V_2 -> V_9 + V_91 ) ;
if ( V_148 & V_150 ) {
F_48 ( V_2 -> V_73 , L_5 ) ;
V_141 |= V_142 | V_151 ;
}
}
if ( V_141 & ( V_145 | V_151 | V_142 ) ) {
F_44 ( V_2 , V_55 ) ;
V_149 = 0 ;
} else {
V_149 = 1 ;
}
V_124 -> V_141 |= V_141 ;
return V_149 ;
}
static int F_52 ( struct V_1 * V_2 ,
struct V_54 * V_55 ,
unsigned int V_161 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
unsigned long V_27 ;
if ( V_161 )
return - V_75 ;
F_9 ( & V_6 -> V_121 , V_27 ) ;
if ( F_53 ( V_122 , & V_6 -> V_123 ) ) {
if ( V_6 -> V_80 < 2 ) {
F_10 ( & V_6 -> V_121 ,
V_27 ) ;
F_46 ( V_2 , V_55 ) ;
F_54 ( V_2 , V_55 ) ;
} else {
F_3 ( V_2 -> V_9 + V_162 ) ;
F_10 ( & V_6 -> V_121 ,
V_27 ) ;
}
F_55 ( 8 ) ;
} else {
F_10 ( & V_6 -> V_121 , V_27 ) ;
}
return 1 ;
}
static void F_56 ( struct V_1 * V_2 ,
struct V_54 * V_55 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_139 * V_124 = V_55 -> V_124 ;
struct V_92 * V_93 = & V_124 -> V_93 ;
unsigned long V_27 ;
F_57 ( V_122 , & V_6 -> V_123 ) ;
if ( V_93 -> V_110 == V_109 && V_6 -> V_140 == 0 ) {
V_124 -> V_141 |= V_145 ;
F_44 ( V_2 , V_55 ) ;
F_54 ( V_2 , V_55 ) ;
} else {
if ( V_6 -> V_80 >= 2 ) {
unsigned short V_163 ;
int V_164 ;
V_164 = F_49 ( V_2 , V_55 ) ;
F_54 ( V_2 , V_55 ) ;
if ( ! V_164 ) {
return;
}
switch ( V_93 -> V_105 ) {
case V_102 :
V_163 = V_165 ;
break;
case V_104 :
if ( ( V_93 -> V_113 & V_116 ) == 0 ) {
V_163 = V_166 ;
} else {
V_163 = V_167 ;
}
break;
case V_101 :
V_163 = V_168 ;
break;
default:
V_163 = V_169 ;
break;
}
V_6 -> V_134 =
( V_6 -> V_134 & ~ V_170 ) |
V_163 ;
F_6 ( V_6 -> V_134 , V_2 -> V_9 + V_91 ) ;
}
switch ( V_93 -> V_105 ) {
case V_102 :
if ( V_6 -> V_80 < 2 ) {
F_9 ( & V_6 -> V_127 ,
V_27 ) ;
V_6 -> V_128 |= V_125 ;
V_6 -> V_132 |= V_125 ;
F_21 ( V_6 -> V_132 ,
V_6 -> V_50 + V_133 ) ;
F_10 ( & V_6 -> V_127 ,
V_27 ) ;
}
F_21 ( F_58 ( 1 , V_171 ) ,
V_6 -> V_50 + V_172 ) ;
break;
case V_101 :
V_124 -> V_173 = F_52 ;
break;
}
if ( V_6 -> V_80 >= 2 ) {
F_9 ( & V_6 -> V_127 , V_27 ) ;
V_6 -> V_128 |= V_126 ;
V_6 -> V_132 |= V_126 ;
F_21 ( V_6 -> V_132 , V_6 -> V_50 + V_133 ) ;
F_10 ( & V_6 -> V_127 ,
V_27 ) ;
}
}
}
static int F_59 ( struct V_1 * V_2 ,
struct V_54 * V_55 ,
unsigned int V_161 )
{
struct V_92 * V_93 = & V_55 -> V_124 -> V_93 ;
if ( V_161 != V_93 -> V_100 )
return - V_75 ;
V_55 -> V_124 -> V_173 = NULL ;
F_56 ( V_2 , V_55 ) ;
return 1 ;
}
static int F_60 ( struct V_1 * V_2 , struct V_54 * V_55 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
unsigned short V_134 ;
unsigned int V_64 ;
struct V_92 * V_93 = & V_55 -> V_124 -> V_93 ;
if ( V_93 -> V_105 == V_102 ) {
if ( ! F_11 ( V_2 , V_174 , V_138 ) )
return - V_62 ;
}
if ( V_93 -> V_110 == V_109 )
V_6 -> V_140 = V_93 -> V_118 ;
else
V_6 -> V_140 = 0 ;
V_64 = F_28 ( V_93 -> V_95 [ 0 ] ) ;
V_6 -> V_14 = V_90 [ V_64 ] ;
V_134 = V_6 -> V_14 ? V_175 : V_176 ;
if ( V_6 -> V_80 >= 2 ) {
unsigned short V_177 ;
unsigned int V_24 ;
V_177 = 0 ;
for ( V_24 = 0 ; V_24 < V_93 -> V_97 ; V_24 ++ )
V_177 |= 1 << F_27 ( V_93 -> V_95 [ V_24 ] ) ;
F_6 ( V_177 , V_2 -> V_9 + V_178 ) ;
V_134 |= V_179 | V_136 |
V_137 |
V_169 | V_180 ;
}
F_6 ( V_134 , V_2 -> V_9 + V_91 ) ;
V_6 -> V_134 = V_134 & ~ ( V_136 |
V_137 ) ;
if ( V_93 -> V_105 == V_102 ) {
F_21 ( F_58 ( 1 , V_181 ) ,
V_6 -> V_50 + V_172 ) ;
F_19 ( V_2 , 1 , V_182 ,
V_93 -> V_113 ,
V_93 -> V_35 ) ;
}
V_55 -> V_124 -> V_173 = F_59 ;
return 0 ;
}
static int F_61 ( struct V_1 * V_2 ,
struct V_54 * V_55 )
{
F_44 ( V_2 , V_55 ) ;
return 0 ;
}
static int F_62 ( struct V_92 * V_93 )
{
unsigned int V_183 , V_97 ;
int V_98 = 0 ;
V_97 = V_93 -> V_97 ;
if ( V_93 -> V_97 == 0 )
V_97 = 1 ;
V_183 = V_97 * V_93 -> V_184 ;
if ( ( V_183 < V_97 ) ||
( V_183 < V_93 -> V_184 ) ) {
V_183 = V_41 ;
V_98 ++ ;
}
if ( V_93 -> V_113 < V_183 ) {
V_93 -> V_113 = V_183 ;
V_98 ++ ;
}
return ! V_98 ;
}
static int F_63 ( struct V_1 * V_2 ,
struct V_54 * V_55 ,
struct V_92 * V_93 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
unsigned int V_185 = ( V_55 -> V_72 / 2 ) - 1 ;
unsigned int V_94 = 0 ;
unsigned int V_186 = 0 ;
unsigned int V_187 = 0 ;
unsigned int V_188 = 0 ;
unsigned int V_189 = 0 ;
int V_24 ;
for ( V_24 = 0 ; V_24 < V_93 -> V_97 ; V_24 ++ ) {
unsigned int V_70 = V_93 -> V_95 [ V_24 ] ;
unsigned int V_16 = F_27 ( V_70 ) ;
unsigned int V_64 = F_28 ( V_70 ) ;
unsigned int V_65 = F_29 ( V_70 ) ;
unsigned int V_190 = V_79 [ V_64 ] ;
if ( V_65 == V_71 && V_16 >= V_185 ) {
F_30 ( V_2 -> V_73 ,
L_1 ,
V_74 , V_185 ) ;
return - V_75 ;
}
if ( V_24 > 0 ) {
if ( V_16 <= V_94 && V_189 == 0 )
V_189 = V_24 ;
if ( V_189 > 0 &&
V_93 -> V_95 [ V_24 % V_189 ] != V_70 ) {
F_30 ( V_2 -> V_73 ,
L_6 ,
V_74 ) ;
return - V_75 ;
}
if ( V_65 != V_187 ) {
F_30 ( V_2 -> V_73 ,
L_7 ,
V_74 ) ;
return - V_75 ;
}
if ( V_190 != V_188 ) {
F_30 ( V_2 -> V_73 ,
L_8 ,
V_74 ) ;
return - V_75 ;
}
if ( V_65 != V_71 && V_64 != V_186 &&
( ( V_16 ^ V_94 ) & ~ 1 ) == 0 ) {
F_30 ( V_2 -> V_73 ,
L_9 ,
V_74 ) ;
return - V_75 ;
}
}
V_94 = V_16 ;
V_186 = V_64 ;
V_187 = V_65 ;
V_188 = V_190 ;
}
if ( V_189 == 0 )
V_189 = V_93 -> V_97 ;
if ( V_93 -> V_97 % V_189 ) {
F_30 ( V_2 -> V_73 ,
L_10 , V_74 ) ;
return - V_75 ;
}
if ( V_6 -> V_80 > 0 && V_6 -> V_80 < 4 ) {
if ( V_189 > 1 && F_27 ( V_93 -> V_95 [ 0 ] ) ) {
F_64 ( V_2 -> V_73 ,
L_11 ,
V_6 -> V_80 ) ;
return - V_75 ;
}
}
return 0 ;
}
static int F_65 ( struct V_1 * V_2 ,
struct V_54 * V_55 , struct V_92 * V_93 )
{
const struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = V_2 -> V_7 ;
int V_98 = 0 ;
unsigned int V_99 ;
V_98 |= F_36 ( & V_93 -> V_100 , V_107 | V_101 ) ;
V_99 = V_191 | V_102 | V_101 ;
if ( ( V_4 -> V_192 ) || ( V_4 -> V_103 > 0 ) ) {
V_99 |= V_104 ;
}
V_98 |= F_36 ( & V_93 -> V_105 , V_99 ) ;
V_98 |= F_36 ( & V_93 -> V_106 ,
V_102 | V_101 | V_104 ) ;
V_98 |= F_36 ( & V_93 -> V_108 , V_109 ) ;
V_98 |= F_36 ( & V_93 -> V_110 , V_109 | V_111 ) ;
if ( V_98 )
return 1 ;
V_98 |= F_37 ( V_93 -> V_100 ) ;
V_98 |= F_37 ( V_93 -> V_105 ) ;
V_98 |= F_37 ( V_93 -> V_106 ) ;
V_98 |= F_37 ( V_93 -> V_110 ) ;
if ( ( V_93 -> V_105 != V_191 ) &&
( V_93 -> V_106 != V_102 ) )
V_98 |= - V_75 ;
if ( V_98 )
return 2 ;
V_98 |= F_38 ( & V_93 -> V_112 , 0 ) ;
#define F_66 3200
#define F_67 8000
#define F_68 4000
#define F_69 4294967295u
if ( V_93 -> V_106 == V_102 ) {
unsigned int V_193 ;
if ( V_6 -> V_80 == 0 ) {
if ( V_93 -> V_95 && ( V_93 -> V_97 > 0 ) ) {
if ( F_29 ( V_93 -> V_95 [ 0 ] ) == V_71 )
V_193 = F_67 ;
else
V_193 = F_66 ;
} else {
V_193 = F_66 ;
}
} else {
V_193 = F_68 ;
}
V_98 |= F_41 ( & V_93 -> V_184 ,
V_193 ) ;
V_98 |= F_42 ( & V_93 -> V_184 ,
F_69 ) ;
} else if ( V_93 -> V_106 == V_104 ) {
if ( V_93 -> V_184 & V_114 ) {
if ( V_93 -> V_184 & ~ V_114 ) {
V_93 -> V_184 = F_43 ( V_93 -> V_184 , 0 ,
~ V_114 ) ;
V_98 |= - V_75 ;
}
if ( ( V_93 -> V_184 &
( V_114 & ~ V_116 ) ) != V_115 ) {
V_93 -> V_184 = F_43 ( V_93 -> V_112 ,
( V_115 | 0 ) ,
V_114 &
~ V_116 ) ;
V_98 |= - V_75 ;
}
} else {
V_98 |= F_42 ( & V_93 -> V_184 , 1 ) ;
}
} else {
V_98 |= F_38 ( & V_93 -> V_184 , 0 ) ;
}
V_98 |= F_38 ( & V_93 -> V_117 , V_93 -> V_97 ) ;
if ( V_93 -> V_110 == V_111 )
V_98 |= F_38 ( & V_93 -> V_118 , 0 ) ;
if ( V_93 -> V_105 == V_104 ) {
if ( V_93 -> V_113 & ~ V_114 ) {
V_93 -> V_113 = F_43 ( V_93 -> V_113 , 0 ,
~ V_114 ) ;
V_98 |= - V_75 ;
}
if ( V_93 -> V_113 & V_114 & ~ V_115 ) {
V_93 -> V_113 = F_43 ( V_93 -> V_113 , 0 ,
V_114 & ~ V_115 ) ;
V_98 |= - V_75 ;
}
} else if ( V_93 -> V_105 == V_102 ) {
if ( ! F_62 ( V_93 ) )
V_98 |= - V_75 ;
} else {
V_98 |= F_38 ( & V_93 -> V_113 , 0 ) ;
}
if ( V_98 )
return 3 ;
if ( V_93 -> V_106 == V_102 ) {
V_99 = V_93 -> V_184 ;
F_18 ( & V_93 -> V_184 , V_93 -> V_35 ) ;
if ( V_99 != V_93 -> V_184 )
V_98 ++ ;
}
if ( V_93 -> V_105 == V_102 ) {
V_99 = V_93 -> V_113 ;
F_18 ( & V_93 -> V_113 , V_93 -> V_35 ) ;
if ( ! F_62 ( V_93 ) ) {
F_18 ( & V_93 -> V_113 ,
V_40 ) ;
F_62 ( V_93 ) ;
}
if ( V_99 != V_93 -> V_113 )
V_98 ++ ;
}
if ( V_98 )
return 4 ;
if ( V_93 -> V_95 && V_93 -> V_97 > 0 )
V_98 |= F_63 ( V_2 , V_55 , V_93 ) ;
if ( V_98 )
return 5 ;
return 0 ;
}
static void F_70 ( struct V_1 * V_2 ,
struct V_54 * V_55 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_92 * V_93 = & V_55 -> V_124 -> V_93 ;
unsigned int V_194 = V_93 -> V_117 ;
unsigned int V_195 ;
unsigned short V_196 ;
unsigned short V_67 ;
if ( V_93 -> V_35 & V_197 ) {
V_195 = V_194 - V_6 -> V_198 ;
} else {
if ( V_93 -> V_110 != V_109 ||
V_6 -> V_199 >= V_200 ||
V_194 >= V_200 ) {
V_195 = V_200 ;
} else {
V_195 = ( V_6 -> V_199 * V_194 ) -
V_6 -> V_198 ;
}
}
if ( V_195 >= V_200 ) {
V_196 = V_201 ;
} else {
if ( ( V_195 > 1 ) && ( V_6 -> V_80 > 0 ) ) {
if ( V_6 -> V_202 != V_195 ) {
V_6 -> V_202 = V_195 ;
F_6 ( V_195 , V_2 -> V_9 + V_203 ) ;
}
V_196 = V_204 ;
} else {
V_196 = V_205 ;
}
}
V_67 = ( V_6 -> V_67 & ~ V_206 ) | V_196 ;
if ( V_67 != V_6 -> V_67 ) {
V_6 -> V_67 = V_67 ;
F_6 ( V_67 , V_2 -> V_9 + V_60 ) ;
}
}
static int F_71 ( struct V_1 * V_2 ,
struct V_54 * V_55 ,
unsigned int V_161 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
unsigned long V_27 ;
if ( V_161 )
return - V_75 ;
F_9 ( & V_6 -> V_207 , V_27 ) ;
if ( F_53 ( V_208 , & V_6 -> V_123 ) ) {
unsigned int V_209 ;
F_20 ( V_6 -> V_50 + V_51 , 0 , 2 ,
V_78 ) ;
F_20 ( V_6 -> V_50 + V_51 , 0 , 2 ,
V_53 ) ;
if ( ( ( V_6 -> V_67 & V_210 ) ==
V_81 ) && ( V_6 -> V_80 == 0 ) ) {
V_209 = 8 ;
} else {
V_209 = 4 ;
}
F_10 ( & V_6 -> V_207 , V_27 ) ;
F_55 ( V_209 ) ;
} else {
F_10 ( & V_6 -> V_207 , V_27 ) ;
}
return 1 ;
}
static int F_72 ( struct V_1 * V_2 ,
struct V_54 * V_55 ,
unsigned int V_161 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
unsigned long V_27 ;
unsigned char V_211 ;
if ( V_161 )
return - V_75 ;
F_9 ( & V_6 -> V_207 , V_27 ) ;
if ( F_53 ( V_208 , & V_6 -> V_123 ) ) {
V_211 = F_58 ( 0 , V_181 ) ;
F_21 ( V_211 , V_6 -> V_50 + V_172 ) ;
V_211 = F_58 ( 0 , V_171 ) ;
F_21 ( V_211 , V_6 -> V_50 + V_172 ) ;
}
F_10 ( & V_6 -> V_207 , V_27 ) ;
return 1 ;
}
static void F_73 ( struct V_1 * V_2 ,
struct V_54 * V_55 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
unsigned long V_27 ;
struct V_92 * V_93 ;
int V_120 ;
F_9 ( & V_6 -> V_207 , V_27 ) ;
V_120 = F_45 ( V_208 , & V_6 -> V_123 ) ;
F_10 ( & V_6 -> V_207 , V_27 ) ;
if ( ! V_120 )
return;
V_93 = & V_55 -> V_124 -> V_93 ;
if ( V_93 -> V_106 == V_102 ) {
F_24 ( V_2 , 2 ) ;
}
if ( V_93 -> V_105 != V_191 ) {
F_24 ( V_2 , 0 ) ;
}
F_9 ( & V_6 -> V_127 , V_27 ) ;
V_6 -> V_128 &= ~ V_212 ;
while ( V_6 -> V_129 && V_6 -> V_130 != V_131 ) {
F_10 ( & V_6 -> V_127 , V_27 ) ;
F_9 ( & V_6 -> V_127 , V_27 ) ;
}
if ( V_6 -> V_132 != V_6 -> V_128 ) {
V_6 -> V_132 = V_6 -> V_128 ;
F_21 ( V_6 -> V_132 , V_6 -> V_50 + V_133 ) ;
}
F_10 ( & V_6 -> V_127 , V_27 ) ;
V_6 -> V_67 =
( V_6 -> V_67 & ( V_213 | V_210 ) ) |
V_214 ;
F_6 ( V_6 -> V_67 | V_89 ,
V_2 -> V_9 + V_60 ) ;
F_14 ( V_2 , V_215 ) ;
}
static void F_74 ( struct V_1 * V_2 ,
struct V_54 * V_55 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
unsigned long V_27 ;
unsigned short V_216 ;
struct V_139 * V_124 = V_55 -> V_124 ;
struct V_92 * V_93 = & V_124 -> V_93 ;
F_57 ( V_208 , & V_6 -> V_123 ) ;
if ( V_93 -> V_110 == V_109 && V_6 -> V_199 == 0 ) {
V_124 -> V_141 |= V_145 ;
F_73 ( V_2 , V_55 ) ;
F_54 ( V_2 , V_55 ) ;
} else {
F_9 ( & V_6 -> V_127 , V_27 ) ;
V_6 -> V_128 |= V_212 ;
V_6 -> V_132 |= V_212 ;
F_21 ( V_6 -> V_132 , V_6 -> V_50 + V_133 ) ;
F_10 ( & V_6 -> V_127 , V_27 ) ;
switch ( V_93 -> V_106 ) {
default:
V_216 = V_214 ;
break;
case V_102 :
V_216 = V_76 ;
break;
case V_104 :
if ( V_93 -> V_184 & V_115 ) {
if ( ( V_93 -> V_184 & V_116 ) == 0 ) {
V_216 = V_217 ;
} else {
V_216 = V_218 ;
}
} else {
if ( V_93 -> V_184 ) {
V_216 = V_217 ;
} else {
V_216 = V_218 ;
}
}
break;
case V_101 :
V_216 = V_76 ;
break;
}
V_6 -> V_67 =
( V_6 -> V_67 & ~ V_219 ) | V_216 ;
F_6 ( V_6 -> V_67 , V_2 -> V_9 + V_60 ) ;
if ( V_93 -> V_106 == V_101 )
V_124 -> V_173 = F_71 ;
F_70 ( V_2 , V_55 ) ;
if ( V_93 -> V_106 == V_102 ) {
unsigned char V_211 ;
if ( V_93 -> V_105 != V_191 ) {
V_211 = F_58 ( 2 , V_220 ) ;
} else {
V_211 = F_58 ( 2 , V_171 ) ;
}
F_21 ( V_211 , V_6 -> V_50 + V_172 ) ;
if ( V_93 -> V_105 != V_191 ) {
switch ( V_93 -> V_105 ) {
default:
V_211 = F_58 ( 0 , V_171 ) ;
break;
case V_104 :
V_211 = F_58 ( 0 , V_221 ) ;
break;
case V_102 :
V_211 = F_58 ( 0 , V_220 ) ;
break;
case V_101 :
V_211 = F_58 ( 0 , V_171 ) ;
break;
}
F_21 ( V_211 , V_6 -> V_50 + V_172 ) ;
switch ( V_93 -> V_105 ) {
case V_102 :
V_211 = F_58 ( 1 , V_171 ) ;
F_21 ( V_211 , V_6 -> V_50 +
V_172 ) ;
break;
case V_101 :
V_124 -> V_173 =
F_72 ;
break;
}
}
} else if ( V_93 -> V_106 != V_101 ) {
F_13 ( V_2 , V_222 , V_215 ) ;
}
}
}
static int F_75 ( struct V_1 * V_2 ,
struct V_54 * V_55 ,
unsigned int V_161 )
{
struct V_92 * V_93 = & V_55 -> V_124 -> V_93 ;
if ( V_161 != V_93 -> V_112 )
return - V_75 ;
V_55 -> V_124 -> V_173 = NULL ;
F_74 ( V_2 , V_55 ) ;
return 1 ;
}
static void F_76 ( struct V_1 * V_2 ,
struct V_54 * V_55 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_139 * V_124 = V_55 -> V_124 ;
struct V_92 * V_93 = & V_124 -> V_93 ;
unsigned int V_194 = V_93 -> V_117 ;
unsigned int V_141 = 0 ;
unsigned int V_223 ;
unsigned int V_24 ;
unsigned int V_224 ;
unsigned int V_225 ;
if ( V_93 -> V_110 != V_109 ) {
V_224 = V_200 ;
} else if ( V_6 -> V_199 == 0 ) {
V_224 = 0 ;
} else if ( ( V_6 -> V_199 > V_200 ) ||
( V_194 > V_200 ) ) {
V_224 = V_200 ;
} else {
V_224 = ( V_6 -> V_199 * V_194 ) -
V_6 -> V_198 ;
if ( V_224 > V_200 )
V_224 = V_200 ;
}
if ( V_224 == 0 )
return;
V_225 = 0 ;
for ( V_24 = 0 ; V_24 < V_224 ; V_24 ++ ) {
if ( V_225 == 0 ) {
V_223 = F_3 ( V_2 -> V_9 + V_60 ) ;
if ( V_223 & V_226 ) {
F_48 ( V_2 -> V_73 , L_12 ) ;
V_141 |= V_142 | V_151 ;
break;
} else if ( V_223 & V_61 ) {
break;
} else if ( V_223 & V_227 ) {
V_225 = V_200 ;
} else {
if ( V_6 -> V_80 > 0 ) {
V_225 =
F_3 ( V_2 -> V_9 + V_228 ) ;
if ( V_225 == 0 ) {
break;
}
} else {
V_225 = 1 ;
}
}
}
if ( F_77 ( V_55 , F_1 ( V_2 ) ) == 0 ) {
V_141 |= V_151 | V_142 ;
F_48 ( V_2 -> V_73 , L_13 ) ;
break;
}
V_225 -- ;
V_6 -> V_198 ++ ;
if ( V_6 -> V_198 == V_194 ) {
V_6 -> V_198 = 0 ;
V_6 -> V_199 -- ;
V_124 -> V_141 |= V_144 ;
}
}
if ( V_93 -> V_110 == V_109 && V_6 -> V_199 == 0 ) {
V_141 |= V_145 ;
} else {
V_141 |= V_143 ;
}
V_124 -> V_141 |= V_141 ;
if ( V_124 -> V_141 & ( V_145 | V_151 |
V_142 ) ) {
F_73 ( V_2 , V_55 ) ;
} else {
F_70 ( V_2 , V_55 ) ;
}
}
static int F_78 ( struct V_1 * V_2 , struct V_54 * V_55 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
unsigned int V_24 , V_16 , V_64 , V_229 ;
unsigned int V_21 ;
unsigned short V_67 , V_68 ;
unsigned char V_211 ;
struct V_139 * V_124 = V_55 -> V_124 ;
struct V_92 * V_93 = & V_124 -> V_93 ;
V_21 = 0 ;
V_21 |= ( 1U << V_222 ) ;
if ( V_93 -> V_105 != V_191 ) {
V_21 |= ( 1U << V_230 ) ;
if ( V_93 -> V_105 == V_102 ) {
V_21 |= ( 1U << V_174 ) ;
}
}
if ( ! F_8 ( V_2 , V_21 , V_215 ) )
return - V_62 ;
if ( V_93 -> V_110 == V_109 )
V_6 -> V_199 = V_93 -> V_118 ;
else
V_6 -> V_199 = 0 ;
V_6 -> V_198 = 0 ;
V_67 = V_77 ;
V_68 = 0 ;
if ( F_29 ( V_93 -> V_95 [ 0 ] ) == V_71 ) {
V_229 = 1 ;
V_67 |= V_81 ;
} else {
V_229 = 0 ;
V_67 |= V_82 ;
}
V_64 = F_28 ( V_93 -> V_95 [ 0 ] ) ;
V_6 -> V_12 = V_79 [ V_64 ] ;
if ( V_6 -> V_12 )
V_67 |= V_85 ;
else
V_67 |= V_86 ;
for ( V_24 = 0 ; V_24 < V_93 -> V_97 ; V_24 ++ ) {
unsigned int V_66 ;
V_16 = F_27 ( V_93 -> V_95 [ V_24 ] ) ;
V_64 = F_28 ( V_93 -> V_95 [ V_24 ] ) ;
if ( V_229 ) {
V_66 = 2 * V_16 ;
if ( V_6 -> V_80 == 0 ) {
V_68 |= 3 << V_66 ;
} else {
V_68 |= 1 << V_66 ;
}
} else {
V_66 = ( V_16 & ~ 1 ) ;
V_68 |= 1 << V_16 ;
}
V_6 -> V_83 = ( V_6 -> V_83 & ~ ( 3 << V_66 ) ) |
( V_84 [ V_64 ] << V_66 ) ;
}
F_6 ( V_68 , V_2 -> V_9 + V_87 ) ;
F_6 ( V_6 -> V_83 , V_2 -> V_9 + V_88 ) ;
F_20 ( V_6 -> V_50 + V_51 , 0 , 2 , V_53 ) ;
V_67 |= V_231 | V_76 ;
V_6 -> V_67 = V_67 ;
F_6 ( V_67 | V_89 , V_2 -> V_9 + V_60 ) ;
F_79 ( 25 , 100 ) ;
F_6 ( V_67 | V_89 , V_2 -> V_9 + V_60 ) ;
if ( V_93 -> V_106 == V_102 ) {
V_211 = F_58 ( 2 , V_181 ) ;
F_21 ( V_211 , V_6 -> V_50 + V_172 ) ;
F_19 ( V_2 , 2 , V_182 , V_93 -> V_184 ,
V_93 -> V_35 ) ;
if ( V_93 -> V_105 != V_191 ) {
V_211 = F_58 ( 0 , V_171 ) ;
F_21 ( V_211 , V_6 -> V_50 + V_172 ) ;
F_19 ( V_2 , 0 , V_53 ,
( ( T_1 ) V_93 -> V_184 *
V_93 -> V_117 ) ,
V_40 ) ;
if ( V_93 -> V_105 == V_102 ) {
V_211 = F_58 ( 1 , V_181 ) ;
F_21 ( V_211 , V_6 -> V_50 + V_172 ) ;
F_19 ( V_2 , 1 , V_182 ,
V_93 -> V_113 ,
V_93 -> V_35 ) ;
}
}
}
if ( V_93 -> V_100 == V_101 )
V_55 -> V_124 -> V_173 = F_75 ;
else
F_74 ( V_2 , V_55 ) ;
return 0 ;
}
static int F_80 ( struct V_1 * V_2 ,
struct V_54 * V_55 )
{
F_73 ( V_2 , V_55 ) ;
return 0 ;
}
static T_2 F_81 ( int V_232 , void * V_233 )
{
unsigned char V_234 , V_235 ;
struct V_1 * V_2 = (struct V_1 * ) V_233 ;
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_54 * V_55 ;
unsigned long V_27 ;
V_234 = F_82 ( V_6 -> V_50 + V_236 ) ;
if ( V_234 == V_237 )
return V_238 ;
F_9 ( & V_6 -> V_127 , V_27 ) ;
V_235 = V_6 -> V_128 & V_234 ;
V_6 -> V_132 = V_6 -> V_128 & ~ V_234 ;
F_21 ( V_6 -> V_132 , V_6 -> V_50 + V_133 ) ;
V_6 -> V_129 = 1 ;
V_6 -> V_130 = V_131 ;
F_10 ( & V_6 -> V_127 , V_27 ) ;
if ( V_235 & V_125 ) {
V_55 = V_2 -> V_239 ;
F_46 ( V_2 , V_55 ) ;
F_54 ( V_2 , V_55 ) ;
}
if ( V_235 & V_126 ) {
V_55 = V_2 -> V_239 ;
F_49 ( V_2 , V_55 ) ;
F_54 ( V_2 , V_55 ) ;
}
if ( V_235 & V_212 ) {
V_55 = V_2 -> V_240 ;
F_76 ( V_2 , V_55 ) ;
F_54 ( V_2 , V_55 ) ;
}
F_9 ( & V_6 -> V_127 , V_27 ) ;
if ( V_6 -> V_132 != V_6 -> V_128 ) {
V_6 -> V_132 = V_6 -> V_128 ;
F_21 ( V_6 -> V_132 , V_6 -> V_50 + V_133 ) ;
}
V_6 -> V_129 = 0 ;
F_10 ( & V_6 -> V_127 , V_27 ) ;
return V_241 ;
}
static bool F_83 ( const struct V_3 * V_242 ,
struct V_243 * V_243 )
{
if ( V_242 -> V_244 != V_243 -> V_245 )
return false ;
if ( V_242 -> V_103 == 0 )
return true ;
if ( F_84 ( V_243 , 3 ) < 32 )
return false ;
return true ;
}
static const struct V_3 * F_85 ( struct V_243 * V_243 )
{
unsigned int V_24 ;
for ( V_24 = 0 ; V_24 < F_86 ( V_246 ) ; V_24 ++ )
if ( F_83 ( & V_246 [ V_24 ] , V_243 ) )
return & V_246 [ V_24 ] ;
return NULL ;
}
static struct V_243 * F_87 ( struct V_1 * V_2 ,
struct V_247 * V_248 )
{
const struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_243 * V_243 = NULL ;
int V_249 = V_248 -> V_250 [ 0 ] ;
int V_251 = V_248 -> V_250 [ 1 ] ;
F_88 (pci_dev) {
if ( V_243 -> V_252 != V_253 )
continue;
if ( ( V_249 || V_251 ) &&
( V_249 != V_243 -> V_249 -> V_254 ||
V_251 != F_89 ( V_243 -> V_255 ) ) )
continue;
if ( V_4 -> V_244 == V_256 ) {
const struct V_3 * V_257 ;
V_257 = F_85 ( V_243 ) ;
if ( V_257 == NULL )
continue;
V_2 -> V_258 = V_257 ;
} else {
if ( ! F_83 ( V_4 , V_243 ) )
continue;
}
return V_243 ;
}
F_48 ( V_2 -> V_73 ,
L_14 ,
V_249 , V_251 ) ;
return NULL ;
}
static int F_90 ( struct V_1 * V_2 )
{
struct V_5 * V_6 ;
V_6 = F_91 ( V_2 , sizeof( * V_6 ) ) ;
if ( ! V_6 )
return - V_259 ;
F_92 ( & V_6 -> V_127 ) ;
F_92 ( & V_6 -> V_28 ) ;
F_92 ( & V_6 -> V_207 ) ;
F_92 ( & V_6 -> V_121 ) ;
return 0 ;
}
static int F_93 ( struct V_1 * V_2 ,
struct V_243 * V_243 )
{
const struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_54 * V_55 ;
unsigned long V_50 , V_260 ;
int V_261 ;
F_94 ( V_2 , & V_243 -> V_2 ) ;
V_2 -> V_262 = V_4 -> V_263 ;
V_261 = F_95 ( V_2 ) ;
if ( V_261 )
return V_261 ;
V_50 = F_96 ( V_243 , 2 ) ;
V_260 = F_96 ( V_243 , 3 ) ;
F_30 ( V_2 -> V_73 ,
L_15 ,
V_2 -> V_262 , V_50 , V_260 ) ;
V_6 -> V_50 = V_50 ;
V_2 -> V_9 = V_260 ;
V_6 -> V_134 = F_3 ( V_2 -> V_9 + V_91 ) & V_135 ;
if ( F_84 ( V_243 , 3 ) >= 32 ) {
unsigned short V_264 = 0 ;
V_6 -> V_80 = F_3 ( V_2 -> V_9 + V_265 ) ;
if ( V_6 -> V_80 < V_4 -> V_103 ) {
F_48 ( V_2 -> V_73 ,
L_16 ,
V_2 -> V_262 , V_6 -> V_80 ,
V_4 -> V_103 ) ;
return - V_266 ;
}
if ( V_6 -> V_80 > 0 ) {
if ( ! V_4 -> V_192 ) {
V_264 |= V_267 ;
}
if ( ( V_4 -> V_268 > 0 ) &&
( V_6 -> V_80 >= 2 ) ) {
V_264 |= V_269 ;
}
}
F_6 ( V_264 , V_2 -> V_9 + V_270 ) ;
if ( V_264 & V_269 ) {
F_6 ( V_6 -> V_134 | V_179 |
V_136 ,
V_2 -> V_9 + V_91 ) ;
F_6 ( 0 , V_2 -> V_9 + V_178 ) ;
F_6 ( V_6 -> V_134 , V_2 -> V_9 + V_91 ) ;
}
}
F_21 ( 0 , V_6 -> V_50 + V_133 ) ;
V_6 -> V_83 = 0 ;
V_6 -> V_67 = V_214 | V_82 |
V_85 ;
F_6 ( 1 << 0 , V_2 -> V_9 + V_87 ) ;
F_6 ( V_6 -> V_83 , V_2 -> V_9 + V_88 ) ;
F_6 ( V_6 -> V_67 | V_89 ,
V_2 -> V_9 + V_60 ) ;
if ( V_243 -> V_232 ) {
V_261 = F_97 ( V_243 -> V_232 , F_81 , V_271 ,
V_2 -> V_262 , V_2 ) ;
if ( V_261 == 0 )
V_2 -> V_232 = V_243 -> V_232 ;
}
V_261 = F_98 ( V_2 , 3 ) ;
if ( V_261 )
return V_261 ;
V_55 = & V_2 -> V_272 [ 0 ] ;
V_55 -> type = V_273 ;
V_55 -> V_274 = V_275 | V_276 | V_277 ;
V_55 -> V_72 = V_4 -> V_278 ;
V_55 -> V_279 = ( 1 << V_4 -> V_11 ) - 1 ;
V_55 -> V_280 = & V_281 ;
V_55 -> V_282 = F_26 ;
V_55 -> V_283 = 256 ;
if ( V_2 -> V_232 ) {
V_2 -> V_240 = V_55 ;
V_55 -> V_274 |= V_284 ;
V_55 -> V_285 = F_78 ;
V_55 -> V_286 = F_65 ;
V_55 -> V_287 = F_80 ;
}
V_55 = & V_2 -> V_272 [ 1 ] ;
if ( V_4 -> V_268 > 0 ) {
V_55 -> type = V_288 ;
V_55 -> V_274 = V_289 | V_277 ;
V_55 -> V_72 = V_4 -> V_268 ;
V_55 -> V_279 = ( 1 << V_4 -> V_15 ) - 1 ;
V_55 -> V_280 = & V_290 ;
V_55 -> V_291 = F_32 ;
V_55 -> V_282 = F_33 ;
V_55 -> V_283 = V_4 -> V_268 ;
if ( V_2 -> V_232 ) {
V_2 -> V_239 = V_55 ;
V_55 -> V_274 |= V_292 ;
V_55 -> V_285 = F_60 ;
V_55 -> V_286 = F_35 ;
V_55 -> V_287 = F_61 ;
}
} else {
V_55 -> type = V_293 ;
}
V_55 = & V_2 -> V_272 [ 2 ] ;
if ( V_4 -> V_192 ) {
V_261 = F_99 ( V_2 , V_55 , NULL ,
V_6 -> V_50 + V_294 ) ;
if ( V_261 )
return V_261 ;
} else {
V_55 -> type = V_293 ;
}
return 0 ;
}
static int F_100 ( struct V_1 * V_2 , struct V_247 * V_248 )
{
const struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_243 * V_243 ;
int V_261 ;
F_64 ( V_2 -> V_73 , L_17 ,
V_4 -> V_263 , V_248 -> V_250 [ 0 ] , V_248 -> V_250 [ 1 ] ) ;
V_261 = F_90 ( V_2 ) ;
if ( V_261 )
return V_261 ;
V_243 = F_87 ( V_2 , V_248 ) ;
if ( ! V_243 )
return - V_266 ;
return F_93 ( V_2 , V_243 ) ;
}
static int F_101 ( struct V_1 * V_2 ,
unsigned long V_295 )
{
struct V_243 * V_243 = F_102 ( V_2 ) ;
int V_261 ;
F_64 ( V_2 -> V_73 , L_18 ,
F_103 ( V_243 ) ) ;
V_261 = F_90 ( V_2 ) ;
if ( V_261 )
return V_261 ;
V_2 -> V_258 = F_85 ( V_243 ) ;
if ( V_2 -> V_258 == NULL ) {
F_48 ( V_2 -> V_73 ,
L_19 ) ;
return - V_75 ;
}
F_104 ( V_243 ) ;
return F_93 ( V_2 , V_243 ) ;
}
static void F_105 ( struct V_1 * V_2 )
{
struct V_243 * V_296 = F_102 ( V_2 ) ;
if ( V_2 -> V_232 )
F_106 ( V_2 -> V_232 , V_2 ) ;
F_107 ( V_2 ) ;
if ( V_296 )
F_108 ( V_296 ) ;
}
static int F_109 ( struct V_243 * V_2 ,
const struct V_297 * V_244 )
{
return F_110 ( V_2 , & V_298 ,
V_244 -> V_299 ) ;
}
