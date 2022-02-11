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
int V_25 ;
int V_69 ;
if ( V_8 -> V_70 ) {
V_25 = F_29 ( V_6 , V_8 -> V_70 ) ;
if ( V_25 < 0 )
return V_25 ;
}
for ( V_69 = 0 ; V_69 < V_8 -> V_71 ; V_69 ++ ) {
V_25 = F_29 ( V_6 , V_8 -> V_72 [ V_69 ] ) ;
if ( V_25 < 0 )
return V_25 ;
}
if ( ! V_8 -> V_73 && V_8 -> V_74 > 0 &&
F_30 ( V_6 , L_2 ) == 1 ) {
V_75 . V_76 = V_8 -> V_74 ;
V_25 = F_31 ( V_6 , 0 ,
F_32 ( & V_75 , V_6 ) ) ;
if ( V_25 < 0 )
return V_25 ;
}
if ( V_8 -> V_77 > 0 ) {
int V_78 = F_33 ( V_6 , V_8 -> V_30 . V_31 ) ;
struct V_22 * V_23 = & V_8 -> V_24 ;
if ( V_78 & V_79 ) {
F_34 ( V_23 , L_3 , 0 , NULL ) ;
V_8 -> V_29 = 1 ;
}
V_80 . V_76 = V_8 -> V_77 ;
V_25 = F_31 ( V_6 , 0 ,
F_32 ( & V_80 , V_6 ) ) ;
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
V_8 -> V_30 . V_81 = 1 ;
}
if ( V_8 -> V_82 && ! ( V_8 -> V_83 & 0x01 ) ) {
V_25 = F_37 ( V_6 , V_8 -> V_82 ) ;
if ( V_25 < 0 )
return V_25 ;
}
if ( ! F_38 ( V_6 , L_4 ) ) {
unsigned int V_84 [ 4 ] ;
F_39 ( V_6 , V_8 -> V_30 . V_85 [ 0 ] ,
V_35 , V_84 ) ;
V_84 [ 2 ] += V_84 [ 3 ] * V_8 -> V_86 ;
V_84 [ 3 ] |= V_87 ;
V_25 = F_40 ( V_6 , L_4 ,
V_84 , V_88 ) ;
if ( V_25 < 0 )
return V_25 ;
}
if ( ! F_38 ( V_6 , L_5 ) ) {
V_25 = F_40 ( V_6 , L_5 ,
NULL , V_89 ) ;
if ( V_25 < 0 )
return V_25 ;
}
if ( V_8 -> V_90 &&
F_30 ( V_6 , L_6 ) == 1 ) {
V_25 = F_29 ( V_6 , V_8 -> V_90 ) ;
if ( V_25 < 0 )
return V_25 ;
}
F_41 ( V_6 ) ;
V_25 = F_42 ( V_6 , & V_8 -> V_91 ) ;
if ( V_25 < 0 )
return V_25 ;
return 0 ;
}
static void F_43 ( struct V_5 * V_6 ,
const unsigned int * V_92 )
{
int V_69 ;
struct V_7 * V_8 = V_6 -> V_8 ;
if ( ! V_92 )
return;
for ( V_69 = 0 ; V_69 < V_8 -> V_93 ; V_69 ++ )
if ( V_8 -> V_94 [ V_69 ] && V_92 [ V_69 ] )
F_44 ( V_6 , V_8 -> V_94 [ V_69 ] ,
V_92 [ V_69 ] ) ;
}
static int F_45 ( struct V_95 * V_96 ,
struct V_5 * V_6 ,
struct V_97 * V_98 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
if ( V_8 -> V_99 )
F_46 ( V_8 -> V_99 ) ;
return F_47 ( V_6 , & V_8 -> V_30 , V_98 ,
V_96 ) ;
}
static int F_48 ( struct V_95 * V_96 ,
struct V_5 * V_6 ,
unsigned int V_100 ,
unsigned int V_101 ,
struct V_97 * V_98 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
return F_49 ( V_6 , & V_8 -> V_30 , V_100 , V_101 , V_98 ) ;
}
static int F_50 ( struct V_95 * V_96 ,
struct V_5 * V_6 ,
struct V_97 * V_98 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
return F_51 ( V_6 , & V_8 -> V_30 ) ;
}
static int F_52 ( struct V_95 * V_96 ,
struct V_5 * V_6 ,
struct V_97 * V_98 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
return F_53 ( V_6 , & V_8 -> V_30 ) ;
}
static int F_54 ( struct V_95 * V_96 ,
struct V_5 * V_6 ,
struct V_97 * V_98 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
return F_55 ( V_6 , & V_8 -> V_30 ) ;
}
static int F_56 ( struct V_95 * V_96 ,
struct V_5 * V_6 ,
unsigned int V_100 ,
unsigned int V_101 ,
struct V_97 * V_98 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
return F_57 ( V_6 , & V_8 -> V_30 ,
V_100 , V_101 , V_98 ) ;
}
static int F_58 ( struct V_95 * V_96 ,
struct V_5 * V_6 ,
struct V_97 * V_98 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
return F_59 ( V_6 , & V_8 -> V_30 ) ;
}
static int F_60 ( struct V_95 * V_96 ,
struct V_5 * V_6 ,
unsigned int V_100 ,
unsigned int V_101 ,
struct V_97 * V_98 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
T_1 V_27 = V_8 -> V_102 [ V_98 -> V_103 ] ;
if ( V_8 -> V_104 ) {
F_46 ( 40 ) ;
F_61 ( V_6 , V_27 , 0 ,
V_105 , V_106 ) ;
}
F_62 ( V_6 , V_27 , V_100 , 0 , V_101 ) ;
return 0 ;
}
static int F_63 ( struct V_95 * V_96 ,
struct V_5 * V_6 ,
struct V_97 * V_98 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
T_1 V_27 = V_8 -> V_102 [ V_98 -> V_103 ] ;
F_64 ( V_6 , V_27 ) ;
if ( V_8 -> V_104 )
F_61 ( V_6 , V_27 , 0 ,
V_105 , V_107 ) ;
return 0 ;
}
static int F_65 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
struct V_108 * V_109 = V_8 -> V_110 ;
V_6 -> V_111 = 1 ;
V_6 -> V_112 = V_109 ;
V_109 -> V_113 = L_7 ;
V_109 -> V_114 [ V_115 ] = V_116 ;
V_109 -> V_114 [ V_115 ] . V_27 =
V_8 -> V_30 . V_85 [ 0 ] ;
V_109 -> V_114 [ V_117 ] = V_118 ;
V_109 -> V_114 [ V_117 ] . V_27 = V_8 -> V_102 [ 0 ] ;
V_109 -> V_114 [ V_117 ] . V_119 = V_8 -> V_120 ;
if ( V_8 -> V_121 ) {
V_6 -> V_111 ++ ;
V_109 ++ ;
V_109 -> V_113 = L_8 ;
V_109 -> V_114 [ V_115 ] = V_122 ;
}
if ( V_8 -> V_30 . V_31 || V_8 -> V_82 ) {
V_6 -> V_111 ++ ;
V_109 ++ ;
V_109 -> V_113 = L_9 ;
V_109 -> V_123 = V_8 -> V_91 . V_124 [ 0 ] ;
if ( V_8 -> V_30 . V_31 ) {
V_109 -> V_114 [ V_115 ] = V_125 ;
V_109 -> V_114 [ V_115 ] . V_27 = V_8 -> V_30 . V_31 ;
}
if ( V_8 -> V_82 ) {
V_109 -> V_114 [ V_117 ] = V_126 ;
V_109 -> V_114 [ V_117 ] . V_27 = V_8 -> V_82 ;
}
}
return 0 ;
}
static unsigned int F_66 ( struct V_5 * V_6 ,
T_1 V_27 )
{
unsigned int V_127 = F_67 ( V_6 , V_27 ) ;
V_127 = ( V_127 & V_128 ) >> V_129 ;
if ( V_127 & V_130 )
return V_131 ;
if ( V_127 & V_132 )
return V_133 ;
if ( V_127 & V_134 )
return V_135 ;
if ( V_127 & V_136 )
return V_137 ;
return 0 ;
}
static void F_68 ( struct V_5 * V_6 , T_1 V_27 , int V_138 )
{
F_15 ( V_6 , V_27 , 0 ,
V_41 , V_138 ) ;
}
static int F_69 ( struct V_1 * V_2 ,
struct V_10 * V_11 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = V_6 -> V_8 ;
V_11 -> V_14 . integer . V_14 [ 0 ] = ! ! V_8 -> V_139 ;
return 0 ;
}
static int F_70 ( struct V_1 * V_2 ,
struct V_10 * V_11 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = V_6 -> V_8 ;
int V_27 = V_2 -> V_67 ;
V_8 -> V_139 = V_11 -> V_14 . integer . V_14 [ 0 ] ? V_27 : 0 ;
F_71 ( V_6 , V_27 ) ;
return 1 ;
}
static int F_72 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
int V_69 ;
static const char * const V_140 [] = {
L_10 , L_11 , L_12
} ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = V_6 -> V_8 ;
T_1 V_27 = V_2 -> V_67 ;
if ( V_27 == V_8 -> V_141 || V_27 == V_8 -> V_142 )
V_69 = 3 ;
else
V_69 = 2 ;
V_4 -> type = V_143 ;
V_4 -> V_14 . V_15 . V_57 = V_69 ;
V_4 -> V_76 = 1 ;
if ( V_4 -> V_14 . V_15 . V_16 >= V_69 )
V_4 -> V_14 . V_15 . V_16 = V_69 - 1 ;
strcpy ( V_4 -> V_14 . V_15 . V_113 ,
V_140 [ V_4 -> V_14 . V_15 . V_16 ] ) ;
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
else if ( V_46 == V_137 )
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
V_36 = V_137 ;
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
char * V_140 [ 2 ] ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = V_6 -> V_8 ;
if ( V_2 -> V_67 == V_8 -> V_142 )
V_140 [ 0 ] = L_11 ;
else
V_140 [ 0 ] = L_10 ;
V_140 [ 1 ] = L_12 ;
V_4 -> type = V_143 ;
V_4 -> V_14 . V_15 . V_57 = 2 ;
V_4 -> V_76 = 1 ;
if ( V_4 -> V_14 . V_15 . V_16 >= 2 )
V_4 -> V_14 . V_15 . V_16 = 1 ;
strcpy ( V_4 -> V_14 . V_15 . V_113 ,
V_140 [ V_4 -> V_14 . V_15 . V_16 ] ) ;
return 0 ;
}
static int F_76 ( struct V_1 * V_2 , struct V_10 * V_11 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = V_6 -> V_8 ;
T_1 V_27 = V_2 -> V_67 ;
int V_144 = ( V_27 == V_8 -> V_141 ) ? 1 : 0 ;
V_11 -> V_14 . V_15 . V_16 [ 0 ] = V_8 -> V_145 [ V_144 ] ;
return 0 ;
}
static int F_77 ( struct V_1 * V_2 , struct V_10 * V_11 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = V_6 -> V_8 ;
T_1 V_27 = V_2 -> V_67 ;
int V_144 = ( V_27 == V_8 -> V_141 ) ? 1 : 0 ;
unsigned short V_26 = ! ! V_11 -> V_14 . V_15 . V_16 [ 0 ] ;
V_8 -> V_145 [ V_144 ] = V_26 ;
if ( V_26 )
F_68 ( V_6 , V_27 , V_44 ) ;
else {
unsigned int V_37 = V_43 ;
if ( V_144 )
V_37 |= F_66 ( V_6 , V_27 ) ;
F_68 ( V_6 , V_27 , V_37 ) ;
}
if ( V_8 -> V_146 )
F_71 ( V_6 , V_27 ) ;
return 1 ;
}
static int F_78 ( struct V_1 * V_2 ,
struct V_10 * V_11 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = V_6 -> V_8 ;
V_11 -> V_14 . integer . V_14 [ 0 ] = V_8 -> V_147 ;
return 0 ;
}
static int F_79 ( struct V_1 * V_2 ,
struct V_10 * V_11 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = V_6 -> V_8 ;
T_1 V_27 = V_2 -> V_67 & 0xff ;
unsigned int V_26 = ! ! V_11 -> V_14 . integer . V_14 [ 0 ] ;
if ( V_8 -> V_147 == V_26 )
return 0 ;
V_8 -> V_147 = V_26 ;
F_15 ( V_6 , V_27 , 0 , V_148 ,
V_8 -> V_147 ? 0x4 : 0x0 ) ;
return 1 ;
}
static struct V_149 *
F_80 ( struct V_7 * V_8 ,
const struct V_149 * V_150 ,
const char * V_113 ,
unsigned int V_151 )
{
struct V_149 * V_152 ;
F_81 ( & V_8 -> V_153 , sizeof( * V_152 ) , 32 ) ;
V_152 = F_82 ( & V_8 -> V_153 ) ;
if ( ! V_152 )
return NULL ;
* V_152 = * V_150 ;
V_152 -> V_113 = F_83 ( V_113 , V_154 ) ;
if ( ! V_152 -> V_113 ) {
memset ( V_152 , 0 , sizeof( * V_152 ) ) ;
V_8 -> V_153 . V_155 -- ;
return NULL ;
}
V_152 -> V_156 = V_151 ;
return V_152 ;
}
static int F_84 ( struct V_7 * V_8 ,
const struct V_149 * V_150 ,
int V_51 , const char * V_113 ,
unsigned long V_26 )
{
struct V_149 * V_152 = F_80 ( V_8 , V_150 , V_113 ,
V_157 ) ;
if ( ! V_152 )
return - V_158 ;
V_152 -> V_58 = V_51 ;
V_152 -> V_67 = V_26 ;
return 0 ;
}
static inline int F_85 ( struct V_7 * V_8 ,
int type , int V_51 , const char * V_113 ,
unsigned long V_26 )
{
return F_84 ( V_8 ,
& V_159 [ type ] ,
V_51 , V_113 , V_26 ) ;
}
static inline int F_86 ( struct V_7 * V_8 , int type ,
const char * V_113 , unsigned long V_26 )
{
return F_85 ( V_8 , type , 0 , V_113 , V_26 ) ;
}
static inline int F_87 ( struct V_5 * V_6 ,
T_1 V_27 , int V_51 )
{
int V_160 = F_88 ( V_6 , V_27 ) ;
int V_161 = 0 ;
struct V_7 * V_8 = V_6 -> V_8 ;
char V_113 [ 22 ] ;
if ( F_89 ( V_160 ) != V_162 ) {
if ( F_66 ( V_6 , V_27 ) == V_137
&& V_27 == V_8 -> V_142 )
V_161 = V_163 ;
else if ( F_67 ( V_6 , V_27 )
& ( V_136 << V_129 ) )
V_161 = V_164 ;
else if ( V_27 == V_8 -> V_141 )
V_161 = V_163 ;
}
if ( V_161 ) {
F_90 ( V_6 , V_27 , & V_8 -> V_91 ,
V_113 , sizeof( V_113 ) , NULL ) ;
return F_86 ( V_6 -> V_8 , V_161 ,
strcat ( V_113 , L_13 ) , V_27 ) ;
}
return 0 ;
}
static int F_91 ( struct V_7 * V_8 )
{
struct V_149 * V_152 ;
struct V_22 * V_50 = & V_8 -> V_165 ;
if ( V_8 -> V_73 )
return 0 ;
if ( ! V_8 -> V_120 || V_50 -> V_33 <= 1 )
return 0 ;
V_152 = F_80 ( V_8 , & V_166 ,
V_166 . V_113 , 0 ) ;
if ( ! V_152 )
return - V_158 ;
V_152 -> V_76 = V_8 -> V_120 ;
return 0 ;
}
static T_1 F_92 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
struct V_167 * V_168 = & V_8 -> V_91 ;
T_1 V_27 ;
unsigned int V_127 ;
int V_69 ;
if ( V_168 -> V_169 != V_170 )
return 0 ;
for ( V_69 = 0 ; V_69 < V_168 -> V_171 ; V_69 ++ ) {
if ( V_168 -> V_172 [ V_69 ] . type == V_173 ) {
V_27 = V_168 -> V_172 [ V_69 ] . V_174 ;
V_127 = F_67 ( V_6 , V_27 ) ;
if ( V_127 & V_175 )
return V_27 ;
}
}
return 0 ;
}
static T_1 F_93 ( struct V_5 * V_6 , T_1 * V_176 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
struct V_167 * V_168 = & V_8 -> V_91 ;
unsigned int V_160 , V_127 ;
int V_69 ;
* V_176 = 0 ;
if ( V_168 -> V_169 != V_170 )
return 0 ;
for ( V_69 = 0 ; V_69 < V_168 -> V_171 ; V_69 ++ ) {
T_1 V_27 = V_168 -> V_172 [ V_69 ] . V_174 ;
if ( V_168 -> V_172 [ V_69 ] . type != V_177 )
continue;
V_160 = F_88 ( V_6 , V_27 ) ;
if ( F_89 ( V_160 ) != V_162 ) {
V_127 = F_67 ( V_6 , V_27 ) ;
if ( V_127 & V_175 ) {
* V_176 = F_94 ( V_6 , V_27 ) ;
if ( * V_176 )
return V_27 ;
}
}
}
return 0 ;
}
static int F_95 ( struct V_7 * V_8 , T_1 V_27 )
{
int V_69 ;
for ( V_69 = 0 ; V_69 < V_8 -> V_30 . V_178 ; V_69 ++ ) {
if ( V_8 -> V_30 . V_85 [ V_69 ] == V_27 )
return 1 ;
}
return 0 ;
}
static int F_96 ( struct V_7 * V_8 , T_1 V_27 )
{
int V_69 ;
if ( F_95 ( V_8 , V_27 ) )
return 1 ;
for ( V_69 = 0 ; V_69 < V_8 -> V_91 . V_179 ; V_69 ++ )
if ( V_8 -> V_180 [ V_69 ] == V_27 )
return 1 ;
for ( V_69 = 0 ; V_69 < V_8 -> V_91 . V_181 ; V_69 ++ )
if ( V_8 -> V_182 [ V_69 ] == V_27 )
return 1 ;
return 0 ;
}
static T_1 F_94 ( struct V_5 * V_6 , T_1 V_27 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
struct V_167 * V_168 = & V_8 -> V_91 ;
int V_183 , V_184 ;
T_1 V_185 [ V_186 ] , V_187 ;
unsigned int V_78 , V_188 ;
V_184 = F_97 ( V_6 , V_27 , V_185 ,
V_186 ) ;
while ( V_184 == 1 && ( F_98 ( F_33 ( V_6 , V_185 [ 0 ] ) )
!= V_189 ) ) {
V_27 = V_185 [ 0 ] ;
V_184 = F_97 ( V_6 , V_27 , V_185 ,
V_186 ) ;
}
for ( V_183 = 0 ; V_183 < V_184 ; V_183 ++ ) {
V_78 = F_33 ( V_6 , V_185 [ V_183 ] ) ;
V_188 = F_98 ( V_78 ) ;
if ( V_188 != V_189 || ( V_78 & V_190 ) )
continue;
if ( ! F_96 ( V_8 , V_185 [ V_183 ] ) ) {
if ( V_184 > 1 ) {
F_15 ( V_6 , V_27 , 0 ,
V_56 , V_183 ) ;
}
return V_185 [ V_183 ] ;
}
}
V_187 = V_8 -> V_30 . V_85 [ 0 ] ;
if ( V_8 -> V_30 . V_191 ) {
for ( V_183 = 0 ; V_183 < V_168 -> V_179 ; V_183 ++ )
if ( V_168 -> V_192 [ V_183 ] == V_27 ) {
V_187 = V_8 -> V_30 . V_191 ;
break;
}
}
if ( V_184 > 1 ) {
for ( V_183 = 0 ; V_183 < V_184 ; V_183 ++ ) {
if ( V_185 [ V_183 ] == V_187 ) {
F_15 ( V_6 , V_27 , 0 ,
V_56 , V_183 ) ;
break;
}
}
}
return 0 ;
}
static int F_99 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
struct V_167 * V_168 = & V_8 -> V_91 ;
int V_69 ;
T_1 V_27 , V_176 ;
for ( V_69 = 0 ; V_69 < V_168 -> V_193 ; V_69 ++ ) {
V_27 = V_168 -> V_194 [ V_69 ] ;
V_176 = F_94 ( V_6 , V_27 ) ;
if ( ! V_176 ) {
if ( V_8 -> V_30 . V_178 > 0 ) {
V_168 -> V_193 = V_8 -> V_30 . V_178 ;
break;
}
F_100 ( V_195
L_14 ,
V_38 , V_27 ) ;
return - V_196 ;
}
F_101 ( V_8 , V_176 ) ;
}
for ( V_69 = 0 ; V_69 < V_168 -> V_179 ; V_69 ++ ) {
V_27 = V_168 -> V_192 [ V_69 ] ;
V_176 = F_94 ( V_6 , V_27 ) ;
if ( V_176 ) {
if ( ! V_8 -> V_30 . V_191 )
V_8 -> V_30 . V_191 = V_176 ;
else
F_102 ( V_8 , V_176 ) ;
}
V_8 -> V_180 [ V_69 ] = V_176 ;
}
for ( V_69 = 0 ; V_69 < V_168 -> V_181 ; V_69 ++ ) {
V_27 = V_168 -> V_197 [ V_69 ] ;
V_176 = F_94 ( V_6 , V_27 ) ;
if ( V_176 )
F_102 ( V_8 , V_176 ) ;
V_8 -> V_182 [ V_69 ] = V_176 ;
}
V_27 = F_92 ( V_6 ) ;
if ( V_27 ) {
V_176 = F_94 ( V_6 , V_27 ) ;
if ( V_176 ) {
F_13 ( L_15 ,
V_27 , V_168 -> V_193 ) ;
V_168 -> V_194 [ V_168 -> V_193 ] = V_27 ;
V_168 -> V_193 ++ ;
V_8 -> V_142 = V_27 ;
F_101 ( V_8 , V_176 ) ;
}
}
V_27 = F_93 ( V_6 , & V_176 ) ;
if ( V_27 && V_176 ) {
F_13 ( L_16 ,
V_27 , V_168 -> V_193 ) ;
V_168 -> V_194 [ V_168 -> V_193 ] = V_27 ;
V_168 -> V_193 ++ ;
V_8 -> V_141 = V_27 ;
F_101 ( V_8 , V_176 ) ;
}
F_103 ( L_17 ,
V_8 -> V_30 . V_178 ,
V_8 -> V_30 . V_85 [ 0 ] ,
V_8 -> V_30 . V_85 [ 1 ] ,
V_8 -> V_30 . V_85 [ 2 ] ,
V_8 -> V_30 . V_85 [ 3 ] ,
V_8 -> V_30 . V_85 [ 4 ] ) ;
return 0 ;
}
static int F_104 ( struct V_5 * V_6 , const char * V_198 ,
int V_51 , T_1 V_27 , int V_199 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
char V_113 [ 32 ] ;
int V_25 ;
if ( ! V_8 -> V_200 ) {
unsigned int V_201 , V_202 , V_203 , V_204 ;
V_201 = F_105 ( V_6 , V_27 , V_35 ) ;
V_202 = ( V_201 & V_205 ) >>
V_206 ;
V_202 = ( V_202 + 1 ) * 25 ;
V_203 = ( V_201 & V_207 ) >>
V_208 ;
V_204 = V_203 * V_202 ;
if ( V_204 > 6400 && V_203 >= 0x1f )
V_8 -> V_86 = V_203 / 2 ;
V_8 -> V_200 = 1 ;
}
sprintf ( V_113 , L_18 , V_198 ) ;
V_25 = F_85 ( V_8 , V_209 , V_51 , V_113 ,
F_106 ( V_27 , V_199 , 0 , V_35 ,
V_8 -> V_86 ) ) ;
if ( V_25 < 0 )
return V_25 ;
sprintf ( V_113 , L_19 , V_198 ) ;
V_25 = F_85 ( V_8 , V_210 , V_51 , V_113 ,
F_107 ( V_27 , V_199 , 0 , V_35 ) ) ;
if ( V_25 < 0 )
return V_25 ;
return 0 ;
}
static int F_101 ( struct V_7 * V_8 , T_1 V_27 )
{
if ( V_8 -> V_30 . V_178 > 4 ) {
F_108 ( V_211 L_20 , V_27 ) ;
return 1 ;
} else {
F_109 ( V_8 -> V_30 . V_85 != V_8 -> V_85 ) ;
V_8 -> V_85 [ V_8 -> V_30 . V_178 ] = V_27 ;
V_8 -> V_30 . V_178 ++ ;
}
return 0 ;
}
static int F_102 ( struct V_7 * V_8 , T_1 V_27 )
{
int V_69 ;
for ( V_69 = 0 ; V_69 < F_110 ( V_8 -> V_30 . V_212 ) ; V_69 ++ ) {
if ( ! V_8 -> V_30 . V_212 [ V_69 ] ) {
V_8 -> V_30 . V_212 [ V_69 ] = V_27 ;
return 0 ;
}
}
F_108 ( V_211 L_21 , V_27 ) ;
return 1 ;
}
static int F_111 ( struct V_5 * V_6 , int V_213 ,
const T_1 * V_214 ,
const T_1 * V_85 ,
int type )
{
struct V_7 * V_8 = V_6 -> V_8 ;
static const char * const V_215 [ 4 ] = {
L_22 , L_23 , NULL , L_24
} ;
T_1 V_27 ;
int V_69 , V_25 ;
unsigned int V_216 ;
for ( V_69 = 0 ; V_69 < V_213 && V_69 < F_110 ( V_215 ) ; V_69 ++ ) {
if ( type == V_217 && ! V_8 -> V_146 ) {
if ( F_112 ( V_6 , V_214 [ V_69 ] ) )
V_8 -> V_146 = 1 ;
}
V_27 = V_85 [ V_69 ] ;
if ( ! V_27 )
continue;
if ( type != V_217 && V_69 == 2 ) {
V_25 = F_113 ( V_6 , L_25 , V_27 , 1 ) ;
if ( V_25 < 0 )
return V_25 ;
V_25 = F_113 ( V_6 , L_26 , V_27 , 2 ) ;
if ( V_25 < 0 )
return V_25 ;
V_216 = F_33 ( V_6 , V_27 ) ;
if ( V_216 & V_218 ) {
V_25 = F_86 ( V_8 ,
V_219 ,
L_27 , V_27 ) ;
if ( V_25 < 0 )
return V_25 ;
}
} else {
const char * V_113 ;
int V_51 ;
switch ( type ) {
case V_217 :
V_113 = L_28 ;
V_51 = V_69 ;
break;
case V_220 :
V_113 = L_29 ;
V_51 = V_69 ;
break;
default:
V_113 = V_215 [ V_69 ] ;
V_51 = 0 ;
break;
}
V_25 = F_104 ( V_6 , V_113 , V_51 , V_27 , 3 ) ;
if ( V_25 < 0 )
return V_25 ;
}
}
return 0 ;
}
static int F_114 ( struct V_5 * V_6 , unsigned long V_221 ,
unsigned long V_222 , int V_51 )
{
int V_25 ;
V_25 = F_85 ( V_6 -> V_8 , V_209 , V_51 ,
L_30 , V_221 ) ;
if ( V_25 < 0 )
return V_25 ;
V_25 = F_85 ( V_6 -> V_8 , V_210 , V_51 ,
L_31 , V_222 ) ;
if ( V_25 < 0 )
return V_25 ;
return 0 ;
}
static int F_115 ( struct V_5 * V_6 ,
const struct V_167 * V_168 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
T_1 V_27 ;
int V_25 ;
int V_51 ;
V_25 = F_111 ( V_6 , V_168 -> V_193 , V_168 -> V_194 ,
V_8 -> V_30 . V_85 ,
V_168 -> V_169 ) ;
if ( V_25 < 0 )
return V_25 ;
if ( V_168 -> V_179 > 1 && V_168 -> V_169 == V_170 ) {
V_25 = F_86 ( V_8 ,
V_223 ,
L_32 ,
V_168 -> V_192 [ V_168 -> V_179 - 1 ] ) ;
if ( V_25 < 0 )
return V_25 ;
}
for ( V_51 = 0 ; V_51 < V_168 -> V_171 ; V_51 ++ ) {
if ( V_168 -> V_172 [ V_51 ] . type > V_173 )
break;
V_27 = V_168 -> V_172 [ V_51 ] . V_174 ;
V_25 = F_87 ( V_6 , V_27 , V_51 ) ;
if ( V_25 < 0 )
return V_25 ;
}
return 0 ;
}
static int F_116 ( struct V_5 * V_6 ,
struct V_167 * V_168 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
int V_25 ;
V_25 = F_111 ( V_6 , V_168 -> V_179 , V_168 -> V_192 ,
V_8 -> V_180 , V_217 ) ;
if ( V_25 < 0 )
return V_25 ;
V_25 = F_111 ( V_6 , V_168 -> V_181 , V_168 -> V_197 ,
V_8 -> V_182 , V_220 ) ;
if ( V_25 < 0 )
return V_25 ;
return 0 ;
}
static int F_117 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
struct V_22 * V_59 = & V_8 -> V_224 ;
int V_69 , V_225 ;
T_1 V_226 [ F_110 ( V_227 ) ] ;
V_225 = F_97 ( V_6 ,
V_8 -> V_61 ,
V_226 ,
V_228 ) ;
if ( V_225 <= 0 || V_225 > F_110 ( V_227 ) )
return - V_229 ;
for ( V_69 = 0 ; V_69 < V_225 ; V_69 ++ )
F_34 ( V_59 , V_227 [ V_69 ] , V_69 ,
NULL ) ;
return F_86 ( V_8 , V_230 ,
L_33 , V_8 -> V_61 ) ;
}
static int F_118 ( struct V_5 * V_6 ,
T_1 V_27 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
T_2 V_201 = F_105 ( V_6 , V_27 , V_35 ) ;
int V_25 , type = V_231 ;
if ( V_8 -> V_232 == V_27 )
type = V_210 ;
if ( ( V_201 & V_233 ) >> V_234 ) {
V_25 = F_86 ( V_8 , type ,
L_34 ,
F_107 ( V_27 , 1 , 0 , V_35 ) ) ;
if ( V_25 < 0 )
return V_25 ;
}
if ( ( V_201 & V_207 ) >> V_208 ) {
V_25 = F_86 ( V_8 , V_209 ,
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
V_11 -> V_14 . integer . V_14 [ 0 ] = V_6 -> V_235 -> V_236 ;
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
return F_84 ( V_6 -> V_8 , & V_237 ,
0 , L_34 , 0 ) ;
}
static int F_123 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
int V_69 , V_183 , V_25 = 0 ;
for ( V_69 = 0 ; V_69 < V_8 -> V_238 ; V_69 ++ ) {
T_1 V_27 ;
unsigned int V_78 ;
unsigned long V_26 ;
V_27 = V_8 -> V_55 [ V_69 ] ;
V_78 = F_33 ( V_6 , V_27 ) ;
if ( ! ( V_78 & V_79 ) )
continue;
V_26 = F_107 ( V_27 , 3 , 0 , V_35 ) ;
for ( V_183 = 0 ; V_183 < V_8 -> V_239 ; V_183 ++ ) {
if ( V_8 -> V_240 [ V_183 ] == V_26 )
break;
}
if ( V_183 < V_8 -> V_239 )
continue;
V_25 = F_85 ( V_8 , V_209 , V_69 ,
L_36 , V_26 ) ;
if ( V_25 < 0 )
return V_25 ;
}
return 0 ;
}
static int F_124 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
struct V_22 * V_241 = & V_8 -> V_24 ;
const char * const * V_242 = V_8 -> V_243 ;
int V_69 , V_225 ;
T_1 V_226 [ V_228 ] ;
V_225 = F_97 ( V_6 ,
V_8 -> V_28 [ 0 ] ,
V_226 ,
V_228 ) ;
if ( V_225 <= 0 )
return - V_229 ;
if ( ! V_242 )
V_242 = V_244 ;
for ( V_69 = 0 ; V_69 < V_225 ; V_69 ++ )
F_34 ( V_241 , V_242 [ V_69 ] , V_69 , NULL ) ;
return 0 ;
}
static T_1 F_125 ( struct V_5 * V_6 , T_1 V_245 ,
int V_51 )
{
T_1 V_185 [ V_228 ] ;
int V_203 ;
V_203 = F_97 ( V_6 , V_245 , V_185 , F_110 ( V_185 ) ) ;
if ( V_51 >= 0 && V_51 < V_203 )
return V_185 [ V_51 ] ;
return 0 ;
}
static int F_126 ( struct V_5 * V_6 , T_1 V_27 ,
const char * V_246 , int V_51 , int V_247 )
{
unsigned int V_201 , V_203 ;
char V_113 [ 32 ] ;
int V_25 ;
if ( V_247 == V_35 )
V_201 = V_79 ;
else
V_201 = V_248 ;
if ( ! ( F_33 ( V_6 , V_27 ) & V_201 ) )
return 0 ;
V_201 = F_105 ( V_6 , V_27 , V_247 ) ;
V_203 = ( V_201 & V_207 ) >> V_208 ;
if ( ! V_203 )
return 0 ;
snprintf ( V_113 , sizeof( V_113 ) , L_37 , V_246 ) ;
V_25 = F_85 ( V_6 -> V_8 , V_209 , V_51 , V_113 ,
F_107 ( V_27 , 3 , 0 , V_247 ) ) ;
if ( V_25 < 0 )
return V_25 ;
return 1 ;
}
static int F_127 ( struct V_5 * V_6 ,
const struct V_167 * V_168 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
struct V_22 * V_50 = & V_8 -> V_165 ;
struct V_22 * V_249 = & V_8 -> V_250 ;
int V_25 , V_69 ;
unsigned int V_160 ;
F_34 ( V_249 , V_251 [ 0 ] , 0 , NULL ) ;
for ( V_69 = 0 ; V_69 < V_8 -> V_252 ; V_69 ++ ) {
T_1 V_27 ;
int V_58 , V_253 ;
char V_246 [ 32 ] ;
V_27 = V_8 -> V_254 [ V_69 ] ;
if ( F_98 ( F_33 ( V_6 , V_27 ) ) != V_255 )
continue;
V_160 = F_88 ( V_6 , V_27 ) ;
if ( F_128 ( V_160 ) == V_256 )
continue;
V_58 = F_129 ( V_6 , V_8 -> V_18 [ 0 ] , V_27 ) ;
if ( V_58 < 0 )
continue;
F_90 ( V_6 , V_27 , & V_8 -> V_91 ,
V_246 , sizeof( V_246 ) , NULL ) ;
F_34 ( V_249 , V_246 , V_58 , & V_253 ) ;
if ( F_30 ( V_6 , L_2 ) != 1 )
F_34 ( V_50 , V_246 , V_58 , & V_253 ) ;
V_25 = F_126 ( V_6 , V_27 , V_246 , V_253 ,
V_257 ) ;
if ( V_25 < 0 )
return V_25 ;
if ( ! V_25 ) {
V_25 = F_126 ( V_6 , V_27 , V_246 ,
V_253 , V_35 ) ;
if ( V_25 < 0 )
return V_25 ;
if ( ! V_25 ) {
V_27 = F_125 ( V_6 ,
V_8 -> V_18 [ 0 ] , V_58 ) ;
if ( V_27 )
V_25 = F_126 ( V_6 ,
V_27 , V_246 ,
V_253 , V_257 ) ;
if ( V_25 < 0 )
return V_25 ;
}
}
}
return 0 ;
}
static int F_130 ( struct V_5 * V_6 , T_1 V_27 ,
T_1 * V_258 , T_1 * V_259 , T_1 * V_260 )
{
unsigned int V_168 ;
unsigned int type ;
if ( ! V_27 )
return 0 ;
V_168 = F_88 ( V_6 , V_27 ) ;
type = F_131 ( V_168 ) ;
switch ( F_89 ( V_168 ) ) {
case V_162 :
if ( * V_258 )
return 1 ;
if ( type != V_261 )
return 1 ;
* V_258 = V_27 ;
break;
case V_262 :
break;
case V_263 :
if ( * V_260 )
return 1 ;
if ( type != V_261 && type != V_264 )
return 1 ;
* V_260 = V_27 ;
break;
default:
if ( * V_259 )
return 1 ;
if ( type != V_261 )
return 1 ;
* V_259 = V_27 ;
break;
}
return 0 ;
}
static int F_132 ( struct V_5 * V_6 ,
struct V_265 * V_266 ,
T_1 V_174 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
struct V_167 * V_168 = & V_8 -> V_91 ;
int V_69 ;
V_266 -> V_174 = V_174 ;
if ( V_174 == 0 )
return 0 ;
for ( V_69 = 0 ; V_69 < V_168 -> V_171 ; V_69 ++ ) {
if ( V_174 == V_168 -> V_172 [ V_69 ] . V_174 )
break;
}
if ( V_69 < V_168 -> V_171 && V_168 -> V_172 [ V_69 ] . type == V_177 ) {
V_69 = F_129 ( V_6 , V_8 -> V_55 [ 0 ] , V_174 ) ;
if ( V_69 < 0 )
return - 1 ;
V_266 -> V_267 = V_69 ;
V_266 -> V_12 = - 1 ;
if ( V_8 -> V_18 )
V_266 -> V_12 = F_129 ( V_6 ,
V_8 -> V_18 [ 0 ] ,
V_8 -> V_55 [ 0 ] ) ;
} else if ( V_8 -> V_18 ) {
V_69 = F_129 ( V_6 , V_8 -> V_18 [ 0 ] , V_174 ) ;
if ( V_69 < 0 )
return - 1 ;
V_266 -> V_12 = V_69 ;
V_266 -> V_267 = - 1 ;
if ( V_8 -> V_55 )
V_266 -> V_267 = F_129 ( V_6 ,
V_8 -> V_55 [ 0 ] ,
V_8 -> V_18 [ 0 ] ) ;
}
return 0 ;
}
static int F_133 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
struct V_167 * V_168 = & V_8 -> V_91 ;
T_1 V_258 , V_259 , V_260 ;
int V_69 ;
V_258 = V_259 = V_260 = 0 ;
for ( V_69 = 0 ; V_69 < V_168 -> V_171 ; V_69 ++ )
if ( F_130 ( V_6 , V_168 -> V_172 [ V_69 ] . V_174 ,
& V_258 , & V_259 , & V_260 ) )
return 0 ;
for ( V_69 = 0 ; V_69 < V_8 -> V_252 ; V_69 ++ )
if ( F_130 ( V_6 , V_8 -> V_254 [ V_69 ] ,
& V_258 , & V_259 , & V_260 ) )
return 0 ;
if ( ! V_258 || ( ! V_259 && ! V_260 ) )
return 0 ;
if ( ! F_112 ( V_6 , V_259 ) )
return 0 ;
if ( F_132 ( V_6 , & V_8 -> V_268 , V_259 ) ||
F_132 ( V_6 , & V_8 -> V_269 , V_258 ) ||
F_132 ( V_6 , & V_8 -> V_270 , V_260 ) )
return 0 ;
return 1 ;
}
static int F_134 ( struct V_5 * V_6 , const struct V_167 * V_168 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
struct V_22 * V_50 = & V_8 -> V_165 ;
int V_69 , V_183 ;
const char * V_246 ;
for ( V_69 = 0 ; V_69 < V_168 -> V_171 ; V_69 ++ ) {
T_1 V_27 = V_168 -> V_172 [ V_69 ] . V_174 ;
int V_58 , V_25 , V_253 ;
V_58 = - 1 ;
for ( V_183 = 0 ; V_183 < V_8 -> V_238 ; V_183 ++ ) {
V_58 = F_129 ( V_6 , V_8 -> V_55 [ V_183 ] ,
V_27 ) ;
if ( V_58 >= 0 )
break;
}
if ( V_58 < 0 )
continue;
V_246 = F_135 ( V_6 , V_168 , V_69 ) ;
F_34 ( V_50 , V_246 , V_58 , & V_253 ) ;
V_25 = F_126 ( V_6 , V_27 ,
V_246 , V_253 ,
V_257 ) ;
if ( V_25 < 0 )
return V_25 ;
}
V_8 -> V_54 = V_50 -> V_33 ;
if ( V_50 -> V_33 ) {
for ( V_69 = 0 ; V_69 < V_8 -> V_238 ; V_69 ++ ) {
F_15 ( V_6 , V_8 -> V_55 [ V_69 ] , 0 ,
V_56 ,
V_50 -> V_57 [ 0 ] . V_58 ) ;
}
}
return 0 ;
}
static void F_136 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
int V_69 ;
for ( V_69 = 0 ; V_69 < V_8 -> V_91 . V_193 ; V_69 ++ ) {
T_1 V_27 = V_8 -> V_91 . V_194 [ V_69 ] ;
F_68 ( V_6 , V_27 , V_44 ) ;
}
}
static void F_137 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
int V_69 ;
for ( V_69 = 0 ; V_69 < V_8 -> V_91 . V_179 ; V_69 ++ ) {
T_1 V_174 ;
V_174 = V_8 -> V_91 . V_192 [ V_69 ] ;
if ( V_174 )
F_68 ( V_6 , V_174 , V_44 | V_271 ) ;
}
for ( V_69 = 0 ; V_69 < V_8 -> V_91 . V_181 ; V_69 ++ ) {
T_1 V_174 ;
V_174 = V_8 -> V_91 . V_197 [ V_69 ] ;
if ( V_174 )
F_68 ( V_6 , V_174 , V_44 ) ;
}
}
static int F_138 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
int V_69 , V_272 ;
if ( V_8 -> V_91 . V_169 != V_220 ||
V_8 -> V_91 . V_179 <= 1 )
return 0 ;
V_272 = 0 ;
for ( V_69 = 0 ; V_69 < V_8 -> V_91 . V_179 ; V_69 ++ ) {
T_1 V_27 = V_8 -> V_91 . V_192 [ V_69 ] ;
unsigned int V_168 = F_88 ( V_6 , V_27 ) ;
if ( F_139 ( V_168 ) & V_273 )
continue;
V_272 ++ ;
}
return ( V_272 > 1 ) ;
}
static int F_140 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
T_1 V_274 = 0 , V_275 = 0 ;
int V_276 = 0 ;
int V_69 , V_25 ;
if ( ( V_25 = F_141 ( V_6 ,
& V_8 -> V_91 ,
V_8 -> V_254 ) ) < 0 )
return V_25 ;
if ( ! V_8 -> V_91 . V_193 )
return 0 ;
if ( F_138 ( V_6 ) ) {
F_13 ( L_38 ) ;
memcpy ( V_8 -> V_91 . V_197 , V_8 -> V_91 . V_194 ,
sizeof( V_8 -> V_91 . V_194 ) ) ;
V_8 -> V_91 . V_181 = V_8 -> V_91 . V_193 ;
memcpy ( V_8 -> V_91 . V_194 , V_8 -> V_91 . V_192 ,
sizeof( V_8 -> V_91 . V_192 ) ) ;
V_8 -> V_91 . V_193 = V_8 -> V_91 . V_179 ;
V_8 -> V_91 . V_169 = V_217 ;
V_8 -> V_91 . V_179 = 0 ;
V_276 = 1 ;
}
if ( V_8 -> V_91 . V_277 ) {
int V_278 = F_33 ( V_6 , V_8 -> V_91 . V_277 ) &
( V_79 | V_248 ) ;
T_2 V_201 = F_105 ( V_6 ,
V_8 -> V_91 . V_277 , V_278 ) ;
T_1 V_279 [ 1 ] ;
if ( F_97 ( V_6 ,
V_8 -> V_91 . V_277 , V_279 , 1 ) &&
F_97 ( V_6 , V_279 [ 0 ] ,
V_279 , 1 ) > 0 ) {
int V_78 = F_33 ( V_6 , V_279 [ 0 ] ) ;
int V_280 = F_98 ( V_78 ) ;
if ( V_280 == V_281 &&
! ( V_78 & V_218 ) )
V_8 -> V_61 = V_279 [ 0 ] ;
}
if ( V_278 ) {
T_1 V_27 = V_8 -> V_91 . V_277 ;
V_278 = ( V_278 & V_79 ) ? V_35 : V_257 ;
V_25 = F_86 ( V_8 , V_210 ,
L_39 ,
F_107 ( V_27 , 1 , 0 , V_278 ) ) ;
if ( V_25 < 0 )
return V_25 ;
if ( ( V_201 & V_207 )
>> V_208 ) {
V_25 = F_86 ( V_8 ,
V_209 ,
L_40 ,
F_107 ( V_27 , 1 , 0 , V_278 ) ) ;
if ( V_25 < 0 )
return V_25 ;
}
}
F_68 ( V_6 , V_8 -> V_91 . V_277 ,
V_44 ) ;
}
if ( ! V_8 -> V_30 . V_178 ) {
V_25 = F_99 ( V_6 ) ;
if ( V_25 < 0 )
return V_25 ;
V_25 = F_115 ( V_6 ,
& V_8 -> V_91 ) ;
if ( V_25 < 0 )
return V_25 ;
}
if ( V_8 -> V_232 > 0 ) {
V_25 = F_118 ( V_6 ,
V_8 -> V_232 ) ;
if ( V_25 < 0 )
return V_25 ;
}
#ifdef F_142
if ( V_8 -> V_282 > 0 ) {
T_1 V_27 = V_8 -> V_282 ;
unsigned int V_201 ;
V_25 = F_118 ( V_6 , V_27 ) ;
if ( V_25 < 0 )
return V_25 ;
V_25 = F_143 ( V_6 , V_27 ) ;
if ( V_25 < 0 )
return V_25 ;
if ( V_6 -> V_235 ) {
V_6 -> V_235 -> V_283 = V_8 -> V_284 ;
V_201 = F_105 ( V_6 , V_27 , V_35 ) ;
if ( ! ( V_201 & V_233 ) ) {
V_25 = F_122 ( V_6 ) ;
if ( V_25 < 0 )
return V_25 ;
}
}
}
#endif
V_25 = F_116 ( V_6 , & V_8 -> V_91 ) ;
if ( V_25 < 0 )
return V_25 ;
if ( V_276 ) {
memcpy ( V_8 -> V_91 . V_192 , V_8 -> V_91 . V_194 ,
sizeof( V_8 -> V_91 . V_192 ) ) ;
V_8 -> V_91 . V_179 = V_8 -> V_91 . V_193 ;
V_8 -> V_91 . V_169 = V_217 ;
V_8 -> V_91 . V_193 = 0 ;
}
if ( F_133 ( V_6 ) ) {
V_8 -> V_73 = 1 ;
V_8 -> V_120 = 1 ;
V_8 -> V_239 = 1 ;
V_8 -> V_238 = 1 ;
}
for ( V_69 = 0 ; V_69 < V_8 -> V_239 ; V_69 ++ ) {
V_25 = F_114 ( V_6 , V_8 -> V_240 [ V_69 ] ,
V_8 -> V_285 [ V_69 ] , V_69 ) ;
if ( V_25 < 0 )
return V_25 ;
}
V_25 = F_134 ( V_6 , & V_8 -> V_91 ) ;
if ( V_25 < 0 )
return V_25 ;
if ( V_8 -> V_61 > 0 ) {
V_25 = F_117 ( V_6 ) ;
if ( V_25 < 0 )
return V_25 ;
}
if ( V_8 -> V_252 > 0 && ! V_8 -> V_9 )
if ( ( V_25 = F_127 ( V_6 ,
& V_8 -> V_91 ) ) < 0 )
return V_25 ;
if ( V_8 -> V_238 > 0 ) {
V_25 = F_123 ( V_6 ) ;
if ( V_25 < 0 )
return V_25 ;
}
if ( V_8 -> V_77 > 0 ) {
V_25 = F_124 ( V_6 ) ;
if ( V_25 < 0 )
return V_25 ;
}
V_25 = F_91 ( V_8 ) ;
if ( V_25 < 0 )
return V_25 ;
V_8 -> V_30 . V_286 = V_8 -> V_30 . V_178 * 2 ;
if ( V_8 -> V_30 . V_286 > 2 )
V_8 -> V_287 = 1 ;
for ( V_69 = V_6 -> V_288 ; V_69 < V_6 -> V_288 + V_6 -> V_289 ; V_69 ++ ) {
unsigned int V_216 = F_33 ( V_6 , V_69 ) ;
if ( V_216 & V_190 ) {
switch ( F_98 ( V_216 ) ) {
case V_189 :
if ( ! V_274 )
V_274 = V_69 ;
break;
case V_290 :
if ( ! V_275 )
V_275 = V_69 ;
break;
}
}
}
if ( V_8 -> V_91 . V_291 )
V_8 -> V_30 . V_31 = V_274 ;
if ( V_275 && V_8 -> V_91 . V_292 )
V_8 -> V_82 = V_275 ;
if ( V_8 -> V_153 . V_293 )
V_8 -> V_72 [ V_8 -> V_71 ++ ] = V_8 -> V_153 . V_293 ;
V_8 -> V_47 = & V_8 -> V_165 ;
if ( ! V_8 -> V_9 )
V_8 -> V_9 = & V_8 -> V_250 ;
V_8 -> V_19 = & V_8 -> V_24 ;
V_8 -> V_59 = & V_8 -> V_224 ;
return 1 ;
}
static int F_144 ( struct V_5 * V_6 ,
struct V_167 * V_168 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
T_1 V_174 = V_168 -> V_192 [ 0 ] ;
if ( ! V_174 )
return 0 ;
if ( F_112 ( V_6 , V_174 ) )
V_8 -> V_146 = 1 ;
return 0 ;
}
static int F_145 ( struct V_5 * V_6 ,
struct V_167 * V_168 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
int V_25 ;
T_1 V_294 = 0x0 ;
int V_69 ;
for ( V_69 = 0 ; V_69 < V_8 -> V_91 . V_181 && V_294 == 0x0 ; V_69 ++ ) {
T_1 V_174 = V_8 -> V_91 . V_197 [ V_69 ] ;
unsigned int V_78 = F_33 ( V_6 , V_174 ) ;
V_78 &= ( V_295 | V_79 ) ;
if ( V_78 == V_79 )
V_294 = V_174 ;
}
if ( V_294 == 0 && V_8 -> V_91 . V_181 == 0 ) {
for ( V_69 = 0 ; V_69 < V_8 -> V_91 . V_193 && V_294 == 0x0 ; V_69 ++ ) {
T_1 V_174 = V_8 -> V_91 . V_194 [ V_69 ] ;
unsigned int V_296 ;
V_296 = F_88 ( V_6 , V_174 ) ;
if ( F_131 ( V_296 ) == V_297 ) {
unsigned int V_78 = F_33 ( V_6 , V_174 ) ;
V_78 &= ( V_295 | V_79 ) ;
if ( V_78 == V_79 )
V_294 = V_174 ;
}
}
}
if ( V_294 ) {
V_25 = F_113 ( V_6 , L_26 , V_294 , 1 ) ;
if ( V_25 < 0 )
return V_25 ;
}
return 0 ;
}
static int F_146 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
int V_25 ;
if ( ( V_25 = F_141 ( V_6 , & V_8 -> V_91 , NULL ) ) < 0 )
return V_25 ;
if ( ( V_25 = F_134 ( V_6 , & V_8 -> V_91 ) ) < 0 )
return V_25 ;
if ( ( V_25 = F_144 ( V_6 , & V_8 -> V_91 ) ) < 0 )
return V_25 ;
if ( ( V_25 = F_145 ( V_6 , & V_8 -> V_91 ) ) < 0 )
return V_25 ;
if ( V_8 -> V_238 > 0 ) {
V_25 = F_123 ( V_6 ) ;
if ( V_25 < 0 )
return V_25 ;
}
V_25 = F_91 ( V_8 ) ;
if ( V_25 < 0 )
return V_25 ;
if ( V_8 -> V_91 . V_291 )
V_8 -> V_30 . V_31 = 0x05 ;
if ( V_8 -> V_91 . V_292 )
V_8 -> V_82 = 0x04 ;
if ( V_8 -> V_153 . V_293 )
V_8 -> V_72 [ V_8 -> V_71 ++ ] = V_8 -> V_153 . V_293 ;
V_8 -> V_47 = & V_8 -> V_165 ;
V_8 -> V_9 = & V_8 -> V_250 ;
return 1 ;
}
static void F_147 ( struct V_5 * V_6 , unsigned int V_298 ,
unsigned int V_299 , unsigned int V_300 )
{
unsigned int V_301 , V_302 , V_303 ;
F_13 ( L_41 , V_38 , V_298 , V_299 , V_300 ) ;
V_301 = F_14 ( V_6 , V_6 -> V_66 , 0 ,
V_304 , 0 ) ;
V_301 = ( V_301 & ~ V_299 ) | ( V_300 & V_299 ) ;
V_302 = F_14 ( V_6 , V_6 -> V_66 , 0 ,
V_305 , 0 ) ;
V_302 |= V_298 ;
V_303 = F_14 ( V_6 , V_6 -> V_66 , 0 ,
V_306 , 0 ) ;
V_303 |= V_299 ;
F_61 ( V_6 , V_6 -> V_66 , 0 , 0x7e7 , 0 ) ;
F_61 ( V_6 , V_6 -> V_66 , 0 ,
V_307 , V_302 ) ;
F_14 ( V_6 , V_6 -> V_66 , 0 ,
V_308 , V_303 ) ;
F_46 ( 1 ) ;
F_14 ( V_6 , V_6 -> V_66 , 0 ,
V_309 , V_301 ) ;
}
static int F_148 ( struct V_5 * V_6 , T_1 V_27 ,
unsigned char type , int V_300 )
{
struct V_310 * V_311 ;
V_311 = F_149 ( V_6 , V_27 ) ;
if ( ! V_311 )
return - V_158 ;
V_311 -> V_312 = type ;
V_311 -> V_313 = V_300 ;
return 0 ;
}
static int F_150 ( struct V_5 * V_6 , T_1 V_27 ,
unsigned int type )
{
struct V_310 * V_311 ;
if ( ! F_112 ( V_6 , V_27 ) )
return 0 ;
V_311 = F_149 ( V_6 , V_27 ) ;
if ( ! V_311 )
return - V_158 ;
if ( V_311 -> V_312 && V_311 -> V_312 != type )
return 0 ;
V_311 -> V_312 = type ;
F_151 ( V_6 , V_27 , 0 ) ;
return 1 ;
}
static int F_152 ( struct V_167 * V_168 , T_1 V_27 )
{
int V_69 ;
for ( V_69 = 0 ; V_69 < V_168 -> V_179 ; V_69 ++ )
if ( V_168 -> V_192 [ V_69 ] == V_27 )
return 1 ;
for ( V_69 = 0 ; V_69 < V_168 -> V_193 ; V_69 ++ )
if ( V_168 -> V_194 [ V_69 ] == V_27 )
return 1 ;
return 0 ;
}
static void F_153 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
const T_1 * V_176 ;
for ( V_176 = V_8 -> V_314 ; * V_176 ; V_176 ++ )
if ( ! F_96 ( V_8 , * V_176 ) )
F_61 ( V_6 , * V_176 , 0 ,
V_105 , V_107 ) ;
}
static inline int F_154 ( struct V_5 * V_6 , const char * V_315 ,
int * V_316 )
{
const char * V_317 ;
V_317 = F_155 ( V_6 , V_315 ) ;
if ( V_317 ) {
unsigned long V_26 ;
if ( ! F_156 ( V_317 , 0 , & V_26 ) ) {
* V_316 = V_26 ;
return 1 ;
}
}
return 0 ;
}
static void F_157 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
int V_26 ;
V_26 = F_30 ( V_6 , L_42 ) ;
if ( V_26 >= 0 )
V_8 -> V_146 = V_26 ;
if ( F_154 ( V_6 , L_43 , & V_8 -> V_318 ) ) {
V_8 -> V_319 = V_8 -> V_83 = V_8 -> V_320 =
V_8 -> V_318 ;
}
if ( F_154 ( V_6 , L_44 , & V_8 -> V_83 ) )
V_8 -> V_318 &= V_8 -> V_318 ;
if ( F_154 ( V_6 , L_45 , & V_8 -> V_320 ) )
V_8 -> V_83 &= V_8 -> V_318 ;
if ( F_154 ( V_6 , L_46 , & V_8 -> V_319 ) )
V_8 -> V_319 &= V_8 -> V_318 ;
if ( F_154 ( V_6 , L_47 , & V_8 -> V_321 ) )
V_8 -> V_321 &= V_8 -> V_318 ;
V_26 = F_30 ( V_6 , L_48 ) ;
if ( V_26 >= 0 )
V_8 -> V_322 = V_26 ;
F_154 ( V_6 , L_49 , & V_8 -> V_323 ) ;
if ( F_154 ( V_6 , L_50 , & V_8 -> V_324 ) ) {
V_8 -> V_318 |= V_8 -> V_324 ;
V_8 -> V_83 |= V_8 -> V_324 ;
if ( V_8 -> V_323 )
V_8 -> V_320 |= V_8 -> V_324 ;
}
}
static void F_158 ( struct V_5 * V_6 , int V_93 ,
const T_1 * V_214 )
{
while ( V_93 -- )
F_71 ( V_6 , * V_214 ++ ) ;
}
static void F_159 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
if ( V_8 -> V_91 . V_179 )
F_158 ( V_6 , V_8 -> V_91 . V_179 ,
V_8 -> V_91 . V_192 ) ;
if ( V_8 -> V_91 . V_193 &&
V_8 -> V_91 . V_194 [ 0 ] != V_8 -> V_91 . V_192 [ 0 ] )
F_158 ( V_6 , V_8 -> V_91 . V_193 ,
V_8 -> V_91 . V_194 ) ;
}
static int F_160 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
struct V_167 * V_168 = & V_8 -> V_91 ;
unsigned int V_325 ;
int V_69 ;
F_161 ( V_6 , V_8 -> V_326 ) ;
if ( V_8 -> V_104 )
for ( V_69 = 0 ; V_69 < V_8 -> V_120 ; V_69 ++ )
F_61 ( V_6 ,
V_8 -> V_102 [ V_69 ] , 0 ,
V_105 , V_107 ) ;
F_157 ( V_6 ) ;
V_325 = V_8 -> V_320 ;
if ( ! V_8 -> V_322 )
V_325 |= V_8 -> V_319 ;
F_147 ( V_6 , V_8 -> V_318 , V_8 -> V_83 , V_325 ) ;
if ( V_8 -> V_146 ) {
for ( V_69 = 0 ; V_69 < V_168 -> V_179 ; V_69 ++ ) {
T_1 V_27 = V_168 -> V_192 [ V_69 ] ;
F_150 ( V_6 , V_27 , V_327 ) ;
}
if ( V_168 -> V_169 == V_170 &&
V_168 -> V_181 > 0 ) {
for ( V_69 = 0 ; V_69 < V_168 -> V_193 ; V_69 ++ ) {
T_1 V_27 = V_168 -> V_194 [ V_69 ] ;
F_150 ( V_6 , V_27 , V_328 ) ;
}
}
F_68 ( V_6 , V_8 -> V_91 . V_194 [ 0 ] ,
V_44 ) ;
F_159 ( V_6 ) ;
} else {
F_136 ( V_6 ) ;
F_137 ( V_6 ) ;
for ( V_69 = 0 ; V_69 < V_168 -> V_179 ; V_69 ++ )
F_162 ( V_6 , V_168 -> V_192 [ V_69 ] , 1 ) ;
}
if ( V_8 -> V_73 ) {
if ( V_8 -> V_18 )
F_15 ( V_6 , V_8 -> V_18 [ 0 ] , 0 ,
V_56 , 0 ) ;
if ( F_150 ( V_6 , V_8 -> V_268 . V_174 , V_329 ) )
F_71 ( V_6 , V_8 -> V_268 . V_174 ) ;
if ( F_150 ( V_6 , V_8 -> V_270 . V_174 ,
V_329 ) )
F_71 ( V_6 , V_8 -> V_270 . V_174 ) ;
}
for ( V_69 = 0 ; V_69 < V_168 -> V_171 ; V_69 ++ ) {
T_1 V_27 = V_168 -> V_172 [ V_69 ] . V_174 ;
int type = V_168 -> V_172 [ V_69 ] . type ;
unsigned int V_37 , V_330 ;
if ( type == V_177 ) {
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
V_330 = F_88 ( V_6 , V_27 ) ;
if ( F_128 ( V_330 ) != V_331 ) {
if ( F_150 ( V_6 , V_27 , V_332 ) )
F_71 ( V_6 , V_27 ) ;
}
}
for ( V_69 = 0 ; V_69 < V_8 -> V_252 ; V_69 ++ )
F_68 ( V_6 , V_8 -> V_254 [ V_69 ] ,
V_43 ) ;
if ( V_168 -> V_333 [ 0 ] )
F_68 ( V_6 , V_168 -> V_333 [ 0 ] ,
V_44 ) ;
if ( V_168 -> V_292 )
F_68 ( V_6 , V_168 -> V_292 ,
V_43 ) ;
for ( V_69 = 0 ; V_69 < V_8 -> V_334 ; V_69 ++ ) {
T_1 V_27 = V_8 -> V_335 [ V_69 ] ;
int V_37 , V_160 ;
if ( ! V_8 -> V_146 ||
V_8 -> V_336 == V_27 ) {
F_162 ( V_6 , V_27 , 1 ) ;
continue;
}
if ( F_152 ( V_168 , V_27 ) )
continue;
V_37 = F_14 ( V_6 , V_27 , 0 ,
V_39 , 0 ) ;
if ( V_37 & V_43 ) {
F_162 ( V_6 , V_27 , 1 ) ;
continue;
}
V_160 = F_88 ( V_6 , V_27 ) ;
V_160 = F_128 ( V_160 ) ;
if ( V_160 != V_337 ) {
if ( V_160 != V_256 )
F_162 ( V_6 , V_27 , 1 ) ;
continue;
}
if ( F_150 ( V_6 , V_27 , V_338 ) ) {
F_71 ( V_6 , V_27 ) ;
continue;
}
F_162 ( V_6 , V_27 , 0 ) ;
}
F_163 ( V_6 ) ;
if ( V_8 -> V_324 )
F_164 ( V_6 , 0x01 ) ;
if ( V_8 -> V_314 )
F_153 ( V_6 ) ;
return 0 ;
}
static void F_41 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
if ( V_8 -> V_153 . V_293 ) {
struct V_149 * V_339 = V_8 -> V_153 . V_293 ;
int V_69 ;
for ( V_69 = 0 ; V_69 < V_8 -> V_153 . V_340 ; V_69 ++ )
F_165 ( V_339 [ V_69 ] . V_113 ) ;
}
F_166 ( & V_8 -> V_153 ) ;
}
static void F_167 ( struct V_5 * V_6 )
{
unsigned int V_69 , V_160 ;
if ( V_6 -> V_341 -> V_342 )
return;
for ( V_69 = 0 ; V_69 < V_6 -> V_343 . V_340 ; V_69 ++ ) {
struct V_344 * V_174 = F_168 ( & V_6 -> V_343 , V_69 ) ;
V_160 = F_88 ( V_6 , V_174 -> V_27 ) ;
if ( F_128 ( V_160 ) != V_256 )
F_61 ( V_6 , V_174 -> V_27 , 0 ,
V_41 , 0 ) ;
}
}
static void F_169 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
F_167 ( V_6 ) ;
if ( V_8 -> V_319 )
F_147 ( V_6 , V_8 -> V_318 ,
V_8 -> V_83 , V_8 -> V_320 &
~ V_8 -> V_319 ) ;
}
static void F_170 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
if ( ! V_8 )
return;
F_169 ( V_6 ) ;
F_165 ( V_8 ) ;
F_171 ( V_6 ) ;
}
static void F_172 ( struct V_5 * V_6 , T_1 V_27 ,
unsigned int V_345 )
{
unsigned int V_346 , V_347 ;
V_347 = F_14 ( V_6 , V_27 ,
0 , V_39 , 0x00 ) ;
if ( V_347 & V_43 ) {
struct V_7 * V_8 = V_6 -> V_8 ;
if ( V_27 == V_8 -> V_142 || V_27 == V_8 -> V_141 )
return;
}
V_346 = V_347 ;
if ( V_345 & ( V_43 | V_44 ) )
V_347 &= ~ ( V_43 | V_44 ) ;
V_347 |= V_345 ;
if ( V_346 != V_347 )
F_15 ( V_6 , V_27 , 0 ,
V_41 ,
V_347 ) ;
}
static void F_173 ( struct V_5 * V_6 , T_1 V_27 ,
unsigned int V_345 )
{
unsigned int V_347 = F_14 ( V_6 , V_27 ,
0 , V_39 , 0x00 ) ;
if ( V_347 & V_345 )
F_15 ( V_6 , V_27 , 0 ,
V_41 ,
V_347 & ~ V_345 ) ;
}
static inline int F_174 ( struct V_5 * V_6 , T_1 V_27 )
{
if ( ! V_27 )
return 0 ;
return F_175 ( V_6 , V_27 ) ;
}
static void F_176 ( struct V_5 * V_6 ,
int V_348 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
struct V_167 * V_168 = & V_8 -> V_91 ;
int V_69 ;
for ( V_69 = 0 ; V_69 < V_168 -> V_193 ; V_69 ++ ) {
if ( V_348 )
break;
V_348 = F_174 ( V_6 , V_168 -> V_194 [ V_69 ] ) ;
if ( V_348 ) {
unsigned int V_37 ;
V_37 = F_14 ( V_6 ,
V_168 -> V_194 [ V_69 ] , 0 ,
V_39 , 0 ) ;
if ( V_37 & V_43 )
V_348 = 0 ;
}
}
if ( V_348 ) {
for ( V_69 = 0 ; V_69 < V_168 -> V_181 ; V_69 ++ )
F_173 ( V_6 , V_168 -> V_197 [ V_69 ] ,
V_44 ) ;
if ( V_8 -> V_319 && V_8 -> V_322 )
F_147 ( V_6 , V_8 -> V_318 ,
V_8 -> V_83 , V_8 -> V_320 &
~ V_8 -> V_319 ) ;
} else {
for ( V_69 = 0 ; V_69 < V_168 -> V_181 ; V_69 ++ )
F_172 ( V_6 , V_168 -> V_197 [ V_69 ] ,
V_44 ) ;
if ( V_8 -> V_319 && V_8 -> V_322 )
F_147 ( V_6 , V_8 -> V_318 ,
V_8 -> V_83 , V_8 -> V_320 |
V_8 -> V_319 ) ;
}
}
static int F_177 ( struct V_7 * V_8 , int V_69 )
{
struct V_167 * V_168 = & V_8 -> V_91 ;
if ( V_168 -> V_192 [ V_69 ] == V_8 -> V_142 )
return 1 ;
if ( V_168 -> V_192 [ V_69 ] == V_8 -> V_141 )
return 1 ;
if ( V_168 -> V_192 [ V_69 ] == V_8 -> V_139 )
return 1 ;
return 0 ;
}
static void F_178 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
struct V_167 * V_168 = & V_8 -> V_91 ;
int V_69 , V_348 ;
V_348 = 0 ;
if ( V_8 -> V_321 )
V_348 = ! ( F_14 ( V_6 , V_6 -> V_66 , 0 ,
V_304 , 0 ) & V_8 -> V_321 ) ;
for ( V_69 = 0 ; V_69 < V_168 -> V_179 ; V_69 ++ ) {
if ( V_348 )
break;
if ( F_177 ( V_8 , V_69 ) )
continue;
V_348 = F_174 ( V_6 , V_168 -> V_192 [ V_69 ] ) ;
if ( V_348 ) {
unsigned int V_37 ;
V_37 = F_14 ( V_6 , V_168 -> V_192 [ V_69 ] , 0 ,
V_39 , 0 ) ;
if ( V_37 & V_43 )
V_348 = 0 ;
}
}
if ( V_348 ) {
if ( V_8 -> V_139 )
F_173 ( V_6 , V_8 -> V_139 ,
V_44 ) ;
for ( V_69 = 0 ; V_69 < V_168 -> V_193 ; V_69 ++ )
F_173 ( V_6 , V_168 -> V_194 [ V_69 ] ,
V_44 ) ;
} else {
if ( V_8 -> V_139 )
F_172 ( V_6 , V_8 -> V_139 ,
V_44 ) ;
for ( V_69 = 0 ; V_69 < V_168 -> V_193 ; V_69 ++ )
F_172 ( V_6 , V_168 -> V_194 [ V_69 ] ,
V_44 ) ;
}
F_176 ( V_6 , V_348 ) ;
for ( V_69 = 0 ; V_69 < V_168 -> V_179 ; V_69 ++ ) {
unsigned int V_26 = V_44 | V_271 ;
if ( F_177 ( V_8 , V_69 ) )
continue;
if ( 1 )
F_172 ( V_6 , V_168 -> V_192 [ V_69 ] , V_26 ) ;
#if 0
else
stac92xx_reset_pinctl(codec, cfg->hp_pins[i], val);
#endif
}
}
static void F_162 ( struct V_5 * V_6 , T_1 V_27 ,
int V_349 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
unsigned int V_51 , V_26 ;
for ( V_51 = 0 ; V_51 < V_8 -> V_334 ; V_51 ++ ) {
if ( V_8 -> V_335 [ V_51 ] == V_27 )
break;
}
if ( V_51 >= V_8 -> V_334 )
return;
V_51 = 1 << V_51 ;
V_26 = F_14 ( V_6 , V_6 -> V_66 , 0 , 0x0fec , 0x0 ) & 0xff ;
if ( V_349 )
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
unsigned int V_168 ;
V_168 = F_88 ( V_6 , V_8 -> V_94 [ V_51 ] ) ;
return F_128 ( V_168 ) ;
}
static int F_181 ( struct V_5 * V_6 ,
const T_1 * V_350 , int V_351 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
int V_51 , V_352 ;
unsigned int V_160 ;
for ( V_352 = 0 ; V_352 < V_351 ; V_352 ++ ) {
for ( V_51 = 0 ; V_51 < V_8 -> V_93 ; V_51 ++ )
if ( V_8 -> V_94 [ V_51 ] == V_350 [ V_352 ] )
break;
if ( V_51 >= V_8 -> V_93 )
break;
V_160 = F_180 ( V_6 , V_51 ) ;
if ( V_160 == V_256 )
break;
}
return V_352 ;
}
static void F_182 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
struct V_265 * V_266 ;
if ( F_174 ( V_6 , V_8 -> V_268 . V_174 ) )
V_266 = & V_8 -> V_268 ;
else if ( F_174 ( V_6 , V_8 -> V_270 . V_174 ) )
V_266 = & V_8 -> V_270 ;
else
V_266 = & V_8 -> V_269 ;
if ( V_266 -> V_12 >= 0 )
F_15 ( V_6 , V_8 -> V_18 [ 0 ] , 0 ,
V_56 ,
V_266 -> V_12 ) ;
if ( V_266 -> V_267 >= 0 )
F_15 ( V_6 , V_8 -> V_55 [ 0 ] , 0 ,
V_56 ,
V_266 -> V_267 ) ;
}
static void F_183 ( struct V_5 * V_6 ,
struct V_310 * V_311 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
int V_300 ;
switch ( V_311 -> V_312 ) {
case V_327 :
case V_328 :
F_178 ( V_6 ) ;
break;
case V_329 :
F_182 ( V_6 ) ;
break;
}
switch ( V_311 -> V_312 ) {
case V_327 :
case V_328 :
case V_329 :
case V_332 :
case V_338 :
if ( V_8 -> V_334 > 0 )
F_179 ( V_6 , V_311 -> V_27 ) ;
switch ( V_6 -> V_353 ) {
case 0x103c308f :
if ( V_311 -> V_27 == 0xb ) {
int V_174 = V_43 ;
if ( F_174 ( V_6 , 0xa )
&& F_174 ( V_6 , 0xb ) )
V_174 |= V_133 ;
if ( ! F_174 ( V_6 , 0xb ) )
V_174 |= V_133 ;
F_68 ( V_6 , 0x0a , V_174 ) ;
}
}
break;
case V_354 :
V_300 = F_14 ( V_6 , V_6 -> V_66 , 0 ,
V_304 , 0 ) ;
F_61 ( V_6 , V_6 -> V_66 , 0 , 0x7e0 ,
! ! ( V_300 & ( 1 << V_311 -> V_313 ) ) ) ;
break;
}
}
static void F_71 ( struct V_5 * V_6 , T_1 V_27 )
{
struct V_310 * V_311 = F_184 ( V_6 , V_27 ) ;
if ( ! V_311 )
return;
F_183 ( V_6 , V_311 ) ;
}
static void F_185 ( struct V_5 * V_6 , unsigned int V_355 )
{
struct V_310 * V_311 ;
int V_356 ;
V_356 = ( V_355 >> 26 ) & 0x7f ;
V_311 = F_186 ( V_6 , V_356 ) ;
if ( ! V_311 )
return;
V_311 -> V_357 = 1 ;
F_183 ( V_6 , V_311 ) ;
F_163 ( V_6 ) ;
}
static void F_187 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
unsigned int V_325 ;
if ( V_8 -> V_324 )
return;
V_325 = F_188 ( V_6 , V_6 -> V_66 , V_358 ) ;
V_325 &= V_359 ;
if ( V_325 > 3 )
V_8 -> V_324 = 0x08 ;
else
V_8 -> V_324 = 0x01 ;
}
static int F_189 ( struct V_5 * V_6 , int V_360 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
const struct V_361 * V_362 = NULL ;
if ( ( V_6 -> V_353 >> 16 ) == V_363 ) {
while ( ( V_362 = F_190 ( V_364 ,
NULL , V_362 ) ) ) {
if ( sscanf ( V_362 -> V_113 , L_51 ,
& V_8 -> V_323 ,
& V_8 -> V_324 ) == 2 ) {
unsigned int V_365 ;
V_365 = F_188 ( V_6 , V_6 -> V_66 ,
V_358 ) ;
V_365 &= V_359 ;
if ( V_8 -> V_324 < V_365 )
V_8 -> V_324 = 1 << V_8 -> V_324 ;
else
V_8 -> V_336 = V_8 -> V_324 ;
return 1 ;
}
if ( sscanf ( V_362 -> V_113 , L_52 ,
& V_8 -> V_323 ) == 1 ) {
F_187 ( V_6 ) ;
return 1 ;
}
if ( strstr ( V_362 -> V_113 , L_53 ) ) {
F_187 ( V_6 ) ;
switch ( V_6 -> V_353 ) {
case 0x103c148a :
V_8 -> V_323 = 0 ;
break;
default:
V_8 -> V_323 = 1 ;
break;
}
return 1 ;
}
}
if ( ! F_191 ( V_6 -> V_353 ) &&
( V_360 == 0 || V_360 == 1 ) ) {
F_187 ( V_6 ) ;
V_8 -> V_323 = V_360 ;
return 1 ;
}
}
return 0 ;
}
static int F_191 ( T_2 V_353 )
{
switch ( V_353 ) {
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
static void F_192 ( struct V_366 * V_367 ,
struct V_5 * V_6 , T_1 V_27 )
{
if ( V_27 == V_6 -> V_66 )
F_193 ( V_367 , L_54 ,
F_14 ( V_6 , V_27 , 0 , 0x0fec , 0x0 ) ) ;
}
static void F_194 ( struct V_366 * V_367 ,
struct V_5 * V_6 ,
unsigned int V_368 )
{
F_193 ( V_367 , L_55 ,
F_14 ( V_6 , V_6 -> V_66 , 0 , V_368 , 0 ) ) ;
}
static void F_195 ( struct V_366 * V_367 ,
struct V_5 * V_6 , T_1 V_27 )
{
F_192 ( V_367 , V_6 , V_27 ) ;
if ( V_27 == V_6 -> V_66 )
F_194 ( V_367 , V_6 , 0xfa0 ) ;
}
static void F_196 ( struct V_366 * V_367 ,
struct V_5 * V_6 , T_1 V_27 )
{
if ( V_27 == V_6 -> V_66 )
F_194 ( V_367 , V_6 , 0xfe0 ) ;
}
static void F_197 ( struct V_366 * V_367 ,
struct V_5 * V_6 , T_1 V_27 )
{
if ( V_27 == V_6 -> V_66 )
F_194 ( V_367 , V_6 , 0xfeb ) ;
}
static int F_198 ( struct V_5 * V_6 )
{
F_160 ( V_6 ) ;
F_199 ( V_6 ) ;
F_200 ( V_6 ) ;
F_159 ( V_6 ) ;
return 0 ;
}
static int F_201 ( struct V_5 * V_6 , T_3 V_369 )
{
F_169 ( V_6 ) ;
return 0 ;
}
static int F_202 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
if ( V_8 -> V_336 )
F_12 ( V_6 , V_8 -> V_336 ,
V_8 -> V_370 ) ;
else if ( V_8 -> V_324 )
F_147 ( V_6 , V_8 -> V_318 ,
V_8 -> V_83 , V_8 -> V_320 ) ;
return 0 ;
}
static void F_203 ( struct V_5 * V_6 , T_1 V_371 ,
unsigned int V_372 )
{
unsigned int V_373 = V_372 ;
struct V_7 * V_8 = V_6 -> V_8 ;
if ( V_372 == V_107 ) {
if ( V_8 -> V_336 ) {
V_373 = V_374 ;
}
F_46 ( 100 ) ;
}
F_14 ( V_6 , V_371 , 0 , V_105 ,
V_373 ) ;
F_204 ( V_6 , V_371 , V_372 , true ) ;
}
static int F_205 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
int V_69 , V_375 , V_376 = 1 ;
unsigned int V_377 , V_378 ;
T_1 V_27 ;
if ( ! V_8 -> V_324 )
return 0 ;
for ( V_69 = 0 ; V_69 < V_8 -> V_30 . V_178 ; V_69 ++ ) {
V_27 = V_8 -> V_30 . V_85 [ V_69 ] ;
if ( ! ( F_206 ( V_6 , V_27 , 0 , V_35 , 0 ) &
V_34 ) ) {
V_376 = 0 ;
break;
}
}
if ( V_376 && V_8 -> V_30 . V_191 )
if ( ! ( F_206 ( V_6 ,
V_8 -> V_30 . V_191 , 0 , V_35 , 0 ) &
V_34 ) ) {
V_376 = 0 ;
}
V_375 = F_110 ( V_8 -> V_30 . V_212 ) ;
for ( V_69 = 0 ; V_376 && V_69 < V_375 ; V_69 ++ ) {
V_27 = V_8 -> V_30 . V_212 [ V_69 ] ;
if ( V_27 == 0 )
break;
if ( ! ( F_206 ( V_6 , V_27 , 0 , V_35 , 0 ) &
V_34 ) ) {
V_376 = 0 ;
}
}
if ( ! V_8 -> V_336 ) {
if ( V_376 )
V_8 -> V_320 &= ~ V_8 -> V_324 ;
else
V_8 -> V_320 |= V_8 -> V_324 ;
if ( ! V_8 -> V_323 ) {
V_8 -> V_320 ^= V_8 -> V_324 ;
}
F_147 ( V_6 , V_8 -> V_318 ,
V_8 -> V_83 , V_8 -> V_320 ) ;
} else {
V_378 = V_8 -> V_323 ?
V_135 : V_137 ;
V_377 = V_8 -> V_323 ?
V_137 : V_135 ;
V_8 -> V_370 = V_376 ? V_377 : V_378 ;
F_12 ( V_6 , V_8 -> V_336 ,
V_8 -> V_370 ) ;
}
return 0 ;
}
static int F_207 ( struct V_5 * V_6 ,
T_1 V_27 )
{
F_205 ( V_6 ) ;
return 0 ;
}
static int F_208 ( struct V_5 * V_6 )
{
struct V_7 * V_8 ;
int V_25 ;
V_8 = F_209 ( sizeof( * V_8 ) , V_154 ) ;
if ( V_8 == NULL )
return - V_158 ;
V_6 -> V_379 = 1 ;
V_6 -> V_8 = V_8 ;
V_8 -> V_284 = 1 ;
V_8 -> V_93 = F_110 ( V_380 ) ;
V_8 -> V_94 = V_380 ;
V_8 -> V_381 = F_210 ( V_6 , V_382 ,
V_383 ,
V_384 ) ;
if ( V_8 -> V_381 < 0 )
F_13 ( V_385 L_56 ,
V_6 -> V_386 ) ;
else
F_43 ( V_6 ,
V_387 [ V_8 -> V_381 ] ) ;
V_8 -> V_30 . V_286 = 2 ;
V_8 -> V_30 . V_178 = 1 ;
V_8 -> V_30 . V_85 = V_388 ;
V_8 -> V_102 = V_389 ;
V_8 -> V_55 = V_390 ;
V_8 -> V_238 = 1 ;
V_8 -> V_252 = 0 ;
V_8 -> V_120 = 1 ;
V_8 -> V_334 = 0 ;
if ( V_8 -> V_381 == V_391 ||
V_8 -> V_381 == V_392 ||
V_8 -> V_381 == V_393 )
V_8 -> V_326 = V_394 ;
else
V_8 -> V_326 = V_395 ;
V_8 -> V_70 = V_396 ;
if ( V_8 -> V_381 == V_397 ) {
V_8 -> V_318 = V_8 -> V_83 = 0x09 ;
V_8 -> V_320 = 0x00 ;
}
V_25 = F_146 ( V_6 ) ;
if ( V_25 < 0 ) {
F_170 ( V_6 ) ;
return V_25 ;
}
if ( V_8 -> V_381 == V_397 )
V_8 -> V_146 = 0 ;
V_6 -> V_398 = V_399 ;
return 0 ;
}
static int F_211 ( struct V_5 * V_6 )
{
struct V_7 * V_8 ;
int V_25 ;
V_8 = F_209 ( sizeof( * V_8 ) , V_154 ) ;
if ( V_8 == NULL )
return - V_158 ;
V_6 -> V_379 = 1 ;
V_6 -> V_8 = V_8 ;
V_8 -> V_284 = 1 ;
V_8 -> V_93 = F_110 ( V_400 ) ;
V_8 -> V_94 = V_400 ;
V_8 -> V_381 = F_212 ( V_6 ,
V_401 ,
V_402 ,
V_403 ) ;
if ( V_8 -> V_381 < 0 )
V_8 -> V_381 = F_210 ( V_6 ,
V_401 ,
V_402 ,
V_404 ) ;
V_405:
if ( V_8 -> V_381 < 0 )
F_13 ( V_385 L_56 ,
V_6 -> V_386 ) ;
else
F_43 ( V_6 ,
V_406 [ V_8 -> V_381 ] ) ;
V_8 -> V_30 . V_286 = 2 ;
V_8 -> V_30 . V_178 = 1 ;
V_8 -> V_30 . V_85 = V_407 ;
V_8 -> V_102 = V_408 ;
V_8 -> V_55 = V_409 ;
V_8 -> V_238 = 1 ;
V_8 -> V_120 = 1 ;
V_8 -> V_334 = 0 ;
switch ( V_6 -> V_410 ) {
case 0x83847632 :
case 0x83847633 :
case 0x83847636 :
case 0x83847637 :
V_8 -> V_252 = V_411 ;
V_8 -> V_254 = V_412 ;
V_8 -> V_74 = F_110 ( V_413 ) ;
V_8 -> V_18 = V_413 ;
break;
default:
V_8 -> V_252 = 0 ;
break;
}
V_8 -> V_326 = V_414 ;
V_8 -> V_70 = V_415 ;
V_8 -> V_239 = 1 ;
V_8 -> V_240 = V_416 ;
V_8 -> V_285 = V_417 ;
V_25 = F_140 ( V_6 ) ;
if ( ! V_25 ) {
if ( V_8 -> V_381 < 0 ) {
F_108 ( V_211 L_57
L_58 ) ;
V_8 -> V_381 = V_418 ;
goto V_405;
}
V_25 = - V_229 ;
}
if ( V_25 < 0 ) {
F_170 ( V_6 ) ;
return V_25 ;
}
V_6 -> V_398 = V_399 ;
return 0 ;
}
static int F_213 ( struct V_5 * V_6 )
{
struct V_7 * V_8 ;
T_1 V_185 [ V_419 + 2 ] ;
int V_25 = 0 ;
int V_178 ;
V_8 = F_209 ( sizeof( * V_8 ) , V_154 ) ;
if ( V_8 == NULL )
return - V_158 ;
V_6 -> V_379 = 1 ;
V_6 -> V_8 = V_8 ;
V_8 -> V_284 = 0 ;
V_6 -> V_32 = V_420 ;
V_8 -> V_93 = F_110 ( V_421 ) ;
V_8 -> V_94 = V_421 ;
V_8 -> V_381 = F_210 ( V_6 ,
V_422 ,
V_423 ,
V_424 ) ;
if ( V_8 -> V_381 < 0 )
V_8 -> V_381 =
F_212 ( V_6 ,
V_422 , V_423 ,
V_425 ) ;
V_405:
if ( V_8 -> V_381 < 0 )
F_13 ( V_385 L_56 ,
V_6 -> V_386 ) ;
else
F_43 ( V_6 ,
V_426 [ V_8 -> V_381 ] ) ;
V_178 = F_97 ( V_6 , 0x0a ,
V_185 , V_419 + 2 ) - 1 ;
if ( V_178 < 3 || V_178 > 5 ) {
F_108 ( V_211 L_59
L_60 ) ;
V_178 = V_419 ;
}
V_8 -> V_326 = V_427 ;
switch ( V_178 ) {
case 0x3 :
V_8 -> V_90 = V_428 ;
break;
case 0x4 :
V_8 -> V_90 = V_429 ;
break;
case 0x5 :
V_8 -> V_90 = V_430 ;
break;
}
V_8 -> V_30 . V_85 = V_8 -> V_85 ;
V_8 -> V_63 = 0x01 ;
V_8 -> V_68 = 8 ;
V_8 -> V_282 = 0x1c ;
V_8 -> V_55 = V_431 ;
V_8 -> V_102 = V_432 ;
V_8 -> V_254 = V_433 ;
V_8 -> V_18 = V_434 ;
V_8 -> V_28 = V_435 ;
V_8 -> V_238 = F_110 ( V_431 ) ;
V_8 -> V_120 = F_110 ( V_432 ) ;
V_8 -> V_74 = F_110 ( V_434 ) ;
V_8 -> V_239 = V_436 ;
V_8 -> V_240 = V_437 ;
V_8 -> V_285 = V_438 ;
switch ( V_8 -> V_381 ) {
case V_439 :
V_8 -> V_326 = V_440 ;
case V_441 :
case V_442 :
case V_443 :
V_8 -> V_77 = 0 ;
V_8 -> V_322 = 0 ;
switch ( V_8 -> V_381 ) {
case V_441 :
F_44 ( V_6 , 0x0b , 0x90A70170 ) ;
V_8 -> V_252 = 0 ;
break;
case V_442 :
F_44 ( V_6 , 0x13 , 0x90A60160 ) ;
V_8 -> V_252 = 1 ;
break;
case V_443 :
F_44 ( V_6 , 0x0b , 0x90A70170 ) ;
F_44 ( V_6 , 0x13 , 0x90A60160 ) ;
V_8 -> V_252 = 1 ;
break;
}
break;
case V_444 :
V_8 -> V_252 = V_445 ;
V_8 -> V_77 = F_110 ( V_435 ) ;
V_8 -> V_322 = 0 ;
break;
default:
V_8 -> V_252 = V_445 ;
V_8 -> V_77 = F_110 ( V_435 ) ;
V_8 -> V_322 = 1 ;
break;
}
if ( V_8 -> V_381 != V_446 ) {
V_8 -> V_319 = V_8 -> V_318 = V_8 -> V_83 = 0x1 ;
V_8 -> V_320 = 0x01 ;
}
V_8 -> V_334 = F_110 ( V_447 ) ;
V_8 -> V_335 = V_447 ;
V_25 = F_140 ( V_6 ) ;
if ( ! V_25 ) {
if ( V_8 -> V_381 < 0 ) {
F_108 ( V_211 L_57
L_58 ) ;
V_8 -> V_381 = V_446 ;
goto V_405;
}
V_25 = - V_229 ;
}
if ( V_25 < 0 ) {
F_170 ( V_6 ) ;
return V_25 ;
}
if ( V_8 -> V_381 == V_448 )
V_8 -> V_146 = 0 ;
V_6 -> V_398 = V_399 ;
V_6 -> V_449 = F_195 ;
return 0 ;
}
static int F_214 ( struct V_5 * V_6 )
{
if ( V_6 -> V_410 != 0x111d7605 &&
V_6 -> V_410 != 0x111d76d1 )
return 0 ;
switch ( V_6 -> V_353 ) {
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
unsigned int V_160 = F_88 ( V_6 , V_27 ) ;
int V_69 ;
V_8 -> V_450 [ V_8 -> V_451 ] = V_27 ;
V_8 -> V_451 ++ ;
if ( F_131 ( V_160 ) == V_261 &&
F_128 ( V_160 ) != V_256 ) {
for ( V_69 = 0 ; V_69 < F_110 ( V_452 ) ; V_69 ++ ) {
if ( V_27 == V_452 [ V_69 ] ) {
V_8 -> V_453 [ V_8 -> V_454 ] = V_27 ;
V_8 -> V_454 ++ ;
}
}
}
}
static void F_216 ( struct V_5 * V_6 , T_1 V_27 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
V_8 -> V_455 [ V_8 -> V_456 ] = V_27 ;
V_8 -> V_456 ++ ;
}
static void F_217 ( struct V_5 * V_6 , T_1 V_27 )
{
int V_69 , V_183 ;
struct V_7 * V_8 = V_6 -> V_8 ;
for ( V_69 = 0 ; V_69 < V_8 -> V_456 ; V_69 ++ ) {
if ( F_129 ( V_6 ,
V_8 -> V_455 [ V_69 ] , V_27 ) >= 0 ) {
if ( ! V_8 -> V_457 [ V_69 ] ) {
V_8 -> V_457 [ V_69 ] = V_27 ;
V_8 -> V_458 [ V_69 ] = F_107 ( V_27 ,
3 , 0 , V_35 ) ;
}
for ( V_183 = 0 ; V_183 < V_8 -> V_454 ; V_183 ++ ) {
if ( F_129 ( V_6 , V_27 ,
V_8 -> V_453 [ V_183 ] ) >= 0 ) {
if ( ! V_8 -> V_459 [ V_69 ] )
V_8 -> V_459 [ V_69 ] = V_27 ;
break;
}
}
break;
}
}
}
static void F_218 ( struct V_5 * V_6 )
{
T_1 V_27 , V_460 ;
unsigned int V_216 , V_280 ;
struct V_7 * V_8 = V_6 -> V_8 ;
V_460 = V_6 -> V_288 + V_6 -> V_289 ;
for ( V_27 = V_6 -> V_288 ; V_27 < V_460 ; V_27 ++ ) {
V_216 = F_33 ( V_6 , V_27 ) ;
V_280 = F_98 ( V_216 ) ;
if ( V_280 == V_255 )
F_215 ( V_6 , V_27 ) ;
if ( V_280 == V_290 && ! ( V_216 & V_190 ) )
F_216 ( V_6 , V_27 ) ;
}
for ( V_27 = V_6 -> V_288 ; V_27 < V_460 ; V_27 ++ ) {
V_216 = F_33 ( V_6 , V_27 ) ;
V_280 = F_98 ( V_216 ) ;
if ( V_280 == V_281 )
F_217 ( V_6 , V_27 ) ;
}
V_8 -> V_94 = V_8 -> V_450 ;
V_8 -> V_93 = V_8 -> V_451 ;
V_8 -> V_102 = V_8 -> V_455 ;
V_8 -> V_120 = V_8 -> V_456 ;
V_8 -> V_240 = V_8 -> V_458 ;
V_8 -> V_285 = V_8 -> V_458 ;
V_8 -> V_239 = V_8 -> V_456 ;
V_8 -> V_55 = V_8 -> V_457 ;
V_8 -> V_238 = V_8 -> V_456 ;
V_8 -> V_18 = V_8 -> V_459 ;
V_8 -> V_74 = V_8 -> V_456 ;
V_8 -> V_254 = V_8 -> V_453 ;
V_8 -> V_252 = V_8 -> V_454 ;
}
static int F_219 ( struct V_5 * V_6 )
{
struct V_7 * V_8 ;
int V_25 ;
V_8 = F_209 ( sizeof( * V_8 ) , V_154 ) ;
if ( V_8 == NULL )
return - V_158 ;
if ( F_214 ( V_6 ) ) {
F_44 ( V_6 , 0xa , 0x2101201f ) ;
F_44 ( V_6 , 0xf , 0x2181205e ) ;
}
V_6 -> V_379 = 1 ;
V_6 -> V_8 = V_8 ;
F_218 ( V_6 ) ;
V_8 -> V_284 = 0 ;
V_6 -> V_32 = V_461 ;
V_8 -> V_282 = 0x21 ;
V_8 -> V_335 = V_462 ;
V_8 -> V_334 = F_110 ( V_462 ) ;
V_8 -> V_30 . V_85 = V_8 -> V_85 ;
V_8 -> V_326 = V_463 ;
V_8 -> V_381 = F_210 ( V_6 ,
V_464 ,
V_465 ,
V_466 ) ;
V_405:
if ( V_8 -> V_381 < 0 )
F_13 ( V_385 L_56 ,
V_6 -> V_386 ) ;
else
F_43 ( V_6 ,
V_467 [ V_8 -> V_381 ] ) ;
V_6 -> V_398 = V_399 ;
if ( F_189 ( V_6 , - 1 ) )
F_103 ( L_61 ,
V_8 -> V_324 ,
V_8 -> V_323 ) ;
#ifdef F_220
if ( V_8 -> V_324 ) {
if ( ! V_8 -> V_336 ) {
V_8 -> V_318 |= V_8 -> V_324 ;
V_8 -> V_83 |= V_8 -> V_324 ;
V_8 -> V_320 |= V_8 -> V_324 ;
} else {
V_6 -> V_398 . V_468 =
F_203 ;
}
V_6 -> V_398 . V_469 = F_202 ;
V_6 -> V_398 . V_470 =
F_207 ;
}
#endif
V_25 = F_140 ( V_6 ) ;
if ( ! V_25 ) {
if ( V_8 -> V_381 < 0 ) {
F_108 ( V_211 L_57
L_58 ) ;
V_8 -> V_381 = V_471 ;
goto V_405;
}
V_25 = - V_229 ;
}
if ( V_25 < 0 ) {
F_170 ( V_6 ) ;
return V_25 ;
}
V_6 -> V_449 = F_192 ;
return 0 ;
}
static int F_221 ( struct V_5 * V_6 ,
T_1 V_472 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
int V_51 ;
for ( V_51 = 0 ; V_51 < V_8 -> V_93 ; V_51 ++ )
if ( V_8 -> V_94 [ V_51 ] == V_472 )
break;
if ( ( V_51 + 2 ) >= V_8 -> V_93 )
return 0 ;
if ( F_180 ( V_6 , V_51 + 1 ) != V_256 )
return 2 ;
if ( F_180 ( V_6 , V_51 + 2 ) != V_256 )
return 2 ;
if ( F_180 ( V_6 , V_51 ) != V_256 )
return 1 ;
else
return 0 ;
}
static int F_222 ( struct V_1 * V_2 ,
struct V_10 * V_11 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = V_6 -> V_8 ;
V_11 -> V_14 . integer . V_14 [ 0 ] = ! ! ( V_8 -> V_320 & 0x20 ) ;
return 0 ;
}
static int F_223 ( struct V_1 * V_2 ,
struct V_10 * V_11 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = V_6 -> V_8 ;
unsigned int V_320 ;
V_320 = ( V_8 -> V_320 & ~ 0x20 ) |
( V_11 -> V_14 . integer . V_14 [ 0 ] ? 0x20 : 0 ) ;
if ( V_320 == V_8 -> V_320 )
return 0 ;
V_8 -> V_320 = V_320 ;
F_147 ( V_6 , V_8 -> V_318 , V_8 -> V_83 , V_8 -> V_320 ) ;
return 1 ;
}
static int F_224 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
if ( ! F_80 ( V_8 , & V_473 ,
L_62 , 0 ) )
return - V_158 ;
V_8 -> V_318 |= 0x20 ;
V_8 -> V_83 |= 0x20 ;
V_8 -> V_320 |= 0x20 ;
return 0 ;
}
static int F_225 ( struct V_5 * V_6 )
{
struct V_7 * V_8 ;
const struct V_474 * V_475 = V_476 ;
unsigned int V_477 ;
int V_25 = 0 ;
V_8 = F_209 ( sizeof( * V_8 ) , V_154 ) ;
if ( V_8 == NULL )
return - V_158 ;
V_6 -> V_379 = 1 ;
V_6 -> V_8 = V_8 ;
V_8 -> V_284 = 0 ;
V_6 -> V_398 = V_399 ;
V_8 -> V_93 = V_478 ;
switch ( V_6 -> V_410 ) {
case 0x111d76b6 :
case 0x111d76b7 :
V_8 -> V_94 = V_479 ;
break;
case 0x111d7603 :
case 0x111d7608 :
V_8 -> V_93 -- ;
default:
V_8 -> V_94 = V_480 ;
}
V_8 -> V_334 = F_110 ( V_481 ) ;
V_8 -> V_381 = F_210 ( V_6 ,
V_482 ,
V_483 ,
V_484 ) ;
V_405:
if ( V_8 -> V_381 < 0 )
F_13 ( V_385 L_56 ,
V_6 -> V_386 ) ;
else
F_43 ( V_6 ,
V_485 [ V_8 -> V_381 ] ) ;
if ( V_8 -> V_381 != V_486 ) {
V_8 -> V_318 = 0x01 ;
V_8 -> V_83 = 0x01 ;
V_8 -> V_320 = 0x01 ;
}
V_8 -> V_254 = V_487 ;
V_8 -> V_18 = V_488 ;
V_8 -> V_239 = V_489 ;
V_8 -> V_240 = V_490 ;
V_8 -> V_285 = V_491 ;
switch ( V_6 -> V_410 ) {
case 0x111d76b6 :
case 0x111d76b7 :
V_475 ++ ;
case 0x111d76b4 :
case 0x111d76b5 :
V_8 -> V_326 = V_492 ;
V_6 -> V_32 = V_493 ;
V_8 -> V_252 = F_181 ( V_6 ,
V_487 ,
V_494 ) ;
break;
case 0x111d7608 :
switch ( V_8 -> V_381 ) {
case V_495 :
V_25 = F_148 ( V_6 , V_6 -> V_66 ,
V_354 , 0x02 ) ;
if ( V_25 < 0 )
return V_25 ;
F_15 ( V_6 , V_6 -> V_66 , 0 ,
V_496 , 0x02 ) ;
F_151 ( V_6 , V_6 -> V_66 , 0 ) ;
V_8 -> V_318 |= 0x02 ;
break;
}
if ( ( V_6 -> V_497 & 0xf ) == 0 ||
( V_6 -> V_497 & 0xf ) == 1 )
V_8 -> V_99 = 40 ;
V_8 -> V_326 = V_492 ;
V_475 ++ ;
F_44 ( V_6 , 0x0f , 0x40f000f0 ) ;
F_44 ( V_6 , 0x19 , 0x40f000f3 ) ;
V_8 -> V_254 = V_498 ;
V_8 -> V_252 = F_181 ( V_6 ,
V_498 ,
V_494 - 1 ) ;
break;
case 0x111d7603 :
if ( ( V_6 -> V_497 & 0xf ) == 1 )
V_8 -> V_99 = 40 ;
default:
V_8 -> V_326 = V_492 ;
V_6 -> V_32 = V_493 ;
V_8 -> V_252 = F_181 ( V_6 ,
V_487 ,
V_494 ) ;
break;
}
if ( F_33 ( V_6 , 0xa ) & V_248 )
F_226 ( V_6 , V_475 ) ;
V_8 -> V_90 = V_499 ;
V_8 -> V_63 = 0x50 ;
V_8 -> V_68 = 0 ;
V_8 -> V_104 = 1 ;
V_8 -> V_282 = 0x26 ;
V_8 -> V_55 = V_500 ;
V_8 -> V_102 = V_501 ;
V_8 -> V_28 = V_502 ;
V_8 -> V_335 = V_481 ;
V_8 -> V_238 = F_110 ( V_500 ) ;
V_8 -> V_120 = F_110 ( V_501 ) ;
V_8 -> V_74 = F_110 ( V_488 ) ;
V_8 -> V_77 = F_221 ( V_6 , 0x1e ) ;
F_13 ( L_63 , V_8 -> V_381 ) ;
switch ( V_8 -> V_381 ) {
case V_495 :
F_44 ( V_6 , 0x0e , 0x01813040 ) ;
F_68 ( V_6 , 0x0e ,
V_43 | V_133 ) ;
case V_503 :
V_8 -> V_252 = 0 ;
V_8 -> V_77 = 0 ;
V_8 -> V_74 = 0 ;
break;
case V_504 :
case V_505 :
V_8 -> V_252 = 1 ;
V_8 -> V_77 = 0 ;
V_8 -> V_74 = 1 ;
break;
case V_506 :
V_8 -> V_252 = 1 ;
V_8 -> V_77 = 1 ;
V_8 -> V_74 = 1 ;
case V_507 :
V_8 -> V_324 = 0x01 ;
case V_508 :
F_44 ( V_6 , 0x0d , 0x90170010 ) ;
F_68 ( V_6 , 0x0d , V_44 ) ;
V_8 -> V_146 = 1 ;
break;
case V_509 :
V_8 -> V_252 = 1 ;
V_8 -> V_74 = 1 ;
V_8 -> V_77 = 1 ;
V_8 -> V_324 = 0x08 ;
break;
}
if ( F_191 ( V_6 -> V_353 ) ) {
V_477 = F_88 ( V_6 , 0x0f ) ;
if ( F_131 ( V_477 ) == V_510 ||
F_131 ( V_477 ) == V_297 ||
F_131 ( V_477 ) == V_511 ) {
V_477 = ( V_477 & ( ~ V_512 ) )
| ( V_511 <<
V_513 ) ;
V_477 = ( V_477 & ( ~ ( V_514
| V_515 ) ) )
| 0x1f ;
F_44 ( V_6 , 0x0f , V_477 ) ;
}
}
if ( F_189 ( V_6 , 1 ) )
F_103 ( L_61 ,
V_8 -> V_324 ,
V_8 -> V_323 ) ;
#ifdef F_220
if ( V_8 -> V_324 ) {
if ( ! V_8 -> V_336 ) {
V_8 -> V_318 |= V_8 -> V_324 ;
V_8 -> V_83 |= V_8 -> V_324 ;
V_8 -> V_320 |= V_8 -> V_324 ;
} else {
V_6 -> V_398 . V_468 =
F_203 ;
}
V_6 -> V_398 . V_469 = F_202 ;
V_6 -> V_398 . V_470 =
F_207 ;
}
#endif
V_8 -> V_30 . V_85 = V_8 -> V_85 ;
V_25 = F_140 ( V_6 ) ;
if ( ! V_25 ) {
if ( V_8 -> V_381 < 0 ) {
F_108 ( V_211 L_57
L_58 ) ;
V_8 -> V_381 = V_486 ;
goto V_405;
}
V_25 = - V_229 ;
}
if ( V_25 < 0 ) {
F_170 ( V_6 ) ;
return V_25 ;
}
if ( V_8 -> V_381 == V_507 ||
V_8 -> V_381 == V_508 ) {
unsigned int V_516 ;
V_516 = F_188 ( V_6 , 0x1 , V_358 ) ;
V_516 &= V_359 ;
if ( V_516 >= 6 )
F_224 ( V_6 ) ;
}
V_6 -> V_449 = F_195 ;
return 0 ;
}
static int F_227 ( struct V_5 * V_6 )
{
struct V_7 * V_8 ;
int V_25 ;
V_8 = F_209 ( sizeof( * V_8 ) , V_154 ) ;
if ( V_8 == NULL )
return - V_158 ;
V_6 -> V_379 = 1 ;
V_6 -> V_8 = V_8 ;
V_8 -> V_284 = 1 ;
V_8 -> V_93 = F_110 ( V_517 ) ;
V_8 -> V_94 = V_517 ;
V_8 -> V_381 = F_210 ( V_6 , V_518 ,
V_519 ,
V_520 ) ;
if ( V_8 -> V_381 == V_521 ) {
V_8 -> V_318 = V_8 -> V_83 = 0x03 ;
V_8 -> V_320 = 0x03 ;
F_108 ( V_385 L_64 , V_6 -> V_353 ) ;
switch ( V_6 -> V_353 ) {
case 0x106b0800 :
V_8 -> V_381 = V_522 ;
break;
case 0x106b0600 :
case 0x106b0700 :
V_8 -> V_381 = V_523 ;
break;
case 0x106b0e00 :
case 0x106b0f00 :
case 0x106b1600 :
case 0x106b1700 :
case 0x106b0200 :
case 0x106b1e00 :
V_8 -> V_381 = V_524 ;
break;
case 0x106b1a00 :
case 0x00000100 :
V_8 -> V_381 = V_525 ;
break;
case 0x106b0a00 :
case 0x106b2200 :
V_8 -> V_381 = V_526 ;
break;
default:
V_8 -> V_381 = V_524 ;
break;
}
}
V_405:
if ( V_8 -> V_381 < 0 )
F_13 ( V_385 L_56 ,
V_6 -> V_386 ) ;
else
F_43 ( V_6 ,
V_527 [ V_8 -> V_381 ] ) ;
V_8 -> V_102 = V_528 ;
V_8 -> V_55 = V_529 ;
V_8 -> V_238 = F_110 ( V_529 ) ;
V_8 -> V_120 = F_110 ( V_528 ) ;
V_8 -> V_252 = 0 ;
V_8 -> V_334 = 0 ;
V_8 -> V_326 = V_530 ;
V_8 -> V_239 = V_531 ;
V_8 -> V_240 = V_532 ;
V_8 -> V_285 = V_533 ;
V_8 -> V_30 . V_85 = V_8 -> V_85 ;
V_25 = F_140 ( V_6 ) ;
if ( ! V_25 ) {
if ( V_8 -> V_381 < 0 ) {
F_108 ( V_211 L_57
L_58 ) ;
V_8 -> V_381 = V_534 ;
goto V_405;
}
V_25 = - V_229 ;
}
if ( V_25 < 0 ) {
F_170 ( V_6 ) ;
return V_25 ;
}
V_6 -> V_398 = V_399 ;
F_228 ( V_6 , 0x12 , V_35 ,
( 0 << V_535 ) |
( 2 << V_208 ) |
( 0x27 << V_206 ) |
( 0 << V_234 ) ) ;
return 0 ;
}
static int F_229 ( struct V_5 * V_6 )
{
struct V_7 * V_8 ;
int V_25 ;
V_8 = F_209 ( sizeof( * V_8 ) , V_154 ) ;
if ( V_8 == NULL )
return - V_158 ;
V_6 -> V_379 = 1 ;
V_6 -> V_8 = V_8 ;
V_8 -> V_284 = 1 ;
V_6 -> V_32 = V_536 ;
V_8 -> V_93 = F_110 ( V_537 ) ;
V_8 -> V_94 = V_537 ;
V_8 -> V_381 = F_210 ( V_6 , V_538 ,
V_539 ,
V_540 ) ;
V_405:
if ( V_8 -> V_381 < 0 )
F_13 ( V_385 L_56 ,
V_6 -> V_386 ) ;
else
F_43 ( V_6 ,
V_541 [ V_8 -> V_381 ] ) ;
V_8 -> V_282 = 0x23 ;
V_8 -> V_102 = V_542 ;
V_8 -> V_120 = F_110 ( V_542 ) ;
V_8 -> V_55 = V_543 ;
V_8 -> V_238 = F_110 ( V_543 ) ;
V_8 -> V_28 = V_544 ;
V_8 -> V_77 = F_110 ( V_544 ) ;
V_8 -> V_243 = V_545 ;
V_8 -> V_314 = V_546 ;
V_8 -> V_30 . V_85 = V_8 -> V_85 ;
if ( V_8 -> V_381 != V_547 ) {
V_8 -> V_319 = V_8 -> V_318 = 0x01 ;
V_8 -> V_83 = V_8 -> V_320 = 0x01 ;
}
switch ( V_8 -> V_381 ) {
case V_548 :
case V_549 :
V_8 -> V_252 = 0 ;
V_8 -> V_326 = V_550 ;
break;
case V_551 :
switch ( V_6 -> V_353 ) {
case 0x10280209 :
case 0x1028022e :
F_44 ( V_6 , 0x21 , 0x01442070 ) ;
break;
}
F_44 ( V_6 , 0x0c , 0x90a79130 ) ;
F_44 ( V_6 , 0x0f , 0x0227011f ) ;
F_44 ( V_6 , 0x0e , 0x02a79130 ) ;
case V_552 :
if ( V_6 -> V_353 != 0x1028022f ) {
V_8 -> V_319 = V_8 -> V_318 = 0x04 ;
V_8 -> V_83 = V_8 -> V_320 = 0x04 ;
}
V_8 -> V_254 = V_553 ;
V_8 -> V_252 = V_554 ;
V_8 -> V_326 = V_555 ;
V_8 -> V_18 = V_556 ;
V_8 -> V_74 = F_110 ( V_556 ) ;
break;
case V_557 :
V_8 -> V_252 = 0 ;
V_8 -> V_326 = V_558 ;
break;
default:
V_8 -> V_252 = 0 ;
V_8 -> V_326 = V_559 ;
break;
}
V_8 -> V_239 = V_560 ;
V_8 -> V_240 = V_561 ;
V_8 -> V_285 = V_562 ;
V_8 -> V_334 = 0 ;
V_8 -> V_90 = V_563 ;
V_8 -> V_63 = 0x40 ;
V_8 -> V_68 = 0 ;
V_8 -> V_322 = 1 ;
V_25 = F_140 ( V_6 ) ;
if ( ! V_25 ) {
if ( V_8 -> V_381 < 0 ) {
F_108 ( V_211 L_57
L_58 ) ;
V_8 -> V_381 = V_547 ;
goto V_405;
}
V_25 = - V_229 ;
}
if ( V_25 < 0 ) {
F_170 ( V_6 ) ;
return V_25 ;
}
V_6 -> V_398 = V_399 ;
V_6 -> V_449 = F_197 ;
V_6 -> V_341 -> V_564 = 1 ;
if ( V_8 -> V_381 == V_565 )
V_8 -> V_146 = 0 ;
return 0 ;
}
static int F_230 ( struct V_5 * V_6 )
{
struct V_7 * V_8 ;
int V_25 ;
V_8 = F_209 ( sizeof( * V_8 ) , V_154 ) ;
if ( V_8 == NULL )
return - V_158 ;
V_6 -> V_379 = 1 ;
V_6 -> V_8 = V_8 ;
V_8 -> V_284 = 1 ;
V_8 -> V_93 = F_110 ( V_566 ) ;
V_8 -> V_94 = V_566 ;
V_8 -> V_381 = F_210 ( V_6 , V_567 ,
V_568 ,
V_569 ) ;
V_405:
if ( V_8 -> V_381 < 0 )
F_13 ( V_385 L_56 ,
V_6 -> V_386 ) ;
else
F_43 ( V_6 ,
V_570 [ V_8 -> V_381 ] ) ;
V_8 -> V_282 = 0x23 ;
V_8 -> V_102 = V_571 ;
V_8 -> V_120 = F_110 ( V_571 ) ;
V_8 -> V_55 = V_572 ;
V_8 -> V_238 = F_110 ( V_572 ) ;
V_8 -> V_28 = V_573 ;
V_8 -> V_77 = F_110 ( V_573 ) ;
V_8 -> V_254 = V_574 ;
V_8 -> V_252 = V_575 ;
V_8 -> V_18 = V_576 ;
V_8 -> V_74 = F_110 ( V_576 ) ;
V_8 -> V_334 = 0 ;
V_8 -> V_326 = V_577 ;
V_8 -> V_90 = V_578 ;
V_8 -> V_239 = V_579 ;
V_8 -> V_240 = V_580 ;
V_8 -> V_285 = V_581 ;
V_8 -> V_63 = 0x40 ;
V_8 -> V_68 = 0 ;
if ( V_8 -> V_381 != V_582 )
V_8 -> V_322 = 1 ;
V_8 -> V_30 . V_85 = V_8 -> V_85 ;
switch ( V_8 -> V_381 ) {
case V_583 :
F_44 ( V_6 , 0x1f , 0x01441030 ) ;
F_44 ( V_6 , 0x20 , 0x1c410030 ) ;
V_25 = F_148 ( V_6 , V_6 -> V_66 , V_354 , 0x01 ) ;
if ( V_25 < 0 )
return V_25 ;
F_15 ( V_6 , V_6 -> V_66 , 0 ,
V_496 , 0x10 ) ;
F_151 ( V_6 , V_6 -> V_66 , 0 ) ;
V_8 -> V_83 = 0x0b ;
V_8 -> V_319 = 0x01 ;
V_8 -> V_318 = 0x1b ;
V_8 -> V_321 = 0x10 ;
V_8 -> V_320 = 0x01 ;
break;
case V_584 :
break;
default:
V_8 -> V_319 = V_8 -> V_318 = V_8 -> V_83 = 0x1 ;
V_8 -> V_320 = 0x01 ;
break;
}
V_25 = F_140 ( V_6 ) ;
if ( ! V_25 ) {
if ( V_8 -> V_381 < 0 ) {
F_108 ( V_211 L_57
L_58 ) ;
V_8 -> V_381 = V_584 ;
goto V_405;
}
V_25 = - V_229 ;
}
if ( V_25 < 0 ) {
F_170 ( V_6 ) ;
return V_25 ;
}
V_6 -> V_398 = V_399 ;
V_6 -> V_449 = F_196 ;
return 0 ;
}
static int F_231 ( struct V_5 * V_6 )
{
struct V_7 * V_8 ;
int V_25 ;
V_8 = F_209 ( sizeof( * V_8 ) , V_154 ) ;
if ( V_8 == NULL )
return - V_158 ;
V_6 -> V_379 = 1 ;
V_6 -> V_8 = V_8 ;
V_8 -> V_284 = 1 ;
V_8 -> V_93 = F_110 ( V_585 ) ;
V_8 -> V_94 = V_585 ;
V_8 -> V_381 = F_210 ( V_6 , V_586 ,
V_587 ,
V_588 ) ;
if ( V_8 -> V_381 < 0 )
F_13 ( V_385 L_56 ,
V_6 -> V_386 ) ;
else
F_43 ( V_6 ,
V_589 [ V_8 -> V_381 ] ) ;
V_8 -> V_30 . V_85 = V_8 -> V_85 ;
V_8 -> V_120 = F_110 ( V_590 ) ;
V_8 -> V_102 = V_590 ;
V_8 -> V_238 = F_110 ( V_591 ) ;
V_8 -> V_55 = V_591 ;
V_8 -> V_326 = V_592 ;
V_8 -> V_239 = 1 ;
V_8 -> V_240 = V_593 ;
V_8 -> V_285 = V_594 ;
V_25 = F_140 ( V_6 ) ;
if ( V_25 < 0 ) {
F_170 ( V_6 ) ;
return - V_229 ;
}
V_8 -> V_47 = & V_8 -> V_165 ;
V_6 -> V_398 = V_399 ;
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
