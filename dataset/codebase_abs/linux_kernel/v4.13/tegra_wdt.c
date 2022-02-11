static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
T_1 V_5 ;
V_5 = 1000000ul / 4 ;
V_5 |= ( V_6 | V_7 ) ;
F_3 ( V_5 , V_4 -> V_8 + V_9 ) ;
V_5 = V_10 |
( V_2 -> V_11 << V_12 ) |
V_13 ;
F_3 ( V_5 , V_4 -> V_14 + V_15 ) ;
F_3 ( V_16 , V_4 -> V_14 + V_17 ) ;
return 0 ;
}
static int F_4 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_3 ( V_18 , V_4 -> V_14 + V_19 ) ;
F_3 ( V_20 , V_4 -> V_14 + V_17 ) ;
F_3 ( 0 , V_4 -> V_8 + V_9 ) ;
return 0 ;
}
static int F_5 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_3 ( V_16 , V_4 -> V_14 + V_17 ) ;
return 0 ;
}
static int F_6 ( struct V_1 * V_2 ,
unsigned int V_11 )
{
V_2 -> V_11 = V_11 ;
if ( F_7 ( V_2 ) ) {
F_4 ( V_2 ) ;
return F_1 ( V_2 ) ;
}
return 0 ;
}
static unsigned int F_8 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
T_1 V_5 ;
int V_21 ;
int exp ;
V_5 = F_9 ( V_4 -> V_14 + V_22 ) ;
V_21 = ( V_5 >> V_23 ) & V_24 ;
exp = ( V_5 >> V_25 ) & V_26 ;
return ( ( ( 3 - exp ) * V_2 -> V_11 ) + V_21 ) / 4 ;
}
static int F_10 ( struct V_27 * V_28 )
{
struct V_1 * V_2 ;
struct V_3 * V_4 ;
struct V_29 * V_30 ;
void T_2 * V_31 ;
int V_32 ;
V_30 = F_11 ( V_28 , V_33 , 0 ) ;
V_31 = F_12 ( & V_28 -> V_34 , V_30 ) ;
if ( F_13 ( V_31 ) )
return F_14 ( V_31 ) ;
V_4 = F_15 ( & V_28 -> V_34 , sizeof( * V_4 ) , V_35 ) ;
if ( ! V_4 )
return - V_36 ;
V_4 -> V_14 = V_31 + V_37 ;
V_4 -> V_8 = V_31 + V_38 ;
V_2 = & V_4 -> V_2 ;
V_2 -> V_11 = V_39 ;
V_2 -> V_40 = & V_41 ;
V_2 -> V_42 = & V_43 ;
V_2 -> V_44 = V_45 ;
V_2 -> V_46 = V_47 ;
V_2 -> V_48 = & V_28 -> V_34 ;
F_16 ( V_2 , V_4 ) ;
F_17 ( V_2 , V_49 ) ;
V_32 = F_18 ( & V_28 -> V_34 , V_2 ) ;
if ( V_32 ) {
F_19 ( & V_28 -> V_34 ,
L_1 ) ;
return V_32 ;
}
F_20 ( V_28 , V_4 ) ;
F_21 ( & V_28 -> V_34 ,
L_2 ,
V_39 , V_49 ) ;
return 0 ;
}
static int F_22 ( struct V_27 * V_28 )
{
struct V_3 * V_4 = F_23 ( V_28 ) ;
F_4 ( & V_4 -> V_2 ) ;
F_21 ( & V_28 -> V_34 , L_3 ) ;
return 0 ;
}
static int F_24 ( struct V_50 * V_34 )
{
struct V_3 * V_4 = F_25 ( V_34 ) ;
if ( F_7 ( & V_4 -> V_2 ) )
F_4 ( & V_4 -> V_2 ) ;
return 0 ;
}
static int F_26 ( struct V_50 * V_34 )
{
struct V_3 * V_4 = F_25 ( V_34 ) ;
if ( F_7 ( & V_4 -> V_2 ) )
F_1 ( & V_4 -> V_2 ) ;
return 0 ;
}
