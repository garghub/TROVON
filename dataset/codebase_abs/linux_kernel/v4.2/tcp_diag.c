static void F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
void * V_5 )
{
struct V_6 * V_7 = V_5 ;
if ( V_2 -> V_8 == V_9 ) {
V_4 -> V_10 = V_2 -> V_11 ;
V_4 -> V_12 = V_2 -> V_13 ;
} else if ( V_2 -> V_14 == V_15 ) {
const struct V_16 * V_17 = F_2 ( V_2 ) ;
V_4 -> V_10 = F_3 ( int , V_17 -> V_18 - V_17 -> V_19 , 0 ) ;
V_4 -> V_12 = V_17 -> V_20 - V_17 -> V_21 ;
}
if ( V_7 )
F_4 ( V_2 , V_7 ) ;
}
static void F_5 ( struct V_22 * V_23 , struct V_24 * V_25 ,
const struct V_26 * V_4 , struct V_27 * V_28 )
{
F_6 ( & V_29 , V_23 , V_25 , V_4 , V_28 ) ;
}
static int F_7 ( struct V_22 * V_30 , const struct V_31 * V_32 ,
const struct V_26 * V_33 )
{
return F_8 ( & V_29 , V_30 , V_32 , V_33 ) ;
}
static int T_1 F_9 ( void )
{
return F_10 ( & V_34 ) ;
}
static void T_2 F_11 ( void )
{
F_12 ( & V_34 ) ;
}
