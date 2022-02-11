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
error = F_15 ( V_6 , V_27 , V_37 ) ;
if ( error < 0 )
return error ;
return 1 ;
}
static unsigned int F_16 ( struct V_5 * V_6 ,
T_1 V_27 , unsigned int V_36 )
{
int error ;
unsigned int V_41 ;
V_41 = F_14 ( V_6 , V_27 , 0 ,
V_39 , 0 ) ;
V_41 &= 0xff ;
V_41 &= ~ ( V_40 | V_42 | V_43 ) ;
V_41 |= V_36 ;
if ( V_36 == V_44 )
V_41 |= V_43 ;
else
V_41 |= V_42 ;
error = F_15 ( V_6 , V_27 , V_41 ) ;
if ( error < 0 )
return error ;
else
return 1 ;
}
static unsigned int F_17 ( struct V_5 * V_6 , T_1 V_27 )
{
unsigned int V_45 ;
V_45 = F_14 ( V_6 , V_27 , 0 ,
V_39 , 0 ) ;
V_45 &= V_40 ;
return V_45 ;
}
static int F_18 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = V_6 -> V_8 ;
return F_3 ( V_8 -> V_46 , V_4 ) ;
}
static int F_19 ( struct V_1 * V_2 , struct V_10 * V_11 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = V_6 -> V_8 ;
unsigned int V_47 = F_5 ( V_2 , & V_11 -> V_13 ) ;
V_11 -> V_14 . V_15 . V_16 [ 0 ] = V_8 -> V_48 [ V_47 ] ;
return 0 ;
}
static int F_20 ( struct V_1 * V_2 , struct V_10 * V_11 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = V_6 -> V_8 ;
unsigned int V_47 = F_5 ( V_2 , & V_11 -> V_13 ) ;
const struct V_22 * V_49 = V_8 -> V_46 ;
unsigned int V_50 , V_51 , V_52 ;
V_50 = V_11 -> V_14 . V_15 . V_16 [ 0 ] ;
if ( V_50 >= V_49 -> V_33 )
V_50 = V_49 -> V_33 - 1 ;
V_51 = V_8 -> V_48 [ V_47 ] ;
if ( V_51 == V_50 )
return 0 ;
if ( V_50 < V_8 -> V_53 ) {
F_21 ( V_6 , V_8 -> V_54 [ V_47 ] , 0 ,
V_55 ,
V_49 -> V_56 [ V_50 ] . V_57 ) ;
if ( V_51 >= V_8 -> V_53 &&
V_8 -> V_54 [ V_47 ] != V_8 -> V_18 [ V_47 ] ) {
V_49 = V_8 -> V_9 ;
F_21 ( V_6 ,
V_8 -> V_18 [ V_47 ] , 0 ,
V_55 ,
V_49 -> V_56 [ 0 ] . V_57 ) ;
}
} else {
V_49 = V_8 -> V_9 ;
V_52 = V_50 - V_8 -> V_53 + 1 ;
F_21 ( V_6 , V_8 -> V_18 [ V_47 ] , 0 ,
V_55 ,
V_49 -> V_56 [ V_52 ] . V_57 ) ;
}
V_8 -> V_48 [ V_47 ] = V_50 ;
return 1 ;
}
static int F_22 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = V_6 -> V_8 ;
return F_3 ( V_8 -> V_58 , V_4 ) ;
}
static int F_23 ( struct V_1 * V_2 ,
struct V_10 * V_11 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = V_6 -> V_8 ;
V_11 -> V_14 . V_15 . V_16 [ 0 ] = V_8 -> V_59 ;
return 0 ;
}
static int F_24 ( struct V_1 * V_2 ,
struct V_10 * V_11 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = V_6 -> V_8 ;
return F_7 ( V_6 , V_8 -> V_58 , V_11 ,
V_8 -> V_60 , & V_8 -> V_59 ) ;
}
static int F_25 ( struct V_1 * V_2 ,
struct V_10 * V_11 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
unsigned int V_50 = F_5 ( V_2 , & V_11 -> V_13 ) ;
struct V_7 * V_8 = V_6 -> V_8 ;
V_11 -> V_14 . integer . V_14 [ 0 ] = ! ! ( V_8 -> V_61 &
( V_8 -> V_62 << V_50 ) ) ;
return 0 ;
}
static int F_26 ( struct V_1 * V_2 ,
struct V_10 * V_11 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = V_6 -> V_8 ;
unsigned int V_50 = F_5 ( V_2 , & V_11 -> V_13 ) ;
unsigned int V_63 ;
unsigned int V_26 , V_64 ;
V_64 = V_8 -> V_62 << V_50 ;
if ( V_11 -> V_14 . integer . V_14 [ 0 ] )
V_26 = V_8 -> V_61 | V_64 ;
else
V_26 = V_8 -> V_61 & ~ V_64 ;
if ( V_8 -> V_61 == V_26 )
return 0 ;
V_8 -> V_61 = V_26 ;
V_63 = F_14 ( V_6 , V_6 -> V_65 , 0 ,
V_2 -> V_66 & 0xFFFF , 0x0 ) ;
V_63 >>= V_8 -> V_67 ;
if ( V_8 -> V_61 & V_64 ) {
F_27 ( V_6 ) ;
V_63 |= V_64 ;
} else {
F_28 ( V_6 ) ;
V_63 &= ~ V_64 ;
}
F_21 ( V_6 , V_6 -> V_65 , 0 ,
V_2 -> V_66 >> 16 , V_63 ) ;
return 1 ;
}
static void F_29 ( void * V_68 , int V_26 )
{
F_30 ( V_68 , V_26 ) ;
}
static int F_31 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
unsigned int V_69 [ 4 ] ;
int V_25 ;
int V_70 ;
if ( V_8 -> V_71 ) {
V_25 = F_32 ( V_6 , V_8 -> V_71 ) ;
if ( V_25 < 0 )
return V_25 ;
}
for ( V_70 = 0 ; V_70 < V_8 -> V_72 ; V_70 ++ ) {
V_25 = F_32 ( V_6 , V_8 -> V_73 [ V_70 ] ) ;
if ( V_25 < 0 )
return V_25 ;
}
if ( ! V_8 -> V_74 && V_8 -> V_75 > 0 &&
F_33 ( V_6 , L_2 ) == 1 ) {
V_76 . V_77 = V_8 -> V_75 ;
V_25 = F_34 ( V_6 , 0 ,
F_35 ( & V_76 , V_6 ) ) ;
if ( V_25 < 0 )
return V_25 ;
}
if ( V_8 -> V_78 > 0 ) {
int V_79 = F_36 ( V_6 , V_8 -> V_30 . V_31 ) ;
struct V_22 * V_23 = & V_8 -> V_24 ;
if ( V_79 & V_80 ) {
F_37 ( V_23 , L_3 , 0 , NULL ) ;
V_8 -> V_29 = 1 ;
}
V_81 . V_77 = V_8 -> V_78 ;
V_25 = F_34 ( V_6 , 0 ,
F_35 ( & V_81 , V_6 ) ) ;
if ( V_25 < 0 )
return V_25 ;
}
if ( V_8 -> V_30 . V_31 ) {
V_25 = F_38 ( V_6 ,
V_8 -> V_30 . V_31 ,
V_8 -> V_30 . V_31 ,
V_8 -> V_82 . V_83 [ 0 ] ) ;
if ( V_25 < 0 )
return V_25 ;
V_25 = F_39 ( V_6 ,
& V_8 -> V_30 ) ;
if ( V_25 < 0 )
return V_25 ;
V_8 -> V_30 . V_84 = 1 ;
}
if ( V_8 -> V_85 && ! ( V_8 -> V_86 & 0x01 ) ) {
V_25 = F_40 ( V_6 , V_8 -> V_85 ) ;
if ( V_25 < 0 )
return V_25 ;
}
F_41 ( V_6 , V_8 -> V_30 . V_87 [ 0 ] ,
V_35 , V_69 ) ;
V_69 [ 2 ] += V_69 [ 3 ] * V_8 -> V_88 ;
V_69 [ 3 ] |= V_89 ;
V_25 = F_42 ( V_6 , L_4 ,
V_69 , V_90 ,
L_5 ) ;
if ( V_25 < 0 )
return V_25 ;
V_25 = F_43 ( V_6 , L_6 ,
NULL , V_90 ,
L_7 , true ,
& V_8 -> V_91 . V_92 ) ;
if ( V_25 < 0 )
return V_25 ;
if ( V_8 -> V_93 ) {
V_8 -> V_91 . V_94 = F_29 ;
V_25 = F_44 ( V_6 , & V_8 -> V_91 , true ) ;
if ( V_25 < 0 )
return V_25 ;
}
if ( V_8 -> V_95 &&
F_33 ( V_6 , L_8 ) == 1 ) {
V_25 = F_32 ( V_6 , V_8 -> V_95 ) ;
if ( V_25 < 0 )
return V_25 ;
}
F_45 ( V_6 ) ;
V_25 = F_46 ( V_6 , & V_8 -> V_82 ) ;
if ( V_25 < 0 )
return V_25 ;
return 0 ;
}
static void F_47 ( struct V_5 * V_6 ,
const unsigned int * V_96 )
{
int V_70 ;
struct V_7 * V_8 = V_6 -> V_8 ;
if ( ! V_96 )
return;
for ( V_70 = 0 ; V_70 < V_8 -> V_97 ; V_70 ++ )
if ( V_8 -> V_98 [ V_70 ] && V_96 [ V_70 ] )
F_48 ( V_6 , V_8 -> V_98 [ V_70 ] ,
V_96 [ V_70 ] ) ;
}
static int F_49 ( struct V_99 * V_100 ,
struct V_5 * V_6 ,
struct V_101 * V_102 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
if ( V_8 -> V_103 )
F_50 ( V_8 -> V_103 ) ;
return F_51 ( V_6 , & V_8 -> V_30 , V_102 ,
V_100 ) ;
}
static int F_52 ( struct V_99 * V_100 ,
struct V_5 * V_6 ,
unsigned int V_104 ,
unsigned int V_105 ,
struct V_101 * V_102 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
return F_53 ( V_6 , & V_8 -> V_30 , V_104 , V_105 , V_102 ) ;
}
static int F_54 ( struct V_99 * V_100 ,
struct V_5 * V_6 ,
struct V_101 * V_102 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
return F_55 ( V_6 , & V_8 -> V_30 ) ;
}
static int F_56 ( struct V_99 * V_100 ,
struct V_5 * V_6 ,
struct V_101 * V_102 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
return F_57 ( V_6 , & V_8 -> V_30 ) ;
}
static int F_58 ( struct V_99 * V_100 ,
struct V_5 * V_6 ,
struct V_101 * V_102 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
return F_59 ( V_6 , & V_8 -> V_30 ) ;
}
static int F_60 ( struct V_99 * V_100 ,
struct V_5 * V_6 ,
unsigned int V_104 ,
unsigned int V_105 ,
struct V_101 * V_102 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
return F_61 ( V_6 , & V_8 -> V_30 ,
V_104 , V_105 , V_102 ) ;
}
static int F_62 ( struct V_99 * V_100 ,
struct V_5 * V_6 ,
struct V_101 * V_102 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
return F_63 ( V_6 , & V_8 -> V_30 ) ;
}
static int F_64 ( struct V_99 * V_100 ,
struct V_5 * V_6 ,
unsigned int V_104 ,
unsigned int V_105 ,
struct V_101 * V_102 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
T_1 V_27 = V_8 -> V_106 [ V_102 -> V_107 ] ;
if ( V_8 -> V_108 ) {
F_50 ( 40 ) ;
F_65 ( V_6 , V_27 , 0 ,
V_109 , V_110 ) ;
}
F_66 ( V_6 , V_27 , V_104 , 0 , V_105 ) ;
return 0 ;
}
static int F_67 ( struct V_99 * V_100 ,
struct V_5 * V_6 ,
struct V_101 * V_102 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
T_1 V_27 = V_8 -> V_106 [ V_102 -> V_107 ] ;
F_68 ( V_6 , V_27 ) ;
if ( V_8 -> V_108 )
F_65 ( V_6 , V_27 , 0 ,
V_109 , V_111 ) ;
return 0 ;
}
static int F_69 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
struct V_112 * V_113 = V_8 -> V_114 ;
V_6 -> V_115 = 1 ;
V_6 -> V_116 = V_113 ;
V_113 -> V_117 = L_9 ;
V_113 -> V_118 [ V_119 ] = V_120 ;
V_113 -> V_118 [ V_119 ] . V_27 =
V_8 -> V_30 . V_87 [ 0 ] ;
if ( V_8 -> V_82 . V_121 == V_122 &&
V_8 -> V_82 . V_123 == 2 )
V_113 -> V_118 [ V_119 ] . V_124 =
V_125 ;
V_113 -> V_118 [ V_126 ] = V_127 ;
V_113 -> V_118 [ V_126 ] . V_27 = V_8 -> V_106 [ 0 ] ;
V_113 -> V_118 [ V_126 ] . V_128 = V_8 -> V_129 ;
if ( V_8 -> V_130 ) {
V_6 -> V_115 ++ ;
V_113 ++ ;
V_113 -> V_117 = L_10 ;
V_113 -> V_118 [ V_119 ] = V_131 ;
}
if ( V_8 -> V_30 . V_31 || V_8 -> V_85 ) {
V_6 -> V_115 ++ ;
V_113 ++ ;
V_113 -> V_117 = L_11 ;
V_113 -> V_132 = V_8 -> V_82 . V_83 [ 0 ] ;
if ( V_8 -> V_30 . V_31 ) {
V_113 -> V_118 [ V_119 ] = V_133 ;
V_113 -> V_118 [ V_119 ] . V_27 = V_8 -> V_30 . V_31 ;
}
if ( V_8 -> V_85 ) {
V_113 -> V_118 [ V_126 ] = V_134 ;
V_113 -> V_118 [ V_126 ] . V_27 = V_8 -> V_85 ;
}
}
return 0 ;
}
static void F_70 ( struct V_5 * V_6 , T_1 V_27 , int V_135 )
{
F_15 ( V_6 , V_27 , V_135 ) ;
}
static int F_71 ( struct V_1 * V_2 ,
struct V_10 * V_11 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = V_6 -> V_8 ;
V_11 -> V_14 . integer . V_14 [ 0 ] = ! ! V_8 -> V_136 ;
return 0 ;
}
static int F_72 ( struct V_1 * V_2 ,
struct V_10 * V_11 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = V_6 -> V_8 ;
int V_27 = V_2 -> V_66 ;
V_8 -> V_136 = V_11 -> V_14 . integer . V_14 [ 0 ] ? V_27 : 0 ;
F_73 ( V_6 , V_27 ) ;
return 1 ;
}
static int F_74 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
int V_70 ;
static const char * const V_137 [] = {
L_12 , L_13 , L_14
} ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = V_6 -> V_8 ;
T_1 V_27 = V_2 -> V_66 ;
if ( V_27 == V_8 -> V_138 || V_27 == V_8 -> V_139 )
V_70 = 3 ;
else
V_70 = 2 ;
V_4 -> type = V_140 ;
V_4 -> V_14 . V_15 . V_56 = V_70 ;
V_4 -> V_77 = 1 ;
if ( V_4 -> V_14 . V_15 . V_16 >= V_70 )
V_4 -> V_14 . V_15 . V_16 = V_70 - 1 ;
strcpy ( V_4 -> V_14 . V_15 . V_117 ,
V_137 [ V_4 -> V_14 . V_15 . V_16 ] ) ;
return 0 ;
}
static int F_75 ( struct V_1 * V_2 ,
struct V_10 * V_11 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
T_1 V_27 = V_2 -> V_66 ;
unsigned int V_45 = F_17 ( V_6 , V_27 ) ;
if ( V_45 == F_76 ( V_6 , V_27 ) )
V_11 -> V_14 . V_15 . V_16 [ 0 ] = 0 ;
else if ( V_45 == V_141 )
V_11 -> V_14 . V_15 . V_16 [ 0 ] = 1 ;
else if ( V_45 == V_44 )
V_11 -> V_14 . V_15 . V_16 [ 0 ] = 2 ;
return 0 ;
}
static int F_77 ( struct V_1 * V_2 ,
struct V_10 * V_11 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
unsigned int V_36 = 0 ;
int error ;
T_1 V_27 = V_2 -> V_66 ;
if ( V_11 -> V_14 . V_15 . V_16 [ 0 ] == 0 )
V_36 = F_76 ( V_6 , V_27 ) ;
else if ( V_11 -> V_14 . V_15 . V_16 [ 0 ] == 1 )
V_36 = V_141 ;
else if ( V_11 -> V_14 . V_15 . V_16 [ 0 ] == 2 )
V_36 = V_44 ;
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
char * V_137 [ 2 ] ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = V_6 -> V_8 ;
if ( V_2 -> V_66 == V_8 -> V_139 )
V_137 [ 0 ] = L_13 ;
else
V_137 [ 0 ] = L_12 ;
V_137 [ 1 ] = L_14 ;
V_4 -> type = V_140 ;
V_4 -> V_14 . V_15 . V_56 = 2 ;
V_4 -> V_77 = 1 ;
if ( V_4 -> V_14 . V_15 . V_16 >= 2 )
V_4 -> V_14 . V_15 . V_16 = 1 ;
strcpy ( V_4 -> V_14 . V_15 . V_117 ,
V_137 [ V_4 -> V_14 . V_15 . V_16 ] ) ;
return 0 ;
}
static int F_79 ( struct V_1 * V_2 , struct V_10 * V_11 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = V_6 -> V_8 ;
T_1 V_27 = V_2 -> V_66 ;
int V_142 = ( V_27 == V_8 -> V_138 ) ? 1 : 0 ;
V_11 -> V_14 . V_15 . V_16 [ 0 ] = V_8 -> V_143 [ V_142 ] ;
return 0 ;
}
static int F_80 ( struct V_1 * V_2 , struct V_10 * V_11 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = V_6 -> V_8 ;
T_1 V_27 = V_2 -> V_66 ;
int V_142 = ( V_27 == V_8 -> V_138 ) ? 1 : 0 ;
unsigned short V_26 = ! ! V_11 -> V_14 . V_15 . V_16 [ 0 ] ;
V_8 -> V_143 [ V_142 ] = V_26 ;
if ( V_26 )
F_70 ( V_6 , V_27 , V_43 ) ;
else {
unsigned int V_37 = V_42 ;
if ( V_142 )
V_37 |= F_76 ( V_6 , V_27 ) ;
F_70 ( V_6 , V_27 , V_37 ) ;
}
if ( V_8 -> V_144 )
F_73 ( V_6 , V_27 ) ;
return 1 ;
}
static int F_81 ( struct V_1 * V_2 ,
struct V_10 * V_11 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = V_6 -> V_8 ;
V_11 -> V_14 . integer . V_14 [ 0 ] = V_8 -> V_145 ;
return 0 ;
}
static int F_82 ( struct V_1 * V_2 ,
struct V_10 * V_11 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = V_6 -> V_8 ;
T_1 V_27 = V_2 -> V_66 & 0xff ;
unsigned int V_26 = ! ! V_11 -> V_14 . integer . V_14 [ 0 ] ;
if ( V_8 -> V_145 == V_26 )
return 0 ;
V_8 -> V_145 = V_26 ;
F_21 ( V_6 , V_27 , 0 , V_146 ,
V_8 -> V_145 ? 0x4 : 0x0 ) ;
return 1 ;
}
static struct V_147 *
F_83 ( struct V_7 * V_8 ,
const struct V_147 * V_148 ,
const char * V_117 ,
unsigned int V_149 )
{
struct V_147 * V_150 ;
V_150 = F_84 ( & V_8 -> V_151 ) ;
if ( ! V_150 )
return NULL ;
* V_150 = * V_148 ;
V_150 -> V_117 = F_85 ( V_117 , V_152 ) ;
if ( ! V_150 -> V_117 ) {
memset ( V_150 , 0 , sizeof( * V_150 ) ) ;
V_8 -> V_151 . V_153 -- ;
return NULL ;
}
V_150 -> V_154 = V_149 ;
return V_150 ;
}
static struct V_147 *
F_86 ( struct V_7 * V_8 ,
const struct V_147 * V_148 ,
int V_50 , const char * V_117 ,
unsigned long V_26 )
{
struct V_147 * V_150 = F_83 ( V_8 , V_148 , V_117 ,
V_155 ) ;
if ( ! V_150 )
return NULL ;
V_150 -> V_57 = V_50 ;
V_150 -> V_66 = V_26 ;
return V_150 ;
}
static int F_87 ( struct V_7 * V_8 ,
const struct V_147 * V_148 ,
int V_50 , const char * V_117 ,
unsigned long V_26 )
{
return F_86 ( V_8 , V_148 , V_50 , V_117 , V_26 ) ? 0 : - V_156 ;
}
static inline int F_88 ( struct V_7 * V_8 ,
int type , int V_50 , const char * V_117 ,
unsigned long V_26 )
{
return F_87 ( V_8 ,
& V_157 [ type ] ,
V_50 , V_117 , V_26 ) ;
}
static inline int F_89 ( struct V_7 * V_8 , int type ,
const char * V_117 , unsigned long V_26 )
{
return F_88 ( V_8 , type , 0 , V_117 , V_26 ) ;
}
static inline int F_90 ( struct V_5 * V_6 ,
T_1 V_27 , int V_50 )
{
int V_158 = F_91 ( V_6 , V_27 ) ;
int V_159 = 0 ;
struct V_7 * V_8 = V_6 -> V_8 ;
char V_117 [ 22 ] ;
if ( F_92 ( V_158 ) != V_160 ) {
if ( V_8 -> V_161 && F_92 ( V_158 )
!= V_162 )
return 0 ;
if ( F_76 ( V_6 , V_27 ) == V_141
&& V_27 == V_8 -> V_139 )
V_159 = V_163 ;
else if ( F_93 ( V_6 , V_27 )
& ( V_164 << V_165 ) )
V_159 = V_166 ;
else if ( V_27 == V_8 -> V_138 )
V_159 = V_163 ;
}
if ( V_159 ) {
F_94 ( V_6 , V_27 , & V_8 -> V_82 ,
V_117 , sizeof( V_117 ) , NULL ) ;
return F_89 ( V_6 -> V_8 , V_159 ,
strcat ( V_117 , L_15 ) , V_27 ) ;
}
return 0 ;
}
static int F_95 ( struct V_7 * V_8 )
{
struct V_147 * V_150 ;
struct V_22 * V_49 = & V_8 -> V_167 ;
if ( V_8 -> V_74 )
return 0 ;
if ( ! V_8 -> V_129 || V_49 -> V_33 <= 1 )
return 0 ;
V_150 = F_83 ( V_8 , & V_168 ,
V_168 . V_117 , 0 ) ;
if ( ! V_150 )
return - V_156 ;
V_150 -> V_77 = V_8 -> V_129 ;
return 0 ;
}
static T_1 F_96 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
struct V_169 * V_170 = & V_8 -> V_82 ;
T_1 V_27 ;
unsigned int V_171 ;
int V_70 ;
if ( V_170 -> V_121 != V_172 )
return 0 ;
for ( V_70 = 0 ; V_70 < V_170 -> V_173 ; V_70 ++ ) {
if ( V_170 -> V_174 [ V_70 ] . type == V_175 ) {
V_27 = V_170 -> V_174 [ V_70 ] . V_176 ;
V_171 = F_93 ( V_6 , V_27 ) ;
if ( V_171 & V_177 )
return V_27 ;
}
}
return 0 ;
}
static T_1 F_97 ( struct V_5 * V_6 , T_1 * V_178 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
struct V_169 * V_170 = & V_8 -> V_82 ;
unsigned int V_158 , V_171 ;
int V_70 ;
* V_178 = 0 ;
if ( V_170 -> V_121 != V_172 )
return 0 ;
for ( V_70 = 0 ; V_70 < V_170 -> V_173 ; V_70 ++ ) {
T_1 V_27 = V_170 -> V_174 [ V_70 ] . V_176 ;
if ( V_170 -> V_174 [ V_70 ] . type != V_179 )
continue;
V_158 = F_91 ( V_6 , V_27 ) ;
if ( F_92 ( V_158 ) != V_160 ) {
V_171 = F_93 ( V_6 , V_27 ) ;
if ( V_171 & V_177 ) {
* V_178 = F_98 ( V_6 , V_27 ) ;
if ( * V_178 )
return V_27 ;
}
}
}
return 0 ;
}
static int F_99 ( struct V_7 * V_8 , T_1 V_27 )
{
int V_70 ;
for ( V_70 = 0 ; V_70 < V_8 -> V_30 . V_180 ; V_70 ++ ) {
if ( V_8 -> V_30 . V_87 [ V_70 ] == V_27 )
return 1 ;
}
return 0 ;
}
static int F_100 ( struct V_7 * V_8 , T_1 V_27 )
{
int V_70 ;
if ( F_99 ( V_8 , V_27 ) )
return 1 ;
for ( V_70 = 0 ; V_70 < V_8 -> V_82 . V_181 ; V_70 ++ )
if ( V_8 -> V_182 [ V_70 ] == V_27 )
return 1 ;
for ( V_70 = 0 ; V_70 < V_8 -> V_82 . V_183 ; V_70 ++ )
if ( V_8 -> V_184 [ V_70 ] == V_27 )
return 1 ;
return 0 ;
}
static T_1 F_98 ( struct V_5 * V_6 , T_1 V_27 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
struct V_169 * V_170 = & V_8 -> V_82 ;
int V_185 , V_186 ;
T_1 V_187 [ V_188 ] , V_189 ;
unsigned int V_79 , V_190 ;
V_186 = F_101 ( V_6 , V_27 , V_187 ,
V_188 ) ;
while ( V_186 == 1 && ( F_102 ( F_36 ( V_6 , V_187 [ 0 ] ) )
!= V_191 ) ) {
V_27 = V_187 [ 0 ] ;
V_186 = F_101 ( V_6 , V_27 , V_187 ,
V_188 ) ;
}
for ( V_185 = 0 ; V_185 < V_186 ; V_185 ++ ) {
V_79 = F_36 ( V_6 , V_187 [ V_185 ] ) ;
V_190 = F_102 ( V_79 ) ;
if ( V_190 != V_191 || ( V_79 & V_192 ) )
continue;
if ( ! F_100 ( V_8 , V_187 [ V_185 ] ) ) {
if ( V_186 > 1 ) {
F_21 ( V_6 , V_27 , 0 ,
V_55 , V_185 ) ;
}
return V_187 [ V_185 ] ;
}
}
V_189 = V_8 -> V_30 . V_87 [ 0 ] ;
if ( V_8 -> V_30 . V_193 ) {
for ( V_185 = 0 ; V_185 < V_170 -> V_181 ; V_185 ++ )
if ( V_170 -> V_194 [ V_185 ] == V_27 ) {
V_189 = V_8 -> V_30 . V_193 ;
break;
}
}
if ( V_186 > 1 ) {
for ( V_185 = 0 ; V_185 < V_186 ; V_185 ++ ) {
if ( V_187 [ V_185 ] == V_189 ) {
F_21 ( V_6 , V_27 , 0 ,
V_55 , V_185 ) ;
break;
}
}
}
return 0 ;
}
static int F_103 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
struct V_169 * V_170 = & V_8 -> V_82 ;
int V_70 ;
T_1 V_27 , V_178 ;
for ( V_70 = 0 ; V_70 < V_170 -> V_123 ; V_70 ++ ) {
V_27 = V_170 -> V_195 [ V_70 ] ;
V_178 = F_98 ( V_6 , V_27 ) ;
if ( ! V_178 ) {
if ( V_8 -> V_30 . V_180 > 0 ) {
V_170 -> V_123 = V_8 -> V_30 . V_180 ;
break;
}
F_104 ( V_196
L_16 ,
V_38 , V_27 ) ;
return - V_197 ;
}
F_105 ( V_8 , V_178 ) ;
}
for ( V_70 = 0 ; V_70 < V_170 -> V_181 ; V_70 ++ ) {
V_27 = V_170 -> V_194 [ V_70 ] ;
V_178 = F_98 ( V_6 , V_27 ) ;
if ( V_178 ) {
if ( ! V_8 -> V_30 . V_193 )
V_8 -> V_30 . V_193 = V_178 ;
else
F_106 ( V_8 , V_178 ) ;
}
V_8 -> V_182 [ V_70 ] = V_178 ;
}
for ( V_70 = 0 ; V_70 < V_170 -> V_183 ; V_70 ++ ) {
V_27 = V_170 -> V_198 [ V_70 ] ;
V_178 = F_98 ( V_6 , V_27 ) ;
if ( V_178 )
F_106 ( V_8 , V_178 ) ;
V_8 -> V_184 [ V_70 ] = V_178 ;
}
V_27 = F_96 ( V_6 ) ;
if ( V_27 ) {
V_178 = F_98 ( V_6 , V_27 ) ;
if ( V_178 ) {
F_13 ( L_17 ,
V_27 , V_170 -> V_123 ) ;
V_170 -> V_195 [ V_170 -> V_123 ] = V_27 ;
V_170 -> V_123 ++ ;
V_8 -> V_139 = V_27 ;
F_105 ( V_8 , V_178 ) ;
}
}
V_27 = F_97 ( V_6 , & V_178 ) ;
if ( V_27 && V_178 ) {
F_13 ( L_18 ,
V_27 , V_170 -> V_123 ) ;
V_170 -> V_195 [ V_170 -> V_123 ] = V_27 ;
V_170 -> V_123 ++ ;
V_8 -> V_138 = V_27 ;
F_105 ( V_8 , V_178 ) ;
}
F_107 ( L_19 ,
V_8 -> V_30 . V_180 ,
V_8 -> V_30 . V_87 [ 0 ] ,
V_8 -> V_30 . V_87 [ 1 ] ,
V_8 -> V_30 . V_87 [ 2 ] ,
V_8 -> V_30 . V_87 [ 3 ] ,
V_8 -> V_30 . V_87 [ 4 ] ) ;
return 0 ;
}
static int F_108 ( struct V_5 * V_6 , const char * V_199 ,
int V_50 , T_1 V_27 , int V_200 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
char V_117 [ 32 ] ;
int V_25 ;
if ( ! V_8 -> V_201 ) {
unsigned int V_202 , V_203 , V_204 , V_205 ;
V_202 = F_109 ( V_6 , V_27 , V_35 ) ;
V_203 = ( V_202 & V_206 ) >>
V_207 ;
V_203 = ( V_203 + 1 ) * 25 ;
V_204 = ( V_202 & V_208 ) >>
V_209 ;
V_205 = V_204 * V_203 ;
if ( V_205 > 6400 && V_204 >= 0x1f )
V_8 -> V_88 = V_204 / 2 ;
V_8 -> V_201 = 1 ;
}
sprintf ( V_117 , L_20 , V_199 ) ;
V_25 = F_88 ( V_8 , V_210 , V_50 , V_117 ,
F_110 ( V_27 , V_200 , 0 , V_35 ,
V_8 -> V_88 ) ) ;
if ( V_25 < 0 )
return V_25 ;
sprintf ( V_117 , L_21 , V_199 ) ;
V_25 = F_88 ( V_8 , V_211 , V_50 , V_117 ,
F_111 ( V_27 , V_200 , 0 , V_35 ) ) ;
if ( V_25 < 0 )
return V_25 ;
return 0 ;
}
static int F_105 ( struct V_7 * V_8 , T_1 V_27 )
{
if ( V_8 -> V_30 . V_180 > 4 ) {
F_112 ( V_212 L_22 , V_27 ) ;
return 1 ;
} else {
F_113 ( V_8 -> V_30 . V_87 != V_8 -> V_87 ) ;
V_8 -> V_87 [ V_8 -> V_30 . V_180 ] = V_27 ;
V_8 -> V_30 . V_180 ++ ;
}
return 0 ;
}
static int F_106 ( struct V_7 * V_8 , T_1 V_27 )
{
int V_70 ;
for ( V_70 = 0 ; V_70 < F_114 ( V_8 -> V_30 . V_213 ) ; V_70 ++ ) {
if ( ! V_8 -> V_30 . V_213 [ V_70 ] ) {
V_8 -> V_30 . V_213 [ V_70 ] = V_27 ;
return 0 ;
}
}
F_112 ( V_212 L_23 , V_27 ) ;
return 1 ;
}
static int F_115 ( struct V_5 * V_6 , int V_214 ,
const T_1 * V_215 ,
const T_1 * V_87 ,
int type )
{
struct V_7 * V_8 = V_6 -> V_8 ;
static const char * const V_216 [ 4 ] = {
L_24 , L_25 , NULL , L_26
} ;
T_1 V_27 ;
int V_70 , V_25 ;
unsigned int V_217 ;
for ( V_70 = 0 ; V_70 < V_214 && V_70 < F_114 ( V_216 ) ; V_70 ++ ) {
if ( type == V_218 && ! V_8 -> V_144 ) {
if ( F_116 ( V_6 , V_215 [ V_70 ] ) )
V_8 -> V_144 = 1 ;
}
V_27 = V_87 [ V_70 ] ;
if ( ! V_27 )
continue;
if ( type != V_218 && V_70 == 2 ) {
V_25 = F_117 ( V_6 , L_27 , V_27 , 1 ) ;
if ( V_25 < 0 )
return V_25 ;
V_25 = F_117 ( V_6 , L_28 , V_27 , 2 ) ;
if ( V_25 < 0 )
return V_25 ;
V_217 = F_36 ( V_6 , V_27 ) ;
if ( V_217 & V_219 ) {
V_25 = F_89 ( V_8 ,
V_220 ,
L_29 , V_27 ) ;
if ( V_25 < 0 )
return V_25 ;
}
} else {
const char * V_117 ;
int V_50 ;
switch ( type ) {
case V_218 :
V_117 = L_30 ;
V_50 = V_70 ;
break;
case V_122 :
if ( V_214 <= 2 ) {
V_117 = V_70 ? L_31 : L_32 ;
V_50 = 0 ;
break;
}
default:
V_117 = V_216 [ V_70 ] ;
V_50 = 0 ;
break;
}
V_25 = F_108 ( V_6 , V_117 , V_50 , V_27 , 3 ) ;
if ( V_25 < 0 )
return V_25 ;
}
}
return 0 ;
}
static int F_118 ( struct V_1 * V_2 ,
struct V_10 * V_11 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = V_6 -> V_8 ;
int V_25 ;
bool V_221 ;
V_25 = F_119 ( V_2 , V_11 ) ;
if ( V_25 <= 0 )
return V_25 ;
V_221 = ! ( V_11 -> V_14 . integer . V_14 [ 0 ] &&
V_11 -> V_14 . integer . V_14 [ 1 ] ) ;
if ( V_8 -> V_222 != V_221 ) {
V_8 -> V_222 = V_221 ;
if ( V_221 )
V_8 -> V_223 |= V_8 -> V_224 ;
else
V_8 -> V_223 &= ~ V_8 -> V_224 ;
F_120 ( V_6 , V_8 -> V_225 ,
V_8 -> V_86 , V_8 -> V_223 ) ;
}
return V_25 ;
}
static int F_121 ( struct V_5 * V_6 , unsigned long V_226 ,
unsigned long V_227 , int V_50 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
struct V_147 * V_150 ;
int V_25 ;
V_25 = F_88 ( V_6 -> V_8 , V_210 , V_50 ,
L_33 , V_226 ) ;
if ( V_25 < 0 )
return V_25 ;
V_150 = F_86 ( V_8 ,
& V_157 [ V_211 ] ,
V_50 , L_34 , V_227 ) ;
if ( ! V_150 )
return - V_156 ;
if ( V_8 -> V_224 )
V_150 -> V_228 = F_118 ;
return 0 ;
}
static int F_122 ( struct V_5 * V_6 ,
const struct V_169 * V_170 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
T_1 V_27 ;
int V_25 ;
int V_50 ;
V_25 = F_115 ( V_6 , V_170 -> V_123 , V_170 -> V_195 ,
V_8 -> V_30 . V_87 ,
V_170 -> V_121 ) ;
if ( V_25 < 0 )
return V_25 ;
if ( V_170 -> V_181 > 1 && V_170 -> V_121 == V_172 ) {
V_25 = F_89 ( V_8 ,
V_229 ,
L_35 ,
V_170 -> V_194 [ V_170 -> V_181 - 1 ] ) ;
if ( V_25 < 0 )
return V_25 ;
}
for ( V_50 = 0 ; V_50 < V_170 -> V_173 ; V_50 ++ ) {
if ( V_170 -> V_174 [ V_50 ] . type > V_175 )
break;
V_27 = V_170 -> V_174 [ V_50 ] . V_176 ;
V_25 = F_90 ( V_6 , V_27 , V_50 ) ;
if ( V_25 < 0 )
return V_25 ;
}
return 0 ;
}
static int F_123 ( struct V_5 * V_6 ,
struct V_169 * V_170 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
int V_25 ;
V_25 = F_115 ( V_6 , V_170 -> V_181 , V_170 -> V_194 ,
V_8 -> V_182 , V_218 ) ;
if ( V_25 < 0 )
return V_25 ;
V_25 = F_115 ( V_6 , V_170 -> V_183 , V_170 -> V_198 ,
V_8 -> V_184 , V_122 ) ;
if ( V_25 < 0 )
return V_25 ;
return 0 ;
}
static int F_124 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
struct V_22 * V_58 = & V_8 -> V_230 ;
int V_70 , V_231 ;
T_1 V_232 [ F_114 ( V_233 ) ] ;
V_231 = F_101 ( V_6 ,
V_8 -> V_60 ,
V_232 ,
V_234 ) ;
if ( V_231 <= 0 || V_231 > F_114 ( V_233 ) )
return - V_235 ;
for ( V_70 = 0 ; V_70 < V_231 ; V_70 ++ )
F_37 ( V_58 , V_233 [ V_70 ] , V_70 ,
NULL ) ;
return F_89 ( V_8 , V_236 ,
L_36 , V_8 -> V_60 ) ;
}
static int F_125 ( struct V_5 * V_6 ,
T_1 V_27 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
T_2 V_202 = F_109 ( V_6 , V_27 , V_35 ) ;
int V_25 , type = V_237 ;
if ( V_8 -> V_238 == V_27 )
type = V_211 ;
if ( ( V_202 & V_239 ) >> V_240 ) {
V_25 = F_89 ( V_8 , type ,
L_37 ,
F_111 ( V_27 , 1 , 0 , V_35 ) ) ;
if ( V_25 < 0 )
return V_25 ;
}
if ( ( V_202 & V_208 ) >> V_209 ) {
V_25 = F_89 ( V_8 , V_210 ,
L_38 ,
F_111 ( V_27 , 1 , 0 , V_35 ) ) ;
if ( V_25 < 0 )
return V_25 ;
}
return 0 ;
}
static int F_126 ( struct V_1 * V_2 ,
struct V_10 * V_11 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
V_11 -> V_14 . integer . V_14 [ 0 ] = V_6 -> V_241 -> V_242 ;
return 0 ;
}
static int F_127 ( struct V_1 * V_2 ,
struct V_10 * V_11 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
return F_128 ( V_6 , V_11 -> V_14 . integer . V_14 [ 0 ] ) ;
}
static int F_129 ( struct V_5 * V_6 )
{
return F_87 ( V_6 -> V_8 , & V_243 ,
0 , L_37 , 0 ) ;
}
static int F_130 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
int V_70 , V_185 , V_25 = 0 ;
for ( V_70 = 0 ; V_70 < V_8 -> V_244 ; V_70 ++ ) {
T_1 V_27 ;
unsigned int V_79 ;
unsigned long V_26 ;
V_27 = V_8 -> V_54 [ V_70 ] ;
V_79 = F_36 ( V_6 , V_27 ) ;
if ( ! ( V_79 & V_80 ) )
continue;
V_26 = F_111 ( V_27 , 3 , 0 , V_35 ) ;
for ( V_185 = 0 ; V_185 < V_8 -> V_245 ; V_185 ++ ) {
if ( V_8 -> V_246 [ V_185 ] == V_26 )
break;
}
if ( V_185 < V_8 -> V_245 )
continue;
V_25 = F_88 ( V_8 , V_210 , V_70 ,
L_39 , V_26 ) ;
if ( V_25 < 0 )
return V_25 ;
}
return 0 ;
}
static int F_131 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
struct V_22 * V_247 = & V_8 -> V_24 ;
const char * const * V_248 = V_8 -> V_249 ;
int V_70 , V_231 ;
T_1 V_232 [ V_234 ] ;
V_231 = F_101 ( V_6 ,
V_8 -> V_28 [ 0 ] ,
V_232 ,
V_234 ) ;
if ( V_231 <= 0 )
return - V_235 ;
if ( ! V_248 )
V_248 = V_250 ;
for ( V_70 = 0 ; V_70 < V_231 ; V_70 ++ )
F_37 ( V_247 , V_248 [ V_70 ] , V_70 , NULL ) ;
return 0 ;
}
static T_1 F_132 ( struct V_5 * V_6 , T_1 V_251 ,
int V_50 )
{
T_1 V_187 [ V_234 ] ;
int V_204 ;
V_204 = F_101 ( V_6 , V_251 , V_187 , F_114 ( V_187 ) ) ;
if ( V_50 >= 0 && V_50 < V_204 )
return V_187 [ V_50 ] ;
return 0 ;
}
static int F_133 ( struct V_5 * V_6 , T_1 V_27 ,
const char * V_252 , int V_50 , int V_253 )
{
unsigned int V_202 , V_204 ;
char V_117 [ 32 ] ;
int V_25 ;
if ( V_253 == V_35 )
V_202 = V_80 ;
else
V_202 = V_254 ;
if ( ! ( F_36 ( V_6 , V_27 ) & V_202 ) )
return 0 ;
V_202 = F_109 ( V_6 , V_27 , V_253 ) ;
V_204 = ( V_202 & V_208 ) >> V_209 ;
if ( ! V_204 )
return 0 ;
snprintf ( V_117 , sizeof( V_117 ) , L_40 , V_252 ) ;
V_25 = F_88 ( V_6 -> V_8 , V_210 , V_50 , V_117 ,
F_111 ( V_27 , 3 , 0 , V_253 ) ) ;
if ( V_25 < 0 )
return V_25 ;
return 1 ;
}
static int F_134 ( struct V_5 * V_6 ,
const struct V_169 * V_170 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
struct V_22 * V_49 = & V_8 -> V_167 ;
struct V_22 * V_255 = & V_8 -> V_256 ;
int V_25 , V_70 ;
unsigned int V_158 ;
F_37 ( V_255 , V_257 [ 0 ] , 0 , NULL ) ;
for ( V_70 = 0 ; V_70 < V_8 -> V_258 ; V_70 ++ ) {
T_1 V_27 ;
int V_57 , V_259 ;
char V_252 [ 32 ] ;
V_27 = V_8 -> V_260 [ V_70 ] ;
if ( F_102 ( F_36 ( V_6 , V_27 ) ) != V_261 )
continue;
V_158 = F_91 ( V_6 , V_27 ) ;
if ( F_135 ( V_158 ) == V_262 )
continue;
V_57 = F_136 ( V_6 , V_8 -> V_18 [ 0 ] , V_27 ) ;
if ( V_57 < 0 )
continue;
F_94 ( V_6 , V_27 , & V_8 -> V_82 ,
V_252 , sizeof( V_252 ) , NULL ) ;
F_37 ( V_255 , V_252 , V_57 , & V_259 ) ;
if ( F_33 ( V_6 , L_2 ) != 1 )
F_37 ( V_49 , V_252 , V_57 , & V_259 ) ;
V_25 = F_133 ( V_6 , V_27 , V_252 , V_259 ,
V_263 ) ;
if ( V_25 < 0 )
return V_25 ;
if ( ! V_25 ) {
V_25 = F_133 ( V_6 , V_27 , V_252 ,
V_259 , V_35 ) ;
if ( V_25 < 0 )
return V_25 ;
if ( ! V_25 ) {
V_27 = F_132 ( V_6 ,
V_8 -> V_18 [ 0 ] , V_57 ) ;
if ( V_27 )
V_25 = F_133 ( V_6 ,
V_27 , V_252 ,
V_259 , V_263 ) ;
if ( V_25 < 0 )
return V_25 ;
}
}
}
return 0 ;
}
static int F_137 ( struct V_5 * V_6 , T_1 V_27 ,
T_1 * V_264 , T_1 * V_265 , T_1 * V_266 )
{
unsigned int V_170 ;
unsigned int type ;
if ( ! V_27 )
return 0 ;
V_170 = F_91 ( V_6 , V_27 ) ;
type = F_138 ( V_170 ) ;
switch ( F_92 ( V_170 ) ) {
case V_160 :
if ( * V_264 )
return 1 ;
if ( type != V_267 )
return 1 ;
* V_264 = V_27 ;
break;
case V_268 :
break;
case V_162 :
if ( * V_266 )
return 1 ;
if ( type != V_267 && type != V_269 )
return 1 ;
* V_266 = V_27 ;
break;
default:
if ( * V_265 )
return 1 ;
if ( type != V_267 )
return 1 ;
* V_265 = V_27 ;
break;
}
return 0 ;
}
static int F_139 ( struct V_5 * V_6 ,
struct V_270 * V_271 ,
T_1 V_176 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
struct V_169 * V_170 = & V_8 -> V_82 ;
int V_70 ;
V_271 -> V_176 = V_176 ;
if ( V_176 == 0 )
return 0 ;
for ( V_70 = 0 ; V_70 < V_170 -> V_173 ; V_70 ++ ) {
if ( V_176 == V_170 -> V_174 [ V_70 ] . V_176 )
break;
}
if ( V_70 < V_170 -> V_173 && V_170 -> V_174 [ V_70 ] . type == V_179 ) {
V_70 = F_136 ( V_6 , V_8 -> V_54 [ 0 ] , V_176 ) ;
if ( V_70 < 0 )
return - 1 ;
V_271 -> V_272 = V_70 ;
V_271 -> V_12 = - 1 ;
if ( V_8 -> V_18 )
V_271 -> V_12 = F_136 ( V_6 ,
V_8 -> V_18 [ 0 ] ,
V_8 -> V_54 [ 0 ] ) ;
} else if ( V_8 -> V_18 ) {
V_70 = F_136 ( V_6 , V_8 -> V_18 [ 0 ] , V_176 ) ;
if ( V_70 < 0 )
return - 1 ;
V_271 -> V_12 = V_70 ;
V_271 -> V_272 = - 1 ;
if ( V_8 -> V_54 )
V_271 -> V_272 = F_136 ( V_6 ,
V_8 -> V_54 [ 0 ] ,
V_8 -> V_18 [ 0 ] ) ;
}
return 0 ;
}
static int F_140 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
struct V_169 * V_170 = & V_8 -> V_82 ;
T_1 V_264 , V_265 , V_266 ;
int V_70 ;
V_264 = V_265 = V_266 = 0 ;
for ( V_70 = 0 ; V_70 < V_170 -> V_173 ; V_70 ++ )
if ( F_137 ( V_6 , V_170 -> V_174 [ V_70 ] . V_176 ,
& V_264 , & V_265 , & V_266 ) )
return 0 ;
for ( V_70 = 0 ; V_70 < V_8 -> V_258 ; V_70 ++ )
if ( F_137 ( V_6 , V_8 -> V_260 [ V_70 ] ,
& V_264 , & V_265 , & V_266 ) )
return 0 ;
if ( ! V_264 || ( ! V_265 && ! V_266 ) )
return 0 ;
if ( ! F_116 ( V_6 , V_265 ) )
return 0 ;
if ( F_139 ( V_6 , & V_8 -> V_273 , V_265 ) ||
F_139 ( V_6 , & V_8 -> V_274 , V_264 ) ||
F_139 ( V_6 , & V_8 -> V_275 , V_266 ) )
return 0 ;
return 1 ;
}
static int F_141 ( struct V_5 * V_6 , const struct V_169 * V_170 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
struct V_22 * V_49 = & V_8 -> V_167 ;
int V_70 , V_185 ;
const char * V_252 ;
for ( V_70 = 0 ; V_70 < V_170 -> V_173 ; V_70 ++ ) {
T_1 V_27 = V_170 -> V_174 [ V_70 ] . V_176 ;
int V_57 , V_25 , V_259 ;
V_57 = - 1 ;
for ( V_185 = 0 ; V_185 < V_8 -> V_244 ; V_185 ++ ) {
V_57 = F_136 ( V_6 , V_8 -> V_54 [ V_185 ] ,
V_27 ) ;
if ( V_57 >= 0 )
break;
}
if ( V_57 < 0 )
continue;
V_252 = F_142 ( V_6 , V_170 , V_70 ) ;
F_37 ( V_49 , V_252 , V_57 , & V_259 ) ;
V_25 = F_133 ( V_6 , V_27 ,
V_252 , V_259 ,
V_263 ) ;
if ( V_25 < 0 )
return V_25 ;
}
V_8 -> V_53 = V_49 -> V_33 ;
if ( V_49 -> V_33 ) {
for ( V_70 = 0 ; V_70 < V_8 -> V_244 ; V_70 ++ ) {
F_21 ( V_6 , V_8 -> V_54 [ V_70 ] , 0 ,
V_55 ,
V_49 -> V_56 [ 0 ] . V_57 ) ;
}
}
return 0 ;
}
static void F_143 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
int V_70 ;
for ( V_70 = 0 ; V_70 < V_8 -> V_82 . V_123 ; V_70 ++ ) {
T_1 V_27 = V_8 -> V_82 . V_195 [ V_70 ] ;
F_70 ( V_6 , V_27 , V_43 ) ;
}
}
static void F_144 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
int V_70 ;
for ( V_70 = 0 ; V_70 < V_8 -> V_82 . V_181 ; V_70 ++ ) {
T_1 V_176 ;
V_176 = V_8 -> V_82 . V_194 [ V_70 ] ;
if ( V_176 )
F_70 ( V_6 , V_176 , V_43 | V_276 ) ;
}
for ( V_70 = 0 ; V_70 < V_8 -> V_82 . V_183 ; V_70 ++ ) {
T_1 V_176 ;
V_176 = V_8 -> V_82 . V_198 [ V_70 ] ;
if ( V_176 )
F_70 ( V_6 , V_176 , V_43 ) ;
}
}
static int F_145 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
int V_70 , V_277 ;
if ( V_8 -> V_82 . V_121 != V_122 ||
V_8 -> V_82 . V_181 <= 1 )
return 0 ;
V_277 = 0 ;
for ( V_70 = 0 ; V_70 < V_8 -> V_82 . V_181 ; V_70 ++ ) {
T_1 V_27 = V_8 -> V_82 . V_194 [ V_70 ] ;
unsigned int V_170 = F_91 ( V_6 , V_27 ) ;
if ( F_146 ( V_170 ) & V_278 )
continue;
V_277 ++ ;
}
return ( V_277 > 1 ) ;
}
static int F_147 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
T_1 V_279 = 0 , V_280 = 0 ;
int V_281 = 0 ;
int V_70 , V_25 ;
if ( ( V_25 = F_148 ( V_6 ,
& V_8 -> V_82 ,
V_8 -> V_260 ) ) < 0 )
return V_25 ;
if ( ! V_8 -> V_82 . V_123 )
return 0 ;
if ( F_145 ( V_6 ) ) {
F_13 ( L_41 ) ;
memcpy ( V_8 -> V_82 . V_198 , V_8 -> V_82 . V_195 ,
sizeof( V_8 -> V_82 . V_195 ) ) ;
V_8 -> V_82 . V_183 = V_8 -> V_82 . V_123 ;
memcpy ( V_8 -> V_82 . V_195 , V_8 -> V_82 . V_194 ,
sizeof( V_8 -> V_82 . V_194 ) ) ;
V_8 -> V_82 . V_123 = V_8 -> V_82 . V_181 ;
V_8 -> V_82 . V_121 = V_218 ;
V_8 -> V_82 . V_181 = 0 ;
V_281 = 1 ;
}
if ( V_8 -> V_82 . V_282 ) {
int V_283 = F_36 ( V_6 , V_8 -> V_82 . V_282 ) &
( V_80 | V_254 ) ;
T_2 V_202 = F_109 ( V_6 ,
V_8 -> V_82 . V_282 , V_283 ) ;
T_1 V_284 [ 1 ] ;
if ( F_101 ( V_6 ,
V_8 -> V_82 . V_282 , V_284 , 1 ) &&
F_101 ( V_6 , V_284 [ 0 ] ,
V_284 , 1 ) > 0 ) {
int V_79 = F_36 ( V_6 , V_284 [ 0 ] ) ;
int V_285 = F_102 ( V_79 ) ;
if ( V_285 == V_286 &&
! ( V_79 & V_219 ) )
V_8 -> V_60 = V_284 [ 0 ] ;
}
if ( V_283 ) {
T_1 V_27 = V_8 -> V_82 . V_282 ;
V_283 = ( V_283 & V_80 ) ? V_35 : V_263 ;
V_25 = F_89 ( V_8 , V_211 ,
L_42 ,
F_111 ( V_27 , 1 , 0 , V_283 ) ) ;
if ( V_25 < 0 )
return V_25 ;
if ( ( V_202 & V_208 )
>> V_209 ) {
V_25 = F_89 ( V_8 ,
V_210 ,
L_43 ,
F_111 ( V_27 , 1 , 0 , V_283 ) ) ;
if ( V_25 < 0 )
return V_25 ;
}
}
F_70 ( V_6 , V_8 -> V_82 . V_282 ,
V_43 ) ;
}
if ( ! V_8 -> V_30 . V_180 ) {
V_25 = F_103 ( V_6 ) ;
if ( V_25 < 0 )
return V_25 ;
V_25 = F_122 ( V_6 ,
& V_8 -> V_82 ) ;
if ( V_25 < 0 )
return V_25 ;
}
if ( V_8 -> V_238 > 0 ) {
V_25 = F_125 ( V_6 ,
V_8 -> V_238 ) ;
if ( V_25 < 0 )
return V_25 ;
}
#ifdef F_149
if ( V_8 -> V_287 > 0 ) {
T_1 V_27 = V_8 -> V_287 ;
unsigned int V_202 ;
V_25 = F_125 ( V_6 , V_27 ) ;
if ( V_25 < 0 )
return V_25 ;
V_25 = F_150 ( V_6 , V_27 ) ;
if ( V_25 < 0 )
return V_25 ;
if ( V_6 -> V_241 ) {
V_6 -> V_241 -> V_288 = V_8 -> V_289 ;
V_202 = F_109 ( V_6 , V_27 , V_35 ) ;
if ( ! ( V_202 & V_239 ) ) {
V_25 = F_129 ( V_6 ) ;
if ( V_25 < 0 )
return V_25 ;
}
}
}
#endif
V_25 = F_123 ( V_6 , & V_8 -> V_82 ) ;
if ( V_25 < 0 )
return V_25 ;
if ( V_281 ) {
memcpy ( V_8 -> V_82 . V_194 , V_8 -> V_82 . V_195 ,
sizeof( V_8 -> V_82 . V_194 ) ) ;
V_8 -> V_82 . V_181 = V_8 -> V_82 . V_123 ;
V_8 -> V_82 . V_121 = V_218 ;
V_8 -> V_82 . V_123 = 0 ;
}
if ( F_140 ( V_6 ) ) {
V_8 -> V_74 = 1 ;
V_8 -> V_129 = 1 ;
V_8 -> V_245 = 1 ;
V_8 -> V_244 = 1 ;
}
for ( V_70 = 0 ; V_70 < V_8 -> V_245 ; V_70 ++ ) {
V_25 = F_121 ( V_6 , V_8 -> V_246 [ V_70 ] ,
V_8 -> V_290 [ V_70 ] , V_70 ) ;
if ( V_25 < 0 )
return V_25 ;
}
V_25 = F_141 ( V_6 , & V_8 -> V_82 ) ;
if ( V_25 < 0 )
return V_25 ;
if ( V_8 -> V_60 > 0 ) {
V_25 = F_124 ( V_6 ) ;
if ( V_25 < 0 )
return V_25 ;
}
if ( V_8 -> V_258 > 0 && ! V_8 -> V_9 )
if ( ( V_25 = F_134 ( V_6 ,
& V_8 -> V_82 ) ) < 0 )
return V_25 ;
if ( V_8 -> V_244 > 0 ) {
V_25 = F_130 ( V_6 ) ;
if ( V_25 < 0 )
return V_25 ;
}
if ( V_8 -> V_78 > 0 ) {
V_25 = F_131 ( V_6 ) ;
if ( V_25 < 0 )
return V_25 ;
}
V_25 = F_95 ( V_8 ) ;
if ( V_25 < 0 )
return V_25 ;
V_8 -> V_30 . V_291 = V_8 -> V_30 . V_180 * 2 ;
if ( V_8 -> V_30 . V_291 > 2 )
V_8 -> V_292 = 1 ;
for ( V_70 = V_6 -> V_293 ; V_70 < V_6 -> V_293 + V_6 -> V_294 ; V_70 ++ ) {
unsigned int V_217 = F_36 ( V_6 , V_70 ) ;
if ( V_217 & V_192 ) {
switch ( F_102 ( V_217 ) ) {
case V_191 :
if ( ! V_279 )
V_279 = V_70 ;
break;
case V_295 :
if ( ! V_280 )
V_280 = V_70 ;
break;
}
}
}
if ( V_8 -> V_82 . V_296 )
V_8 -> V_30 . V_31 = V_279 ;
if ( V_280 && V_8 -> V_82 . V_297 )
V_8 -> V_85 = V_280 ;
if ( V_8 -> V_151 . V_298 )
V_8 -> V_73 [ V_8 -> V_72 ++ ] = V_8 -> V_151 . V_298 ;
V_8 -> V_46 = & V_8 -> V_167 ;
if ( ! V_8 -> V_9 )
V_8 -> V_9 = & V_8 -> V_256 ;
V_8 -> V_19 = & V_8 -> V_24 ;
V_8 -> V_58 = & V_8 -> V_230 ;
return 1 ;
}
static int F_151 ( struct V_5 * V_6 ,
struct V_169 * V_170 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
T_1 V_176 = V_170 -> V_194 [ 0 ] ;
if ( ! V_176 )
return 0 ;
if ( F_116 ( V_6 , V_176 ) )
V_8 -> V_144 = 1 ;
return 0 ;
}
static int F_152 ( struct V_5 * V_6 ,
struct V_169 * V_170 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
int V_25 ;
T_1 V_299 = 0x0 ;
int V_70 ;
for ( V_70 = 0 ; V_70 < V_8 -> V_82 . V_183 && V_299 == 0x0 ; V_70 ++ ) {
T_1 V_176 = V_8 -> V_82 . V_198 [ V_70 ] ;
unsigned int V_79 = F_36 ( V_6 , V_176 ) ;
V_79 &= ( V_300 | V_80 ) ;
if ( V_79 == V_80 )
V_299 = V_176 ;
}
if ( V_299 == 0 && V_8 -> V_82 . V_183 == 0 ) {
for ( V_70 = 0 ; V_70 < V_8 -> V_82 . V_123 && V_299 == 0x0 ; V_70 ++ ) {
T_1 V_176 = V_8 -> V_82 . V_195 [ V_70 ] ;
unsigned int V_301 ;
V_301 = F_91 ( V_6 , V_176 ) ;
if ( F_138 ( V_301 ) == V_302 ) {
unsigned int V_79 = F_36 ( V_6 , V_176 ) ;
V_79 &= ( V_300 | V_80 ) ;
if ( V_79 == V_80 )
V_299 = V_176 ;
}
}
}
if ( V_299 ) {
V_25 = F_117 ( V_6 , L_28 , V_299 , 1 ) ;
if ( V_25 < 0 )
return V_25 ;
}
return 0 ;
}
static int F_153 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
int V_25 ;
if ( ( V_25 = F_148 ( V_6 , & V_8 -> V_82 , NULL ) ) < 0 )
return V_25 ;
if ( ( V_25 = F_141 ( V_6 , & V_8 -> V_82 ) ) < 0 )
return V_25 ;
if ( ( V_25 = F_151 ( V_6 , & V_8 -> V_82 ) ) < 0 )
return V_25 ;
if ( ( V_25 = F_152 ( V_6 , & V_8 -> V_82 ) ) < 0 )
return V_25 ;
if ( V_8 -> V_244 > 0 ) {
V_25 = F_130 ( V_6 ) ;
if ( V_25 < 0 )
return V_25 ;
}
V_25 = F_95 ( V_8 ) ;
if ( V_25 < 0 )
return V_25 ;
if ( V_8 -> V_82 . V_296 )
V_8 -> V_30 . V_31 = 0x05 ;
if ( V_8 -> V_82 . V_297 )
V_8 -> V_85 = 0x04 ;
if ( V_8 -> V_151 . V_298 )
V_8 -> V_73 [ V_8 -> V_72 ++ ] = V_8 -> V_151 . V_298 ;
V_8 -> V_46 = & V_8 -> V_167 ;
V_8 -> V_9 = & V_8 -> V_256 ;
return 1 ;
}
static void F_120 ( struct V_5 * V_6 , unsigned int V_303 ,
unsigned int V_304 , unsigned int V_305 )
{
unsigned int V_306 , V_307 , V_308 ;
F_13 ( L_44 , V_38 , V_303 , V_304 , V_305 ) ;
V_306 = F_14 ( V_6 , V_6 -> V_65 , 0 ,
V_309 , 0 ) ;
V_306 = ( V_306 & ~ V_304 ) | ( V_305 & V_304 ) ;
V_307 = F_14 ( V_6 , V_6 -> V_65 , 0 ,
V_310 , 0 ) ;
V_307 |= V_303 ;
V_308 = F_14 ( V_6 , V_6 -> V_65 , 0 ,
V_311 , 0 ) ;
V_308 |= V_304 ;
F_65 ( V_6 , V_6 -> V_65 , 0 , 0x7e7 , 0 ) ;
F_65 ( V_6 , V_6 -> V_65 , 0 ,
V_312 , V_307 ) ;
F_14 ( V_6 , V_6 -> V_65 , 0 ,
V_313 , V_308 ) ;
F_50 ( 1 ) ;
F_14 ( V_6 , V_6 -> V_65 , 0 ,
V_314 , V_306 ) ;
}
static int F_154 ( struct V_5 * V_6 , T_1 V_27 ,
unsigned char type , int V_305 )
{
struct V_315 * V_316 ;
V_316 = F_155 ( V_6 , V_27 ) ;
if ( ! V_316 )
return - V_156 ;
V_316 -> V_317 = type ;
V_316 -> V_68 = V_305 ;
return 0 ;
}
static int F_156 ( struct V_5 * V_6 , T_1 V_27 ,
unsigned int type )
{
struct V_315 * V_316 ;
if ( ! F_116 ( V_6 , V_27 ) )
return 0 ;
V_316 = F_155 ( V_6 , V_27 ) ;
if ( ! V_316 )
return - V_156 ;
if ( V_316 -> V_317 && V_316 -> V_317 != type )
return 0 ;
V_316 -> V_317 = type ;
V_316 -> V_318 = V_319 ;
F_157 ( V_6 , V_27 , 0 ) ;
return 1 ;
}
static int F_158 ( struct V_169 * V_170 , T_1 V_27 )
{
int V_70 ;
for ( V_70 = 0 ; V_70 < V_170 -> V_181 ; V_70 ++ )
if ( V_170 -> V_194 [ V_70 ] == V_27 )
return 1 ;
for ( V_70 = 0 ; V_70 < V_170 -> V_123 ; V_70 ++ )
if ( V_170 -> V_195 [ V_70 ] == V_27 )
return 1 ;
return 0 ;
}
static void F_159 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
const T_1 * V_178 ;
for ( V_178 = V_8 -> V_320 ; * V_178 ; V_178 ++ )
if ( ! F_100 ( V_8 , * V_178 ) )
F_65 ( V_6 , * V_178 , 0 ,
V_109 , V_111 ) ;
}
static inline int F_160 ( struct V_5 * V_6 , const char * V_321 ,
int * V_322 )
{
const char * V_323 ;
V_323 = F_161 ( V_6 , V_321 ) ;
if ( V_323 ) {
unsigned long V_26 ;
if ( ! F_162 ( V_323 , 0 , & V_26 ) ) {
* V_322 = V_26 ;
return 1 ;
}
}
return 0 ;
}
static void F_163 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
int V_26 ;
V_26 = F_33 ( V_6 , L_45 ) ;
if ( V_26 >= 0 )
V_8 -> V_144 = V_26 ;
if ( F_160 ( V_6 , L_46 , & V_8 -> V_225 ) ) {
V_8 -> V_324 = V_8 -> V_86 = V_8 -> V_223 =
V_8 -> V_225 ;
}
if ( F_160 ( V_6 , L_47 , & V_8 -> V_86 ) )
V_8 -> V_225 &= V_8 -> V_225 ;
if ( F_160 ( V_6 , L_48 , & V_8 -> V_223 ) )
V_8 -> V_86 &= V_8 -> V_225 ;
if ( F_160 ( V_6 , L_49 , & V_8 -> V_324 ) )
V_8 -> V_324 &= V_8 -> V_225 ;
if ( F_160 ( V_6 , L_50 , & V_8 -> V_325 ) )
V_8 -> V_325 &= V_8 -> V_225 ;
V_26 = F_33 ( V_6 , L_51 ) ;
if ( V_26 >= 0 )
V_8 -> V_326 = V_26 ;
}
static void F_164 ( struct V_5 * V_6 , int V_97 ,
const T_1 * V_215 )
{
while ( V_97 -- )
F_73 ( V_6 , * V_215 ++ ) ;
}
static void F_165 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
if ( V_8 -> V_82 . V_181 )
F_164 ( V_6 , V_8 -> V_82 . V_181 ,
V_8 -> V_82 . V_194 ) ;
if ( V_8 -> V_82 . V_123 &&
V_8 -> V_82 . V_195 [ 0 ] != V_8 -> V_82 . V_194 [ 0 ] )
F_164 ( V_6 , V_8 -> V_82 . V_123 ,
V_8 -> V_82 . V_195 ) ;
}
static int F_166 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
struct V_169 * V_170 = & V_8 -> V_82 ;
unsigned int V_327 ;
int V_70 ;
if ( V_8 -> V_328 )
F_167 ( V_6 , V_8 -> V_328 ) ;
if ( V_8 -> V_108 )
for ( V_70 = 0 ; V_70 < V_8 -> V_129 ; V_70 ++ )
F_65 ( V_6 ,
V_8 -> V_106 [ V_70 ] , 0 ,
V_109 , V_111 ) ;
F_163 ( V_6 ) ;
V_327 = V_8 -> V_223 ;
if ( ! V_8 -> V_326 )
V_327 |= V_8 -> V_324 ;
F_120 ( V_6 , V_8 -> V_225 , V_8 -> V_86 , V_327 ) ;
if ( V_8 -> V_144 ) {
for ( V_70 = 0 ; V_70 < V_170 -> V_181 ; V_70 ++ ) {
T_1 V_27 = V_170 -> V_194 [ V_70 ] ;
F_156 ( V_6 , V_27 , V_329 ) ;
}
if ( V_170 -> V_121 == V_172 &&
V_170 -> V_183 > 0 ) {
for ( V_70 = 0 ; V_70 < V_170 -> V_123 ; V_70 ++ ) {
T_1 V_27 = V_170 -> V_195 [ V_70 ] ;
F_156 ( V_6 , V_27 , V_330 ) ;
}
}
F_70 ( V_6 , V_8 -> V_82 . V_195 [ 0 ] ,
V_43 ) ;
F_165 ( V_6 ) ;
} else {
F_143 ( V_6 ) ;
F_144 ( V_6 ) ;
for ( V_70 = 0 ; V_70 < V_170 -> V_181 ; V_70 ++ )
F_168 ( V_6 , V_170 -> V_194 [ V_70 ] , 1 ) ;
}
if ( V_8 -> V_74 ) {
if ( V_8 -> V_18 )
F_21 ( V_6 , V_8 -> V_18 [ 0 ] , 0 ,
V_55 , 0 ) ;
if ( F_156 ( V_6 , V_8 -> V_273 . V_176 , V_331 ) )
F_73 ( V_6 , V_8 -> V_273 . V_176 ) ;
if ( F_156 ( V_6 , V_8 -> V_275 . V_176 ,
V_331 ) )
F_73 ( V_6 , V_8 -> V_275 . V_176 ) ;
}
for ( V_70 = 0 ; V_70 < V_170 -> V_173 ; V_70 ++ ) {
T_1 V_27 = V_170 -> V_174 [ V_70 ] . V_176 ;
int type = V_170 -> V_174 [ V_70 ] . type ;
unsigned int V_37 , V_332 ;
if ( type == V_179 ) {
V_37 = F_76 ( V_6 , V_27 ) ;
V_37 |= V_42 ;
F_70 ( V_6 , V_27 , V_37 ) ;
} else {
V_37 = F_14 ( V_6 , V_27 , 0 ,
V_39 , 0 ) ;
if ( ! ( V_37 & V_42 ) ||
( V_37 & V_43 ) ) {
V_37 &= ~ V_43 ;
V_37 |= V_42 ;
F_70 ( V_6 , V_27 , V_37 ) ;
}
}
V_332 = F_91 ( V_6 , V_27 ) ;
if ( F_135 ( V_332 ) != V_333 ) {
if ( F_156 ( V_6 , V_27 , V_334 ) )
F_73 ( V_6 , V_27 ) ;
}
}
for ( V_70 = 0 ; V_70 < V_8 -> V_258 ; V_70 ++ )
F_70 ( V_6 , V_8 -> V_260 [ V_70 ] ,
V_42 ) ;
if ( V_170 -> V_335 [ 0 ] )
F_70 ( V_6 , V_170 -> V_335 [ 0 ] ,
V_43 ) ;
if ( V_170 -> V_297 )
F_70 ( V_6 , V_170 -> V_297 ,
V_42 ) ;
for ( V_70 = 0 ; V_70 < V_8 -> V_336 ; V_70 ++ ) {
T_1 V_27 = V_8 -> V_337 [ V_70 ] ;
unsigned int V_37 , V_158 ;
V_158 = F_91 ( V_6 , V_27 ) ;
V_158 = F_135 ( V_158 ) ;
if ( V_158 == V_262 ) {
F_168 ( V_6 , V_27 , 0 ) ;
continue;
}
if ( V_158 == V_333 ) {
F_168 ( V_6 , V_27 , 1 ) ;
continue;
}
if ( ! V_8 -> V_144 ||
V_8 -> V_338 == V_27 ||
! F_116 ( V_6 , V_27 ) ) {
F_168 ( V_6 , V_27 , 1 ) ;
continue;
}
if ( F_158 ( V_170 , V_27 ) )
continue;
V_37 = F_14 ( V_6 , V_27 , 0 ,
V_39 , 0 ) ;
if ( V_37 & V_42 ) {
F_168 ( V_6 , V_27 , 1 ) ;
continue;
}
if ( F_156 ( V_6 , V_27 , V_339 ) ) {
F_73 ( V_6 , V_27 ) ;
continue;
}
F_168 ( V_6 , V_27 , 0 ) ;
}
if ( V_8 -> V_93 ) {
if ( V_8 -> V_91 . V_94 )
F_169 ( & V_8 -> V_91 ) ;
else
F_30 ( V_6 , false ) ;
}
if ( V_8 -> V_336 )
F_65 ( V_6 , V_6 -> V_65 , 0 ,
V_340 ,
V_8 -> V_341 ) ;
if ( V_8 -> V_320 )
F_159 ( V_6 ) ;
return 0 ;
}
static void F_45 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
if ( V_8 -> V_151 . V_298 ) {
struct V_147 * V_342 = V_8 -> V_151 . V_298 ;
int V_70 ;
for ( V_70 = 0 ; V_70 < V_8 -> V_151 . V_343 ; V_70 ++ )
F_170 ( V_342 [ V_70 ] . V_117 ) ;
}
F_171 ( & V_8 -> V_151 ) ;
}
static void F_172 ( struct V_5 * V_6 )
{
unsigned int V_70 , V_158 ;
if ( V_6 -> V_344 -> V_345 )
return;
for ( V_70 = 0 ; V_70 < V_6 -> V_346 . V_343 ; V_70 ++ ) {
struct V_347 * V_176 = F_173 ( & V_6 -> V_346 , V_70 ) ;
V_158 = F_91 ( V_6 , V_176 -> V_27 ) ;
if ( F_135 ( V_158 ) != V_262 )
F_174 ( V_6 , V_176 -> V_27 , 0 ) ;
}
}
static void F_175 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
F_172 ( V_6 ) ;
if ( V_8 -> V_324 )
F_120 ( V_6 , V_8 -> V_225 ,
V_8 -> V_86 , V_8 -> V_223 &
~ V_8 -> V_324 ) ;
}
static void F_176 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
if ( ! V_8 )
return;
F_170 ( V_8 ) ;
F_177 ( V_6 ) ;
}
static void F_178 ( struct V_5 * V_6 , T_1 V_27 ,
unsigned int V_348 )
{
unsigned int V_349 , V_350 ;
V_350 = F_14 ( V_6 , V_27 ,
0 , V_39 , 0x00 ) ;
if ( V_350 & V_42 ) {
struct V_7 * V_8 = V_6 -> V_8 ;
if ( V_27 == V_8 -> V_139 || V_27 == V_8 -> V_138 )
return;
}
V_349 = V_350 ;
if ( V_348 & ( V_42 | V_43 ) )
V_350 &= ~ ( V_42 | V_43 ) ;
V_350 |= V_348 ;
if ( V_349 != V_350 )
F_15 ( V_6 , V_27 , V_350 ) ;
}
static void F_179 ( struct V_5 * V_6 , T_1 V_27 ,
unsigned int V_348 )
{
unsigned int V_350 = F_14 ( V_6 , V_27 ,
0 , V_39 , 0x00 ) ;
if ( V_350 & V_348 )
F_15 ( V_6 , V_27 , V_350 & ~ V_348 ) ;
}
static inline int F_180 ( struct V_5 * V_6 , T_1 V_27 )
{
if ( ! V_27 )
return 0 ;
return F_181 ( V_6 , V_27 ) ;
}
static void F_182 ( struct V_5 * V_6 ,
int V_351 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
struct V_169 * V_170 = & V_8 -> V_82 ;
int V_70 ;
if ( V_170 -> V_183 == 0 )
return;
for ( V_70 = 0 ; V_70 < V_170 -> V_123 ; V_70 ++ ) {
if ( V_351 )
break;
V_351 = F_180 ( V_6 , V_170 -> V_195 [ V_70 ] ) ;
if ( V_351 ) {
unsigned int V_37 ;
V_37 = F_14 ( V_6 ,
V_170 -> V_195 [ V_70 ] , 0 ,
V_39 , 0 ) ;
if ( V_37 & V_42 )
V_351 = 0 ;
}
}
if ( V_351 ) {
for ( V_70 = 0 ; V_70 < V_170 -> V_183 ; V_70 ++ )
F_179 ( V_6 , V_170 -> V_198 [ V_70 ] ,
V_43 ) ;
if ( V_8 -> V_324 && V_8 -> V_326 )
F_120 ( V_6 , V_8 -> V_225 ,
V_8 -> V_86 , V_8 -> V_223 &
~ V_8 -> V_324 ) ;
} else {
for ( V_70 = 0 ; V_70 < V_170 -> V_183 ; V_70 ++ )
F_178 ( V_6 , V_170 -> V_198 [ V_70 ] ,
V_43 ) ;
if ( V_8 -> V_324 && V_8 -> V_326 )
F_120 ( V_6 , V_8 -> V_225 ,
V_8 -> V_86 , V_8 -> V_223 |
V_8 -> V_324 ) ;
}
}
static int F_183 ( struct V_7 * V_8 , int V_70 )
{
struct V_169 * V_170 = & V_8 -> V_82 ;
if ( V_170 -> V_194 [ V_70 ] == V_8 -> V_139 )
return 1 ;
if ( V_170 -> V_194 [ V_70 ] == V_8 -> V_138 )
return 1 ;
if ( V_170 -> V_194 [ V_70 ] == V_8 -> V_136 )
return 1 ;
return 0 ;
}
static void F_184 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
struct V_169 * V_170 = & V_8 -> V_82 ;
int V_70 , V_351 ;
V_351 = 0 ;
if ( V_8 -> V_325 )
V_351 = ! ( F_14 ( V_6 , V_6 -> V_65 , 0 ,
V_309 , 0 ) & V_8 -> V_325 ) ;
for ( V_70 = 0 ; V_70 < V_170 -> V_181 ; V_70 ++ ) {
if ( V_351 )
break;
if ( F_183 ( V_8 , V_70 ) )
continue;
V_351 = F_180 ( V_6 , V_170 -> V_194 [ V_70 ] ) ;
if ( V_351 ) {
unsigned int V_37 ;
V_37 = F_14 ( V_6 , V_170 -> V_194 [ V_70 ] , 0 ,
V_39 , 0 ) ;
if ( V_37 & V_42 )
V_351 = 0 ;
}
}
if ( V_351 ) {
if ( V_8 -> V_136 )
F_179 ( V_6 , V_8 -> V_136 ,
V_43 ) ;
for ( V_70 = 0 ; V_70 < V_170 -> V_123 ; V_70 ++ )
F_179 ( V_6 , V_170 -> V_195 [ V_70 ] ,
V_43 ) ;
} else {
if ( V_8 -> V_136 )
F_178 ( V_6 , V_8 -> V_136 ,
V_43 ) ;
for ( V_70 = 0 ; V_70 < V_170 -> V_123 ; V_70 ++ )
F_178 ( V_6 , V_170 -> V_195 [ V_70 ] ,
V_43 ) ;
}
F_182 ( V_6 , V_351 ) ;
for ( V_70 = 0 ; V_70 < V_170 -> V_181 ; V_70 ++ ) {
unsigned int V_26 = V_43 | V_276 ;
if ( F_183 ( V_8 , V_70 ) )
continue;
if ( 1 )
F_178 ( V_6 , V_170 -> V_194 [ V_70 ] , V_26 ) ;
#if 0
else
stac92xx_reset_pinctl(codec, cfg->hp_pins[i], val);
#endif
}
}
static void F_168 ( struct V_5 * V_6 , T_1 V_27 ,
int V_352 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
unsigned int V_50 , V_26 ;
for ( V_50 = 0 ; V_50 < V_8 -> V_336 ; V_50 ++ ) {
if ( V_8 -> V_337 [ V_50 ] == V_27 )
break;
}
if ( V_50 >= V_8 -> V_336 )
return;
V_50 = 1 << V_50 ;
V_26 = V_8 -> V_341 ;
if ( V_352 )
V_26 &= ~ V_50 ;
else
V_26 |= V_50 ;
if ( V_26 != V_8 -> V_341 ) {
V_8 -> V_341 = V_26 ;
F_65 ( V_6 , V_6 -> V_65 , 0 ,
V_340 , V_26 ) ;
}
}
static void F_185 ( struct V_5 * V_6 , T_1 V_27 )
{
F_168 ( V_6 , V_27 , F_180 ( V_6 , V_27 ) ) ;
}
static unsigned int F_186 ( struct V_5 * V_6 , int V_50 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
unsigned int V_170 ;
V_170 = F_91 ( V_6 , V_8 -> V_98 [ V_50 ] ) ;
return F_135 ( V_170 ) ;
}
static int F_187 ( struct V_5 * V_6 ,
const T_1 * V_353 , int V_354 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
int V_50 , V_355 ;
unsigned int V_158 ;
for ( V_355 = 0 ; V_355 < V_354 ; V_355 ++ ) {
for ( V_50 = 0 ; V_50 < V_8 -> V_97 ; V_50 ++ )
if ( V_8 -> V_98 [ V_50 ] == V_353 [ V_355 ] )
break;
if ( V_50 >= V_8 -> V_97 )
break;
V_158 = F_186 ( V_6 , V_50 ) ;
if ( V_158 == V_262 )
break;
}
return V_355 ;
}
static void F_188 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
struct V_270 * V_271 ;
if ( F_180 ( V_6 , V_8 -> V_273 . V_176 ) )
V_271 = & V_8 -> V_273 ;
else if ( F_180 ( V_6 , V_8 -> V_275 . V_176 ) )
V_271 = & V_8 -> V_275 ;
else
V_271 = & V_8 -> V_274 ;
if ( V_271 -> V_12 >= 0 )
F_21 ( V_6 , V_8 -> V_18 [ 0 ] , 0 ,
V_55 ,
V_271 -> V_12 ) ;
if ( V_271 -> V_272 >= 0 )
F_21 ( V_6 , V_8 -> V_54 [ 0 ] , 0 ,
V_55 ,
V_271 -> V_272 ) ;
}
static void V_319 ( struct V_5 * V_6 ,
struct V_315 * V_316 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
int V_305 ;
switch ( V_316 -> V_317 ) {
case V_329 :
case V_330 :
F_184 ( V_6 ) ;
break;
case V_331 :
F_188 ( V_6 ) ;
break;
}
switch ( V_316 -> V_317 ) {
case V_329 :
case V_330 :
case V_331 :
case V_334 :
case V_339 :
if ( V_8 -> V_336 > 0 )
F_185 ( V_6 , V_316 -> V_27 ) ;
switch ( V_6 -> V_356 ) {
case 0x103c308f :
if ( V_316 -> V_27 == 0xb ) {
int V_176 = V_42 ;
if ( F_180 ( V_6 , 0xa )
&& F_180 ( V_6 , 0xb ) )
V_176 |= V_357 ;
if ( ! F_180 ( V_6 , 0xb ) )
V_176 |= V_357 ;
F_70 ( V_6 , 0x0a , V_176 ) ;
}
}
break;
case V_358 :
V_305 = F_14 ( V_6 , V_6 -> V_65 , 0 ,
V_309 , 0 ) ;
F_65 ( V_6 , V_6 -> V_65 , 0 , 0x7e0 ,
! ! ( V_305 & ( 1 << V_316 -> V_68 ) ) ) ;
break;
}
}
static void F_73 ( struct V_5 * V_6 , T_1 V_27 )
{
struct V_315 * V_316 = F_189 ( V_6 , V_27 ) ;
if ( ! V_316 )
return;
V_319 ( V_6 , V_316 ) ;
}
static void F_190 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
unsigned int V_327 ;
if ( V_8 -> V_93 )
return;
V_327 = F_191 ( V_6 , V_6 -> V_65 , V_359 ) ;
V_327 &= V_360 ;
if ( V_327 > 3 )
V_8 -> V_93 = 0x08 ;
else
V_8 -> V_93 = 0x01 ;
}
static int F_192 ( struct V_5 * V_6 , int V_361 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
const struct V_362 * V_363 = NULL ;
if ( F_160 ( V_6 , L_52 , & V_8 -> V_93 ) ) {
F_160 ( V_6 , L_53 ,
& V_8 -> V_364 ) ;
return 1 ;
}
if ( ( V_6 -> V_356 >> 16 ) == V_365 ) {
while ( ( V_363 = F_193 ( V_366 ,
NULL , V_363 ) ) ) {
if ( sscanf ( V_363 -> V_117 , L_54 ,
& V_8 -> V_364 ,
& V_8 -> V_93 ) == 2 ) {
unsigned int V_367 ;
V_367 = F_191 ( V_6 , V_6 -> V_65 ,
V_359 ) ;
V_367 &= V_360 ;
if ( V_8 -> V_93 < V_367 )
V_8 -> V_93 = 1 << V_8 -> V_93 ;
else
V_8 -> V_338 = V_8 -> V_93 ;
return 1 ;
}
if ( sscanf ( V_363 -> V_117 , L_55 ,
& V_8 -> V_364 ) == 1 ) {
F_190 ( V_6 ) ;
return 1 ;
}
if ( strstr ( V_363 -> V_117 , L_56 ) ) {
F_190 ( V_6 ) ;
switch ( V_6 -> V_356 ) {
case 0x103c148a :
V_8 -> V_364 = 0 ;
break;
default:
V_8 -> V_364 = 1 ;
break;
}
return 1 ;
}
}
if ( ! F_194 ( V_6 -> V_356 ) &&
( V_361 == 0 || V_361 == 1 ) ) {
F_190 ( V_6 ) ;
V_8 -> V_364 = V_361 ;
return 1 ;
}
}
return 0 ;
}
static int F_194 ( T_2 V_356 )
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
static void F_195 ( struct V_368 * V_369 ,
struct V_5 * V_6 , T_1 V_27 )
{
if ( V_27 == V_6 -> V_65 )
F_196 ( V_369 , L_57 ,
F_14 ( V_6 , V_27 , 0 ,
V_370 , 0 ) ) ;
}
static void F_197 ( struct V_368 * V_369 ,
struct V_5 * V_6 ,
unsigned int V_371 )
{
F_196 ( V_369 , L_58 ,
F_14 ( V_6 , V_6 -> V_65 , 0 , V_371 , 0 ) ) ;
}
static void F_198 ( struct V_368 * V_369 ,
struct V_5 * V_6 , T_1 V_27 )
{
F_195 ( V_369 , V_6 , V_27 ) ;
if ( V_27 == V_6 -> V_65 )
F_197 ( V_369 , V_6 , 0xfa0 ) ;
}
static void F_199 ( struct V_368 * V_369 ,
struct V_5 * V_6 , T_1 V_27 )
{
if ( V_27 == V_6 -> V_65 )
F_197 ( V_369 , V_6 , 0xfe0 ) ;
}
static void F_200 ( struct V_368 * V_369 ,
struct V_5 * V_6 , T_1 V_27 )
{
if ( V_27 == V_6 -> V_65 )
F_197 ( V_369 , V_6 , 0xfeb ) ;
}
static int F_201 ( struct V_5 * V_6 )
{
F_166 ( V_6 ) ;
F_202 ( V_6 ) ;
F_203 ( V_6 ) ;
F_165 ( V_6 ) ;
return 0 ;
}
static int F_204 ( struct V_5 * V_6 )
{
F_175 ( V_6 ) ;
return 0 ;
}
static void F_205 ( struct V_5 * V_6 , T_1 V_372 ,
unsigned int V_373 )
{
unsigned int V_374 = V_373 ;
struct V_7 * V_8 = V_6 -> V_8 ;
if ( V_373 == V_111 ) {
if ( V_8 -> V_338 ) {
V_374 = V_375 ;
}
F_50 ( 100 ) ;
}
F_14 ( V_6 , V_372 , 0 , V_109 ,
V_374 ) ;
F_206 ( V_6 , V_372 , V_373 , true ) ;
}
static void F_30 ( struct V_5 * V_6 , int V_242 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
int V_376 = ! V_242 ;
if ( ! V_8 -> V_93 )
return;
if ( V_8 -> V_364 )
V_376 = ! V_376 ;
if ( ! V_8 -> V_338 ) {
if ( V_376 )
V_8 -> V_223 |= V_8 -> V_93 ;
else
V_8 -> V_223 &= ~ V_8 -> V_93 ;
F_120 ( V_6 , V_8 -> V_225 ,
V_8 -> V_86 , V_8 -> V_223 ) ;
} else {
V_8 -> V_377 = V_376 ? V_378 : V_141 ;
F_12 ( V_6 , V_8 -> V_338 ,
V_8 -> V_377 ) ;
}
}
static int F_207 ( struct V_5 * V_6 , int V_97 ,
const T_1 * V_98 )
{
struct V_7 * V_8 ;
V_8 = F_208 ( sizeof( * V_8 ) , V_152 ) ;
if ( ! V_8 )
return - V_156 ;
V_6 -> V_8 = V_8 ;
V_6 -> V_379 = 1 ;
V_8 -> V_97 = V_97 ;
V_8 -> V_98 = V_98 ;
F_209 ( & V_8 -> V_151 , sizeof( struct V_147 ) , 32 ) ;
return 0 ;
}
static int F_210 ( struct V_5 * V_6 )
{
struct V_7 * V_8 ;
int V_25 ;
V_25 = F_207 ( V_6 , F_114 ( V_380 ) ,
V_380 ) ;
if ( V_25 < 0 )
return V_25 ;
V_8 = V_6 -> V_8 ;
V_8 -> V_289 = 1 ;
V_8 -> V_381 = F_211 ( V_6 , V_382 ,
V_383 ,
V_384 ) ;
if ( V_8 -> V_381 < 0 )
F_13 ( V_385 L_59 ,
V_6 -> V_386 ) ;
else
F_47 ( V_6 ,
V_387 [ V_8 -> V_381 ] ) ;
V_8 -> V_30 . V_291 = 2 ;
V_8 -> V_30 . V_180 = 1 ;
V_8 -> V_30 . V_87 = V_388 ;
V_8 -> V_106 = V_389 ;
V_8 -> V_54 = V_390 ;
V_8 -> V_244 = 1 ;
V_8 -> V_258 = 0 ;
V_8 -> V_129 = 1 ;
V_8 -> V_336 = 0 ;
if ( V_8 -> V_381 == V_391 ||
V_8 -> V_381 == V_392 ||
V_8 -> V_381 == V_393 )
V_8 -> V_328 = V_394 ;
else
V_8 -> V_328 = V_395 ;
V_8 -> V_71 = V_396 ;
if ( V_8 -> V_381 == V_397 ) {
V_8 -> V_225 = V_8 -> V_86 = 0x09 ;
V_8 -> V_223 = 0x00 ;
}
V_25 = F_153 ( V_6 ) ;
if ( V_25 < 0 ) {
F_176 ( V_6 ) ;
return V_25 ;
}
if ( V_8 -> V_381 == V_397 )
V_8 -> V_144 = 0 ;
V_6 -> V_398 = V_399 ;
return 0 ;
}
static int F_212 ( struct V_5 * V_6 )
{
struct V_7 * V_8 ;
int V_25 ;
V_25 = F_207 ( V_6 , F_114 ( V_400 ) ,
V_400 ) ;
if ( V_25 < 0 )
return V_25 ;
V_8 = V_6 -> V_8 ;
V_8 -> V_289 = 1 ;
V_8 -> V_381 = F_213 ( V_6 ,
V_401 ,
V_402 ,
V_403 ) ;
if ( V_8 -> V_381 < 0 )
V_8 -> V_381 = F_211 ( V_6 ,
V_401 ,
V_402 ,
V_404 ) ;
V_405:
if ( V_8 -> V_381 < 0 )
F_13 ( V_385 L_59 ,
V_6 -> V_386 ) ;
else
F_47 ( V_6 ,
V_406 [ V_8 -> V_381 ] ) ;
V_8 -> V_30 . V_291 = 2 ;
V_8 -> V_30 . V_180 = 1 ;
V_8 -> V_30 . V_87 = V_407 ;
V_8 -> V_106 = V_408 ;
V_8 -> V_54 = V_409 ;
V_8 -> V_244 = 1 ;
V_8 -> V_129 = 1 ;
V_8 -> V_336 = 0 ;
switch ( V_6 -> V_410 ) {
case 0x83847632 :
case 0x83847633 :
case 0x83847636 :
case 0x83847637 :
V_8 -> V_258 = V_411 ;
V_8 -> V_260 = V_412 ;
V_8 -> V_75 = F_114 ( V_413 ) ;
V_8 -> V_18 = V_413 ;
break;
default:
V_8 -> V_258 = 0 ;
break;
}
V_8 -> V_328 = V_414 ;
V_8 -> V_71 = V_415 ;
V_8 -> V_245 = 1 ;
V_8 -> V_246 = V_416 ;
V_8 -> V_290 = V_417 ;
V_25 = F_147 ( V_6 ) ;
if ( ! V_25 ) {
if ( V_8 -> V_381 < 0 ) {
F_112 ( V_212 L_60
L_61 ) ;
V_8 -> V_381 = V_418 ;
goto V_405;
}
V_25 = - V_235 ;
}
if ( V_25 < 0 ) {
F_176 ( V_6 ) ;
return V_25 ;
}
V_6 -> V_398 = V_399 ;
return 0 ;
}
static int F_214 ( struct V_5 * V_6 )
{
struct V_7 * V_8 ;
T_1 V_187 [ V_419 + 2 ] ;
int V_25 ;
int V_180 ;
V_25 = F_207 ( V_6 , F_114 ( V_420 ) ,
V_420 ) ;
if ( V_25 < 0 )
return V_25 ;
V_8 = V_6 -> V_8 ;
V_8 -> V_289 = 0 ;
V_6 -> V_32 = V_421 ;
V_8 -> V_381 = F_211 ( V_6 ,
V_422 ,
V_423 ,
V_424 ) ;
if ( V_8 -> V_381 < 0 )
V_8 -> V_381 =
F_213 ( V_6 ,
V_422 , V_423 ,
V_425 ) ;
V_405:
if ( V_8 -> V_381 < 0 )
F_13 ( V_385 L_59 ,
V_6 -> V_386 ) ;
else
F_47 ( V_6 ,
V_426 [ V_8 -> V_381 ] ) ;
V_180 = F_101 ( V_6 , 0x0a ,
V_187 , V_419 + 2 ) - 1 ;
if ( V_180 < 3 || V_180 > 5 ) {
F_112 ( V_212 L_62
L_63 ) ;
V_180 = V_419 ;
}
V_8 -> V_328 = V_427 ;
switch ( V_180 ) {
case 0x3 :
V_8 -> V_95 = V_428 ;
break;
case 0x4 :
V_8 -> V_95 = V_429 ;
break;
case 0x5 :
V_8 -> V_95 = V_430 ;
break;
}
V_8 -> V_30 . V_87 = V_8 -> V_87 ;
V_8 -> V_62 = 0x01 ;
V_8 -> V_67 = 8 ;
V_8 -> V_287 = 0x1c ;
V_8 -> V_54 = V_431 ;
V_8 -> V_106 = V_432 ;
V_8 -> V_260 = V_433 ;
V_8 -> V_18 = V_434 ;
V_8 -> V_28 = V_435 ;
V_8 -> V_244 = F_114 ( V_431 ) ;
V_8 -> V_129 = F_114 ( V_432 ) ;
V_8 -> V_75 = F_114 ( V_434 ) ;
V_8 -> V_245 = V_436 ;
V_8 -> V_246 = V_437 ;
V_8 -> V_290 = V_438 ;
switch ( V_8 -> V_381 ) {
case V_439 :
V_8 -> V_328 = V_440 ;
case V_441 :
case V_442 :
case V_443 :
V_8 -> V_78 = 0 ;
V_8 -> V_326 = 0 ;
switch ( V_8 -> V_381 ) {
case V_441 :
F_48 ( V_6 , 0x0b , 0x90A70170 ) ;
V_8 -> V_258 = 0 ;
break;
case V_442 :
F_48 ( V_6 , 0x13 , 0x90A60160 ) ;
V_8 -> V_258 = 1 ;
break;
case V_443 :
F_48 ( V_6 , 0x0b , 0x90A70170 ) ;
F_48 ( V_6 , 0x13 , 0x90A60160 ) ;
V_8 -> V_258 = 1 ;
break;
}
break;
case V_444 :
V_8 -> V_258 = V_445 ;
V_8 -> V_78 = F_114 ( V_435 ) ;
V_8 -> V_326 = 0 ;
break;
default:
V_8 -> V_258 = V_445 ;
V_8 -> V_78 = F_114 ( V_435 ) ;
V_8 -> V_326 = 1 ;
break;
}
if ( V_8 -> V_381 != V_446 ) {
V_8 -> V_324 = V_8 -> V_225 = V_8 -> V_86 = 0x1 ;
V_8 -> V_223 = 0x01 ;
}
V_8 -> V_336 = F_114 ( V_447 ) ;
V_8 -> V_337 = V_447 ;
V_25 = F_147 ( V_6 ) ;
if ( ! V_25 ) {
if ( V_8 -> V_381 < 0 ) {
F_112 ( V_212 L_60
L_61 ) ;
V_8 -> V_381 = V_446 ;
goto V_405;
}
V_25 = - V_235 ;
}
if ( V_25 < 0 ) {
F_176 ( V_6 ) ;
return V_25 ;
}
if ( V_8 -> V_381 == V_448 )
V_8 -> V_144 = 0 ;
V_6 -> V_398 = V_399 ;
V_6 -> V_449 = F_198 ;
return 0 ;
}
static int F_215 ( struct V_5 * V_6 )
{
if ( V_6 -> V_410 != 0x111d7605 &&
V_6 -> V_410 != 0x111d76d1 )
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
static void F_216 ( struct V_5 * V_6 , T_1 V_27 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
unsigned int V_158 = F_91 ( V_6 , V_27 ) ;
int V_70 ;
V_8 -> V_450 [ V_8 -> V_451 ] = V_27 ;
V_8 -> V_451 ++ ;
if ( F_138 ( V_158 ) == V_267 &&
F_135 ( V_158 ) != V_262 ) {
for ( V_70 = 0 ; V_70 < F_114 ( V_452 ) ; V_70 ++ ) {
if ( V_27 == V_452 [ V_70 ] ) {
V_8 -> V_453 [ V_8 -> V_454 ] = V_27 ;
V_8 -> V_454 ++ ;
}
}
}
}
static void F_217 ( struct V_5 * V_6 , T_1 V_27 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
V_8 -> V_455 [ V_8 -> V_456 ] = V_27 ;
V_8 -> V_456 ++ ;
}
static void F_218 ( struct V_5 * V_6 , T_1 V_27 )
{
int V_70 , V_185 ;
struct V_7 * V_8 = V_6 -> V_8 ;
for ( V_70 = 0 ; V_70 < V_8 -> V_456 ; V_70 ++ ) {
if ( F_136 ( V_6 ,
V_8 -> V_455 [ V_70 ] , V_27 ) >= 0 ) {
if ( ! V_8 -> V_457 [ V_70 ] ) {
V_8 -> V_457 [ V_70 ] = V_27 ;
V_8 -> V_458 [ V_70 ] = F_111 ( V_27 ,
3 , 0 , V_35 ) ;
}
for ( V_185 = 0 ; V_185 < V_8 -> V_454 ; V_185 ++ ) {
if ( F_136 ( V_6 , V_27 ,
V_8 -> V_453 [ V_185 ] ) >= 0 ) {
if ( ! V_8 -> V_459 [ V_70 ] )
V_8 -> V_459 [ V_70 ] = V_27 ;
break;
}
}
break;
}
}
}
static void F_219 ( struct V_5 * V_6 )
{
T_1 V_27 , V_460 ;
unsigned int V_217 , V_285 ;
struct V_7 * V_8 = V_6 -> V_8 ;
V_460 = V_6 -> V_293 + V_6 -> V_294 ;
for ( V_27 = V_6 -> V_293 ; V_27 < V_460 ; V_27 ++ ) {
V_217 = F_36 ( V_6 , V_27 ) ;
V_285 = F_102 ( V_217 ) ;
if ( V_285 == V_261 )
F_216 ( V_6 , V_27 ) ;
if ( V_285 == V_295 && ! ( V_217 & V_192 ) )
F_217 ( V_6 , V_27 ) ;
}
for ( V_27 = V_6 -> V_293 ; V_27 < V_460 ; V_27 ++ ) {
V_217 = F_36 ( V_6 , V_27 ) ;
V_285 = F_102 ( V_217 ) ;
if ( V_285 == V_286 )
F_218 ( V_6 , V_27 ) ;
}
V_8 -> V_98 = V_8 -> V_450 ;
V_8 -> V_97 = V_8 -> V_451 ;
V_8 -> V_106 = V_8 -> V_455 ;
V_8 -> V_129 = V_8 -> V_456 ;
V_8 -> V_246 = V_8 -> V_458 ;
V_8 -> V_290 = V_8 -> V_458 ;
V_8 -> V_245 = V_8 -> V_456 ;
V_8 -> V_54 = V_8 -> V_457 ;
V_8 -> V_244 = V_8 -> V_456 ;
V_8 -> V_18 = V_8 -> V_459 ;
V_8 -> V_75 = V_8 -> V_456 ;
V_8 -> V_260 = V_8 -> V_453 ;
V_8 -> V_258 = V_8 -> V_454 ;
}
static int F_220 ( struct V_5 * V_6 )
{
struct V_7 * V_8 ;
int V_361 = - 1 ;
int V_25 ;
V_25 = F_207 ( V_6 , 0 , NULL ) ;
if ( V_25 < 0 )
return V_25 ;
if ( F_215 ( V_6 ) ) {
F_48 ( V_6 , 0xa , 0x2101201f ) ;
F_48 ( V_6 , 0xf , 0x2181205e ) ;
}
V_6 -> V_461 = 0 ;
F_219 ( V_6 ) ;
V_8 = V_6 -> V_8 ;
V_8 -> V_289 = 0 ;
V_6 -> V_32 = V_462 ;
V_8 -> V_287 = 0x21 ;
V_8 -> V_337 = V_463 ;
V_8 -> V_336 = F_114 ( V_463 ) ;
V_8 -> V_30 . V_87 = V_8 -> V_87 ;
V_8 -> V_328 = V_464 ;
V_8 -> V_381 = F_211 ( V_6 ,
V_465 ,
V_466 ,
V_467 ) ;
if ( V_8 -> V_381 < 0 )
V_8 -> V_381 =
F_213 ( V_6 ,
V_465 , V_466 ,
V_468 ) ;
V_405:
if ( V_8 -> V_381 < 0 )
F_13 ( V_385 L_59 ,
V_6 -> V_386 ) ;
else
F_47 ( V_6 ,
V_469 [ V_8 -> V_381 ] ) ;
V_6 -> V_398 = V_399 ;
switch ( V_8 -> V_381 ) {
case V_470 :
V_8 -> V_328 = V_471 ;
break;
case V_472 :
V_361 = 0 ;
break;
case V_473 :
V_361 = 1 ;
break;
case V_474 :
V_8 -> V_224 = 0x08 ;
break;
case V_475 :
V_8 -> V_161 = 1 ;
break;
}
if ( F_192 ( V_6 , V_361 ) )
F_107 ( L_64 ,
V_8 -> V_93 ,
V_8 -> V_364 ) ;
if ( V_8 -> V_93 ) {
if ( ! V_8 -> V_338 ) {
V_8 -> V_225 |= V_8 -> V_93 ;
V_8 -> V_86 |= V_8 -> V_93 ;
V_8 -> V_223 |= V_8 -> V_93 ;
} else {
V_6 -> V_398 . V_476 =
F_205 ;
}
}
if ( V_8 -> V_224 ) {
V_8 -> V_225 |= V_8 -> V_224 ;
V_8 -> V_86 |= V_8 -> V_224 ;
V_8 -> V_222 = true ;
V_8 -> V_223 |= V_8 -> V_224 ;
}
V_25 = F_147 ( V_6 ) ;
if ( ! V_25 ) {
if ( V_8 -> V_381 < 0 ) {
F_112 ( V_212 L_60
L_61 ) ;
V_8 -> V_381 = V_477 ;
goto V_405;
}
V_25 = - V_235 ;
}
if ( V_25 < 0 ) {
F_176 ( V_6 ) ;
return V_25 ;
}
V_6 -> V_449 = F_195 ;
return 0 ;
}
static int F_221 ( struct V_5 * V_6 ,
T_1 V_478 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
int V_50 ;
for ( V_50 = 0 ; V_50 < V_8 -> V_97 ; V_50 ++ )
if ( V_8 -> V_98 [ V_50 ] == V_478 )
break;
if ( ( V_50 + 2 ) >= V_8 -> V_97 )
return 0 ;
if ( F_186 ( V_6 , V_50 + 1 ) != V_262 )
return 2 ;
if ( F_186 ( V_6 , V_50 + 2 ) != V_262 )
return 2 ;
if ( F_186 ( V_6 , V_50 ) != V_262 )
return 1 ;
else
return 0 ;
}
static int F_222 ( struct V_1 * V_2 ,
struct V_10 * V_11 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = V_6 -> V_8 ;
V_11 -> V_14 . integer . V_14 [ 0 ] = ! ! ( V_8 -> V_223 & 0x20 ) ;
return 0 ;
}
static int F_223 ( struct V_1 * V_2 ,
struct V_10 * V_11 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = V_6 -> V_8 ;
unsigned int V_223 ;
V_223 = ( V_8 -> V_223 & ~ 0x20 ) |
( V_11 -> V_14 . integer . V_14 [ 0 ] ? 0x20 : 0 ) ;
if ( V_223 == V_8 -> V_223 )
return 0 ;
V_8 -> V_223 = V_223 ;
F_120 ( V_6 , V_8 -> V_225 , V_8 -> V_86 , V_8 -> V_223 ) ;
return 1 ;
}
static int F_224 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
if ( ! F_83 ( V_8 , & V_479 ,
L_65 , 0 ) )
return - V_156 ;
V_8 -> V_225 |= 0x20 ;
V_8 -> V_86 |= 0x20 ;
V_8 -> V_223 |= 0x20 ;
return 0 ;
}
static int F_225 ( struct V_5 * V_6 )
{
struct V_7 * V_8 ;
const struct V_480 * V_481 = V_482 ;
unsigned int V_483 ;
int V_25 ;
V_25 = F_207 ( V_6 , V_484 ,
V_485 ) ;
if ( V_25 < 0 )
return V_25 ;
V_8 = V_6 -> V_8 ;
V_8 -> V_289 = 0 ;
V_6 -> V_398 = V_399 ;
switch ( V_6 -> V_410 ) {
case 0x111d76b6 :
case 0x111d76b7 :
break;
case 0x111d7603 :
case 0x111d7608 :
V_8 -> V_97 -- ;
default:
V_8 -> V_98 = V_486 ;
}
V_8 -> V_336 = F_114 ( V_487 ) ;
V_8 -> V_381 = F_211 ( V_6 ,
V_488 ,
V_489 ,
V_490 ) ;
V_405:
if ( V_8 -> V_381 < 0 )
F_13 ( V_385 L_59 ,
V_6 -> V_386 ) ;
else
F_47 ( V_6 ,
V_491 [ V_8 -> V_381 ] ) ;
if ( V_8 -> V_381 != V_492 ) {
V_8 -> V_225 = 0x01 ;
V_8 -> V_86 = 0x01 ;
V_8 -> V_223 = 0x01 ;
}
V_8 -> V_260 = V_493 ;
V_8 -> V_18 = V_494 ;
V_8 -> V_245 = V_495 ;
V_8 -> V_246 = V_496 ;
V_8 -> V_290 = V_497 ;
switch ( V_6 -> V_410 ) {
case 0x111d76b6 :
case 0x111d76b7 :
V_481 ++ ;
case 0x111d76b4 :
case 0x111d76b5 :
V_6 -> V_32 = V_498 ;
V_8 -> V_258 = F_187 ( V_6 ,
V_493 ,
V_499 ) ;
break;
case 0x111d7608 :
switch ( V_8 -> V_381 ) {
case V_500 :
V_25 = F_154 ( V_6 , V_6 -> V_65 ,
V_358 , 0x02 ) ;
if ( V_25 < 0 )
return V_25 ;
F_21 ( V_6 , V_6 -> V_65 , 0 ,
V_501 , 0x02 ) ;
F_157 ( V_6 , V_6 -> V_65 , 0 ) ;
V_8 -> V_225 |= 0x02 ;
break;
}
if ( ( V_6 -> V_502 & 0xf ) == 0 ||
( V_6 -> V_502 & 0xf ) == 1 )
V_8 -> V_103 = 40 ;
V_481 ++ ;
F_48 ( V_6 , 0x0f , 0x40f000f0 ) ;
F_48 ( V_6 , 0x19 , 0x40f000f3 ) ;
V_8 -> V_260 = V_503 ;
V_8 -> V_258 = F_187 ( V_6 ,
V_503 ,
V_499 - 1 ) ;
break;
case 0x111d7603 :
if ( ( V_6 -> V_502 & 0xf ) == 1 )
V_8 -> V_103 = 40 ;
default:
V_6 -> V_32 = V_498 ;
V_8 -> V_258 = F_187 ( V_6 ,
V_493 ,
V_499 ) ;
break;
}
if ( F_102 ( F_36 ( V_6 , 0x28 ) ) == V_504 )
V_8 -> V_328 = V_505 ;
if ( F_36 ( V_6 , 0xa ) & V_254 )
F_226 ( V_6 , V_481 ) ;
V_8 -> V_95 = V_506 ;
V_8 -> V_62 = 0x50 ;
V_8 -> V_67 = 0 ;
V_8 -> V_108 = 1 ;
V_8 -> V_287 = 0x26 ;
V_8 -> V_54 = V_507 ;
V_8 -> V_106 = V_508 ;
V_8 -> V_28 = V_509 ;
V_8 -> V_337 = V_487 ;
V_8 -> V_244 = F_114 ( V_507 ) ;
V_8 -> V_129 = F_114 ( V_508 ) ;
V_8 -> V_75 = F_114 ( V_494 ) ;
V_8 -> V_78 = F_221 ( V_6 , 0x1e ) ;
F_13 ( L_66 , V_8 -> V_381 ) ;
switch ( V_8 -> V_381 ) {
case V_500 :
F_48 ( V_6 , 0x0e , 0x01813040 ) ;
F_70 ( V_6 , 0x0e ,
V_42 | V_357 ) ;
case V_510 :
V_8 -> V_258 = 0 ;
V_8 -> V_78 = 0 ;
V_8 -> V_75 = 0 ;
break;
case V_511 :
case V_512 :
V_8 -> V_258 = 1 ;
V_8 -> V_78 = 0 ;
V_8 -> V_75 = 1 ;
break;
case V_513 :
V_8 -> V_258 = 1 ;
V_8 -> V_78 = 1 ;
V_8 -> V_75 = 1 ;
case V_514 :
V_8 -> V_93 = 0x01 ;
case V_515 :
F_48 ( V_6 , 0x0d , 0x90170010 ) ;
F_70 ( V_6 , 0x0d , V_43 ) ;
V_8 -> V_144 = 1 ;
break;
case V_516 :
V_8 -> V_258 = 1 ;
V_8 -> V_75 = 1 ;
V_8 -> V_78 = 1 ;
V_8 -> V_93 = 0x08 ;
break;
}
if ( F_194 ( V_6 -> V_356 ) ) {
V_483 = F_91 ( V_6 , 0x0f ) ;
if ( F_138 ( V_483 ) == V_517 ||
F_138 ( V_483 ) == V_302 ||
F_138 ( V_483 ) == V_518 ) {
V_483 = ( V_483 & ( ~ V_519 ) )
| ( V_518 <<
V_520 ) ;
V_483 = ( V_483 & ( ~ ( V_521
| V_522 ) ) )
| 0x1f ;
F_48 ( V_6 , 0x0f , V_483 ) ;
}
}
if ( F_192 ( V_6 , 1 ) )
F_107 ( L_64 ,
V_8 -> V_93 ,
V_8 -> V_364 ) ;
if ( V_8 -> V_93 ) {
if ( ! V_8 -> V_338 ) {
V_8 -> V_225 |= V_8 -> V_93 ;
V_8 -> V_86 |= V_8 -> V_93 ;
V_8 -> V_223 |= V_8 -> V_93 ;
} else {
V_6 -> V_398 . V_476 =
F_205 ;
}
}
V_8 -> V_30 . V_87 = V_8 -> V_87 ;
V_25 = F_147 ( V_6 ) ;
if ( ! V_25 ) {
if ( V_8 -> V_381 < 0 ) {
F_112 ( V_212 L_60
L_61 ) ;
V_8 -> V_381 = V_492 ;
goto V_405;
}
V_25 = - V_235 ;
}
if ( V_25 < 0 ) {
F_176 ( V_6 ) ;
return V_25 ;
}
if ( V_8 -> V_381 == V_514 ||
V_8 -> V_381 == V_515 ) {
unsigned int V_523 ;
V_523 = F_191 ( V_6 , 0x1 , V_359 ) ;
V_523 &= V_360 ;
if ( V_523 >= 6 )
F_224 ( V_6 ) ;
}
V_6 -> V_449 = F_198 ;
return 0 ;
}
static int F_227 ( struct V_5 * V_6 )
{
struct V_7 * V_8 ;
int V_25 ;
V_25 = F_207 ( V_6 , F_114 ( V_524 ) ,
V_524 ) ;
if ( V_25 < 0 )
return V_25 ;
V_8 = V_6 -> V_8 ;
V_8 -> V_289 = 1 ;
V_8 -> V_381 = F_211 ( V_6 , V_525 ,
V_526 ,
V_527 ) ;
if ( V_8 -> V_381 == V_528 ) {
V_8 -> V_225 = V_8 -> V_86 = 0x03 ;
V_8 -> V_223 = 0x03 ;
F_112 ( V_385 L_67 , V_6 -> V_356 ) ;
switch ( V_6 -> V_356 ) {
case 0x106b0800 :
V_8 -> V_381 = V_529 ;
break;
case 0x106b0600 :
case 0x106b0700 :
V_8 -> V_381 = V_530 ;
break;
case 0x106b0e00 :
case 0x106b0f00 :
case 0x106b1600 :
case 0x106b1700 :
case 0x106b0200 :
case 0x106b1e00 :
V_8 -> V_381 = V_531 ;
break;
case 0x106b1a00 :
case 0x00000100 :
V_8 -> V_381 = V_532 ;
break;
case 0x106b0a00 :
case 0x106b2200 :
V_8 -> V_381 = V_533 ;
break;
default:
V_8 -> V_381 = V_531 ;
break;
}
}
V_405:
if ( V_8 -> V_381 < 0 )
F_13 ( V_385 L_59 ,
V_6 -> V_386 ) ;
else
F_47 ( V_6 ,
V_534 [ V_8 -> V_381 ] ) ;
V_8 -> V_106 = V_535 ;
V_8 -> V_54 = V_536 ;
V_8 -> V_244 = F_114 ( V_536 ) ;
V_8 -> V_129 = F_114 ( V_535 ) ;
V_8 -> V_258 = 0 ;
V_8 -> V_336 = 0 ;
V_8 -> V_328 = V_537 ;
V_8 -> V_245 = V_538 ;
V_8 -> V_246 = V_539 ;
V_8 -> V_290 = V_540 ;
V_8 -> V_30 . V_87 = V_8 -> V_87 ;
V_25 = F_147 ( V_6 ) ;
if ( ! V_25 ) {
if ( V_8 -> V_381 < 0 ) {
F_112 ( V_212 L_60
L_61 ) ;
V_8 -> V_381 = V_541 ;
goto V_405;
}
V_25 = - V_235 ;
}
if ( V_25 < 0 ) {
F_176 ( V_6 ) ;
return V_25 ;
}
V_6 -> V_398 = V_399 ;
F_228 ( V_6 , 0x12 , V_35 ,
( 0 << V_542 ) |
( 2 << V_209 ) |
( 0x27 << V_207 ) |
( 0 << V_240 ) ) ;
return 0 ;
}
static int F_229 ( struct V_5 * V_6 )
{
struct V_7 * V_8 ;
int V_25 ;
V_25 = F_207 ( V_6 , F_114 ( V_543 ) ,
V_543 ) ;
if ( V_25 < 0 )
return V_25 ;
V_8 = V_6 -> V_8 ;
V_8 -> V_289 = 1 ;
V_6 -> V_32 = V_544 ;
V_8 -> V_381 = F_211 ( V_6 , V_545 ,
V_546 ,
V_547 ) ;
V_405:
if ( V_8 -> V_381 < 0 )
F_13 ( V_385 L_59 ,
V_6 -> V_386 ) ;
else
F_47 ( V_6 ,
V_548 [ V_8 -> V_381 ] ) ;
V_8 -> V_287 = 0x23 ;
V_8 -> V_106 = V_549 ;
V_8 -> V_129 = F_114 ( V_549 ) ;
V_8 -> V_54 = V_550 ;
V_8 -> V_244 = F_114 ( V_550 ) ;
V_8 -> V_28 = V_551 ;
V_8 -> V_78 = F_114 ( V_551 ) ;
V_8 -> V_249 = V_552 ;
V_8 -> V_320 = V_553 ;
V_8 -> V_30 . V_87 = V_8 -> V_87 ;
if ( V_8 -> V_381 != V_554 ) {
V_8 -> V_324 = V_8 -> V_225 = 0x01 ;
V_8 -> V_86 = V_8 -> V_223 = 0x01 ;
}
switch ( V_8 -> V_381 ) {
case V_555 :
case V_556 :
V_8 -> V_258 = 0 ;
V_8 -> V_328 = V_557 ;
break;
case V_558 :
switch ( V_6 -> V_356 ) {
case 0x10280209 :
case 0x1028022e :
F_48 ( V_6 , 0x21 , 0x01442070 ) ;
break;
}
F_48 ( V_6 , 0x0c , 0x90a79130 ) ;
F_48 ( V_6 , 0x0f , 0x0227011f ) ;
F_48 ( V_6 , 0x0e , 0x02a79130 ) ;
case V_559 :
if ( V_6 -> V_356 != 0x1028022f ) {
V_8 -> V_324 = V_8 -> V_225 = 0x04 ;
V_8 -> V_86 = V_8 -> V_223 = 0x04 ;
}
V_8 -> V_260 = V_560 ;
V_8 -> V_258 = V_561 ;
V_8 -> V_328 = V_562 ;
V_8 -> V_18 = V_563 ;
V_8 -> V_75 = F_114 ( V_563 ) ;
break;
case V_564 :
V_8 -> V_258 = 0 ;
V_8 -> V_328 = V_565 ;
break;
default:
V_8 -> V_258 = 0 ;
V_8 -> V_328 = V_566 ;
break;
}
V_8 -> V_245 = V_567 ;
V_8 -> V_246 = V_568 ;
V_8 -> V_290 = V_569 ;
V_8 -> V_336 = 0 ;
V_8 -> V_95 = V_570 ;
V_8 -> V_62 = 0x40 ;
V_8 -> V_67 = 0 ;
V_8 -> V_326 = 1 ;
V_25 = F_147 ( V_6 ) ;
if ( ! V_25 ) {
if ( V_8 -> V_381 < 0 ) {
F_112 ( V_212 L_60
L_61 ) ;
V_8 -> V_381 = V_554 ;
goto V_405;
}
V_25 = - V_235 ;
}
if ( V_25 < 0 ) {
F_176 ( V_6 ) ;
return V_25 ;
}
V_6 -> V_398 = V_399 ;
V_6 -> V_449 = F_200 ;
V_6 -> V_344 -> V_571 = 1 ;
if ( V_8 -> V_381 == V_572 )
V_8 -> V_144 = 0 ;
return 0 ;
}
static int F_230 ( struct V_5 * V_6 )
{
struct V_7 * V_8 ;
int V_25 ;
V_25 = F_207 ( V_6 , F_114 ( V_573 ) ,
V_573 ) ;
if ( V_25 < 0 )
return V_25 ;
V_8 = V_6 -> V_8 ;
V_8 -> V_289 = 1 ;
V_8 -> V_381 = F_211 ( V_6 , V_574 ,
V_575 ,
V_576 ) ;
V_405:
if ( V_8 -> V_381 < 0 )
F_13 ( V_385 L_59 ,
V_6 -> V_386 ) ;
else
F_47 ( V_6 ,
V_577 [ V_8 -> V_381 ] ) ;
V_8 -> V_287 = 0x23 ;
V_8 -> V_106 = V_578 ;
V_8 -> V_129 = F_114 ( V_578 ) ;
V_8 -> V_54 = V_579 ;
V_8 -> V_244 = F_114 ( V_579 ) ;
V_8 -> V_28 = V_580 ;
V_8 -> V_78 = F_114 ( V_580 ) ;
V_8 -> V_260 = V_581 ;
V_8 -> V_258 = V_582 ;
V_8 -> V_18 = V_583 ;
V_8 -> V_75 = F_114 ( V_583 ) ;
V_8 -> V_336 = 0 ;
V_8 -> V_328 = V_584 ;
V_8 -> V_95 = V_585 ;
V_8 -> V_245 = V_586 ;
V_8 -> V_246 = V_587 ;
V_8 -> V_290 = V_588 ;
V_8 -> V_62 = 0x40 ;
V_8 -> V_67 = 0 ;
if ( V_8 -> V_381 != V_589 )
V_8 -> V_326 = 1 ;
V_8 -> V_30 . V_87 = V_8 -> V_87 ;
switch ( V_8 -> V_381 ) {
case V_590 :
F_48 ( V_6 , 0x1f , 0x01441030 ) ;
F_48 ( V_6 , 0x20 , 0x1c410030 ) ;
V_25 = F_154 ( V_6 , V_6 -> V_65 , V_358 , 0x01 ) ;
if ( V_25 < 0 )
return V_25 ;
F_21 ( V_6 , V_6 -> V_65 , 0 ,
V_501 , 0x10 ) ;
F_157 ( V_6 , V_6 -> V_65 , 0 ) ;
V_8 -> V_86 = 0x0b ;
V_8 -> V_324 = 0x01 ;
V_8 -> V_225 = 0x1b ;
V_8 -> V_325 = 0x10 ;
V_8 -> V_223 = 0x01 ;
break;
case V_591 :
break;
default:
V_8 -> V_324 = V_8 -> V_225 = V_8 -> V_86 = 0x1 ;
V_8 -> V_223 = 0x01 ;
break;
}
V_25 = F_147 ( V_6 ) ;
if ( ! V_25 ) {
if ( V_8 -> V_381 < 0 ) {
F_112 ( V_212 L_60
L_61 ) ;
V_8 -> V_381 = V_591 ;
goto V_405;
}
V_25 = - V_235 ;
}
if ( V_25 < 0 ) {
F_176 ( V_6 ) ;
return V_25 ;
}
V_6 -> V_398 = V_399 ;
V_6 -> V_449 = F_199 ;
return 0 ;
}
static int F_231 ( struct V_5 * V_6 )
{
struct V_7 * V_8 ;
int V_25 ;
V_25 = F_207 ( V_6 , F_114 ( V_592 ) ,
V_592 ) ;
if ( V_25 < 0 )
return V_25 ;
V_8 = V_6 -> V_8 ;
V_8 -> V_289 = 1 ;
V_8 -> V_381 = F_211 ( V_6 , V_593 ,
V_594 ,
V_595 ) ;
if ( V_8 -> V_381 < 0 )
F_13 ( V_385 L_59 ,
V_6 -> V_386 ) ;
else
F_47 ( V_6 ,
V_596 [ V_8 -> V_381 ] ) ;
V_8 -> V_30 . V_87 = V_8 -> V_87 ;
V_8 -> V_129 = F_114 ( V_597 ) ;
V_8 -> V_106 = V_597 ;
V_8 -> V_244 = F_114 ( V_598 ) ;
V_8 -> V_54 = V_598 ;
V_8 -> V_328 = V_599 ;
V_8 -> V_245 = 1 ;
V_8 -> V_246 = V_600 ;
V_8 -> V_290 = V_601 ;
V_25 = F_147 ( V_6 ) ;
if ( V_25 < 0 ) {
F_176 ( V_6 ) ;
return - V_235 ;
}
V_8 -> V_46 = & V_8 -> V_167 ;
V_6 -> V_398 = V_399 ;
return 0 ;
}
static int T_3 F_232 ( void )
{
return F_233 ( & V_602 ) ;
}
static void T_4 F_234 ( void )
{
F_235 ( & V_602 ) ;
}
