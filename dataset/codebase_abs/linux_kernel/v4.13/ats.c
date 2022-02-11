void F_1 ( struct V_1 * V_2 )
{
int V_3 ;
V_3 = F_2 ( V_2 , V_4 ) ;
if ( ! V_3 )
return;
V_2 -> V_5 = V_3 ;
}
int F_3 ( struct V_1 * V_2 , int V_6 )
{
T_1 V_7 ;
struct V_1 * V_8 ;
if ( ! V_2 -> V_5 )
return - V_9 ;
if ( F_4 ( V_2 -> V_10 ) )
return - V_11 ;
if ( V_6 < V_12 )
return - V_9 ;
V_7 = V_13 ;
if ( V_2 -> V_14 ) {
V_8 = F_5 ( V_2 ) ;
if ( V_8 -> V_15 != V_6 )
return - V_9 ;
F_6 ( & V_8 -> V_16 ) ;
} else {
V_2 -> V_15 = V_6 ;
V_7 |= F_7 ( V_2 -> V_15 - V_12 ) ;
}
F_8 ( V_2 , V_2 -> V_5 + V_17 , V_7 ) ;
V_2 -> V_10 = 1 ;
return 0 ;
}
void F_9 ( struct V_1 * V_2 )
{
struct V_1 * V_8 ;
T_1 V_7 ;
if ( F_4 ( ! V_2 -> V_10 ) )
return;
if ( F_10 ( & V_2 -> V_16 ) )
return;
if ( V_2 -> V_14 ) {
V_8 = F_5 ( V_2 ) ;
F_11 ( & V_8 -> V_16 ) ;
}
F_12 ( V_2 , V_2 -> V_5 + V_17 , & V_7 ) ;
V_7 &= ~ V_13 ;
F_8 ( V_2 , V_2 -> V_5 + V_17 , V_7 ) ;
V_2 -> V_10 = 0 ;
}
void F_13 ( struct V_1 * V_2 )
{
T_1 V_7 ;
if ( ! V_2 -> V_10 )
return;
V_7 = V_13 ;
if ( ! V_2 -> V_14 )
V_7 |= F_7 ( V_2 -> V_15 - V_12 ) ;
F_8 ( V_2 , V_2 -> V_5 + V_17 , V_7 ) ;
}
int F_14 ( struct V_1 * V_2 )
{
T_1 V_18 ;
if ( ! V_2 -> V_5 )
return - V_9 ;
if ( V_2 -> V_14 )
return 0 ;
F_12 ( V_2 , V_2 -> V_5 + V_19 , & V_18 ) ;
return F_15 ( V_18 ) ? F_15 ( V_18 ) : V_20 ;
}
int F_16 ( struct V_1 * V_8 , T_2 V_21 )
{
T_1 V_22 , V_23 ;
T_2 V_24 ;
int V_3 ;
if ( F_4 ( V_8 -> V_25 ) )
return - V_11 ;
V_3 = F_2 ( V_8 , V_26 ) ;
if ( ! V_3 )
return - V_9 ;
F_12 ( V_8 , V_3 + V_27 , & V_23 ) ;
if ( ! ( V_23 & V_28 ) )
return - V_11 ;
F_17 ( V_8 , V_3 + V_29 , & V_24 ) ;
V_21 = F_18 ( V_24 , V_21 ) ;
V_8 -> V_30 = V_21 ;
F_19 ( V_8 , V_3 + V_31 , V_21 ) ;
V_22 = V_32 ;
F_8 ( V_8 , V_3 + V_33 , V_22 ) ;
V_8 -> V_25 = 1 ;
return 0 ;
}
void F_20 ( struct V_1 * V_8 )
{
T_1 V_22 ;
int V_3 ;
if ( F_4 ( ! V_8 -> V_25 ) )
return;
V_3 = F_2 ( V_8 , V_26 ) ;
if ( ! V_3 )
return;
F_12 ( V_8 , V_3 + V_33 , & V_22 ) ;
V_22 &= ~ V_32 ;
F_8 ( V_8 , V_3 + V_33 , V_22 ) ;
V_8 -> V_25 = 0 ;
}
void F_21 ( struct V_1 * V_8 )
{
T_1 V_22 = V_32 ;
T_2 V_21 = V_8 -> V_30 ;
int V_3 ;
if ( ! V_8 -> V_25 )
return;
V_3 = F_2 ( V_8 , V_26 ) ;
if ( ! V_3 )
return;
F_19 ( V_8 , V_3 + V_31 , V_21 ) ;
F_8 ( V_8 , V_3 + V_33 , V_22 ) ;
}
int F_22 ( struct V_1 * V_8 )
{
T_1 V_22 ;
int V_3 ;
if ( F_4 ( V_8 -> V_25 ) )
return - V_11 ;
V_3 = F_2 ( V_8 , V_26 ) ;
if ( ! V_3 )
return - V_9 ;
V_22 = V_34 ;
F_8 ( V_8 , V_3 + V_33 , V_22 ) ;
return 0 ;
}
int F_23 ( struct V_1 * V_8 , int V_35 )
{
T_1 V_22 , V_36 ;
int V_3 ;
if ( F_4 ( V_8 -> V_37 ) )
return - V_11 ;
V_3 = F_2 ( V_8 , V_38 ) ;
if ( ! V_3 )
return - V_9 ;
F_12 ( V_8 , V_3 + V_39 , & V_36 ) ;
V_36 &= V_40 | V_41 ;
if ( ( V_36 & V_35 ) != V_35 )
return - V_9 ;
V_22 = V_42 | V_35 ;
V_8 -> V_43 = V_35 ;
F_8 ( V_8 , V_3 + V_44 , V_22 ) ;
V_8 -> V_37 = 1 ;
return 0 ;
}
void F_24 ( struct V_1 * V_8 )
{
T_1 V_22 = 0 ;
int V_3 ;
if ( F_4 ( ! V_8 -> V_37 ) )
return;
V_3 = F_2 ( V_8 , V_38 ) ;
if ( ! V_3 )
return;
F_8 ( V_8 , V_3 + V_44 , V_22 ) ;
V_8 -> V_37 = 0 ;
}
void F_25 ( struct V_1 * V_8 )
{
T_1 V_22 ;
int V_3 ;
if ( ! V_8 -> V_37 )
return;
V_3 = F_2 ( V_8 , V_38 ) ;
if ( ! V_3 )
return;
V_22 = V_42 | V_8 -> V_43 ;
F_8 ( V_8 , V_3 + V_44 , V_22 ) ;
}
int F_26 ( struct V_1 * V_8 )
{
T_1 V_36 ;
int V_3 ;
V_3 = F_2 ( V_8 , V_38 ) ;
if ( ! V_3 )
return - V_9 ;
F_12 ( V_8 , V_3 + V_39 , & V_36 ) ;
V_36 &= V_40 | V_41 ;
return V_36 ;
}
int F_27 ( struct V_1 * V_8 )
{
T_1 V_36 ;
int V_3 ;
V_3 = F_2 ( V_8 , V_38 ) ;
if ( ! V_3 )
return - V_9 ;
F_12 ( V_8 , V_3 + V_39 , & V_36 ) ;
V_36 = ( V_36 & V_45 ) >> V_46 ;
return ( 1 << V_36 ) ;
}
