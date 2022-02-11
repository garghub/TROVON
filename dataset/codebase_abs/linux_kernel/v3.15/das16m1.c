static inline unsigned short F_1 ( unsigned short V_1 )
{
return ( V_1 >> 4 ) & 0xfff ;
}
static void F_2 ( unsigned short * V_2 , unsigned int V_3 )
{
unsigned int V_4 ;
for ( V_4 = 0 ; V_4 < V_3 ; V_4 ++ )
V_2 [ V_4 ] = F_1 ( V_2 [ V_4 ] ) ;
}
static int F_3 ( struct V_5 * V_6 ,
struct V_7 * V_8 , struct V_9 * V_10 )
{
struct V_11 * V_12 = V_6 -> V_13 ;
unsigned int V_14 = 0 , V_15 , V_4 ;
V_14 |= F_4 ( & V_10 -> V_16 , V_17 | V_18 ) ;
V_14 |= F_4 ( & V_10 -> V_19 , V_20 ) ;
V_14 |= F_4 ( & V_10 -> V_21 , V_22 | V_18 ) ;
V_14 |= F_4 ( & V_10 -> V_23 , V_24 ) ;
V_14 |= F_4 ( & V_10 -> V_25 , V_24 | V_26 ) ;
if ( V_14 )
return 1 ;
V_14 |= F_5 ( V_10 -> V_16 ) ;
V_14 |= F_5 ( V_10 -> V_21 ) ;
V_14 |= F_5 ( V_10 -> V_25 ) ;
if ( V_14 )
return 2 ;
V_14 |= F_6 ( & V_10 -> V_27 , 0 ) ;
if ( V_10 -> V_19 == V_20 )
V_14 |= F_6 ( & V_10 -> V_28 , 0 ) ;
if ( V_10 -> V_21 == V_22 )
V_14 |= F_7 ( & V_10 -> V_29 , 1000 ) ;
V_14 |= F_6 ( & V_10 -> V_30 , V_10 -> V_31 ) ;
if ( V_10 -> V_25 == V_24 ) {
} else {
V_14 |= F_6 ( & V_10 -> V_32 , 0 ) ;
}
if ( V_14 )
return 3 ;
if ( V_10 -> V_21 == V_22 ) {
V_15 = V_10 -> V_29 ;
F_8 ( V_33 ,
& V_12 -> V_34 ,
& V_12 -> V_35 ,
& V_10 -> V_29 , V_10 -> V_36 ) ;
if ( V_15 != V_10 -> V_29 )
V_14 ++ ;
}
if ( V_14 )
return 4 ;
if ( V_10 -> V_37 && V_10 -> V_31 > 1 ) {
for ( V_4 = 0 ; V_4 < V_10 -> V_31 ; V_4 ++ ) {
if ( ( V_4 % 2 ) != ( F_9 ( V_10 -> V_37 [ V_4 ] ) % 2 ) ) {
F_10 ( V_6 , L_1
L_2 ) ;
V_14 ++ ;
}
}
if ( ( V_10 -> V_31 % 2 ) != 0 ) {
F_10 ( V_6 ,
L_3 ) ;
V_14 ++ ;
}
}
if ( V_14 )
return 5 ;
return 0 ;
}
static unsigned int F_11 ( struct V_5 * V_6 ,
unsigned int V_38 , int V_39 )
{
struct V_11 * V_12 = V_6 -> V_13 ;
F_12 ( V_33 ,
& V_12 -> V_34 ,
& V_12 -> V_35 ,
& V_38 , V_39 ) ;
F_13 ( V_6 -> V_40 + V_41 , 0 , 1 , V_12 -> V_34 ,
2 ) ;
F_13 ( V_6 -> V_40 + V_41 , 0 , 2 , V_12 -> V_35 ,
2 ) ;
return V_38 ;
}
static int F_14 ( struct V_5 * V_6 ,
struct V_7 * V_8 )
{
struct V_11 * V_12 = V_6 -> V_13 ;
struct V_42 * V_43 = V_8 -> V_43 ;
struct V_9 * V_10 = & V_43 -> V_10 ;
unsigned int V_44 , V_4 ;
V_12 -> V_45 &= ~ V_46 & ~ V_47 ;
F_15 ( V_12 -> V_45 , V_6 -> V_40 + V_48 ) ;
V_12 -> V_49 = 0 ;
F_13 ( V_6 -> V_40 + V_50 , 0 , 1 , 0 , 2 ) ;
V_12 -> V_51 =
F_16 ( V_6 -> V_40 + V_50 , 0 , 1 ) ;
for ( V_4 = 0 ; V_4 < V_10 -> V_31 ; V_4 ++ ) {
F_15 ( V_4 , V_6 -> V_40 + V_52 ) ;
V_44 =
F_17 ( F_9 ( V_10 -> V_37 [ V_4 ] ) ) |
F_18 ( F_19 ( V_10 -> V_37 [ V_4 ] ) ) ;
F_15 ( V_44 , V_6 -> V_40 + V_53 ) ;
}
V_10 -> V_29 =
F_11 ( V_6 , V_10 -> V_29 ,
V_10 -> V_36 & V_54 ) ;
V_44 = 0 ;
if ( V_10 -> V_16 == V_18 && V_10 -> V_21 != V_18 )
V_44 |= V_55 ;
F_15 ( V_44 , V_6 -> V_40 + V_56 ) ;
F_15 ( 0 , V_6 -> V_40 + V_57 ) ;
V_12 -> V_45 &= ~ V_47 ;
if ( V_10 -> V_21 == V_22 )
V_12 -> V_45 |= V_58 ;
else
V_12 -> V_45 |= V_59 ;
V_12 -> V_45 |= V_46 ;
F_15 ( V_12 -> V_45 , V_6 -> V_40 + V_48 ) ;
return 0 ;
}
static int F_20 ( struct V_5 * V_6 , struct V_7 * V_8 )
{
struct V_11 * V_12 = V_6 -> V_13 ;
V_12 -> V_45 &= ~ V_46 & ~ V_47 ;
F_15 ( V_12 -> V_45 , V_6 -> V_40 + V_48 ) ;
return 0 ;
}
static int F_21 ( struct V_5 * V_6 ,
struct V_7 * V_8 ,
struct V_60 * V_61 ,
unsigned long V_62 )
{
unsigned int V_63 ;
V_63 = F_22 ( V_6 -> V_40 + V_56 ) ;
if ( V_63 & V_64 )
return 0 ;
return - V_65 ;
}
static int F_23 ( struct V_5 * V_6 ,
struct V_7 * V_8 ,
struct V_60 * V_61 , unsigned int * V_1 )
{
struct V_11 * V_12 = V_6 -> V_13 ;
int V_66 ;
int V_67 ;
int V_44 ;
V_12 -> V_45 &= ~ V_46 & ~ V_47 ;
F_15 ( V_12 -> V_45 , V_6 -> V_40 + V_48 ) ;
F_15 ( 0 , V_6 -> V_40 + V_52 ) ;
V_44 =
F_17 ( F_9 ( V_61 -> V_68 ) ) | F_18 ( F_19 ( V_61 -> V_68 ) ) ;
F_15 ( V_44 , V_6 -> V_40 + V_53 ) ;
for ( V_67 = 0 ; V_67 < V_61 -> V_67 ; V_67 ++ ) {
F_15 ( 0 , V_6 -> V_40 + V_57 ) ;
F_15 ( 0 , V_6 -> V_40 ) ;
V_66 = F_24 ( V_6 , V_8 , V_61 , F_21 , 0 ) ;
if ( V_66 )
return V_66 ;
V_1 [ V_67 ] = F_1 ( F_25 ( V_6 -> V_40 ) ) ;
}
return V_67 ;
}
static int F_26 ( struct V_5 * V_6 ,
struct V_7 * V_8 ,
struct V_60 * V_61 , unsigned int * V_1 )
{
unsigned int V_69 ;
V_69 = F_22 ( V_6 -> V_40 + V_70 ) & 0xf ;
V_1 [ 1 ] = V_69 ;
V_1 [ 0 ] = 0 ;
return V_61 -> V_67 ;
}
static int F_27 ( struct V_5 * V_6 ,
struct V_7 * V_8 ,
struct V_60 * V_61 ,
unsigned int * V_1 )
{
if ( F_28 ( V_8 , V_1 ) )
F_15 ( V_8 -> V_71 , V_6 -> V_40 + V_70 ) ;
V_1 [ 1 ] = V_8 -> V_71 ;
return V_61 -> V_67 ;
}
static void F_29 ( struct V_5 * V_6 , unsigned int V_63 )
{
struct V_11 * V_12 = V_6 -> V_13 ;
struct V_7 * V_8 ;
struct V_42 * V_43 ;
struct V_9 * V_10 ;
T_1 V_72 ;
T_1 V_73 ;
V_8 = V_6 -> V_74 ;
V_43 = V_8 -> V_43 ;
V_10 = & V_43 -> V_10 ;
V_73 = F_16 ( V_6 -> V_40 + V_50 , 0 , 1 ) ;
if ( V_12 -> V_49 == 0 && V_73 == V_12 -> V_51 ) {
V_72 = 0 ;
} else {
V_72 = - V_73 - V_12 -> V_49 ;
}
if ( V_10 -> V_25 == V_24 ) {
if ( V_72 > V_10 -> V_32 * V_10 -> V_31 )
V_72 = V_10 -> V_32 * V_10 -> V_31 ;
}
if ( V_72 > V_75 )
V_72 = V_75 ;
F_30 ( V_6 -> V_40 , V_12 -> V_76 , V_72 ) ;
F_2 ( V_12 -> V_76 , V_72 ) ;
F_31 ( V_8 , V_12 -> V_76 ,
V_72 * sizeof( short ) ) ;
V_12 -> V_49 += V_72 ;
if ( V_10 -> V_25 == V_24 ) {
if ( V_12 -> V_49 >= V_10 -> V_32 * V_10 -> V_31 ) {
V_43 -> V_77 |= V_78 ;
}
}
if ( V_63 & V_79 ) {
V_43 -> V_77 |= V_78 | V_80 ;
F_10 ( V_6 , L_4 ) ;
}
F_32 ( V_6 , V_8 ) ;
}
static int F_33 ( struct V_5 * V_6 , struct V_7 * V_8 )
{
unsigned long V_36 ;
unsigned int V_63 ;
F_34 ( & V_6 -> V_81 , V_36 ) ;
V_63 = F_22 ( V_6 -> V_40 + V_56 ) ;
F_29 ( V_6 , V_63 ) ;
F_35 ( & V_6 -> V_81 , V_36 ) ;
return V_8 -> V_43 -> V_82 - V_8 -> V_43 -> V_83 ;
}
static T_2 F_36 ( int V_84 , void * V_85 )
{
int V_63 ;
struct V_5 * V_6 = V_85 ;
if ( ! V_6 -> V_86 ) {
F_10 ( V_6 , L_5 ) ;
return V_87 ;
}
F_37 ( & V_6 -> V_81 ) ;
V_63 = F_22 ( V_6 -> V_40 + V_56 ) ;
if ( ( V_63 & ( V_64 | V_79 ) ) == 0 ) {
F_10 ( V_6 , L_6 ) ;
F_38 ( & V_6 -> V_81 ) ;
return V_88 ;
}
F_29 ( V_6 , V_63 ) ;
F_15 ( 0 , V_6 -> V_40 + V_57 ) ;
F_38 ( & V_6 -> V_81 ) ;
return V_87 ;
}
static int F_39 ( unsigned int V_84 )
{
switch ( V_84 ) {
case 10 :
return 0x0 ;
case 11 :
return 0x1 ;
case 12 :
return 0x2 ;
case 15 :
return 0x3 ;
case 2 :
return 0x4 ;
case 3 :
return 0x5 ;
case 5 :
return 0x6 ;
case 7 :
return 0x7 ;
default:
return 0x0 ;
}
}
static int F_40 ( struct V_5 * V_6 ,
struct V_89 * V_90 )
{
struct V_11 * V_12 ;
struct V_7 * V_8 ;
int V_66 ;
V_12 = F_41 ( V_6 , sizeof( * V_12 ) ) ;
if ( ! V_12 )
return - V_91 ;
V_66 = F_42 ( V_6 , V_90 -> V_92 [ 0 ] , V_93 ) ;
if ( V_66 )
return V_66 ;
V_66 = F_43 ( V_6 , V_6 -> V_40 + V_94 ,
V_95 ) ;
if ( V_66 )
return V_66 ;
V_12 -> V_96 = V_6 -> V_40 + V_94 ;
if ( ( 1 << V_90 -> V_92 [ 1 ] ) & 0xdcfc ) {
V_66 = F_44 ( V_90 -> V_92 [ 1 ] , F_36 , 0 ,
V_6 -> V_97 , V_6 ) ;
if ( V_66 == 0 )
V_6 -> V_84 = V_90 -> V_92 [ 1 ] ;
}
V_66 = F_45 ( V_6 , 4 ) ;
if ( V_66 )
return V_66 ;
V_8 = & V_6 -> V_98 [ 0 ] ;
V_8 -> type = V_99 ;
V_8 -> V_100 = V_101 | V_102 ;
V_8 -> V_103 = 8 ;
V_8 -> V_104 = ( 1 << 12 ) - 1 ;
V_8 -> V_105 = & V_106 ;
V_8 -> V_107 = F_23 ;
if ( V_6 -> V_84 ) {
V_6 -> V_74 = V_8 ;
V_8 -> V_100 |= V_108 ;
V_8 -> V_109 = 256 ;
V_8 -> V_110 = F_3 ;
V_8 -> V_111 = F_14 ;
V_8 -> V_112 = F_20 ;
V_8 -> V_113 = F_33 ;
}
V_8 = & V_6 -> V_98 [ 1 ] ;
V_8 -> type = V_114 ;
V_8 -> V_100 = V_101 ;
V_8 -> V_103 = 4 ;
V_8 -> V_104 = 1 ;
V_8 -> V_105 = & V_115 ;
V_8 -> V_116 = F_26 ;
V_8 = & V_6 -> V_98 [ 2 ] ;
V_8 -> type = V_117 ;
V_8 -> V_100 = V_118 | V_101 ;
V_8 -> V_103 = 4 ;
V_8 -> V_104 = 1 ;
V_8 -> V_105 = & V_115 ;
V_8 -> V_116 = F_27 ;
V_8 = & V_6 -> V_98 [ 3 ] ;
V_66 = F_46 ( V_6 , V_8 , NULL , V_12 -> V_96 ) ;
if ( V_66 )
return V_66 ;
F_15 ( V_119 , V_6 -> V_40 + V_120 ) ;
F_15 ( 0 , V_6 -> V_40 + V_70 ) ;
V_12 -> V_45 = F_39 ( V_6 -> V_84 ) << 4 ;
F_15 ( V_12 -> V_45 , V_6 -> V_40 + V_48 ) ;
return 0 ;
}
static void F_47 ( struct V_5 * V_6 )
{
struct V_11 * V_12 = V_6 -> V_13 ;
if ( V_12 && V_12 -> V_96 )
F_48 ( V_12 -> V_96 , V_95 ) ;
F_49 ( V_6 ) ;
}
