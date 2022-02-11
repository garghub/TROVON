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
F_2 ( V_23 & ~ V_26 ,
V_2 -> V_6 + V_7 ) ;
V_21 -> V_27 = F_3 ( V_2 -> V_6 + V_8 ) &
0xffff ;
F_7 ( V_21 , & V_21 -> V_27 , 1 ) ;
F_8 ( V_2 , V_21 ) ;
F_2 ( V_23 , V_2 -> V_6 + V_7 ) ;
}
V_23 = F_3 ( V_4 -> V_14 + V_28 ) ;
if ( V_23 & 0x01 ) {
V_24 = F_3 ( V_4 -> V_14 + V_15 ) ;
F_2 ( 0x0 , V_4 -> V_14 + V_15 ) ;
F_9 ( V_29 , V_4 -> V_30 , 0 ) ;
F_2 ( V_24 , V_4 -> V_14 + V_15 ) ;
}
if ( V_4 -> V_17 ) {
for ( V_25 = 0 ; V_25 < 4 ; V_25 ++ ) {
unsigned long V_6 ;
V_6 = V_4 -> V_17 + F_5 ( V_25 ) ;
V_23 = F_3 ( V_6 + V_28 ) ;
if ( V_23 & 0x01 ) {
V_24 = F_3 ( V_6 + V_15 ) ;
F_2 ( 0x0 , V_6 + V_15 ) ;
F_9 ( V_29 , V_4 -> V_30 , 0 ) ;
F_2 ( V_24 , V_6 + V_15 ) ;
}
}
}
return V_31 ;
}
static int F_10 ( struct V_1 * V_2 ,
struct V_20 * V_21 ,
struct V_32 * V_33 ,
unsigned int * V_34 )
{
V_34 [ 1 ] = F_3 ( V_2 -> V_6 + V_35 ) ;
return V_33 -> V_36 ;
}
static int F_11 ( struct V_1 * V_2 ,
struct V_20 * V_21 ,
struct V_32 * V_33 ,
unsigned int * V_34 )
{
V_21 -> V_27 = F_3 ( V_2 -> V_6 + V_11 ) ;
if ( F_12 ( V_21 , V_34 ) )
F_2 ( V_21 -> V_27 , V_2 -> V_6 + V_11 ) ;
V_34 [ 1 ] = V_21 -> V_27 ;
return V_33 -> V_36 ;
}
static int F_13 ( struct V_1 * V_2 ,
struct V_20 * V_21 ,
struct V_32 * V_33 ,
unsigned int * V_34 )
{
V_34 [ 1 ] = F_3 ( V_2 -> V_6 + V_37 ) & 3 ;
return V_33 -> V_36 ;
}
static int F_14 ( struct V_1 * V_2 ,
struct V_20 * V_21 ,
struct V_32 * V_33 ,
unsigned int * V_34 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
unsigned int V_38 , V_39 ;
switch ( V_34 [ 0 ] ) {
case V_40 :
if ( V_34 [ 1 ] != 0 )
return - V_41 ;
V_38 = V_34 [ 3 ] ;
V_39 = ( 1U << V_38 ) - 1 ;
switch ( V_34 [ 2 ] ) {
case V_42 :
V_4 -> V_24 = 0 ;
V_4 -> V_43 = 0 ;
V_4 -> V_44 = 0 ;
F_2 ( 0x0 , V_2 -> V_6 + V_7 ) ;
F_3 ( V_2 -> V_6 + V_8 ) ;
F_2 ( 0x0 , V_2 -> V_6 + V_9 ) ;
F_2 ( 0x0 , V_2 -> V_6 + V_10 ) ;
break;
case V_45 :
if ( V_4 -> V_24 != V_26 ) {
V_4 -> V_24 = V_26 ;
V_4 -> V_43 = 0 ;
V_4 -> V_44 = 0 ;
} else {
V_4 -> V_43 &= V_39 ;
V_4 -> V_44 &= V_39 ;
}
V_4 -> V_43 |= V_34 [ 4 ] << V_38 ;
V_4 -> V_44 |= V_34 [ 5 ] << V_38 ;
break;
case V_46 :
if ( V_4 -> V_24 != ( V_26 |
V_47 ) ) {
V_4 -> V_24 = V_26 |
V_47 ;
V_4 -> V_43 = 0 ;
V_4 -> V_44 = 0 ;
} else {
V_4 -> V_43 &= V_39 ;
V_4 -> V_44 &= V_39 ;
}
V_4 -> V_43 |= V_34 [ 4 ] << V_38 ;
V_4 -> V_44 |= V_34 [ 5 ] << V_38 ;
break;
default:
return - V_41 ;
}
break;
default:
return - V_41 ;
}
return V_33 -> V_36 ;
}
static int F_15 ( struct V_1 * V_2 ,
struct V_20 * V_21 ,
struct V_32 * V_33 ,
unsigned int * V_34 )
{
V_34 [ 1 ] = V_21 -> V_27 ;
return 0 ;
}
static int F_16 ( struct V_1 * V_2 ,
struct V_20 * V_21 ,
struct V_48 * V_49 )
{
int V_50 = 0 ;
V_50 |= F_17 ( & V_49 -> V_51 , V_52 ) ;
V_50 |= F_17 ( & V_49 -> V_53 , V_54 ) ;
V_50 |= F_17 ( & V_49 -> V_55 , V_56 ) ;
V_50 |= F_17 ( & V_49 -> V_57 , V_58 ) ;
V_50 |= F_17 ( & V_49 -> V_59 , V_60 ) ;
if ( V_50 )
return 1 ;
V_50 |= F_18 ( & V_49 -> V_61 , 0 ) ;
V_50 |= F_18 ( & V_49 -> V_62 , 0 ) ;
V_50 |= F_18 ( & V_49 -> V_63 , 0 ) ;
V_50 |= F_18 ( & V_49 -> V_64 ,
V_49 -> V_65 ) ;
V_50 |= F_18 ( & V_49 -> V_66 , 0 ) ;
if ( V_50 )
return 3 ;
return 0 ;
}
static int F_19 ( struct V_1 * V_2 ,
struct V_20 * V_21 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
if ( ! V_4 -> V_24 ) {
F_20 ( V_2 -> V_67 ,
L_1 ) ;
return - V_41 ;
}
F_2 ( V_4 -> V_43 , V_2 -> V_6 + V_9 ) ;
F_2 ( V_4 -> V_44 , V_2 -> V_6 + V_10 ) ;
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
unsigned long V_68 )
{
struct V_69 * V_70 = F_23 ( V_2 ) ;
struct V_3 * V_4 ;
struct V_20 * V_21 ;
unsigned int V_71 ;
int V_72 ;
V_4 = F_24 ( V_2 , sizeof( * V_4 ) ) ;
if ( ! V_4 )
return - V_73 ;
V_72 = F_25 ( V_2 ) ;
if ( V_72 )
return V_72 ;
V_4 -> V_74 = F_26 ( V_70 , 0 ) ;
V_71 = F_3 ( V_4 -> V_74 + V_75 ) ;
if ( F_27 ( V_71 ) == 0 ) {
V_2 -> V_6 = F_26 ( V_70 , 1 ) +
V_76 ;
V_4 -> V_14 = V_4 -> V_74 + V_77 ;
} else {
V_2 -> V_6 = V_4 -> V_74 + V_78 ;
V_4 -> V_14 = V_4 -> V_74 + V_79 ;
V_4 -> V_17 = F_26 ( V_70 , 1 ) ;
}
F_1 ( V_2 ) ;
if ( V_70 -> V_18 > 0 ) {
V_72 = F_28 ( V_70 -> V_18 , F_6 , V_80 ,
V_2 -> V_81 , V_2 ) ;
if ( V_72 == 0 )
V_2 -> V_18 = V_70 -> V_18 ;
}
V_72 = F_29 ( V_2 , 7 ) ;
if ( V_72 )
return V_72 ;
V_21 = & V_2 -> V_82 [ 0 ] ;
V_21 -> type = V_83 ;
V_21 -> V_84 = V_85 ;
V_21 -> V_86 = 32 ;
V_21 -> V_87 = 1 ;
V_21 -> V_88 = & V_89 ;
V_21 -> V_90 = F_10 ;
V_21 = & V_2 -> V_82 [ 1 ] ;
V_21 -> type = V_91 ;
V_21 -> V_84 = V_92 ;
V_21 -> V_86 = 32 ;
V_21 -> V_87 = 1 ;
V_21 -> V_88 = & V_89 ;
V_21 -> V_90 = F_11 ;
V_21 = & V_2 -> V_82 [ 2 ] ;
if ( V_2 -> V_18 ) {
V_2 -> V_22 = V_21 ;
V_21 -> type = V_83 ;
V_21 -> V_84 = V_85 | V_93 ;
V_21 -> V_86 = 1 ;
V_21 -> V_87 = 1 ;
V_21 -> V_88 = & V_89 ;
V_21 -> V_94 = 1 ;
V_21 -> V_95 = F_14 ;
V_21 -> V_90 = F_15 ;
V_21 -> V_96 = F_16 ;
V_21 -> V_97 = F_19 ;
V_21 -> V_98 = F_21 ;
} else {
V_21 -> type = V_99 ;
}
V_21 = & V_2 -> V_82 [ 3 ] ;
V_21 -> type = V_100 ;
V_21 -> V_84 = V_92 | V_85 ;
V_21 -> V_86 = 1 ;
V_21 -> V_87 = 0x0fff ;
V_21 -> V_88 = & V_89 ;
V_21 -> V_95 = V_101 ;
V_21 -> V_102 = V_103 ;
V_21 -> V_104 = V_105 ;
V_21 = & V_2 -> V_82 [ 4 ] ;
if ( V_4 -> V_17 ) {
V_21 -> type = V_106 ;
V_21 -> V_84 = V_92 | V_85 | V_107 ;
V_21 -> V_86 = 3 ;
V_21 -> V_87 = 0xffffffff ;
V_21 -> V_88 = & V_89 ;
V_21 -> V_95 = V_108 ;
V_21 -> V_102 = V_109 ;
V_21 -> V_104 = V_110 ;
} else {
V_21 -> type = V_99 ;
}
V_21 = & V_2 -> V_82 [ 5 ] ;
V_72 = F_30 ( V_21 , V_2 -> V_6 + V_13 ) ;
if ( V_72 )
return V_72 ;
V_21 = & V_2 -> V_82 [ 6 ] ;
V_21 -> type = V_83 ;
V_21 -> V_84 = V_85 ;
V_21 -> V_86 = 2 ;
V_21 -> V_87 = 1 ;
V_21 -> V_88 = & V_89 ;
V_21 -> V_90 = F_13 ;
return 0 ;
}
static void F_31 ( struct V_1 * V_2 )
{
if ( V_2 -> V_6 )
F_1 ( V_2 ) ;
F_32 ( V_2 ) ;
}
static int F_33 ( struct V_69 * V_2 ,
const struct V_111 * V_112 )
{
return F_34 ( V_2 , & V_113 , V_112 -> V_114 ) ;
}
