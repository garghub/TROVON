void
F_1 ( struct V_1 * V_2 , int V_3 , T_1 V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 -> V_8 . V_9 . V_6 ;
const T_2 V_10 = F_2 ( V_2 ) ;
F_3 ( V_6 , 0x61c128 + V_10 , 0x0000003f , V_4 ) ;
}
void
F_4 ( struct V_1 * V_2 , int V_3 ,
T_1 V_11 , T_1 V_12 , T_1 V_13 , T_1 V_14 )
{
struct V_5 * V_6 = V_2 -> V_7 -> V_8 . V_9 . V_6 ;
const T_2 V_10 = F_2 ( V_2 ) ;
F_3 ( V_6 , 0x61c10c + V_10 , 0x000001fc , V_11 << 2 ) ;
F_3 ( V_6 , 0x61c128 + V_10 , 0x010f7f00 , V_12 << 24 |
V_13 << 16 |
V_14 << 8 ) ;
}
void
F_5 ( struct V_1 * V_2 , int V_3 , T_3 V_15 , T_2 V_16 )
{
struct V_5 * V_6 = V_2 -> V_7 -> V_8 . V_9 . V_6 ;
const T_2 V_17 = F_6 ( V_2 ) ;
F_3 ( V_6 , 0x61c1e8 + V_17 , 0x0000ffff , V_15 ) ;
F_3 ( V_6 , 0x61c1ec + V_17 , 0x00ffffff , V_16 ) ;
}
void
F_7 ( struct V_1 * V_2 , int V_18 , int V_19 , int V_20 , int V_21 , int V_22 )
{
struct V_5 * V_6 = V_2 -> V_7 -> V_8 . V_9 . V_6 ;
const T_2 V_10 = F_2 ( V_2 ) ;
const T_2 V_23 = V_2 -> V_24 -> V_25 . V_26 [ V_18 ] * 8 ;
T_2 V_27 [ 3 ] ;
V_27 [ 0 ] = F_8 ( V_6 , 0x61c118 + V_10 ) & ~ ( 0x000000ff << V_23 ) ;
V_27 [ 1 ] = F_8 ( V_6 , 0x61c120 + V_10 ) & ~ ( 0x000000ff << V_23 ) ;
V_27 [ 2 ] = F_8 ( V_6 , 0x61c130 + V_10 ) ;
if ( ( V_27 [ 2 ] & 0x0000ff00 ) < ( V_22 << 8 ) || V_18 == 0 )
V_27 [ 2 ] = ( V_27 [ 2 ] & ~ 0x0000ff00 ) | ( V_22 << 8 ) ;
F_9 ( V_6 , 0x61c118 + V_10 , V_27 [ 0 ] | ( V_20 << V_23 ) ) ;
F_9 ( V_6 , 0x61c120 + V_10 , V_27 [ 1 ] | ( V_21 << V_23 ) ) ;
F_9 ( V_6 , 0x61c130 + V_10 , V_27 [ 2 ] ) ;
}
void
F_10 ( struct V_1 * V_2 , int V_28 )
{
struct V_5 * V_6 = V_2 -> V_7 -> V_8 . V_9 . V_6 ;
const T_2 V_10 = F_2 ( V_2 ) ;
F_3 ( V_6 , 0x61c10c + V_10 , 0x0f000000 , V_28 << 24 ) ;
}
void
F_11 ( struct V_1 * V_2 , int V_29 )
{
struct V_5 * V_6 = V_2 -> V_7 -> V_8 . V_9 . V_6 ;
const T_2 V_17 = F_6 ( V_2 ) ;
const T_2 V_10 = F_2 ( V_2 ) ;
T_2 V_30 = 0 , V_31 ;
for ( V_31 = 0 ; V_31 < V_29 ; V_31 ++ )
V_30 |= 1 << V_2 -> V_24 -> V_25 . V_26 [ V_31 ] ;
F_3 ( V_6 , 0x61c130 + V_10 , 0x0000000f , V_30 ) ;
F_3 ( V_6 , 0x61c034 + V_17 , 0x80000000 , 0x80000000 ) ;
F_12 (device, 2000 ,
if (!(nvkm_rd32(device, 0x61c034 + soff) & 0x80000000))
break;
) ;
}
int
F_13 ( struct V_1 * V_2 , struct V_32 * V_33 )
{
struct V_5 * V_6 = V_2 -> V_7 -> V_8 . V_9 . V_6 ;
const T_2 V_17 = F_6 ( V_2 ) ;
const T_2 V_10 = F_2 ( V_2 ) ;
T_2 V_34 = 0x00000000 ;
T_2 V_35 = 0x00000000 ;
V_34 |= ( ( 1 << V_2 -> V_25 . V_29 ) - 1 ) << 16 ;
if ( V_2 -> V_25 . V_36 )
V_34 |= 0x00004000 ;
if ( V_2 -> V_25 . V_37 > 0x06 )
V_35 |= 0x00040000 ;
F_3 ( V_6 , 0x614300 + V_17 , 0x000c0000 , V_35 ) ;
F_3 ( V_6 , 0x61c10c + V_10 , 0x001f4000 , V_34 ) ;
return 0 ;
}
static bool
F_14 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_7 -> V_8 . V_9 . V_6 ;
const T_2 V_17 = F_6 ( V_2 ) ;
if ( V_2 -> V_38 . V_39 == V_40 ) {
switch ( F_8 ( V_6 , 0x614300 + V_17 ) & 0x00030000 ) {
case 0x00000000 :
case 0x00030000 :
return true ;
default:
break;
}
}
return false ;
}
static void
F_15 ( struct V_41 * V_7 )
{
struct V_5 * V_6 = V_7 -> V_8 . V_9 . V_6 ;
struct V_1 * V_42 ;
bool V_43 = false ;
T_2 V_35 ;
F_16 (ior, &disp->ior, head) {
if ( V_42 -> type != V_44 )
continue;
V_35 = F_8 ( V_6 , 0x614300 + F_6 ( V_42 ) ) ;
switch ( V_35 & 0x03000000 ) {
case 0x02000000 :
case 0x03000000 :
V_43 = true ;
break;
default:
break;
}
}
if ( V_43 )
return;
F_3 ( V_6 , 0x00e840 , 0x80000000 , 0x00000000 ) ;
}
static void
F_17 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_7 -> V_8 . V_9 . V_6 ;
const T_2 V_17 = F_6 ( V_2 ) ;
T_2 V_45 ;
if ( ! F_14 ( V_2 ) )
return;
V_45 = F_8 ( V_6 , 0x61c004 + V_17 ) ;
if ( V_45 & 0x00000001 ) {
T_2 V_46 = F_8 ( V_6 , 0x61c030 + V_17 ) ;
T_2 V_47 = ( V_46 & 0x00000f00 ) >> 8 ;
T_2 V_48 = V_46 & 0x0000000f ;
F_9 ( V_6 , 0x61c040 + V_17 + V_47 * 4 , 0x1f008000 ) ;
F_12 (device, 2000 ,
if (!(nvkm_rd32(device, 0x61c030 + soff) & 0x10000000))
break;
) ;
F_3 ( V_6 , 0x61c004 + V_17 , 0x80000001 , 0x80000000 ) ;
F_12 (device, 2000 ,
if (!(nvkm_rd32(device, 0x61c030 + soff) & 0x10000000))
break;
) ;
F_9 ( V_6 , 0x61c040 + V_17 + V_47 * 4 , 0x00002000 ) ;
F_9 ( V_6 , 0x61c040 + V_17 + V_48 * 4 , 0x1f000000 ) ;
}
F_3 ( V_6 , 0x61c10c + V_17 , 0x00000001 , 0x00000000 ) ;
F_3 ( V_6 , 0x614300 + V_17 , 0x03000000 , 0x00000000 ) ;
if ( V_45 & 0x00000001 ) {
F_3 ( V_6 , 0x61c004 + V_17 , 0x80000001 , 0x80000001 ) ;
}
F_15 ( V_2 -> V_7 ) ;
}
static void
F_18 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_7 -> V_8 . V_9 . V_6 ;
const T_2 V_17 = F_6 ( V_2 ) ;
if ( ! F_14 ( V_2 ) )
return;
F_3 ( V_6 , 0x00e840 , 0x80000000 , 0x80000000 ) ;
F_3 ( V_6 , 0x614300 + V_17 , 0x03000000 , 0x03000000 ) ;
F_3 ( V_6 , 0x61c10c + V_17 , 0x00000001 , 0x00000001 ) ;
F_3 ( V_6 , 0x61c00c + V_17 , 0x0f000000 , 0x00000000 ) ;
F_3 ( V_6 , 0x61c008 + V_17 , 0xff000000 , 0x14000000 ) ;
F_19 ( V_6 , 400 , V_49 ) ;
F_3 ( V_6 , 0x61c008 + V_17 , 0xff000000 , 0x00000000 ) ;
F_3 ( V_6 , 0x61c00c + V_17 , 0x0f000000 , 0x01000000 ) ;
if ( F_8 ( V_6 , 0x61c004 + V_17 ) & 0x00000001 ) {
T_2 V_46 = F_8 ( V_6 , 0x61c030 + V_17 ) ;
T_2 V_48 = V_46 & 0x0000000f ;
F_9 ( V_6 , 0x61c040 + V_17 + V_48 * 4 , 0x1f008000 ) ;
}
}
void
F_20 ( struct V_1 * V_2 , struct V_50 * V_51 )
{
struct V_5 * V_6 = V_2 -> V_7 -> V_8 . V_9 . V_6 ;
const T_2 V_52 = V_2 -> V_53 * 8 + ( V_51 == & V_2 -> V_54 ) * 4 ;
T_2 V_55 = F_8 ( V_6 , 0x610794 + V_52 ) ;
V_51 -> V_56 = ( V_55 & 0x00000f00 ) >> 8 ;
switch ( V_51 -> V_56 ) {
case 0 : V_51 -> V_39 = V_57 ; V_51 -> V_58 = 1 ; break;
case 1 : V_51 -> V_39 = V_40 ; V_51 -> V_58 = 1 ; break;
case 2 : V_51 -> V_39 = V_40 ; V_51 -> V_58 = 2 ; break;
case 5 : V_51 -> V_39 = V_40 ; V_51 -> V_58 = 3 ; break;
case 8 : V_51 -> V_39 = V_59 ; V_51 -> V_58 = 1 ; break;
case 9 : V_51 -> V_39 = V_59 ; V_51 -> V_58 = 2 ; break;
default:
V_51 -> V_39 = V_60 ;
break;
}
V_51 -> V_3 = V_55 & 0x00000003 ;
F_21 ( V_2 , V_51 , V_55 ) ;
}
int
F_22 ( struct V_41 * V_7 , int V_53 )
{
return F_23 ( & V_61 , V_7 , V_53 ) ;
}
