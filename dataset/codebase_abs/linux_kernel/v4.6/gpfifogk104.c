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
case V_24 : return 0x0220 ;
case V_25 : return 0x0250 ;
case V_26 : return 0x0260 ;
case V_27 : return 0x0270 ;
case V_28 : return 0x0280 ;
case V_29 : return 0x0290 ;
case V_30 : return 0x02100270 ;
case V_31 : return 0x02100290 ;
case V_32 : return 0x0210 ;
default:
F_6 ( 1 ) ;
return 0 ;
}
}
static int
F_7 ( struct V_33 * V_7 ,
struct V_17 * V_8 , bool V_34 )
{
struct V_1 * V_2 = V_1 ( V_7 ) ;
struct V_35 * V_36 = V_2 -> V_7 . V_36 ;
T_1 V_37 = F_5 ( V_8 ) ;
int V_38 ;
V_38 = F_1 ( V_2 ) ;
if ( V_38 && V_34 )
return V_38 ;
if ( V_37 ) {
F_8 ( V_36 ) ;
F_9 ( V_36 , ( V_37 & 0xffff ) + 0x00 , 0x00000000 ) ;
F_9 ( V_36 , ( V_37 & 0xffff ) + 0x04 , 0x00000000 ) ;
if ( ( V_37 >>= 16 ) ) {
F_9 ( V_36 , V_37 + 0x00 , 0x00000000 ) ;
F_9 ( V_36 , V_37 + 0x04 , 0x00000000 ) ;
}
F_10 ( V_36 ) ;
}
return V_38 ;
}
static int
F_11 ( struct V_33 * V_7 ,
struct V_17 * V_8 )
{
struct V_1 * V_2 = V_1 ( V_7 ) ;
struct V_35 * V_36 = V_2 -> V_7 . V_36 ;
T_1 V_37 = F_5 ( V_8 ) ;
if ( V_37 ) {
T_2 V_39 = V_2 -> V_40 [ V_8 -> V_6 . V_18 ] . V_41 . V_37 ;
T_1 V_42 = F_12 ( V_39 ) | 0x00000004 ;
T_1 V_43 = F_13 ( V_39 ) ;
F_8 ( V_36 ) ;
F_9 ( V_36 , ( V_37 & 0xffff ) + 0x00 , V_42 ) ;
F_9 ( V_36 , ( V_37 & 0xffff ) + 0x04 , V_43 ) ;
if ( ( V_37 >>= 16 ) ) {
F_9 ( V_36 , V_37 + 0x00 , V_42 ) ;
F_9 ( V_36 , V_37 + 0x04 , V_43 ) ;
}
F_10 ( V_36 ) ;
}
return 0 ;
}
static void
F_14 ( struct V_33 * V_7 ,
struct V_17 * V_8 )
{
struct V_1 * V_2 = V_1 ( V_7 ) ;
F_15 ( & V_2 -> V_40 [ V_8 -> V_6 . V_18 ] . V_41 ) ;
F_16 ( & V_2 -> V_40 [ V_8 -> V_6 . V_18 ] . V_36 ) ;
}
static int
F_17 ( struct V_33 * V_7 ,
struct V_17 * V_8 ,
struct V_44 * V_13 )
{
struct V_1 * V_2 = V_1 ( V_7 ) ;
int V_40 = V_8 -> V_6 . V_18 ;
int V_38 ;
if ( ! F_5 ( V_8 ) )
return 0 ;
V_38 = F_18 ( V_13 , NULL , 0 , & V_2 -> V_40 [ V_40 ] . V_36 ) ;
if ( V_38 )
return V_38 ;
return F_19 ( V_2 -> V_40 [ V_40 ] . V_36 , V_2 -> V_45 ,
V_46 , & V_2 -> V_40 [ V_40 ] . V_41 ) ;
}
static void
F_20 ( struct V_33 * V_7 )
{
struct V_1 * V_2 = V_1 ( V_7 ) ;
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_9 * V_10 = V_4 -> V_7 . V_8 . V_6 . V_10 ;
T_1 V_47 = V_2 -> V_7 . V_14 * 8 ;
if ( ! F_21 ( & V_2 -> V_48 ) ) {
F_22 ( V_4 , V_2 ) ;
F_23 ( V_10 , 0x800004 + V_47 , 0x00000800 , 0x00000800 ) ;
F_1 ( V_2 ) ;
F_24 ( V_4 , V_2 -> V_49 ) ;
}
F_2 ( V_10 , 0x800000 + V_47 , 0x00000000 ) ;
}
static void
F_25 ( struct V_33 * V_7 )
{
struct V_1 * V_2 = V_1 ( V_7 ) ;
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_9 * V_10 = V_4 -> V_7 . V_8 . V_6 . V_10 ;
T_1 V_39 = V_2 -> V_7 . V_36 -> V_39 >> 12 ;
T_1 V_47 = V_2 -> V_7 . V_14 * 8 ;
F_23 ( V_10 , 0x800004 + V_47 , 0x000f0000 , V_2 -> V_49 << 16 ) ;
F_2 ( V_10 , 0x800000 + V_47 , 0x80000000 | V_39 ) ;
if ( F_21 ( & V_2 -> V_48 ) && ! V_2 -> V_50 ) {
F_26 ( V_4 , V_2 ) ;
F_23 ( V_10 , 0x800004 + V_47 , 0x00000400 , 0x00000400 ) ;
F_24 ( V_4 , V_2 -> V_49 ) ;
F_23 ( V_10 , 0x800004 + V_47 , 0x00000400 , 0x00000400 ) ;
}
}
static void *
F_27 ( struct V_33 * V_7 )
{
struct V_1 * V_2 = V_1 ( V_7 ) ;
F_28 ( NULL , & V_2 -> V_45 , V_2 -> V_51 ) ;
F_16 ( & V_2 -> V_51 ) ;
return V_2 ;
}
static int
F_29 ( const struct V_52 * V_53 ,
struct V_3 * V_4 , T_1 * V_54 , T_3 * V_14 ,
T_2 V_45 , T_2 V_55 , T_2 V_56 ,
const struct V_57 * V_58 ,
struct V_44 * * V_59 )
{
struct V_9 * V_10 = V_4 -> V_7 . V_8 . V_6 . V_10 ;
struct V_1 * V_2 ;
int V_60 = - 1 , V_38 = - V_61 , V_62 , V_63 ;
T_1 V_64 = 0 , V_65 = 0 ;
T_2 V_66 = 0 ;
T_2 V_67 ;
for ( V_62 = 0 ; V_62 < V_4 -> V_68 ; V_62 ++ ) {
struct V_17 * V_8 = V_4 -> V_8 [ V_62 ] . V_8 ;
if ( V_8 ) {
T_2 V_69 = F_30 ( V_8 -> V_6 . V_18 ) ;
for ( V_63 = 0 ; V_53 [ V_63 ] . V_6 ; V_63 ++ ) {
if ( V_53 [ V_63 ] . V_6 & V_69 ) {
V_65 |= V_53 [ V_63 ] . V_8 ;
break;
}
}
if ( ! V_53 [ V_63 ] . V_6 )
continue;
if ( V_60 < 0 && ( * V_54 & V_65 ) )
V_60 = V_4 -> V_8 [ V_62 ] . V_49 ;
if ( V_60 == V_4 -> V_8 [ V_62 ] . V_49 ) {
V_64 |= V_53 [ V_63 ] . V_8 ;
V_66 |= V_53 [ V_63 ] . V_6 ;
}
}
}
if ( ! * V_54 ) {
* V_54 = V_65 ;
return F_31 ( V_58 , NULL , 0 , V_59 ) ;
}
* V_54 = V_65 ;
if ( V_60 < 0 )
return - V_70 ;
* V_54 = V_64 ;
if ( ! ( V_2 = F_32 ( sizeof( * V_2 ) , V_71 ) ) )
return - V_72 ;
* V_59 = & V_2 -> V_7 . V_13 ;
V_2 -> V_4 = V_4 ;
V_2 -> V_49 = V_60 ;
F_33 ( & V_2 -> V_48 ) ;
V_38 = F_34 ( & V_73 , & V_4 -> V_7 ,
0x1000 , 0x1000 , true , V_45 , 0 , V_66 ,
1 , V_4 -> V_74 . V_75 . V_37 , 0x200 ,
V_58 , & V_2 -> V_7 ) ;
if ( V_38 )
return V_38 ;
* V_14 = V_2 -> V_7 . V_14 ;
V_38 = F_35 ( V_10 , 0x10000 , 0x1000 , false , NULL , & V_2 -> V_51 ) ;
if ( V_38 )
return V_38 ;
F_8 ( V_2 -> V_7 . V_36 ) ;
F_9 ( V_2 -> V_7 . V_36 , 0x0200 , F_12 ( V_2 -> V_51 -> V_39 ) ) ;
F_9 ( V_2 -> V_7 . V_36 , 0x0204 , F_13 ( V_2 -> V_51 -> V_39 ) ) ;
F_9 ( V_2 -> V_7 . V_36 , 0x0208 , 0xffffffff ) ;
F_9 ( V_2 -> V_7 . V_36 , 0x020c , 0x000000ff ) ;
F_10 ( V_2 -> V_7 . V_36 ) ;
V_38 = F_28 ( V_2 -> V_7 . V_45 , & V_2 -> V_45 , V_2 -> V_51 ) ;
if ( V_38 )
return V_38 ;
V_67 = V_2 -> V_7 . V_14 * 0x200 ;
V_56 = F_36 ( V_56 / 8 ) ;
F_8 ( V_4 -> V_74 . V_76 ) ;
for ( V_62 = 0 ; V_62 < 0x200 ; V_62 += 4 )
F_9 ( V_4 -> V_74 . V_76 , V_67 + V_62 , 0x00000000 ) ;
F_10 ( V_4 -> V_74 . V_76 ) ;
V_67 = F_37 ( V_4 -> V_74 . V_76 ) + V_67 ;
F_8 ( V_2 -> V_7 . V_36 ) ;
F_9 ( V_2 -> V_7 . V_36 , 0x08 , F_12 ( V_67 ) ) ;
F_9 ( V_2 -> V_7 . V_36 , 0x0c , F_13 ( V_67 ) ) ;
F_9 ( V_2 -> V_7 . V_36 , 0x10 , 0x0000face ) ;
F_9 ( V_2 -> V_7 . V_36 , 0x30 , 0xfffff902 ) ;
F_9 ( V_2 -> V_7 . V_36 , 0x48 , F_12 ( V_55 ) ) ;
F_9 ( V_2 -> V_7 . V_36 , 0x4c , F_13 ( V_55 ) |
( V_56 << 16 ) ) ;
F_9 ( V_2 -> V_7 . V_36 , 0x84 , 0x20400000 ) ;
F_9 ( V_2 -> V_7 . V_36 , 0x94 , 0x30000001 ) ;
F_9 ( V_2 -> V_7 . V_36 , 0x9c , 0x00000100 ) ;
F_9 ( V_2 -> V_7 . V_36 , 0xac , 0x0000001f ) ;
F_9 ( V_2 -> V_7 . V_36 , 0xe8 , V_2 -> V_7 . V_14 ) ;
F_9 ( V_2 -> V_7 . V_36 , 0xb8 , 0xf8000000 ) ;
F_9 ( V_2 -> V_7 . V_36 , 0xf8 , 0x10003080 ) ;
F_9 ( V_2 -> V_7 . V_36 , 0xfc , 0x10000010 ) ;
F_10 ( V_2 -> V_7 . V_36 ) ;
return 0 ;
}
int
F_38 ( struct V_77 * V_7 , const struct V_57 * V_58 ,
void * V_78 , T_1 V_79 , struct V_44 * * V_59 )
{
struct V_44 * V_80 = V_58 -> V_80 ;
union {
struct V_81 V_82 ;
} * args = V_78 ;
struct V_3 * V_4 = V_3 ( V_7 ) ;
int V_38 = - V_61 ;
F_39 ( V_80 , L_2 , V_79 ) ;
if ( ! ( V_38 = F_40 ( V_38 , & V_78 , & V_79 , args -> V_82 , 0 , 0 , false ) ) ) {
F_39 ( V_80 , L_3
L_4 ,
args -> V_82 . V_83 , args -> V_82 . V_45 , args -> V_82 . V_55 ,
args -> V_82 . V_56 , args -> V_82 . V_64 ) ;
return F_29 ( V_84 , V_4 ,
& args -> V_82 . V_64 ,
& args -> V_82 . V_14 ,
args -> V_82 . V_45 ,
args -> V_82 . V_55 ,
args -> V_82 . V_56 ,
V_58 , V_59 ) ;
}
return V_38 ;
}
