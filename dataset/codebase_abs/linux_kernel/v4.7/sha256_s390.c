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
static int F_5 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
V_4 -> V_5 [ 0 ] = V_23 ;
V_4 -> V_5 [ 1 ] = V_24 ;
V_4 -> V_5 [ 2 ] = V_25 ;
V_4 -> V_5 [ 3 ] = V_26 ;
V_4 -> V_5 [ 4 ] = V_27 ;
V_4 -> V_5 [ 5 ] = V_28 ;
V_4 -> V_5 [ 6 ] = V_29 ;
V_4 -> V_5 [ 7 ] = V_30 ;
V_4 -> V_14 = 0 ;
V_4 -> V_15 = V_16 ;
return 0 ;
}
static int T_1 F_6 ( void )
{
int V_31 ;
if ( ! F_7 ( V_32 , V_16 ) )
return - V_33 ;
V_31 = F_8 ( & V_34 ) ;
if ( V_31 < 0 )
goto V_17;
V_31 = F_8 ( & V_35 ) ;
if ( V_31 < 0 )
F_9 ( & V_34 ) ;
V_17:
return V_31 ;
}
static void T_2 F_10 ( void )
{
F_9 ( & V_35 ) ;
F_9 ( & V_34 ) ;
}
