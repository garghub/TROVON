int
F_1 ( struct V_1 * V_2 , T_1 type ,
struct V_3 * * V_4 )
{
switch ( type ) {
case V_5 :
* V_4 = & V_2 -> V_6 -> V_7 ;
return 0 ;
default:
break;
}
return - V_8 ;
}
static int
F_2 ( struct V_9 * V_10 )
{
switch ( V_10 -> V_11 . V_12 ) {
case V_13 : return 0 ;
case V_14 :
case V_15 : return 1 ;
case V_16 : return 2 ;
case V_17 :
case V_18 : return 3 ;
case V_19 :
case V_20 : return 4 ;
case V_21 :
case V_22 : return 5 ;
default:
F_3 ( 1 ) ;
return 0 ;
}
}
static int
F_4 ( struct V_9 * V_10 )
{
switch ( V_10 -> V_11 . V_12 ) {
case V_23 :
case V_24 : return - 1 ;
case V_13 : return 0x0020 ;
case V_17 :
case V_18 : return 0x0040 ;
case V_14 :
case V_15 : return 0x0060 ;
case V_21 :
case V_22 : return 0x0080 ;
case V_19 :
case V_20 : return 0x00a0 ;
case V_16 : return 0x00c0 ;
default:
F_3 ( 1 ) ;
return - 1 ;
}
}
static int
F_5 ( struct V_1 * V_25 ,
struct V_9 * V_10 , bool V_26 )
{
struct V_27 * V_2 = V_27 ( V_25 ) ;
struct V_28 * V_6 = V_2 -> V_6 ;
struct V_29 * V_11 = & V_6 -> V_25 . V_10 . V_11 ;
struct V_30 * V_31 = V_11 -> V_31 ;
T_1 V_32 , V_33 ;
int V_34 ;
bool V_35 ;
V_34 = F_4 ( V_10 ) ;
if ( V_34 < 0 )
return 0 ;
V_32 = F_2 ( V_10 ) ;
V_33 = F_6 ( V_31 , 0x002520 , 0x0000003f , 1 << V_32 ) ;
F_7 ( V_31 , 0x0032fc , V_2 -> V_25 . V_36 -> V_37 >> 12 ) ;
V_35 = F_8 (device, 2000 ,
if (nvkm_rd32(device, 0x0032fc) != 0xffffffff)
break;
) >= 0 ;
F_7 ( V_31 , 0x002520 , V_33 ) ;
if ( ! V_35 ) {
F_9 ( V_11 , L_1 ,
V_2 -> V_25 . V_38 , V_2 -> V_25 . V_39 . V_40 -> V_41 ) ;
if ( V_26 )
return - V_42 ;
}
F_10 ( V_2 -> V_43 ) ;
F_11 ( V_2 -> V_43 , V_34 + 0x00 , 0x00000000 ) ;
F_11 ( V_2 -> V_43 , V_34 + 0x04 , 0x00000000 ) ;
F_11 ( V_2 -> V_43 , V_34 + 0x08 , 0x00000000 ) ;
F_11 ( V_2 -> V_43 , V_34 + 0x0c , 0x00000000 ) ;
F_11 ( V_2 -> V_43 , V_34 + 0x10 , 0x00000000 ) ;
F_11 ( V_2 -> V_43 , V_34 + 0x14 , 0x00000000 ) ;
F_12 ( V_2 -> V_43 ) ;
return 0 ;
}
int
F_13 ( struct V_1 * V_25 ,
struct V_9 * V_10 )
{
struct V_27 * V_2 = V_27 ( V_25 ) ;
struct V_44 * V_32 = V_2 -> V_32 [ V_10 -> V_11 . V_12 ] ;
T_2 V_45 , V_46 ;
int V_34 ;
V_34 = F_4 ( V_10 ) ;
if ( V_34 < 0 )
return 0 ;
V_45 = V_32 -> V_37 + V_32 -> V_47 - 1 ;
V_46 = V_32 -> V_37 ;
F_10 ( V_2 -> V_43 ) ;
F_11 ( V_2 -> V_43 , V_34 + 0x00 , 0x00190000 ) ;
F_11 ( V_2 -> V_43 , V_34 + 0x04 , F_14 ( V_45 ) ) ;
F_11 ( V_2 -> V_43 , V_34 + 0x08 , F_14 ( V_46 ) ) ;
F_11 ( V_2 -> V_43 , V_34 + 0x0c , F_15 ( V_45 ) << 24 |
F_15 ( V_46 ) ) ;
F_11 ( V_2 -> V_43 , V_34 + 0x10 , 0x00000000 ) ;
F_11 ( V_2 -> V_43 , V_34 + 0x14 , 0x00000000 ) ;
F_12 ( V_2 -> V_43 ) ;
return 0 ;
}
static int
F_16 ( struct V_1 * V_25 ,
struct V_9 * V_10 ,
struct V_48 * V_39 )
{
struct V_27 * V_2 = V_27 ( V_25 ) ;
int V_32 = V_10 -> V_11 . V_12 ;
if ( F_4 ( V_10 ) < 0 )
return 0 ;
return F_17 ( V_39 , NULL , 0 , & V_2 -> V_32 [ V_32 ] ) ;
}
int
F_18 ( struct V_1 * V_25 ,
struct V_48 * V_39 )
{
struct V_27 * V_2 = V_27 ( V_25 ) ;
T_1 V_49 = V_39 -> V_49 ;
T_1 V_50 ;
switch ( V_39 -> V_10 -> V_11 . V_12 ) {
case V_23 :
case V_24 : V_50 = 0x00000000 ; break;
case V_13 : V_50 = 0x00100000 ; break;
case V_14 :
case V_15 : V_50 = 0x00200000 ; break;
case V_51 :
case V_16 : V_50 = 0x00300000 ; break;
case V_17 :
case V_18 : V_50 = 0x00400000 ; break;
case V_19 :
case V_20 :
case V_52 : V_50 = 0x00500000 ; break;
case V_21 :
case V_22 : V_50 = 0x00600000 ; break;
default:
F_3 ( 1 ) ;
return - V_8 ;
}
return F_19 ( V_2 -> V_53 , V_39 , 0 , 4 , V_49 , V_50 ) ;
}
static void
F_20 ( struct V_1 * V_25 )
{
struct V_27 * V_2 = V_27 ( V_25 ) ;
struct V_28 * V_6 = V_2 -> V_6 ;
struct V_30 * V_31 = V_6 -> V_25 . V_10 . V_11 . V_31 ;
T_2 V_37 = V_2 -> V_54 -> V_37 >> 8 ;
T_1 V_38 = V_2 -> V_25 . V_38 ;
F_7 ( V_31 , 0x002600 + ( V_38 * 4 ) , 0x80000000 | V_37 ) ;
F_21 ( V_6 ) ;
}
int
F_22 ( struct V_28 * V_6 , T_2 V_55 , T_2 V_56 ,
const struct V_57 * V_58 ,
struct V_27 * V_2 )
{
struct V_30 * V_31 = V_6 -> V_25 . V_10 . V_11 . V_31 ;
int V_59 ;
V_59 = F_23 ( & V_60 , & V_6 -> V_25 ,
0x10000 , 0x1000 , false , V_55 , V_56 ,
( 1ULL << V_21 ) |
( 1ULL << V_16 ) |
( 1ULL << V_19 ) |
( 1ULL << V_23 ) |
( 1ULL << V_13 ) |
( 1ULL << V_51 ) |
( 1ULL << V_14 ) |
( 1ULL << V_18 ) |
( 1ULL << V_15 ) |
( 1ULL << V_22 ) |
( 1ULL << V_20 ) |
( 1ULL << V_24 ) |
( 1ULL << V_52 ) |
( 1ULL << V_17 ) ,
0 , 0xc00000 , 0x2000 , V_58 , & V_2 -> V_25 ) ;
V_2 -> V_6 = V_6 ;
if ( V_59 )
return V_59 ;
V_59 = F_24 ( V_31 , 0x0200 , 0 , true , V_2 -> V_25 . V_36 ,
& V_2 -> V_43 ) ;
if ( V_59 )
return V_59 ;
V_59 = F_24 ( V_31 , 0x4000 , 0 , false , V_2 -> V_25 . V_36 ,
& V_2 -> V_61 ) ;
if ( V_59 )
return V_59 ;
V_59 = F_24 ( V_31 , 0x1000 , 0x400 , true , V_2 -> V_25 . V_36 ,
& V_2 -> V_62 ) ;
if ( V_59 )
return V_59 ;
V_59 = F_24 ( V_31 , 0x100 , 0x100 , true , V_2 -> V_25 . V_36 ,
& V_2 -> V_54 ) ;
if ( V_59 )
return V_59 ;
V_59 = F_25 ( V_31 , 0x8000 , 16 , V_2 -> V_25 . V_36 , & V_2 -> V_53 ) ;
if ( V_59 )
return V_59 ;
return F_26 ( V_2 -> V_25 . V_55 , & V_2 -> V_55 , V_2 -> V_61 ) ;
}
