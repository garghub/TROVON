static void
F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 , T_1 V_7 , T_1 V_8 , T_2 * V_9 )
{
V_7 = V_7 * 4 ;
F_2 ( V_4 ) ;
while ( V_8 ) {
T_1 V_10 = V_11 / V_12 ;
T_3 V_13 = ( T_3 ) * V_9 ++ ;
while ( V_8 && V_10 -- ) {
F_3 ( V_4 , V_7 , ( V_13 >> 7 ) | 1 ) ;
V_13 += V_12 ;
V_7 += 4 ;
V_8 -= 1 ;
}
}
F_4 ( V_4 ) ;
}
static void
F_5 ( struct V_1 * V_2 , struct V_3 * V_4 , T_1 V_7 , T_1 V_8 )
{
V_7 = V_7 * 4 ;
F_2 ( V_4 ) ;
while ( V_8 -- ) {
F_3 ( V_4 , V_7 , 0x00000000 ) ;
V_7 += 4 ;
}
F_4 ( V_4 ) ;
}
static void
F_6 ( struct V_14 * V_15 )
{
struct V_16 * V_17 = V_16 ( V_15 -> V_17 ) ;
struct V_18 * V_19 = V_17 -> V_20 . V_21 . V_19 ;
F_7 ( & V_17 -> V_20 . V_21 . V_22 ) ;
F_8 ( V_19 , 0x100810 , 0x00000022 ) ;
F_9 (device, 2000 ,
if (nvkm_rd32(device, 0x100810) & 0x00000020)
break;
) ;
F_8 ( V_19 , 0x100810 , 0x00000000 ) ;
F_10 ( & V_17 -> V_20 . V_21 . V_22 ) ;
}
static int
F_11 ( struct V_23 * V_20 )
{
struct V_16 * V_17 = V_16 ( V_20 ) ;
struct V_18 * V_19 = V_17 -> V_20 . V_21 . V_19 ;
int V_24 ;
V_24 = F_12 ( & V_17 -> V_20 , 0 , V_25 , 0 , 4096 , NULL ,
& V_17 -> V_15 ) ;
if ( V_24 )
return V_24 ;
V_24 = F_13 ( V_19 , V_26 ,
( V_25 / V_12 ) * 4 , 16 , true ,
& V_17 -> V_15 -> V_4 [ 0 ] . V_6 [ 0 ] ) ;
V_17 -> V_15 -> V_4 [ 0 ] . V_27 [ 0 ] = 1 ;
return V_24 ;
}
static void
F_14 ( struct V_23 * V_20 )
{
struct V_16 * V_17 = V_16 ( V_20 ) ;
struct V_18 * V_19 = V_17 -> V_20 . V_21 . V_19 ;
struct V_3 * V_28 = V_17 -> V_15 -> V_4 [ 0 ] . V_6 [ 0 ] ;
F_8 ( V_19 , 0x100800 , 0x00000002 | F_15 ( V_28 ) ) ;
F_16 ( V_19 , 0x10008c , 0x00000100 , 0x00000100 ) ;
F_8 ( V_19 , 0x100820 , 0x00000000 ) ;
}
int
F_17 ( struct V_18 * V_19 , int V_29 , struct V_23 * * V_30 )
{
if ( V_19 -> type == V_31 ||
! F_18 ( V_19 -> V_32 , L_1 , true ) )
return F_19 ( V_19 , V_29 , V_30 ) ;
return F_20 ( & V_33 , V_19 , V_29 , V_30 ) ;
}
