static unsigned F_1 ( struct V_1 * V_2 , unsigned V_3 ,
unsigned V_4 )
{
unsigned V_5 = 0 ;
if ( V_3 >= V_2 -> V_6 ) {
V_3 -= V_2 -> V_6 ;
V_5 += 0x20 ;
}
return V_5 + V_4 + V_3 / 8 ;
}
static unsigned F_2 ( struct V_1 * V_2 , unsigned V_3 )
{
if ( V_3 >= V_2 -> V_6 )
V_3 -= V_2 -> V_6 ;
return V_3 % 8 ;
}
static void F_3 ( struct V_1 * V_2 , unsigned V_3 )
{
unsigned short V_7 , V_8 ;
T_1 V_9 ;
F_4 ( & V_2 -> V_10 ) ;
V_7 = F_1 ( V_2 , V_3 , V_11 ) ;
V_8 = F_2 ( V_2 , V_3 ) ;
V_9 = F_5 ( V_2 -> V_12 + V_7 ) ;
if ( ! ( V_9 & ( 1 << V_8 ) ) )
F_6 ( V_9 | ( 1 << V_8 ) , V_2 -> V_12 + V_7 ) ;
F_7 ( & V_2 -> V_10 ) ;
}
static int F_8 ( struct V_13 * V_14 , unsigned V_15 )
{
struct V_1 * V_2 = F_9 ( V_14 ) ;
T_1 V_16 ;
unsigned short V_7 , V_8 ;
F_4 ( & V_2 -> V_10 ) ;
V_7 = F_1 ( V_2 , V_15 , V_17 ) ;
V_8 = F_2 ( V_2 , V_15 ) ;
V_16 = F_5 ( V_2 -> V_12 + V_7 ) ;
if ( ! ( V_16 & ( 1 << V_8 ) ) )
F_6 ( V_16 | ( 1 << V_8 ) , V_2 -> V_12 + V_7 ) ;
F_7 ( & V_2 -> V_10 ) ;
return 0 ;
}
static int F_10 ( struct V_13 * V_14 , unsigned V_15 )
{
struct V_1 * V_2 = F_9 ( V_14 ) ;
int V_18 ;
unsigned short V_7 , V_8 ;
V_7 = F_1 ( V_2 , V_15 , V_19 ) ;
V_8 = F_2 ( V_2 , V_15 ) ;
V_18 = ! ! ( F_5 ( V_2 -> V_12 + V_7 ) & ( 1 << V_8 ) ) ;
return V_18 ;
}
static void F_11 ( struct V_13 * V_14 , unsigned V_15 , int V_20 )
{
struct V_1 * V_2 = F_9 ( V_14 ) ;
T_1 V_21 ;
unsigned short V_7 , V_8 ;
F_4 ( & V_2 -> V_10 ) ;
V_7 = F_1 ( V_2 , V_15 , V_19 ) ;
V_8 = F_2 ( V_2 , V_15 ) ;
V_21 = F_5 ( V_2 -> V_12 + V_7 ) ;
if ( V_20 )
F_6 ( V_21 | ( 1 << V_8 ) , V_2 -> V_12 + V_7 ) ;
else
F_6 ( ( V_21 & ~ ( 1 << V_8 ) ) , V_2 -> V_12 + V_7 ) ;
F_7 ( & V_2 -> V_10 ) ;
}
static int F_12 ( struct V_13 * V_14 , unsigned V_15 ,
int V_20 )
{
struct V_1 * V_2 = F_9 ( V_14 ) ;
T_1 V_16 ;
unsigned short V_7 , V_8 ;
F_4 ( & V_2 -> V_10 ) ;
V_7 = F_1 ( V_2 , V_15 , V_17 ) ;
V_8 = F_2 ( V_2 , V_15 ) ;
V_16 = F_5 ( V_2 -> V_12 + V_7 ) ;
if ( V_16 & ( 1 << V_8 ) )
F_6 ( V_16 & ~ ( 1 << V_8 ) , V_2 -> V_12 + V_7 ) ;
F_7 ( & V_2 -> V_10 ) ;
F_11 ( V_14 , V_15 , V_20 ) ;
return 0 ;
}
static int F_13 ( struct V_22 * V_23 )
{
struct V_1 * V_2 ;
struct V_24 * V_18 ;
V_2 = F_14 ( & V_23 -> V_25 , sizeof( * V_2 ) , V_26 ) ;
if ( ! V_2 )
return - V_27 ;
V_18 = F_15 ( V_23 , V_28 , 0 ) ;
if ( ! V_18 )
return - V_29 ;
if ( ! F_16 ( & V_23 -> V_25 , V_18 -> V_30 , F_17 ( V_18 ) ,
V_23 -> V_31 ) )
return - V_29 ;
F_18 ( & V_2 -> V_10 ) ;
V_2 -> V_12 = V_18 -> V_30 ;
V_2 -> V_32 = V_33 ;
V_2 -> V_32 . V_34 = F_19 ( & V_23 -> V_25 ) ;
V_2 -> V_32 . V_25 = & V_23 -> V_25 ;
switch ( V_23 -> V_35 ) {
case V_36 :
V_2 -> V_37 = 0 ;
V_2 -> V_6 = 10 ;
V_2 -> V_32 . V_38 = 14 ;
F_3 ( V_2 , 8 ) ;
F_3 ( V_2 , 9 ) ;
F_3 ( V_2 , 13 ) ;
break;
case V_39 :
V_2 -> V_37 = 0 ;
V_2 -> V_6 = 5 ;
V_2 -> V_32 . V_38 = 14 ;
break;
case V_40 :
V_2 -> V_37 = 0 ;
V_2 -> V_6 = 21 ;
V_2 -> V_32 . V_38 = 30 ;
break;
default:
return - V_41 ;
}
F_20 ( V_23 , V_2 ) ;
return F_21 ( & V_2 -> V_32 ) ;
}
static int F_22 ( struct V_22 * V_23 )
{
struct V_1 * V_2 = F_23 ( V_23 ) ;
F_24 ( & V_2 -> V_32 ) ;
return 0 ;
}
