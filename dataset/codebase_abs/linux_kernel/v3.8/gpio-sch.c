static int F_1 ( struct V_1 * V_2 , unsigned V_3 )
{
T_1 V_4 ;
unsigned short V_5 , V_6 ;
F_2 ( & V_7 ) ;
V_5 = V_8 + V_3 / 8 ;
V_6 = V_3 % 8 ;
V_4 = F_3 ( V_9 + V_5 ) ;
if ( ! ( V_4 & ( 1 << V_6 ) ) )
F_4 ( V_4 | ( 1 << V_6 ) , V_9 + V_5 ) ;
F_5 ( & V_7 ) ;
return 0 ;
}
static int F_6 ( struct V_1 * V_2 , unsigned V_3 )
{
int V_10 ;
unsigned short V_5 , V_6 ;
V_5 = V_11 + V_3 / 8 ;
V_6 = V_3 % 8 ;
V_10 = ! ! ( F_3 ( V_9 + V_5 ) & ( 1 << V_6 ) ) ;
return V_10 ;
}
static void F_7 ( struct V_1 * V_2 , unsigned V_3 , int V_12 )
{
T_1 V_13 ;
unsigned short V_5 , V_6 ;
F_2 ( & V_7 ) ;
V_5 = V_11 + V_3 / 8 ;
V_6 = V_3 % 8 ;
V_13 = F_3 ( V_9 + V_5 ) ;
if ( V_12 )
F_4 ( V_13 | ( 1 << V_6 ) , V_9 + V_5 ) ;
else
F_4 ( ( V_13 & ~ ( 1 << V_6 ) ) , V_9 + V_5 ) ;
F_5 ( & V_7 ) ;
}
static int F_8 ( struct V_1 * V_2 ,
unsigned V_3 , int V_12 )
{
T_1 V_4 ;
unsigned short V_5 , V_6 ;
F_7 ( V_2 , V_3 , V_12 ) ;
F_2 ( & V_7 ) ;
V_5 = V_8 + V_3 / 8 ;
V_6 = V_3 % 8 ;
V_4 = F_3 ( V_9 + V_5 ) ;
if ( V_4 & ( 1 << V_6 ) )
F_4 ( V_4 & ~ ( 1 << V_6 ) , V_9 + V_5 ) ;
F_5 ( & V_7 ) ;
return 0 ;
}
static int F_9 ( struct V_1 * V_2 ,
unsigned V_3 )
{
T_1 V_4 ;
F_2 ( & V_7 ) ;
V_4 = F_3 ( V_9 + V_14 ) ;
if ( ! ( V_4 & ( 1 << V_3 ) ) )
F_4 ( V_4 | ( 1 << V_3 ) , V_9 + V_14 ) ;
F_5 ( & V_7 ) ;
return 0 ;
}
static int F_10 ( struct V_1 * V_2 , unsigned V_3 )
{
return ! ! ( F_3 ( V_9 + V_15 ) & ( 1 << V_3 ) ) ;
}
static void F_11 ( struct V_1 * V_2 ,
unsigned V_3 , int V_12 )
{
T_1 V_13 ;
F_2 ( & V_7 ) ;
V_13 = F_3 ( V_9 + V_15 ) ;
if ( V_12 )
F_4 ( V_13 | ( 1 << V_3 ) , V_9 + V_15 ) ;
else
F_4 ( ( V_13 & ~ ( 1 << V_3 ) ) , V_9 + V_15 ) ;
F_5 ( & V_7 ) ;
}
static int F_12 ( struct V_1 * V_2 ,
unsigned V_3 , int V_12 )
{
T_1 V_4 ;
F_11 ( V_2 , V_3 , V_12 ) ;
F_2 ( & V_7 ) ;
V_4 = F_3 ( V_9 + V_14 ) ;
if ( V_4 & ( 1 << V_3 ) )
F_4 ( V_4 & ~ ( 1 << V_3 ) , V_9 + V_14 ) ;
F_5 ( & V_7 ) ;
return 0 ;
}
static int F_13 ( struct V_16 * V_17 )
{
struct V_18 * V_10 ;
int V_19 , V_20 ;
V_20 = V_17 -> V_20 ;
if ( ! V_20 )
return - V_21 ;
V_10 = F_14 ( V_17 , V_22 , 0 ) ;
if ( ! V_10 )
return - V_23 ;
if ( ! F_15 ( V_10 -> V_24 , F_16 ( V_10 ) , V_17 -> V_25 ) )
return - V_23 ;
V_9 = V_10 -> V_24 ;
switch ( V_20 ) {
case V_26 :
V_27 . V_28 = 0 ;
V_27 . V_29 = 10 ;
V_30 . V_28 = 10 ;
V_30 . V_29 = 4 ;
F_4 ( 0x3 , V_9 + V_31 + 1 ) ;
F_4 ( 0x8 , V_9 + V_32 ) ;
break;
case V_33 :
V_27 . V_28 = 0 ;
V_27 . V_29 = 5 ;
V_30 . V_28 = 5 ;
V_30 . V_29 = 9 ;
break;
case V_34 :
V_27 . V_28 = 0 ;
V_27 . V_29 = 21 ;
V_30 . V_28 = 21 ;
V_30 . V_29 = 9 ;
break;
default:
V_19 = - V_21 ;
goto V_35;
}
V_27 . V_36 = & V_17 -> V_36 ;
V_30 . V_36 = & V_17 -> V_36 ;
V_19 = F_17 ( & V_27 ) ;
if ( V_19 < 0 )
goto V_35;
V_19 = F_17 ( & V_30 ) ;
if ( V_19 < 0 )
goto V_37;
return 0 ;
V_37:
V_19 = F_18 ( & V_27 ) ;
if ( V_19 )
F_19 ( & V_17 -> V_36 , L_1 ,
L_2 , V_19 ) ;
V_35:
F_20 ( V_10 -> V_24 , F_16 ( V_10 ) ) ;
V_9 = 0 ;
return V_19 ;
}
static int F_21 ( struct V_16 * V_17 )
{
struct V_18 * V_10 ;
if ( V_9 ) {
int V_19 ;
V_19 = F_18 ( & V_27 ) ;
if ( V_19 )
F_19 ( & V_17 -> V_36 , L_1 ,
L_2 , V_19 ) ;
V_19 = F_18 ( & V_30 ) ;
if ( V_19 )
F_19 ( & V_17 -> V_36 , L_1 ,
L_2 , V_19 ) ;
V_10 = F_14 ( V_17 , V_22 , 0 ) ;
F_20 ( V_10 -> V_24 , F_16 ( V_10 ) ) ;
V_9 = 0 ;
return V_19 ;
}
return 0 ;
}
