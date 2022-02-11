static int F_1 ( struct V_1 * V_2 )
{
F_2 ( 0x0 , V_2 -> V_3 + V_4 ) ;
F_3 ( V_2 -> V_3 + V_5 ) ;
F_2 ( 0x0 , V_2 -> V_3 + V_6 ) ;
F_2 ( 0x0 , V_2 -> V_3 + V_7 ) ;
return 0 ;
}
static int F_4 ( struct V_1 * V_2 ,
struct V_8 * V_9 ,
struct V_10 * V_11 ,
unsigned int * V_12 )
{
struct V_13 * V_14 = V_2 -> V_15 ;
unsigned int V_16 , V_17 ;
switch ( V_12 [ 0 ] ) {
case V_18 :
if ( V_12 [ 1 ] != 0 )
return - V_19 ;
V_16 = V_12 [ 3 ] ;
V_17 = ( 1U << V_16 ) - 1 ;
switch ( V_12 [ 2 ] ) {
case V_20 :
V_14 -> V_21 = 0 ;
V_14 -> V_22 = 0 ;
V_14 -> V_23 = 0 ;
F_1 ( V_2 ) ;
break;
case V_24 :
if ( V_14 -> V_21 != ( V_25 |
V_26 ) ) {
V_14 -> V_21 = V_25 |
V_26 ;
V_14 -> V_22 = 0 ;
V_14 -> V_23 = 0 ;
} else {
V_14 -> V_22 &= V_17 ;
V_14 -> V_23 &= V_17 ;
}
V_14 -> V_22 |= V_12 [ 4 ] << V_16 ;
V_14 -> V_23 |= V_12 [ 5 ] << V_16 ;
break;
case V_27 :
if ( V_14 -> V_21 != ( V_25 |
V_28 ) ) {
V_14 -> V_21 = V_25 |
V_28 ;
V_14 -> V_22 = 0 ;
V_14 -> V_23 = 0 ;
} else {
V_14 -> V_22 &= V_17 ;
V_14 -> V_23 &= V_17 ;
}
V_14 -> V_22 |= V_12 [ 4 ] << V_16 ;
V_14 -> V_23 |= V_12 [ 5 ] << V_16 ;
break;
default:
return - V_19 ;
}
break;
default:
return - V_19 ;
}
return V_11 -> V_29 ;
}
static int F_5 ( struct V_1 * V_2 ,
struct V_8 * V_9 ,
struct V_10 * V_11 ,
unsigned int * V_12 )
{
V_12 [ 1 ] = V_9 -> V_30 ;
return 0 ;
}
static int F_6 ( struct V_1 * V_2 ,
struct V_8 * V_9 ,
struct V_31 * V_32 )
{
int V_33 = 0 ;
V_33 |= F_7 ( & V_32 -> V_34 , V_35 ) ;
V_33 |= F_7 ( & V_32 -> V_36 , V_37 ) ;
V_33 |= F_7 ( & V_32 -> V_38 , V_39 ) ;
V_33 |= F_7 ( & V_32 -> V_40 , V_41 ) ;
V_33 |= F_7 ( & V_32 -> V_42 , V_43 ) ;
if ( V_33 )
return 1 ;
if ( V_33 )
return 2 ;
V_33 |= F_8 ( & V_32 -> V_44 , 0 ) ;
V_33 |= F_8 ( & V_32 -> V_45 , 0 ) ;
V_33 |= F_8 ( & V_32 -> V_46 , 0 ) ;
V_33 |= F_8 ( & V_32 -> V_47 , 1 ) ;
V_33 |= F_8 ( & V_32 -> V_48 , 0 ) ;
if ( V_33 )
return 3 ;
if ( V_33 )
return 4 ;
return 0 ;
}
static int F_9 ( struct V_1 * V_2 ,
struct V_8 * V_9 )
{
struct V_13 * V_14 = V_2 -> V_15 ;
if ( ! V_14 -> V_21 ) {
F_10 ( V_2 -> V_49 ,
L_1 ) ;
return - V_19 ;
}
F_2 ( V_14 -> V_22 , V_2 -> V_3 + V_6 ) ;
F_2 ( V_14 -> V_23 , V_2 -> V_3 + V_7 ) ;
F_2 ( V_14 -> V_21 , V_2 -> V_3 + V_4 ) ;
return 0 ;
}
static int F_11 ( struct V_1 * V_2 ,
struct V_8 * V_9 )
{
return F_1 ( V_2 ) ;
}
static T_1 F_12 ( int V_50 , void * V_51 )
{
struct V_1 * V_2 = V_51 ;
struct V_13 * V_14 = V_2 -> V_15 ;
struct V_8 * V_9 = V_2 -> V_52 ;
unsigned int V_21 ;
if ( ( F_3 ( V_14 -> V_53 + V_54 ) &
V_55 ) == 0 )
return V_56 ;
V_21 = F_3 ( V_2 -> V_3 + V_4 ) ;
if ( ( V_21 & V_25 ) == 0 )
return V_57 ;
F_2 ( V_21 & ~ V_25 , V_2 -> V_3 + V_4 ) ;
V_9 -> V_30 = F_3 ( V_2 -> V_3 + V_5 ) & 0xffff ;
F_13 ( V_9 -> V_58 , V_9 -> V_30 ) ;
V_9 -> V_58 -> V_59 |= V_60 | V_61 ;
F_14 ( V_2 , V_9 ) ;
F_2 ( V_21 , V_2 -> V_3 + V_4 ) ;
return V_57 ;
}
static int F_15 ( struct V_1 * V_2 ,
struct V_8 * V_9 ,
struct V_10 * V_11 ,
unsigned int * V_12 )
{
V_12 [ 1 ] = F_3 ( V_2 -> V_3 + V_62 ) ;
return V_11 -> V_29 ;
}
static int F_16 ( struct V_1 * V_2 ,
unsigned long V_63 )
{
struct V_64 * V_65 = F_17 ( V_2 ) ;
struct V_13 * V_14 ;
struct V_8 * V_9 ;
int V_66 ;
V_14 = F_18 ( sizeof( * V_14 ) , V_67 ) ;
if ( ! V_14 )
return - V_68 ;
V_2 -> V_15 = V_14 ;
V_66 = F_19 ( V_2 ) ;
if ( V_66 )
return V_66 ;
V_14 -> V_53 = F_20 ( V_65 , 0 ) ;
V_2 -> V_3 = F_20 ( V_65 , 1 ) ;
F_1 ( V_2 ) ;
if ( V_65 -> V_50 > 0 ) {
V_66 = F_21 ( V_65 -> V_50 , F_12 , V_69 ,
V_2 -> V_70 , V_2 ) ;
if ( V_66 == 0 )
V_2 -> V_50 = V_65 -> V_50 ;
}
V_66 = F_22 ( V_2 , 2 ) ;
if ( V_66 )
return V_66 ;
V_9 = & V_2 -> V_71 [ 0 ] ;
V_9 -> type = V_72 ;
V_9 -> V_73 = V_74 ;
V_9 -> V_75 = 32 ;
V_9 -> V_76 = 1 ;
V_9 -> V_77 = & V_78 ;
V_9 -> V_79 = F_15 ;
V_9 = & V_2 -> V_71 [ 1 ] ;
if ( V_2 -> V_50 ) {
V_2 -> V_52 = V_9 ;
V_9 -> type = V_72 | V_80 ;
V_9 -> V_73 = V_74 ;
V_9 -> V_75 = 1 ;
V_9 -> V_76 = 1 ;
V_9 -> V_77 = & V_78 ;
V_9 -> V_81 = F_4 ;
V_9 -> V_79 = F_5 ;
V_9 -> V_82 = F_6 ;
V_9 -> V_83 = F_9 ;
V_9 -> V_84 = F_11 ;
} else {
V_9 -> type = V_85 ;
}
return 0 ;
}
static void F_23 ( struct V_1 * V_2 )
{
if ( V_2 -> V_3 )
F_1 ( V_2 ) ;
if ( V_2 -> V_50 )
F_24 ( V_2 -> V_50 , V_2 ) ;
F_25 ( V_2 ) ;
}
static int F_26 ( struct V_64 * V_2 ,
const struct V_86 * V_87 )
{
return F_27 ( V_2 , & V_88 , V_87 -> V_89 ) ;
}
