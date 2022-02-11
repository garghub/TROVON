int
F_1 ( T_1 )
{
struct V_1 * V_2 = V_3 -> V_4 . V_5 . V_6 . V_2 ;
const T_2 V_7 = V_8 -> V_9 * 0x800 ;
union {
struct V_10 V_11 ;
} * args = V_12 ;
T_2 V_13 , type ;
int V_14 = - V_15 ;
F_2 ( V_16 , L_1 , V_17 ) ;
if ( ! ( V_14 = F_3 ( V_14 , & V_12 , & V_17 , args -> V_11 , 0 , 0 , false ) ) ) {
F_2 ( V_16 , L_2 ,
args -> V_11 . V_18 , args -> V_11 . V_19 , args -> V_11 . type ) ;
if ( args -> V_11 . type > 0x0f )
return - V_20 ;
V_13 = ! ! args -> V_11 . V_19 ;
type = args -> V_11 . type ;
} else
return V_14 ;
F_4 (device, 2000 ,
if (!(nvkm_rd32(device, 0x61e004 + soff) & 0x80000000))
break;
) ;
F_5 ( V_2 , 0x61e004 + V_7 , 0x80000101 , 0x80000000 | V_13 ) ;
F_4 (device, 2000 ,
if (!(nvkm_rd32(device, 0x61e004 + soff) & 0x80000000))
break;
) ;
V_3 -> V_21 . type [ V_8 -> V_9 ] = type ;
return 0 ;
}
int
F_6 ( struct V_22 * V_3 , int V_23 ,
struct V_24 * V_25 , struct V_26 * * V_27 )
{
return F_7 ( & V_28 , V_3 ,
V_23 , V_25 , V_27 ) ;
}
static int
F_8 ( struct V_29 * V_8 , int V_30 )
{
return 0 ;
}
static int
F_9 ( struct V_29 * V_8 , int V_31 )
{
return 0 ;
}
static int
F_10 ( struct V_29 * V_8 ,
int V_31 , int V_32 , bool V_33 )
{
int V_14 = F_11 ( V_8 -> V_34 , V_31 , V_32 , V_33 ) ;
if ( V_14 )
return V_14 ;
return 1 ;
}
int
F_12 ( struct V_22 * V_3 , int V_23 , struct V_24 * V_25 ,
struct V_26 * * V_27 )
{
struct V_35 * V_36 = V_3 -> V_5 . V_6 . V_2 -> V_36 ;
struct V_37 * V_34 =
F_13 ( V_36 , F_14 ( V_25 -> V_38 ) ) ;
struct V_29 * V_8 ;
if ( ! ( V_8 = F_15 ( sizeof( * V_8 ) , V_39 ) ) )
return - V_40 ;
* V_27 = & V_8 -> V_4 ;
return F_16 ( & V_41 , V_3 ,
V_23 , V_25 , V_34 , V_8 ) ;
}
