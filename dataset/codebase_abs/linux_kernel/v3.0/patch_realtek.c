static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = V_6 -> V_8 ;
unsigned int V_9 = F_3 ( V_2 , & V_4 -> V_10 ) ;
if ( V_9 >= V_8 -> V_11 )
V_9 = 0 ;
if ( ! V_8 -> V_12 [ V_9 ] . V_13 && V_9 > 0 )
V_9 = 0 ;
return F_4 ( & V_8 -> V_12 [ V_9 ] , V_4 ) ;
}
static int F_5 ( struct V_1 * V_2 ,
struct V_14 * V_15 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = V_6 -> V_8 ;
unsigned int V_16 = F_3 ( V_2 , & V_15 -> V_10 ) ;
V_15 -> V_17 . V_18 . V_19 [ 0 ] = V_8 -> V_20 [ V_16 ] ;
return 0 ;
}
static int F_6 ( struct V_1 * V_2 ,
struct V_14 * V_15 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = V_6 -> V_8 ;
const struct V_21 * V_22 ;
unsigned int V_16 = F_3 ( V_2 , & V_15 -> V_10 ) ;
unsigned int V_9 ;
T_1 V_23 = V_8 -> V_24 ?
V_8 -> V_24 [ V_16 ] : V_8 -> V_25 [ V_16 ] ;
unsigned int type ;
V_9 = V_16 >= V_8 -> V_11 ? 0 : V_16 ;
V_22 = & V_8 -> V_12 [ V_9 ] ;
if ( ! V_22 -> V_13 && V_9 > 0 )
V_22 = & V_8 -> V_12 [ 0 ] ;
type = F_7 ( F_8 ( V_6 , V_23 ) ) ;
if ( type == V_26 ) {
unsigned int * V_27 = & V_8 -> V_20 [ V_16 ] ;
unsigned int V_28 , V_29 ;
V_29 = V_15 -> V_17 . V_18 . V_19 [ 0 ] ;
if ( V_29 >= V_22 -> V_13 )
V_29 = V_22 -> V_13 - 1 ;
if ( * V_27 == V_29 )
return 0 ;
for ( V_28 = 0 ; V_28 < V_22 -> V_13 ; V_28 ++ ) {
unsigned int V_30 = ( V_28 == V_29 ) ? 0 : V_31 ;
F_9 ( V_6 , V_23 , V_32 ,
V_22 -> V_33 [ V_28 ] . V_34 ,
V_31 , V_30 ) ;
}
* V_27 = V_29 ;
return 1 ;
} else {
return F_10 ( V_6 , V_22 , V_15 , V_23 ,
& V_8 -> V_20 [ V_16 ] ) ;
}
}
static int F_11 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = V_6 -> V_8 ;
return F_12 ( V_6 , V_4 , V_8 -> V_35 ,
V_8 -> V_36 ) ;
}
static int F_13 ( struct V_1 * V_2 ,
struct V_14 * V_15 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = V_6 -> V_8 ;
return F_14 ( V_6 , V_15 , V_8 -> V_35 ,
V_8 -> V_36 ,
V_8 -> V_37 ) ;
}
static int F_15 ( struct V_1 * V_2 ,
struct V_14 * V_15 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = V_6 -> V_8 ;
int V_38 = F_16 ( V_6 , V_15 , V_8 -> V_35 ,
V_8 -> V_36 ,
& V_8 -> V_37 ) ;
if ( V_38 >= 0 && ! V_8 -> V_39 ) {
V_8 -> V_40 . V_41 = V_8 -> V_37 ;
if ( V_8 -> V_42 )
V_8 -> V_40 . V_43 = V_8 -> V_40 . V_41 / 2 ;
}
return V_38 ;
}
static int F_17 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
unsigned int V_44 = V_4 -> V_17 . V_18 . V_19 ;
unsigned char V_45 = ( V_2 -> V_46 >> 16 ) & 0xff ;
V_4 -> type = V_47 ;
V_4 -> V_48 = 1 ;
V_4 -> V_17 . V_18 . V_33 = F_18 ( V_45 ) ;
if ( V_44 < V_49 ( V_45 ) || V_44 > F_19 ( V_45 ) )
V_44 = V_49 ( V_45 ) ;
strcpy ( V_4 -> V_17 . V_18 . V_50 , V_51 [ V_44 ] ) ;
return 0 ;
}
static int F_20 ( struct V_1 * V_2 ,
struct V_14 * V_15 )
{
unsigned int V_28 ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
T_1 V_23 = V_2 -> V_46 & 0xffff ;
unsigned char V_45 = ( V_2 -> V_46 >> 16 ) & 0xff ;
long * V_52 = V_15 -> V_17 . integer . V_17 ;
unsigned int V_53 = F_21 ( V_6 , V_23 , 0 ,
V_54 ,
0x00 ) ;
V_28 = V_49 ( V_45 ) ;
while ( V_28 <= F_19 ( V_45 ) && V_55 [ V_28 ] != V_53 )
V_28 ++ ;
* V_52 = V_28 <= F_19 ( V_45 ) ? V_28 : V_49 ( V_45 ) ;
return 0 ;
}
static int F_22 ( struct V_1 * V_2 ,
struct V_14 * V_15 )
{
signed int V_56 ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
T_1 V_23 = V_2 -> V_46 & 0xffff ;
unsigned char V_45 = ( V_2 -> V_46 >> 16 ) & 0xff ;
long V_57 = * V_15 -> V_17 . integer . V_17 ;
unsigned int V_53 = F_21 ( V_6 , V_23 , 0 ,
V_54 ,
0x00 ) ;
if ( V_57 < V_49 ( V_45 ) || V_57 > F_19 ( V_45 ) )
V_57 = V_49 ( V_45 ) ;
V_56 = V_53 != V_55 [ V_57 ] ;
if ( V_56 ) {
F_23 ( V_6 , V_23 , 0 ,
V_58 ,
V_55 [ V_57 ] ) ;
if ( V_57 <= 2 ) {
F_9 ( V_6 , V_23 , V_59 , 0 ,
V_31 , V_31 ) ;
F_9 ( V_6 , V_23 , V_32 , 0 ,
V_31 , 0 ) ;
} else {
F_9 ( V_6 , V_23 , V_32 , 0 ,
V_31 , V_31 ) ;
F_9 ( V_6 , V_23 , V_59 , 0 ,
V_31 , 0 ) ;
}
}
return V_56 ;
}
static int F_24 ( struct V_1 * V_2 ,
struct V_14 * V_15 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
T_1 V_23 = V_2 -> V_46 & 0xffff ;
unsigned char V_60 = ( V_2 -> V_46 >> 16 ) & 0xff ;
long * V_52 = V_15 -> V_17 . integer . V_17 ;
unsigned int V_57 = F_21 ( V_6 , V_23 , 0 ,
V_61 , 0x00 ) ;
* V_52 = ( V_57 & V_60 ) != 0 ;
return 0 ;
}
static int F_25 ( struct V_1 * V_2 ,
struct V_14 * V_15 )
{
signed int V_56 ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
T_1 V_23 = V_2 -> V_46 & 0xffff ;
unsigned char V_60 = ( V_2 -> V_46 >> 16 ) & 0xff ;
long V_57 = * V_15 -> V_17 . integer . V_17 ;
unsigned int V_62 = F_21 ( V_6 , V_23 , 0 ,
V_61 ,
0x00 ) ;
V_56 = ( V_57 == 0 ? 0 : V_60 ) != ( V_62 & V_60 ) ;
if ( V_57 == 0 )
V_62 &= ~ V_60 ;
else
V_62 |= V_60 ;
F_23 ( V_6 , V_23 , 0 ,
V_63 , V_62 ) ;
return V_56 ;
}
static int F_26 ( struct V_1 * V_2 ,
struct V_14 * V_15 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
T_1 V_23 = V_2 -> V_46 & 0xffff ;
unsigned char V_60 = ( V_2 -> V_46 >> 16 ) & 0xff ;
long * V_52 = V_15 -> V_17 . integer . V_17 ;
unsigned int V_57 = F_21 ( V_6 , V_23 , 0 ,
V_64 , 0x00 ) ;
* V_52 = ( V_57 & V_60 ) != 0 ;
return 0 ;
}
static int F_27 ( struct V_1 * V_2 ,
struct V_14 * V_15 )
{
signed int V_56 ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
T_1 V_23 = V_2 -> V_46 & 0xffff ;
unsigned char V_60 = ( V_2 -> V_46 >> 16 ) & 0xff ;
long V_57 = * V_15 -> V_17 . integer . V_17 ;
unsigned int V_65 = F_21 ( V_6 , V_23 , 0 ,
V_64 ,
0x00 ) ;
V_56 = ( V_57 == 0 ? 0 : V_60 ) != ( V_65 & V_60 ) ;
if ( V_57 == 0 )
V_65 &= ~ V_60 ;
else
V_65 |= V_60 ;
F_23 ( V_6 , V_23 , 0 , V_66 ,
V_65 ) ;
return V_56 ;
}
static int F_28 ( struct V_1 * V_2 ,
struct V_14 * V_15 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
T_1 V_23 = V_2 -> V_46 & 0xffff ;
unsigned char V_60 = ( V_2 -> V_46 >> 16 ) & 0xff ;
long * V_52 = V_15 -> V_17 . integer . V_17 ;
unsigned int V_57 = F_21 ( V_6 , V_23 , 0 ,
V_67 , 0x00 ) ;
* V_52 = ( V_57 & V_60 ) != 0 ;
return 0 ;
}
static int F_29 ( struct V_1 * V_2 ,
struct V_14 * V_15 )
{
int V_56 ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
T_1 V_23 = V_2 -> V_46 & 0xffff ;
unsigned char V_60 = ( V_2 -> V_46 >> 16 ) & 0xff ;
long V_57 = * V_15 -> V_17 . integer . V_17 ;
unsigned int V_65 = F_21 ( V_6 , V_23 , 0 ,
V_67 ,
0x00 ) ;
V_56 = ( ! V_57 ? 0 : V_60 ) != ( V_65 & V_60 ) ;
if ( ! V_57 )
V_65 &= ~ V_60 ;
else
V_65 |= V_60 ;
F_23 ( V_6 , V_23 , 0 , V_68 ,
V_65 ) ;
return V_56 ;
}
static void F_30 ( struct V_5 * V_6 , T_1 V_23 ,
int V_69 )
{
unsigned int V_57 = V_70 ;
if ( V_69 == V_71 ) {
unsigned int V_72 ;
unsigned int V_73 ;
V_73 = F_21 ( V_6 , V_23 , 0 ,
V_54 , 0 ) ;
V_72 = F_31 ( V_6 , V_23 ) ;
V_72 = ( V_72 & V_74 ) >> V_75 ;
if ( ( V_72 & V_76 ) && V_73 != V_77 )
V_57 = V_78 ;
else if ( V_72 & V_79 )
V_57 = V_77 ;
else if ( V_72 & V_80 )
V_57 = V_81 ;
else if ( V_72 & V_82 )
V_57 = V_83 ;
}
F_32 ( V_6 , V_23 , 0 , V_58 , V_57 ) ;
}
static void F_33 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
struct V_84 * V_85 = & V_8 -> V_86 ;
if ( ! V_85 -> V_87 ) {
while ( V_85 -> V_87 < V_88 &&
V_85 -> V_89 [ V_85 -> V_87 ] )
V_85 -> V_87 ++ ;
}
if ( ! V_85 -> V_90 ) {
while ( V_85 -> V_90 < V_88 &&
V_85 -> V_91 [ V_85 -> V_90 ] )
V_85 -> V_90 ++ ;
}
if ( ! V_85 -> V_92 ) {
while ( V_85 -> V_92 < V_88 &&
V_85 -> V_93 [ V_85 -> V_92 ] )
V_85 -> V_92 ++ ;
}
}
static void F_34 ( struct V_7 * V_8 , const struct V_94 * V_95 )
{
if ( F_35 ( V_8 -> V_96 >= F_36 ( V_8 -> V_97 ) ) )
return;
V_8 -> V_97 [ V_8 -> V_96 ++ ] = V_95 ;
}
static void F_37 ( struct V_7 * V_8 , const struct V_98 * V_99 )
{
if ( F_35 ( V_8 -> V_100 >= F_36 ( V_8 -> V_101 ) ) )
return;
V_8 -> V_101 [ V_8 -> V_100 ++ ] = V_99 ;
}
static void F_38 ( struct V_5 * V_6 ,
const struct V_102 * V_103 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
int V_28 ;
for ( V_28 = 0 ; V_28 < F_36 ( V_103 -> V_97 ) && V_103 -> V_97 [ V_28 ] ; V_28 ++ )
F_34 ( V_8 , V_103 -> V_97 [ V_28 ] ) ;
V_8 -> V_104 = V_103 -> V_104 ;
for ( V_28 = 0 ; V_28 < F_36 ( V_103 -> V_101 ) && V_103 -> V_101 [ V_28 ] ;
V_28 ++ )
F_37 ( V_8 , V_103 -> V_101 [ V_28 ] ) ;
V_8 -> V_35 = V_103 -> V_35 ;
V_8 -> V_36 = V_103 -> V_36 ;
V_8 -> V_42 = V_103 -> V_42 ;
V_8 -> V_39 = V_103 -> V_39 ;
if ( V_103 -> V_39 )
V_8 -> V_40 . V_41 = V_103 -> V_39 ;
else
V_8 -> V_40 . V_41 = V_8 -> V_35 [ 0 ] . V_105 ;
V_8 -> V_37 = V_8 -> V_35 [ 0 ] . V_105 ;
V_8 -> V_40 . V_43 = V_103 -> V_43 ;
V_8 -> V_40 . V_106 = V_103 -> V_106 ;
V_8 -> V_40 . V_107 = V_103 -> V_107 ;
V_8 -> V_40 . V_108 = V_103 -> V_108 ;
V_8 -> V_40 . V_109 = V_103 -> V_109 ;
V_8 -> V_11 = V_103 -> V_11 ;
if ( ! V_8 -> V_11 )
V_8 -> V_11 = 1 ;
V_8 -> V_12 = V_103 -> V_12 ;
V_8 -> V_110 = V_103 -> V_110 ;
V_8 -> V_25 = V_103 -> V_25 ;
V_8 -> V_24 = V_103 -> V_24 ;
V_8 -> V_111 = V_103 -> V_111 ;
V_8 -> V_112 = V_103 -> V_112 ;
V_8 -> V_113 = V_103 -> V_113 ;
#ifdef F_39
V_8 -> V_114 = V_103 -> V_114 ;
V_8 -> V_115 . V_116 = V_103 -> V_117 ;
#endif
if ( V_103 -> V_118 )
V_103 -> V_118 ( V_6 ) ;
F_33 ( V_6 ) ;
}
static void F_40 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
unsigned int V_57 ;
if ( ! V_8 -> V_119 )
return;
F_32 ( V_6 , V_8 -> V_119 , 0 , V_120 ,
V_8 -> V_121 ) ;
V_57 = F_21 ( V_6 , V_8 -> V_119 , 0 ,
V_122 , 0 ) ;
F_32 ( V_6 , V_8 -> V_119 , 0 , V_120 ,
V_8 -> V_121 ) ;
F_32 ( V_6 , V_8 -> V_119 , 0 , V_123 ,
V_57 & ~ ( 1 << V_8 -> V_124 ) ) ;
}
static void F_41 ( struct V_5 * V_6 , T_1 V_23 ,
unsigned int V_125 , unsigned int V_126 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
V_8 -> V_119 = V_23 ;
V_8 -> V_121 = V_125 ;
V_8 -> V_124 = V_126 ;
F_40 ( V_6 ) ;
}
static int F_42 ( struct V_5 * V_6 )
{
#ifdef F_43
struct V_7 * V_8 = V_6 -> V_8 ;
int V_38 ;
unsigned int V_109 = V_8 -> V_86 . V_93 [ 0 ] ;
unsigned int V_127 = V_8 -> V_128 . V_129 ;
unsigned int V_130 = V_8 -> V_131 . V_129 ;
if ( V_109 ) {
V_38 = F_44 ( V_6 , V_109 ,
V_132 , NULL ) ;
if ( V_38 < 0 )
return V_38 ;
F_45 ( V_6 , V_109 ) ;
}
if ( V_127 ) {
V_38 = F_44 ( V_6 , V_127 ,
V_133 , NULL ) ;
if ( V_38 < 0 )
return V_38 ;
F_45 ( V_6 , V_127 ) ;
}
if ( V_130 ) {
V_38 = F_44 ( V_6 , V_130 ,
V_133 , NULL ) ;
if ( V_38 < 0 )
return V_38 ;
F_45 ( V_6 , V_130 ) ;
}
#endif
return 0 ;
}
static int F_46 ( struct V_5 * V_6 , int V_134 , T_1 * V_135 )
{
int V_28 , V_136 = 0 ;
for ( V_28 = 0 ; V_28 < V_134 ; V_28 ++ ) {
T_1 V_23 = V_135 [ V_28 ] ;
if ( ! V_23 )
break;
F_45 ( V_6 , V_23 ) ;
V_136 |= F_47 ( V_6 , V_23 ) ;
}
return V_136 ;
}
static void F_48 ( struct V_5 * V_6 , int V_134 , T_1 * V_135 ,
bool V_137 , bool V_138 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
unsigned int V_139 = V_137 ? V_31 : 0 ;
unsigned int V_140 = V_137 ? 0 : ( V_138 ? V_141 : V_142 ) ;
int V_28 ;
for ( V_28 = 0 ; V_28 < V_134 ; V_28 ++ ) {
T_1 V_23 = V_135 [ V_28 ] ;
if ( ! V_23 )
break;
switch ( V_8 -> V_143 ) {
case V_144 :
F_32 ( V_6 , V_23 , 0 ,
V_58 ,
V_140 ) ;
break;
case V_145 :
F_9 ( V_6 , V_23 , V_59 , 0 ,
V_31 , V_139 ) ;
break;
case V_146 :
V_23 = V_8 -> V_147 [ V_28 ] ;
if ( ! V_23 )
break;
F_9 ( V_6 , V_23 , V_32 , 0 ,
V_31 , V_139 ) ;
F_9 ( V_6 , V_23 , V_32 , 1 ,
V_31 , V_139 ) ;
break;
}
}
}
static void F_49 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
int V_148 ;
F_48 ( V_6 , F_36 ( V_8 -> V_86 . V_93 ) ,
V_8 -> V_86 . V_93 , V_8 -> V_149 , true ) ;
if ( ! V_8 -> V_150 )
V_148 = 0 ;
else
V_148 = V_8 -> V_151 | V_8 -> V_152 ;
V_148 |= V_8 -> V_149 ;
F_48 ( V_6 , F_36 ( V_8 -> V_86 . V_91 ) ,
V_8 -> V_86 . V_91 , V_148 , false ) ;
if ( V_8 -> V_86 . V_89 [ 0 ] == V_8 -> V_86 . V_93 [ 0 ] ||
V_8 -> V_86 . V_89 [ 0 ] == V_8 -> V_86 . V_91 [ 0 ] )
return;
if ( ! V_8 -> V_153 || ! V_8 -> V_150 )
V_148 = 0 ;
else
V_148 = V_8 -> V_151 ;
V_148 |= V_8 -> V_149 ;
F_48 ( V_6 , F_36 ( V_8 -> V_86 . V_89 ) ,
V_8 -> V_86 . V_89 , V_148 , false ) ;
}
static void F_50 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
if ( ! V_8 -> V_150 )
return;
V_8 -> V_151 =
F_46 ( V_6 , F_36 ( V_8 -> V_86 . V_93 ) ,
V_8 -> V_86 . V_93 ) ;
F_49 ( V_6 ) ;
}
static void F_51 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
if ( ! V_8 -> V_150 || ! V_8 -> V_154 )
return;
V_8 -> V_152 =
F_46 ( V_6 , F_36 ( V_8 -> V_86 . V_89 ) ,
V_8 -> V_86 . V_89 ) ;
F_49 ( V_6 ) ;
}
static int F_52 ( struct V_5 * V_6 , T_1 V_155 ,
T_1 V_23 )
{
T_1 V_156 [ V_157 ] ;
int V_28 , V_158 ;
V_158 = F_53 ( V_6 , V_155 , V_156 , F_36 ( V_156 ) ) ;
for ( V_28 = 0 ; V_28 < V_158 ; V_28 ++ )
if ( V_156 [ V_28 ] == V_23 )
return V_28 ;
return - 1 ;
}
static void F_54 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
unsigned int V_136 ;
T_1 V_159 ;
V_136 = F_47 ( V_6 , V_8 -> V_128 . V_129 ) ;
if ( V_136 )
V_8 -> V_160 = 1 ;
else
V_8 -> V_160 = 0 ;
V_159 = V_8 -> V_25 [ V_8 -> V_160 ] ;
if ( V_8 -> V_161 && V_8 -> V_161 != V_159 ) {
F_55 ( V_6 , V_8 -> V_161 , 1 ) ;
V_8 -> V_161 = V_159 ;
F_56 ( V_6 , V_159 ,
V_8 -> V_162 , 0 ,
V_8 -> V_163 ) ;
}
}
static void F_57 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
struct V_164 * V_165 , * V_166 , * V_167 ;
unsigned int V_136 , type ;
T_1 V_168 ;
if ( ! V_8 -> V_169 )
return;
if ( ! V_8 -> V_170 . V_129 || ! V_8 -> V_128 . V_129 )
return;
if ( F_35 ( ! V_8 -> V_25 ) )
return;
if ( V_8 -> V_171 ) {
F_54 ( V_6 ) ;
return;
}
V_168 = V_8 -> V_24 ? V_8 -> V_24 [ 0 ] : V_8 -> V_25 [ 0 ] ;
V_167 = & V_8 -> V_170 ;
V_165 = & V_8 -> V_128 ;
V_166 = & V_8 -> V_131 ;
V_136 = F_47 ( V_6 , V_8 -> V_128 . V_129 ) ;
if ( V_136 ) {
V_167 = & V_8 -> V_128 ;
V_165 = & V_8 -> V_170 ;
V_166 = & V_8 -> V_131 ;
}
if ( ! V_136 && V_8 -> V_131 . V_129 > 0 ) {
V_136 = F_47 ( V_6 , V_8 -> V_131 . V_129 ) ;
if ( V_136 ) {
V_167 = & V_8 -> V_131 ;
V_165 = & V_8 -> V_170 ;
V_166 = & V_8 -> V_128 ;
}
F_45 ( V_6 , V_8 -> V_131 . V_129 ) ;
}
type = F_7 ( F_8 ( V_6 , V_168 ) ) ;
if ( type == V_26 ) {
F_9 ( V_6 , V_168 , V_32 ,
V_167 -> V_9 ,
V_31 , 0 ) ;
if ( V_165 -> V_129 > 0 )
F_9 ( V_6 , V_168 , V_32 ,
V_165 -> V_9 ,
V_31 , V_31 ) ;
if ( V_166 -> V_129 > 0 )
F_9 ( V_6 , V_168 , V_32 ,
V_166 -> V_9 ,
V_31 , V_31 ) ;
} else {
F_23 ( V_6 , V_168 , 0 ,
V_172 ,
V_167 -> V_9 ) ;
}
F_45 ( V_6 , V_8 -> V_128 . V_129 ) ;
}
static void F_58 ( struct V_5 * V_6 , unsigned int V_173 )
{
if ( V_6 -> V_174 == 0x10ec0880 )
V_173 >>= 28 ;
else
V_173 >>= 26 ;
switch ( V_173 ) {
case V_175 :
F_50 ( V_6 ) ;
break;
case V_176 :
F_51 ( V_6 ) ;
break;
case V_177 :
F_57 ( V_6 ) ;
break;
}
}
static void F_59 ( struct V_5 * V_6 )
{
F_50 ( V_6 ) ;
F_51 ( V_6 ) ;
F_57 ( V_6 ) ;
}
static void F_60 ( struct V_5 * V_6 )
{
unsigned int V_178 ;
F_32 ( V_6 , 0x20 , 0 , V_120 , 0 ) ;
V_178 = F_21 ( V_6 , 0x20 , 0 , V_122 , 0 ) ;
F_32 ( V_6 , 0x20 , 0 , V_120 , 7 ) ;
if ( ( V_178 & 0xf0 ) == 0x20 )
F_21 ( V_6 , 0x20 , 0 ,
V_123 , 0x830 ) ;
else
F_21 ( V_6 , 0x20 , 0 ,
V_123 , 0x3030 ) ;
}
static void F_61 ( struct V_5 * V_6 )
{
unsigned int V_178 ;
F_32 ( V_6 , 0x20 , 0 , V_120 , 7 ) ;
V_178 = F_21 ( V_6 , 0x20 , 0 , V_122 , 0 ) ;
F_32 ( V_6 , 0x20 , 0 , V_120 , 7 ) ;
F_32 ( V_6 , 0x20 , 0 , V_123 , V_178 | 0x2010 ) ;
}
static void F_62 ( struct V_5 * V_6 , T_1 V_23 , int V_148 )
{
if ( F_7 ( F_8 ( V_6 , V_23 ) ) != V_179 )
return;
if ( F_31 ( V_6 , V_23 ) & V_180 )
F_32 ( V_6 , V_23 , 0 , V_68 ,
V_148 ? 2 : 0 ) ;
}
static void F_63 ( struct V_5 * V_6 , bool V_148 )
{
switch ( V_6 -> V_174 ) {
case 0x10ec0260 :
F_62 ( V_6 , 0x0f , V_148 ) ;
F_62 ( V_6 , 0x10 , V_148 ) ;
break;
case 0x10ec0262 :
case 0x10ec0267 :
case 0x10ec0268 :
case 0x10ec0269 :
case 0x10ec0270 :
case 0x10ec0272 :
case 0x10ec0660 :
case 0x10ec0662 :
case 0x10ec0663 :
case 0x10ec0665 :
case 0x10ec0862 :
case 0x10ec0889 :
case 0x10ec0892 :
F_62 ( V_6 , 0x14 , V_148 ) ;
F_62 ( V_6 , 0x15 , V_148 ) ;
break;
}
}
static void F_64 ( struct V_5 * V_6 )
{
F_63 ( V_6 , false ) ;
F_65 ( 200 ) ;
}
static void F_66 ( struct V_5 * V_6 , int type )
{
unsigned int V_178 ;
switch ( type ) {
case V_181 :
F_67 ( V_6 , V_182 ) ;
break;
case V_183 :
F_67 ( V_6 , V_184 ) ;
break;
case V_185 :
F_67 ( V_6 , V_186 ) ;
break;
case V_187 :
F_63 ( V_6 , true ) ;
switch ( V_6 -> V_174 ) {
case 0x10ec0260 :
F_32 ( V_6 , 0x1a , 0 ,
V_120 , 7 ) ;
V_178 = F_21 ( V_6 , 0x1a , 0 ,
V_122 , 0 ) ;
F_32 ( V_6 , 0x1a , 0 ,
V_120 , 7 ) ;
F_32 ( V_6 , 0x1a , 0 ,
V_123 ,
V_178 | 0x2010 ) ;
break;
case 0x10ec0262 :
case 0x10ec0880 :
case 0x10ec0882 :
case 0x10ec0883 :
case 0x10ec0885 :
case 0x10ec0887 :
F_61 ( V_6 ) ;
break;
case 0x10ec0888 :
F_60 ( V_6 ) ;
break;
#if 0
case 0x10ec0267:
case 0x10ec0268:
snd_hda_codec_write(codec, 0x20, 0,
AC_VERB_SET_COEF_INDEX, 7);
tmp = snd_hda_codec_read(codec, 0x20, 0,
AC_VERB_GET_PROC_COEF, 0);
snd_hda_codec_write(codec, 0x20, 0,
AC_VERB_SET_COEF_INDEX, 7);
snd_hda_codec_write(codec, 0x20, 0,
AC_VERB_SET_PROC_COEF,
tmp | 0x3000);
break;
#endif
}
break;
}
}
static int F_68 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = V_6 -> V_8 ;
static const char * const V_188 [] = {
L_1 , L_2
} ;
static const char * const V_189 [] = {
L_1 , L_3 , L_4
} ;
const char * const * V_190 ;
V_4 -> type = V_47 ;
V_4 -> V_48 = 1 ;
if ( V_8 -> V_191 ) {
V_4 -> V_17 . V_18 . V_33 = 3 ;
V_190 = V_189 ;
} else {
V_4 -> V_17 . V_18 . V_33 = 2 ;
V_190 = V_188 ;
}
if ( V_4 -> V_17 . V_18 . V_19 >= V_4 -> V_17 . V_18 . V_33 )
V_4 -> V_17 . V_18 . V_19 = V_4 -> V_17 . V_18 . V_33 - 1 ;
strcpy ( V_4 -> V_17 . V_18 . V_50 ,
V_190 [ V_4 -> V_17 . V_18 . V_19 ] ) ;
return 0 ;
}
static int F_69 ( struct V_1 * V_2 ,
struct V_14 * V_15 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = V_6 -> V_8 ;
unsigned int V_57 ;
if ( ! V_8 -> V_150 )
V_57 = 0 ;
else if ( ! V_8 -> V_153 )
V_57 = 1 ;
else
V_57 = 2 ;
V_15 -> V_17 . V_18 . V_19 [ 0 ] = V_57 ;
return 0 ;
}
static int F_70 ( struct V_1 * V_2 ,
struct V_14 * V_15 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = V_6 -> V_8 ;
switch ( V_15 -> V_17 . V_18 . V_19 [ 0 ] ) {
case 0 :
if ( ! V_8 -> V_150 )
return 0 ;
V_8 -> V_150 = 0 ;
break;
case 1 :
if ( V_8 -> V_150 && ! V_8 -> V_153 )
return 0 ;
V_8 -> V_150 = 1 ;
V_8 -> V_153 = 0 ;
break;
case 2 :
if ( ! V_8 -> V_191 )
return - V_192 ;
if ( V_8 -> V_150 && V_8 -> V_153 )
return 0 ;
V_8 -> V_150 = 1 ;
V_8 -> V_153 = 1 ;
break;
default:
return - V_192 ;
}
F_49 ( V_6 ) ;
return 1 ;
}
static int F_71 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
struct V_94 * V_193 ;
V_193 = F_72 ( V_8 ) ;
if ( ! V_193 )
return - V_194 ;
* V_193 = V_195 ;
V_193 -> V_50 = F_73 ( L_5 , V_196 ) ;
if ( ! V_193 -> V_50 )
return - V_194 ;
return 0 ;
}
static void F_74 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
struct V_84 * V_85 = & V_8 -> V_86 ;
int V_136 = 0 ;
int V_28 ;
if ( V_85 -> V_93 [ 0 ] )
V_136 ++ ;
if ( V_85 -> V_89 [ 0 ] )
V_136 ++ ;
if ( V_85 -> V_91 [ 0 ] )
V_136 ++ ;
if ( V_136 < 2 )
return;
if ( V_136 == 3 )
V_8 -> V_191 = 1 ;
if ( ! V_85 -> V_91 [ 0 ] ) {
memcpy ( V_85 -> V_91 , V_85 -> V_89 ,
sizeof( V_85 -> V_91 ) ) ;
V_85 -> V_90 = V_85 -> V_87 ;
}
if ( ! V_85 -> V_93 [ 0 ] ) {
memcpy ( V_85 -> V_93 , V_85 -> V_89 ,
sizeof( V_85 -> V_93 ) ) ;
V_85 -> V_92 = V_85 -> V_87 ;
}
for ( V_28 = 0 ; V_28 < V_85 -> V_92 ; V_28 ++ ) {
T_1 V_23 = V_85 -> V_93 [ V_28 ] ;
if ( ! F_75 ( V_6 , V_23 ) )
continue;
F_76 ( L_6 ,
V_23 ) ;
F_23 ( V_6 , V_23 , 0 ,
V_197 ,
V_198 | V_175 ) ;
V_8 -> V_150 = 1 ;
V_8 -> V_143 = V_144 ;
}
if ( V_8 -> V_150 && V_85 -> V_89 [ 0 ] &&
V_85 -> V_89 [ 0 ] != V_85 -> V_93 [ 0 ] &&
V_85 -> V_89 [ 0 ] != V_85 -> V_91 [ 0 ] ) {
for ( V_28 = 0 ; V_28 < V_85 -> V_87 ; V_28 ++ ) {
T_1 V_23 = V_85 -> V_89 [ V_28 ] ;
if ( ! F_75 ( V_6 , V_23 ) )
continue;
F_76 ( L_7
L_8 , V_23 ) ;
F_23 ( V_6 , V_23 , 0 ,
V_197 ,
V_198 | V_176 ) ;
V_8 -> V_154 = 1 ;
}
V_8 -> V_153 = V_8 -> V_154 ;
}
if ( V_8 -> V_150 ) {
F_71 ( V_6 ) ;
V_8 -> V_112 = F_58 ;
}
}
static void F_77 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
struct V_84 * V_85 = & V_8 -> V_86 ;
T_1 V_199 , V_200 , V_201 ;
int V_28 ;
V_199 = V_200 = V_201 = 0 ;
for ( V_28 = 0 ; V_28 < V_85 -> V_202 ; V_28 ++ ) {
T_1 V_23 = V_85 -> V_203 [ V_28 ] . V_129 ;
unsigned int V_204 ;
V_204 = F_78 ( V_6 , V_23 ) ;
switch ( F_79 ( V_204 ) ) {
case V_205 :
if ( V_199 )
return;
if ( V_85 -> V_203 [ V_28 ] . type != V_71 )
return;
V_199 = V_23 ;
break;
case V_206 :
return;
case V_207 :
if ( V_201 )
return;
if ( V_85 -> V_203 [ V_28 ] . type > V_208 )
return;
V_201 = V_23 ;
break;
default:
if ( V_200 )
return;
if ( V_85 -> V_203 [ V_28 ] . type != V_71 )
return;
V_200 = V_23 ;
break;
}
}
if ( ! V_200 && V_201 ) {
V_200 = V_201 ;
V_201 = 0 ;
}
if ( ! V_200 || ! V_199 )
return;
if ( ! F_75 ( V_6 , V_200 ) )
return;
if ( V_201 && ! F_75 ( V_6 , V_201 ) )
return;
F_76 ( L_9 ,
V_200 , V_199 , V_201 ) ;
V_8 -> V_128 . V_129 = V_200 ;
V_8 -> V_131 . V_129 = V_201 ;
V_8 -> V_170 . V_129 = V_199 ;
V_8 -> V_128 . V_9 = V_209 ;
V_8 -> V_131 . V_9 = V_209 ;
V_8 -> V_170 . V_9 = V_209 ;
V_8 -> V_169 = 1 ;
F_23 ( V_6 , V_8 -> V_128 . V_129 , 0 ,
V_197 ,
V_198 | V_177 ) ;
V_8 -> V_112 = F_58 ;
}
static int F_80 ( struct V_5 * V_6 )
{
unsigned int V_210 , V_178 , V_28 ;
unsigned V_23 = 0 ;
struct V_7 * V_8 = V_6 -> V_8 ;
V_8 -> V_211 . V_212 = 1 ;
if ( V_8 -> V_211 . V_213 ) {
V_210 = V_8 -> V_211 . V_214 ;
if ( V_210 == V_215 )
return - 1 ;
goto V_216;
}
V_210 = V_6 -> V_217 & 0xffff ;
if ( V_210 != V_6 -> V_218 -> V_219 -> V_220 && ( V_210 & 1 ) )
goto V_216;
V_23 = 0x1d ;
if ( V_6 -> V_174 == 0x10ec0260 )
V_23 = 0x17 ;
V_210 = F_78 ( V_6 , V_23 ) ;
if ( ! ( V_210 & 1 ) ) {
F_81 ( V_221 L_10 ,
V_6 -> V_222 , V_210 ) ;
return - 1 ;
}
V_178 = 0 ;
for ( V_28 = 1 ; V_28 < 16 ; V_28 ++ ) {
if ( ( V_210 >> V_28 ) & 1 )
V_178 ++ ;
}
if ( ( ( V_210 >> 16 ) & 0xf ) != V_178 )
return - 1 ;
V_8 -> V_211 . V_223 = V_210 >> 30 ;
V_8 -> V_211 . V_212 = ( V_210 & 0x100000 ) >> 20 ;
V_8 -> V_211 . V_224 = ( V_210 >> 16 ) & 0xf ;
V_8 -> V_211 . V_225 = V_210 >> 8 ;
V_216:
V_8 -> V_211 . V_214 = V_210 ;
V_8 -> V_211 . V_226 = ( V_210 & 0x38 ) >> 3 ;
V_8 -> V_211 . V_227 = ( V_210 & 0x4 ) >> 2 ;
V_8 -> V_211 . V_228 = ( V_210 & 0x2 ) >> 1 ;
V_8 -> V_211 . V_229 = V_210 & 0x1 ;
F_82 ( L_11 ,
V_23 , V_8 -> V_211 . V_214 ) ;
F_82 ( L_12 ,
V_8 -> V_211 . V_223 ) ;
F_82 ( L_13 , V_8 -> V_211 . V_212 ) ;
F_82 ( L_14 , V_8 -> V_211 . V_224 ) ;
F_82 ( L_15 , V_8 -> V_211 . V_225 ) ;
F_82 ( L_16 , V_8 -> V_211 . V_226 ) ;
F_82 ( L_17 , V_8 -> V_211 . V_227 ) ;
F_82 ( L_18 , V_8 -> V_211 . V_228 ) ;
F_82 ( L_19 , V_8 -> V_211 . V_229 ) ;
return 0 ;
}
static int F_83 ( struct V_5 * V_6 ,
T_1 V_230 , T_1 V_231 ,
T_1 V_232 , T_1 V_233 )
{
unsigned int V_210 , V_178 , V_28 ;
unsigned V_23 ;
struct V_7 * V_8 = V_6 -> V_8 ;
if ( V_8 -> V_211 . V_213 ) {
V_210 = V_8 -> V_211 . V_214 ;
if ( V_210 == V_215 )
return 0 ;
goto V_216;
}
V_210 = V_6 -> V_217 & 0xffff ;
if ( ( V_210 != V_6 -> V_218 -> V_219 -> V_220 ) && ( V_210 & 1 ) )
goto V_216;
V_23 = 0x1d ;
if ( V_6 -> V_174 == 0x10ec0260 )
V_23 = 0x17 ;
V_210 = F_78 ( V_6 , V_23 ) ;
F_82 ( L_20
L_21 ,
V_210 , V_23 ) ;
if ( ! ( V_210 & 1 ) )
return 0 ;
if ( ( V_210 >> 30 ) != 1 )
return 0 ;
V_178 = 0 ;
for ( V_28 = 1 ; V_28 < 16 ; V_28 ++ ) {
if ( ( V_210 >> V_28 ) & 1 )
V_178 ++ ;
}
if ( ( ( V_210 >> 16 ) & 0xf ) != V_178 )
return 0 ;
V_216:
F_82 ( L_22 ,
V_210 & 0xffff , V_6 -> V_174 ) ;
V_178 = ( V_210 & 0x38 ) >> 3 ;
switch ( V_178 ) {
case 1 :
V_8 -> V_234 = V_181 ;
break;
case 3 :
V_8 -> V_234 = V_183 ;
break;
case 7 :
V_8 -> V_234 = V_185 ;
break;
case 5 :
default:
V_8 -> V_234 = V_187 ;
break;
}
if ( ! ( V_210 & 0x8000 ) )
return 1 ;
if ( ! V_8 -> V_86 . V_93 [ 0 ] ) {
T_1 V_23 ;
V_178 = ( V_210 >> 11 ) & 0x3 ;
if ( V_178 == 0 )
V_23 = V_230 ;
else if ( V_178 == 1 )
V_23 = V_231 ;
else if ( V_178 == 2 )
V_23 = V_232 ;
else if ( V_178 == 3 )
V_23 = V_233 ;
else
return 1 ;
for ( V_28 = 0 ; V_28 < V_8 -> V_86 . V_87 ; V_28 ++ )
if ( V_8 -> V_86 . V_89 [ V_28 ] == V_23 )
return 1 ;
V_8 -> V_86 . V_93 [ 0 ] = V_23 ;
}
return 1 ;
}
static void F_84 ( struct V_5 * V_6 ,
T_1 V_230 , T_1 V_231 ,
T_1 V_232 , T_1 V_233 )
{
if ( ! F_83 ( V_6 , V_230 , V_231 , V_232 , V_233 ) ) {
struct V_7 * V_8 = V_6 -> V_8 ;
F_82 ( L_23
L_24 ) ;
V_8 -> V_234 = V_187 ;
}
F_74 ( V_6 ) ;
F_77 ( V_6 ) ;
}
static void F_85 ( struct V_5 * V_6 , int V_235 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
int V_10 = V_8 -> V_236 ;
#ifdef F_86
const char * V_237 = V_8 -> V_238 ;
#endif
int V_239 = 0 ;
if ( ! V_8 -> V_240 )
return;
while ( V_10 >= 0 ) {
const struct V_241 * V_242 = V_8 -> V_240 + V_10 ;
const struct V_243 * V_85 ;
switch ( V_242 -> type ) {
case V_244 :
if ( V_235 != V_245 || ! V_242 -> V_30 . V_246 )
break; ;
F_76 ( V_221 L_25
L_26 ,
V_6 -> V_222 , V_237 ) ;
V_8 -> V_211 . V_214 = V_242 -> V_30 . V_246 ;
V_8 -> V_211 . V_213 = 1 ;
break;
case V_247 :
V_85 = V_242 -> V_30 . V_135 ;
if ( V_235 != V_245 || ! V_85 )
break;
F_76 ( V_221 L_25
L_27 ,
V_6 -> V_222 , V_237 ) ;
for (; V_85 -> V_23 ; V_85 ++ )
F_87 ( V_6 , V_85 -> V_23 ,
V_85 -> V_57 ) ;
break;
case V_248 :
if ( V_235 != V_249 || ! V_242 -> V_30 . V_250 )
break;
F_76 ( V_221 L_25
L_28 ,
V_6 -> V_222 , V_237 ) ;
F_37 ( V_6 -> V_8 , V_242 -> V_30 . V_250 ) ;
break;
case V_251 :
if ( ! V_242 -> V_30 . V_252 )
break;
F_76 ( V_221 L_25
L_29 ,
V_6 -> V_222 , V_237 ) ;
V_242 -> V_30 . V_252 ( V_6 , V_242 , V_235 ) ;
break;
default:
F_88 ( V_253 L_25
L_30 ,
V_6 -> V_222 , V_242 -> type ) ;
break;
}
if ( ! V_242 -> V_254 )
break;
if ( ++ V_239 > 10 )
break;
V_10 = V_242 -> V_255 ;
}
}
static void F_89 ( struct V_5 * V_6 ,
const struct V_256 * V_257 ,
const struct V_258 * V_259 ,
const struct V_241 * V_260 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
int V_10 = - 1 ;
const char * V_50 = NULL ;
if ( V_6 -> V_237 && V_257 ) {
while ( V_257 -> V_50 ) {
if ( ! strcmp ( V_6 -> V_237 , V_257 -> V_50 ) ) {
V_10 = V_257 -> V_10 ;
V_50 = V_257 -> V_50 ;
break;
}
V_257 ++ ;
}
}
if ( V_10 < 0 ) {
V_259 = F_90 ( V_6 -> V_218 -> V_219 , V_259 ) ;
if ( V_259 ) {
V_10 = V_259 -> V_17 ;
#ifdef F_86
V_50 = V_259 -> V_50 ;
#endif
}
}
V_8 -> V_236 = V_10 ;
if ( V_10 >= 0 ) {
V_8 -> V_240 = V_260 ;
V_8 -> V_238 = V_50 ;
}
}
static int F_91 ( struct V_5 * V_6 ,
unsigned int V_125 )
{
unsigned int V_57 ;
F_32 ( V_6 , 0x20 , 0 , V_120 ,
V_125 ) ;
V_57 = F_21 ( V_6 , 0x20 , 0 ,
V_122 , 0 ) ;
return V_57 ;
}
static void F_92 ( struct V_5 * V_6 , unsigned int V_125 ,
unsigned int V_261 )
{
F_32 ( V_6 , 0x20 , 0 , V_120 ,
V_125 ) ;
F_32 ( V_6 , 0x20 , 0 , V_123 ,
V_261 ) ;
}
static void F_93 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
int V_28 ;
T_1 V_129 ;
for ( V_28 = 0 ; V_28 < V_8 -> V_86 . V_262 ; V_28 ++ ) {
V_129 = V_8 -> V_86 . V_263 [ V_28 ] ;
if ( V_129 ) {
F_32 ( V_6 , V_129 , 0 ,
V_58 ,
V_142 ) ;
}
}
V_129 = V_8 -> V_86 . V_264 ;
if ( V_129 )
F_32 ( V_6 , V_129 , 0 ,
V_58 ,
V_70 ) ;
}
static void F_94 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
int V_28 , V_38 ;
T_1 V_265 ;
for ( V_28 = 0 ; V_28 < V_8 -> V_86 . V_262 ; V_28 ++ ) {
V_38 = F_53 ( V_6 ,
V_8 -> V_86 . V_263 [ V_28 ] ,
& V_265 , 1 ) ;
if ( V_38 < 0 )
continue;
if ( ! V_28 ) {
V_8 -> V_40 . V_107 = V_265 ;
V_8 -> V_266 = V_8 -> V_86 . V_266 [ 0 ] ;
} else {
V_8 -> V_40 . V_108 = V_8 -> V_108 ;
if ( V_28 >= F_36 ( V_8 -> V_108 ) - 1 )
break;
V_8 -> V_108 [ V_28 - 1 ] = V_265 ;
}
}
if ( V_8 -> V_86 . V_264 ) {
V_265 = V_6 -> V_267 ;
for ( V_28 = 0 ; V_28 < V_6 -> V_268 ; V_28 ++ , V_265 ++ ) {
unsigned int V_269 = F_8 ( V_6 , V_265 ) ;
if ( F_7 ( V_269 ) != V_270 )
continue;
if ( ! ( V_269 & V_271 ) )
continue;
if ( ! ( V_269 & V_272 ) )
continue;
V_38 = F_52 ( V_6 , V_265 ,
V_8 -> V_86 . V_264 ) ;
if ( V_38 >= 0 ) {
V_8 -> V_111 = V_265 ;
break;
}
}
}
}
static void F_95 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
V_8 -> V_86 . V_93 [ 0 ] = 0x15 ;
V_8 -> V_86 . V_91 [ 0 ] = 0x14 ;
V_8 -> V_86 . V_91 [ 1 ] = 0x16 ;
V_8 -> V_86 . V_91 [ 2 ] = 0x17 ;
V_8 -> V_86 . V_91 [ 3 ] = 0x19 ;
V_8 -> V_86 . V_91 [ 4 ] = 0x1a ;
V_8 -> V_150 = 1 ;
V_8 -> V_143 = V_145 ;
}
static void F_96 ( struct V_5 * V_6 )
{
F_61 ( V_6 ) ;
F_50 ( V_6 ) ;
}
static void F_97 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
V_8 -> V_86 . V_93 [ 0 ] = 0x17 ;
V_8 -> V_86 . V_93 [ 1 ] = 0x1b ;
V_8 -> V_86 . V_91 [ 0 ] = 0x14 ;
V_8 -> V_86 . V_91 [ 1 ] = 0x15 ;
V_8 -> V_150 = 1 ;
V_8 -> V_143 = V_145 ;
}
static void F_98 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
V_8 -> V_86 . V_93 [ 0 ] = 0x15 ;
V_8 -> V_86 . V_91 [ 0 ] = 0x14 ;
V_8 -> V_86 . V_91 [ 1 ] = 0x16 ;
V_8 -> V_86 . V_91 [ 2 ] = 0x17 ;
V_8 -> V_150 = 1 ;
V_8 -> V_143 = V_145 ;
}
static void F_99 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
V_8 -> V_86 . V_93 [ 0 ] = 0x15 ;
V_8 -> V_86 . V_91 [ 0 ] = 0x14 ;
V_8 -> V_86 . V_91 [ 1 ] = 0x16 ;
V_8 -> V_86 . V_91 [ 2 ] = 0x17 ;
V_8 -> V_150 = 1 ;
V_8 -> V_143 = V_145 ;
}
static void F_100 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
V_8 -> V_86 . V_93 [ 0 ] = 0x15 ;
V_8 -> V_86 . V_91 [ 0 ] = 0x14 ;
V_8 -> V_86 . V_91 [ 1 ] = 0x16 ;
V_8 -> V_86 . V_91 [ 2 ] = 0x17 ;
V_8 -> V_150 = 1 ;
V_8 -> V_143 = V_145 ;
}
static void F_101 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
V_8 -> V_86 . V_93 [ 0 ] = 0x15 ;
V_8 -> V_86 . V_91 [ 0 ] = 0x14 ;
V_8 -> V_86 . V_91 [ 1 ] = 0x16 ;
V_8 -> V_86 . V_91 [ 2 ] = 0x1b ;
V_8 -> V_150 = 1 ;
V_8 -> V_143 = V_145 ;
}
static int F_102 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = V_6 -> V_8 ;
int V_38 ;
F_103 ( & V_6 -> V_273 ) ;
V_2 -> V_46 = F_104 ( V_8 -> V_25 [ 0 ] , 3 , 0 ,
V_32 ) ;
V_38 = F_105 ( V_2 , V_4 ) ;
F_106 ( & V_6 -> V_273 ) ;
return V_38 ;
}
static int F_107 ( struct V_1 * V_2 , int V_274 ,
unsigned int V_275 , unsigned int T_2 * V_276 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = V_6 -> V_8 ;
int V_38 ;
F_103 ( & V_6 -> V_273 ) ;
V_2 -> V_46 = F_104 ( V_8 -> V_25 [ 0 ] , 3 , 0 ,
V_32 ) ;
V_38 = F_108 ( V_2 , V_274 , V_275 , V_276 ) ;
F_106 ( & V_6 -> V_273 ) ;
return V_38 ;
}
static int F_109 ( struct V_1 * V_2 ,
struct V_14 * V_15 ,
T_3 V_252 , bool V_277 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = V_6 -> V_8 ;
int V_28 , V_38 = 0 ;
F_103 ( & V_6 -> V_273 ) ;
if ( V_277 && V_8 -> V_171 ) {
for ( V_28 = 0 ; V_28 < V_8 -> V_110 ; V_28 ++ ) {
V_2 -> V_46 =
F_104 ( V_8 -> V_25 [ V_28 ] ,
3 , 0 , V_32 ) ;
V_38 = V_252 ( V_2 , V_15 ) ;
if ( V_38 < 0 )
goto error;
}
} else {
V_28 = F_3 ( V_2 , & V_15 -> V_10 ) ;
V_2 -> V_46 =
F_104 ( V_8 -> V_25 [ V_28 ] ,
3 , 0 , V_32 ) ;
V_38 = V_252 ( V_2 , V_15 ) ;
}
error:
F_106 ( & V_6 -> V_273 ) ;
return V_38 ;
}
static int F_110 ( struct V_1 * V_2 ,
struct V_14 * V_15 )
{
return F_109 ( V_2 , V_15 ,
V_278 , false ) ;
}
static int F_111 ( struct V_1 * V_2 ,
struct V_14 * V_15 )
{
return F_109 ( V_2 , V_15 ,
V_279 , true ) ;
}
static int F_112 ( struct V_1 * V_2 ,
struct V_14 * V_15 )
{
return F_109 ( V_2 , V_15 ,
V_280 , false ) ;
}
static int F_113 ( struct V_1 * V_2 ,
struct V_14 * V_15 )
{
return F_109 ( V_2 , V_15 ,
V_281 , true ) ;
}
static int F_114 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
struct V_1 * V_282 = NULL ;
const struct V_94 * V_193 ;
int V_28 , V_283 , V_38 ;
unsigned int V_284 ;
T_1 V_23 ;
for ( V_28 = 0 ; V_28 < V_8 -> V_96 ; V_28 ++ ) {
V_38 = F_115 ( V_6 , V_8 -> V_97 [ V_28 ] ) ;
if ( V_38 < 0 )
return V_38 ;
}
if ( V_8 -> V_104 ) {
V_38 = F_115 ( V_6 , V_8 -> V_104 ) ;
if ( V_38 < 0 )
return V_38 ;
}
if ( V_8 -> V_40 . V_107 ) {
V_38 = F_116 ( V_6 ,
V_8 -> V_40 . V_107 ) ;
if ( V_38 < 0 )
return V_38 ;
if ( ! V_8 -> V_285 ) {
V_38 = F_117 ( V_6 ,
& V_8 -> V_40 ) ;
if ( V_38 < 0 )
return V_38 ;
V_8 -> V_40 . V_286 = 1 ;
}
}
if ( V_8 -> V_111 ) {
V_38 = F_118 ( V_6 , V_8 -> V_111 ) ;
if ( V_38 < 0 )
return V_38 ;
}
#ifdef F_119
if ( V_8 -> V_287 ) {
const struct V_94 * V_193 ;
for ( V_193 = V_288 ; V_193 -> V_50 ; V_193 ++ ) {
struct V_1 * V_282 ;
V_282 = F_120 ( V_193 , V_6 ) ;
if ( ! V_282 )
return - V_194 ;
V_282 -> V_46 = V_8 -> V_287 ;
V_38 = F_121 ( V_6 , 0 , V_282 ) ;
if ( V_38 < 0 )
return V_38 ;
}
}
#endif
if ( ! V_8 -> V_285 &&
! F_122 ( V_6 , L_31 ) ) {
unsigned int V_289 [ 4 ] ;
F_123 ( V_6 , V_8 -> V_290 ,
V_59 , V_289 ) ;
V_38 = F_124 ( V_6 , L_31 ,
V_289 , V_291 ) ;
if ( V_38 < 0 )
return V_38 ;
}
if ( ! V_8 -> V_285 &&
! F_122 ( V_6 , L_32 ) ) {
V_38 = F_124 ( V_6 , L_32 ,
NULL , V_292 ) ;
if ( V_38 < 0 )
return V_38 ;
}
if ( V_8 -> V_24 || V_8 -> V_25 ) {
V_282 = F_122 ( V_6 , L_33 ) ;
if ( ! V_282 )
V_282 = F_122 ( V_6 , L_34 ) ;
for ( V_28 = 0 ; V_282 && V_28 < V_282 -> V_48 ; V_28 ++ ) {
const T_1 * V_293 = V_8 -> V_24 ;
if ( ! V_293 )
V_293 = V_8 -> V_25 ;
V_38 = F_125 ( V_6 , V_282 , V_28 , V_293 [ V_28 ] ) ;
if ( V_38 < 0 )
return V_38 ;
}
}
if ( V_8 -> V_104 ) {
const char * V_294 = V_282 ? V_282 -> V_10 . V_50 : NULL ;
for ( V_193 = V_8 -> V_104 ; V_193 -> V_50 ; V_193 ++ ) {
if ( V_294 && strcmp ( V_193 -> V_50 , V_294 ) == 0 )
continue;
V_282 = F_122 ( V_6 , V_193 -> V_50 ) ;
for ( V_28 = 0 ; V_282 && V_28 < V_282 -> V_48 ; V_28 ++ ) {
V_38 = F_125 ( V_6 , V_282 , V_28 ,
V_8 -> V_25 [ V_28 ] ) ;
if ( V_38 < 0 )
return V_38 ;
}
}
}
for ( V_28 = 0 ; V_28 < V_8 -> V_96 ; V_28 ++ ) {
for ( V_193 = V_8 -> V_97 [ V_28 ] ; V_193 -> V_50 ; V_193 ++ ) {
if ( V_193 -> V_295 != V_296 )
continue;
V_282 = F_122 ( V_6 , V_193 -> V_50 ) ;
if ( V_282 == NULL )
continue;
V_284 = V_193 -> V_297 ;
for ( V_283 = 0 ; V_283 < 4 ; V_283 ++ , V_284 >>= 8 ) {
V_23 = V_284 & 0x3f ;
if ( V_23 == 0 )
continue;
switch ( V_284 & 0xc0 ) {
case V_298 :
V_23 = V_8 -> V_86 . V_91 [ V_23 ] ;
break;
case V_299 :
V_23 = V_8 -> V_86 . V_89 [ V_23 ] ;
break;
case V_300 :
V_23 = V_8 -> V_86 . V_93 [ V_23 ] ;
break;
default:
continue;
}
V_38 = F_125 ( V_6 , V_282 , 0 , V_23 ) ;
if ( V_38 < 0 )
return V_38 ;
}
V_284 = V_193 -> V_46 ;
for ( V_283 = 0 ; V_283 < 4 ; V_283 ++ , V_284 >>= 8 ) {
V_23 = V_284 & 0xff ;
if ( V_23 == 0 )
continue;
V_38 = F_125 ( V_6 , V_282 , 0 , V_23 ) ;
if ( V_38 < 0 )
return V_38 ;
}
}
}
F_126 ( V_6 ) ;
return 0 ;
}
static void F_127 ( struct V_5 * V_6 )
{
unsigned int V_136 ;
unsigned char V_301 ;
V_136 = F_47 ( V_6 , 0x18 ) ;
V_301 = V_136 ? V_31 : 0 ;
F_9 ( V_6 , 0x0b , V_32 , 1 , V_31 , V_301 ) ;
}
static void F_128 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
V_8 -> V_86 . V_93 [ 0 ] = 0x14 ;
V_8 -> V_86 . V_91 [ 0 ] = 0x15 ;
V_8 -> V_86 . V_91 [ 0 ] = 0x16 ;
V_8 -> V_150 = 1 ;
V_8 -> V_143 = V_145 ;
}
static void F_129 ( struct V_5 * V_6 )
{
F_50 ( V_6 ) ;
F_127 ( V_6 ) ;
}
static void F_130 ( struct V_5 * V_6 ,
unsigned int V_173 )
{
switch ( V_173 >> 28 ) {
case V_177 :
F_127 ( V_6 ) ;
break;
default:
F_58 ( V_6 , V_173 ) ;
break;
}
}
static void F_131 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
V_8 -> V_86 . V_93 [ 0 ] = 0x14 ;
V_8 -> V_86 . V_91 [ 0 ] = 0x15 ;
V_8 -> V_150 = 1 ;
V_8 -> V_143 = V_145 ;
}
static void F_132 ( struct V_5 * V_6 )
{
unsigned int V_136 ;
V_136 = F_21 ( V_6 , 0x21 , 0 ,
V_302 , 0 ) ;
V_136 &= V_303 ;
F_9 ( V_6 , 0x0c , V_59 , 0 ,
V_303 , V_136 ) ;
F_9 ( V_6 , 0x0d , V_59 , 0 ,
V_303 , V_136 ) ;
}
static void F_133 ( struct V_5 * V_6 ,
unsigned int V_173 )
{
if ( ( V_173 >> 28 ) == V_304 )
F_132 ( V_6 ) ;
else
F_58 ( V_6 , V_173 ) ;
}
static void F_134 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
V_8 -> V_86 . V_93 [ 0 ] = 0x1b ;
V_8 -> V_86 . V_91 [ 0 ] = 0x17 ;
V_8 -> V_150 = 1 ;
V_8 -> V_143 = V_145 ;
}
static void F_135 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
V_8 -> V_86 . V_93 [ 0 ] = 0x1b ;
V_8 -> V_86 . V_91 [ 0 ] = 0x14 ;
V_8 -> V_150 = 1 ;
V_8 -> V_143 = V_145 ;
}
static void F_136 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
F_50 ( V_6 ) ;
if ( V_8 -> V_151 )
F_32 ( V_6 , 0x01 , 0 , V_63 , 0 ) ;
else
F_32 ( V_6 , 0x01 , 0 , V_63 , 2 ) ;
}
static void F_137 ( struct V_5 * V_6 ,
unsigned int V_173 )
{
if ( ( V_173 >> 28 ) == V_175 )
F_136 ( V_6 ) ;
}
static void F_138 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
V_8 -> V_86 . V_93 [ 0 ] = 0x14 ;
V_8 -> V_86 . V_91 [ 0 ] = 0x1b ;
V_8 -> V_150 = 1 ;
V_8 -> V_143 = V_145 ;
}
static int F_139 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
unsigned int V_28 ;
F_40 ( V_6 ) ;
F_66 ( V_6 , V_8 -> V_234 ) ;
for ( V_28 = 0 ; V_28 < V_8 -> V_100 ; V_28 ++ )
F_67 ( V_6 , V_8 -> V_101 [ V_28 ] ) ;
F_140 ( V_6 ) ;
if ( V_8 -> V_113 )
V_8 -> V_113 ( V_6 ) ;
F_85 ( V_6 , V_305 ) ;
F_141 ( V_6 , 0x01 ) ;
return 0 ;
}
static void F_142 ( struct V_5 * V_6 , unsigned int V_173 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
if ( V_8 -> V_112 )
V_8 -> V_112 ( V_6 , V_173 ) ;
}
static int F_143 ( struct V_5 * V_6 , T_1 V_23 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
return F_144 ( V_6 , & V_8 -> V_115 , V_23 ) ;
}
static int F_145 ( struct V_306 * V_307 ,
struct V_5 * V_6 ,
struct V_308 * V_309 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
return F_146 ( V_6 , & V_8 -> V_40 , V_309 ,
V_307 ) ;
}
static int F_147 ( struct V_306 * V_307 ,
struct V_5 * V_6 ,
unsigned int V_310 ,
unsigned int V_311 ,
struct V_308 * V_309 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
return F_148 ( V_6 , & V_8 -> V_40 ,
V_310 , V_311 , V_309 ) ;
}
static int F_149 ( struct V_306 * V_307 ,
struct V_5 * V_6 ,
struct V_308 * V_309 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
return F_150 ( V_6 , & V_8 -> V_40 ) ;
}
static int F_151 ( struct V_306 * V_307 ,
struct V_5 * V_6 ,
struct V_308 * V_309 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
return F_152 ( V_6 , & V_8 -> V_40 ) ;
}
static int F_153 ( struct V_306 * V_307 ,
struct V_5 * V_6 ,
unsigned int V_310 ,
unsigned int V_311 ,
struct V_308 * V_309 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
return F_154 ( V_6 , & V_8 -> V_40 ,
V_310 , V_311 , V_309 ) ;
}
static int F_155 ( struct V_306 * V_307 ,
struct V_5 * V_6 ,
struct V_308 * V_309 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
return F_156 ( V_6 , & V_8 -> V_40 ) ;
}
static int F_157 ( struct V_306 * V_307 ,
struct V_5 * V_6 ,
struct V_308 * V_309 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
return F_158 ( V_6 , & V_8 -> V_40 ) ;
}
static int F_159 ( struct V_306 * V_307 ,
struct V_5 * V_6 ,
unsigned int V_310 ,
unsigned int V_311 ,
struct V_308 * V_309 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
F_56 ( V_6 , V_8 -> V_25 [ V_309 -> V_312 + 1 ] ,
V_310 , 0 , V_311 ) ;
return 0 ;
}
static int F_160 ( struct V_306 * V_307 ,
struct V_5 * V_6 ,
struct V_308 * V_309 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
F_161 ( V_6 ,
V_8 -> V_25 [ V_309 -> V_312 + 1 ] ) ;
return 0 ;
}
static int F_162 ( struct V_306 * V_307 ,
struct V_5 * V_6 ,
unsigned int V_310 ,
unsigned int V_311 ,
struct V_308 * V_309 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
V_8 -> V_161 = V_8 -> V_25 [ V_8 -> V_160 ] ;
V_8 -> V_162 = V_310 ;
V_8 -> V_163 = V_311 ;
F_56 ( V_6 , V_8 -> V_161 , V_310 , 0 , V_311 ) ;
return 0 ;
}
static int F_163 ( struct V_306 * V_307 ,
struct V_5 * V_6 ,
struct V_308 * V_309 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
F_161 ( V_6 , V_8 -> V_161 ) ;
V_8 -> V_161 = 0 ;
return 0 ;
}
static int F_164 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
struct V_313 * V_314 = V_8 -> V_315 ;
int V_28 ;
V_6 -> V_316 = 1 ;
V_6 -> V_317 = V_314 ;
if ( V_8 -> V_285 )
goto V_318;
snprintf ( V_8 -> V_319 , sizeof( V_8 -> V_319 ) ,
L_35 , V_6 -> V_222 ) ;
V_314 -> V_50 = V_8 -> V_319 ;
if ( V_8 -> V_320 ) {
if ( F_35 ( ! V_8 -> V_40 . V_106 ) )
return - V_192 ;
V_314 -> V_321 [ V_322 ] = * ( V_8 -> V_320 ) ;
V_314 -> V_321 [ V_322 ] . V_23 = V_8 -> V_40 . V_106 [ 0 ] ;
}
if ( V_8 -> V_323 ) {
if ( F_35 ( ! V_8 -> V_25 ) )
return - V_192 ;
V_314 -> V_321 [ V_324 ] = * ( V_8 -> V_323 ) ;
V_314 -> V_321 [ V_324 ] . V_23 = V_8 -> V_25 [ 0 ] ;
}
if ( V_8 -> V_35 ) {
V_314 -> V_321 [ V_322 ] . V_325 = 0 ;
for ( V_28 = 0 ; V_28 < V_8 -> V_36 ; V_28 ++ ) {
if ( V_8 -> V_35 [ V_28 ] . V_105 > V_314 -> V_321 [ V_322 ] . V_325 ) {
V_314 -> V_321 [ V_322 ] . V_325 = V_8 -> V_35 [ V_28 ] . V_105 ;
}
}
}
V_318:
if ( V_8 -> V_40 . V_107 || V_8 -> V_111 ) {
snprintf ( V_8 -> V_326 ,
sizeof( V_8 -> V_326 ) ,
L_36 , V_6 -> V_222 ) ;
V_6 -> V_316 = 2 ;
V_6 -> V_108 = V_8 -> V_40 . V_108 ;
V_314 = V_8 -> V_315 + 1 ;
V_314 -> V_50 = V_8 -> V_326 ;
if ( V_8 -> V_266 )
V_314 -> V_327 = V_8 -> V_266 ;
else
V_314 -> V_327 = V_328 ;
if ( V_8 -> V_40 . V_107 &&
V_8 -> V_329 ) {
V_314 -> V_321 [ V_322 ] = * ( V_8 -> V_329 ) ;
V_314 -> V_321 [ V_322 ] . V_23 = V_8 -> V_40 . V_107 ;
}
if ( V_8 -> V_111 &&
V_8 -> V_330 ) {
V_314 -> V_321 [ V_324 ] = * ( V_8 -> V_330 ) ;
V_314 -> V_321 [ V_324 ] . V_23 = V_8 -> V_111 ;
}
V_6 -> V_331 = 1 ;
}
if ( V_8 -> V_285 )
return 0 ;
if ( ( V_8 -> V_332 && V_8 -> V_333 ) ||
( V_8 -> V_110 > 1 && V_8 -> V_334 ) ) {
V_6 -> V_316 = 3 ;
V_314 = V_8 -> V_315 + 2 ;
V_314 -> V_50 = V_8 -> V_319 ;
if ( V_8 -> V_332 ) {
V_314 -> V_321 [ V_322 ] =
* V_8 -> V_333 ;
V_314 -> V_321 [ V_322 ] . V_23 =
V_8 -> V_332 ;
} else {
V_314 -> V_321 [ V_322 ] =
V_335 ;
V_314 -> V_321 [ V_322 ] . V_23 = 0 ;
}
if ( V_8 -> V_110 > 1 && V_8 -> V_334 ) {
V_314 -> V_321 [ V_324 ] =
* V_8 -> V_334 ;
V_314 -> V_321 [ V_324 ] . V_23 =
V_8 -> V_25 [ 1 ] ;
V_314 -> V_321 [ V_324 ] . V_336 =
V_8 -> V_110 - 1 ;
} else {
V_314 -> V_321 [ V_324 ] =
V_335 ;
V_314 -> V_321 [ V_324 ] . V_23 = 0 ;
}
}
return 0 ;
}
static inline void F_165 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
if ( V_8 && V_8 -> V_337 )
V_8 -> V_337 ( V_6 ) ;
F_166 ( V_6 ) ;
}
static void F_126 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
if ( V_8 -> V_338 . V_339 ) {
struct V_94 * V_282 = V_8 -> V_338 . V_339 ;
int V_28 ;
for ( V_28 = 0 ; V_28 < V_8 -> V_338 . V_340 ; V_28 ++ )
F_167 ( V_282 [ V_28 ] . V_50 ) ;
}
F_168 ( & V_8 -> V_338 ) ;
}
static void F_169 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
if ( ! V_8 )
return;
F_165 ( V_6 ) ;
F_170 ( V_6 ) ;
F_126 ( V_6 ) ;
F_167 ( V_8 ) ;
F_171 ( V_6 ) ;
}
static void F_172 ( struct V_5 * V_6 )
{
F_63 ( V_6 , false ) ;
}
static int F_173 ( struct V_5 * V_6 , T_4 V_341 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
F_165 ( V_6 ) ;
if ( V_8 && V_8 -> V_114 )
V_8 -> V_114 ( V_6 ) ;
return 0 ;
}
static int F_174 ( struct V_5 * V_6 )
{
F_65 ( 150 ) ;
V_6 -> V_342 . V_343 ( V_6 ) ;
F_175 ( V_6 ) ;
F_176 ( V_6 ) ;
F_141 ( V_6 , 0x01 ) ;
return 0 ;
}
static int F_177 ( struct V_5 * V_6 , const char * V_50 )
{
F_167 ( V_6 -> V_222 ) ;
V_6 -> V_222 = F_73 ( V_50 , V_196 ) ;
if ( ! V_6 -> V_222 ) {
F_169 ( V_6 ) ;
return - V_194 ;
}
return 0 ;
}
static int F_178 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
static const char * const V_190 [] = {
L_37 , L_38 , L_39 ,
L_40 , L_41 , L_42 , L_43 , L_44
} ;
V_4 -> type = V_47 ;
V_4 -> V_48 = 1 ;
V_4 -> V_17 . V_18 . V_33 = 8 ;
if ( V_4 -> V_17 . V_18 . V_19 >= 8 )
V_4 -> V_17 . V_18 . V_19 = 7 ;
strcpy ( V_4 -> V_17 . V_18 . V_50 , V_190 [ V_4 -> V_17 . V_18 . V_19 ] ) ;
return 0 ;
}
static int F_179 ( struct V_1 * V_2 ,
struct V_14 * V_15 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
T_1 V_23 = ( T_1 ) V_2 -> V_46 ;
unsigned int V_344 , V_19 = 0 ;
V_344 = F_21 ( V_6 , V_23 , 0 ,
V_54 , 0 ) ;
if ( V_344 & V_345 ) {
if ( V_344 & V_346 )
V_19 = 2 ;
else
V_19 = 1 ;
} else if ( V_344 & V_347 ) {
switch ( V_344 & V_348 ) {
case V_349 : V_19 = 3 ; break;
case V_350 : V_19 = 4 ; break;
case V_351 : V_19 = 5 ; break;
case V_352 : V_19 = 6 ; break;
case V_353 : V_19 = 7 ; break;
}
}
V_15 -> V_17 . V_18 . V_19 [ 0 ] = V_19 ;
return 0 ;
}
static int F_180 ( struct V_1 * V_2 ,
struct V_14 * V_15 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
T_1 V_23 = ( T_1 ) V_2 -> V_46 ;
static const unsigned int V_354 [] = {
0 , V_345 , V_345 | V_346 ,
V_347 | V_349 ,
V_347 | V_350 ,
V_347 | V_351 ,
V_347 | V_352 ,
V_347 | V_353 ,
} ;
unsigned int V_355 , V_356 ;
V_355 = F_21 ( V_6 , V_23 , 0 ,
V_54 , 0 ) ;
V_356 = V_354 [ V_15 -> V_17 . V_18 . V_19 [ 0 ] ] ;
if ( V_355 != V_356 ) {
int V_57 ;
F_23 ( V_6 , V_23 , 0 ,
V_58 ,
V_356 ) ;
V_57 = V_15 -> V_17 . V_18 . V_19 [ 0 ] >= 3 ?
V_31 : 0 ;
F_9 ( V_6 , V_23 , V_59 , 0 ,
V_31 , V_57 ) ;
return 1 ;
}
return 0 ;
}
static int F_181 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
static const char * const V_190 [] = {
L_45 , L_46 , L_47 , L_48
} ;
V_4 -> type = V_47 ;
V_4 -> V_48 = 1 ;
V_4 -> V_17 . V_18 . V_33 = 4 ;
if ( V_4 -> V_17 . V_18 . V_19 >= 4 )
V_4 -> V_17 . V_18 . V_19 = 3 ;
strcpy ( V_4 -> V_17 . V_18 . V_50 , V_190 [ V_4 -> V_17 . V_18 . V_19 ] ) ;
return 0 ;
}
static int F_182 ( struct V_1 * V_2 ,
struct V_14 * V_15 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
T_1 V_23 = ( T_1 ) V_2 -> V_46 ;
unsigned int V_357 ;
V_357 = F_21 ( V_6 , V_23 , 0 , V_358 , 0 ) ;
V_15 -> V_17 . V_18 . V_19 [ 0 ] = V_357 & 3 ;
return 0 ;
}
static int F_183 ( struct V_1 * V_2 ,
struct V_14 * V_15 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
T_1 V_23 = ( T_1 ) V_2 -> V_46 ;
unsigned int V_357 ;
V_357 = F_21 ( V_6 , V_23 , 0 , V_358 , 0 ) & 3 ;
if ( V_15 -> V_17 . V_18 . V_19 [ 0 ] != V_357 ) {
V_357 = V_15 -> V_17 . V_18 . V_19 [ 0 ] & 3 ;
F_23 ( V_6 , V_23 , 0 ,
V_172 , V_357 ) ;
return 1 ;
}
return 0 ;
}
static struct V_94 * F_72 ( struct V_7 * V_8 )
{
F_184 ( & V_8 -> V_338 , sizeof( struct V_94 ) , 32 ) ;
return F_185 ( & V_8 -> V_338 ) ;
}
static int F_186 ( struct V_7 * V_8 , int type , const char * V_50 ,
int V_359 , unsigned long V_57 )
{
struct V_94 * V_193 ;
V_193 = F_72 ( V_8 ) ;
if ( ! V_193 )
return - V_194 ;
* V_193 = V_360 [ type ] ;
V_193 -> V_50 = F_73 ( V_50 , V_196 ) ;
if ( ! V_193 -> V_50 )
return - V_194 ;
V_193 -> V_34 = V_359 ;
if ( F_187 ( V_57 ) )
V_193 -> V_297 = V_361 ;
V_193 -> V_46 = V_57 ;
return 0 ;
}
static int F_188 ( struct V_7 * V_8 , int type ,
const char * V_362 , const char * V_45 ,
const char * V_363 , int V_359 , unsigned long V_57 )
{
char V_50 [ 32 ] ;
snprintf ( V_50 , sizeof( V_50 ) , L_49 , V_362 , V_45 , V_363 ) ;
return F_186 ( V_8 , type , V_50 , V_359 , V_57 ) ;
}
static int F_189 ( struct V_7 * V_8 ,
const struct V_84 * V_85 )
{
T_1 V_23 ;
int V_364 [ 4 ] ;
int V_28 , V_283 ;
memset ( V_364 , 0 , sizeof( V_364 ) ) ;
V_8 -> V_40 . V_106 = V_8 -> V_365 ;
for ( V_28 = 0 ; V_28 < V_85 -> V_87 ; V_28 ++ ) {
V_23 = V_85 -> V_89 [ V_28 ] ;
if ( F_190 ( V_23 ) ) {
int V_29 = F_191 ( V_23 ) ;
V_8 -> V_365 [ V_28 ] = F_192 ( V_29 ) ;
V_364 [ V_29 ] = 1 ;
}
}
for ( V_28 = 0 ; V_28 < V_85 -> V_87 ; V_28 ++ ) {
V_23 = V_85 -> V_89 [ V_28 ] ;
if ( F_190 ( V_23 ) )
continue;
for ( V_283 = 0 ; V_283 < V_85 -> V_87 ; V_283 ++ ) {
if ( ! V_364 [ V_283 ] ) {
V_8 -> V_365 [ V_28 ] =
F_192 ( V_283 ) ;
V_364 [ V_283 ] = 1 ;
break;
}
}
}
V_8 -> V_40 . V_43 = V_85 -> V_87 ;
return 0 ;
}
static const char * F_193 ( struct V_7 * V_8 ,
bool V_366 )
{
struct V_84 * V_85 = & V_8 -> V_86 ;
if ( V_85 -> V_87 == 1 && ! V_8 -> V_367 &&
! V_85 -> V_92 && ! V_85 -> V_90 && V_366 )
return L_50 ;
switch ( V_85 -> V_368 ) {
case V_369 :
if ( V_85 -> V_87 == 1 )
return L_51 ;
break;
case V_370 :
return L_52 ;
default:
if ( V_85 -> V_87 == 1 && ! V_8 -> V_367 )
return L_53 ;
break;
}
return NULL ;
}
static int F_194 ( struct V_7 * V_8 ,
const struct V_84 * V_85 )
{
static const char * const V_371 [ 4 ] = {
L_45 , L_46 , NULL , L_48
} ;
const char * V_362 = F_193 ( V_8 , false ) ;
T_1 V_23 ;
int V_28 , V_38 , V_372 ;
V_372 = V_85 -> V_87 ;
if ( V_8 -> V_367 > 0 )
V_372 += V_8 -> V_367 ;
for ( V_28 = 0 ; V_28 < V_372 ; V_28 ++ ) {
if ( ! V_8 -> V_40 . V_106 [ V_28 ] )
continue;
V_23 = F_195 ( F_196 ( V_8 -> V_40 . V_106 [ V_28 ] ) ) ;
if ( ! V_362 && V_28 == 2 ) {
V_38 = F_197 ( V_8 , V_373 ,
L_54 ,
F_104 ( V_23 , 1 , 0 ,
V_59 ) ) ;
if ( V_38 < 0 )
return V_38 ;
V_38 = F_197 ( V_8 , V_373 ,
L_55 ,
F_104 ( V_23 , 2 , 0 ,
V_59 ) ) ;
if ( V_38 < 0 )
return V_38 ;
V_38 = F_198 ( V_8 , V_374 ,
L_54 ,
F_104 ( V_23 , 1 , 2 ,
V_32 ) ) ;
if ( V_38 < 0 )
return V_38 ;
V_38 = F_198 ( V_8 , V_374 ,
L_55 ,
F_104 ( V_23 , 2 , 2 ,
V_32 ) ) ;
if ( V_38 < 0 )
return V_38 ;
} else {
const char * V_50 = V_362 ;
int V_34 = V_28 ;
if ( ! V_50 ) {
V_50 = V_371 [ V_28 ] ;
V_34 = 0 ;
}
V_38 = F_199 ( V_8 , V_373 ,
V_50 , V_34 ,
F_104 ( V_23 , 3 , 0 ,
V_59 ) ) ;
if ( V_38 < 0 )
return V_38 ;
V_38 = F_200 ( V_8 , V_374 ,
V_50 , V_34 ,
F_104 ( V_23 , 3 , 2 ,
V_32 ) ) ;
if ( V_38 < 0 )
return V_38 ;
}
}
return 0 ;
}
static int F_201 ( struct V_7 * V_8 , T_1 V_129 ,
const char * V_362 )
{
T_1 V_23 ;
int V_38 ;
if ( ! V_129 )
return 0 ;
if ( F_190 ( V_129 ) ) {
V_23 = F_192 ( F_191 ( V_129 ) ) ;
if ( ! V_8 -> V_40 . V_109 )
V_8 -> V_40 . V_109 = V_23 ;
else
V_8 -> V_40 . V_375 [ 0 ] = V_23 ;
V_23 = F_195 ( F_191 ( V_129 ) ) ;
V_38 = F_197 ( V_8 , V_373 , V_362 ,
F_104 ( V_23 , 3 , 0 , V_59 ) ) ;
if ( V_38 < 0 )
return V_38 ;
V_38 = F_198 ( V_8 , V_374 , V_362 ,
F_104 ( V_23 , 3 , 2 , V_32 ) ) ;
if ( V_38 < 0 )
return V_38 ;
} else if ( F_202 ( V_129 ) ) {
V_38 = F_198 ( V_8 , V_376 , V_362 ,
F_104 ( V_129 , 3 , 0 , V_59 ) ) ;
if ( V_38 < 0 )
return V_38 ;
}
return 0 ;
}
static int F_203 ( struct V_7 * V_8 , T_1 V_129 ,
const char * V_377 , int V_378 ,
int V_29 , T_1 V_379 )
{
int V_38 ;
V_38 = F_199 ( V_8 , V_373 , V_377 , V_378 ,
F_104 ( V_379 , 3 , V_29 , V_32 ) ) ;
if ( V_38 < 0 )
return V_38 ;
V_38 = F_200 ( V_8 , V_376 , V_377 , V_378 ,
F_104 ( V_379 , 3 , V_29 , V_32 ) ) ;
if ( V_38 < 0 )
return V_38 ;
return 0 ;
}
static int F_204 ( struct V_5 * V_6 , T_1 V_23 )
{
unsigned int V_72 = F_31 ( V_6 , V_23 ) ;
return ( V_72 & V_380 ) != 0 ;
}
static int F_205 ( struct V_5 * V_6 ,
const struct V_84 * V_85 ,
T_1 V_381 ,
T_1 V_382 , T_1 V_383 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
struct V_21 * V_22 = & V_8 -> V_384 [ 0 ] ;
int V_28 , V_38 , V_29 , V_385 = 0 ;
const char * V_386 = NULL ;
for ( V_28 = 0 ; V_28 < V_85 -> V_202 ; V_28 ++ ) {
T_1 V_129 ;
const char * V_387 ;
V_129 = V_85 -> V_203 [ V_28 ] . V_129 ;
if ( ! F_204 ( V_6 , V_129 ) )
continue;
V_387 = F_206 ( V_6 , V_85 , V_28 ) ;
if ( V_386 && ! strcmp ( V_387 , V_386 ) )
V_385 ++ ;
else
V_385 = 0 ;
V_386 = V_387 ;
if ( V_381 ) {
V_29 = F_52 ( V_6 , V_381 , V_129 ) ;
if ( V_29 >= 0 ) {
V_38 = F_203 ( V_8 , V_129 ,
V_387 , V_385 ,
V_29 , V_381 ) ;
if ( V_38 < 0 )
return V_38 ;
}
}
if ( ! V_382 )
continue;
V_29 = F_52 ( V_6 , V_382 , V_129 ) ;
if ( V_29 < 0 && V_383 )
V_29 = F_52 ( V_6 , V_383 , V_129 ) ;
if ( V_29 >= 0 )
F_207 ( V_22 , V_387 , V_29 , NULL ) ;
}
return 0 ;
}
static int F_208 ( struct V_5 * V_6 ,
const struct V_84 * V_85 )
{
return F_205 ( V_6 , V_85 , 0x0b , 0x08 , 0x09 ) ;
}
static void F_209 ( struct V_5 * V_6 , T_1 V_23 ,
unsigned int V_388 )
{
F_32 ( V_6 , V_23 , 0 , V_58 ,
V_388 ) ;
F_32 ( V_6 , V_23 , 0 , V_389 ,
V_390 ) ;
}
static void F_210 ( struct V_5 * V_6 ,
T_1 V_23 , int V_388 ,
int V_391 )
{
F_209 ( V_6 , V_23 , V_388 ) ;
if ( F_202 ( V_23 ) ) {
struct V_7 * V_8 = V_6 -> V_8 ;
int V_29 = F_211 ( V_23 ) ;
F_32 ( V_6 , F_212 ( V_29 ) , 0 ,
V_172 ,
F_196 ( V_8 -> V_40 . V_106 [ V_391 ] ) ) ;
}
}
static int F_213 ( int V_368 )
{
if ( V_368 == V_370 )
return V_141 ;
else
return V_142 ;
}
static void F_214 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
int V_28 ;
for ( V_28 = 0 ; V_28 < V_8 -> V_86 . V_87 ; V_28 ++ ) {
T_1 V_23 = V_8 -> V_86 . V_89 [ V_28 ] ;
int V_388 = F_213 ( V_8 -> V_86 . V_368 ) ;
F_210 ( V_6 , V_23 , V_388 , V_28 ) ;
}
}
static void F_215 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
T_1 V_129 ;
V_129 = V_8 -> V_86 . V_91 [ 0 ] ;
if ( V_129 )
F_210 ( V_6 , V_129 , V_142 , 0 ) ;
V_129 = V_8 -> V_86 . V_93 [ 0 ] ;
if ( V_129 )
F_210 ( V_6 , V_129 , V_141 , 0 ) ;
}
static void F_216 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
struct V_84 * V_85 = & V_8 -> V_86 ;
int V_28 ;
for ( V_28 = 0 ; V_28 < V_85 -> V_202 ; V_28 ++ ) {
T_1 V_23 = V_85 -> V_203 [ V_28 ] . V_129 ;
if ( F_204 ( V_6 , V_23 ) ) {
F_30 ( V_6 , V_23 , V_85 -> V_203 [ V_28 ] . type ) ;
if ( V_23 != V_392 &&
( F_8 ( V_6 , V_23 ) & V_393 ) )
F_32 ( V_6 , V_23 , 0 ,
V_389 ,
V_394 ) ;
}
}
}
static void F_217 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
int V_395 ;
for ( V_395 = 0 ; V_395 < V_8 -> V_110 ; V_395 ++ ) {
unsigned int V_9 ;
const struct V_21 * V_22 ;
V_9 = V_395 >= V_8 -> V_11 ? 0 : V_395 ;
V_22 = & V_8 -> V_12 [ V_9 ] ;
if ( ! V_22 -> V_13 && V_9 > 0 )
V_22 = & V_8 -> V_12 [ 0 ] ;
if ( V_22 )
F_32 ( V_6 , V_8 -> V_25 [ V_395 ] , 0 ,
V_172 ,
V_22 -> V_33 [ 0 ] . V_34 ) ;
}
}
static int F_218 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
int V_38 ;
static const T_1 V_396 [] = { 0x1d , 0 } ;
V_38 = F_219 ( V_6 , & V_8 -> V_86 ,
V_396 ) ;
if ( V_38 < 0 )
return V_38 ;
if ( ! V_8 -> V_86 . V_87 )
return 0 ;
V_38 = F_189 ( V_8 , & V_8 -> V_86 ) ;
if ( V_38 < 0 )
return V_38 ;
V_38 = F_220 ( V_6 ) ;
if ( V_38 < 0 )
return V_38 ;
V_38 = F_194 ( V_8 , & V_8 -> V_86 ) ;
if ( V_38 < 0 )
return V_38 ;
V_38 = F_201 ( V_8 ,
V_8 -> V_86 . V_91 [ 0 ] ,
L_51 ) ;
if ( V_38 < 0 )
return V_38 ;
V_38 = F_201 ( V_8 , V_8 -> V_86 . V_93 [ 0 ] ,
L_52 ) ;
if ( V_38 < 0 )
return V_38 ;
V_38 = F_208 ( V_6 , & V_8 -> V_86 ) ;
if ( V_38 < 0 )
return V_38 ;
V_8 -> V_40 . V_41 = V_8 -> V_40 . V_43 * 2 ;
F_94 ( V_6 ) ;
if ( V_8 -> V_338 . V_339 )
F_34 ( V_8 , V_8 -> V_338 . V_339 ) ;
F_37 ( V_8 , V_397 ) ;
V_8 -> V_11 = 1 ;
V_8 -> V_12 = & V_8 -> V_384 [ 0 ] ;
F_84 ( V_6 , 0x15 , 0x1b , 0x14 , 0 ) ;
return 1 ;
}
static void F_221 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
F_214 ( V_6 ) ;
F_215 ( V_6 ) ;
F_216 ( V_6 ) ;
F_217 ( V_6 ) ;
F_93 ( V_6 ) ;
if ( V_8 -> V_112 )
F_59 ( V_6 ) ;
}
static void F_222 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
int V_28 ;
for ( V_28 = 0 ; V_28 < V_8 -> V_110 ; V_28 ++ ) {
T_1 V_398 = V_8 -> V_24 ?
V_8 -> V_24 [ V_28 ] : V_8 -> V_25 [ V_28 ] ;
int V_399 , V_400 ;
V_399 = F_52 ( V_6 , V_398 , V_8 -> V_170 . V_129 ) ;
if ( V_399 < 0 )
continue;
V_400 = F_52 ( V_6 , V_398 , V_8 -> V_128 . V_129 ) ;
if ( V_400 < 0 )
continue;
V_8 -> V_170 . V_9 = V_399 ;
V_8 -> V_128 . V_9 = V_400 ;
if ( V_8 -> V_24 )
V_8 -> V_24 += V_28 ;
V_8 -> V_25 += V_28 ;
V_8 -> V_110 = 1 ;
V_400 = F_52 ( V_6 , V_398 , V_8 -> V_131 . V_129 ) ;
if ( V_400 < 0 )
V_8 -> V_131 . V_129 = 0 ;
else
V_8 -> V_131 . V_9 = V_400 ;
return;
}
F_82 ( V_221 L_25
L_56 ,
V_6 -> V_222 , V_8 -> V_170 . V_129 , V_8 -> V_128 . V_129 ) ;
V_8 -> V_169 = 0 ;
}
static void F_223 ( struct V_5 * V_6 , T_1 V_398 ,
int V_29 )
{
if ( F_7 ( F_8 ( V_6 , V_398 ) ) == V_26 ) {
F_9 ( V_6 , V_398 , V_32 , V_29 ,
V_31 , 0 ) ;
} else {
F_23 ( V_6 , V_398 , 0 ,
V_172 , V_29 ) ;
}
}
static int F_224 ( struct V_5 * V_6 , T_1 V_129 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
int V_28 ;
if ( ! V_129 )
return 0 ;
for ( V_28 = 0 ; V_28 < V_8 -> V_110 ; V_28 ++ ) {
T_1 V_398 = V_8 -> V_24 ?
V_8 -> V_24 [ V_28 ] : V_8 -> V_25 [ V_28 ] ;
int V_29 ;
V_29 = F_52 ( V_6 , V_398 , V_129 ) ;
if ( V_29 < 0 )
continue;
F_223 ( V_6 , V_398 , V_29 ) ;
return V_28 ;
}
return - 1 ;
}
static void F_225 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
struct V_84 * V_85 = & V_8 -> V_86 ;
int V_28 ;
if ( V_85 -> V_202 != 1 )
return;
V_28 = F_224 ( V_6 , V_85 -> V_203 [ 0 ] . V_129 ) ;
if ( V_28 >= 0 ) {
if ( V_8 -> V_24 )
V_8 -> V_24 += V_28 ;
V_8 -> V_25 += V_28 ;
V_8 -> V_110 = 1 ;
V_8 -> V_401 = 1 ;
}
}
static void F_226 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
F_224 ( V_6 , V_8 -> V_128 . V_129 ) ;
F_224 ( V_6 , V_8 -> V_131 . V_129 ) ;
F_224 ( V_6 , V_8 -> V_170 . V_129 ) ;
}
static void F_140 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
if ( V_8 -> V_171 )
F_226 ( V_6 ) ;
else if ( V_8 -> V_401 )
F_224 ( V_6 , V_8 -> V_86 . V_203 [ 0 ] . V_129 ) ;
}
static void F_227 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
static const struct V_94 * V_402 [ 2 ] [ 3 ] = {
{ V_403 ,
V_404 ,
V_405 } ,
{ V_406 ,
V_407 ,
V_408 } ,
} ;
if ( V_8 -> V_110 > 0 && V_8 -> V_110 <= 3 ) {
int V_155 = 0 ;
int V_409 = V_8 -> V_110 ;
if ( V_8 -> V_171 )
V_409 = 1 ;
else if ( V_8 -> V_169 )
F_222 ( V_6 ) ;
else if ( V_8 -> V_12 ) {
if ( V_8 -> V_12 -> V_13 > 1 )
V_155 = 1 ;
else if ( V_8 -> V_12 -> V_13 == 1 )
F_225 ( V_6 ) ;
}
V_8 -> V_104 = V_402 [ V_155 ] [ V_409 - 1 ] ;
}
}
static void F_228 ( struct V_5 * V_6 , const T_1 * V_293 ,
int V_410 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
struct V_84 * V_85 = & V_8 -> V_86 ;
int V_411 ;
T_1 V_412 = 0 , V_413 = 0 ;
for ( V_411 = 0 ; V_411 < V_410 ; V_411 ++ ) {
T_1 V_414 , V_398 ;
T_1 V_156 [ V_157 ] ;
int V_415 , V_28 , V_283 ;
V_414 = V_293 [ V_411 ] ;
if ( F_7 ( F_8 ( V_6 , V_414 ) ) != V_270 )
continue;
V_398 = V_414 ;
V_415 = F_53 ( V_6 , V_398 , V_156 ,
F_36 ( V_156 ) ) ;
if ( V_415 == 1 ) {
V_398 = V_156 [ 0 ] ;
V_415 = F_53 ( V_6 , V_398 , V_156 ,
F_36 ( V_156 ) ) ;
}
if ( V_415 <= 0 )
continue;
if ( ! V_412 ) {
V_412 = V_414 ;
V_413 = V_398 ;
}
for ( V_28 = 0 ; V_28 < V_85 -> V_202 ; V_28 ++ ) {
T_1 V_23 = V_85 -> V_203 [ V_28 ] . V_129 ;
for ( V_283 = 0 ; V_283 < V_415 ; V_283 ++ ) {
if ( V_156 [ V_283 ] == V_23 )
break;
}
if ( V_283 >= V_415 )
break;
}
if ( V_28 >= V_85 -> V_202 ) {
int V_409 = V_8 -> V_110 ;
V_8 -> V_416 [ V_409 ] = V_414 ;
V_8 -> V_417 [ V_409 ] = V_398 ;
V_8 -> V_110 ++ ;
V_8 -> V_25 = V_8 -> V_416 ;
if ( V_414 != V_398 )
V_8 -> V_24 = V_8 -> V_417 ;
}
}
if ( ! V_8 -> V_110 ) {
F_81 ( V_418 L_57
L_58 ,
V_6 -> V_222 , V_412 ) ;
V_8 -> V_416 [ 0 ] = V_412 ;
V_8 -> V_25 = V_8 -> V_416 ;
if ( V_412 != V_413 ) {
V_8 -> V_417 [ 0 ] = V_413 ;
V_8 -> V_24 = V_8 -> V_416 ;
}
}
}
static inline int F_229 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
const struct V_258 * V_419 ;
V_419 = F_90 ( V_6 -> V_218 -> V_219 , V_420 ) ;
if ( V_419 )
return V_419 -> V_17 ;
return V_8 -> V_211 . V_212 ;
}
static int F_230 ( struct V_5 * V_6 )
{
struct V_7 * V_8 ;
int V_421 ;
int V_38 ;
V_8 = F_231 ( sizeof( * V_8 ) , V_196 ) ;
if ( V_8 == NULL )
return - V_194 ;
V_6 -> V_8 = V_8 ;
V_421 = F_232 ( V_6 , V_422 ,
V_423 ,
V_424 ) ;
if ( V_421 < 0 ) {
F_81 ( V_221 L_59 ,
V_6 -> V_222 ) ;
V_421 = V_425 ;
}
if ( V_421 == V_425 ) {
V_38 = F_218 ( V_6 ) ;
if ( V_38 < 0 ) {
F_169 ( V_6 ) ;
return V_38 ;
} else if ( ! V_38 ) {
F_81 ( V_221
L_60
L_61 ) ;
V_421 = V_426 ;
}
}
V_38 = F_233 ( V_6 , 0x1 ) ;
if ( V_38 < 0 ) {
F_169 ( V_6 ) ;
return V_38 ;
}
if ( V_421 != V_425 )
F_38 ( V_6 , & V_427 [ V_421 ] ) ;
V_8 -> V_320 = & V_428 ;
V_8 -> V_323 = & V_429 ;
V_8 -> V_334 = & V_430 ;
V_8 -> V_329 = & V_431 ;
V_8 -> V_330 = & V_432 ;
if ( ! V_8 -> V_25 && V_8 -> V_12 ) {
unsigned int V_433 = F_8 ( V_6 , V_434 [ 0 ] ) ;
V_433 = F_7 ( V_433 ) ;
if ( V_433 != V_270 ) {
V_8 -> V_25 = V_435 ;
V_8 -> V_110 = F_36 ( V_435 ) ;
} else {
V_8 -> V_25 = V_434 ;
V_8 -> V_110 = F_36 ( V_434 ) ;
}
}
F_227 ( V_6 ) ;
F_234 ( V_8 , 0x0b , 0x05 , V_32 ) ;
V_8 -> V_290 = 0x0c ;
V_6 -> V_342 = V_436 ;
if ( V_421 == V_425 )
V_8 -> V_113 = F_221 ;
#ifdef F_39
if ( ! V_8 -> V_115 . V_116 )
V_8 -> V_115 . V_116 = V_437 ;
#endif
return 0 ;
}
static void F_235 ( struct V_5 * V_6 )
{
F_49 ( V_6 ) ;
}
static int F_236 ( struct V_1 * V_2 ,
struct V_14 * V_15 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = V_6 -> V_8 ;
* V_15 -> V_17 . integer . V_17 = ! V_8 -> V_149 ;
return 0 ;
}
static int F_237 ( struct V_1 * V_2 ,
struct V_14 * V_15 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = V_6 -> V_8 ;
int V_57 = ! * V_15 -> V_17 . integer . V_17 ;
if ( V_57 == V_8 -> V_149 )
return 0 ;
V_8 -> V_149 = V_57 ;
F_235 ( V_6 ) ;
return 1 ;
}
static void F_238 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
V_8 -> V_86 . V_93 [ 0 ] = 0x0f ;
V_8 -> V_86 . V_91 [ 0 ] = 0x10 ;
V_8 -> V_86 . V_91 [ 1 ] = 0x11 ;
V_8 -> V_150 = 1 ;
V_8 -> V_143 = V_144 ;
}
static void F_239 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
V_8 -> V_86 . V_93 [ 0 ] = 0x15 ;
V_8 -> V_86 . V_91 [ 0 ] = 0x10 ;
V_8 -> V_86 . V_91 [ 1 ] = 0x11 ;
V_8 -> V_150 = 1 ;
V_8 -> V_143 = V_144 ;
}
static void F_240 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
V_8 -> V_86 . V_93 [ 0 ] = 0x10 ;
V_8 -> V_86 . V_91 [ 0 ] = 0x0f ;
V_8 -> V_86 . V_91 [ 1 ] = 0x11 ;
V_8 -> V_86 . V_91 [ 2 ] = 0x15 ;
V_8 -> V_150 = 1 ;
V_8 -> V_143 = V_144 ;
}
static void F_241 ( struct V_5 * V_6 )
{
unsigned int V_136 ;
V_136 = F_47 ( V_6 , 0x0f ) ;
if ( V_136 ) {
F_23 ( V_6 , 0x01 , 0 ,
V_63 , 1 ) ;
F_23 ( V_6 , 0x0f , 0 ,
V_58 ,
V_141 ) ;
} else {
F_23 ( V_6 , 0x01 , 0 ,
V_63 , 0 ) ;
F_23 ( V_6 , 0x0f , 0 ,
V_58 ,
V_142 ) ;
}
}
static void F_242 ( struct V_5 * V_6 ,
unsigned int V_173 )
{
if ( ( V_173 >> 26 ) == V_175 )
F_241 ( V_6 ) ;
}
static int F_243 ( struct V_7 * V_8 , T_1 V_23 ,
const char * V_362 , int * V_438 )
{
T_1 V_439 ;
unsigned long V_440 , V_441 ;
int V_38 ;
if ( V_23 >= 0x0f && V_23 < 0x11 ) {
V_439 = V_23 - 0x7 ;
V_440 = F_104 ( V_439 , 3 , 0 , V_59 ) ;
V_441 = F_104 ( V_23 , 3 , 0 , V_59 ) ;
} else if ( V_23 == 0x11 ) {
V_439 = V_23 - 0x7 ;
V_440 = F_104 ( V_439 , 2 , 0 , V_59 ) ;
V_441 = F_104 ( V_23 , 2 , 0 , V_59 ) ;
} else if ( V_23 >= 0x12 && V_23 <= 0x15 ) {
V_439 = 0x08 ;
V_440 = F_104 ( V_439 , 3 , 0 , V_59 ) ;
V_441 = F_104 ( V_23 , 3 , 0 , V_59 ) ;
} else
return 0 ;
if ( ! ( * V_438 & ( 1 << V_439 ) ) ) {
V_38 = F_197 ( V_8 , V_373 , V_362 , V_440 ) ;
if ( V_38 < 0 )
return V_38 ;
* V_438 |= ( 1 << V_439 ) ;
}
V_38 = F_198 ( V_8 , V_376 , V_362 , V_441 ) ;
if ( V_38 < 0 )
return V_38 ;
return 1 ;
}
static int F_244 ( struct V_7 * V_8 ,
const struct V_84 * V_85 )
{
T_1 V_23 ;
int V_38 ;
int V_442 = 0 ;
V_8 -> V_40 . V_43 = 1 ;
V_8 -> V_40 . V_106 = V_8 -> V_365 ;
V_8 -> V_365 [ 0 ] = 0x02 ;
V_23 = V_85 -> V_89 [ 0 ] ;
if ( V_23 ) {
const char * V_362 ;
if ( ! V_85 -> V_91 [ 0 ] && ! V_85 -> V_93 [ 0 ] )
V_362 = L_50 ;
else if ( V_85 -> V_368 == V_369 )
V_362 = L_51 ;
else
V_362 = L_45 ;
V_38 = F_243 ( V_8 , V_23 , V_362 , & V_442 ) ;
if ( V_38 < 0 )
return V_38 ;
}
V_23 = V_85 -> V_91 [ 0 ] ;
if ( V_23 ) {
V_38 = F_243 ( V_8 , V_23 , L_51 , & V_442 ) ;
if ( V_38 < 0 )
return V_38 ;
}
V_23 = V_85 -> V_93 [ 0 ] ;
if ( V_23 ) {
V_38 = F_243 ( V_8 , V_23 , L_52 ,
& V_442 ) ;
if ( V_38 < 0 )
return V_38 ;
}
return 0 ;
}
static int F_245 ( struct V_5 * V_6 ,
const struct V_84 * V_85 )
{
return F_205 ( V_6 , V_85 , 0x07 , 0x04 , 0x05 ) ;
}
static void F_246 ( struct V_5 * V_6 ,
T_1 V_23 , int V_388 ,
int V_443 )
{
F_209 ( V_6 , V_23 , V_388 ) ;
if ( V_23 >= 0x12 ) {
int V_29 = V_23 - 0x12 ;
F_32 ( V_6 , V_29 + 0x0b , 0 ,
V_172 , V_443 ) ;
}
}
static void F_247 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
T_1 V_23 ;
V_23 = V_8 -> V_86 . V_89 [ 0 ] ;
if ( V_23 ) {
int V_388 = F_213 ( V_8 -> V_86 . V_368 ) ;
F_246 ( V_6 , V_23 , V_388 , 0 ) ;
}
V_23 = V_8 -> V_86 . V_91 [ 0 ] ;
if ( V_23 )
F_246 ( V_6 , V_23 , V_142 , 0 ) ;
V_23 = V_8 -> V_86 . V_93 [ 0 ] ;
if ( V_23 )
F_246 ( V_6 , V_23 , V_141 , 0 ) ;
}
static void F_248 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
struct V_84 * V_85 = & V_8 -> V_86 ;
int V_28 ;
for ( V_28 = 0 ; V_28 < V_85 -> V_202 ; V_28 ++ ) {
T_1 V_23 = V_85 -> V_203 [ V_28 ] . V_129 ;
if ( V_23 >= 0x12 ) {
F_30 ( V_6 , V_23 , V_85 -> V_203 [ V_28 ] . type ) ;
if ( V_23 != V_444 &&
( F_8 ( V_6 , V_23 ) & V_393 ) )
F_32 ( V_6 , V_23 , 0 ,
V_389 ,
V_394 ) ;
}
}
}
static int F_249 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
int V_38 ;
static const T_1 V_445 [] = { 0x17 , 0 } ;
V_38 = F_219 ( V_6 , & V_8 -> V_86 ,
V_445 ) ;
if ( V_38 < 0 )
return V_38 ;
V_38 = F_244 ( V_8 , & V_8 -> V_86 ) ;
if ( V_38 < 0 )
return V_38 ;
if ( ! V_8 -> V_338 . V_339 )
return 0 ;
V_38 = F_245 ( V_6 , & V_8 -> V_86 ) ;
if ( V_38 < 0 )
return V_38 ;
V_8 -> V_40 . V_41 = 2 ;
if ( V_8 -> V_86 . V_262 )
V_8 -> V_40 . V_107 = V_446 ;
if ( V_8 -> V_338 . V_339 )
F_34 ( V_8 , V_8 -> V_338 . V_339 ) ;
F_37 ( V_8 , V_447 ) ;
V_8 -> V_11 = 1 ;
V_8 -> V_12 = & V_8 -> V_384 [ 0 ] ;
F_84 ( V_6 , 0x10 , 0x15 , 0x0f , 0 ) ;
return 1 ;
}
static void F_250 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
F_247 ( V_6 ) ;
F_248 ( V_6 ) ;
F_251 ( V_6 ) ;
F_93 ( V_6 ) ;
if ( V_8 -> V_112 )
F_59 ( V_6 ) ;
}
static int F_252 ( struct V_5 * V_6 )
{
struct V_7 * V_8 ;
int V_38 , V_421 ;
V_8 = F_231 ( sizeof( * V_8 ) , V_196 ) ;
if ( V_8 == NULL )
return - V_194 ;
V_6 -> V_8 = V_8 ;
V_421 = F_232 ( V_6 , V_448 ,
V_449 ,
V_450 ) ;
if ( V_421 < 0 ) {
F_82 ( V_221 L_59 ,
V_6 -> V_222 ) ;
V_421 = V_451 ;
}
if ( V_421 == V_451 ) {
F_89 ( V_6 , NULL , V_452 , V_453 ) ;
F_85 ( V_6 , V_245 ) ;
}
if ( V_421 == V_451 ) {
V_38 = F_249 ( V_6 ) ;
if ( V_38 < 0 ) {
F_169 ( V_6 ) ;
return V_38 ;
} else if ( ! V_38 ) {
F_81 ( V_221
L_60
L_62 ) ;
V_421 = V_454 ;
}
}
V_38 = F_233 ( V_6 , 0x1 ) ;
if ( V_38 < 0 ) {
F_169 ( V_6 ) ;
return V_38 ;
}
if ( V_421 != V_451 )
F_38 ( V_6 , & V_455 [ V_421 ] ) ;
V_8 -> V_320 = & V_456 ;
V_8 -> V_323 = & V_457 ;
V_8 -> V_334 = & V_457 ;
V_8 -> V_329 = & V_458 ;
V_8 -> V_330 = & V_459 ;
if ( ! V_8 -> V_25 && V_8 -> V_12 ) {
unsigned int V_433 = F_8 ( V_6 , 0x04 ) ;
V_433 = F_7 ( V_433 ) ;
if ( V_433 != V_270 || V_8 -> V_12 -> V_13 == 1 ) {
V_8 -> V_25 = V_460 ;
V_8 -> V_110 = F_36 ( V_460 ) ;
} else {
V_8 -> V_25 = V_461 ;
V_8 -> V_110 = F_36 ( V_461 ) ;
}
}
F_227 ( V_6 ) ;
F_234 ( V_8 , 0x07 , 0x05 , V_32 ) ;
F_85 ( V_6 , V_249 ) ;
V_8 -> V_290 = 0x08 ;
V_6 -> V_342 = V_436 ;
if ( V_421 == V_451 )
V_8 -> V_113 = F_250 ;
V_8 -> V_337 = F_64 ;
#ifdef F_39
if ( ! V_8 -> V_115 . V_116 )
V_8 -> V_115 . V_116 = V_462 ;
#endif
return 0 ;
}
static void F_253 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
V_8 -> V_86 . V_93 [ 0 ] = 0x14 ;
V_8 -> V_86 . V_91 [ 0 ] = 0x18 ;
V_8 -> V_86 . V_91 [ 1 ] = 0x1a ;
V_8 -> V_150 = 1 ;
V_8 -> V_143 = V_145 ;
}
static void F_254 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
V_8 -> V_86 . V_93 [ 0 ] = 0x14 ;
V_8 -> V_86 . V_91 [ 0 ] = 0x18 ;
V_8 -> V_150 = 1 ;
V_8 -> V_143 = V_145 ;
}
static void F_255 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
V_8 -> V_86 . V_93 [ 0 ] = 0x15 ;
V_8 -> V_86 . V_91 [ 0 ] = 0x14 ;
V_8 -> V_150 = 1 ;
V_8 -> V_143 = V_145 ;
}
static void F_256 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
V_8 -> V_86 . V_93 [ 0 ] = 0x14 ;
V_8 -> V_86 . V_91 [ 0 ] = 0x18 ;
V_8 -> V_86 . V_91 [ 1 ] = 0x1a ;
V_8 -> V_150 = 1 ;
V_8 -> V_143 = V_145 ;
}
static void F_257 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
F_50 ( V_6 ) ;
F_23 ( V_6 , 1 , 0 , V_63 ,
V_8 -> V_151 ? 1 : 3 ) ;
}
static void F_258 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
V_8 -> V_86 . V_93 [ 0 ] = 0x14 ;
V_8 -> V_86 . V_91 [ 0 ] = 0x1b ;
V_8 -> V_150 = 1 ;
V_8 -> V_143 = V_145 ;
}
static void F_259 ( struct V_5 * V_6 , unsigned int V_173 )
{
if ( ( V_173 >> 26 ) == V_175 )
F_257 ( V_6 ) ;
}
static void F_260 ( struct V_5 * V_6 , int V_129 , int V_463 )
{
unsigned int V_464 , V_465 , V_466 ;
V_464 = F_21 ( V_6 , V_6 -> V_467 , 0 ,
V_61 , 0 ) ;
if ( ! V_463 )
V_464 |= ( 1 << V_129 ) ;
else
V_464 &= ~ ( 1 << V_129 ) ;
V_465 = F_21 ( V_6 , V_6 -> V_467 , 0 ,
V_468 , 0 ) ;
V_465 |= ( 1 << V_129 ) ;
V_466 = F_21 ( V_6 , V_6 -> V_467 , 0 ,
V_469 , 0 ) ;
V_466 |= ( 1 << V_129 ) ;
F_32 ( V_6 , V_6 -> V_467 , 0 ,
V_470 , V_465 ) ;
F_32 ( V_6 , V_6 -> V_467 , 0 ,
V_471 , V_466 ) ;
F_65 ( 1 ) ;
F_32 ( V_6 , V_6 -> V_467 , 0 ,
V_63 , V_464 ) ;
}
static void F_261 ( struct V_5 * V_6 )
{
F_260 ( V_6 , 0 , 0 ) ;
F_260 ( V_6 , 1 , 0 ) ;
}
static void F_262 ( struct V_5 * V_6 )
{
F_261 ( V_6 ) ;
F_50 ( V_6 ) ;
}
static void F_263 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
V_8 -> V_86 . V_93 [ 0 ] = 0x1a ;
V_8 -> V_86 . V_91 [ 0 ] = 0x15 ;
V_8 -> V_150 = 1 ;
V_8 -> V_143 = V_145 ;
}
static void F_264 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
V_8 -> V_86 . V_93 [ 0 ] = 0x15 ;
V_8 -> V_86 . V_91 [ 0 ] = 0x14 ;
V_8 -> V_86 . V_91 [ 1 ] = 0x17 ;
V_8 -> V_150 = 1 ;
V_8 -> V_143 = V_145 ;
}
static void F_265 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
V_8 -> V_86 . V_93 [ 0 ] = 0x1b ;
V_8 -> V_86 . V_91 [ 0 ] = 0x14 ;
V_8 -> V_86 . V_91 [ 1 ] = 0x16 ;
V_8 -> V_86 . V_91 [ 2 ] = 0x18 ;
V_8 -> V_150 = 1 ;
V_8 -> V_143 = V_145 ;
}
static void F_266 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
V_8 -> V_86 . V_93 [ 0 ] = 0x1b ;
V_8 -> V_86 . V_89 [ 0 ] = 0x14 ;
V_8 -> V_86 . V_91 [ 0 ] = 0x15 ;
V_8 -> V_150 = 1 ;
V_8 -> V_143 = V_145 ;
}
static void F_267 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
V_8 -> V_86 . V_93 [ 0 ] = 0x14 ;
V_8 -> V_86 . V_91 [ 0 ] = 0x15 ;
V_8 -> V_150 = 1 ;
V_8 -> V_143 = V_145 ;
}
static void F_268 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
V_8 -> V_86 . V_93 [ 0 ] = 0x15 ;
V_8 -> V_86 . V_91 [ 0 ] = 0x14 ;
V_8 -> V_150 = 1 ;
V_8 -> V_143 = V_145 ;
}
static void F_269 ( struct V_5 * V_6 )
{
F_50 ( V_6 ) ;
F_127 ( V_6 ) ;
}
static void F_270 ( struct V_5 * V_6 ,
unsigned int V_173 )
{
switch ( V_173 >> 26 ) {
case V_177 :
F_127 ( V_6 ) ;
break;
default:
F_58 ( V_6 , V_173 ) ;
break;
}
}
static void F_271 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
V_8 -> V_86 . V_93 [ 0 ] = 0x14 ;
V_8 -> V_86 . V_91 [ 0 ] = 0x15 ;
V_8 -> V_150 = 1 ;
V_8 -> V_143 = V_145 ;
}
static void F_272 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
V_8 -> V_86 . V_93 [ 0 ] = 0x1b ;
V_8 -> V_86 . V_91 [ 0 ] = 0x14 ;
V_8 -> V_150 = 1 ;
V_8 -> V_143 = V_145 ;
}
static void F_273 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
V_8 -> V_86 . V_93 [ 0 ] = 0x1b ;
V_8 -> V_86 . V_89 [ 0 ] = 0x14 ;
V_8 -> V_86 . V_91 [ 0 ] = 0x15 ;
V_8 -> V_150 = 1 ;
V_8 -> V_154 = 1 ;
V_8 -> V_153 = 1 ;
V_8 -> V_143 = V_145 ;
}
static void F_274 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
V_8 -> V_86 . V_93 [ 0 ] = 0x14 ;
V_8 -> V_86 . V_91 [ 0 ] = 0x15 ;
V_8 -> V_86 . V_91 [ 1 ] = 0x16 ;
V_8 -> V_150 = 1 ;
V_8 -> V_143 = V_145 ;
}
static void F_275 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
V_8 -> V_86 . V_93 [ 0 ] = 0x1b ;
V_8 -> V_86 . V_91 [ 0 ] = 0x14 ;
V_8 -> V_86 . V_91 [ 1 ] = 0x15 ;
V_8 -> V_86 . V_91 [ 2 ] = 0x16 ;
V_8 -> V_86 . V_91 [ 3 ] = 0x17 ;
V_8 -> V_150 = 1 ;
V_8 -> V_143 = V_145 ;
}
static void F_276 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
V_8 -> V_86 . V_93 [ 0 ] = 0x1b ;
V_8 -> V_86 . V_91 [ 0 ] = 0x14 ;
V_8 -> V_86 . V_91 [ 1 ] = 0x15 ;
V_8 -> V_86 . V_91 [ 2 ] = 0x16 ;
V_8 -> V_86 . V_91 [ 3 ] = 0x17 ;
V_8 -> V_86 . V_91 [ 4 ] = 0x1a ;
V_8 -> V_150 = 1 ;
V_8 -> V_143 = V_145 ;
}
static void F_277 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
V_8 -> V_86 . V_93 [ 0 ] = 0x15 ;
V_8 -> V_86 . V_91 [ 0 ] = 0x14 ;
V_8 -> V_86 . V_91 [ 1 ] = 0x17 ;
V_8 -> V_150 = 1 ;
V_8 -> V_143 = V_145 ;
}
static void F_278 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
V_8 -> V_86 . V_93 [ 0 ] = 0x1b ;
V_8 -> V_86 . V_91 [ 0 ] = 0x14 ;
V_8 -> V_86 . V_91 [ 1 ] = 0x15 ;
V_8 -> V_86 . V_91 [ 2 ] = 0x16 ;
V_8 -> V_128 . V_129 = 0x18 ;
V_8 -> V_170 . V_129 = 0x19 ;
V_8 -> V_128 . V_9 = 0 ;
V_8 -> V_170 . V_9 = 1 ;
V_8 -> V_169 = 1 ;
V_8 -> V_150 = 1 ;
V_8 -> V_143 = V_145 ;
}
static void F_279 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
V_8 -> V_86 . V_93 [ 0 ] = 0x14 ;
V_8 -> V_86 . V_91 [ 0 ] = 0x1b ;
F_50 ( V_6 ) ;
}
static void F_280 ( struct V_5 * V_6 )
{
unsigned int V_136 ;
if ( F_21 ( V_6 , 0x15 , 0 , V_358 , 0 )
== 0x00 ) {
V_136 = F_47 ( V_6 , 0x15 ) ;
F_9 ( V_6 , 0x14 , V_59 , 0 ,
V_31 , V_136 ? V_31 : 0 ) ;
F_9 ( V_6 , 0x16 , V_59 , 0 ,
V_31 , V_136 ? V_31 : 0 ) ;
}
}
static void F_281 ( struct V_5 * V_6 , unsigned int V_173 )
{
if ( ( V_173 >> 26 ) == V_175 )
F_280 ( V_6 ) ;
}
static int F_282 ( struct V_5 * V_6 ,
const struct V_84 * V_85 )
{
return F_205 ( V_6 , V_85 , 0x0b , 0x23 , 0x22 ) ;
}
static void F_283 ( struct V_5 * V_6 ,
T_1 V_23 , int V_388 ,
T_1 V_472 )
{
int V_29 ;
F_209 ( V_6 , V_23 , V_388 ) ;
if ( V_472 == 0x25 )
V_29 = 4 ;
else if ( V_472 >= 0x02 && V_472 <= 0x05 )
V_29 = V_472 - 2 ;
else
return;
F_32 ( V_6 , V_23 , 0 , V_172 , V_29 ) ;
}
static void F_284 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
int V_28 ;
for ( V_28 = 0 ; V_28 <= V_473 ; V_28 ++ ) {
T_1 V_23 = V_8 -> V_86 . V_89 [ V_28 ] ;
int V_388 = F_213 ( V_8 -> V_86 . V_368 ) ;
if ( V_23 )
F_283 ( V_6 , V_23 , V_388 ,
V_8 -> V_40 . V_106 [ V_28 ] ) ;
}
}
static void F_285 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
T_1 V_129 , V_472 ;
int V_28 ;
if ( V_8 -> V_86 . V_368 != V_370 ) {
for ( V_28 = 0 ; V_28 < F_36 ( V_8 -> V_86 . V_93 ) ; V_28 ++ ) {
V_129 = V_8 -> V_86 . V_93 [ V_28 ] ;
if ( ! V_129 )
break;
V_472 = V_8 -> V_40 . V_109 ;
if ( ! V_472 )
V_472 = V_8 -> V_40 . V_106 [ 0 ] ;
F_283 ( V_6 , V_129 , V_141 , V_472 ) ;
}
}
if ( V_8 -> V_86 . V_368 != V_369 ) {
for ( V_28 = 0 ; V_28 < F_36 ( V_8 -> V_86 . V_91 ) ; V_28 ++ ) {
V_129 = V_8 -> V_86 . V_91 [ V_28 ] ;
if ( ! V_129 )
break;
V_472 = V_8 -> V_40 . V_375 [ 0 ] ;
if ( ! V_472 )
V_472 = V_8 -> V_40 . V_106 [ 0 ] ;
F_283 ( V_6 , V_129 , V_142 , V_472 ) ;
}
}
}
static void F_286 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
struct V_84 * V_85 = & V_8 -> V_86 ;
int V_28 ;
for ( V_28 = 0 ; V_28 < V_85 -> V_202 ; V_28 ++ ) {
T_1 V_23 = V_85 -> V_203 [ V_28 ] . V_129 ;
F_30 ( V_6 , V_23 , V_85 -> V_203 [ V_28 ] . type ) ;
if ( F_8 ( V_6 , V_23 ) & V_393 )
F_32 ( V_6 , V_23 , 0 ,
V_389 ,
V_394 ) ;
}
}
static void F_287 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
int V_395 ;
for ( V_395 = 0 ; V_395 < V_8 -> V_110 ; V_395 ++ ) {
T_1 V_474 [ V_157 ] ;
T_1 V_23 = V_8 -> V_24 [ V_395 ] ;
unsigned int V_9 ;
const struct V_21 * V_22 ;
int V_475 , V_137 , V_29 , V_19 ;
F_32 ( V_6 , V_8 -> V_25 [ V_395 ] , 0 ,
V_389 ,
F_288 ( 0 ) ) ;
V_475 = F_53 ( V_6 , V_23 , V_474 ,
F_36 ( V_474 ) ) ;
if ( V_475 < 0 )
continue;
V_9 = V_395 >= V_8 -> V_11 ? 0 : V_395 ;
V_22 = & V_8 -> V_12 [ V_9 ] ;
if ( ! V_22 -> V_13 && V_9 > 0 )
V_22 = & V_8 -> V_12 [ 0 ] ;
for ( V_29 = 0 ; V_29 < V_475 ; V_29 ++ ) {
V_137 = F_288 ( V_29 ) ;
for ( V_19 = 0 ; V_19 < V_22 -> V_13 ; V_19 ++ ) {
if ( V_22 -> V_33 [ V_19 ] . V_34 == V_29 ) {
if ( V_8 -> V_20 [ V_395 ] == V_19 )
V_137 = F_289 ( V_29 ) ;
break;
}
}
if ( F_8 ( V_6 , V_23 ) & V_476 )
F_32 ( V_6 , V_23 , 0 ,
V_389 ,
V_137 ) ;
else if ( V_137 != F_288 ( V_29 ) )
F_32 ( V_6 , V_23 , 0 ,
V_172 ,
V_29 ) ;
}
}
}
static int F_290 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
struct V_84 * V_85 = & V_8 -> V_86 ;
int V_28 , V_38 ;
int V_385 = 0 ;
T_1 V_23 ;
const char * V_386 = NULL ;
for ( V_28 = 0 ; V_28 < V_85 -> V_202 ; V_28 ++ ) {
if ( V_85 -> V_203 [ V_28 ] . type > V_71 )
break;
V_23 = V_85 -> V_203 [ V_28 ] . V_129 ;
if ( F_8 ( V_6 , V_23 ) & V_476 ) {
const char * V_387 ;
char V_477 [ 32 ] ;
V_387 = F_206 ( V_6 , V_85 , V_28 ) ;
if ( V_386 && ! strcmp ( V_387 , V_386 ) )
V_385 ++ ;
else
V_385 = 0 ;
V_386 = V_387 ;
snprintf ( V_477 , sizeof( V_477 ) ,
L_63 , V_387 ) ;
V_38 = F_186 ( V_8 , V_373 ,
V_477 , V_385 ,
F_104 ( V_23 , 3 , 0 , V_32 ) ) ;
if ( V_38 < 0 )
return V_38 ;
}
}
return 0 ;
}
static int F_291 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
static const T_1 V_478 [] = { 0x1d , 0 } ;
int V_38 ;
V_38 = F_219 ( V_6 , & V_8 -> V_86 ,
V_478 ) ;
if ( V_38 < 0 )
return V_38 ;
if ( ! V_8 -> V_86 . V_87 )
return 0 ;
V_38 = F_189 ( V_8 , & V_8 -> V_86 ) ;
if ( V_38 < 0 )
return V_38 ;
V_38 = F_220 ( V_6 ) ;
if ( V_38 < 0 )
return V_38 ;
V_38 = F_194 ( V_8 , & V_8 -> V_86 ) ;
if ( V_38 < 0 )
return V_38 ;
V_38 = F_201 ( V_8 , V_8 -> V_86 . V_93 [ 0 ] ,
L_52 ) ;
if ( V_38 < 0 )
return V_38 ;
V_38 = F_201 ( V_8 ,
V_8 -> V_86 . V_91 [ 0 ] ,
L_51 ) ;
if ( V_38 < 0 )
return V_38 ;
V_38 = F_282 ( V_6 , & V_8 -> V_86 ) ;
if ( V_38 < 0 )
return V_38 ;
V_8 -> V_40 . V_41 = V_8 -> V_40 . V_43 * 2 ;
F_94 ( V_6 ) ;
if ( V_8 -> V_338 . V_339 )
F_34 ( V_8 , V_8 -> V_338 . V_339 ) ;
F_37 ( V_8 , V_479 ) ;
if ( F_7 ( F_8 ( V_6 , 0x07 ) ) == V_270 )
F_37 ( V_8 , V_480 ) ;
V_8 -> V_11 = 1 ;
V_8 -> V_12 = & V_8 -> V_384 [ 0 ] ;
F_84 ( V_6 , 0x15 , 0x1b , 0x14 , 0 ) ;
V_38 = F_290 ( V_6 ) ;
if ( V_38 < 0 )
return V_38 ;
return 1 ;
}
static void F_292 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
F_284 ( V_6 ) ;
F_285 ( V_6 ) ;
F_286 ( V_6 ) ;
F_287 ( V_6 ) ;
F_93 ( V_6 ) ;
if ( V_8 -> V_112 )
F_59 ( V_6 ) ;
}
static int F_293 ( struct V_5 * V_6 )
{
struct V_7 * V_8 ;
int V_38 , V_421 ;
V_8 = F_231 ( sizeof( * V_8 ) , V_196 ) ;
if ( V_8 == NULL )
return - V_194 ;
V_6 -> V_8 = V_8 ;
switch ( V_6 -> V_174 ) {
case 0x10ec0882 :
case 0x10ec0885 :
break;
default:
F_41 ( V_6 , 0x20 , 0x0a , 10 ) ;
break;
}
V_421 = F_232 ( V_6 , V_481 ,
V_482 ,
V_483 ) ;
if ( V_421 < 0 || V_421 >= V_481 )
V_421 = F_294 ( V_6 ,
V_481 , V_482 , V_484 ) ;
if ( V_421 < 0 || V_421 >= V_481 ) {
F_81 ( V_221 L_59 ,
V_6 -> V_222 ) ;
V_421 = V_485 ;
}
if ( V_421 == V_485 ) {
F_89 ( V_6 , NULL , V_486 , V_487 ) ;
F_85 ( V_6 , V_245 ) ;
}
F_80 ( V_6 ) ;
if ( V_421 == V_485 ) {
V_38 = F_291 ( V_6 ) ;
if ( V_38 < 0 ) {
F_169 ( V_6 ) ;
return V_38 ;
} else if ( ! V_38 ) {
F_81 ( V_221
L_60
L_62 ) ;
V_421 = V_488 ;
}
}
if ( F_229 ( V_6 ) ) {
V_38 = F_233 ( V_6 , 0x1 ) ;
if ( V_38 < 0 ) {
F_169 ( V_6 ) ;
return V_38 ;
}
}
if ( V_421 != V_485 )
F_38 ( V_6 , & V_489 [ V_421 ] ) ;
V_8 -> V_320 = & V_490 ;
V_8 -> V_323 = & V_491 ;
V_8 -> V_334 = & V_430 ;
V_8 -> V_329 = & V_492 ;
V_8 -> V_330 = & V_493 ;
if ( ! V_8 -> V_25 && V_8 -> V_12 ) {
int V_28 , V_283 ;
V_8 -> V_110 = 0 ;
for ( V_28 = 0 ; V_28 < F_36 ( V_494 ) ; V_28 ++ ) {
const struct V_21 * V_22 = V_8 -> V_12 ;
T_1 V_398 ;
T_1 V_33 [ 16 ] ;
T_1 V_23 = V_494 [ V_28 ] ;
unsigned int V_433 = F_8 ( V_6 , V_23 ) ;
V_433 = F_7 ( V_433 ) ;
if ( V_433 != V_270 )
continue;
V_8 -> V_416 [ V_8 -> V_110 ] = V_23 ;
V_38 = F_53 ( V_6 , V_23 , & V_398 , 1 ) ;
if ( V_38 < 0 )
continue;
V_38 = F_53 ( V_6 , V_398 , V_33 ,
F_36 ( V_33 ) ) ;
if ( V_38 < 0 )
continue;
for ( V_283 = 0 ; V_283 < V_22 -> V_13 ; V_283 ++ )
if ( V_22 -> V_33 [ V_283 ] . V_34 >= V_38 )
break;
if ( V_283 < V_22 -> V_13 )
continue;
V_8 -> V_417 [ V_8 -> V_110 ] = V_398 ;
V_8 -> V_110 ++ ;
}
V_8 -> V_25 = V_8 -> V_416 ;
V_8 -> V_24 = V_8 -> V_417 ;
}
F_227 ( V_6 ) ;
if ( F_229 ( V_6 ) )
F_234 ( V_8 , 0x0b , 0x05 , V_32 ) ;
F_85 ( V_6 , V_249 ) ;
V_8 -> V_290 = 0x0c ;
V_6 -> V_342 = V_436 ;
if ( V_421 == V_485 )
V_8 -> V_113 = F_292 ;
F_42 ( V_6 ) ;
#ifdef F_39
if ( ! V_8 -> V_115 . V_116 )
V_8 -> V_115 . V_116 = V_495 ;
#endif
return 0 ;
}
static void F_295 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
V_8 -> V_86 . V_93 [ 0 ] = 0x1b ;
V_8 -> V_86 . V_91 [ 0 ] = 0x16 ;
V_8 -> V_150 = 1 ;
V_8 -> V_143 = V_144 ;
}
static void F_296 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
V_8 -> V_86 . V_93 [ 0 ] = 0x15 ;
V_8 -> V_86 . V_91 [ 0 ] = 0x16 ;
V_8 -> V_150 = 1 ;
V_8 -> V_143 = V_144 ;
}
static void F_297 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
V_8 -> V_86 . V_93 [ 0 ] = 0x15 ;
V_8 -> V_86 . V_91 [ 0 ] = 0x14 ;
V_8 -> V_150 = 1 ;
V_8 -> V_143 = V_144 ;
}
static void F_298 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
V_8 -> V_86 . V_93 [ 0 ] = 0x15 ;
V_8 -> V_86 . V_91 [ 0 ] = 0x14 ;
V_8 -> V_150 = 1 ;
V_8 -> V_143 = V_145 ;
}
static void F_299 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
V_8 -> V_86 . V_93 [ 0 ] = 0x1b ;
V_8 -> V_86 . V_91 [ 0 ] = 0x14 ;
V_8 -> V_150 = 1 ;
V_8 -> V_143 = V_145 ;
}
static void F_300 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
V_8 -> V_86 . V_93 [ 0 ] = 0x1b ;
V_8 -> V_86 . V_91 [ 0 ] = 0x15 ;
V_8 -> V_150 = 1 ;
V_8 -> V_143 = V_145 ;
}
static void F_301 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
V_8 -> V_86 . V_93 [ 0 ] = 0x15 ;
V_8 -> V_86 . V_91 [ 0 ] = 0x14 ;
V_8 -> V_128 . V_129 = 0x18 ;
V_8 -> V_128 . V_9 = 0 ;
V_8 -> V_170 . V_129 = 0x12 ;
V_8 -> V_170 . V_9 = 9 ;
V_8 -> V_169 = 1 ;
V_8 -> V_150 = 1 ;
V_8 -> V_143 = V_144 ;
}
static void F_302 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
V_8 -> V_86 . V_93 [ 0 ] = 0x14 ;
V_8 -> V_86 . V_93 [ 1 ] = 0x1b ;
V_8 -> V_86 . V_91 [ 0 ] = 0x15 ;
V_8 -> V_150 = 1 ;
V_8 -> V_143 = V_145 ;
}
static void F_303 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
V_8 -> V_86 . V_93 [ 0 ] = 0x1b ;
V_8 -> V_86 . V_91 [ 0 ] = 0x14 ;
V_8 -> V_86 . V_91 [ 1 ] = 0x16 ;
V_8 -> V_150 = 1 ;
V_8 -> V_143 = V_145 ;
}
static void F_304 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
unsigned int V_137 ;
V_137 = 0 ;
if ( ! V_8 -> V_20 [ 0 ] ) {
V_8 -> V_151 = F_47 ( V_6 , 0x15 ) ;
if ( V_8 -> V_151 )
V_137 = V_31 ;
}
F_9 ( V_6 , 0x14 , V_59 , 0 ,
V_31 , V_137 ) ;
F_9 ( V_6 , 0x15 , V_59 , 0 ,
V_31 , V_137 ? 0 : V_31 ) ;
}
static void F_305 ( struct V_5 * V_6 ,
unsigned int V_173 )
{
if ( ( V_173 >> 26 ) != V_175 )
return;
F_304 ( V_6 ) ;
}
static int F_306 ( struct V_1 * V_2 ,
struct V_14 * V_15 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = V_6 -> V_8 ;
int V_496 ;
V_496 = F_6 ( V_2 , V_15 ) ;
if ( ! V_496 )
return 0 ;
F_23 ( V_6 , 0x15 , 0 ,
V_58 ,
V_8 -> V_20 [ 0 ] ? V_78 : V_141 ) ;
F_304 ( V_6 ) ;
return V_496 ;
}
static int F_307 ( T_1 V_23 )
{
if ( ! V_23 )
return 0 ;
else if ( V_23 == 0x16 )
return 2 ;
else
return 1 ;
}
static int F_308 ( struct V_7 * V_8 , T_1 V_23 ,
const char * V_362 , int * V_497 , int V_29 )
{
unsigned long V_57 ;
int V_498 ;
V_498 = F_307 ( V_23 ) ;
if ( ! V_498 )
return 0 ;
if ( * V_497 & V_498 )
return 0 ;
* V_497 |= V_498 ;
if ( V_498 == 2 )
V_57 = F_104 ( 0x0e , 2 , 0 , V_59 ) ;
else
V_57 = F_104 ( 0x0c , 3 , 0 , V_59 ) ;
return F_199 ( V_8 , V_373 , V_362 , V_29 , V_57 ) ;
}
static int F_309 ( struct V_7 * V_8 , T_1 V_23 ,
const char * V_362 , int V_29 )
{
unsigned long V_57 ;
if ( ! V_23 )
return 0 ;
if ( V_23 == 0x16 )
V_57 = F_104 ( V_23 , 2 , 0 , V_59 ) ;
else
V_57 = F_104 ( V_23 , 3 , 0 , V_59 ) ;
return F_200 ( V_8 , V_376 , V_362 , V_29 , V_57 ) ;
}
static int F_310 ( struct V_7 * V_8 ,
const struct V_84 * V_85 )
{
const char * V_362 ;
int V_497 ;
int V_28 , V_38 ;
V_8 -> V_40 . V_43 = 1 ;
V_8 -> V_40 . V_106 = V_8 -> V_365 ;
V_8 -> V_365 [ 0 ] = 2 ;
V_362 = F_193 ( V_8 , true ) ;
if ( ! V_362 )
V_362 = L_45 ;
for ( V_28 = 0 ; V_28 < 2 ; V_28 ++ ) {
V_38 = F_309 ( V_8 , V_85 -> V_89 [ V_28 ] , V_362 , V_28 ) ;
if ( V_38 < 0 )
return V_38 ;
if ( V_85 -> V_368 != V_369 ) {
V_38 = F_309 ( V_8 , V_85 -> V_91 [ V_28 ] ,
L_51 , V_28 ) ;
if ( V_38 < 0 )
return V_38 ;
}
if ( V_85 -> V_368 != V_370 ) {
V_38 = F_309 ( V_8 , V_85 -> V_93 [ V_28 ] ,
L_52 , V_28 ) ;
if ( V_38 < 0 )
return V_38 ;
}
}
V_497 = F_307 ( V_85 -> V_89 [ 0 ] ) |
F_307 ( V_85 -> V_91 [ 0 ] ) |
F_307 ( V_85 -> V_93 [ 0 ] ) ;
if ( V_497 == 1 || V_497 == 2 )
V_362 = L_50 ;
V_497 = 0 ;
for ( V_28 = 0 ; V_28 < 2 ; V_28 ++ ) {
V_38 = F_308 ( V_8 , V_85 -> V_89 [ V_28 ] , V_362 ,
& V_497 , V_28 ) ;
if ( V_38 < 0 )
return V_38 ;
if ( V_85 -> V_368 != V_369 ) {
V_38 = F_308 ( V_8 , V_85 -> V_91 [ V_28 ] ,
L_51 , & V_497 , V_28 ) ;
if ( V_38 < 0 )
return V_38 ;
}
if ( V_85 -> V_368 != V_370 ) {
V_38 = F_308 ( V_8 , V_85 -> V_93 [ V_28 ] ,
L_52 , & V_497 , V_28 ) ;
if ( V_38 < 0 )
return V_38 ;
}
}
return 0 ;
}
static int F_311 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
int V_38 ;
static const T_1 V_499 [] = { 0x1d , 0 } ;
V_38 = F_219 ( V_6 , & V_8 -> V_86 ,
V_499 ) ;
if ( V_38 < 0 )
return V_38 ;
if ( ! V_8 -> V_86 . V_87 ) {
if ( V_8 -> V_86 . V_262 || V_8 -> V_86 . V_264 ) {
V_8 -> V_40 . V_41 = 2 ;
V_8 -> V_285 = 1 ;
goto V_500;
}
return 0 ;
}
V_38 = F_310 ( V_8 , & V_8 -> V_86 ) ;
if ( V_38 < 0 )
return V_38 ;
V_38 = F_312 ( V_6 , & V_8 -> V_86 ) ;
if ( V_38 < 0 )
return V_38 ;
V_8 -> V_40 . V_41 = V_8 -> V_40 . V_43 * 2 ;
V_500:
F_94 ( V_6 ) ;
if ( V_8 -> V_338 . V_339 )
F_34 ( V_8 , V_8 -> V_338 . V_339 ) ;
F_37 ( V_8 , V_501 ) ;
V_8 -> V_11 = 1 ;
V_8 -> V_12 = & V_8 -> V_384 [ 0 ] ;
V_38 = F_290 ( V_6 ) ;
if ( V_38 < 0 )
return V_38 ;
F_84 ( V_6 , 0x15 , 0x1b , 0x14 , 0 ) ;
return 1 ;
}
static void F_313 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
F_314 ( V_6 ) ;
F_315 ( V_6 ) ;
F_316 ( V_6 ) ;
F_317 ( V_6 ) ;
F_93 ( V_6 ) ;
if ( V_8 -> V_112 )
F_59 ( V_6 ) ;
}
static int F_318 ( struct V_5 * V_6 )
{
struct V_7 * V_8 ;
int V_421 ;
int V_38 ;
V_8 = F_231 ( sizeof( * V_8 ) , V_196 ) ;
if ( V_8 == NULL )
return - V_194 ;
V_6 -> V_8 = V_8 ;
#if 0
{
int tmp;
snd_hda_codec_write(codec, 0x1a, 0, AC_VERB_SET_COEF_INDEX, 7);
tmp = snd_hda_codec_read(codec, 0x20, 0, AC_VERB_GET_PROC_COEF, 0);
snd_hda_codec_write(codec, 0x1a, 0, AC_VERB_SET_COEF_INDEX, 7);
snd_hda_codec_write(codec, 0x1a, 0, AC_VERB_SET_PROC_COEF, tmp | 0x80);
}
#endif
F_80 ( V_6 ) ;
F_41 ( V_6 , 0x20 , 0x0a , 10 ) ;
V_421 = F_232 ( V_6 , V_502 ,
V_503 ,
V_504 ) ;
if ( V_421 < 0 ) {
F_81 ( V_221 L_59 ,
V_6 -> V_222 ) ;
V_421 = V_505 ;
}
if ( V_421 == V_505 ) {
F_89 ( V_6 , NULL , V_506 , V_507 ) ;
F_85 ( V_6 , V_245 ) ;
}
if ( V_421 == V_505 ) {
V_38 = F_311 ( V_6 ) ;
if ( V_38 < 0 ) {
F_169 ( V_6 ) ;
return V_38 ;
} else if ( ! V_38 ) {
F_81 ( V_221
L_60
L_62 ) ;
V_421 = V_508 ;
}
}
if ( ! V_8 -> V_285 && F_229 ( V_6 ) ) {
V_38 = F_233 ( V_6 , 0x1 ) ;
if ( V_38 < 0 ) {
F_169 ( V_6 ) ;
return V_38 ;
}
}
if ( V_421 != V_505 )
F_38 ( V_6 , & V_509 [ V_421 ] ) ;
V_8 -> V_320 = & V_510 ;
V_8 -> V_323 = & V_511 ;
V_8 -> V_329 = & V_512 ;
V_8 -> V_330 = & V_513 ;
if ( ! V_8 -> V_25 && V_8 -> V_12 ) {
int V_28 ;
for ( V_28 = 0 ; V_28 < V_8 -> V_12 -> V_13 ; V_28 ++ ) {
if ( V_8 -> V_12 -> V_33 [ V_28 ] . V_34 >= 9 )
break;
}
if ( V_28 < V_8 -> V_12 -> V_13 ) {
V_8 -> V_25 = V_514 ;
V_8 -> V_110 = 1 ;
V_8 -> V_24 = V_515 ;
} else {
unsigned int V_433 = F_8 ( V_6 , 0x07 ) ;
V_433 = F_7 ( V_433 ) ;
if ( V_433 != V_270 ) {
V_8 -> V_25 = V_516 ;
V_8 -> V_110 =
F_36 ( V_516 ) ;
V_8 -> V_24 = V_517 ;
} else {
V_8 -> V_25 = V_518 ;
V_8 -> V_110 =
F_36 ( V_518 ) ;
V_8 -> V_24 = V_519 ;
}
}
}
if ( ! V_8 -> V_104 && ! V_8 -> V_285 )
F_227 ( V_6 ) ;
if ( ! V_8 -> V_285 && F_229 ( V_6 ) )
F_234 ( V_8 , 0x0b , 0x05 , V_32 ) ;
F_85 ( V_6 , V_249 ) ;
V_8 -> V_290 = 0x0c ;
V_6 -> V_342 = V_436 ;
if ( V_421 == V_505 )
V_8 -> V_113 = F_313 ;
V_8 -> V_337 = F_64 ;
F_42 ( V_6 ) ;
#ifdef F_39
if ( ! V_8 -> V_115 . V_116 )
V_8 -> V_115 . V_116 = V_520 ;
#endif
return 0 ;
}
static void F_319 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
V_8 -> V_86 . V_93 [ 0 ] = 0x14 ;
V_8 -> V_86 . V_91 [ 0 ] = 0x15 ;
V_8 -> V_150 = 1 ;
V_8 -> V_143 = V_145 ;
}
static void F_320 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
V_8 -> V_86 . V_93 [ 0 ] = 0x15 ;
V_8 -> V_86 . V_91 [ 0 ] = 0x14 ;
V_8 -> V_150 = 1 ;
V_8 -> V_143 = V_145 ;
V_8 -> V_128 . V_129 = 0x18 ;
V_8 -> V_128 . V_9 = 0 ;
V_8 -> V_170 . V_129 = 0x12 ;
V_8 -> V_170 . V_9 = 6 ;
V_8 -> V_169 = 1 ;
}
static void F_321 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
V_8 -> V_86 . V_93 [ 0 ] = 0x15 ;
V_8 -> V_86 . V_91 [ 0 ] = 0x14 ;
V_8 -> V_128 . V_129 = 0x18 ;
V_8 -> V_128 . V_9 = 0 ;
V_8 -> V_170 . V_129 = 0x19 ;
V_8 -> V_170 . V_9 = 1 ;
V_8 -> V_169 = 1 ;
V_8 -> V_150 = 1 ;
V_8 -> V_143 = V_144 ;
}
static void F_322 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
V_8 -> V_86 . V_93 [ 0 ] = 0x15 ;
V_8 -> V_86 . V_91 [ 0 ] = 0x14 ;
V_8 -> V_128 . V_129 = 0x18 ;
V_8 -> V_128 . V_9 = 0 ;
V_8 -> V_170 . V_129 = 0x19 ;
V_8 -> V_170 . V_9 = 1 ;
V_8 -> V_169 = 1 ;
V_8 -> V_150 = 1 ;
V_8 -> V_143 = V_144 ;
}
static int F_323 ( struct V_7 * V_8 , T_1 V_23 ,
const char * V_377 , int V_29 )
{
T_1 V_472 ;
int V_38 ;
switch ( V_23 ) {
case 0x14 :
case 0x16 :
V_472 = 0x02 ;
break;
case 0x15 :
case 0x1a :
case 0x1b :
case 0x21 :
V_472 = 0x03 ;
break;
default:
F_82 ( V_418 L_64
L_65 , V_23 ) ;
return 0 ;
}
if ( V_8 -> V_40 . V_106 [ 0 ] != V_472 &&
V_8 -> V_40 . V_106 [ 1 ] != V_472 ) {
V_38 = F_197 ( V_8 , V_373 , V_377 ,
F_104 ( V_472 , 3 , V_29 ,
V_59 ) ) ;
if ( V_38 < 0 )
return V_38 ;
V_8 -> V_365 [ V_8 -> V_40 . V_43 ++ ] = V_472 ;
}
if ( V_23 != 0x16 )
V_38 = F_198 ( V_8 , V_376 , V_377 ,
F_104 ( V_23 , 3 , V_29 , V_59 ) ) ;
else
V_38 = F_198 ( V_8 , V_376 , V_377 ,
F_104 ( V_23 , 2 , V_29 , V_59 ) ) ;
if ( V_38 < 0 )
return V_38 ;
return 0 ;
}
static int F_324 ( struct V_7 * V_8 ,
const struct V_84 * V_85 )
{
T_1 V_23 ;
int V_38 ;
V_8 -> V_40 . V_106 = V_8 -> V_365 ;
V_23 = V_85 -> V_89 [ 0 ] ;
if ( V_23 ) {
const char * V_50 ;
if ( V_85 -> V_368 == V_369 )
V_50 = L_51 ;
else
V_50 = L_45 ;
V_38 = F_323 ( V_8 , V_23 , V_50 , 0 ) ;
if ( V_38 < 0 )
return V_38 ;
}
V_23 = V_85 -> V_91 [ 0 ] ;
if ( V_23 == 0x1d ) {
V_38 = F_197 ( V_8 , V_373 , L_51 ,
F_104 ( V_23 , 3 , 0 , V_32 ) ) ;
if ( V_38 < 0 )
return V_38 ;
} else if ( V_23 ) {
V_38 = F_323 ( V_8 , V_23 , L_51 , 0 ) ;
if ( V_38 < 0 )
return V_38 ;
}
V_23 = V_85 -> V_93 [ 0 ] ;
if ( V_23 ) {
V_38 = F_323 ( V_8 , V_23 , L_52 , 0 ) ;
if ( V_38 < 0 )
return V_38 ;
}
V_23 = V_85 -> V_89 [ 1 ] | V_85 -> V_89 [ 2 ] ;
if ( V_23 == 0x16 ) {
V_38 = F_198 ( V_8 , V_376 , L_66 ,
F_104 ( V_23 , 2 , 0 , V_59 ) ) ;
if ( V_38 < 0 )
return V_38 ;
}
return 0 ;
}
static int F_325 ( struct V_5 * V_6 ,
const struct V_84 * V_85 )
{
return F_205 ( V_6 , V_85 , 0 , 0x23 , 0x24 ) ;
}
static void F_326 ( struct V_5 * V_6 ,
T_1 V_23 , int V_388 )
{
int V_29 ;
F_209 ( V_6 , V_23 , V_388 ) ;
if ( V_23 == 0x14 || V_23 == 0x16 )
V_29 = 0 ;
else
V_29 = 1 ;
F_32 ( V_6 , V_23 , 0 , V_172 , V_29 ) ;
}
static void F_327 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
int V_28 ;
for ( V_28 = 0 ; V_28 < V_8 -> V_86 . V_87 ; V_28 ++ ) {
T_1 V_23 = V_8 -> V_86 . V_89 [ V_28 ] ;
int V_388 = F_213 ( V_8 -> V_86 . V_368 ) ;
F_326 ( V_6 , V_23 , V_388 ) ;
}
}
static void F_328 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
T_1 V_129 ;
int V_28 ;
for ( V_28 = 0 ; V_28 < V_8 -> V_86 . V_92 ; V_28 ++ ) {
V_129 = V_8 -> V_86 . V_93 [ V_28 ] ;
F_326 ( V_6 , V_129 , V_141 ) ;
}
for ( V_28 = 0 ; V_28 < V_8 -> V_86 . V_90 ; V_28 ++ ) {
V_129 = V_8 -> V_86 . V_91 [ V_28 ] ;
F_326 ( V_6 , V_129 , V_142 ) ;
}
if ( V_8 -> V_86 . V_521 )
F_32 ( V_6 , V_8 -> V_86 . V_521 , 0 ,
V_58 , V_142 ) ;
}
static void F_329 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
T_1 V_522 = V_8 -> V_86 . V_91 [ 0 ] ;
T_1 V_109 = V_8 -> V_86 . V_93 [ 0 ] ;
T_1 V_523 = V_8 -> V_86 . V_89 [ 0 ] ;
unsigned int V_524 , V_525 ;
if ( V_523 == 0x1d || V_522 == 0x1d ) {
F_32 ( V_6 , V_522 , 0 ,
V_58 , V_142 ) ;
F_32 ( V_6 , 0x0f , 0 ,
V_389 ,
F_289 ( 1 ) ) ;
F_32 ( V_6 , 0x10 , 0 ,
V_389 ,
F_289 ( 1 ) ) ;
} else {
F_32 ( V_6 , 0x0f , 0 ,
V_389 , F_288 ( 1 ) ) ;
F_32 ( V_6 , 0x10 , 0 ,
V_389 , F_288 ( 1 ) ) ;
}
V_524 = V_525 = 0xb000 | 0x40 ;
if ( V_523 == 0x14 )
V_525 = V_526 ;
else if ( V_523 == 0x15 )
V_524 = V_526 ;
if ( V_109 == 0x14 )
V_525 = V_526 ;
else if ( V_109 == 0x15 )
V_524 = V_526 ;
if ( V_523 != 0x16 || V_109 != 0x16 ||
V_8 -> V_86 . V_89 [ 1 ] != 0x16 ||
V_8 -> V_86 . V_89 [ 2 ] != 0x16 )
V_524 = V_525 = V_526 ;
F_32 ( V_6 , 0x02 , 0 ,
V_389 , V_524 ) ;
F_32 ( V_6 , 0x03 , 0 ,
V_389 , V_525 ) ;
}
static int F_330 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
int V_38 ;
static const T_1 V_527 [] = { 0 } ;
V_38 = F_219 ( V_6 , & V_8 -> V_86 ,
V_527 ) ;
if ( V_38 < 0 )
return V_38 ;
if ( ! V_8 -> V_86 . V_87 ) {
if ( V_8 -> V_86 . V_262 || V_8 -> V_86 . V_264 ) {
V_8 -> V_40 . V_41 = 2 ;
V_8 -> V_285 = 1 ;
goto V_500;
}
return 0 ;
}
V_38 = F_324 ( V_8 , & V_8 -> V_86 ) ;
if ( V_38 < 0 )
return V_38 ;
V_38 = F_325 ( V_6 , & V_8 -> V_86 ) ;
if ( V_38 < 0 )
return V_38 ;
V_8 -> V_40 . V_41 = 2 ;
V_500:
F_94 ( V_6 ) ;
if ( V_8 -> V_338 . V_339 )
F_34 ( V_8 , V_8 -> V_338 . V_339 ) ;
if ( ! V_8 -> V_285 && V_8 -> V_86 . V_91 [ 0 ] != 0x1d )
F_34 ( V_8 , V_528 ) ;
F_37 ( V_8 , V_529 ) ;
V_8 -> V_11 = 2 ;
V_8 -> V_12 = & V_8 -> V_384 [ 0 ] ;
V_38 = F_290 ( V_6 ) ;
if ( V_38 < 0 )
return V_38 ;
F_84 ( V_6 , 0x15 , 0x1b , 0x14 , 0 ) ;
return 1 ;
}
static void F_331 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
F_327 ( V_6 ) ;
F_328 ( V_6 ) ;
F_329 ( V_6 ) ;
F_332 ( V_6 ) ;
F_333 ( V_6 ) ;
F_93 ( V_6 ) ;
if ( V_8 -> V_112 )
F_59 ( V_6 ) ;
}
static int F_334 ( struct V_5 * V_6 )
{
struct V_7 * V_8 ;
int V_421 ;
int V_28 , V_530 , V_38 ;
V_8 = F_231 ( sizeof( * V_8 ) , V_196 ) ;
if ( V_8 == NULL )
return - V_194 ;
V_6 -> V_8 = V_8 ;
V_421 = F_232 ( V_6 , V_531 ,
V_532 ,
V_533 ) ;
if ( V_421 < 0 || V_421 >= V_531 )
V_421 = F_294 ( V_6 ,
V_531 , V_532 , V_534 ) ;
if ( V_421 < 0 || V_421 >= V_531 ) {
F_81 ( V_221 L_59 ,
V_6 -> V_222 ) ;
V_421 = V_535 ;
}
if ( V_421 == V_535 ) {
V_38 = F_330 ( V_6 ) ;
if ( V_38 < 0 ) {
F_169 ( V_6 ) ;
return V_38 ;
} else if ( ! V_38 ) {
F_81 ( V_221
L_60
L_62 ) ;
V_421 = V_536 ;
}
}
if ( V_421 != V_535 )
F_38 ( V_6 , & V_537 [ V_421 ] ) ;
V_8 -> V_320 = & V_538 ;
V_8 -> V_323 = & V_539 ;
V_8 -> V_334 = & V_540 ;
V_8 -> V_329 = & V_541 ;
V_530 = 0 ;
for ( V_28 = 0 ; V_28 < V_8 -> V_96 ; V_28 ++ ) {
if ( V_8 -> V_97 [ V_28 ] == V_528 ) {
V_530 = 1 ;
break;
}
}
if ( V_530 ) {
V_38 = F_233 ( V_6 , 0x1 ) ;
if ( V_38 < 0 ) {
F_169 ( V_6 ) ;
return V_38 ;
}
if ( ! F_335 ( V_6 , 0x1d , V_32 ) )
F_336 ( V_6 , 0x1d , V_32 ,
( 0x0c << V_542 ) |
( 0x0c << V_543 ) |
( 0x07 << V_544 ) |
( 0 << V_545 ) ) ;
}
if ( ! V_8 -> V_285 && ! V_8 -> V_25 && V_8 -> V_12 ) {
unsigned int V_433 = F_8 ( V_6 , 0x07 ) ;
V_8 -> V_24 = V_546 ;
V_433 = F_7 ( V_433 ) ;
if ( V_8 -> V_169 ||
V_433 != V_270 || V_8 -> V_12 -> V_13 == 1 ) {
V_8 -> V_25 = V_547 ;
V_8 -> V_110 = F_36 ( V_547 ) ;
if ( V_8 -> V_169 )
F_222 ( V_6 ) ;
if ( V_8 -> V_169 || V_8 -> V_12 -> V_13 == 1 )
F_34 ( V_8 , V_548 ) ;
else
F_34 ( V_8 , V_549 ) ;
} else {
V_8 -> V_25 = V_550 ;
V_8 -> V_110 = F_36 ( V_550 ) ;
F_34 ( V_8 , V_551 ) ;
}
}
V_8 -> V_290 = 0x02 ;
V_6 -> V_342 = V_436 ;
if ( V_421 == V_535 )
V_8 -> V_113 = F_331 ;
V_8 -> V_337 = F_64 ;
F_42 ( V_6 ) ;
return 0 ;
}
static void F_337 ( struct V_5 * V_6 )
{
F_50 ( V_6 ) ;
F_32 ( V_6 , 0x20 , 0 ,
V_120 , 0x0c ) ;
F_32 ( V_6 , 0x20 , 0 ,
V_123 , 0x680 ) ;
F_32 ( V_6 , 0x20 , 0 ,
V_120 , 0x0c ) ;
F_32 ( V_6 , 0x20 , 0 ,
V_123 , 0x480 ) ;
}
static void F_338 ( struct V_5 * V_6 )
{
unsigned int V_552 ;
unsigned int V_553 ;
V_552 = F_47 ( V_6 , 0x18 ) ;
V_553 = F_47 ( V_6 , 0x1b ) ;
if ( V_553 )
F_32 ( V_6 , 0x23 , 0 ,
V_172 , 0x3 ) ;
if ( V_552 )
F_32 ( V_6 , 0x23 , 0 ,
V_172 , 0x0 ) ;
if ( ! V_553 && ! V_552 )
F_32 ( V_6 , 0x23 , 0 ,
V_172 , 0x1 ) ;
}
static void F_339 ( struct V_5 * V_6 ,
unsigned int V_173 )
{
switch ( V_173 >> 26 ) {
case V_175 :
F_337 ( V_6 ) ;
break;
case V_177 :
F_57 ( V_6 ) ;
break;
}
}
static void F_340 ( struct V_5 * V_6 ,
unsigned int V_173 )
{
if ( ( V_173 >> 26 ) == V_175 )
F_341 ( V_6 ) ;
if ( ( V_173 >> 26 ) == V_177 )
F_338 ( V_6 ) ;
}
static void F_342 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
V_8 -> V_86 . V_93 [ 0 ] = 0x15 ;
V_8 -> V_86 . V_91 [ 0 ] = 0x14 ;
V_8 -> V_147 [ 0 ] = 0x0c ;
V_8 -> V_150 = 1 ;
V_8 -> V_143 = V_146 ;
V_8 -> V_128 . V_129 = 0x18 ;
V_8 -> V_128 . V_9 = 0 ;
V_8 -> V_170 . V_129 = 0x19 ;
V_8 -> V_170 . V_9 = 1 ;
V_8 -> V_169 = 1 ;
}
static void F_343 ( struct V_5 * V_6 )
{
F_337 ( V_6 ) ;
F_57 ( V_6 ) ;
}
static void F_344 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
V_8 -> V_86 . V_93 [ 0 ] = 0x15 ;
V_8 -> V_86 . V_93 [ 1 ] = 0x1a ;
V_8 -> V_86 . V_91 [ 0 ] = 0x14 ;
V_8 -> V_147 [ 0 ] = 0x0c ;
V_8 -> V_150 = 1 ;
V_8 -> V_143 = V_146 ;
}
static void F_345 ( struct V_5 * V_6 )
{
F_341 ( V_6 ) ;
F_338 ( V_6 ) ;
}
static void F_346 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
V_8 -> V_86 . V_93 [ 0 ] = 0x15 ;
V_8 -> V_86 . V_91 [ 0 ] = 0x14 ;
V_8 -> V_147 [ 0 ] = 0x0c ;
V_8 -> V_150 = 1 ;
V_8 -> V_143 = V_146 ;
V_8 -> V_128 . V_129 = 0x18 ;
V_8 -> V_128 . V_9 = 0 ;
V_8 -> V_170 . V_129 = 0x19 ;
V_8 -> V_170 . V_9 = 1 ;
V_8 -> V_169 = 1 ;
}
static void F_347 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
V_8 -> V_86 . V_93 [ 0 ] = 0x15 ;
V_8 -> V_86 . V_91 [ 0 ] = 0x14 ;
V_8 -> V_147 [ 0 ] = 0x0c ;
V_8 -> V_150 = 1 ;
V_8 -> V_143 = V_146 ;
V_8 -> V_128 . V_129 = 0x18 ;
V_8 -> V_128 . V_9 = 0 ;
V_8 -> V_170 . V_129 = 0x12 ;
V_8 -> V_170 . V_9 = 5 ;
V_8 -> V_169 = 1 ;
}
static void F_348 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
V_8 -> V_86 . V_93 [ 0 ] = 0x21 ;
V_8 -> V_86 . V_91 [ 0 ] = 0x14 ;
V_8 -> V_147 [ 0 ] = 0x0c ;
V_8 -> V_150 = 1 ;
V_8 -> V_143 = V_146 ;
V_8 -> V_128 . V_129 = 0x18 ;
V_8 -> V_128 . V_9 = 0 ;
V_8 -> V_170 . V_129 = 0x19 ;
V_8 -> V_170 . V_9 = 1 ;
V_8 -> V_169 = 1 ;
}
static void F_349 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
V_8 -> V_86 . V_93 [ 0 ] = 0x21 ;
V_8 -> V_86 . V_91 [ 0 ] = 0x14 ;
V_8 -> V_147 [ 0 ] = 0x0c ;
V_8 -> V_150 = 1 ;
V_8 -> V_143 = V_146 ;
V_8 -> V_128 . V_129 = 0x18 ;
V_8 -> V_128 . V_9 = 0 ;
V_8 -> V_170 . V_129 = 0x12 ;
V_8 -> V_170 . V_9 = 6 ;
V_8 -> V_169 = 1 ;
}
static int F_350 ( struct V_5 * V_6 )
{
switch ( V_6 -> V_217 ) {
case 0x103c1586 :
return 1 ;
}
return 0 ;
}
static int F_351 ( struct V_5 * V_6 , T_1 V_23 )
{
if ( V_23 == 0x01 || V_23 == 0x14 ) {
int V_554 ;
if ( F_352 ( V_6 , 0x14 , 0 , V_59 , 0 ) &
V_31 )
V_554 = 0x24 ;
else
V_554 = 0x20 ;
F_353 ( V_6 , 0x19 , 0 ,
V_58 ,
V_554 ) ;
}
return F_143 ( V_6 , V_23 ) ;
}
static int F_354 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
if ( V_6 -> V_174 != 0x10ec0275 || ! V_8 -> V_169 )
return 0 ;
if ( ( V_8 -> V_128 . V_129 >= 0x18 && V_8 -> V_170 . V_129 <= 0x13 ) ||
( V_8 -> V_128 . V_129 <= 0x12 && V_8 -> V_170 . V_129 >= 0x18 ) ) {
if ( V_8 -> V_128 . V_129 <= 0x12 ) {
V_8 -> V_416 [ 0 ] = 0x08 ;
V_8 -> V_416 [ 1 ] = 0x11 ;
V_8 -> V_417 [ 0 ] = 0x23 ;
V_8 -> V_417 [ 1 ] = 0x22 ;
} else {
V_8 -> V_416 [ 0 ] = 0x11 ;
V_8 -> V_416 [ 1 ] = 0x08 ;
V_8 -> V_417 [ 0 ] = 0x22 ;
V_8 -> V_417 [ 1 ] = 0x23 ;
}
V_8 -> V_25 = V_8 -> V_416 ;
V_8 -> V_24 = V_8 -> V_417 ;
V_8 -> V_110 = 2 ;
V_8 -> V_171 = 1 ;
F_76 ( L_67 ,
V_8 -> V_25 [ 0 ] , V_8 -> V_25 [ 1 ] ) ;
return 1 ;
}
return 0 ;
}
static int F_355 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
int V_38 ;
static const T_1 V_555 [] = { 0x1d , 0 } ;
V_38 = F_219 ( V_6 , & V_8 -> V_86 ,
V_555 ) ;
if ( V_38 < 0 )
return V_38 ;
V_38 = F_356 ( V_8 , & V_8 -> V_86 ) ;
if ( V_38 < 0 )
return V_38 ;
if ( V_8 -> V_556 == V_557 )
V_38 = F_357 ( V_6 , & V_8 -> V_86 ) ;
else
V_38 = F_205 ( V_6 , & V_8 -> V_86 , 0 ,
0x22 , 0 ) ;
if ( V_38 < 0 )
return V_38 ;
V_8 -> V_40 . V_41 = V_8 -> V_40 . V_43 * 2 ;
F_94 ( V_6 ) ;
if ( V_8 -> V_338 . V_339 )
F_34 ( V_8 , V_8 -> V_338 . V_339 ) ;
if ( V_8 -> V_556 != V_557 ) {
F_37 ( V_8 , V_558 ) ;
F_84 ( V_6 , 0 , 0x1b , 0x14 , 0x21 ) ;
} else {
F_37 ( V_8 , V_559 ) ;
F_84 ( V_6 , 0x15 , 0x1b , 0x14 , 0 ) ;
}
V_8 -> V_11 = 1 ;
V_8 -> V_12 = & V_8 -> V_384 [ 0 ] ;
if ( ! F_354 ( V_6 ) )
F_228 ( V_6 , V_560 ,
sizeof( V_560 ) ) ;
V_38 = F_290 ( V_6 ) ;
if ( V_38 < 0 )
return V_38 ;
if ( ! V_8 -> V_104 && ! V_8 -> V_285 )
F_227 ( V_6 ) ;
return 1 ;
}
static void F_358 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
F_359 ( V_6 ) ;
F_360 ( V_6 ) ;
F_361 ( V_6 ) ;
if ( ! V_8 -> V_171 )
F_362 ( V_6 ) ;
F_93 ( V_6 ) ;
if ( V_8 -> V_112 )
F_59 ( V_6 ) ;
}
static void F_363 ( struct V_5 * V_6 , int V_561 )
{
int V_57 = F_91 ( V_6 , 0x04 ) ;
if ( V_561 )
V_57 |= 1 << 11 ;
else
V_57 &= ~ ( 1 << 11 ) ;
F_92 ( V_6 , 0x04 , V_57 ) ;
}
static void F_364 ( struct V_5 * V_6 )
{
if ( ( F_91 ( V_6 , 0 ) & 0x00ff ) == 0x017 )
F_363 ( V_6 , 0 ) ;
if ( ( F_91 ( V_6 , 0 ) & 0x00ff ) == 0x018 ) {
F_363 ( V_6 , 0 ) ;
F_65 ( 150 ) ;
}
}
static int F_365 ( struct V_5 * V_6 )
{
if ( ( F_91 ( V_6 , 0 ) & 0x00ff ) == 0x018 ) {
F_363 ( V_6 , 0 ) ;
F_65 ( 150 ) ;
}
V_6 -> V_342 . V_343 ( V_6 ) ;
if ( ( F_91 ( V_6 , 0 ) & 0x00ff ) == 0x017 ) {
F_363 ( V_6 , 1 ) ;
F_65 ( 200 ) ;
}
if ( ( F_91 ( V_6 , 0 ) & 0x00ff ) == 0x018 )
F_363 ( V_6 , 1 ) ;
F_175 ( V_6 ) ;
F_176 ( V_6 ) ;
F_141 ( V_6 , 0x01 ) ;
return 0 ;
}
static void F_366 ( struct V_5 * V_6 ,
const struct V_241 * V_242 , int V_235 )
{
int V_562 ;
if ( V_235 != V_305 )
return;
V_562 = F_91 ( V_6 , 0x1e ) ;
F_92 ( V_6 , 0x1e , V_562 | 0x80 ) ;
}
static void F_367 ( struct V_5 * V_6 ,
const struct V_241 * V_242 , int V_235 )
{
static const struct V_98 V_250 [] = {
{ 0x20 , V_120 , 0x0d } ,
{ 0x20 , V_123 , 0x4000 } ,
{}
} ;
unsigned int V_85 ;
if ( strcmp ( V_6 -> V_222 , L_68 ) )
return;
V_85 = F_78 ( V_6 , 0x12 ) ;
if ( F_368 ( V_85 ) == V_563 )
F_67 ( V_6 , V_250 ) ;
}
static int F_369 ( struct V_5 * V_6 )
{
int V_57 ;
if ( ( F_91 ( V_6 , 0 ) & 0x00ff ) < 0x015 ) {
F_92 ( V_6 , 0xf , 0x960b ) ;
F_92 ( V_6 , 0xe , 0x8817 ) ;
}
if ( ( F_91 ( V_6 , 0 ) & 0x00ff ) == 0x016 ) {
F_92 ( V_6 , 0xf , 0x960b ) ;
F_92 ( V_6 , 0xe , 0x8814 ) ;
}
if ( ( F_91 ( V_6 , 0 ) & 0x00ff ) == 0x017 ) {
V_57 = F_91 ( V_6 , 0x04 ) ;
F_92 ( V_6 , 0x04 , V_57 | ( 1 << 11 ) ) ;
}
if ( ( F_91 ( V_6 , 0 ) & 0x00ff ) == 0x018 ) {
V_57 = F_91 ( V_6 , 0xd ) ;
if ( ( V_57 & 0x0c00 ) >> 10 != 0x1 ) {
F_92 ( V_6 , 0xd , V_57 | ( 1 << 10 ) ) ;
}
V_57 = F_91 ( V_6 , 0x17 ) ;
if ( ( V_57 & 0x01c0 ) >> 6 != 0x4 ) {
F_92 ( V_6 , 0x17 , V_57 | ( 1 << 7 ) ) ;
}
}
V_57 = F_91 ( V_6 , 0xd ) ;
F_92 ( V_6 , 0xd , V_57 | ( 1 << 14 ) ) ;
V_57 = F_91 ( V_6 , 0x4 ) ;
F_92 ( V_6 , 0x4 , V_57 | ( 1 << 11 ) ) ;
return 0 ;
}
static int F_370 ( struct V_5 * V_6 )
{
struct V_7 * V_8 ;
int V_421 , V_562 ;
int V_38 ;
V_8 = F_231 ( sizeof( * V_8 ) , V_196 ) ;
if ( V_8 == NULL )
return - V_194 ;
V_6 -> V_8 = V_8 ;
F_80 ( V_6 ) ;
if ( V_6 -> V_174 == 0x10ec0269 ) {
V_562 = F_91 ( V_6 , 0 ) ;
if ( ( V_562 & 0x00f0 ) == 0x0010 ) {
if ( V_6 -> V_218 -> V_219 -> V_564 == 0x1025 &&
V_8 -> V_211 . V_227 == 1 ) {
F_177 ( V_6 , L_68 ) ;
V_8 -> V_556 = V_565 ;
} else if ( ( V_562 & 0xf000 ) == 0x1000 ) {
V_8 -> V_556 = V_566 ;
} else if ( ( V_562 & 0xf000 ) == 0x2000 ) {
F_177 ( V_6 , L_69 ) ;
V_8 -> V_556 = V_567 ;
} else if ( ( V_562 & 0xf000 ) == 0x3000 ) {
F_177 ( V_6 , L_70 ) ;
V_8 -> V_556 = V_568 ;
} else {
F_177 ( V_6 , L_71 ) ;
V_8 -> V_556 = V_569 ;
}
} else
F_41 ( V_6 , 0x20 , 0x04 , 15 ) ;
F_369 ( V_6 ) ;
}
V_421 = F_232 ( V_6 , V_570 ,
V_571 ,
V_572 ) ;
if ( V_421 < 0 ) {
F_81 ( V_221 L_59 ,
V_6 -> V_222 ) ;
V_421 = V_573 ;
}
if ( V_421 == V_573 ) {
F_89 ( V_6 , NULL , V_574 , V_575 ) ;
F_85 ( V_6 , V_245 ) ;
}
if ( V_421 == V_573 ) {
V_38 = F_355 ( V_6 ) ;
if ( V_38 < 0 ) {
F_169 ( V_6 ) ;
return V_38 ;
} else if ( ! V_38 ) {
F_81 ( V_221
L_60
L_62 ) ;
V_421 = V_576 ;
}
}
if ( F_229 ( V_6 ) ) {
V_38 = F_233 ( V_6 , 0x1 ) ;
if ( V_38 < 0 ) {
F_169 ( V_6 ) ;
return V_38 ;
}
}
if ( V_421 != V_573 )
F_38 ( V_6 , & V_577 [ V_421 ] ) ;
if ( V_421 == V_578 ) {
V_8 -> V_320 = & V_579 ;
V_8 -> V_323 = & V_580 ;
} else if ( V_8 -> V_171 ) {
V_8 -> V_320 = & V_581 ;
V_8 -> V_323 = & V_582 ;
} else {
V_8 -> V_320 = & V_581 ;
V_8 -> V_323 = & V_583 ;
}
V_8 -> V_329 = & V_584 ;
V_8 -> V_330 = & V_585 ;
if ( ! V_8 -> V_25 ) {
if ( V_8 -> V_556 == V_557 ) {
V_8 -> V_25 = V_586 ;
V_8 -> V_110 = F_36 ( V_586 ) ;
V_8 -> V_24 = V_587 ;
} else {
V_8 -> V_25 = V_588 ;
V_8 -> V_110 = F_36 ( V_588 ) ;
V_8 -> V_24 = V_589 ;
}
}
if ( ! V_8 -> V_104 )
F_227 ( V_6 ) ;
if ( F_229 ( V_6 ) )
F_234 ( V_8 , 0x0b , 0x04 , V_32 ) ;
F_85 ( V_6 , V_249 ) ;
V_8 -> V_290 = 0x02 ;
V_6 -> V_342 = V_436 ;
#ifdef F_371
V_6 -> V_342 . V_590 = F_365 ;
#endif
if ( V_421 == V_573 )
V_8 -> V_113 = F_358 ;
V_8 -> V_337 = F_364 ;
F_42 ( V_6 ) ;
#ifdef F_39
if ( ! V_8 -> V_115 . V_116 )
V_8 -> V_115 . V_116 = V_591 ;
if ( F_350 ( V_6 ) )
V_6 -> V_342 . V_592 = F_351 ;
#endif
return 0 ;
}
static void F_372 ( struct V_5 * V_6 )
{
unsigned int V_136 = F_47 ( V_6 , 0x0f ) ;
F_9 ( V_6 , 0x16 , V_32 , 0 ,
V_31 , V_136 ? V_31 : 0 ) ;
F_9 ( V_6 , 0x1a , V_32 , 3 ,
V_31 , V_136 ? 0 : V_31 ) ;
}
static void F_373 ( struct V_5 * V_6 ,
unsigned int V_173 )
{
if ( ( V_173 >> 26 ) == V_175 )
F_372 ( V_6 ) ;
}
static T_1 F_374 ( struct V_5 * V_6 , T_1 V_129 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
T_1 V_95 , V_593 [ 5 ] ;
int V_28 , V_283 , V_594 ;
if ( F_53 ( V_6 , V_129 , & V_95 , 1 ) != 1 )
return 0 ;
V_594 = F_53 ( V_6 , V_95 , V_593 , F_36 ( V_593 ) ) ;
if ( V_594 < 0 )
return 0 ;
for ( V_28 = 0 ; V_28 < V_594 ; V_28 ++ ) {
unsigned int type ;
type = F_7 ( F_8 ( V_6 , V_593 [ V_28 ] ) ) ;
if ( type != V_595 )
continue;
for ( V_283 = 0 ; V_283 < V_8 -> V_40 . V_43 ; V_283 ++ )
if ( V_8 -> V_40 . V_106 [ V_283 ] == V_593 [ V_28 ] )
break;
if ( V_283 >= V_8 -> V_40 . V_43 )
return V_593 [ V_28 ] ;
}
return 0 ;
}
static int F_375 ( struct V_5 * V_6 ,
const struct V_84 * V_85 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
int V_28 ;
T_1 V_23 , V_472 ;
V_8 -> V_40 . V_106 = V_8 -> V_365 ;
for ( V_28 = 0 ; V_28 < V_85 -> V_87 ; V_28 ++ ) {
V_23 = V_85 -> V_89 [ V_28 ] ;
V_472 = F_374 ( V_6 , V_23 ) ;
if ( ! V_472 )
continue;
V_8 -> V_365 [ V_8 -> V_40 . V_43 ++ ] = V_472 ;
}
return 0 ;
}
static int F_376 ( struct V_5 * V_6 , const char * V_362 ,
T_1 V_23 , int V_29 , unsigned int V_596 )
{
return F_200 ( V_6 -> V_8 , V_376 , V_362 , V_29 ,
F_104 ( V_23 , V_596 , 0 , V_59 ) ) ;
}
static int F_377 ( struct V_5 * V_6 ,
const struct V_84 * V_85 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
static const char * const V_371 [ 4 ] = {
L_45 , L_46 , NULL , L_48
} ;
const char * V_362 = F_193 ( V_8 , true ) ;
T_1 V_23 ;
int V_28 , V_38 , V_372 ;
V_372 = V_85 -> V_87 ;
if ( V_8 -> V_367 > 0 )
V_372 += V_8 -> V_367 ;
for ( V_28 = 0 ; V_28 < V_372 ; V_28 ++ ) {
V_23 = V_8 -> V_40 . V_106 [ V_28 ] ;
if ( ! V_23 )
continue;
if ( ! V_362 && V_28 == 2 ) {
V_38 = F_378 ( V_6 , L_54 , V_23 , 1 ) ;
if ( V_38 < 0 )
return V_38 ;
V_38 = F_378 ( V_6 , L_55 , V_23 , 2 ) ;
if ( V_38 < 0 )
return V_38 ;
} else {
const char * V_50 = V_362 ;
int V_34 = V_28 ;
if ( ! V_50 ) {
V_50 = V_371 [ V_28 ] ;
V_34 = 0 ;
}
V_38 = F_376 ( V_6 , V_50 , V_23 , V_34 , 3 ) ;
if ( V_38 < 0 )
return V_38 ;
}
}
return 0 ;
}
static int F_379 ( struct V_5 * V_6 , T_1 V_129 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
int V_38 ;
T_1 V_23 ;
if ( ! V_129 )
return 0 ;
if ( ( V_129 >= 0x0b && V_129 <= 0x10 ) || V_129 == 0x1f || V_129 == 0x20 ) {
V_23 = F_374 ( V_6 , V_129 ) ;
if ( V_23 ) {
V_38 = F_378 ( V_6 , L_52 , V_23 , 3 ) ;
if ( V_38 < 0 )
return V_38 ;
V_8 -> V_40 . V_109 = V_23 ;
}
}
return 0 ;
}
static int F_380 ( struct V_5 * V_6 ,
const struct V_84 * V_85 )
{
return F_205 ( V_6 , V_85 , 0x15 , 0x08 , 0 ) ;
}
static void F_381 ( struct V_5 * V_6 ,
T_1 V_23 ,
int V_388 , T_1 V_472 )
{
T_1 V_95 , V_593 [ 5 ] ;
int V_28 , V_594 ;
F_32 ( V_6 , V_23 , 0 , V_58 ,
V_388 ) ;
F_32 ( V_6 , V_472 , 0 , V_389 ,
V_390 ) ;
if ( F_53 ( V_6 , V_23 , & V_95 , 1 ) != 1 )
return;
V_594 = F_53 ( V_6 , V_95 , V_593 , F_36 ( V_593 ) ) ;
if ( V_594 < 0 )
return;
for ( V_28 = 0 ; V_28 < V_594 ; V_28 ++ ) {
unsigned int V_137 ;
if ( V_593 [ V_28 ] == V_472 || V_593 [ V_28 ] == 0x15 )
V_137 = F_289 ( V_28 ) ;
else
V_137 = F_288 ( V_28 ) ;
F_32 ( V_6 , V_95 , 0 , V_389 ,
V_137 ) ;
}
}
static void F_382 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
int V_28 ;
for ( V_28 = 0 ; V_28 < V_8 -> V_86 . V_87 ; V_28 ++ ) {
T_1 V_23 = V_8 -> V_86 . V_89 [ V_28 ] ;
int V_388 = F_213 ( V_8 -> V_86 . V_368 ) ;
if ( V_23 )
F_381 ( V_6 , V_23 , V_388 ,
V_8 -> V_40 . V_106 [ V_28 ] ) ;
}
}
static void F_383 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
if ( V_8 -> V_86 . V_92 )
F_381 ( V_6 ,
V_8 -> V_86 . V_93 [ 0 ] ,
V_141 ,
V_8 -> V_40 . V_109 ) ;
if ( V_8 -> V_86 . V_90 )
F_381 ( V_6 ,
V_8 -> V_86 . V_91 [ 0 ] ,
V_142 ,
V_8 -> V_40 . V_106 [ 0 ] ) ;
}
static void F_384 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
struct V_84 * V_85 = & V_8 -> V_86 ;
int V_28 ;
for ( V_28 = 0 ; V_28 < V_85 -> V_202 ; V_28 ++ ) {
T_1 V_23 = V_85 -> V_203 [ V_28 ] . V_129 ;
if ( V_23 >= 0x0c && V_23 <= 0x11 )
F_30 ( V_6 , V_23 , V_85 -> V_203 [ V_28 ] . type ) ;
}
}
static int F_385 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
int V_38 ;
static const T_1 V_597 [] = { 0x1d , 0 } ;
V_38 = F_219 ( V_6 , & V_8 -> V_86 ,
V_597 ) ;
if ( V_38 < 0 )
return V_38 ;
if ( ! V_8 -> V_86 . V_87 )
return 0 ;
V_38 = F_375 ( V_6 , & V_8 -> V_86 ) ;
if ( V_38 < 0 )
return V_38 ;
V_38 = F_220 ( V_6 ) ;
if ( V_38 < 0 )
return V_38 ;
V_38 = F_377 ( V_6 , & V_8 -> V_86 ) ;
if ( V_38 < 0 )
return V_38 ;
V_38 = F_379 ( V_6 , V_8 -> V_86 . V_93 [ 0 ] ) ;
if ( V_38 < 0 )
return V_38 ;
V_38 = F_380 ( V_6 , & V_8 -> V_86 ) ;
if ( V_38 < 0 )
return V_38 ;
V_8 -> V_40 . V_41 = V_8 -> V_40 . V_43 * 2 ;
F_94 ( V_6 ) ;
if ( V_8 -> V_338 . V_339 )
F_34 ( V_8 , V_8 -> V_338 . V_339 ) ;
F_37 ( V_8 , V_598 ) ;
V_8 -> V_11 = 1 ;
V_8 -> V_12 = & V_8 -> V_384 [ 0 ] ;
V_8 -> V_25 = V_599 ;
V_8 -> V_110 = F_36 ( V_599 ) ;
F_227 ( V_6 ) ;
F_84 ( V_6 , 0x0e , 0x0f , 0x0b , 0 ) ;
return 1 ;
}
static void F_386 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
F_382 ( V_6 ) ;
F_383 ( V_6 ) ;
F_384 ( V_6 ) ;
F_93 ( V_6 ) ;
if ( V_8 -> V_112 )
F_59 ( V_6 ) ;
}
static int F_387 ( struct V_5 * V_6 )
{
struct V_7 * V_8 ;
int V_421 ;
int V_38 ;
V_8 = F_231 ( sizeof( * V_8 ) , V_196 ) ;
if ( V_8 == NULL )
return - V_194 ;
V_6 -> V_8 = V_8 ;
V_421 = F_232 ( V_6 , V_600 ,
V_601 ,
V_602 ) ;
if ( V_421 < 0 ) {
F_81 ( V_221 L_59 ,
V_6 -> V_222 ) ;
V_421 = V_603 ;
}
if ( V_421 == V_603 ) {
F_89 ( V_6 , NULL , V_604 , V_605 ) ;
F_85 ( V_6 , V_245 ) ;
}
if ( V_421 == V_603 ) {
V_38 = F_385 ( V_6 ) ;
if ( V_38 < 0 ) {
F_169 ( V_6 ) ;
return V_38 ;
} else if ( ! V_38 ) {
F_81 ( V_221
L_60
L_62 ) ;
V_421 = V_606 ;
}
}
V_38 = F_233 ( V_6 , 0x23 ) ;
if ( V_38 < 0 ) {
F_169 ( V_6 ) ;
return V_38 ;
}
if ( V_421 != V_603 )
F_38 ( V_6 , & V_607 [ V_421 ] ) ;
V_8 -> V_320 = & V_608 ;
V_8 -> V_323 = & V_609 ;
V_8 -> V_329 = & V_610 ;
V_8 -> V_330 = & V_611 ;
if ( ! V_8 -> V_104 )
F_227 ( V_6 ) ;
F_234 ( V_8 , 0x23 , 0 , V_59 ) ;
V_8 -> V_290 = 0x03 ;
F_85 ( V_6 , V_249 ) ;
V_6 -> V_342 = V_436 ;
if ( V_421 == V_603 ) {
V_8 -> V_113 = F_386 ;
#ifdef F_39
V_8 -> V_114 = F_172 ;
#endif
}
#ifdef F_39
if ( ! V_8 -> V_115 . V_116 )
V_8 -> V_115 . V_116 = V_612 ;
#endif
return 0 ;
}
static void F_388 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
V_8 -> V_86 . V_93 [ 0 ] = 0x1b ;
V_8 -> V_86 . V_91 [ 0 ] = 0x14 ;
V_8 -> V_150 = 1 ;
V_8 -> V_143 = V_145 ;
}
static void F_389 ( struct V_5 * V_6 )
{
F_50 ( V_6 ) ;
F_127 ( V_6 ) ;
}
static void F_390 ( struct V_5 * V_6 ,
unsigned int V_173 )
{
switch ( V_173 >> 26 ) {
case V_177 :
F_127 ( V_6 ) ;
break;
default:
F_58 ( V_6 , V_173 ) ;
break;
}
}
static void F_391 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
V_8 -> V_86 . V_93 [ 0 ] = 0x15 ;
V_8 -> V_86 . V_91 [ 0 ] = 0x14 ;
V_8 -> V_150 = 1 ;
V_8 -> V_143 = V_145 ;
}
static int F_392 ( struct V_5 * V_6 ,
const struct V_84 * V_85 )
{
return F_205 ( V_6 , V_85 , 0x0b , 0x22 , 0 ) ;
}
static void F_393 ( struct V_5 * V_6 ,
T_1 V_23 , int V_388 , int V_391 )
{
F_209 ( V_6 , V_23 , V_388 ) ;
}
static void F_394 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
int V_28 ;
for ( V_28 = 0 ; V_28 <= V_473 ; V_28 ++ ) {
T_1 V_23 = V_8 -> V_86 . V_89 [ V_28 ] ;
int V_388 = F_213 ( V_8 -> V_86 . V_368 ) ;
if ( V_23 )
F_393 ( V_6 , V_23 ,
V_388 , V_28 ) ;
}
}
static void F_395 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
T_1 V_129 ;
V_129 = V_8 -> V_86 . V_93 [ 0 ] ;
if ( V_129 )
F_393 ( V_6 , V_129 , V_141 , 0 ) ;
V_129 = V_8 -> V_86 . V_91 [ 0 ] ;
if ( V_129 )
F_393 ( V_6 , V_129 , V_142 , 0 ) ;
}
static void F_396 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
struct V_84 * V_85 = & V_8 -> V_86 ;
int V_28 ;
for ( V_28 = 0 ; V_28 < V_85 -> V_202 ; V_28 ++ ) {
T_1 V_23 = V_85 -> V_203 [ V_28 ] . V_129 ;
if ( F_204 ( V_6 , V_23 ) ) {
F_30 ( V_6 , V_23 , V_85 -> V_203 [ V_28 ] . type ) ;
if ( V_23 != V_613 &&
( F_8 ( V_6 , V_23 ) & V_393 ) )
F_32 ( V_6 , V_23 , 0 ,
V_389 ,
V_394 ) ;
}
}
}
static int F_397 ( struct V_7 * V_8 ,
const struct V_84 * V_85 )
{
static const char * const V_371 [ 4 ] = {
L_45 , L_46 , L_47 , L_48
} ;
const char * V_362 = F_193 ( V_8 , true ) ;
T_1 V_614 , V_615 ;
int V_28 , V_38 , V_372 ;
V_372 = V_85 -> V_87 ;
if ( V_8 -> V_367 > 0 )
V_372 += V_8 -> V_367 ;
for ( V_28 = 0 ; V_28 < V_372 ; V_28 ++ ) {
if ( ! V_8 -> V_40 . V_106 [ V_28 ] )
continue;
V_614 = F_398 (
F_196 (
V_8 -> V_40 . V_106 [ V_28 ] ) ) ;
V_615 = F_399 (
F_196 (
V_8 -> V_40 . V_106 [ V_28 ] ) ) ;
if ( ! V_362 && V_28 == 2 ) {
V_38 = F_197 ( V_8 , V_373 ,
L_54 ,
F_104 ( V_614 , 1 , 0 ,
V_59 ) ) ;
if ( V_38 < 0 )
return V_38 ;
V_38 = F_197 ( V_8 , V_373 ,
L_55 ,
F_104 ( V_614 , 2 , 0 ,
V_59 ) ) ;
if ( V_38 < 0 )
return V_38 ;
V_38 = F_198 ( V_8 , V_374 ,
L_54 ,
F_104 ( V_615 , 1 , 2 ,
V_32 ) ) ;
if ( V_38 < 0 )
return V_38 ;
V_38 = F_198 ( V_8 , V_374 ,
L_55 ,
F_104 ( V_615 , 2 , 2 ,
V_32 ) ) ;
if ( V_38 < 0 )
return V_38 ;
} else {
const char * V_50 = V_362 ;
int V_34 = V_28 ;
if ( ! V_50 ) {
V_50 = V_371 [ V_28 ] ;
V_34 = 0 ;
}
V_38 = F_199 ( V_8 , V_373 ,
V_50 , V_34 ,
F_104 ( V_614 , 3 , 0 ,
V_59 ) ) ;
if ( V_38 < 0 )
return V_38 ;
V_38 = F_200 ( V_8 , V_374 ,
V_50 , V_34 ,
F_104 ( V_615 , 3 , 2 ,
V_32 ) ) ;
if ( V_38 < 0 )
return V_38 ;
}
}
return 0 ;
}
static int F_400 ( struct V_7 * V_8 ,
T_1 V_129 , const char * V_362 )
{
T_1 V_614 , V_615 ;
int V_38 ;
if ( ! V_129 )
return 0 ;
if ( F_190 ( V_129 ) ) {
V_614 = F_192 ( F_191 ( V_129 ) ) ;
if ( ! V_8 -> V_40 . V_109 )
V_8 -> V_40 . V_109 = V_614 ;
else
V_8 -> V_40 . V_375 [ 0 ] = V_614 ;
V_614 = F_398 (
F_191 ( V_129 ) ) ;
V_615 = F_399 (
F_191 ( V_129 ) ) ;
V_38 = F_197 ( V_8 , V_373 , V_362 ,
F_104 ( V_614 , 3 , 0 , V_59 ) ) ;
if ( V_38 < 0 )
return V_38 ;
V_38 = F_198 ( V_8 , V_374 , V_362 ,
F_104 ( V_615 , 3 , 2 , V_32 ) ) ;
if ( V_38 < 0 )
return V_38 ;
} else if ( F_202 ( V_129 ) ) {
V_38 = F_198 ( V_8 , V_376 , V_362 ,
F_104 ( V_129 , 3 , 0 , V_59 ) ) ;
if ( V_38 < 0 )
return V_38 ;
}
return 0 ;
}
static int F_401 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
int V_38 ;
static const T_1 V_616 [] = { 0x1d , 0 } ;
V_38 = F_219 ( V_6 , & V_8 -> V_86 ,
V_616 ) ;
if ( V_38 < 0 )
return V_38 ;
if ( ! V_8 -> V_86 . V_87 )
return 0 ;
V_38 = F_189 ( V_8 , & V_8 -> V_86 ) ;
if ( V_38 < 0 )
return V_38 ;
V_38 = F_220 ( V_6 ) ;
if ( V_38 < 0 )
return V_38 ;
V_38 = F_397 ( V_8 , & V_8 -> V_86 ) ;
if ( V_38 < 0 )
return V_38 ;
V_38 = F_400 ( V_8 ,
V_8 -> V_86 . V_91 [ 0 ] ,
L_51 ) ;
if ( V_38 < 0 )
return V_38 ;
V_38 = F_400 ( V_8 ,
V_8 -> V_86 . V_93 [ 0 ] ,
L_52 ) ;
if ( V_38 < 0 )
return V_38 ;
V_38 = F_392 ( V_6 , & V_8 -> V_86 ) ;
if ( V_38 < 0 )
return V_38 ;
V_8 -> V_40 . V_41 = V_8 -> V_40 . V_43 * 2 ;
F_94 ( V_6 ) ;
if ( V_8 -> V_338 . V_339 )
F_34 ( V_8 , V_8 -> V_338 . V_339 ) ;
F_37 ( V_8 , V_617 ) ;
V_8 -> V_11 = 1 ;
V_8 -> V_12 = & V_8 -> V_384 [ 0 ] ;
V_38 = F_290 ( V_6 ) ;
if ( V_38 < 0 )
return V_38 ;
F_84 ( V_6 , 0x15 , 0x1b , 0x14 , 0 ) ;
return 1 ;
}
static void F_402 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
F_394 ( V_6 ) ;
F_395 ( V_6 ) ;
F_396 ( V_6 ) ;
F_403 ( V_6 ) ;
F_93 ( V_6 ) ;
if ( V_8 -> V_112 )
F_59 ( V_6 ) ;
}
static int F_404 ( struct V_5 * V_6 )
{
struct V_7 * V_8 ;
int V_38 , V_421 ;
V_8 = F_231 ( sizeof( * V_8 ) , V_196 ) ;
if ( V_8 == NULL )
return - V_194 ;
V_6 -> V_8 = V_8 ;
V_421 = F_232 ( V_6 , V_618 ,
V_619 ,
V_620 ) ;
if ( V_421 < 0 || V_421 >= V_618 ) {
F_81 ( V_221 L_59 ,
V_6 -> V_222 ) ;
V_421 = V_621 ;
}
if ( V_421 == V_621 ) {
F_89 ( V_6 , NULL , V_622 , V_623 ) ;
F_85 ( V_6 , V_245 ) ;
}
if ( V_421 == V_621 ) {
V_38 = F_401 ( V_6 ) ;
if ( V_38 < 0 ) {
F_169 ( V_6 ) ;
return V_38 ;
} else if ( ! V_38 ) {
F_81 ( V_221
L_60
L_62 ) ;
V_421 = V_624 ;
}
}
V_38 = F_233 ( V_6 , 0x23 ) ;
if ( V_38 < 0 ) {
F_169 ( V_6 ) ;
return V_38 ;
}
if ( V_421 != V_621 )
F_38 ( V_6 , & V_625 [ V_421 ] ) ;
if ( V_6 -> V_174 == 0x10ec0660 ) {
F_37 ( V_8 , V_626 ) ;
}
V_8 -> V_320 = & V_627 ;
V_8 -> V_323 = & V_628 ;
V_8 -> V_329 = & V_629 ;
V_8 -> V_330 = & V_630 ;
if ( ! V_8 -> V_25 ) {
V_8 -> V_25 = V_631 ;
V_8 -> V_110 = F_36 ( V_631 ) ;
}
if ( ! V_8 -> V_24 )
V_8 -> V_24 = V_632 ;
F_227 ( V_6 ) ;
F_234 ( V_8 , 0x0b , 0x05 , V_32 ) ;
V_8 -> V_290 = 0x02 ;
F_85 ( V_6 , V_249 ) ;
V_6 -> V_342 = V_436 ;
if ( V_421 == V_621 )
V_8 -> V_113 = F_402 ;
V_8 -> V_337 = F_64 ;
#ifdef F_39
if ( ! V_8 -> V_115 . V_116 )
V_8 -> V_115 . V_116 = V_633 ;
#endif
return 0 ;
}
static void F_405 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
V_8 -> V_86 . V_93 [ 0 ] = 0x1b ;
V_8 -> V_86 . V_89 [ 0 ] = 0x14 ;
V_8 -> V_86 . V_91 [ 0 ] = 0x15 ;
V_8 -> V_150 = 1 ;
V_8 -> V_154 = 1 ;
V_8 -> V_153 = 1 ;
V_8 -> V_143 = V_145 ;
}
static void F_406 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
F_299 ( V_6 ) ;
V_8 -> V_128 . V_129 = 0x18 ;
V_8 -> V_128 . V_9 = 0 ;
V_8 -> V_170 . V_129 = 0x19 ;
V_8 -> V_170 . V_9 = 1 ;
V_8 -> V_169 = 1 ;
}
static void F_407 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
V_8 -> V_86 . V_93 [ 0 ] = 0x14 ;
V_8 -> V_86 . V_91 [ 0 ] = 0x1b ;
V_8 -> V_150 = 1 ;
V_8 -> V_143 = V_145 ;
}
static void F_408 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
V_8 -> V_86 . V_93 [ 0 ] = 0x21 ;
V_8 -> V_86 . V_91 [ 0 ] = 0x14 ;
V_8 -> V_147 [ 0 ] = 0x0c ;
V_8 -> V_150 = 1 ;
V_8 -> V_143 = V_146 ;
V_8 -> V_128 . V_129 = 0x18 ;
V_8 -> V_128 . V_9 = 0 ;
V_8 -> V_170 . V_129 = 0x12 ;
V_8 -> V_170 . V_9 = 9 ;
V_8 -> V_169 = 1 ;
}
static void F_409 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
V_8 -> V_86 . V_93 [ 0 ] = 0x21 ;
V_8 -> V_86 . V_91 [ 0 ] = 0x14 ;
V_8 -> V_147 [ 0 ] = 0x0c ;
V_8 -> V_150 = 1 ;
V_8 -> V_143 = V_146 ;
V_8 -> V_128 . V_129 = 0x18 ;
V_8 -> V_128 . V_9 = 0 ;
V_8 -> V_170 . V_129 = 0x19 ;
V_8 -> V_170 . V_9 = 1 ;
V_8 -> V_169 = 1 ;
}
static void F_410 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
V_8 -> V_86 . V_93 [ 0 ] = 0x1b ;
V_8 -> V_86 . V_91 [ 0 ] = 0x14 ;
V_8 -> V_150 = 1 ;
V_8 -> V_143 = V_144 ;
V_8 -> V_128 . V_129 = 0x18 ;
V_8 -> V_128 . V_9 = 0 ;
V_8 -> V_170 . V_129 = 0x19 ;
V_8 -> V_170 . V_9 = 1 ;
V_8 -> V_169 = 1 ;
}
static void F_411 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
V_8 -> V_86 . V_93 [ 0 ] = 0x21 ;
V_8 -> V_86 . V_93 [ 0 ] = 0x15 ;
V_8 -> V_86 . V_91 [ 0 ] = 0x14 ;
V_8 -> V_150 = 1 ;
V_8 -> V_143 = V_144 ;
V_8 -> V_128 . V_129 = 0x18 ;
V_8 -> V_128 . V_9 = 0 ;
V_8 -> V_170 . V_129 = 0x19 ;
V_8 -> V_170 . V_9 = 1 ;
V_8 -> V_169 = 1 ;
}
static void F_412 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
V_8 -> V_86 . V_93 [ 0 ] = 0x21 ;
V_8 -> V_86 . V_91 [ 0 ] = 0x14 ;
V_8 -> V_86 . V_91 [ 1 ] = 0x16 ;
V_8 -> V_147 [ 0 ] = 0x0c ;
V_8 -> V_147 [ 1 ] = 0x0e ;
V_8 -> V_150 = 1 ;
V_8 -> V_143 = V_146 ;
V_8 -> V_128 . V_129 = 0x18 ;
V_8 -> V_128 . V_9 = 0 ;
V_8 -> V_170 . V_129 = 0x19 ;
V_8 -> V_170 . V_9 = 1 ;
V_8 -> V_169 = 1 ;
}
static void F_413 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
V_8 -> V_86 . V_93 [ 0 ] = 0x15 ;
V_8 -> V_86 . V_91 [ 0 ] = 0x14 ;
V_8 -> V_86 . V_91 [ 1 ] = 0x16 ;
V_8 -> V_147 [ 0 ] = 0x0c ;
V_8 -> V_147 [ 1 ] = 0x0e ;
V_8 -> V_150 = 1 ;
V_8 -> V_143 = V_146 ;
V_8 -> V_128 . V_129 = 0x18 ;
V_8 -> V_128 . V_9 = 0 ;
V_8 -> V_170 . V_129 = 0x19 ;
V_8 -> V_170 . V_9 = 1 ;
V_8 -> V_169 = 1 ;
}
static void F_414 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
V_8 -> V_86 . V_93 [ 0 ] = 0x1b ;
V_8 -> V_86 . V_93 [ 0 ] = 0x15 ;
V_8 -> V_86 . V_91 [ 0 ] = 0x14 ;
V_8 -> V_147 [ 0 ] = 0x0c ;
V_8 -> V_150 = 1 ;
V_8 -> V_143 = V_146 ;
V_8 -> V_128 . V_129 = 0x18 ;
V_8 -> V_128 . V_9 = 0 ;
V_8 -> V_170 . V_129 = 0x19 ;
V_8 -> V_170 . V_9 = 1 ;
V_8 -> V_169 = 1 ;
}
static void F_415 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
V_8 -> V_86 . V_93 [ 0 ] = 0x1b ;
V_8 -> V_86 . V_93 [ 0 ] = 0x21 ;
V_8 -> V_86 . V_91 [ 0 ] = 0x14 ;
V_8 -> V_86 . V_91 [ 0 ] = 0x17 ;
V_8 -> V_150 = 1 ;
V_8 -> V_143 = V_144 ;
V_8 -> V_128 . V_129 = 0x18 ;
V_8 -> V_128 . V_9 = 0 ;
V_8 -> V_170 . V_129 = 0x19 ;
V_8 -> V_170 . V_9 = 1 ;
V_8 -> V_169 = 1 ;
}
static void F_416 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
V_8 -> V_86 . V_93 [ 0 ] = 0x21 ;
V_8 -> V_86 . V_93 [ 1 ] = 0x15 ;
V_8 -> V_86 . V_91 [ 0 ] = 0x14 ;
V_8 -> V_86 . V_91 [ 0 ] = 0x17 ;
V_8 -> V_150 = 1 ;
V_8 -> V_143 = V_144 ;
V_8 -> V_128 . V_129 = 0x18 ;
V_8 -> V_128 . V_9 = 0 ;
V_8 -> V_170 . V_129 = 0x12 ;
V_8 -> V_170 . V_9 = 9 ;
V_8 -> V_169 = 1 ;
}
static void F_417 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
V_8 -> V_86 . V_93 [ 0 ] = 0x21 ;
V_8 -> V_86 . V_89 [ 0 ] = 0x15 ;
V_8 -> V_86 . V_91 [ 0 ] = 0x14 ;
V_8 -> V_150 = 1 ;
V_8 -> V_143 = V_145 ;
V_8 -> V_154 = 1 ;
V_8 -> V_153 = 1 ;
V_8 -> V_128 . V_129 = 0x18 ;
V_8 -> V_128 . V_9 = 0 ;
V_8 -> V_170 . V_129 = 0x12 ;
V_8 -> V_170 . V_9 = 9 ;
V_8 -> V_169 = 1 ;
}
static T_1 F_418 ( struct V_5 * V_6 , T_1 V_23 )
{
T_1 V_339 [ 5 ] ;
int V_28 , V_594 ;
V_594 = F_53 ( V_6 , V_23 , V_339 , F_36 ( V_339 ) ) ;
for ( V_28 = 0 ; V_28 < V_594 ; V_28 ++ ) {
if ( F_7 ( F_8 ( V_6 , V_339 [ V_28 ] ) ) == V_595 )
return V_339 [ V_28 ] ;
}
return 0 ;
}
static T_1 F_419 ( struct V_5 * V_6 , T_1 V_129 )
{
T_1 V_593 [ 5 ] ;
int V_594 = F_53 ( V_6 , V_129 , V_593 ,
F_36 ( V_593 ) ) ;
if ( V_594 != 1 ||
F_7 ( F_8 ( V_6 , V_593 [ 0 ] ) ) != V_634 )
return V_129 ;
return V_593 [ 0 ] ;
}
static T_1 F_420 ( struct V_5 * V_6 , T_1 V_129 ,
T_1 V_472 )
{
T_1 V_95 [ 5 ] ;
int V_28 , V_594 ;
V_129 = F_419 ( V_6 , V_129 ) ;
V_594 = F_53 ( V_6 , V_129 , V_95 , F_36 ( V_95 ) ) ;
for ( V_28 = 0 ; V_28 < V_594 ; V_28 ++ ) {
if ( F_418 ( V_6 , V_95 [ V_28 ] ) == V_472 )
return V_95 [ V_28 ] ;
}
return 0 ;
}
static int F_421 ( struct V_5 * V_6 , T_1 V_129 ,
T_1 V_472 )
{
T_1 V_95 [ 5 ] ;
int V_28 , V_594 ;
V_129 = F_419 ( V_6 , V_129 ) ;
V_594 = F_53 ( V_6 , V_129 , V_95 , F_36 ( V_95 ) ) ;
if ( V_594 < 2 )
return 0 ;
for ( V_28 = 0 ; V_28 < V_594 ; V_28 ++ ) {
if ( F_418 ( V_6 , V_95 [ V_28 ] ) == V_472 ) {
F_353 ( V_6 , V_129 , 0 ,
V_172 , V_28 ) ;
return 0 ;
}
}
return 0 ;
}
static T_1 F_422 ( struct V_5 * V_6 , T_1 V_129 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
T_1 V_593 [ 5 ] ;
int V_28 , V_283 , V_594 ;
V_129 = F_419 ( V_6 , V_129 ) ;
V_594 = F_53 ( V_6 , V_129 , V_593 , F_36 ( V_593 ) ) ;
for ( V_28 = 0 ; V_28 < V_594 ; V_28 ++ ) {
T_1 V_23 = F_418 ( V_6 , V_593 [ V_28 ] ) ;
if ( ! V_23 )
continue;
for ( V_283 = 0 ; V_283 < V_8 -> V_40 . V_43 ; V_283 ++ )
if ( V_8 -> V_40 . V_106 [ V_283 ] == V_23 )
break;
if ( V_283 >= V_8 -> V_40 . V_43 )
return V_23 ;
}
return 0 ;
}
static int F_423 ( struct V_5 * V_6 ,
const struct V_84 * V_85 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
int V_28 ;
T_1 V_472 ;
V_8 -> V_40 . V_106 = V_8 -> V_365 ;
for ( V_28 = 0 ; V_28 < V_85 -> V_87 ; V_28 ++ ) {
V_472 = F_422 ( V_6 , V_85 -> V_89 [ V_28 ] ) ;
if ( ! V_472 )
continue;
V_8 -> V_365 [ V_8 -> V_40 . V_43 ++ ] = V_472 ;
}
return 0 ;
}
static inline int F_424 ( struct V_7 * V_8 , const char * V_362 ,
T_1 V_23 , int V_29 , unsigned int V_596 )
{
return F_199 ( V_8 , V_373 , V_362 , V_29 ,
F_104 ( V_23 , V_596 , 0 , V_59 ) ) ;
}
static inline int F_425 ( struct V_7 * V_8 , const char * V_362 ,
T_1 V_23 , int V_29 , unsigned int V_596 )
{
return F_200 ( V_8 , V_376 , V_362 , V_29 ,
F_104 ( V_23 , V_596 , 0 , V_32 ) ) ;
}
static int F_426 ( struct V_5 * V_6 ,
const struct V_84 * V_85 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
static const char * const V_371 [ 4 ] = {
L_45 , L_46 , NULL , L_48
} ;
const char * V_362 = F_193 ( V_8 , true ) ;
T_1 V_23 , V_95 , V_129 ;
int V_28 , V_38 , V_372 ;
V_372 = V_85 -> V_87 ;
if ( V_8 -> V_367 > 0 )
V_372 += V_8 -> V_367 ;
for ( V_28 = 0 ; V_28 < V_372 ; V_28 ++ ) {
V_23 = V_8 -> V_40 . V_106 [ V_28 ] ;
if ( ! V_23 )
continue;
if ( V_28 >= V_85 -> V_87 )
V_129 = V_8 -> V_635 [ V_28 - 1 ] . V_129 ;
else
V_129 = V_85 -> V_89 [ V_28 ] ;
V_95 = F_420 ( V_6 , V_129 , V_23 ) ;
if ( ! V_95 )
continue;
if ( ! V_362 && V_28 == 2 ) {
V_38 = F_427 ( V_8 , L_54 , V_23 , 1 ) ;
if ( V_38 < 0 )
return V_38 ;
V_38 = F_427 ( V_8 , L_55 , V_23 , 2 ) ;
if ( V_38 < 0 )
return V_38 ;
V_38 = F_428 ( V_8 , L_54 , V_95 , 1 ) ;
if ( V_38 < 0 )
return V_38 ;
V_38 = F_428 ( V_8 , L_55 , V_95 , 2 ) ;
if ( V_38 < 0 )
return V_38 ;
} else {
const char * V_50 = V_362 ;
int V_34 = V_28 ;
if ( ! V_50 ) {
V_50 = V_371 [ V_28 ] ;
V_34 = 0 ;
}
V_38 = F_424 ( V_8 , V_50 , V_23 , V_34 , 3 ) ;
if ( V_38 < 0 )
return V_38 ;
V_38 = F_425 ( V_8 , V_50 , V_95 , V_34 , 3 ) ;
if ( V_38 < 0 )
return V_38 ;
}
}
return 0 ;
}
static int F_429 ( struct V_5 * V_6 , T_1 V_129 ,
const char * V_362 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
T_1 V_23 , V_95 ;
int V_38 ;
if ( ! V_129 )
return 0 ;
V_23 = F_422 ( V_6 , V_129 ) ;
if ( ! V_23 ) {
if ( ! ( F_8 ( V_6 , V_129 ) & V_393 ) )
return 0 ;
return F_198 ( V_8 , V_376 , V_362 ,
F_104 ( V_129 , 3 , 0 , V_59 ) ) ;
}
V_95 = F_420 ( V_6 , V_129 , V_23 ) ;
if ( ! V_95 )
return 0 ;
V_38 = F_427 ( V_8 , V_362 , V_23 , 3 ) ;
if ( V_38 < 0 )
return V_38 ;
V_38 = F_428 ( V_8 , V_362 , V_95 , 3 ) ;
if ( V_38 < 0 )
return V_38 ;
return V_23 ;
}
static void F_430 ( struct V_5 * V_6 ,
T_1 V_23 , int V_388 ,
T_1 V_472 )
{
int V_28 , V_594 ;
T_1 V_593 [ V_636 ] ;
F_209 ( V_6 , V_23 , V_388 ) ;
V_594 = F_53 ( V_6 , V_23 , V_593 , F_36 ( V_593 ) ) ;
for ( V_28 = 0 ; V_28 < V_594 ; V_28 ++ ) {
if ( F_418 ( V_6 , V_593 [ V_28 ] ) != V_472 )
continue;
if ( V_594 > 1 )
F_32 ( V_6 , V_23 , 0 ,
V_172 , V_28 ) ;
F_32 ( V_6 , V_593 [ V_28 ] , 0 ,
V_389 ,
F_289 ( 0 ) ) ;
F_32 ( V_6 , V_593 [ V_28 ] , 0 ,
V_389 ,
F_289 ( 1 ) ) ;
return;
}
}
static void F_431 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
int V_388 = F_213 ( V_8 -> V_86 . V_368 ) ;
int V_28 ;
for ( V_28 = 0 ; V_28 <= V_473 ; V_28 ++ ) {
T_1 V_23 = V_8 -> V_86 . V_89 [ V_28 ] ;
if ( V_23 )
F_430 ( V_6 , V_23 , V_388 ,
V_8 -> V_40 . V_106 [ V_28 ] ) ;
}
}
static void F_432 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
T_1 V_129 ;
V_129 = V_8 -> V_86 . V_93 [ 0 ] ;
if ( V_129 )
F_430 ( V_6 , V_129 , V_141 ,
V_8 -> V_40 . V_109 ) ;
V_129 = V_8 -> V_86 . V_91 [ 0 ] ;
if ( V_129 )
F_430 ( V_6 , V_129 , V_142 ,
V_8 -> V_40 . V_375 [ 0 ] ) ;
}
static void F_433 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
struct V_84 * V_85 = & V_8 -> V_86 ;
int V_28 ;
for ( V_28 = 0 ; V_28 < V_85 -> V_202 ; V_28 ++ ) {
T_1 V_23 = V_85 -> V_203 [ V_28 ] . V_129 ;
if ( F_204 ( V_6 , V_23 ) ) {
F_30 ( V_6 , V_23 , V_85 -> V_203 [ V_28 ] . type ) ;
if ( V_23 != V_637 &&
( F_8 ( V_6 , V_23 ) & V_393 ) )
F_32 ( V_6 , V_23 , 0 ,
V_389 ,
V_394 ) ;
}
}
}
static int F_434 ( struct V_5 * V_6 ,
unsigned int V_638 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
struct V_84 * V_85 = & V_8 -> V_86 ;
int type , V_28 , V_134 = 0 ;
for ( type = V_208 ; type >= V_71 ; type -- ) {
for ( V_28 = 0 ; V_28 < V_85 -> V_202 ; V_28 ++ ) {
T_1 V_23 = V_85 -> V_203 [ V_28 ] . V_129 ;
T_1 V_472 ;
unsigned int V_204 , V_402 ;
if ( V_85 -> V_203 [ V_28 ] . type != type )
continue;
V_204 = F_78 ( V_6 , V_23 ) ;
if ( F_368 ( V_204 ) != V_639 )
continue;
if ( V_638 && F_435 ( V_204 ) != V_638 )
continue;
V_402 = F_31 ( V_6 , V_23 ) ;
if ( ! ( V_402 & V_640 ) )
continue;
V_472 = F_422 ( V_6 , V_23 ) ;
if ( ! V_472 )
continue;
V_8 -> V_635 [ V_134 ] . V_129 = V_23 ;
V_8 -> V_635 [ V_134 ] . V_472 = V_472 ;
V_134 ++ ;
V_8 -> V_365 [ V_8 -> V_40 . V_43 ++ ] = V_472 ;
}
}
V_8 -> V_40 . V_43 = 1 ;
if ( V_134 < 2 )
return 0 ;
return V_134 ;
}
static int F_436 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = V_6 -> V_8 ;
V_4 -> type = V_47 ;
V_4 -> V_48 = 1 ;
V_4 -> V_17 . V_18 . V_33 = V_8 -> V_367 + 1 ;
if ( V_4 -> V_17 . V_18 . V_19 > V_8 -> V_367 )
V_4 -> V_17 . V_18 . V_19 = V_8 -> V_367 ;
sprintf ( V_4 -> V_17 . V_18 . V_50 , L_72 ,
( V_4 -> V_17 . V_18 . V_19 + 1 ) * 2 ) ;
return 0 ;
}
static int F_437 ( struct V_1 * V_2 ,
struct V_14 * V_15 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = V_6 -> V_8 ;
V_15 -> V_17 . V_18 . V_19 [ 0 ] = ( V_8 -> V_37 - 1 ) / 2 ;
return 0 ;
}
static int F_438 ( struct V_5 * V_6 , int V_29 , bool V_641 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
T_1 V_23 = V_8 -> V_635 [ V_29 ] . V_129 ;
if ( ! V_8 -> V_635 [ V_29 ] . V_642 )
V_8 -> V_635 [ V_29 ] . V_642 =
F_21 ( V_6 , V_23 , 0 ,
V_54 , 0 ) ;
if ( V_641 ) {
F_353 ( V_6 , V_23 , 0 ,
V_58 ,
V_142 ) ;
if ( F_8 ( V_6 , V_23 ) & V_393 )
F_9 ( V_6 , V_23 , V_59 , 0 ,
V_31 , 0 ) ;
F_421 ( V_6 , V_23 , V_8 -> V_635 [ V_29 ] . V_472 ) ;
} else {
if ( F_8 ( V_6 , V_23 ) & V_393 )
F_9 ( V_6 , V_23 , V_59 , 0 ,
V_31 , V_31 ) ;
F_353 ( V_6 , V_23 , 0 ,
V_58 ,
V_8 -> V_635 [ V_29 ] . V_642 ) ;
}
return 0 ;
}
static int F_439 ( struct V_1 * V_2 ,
struct V_14 * V_15 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = V_6 -> V_8 ;
int V_28 , V_643 ;
V_643 = V_15 -> V_17 . V_18 . V_19 [ 0 ] ;
if ( V_643 < 0 || V_643 > V_8 -> V_367 )
return - V_192 ;
if ( V_643 == ( V_8 -> V_37 - 1 ) / 2 )
return 0 ;
V_8 -> V_37 = ( V_643 + 1 ) * 2 ;
for ( V_28 = 0 ; V_28 < V_8 -> V_367 ; V_28 ++ )
F_438 ( V_6 , V_28 , V_28 < V_643 ) ;
V_8 -> V_40 . V_41 = V_8 -> V_37 ;
return 1 ;
}
static int F_220 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
struct V_84 * V_85 = & V_8 -> V_86 ;
unsigned int V_638 , V_204 ;
int V_134 ;
if ( V_85 -> V_87 != 1 ||
V_85 -> V_368 != V_644 )
return 0 ;
V_204 = F_78 ( V_6 , V_85 -> V_89 [ 0 ] ) ;
V_638 = F_435 ( V_204 ) ;
V_134 = F_434 ( V_6 , V_638 ) ;
if ( V_134 > 0 ) {
struct V_94 * V_193 ;
V_193 = F_72 ( V_8 ) ;
if ( ! V_193 )
return - V_194 ;
* V_193 = V_645 ;
V_193 -> V_50 = F_73 ( L_73 , V_196 ) ;
if ( ! V_193 -> V_50 )
return - V_194 ;
V_8 -> V_367 = V_134 ;
V_8 -> V_37 = 2 ;
V_8 -> V_40 . V_43 = V_134 + 1 ;
}
return 0 ;
}
static int F_440 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
int V_38 ;
static const T_1 V_646 [] = { 0x1d , 0 } ;
V_38 = F_219 ( V_6 , & V_8 -> V_86 ,
V_646 ) ;
if ( V_38 < 0 )
return V_38 ;
if ( ! V_8 -> V_86 . V_87 )
return 0 ;
V_38 = F_423 ( V_6 , & V_8 -> V_86 ) ;
if ( V_38 < 0 )
return V_38 ;
V_38 = F_220 ( V_6 ) ;
if ( V_38 < 0 )
return V_38 ;
V_38 = F_426 ( V_6 , & V_8 -> V_86 ) ;
if ( V_38 < 0 )
return V_38 ;
V_38 = F_429 ( V_6 ,
V_8 -> V_86 . V_91 [ 0 ] ,
L_51 ) ;
if ( V_38 < 0 )
return V_38 ;
if ( V_38 )
V_8 -> V_40 . V_375 [ 0 ] = V_38 ;
V_38 = F_429 ( V_6 , V_8 -> V_86 . V_93 [ 0 ] ,
L_52 ) ;
if ( V_38 < 0 )
return V_38 ;
if ( V_38 )
V_8 -> V_40 . V_109 = V_38 ;
V_38 = F_441 ( V_6 , & V_8 -> V_86 ) ;
if ( V_38 < 0 )
return V_38 ;
V_8 -> V_40 . V_41 = V_8 -> V_40 . V_43 * 2 ;
F_94 ( V_6 ) ;
if ( V_8 -> V_338 . V_339 )
F_34 ( V_8 , V_8 -> V_338 . V_339 ) ;
V_8 -> V_11 = 1 ;
V_8 -> V_12 = & V_8 -> V_384 [ 0 ] ;
V_38 = F_290 ( V_6 ) ;
if ( V_38 < 0 )
return V_38 ;
if ( V_6 -> V_174 == 0x10ec0272 || V_6 -> V_174 == 0x10ec0663 ||
V_6 -> V_174 == 0x10ec0665 || V_6 -> V_174 == 0x10ec0670 )
F_84 ( V_6 , 0x15 , 0x1b , 0x14 , 0x21 ) ;
else
F_84 ( V_6 , 0x15 , 0x1b , 0x14 , 0 ) ;
return 1 ;
}
static void F_442 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
F_431 ( V_6 ) ;
F_432 ( V_6 ) ;
F_433 ( V_6 ) ;
F_443 ( V_6 ) ;
F_93 ( V_6 ) ;
if ( V_8 -> V_112 )
F_59 ( V_6 ) ;
}
static void F_444 ( struct V_5 * V_6 ,
const struct V_241 * V_242 , int V_235 )
{
if ( V_235 != V_249 )
return;
if ( F_336 ( V_6 , 0x2 , V_59 ,
( 0x3b << V_542 ) |
( 0x3b << V_543 ) |
( 0x03 << V_544 ) |
( 0 << V_545 ) ) )
F_81 ( V_418
L_74 ) ;
}
static int F_445 ( struct V_5 * V_6 )
{
struct V_7 * V_8 ;
int V_38 , V_421 ;
int V_562 ;
V_8 = F_231 ( sizeof( * V_8 ) , V_196 ) ;
if ( ! V_8 )
return - V_194 ;
V_6 -> V_8 = V_8 ;
F_80 ( V_6 ) ;
F_41 ( V_6 , 0x20 , 0x04 , 15 ) ;
V_562 = F_91 ( V_6 , 0 ) ;
if ( V_562 == 0x8020 || V_562 == 0x8011 )
F_177 ( V_6 , L_75 ) ;
else if ( V_562 & ( 1 << 14 ) &&
V_6 -> V_218 -> V_219 -> V_564 == 0x1025 &&
V_8 -> V_211 . V_227 == 1 )
F_177 ( V_6 , L_76 ) ;
else if ( V_562 == 0x4011 )
F_177 ( V_6 , L_77 ) ;
V_421 = F_232 ( V_6 , V_647 ,
V_648 ,
V_649 ) ;
if ( V_421 < 0 ) {
F_81 ( V_221 L_59 ,
V_6 -> V_222 ) ;
V_421 = V_650 ;
}
if ( V_421 == V_650 ) {
F_89 ( V_6 , V_651 ,
V_652 , V_653 ) ;
F_85 ( V_6 , V_245 ) ;
V_38 = F_440 ( V_6 ) ;
if ( V_38 < 0 ) {
F_169 ( V_6 ) ;
return V_38 ;
} else if ( ! V_38 ) {
F_81 ( V_221
L_60
L_62 ) ;
V_421 = V_654 ;
}
}
if ( F_229 ( V_6 ) ) {
V_38 = F_233 ( V_6 , 0x1 ) ;
if ( V_38 < 0 ) {
F_169 ( V_6 ) ;
return V_38 ;
}
}
if ( V_421 != V_650 )
F_38 ( V_6 , & V_655 [ V_421 ] ) ;
V_8 -> V_320 = & V_656 ;
V_8 -> V_323 = & V_657 ;
V_8 -> V_329 = & V_658 ;
V_8 -> V_330 = & V_659 ;
if ( ! V_8 -> V_25 ) {
V_8 -> V_25 = V_660 ;
V_8 -> V_110 = F_36 ( V_660 ) ;
}
if ( ! V_8 -> V_24 )
V_8 -> V_24 = V_661 ;
if ( ! V_8 -> V_104 )
F_227 ( V_6 ) ;
if ( F_229 ( V_6 ) ) {
switch ( V_6 -> V_174 ) {
case 0x10ec0662 :
F_234 ( V_8 , 0x0b , 0x05 , V_32 ) ;
break;
case 0x10ec0272 :
case 0x10ec0663 :
case 0x10ec0665 :
F_234 ( V_8 , 0x0b , 0x04 , V_32 ) ;
break;
case 0x10ec0273 :
F_234 ( V_8 , 0x0b , 0x03 , V_32 ) ;
break;
}
}
V_8 -> V_290 = 0x02 ;
F_85 ( V_6 , V_249 ) ;
V_6 -> V_342 = V_436 ;
if ( V_421 == V_650 )
V_8 -> V_113 = F_442 ;
V_8 -> V_337 = F_64 ;
F_42 ( V_6 ) ;
#ifdef F_39
if ( ! V_8 -> V_115 . V_116 )
V_8 -> V_115 . V_116 = V_662 ;
#endif
return 0 ;
}
static int F_446 ( struct V_5 * V_6 )
{
if ( ( F_91 ( V_6 , 0 ) & 0x00f0 ) == 0x0030 ) {
F_167 ( V_6 -> V_222 ) ;
if ( V_6 -> V_174 == 0x10ec0887 )
V_6 -> V_222 = F_73 ( L_78 , V_196 ) ;
else
V_6 -> V_222 = F_73 ( L_79 , V_196 ) ;
if ( ! V_6 -> V_222 ) {
F_169 ( V_6 ) ;
return - V_194 ;
}
return F_445 ( V_6 ) ;
}
return F_293 ( V_6 ) ;
}
static int F_447 ( struct V_5 * V_6 )
{
if ( ( F_91 ( V_6 , 0 ) & 0x2000 ) != 0x2000 ) {
F_167 ( V_6 -> V_222 ) ;
V_6 -> V_222 = F_73 ( L_80 , V_196 ) ;
}
return F_293 ( V_6 ) ;
}
static void F_448 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
struct V_84 * V_85 = & V_8 -> V_86 ;
int V_663 = 0 ;
int V_664 = V_665 ;
T_1 V_23 ;
int V_28 ;
for ( V_28 = 0 ; V_28 < V_85 -> V_202 ; V_28 ++ ) {
V_23 = V_85 -> V_203 [ V_28 ] . V_129 ;
if ( ! F_75 ( V_6 , V_23 ) )
continue;
if ( F_47 ( V_6 , V_23 ) ) {
if ( V_85 -> V_203 [ V_28 ] . type < V_664 ) {
V_664 = V_85 -> V_203 [ V_28 ] . type ;
V_663 = V_23 ;
}
}
}
V_23 = 0x07 ;
if ( V_663 )
F_53 ( V_6 , V_663 , & V_23 , 1 ) ;
if ( V_23 != V_8 -> V_161 )
F_55 ( V_6 , V_8 -> V_161 , 1 ) ;
V_8 -> V_161 = V_23 ;
F_56 ( V_6 , V_23 , V_8 -> V_162 , 0 ,
V_8 -> V_163 ) ;
}
static int F_449 ( struct V_306 * V_307 ,
struct V_5 * V_6 ,
unsigned int V_310 ,
unsigned int V_311 ,
struct V_308 * V_309 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
V_8 -> V_161 = 0x07 ;
V_8 -> V_162 = V_310 ;
V_8 -> V_163 = V_311 ;
F_448 ( V_6 ) ;
return 0 ;
}
static int F_450 ( struct V_306 * V_307 ,
struct V_5 * V_6 ,
struct V_308 * V_309 )
{
F_161 ( V_6 , 0x07 ) ;
F_161 ( V_6 , 0x08 ) ;
F_161 ( V_6 , 0x09 ) ;
return 0 ;
}
static void F_451 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
V_8 -> V_86 . V_93 [ 0 ] = 0x16 ;
V_8 -> V_86 . V_91 [ 0 ] = 0x14 ;
V_8 -> V_86 . V_91 [ 1 ] = 0x15 ;
V_8 -> V_86 . V_202 = 2 ;
V_8 -> V_86 . V_203 [ 0 ] . V_129 = 0x18 ;
V_8 -> V_86 . V_203 [ 0 ] . type = V_71 ;
V_8 -> V_86 . V_203 [ 1 ] . V_129 = 0x19 ;
V_8 -> V_86 . V_203 [ 1 ] . type = V_208 ;
V_8 -> V_150 = 1 ;
V_8 -> V_143 = V_145 ;
}
static void F_452 ( struct V_5 * V_6 ,
unsigned int V_173 )
{
if ( ( V_173 >> 26 ) == V_175 )
F_50 ( V_6 ) ;
if ( ( V_173 >> 26 ) == V_177 )
F_448 ( V_6 ) ;
}
static void F_453 ( struct V_5 * V_6 )
{
F_50 ( V_6 ) ;
F_448 ( V_6 ) ;
}
static int F_454 ( struct V_7 * V_8 , T_1 V_23 ,
const char * V_377 , int V_29 )
{
T_1 V_472 ;
int V_38 ;
switch ( V_23 ) {
case 0x14 :
V_472 = 0x02 ;
break;
case 0x15 :
V_472 = 0x03 ;
break;
case 0x16 :
V_472 = 0x04 ;
break;
default:
return 0 ;
}
if ( V_8 -> V_40 . V_106 [ 0 ] != V_472 &&
V_8 -> V_40 . V_106 [ 1 ] != V_472 ) {
V_38 = F_197 ( V_8 , V_373 , V_377 ,
F_104 ( V_472 , 3 , V_29 ,
V_59 ) ) ;
if ( V_38 < 0 )
return V_38 ;
V_38 = F_198 ( V_8 , V_376 , V_377 ,
F_104 ( V_23 , 3 , V_29 , V_59 ) ) ;
if ( V_38 < 0 )
return V_38 ;
V_8 -> V_365 [ V_8 -> V_40 . V_43 ++ ] = V_472 ;
}
return 0 ;
}
static int F_455 ( struct V_7 * V_8 ,
const struct V_84 * V_85 )
{
T_1 V_23 ;
int V_38 ;
V_8 -> V_40 . V_106 = V_8 -> V_365 ;
V_23 = V_85 -> V_89 [ 0 ] ;
if ( V_23 ) {
const char * V_50 ;
if ( V_85 -> V_368 == V_369 )
V_50 = L_51 ;
else
V_50 = L_45 ;
V_38 = F_454 ( V_8 , V_23 , V_50 , 0 ) ;
if ( V_38 < 0 )
return V_38 ;
}
V_23 = V_85 -> V_91 [ 0 ] ;
if ( V_23 ) {
V_38 = F_454 ( V_8 , V_23 , L_51 , 0 ) ;
if ( V_38 < 0 )
return V_38 ;
}
V_23 = V_85 -> V_93 [ 0 ] ;
if ( V_23 ) {
V_38 = F_454 ( V_8 , V_23 , L_52 , 0 ) ;
if ( V_38 < 0 )
return V_38 ;
}
return 0 ;
}
static void F_456 ( struct V_5 * V_6 ,
T_1 V_23 , int V_388 )
{
F_209 ( V_6 , V_23 , V_388 ) ;
}
static void F_457 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
T_1 V_23 = V_8 -> V_86 . V_89 [ 0 ] ;
if ( V_23 ) {
int V_388 = F_213 ( V_8 -> V_86 . V_368 ) ;
F_456 ( V_6 , V_23 , V_388 ) ;
}
}
static void F_458 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
T_1 V_129 ;
V_129 = V_8 -> V_86 . V_93 [ 0 ] ;
if ( V_129 )
F_456 ( V_6 , V_129 , V_141 ) ;
V_129 = V_8 -> V_86 . V_91 [ 0 ] ;
if ( V_129 )
F_456 ( V_6 , V_129 , V_142 ) ;
}
static int F_459 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
int V_38 ;
static const T_1 V_666 [] = { 0 } ;
V_38 = F_219 ( V_6 , & V_8 -> V_86 ,
V_666 ) ;
if ( V_38 < 0 )
return V_38 ;
if ( ! V_8 -> V_86 . V_87 ) {
if ( V_8 -> V_86 . V_262 || V_8 -> V_86 . V_264 ) {
V_8 -> V_40 . V_41 = 2 ;
V_8 -> V_285 = 1 ;
goto V_500;
}
return 0 ;
}
V_38 = F_455 ( V_8 , & V_8 -> V_86 ) ;
if ( V_38 < 0 )
return V_38 ;
V_8 -> V_40 . V_41 = 2 ;
V_500:
F_94 ( V_6 ) ;
if ( V_8 -> V_338 . V_339 )
F_34 ( V_8 , V_8 -> V_338 . V_339 ) ;
F_37 ( V_8 , V_667 ) ;
V_38 = F_290 ( V_6 ) ;
if ( V_38 < 0 )
return V_38 ;
return 1 ;
}
static void F_460 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
F_457 ( V_6 ) ;
F_458 ( V_6 ) ;
F_461 ( V_6 ) ;
F_93 ( V_6 ) ;
if ( V_8 -> V_112 )
F_59 ( V_6 ) ;
}
static int F_462 ( struct V_5 * V_6 )
{
struct V_7 * V_8 ;
int V_421 ;
int V_38 ;
V_8 = F_231 ( sizeof( * V_8 ) , V_196 ) ;
if ( V_8 == NULL )
return - V_194 ;
V_6 -> V_8 = V_8 ;
V_421 = F_232 ( V_6 , V_668 ,
V_669 ,
V_670 ) ;
if ( V_421 < 0 || V_421 >= V_668 ) {
F_81 ( V_221 L_59 ,
V_6 -> V_222 ) ;
V_421 = V_671 ;
}
if ( V_421 == V_671 ) {
V_38 = F_459 ( V_6 ) ;
if ( V_38 < 0 ) {
F_169 ( V_6 ) ;
return V_38 ;
} else if ( ! V_38 ) {
F_81 ( V_221
L_60
L_62 ) ;
V_421 = V_672 ;
}
}
if ( V_421 != V_671 )
F_38 ( V_6 , & V_673 [ V_421 ] ) ;
V_8 -> V_320 = & V_674 ;
V_8 -> V_323 = & V_675 ;
V_8 -> V_329 = & V_676 ;
V_8 -> V_330 = & V_677 ;
if ( ! V_8 -> V_25 ) {
V_8 -> V_25 = V_678 ;
V_8 -> V_110 = F_36 ( V_678 ) ;
}
if ( ! V_8 -> V_104 )
F_227 ( V_6 ) ;
V_8 -> V_290 = 0x02 ;
V_6 -> V_342 = V_436 ;
if ( V_421 == V_671 )
V_8 -> V_113 = F_460 ;
return 0 ;
}
static int T_5 F_463 ( void )
{
return F_464 ( & V_679 ) ;
}
static void T_6 F_465 ( void )
{
F_466 ( & V_679 ) ;
}
