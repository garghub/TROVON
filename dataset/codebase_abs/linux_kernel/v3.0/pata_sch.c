static void F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
unsigned int V_5 = V_4 -> V_6 - V_7 ;
struct V_8 * V_9 = F_2 ( V_2 -> V_10 -> V_9 ) ;
unsigned int V_11 = V_4 -> V_12 ? V_13 : V_14 ;
unsigned int V_15 ;
F_3 ( V_9 , V_11 , & V_15 ) ;
V_15 &= ~ ( V_16 | V_17 ) ;
V_15 |= V_5 ;
if ( V_4 -> V_18 == V_19 )
V_15 |= V_17 ;
F_4 ( V_9 , V_11 , V_15 ) ;
}
static void F_5 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
unsigned int V_20 = V_4 -> V_20 ;
struct V_8 * V_9 = F_2 ( V_2 -> V_10 -> V_9 ) ;
unsigned int V_11 = V_4 -> V_12 ? V_13 : V_14 ;
unsigned int V_15 ;
F_3 ( V_9 , V_11 , & V_15 ) ;
if ( V_20 >= V_21 ) {
V_15 |= V_22 ;
V_15 &= ~ V_23 ;
V_15 |= ( V_20 - V_21 ) << 16 ;
} else {
V_15 &= ~ ( V_22 | V_24 ) ;
V_15 |= ( V_20 - V_25 ) << 8 ;
}
F_4 ( V_9 , V_11 , V_15 ) ;
}
static int T_1 F_6 ( struct V_8 * V_26 ,
const struct V_27 * V_28 )
{
static int V_29 ;
const struct V_30 * V_31 [] = { & V_32 , NULL } ;
if ( ! V_29 ++ )
F_7 ( V_33 , & V_26 -> V_9 ,
L_1 V_34 L_2 ) ;
return F_8 ( V_26 , V_31 , & V_35 , NULL , 0 ) ;
}
static int T_2 F_9 ( void )
{
return F_10 ( & V_36 ) ;
}
static void T_3 F_11 ( void )
{
F_12 ( & V_36 ) ;
}
