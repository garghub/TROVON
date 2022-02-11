static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
V_4 -> V_5 [ 0 ] = V_6 ;
V_4 -> V_5 [ 1 ] = V_7 ;
V_4 -> V_5 [ 2 ] = V_8 ;
V_4 -> V_5 [ 3 ] = V_9 ;
V_4 -> V_5 [ 4 ] = V_10 ;
V_4 -> V_5 [ 5 ] = V_11 ;
V_4 -> V_5 [ 6 ] = V_12 ;
V_4 -> V_5 [ 7 ] = V_13 ;
V_4 -> V_14 = 0 ;
V_4 -> V_15 = V_16 ;
return 0 ;
}
static int F_3 ( struct V_1 * V_2 , void * V_17 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_18 * V_19 = V_17 ;
V_19 -> V_14 = V_4 -> V_14 ;
memcpy ( V_19 -> V_5 , V_4 -> V_5 , sizeof( V_19 -> V_5 ) ) ;
memcpy ( V_19 -> V_20 , V_4 -> V_20 , sizeof( V_19 -> V_20 ) ) ;
return 0 ;
}
static int F_4 ( struct V_1 * V_2 , const void * V_21 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
const struct V_18 * V_22 = V_21 ;
V_4 -> V_14 = V_22 -> V_14 ;
memcpy ( V_4 -> V_5 , V_22 -> V_5 , sizeof( V_22 -> V_5 ) ) ;
memcpy ( V_4 -> V_20 , V_22 -> V_20 , sizeof( V_22 -> V_20 ) ) ;
V_4 -> V_15 = V_16 ;
return 0 ;
}
static int F_5 ( void )
{
if ( ! F_6 ( V_16 , V_23 ) )
return - V_24 ;
return F_7 ( & V_25 ) ;
}
static void T_1 F_8 ( void )
{
F_9 ( & V_25 ) ;
}
