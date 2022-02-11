int
F_1 ( T_1 )
{
struct V_1 * V_2 = V_3 -> V_4 . V_5 . V_6 . V_2 ;
const T_2 V_7 = V_8 -> V_9 * 0x800 ;
union {
struct V_10 V_11 ;
} * args = V_12 ;
T_2 V_13 , type ;
int V_14 ;
F_2 ( V_15 , L_1 , V_16 ) ;
if ( F_3 ( args -> V_11 , 0 , 0 , false ) ) {
F_2 ( V_15 , L_2 ,
args -> V_11 . V_17 , args -> V_11 . V_18 , args -> V_11 . type ) ;
if ( args -> V_11 . type > 0x0f )
return - V_19 ;
V_13 = ! ! args -> V_11 . V_18 ;
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
V_3 -> V_20 . type [ V_8 -> V_9 ] = type ;
return 0 ;
}
int
F_6 ( struct V_21 * V_3 , int V_22 ,
struct V_23 * V_24 , struct V_25 * * V_26 )
{
return F_7 ( & V_27 , V_3 ,
V_22 , V_24 , V_26 ) ;
}
static int
F_8 ( struct V_28 * V_8 , int V_29 )
{
return 0 ;
}
static int
F_9 ( struct V_28 * V_8 , int V_30 )
{
return 0 ;
}
static int
F_10 ( struct V_28 * V_8 ,
int V_30 , int V_31 , bool V_32 )
{
int V_14 = F_11 ( V_8 -> V_33 , V_30 , V_31 , V_32 ) ;
if ( V_14 )
return V_14 ;
return 1 ;
}
int
F_12 ( struct V_21 * V_3 , int V_22 , struct V_23 * V_24 ,
struct V_25 * * V_26 )
{
struct V_34 * V_35 = V_3 -> V_5 . V_6 . V_2 -> V_35 ;
struct V_36 * V_33 =
F_13 ( V_35 , F_14 ( V_24 -> V_37 ) ) ;
struct V_28 * V_8 ;
if ( ! ( V_8 = F_15 ( sizeof( * V_8 ) , V_38 ) ) )
return - V_39 ;
* V_26 = & V_8 -> V_4 ;
return F_16 ( & V_40 , V_3 ,
V_22 , V_24 , V_33 , V_8 ) ;
}
