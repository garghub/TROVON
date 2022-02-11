static void
F_1 ( struct V_1 * V_2 , int V_3 , int V_4 ,
unsigned int V_5 )
{
unsigned short V_6 ;
V_7 -> V_8 [ V_3 ] = V_5 ;
F_2 ( 1 << V_3 , V_2 -> V_9 + V_10 ) ;
V_7 -> V_11 = F_3 ( V_7 -> V_11 , V_7 -> V_12 [ V_4 ] ,
( V_13 |
V_14 ) ) ;
F_2 ( V_7 -> V_11 | V_15 ,
V_2 -> V_9 + V_16 ) ;
V_6 = ( unsigned short ) V_5 << ( 16 - V_17 -> V_18 ) ;
if ( ( V_7 -> V_11 & V_13 ) ==
V_19 ) {
V_6 ^= 0x8000 ;
}
F_2 ( V_6 , V_2 -> V_9 + V_20 ) ;
F_4 ( V_2 -> V_9 + V_21 ) ;
}
static int
F_5 ( struct V_1 * V_2 , struct V_22 * V_23 ,
struct V_24 * V_25 , unsigned int * V_5 )
{
int V_26 ;
int V_3 , V_4 ;
V_3 = F_6 ( V_25 -> V_27 ) ;
V_4 = F_7 ( V_25 -> V_27 ) ;
for ( V_26 = 0 ; V_26 < V_25 -> V_28 ; V_26 ++ )
F_1 ( V_2 , V_3 , V_4 , V_5 [ V_26 ] ) ;
return V_26 ;
}
static int
F_8 ( struct V_1 * V_2 , struct V_22 * V_23 ,
struct V_24 * V_25 , unsigned int * V_5 )
{
int V_26 ;
int V_3 ;
V_3 = F_6 ( V_25 -> V_27 ) ;
for ( V_26 = 0 ; V_26 < V_25 -> V_28 ; V_26 ++ )
V_5 [ V_26 ] = V_7 -> V_8 [ V_3 ] ;
return V_26 ;
}
static void
F_9 ( int V_29 , unsigned int * V_30 , unsigned int * V_31 ,
unsigned int * V_32 , int V_33 )
{
F_10 ( V_29 , V_30 , V_31 , V_32 , V_33 ) ;
}
static void F_11 ( struct V_1 * V_2 ,
struct V_22 * V_23 )
{
unsigned long V_34 ;
if ( ! F_12 ( V_35 , & V_7 -> V_36 ) )
return;
F_13 ( & V_7 -> V_37 , V_34 ) ;
V_7 -> V_38 = 0 ;
F_14 ( 0 , V_7 -> V_39 + V_40 ) ;
while ( V_7 -> V_41 && V_7 -> V_42 != V_43 ) {
F_15 ( & V_7 -> V_37 , V_34 ) ;
F_13 ( & V_7 -> V_37 , V_34 ) ;
}
F_15 ( & V_7 -> V_37 , V_34 ) ;
F_2 ( 0 , V_2 -> V_9 + V_10 ) ;
V_7 -> V_11 = F_3 ( V_7 -> V_11 ,
V_44 |
V_45 ,
V_46 |
V_47 ) ;
F_2 ( V_7 -> V_11 | V_15 ,
V_2 -> V_9 + V_16 ) ;
}
static void F_16 ( struct V_1 * V_2 ,
struct V_22 * V_23 )
{
struct V_48 * V_49 = & V_23 -> V_50 -> V_49 ;
unsigned long V_34 ;
F_17 ( V_35 , & V_7 -> V_36 ) ;
if ( ! V_7 -> V_51 && V_7 -> V_52 == 0 ) {
F_11 ( V_2 , V_23 ) ;
V_23 -> V_50 -> V_53 |= V_54 ;
F_18 ( V_2 , V_23 ) ;
} else {
F_13 ( & V_7 -> V_37 , V_34 ) ;
if ( V_49 -> V_55 == V_56 )
V_7 -> V_38 = V_57 | V_58 ;
else
V_7 -> V_38 = V_58 ;
F_14 ( V_7 -> V_38 , V_7 -> V_39 + V_40 ) ;
F_15 ( & V_7 -> V_37 , V_34 ) ;
}
}
static void F_19 ( struct V_1 * V_2 ,
struct V_22 * V_23 )
{
struct V_48 * V_49 = & V_23 -> V_50 -> V_49 ;
unsigned int V_59 ;
unsigned int V_60 ;
unsigned short V_61 ;
unsigned int V_26 , V_28 ;
unsigned int V_62 ;
if ( V_49 -> V_63 ) {
V_62 = V_49 -> V_63 * sizeof( short ) ;
} else {
V_62 = sizeof( short ) ;
}
V_59 = F_20 ( V_23 -> V_50 ) / V_62 ;
if ( ! V_7 -> V_51 ) {
if ( V_59 > V_7 -> V_52 )
V_59 = V_7 -> V_52 ;
}
V_61 = F_4 ( V_2 -> V_9 + V_16 ) ;
switch ( V_61 & V_64 ) {
case V_65 :
V_60 = V_66 ;
if ( ! V_7 -> V_51 && V_7 -> V_52 == 0 ) {
F_11 ( V_2 , V_23 ) ;
V_23 -> V_50 -> V_53 |= V_54 ;
F_18 ( V_2 , V_23 ) ;
return;
}
break;
case V_67 :
V_60 = V_68 ;
break;
case V_69 :
V_60 = V_70 ;
break;
default:
V_60 = V_71 ;
break;
}
if ( V_60 >= V_68 ) {
if ( V_59 == 0 ) {
F_11 ( V_2 , V_23 ) ;
V_23 -> V_50 -> V_53 |= V_72 ;
F_21 ( V_73 L_1
L_2 , V_2 -> V_74 ) ;
}
}
if ( V_49 -> V_63 )
V_60 /= V_49 -> V_63 ;
if ( V_59 > V_60 )
V_59 = V_60 ;
for ( V_28 = 0 ; V_28 < V_59 ; V_28 ++ ) {
F_22 ( V_23 , & V_7 -> V_75 [ 0 ] ,
V_62 ) ;
for ( V_26 = 0 ; V_26 < V_49 -> V_63 ; V_26 ++ ) {
F_2 ( V_7 -> V_75 [ V_7 -> V_76 [ V_26 ] ] ,
V_2 -> V_9 + V_20 ) ;
}
}
if ( ! V_7 -> V_51 ) {
V_7 -> V_52 -= V_59 ;
if ( V_7 -> V_52 == 0 ) {
V_7 -> V_11 = F_3 ( V_7 -> V_11 ,
V_45 ,
V_47 ) ;
F_2 ( V_7 -> V_11 , V_2 -> V_9 + V_16 ) ;
}
}
if ( ( V_7 -> V_11 & V_46 ) ==
V_77 ) {
unsigned short V_78 ;
if ( V_49 -> V_79 == V_80 ) {
V_78 = V_81 ;
} else {
if ( V_49 -> V_82 & V_83 )
V_78 = V_84 ;
else
V_78 = V_85 ;
}
V_7 -> V_11 = F_3 ( V_7 -> V_11 , V_78 ,
V_46 ) ;
F_2 ( V_7 -> V_11 , V_2 -> V_9 + V_16 ) ;
}
if ( V_23 -> V_50 -> V_53 )
F_18 ( V_2 , V_23 ) ;
}
static int
F_23 ( struct V_1 * V_2 , struct V_22 * V_23 ,
unsigned int V_86 )
{
if ( V_86 != 0 )
return - V_87 ;
V_23 -> V_50 -> V_88 = V_89 ;
F_16 ( V_2 , V_23 ) ;
return 1 ;
}
static int
F_24 ( struct V_1 * V_2 , struct V_22 * V_23 ,
struct V_48 * V_49 )
{
int V_90 = 0 ;
unsigned int V_91 ;
V_91 = V_49 -> V_92 ;
V_49 -> V_92 &= V_93 | V_56 ;
if ( ! V_49 -> V_92 || V_91 != V_49 -> V_92 )
V_90 ++ ;
V_91 = V_49 -> V_79 ;
V_49 -> V_79 &= V_56 | V_80 ;
if ( ! V_49 -> V_79 || V_91 != V_49 -> V_79 )
V_90 ++ ;
V_91 = V_49 -> V_94 ;
V_49 -> V_94 &= V_95 ;
if ( ! V_49 -> V_94 || V_91 != V_49 -> V_94 )
V_90 ++ ;
V_91 = V_49 -> V_96 ;
V_49 -> V_96 &= V_97 ;
if ( ! V_49 -> V_96 || V_91 != V_49 -> V_96 )
V_90 ++ ;
V_91 = V_49 -> V_55 ;
V_49 -> V_55 &= V_97 | V_56 | V_98 ;
if ( ! V_49 -> V_55 || V_91 != V_49 -> V_55 )
V_90 ++ ;
if ( V_90 )
return 1 ;
if ( ( V_49 -> V_92 & ( V_49 -> V_92 - 1 ) ) != 0 )
V_90 ++ ;
if ( ( V_49 -> V_79 & ( V_49 -> V_79 - 1 ) ) != 0 )
V_90 ++ ;
if ( ( V_49 -> V_94 & ( V_49 -> V_94 - 1 ) ) != 0 )
V_90 ++ ;
if ( ( V_49 -> V_96 & ( V_49 -> V_96 - 1 ) ) != 0 )
V_90 ++ ;
if ( ( V_49 -> V_55 & ( V_49 -> V_55 - 1 ) ) != 0 )
V_90 ++ ;
V_91 = 0 ;
if ( V_49 -> V_92 & V_56 )
V_91 ++ ;
if ( V_49 -> V_79 & V_56 )
V_91 ++ ;
if ( V_49 -> V_55 & V_56 )
V_91 ++ ;
if ( V_91 > 1 )
V_90 ++ ;
if ( V_90 )
return 2 ;
switch ( V_49 -> V_92 ) {
case V_93 :
if ( V_49 -> V_99 != 0 ) {
V_49 -> V_99 = 0 ;
V_90 ++ ;
}
break;
case V_56 :
if ( ( V_49 -> V_99 & ~ V_100 ) != 0 ) {
V_49 -> V_99 = F_3 ( V_49 -> V_99 , 0 ,
~ V_100 ) ;
V_90 ++ ;
}
if ( ( V_49 -> V_99 & V_100 & ~ V_101 ) != 0 ) {
V_49 -> V_99 = F_3 ( V_49 -> V_99 , 0 ,
V_100 & ~ V_101 ) ;
V_90 ++ ;
}
break;
}
switch ( V_49 -> V_79 ) {
case V_80 :
if ( V_49 -> V_82 > V_102 ) {
V_49 -> V_82 = V_102 ;
V_90 ++ ;
}
V_91 = V_49 -> V_63 * V_103 ;
if ( V_91 < V_104 )
V_91 = V_104 ;
if ( V_49 -> V_82 < V_91 ) {
V_49 -> V_82 = V_91 ;
V_90 ++ ;
}
break;
case V_56 :
if ( ( V_49 -> V_82 & ~ V_100 ) != 0 ) {
V_49 -> V_82 = F_3 ( V_49 -> V_82 , 0 ,
~ V_100 ) ;
V_90 ++ ;
}
if ( ( V_49 -> V_82 & V_100 &
~ ( V_101 | V_83 ) ) != 0 ) {
V_49 -> V_82 = F_3 ( V_49 -> V_82 , 0 ,
V_100 & ~ ( V_101
|
V_83 ) ) ;
V_90 ++ ;
}
break;
}
if ( V_49 -> V_105 != 0 ) {
V_49 -> V_105 = 0 ;
V_90 ++ ;
}
if ( V_49 -> V_106 != V_49 -> V_63 ) {
V_49 -> V_106 = V_49 -> V_63 ;
V_90 ++ ;
}
switch ( V_49 -> V_55 ) {
case V_97 :
break;
case V_56 :
if ( ( V_49 -> V_107 & ~ V_100 ) != 0 ) {
V_49 -> V_107 = F_3 ( V_49 -> V_107 , 0 ,
~ V_100 ) ;
V_90 ++ ;
}
if ( ( V_49 -> V_107 & V_100 & ~ V_101 ) != 0 ) {
V_49 -> V_107 = F_3 ( V_49 -> V_107 , 0 ,
V_100 & ~ V_101 ) ;
}
break;
case V_98 :
if ( V_49 -> V_107 != 0 ) {
V_49 -> V_107 = 0 ;
V_90 ++ ;
}
break;
}
if ( V_90 )
return 3 ;
if ( V_49 -> V_79 == V_80 ) {
unsigned int V_108 , V_109 , V_110 ;
int V_33 = V_49 -> V_34 & V_111 ;
V_91 = V_49 -> V_82 ;
switch ( V_33 ) {
case V_112 :
default:
V_110 = V_113 / 2 ;
break;
case V_114 :
V_110 = 0 ;
break;
case V_115 :
V_110 = V_113 - 1 ;
break;
}
V_109 = V_49 -> V_82 / V_113 ;
V_109 += ( V_110 + V_49 -> V_82 % V_113 ) /
V_113 ;
if ( V_109 <= 0x10000 ) {
if ( V_109 < 2 )
V_109 = 2 ;
V_49 -> V_82 = V_109 * V_113 ;
if ( V_49 -> V_82 < V_109 ||
V_49 -> V_82 < V_113 ) {
V_49 -> V_82 = V_102 ;
}
} else {
V_108 = V_7 -> V_116 ;
V_109 = V_7 -> V_117 ;
F_9 ( V_113 , & V_108 , & V_109 ,
& V_49 -> V_82 ,
V_33 ) ;
V_7 -> V_116 = V_108 ;
V_7 -> V_117 = V_109 ;
}
if ( V_91 != V_49 -> V_82 )
V_90 ++ ;
}
if ( V_90 )
return 4 ;
if ( V_49 -> V_118 && ( V_49 -> V_63 > 0 ) ) {
unsigned int V_4 ;
enum { V_119 = 1 , V_120 = 2 , };
unsigned V_121 ;
unsigned int V_28 ;
unsigned int V_122 ;
V_4 = F_7 ( V_49 -> V_118 [ 0 ] ) ;
V_121 = 0 ;
V_91 = 0 ;
for ( V_28 = 0 ; V_28 < V_49 -> V_63 ; V_28 ++ ) {
V_122 = F_6 ( V_49 -> V_118 [ V_28 ] ) ;
if ( V_91 & ( 1U << V_122 ) )
V_121 |= V_120 ;
V_91 |= ( 1U << V_122 ) ;
if ( F_7 ( V_49 -> V_118 [ V_28 ] ) != V_4 )
V_121 |= V_119 ;
}
if ( V_121 ) {
if ( V_121 & V_120 ) {
F_25 ( L_1 V_123
L_3
L_4
L_5 , V_2 -> V_74 ) ;
}
if ( V_121 & V_119 ) {
F_25 ( L_1 V_123
L_3
L_6
L_7 , V_2 -> V_74 ) ;
}
V_90 ++ ;
}
}
if ( V_90 )
return 5 ;
return 0 ;
}
static int F_26 ( struct V_1 * V_2 , struct V_22 * V_23 )
{
struct V_48 * V_49 = & V_23 -> V_50 -> V_49 ;
int V_4 ;
unsigned int V_26 , V_124 ;
unsigned int V_122 ;
unsigned int V_125 ;
unsigned long V_34 ;
if ( V_49 -> V_118 == NULL || V_49 -> V_63 == 0 )
return - V_87 ;
V_7 -> V_126 = 0 ;
for ( V_26 = 0 ; V_26 < V_49 -> V_63 ; V_26 ++ ) {
V_122 = F_6 ( V_49 -> V_118 [ V_26 ] ) ;
V_7 -> V_126 |= 1U << V_122 ;
V_125 = 0 ;
for ( V_124 = 0 ; V_124 < V_49 -> V_63 ; V_124 ++ ) {
if ( F_6 ( V_49 -> V_118 [ V_124 ] ) < V_122 )
V_125 ++ ;
}
V_7 -> V_76 [ V_125 ] = V_26 ;
}
F_2 ( V_7 -> V_126 , V_2 -> V_9 + V_10 ) ;
V_4 = F_7 ( V_49 -> V_118 [ 0 ] ) ;
V_7 -> V_11 = F_3 ( V_7 -> V_11 ,
( V_7 ->
V_12 [ V_4 ] | V_77 |
V_127 ) ,
( V_13 |
V_14 |
V_46 |
V_47 ) ) ;
F_2 ( V_7 -> V_11 | V_15 ,
V_2 -> V_9 + V_16 ) ;
if ( V_49 -> V_79 == V_80 ) {
unsigned int V_108 , V_109 , V_110 ;
unsigned int V_128 = V_49 -> V_82 ;
int V_33 = V_49 -> V_34 & V_111 ;
switch ( V_33 ) {
case V_112 :
default:
V_110 = V_113 / 2 ;
break;
case V_114 :
V_110 = 0 ;
break;
case V_115 :
V_110 = V_113 - 1 ;
break;
}
V_109 = V_49 -> V_82 / V_113 ;
V_109 += ( V_110 + V_49 -> V_82 % V_113 ) /
V_113 ;
if ( V_109 <= 0x10000 ) {
if ( V_109 < 2 )
V_109 = 2 ;
V_109 &= 0xffff ;
V_108 = 1 ;
} else {
V_108 = V_7 -> V_116 ;
V_109 = V_7 -> V_117 ;
F_9 ( V_113 , & V_108 , & V_109 ,
& V_128 , V_33 ) ;
}
F_14 ( F_27 ( 0 , V_129 ) ,
V_7 -> V_39 + V_130 ) ;
if ( V_108 == 1 ) {
F_14 ( F_28 ( 0 , V_131 ) ,
V_7 -> V_39 + V_132 ) ;
} else {
F_14 ( F_27 ( 2 , V_129 ) ,
V_7 -> V_39 + V_130 ) ;
F_14 ( F_28 ( 2 , V_131 ) ,
V_7 -> V_39 + V_132 ) ;
F_29 ( V_7 -> V_39 + V_133 , 0 ,
2 , V_108 , 2 ) ;
F_14 ( F_28 ( 0 , V_134 ) ,
V_7 -> V_39 + V_132 ) ;
}
F_29 ( V_7 -> V_39 + V_133 , 0 , 0 , V_109 , 2 ) ;
}
switch ( V_49 -> V_55 ) {
case V_97 :
V_7 -> V_51 = 0 ;
V_7 -> V_52 = V_49 -> V_107 ;
break;
default:
V_7 -> V_51 = 1 ;
V_7 -> V_52 = 0 ;
break;
}
switch ( V_49 -> V_92 ) {
case V_93 :
F_13 ( & V_7 -> V_37 , V_34 ) ;
V_23 -> V_50 -> V_88 = & F_23 ;
F_15 ( & V_7 -> V_37 , V_34 ) ;
break;
case V_56 :
F_13 ( & V_7 -> V_37 , V_34 ) ;
V_7 -> V_38 |= V_57 ;
F_14 ( V_7 -> V_38 , V_7 -> V_39 + V_40 ) ;
F_15 ( & V_7 -> V_37 , V_34 ) ;
break;
}
return 0 ;
}
static int F_30 ( struct V_1 * V_2 ,
struct V_22 * V_23 )
{
F_11 ( V_2 , V_23 ) ;
return 0 ;
}
static void
F_31 ( struct V_1 * V_2 , struct V_22 * V_23 ,
void * V_5 , unsigned int V_135 , unsigned int V_136 )
{
struct V_137 * V_50 = V_23 -> V_50 ;
short * V_138 = V_5 ;
unsigned int V_139 = V_135 / sizeof( * V_138 ) ;
unsigned int V_140 ;
unsigned int V_141 ;
unsigned int V_26 ;
V_141 = 16 - V_17 -> V_18 ;
if ( ( V_7 -> V_12 [ F_7 ( V_50 -> V_49 . V_118 [ 0 ] ) ] &
V_13 ) == V_142 ) {
V_140 = 0 ;
} else {
V_140 = 32768 ;
}
for ( V_26 = 0 ; V_26 < V_139 ; V_26 ++ )
V_138 [ V_26 ] = ( V_138 [ V_26 ] << V_141 ) - V_140 ;
}
static T_1 F_32 ( int V_143 , void * V_144 )
{
struct V_1 * V_2 = V_144 ;
struct V_22 * V_23 = & V_2 -> V_145 [ 0 ] ;
struct V_48 * V_49 ;
unsigned char V_146 , V_147 ;
unsigned char V_148 ;
int V_149 = 0 ;
unsigned long V_34 ;
V_146 = F_33 ( V_7 -> V_39 + V_40 ) & 0x3F ;
if ( V_146 ) {
V_149 = 1 ;
F_13 ( & V_7 -> V_37 , V_34 ) ;
V_147 = V_7 -> V_38 & V_146 ;
V_148 = V_7 -> V_38 & ~ V_146 ;
F_14 ( V_148 , V_7 -> V_39 + V_40 ) ;
V_7 -> V_41 = 1 ;
V_7 -> V_42 = V_43 ;
F_15 ( & V_7 -> V_37 , V_34 ) ;
if ( V_147 != 0 ) {
V_49 = & V_23 -> V_50 -> V_49 ;
if ( V_147 & V_57 ) {
V_7 -> V_38 &= ~ V_57 ;
if ( V_49 -> V_92 == V_56 )
F_16 ( V_2 , V_23 ) ;
else if ( V_49 -> V_55 == V_56 )
F_11 ( V_2 , V_23 ) ;
}
if ( V_147 & V_58 )
F_19 ( V_2 , V_23 ) ;
}
F_13 ( & V_7 -> V_37 , V_34 ) ;
if ( V_148 != V_7 -> V_38 ) {
F_14 ( V_7 -> V_38 ,
V_7 -> V_39 + V_40 ) ;
}
V_7 -> V_41 = 0 ;
F_15 ( & V_7 -> V_37 , V_34 ) ;
}
return F_34 ( V_149 ) ;
}
static const struct V_150
* F_35 ( struct V_151 * V_151 )
{
int V_26 ;
for ( V_26 = 0 ; V_26 < F_36 ( V_152 ) ; V_26 ++ )
if ( V_151 -> V_153 == V_152 [ V_26 ] . V_154 )
return & V_152 [ V_26 ] ;
return NULL ;
}
static int
F_37 ( struct V_1 * V_2 , int V_155 , int V_156 ,
struct V_151 * * V_157 )
{
struct V_151 * V_151 = NULL ;
* V_157 = NULL ;
for ( V_151 = F_38 ( V_158 , V_159 , NULL ) ;
V_151 != NULL ;
V_151 = F_38 ( V_158 , V_159 ,
V_151 ) ) {
if ( V_155 || V_156 ) {
if ( V_155 != V_151 -> V_155 -> V_160
|| V_156 != F_39 ( V_151 -> V_161 ) )
continue;
}
if ( V_17 -> V_162 == V_163 ) {
const struct V_150 * V_164 ;
V_164 = F_35 ( V_151 ) ;
if ( V_164 == NULL )
continue;
V_2 -> V_164 = V_164 ;
} else {
if ( V_17 -> V_154 != V_151 -> V_153 )
continue;
}
* V_157 = V_151 ;
return 0 ;
}
if ( V_155 || V_156 ) {
F_21 ( V_73 L_8
L_9 ,
V_2 -> V_74 , V_17 -> V_165 , V_155 , V_156 ) ;
} else {
F_21 ( V_73 L_10 ,
V_2 -> V_74 , V_17 -> V_165 ) ;
}
return - V_166 ;
}
static int F_40 ( struct V_1 * V_2 ,
struct V_151 * V_151 , int * V_167 )
{
struct V_22 * V_23 ;
unsigned int V_143 ;
unsigned V_28 ;
int V_168 ;
V_7 -> V_151 = V_151 ;
V_168 = F_41 ( V_151 , V_123 ) ;
if ( V_168 < 0 ) {
F_21 ( V_73
L_11
L_12 , V_2 -> V_74 ) ;
return V_168 ;
}
F_42 ( & V_7 -> V_37 ) ;
V_7 -> V_39 = F_43 ( V_151 , 2 ) ;
V_2 -> V_9 = F_43 ( V_151 , 3 ) ;
V_143 = V_151 -> V_143 ;
V_7 -> V_8 = F_44 ( sizeof( V_7 -> V_8 [ 0 ] ) *
V_17 -> V_169 , V_170 ) ;
if ( ! V_7 -> V_8 )
return - V_171 ;
V_7 -> V_75 = F_44 ( sizeof( V_7 -> V_75 [ 0 ] ) *
V_17 -> V_169 , V_170 ) ;
if ( ! V_7 -> V_75 )
return - V_171 ;
V_7 -> V_76 = F_44 ( sizeof( V_7 -> V_76 [ 0 ] ) *
V_17 -> V_169 , V_170 ) ;
if ( ! V_7 -> V_76 )
return - V_171 ;
V_7 -> V_38 = 0 ;
F_14 ( 0 , V_7 -> V_39 + V_40 ) ;
F_2 ( V_172 , V_2 -> V_9 + V_16 ) ;
F_2 ( 0 , V_2 -> V_9 + V_10 ) ;
F_2 ( 0 , V_2 -> V_9 + V_173 ) ;
V_7 -> V_11 = ( V_44 | V_19 |
V_174 |
V_45 ) ;
F_2 ( V_7 -> V_11 | V_15 ,
V_2 -> V_9 + V_16 ) ;
V_168 = F_45 ( V_2 , 1 ) ;
if ( V_168 < 0 ) {
F_21 ( V_73 L_13 ,
V_2 -> V_74 ) ;
return V_168 ;
}
V_23 = V_2 -> V_145 + 0 ;
V_23 -> type = V_175 ;
V_23 -> V_176 = V_177 | V_178 | V_179 ;
V_23 -> V_180 = V_17 -> V_169 ;
V_23 -> V_181 = ( 1 << V_17 -> V_18 ) - 1 ;
V_23 -> V_182 = & F_5 ;
V_23 -> V_183 = & F_8 ;
V_23 -> V_184 = V_23 -> V_180 ;
V_2 -> V_185 = V_23 ;
V_23 -> V_186 = & F_26 ;
V_23 -> V_187 = & F_24 ;
V_23 -> V_188 = & F_30 ;
V_23 -> V_189 = & F_31 ;
if ( V_17 -> V_162 == V_190 ) {
const struct V_191 * * V_192 ;
V_23 -> V_192 = V_192 =
F_44 ( sizeof( struct V_191 * ) * V_23 -> V_180 ,
V_170 ) ;
if ( ! V_23 -> V_192 )
return - V_171 ;
if ( V_167 ) {
for ( V_28 = 2 ; V_28 < 3 + V_23 -> V_180 ; V_28 ++ ) {
if ( V_167 [ V_28 ] < 0 || V_167 [ V_28 ] > 1 ) {
F_21 ( V_193
L_14 ,
V_2 -> V_74 , V_123 , V_28 ,
V_167 [ V_28 ] ) ;
}
}
}
for ( V_28 = 0 ; V_28 < V_23 -> V_180 ; V_28 ++ ) {
if ( V_28 < V_194 - 3 && V_167 &&
V_167 [ 3 + V_28 ] == 1 ) {
if ( V_167 [ 2 ] == 1 )
V_192 [ V_28 ] = & V_195 ;
else
V_192 [ V_28 ] = & V_196 ;
} else {
if ( V_167 && V_167 [ 2 ] == 1 ) {
V_192 [ V_28 ] =
& V_197 ;
} else {
V_192 [ V_28 ] = & V_198 ;
}
}
}
V_7 -> V_12 = V_199 ;
} else {
if ( V_167 && V_167 [ 2 ] == 1 ) {
V_23 -> V_200 = & V_201 ;
V_7 -> V_12 = V_202 ;
} else {
if ( V_167 && V_167 [ 2 ] != 0 ) {
F_21 ( V_193 L_15
L_16 ,
V_2 -> V_74 , V_123 , V_167 [ 2 ] ) ;
}
V_23 -> V_200 = & V_203 ;
V_7 -> V_12 = V_204 ;
}
}
V_2 -> V_205 = V_17 -> V_165 ;
if ( V_143 ) {
V_168 = F_46 ( V_143 , F_32 , V_206 ,
V_123 , V_2 ) ;
if ( V_168 < 0 ) {
F_21 ( V_73 L_8
L_17 , V_2 -> V_74 , V_143 ) ;
return V_168 ;
} else {
V_2 -> V_143 = V_143 ;
}
}
F_21 ( V_207 L_18 , V_2 -> V_74 , V_2 -> V_205 ) ;
F_21 ( L_19 , F_47 ( V_151 ) ) ;
if ( V_143 )
F_21 ( L_20 , V_143 , ( V_2 -> V_143 ? L_21 : L_22 ) ) ;
else
F_21 ( L_23 ) ;
F_21 ( L_24 ) ;
return 1 ;
}
static int F_48 ( struct V_1 * V_2 , struct V_208 * V_209 )
{
struct V_151 * V_151 ;
int V_155 , V_156 ;
int V_168 ;
F_21 ( V_210 L_25 , V_2 -> V_74 , V_123 ) ;
V_155 = V_209 -> V_167 [ 0 ] ;
V_156 = V_209 -> V_167 [ 1 ] ;
V_168 = F_49 ( V_2 , sizeof( struct V_211 ) ) ;
if ( V_168 < 0 ) {
F_21 ( V_73 L_13 ,
V_2 -> V_74 ) ;
return V_168 ;
}
V_168 = F_37 ( V_2 , V_155 , V_156 , & V_151 ) ;
if ( V_168 < 0 )
return V_168 ;
return F_40 ( V_2 , V_151 , V_209 -> V_167 ) ;
}
static int
F_50 ( struct V_1 * V_2 , struct V_151 * V_151 )
{
int V_168 ;
F_21 ( V_210 L_26 , V_2 -> V_74 ,
V_123 , F_47 ( V_151 ) ) ;
V_168 = F_49 ( V_2 , sizeof( struct V_211 ) ) ;
if ( V_168 < 0 ) {
F_21 ( V_73 L_13 ,
V_2 -> V_74 ) ;
return V_168 ;
}
V_2 -> V_164 = F_35 ( V_151 ) ;
if ( V_2 -> V_164 == NULL ) {
F_21 ( V_73
L_27 ,
V_2 -> V_74 , V_123 ) ;
return - V_87 ;
}
return F_40 ( V_2 , V_151 , NULL ) ;
}
static void F_51 ( struct V_1 * V_2 )
{
if ( V_2 -> V_143 )
F_52 ( V_2 -> V_143 , V_2 ) ;
if ( V_2 -> V_145 ) {
struct V_22 * V_23 ;
V_23 = V_2 -> V_145 + 0 ;
F_53 ( V_23 -> V_192 ) ;
}
if ( V_7 ) {
F_53 ( V_7 -> V_8 ) ;
F_53 ( V_7 -> V_75 ) ;
F_53 ( V_7 -> V_76 ) ;
if ( V_7 -> V_151 ) {
if ( V_2 -> V_9 )
F_54 ( V_7 -> V_151 ) ;
F_55 ( V_7 -> V_151 ) ;
}
}
}
static int T_2 F_56 ( struct V_151 * V_2 ,
const struct V_212
* V_213 )
{
return F_57 ( V_2 , & V_214 ) ;
}
static void T_3 F_58 ( struct V_151 * V_2 )
{
F_59 ( V_2 ) ;
}
