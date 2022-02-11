static int F_1 ( struct V_1 * V_2 , enum V_3 * V_4 ,
T_1 * V_5 , T_2 * V_6 )
{
int V_7 ;
T_2 V_8 , V_9 ;
F_2 ( & V_2 -> V_7 -> V_10 -> V_11 , L_1 , V_12 ) ;
V_7 = F_3 ( V_2 -> V_13 , & V_8 , 1 ) ;
if ( V_7 < 0 )
return V_7 ;
if ( V_7 != 1 )
return - V_14 ;
if ( V_8 == 0xff )
return 0 ;
V_9 = F_4 ( V_8 ) ;
F_2 ( & V_2 -> V_7 -> V_10 -> V_11 , L_2 ,
V_8 , V_9 ) ;
* V_4 = V_15 ;
* V_5 = V_9 ;
* V_6 = 0 ;
return 1 ;
}
int F_5 ( struct V_16 * V_11 )
{
struct V_17 V_18 ;
T_2 V_19 ;
F_2 ( & V_11 -> V_20 -> V_11 , L_1 , V_12 ) ;
if ( ! V_21 [ V_11 -> V_22 ] . V_23 )
return - V_24 ;
F_6 ( L_3 ) ;
memset ( & V_18 , 0 , sizeof( struct V_17 ) ) ;
memset ( & V_11 -> V_25 , 0 , sizeof( V_11 -> V_25 ) ) ;
V_11 -> V_25 . V_26 = F_7 () ;
if ( ! V_11 -> V_25 . V_26 )
return - V_27 ;
V_11 -> V_25 . V_28 = V_21 [ V_11 -> V_22 ] . V_28 ;
F_8 ( V_18 . type , L_4 , V_29 ) ;
V_18 . V_30 = & V_11 -> V_25 ;
V_11 -> V_25 . V_31 = F_1 ;
V_11 -> V_25 . V_32 = V_21 [ V_11 -> V_22 ] . V_23 ;
V_11 -> V_25 . V_26 -> V_33 = 0xff ;
V_11 -> V_25 . V_26 -> V_34 = L_5 ;
V_11 -> V_25 . type = V_35 ;
V_18 . V_36 = 0x30 ;
V_19 = V_21 [ V_11 -> V_22 ] . V_37 ;
F_2 ( & V_11 -> V_20 -> V_11 , L_6 ,
V_19 , V_18 . V_36 ) ;
V_11 -> V_38 = F_9 ( & V_11 -> V_39 [ V_19 ] . V_40 , & V_18 ) ;
return 0 ;
}
void F_10 ( struct V_16 * V_11 )
{
if ( V_11 -> V_38 )
F_11 ( V_11 -> V_38 ) ;
V_11 -> V_38 = NULL ;
}
