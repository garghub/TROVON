static int F_1 ( struct V_1 * V_2 , enum V_3 * V_4 ,
T_1 * V_5 , T_2 * V_6 )
{
int V_7 ;
T_2 V_8 , V_9 ;
F_2 ( & V_2 -> V_7 -> V_10 , L_1 , V_11 ) ;
V_7 = F_3 ( V_2 -> V_12 , & V_8 , 1 ) ;
if ( V_7 < 0 )
return V_7 ;
if ( V_7 != 1 )
return - V_13 ;
if ( V_8 == 0xff )
return 0 ;
V_9 = F_4 ( V_8 ) ;
F_2 ( & V_2 -> V_7 -> V_10 , L_2 , V_8 , V_9 ) ;
* V_4 = V_14 ;
* V_5 = V_9 ;
* V_6 = 0 ;
return 1 ;
}
int F_5 ( struct V_15 * V_10 )
{
struct V_16 V_17 ;
T_2 V_18 ;
F_2 ( V_10 -> V_10 , L_1 , V_11 ) ;
if ( ! V_19 [ V_10 -> V_20 ] . V_21 )
return - V_22 ;
F_6 ( L_3 ) ;
memset ( & V_17 , 0 , sizeof( struct V_16 ) ) ;
memset ( & V_10 -> V_23 , 0 , sizeof( V_10 -> V_23 ) ) ;
V_10 -> V_23 . V_24 = F_7 ( V_25 ) ;
if ( ! V_10 -> V_23 . V_24 )
return - V_26 ;
V_10 -> V_23 . V_27 = V_19 [ V_10 -> V_20 ] . V_27 ;
F_8 ( V_17 . type , L_4 , V_28 ) ;
V_17 . V_29 = & V_10 -> V_23 ;
V_10 -> V_23 . V_30 = F_1 ;
V_10 -> V_23 . V_31 = V_19 [ V_10 -> V_20 ] . V_21 ;
V_10 -> V_23 . V_24 -> V_32 = 0xff ;
V_10 -> V_23 . V_24 -> V_33 = L_5 ;
V_10 -> V_23 . type = V_34 ;
V_17 . V_35 = 0x30 ;
V_18 = V_19 [ V_10 -> V_20 ] . V_36 ;
F_2 ( V_10 -> V_10 , L_6 ,
V_18 , V_17 . V_35 ) ;
V_10 -> V_37 = F_9 (
F_10 ( V_10 , V_18 ) , & V_17 ) ;
return 0 ;
}
void F_11 ( struct V_15 * V_10 )
{
if ( V_10 -> V_37 )
F_12 ( V_10 -> V_37 ) ;
V_10 -> V_37 = NULL ;
}
