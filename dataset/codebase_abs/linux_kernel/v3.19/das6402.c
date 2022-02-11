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
static void F_6 ( struct V_1 * V_2 , bool V_13 )
{
struct V_14 * V_15 = V_2 -> V_16 ;
unsigned long V_17 = V_2 -> V_5 + V_18 ;
if ( V_13 ) {
F_7 ( V_17 , 0 , 0 , V_19 | V_20 ) ;
F_7 ( V_17 , 0 , 1 , V_21 | V_20 ) ;
F_7 ( V_17 , 0 , 2 , V_21 | V_20 ) ;
F_8 ( V_17 , 0 , 0 , V_15 -> V_22 ) ;
F_8 ( V_17 , 0 , 1 , V_15 -> V_23 ) ;
F_8 ( V_17 , 0 , 2 , V_15 -> V_24 ) ;
} else {
F_7 ( V_17 , 0 , 0 , V_19 | V_20 ) ;
F_7 ( V_17 , 0 , 1 , V_19 | V_20 ) ;
F_7 ( V_17 , 0 , 2 , V_19 | V_20 ) ;
}
}
static unsigned int F_9 ( struct V_1 * V_2 ,
struct V_25 * V_26 )
{
unsigned int V_7 ;
V_7 = F_10 ( V_2 -> V_5 + V_27 ) ;
if ( V_26 -> V_28 == 0x0fff )
V_7 >>= 4 ;
return V_7 ;
}
static T_1 F_11 ( int V_29 , void * V_30 )
{
struct V_1 * V_2 = V_30 ;
struct V_25 * V_26 = V_2 -> V_31 ;
struct V_32 * V_33 = V_26 -> V_33 ;
struct V_34 * V_35 = & V_33 -> V_35 ;
unsigned int V_36 ;
V_36 = F_12 ( V_2 -> V_5 + V_9 ) ;
if ( ( V_36 & V_37 ) == 0 )
return V_38 ;
if ( V_36 & V_39 ) {
V_33 -> V_40 |= V_41 ;
} else if ( V_36 & V_42 ) {
unsigned int V_7 ;
V_7 = F_9 ( V_2 , V_26 ) ;
F_13 ( V_26 , & V_7 , 1 ) ;
if ( V_35 -> V_43 == V_44 &&
V_33 -> V_45 >= V_35 -> V_46 )
V_33 -> V_40 |= V_47 ;
}
F_4 ( V_2 ) ;
F_14 ( V_2 , V_26 ) ;
return V_48 ;
}
static void F_15 ( struct V_1 * V_2 ,
struct V_25 * V_26 ,
unsigned int V_49 ,
unsigned int V_3 )
{
unsigned int V_50 = F_16 ( V_49 ) ;
unsigned int V_51 = F_17 ( V_49 ) ;
V_3 |= F_18 ( V_50 ) ;
if ( V_51 == V_52 )
V_3 |= V_53 ;
if ( F_19 ( V_26 , V_50 ) )
V_3 |= V_54 ;
F_1 ( V_2 , V_3 ) ;
}
static int F_20 ( struct V_1 * V_2 ,
struct V_25 * V_26 )
{
struct V_14 * V_15 = V_2 -> V_16 ;
struct V_34 * V_35 = & V_26 -> V_33 -> V_35 ;
unsigned int V_55 = F_21 ( V_35 -> V_56 [ 0 ] ) ;
unsigned int V_57 = F_21 ( V_35 -> V_56 [ V_35 -> V_58 - 1 ] ) ;
F_15 ( V_2 , V_26 , V_35 -> V_56 [ 0 ] , V_59 ) ;
F_22 ( F_23 ( V_57 ) | F_24 ( V_55 ) ,
V_2 -> V_5 + V_60 ) ;
F_6 ( V_2 , true ) ;
F_2 ( V_61 |
F_25 ( V_15 -> V_29 ) |
V_62 , V_2 -> V_5 + V_63 ) ;
return 0 ;
}
static int F_26 ( struct V_1 * V_2 ,
struct V_25 * V_26 ,
struct V_34 * V_35 )
{
unsigned int V_64 = F_21 ( V_35 -> V_56 [ 0 ] ) ;
unsigned int V_65 = F_16 ( V_35 -> V_56 [ 0 ] ) ;
unsigned int V_66 = F_17 ( V_35 -> V_56 [ 0 ] ) ;
int V_67 ;
for ( V_67 = 1 ; V_67 < V_35 -> V_58 ; V_67 ++ ) {
unsigned int V_68 = F_21 ( V_35 -> V_56 [ V_67 ] ) ;
unsigned int V_50 = F_16 ( V_35 -> V_56 [ V_67 ] ) ;
unsigned int V_51 = F_17 ( V_35 -> V_56 [ V_67 ] ) ;
if ( V_68 != V_64 + V_67 ) {
F_27 ( V_2 -> V_69 ,
L_1 ) ;
return - V_70 ;
}
if ( V_50 != V_65 ) {
F_27 ( V_2 -> V_69 ,
L_2 ) ;
return - V_70 ;
}
if ( V_51 != V_66 ) {
F_27 ( V_2 -> V_69 ,
L_3 ) ;
return - V_70 ;
}
if ( V_66 == V_71 && V_68 > ( V_26 -> V_72 / 2 ) ) {
F_27 ( V_2 -> V_69 ,
L_4 ) ;
return - V_70 ;
}
}
return 0 ;
}
static int F_28 ( struct V_1 * V_2 ,
struct V_25 * V_26 ,
struct V_34 * V_35 )
{
struct V_14 * V_15 = V_2 -> V_16 ;
int V_73 = 0 ;
unsigned int V_74 ;
V_73 |= F_29 ( & V_35 -> V_75 , V_76 ) ;
V_73 |= F_29 ( & V_35 -> V_77 , V_78 ) ;
V_73 |= F_29 ( & V_35 -> V_79 , V_80 ) ;
V_73 |= F_29 ( & V_35 -> V_81 , V_44 ) ;
V_73 |= F_29 ( & V_35 -> V_43 , V_44 | V_82 ) ;
if ( V_73 )
return 1 ;
V_73 |= F_30 ( V_35 -> V_43 ) ;
if ( V_73 )
return 2 ;
V_73 |= F_31 ( & V_35 -> V_83 , 0 ) ;
V_73 |= F_31 ( & V_35 -> V_84 , 0 ) ;
V_73 |= F_32 ( & V_35 -> V_85 , 10000 ) ;
V_73 |= F_32 ( & V_35 -> V_58 , 1 ) ;
V_73 |= F_31 ( & V_35 -> V_86 , V_35 -> V_58 ) ;
if ( V_35 -> V_43 == V_44 )
V_73 |= F_32 ( & V_35 -> V_46 , 1 ) ;
else
V_73 |= F_31 ( & V_35 -> V_46 , 0 ) ;
if ( V_73 )
return 3 ;
if ( V_35 -> V_79 == V_80 ) {
V_74 = V_35 -> V_85 ;
F_33 ( V_87 ,
& V_15 -> V_23 ,
& V_15 -> V_24 ,
& V_74 , V_35 -> V_88 ) ;
V_73 |= F_31 ( & V_35 -> V_85 , V_74 ) ;
}
if ( V_73 )
return 4 ;
if ( V_35 -> V_56 && V_35 -> V_58 > 0 )
V_73 |= F_26 ( V_2 , V_26 , V_35 ) ;
if ( V_73 )
return 5 ;
return 0 ;
}
static int F_34 ( struct V_1 * V_2 ,
struct V_25 * V_26 )
{
F_2 ( V_89 , V_2 -> V_5 + V_63 ) ;
return 0 ;
}
static void F_35 ( struct V_1 * V_2 )
{
F_22 ( 0 , V_2 -> V_5 + V_27 ) ;
}
static int F_36 ( struct V_1 * V_2 ,
struct V_25 * V_26 ,
struct V_90 * V_91 ,
unsigned long V_92 )
{
unsigned int V_36 ;
V_36 = F_12 ( V_2 -> V_5 + V_9 ) ;
if ( V_36 & V_42 )
return 0 ;
return - V_93 ;
}
static int F_37 ( struct V_1 * V_2 ,
struct V_25 * V_26 ,
struct V_90 * V_91 ,
unsigned int * V_94 )
{
unsigned int V_68 = F_21 ( V_91 -> V_49 ) ;
unsigned int V_51 = F_17 ( V_91 -> V_49 ) ;
int V_95 ;
int V_67 ;
if ( V_51 == V_71 && V_68 > ( V_26 -> V_72 / 2 ) )
return - V_70 ;
F_2 ( V_89 , V_2 -> V_5 + V_63 ) ;
F_15 ( V_2 , V_26 , V_91 -> V_49 , V_96 ) ;
F_22 ( F_23 ( V_68 ) | F_24 ( V_68 ) ,
V_2 -> V_5 + V_60 ) ;
for ( V_67 = 0 ; V_67 < V_91 -> V_97 ; V_67 ++ ) {
F_5 ( V_2 ) ;
F_35 ( V_2 ) ;
V_95 = F_38 ( V_2 , V_26 , V_91 , F_36 , 0 ) ;
if ( V_95 )
break;
V_94 [ V_67 ] = F_9 ( V_2 , V_26 ) ;
}
F_5 ( V_2 ) ;
return V_91 -> V_97 ;
}
static int F_39 ( struct V_1 * V_2 ,
struct V_25 * V_26 ,
struct V_90 * V_91 ,
unsigned int * V_94 )
{
struct V_14 * V_15 = V_2 -> V_16 ;
unsigned int V_68 = F_21 ( V_91 -> V_49 ) ;
unsigned int V_50 = F_16 ( V_91 -> V_49 ) ;
unsigned int V_7 ;
int V_67 ;
V_7 = V_15 -> V_98 ;
V_7 &= ~ F_40 ( V_68 ) ;
V_7 |= F_41 ( V_68 , V_50 ) ;
if ( V_7 != V_15 -> V_98 ) {
V_15 -> V_98 = V_7 ;
F_2 ( V_7 , V_2 -> V_5 + V_99 ) ;
}
for ( V_67 = 0 ; V_67 < V_91 -> V_97 ; V_67 ++ ) {
V_7 = V_94 [ V_67 ] ;
V_26 -> V_100 [ V_68 ] = V_7 ;
if ( V_26 -> V_28 == 0x0fff ) {
V_7 <<= 4 ;
F_22 ( V_7 , V_2 -> V_5 + F_42 ( V_68 ) ) ;
} else {
F_2 ( V_7 & 0xff ,
V_2 -> V_5 + F_43 ( V_68 ) ) ;
F_2 ( ( V_7 >> 8 ) & 0xff ,
V_2 -> V_5 + F_43 ( V_68 ) ) ;
}
}
return V_91 -> V_97 ;
}
static int F_44 ( struct V_1 * V_2 ,
struct V_25 * V_26 ,
struct V_90 * V_91 ,
unsigned int * V_94 )
{
unsigned int V_68 = F_21 ( V_91 -> V_49 ) ;
F_10 ( V_2 -> V_5 + F_43 ( V_68 ) ) ;
return F_45 ( V_2 , V_26 , V_91 , V_94 ) ;
}
static int F_46 ( struct V_1 * V_2 ,
struct V_25 * V_26 ,
struct V_90 * V_91 ,
unsigned int * V_94 )
{
V_94 [ 1 ] = F_12 ( V_2 -> V_5 + V_101 ) ;
return V_91 -> V_97 ;
}
static int F_47 ( struct V_1 * V_2 ,
struct V_25 * V_26 ,
struct V_90 * V_91 ,
unsigned int * V_94 )
{
if ( F_48 ( V_26 , V_94 ) )
F_2 ( V_26 -> V_102 , V_2 -> V_5 + V_101 ) ;
V_94 [ 1 ] = V_26 -> V_102 ;
return V_91 -> V_97 ;
}
static void F_49 ( struct V_1 * V_2 )
{
struct V_14 * V_15 = V_2 -> V_16 ;
F_2 ( V_4 , V_2 -> V_5 + V_6 ) ;
F_3 ( V_2 , V_103 ) ;
F_2 ( V_89 , V_2 -> V_5 + V_63 ) ;
F_1 ( V_2 , F_18 ( 0 ) |
V_96 |
V_53 |
V_54 ) ;
F_22 ( F_23 ( 0 ) | F_24 ( 0 ) ,
V_2 -> V_5 + V_60 ) ;
V_15 -> V_98 = F_41 ( 0 , 2 ) | F_41 ( 1 , 2 ) ;
F_2 ( V_15 -> V_98 , V_2 -> V_5 + V_99 ) ;
F_22 ( 0 , V_2 -> V_5 + F_42 ( 0 ) ) ;
F_22 ( 0 , V_2 -> V_5 + F_42 ( 0 ) ) ;
F_10 ( V_2 -> V_5 + F_43 ( 0 ) ) ;
F_6 ( V_2 , false ) ;
F_2 ( 0 , V_2 -> V_5 + V_101 ) ;
F_4 ( V_2 ) ;
}
static int F_50 ( struct V_1 * V_2 ,
struct V_104 * V_105 )
{
const struct V_106 * V_107 = V_2 -> V_108 ;
struct V_14 * V_15 ;
struct V_25 * V_26 ;
int V_95 ;
V_15 = F_51 ( V_2 , sizeof( * V_15 ) ) ;
if ( ! V_15 )
return - V_109 ;
V_95 = F_52 ( V_2 , V_105 -> V_110 [ 0 ] , 0x10 ) ;
if ( V_95 )
return V_95 ;
F_49 ( V_2 ) ;
if ( ( 1 << V_105 -> V_110 [ 1 ] ) & 0x8cec ) {
V_95 = F_53 ( V_105 -> V_110 [ 1 ] , F_11 , 0 ,
V_2 -> V_111 , V_2 ) ;
if ( V_95 == 0 ) {
V_2 -> V_29 = V_105 -> V_110 [ 1 ] ;
switch ( V_2 -> V_29 ) {
case 10 :
V_15 -> V_29 = 4 ;
break;
case 11 :
V_15 -> V_29 = 1 ;
break;
case 15 :
V_15 -> V_29 = 6 ;
break;
default:
V_15 -> V_29 = V_2 -> V_29 ;
break;
}
}
}
V_95 = F_54 ( V_2 , 4 ) ;
if ( V_95 )
return V_95 ;
V_26 = & V_2 -> V_112 [ 0 ] ;
V_26 -> type = V_113 ;
V_26 -> V_114 = V_115 | V_116 | V_117 ;
V_26 -> V_72 = 64 ;
V_26 -> V_28 = V_107 -> V_28 ;
V_26 -> V_118 = & V_119 ;
V_26 -> V_120 = F_37 ;
if ( V_2 -> V_29 ) {
V_2 -> V_31 = V_26 ;
V_26 -> V_114 |= V_121 ;
V_26 -> V_122 = V_26 -> V_72 ;
V_26 -> V_123 = F_28 ;
V_26 -> V_124 = F_20 ;
V_26 -> V_125 = F_34 ;
}
V_26 = & V_2 -> V_112 [ 1 ] ;
V_26 -> type = V_126 ;
V_26 -> V_114 = V_127 ;
V_26 -> V_72 = 2 ;
V_26 -> V_28 = V_107 -> V_28 ;
V_26 -> V_118 = & V_128 ;
V_26 -> V_129 = F_39 ;
V_26 -> V_120 = F_44 ;
V_95 = F_55 ( V_26 ) ;
if ( V_95 )
return V_95 ;
V_26 = & V_2 -> V_112 [ 2 ] ;
V_26 -> type = V_130 ;
V_26 -> V_114 = V_115 ;
V_26 -> V_72 = 8 ;
V_26 -> V_28 = 1 ;
V_26 -> V_118 = & V_131 ;
V_26 -> V_132 = F_46 ;
V_26 = & V_2 -> V_112 [ 3 ] ;
V_26 -> type = V_133 ;
V_26 -> V_114 = V_127 ;
V_26 -> V_72 = 8 ;
V_26 -> V_28 = 1 ;
V_26 -> V_118 = & V_131 ;
V_26 -> V_132 = F_47 ;
return 0 ;
}
