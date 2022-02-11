int
F_1 ( struct V_1 * V_2 , T_1 type ,
struct V_3 * * V_4 )
{
switch ( type ) {
case V_5 :
* V_4 = & V_2 -> V_6 -> V_7 ;
return 0 ;
case V_8 :
* V_4 = & V_2 -> V_6 -> V_9 ;
return 0 ;
default:
break;
}
return - V_10 ;
}
static T_1
F_2 ( struct V_11 * V_12 )
{
switch ( V_12 -> V_13 . V_14 ) {
case V_15 : return 0 ;
case V_16 : return 0x0210 ;
case V_17 : return 0x0230 ;
case V_18 : return 0x0240 ;
case V_19 : return 0x0250 ;
case V_20 : return 0x0260 ;
case V_21 : return 0x0270 ;
default:
F_3 ( 1 ) ;
return 0 ;
}
}
static int
F_4 ( struct V_1 * V_22 ,
struct V_11 * V_12 , bool V_23 )
{
const T_1 V_24 = F_2 ( V_12 ) ;
struct V_25 * V_2 = V_25 ( V_22 ) ;
struct V_26 * V_13 = & V_2 -> V_6 -> V_22 . V_12 . V_13 ;
struct V_27 * V_28 = V_13 -> V_28 ;
struct V_29 * V_30 = V_2 -> V_22 . V_30 ;
int V_31 = 0 ;
F_5 ( & V_13 -> V_32 ) ;
F_6 ( V_28 , 0x002634 , V_2 -> V_22 . V_33 ) ;
if ( F_7 (device, 2000 ,
if (nvkm_rd32(device, 0x002634) == chan->base.chid)
break;
) < 0 ) {
F_8 ( V_13 , L_1 ,
V_2 -> V_22 . V_33 , V_2 -> V_22 . V_34 . V_35 -> V_36 ) ;
V_31 = - V_37 ;
}
F_9 ( & V_13 -> V_32 ) ;
if ( V_31 && V_23 )
return V_31 ;
if ( V_24 ) {
F_10 ( V_30 ) ;
F_11 ( V_30 , V_24 + 0x00 , 0x00000000 ) ;
F_11 ( V_30 , V_24 + 0x04 , 0x00000000 ) ;
F_12 ( V_30 ) ;
}
return V_31 ;
}
static int
F_13 ( struct V_1 * V_22 ,
struct V_11 * V_12 )
{
const T_1 V_24 = F_2 ( V_12 ) ;
struct V_25 * V_2 = V_25 ( V_22 ) ;
struct V_29 * V_30 = V_2 -> V_22 . V_30 ;
if ( V_24 ) {
T_2 V_38 = V_2 -> V_39 [ V_12 -> V_13 . V_14 ] . V_40 . V_24 ;
F_10 ( V_30 ) ;
F_11 ( V_30 , V_24 + 0x00 , F_14 ( V_38 ) | 4 ) ;
F_11 ( V_30 , V_24 + 0x04 , F_15 ( V_38 ) ) ;
F_12 ( V_30 ) ;
}
return 0 ;
}
static void
F_16 ( struct V_1 * V_22 ,
struct V_11 * V_12 )
{
struct V_25 * V_2 = V_25 ( V_22 ) ;
F_17 ( & V_2 -> V_39 [ V_12 -> V_13 . V_14 ] . V_40 ) ;
F_18 ( & V_2 -> V_39 [ V_12 -> V_13 . V_14 ] . V_30 ) ;
}
static int
F_19 ( struct V_1 * V_22 ,
struct V_11 * V_12 ,
struct V_41 * V_34 )
{
struct V_25 * V_2 = V_25 ( V_22 ) ;
int V_39 = V_12 -> V_13 . V_14 ;
int V_31 ;
if ( ! F_2 ( V_12 ) )
return 0 ;
V_31 = F_20 ( V_34 , NULL , 0 , & V_2 -> V_39 [ V_39 ] . V_30 ) ;
if ( V_31 )
return V_31 ;
return F_21 ( V_2 -> V_39 [ V_39 ] . V_30 , V_2 -> V_42 ,
V_43 , & V_2 -> V_39 [ V_39 ] . V_40 ) ;
}
static void
F_22 ( struct V_1 * V_22 )
{
struct V_25 * V_2 = V_25 ( V_22 ) ;
struct V_44 * V_6 = V_2 -> V_6 ;
struct V_27 * V_28 = V_6 -> V_22 . V_12 . V_13 . V_28 ;
T_1 V_45 = V_2 -> V_22 . V_33 * 8 ;
if ( ! F_23 ( & V_2 -> V_46 ) && ! V_2 -> V_47 ) {
F_24 ( V_6 , V_2 ) ;
F_25 ( V_28 , 0x003004 + V_45 , 0x00000001 , 0x00000000 ) ;
F_26 ( V_6 ) ;
}
F_27 ( V_6 ) ;
F_6 ( V_28 , 0x003000 + V_45 , 0x00000000 ) ;
}
static void
F_28 ( struct V_1 * V_22 )
{
struct V_25 * V_2 = V_25 ( V_22 ) ;
struct V_44 * V_6 = V_2 -> V_6 ;
struct V_27 * V_28 = V_6 -> V_22 . V_12 . V_13 . V_28 ;
T_1 V_38 = V_2 -> V_22 . V_30 -> V_38 >> 12 ;
T_1 V_45 = V_2 -> V_22 . V_33 * 8 ;
F_6 ( V_28 , 0x003000 + V_45 , 0xc0000000 | V_38 ) ;
if ( F_23 ( & V_2 -> V_46 ) && ! V_2 -> V_47 ) {
F_29 ( V_6 , V_2 ) ;
F_6 ( V_28 , 0x003004 + V_45 , 0x001f0001 ) ;
F_26 ( V_6 ) ;
}
}
static void *
F_30 ( struct V_1 * V_22 )
{
struct V_25 * V_2 = V_25 ( V_22 ) ;
F_31 ( NULL , & V_2 -> V_42 , V_2 -> V_48 ) ;
F_18 ( & V_2 -> V_48 ) ;
return V_2 ;
}
static int
F_32 ( struct V_49 * V_22 , const struct V_50 * V_51 ,
void * V_52 , T_1 V_53 , struct V_41 * * V_54 )
{
union {
struct V_55 V_56 ;
} * args = V_52 ;
struct V_44 * V_6 = V_44 ( V_22 ) ;
struct V_27 * V_28 = V_6 -> V_22 . V_12 . V_13 . V_28 ;
struct V_41 * V_57 = V_51 -> V_57 ;
struct V_25 * V_2 ;
T_2 V_58 , V_59 , V_60 ;
int V_31 = - V_61 , V_62 ;
F_33 ( V_57 , L_2 , V_53 ) ;
if ( ! ( V_31 = F_34 ( V_31 , & V_52 , & V_53 , args -> V_56 , 0 , 0 , false ) ) ) {
F_33 ( V_57 , L_3
L_4 ,
args -> V_56 . V_63 , args -> V_56 . V_42 , args -> V_56 . V_59 ,
args -> V_56 . V_60 ) ;
} else
return V_31 ;
if ( ! ( V_2 = F_35 ( sizeof( * V_2 ) , V_64 ) ) )
return - V_65 ;
* V_54 = & V_2 -> V_22 . V_34 ;
V_2 -> V_6 = V_6 ;
F_36 ( & V_2 -> V_46 ) ;
V_31 = F_37 ( & V_66 , & V_6 -> V_22 ,
0x1000 , 0x1000 , true , args -> V_56 . V_42 , 0 ,
( 1ULL << V_17 ) |
( 1ULL << V_18 ) |
( 1ULL << V_16 ) |
( 1ULL << V_19 ) |
( 1ULL << V_20 ) |
( 1ULL << V_21 ) |
( 1ULL << V_15 ) ,
1 , V_6 -> V_67 . V_68 . V_24 , 0x1000 ,
V_51 , & V_2 -> V_22 ) ;
if ( V_31 )
return V_31 ;
args -> V_56 . V_33 = V_2 -> V_22 . V_33 ;
V_31 = F_38 ( V_28 , 0x10000 , 0x1000 , false , NULL , & V_2 -> V_48 ) ;
if ( V_31 )
return V_31 ;
F_10 ( V_2 -> V_22 . V_30 ) ;
F_11 ( V_2 -> V_22 . V_30 , 0x0200 , F_14 ( V_2 -> V_48 -> V_38 ) ) ;
F_11 ( V_2 -> V_22 . V_30 , 0x0204 , F_15 ( V_2 -> V_48 -> V_38 ) ) ;
F_11 ( V_2 -> V_22 . V_30 , 0x0208 , 0xffffffff ) ;
F_11 ( V_2 -> V_22 . V_30 , 0x020c , 0x000000ff ) ;
F_12 ( V_2 -> V_22 . V_30 ) ;
V_31 = F_31 ( V_2 -> V_22 . V_42 , & V_2 -> V_42 , V_2 -> V_48 ) ;
if ( V_31 )
return V_31 ;
V_58 = V_2 -> V_22 . V_33 * 0x1000 ;
V_59 = args -> V_56 . V_59 ;
V_60 = F_39 ( args -> V_56 . V_60 / 8 ) ;
F_10 ( V_6 -> V_67 . V_69 ) ;
for ( V_62 = 0 ; V_62 < 0x1000 ; V_62 += 4 )
F_11 ( V_6 -> V_67 . V_69 , V_58 + V_62 , 0x00000000 ) ;
F_12 ( V_6 -> V_67 . V_69 ) ;
V_58 = F_40 ( V_6 -> V_67 . V_69 ) + V_58 ;
F_10 ( V_2 -> V_22 . V_30 ) ;
F_11 ( V_2 -> V_22 . V_30 , 0x08 , F_14 ( V_58 ) ) ;
F_11 ( V_2 -> V_22 . V_30 , 0x0c , F_15 ( V_58 ) ) ;
F_11 ( V_2 -> V_22 . V_30 , 0x10 , 0x0000face ) ;
F_11 ( V_2 -> V_22 . V_30 , 0x30 , 0xfffff902 ) ;
F_11 ( V_2 -> V_22 . V_30 , 0x48 , F_14 ( V_59 ) ) ;
F_11 ( V_2 -> V_22 . V_30 , 0x4c , F_15 ( V_59 ) |
( V_60 << 16 ) ) ;
F_11 ( V_2 -> V_22 . V_30 , 0x54 , 0x00000002 ) ;
F_11 ( V_2 -> V_22 . V_30 , 0x84 , 0x20400000 ) ;
F_11 ( V_2 -> V_22 . V_30 , 0x94 , 0x30000001 ) ;
F_11 ( V_2 -> V_22 . V_30 , 0x9c , 0x00000100 ) ;
F_11 ( V_2 -> V_22 . V_30 , 0xa4 , 0x1f1f1f1f ) ;
F_11 ( V_2 -> V_22 . V_30 , 0xa8 , 0x1f1f1f1f ) ;
F_11 ( V_2 -> V_22 . V_30 , 0xac , 0x0000001f ) ;
F_11 ( V_2 -> V_22 . V_30 , 0xb8 , 0xf8000000 ) ;
F_11 ( V_2 -> V_22 . V_30 , 0xf8 , 0x10003080 ) ;
F_11 ( V_2 -> V_22 . V_30 , 0xfc , 0x10000010 ) ;
F_12 ( V_2 -> V_22 . V_30 ) ;
return 0 ;
}
