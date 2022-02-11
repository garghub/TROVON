static int F_1 ( struct V_1 * V_2 ,
const struct V_3 * V_4 )
{
struct V_5 * V_6 = ( void * ) V_4 -> V_7 ;
struct V_8 * V_9 ;
struct V_10 V_11 [ 3 ] ;
int V_12 = 0 , V_13 = 2 ;
if ( ! V_6 ) {
F_2 ( & V_2 -> V_14 , L_1 ) ;
return - V_15 ;
}
V_12 = F_3 ( V_2 ) ;
if ( V_12 )
return V_12 ;
if ( ! V_2 -> V_16 ) {
F_2 ( & V_2 -> V_14 , L_2 ) ;
return - V_15 ;
}
F_4 ( V_2 ) ;
F_5 ( V_2 ) ;
memset ( V_11 , 0 , sizeof( V_11 ) ) ;
V_11 [ 0 ] . V_17 = F_6 ( V_2 , 0 ) ;
V_11 [ 0 ] . V_18 = F_7 ( V_2 , 0 ) ;
V_11 [ 0 ] . V_19 = V_20 ;
V_11 [ 1 ] . V_17 = V_2 -> V_16 ;
V_11 [ 1 ] . V_19 = V_21 ;
V_9 = F_8 ( & V_2 -> V_14 , V_11 , V_13 , V_6 ) ;
if ( F_9 ( V_9 ) ) {
F_2 ( & V_2 -> V_14 , L_3 ) ;
return F_10 ( V_9 ) ;
}
F_11 ( V_2 , V_9 ) ;
return 0 ;
}
static void F_12 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = F_13 ( V_2 ) ;
F_14 ( V_9 ) ;
}
