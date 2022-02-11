static T_1
F_1 ( struct V_1 * V_2 )
{
switch ( V_2 -> V_3 . V_4 ) {
case V_5 : return 0 ;
case V_6 : return 0x0210 ;
case V_7 : return 0x0230 ;
case V_8 : return 0x0240 ;
case V_9 : return 0x0250 ;
case V_10 : return 0x0260 ;
case V_11 : return 0x0270 ;
default:
F_2 ( 1 ) ;
return 0 ;
}
}
static int
F_3 ( struct V_12 * V_13 ,
struct V_1 * V_2 , bool V_14 )
{
const T_1 V_15 = F_1 ( V_2 ) ;
struct V_16 * V_17 = V_16 ( V_13 ) ;
struct V_18 * V_3 = & V_17 -> V_19 -> V_13 . V_2 . V_3 ;
struct V_20 * V_21 = V_3 -> V_21 ;
struct V_22 * V_23 = V_17 -> V_13 . V_23 ;
int V_24 = 0 ;
F_4 ( V_21 , 0x002634 , V_17 -> V_13 . V_25 ) ;
if ( F_5 (device, 2000 ,
if (nvkm_rd32(device, 0x002634) == chan->base.chid)
break;
) < 0 ) {
F_6 ( V_3 , L_1 ,
V_17 -> V_13 . V_25 , V_17 -> V_13 . V_26 . V_27 -> V_28 ) ;
V_24 = - V_29 ;
if ( V_14 )
return V_24 ;
}
if ( V_15 ) {
F_7 ( V_23 ) ;
F_8 ( V_23 , V_15 + 0x00 , 0x00000000 ) ;
F_8 ( V_23 , V_15 + 0x04 , 0x00000000 ) ;
F_9 ( V_23 ) ;
}
return V_24 ;
}
static int
F_10 ( struct V_12 * V_13 ,
struct V_1 * V_2 )
{
const T_1 V_15 = F_1 ( V_2 ) ;
struct V_16 * V_17 = V_16 ( V_13 ) ;
struct V_22 * V_23 = V_17 -> V_13 . V_23 ;
if ( V_15 ) {
T_2 V_30 = V_17 -> V_31 [ V_2 -> V_3 . V_4 ] . V_32 . V_15 ;
F_7 ( V_23 ) ;
F_8 ( V_23 , V_15 + 0x00 , F_11 ( V_30 ) | 4 ) ;
F_8 ( V_23 , V_15 + 0x04 , F_12 ( V_30 ) ) ;
F_9 ( V_23 ) ;
}
return 0 ;
}
static void
F_13 ( struct V_12 * V_13 ,
struct V_1 * V_2 )
{
struct V_16 * V_17 = V_16 ( V_13 ) ;
F_14 ( & V_17 -> V_31 [ V_2 -> V_3 . V_4 ] . V_32 ) ;
F_15 ( & V_17 -> V_31 [ V_2 -> V_3 . V_4 ] . V_23 ) ;
}
static int
F_16 ( struct V_12 * V_13 ,
struct V_1 * V_2 ,
struct V_33 * V_26 )
{
struct V_16 * V_17 = V_16 ( V_13 ) ;
int V_31 = V_2 -> V_3 . V_4 ;
int V_24 ;
if ( ! F_1 ( V_2 ) )
return 0 ;
V_24 = F_17 ( V_26 , NULL , 0 , & V_17 -> V_31 [ V_31 ] . V_23 ) ;
if ( V_24 )
return V_24 ;
return F_18 ( V_17 -> V_31 [ V_31 ] . V_23 , V_17 -> V_34 ,
V_35 , & V_17 -> V_31 [ V_31 ] . V_32 ) ;
}
static void
F_19 ( struct V_12 * V_13 )
{
struct V_16 * V_17 = V_16 ( V_13 ) ;
struct V_36 * V_19 = V_17 -> V_19 ;
struct V_20 * V_21 = V_19 -> V_13 . V_2 . V_3 . V_21 ;
T_1 V_37 = V_17 -> V_13 . V_25 * 8 ;
if ( ! F_20 ( & V_17 -> V_38 ) && ! V_17 -> V_39 ) {
F_21 ( V_19 , V_17 ) ;
F_22 ( V_21 , 0x003004 + V_37 , 0x00000001 , 0x00000000 ) ;
F_23 ( V_19 ) ;
}
F_24 ( V_19 ) ;
F_4 ( V_21 , 0x003000 + V_37 , 0x00000000 ) ;
}
static void
F_25 ( struct V_12 * V_13 )
{
struct V_16 * V_17 = V_16 ( V_13 ) ;
struct V_36 * V_19 = V_17 -> V_19 ;
struct V_20 * V_21 = V_19 -> V_13 . V_2 . V_3 . V_21 ;
T_1 V_30 = V_17 -> V_13 . V_23 -> V_30 >> 12 ;
T_1 V_37 = V_17 -> V_13 . V_25 * 8 ;
F_4 ( V_21 , 0x003000 + V_37 , 0xc0000000 | V_30 ) ;
if ( F_20 ( & V_17 -> V_38 ) && ! V_17 -> V_39 ) {
F_26 ( V_19 , V_17 ) ;
F_4 ( V_21 , 0x003004 + V_37 , 0x001f0001 ) ;
F_23 ( V_19 ) ;
}
}
static void *
F_27 ( struct V_12 * V_13 )
{
struct V_16 * V_17 = V_16 ( V_13 ) ;
F_28 ( NULL , & V_17 -> V_34 , V_17 -> V_40 ) ;
F_15 ( & V_17 -> V_40 ) ;
return V_17 ;
}
static int
F_29 ( struct V_41 * V_13 , const struct V_42 * V_43 ,
void * V_44 , T_1 V_45 , struct V_33 * * V_46 )
{
union {
struct V_47 V_48 ;
} * args = V_44 ;
struct V_36 * V_19 = V_36 ( V_13 ) ;
struct V_20 * V_21 = V_19 -> V_13 . V_2 . V_3 . V_21 ;
struct V_33 * V_49 = V_43 -> V_49 ;
struct V_16 * V_17 ;
T_2 V_50 , V_51 , V_52 ;
int V_24 = - V_53 , V_54 ;
F_30 ( V_49 , L_2 , V_45 ) ;
if ( ! ( V_24 = F_31 ( V_24 , & V_44 , & V_45 , args -> V_48 , 0 , 0 , false ) ) ) {
F_30 ( V_49 , L_3
L_4 ,
args -> V_48 . V_55 , args -> V_48 . V_34 , args -> V_48 . V_51 ,
args -> V_48 . V_52 ) ;
} else
return V_24 ;
if ( ! ( V_17 = F_32 ( sizeof( * V_17 ) , V_56 ) ) )
return - V_57 ;
* V_46 = & V_17 -> V_13 . V_26 ;
V_17 -> V_19 = V_19 ;
F_33 ( & V_17 -> V_38 ) ;
V_24 = F_34 ( & V_58 , & V_19 -> V_13 ,
0x1000 , 0x1000 , true , args -> V_48 . V_34 , 0 ,
( 1ULL << V_7 ) |
( 1ULL << V_8 ) |
( 1ULL << V_6 ) |
( 1ULL << V_9 ) |
( 1ULL << V_10 ) |
( 1ULL << V_11 ) |
( 1ULL << V_5 ) ,
1 , V_19 -> V_59 . V_60 . V_15 , 0x1000 ,
V_43 , & V_17 -> V_13 ) ;
if ( V_24 )
return V_24 ;
args -> V_48 . V_25 = V_17 -> V_13 . V_25 ;
V_24 = F_35 ( V_21 , 0x10000 , 0x1000 , false , NULL , & V_17 -> V_40 ) ;
if ( V_24 )
return V_24 ;
F_7 ( V_17 -> V_13 . V_23 ) ;
F_8 ( V_17 -> V_13 . V_23 , 0x0200 , F_11 ( V_17 -> V_40 -> V_30 ) ) ;
F_8 ( V_17 -> V_13 . V_23 , 0x0204 , F_12 ( V_17 -> V_40 -> V_30 ) ) ;
F_8 ( V_17 -> V_13 . V_23 , 0x0208 , 0xffffffff ) ;
F_8 ( V_17 -> V_13 . V_23 , 0x020c , 0x000000ff ) ;
F_9 ( V_17 -> V_13 . V_23 ) ;
V_24 = F_28 ( V_17 -> V_13 . V_34 , & V_17 -> V_34 , V_17 -> V_40 ) ;
if ( V_24 )
return V_24 ;
V_50 = V_17 -> V_13 . V_25 * 0x1000 ;
V_51 = args -> V_48 . V_51 ;
V_52 = F_36 ( args -> V_48 . V_52 / 8 ) ;
F_7 ( V_19 -> V_59 . V_61 ) ;
for ( V_54 = 0 ; V_54 < 0x1000 ; V_54 += 4 )
F_8 ( V_19 -> V_59 . V_61 , V_50 + V_54 , 0x00000000 ) ;
F_9 ( V_19 -> V_59 . V_61 ) ;
V_50 = F_37 ( V_19 -> V_59 . V_61 ) + V_50 ;
F_7 ( V_17 -> V_13 . V_23 ) ;
F_8 ( V_17 -> V_13 . V_23 , 0x08 , F_11 ( V_50 ) ) ;
F_8 ( V_17 -> V_13 . V_23 , 0x0c , F_12 ( V_50 ) ) ;
F_8 ( V_17 -> V_13 . V_23 , 0x10 , 0x0000face ) ;
F_8 ( V_17 -> V_13 . V_23 , 0x30 , 0xfffff902 ) ;
F_8 ( V_17 -> V_13 . V_23 , 0x48 , F_11 ( V_51 ) ) ;
F_8 ( V_17 -> V_13 . V_23 , 0x4c , F_12 ( V_51 ) |
( V_52 << 16 ) ) ;
F_8 ( V_17 -> V_13 . V_23 , 0x54 , 0x00000002 ) ;
F_8 ( V_17 -> V_13 . V_23 , 0x84 , 0x20400000 ) ;
F_8 ( V_17 -> V_13 . V_23 , 0x94 , 0x30000001 ) ;
F_8 ( V_17 -> V_13 . V_23 , 0x9c , 0x00000100 ) ;
F_8 ( V_17 -> V_13 . V_23 , 0xa4 , 0x1f1f1f1f ) ;
F_8 ( V_17 -> V_13 . V_23 , 0xa8 , 0x1f1f1f1f ) ;
F_8 ( V_17 -> V_13 . V_23 , 0xac , 0x0000001f ) ;
F_8 ( V_17 -> V_13 . V_23 , 0xb8 , 0xf8000000 ) ;
F_8 ( V_17 -> V_13 . V_23 , 0xf8 , 0x10003080 ) ;
F_8 ( V_17 -> V_13 . V_23 , 0xfc , 0x10000010 ) ;
F_9 ( V_17 -> V_13 . V_23 ) ;
return 0 ;
}
