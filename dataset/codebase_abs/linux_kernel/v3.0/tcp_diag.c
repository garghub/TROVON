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
if ( V_9 != NULL )
F_4 ( V_2 , V_9 ) ;
}
static int T_1 F_5 ( void )
{
return F_6 ( & V_20 ) ;
}
static void T_2 F_7 ( void )
{
F_8 ( & V_20 ) ;
}
