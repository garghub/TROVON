static void F_1 ( struct V_1 * V_2 )
{
unsigned long V_3 ;
V_3 = F_2 ( V_2 -> V_4 ) ;
V_3 |= V_5 ;
F_3 ( V_3 , V_2 -> V_4 ) ;
V_3 &= ~ V_6 ;
V_3 |= ( 0xf1 << V_7 ) ;
F_3 ( V_3 , V_2 -> V_4 ) ;
V_3 = F_2 ( V_2 -> V_4 ) ;
F_3 ( ( V_3 | V_8 ) , V_2 -> V_4 ) ;
F_3 ( V_3 , V_2 -> V_4 ) ;
V_3 = F_2 ( V_2 -> V_9 ) ;
V_3 &= ~ V_10 ;
F_3 ( V_3 , V_2 -> V_9 ) ;
}
static void F_4 ( struct V_1 * V_2 )
{
unsigned long V_3 ;
V_3 = F_2 ( V_2 -> V_4 ) ;
V_3 |= V_5 ;
F_3 ( V_3 , V_2 -> V_4 ) ;
V_3 &= ~ V_6 ;
V_3 |= ( 0xf1 << V_7 ) ;
F_3 ( V_3 , V_2 -> V_4 ) ;
V_3 &= ~ V_11 ;
F_3 ( V_3 , V_2 -> V_4 ) ;
F_5 ( 10 ) ;
}
static bool F_6 ( struct V_1 * V_2 )
{
unsigned long V_3 = F_2 ( V_2 -> V_9 ) ;
return ( V_3 >> V_12 ) & V_13 ;
}
static int F_7 ( struct V_14 * V_15 ,
unsigned long * V_16 )
{
struct V_1 * V_2 = V_15 -> V_17 ;
unsigned long V_3 ;
if ( V_2 -> V_18 -> V_19 && ! V_2 -> V_18 -> V_19 ( V_2 ) ) {
F_8 ( & V_15 -> V_20 ,
L_1 ) ;
return - V_21 ;
}
V_3 = F_2 ( V_2 -> V_9 ) ;
V_3 = ( V_3 >> V_22 ) & V_23 ;
* V_16 = ( 3153000000UL - ( 10000000UL * V_3 ) ) / 13825 ;
return 0 ;
}
static int F_9 ( struct V_24 * V_25 )
{
struct V_14 * V_15 ;
const struct V_26 * V_27 ;
struct V_1 * V_2 ;
struct V_28 * V_29 ;
V_27 = F_10 ( V_30 , & V_25 -> V_31 ) ;
if ( ! V_27 )
return - V_32 ;
V_2 = F_11 ( & V_25 -> V_31 , sizeof( * V_2 ) , V_33 ) ;
if ( ! V_2 )
return - V_34 ;
V_29 = F_12 ( V_25 , V_35 , 0 ) ;
V_2 -> V_9 = F_13 ( & V_25 -> V_31 , V_29 ) ;
if ( F_14 ( V_2 -> V_9 ) )
return F_15 ( V_2 -> V_9 ) ;
V_29 = F_12 ( V_25 , V_35 , 1 ) ;
V_2 -> V_4 = F_13 ( & V_25 -> V_31 , V_29 ) ;
if ( F_14 ( V_2 -> V_4 ) )
return F_15 ( V_2 -> V_4 ) ;
V_2 -> V_18 = (struct V_36 * ) V_27 -> V_37 ;
V_2 -> V_18 -> V_38 ( V_2 ) ;
V_15 = F_16 ( L_2 , 0 , 0 ,
V_2 , & V_18 , NULL , 0 , 0 ) ;
if ( F_14 ( V_15 ) ) {
F_8 ( & V_25 -> V_31 ,
L_3 ) ;
return F_15 ( V_15 ) ;
}
F_17 ( V_25 , V_15 ) ;
return 0 ;
}
static int F_18 ( struct V_24 * V_25 )
{
struct V_14 * V_39 =
F_19 ( V_25 ) ;
F_20 ( V_39 ) ;
F_17 ( V_25 , NULL ) ;
return 0 ;
}
