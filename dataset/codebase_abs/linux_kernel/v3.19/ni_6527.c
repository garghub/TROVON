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
F_15 ( V_12 , & V_12 -> V_24 , 1 ) ;
F_16 ( V_2 , V_12 ) ;
}
F_2 ( V_33 , V_2 -> V_8 + V_10 ) ;
return V_34 ;
}
static int F_17 ( struct V_1 * V_2 ,
struct V_11 * V_12 ,
struct V_35 * V_36 )
{
int V_37 = 0 ;
V_37 |= F_18 ( & V_36 -> V_38 , V_39 ) ;
V_37 |= F_18 ( & V_36 -> V_40 , V_41 ) ;
V_37 |= F_18 ( & V_36 -> V_42 , V_43 ) ;
V_37 |= F_18 ( & V_36 -> V_44 , V_45 ) ;
V_37 |= F_18 ( & V_36 -> V_46 , V_45 ) ;
if ( V_37 )
return 1 ;
V_37 |= F_19 ( & V_36 -> V_47 , 0 ) ;
V_37 |= F_19 ( & V_36 -> V_48 , 0 ) ;
V_37 |= F_19 ( & V_36 -> V_49 , 0 ) ;
V_37 |= F_19 ( & V_36 -> V_50 , V_36 -> V_51 ) ;
V_37 |= F_19 ( & V_36 -> V_52 , 0 ) ;
if ( V_37 )
return 3 ;
return 0 ;
}
static int F_20 ( struct V_1 * V_2 ,
struct V_11 * V_12 )
{
F_2 ( V_33 , V_2 -> V_8 + V_10 ) ;
F_2 ( V_53 , V_2 -> V_8 + V_54 ) ;
return 0 ;
}
static int F_21 ( struct V_1 * V_2 ,
struct V_11 * V_12 )
{
F_2 ( V_55 , V_2 -> V_8 + V_54 ) ;
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
unsigned int V_56 ,
unsigned int V_57 )
{
unsigned int V_58 ;
V_56 &= V_23 ;
V_57 &= V_23 ;
for ( V_58 = 0 ; V_58 < 2 ; V_58 ++ ) {
if ( V_23 & 0xff ) {
if ( ~ V_23 & 0xff ) {
V_56 |= F_9 ( V_2 -> V_8 +
F_24 ( V_58 ) ) &
( ~ V_23 & 0xff ) ;
V_57 |= F_9 ( V_2 -> V_8 +
F_25 ( V_58 ) ) &
( ~ V_23 & 0xff ) ;
}
F_2 ( V_56 & 0xff ,
V_2 -> V_8 + F_24 ( V_58 ) ) ;
F_2 ( V_57 & 0xff ,
V_2 -> V_8 + F_25 ( V_58 ) ) ;
}
V_56 >>= 8 ;
V_57 >>= 8 ;
V_23 >>= 8 ;
}
}
static int F_26 ( struct V_1 * V_2 ,
struct V_11 * V_12 ,
struct V_13 * V_14 ,
unsigned int * V_15 )
{
unsigned int V_23 = 0xffffffff ;
unsigned int V_56 , V_57 , V_59 ;
switch ( V_15 [ 0 ] ) {
case V_60 :
if ( V_14 -> V_22 != 3 )
return - V_21 ;
V_56 = V_15 [ 1 ] ;
V_57 = V_15 [ 2 ] ;
F_23 ( V_2 , V_23 , V_56 , V_57 ) ;
break;
case V_61 :
if ( V_15 [ 1 ] != 0 )
return - V_21 ;
switch ( V_15 [ 2 ] ) {
case V_62 :
V_56 = 0 ;
V_57 = 0 ;
break;
case V_63 :
V_59 = V_15 [ 3 ] ;
if ( V_59 >= V_12 -> V_64 ) {
V_23 = 0 ;
V_56 = 0 ;
V_57 = 0 ;
} else {
V_23 <<= V_59 ;
V_56 = V_15 [ 4 ] << V_59 ;
V_57 = V_15 [ 5 ] << V_59 ;
}
break;
default:
return - V_21 ;
}
F_23 ( V_2 , V_23 , V_56 , V_57 ) ;
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
F_2 ( V_33 | V_65 ,
V_2 -> V_8 + V_10 ) ;
F_2 ( V_55 , V_2 -> V_8 + V_54 ) ;
}
static int F_28 ( struct V_1 * V_2 ,
unsigned long V_66 )
{
struct V_67 * V_68 = F_29 ( V_2 ) ;
const struct V_69 * V_70 = NULL ;
struct V_4 * V_5 ;
struct V_11 * V_12 ;
int V_71 ;
if ( V_66 < F_30 ( V_72 ) )
V_70 = & V_72 [ V_66 ] ;
if ( ! V_70 )
return - V_73 ;
V_2 -> V_74 = V_70 ;
V_2 -> V_75 = V_70 -> V_76 ;
V_5 = F_31 ( V_2 , sizeof( * V_5 ) ) ;
if ( ! V_5 )
return - V_77 ;
V_71 = F_32 ( V_2 ) ;
if ( V_71 )
return V_71 ;
V_2 -> V_8 = F_33 ( V_68 , 1 ) ;
if ( ! V_2 -> V_8 )
return - V_77 ;
if ( F_9 ( V_2 -> V_8 + V_78 ) != 0x27 )
return - V_73 ;
F_27 ( V_2 ) ;
V_71 = F_34 ( V_68 -> V_25 , F_14 , V_79 ,
V_2 -> V_75 , V_2 ) ;
if ( V_71 == 0 )
V_2 -> V_25 = V_68 -> V_25 ;
V_71 = F_35 ( V_2 , 3 ) ;
if ( V_71 )
return V_71 ;
V_12 = & V_2 -> V_80 [ 0 ] ;
V_12 -> type = V_81 ;
V_12 -> V_82 = V_83 ;
V_12 -> V_64 = 24 ;
V_12 -> V_84 = 1 ;
V_12 -> V_85 = & V_86 ;
V_12 -> V_87 = F_6 ;
V_12 -> V_88 = F_8 ;
V_12 = & V_2 -> V_80 [ 1 ] ;
V_12 -> type = V_89 ;
V_12 -> V_82 = V_90 ;
V_12 -> V_64 = 24 ;
V_12 -> V_84 = 1 ;
V_12 -> V_85 = & V_86 ;
V_12 -> V_88 = F_11 ;
V_12 = & V_2 -> V_80 [ 2 ] ;
if ( V_2 -> V_25 ) {
V_2 -> V_27 = V_12 ;
V_12 -> type = V_81 ;
V_12 -> V_82 = V_83 | V_91 ;
V_12 -> V_64 = 1 ;
V_12 -> V_84 = 1 ;
V_12 -> V_85 = & V_86 ;
V_12 -> V_87 = F_26 ;
V_12 -> V_88 = F_22 ;
V_12 -> V_92 = 1 ;
V_12 -> V_93 = F_17 ;
V_12 -> V_94 = F_20 ;
V_12 -> V_95 = F_21 ;
} else {
V_12 -> type = V_96 ;
}
return 0 ;
}
static void F_36 ( struct V_1 * V_2 )
{
if ( V_2 -> V_8 )
F_27 ( V_2 ) ;
F_37 ( V_2 ) ;
}
static int F_38 ( struct V_67 * V_2 ,
const struct V_97 * V_98 )
{
return F_39 ( V_2 , & V_99 , V_98 -> V_100 ) ;
}
