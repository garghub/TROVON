static void
F_1 ( struct V_1 * V_2 , int V_3 , int V_4 ,
unsigned int V_5 )
{
const struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = V_2 -> V_10 ;
unsigned short V_11 ;
V_9 -> V_12 [ V_3 ] = V_5 ;
F_3 ( 1 << V_3 , V_2 -> V_13 + V_14 ) ;
V_9 -> V_15 = F_4 ( V_9 -> V_15 , V_9 -> V_16 [ V_4 ] ,
( V_17 |
V_18 ) ) ;
F_3 ( V_9 -> V_15 | V_19 ,
V_2 -> V_13 + V_20 ) ;
V_11 = ( unsigned short ) V_5 << ( 16 - V_7 -> V_21 ) ;
if ( ( V_9 -> V_15 & V_17 ) ==
V_22 ) {
V_11 ^= 0x8000 ;
}
F_3 ( V_11 , V_2 -> V_13 + V_23 ) ;
F_5 ( V_2 -> V_13 + V_24 ) ;
}
static int
F_6 ( struct V_1 * V_2 , struct V_25 * V_26 ,
struct V_27 * V_28 , unsigned int * V_5 )
{
int V_29 ;
int V_3 , V_4 ;
V_3 = F_7 ( V_28 -> V_30 ) ;
V_4 = F_8 ( V_28 -> V_30 ) ;
for ( V_29 = 0 ; V_29 < V_28 -> V_31 ; V_29 ++ )
F_1 ( V_2 , V_3 , V_4 , V_5 [ V_29 ] ) ;
return V_29 ;
}
static int
F_9 ( struct V_1 * V_2 , struct V_25 * V_26 ,
struct V_27 * V_28 , unsigned int * V_5 )
{
struct V_8 * V_9 = V_2 -> V_10 ;
int V_29 ;
int V_3 ;
V_3 = F_7 ( V_28 -> V_30 ) ;
for ( V_29 = 0 ; V_29 < V_28 -> V_31 ; V_29 ++ )
V_5 [ V_29 ] = V_9 -> V_12 [ V_3 ] ;
return V_29 ;
}
static void
F_10 ( int V_32 , unsigned int * V_33 , unsigned int * V_34 ,
unsigned int * V_35 , int V_36 )
{
F_11 ( V_32 , V_33 , V_34 , V_35 , V_36 ) ;
}
static void F_12 ( struct V_1 * V_2 ,
struct V_25 * V_26 )
{
struct V_8 * V_9 = V_2 -> V_10 ;
unsigned long V_37 ;
if ( ! F_13 ( V_38 , & V_9 -> V_39 ) )
return;
F_14 ( & V_9 -> V_40 , V_37 ) ;
V_9 -> V_41 = 0 ;
F_15 ( 0 , V_9 -> V_42 + V_43 ) ;
while ( V_9 -> V_44 && V_9 -> V_45 != V_46 ) {
F_16 ( & V_9 -> V_40 , V_37 ) ;
F_14 ( & V_9 -> V_40 , V_37 ) ;
}
F_16 ( & V_9 -> V_40 , V_37 ) ;
F_3 ( 0 , V_2 -> V_13 + V_14 ) ;
V_9 -> V_15 = F_4 ( V_9 -> V_15 ,
V_47 |
V_48 ,
V_49 |
V_50 ) ;
F_3 ( V_9 -> V_15 | V_19 ,
V_2 -> V_13 + V_20 ) ;
}
static void F_17 ( struct V_1 * V_2 ,
struct V_25 * V_26 )
{
struct V_8 * V_9 = V_2 -> V_10 ;
struct V_51 * V_52 = & V_26 -> V_53 -> V_52 ;
unsigned long V_37 ;
F_18 ( V_38 , & V_9 -> V_39 ) ;
if ( ! V_9 -> V_54 && V_9 -> V_55 == 0 ) {
F_12 ( V_2 , V_26 ) ;
V_26 -> V_53 -> V_56 |= V_57 ;
F_19 ( V_2 , V_26 ) ;
} else {
F_14 ( & V_9 -> V_40 , V_37 ) ;
if ( V_52 -> V_58 == V_59 )
V_9 -> V_41 = V_60 | V_61 ;
else
V_9 -> V_41 = V_61 ;
F_15 ( V_9 -> V_41 , V_9 -> V_42 + V_43 ) ;
F_16 ( & V_9 -> V_40 , V_37 ) ;
}
}
static void F_20 ( struct V_1 * V_2 ,
struct V_25 * V_26 )
{
struct V_8 * V_9 = V_2 -> V_10 ;
struct V_51 * V_52 = & V_26 -> V_53 -> V_52 ;
unsigned int V_62 ;
unsigned int V_63 ;
unsigned short V_64 ;
unsigned int V_29 , V_31 ;
unsigned int V_65 ;
if ( V_52 -> V_66 ) {
V_65 = V_52 -> V_66 * sizeof( short ) ;
} else {
V_65 = sizeof( short ) ;
}
V_62 = F_21 ( V_26 -> V_53 ) / V_65 ;
if ( ! V_9 -> V_54 ) {
if ( V_62 > V_9 -> V_55 )
V_62 = V_9 -> V_55 ;
}
V_64 = F_5 ( V_2 -> V_13 + V_20 ) ;
switch ( V_64 & V_67 ) {
case V_68 :
V_63 = V_69 ;
if ( ! V_9 -> V_54 && V_9 -> V_55 == 0 ) {
F_12 ( V_2 , V_26 ) ;
V_26 -> V_53 -> V_56 |= V_57 ;
F_19 ( V_2 , V_26 ) ;
return;
}
break;
case V_70 :
V_63 = V_71 ;
break;
case V_72 :
V_63 = V_73 ;
break;
default:
V_63 = V_74 ;
break;
}
if ( V_63 >= V_71 ) {
if ( V_62 == 0 ) {
F_12 ( V_2 , V_26 ) ;
V_26 -> V_53 -> V_56 |= V_75 ;
F_22 ( V_2 -> V_76 , L_1 ) ;
}
}
if ( V_52 -> V_66 )
V_63 /= V_52 -> V_66 ;
if ( V_62 > V_63 )
V_62 = V_63 ;
for ( V_31 = 0 ; V_31 < V_62 ; V_31 ++ ) {
F_23 ( V_26 , & V_9 -> V_77 [ 0 ] ,
V_65 ) ;
for ( V_29 = 0 ; V_29 < V_52 -> V_66 ; V_29 ++ ) {
F_3 ( V_9 -> V_77 [ V_9 -> V_78 [ V_29 ] ] ,
V_2 -> V_13 + V_23 ) ;
}
}
if ( ! V_9 -> V_54 ) {
V_9 -> V_55 -= V_62 ;
if ( V_9 -> V_55 == 0 ) {
V_9 -> V_15 = F_4 ( V_9 -> V_15 ,
V_48 ,
V_50 ) ;
F_3 ( V_9 -> V_15 , V_2 -> V_13 + V_20 ) ;
}
}
if ( ( V_9 -> V_15 & V_49 ) ==
V_79 ) {
unsigned short V_80 ;
if ( V_52 -> V_81 == V_82 ) {
V_80 = V_83 ;
} else {
if ( V_52 -> V_84 & V_85 )
V_80 = V_86 ;
else
V_80 = V_87 ;
}
V_9 -> V_15 = F_4 ( V_9 -> V_15 , V_80 ,
V_49 ) ;
F_3 ( V_9 -> V_15 , V_2 -> V_13 + V_20 ) ;
}
if ( V_26 -> V_53 -> V_56 )
F_19 ( V_2 , V_26 ) ;
}
static int
F_24 ( struct V_1 * V_2 , struct V_25 * V_26 ,
unsigned int V_88 )
{
if ( V_88 != 0 )
return - V_89 ;
V_26 -> V_53 -> V_90 = NULL ;
F_17 ( V_2 , V_26 ) ;
return 1 ;
}
static int
F_25 ( struct V_1 * V_2 , struct V_25 * V_26 ,
struct V_51 * V_52 )
{
struct V_8 * V_9 = V_2 -> V_10 ;
int V_91 = 0 ;
unsigned int V_92 ;
V_91 |= F_26 ( & V_52 -> V_93 , V_94 | V_59 ) ;
V_91 |= F_26 ( & V_52 -> V_81 ,
V_59 | V_82 ) ;
V_91 |= F_26 ( & V_52 -> V_95 , V_96 ) ;
V_91 |= F_26 ( & V_52 -> V_97 , V_98 ) ;
V_91 |= F_26 ( & V_52 -> V_58 ,
V_98 | V_59 | V_99 ) ;
if ( V_91 )
return 1 ;
V_91 |= F_27 ( V_52 -> V_93 ) ;
V_91 |= F_27 ( V_52 -> V_81 ) ;
V_91 |= F_27 ( V_52 -> V_58 ) ;
V_92 = 0 ;
if ( V_52 -> V_93 & V_59 )
V_92 ++ ;
if ( V_52 -> V_81 & V_59 )
V_92 ++ ;
if ( V_52 -> V_58 & V_59 )
V_92 ++ ;
if ( V_92 > 1 )
V_91 |= - V_89 ;
if ( V_91 )
return 2 ;
switch ( V_52 -> V_93 ) {
case V_94 :
V_91 |= F_28 ( & V_52 -> V_100 , 0 ) ;
break;
case V_59 :
if ( ( V_52 -> V_100 & ~ V_101 ) != 0 ) {
V_52 -> V_100 = F_4 ( V_52 -> V_100 , 0 ,
~ V_101 ) ;
V_91 |= - V_89 ;
}
if ( ( V_52 -> V_100 & V_101 & ~ V_102 ) != 0 ) {
V_52 -> V_100 = F_4 ( V_52 -> V_100 , 0 ,
V_101 & ~ V_102 ) ;
V_91 |= - V_89 ;
}
break;
}
switch ( V_52 -> V_81 ) {
case V_82 :
V_91 |= F_29 ( & V_52 -> V_84 ,
V_103 ) ;
V_92 = V_52 -> V_66 * V_104 ;
if ( V_92 < V_105 )
V_92 = V_105 ;
V_91 |= F_30 ( & V_52 -> V_84 , V_92 ) ;
break;
case V_59 :
if ( ( V_52 -> V_84 & ~ V_101 ) != 0 ) {
V_52 -> V_84 = F_4 ( V_52 -> V_84 , 0 ,
~ V_101 ) ;
V_91 |= - V_89 ;
}
if ( ( V_52 -> V_84 & V_101 &
~ ( V_102 | V_85 ) ) != 0 ) {
V_52 -> V_84 = F_4 ( V_52 -> V_84 , 0 ,
V_101 &
~ ( V_102 | V_85 ) ) ;
V_91 |= - V_89 ;
}
break;
}
V_91 |= F_28 ( & V_52 -> V_106 , 0 ) ;
V_91 |= F_28 ( & V_52 -> V_107 , V_52 -> V_66 ) ;
switch ( V_52 -> V_58 ) {
case V_98 :
break;
case V_59 :
if ( ( V_52 -> V_108 & ~ V_101 ) != 0 ) {
V_52 -> V_108 = F_4 ( V_52 -> V_108 , 0 ,
~ V_101 ) ;
V_91 |= - V_89 ;
}
if ( ( V_52 -> V_108 & V_101 & ~ V_102 ) != 0 ) {
V_52 -> V_108 = F_4 ( V_52 -> V_108 , 0 ,
V_101 & ~ V_102 ) ;
}
break;
case V_99 :
V_91 |= F_28 ( & V_52 -> V_108 , 0 ) ;
break;
}
if ( V_91 )
return 3 ;
if ( V_52 -> V_81 == V_82 ) {
unsigned int V_109 , V_110 , V_111 ;
int V_36 = V_52 -> V_37 & V_112 ;
V_92 = V_52 -> V_84 ;
switch ( V_36 ) {
case V_113 :
default:
V_111 = V_114 / 2 ;
break;
case V_115 :
V_111 = 0 ;
break;
case V_116 :
V_111 = V_114 - 1 ;
break;
}
V_110 = V_52 -> V_84 / V_114 ;
V_110 += ( V_111 + V_52 -> V_84 % V_114 ) /
V_114 ;
if ( V_110 <= 0x10000 ) {
if ( V_110 < 2 )
V_110 = 2 ;
V_52 -> V_84 = V_110 * V_114 ;
if ( V_52 -> V_84 < V_110 ||
V_52 -> V_84 < V_114 ) {
V_52 -> V_84 = V_103 ;
}
} else {
V_109 = V_9 -> V_117 ;
V_110 = V_9 -> V_118 ;
F_10 ( V_114 ,
& V_109 , & V_110 ,
& V_52 -> V_84 ,
V_36 ) ;
V_9 -> V_117 = V_109 ;
V_9 -> V_118 = V_110 ;
}
if ( V_92 != V_52 -> V_84 )
V_91 ++ ;
}
if ( V_91 )
return 4 ;
if ( V_52 -> V_119 && ( V_52 -> V_66 > 0 ) ) {
unsigned int V_4 ;
enum { V_120 = 1 , V_121 = 2 , };
unsigned V_122 ;
unsigned int V_31 ;
unsigned int V_123 ;
V_4 = F_8 ( V_52 -> V_119 [ 0 ] ) ;
V_122 = 0 ;
V_92 = 0 ;
for ( V_31 = 0 ; V_31 < V_52 -> V_66 ; V_31 ++ ) {
V_123 = F_7 ( V_52 -> V_119 [ V_31 ] ) ;
if ( V_92 & ( 1U << V_123 ) )
V_122 |= V_121 ;
V_92 |= ( 1U << V_123 ) ;
if ( F_8 ( V_52 -> V_119 [ V_31 ] ) != V_4 )
V_122 |= V_120 ;
}
if ( V_122 ) {
if ( V_122 & V_121 ) {
F_31 ( V_2 -> V_76 ,
L_2 ,
V_124 ) ;
}
if ( V_122 & V_120 ) {
F_31 ( V_2 -> V_76 ,
L_3 ,
V_124 ) ;
}
V_91 ++ ;
}
}
if ( V_91 )
return 5 ;
return 0 ;
}
static int F_32 ( struct V_1 * V_2 , struct V_25 * V_26 )
{
struct V_8 * V_9 = V_2 -> V_10 ;
struct V_51 * V_52 = & V_26 -> V_53 -> V_52 ;
int V_4 ;
unsigned int V_29 , V_125 ;
unsigned int V_123 ;
unsigned int V_126 ;
unsigned long V_37 ;
if ( V_52 -> V_119 == NULL || V_52 -> V_66 == 0 )
return - V_89 ;
V_9 -> V_127 = 0 ;
for ( V_29 = 0 ; V_29 < V_52 -> V_66 ; V_29 ++ ) {
V_123 = F_7 ( V_52 -> V_119 [ V_29 ] ) ;
V_9 -> V_127 |= 1U << V_123 ;
V_126 = 0 ;
for ( V_125 = 0 ; V_125 < V_52 -> V_66 ; V_125 ++ ) {
if ( F_7 ( V_52 -> V_119 [ V_125 ] ) < V_123 )
V_126 ++ ;
}
V_9 -> V_78 [ V_126 ] = V_29 ;
}
F_3 ( V_9 -> V_127 , V_2 -> V_13 + V_14 ) ;
V_4 = F_8 ( V_52 -> V_119 [ 0 ] ) ;
V_9 -> V_15 = F_4 ( V_9 -> V_15 ,
( V_9 ->
V_16 [ V_4 ] | V_79 |
V_128 ) ,
( V_17 |
V_18 |
V_49 |
V_50 ) ) ;
F_3 ( V_9 -> V_15 | V_19 ,
V_2 -> V_13 + V_20 ) ;
if ( V_52 -> V_81 == V_82 ) {
unsigned int V_109 , V_110 , V_111 ;
unsigned int V_129 = V_52 -> V_84 ;
int V_36 = V_52 -> V_37 & V_112 ;
switch ( V_36 ) {
case V_113 :
default:
V_111 = V_114 / 2 ;
break;
case V_115 :
V_111 = 0 ;
break;
case V_116 :
V_111 = V_114 - 1 ;
break;
}
V_110 = V_52 -> V_84 / V_114 ;
V_110 += ( V_111 + V_52 -> V_84 % V_114 ) /
V_114 ;
if ( V_110 <= 0x10000 ) {
if ( V_110 < 2 )
V_110 = 2 ;
V_110 &= 0xffff ;
V_109 = 1 ;
} else {
V_109 = V_9 -> V_117 ;
V_110 = V_9 -> V_118 ;
F_10 ( V_114 ,
& V_109 , & V_110 ,
& V_129 , V_36 ) ;
}
F_15 ( F_33 ( 0 , V_130 ) ,
V_9 -> V_42 + V_131 ) ;
if ( V_109 == 1 ) {
F_15 ( F_34 ( 0 , V_132 ) ,
V_9 -> V_42 + V_133 ) ;
} else {
F_15 ( F_33 ( 2 , V_130 ) ,
V_9 -> V_42 + V_131 ) ;
F_15 ( F_34 ( 2 , V_132 ) ,
V_9 -> V_42 + V_133 ) ;
F_35 ( V_9 -> V_42 + V_134 , 0 ,
2 , V_109 , 2 ) ;
F_15 ( F_34 ( 0 , V_135 ) ,
V_9 -> V_42 + V_133 ) ;
}
F_35 ( V_9 -> V_42 + V_134 , 0 , 0 , V_110 , 2 ) ;
}
switch ( V_52 -> V_58 ) {
case V_98 :
V_9 -> V_54 = 0 ;
V_9 -> V_55 = V_52 -> V_108 ;
break;
default:
V_9 -> V_54 = 1 ;
V_9 -> V_55 = 0 ;
break;
}
switch ( V_52 -> V_93 ) {
case V_94 :
F_14 ( & V_9 -> V_40 , V_37 ) ;
V_26 -> V_53 -> V_90 = & F_24 ;
F_16 ( & V_9 -> V_40 , V_37 ) ;
break;
case V_59 :
F_14 ( & V_9 -> V_40 , V_37 ) ;
V_9 -> V_41 |= V_60 ;
F_15 ( V_9 -> V_41 , V_9 -> V_42 + V_43 ) ;
F_16 ( & V_9 -> V_40 , V_37 ) ;
break;
}
return 0 ;
}
static int F_36 ( struct V_1 * V_2 ,
struct V_25 * V_26 )
{
F_12 ( V_2 , V_26 ) ;
return 0 ;
}
static void
F_37 ( struct V_1 * V_2 , struct V_25 * V_26 ,
void * V_5 , unsigned int V_136 , unsigned int V_137 )
{
const struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = V_2 -> V_10 ;
struct V_138 * V_53 = V_26 -> V_53 ;
unsigned short * V_139 = V_5 ;
unsigned int V_140 = V_136 / sizeof( * V_139 ) ;
unsigned int V_141 ;
unsigned int V_142 ;
unsigned int V_29 ;
V_142 = 16 - V_7 -> V_21 ;
if ( ( V_9 -> V_16 [ F_8 ( V_53 -> V_52 . V_119 [ 0 ] ) ] &
V_17 ) == V_143 ) {
V_141 = 0 ;
} else {
V_141 = 32768 ;
}
for ( V_29 = 0 ; V_29 < V_140 ; V_29 ++ )
V_139 [ V_29 ] = ( V_139 [ V_29 ] << V_142 ) - V_141 ;
}
static T_1 F_38 ( int V_144 , void * V_145 )
{
struct V_1 * V_2 = V_145 ;
struct V_8 * V_9 = V_2 -> V_10 ;
struct V_25 * V_26 = V_2 -> V_146 ;
struct V_51 * V_52 ;
unsigned char V_147 , V_148 ;
unsigned char V_149 ;
int V_150 = 0 ;
unsigned long V_37 ;
V_147 = F_39 ( V_9 -> V_42 + V_43 ) & 0x3F ;
if ( V_147 ) {
V_150 = 1 ;
F_14 ( & V_9 -> V_40 , V_37 ) ;
V_148 = V_9 -> V_41 & V_147 ;
V_149 = V_9 -> V_41 & ~ V_147 ;
F_15 ( V_149 , V_9 -> V_42 + V_43 ) ;
V_9 -> V_44 = 1 ;
V_9 -> V_45 = V_46 ;
F_16 ( & V_9 -> V_40 , V_37 ) ;
if ( V_148 != 0 ) {
V_52 = & V_26 -> V_53 -> V_52 ;
if ( V_148 & V_60 ) {
V_9 -> V_41 &= ~ V_60 ;
if ( V_52 -> V_93 == V_59 )
F_17 ( V_2 , V_26 ) ;
else if ( V_52 -> V_58 == V_59 )
F_12 ( V_2 , V_26 ) ;
}
if ( V_148 & V_61 )
F_20 ( V_2 , V_26 ) ;
}
F_14 ( & V_9 -> V_40 , V_37 ) ;
if ( V_149 != V_9 -> V_41 ) {
F_15 ( V_9 -> V_41 ,
V_9 -> V_42 + V_43 ) ;
}
V_9 -> V_44 = 0 ;
F_16 ( & V_9 -> V_40 , V_37 ) ;
}
return F_40 ( V_150 ) ;
}
static const struct V_6
* F_41 ( struct V_151 * V_151 )
{
int V_29 ;
for ( V_29 = 0 ; V_29 < F_42 ( V_152 ) ; V_29 ++ )
if ( V_151 -> V_153 == V_152 [ V_29 ] . V_154 )
return & V_152 [ V_29 ] ;
return NULL ;
}
static struct V_151 * F_43 ( struct V_1 * V_2 ,
struct V_155 * V_156 )
{
const struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_151 * V_151 = NULL ;
int V_157 = V_156 -> V_158 [ 0 ] ;
int V_159 = V_156 -> V_158 [ 1 ] ;
F_44 (pci_dev) {
if ( V_157 || V_159 ) {
if ( V_157 != V_151 -> V_157 -> V_160 ||
V_159 != F_45 ( V_151 -> V_161 ) )
continue;
}
if ( V_151 -> V_162 != V_163 )
continue;
if ( V_7 -> V_164 == V_165 ) {
const struct V_6 * V_166 ;
V_166 = F_41 ( V_151 ) ;
if ( V_166 == NULL )
continue;
V_2 -> V_166 = V_166 ;
} else {
if ( V_7 -> V_154 != V_151 -> V_153 )
continue;
}
return V_151 ;
}
F_22 ( V_2 -> V_76 ,
L_4 ,
V_157 , V_159 ) ;
return NULL ;
}
static void F_46 ( struct V_1 * V_2 , unsigned int V_144 )
{
struct V_151 * V_167 = F_47 ( V_2 ) ;
char V_168 [ 30 ] ;
if ( V_144 )
snprintf ( V_168 , sizeof( V_168 ) , L_5 , V_144 ,
( V_2 -> V_144 ? L_6 : L_7 ) ) ;
else
snprintf ( V_168 , sizeof( V_168 ) , L_8 ) ;
F_48 ( V_2 -> V_76 , L_9 ,
V_2 -> V_169 , F_49 ( V_167 ) , V_168 ) ;
}
static int F_50 ( struct V_1 * V_2 ,
struct V_151 * V_151 , int * V_158 )
{
const struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = V_2 -> V_10 ;
struct V_25 * V_26 ;
unsigned int V_144 ;
unsigned V_31 ;
int V_170 ;
F_51 ( V_2 , & V_151 -> V_2 ) ;
V_170 = F_52 ( V_2 ) ;
if ( V_170 )
return V_170 ;
F_53 ( & V_9 -> V_40 ) ;
V_9 -> V_42 = F_54 ( V_151 , 2 ) ;
V_2 -> V_13 = F_54 ( V_151 , 3 ) ;
V_144 = V_151 -> V_144 ;
V_9 -> V_12 = F_55 ( sizeof( V_9 -> V_12 [ 0 ] ) *
V_7 -> V_171 , V_172 ) ;
if ( ! V_9 -> V_12 )
return - V_173 ;
V_9 -> V_77 = F_55 ( sizeof( V_9 -> V_77 [ 0 ] ) *
V_7 -> V_171 , V_172 ) ;
if ( ! V_9 -> V_77 )
return - V_173 ;
V_9 -> V_78 = F_55 ( sizeof( V_9 -> V_78 [ 0 ] ) *
V_7 -> V_171 , V_172 ) ;
if ( ! V_9 -> V_78 )
return - V_173 ;
V_9 -> V_41 = 0 ;
F_15 ( 0 , V_9 -> V_42 + V_43 ) ;
F_3 ( V_174 , V_2 -> V_13 + V_20 ) ;
F_3 ( 0 , V_2 -> V_13 + V_14 ) ;
F_3 ( 0 , V_2 -> V_13 + V_175 ) ;
V_9 -> V_15 = ( V_47 | V_22 |
V_176 |
V_48 ) ;
F_3 ( V_9 -> V_15 | V_19 ,
V_2 -> V_13 + V_20 ) ;
V_170 = F_56 ( V_2 , 1 ) ;
if ( V_170 )
return V_170 ;
V_26 = & V_2 -> V_177 [ 0 ] ;
V_26 -> type = V_178 ;
V_26 -> V_179 = V_180 | V_181 | V_182 ;
V_26 -> V_183 = V_7 -> V_171 ;
V_26 -> V_184 = ( 1 << V_7 -> V_21 ) - 1 ;
V_26 -> V_185 = & F_6 ;
V_26 -> V_186 = & F_9 ;
V_26 -> V_187 = V_26 -> V_183 ;
V_2 -> V_146 = V_26 ;
V_26 -> V_188 = & F_32 ;
V_26 -> V_189 = & F_25 ;
V_26 -> V_190 = & F_36 ;
V_26 -> V_191 = & F_37 ;
if ( V_7 -> V_164 == V_192 ) {
const struct V_193 * * V_194 ;
V_26 -> V_194 = V_194 =
F_55 ( sizeof( struct V_193 * ) * V_26 -> V_183 ,
V_172 ) ;
if ( ! V_26 -> V_194 )
return - V_173 ;
if ( V_158 ) {
for ( V_31 = 2 ; V_31 < 3 + V_26 -> V_183 ; V_31 ++ ) {
if ( V_158 [ V_31 ] < 0 || V_158 [ V_31 ] > 1 ) {
F_57 ( V_2 -> V_76 , V_195
L_10 ,
V_31 , V_158 [ V_31 ] ) ;
}
}
}
for ( V_31 = 0 ; V_31 < V_26 -> V_183 ; V_31 ++ ) {
if ( V_31 < V_196 - 3 && V_158 &&
V_158 [ 3 + V_31 ] == 1 ) {
if ( V_158 [ 2 ] == 1 )
V_194 [ V_31 ] = & V_197 ;
else
V_194 [ V_31 ] = & V_198 ;
} else {
if ( V_158 && V_158 [ 2 ] == 1 ) {
V_194 [ V_31 ] =
& V_199 ;
} else {
V_194 [ V_31 ] = & V_200 ;
}
}
}
V_9 -> V_16 = V_201 ;
} else {
if ( V_158 && V_158 [ 2 ] == 1 ) {
V_26 -> V_202 = & V_203 ;
V_9 -> V_16 = V_204 ;
} else {
if ( V_158 && V_158 [ 2 ] != 0 ) {
F_57 ( V_2 -> V_76 , V_195
L_11 ,
V_158 [ 2 ] ) ;
}
V_26 -> V_202 = & V_205 ;
V_9 -> V_16 = V_206 ;
}
}
V_2 -> V_169 = V_7 -> V_207 ;
if ( V_144 ) {
V_170 = F_58 ( V_144 , F_38 , V_208 ,
V_195 , V_2 ) ;
if ( V_170 < 0 ) {
F_22 ( V_2 -> V_76 ,
L_12 , V_144 ) ;
return V_170 ;
} else {
V_2 -> V_144 = V_144 ;
}
}
F_46 ( V_2 , V_144 ) ;
return 1 ;
}
static int F_59 ( struct V_1 * V_2 , struct V_155 * V_156 )
{
struct V_8 * V_9 ;
struct V_151 * V_151 ;
F_48 ( V_2 -> V_76 , V_195 L_13 ) ;
V_9 = F_60 ( V_2 , sizeof( * V_9 ) ) ;
if ( ! V_9 )
return - V_173 ;
V_151 = F_43 ( V_2 , V_156 ) ;
if ( ! V_151 )
return - V_209 ;
return F_50 ( V_2 , V_151 , V_156 -> V_158 ) ;
}
static int
F_61 ( struct V_1 * V_2 , unsigned long V_210 )
{
struct V_151 * V_151 = F_47 ( V_2 ) ;
struct V_8 * V_9 ;
F_48 ( V_2 -> V_76 , V_195 L_14 ,
F_49 ( V_151 ) ) ;
V_9 = F_60 ( V_2 , sizeof( * V_9 ) ) ;
if ( ! V_9 )
return - V_173 ;
V_2 -> V_166 = F_41 ( V_151 ) ;
if ( V_2 -> V_166 == NULL ) {
F_22 ( V_2 -> V_76 ,
V_195 L_15 ) ;
return - V_89 ;
}
F_62 ( V_151 ) ;
return F_50 ( V_2 , V_151 , NULL ) ;
}
static void F_63 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = V_2 -> V_10 ;
struct V_151 * V_167 = F_47 ( V_2 ) ;
if ( V_2 -> V_144 )
F_64 ( V_2 -> V_144 , V_2 ) ;
if ( V_2 -> V_177 ) {
struct V_25 * V_26 ;
V_26 = & V_2 -> V_177 [ 0 ] ;
F_65 ( V_26 -> V_194 ) ;
}
if ( V_9 ) {
F_65 ( V_9 -> V_12 ) ;
F_65 ( V_9 -> V_77 ) ;
F_65 ( V_9 -> V_78 ) ;
}
F_66 ( V_2 ) ;
if ( V_167 )
F_67 ( V_167 ) ;
}
static int F_68 ( struct V_151 * V_2 ,
const struct V_211 * V_212 )
{
return F_69 ( V_2 , & V_213 ,
V_212 -> V_214 ) ;
}
