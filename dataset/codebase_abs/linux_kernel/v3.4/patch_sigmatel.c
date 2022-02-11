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
static void F_28 ( void * V_69 , int V_26 )
{
F_29 ( V_69 , V_26 ) ;
}
static int F_30 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
unsigned int V_70 [ 4 ] ;
int V_25 ;
int V_71 ;
if ( V_8 -> V_72 ) {
V_25 = F_31 ( V_6 , V_8 -> V_72 ) ;
if ( V_25 < 0 )
return V_25 ;
}
for ( V_71 = 0 ; V_71 < V_8 -> V_73 ; V_71 ++ ) {
V_25 = F_31 ( V_6 , V_8 -> V_74 [ V_71 ] ) ;
if ( V_25 < 0 )
return V_25 ;
}
if ( ! V_8 -> V_75 && V_8 -> V_76 > 0 &&
F_32 ( V_6 , L_2 ) == 1 ) {
V_77 . V_78 = V_8 -> V_76 ;
V_25 = F_33 ( V_6 , 0 ,
F_34 ( & V_77 , V_6 ) ) ;
if ( V_25 < 0 )
return V_25 ;
}
if ( V_8 -> V_79 > 0 ) {
int V_80 = F_35 ( V_6 , V_8 -> V_30 . V_31 ) ;
struct V_22 * V_23 = & V_8 -> V_24 ;
if ( V_80 & V_81 ) {
F_36 ( V_23 , L_3 , 0 , NULL ) ;
V_8 -> V_29 = 1 ;
}
V_82 . V_78 = V_8 -> V_79 ;
V_25 = F_33 ( V_6 , 0 ,
F_34 ( & V_82 , V_6 ) ) ;
if ( V_25 < 0 )
return V_25 ;
}
if ( V_8 -> V_30 . V_31 ) {
V_25 = F_37 ( V_6 ,
V_8 -> V_30 . V_31 ,
V_8 -> V_30 . V_31 ) ;
if ( V_25 < 0 )
return V_25 ;
V_25 = F_38 ( V_6 ,
& V_8 -> V_30 ) ;
if ( V_25 < 0 )
return V_25 ;
V_8 -> V_30 . V_83 = 1 ;
}
if ( V_8 -> V_84 && ! ( V_8 -> V_85 & 0x01 ) ) {
V_25 = F_39 ( V_6 , V_8 -> V_84 ) ;
if ( V_25 < 0 )
return V_25 ;
}
F_40 ( V_6 , V_8 -> V_30 . V_86 [ 0 ] ,
V_35 , V_70 ) ;
V_70 [ 2 ] += V_70 [ 3 ] * V_8 -> V_87 ;
V_70 [ 3 ] |= V_88 ;
V_25 = F_41 ( V_6 , L_4 ,
V_70 , V_89 ,
L_5 ) ;
if ( V_25 < 0 )
return V_25 ;
V_25 = F_42 ( V_6 , L_6 ,
NULL , V_89 ,
L_7 , true ,
& V_8 -> V_90 . V_91 ) ;
if ( V_25 < 0 )
return V_25 ;
if ( V_8 -> V_92 ) {
V_8 -> V_90 . V_93 = F_28 ;
V_25 = F_43 ( V_6 , & V_8 -> V_90 , true ) ;
if ( V_25 < 0 )
return V_25 ;
}
if ( V_8 -> V_94 &&
F_32 ( V_6 , L_8 ) == 1 ) {
V_25 = F_31 ( V_6 , V_8 -> V_94 ) ;
if ( V_25 < 0 )
return V_25 ;
}
F_44 ( V_6 ) ;
V_25 = F_45 ( V_6 , & V_8 -> V_95 ) ;
if ( V_25 < 0 )
return V_25 ;
return 0 ;
}
static void F_46 ( struct V_5 * V_6 ,
const unsigned int * V_96 )
{
int V_71 ;
struct V_7 * V_8 = V_6 -> V_8 ;
if ( ! V_96 )
return;
for ( V_71 = 0 ; V_71 < V_8 -> V_97 ; V_71 ++ )
if ( V_8 -> V_98 [ V_71 ] && V_96 [ V_71 ] )
F_47 ( V_6 , V_8 -> V_98 [ V_71 ] ,
V_96 [ V_71 ] ) ;
}
static int F_48 ( struct V_99 * V_100 ,
struct V_5 * V_6 ,
struct V_101 * V_102 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
if ( V_8 -> V_103 )
F_49 ( V_8 -> V_103 ) ;
return F_50 ( V_6 , & V_8 -> V_30 , V_102 ,
V_100 ) ;
}
static int F_51 ( struct V_99 * V_100 ,
struct V_5 * V_6 ,
unsigned int V_104 ,
unsigned int V_105 ,
struct V_101 * V_102 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
return F_52 ( V_6 , & V_8 -> V_30 , V_104 , V_105 , V_102 ) ;
}
static int F_53 ( struct V_99 * V_100 ,
struct V_5 * V_6 ,
struct V_101 * V_102 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
return F_54 ( V_6 , & V_8 -> V_30 ) ;
}
static int F_55 ( struct V_99 * V_100 ,
struct V_5 * V_6 ,
struct V_101 * V_102 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
return F_56 ( V_6 , & V_8 -> V_30 ) ;
}
static int F_57 ( struct V_99 * V_100 ,
struct V_5 * V_6 ,
struct V_101 * V_102 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
return F_58 ( V_6 , & V_8 -> V_30 ) ;
}
static int F_59 ( struct V_99 * V_100 ,
struct V_5 * V_6 ,
unsigned int V_104 ,
unsigned int V_105 ,
struct V_101 * V_102 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
return F_60 ( V_6 , & V_8 -> V_30 ,
V_104 , V_105 , V_102 ) ;
}
static int F_61 ( struct V_99 * V_100 ,
struct V_5 * V_6 ,
struct V_101 * V_102 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
return F_62 ( V_6 , & V_8 -> V_30 ) ;
}
static int F_63 ( struct V_99 * V_100 ,
struct V_5 * V_6 ,
unsigned int V_104 ,
unsigned int V_105 ,
struct V_101 * V_102 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
T_1 V_27 = V_8 -> V_106 [ V_102 -> V_107 ] ;
if ( V_8 -> V_108 ) {
F_49 ( 40 ) ;
F_64 ( V_6 , V_27 , 0 ,
V_109 , V_110 ) ;
}
F_65 ( V_6 , V_27 , V_104 , 0 , V_105 ) ;
return 0 ;
}
static int F_66 ( struct V_99 * V_100 ,
struct V_5 * V_6 ,
struct V_101 * V_102 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
T_1 V_27 = V_8 -> V_106 [ V_102 -> V_107 ] ;
F_67 ( V_6 , V_27 ) ;
if ( V_8 -> V_108 )
F_64 ( V_6 , V_27 , 0 ,
V_109 , V_111 ) ;
return 0 ;
}
static int F_68 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
struct V_112 * V_113 = V_8 -> V_114 ;
V_6 -> V_115 = 1 ;
V_6 -> V_116 = V_113 ;
V_113 -> V_117 = L_9 ;
V_113 -> V_118 [ V_119 ] = V_120 ;
V_113 -> V_118 [ V_119 ] . V_27 =
V_8 -> V_30 . V_86 [ 0 ] ;
V_113 -> V_118 [ V_121 ] = V_122 ;
V_113 -> V_118 [ V_121 ] . V_27 = V_8 -> V_106 [ 0 ] ;
V_113 -> V_118 [ V_121 ] . V_123 = V_8 -> V_124 ;
if ( V_8 -> V_125 ) {
V_6 -> V_115 ++ ;
V_113 ++ ;
V_113 -> V_117 = L_10 ;
V_113 -> V_118 [ V_119 ] = V_126 ;
}
if ( V_8 -> V_30 . V_31 || V_8 -> V_84 ) {
V_6 -> V_115 ++ ;
V_113 ++ ;
V_113 -> V_117 = L_11 ;
V_113 -> V_127 = V_8 -> V_95 . V_128 [ 0 ] ;
if ( V_8 -> V_30 . V_31 ) {
V_113 -> V_118 [ V_119 ] = V_129 ;
V_113 -> V_118 [ V_119 ] . V_27 = V_8 -> V_30 . V_31 ;
}
if ( V_8 -> V_84 ) {
V_113 -> V_118 [ V_121 ] = V_130 ;
V_113 -> V_118 [ V_121 ] . V_27 = V_8 -> V_84 ;
}
}
return 0 ;
}
static unsigned int F_69 ( struct V_5 * V_6 ,
T_1 V_27 )
{
unsigned int V_131 = F_70 ( V_6 , V_27 ) ;
V_131 = ( V_131 & V_132 ) >> V_133 ;
if ( V_131 & V_134 )
return V_135 ;
if ( V_131 & V_136 )
return V_137 ;
if ( V_131 & V_138 )
return V_139 ;
if ( V_131 & V_140 )
return V_141 ;
return 0 ;
}
static void F_71 ( struct V_5 * V_6 , T_1 V_27 , int V_142 )
{
F_15 ( V_6 , V_27 , 0 ,
V_41 , V_142 ) ;
}
static int F_72 ( struct V_1 * V_2 ,
struct V_10 * V_11 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = V_6 -> V_8 ;
V_11 -> V_14 . integer . V_14 [ 0 ] = ! ! V_8 -> V_143 ;
return 0 ;
}
static int F_73 ( struct V_1 * V_2 ,
struct V_10 * V_11 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = V_6 -> V_8 ;
int V_27 = V_2 -> V_67 ;
V_8 -> V_143 = V_11 -> V_14 . integer . V_14 [ 0 ] ? V_27 : 0 ;
F_74 ( V_6 , V_27 ) ;
return 1 ;
}
static int F_75 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
int V_71 ;
static const char * const V_144 [] = {
L_12 , L_13 , L_14
} ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = V_6 -> V_8 ;
T_1 V_27 = V_2 -> V_67 ;
if ( V_27 == V_8 -> V_145 || V_27 == V_8 -> V_146 )
V_71 = 3 ;
else
V_71 = 2 ;
V_4 -> type = V_147 ;
V_4 -> V_14 . V_15 . V_57 = V_71 ;
V_4 -> V_78 = 1 ;
if ( V_4 -> V_14 . V_15 . V_16 >= V_71 )
V_4 -> V_14 . V_15 . V_16 = V_71 - 1 ;
strcpy ( V_4 -> V_14 . V_15 . V_117 ,
V_144 [ V_4 -> V_14 . V_15 . V_16 ] ) ;
return 0 ;
}
static int F_76 ( struct V_1 * V_2 ,
struct V_10 * V_11 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
T_1 V_27 = V_2 -> V_67 ;
unsigned int V_46 = F_17 ( V_6 , V_27 ) ;
if ( V_46 == F_69 ( V_6 , V_27 ) )
V_11 -> V_14 . V_15 . V_16 [ 0 ] = 0 ;
else if ( V_46 == V_141 )
V_11 -> V_14 . V_15 . V_16 [ 0 ] = 1 ;
else if ( V_46 == V_45 )
V_11 -> V_14 . V_15 . V_16 [ 0 ] = 2 ;
return 0 ;
}
static int F_77 ( struct V_1 * V_2 ,
struct V_10 * V_11 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
unsigned int V_36 = 0 ;
int error ;
T_1 V_27 = V_2 -> V_67 ;
if ( V_11 -> V_14 . V_15 . V_16 [ 0 ] == 0 )
V_36 = F_69 ( V_6 , V_27 ) ;
else if ( V_11 -> V_14 . V_15 . V_16 [ 0 ] == 1 )
V_36 = V_141 ;
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
static int F_78 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
char * V_144 [ 2 ] ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = V_6 -> V_8 ;
if ( V_2 -> V_67 == V_8 -> V_146 )
V_144 [ 0 ] = L_13 ;
else
V_144 [ 0 ] = L_12 ;
V_144 [ 1 ] = L_14 ;
V_4 -> type = V_147 ;
V_4 -> V_14 . V_15 . V_57 = 2 ;
V_4 -> V_78 = 1 ;
if ( V_4 -> V_14 . V_15 . V_16 >= 2 )
V_4 -> V_14 . V_15 . V_16 = 1 ;
strcpy ( V_4 -> V_14 . V_15 . V_117 ,
V_144 [ V_4 -> V_14 . V_15 . V_16 ] ) ;
return 0 ;
}
static int F_79 ( struct V_1 * V_2 , struct V_10 * V_11 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = V_6 -> V_8 ;
T_1 V_27 = V_2 -> V_67 ;
int V_148 = ( V_27 == V_8 -> V_145 ) ? 1 : 0 ;
V_11 -> V_14 . V_15 . V_16 [ 0 ] = V_8 -> V_149 [ V_148 ] ;
return 0 ;
}
static int F_80 ( struct V_1 * V_2 , struct V_10 * V_11 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = V_6 -> V_8 ;
T_1 V_27 = V_2 -> V_67 ;
int V_148 = ( V_27 == V_8 -> V_145 ) ? 1 : 0 ;
unsigned short V_26 = ! ! V_11 -> V_14 . V_15 . V_16 [ 0 ] ;
V_8 -> V_149 [ V_148 ] = V_26 ;
if ( V_26 )
F_71 ( V_6 , V_27 , V_44 ) ;
else {
unsigned int V_37 = V_43 ;
if ( V_148 )
V_37 |= F_69 ( V_6 , V_27 ) ;
F_71 ( V_6 , V_27 , V_37 ) ;
}
if ( V_8 -> V_150 )
F_74 ( V_6 , V_27 ) ;
return 1 ;
}
static int F_81 ( struct V_1 * V_2 ,
struct V_10 * V_11 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = V_6 -> V_8 ;
V_11 -> V_14 . integer . V_14 [ 0 ] = V_8 -> V_151 ;
return 0 ;
}
static int F_82 ( struct V_1 * V_2 ,
struct V_10 * V_11 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = V_6 -> V_8 ;
T_1 V_27 = V_2 -> V_67 & 0xff ;
unsigned int V_26 = ! ! V_11 -> V_14 . integer . V_14 [ 0 ] ;
if ( V_8 -> V_151 == V_26 )
return 0 ;
V_8 -> V_151 = V_26 ;
F_15 ( V_6 , V_27 , 0 , V_152 ,
V_8 -> V_151 ? 0x4 : 0x0 ) ;
return 1 ;
}
static struct V_153 *
F_83 ( struct V_7 * V_8 ,
const struct V_153 * V_154 ,
const char * V_117 ,
unsigned int V_155 )
{
struct V_153 * V_156 ;
F_84 ( & V_8 -> V_157 , sizeof( * V_156 ) , 32 ) ;
V_156 = F_85 ( & V_8 -> V_157 ) ;
if ( ! V_156 )
return NULL ;
* V_156 = * V_154 ;
V_156 -> V_117 = F_86 ( V_117 , V_158 ) ;
if ( ! V_156 -> V_117 ) {
memset ( V_156 , 0 , sizeof( * V_156 ) ) ;
V_8 -> V_157 . V_159 -- ;
return NULL ;
}
V_156 -> V_160 = V_155 ;
return V_156 ;
}
static int F_87 ( struct V_7 * V_8 ,
const struct V_153 * V_154 ,
int V_51 , const char * V_117 ,
unsigned long V_26 )
{
struct V_153 * V_156 = F_83 ( V_8 , V_154 , V_117 ,
V_161 ) ;
if ( ! V_156 )
return - V_162 ;
V_156 -> V_58 = V_51 ;
V_156 -> V_67 = V_26 ;
return 0 ;
}
static inline int F_88 ( struct V_7 * V_8 ,
int type , int V_51 , const char * V_117 ,
unsigned long V_26 )
{
return F_87 ( V_8 ,
& V_163 [ type ] ,
V_51 , V_117 , V_26 ) ;
}
static inline int F_89 ( struct V_7 * V_8 , int type ,
const char * V_117 , unsigned long V_26 )
{
return F_88 ( V_8 , type , 0 , V_117 , V_26 ) ;
}
static inline int F_90 ( struct V_5 * V_6 ,
T_1 V_27 , int V_51 )
{
int V_164 = F_91 ( V_6 , V_27 ) ;
int V_165 = 0 ;
struct V_7 * V_8 = V_6 -> V_8 ;
char V_117 [ 22 ] ;
if ( F_92 ( V_164 ) != V_166 ) {
if ( F_69 ( V_6 , V_27 ) == V_141
&& V_27 == V_8 -> V_146 )
V_165 = V_167 ;
else if ( F_70 ( V_6 , V_27 )
& ( V_140 << V_133 ) )
V_165 = V_168 ;
else if ( V_27 == V_8 -> V_145 )
V_165 = V_167 ;
}
if ( V_165 ) {
F_93 ( V_6 , V_27 , & V_8 -> V_95 ,
V_117 , sizeof( V_117 ) , NULL ) ;
return F_89 ( V_6 -> V_8 , V_165 ,
strcat ( V_117 , L_15 ) , V_27 ) ;
}
return 0 ;
}
static int F_94 ( struct V_7 * V_8 )
{
struct V_153 * V_156 ;
struct V_22 * V_50 = & V_8 -> V_169 ;
if ( V_8 -> V_75 )
return 0 ;
if ( ! V_8 -> V_124 || V_50 -> V_33 <= 1 )
return 0 ;
V_156 = F_83 ( V_8 , & V_170 ,
V_170 . V_117 , 0 ) ;
if ( ! V_156 )
return - V_162 ;
V_156 -> V_78 = V_8 -> V_124 ;
return 0 ;
}
static T_1 F_95 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
struct V_171 * V_172 = & V_8 -> V_95 ;
T_1 V_27 ;
unsigned int V_131 ;
int V_71 ;
if ( V_172 -> V_173 != V_174 )
return 0 ;
for ( V_71 = 0 ; V_71 < V_172 -> V_175 ; V_71 ++ ) {
if ( V_172 -> V_176 [ V_71 ] . type == V_177 ) {
V_27 = V_172 -> V_176 [ V_71 ] . V_178 ;
V_131 = F_70 ( V_6 , V_27 ) ;
if ( V_131 & V_179 )
return V_27 ;
}
}
return 0 ;
}
static T_1 F_96 ( struct V_5 * V_6 , T_1 * V_180 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
struct V_171 * V_172 = & V_8 -> V_95 ;
unsigned int V_164 , V_131 ;
int V_71 ;
* V_180 = 0 ;
if ( V_172 -> V_173 != V_174 )
return 0 ;
for ( V_71 = 0 ; V_71 < V_172 -> V_175 ; V_71 ++ ) {
T_1 V_27 = V_172 -> V_176 [ V_71 ] . V_178 ;
if ( V_172 -> V_176 [ V_71 ] . type != V_181 )
continue;
V_164 = F_91 ( V_6 , V_27 ) ;
if ( F_92 ( V_164 ) != V_166 ) {
V_131 = F_70 ( V_6 , V_27 ) ;
if ( V_131 & V_179 ) {
* V_180 = F_97 ( V_6 , V_27 ) ;
if ( * V_180 )
return V_27 ;
}
}
}
return 0 ;
}
static int F_98 ( struct V_7 * V_8 , T_1 V_27 )
{
int V_71 ;
for ( V_71 = 0 ; V_71 < V_8 -> V_30 . V_182 ; V_71 ++ ) {
if ( V_8 -> V_30 . V_86 [ V_71 ] == V_27 )
return 1 ;
}
return 0 ;
}
static int F_99 ( struct V_7 * V_8 , T_1 V_27 )
{
int V_71 ;
if ( F_98 ( V_8 , V_27 ) )
return 1 ;
for ( V_71 = 0 ; V_71 < V_8 -> V_95 . V_183 ; V_71 ++ )
if ( V_8 -> V_184 [ V_71 ] == V_27 )
return 1 ;
for ( V_71 = 0 ; V_71 < V_8 -> V_95 . V_185 ; V_71 ++ )
if ( V_8 -> V_186 [ V_71 ] == V_27 )
return 1 ;
return 0 ;
}
static T_1 F_97 ( struct V_5 * V_6 , T_1 V_27 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
struct V_171 * V_172 = & V_8 -> V_95 ;
int V_187 , V_188 ;
T_1 V_189 [ V_190 ] , V_191 ;
unsigned int V_80 , V_192 ;
V_188 = F_100 ( V_6 , V_27 , V_189 ,
V_190 ) ;
while ( V_188 == 1 && ( F_101 ( F_35 ( V_6 , V_189 [ 0 ] ) )
!= V_193 ) ) {
V_27 = V_189 [ 0 ] ;
V_188 = F_100 ( V_6 , V_27 , V_189 ,
V_190 ) ;
}
for ( V_187 = 0 ; V_187 < V_188 ; V_187 ++ ) {
V_80 = F_35 ( V_6 , V_189 [ V_187 ] ) ;
V_192 = F_101 ( V_80 ) ;
if ( V_192 != V_193 || ( V_80 & V_194 ) )
continue;
if ( ! F_99 ( V_8 , V_189 [ V_187 ] ) ) {
if ( V_188 > 1 ) {
F_15 ( V_6 , V_27 , 0 ,
V_56 , V_187 ) ;
}
return V_189 [ V_187 ] ;
}
}
V_191 = V_8 -> V_30 . V_86 [ 0 ] ;
if ( V_8 -> V_30 . V_195 ) {
for ( V_187 = 0 ; V_187 < V_172 -> V_183 ; V_187 ++ )
if ( V_172 -> V_196 [ V_187 ] == V_27 ) {
V_191 = V_8 -> V_30 . V_195 ;
break;
}
}
if ( V_188 > 1 ) {
for ( V_187 = 0 ; V_187 < V_188 ; V_187 ++ ) {
if ( V_189 [ V_187 ] == V_191 ) {
F_15 ( V_6 , V_27 , 0 ,
V_56 , V_187 ) ;
break;
}
}
}
return 0 ;
}
static int F_102 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
struct V_171 * V_172 = & V_8 -> V_95 ;
int V_71 ;
T_1 V_27 , V_180 ;
for ( V_71 = 0 ; V_71 < V_172 -> V_197 ; V_71 ++ ) {
V_27 = V_172 -> V_198 [ V_71 ] ;
V_180 = F_97 ( V_6 , V_27 ) ;
if ( ! V_180 ) {
if ( V_8 -> V_30 . V_182 > 0 ) {
V_172 -> V_197 = V_8 -> V_30 . V_182 ;
break;
}
F_103 ( V_199
L_16 ,
V_38 , V_27 ) ;
return - V_200 ;
}
F_104 ( V_8 , V_180 ) ;
}
for ( V_71 = 0 ; V_71 < V_172 -> V_183 ; V_71 ++ ) {
V_27 = V_172 -> V_196 [ V_71 ] ;
V_180 = F_97 ( V_6 , V_27 ) ;
if ( V_180 ) {
if ( ! V_8 -> V_30 . V_195 )
V_8 -> V_30 . V_195 = V_180 ;
else
F_105 ( V_8 , V_180 ) ;
}
V_8 -> V_184 [ V_71 ] = V_180 ;
}
for ( V_71 = 0 ; V_71 < V_172 -> V_185 ; V_71 ++ ) {
V_27 = V_172 -> V_201 [ V_71 ] ;
V_180 = F_97 ( V_6 , V_27 ) ;
if ( V_180 )
F_105 ( V_8 , V_180 ) ;
V_8 -> V_186 [ V_71 ] = V_180 ;
}
V_27 = F_95 ( V_6 ) ;
if ( V_27 ) {
V_180 = F_97 ( V_6 , V_27 ) ;
if ( V_180 ) {
F_13 ( L_17 ,
V_27 , V_172 -> V_197 ) ;
V_172 -> V_198 [ V_172 -> V_197 ] = V_27 ;
V_172 -> V_197 ++ ;
V_8 -> V_146 = V_27 ;
F_104 ( V_8 , V_180 ) ;
}
}
V_27 = F_96 ( V_6 , & V_180 ) ;
if ( V_27 && V_180 ) {
F_13 ( L_18 ,
V_27 , V_172 -> V_197 ) ;
V_172 -> V_198 [ V_172 -> V_197 ] = V_27 ;
V_172 -> V_197 ++ ;
V_8 -> V_145 = V_27 ;
F_104 ( V_8 , V_180 ) ;
}
F_106 ( L_19 ,
V_8 -> V_30 . V_182 ,
V_8 -> V_30 . V_86 [ 0 ] ,
V_8 -> V_30 . V_86 [ 1 ] ,
V_8 -> V_30 . V_86 [ 2 ] ,
V_8 -> V_30 . V_86 [ 3 ] ,
V_8 -> V_30 . V_86 [ 4 ] ) ;
return 0 ;
}
static int F_107 ( struct V_5 * V_6 , const char * V_202 ,
int V_51 , T_1 V_27 , int V_203 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
char V_117 [ 32 ] ;
int V_25 ;
if ( ! V_8 -> V_204 ) {
unsigned int V_205 , V_206 , V_207 , V_208 ;
V_205 = F_108 ( V_6 , V_27 , V_35 ) ;
V_206 = ( V_205 & V_209 ) >>
V_210 ;
V_206 = ( V_206 + 1 ) * 25 ;
V_207 = ( V_205 & V_211 ) >>
V_212 ;
V_208 = V_207 * V_206 ;
if ( V_208 > 6400 && V_207 >= 0x1f )
V_8 -> V_87 = V_207 / 2 ;
V_8 -> V_204 = 1 ;
}
sprintf ( V_117 , L_20 , V_202 ) ;
V_25 = F_88 ( V_8 , V_213 , V_51 , V_117 ,
F_109 ( V_27 , V_203 , 0 , V_35 ,
V_8 -> V_87 ) ) ;
if ( V_25 < 0 )
return V_25 ;
sprintf ( V_117 , L_21 , V_202 ) ;
V_25 = F_88 ( V_8 , V_214 , V_51 , V_117 ,
F_110 ( V_27 , V_203 , 0 , V_35 ) ) ;
if ( V_25 < 0 )
return V_25 ;
return 0 ;
}
static int F_104 ( struct V_7 * V_8 , T_1 V_27 )
{
if ( V_8 -> V_30 . V_182 > 4 ) {
F_111 ( V_215 L_22 , V_27 ) ;
return 1 ;
} else {
F_112 ( V_8 -> V_30 . V_86 != V_8 -> V_86 ) ;
V_8 -> V_86 [ V_8 -> V_30 . V_182 ] = V_27 ;
V_8 -> V_30 . V_182 ++ ;
}
return 0 ;
}
static int F_105 ( struct V_7 * V_8 , T_1 V_27 )
{
int V_71 ;
for ( V_71 = 0 ; V_71 < F_113 ( V_8 -> V_30 . V_216 ) ; V_71 ++ ) {
if ( ! V_8 -> V_30 . V_216 [ V_71 ] ) {
V_8 -> V_30 . V_216 [ V_71 ] = V_27 ;
return 0 ;
}
}
F_111 ( V_215 L_23 , V_27 ) ;
return 1 ;
}
static int F_114 ( struct V_5 * V_6 , int V_217 ,
const T_1 * V_218 ,
const T_1 * V_86 ,
int type )
{
struct V_7 * V_8 = V_6 -> V_8 ;
static const char * const V_219 [ 4 ] = {
L_24 , L_25 , NULL , L_26
} ;
T_1 V_27 ;
int V_71 , V_25 ;
unsigned int V_220 ;
for ( V_71 = 0 ; V_71 < V_217 && V_71 < F_113 ( V_219 ) ; V_71 ++ ) {
if ( type == V_221 && ! V_8 -> V_150 ) {
if ( F_115 ( V_6 , V_218 [ V_71 ] ) )
V_8 -> V_150 = 1 ;
}
V_27 = V_86 [ V_71 ] ;
if ( ! V_27 )
continue;
if ( type != V_221 && V_71 == 2 ) {
V_25 = F_116 ( V_6 , L_27 , V_27 , 1 ) ;
if ( V_25 < 0 )
return V_25 ;
V_25 = F_116 ( V_6 , L_28 , V_27 , 2 ) ;
if ( V_25 < 0 )
return V_25 ;
V_220 = F_35 ( V_6 , V_27 ) ;
if ( V_220 & V_222 ) {
V_25 = F_89 ( V_8 ,
V_223 ,
L_29 , V_27 ) ;
if ( V_25 < 0 )
return V_25 ;
}
} else {
const char * V_117 ;
int V_51 ;
switch ( type ) {
case V_221 :
V_117 = L_30 ;
V_51 = V_71 ;
break;
case V_224 :
V_117 = L_31 ;
V_51 = V_71 ;
break;
default:
V_117 = V_219 [ V_71 ] ;
V_51 = 0 ;
break;
}
V_25 = F_107 ( V_6 , V_117 , V_51 , V_27 , 3 ) ;
if ( V_25 < 0 )
return V_25 ;
}
}
return 0 ;
}
static int F_117 ( struct V_5 * V_6 , unsigned long V_225 ,
unsigned long V_226 , int V_51 )
{
int V_25 ;
V_25 = F_88 ( V_6 -> V_8 , V_213 , V_51 ,
L_32 , V_225 ) ;
if ( V_25 < 0 )
return V_25 ;
V_25 = F_88 ( V_6 -> V_8 , V_214 , V_51 ,
L_33 , V_226 ) ;
if ( V_25 < 0 )
return V_25 ;
return 0 ;
}
static int F_118 ( struct V_5 * V_6 ,
const struct V_171 * V_172 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
T_1 V_27 ;
int V_25 ;
int V_51 ;
V_25 = F_114 ( V_6 , V_172 -> V_197 , V_172 -> V_198 ,
V_8 -> V_30 . V_86 ,
V_172 -> V_173 ) ;
if ( V_25 < 0 )
return V_25 ;
if ( V_172 -> V_183 > 1 && V_172 -> V_173 == V_174 ) {
V_25 = F_89 ( V_8 ,
V_227 ,
L_34 ,
V_172 -> V_196 [ V_172 -> V_183 - 1 ] ) ;
if ( V_25 < 0 )
return V_25 ;
}
for ( V_51 = 0 ; V_51 < V_172 -> V_175 ; V_51 ++ ) {
if ( V_172 -> V_176 [ V_51 ] . type > V_177 )
break;
V_27 = V_172 -> V_176 [ V_51 ] . V_178 ;
V_25 = F_90 ( V_6 , V_27 , V_51 ) ;
if ( V_25 < 0 )
return V_25 ;
}
return 0 ;
}
static int F_119 ( struct V_5 * V_6 ,
struct V_171 * V_172 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
int V_25 ;
V_25 = F_114 ( V_6 , V_172 -> V_183 , V_172 -> V_196 ,
V_8 -> V_184 , V_221 ) ;
if ( V_25 < 0 )
return V_25 ;
V_25 = F_114 ( V_6 , V_172 -> V_185 , V_172 -> V_201 ,
V_8 -> V_186 , V_224 ) ;
if ( V_25 < 0 )
return V_25 ;
return 0 ;
}
static int F_120 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
struct V_22 * V_59 = & V_8 -> V_228 ;
int V_71 , V_229 ;
T_1 V_230 [ F_113 ( V_231 ) ] ;
V_229 = F_100 ( V_6 ,
V_8 -> V_61 ,
V_230 ,
V_232 ) ;
if ( V_229 <= 0 || V_229 > F_113 ( V_231 ) )
return - V_233 ;
for ( V_71 = 0 ; V_71 < V_229 ; V_71 ++ )
F_36 ( V_59 , V_231 [ V_71 ] , V_71 ,
NULL ) ;
return F_89 ( V_8 , V_234 ,
L_35 , V_8 -> V_61 ) ;
}
static int F_121 ( struct V_5 * V_6 ,
T_1 V_27 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
T_2 V_205 = F_108 ( V_6 , V_27 , V_35 ) ;
int V_25 , type = V_235 ;
if ( V_8 -> V_236 == V_27 )
type = V_214 ;
if ( ( V_205 & V_237 ) >> V_238 ) {
V_25 = F_89 ( V_8 , type ,
L_36 ,
F_110 ( V_27 , 1 , 0 , V_35 ) ) ;
if ( V_25 < 0 )
return V_25 ;
}
if ( ( V_205 & V_211 ) >> V_212 ) {
V_25 = F_89 ( V_8 , V_213 ,
L_37 ,
F_110 ( V_27 , 1 , 0 , V_35 ) ) ;
if ( V_25 < 0 )
return V_25 ;
}
return 0 ;
}
static int F_122 ( struct V_1 * V_2 ,
struct V_10 * V_11 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
V_11 -> V_14 . integer . V_14 [ 0 ] = V_6 -> V_239 -> V_240 ;
return 0 ;
}
static int F_123 ( struct V_1 * V_2 ,
struct V_10 * V_11 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
return F_124 ( V_6 , V_11 -> V_14 . integer . V_14 [ 0 ] ) ;
}
static int F_125 ( struct V_5 * V_6 )
{
return F_87 ( V_6 -> V_8 , & V_241 ,
0 , L_36 , 0 ) ;
}
static int F_126 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
int V_71 , V_187 , V_25 = 0 ;
for ( V_71 = 0 ; V_71 < V_8 -> V_242 ; V_71 ++ ) {
T_1 V_27 ;
unsigned int V_80 ;
unsigned long V_26 ;
V_27 = V_8 -> V_55 [ V_71 ] ;
V_80 = F_35 ( V_6 , V_27 ) ;
if ( ! ( V_80 & V_81 ) )
continue;
V_26 = F_110 ( V_27 , 3 , 0 , V_35 ) ;
for ( V_187 = 0 ; V_187 < V_8 -> V_243 ; V_187 ++ ) {
if ( V_8 -> V_244 [ V_187 ] == V_26 )
break;
}
if ( V_187 < V_8 -> V_243 )
continue;
V_25 = F_88 ( V_8 , V_213 , V_71 ,
L_38 , V_26 ) ;
if ( V_25 < 0 )
return V_25 ;
}
return 0 ;
}
static int F_127 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
struct V_22 * V_245 = & V_8 -> V_24 ;
const char * const * V_246 = V_8 -> V_247 ;
int V_71 , V_229 ;
T_1 V_230 [ V_232 ] ;
V_229 = F_100 ( V_6 ,
V_8 -> V_28 [ 0 ] ,
V_230 ,
V_232 ) ;
if ( V_229 <= 0 )
return - V_233 ;
if ( ! V_246 )
V_246 = V_248 ;
for ( V_71 = 0 ; V_71 < V_229 ; V_71 ++ )
F_36 ( V_245 , V_246 [ V_71 ] , V_71 , NULL ) ;
return 0 ;
}
static T_1 F_128 ( struct V_5 * V_6 , T_1 V_249 ,
int V_51 )
{
T_1 V_189 [ V_232 ] ;
int V_207 ;
V_207 = F_100 ( V_6 , V_249 , V_189 , F_113 ( V_189 ) ) ;
if ( V_51 >= 0 && V_51 < V_207 )
return V_189 [ V_51 ] ;
return 0 ;
}
static int F_129 ( struct V_5 * V_6 , T_1 V_27 ,
const char * V_250 , int V_51 , int V_251 )
{
unsigned int V_205 , V_207 ;
char V_117 [ 32 ] ;
int V_25 ;
if ( V_251 == V_35 )
V_205 = V_81 ;
else
V_205 = V_252 ;
if ( ! ( F_35 ( V_6 , V_27 ) & V_205 ) )
return 0 ;
V_205 = F_108 ( V_6 , V_27 , V_251 ) ;
V_207 = ( V_205 & V_211 ) >> V_212 ;
if ( ! V_207 )
return 0 ;
snprintf ( V_117 , sizeof( V_117 ) , L_39 , V_250 ) ;
V_25 = F_88 ( V_6 -> V_8 , V_213 , V_51 , V_117 ,
F_110 ( V_27 , 3 , 0 , V_251 ) ) ;
if ( V_25 < 0 )
return V_25 ;
return 1 ;
}
static int F_130 ( struct V_5 * V_6 ,
const struct V_171 * V_172 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
struct V_22 * V_50 = & V_8 -> V_169 ;
struct V_22 * V_253 = & V_8 -> V_254 ;
int V_25 , V_71 ;
unsigned int V_164 ;
F_36 ( V_253 , V_255 [ 0 ] , 0 , NULL ) ;
for ( V_71 = 0 ; V_71 < V_8 -> V_256 ; V_71 ++ ) {
T_1 V_27 ;
int V_58 , V_257 ;
char V_250 [ 32 ] ;
V_27 = V_8 -> V_258 [ V_71 ] ;
if ( F_101 ( F_35 ( V_6 , V_27 ) ) != V_259 )
continue;
V_164 = F_91 ( V_6 , V_27 ) ;
if ( F_131 ( V_164 ) == V_260 )
continue;
V_58 = F_132 ( V_6 , V_8 -> V_18 [ 0 ] , V_27 ) ;
if ( V_58 < 0 )
continue;
F_93 ( V_6 , V_27 , & V_8 -> V_95 ,
V_250 , sizeof( V_250 ) , NULL ) ;
F_36 ( V_253 , V_250 , V_58 , & V_257 ) ;
if ( F_32 ( V_6 , L_2 ) != 1 )
F_36 ( V_50 , V_250 , V_58 , & V_257 ) ;
V_25 = F_129 ( V_6 , V_27 , V_250 , V_257 ,
V_261 ) ;
if ( V_25 < 0 )
return V_25 ;
if ( ! V_25 ) {
V_25 = F_129 ( V_6 , V_27 , V_250 ,
V_257 , V_35 ) ;
if ( V_25 < 0 )
return V_25 ;
if ( ! V_25 ) {
V_27 = F_128 ( V_6 ,
V_8 -> V_18 [ 0 ] , V_58 ) ;
if ( V_27 )
V_25 = F_129 ( V_6 ,
V_27 , V_250 ,
V_257 , V_261 ) ;
if ( V_25 < 0 )
return V_25 ;
}
}
}
return 0 ;
}
static int F_133 ( struct V_5 * V_6 , T_1 V_27 ,
T_1 * V_262 , T_1 * V_263 , T_1 * V_264 )
{
unsigned int V_172 ;
unsigned int type ;
if ( ! V_27 )
return 0 ;
V_172 = F_91 ( V_6 , V_27 ) ;
type = F_134 ( V_172 ) ;
switch ( F_92 ( V_172 ) ) {
case V_166 :
if ( * V_262 )
return 1 ;
if ( type != V_265 )
return 1 ;
* V_262 = V_27 ;
break;
case V_266 :
break;
case V_267 :
if ( * V_264 )
return 1 ;
if ( type != V_265 && type != V_268 )
return 1 ;
* V_264 = V_27 ;
break;
default:
if ( * V_263 )
return 1 ;
if ( type != V_265 )
return 1 ;
* V_263 = V_27 ;
break;
}
return 0 ;
}
static int F_135 ( struct V_5 * V_6 ,
struct V_269 * V_270 ,
T_1 V_178 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
struct V_171 * V_172 = & V_8 -> V_95 ;
int V_71 ;
V_270 -> V_178 = V_178 ;
if ( V_178 == 0 )
return 0 ;
for ( V_71 = 0 ; V_71 < V_172 -> V_175 ; V_71 ++ ) {
if ( V_178 == V_172 -> V_176 [ V_71 ] . V_178 )
break;
}
if ( V_71 < V_172 -> V_175 && V_172 -> V_176 [ V_71 ] . type == V_181 ) {
V_71 = F_132 ( V_6 , V_8 -> V_55 [ 0 ] , V_178 ) ;
if ( V_71 < 0 )
return - 1 ;
V_270 -> V_271 = V_71 ;
V_270 -> V_12 = - 1 ;
if ( V_8 -> V_18 )
V_270 -> V_12 = F_132 ( V_6 ,
V_8 -> V_18 [ 0 ] ,
V_8 -> V_55 [ 0 ] ) ;
} else if ( V_8 -> V_18 ) {
V_71 = F_132 ( V_6 , V_8 -> V_18 [ 0 ] , V_178 ) ;
if ( V_71 < 0 )
return - 1 ;
V_270 -> V_12 = V_71 ;
V_270 -> V_271 = - 1 ;
if ( V_8 -> V_55 )
V_270 -> V_271 = F_132 ( V_6 ,
V_8 -> V_55 [ 0 ] ,
V_8 -> V_18 [ 0 ] ) ;
}
return 0 ;
}
static int F_136 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
struct V_171 * V_172 = & V_8 -> V_95 ;
T_1 V_262 , V_263 , V_264 ;
int V_71 ;
V_262 = V_263 = V_264 = 0 ;
for ( V_71 = 0 ; V_71 < V_172 -> V_175 ; V_71 ++ )
if ( F_133 ( V_6 , V_172 -> V_176 [ V_71 ] . V_178 ,
& V_262 , & V_263 , & V_264 ) )
return 0 ;
for ( V_71 = 0 ; V_71 < V_8 -> V_256 ; V_71 ++ )
if ( F_133 ( V_6 , V_8 -> V_258 [ V_71 ] ,
& V_262 , & V_263 , & V_264 ) )
return 0 ;
if ( ! V_262 || ( ! V_263 && ! V_264 ) )
return 0 ;
if ( ! F_115 ( V_6 , V_263 ) )
return 0 ;
if ( F_135 ( V_6 , & V_8 -> V_272 , V_263 ) ||
F_135 ( V_6 , & V_8 -> V_273 , V_262 ) ||
F_135 ( V_6 , & V_8 -> V_274 , V_264 ) )
return 0 ;
return 1 ;
}
static int F_137 ( struct V_5 * V_6 , const struct V_171 * V_172 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
struct V_22 * V_50 = & V_8 -> V_169 ;
int V_71 , V_187 ;
const char * V_250 ;
for ( V_71 = 0 ; V_71 < V_172 -> V_175 ; V_71 ++ ) {
T_1 V_27 = V_172 -> V_176 [ V_71 ] . V_178 ;
int V_58 , V_25 , V_257 ;
V_58 = - 1 ;
for ( V_187 = 0 ; V_187 < V_8 -> V_242 ; V_187 ++ ) {
V_58 = F_132 ( V_6 , V_8 -> V_55 [ V_187 ] ,
V_27 ) ;
if ( V_58 >= 0 )
break;
}
if ( V_58 < 0 )
continue;
V_250 = F_138 ( V_6 , V_172 , V_71 ) ;
F_36 ( V_50 , V_250 , V_58 , & V_257 ) ;
V_25 = F_129 ( V_6 , V_27 ,
V_250 , V_257 ,
V_261 ) ;
if ( V_25 < 0 )
return V_25 ;
}
V_8 -> V_54 = V_50 -> V_33 ;
if ( V_50 -> V_33 ) {
for ( V_71 = 0 ; V_71 < V_8 -> V_242 ; V_71 ++ ) {
F_15 ( V_6 , V_8 -> V_55 [ V_71 ] , 0 ,
V_56 ,
V_50 -> V_57 [ 0 ] . V_58 ) ;
}
}
return 0 ;
}
static void F_139 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
int V_71 ;
for ( V_71 = 0 ; V_71 < V_8 -> V_95 . V_197 ; V_71 ++ ) {
T_1 V_27 = V_8 -> V_95 . V_198 [ V_71 ] ;
F_71 ( V_6 , V_27 , V_44 ) ;
}
}
static void F_140 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
int V_71 ;
for ( V_71 = 0 ; V_71 < V_8 -> V_95 . V_183 ; V_71 ++ ) {
T_1 V_178 ;
V_178 = V_8 -> V_95 . V_196 [ V_71 ] ;
if ( V_178 )
F_71 ( V_6 , V_178 , V_44 | V_275 ) ;
}
for ( V_71 = 0 ; V_71 < V_8 -> V_95 . V_185 ; V_71 ++ ) {
T_1 V_178 ;
V_178 = V_8 -> V_95 . V_201 [ V_71 ] ;
if ( V_178 )
F_71 ( V_6 , V_178 , V_44 ) ;
}
}
static int F_141 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
int V_71 , V_276 ;
if ( V_8 -> V_95 . V_173 != V_224 ||
V_8 -> V_95 . V_183 <= 1 )
return 0 ;
V_276 = 0 ;
for ( V_71 = 0 ; V_71 < V_8 -> V_95 . V_183 ; V_71 ++ ) {
T_1 V_27 = V_8 -> V_95 . V_196 [ V_71 ] ;
unsigned int V_172 = F_91 ( V_6 , V_27 ) ;
if ( F_142 ( V_172 ) & V_277 )
continue;
V_276 ++ ;
}
return ( V_276 > 1 ) ;
}
static int F_143 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
T_1 V_278 = 0 , V_279 = 0 ;
int V_280 = 0 ;
int V_71 , V_25 ;
if ( ( V_25 = F_144 ( V_6 ,
& V_8 -> V_95 ,
V_8 -> V_258 ) ) < 0 )
return V_25 ;
if ( ! V_8 -> V_95 . V_197 )
return 0 ;
if ( F_141 ( V_6 ) ) {
F_13 ( L_40 ) ;
memcpy ( V_8 -> V_95 . V_201 , V_8 -> V_95 . V_198 ,
sizeof( V_8 -> V_95 . V_198 ) ) ;
V_8 -> V_95 . V_185 = V_8 -> V_95 . V_197 ;
memcpy ( V_8 -> V_95 . V_198 , V_8 -> V_95 . V_196 ,
sizeof( V_8 -> V_95 . V_196 ) ) ;
V_8 -> V_95 . V_197 = V_8 -> V_95 . V_183 ;
V_8 -> V_95 . V_173 = V_221 ;
V_8 -> V_95 . V_183 = 0 ;
V_280 = 1 ;
}
if ( V_8 -> V_95 . V_281 ) {
int V_282 = F_35 ( V_6 , V_8 -> V_95 . V_281 ) &
( V_81 | V_252 ) ;
T_2 V_205 = F_108 ( V_6 ,
V_8 -> V_95 . V_281 , V_282 ) ;
T_1 V_283 [ 1 ] ;
if ( F_100 ( V_6 ,
V_8 -> V_95 . V_281 , V_283 , 1 ) &&
F_100 ( V_6 , V_283 [ 0 ] ,
V_283 , 1 ) > 0 ) {
int V_80 = F_35 ( V_6 , V_283 [ 0 ] ) ;
int V_284 = F_101 ( V_80 ) ;
if ( V_284 == V_285 &&
! ( V_80 & V_222 ) )
V_8 -> V_61 = V_283 [ 0 ] ;
}
if ( V_282 ) {
T_1 V_27 = V_8 -> V_95 . V_281 ;
V_282 = ( V_282 & V_81 ) ? V_35 : V_261 ;
V_25 = F_89 ( V_8 , V_214 ,
L_41 ,
F_110 ( V_27 , 1 , 0 , V_282 ) ) ;
if ( V_25 < 0 )
return V_25 ;
if ( ( V_205 & V_211 )
>> V_212 ) {
V_25 = F_89 ( V_8 ,
V_213 ,
L_42 ,
F_110 ( V_27 , 1 , 0 , V_282 ) ) ;
if ( V_25 < 0 )
return V_25 ;
}
}
F_71 ( V_6 , V_8 -> V_95 . V_281 ,
V_44 ) ;
}
if ( ! V_8 -> V_30 . V_182 ) {
V_25 = F_102 ( V_6 ) ;
if ( V_25 < 0 )
return V_25 ;
V_25 = F_118 ( V_6 ,
& V_8 -> V_95 ) ;
if ( V_25 < 0 )
return V_25 ;
}
if ( V_8 -> V_236 > 0 ) {
V_25 = F_121 ( V_6 ,
V_8 -> V_236 ) ;
if ( V_25 < 0 )
return V_25 ;
}
#ifdef F_145
if ( V_8 -> V_286 > 0 ) {
T_1 V_27 = V_8 -> V_286 ;
unsigned int V_205 ;
V_25 = F_121 ( V_6 , V_27 ) ;
if ( V_25 < 0 )
return V_25 ;
V_25 = F_146 ( V_6 , V_27 ) ;
if ( V_25 < 0 )
return V_25 ;
if ( V_6 -> V_239 ) {
V_6 -> V_239 -> V_287 = V_8 -> V_288 ;
V_205 = F_108 ( V_6 , V_27 , V_35 ) ;
if ( ! ( V_205 & V_237 ) ) {
V_25 = F_125 ( V_6 ) ;
if ( V_25 < 0 )
return V_25 ;
}
}
}
#endif
V_25 = F_119 ( V_6 , & V_8 -> V_95 ) ;
if ( V_25 < 0 )
return V_25 ;
if ( V_280 ) {
memcpy ( V_8 -> V_95 . V_196 , V_8 -> V_95 . V_198 ,
sizeof( V_8 -> V_95 . V_196 ) ) ;
V_8 -> V_95 . V_183 = V_8 -> V_95 . V_197 ;
V_8 -> V_95 . V_173 = V_221 ;
V_8 -> V_95 . V_197 = 0 ;
}
if ( F_136 ( V_6 ) ) {
V_8 -> V_75 = 1 ;
V_8 -> V_124 = 1 ;
V_8 -> V_243 = 1 ;
V_8 -> V_242 = 1 ;
}
for ( V_71 = 0 ; V_71 < V_8 -> V_243 ; V_71 ++ ) {
V_25 = F_117 ( V_6 , V_8 -> V_244 [ V_71 ] ,
V_8 -> V_289 [ V_71 ] , V_71 ) ;
if ( V_25 < 0 )
return V_25 ;
}
V_25 = F_137 ( V_6 , & V_8 -> V_95 ) ;
if ( V_25 < 0 )
return V_25 ;
if ( V_8 -> V_61 > 0 ) {
V_25 = F_120 ( V_6 ) ;
if ( V_25 < 0 )
return V_25 ;
}
if ( V_8 -> V_256 > 0 && ! V_8 -> V_9 )
if ( ( V_25 = F_130 ( V_6 ,
& V_8 -> V_95 ) ) < 0 )
return V_25 ;
if ( V_8 -> V_242 > 0 ) {
V_25 = F_126 ( V_6 ) ;
if ( V_25 < 0 )
return V_25 ;
}
if ( V_8 -> V_79 > 0 ) {
V_25 = F_127 ( V_6 ) ;
if ( V_25 < 0 )
return V_25 ;
}
V_25 = F_94 ( V_8 ) ;
if ( V_25 < 0 )
return V_25 ;
V_8 -> V_30 . V_290 = V_8 -> V_30 . V_182 * 2 ;
if ( V_8 -> V_30 . V_290 > 2 )
V_8 -> V_291 = 1 ;
for ( V_71 = V_6 -> V_292 ; V_71 < V_6 -> V_292 + V_6 -> V_293 ; V_71 ++ ) {
unsigned int V_220 = F_35 ( V_6 , V_71 ) ;
if ( V_220 & V_194 ) {
switch ( F_101 ( V_220 ) ) {
case V_193 :
if ( ! V_278 )
V_278 = V_71 ;
break;
case V_294 :
if ( ! V_279 )
V_279 = V_71 ;
break;
}
}
}
if ( V_8 -> V_95 . V_295 )
V_8 -> V_30 . V_31 = V_278 ;
if ( V_279 && V_8 -> V_95 . V_296 )
V_8 -> V_84 = V_279 ;
if ( V_8 -> V_157 . V_297 )
V_8 -> V_74 [ V_8 -> V_73 ++ ] = V_8 -> V_157 . V_297 ;
V_8 -> V_47 = & V_8 -> V_169 ;
if ( ! V_8 -> V_9 )
V_8 -> V_9 = & V_8 -> V_254 ;
V_8 -> V_19 = & V_8 -> V_24 ;
V_8 -> V_59 = & V_8 -> V_228 ;
return 1 ;
}
static int F_147 ( struct V_5 * V_6 ,
struct V_171 * V_172 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
T_1 V_178 = V_172 -> V_196 [ 0 ] ;
if ( ! V_178 )
return 0 ;
if ( F_115 ( V_6 , V_178 ) )
V_8 -> V_150 = 1 ;
return 0 ;
}
static int F_148 ( struct V_5 * V_6 ,
struct V_171 * V_172 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
int V_25 ;
T_1 V_298 = 0x0 ;
int V_71 ;
for ( V_71 = 0 ; V_71 < V_8 -> V_95 . V_185 && V_298 == 0x0 ; V_71 ++ ) {
T_1 V_178 = V_8 -> V_95 . V_201 [ V_71 ] ;
unsigned int V_80 = F_35 ( V_6 , V_178 ) ;
V_80 &= ( V_299 | V_81 ) ;
if ( V_80 == V_81 )
V_298 = V_178 ;
}
if ( V_298 == 0 && V_8 -> V_95 . V_185 == 0 ) {
for ( V_71 = 0 ; V_71 < V_8 -> V_95 . V_197 && V_298 == 0x0 ; V_71 ++ ) {
T_1 V_178 = V_8 -> V_95 . V_198 [ V_71 ] ;
unsigned int V_300 ;
V_300 = F_91 ( V_6 , V_178 ) ;
if ( F_134 ( V_300 ) == V_301 ) {
unsigned int V_80 = F_35 ( V_6 , V_178 ) ;
V_80 &= ( V_299 | V_81 ) ;
if ( V_80 == V_81 )
V_298 = V_178 ;
}
}
}
if ( V_298 ) {
V_25 = F_116 ( V_6 , L_28 , V_298 , 1 ) ;
if ( V_25 < 0 )
return V_25 ;
}
return 0 ;
}
static int F_149 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
int V_25 ;
if ( ( V_25 = F_144 ( V_6 , & V_8 -> V_95 , NULL ) ) < 0 )
return V_25 ;
if ( ( V_25 = F_137 ( V_6 , & V_8 -> V_95 ) ) < 0 )
return V_25 ;
if ( ( V_25 = F_147 ( V_6 , & V_8 -> V_95 ) ) < 0 )
return V_25 ;
if ( ( V_25 = F_148 ( V_6 , & V_8 -> V_95 ) ) < 0 )
return V_25 ;
if ( V_8 -> V_242 > 0 ) {
V_25 = F_126 ( V_6 ) ;
if ( V_25 < 0 )
return V_25 ;
}
V_25 = F_94 ( V_8 ) ;
if ( V_25 < 0 )
return V_25 ;
if ( V_8 -> V_95 . V_295 )
V_8 -> V_30 . V_31 = 0x05 ;
if ( V_8 -> V_95 . V_296 )
V_8 -> V_84 = 0x04 ;
if ( V_8 -> V_157 . V_297 )
V_8 -> V_74 [ V_8 -> V_73 ++ ] = V_8 -> V_157 . V_297 ;
V_8 -> V_47 = & V_8 -> V_169 ;
V_8 -> V_9 = & V_8 -> V_254 ;
return 1 ;
}
static void F_150 ( struct V_5 * V_6 , unsigned int V_302 ,
unsigned int V_303 , unsigned int V_304 )
{
unsigned int V_305 , V_306 , V_307 ;
F_13 ( L_43 , V_38 , V_302 , V_303 , V_304 ) ;
V_305 = F_14 ( V_6 , V_6 -> V_66 , 0 ,
V_308 , 0 ) ;
V_305 = ( V_305 & ~ V_303 ) | ( V_304 & V_303 ) ;
V_306 = F_14 ( V_6 , V_6 -> V_66 , 0 ,
V_309 , 0 ) ;
V_306 |= V_302 ;
V_307 = F_14 ( V_6 , V_6 -> V_66 , 0 ,
V_310 , 0 ) ;
V_307 |= V_303 ;
F_64 ( V_6 , V_6 -> V_66 , 0 , 0x7e7 , 0 ) ;
F_64 ( V_6 , V_6 -> V_66 , 0 ,
V_311 , V_306 ) ;
F_14 ( V_6 , V_6 -> V_66 , 0 ,
V_312 , V_307 ) ;
F_49 ( 1 ) ;
F_14 ( V_6 , V_6 -> V_66 , 0 ,
V_313 , V_305 ) ;
}
static int F_151 ( struct V_5 * V_6 , T_1 V_27 ,
unsigned char type , int V_304 )
{
struct V_314 * V_315 ;
V_315 = F_152 ( V_6 , V_27 ) ;
if ( ! V_315 )
return - V_162 ;
V_315 -> V_316 = type ;
V_315 -> V_69 = V_304 ;
return 0 ;
}
static int F_153 ( struct V_5 * V_6 , T_1 V_27 ,
unsigned int type )
{
struct V_314 * V_315 ;
if ( ! F_115 ( V_6 , V_27 ) )
return 0 ;
V_315 = F_152 ( V_6 , V_27 ) ;
if ( ! V_315 )
return - V_162 ;
if ( V_315 -> V_316 && V_315 -> V_316 != type )
return 0 ;
V_315 -> V_316 = type ;
F_154 ( V_6 , V_27 , 0 ) ;
return 1 ;
}
static int F_155 ( struct V_171 * V_172 , T_1 V_27 )
{
int V_71 ;
for ( V_71 = 0 ; V_71 < V_172 -> V_183 ; V_71 ++ )
if ( V_172 -> V_196 [ V_71 ] == V_27 )
return 1 ;
for ( V_71 = 0 ; V_71 < V_172 -> V_197 ; V_71 ++ )
if ( V_172 -> V_198 [ V_71 ] == V_27 )
return 1 ;
return 0 ;
}
static void F_156 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
const T_1 * V_180 ;
for ( V_180 = V_8 -> V_317 ; * V_180 ; V_180 ++ )
if ( ! F_99 ( V_8 , * V_180 ) )
F_64 ( V_6 , * V_180 , 0 ,
V_109 , V_111 ) ;
}
static inline int F_157 ( struct V_5 * V_6 , const char * V_318 ,
int * V_319 )
{
const char * V_320 ;
V_320 = F_158 ( V_6 , V_318 ) ;
if ( V_320 ) {
unsigned long V_26 ;
if ( ! F_159 ( V_320 , 0 , & V_26 ) ) {
* V_319 = V_26 ;
return 1 ;
}
}
return 0 ;
}
static void F_160 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
int V_26 ;
V_26 = F_32 ( V_6 , L_44 ) ;
if ( V_26 >= 0 )
V_8 -> V_150 = V_26 ;
if ( F_157 ( V_6 , L_45 , & V_8 -> V_321 ) ) {
V_8 -> V_322 = V_8 -> V_85 = V_8 -> V_323 =
V_8 -> V_321 ;
}
if ( F_157 ( V_6 , L_46 , & V_8 -> V_85 ) )
V_8 -> V_321 &= V_8 -> V_321 ;
if ( F_157 ( V_6 , L_47 , & V_8 -> V_323 ) )
V_8 -> V_85 &= V_8 -> V_321 ;
if ( F_157 ( V_6 , L_48 , & V_8 -> V_322 ) )
V_8 -> V_322 &= V_8 -> V_321 ;
if ( F_157 ( V_6 , L_49 , & V_8 -> V_324 ) )
V_8 -> V_324 &= V_8 -> V_321 ;
V_26 = F_32 ( V_6 , L_50 ) ;
if ( V_26 >= 0 )
V_8 -> V_325 = V_26 ;
F_157 ( V_6 , L_51 , & V_8 -> V_326 ) ;
if ( F_157 ( V_6 , L_52 , & V_8 -> V_92 ) ) {
V_8 -> V_321 |= V_8 -> V_92 ;
V_8 -> V_85 |= V_8 -> V_92 ;
if ( V_8 -> V_326 )
V_8 -> V_323 |= V_8 -> V_92 ;
}
}
static void F_161 ( struct V_5 * V_6 , int V_97 ,
const T_1 * V_218 )
{
while ( V_97 -- )
F_74 ( V_6 , * V_218 ++ ) ;
}
static void F_162 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
if ( V_8 -> V_95 . V_183 )
F_161 ( V_6 , V_8 -> V_95 . V_183 ,
V_8 -> V_95 . V_196 ) ;
if ( V_8 -> V_95 . V_197 &&
V_8 -> V_95 . V_198 [ 0 ] != V_8 -> V_95 . V_196 [ 0 ] )
F_161 ( V_6 , V_8 -> V_95 . V_197 ,
V_8 -> V_95 . V_198 ) ;
}
static int F_163 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
struct V_171 * V_172 = & V_8 -> V_95 ;
unsigned int V_327 ;
int V_71 ;
F_164 ( V_6 , V_8 -> V_328 ) ;
if ( V_8 -> V_108 )
for ( V_71 = 0 ; V_71 < V_8 -> V_124 ; V_71 ++ )
F_64 ( V_6 ,
V_8 -> V_106 [ V_71 ] , 0 ,
V_109 , V_111 ) ;
F_160 ( V_6 ) ;
V_327 = V_8 -> V_323 ;
if ( ! V_8 -> V_325 )
V_327 |= V_8 -> V_322 ;
F_150 ( V_6 , V_8 -> V_321 , V_8 -> V_85 , V_327 ) ;
if ( V_8 -> V_150 ) {
for ( V_71 = 0 ; V_71 < V_172 -> V_183 ; V_71 ++ ) {
T_1 V_27 = V_172 -> V_196 [ V_71 ] ;
F_153 ( V_6 , V_27 , V_329 ) ;
}
if ( V_172 -> V_173 == V_174 &&
V_172 -> V_185 > 0 ) {
for ( V_71 = 0 ; V_71 < V_172 -> V_197 ; V_71 ++ ) {
T_1 V_27 = V_172 -> V_198 [ V_71 ] ;
F_153 ( V_6 , V_27 , V_330 ) ;
}
}
F_71 ( V_6 , V_8 -> V_95 . V_198 [ 0 ] ,
V_44 ) ;
F_162 ( V_6 ) ;
} else {
F_139 ( V_6 ) ;
F_140 ( V_6 ) ;
for ( V_71 = 0 ; V_71 < V_172 -> V_183 ; V_71 ++ )
F_165 ( V_6 , V_172 -> V_196 [ V_71 ] , 1 ) ;
}
if ( V_8 -> V_75 ) {
if ( V_8 -> V_18 )
F_15 ( V_6 , V_8 -> V_18 [ 0 ] , 0 ,
V_56 , 0 ) ;
if ( F_153 ( V_6 , V_8 -> V_272 . V_178 , V_331 ) )
F_74 ( V_6 , V_8 -> V_272 . V_178 ) ;
if ( F_153 ( V_6 , V_8 -> V_274 . V_178 ,
V_331 ) )
F_74 ( V_6 , V_8 -> V_274 . V_178 ) ;
}
for ( V_71 = 0 ; V_71 < V_172 -> V_175 ; V_71 ++ ) {
T_1 V_27 = V_172 -> V_176 [ V_71 ] . V_178 ;
int type = V_172 -> V_176 [ V_71 ] . type ;
unsigned int V_37 , V_332 ;
if ( type == V_181 ) {
V_37 = F_69 ( V_6 , V_27 ) ;
V_37 |= V_43 ;
F_71 ( V_6 , V_27 , V_37 ) ;
} else {
V_37 = F_14 ( V_6 , V_27 , 0 ,
V_39 , 0 ) ;
if ( ! ( V_37 & V_43 ) ||
( V_37 & V_44 ) ) {
V_37 &= ~ V_44 ;
V_37 |= V_43 ;
F_71 ( V_6 , V_27 , V_37 ) ;
}
}
V_332 = F_91 ( V_6 , V_27 ) ;
if ( F_131 ( V_332 ) != V_333 ) {
if ( F_153 ( V_6 , V_27 , V_334 ) )
F_74 ( V_6 , V_27 ) ;
}
}
for ( V_71 = 0 ; V_71 < V_8 -> V_256 ; V_71 ++ )
F_71 ( V_6 , V_8 -> V_258 [ V_71 ] ,
V_43 ) ;
if ( V_172 -> V_335 [ 0 ] )
F_71 ( V_6 , V_172 -> V_335 [ 0 ] ,
V_44 ) ;
if ( V_172 -> V_296 )
F_71 ( V_6 , V_172 -> V_296 ,
V_43 ) ;
for ( V_71 = 0 ; V_71 < V_8 -> V_336 ; V_71 ++ ) {
T_1 V_27 = V_8 -> V_337 [ V_71 ] ;
int V_37 , V_164 ;
if ( ! V_8 -> V_150 ||
V_8 -> V_338 == V_27 ) {
F_165 ( V_6 , V_27 , 1 ) ;
continue;
}
if ( F_155 ( V_172 , V_27 ) )
continue;
V_37 = F_14 ( V_6 , V_27 , 0 ,
V_39 , 0 ) ;
if ( V_37 & V_43 ) {
F_165 ( V_6 , V_27 , 1 ) ;
continue;
}
V_164 = F_91 ( V_6 , V_27 ) ;
V_164 = F_131 ( V_164 ) ;
if ( V_164 != V_260 &&
! F_115 ( V_6 , V_27 ) ) {
F_165 ( V_6 , V_27 , 1 ) ;
continue;
}
if ( F_153 ( V_6 , V_27 , V_339 ) ) {
F_74 ( V_6 , V_27 ) ;
continue;
}
F_165 ( V_6 , V_27 , 0 ) ;
}
F_166 ( V_6 ) ;
F_167 ( & V_8 -> V_90 ) ;
if ( V_8 -> V_317 )
F_156 ( V_6 ) ;
return 0 ;
}
static void F_44 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
if ( V_8 -> V_157 . V_297 ) {
struct V_153 * V_340 = V_8 -> V_157 . V_297 ;
int V_71 ;
for ( V_71 = 0 ; V_71 < V_8 -> V_157 . V_341 ; V_71 ++ )
F_168 ( V_340 [ V_71 ] . V_117 ) ;
}
F_169 ( & V_8 -> V_157 ) ;
}
static void F_170 ( struct V_5 * V_6 )
{
unsigned int V_71 , V_164 ;
if ( V_6 -> V_342 -> V_343 )
return;
for ( V_71 = 0 ; V_71 < V_6 -> V_344 . V_341 ; V_71 ++ ) {
struct V_345 * V_178 = F_171 ( & V_6 -> V_344 , V_71 ) ;
V_164 = F_91 ( V_6 , V_178 -> V_27 ) ;
if ( F_131 ( V_164 ) != V_260 )
F_64 ( V_6 , V_178 -> V_27 , 0 ,
V_41 , 0 ) ;
}
}
static void F_172 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
F_170 ( V_6 ) ;
if ( V_8 -> V_322 )
F_150 ( V_6 , V_8 -> V_321 ,
V_8 -> V_85 , V_8 -> V_323 &
~ V_8 -> V_322 ) ;
}
static void F_173 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
if ( ! V_8 )
return;
F_172 ( V_6 ) ;
F_168 ( V_8 ) ;
F_174 ( V_6 ) ;
}
static void F_175 ( struct V_5 * V_6 , T_1 V_27 ,
unsigned int V_346 )
{
unsigned int V_347 , V_348 ;
V_348 = F_14 ( V_6 , V_27 ,
0 , V_39 , 0x00 ) ;
if ( V_348 & V_43 ) {
struct V_7 * V_8 = V_6 -> V_8 ;
if ( V_27 == V_8 -> V_146 || V_27 == V_8 -> V_145 )
return;
}
V_347 = V_348 ;
if ( V_346 & ( V_43 | V_44 ) )
V_348 &= ~ ( V_43 | V_44 ) ;
V_348 |= V_346 ;
if ( V_347 != V_348 )
F_15 ( V_6 , V_27 , 0 ,
V_41 ,
V_348 ) ;
}
static void F_176 ( struct V_5 * V_6 , T_1 V_27 ,
unsigned int V_346 )
{
unsigned int V_348 = F_14 ( V_6 , V_27 ,
0 , V_39 , 0x00 ) ;
if ( V_348 & V_346 )
F_15 ( V_6 , V_27 , 0 ,
V_41 ,
V_348 & ~ V_346 ) ;
}
static inline int F_177 ( struct V_5 * V_6 , T_1 V_27 )
{
if ( ! V_27 )
return 0 ;
return F_178 ( V_6 , V_27 ) ;
}
static void F_179 ( struct V_5 * V_6 ,
int V_349 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
struct V_171 * V_172 = & V_8 -> V_95 ;
int V_71 ;
for ( V_71 = 0 ; V_71 < V_172 -> V_197 ; V_71 ++ ) {
if ( V_349 )
break;
V_349 = F_177 ( V_6 , V_172 -> V_198 [ V_71 ] ) ;
if ( V_349 ) {
unsigned int V_37 ;
V_37 = F_14 ( V_6 ,
V_172 -> V_198 [ V_71 ] , 0 ,
V_39 , 0 ) ;
if ( V_37 & V_43 )
V_349 = 0 ;
}
}
if ( V_349 ) {
for ( V_71 = 0 ; V_71 < V_172 -> V_185 ; V_71 ++ )
F_176 ( V_6 , V_172 -> V_201 [ V_71 ] ,
V_44 ) ;
if ( V_8 -> V_322 && V_8 -> V_325 )
F_150 ( V_6 , V_8 -> V_321 ,
V_8 -> V_85 , V_8 -> V_323 &
~ V_8 -> V_322 ) ;
} else {
for ( V_71 = 0 ; V_71 < V_172 -> V_185 ; V_71 ++ )
F_175 ( V_6 , V_172 -> V_201 [ V_71 ] ,
V_44 ) ;
if ( V_8 -> V_322 && V_8 -> V_325 )
F_150 ( V_6 , V_8 -> V_321 ,
V_8 -> V_85 , V_8 -> V_323 |
V_8 -> V_322 ) ;
}
}
static int F_180 ( struct V_7 * V_8 , int V_71 )
{
struct V_171 * V_172 = & V_8 -> V_95 ;
if ( V_172 -> V_196 [ V_71 ] == V_8 -> V_146 )
return 1 ;
if ( V_172 -> V_196 [ V_71 ] == V_8 -> V_145 )
return 1 ;
if ( V_172 -> V_196 [ V_71 ] == V_8 -> V_143 )
return 1 ;
return 0 ;
}
static void F_181 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
struct V_171 * V_172 = & V_8 -> V_95 ;
int V_71 , V_349 ;
V_349 = 0 ;
if ( V_8 -> V_324 )
V_349 = ! ( F_14 ( V_6 , V_6 -> V_66 , 0 ,
V_308 , 0 ) & V_8 -> V_324 ) ;
for ( V_71 = 0 ; V_71 < V_172 -> V_183 ; V_71 ++ ) {
if ( V_349 )
break;
if ( F_180 ( V_8 , V_71 ) )
continue;
V_349 = F_177 ( V_6 , V_172 -> V_196 [ V_71 ] ) ;
if ( V_349 ) {
unsigned int V_37 ;
V_37 = F_14 ( V_6 , V_172 -> V_196 [ V_71 ] , 0 ,
V_39 , 0 ) ;
if ( V_37 & V_43 )
V_349 = 0 ;
}
}
if ( V_349 ) {
if ( V_8 -> V_143 )
F_176 ( V_6 , V_8 -> V_143 ,
V_44 ) ;
for ( V_71 = 0 ; V_71 < V_172 -> V_197 ; V_71 ++ )
F_176 ( V_6 , V_172 -> V_198 [ V_71 ] ,
V_44 ) ;
} else {
if ( V_8 -> V_143 )
F_175 ( V_6 , V_8 -> V_143 ,
V_44 ) ;
for ( V_71 = 0 ; V_71 < V_172 -> V_197 ; V_71 ++ )
F_175 ( V_6 , V_172 -> V_198 [ V_71 ] ,
V_44 ) ;
}
F_179 ( V_6 , V_349 ) ;
for ( V_71 = 0 ; V_71 < V_172 -> V_183 ; V_71 ++ ) {
unsigned int V_26 = V_44 | V_275 ;
if ( F_180 ( V_8 , V_71 ) )
continue;
if ( 1 )
F_175 ( V_6 , V_172 -> V_196 [ V_71 ] , V_26 ) ;
#if 0
else
stac92xx_reset_pinctl(codec, cfg->hp_pins[i], val);
#endif
}
}
static void F_165 ( struct V_5 * V_6 , T_1 V_27 ,
int V_350 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
unsigned int V_51 , V_26 ;
for ( V_51 = 0 ; V_51 < V_8 -> V_336 ; V_51 ++ ) {
if ( V_8 -> V_337 [ V_51 ] == V_27 )
break;
}
if ( V_51 >= V_8 -> V_336 )
return;
V_51 = 1 << V_51 ;
V_26 = F_14 ( V_6 , V_6 -> V_66 , 0 , 0x0fec , 0x0 ) & 0xff ;
if ( V_350 )
V_26 &= ~ V_51 ;
else
V_26 |= V_51 ;
F_64 ( V_6 , V_6 -> V_66 , 0 , 0x7ec , V_26 ) ;
}
static void F_182 ( struct V_5 * V_6 , T_1 V_27 )
{
F_165 ( V_6 , V_27 , F_177 ( V_6 , V_27 ) ) ;
}
static unsigned int F_183 ( struct V_5 * V_6 , int V_51 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
unsigned int V_172 ;
V_172 = F_91 ( V_6 , V_8 -> V_98 [ V_51 ] ) ;
return F_131 ( V_172 ) ;
}
static int F_184 ( struct V_5 * V_6 ,
const T_1 * V_351 , int V_352 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
int V_51 , V_353 ;
unsigned int V_164 ;
for ( V_353 = 0 ; V_353 < V_352 ; V_353 ++ ) {
for ( V_51 = 0 ; V_51 < V_8 -> V_97 ; V_51 ++ )
if ( V_8 -> V_98 [ V_51 ] == V_351 [ V_353 ] )
break;
if ( V_51 >= V_8 -> V_97 )
break;
V_164 = F_183 ( V_6 , V_51 ) ;
if ( V_164 == V_260 )
break;
}
return V_353 ;
}
static void F_185 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
struct V_269 * V_270 ;
if ( F_177 ( V_6 , V_8 -> V_272 . V_178 ) )
V_270 = & V_8 -> V_272 ;
else if ( F_177 ( V_6 , V_8 -> V_274 . V_178 ) )
V_270 = & V_8 -> V_274 ;
else
V_270 = & V_8 -> V_273 ;
if ( V_270 -> V_12 >= 0 )
F_15 ( V_6 , V_8 -> V_18 [ 0 ] , 0 ,
V_56 ,
V_270 -> V_12 ) ;
if ( V_270 -> V_271 >= 0 )
F_15 ( V_6 , V_8 -> V_55 [ 0 ] , 0 ,
V_56 ,
V_270 -> V_271 ) ;
}
static void F_186 ( struct V_5 * V_6 ,
struct V_314 * V_315 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
int V_304 ;
switch ( V_315 -> V_316 ) {
case V_329 :
case V_330 :
F_181 ( V_6 ) ;
break;
case V_331 :
F_185 ( V_6 ) ;
break;
}
switch ( V_315 -> V_316 ) {
case V_329 :
case V_330 :
case V_331 :
case V_334 :
case V_339 :
if ( V_8 -> V_336 > 0 )
F_182 ( V_6 , V_315 -> V_27 ) ;
switch ( V_6 -> V_354 ) {
case 0x103c308f :
if ( V_315 -> V_27 == 0xb ) {
int V_178 = V_43 ;
if ( F_177 ( V_6 , 0xa )
&& F_177 ( V_6 , 0xb ) )
V_178 |= V_137 ;
if ( ! F_177 ( V_6 , 0xb ) )
V_178 |= V_137 ;
F_71 ( V_6 , 0x0a , V_178 ) ;
}
}
break;
case V_355 :
V_304 = F_14 ( V_6 , V_6 -> V_66 , 0 ,
V_308 , 0 ) ;
F_64 ( V_6 , V_6 -> V_66 , 0 , 0x7e0 ,
! ! ( V_304 & ( 1 << V_315 -> V_69 ) ) ) ;
break;
}
}
static void F_74 ( struct V_5 * V_6 , T_1 V_27 )
{
struct V_314 * V_315 = F_187 ( V_6 , V_27 ) ;
if ( ! V_315 )
return;
F_186 ( V_6 , V_315 ) ;
}
static void F_188 ( struct V_5 * V_6 , unsigned int V_356 )
{
struct V_314 * V_315 ;
int V_357 ;
V_357 = ( V_356 >> 26 ) & 0x7f ;
V_315 = F_189 ( V_6 , V_357 ) ;
if ( ! V_315 )
return;
V_315 -> V_358 = 1 ;
F_186 ( V_6 , V_315 ) ;
F_166 ( V_6 ) ;
}
static void F_190 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
unsigned int V_327 ;
if ( V_8 -> V_92 )
return;
V_327 = F_191 ( V_6 , V_6 -> V_66 , V_359 ) ;
V_327 &= V_360 ;
if ( V_327 > 3 )
V_8 -> V_92 = 0x08 ;
else
V_8 -> V_92 = 0x01 ;
}
static int F_192 ( struct V_5 * V_6 , int V_361 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
const struct V_362 * V_363 = NULL ;
if ( ( V_6 -> V_354 >> 16 ) == V_364 ) {
while ( ( V_363 = F_193 ( V_365 ,
NULL , V_363 ) ) ) {
if ( sscanf ( V_363 -> V_117 , L_53 ,
& V_8 -> V_326 ,
& V_8 -> V_92 ) == 2 ) {
unsigned int V_366 ;
V_366 = F_191 ( V_6 , V_6 -> V_66 ,
V_359 ) ;
V_366 &= V_360 ;
if ( V_8 -> V_92 < V_366 )
V_8 -> V_92 = 1 << V_8 -> V_92 ;
else
V_8 -> V_338 = V_8 -> V_92 ;
return 1 ;
}
if ( sscanf ( V_363 -> V_117 , L_54 ,
& V_8 -> V_326 ) == 1 ) {
F_190 ( V_6 ) ;
return 1 ;
}
if ( strstr ( V_363 -> V_117 , L_55 ) ) {
F_190 ( V_6 ) ;
switch ( V_6 -> V_354 ) {
case 0x103c148a :
V_8 -> V_326 = 0 ;
break;
default:
V_8 -> V_326 = 1 ;
break;
}
return 1 ;
}
}
if ( ! F_194 ( V_6 -> V_354 ) &&
( V_361 == 0 || V_361 == 1 ) ) {
F_190 ( V_6 ) ;
V_8 -> V_326 = V_361 ;
return 1 ;
}
}
return 0 ;
}
static int F_194 ( T_2 V_354 )
{
switch ( V_354 ) {
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
static void F_195 ( struct V_367 * V_368 ,
struct V_5 * V_6 , T_1 V_27 )
{
if ( V_27 == V_6 -> V_66 )
F_196 ( V_368 , L_56 ,
F_14 ( V_6 , V_27 , 0 , 0x0fec , 0x0 ) ) ;
}
static void F_197 ( struct V_367 * V_368 ,
struct V_5 * V_6 ,
unsigned int V_369 )
{
F_196 ( V_368 , L_57 ,
F_14 ( V_6 , V_6 -> V_66 , 0 , V_369 , 0 ) ) ;
}
static void F_198 ( struct V_367 * V_368 ,
struct V_5 * V_6 , T_1 V_27 )
{
F_195 ( V_368 , V_6 , V_27 ) ;
if ( V_27 == V_6 -> V_66 )
F_197 ( V_368 , V_6 , 0xfa0 ) ;
}
static void F_199 ( struct V_367 * V_368 ,
struct V_5 * V_6 , T_1 V_27 )
{
if ( V_27 == V_6 -> V_66 )
F_197 ( V_368 , V_6 , 0xfe0 ) ;
}
static void F_200 ( struct V_367 * V_368 ,
struct V_5 * V_6 , T_1 V_27 )
{
if ( V_27 == V_6 -> V_66 )
F_197 ( V_368 , V_6 , 0xfeb ) ;
}
static int F_201 ( struct V_5 * V_6 )
{
F_163 ( V_6 ) ;
F_202 ( V_6 ) ;
F_203 ( V_6 ) ;
F_162 ( V_6 ) ;
return 0 ;
}
static int F_204 ( struct V_5 * V_6 , T_3 V_370 )
{
F_172 ( V_6 ) ;
return 0 ;
}
static int F_205 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
if ( V_8 -> V_338 )
F_12 ( V_6 , V_8 -> V_338 ,
V_8 -> V_371 ) ;
else if ( V_8 -> V_92 )
F_150 ( V_6 , V_8 -> V_321 ,
V_8 -> V_85 , V_8 -> V_323 ) ;
return 0 ;
}
static void F_206 ( struct V_5 * V_6 , T_1 V_372 ,
unsigned int V_373 )
{
unsigned int V_374 = V_373 ;
struct V_7 * V_8 = V_6 -> V_8 ;
if ( V_373 == V_111 ) {
if ( V_8 -> V_338 ) {
V_374 = V_375 ;
}
F_49 ( 100 ) ;
}
F_14 ( V_6 , V_372 , 0 , V_109 ,
V_374 ) ;
F_207 ( V_6 , V_372 , V_373 , true ) ;
}
static void F_29 ( struct V_5 * V_6 , int V_240 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
int V_376 = ! V_240 ;
if ( ! V_8 -> V_92 )
return;
if ( V_8 -> V_326 )
V_376 = ! V_376 ;
if ( ! V_8 -> V_338 ) {
if ( V_376 )
V_8 -> V_323 |= V_8 -> V_92 ;
else
V_8 -> V_323 &= ~ V_8 -> V_92 ;
F_150 ( V_6 , V_8 -> V_321 ,
V_8 -> V_85 , V_8 -> V_323 ) ;
} else {
V_8 -> V_371 = V_376 ? V_139 : V_141 ;
F_12 ( V_6 , V_8 -> V_338 ,
V_8 -> V_371 ) ;
}
}
static int F_208 ( struct V_5 * V_6 )
{
struct V_7 * V_8 ;
int V_25 ;
V_8 = F_209 ( sizeof( * V_8 ) , V_158 ) ;
if ( V_8 == NULL )
return - V_162 ;
V_6 -> V_377 = 1 ;
V_6 -> V_8 = V_8 ;
V_8 -> V_288 = 1 ;
V_8 -> V_97 = F_113 ( V_378 ) ;
V_8 -> V_98 = V_378 ;
V_8 -> V_379 = F_210 ( V_6 , V_380 ,
V_381 ,
V_382 ) ;
if ( V_8 -> V_379 < 0 )
F_13 ( V_383 L_58 ,
V_6 -> V_384 ) ;
else
F_46 ( V_6 ,
V_385 [ V_8 -> V_379 ] ) ;
V_8 -> V_30 . V_290 = 2 ;
V_8 -> V_30 . V_182 = 1 ;
V_8 -> V_30 . V_86 = V_386 ;
V_8 -> V_106 = V_387 ;
V_8 -> V_55 = V_388 ;
V_8 -> V_242 = 1 ;
V_8 -> V_256 = 0 ;
V_8 -> V_124 = 1 ;
V_8 -> V_336 = 0 ;
if ( V_8 -> V_379 == V_389 ||
V_8 -> V_379 == V_390 ||
V_8 -> V_379 == V_391 )
V_8 -> V_328 = V_392 ;
else
V_8 -> V_328 = V_393 ;
V_8 -> V_72 = V_394 ;
if ( V_8 -> V_379 == V_395 ) {
V_8 -> V_321 = V_8 -> V_85 = 0x09 ;
V_8 -> V_323 = 0x00 ;
}
V_25 = F_149 ( V_6 ) ;
if ( V_25 < 0 ) {
F_173 ( V_6 ) ;
return V_25 ;
}
if ( V_8 -> V_379 == V_395 )
V_8 -> V_150 = 0 ;
V_6 -> V_396 = V_397 ;
return 0 ;
}
static int F_211 ( struct V_5 * V_6 )
{
struct V_7 * V_8 ;
int V_25 ;
V_8 = F_209 ( sizeof( * V_8 ) , V_158 ) ;
if ( V_8 == NULL )
return - V_162 ;
V_6 -> V_377 = 1 ;
V_6 -> V_8 = V_8 ;
V_8 -> V_288 = 1 ;
V_8 -> V_97 = F_113 ( V_398 ) ;
V_8 -> V_98 = V_398 ;
V_8 -> V_379 = F_212 ( V_6 ,
V_399 ,
V_400 ,
V_401 ) ;
if ( V_8 -> V_379 < 0 )
V_8 -> V_379 = F_210 ( V_6 ,
V_399 ,
V_400 ,
V_402 ) ;
V_403:
if ( V_8 -> V_379 < 0 )
F_13 ( V_383 L_58 ,
V_6 -> V_384 ) ;
else
F_46 ( V_6 ,
V_404 [ V_8 -> V_379 ] ) ;
V_8 -> V_30 . V_290 = 2 ;
V_8 -> V_30 . V_182 = 1 ;
V_8 -> V_30 . V_86 = V_405 ;
V_8 -> V_106 = V_406 ;
V_8 -> V_55 = V_407 ;
V_8 -> V_242 = 1 ;
V_8 -> V_124 = 1 ;
V_8 -> V_336 = 0 ;
switch ( V_6 -> V_408 ) {
case 0x83847632 :
case 0x83847633 :
case 0x83847636 :
case 0x83847637 :
V_8 -> V_256 = V_409 ;
V_8 -> V_258 = V_410 ;
V_8 -> V_76 = F_113 ( V_411 ) ;
V_8 -> V_18 = V_411 ;
break;
default:
V_8 -> V_256 = 0 ;
break;
}
V_8 -> V_328 = V_412 ;
V_8 -> V_72 = V_413 ;
V_8 -> V_243 = 1 ;
V_8 -> V_244 = V_414 ;
V_8 -> V_289 = V_415 ;
V_25 = F_143 ( V_6 ) ;
if ( ! V_25 ) {
if ( V_8 -> V_379 < 0 ) {
F_111 ( V_215 L_59
L_60 ) ;
V_8 -> V_379 = V_416 ;
goto V_403;
}
V_25 = - V_233 ;
}
if ( V_25 < 0 ) {
F_173 ( V_6 ) ;
return V_25 ;
}
V_6 -> V_396 = V_397 ;
return 0 ;
}
static int F_213 ( struct V_5 * V_6 )
{
struct V_7 * V_8 ;
T_1 V_189 [ V_417 + 2 ] ;
int V_25 = 0 ;
int V_182 ;
V_8 = F_209 ( sizeof( * V_8 ) , V_158 ) ;
if ( V_8 == NULL )
return - V_162 ;
V_6 -> V_377 = 1 ;
V_6 -> V_8 = V_8 ;
V_8 -> V_288 = 0 ;
V_6 -> V_32 = V_418 ;
V_8 -> V_97 = F_113 ( V_419 ) ;
V_8 -> V_98 = V_419 ;
V_8 -> V_379 = F_210 ( V_6 ,
V_420 ,
V_421 ,
V_422 ) ;
if ( V_8 -> V_379 < 0 )
V_8 -> V_379 =
F_212 ( V_6 ,
V_420 , V_421 ,
V_423 ) ;
V_403:
if ( V_8 -> V_379 < 0 )
F_13 ( V_383 L_58 ,
V_6 -> V_384 ) ;
else
F_46 ( V_6 ,
V_424 [ V_8 -> V_379 ] ) ;
V_182 = F_100 ( V_6 , 0x0a ,
V_189 , V_417 + 2 ) - 1 ;
if ( V_182 < 3 || V_182 > 5 ) {
F_111 ( V_215 L_61
L_62 ) ;
V_182 = V_417 ;
}
V_8 -> V_328 = V_425 ;
switch ( V_182 ) {
case 0x3 :
V_8 -> V_94 = V_426 ;
break;
case 0x4 :
V_8 -> V_94 = V_427 ;
break;
case 0x5 :
V_8 -> V_94 = V_428 ;
break;
}
V_8 -> V_30 . V_86 = V_8 -> V_86 ;
V_8 -> V_63 = 0x01 ;
V_8 -> V_68 = 8 ;
V_8 -> V_286 = 0x1c ;
V_8 -> V_55 = V_429 ;
V_8 -> V_106 = V_430 ;
V_8 -> V_258 = V_431 ;
V_8 -> V_18 = V_432 ;
V_8 -> V_28 = V_433 ;
V_8 -> V_242 = F_113 ( V_429 ) ;
V_8 -> V_124 = F_113 ( V_430 ) ;
V_8 -> V_76 = F_113 ( V_432 ) ;
V_8 -> V_243 = V_434 ;
V_8 -> V_244 = V_435 ;
V_8 -> V_289 = V_436 ;
switch ( V_8 -> V_379 ) {
case V_437 :
V_8 -> V_328 = V_438 ;
case V_439 :
case V_440 :
case V_441 :
V_8 -> V_79 = 0 ;
V_8 -> V_325 = 0 ;
switch ( V_8 -> V_379 ) {
case V_439 :
F_47 ( V_6 , 0x0b , 0x90A70170 ) ;
V_8 -> V_256 = 0 ;
break;
case V_440 :
F_47 ( V_6 , 0x13 , 0x90A60160 ) ;
V_8 -> V_256 = 1 ;
break;
case V_441 :
F_47 ( V_6 , 0x0b , 0x90A70170 ) ;
F_47 ( V_6 , 0x13 , 0x90A60160 ) ;
V_8 -> V_256 = 1 ;
break;
}
break;
case V_442 :
V_8 -> V_256 = V_443 ;
V_8 -> V_79 = F_113 ( V_433 ) ;
V_8 -> V_325 = 0 ;
break;
default:
V_8 -> V_256 = V_443 ;
V_8 -> V_79 = F_113 ( V_433 ) ;
V_8 -> V_325 = 1 ;
break;
}
if ( V_8 -> V_379 != V_444 ) {
V_8 -> V_322 = V_8 -> V_321 = V_8 -> V_85 = 0x1 ;
V_8 -> V_323 = 0x01 ;
}
V_8 -> V_336 = F_113 ( V_445 ) ;
V_8 -> V_337 = V_445 ;
V_25 = F_143 ( V_6 ) ;
if ( ! V_25 ) {
if ( V_8 -> V_379 < 0 ) {
F_111 ( V_215 L_59
L_60 ) ;
V_8 -> V_379 = V_444 ;
goto V_403;
}
V_25 = - V_233 ;
}
if ( V_25 < 0 ) {
F_173 ( V_6 ) ;
return V_25 ;
}
if ( V_8 -> V_379 == V_446 )
V_8 -> V_150 = 0 ;
V_6 -> V_396 = V_397 ;
V_6 -> V_447 = F_198 ;
return 0 ;
}
static int F_214 ( struct V_5 * V_6 )
{
if ( V_6 -> V_408 != 0x111d7605 &&
V_6 -> V_408 != 0x111d76d1 )
return 0 ;
switch ( V_6 -> V_354 ) {
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
static void F_215 ( struct V_5 * V_6 , T_1 V_27 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
unsigned int V_164 = F_91 ( V_6 , V_27 ) ;
int V_71 ;
V_8 -> V_448 [ V_8 -> V_449 ] = V_27 ;
V_8 -> V_449 ++ ;
if ( F_134 ( V_164 ) == V_265 &&
F_131 ( V_164 ) != V_260 ) {
for ( V_71 = 0 ; V_71 < F_113 ( V_450 ) ; V_71 ++ ) {
if ( V_27 == V_450 [ V_71 ] ) {
V_8 -> V_451 [ V_8 -> V_452 ] = V_27 ;
V_8 -> V_452 ++ ;
}
}
}
}
static void F_216 ( struct V_5 * V_6 , T_1 V_27 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
V_8 -> V_453 [ V_8 -> V_454 ] = V_27 ;
V_8 -> V_454 ++ ;
}
static void F_217 ( struct V_5 * V_6 , T_1 V_27 )
{
int V_71 , V_187 ;
struct V_7 * V_8 = V_6 -> V_8 ;
for ( V_71 = 0 ; V_71 < V_8 -> V_454 ; V_71 ++ ) {
if ( F_132 ( V_6 ,
V_8 -> V_453 [ V_71 ] , V_27 ) >= 0 ) {
if ( ! V_8 -> V_455 [ V_71 ] ) {
V_8 -> V_455 [ V_71 ] = V_27 ;
V_8 -> V_456 [ V_71 ] = F_110 ( V_27 ,
3 , 0 , V_35 ) ;
}
for ( V_187 = 0 ; V_187 < V_8 -> V_452 ; V_187 ++ ) {
if ( F_132 ( V_6 , V_27 ,
V_8 -> V_451 [ V_187 ] ) >= 0 ) {
if ( ! V_8 -> V_457 [ V_71 ] )
V_8 -> V_457 [ V_71 ] = V_27 ;
break;
}
}
break;
}
}
}
static void F_218 ( struct V_5 * V_6 )
{
T_1 V_27 , V_458 ;
unsigned int V_220 , V_284 ;
struct V_7 * V_8 = V_6 -> V_8 ;
V_458 = V_6 -> V_292 + V_6 -> V_293 ;
for ( V_27 = V_6 -> V_292 ; V_27 < V_458 ; V_27 ++ ) {
V_220 = F_35 ( V_6 , V_27 ) ;
V_284 = F_101 ( V_220 ) ;
if ( V_284 == V_259 )
F_215 ( V_6 , V_27 ) ;
if ( V_284 == V_294 && ! ( V_220 & V_194 ) )
F_216 ( V_6 , V_27 ) ;
}
for ( V_27 = V_6 -> V_292 ; V_27 < V_458 ; V_27 ++ ) {
V_220 = F_35 ( V_6 , V_27 ) ;
V_284 = F_101 ( V_220 ) ;
if ( V_284 == V_285 )
F_217 ( V_6 , V_27 ) ;
}
V_8 -> V_98 = V_8 -> V_448 ;
V_8 -> V_97 = V_8 -> V_449 ;
V_8 -> V_106 = V_8 -> V_453 ;
V_8 -> V_124 = V_8 -> V_454 ;
V_8 -> V_244 = V_8 -> V_456 ;
V_8 -> V_289 = V_8 -> V_456 ;
V_8 -> V_243 = V_8 -> V_454 ;
V_8 -> V_55 = V_8 -> V_455 ;
V_8 -> V_242 = V_8 -> V_454 ;
V_8 -> V_18 = V_8 -> V_457 ;
V_8 -> V_76 = V_8 -> V_454 ;
V_8 -> V_258 = V_8 -> V_451 ;
V_8 -> V_256 = V_8 -> V_452 ;
}
static int F_219 ( struct V_5 * V_6 )
{
struct V_7 * V_8 ;
int V_25 ;
V_8 = F_209 ( sizeof( * V_8 ) , V_158 ) ;
if ( V_8 == NULL )
return - V_162 ;
if ( F_214 ( V_6 ) ) {
F_47 ( V_6 , 0xa , 0x2101201f ) ;
F_47 ( V_6 , 0xf , 0x2181205e ) ;
}
V_6 -> V_377 = 1 ;
V_6 -> V_8 = V_8 ;
F_218 ( V_6 ) ;
V_8 -> V_288 = 0 ;
V_6 -> V_32 = V_459 ;
V_8 -> V_286 = 0x21 ;
V_8 -> V_337 = V_460 ;
V_8 -> V_336 = F_113 ( V_460 ) ;
V_8 -> V_30 . V_86 = V_8 -> V_86 ;
V_8 -> V_328 = V_461 ;
V_8 -> V_379 = F_210 ( V_6 ,
V_462 ,
V_463 ,
V_464 ) ;
if ( V_8 -> V_379 < 0 )
V_8 -> V_379 =
F_212 ( V_6 ,
V_462 , V_463 ,
V_465 ) ;
V_403:
if ( V_8 -> V_379 < 0 )
F_13 ( V_383 L_58 ,
V_6 -> V_384 ) ;
else
F_46 ( V_6 ,
V_466 [ V_8 -> V_379 ] ) ;
V_6 -> V_396 = V_397 ;
switch ( V_8 -> V_379 ) {
case V_467 :
V_8 -> V_328 = V_468 ;
break;
}
if ( F_192 ( V_6 , - 1 ) )
F_106 ( L_63 ,
V_8 -> V_92 ,
V_8 -> V_326 ) ;
if ( V_8 -> V_92 ) {
if ( ! V_8 -> V_338 ) {
V_8 -> V_321 |= V_8 -> V_92 ;
V_8 -> V_85 |= V_8 -> V_92 ;
V_8 -> V_323 |= V_8 -> V_92 ;
} else {
V_6 -> V_396 . V_469 =
F_206 ;
}
#ifdef F_220
V_6 -> V_396 . V_470 = F_205 ;
#endif
}
V_25 = F_143 ( V_6 ) ;
if ( ! V_25 ) {
if ( V_8 -> V_379 < 0 ) {
F_111 ( V_215 L_59
L_60 ) ;
V_8 -> V_379 = V_471 ;
goto V_403;
}
V_25 = - V_233 ;
}
if ( V_25 < 0 ) {
F_173 ( V_6 ) ;
return V_25 ;
}
V_6 -> V_447 = F_195 ;
return 0 ;
}
static int F_221 ( struct V_5 * V_6 ,
T_1 V_472 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
int V_51 ;
for ( V_51 = 0 ; V_51 < V_8 -> V_97 ; V_51 ++ )
if ( V_8 -> V_98 [ V_51 ] == V_472 )
break;
if ( ( V_51 + 2 ) >= V_8 -> V_97 )
return 0 ;
if ( F_183 ( V_6 , V_51 + 1 ) != V_260 )
return 2 ;
if ( F_183 ( V_6 , V_51 + 2 ) != V_260 )
return 2 ;
if ( F_183 ( V_6 , V_51 ) != V_260 )
return 1 ;
else
return 0 ;
}
static int F_222 ( struct V_1 * V_2 ,
struct V_10 * V_11 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = V_6 -> V_8 ;
V_11 -> V_14 . integer . V_14 [ 0 ] = ! ! ( V_8 -> V_323 & 0x20 ) ;
return 0 ;
}
static int F_223 ( struct V_1 * V_2 ,
struct V_10 * V_11 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = V_6 -> V_8 ;
unsigned int V_323 ;
V_323 = ( V_8 -> V_323 & ~ 0x20 ) |
( V_11 -> V_14 . integer . V_14 [ 0 ] ? 0x20 : 0 ) ;
if ( V_323 == V_8 -> V_323 )
return 0 ;
V_8 -> V_323 = V_323 ;
F_150 ( V_6 , V_8 -> V_321 , V_8 -> V_85 , V_8 -> V_323 ) ;
return 1 ;
}
static int F_224 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
if ( ! F_83 ( V_8 , & V_473 ,
L_64 , 0 ) )
return - V_162 ;
V_8 -> V_321 |= 0x20 ;
V_8 -> V_85 |= 0x20 ;
V_8 -> V_323 |= 0x20 ;
return 0 ;
}
static int F_225 ( struct V_5 * V_6 )
{
struct V_7 * V_8 ;
const struct V_474 * V_475 = V_476 ;
unsigned int V_477 ;
int V_25 = 0 ;
V_8 = F_209 ( sizeof( * V_8 ) , V_158 ) ;
if ( V_8 == NULL )
return - V_162 ;
V_6 -> V_377 = 1 ;
V_6 -> V_8 = V_8 ;
V_8 -> V_288 = 0 ;
V_6 -> V_396 = V_397 ;
V_8 -> V_97 = V_478 ;
switch ( V_6 -> V_408 ) {
case 0x111d76b6 :
case 0x111d76b7 :
V_8 -> V_98 = V_479 ;
break;
case 0x111d7603 :
case 0x111d7608 :
V_8 -> V_97 -- ;
default:
V_8 -> V_98 = V_480 ;
}
V_8 -> V_336 = F_113 ( V_481 ) ;
V_8 -> V_379 = F_210 ( V_6 ,
V_482 ,
V_483 ,
V_484 ) ;
V_403:
if ( V_8 -> V_379 < 0 )
F_13 ( V_383 L_58 ,
V_6 -> V_384 ) ;
else
F_46 ( V_6 ,
V_485 [ V_8 -> V_379 ] ) ;
if ( V_8 -> V_379 != V_486 ) {
V_8 -> V_321 = 0x01 ;
V_8 -> V_85 = 0x01 ;
V_8 -> V_323 = 0x01 ;
}
V_8 -> V_258 = V_487 ;
V_8 -> V_18 = V_488 ;
V_8 -> V_243 = V_489 ;
V_8 -> V_244 = V_490 ;
V_8 -> V_289 = V_491 ;
switch ( V_6 -> V_408 ) {
case 0x111d76b6 :
case 0x111d76b7 :
V_475 ++ ;
case 0x111d76b4 :
case 0x111d76b5 :
V_8 -> V_328 = V_492 ;
V_6 -> V_32 = V_493 ;
V_8 -> V_256 = F_184 ( V_6 ,
V_487 ,
V_494 ) ;
break;
case 0x111d7608 :
switch ( V_8 -> V_379 ) {
case V_495 :
V_25 = F_151 ( V_6 , V_6 -> V_66 ,
V_355 , 0x02 ) ;
if ( V_25 < 0 )
return V_25 ;
F_15 ( V_6 , V_6 -> V_66 , 0 ,
V_496 , 0x02 ) ;
F_154 ( V_6 , V_6 -> V_66 , 0 ) ;
V_8 -> V_321 |= 0x02 ;
break;
}
if ( ( V_6 -> V_497 & 0xf ) == 0 ||
( V_6 -> V_497 & 0xf ) == 1 )
V_8 -> V_103 = 40 ;
V_8 -> V_328 = V_492 ;
V_475 ++ ;
F_47 ( V_6 , 0x0f , 0x40f000f0 ) ;
F_47 ( V_6 , 0x19 , 0x40f000f3 ) ;
V_8 -> V_258 = V_498 ;
V_8 -> V_256 = F_184 ( V_6 ,
V_498 ,
V_494 - 1 ) ;
break;
case 0x111d7603 :
if ( ( V_6 -> V_497 & 0xf ) == 1 )
V_8 -> V_103 = 40 ;
default:
V_8 -> V_328 = V_492 ;
V_6 -> V_32 = V_493 ;
V_8 -> V_256 = F_184 ( V_6 ,
V_487 ,
V_494 ) ;
break;
}
if ( F_35 ( V_6 , 0xa ) & V_252 )
F_226 ( V_6 , V_475 ) ;
V_8 -> V_94 = V_499 ;
V_8 -> V_63 = 0x50 ;
V_8 -> V_68 = 0 ;
V_8 -> V_108 = 1 ;
V_8 -> V_286 = 0x26 ;
V_8 -> V_55 = V_500 ;
V_8 -> V_106 = V_501 ;
V_8 -> V_28 = V_502 ;
V_8 -> V_337 = V_481 ;
V_8 -> V_242 = F_113 ( V_500 ) ;
V_8 -> V_124 = F_113 ( V_501 ) ;
V_8 -> V_76 = F_113 ( V_488 ) ;
V_8 -> V_79 = F_221 ( V_6 , 0x1e ) ;
F_13 ( L_65 , V_8 -> V_379 ) ;
switch ( V_8 -> V_379 ) {
case V_495 :
F_47 ( V_6 , 0x0e , 0x01813040 ) ;
F_71 ( V_6 , 0x0e ,
V_43 | V_137 ) ;
case V_503 :
V_8 -> V_256 = 0 ;
V_8 -> V_79 = 0 ;
V_8 -> V_76 = 0 ;
break;
case V_504 :
case V_505 :
V_8 -> V_256 = 1 ;
V_8 -> V_79 = 0 ;
V_8 -> V_76 = 1 ;
break;
case V_506 :
V_8 -> V_256 = 1 ;
V_8 -> V_79 = 1 ;
V_8 -> V_76 = 1 ;
case V_507 :
V_8 -> V_92 = 0x01 ;
case V_508 :
F_47 ( V_6 , 0x0d , 0x90170010 ) ;
F_71 ( V_6 , 0x0d , V_44 ) ;
V_8 -> V_150 = 1 ;
break;
case V_509 :
V_8 -> V_256 = 1 ;
V_8 -> V_76 = 1 ;
V_8 -> V_79 = 1 ;
V_8 -> V_92 = 0x08 ;
break;
}
if ( F_194 ( V_6 -> V_354 ) ) {
V_477 = F_91 ( V_6 , 0x0f ) ;
if ( F_134 ( V_477 ) == V_510 ||
F_134 ( V_477 ) == V_301 ||
F_134 ( V_477 ) == V_511 ) {
V_477 = ( V_477 & ( ~ V_512 ) )
| ( V_511 <<
V_513 ) ;
V_477 = ( V_477 & ( ~ ( V_514
| V_515 ) ) )
| 0x1f ;
F_47 ( V_6 , 0x0f , V_477 ) ;
}
}
if ( F_192 ( V_6 , 1 ) )
F_106 ( L_63 ,
V_8 -> V_92 ,
V_8 -> V_326 ) ;
if ( V_8 -> V_92 ) {
if ( ! V_8 -> V_338 ) {
V_8 -> V_321 |= V_8 -> V_92 ;
V_8 -> V_85 |= V_8 -> V_92 ;
V_8 -> V_323 |= V_8 -> V_92 ;
} else {
V_6 -> V_396 . V_469 =
F_206 ;
}
#ifdef F_220
V_6 -> V_396 . V_470 = F_205 ;
#endif
}
V_8 -> V_30 . V_86 = V_8 -> V_86 ;
V_25 = F_143 ( V_6 ) ;
if ( ! V_25 ) {
if ( V_8 -> V_379 < 0 ) {
F_111 ( V_215 L_59
L_60 ) ;
V_8 -> V_379 = V_486 ;
goto V_403;
}
V_25 = - V_233 ;
}
if ( V_25 < 0 ) {
F_173 ( V_6 ) ;
return V_25 ;
}
if ( V_8 -> V_379 == V_507 ||
V_8 -> V_379 == V_508 ) {
unsigned int V_516 ;
V_516 = F_191 ( V_6 , 0x1 , V_359 ) ;
V_516 &= V_360 ;
if ( V_516 >= 6 )
F_224 ( V_6 ) ;
}
V_6 -> V_447 = F_198 ;
return 0 ;
}
static int F_227 ( struct V_5 * V_6 )
{
struct V_7 * V_8 ;
int V_25 ;
V_8 = F_209 ( sizeof( * V_8 ) , V_158 ) ;
if ( V_8 == NULL )
return - V_162 ;
V_6 -> V_377 = 1 ;
V_6 -> V_8 = V_8 ;
V_8 -> V_288 = 1 ;
V_8 -> V_97 = F_113 ( V_517 ) ;
V_8 -> V_98 = V_517 ;
V_8 -> V_379 = F_210 ( V_6 , V_518 ,
V_519 ,
V_520 ) ;
if ( V_8 -> V_379 == V_521 ) {
V_8 -> V_321 = V_8 -> V_85 = 0x03 ;
V_8 -> V_323 = 0x03 ;
F_111 ( V_383 L_66 , V_6 -> V_354 ) ;
switch ( V_6 -> V_354 ) {
case 0x106b0800 :
V_8 -> V_379 = V_522 ;
break;
case 0x106b0600 :
case 0x106b0700 :
V_8 -> V_379 = V_523 ;
break;
case 0x106b0e00 :
case 0x106b0f00 :
case 0x106b1600 :
case 0x106b1700 :
case 0x106b0200 :
case 0x106b1e00 :
V_8 -> V_379 = V_524 ;
break;
case 0x106b1a00 :
case 0x00000100 :
V_8 -> V_379 = V_525 ;
break;
case 0x106b0a00 :
case 0x106b2200 :
V_8 -> V_379 = V_526 ;
break;
default:
V_8 -> V_379 = V_524 ;
break;
}
}
V_403:
if ( V_8 -> V_379 < 0 )
F_13 ( V_383 L_58 ,
V_6 -> V_384 ) ;
else
F_46 ( V_6 ,
V_527 [ V_8 -> V_379 ] ) ;
V_8 -> V_106 = V_528 ;
V_8 -> V_55 = V_529 ;
V_8 -> V_242 = F_113 ( V_529 ) ;
V_8 -> V_124 = F_113 ( V_528 ) ;
V_8 -> V_256 = 0 ;
V_8 -> V_336 = 0 ;
V_8 -> V_328 = V_530 ;
V_8 -> V_243 = V_531 ;
V_8 -> V_244 = V_532 ;
V_8 -> V_289 = V_533 ;
V_8 -> V_30 . V_86 = V_8 -> V_86 ;
V_25 = F_143 ( V_6 ) ;
if ( ! V_25 ) {
if ( V_8 -> V_379 < 0 ) {
F_111 ( V_215 L_59
L_60 ) ;
V_8 -> V_379 = V_534 ;
goto V_403;
}
V_25 = - V_233 ;
}
if ( V_25 < 0 ) {
F_173 ( V_6 ) ;
return V_25 ;
}
V_6 -> V_396 = V_397 ;
F_228 ( V_6 , 0x12 , V_35 ,
( 0 << V_535 ) |
( 2 << V_212 ) |
( 0x27 << V_210 ) |
( 0 << V_238 ) ) ;
return 0 ;
}
static int F_229 ( struct V_5 * V_6 )
{
struct V_7 * V_8 ;
int V_25 ;
V_8 = F_209 ( sizeof( * V_8 ) , V_158 ) ;
if ( V_8 == NULL )
return - V_162 ;
V_6 -> V_377 = 1 ;
V_6 -> V_8 = V_8 ;
V_8 -> V_288 = 1 ;
V_6 -> V_32 = V_536 ;
V_8 -> V_97 = F_113 ( V_537 ) ;
V_8 -> V_98 = V_537 ;
V_8 -> V_379 = F_210 ( V_6 , V_538 ,
V_539 ,
V_540 ) ;
V_403:
if ( V_8 -> V_379 < 0 )
F_13 ( V_383 L_58 ,
V_6 -> V_384 ) ;
else
F_46 ( V_6 ,
V_541 [ V_8 -> V_379 ] ) ;
V_8 -> V_286 = 0x23 ;
V_8 -> V_106 = V_542 ;
V_8 -> V_124 = F_113 ( V_542 ) ;
V_8 -> V_55 = V_543 ;
V_8 -> V_242 = F_113 ( V_543 ) ;
V_8 -> V_28 = V_544 ;
V_8 -> V_79 = F_113 ( V_544 ) ;
V_8 -> V_247 = V_545 ;
V_8 -> V_317 = V_546 ;
V_8 -> V_30 . V_86 = V_8 -> V_86 ;
if ( V_8 -> V_379 != V_547 ) {
V_8 -> V_322 = V_8 -> V_321 = 0x01 ;
V_8 -> V_85 = V_8 -> V_323 = 0x01 ;
}
switch ( V_8 -> V_379 ) {
case V_548 :
case V_549 :
V_8 -> V_256 = 0 ;
V_8 -> V_328 = V_550 ;
break;
case V_551 :
switch ( V_6 -> V_354 ) {
case 0x10280209 :
case 0x1028022e :
F_47 ( V_6 , 0x21 , 0x01442070 ) ;
break;
}
F_47 ( V_6 , 0x0c , 0x90a79130 ) ;
F_47 ( V_6 , 0x0f , 0x0227011f ) ;
F_47 ( V_6 , 0x0e , 0x02a79130 ) ;
case V_552 :
if ( V_6 -> V_354 != 0x1028022f ) {
V_8 -> V_322 = V_8 -> V_321 = 0x04 ;
V_8 -> V_85 = V_8 -> V_323 = 0x04 ;
}
V_8 -> V_258 = V_553 ;
V_8 -> V_256 = V_554 ;
V_8 -> V_328 = V_555 ;
V_8 -> V_18 = V_556 ;
V_8 -> V_76 = F_113 ( V_556 ) ;
break;
case V_557 :
V_8 -> V_256 = 0 ;
V_8 -> V_328 = V_558 ;
break;
default:
V_8 -> V_256 = 0 ;
V_8 -> V_328 = V_559 ;
break;
}
V_8 -> V_243 = V_560 ;
V_8 -> V_244 = V_561 ;
V_8 -> V_289 = V_562 ;
V_8 -> V_336 = 0 ;
V_8 -> V_94 = V_563 ;
V_8 -> V_63 = 0x40 ;
V_8 -> V_68 = 0 ;
V_8 -> V_325 = 1 ;
V_25 = F_143 ( V_6 ) ;
if ( ! V_25 ) {
if ( V_8 -> V_379 < 0 ) {
F_111 ( V_215 L_59
L_60 ) ;
V_8 -> V_379 = V_547 ;
goto V_403;
}
V_25 = - V_233 ;
}
if ( V_25 < 0 ) {
F_173 ( V_6 ) ;
return V_25 ;
}
V_6 -> V_396 = V_397 ;
V_6 -> V_447 = F_200 ;
V_6 -> V_342 -> V_564 = 1 ;
if ( V_8 -> V_379 == V_565 )
V_8 -> V_150 = 0 ;
return 0 ;
}
static int F_230 ( struct V_5 * V_6 )
{
struct V_7 * V_8 ;
int V_25 ;
V_8 = F_209 ( sizeof( * V_8 ) , V_158 ) ;
if ( V_8 == NULL )
return - V_162 ;
V_6 -> V_377 = 1 ;
V_6 -> V_8 = V_8 ;
V_8 -> V_288 = 1 ;
V_8 -> V_97 = F_113 ( V_566 ) ;
V_8 -> V_98 = V_566 ;
V_8 -> V_379 = F_210 ( V_6 , V_567 ,
V_568 ,
V_569 ) ;
V_403:
if ( V_8 -> V_379 < 0 )
F_13 ( V_383 L_58 ,
V_6 -> V_384 ) ;
else
F_46 ( V_6 ,
V_570 [ V_8 -> V_379 ] ) ;
V_8 -> V_286 = 0x23 ;
V_8 -> V_106 = V_571 ;
V_8 -> V_124 = F_113 ( V_571 ) ;
V_8 -> V_55 = V_572 ;
V_8 -> V_242 = F_113 ( V_572 ) ;
V_8 -> V_28 = V_573 ;
V_8 -> V_79 = F_113 ( V_573 ) ;
V_8 -> V_258 = V_574 ;
V_8 -> V_256 = V_575 ;
V_8 -> V_18 = V_576 ;
V_8 -> V_76 = F_113 ( V_576 ) ;
V_8 -> V_336 = 0 ;
V_8 -> V_328 = V_577 ;
V_8 -> V_94 = V_578 ;
V_8 -> V_243 = V_579 ;
V_8 -> V_244 = V_580 ;
V_8 -> V_289 = V_581 ;
V_8 -> V_63 = 0x40 ;
V_8 -> V_68 = 0 ;
if ( V_8 -> V_379 != V_582 )
V_8 -> V_325 = 1 ;
V_8 -> V_30 . V_86 = V_8 -> V_86 ;
switch ( V_8 -> V_379 ) {
case V_583 :
F_47 ( V_6 , 0x1f , 0x01441030 ) ;
F_47 ( V_6 , 0x20 , 0x1c410030 ) ;
V_25 = F_151 ( V_6 , V_6 -> V_66 , V_355 , 0x01 ) ;
if ( V_25 < 0 )
return V_25 ;
F_15 ( V_6 , V_6 -> V_66 , 0 ,
V_496 , 0x10 ) ;
F_154 ( V_6 , V_6 -> V_66 , 0 ) ;
V_8 -> V_85 = 0x0b ;
V_8 -> V_322 = 0x01 ;
V_8 -> V_321 = 0x1b ;
V_8 -> V_324 = 0x10 ;
V_8 -> V_323 = 0x01 ;
break;
case V_584 :
break;
default:
V_8 -> V_322 = V_8 -> V_321 = V_8 -> V_85 = 0x1 ;
V_8 -> V_323 = 0x01 ;
break;
}
V_25 = F_143 ( V_6 ) ;
if ( ! V_25 ) {
if ( V_8 -> V_379 < 0 ) {
F_111 ( V_215 L_59
L_60 ) ;
V_8 -> V_379 = V_584 ;
goto V_403;
}
V_25 = - V_233 ;
}
if ( V_25 < 0 ) {
F_173 ( V_6 ) ;
return V_25 ;
}
V_6 -> V_396 = V_397 ;
V_6 -> V_447 = F_199 ;
return 0 ;
}
static int F_231 ( struct V_5 * V_6 )
{
struct V_7 * V_8 ;
int V_25 ;
V_8 = F_209 ( sizeof( * V_8 ) , V_158 ) ;
if ( V_8 == NULL )
return - V_162 ;
V_6 -> V_377 = 1 ;
V_6 -> V_8 = V_8 ;
V_8 -> V_288 = 1 ;
V_8 -> V_97 = F_113 ( V_585 ) ;
V_8 -> V_98 = V_585 ;
V_8 -> V_379 = F_210 ( V_6 , V_586 ,
V_587 ,
V_588 ) ;
if ( V_8 -> V_379 < 0 )
F_13 ( V_383 L_58 ,
V_6 -> V_384 ) ;
else
F_46 ( V_6 ,
V_589 [ V_8 -> V_379 ] ) ;
V_8 -> V_30 . V_86 = V_8 -> V_86 ;
V_8 -> V_124 = F_113 ( V_590 ) ;
V_8 -> V_106 = V_590 ;
V_8 -> V_242 = F_113 ( V_591 ) ;
V_8 -> V_55 = V_591 ;
V_8 -> V_328 = V_592 ;
V_8 -> V_243 = 1 ;
V_8 -> V_244 = V_593 ;
V_8 -> V_289 = V_594 ;
V_25 = F_143 ( V_6 ) ;
if ( V_25 < 0 ) {
F_173 ( V_6 ) ;
return - V_233 ;
}
V_8 -> V_47 = & V_8 -> V_169 ;
V_6 -> V_396 = V_397 ;
return 0 ;
}
static int T_4 F_232 ( void )
{
return F_233 ( & V_595 ) ;
}
static void T_5 F_234 ( void )
{
F_235 ( & V_595 ) ;
}
