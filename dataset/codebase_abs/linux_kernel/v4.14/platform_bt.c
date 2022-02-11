static int T_1 F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = & V_5 ;
struct V_6 * V_7 = V_4 -> V_4 ;
struct V_8 * V_9 ;
V_9 = F_2 ( 0 , 0 , F_3 ( 4 , 1 ) ) ;
if ( ! V_9 )
return - V_10 ;
V_2 -> V_11 = & V_9 -> V_11 ;
V_2 -> V_12 = V_4 -> V_13 ;
V_7 [ 0 ] . V_14 = F_4 ( V_15 ) ;
V_7 [ 1 ] . V_14 = F_4 ( V_16 ) ;
V_7 [ 2 ] . V_14 = F_4 ( V_17 ) ;
F_5 ( V_4 ) ;
return 0 ;
}
static int T_1 F_6 ( void )
{
struct V_18 V_19 ;
struct V_20 * V_9 ;
const struct V_21 * V_22 ;
struct V_1 * V_2 ;
int V_23 ;
V_22 = F_7 ( V_24 ) ;
if ( ! V_22 )
return - V_10 ;
V_2 = (struct V_1 * ) V_22 -> V_25 ;
if ( ! V_2 )
return - V_10 ;
V_23 = V_2 -> V_26 ( V_2 ) ;
if ( V_23 )
return V_23 ;
memset ( & V_19 , 0 , sizeof( V_19 ) ) ;
V_19 . V_27 = V_2 -> V_11 -> V_27 ;
V_19 . V_28 = V_2 -> V_11 ;
V_19 . V_12 = V_2 -> V_12 ,
V_19 . V_22 = V_29 ,
V_9 = F_8 ( & V_19 ) ;
if ( F_9 ( V_9 ) )
return F_10 ( V_9 ) ;
F_11 ( V_2 -> V_11 , L_1 , V_2 -> V_12 ) ;
return 0 ;
}
