static int F_1 ( const struct V_1 * V_2 )
{
const struct V_3 * V_4 = V_2 -> V_5 ;
if ( V_4 -> V_6 [ 0 ] . V_7 & V_8 ) {
F_2 ( L_1 ) ;
return - V_9 ;
}
if ( V_4 -> V_10 != 1 ) {
F_2 ( L_2 , V_4 -> V_10 ) ;
return - V_9 ;
}
return 0 ;
}
static unsigned int
F_3 ( struct V_11 * V_12 , const struct V_13 * V_2 )
{
struct V_14 V_6 ;
const struct V_3 * V_4 ;
V_4 = V_2 -> V_5 ;
V_6 . V_7 = V_4 -> V_6 [ 0 ] . V_7 ;
V_6 . V_15 = V_4 -> V_6 [ 0 ] . V_16 ;
V_6 . V_17 = V_4 -> V_6 [ 0 ] . V_18 ;
return F_4 ( V_12 , V_2 -> V_19 , & V_6 , V_2 -> V_20 ) ;
}
static int T_1 F_5 ( void )
{
int V_21 ;
V_21 = F_6 ( & V_22 ) ;
if ( V_21 == 0 )
F_7 () ;
return V_21 ;
}
static void T_2 F_8 ( void )
{
F_9 ( & V_22 ) ;
F_10 () ;
}
