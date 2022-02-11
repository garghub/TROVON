static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
V_4 -> V_5 [ 0 ] = V_6 ;
V_4 -> V_5 [ 1 ] = V_7 ;
V_4 -> V_5 [ 2 ] = V_8 ;
V_4 -> V_5 [ 3 ] = V_9 ;
V_4 -> V_5 [ 4 ] = V_10 ;
V_4 -> V_11 = 0 ;
V_4 -> V_12 = V_13 ;
return 0 ;
}
static int F_3 ( struct V_1 * V_2 , void * V_14 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_15 * V_16 = V_14 ;
V_16 -> V_11 = V_4 -> V_11 ;
memcpy ( V_16 -> V_5 , V_4 -> V_5 , sizeof( V_16 -> V_5 ) ) ;
memcpy ( V_16 -> V_17 , V_4 -> V_18 , sizeof( V_16 -> V_17 ) ) ;
return 0 ;
}
static int F_4 ( struct V_1 * V_2 , const void * V_19 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
const struct V_15 * V_20 = V_19 ;
V_4 -> V_11 = V_20 -> V_11 ;
memcpy ( V_4 -> V_5 , V_20 -> V_5 , sizeof( V_20 -> V_5 ) ) ;
memcpy ( V_4 -> V_18 , V_20 -> V_17 , sizeof( V_20 -> V_17 ) ) ;
V_4 -> V_12 = V_13 ;
return 0 ;
}
static int T_1 F_5 ( void )
{
if ( ! F_6 ( V_13 , V_21 ) )
return - V_22 ;
return F_7 ( & V_23 ) ;
}
static void T_2 F_8 ( void )
{
F_9 ( & V_23 ) ;
}
