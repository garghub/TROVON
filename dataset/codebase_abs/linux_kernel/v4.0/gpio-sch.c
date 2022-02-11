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
static int F_3 ( struct V_7 * V_8 , unsigned V_3 , unsigned V_4 )
{
struct V_1 * V_2 = F_4 ( V_8 ) ;
unsigned short V_9 , V_10 ;
T_1 V_11 ;
V_9 = F_1 ( V_2 , V_3 , V_4 ) ;
V_10 = F_2 ( V_2 , V_3 ) ;
V_11 = ! ! ( F_5 ( V_2 -> V_12 + V_9 ) & F_6 ( V_10 ) ) ;
return V_11 ;
}
static void F_7 ( struct V_7 * V_8 , unsigned V_3 , unsigned V_4 ,
int V_13 )
{
struct V_1 * V_2 = F_4 ( V_8 ) ;
unsigned short V_9 , V_10 ;
T_1 V_11 ;
V_9 = F_1 ( V_2 , V_3 , V_4 ) ;
V_10 = F_2 ( V_2 , V_3 ) ;
V_11 = F_5 ( V_2 -> V_12 + V_9 ) ;
if ( V_13 )
F_8 ( V_11 | F_6 ( V_10 ) , V_2 -> V_12 + V_9 ) ;
else
F_8 ( ( V_11 & ~ F_6 ( V_10 ) ) , V_2 -> V_12 + V_9 ) ;
}
static int F_9 ( struct V_7 * V_8 , unsigned V_14 )
{
struct V_1 * V_2 = F_4 ( V_8 ) ;
F_10 ( & V_2 -> V_15 ) ;
F_7 ( V_8 , V_14 , V_16 , 1 ) ;
F_11 ( & V_2 -> V_15 ) ;
return 0 ;
}
static int F_12 ( struct V_7 * V_8 , unsigned V_14 )
{
return F_3 ( V_8 , V_14 , V_17 ) ;
}
static void F_13 ( struct V_7 * V_8 , unsigned V_14 , int V_13 )
{
struct V_1 * V_2 = F_4 ( V_8 ) ;
F_10 ( & V_2 -> V_15 ) ;
F_7 ( V_8 , V_14 , V_17 , V_13 ) ;
F_11 ( & V_2 -> V_15 ) ;
}
static int F_14 ( struct V_7 * V_8 , unsigned V_14 ,
int V_13 )
{
struct V_1 * V_2 = F_4 ( V_8 ) ;
F_10 ( & V_2 -> V_15 ) ;
F_7 ( V_8 , V_14 , V_16 , 0 ) ;
F_11 ( & V_2 -> V_15 ) ;
F_13 ( V_8 , V_14 , V_13 ) ;
return 0 ;
}
static int F_15 ( struct V_18 * V_19 )
{
struct V_1 * V_2 ;
struct V_20 * V_21 ;
V_2 = F_16 ( & V_19 -> V_22 , sizeof( * V_2 ) , V_23 ) ;
if ( ! V_2 )
return - V_24 ;
V_21 = F_17 ( V_19 , V_25 , 0 ) ;
if ( ! V_21 )
return - V_26 ;
if ( ! F_18 ( & V_19 -> V_22 , V_21 -> V_27 , F_19 ( V_21 ) ,
V_19 -> V_28 ) )
return - V_26 ;
F_20 ( & V_2 -> V_15 ) ;
V_2 -> V_12 = V_21 -> V_27 ;
V_2 -> V_29 = V_30 ;
V_2 -> V_29 . V_31 = F_21 ( & V_19 -> V_22 ) ;
V_2 -> V_29 . V_22 = & V_19 -> V_22 ;
switch ( V_19 -> V_32 ) {
case V_33 :
V_2 -> V_34 = 0 ;
V_2 -> V_6 = 10 ;
V_2 -> V_29 . V_35 = 14 ;
F_7 ( & V_2 -> V_29 , 8 , V_36 , 1 ) ;
F_7 ( & V_2 -> V_29 , 9 , V_36 , 1 ) ;
F_7 ( & V_2 -> V_29 , 13 , V_36 , 1 ) ;
break;
case V_37 :
V_2 -> V_34 = 0 ;
V_2 -> V_6 = 5 ;
V_2 -> V_29 . V_35 = 14 ;
break;
case V_38 :
V_2 -> V_34 = 0 ;
V_2 -> V_6 = 21 ;
V_2 -> V_29 . V_35 = 30 ;
break;
case V_39 :
V_2 -> V_34 = 0 ;
V_2 -> V_6 = 2 ;
V_2 -> V_29 . V_35 = 8 ;
break;
default:
return - V_40 ;
}
F_22 ( V_19 , V_2 ) ;
return F_23 ( & V_2 -> V_29 ) ;
}
static int F_24 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = F_25 ( V_19 ) ;
F_26 ( & V_2 -> V_29 ) ;
return 0 ;
}
