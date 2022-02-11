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
struct V_7 * V_8 ,
struct V_9 * V_10 )
{
int V_4 ;
if ( V_10 -> V_11 == 1 )
return 0 ;
if ( ( V_10 -> V_11 % 2 ) != 0 ) {
F_4 ( V_6 -> V_12 ,
L_1 ) ;
return - V_13 ;
}
for ( V_4 = 0 ; V_4 < V_10 -> V_11 ; V_4 ++ ) {
unsigned int V_14 = F_5 ( V_10 -> V_15 [ V_4 ] ) ;
if ( ( V_4 % 2 ) != ( V_14 % 2 ) ) {
F_4 ( V_6 -> V_12 ,
L_2 ) ;
return - V_13 ;
}
}
return 0 ;
}
static int F_6 ( struct V_5 * V_6 ,
struct V_7 * V_8 , struct V_9 * V_10 )
{
struct V_16 * V_17 = V_6 -> V_18 ;
int V_19 = 0 ;
unsigned int V_20 ;
V_19 |= F_7 ( & V_10 -> V_21 , V_22 | V_23 ) ;
V_19 |= F_7 ( & V_10 -> V_24 , V_25 ) ;
V_19 |= F_7 ( & V_10 -> V_26 , V_27 | V_23 ) ;
V_19 |= F_7 ( & V_10 -> V_28 , V_29 ) ;
V_19 |= F_7 ( & V_10 -> V_30 , V_29 | V_31 ) ;
if ( V_19 )
return 1 ;
V_19 |= F_8 ( V_10 -> V_21 ) ;
V_19 |= F_8 ( V_10 -> V_26 ) ;
V_19 |= F_8 ( V_10 -> V_30 ) ;
if ( V_19 )
return 2 ;
V_19 |= F_9 ( & V_10 -> V_32 , 0 ) ;
if ( V_10 -> V_24 == V_25 )
V_19 |= F_9 ( & V_10 -> V_33 , 0 ) ;
if ( V_10 -> V_26 == V_27 )
V_19 |= F_10 ( & V_10 -> V_34 , 1000 ) ;
V_19 |= F_9 ( & V_10 -> V_35 , V_10 -> V_11 ) ;
if ( V_10 -> V_30 == V_29 ) {
} else {
V_19 |= F_9 ( & V_10 -> V_36 , 0 ) ;
}
if ( V_19 )
return 3 ;
if ( V_10 -> V_26 == V_27 ) {
V_20 = V_10 -> V_34 ;
F_11 ( V_37 ,
& V_17 -> V_38 ,
& V_17 -> V_39 ,
& V_20 , V_10 -> V_40 ) ;
V_19 |= F_9 ( & V_10 -> V_34 , V_20 ) ;
}
if ( V_19 )
return 4 ;
if ( V_10 -> V_15 && V_10 -> V_11 > 0 )
V_19 |= F_3 ( V_6 , V_8 , V_10 ) ;
if ( V_19 )
return 5 ;
return 0 ;
}
static void F_12 ( struct V_5 * V_6 )
{
struct V_16 * V_17 = V_6 -> V_18 ;
unsigned long V_41 = V_6 -> V_42 + V_43 ;
F_13 ( V_41 , 0 , 1 , V_44 | V_45 ) ;
F_13 ( V_41 , 0 , 2 , V_44 | V_45 ) ;
F_14 ( V_41 , 0 , 1 , V_17 -> V_38 ) ;
F_14 ( V_41 , 0 , 2 , V_17 -> V_39 ) ;
}
static int F_15 ( struct V_5 * V_6 ,
struct V_7 * V_8 )
{
struct V_16 * V_17 = V_6 -> V_18 ;
struct V_46 * V_47 = V_8 -> V_47 ;
struct V_9 * V_10 = & V_47 -> V_10 ;
unsigned long V_41 = V_6 -> V_42 + V_48 ;
unsigned int V_49 , V_4 ;
V_17 -> V_50 &= ~ V_51 & ~ V_52 ;
F_16 ( V_17 -> V_50 , V_6 -> V_42 + V_53 ) ;
V_17 -> V_54 = 0 ;
F_13 ( V_41 , 0 , 1 , V_44 | V_45 ) ;
F_14 ( V_41 , 0 , 1 , 0 ) ;
V_17 -> V_55 = F_17 ( V_41 , 0 , 1 ) ;
for ( V_4 = 0 ; V_4 < V_10 -> V_11 ; V_4 ++ ) {
F_16 ( V_4 , V_6 -> V_42 + V_56 ) ;
V_49 =
F_18 ( F_5 ( V_10 -> V_15 [ V_4 ] ) ) |
F_19 ( F_20 ( V_10 -> V_15 [ V_4 ] ) ) ;
F_16 ( V_49 , V_6 -> V_42 + V_57 ) ;
}
V_17 -> V_50 &= ~ V_52 ;
if ( V_10 -> V_26 == V_27 ) {
F_12 ( V_6 ) ;
V_17 -> V_50 |= V_58 ;
} else {
V_17 -> V_50 |= V_59 ;
}
V_49 = 0 ;
if ( V_10 -> V_21 == V_23 && V_10 -> V_26 != V_23 )
V_49 |= V_60 ;
F_16 ( V_49 , V_6 -> V_42 + V_61 ) ;
F_16 ( 0 , V_6 -> V_42 + V_62 ) ;
V_17 -> V_50 |= V_51 ;
F_16 ( V_17 -> V_50 , V_6 -> V_42 + V_53 ) ;
return 0 ;
}
static int F_21 ( struct V_5 * V_6 , struct V_7 * V_8 )
{
struct V_16 * V_17 = V_6 -> V_18 ;
V_17 -> V_50 &= ~ V_51 & ~ V_52 ;
F_16 ( V_17 -> V_50 , V_6 -> V_42 + V_53 ) ;
return 0 ;
}
static int F_22 ( struct V_5 * V_6 ,
struct V_7 * V_8 ,
struct V_63 * V_64 ,
unsigned long V_65 )
{
unsigned int V_66 ;
V_66 = F_23 ( V_6 -> V_42 + V_61 ) ;
if ( V_66 & V_67 )
return 0 ;
return - V_68 ;
}
static int F_24 ( struct V_5 * V_6 ,
struct V_7 * V_8 ,
struct V_63 * V_64 , unsigned int * V_1 )
{
struct V_16 * V_17 = V_6 -> V_18 ;
int V_69 ;
int V_70 ;
int V_49 ;
V_17 -> V_50 &= ~ V_51 & ~ V_52 ;
F_16 ( V_17 -> V_50 , V_6 -> V_42 + V_53 ) ;
F_16 ( 0 , V_6 -> V_42 + V_56 ) ;
V_49 =
F_18 ( F_5 ( V_64 -> V_71 ) ) | F_19 ( F_20 ( V_64 -> V_71 ) ) ;
F_16 ( V_49 , V_6 -> V_42 + V_57 ) ;
for ( V_70 = 0 ; V_70 < V_64 -> V_70 ; V_70 ++ ) {
F_16 ( 0 , V_6 -> V_42 + V_62 ) ;
F_16 ( 0 , V_6 -> V_42 ) ;
V_69 = F_25 ( V_6 , V_8 , V_64 , F_22 , 0 ) ;
if ( V_69 )
return V_69 ;
V_1 [ V_70 ] = F_1 ( F_26 ( V_6 -> V_42 ) ) ;
}
return V_70 ;
}
static int F_27 ( struct V_5 * V_6 ,
struct V_7 * V_8 ,
struct V_63 * V_64 , unsigned int * V_1 )
{
unsigned int V_72 ;
V_72 = F_23 ( V_6 -> V_42 + V_73 ) & 0xf ;
V_1 [ 1 ] = V_72 ;
V_1 [ 0 ] = 0 ;
return V_64 -> V_70 ;
}
static int F_28 ( struct V_5 * V_6 ,
struct V_7 * V_8 ,
struct V_63 * V_64 ,
unsigned int * V_1 )
{
if ( F_29 ( V_8 , V_1 ) )
F_16 ( V_8 -> V_74 , V_6 -> V_42 + V_73 ) ;
V_1 [ 1 ] = V_8 -> V_74 ;
return V_64 -> V_70 ;
}
static void F_30 ( struct V_5 * V_6 , unsigned int V_66 )
{
struct V_16 * V_17 = V_6 -> V_18 ;
struct V_7 * V_8 ;
struct V_46 * V_47 ;
struct V_9 * V_10 ;
T_1 V_75 ;
T_1 V_76 ;
V_8 = V_6 -> V_77 ;
V_47 = V_8 -> V_47 ;
V_10 = & V_47 -> V_10 ;
V_76 = F_17 ( V_6 -> V_42 + V_48 , 0 , 1 ) ;
if ( V_17 -> V_54 == 0 && V_76 == V_17 -> V_55 ) {
V_75 = 0 ;
} else {
V_75 = - V_76 - V_17 -> V_54 ;
}
if ( V_10 -> V_30 == V_29 ) {
if ( V_75 > V_10 -> V_36 * V_10 -> V_11 )
V_75 = V_10 -> V_36 * V_10 -> V_11 ;
}
if ( V_75 > V_78 )
V_75 = V_78 ;
F_31 ( V_6 -> V_42 , V_17 -> V_79 , V_75 ) ;
F_2 ( V_17 -> V_79 , V_75 ) ;
F_32 ( V_8 , V_17 -> V_79 ,
V_75 * sizeof( short ) ) ;
V_17 -> V_54 += V_75 ;
if ( V_10 -> V_30 == V_29 ) {
if ( V_17 -> V_54 >= V_10 -> V_36 * V_10 -> V_11 ) {
V_47 -> V_80 |= V_81 ;
}
}
if ( V_66 & V_82 ) {
V_47 -> V_80 |= V_81 | V_83 ;
F_33 ( V_6 , L_3 ) ;
}
F_34 ( V_6 , V_8 ) ;
}
static int F_35 ( struct V_5 * V_6 , struct V_7 * V_8 )
{
unsigned long V_40 ;
unsigned int V_66 ;
F_36 ( & V_6 -> V_84 , V_40 ) ;
V_66 = F_23 ( V_6 -> V_42 + V_61 ) ;
F_30 ( V_6 , V_66 ) ;
F_37 ( & V_6 -> V_84 , V_40 ) ;
return V_8 -> V_47 -> V_85 - V_8 -> V_47 -> V_86 ;
}
static T_2 F_38 ( int V_87 , void * V_88 )
{
int V_66 ;
struct V_5 * V_6 = V_88 ;
if ( ! V_6 -> V_89 ) {
F_33 ( V_6 , L_4 ) ;
return V_90 ;
}
F_39 ( & V_6 -> V_84 ) ;
V_66 = F_23 ( V_6 -> V_42 + V_61 ) ;
if ( ( V_66 & ( V_67 | V_82 ) ) == 0 ) {
F_33 ( V_6 , L_5 ) ;
F_40 ( & V_6 -> V_84 ) ;
return V_91 ;
}
F_30 ( V_6 , V_66 ) ;
F_16 ( 0 , V_6 -> V_42 + V_62 ) ;
F_40 ( & V_6 -> V_84 ) ;
return V_90 ;
}
static int F_41 ( unsigned int V_87 )
{
switch ( V_87 ) {
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
static int F_42 ( struct V_5 * V_6 ,
struct V_92 * V_93 )
{
struct V_16 * V_17 ;
struct V_7 * V_8 ;
int V_69 ;
V_17 = F_43 ( V_6 , sizeof( * V_17 ) ) ;
if ( ! V_17 )
return - V_94 ;
V_69 = F_44 ( V_6 , V_93 -> V_95 [ 0 ] , V_96 ) ;
if ( V_69 )
return V_69 ;
V_69 = F_45 ( V_6 , V_6 -> V_42 + V_97 ,
V_98 ) ;
if ( V_69 )
return V_69 ;
V_17 -> V_99 = V_6 -> V_42 + V_97 ;
if ( ( 1 << V_93 -> V_95 [ 1 ] ) & 0xdcfc ) {
V_69 = F_46 ( V_93 -> V_95 [ 1 ] , F_38 , 0 ,
V_6 -> V_100 , V_6 ) ;
if ( V_69 == 0 )
V_6 -> V_87 = V_93 -> V_95 [ 1 ] ;
}
V_69 = F_47 ( V_6 , 4 ) ;
if ( V_69 )
return V_69 ;
V_8 = & V_6 -> V_101 [ 0 ] ;
V_8 -> type = V_102 ;
V_8 -> V_103 = V_104 | V_105 ;
V_8 -> V_106 = 8 ;
V_8 -> V_107 = ( 1 << 12 ) - 1 ;
V_8 -> V_108 = & V_109 ;
V_8 -> V_110 = F_24 ;
if ( V_6 -> V_87 ) {
V_6 -> V_77 = V_8 ;
V_8 -> V_103 |= V_111 ;
V_8 -> V_112 = 256 ;
V_8 -> V_113 = F_6 ;
V_8 -> V_114 = F_15 ;
V_8 -> V_115 = F_21 ;
V_8 -> V_116 = F_35 ;
}
V_8 = & V_6 -> V_101 [ 1 ] ;
V_8 -> type = V_117 ;
V_8 -> V_103 = V_104 ;
V_8 -> V_106 = 4 ;
V_8 -> V_107 = 1 ;
V_8 -> V_108 = & V_118 ;
V_8 -> V_119 = F_27 ;
V_8 = & V_6 -> V_101 [ 2 ] ;
V_8 -> type = V_120 ;
V_8 -> V_103 = V_121 | V_104 ;
V_8 -> V_106 = 4 ;
V_8 -> V_107 = 1 ;
V_8 -> V_108 = & V_118 ;
V_8 -> V_119 = F_28 ;
V_8 = & V_6 -> V_101 [ 3 ] ;
V_69 = F_48 ( V_6 , V_8 , NULL , V_17 -> V_99 ) ;
if ( V_69 )
return V_69 ;
F_16 ( V_122 , V_6 -> V_42 + V_123 ) ;
F_16 ( 0 , V_6 -> V_42 + V_73 ) ;
V_17 -> V_50 = F_41 ( V_6 -> V_87 ) << 4 ;
F_16 ( V_17 -> V_50 , V_6 -> V_42 + V_53 ) ;
return 0 ;
}
static void F_49 ( struct V_5 * V_6 )
{
struct V_16 * V_17 = V_6 -> V_18 ;
if ( V_17 && V_17 -> V_99 )
F_50 ( V_17 -> V_99 , V_98 ) ;
F_51 ( V_6 ) ;
}
