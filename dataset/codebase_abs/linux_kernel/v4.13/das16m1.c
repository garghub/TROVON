static void F_1 ( struct V_1 * V_2 ,
unsigned int * V_3 , unsigned int V_4 )
{
unsigned int V_5 ;
for ( V_5 = 0 ; V_5 < V_4 ; V_5 ++ ) {
unsigned int V_6 = F_2 ( V_3 [ V_5 ] ) ;
unsigned int V_7 = F_3 ( V_3 [ V_5 ] ) ;
F_4 ( V_5 , V_2 -> V_8 + V_9 ) ;
F_4 ( F_5 ( V_6 ) | F_6 ( V_7 ) ,
V_2 -> V_8 + V_10 ) ;
}
}
static void F_7 ( struct V_1 * V_2 ,
struct V_11 * V_12 ,
void * V_13 , unsigned int V_14 ,
unsigned int V_15 )
{
unsigned short * V_16 = V_13 ;
unsigned int V_17 = F_8 ( V_12 , V_14 ) ;
unsigned int V_5 ;
for ( V_5 = 0 ; V_5 < V_17 ; V_5 ++ )
V_16 [ V_5 ] = F_9 ( V_16 [ V_5 ] ) ;
}
static int F_10 ( struct V_1 * V_2 ,
struct V_11 * V_12 ,
struct V_18 * V_19 )
{
int V_5 ;
if ( V_19 -> V_20 == 1 )
return 0 ;
if ( ( V_19 -> V_20 % 2 ) != 0 ) {
F_11 ( V_2 -> V_21 ,
L_1 ) ;
return - V_22 ;
}
for ( V_5 = 0 ; V_5 < V_19 -> V_20 ; V_5 ++ ) {
unsigned int V_6 = F_2 ( V_19 -> V_23 [ V_5 ] ) ;
if ( ( V_5 % 2 ) != ( V_6 % 2 ) ) {
F_11 ( V_2 -> V_21 ,
L_2 ) ;
return - V_22 ;
}
}
return 0 ;
}
static int F_12 ( struct V_1 * V_2 ,
struct V_11 * V_12 ,
struct V_18 * V_19 )
{
int V_24 = 0 ;
V_24 |= F_13 ( & V_19 -> V_25 , V_26 | V_27 ) ;
V_24 |= F_13 ( & V_19 -> V_28 , V_29 ) ;
V_24 |= F_13 ( & V_19 -> V_30 ,
V_31 | V_27 ) ;
V_24 |= F_13 ( & V_19 -> V_32 , V_33 ) ;
V_24 |= F_13 ( & V_19 -> V_34 , V_33 | V_35 ) ;
if ( V_24 )
return 1 ;
V_24 |= F_14 ( V_19 -> V_25 ) ;
V_24 |= F_14 ( V_19 -> V_30 ) ;
V_24 |= F_14 ( V_19 -> V_34 ) ;
if ( V_24 )
return 2 ;
V_24 |= F_15 ( & V_19 -> V_36 , 0 ) ;
if ( V_19 -> V_28 == V_29 )
V_24 |= F_15 ( & V_19 -> V_37 , 0 ) ;
if ( V_19 -> V_30 == V_31 )
V_24 |= F_16 ( & V_19 -> V_38 , 1000 ) ;
V_24 |= F_15 ( & V_19 -> V_39 ,
V_19 -> V_20 ) ;
if ( V_19 -> V_34 == V_33 )
V_24 |= F_16 ( & V_19 -> V_40 , 1 ) ;
else
V_24 |= F_15 ( & V_19 -> V_40 , 0 ) ;
if ( V_24 )
return 3 ;
if ( V_19 -> V_30 == V_31 ) {
unsigned int V_41 = V_19 -> V_38 ;
F_17 ( V_2 -> V_42 , & V_41 , V_19 -> V_43 ) ;
V_24 |= F_15 ( & V_19 -> V_38 , V_41 ) ;
}
if ( V_24 )
return 4 ;
if ( V_19 -> V_23 && V_19 -> V_20 > 0 )
V_24 |= F_10 ( V_2 , V_12 , V_19 ) ;
if ( V_24 )
return 5 ;
return 0 ;
}
static int F_18 ( struct V_1 * V_2 ,
struct V_11 * V_12 )
{
struct V_44 * V_45 = V_2 -> V_46 ;
struct V_47 * V_48 = V_12 -> V_48 ;
struct V_18 * V_19 = & V_48 -> V_19 ;
unsigned int V_49 ;
V_45 -> V_50 = 0 ;
F_19 ( V_45 -> V_51 , 1 , V_52 | V_53 ) ;
F_20 ( V_45 -> V_51 , 1 , 0 ) ;
V_45 -> V_54 = F_21 ( V_45 -> V_51 , 1 ) ;
F_1 ( V_2 , V_19 -> V_23 , V_19 -> V_20 ) ;
V_45 -> V_55 &= ~ V_56 ;
if ( V_19 -> V_30 == V_31 ) {
F_22 ( V_2 -> V_42 ) ;
F_23 ( V_2 -> V_42 , 1 , 2 , true ) ;
V_45 -> V_55 |= V_57 ;
} else {
V_45 -> V_55 |= V_58 ;
}
V_49 = 0 ;
if ( V_19 -> V_25 == V_27 && V_19 -> V_30 != V_27 )
V_49 |= V_59 ;
F_4 ( V_49 , V_2 -> V_8 + V_60 ) ;
F_4 ( 0 , V_2 -> V_8 + V_61 ) ;
V_45 -> V_55 |= V_62 ;
F_4 ( V_45 -> V_55 , V_2 -> V_8 + V_63 ) ;
return 0 ;
}
static int F_24 ( struct V_1 * V_2 ,
struct V_11 * V_12 )
{
struct V_44 * V_45 = V_2 -> V_46 ;
V_45 -> V_55 &= ~ ( V_62 |
V_56 ) ;
F_4 ( V_45 -> V_55 , V_2 -> V_8 + V_63 ) ;
return 0 ;
}
static int F_25 ( struct V_1 * V_2 ,
struct V_11 * V_12 ,
struct V_64 * V_65 ,
unsigned long V_66 )
{
unsigned int V_67 ;
V_67 = F_26 ( V_2 -> V_8 + V_60 ) ;
if ( V_67 & V_68 )
return 0 ;
return - V_69 ;
}
static int F_27 ( struct V_1 * V_2 ,
struct V_11 * V_12 ,
struct V_64 * V_65 ,
unsigned int * V_13 )
{
int V_70 ;
int V_5 ;
F_1 ( V_2 , & V_65 -> V_3 , 1 ) ;
for ( V_5 = 0 ; V_5 < V_65 -> V_71 ; V_5 ++ ) {
unsigned short V_72 ;
F_4 ( 0 , V_2 -> V_8 + V_61 ) ;
F_4 ( 0 , V_2 -> V_8 + V_73 ) ;
V_70 = F_28 ( V_2 , V_12 , V_65 , F_25 , 0 ) ;
if ( V_70 )
return V_70 ;
V_72 = F_29 ( V_2 -> V_8 + V_73 ) ;
V_13 [ V_5 ] = F_9 ( V_72 ) ;
}
return V_65 -> V_71 ;
}
static int F_30 ( struct V_1 * V_2 ,
struct V_11 * V_12 ,
struct V_64 * V_65 ,
unsigned int * V_13 )
{
V_13 [ 1 ] = F_26 ( V_2 -> V_8 + V_74 ) & 0xf ;
return V_65 -> V_71 ;
}
static int F_31 ( struct V_1 * V_2 ,
struct V_11 * V_12 ,
struct V_64 * V_65 ,
unsigned int * V_13 )
{
if ( F_32 ( V_12 , V_13 ) )
F_4 ( V_12 -> V_75 , V_2 -> V_8 + V_76 ) ;
V_13 [ 1 ] = V_12 -> V_75 ;
return V_65 -> V_71 ;
}
static void F_33 ( struct V_1 * V_2 , unsigned int V_67 )
{
struct V_44 * V_45 = V_2 -> V_46 ;
struct V_11 * V_12 = V_2 -> V_77 ;
struct V_47 * V_48 = V_12 -> V_48 ;
struct V_18 * V_19 = & V_48 -> V_19 ;
T_1 V_78 ;
T_1 V_79 ;
V_79 = F_21 ( V_45 -> V_51 , 1 ) ;
if ( V_45 -> V_50 == 0 &&
V_79 == V_45 -> V_54 ) {
V_78 = 0 ;
} else {
V_78 = - V_79 - V_45 -> V_50 ;
}
if ( V_19 -> V_34 == V_33 ) {
if ( V_78 > V_19 -> V_40 * V_19 -> V_20 )
V_78 = V_19 -> V_40 * V_19 -> V_20 ;
}
if ( V_78 > V_80 )
V_78 = V_80 ;
F_34 ( V_2 -> V_8 , V_45 -> V_81 , V_78 ) ;
F_35 ( V_12 , V_45 -> V_81 , V_78 ) ;
V_45 -> V_50 += V_78 ;
if ( V_19 -> V_34 == V_33 ) {
if ( V_45 -> V_50 >= V_19 -> V_40 * V_19 -> V_20 ) {
V_48 -> V_82 |= V_83 ;
}
}
if ( V_67 & V_84 ) {
V_48 -> V_82 |= V_85 ;
F_36 ( V_2 -> V_21 , L_3 ) ;
}
F_37 ( V_2 , V_12 ) ;
}
static int F_38 ( struct V_1 * V_2 ,
struct V_11 * V_12 )
{
unsigned long V_43 ;
unsigned int V_67 ;
F_39 ( & V_2 -> V_86 , V_43 ) ;
V_67 = F_26 ( V_2 -> V_8 + V_60 ) ;
F_33 ( V_2 , V_67 ) ;
F_40 ( & V_2 -> V_86 , V_43 ) ;
return F_41 ( V_12 ) ;
}
static T_2 F_42 ( int V_87 , void * V_88 )
{
int V_67 ;
struct V_1 * V_2 = V_88 ;
if ( ! V_2 -> V_89 ) {
F_36 ( V_2 -> V_21 , L_4 ) ;
return V_90 ;
}
F_43 ( & V_2 -> V_86 ) ;
V_67 = F_26 ( V_2 -> V_8 + V_60 ) ;
if ( ( V_67 & ( V_68 | V_84 ) ) == 0 ) {
F_36 ( V_2 -> V_21 , L_5 ) ;
F_44 ( & V_2 -> V_86 ) ;
return V_91 ;
}
F_33 ( V_2 , V_67 ) ;
F_4 ( 0 , V_2 -> V_8 + V_61 ) ;
F_44 ( & V_2 -> V_86 ) ;
return V_90 ;
}
static int F_45 ( unsigned int V_87 )
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
static int F_46 ( struct V_1 * V_2 ,
struct V_92 * V_93 )
{
struct V_44 * V_45 ;
struct V_11 * V_12 ;
int V_70 ;
V_45 = F_47 ( V_2 , sizeof( * V_45 ) ) ;
if ( ! V_45 )
return - V_94 ;
V_70 = F_48 ( V_2 , V_93 -> V_95 [ 0 ] , 0x10 ) ;
if ( V_70 )
return V_70 ;
V_70 = F_49 ( V_2 , V_2 -> V_8 + V_96 ,
V_97 ) ;
if ( V_70 )
return V_70 ;
V_45 -> V_98 = V_2 -> V_8 + V_96 ;
if ( ( 1 << V_93 -> V_95 [ 1 ] ) & 0xdcfc ) {
V_70 = F_50 ( V_93 -> V_95 [ 1 ] , F_42 , 0 ,
V_2 -> V_99 , V_2 ) ;
if ( V_70 == 0 )
V_2 -> V_87 = V_93 -> V_95 [ 1 ] ;
}
V_2 -> V_42 = F_51 ( V_2 -> V_8 + V_100 ,
V_101 , V_102 , 0 ) ;
if ( ! V_2 -> V_42 )
return - V_94 ;
V_45 -> V_51 = F_51 ( V_2 -> V_8 + V_103 ,
0 , V_102 , 0 ) ;
if ( ! V_45 -> V_51 )
return - V_94 ;
V_70 = F_52 ( V_2 , 4 ) ;
if ( V_70 )
return V_70 ;
V_12 = & V_2 -> V_104 [ 0 ] ;
V_12 -> type = V_105 ;
V_12 -> V_106 = V_107 | V_108 ;
V_12 -> V_109 = 8 ;
V_12 -> V_110 = 0x0fff ;
V_12 -> V_111 = & V_112 ;
V_12 -> V_113 = F_27 ;
if ( V_2 -> V_87 ) {
V_2 -> V_77 = V_12 ;
V_12 -> V_106 |= V_114 ;
V_12 -> V_115 = 256 ;
V_12 -> V_116 = F_12 ;
V_12 -> V_117 = F_18 ;
V_12 -> V_118 = F_24 ;
V_12 -> V_119 = F_38 ;
V_12 -> V_120 = F_7 ;
}
V_12 = & V_2 -> V_104 [ 1 ] ;
V_12 -> type = V_121 ;
V_12 -> V_106 = V_107 ;
V_12 -> V_109 = 4 ;
V_12 -> V_110 = 1 ;
V_12 -> V_111 = & V_122 ;
V_12 -> V_123 = F_30 ;
V_12 = & V_2 -> V_104 [ 2 ] ;
V_12 -> type = V_124 ;
V_12 -> V_106 = V_125 ;
V_12 -> V_109 = 4 ;
V_12 -> V_110 = 1 ;
V_12 -> V_111 = & V_122 ;
V_12 -> V_123 = F_31 ;
V_12 = & V_2 -> V_104 [ 3 ] ;
V_70 = F_53 ( V_2 , V_12 , NULL , V_96 ) ;
if ( V_70 )
return V_70 ;
F_4 ( 0 , V_2 -> V_8 + V_76 ) ;
V_45 -> V_55 = F_54 ( F_45 ( V_2 -> V_87 ) ) ;
F_4 ( V_45 -> V_55 , V_2 -> V_8 + V_63 ) ;
return 0 ;
}
static void F_55 ( struct V_1 * V_2 )
{
struct V_44 * V_45 = V_2 -> V_46 ;
if ( V_45 ) {
if ( V_45 -> V_98 )
F_56 ( V_45 -> V_98 , V_97 ) ;
F_57 ( V_45 -> V_51 ) ;
}
F_58 ( V_2 ) ;
}
