static void F_1 ( struct V_1 * V_2 ,
unsigned int V_3 )
{
F_2 ( V_4 | V_3 , V_2 -> V_5 + V_6 ) ;
}
static void F_3 ( struct V_1 * V_2 ,
unsigned int V_7 )
{
F_2 ( V_8 , V_2 -> V_5 + V_9 ) ;
F_2 ( V_8 | V_7 , V_2 -> V_5 + V_9 ) ;
F_2 ( V_7 , V_2 -> V_5 + V_9 ) ;
}
static void F_4 ( struct V_1 * V_2 )
{
F_2 ( V_10 |
V_11 |
V_12 , V_2 -> V_5 + V_9 ) ;
}
static void F_5 ( struct V_1 * V_2 )
{
F_2 ( V_10 , V_2 -> V_5 + V_9 ) ;
}
static unsigned int F_6 ( struct V_1 * V_2 ,
struct V_13 * V_14 )
{
unsigned int V_7 ;
V_7 = F_7 ( V_2 -> V_5 + V_15 ) ;
if ( V_14 -> V_16 == 0x0fff )
V_7 >>= 4 ;
return V_7 ;
}
static T_1 F_8 ( int V_17 , void * V_18 )
{
struct V_1 * V_2 = V_18 ;
struct V_13 * V_14 = V_2 -> V_19 ;
struct V_20 * V_21 = V_14 -> V_21 ;
struct V_22 * V_23 = & V_21 -> V_23 ;
unsigned int V_24 ;
V_24 = F_9 ( V_2 -> V_5 + V_9 ) ;
if ( ( V_24 & V_25 ) == 0 )
return V_26 ;
if ( V_24 & V_27 ) {
V_21 -> V_28 |= V_29 ;
} else if ( V_24 & V_30 ) {
unsigned int V_7 ;
V_7 = F_6 ( V_2 , V_14 ) ;
F_10 ( V_14 , & V_7 , 1 ) ;
if ( V_23 -> V_31 == V_32 &&
V_21 -> V_33 >= V_23 -> V_34 )
V_21 -> V_28 |= V_35 ;
}
F_4 ( V_2 ) ;
F_11 ( V_2 , V_14 ) ;
return V_36 ;
}
static void F_12 ( struct V_1 * V_2 ,
struct V_13 * V_14 ,
unsigned int V_37 ,
unsigned int V_3 )
{
unsigned int V_38 = F_13 ( V_37 ) ;
unsigned int V_39 = F_14 ( V_37 ) ;
V_3 |= F_15 ( V_38 ) ;
if ( V_39 == V_40 )
V_3 |= V_41 ;
if ( F_16 ( V_14 , V_38 ) )
V_3 |= V_42 ;
F_1 ( V_2 , V_3 ) ;
}
static int F_17 ( struct V_1 * V_2 ,
struct V_13 * V_14 )
{
struct V_43 * V_44 = V_2 -> V_45 ;
struct V_22 * V_23 = & V_14 -> V_21 -> V_23 ;
unsigned int V_46 = F_18 ( V_23 -> V_47 [ 0 ] ) ;
unsigned int V_48 = F_18 ( V_23 -> V_47 [ V_23 -> V_49 - 1 ] ) ;
F_12 ( V_2 , V_14 , V_23 -> V_47 [ 0 ] , V_50 ) ;
F_19 ( F_20 ( V_48 ) | F_21 ( V_46 ) ,
V_2 -> V_5 + V_51 ) ;
F_22 ( V_2 -> V_52 ) ;
F_23 ( V_2 -> V_52 , 1 , 2 , true ) ;
F_2 ( V_53 |
F_24 ( V_44 -> V_17 ) |
V_54 , V_2 -> V_5 + V_55 ) ;
return 0 ;
}
static int F_25 ( struct V_1 * V_2 ,
struct V_13 * V_14 ,
struct V_22 * V_23 )
{
unsigned int V_56 = F_18 ( V_23 -> V_47 [ 0 ] ) ;
unsigned int V_57 = F_13 ( V_23 -> V_47 [ 0 ] ) ;
unsigned int V_58 = F_14 ( V_23 -> V_47 [ 0 ] ) ;
int V_59 ;
for ( V_59 = 1 ; V_59 < V_23 -> V_49 ; V_59 ++ ) {
unsigned int V_60 = F_18 ( V_23 -> V_47 [ V_59 ] ) ;
unsigned int V_38 = F_13 ( V_23 -> V_47 [ V_59 ] ) ;
unsigned int V_39 = F_14 ( V_23 -> V_47 [ V_59 ] ) ;
if ( V_60 != V_56 + V_59 ) {
F_26 ( V_2 -> V_61 ,
L_1 ) ;
return - V_62 ;
}
if ( V_38 != V_57 ) {
F_26 ( V_2 -> V_61 ,
L_2 ) ;
return - V_62 ;
}
if ( V_39 != V_58 ) {
F_26 ( V_2 -> V_61 ,
L_3 ) ;
return - V_62 ;
}
if ( V_58 == V_63 && V_60 > ( V_14 -> V_64 / 2 ) ) {
F_26 ( V_2 -> V_61 ,
L_4 ) ;
return - V_62 ;
}
}
return 0 ;
}
static int F_27 ( struct V_1 * V_2 ,
struct V_13 * V_14 ,
struct V_22 * V_23 )
{
int V_65 = 0 ;
unsigned int V_66 ;
V_65 |= F_28 ( & V_23 -> V_67 , V_68 ) ;
V_65 |= F_28 ( & V_23 -> V_69 , V_70 ) ;
V_65 |= F_28 ( & V_23 -> V_71 , V_72 ) ;
V_65 |= F_28 ( & V_23 -> V_73 , V_32 ) ;
V_65 |= F_28 ( & V_23 -> V_31 , V_32 | V_74 ) ;
if ( V_65 )
return 1 ;
V_65 |= F_29 ( V_23 -> V_31 ) ;
if ( V_65 )
return 2 ;
V_65 |= F_30 ( & V_23 -> V_75 , 0 ) ;
V_65 |= F_30 ( & V_23 -> V_76 , 0 ) ;
V_65 |= F_31 ( & V_23 -> V_77 , 10000 ) ;
V_65 |= F_31 ( & V_23 -> V_49 , 1 ) ;
V_65 |= F_30 ( & V_23 -> V_78 ,
V_23 -> V_49 ) ;
if ( V_23 -> V_31 == V_32 )
V_65 |= F_31 ( & V_23 -> V_34 , 1 ) ;
else
V_65 |= F_30 ( & V_23 -> V_34 , 0 ) ;
if ( V_65 )
return 3 ;
V_66 = V_23 -> V_77 ;
F_32 ( V_2 -> V_52 , & V_66 , V_23 -> V_79 ) ;
V_65 |= F_30 ( & V_23 -> V_77 , V_66 ) ;
if ( V_65 )
return 4 ;
if ( V_23 -> V_47 && V_23 -> V_49 > 0 )
V_65 |= F_25 ( V_2 , V_14 , V_23 ) ;
if ( V_65 )
return 5 ;
return 0 ;
}
static int F_33 ( struct V_1 * V_2 ,
struct V_13 * V_14 )
{
F_2 ( V_80 , V_2 -> V_5 + V_55 ) ;
return 0 ;
}
static void F_34 ( struct V_1 * V_2 )
{
F_19 ( 0 , V_2 -> V_5 + V_15 ) ;
}
static int F_35 ( struct V_1 * V_2 ,
struct V_13 * V_14 ,
struct V_81 * V_82 ,
unsigned long V_83 )
{
unsigned int V_24 ;
V_24 = F_9 ( V_2 -> V_5 + V_9 ) ;
if ( V_24 & V_30 )
return 0 ;
return - V_84 ;
}
static int F_36 ( struct V_1 * V_2 ,
struct V_13 * V_14 ,
struct V_81 * V_82 ,
unsigned int * V_85 )
{
unsigned int V_60 = F_18 ( V_82 -> V_37 ) ;
unsigned int V_39 = F_14 ( V_82 -> V_37 ) ;
int V_86 ;
int V_59 ;
if ( V_39 == V_63 && V_60 > ( V_14 -> V_64 / 2 ) )
return - V_62 ;
F_2 ( V_80 , V_2 -> V_5 + V_55 ) ;
F_12 ( V_2 , V_14 , V_82 -> V_37 , V_87 ) ;
F_19 ( F_20 ( V_60 ) | F_21 ( V_60 ) ,
V_2 -> V_5 + V_51 ) ;
for ( V_59 = 0 ; V_59 < V_82 -> V_88 ; V_59 ++ ) {
F_5 ( V_2 ) ;
F_34 ( V_2 ) ;
V_86 = F_37 ( V_2 , V_14 , V_82 , F_35 , 0 ) ;
if ( V_86 )
break;
V_85 [ V_59 ] = F_6 ( V_2 , V_14 ) ;
}
F_5 ( V_2 ) ;
return V_82 -> V_88 ;
}
static int F_38 ( struct V_1 * V_2 ,
struct V_13 * V_14 ,
struct V_81 * V_82 ,
unsigned int * V_85 )
{
struct V_43 * V_44 = V_2 -> V_45 ;
unsigned int V_60 = F_18 ( V_82 -> V_37 ) ;
unsigned int V_38 = F_13 ( V_82 -> V_37 ) ;
unsigned int V_7 ;
int V_59 ;
V_7 = V_44 -> V_89 ;
V_7 &= ~ F_39 ( V_60 ) ;
V_7 |= F_40 ( V_60 , V_38 ) ;
if ( V_7 != V_44 -> V_89 ) {
V_44 -> V_89 = V_7 ;
F_2 ( V_7 , V_2 -> V_5 + V_90 ) ;
}
for ( V_59 = 0 ; V_59 < V_82 -> V_88 ; V_59 ++ ) {
V_7 = V_85 [ V_59 ] ;
V_14 -> V_91 [ V_60 ] = V_7 ;
if ( V_14 -> V_16 == 0x0fff ) {
V_7 <<= 4 ;
F_19 ( V_7 , V_2 -> V_5 + F_41 ( V_60 ) ) ;
} else {
F_2 ( V_7 & 0xff ,
V_2 -> V_5 + F_42 ( V_60 ) ) ;
F_2 ( ( V_7 >> 8 ) & 0xff ,
V_2 -> V_5 + F_42 ( V_60 ) ) ;
}
}
return V_82 -> V_88 ;
}
static int F_43 ( struct V_1 * V_2 ,
struct V_13 * V_14 ,
struct V_81 * V_82 ,
unsigned int * V_85 )
{
unsigned int V_60 = F_18 ( V_82 -> V_37 ) ;
F_7 ( V_2 -> V_5 + F_42 ( V_60 ) ) ;
return F_44 ( V_2 , V_14 , V_82 , V_85 ) ;
}
static int F_45 ( struct V_1 * V_2 ,
struct V_13 * V_14 ,
struct V_81 * V_82 ,
unsigned int * V_85 )
{
V_85 [ 1 ] = F_9 ( V_2 -> V_5 + V_92 ) ;
return V_82 -> V_88 ;
}
static int F_46 ( struct V_1 * V_2 ,
struct V_13 * V_14 ,
struct V_81 * V_82 ,
unsigned int * V_85 )
{
if ( F_47 ( V_14 , V_85 ) )
F_2 ( V_14 -> V_93 , V_2 -> V_5 + V_92 ) ;
V_85 [ 1 ] = V_14 -> V_93 ;
return V_82 -> V_88 ;
}
static void F_48 ( struct V_1 * V_2 )
{
struct V_43 * V_44 = V_2 -> V_45 ;
F_2 ( V_4 , V_2 -> V_5 + V_6 ) ;
F_3 ( V_2 , V_94 ) ;
F_2 ( V_80 , V_2 -> V_5 + V_55 ) ;
F_1 ( V_2 , F_15 ( 0 ) |
V_87 |
V_41 |
V_42 ) ;
F_19 ( F_20 ( 0 ) | F_21 ( 0 ) ,
V_2 -> V_5 + V_51 ) ;
V_44 -> V_89 = F_40 ( 0 , 2 ) | F_40 ( 1 , 2 ) ;
F_2 ( V_44 -> V_89 , V_2 -> V_5 + V_90 ) ;
F_19 ( 0 , V_2 -> V_5 + F_41 ( 0 ) ) ;
F_19 ( 0 , V_2 -> V_5 + F_41 ( 0 ) ) ;
F_7 ( V_2 -> V_5 + F_42 ( 0 ) ) ;
F_2 ( 0 , V_2 -> V_5 + V_92 ) ;
F_4 ( V_2 ) ;
}
static int F_49 ( struct V_1 * V_2 ,
struct V_95 * V_96 )
{
const struct V_97 * V_98 = V_2 -> V_99 ;
struct V_43 * V_44 ;
struct V_13 * V_14 ;
int V_86 ;
V_44 = F_50 ( V_2 , sizeof( * V_44 ) ) ;
if ( ! V_44 )
return - V_100 ;
V_86 = F_51 ( V_2 , V_96 -> V_101 [ 0 ] , 0x10 ) ;
if ( V_86 )
return V_86 ;
F_48 ( V_2 ) ;
if ( ( 1 << V_96 -> V_101 [ 1 ] ) & 0x8cec ) {
V_86 = F_52 ( V_96 -> V_101 [ 1 ] , F_8 , 0 ,
V_2 -> V_102 , V_2 ) ;
if ( V_86 == 0 ) {
V_2 -> V_17 = V_96 -> V_101 [ 1 ] ;
switch ( V_2 -> V_17 ) {
case 10 :
V_44 -> V_17 = 4 ;
break;
case 11 :
V_44 -> V_17 = 1 ;
break;
case 15 :
V_44 -> V_17 = 6 ;
break;
default:
V_44 -> V_17 = V_2 -> V_17 ;
break;
}
}
}
V_2 -> V_52 = F_53 ( V_2 -> V_5 + V_103 ,
V_104 , V_105 , 0 ) ;
if ( ! V_2 -> V_52 )
return - V_100 ;
V_86 = F_54 ( V_2 , 4 ) ;
if ( V_86 )
return V_86 ;
V_14 = & V_2 -> V_106 [ 0 ] ;
V_14 -> type = V_107 ;
V_14 -> V_108 = V_109 | V_110 | V_111 ;
V_14 -> V_64 = 64 ;
V_14 -> V_16 = V_98 -> V_16 ;
V_14 -> V_112 = & V_113 ;
V_14 -> V_114 = F_36 ;
if ( V_2 -> V_17 ) {
V_2 -> V_19 = V_14 ;
V_14 -> V_108 |= V_115 ;
V_14 -> V_116 = V_14 -> V_64 ;
V_14 -> V_117 = F_27 ;
V_14 -> V_118 = F_17 ;
V_14 -> V_119 = F_33 ;
}
V_14 = & V_2 -> V_106 [ 1 ] ;
V_14 -> type = V_120 ;
V_14 -> V_108 = V_121 ;
V_14 -> V_64 = 2 ;
V_14 -> V_16 = V_98 -> V_16 ;
V_14 -> V_112 = & V_122 ;
V_14 -> V_123 = F_38 ;
V_14 -> V_114 = F_43 ;
V_86 = F_55 ( V_14 ) ;
if ( V_86 )
return V_86 ;
V_14 = & V_2 -> V_106 [ 2 ] ;
V_14 -> type = V_124 ;
V_14 -> V_108 = V_109 ;
V_14 -> V_64 = 8 ;
V_14 -> V_16 = 1 ;
V_14 -> V_112 = & V_125 ;
V_14 -> V_126 = F_45 ;
V_14 = & V_2 -> V_106 [ 3 ] ;
V_14 -> type = V_127 ;
V_14 -> V_108 = V_121 ;
V_14 -> V_64 = 8 ;
V_14 -> V_16 = 1 ;
V_14 -> V_112 = & V_125 ;
V_14 -> V_126 = F_46 ;
return 0 ;
}
