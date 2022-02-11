static int
F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
struct V_4 * V_5 = V_4 ( V_2 ) ;
struct V_6 * V_7 = & V_5 -> V_2 . V_8 -> V_7 ;
struct V_9 * V_10 = V_7 -> V_11 -> V_10 ;
struct V_12 V_13 ;
int V_14 , V_15 , V_16 , V_17 ;
int V_18 , V_19 ;
V_19 = F_2 ( V_10 , 0x04 , & V_13 ) ;
if ( V_19 ) {
F_3 ( V_7 , L_1 ) ;
return V_19 ;
}
V_19 = F_4 ( V_7 , & V_13 , V_3 , & V_14 , & V_15 , & V_16 , & V_17 , & V_18 ) ;
if ( V_19 < 0 )
return V_19 ;
V_5 -> V_20 = 0x80000000 | ( V_18 << 16 ) ;
V_5 -> V_20 |= F_5 ( V_13 . V_21 + V_18 , ( int ) V_13 . V_22 ) << 20 ;
if ( V_16 == V_17 ) {
V_5 -> V_20 |= 0x00000100 ;
V_5 -> V_23 = ( V_14 << 8 ) | V_15 ;
} else {
V_5 -> V_20 |= 0x40000000 ;
V_5 -> V_23 = ( V_16 << 24 ) | ( V_17 << 16 ) | ( V_14 << 8 ) | V_15 ;
}
return 0 ;
}
static int
F_6 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_4 ( V_2 ) ;
struct V_6 * V_7 = & V_5 -> V_2 . V_8 -> V_7 ;
struct V_24 * V_11 = V_7 -> V_11 ;
struct V_9 * V_10 = V_11 -> V_10 ;
struct V_25 V_26 ;
T_1 V_27 = 0 ;
T_2 V_28 [ 2 ] ;
int V_29 ;
for ( V_29 = 0 ; V_29 < 2 ; V_29 ++ ) {
T_1 V_30 = F_7 ( V_11 , 0x600808 + ( V_29 * 0x2000 ) ) ;
T_1 V_31 = 0 ;
do {
if ( V_30 != F_7 ( V_11 , 0x600808 + ( V_29 * 0x2000 ) ) ) {
F_8 ( V_11 , 0x0c03c4 + ( V_29 * 0x2000 ) , 0x01 ) ;
V_28 [ V_29 ] = F_9 ( V_11 , 0x0c03c5 + ( V_29 * 0x2000 ) ) ;
if ( ! ( V_28 [ V_29 ] & 0x20 ) )
V_27 |= ( 1 << V_29 ) ;
break;
}
F_10 ( 1 ) ;
} while ( V_31 ++ < 32 );
}
for ( V_29 = 0 ; V_29 < 2 ; V_29 ++ ) {
if ( ! ( V_27 & ( 1 << V_29 ) ) )
continue;
F_11 (device, 2000 ,
u32 tmp = nvkm_rd32(device, 0x600808 + (i * 0x2000));
if (!(tmp & 0x00010000))
break;
) ;
F_11 (device, 2000 ,
u32 tmp = nvkm_rd32(device, 0x600808 + (i * 0x2000));
if ( (tmp & 0x00010000))
break;
) ;
F_8 ( V_11 , 0x0c03c4 + ( V_29 * 0x2000 ) , 0x01 ) ;
F_8 ( V_11 , 0x0c03c5 + ( V_29 * 0x2000 ) , V_28 [ V_29 ] | 0x20 ) ;
}
F_12 ( V_11 , 0x1002d4 , 0x00000001 ) ;
F_12 ( V_11 , 0x1002d0 , 0x00000001 ) ;
F_12 ( V_11 , 0x1002d0 , 0x00000001 ) ;
F_13 ( V_11 , 0x100210 , 0x80000000 , 0x00000000 ) ;
F_12 ( V_11 , 0x1002dc , 0x00000001 ) ;
F_13 ( V_11 , 0x00c040 , 0x0000c000 , 0x00000000 ) ;
switch ( V_11 -> V_32 ) {
case 0x40 :
case 0x45 :
case 0x41 :
case 0x42 :
case 0x47 :
F_13 ( V_11 , 0x004044 , 0xc0771100 , V_5 -> V_20 ) ;
F_13 ( V_11 , 0x00402c , 0xc0771100 , V_5 -> V_20 ) ;
F_12 ( V_11 , 0x004048 , V_5 -> V_23 ) ;
F_12 ( V_11 , 0x004030 , V_5 -> V_23 ) ;
case 0x43 :
case 0x49 :
case 0x4b :
F_13 ( V_11 , 0x004038 , 0xc0771100 , V_5 -> V_20 ) ;
F_12 ( V_11 , 0x00403c , V_5 -> V_23 ) ;
default:
F_13 ( V_11 , 0x004020 , 0xc0771100 , V_5 -> V_20 ) ;
F_12 ( V_11 , 0x004024 , V_5 -> V_23 ) ;
break;
}
F_10 ( 100 ) ;
F_13 ( V_11 , 0x00c040 , 0x0000c000 , 0x0000c000 ) ;
F_12 ( V_11 , 0x1002dc , 0x00000000 ) ;
F_13 ( V_11 , 0x100210 , 0x80000000 , 0x80000000 ) ;
F_10 ( 100 ) ;
if ( ! V_25 ( V_10 , 'M' , & V_26 ) ) {
struct V_33 V_34 = {
. V_7 = V_7 ,
. V_10 = V_10 ,
. V_35 = F_14 ( V_10 , V_26 . V_35 + 0x00 ) ,
. V_36 = 1 ,
} ;
F_15 ( & V_34 ) ;
}
for ( V_29 = 0 ; V_29 < 2 ; V_29 ++ ) {
if ( ! ( V_27 & ( 1 << V_29 ) ) )
continue;
F_11 (device, 2000 ,
u32 tmp = nvkm_rd32(device, 0x600808 + (i * 0x2000));
if ( (tmp & 0x00010000))
break;
) ;
F_8 ( V_11 , 0x0c03c4 + ( V_29 * 0x2000 ) , 0x01 ) ;
F_8 ( V_11 , 0x0c03c5 + ( V_29 * 0x2000 ) , V_28 [ V_29 ] ) ;
}
return 0 ;
}
static void
F_16 ( struct V_1 * V_2 )
{
}
int
F_17 ( struct V_37 * V_8 , enum V_38 type , T_3 V_39 ,
T_1 V_40 , struct V_1 * * V_41 )
{
struct V_4 * V_5 ;
if ( ! ( V_5 = F_18 ( sizeof( * V_5 ) , V_42 ) ) )
return - V_43 ;
* V_41 = & V_5 -> V_2 ;
return F_19 ( & V_44 , V_8 , type , V_39 , V_40 , & V_5 -> V_2 ) ;
}
int
F_20 ( struct V_37 * V_8 , struct V_1 * * V_41 )
{
struct V_24 * V_11 = V_8 -> V_7 . V_11 ;
T_1 V_45 = F_7 ( V_11 , 0x001218 ) ;
T_1 V_39 = F_7 ( V_11 , 0x10020c ) & 0xff000000 ;
T_1 V_40 = F_7 ( V_11 , 0x100320 ) ;
enum V_38 type = V_46 ;
int V_19 ;
switch ( V_45 & 0x00000300 ) {
case 0x00000000 : type = V_47 ; break;
case 0x00000100 : type = V_48 ; break;
case 0x00000200 : type = V_49 ; break;
case 0x00000300 : type = V_50 ; break;
}
V_19 = F_17 ( V_8 , type , V_39 , V_40 , V_41 ) ;
if ( V_19 )
return V_19 ;
( * V_41 ) -> V_51 = ( F_7 ( V_11 , 0x100200 ) & 0x00000003 ) + 1 ;
return 0 ;
}
