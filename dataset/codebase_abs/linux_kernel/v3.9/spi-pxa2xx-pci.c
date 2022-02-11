static int F_1 ( struct V_1 * V_2 ,
const struct V_3 * V_4 )
{
struct V_5 V_6 ;
int V_7 ;
struct V_8 * V_9 ;
struct V_10 V_11 ;
struct V_12 * V_13 ;
V_7 = F_2 ( V_2 ) ;
if ( V_7 )
return V_7 ;
V_7 = F_3 ( V_2 , 1 << 0 , L_1 ) ;
if ( ! V_7 )
return V_7 ;
memset ( & V_11 , 0 , sizeof( V_11 ) ) ;
V_11 . V_14 = V_2 -> V_15 ;
V_13 = & V_11 . V_13 ;
V_13 -> V_16 = F_4 ( V_2 , 0 ) ;
V_13 -> V_17 = F_5 ( V_2 ) [ 0 ] ;
if ( ! V_13 -> V_17 ) {
F_6 ( & V_2 -> V_2 , L_2 ) ;
return - V_18 ;
}
V_13 -> V_19 = V_2 -> V_19 ;
V_13 -> V_20 = V_2 -> V_15 ;
V_13 -> type = V_21 ;
memset ( & V_6 , 0 , sizeof( V_6 ) ) ;
V_6 . V_22 = & V_2 -> V_2 ;
V_6 . V_23 = L_3 ;
V_6 . V_24 = V_13 -> V_20 ;
V_6 . V_25 = & V_11 ;
V_6 . V_26 = sizeof( V_11 ) ;
V_9 = F_7 ( & V_6 ) ;
if ( ! V_9 )
return - V_27 ;
F_8 ( V_2 , V_9 ) ;
return 0 ;
}
static void F_9 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = F_10 ( V_2 ) ;
F_11 ( V_9 ) ;
}
