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
static int F_3 ( struct V_1 * V_2 , unsigned V_3 , unsigned V_4 )
{
unsigned short V_7 , V_8 ;
T_1 V_9 ;
V_7 = F_1 ( V_2 , V_3 , V_4 ) ;
V_8 = F_2 ( V_2 , V_3 ) ;
V_9 = ! ! ( F_4 ( V_2 -> V_10 + V_7 ) & F_5 ( V_8 ) ) ;
return V_9 ;
}
static void F_6 ( struct V_1 * V_2 , unsigned V_3 , unsigned V_4 ,
int V_11 )
{
unsigned short V_7 , V_8 ;
T_1 V_9 ;
V_7 = F_1 ( V_2 , V_3 , V_4 ) ;
V_8 = F_2 ( V_2 , V_3 ) ;
V_9 = F_4 ( V_2 -> V_10 + V_7 ) ;
if ( V_11 )
F_7 ( V_9 | F_5 ( V_8 ) , V_2 -> V_10 + V_7 ) ;
else
F_7 ( ( V_9 & ~ F_5 ( V_8 ) ) , V_2 -> V_10 + V_7 ) ;
}
static int F_8 ( struct V_12 * V_13 , unsigned V_14 )
{
struct V_1 * V_2 = F_9 ( V_13 ) ;
F_10 ( & V_2 -> V_15 ) ;
F_6 ( V_2 , V_14 , V_16 , 1 ) ;
F_11 ( & V_2 -> V_15 ) ;
return 0 ;
}
static int F_12 ( struct V_12 * V_13 , unsigned V_14 )
{
struct V_1 * V_2 = F_9 ( V_13 ) ;
return F_3 ( V_2 , V_14 , V_17 ) ;
}
static void F_13 ( struct V_12 * V_13 , unsigned V_14 , int V_11 )
{
struct V_1 * V_2 = F_9 ( V_13 ) ;
F_10 ( & V_2 -> V_15 ) ;
F_6 ( V_2 , V_14 , V_17 , V_11 ) ;
F_11 ( & V_2 -> V_15 ) ;
}
static int F_14 ( struct V_12 * V_13 , unsigned V_14 ,
int V_11 )
{
struct V_1 * V_2 = F_9 ( V_13 ) ;
F_10 ( & V_2 -> V_15 ) ;
F_6 ( V_2 , V_14 , V_16 , 0 ) ;
F_11 ( & V_2 -> V_15 ) ;
F_13 ( V_13 , V_14 , V_11 ) ;
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
V_2 -> V_10 = V_21 -> V_27 ;
V_2 -> V_29 = V_30 ;
V_2 -> V_29 . V_31 = F_21 ( & V_19 -> V_22 ) ;
V_2 -> V_29 . V_32 = & V_19 -> V_22 ;
switch ( V_19 -> V_33 ) {
case V_34 :
V_2 -> V_35 = 0 ;
V_2 -> V_6 = 10 ;
V_2 -> V_29 . V_36 = 14 ;
F_6 ( V_2 , 8 , V_37 , 1 ) ;
F_6 ( V_2 , 9 , V_37 , 1 ) ;
F_6 ( V_2 , 13 , V_37 , 1 ) ;
break;
case V_38 :
V_2 -> V_35 = 0 ;
V_2 -> V_6 = 5 ;
V_2 -> V_29 . V_36 = 14 ;
break;
case V_39 :
V_2 -> V_35 = 0 ;
V_2 -> V_6 = 21 ;
V_2 -> V_29 . V_36 = 30 ;
break;
case V_40 :
V_2 -> V_35 = 0 ;
V_2 -> V_6 = 2 ;
V_2 -> V_29 . V_36 = 8 ;
break;
default:
return - V_41 ;
}
F_22 ( V_19 , V_2 ) ;
return F_23 ( & V_19 -> V_22 , & V_2 -> V_29 , V_2 ) ;
}
