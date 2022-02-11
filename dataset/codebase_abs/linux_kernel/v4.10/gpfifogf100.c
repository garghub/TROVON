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
F_4 ( & V_3 -> V_25 ) ;
F_5 ( V_21 , 0x002634 , V_17 -> V_13 . V_26 ) ;
if ( F_6 (device, 2000 ,
if (nvkm_rd32(device, 0x002634) == chan->base.chid)
break;
) < 0 ) {
F_7 ( V_3 , L_1 ,
V_17 -> V_13 . V_26 , V_17 -> V_13 . V_27 . V_28 -> V_29 ) ;
V_24 = - V_30 ;
}
F_8 ( & V_3 -> V_25 ) ;
if ( V_24 && V_14 )
return V_24 ;
if ( V_15 ) {
F_9 ( V_23 ) ;
F_10 ( V_23 , V_15 + 0x00 , 0x00000000 ) ;
F_10 ( V_23 , V_15 + 0x04 , 0x00000000 ) ;
F_11 ( V_23 ) ;
}
return V_24 ;
}
static int
F_12 ( struct V_12 * V_13 ,
struct V_1 * V_2 )
{
const T_1 V_15 = F_1 ( V_2 ) ;
struct V_16 * V_17 = V_16 ( V_13 ) ;
struct V_22 * V_23 = V_17 -> V_13 . V_23 ;
if ( V_15 ) {
T_2 V_31 = V_17 -> V_32 [ V_2 -> V_3 . V_4 ] . V_33 . V_15 ;
F_9 ( V_23 ) ;
F_10 ( V_23 , V_15 + 0x00 , F_13 ( V_31 ) | 4 ) ;
F_10 ( V_23 , V_15 + 0x04 , F_14 ( V_31 ) ) ;
F_11 ( V_23 ) ;
}
return 0 ;
}
static void
F_15 ( struct V_12 * V_13 ,
struct V_1 * V_2 )
{
struct V_16 * V_17 = V_16 ( V_13 ) ;
F_16 ( & V_17 -> V_32 [ V_2 -> V_3 . V_4 ] . V_33 ) ;
F_17 ( & V_17 -> V_32 [ V_2 -> V_3 . V_4 ] . V_23 ) ;
}
static int
F_18 ( struct V_12 * V_13 ,
struct V_1 * V_2 ,
struct V_34 * V_27 )
{
struct V_16 * V_17 = V_16 ( V_13 ) ;
int V_32 = V_2 -> V_3 . V_4 ;
int V_24 ;
if ( ! F_1 ( V_2 ) )
return 0 ;
V_24 = F_19 ( V_27 , NULL , 0 , & V_17 -> V_32 [ V_32 ] . V_23 ) ;
if ( V_24 )
return V_24 ;
return F_20 ( V_17 -> V_32 [ V_32 ] . V_23 , V_17 -> V_35 ,
V_36 , & V_17 -> V_32 [ V_32 ] . V_33 ) ;
}
static void
F_21 ( struct V_12 * V_13 )
{
struct V_16 * V_17 = V_16 ( V_13 ) ;
struct V_37 * V_19 = V_17 -> V_19 ;
struct V_20 * V_21 = V_19 -> V_13 . V_2 . V_3 . V_21 ;
T_1 V_38 = V_17 -> V_13 . V_26 * 8 ;
if ( ! F_22 ( & V_17 -> V_39 ) && ! V_17 -> V_40 ) {
F_23 ( V_19 , V_17 ) ;
F_24 ( V_21 , 0x003004 + V_38 , 0x00000001 , 0x00000000 ) ;
F_25 ( V_19 ) ;
}
F_26 ( V_19 ) ;
F_5 ( V_21 , 0x003000 + V_38 , 0x00000000 ) ;
}
static void
F_27 ( struct V_12 * V_13 )
{
struct V_16 * V_17 = V_16 ( V_13 ) ;
struct V_37 * V_19 = V_17 -> V_19 ;
struct V_20 * V_21 = V_19 -> V_13 . V_2 . V_3 . V_21 ;
T_1 V_31 = V_17 -> V_13 . V_23 -> V_31 >> 12 ;
T_1 V_38 = V_17 -> V_13 . V_26 * 8 ;
F_5 ( V_21 , 0x003000 + V_38 , 0xc0000000 | V_31 ) ;
if ( F_22 ( & V_17 -> V_39 ) && ! V_17 -> V_40 ) {
F_28 ( V_19 , V_17 ) ;
F_5 ( V_21 , 0x003004 + V_38 , 0x001f0001 ) ;
F_25 ( V_19 ) ;
}
}
static void *
F_29 ( struct V_12 * V_13 )
{
struct V_16 * V_17 = V_16 ( V_13 ) ;
F_30 ( NULL , & V_17 -> V_35 , V_17 -> V_41 ) ;
F_17 ( & V_17 -> V_41 ) ;
return V_17 ;
}
static int
F_31 ( struct V_42 * V_13 , const struct V_43 * V_44 ,
void * V_45 , T_1 V_46 , struct V_34 * * V_47 )
{
union {
struct V_48 V_49 ;
} * args = V_45 ;
struct V_37 * V_19 = V_37 ( V_13 ) ;
struct V_20 * V_21 = V_19 -> V_13 . V_2 . V_3 . V_21 ;
struct V_34 * V_50 = V_44 -> V_50 ;
struct V_16 * V_17 ;
T_2 V_51 , V_52 , V_53 ;
int V_24 = - V_54 , V_55 ;
F_32 ( V_50 , L_2 , V_46 ) ;
if ( ! ( V_24 = F_33 ( V_24 , & V_45 , & V_46 , args -> V_49 , 0 , 0 , false ) ) ) {
F_32 ( V_50 , L_3
L_4 ,
args -> V_49 . V_56 , args -> V_49 . V_35 , args -> V_49 . V_52 ,
args -> V_49 . V_53 ) ;
} else
return V_24 ;
if ( ! ( V_17 = F_34 ( sizeof( * V_17 ) , V_57 ) ) )
return - V_58 ;
* V_47 = & V_17 -> V_13 . V_27 ;
V_17 -> V_19 = V_19 ;
F_35 ( & V_17 -> V_39 ) ;
V_24 = F_36 ( & V_59 , & V_19 -> V_13 ,
0x1000 , 0x1000 , true , args -> V_49 . V_35 , 0 ,
( 1ULL << V_7 ) |
( 1ULL << V_8 ) |
( 1ULL << V_6 ) |
( 1ULL << V_9 ) |
( 1ULL << V_10 ) |
( 1ULL << V_11 ) |
( 1ULL << V_5 ) ,
1 , V_19 -> V_60 . V_61 . V_15 , 0x1000 ,
V_44 , & V_17 -> V_13 ) ;
if ( V_24 )
return V_24 ;
args -> V_49 . V_26 = V_17 -> V_13 . V_26 ;
V_24 = F_37 ( V_21 , 0x10000 , 0x1000 , false , NULL , & V_17 -> V_41 ) ;
if ( V_24 )
return V_24 ;
F_9 ( V_17 -> V_13 . V_23 ) ;
F_10 ( V_17 -> V_13 . V_23 , 0x0200 , F_13 ( V_17 -> V_41 -> V_31 ) ) ;
F_10 ( V_17 -> V_13 . V_23 , 0x0204 , F_14 ( V_17 -> V_41 -> V_31 ) ) ;
F_10 ( V_17 -> V_13 . V_23 , 0x0208 , 0xffffffff ) ;
F_10 ( V_17 -> V_13 . V_23 , 0x020c , 0x000000ff ) ;
F_11 ( V_17 -> V_13 . V_23 ) ;
V_24 = F_30 ( V_17 -> V_13 . V_35 , & V_17 -> V_35 , V_17 -> V_41 ) ;
if ( V_24 )
return V_24 ;
V_51 = V_17 -> V_13 . V_26 * 0x1000 ;
V_52 = args -> V_49 . V_52 ;
V_53 = F_38 ( args -> V_49 . V_53 / 8 ) ;
F_9 ( V_19 -> V_60 . V_62 ) ;
for ( V_55 = 0 ; V_55 < 0x1000 ; V_55 += 4 )
F_10 ( V_19 -> V_60 . V_62 , V_51 + V_55 , 0x00000000 ) ;
F_11 ( V_19 -> V_60 . V_62 ) ;
V_51 = F_39 ( V_19 -> V_60 . V_62 ) + V_51 ;
F_9 ( V_17 -> V_13 . V_23 ) ;
F_10 ( V_17 -> V_13 . V_23 , 0x08 , F_13 ( V_51 ) ) ;
F_10 ( V_17 -> V_13 . V_23 , 0x0c , F_14 ( V_51 ) ) ;
F_10 ( V_17 -> V_13 . V_23 , 0x10 , 0x0000face ) ;
F_10 ( V_17 -> V_13 . V_23 , 0x30 , 0xfffff902 ) ;
F_10 ( V_17 -> V_13 . V_23 , 0x48 , F_13 ( V_52 ) ) ;
F_10 ( V_17 -> V_13 . V_23 , 0x4c , F_14 ( V_52 ) |
( V_53 << 16 ) ) ;
F_10 ( V_17 -> V_13 . V_23 , 0x54 , 0x00000002 ) ;
F_10 ( V_17 -> V_13 . V_23 , 0x84 , 0x20400000 ) ;
F_10 ( V_17 -> V_13 . V_23 , 0x94 , 0x30000001 ) ;
F_10 ( V_17 -> V_13 . V_23 , 0x9c , 0x00000100 ) ;
F_10 ( V_17 -> V_13 . V_23 , 0xa4 , 0x1f1f1f1f ) ;
F_10 ( V_17 -> V_13 . V_23 , 0xa8 , 0x1f1f1f1f ) ;
F_10 ( V_17 -> V_13 . V_23 , 0xac , 0x0000001f ) ;
F_10 ( V_17 -> V_13 . V_23 , 0xb8 , 0xf8000000 ) ;
F_10 ( V_17 -> V_13 . V_23 , 0xf8 , 0x10003080 ) ;
F_10 ( V_17 -> V_13 . V_23 , 0xfc , 0x10000010 ) ;
F_11 ( V_17 -> V_13 . V_23 ) ;
return 0 ;
}
