static int F_1 ( struct V_1 * V_2 )
{
V_2 -> V_3 = V_4 ;
V_2 -> V_5 = V_4 ;
return 0 ;
}
static int F_2 ( struct V_1 * V_2 )
{
return 0 ;
}
static int F_3 ( struct V_1 * V_2 )
{
int V_6 ;
if ( ! F_4 ( V_2 , V_7 , 93 ) ) {
V_6 = F_4 ( V_2 , V_8 , V_9 ) ;
return ( V_6 < 0 ) ? V_6 : ( V_6 & V_10 ) ;
}
return 1 ;
}
static int F_5 ( struct V_1 * V_2 )
{
return 0 ;
}
static int F_6 ( struct V_1 * V_2 )
{
int V_6 ;
V_2 -> V_11 = 1 ;
V_2 -> V_12 = V_13 ;
V_2 -> V_14 = V_15 ;
if ( ! F_4 ( V_2 , V_7 , 93 ) ) {
V_6 = F_4 ( V_2 , V_16 , V_17 ) ;
if ( V_6 < 0 ||
! ( ( V_6 & V_18 ) == V_18 ) ) {
V_2 -> V_11 = 0 ;
return 0 ;
}
V_6 = F_4 ( V_2 , V_8 , V_9 ) ;
if ( V_6 < 0 || ! ( V_6 & V_19 ) )
V_2 -> V_11 = 0 ;
}
return 0 ;
}
static int F_7 ( struct V_1 * V_2 )
{
return V_2 -> V_20 . V_21 [ 3 ] == V_22 ;
}
static int T_1 F_8 ( void )
{
return F_9 ( V_23 ,
F_10 ( V_23 ) ) ;
}
static void T_2 F_11 ( void )
{
return F_12 ( V_23 ,
F_10 ( V_23 ) ) ;
}
