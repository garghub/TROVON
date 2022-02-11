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
int V_16 = 0 ;
V_16 |= F_7 ( & V_10 -> V_17 , V_18 | V_19 ) ;
V_16 |= F_7 ( & V_10 -> V_20 , V_21 ) ;
V_16 |= F_7 ( & V_10 -> V_22 ,
V_23 | V_19 ) ;
V_16 |= F_7 ( & V_10 -> V_24 , V_25 ) ;
V_16 |= F_7 ( & V_10 -> V_26 , V_25 | V_27 ) ;
if ( V_16 )
return 1 ;
V_16 |= F_8 ( V_10 -> V_17 ) ;
V_16 |= F_8 ( V_10 -> V_22 ) ;
V_16 |= F_8 ( V_10 -> V_26 ) ;
if ( V_16 )
return 2 ;
V_16 |= F_9 ( & V_10 -> V_28 , 0 ) ;
if ( V_10 -> V_20 == V_21 )
V_16 |= F_9 ( & V_10 -> V_29 , 0 ) ;
if ( V_10 -> V_22 == V_23 )
V_16 |= F_10 ( & V_10 -> V_30 , 1000 ) ;
V_16 |= F_9 ( & V_10 -> V_31 ,
V_10 -> V_11 ) ;
if ( V_10 -> V_26 == V_25 )
V_16 |= F_10 ( & V_10 -> V_32 , 1 ) ;
else
V_16 |= F_9 ( & V_10 -> V_32 , 0 ) ;
if ( V_16 )
return 3 ;
if ( V_10 -> V_22 == V_23 ) {
unsigned int V_33 = V_10 -> V_30 ;
F_11 ( V_6 -> V_34 , & V_33 , V_10 -> V_35 ) ;
V_16 |= F_9 ( & V_10 -> V_30 , V_33 ) ;
}
if ( V_16 )
return 4 ;
if ( V_10 -> V_15 && V_10 -> V_11 > 0 )
V_16 |= F_3 ( V_6 , V_8 , V_10 ) ;
if ( V_16 )
return 5 ;
return 0 ;
}
static int F_12 ( struct V_5 * V_6 ,
struct V_7 * V_8 )
{
struct V_36 * V_37 = V_6 -> V_38 ;
struct V_39 * V_40 = V_8 -> V_40 ;
struct V_9 * V_10 = & V_40 -> V_10 ;
unsigned int V_41 , V_4 ;
V_37 -> V_42 &= ~ V_43 & ~ V_44 ;
F_13 ( V_37 -> V_42 , V_6 -> V_45 + V_46 ) ;
V_37 -> V_47 = 0 ;
F_14 ( V_37 -> V_48 , 1 , V_49 | V_50 ) ;
F_15 ( V_37 -> V_48 , 1 , 0 ) ;
V_37 -> V_51 = F_16 ( V_37 -> V_48 , 1 ) ;
for ( V_4 = 0 ; V_4 < V_10 -> V_11 ; V_4 ++ ) {
F_13 ( V_4 , V_6 -> V_45 + V_52 ) ;
V_41 =
F_17 ( F_5 ( V_10 -> V_15 [ V_4 ] ) ) |
F_18 ( F_19 ( V_10 -> V_15 [ V_4 ] ) ) ;
F_13 ( V_41 , V_6 -> V_45 + V_53 ) ;
}
V_37 -> V_42 &= ~ V_44 ;
if ( V_10 -> V_22 == V_23 ) {
F_20 ( V_6 -> V_34 ) ;
F_21 ( V_6 -> V_34 , 1 , 2 , true ) ;
V_37 -> V_42 |= V_54 ;
} else {
V_37 -> V_42 |= V_55 ;
}
V_41 = 0 ;
if ( V_10 -> V_17 == V_19 && V_10 -> V_22 != V_19 )
V_41 |= V_56 ;
F_13 ( V_41 , V_6 -> V_45 + V_57 ) ;
F_13 ( 0 , V_6 -> V_45 + V_58 ) ;
V_37 -> V_42 |= V_43 ;
F_13 ( V_37 -> V_42 , V_6 -> V_45 + V_46 ) ;
return 0 ;
}
static int F_22 ( struct V_5 * V_6 , struct V_7 * V_8 )
{
struct V_36 * V_37 = V_6 -> V_38 ;
V_37 -> V_42 &= ~ V_43 & ~ V_44 ;
F_13 ( V_37 -> V_42 , V_6 -> V_45 + V_46 ) ;
return 0 ;
}
static int F_23 ( struct V_5 * V_6 ,
struct V_7 * V_8 ,
struct V_59 * V_60 ,
unsigned long V_61 )
{
unsigned int V_62 ;
V_62 = F_24 ( V_6 -> V_45 + V_57 ) ;
if ( V_62 & V_63 )
return 0 ;
return - V_64 ;
}
static int F_25 ( struct V_5 * V_6 ,
struct V_7 * V_8 ,
struct V_59 * V_60 , unsigned int * V_1 )
{
struct V_36 * V_37 = V_6 -> V_38 ;
int V_65 ;
int V_66 ;
int V_41 ;
V_37 -> V_42 &= ~ V_43 & ~ V_44 ;
F_13 ( V_37 -> V_42 , V_6 -> V_45 + V_46 ) ;
F_13 ( 0 , V_6 -> V_45 + V_52 ) ;
V_41 =
F_17 ( F_5 ( V_60 -> V_67 ) ) | F_18 ( F_19 ( V_60 -> V_67 ) ) ;
F_13 ( V_41 , V_6 -> V_45 + V_53 ) ;
for ( V_66 = 0 ; V_66 < V_60 -> V_66 ; V_66 ++ ) {
F_13 ( 0 , V_6 -> V_45 + V_58 ) ;
F_13 ( 0 , V_6 -> V_45 ) ;
V_65 = F_26 ( V_6 , V_8 , V_60 , F_23 , 0 ) ;
if ( V_65 )
return V_65 ;
V_1 [ V_66 ] = F_1 ( F_27 ( V_6 -> V_45 ) ) ;
}
return V_66 ;
}
static int F_28 ( struct V_5 * V_6 ,
struct V_7 * V_8 ,
struct V_59 * V_60 , unsigned int * V_1 )
{
unsigned int V_68 ;
V_68 = F_24 ( V_6 -> V_45 + V_69 ) & 0xf ;
V_1 [ 1 ] = V_68 ;
V_1 [ 0 ] = 0 ;
return V_60 -> V_66 ;
}
static int F_29 ( struct V_5 * V_6 ,
struct V_7 * V_8 ,
struct V_59 * V_60 ,
unsigned int * V_1 )
{
if ( F_30 ( V_8 , V_1 ) )
F_13 ( V_8 -> V_70 , V_6 -> V_45 + V_69 ) ;
V_1 [ 1 ] = V_8 -> V_70 ;
return V_60 -> V_66 ;
}
static void F_31 ( struct V_5 * V_6 , unsigned int V_62 )
{
struct V_36 * V_37 = V_6 -> V_38 ;
struct V_7 * V_8 ;
struct V_39 * V_40 ;
struct V_9 * V_10 ;
T_1 V_71 ;
T_1 V_72 ;
V_8 = V_6 -> V_73 ;
V_40 = V_8 -> V_40 ;
V_10 = & V_40 -> V_10 ;
V_72 = F_16 ( V_37 -> V_48 , 1 ) ;
if ( V_37 -> V_47 == 0 && V_72 == V_37 -> V_51 ) {
V_71 = 0 ;
} else {
V_71 = - V_72 - V_37 -> V_47 ;
}
if ( V_10 -> V_26 == V_25 ) {
if ( V_71 > V_10 -> V_32 * V_10 -> V_11 )
V_71 = V_10 -> V_32 * V_10 -> V_11 ;
}
if ( V_71 > V_74 )
V_71 = V_74 ;
F_32 ( V_6 -> V_45 , V_37 -> V_75 , V_71 ) ;
F_2 ( V_37 -> V_75 , V_71 ) ;
F_33 ( V_8 , V_37 -> V_75 , V_71 ) ;
V_37 -> V_47 += V_71 ;
if ( V_10 -> V_26 == V_25 ) {
if ( V_37 -> V_47 >= V_10 -> V_32 * V_10 -> V_11 ) {
V_40 -> V_76 |= V_77 ;
}
}
if ( V_62 & V_78 ) {
V_40 -> V_76 |= V_79 ;
F_34 ( V_6 -> V_12 , L_3 ) ;
}
F_35 ( V_6 , V_8 ) ;
}
static int F_36 ( struct V_5 * V_6 , struct V_7 * V_8 )
{
unsigned long V_35 ;
unsigned int V_62 ;
F_37 ( & V_6 -> V_80 , V_35 ) ;
V_62 = F_24 ( V_6 -> V_45 + V_57 ) ;
F_31 ( V_6 , V_62 ) ;
F_38 ( & V_6 -> V_80 , V_35 ) ;
return F_39 ( V_8 ) ;
}
static T_2 F_40 ( int V_81 , void * V_82 )
{
int V_62 ;
struct V_5 * V_6 = V_82 ;
if ( ! V_6 -> V_83 ) {
F_34 ( V_6 -> V_12 , L_4 ) ;
return V_84 ;
}
F_41 ( & V_6 -> V_80 ) ;
V_62 = F_24 ( V_6 -> V_45 + V_57 ) ;
if ( ( V_62 & ( V_63 | V_78 ) ) == 0 ) {
F_34 ( V_6 -> V_12 , L_5 ) ;
F_42 ( & V_6 -> V_80 ) ;
return V_85 ;
}
F_31 ( V_6 , V_62 ) ;
F_13 ( 0 , V_6 -> V_45 + V_58 ) ;
F_42 ( & V_6 -> V_80 ) ;
return V_84 ;
}
static int F_43 ( unsigned int V_81 )
{
switch ( V_81 ) {
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
static int F_44 ( struct V_5 * V_6 ,
struct V_86 * V_87 )
{
struct V_36 * V_37 ;
struct V_7 * V_8 ;
int V_65 ;
V_37 = F_45 ( V_6 , sizeof( * V_37 ) ) ;
if ( ! V_37 )
return - V_88 ;
V_65 = F_46 ( V_6 , V_87 -> V_89 [ 0 ] , 0x10 ) ;
if ( V_65 )
return V_65 ;
V_65 = F_47 ( V_6 , V_6 -> V_45 + V_90 ,
V_91 ) ;
if ( V_65 )
return V_65 ;
V_37 -> V_92 = V_6 -> V_45 + V_90 ;
if ( ( 1 << V_87 -> V_89 [ 1 ] ) & 0xdcfc ) {
V_65 = F_48 ( V_87 -> V_89 [ 1 ] , F_40 , 0 ,
V_6 -> V_93 , V_6 ) ;
if ( V_65 == 0 )
V_6 -> V_81 = V_87 -> V_89 [ 1 ] ;
}
V_6 -> V_34 = F_49 ( V_6 -> V_45 + V_94 ,
V_95 , V_96 , 0 ) ;
if ( ! V_6 -> V_34 )
return - V_88 ;
V_37 -> V_48 = F_49 ( V_6 -> V_45 + V_97 ,
0 , V_96 , 0 ) ;
if ( ! V_37 -> V_48 )
return - V_88 ;
V_65 = F_50 ( V_6 , 4 ) ;
if ( V_65 )
return V_65 ;
V_8 = & V_6 -> V_98 [ 0 ] ;
V_8 -> type = V_99 ;
V_8 -> V_100 = V_101 | V_102 ;
V_8 -> V_103 = 8 ;
V_8 -> V_104 = ( 1 << 12 ) - 1 ;
V_8 -> V_105 = & V_106 ;
V_8 -> V_107 = F_25 ;
if ( V_6 -> V_81 ) {
V_6 -> V_73 = V_8 ;
V_8 -> V_100 |= V_108 ;
V_8 -> V_109 = 256 ;
V_8 -> V_110 = F_6 ;
V_8 -> V_111 = F_12 ;
V_8 -> V_112 = F_22 ;
V_8 -> V_113 = F_36 ;
}
V_8 = & V_6 -> V_98 [ 1 ] ;
V_8 -> type = V_114 ;
V_8 -> V_100 = V_101 ;
V_8 -> V_103 = 4 ;
V_8 -> V_104 = 1 ;
V_8 -> V_105 = & V_115 ;
V_8 -> V_116 = F_28 ;
V_8 = & V_6 -> V_98 [ 2 ] ;
V_8 -> type = V_117 ;
V_8 -> V_100 = V_118 ;
V_8 -> V_103 = 4 ;
V_8 -> V_104 = 1 ;
V_8 -> V_105 = & V_115 ;
V_8 -> V_116 = F_29 ;
V_8 = & V_6 -> V_98 [ 3 ] ;
V_65 = F_51 ( V_6 , V_8 , NULL , V_90 ) ;
if ( V_65 )
return V_65 ;
F_13 ( 0 , V_6 -> V_45 + V_69 ) ;
V_37 -> V_42 = F_43 ( V_6 -> V_81 ) << 4 ;
F_13 ( V_37 -> V_42 , V_6 -> V_45 + V_46 ) ;
return 0 ;
}
static void F_52 ( struct V_5 * V_6 )
{
struct V_36 * V_37 = V_6 -> V_38 ;
if ( V_37 ) {
if ( V_37 -> V_92 )
F_53 ( V_37 -> V_92 , V_91 ) ;
F_54 ( V_37 -> V_48 ) ;
}
F_55 ( V_6 ) ;
}
