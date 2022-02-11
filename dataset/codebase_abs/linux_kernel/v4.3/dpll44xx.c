static void F_1 ( struct V_1 * V_2 )
{
T_1 V_3 ;
T_1 V_4 ;
if ( ! V_2 || ! V_2 -> V_5 )
return;
V_4 = V_2 -> V_6 & V_7 ?
V_8 :
V_9 ;
V_3 = V_10 -> V_11 ( V_2 -> V_5 ) ;
V_3 &= ~ V_4 ;
V_10 -> V_12 ( V_3 , V_2 -> V_5 ) ;
}
static void F_2 ( struct V_1 * V_2 )
{
T_1 V_3 ;
T_1 V_4 ;
if ( ! V_2 || ! V_2 -> V_5 )
return;
V_4 = V_2 -> V_6 & V_7 ?
V_8 :
V_9 ;
V_3 = V_10 -> V_11 ( V_2 -> V_5 ) ;
V_3 |= V_4 ;
V_10 -> V_12 ( V_3 , V_2 -> V_5 ) ;
}
static void F_3 ( struct V_13 * V_14 )
{
long V_15 , V_16 ;
V_15 = F_4 ( V_14 -> V_17 ) / ( V_14 -> V_18 + 1 ) ;
V_16 = V_15 * V_14 -> V_19 ;
if ( ( V_15 < V_20 ) && ( V_16 < V_21 ) )
V_14 -> V_22 = 1 ;
else
V_14 -> V_22 = 0 ;
}
unsigned long F_5 ( struct V_23 * V_24 ,
unsigned long V_25 )
{
struct V_1 * V_2 = F_6 ( V_24 ) ;
T_1 V_3 ;
unsigned long V_26 ;
struct V_13 * V_14 ;
if ( ! V_2 || ! V_2 -> V_13 )
return 0 ;
V_14 = V_2 -> V_13 ;
V_26 = F_7 ( V_2 ) ;
V_3 = V_10 -> V_11 ( V_14 -> V_27 ) ;
if ( V_3 & V_28 )
V_26 *= V_29 ;
return V_26 ;
}
long F_8 ( struct V_23 * V_24 ,
unsigned long V_30 ,
unsigned long * V_25 )
{
struct V_1 * V_2 = F_6 ( V_24 ) ;
struct V_13 * V_14 ;
long V_31 ;
if ( ! V_2 || ! V_2 -> V_13 )
return - V_32 ;
V_14 = V_2 -> V_13 ;
V_14 -> V_33 = 0 ;
V_31 = F_9 ( V_24 , V_30 , NULL ) ;
if ( V_31 != ~ 0 )
goto V_34;
V_31 = F_9 ( V_24 , V_30 / V_29 ,
NULL ) ;
if ( V_31 == ~ 0 )
return V_31 ;
V_14 -> V_35 *= V_29 ;
V_14 -> V_33 = 1 ;
V_34:
F_3 ( V_14 ) ;
return V_14 -> V_35 ;
}
int F_10 ( struct V_23 * V_24 ,
struct V_36 * V_37 )
{
struct V_1 * V_2 = F_6 ( V_24 ) ;
struct V_13 * V_14 ;
if ( ! V_37 -> V_26 )
return - V_32 ;
V_14 = V_2 -> V_13 ;
if ( ! V_14 )
return - V_32 ;
if ( F_4 ( V_14 -> V_38 ) == V_37 -> V_26 &&
( V_14 -> V_39 & ( 1 << V_40 ) ) ) {
V_37 -> V_41 = F_11 ( V_14 -> V_38 ) ;
} else {
V_37 -> V_26 = F_8 ( V_24 , V_37 -> V_26 ,
& V_37 -> V_42 ) ;
V_37 -> V_41 = F_11 ( V_14 -> V_17 ) ;
}
V_37 -> V_42 = V_37 -> V_26 ;
return 0 ;
}
