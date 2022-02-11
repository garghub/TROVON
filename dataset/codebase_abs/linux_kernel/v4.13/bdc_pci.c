static int F_1 ( struct V_1 * V_2 )
{
int V_3 ;
V_3 = F_2 ( V_2 ) ;
if ( V_3 ) {
F_3 ( L_1 ) ;
return V_3 ;
}
return V_3 ;
}
static int F_4 ( struct V_1 * V_2 , const struct V_4 * V_5 )
{
struct V_6 V_7 [ 2 ] ;
struct V_8 * V_9 ;
struct V_10 * V_11 ;
int V_3 = - V_12 ;
V_11 = F_5 ( & V_2 -> V_13 , sizeof( * V_11 ) , V_14 ) ;
if ( ! V_11 )
return - V_12 ;
V_11 -> V_13 = & V_2 -> V_13 ;
V_3 = F_6 ( V_2 ) ;
if ( V_3 ) {
F_7 ( & V_2 -> V_13 , L_2 ) ;
return - V_15 ;
}
F_8 ( V_2 ) ;
V_9 = F_9 ( V_16 , V_17 ) ;
if ( ! V_9 )
return - V_12 ;
memset ( V_7 , 0x00 , sizeof( struct V_6 ) * F_10 ( V_7 ) ) ;
F_1 ( V_2 ) ;
V_7 [ 0 ] . V_18 = F_11 ( V_2 , 0 ) ;
V_7 [ 0 ] . V_19 = F_12 ( V_2 , 0 ) ;
V_7 [ 0 ] . V_20 = V_16 ;
V_7 [ 0 ] . V_21 = V_22 ;
V_7 [ 1 ] . V_18 = V_2 -> V_23 ;
V_7 [ 1 ] . V_20 = V_16 ;
V_7 [ 1 ] . V_21 = V_24 ;
V_3 = F_13 ( V_9 , V_7 , F_10 ( V_7 ) ) ;
if ( V_3 ) {
F_7 ( & V_2 -> V_13 ,
L_3 ) ;
return V_3 ;
}
F_14 ( V_2 , V_11 ) ;
F_15 ( & V_9 -> V_13 , V_2 -> V_13 . V_25 ) ;
V_9 -> V_13 . V_26 = V_2 -> V_13 . V_26 ;
V_9 -> V_13 . V_27 = V_2 -> V_13 . V_27 ;
V_9 -> V_13 . V_28 = & V_2 -> V_13 ;
V_11 -> V_9 = V_9 ;
V_3 = F_16 ( V_9 ) ;
if ( V_3 ) {
F_7 ( & V_2 -> V_13 , L_4 ) ;
F_17 ( V_9 ) ;
return V_3 ;
}
return 0 ;
}
static void F_18 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = F_19 ( V_2 ) ;
F_20 ( V_11 -> V_9 ) ;
F_21 ( V_2 ) ;
}
