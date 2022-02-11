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
static void F_9 ( struct V_9 * V_11 , unsigned long * V_18 ,
unsigned long * V_19 )
{
struct V_1 * V_2 = F_5 ( V_11 ) ;
unsigned int V_20 , V_21 , V_22 ;
T_1 V_13 , V_23 ;
F_6 ( & V_2 -> V_16 ) ;
for ( V_20 = 0 , V_13 = V_2 -> V_8 - 1 ; V_20 < V_2 -> V_8 ;
V_20 ++ , V_13 -- ) {
V_21 = V_20 / sizeof( * V_18 ) ;
V_22 = V_20 % sizeof( * V_18 ) * V_24 ;
V_23 = V_18 [ V_21 ] >> V_22 ;
if ( ! V_23 )
continue;
V_2 -> V_6 [ V_13 ] &= ~ V_23 ;
V_2 -> V_6 [ V_13 ] |= V_23 & ( V_19 [ V_21 ] >> V_22 ) ;
}
F_1 ( V_2 ) ;
F_7 ( & V_2 -> V_16 ) ;
}
static int F_10 ( struct V_9 * V_11 ,
unsigned V_12 , int V_17 )
{
F_8 ( V_11 , V_12 , V_17 ) ;
return 0 ;
}
static int F_11 ( struct V_25 * V_26 )
{
struct V_1 * V_2 ;
T_2 V_27 ;
int V_15 ;
V_26 -> V_28 = 8 ;
V_15 = F_12 ( V_26 ) ;
if ( V_15 < 0 )
return V_15 ;
if ( F_13 ( V_26 -> V_29 . V_30 , L_1 ,
& V_27 ) ) {
F_14 ( & V_26 -> V_29 ,
L_2 ) ;
return - V_31 ;
}
V_2 = F_15 ( & V_26 -> V_29 , sizeof( * V_2 ) + V_27 , V_32 ) ;
if ( ! V_2 )
return - V_33 ;
F_16 ( V_26 , V_2 ) ;
V_2 -> V_9 . V_34 = V_26 -> V_35 ;
V_2 -> V_9 . V_36 = F_10 ;
V_2 -> V_9 . V_37 = F_4 ;
V_2 -> V_9 . V_38 = F_8 ;
V_2 -> V_9 . V_39 = F_9 ;
V_2 -> V_9 . V_40 = - 1 ;
V_2 -> V_8 = V_27 ;
V_2 -> V_9 . V_41 = V_42 * V_2 -> V_8 ;
V_2 -> V_9 . V_43 = true ;
V_2 -> V_9 . V_10 = & V_26 -> V_29 ;
V_2 -> V_9 . V_44 = V_45 ;
F_17 ( & V_2 -> V_16 ) ;
V_15 = F_1 ( V_2 ) ;
if ( V_15 ) {
F_14 ( & V_26 -> V_29 , L_3 , V_15 ) ;
goto V_46;
}
V_15 = F_18 ( & V_2 -> V_9 , V_2 ) ;
if ( ! V_15 )
return 0 ;
V_46:
F_19 ( & V_2 -> V_16 ) ;
return V_15 ;
}
static int F_20 ( struct V_25 * V_26 )
{
struct V_1 * V_2 = F_21 ( V_26 ) ;
F_22 ( & V_2 -> V_9 ) ;
F_19 ( & V_2 -> V_16 ) ;
return 0 ;
}
