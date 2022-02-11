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
static int F_12 ( struct V_5 * V_6 ,
T_1 V_27 , unsigned int V_36 )
{
int error , V_37 ;
F_13 ( L_1 , V_38 , V_27 , V_36 ) ;
V_37 = F_14 ( V_6 , V_27 , 0 ,
V_39 , 0 ) ;
if ( V_37 < 0 )
return V_37 ;
V_37 &= 0xff ;
V_37 &= ~ V_40 ;
V_37 |= ( V_36 & V_40 ) ;
error = F_15 ( V_6 , V_27 , 0 ,
V_41 , V_37 ) ;
if ( error < 0 )
return error ;
return 1 ;
}
static unsigned int F_16 ( struct V_5 * V_6 ,
T_1 V_27 , unsigned int V_36 )
{
int error ;
unsigned int V_42 ;
V_42 = F_14 ( V_6 , V_27 , 0 ,
V_39 , 0 ) ;
V_42 &= 0xff ;
V_42 &= ~ ( V_40 | V_43 | V_44 ) ;
V_42 |= V_36 ;
if ( V_36 == V_45 )
V_42 |= V_44 ;
else
V_42 |= V_43 ;
error = F_15 ( V_6 , V_27 , 0 ,
V_41 , V_42 ) ;
if ( error < 0 )
return error ;
else
return 1 ;
}
static unsigned int F_17 ( struct V_5 * V_6 , T_1 V_27 )
{
unsigned int V_46 ;
V_46 = F_14 ( V_6 , V_27 , 0 ,
V_39 , 0 ) ;
V_46 &= V_40 ;
return V_46 ;
}
static int F_18 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = V_6 -> V_8 ;
return F_3 ( V_8 -> V_47 , V_4 ) ;
}
static int F_19 ( struct V_1 * V_2 , struct V_10 * V_11 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = V_6 -> V_8 ;
unsigned int V_48 = F_5 ( V_2 , & V_11 -> V_13 ) ;
V_11 -> V_14 . V_15 . V_16 [ 0 ] = V_8 -> V_49 [ V_48 ] ;
return 0 ;
}
static int F_20 ( struct V_1 * V_2 , struct V_10 * V_11 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = V_6 -> V_8 ;
unsigned int V_48 = F_5 ( V_2 , & V_11 -> V_13 ) ;
const struct V_22 * V_50 = V_8 -> V_47 ;
unsigned int V_51 , V_52 , V_53 ;
V_51 = V_11 -> V_14 . V_15 . V_16 [ 0 ] ;
if ( V_51 >= V_50 -> V_33 )
V_51 = V_50 -> V_33 - 1 ;
V_52 = V_8 -> V_49 [ V_48 ] ;
if ( V_52 == V_51 )
return 0 ;
if ( V_51 < V_8 -> V_54 ) {
F_15 ( V_6 , V_8 -> V_55 [ V_48 ] , 0 ,
V_56 ,
V_50 -> V_57 [ V_51 ] . V_58 ) ;
if ( V_52 >= V_8 -> V_54 &&
V_8 -> V_55 [ V_48 ] != V_8 -> V_18 [ V_48 ] ) {
V_50 = V_8 -> V_9 ;
F_15 ( V_6 ,
V_8 -> V_18 [ V_48 ] , 0 ,
V_56 ,
V_50 -> V_57 [ 0 ] . V_58 ) ;
}
} else {
V_50 = V_8 -> V_9 ;
V_53 = V_51 - V_8 -> V_54 + 1 ;
F_15 ( V_6 , V_8 -> V_18 [ V_48 ] , 0 ,
V_56 ,
V_50 -> V_57 [ V_53 ] . V_58 ) ;
}
V_8 -> V_49 [ V_48 ] = V_51 ;
return 1 ;
}
static int F_21 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = V_6 -> V_8 ;
return F_3 ( V_8 -> V_59 , V_4 ) ;
}
static int F_22 ( struct V_1 * V_2 ,
struct V_10 * V_11 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = V_6 -> V_8 ;
V_11 -> V_14 . V_15 . V_16 [ 0 ] = V_8 -> V_60 ;
return 0 ;
}
static int F_23 ( struct V_1 * V_2 ,
struct V_10 * V_11 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = V_6 -> V_8 ;
return F_7 ( V_6 , V_8 -> V_59 , V_11 ,
V_8 -> V_61 , & V_8 -> V_60 ) ;
}
static int F_24 ( struct V_1 * V_2 ,
struct V_10 * V_11 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
unsigned int V_51 = F_5 ( V_2 , & V_11 -> V_13 ) ;
struct V_7 * V_8 = V_6 -> V_8 ;
V_11 -> V_14 . integer . V_14 [ 0 ] = ! ! ( V_8 -> V_62 &
( V_8 -> V_63 << V_51 ) ) ;
return 0 ;
}
static int F_25 ( struct V_1 * V_2 ,
struct V_10 * V_11 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = V_6 -> V_8 ;
unsigned int V_51 = F_5 ( V_2 , & V_11 -> V_13 ) ;
unsigned int V_64 ;
unsigned int V_26 , V_65 ;
V_65 = V_8 -> V_63 << V_51 ;
if ( V_11 -> V_14 . integer . V_14 [ 0 ] )
V_26 = V_8 -> V_62 | V_65 ;
else
V_26 = V_8 -> V_62 & ~ V_65 ;
if ( V_8 -> V_62 == V_26 )
return 0 ;
V_8 -> V_62 = V_26 ;
V_64 = F_14 ( V_6 , V_6 -> V_66 , 0 ,
V_2 -> V_67 & 0xFFFF , 0x0 ) ;
V_64 >>= V_8 -> V_68 ;
if ( V_8 -> V_62 & V_65 ) {
F_26 ( V_6 ) ;
V_64 |= V_65 ;
} else {
F_27 ( V_6 ) ;
V_64 &= ~ V_65 ;
}
F_15 ( V_6 , V_6 -> V_66 , 0 ,
V_2 -> V_67 >> 16 , V_64 ) ;
return 1 ;
}
static int F_28 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
struct V_69 * V_70 = & V_8 -> V_71 ;
T_1 V_27 ;
int V_25 ;
int V_72 ;
if ( V_8 -> V_73 ) {
V_25 = F_29 ( V_6 , V_8 -> V_73 ) ;
if ( V_25 < 0 )
return V_25 ;
}
for ( V_72 = 0 ; V_72 < V_8 -> V_74 ; V_72 ++ ) {
V_25 = F_29 ( V_6 , V_8 -> V_75 [ V_72 ] ) ;
if ( V_25 < 0 )
return V_25 ;
}
if ( ! V_8 -> V_76 && V_8 -> V_77 > 0 &&
F_30 ( V_6 , L_2 ) == 1 ) {
V_78 . V_79 = V_8 -> V_77 ;
V_25 = F_31 ( V_6 , 0 ,
F_32 ( & V_78 , V_6 ) ) ;
if ( V_25 < 0 )
return V_25 ;
}
if ( V_8 -> V_80 > 0 ) {
int V_81 = F_33 ( V_6 , V_8 -> V_30 . V_31 ) ;
struct V_22 * V_23 = & V_8 -> V_24 ;
if ( V_81 & V_82 ) {
F_34 ( V_23 , L_3 , 0 , NULL ) ;
V_8 -> V_29 = 1 ;
}
V_83 . V_79 = V_8 -> V_80 ;
V_25 = F_31 ( V_6 , 0 ,
F_32 ( & V_83 , V_6 ) ) ;
if ( V_25 < 0 )
return V_25 ;
}
if ( V_8 -> V_30 . V_31 ) {
V_25 = F_35 ( V_6 ,
V_8 -> V_30 . V_31 ,
V_8 -> V_30 . V_31 ) ;
if ( V_25 < 0 )
return V_25 ;
V_25 = F_36 ( V_6 ,
& V_8 -> V_30 ) ;
if ( V_25 < 0 )
return V_25 ;
V_8 -> V_30 . V_84 = 1 ;
}
if ( V_8 -> V_85 && ! ( V_8 -> V_86 & 0x01 ) ) {
V_25 = F_37 ( V_6 , V_8 -> V_85 ) ;
if ( V_25 < 0 )
return V_25 ;
}
if ( ! F_38 ( V_6 , L_4 ) ) {
unsigned int V_87 [ 4 ] ;
F_39 ( V_6 , V_8 -> V_30 . V_88 [ 0 ] ,
V_35 , V_87 ) ;
V_87 [ 2 ] += V_87 [ 3 ] * V_8 -> V_89 ;
V_87 [ 3 ] |= V_90 ;
V_25 = F_40 ( V_6 , L_4 ,
V_87 , V_91 ) ;
if ( V_25 < 0 )
return V_25 ;
}
if ( ! F_38 ( V_6 , L_5 ) ) {
V_25 = F_40 ( V_6 , L_5 ,
NULL , V_92 ) ;
if ( V_25 < 0 )
return V_25 ;
}
if ( V_8 -> V_93 &&
F_30 ( V_6 , L_6 ) == 1 ) {
V_25 = F_29 ( V_6 , V_8 -> V_93 ) ;
if ( V_25 < 0 )
return V_25 ;
}
F_41 ( V_6 ) ;
if ( V_8 -> V_94 ) {
for ( V_72 = 0 ; V_72 < V_70 -> V_95 ; V_72 ++ ) {
int type = V_96 ;
V_27 = V_70 -> V_97 [ V_72 ] ;
if ( V_70 -> V_95 == V_72 )
type |= V_98 ;
V_25 = F_42 ( V_6 , V_27 , type ) ;
if ( V_25 < 0 )
return V_25 ;
}
}
for ( V_72 = 0 ; V_72 < V_70 -> V_99 ; V_72 ++ ) {
V_25 = F_42 ( V_6 , V_70 -> V_100 [ V_72 ] ,
V_98 ) ;
if ( V_25 < 0 )
return V_25 ;
}
for ( V_72 = 0 ; V_72 < V_70 -> V_101 ; V_72 ++ ) {
V_27 = V_70 -> V_102 [ V_72 ] . V_103 ;
V_25 = F_42 ( V_6 , V_27 , V_104 ) ;
if ( V_25 < 0 )
return V_25 ;
}
return 0 ;
}
static void F_43 ( struct V_5 * V_6 ,
const unsigned int * V_105 )
{
int V_72 ;
struct V_7 * V_8 = V_6 -> V_8 ;
if ( ! V_105 )
return;
for ( V_72 = 0 ; V_72 < V_8 -> V_106 ; V_72 ++ )
if ( V_8 -> V_107 [ V_72 ] && V_105 [ V_72 ] )
F_44 ( V_6 , V_8 -> V_107 [ V_72 ] ,
V_105 [ V_72 ] ) ;
}
static int F_45 ( struct V_108 * V_109 ,
struct V_5 * V_6 ,
struct V_110 * V_111 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
if ( V_8 -> V_112 )
F_46 ( V_8 -> V_112 ) ;
return F_47 ( V_6 , & V_8 -> V_30 , V_111 ,
V_109 ) ;
}
static int F_48 ( struct V_108 * V_109 ,
struct V_5 * V_6 ,
unsigned int V_113 ,
unsigned int V_114 ,
struct V_110 * V_111 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
return F_49 ( V_6 , & V_8 -> V_30 , V_113 , V_114 , V_111 ) ;
}
static int F_50 ( struct V_108 * V_109 ,
struct V_5 * V_6 ,
struct V_110 * V_111 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
return F_51 ( V_6 , & V_8 -> V_30 ) ;
}
static int F_52 ( struct V_108 * V_109 ,
struct V_5 * V_6 ,
struct V_110 * V_111 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
return F_53 ( V_6 , & V_8 -> V_30 ) ;
}
static int F_54 ( struct V_108 * V_109 ,
struct V_5 * V_6 ,
struct V_110 * V_111 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
return F_55 ( V_6 , & V_8 -> V_30 ) ;
}
static int F_56 ( struct V_108 * V_109 ,
struct V_5 * V_6 ,
unsigned int V_113 ,
unsigned int V_114 ,
struct V_110 * V_111 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
return F_57 ( V_6 , & V_8 -> V_30 ,
V_113 , V_114 , V_111 ) ;
}
static int F_58 ( struct V_108 * V_109 ,
struct V_5 * V_6 ,
struct V_110 * V_111 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
return F_59 ( V_6 , & V_8 -> V_30 ) ;
}
static int F_60 ( struct V_108 * V_109 ,
struct V_5 * V_6 ,
unsigned int V_113 ,
unsigned int V_114 ,
struct V_110 * V_111 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
T_1 V_27 = V_8 -> V_115 [ V_111 -> V_116 ] ;
if ( V_8 -> V_117 ) {
F_46 ( 40 ) ;
F_61 ( V_6 , V_27 , 0 ,
V_118 , V_119 ) ;
}
F_62 ( V_6 , V_27 , V_113 , 0 , V_114 ) ;
return 0 ;
}
static int F_63 ( struct V_108 * V_109 ,
struct V_5 * V_6 ,
struct V_110 * V_111 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
T_1 V_27 = V_8 -> V_115 [ V_111 -> V_116 ] ;
F_64 ( V_6 , V_27 ) ;
if ( V_8 -> V_117 )
F_61 ( V_6 , V_27 , 0 ,
V_118 , V_120 ) ;
return 0 ;
}
static int F_65 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
struct V_121 * V_122 = V_8 -> V_123 ;
V_6 -> V_124 = 1 ;
V_6 -> V_125 = V_122 ;
V_122 -> V_126 = L_7 ;
V_122 -> V_127 [ V_128 ] = V_129 ;
V_122 -> V_127 [ V_128 ] . V_27 =
V_8 -> V_30 . V_88 [ 0 ] ;
V_122 -> V_127 [ V_130 ] = V_131 ;
V_122 -> V_127 [ V_130 ] . V_27 = V_8 -> V_115 [ 0 ] ;
V_122 -> V_127 [ V_130 ] . V_132 = V_8 -> V_133 ;
if ( V_8 -> V_134 ) {
V_6 -> V_124 ++ ;
V_122 ++ ;
V_122 -> V_126 = L_8 ;
V_122 -> V_127 [ V_128 ] = V_135 ;
}
if ( V_8 -> V_30 . V_31 || V_8 -> V_85 ) {
V_6 -> V_124 ++ ;
V_122 ++ ;
V_122 -> V_126 = L_9 ;
V_122 -> V_136 = V_8 -> V_71 . V_137 [ 0 ] ;
if ( V_8 -> V_30 . V_31 ) {
V_122 -> V_127 [ V_128 ] = V_138 ;
V_122 -> V_127 [ V_128 ] . V_27 = V_8 -> V_30 . V_31 ;
}
if ( V_8 -> V_85 ) {
V_122 -> V_127 [ V_130 ] = V_139 ;
V_122 -> V_127 [ V_130 ] . V_27 = V_8 -> V_85 ;
}
}
return 0 ;
}
static unsigned int F_66 ( struct V_5 * V_6 ,
T_1 V_27 )
{
unsigned int V_140 = F_67 ( V_6 , V_27 ) ;
V_140 = ( V_140 & V_141 ) >> V_142 ;
if ( V_140 & V_143 )
return V_144 ;
if ( V_140 & V_145 )
return V_146 ;
if ( V_140 & V_147 )
return V_148 ;
if ( V_140 & V_149 )
return V_150 ;
return 0 ;
}
static void F_68 ( struct V_5 * V_6 , T_1 V_27 , int V_151 )
{
F_15 ( V_6 , V_27 , 0 ,
V_41 , V_151 ) ;
}
static int F_69 ( struct V_1 * V_2 ,
struct V_10 * V_11 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = V_6 -> V_8 ;
V_11 -> V_14 . integer . V_14 [ 0 ] = ! ! V_8 -> V_152 ;
return 0 ;
}
static int F_70 ( struct V_1 * V_2 ,
struct V_10 * V_11 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = V_6 -> V_8 ;
int V_27 = V_2 -> V_67 ;
V_8 -> V_152 = V_11 -> V_14 . integer . V_14 [ 0 ] ? V_27 : 0 ;
F_71 ( V_6 , V_27 ) ;
return 1 ;
}
static int F_72 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
int V_72 ;
static const char * const V_153 [] = {
L_10 , L_11 , L_12
} ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = V_6 -> V_8 ;
T_1 V_27 = V_2 -> V_67 ;
if ( V_27 == V_8 -> V_154 || V_27 == V_8 -> V_155 )
V_72 = 3 ;
else
V_72 = 2 ;
V_4 -> type = V_156 ;
V_4 -> V_14 . V_15 . V_57 = V_72 ;
V_4 -> V_79 = 1 ;
if ( V_4 -> V_14 . V_15 . V_16 >= V_72 )
V_4 -> V_14 . V_15 . V_16 = V_72 - 1 ;
strcpy ( V_4 -> V_14 . V_15 . V_126 ,
V_153 [ V_4 -> V_14 . V_15 . V_16 ] ) ;
return 0 ;
}
static int F_73 ( struct V_1 * V_2 ,
struct V_10 * V_11 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
T_1 V_27 = V_2 -> V_67 ;
unsigned int V_46 = F_17 ( V_6 , V_27 ) ;
if ( V_46 == F_66 ( V_6 , V_27 ) )
V_11 -> V_14 . V_15 . V_16 [ 0 ] = 0 ;
else if ( V_46 == V_150 )
V_11 -> V_14 . V_15 . V_16 [ 0 ] = 1 ;
else if ( V_46 == V_45 )
V_11 -> V_14 . V_15 . V_16 [ 0 ] = 2 ;
return 0 ;
}
static int F_74 ( struct V_1 * V_2 ,
struct V_10 * V_11 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
unsigned int V_36 = 0 ;
int error ;
T_1 V_27 = V_2 -> V_67 ;
if ( V_11 -> V_14 . V_15 . V_16 [ 0 ] == 0 )
V_36 = F_66 ( V_6 , V_27 ) ;
else if ( V_11 -> V_14 . V_15 . V_16 [ 0 ] == 1 )
V_36 = V_150 ;
else if ( V_11 -> V_14 . V_15 . V_16 [ 0 ] == 2 )
V_36 = V_45 ;
else
return 0 ;
if ( V_36 != F_17 ( V_6 , V_27 ) ) {
error = F_16 ( V_6 , V_27 , V_36 ) ;
return error ;
}
return 0 ;
}
static int F_75 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
char * V_153 [ 2 ] ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = V_6 -> V_8 ;
if ( V_2 -> V_67 == V_8 -> V_155 )
V_153 [ 0 ] = L_11 ;
else
V_153 [ 0 ] = L_10 ;
V_153 [ 1 ] = L_12 ;
V_4 -> type = V_156 ;
V_4 -> V_14 . V_15 . V_57 = 2 ;
V_4 -> V_79 = 1 ;
if ( V_4 -> V_14 . V_15 . V_16 >= 2 )
V_4 -> V_14 . V_15 . V_16 = 1 ;
strcpy ( V_4 -> V_14 . V_15 . V_126 ,
V_153 [ V_4 -> V_14 . V_15 . V_16 ] ) ;
return 0 ;
}
static int F_76 ( struct V_1 * V_2 , struct V_10 * V_11 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = V_6 -> V_8 ;
T_1 V_27 = V_2 -> V_67 ;
int V_157 = ( V_27 == V_8 -> V_154 ) ? 1 : 0 ;
V_11 -> V_14 . V_15 . V_16 [ 0 ] = V_8 -> V_158 [ V_157 ] ;
return 0 ;
}
static int F_77 ( struct V_1 * V_2 , struct V_10 * V_11 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = V_6 -> V_8 ;
T_1 V_27 = V_2 -> V_67 ;
int V_157 = ( V_27 == V_8 -> V_154 ) ? 1 : 0 ;
unsigned short V_26 = ! ! V_11 -> V_14 . V_15 . V_16 [ 0 ] ;
V_8 -> V_158 [ V_157 ] = V_26 ;
if ( V_26 )
F_68 ( V_6 , V_27 , V_44 ) ;
else {
unsigned int V_37 = V_43 ;
if ( V_157 )
V_37 |= F_66 ( V_6 , V_27 ) ;
F_68 ( V_6 , V_27 , V_37 ) ;
}
if ( V_8 -> V_94 )
F_71 ( V_6 , V_27 ) ;
return 1 ;
}
static int F_78 ( struct V_1 * V_2 ,
struct V_10 * V_11 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = V_6 -> V_8 ;
V_11 -> V_14 . integer . V_14 [ 0 ] = V_8 -> V_159 ;
return 0 ;
}
static int F_79 ( struct V_1 * V_2 ,
struct V_10 * V_11 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = V_6 -> V_8 ;
T_1 V_27 = V_2 -> V_67 & 0xff ;
unsigned int V_26 = ! ! V_11 -> V_14 . integer . V_14 [ 0 ] ;
if ( V_8 -> V_159 == V_26 )
return 0 ;
V_8 -> V_159 = V_26 ;
F_15 ( V_6 , V_27 , 0 , V_160 ,
V_8 -> V_159 ? 0x4 : 0x0 ) ;
return 1 ;
}
static struct V_161 *
F_80 ( struct V_7 * V_8 ,
const struct V_161 * V_162 ,
const char * V_126 ,
unsigned int V_163 )
{
struct V_161 * V_164 ;
F_81 ( & V_8 -> V_165 , sizeof( * V_164 ) , 32 ) ;
V_164 = F_82 ( & V_8 -> V_165 ) ;
if ( ! V_164 )
return NULL ;
* V_164 = * V_162 ;
V_164 -> V_126 = F_83 ( V_126 , V_166 ) ;
if ( ! V_164 -> V_126 ) {
memset ( V_164 , 0 , sizeof( * V_164 ) ) ;
V_8 -> V_165 . V_167 -- ;
return NULL ;
}
V_164 -> V_168 = V_163 ;
return V_164 ;
}
static int F_84 ( struct V_7 * V_8 ,
const struct V_161 * V_162 ,
int V_51 , const char * V_126 ,
unsigned long V_26 )
{
struct V_161 * V_164 = F_80 ( V_8 , V_162 , V_126 ,
V_169 ) ;
if ( ! V_164 )
return - V_170 ;
V_164 -> V_58 = V_51 ;
V_164 -> V_67 = V_26 ;
return 0 ;
}
static inline int F_85 ( struct V_7 * V_8 ,
int type , int V_51 , const char * V_126 ,
unsigned long V_26 )
{
return F_84 ( V_8 ,
& V_171 [ type ] ,
V_51 , V_126 , V_26 ) ;
}
static inline int F_86 ( struct V_7 * V_8 , int type ,
const char * V_126 , unsigned long V_26 )
{
return F_85 ( V_8 , type , 0 , V_126 , V_26 ) ;
}
static inline int F_87 ( struct V_5 * V_6 ,
T_1 V_27 , int V_51 )
{
int V_172 = F_88 ( V_6 , V_27 ) ;
int V_173 = 0 ;
struct V_7 * V_8 = V_6 -> V_8 ;
char V_126 [ 22 ] ;
if ( F_89 ( V_172 ) != V_174 ) {
if ( F_66 ( V_6 , V_27 ) == V_150
&& V_27 == V_8 -> V_155 )
V_173 = V_175 ;
else if ( F_67 ( V_6 , V_27 )
& ( V_149 << V_142 ) )
V_173 = V_176 ;
else if ( V_27 == V_8 -> V_154 )
V_173 = V_175 ;
}
if ( V_173 ) {
strcpy ( V_126 , F_90 ( V_6 , V_27 , 1 ) ) ;
return F_86 ( V_6 -> V_8 , V_173 ,
strcat ( V_126 , L_13 ) , V_27 ) ;
}
return 0 ;
}
static int F_91 ( struct V_7 * V_8 )
{
struct V_161 * V_164 ;
struct V_22 * V_50 = & V_8 -> V_177 ;
if ( V_8 -> V_76 )
return 0 ;
if ( ! V_8 -> V_133 || V_50 -> V_33 <= 1 )
return 0 ;
V_164 = F_80 ( V_8 , & V_178 ,
V_178 . V_126 , 0 ) ;
if ( ! V_164 )
return - V_170 ;
V_164 -> V_79 = V_8 -> V_133 ;
return 0 ;
}
static T_1 F_92 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
struct V_69 * V_70 = & V_8 -> V_71 ;
T_1 V_27 ;
unsigned int V_140 ;
int V_72 ;
if ( V_70 -> V_179 != V_180 )
return 0 ;
for ( V_72 = 0 ; V_72 < V_70 -> V_101 ; V_72 ++ ) {
if ( V_70 -> V_102 [ V_72 ] . type == V_181 ) {
V_27 = V_70 -> V_102 [ V_72 ] . V_103 ;
V_140 = F_67 ( V_6 , V_27 ) ;
if ( V_140 & V_182 )
return V_27 ;
}
}
return 0 ;
}
static T_1 F_93 ( struct V_5 * V_6 , T_1 * V_183 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
struct V_69 * V_70 = & V_8 -> V_71 ;
unsigned int V_172 , V_140 ;
int V_72 ;
* V_183 = 0 ;
if ( V_70 -> V_179 != V_180 )
return 0 ;
for ( V_72 = 0 ; V_72 < V_70 -> V_101 ; V_72 ++ ) {
T_1 V_27 = V_70 -> V_102 [ V_72 ] . V_103 ;
if ( V_70 -> V_102 [ V_72 ] . type != V_184 )
continue;
V_172 = F_88 ( V_6 , V_27 ) ;
if ( F_89 ( V_172 ) != V_174 ) {
V_140 = F_67 ( V_6 , V_27 ) ;
if ( V_140 & V_182 ) {
* V_183 = F_94 ( V_6 , V_27 ) ;
if ( * V_183 )
return V_27 ;
}
}
}
return 0 ;
}
static int F_95 ( struct V_7 * V_8 , T_1 V_27 )
{
int V_72 ;
for ( V_72 = 0 ; V_72 < V_8 -> V_30 . V_185 ; V_72 ++ ) {
if ( V_8 -> V_30 . V_88 [ V_72 ] == V_27 )
return 1 ;
}
return 0 ;
}
static int F_96 ( struct V_7 * V_8 , T_1 V_27 )
{
int V_72 ;
if ( F_95 ( V_8 , V_27 ) )
return 1 ;
for ( V_72 = 0 ; V_72 < V_8 -> V_71 . V_95 ; V_72 ++ )
if ( V_8 -> V_186 [ V_72 ] == V_27 )
return 1 ;
for ( V_72 = 0 ; V_72 < V_8 -> V_71 . V_187 ; V_72 ++ )
if ( V_8 -> V_188 [ V_72 ] == V_27 )
return 1 ;
return 0 ;
}
static T_1 F_94 ( struct V_5 * V_6 , T_1 V_27 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
struct V_69 * V_70 = & V_8 -> V_71 ;
int V_189 , V_190 ;
T_1 V_191 [ V_192 ] , V_193 ;
unsigned int V_81 , V_194 ;
V_190 = F_97 ( V_6 , V_27 , V_191 ,
V_192 ) ;
while ( V_190 == 1 && ( F_98 ( F_33 ( V_6 , V_191 [ 0 ] ) )
!= V_195 ) ) {
V_27 = V_191 [ 0 ] ;
V_190 = F_97 ( V_6 , V_27 , V_191 ,
V_192 ) ;
}
for ( V_189 = 0 ; V_189 < V_190 ; V_189 ++ ) {
V_81 = F_33 ( V_6 , V_191 [ V_189 ] ) ;
V_194 = F_98 ( V_81 ) ;
if ( V_194 != V_195 || ( V_81 & V_196 ) )
continue;
if ( ! F_96 ( V_8 , V_191 [ V_189 ] ) ) {
if ( V_190 > 1 ) {
F_15 ( V_6 , V_27 , 0 ,
V_56 , V_189 ) ;
}
return V_191 [ V_189 ] ;
}
}
V_193 = V_8 -> V_30 . V_88 [ 0 ] ;
if ( V_8 -> V_30 . V_197 ) {
for ( V_189 = 0 ; V_189 < V_70 -> V_95 ; V_189 ++ )
if ( V_70 -> V_97 [ V_189 ] == V_27 ) {
V_193 = V_8 -> V_30 . V_197 ;
break;
}
}
if ( V_190 > 1 ) {
for ( V_189 = 0 ; V_189 < V_190 ; V_189 ++ ) {
if ( V_191 [ V_189 ] == V_193 ) {
F_15 ( V_6 , V_27 , 0 ,
V_56 , V_189 ) ;
break;
}
}
}
return 0 ;
}
static int F_99 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
struct V_69 * V_70 = & V_8 -> V_71 ;
int V_72 ;
T_1 V_27 , V_183 ;
for ( V_72 = 0 ; V_72 < V_70 -> V_99 ; V_72 ++ ) {
V_27 = V_70 -> V_100 [ V_72 ] ;
V_183 = F_94 ( V_6 , V_27 ) ;
if ( ! V_183 ) {
if ( V_8 -> V_30 . V_185 > 0 ) {
V_70 -> V_99 = V_8 -> V_30 . V_185 ;
break;
}
F_100 ( V_198
L_14 ,
V_38 , V_27 ) ;
return - V_199 ;
}
F_101 ( V_8 , V_183 ) ;
}
for ( V_72 = 0 ; V_72 < V_70 -> V_95 ; V_72 ++ ) {
V_27 = V_70 -> V_97 [ V_72 ] ;
V_183 = F_94 ( V_6 , V_27 ) ;
if ( V_183 ) {
if ( ! V_8 -> V_30 . V_197 )
V_8 -> V_30 . V_197 = V_183 ;
else
F_102 ( V_8 , V_183 ) ;
}
V_8 -> V_186 [ V_72 ] = V_183 ;
}
for ( V_72 = 0 ; V_72 < V_70 -> V_187 ; V_72 ++ ) {
V_27 = V_70 -> V_200 [ V_72 ] ;
V_183 = F_94 ( V_6 , V_27 ) ;
if ( V_183 )
F_102 ( V_8 , V_183 ) ;
V_8 -> V_188 [ V_72 ] = V_183 ;
}
V_27 = F_92 ( V_6 ) ;
if ( V_27 ) {
V_183 = F_94 ( V_6 , V_27 ) ;
if ( V_183 ) {
F_13 ( L_15 ,
V_27 , V_70 -> V_99 ) ;
V_70 -> V_100 [ V_70 -> V_99 ] = V_27 ;
V_70 -> V_99 ++ ;
V_8 -> V_155 = V_27 ;
F_101 ( V_8 , V_183 ) ;
}
}
V_27 = F_93 ( V_6 , & V_183 ) ;
if ( V_27 && V_183 ) {
F_13 ( L_16 ,
V_27 , V_70 -> V_99 ) ;
V_70 -> V_100 [ V_70 -> V_99 ] = V_27 ;
V_70 -> V_99 ++ ;
V_8 -> V_154 = V_27 ;
F_101 ( V_8 , V_183 ) ;
}
F_103 ( L_17 ,
V_8 -> V_30 . V_185 ,
V_8 -> V_30 . V_88 [ 0 ] ,
V_8 -> V_30 . V_88 [ 1 ] ,
V_8 -> V_30 . V_88 [ 2 ] ,
V_8 -> V_30 . V_88 [ 3 ] ,
V_8 -> V_30 . V_88 [ 4 ] ) ;
return 0 ;
}
static int F_104 ( struct V_5 * V_6 , const char * V_201 ,
int V_51 , T_1 V_27 , int V_202 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
char V_126 [ 32 ] ;
int V_25 ;
if ( ! V_8 -> V_203 ) {
unsigned int V_204 , V_205 , V_206 , V_207 ;
V_204 = F_105 ( V_6 , V_27 , V_35 ) ;
V_205 = ( V_204 & V_208 ) >>
V_209 ;
V_205 = ( V_205 + 1 ) * 25 ;
V_206 = ( V_204 & V_210 ) >>
V_211 ;
V_207 = V_206 * V_205 ;
if ( V_207 > 6400 && V_206 >= 0x1f )
V_8 -> V_89 = V_206 / 2 ;
V_8 -> V_203 = 1 ;
}
sprintf ( V_126 , L_18 , V_201 ) ;
V_25 = F_85 ( V_8 , V_212 , V_51 , V_126 ,
F_106 ( V_27 , V_202 , 0 , V_35 ,
V_8 -> V_89 ) ) ;
if ( V_25 < 0 )
return V_25 ;
sprintf ( V_126 , L_19 , V_201 ) ;
V_25 = F_85 ( V_8 , V_213 , V_51 , V_126 ,
F_107 ( V_27 , V_202 , 0 , V_35 ) ) ;
if ( V_25 < 0 )
return V_25 ;
return 0 ;
}
static int F_101 ( struct V_7 * V_8 , T_1 V_27 )
{
if ( V_8 -> V_30 . V_185 > 4 ) {
F_108 ( V_214 L_20 , V_27 ) ;
return 1 ;
} else {
F_109 ( V_8 -> V_30 . V_88 != V_8 -> V_88 ) ;
V_8 -> V_88 [ V_8 -> V_30 . V_185 ] = V_27 ;
V_8 -> V_30 . V_185 ++ ;
}
return 0 ;
}
static int F_102 ( struct V_7 * V_8 , T_1 V_27 )
{
int V_72 ;
for ( V_72 = 0 ; V_72 < F_110 ( V_8 -> V_30 . V_215 ) ; V_72 ++ ) {
if ( ! V_8 -> V_30 . V_215 [ V_72 ] ) {
V_8 -> V_30 . V_215 [ V_72 ] = V_27 ;
return 0 ;
}
}
F_108 ( V_214 L_21 , V_27 ) ;
return 1 ;
}
static int F_111 ( struct V_5 * V_6 , int V_216 ,
const T_1 * V_217 ,
const T_1 * V_88 ,
int type )
{
struct V_7 * V_8 = V_6 -> V_8 ;
static const char * const V_218 [ 4 ] = {
L_22 , L_23 , NULL , L_24
} ;
T_1 V_27 ;
int V_72 , V_25 ;
unsigned int V_219 ;
for ( V_72 = 0 ; V_72 < V_216 && V_72 < F_110 ( V_218 ) ; V_72 ++ ) {
if ( type == V_220 && ! V_8 -> V_94 ) {
if ( F_112 ( V_6 , V_217 [ V_72 ] ) )
V_8 -> V_94 = 1 ;
}
V_27 = V_88 [ V_72 ] ;
if ( ! V_27 )
continue;
if ( type != V_220 && V_72 == 2 ) {
V_25 = F_113 ( V_6 , L_25 , V_27 , 1 ) ;
if ( V_25 < 0 )
return V_25 ;
V_25 = F_113 ( V_6 , L_26 , V_27 , 2 ) ;
if ( V_25 < 0 )
return V_25 ;
V_219 = F_33 ( V_6 , V_27 ) ;
if ( V_219 & V_221 ) {
V_25 = F_86 ( V_8 ,
V_222 ,
L_27 , V_27 ) ;
if ( V_25 < 0 )
return V_25 ;
}
} else {
const char * V_126 ;
int V_51 ;
switch ( type ) {
case V_220 :
V_126 = L_28 ;
V_51 = V_72 ;
break;
case V_223 :
V_126 = L_29 ;
V_51 = V_72 ;
break;
default:
V_126 = V_218 [ V_72 ] ;
V_51 = 0 ;
break;
}
V_25 = F_104 ( V_6 , V_126 , V_51 , V_27 , 3 ) ;
if ( V_25 < 0 )
return V_25 ;
}
}
return 0 ;
}
static int F_114 ( struct V_5 * V_6 , unsigned long V_224 ,
unsigned long V_225 , int V_51 )
{
int V_25 ;
V_25 = F_85 ( V_6 -> V_8 , V_212 , V_51 ,
L_30 , V_224 ) ;
if ( V_25 < 0 )
return V_25 ;
V_25 = F_85 ( V_6 -> V_8 , V_213 , V_51 ,
L_31 , V_225 ) ;
if ( V_25 < 0 )
return V_25 ;
return 0 ;
}
static int F_115 ( struct V_5 * V_6 ,
const struct V_69 * V_70 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
T_1 V_27 ;
int V_25 ;
int V_51 ;
V_25 = F_111 ( V_6 , V_70 -> V_99 , V_70 -> V_100 ,
V_8 -> V_30 . V_88 ,
V_70 -> V_179 ) ;
if ( V_25 < 0 )
return V_25 ;
if ( V_70 -> V_95 > 1 && V_70 -> V_179 == V_180 ) {
V_25 = F_86 ( V_8 ,
V_226 ,
L_32 ,
V_70 -> V_97 [ V_70 -> V_95 - 1 ] ) ;
if ( V_25 < 0 )
return V_25 ;
}
for ( V_51 = 0 ; V_51 < V_70 -> V_101 ; V_51 ++ ) {
if ( V_70 -> V_102 [ V_51 ] . type > V_181 )
break;
V_27 = V_70 -> V_102 [ V_51 ] . V_103 ;
V_25 = F_87 ( V_6 , V_27 , V_51 ) ;
if ( V_25 < 0 )
return V_25 ;
}
return 0 ;
}
static int F_116 ( struct V_5 * V_6 ,
struct V_69 * V_70 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
int V_25 ;
V_25 = F_111 ( V_6 , V_70 -> V_95 , V_70 -> V_97 ,
V_8 -> V_186 , V_220 ) ;
if ( V_25 < 0 )
return V_25 ;
V_25 = F_111 ( V_6 , V_70 -> V_187 , V_70 -> V_200 ,
V_8 -> V_188 , V_223 ) ;
if ( V_25 < 0 )
return V_25 ;
return 0 ;
}
static int F_117 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
struct V_22 * V_59 = & V_8 -> V_227 ;
int V_72 , V_228 ;
T_1 V_229 [ F_110 ( V_230 ) ] ;
V_228 = F_97 ( V_6 ,
V_8 -> V_61 ,
V_229 ,
V_231 ) ;
if ( V_228 <= 0 || V_228 > F_110 ( V_230 ) )
return - V_232 ;
for ( V_72 = 0 ; V_72 < V_228 ; V_72 ++ )
F_34 ( V_59 , V_230 [ V_72 ] , V_72 ,
NULL ) ;
return F_86 ( V_8 , V_233 ,
L_33 , V_8 -> V_61 ) ;
}
static int F_118 ( struct V_5 * V_6 ,
T_1 V_27 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
T_2 V_204 = F_105 ( V_6 , V_27 , V_35 ) ;
int V_25 , type = V_234 ;
if ( V_8 -> V_235 == V_27 )
type = V_213 ;
if ( ( V_204 & V_236 ) >> V_237 ) {
V_25 = F_86 ( V_8 , type ,
L_34 ,
F_107 ( V_27 , 1 , 0 , V_35 ) ) ;
if ( V_25 < 0 )
return V_25 ;
}
if ( ( V_204 & V_210 ) >> V_211 ) {
V_25 = F_86 ( V_8 , V_212 ,
L_35 ,
F_107 ( V_27 , 1 , 0 , V_35 ) ) ;
if ( V_25 < 0 )
return V_25 ;
}
return 0 ;
}
static int F_119 ( struct V_1 * V_2 ,
struct V_10 * V_11 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
V_11 -> V_14 . integer . V_14 [ 0 ] = V_6 -> V_238 -> V_239 ;
return 0 ;
}
static int F_120 ( struct V_1 * V_2 ,
struct V_10 * V_11 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
return F_121 ( V_6 , V_11 -> V_14 . integer . V_14 [ 0 ] ) ;
}
static int F_122 ( struct V_5 * V_6 )
{
return F_84 ( V_6 -> V_8 , & V_240 ,
0 , L_34 , 0 ) ;
}
static int F_123 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
int V_72 , V_189 , V_25 = 0 ;
for ( V_72 = 0 ; V_72 < V_8 -> V_241 ; V_72 ++ ) {
T_1 V_27 ;
unsigned int V_81 ;
unsigned long V_26 ;
V_27 = V_8 -> V_55 [ V_72 ] ;
V_81 = F_33 ( V_6 , V_27 ) ;
if ( ! ( V_81 & V_82 ) )
continue;
V_26 = F_107 ( V_27 , 3 , 0 , V_35 ) ;
for ( V_189 = 0 ; V_189 < V_8 -> V_242 ; V_189 ++ ) {
if ( V_8 -> V_243 [ V_189 ] == V_26 )
break;
}
if ( V_189 < V_8 -> V_242 )
continue;
V_25 = F_85 ( V_8 , V_212 , V_72 ,
L_36 , V_26 ) ;
if ( V_25 < 0 )
return V_25 ;
}
return 0 ;
}
static int F_124 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
struct V_22 * V_244 = & V_8 -> V_24 ;
const char * const * V_245 = V_8 -> V_246 ;
int V_72 , V_228 ;
T_1 V_229 [ V_231 ] ;
V_228 = F_97 ( V_6 ,
V_8 -> V_28 [ 0 ] ,
V_229 ,
V_231 ) ;
if ( V_228 <= 0 )
return - V_232 ;
if ( ! V_245 )
V_245 = V_247 ;
for ( V_72 = 0 ; V_72 < V_228 ; V_72 ++ )
F_34 ( V_244 , V_245 [ V_72 ] , V_72 , NULL ) ;
return 0 ;
}
static T_1 F_125 ( struct V_5 * V_6 , T_1 V_248 ,
int V_51 )
{
T_1 V_191 [ V_231 ] ;
int V_206 ;
V_206 = F_97 ( V_6 , V_248 , V_191 , F_110 ( V_191 ) ) ;
if ( V_51 >= 0 && V_51 < V_206 )
return V_191 [ V_51 ] ;
return 0 ;
}
static int F_126 ( struct V_5 * V_6 , T_1 V_27 ,
const char * V_249 , int V_51 , int V_250 )
{
unsigned int V_204 , V_206 ;
char V_126 [ 32 ] ;
int V_25 ;
if ( V_250 == V_35 )
V_204 = V_82 ;
else
V_204 = V_251 ;
if ( ! ( F_33 ( V_6 , V_27 ) & V_204 ) )
return 0 ;
V_204 = F_105 ( V_6 , V_27 , V_250 ) ;
V_206 = ( V_204 & V_210 ) >> V_211 ;
if ( ! V_206 )
return 0 ;
snprintf ( V_126 , sizeof( V_126 ) , L_37 , V_249 ) ;
V_25 = F_85 ( V_6 -> V_8 , V_212 , V_51 , V_126 ,
F_107 ( V_27 , 3 , 0 , V_250 ) ) ;
if ( V_25 < 0 )
return V_25 ;
return 1 ;
}
static int F_127 ( struct V_5 * V_6 ,
const struct V_69 * V_70 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
struct V_22 * V_50 = & V_8 -> V_177 ;
struct V_22 * V_252 = & V_8 -> V_253 ;
int V_25 , V_72 ;
unsigned int V_172 ;
F_34 ( V_252 , V_254 [ 0 ] , 0 , NULL ) ;
for ( V_72 = 0 ; V_72 < V_8 -> V_255 ; V_72 ++ ) {
T_1 V_27 ;
int V_58 , V_256 ;
const char * V_249 ;
V_27 = V_8 -> V_257 [ V_72 ] ;
if ( F_98 ( F_33 ( V_6 , V_27 ) ) != V_258 )
continue;
V_172 = F_88 ( V_6 , V_27 ) ;
if ( F_128 ( V_172 ) == V_259 )
continue;
V_58 = F_129 ( V_6 , V_8 -> V_18 [ 0 ] , V_27 ) ;
if ( V_58 < 0 )
continue;
V_249 = F_90 ( V_6 , V_27 , 1 ) ;
F_34 ( V_252 , V_249 , V_58 , & V_256 ) ;
if ( F_30 ( V_6 , L_2 ) != 1 )
F_34 ( V_50 , V_249 , V_58 , & V_256 ) ;
V_25 = F_126 ( V_6 , V_27 , V_249 , V_256 ,
V_260 ) ;
if ( V_25 < 0 )
return V_25 ;
if ( ! V_25 ) {
V_25 = F_126 ( V_6 , V_27 , V_249 ,
V_256 , V_35 ) ;
if ( V_25 < 0 )
return V_25 ;
if ( ! V_25 ) {
V_27 = F_125 ( V_6 ,
V_8 -> V_18 [ 0 ] , V_58 ) ;
if ( V_27 )
V_25 = F_126 ( V_6 ,
V_27 , V_249 ,
V_256 , V_260 ) ;
if ( V_25 < 0 )
return V_25 ;
}
}
}
return 0 ;
}
static int F_130 ( struct V_5 * V_6 , T_1 V_27 ,
T_1 * V_261 , T_1 * V_262 , T_1 * V_263 )
{
unsigned int V_70 ;
unsigned int type ;
if ( ! V_27 )
return 0 ;
V_70 = F_88 ( V_6 , V_27 ) ;
type = F_131 ( V_70 ) ;
switch ( F_89 ( V_70 ) ) {
case V_174 :
if ( * V_261 )
return 1 ;
if ( type != V_264 )
return 1 ;
* V_261 = V_27 ;
break;
case V_265 :
break;
case V_266 :
if ( * V_263 )
return 1 ;
if ( type != V_264 && type != V_267 )
return 1 ;
* V_263 = V_27 ;
break;
default:
if ( * V_262 )
return 1 ;
if ( type != V_264 )
return 1 ;
* V_262 = V_27 ;
break;
}
return 0 ;
}
static int F_132 ( struct V_5 * V_6 ,
struct V_268 * V_269 ,
T_1 V_103 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
struct V_69 * V_70 = & V_8 -> V_71 ;
int V_72 ;
V_269 -> V_103 = V_103 ;
if ( V_103 == 0 )
return 0 ;
for ( V_72 = 0 ; V_72 < V_70 -> V_101 ; V_72 ++ ) {
if ( V_103 == V_70 -> V_102 [ V_72 ] . V_103 )
break;
}
if ( V_72 < V_70 -> V_101 && V_70 -> V_102 [ V_72 ] . type == V_184 ) {
V_72 = F_129 ( V_6 , V_8 -> V_55 [ 0 ] , V_103 ) ;
if ( V_72 < 0 )
return - 1 ;
V_269 -> V_270 = V_72 ;
V_269 -> V_12 = - 1 ;
if ( V_8 -> V_18 )
V_269 -> V_12 = F_129 ( V_6 ,
V_8 -> V_18 [ 0 ] ,
V_8 -> V_55 [ 0 ] ) ;
} else if ( V_8 -> V_18 ) {
V_72 = F_129 ( V_6 , V_8 -> V_18 [ 0 ] , V_103 ) ;
if ( V_72 < 0 )
return - 1 ;
V_269 -> V_12 = V_72 ;
V_269 -> V_270 = - 1 ;
if ( V_8 -> V_55 )
V_269 -> V_270 = F_129 ( V_6 ,
V_8 -> V_55 [ 0 ] ,
V_8 -> V_18 [ 0 ] ) ;
}
return 0 ;
}
static int F_133 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
struct V_69 * V_70 = & V_8 -> V_71 ;
T_1 V_261 , V_262 , V_263 ;
int V_72 ;
V_261 = V_262 = V_263 = 0 ;
for ( V_72 = 0 ; V_72 < V_70 -> V_101 ; V_72 ++ )
if ( F_130 ( V_6 , V_70 -> V_102 [ V_72 ] . V_103 ,
& V_261 , & V_262 , & V_263 ) )
return 0 ;
for ( V_72 = 0 ; V_72 < V_8 -> V_255 ; V_72 ++ )
if ( F_130 ( V_6 , V_8 -> V_257 [ V_72 ] ,
& V_261 , & V_262 , & V_263 ) )
return 0 ;
if ( ! V_261 || ( ! V_262 && ! V_263 ) )
return 0 ;
if ( ! F_112 ( V_6 , V_262 ) )
return 0 ;
if ( F_132 ( V_6 , & V_8 -> V_271 , V_262 ) ||
F_132 ( V_6 , & V_8 -> V_272 , V_261 ) ||
F_132 ( V_6 , & V_8 -> V_273 , V_263 ) )
return 0 ;
return 1 ;
}
static int F_134 ( struct V_5 * V_6 , const struct V_69 * V_70 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
struct V_22 * V_50 = & V_8 -> V_177 ;
int V_72 , V_189 ;
const char * V_249 ;
for ( V_72 = 0 ; V_72 < V_70 -> V_101 ; V_72 ++ ) {
T_1 V_27 = V_70 -> V_102 [ V_72 ] . V_103 ;
int V_58 , V_25 , V_256 ;
V_58 = - 1 ;
for ( V_189 = 0 ; V_189 < V_8 -> V_241 ; V_189 ++ ) {
V_58 = F_129 ( V_6 , V_8 -> V_55 [ V_189 ] ,
V_27 ) ;
if ( V_58 >= 0 )
break;
}
if ( V_58 < 0 )
continue;
V_249 = F_135 ( V_6 , V_70 , V_72 ) ;
F_34 ( V_50 , V_249 , V_58 , & V_256 ) ;
V_25 = F_126 ( V_6 , V_27 ,
V_249 , V_256 ,
V_260 ) ;
if ( V_25 < 0 )
return V_25 ;
}
V_8 -> V_54 = V_50 -> V_33 ;
if ( V_50 -> V_33 ) {
for ( V_72 = 0 ; V_72 < V_8 -> V_241 ; V_72 ++ ) {
F_15 ( V_6 , V_8 -> V_55 [ V_72 ] , 0 ,
V_56 ,
V_50 -> V_57 [ 0 ] . V_58 ) ;
}
}
return 0 ;
}
static void F_136 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
int V_72 ;
for ( V_72 = 0 ; V_72 < V_8 -> V_71 . V_99 ; V_72 ++ ) {
T_1 V_27 = V_8 -> V_71 . V_100 [ V_72 ] ;
F_68 ( V_6 , V_27 , V_44 ) ;
}
}
static void F_137 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
int V_72 ;
for ( V_72 = 0 ; V_72 < V_8 -> V_71 . V_95 ; V_72 ++ ) {
T_1 V_103 ;
V_103 = V_8 -> V_71 . V_97 [ V_72 ] ;
if ( V_103 )
F_68 ( V_6 , V_103 , V_44 | V_274 ) ;
}
for ( V_72 = 0 ; V_72 < V_8 -> V_71 . V_187 ; V_72 ++ ) {
T_1 V_103 ;
V_103 = V_8 -> V_71 . V_200 [ V_72 ] ;
if ( V_103 )
F_68 ( V_6 , V_103 , V_44 ) ;
}
}
static int F_138 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
int V_72 , V_275 ;
if ( V_8 -> V_71 . V_179 != V_223 ||
V_8 -> V_71 . V_95 <= 1 )
return 0 ;
V_275 = 0 ;
for ( V_72 = 0 ; V_72 < V_8 -> V_71 . V_95 ; V_72 ++ ) {
T_1 V_27 = V_8 -> V_71 . V_97 [ V_72 ] ;
unsigned int V_70 = F_88 ( V_6 , V_27 ) ;
if ( F_139 ( V_70 ) & V_276 )
continue;
V_275 ++ ;
}
return ( V_275 > 1 ) ;
}
static int F_140 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
T_1 V_277 = 0 , V_278 = 0 ;
int V_279 = 0 ;
int V_72 , V_25 ;
if ( ( V_25 = F_141 ( V_6 ,
& V_8 -> V_71 ,
V_8 -> V_257 ) ) < 0 )
return V_25 ;
if ( ! V_8 -> V_71 . V_99 )
return 0 ;
if ( F_138 ( V_6 ) ) {
F_13 ( L_38 ) ;
memcpy ( V_8 -> V_71 . V_200 , V_8 -> V_71 . V_100 ,
sizeof( V_8 -> V_71 . V_100 ) ) ;
V_8 -> V_71 . V_187 = V_8 -> V_71 . V_99 ;
memcpy ( V_8 -> V_71 . V_100 , V_8 -> V_71 . V_97 ,
sizeof( V_8 -> V_71 . V_97 ) ) ;
V_8 -> V_71 . V_99 = V_8 -> V_71 . V_95 ;
V_8 -> V_71 . V_179 = V_220 ;
V_8 -> V_71 . V_95 = 0 ;
V_279 = 1 ;
}
if ( V_8 -> V_71 . V_280 ) {
int V_281 = F_33 ( V_6 , V_8 -> V_71 . V_280 ) &
( V_82 | V_251 ) ;
T_2 V_204 = F_105 ( V_6 ,
V_8 -> V_71 . V_280 , V_281 ) ;
T_1 V_282 [ 1 ] ;
if ( F_97 ( V_6 ,
V_8 -> V_71 . V_280 , V_282 , 1 ) &&
F_97 ( V_6 , V_282 [ 0 ] ,
V_282 , 1 ) > 0 ) {
int V_81 = F_33 ( V_6 , V_282 [ 0 ] ) ;
int V_283 = F_98 ( V_81 ) ;
if ( V_283 == V_284 &&
! ( V_81 & V_221 ) )
V_8 -> V_61 = V_282 [ 0 ] ;
}
if ( V_281 ) {
T_1 V_27 = V_8 -> V_71 . V_280 ;
V_281 = ( V_281 & V_82 ) ? V_35 : V_260 ;
V_25 = F_86 ( V_8 , V_213 ,
L_39 ,
F_107 ( V_27 , 1 , 0 , V_281 ) ) ;
if ( V_25 < 0 )
return V_25 ;
if ( ( V_204 & V_210 )
>> V_211 ) {
V_25 = F_86 ( V_8 ,
V_212 ,
L_40 ,
F_107 ( V_27 , 1 , 0 , V_281 ) ) ;
if ( V_25 < 0 )
return V_25 ;
}
}
F_68 ( V_6 , V_8 -> V_71 . V_280 ,
V_44 ) ;
}
if ( ! V_8 -> V_30 . V_185 ) {
V_25 = F_99 ( V_6 ) ;
if ( V_25 < 0 )
return V_25 ;
V_25 = F_115 ( V_6 ,
& V_8 -> V_71 ) ;
if ( V_25 < 0 )
return V_25 ;
}
if ( V_8 -> V_235 > 0 ) {
V_25 = F_118 ( V_6 ,
V_8 -> V_235 ) ;
if ( V_25 < 0 )
return V_25 ;
}
#ifdef F_142
if ( V_8 -> V_285 > 0 ) {
T_1 V_27 = V_8 -> V_285 ;
unsigned int V_204 ;
V_25 = F_118 ( V_6 , V_27 ) ;
if ( V_25 < 0 )
return V_25 ;
V_25 = F_143 ( V_6 , V_27 ) ;
if ( V_25 < 0 )
return V_25 ;
if ( V_6 -> V_238 ) {
V_6 -> V_238 -> V_286 = V_8 -> V_287 ;
V_204 = F_105 ( V_6 , V_27 , V_35 ) ;
if ( ! ( V_204 & V_236 ) ) {
V_25 = F_122 ( V_6 ) ;
if ( V_25 < 0 )
return V_25 ;
}
}
}
#endif
V_25 = F_116 ( V_6 , & V_8 -> V_71 ) ;
if ( V_25 < 0 )
return V_25 ;
if ( V_279 ) {
memcpy ( V_8 -> V_71 . V_97 , V_8 -> V_71 . V_100 ,
sizeof( V_8 -> V_71 . V_97 ) ) ;
V_8 -> V_71 . V_95 = V_8 -> V_71 . V_99 ;
V_8 -> V_71 . V_179 = V_220 ;
V_8 -> V_71 . V_99 = 0 ;
}
if ( F_133 ( V_6 ) ) {
V_8 -> V_76 = 1 ;
V_8 -> V_133 = 1 ;
V_8 -> V_242 = 1 ;
V_8 -> V_241 = 1 ;
}
for ( V_72 = 0 ; V_72 < V_8 -> V_242 ; V_72 ++ ) {
V_25 = F_114 ( V_6 , V_8 -> V_243 [ V_72 ] ,
V_8 -> V_288 [ V_72 ] , V_72 ) ;
if ( V_25 < 0 )
return V_25 ;
}
V_25 = F_134 ( V_6 , & V_8 -> V_71 ) ;
if ( V_25 < 0 )
return V_25 ;
if ( V_8 -> V_61 > 0 ) {
V_25 = F_117 ( V_6 ) ;
if ( V_25 < 0 )
return V_25 ;
}
if ( V_8 -> V_255 > 0 && ! V_8 -> V_9 )
if ( ( V_25 = F_127 ( V_6 ,
& V_8 -> V_71 ) ) < 0 )
return V_25 ;
if ( V_8 -> V_241 > 0 ) {
V_25 = F_123 ( V_6 ) ;
if ( V_25 < 0 )
return V_25 ;
}
if ( V_8 -> V_80 > 0 ) {
V_25 = F_124 ( V_6 ) ;
if ( V_25 < 0 )
return V_25 ;
}
V_25 = F_91 ( V_8 ) ;
if ( V_25 < 0 )
return V_25 ;
V_8 -> V_30 . V_289 = V_8 -> V_30 . V_185 * 2 ;
if ( V_8 -> V_30 . V_289 > 2 )
V_8 -> V_290 = 1 ;
for ( V_72 = V_6 -> V_291 ; V_72 < V_6 -> V_291 + V_6 -> V_292 ; V_72 ++ ) {
unsigned int V_219 = F_33 ( V_6 , V_72 ) ;
if ( V_219 & V_196 ) {
switch ( F_98 ( V_219 ) ) {
case V_195 :
if ( ! V_277 )
V_277 = V_72 ;
break;
case V_293 :
if ( ! V_278 )
V_278 = V_72 ;
break;
}
}
}
if ( V_8 -> V_71 . V_294 )
V_8 -> V_30 . V_31 = V_277 ;
if ( V_278 && V_8 -> V_71 . V_295 )
V_8 -> V_85 = V_278 ;
if ( V_8 -> V_165 . V_296 )
V_8 -> V_75 [ V_8 -> V_74 ++ ] = V_8 -> V_165 . V_296 ;
V_8 -> V_47 = & V_8 -> V_177 ;
if ( ! V_8 -> V_9 )
V_8 -> V_9 = & V_8 -> V_253 ;
V_8 -> V_19 = & V_8 -> V_24 ;
V_8 -> V_59 = & V_8 -> V_227 ;
return 1 ;
}
static int F_144 ( struct V_5 * V_6 ,
struct V_69 * V_70 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
T_1 V_103 = V_70 -> V_97 [ 0 ] ;
if ( ! V_103 )
return 0 ;
if ( F_112 ( V_6 , V_103 ) )
V_8 -> V_94 = 1 ;
return 0 ;
}
static int F_145 ( struct V_5 * V_6 ,
struct V_69 * V_70 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
int V_25 ;
T_1 V_297 = 0x0 ;
int V_72 ;
for ( V_72 = 0 ; V_72 < V_8 -> V_71 . V_187 && V_297 == 0x0 ; V_72 ++ ) {
T_1 V_103 = V_8 -> V_71 . V_200 [ V_72 ] ;
unsigned int V_81 = F_33 ( V_6 , V_103 ) ;
V_81 &= ( V_298 | V_82 ) ;
if ( V_81 == V_82 )
V_297 = V_103 ;
}
if ( V_297 == 0 && V_8 -> V_71 . V_187 == 0 ) {
for ( V_72 = 0 ; V_72 < V_8 -> V_71 . V_99 && V_297 == 0x0 ; V_72 ++ ) {
T_1 V_103 = V_8 -> V_71 . V_100 [ V_72 ] ;
unsigned int V_299 ;
V_299 = F_88 ( V_6 , V_103 ) ;
if ( F_131 ( V_299 ) == V_300 ) {
unsigned int V_81 = F_33 ( V_6 , V_103 ) ;
V_81 &= ( V_298 | V_82 ) ;
if ( V_81 == V_82 )
V_297 = V_103 ;
}
}
}
if ( V_297 ) {
V_25 = F_113 ( V_6 , L_26 , V_297 , 1 ) ;
if ( V_25 < 0 )
return V_25 ;
}
return 0 ;
}
static int F_146 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
int V_25 ;
if ( ( V_25 = F_141 ( V_6 , & V_8 -> V_71 , NULL ) ) < 0 )
return V_25 ;
if ( ( V_25 = F_134 ( V_6 , & V_8 -> V_71 ) ) < 0 )
return V_25 ;
if ( ( V_25 = F_144 ( V_6 , & V_8 -> V_71 ) ) < 0 )
return V_25 ;
if ( ( V_25 = F_145 ( V_6 , & V_8 -> V_71 ) ) < 0 )
return V_25 ;
if ( V_8 -> V_241 > 0 ) {
V_25 = F_123 ( V_6 ) ;
if ( V_25 < 0 )
return V_25 ;
}
V_25 = F_91 ( V_8 ) ;
if ( V_25 < 0 )
return V_25 ;
if ( V_8 -> V_71 . V_294 )
V_8 -> V_30 . V_31 = 0x05 ;
if ( V_8 -> V_71 . V_295 )
V_8 -> V_85 = 0x04 ;
if ( V_8 -> V_165 . V_296 )
V_8 -> V_75 [ V_8 -> V_74 ++ ] = V_8 -> V_165 . V_296 ;
V_8 -> V_47 = & V_8 -> V_177 ;
V_8 -> V_9 = & V_8 -> V_253 ;
return 1 ;
}
static void F_147 ( struct V_5 * V_6 , unsigned int V_301 ,
unsigned int V_302 , unsigned int V_303 )
{
unsigned int V_304 , V_305 , V_306 ;
F_13 ( L_41 , V_38 , V_301 , V_302 , V_303 ) ;
V_304 = F_14 ( V_6 , V_6 -> V_66 , 0 ,
V_307 , 0 ) ;
V_304 = ( V_304 & ~ V_302 ) | ( V_303 & V_302 ) ;
V_305 = F_14 ( V_6 , V_6 -> V_66 , 0 ,
V_308 , 0 ) ;
V_305 |= V_301 ;
V_306 = F_14 ( V_6 , V_6 -> V_66 , 0 ,
V_309 , 0 ) ;
V_306 |= V_302 ;
F_61 ( V_6 , V_6 -> V_66 , 0 , 0x7e7 , 0 ) ;
F_61 ( V_6 , V_6 -> V_66 , 0 ,
V_310 , V_305 ) ;
F_14 ( V_6 , V_6 -> V_66 , 0 ,
V_311 , V_306 ) ;
F_46 ( 1 ) ;
F_14 ( V_6 , V_6 -> V_66 , 0 ,
V_312 , V_304 ) ;
}
static int F_42 ( struct V_5 * V_6 ,
T_1 V_27 , int type )
{
#ifdef F_148
int V_172 = F_88 ( V_6 , V_27 ) ;
int V_313 = F_128 ( V_172 ) ;
if ( V_313 && V_313 != V_314 )
return 0 ;
return F_149 ( V_6 , V_27 , type , NULL ) ;
#else
return 0 ;
#endif
}
static int F_150 ( struct V_7 * V_8 , T_1 V_27 ,
unsigned char type , int V_303 )
{
struct V_315 * V_316 ;
F_81 ( & V_8 -> V_317 , sizeof( * V_316 ) , 32 ) ;
V_316 = F_82 ( & V_8 -> V_317 ) ;
if ( ! V_316 )
return - V_170 ;
V_316 -> V_27 = V_27 ;
V_316 -> type = type ;
V_316 -> V_318 = V_8 -> V_317 . V_319 ;
V_316 -> V_303 = V_303 ;
return V_316 -> V_318 ;
}
static struct V_315 * F_151 ( struct V_5 * V_6 ,
T_1 V_27 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
struct V_315 * V_316 = V_8 -> V_317 . V_296 ;
int V_72 ;
for ( V_72 = 0 ; V_72 < V_8 -> V_317 . V_319 ; V_72 ++ , V_316 ++ ) {
if ( V_316 -> V_27 == V_27 )
return V_316 ;
}
return NULL ;
}
static struct V_315 * F_152 ( struct V_5 * V_6 ,
unsigned char V_318 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
struct V_315 * V_316 = V_8 -> V_317 . V_296 ;
int V_72 ;
for ( V_72 = 0 ; V_72 < V_8 -> V_317 . V_319 ; V_72 ++ , V_316 ++ ) {
if ( V_316 -> V_318 == V_318 )
return V_316 ;
}
return NULL ;
}
static int F_153 ( struct V_5 * V_6 , T_1 V_27 ,
unsigned int type )
{
struct V_315 * V_316 ;
int V_318 ;
if ( ! F_112 ( V_6 , V_27 ) )
return 0 ;
V_316 = F_151 ( V_6 , V_27 ) ;
if ( V_316 ) {
if ( V_316 -> type != type )
return 0 ;
V_318 = V_316 -> V_318 ;
} else {
V_318 = F_150 ( V_6 -> V_8 , V_27 , type , 0 ) ;
if ( V_318 < 0 )
return 0 ;
}
F_15 ( V_6 , V_27 , 0 ,
V_320 ,
V_321 | V_318 ) ;
return 1 ;
}
static int F_154 ( struct V_69 * V_70 , T_1 V_27 )
{
int V_72 ;
for ( V_72 = 0 ; V_72 < V_70 -> V_95 ; V_72 ++ )
if ( V_70 -> V_97 [ V_72 ] == V_27 )
return 1 ;
return 0 ;
}
static void F_155 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
const T_1 * V_183 ;
for ( V_183 = V_8 -> V_322 ; * V_183 ; V_183 ++ )
if ( ! F_96 ( V_8 , * V_183 ) )
F_61 ( V_6 , * V_183 , 0 ,
V_118 , V_120 ) ;
}
static inline int F_156 ( struct V_5 * V_6 , const char * V_323 ,
int * V_324 )
{
const char * V_325 ;
V_325 = F_157 ( V_6 , V_323 ) ;
if ( V_325 ) {
unsigned long V_26 ;
if ( ! F_158 ( V_325 , 0 , & V_26 ) ) {
* V_324 = V_26 ;
return 1 ;
}
}
return 0 ;
}
static void F_159 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
int V_26 ;
V_26 = F_30 ( V_6 , L_42 ) ;
if ( V_26 >= 0 )
V_8 -> V_94 = V_26 ;
if ( F_156 ( V_6 , L_43 , & V_8 -> V_326 ) ) {
V_8 -> V_327 = V_8 -> V_86 = V_8 -> V_328 =
V_8 -> V_326 ;
}
if ( F_156 ( V_6 , L_44 , & V_8 -> V_86 ) )
V_8 -> V_326 &= V_8 -> V_326 ;
if ( F_156 ( V_6 , L_45 , & V_8 -> V_328 ) )
V_8 -> V_86 &= V_8 -> V_326 ;
if ( F_156 ( V_6 , L_46 , & V_8 -> V_327 ) )
V_8 -> V_327 &= V_8 -> V_326 ;
if ( F_156 ( V_6 , L_47 , & V_8 -> V_329 ) )
V_8 -> V_329 &= V_8 -> V_326 ;
V_26 = F_30 ( V_6 , L_48 ) ;
if ( V_26 >= 0 )
V_8 -> V_330 = V_26 ;
F_156 ( V_6 , L_49 , & V_8 -> V_331 ) ;
if ( F_156 ( V_6 , L_50 , & V_8 -> V_332 ) ) {
V_8 -> V_326 |= V_8 -> V_332 ;
V_8 -> V_86 |= V_8 -> V_332 ;
if ( V_8 -> V_331 )
V_8 -> V_328 |= V_8 -> V_332 ;
}
}
static int F_160 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
struct V_69 * V_70 = & V_8 -> V_71 ;
unsigned int V_333 ;
int V_72 ;
F_161 ( V_6 , V_8 -> V_334 ) ;
if ( V_8 -> V_117 )
for ( V_72 = 0 ; V_72 < V_8 -> V_133 ; V_72 ++ )
F_61 ( V_6 ,
V_8 -> V_115 [ V_72 ] , 0 ,
V_118 , V_120 ) ;
F_159 ( V_6 ) ;
V_333 = V_8 -> V_328 ;
if ( ! V_8 -> V_330 )
V_333 |= V_8 -> V_327 ;
F_147 ( V_6 , V_8 -> V_326 , V_8 -> V_86 , V_333 ) ;
if ( V_8 -> V_94 ) {
for ( V_72 = 0 ; V_72 < V_70 -> V_95 ; V_72 ++ ) {
T_1 V_27 = V_70 -> V_97 [ V_72 ] ;
F_153 ( V_6 , V_27 , V_335 ) ;
}
if ( V_70 -> V_179 == V_180 &&
V_70 -> V_187 > 0 ) {
for ( V_72 = 0 ; V_72 < V_70 -> V_99 ; V_72 ++ ) {
T_1 V_27 = V_70 -> V_100 [ V_72 ] ;
F_153 ( V_6 , V_27 , V_336 ) ;
}
}
F_68 ( V_6 , V_8 -> V_71 . V_100 [ 0 ] ,
V_44 ) ;
if ( V_70 -> V_97 [ 0 ] )
F_71 ( V_6 , V_70 -> V_97 [ 0 ] ) ;
else if ( V_70 -> V_100 [ 0 ] )
F_71 ( V_6 , V_70 -> V_100 [ 0 ] ) ;
} else {
F_136 ( V_6 ) ;
F_137 ( V_6 ) ;
for ( V_72 = 0 ; V_72 < V_70 -> V_95 ; V_72 ++ )
F_162 ( V_6 , V_70 -> V_97 [ V_72 ] , 1 ) ;
}
if ( V_8 -> V_76 ) {
if ( V_8 -> V_18 )
F_15 ( V_6 , V_8 -> V_18 [ 0 ] , 0 ,
V_56 , 0 ) ;
if ( F_153 ( V_6 , V_8 -> V_271 . V_103 , V_337 ) )
F_71 ( V_6 , V_8 -> V_271 . V_103 ) ;
if ( F_153 ( V_6 , V_8 -> V_273 . V_103 ,
V_337 ) )
F_71 ( V_6 , V_8 -> V_273 . V_103 ) ;
}
for ( V_72 = 0 ; V_72 < V_70 -> V_101 ; V_72 ++ ) {
T_1 V_27 = V_70 -> V_102 [ V_72 ] . V_103 ;
int type = V_70 -> V_102 [ V_72 ] . type ;
unsigned int V_37 , V_338 ;
if ( type == V_184 ) {
V_37 = F_66 ( V_6 , V_27 ) ;
V_37 |= V_43 ;
F_68 ( V_6 , V_27 , V_37 ) ;
} else {
V_37 = F_14 ( V_6 , V_27 , 0 ,
V_39 , 0 ) ;
if ( ! ( V_37 & V_43 ) ||
( V_37 & V_44 ) ) {
V_37 &= ~ V_44 ;
V_37 |= V_43 ;
F_68 ( V_6 , V_27 , V_37 ) ;
}
}
V_338 = F_88 ( V_6 , V_27 ) ;
if ( F_128 ( V_338 ) != V_314 ) {
if ( F_153 ( V_6 , V_27 , V_339 ) )
F_71 ( V_6 , V_27 ) ;
}
}
for ( V_72 = 0 ; V_72 < V_8 -> V_255 ; V_72 ++ )
F_68 ( V_6 , V_8 -> V_257 [ V_72 ] ,
V_43 ) ;
if ( V_70 -> V_340 [ 0 ] )
F_68 ( V_6 , V_70 -> V_340 [ 0 ] ,
V_44 ) ;
if ( V_70 -> V_295 )
F_68 ( V_6 , V_70 -> V_295 ,
V_43 ) ;
for ( V_72 = 0 ; V_72 < V_8 -> V_341 ; V_72 ++ ) {
T_1 V_27 = V_8 -> V_342 [ V_72 ] ;
int V_37 , V_172 ;
if ( ! V_8 -> V_94 ||
V_8 -> V_343 == V_27 ) {
F_162 ( V_6 , V_27 , 1 ) ;
continue;
}
if ( F_154 ( V_70 , V_27 ) )
continue;
V_37 = F_14 ( V_6 , V_27 , 0 ,
V_39 , 0 ) ;
if ( V_37 & V_43 ) {
F_162 ( V_6 , V_27 , 1 ) ;
continue;
}
V_172 = F_88 ( V_6 , V_27 ) ;
V_172 = F_128 ( V_172 ) ;
if ( V_172 != V_344 ) {
if ( V_172 != V_259 )
F_162 ( V_6 , V_27 , 1 ) ;
continue;
}
if ( F_153 ( V_6 , V_27 , V_345 ) ) {
F_71 ( V_6 , V_27 ) ;
continue;
}
F_162 ( V_6 , V_27 , 0 ) ;
}
if ( V_8 -> V_332 )
F_163 ( V_6 , 0x01 ) ;
if ( V_8 -> V_322 )
F_155 ( V_6 ) ;
return 0 ;
}
static void F_41 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
if ( V_8 -> V_165 . V_296 ) {
struct V_161 * V_346 = V_8 -> V_165 . V_296 ;
int V_72 ;
for ( V_72 = 0 ; V_72 < V_8 -> V_165 . V_319 ; V_72 ++ )
F_164 ( V_346 [ V_72 ] . V_126 ) ;
}
F_165 ( & V_8 -> V_165 ) ;
}
static void F_166 ( struct V_5 * V_6 )
{
unsigned int V_72 , V_172 ;
if ( V_6 -> V_347 -> V_348 )
return;
for ( V_72 = 0 ; V_72 < V_6 -> V_349 . V_319 ; V_72 ++ ) {
struct V_350 * V_103 = F_167 ( & V_6 -> V_349 , V_72 ) ;
V_172 = F_88 ( V_6 , V_103 -> V_27 ) ;
if ( F_128 ( V_172 ) != V_259 )
F_61 ( V_6 , V_103 -> V_27 , 0 ,
V_41 , 0 ) ;
}
}
static void F_168 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
F_166 ( V_6 ) ;
if ( V_8 -> V_327 )
F_147 ( V_6 , V_8 -> V_326 ,
V_8 -> V_86 , V_8 -> V_328 &
~ V_8 -> V_327 ) ;
}
static void F_169 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
if ( ! V_8 )
return;
F_168 ( V_6 ) ;
F_170 ( V_6 ) ;
F_165 ( & V_8 -> V_317 ) ;
F_164 ( V_8 ) ;
F_171 ( V_6 ) ;
}
static void F_172 ( struct V_5 * V_6 , T_1 V_27 ,
unsigned int V_351 )
{
unsigned int V_352 , V_353 ;
V_353 = F_14 ( V_6 , V_27 ,
0 , V_39 , 0x00 ) ;
if ( V_353 & V_43 ) {
struct V_7 * V_8 = V_6 -> V_8 ;
if ( V_27 == V_8 -> V_155 || V_27 == V_8 -> V_154 )
return;
}
V_352 = V_353 ;
if ( V_351 & ( V_43 | V_44 ) )
V_353 &= ~ ( V_43 | V_44 ) ;
V_353 |= V_351 ;
if ( V_352 != V_353 )
F_15 ( V_6 , V_27 , 0 ,
V_41 ,
V_353 ) ;
}
static void F_173 ( struct V_5 * V_6 , T_1 V_27 ,
unsigned int V_351 )
{
unsigned int V_353 = F_14 ( V_6 , V_27 ,
0 , V_39 , 0x00 ) ;
if ( V_353 & V_351 )
F_15 ( V_6 , V_27 , 0 ,
V_41 ,
V_353 & ~ V_351 ) ;
}
static inline int F_174 ( struct V_5 * V_6 , T_1 V_27 )
{
if ( ! V_27 )
return 0 ;
return F_175 ( V_6 , V_27 ) ;
}
static void F_176 ( struct V_5 * V_6 ,
int V_354 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
struct V_69 * V_70 = & V_8 -> V_71 ;
int V_72 ;
for ( V_72 = 0 ; V_72 < V_70 -> V_99 ; V_72 ++ ) {
if ( V_354 )
break;
V_354 = F_174 ( V_6 , V_70 -> V_100 [ V_72 ] ) ;
if ( V_354 ) {
unsigned int V_37 ;
V_37 = F_14 ( V_6 ,
V_70 -> V_100 [ V_72 ] , 0 ,
V_39 , 0 ) ;
if ( V_37 & V_43 )
V_354 = 0 ;
}
}
if ( V_354 ) {
for ( V_72 = 0 ; V_72 < V_70 -> V_187 ; V_72 ++ )
F_173 ( V_6 , V_70 -> V_200 [ V_72 ] ,
V_44 ) ;
if ( V_8 -> V_327 && V_8 -> V_330 )
F_147 ( V_6 , V_8 -> V_326 ,
V_8 -> V_86 , V_8 -> V_328 &
~ V_8 -> V_327 ) ;
} else {
for ( V_72 = 0 ; V_72 < V_70 -> V_187 ; V_72 ++ )
F_172 ( V_6 , V_70 -> V_200 [ V_72 ] ,
V_44 ) ;
if ( V_8 -> V_327 && V_8 -> V_330 )
F_147 ( V_6 , V_8 -> V_326 ,
V_8 -> V_86 , V_8 -> V_328 |
V_8 -> V_327 ) ;
}
}
static int F_177 ( struct V_7 * V_8 , int V_72 )
{
struct V_69 * V_70 = & V_8 -> V_71 ;
if ( V_70 -> V_97 [ V_72 ] == V_8 -> V_155 )
return 1 ;
if ( V_70 -> V_97 [ V_72 ] == V_8 -> V_154 )
return 1 ;
if ( V_70 -> V_97 [ V_72 ] == V_8 -> V_152 )
return 1 ;
return 0 ;
}
static void F_178 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
struct V_69 * V_70 = & V_8 -> V_71 ;
int V_72 , V_354 ;
V_354 = 0 ;
if ( V_8 -> V_329 )
V_354 = ! ( F_14 ( V_6 , V_6 -> V_66 , 0 ,
V_307 , 0 ) & V_8 -> V_329 ) ;
for ( V_72 = 0 ; V_72 < V_70 -> V_95 ; V_72 ++ ) {
if ( V_354 )
break;
if ( F_177 ( V_8 , V_72 ) )
continue;
V_354 = F_174 ( V_6 , V_70 -> V_97 [ V_72 ] ) ;
if ( V_354 ) {
unsigned int V_37 ;
V_37 = F_14 ( V_6 , V_70 -> V_97 [ V_72 ] , 0 ,
V_39 , 0 ) ;
if ( V_37 & V_43 )
V_354 = 0 ;
}
}
if ( V_354 ) {
if ( V_8 -> V_152 )
F_173 ( V_6 , V_8 -> V_152 ,
V_44 ) ;
for ( V_72 = 0 ; V_72 < V_70 -> V_99 ; V_72 ++ )
F_173 ( V_6 , V_70 -> V_100 [ V_72 ] ,
V_44 ) ;
} else {
if ( V_8 -> V_152 )
F_172 ( V_6 , V_8 -> V_152 ,
V_44 ) ;
for ( V_72 = 0 ; V_72 < V_70 -> V_99 ; V_72 ++ )
F_172 ( V_6 , V_70 -> V_100 [ V_72 ] ,
V_44 ) ;
}
F_176 ( V_6 , V_354 ) ;
for ( V_72 = 0 ; V_72 < V_70 -> V_95 ; V_72 ++ ) {
unsigned int V_26 = V_44 | V_274 ;
if ( F_177 ( V_8 , V_72 ) )
continue;
if ( V_354 )
F_172 ( V_6 , V_70 -> V_97 [ V_72 ] , V_26 ) ;
#if 0
else
stac92xx_reset_pinctl(codec, cfg->hp_pins[i], val);
#endif
}
}
static void F_162 ( struct V_5 * V_6 , T_1 V_27 ,
int V_355 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
unsigned int V_51 , V_26 ;
for ( V_51 = 0 ; V_51 < V_8 -> V_341 ; V_51 ++ ) {
if ( V_8 -> V_342 [ V_51 ] == V_27 )
break;
}
if ( V_51 >= V_8 -> V_341 )
return;
V_51 = 1 << V_51 ;
V_26 = F_14 ( V_6 , V_6 -> V_66 , 0 , 0x0fec , 0x0 ) & 0xff ;
if ( V_355 )
V_26 &= ~ V_51 ;
else
V_26 |= V_51 ;
F_61 ( V_6 , V_6 -> V_66 , 0 , 0x7ec , V_26 ) ;
}
static void F_179 ( struct V_5 * V_6 , T_1 V_27 )
{
F_162 ( V_6 , V_27 , F_174 ( V_6 , V_27 ) ) ;
}
static unsigned int F_180 ( struct V_5 * V_6 , int V_51 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
unsigned int V_70 ;
V_70 = F_88 ( V_6 , V_8 -> V_107 [ V_51 ] ) ;
return F_128 ( V_70 ) ;
}
static int F_181 ( struct V_5 * V_6 ,
const T_1 * V_356 , int V_357 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
int V_51 , V_358 ;
unsigned int V_172 ;
for ( V_358 = 0 ; V_358 < V_357 ; V_358 ++ ) {
for ( V_51 = 0 ; V_51 < V_8 -> V_106 ; V_51 ++ )
if ( V_8 -> V_107 [ V_51 ] == V_356 [ V_358 ] )
break;
if ( V_51 >= V_8 -> V_106 )
break;
V_172 = F_180 ( V_6 , V_51 ) ;
if ( V_172 == V_259 )
break;
}
return V_358 ;
}
static void F_182 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
struct V_268 * V_269 ;
if ( F_174 ( V_6 , V_8 -> V_271 . V_103 ) )
V_269 = & V_8 -> V_271 ;
else if ( F_174 ( V_6 , V_8 -> V_273 . V_103 ) )
V_269 = & V_8 -> V_273 ;
else
V_269 = & V_8 -> V_272 ;
if ( V_269 -> V_12 >= 0 )
F_15 ( V_6 , V_8 -> V_18 [ 0 ] , 0 ,
V_56 ,
V_269 -> V_12 ) ;
if ( V_269 -> V_270 >= 0 )
F_15 ( V_6 , V_8 -> V_55 [ 0 ] , 0 ,
V_56 ,
V_269 -> V_270 ) ;
}
static void F_71 ( struct V_5 * V_6 , T_1 V_27 )
{
struct V_315 * V_316 = F_151 ( V_6 , V_27 ) ;
if ( ! V_316 )
return;
V_6 -> V_359 . V_360 ( V_6 , ( unsigned ) V_316 -> V_318 << 26 ) ;
}
static void F_183 ( struct V_5 * V_6 , unsigned int V_361 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
struct V_315 * V_316 ;
int V_318 , V_303 ;
V_318 = ( V_361 >> 26 ) & 0x7f ;
V_316 = F_152 ( V_6 , V_318 ) ;
if ( ! V_316 )
return;
switch ( V_316 -> type ) {
case V_335 :
case V_336 :
F_178 ( V_6 ) ;
break;
case V_337 :
F_182 ( V_6 ) ;
break;
}
switch ( V_316 -> type ) {
case V_335 :
case V_336 :
case V_337 :
case V_339 :
case V_345 :
if ( V_8 -> V_341 > 0 )
F_179 ( V_6 , V_316 -> V_27 ) ;
F_184 ( V_6 , V_316 -> V_27 ) ;
switch ( V_6 -> V_362 ) {
case 0x103c308f :
if ( V_316 -> V_27 == 0xb ) {
int V_103 = V_43 ;
if ( F_174 ( V_6 , 0xa )
&& F_174 ( V_6 , 0xb ) )
V_103 |= V_146 ;
if ( ! F_174 ( V_6 , 0xb ) )
V_103 |= V_146 ;
F_68 ( V_6 , 0x0a , V_103 ) ;
}
}
break;
case V_363 :
V_303 = F_14 ( V_6 , V_6 -> V_66 , 0 ,
V_307 , 0 ) ;
F_61 ( V_6 , V_6 -> V_66 , 0 , 0x7e0 ,
! ! ( V_303 & ( 1 << V_316 -> V_303 ) ) ) ;
break;
}
}
static void F_185 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
unsigned int V_333 ;
if ( V_8 -> V_332 )
return;
V_333 = F_186 ( V_6 , V_6 -> V_66 , V_364 ) ;
V_333 &= V_365 ;
if ( V_333 > 3 )
V_8 -> V_332 = 0x08 ;
else
V_8 -> V_332 = 0x01 ;
}
static int F_187 ( struct V_5 * V_6 , int V_366 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
const struct V_367 * V_368 = NULL ;
if ( ( V_6 -> V_362 >> 16 ) == V_369 ) {
while ( ( V_368 = F_188 ( V_370 ,
NULL , V_368 ) ) ) {
if ( sscanf ( V_368 -> V_126 , L_51 ,
& V_8 -> V_331 ,
& V_8 -> V_332 ) == 2 ) {
unsigned int V_371 ;
V_371 = F_186 ( V_6 , V_6 -> V_66 ,
V_364 ) ;
V_371 &= V_365 ;
if ( V_8 -> V_332 < V_371 )
V_8 -> V_332 = 1 << V_8 -> V_332 ;
else
V_8 -> V_343 = V_8 -> V_332 ;
return 1 ;
}
if ( sscanf ( V_368 -> V_126 , L_52 ,
& V_8 -> V_331 ) == 1 ) {
F_185 ( V_6 ) ;
return 1 ;
}
if ( strstr ( V_368 -> V_126 , L_53 ) ) {
F_185 ( V_6 ) ;
V_8 -> V_331 = 1 ;
return 1 ;
}
}
if ( ! F_189 ( V_6 -> V_362 ) ) {
F_185 ( V_6 ) ;
V_8 -> V_331 = V_366 ;
return 1 ;
}
}
return 0 ;
}
static int F_189 ( T_2 V_362 )
{
switch ( V_362 ) {
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
static void F_190 ( struct V_372 * V_373 ,
struct V_5 * V_6 , T_1 V_27 )
{
if ( V_27 == V_6 -> V_66 )
F_191 ( V_373 , L_54 ,
F_14 ( V_6 , V_27 , 0 , 0x0fec , 0x0 ) ) ;
}
static void F_192 ( struct V_372 * V_373 ,
struct V_5 * V_6 ,
unsigned int V_374 )
{
F_191 ( V_373 , L_55 ,
F_14 ( V_6 , V_6 -> V_66 , 0 , V_374 , 0 ) ) ;
}
static void F_193 ( struct V_372 * V_373 ,
struct V_5 * V_6 , T_1 V_27 )
{
F_190 ( V_373 , V_6 , V_27 ) ;
if ( V_27 == V_6 -> V_66 )
F_192 ( V_373 , V_6 , 0xfa0 ) ;
}
static void F_194 ( struct V_372 * V_373 ,
struct V_5 * V_6 , T_1 V_27 )
{
if ( V_27 == V_6 -> V_66 )
F_192 ( V_373 , V_6 , 0xfe0 ) ;
}
static void F_195 ( struct V_372 * V_373 ,
struct V_5 * V_6 , T_1 V_27 )
{
if ( V_27 == V_6 -> V_66 )
F_192 ( V_373 , V_6 , 0xfeb ) ;
}
static int F_196 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
F_160 ( V_6 ) ;
F_197 ( V_6 ) ;
F_198 ( V_6 ) ;
if ( V_8 -> V_94 ) {
if ( V_8 -> V_71 . V_97 [ 0 ] )
F_71 ( V_6 , V_8 -> V_71 . V_97 [ 0 ] ) ;
else if ( V_8 -> V_71 . V_100 [ 0 ] )
F_71 ( V_6 ,
V_8 -> V_71 . V_100 [ 0 ] ) ;
}
return 0 ;
}
static int F_199 ( struct V_5 * V_6 , T_3 V_375 )
{
F_168 ( V_6 ) ;
return 0 ;
}
static int F_200 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
if ( V_8 -> V_343 )
F_12 ( V_6 , V_8 -> V_343 ,
V_8 -> V_376 ) ;
else if ( V_8 -> V_332 )
F_147 ( V_6 , V_8 -> V_326 ,
V_8 -> V_86 , V_8 -> V_328 ) ;
return 0 ;
}
static void F_201 ( struct V_5 * V_6 , T_1 V_377 ,
unsigned int V_378 )
{
unsigned int V_379 = V_378 ;
struct V_7 * V_8 = V_6 -> V_8 ;
if ( V_378 == V_120 ) {
if ( V_8 -> V_343 ) {
V_379 = V_380 ;
}
F_46 ( 100 ) ;
}
F_14 ( V_6 , V_377 , 0 , V_118 ,
V_379 ) ;
F_202 ( V_6 , V_377 , V_378 , true ) ;
}
static int F_203 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
int V_72 , V_381 , V_382 = 1 ;
unsigned int V_383 , V_384 ;
T_1 V_27 ;
if ( ! V_8 -> V_332 )
return 0 ;
for ( V_72 = 0 ; V_72 < V_8 -> V_30 . V_185 ; V_72 ++ ) {
V_27 = V_8 -> V_30 . V_88 [ V_72 ] ;
if ( ! ( F_204 ( V_6 , V_27 , 0 , V_35 , 0 ) &
V_34 ) ) {
V_382 = 0 ;
break;
}
}
if ( V_382 && V_8 -> V_30 . V_197 )
if ( ! ( F_204 ( V_6 ,
V_8 -> V_30 . V_197 , 0 , V_35 , 0 ) &
V_34 ) ) {
V_382 = 0 ;
}
V_381 = F_110 ( V_8 -> V_30 . V_215 ) ;
for ( V_72 = 0 ; V_382 && V_72 < V_381 ; V_72 ++ ) {
V_27 = V_8 -> V_30 . V_215 [ V_72 ] ;
if ( V_27 == 0 )
break;
if ( ! ( F_204 ( V_6 , V_27 , 0 , V_35 , 0 ) &
V_34 ) ) {
V_382 = 0 ;
}
}
if ( ! V_8 -> V_343 ) {
if ( V_382 )
V_8 -> V_328 &= ~ V_8 -> V_332 ;
else
V_8 -> V_328 |= V_8 -> V_332 ;
if ( ! V_8 -> V_331 ) {
V_8 -> V_328 ^= V_8 -> V_332 ;
}
F_147 ( V_6 , V_8 -> V_326 ,
V_8 -> V_86 , V_8 -> V_328 ) ;
} else {
V_384 = V_8 -> V_331 ?
V_45 : V_150 ;
V_383 = V_8 -> V_331 ?
V_150 : V_45 ;
V_8 -> V_376 = V_382 ? V_383 : V_384 ;
F_12 ( V_6 , V_8 -> V_343 ,
V_8 -> V_376 ) ;
}
return 0 ;
}
static int F_205 ( struct V_5 * V_6 ,
T_1 V_27 )
{
F_203 ( V_6 ) ;
return 0 ;
}
static int F_206 ( struct V_5 * V_6 )
{
struct V_7 * V_8 ;
int V_25 ;
V_8 = F_207 ( sizeof( * V_8 ) , V_166 ) ;
if ( V_8 == NULL )
return - V_170 ;
V_6 -> V_385 = 1 ;
V_6 -> V_8 = V_8 ;
V_8 -> V_287 = 1 ;
V_8 -> V_106 = F_110 ( V_386 ) ;
V_8 -> V_107 = V_386 ;
V_8 -> V_387 = F_208 ( V_6 , V_388 ,
V_389 ,
V_390 ) ;
if ( V_8 -> V_387 < 0 )
F_13 ( V_391 L_56 ,
V_6 -> V_392 ) ;
else
F_43 ( V_6 ,
V_393 [ V_8 -> V_387 ] ) ;
V_8 -> V_30 . V_289 = 2 ;
V_8 -> V_30 . V_185 = 1 ;
V_8 -> V_30 . V_88 = V_394 ;
V_8 -> V_115 = V_395 ;
V_8 -> V_55 = V_396 ;
V_8 -> V_241 = 1 ;
V_8 -> V_255 = 0 ;
V_8 -> V_133 = 1 ;
V_8 -> V_341 = 0 ;
if ( V_8 -> V_387 == V_397 ||
V_8 -> V_387 == V_398 ||
V_8 -> V_387 == V_399 )
V_8 -> V_334 = V_400 ;
else
V_8 -> V_334 = V_401 ;
V_8 -> V_73 = V_402 ;
if ( V_8 -> V_387 == V_403 ) {
V_8 -> V_326 = V_8 -> V_86 = 0x09 ;
V_8 -> V_328 = 0x00 ;
}
V_25 = F_146 ( V_6 ) ;
if ( V_25 < 0 ) {
F_169 ( V_6 ) ;
return V_25 ;
}
if ( V_8 -> V_387 == V_403 )
V_8 -> V_94 = 0 ;
V_6 -> V_359 = V_404 ;
return 0 ;
}
static int F_209 ( struct V_5 * V_6 )
{
struct V_7 * V_8 ;
int V_25 ;
V_8 = F_207 ( sizeof( * V_8 ) , V_166 ) ;
if ( V_8 == NULL )
return - V_170 ;
V_6 -> V_385 = 1 ;
V_6 -> V_8 = V_8 ;
V_8 -> V_287 = 1 ;
V_8 -> V_106 = F_110 ( V_405 ) ;
V_8 -> V_107 = V_405 ;
V_8 -> V_387 = F_210 ( V_6 ,
V_406 ,
V_407 ,
V_408 ) ;
if ( V_8 -> V_387 < 0 )
V_8 -> V_387 = F_208 ( V_6 ,
V_406 ,
V_407 ,
V_409 ) ;
V_410:
if ( V_8 -> V_387 < 0 )
F_13 ( V_391 L_56 ,
V_6 -> V_392 ) ;
else
F_43 ( V_6 ,
V_411 [ V_8 -> V_387 ] ) ;
V_8 -> V_30 . V_289 = 2 ;
V_8 -> V_30 . V_185 = 1 ;
V_8 -> V_30 . V_88 = V_412 ;
V_8 -> V_115 = V_413 ;
V_8 -> V_55 = V_414 ;
V_8 -> V_241 = 1 ;
V_8 -> V_133 = 1 ;
V_8 -> V_341 = 0 ;
switch ( V_6 -> V_415 ) {
case 0x83847632 :
case 0x83847633 :
case 0x83847636 :
case 0x83847637 :
V_8 -> V_255 = V_416 ;
V_8 -> V_257 = V_417 ;
V_8 -> V_77 = F_110 ( V_418 ) ;
V_8 -> V_18 = V_418 ;
break;
default:
V_8 -> V_255 = 0 ;
break;
}
V_8 -> V_334 = V_419 ;
V_8 -> V_73 = V_420 ;
V_8 -> V_242 = 1 ;
V_8 -> V_243 = V_421 ;
V_8 -> V_288 = V_422 ;
V_25 = F_140 ( V_6 ) ;
if ( ! V_25 ) {
if ( V_8 -> V_387 < 0 ) {
F_108 ( V_214 L_57
L_58 ) ;
V_8 -> V_387 = V_423 ;
goto V_410;
}
V_25 = - V_232 ;
}
if ( V_25 < 0 ) {
F_169 ( V_6 ) ;
return V_25 ;
}
V_6 -> V_359 = V_404 ;
return 0 ;
}
static int F_211 ( struct V_5 * V_6 )
{
struct V_7 * V_8 ;
T_1 V_191 [ V_424 + 2 ] ;
int V_25 = 0 ;
int V_185 ;
V_8 = F_207 ( sizeof( * V_8 ) , V_166 ) ;
if ( V_8 == NULL )
return - V_170 ;
V_6 -> V_385 = 1 ;
V_6 -> V_8 = V_8 ;
V_8 -> V_287 = 0 ;
V_6 -> V_32 = V_425 ;
V_8 -> V_106 = F_110 ( V_426 ) ;
V_8 -> V_107 = V_426 ;
V_8 -> V_387 = F_208 ( V_6 ,
V_427 ,
V_428 ,
V_429 ) ;
if ( V_8 -> V_387 < 0 )
V_8 -> V_387 =
F_210 ( V_6 ,
V_427 , V_428 ,
V_430 ) ;
V_410:
if ( V_8 -> V_387 < 0 )
F_13 ( V_391 L_56 ,
V_6 -> V_392 ) ;
else
F_43 ( V_6 ,
V_431 [ V_8 -> V_387 ] ) ;
V_185 = F_97 ( V_6 , 0x0a ,
V_191 , V_424 + 2 ) - 1 ;
if ( V_185 < 3 || V_185 > 5 ) {
F_108 ( V_214 L_59
L_60 ) ;
V_185 = V_424 ;
}
V_8 -> V_334 = V_432 ;
switch ( V_185 ) {
case 0x3 :
V_8 -> V_93 = V_433 ;
break;
case 0x4 :
V_8 -> V_93 = V_434 ;
break;
case 0x5 :
V_8 -> V_93 = V_435 ;
break;
}
V_8 -> V_30 . V_88 = V_8 -> V_88 ;
V_8 -> V_63 = 0x01 ;
V_8 -> V_68 = 8 ;
V_8 -> V_285 = 0x1c ;
V_8 -> V_55 = V_436 ;
V_8 -> V_115 = V_437 ;
V_8 -> V_257 = V_438 ;
V_8 -> V_18 = V_439 ;
V_8 -> V_28 = V_440 ;
V_8 -> V_241 = F_110 ( V_436 ) ;
V_8 -> V_133 = F_110 ( V_437 ) ;
V_8 -> V_77 = F_110 ( V_439 ) ;
V_8 -> V_242 = V_441 ;
V_8 -> V_243 = V_442 ;
V_8 -> V_288 = V_443 ;
switch ( V_8 -> V_387 ) {
case V_444 :
V_8 -> V_334 = V_445 ;
case V_446 :
case V_447 :
case V_448 :
V_8 -> V_80 = 0 ;
V_8 -> V_330 = 0 ;
switch ( V_8 -> V_387 ) {
case V_446 :
F_44 ( V_6 , 0x0b , 0x90A70170 ) ;
V_8 -> V_255 = 0 ;
break;
case V_447 :
F_44 ( V_6 , 0x13 , 0x90A60160 ) ;
V_8 -> V_255 = 1 ;
break;
case V_448 :
F_44 ( V_6 , 0x0b , 0x90A70170 ) ;
F_44 ( V_6 , 0x13 , 0x90A60160 ) ;
V_8 -> V_255 = 1 ;
break;
}
break;
case V_449 :
V_8 -> V_255 = V_450 ;
V_8 -> V_80 = F_110 ( V_440 ) ;
V_8 -> V_330 = 0 ;
break;
default:
V_8 -> V_255 = V_450 ;
V_8 -> V_80 = F_110 ( V_440 ) ;
V_8 -> V_330 = 1 ;
break;
}
if ( V_8 -> V_387 != V_451 ) {
V_8 -> V_327 = V_8 -> V_326 = V_8 -> V_86 = 0x1 ;
V_8 -> V_328 = 0x01 ;
}
V_8 -> V_341 = F_110 ( V_452 ) ;
V_8 -> V_342 = V_452 ;
V_25 = F_140 ( V_6 ) ;
if ( ! V_25 ) {
if ( V_8 -> V_387 < 0 ) {
F_108 ( V_214 L_57
L_58 ) ;
V_8 -> V_387 = V_451 ;
goto V_410;
}
V_25 = - V_232 ;
}
if ( V_25 < 0 ) {
F_169 ( V_6 ) ;
return V_25 ;
}
if ( V_8 -> V_387 == V_453 )
V_8 -> V_94 = 0 ;
V_6 -> V_359 = V_404 ;
V_6 -> V_454 = F_193 ;
return 0 ;
}
static int F_212 ( struct V_5 * V_6 )
{
if ( V_6 -> V_415 != 0x111d7605 &&
V_6 -> V_415 != 0x111d76d1 )
return 0 ;
switch ( V_6 -> V_362 ) {
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
static void F_213 ( struct V_5 * V_6 , T_1 V_27 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
unsigned int V_172 = F_88 ( V_6 , V_27 ) ;
int V_72 ;
V_8 -> V_455 [ V_8 -> V_456 ] = V_27 ;
V_8 -> V_456 ++ ;
if ( F_131 ( V_172 ) == V_264 &&
F_128 ( V_172 ) != V_259 ) {
for ( V_72 = 0 ; V_72 < F_110 ( V_457 ) ; V_72 ++ ) {
if ( V_27 == V_457 [ V_72 ] ) {
V_8 -> V_458 [ V_8 -> V_459 ] = V_27 ;
V_8 -> V_459 ++ ;
}
}
}
}
static void F_214 ( struct V_5 * V_6 , T_1 V_27 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
V_8 -> V_460 [ V_8 -> V_461 ] = V_27 ;
V_8 -> V_461 ++ ;
}
static void F_215 ( struct V_5 * V_6 , T_1 V_27 )
{
int V_72 , V_189 ;
struct V_7 * V_8 = V_6 -> V_8 ;
for ( V_72 = 0 ; V_72 < V_8 -> V_461 ; V_72 ++ ) {
if ( F_129 ( V_6 ,
V_8 -> V_460 [ V_72 ] , V_27 ) >= 0 ) {
if ( ! V_8 -> V_462 [ V_72 ] ) {
V_8 -> V_462 [ V_72 ] = V_27 ;
V_8 -> V_463 [ V_72 ] = F_107 ( V_27 ,
3 , 0 , V_35 ) ;
}
for ( V_189 = 0 ; V_189 < V_8 -> V_459 ; V_189 ++ ) {
if ( F_129 ( V_6 , V_27 ,
V_8 -> V_458 [ V_189 ] ) >= 0 ) {
if ( ! V_8 -> V_464 [ V_72 ] )
V_8 -> V_464 [ V_72 ] = V_27 ;
break;
}
}
break;
}
}
}
static void F_216 ( struct V_5 * V_6 )
{
T_1 V_27 , V_465 ;
unsigned int V_219 , V_283 ;
struct V_7 * V_8 = V_6 -> V_8 ;
V_465 = V_6 -> V_291 + V_6 -> V_292 ;
for ( V_27 = V_6 -> V_291 ; V_27 < V_465 ; V_27 ++ ) {
V_219 = F_33 ( V_6 , V_27 ) ;
V_283 = F_98 ( V_219 ) ;
if ( V_283 == V_258 )
F_213 ( V_6 , V_27 ) ;
if ( V_283 == V_293 && ! ( V_219 & V_196 ) )
F_214 ( V_6 , V_27 ) ;
}
for ( V_27 = V_6 -> V_291 ; V_27 < V_465 ; V_27 ++ ) {
V_219 = F_33 ( V_6 , V_27 ) ;
V_283 = F_98 ( V_219 ) ;
if ( V_283 == V_284 )
F_215 ( V_6 , V_27 ) ;
}
V_8 -> V_107 = V_8 -> V_455 ;
V_8 -> V_106 = V_8 -> V_456 ;
V_8 -> V_115 = V_8 -> V_460 ;
V_8 -> V_133 = V_8 -> V_461 ;
V_8 -> V_243 = V_8 -> V_463 ;
V_8 -> V_288 = V_8 -> V_463 ;
V_8 -> V_242 = V_8 -> V_461 ;
V_8 -> V_55 = V_8 -> V_462 ;
V_8 -> V_241 = V_8 -> V_461 ;
V_8 -> V_18 = V_8 -> V_464 ;
V_8 -> V_77 = V_8 -> V_461 ;
V_8 -> V_257 = V_8 -> V_458 ;
V_8 -> V_255 = V_8 -> V_459 ;
}
static int F_217 ( struct V_5 * V_6 )
{
struct V_7 * V_8 ;
int V_25 ;
V_8 = F_207 ( sizeof( * V_8 ) , V_166 ) ;
if ( V_8 == NULL )
return - V_170 ;
if ( F_212 ( V_6 ) ) {
F_44 ( V_6 , 0xa , 0x2101201f ) ;
F_44 ( V_6 , 0xf , 0x2181205e ) ;
}
V_6 -> V_385 = 1 ;
V_6 -> V_8 = V_8 ;
F_216 ( V_6 ) ;
V_8 -> V_287 = 0 ;
V_6 -> V_32 = V_466 ;
V_8 -> V_285 = 0x21 ;
V_8 -> V_342 = V_467 ;
V_8 -> V_341 = F_110 ( V_467 ) ;
V_8 -> V_30 . V_88 = V_8 -> V_88 ;
V_8 -> V_334 = V_468 ;
V_8 -> V_387 = F_208 ( V_6 ,
V_469 ,
V_470 ,
V_471 ) ;
V_410:
if ( V_8 -> V_387 < 0 )
F_13 ( V_391 L_56 ,
V_6 -> V_392 ) ;
else
F_43 ( V_6 ,
V_472 [ V_8 -> V_387 ] ) ;
V_6 -> V_359 = V_404 ;
if ( F_187 ( V_6 , 0 ) )
F_103 ( L_61 ,
V_8 -> V_332 ,
V_8 -> V_331 ) ;
#ifdef F_218
if ( V_8 -> V_332 ) {
if ( ! V_8 -> V_343 ) {
V_8 -> V_326 |= V_8 -> V_332 ;
V_8 -> V_86 |= V_8 -> V_332 ;
V_8 -> V_328 |= V_8 -> V_332 ;
} else {
V_6 -> V_359 . V_473 =
F_201 ;
}
V_6 -> V_359 . V_474 = F_200 ;
V_6 -> V_359 . V_475 =
F_205 ;
}
#endif
V_25 = F_140 ( V_6 ) ;
if ( ! V_25 ) {
if ( V_8 -> V_387 < 0 ) {
F_108 ( V_214 L_57
L_58 ) ;
V_8 -> V_387 = V_476 ;
goto V_410;
}
V_25 = - V_232 ;
}
if ( V_25 < 0 ) {
F_169 ( V_6 ) ;
return V_25 ;
}
V_6 -> V_454 = F_190 ;
return 0 ;
}
static int F_219 ( struct V_5 * V_6 ,
T_1 V_477 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
int V_51 ;
for ( V_51 = 0 ; V_51 < V_8 -> V_106 ; V_51 ++ )
if ( V_8 -> V_107 [ V_51 ] == V_477 )
break;
if ( ( V_51 + 2 ) >= V_8 -> V_106 )
return 0 ;
if ( F_180 ( V_6 , V_51 + 1 ) != V_259 )
return 2 ;
if ( F_180 ( V_6 , V_51 + 2 ) != V_259 )
return 2 ;
if ( F_180 ( V_6 , V_51 ) != V_259 )
return 1 ;
else
return 0 ;
}
static int F_220 ( struct V_1 * V_2 ,
struct V_10 * V_11 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = V_6 -> V_8 ;
V_11 -> V_14 . integer . V_14 [ 0 ] = ! ! ( V_8 -> V_328 & 0x20 ) ;
return 0 ;
}
static int F_221 ( struct V_1 * V_2 ,
struct V_10 * V_11 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = V_6 -> V_8 ;
unsigned int V_328 ;
V_328 = ( V_8 -> V_328 & ~ 0x20 ) |
( V_11 -> V_14 . integer . V_14 [ 0 ] ? 0x20 : 0 ) ;
if ( V_328 == V_8 -> V_328 )
return 0 ;
V_8 -> V_328 = V_328 ;
F_147 ( V_6 , V_8 -> V_326 , V_8 -> V_86 , V_8 -> V_328 ) ;
return 1 ;
}
static int F_222 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
if ( ! F_80 ( V_8 , & V_478 ,
L_62 , 0 ) )
return - V_170 ;
V_8 -> V_326 |= 0x20 ;
V_8 -> V_86 |= 0x20 ;
V_8 -> V_328 |= 0x20 ;
return 0 ;
}
static int F_223 ( struct V_5 * V_6 )
{
struct V_7 * V_8 ;
const struct V_479 * V_480 = V_481 ;
unsigned int V_482 ;
int V_25 = 0 ;
V_8 = F_207 ( sizeof( * V_8 ) , V_166 ) ;
if ( V_8 == NULL )
return - V_170 ;
V_6 -> V_385 = 1 ;
V_6 -> V_8 = V_8 ;
V_8 -> V_287 = 0 ;
V_6 -> V_359 = V_404 ;
V_8 -> V_106 = V_483 ;
switch ( V_6 -> V_415 ) {
case 0x111d76b6 :
case 0x111d76b7 :
V_8 -> V_107 = V_484 ;
break;
case 0x111d7603 :
case 0x111d7608 :
V_8 -> V_106 -- ;
default:
V_8 -> V_107 = V_485 ;
}
V_8 -> V_341 = F_110 ( V_486 ) ;
V_8 -> V_387 = F_208 ( V_6 ,
V_487 ,
V_488 ,
V_489 ) ;
V_410:
if ( V_8 -> V_387 < 0 )
F_13 ( V_391 L_56 ,
V_6 -> V_392 ) ;
else
F_43 ( V_6 ,
V_490 [ V_8 -> V_387 ] ) ;
if ( V_8 -> V_387 != V_491 ) {
V_8 -> V_326 = 0x01 ;
V_8 -> V_86 = 0x01 ;
V_8 -> V_328 = 0x01 ;
}
V_8 -> V_257 = V_492 ;
V_8 -> V_18 = V_493 ;
V_8 -> V_242 = V_494 ;
V_8 -> V_243 = V_495 ;
V_8 -> V_288 = V_496 ;
switch ( V_6 -> V_415 ) {
case 0x111d76b6 :
case 0x111d76b7 :
V_480 ++ ;
case 0x111d76b4 :
case 0x111d76b5 :
V_8 -> V_334 = V_497 ;
V_6 -> V_32 = V_498 ;
V_8 -> V_255 = F_181 ( V_6 ,
V_492 ,
V_499 ) ;
break;
case 0x111d7608 :
switch ( V_8 -> V_387 ) {
case V_500 :
V_25 = F_150 ( V_8 , V_6 -> V_66 ,
V_363 , 0x02 ) ;
if ( V_25 < 0 )
return V_25 ;
F_15 ( V_6 , V_6 -> V_66 , 0 ,
V_501 , 0x02 ) ;
F_15 ( V_6 , V_6 -> V_66 , 0 ,
V_320 ,
V_321 | V_25 ) ;
V_8 -> V_326 |= 0x02 ;
break;
}
if ( ( V_6 -> V_502 & 0xf ) == 0 ||
( V_6 -> V_502 & 0xf ) == 1 )
V_8 -> V_112 = 40 ;
V_8 -> V_334 = V_497 ;
V_480 ++ ;
F_44 ( V_6 , 0x0f , 0x40f000f0 ) ;
F_44 ( V_6 , 0x19 , 0x40f000f3 ) ;
V_8 -> V_257 = V_503 ;
V_8 -> V_255 = F_181 ( V_6 ,
V_503 ,
V_499 - 1 ) ;
break;
case 0x111d7603 :
if ( ( V_6 -> V_502 & 0xf ) == 1 )
V_8 -> V_112 = 40 ;
default:
V_8 -> V_334 = V_497 ;
V_6 -> V_32 = V_498 ;
V_8 -> V_255 = F_181 ( V_6 ,
V_492 ,
V_499 ) ;
break;
}
if ( F_33 ( V_6 , 0xa ) & V_251 )
F_224 ( V_6 , V_480 ) ;
V_8 -> V_93 = V_504 ;
V_8 -> V_63 = 0x50 ;
V_8 -> V_68 = 0 ;
V_8 -> V_117 = 1 ;
V_8 -> V_285 = 0x26 ;
V_8 -> V_55 = V_505 ;
V_8 -> V_115 = V_506 ;
V_8 -> V_28 = V_507 ;
V_8 -> V_342 = V_486 ;
V_8 -> V_241 = F_110 ( V_505 ) ;
V_8 -> V_133 = F_110 ( V_506 ) ;
V_8 -> V_77 = F_110 ( V_493 ) ;
V_8 -> V_80 = F_219 ( V_6 , 0x1e ) ;
F_13 ( L_63 , V_8 -> V_387 ) ;
switch ( V_8 -> V_387 ) {
case V_500 :
F_44 ( V_6 , 0x0e , 0x01813040 ) ;
F_68 ( V_6 , 0x0e ,
V_43 | V_146 ) ;
case V_508 :
V_8 -> V_255 = 0 ;
V_8 -> V_80 = 0 ;
V_8 -> V_77 = 0 ;
break;
case V_509 :
case V_510 :
V_8 -> V_255 = 1 ;
V_8 -> V_80 = 0 ;
V_8 -> V_77 = 1 ;
break;
case V_511 :
V_8 -> V_255 = 1 ;
V_8 -> V_80 = 1 ;
V_8 -> V_77 = 1 ;
case V_512 :
V_8 -> V_332 = 0x01 ;
case V_513 :
F_44 ( V_6 , 0x0d , 0x90170010 ) ;
F_68 ( V_6 , 0x0d , V_44 ) ;
V_8 -> V_94 = 1 ;
break;
case V_514 :
V_8 -> V_255 = 1 ;
V_8 -> V_77 = 1 ;
V_8 -> V_80 = 1 ;
V_8 -> V_332 = 0x08 ;
break;
}
if ( F_189 ( V_6 -> V_362 ) ) {
V_482 = F_88 ( V_6 , 0x0f ) ;
if ( F_131 ( V_482 ) == V_515 ||
F_131 ( V_482 ) == V_300 ||
F_131 ( V_482 ) == V_516 ) {
V_482 = ( V_482 & ( ~ V_517 ) )
| ( V_516 <<
V_518 ) ;
V_482 = ( V_482 & ( ~ ( V_519
| V_520 ) ) )
| 0x1f ;
F_44 ( V_6 , 0x0f , V_482 ) ;
}
}
if ( F_187 ( V_6 , 1 ) )
F_103 ( L_61 ,
V_8 -> V_332 ,
V_8 -> V_331 ) ;
#ifdef F_218
if ( V_8 -> V_332 ) {
if ( ! V_8 -> V_343 ) {
V_8 -> V_326 |= V_8 -> V_332 ;
V_8 -> V_86 |= V_8 -> V_332 ;
V_8 -> V_328 |= V_8 -> V_332 ;
} else {
V_6 -> V_359 . V_473 =
F_201 ;
}
V_6 -> V_359 . V_474 = F_200 ;
V_6 -> V_359 . V_475 =
F_205 ;
}
#endif
V_8 -> V_30 . V_88 = V_8 -> V_88 ;
V_25 = F_140 ( V_6 ) ;
if ( ! V_25 ) {
if ( V_8 -> V_387 < 0 ) {
F_108 ( V_214 L_57
L_58 ) ;
V_8 -> V_387 = V_491 ;
goto V_410;
}
V_25 = - V_232 ;
}
if ( V_25 < 0 ) {
F_169 ( V_6 ) ;
return V_25 ;
}
if ( V_8 -> V_387 == V_512 ||
V_8 -> V_387 == V_513 ) {
unsigned int V_521 ;
V_521 = F_186 ( V_6 , 0x1 , V_364 ) ;
V_521 &= V_365 ;
if ( V_521 >= 6 )
F_222 ( V_6 ) ;
}
V_6 -> V_454 = F_193 ;
return 0 ;
}
static int F_225 ( struct V_5 * V_6 )
{
struct V_7 * V_8 ;
int V_25 ;
V_8 = F_207 ( sizeof( * V_8 ) , V_166 ) ;
if ( V_8 == NULL )
return - V_170 ;
V_6 -> V_385 = 1 ;
V_6 -> V_8 = V_8 ;
V_8 -> V_287 = 1 ;
V_8 -> V_106 = F_110 ( V_522 ) ;
V_8 -> V_107 = V_522 ;
V_8 -> V_387 = F_208 ( V_6 , V_523 ,
V_524 ,
V_525 ) ;
if ( V_8 -> V_387 == V_526 ) {
V_8 -> V_326 = V_8 -> V_86 = 0x03 ;
V_8 -> V_328 = 0x03 ;
F_108 ( V_391 L_64 , V_6 -> V_362 ) ;
switch ( V_6 -> V_362 ) {
case 0x106b0800 :
V_8 -> V_387 = V_527 ;
break;
case 0x106b0600 :
case 0x106b0700 :
V_8 -> V_387 = V_528 ;
break;
case 0x106b0e00 :
case 0x106b0f00 :
case 0x106b1600 :
case 0x106b1700 :
case 0x106b0200 :
case 0x106b1e00 :
V_8 -> V_387 = V_529 ;
break;
case 0x106b1a00 :
case 0x00000100 :
V_8 -> V_387 = V_530 ;
break;
case 0x106b0a00 :
case 0x106b2200 :
V_8 -> V_387 = V_531 ;
break;
default:
V_8 -> V_387 = V_529 ;
break;
}
}
V_410:
if ( V_8 -> V_387 < 0 )
F_13 ( V_391 L_56 ,
V_6 -> V_392 ) ;
else
F_43 ( V_6 ,
V_532 [ V_8 -> V_387 ] ) ;
V_8 -> V_115 = V_533 ;
V_8 -> V_55 = V_534 ;
V_8 -> V_241 = F_110 ( V_534 ) ;
V_8 -> V_133 = F_110 ( V_533 ) ;
V_8 -> V_255 = 0 ;
V_8 -> V_341 = 0 ;
V_8 -> V_334 = V_535 ;
V_8 -> V_242 = V_536 ;
V_8 -> V_243 = V_537 ;
V_8 -> V_288 = V_538 ;
V_8 -> V_30 . V_88 = V_8 -> V_88 ;
V_25 = F_140 ( V_6 ) ;
if ( ! V_25 ) {
if ( V_8 -> V_387 < 0 ) {
F_108 ( V_214 L_57
L_58 ) ;
V_8 -> V_387 = V_539 ;
goto V_410;
}
V_25 = - V_232 ;
}
if ( V_25 < 0 ) {
F_169 ( V_6 ) ;
return V_25 ;
}
V_6 -> V_359 = V_404 ;
F_226 ( V_6 , 0x12 , V_35 ,
( 0 << V_540 ) |
( 2 << V_211 ) |
( 0x27 << V_209 ) |
( 0 << V_237 ) ) ;
return 0 ;
}
static int F_227 ( struct V_5 * V_6 )
{
struct V_7 * V_8 ;
int V_25 ;
V_8 = F_207 ( sizeof( * V_8 ) , V_166 ) ;
if ( V_8 == NULL )
return - V_170 ;
V_6 -> V_385 = 1 ;
V_6 -> V_8 = V_8 ;
V_8 -> V_287 = 1 ;
V_6 -> V_32 = V_541 ;
V_8 -> V_106 = F_110 ( V_542 ) ;
V_8 -> V_107 = V_542 ;
V_8 -> V_387 = F_208 ( V_6 , V_543 ,
V_544 ,
V_545 ) ;
V_410:
if ( V_8 -> V_387 < 0 )
F_13 ( V_391 L_56 ,
V_6 -> V_392 ) ;
else
F_43 ( V_6 ,
V_546 [ V_8 -> V_387 ] ) ;
V_8 -> V_285 = 0x23 ;
V_8 -> V_115 = V_547 ;
V_8 -> V_133 = F_110 ( V_547 ) ;
V_8 -> V_55 = V_548 ;
V_8 -> V_241 = F_110 ( V_548 ) ;
V_8 -> V_28 = V_549 ;
V_8 -> V_80 = F_110 ( V_549 ) ;
V_8 -> V_246 = V_550 ;
V_8 -> V_322 = V_551 ;
V_8 -> V_30 . V_88 = V_8 -> V_88 ;
if ( V_8 -> V_387 != V_552 ) {
V_8 -> V_327 = V_8 -> V_326 = 0x01 ;
V_8 -> V_86 = V_8 -> V_328 = 0x01 ;
}
switch ( V_8 -> V_387 ) {
case V_553 :
case V_554 :
V_8 -> V_255 = 0 ;
V_8 -> V_334 = V_555 ;
break;
case V_556 :
switch ( V_6 -> V_362 ) {
case 0x10280209 :
case 0x1028022e :
F_44 ( V_6 , 0x21 , 0x01442070 ) ;
break;
}
F_44 ( V_6 , 0x0c , 0x90a79130 ) ;
F_44 ( V_6 , 0x0f , 0x0227011f ) ;
F_44 ( V_6 , 0x0e , 0x02a79130 ) ;
case V_557 :
if ( V_6 -> V_362 != 0x1028022f ) {
V_8 -> V_327 = V_8 -> V_326 = 0x04 ;
V_8 -> V_86 = V_8 -> V_328 = 0x04 ;
}
V_8 -> V_257 = V_558 ;
V_8 -> V_255 = V_559 ;
V_8 -> V_334 = V_560 ;
V_8 -> V_18 = V_561 ;
V_8 -> V_77 = F_110 ( V_561 ) ;
break;
case V_562 :
V_8 -> V_255 = 0 ;
V_8 -> V_334 = V_563 ;
break;
default:
V_8 -> V_255 = 0 ;
V_8 -> V_334 = V_564 ;
break;
}
V_8 -> V_242 = V_565 ;
V_8 -> V_243 = V_566 ;
V_8 -> V_288 = V_567 ;
V_8 -> V_341 = 0 ;
V_8 -> V_93 = V_568 ;
V_8 -> V_63 = 0x40 ;
V_8 -> V_68 = 0 ;
V_8 -> V_330 = 1 ;
V_25 = F_140 ( V_6 ) ;
if ( ! V_25 ) {
if ( V_8 -> V_387 < 0 ) {
F_108 ( V_214 L_57
L_58 ) ;
V_8 -> V_387 = V_552 ;
goto V_410;
}
V_25 = - V_232 ;
}
if ( V_25 < 0 ) {
F_169 ( V_6 ) ;
return V_25 ;
}
V_6 -> V_359 = V_404 ;
V_6 -> V_454 = F_195 ;
V_6 -> V_347 -> V_569 = 1 ;
if ( V_8 -> V_387 == V_570 )
V_8 -> V_94 = 0 ;
return 0 ;
}
static int F_228 ( struct V_5 * V_6 )
{
struct V_7 * V_8 ;
int V_25 ;
V_8 = F_207 ( sizeof( * V_8 ) , V_166 ) ;
if ( V_8 == NULL )
return - V_170 ;
V_6 -> V_385 = 1 ;
V_6 -> V_8 = V_8 ;
V_8 -> V_287 = 1 ;
V_8 -> V_106 = F_110 ( V_571 ) ;
V_8 -> V_107 = V_571 ;
V_8 -> V_387 = F_208 ( V_6 , V_572 ,
V_573 ,
V_574 ) ;
V_410:
if ( V_8 -> V_387 < 0 )
F_13 ( V_391 L_56 ,
V_6 -> V_392 ) ;
else
F_43 ( V_6 ,
V_575 [ V_8 -> V_387 ] ) ;
V_8 -> V_285 = 0x23 ;
V_8 -> V_115 = V_576 ;
V_8 -> V_133 = F_110 ( V_576 ) ;
V_8 -> V_55 = V_577 ;
V_8 -> V_241 = F_110 ( V_577 ) ;
V_8 -> V_28 = V_578 ;
V_8 -> V_80 = F_110 ( V_578 ) ;
V_8 -> V_257 = V_579 ;
V_8 -> V_255 = V_580 ;
V_8 -> V_18 = V_581 ;
V_8 -> V_77 = F_110 ( V_581 ) ;
V_8 -> V_341 = 0 ;
V_8 -> V_334 = V_582 ;
V_8 -> V_93 = V_583 ;
V_8 -> V_242 = V_584 ;
V_8 -> V_243 = V_585 ;
V_8 -> V_288 = V_586 ;
V_8 -> V_63 = 0x40 ;
V_8 -> V_68 = 0 ;
if ( V_8 -> V_387 != V_587 )
V_8 -> V_330 = 1 ;
V_8 -> V_30 . V_88 = V_8 -> V_88 ;
switch ( V_8 -> V_387 ) {
case V_588 :
F_44 ( V_6 , 0x1f , 0x01441030 ) ;
F_44 ( V_6 , 0x20 , 0x1c410030 ) ;
V_25 = F_150 ( V_8 , V_6 -> V_66 , V_363 , 0x01 ) ;
if ( V_25 < 0 )
return V_25 ;
F_15 ( V_6 , V_6 -> V_66 , 0 ,
V_501 , 0x10 ) ;
F_15 ( V_6 , V_6 -> V_66 , 0 ,
V_320 ,
V_321 | V_25 ) ;
V_8 -> V_86 = 0x0b ;
V_8 -> V_327 = 0x01 ;
V_8 -> V_326 = 0x1b ;
V_8 -> V_329 = 0x10 ;
V_8 -> V_328 = 0x01 ;
break;
case V_589 :
break;
default:
V_8 -> V_327 = V_8 -> V_326 = V_8 -> V_86 = 0x1 ;
V_8 -> V_328 = 0x01 ;
break;
}
V_25 = F_140 ( V_6 ) ;
if ( ! V_25 ) {
if ( V_8 -> V_387 < 0 ) {
F_108 ( V_214 L_57
L_58 ) ;
V_8 -> V_387 = V_589 ;
goto V_410;
}
V_25 = - V_232 ;
}
if ( V_25 < 0 ) {
F_169 ( V_6 ) ;
return V_25 ;
}
V_6 -> V_359 = V_404 ;
V_6 -> V_454 = F_194 ;
return 0 ;
}
static int F_229 ( struct V_5 * V_6 )
{
struct V_7 * V_8 ;
int V_25 ;
V_8 = F_207 ( sizeof( * V_8 ) , V_166 ) ;
if ( V_8 == NULL )
return - V_170 ;
V_6 -> V_385 = 1 ;
V_6 -> V_8 = V_8 ;
V_8 -> V_287 = 1 ;
V_8 -> V_106 = F_110 ( V_590 ) ;
V_8 -> V_107 = V_590 ;
V_8 -> V_387 = F_208 ( V_6 , V_591 ,
V_592 ,
V_593 ) ;
if ( V_8 -> V_387 < 0 )
F_13 ( V_391 L_56 ,
V_6 -> V_392 ) ;
else
F_43 ( V_6 ,
V_594 [ V_8 -> V_387 ] ) ;
V_8 -> V_30 . V_88 = V_8 -> V_88 ;
V_8 -> V_133 = F_110 ( V_595 ) ;
V_8 -> V_115 = V_595 ;
V_8 -> V_241 = F_110 ( V_596 ) ;
V_8 -> V_55 = V_596 ;
V_8 -> V_334 = V_597 ;
V_8 -> V_242 = 1 ;
V_8 -> V_243 = V_598 ;
V_8 -> V_288 = V_599 ;
V_25 = F_140 ( V_6 ) ;
if ( V_25 < 0 ) {
F_169 ( V_6 ) ;
return - V_232 ;
}
V_8 -> V_47 = & V_8 -> V_177 ;
V_6 -> V_359 = V_404 ;
return 0 ;
}
static int T_4 F_230 ( void )
{
return F_231 ( & V_600 ) ;
}
static void T_5 F_232 ( void )
{
F_233 ( & V_600 ) ;
}
