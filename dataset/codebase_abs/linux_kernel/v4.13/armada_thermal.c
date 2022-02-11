static void F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
unsigned long V_5 ;
V_5 = F_2 ( V_4 -> V_6 ) ;
V_5 |= V_7 ;
F_3 ( V_5 , V_4 -> V_6 ) ;
V_5 &= ~ V_8 ;
V_5 |= ( 0xf1 << V_9 ) ;
F_3 ( V_5 , V_4 -> V_6 ) ;
V_5 = F_2 ( V_4 -> V_6 ) ;
F_3 ( ( V_5 | V_10 ) , V_4 -> V_6 ) ;
F_3 ( V_5 , V_4 -> V_6 ) ;
V_5 = F_2 ( V_4 -> V_11 ) ;
V_5 &= ~ V_12 ;
F_3 ( V_5 , V_4 -> V_11 ) ;
}
static void F_4 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
unsigned long V_5 ;
V_5 = F_2 ( V_4 -> V_6 ) ;
V_5 |= V_7 ;
F_3 ( V_5 , V_4 -> V_6 ) ;
V_5 &= ~ V_8 ;
V_5 |= ( 0xf1 << V_9 ) ;
F_3 ( V_5 , V_4 -> V_6 ) ;
V_5 &= ~ V_13 ;
F_3 ( V_5 , V_4 -> V_6 ) ;
F_5 ( 10 ) ;
}
static void F_6 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
unsigned long V_5 ;
V_5 = F_7 ( V_4 -> V_6 + 4 ) ;
V_5 &= ~ ( V_14 << V_15 ) ;
V_5 &= ~ V_16 ;
V_5 &= ~ V_17 ;
F_3 ( V_5 , V_4 -> V_6 + 4 ) ;
F_5 ( 20 ) ;
V_5 |= V_17 ;
F_3 ( V_5 , V_4 -> V_6 + 4 ) ;
F_5 ( 50 ) ;
}
static void F_8 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
unsigned long V_5 = F_2 ( V_4 -> V_6 ) ;
if ( ! ( V_5 & V_18 ) ) {
V_5 |= V_18 ;
F_3 ( V_5 , V_4 -> V_6 ) ;
F_5 ( 10 ) ;
}
}
static bool F_9 ( struct V_3 * V_4 )
{
unsigned long V_5 = F_2 ( V_4 -> V_11 ) ;
return ( V_5 >> V_4 -> V_19 -> V_20 ) & V_21 ;
}
static int F_10 ( struct V_22 * V_23 ,
int * V_24 )
{
struct V_3 * V_4 = V_23 -> V_25 ;
unsigned long V_5 ;
unsigned long V_26 , V_27 , div ;
if ( V_4 -> V_19 -> V_28 && ! V_4 -> V_19 -> V_28 ( V_4 ) ) {
F_11 ( & V_23 -> V_29 ,
L_1 ) ;
return - V_30 ;
}
V_5 = F_2 ( V_4 -> V_11 ) ;
V_5 = ( V_5 >> V_4 -> V_19 -> V_31 ) & V_4 -> V_19 -> V_32 ;
V_27 = V_4 -> V_19 -> V_33 ;
V_26 = V_4 -> V_19 -> V_34 ;
div = V_4 -> V_19 -> V_35 ;
if ( V_4 -> V_19 -> V_36 )
* V_24 = ( ( V_26 * V_5 ) - V_27 ) / div ;
else
* V_24 = ( V_27 - ( V_26 * V_5 ) ) / div ;
return 0 ;
}
static int F_12 ( struct V_1 * V_2 )
{
struct V_22 * V_23 ;
const struct V_37 * V_38 ;
struct V_3 * V_4 ;
struct V_39 * V_40 ;
V_38 = F_13 ( V_41 , & V_2 -> V_42 ) ;
if ( ! V_38 )
return - V_43 ;
V_4 = F_14 ( & V_2 -> V_42 , sizeof( * V_4 ) , V_44 ) ;
if ( ! V_4 )
return - V_45 ;
V_40 = F_15 ( V_2 , V_46 , 0 ) ;
V_4 -> V_11 = F_16 ( & V_2 -> V_42 , V_40 ) ;
if ( F_17 ( V_4 -> V_11 ) )
return F_18 ( V_4 -> V_11 ) ;
V_40 = F_15 ( V_2 , V_46 , 1 ) ;
V_4 -> V_6 = F_16 ( & V_2 -> V_42 , V_40 ) ;
if ( F_17 ( V_4 -> V_6 ) )
return F_18 ( V_4 -> V_6 ) ;
V_4 -> V_19 = (struct V_47 * ) V_38 -> V_19 ;
V_4 -> V_19 -> V_48 ( V_2 , V_4 ) ;
V_23 = F_19 ( L_2 , 0 , 0 ,
V_4 , & V_49 , NULL , 0 , 0 ) ;
if ( F_17 ( V_23 ) ) {
F_11 ( & V_2 -> V_42 ,
L_3 ) ;
return F_18 ( V_23 ) ;
}
F_20 ( V_2 , V_23 ) ;
return 0 ;
}
static int F_21 ( struct V_1 * V_2 )
{
struct V_22 * V_50 =
F_22 ( V_2 ) ;
F_23 ( V_50 ) ;
return 0 ;
}
