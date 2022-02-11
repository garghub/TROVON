static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = V_6 -> V_8 ;
return F_3 ( V_8 -> V_9 , V_4 ) ;
}
static int F_4 ( struct V_1 * V_2 ,
struct V_10 * V_11 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = V_6 -> V_8 ;
unsigned int V_12 = F_5 ( V_2 , & V_11 -> V_13 ) ;
V_11 -> V_14 . V_15 . V_16 [ 0 ] = V_8 -> V_17 [ V_12 ] ;
return 0 ;
}
static int F_6 ( struct V_1 * V_2 ,
struct V_10 * V_11 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = V_6 -> V_8 ;
unsigned int V_12 = F_5 ( V_2 , & V_11 -> V_13 ) ;
return F_7 ( V_6 , V_8 -> V_9 , V_11 ,
V_8 -> V_18 [ V_12 ] , & V_8 -> V_17 [ V_12 ] ) ;
}
static int F_8 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = V_6 -> V_8 ;
return F_3 ( V_8 -> V_19 , V_4 ) ;
}
static int F_9 ( struct V_1 * V_2 ,
struct V_10 * V_11 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = V_6 -> V_8 ;
unsigned int V_20 = F_5 ( V_2 , & V_11 -> V_13 ) ;
V_11 -> V_14 . V_15 . V_16 [ 0 ] = V_8 -> V_21 [ V_20 ] ;
return 0 ;
}
static int F_10 ( struct V_1 * V_2 ,
struct V_10 * V_11 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = V_6 -> V_8 ;
struct V_22 * V_23 = & V_8 -> V_24 ;
unsigned int V_20 = F_5 ( V_2 , & V_11 -> V_13 ) ;
int V_25 , V_26 ;
T_1 V_27 ;
V_25 = F_7 ( V_6 , V_8 -> V_19 , V_11 ,
V_8 -> V_28 [ V_20 ] , & V_8 -> V_21 [ V_20 ] ) ;
if ( V_25 < 0 )
return V_25 ;
if ( V_8 -> V_29 ) {
if ( V_20 == 0 )
V_27 = V_8 -> V_30 . V_31 ;
else
V_27 = V_6 -> V_32 [ V_20 - 1 ] ;
if ( V_8 -> V_21 [ V_20 ] == V_23 -> V_33 - 1 )
V_26 = V_34 ;
else
V_26 = 0 ;
F_11 ( V_6 , V_27 , V_35 , 0 ,
V_34 , V_26 ) ;
}
return 0 ;
}
static unsigned int F_12 ( struct V_5 * V_6 ,
T_1 V_27 , unsigned int V_36 )
{
int error ;
unsigned int V_37 ;
V_37 = F_13 ( V_6 , V_27 , 0 ,
V_38 , 0 ) ;
V_37 &= 0xff ;
V_37 &= ~ ( V_39 | V_40 | V_41 ) ;
V_37 |= V_36 ;
if ( V_36 == V_42 )
V_37 |= V_41 ;
else
V_37 |= V_40 ;
error = F_14 ( V_6 , V_27 , 0 ,
V_43 , V_37 ) ;
if ( error < 0 )
return error ;
else
return 1 ;
}
static unsigned int F_15 ( struct V_5 * V_6 , T_1 V_27 )
{
unsigned int V_44 ;
V_44 = F_13 ( V_6 , V_27 , 0 ,
V_38 , 0 ) ;
V_44 &= V_39 ;
return V_44 ;
}
static int F_16 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = V_6 -> V_8 ;
return F_3 ( V_8 -> V_45 , V_4 ) ;
}
static int F_17 ( struct V_1 * V_2 , struct V_10 * V_11 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = V_6 -> V_8 ;
unsigned int V_46 = F_5 ( V_2 , & V_11 -> V_13 ) ;
V_11 -> V_14 . V_15 . V_16 [ 0 ] = V_8 -> V_47 [ V_46 ] ;
return 0 ;
}
static int F_18 ( struct V_1 * V_2 , struct V_10 * V_11 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = V_6 -> V_8 ;
unsigned int V_46 = F_5 ( V_2 , & V_11 -> V_13 ) ;
const struct V_22 * V_48 = V_8 -> V_45 ;
unsigned int V_49 , V_50 , V_51 ;
V_49 = V_11 -> V_14 . V_15 . V_16 [ 0 ] ;
if ( V_49 >= V_48 -> V_33 )
V_49 = V_48 -> V_33 - 1 ;
V_50 = V_8 -> V_47 [ V_46 ] ;
if ( V_50 == V_49 )
return 0 ;
if ( V_49 < V_8 -> V_52 ) {
F_14 ( V_6 , V_8 -> V_53 [ V_46 ] , 0 ,
V_54 ,
V_48 -> V_55 [ V_49 ] . V_56 ) ;
if ( V_50 >= V_8 -> V_52 &&
V_8 -> V_53 [ V_46 ] != V_8 -> V_18 [ V_46 ] ) {
V_48 = V_8 -> V_9 ;
F_14 ( V_6 ,
V_8 -> V_18 [ V_46 ] , 0 ,
V_54 ,
V_48 -> V_55 [ 0 ] . V_56 ) ;
}
} else {
V_48 = V_8 -> V_9 ;
V_51 = V_49 - V_8 -> V_52 + 1 ;
F_14 ( V_6 , V_8 -> V_18 [ V_46 ] , 0 ,
V_54 ,
V_48 -> V_55 [ V_51 ] . V_56 ) ;
}
V_8 -> V_47 [ V_46 ] = V_49 ;
return 1 ;
}
static int F_19 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = V_6 -> V_8 ;
return F_3 ( V_8 -> V_57 , V_4 ) ;
}
static int F_20 ( struct V_1 * V_2 ,
struct V_10 * V_11 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = V_6 -> V_8 ;
V_11 -> V_14 . V_15 . V_16 [ 0 ] = V_8 -> V_58 ;
return 0 ;
}
static int F_21 ( struct V_1 * V_2 ,
struct V_10 * V_11 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = V_6 -> V_8 ;
return F_7 ( V_6 , V_8 -> V_57 , V_11 ,
V_8 -> V_59 , & V_8 -> V_58 ) ;
}
static int F_22 ( struct V_1 * V_2 ,
struct V_10 * V_11 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
unsigned int V_49 = F_5 ( V_2 , & V_11 -> V_13 ) ;
struct V_7 * V_8 = V_6 -> V_8 ;
V_11 -> V_14 . integer . V_14 [ 0 ] = ! ! ( V_8 -> V_60 &
( V_8 -> V_61 << V_49 ) ) ;
return 0 ;
}
static int F_23 ( struct V_1 * V_2 ,
struct V_10 * V_11 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = V_6 -> V_8 ;
unsigned int V_49 = F_5 ( V_2 , & V_11 -> V_13 ) ;
unsigned int V_62 ;
unsigned int V_26 , V_63 ;
V_63 = V_8 -> V_61 << V_49 ;
if ( V_11 -> V_14 . integer . V_14 [ 0 ] )
V_26 = V_8 -> V_60 | V_63 ;
else
V_26 = V_8 -> V_60 & ~ V_63 ;
if ( V_8 -> V_60 == V_26 )
return 0 ;
V_8 -> V_60 = V_26 ;
V_62 = F_13 ( V_6 , V_6 -> V_64 , 0 ,
V_2 -> V_65 & 0xFFFF , 0x0 ) ;
V_62 >>= V_8 -> V_66 ;
if ( V_8 -> V_60 & V_63 ) {
F_24 ( V_6 ) ;
V_62 |= V_63 ;
} else {
F_25 ( V_6 ) ;
V_62 &= ~ V_63 ;
}
F_14 ( V_6 , V_6 -> V_64 , 0 ,
V_2 -> V_65 >> 16 , V_62 ) ;
return 1 ;
}
static int F_26 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
struct V_67 * V_68 = & V_8 -> V_69 ;
T_1 V_27 ;
int V_25 ;
int V_70 ;
if ( V_8 -> V_71 ) {
V_25 = F_27 ( V_6 , V_8 -> V_71 ) ;
if ( V_25 < 0 )
return V_25 ;
}
for ( V_70 = 0 ; V_70 < V_8 -> V_72 ; V_70 ++ ) {
V_25 = F_27 ( V_6 , V_8 -> V_73 [ V_70 ] ) ;
if ( V_25 < 0 )
return V_25 ;
}
if ( ! V_8 -> V_74 && V_8 -> V_75 > 0 &&
F_28 ( V_6 , L_1 ) == 1 ) {
V_76 . V_77 = V_8 -> V_75 ;
V_25 = F_29 ( V_6 , 0 ,
F_30 ( & V_76 , V_6 ) ) ;
if ( V_25 < 0 )
return V_25 ;
}
if ( V_8 -> V_78 > 0 ) {
int V_79 = F_31 ( V_6 , V_8 -> V_30 . V_31 ) ;
struct V_22 * V_23 = & V_8 -> V_24 ;
if ( V_79 & V_80 ) {
F_32 ( V_23 , L_2 , 0 , NULL ) ;
V_8 -> V_29 = 1 ;
}
V_81 . V_77 = V_8 -> V_78 ;
V_25 = F_29 ( V_6 , 0 ,
F_30 ( & V_81 , V_6 ) ) ;
if ( V_25 < 0 )
return V_25 ;
}
if ( V_8 -> V_30 . V_31 ) {
V_25 = F_33 ( V_6 , V_8 -> V_30 . V_31 ) ;
if ( V_25 < 0 )
return V_25 ;
V_25 = F_34 ( V_6 ,
& V_8 -> V_30 ) ;
if ( V_25 < 0 )
return V_25 ;
V_8 -> V_30 . V_82 = 1 ;
}
if ( V_8 -> V_83 && ! ( V_8 -> V_84 & 0x01 ) ) {
V_25 = F_35 ( V_6 , V_8 -> V_83 ) ;
if ( V_25 < 0 )
return V_25 ;
}
if ( ! F_36 ( V_6 , L_3 ) ) {
unsigned int V_85 [ 4 ] ;
F_37 ( V_6 , V_8 -> V_30 . V_86 [ 0 ] ,
V_35 , V_85 ) ;
V_85 [ 2 ] += V_85 [ 3 ] * V_8 -> V_87 ;
V_85 [ 3 ] |= V_88 ;
V_25 = F_38 ( V_6 , L_3 ,
V_85 , V_89 ) ;
if ( V_25 < 0 )
return V_25 ;
}
if ( ! F_36 ( V_6 , L_4 ) ) {
V_25 = F_38 ( V_6 , L_4 ,
NULL , V_90 ) ;
if ( V_25 < 0 )
return V_25 ;
}
if ( V_8 -> V_91 &&
F_28 ( V_6 , L_5 ) == 1 ) {
V_25 = F_27 ( V_6 , V_8 -> V_91 ) ;
if ( V_25 < 0 )
return V_25 ;
}
F_39 ( V_6 ) ;
if ( V_8 -> V_92 ) {
for ( V_70 = 0 ; V_70 < V_68 -> V_93 ; V_70 ++ ) {
int type = V_94 ;
V_27 = V_68 -> V_95 [ V_70 ] ;
if ( V_68 -> V_93 == V_70 )
type |= V_96 ;
V_25 = F_40 ( V_6 , V_27 , type ) ;
if ( V_25 < 0 )
return V_25 ;
}
}
for ( V_70 = 0 ; V_70 < V_68 -> V_97 ; V_70 ++ ) {
V_25 = F_40 ( V_6 , V_68 -> V_98 [ V_70 ] ,
V_96 ) ;
if ( V_25 < 0 )
return V_25 ;
}
for ( V_70 = 0 ; V_70 < V_68 -> V_99 ; V_70 ++ ) {
V_27 = V_68 -> V_100 [ V_70 ] . V_101 ;
V_25 = F_40 ( V_6 , V_27 , V_102 ) ;
if ( V_25 < 0 )
return V_25 ;
}
return 0 ;
}
static void F_41 ( struct V_5 * V_6 ,
const unsigned int * V_103 )
{
int V_70 ;
struct V_7 * V_8 = V_6 -> V_8 ;
if ( ! V_103 )
return;
for ( V_70 = 0 ; V_70 < V_8 -> V_104 ; V_70 ++ )
if ( V_8 -> V_105 [ V_70 ] && V_103 [ V_70 ] )
F_42 ( V_6 , V_8 -> V_105 [ V_70 ] ,
V_103 [ V_70 ] ) ;
}
static int F_43 ( struct V_106 * V_107 ,
struct V_5 * V_6 ,
struct V_108 * V_109 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
if ( V_8 -> V_110 )
F_44 ( V_8 -> V_110 ) ;
return F_45 ( V_6 , & V_8 -> V_30 , V_109 ,
V_107 ) ;
}
static int F_46 ( struct V_106 * V_107 ,
struct V_5 * V_6 ,
unsigned int V_111 ,
unsigned int V_112 ,
struct V_108 * V_109 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
return F_47 ( V_6 , & V_8 -> V_30 , V_111 , V_112 , V_109 ) ;
}
static int F_48 ( struct V_106 * V_107 ,
struct V_5 * V_6 ,
struct V_108 * V_109 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
return F_49 ( V_6 , & V_8 -> V_30 ) ;
}
static int F_50 ( struct V_106 * V_107 ,
struct V_5 * V_6 ,
struct V_108 * V_109 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
return F_51 ( V_6 , & V_8 -> V_30 ) ;
}
static int F_52 ( struct V_106 * V_107 ,
struct V_5 * V_6 ,
struct V_108 * V_109 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
return F_53 ( V_6 , & V_8 -> V_30 ) ;
}
static int F_54 ( struct V_106 * V_107 ,
struct V_5 * V_6 ,
unsigned int V_111 ,
unsigned int V_112 ,
struct V_108 * V_109 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
return F_55 ( V_6 , & V_8 -> V_30 ,
V_111 , V_112 , V_109 ) ;
}
static int F_56 ( struct V_106 * V_107 ,
struct V_5 * V_6 ,
struct V_108 * V_109 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
return F_57 ( V_6 , & V_8 -> V_30 ) ;
}
static int F_58 ( struct V_106 * V_107 ,
struct V_5 * V_6 ,
unsigned int V_111 ,
unsigned int V_112 ,
struct V_108 * V_109 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
T_1 V_27 = V_8 -> V_113 [ V_109 -> V_114 ] ;
if ( V_8 -> V_115 ) {
F_44 ( 40 ) ;
F_59 ( V_6 , V_27 , 0 ,
V_116 , V_117 ) ;
}
F_60 ( V_6 , V_27 , V_111 , 0 , V_112 ) ;
return 0 ;
}
static int F_61 ( struct V_106 * V_107 ,
struct V_5 * V_6 ,
struct V_108 * V_109 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
T_1 V_27 = V_8 -> V_113 [ V_109 -> V_114 ] ;
F_62 ( V_6 , V_27 ) ;
if ( V_8 -> V_115 )
F_59 ( V_6 , V_27 , 0 ,
V_116 , V_118 ) ;
return 0 ;
}
static int F_63 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
struct V_119 * V_120 = V_8 -> V_121 ;
V_6 -> V_122 = 1 ;
V_6 -> V_123 = V_120 ;
V_120 -> V_124 = L_6 ;
V_120 -> V_125 [ V_126 ] = V_127 ;
V_120 -> V_125 [ V_126 ] . V_27 =
V_8 -> V_30 . V_86 [ 0 ] ;
V_120 -> V_125 [ V_128 ] = V_129 ;
V_120 -> V_125 [ V_128 ] . V_27 = V_8 -> V_113 [ 0 ] ;
V_120 -> V_125 [ V_128 ] . V_130 = V_8 -> V_131 ;
if ( V_8 -> V_132 ) {
V_6 -> V_122 ++ ;
V_120 ++ ;
V_120 -> V_124 = L_7 ;
V_120 -> V_125 [ V_126 ] = V_133 ;
}
if ( V_8 -> V_30 . V_31 || V_8 -> V_83 ) {
V_6 -> V_122 ++ ;
V_120 ++ ;
V_120 -> V_124 = L_8 ;
V_120 -> V_134 = V_8 -> V_69 . V_135 [ 0 ] ;
if ( V_8 -> V_30 . V_31 ) {
V_120 -> V_125 [ V_126 ] = V_136 ;
V_120 -> V_125 [ V_126 ] . V_27 = V_8 -> V_30 . V_31 ;
}
if ( V_8 -> V_83 ) {
V_120 -> V_125 [ V_128 ] = V_137 ;
V_120 -> V_125 [ V_128 ] . V_27 = V_8 -> V_83 ;
}
}
return 0 ;
}
static unsigned int F_64 ( struct V_5 * V_6 ,
T_1 V_27 )
{
unsigned int V_138 = F_65 ( V_6 , V_27 ) ;
V_138 = ( V_138 & V_139 ) >> V_140 ;
if ( V_138 & V_141 )
return V_142 ;
if ( V_138 & V_143 )
return V_144 ;
if ( V_138 & V_145 )
return V_146 ;
if ( V_138 & V_147 )
return V_148 ;
return 0 ;
}
static void F_66 ( struct V_5 * V_6 , T_1 V_27 , int V_149 )
{
F_14 ( V_6 , V_27 , 0 ,
V_43 , V_149 ) ;
}
static int F_67 ( struct V_1 * V_2 ,
struct V_10 * V_11 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = V_6 -> V_8 ;
V_11 -> V_14 . integer . V_14 [ 0 ] = ! ! V_8 -> V_150 ;
return 0 ;
}
static int F_68 ( struct V_1 * V_2 ,
struct V_10 * V_11 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = V_6 -> V_8 ;
int V_27 = V_2 -> V_65 ;
V_8 -> V_150 = V_11 -> V_14 . integer . V_14 [ 0 ] ? V_27 : 0 ;
F_69 ( V_6 , V_27 ) ;
return 1 ;
}
static int F_70 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
int V_70 ;
static const char * const V_151 [] = {
L_9 , L_10 , L_11
} ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = V_6 -> V_8 ;
T_1 V_27 = V_2 -> V_65 ;
if ( V_27 == V_8 -> V_152 || V_27 == V_8 -> V_153 )
V_70 = 3 ;
else
V_70 = 2 ;
V_4 -> type = V_154 ;
V_4 -> V_14 . V_15 . V_55 = V_70 ;
V_4 -> V_77 = 1 ;
if ( V_4 -> V_14 . V_15 . V_16 >= V_70 )
V_4 -> V_14 . V_15 . V_16 = V_70 - 1 ;
strcpy ( V_4 -> V_14 . V_15 . V_124 ,
V_151 [ V_4 -> V_14 . V_15 . V_16 ] ) ;
return 0 ;
}
static int F_71 ( struct V_1 * V_2 ,
struct V_10 * V_11 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
T_1 V_27 = V_2 -> V_65 ;
unsigned int V_44 = F_15 ( V_6 , V_27 ) ;
if ( V_44 == F_64 ( V_6 , V_27 ) )
V_11 -> V_14 . V_15 . V_16 [ 0 ] = 0 ;
else if ( V_44 == V_148 )
V_11 -> V_14 . V_15 . V_16 [ 0 ] = 1 ;
else if ( V_44 == V_42 )
V_11 -> V_14 . V_15 . V_16 [ 0 ] = 2 ;
return 0 ;
}
static int F_72 ( struct V_1 * V_2 ,
struct V_10 * V_11 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
unsigned int V_36 = 0 ;
int error ;
T_1 V_27 = V_2 -> V_65 ;
if ( V_11 -> V_14 . V_15 . V_16 [ 0 ] == 0 )
V_36 = F_64 ( V_6 , V_27 ) ;
else if ( V_11 -> V_14 . V_15 . V_16 [ 0 ] == 1 )
V_36 = V_148 ;
else if ( V_11 -> V_14 . V_15 . V_16 [ 0 ] == 2 )
V_36 = V_42 ;
else
return 0 ;
if ( V_36 != F_15 ( V_6 , V_27 ) ) {
error = F_12 ( V_6 , V_27 , V_36 ) ;
return error ;
}
return 0 ;
}
static int F_73 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
char * V_151 [ 2 ] ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = V_6 -> V_8 ;
if ( V_2 -> V_65 == V_8 -> V_153 )
V_151 [ 0 ] = L_10 ;
else
V_151 [ 0 ] = L_9 ;
V_151 [ 1 ] = L_11 ;
V_4 -> type = V_154 ;
V_4 -> V_14 . V_15 . V_55 = 2 ;
V_4 -> V_77 = 1 ;
if ( V_4 -> V_14 . V_15 . V_16 >= 2 )
V_4 -> V_14 . V_15 . V_16 = 1 ;
strcpy ( V_4 -> V_14 . V_15 . V_124 ,
V_151 [ V_4 -> V_14 . V_15 . V_16 ] ) ;
return 0 ;
}
static int F_74 ( struct V_1 * V_2 , struct V_10 * V_11 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = V_6 -> V_8 ;
T_1 V_27 = V_2 -> V_65 ;
int V_155 = ( V_27 == V_8 -> V_152 ) ? 1 : 0 ;
V_11 -> V_14 . V_15 . V_16 [ 0 ] = V_8 -> V_156 [ V_155 ] ;
return 0 ;
}
static int F_75 ( struct V_1 * V_2 , struct V_10 * V_11 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = V_6 -> V_8 ;
T_1 V_27 = V_2 -> V_65 ;
int V_155 = ( V_27 == V_8 -> V_152 ) ? 1 : 0 ;
unsigned short V_26 = ! ! V_11 -> V_14 . V_15 . V_16 [ 0 ] ;
V_8 -> V_156 [ V_155 ] = V_26 ;
if ( V_26 )
F_66 ( V_6 , V_27 , V_41 ) ;
else {
unsigned int V_157 = V_40 ;
if ( V_155 )
V_157 |= F_64 ( V_6 , V_27 ) ;
F_66 ( V_6 , V_27 , V_157 ) ;
}
if ( V_8 -> V_92 )
F_69 ( V_6 , V_27 ) ;
return 1 ;
}
static int F_76 ( struct V_1 * V_2 ,
struct V_10 * V_11 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = V_6 -> V_8 ;
V_11 -> V_14 . integer . V_14 [ 0 ] = V_8 -> V_158 ;
return 0 ;
}
static int F_77 ( struct V_1 * V_2 ,
struct V_10 * V_11 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = V_6 -> V_8 ;
T_1 V_27 = V_2 -> V_65 & 0xff ;
unsigned int V_26 = ! ! V_11 -> V_14 . integer . V_14 [ 0 ] ;
if ( V_8 -> V_158 == V_26 )
return 0 ;
V_8 -> V_158 = V_26 ;
F_14 ( V_6 , V_27 , 0 , V_159 ,
V_8 -> V_158 ? 0x4 : 0x0 ) ;
return 1 ;
}
static struct V_160 *
F_78 ( struct V_7 * V_8 ,
const struct V_160 * V_161 ,
const char * V_124 ,
unsigned int V_162 )
{
struct V_160 * V_163 ;
F_79 ( & V_8 -> V_164 , sizeof( * V_163 ) , 32 ) ;
V_163 = F_80 ( & V_8 -> V_164 ) ;
if ( ! V_163 )
return NULL ;
* V_163 = * V_161 ;
V_163 -> V_124 = F_81 ( V_124 , V_165 ) ;
if ( ! V_163 -> V_124 ) {
memset ( V_163 , 0 , sizeof( * V_163 ) ) ;
V_8 -> V_164 . V_166 -- ;
return NULL ;
}
V_163 -> V_167 = V_162 ;
return V_163 ;
}
static int F_82 ( struct V_7 * V_8 ,
const struct V_160 * V_161 ,
int V_49 , const char * V_124 ,
unsigned long V_26 )
{
struct V_160 * V_163 = F_78 ( V_8 , V_161 , V_124 ,
V_168 ) ;
if ( ! V_163 )
return - V_169 ;
V_163 -> V_56 = V_49 ;
V_163 -> V_65 = V_26 ;
return 0 ;
}
static inline int F_83 ( struct V_7 * V_8 ,
int type , int V_49 , const char * V_124 ,
unsigned long V_26 )
{
return F_82 ( V_8 ,
& V_170 [ type ] ,
V_49 , V_124 , V_26 ) ;
}
static inline int F_84 ( struct V_7 * V_8 , int type ,
const char * V_124 , unsigned long V_26 )
{
return F_83 ( V_8 , type , 0 , V_124 , V_26 ) ;
}
static inline int F_85 ( struct V_5 * V_6 ,
T_1 V_27 , int V_49 )
{
int V_171 = F_86 ( V_6 , V_27 ) ;
int V_172 = 0 ;
struct V_7 * V_8 = V_6 -> V_8 ;
char V_124 [ 22 ] ;
if ( F_87 ( V_171 ) != V_173 ) {
if ( F_64 ( V_6 , V_27 ) == V_148
&& V_27 == V_8 -> V_153 )
V_172 = V_174 ;
else if ( F_65 ( V_6 , V_27 )
& ( V_147 << V_140 ) )
V_172 = V_175 ;
else if ( V_27 == V_8 -> V_152 )
V_172 = V_174 ;
}
if ( V_172 ) {
strcpy ( V_124 , F_88 ( V_6 , V_27 , 1 ) ) ;
return F_84 ( V_6 -> V_8 , V_172 ,
strcat ( V_124 , L_12 ) , V_27 ) ;
}
return 0 ;
}
static int F_89 ( struct V_7 * V_8 )
{
struct V_160 * V_163 ;
struct V_22 * V_48 = & V_8 -> V_176 ;
if ( V_8 -> V_74 )
return 0 ;
if ( ! V_8 -> V_131 || V_48 -> V_33 <= 1 )
return 0 ;
V_163 = F_78 ( V_8 , & V_177 ,
V_177 . V_124 , 0 ) ;
if ( ! V_163 )
return - V_169 ;
V_163 -> V_77 = V_8 -> V_131 ;
return 0 ;
}
static T_1 F_90 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
struct V_67 * V_68 = & V_8 -> V_69 ;
T_1 V_27 ;
unsigned int V_138 ;
int V_70 ;
if ( V_68 -> V_178 != V_179 )
return 0 ;
for ( V_70 = 0 ; V_70 < V_68 -> V_99 ; V_70 ++ ) {
if ( V_68 -> V_100 [ V_70 ] . type == V_180 ) {
V_27 = V_68 -> V_100 [ V_70 ] . V_101 ;
V_138 = F_65 ( V_6 , V_27 ) ;
if ( V_138 & V_181 )
return V_27 ;
}
}
return 0 ;
}
static T_1 F_91 ( struct V_5 * V_6 , T_1 * V_182 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
struct V_67 * V_68 = & V_8 -> V_69 ;
unsigned int V_171 , V_138 ;
int V_70 ;
* V_182 = 0 ;
if ( V_68 -> V_178 != V_179 )
return 0 ;
for ( V_70 = 0 ; V_70 < V_68 -> V_99 ; V_70 ++ ) {
T_1 V_27 = V_68 -> V_100 [ V_70 ] . V_101 ;
if ( V_68 -> V_100 [ V_70 ] . type != V_183 )
continue;
V_171 = F_86 ( V_6 , V_27 ) ;
if ( F_87 ( V_171 ) != V_173 ) {
V_138 = F_65 ( V_6 , V_27 ) ;
if ( V_138 & V_181 ) {
* V_182 = F_92 ( V_6 , V_27 ) ;
if ( * V_182 )
return V_27 ;
}
}
}
return 0 ;
}
static int F_93 ( struct V_7 * V_8 , T_1 V_27 )
{
int V_70 ;
for ( V_70 = 0 ; V_70 < V_8 -> V_30 . V_184 ; V_70 ++ ) {
if ( V_8 -> V_30 . V_86 [ V_70 ] == V_27 )
return 1 ;
}
return 0 ;
}
static int F_94 ( struct V_7 * V_8 , T_1 V_27 )
{
int V_70 ;
if ( F_93 ( V_8 , V_27 ) )
return 1 ;
for ( V_70 = 0 ; V_70 < V_8 -> V_69 . V_93 ; V_70 ++ )
if ( V_8 -> V_185 [ V_70 ] == V_27 )
return 1 ;
for ( V_70 = 0 ; V_70 < V_8 -> V_69 . V_186 ; V_70 ++ )
if ( V_8 -> V_187 [ V_70 ] == V_27 )
return 1 ;
return 0 ;
}
static T_1 F_92 ( struct V_5 * V_6 , T_1 V_27 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
int V_188 , V_189 ;
T_1 V_190 [ V_191 ] ;
unsigned int V_79 , V_192 ;
V_189 = F_95 ( V_6 , V_27 , V_190 ,
V_191 ) ;
while ( V_189 == 1 && ( F_96 ( F_31 ( V_6 , V_190 [ 0 ] ) )
!= V_193 ) ) {
V_27 = V_190 [ 0 ] ;
V_189 = F_95 ( V_6 , V_27 , V_190 ,
V_191 ) ;
}
for ( V_188 = 0 ; V_188 < V_189 ; V_188 ++ ) {
V_79 = F_31 ( V_6 , V_190 [ V_188 ] ) ;
V_192 = F_96 ( V_79 ) ;
if ( V_192 != V_193 || ( V_79 & V_194 ) )
continue;
if ( ! F_94 ( V_8 , V_190 [ V_188 ] ) ) {
if ( V_189 > 1 ) {
F_14 ( V_6 , V_27 , 0 ,
V_54 , V_188 ) ;
}
return V_190 [ V_188 ] ;
}
}
if ( V_189 > 1 ) {
for ( V_188 = 0 ; V_188 < V_189 ; V_188 ++ ) {
if ( V_190 [ V_188 ] == V_8 -> V_30 . V_86 [ 0 ] ) {
F_14 ( V_6 , V_27 , 0 ,
V_54 , V_188 ) ;
break;
}
}
}
return 0 ;
}
static int F_97 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
struct V_67 * V_68 = & V_8 -> V_69 ;
int V_70 ;
T_1 V_27 , V_182 ;
for ( V_70 = 0 ; V_70 < V_68 -> V_97 ; V_70 ++ ) {
V_27 = V_68 -> V_98 [ V_70 ] ;
V_182 = F_92 ( V_6 , V_27 ) ;
if ( ! V_182 ) {
if ( V_8 -> V_30 . V_184 > 0 ) {
V_68 -> V_97 = V_8 -> V_30 . V_184 ;
break;
}
F_98 ( V_195
L_13 ,
V_196 , V_27 ) ;
return - V_197 ;
}
F_99 ( V_8 , V_182 ) ;
}
for ( V_70 = 0 ; V_70 < V_68 -> V_93 ; V_70 ++ ) {
V_27 = V_68 -> V_95 [ V_70 ] ;
V_182 = F_92 ( V_6 , V_27 ) ;
if ( V_182 ) {
if ( ! V_8 -> V_30 . V_198 )
V_8 -> V_30 . V_198 = V_182 ;
else
F_100 ( V_8 , V_182 ) ;
}
V_8 -> V_185 [ V_70 ] = V_182 ;
}
for ( V_70 = 0 ; V_70 < V_68 -> V_186 ; V_70 ++ ) {
V_27 = V_68 -> V_199 [ V_70 ] ;
V_182 = F_92 ( V_6 , V_27 ) ;
if ( V_182 )
F_100 ( V_8 , V_182 ) ;
V_8 -> V_187 [ V_70 ] = V_182 ;
}
V_27 = F_90 ( V_6 ) ;
if ( V_27 ) {
V_182 = F_92 ( V_6 , V_27 ) ;
if ( V_182 ) {
F_101 ( L_14 ,
V_27 , V_68 -> V_97 ) ;
V_68 -> V_98 [ V_68 -> V_97 ] = V_27 ;
V_68 -> V_97 ++ ;
V_8 -> V_153 = V_27 ;
F_99 ( V_8 , V_182 ) ;
}
}
V_27 = F_91 ( V_6 , & V_182 ) ;
if ( V_27 && V_182 ) {
F_101 ( L_15 ,
V_27 , V_68 -> V_97 ) ;
V_68 -> V_98 [ V_68 -> V_97 ] = V_27 ;
V_68 -> V_97 ++ ;
V_8 -> V_152 = V_27 ;
F_99 ( V_8 , V_182 ) ;
}
F_102 ( L_16 ,
V_8 -> V_30 . V_184 ,
V_8 -> V_30 . V_86 [ 0 ] ,
V_8 -> V_30 . V_86 [ 1 ] ,
V_8 -> V_30 . V_86 [ 2 ] ,
V_8 -> V_30 . V_86 [ 3 ] ,
V_8 -> V_30 . V_86 [ 4 ] ) ;
return 0 ;
}
static int F_103 ( struct V_5 * V_6 , const char * V_200 ,
int V_49 , T_1 V_27 , int V_201 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
char V_124 [ 32 ] ;
int V_25 ;
if ( ! V_8 -> V_202 ) {
unsigned int V_203 , V_204 , V_205 , V_206 ;
V_203 = F_104 ( V_6 , V_27 , V_35 ) ;
V_204 = ( V_203 & V_207 ) >>
V_208 ;
V_204 = ( V_204 + 1 ) * 25 ;
V_205 = ( V_203 & V_209 ) >>
V_210 ;
V_206 = V_205 * V_204 ;
if ( V_206 > 6400 && V_205 >= 0x1f )
V_8 -> V_87 = V_205 / 2 ;
V_8 -> V_202 = 1 ;
}
sprintf ( V_124 , L_17 , V_200 ) ;
V_25 = F_83 ( V_8 , V_211 , V_49 , V_124 ,
F_105 ( V_27 , V_201 , 0 , V_35 ,
V_8 -> V_87 ) ) ;
if ( V_25 < 0 )
return V_25 ;
sprintf ( V_124 , L_18 , V_200 ) ;
V_25 = F_83 ( V_8 , V_212 , V_49 , V_124 ,
F_106 ( V_27 , V_201 , 0 , V_35 ) ) ;
if ( V_25 < 0 )
return V_25 ;
return 0 ;
}
static int F_99 ( struct V_7 * V_8 , T_1 V_27 )
{
if ( V_8 -> V_30 . V_184 > 4 ) {
F_107 ( V_213 L_19 , V_27 ) ;
return 1 ;
} else {
F_108 ( V_8 -> V_30 . V_86 != V_8 -> V_86 ) ;
V_8 -> V_86 [ V_8 -> V_30 . V_184 ] = V_27 ;
V_8 -> V_30 . V_184 ++ ;
}
return 0 ;
}
static int F_100 ( struct V_7 * V_8 , T_1 V_27 )
{
int V_70 ;
for ( V_70 = 0 ; V_70 < F_109 ( V_8 -> V_30 . V_214 ) ; V_70 ++ ) {
if ( ! V_8 -> V_30 . V_214 [ V_70 ] ) {
V_8 -> V_30 . V_214 [ V_70 ] = V_27 ;
return 0 ;
}
}
F_107 ( V_213 L_20 , V_27 ) ;
return 1 ;
}
static int F_110 ( struct V_5 * V_6 , int V_215 ,
const T_1 * V_216 ,
const T_1 * V_86 ,
int type )
{
struct V_7 * V_8 = V_6 -> V_8 ;
static const char * const V_217 [ 4 ] = {
L_21 , L_22 , NULL , L_23
} ;
T_1 V_27 ;
int V_70 , V_25 ;
unsigned int V_218 ;
for ( V_70 = 0 ; V_70 < V_215 && V_70 < F_109 ( V_217 ) ; V_70 ++ ) {
if ( type == V_219 && ! V_8 -> V_92 ) {
if ( F_111 ( V_6 , V_216 [ V_70 ] ) )
V_8 -> V_92 = 1 ;
}
V_27 = V_86 [ V_70 ] ;
if ( ! V_27 )
continue;
if ( type != V_219 && V_70 == 2 ) {
V_25 = F_112 ( V_6 , L_24 , V_27 , 1 ) ;
if ( V_25 < 0 )
return V_25 ;
V_25 = F_112 ( V_6 , L_25 , V_27 , 2 ) ;
if ( V_25 < 0 )
return V_25 ;
V_218 = F_31 ( V_6 , V_27 ) ;
if ( V_218 & V_220 ) {
V_25 = F_84 ( V_8 ,
V_221 ,
L_26 , V_27 ) ;
if ( V_25 < 0 )
return V_25 ;
}
} else {
const char * V_124 ;
int V_49 ;
switch ( type ) {
case V_219 :
V_124 = L_27 ;
V_49 = V_70 ;
break;
case V_222 :
V_124 = L_28 ;
V_49 = V_70 ;
break;
default:
V_124 = V_217 [ V_70 ] ;
V_49 = 0 ;
break;
}
V_25 = F_103 ( V_6 , V_124 , V_49 , V_27 , 3 ) ;
if ( V_25 < 0 )
return V_25 ;
}
}
return 0 ;
}
static int F_113 ( struct V_5 * V_6 , unsigned long V_223 ,
unsigned long V_224 , int V_49 )
{
int V_25 ;
V_25 = F_83 ( V_6 -> V_8 , V_211 , V_49 ,
L_29 , V_223 ) ;
if ( V_25 < 0 )
return V_25 ;
V_25 = F_83 ( V_6 -> V_8 , V_212 , V_49 ,
L_30 , V_224 ) ;
if ( V_25 < 0 )
return V_25 ;
return 0 ;
}
static int F_114 ( struct V_5 * V_6 ,
const struct V_67 * V_68 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
T_1 V_27 ;
int V_25 ;
int V_49 ;
V_25 = F_110 ( V_6 , V_68 -> V_97 , V_68 -> V_98 ,
V_8 -> V_30 . V_86 ,
V_68 -> V_178 ) ;
if ( V_25 < 0 )
return V_25 ;
if ( V_68 -> V_93 > 1 && V_68 -> V_178 == V_179 ) {
V_25 = F_84 ( V_8 ,
V_225 ,
L_31 ,
V_68 -> V_95 [ V_68 -> V_93 - 1 ] ) ;
if ( V_25 < 0 )
return V_25 ;
}
for ( V_49 = 0 ; V_49 < V_68 -> V_99 ; V_49 ++ ) {
if ( V_68 -> V_100 [ V_49 ] . type > V_180 )
break;
V_27 = V_68 -> V_100 [ V_49 ] . V_101 ;
V_25 = F_85 ( V_6 , V_27 , V_49 ) ;
if ( V_25 < 0 )
return V_25 ;
}
return 0 ;
}
static int F_115 ( struct V_5 * V_6 ,
struct V_67 * V_68 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
int V_25 ;
V_25 = F_110 ( V_6 , V_68 -> V_93 , V_68 -> V_95 ,
V_8 -> V_185 , V_219 ) ;
if ( V_25 < 0 )
return V_25 ;
V_25 = F_110 ( V_6 , V_68 -> V_186 , V_68 -> V_199 ,
V_8 -> V_187 , V_222 ) ;
if ( V_25 < 0 )
return V_25 ;
return 0 ;
}
static int F_116 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
struct V_22 * V_57 = & V_8 -> V_226 ;
int V_70 , V_227 ;
T_1 V_228 [ F_109 ( V_229 ) ] ;
V_227 = F_95 ( V_6 ,
V_8 -> V_59 ,
V_228 ,
V_230 ) ;
if ( V_227 <= 0 || V_227 > F_109 ( V_229 ) )
return - V_231 ;
for ( V_70 = 0 ; V_70 < V_227 ; V_70 ++ )
F_32 ( V_57 , V_229 [ V_70 ] , V_70 ,
NULL ) ;
return F_84 ( V_8 , V_232 ,
L_32 , V_8 -> V_59 ) ;
}
static int F_117 ( struct V_5 * V_6 ,
T_1 V_27 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
T_2 V_203 = F_104 ( V_6 , V_27 , V_35 ) ;
int V_25 , type = V_233 ;
if ( V_8 -> V_234 == V_27 )
type = V_212 ;
if ( ( V_203 & V_235 ) >> V_236 ) {
V_25 = F_84 ( V_8 , type ,
L_33 ,
F_106 ( V_27 , 1 , 0 , V_35 ) ) ;
if ( V_25 < 0 )
return V_25 ;
}
if ( ( V_203 & V_209 ) >> V_210 ) {
V_25 = F_84 ( V_8 , V_211 ,
L_34 ,
F_106 ( V_27 , 1 , 0 , V_35 ) ) ;
if ( V_25 < 0 )
return V_25 ;
}
return 0 ;
}
static int F_118 ( struct V_1 * V_2 ,
struct V_10 * V_11 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
V_11 -> V_14 . integer . V_14 [ 0 ] = V_6 -> V_237 -> V_238 ;
return 0 ;
}
static int F_119 ( struct V_1 * V_2 ,
struct V_10 * V_11 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
return F_120 ( V_6 , V_11 -> V_14 . integer . V_14 [ 0 ] ) ;
}
static int F_121 ( struct V_5 * V_6 )
{
return F_82 ( V_6 -> V_8 , & V_239 ,
0 , L_33 , 0 ) ;
}
static int F_122 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
int V_70 , V_188 , V_25 = 0 ;
for ( V_70 = 0 ; V_70 < V_8 -> V_240 ; V_70 ++ ) {
T_1 V_27 ;
unsigned int V_79 ;
unsigned long V_26 ;
V_27 = V_8 -> V_53 [ V_70 ] ;
V_79 = F_31 ( V_6 , V_27 ) ;
if ( ! ( V_79 & V_80 ) )
continue;
V_26 = F_106 ( V_27 , 3 , 0 , V_35 ) ;
for ( V_188 = 0 ; V_188 < V_8 -> V_241 ; V_188 ++ ) {
if ( V_8 -> V_242 [ V_188 ] == V_26 )
break;
}
if ( V_188 < V_8 -> V_241 )
continue;
V_25 = F_83 ( V_8 , V_211 , V_70 ,
L_35 , V_26 ) ;
if ( V_25 < 0 )
return V_25 ;
}
return 0 ;
}
static int F_123 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
struct V_22 * V_243 = & V_8 -> V_24 ;
const char * const * V_244 = V_8 -> V_245 ;
int V_70 , V_227 ;
T_1 V_228 [ V_230 ] ;
V_227 = F_95 ( V_6 ,
V_8 -> V_28 [ 0 ] ,
V_228 ,
V_230 ) ;
if ( V_227 <= 0 )
return - V_231 ;
if ( ! V_244 )
V_244 = V_246 ;
for ( V_70 = 0 ; V_70 < V_227 ; V_70 ++ )
F_32 ( V_243 , V_244 [ V_70 ] , V_70 , NULL ) ;
return 0 ;
}
static T_1 F_124 ( struct V_5 * V_6 , T_1 V_247 ,
int V_49 )
{
T_1 V_190 [ V_230 ] ;
int V_205 ;
V_205 = F_95 ( V_6 , V_247 , V_190 , F_109 ( V_190 ) ) ;
if ( V_49 >= 0 && V_49 < V_205 )
return V_190 [ V_49 ] ;
return 0 ;
}
static int F_125 ( struct V_5 * V_6 , T_1 V_247 ,
T_1 V_27 )
{
T_1 V_190 [ V_230 ] ;
int V_70 , V_205 ;
if ( ! ( F_31 ( V_6 , V_247 ) & V_248 ) )
return - 1 ;
V_205 = F_95 ( V_6 , V_247 , V_190 , F_109 ( V_190 ) ) ;
for ( V_70 = 0 ; V_70 < V_205 ; V_70 ++ )
if ( V_190 [ V_70 ] == V_27 )
return V_70 ;
for ( V_70 = 0 ; V_70 < V_205 ; V_70 ++ ) {
unsigned int V_218 = F_31 ( V_6 , V_190 [ V_70 ] ) ;
unsigned int V_249 = F_96 ( V_218 ) ;
if ( V_249 != V_250 && V_249 != V_251 )
if ( F_125 ( V_6 , V_190 [ V_70 ] , V_27 ) >= 0 )
return V_70 ;
}
return - 1 ;
}
static int F_126 ( struct V_5 * V_6 , T_1 V_27 ,
const char * V_252 , int V_49 , int V_253 )
{
unsigned int V_203 , V_205 ;
char V_124 [ 32 ] ;
int V_25 ;
if ( V_253 == V_35 )
V_203 = V_80 ;
else
V_203 = V_254 ;
if ( ! ( F_31 ( V_6 , V_27 ) & V_203 ) )
return 0 ;
V_203 = F_104 ( V_6 , V_27 , V_253 ) ;
V_205 = ( V_203 & V_209 ) >> V_210 ;
if ( ! V_205 )
return 0 ;
snprintf ( V_124 , sizeof( V_124 ) , L_36 , V_252 ) ;
V_25 = F_83 ( V_6 -> V_8 , V_211 , V_49 , V_124 ,
F_106 ( V_27 , 3 , 0 , V_253 ) ) ;
if ( V_25 < 0 )
return V_25 ;
return 1 ;
}
static int F_127 ( struct V_5 * V_6 ,
const struct V_67 * V_68 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
struct V_22 * V_48 = & V_8 -> V_176 ;
struct V_22 * V_255 = & V_8 -> V_256 ;
int V_25 , V_70 ;
unsigned int V_171 ;
F_32 ( V_255 , V_257 [ 0 ] , 0 , NULL ) ;
for ( V_70 = 0 ; V_70 < V_8 -> V_258 ; V_70 ++ ) {
T_1 V_27 ;
int V_56 , V_259 ;
const char * V_252 ;
V_27 = V_8 -> V_260 [ V_70 ] ;
if ( F_96 ( F_31 ( V_6 , V_27 ) ) != V_250 )
continue;
V_171 = F_86 ( V_6 , V_27 ) ;
if ( F_128 ( V_171 ) == V_261 )
continue;
V_56 = F_125 ( V_6 , V_8 -> V_18 [ 0 ] , V_27 ) ;
if ( V_56 < 0 )
continue;
V_252 = F_88 ( V_6 , V_27 , 1 ) ;
F_32 ( V_255 , V_252 , V_56 , & V_259 ) ;
if ( F_28 ( V_6 , L_1 ) != 1 )
F_32 ( V_48 , V_252 , V_56 , & V_259 ) ;
V_25 = F_126 ( V_6 , V_27 , V_252 , V_259 ,
V_262 ) ;
if ( V_25 < 0 )
return V_25 ;
if ( ! V_25 ) {
V_25 = F_126 ( V_6 , V_27 , V_252 ,
V_259 , V_35 ) ;
if ( V_25 < 0 )
return V_25 ;
if ( ! V_25 ) {
V_27 = F_124 ( V_6 ,
V_8 -> V_18 [ 0 ] , V_56 ) ;
if ( V_27 )
V_25 = F_126 ( V_6 ,
V_27 , V_252 ,
V_259 , V_262 ) ;
if ( V_25 < 0 )
return V_25 ;
}
}
}
return 0 ;
}
static int F_129 ( struct V_5 * V_6 , T_1 V_27 ,
T_1 * V_263 , T_1 * V_264 , T_1 * V_265 )
{
unsigned int V_68 ;
unsigned int type ;
if ( ! V_27 )
return 0 ;
V_68 = F_86 ( V_6 , V_27 ) ;
type = F_130 ( V_68 ) ;
switch ( F_87 ( V_68 ) ) {
case V_173 :
if ( * V_263 )
return 1 ;
if ( type != V_266 )
return 1 ;
* V_263 = V_27 ;
break;
case V_267 :
break;
case V_268 :
if ( * V_265 )
return 1 ;
if ( type != V_266 && type != V_269 )
return 1 ;
* V_265 = V_27 ;
break;
default:
if ( * V_264 )
return 1 ;
if ( type != V_266 )
return 1 ;
* V_264 = V_27 ;
break;
}
return 0 ;
}
static int F_131 ( struct V_5 * V_6 ,
struct V_270 * V_271 ,
T_1 V_101 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
struct V_67 * V_68 = & V_8 -> V_69 ;
int V_70 ;
V_271 -> V_101 = V_101 ;
if ( V_101 == 0 )
return 0 ;
for ( V_70 = 0 ; V_70 < V_68 -> V_99 ; V_70 ++ ) {
if ( V_101 == V_68 -> V_100 [ V_70 ] . V_101 )
break;
}
if ( V_70 < V_68 -> V_99 && V_68 -> V_100 [ V_70 ] . type == V_183 ) {
V_70 = F_125 ( V_6 , V_8 -> V_53 [ 0 ] , V_101 ) ;
if ( V_70 < 0 )
return - 1 ;
V_271 -> V_272 = V_70 ;
V_271 -> V_12 = - 1 ;
if ( V_8 -> V_18 )
V_271 -> V_12 = F_125 ( V_6 ,
V_8 -> V_18 [ 0 ] ,
V_8 -> V_53 [ 0 ] ) ;
} else if ( V_8 -> V_18 ) {
V_70 = F_125 ( V_6 , V_8 -> V_18 [ 0 ] , V_101 ) ;
if ( V_70 < 0 )
return - 1 ;
V_271 -> V_12 = V_70 ;
V_271 -> V_272 = - 1 ;
if ( V_8 -> V_53 )
V_271 -> V_272 = F_125 ( V_6 ,
V_8 -> V_53 [ 0 ] ,
V_8 -> V_18 [ 0 ] ) ;
}
return 0 ;
}
static int F_132 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
struct V_67 * V_68 = & V_8 -> V_69 ;
T_1 V_263 , V_264 , V_265 ;
int V_70 ;
V_263 = V_264 = V_265 = 0 ;
for ( V_70 = 0 ; V_70 < V_68 -> V_99 ; V_70 ++ )
if ( F_129 ( V_6 , V_68 -> V_100 [ V_70 ] . V_101 ,
& V_263 , & V_264 , & V_265 ) )
return 0 ;
for ( V_70 = 0 ; V_70 < V_8 -> V_258 ; V_70 ++ )
if ( F_129 ( V_6 , V_8 -> V_260 [ V_70 ] ,
& V_263 , & V_264 , & V_265 ) )
return 0 ;
if ( ! V_263 || ( ! V_264 && ! V_265 ) )
return 0 ;
if ( ! F_111 ( V_6 , V_264 ) )
return 0 ;
if ( F_131 ( V_6 , & V_8 -> V_273 , V_264 ) ||
F_131 ( V_6 , & V_8 -> V_274 , V_263 ) ||
F_131 ( V_6 , & V_8 -> V_275 , V_265 ) )
return 0 ;
return 1 ;
}
static int F_133 ( struct V_5 * V_6 , const struct V_67 * V_68 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
struct V_22 * V_48 = & V_8 -> V_176 ;
int V_70 , V_188 ;
const char * V_252 ;
for ( V_70 = 0 ; V_70 < V_68 -> V_99 ; V_70 ++ ) {
T_1 V_27 = V_68 -> V_100 [ V_70 ] . V_101 ;
int V_56 , V_25 , V_259 ;
V_56 = - 1 ;
for ( V_188 = 0 ; V_188 < V_8 -> V_240 ; V_188 ++ ) {
V_56 = F_125 ( V_6 , V_8 -> V_53 [ V_188 ] ,
V_27 ) ;
if ( V_56 >= 0 )
break;
}
if ( V_56 < 0 )
continue;
V_252 = F_134 ( V_6 , V_68 , V_70 ) ;
F_32 ( V_48 , V_252 , V_56 , & V_259 ) ;
V_25 = F_126 ( V_6 , V_27 ,
V_252 , V_259 ,
V_262 ) ;
if ( V_25 < 0 )
return V_25 ;
}
V_8 -> V_52 = V_48 -> V_33 ;
if ( V_48 -> V_33 ) {
for ( V_70 = 0 ; V_70 < V_8 -> V_240 ; V_70 ++ ) {
F_14 ( V_6 , V_8 -> V_53 [ V_70 ] , 0 ,
V_54 ,
V_48 -> V_55 [ 0 ] . V_56 ) ;
}
}
return 0 ;
}
static void F_135 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
int V_70 ;
for ( V_70 = 0 ; V_70 < V_8 -> V_69 . V_97 ; V_70 ++ ) {
T_1 V_27 = V_8 -> V_69 . V_98 [ V_70 ] ;
F_66 ( V_6 , V_27 , V_41 ) ;
}
}
static void F_136 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
int V_70 ;
for ( V_70 = 0 ; V_70 < V_8 -> V_69 . V_93 ; V_70 ++ ) {
T_1 V_101 ;
V_101 = V_8 -> V_69 . V_95 [ V_70 ] ;
if ( V_101 )
F_66 ( V_6 , V_101 , V_41 | V_276 ) ;
}
for ( V_70 = 0 ; V_70 < V_8 -> V_69 . V_186 ; V_70 ++ ) {
T_1 V_101 ;
V_101 = V_8 -> V_69 . V_199 [ V_70 ] ;
if ( V_101 )
F_66 ( V_6 , V_101 , V_41 ) ;
}
}
static int F_137 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
int V_70 , V_277 ;
if ( V_8 -> V_69 . V_178 != V_222 ||
V_8 -> V_69 . V_93 <= 1 )
return 0 ;
V_277 = 0 ;
for ( V_70 = 0 ; V_70 < V_8 -> V_69 . V_93 ; V_70 ++ ) {
T_1 V_27 = V_8 -> V_69 . V_95 [ V_70 ] ;
unsigned int V_68 = F_86 ( V_6 , V_27 ) ;
if ( F_138 ( V_68 ) & V_278 )
continue;
V_277 ++ ;
}
return ( V_277 > 1 ) ;
}
static int F_139 ( struct V_5 * V_6 , T_1 V_279 , T_1 V_280 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
int V_281 = 0 ;
int V_70 , V_25 ;
if ( ( V_25 = F_140 ( V_6 ,
& V_8 -> V_69 ,
V_8 -> V_260 ) ) < 0 )
return V_25 ;
if ( ! V_8 -> V_69 . V_97 )
return 0 ;
if ( F_137 ( V_6 ) ) {
F_101 ( L_37 ) ;
memcpy ( V_8 -> V_69 . V_199 , V_8 -> V_69 . V_98 ,
sizeof( V_8 -> V_69 . V_98 ) ) ;
V_8 -> V_69 . V_186 = V_8 -> V_69 . V_97 ;
memcpy ( V_8 -> V_69 . V_98 , V_8 -> V_69 . V_95 ,
sizeof( V_8 -> V_69 . V_95 ) ) ;
V_8 -> V_69 . V_97 = V_8 -> V_69 . V_93 ;
V_8 -> V_69 . V_178 = V_219 ;
V_8 -> V_69 . V_93 = 0 ;
V_281 = 1 ;
}
if ( V_8 -> V_69 . V_282 ) {
int V_283 = F_31 ( V_6 , V_8 -> V_69 . V_282 ) &
( V_80 | V_254 ) ;
T_2 V_203 = F_104 ( V_6 ,
V_8 -> V_69 . V_282 , V_283 ) ;
T_1 V_284 [ 1 ] ;
if ( F_95 ( V_6 ,
V_8 -> V_69 . V_282 , V_284 , 1 ) &&
F_95 ( V_6 , V_284 [ 0 ] ,
V_284 , 1 ) > 0 ) {
int V_79 = F_31 ( V_6 , V_284 [ 0 ] ) ;
int V_249 = F_96 ( V_79 ) ;
if ( V_249 == V_285 &&
! ( V_79 & V_220 ) )
V_8 -> V_59 = V_284 [ 0 ] ;
}
if ( V_283 ) {
T_1 V_27 = V_8 -> V_69 . V_282 ;
V_283 = ( V_283 & V_80 ) ? V_35 : V_262 ;
V_25 = F_84 ( V_8 , V_212 ,
L_38 ,
F_106 ( V_27 , 1 , 0 , V_283 ) ) ;
if ( V_25 < 0 )
return V_25 ;
if ( ( V_203 & V_209 )
>> V_210 ) {
V_25 = F_84 ( V_8 ,
V_211 ,
L_39 ,
F_106 ( V_27 , 1 , 0 , V_283 ) ) ;
if ( V_25 < 0 )
return V_25 ;
}
}
F_66 ( V_6 , V_8 -> V_69 . V_282 ,
V_41 ) ;
}
if ( ! V_8 -> V_30 . V_184 ) {
V_25 = F_97 ( V_6 ) ;
if ( V_25 < 0 )
return V_25 ;
V_25 = F_114 ( V_6 ,
& V_8 -> V_69 ) ;
if ( V_25 < 0 )
return V_25 ;
}
if ( V_8 -> V_234 > 0 ) {
V_25 = F_117 ( V_6 ,
V_8 -> V_234 ) ;
if ( V_25 < 0 )
return V_25 ;
}
#ifdef F_141
if ( V_8 -> V_286 > 0 ) {
T_1 V_27 = V_8 -> V_286 ;
unsigned int V_203 ;
V_25 = F_117 ( V_6 , V_27 ) ;
if ( V_25 < 0 )
return V_25 ;
V_25 = F_142 ( V_6 , V_27 ) ;
if ( V_25 < 0 )
return V_25 ;
if ( V_6 -> V_237 ) {
V_6 -> V_237 -> V_287 = V_8 -> V_288 ;
V_203 = F_104 ( V_6 , V_27 , V_35 ) ;
if ( ! ( V_203 & V_235 ) ) {
V_25 = F_121 ( V_6 ) ;
if ( V_25 < 0 )
return V_25 ;
}
}
}
#endif
V_25 = F_115 ( V_6 , & V_8 -> V_69 ) ;
if ( V_25 < 0 )
return V_25 ;
if ( V_281 ) {
memcpy ( V_8 -> V_69 . V_95 , V_8 -> V_69 . V_98 ,
sizeof( V_8 -> V_69 . V_95 ) ) ;
V_8 -> V_69 . V_93 = V_8 -> V_69 . V_97 ;
V_8 -> V_69 . V_178 = V_219 ;
V_8 -> V_69 . V_97 = 0 ;
}
if ( F_132 ( V_6 ) ) {
V_8 -> V_74 = 1 ;
V_8 -> V_131 = 1 ;
V_8 -> V_241 = 1 ;
V_8 -> V_240 = 1 ;
}
for ( V_70 = 0 ; V_70 < V_8 -> V_241 ; V_70 ++ ) {
V_25 = F_113 ( V_6 , V_8 -> V_242 [ V_70 ] ,
V_8 -> V_289 [ V_70 ] , V_70 ) ;
if ( V_25 < 0 )
return V_25 ;
}
V_25 = F_133 ( V_6 , & V_8 -> V_69 ) ;
if ( V_25 < 0 )
return V_25 ;
if ( V_8 -> V_59 > 0 ) {
V_25 = F_116 ( V_6 ) ;
if ( V_25 < 0 )
return V_25 ;
}
if ( V_8 -> V_258 > 0 && ! V_8 -> V_9 )
if ( ( V_25 = F_127 ( V_6 ,
& V_8 -> V_69 ) ) < 0 )
return V_25 ;
if ( V_8 -> V_240 > 0 ) {
V_25 = F_122 ( V_6 ) ;
if ( V_25 < 0 )
return V_25 ;
}
if ( V_8 -> V_78 > 0 ) {
V_25 = F_123 ( V_6 ) ;
if ( V_25 < 0 )
return V_25 ;
}
V_25 = F_89 ( V_8 ) ;
if ( V_25 < 0 )
return V_25 ;
V_8 -> V_30 . V_290 = V_8 -> V_30 . V_184 * 2 ;
if ( V_8 -> V_30 . V_290 > 2 )
V_8 -> V_291 = 1 ;
if ( V_8 -> V_69 . V_292 )
V_8 -> V_30 . V_31 = V_279 ;
if ( V_280 && V_8 -> V_69 . V_293 )
V_8 -> V_83 = V_280 ;
if ( V_8 -> V_164 . V_294 )
V_8 -> V_73 [ V_8 -> V_72 ++ ] = V_8 -> V_164 . V_294 ;
V_8 -> V_45 = & V_8 -> V_176 ;
if ( ! V_8 -> V_9 )
V_8 -> V_9 = & V_8 -> V_256 ;
V_8 -> V_19 = & V_8 -> V_24 ;
V_8 -> V_57 = & V_8 -> V_226 ;
return 1 ;
}
static int F_143 ( struct V_5 * V_6 ,
struct V_67 * V_68 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
T_1 V_101 = V_68 -> V_95 [ 0 ] ;
if ( ! V_101 )
return 0 ;
if ( F_111 ( V_6 , V_101 ) )
V_8 -> V_92 = 1 ;
return 0 ;
}
static int F_144 ( struct V_5 * V_6 ,
struct V_67 * V_68 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
int V_25 ;
T_1 V_295 = 0x0 ;
int V_70 ;
for ( V_70 = 0 ; V_70 < V_8 -> V_69 . V_186 && V_295 == 0x0 ; V_70 ++ ) {
T_1 V_101 = V_8 -> V_69 . V_199 [ V_70 ] ;
unsigned int V_79 = F_31 ( V_6 , V_101 ) ;
V_79 &= ( V_296 | V_80 ) ;
if ( V_79 == V_80 )
V_295 = V_101 ;
}
if ( V_295 == 0 && V_8 -> V_69 . V_186 == 0 ) {
for ( V_70 = 0 ; V_70 < V_8 -> V_69 . V_97 && V_295 == 0x0 ; V_70 ++ ) {
T_1 V_101 = V_8 -> V_69 . V_98 [ V_70 ] ;
unsigned int V_297 ;
V_297 = F_86 ( V_6 , V_101 ) ;
if ( F_130 ( V_297 ) == V_298 ) {
unsigned int V_79 = F_31 ( V_6 , V_101 ) ;
V_79 &= ( V_296 | V_80 ) ;
if ( V_79 == V_80 )
V_295 = V_101 ;
}
}
}
if ( V_295 ) {
V_25 = F_112 ( V_6 , L_25 , V_295 , 1 ) ;
if ( V_25 < 0 )
return V_25 ;
}
return 0 ;
}
static int F_145 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
int V_25 ;
if ( ( V_25 = F_140 ( V_6 , & V_8 -> V_69 , NULL ) ) < 0 )
return V_25 ;
if ( ( V_25 = F_133 ( V_6 , & V_8 -> V_69 ) ) < 0 )
return V_25 ;
if ( ( V_25 = F_143 ( V_6 , & V_8 -> V_69 ) ) < 0 )
return V_25 ;
if ( ( V_25 = F_144 ( V_6 , & V_8 -> V_69 ) ) < 0 )
return V_25 ;
if ( V_8 -> V_240 > 0 ) {
V_25 = F_122 ( V_6 ) ;
if ( V_25 < 0 )
return V_25 ;
}
V_25 = F_89 ( V_8 ) ;
if ( V_25 < 0 )
return V_25 ;
if ( V_8 -> V_69 . V_292 )
V_8 -> V_30 . V_31 = 0x05 ;
if ( V_8 -> V_69 . V_293 )
V_8 -> V_83 = 0x04 ;
if ( V_8 -> V_164 . V_294 )
V_8 -> V_73 [ V_8 -> V_72 ++ ] = V_8 -> V_164 . V_294 ;
V_8 -> V_45 = & V_8 -> V_176 ;
V_8 -> V_9 = & V_8 -> V_256 ;
return 1 ;
}
static void F_146 ( struct V_5 * V_6 , unsigned int V_299 ,
unsigned int V_300 , unsigned int V_301 )
{
unsigned int V_302 , V_303 , V_304 ;
V_302 = F_13 ( V_6 , V_6 -> V_64 , 0 ,
V_305 , 0 ) ;
V_302 = ( V_302 & ~ V_300 ) | ( V_301 & V_300 ) ;
V_303 = F_13 ( V_6 , V_6 -> V_64 , 0 ,
V_306 , 0 ) ;
V_303 |= V_299 ;
V_304 = F_13 ( V_6 , V_6 -> V_64 , 0 ,
V_307 , 0 ) ;
V_304 |= V_300 ;
F_59 ( V_6 , V_6 -> V_64 , 0 , 0x7e7 , 0 ) ;
F_59 ( V_6 , V_6 -> V_64 , 0 ,
V_308 , V_303 ) ;
F_13 ( V_6 , V_6 -> V_64 , 0 ,
V_309 , V_304 ) ;
F_44 ( 1 ) ;
F_13 ( V_6 , V_6 -> V_64 , 0 ,
V_310 , V_302 ) ;
}
static int F_40 ( struct V_5 * V_6 ,
T_1 V_27 , int type )
{
#ifdef F_147
int V_171 = F_86 ( V_6 , V_27 ) ;
int V_311 = F_128 ( V_171 ) ;
char V_124 [ 32 ] ;
int V_25 ;
if ( V_311 && V_311 != V_312 )
return 0 ;
snprintf ( V_124 , sizeof( V_124 ) , L_40 ,
F_148 ( V_171 ) ,
F_149 ( V_171 ) ,
F_150 ( V_171 ) ) ;
V_25 = F_151 ( V_6 , V_27 , type , V_124 ) ;
if ( V_25 < 0 )
return V_25 ;
#endif
return 0 ;
}
static int F_152 ( struct V_7 * V_8 , T_1 V_27 ,
unsigned char type , int V_301 )
{
struct V_313 * V_314 ;
F_79 ( & V_8 -> V_315 , sizeof( * V_314 ) , 32 ) ;
V_314 = F_80 ( & V_8 -> V_315 ) ;
if ( ! V_314 )
return - V_169 ;
V_314 -> V_27 = V_27 ;
V_314 -> type = type ;
V_314 -> V_316 = V_8 -> V_315 . V_317 ;
V_314 -> V_301 = V_301 ;
return V_314 -> V_316 ;
}
static struct V_313 * F_153 ( struct V_5 * V_6 ,
T_1 V_27 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
struct V_313 * V_314 = V_8 -> V_315 . V_294 ;
int V_70 ;
for ( V_70 = 0 ; V_70 < V_8 -> V_315 . V_317 ; V_70 ++ , V_314 ++ ) {
if ( V_314 -> V_27 == V_27 )
return V_314 ;
}
return NULL ;
}
static struct V_313 * F_154 ( struct V_5 * V_6 ,
unsigned char V_316 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
struct V_313 * V_314 = V_8 -> V_315 . V_294 ;
int V_70 ;
for ( V_70 = 0 ; V_70 < V_8 -> V_315 . V_317 ; V_70 ++ , V_314 ++ ) {
if ( V_314 -> V_316 == V_316 )
return V_314 ;
}
return NULL ;
}
static int F_155 ( struct V_5 * V_6 , T_1 V_27 ,
unsigned int type )
{
struct V_313 * V_314 ;
int V_316 ;
if ( ! F_111 ( V_6 , V_27 ) )
return 0 ;
V_314 = F_153 ( V_6 , V_27 ) ;
if ( V_314 ) {
if ( V_314 -> type != type )
return 0 ;
V_316 = V_314 -> V_316 ;
} else {
V_316 = F_152 ( V_6 -> V_8 , V_27 , type , 0 ) ;
if ( V_316 < 0 )
return 0 ;
}
F_14 ( V_6 , V_27 , 0 ,
V_318 ,
V_319 | V_316 ) ;
return 1 ;
}
static int F_156 ( struct V_67 * V_68 , T_1 V_27 )
{
int V_70 ;
for ( V_70 = 0 ; V_70 < V_68 -> V_93 ; V_70 ++ )
if ( V_68 -> V_95 [ V_70 ] == V_27 )
return 1 ;
return 0 ;
}
static void F_157 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
const T_1 * V_182 ;
for ( V_182 = V_8 -> V_320 ; * V_182 ; V_182 ++ )
if ( ! F_94 ( V_8 , * V_182 ) )
F_59 ( V_6 , * V_182 , 0 ,
V_116 , V_118 ) ;
}
static inline int F_158 ( struct V_5 * V_6 , const char * V_321 ,
int * V_322 )
{
const char * V_323 ;
V_323 = F_159 ( V_6 , V_321 ) ;
if ( V_323 ) {
unsigned long V_26 ;
if ( ! F_160 ( V_323 , 0 , & V_26 ) ) {
* V_322 = V_26 ;
return 1 ;
}
}
return 0 ;
}
static void F_161 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
int V_26 ;
V_26 = F_28 ( V_6 , L_41 ) ;
if ( V_26 >= 0 )
V_8 -> V_92 = V_26 ;
if ( F_158 ( V_6 , L_42 , & V_8 -> V_324 ) ) {
V_8 -> V_325 = V_8 -> V_84 = V_8 -> V_326 =
V_8 -> V_324 ;
}
if ( F_158 ( V_6 , L_43 , & V_8 -> V_84 ) )
V_8 -> V_324 &= V_8 -> V_324 ;
if ( F_158 ( V_6 , L_44 , & V_8 -> V_326 ) )
V_8 -> V_84 &= V_8 -> V_324 ;
if ( F_158 ( V_6 , L_45 , & V_8 -> V_325 ) )
V_8 -> V_325 &= V_8 -> V_324 ;
if ( F_158 ( V_6 , L_46 , & V_8 -> V_327 ) )
V_8 -> V_327 &= V_8 -> V_324 ;
V_26 = F_28 ( V_6 , L_47 ) ;
if ( V_26 >= 0 )
V_8 -> V_328 = V_26 ;
F_158 ( V_6 , L_48 , & V_8 -> V_329 ) ;
if ( F_158 ( V_6 , L_49 , & V_8 -> V_330 ) ) {
V_8 -> V_324 |= V_8 -> V_330 ;
V_8 -> V_84 |= V_8 -> V_330 ;
if ( V_8 -> V_329 )
V_8 -> V_326 |= V_8 -> V_330 ;
}
}
static int F_162 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
struct V_67 * V_68 = & V_8 -> V_69 ;
unsigned int V_331 ;
int V_70 ;
F_163 ( V_6 , V_8 -> V_332 ) ;
if ( V_8 -> V_115 )
for ( V_70 = 0 ; V_70 < V_8 -> V_131 ; V_70 ++ )
F_59 ( V_6 ,
V_8 -> V_113 [ V_70 ] , 0 ,
V_116 , V_118 ) ;
F_161 ( V_6 ) ;
V_331 = V_8 -> V_326 ;
if ( ! V_8 -> V_328 )
V_331 |= V_8 -> V_325 ;
F_146 ( V_6 , V_8 -> V_324 , V_8 -> V_84 , V_331 ) ;
if ( V_8 -> V_92 ) {
for ( V_70 = 0 ; V_70 < V_68 -> V_93 ; V_70 ++ ) {
T_1 V_27 = V_68 -> V_95 [ V_70 ] ;
F_155 ( V_6 , V_27 , V_333 ) ;
}
if ( V_68 -> V_178 == V_179 &&
V_68 -> V_186 > 0 ) {
for ( V_70 = 0 ; V_70 < V_68 -> V_97 ; V_70 ++ ) {
T_1 V_27 = V_68 -> V_98 [ V_70 ] ;
F_155 ( V_6 , V_27 , V_334 ) ;
}
}
F_66 ( V_6 , V_8 -> V_69 . V_98 [ 0 ] ,
V_41 ) ;
if ( V_68 -> V_95 [ 0 ] )
F_69 ( V_6 , V_68 -> V_95 [ 0 ] ) ;
else if ( V_68 -> V_98 [ 0 ] )
F_69 ( V_6 , V_68 -> V_98 [ 0 ] ) ;
} else {
F_135 ( V_6 ) ;
F_136 ( V_6 ) ;
for ( V_70 = 0 ; V_70 < V_68 -> V_93 ; V_70 ++ )
F_164 ( V_6 , V_68 -> V_95 [ V_70 ] , 1 ) ;
}
if ( V_8 -> V_74 ) {
if ( V_8 -> V_18 )
F_14 ( V_6 , V_8 -> V_18 [ 0 ] , 0 ,
V_54 , 0 ) ;
if ( F_155 ( V_6 , V_8 -> V_273 . V_101 , V_335 ) )
F_69 ( V_6 , V_8 -> V_273 . V_101 ) ;
if ( F_155 ( V_6 , V_8 -> V_275 . V_101 ,
V_335 ) )
F_69 ( V_6 , V_8 -> V_275 . V_101 ) ;
}
for ( V_70 = 0 ; V_70 < V_68 -> V_99 ; V_70 ++ ) {
T_1 V_27 = V_68 -> V_100 [ V_70 ] . V_101 ;
int type = V_68 -> V_100 [ V_70 ] . type ;
unsigned int V_157 , V_336 ;
if ( type == V_183 ) {
V_157 = F_64 ( V_6 , V_27 ) ;
V_157 |= V_40 ;
F_66 ( V_6 , V_27 , V_157 ) ;
} else {
V_157 = F_13 ( V_6 , V_27 , 0 ,
V_38 , 0 ) ;
if ( ! ( V_157 & V_40 ) ||
( V_157 & V_41 ) ) {
V_157 &= ~ V_41 ;
V_157 |= V_40 ;
F_66 ( V_6 , V_27 , V_157 ) ;
}
}
V_336 = F_86 ( V_6 , V_27 ) ;
if ( F_128 ( V_336 ) != V_312 ) {
if ( F_155 ( V_6 , V_27 , V_337 ) )
F_69 ( V_6 , V_27 ) ;
}
}
for ( V_70 = 0 ; V_70 < V_8 -> V_258 ; V_70 ++ )
F_66 ( V_6 , V_8 -> V_260 [ V_70 ] ,
V_40 ) ;
if ( V_68 -> V_338 [ 0 ] )
F_66 ( V_6 , V_68 -> V_338 [ 0 ] ,
V_41 ) ;
if ( V_68 -> V_293 )
F_66 ( V_6 , V_68 -> V_293 ,
V_40 ) ;
for ( V_70 = 0 ; V_70 < V_8 -> V_339 ; V_70 ++ ) {
T_1 V_27 = V_8 -> V_340 [ V_70 ] ;
int V_157 , V_171 ;
if ( ! V_8 -> V_92 ) {
F_164 ( V_6 , V_27 , 1 ) ;
continue;
}
if ( F_156 ( V_68 , V_27 ) )
continue;
V_157 = F_13 ( V_6 , V_27 , 0 ,
V_38 , 0 ) ;
if ( V_157 & V_40 ) {
F_164 ( V_6 , V_27 , 1 ) ;
continue;
}
V_171 = F_86 ( V_6 , V_27 ) ;
V_171 = F_128 ( V_171 ) ;
if ( V_171 != V_341 ) {
if ( V_171 != V_261 )
F_164 ( V_6 , V_27 , 1 ) ;
continue;
}
if ( F_155 ( V_6 , V_27 , V_342 ) )
F_69 ( V_6 , V_27 ) ;
}
if ( V_8 -> V_330 )
F_165 ( V_6 , 0x01 ) ;
if ( V_8 -> V_320 )
F_157 ( V_6 ) ;
return 0 ;
}
static void F_39 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
if ( V_8 -> V_164 . V_294 ) {
struct V_160 * V_343 = V_8 -> V_164 . V_294 ;
int V_70 ;
for ( V_70 = 0 ; V_70 < V_8 -> V_164 . V_317 ; V_70 ++ )
F_166 ( V_343 [ V_70 ] . V_124 ) ;
}
F_167 ( & V_8 -> V_164 ) ;
}
static void F_168 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
F_169 ( V_6 ) ;
if ( V_8 -> V_325 )
F_146 ( V_6 , V_8 -> V_324 ,
V_8 -> V_84 , V_8 -> V_326 &
~ V_8 -> V_325 ) ;
}
static void F_170 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
if ( ! V_8 )
return;
F_168 ( V_6 ) ;
F_171 ( V_6 ) ;
F_167 ( & V_8 -> V_315 ) ;
F_166 ( V_8 ) ;
F_172 ( V_6 ) ;
}
static void F_173 ( struct V_5 * V_6 , T_1 V_27 ,
unsigned int V_344 )
{
unsigned int V_345 , V_346 ;
V_346 = F_13 ( V_6 , V_27 ,
0 , V_38 , 0x00 ) ;
if ( V_346 & V_40 ) {
struct V_7 * V_8 = V_6 -> V_8 ;
if ( V_27 == V_8 -> V_153 || V_27 == V_8 -> V_152 )
return;
}
V_345 = V_346 ;
if ( V_344 & ( V_40 | V_41 ) )
V_346 &= ~ ( V_40 | V_41 ) ;
V_346 |= V_344 ;
if ( V_345 != V_346 )
F_14 ( V_6 , V_27 , 0 ,
V_43 ,
V_346 ) ;
}
static void F_174 ( struct V_5 * V_6 , T_1 V_27 ,
unsigned int V_344 )
{
unsigned int V_346 = F_13 ( V_6 , V_27 ,
0 , V_38 , 0x00 ) ;
if ( V_346 & V_344 )
F_14 ( V_6 , V_27 , 0 ,
V_43 ,
V_346 & ~ V_344 ) ;
}
static inline int F_175 ( struct V_5 * V_6 , T_1 V_27 )
{
if ( ! V_27 )
return 0 ;
return F_176 ( V_6 , V_27 ) ;
}
static void F_177 ( struct V_5 * V_6 ,
int V_347 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
struct V_67 * V_68 = & V_8 -> V_69 ;
int V_70 ;
for ( V_70 = 0 ; V_70 < V_68 -> V_97 ; V_70 ++ ) {
if ( V_347 )
break;
V_347 = F_175 ( V_6 , V_68 -> V_98 [ V_70 ] ) ;
if ( V_347 ) {
unsigned int V_157 ;
V_157 = F_13 ( V_6 ,
V_68 -> V_98 [ V_70 ] , 0 ,
V_38 , 0 ) ;
if ( V_157 & V_40 )
V_347 = 0 ;
}
}
if ( V_347 ) {
for ( V_70 = 0 ; V_70 < V_68 -> V_186 ; V_70 ++ )
F_174 ( V_6 , V_68 -> V_199 [ V_70 ] ,
V_41 ) ;
if ( V_8 -> V_325 && V_8 -> V_328 )
F_146 ( V_6 , V_8 -> V_324 ,
V_8 -> V_84 , V_8 -> V_326 &
~ V_8 -> V_325 ) ;
} else {
for ( V_70 = 0 ; V_70 < V_68 -> V_186 ; V_70 ++ )
F_173 ( V_6 , V_68 -> V_199 [ V_70 ] ,
V_41 ) ;
if ( V_8 -> V_325 && V_8 -> V_328 )
F_146 ( V_6 , V_8 -> V_324 ,
V_8 -> V_84 , V_8 -> V_326 |
V_8 -> V_325 ) ;
}
}
static int F_178 ( struct V_7 * V_8 , int V_70 )
{
struct V_67 * V_68 = & V_8 -> V_69 ;
if ( V_68 -> V_95 [ V_70 ] == V_8 -> V_153 )
return 1 ;
if ( V_68 -> V_95 [ V_70 ] == V_8 -> V_152 )
return 1 ;
if ( V_68 -> V_95 [ V_70 ] == V_8 -> V_150 )
return 1 ;
return 0 ;
}
static void F_179 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
struct V_67 * V_68 = & V_8 -> V_69 ;
int V_70 , V_347 ;
V_347 = 0 ;
if ( V_8 -> V_327 )
V_347 = ! ( F_13 ( V_6 , V_6 -> V_64 , 0 ,
V_305 , 0 ) & V_8 -> V_327 ) ;
for ( V_70 = 0 ; V_70 < V_68 -> V_93 ; V_70 ++ ) {
if ( V_347 )
break;
if ( F_178 ( V_8 , V_70 ) )
continue;
V_347 = F_175 ( V_6 , V_68 -> V_95 [ V_70 ] ) ;
if ( V_347 ) {
unsigned int V_157 ;
V_157 = F_13 ( V_6 , V_68 -> V_95 [ V_70 ] , 0 ,
V_38 , 0 ) ;
if ( V_157 & V_40 )
V_347 = 0 ;
}
}
if ( V_347 ) {
if ( V_8 -> V_150 )
F_174 ( V_6 , V_8 -> V_150 ,
V_41 ) ;
for ( V_70 = 0 ; V_70 < V_68 -> V_97 ; V_70 ++ )
F_174 ( V_6 , V_68 -> V_98 [ V_70 ] ,
V_41 ) ;
} else {
if ( V_8 -> V_150 )
F_173 ( V_6 , V_8 -> V_150 ,
V_41 ) ;
for ( V_70 = 0 ; V_70 < V_68 -> V_97 ; V_70 ++ )
F_173 ( V_6 , V_68 -> V_98 [ V_70 ] ,
V_41 ) ;
}
F_177 ( V_6 , V_347 ) ;
for ( V_70 = 0 ; V_70 < V_68 -> V_93 ; V_70 ++ ) {
unsigned int V_26 = V_41 | V_276 ;
if ( F_178 ( V_8 , V_70 ) )
continue;
if ( V_347 )
F_173 ( V_6 , V_68 -> V_95 [ V_70 ] , V_26 ) ;
#if 0
else
stac92xx_reset_pinctl(codec, cfg->hp_pins[i], val);
#endif
}
}
static void F_164 ( struct V_5 * V_6 , T_1 V_27 ,
int V_348 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
unsigned int V_49 , V_26 ;
for ( V_49 = 0 ; V_49 < V_8 -> V_339 ; V_49 ++ ) {
if ( V_8 -> V_340 [ V_49 ] == V_27 )
break;
}
if ( V_49 >= V_8 -> V_339 )
return;
if ( V_8 -> V_349 )
V_49 = V_8 -> V_349 [ V_49 ] ;
else
V_49 = 1 << V_49 ;
V_26 = F_13 ( V_6 , V_6 -> V_64 , 0 , 0x0fec , 0x0 ) & 0xff ;
if ( V_348 )
V_26 &= ~ V_49 ;
else
V_26 |= V_49 ;
F_59 ( V_6 , V_6 -> V_64 , 0 , 0x7ec , V_26 ) ;
}
static void F_180 ( struct V_5 * V_6 , T_1 V_27 )
{
F_164 ( V_6 , V_27 , F_175 ( V_6 , V_27 ) ) ;
}
static unsigned int F_181 ( struct V_5 * V_6 , int V_49 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
unsigned int V_68 ;
V_68 = F_86 ( V_6 , V_8 -> V_105 [ V_49 ] ) ;
return F_128 ( V_68 ) ;
}
static int F_182 ( struct V_5 * V_6 ,
const T_1 * V_350 , int V_351 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
int V_49 , V_352 ;
unsigned int V_171 ;
for ( V_352 = 0 ; V_352 < V_351 ; V_352 ++ ) {
for ( V_49 = 0 ; V_49 < V_8 -> V_104 ; V_49 ++ )
if ( V_8 -> V_105 [ V_49 ] == V_350 [ V_352 ] )
break;
if ( V_49 >= V_8 -> V_104 )
break;
V_171 = F_181 ( V_6 , V_49 ) ;
if ( V_171 == V_261 )
break;
}
return V_352 ;
}
static void F_183 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
struct V_270 * V_271 ;
if ( F_175 ( V_6 , V_8 -> V_273 . V_101 ) )
V_271 = & V_8 -> V_273 ;
else if ( F_175 ( V_6 , V_8 -> V_275 . V_101 ) )
V_271 = & V_8 -> V_275 ;
else
V_271 = & V_8 -> V_274 ;
if ( V_271 -> V_12 >= 0 )
F_14 ( V_6 , V_8 -> V_18 [ 0 ] , 0 ,
V_54 ,
V_271 -> V_12 ) ;
if ( V_271 -> V_272 >= 0 )
F_14 ( V_6 , V_8 -> V_53 [ 0 ] , 0 ,
V_54 ,
V_271 -> V_272 ) ;
}
static void F_69 ( struct V_5 * V_6 , T_1 V_27 )
{
struct V_313 * V_314 = F_153 ( V_6 , V_27 ) ;
if ( ! V_314 )
return;
V_6 -> V_353 . V_354 ( V_6 , ( unsigned ) V_314 -> V_316 << 26 ) ;
}
static void F_184 ( struct V_5 * V_6 , unsigned int V_355 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
struct V_313 * V_314 ;
int V_316 , V_301 ;
V_316 = ( V_355 >> 26 ) & 0x7f ;
V_314 = F_154 ( V_6 , V_316 ) ;
if ( ! V_314 )
return;
switch ( V_314 -> type ) {
case V_333 :
case V_334 :
F_179 ( V_6 ) ;
break;
case V_335 :
F_183 ( V_6 ) ;
break;
}
switch ( V_314 -> type ) {
case V_333 :
case V_334 :
case V_335 :
case V_337 :
case V_342 :
if ( V_8 -> V_339 > 0 )
F_180 ( V_6 , V_314 -> V_27 ) ;
F_185 ( V_6 , V_314 -> V_27 ) ;
switch ( V_6 -> V_356 ) {
case 0x103c308f :
if ( V_314 -> V_27 == 0xb ) {
int V_101 = V_40 ;
if ( F_175 ( V_6 , 0xa )
&& F_175 ( V_6 , 0xb ) )
V_101 |= V_144 ;
if ( ! F_175 ( V_6 , 0xb ) )
V_101 |= V_144 ;
F_66 ( V_6 , 0x0a , V_101 ) ;
}
}
break;
case V_357 :
V_301 = F_13 ( V_6 , V_6 -> V_64 , 0 ,
V_305 , 0 ) ;
F_59 ( V_6 , V_6 -> V_64 , 0 , 0x7e0 ,
! ! ( V_301 & ( 1 << V_314 -> V_301 ) ) ) ;
break;
}
}
static void F_186 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
unsigned int V_331 ;
if ( V_8 -> V_330 )
return;
V_331 = F_187 ( V_6 , V_6 -> V_64 , V_358 ) ;
V_331 &= V_359 ;
if ( V_331 > 3 )
V_8 -> V_330 = 0x08 ;
else
V_8 -> V_330 = 0x01 ;
}
static int F_188 ( struct V_5 * V_6 , int V_360 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
const struct V_361 * V_362 = NULL ;
if ( ( V_6 -> V_356 >> 16 ) == V_363 ) {
while ( ( V_362 = F_189 ( V_364 ,
NULL , V_362 ) ) ) {
if ( sscanf ( V_362 -> V_124 , L_50 ,
& V_8 -> V_329 ,
& V_8 -> V_330 ) == 2 ) {
V_8 -> V_330 = 1 << V_8 -> V_330 ;
return 1 ;
}
if ( sscanf ( V_362 -> V_124 , L_51 ,
& V_8 -> V_329 ) == 1 ) {
F_186 ( V_6 ) ;
return 1 ;
}
}
if ( ! F_190 ( V_6 -> V_356 ) ) {
F_186 ( V_6 ) ;
V_8 -> V_329 = V_360 ;
return 1 ;
}
}
return 0 ;
}
static int F_190 ( T_2 V_356 )
{
switch ( V_356 ) {
case 0x103c1520 :
case 0x103c1521 :
case 0x103c1523 :
case 0x103c1524 :
case 0x103c1525 :
case 0x103c1722 :
case 0x103c1723 :
case 0x103c1724 :
case 0x103c1725 :
case 0x103c1726 :
case 0x103c1727 :
case 0x103c1728 :
case 0x103c1729 :
case 0x103c172a :
case 0x103c172b :
case 0x103c307e :
case 0x103c307f :
case 0x103c3080 :
case 0x103c3081 :
case 0x103c7007 :
case 0x103c7008 :
return 1 ;
}
return 0 ;
}
static void F_191 ( struct V_365 * V_366 ,
struct V_5 * V_6 , T_1 V_27 )
{
if ( V_27 == V_6 -> V_64 )
F_192 ( V_366 , L_52 ,
F_13 ( V_6 , V_27 , 0 , 0x0fec , 0x0 ) ) ;
}
static void F_193 ( struct V_365 * V_366 ,
struct V_5 * V_6 ,
unsigned int V_367 )
{
F_192 ( V_366 , L_53 ,
F_13 ( V_6 , V_6 -> V_64 , 0 , V_367 , 0 ) ) ;
}
static void F_194 ( struct V_365 * V_366 ,
struct V_5 * V_6 , T_1 V_27 )
{
F_191 ( V_366 , V_6 , V_27 ) ;
if ( V_27 == V_6 -> V_64 )
F_193 ( V_366 , V_6 , 0xfa0 ) ;
}
static void F_195 ( struct V_365 * V_366 ,
struct V_5 * V_6 , T_1 V_27 )
{
if ( V_27 == V_6 -> V_64 )
F_193 ( V_366 , V_6 , 0xfe0 ) ;
}
static void F_196 ( struct V_365 * V_366 ,
struct V_5 * V_6 , T_1 V_27 )
{
if ( V_27 == V_6 -> V_64 )
F_193 ( V_366 , V_6 , 0xfeb ) ;
}
static int F_197 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
F_162 ( V_6 ) ;
F_198 ( V_6 ) ;
F_199 ( V_6 ) ;
if ( V_8 -> V_92 ) {
if ( V_8 -> V_69 . V_95 [ 0 ] )
F_69 ( V_6 , V_8 -> V_69 . V_95 [ 0 ] ) ;
else if ( V_8 -> V_69 . V_98 [ 0 ] )
F_69 ( V_6 ,
V_8 -> V_69 . V_98 [ 0 ] ) ;
}
if ( V_8 -> V_330 )
F_165 ( V_6 , 0x01 ) ;
return 0 ;
}
static int F_200 ( struct V_5 * V_6 ,
T_1 V_27 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
int V_70 , V_368 = 1 ;
for ( V_70 = 0 ; V_70 < V_8 -> V_30 . V_184 ; V_70 ++ ) {
V_27 = V_8 -> V_30 . V_86 [ V_70 ] ;
if ( ! ( F_201 ( V_6 , V_27 , 0 , V_35 , 0 ) &
V_34 ) ) {
V_368 = 0 ;
break;
}
}
if ( V_368 )
V_8 -> V_326 &= ~ V_8 -> V_330 ;
else
V_8 -> V_326 |= V_8 -> V_330 ;
if ( ! V_8 -> V_329 ) {
V_8 -> V_326 ^= V_8 -> V_330 ;
}
F_146 ( V_6 , V_8 -> V_324 , V_8 -> V_84 , V_8 -> V_326 ) ;
return 0 ;
}
static int F_202 ( struct V_5 * V_6 , T_3 V_369 )
{
F_168 ( V_6 ) ;
return 0 ;
}
static int F_203 ( struct V_5 * V_6 )
{
struct V_7 * V_8 ;
int V_25 ;
V_8 = F_204 ( sizeof( * V_8 ) , V_165 ) ;
if ( V_8 == NULL )
return - V_169 ;
V_6 -> V_370 = 1 ;
V_6 -> V_8 = V_8 ;
V_8 -> V_288 = 1 ;
V_8 -> V_104 = F_109 ( V_371 ) ;
V_8 -> V_105 = V_371 ;
V_8 -> V_372 = F_205 ( V_6 , V_373 ,
V_374 ,
V_375 ) ;
if ( V_8 -> V_372 < 0 )
F_101 ( V_376 L_54 ,
V_6 -> V_377 ) ;
else
F_41 ( V_6 ,
V_378 [ V_8 -> V_372 ] ) ;
V_8 -> V_30 . V_290 = 2 ;
V_8 -> V_30 . V_184 = 1 ;
V_8 -> V_30 . V_86 = V_379 ;
V_8 -> V_113 = V_380 ;
V_8 -> V_53 = V_381 ;
V_8 -> V_240 = 1 ;
V_8 -> V_258 = 0 ;
V_8 -> V_131 = 1 ;
V_8 -> V_339 = 0 ;
if ( V_8 -> V_372 == V_382 ||
V_8 -> V_372 == V_383 ||
V_8 -> V_372 == V_384 )
V_8 -> V_332 = V_385 ;
else
V_8 -> V_332 = V_386 ;
V_8 -> V_71 = V_387 ;
if ( V_8 -> V_372 == V_388 ) {
V_8 -> V_324 = V_8 -> V_84 = 0x09 ;
V_8 -> V_326 = 0x00 ;
}
V_25 = F_145 ( V_6 ) ;
if ( V_25 < 0 ) {
F_170 ( V_6 ) ;
return V_25 ;
}
if ( V_8 -> V_372 == V_388 )
V_8 -> V_92 = 0 ;
V_6 -> V_353 = V_389 ;
return 0 ;
}
static int F_206 ( struct V_5 * V_6 )
{
struct V_7 * V_8 ;
int V_25 ;
V_8 = F_204 ( sizeof( * V_8 ) , V_165 ) ;
if ( V_8 == NULL )
return - V_169 ;
V_6 -> V_370 = 1 ;
V_6 -> V_8 = V_8 ;
V_8 -> V_288 = 1 ;
V_8 -> V_104 = F_109 ( V_390 ) ;
V_8 -> V_105 = V_390 ;
V_8 -> V_372 = F_207 ( V_6 ,
V_391 ,
V_392 ,
V_393 ) ;
if ( V_8 -> V_372 < 0 )
V_8 -> V_372 = F_205 ( V_6 ,
V_391 ,
V_392 ,
V_394 ) ;
V_395:
if ( V_8 -> V_372 < 0 )
F_101 ( V_376 L_54 ,
V_6 -> V_377 ) ;
else
F_41 ( V_6 ,
V_396 [ V_8 -> V_372 ] ) ;
V_8 -> V_30 . V_290 = 2 ;
V_8 -> V_30 . V_184 = 1 ;
V_8 -> V_30 . V_86 = V_397 ;
V_8 -> V_113 = V_398 ;
V_8 -> V_53 = V_399 ;
V_8 -> V_240 = 1 ;
V_8 -> V_131 = 1 ;
V_8 -> V_339 = 0 ;
switch ( V_6 -> V_400 ) {
case 0x83847632 :
case 0x83847633 :
case 0x83847636 :
case 0x83847637 :
V_8 -> V_258 = V_401 ;
V_8 -> V_260 = V_402 ;
V_8 -> V_75 = F_109 ( V_403 ) ;
V_8 -> V_18 = V_403 ;
break;
default:
V_8 -> V_258 = 0 ;
break;
}
V_8 -> V_332 = V_404 ;
V_8 -> V_71 = V_405 ;
V_8 -> V_241 = 1 ;
V_8 -> V_242 = V_406 ;
V_8 -> V_289 = V_407 ;
V_25 = F_139 ( V_6 , 0x8 , 0x7 ) ;
if ( ! V_25 ) {
if ( V_8 -> V_372 < 0 ) {
F_107 ( V_213 L_55
L_56 ) ;
V_8 -> V_372 = V_408 ;
goto V_395;
}
V_25 = - V_231 ;
}
if ( V_25 < 0 ) {
F_170 ( V_6 ) ;
return V_25 ;
}
V_6 -> V_353 = V_389 ;
return 0 ;
}
static int F_208 ( struct V_5 * V_6 )
{
struct V_7 * V_8 ;
T_1 V_190 [ V_409 + 2 ] ;
int V_25 = 0 ;
int V_184 ;
V_8 = F_204 ( sizeof( * V_8 ) , V_165 ) ;
if ( V_8 == NULL )
return - V_169 ;
V_6 -> V_370 = 1 ;
V_6 -> V_8 = V_8 ;
V_8 -> V_288 = 0 ;
V_6 -> V_32 = V_410 ;
V_8 -> V_104 = F_109 ( V_411 ) ;
V_8 -> V_105 = V_411 ;
V_8 -> V_372 = F_205 ( V_6 ,
V_412 ,
V_413 ,
V_414 ) ;
if ( V_8 -> V_372 < 0 )
V_8 -> V_372 =
F_207 ( V_6 ,
V_412 , V_413 ,
V_415 ) ;
V_395:
if ( V_8 -> V_372 < 0 )
F_101 ( V_376 L_54 ,
V_6 -> V_377 ) ;
else
F_41 ( V_6 ,
V_416 [ V_8 -> V_372 ] ) ;
V_184 = F_95 ( V_6 , 0x0a ,
V_190 , V_409 + 2 ) - 1 ;
if ( V_184 < 3 || V_184 > 5 ) {
F_107 ( V_213 L_57
L_58 ) ;
V_184 = V_409 ;
}
V_8 -> V_332 = V_417 ;
switch ( V_184 ) {
case 0x3 :
V_8 -> V_91 = V_418 ;
break;
case 0x4 :
V_8 -> V_91 = V_419 ;
break;
case 0x5 :
V_8 -> V_91 = V_420 ;
break;
}
V_8 -> V_30 . V_86 = V_8 -> V_86 ;
V_8 -> V_61 = 0x01 ;
V_8 -> V_66 = 8 ;
V_8 -> V_286 = 0x1c ;
V_8 -> V_53 = V_421 ;
V_8 -> V_113 = V_422 ;
V_8 -> V_260 = V_423 ;
V_8 -> V_18 = V_424 ;
V_8 -> V_28 = V_425 ;
V_8 -> V_240 = F_109 ( V_421 ) ;
V_8 -> V_131 = F_109 ( V_422 ) ;
V_8 -> V_75 = F_109 ( V_424 ) ;
V_8 -> V_241 = V_426 ;
V_8 -> V_242 = V_427 ;
V_8 -> V_289 = V_428 ;
switch ( V_8 -> V_372 ) {
case V_429 :
V_8 -> V_332 = V_430 ;
case V_431 :
case V_432 :
case V_433 :
V_8 -> V_78 = 0 ;
V_8 -> V_328 = 0 ;
switch ( V_8 -> V_372 ) {
case V_431 :
F_42 ( V_6 , 0x0b , 0x90A70170 ) ;
V_8 -> V_258 = 0 ;
break;
case V_432 :
F_42 ( V_6 , 0x13 , 0x90A60160 ) ;
V_8 -> V_258 = 1 ;
break;
case V_433 :
F_42 ( V_6 , 0x0b , 0x90A70170 ) ;
F_42 ( V_6 , 0x13 , 0x90A60160 ) ;
V_8 -> V_258 = 1 ;
break;
}
break;
case V_434 :
V_8 -> V_258 = V_435 ;
V_8 -> V_78 = F_109 ( V_425 ) ;
V_8 -> V_328 = 0 ;
break;
default:
V_8 -> V_258 = V_435 ;
V_8 -> V_78 = F_109 ( V_425 ) ;
V_8 -> V_328 = 1 ;
break;
}
if ( V_8 -> V_372 != V_436 ) {
V_8 -> V_325 = V_8 -> V_324 = V_8 -> V_84 = 0x1 ;
V_8 -> V_326 = 0x01 ;
}
V_8 -> V_339 = F_109 ( V_437 ) ;
V_8 -> V_340 = V_437 ;
V_25 = F_139 ( V_6 , 0x25 , 0x27 ) ;
if ( ! V_25 ) {
if ( V_8 -> V_372 < 0 ) {
F_107 ( V_213 L_55
L_56 ) ;
V_8 -> V_372 = V_436 ;
goto V_395;
}
V_25 = - V_231 ;
}
if ( V_25 < 0 ) {
F_170 ( V_6 ) ;
return V_25 ;
}
if ( V_8 -> V_372 == V_438 )
V_8 -> V_92 = 0 ;
V_6 -> V_353 = V_389 ;
V_6 -> V_439 = F_194 ;
return 0 ;
}
static int F_209 ( struct V_5 * V_6 )
{
if ( V_6 -> V_400 != 0x111d7605 &&
V_6 -> V_400 != 0x111d76d1 )
return 0 ;
switch ( V_6 -> V_356 ) {
case 0x103c1618 :
case 0x103c1619 :
case 0x103c161a :
case 0x103c161b :
case 0x103c161c :
case 0x103c161d :
case 0x103c161e :
case 0x103c161f :
case 0x103c162a :
case 0x103c162b :
case 0x103c1630 :
case 0x103c1631 :
case 0x103c1633 :
case 0x103c1634 :
case 0x103c1635 :
case 0x103c3587 :
case 0x103c3588 :
case 0x103c3589 :
case 0x103c358a :
case 0x103c3667 :
case 0x103c3668 :
case 0x103c3669 :
return 1 ;
}
return 0 ;
}
static void F_210 ( struct V_5 * V_6 , T_1 V_27 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
unsigned int V_171 = F_86 ( V_6 , V_27 ) ;
int V_70 ;
V_8 -> V_440 [ V_8 -> V_441 ] = V_27 ;
V_8 -> V_441 ++ ;
if ( F_130 ( V_171 ) == V_266 &&
F_128 ( V_171 ) != V_261 ) {
for ( V_70 = 0 ; V_70 < F_109 ( V_442 ) ; V_70 ++ ) {
if ( V_27 == V_442 [ V_70 ] ) {
V_8 -> V_443 [ V_8 -> V_444 ] = V_27 ;
V_8 -> V_444 ++ ;
}
}
}
}
static void F_211 ( struct V_5 * V_6 , T_1 V_27 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
V_8 -> V_445 [ V_8 -> V_446 ] = V_27 ;
V_8 -> V_446 ++ ;
}
static void F_212 ( struct V_5 * V_6 , T_1 V_27 )
{
int V_70 , V_188 ;
struct V_7 * V_8 = V_6 -> V_8 ;
for ( V_70 = 0 ; V_70 < V_8 -> V_446 ; V_70 ++ ) {
if ( F_125 ( V_6 ,
V_8 -> V_445 [ V_70 ] , V_27 ) >= 0 ) {
if ( ! V_8 -> V_447 [ V_70 ] ) {
V_8 -> V_447 [ V_70 ] = V_27 ;
V_8 -> V_448 [ V_70 ] = F_106 ( V_27 ,
3 , 0 , V_35 ) ;
}
for ( V_188 = 0 ; V_188 < V_8 -> V_444 ; V_188 ++ ) {
if ( F_125 ( V_6 , V_27 ,
V_8 -> V_443 [ V_188 ] ) >= 0 ) {
if ( ! V_8 -> V_449 [ V_70 ] )
V_8 -> V_449 [ V_70 ] = V_27 ;
break;
}
}
break;
}
}
}
static void F_213 ( struct V_5 * V_6 )
{
T_1 V_27 , V_450 ;
unsigned int V_218 , V_249 ;
struct V_7 * V_8 = V_6 -> V_8 ;
V_450 = V_6 -> V_451 + V_6 -> V_452 ;
for ( V_27 = V_6 -> V_451 ; V_27 < V_450 ; V_27 ++ ) {
V_218 = F_31 ( V_6 , V_27 ) ;
V_249 = F_96 ( V_218 ) ;
if ( V_249 == V_250 )
F_210 ( V_6 , V_27 ) ;
if ( V_249 == V_453 && ! ( V_218 & V_194 ) )
F_211 ( V_6 , V_27 ) ;
}
for ( V_27 = V_6 -> V_451 ; V_27 < V_450 ; V_27 ++ ) {
V_218 = F_31 ( V_6 , V_27 ) ;
V_249 = F_96 ( V_218 ) ;
if ( V_249 == V_285 )
F_212 ( V_6 , V_27 ) ;
}
V_8 -> V_105 = V_8 -> V_440 ;
V_8 -> V_104 = V_8 -> V_441 ;
V_8 -> V_113 = V_8 -> V_445 ;
V_8 -> V_131 = V_8 -> V_446 ;
V_8 -> V_242 = V_8 -> V_448 ;
V_8 -> V_289 = V_8 -> V_448 ;
V_8 -> V_241 = V_8 -> V_446 ;
V_8 -> V_53 = V_8 -> V_447 ;
V_8 -> V_240 = V_8 -> V_446 ;
V_8 -> V_18 = V_8 -> V_449 ;
V_8 -> V_75 = V_8 -> V_446 ;
V_8 -> V_260 = V_8 -> V_443 ;
V_8 -> V_258 = V_8 -> V_444 ;
}
static int F_214 ( struct V_5 * V_6 )
{
struct V_7 * V_8 ;
T_1 V_190 [ V_454 + 1 ] ;
int V_25 ;
int V_184 ;
V_8 = F_204 ( sizeof( * V_8 ) , V_165 ) ;
if ( V_8 == NULL )
return - V_169 ;
if ( F_209 ( V_6 ) ) {
F_42 ( V_6 , 0xa , 0x2101201f ) ;
F_42 ( V_6 , 0xf , 0x2181205e ) ;
}
F_14 ( V_6 , V_6 -> V_64 , 0 , 0x7EC , 0 ) ;
F_14 ( V_6 , V_6 -> V_64 , 0 , 0x7ED , 0 ) ;
V_6 -> V_370 = 1 ;
V_6 -> V_8 = V_8 ;
F_213 ( V_6 ) ;
V_8 -> V_288 = 0 ;
V_6 -> V_32 = V_455 ;
V_8 -> V_286 = 0x21 ;
V_8 -> V_340 = V_456 ;
V_8 -> V_349 = V_457 ;
V_8 -> V_339 = F_109 ( V_456 ) ;
V_8 -> V_30 . V_86 = V_8 -> V_86 ;
V_8 -> V_332 = V_458 ;
V_8 -> V_372 = F_205 ( V_6 ,
V_459 ,
V_460 ,
V_461 ) ;
V_395:
if ( V_8 -> V_372 < 0 )
F_101 ( V_376 L_54 ,
V_6 -> V_377 ) ;
else
F_41 ( V_6 ,
V_462 [ V_8 -> V_372 ] ) ;
switch ( V_6 -> V_400 ) {
case 0x111d76d1 :
case 0x111d76d9 :
case 0x111d76e5 :
case 0x111d7666 :
case 0x111d7667 :
case 0x111d7668 :
case 0x111d7669 :
case 0x111d76e3 :
case 0x111d7604 :
case 0x111d76d4 :
case 0x111d7605 :
case 0x111d76d5 :
case 0x111d76e7 :
if ( V_8 -> V_372 == V_463 )
break;
V_8 -> V_339 = 0 ;
break;
}
V_6 -> V_353 = V_389 ;
if ( F_188 ( V_6 , 0 ) )
F_102 ( L_59 ,
V_8 -> V_330 ,
V_8 -> V_329 ) ;
#ifdef F_215
if ( V_8 -> V_330 ) {
V_8 -> V_324 |= V_8 -> V_330 ;
V_8 -> V_84 |= V_8 -> V_330 ;
V_8 -> V_326 |= V_8 -> V_330 ;
V_6 -> V_353 . V_464 =
F_200 ;
}
#endif
V_25 = F_139 ( V_6 , 0x1d , 0 ) ;
if ( ! V_25 ) {
if ( V_8 -> V_372 < 0 ) {
F_107 ( V_213 L_55
L_56 ) ;
V_8 -> V_372 = V_465 ;
goto V_395;
}
V_25 = - V_231 ;
}
if ( V_25 < 0 ) {
F_170 ( V_6 ) ;
return V_25 ;
}
V_184 = F_95 ( V_6 , 0xF ,
V_190 , V_454 + 1 ) - 1 ;
while ( V_184 >= 0 &&
( F_96 ( F_31 ( V_6 , V_190 [ V_184 ] ) )
!= V_193 ) )
V_184 -- ;
if ( V_184 >= 0 ) {
F_14 ( V_6 , 0xE , 0 ,
V_54 , V_184 ) ;
F_14 ( V_6 , 0xF , 0 ,
V_54 , V_184 ) ;
}
V_6 -> V_439 = F_191 ;
return 0 ;
}
static int F_216 ( struct V_5 * V_6 ,
T_1 V_466 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
int V_49 ;
for ( V_49 = 0 ; V_49 < V_8 -> V_104 ; V_49 ++ )
if ( V_8 -> V_105 [ V_49 ] == V_466 )
break;
if ( ( V_49 + 2 ) >= V_8 -> V_104 )
return 0 ;
if ( F_181 ( V_6 , V_49 + 1 ) != V_261 )
return 2 ;
if ( F_181 ( V_6 , V_49 + 2 ) != V_261 )
return 2 ;
if ( F_181 ( V_6 , V_49 ) != V_261 )
return 1 ;
else
return 0 ;
}
static int F_217 ( struct V_1 * V_2 ,
struct V_10 * V_11 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = V_6 -> V_8 ;
V_11 -> V_14 . integer . V_14 [ 0 ] = ! ! ( V_8 -> V_326 & 0x20 ) ;
return 0 ;
}
static int F_218 ( struct V_1 * V_2 ,
struct V_10 * V_11 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = V_6 -> V_8 ;
unsigned int V_326 ;
V_326 = ( V_8 -> V_326 & ~ 0x20 ) |
( V_11 -> V_14 . integer . V_14 [ 0 ] ? 0x20 : 0 ) ;
if ( V_326 == V_8 -> V_326 )
return 0 ;
V_8 -> V_326 = V_326 ;
F_146 ( V_6 , V_8 -> V_324 , V_8 -> V_84 , V_8 -> V_326 ) ;
return 1 ;
}
static int F_219 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
if ( ! F_78 ( V_8 , & V_467 ,
L_60 , 0 ) )
return - V_169 ;
V_8 -> V_324 |= 0x20 ;
V_8 -> V_84 |= 0x20 ;
V_8 -> V_326 |= 0x20 ;
return 0 ;
}
static int F_220 ( struct V_5 * V_6 )
{
struct V_7 * V_8 ;
const struct V_468 * V_469 = V_470 ;
unsigned int V_471 ;
int V_25 = 0 ;
V_8 = F_204 ( sizeof( * V_8 ) , V_165 ) ;
if ( V_8 == NULL )
return - V_169 ;
V_6 -> V_370 = 1 ;
V_6 -> V_8 = V_8 ;
V_8 -> V_288 = 0 ;
V_6 -> V_353 = V_389 ;
V_8 -> V_104 = V_472 ;
switch ( V_6 -> V_400 ) {
case 0x111d76b6 :
case 0x111d76b7 :
V_8 -> V_105 = V_473 ;
break;
case 0x111d7603 :
case 0x111d7608 :
V_8 -> V_104 -- ;
default:
V_8 -> V_105 = V_474 ;
}
V_8 -> V_339 = F_109 ( V_475 ) ;
V_8 -> V_372 = F_205 ( V_6 ,
V_476 ,
V_477 ,
V_478 ) ;
V_395:
if ( V_8 -> V_372 < 0 )
F_101 ( V_376 L_54 ,
V_6 -> V_377 ) ;
else
F_41 ( V_6 ,
V_479 [ V_8 -> V_372 ] ) ;
if ( V_8 -> V_372 != V_480 ) {
V_8 -> V_324 = 0x01 ;
V_8 -> V_84 = 0x01 ;
V_8 -> V_326 = 0x01 ;
}
V_8 -> V_260 = V_481 ;
V_8 -> V_18 = V_482 ;
V_8 -> V_241 = V_483 ;
V_8 -> V_242 = V_484 ;
V_8 -> V_289 = V_485 ;
switch ( V_6 -> V_400 ) {
case 0x111d76b6 :
case 0x111d76b7 :
V_469 ++ ;
case 0x111d76b4 :
case 0x111d76b5 :
V_8 -> V_332 = V_486 ;
V_6 -> V_32 = V_487 ;
V_8 -> V_258 = F_182 ( V_6 ,
V_481 ,
V_488 ) ;
break;
case 0x111d7608 :
switch ( V_8 -> V_372 ) {
case V_489 :
V_25 = F_152 ( V_8 , V_6 -> V_64 ,
V_357 , 0x02 ) ;
if ( V_25 < 0 )
return V_25 ;
F_14 ( V_6 , V_6 -> V_64 , 0 ,
V_490 , 0x02 ) ;
F_14 ( V_6 , V_6 -> V_64 , 0 ,
V_318 ,
V_319 | V_25 ) ;
V_8 -> V_324 |= 0x02 ;
break;
}
if ( ( V_6 -> V_491 & 0xf ) == 0 ||
( V_6 -> V_491 & 0xf ) == 1 )
V_8 -> V_110 = 40 ;
V_8 -> V_339 = 0 ;
V_8 -> V_332 = V_486 ;
V_469 ++ ;
F_42 ( V_6 , 0x0f , 0x40f000f0 ) ;
F_42 ( V_6 , 0x19 , 0x40f000f3 ) ;
V_8 -> V_260 = V_492 ;
V_8 -> V_258 = F_182 ( V_6 ,
V_492 ,
V_488 - 1 ) ;
break;
case 0x111d7603 :
if ( ( V_6 -> V_491 & 0xf ) == 1 )
V_8 -> V_110 = 40 ;
V_8 -> V_339 = 0 ;
default:
V_8 -> V_332 = V_486 ;
V_6 -> V_32 = V_487 ;
V_8 -> V_258 = F_182 ( V_6 ,
V_481 ,
V_488 ) ;
break;
}
if ( F_31 ( V_6 , 0xa ) & V_254 )
F_221 ( V_6 , V_469 ) ;
V_8 -> V_91 = V_493 ;
V_8 -> V_61 = 0x50 ;
V_8 -> V_66 = 0 ;
V_8 -> V_115 = 1 ;
V_8 -> V_286 = 0x26 ;
V_8 -> V_53 = V_494 ;
V_8 -> V_113 = V_495 ;
V_8 -> V_28 = V_496 ;
V_8 -> V_340 = V_475 ;
V_8 -> V_240 = F_109 ( V_494 ) ;
V_8 -> V_131 = F_109 ( V_495 ) ;
V_8 -> V_75 = F_109 ( V_482 ) ;
V_8 -> V_78 = F_216 ( V_6 , 0x1e ) ;
F_101 ( L_61 , V_8 -> V_372 ) ;
switch ( V_8 -> V_372 ) {
case V_489 :
F_42 ( V_6 , 0x0e , 0x01813040 ) ;
F_66 ( V_6 , 0x0e ,
V_40 | V_144 ) ;
case V_497 :
V_8 -> V_258 = 0 ;
V_8 -> V_78 = 0 ;
V_8 -> V_75 = 0 ;
break;
case V_498 :
case V_499 :
V_8 -> V_258 = 1 ;
V_8 -> V_78 = 0 ;
V_8 -> V_75 = 1 ;
break;
case V_500 :
V_8 -> V_258 = 1 ;
V_8 -> V_78 = 1 ;
V_8 -> V_75 = 1 ;
case V_501 :
V_8 -> V_330 = 0x01 ;
case V_502 :
F_42 ( V_6 , 0x0d , 0x90170010 ) ;
F_66 ( V_6 , 0x0d , V_41 ) ;
V_8 -> V_92 = 1 ;
break;
case V_503 :
V_8 -> V_258 = 1 ;
V_8 -> V_75 = 1 ;
V_8 -> V_78 = 1 ;
V_8 -> V_330 = 0x08 ;
break;
}
if ( F_190 ( V_6 -> V_356 ) ) {
V_471 = F_86 ( V_6 , 0x0f ) ;
if ( F_130 ( V_471 ) == V_504 ||
F_130 ( V_471 ) == V_298 ||
F_130 ( V_471 ) == V_505 ) {
V_471 = ( V_471 & ( ~ V_506 ) )
| ( V_505 <<
V_507 ) ;
V_471 = ( V_471 & ( ~ ( V_508
| V_509 ) ) )
| 0x1f ;
F_42 ( V_6 , 0x0f , V_471 ) ;
}
}
if ( F_188 ( V_6 , 1 ) )
F_102 ( L_59 ,
V_8 -> V_330 ,
V_8 -> V_329 ) ;
#ifdef F_215
if ( V_8 -> V_330 ) {
V_8 -> V_324 |= V_8 -> V_330 ;
V_8 -> V_84 |= V_8 -> V_330 ;
V_8 -> V_326 |= V_8 -> V_330 ;
V_6 -> V_353 . V_464 =
F_200 ;
}
#endif
V_8 -> V_30 . V_86 = V_8 -> V_86 ;
V_25 = F_139 ( V_6 , 0x21 , 0 ) ;
if ( ! V_25 ) {
if ( V_8 -> V_372 < 0 ) {
F_107 ( V_213 L_55
L_56 ) ;
V_8 -> V_372 = V_480 ;
goto V_395;
}
V_25 = - V_231 ;
}
if ( V_25 < 0 ) {
F_170 ( V_6 ) ;
return V_25 ;
}
if ( V_8 -> V_372 == V_501 ||
V_8 -> V_372 == V_502 ) {
unsigned int V_510 ;
V_510 = F_187 ( V_6 , 0x1 , V_358 ) ;
V_510 &= V_359 ;
if ( V_510 >= 6 )
F_219 ( V_6 ) ;
}
V_6 -> V_439 = F_194 ;
return 0 ;
}
static int F_222 ( struct V_5 * V_6 )
{
struct V_7 * V_8 ;
int V_25 ;
V_8 = F_204 ( sizeof( * V_8 ) , V_165 ) ;
if ( V_8 == NULL )
return - V_169 ;
V_6 -> V_370 = 1 ;
V_6 -> V_8 = V_8 ;
V_8 -> V_288 = 1 ;
V_8 -> V_104 = F_109 ( V_511 ) ;
V_8 -> V_105 = V_511 ;
V_8 -> V_372 = F_205 ( V_6 , V_512 ,
V_513 ,
V_514 ) ;
if ( V_8 -> V_372 == V_515 ) {
V_8 -> V_324 = V_8 -> V_84 = 0x03 ;
V_8 -> V_326 = 0x03 ;
F_107 ( V_376 L_62 , V_6 -> V_356 ) ;
switch ( V_6 -> V_356 ) {
case 0x106b0800 :
V_8 -> V_372 = V_516 ;
break;
case 0x106b0600 :
case 0x106b0700 :
V_8 -> V_372 = V_517 ;
break;
case 0x106b0e00 :
case 0x106b0f00 :
case 0x106b1600 :
case 0x106b1700 :
case 0x106b0200 :
case 0x106b1e00 :
V_8 -> V_372 = V_518 ;
break;
case 0x106b1a00 :
case 0x00000100 :
V_8 -> V_372 = V_519 ;
break;
case 0x106b0a00 :
case 0x106b2200 :
V_8 -> V_372 = V_520 ;
break;
default:
V_8 -> V_372 = V_518 ;
break;
}
}
V_395:
if ( V_8 -> V_372 < 0 )
F_101 ( V_376 L_54 ,
V_6 -> V_377 ) ;
else
F_41 ( V_6 ,
V_521 [ V_8 -> V_372 ] ) ;
V_8 -> V_113 = V_522 ;
V_8 -> V_53 = V_523 ;
V_8 -> V_240 = F_109 ( V_523 ) ;
V_8 -> V_131 = F_109 ( V_522 ) ;
V_8 -> V_258 = 0 ;
V_8 -> V_339 = 0 ;
V_8 -> V_332 = V_524 ;
V_8 -> V_241 = V_525 ;
V_8 -> V_242 = V_526 ;
V_8 -> V_289 = V_527 ;
V_8 -> V_30 . V_86 = V_8 -> V_86 ;
V_25 = F_139 ( V_6 , 0x08 , 0x09 ) ;
if ( ! V_25 ) {
if ( V_8 -> V_372 < 0 ) {
F_107 ( V_213 L_55
L_56 ) ;
V_8 -> V_372 = V_528 ;
goto V_395;
}
V_25 = - V_231 ;
}
if ( V_25 < 0 ) {
F_170 ( V_6 ) ;
return V_25 ;
}
V_6 -> V_353 = V_389 ;
F_223 ( V_6 , 0x12 , V_35 ,
( 0 << V_529 ) |
( 2 << V_210 ) |
( 0x27 << V_208 ) |
( 0 << V_236 ) ) ;
return 0 ;
}
static int F_224 ( struct V_5 * V_6 )
{
struct V_7 * V_8 ;
int V_25 ;
V_8 = F_204 ( sizeof( * V_8 ) , V_165 ) ;
if ( V_8 == NULL )
return - V_169 ;
V_6 -> V_370 = 1 ;
V_6 -> V_8 = V_8 ;
V_8 -> V_288 = 1 ;
V_6 -> V_32 = V_530 ;
V_8 -> V_104 = F_109 ( V_531 ) ;
V_8 -> V_105 = V_531 ;
V_8 -> V_372 = F_205 ( V_6 , V_532 ,
V_533 ,
V_534 ) ;
V_395:
if ( V_8 -> V_372 < 0 )
F_101 ( V_376 L_54 ,
V_6 -> V_377 ) ;
else
F_41 ( V_6 ,
V_535 [ V_8 -> V_372 ] ) ;
V_8 -> V_286 = 0x23 ;
V_8 -> V_113 = V_536 ;
V_8 -> V_131 = F_109 ( V_536 ) ;
V_8 -> V_53 = V_537 ;
V_8 -> V_240 = F_109 ( V_537 ) ;
V_8 -> V_28 = V_538 ;
V_8 -> V_78 = F_109 ( V_538 ) ;
V_8 -> V_245 = V_539 ;
V_8 -> V_320 = V_540 ;
V_8 -> V_30 . V_86 = V_8 -> V_86 ;
if ( V_8 -> V_372 != V_541 ) {
V_8 -> V_325 = V_8 -> V_324 = 0x01 ;
V_8 -> V_84 = V_8 -> V_326 = 0x01 ;
}
switch ( V_8 -> V_372 ) {
case V_542 :
case V_543 :
V_8 -> V_258 = 0 ;
V_8 -> V_332 = V_544 ;
break;
case V_545 :
switch ( V_6 -> V_356 ) {
case 0x10280209 :
case 0x1028022e :
F_42 ( V_6 , 0x21 , 0x01442070 ) ;
break;
}
F_42 ( V_6 , 0x0c , 0x90a79130 ) ;
F_42 ( V_6 , 0x0f , 0x0227011f ) ;
F_42 ( V_6 , 0x0e , 0x02a79130 ) ;
case V_546 :
if ( V_6 -> V_356 != 0x1028022f ) {
V_8 -> V_325 = V_8 -> V_324 = 0x04 ;
V_8 -> V_84 = V_8 -> V_326 = 0x04 ;
}
V_8 -> V_260 = V_547 ;
V_8 -> V_258 = V_548 ;
V_8 -> V_332 = V_549 ;
V_8 -> V_18 = V_550 ;
V_8 -> V_75 = F_109 ( V_550 ) ;
break;
case V_551 :
V_8 -> V_258 = 0 ;
V_8 -> V_332 = V_552 ;
break;
default:
V_8 -> V_258 = 0 ;
V_8 -> V_332 = V_553 ;
break;
}
V_8 -> V_241 = V_554 ;
V_8 -> V_242 = V_555 ;
V_8 -> V_289 = V_556 ;
V_8 -> V_339 = 0 ;
V_8 -> V_91 = V_557 ;
V_8 -> V_61 = 0x40 ;
V_8 -> V_66 = 0 ;
V_8 -> V_328 = 1 ;
V_25 = F_139 ( V_6 , 0x1e , 0x20 ) ;
if ( ! V_25 ) {
if ( V_8 -> V_372 < 0 ) {
F_107 ( V_213 L_55
L_56 ) ;
V_8 -> V_372 = V_541 ;
goto V_395;
}
V_25 = - V_231 ;
}
if ( V_25 < 0 ) {
F_170 ( V_6 ) ;
return V_25 ;
}
V_6 -> V_353 = V_389 ;
V_6 -> V_439 = F_196 ;
V_6 -> V_558 -> V_559 = 1 ;
if ( V_8 -> V_372 == V_560 )
V_8 -> V_92 = 0 ;
return 0 ;
}
static int F_225 ( struct V_5 * V_6 )
{
struct V_7 * V_8 ;
int V_25 ;
V_8 = F_204 ( sizeof( * V_8 ) , V_165 ) ;
if ( V_8 == NULL )
return - V_169 ;
V_6 -> V_370 = 1 ;
V_6 -> V_8 = V_8 ;
V_8 -> V_288 = 1 ;
V_8 -> V_104 = F_109 ( V_561 ) ;
V_8 -> V_105 = V_561 ;
V_8 -> V_372 = F_205 ( V_6 , V_562 ,
V_563 ,
V_564 ) ;
V_395:
if ( V_8 -> V_372 < 0 )
F_101 ( V_376 L_54 ,
V_6 -> V_377 ) ;
else
F_41 ( V_6 ,
V_565 [ V_8 -> V_372 ] ) ;
V_8 -> V_286 = 0x23 ;
V_8 -> V_113 = V_566 ;
V_8 -> V_131 = F_109 ( V_566 ) ;
V_8 -> V_53 = V_567 ;
V_8 -> V_240 = F_109 ( V_567 ) ;
V_8 -> V_28 = V_568 ;
V_8 -> V_78 = F_109 ( V_568 ) ;
V_8 -> V_260 = V_569 ;
V_8 -> V_258 = V_570 ;
V_8 -> V_18 = V_571 ;
V_8 -> V_75 = F_109 ( V_571 ) ;
V_8 -> V_339 = 0 ;
V_8 -> V_332 = V_572 ;
V_8 -> V_91 = V_573 ;
V_8 -> V_241 = V_574 ;
V_8 -> V_242 = V_575 ;
V_8 -> V_289 = V_576 ;
V_8 -> V_61 = 0x40 ;
V_8 -> V_66 = 0 ;
if ( V_8 -> V_372 != V_577 )
V_8 -> V_328 = 1 ;
V_8 -> V_30 . V_86 = V_8 -> V_86 ;
switch ( V_8 -> V_372 ) {
case V_578 :
F_42 ( V_6 , 0x1f , 0x01441030 ) ;
F_42 ( V_6 , 0x20 , 0x1c410030 ) ;
V_25 = F_152 ( V_8 , V_6 -> V_64 , V_357 , 0x01 ) ;
if ( V_25 < 0 )
return V_25 ;
F_14 ( V_6 , V_6 -> V_64 , 0 ,
V_490 , 0x10 ) ;
F_14 ( V_6 , V_6 -> V_64 , 0 ,
V_318 ,
V_319 | V_25 ) ;
V_8 -> V_84 = 0x0b ;
V_8 -> V_325 = 0x01 ;
V_8 -> V_324 = 0x1b ;
V_8 -> V_327 = 0x10 ;
V_8 -> V_326 = 0x01 ;
break;
case V_579 :
break;
default:
V_8 -> V_325 = V_8 -> V_324 = V_8 -> V_84 = 0x1 ;
V_8 -> V_326 = 0x01 ;
break;
}
V_25 = F_139 ( V_6 , 0x1f , 0x20 ) ;
if ( ! V_25 ) {
if ( V_8 -> V_372 < 0 ) {
F_107 ( V_213 L_55
L_56 ) ;
V_8 -> V_372 = V_579 ;
goto V_395;
}
V_25 = - V_231 ;
}
if ( V_25 < 0 ) {
F_170 ( V_6 ) ;
return V_25 ;
}
V_6 -> V_353 = V_389 ;
V_6 -> V_439 = F_195 ;
return 0 ;
}
static int F_226 ( struct V_5 * V_6 )
{
struct V_7 * V_8 ;
int V_25 ;
V_8 = F_204 ( sizeof( * V_8 ) , V_165 ) ;
if ( V_8 == NULL )
return - V_169 ;
V_6 -> V_370 = 1 ;
V_6 -> V_8 = V_8 ;
V_8 -> V_288 = 1 ;
V_8 -> V_104 = F_109 ( V_580 ) ;
V_8 -> V_105 = V_580 ;
V_8 -> V_372 = F_205 ( V_6 , V_581 ,
V_582 ,
V_583 ) ;
if ( V_8 -> V_372 < 0 )
F_101 ( V_376 L_54 ,
V_6 -> V_377 ) ;
else
F_41 ( V_6 ,
V_584 [ V_8 -> V_372 ] ) ;
V_8 -> V_30 . V_86 = V_8 -> V_86 ;
V_8 -> V_131 = F_109 ( V_585 ) ;
V_8 -> V_113 = V_585 ;
V_8 -> V_240 = F_109 ( V_586 ) ;
V_8 -> V_53 = V_586 ;
V_8 -> V_332 = V_587 ;
V_8 -> V_241 = 1 ;
V_8 -> V_242 = V_588 ;
V_8 -> V_289 = V_589 ;
V_25 = F_139 ( V_6 , 0x10 , 0x12 ) ;
if ( V_25 < 0 ) {
F_170 ( V_6 ) ;
return - V_231 ;
}
V_8 -> V_45 = & V_8 -> V_176 ;
V_6 -> V_353 = V_389 ;
return 0 ;
}
static int T_4 F_227 ( void )
{
return F_228 ( & V_590 ) ;
}
static void T_5 F_229 ( void )
{
F_230 ( & V_590 ) ;
}
