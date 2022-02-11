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
return F_3 ( V_2 -> V_11 , V_2 -> V_12 ) ;
}
static unsigned int
F_4 ( struct V_13 * V_14 , const struct V_15 * V_2 )
{
struct V_16 V_6 ;
const struct V_3 * V_4 ;
V_4 = V_2 -> V_5 ;
V_6 . V_7 = V_4 -> V_6 [ 0 ] . V_7 ;
V_6 . V_17 = V_4 -> V_6 [ 0 ] . V_18 ;
V_6 . V_19 = V_4 -> V_6 [ 0 ] . V_20 ;
return F_5 ( V_14 , F_6 ( V_2 ) , & V_6 ,
F_7 ( V_2 ) ) ;
}
static void F_8 ( const struct V_21 * V_2 )
{
F_9 ( V_2 -> V_11 , V_2 -> V_12 ) ;
}
static int T_1 F_10 ( void )
{
int V_22 ;
V_22 = F_11 ( & V_23 ) ;
if ( V_22 == 0 )
F_12 () ;
return V_22 ;
}
static void T_2 F_13 ( void )
{
F_14 ( & V_23 ) ;
F_15 () ;
}
