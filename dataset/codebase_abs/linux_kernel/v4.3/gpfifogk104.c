static int
F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_5 * V_6 = & V_4 -> V_7 . V_8 . V_6 ;
struct V_9 * V_10 = V_6 -> V_10 ;
struct V_11 * V_12 = V_2 -> V_7 . V_13 . V_12 ;
F_2 ( V_10 , 0x002634 , V_2 -> V_7 . V_14 ) ;
if ( F_3 (device, 2000 ,
if (!(nvkm_rd32(device, 0x002634) & 0x00100000))
break;
) < 0 ) {
F_4 ( V_6 , L_1 ,
V_2 -> V_7 . V_14 , V_12 -> V_15 ) ;
return - V_16 ;
}
return 0 ;
}
static T_1
F_5 ( struct V_17 * V_8 )
{
switch ( V_8 -> V_6 . V_18 ) {
case V_19 :
case V_20 :
case V_21 :
case V_22 : return 0x0000 ;
case V_23 : return 0x0210 ;
case V_24 : return 0x0250 ;
case V_25 : return 0x0260 ;
case V_26 : return 0x0270 ;
default:
F_6 ( 1 ) ;
return 0 ;
}
}
static int
F_7 ( struct V_27 * V_7 ,
struct V_17 * V_8 , bool V_28 )
{
const T_1 V_29 = F_5 ( V_8 ) ;
struct V_1 * V_2 = V_1 ( V_7 ) ;
struct V_30 * V_31 = V_2 -> V_7 . V_31 ;
int V_32 ;
V_32 = F_1 ( V_2 ) ;
if ( V_32 && V_28 )
return V_32 ;
if ( V_29 ) {
F_8 ( V_31 ) ;
F_9 ( V_31 , V_29 + 0x00 , 0x00000000 ) ;
F_9 ( V_31 , V_29 + 0x04 , 0x00000000 ) ;
F_10 ( V_31 ) ;
}
return V_32 ;
}
static int
F_11 ( struct V_27 * V_7 ,
struct V_17 * V_8 )
{
const T_1 V_29 = F_5 ( V_8 ) ;
struct V_1 * V_2 = V_1 ( V_7 ) ;
struct V_30 * V_31 = V_2 -> V_7 . V_31 ;
if ( V_29 ) {
T_2 V_33 = V_2 -> V_34 [ V_8 -> V_6 . V_18 ] . V_35 . V_29 ;
F_8 ( V_31 ) ;
F_9 ( V_31 , V_29 + 0x00 , F_12 ( V_33 ) | 4 ) ;
F_9 ( V_31 , V_29 + 0x04 , F_13 ( V_33 ) ) ;
F_10 ( V_31 ) ;
}
return 0 ;
}
static void
F_14 ( struct V_27 * V_7 ,
struct V_17 * V_8 )
{
struct V_1 * V_2 = V_1 ( V_7 ) ;
F_15 ( & V_2 -> V_34 [ V_8 -> V_6 . V_18 ] . V_35 ) ;
F_16 ( & V_2 -> V_34 [ V_8 -> V_6 . V_18 ] . V_31 ) ;
}
static int
F_17 ( struct V_27 * V_7 ,
struct V_17 * V_8 ,
struct V_36 * V_13 )
{
struct V_1 * V_2 = V_1 ( V_7 ) ;
int V_34 = V_8 -> V_6 . V_18 ;
int V_32 ;
if ( ! F_5 ( V_8 ) )
return 0 ;
V_32 = F_18 ( V_13 , NULL , 0 , & V_2 -> V_34 [ V_34 ] . V_31 ) ;
if ( V_32 )
return V_32 ;
return F_19 ( V_2 -> V_34 [ V_34 ] . V_31 , V_2 -> V_37 ,
V_38 , & V_2 -> V_34 [ V_34 ] . V_35 ) ;
}
static void
F_20 ( struct V_27 * V_7 )
{
struct V_1 * V_2 = V_1 ( V_7 ) ;
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_9 * V_10 = V_4 -> V_7 . V_8 . V_6 . V_10 ;
T_1 V_39 = V_2 -> V_7 . V_14 * 8 ;
if ( ! F_21 ( & V_2 -> V_40 ) ) {
F_22 ( & V_2 -> V_40 ) ;
F_23 ( V_10 , 0x800004 + V_39 , 0x00000800 , 0x00000800 ) ;
F_24 ( V_4 , V_2 -> V_8 ) ;
}
F_2 ( V_10 , 0x800000 + V_39 , 0x00000000 ) ;
}
static void
F_25 ( struct V_27 * V_7 )
{
struct V_1 * V_2 = V_1 ( V_7 ) ;
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_9 * V_10 = V_4 -> V_7 . V_8 . V_6 . V_10 ;
T_1 V_33 = V_2 -> V_7 . V_31 -> V_33 >> 12 ;
T_1 V_39 = V_2 -> V_7 . V_14 * 8 ;
F_23 ( V_10 , 0x800004 + V_39 , 0x000f0000 , V_2 -> V_8 << 16 ) ;
F_2 ( V_10 , 0x800000 + V_39 , 0x80000000 | V_33 ) ;
if ( F_21 ( & V_2 -> V_40 ) && ! V_2 -> V_41 ) {
F_26 ( & V_2 -> V_40 , & V_4 -> V_8 [ V_2 -> V_8 ] . V_2 ) ;
F_23 ( V_10 , 0x800004 + V_39 , 0x00000400 , 0x00000400 ) ;
F_24 ( V_4 , V_2 -> V_8 ) ;
F_23 ( V_10 , 0x800004 + V_39 , 0x00000400 , 0x00000400 ) ;
}
}
static void *
F_27 ( struct V_27 * V_7 )
{
struct V_1 * V_2 = V_1 ( V_7 ) ;
F_28 ( NULL , & V_2 -> V_37 , V_2 -> V_42 ) ;
F_16 ( & V_2 -> V_42 ) ;
return V_2 ;
}
int
F_29 ( struct V_43 * V_7 , const struct V_44 * V_45 ,
void * V_46 , T_1 V_47 , struct V_36 * * V_48 )
{
union {
struct V_49 V_50 ;
} * args = V_46 ;
struct V_3 * V_4 = V_3 ( V_7 ) ;
struct V_9 * V_10 = V_4 -> V_7 . V_8 . V_6 . V_10 ;
struct V_36 * V_51 = V_45 -> V_51 ;
struct V_1 * V_2 ;
T_2 V_52 , V_53 , V_54 ;
T_1 V_55 ;
int V_32 , V_56 ;
F_30 ( V_51 , L_2 , V_47 ) ;
if ( F_31 ( args -> V_50 , 0 , 0 , false ) ) {
F_30 ( V_51 , L_3
L_4 ,
args -> V_50 . V_57 , args -> V_50 . V_37 , args -> V_50 . V_53 ,
args -> V_50 . V_54 , args -> V_50 . V_8 ) ;
} else
return V_32 ;
for ( V_56 = 0 , V_55 = 0 ; V_56 < F_32 ( V_4 -> V_8 ) ; V_56 ++ ) {
T_2 V_58 = F_33 ( V_56 ) ;
if ( ! F_34 ( V_10 , F_35 ( V_58 ) ) )
continue;
V_55 |= ( 1 << V_56 ) ;
}
if ( ! args -> V_50 . V_8 ) {
args -> V_50 . V_8 = V_55 ;
return F_36 ( V_45 , NULL , 0 , V_48 ) ;
}
args -> V_50 . V_8 &= V_55 ;
if ( ! args -> V_50 . V_8 ) {
F_30 ( V_51 , L_5 ) ;
return - V_59 ;
}
if ( ! ( V_2 = F_37 ( sizeof( * V_2 ) , V_60 ) ) )
return - V_61 ;
* V_48 = & V_2 -> V_7 . V_13 ;
V_2 -> V_4 = V_4 ;
V_2 -> V_8 = F_38 ( args -> V_50 . V_8 ) ;
F_39 ( & V_2 -> V_40 ) ;
V_32 = F_40 ( & V_62 , & V_4 -> V_7 ,
0x1000 , 0x1000 , true , args -> V_50 . V_37 , 0 ,
F_33 ( V_2 -> V_8 ) ,
1 , V_4 -> V_63 . V_64 . V_29 , 0x200 ,
V_45 , & V_2 -> V_7 ) ;
if ( V_32 )
return V_32 ;
args -> V_50 . V_14 = V_2 -> V_7 . V_14 ;
V_32 = F_41 ( V_10 , 0x10000 , 0x1000 , false , NULL , & V_2 -> V_42 ) ;
if ( V_32 )
return V_32 ;
F_8 ( V_2 -> V_7 . V_31 ) ;
F_9 ( V_2 -> V_7 . V_31 , 0x0200 , F_12 ( V_2 -> V_42 -> V_33 ) ) ;
F_9 ( V_2 -> V_7 . V_31 , 0x0204 , F_13 ( V_2 -> V_42 -> V_33 ) ) ;
F_9 ( V_2 -> V_7 . V_31 , 0x0208 , 0xffffffff ) ;
F_9 ( V_2 -> V_7 . V_31 , 0x020c , 0x000000ff ) ;
F_10 ( V_2 -> V_7 . V_31 ) ;
V_32 = F_28 ( V_2 -> V_7 . V_37 , & V_2 -> V_37 , V_2 -> V_42 ) ;
if ( V_32 )
return V_32 ;
V_52 = V_2 -> V_7 . V_14 * 0x200 ;
V_53 = args -> V_50 . V_53 ;
V_54 = F_42 ( args -> V_50 . V_54 / 8 ) ;
F_8 ( V_4 -> V_63 . V_65 ) ;
for ( V_56 = 0 ; V_56 < 0x200 ; V_56 += 4 )
F_9 ( V_4 -> V_63 . V_65 , V_52 + V_56 , 0x00000000 ) ;
F_10 ( V_4 -> V_63 . V_65 ) ;
V_52 = F_43 ( V_4 -> V_63 . V_65 ) + V_52 ;
F_8 ( V_2 -> V_7 . V_31 ) ;
F_9 ( V_2 -> V_7 . V_31 , 0x08 , F_12 ( V_52 ) ) ;
F_9 ( V_2 -> V_7 . V_31 , 0x0c , F_13 ( V_52 ) ) ;
F_9 ( V_2 -> V_7 . V_31 , 0x10 , 0x0000face ) ;
F_9 ( V_2 -> V_7 . V_31 , 0x30 , 0xfffff902 ) ;
F_9 ( V_2 -> V_7 . V_31 , 0x48 , F_12 ( V_53 ) ) ;
F_9 ( V_2 -> V_7 . V_31 , 0x4c , F_13 ( V_53 ) |
( V_54 << 16 ) ) ;
F_9 ( V_2 -> V_7 . V_31 , 0x84 , 0x20400000 ) ;
F_9 ( V_2 -> V_7 . V_31 , 0x94 , 0x30000001 ) ;
F_9 ( V_2 -> V_7 . V_31 , 0x9c , 0x00000100 ) ;
F_9 ( V_2 -> V_7 . V_31 , 0xac , 0x0000001f ) ;
F_9 ( V_2 -> V_7 . V_31 , 0xe8 , V_2 -> V_7 . V_14 ) ;
F_9 ( V_2 -> V_7 . V_31 , 0xb8 , 0xf8000000 ) ;
F_9 ( V_2 -> V_7 . V_31 , 0xf8 , 0x10003080 ) ;
F_9 ( V_2 -> V_7 . V_31 , 0xfc , 0x10000010 ) ;
F_10 ( V_2 -> V_7 . V_31 ) ;
return 0 ;
}
