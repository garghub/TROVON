static int F_1 ( struct V_1 * V_2 )
{
struct V_3 V_4 = {
. V_5 = V_2 -> V_6 ,
. V_7 = V_2 -> V_8 ,
} ;
return F_2 ( F_3 ( V_2 -> V_9 . V_10 ) ,
& V_4 , 1 ) ;
}
static int F_4 ( struct V_9 * V_11 , unsigned V_12 )
{
struct V_1 * V_2 = F_5 ( V_11 ) ;
T_1 V_13 = V_2 -> V_8 - 1 - V_12 / 8 ;
T_1 V_14 = V_12 % 8 ;
int V_15 ;
F_6 ( & V_2 -> V_16 ) ;
V_15 = ( V_2 -> V_6 [ V_13 ] >> V_14 ) & 0x1 ;
F_7 ( & V_2 -> V_16 ) ;
return V_15 ;
}
static void F_8 ( struct V_9 * V_11 ,
unsigned V_12 , int V_17 )
{
struct V_1 * V_2 = F_5 ( V_11 ) ;
T_1 V_13 = V_2 -> V_8 - 1 - V_12 / 8 ;
T_1 V_14 = V_12 % 8 ;
F_6 ( & V_2 -> V_16 ) ;
if ( V_17 )
V_2 -> V_6 [ V_13 ] |= ( 1 << V_14 ) ;
else
V_2 -> V_6 [ V_13 ] &= ~ ( 1 << V_14 ) ;
F_1 ( V_2 ) ;
F_7 ( & V_2 -> V_16 ) ;
}
static int F_9 ( struct V_9 * V_11 ,
unsigned V_12 , int V_17 )
{
F_8 ( V_11 , V_12 , V_17 ) ;
return 0 ;
}
static int F_10 ( struct V_18 * V_19 )
{
struct V_1 * V_2 ;
T_2 V_20 ;
int V_15 ;
V_19 -> V_21 = 8 ;
V_15 = F_11 ( V_19 ) ;
if ( V_15 < 0 )
return V_15 ;
if ( F_12 ( V_19 -> V_22 . V_23 , L_1 ,
& V_20 ) ) {
F_13 ( & V_19 -> V_22 ,
L_2 ) ;
return - V_24 ;
}
V_2 = F_14 ( & V_19 -> V_22 , sizeof( * V_2 ) + V_20 , V_25 ) ;
if ( ! V_2 )
return - V_26 ;
F_15 ( V_19 , V_2 ) ;
V_2 -> V_9 . V_27 = V_19 -> V_28 ;
V_2 -> V_9 . V_29 = F_9 ;
V_2 -> V_9 . V_30 = F_4 ;
V_2 -> V_9 . V_31 = F_8 ;
V_2 -> V_9 . V_32 = - 1 ;
V_2 -> V_8 = V_20 ;
V_2 -> V_9 . V_33 = V_34 * V_2 -> V_8 ;
V_2 -> V_9 . V_35 = true ;
V_2 -> V_9 . V_10 = & V_19 -> V_22 ;
V_2 -> V_9 . V_36 = V_37 ;
F_16 ( & V_2 -> V_16 ) ;
V_15 = F_1 ( V_2 ) ;
if ( V_15 ) {
F_13 ( & V_19 -> V_22 , L_3 , V_15 ) ;
goto V_38;
}
V_15 = F_17 ( & V_2 -> V_9 , V_2 ) ;
if ( ! V_15 )
return 0 ;
V_38:
F_18 ( & V_2 -> V_16 ) ;
return V_15 ;
}
static int F_19 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = F_20 ( V_19 ) ;
F_21 ( & V_2 -> V_9 ) ;
F_18 ( & V_2 -> V_16 ) ;
return 0 ;
}
