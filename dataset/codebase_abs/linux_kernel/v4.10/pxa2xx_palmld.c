static int F_1 ( struct V_1 * V_2 )
{
int V_3 ;
V_3 = F_2 ( V_4 ,
F_3 ( V_4 ) ) ;
V_2 -> V_5 [ V_6 ] . V_7 = V_8 ;
V_2 -> V_5 [ V_6 ] . V_9 = L_1 ;
return V_3 ;
}
static void F_4 ( struct V_1 * V_2 )
{
F_5 ( V_4 , F_3 ( V_4 ) ) ;
}
static void F_6 ( struct V_1 * V_2 ,
struct V_10 * V_11 )
{
V_11 -> V_12 = 1 ;
V_11 -> V_13 = 1 ;
V_11 -> V_14 = 0 ;
}
static int F_7 ( struct V_1 * V_2 ,
const T_1 * V_11 )
{
F_8 ( V_15 , 1 ) ;
F_8 ( V_16 ,
! ! ( V_11 -> V_17 & V_18 ) ) ;
return 0 ;
}
static int T_2 F_9 ( void )
{
int V_3 ;
if ( ! F_10 () )
return - V_19 ;
V_20 = F_11 ( L_2 , - 1 ) ;
if ( ! V_20 )
return - V_21 ;
V_3 = F_12 ( V_20 , & V_22 ,
sizeof( V_22 ) ) ;
if ( ! V_3 )
V_3 = F_13 ( V_20 ) ;
if ( V_3 )
F_14 ( V_20 ) ;
return V_3 ;
}
static void T_3 F_15 ( void )
{
F_16 ( V_20 ) ;
}
