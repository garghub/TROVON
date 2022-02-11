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
V_8 -> V_30 . V_31 ) ;
if ( V_25 < 0 )
return V_25 ;
V_25 = F_39 ( V_6 ,
& V_8 -> V_30 ) ;
if ( V_25 < 0 )
return V_25 ;
V_8 -> V_30 . V_82 = 1 ;
}
if ( V_8 -> V_83 && ! ( V_8 -> V_84 & 0x01 ) ) {
V_25 = F_40 ( V_6 , V_8 -> V_83 ) ;
if ( V_25 < 0 )
return V_25 ;
}
F_41 ( V_6 , V_8 -> V_30 . V_85 [ 0 ] ,
V_35 , V_69 ) ;
V_69 [ 2 ] += V_69 [ 3 ] * V_8 -> V_86 ;
V_69 [ 3 ] |= V_87 ;
V_25 = F_42 ( V_6 , L_4 ,
V_69 , V_88 ,
L_5 ) ;
if ( V_25 < 0 )
return V_25 ;
V_25 = F_43 ( V_6 , L_6 ,
NULL , V_88 ,
L_7 , true ,
& V_8 -> V_89 . V_90 ) ;
if ( V_25 < 0 )
return V_25 ;
if ( V_8 -> V_91 ) {
V_8 -> V_89 . V_92 = F_29 ;
V_25 = F_44 ( V_6 , & V_8 -> V_89 , true ) ;
if ( V_25 < 0 )
return V_25 ;
}
if ( V_8 -> V_93 &&
F_33 ( V_6 , L_8 ) == 1 ) {
V_25 = F_32 ( V_6 , V_8 -> V_93 ) ;
if ( V_25 < 0 )
return V_25 ;
}
F_45 ( V_6 ) ;
V_25 = F_46 ( V_6 , & V_8 -> V_94 ) ;
if ( V_25 < 0 )
return V_25 ;
return 0 ;
}
static void F_47 ( struct V_5 * V_6 ,
const unsigned int * V_95 )
{
int V_70 ;
struct V_7 * V_8 = V_6 -> V_8 ;
if ( ! V_95 )
return;
for ( V_70 = 0 ; V_70 < V_8 -> V_96 ; V_70 ++ )
if ( V_8 -> V_97 [ V_70 ] && V_95 [ V_70 ] )
F_48 ( V_6 , V_8 -> V_97 [ V_70 ] ,
V_95 [ V_70 ] ) ;
}
static int F_49 ( struct V_98 * V_99 ,
struct V_5 * V_6 ,
struct V_100 * V_101 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
if ( V_8 -> V_102 )
F_50 ( V_8 -> V_102 ) ;
return F_51 ( V_6 , & V_8 -> V_30 , V_101 ,
V_99 ) ;
}
static int F_52 ( struct V_98 * V_99 ,
struct V_5 * V_6 ,
unsigned int V_103 ,
unsigned int V_104 ,
struct V_100 * V_101 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
return F_53 ( V_6 , & V_8 -> V_30 , V_103 , V_104 , V_101 ) ;
}
static int F_54 ( struct V_98 * V_99 ,
struct V_5 * V_6 ,
struct V_100 * V_101 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
return F_55 ( V_6 , & V_8 -> V_30 ) ;
}
static int F_56 ( struct V_98 * V_99 ,
struct V_5 * V_6 ,
struct V_100 * V_101 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
return F_57 ( V_6 , & V_8 -> V_30 ) ;
}
static int F_58 ( struct V_98 * V_99 ,
struct V_5 * V_6 ,
struct V_100 * V_101 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
return F_59 ( V_6 , & V_8 -> V_30 ) ;
}
static int F_60 ( struct V_98 * V_99 ,
struct V_5 * V_6 ,
unsigned int V_103 ,
unsigned int V_104 ,
struct V_100 * V_101 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
return F_61 ( V_6 , & V_8 -> V_30 ,
V_103 , V_104 , V_101 ) ;
}
static int F_62 ( struct V_98 * V_99 ,
struct V_5 * V_6 ,
struct V_100 * V_101 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
return F_63 ( V_6 , & V_8 -> V_30 ) ;
}
static int F_64 ( struct V_98 * V_99 ,
struct V_5 * V_6 ,
unsigned int V_103 ,
unsigned int V_104 ,
struct V_100 * V_101 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
T_1 V_27 = V_8 -> V_105 [ V_101 -> V_106 ] ;
if ( V_8 -> V_107 ) {
F_50 ( 40 ) ;
F_65 ( V_6 , V_27 , 0 ,
V_108 , V_109 ) ;
}
F_66 ( V_6 , V_27 , V_103 , 0 , V_104 ) ;
return 0 ;
}
static int F_67 ( struct V_98 * V_99 ,
struct V_5 * V_6 ,
struct V_100 * V_101 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
T_1 V_27 = V_8 -> V_105 [ V_101 -> V_106 ] ;
F_68 ( V_6 , V_27 ) ;
if ( V_8 -> V_107 )
F_65 ( V_6 , V_27 , 0 ,
V_108 , V_110 ) ;
return 0 ;
}
static int F_69 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
struct V_111 * V_112 = V_8 -> V_113 ;
V_6 -> V_114 = 1 ;
V_6 -> V_115 = V_112 ;
V_112 -> V_116 = L_9 ;
V_112 -> V_117 [ V_118 ] = V_119 ;
V_112 -> V_117 [ V_118 ] . V_27 =
V_8 -> V_30 . V_85 [ 0 ] ;
V_112 -> V_117 [ V_120 ] = V_121 ;
V_112 -> V_117 [ V_120 ] . V_27 = V_8 -> V_105 [ 0 ] ;
V_112 -> V_117 [ V_120 ] . V_122 = V_8 -> V_123 ;
if ( V_8 -> V_124 ) {
V_6 -> V_114 ++ ;
V_112 ++ ;
V_112 -> V_116 = L_10 ;
V_112 -> V_117 [ V_118 ] = V_125 ;
}
if ( V_8 -> V_30 . V_31 || V_8 -> V_83 ) {
V_6 -> V_114 ++ ;
V_112 ++ ;
V_112 -> V_116 = L_11 ;
V_112 -> V_126 = V_8 -> V_94 . V_127 [ 0 ] ;
if ( V_8 -> V_30 . V_31 ) {
V_112 -> V_117 [ V_118 ] = V_128 ;
V_112 -> V_117 [ V_118 ] . V_27 = V_8 -> V_30 . V_31 ;
}
if ( V_8 -> V_83 ) {
V_112 -> V_117 [ V_120 ] = V_129 ;
V_112 -> V_117 [ V_120 ] . V_27 = V_8 -> V_83 ;
}
}
return 0 ;
}
static void F_70 ( struct V_5 * V_6 , T_1 V_27 , int V_130 )
{
F_15 ( V_6 , V_27 , V_130 ) ;
}
static int F_71 ( struct V_1 * V_2 ,
struct V_10 * V_11 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = V_6 -> V_8 ;
V_11 -> V_14 . integer . V_14 [ 0 ] = ! ! V_8 -> V_131 ;
return 0 ;
}
static int F_72 ( struct V_1 * V_2 ,
struct V_10 * V_11 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = V_6 -> V_8 ;
int V_27 = V_2 -> V_66 ;
V_8 -> V_131 = V_11 -> V_14 . integer . V_14 [ 0 ] ? V_27 : 0 ;
F_73 ( V_6 , V_27 ) ;
return 1 ;
}
static int F_74 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
int V_70 ;
static const char * const V_132 [] = {
L_12 , L_13 , L_14
} ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = V_6 -> V_8 ;
T_1 V_27 = V_2 -> V_66 ;
if ( V_27 == V_8 -> V_133 || V_27 == V_8 -> V_134 )
V_70 = 3 ;
else
V_70 = 2 ;
V_4 -> type = V_135 ;
V_4 -> V_14 . V_15 . V_56 = V_70 ;
V_4 -> V_77 = 1 ;
if ( V_4 -> V_14 . V_15 . V_16 >= V_70 )
V_4 -> V_14 . V_15 . V_16 = V_70 - 1 ;
strcpy ( V_4 -> V_14 . V_15 . V_116 ,
V_132 [ V_4 -> V_14 . V_15 . V_16 ] ) ;
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
else if ( V_45 == V_136 )
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
V_36 = V_136 ;
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
char * V_132 [ 2 ] ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = V_6 -> V_8 ;
if ( V_2 -> V_66 == V_8 -> V_134 )
V_132 [ 0 ] = L_13 ;
else
V_132 [ 0 ] = L_12 ;
V_132 [ 1 ] = L_14 ;
V_4 -> type = V_135 ;
V_4 -> V_14 . V_15 . V_56 = 2 ;
V_4 -> V_77 = 1 ;
if ( V_4 -> V_14 . V_15 . V_16 >= 2 )
V_4 -> V_14 . V_15 . V_16 = 1 ;
strcpy ( V_4 -> V_14 . V_15 . V_116 ,
V_132 [ V_4 -> V_14 . V_15 . V_16 ] ) ;
return 0 ;
}
static int F_79 ( struct V_1 * V_2 , struct V_10 * V_11 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = V_6 -> V_8 ;
T_1 V_27 = V_2 -> V_66 ;
int V_137 = ( V_27 == V_8 -> V_133 ) ? 1 : 0 ;
V_11 -> V_14 . V_15 . V_16 [ 0 ] = V_8 -> V_138 [ V_137 ] ;
return 0 ;
}
static int F_80 ( struct V_1 * V_2 , struct V_10 * V_11 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = V_6 -> V_8 ;
T_1 V_27 = V_2 -> V_66 ;
int V_137 = ( V_27 == V_8 -> V_133 ) ? 1 : 0 ;
unsigned short V_26 = ! ! V_11 -> V_14 . V_15 . V_16 [ 0 ] ;
V_8 -> V_138 [ V_137 ] = V_26 ;
if ( V_26 )
F_70 ( V_6 , V_27 , V_43 ) ;
else {
unsigned int V_37 = V_42 ;
if ( V_137 )
V_37 |= F_76 ( V_6 , V_27 ) ;
F_70 ( V_6 , V_27 , V_37 ) ;
}
if ( V_8 -> V_139 )
F_73 ( V_6 , V_27 ) ;
return 1 ;
}
static int F_81 ( struct V_1 * V_2 ,
struct V_10 * V_11 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = V_6 -> V_8 ;
V_11 -> V_14 . integer . V_14 [ 0 ] = V_8 -> V_140 ;
return 0 ;
}
static int F_82 ( struct V_1 * V_2 ,
struct V_10 * V_11 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = V_6 -> V_8 ;
T_1 V_27 = V_2 -> V_66 & 0xff ;
unsigned int V_26 = ! ! V_11 -> V_14 . integer . V_14 [ 0 ] ;
if ( V_8 -> V_140 == V_26 )
return 0 ;
V_8 -> V_140 = V_26 ;
F_21 ( V_6 , V_27 , 0 , V_141 ,
V_8 -> V_140 ? 0x4 : 0x0 ) ;
return 1 ;
}
static struct V_142 *
F_83 ( struct V_7 * V_8 ,
const struct V_142 * V_143 ,
const char * V_116 ,
unsigned int V_144 )
{
struct V_142 * V_145 ;
F_84 ( & V_8 -> V_146 , sizeof( * V_145 ) , 32 ) ;
V_145 = F_85 ( & V_8 -> V_146 ) ;
if ( ! V_145 )
return NULL ;
* V_145 = * V_143 ;
V_145 -> V_116 = F_86 ( V_116 , V_147 ) ;
if ( ! V_145 -> V_116 ) {
memset ( V_145 , 0 , sizeof( * V_145 ) ) ;
V_8 -> V_146 . V_148 -- ;
return NULL ;
}
V_145 -> V_149 = V_144 ;
return V_145 ;
}
static int F_87 ( struct V_7 * V_8 ,
const struct V_142 * V_143 ,
int V_50 , const char * V_116 ,
unsigned long V_26 )
{
struct V_142 * V_145 = F_83 ( V_8 , V_143 , V_116 ,
V_150 ) ;
if ( ! V_145 )
return - V_151 ;
V_145 -> V_57 = V_50 ;
V_145 -> V_66 = V_26 ;
return 0 ;
}
static inline int F_88 ( struct V_7 * V_8 ,
int type , int V_50 , const char * V_116 ,
unsigned long V_26 )
{
return F_87 ( V_8 ,
& V_152 [ type ] ,
V_50 , V_116 , V_26 ) ;
}
static inline int F_89 ( struct V_7 * V_8 , int type ,
const char * V_116 , unsigned long V_26 )
{
return F_88 ( V_8 , type , 0 , V_116 , V_26 ) ;
}
static inline int F_90 ( struct V_5 * V_6 ,
T_1 V_27 , int V_50 )
{
int V_153 = F_91 ( V_6 , V_27 ) ;
int V_154 = 0 ;
struct V_7 * V_8 = V_6 -> V_8 ;
char V_116 [ 22 ] ;
if ( F_92 ( V_153 ) != V_155 ) {
if ( F_76 ( V_6 , V_27 ) == V_136
&& V_27 == V_8 -> V_134 )
V_154 = V_156 ;
else if ( F_93 ( V_6 , V_27 )
& ( V_157 << V_158 ) )
V_154 = V_159 ;
else if ( V_27 == V_8 -> V_133 )
V_154 = V_156 ;
}
if ( V_154 ) {
F_94 ( V_6 , V_27 , & V_8 -> V_94 ,
V_116 , sizeof( V_116 ) , NULL ) ;
return F_89 ( V_6 -> V_8 , V_154 ,
strcat ( V_116 , L_15 ) , V_27 ) ;
}
return 0 ;
}
static int F_95 ( struct V_7 * V_8 )
{
struct V_142 * V_145 ;
struct V_22 * V_49 = & V_8 -> V_160 ;
if ( V_8 -> V_74 )
return 0 ;
if ( ! V_8 -> V_123 || V_49 -> V_33 <= 1 )
return 0 ;
V_145 = F_83 ( V_8 , & V_161 ,
V_161 . V_116 , 0 ) ;
if ( ! V_145 )
return - V_151 ;
V_145 -> V_77 = V_8 -> V_123 ;
return 0 ;
}
static T_1 F_96 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
struct V_162 * V_163 = & V_8 -> V_94 ;
T_1 V_27 ;
unsigned int V_164 ;
int V_70 ;
if ( V_163 -> V_165 != V_166 )
return 0 ;
for ( V_70 = 0 ; V_70 < V_163 -> V_167 ; V_70 ++ ) {
if ( V_163 -> V_168 [ V_70 ] . type == V_169 ) {
V_27 = V_163 -> V_168 [ V_70 ] . V_170 ;
V_164 = F_93 ( V_6 , V_27 ) ;
if ( V_164 & V_171 )
return V_27 ;
}
}
return 0 ;
}
static T_1 F_97 ( struct V_5 * V_6 , T_1 * V_172 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
struct V_162 * V_163 = & V_8 -> V_94 ;
unsigned int V_153 , V_164 ;
int V_70 ;
* V_172 = 0 ;
if ( V_163 -> V_165 != V_166 )
return 0 ;
for ( V_70 = 0 ; V_70 < V_163 -> V_167 ; V_70 ++ ) {
T_1 V_27 = V_163 -> V_168 [ V_70 ] . V_170 ;
if ( V_163 -> V_168 [ V_70 ] . type != V_173 )
continue;
V_153 = F_91 ( V_6 , V_27 ) ;
if ( F_92 ( V_153 ) != V_155 ) {
V_164 = F_93 ( V_6 , V_27 ) ;
if ( V_164 & V_171 ) {
* V_172 = F_98 ( V_6 , V_27 ) ;
if ( * V_172 )
return V_27 ;
}
}
}
return 0 ;
}
static int F_99 ( struct V_7 * V_8 , T_1 V_27 )
{
int V_70 ;
for ( V_70 = 0 ; V_70 < V_8 -> V_30 . V_174 ; V_70 ++ ) {
if ( V_8 -> V_30 . V_85 [ V_70 ] == V_27 )
return 1 ;
}
return 0 ;
}
static int F_100 ( struct V_7 * V_8 , T_1 V_27 )
{
int V_70 ;
if ( F_99 ( V_8 , V_27 ) )
return 1 ;
for ( V_70 = 0 ; V_70 < V_8 -> V_94 . V_175 ; V_70 ++ )
if ( V_8 -> V_176 [ V_70 ] == V_27 )
return 1 ;
for ( V_70 = 0 ; V_70 < V_8 -> V_94 . V_177 ; V_70 ++ )
if ( V_8 -> V_178 [ V_70 ] == V_27 )
return 1 ;
return 0 ;
}
static T_1 F_98 ( struct V_5 * V_6 , T_1 V_27 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
struct V_162 * V_163 = & V_8 -> V_94 ;
int V_179 , V_180 ;
T_1 V_181 [ V_182 ] , V_183 ;
unsigned int V_79 , V_184 ;
V_180 = F_101 ( V_6 , V_27 , V_181 ,
V_182 ) ;
while ( V_180 == 1 && ( F_102 ( F_36 ( V_6 , V_181 [ 0 ] ) )
!= V_185 ) ) {
V_27 = V_181 [ 0 ] ;
V_180 = F_101 ( V_6 , V_27 , V_181 ,
V_182 ) ;
}
for ( V_179 = 0 ; V_179 < V_180 ; V_179 ++ ) {
V_79 = F_36 ( V_6 , V_181 [ V_179 ] ) ;
V_184 = F_102 ( V_79 ) ;
if ( V_184 != V_185 || ( V_79 & V_186 ) )
continue;
if ( ! F_100 ( V_8 , V_181 [ V_179 ] ) ) {
if ( V_180 > 1 ) {
F_21 ( V_6 , V_27 , 0 ,
V_55 , V_179 ) ;
}
return V_181 [ V_179 ] ;
}
}
V_183 = V_8 -> V_30 . V_85 [ 0 ] ;
if ( V_8 -> V_30 . V_187 ) {
for ( V_179 = 0 ; V_179 < V_163 -> V_175 ; V_179 ++ )
if ( V_163 -> V_188 [ V_179 ] == V_27 ) {
V_183 = V_8 -> V_30 . V_187 ;
break;
}
}
if ( V_180 > 1 ) {
for ( V_179 = 0 ; V_179 < V_180 ; V_179 ++ ) {
if ( V_181 [ V_179 ] == V_183 ) {
F_21 ( V_6 , V_27 , 0 ,
V_55 , V_179 ) ;
break;
}
}
}
return 0 ;
}
static int F_103 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
struct V_162 * V_163 = & V_8 -> V_94 ;
int V_70 ;
T_1 V_27 , V_172 ;
for ( V_70 = 0 ; V_70 < V_163 -> V_189 ; V_70 ++ ) {
V_27 = V_163 -> V_190 [ V_70 ] ;
V_172 = F_98 ( V_6 , V_27 ) ;
if ( ! V_172 ) {
if ( V_8 -> V_30 . V_174 > 0 ) {
V_163 -> V_189 = V_8 -> V_30 . V_174 ;
break;
}
F_104 ( V_191
L_16 ,
V_38 , V_27 ) ;
return - V_192 ;
}
F_105 ( V_8 , V_172 ) ;
}
for ( V_70 = 0 ; V_70 < V_163 -> V_175 ; V_70 ++ ) {
V_27 = V_163 -> V_188 [ V_70 ] ;
V_172 = F_98 ( V_6 , V_27 ) ;
if ( V_172 ) {
if ( ! V_8 -> V_30 . V_187 )
V_8 -> V_30 . V_187 = V_172 ;
else
F_106 ( V_8 , V_172 ) ;
}
V_8 -> V_176 [ V_70 ] = V_172 ;
}
for ( V_70 = 0 ; V_70 < V_163 -> V_177 ; V_70 ++ ) {
V_27 = V_163 -> V_193 [ V_70 ] ;
V_172 = F_98 ( V_6 , V_27 ) ;
if ( V_172 )
F_106 ( V_8 , V_172 ) ;
V_8 -> V_178 [ V_70 ] = V_172 ;
}
V_27 = F_96 ( V_6 ) ;
if ( V_27 ) {
V_172 = F_98 ( V_6 , V_27 ) ;
if ( V_172 ) {
F_13 ( L_17 ,
V_27 , V_163 -> V_189 ) ;
V_163 -> V_190 [ V_163 -> V_189 ] = V_27 ;
V_163 -> V_189 ++ ;
V_8 -> V_134 = V_27 ;
F_105 ( V_8 , V_172 ) ;
}
}
V_27 = F_97 ( V_6 , & V_172 ) ;
if ( V_27 && V_172 ) {
F_13 ( L_18 ,
V_27 , V_163 -> V_189 ) ;
V_163 -> V_190 [ V_163 -> V_189 ] = V_27 ;
V_163 -> V_189 ++ ;
V_8 -> V_133 = V_27 ;
F_105 ( V_8 , V_172 ) ;
}
F_107 ( L_19 ,
V_8 -> V_30 . V_174 ,
V_8 -> V_30 . V_85 [ 0 ] ,
V_8 -> V_30 . V_85 [ 1 ] ,
V_8 -> V_30 . V_85 [ 2 ] ,
V_8 -> V_30 . V_85 [ 3 ] ,
V_8 -> V_30 . V_85 [ 4 ] ) ;
return 0 ;
}
static int F_108 ( struct V_5 * V_6 , const char * V_194 ,
int V_50 , T_1 V_27 , int V_195 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
char V_116 [ 32 ] ;
int V_25 ;
if ( ! V_8 -> V_196 ) {
unsigned int V_197 , V_198 , V_199 , V_200 ;
V_197 = F_109 ( V_6 , V_27 , V_35 ) ;
V_198 = ( V_197 & V_201 ) >>
V_202 ;
V_198 = ( V_198 + 1 ) * 25 ;
V_199 = ( V_197 & V_203 ) >>
V_204 ;
V_200 = V_199 * V_198 ;
if ( V_200 > 6400 && V_199 >= 0x1f )
V_8 -> V_86 = V_199 / 2 ;
V_8 -> V_196 = 1 ;
}
sprintf ( V_116 , L_20 , V_194 ) ;
V_25 = F_88 ( V_8 , V_205 , V_50 , V_116 ,
F_110 ( V_27 , V_195 , 0 , V_35 ,
V_8 -> V_86 ) ) ;
if ( V_25 < 0 )
return V_25 ;
sprintf ( V_116 , L_21 , V_194 ) ;
V_25 = F_88 ( V_8 , V_206 , V_50 , V_116 ,
F_111 ( V_27 , V_195 , 0 , V_35 ) ) ;
if ( V_25 < 0 )
return V_25 ;
return 0 ;
}
static int F_105 ( struct V_7 * V_8 , T_1 V_27 )
{
if ( V_8 -> V_30 . V_174 > 4 ) {
F_112 ( V_207 L_22 , V_27 ) ;
return 1 ;
} else {
F_113 ( V_8 -> V_30 . V_85 != V_8 -> V_85 ) ;
V_8 -> V_85 [ V_8 -> V_30 . V_174 ] = V_27 ;
V_8 -> V_30 . V_174 ++ ;
}
return 0 ;
}
static int F_106 ( struct V_7 * V_8 , T_1 V_27 )
{
int V_70 ;
for ( V_70 = 0 ; V_70 < F_114 ( V_8 -> V_30 . V_208 ) ; V_70 ++ ) {
if ( ! V_8 -> V_30 . V_208 [ V_70 ] ) {
V_8 -> V_30 . V_208 [ V_70 ] = V_27 ;
return 0 ;
}
}
F_112 ( V_207 L_23 , V_27 ) ;
return 1 ;
}
static int F_115 ( struct V_5 * V_6 , int V_209 ,
const T_1 * V_210 ,
const T_1 * V_85 ,
int type )
{
struct V_7 * V_8 = V_6 -> V_8 ;
static const char * const V_211 [ 4 ] = {
L_24 , L_25 , NULL , L_26
} ;
T_1 V_27 ;
int V_70 , V_25 ;
unsigned int V_212 ;
for ( V_70 = 0 ; V_70 < V_209 && V_70 < F_114 ( V_211 ) ; V_70 ++ ) {
if ( type == V_213 && ! V_8 -> V_139 ) {
if ( F_116 ( V_6 , V_210 [ V_70 ] ) )
V_8 -> V_139 = 1 ;
}
V_27 = V_85 [ V_70 ] ;
if ( ! V_27 )
continue;
if ( type != V_213 && V_70 == 2 ) {
V_25 = F_117 ( V_6 , L_27 , V_27 , 1 ) ;
if ( V_25 < 0 )
return V_25 ;
V_25 = F_117 ( V_6 , L_28 , V_27 , 2 ) ;
if ( V_25 < 0 )
return V_25 ;
V_212 = F_36 ( V_6 , V_27 ) ;
if ( V_212 & V_214 ) {
V_25 = F_89 ( V_8 ,
V_215 ,
L_29 , V_27 ) ;
if ( V_25 < 0 )
return V_25 ;
}
} else {
const char * V_116 ;
int V_50 ;
switch ( type ) {
case V_213 :
V_116 = L_30 ;
V_50 = V_70 ;
break;
case V_216 :
V_116 = L_31 ;
V_50 = V_70 ;
break;
default:
V_116 = V_211 [ V_70 ] ;
V_50 = 0 ;
break;
}
V_25 = F_108 ( V_6 , V_116 , V_50 , V_27 , 3 ) ;
if ( V_25 < 0 )
return V_25 ;
}
}
return 0 ;
}
static int F_118 ( struct V_5 * V_6 , unsigned long V_217 ,
unsigned long V_218 , int V_50 )
{
int V_25 ;
V_25 = F_88 ( V_6 -> V_8 , V_205 , V_50 ,
L_32 , V_217 ) ;
if ( V_25 < 0 )
return V_25 ;
V_25 = F_88 ( V_6 -> V_8 , V_206 , V_50 ,
L_33 , V_218 ) ;
if ( V_25 < 0 )
return V_25 ;
return 0 ;
}
static int F_119 ( struct V_5 * V_6 ,
const struct V_162 * V_163 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
T_1 V_27 ;
int V_25 ;
int V_50 ;
V_25 = F_115 ( V_6 , V_163 -> V_189 , V_163 -> V_190 ,
V_8 -> V_30 . V_85 ,
V_163 -> V_165 ) ;
if ( V_25 < 0 )
return V_25 ;
if ( V_163 -> V_175 > 1 && V_163 -> V_165 == V_166 ) {
V_25 = F_89 ( V_8 ,
V_219 ,
L_34 ,
V_163 -> V_188 [ V_163 -> V_175 - 1 ] ) ;
if ( V_25 < 0 )
return V_25 ;
}
for ( V_50 = 0 ; V_50 < V_163 -> V_167 ; V_50 ++ ) {
if ( V_163 -> V_168 [ V_50 ] . type > V_169 )
break;
V_27 = V_163 -> V_168 [ V_50 ] . V_170 ;
V_25 = F_90 ( V_6 , V_27 , V_50 ) ;
if ( V_25 < 0 )
return V_25 ;
}
return 0 ;
}
static int F_120 ( struct V_5 * V_6 ,
struct V_162 * V_163 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
int V_25 ;
V_25 = F_115 ( V_6 , V_163 -> V_175 , V_163 -> V_188 ,
V_8 -> V_176 , V_213 ) ;
if ( V_25 < 0 )
return V_25 ;
V_25 = F_115 ( V_6 , V_163 -> V_177 , V_163 -> V_193 ,
V_8 -> V_178 , V_216 ) ;
if ( V_25 < 0 )
return V_25 ;
return 0 ;
}
static int F_121 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
struct V_22 * V_58 = & V_8 -> V_220 ;
int V_70 , V_221 ;
T_1 V_222 [ F_114 ( V_223 ) ] ;
V_221 = F_101 ( V_6 ,
V_8 -> V_60 ,
V_222 ,
V_224 ) ;
if ( V_221 <= 0 || V_221 > F_114 ( V_223 ) )
return - V_225 ;
for ( V_70 = 0 ; V_70 < V_221 ; V_70 ++ )
F_37 ( V_58 , V_223 [ V_70 ] , V_70 ,
NULL ) ;
return F_89 ( V_8 , V_226 ,
L_35 , V_8 -> V_60 ) ;
}
static int F_122 ( struct V_5 * V_6 ,
T_1 V_27 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
T_2 V_197 = F_109 ( V_6 , V_27 , V_35 ) ;
int V_25 , type = V_227 ;
if ( V_8 -> V_228 == V_27 )
type = V_206 ;
if ( ( V_197 & V_229 ) >> V_230 ) {
V_25 = F_89 ( V_8 , type ,
L_36 ,
F_111 ( V_27 , 1 , 0 , V_35 ) ) ;
if ( V_25 < 0 )
return V_25 ;
}
if ( ( V_197 & V_203 ) >> V_204 ) {
V_25 = F_89 ( V_8 , V_205 ,
L_37 ,
F_111 ( V_27 , 1 , 0 , V_35 ) ) ;
if ( V_25 < 0 )
return V_25 ;
}
return 0 ;
}
static int F_123 ( struct V_1 * V_2 ,
struct V_10 * V_11 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
V_11 -> V_14 . integer . V_14 [ 0 ] = V_6 -> V_231 -> V_232 ;
return 0 ;
}
static int F_124 ( struct V_1 * V_2 ,
struct V_10 * V_11 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
return F_125 ( V_6 , V_11 -> V_14 . integer . V_14 [ 0 ] ) ;
}
static int F_126 ( struct V_5 * V_6 )
{
return F_87 ( V_6 -> V_8 , & V_233 ,
0 , L_36 , 0 ) ;
}
static int F_127 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
int V_70 , V_179 , V_25 = 0 ;
for ( V_70 = 0 ; V_70 < V_8 -> V_234 ; V_70 ++ ) {
T_1 V_27 ;
unsigned int V_79 ;
unsigned long V_26 ;
V_27 = V_8 -> V_54 [ V_70 ] ;
V_79 = F_36 ( V_6 , V_27 ) ;
if ( ! ( V_79 & V_80 ) )
continue;
V_26 = F_111 ( V_27 , 3 , 0 , V_35 ) ;
for ( V_179 = 0 ; V_179 < V_8 -> V_235 ; V_179 ++ ) {
if ( V_8 -> V_236 [ V_179 ] == V_26 )
break;
}
if ( V_179 < V_8 -> V_235 )
continue;
V_25 = F_88 ( V_8 , V_205 , V_70 ,
L_38 , V_26 ) ;
if ( V_25 < 0 )
return V_25 ;
}
return 0 ;
}
static int F_128 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
struct V_22 * V_237 = & V_8 -> V_24 ;
const char * const * V_238 = V_8 -> V_239 ;
int V_70 , V_221 ;
T_1 V_222 [ V_224 ] ;
V_221 = F_101 ( V_6 ,
V_8 -> V_28 [ 0 ] ,
V_222 ,
V_224 ) ;
if ( V_221 <= 0 )
return - V_225 ;
if ( ! V_238 )
V_238 = V_240 ;
for ( V_70 = 0 ; V_70 < V_221 ; V_70 ++ )
F_37 ( V_237 , V_238 [ V_70 ] , V_70 , NULL ) ;
return 0 ;
}
static T_1 F_129 ( struct V_5 * V_6 , T_1 V_241 ,
int V_50 )
{
T_1 V_181 [ V_224 ] ;
int V_199 ;
V_199 = F_101 ( V_6 , V_241 , V_181 , F_114 ( V_181 ) ) ;
if ( V_50 >= 0 && V_50 < V_199 )
return V_181 [ V_50 ] ;
return 0 ;
}
static int F_130 ( struct V_5 * V_6 , T_1 V_27 ,
const char * V_242 , int V_50 , int V_243 )
{
unsigned int V_197 , V_199 ;
char V_116 [ 32 ] ;
int V_25 ;
if ( V_243 == V_35 )
V_197 = V_80 ;
else
V_197 = V_244 ;
if ( ! ( F_36 ( V_6 , V_27 ) & V_197 ) )
return 0 ;
V_197 = F_109 ( V_6 , V_27 , V_243 ) ;
V_199 = ( V_197 & V_203 ) >> V_204 ;
if ( ! V_199 )
return 0 ;
snprintf ( V_116 , sizeof( V_116 ) , L_39 , V_242 ) ;
V_25 = F_88 ( V_6 -> V_8 , V_205 , V_50 , V_116 ,
F_111 ( V_27 , 3 , 0 , V_243 ) ) ;
if ( V_25 < 0 )
return V_25 ;
return 1 ;
}
static int F_131 ( struct V_5 * V_6 ,
const struct V_162 * V_163 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
struct V_22 * V_49 = & V_8 -> V_160 ;
struct V_22 * V_245 = & V_8 -> V_246 ;
int V_25 , V_70 ;
unsigned int V_153 ;
F_37 ( V_245 , V_247 [ 0 ] , 0 , NULL ) ;
for ( V_70 = 0 ; V_70 < V_8 -> V_248 ; V_70 ++ ) {
T_1 V_27 ;
int V_57 , V_249 ;
char V_242 [ 32 ] ;
V_27 = V_8 -> V_250 [ V_70 ] ;
if ( F_102 ( F_36 ( V_6 , V_27 ) ) != V_251 )
continue;
V_153 = F_91 ( V_6 , V_27 ) ;
if ( F_132 ( V_153 ) == V_252 )
continue;
V_57 = F_133 ( V_6 , V_8 -> V_18 [ 0 ] , V_27 ) ;
if ( V_57 < 0 )
continue;
F_94 ( V_6 , V_27 , & V_8 -> V_94 ,
V_242 , sizeof( V_242 ) , NULL ) ;
F_37 ( V_245 , V_242 , V_57 , & V_249 ) ;
if ( F_33 ( V_6 , L_2 ) != 1 )
F_37 ( V_49 , V_242 , V_57 , & V_249 ) ;
V_25 = F_130 ( V_6 , V_27 , V_242 , V_249 ,
V_253 ) ;
if ( V_25 < 0 )
return V_25 ;
if ( ! V_25 ) {
V_25 = F_130 ( V_6 , V_27 , V_242 ,
V_249 , V_35 ) ;
if ( V_25 < 0 )
return V_25 ;
if ( ! V_25 ) {
V_27 = F_129 ( V_6 ,
V_8 -> V_18 [ 0 ] , V_57 ) ;
if ( V_27 )
V_25 = F_130 ( V_6 ,
V_27 , V_242 ,
V_249 , V_253 ) ;
if ( V_25 < 0 )
return V_25 ;
}
}
}
return 0 ;
}
static int F_134 ( struct V_5 * V_6 , T_1 V_27 ,
T_1 * V_254 , T_1 * V_255 , T_1 * V_256 )
{
unsigned int V_163 ;
unsigned int type ;
if ( ! V_27 )
return 0 ;
V_163 = F_91 ( V_6 , V_27 ) ;
type = F_135 ( V_163 ) ;
switch ( F_92 ( V_163 ) ) {
case V_155 :
if ( * V_254 )
return 1 ;
if ( type != V_257 )
return 1 ;
* V_254 = V_27 ;
break;
case V_258 :
break;
case V_259 :
if ( * V_256 )
return 1 ;
if ( type != V_257 && type != V_260 )
return 1 ;
* V_256 = V_27 ;
break;
default:
if ( * V_255 )
return 1 ;
if ( type != V_257 )
return 1 ;
* V_255 = V_27 ;
break;
}
return 0 ;
}
static int F_136 ( struct V_5 * V_6 ,
struct V_261 * V_262 ,
T_1 V_170 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
struct V_162 * V_163 = & V_8 -> V_94 ;
int V_70 ;
V_262 -> V_170 = V_170 ;
if ( V_170 == 0 )
return 0 ;
for ( V_70 = 0 ; V_70 < V_163 -> V_167 ; V_70 ++ ) {
if ( V_170 == V_163 -> V_168 [ V_70 ] . V_170 )
break;
}
if ( V_70 < V_163 -> V_167 && V_163 -> V_168 [ V_70 ] . type == V_173 ) {
V_70 = F_133 ( V_6 , V_8 -> V_54 [ 0 ] , V_170 ) ;
if ( V_70 < 0 )
return - 1 ;
V_262 -> V_263 = V_70 ;
V_262 -> V_12 = - 1 ;
if ( V_8 -> V_18 )
V_262 -> V_12 = F_133 ( V_6 ,
V_8 -> V_18 [ 0 ] ,
V_8 -> V_54 [ 0 ] ) ;
} else if ( V_8 -> V_18 ) {
V_70 = F_133 ( V_6 , V_8 -> V_18 [ 0 ] , V_170 ) ;
if ( V_70 < 0 )
return - 1 ;
V_262 -> V_12 = V_70 ;
V_262 -> V_263 = - 1 ;
if ( V_8 -> V_54 )
V_262 -> V_263 = F_133 ( V_6 ,
V_8 -> V_54 [ 0 ] ,
V_8 -> V_18 [ 0 ] ) ;
}
return 0 ;
}
static int F_137 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
struct V_162 * V_163 = & V_8 -> V_94 ;
T_1 V_254 , V_255 , V_256 ;
int V_70 ;
V_254 = V_255 = V_256 = 0 ;
for ( V_70 = 0 ; V_70 < V_163 -> V_167 ; V_70 ++ )
if ( F_134 ( V_6 , V_163 -> V_168 [ V_70 ] . V_170 ,
& V_254 , & V_255 , & V_256 ) )
return 0 ;
for ( V_70 = 0 ; V_70 < V_8 -> V_248 ; V_70 ++ )
if ( F_134 ( V_6 , V_8 -> V_250 [ V_70 ] ,
& V_254 , & V_255 , & V_256 ) )
return 0 ;
if ( ! V_254 || ( ! V_255 && ! V_256 ) )
return 0 ;
if ( ! F_116 ( V_6 , V_255 ) )
return 0 ;
if ( F_136 ( V_6 , & V_8 -> V_264 , V_255 ) ||
F_136 ( V_6 , & V_8 -> V_265 , V_254 ) ||
F_136 ( V_6 , & V_8 -> V_266 , V_256 ) )
return 0 ;
return 1 ;
}
static int F_138 ( struct V_5 * V_6 , const struct V_162 * V_163 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
struct V_22 * V_49 = & V_8 -> V_160 ;
int V_70 , V_179 ;
const char * V_242 ;
for ( V_70 = 0 ; V_70 < V_163 -> V_167 ; V_70 ++ ) {
T_1 V_27 = V_163 -> V_168 [ V_70 ] . V_170 ;
int V_57 , V_25 , V_249 ;
V_57 = - 1 ;
for ( V_179 = 0 ; V_179 < V_8 -> V_234 ; V_179 ++ ) {
V_57 = F_133 ( V_6 , V_8 -> V_54 [ V_179 ] ,
V_27 ) ;
if ( V_57 >= 0 )
break;
}
if ( V_57 < 0 )
continue;
V_242 = F_139 ( V_6 , V_163 , V_70 ) ;
F_37 ( V_49 , V_242 , V_57 , & V_249 ) ;
V_25 = F_130 ( V_6 , V_27 ,
V_242 , V_249 ,
V_253 ) ;
if ( V_25 < 0 )
return V_25 ;
}
V_8 -> V_53 = V_49 -> V_33 ;
if ( V_49 -> V_33 ) {
for ( V_70 = 0 ; V_70 < V_8 -> V_234 ; V_70 ++ ) {
F_21 ( V_6 , V_8 -> V_54 [ V_70 ] , 0 ,
V_55 ,
V_49 -> V_56 [ 0 ] . V_57 ) ;
}
}
return 0 ;
}
static void F_140 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
int V_70 ;
for ( V_70 = 0 ; V_70 < V_8 -> V_94 . V_189 ; V_70 ++ ) {
T_1 V_27 = V_8 -> V_94 . V_190 [ V_70 ] ;
F_70 ( V_6 , V_27 , V_43 ) ;
}
}
static void F_141 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
int V_70 ;
for ( V_70 = 0 ; V_70 < V_8 -> V_94 . V_175 ; V_70 ++ ) {
T_1 V_170 ;
V_170 = V_8 -> V_94 . V_188 [ V_70 ] ;
if ( V_170 )
F_70 ( V_6 , V_170 , V_43 | V_267 ) ;
}
for ( V_70 = 0 ; V_70 < V_8 -> V_94 . V_177 ; V_70 ++ ) {
T_1 V_170 ;
V_170 = V_8 -> V_94 . V_193 [ V_70 ] ;
if ( V_170 )
F_70 ( V_6 , V_170 , V_43 ) ;
}
}
static int F_142 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
int V_70 , V_268 ;
if ( V_8 -> V_94 . V_165 != V_216 ||
V_8 -> V_94 . V_175 <= 1 )
return 0 ;
V_268 = 0 ;
for ( V_70 = 0 ; V_70 < V_8 -> V_94 . V_175 ; V_70 ++ ) {
T_1 V_27 = V_8 -> V_94 . V_188 [ V_70 ] ;
unsigned int V_163 = F_91 ( V_6 , V_27 ) ;
if ( F_143 ( V_163 ) & V_269 )
continue;
V_268 ++ ;
}
return ( V_268 > 1 ) ;
}
static int F_144 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
T_1 V_270 = 0 , V_271 = 0 ;
int V_272 = 0 ;
int V_70 , V_25 ;
if ( ( V_25 = F_145 ( V_6 ,
& V_8 -> V_94 ,
V_8 -> V_250 ) ) < 0 )
return V_25 ;
if ( ! V_8 -> V_94 . V_189 )
return 0 ;
if ( F_142 ( V_6 ) ) {
F_13 ( L_40 ) ;
memcpy ( V_8 -> V_94 . V_193 , V_8 -> V_94 . V_190 ,
sizeof( V_8 -> V_94 . V_190 ) ) ;
V_8 -> V_94 . V_177 = V_8 -> V_94 . V_189 ;
memcpy ( V_8 -> V_94 . V_190 , V_8 -> V_94 . V_188 ,
sizeof( V_8 -> V_94 . V_188 ) ) ;
V_8 -> V_94 . V_189 = V_8 -> V_94 . V_175 ;
V_8 -> V_94 . V_165 = V_213 ;
V_8 -> V_94 . V_175 = 0 ;
V_272 = 1 ;
}
if ( V_8 -> V_94 . V_273 ) {
int V_274 = F_36 ( V_6 , V_8 -> V_94 . V_273 ) &
( V_80 | V_244 ) ;
T_2 V_197 = F_109 ( V_6 ,
V_8 -> V_94 . V_273 , V_274 ) ;
T_1 V_275 [ 1 ] ;
if ( F_101 ( V_6 ,
V_8 -> V_94 . V_273 , V_275 , 1 ) &&
F_101 ( V_6 , V_275 [ 0 ] ,
V_275 , 1 ) > 0 ) {
int V_79 = F_36 ( V_6 , V_275 [ 0 ] ) ;
int V_276 = F_102 ( V_79 ) ;
if ( V_276 == V_277 &&
! ( V_79 & V_214 ) )
V_8 -> V_60 = V_275 [ 0 ] ;
}
if ( V_274 ) {
T_1 V_27 = V_8 -> V_94 . V_273 ;
V_274 = ( V_274 & V_80 ) ? V_35 : V_253 ;
V_25 = F_89 ( V_8 , V_206 ,
L_41 ,
F_111 ( V_27 , 1 , 0 , V_274 ) ) ;
if ( V_25 < 0 )
return V_25 ;
if ( ( V_197 & V_203 )
>> V_204 ) {
V_25 = F_89 ( V_8 ,
V_205 ,
L_42 ,
F_111 ( V_27 , 1 , 0 , V_274 ) ) ;
if ( V_25 < 0 )
return V_25 ;
}
}
F_70 ( V_6 , V_8 -> V_94 . V_273 ,
V_43 ) ;
}
if ( ! V_8 -> V_30 . V_174 ) {
V_25 = F_103 ( V_6 ) ;
if ( V_25 < 0 )
return V_25 ;
V_25 = F_119 ( V_6 ,
& V_8 -> V_94 ) ;
if ( V_25 < 0 )
return V_25 ;
}
if ( V_8 -> V_228 > 0 ) {
V_25 = F_122 ( V_6 ,
V_8 -> V_228 ) ;
if ( V_25 < 0 )
return V_25 ;
}
#ifdef F_146
if ( V_8 -> V_278 > 0 ) {
T_1 V_27 = V_8 -> V_278 ;
unsigned int V_197 ;
V_25 = F_122 ( V_6 , V_27 ) ;
if ( V_25 < 0 )
return V_25 ;
V_25 = F_147 ( V_6 , V_27 ) ;
if ( V_25 < 0 )
return V_25 ;
if ( V_6 -> V_231 ) {
V_6 -> V_231 -> V_279 = V_8 -> V_280 ;
V_197 = F_109 ( V_6 , V_27 , V_35 ) ;
if ( ! ( V_197 & V_229 ) ) {
V_25 = F_126 ( V_6 ) ;
if ( V_25 < 0 )
return V_25 ;
}
}
}
#endif
V_25 = F_120 ( V_6 , & V_8 -> V_94 ) ;
if ( V_25 < 0 )
return V_25 ;
if ( V_272 ) {
memcpy ( V_8 -> V_94 . V_188 , V_8 -> V_94 . V_190 ,
sizeof( V_8 -> V_94 . V_188 ) ) ;
V_8 -> V_94 . V_175 = V_8 -> V_94 . V_189 ;
V_8 -> V_94 . V_165 = V_213 ;
V_8 -> V_94 . V_189 = 0 ;
}
if ( F_137 ( V_6 ) ) {
V_8 -> V_74 = 1 ;
V_8 -> V_123 = 1 ;
V_8 -> V_235 = 1 ;
V_8 -> V_234 = 1 ;
}
for ( V_70 = 0 ; V_70 < V_8 -> V_235 ; V_70 ++ ) {
V_25 = F_118 ( V_6 , V_8 -> V_236 [ V_70 ] ,
V_8 -> V_281 [ V_70 ] , V_70 ) ;
if ( V_25 < 0 )
return V_25 ;
}
V_25 = F_138 ( V_6 , & V_8 -> V_94 ) ;
if ( V_25 < 0 )
return V_25 ;
if ( V_8 -> V_60 > 0 ) {
V_25 = F_121 ( V_6 ) ;
if ( V_25 < 0 )
return V_25 ;
}
if ( V_8 -> V_248 > 0 && ! V_8 -> V_9 )
if ( ( V_25 = F_131 ( V_6 ,
& V_8 -> V_94 ) ) < 0 )
return V_25 ;
if ( V_8 -> V_234 > 0 ) {
V_25 = F_127 ( V_6 ) ;
if ( V_25 < 0 )
return V_25 ;
}
if ( V_8 -> V_78 > 0 ) {
V_25 = F_128 ( V_6 ) ;
if ( V_25 < 0 )
return V_25 ;
}
V_25 = F_95 ( V_8 ) ;
if ( V_25 < 0 )
return V_25 ;
V_8 -> V_30 . V_282 = V_8 -> V_30 . V_174 * 2 ;
if ( V_8 -> V_30 . V_282 > 2 )
V_8 -> V_283 = 1 ;
for ( V_70 = V_6 -> V_284 ; V_70 < V_6 -> V_284 + V_6 -> V_285 ; V_70 ++ ) {
unsigned int V_212 = F_36 ( V_6 , V_70 ) ;
if ( V_212 & V_186 ) {
switch ( F_102 ( V_212 ) ) {
case V_185 :
if ( ! V_270 )
V_270 = V_70 ;
break;
case V_286 :
if ( ! V_271 )
V_271 = V_70 ;
break;
}
}
}
if ( V_8 -> V_94 . V_287 )
V_8 -> V_30 . V_31 = V_270 ;
if ( V_271 && V_8 -> V_94 . V_288 )
V_8 -> V_83 = V_271 ;
if ( V_8 -> V_146 . V_289 )
V_8 -> V_73 [ V_8 -> V_72 ++ ] = V_8 -> V_146 . V_289 ;
V_8 -> V_46 = & V_8 -> V_160 ;
if ( ! V_8 -> V_9 )
V_8 -> V_9 = & V_8 -> V_246 ;
V_8 -> V_19 = & V_8 -> V_24 ;
V_8 -> V_58 = & V_8 -> V_220 ;
return 1 ;
}
static int F_148 ( struct V_5 * V_6 ,
struct V_162 * V_163 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
T_1 V_170 = V_163 -> V_188 [ 0 ] ;
if ( ! V_170 )
return 0 ;
if ( F_116 ( V_6 , V_170 ) )
V_8 -> V_139 = 1 ;
return 0 ;
}
static int F_149 ( struct V_5 * V_6 ,
struct V_162 * V_163 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
int V_25 ;
T_1 V_290 = 0x0 ;
int V_70 ;
for ( V_70 = 0 ; V_70 < V_8 -> V_94 . V_177 && V_290 == 0x0 ; V_70 ++ ) {
T_1 V_170 = V_8 -> V_94 . V_193 [ V_70 ] ;
unsigned int V_79 = F_36 ( V_6 , V_170 ) ;
V_79 &= ( V_291 | V_80 ) ;
if ( V_79 == V_80 )
V_290 = V_170 ;
}
if ( V_290 == 0 && V_8 -> V_94 . V_177 == 0 ) {
for ( V_70 = 0 ; V_70 < V_8 -> V_94 . V_189 && V_290 == 0x0 ; V_70 ++ ) {
T_1 V_170 = V_8 -> V_94 . V_190 [ V_70 ] ;
unsigned int V_292 ;
V_292 = F_91 ( V_6 , V_170 ) ;
if ( F_135 ( V_292 ) == V_293 ) {
unsigned int V_79 = F_36 ( V_6 , V_170 ) ;
V_79 &= ( V_291 | V_80 ) ;
if ( V_79 == V_80 )
V_290 = V_170 ;
}
}
}
if ( V_290 ) {
V_25 = F_117 ( V_6 , L_28 , V_290 , 1 ) ;
if ( V_25 < 0 )
return V_25 ;
}
return 0 ;
}
static int F_150 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
int V_25 ;
if ( ( V_25 = F_145 ( V_6 , & V_8 -> V_94 , NULL ) ) < 0 )
return V_25 ;
if ( ( V_25 = F_138 ( V_6 , & V_8 -> V_94 ) ) < 0 )
return V_25 ;
if ( ( V_25 = F_148 ( V_6 , & V_8 -> V_94 ) ) < 0 )
return V_25 ;
if ( ( V_25 = F_149 ( V_6 , & V_8 -> V_94 ) ) < 0 )
return V_25 ;
if ( V_8 -> V_234 > 0 ) {
V_25 = F_127 ( V_6 ) ;
if ( V_25 < 0 )
return V_25 ;
}
V_25 = F_95 ( V_8 ) ;
if ( V_25 < 0 )
return V_25 ;
if ( V_8 -> V_94 . V_287 )
V_8 -> V_30 . V_31 = 0x05 ;
if ( V_8 -> V_94 . V_288 )
V_8 -> V_83 = 0x04 ;
if ( V_8 -> V_146 . V_289 )
V_8 -> V_73 [ V_8 -> V_72 ++ ] = V_8 -> V_146 . V_289 ;
V_8 -> V_46 = & V_8 -> V_160 ;
V_8 -> V_9 = & V_8 -> V_246 ;
return 1 ;
}
static void F_151 ( struct V_5 * V_6 , unsigned int V_294 ,
unsigned int V_295 , unsigned int V_296 )
{
unsigned int V_297 , V_298 , V_299 ;
F_13 ( L_43 , V_38 , V_294 , V_295 , V_296 ) ;
V_297 = F_14 ( V_6 , V_6 -> V_65 , 0 ,
V_300 , 0 ) ;
V_297 = ( V_297 & ~ V_295 ) | ( V_296 & V_295 ) ;
V_298 = F_14 ( V_6 , V_6 -> V_65 , 0 ,
V_301 , 0 ) ;
V_298 |= V_294 ;
V_299 = F_14 ( V_6 , V_6 -> V_65 , 0 ,
V_302 , 0 ) ;
V_299 |= V_295 ;
F_65 ( V_6 , V_6 -> V_65 , 0 , 0x7e7 , 0 ) ;
F_65 ( V_6 , V_6 -> V_65 , 0 ,
V_303 , V_298 ) ;
F_14 ( V_6 , V_6 -> V_65 , 0 ,
V_304 , V_299 ) ;
F_50 ( 1 ) ;
F_14 ( V_6 , V_6 -> V_65 , 0 ,
V_305 , V_297 ) ;
}
static int F_152 ( struct V_5 * V_6 , T_1 V_27 ,
unsigned char type , int V_296 )
{
struct V_306 * V_307 ;
V_307 = F_153 ( V_6 , V_27 ) ;
if ( ! V_307 )
return - V_151 ;
V_307 -> V_308 = type ;
V_307 -> V_68 = V_296 ;
return 0 ;
}
static int F_154 ( struct V_5 * V_6 , T_1 V_27 ,
unsigned int type )
{
struct V_306 * V_307 ;
if ( ! F_116 ( V_6 , V_27 ) )
return 0 ;
V_307 = F_153 ( V_6 , V_27 ) ;
if ( ! V_307 )
return - V_151 ;
if ( V_307 -> V_308 && V_307 -> V_308 != type )
return 0 ;
V_307 -> V_308 = type ;
F_155 ( V_6 , V_27 , 0 ) ;
return 1 ;
}
static int F_156 ( struct V_162 * V_163 , T_1 V_27 )
{
int V_70 ;
for ( V_70 = 0 ; V_70 < V_163 -> V_175 ; V_70 ++ )
if ( V_163 -> V_188 [ V_70 ] == V_27 )
return 1 ;
for ( V_70 = 0 ; V_70 < V_163 -> V_189 ; V_70 ++ )
if ( V_163 -> V_190 [ V_70 ] == V_27 )
return 1 ;
return 0 ;
}
static void F_157 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
const T_1 * V_172 ;
for ( V_172 = V_8 -> V_309 ; * V_172 ; V_172 ++ )
if ( ! F_100 ( V_8 , * V_172 ) )
F_65 ( V_6 , * V_172 , 0 ,
V_108 , V_110 ) ;
}
static inline int F_158 ( struct V_5 * V_6 , const char * V_310 ,
int * V_311 )
{
const char * V_312 ;
V_312 = F_159 ( V_6 , V_310 ) ;
if ( V_312 ) {
unsigned long V_26 ;
if ( ! F_160 ( V_312 , 0 , & V_26 ) ) {
* V_311 = V_26 ;
return 1 ;
}
}
return 0 ;
}
static void F_161 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
int V_26 ;
V_26 = F_33 ( V_6 , L_44 ) ;
if ( V_26 >= 0 )
V_8 -> V_139 = V_26 ;
if ( F_158 ( V_6 , L_45 , & V_8 -> V_313 ) ) {
V_8 -> V_314 = V_8 -> V_84 = V_8 -> V_315 =
V_8 -> V_313 ;
}
if ( F_158 ( V_6 , L_46 , & V_8 -> V_84 ) )
V_8 -> V_313 &= V_8 -> V_313 ;
if ( F_158 ( V_6 , L_47 , & V_8 -> V_315 ) )
V_8 -> V_84 &= V_8 -> V_313 ;
if ( F_158 ( V_6 , L_48 , & V_8 -> V_314 ) )
V_8 -> V_314 &= V_8 -> V_313 ;
if ( F_158 ( V_6 , L_49 , & V_8 -> V_316 ) )
V_8 -> V_316 &= V_8 -> V_313 ;
V_26 = F_33 ( V_6 , L_50 ) ;
if ( V_26 >= 0 )
V_8 -> V_317 = V_26 ;
}
static void F_162 ( struct V_5 * V_6 , int V_96 ,
const T_1 * V_210 )
{
while ( V_96 -- )
F_73 ( V_6 , * V_210 ++ ) ;
}
static void F_163 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
if ( V_8 -> V_94 . V_175 )
F_162 ( V_6 , V_8 -> V_94 . V_175 ,
V_8 -> V_94 . V_188 ) ;
if ( V_8 -> V_94 . V_189 &&
V_8 -> V_94 . V_190 [ 0 ] != V_8 -> V_94 . V_188 [ 0 ] )
F_162 ( V_6 , V_8 -> V_94 . V_189 ,
V_8 -> V_94 . V_190 ) ;
}
static int F_164 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
struct V_162 * V_163 = & V_8 -> V_94 ;
unsigned int V_318 ;
int V_70 ;
if ( V_8 -> V_319 )
F_165 ( V_6 , V_8 -> V_319 ) ;
if ( V_8 -> V_107 )
for ( V_70 = 0 ; V_70 < V_8 -> V_123 ; V_70 ++ )
F_65 ( V_6 ,
V_8 -> V_105 [ V_70 ] , 0 ,
V_108 , V_110 ) ;
F_161 ( V_6 ) ;
V_318 = V_8 -> V_315 ;
if ( ! V_8 -> V_317 )
V_318 |= V_8 -> V_314 ;
F_151 ( V_6 , V_8 -> V_313 , V_8 -> V_84 , V_318 ) ;
if ( V_8 -> V_139 ) {
for ( V_70 = 0 ; V_70 < V_163 -> V_175 ; V_70 ++ ) {
T_1 V_27 = V_163 -> V_188 [ V_70 ] ;
F_154 ( V_6 , V_27 , V_320 ) ;
}
if ( V_163 -> V_165 == V_166 &&
V_163 -> V_177 > 0 ) {
for ( V_70 = 0 ; V_70 < V_163 -> V_189 ; V_70 ++ ) {
T_1 V_27 = V_163 -> V_190 [ V_70 ] ;
F_154 ( V_6 , V_27 , V_321 ) ;
}
}
F_70 ( V_6 , V_8 -> V_94 . V_190 [ 0 ] ,
V_43 ) ;
F_163 ( V_6 ) ;
} else {
F_140 ( V_6 ) ;
F_141 ( V_6 ) ;
for ( V_70 = 0 ; V_70 < V_163 -> V_175 ; V_70 ++ )
F_166 ( V_6 , V_163 -> V_188 [ V_70 ] , 1 ) ;
}
if ( V_8 -> V_74 ) {
if ( V_8 -> V_18 )
F_21 ( V_6 , V_8 -> V_18 [ 0 ] , 0 ,
V_55 , 0 ) ;
if ( F_154 ( V_6 , V_8 -> V_264 . V_170 , V_322 ) )
F_73 ( V_6 , V_8 -> V_264 . V_170 ) ;
if ( F_154 ( V_6 , V_8 -> V_266 . V_170 ,
V_322 ) )
F_73 ( V_6 , V_8 -> V_266 . V_170 ) ;
}
for ( V_70 = 0 ; V_70 < V_163 -> V_167 ; V_70 ++ ) {
T_1 V_27 = V_163 -> V_168 [ V_70 ] . V_170 ;
int type = V_163 -> V_168 [ V_70 ] . type ;
unsigned int V_37 , V_323 ;
if ( type == V_173 ) {
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
V_323 = F_91 ( V_6 , V_27 ) ;
if ( F_132 ( V_323 ) != V_324 ) {
if ( F_154 ( V_6 , V_27 , V_325 ) )
F_73 ( V_6 , V_27 ) ;
}
}
for ( V_70 = 0 ; V_70 < V_8 -> V_248 ; V_70 ++ )
F_70 ( V_6 , V_8 -> V_250 [ V_70 ] ,
V_42 ) ;
if ( V_163 -> V_326 [ 0 ] )
F_70 ( V_6 , V_163 -> V_326 [ 0 ] ,
V_43 ) ;
if ( V_163 -> V_288 )
F_70 ( V_6 , V_163 -> V_288 ,
V_42 ) ;
for ( V_70 = 0 ; V_70 < V_8 -> V_327 ; V_70 ++ ) {
T_1 V_27 = V_8 -> V_328 [ V_70 ] ;
unsigned int V_37 , V_153 ;
V_153 = F_91 ( V_6 , V_27 ) ;
V_153 = F_132 ( V_153 ) ;
if ( V_153 == V_252 ) {
F_166 ( V_6 , V_27 , 0 ) ;
continue;
}
if ( V_153 == V_324 ) {
F_166 ( V_6 , V_27 , 1 ) ;
continue;
}
if ( ! V_8 -> V_139 ||
V_8 -> V_329 == V_27 ||
! F_116 ( V_6 , V_27 ) ) {
F_166 ( V_6 , V_27 , 1 ) ;
continue;
}
if ( F_156 ( V_163 , V_27 ) )
continue;
V_37 = F_14 ( V_6 , V_27 , 0 ,
V_39 , 0 ) ;
if ( V_37 & V_42 ) {
F_166 ( V_6 , V_27 , 1 ) ;
continue;
}
if ( F_154 ( V_6 , V_27 , V_330 ) ) {
F_73 ( V_6 , V_27 ) ;
continue;
}
F_166 ( V_6 , V_27 , 0 ) ;
}
F_167 ( V_6 ) ;
if ( V_8 -> V_91 ) {
if ( V_8 -> V_89 . V_92 )
F_168 ( & V_8 -> V_89 ) ;
else
F_30 ( V_6 , false ) ;
}
if ( V_8 -> V_327 )
F_65 ( V_6 , V_6 -> V_65 , 0 ,
V_331 ,
V_8 -> V_332 ) ;
if ( V_8 -> V_309 )
F_157 ( V_6 ) ;
return 0 ;
}
static void F_45 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
if ( V_8 -> V_146 . V_289 ) {
struct V_142 * V_333 = V_8 -> V_146 . V_289 ;
int V_70 ;
for ( V_70 = 0 ; V_70 < V_8 -> V_146 . V_334 ; V_70 ++ )
F_169 ( V_333 [ V_70 ] . V_116 ) ;
}
F_170 ( & V_8 -> V_146 ) ;
}
static void F_171 ( struct V_5 * V_6 )
{
unsigned int V_70 , V_153 ;
if ( V_6 -> V_335 -> V_336 )
return;
for ( V_70 = 0 ; V_70 < V_6 -> V_337 . V_334 ; V_70 ++ ) {
struct V_338 * V_170 = F_172 ( & V_6 -> V_337 , V_70 ) ;
V_153 = F_91 ( V_6 , V_170 -> V_27 ) ;
if ( F_132 ( V_153 ) != V_252 )
F_173 ( V_6 , V_170 -> V_27 , 0 ) ;
}
}
static void F_174 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
F_171 ( V_6 ) ;
if ( V_8 -> V_314 )
F_151 ( V_6 , V_8 -> V_313 ,
V_8 -> V_84 , V_8 -> V_315 &
~ V_8 -> V_314 ) ;
}
static void F_175 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
if ( ! V_8 )
return;
F_174 ( V_6 ) ;
F_169 ( V_8 ) ;
F_176 ( V_6 ) ;
}
static void F_177 ( struct V_5 * V_6 , T_1 V_27 ,
unsigned int V_339 )
{
unsigned int V_340 , V_341 ;
V_341 = F_14 ( V_6 , V_27 ,
0 , V_39 , 0x00 ) ;
if ( V_341 & V_42 ) {
struct V_7 * V_8 = V_6 -> V_8 ;
if ( V_27 == V_8 -> V_134 || V_27 == V_8 -> V_133 )
return;
}
V_340 = V_341 ;
if ( V_339 & ( V_42 | V_43 ) )
V_341 &= ~ ( V_42 | V_43 ) ;
V_341 |= V_339 ;
if ( V_340 != V_341 )
F_15 ( V_6 , V_27 , V_341 ) ;
}
static void F_178 ( struct V_5 * V_6 , T_1 V_27 ,
unsigned int V_339 )
{
unsigned int V_341 = F_14 ( V_6 , V_27 ,
0 , V_39 , 0x00 ) ;
if ( V_341 & V_339 )
F_15 ( V_6 , V_27 , V_341 & ~ V_339 ) ;
}
static inline int F_179 ( struct V_5 * V_6 , T_1 V_27 )
{
if ( ! V_27 )
return 0 ;
return F_180 ( V_6 , V_27 ) ;
}
static void F_181 ( struct V_5 * V_6 ,
int V_342 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
struct V_162 * V_163 = & V_8 -> V_94 ;
int V_70 ;
if ( V_163 -> V_177 == 0 )
return;
for ( V_70 = 0 ; V_70 < V_163 -> V_189 ; V_70 ++ ) {
if ( V_342 )
break;
V_342 = F_179 ( V_6 , V_163 -> V_190 [ V_70 ] ) ;
if ( V_342 ) {
unsigned int V_37 ;
V_37 = F_14 ( V_6 ,
V_163 -> V_190 [ V_70 ] , 0 ,
V_39 , 0 ) ;
if ( V_37 & V_42 )
V_342 = 0 ;
}
}
if ( V_342 ) {
for ( V_70 = 0 ; V_70 < V_163 -> V_177 ; V_70 ++ )
F_178 ( V_6 , V_163 -> V_193 [ V_70 ] ,
V_43 ) ;
if ( V_8 -> V_314 && V_8 -> V_317 )
F_151 ( V_6 , V_8 -> V_313 ,
V_8 -> V_84 , V_8 -> V_315 &
~ V_8 -> V_314 ) ;
} else {
for ( V_70 = 0 ; V_70 < V_163 -> V_177 ; V_70 ++ )
F_177 ( V_6 , V_163 -> V_193 [ V_70 ] ,
V_43 ) ;
if ( V_8 -> V_314 && V_8 -> V_317 )
F_151 ( V_6 , V_8 -> V_313 ,
V_8 -> V_84 , V_8 -> V_315 |
V_8 -> V_314 ) ;
}
}
static int F_182 ( struct V_7 * V_8 , int V_70 )
{
struct V_162 * V_163 = & V_8 -> V_94 ;
if ( V_163 -> V_188 [ V_70 ] == V_8 -> V_134 )
return 1 ;
if ( V_163 -> V_188 [ V_70 ] == V_8 -> V_133 )
return 1 ;
if ( V_163 -> V_188 [ V_70 ] == V_8 -> V_131 )
return 1 ;
return 0 ;
}
static void F_183 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
struct V_162 * V_163 = & V_8 -> V_94 ;
int V_70 , V_342 ;
V_342 = 0 ;
if ( V_8 -> V_316 )
V_342 = ! ( F_14 ( V_6 , V_6 -> V_65 , 0 ,
V_300 , 0 ) & V_8 -> V_316 ) ;
for ( V_70 = 0 ; V_70 < V_163 -> V_175 ; V_70 ++ ) {
if ( V_342 )
break;
if ( F_182 ( V_8 , V_70 ) )
continue;
V_342 = F_179 ( V_6 , V_163 -> V_188 [ V_70 ] ) ;
if ( V_342 ) {
unsigned int V_37 ;
V_37 = F_14 ( V_6 , V_163 -> V_188 [ V_70 ] , 0 ,
V_39 , 0 ) ;
if ( V_37 & V_42 )
V_342 = 0 ;
}
}
if ( V_342 ) {
if ( V_8 -> V_131 )
F_178 ( V_6 , V_8 -> V_131 ,
V_43 ) ;
for ( V_70 = 0 ; V_70 < V_163 -> V_189 ; V_70 ++ )
F_178 ( V_6 , V_163 -> V_190 [ V_70 ] ,
V_43 ) ;
} else {
if ( V_8 -> V_131 )
F_177 ( V_6 , V_8 -> V_131 ,
V_43 ) ;
for ( V_70 = 0 ; V_70 < V_163 -> V_189 ; V_70 ++ )
F_177 ( V_6 , V_163 -> V_190 [ V_70 ] ,
V_43 ) ;
}
F_181 ( V_6 , V_342 ) ;
for ( V_70 = 0 ; V_70 < V_163 -> V_175 ; V_70 ++ ) {
unsigned int V_26 = V_43 | V_267 ;
if ( F_182 ( V_8 , V_70 ) )
continue;
if ( 1 )
F_177 ( V_6 , V_163 -> V_188 [ V_70 ] , V_26 ) ;
#if 0
else
stac92xx_reset_pinctl(codec, cfg->hp_pins[i], val);
#endif
}
}
static void F_166 ( struct V_5 * V_6 , T_1 V_27 ,
int V_343 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
unsigned int V_50 , V_26 ;
for ( V_50 = 0 ; V_50 < V_8 -> V_327 ; V_50 ++ ) {
if ( V_8 -> V_328 [ V_50 ] == V_27 )
break;
}
if ( V_50 >= V_8 -> V_327 )
return;
V_50 = 1 << V_50 ;
V_26 = V_8 -> V_332 ;
if ( V_343 )
V_26 &= ~ V_50 ;
else
V_26 |= V_50 ;
if ( V_26 != V_8 -> V_332 ) {
V_8 -> V_332 = V_26 ;
F_65 ( V_6 , V_6 -> V_65 , 0 ,
V_331 , V_26 ) ;
}
}
static void F_184 ( struct V_5 * V_6 , T_1 V_27 )
{
F_166 ( V_6 , V_27 , F_179 ( V_6 , V_27 ) ) ;
}
static unsigned int F_185 ( struct V_5 * V_6 , int V_50 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
unsigned int V_163 ;
V_163 = F_91 ( V_6 , V_8 -> V_97 [ V_50 ] ) ;
return F_132 ( V_163 ) ;
}
static int F_186 ( struct V_5 * V_6 ,
const T_1 * V_344 , int V_345 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
int V_50 , V_346 ;
unsigned int V_153 ;
for ( V_346 = 0 ; V_346 < V_345 ; V_346 ++ ) {
for ( V_50 = 0 ; V_50 < V_8 -> V_96 ; V_50 ++ )
if ( V_8 -> V_97 [ V_50 ] == V_344 [ V_346 ] )
break;
if ( V_50 >= V_8 -> V_96 )
break;
V_153 = F_185 ( V_6 , V_50 ) ;
if ( V_153 == V_252 )
break;
}
return V_346 ;
}
static void F_187 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
struct V_261 * V_262 ;
if ( F_179 ( V_6 , V_8 -> V_264 . V_170 ) )
V_262 = & V_8 -> V_264 ;
else if ( F_179 ( V_6 , V_8 -> V_266 . V_170 ) )
V_262 = & V_8 -> V_266 ;
else
V_262 = & V_8 -> V_265 ;
if ( V_262 -> V_12 >= 0 )
F_21 ( V_6 , V_8 -> V_18 [ 0 ] , 0 ,
V_55 ,
V_262 -> V_12 ) ;
if ( V_262 -> V_263 >= 0 )
F_21 ( V_6 , V_8 -> V_54 [ 0 ] , 0 ,
V_55 ,
V_262 -> V_263 ) ;
}
static void F_188 ( struct V_5 * V_6 ,
struct V_306 * V_307 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
int V_296 ;
switch ( V_307 -> V_308 ) {
case V_320 :
case V_321 :
F_183 ( V_6 ) ;
break;
case V_322 :
F_187 ( V_6 ) ;
break;
}
switch ( V_307 -> V_308 ) {
case V_320 :
case V_321 :
case V_322 :
case V_325 :
case V_330 :
if ( V_8 -> V_327 > 0 )
F_184 ( V_6 , V_307 -> V_27 ) ;
switch ( V_6 -> V_347 ) {
case 0x103c308f :
if ( V_307 -> V_27 == 0xb ) {
int V_170 = V_42 ;
if ( F_179 ( V_6 , 0xa )
&& F_179 ( V_6 , 0xb ) )
V_170 |= V_348 ;
if ( ! F_179 ( V_6 , 0xb ) )
V_170 |= V_348 ;
F_70 ( V_6 , 0x0a , V_170 ) ;
}
}
break;
case V_349 :
V_296 = F_14 ( V_6 , V_6 -> V_65 , 0 ,
V_300 , 0 ) ;
F_65 ( V_6 , V_6 -> V_65 , 0 , 0x7e0 ,
! ! ( V_296 & ( 1 << V_307 -> V_68 ) ) ) ;
break;
}
}
static void F_73 ( struct V_5 * V_6 , T_1 V_27 )
{
struct V_306 * V_307 = F_189 ( V_6 , V_27 ) ;
if ( ! V_307 )
return;
F_188 ( V_6 , V_307 ) ;
}
static void F_190 ( struct V_5 * V_6 , unsigned int V_350 )
{
struct V_306 * V_307 ;
int V_351 ;
V_351 = ( V_350 >> 26 ) & 0x7f ;
V_307 = F_191 ( V_6 , V_351 ) ;
if ( ! V_307 )
return;
V_307 -> V_352 = 1 ;
F_188 ( V_6 , V_307 ) ;
F_167 ( V_6 ) ;
}
static void F_192 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
unsigned int V_318 ;
if ( V_8 -> V_91 )
return;
V_318 = F_193 ( V_6 , V_6 -> V_65 , V_353 ) ;
V_318 &= V_354 ;
if ( V_318 > 3 )
V_8 -> V_91 = 0x08 ;
else
V_8 -> V_91 = 0x01 ;
}
static int F_194 ( struct V_5 * V_6 , int V_355 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
const struct V_356 * V_357 = NULL ;
if ( F_158 ( V_6 , L_51 , & V_8 -> V_91 ) ) {
F_158 ( V_6 , L_52 ,
& V_8 -> V_358 ) ;
return 1 ;
}
if ( ( V_6 -> V_347 >> 16 ) == V_359 ) {
while ( ( V_357 = F_195 ( V_360 ,
NULL , V_357 ) ) ) {
if ( sscanf ( V_357 -> V_116 , L_53 ,
& V_8 -> V_358 ,
& V_8 -> V_91 ) == 2 ) {
unsigned int V_361 ;
V_361 = F_193 ( V_6 , V_6 -> V_65 ,
V_353 ) ;
V_361 &= V_354 ;
if ( V_8 -> V_91 < V_361 )
V_8 -> V_91 = 1 << V_8 -> V_91 ;
else
V_8 -> V_329 = V_8 -> V_91 ;
return 1 ;
}
if ( sscanf ( V_357 -> V_116 , L_54 ,
& V_8 -> V_358 ) == 1 ) {
F_192 ( V_6 ) ;
return 1 ;
}
if ( strstr ( V_357 -> V_116 , L_55 ) ) {
F_192 ( V_6 ) ;
switch ( V_6 -> V_347 ) {
case 0x103c148a :
V_8 -> V_358 = 0 ;
break;
default:
V_8 -> V_358 = 1 ;
break;
}
return 1 ;
}
}
if ( ! F_196 ( V_6 -> V_347 ) &&
( V_355 == 0 || V_355 == 1 ) ) {
F_192 ( V_6 ) ;
V_8 -> V_358 = V_355 ;
return 1 ;
}
}
return 0 ;
}
static int F_196 ( T_2 V_347 )
{
switch ( V_347 ) {
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
static void F_197 ( struct V_362 * V_363 ,
struct V_5 * V_6 , T_1 V_27 )
{
if ( V_27 == V_6 -> V_65 )
F_198 ( V_363 , L_56 ,
F_14 ( V_6 , V_27 , 0 ,
V_364 , 0 ) ) ;
}
static void F_199 ( struct V_362 * V_363 ,
struct V_5 * V_6 ,
unsigned int V_365 )
{
F_198 ( V_363 , L_57 ,
F_14 ( V_6 , V_6 -> V_65 , 0 , V_365 , 0 ) ) ;
}
static void F_200 ( struct V_362 * V_363 ,
struct V_5 * V_6 , T_1 V_27 )
{
F_197 ( V_363 , V_6 , V_27 ) ;
if ( V_27 == V_6 -> V_65 )
F_199 ( V_363 , V_6 , 0xfa0 ) ;
}
static void F_201 ( struct V_362 * V_363 ,
struct V_5 * V_6 , T_1 V_27 )
{
if ( V_27 == V_6 -> V_65 )
F_199 ( V_363 , V_6 , 0xfe0 ) ;
}
static void F_202 ( struct V_362 * V_363 ,
struct V_5 * V_6 , T_1 V_27 )
{
if ( V_27 == V_6 -> V_65 )
F_199 ( V_363 , V_6 , 0xfeb ) ;
}
static int F_203 ( struct V_5 * V_6 )
{
F_164 ( V_6 ) ;
F_204 ( V_6 ) ;
F_205 ( V_6 ) ;
F_163 ( V_6 ) ;
return 0 ;
}
static int F_206 ( struct V_5 * V_6 )
{
F_174 ( V_6 ) ;
return 0 ;
}
static void F_207 ( struct V_5 * V_6 , T_1 V_366 ,
unsigned int V_367 )
{
unsigned int V_368 = V_367 ;
struct V_7 * V_8 = V_6 -> V_8 ;
if ( V_367 == V_110 ) {
if ( V_8 -> V_329 ) {
V_368 = V_369 ;
}
F_50 ( 100 ) ;
}
F_14 ( V_6 , V_366 , 0 , V_108 ,
V_368 ) ;
F_208 ( V_6 , V_366 , V_367 , true ) ;
}
static void F_30 ( struct V_5 * V_6 , int V_232 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
int V_370 = ! V_232 ;
if ( ! V_8 -> V_91 )
return;
if ( V_8 -> V_358 )
V_370 = ! V_370 ;
if ( ! V_8 -> V_329 ) {
if ( V_370 )
V_8 -> V_315 |= V_8 -> V_91 ;
else
V_8 -> V_315 &= ~ V_8 -> V_91 ;
F_151 ( V_6 , V_8 -> V_313 ,
V_8 -> V_84 , V_8 -> V_315 ) ;
} else {
V_8 -> V_371 = V_370 ? V_372 : V_136 ;
F_12 ( V_6 , V_8 -> V_329 ,
V_8 -> V_371 ) ;
}
}
static int F_209 ( struct V_5 * V_6 )
{
struct V_7 * V_8 ;
int V_25 ;
V_8 = F_210 ( sizeof( * V_8 ) , V_147 ) ;
if ( V_8 == NULL )
return - V_151 ;
V_6 -> V_373 = 1 ;
V_6 -> V_8 = V_8 ;
V_8 -> V_280 = 1 ;
V_8 -> V_96 = F_114 ( V_374 ) ;
V_8 -> V_97 = V_374 ;
V_8 -> V_375 = F_211 ( V_6 , V_376 ,
V_377 ,
V_378 ) ;
if ( V_8 -> V_375 < 0 )
F_13 ( V_379 L_58 ,
V_6 -> V_380 ) ;
else
F_47 ( V_6 ,
V_381 [ V_8 -> V_375 ] ) ;
V_8 -> V_30 . V_282 = 2 ;
V_8 -> V_30 . V_174 = 1 ;
V_8 -> V_30 . V_85 = V_382 ;
V_8 -> V_105 = V_383 ;
V_8 -> V_54 = V_384 ;
V_8 -> V_234 = 1 ;
V_8 -> V_248 = 0 ;
V_8 -> V_123 = 1 ;
V_8 -> V_327 = 0 ;
if ( V_8 -> V_375 == V_385 ||
V_8 -> V_375 == V_386 ||
V_8 -> V_375 == V_387 )
V_8 -> V_319 = V_388 ;
else
V_8 -> V_319 = V_389 ;
V_8 -> V_71 = V_390 ;
if ( V_8 -> V_375 == V_391 ) {
V_8 -> V_313 = V_8 -> V_84 = 0x09 ;
V_8 -> V_315 = 0x00 ;
}
V_25 = F_150 ( V_6 ) ;
if ( V_25 < 0 ) {
F_175 ( V_6 ) ;
return V_25 ;
}
if ( V_8 -> V_375 == V_391 )
V_8 -> V_139 = 0 ;
V_6 -> V_392 = V_393 ;
return 0 ;
}
static int F_212 ( struct V_5 * V_6 )
{
struct V_7 * V_8 ;
int V_25 ;
V_8 = F_210 ( sizeof( * V_8 ) , V_147 ) ;
if ( V_8 == NULL )
return - V_151 ;
V_6 -> V_373 = 1 ;
V_6 -> V_8 = V_8 ;
V_8 -> V_280 = 1 ;
V_8 -> V_96 = F_114 ( V_394 ) ;
V_8 -> V_97 = V_394 ;
V_8 -> V_375 = F_213 ( V_6 ,
V_395 ,
V_396 ,
V_397 ) ;
if ( V_8 -> V_375 < 0 )
V_8 -> V_375 = F_211 ( V_6 ,
V_395 ,
V_396 ,
V_398 ) ;
V_399:
if ( V_8 -> V_375 < 0 )
F_13 ( V_379 L_58 ,
V_6 -> V_380 ) ;
else
F_47 ( V_6 ,
V_400 [ V_8 -> V_375 ] ) ;
V_8 -> V_30 . V_282 = 2 ;
V_8 -> V_30 . V_174 = 1 ;
V_8 -> V_30 . V_85 = V_401 ;
V_8 -> V_105 = V_402 ;
V_8 -> V_54 = V_403 ;
V_8 -> V_234 = 1 ;
V_8 -> V_123 = 1 ;
V_8 -> V_327 = 0 ;
switch ( V_6 -> V_404 ) {
case 0x83847632 :
case 0x83847633 :
case 0x83847636 :
case 0x83847637 :
V_8 -> V_248 = V_405 ;
V_8 -> V_250 = V_406 ;
V_8 -> V_75 = F_114 ( V_407 ) ;
V_8 -> V_18 = V_407 ;
break;
default:
V_8 -> V_248 = 0 ;
break;
}
V_8 -> V_319 = V_408 ;
V_8 -> V_71 = V_409 ;
V_8 -> V_235 = 1 ;
V_8 -> V_236 = V_410 ;
V_8 -> V_281 = V_411 ;
V_25 = F_144 ( V_6 ) ;
if ( ! V_25 ) {
if ( V_8 -> V_375 < 0 ) {
F_112 ( V_207 L_59
L_60 ) ;
V_8 -> V_375 = V_412 ;
goto V_399;
}
V_25 = - V_225 ;
}
if ( V_25 < 0 ) {
F_175 ( V_6 ) ;
return V_25 ;
}
V_6 -> V_392 = V_393 ;
return 0 ;
}
static int F_214 ( struct V_5 * V_6 )
{
struct V_7 * V_8 ;
T_1 V_181 [ V_413 + 2 ] ;
int V_25 = 0 ;
int V_174 ;
V_8 = F_210 ( sizeof( * V_8 ) , V_147 ) ;
if ( V_8 == NULL )
return - V_151 ;
V_6 -> V_373 = 1 ;
V_6 -> V_8 = V_8 ;
V_8 -> V_280 = 0 ;
V_6 -> V_32 = V_414 ;
V_8 -> V_96 = F_114 ( V_415 ) ;
V_8 -> V_97 = V_415 ;
V_8 -> V_375 = F_211 ( V_6 ,
V_416 ,
V_417 ,
V_418 ) ;
if ( V_8 -> V_375 < 0 )
V_8 -> V_375 =
F_213 ( V_6 ,
V_416 , V_417 ,
V_419 ) ;
V_399:
if ( V_8 -> V_375 < 0 )
F_13 ( V_379 L_58 ,
V_6 -> V_380 ) ;
else
F_47 ( V_6 ,
V_420 [ V_8 -> V_375 ] ) ;
V_174 = F_101 ( V_6 , 0x0a ,
V_181 , V_413 + 2 ) - 1 ;
if ( V_174 < 3 || V_174 > 5 ) {
F_112 ( V_207 L_61
L_62 ) ;
V_174 = V_413 ;
}
V_8 -> V_319 = V_421 ;
switch ( V_174 ) {
case 0x3 :
V_8 -> V_93 = V_422 ;
break;
case 0x4 :
V_8 -> V_93 = V_423 ;
break;
case 0x5 :
V_8 -> V_93 = V_424 ;
break;
}
V_8 -> V_30 . V_85 = V_8 -> V_85 ;
V_8 -> V_62 = 0x01 ;
V_8 -> V_67 = 8 ;
V_8 -> V_278 = 0x1c ;
V_8 -> V_54 = V_425 ;
V_8 -> V_105 = V_426 ;
V_8 -> V_250 = V_427 ;
V_8 -> V_18 = V_428 ;
V_8 -> V_28 = V_429 ;
V_8 -> V_234 = F_114 ( V_425 ) ;
V_8 -> V_123 = F_114 ( V_426 ) ;
V_8 -> V_75 = F_114 ( V_428 ) ;
V_8 -> V_235 = V_430 ;
V_8 -> V_236 = V_431 ;
V_8 -> V_281 = V_432 ;
switch ( V_8 -> V_375 ) {
case V_433 :
V_8 -> V_319 = V_434 ;
case V_435 :
case V_436 :
case V_437 :
V_8 -> V_78 = 0 ;
V_8 -> V_317 = 0 ;
switch ( V_8 -> V_375 ) {
case V_435 :
F_48 ( V_6 , 0x0b , 0x90A70170 ) ;
V_8 -> V_248 = 0 ;
break;
case V_436 :
F_48 ( V_6 , 0x13 , 0x90A60160 ) ;
V_8 -> V_248 = 1 ;
break;
case V_437 :
F_48 ( V_6 , 0x0b , 0x90A70170 ) ;
F_48 ( V_6 , 0x13 , 0x90A60160 ) ;
V_8 -> V_248 = 1 ;
break;
}
break;
case V_438 :
V_8 -> V_248 = V_439 ;
V_8 -> V_78 = F_114 ( V_429 ) ;
V_8 -> V_317 = 0 ;
break;
default:
V_8 -> V_248 = V_439 ;
V_8 -> V_78 = F_114 ( V_429 ) ;
V_8 -> V_317 = 1 ;
break;
}
if ( V_8 -> V_375 != V_440 ) {
V_8 -> V_314 = V_8 -> V_313 = V_8 -> V_84 = 0x1 ;
V_8 -> V_315 = 0x01 ;
}
V_8 -> V_327 = F_114 ( V_441 ) ;
V_8 -> V_328 = V_441 ;
V_25 = F_144 ( V_6 ) ;
if ( ! V_25 ) {
if ( V_8 -> V_375 < 0 ) {
F_112 ( V_207 L_59
L_60 ) ;
V_8 -> V_375 = V_440 ;
goto V_399;
}
V_25 = - V_225 ;
}
if ( V_25 < 0 ) {
F_175 ( V_6 ) ;
return V_25 ;
}
if ( V_8 -> V_375 == V_442 )
V_8 -> V_139 = 0 ;
V_6 -> V_392 = V_393 ;
V_6 -> V_443 = F_200 ;
return 0 ;
}
static int F_215 ( struct V_5 * V_6 )
{
if ( V_6 -> V_404 != 0x111d7605 &&
V_6 -> V_404 != 0x111d76d1 )
return 0 ;
switch ( V_6 -> V_347 ) {
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
unsigned int V_153 = F_91 ( V_6 , V_27 ) ;
int V_70 ;
V_8 -> V_444 [ V_8 -> V_445 ] = V_27 ;
V_8 -> V_445 ++ ;
if ( F_135 ( V_153 ) == V_257 &&
F_132 ( V_153 ) != V_252 ) {
for ( V_70 = 0 ; V_70 < F_114 ( V_446 ) ; V_70 ++ ) {
if ( V_27 == V_446 [ V_70 ] ) {
V_8 -> V_447 [ V_8 -> V_448 ] = V_27 ;
V_8 -> V_448 ++ ;
}
}
}
}
static void F_217 ( struct V_5 * V_6 , T_1 V_27 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
V_8 -> V_449 [ V_8 -> V_450 ] = V_27 ;
V_8 -> V_450 ++ ;
}
static void F_218 ( struct V_5 * V_6 , T_1 V_27 )
{
int V_70 , V_179 ;
struct V_7 * V_8 = V_6 -> V_8 ;
for ( V_70 = 0 ; V_70 < V_8 -> V_450 ; V_70 ++ ) {
if ( F_133 ( V_6 ,
V_8 -> V_449 [ V_70 ] , V_27 ) >= 0 ) {
if ( ! V_8 -> V_451 [ V_70 ] ) {
V_8 -> V_451 [ V_70 ] = V_27 ;
V_8 -> V_452 [ V_70 ] = F_111 ( V_27 ,
3 , 0 , V_35 ) ;
}
for ( V_179 = 0 ; V_179 < V_8 -> V_448 ; V_179 ++ ) {
if ( F_133 ( V_6 , V_27 ,
V_8 -> V_447 [ V_179 ] ) >= 0 ) {
if ( ! V_8 -> V_453 [ V_70 ] )
V_8 -> V_453 [ V_70 ] = V_27 ;
break;
}
}
break;
}
}
}
static void F_219 ( struct V_5 * V_6 )
{
T_1 V_27 , V_454 ;
unsigned int V_212 , V_276 ;
struct V_7 * V_8 = V_6 -> V_8 ;
V_454 = V_6 -> V_284 + V_6 -> V_285 ;
for ( V_27 = V_6 -> V_284 ; V_27 < V_454 ; V_27 ++ ) {
V_212 = F_36 ( V_6 , V_27 ) ;
V_276 = F_102 ( V_212 ) ;
if ( V_276 == V_251 )
F_216 ( V_6 , V_27 ) ;
if ( V_276 == V_286 && ! ( V_212 & V_186 ) )
F_217 ( V_6 , V_27 ) ;
}
for ( V_27 = V_6 -> V_284 ; V_27 < V_454 ; V_27 ++ ) {
V_212 = F_36 ( V_6 , V_27 ) ;
V_276 = F_102 ( V_212 ) ;
if ( V_276 == V_277 )
F_218 ( V_6 , V_27 ) ;
}
V_8 -> V_97 = V_8 -> V_444 ;
V_8 -> V_96 = V_8 -> V_445 ;
V_8 -> V_105 = V_8 -> V_449 ;
V_8 -> V_123 = V_8 -> V_450 ;
V_8 -> V_236 = V_8 -> V_452 ;
V_8 -> V_281 = V_8 -> V_452 ;
V_8 -> V_235 = V_8 -> V_450 ;
V_8 -> V_54 = V_8 -> V_451 ;
V_8 -> V_234 = V_8 -> V_450 ;
V_8 -> V_18 = V_8 -> V_453 ;
V_8 -> V_75 = V_8 -> V_450 ;
V_8 -> V_250 = V_8 -> V_447 ;
V_8 -> V_248 = V_8 -> V_448 ;
}
static int F_220 ( struct V_5 * V_6 )
{
struct V_7 * V_8 ;
int V_355 = - 1 ;
int V_25 ;
V_8 = F_210 ( sizeof( * V_8 ) , V_147 ) ;
if ( V_8 == NULL )
return - V_151 ;
if ( F_215 ( V_6 ) ) {
F_48 ( V_6 , 0xa , 0x2101201f ) ;
F_48 ( V_6 , 0xf , 0x2181205e ) ;
}
V_6 -> V_455 = 0 ;
V_6 -> V_373 = 1 ;
V_6 -> V_8 = V_8 ;
F_219 ( V_6 ) ;
V_8 -> V_280 = 0 ;
V_6 -> V_32 = V_456 ;
V_8 -> V_278 = 0x21 ;
V_8 -> V_328 = V_457 ;
V_8 -> V_327 = F_114 ( V_457 ) ;
V_8 -> V_30 . V_85 = V_8 -> V_85 ;
V_8 -> V_319 = V_458 ;
V_8 -> V_375 = F_211 ( V_6 ,
V_459 ,
V_460 ,
V_461 ) ;
if ( V_8 -> V_375 < 0 )
V_8 -> V_375 =
F_213 ( V_6 ,
V_459 , V_460 ,
V_462 ) ;
V_399:
if ( V_8 -> V_375 < 0 )
F_13 ( V_379 L_58 ,
V_6 -> V_380 ) ;
else
F_47 ( V_6 ,
V_463 [ V_8 -> V_375 ] ) ;
V_6 -> V_392 = V_393 ;
switch ( V_8 -> V_375 ) {
case V_464 :
V_8 -> V_319 = V_465 ;
break;
case V_466 :
V_355 = 0 ;
break;
case V_467 :
V_355 = 1 ;
break;
}
if ( F_194 ( V_6 , V_355 ) )
F_107 ( L_63 ,
V_8 -> V_91 ,
V_8 -> V_358 ) ;
if ( V_8 -> V_91 ) {
if ( ! V_8 -> V_329 ) {
V_8 -> V_313 |= V_8 -> V_91 ;
V_8 -> V_84 |= V_8 -> V_91 ;
V_8 -> V_315 |= V_8 -> V_91 ;
} else {
V_6 -> V_392 . V_468 =
F_207 ;
}
}
V_25 = F_144 ( V_6 ) ;
if ( ! V_25 ) {
if ( V_8 -> V_375 < 0 ) {
F_112 ( V_207 L_59
L_60 ) ;
V_8 -> V_375 = V_469 ;
goto V_399;
}
V_25 = - V_225 ;
}
if ( V_25 < 0 ) {
F_175 ( V_6 ) ;
return V_25 ;
}
V_6 -> V_443 = F_197 ;
return 0 ;
}
static int F_221 ( struct V_5 * V_6 ,
T_1 V_470 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
int V_50 ;
for ( V_50 = 0 ; V_50 < V_8 -> V_96 ; V_50 ++ )
if ( V_8 -> V_97 [ V_50 ] == V_470 )
break;
if ( ( V_50 + 2 ) >= V_8 -> V_96 )
return 0 ;
if ( F_185 ( V_6 , V_50 + 1 ) != V_252 )
return 2 ;
if ( F_185 ( V_6 , V_50 + 2 ) != V_252 )
return 2 ;
if ( F_185 ( V_6 , V_50 ) != V_252 )
return 1 ;
else
return 0 ;
}
static int F_222 ( struct V_1 * V_2 ,
struct V_10 * V_11 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = V_6 -> V_8 ;
V_11 -> V_14 . integer . V_14 [ 0 ] = ! ! ( V_8 -> V_315 & 0x20 ) ;
return 0 ;
}
static int F_223 ( struct V_1 * V_2 ,
struct V_10 * V_11 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = V_6 -> V_8 ;
unsigned int V_315 ;
V_315 = ( V_8 -> V_315 & ~ 0x20 ) |
( V_11 -> V_14 . integer . V_14 [ 0 ] ? 0x20 : 0 ) ;
if ( V_315 == V_8 -> V_315 )
return 0 ;
V_8 -> V_315 = V_315 ;
F_151 ( V_6 , V_8 -> V_313 , V_8 -> V_84 , V_8 -> V_315 ) ;
return 1 ;
}
static int F_224 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
if ( ! F_83 ( V_8 , & V_471 ,
L_64 , 0 ) )
return - V_151 ;
V_8 -> V_313 |= 0x20 ;
V_8 -> V_84 |= 0x20 ;
V_8 -> V_315 |= 0x20 ;
return 0 ;
}
static int F_225 ( struct V_5 * V_6 )
{
struct V_7 * V_8 ;
const struct V_472 * V_473 = V_474 ;
unsigned int V_475 ;
int V_25 = 0 ;
V_8 = F_210 ( sizeof( * V_8 ) , V_147 ) ;
if ( V_8 == NULL )
return - V_151 ;
V_6 -> V_373 = 1 ;
V_6 -> V_8 = V_8 ;
V_8 -> V_280 = 0 ;
V_6 -> V_392 = V_393 ;
V_8 -> V_96 = V_476 ;
switch ( V_6 -> V_404 ) {
case 0x111d76b6 :
case 0x111d76b7 :
V_8 -> V_97 = V_477 ;
break;
case 0x111d7603 :
case 0x111d7608 :
V_8 -> V_96 -- ;
default:
V_8 -> V_97 = V_478 ;
}
V_8 -> V_327 = F_114 ( V_479 ) ;
V_8 -> V_375 = F_211 ( V_6 ,
V_480 ,
V_481 ,
V_482 ) ;
V_399:
if ( V_8 -> V_375 < 0 )
F_13 ( V_379 L_58 ,
V_6 -> V_380 ) ;
else
F_47 ( V_6 ,
V_483 [ V_8 -> V_375 ] ) ;
if ( V_8 -> V_375 != V_484 ) {
V_8 -> V_313 = 0x01 ;
V_8 -> V_84 = 0x01 ;
V_8 -> V_315 = 0x01 ;
}
V_8 -> V_250 = V_485 ;
V_8 -> V_18 = V_486 ;
V_8 -> V_235 = V_487 ;
V_8 -> V_236 = V_488 ;
V_8 -> V_281 = V_489 ;
switch ( V_6 -> V_404 ) {
case 0x111d76b6 :
case 0x111d76b7 :
V_473 ++ ;
case 0x111d76b4 :
case 0x111d76b5 :
V_6 -> V_32 = V_490 ;
V_8 -> V_248 = F_186 ( V_6 ,
V_485 ,
V_491 ) ;
break;
case 0x111d7608 :
switch ( V_8 -> V_375 ) {
case V_492 :
V_25 = F_152 ( V_6 , V_6 -> V_65 ,
V_349 , 0x02 ) ;
if ( V_25 < 0 )
return V_25 ;
F_21 ( V_6 , V_6 -> V_65 , 0 ,
V_493 , 0x02 ) ;
F_155 ( V_6 , V_6 -> V_65 , 0 ) ;
V_8 -> V_313 |= 0x02 ;
break;
}
if ( ( V_6 -> V_494 & 0xf ) == 0 ||
( V_6 -> V_494 & 0xf ) == 1 )
V_8 -> V_102 = 40 ;
V_473 ++ ;
F_48 ( V_6 , 0x0f , 0x40f000f0 ) ;
F_48 ( V_6 , 0x19 , 0x40f000f3 ) ;
V_8 -> V_250 = V_495 ;
V_8 -> V_248 = F_186 ( V_6 ,
V_495 ,
V_491 - 1 ) ;
break;
case 0x111d7603 :
if ( ( V_6 -> V_494 & 0xf ) == 1 )
V_8 -> V_102 = 40 ;
default:
V_6 -> V_32 = V_490 ;
V_8 -> V_248 = F_186 ( V_6 ,
V_485 ,
V_491 ) ;
break;
}
if ( F_102 ( F_36 ( V_6 , 0x28 ) ) == V_496 )
V_8 -> V_319 = V_497 ;
if ( F_36 ( V_6 , 0xa ) & V_244 )
F_226 ( V_6 , V_473 ) ;
V_8 -> V_93 = V_498 ;
V_8 -> V_62 = 0x50 ;
V_8 -> V_67 = 0 ;
V_8 -> V_107 = 1 ;
V_8 -> V_278 = 0x26 ;
V_8 -> V_54 = V_499 ;
V_8 -> V_105 = V_500 ;
V_8 -> V_28 = V_501 ;
V_8 -> V_328 = V_479 ;
V_8 -> V_234 = F_114 ( V_499 ) ;
V_8 -> V_123 = F_114 ( V_500 ) ;
V_8 -> V_75 = F_114 ( V_486 ) ;
V_8 -> V_78 = F_221 ( V_6 , 0x1e ) ;
F_13 ( L_65 , V_8 -> V_375 ) ;
switch ( V_8 -> V_375 ) {
case V_492 :
F_48 ( V_6 , 0x0e , 0x01813040 ) ;
F_70 ( V_6 , 0x0e ,
V_42 | V_348 ) ;
case V_502 :
V_8 -> V_248 = 0 ;
V_8 -> V_78 = 0 ;
V_8 -> V_75 = 0 ;
break;
case V_503 :
case V_504 :
V_8 -> V_248 = 1 ;
V_8 -> V_78 = 0 ;
V_8 -> V_75 = 1 ;
break;
case V_505 :
V_8 -> V_248 = 1 ;
V_8 -> V_78 = 1 ;
V_8 -> V_75 = 1 ;
case V_506 :
V_8 -> V_91 = 0x01 ;
case V_507 :
F_48 ( V_6 , 0x0d , 0x90170010 ) ;
F_70 ( V_6 , 0x0d , V_43 ) ;
V_8 -> V_139 = 1 ;
break;
case V_508 :
V_8 -> V_248 = 1 ;
V_8 -> V_75 = 1 ;
V_8 -> V_78 = 1 ;
V_8 -> V_91 = 0x08 ;
break;
}
if ( F_196 ( V_6 -> V_347 ) ) {
V_475 = F_91 ( V_6 , 0x0f ) ;
if ( F_135 ( V_475 ) == V_509 ||
F_135 ( V_475 ) == V_293 ||
F_135 ( V_475 ) == V_510 ) {
V_475 = ( V_475 & ( ~ V_511 ) )
| ( V_510 <<
V_512 ) ;
V_475 = ( V_475 & ( ~ ( V_513
| V_514 ) ) )
| 0x1f ;
F_48 ( V_6 , 0x0f , V_475 ) ;
}
}
if ( F_194 ( V_6 , 1 ) )
F_107 ( L_63 ,
V_8 -> V_91 ,
V_8 -> V_358 ) ;
if ( V_8 -> V_91 ) {
if ( ! V_8 -> V_329 ) {
V_8 -> V_313 |= V_8 -> V_91 ;
V_8 -> V_84 |= V_8 -> V_91 ;
V_8 -> V_315 |= V_8 -> V_91 ;
} else {
V_6 -> V_392 . V_468 =
F_207 ;
}
}
V_8 -> V_30 . V_85 = V_8 -> V_85 ;
V_25 = F_144 ( V_6 ) ;
if ( ! V_25 ) {
if ( V_8 -> V_375 < 0 ) {
F_112 ( V_207 L_59
L_60 ) ;
V_8 -> V_375 = V_484 ;
goto V_399;
}
V_25 = - V_225 ;
}
if ( V_25 < 0 ) {
F_175 ( V_6 ) ;
return V_25 ;
}
if ( V_8 -> V_375 == V_506 ||
V_8 -> V_375 == V_507 ) {
unsigned int V_515 ;
V_515 = F_193 ( V_6 , 0x1 , V_353 ) ;
V_515 &= V_354 ;
if ( V_515 >= 6 )
F_224 ( V_6 ) ;
}
V_6 -> V_443 = F_200 ;
return 0 ;
}
static int F_227 ( struct V_5 * V_6 )
{
struct V_7 * V_8 ;
int V_25 ;
V_8 = F_210 ( sizeof( * V_8 ) , V_147 ) ;
if ( V_8 == NULL )
return - V_151 ;
V_6 -> V_373 = 1 ;
V_6 -> V_8 = V_8 ;
V_8 -> V_280 = 1 ;
V_8 -> V_96 = F_114 ( V_516 ) ;
V_8 -> V_97 = V_516 ;
V_8 -> V_375 = F_211 ( V_6 , V_517 ,
V_518 ,
V_519 ) ;
if ( V_8 -> V_375 == V_520 ) {
V_8 -> V_313 = V_8 -> V_84 = 0x03 ;
V_8 -> V_315 = 0x03 ;
F_112 ( V_379 L_66 , V_6 -> V_347 ) ;
switch ( V_6 -> V_347 ) {
case 0x106b0800 :
V_8 -> V_375 = V_521 ;
break;
case 0x106b0600 :
case 0x106b0700 :
V_8 -> V_375 = V_522 ;
break;
case 0x106b0e00 :
case 0x106b0f00 :
case 0x106b1600 :
case 0x106b1700 :
case 0x106b0200 :
case 0x106b1e00 :
V_8 -> V_375 = V_523 ;
break;
case 0x106b1a00 :
case 0x00000100 :
V_8 -> V_375 = V_524 ;
break;
case 0x106b0a00 :
case 0x106b2200 :
V_8 -> V_375 = V_525 ;
break;
default:
V_8 -> V_375 = V_523 ;
break;
}
}
V_399:
if ( V_8 -> V_375 < 0 )
F_13 ( V_379 L_58 ,
V_6 -> V_380 ) ;
else
F_47 ( V_6 ,
V_526 [ V_8 -> V_375 ] ) ;
V_8 -> V_105 = V_527 ;
V_8 -> V_54 = V_528 ;
V_8 -> V_234 = F_114 ( V_528 ) ;
V_8 -> V_123 = F_114 ( V_527 ) ;
V_8 -> V_248 = 0 ;
V_8 -> V_327 = 0 ;
V_8 -> V_319 = V_529 ;
V_8 -> V_235 = V_530 ;
V_8 -> V_236 = V_531 ;
V_8 -> V_281 = V_532 ;
V_8 -> V_30 . V_85 = V_8 -> V_85 ;
V_25 = F_144 ( V_6 ) ;
if ( ! V_25 ) {
if ( V_8 -> V_375 < 0 ) {
F_112 ( V_207 L_59
L_60 ) ;
V_8 -> V_375 = V_533 ;
goto V_399;
}
V_25 = - V_225 ;
}
if ( V_25 < 0 ) {
F_175 ( V_6 ) ;
return V_25 ;
}
V_6 -> V_392 = V_393 ;
F_228 ( V_6 , 0x12 , V_35 ,
( 0 << V_534 ) |
( 2 << V_204 ) |
( 0x27 << V_202 ) |
( 0 << V_230 ) ) ;
return 0 ;
}
static int F_229 ( struct V_5 * V_6 )
{
struct V_7 * V_8 ;
int V_25 ;
V_8 = F_210 ( sizeof( * V_8 ) , V_147 ) ;
if ( V_8 == NULL )
return - V_151 ;
V_6 -> V_373 = 1 ;
V_6 -> V_8 = V_8 ;
V_8 -> V_280 = 1 ;
V_6 -> V_32 = V_535 ;
V_8 -> V_96 = F_114 ( V_536 ) ;
V_8 -> V_97 = V_536 ;
V_8 -> V_375 = F_211 ( V_6 , V_537 ,
V_538 ,
V_539 ) ;
V_399:
if ( V_8 -> V_375 < 0 )
F_13 ( V_379 L_58 ,
V_6 -> V_380 ) ;
else
F_47 ( V_6 ,
V_540 [ V_8 -> V_375 ] ) ;
V_8 -> V_278 = 0x23 ;
V_8 -> V_105 = V_541 ;
V_8 -> V_123 = F_114 ( V_541 ) ;
V_8 -> V_54 = V_542 ;
V_8 -> V_234 = F_114 ( V_542 ) ;
V_8 -> V_28 = V_543 ;
V_8 -> V_78 = F_114 ( V_543 ) ;
V_8 -> V_239 = V_544 ;
V_8 -> V_309 = V_545 ;
V_8 -> V_30 . V_85 = V_8 -> V_85 ;
if ( V_8 -> V_375 != V_546 ) {
V_8 -> V_314 = V_8 -> V_313 = 0x01 ;
V_8 -> V_84 = V_8 -> V_315 = 0x01 ;
}
switch ( V_8 -> V_375 ) {
case V_547 :
case V_548 :
V_8 -> V_248 = 0 ;
V_8 -> V_319 = V_549 ;
break;
case V_550 :
switch ( V_6 -> V_347 ) {
case 0x10280209 :
case 0x1028022e :
F_48 ( V_6 , 0x21 , 0x01442070 ) ;
break;
}
F_48 ( V_6 , 0x0c , 0x90a79130 ) ;
F_48 ( V_6 , 0x0f , 0x0227011f ) ;
F_48 ( V_6 , 0x0e , 0x02a79130 ) ;
case V_551 :
if ( V_6 -> V_347 != 0x1028022f ) {
V_8 -> V_314 = V_8 -> V_313 = 0x04 ;
V_8 -> V_84 = V_8 -> V_315 = 0x04 ;
}
V_8 -> V_250 = V_552 ;
V_8 -> V_248 = V_553 ;
V_8 -> V_319 = V_554 ;
V_8 -> V_18 = V_555 ;
V_8 -> V_75 = F_114 ( V_555 ) ;
break;
case V_556 :
V_8 -> V_248 = 0 ;
V_8 -> V_319 = V_557 ;
break;
default:
V_8 -> V_248 = 0 ;
V_8 -> V_319 = V_558 ;
break;
}
V_8 -> V_235 = V_559 ;
V_8 -> V_236 = V_560 ;
V_8 -> V_281 = V_561 ;
V_8 -> V_327 = 0 ;
V_8 -> V_93 = V_562 ;
V_8 -> V_62 = 0x40 ;
V_8 -> V_67 = 0 ;
V_8 -> V_317 = 1 ;
V_25 = F_144 ( V_6 ) ;
if ( ! V_25 ) {
if ( V_8 -> V_375 < 0 ) {
F_112 ( V_207 L_59
L_60 ) ;
V_8 -> V_375 = V_546 ;
goto V_399;
}
V_25 = - V_225 ;
}
if ( V_25 < 0 ) {
F_175 ( V_6 ) ;
return V_25 ;
}
V_6 -> V_392 = V_393 ;
V_6 -> V_443 = F_202 ;
V_6 -> V_335 -> V_563 = 1 ;
if ( V_8 -> V_375 == V_564 )
V_8 -> V_139 = 0 ;
return 0 ;
}
static int F_230 ( struct V_5 * V_6 )
{
struct V_7 * V_8 ;
int V_25 ;
V_8 = F_210 ( sizeof( * V_8 ) , V_147 ) ;
if ( V_8 == NULL )
return - V_151 ;
V_6 -> V_373 = 1 ;
V_6 -> V_8 = V_8 ;
V_8 -> V_280 = 1 ;
V_8 -> V_96 = F_114 ( V_565 ) ;
V_8 -> V_97 = V_565 ;
V_8 -> V_375 = F_211 ( V_6 , V_566 ,
V_567 ,
V_568 ) ;
V_399:
if ( V_8 -> V_375 < 0 )
F_13 ( V_379 L_58 ,
V_6 -> V_380 ) ;
else
F_47 ( V_6 ,
V_569 [ V_8 -> V_375 ] ) ;
V_8 -> V_278 = 0x23 ;
V_8 -> V_105 = V_570 ;
V_8 -> V_123 = F_114 ( V_570 ) ;
V_8 -> V_54 = V_571 ;
V_8 -> V_234 = F_114 ( V_571 ) ;
V_8 -> V_28 = V_572 ;
V_8 -> V_78 = F_114 ( V_572 ) ;
V_8 -> V_250 = V_573 ;
V_8 -> V_248 = V_574 ;
V_8 -> V_18 = V_575 ;
V_8 -> V_75 = F_114 ( V_575 ) ;
V_8 -> V_327 = 0 ;
V_8 -> V_319 = V_576 ;
V_8 -> V_93 = V_577 ;
V_8 -> V_235 = V_578 ;
V_8 -> V_236 = V_579 ;
V_8 -> V_281 = V_580 ;
V_8 -> V_62 = 0x40 ;
V_8 -> V_67 = 0 ;
if ( V_8 -> V_375 != V_581 )
V_8 -> V_317 = 1 ;
V_8 -> V_30 . V_85 = V_8 -> V_85 ;
switch ( V_8 -> V_375 ) {
case V_582 :
F_48 ( V_6 , 0x1f , 0x01441030 ) ;
F_48 ( V_6 , 0x20 , 0x1c410030 ) ;
V_25 = F_152 ( V_6 , V_6 -> V_65 , V_349 , 0x01 ) ;
if ( V_25 < 0 )
return V_25 ;
F_21 ( V_6 , V_6 -> V_65 , 0 ,
V_493 , 0x10 ) ;
F_155 ( V_6 , V_6 -> V_65 , 0 ) ;
V_8 -> V_84 = 0x0b ;
V_8 -> V_314 = 0x01 ;
V_8 -> V_313 = 0x1b ;
V_8 -> V_316 = 0x10 ;
V_8 -> V_315 = 0x01 ;
break;
case V_583 :
break;
default:
V_8 -> V_314 = V_8 -> V_313 = V_8 -> V_84 = 0x1 ;
V_8 -> V_315 = 0x01 ;
break;
}
V_25 = F_144 ( V_6 ) ;
if ( ! V_25 ) {
if ( V_8 -> V_375 < 0 ) {
F_112 ( V_207 L_59
L_60 ) ;
V_8 -> V_375 = V_583 ;
goto V_399;
}
V_25 = - V_225 ;
}
if ( V_25 < 0 ) {
F_175 ( V_6 ) ;
return V_25 ;
}
V_6 -> V_392 = V_393 ;
V_6 -> V_443 = F_201 ;
return 0 ;
}
static int F_231 ( struct V_5 * V_6 )
{
struct V_7 * V_8 ;
int V_25 ;
V_8 = F_210 ( sizeof( * V_8 ) , V_147 ) ;
if ( V_8 == NULL )
return - V_151 ;
V_6 -> V_373 = 1 ;
V_6 -> V_8 = V_8 ;
V_8 -> V_280 = 1 ;
V_8 -> V_96 = F_114 ( V_584 ) ;
V_8 -> V_97 = V_584 ;
V_8 -> V_375 = F_211 ( V_6 , V_585 ,
V_586 ,
V_587 ) ;
if ( V_8 -> V_375 < 0 )
F_13 ( V_379 L_58 ,
V_6 -> V_380 ) ;
else
F_47 ( V_6 ,
V_588 [ V_8 -> V_375 ] ) ;
V_8 -> V_30 . V_85 = V_8 -> V_85 ;
V_8 -> V_123 = F_114 ( V_589 ) ;
V_8 -> V_105 = V_589 ;
V_8 -> V_234 = F_114 ( V_590 ) ;
V_8 -> V_54 = V_590 ;
V_8 -> V_319 = V_591 ;
V_8 -> V_235 = 1 ;
V_8 -> V_236 = V_592 ;
V_8 -> V_281 = V_593 ;
V_25 = F_144 ( V_6 ) ;
if ( V_25 < 0 ) {
F_175 ( V_6 ) ;
return - V_225 ;
}
V_8 -> V_46 = & V_8 -> V_160 ;
V_6 -> V_392 = V_393 ;
return 0 ;
}
static int T_3 F_232 ( void )
{
return F_233 ( & V_594 ) ;
}
static void T_4 F_234 ( void )
{
F_235 ( & V_594 ) ;
}
