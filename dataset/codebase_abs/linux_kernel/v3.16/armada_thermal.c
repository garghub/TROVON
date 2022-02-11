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
bool V_14 =
! ! F_7 ( V_2 -> V_15 . V_16 ,
L_1 ) ;
if ( V_14 ) {
F_3 ( V_17 , V_4 -> V_6 ) ;
F_3 ( V_18 , V_4 -> V_6 + 0x4 ) ;
}
V_5 = F_8 ( V_4 -> V_6 + 4 ) ;
V_5 &= ~ ( V_19 << V_20 ) ;
V_5 &= ~ V_21 ;
V_5 &= ~ V_22 ;
if ( V_14 )
V_5 |= V_23 ;
F_3 ( V_5 , V_4 -> V_6 + 4 ) ;
F_5 ( 20 ) ;
V_5 |= V_22 ;
F_3 ( V_5 , V_4 -> V_6 + 4 ) ;
F_5 ( 50 ) ;
}
static void F_9 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
unsigned long V_5 = F_2 ( V_4 -> V_6 ) ;
if ( ! ( V_5 & V_24 ) ) {
V_5 |= V_24 ;
F_3 ( V_5 , V_4 -> V_6 ) ;
F_5 ( 10 ) ;
}
}
static bool F_10 ( struct V_3 * V_4 )
{
unsigned long V_5 = F_2 ( V_4 -> V_11 ) ;
return ( V_5 >> V_4 -> V_25 -> V_26 ) & V_27 ;
}
static int F_11 ( struct V_28 * V_29 ,
unsigned long * V_30 )
{
struct V_3 * V_4 = V_29 -> V_31 ;
unsigned long V_5 ;
unsigned long V_32 , V_33 , div ;
if ( V_4 -> V_25 -> V_34 && ! V_4 -> V_25 -> V_34 ( V_4 ) ) {
F_12 ( & V_29 -> V_35 ,
L_2 ) ;
return - V_36 ;
}
V_5 = F_2 ( V_4 -> V_11 ) ;
V_5 = ( V_5 >> V_4 -> V_25 -> V_37 ) & V_4 -> V_25 -> V_38 ;
V_33 = V_4 -> V_25 -> V_39 ;
V_32 = V_4 -> V_25 -> V_40 ;
div = V_4 -> V_25 -> V_41 ;
if ( V_4 -> V_25 -> V_42 )
* V_30 = ( ( V_32 * V_5 ) - V_33 ) / div ;
else
* V_30 = ( V_33 - ( V_32 * V_5 ) ) / div ;
return 0 ;
}
static int F_13 ( struct V_1 * V_2 )
{
struct V_28 * V_29 ;
const struct V_43 * V_44 ;
struct V_3 * V_4 ;
struct V_45 * V_46 ;
V_44 = F_14 ( V_47 , & V_2 -> V_15 ) ;
if ( ! V_44 )
return - V_48 ;
V_4 = F_15 ( & V_2 -> V_15 , sizeof( * V_4 ) , V_49 ) ;
if ( ! V_4 )
return - V_50 ;
V_46 = F_16 ( V_2 , V_51 , 0 ) ;
V_4 -> V_11 = F_17 ( & V_2 -> V_15 , V_46 ) ;
if ( F_18 ( V_4 -> V_11 ) )
return F_19 ( V_4 -> V_11 ) ;
V_46 = F_16 ( V_2 , V_51 , 1 ) ;
V_4 -> V_6 = F_17 ( & V_2 -> V_15 , V_46 ) ;
if ( F_18 ( V_4 -> V_6 ) )
return F_19 ( V_4 -> V_6 ) ;
V_4 -> V_25 = (struct V_52 * ) V_44 -> V_25 ;
V_4 -> V_25 -> V_53 ( V_2 , V_4 ) ;
V_29 = F_20 ( L_3 , 0 , 0 ,
V_4 , & V_54 , NULL , 0 , 0 ) ;
if ( F_18 ( V_29 ) ) {
F_12 ( & V_2 -> V_15 ,
L_4 ) ;
return F_19 ( V_29 ) ;
}
F_21 ( V_2 , V_29 ) ;
return 0 ;
}
static int F_22 ( struct V_1 * V_2 )
{
struct V_28 * V_55 =
F_23 ( V_2 ) ;
F_24 ( V_55 ) ;
return 0 ;
}
