static int
F_1 ( const struct V_1 * V_2 , const char * V_3 ,
struct V_4 * V_5 )
{
const struct V_6 * V_7 , * V_8 , * V_9 ;
char V_10 [ 64 ] ;
int V_11 ;
snprintf ( V_10 , sizeof( V_10 ) , L_1 , V_3 ) ;
V_11 = F_2 ( V_2 -> V_12 , V_10 , & V_7 ) ;
if ( V_11 )
return V_11 ;
V_5 -> V_13 = F_3 ( V_7 -> V_14 , V_7 -> V_15 , V_16 ) ;
F_4 ( V_7 ) ;
if ( ! V_5 -> V_13 )
return - V_17 ;
snprintf ( V_10 , sizeof( V_10 ) , L_2 , V_3 ) ;
V_11 = F_2 ( V_2 -> V_12 , V_10 , & V_8 ) ;
if ( V_11 )
return V_11 ;
memcpy ( & V_5 -> V_18 , V_8 -> V_14 , sizeof( V_5 -> V_18 ) ) ;
V_5 -> V_19 = F_5 ( V_5 -> V_18 . V_20 + V_5 -> V_18 . V_21 , 256 ) ;
F_4 ( V_8 ) ;
snprintf ( V_10 , sizeof( V_10 ) , L_3 , V_3 ) ;
V_11 = F_2 ( V_2 -> V_12 , V_10 , & V_9 ) ;
if ( V_11 )
return V_11 ;
V_5 -> V_22 = V_9 -> V_15 ;
V_5 -> V_9 = F_3 ( V_9 -> V_14 , V_9 -> V_15 , V_16 ) ;
F_4 ( V_9 ) ;
if ( ! V_5 -> V_9 )
return - V_17 ;
return 0 ;
}
static int
F_6 ( struct V_23 * V_24 ,
struct V_25 * V_26 , T_1 V_27 )
{
struct V_28 * V_12 = V_26 -> V_29 -> V_12 ;
T_1 V_30 = V_31 ;
T_2 V_32 [ V_30 ] ;
memset ( V_32 , 0 , V_30 ) ;
F_7 ( V_24 , V_32 ) ;
F_8 ( V_26 , V_32 , V_27 , V_30 , 0 ) ;
F_9 ( V_24 ) ;
F_10 ( V_26 , 0x10 , 0xff ) ;
F_11 ( V_12 , V_26 -> V_29 -> V_33 , true ) ;
F_12 ( V_26 ) ;
return 0 ;
}
int
F_13 ( const struct V_34 * V_35 , struct V_4 * V_5 )
{
struct V_36 * V_37 = V_35 -> V_2 . V_12 -> V_37 ;
int V_11 ;
V_11 = F_1 ( & V_35 -> V_2 , L_4 , V_5 ) ;
if ( V_11 )
return V_11 ;
V_11 = F_14 ( V_5 -> V_18 . V_38 , V_37 -> V_26 ,
V_35 , & V_37 -> V_24 ) ;
if ( V_11 )
return V_11 ;
return 0 ;
}
int
F_15 ( const struct V_39 * V_40 , const struct V_34 * V_35 )
{
struct V_28 * V_12 = V_35 -> V_2 . V_12 ;
struct V_36 * V_37 = V_12 -> V_37 ;
T_1 V_27 = V_37 -> V_26 -> V_14 . V_41 - V_31 ;
int V_11 ;
V_11 = F_6 ( V_37 -> V_24 , V_37 -> V_26 , V_27 ) ;
if ( V_11 )
return V_11 ;
F_16 ( & V_35 -> V_2 , L_5 ,
V_42 [ V_40 -> V_43 ] ) ;
return 0 ;
}
int
F_17 ( const struct V_34 * V_35 , struct V_4 * V_5 )
{
struct V_44 * V_45 = V_35 -> V_2 . V_12 -> V_46 ;
int V_11 ;
V_11 = F_1 ( & V_35 -> V_2 , L_6 , V_5 ) ;
if ( V_11 )
return V_11 ;
V_11 = F_14 ( V_5 -> V_18 . V_38 , V_45 -> V_26 ,
V_35 , & V_45 -> V_24 ) ;
if ( V_11 )
return V_11 ;
return 0 ;
}
int
F_18 ( const struct V_39 * V_40 , const struct V_34 * V_35 )
{
const struct V_1 * V_2 = & V_35 -> V_2 ;
struct V_28 * V_12 = V_2 -> V_12 ;
struct V_44 * V_45 = V_12 -> V_46 ;
const T_1 V_27 = 0x01000000 ;
T_1 V_47 ;
int V_11 ;
V_11 = F_6 ( V_45 -> V_24 , V_45 -> V_26 , V_27 ) ;
if ( V_11 )
return V_11 ;
F_19 (device, 1 ,
if ((reg = nvkm_falcon_rd32(sb->boot_falcon, 0x100) & 0x30) != 0)
break;
) ;
if ( V_47 & F_20 ( 4 ) ) {
F_16 ( V_2 , L_7 ) ;
F_12 ( V_35 -> V_43 ) ;
F_19 (subdev->device, 1 ,
if ((reg = nvkm_rd32(subdev->device,
sb->boot_falcon->addr + 0x100)
& 0x30) != 0)
break;
) ;
if ( V_47 & F_20 ( 4 ) ) {
F_21 ( V_2 , L_8 ,
V_42 [ V_40 -> V_43 ] ) ;
return - V_48 ;
}
}
F_16 ( & V_35 -> V_2 , L_5 ,
V_42 [ V_40 -> V_43 ] ) ;
return 0 ;
}
