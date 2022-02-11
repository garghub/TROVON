static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_2 ( 0x0 , V_2 -> V_6 + V_7 ) ;
F_3 ( V_2 -> V_6 + V_8 ) ;
F_2 ( 0x0 , V_2 -> V_6 + V_9 ) ;
F_2 ( 0x0 , V_2 -> V_6 + V_10 ) ;
F_2 ( 0x0 , V_2 -> V_6 + V_11 ) ;
F_2 ( 0x0 , V_2 -> V_6 + V_12 ) ;
F_4 ( V_2 -> V_6 + V_13 ) ;
F_2 ( 0x0 , V_4 -> V_14 + V_15 ) ;
F_2 ( 0x0 , V_4 -> V_14 + V_16 ) ;
if ( V_4 -> V_17 ) {
unsigned long V_6 = V_4 -> V_17 + V_15 ;
F_2 ( 0x0 , V_6 + F_5 ( 0 ) ) ;
F_2 ( 0x0 , V_6 + F_5 ( 1 ) ) ;
F_2 ( 0x0 , V_6 + F_5 ( 2 ) ) ;
}
return 0 ;
}
static T_1 F_6 ( int V_18 , void * V_19 )
{
struct V_1 * V_2 = V_19 ;
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_20 * V_21 = V_2 -> V_22 ;
unsigned int V_23 ;
unsigned int V_24 ;
unsigned int V_25 ;
V_23 = F_3 ( V_2 -> V_6 + V_7 ) ;
if ( V_23 & V_26 ) {
F_2 ( V_23 & V_27 ,
V_2 -> V_6 + V_7 ) ;
V_21 -> V_28 = F_3 ( V_2 -> V_6 + V_8 ) &
0xffff ;
F_7 ( V_21 , & V_21 -> V_28 , 1 ) ;
F_8 ( V_2 , V_21 ) ;
F_2 ( V_23 , V_2 -> V_6 + V_7 ) ;
}
V_23 = F_3 ( V_4 -> V_14 + V_29 ) ;
if ( V_23 & 0x01 ) {
V_24 = F_3 ( V_4 -> V_14 + V_15 ) ;
F_2 ( 0x0 , V_4 -> V_14 + V_15 ) ;
F_9 ( V_30 , V_4 -> V_31 , 0 ) ;
F_2 ( V_24 , V_4 -> V_14 + V_15 ) ;
}
if ( V_4 -> V_17 ) {
for ( V_25 = 0 ; V_25 < 4 ; V_25 ++ ) {
unsigned long V_6 ;
V_6 = V_4 -> V_17 + F_5 ( V_25 ) ;
V_23 = F_3 ( V_6 + V_29 ) ;
if ( V_23 & 0x01 ) {
V_24 = F_3 ( V_6 + V_15 ) ;
F_2 ( 0x0 , V_6 + V_15 ) ;
F_9 ( V_30 , V_4 -> V_31 , 0 ) ;
F_2 ( V_24 , V_6 + V_15 ) ;
}
}
}
return V_32 ;
}
static int F_10 ( struct V_1 * V_2 ,
struct V_20 * V_21 ,
struct V_33 * V_34 ,
unsigned int * V_35 )
{
V_35 [ 1 ] = F_3 ( V_2 -> V_6 + V_36 ) ;
return V_34 -> V_37 ;
}
static int F_11 ( struct V_1 * V_2 ,
struct V_20 * V_21 ,
struct V_33 * V_34 ,
unsigned int * V_35 )
{
V_21 -> V_28 = F_3 ( V_2 -> V_6 + V_11 ) ;
if ( F_12 ( V_21 , V_35 ) )
F_2 ( V_21 -> V_28 , V_2 -> V_6 + V_11 ) ;
V_35 [ 1 ] = V_21 -> V_28 ;
return V_34 -> V_37 ;
}
static int F_13 ( struct V_1 * V_2 ,
struct V_20 * V_21 ,
struct V_33 * V_34 ,
unsigned int * V_35 )
{
V_35 [ 1 ] = F_3 ( V_2 -> V_6 + V_38 ) & 3 ;
return V_34 -> V_37 ;
}
static int F_14 ( struct V_1 * V_2 ,
struct V_20 * V_21 ,
struct V_33 * V_34 ,
unsigned int * V_35 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
unsigned int V_39 , V_40 ;
switch ( V_35 [ 0 ] ) {
case V_41 :
if ( V_35 [ 1 ] != 0 )
return - V_42 ;
V_39 = V_35 [ 3 ] ;
V_40 = ( 1U << V_39 ) - 1 ;
switch ( V_35 [ 2 ] ) {
case V_43 :
V_4 -> V_24 = 0 ;
V_4 -> V_44 = 0 ;
V_4 -> V_45 = 0 ;
F_2 ( 0x0 , V_2 -> V_6 + V_7 ) ;
F_3 ( V_2 -> V_6 + V_8 ) ;
F_2 ( 0x0 , V_2 -> V_6 + V_9 ) ;
F_2 ( 0x0 , V_2 -> V_6 + V_10 ) ;
break;
case V_46 :
if ( V_4 -> V_24 != ( V_26 |
V_47 ) ) {
V_4 -> V_24 = V_26 |
V_47 ;
V_4 -> V_44 = 0 ;
V_4 -> V_45 = 0 ;
} else {
V_4 -> V_44 &= V_40 ;
V_4 -> V_45 &= V_40 ;
}
V_4 -> V_44 |= V_35 [ 4 ] << V_39 ;
V_4 -> V_45 |= V_35 [ 5 ] << V_39 ;
break;
case V_48 :
if ( V_4 -> V_24 != ( V_26 |
V_49 ) ) {
V_4 -> V_24 = V_26 |
V_49 ;
V_4 -> V_44 = 0 ;
V_4 -> V_45 = 0 ;
} else {
V_4 -> V_44 &= V_40 ;
V_4 -> V_45 &= V_40 ;
}
V_4 -> V_44 |= V_35 [ 4 ] << V_39 ;
V_4 -> V_45 |= V_35 [ 5 ] << V_39 ;
break;
default:
return - V_42 ;
}
break;
default:
return - V_42 ;
}
return V_34 -> V_37 ;
}
static int F_15 ( struct V_1 * V_2 ,
struct V_20 * V_21 ,
struct V_33 * V_34 ,
unsigned int * V_35 )
{
V_35 [ 1 ] = V_21 -> V_28 ;
return 0 ;
}
static int F_16 ( struct V_1 * V_2 ,
struct V_20 * V_21 ,
struct V_50 * V_51 )
{
int V_52 = 0 ;
V_52 |= F_17 ( & V_51 -> V_53 , V_54 ) ;
V_52 |= F_17 ( & V_51 -> V_55 , V_56 ) ;
V_52 |= F_17 ( & V_51 -> V_57 , V_58 ) ;
V_52 |= F_17 ( & V_51 -> V_59 , V_60 ) ;
V_52 |= F_17 ( & V_51 -> V_61 , V_62 ) ;
if ( V_52 )
return 1 ;
V_52 |= F_18 ( & V_51 -> V_63 , 0 ) ;
V_52 |= F_18 ( & V_51 -> V_64 , 0 ) ;
V_52 |= F_18 ( & V_51 -> V_65 , 0 ) ;
V_52 |= F_18 ( & V_51 -> V_66 , V_51 -> V_67 ) ;
V_52 |= F_18 ( & V_51 -> V_68 , 0 ) ;
if ( V_52 )
return 3 ;
return 0 ;
}
static int F_19 ( struct V_1 * V_2 ,
struct V_20 * V_21 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
if ( ! V_4 -> V_24 ) {
F_20 ( V_2 -> V_69 ,
L_1 ) ;
return - V_42 ;
}
F_2 ( V_4 -> V_44 , V_2 -> V_6 + V_9 ) ;
F_2 ( V_4 -> V_45 , V_2 -> V_6 + V_10 ) ;
F_2 ( V_4 -> V_24 , V_2 -> V_6 + V_7 ) ;
return 0 ;
}
static int F_21 ( struct V_1 * V_2 ,
struct V_20 * V_21 )
{
F_2 ( 0x0 , V_2 -> V_6 + V_7 ) ;
F_3 ( V_2 -> V_6 + V_8 ) ;
F_2 ( 0x0 , V_2 -> V_6 + V_9 ) ;
F_2 ( 0x0 , V_2 -> V_6 + V_10 ) ;
return 0 ;
}
static int F_22 ( struct V_1 * V_2 ,
unsigned long V_70 )
{
struct V_71 * V_72 = F_23 ( V_2 ) ;
struct V_3 * V_4 ;
struct V_20 * V_21 ;
unsigned int V_73 ;
int V_74 ;
V_4 = F_24 ( V_2 , sizeof( * V_4 ) ) ;
if ( ! V_4 )
return - V_75 ;
V_74 = F_25 ( V_2 ) ;
if ( V_74 )
return V_74 ;
V_4 -> V_76 = F_26 ( V_72 , 0 ) ;
V_73 = F_3 ( V_4 -> V_76 + V_77 ) ;
if ( F_27 ( V_73 ) == 0 ) {
V_2 -> V_6 = F_26 ( V_72 , 1 ) +
V_78 ;
V_4 -> V_14 = V_4 -> V_76 + V_79 ;
} else {
V_2 -> V_6 = V_4 -> V_76 + V_80 ;
V_4 -> V_14 = V_4 -> V_76 + V_81 ;
V_4 -> V_17 = F_26 ( V_72 , 1 ) ;
}
F_1 ( V_2 ) ;
if ( V_72 -> V_18 > 0 ) {
V_74 = F_28 ( V_72 -> V_18 , F_6 , V_82 ,
V_2 -> V_83 , V_2 ) ;
if ( V_74 == 0 )
V_2 -> V_18 = V_72 -> V_18 ;
}
V_74 = F_29 ( V_2 , 7 ) ;
if ( V_74 )
return V_74 ;
V_21 = & V_2 -> V_84 [ 0 ] ;
V_21 -> type = V_85 ;
V_21 -> V_86 = V_87 ;
V_21 -> V_88 = 32 ;
V_21 -> V_89 = 1 ;
V_21 -> V_90 = & V_91 ;
V_21 -> V_92 = F_10 ;
V_21 = & V_2 -> V_84 [ 1 ] ;
V_21 -> type = V_93 ;
V_21 -> V_86 = V_94 ;
V_21 -> V_88 = 32 ;
V_21 -> V_89 = 1 ;
V_21 -> V_90 = & V_91 ;
V_21 -> V_92 = F_11 ;
V_21 = & V_2 -> V_84 [ 2 ] ;
if ( V_2 -> V_18 ) {
V_2 -> V_22 = V_21 ;
V_21 -> type = V_85 ;
V_21 -> V_86 = V_87 | V_95 ;
V_21 -> V_88 = 1 ;
V_21 -> V_89 = 1 ;
V_21 -> V_90 = & V_91 ;
V_21 -> V_96 = 1 ;
V_21 -> V_97 = F_14 ;
V_21 -> V_92 = F_15 ;
V_21 -> V_98 = F_16 ;
V_21 -> V_99 = F_19 ;
V_21 -> V_100 = F_21 ;
} else {
V_21 -> type = V_101 ;
}
V_21 = & V_2 -> V_84 [ 3 ] ;
V_21 -> type = V_102 ;
V_21 -> V_86 = V_94 | V_87 ;
V_21 -> V_88 = 1 ;
V_21 -> V_89 = 0x0fff ;
V_21 -> V_90 = & V_91 ;
V_21 -> V_97 = V_103 ;
V_21 -> V_104 = V_105 ;
V_21 -> V_106 = V_107 ;
V_21 = & V_2 -> V_84 [ 4 ] ;
if ( V_4 -> V_17 ) {
V_21 -> type = V_108 ;
V_21 -> V_86 = V_94 | V_87 | V_109 ;
V_21 -> V_88 = 3 ;
V_21 -> V_89 = 0xffffffff ;
V_21 -> V_90 = & V_91 ;
V_21 -> V_97 = V_110 ;
V_21 -> V_104 = V_111 ;
V_21 -> V_106 = V_112 ;
} else {
V_21 -> type = V_101 ;
}
V_21 = & V_2 -> V_84 [ 5 ] ;
V_74 = F_30 ( V_21 , V_2 -> V_6 + V_13 ) ;
if ( V_74 )
return V_74 ;
V_21 = & V_2 -> V_84 [ 6 ] ;
V_21 -> type = V_85 ;
V_21 -> V_86 = V_87 ;
V_21 -> V_88 = 2 ;
V_21 -> V_89 = 1 ;
V_21 -> V_90 = & V_91 ;
V_21 -> V_92 = F_13 ;
return 0 ;
}
static void F_31 ( struct V_1 * V_2 )
{
if ( V_2 -> V_6 )
F_1 ( V_2 ) ;
F_32 ( V_2 ) ;
}
static int F_33 ( struct V_71 * V_2 ,
const struct V_113 * V_114 )
{
return F_34 ( V_2 , & V_115 , V_114 -> V_116 ) ;
}
