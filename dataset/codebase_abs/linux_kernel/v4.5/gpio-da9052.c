static unsigned char F_1 ( unsigned V_1 )
{
return V_1 % 2 ;
}
static int F_2 ( struct V_2 * V_3 , unsigned V_1 )
{
struct V_4 * V_5 = F_3 ( V_3 ) ;
int V_6 = 0 ;
int V_7 ;
V_7 = F_4 ( V_5 -> V_8 ,
V_9 + ( V_1 >> 1 ) ) ;
if ( V_7 < 0 )
return V_7 ;
if ( F_1 ( V_1 ) ) {
V_6 = V_7 & V_10 ;
V_6 >>= 4 ;
} else {
V_6 = V_7 & V_11 ;
}
switch ( V_6 ) {
case V_12 :
if ( V_1 < V_13 )
V_7 = F_4 ( V_5 -> V_8 ,
V_14 ) ;
else
V_7 = F_4 ( V_5 -> V_8 ,
V_15 ) ;
if ( V_7 < 0 )
return V_7 ;
return ! ! ( V_7 & ( 1 << F_5 ( V_1 ) ) ) ;
case V_16 :
if ( F_1 ( V_1 ) )
return ! ! ( V_7 & V_17 ) ;
else
return ! ! ( V_7 & V_18 ) ;
default:
return - V_19 ;
}
}
static void F_6 ( struct V_2 * V_3 , unsigned V_1 , int V_20 )
{
struct V_4 * V_5 = F_3 ( V_3 ) ;
int V_7 ;
if ( F_1 ( V_1 ) ) {
V_7 = F_7 ( V_5 -> V_8 , ( V_1 >> 1 ) +
V_9 ,
V_17 ,
V_20 << V_21 ) ;
if ( V_7 != 0 )
F_8 ( V_5 -> V_8 -> V_22 ,
L_1 ,
V_7 ) ;
} else {
V_7 = F_7 ( V_5 -> V_8 , ( V_1 >> 1 ) +
V_9 ,
V_18 ,
V_20 << V_23 ) ;
if ( V_7 != 0 )
F_8 ( V_5 -> V_8 -> V_22 ,
L_2 ,
V_7 ) ;
}
}
static int F_9 ( struct V_2 * V_3 , unsigned V_1 )
{
struct V_4 * V_5 = F_3 ( V_3 ) ;
unsigned char V_24 ;
int V_7 ;
V_24 = V_12 | V_25 << 2 |
V_26 << 3 ;
if ( F_1 ( V_1 ) )
V_7 = F_7 ( V_5 -> V_8 , ( V_1 >> 1 ) +
V_9 ,
V_27 ,
( V_24 <<
V_28 ) ) ;
else
V_7 = F_7 ( V_5 -> V_8 , ( V_1 >> 1 ) +
V_9 ,
V_29 ,
V_24 ) ;
return V_7 ;
}
static int F_10 ( struct V_2 * V_3 ,
unsigned V_1 , int V_20 )
{
struct V_4 * V_5 = F_3 ( V_3 ) ;
unsigned char V_24 ;
int V_7 ;
V_24 = V_16 | V_30 << 2 |
V_20 << 3 ;
if ( F_1 ( V_1 ) )
V_7 = F_7 ( V_5 -> V_8 , ( V_1 >> 1 ) +
V_9 ,
V_27 ,
( V_24 <<
V_28 ) ) ;
else
V_7 = F_7 ( V_5 -> V_8 , ( V_1 >> 1 ) +
V_9 ,
V_29 ,
V_24 ) ;
return V_7 ;
}
static int F_11 ( struct V_2 * V_3 , T_1 V_1 )
{
struct V_4 * V_5 = F_3 ( V_3 ) ;
struct V_8 * V_8 = V_5 -> V_8 ;
int V_31 ;
V_31 = F_12 ( V_8 -> V_32 , V_33 + V_1 ) ;
return V_31 ;
}
static int F_13 ( struct V_34 * V_35 )
{
struct V_4 * V_5 ;
struct V_36 * V_37 ;
int V_7 ;
V_5 = F_14 ( & V_35 -> V_22 , sizeof( * V_5 ) , V_38 ) ;
if ( ! V_5 )
return - V_39 ;
V_5 -> V_8 = F_15 ( V_35 -> V_22 . V_40 ) ;
V_37 = F_16 ( V_5 -> V_8 -> V_22 ) ;
V_5 -> V_41 = V_42 ;
if ( V_37 && V_37 -> V_43 )
V_5 -> V_41 . V_44 = V_37 -> V_43 ;
V_7 = F_17 ( & V_5 -> V_41 , V_5 ) ;
if ( V_7 < 0 ) {
F_8 ( & V_35 -> V_22 , L_3 , V_7 ) ;
return V_7 ;
}
F_18 ( V_35 , V_5 ) ;
return 0 ;
}
static int F_19 ( struct V_34 * V_35 )
{
struct V_4 * V_5 = F_20 ( V_35 ) ;
F_21 ( & V_5 -> V_41 ) ;
return 0 ;
}
