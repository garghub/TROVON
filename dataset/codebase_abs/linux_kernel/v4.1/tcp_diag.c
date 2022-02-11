static void F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
void * V_5 )
{
const struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = V_5 ;
if ( V_2 -> V_10 == V_11 ) {
V_4 -> V_12 = V_2 -> V_13 ;
V_4 -> V_14 = V_2 -> V_15 ;
} else {
V_4 -> V_12 = F_3 ( int , V_7 -> V_16 - V_7 -> V_17 , 0 ) ;
V_4 -> V_14 = V_7 -> V_18 - V_7 -> V_19 ;
}
if ( V_9 )
F_4 ( V_2 , V_9 ) ;
}
static void F_5 ( struct V_20 * V_21 , struct V_22 * V_23 ,
const struct V_24 * V_4 , struct V_25 * V_26 )
{
F_6 ( & V_27 , V_21 , V_23 , V_4 , V_26 ) ;
}
static int F_7 ( struct V_20 * V_28 , const struct V_29 * V_30 ,
const struct V_24 * V_31 )
{
return F_8 ( & V_27 , V_28 , V_30 , V_31 ) ;
}
static int T_1 F_9 ( void )
{
return F_10 ( & V_32 ) ;
}
static void T_2 F_11 ( void )
{
F_12 ( & V_32 ) ;
}
