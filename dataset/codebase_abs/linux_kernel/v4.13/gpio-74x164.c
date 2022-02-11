static int F_1 ( struct V_1 * V_2 )
{
return F_2 ( F_3 ( V_2 -> V_3 . V_4 ) , V_2 -> V_5 ,
V_2 -> V_6 ) ;
}
static int F_4 ( struct V_3 * V_7 , unsigned V_8 )
{
struct V_1 * V_2 = F_5 ( V_7 ) ;
T_1 V_9 = V_2 -> V_6 - 1 - V_8 / 8 ;
T_1 V_10 = V_8 % 8 ;
int V_11 ;
F_6 ( & V_2 -> V_12 ) ;
V_11 = ( V_2 -> V_5 [ V_9 ] >> V_10 ) & 0x1 ;
F_7 ( & V_2 -> V_12 ) ;
return V_11 ;
}
static void F_8 ( struct V_3 * V_7 ,
unsigned V_8 , int V_13 )
{
struct V_1 * V_2 = F_5 ( V_7 ) ;
T_1 V_9 = V_2 -> V_6 - 1 - V_8 / 8 ;
T_1 V_10 = V_8 % 8 ;
F_6 ( & V_2 -> V_12 ) ;
if ( V_13 )
V_2 -> V_5 [ V_9 ] |= ( 1 << V_10 ) ;
else
V_2 -> V_5 [ V_9 ] &= ~ ( 1 << V_10 ) ;
F_1 ( V_2 ) ;
F_7 ( & V_2 -> V_12 ) ;
}
static void F_9 ( struct V_3 * V_7 , unsigned long * V_14 ,
unsigned long * V_15 )
{
struct V_1 * V_2 = F_5 ( V_7 ) ;
unsigned int V_16 , V_17 , V_18 ;
T_1 V_9 , V_19 ;
F_6 ( & V_2 -> V_12 ) ;
for ( V_16 = 0 , V_9 = V_2 -> V_6 - 1 ; V_16 < V_2 -> V_6 ;
V_16 ++ , V_9 -- ) {
V_17 = V_16 / sizeof( * V_14 ) ;
V_18 = V_16 % sizeof( * V_14 ) * V_20 ;
V_19 = V_14 [ V_17 ] >> V_18 ;
if ( ! V_19 )
continue;
V_2 -> V_5 [ V_9 ] &= ~ V_19 ;
V_2 -> V_5 [ V_9 ] |= V_19 & ( V_15 [ V_17 ] >> V_18 ) ;
}
F_1 ( V_2 ) ;
F_7 ( & V_2 -> V_12 ) ;
}
static int F_10 ( struct V_3 * V_7 ,
unsigned V_8 , int V_13 )
{
F_8 ( V_7 , V_8 , V_13 ) ;
return 0 ;
}
static int F_11 ( struct V_21 * V_22 )
{
struct V_1 * V_2 ;
T_2 V_23 ;
int V_11 ;
V_22 -> V_24 = 8 ;
V_11 = F_12 ( V_22 ) ;
if ( V_11 < 0 )
return V_11 ;
if ( F_13 ( V_22 -> V_25 . V_26 , L_1 ,
& V_23 ) ) {
F_14 ( & V_22 -> V_25 ,
L_2 ) ;
return - V_27 ;
}
V_2 = F_15 ( & V_22 -> V_25 , sizeof( * V_2 ) + V_23 , V_28 ) ;
if ( ! V_2 )
return - V_29 ;
F_16 ( V_22 , V_2 ) ;
V_2 -> V_3 . V_30 = V_22 -> V_31 ;
V_2 -> V_3 . V_32 = F_10 ;
V_2 -> V_3 . V_33 = F_4 ;
V_2 -> V_3 . V_34 = F_8 ;
V_2 -> V_3 . V_35 = F_9 ;
V_2 -> V_3 . V_36 = - 1 ;
V_2 -> V_6 = V_23 ;
V_2 -> V_3 . V_37 = V_38 * V_2 -> V_6 ;
V_2 -> V_3 . V_39 = true ;
V_2 -> V_3 . V_4 = & V_22 -> V_25 ;
V_2 -> V_3 . V_40 = V_41 ;
F_17 ( & V_2 -> V_12 ) ;
V_11 = F_1 ( V_2 ) ;
if ( V_11 ) {
F_14 ( & V_22 -> V_25 , L_3 , V_11 ) ;
goto V_42;
}
V_11 = F_18 ( & V_2 -> V_3 , V_2 ) ;
if ( ! V_11 )
return 0 ;
V_42:
F_19 ( & V_2 -> V_12 ) ;
return V_11 ;
}
static int F_20 ( struct V_21 * V_22 )
{
struct V_1 * V_2 = F_21 ( V_22 ) ;
F_22 ( & V_2 -> V_3 ) ;
F_19 ( & V_2 -> V_12 ) ;
return 0 ;
}
