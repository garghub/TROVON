static int
F_1 ( struct V_1 * V_2 )
{
switch ( V_2 -> V_3 . V_4 ) {
case V_5 :
case V_6 : return - 1 ;
case V_7 : return 0x0000 ;
case V_8 : return 0x0060 ;
default:
F_2 ( 1 ) ;
return - 1 ;
}
}
static int
F_3 ( struct V_9 * V_10 ,
struct V_1 * V_2 , bool V_11 )
{
struct V_12 * V_13 = V_12 ( V_10 ) ;
struct V_14 * V_15 = V_13 -> V_15 ;
struct V_16 * V_3 = & V_15 -> V_10 . V_2 . V_3 ;
struct V_17 * V_18 = V_3 -> V_18 ;
int V_19 , V_20 = 0 ;
T_1 V_21 ;
V_19 = F_1 ( V_2 ) ;
if ( V_19 < 0 )
return 0 ;
V_21 = F_4 ( V_18 , 0x00b860 , 0x00000001 , 0x00000001 ) ;
F_5 ( V_18 , 0x0032fc , V_13 -> V_10 . V_22 -> V_23 >> 12 ) ;
if ( F_6 (device, 2000 ,
if (nvkm_rd32(device, 0x0032fc) != 0xffffffff)
break;
) < 0 ) {
F_7 ( V_3 , L_1 ,
V_13 -> V_10 . V_24 , V_13 -> V_10 . V_25 . V_26 -> V_27 ) ;
if ( V_11 )
V_20 = - V_28 ;
}
F_5 ( V_18 , 0x00b860 , V_21 ) ;
if ( V_20 == 0 ) {
F_8 ( V_13 -> V_29 ) ;
F_9 ( V_13 -> V_29 , V_19 + 0x00 , 0x00000000 ) ;
F_9 ( V_13 -> V_29 , V_19 + 0x04 , 0x00000000 ) ;
F_9 ( V_13 -> V_29 , V_19 + 0x08 , 0x00000000 ) ;
F_9 ( V_13 -> V_29 , V_19 + 0x0c , 0x00000000 ) ;
F_9 ( V_13 -> V_29 , V_19 + 0x10 , 0x00000000 ) ;
F_9 ( V_13 -> V_29 , V_19 + 0x14 , 0x00000000 ) ;
F_10 ( V_13 -> V_29 ) ;
}
return V_20 ;
}
static int
F_11 ( struct V_9 * V_10 ,
struct V_1 * V_2 )
{
struct V_12 * V_13 = V_12 ( V_10 ) ;
struct V_30 * V_31 = V_13 -> V_31 [ V_2 -> V_3 . V_4 ] ;
T_2 V_32 , V_33 ;
int V_19 ;
V_19 = F_1 ( V_2 ) ;
if ( V_19 < 0 )
return 0 ;
V_32 = V_31 -> V_23 + V_31 -> V_34 - 1 ;
V_33 = V_31 -> V_23 ;
F_8 ( V_13 -> V_29 ) ;
F_9 ( V_13 -> V_29 , V_19 + 0x00 , 0x00190000 ) ;
F_9 ( V_13 -> V_29 , V_19 + 0x04 , F_12 ( V_32 ) ) ;
F_9 ( V_13 -> V_29 , V_19 + 0x08 , F_12 ( V_33 ) ) ;
F_9 ( V_13 -> V_29 , V_19 + 0x0c , F_13 ( V_32 ) << 24 |
F_13 ( V_33 ) ) ;
F_9 ( V_13 -> V_29 , V_19 + 0x10 , 0x00000000 ) ;
F_9 ( V_13 -> V_29 , V_19 + 0x14 , 0x00000000 ) ;
F_10 ( V_13 -> V_29 ) ;
return 0 ;
}
void
F_14 ( struct V_9 * V_10 ,
struct V_1 * V_2 )
{
struct V_12 * V_13 = V_12 ( V_10 ) ;
F_15 ( & V_13 -> V_31 [ V_2 -> V_3 . V_4 ] ) ;
}
static int
F_16 ( struct V_9 * V_10 ,
struct V_1 * V_2 ,
struct V_35 * V_25 )
{
struct V_12 * V_13 = V_12 ( V_10 ) ;
int V_31 = V_2 -> V_3 . V_4 ;
if ( F_1 ( V_2 ) < 0 )
return 0 ;
return F_17 ( V_25 , NULL , 0 , & V_13 -> V_31 [ V_31 ] ) ;
}
void
F_18 ( struct V_9 * V_10 , int V_36 )
{
struct V_12 * V_13 = V_12 ( V_10 ) ;
F_19 ( V_13 -> V_37 , V_36 ) ;
}
static int
F_20 ( struct V_9 * V_10 ,
struct V_35 * V_25 )
{
struct V_12 * V_13 = V_12 ( V_10 ) ;
T_1 V_38 = V_25 -> V_38 ;
T_1 V_39 ;
switch ( V_25 -> V_2 -> V_3 . V_4 ) {
case V_5 :
case V_6 : V_39 = 0x00000000 ; break;
case V_7 : V_39 = 0x00100000 ; break;
case V_8 : V_39 = 0x00200000 ; break;
default:
F_2 ( 1 ) ;
return - V_40 ;
}
return F_21 ( V_13 -> V_37 , V_25 , 0 , 4 , V_38 , V_39 ) ;
}
void
F_22 ( struct V_9 * V_10 )
{
struct V_12 * V_13 = V_12 ( V_10 ) ;
struct V_14 * V_15 = V_13 -> V_15 ;
struct V_17 * V_18 = V_15 -> V_10 . V_2 . V_3 . V_18 ;
T_1 V_24 = V_13 -> V_10 . V_24 ;
F_4 ( V_18 , 0x002600 + ( V_24 * 4 ) , 0x80000000 , 0x00000000 ) ;
F_23 ( V_15 ) ;
F_5 ( V_18 , 0x002600 + ( V_24 * 4 ) , 0x00000000 ) ;
}
static void
F_24 ( struct V_9 * V_10 )
{
struct V_12 * V_13 = V_12 ( V_10 ) ;
struct V_14 * V_15 = V_13 -> V_15 ;
struct V_17 * V_18 = V_15 -> V_10 . V_2 . V_3 . V_18 ;
T_2 V_23 = V_13 -> V_41 -> V_23 >> 12 ;
T_1 V_24 = V_13 -> V_10 . V_24 ;
F_5 ( V_18 , 0x002600 + ( V_24 * 4 ) , 0x80000000 | V_23 ) ;
F_23 ( V_15 ) ;
}
void *
F_25 ( struct V_9 * V_10 )
{
struct V_12 * V_13 = V_12 ( V_10 ) ;
F_26 ( NULL , & V_13 -> V_42 , V_13 -> V_43 ) ;
F_27 ( & V_13 -> V_37 ) ;
F_15 ( & V_13 -> V_43 ) ;
F_15 ( & V_13 -> V_29 ) ;
F_15 ( & V_13 -> V_44 ) ;
F_15 ( & V_13 -> V_41 ) ;
return V_13 ;
}
int
F_28 ( struct V_14 * V_15 , T_2 V_42 , T_2 V_45 ,
const struct V_46 * V_47 ,
struct V_12 * V_13 )
{
struct V_17 * V_18 = V_15 -> V_10 . V_2 . V_3 . V_18 ;
int V_20 ;
V_20 = F_29 ( & V_48 , & V_15 -> V_10 ,
0x10000 , 0x1000 , false , V_42 , V_45 ,
( 1ULL << V_5 ) |
( 1ULL << V_6 ) |
( 1ULL << V_7 ) |
( 1ULL << V_8 ) ,
0 , 0xc00000 , 0x2000 , V_47 , & V_13 -> V_10 ) ;
V_13 -> V_15 = V_15 ;
if ( V_20 )
return V_20 ;
V_20 = F_30 ( V_18 , 0x0200 , 0x1000 , true , V_13 -> V_10 . V_22 ,
& V_13 -> V_41 ) ;
if ( V_20 )
return V_20 ;
V_20 = F_30 ( V_18 , 0x1200 , 0 , true , V_13 -> V_10 . V_22 ,
& V_13 -> V_29 ) ;
if ( V_20 )
return V_20 ;
V_20 = F_30 ( V_18 , 0x4000 , 0 , false , V_13 -> V_10 . V_22 ,
& V_13 -> V_43 ) ;
if ( V_20 )
return V_20 ;
V_20 = F_31 ( V_18 , 0x8000 , 16 , V_13 -> V_10 . V_22 , & V_13 -> V_37 ) ;
if ( V_20 )
return V_20 ;
return F_26 ( V_13 -> V_10 . V_42 , & V_13 -> V_42 , V_13 -> V_43 ) ;
}
