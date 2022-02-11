void F_1 ( struct V_1 * V_2 )
{
T_1 V_3 ;
T_1 V_4 ;
if ( ! V_2 || ! V_2 -> V_5 )
return;
V_4 = V_2 -> V_6 & V_7 ?
V_8 :
V_9 ;
V_3 = F_2 ( V_2 , V_2 -> V_5 ) ;
V_3 &= ~ V_4 ;
F_3 ( V_3 , V_2 , V_2 -> V_5 ) ;
}
void F_4 ( struct V_1 * V_2 )
{
T_1 V_3 ;
T_1 V_4 ;
if ( ! V_2 || ! V_2 -> V_5 )
return;
V_4 = V_2 -> V_6 & V_7 ?
V_8 :
V_9 ;
V_3 = F_2 ( V_2 , V_2 -> V_5 ) ;
V_3 |= V_4 ;
F_3 ( V_3 , V_2 , V_2 -> V_5 ) ;
}
static void F_5 ( struct V_10 * V_11 )
{
long V_12 , V_13 ;
V_12 = F_6 ( V_11 -> V_14 ) / ( V_11 -> V_15 + 1 ) ;
V_13 = V_12 * V_11 -> V_16 ;
if ( ( V_12 < V_17 ) && ( V_13 < V_18 ) )
V_11 -> V_19 = 1 ;
else
V_11 -> V_19 = 0 ;
}
unsigned long F_7 ( struct V_20 * V_21 ,
unsigned long V_22 )
{
struct V_1 * V_2 = F_8 ( V_21 ) ;
T_1 V_3 ;
unsigned long V_23 ;
struct V_10 * V_11 ;
if ( ! V_2 || ! V_2 -> V_10 )
return 0 ;
V_11 = V_2 -> V_10 ;
V_23 = F_9 ( V_2 ) ;
V_3 = F_2 ( V_2 , V_11 -> V_24 ) ;
if ( V_3 & V_25 )
V_23 *= V_26 ;
return V_23 ;
}
long F_10 ( struct V_20 * V_21 ,
unsigned long V_27 ,
unsigned long * V_22 )
{
struct V_1 * V_2 = F_8 ( V_21 ) ;
struct V_10 * V_11 ;
long V_28 ;
if ( ! V_2 || ! V_2 -> V_10 )
return - V_29 ;
V_11 = V_2 -> V_10 ;
V_11 -> V_30 = 0 ;
V_28 = F_11 ( V_21 , V_27 , NULL ) ;
if ( V_28 != ~ 0 )
goto V_31;
V_28 = F_11 ( V_21 , V_27 / V_26 ,
NULL ) ;
if ( V_28 == ~ 0 )
return V_28 ;
V_11 -> V_32 *= V_26 ;
V_11 -> V_30 = 1 ;
V_31:
F_5 ( V_11 ) ;
return V_11 -> V_32 ;
}
long F_12 ( struct V_20 * V_21 , unsigned long V_23 ,
unsigned long V_33 ,
unsigned long V_34 ,
unsigned long * V_35 ,
struct V_20 * * V_36 )
{
struct V_1 * V_2 = F_8 ( V_21 ) ;
struct V_10 * V_11 ;
if ( ! V_21 || ! V_23 )
return - V_29 ;
V_11 = V_2 -> V_10 ;
if ( ! V_11 )
return - V_29 ;
if ( F_6 ( V_11 -> V_37 ) == V_23 &&
( V_11 -> V_38 & ( 1 << V_39 ) ) ) {
* V_36 = F_13 ( V_11 -> V_37 ) ;
} else {
V_23 = F_10 ( V_21 , V_23 ,
V_35 ) ;
* V_36 = F_13 ( V_11 -> V_14 ) ;
}
* V_35 = V_23 ;
return V_23 ;
}
