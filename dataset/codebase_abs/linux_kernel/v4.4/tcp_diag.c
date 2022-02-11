static void F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
void * V_5 )
{
struct V_6 * V_7 = V_5 ;
if ( F_2 ( V_2 ) == V_8 ) {
V_4 -> V_9 = V_2 -> V_10 ;
V_4 -> V_11 = V_2 -> V_12 ;
} else if ( V_2 -> V_13 == V_14 ) {
const struct V_15 * V_16 = F_3 ( V_2 ) ;
V_4 -> V_9 = F_4 ( int , V_16 -> V_17 - V_16 -> V_18 , 0 ) ;
V_4 -> V_11 = V_16 -> V_19 - V_16 -> V_20 ;
}
if ( V_7 )
F_5 ( V_2 , V_7 ) ;
}
static void F_6 ( struct V_21 * V_22 , struct V_23 * V_24 ,
const struct V_25 * V_4 , struct V_26 * V_27 )
{
F_7 ( & V_28 , V_22 , V_24 , V_4 , V_27 ) ;
}
static int F_8 ( struct V_21 * V_29 , const struct V_30 * V_31 ,
const struct V_25 * V_32 )
{
return F_9 ( & V_28 , V_29 , V_31 , V_32 ) ;
}
static int T_1 F_10 ( void )
{
return F_11 ( & V_33 ) ;
}
static void T_2 F_12 ( void )
{
F_13 ( & V_33 ) ;
}
