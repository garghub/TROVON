static int F_1 ( struct V_1 * V_2 ,
const struct V_3 * V_4 )
{
struct V_5 * V_6 = & V_2 -> V_6 ;
const struct V_7 * V_8 = F_2 ( V_6 ) ;
struct V_9 V_10 [ 2 ] ;
struct V_11 * V_11 ;
int V_12 ;
if ( ! V_8 ) {
V_8 = F_3 ( V_6 , sizeof( * V_8 ) , V_13 ) ;
if ( ! V_8 )
return - V_14 ;
}
V_11 = F_4 ( V_2 , & V_15 ) ;
if ( F_5 ( V_11 ) ) {
F_6 ( V_6 , L_1 , F_7 ( V_11 ) ) ;
return F_7 ( V_11 ) ;
}
F_8 ( V_2 , V_11 ) ;
memset ( V_10 , 0 , sizeof( V_10 ) ) ;
V_10 [ 0 ] . V_16 = L_2 ;
V_10 [ 0 ] . V_17 = L_3 ;
V_10 [ 0 ] . V_18 = V_8 -> V_19 ;
V_10 [ 0 ] . V_20 = sizeof( * V_8 -> V_19 ) ;
V_10 [ 1 ] . V_16 = L_4 ;
V_10 [ 1 ] . V_18 = V_8 -> V_21 ;
V_10 [ 1 ] . V_20 = sizeof( * V_8 -> V_21 ) ;
V_12 = F_9 ( V_6 , - 1 , V_10 , F_10 ( V_10 ) ,
NULL , 0 , NULL ) ;
if ( V_12 )
F_6 ( V_6 , L_5 , V_12 ) ;
return V_12 ;
}
