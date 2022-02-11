static int F_1 ( struct V_1 * V_2 )
{
int V_3 ;
V_3 = F_2 ( V_4 ,
F_3 ( V_4 ) ) ;
V_2 -> V_5 . V_6 = F_4 ( V_7 ) ;
return V_3 ;
}
static void F_5 ( struct V_1 * V_2 )
{
F_6 ( V_4 , F_3 ( V_4 ) ) ;
}
static void F_7 ( struct V_1 * V_2 ,
struct V_8 * V_9 )
{
V_9 -> V_10 = 1 ;
V_9 -> V_11 = ! ! F_8 ( V_7 ) ;
V_9 -> V_12 = 1 ;
V_9 -> V_13 = 1 ;
V_9 -> V_14 = 0 ;
V_9 -> V_15 = 1 ;
V_9 -> V_16 = 0 ;
}
static int F_9 ( struct V_1 * V_2 ,
const T_1 * V_9 )
{
F_10 ( V_17 , 1 ) ;
F_10 ( V_18 ,
! ! ( V_9 -> V_19 & V_20 ) ) ;
return 0 ;
}
static void F_11 ( struct V_1 * V_2 )
{
}
static void F_12 ( struct V_1 * V_2 )
{
}
static int T_2 F_13 ( void )
{
int V_3 ;
if ( ! F_14 () )
return - V_21 ;
V_22 = F_15 ( L_1 , - 1 ) ;
if ( ! V_22 )
return - V_23 ;
V_3 = F_16 ( V_22 , & V_24 ,
sizeof( V_24 ) ) ;
if ( ! V_3 )
V_3 = F_17 ( V_22 ) ;
if ( V_3 )
F_18 ( V_22 ) ;
return V_3 ;
}
static void T_3 F_19 ( void )
{
F_20 ( V_22 ) ;
}
