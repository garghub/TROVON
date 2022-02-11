static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * div = F_2 ( V_2 ) ;
struct V_4 * V_5 = & div -> V_5 ;
T_1 V_6 ;
if ( div -> V_7 )
F_3 ( div -> V_7 ) ;
V_6 = F_4 ( div -> V_8 + V_5 -> V_9 ) ;
V_6 >>= V_5 -> V_10 ;
if ( div -> V_7 )
F_5 ( div -> V_7 ) ;
return ( V_6 & 0x1 ) ;
}
static int F_6 ( struct V_1 * V_2 )
{
struct V_3 * div = F_2 ( V_2 ) ;
struct V_4 * V_5 = & div -> V_5 ;
T_1 V_6 ;
if ( div -> V_7 )
F_3 ( div -> V_7 ) ;
V_6 = F_4 ( div -> V_8 + V_5 -> V_9 ) ;
V_6 |= F_7 ( V_5 -> V_10 ) ;
F_8 ( V_6 , div -> V_8 + V_5 -> V_9 ) ;
if ( div -> V_7 )
F_5 ( div -> V_7 ) ;
return 0 ;
}
static void F_9 ( struct V_1 * V_2 )
{
struct V_3 * div = F_2 ( V_2 ) ;
struct V_4 * V_5 = & div -> V_5 ;
T_1 V_6 ;
if ( div -> V_7 )
F_3 ( div -> V_7 ) ;
V_6 = F_4 ( div -> V_8 + V_5 -> V_9 ) ;
V_6 &= ~ F_7 ( V_5 -> V_10 ) ;
F_8 ( V_6 , div -> V_8 + V_5 -> V_9 ) ;
if ( div -> V_7 )
F_5 ( div -> V_7 ) ;
}
static int F_10 ( struct V_1 * V_2 , T_2 V_11 )
{
struct V_3 * div = F_2 ( V_2 ) ;
struct V_4 * V_5 = & div -> V_5 ;
T_1 V_6 ;
if ( div -> V_7 )
F_3 ( div -> V_7 ) ;
V_6 = F_4 ( div -> V_8 + V_5 -> V_12 ) ;
if ( V_11 == 0 )
V_6 &= ~ F_7 ( V_5 -> V_13 ) ;
else
V_6 |= F_7 ( V_5 -> V_13 ) ;
F_8 ( V_6 , div -> V_8 + V_5 -> V_12 ) ;
if ( V_11 > 0 ) {
V_6 = F_4 ( div -> V_8 + V_5 -> V_14 ) ;
V_6 &= ~ ( V_15 << V_5 -> V_16 ) ;
V_6 |= ( V_11 - 1 ) << V_5 -> V_16 ;
F_8 ( V_6 , div -> V_8 + V_5 -> V_14 ) ;
}
if ( div -> V_7 )
F_5 ( div -> V_7 ) ;
return 0 ;
}
static T_2 F_11 ( struct V_1 * V_2 )
{
struct V_3 * div = F_2 ( V_2 ) ;
struct V_4 * V_5 = & div -> V_5 ;
T_1 V_6 ;
T_2 V_11 = 0 ;
if ( div -> V_7 )
F_3 ( div -> V_7 ) ;
V_6 = F_4 ( div -> V_8 + V_5 -> V_12 ) ;
V_6 &= F_7 ( V_5 -> V_13 ) ;
if ( V_6 ) {
V_6 = F_4 ( div -> V_8 + V_5 -> V_14 ) ;
V_6 >>= V_5 -> V_16 ;
V_6 &= V_15 ;
V_11 = 1 + V_6 ;
}
if ( div -> V_7 )
F_5 ( div -> V_7 ) ;
return V_11 ;
}
static unsigned long F_12 ( struct V_1 * V_2 ,
unsigned long V_17 )
{
struct V_3 * div = F_2 ( V_2 ) ;
struct V_4 * V_5 = & div -> V_5 ;
T_1 V_18 , V_19 , V_20 = 1 ;
if ( div -> V_7 )
F_3 ( div -> V_7 ) ;
V_18 = F_4 ( div -> V_8 + V_5 -> V_21 ) &
( 1 << V_5 -> V_22 ) ;
V_19 = F_4 ( div -> V_8 + V_5 -> V_23 ) &
( 1 << V_5 -> V_24 ) ;
if ( V_19 != 0 ) {
V_20 = 3 ;
} else if ( V_18 == 0 ) {
V_20 = 1 ;
} else {
T_1 V_6 ;
V_6 = F_4 ( div -> V_8 + V_5 -> V_25 ) ;
V_6 >>= V_5 -> V_26 ;
V_6 &= V_27 ;
V_20 = V_28 [ V_6 ] ;
}
if ( div -> V_7 )
F_5 ( div -> V_7 ) ;
return V_17 / V_20 ;
}
struct V_29 * T_3
F_13 ( const struct V_4 * V_5 ,
void T_4 * V_8 , const char * V_30 , T_2 V_31 ,
const char * * V_32 , int V_33 ,
unsigned long V_34 , T_5 * V_7 )
{
const struct V_35 * V_36 = & V_37 ;
const struct V_35 * V_38 = & V_39 ;
const struct V_35 * V_40 = & V_41 ;
struct V_3 * div ;
div = F_14 ( sizeof( * div ) , V_42 ) ;
if ( ! div )
return F_15 ( - V_43 ) ;
memcpy ( & div -> V_5 , V_5 , sizeof( * V_5 ) ) ;
div -> V_8 = V_8 ;
div -> V_7 = V_7 ;
if ( ( V_31 & V_44 ) == 0 )
V_40 = NULL ;
if ( ( V_31 & V_45 ) == 0 )
V_36 = NULL ;
return F_16 ( NULL , V_30 , V_32 , V_33 ,
& div -> V_2 , V_36 , & div -> V_2 , V_38 ,
& div -> V_2 , V_40 , V_34 ) ;
}
