static int F_1 ( struct V_1 * V_2 , int V_3 )
{
int V_4 ;
T_1 V_5 ;
struct V_6 * V_7 ;
V_4 = F_2 ( V_2 , V_8 ) ;
if ( ! V_4 )
return - V_9 ;
V_7 = F_3 ( sizeof( * V_7 ) , V_10 ) ;
if ( ! V_7 )
return - V_11 ;
V_7 -> V_4 = V_4 ;
V_7 -> V_12 = V_3 ;
F_4 ( V_2 , V_4 + V_13 , & V_5 ) ;
V_7 -> V_14 = F_5 ( V_5 ) ? F_5 ( V_5 ) :
V_15 ;
V_2 -> V_7 = V_7 ;
return 0 ;
}
static void F_6 ( struct V_1 * V_2 )
{
F_7 ( V_2 -> V_7 ) ;
V_2 -> V_7 = NULL ;
}
int F_8 ( struct V_1 * V_2 , int V_3 )
{
int V_16 ;
T_1 V_17 ;
F_9 ( V_2 -> V_7 && V_2 -> V_7 -> V_18 ) ;
if ( V_3 < V_19 )
return - V_20 ;
if ( V_2 -> V_21 || V_2 -> V_22 ) {
struct V_1 * V_23 = V_2 -> V_21 ? V_2 : V_2 -> V_24 ;
F_10 ( & V_23 -> V_25 -> V_26 ) ;
if ( V_23 -> V_7 )
V_16 = V_23 -> V_7 -> V_12 == V_3 ? 0 : - V_20 ;
else
V_16 = F_1 ( V_23 , V_3 ) ;
if ( ! V_16 )
V_23 -> V_7 -> V_27 ++ ;
F_11 ( & V_23 -> V_25 -> V_26 ) ;
if ( V_16 )
return V_16 ;
}
if ( ! V_2 -> V_21 ) {
V_16 = F_1 ( V_2 , V_3 ) ;
if ( V_16 )
return V_16 ;
}
V_17 = V_28 ;
if ( ! V_2 -> V_22 )
V_17 |= F_12 ( V_3 - V_19 ) ;
F_13 ( V_2 , V_2 -> V_7 -> V_4 + V_29 , V_17 ) ;
V_2 -> V_7 -> V_18 = 1 ;
return 0 ;
}
void F_14 ( struct V_1 * V_2 )
{
T_1 V_17 ;
F_9 ( ! V_2 -> V_7 || ! V_2 -> V_7 -> V_18 ) ;
F_4 ( V_2 , V_2 -> V_7 -> V_4 + V_29 , & V_17 ) ;
V_17 &= ~ V_28 ;
F_13 ( V_2 , V_2 -> V_7 -> V_4 + V_29 , V_17 ) ;
V_2 -> V_7 -> V_18 = 0 ;
if ( V_2 -> V_21 || V_2 -> V_22 ) {
struct V_1 * V_23 = V_2 -> V_21 ? V_2 : V_2 -> V_24 ;
F_10 ( & V_23 -> V_25 -> V_26 ) ;
V_23 -> V_7 -> V_27 -- ;
if ( ! V_23 -> V_7 -> V_27 )
F_6 ( V_23 ) ;
F_11 ( & V_23 -> V_25 -> V_26 ) ;
}
if ( ! V_2 -> V_21 )
F_6 ( V_2 ) ;
}
void F_15 ( struct V_1 * V_2 )
{
T_1 V_17 ;
if ( ! F_16 ( V_2 ) )
return;
if ( ! F_2 ( V_2 , V_8 ) )
F_17 () ;
V_17 = V_28 ;
if ( ! V_2 -> V_22 )
V_17 |= F_12 ( V_2 -> V_7 -> V_12 - V_19 ) ;
F_13 ( V_2 , V_2 -> V_7 -> V_4 + V_29 , V_17 ) ;
}
int F_18 ( struct V_1 * V_2 )
{
int V_4 ;
T_1 V_5 ;
if ( V_2 -> V_22 )
return 0 ;
if ( V_2 -> V_7 )
return V_2 -> V_7 -> V_14 ;
V_4 = F_2 ( V_2 , V_8 ) ;
if ( ! V_4 )
return - V_9 ;
F_4 ( V_2 , V_4 + V_13 , & V_5 ) ;
return F_5 ( V_5 ) ? F_5 ( V_5 ) :
V_15 ;
}
int F_19 ( struct V_1 * V_23 , T_2 V_30 )
{
T_1 V_31 , V_32 ;
T_2 V_33 ;
int V_4 ;
V_4 = F_2 ( V_23 , V_34 ) ;
if ( ! V_4 )
return - V_20 ;
F_4 ( V_23 , V_4 + V_35 , & V_31 ) ;
F_4 ( V_23 , V_4 + V_36 , & V_32 ) ;
if ( ( V_31 & V_37 ) ||
! ( V_32 & V_38 ) )
return - V_39 ;
F_20 ( V_23 , V_4 + V_40 , & V_33 ) ;
V_30 = F_21 ( V_33 , V_30 ) ;
F_22 ( V_23 , V_4 + V_41 , V_30 ) ;
V_31 |= V_37 ;
F_13 ( V_23 , V_4 + V_35 , V_31 ) ;
return 0 ;
}
void F_23 ( struct V_1 * V_23 )
{
T_1 V_31 ;
int V_4 ;
V_4 = F_2 ( V_23 , V_34 ) ;
if ( ! V_4 )
return;
F_4 ( V_23 , V_4 + V_35 , & V_31 ) ;
V_31 &= ~ V_37 ;
F_13 ( V_23 , V_4 + V_35 , V_31 ) ;
}
int F_24 ( struct V_1 * V_23 )
{
T_1 V_31 ;
int V_4 ;
V_4 = F_2 ( V_23 , V_34 ) ;
if ( ! V_4 )
return - V_20 ;
F_4 ( V_23 , V_4 + V_35 , & V_31 ) ;
if ( V_31 & V_37 )
return - V_39 ;
V_31 |= V_42 ;
F_13 ( V_23 , V_4 + V_35 , V_31 ) ;
return 0 ;
}
int F_25 ( struct V_1 * V_23 , int V_43 )
{
T_1 V_31 , V_44 ;
int V_4 ;
V_4 = F_2 ( V_23 , V_45 ) ;
if ( ! V_4 )
return - V_20 ;
F_4 ( V_23 , V_4 + V_46 , & V_31 ) ;
F_4 ( V_23 , V_4 + V_47 , & V_44 ) ;
if ( V_31 & V_48 )
return - V_20 ;
V_44 &= V_49 | V_50 ;
if ( ( V_44 & V_43 ) != V_43 )
return - V_20 ;
V_31 = V_48 | V_43 ;
F_13 ( V_23 , V_4 + V_46 , V_31 ) ;
return 0 ;
}
void F_26 ( struct V_1 * V_23 )
{
T_1 V_31 = 0 ;
int V_4 ;
V_4 = F_2 ( V_23 , V_45 ) ;
if ( ! V_4 )
return;
F_13 ( V_23 , V_4 + V_46 , V_31 ) ;
}
int F_27 ( struct V_1 * V_23 )
{
T_1 V_44 ;
int V_4 ;
V_4 = F_2 ( V_23 , V_45 ) ;
if ( ! V_4 )
return - V_20 ;
F_4 ( V_23 , V_4 + V_47 , & V_44 ) ;
V_44 &= V_49 | V_50 ;
return V_44 ;
}
int F_28 ( struct V_1 * V_23 )
{
T_1 V_44 ;
int V_4 ;
V_4 = F_2 ( V_23 , V_45 ) ;
if ( ! V_4 )
return - V_20 ;
F_4 ( V_23 , V_4 + V_47 , & V_44 ) ;
V_44 = ( V_44 & V_51 ) >> V_52 ;
return ( 1 << V_44 ) ;
}
