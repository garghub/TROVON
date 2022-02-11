int
F_1 ( const struct V_1 * V_2 ,
const struct V_3 * V_4 ,
struct V_5 * V_6 , int V_7 ,
const struct V_8 * V_9 , void * V_10 , T_1 V_11 ,
struct V_12 * * V_13 )
{
union {
struct V_14 V_15 ;
} * args = V_10 ;
struct V_12 * V_16 = V_9 -> V_16 ;
T_2 V_17 ;
int V_18 ;
F_2 ( V_16 , L_1 , V_11 ) ;
if ( F_3 ( args -> V_15 , 0 , 0 , false ) ) {
F_2 ( V_16 , L_2
L_3 ,
args -> V_15 . V_19 , args -> V_15 . V_20 ) ;
V_17 = args -> V_15 . V_20 ;
} else
return V_18 ;
return F_4 ( V_2 , V_4 , V_6 , V_7 , 0 ,
V_17 , V_9 , V_13 ) ;
}
static void
F_5 ( struct V_21 * V_22 )
{
struct V_23 * V_24 = V_22 -> V_25 . V_6 -> V_24 ;
struct V_26 * V_27 = & V_24 -> V_25 . V_28 . V_27 ;
struct V_29 * V_30 = V_27 -> V_30 ;
F_6 ( V_30 , 0x610200 , 0x00000010 , 0x00000000 ) ;
F_6 ( V_30 , 0x610200 , 0x00000003 , 0x00000000 ) ;
if ( F_7 (device, 2000 ,
if (!(nvkm_rd32(device, 0x610200) & 0x001e0000))
break;
) < 0 ) {
F_8 ( V_27 , L_4 ,
F_9 ( V_30 , 0x610200 ) ) ;
}
F_6 ( V_30 , 0x610028 , 0x00010001 , 0x00000000 ) ;
}
static int
F_10 ( struct V_21 * V_22 )
{
struct V_23 * V_24 = V_22 -> V_25 . V_6 -> V_24 ;
struct V_26 * V_27 = & V_24 -> V_25 . V_28 . V_27 ;
struct V_29 * V_30 = V_27 -> V_30 ;
F_6 ( V_30 , 0x610028 , 0x00010000 , 0x00010000 ) ;
if ( ( F_9 ( V_30 , 0x610200 ) & 0x009f0000 ) == 0x00020000 )
F_6 ( V_30 , 0x610200 , 0x00800000 , 0x00800000 ) ;
if ( ( F_9 ( V_30 , 0x610200 ) & 0x003f0000 ) == 0x00030000 )
F_6 ( V_30 , 0x610200 , 0x00600000 , 0x00600000 ) ;
F_11 ( V_30 , 0x610204 , V_22 -> V_17 ) ;
F_11 ( V_30 , 0x610208 , 0x00010000 ) ;
F_11 ( V_30 , 0x61020c , 0x00000000 ) ;
F_6 ( V_30 , 0x610200 , 0x00000010 , 0x00000010 ) ;
F_11 ( V_30 , 0x640000 , 0x00000000 ) ;
F_11 ( V_30 , 0x610200 , 0x01000013 ) ;
if ( F_7 (device, 2000 ,
if (!(nvkm_rd32(device, 0x610200) & 0x80000000))
break;
) < 0 ) {
F_8 ( V_27 , L_5 ,
F_9 ( V_30 , 0x610200 ) ) ;
return - V_31 ;
}
return 0 ;
}
