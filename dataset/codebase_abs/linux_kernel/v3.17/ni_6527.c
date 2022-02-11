static void F_1 ( struct V_1 * V_2 ,
unsigned int V_3 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
if ( V_3 != V_5 -> V_7 ) {
F_2 ( V_3 & 0xff , V_2 -> V_8 + F_3 ( 0 ) ) ;
F_2 ( ( V_3 >> 8 ) & 0xff ,
V_2 -> V_8 + F_3 ( 1 ) ) ;
F_2 ( ( V_3 >> 16 ) & 0x0f ,
V_2 -> V_8 + F_3 ( 2 ) ) ;
F_2 ( V_9 , V_2 -> V_8 + V_10 ) ;
V_5 -> V_7 = V_3 ;
}
}
static void F_4 ( struct V_1 * V_2 ,
unsigned int V_3 )
{
F_2 ( V_3 & 0xff , V_2 -> V_8 + F_5 ( 0 ) ) ;
F_2 ( ( V_3 >> 8 ) & 0xff , V_2 -> V_8 + F_5 ( 1 ) ) ;
F_2 ( ( V_3 >> 16 ) & 0xff , V_2 -> V_8 + F_5 ( 2 ) ) ;
}
static int F_6 ( struct V_1 * V_2 ,
struct V_11 * V_12 ,
struct V_13 * V_14 ,
unsigned int * V_15 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
unsigned int V_16 = F_7 ( V_14 -> V_17 ) ;
unsigned int V_18 ;
switch ( V_15 [ 0 ] ) {
case V_19 :
V_18 = ( V_15 [ 1 ] + 100 ) / 200 ;
V_15 [ 1 ] = V_18 * 200 ;
if ( V_18 ) {
F_1 ( V_2 , V_18 ) ;
V_5 -> V_20 |= 1 << V_16 ;
} else {
V_5 -> V_20 &= ~ ( 1 << V_16 ) ;
}
F_4 ( V_2 , V_5 -> V_20 ) ;
break;
default:
return - V_21 ;
}
return V_14 -> V_22 ;
}
static int F_8 ( struct V_1 * V_2 ,
struct V_11 * V_12 ,
struct V_13 * V_14 ,
unsigned int * V_15 )
{
unsigned int V_3 ;
V_3 = F_9 ( V_2 -> V_8 + F_10 ( 0 ) ) ;
V_3 |= ( F_9 ( V_2 -> V_8 + F_10 ( 1 ) ) << 8 ) ;
V_3 |= ( F_9 ( V_2 -> V_8 + F_10 ( 2 ) ) << 16 ) ;
V_15 [ 1 ] = V_3 ;
return V_14 -> V_22 ;
}
static int F_11 ( struct V_1 * V_2 ,
struct V_11 * V_12 ,
struct V_13 * V_14 ,
unsigned int * V_15 )
{
unsigned int V_23 ;
V_23 = F_12 ( V_12 , V_15 ) ;
if ( V_23 ) {
unsigned int V_3 = V_12 -> V_24 ^ 0xffffff ;
if ( V_23 & 0x0000ff )
F_2 ( V_3 & 0xff , V_2 -> V_8 + F_13 ( 0 ) ) ;
if ( V_23 & 0x00ff00 )
F_2 ( ( V_3 >> 8 ) & 0xff ,
V_2 -> V_8 + F_13 ( 1 ) ) ;
if ( V_23 & 0xff0000 )
F_2 ( ( V_3 >> 16 ) & 0xff ,
V_2 -> V_8 + F_13 ( 2 ) ) ;
}
V_15 [ 1 ] = V_12 -> V_24 ;
return V_14 -> V_22 ;
}
static T_1 F_14 ( int V_25 , void * V_26 )
{
struct V_1 * V_2 = V_26 ;
struct V_11 * V_12 = V_2 -> V_27 ;
unsigned int V_28 ;
V_28 = F_9 ( V_2 -> V_8 + V_29 ) ;
if ( ! ( V_28 & V_30 ) )
return V_31 ;
if ( V_28 & V_32 ) {
F_15 ( V_12 , 0 ) ;
V_12 -> V_33 -> V_34 |= V_35 ;
F_16 ( V_2 , V_12 ) ;
}
F_2 ( V_36 , V_2 -> V_8 + V_10 ) ;
return V_37 ;
}
static int F_17 ( struct V_1 * V_2 ,
struct V_11 * V_12 ,
struct V_38 * V_39 )
{
int V_40 = 0 ;
V_40 |= F_18 ( & V_39 -> V_41 , V_42 ) ;
V_40 |= F_18 ( & V_39 -> V_43 , V_44 ) ;
V_40 |= F_18 ( & V_39 -> V_45 , V_46 ) ;
V_40 |= F_18 ( & V_39 -> V_47 , V_48 ) ;
V_40 |= F_18 ( & V_39 -> V_49 , V_48 ) ;
if ( V_40 )
return 1 ;
if ( V_40 )
return 2 ;
V_40 |= F_19 ( & V_39 -> V_50 , 0 ) ;
V_40 |= F_19 ( & V_39 -> V_51 , 0 ) ;
V_40 |= F_19 ( & V_39 -> V_52 , 0 ) ;
V_40 |= F_19 ( & V_39 -> V_53 , V_39 -> V_54 ) ;
V_40 |= F_19 ( & V_39 -> V_55 , 0 ) ;
if ( V_40 )
return 3 ;
if ( V_40 )
return 4 ;
return 0 ;
}
static int F_20 ( struct V_1 * V_2 ,
struct V_11 * V_12 )
{
F_2 ( V_36 , V_2 -> V_8 + V_10 ) ;
F_2 ( V_56 , V_2 -> V_8 + V_57 ) ;
return 0 ;
}
static int F_21 ( struct V_1 * V_2 ,
struct V_11 * V_12 )
{
F_2 ( V_58 , V_2 -> V_8 + V_57 ) ;
return 0 ;
}
static int F_22 ( struct V_1 * V_2 ,
struct V_11 * V_12 ,
struct V_13 * V_14 , unsigned int * V_15 )
{
V_15 [ 1 ] = 0 ;
return V_14 -> V_22 ;
}
static void F_23 ( struct V_1 * V_2 ,
unsigned int V_23 ,
unsigned int V_59 ,
unsigned int V_60 )
{
unsigned int V_61 ;
V_59 &= V_23 ;
V_60 &= V_23 ;
for ( V_61 = 0 ; V_61 < 2 ; V_61 ++ ) {
if ( V_23 & 0xff ) {
if ( ~ V_23 & 0xff ) {
V_59 |= F_9 ( V_2 -> V_8 +
F_24 ( V_61 ) ) &
( ~ V_23 & 0xff ) ;
V_60 |= F_9 ( V_2 -> V_8 +
F_25 ( V_61 ) ) &
( ~ V_23 & 0xff ) ;
}
F_2 ( V_59 & 0xff ,
V_2 -> V_8 + F_24 ( V_61 ) ) ;
F_2 ( V_60 & 0xff ,
V_2 -> V_8 + F_25 ( V_61 ) ) ;
}
V_59 >>= 8 ;
V_60 >>= 8 ;
V_23 >>= 8 ;
}
}
static int F_26 ( struct V_1 * V_2 ,
struct V_11 * V_12 ,
struct V_13 * V_14 ,
unsigned int * V_15 )
{
unsigned int V_23 = 0xffffffff ;
unsigned int V_59 , V_60 , V_62 ;
switch ( V_15 [ 0 ] ) {
case V_63 :
if ( V_14 -> V_22 != 3 )
return - V_21 ;
V_59 = V_15 [ 1 ] ;
V_60 = V_15 [ 2 ] ;
F_23 ( V_2 , V_23 , V_59 , V_60 ) ;
break;
case V_64 :
if ( V_15 [ 1 ] != 0 )
return - V_21 ;
switch ( V_15 [ 2 ] ) {
case V_65 :
V_59 = 0 ;
V_60 = 0 ;
break;
case V_66 :
V_62 = V_15 [ 3 ] ;
if ( V_62 >= V_12 -> V_67 ) {
V_23 = 0 ;
V_59 = 0 ;
V_60 = 0 ;
} else {
V_23 <<= V_62 ;
V_59 = V_15 [ 4 ] << V_62 ;
V_60 = V_15 [ 5 ] << V_62 ;
}
break;
default:
return - V_21 ;
}
F_23 ( V_2 , V_23 , V_59 , V_60 ) ;
break;
default:
return - V_21 ;
}
return V_14 -> V_22 ;
}
static void F_27 ( struct V_1 * V_2 )
{
F_4 ( V_2 , 0 ) ;
F_23 ( V_2 , 0xffffffff , 0 , 0 ) ;
F_2 ( V_36 | V_68 ,
V_2 -> V_8 + V_10 ) ;
F_2 ( V_58 , V_2 -> V_8 + V_57 ) ;
}
static int F_28 ( struct V_1 * V_2 ,
unsigned long V_69 )
{
struct V_70 * V_71 = F_29 ( V_2 ) ;
const struct V_72 * V_73 = NULL ;
struct V_4 * V_5 ;
struct V_11 * V_12 ;
int V_74 ;
if ( V_69 < F_30 ( V_75 ) )
V_73 = & V_75 [ V_69 ] ;
if ( ! V_73 )
return - V_76 ;
V_2 -> V_77 = V_73 ;
V_2 -> V_78 = V_73 -> V_79 ;
V_5 = F_31 ( V_2 , sizeof( * V_5 ) ) ;
if ( ! V_5 )
return - V_80 ;
V_74 = F_32 ( V_2 ) ;
if ( V_74 )
return V_74 ;
V_2 -> V_8 = F_33 ( V_71 , 1 ) ;
if ( ! V_2 -> V_8 )
return - V_80 ;
if ( F_9 ( V_2 -> V_8 + V_81 ) != 0x27 )
return - V_76 ;
F_27 ( V_2 ) ;
V_74 = F_34 ( V_71 -> V_25 , F_14 , V_82 ,
V_2 -> V_78 , V_2 ) ;
if ( V_74 == 0 )
V_2 -> V_25 = V_71 -> V_25 ;
V_74 = F_35 ( V_2 , 3 ) ;
if ( V_74 )
return V_74 ;
V_12 = & V_2 -> V_83 [ 0 ] ;
V_12 -> type = V_84 ;
V_12 -> V_85 = V_86 ;
V_12 -> V_67 = 24 ;
V_12 -> V_87 = 1 ;
V_12 -> V_88 = & V_89 ;
V_12 -> V_90 = F_6 ;
V_12 -> V_91 = F_8 ;
V_12 = & V_2 -> V_83 [ 1 ] ;
V_12 -> type = V_92 ;
V_12 -> V_85 = V_93 ;
V_12 -> V_67 = 24 ;
V_12 -> V_87 = 1 ;
V_12 -> V_88 = & V_89 ;
V_12 -> V_91 = F_11 ;
V_12 = & V_2 -> V_83 [ 2 ] ;
if ( V_2 -> V_25 ) {
V_2 -> V_27 = V_12 ;
V_12 -> type = V_84 ;
V_12 -> V_85 = V_86 | V_94 ;
V_12 -> V_67 = 1 ;
V_12 -> V_87 = 1 ;
V_12 -> V_88 = & V_89 ;
V_12 -> V_90 = F_26 ;
V_12 -> V_91 = F_22 ;
V_12 -> V_95 = 1 ;
V_12 -> V_96 = F_17 ;
V_12 -> V_97 = F_20 ;
V_12 -> V_98 = F_21 ;
} else {
V_12 -> type = V_99 ;
}
return 0 ;
}
static void F_36 ( struct V_1 * V_2 )
{
if ( V_2 -> V_8 )
F_27 ( V_2 ) ;
if ( V_2 -> V_25 )
F_37 ( V_2 -> V_25 , V_2 ) ;
if ( V_2 -> V_8 )
F_38 ( V_2 -> V_8 ) ;
F_39 ( V_2 ) ;
}
static int F_40 ( struct V_70 * V_2 ,
const struct V_100 * V_101 )
{
return F_41 ( V_2 , & V_102 , V_101 -> V_103 ) ;
}
