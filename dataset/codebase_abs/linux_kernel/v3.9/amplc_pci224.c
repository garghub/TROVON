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
F_10 ( V_114 , & V_109 , & V_110 ,
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
F_31 ( L_2 V_124
L_3
L_4
L_5 , V_2 -> V_125 ) ;
}
if ( V_122 & V_120 ) {
F_31 ( L_2 V_124
L_3
L_6
L_7 , V_2 -> V_125 ) ;
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
unsigned int V_29 , V_126 ;
unsigned int V_123 ;
unsigned int V_127 ;
unsigned long V_37 ;
if ( V_52 -> V_119 == NULL || V_52 -> V_66 == 0 )
return - V_89 ;
V_9 -> V_128 = 0 ;
for ( V_29 = 0 ; V_29 < V_52 -> V_66 ; V_29 ++ ) {
V_123 = F_7 ( V_52 -> V_119 [ V_29 ] ) ;
V_9 -> V_128 |= 1U << V_123 ;
V_127 = 0 ;
for ( V_126 = 0 ; V_126 < V_52 -> V_66 ; V_126 ++ ) {
if ( F_7 ( V_52 -> V_119 [ V_126 ] ) < V_123 )
V_127 ++ ;
}
V_9 -> V_78 [ V_127 ] = V_29 ;
}
F_3 ( V_9 -> V_128 , V_2 -> V_13 + V_14 ) ;
V_4 = F_8 ( V_52 -> V_119 [ 0 ] ) ;
V_9 -> V_15 = F_4 ( V_9 -> V_15 ,
( V_9 ->
V_16 [ V_4 ] | V_79 |
V_129 ) ,
( V_17 |
V_18 |
V_49 |
V_50 ) ) ;
F_3 ( V_9 -> V_15 | V_19 ,
V_2 -> V_13 + V_20 ) ;
if ( V_52 -> V_81 == V_82 ) {
unsigned int V_109 , V_110 , V_111 ;
unsigned int V_130 = V_52 -> V_84 ;
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
F_10 ( V_114 , & V_109 , & V_110 ,
& V_130 , V_36 ) ;
}
F_15 ( F_33 ( 0 , V_131 ) ,
V_9 -> V_42 + V_132 ) ;
if ( V_109 == 1 ) {
F_15 ( F_34 ( 0 , V_133 ) ,
V_9 -> V_42 + V_134 ) ;
} else {
F_15 ( F_33 ( 2 , V_131 ) ,
V_9 -> V_42 + V_132 ) ;
F_15 ( F_34 ( 2 , V_133 ) ,
V_9 -> V_42 + V_134 ) ;
F_35 ( V_9 -> V_42 + V_135 , 0 ,
2 , V_109 , 2 ) ;
F_15 ( F_34 ( 0 , V_136 ) ,
V_9 -> V_42 + V_134 ) ;
}
F_35 ( V_9 -> V_42 + V_135 , 0 , 0 , V_110 , 2 ) ;
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
void * V_5 , unsigned int V_137 , unsigned int V_138 )
{
const struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = V_2 -> V_10 ;
struct V_139 * V_53 = V_26 -> V_53 ;
short * V_140 = V_5 ;
unsigned int V_141 = V_137 / sizeof( * V_140 ) ;
unsigned int V_142 ;
unsigned int V_143 ;
unsigned int V_29 ;
V_143 = 16 - V_7 -> V_21 ;
if ( ( V_9 -> V_16 [ F_8 ( V_53 -> V_52 . V_119 [ 0 ] ) ] &
V_17 ) == V_144 ) {
V_142 = 0 ;
} else {
V_142 = 32768 ;
}
for ( V_29 = 0 ; V_29 < V_141 ; V_29 ++ )
V_140 [ V_29 ] = ( V_140 [ V_29 ] << V_143 ) - V_142 ;
}
static T_1 F_38 ( int V_145 , void * V_146 )
{
struct V_1 * V_2 = V_146 ;
struct V_8 * V_9 = V_2 -> V_10 ;
struct V_25 * V_26 = & V_2 -> V_147 [ 0 ] ;
struct V_51 * V_52 ;
unsigned char V_148 , V_149 ;
unsigned char V_150 ;
int V_151 = 0 ;
unsigned long V_37 ;
V_148 = F_39 ( V_9 -> V_42 + V_43 ) & 0x3F ;
if ( V_148 ) {
V_151 = 1 ;
F_14 ( & V_9 -> V_40 , V_37 ) ;
V_149 = V_9 -> V_41 & V_148 ;
V_150 = V_9 -> V_41 & ~ V_148 ;
F_15 ( V_150 , V_9 -> V_42 + V_43 ) ;
V_9 -> V_44 = 1 ;
V_9 -> V_45 = V_46 ;
F_16 ( & V_9 -> V_40 , V_37 ) ;
if ( V_149 != 0 ) {
V_52 = & V_26 -> V_53 -> V_52 ;
if ( V_149 & V_60 ) {
V_9 -> V_41 &= ~ V_60 ;
if ( V_52 -> V_93 == V_59 )
F_17 ( V_2 , V_26 ) ;
else if ( V_52 -> V_58 == V_59 )
F_12 ( V_2 , V_26 ) ;
}
if ( V_149 & V_61 )
F_20 ( V_2 , V_26 ) ;
}
F_14 ( & V_9 -> V_40 , V_37 ) ;
if ( V_150 != V_9 -> V_41 ) {
F_15 ( V_9 -> V_41 ,
V_9 -> V_42 + V_43 ) ;
}
V_9 -> V_44 = 0 ;
F_16 ( & V_9 -> V_40 , V_37 ) ;
}
return F_40 ( V_151 ) ;
}
static const struct V_6
* F_41 ( struct V_152 * V_152 )
{
int V_29 ;
for ( V_29 = 0 ; V_29 < F_42 ( V_153 ) ; V_29 ++ )
if ( V_152 -> V_154 == V_153 [ V_29 ] . V_155 )
return & V_153 [ V_29 ] ;
return NULL ;
}
static struct V_152 * F_43 ( struct V_1 * V_2 ,
struct V_156 * V_157 )
{
const struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_152 * V_152 = NULL ;
int V_158 = V_157 -> V_159 [ 0 ] ;
int V_160 = V_157 -> V_159 [ 1 ] ;
F_44 (pci_dev) {
if ( V_158 || V_160 ) {
if ( V_158 != V_152 -> V_158 -> V_161 ||
V_160 != F_45 ( V_152 -> V_162 ) )
continue;
}
if ( V_152 -> V_163 != V_164 )
continue;
if ( V_7 -> V_165 == V_166 ) {
const struct V_6 * V_167 ;
V_167 = F_41 ( V_152 ) ;
if ( V_167 == NULL )
continue;
V_2 -> V_167 = V_167 ;
} else {
if ( V_7 -> V_155 != V_152 -> V_154 )
continue;
}
return V_152 ;
}
F_22 ( V_2 -> V_76 ,
L_8 ,
V_158 , V_160 ) ;
return NULL ;
}
static void F_46 ( struct V_1 * V_2 , unsigned int V_145 )
{
struct V_152 * V_168 = F_47 ( V_2 ) ;
char V_169 [ 30 ] ;
if ( V_145 )
snprintf ( V_169 , sizeof( V_169 ) , L_9 , V_145 ,
( V_2 -> V_145 ? L_10 : L_11 ) ) ;
else
snprintf ( V_169 , sizeof( V_169 ) , L_12 ) ;
F_48 ( V_2 -> V_76 , L_13 ,
V_2 -> V_170 , F_49 ( V_168 ) , V_169 ) ;
}
static int F_50 ( struct V_1 * V_2 ,
struct V_152 * V_152 , int * V_159 )
{
const struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = V_2 -> V_10 ;
struct V_25 * V_26 ;
unsigned int V_145 ;
unsigned V_31 ;
int V_171 ;
F_51 ( V_2 , & V_152 -> V_2 ) ;
V_171 = F_52 ( V_152 , V_124 ) ;
if ( V_171 < 0 ) {
F_22 ( V_2 -> V_76 ,
L_14
) ;
return V_171 ;
}
F_53 ( & V_9 -> V_40 ) ;
V_9 -> V_42 = F_54 ( V_152 , 2 ) ;
V_2 -> V_13 = F_54 ( V_152 , 3 ) ;
V_145 = V_152 -> V_145 ;
V_9 -> V_12 = F_55 ( sizeof( V_9 -> V_12 [ 0 ] ) *
V_7 -> V_172 , V_173 ) ;
if ( ! V_9 -> V_12 )
return - V_174 ;
V_9 -> V_77 = F_55 ( sizeof( V_9 -> V_77 [ 0 ] ) *
V_7 -> V_172 , V_173 ) ;
if ( ! V_9 -> V_77 )
return - V_174 ;
V_9 -> V_78 = F_55 ( sizeof( V_9 -> V_78 [ 0 ] ) *
V_7 -> V_172 , V_173 ) ;
if ( ! V_9 -> V_78 )
return - V_174 ;
V_9 -> V_41 = 0 ;
F_15 ( 0 , V_9 -> V_42 + V_43 ) ;
F_3 ( V_175 , V_2 -> V_13 + V_20 ) ;
F_3 ( 0 , V_2 -> V_13 + V_14 ) ;
F_3 ( 0 , V_2 -> V_13 + V_176 ) ;
V_9 -> V_15 = ( V_47 | V_22 |
V_177 |
V_48 ) ;
F_3 ( V_9 -> V_15 | V_19 ,
V_2 -> V_13 + V_20 ) ;
V_171 = F_56 ( V_2 , 1 ) ;
if ( V_171 )
return V_171 ;
V_26 = & V_2 -> V_147 [ 0 ] ;
V_26 -> type = V_178 ;
V_26 -> V_179 = V_180 | V_181 | V_182 ;
V_26 -> V_183 = V_7 -> V_172 ;
V_26 -> V_184 = ( 1 << V_7 -> V_21 ) - 1 ;
V_26 -> V_185 = & F_6 ;
V_26 -> V_186 = & F_9 ;
V_26 -> V_187 = V_26 -> V_183 ;
V_2 -> V_188 = V_26 ;
V_26 -> V_189 = & F_32 ;
V_26 -> V_190 = & F_25 ;
V_26 -> V_191 = & F_36 ;
V_26 -> V_192 = & F_37 ;
if ( V_7 -> V_165 == V_193 ) {
const struct V_194 * * V_195 ;
V_26 -> V_195 = V_195 =
F_55 ( sizeof( struct V_194 * ) * V_26 -> V_183 ,
V_173 ) ;
if ( ! V_26 -> V_195 )
return - V_174 ;
if ( V_159 ) {
for ( V_31 = 2 ; V_31 < 3 + V_26 -> V_183 ; V_31 ++ ) {
if ( V_159 [ V_31 ] < 0 || V_159 [ V_31 ] > 1 ) {
F_57 ( V_2 -> V_76 , V_124
L_15 ,
V_31 , V_159 [ V_31 ] ) ;
}
}
}
for ( V_31 = 0 ; V_31 < V_26 -> V_183 ; V_31 ++ ) {
if ( V_31 < V_196 - 3 && V_159 &&
V_159 [ 3 + V_31 ] == 1 ) {
if ( V_159 [ 2 ] == 1 )
V_195 [ V_31 ] = & V_197 ;
else
V_195 [ V_31 ] = & V_198 ;
} else {
if ( V_159 && V_159 [ 2 ] == 1 ) {
V_195 [ V_31 ] =
& V_199 ;
} else {
V_195 [ V_31 ] = & V_200 ;
}
}
}
V_9 -> V_16 = V_201 ;
} else {
if ( V_159 && V_159 [ 2 ] == 1 ) {
V_26 -> V_202 = & V_203 ;
V_9 -> V_16 = V_204 ;
} else {
if ( V_159 && V_159 [ 2 ] != 0 ) {
F_57 ( V_2 -> V_76 , V_124
L_16 ,
V_159 [ 2 ] ) ;
}
V_26 -> V_202 = & V_205 ;
V_9 -> V_16 = V_206 ;
}
}
V_2 -> V_170 = V_7 -> V_207 ;
if ( V_145 ) {
V_171 = F_58 ( V_145 , F_38 , V_208 ,
V_124 , V_2 ) ;
if ( V_171 < 0 ) {
F_22 ( V_2 -> V_76 ,
L_17 , V_145 ) ;
return V_171 ;
} else {
V_2 -> V_145 = V_145 ;
}
}
F_46 ( V_2 , V_145 ) ;
return 1 ;
}
static int F_59 ( struct V_1 * V_2 , struct V_156 * V_157 )
{
struct V_8 * V_9 ;
struct V_152 * V_152 ;
F_48 ( V_2 -> V_76 , V_124 L_18 ) ;
V_9 = F_60 ( sizeof( * V_9 ) , V_173 ) ;
if ( ! V_9 )
return - V_174 ;
V_2 -> V_10 = V_9 ;
V_152 = F_43 ( V_2 , V_157 ) ;
if ( ! V_152 )
return - V_209 ;
return F_50 ( V_2 , V_152 , V_157 -> V_159 ) ;
}
static int
F_61 ( struct V_1 * V_2 , unsigned long V_210 )
{
struct V_152 * V_152 = F_47 ( V_2 ) ;
struct V_8 * V_9 ;
F_48 ( V_2 -> V_76 , V_124 L_19 ,
F_49 ( V_152 ) ) ;
V_9 = F_60 ( sizeof( * V_9 ) , V_173 ) ;
if ( ! V_9 )
return - V_174 ;
V_2 -> V_10 = V_9 ;
V_2 -> V_167 = F_41 ( V_152 ) ;
if ( V_2 -> V_167 == NULL ) {
F_22 ( V_2 -> V_76 ,
V_124 L_20 ) ;
return - V_89 ;
}
F_62 ( V_152 ) ;
return F_50 ( V_2 , V_152 , NULL ) ;
}
static void F_63 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = V_2 -> V_10 ;
struct V_152 * V_168 = F_47 ( V_2 ) ;
if ( V_2 -> V_145 )
F_64 ( V_2 -> V_145 , V_2 ) ;
if ( V_2 -> V_147 ) {
struct V_25 * V_26 ;
V_26 = & V_2 -> V_147 [ 0 ] ;
F_65 ( V_26 -> V_195 ) ;
}
if ( V_9 ) {
F_65 ( V_9 -> V_12 ) ;
F_65 ( V_9 -> V_77 ) ;
F_65 ( V_9 -> V_78 ) ;
}
if ( V_168 ) {
if ( V_2 -> V_13 )
F_66 ( V_168 ) ;
F_67 ( V_168 ) ;
}
}
static int F_68 ( struct V_152 * V_2 ,
const struct V_211
* V_212 )
{
return F_69 ( V_2 , & V_213 ) ;
}
