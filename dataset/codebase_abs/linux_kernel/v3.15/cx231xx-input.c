static int F_1 ( struct V_1 * V_2 , T_1 * V_3 ,
T_1 * V_4 )
{
int V_5 ;
T_2 V_6 , V_7 ;
F_2 ( & V_2 -> V_5 -> V_8 -> V_9 , L_1 , V_10 ) ;
V_5 = F_3 ( V_2 -> V_11 , & V_6 , 1 ) ;
if ( V_5 < 0 )
return V_5 ;
if ( V_5 != 1 )
return - V_12 ;
if ( V_6 == 0xff )
return 0 ;
V_7 =
( ( V_6 & 0x01 ) ? 0x80 : 0 ) |
( ( V_6 & 0x02 ) ? 0x40 : 0 ) |
( ( V_6 & 0x04 ) ? 0x20 : 0 ) |
( ( V_6 & 0x08 ) ? 0x10 : 0 ) |
( ( V_6 & 0x10 ) ? 0x08 : 0 ) |
( ( V_6 & 0x20 ) ? 0x04 : 0 ) |
( ( V_6 & 0x40 ) ? 0x02 : 0 ) |
( ( V_6 & 0x80 ) ? 0x01 : 0 ) ;
F_2 ( & V_2 -> V_5 -> V_8 -> V_9 , L_2 ,
V_6 , V_7 ) ;
* V_3 = V_7 ;
* V_4 = V_7 ;
return 1 ;
}
int F_4 ( struct V_13 * V_9 )
{
struct V_14 V_15 ;
T_2 V_16 ;
F_2 ( & V_9 -> V_17 -> V_9 , L_1 , V_10 ) ;
if ( ! V_18 [ V_9 -> V_19 ] . V_20 )
return - V_21 ;
F_5 ( L_3 ) ;
memset ( & V_15 , 0 , sizeof( struct V_14 ) ) ;
memset ( & V_9 -> V_22 , 0 , sizeof( V_9 -> V_22 ) ) ;
V_9 -> V_22 . V_23 = F_6 () ;
if ( ! V_9 -> V_22 . V_23 )
return - V_24 ;
V_9 -> V_22 . V_25 = V_18 [ V_9 -> V_19 ] . V_25 ;
F_7 ( V_15 . type , L_4 , V_26 ) ;
V_15 . V_27 = & V_9 -> V_22 ;
V_9 -> V_22 . V_28 = F_1 ;
V_9 -> V_22 . V_29 = V_18 [ V_9 -> V_19 ] . V_20 ;
V_9 -> V_22 . V_23 -> V_30 = 0xff ;
V_9 -> V_22 . V_23 -> V_31 = L_5 ;
V_9 -> V_22 . type = V_32 ;
V_15 . V_33 = 0x30 ;
V_16 = V_18 [ V_9 -> V_19 ] . V_34 ;
F_2 ( & V_9 -> V_17 -> V_9 , L_6 ,
V_16 , V_15 . V_33 ) ;
V_9 -> V_35 = F_8 ( & V_9 -> V_36 [ V_16 ] . V_37 , & V_15 ) ;
return 0 ;
}
void F_9 ( struct V_13 * V_9 )
{
if ( V_9 -> V_35 )
F_10 ( V_9 -> V_35 ) ;
V_9 -> V_35 = NULL ;
}
