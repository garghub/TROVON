static int
F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_5 * V_6 = & V_4 -> V_7 . V_8 . V_6 ;
struct V_9 * V_10 = V_6 -> V_10 ;
struct V_11 * V_12 = V_2 -> V_7 . V_13 . V_12 ;
int V_14 = 0 ;
F_2 ( & V_6 -> V_15 ) ;
F_3 ( V_10 , 0x002634 , V_2 -> V_7 . V_16 ) ;
if ( F_4 (device, 2000 ,
if (!(nvkm_rd32(device, 0x002634) & 0x00100000))
break;
) < 0 ) {
F_5 ( V_6 , L_1 ,
V_2 -> V_7 . V_16 , V_12 -> V_17 ) ;
F_6 ( & V_4 -> V_7 , V_2 -> V_7 . V_16 ) ;
V_14 = - V_18 ;
}
F_7 ( & V_6 -> V_15 ) ;
return V_14 ;
}
static T_1
F_8 ( struct V_19 * V_8 )
{
switch ( V_8 -> V_6 . V_20 ) {
case V_21 :
case V_22 :
case V_23 :
case V_24 : return 0x0000 ;
case V_25 : return 0x0210 ;
case V_26 : return 0x0220 ;
case V_27 : return 0x0250 ;
case V_28 : return 0x0260 ;
case V_29 : return 0x0270 ;
case V_30 : return 0x0280 ;
case V_31 : return 0x0290 ;
case V_32 : return 0x02100270 ;
case V_33 : return 0x02100290 ;
case V_34 : return 0x0210 ;
default:
F_9 ( 1 ) ;
return 0 ;
}
}
static int
F_10 ( struct V_35 * V_7 ,
struct V_19 * V_8 , bool V_36 )
{
struct V_1 * V_2 = V_1 ( V_7 ) ;
struct V_37 * V_38 = V_2 -> V_7 . V_38 ;
T_1 V_39 = F_8 ( V_8 ) ;
int V_14 ;
V_14 = F_1 ( V_2 ) ;
if ( V_14 && V_36 )
return V_14 ;
if ( V_39 ) {
F_11 ( V_38 ) ;
F_12 ( V_38 , ( V_39 & 0xffff ) + 0x00 , 0x00000000 ) ;
F_12 ( V_38 , ( V_39 & 0xffff ) + 0x04 , 0x00000000 ) ;
if ( ( V_39 >>= 16 ) ) {
F_12 ( V_38 , V_39 + 0x00 , 0x00000000 ) ;
F_12 ( V_38 , V_39 + 0x04 , 0x00000000 ) ;
}
F_13 ( V_38 ) ;
}
return V_14 ;
}
static int
F_14 ( struct V_35 * V_7 ,
struct V_19 * V_8 )
{
struct V_1 * V_2 = V_1 ( V_7 ) ;
struct V_37 * V_38 = V_2 -> V_7 . V_38 ;
T_1 V_39 = F_8 ( V_8 ) ;
if ( V_39 ) {
T_2 V_40 = V_2 -> V_41 [ V_8 -> V_6 . V_20 ] . V_42 . V_39 ;
T_1 V_43 = F_15 ( V_40 ) | 0x00000004 ;
T_1 V_44 = F_16 ( V_40 ) ;
F_11 ( V_38 ) ;
F_12 ( V_38 , ( V_39 & 0xffff ) + 0x00 , V_43 ) ;
F_12 ( V_38 , ( V_39 & 0xffff ) + 0x04 , V_44 ) ;
if ( ( V_39 >>= 16 ) ) {
F_12 ( V_38 , V_39 + 0x00 , V_43 ) ;
F_12 ( V_38 , V_39 + 0x04 , V_44 ) ;
}
F_13 ( V_38 ) ;
}
return 0 ;
}
static void
F_17 ( struct V_35 * V_7 ,
struct V_19 * V_8 )
{
struct V_1 * V_2 = V_1 ( V_7 ) ;
F_18 ( & V_2 -> V_41 [ V_8 -> V_6 . V_20 ] . V_42 ) ;
F_19 ( & V_2 -> V_41 [ V_8 -> V_6 . V_20 ] . V_38 ) ;
}
static int
F_20 ( struct V_35 * V_7 ,
struct V_19 * V_8 ,
struct V_45 * V_13 )
{
struct V_1 * V_2 = V_1 ( V_7 ) ;
int V_41 = V_8 -> V_6 . V_20 ;
int V_14 ;
if ( ! F_8 ( V_8 ) )
return 0 ;
V_14 = F_21 ( V_13 , NULL , 0 , & V_2 -> V_41 [ V_41 ] . V_38 ) ;
if ( V_14 )
return V_14 ;
return F_22 ( V_2 -> V_41 [ V_41 ] . V_38 , V_2 -> V_46 ,
V_47 , & V_2 -> V_41 [ V_41 ] . V_42 ) ;
}
static void
F_23 ( struct V_35 * V_7 )
{
struct V_1 * V_2 = V_1 ( V_7 ) ;
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_9 * V_10 = V_4 -> V_7 . V_8 . V_6 . V_10 ;
T_1 V_48 = V_2 -> V_7 . V_16 * 8 ;
if ( ! F_24 ( & V_2 -> V_49 ) ) {
F_25 ( V_4 , V_2 ) ;
F_26 ( V_10 , 0x800004 + V_48 , 0x00000800 , 0x00000800 ) ;
F_1 ( V_2 ) ;
F_27 ( V_4 , V_2 -> V_50 ) ;
}
F_3 ( V_10 , 0x800000 + V_48 , 0x00000000 ) ;
}
static void
F_28 ( struct V_35 * V_7 )
{
struct V_1 * V_2 = V_1 ( V_7 ) ;
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_9 * V_10 = V_4 -> V_7 . V_8 . V_6 . V_10 ;
T_1 V_40 = V_2 -> V_7 . V_38 -> V_40 >> 12 ;
T_1 V_48 = V_2 -> V_7 . V_16 * 8 ;
F_26 ( V_10 , 0x800004 + V_48 , 0x000f0000 , V_2 -> V_50 << 16 ) ;
F_3 ( V_10 , 0x800000 + V_48 , 0x80000000 | V_40 ) ;
if ( F_24 ( & V_2 -> V_49 ) && ! V_2 -> V_51 ) {
F_29 ( V_4 , V_2 ) ;
F_26 ( V_10 , 0x800004 + V_48 , 0x00000400 , 0x00000400 ) ;
F_27 ( V_4 , V_2 -> V_50 ) ;
F_26 ( V_10 , 0x800004 + V_48 , 0x00000400 , 0x00000400 ) ;
}
}
static void *
F_30 ( struct V_35 * V_7 )
{
struct V_1 * V_2 = V_1 ( V_7 ) ;
F_31 ( NULL , & V_2 -> V_46 , V_2 -> V_52 ) ;
F_19 ( & V_2 -> V_52 ) ;
return V_2 ;
}
static int
F_32 ( const struct V_53 * V_54 ,
struct V_3 * V_4 , T_1 * V_55 , T_3 * V_16 ,
T_2 V_46 , T_2 V_56 , T_2 V_57 ,
const struct V_58 * V_59 ,
struct V_45 * * V_60 )
{
struct V_9 * V_10 = V_4 -> V_7 . V_8 . V_6 . V_10 ;
struct V_1 * V_2 ;
int V_61 = - 1 , V_14 = - V_62 , V_63 , V_64 ;
T_1 V_65 = 0 , V_66 = 0 ;
T_2 V_67 = 0 ;
T_2 V_68 ;
for ( V_63 = 0 ; V_63 < V_4 -> V_69 ; V_63 ++ ) {
struct V_19 * V_8 = V_4 -> V_8 [ V_63 ] . V_8 ;
if ( V_8 ) {
T_2 V_70 = F_33 ( V_8 -> V_6 . V_20 ) ;
for ( V_64 = 0 ; V_54 [ V_64 ] . V_6 ; V_64 ++ ) {
if ( V_54 [ V_64 ] . V_6 & V_70 ) {
V_66 |= V_54 [ V_64 ] . V_8 ;
break;
}
}
if ( ! V_54 [ V_64 ] . V_6 )
continue;
if ( V_61 < 0 && ( * V_55 & V_66 ) )
V_61 = V_4 -> V_8 [ V_63 ] . V_50 ;
if ( V_61 == V_4 -> V_8 [ V_63 ] . V_50 ) {
V_65 |= V_54 [ V_64 ] . V_8 ;
V_67 |= V_54 [ V_64 ] . V_6 ;
}
}
}
if ( ! * V_55 ) {
* V_55 = V_66 ;
return F_34 ( V_59 , NULL , 0 , V_60 ) ;
}
* V_55 = V_66 ;
if ( V_61 < 0 )
return - V_71 ;
* V_55 = V_65 ;
if ( ! ( V_2 = F_35 ( sizeof( * V_2 ) , V_72 ) ) )
return - V_73 ;
* V_60 = & V_2 -> V_7 . V_13 ;
V_2 -> V_4 = V_4 ;
V_2 -> V_50 = V_61 ;
F_36 ( & V_2 -> V_49 ) ;
V_14 = F_37 ( & V_74 , & V_4 -> V_7 ,
0x1000 , 0x1000 , true , V_46 , 0 , V_67 ,
1 , V_4 -> V_75 . V_76 . V_39 , 0x200 ,
V_59 , & V_2 -> V_7 ) ;
if ( V_14 )
return V_14 ;
* V_16 = V_2 -> V_7 . V_16 ;
V_14 = F_38 ( V_10 , 0x10000 , 0x1000 , false , NULL , & V_2 -> V_52 ) ;
if ( V_14 )
return V_14 ;
F_11 ( V_2 -> V_7 . V_38 ) ;
F_12 ( V_2 -> V_7 . V_38 , 0x0200 , F_15 ( V_2 -> V_52 -> V_40 ) ) ;
F_12 ( V_2 -> V_7 . V_38 , 0x0204 , F_16 ( V_2 -> V_52 -> V_40 ) ) ;
F_12 ( V_2 -> V_7 . V_38 , 0x0208 , 0xffffffff ) ;
F_12 ( V_2 -> V_7 . V_38 , 0x020c , 0x000000ff ) ;
F_13 ( V_2 -> V_7 . V_38 ) ;
V_14 = F_31 ( V_2 -> V_7 . V_46 , & V_2 -> V_46 , V_2 -> V_52 ) ;
if ( V_14 )
return V_14 ;
V_68 = V_2 -> V_7 . V_16 * 0x200 ;
V_57 = F_39 ( V_57 / 8 ) ;
F_11 ( V_4 -> V_75 . V_77 ) ;
for ( V_63 = 0 ; V_63 < 0x200 ; V_63 += 4 )
F_12 ( V_4 -> V_75 . V_77 , V_68 + V_63 , 0x00000000 ) ;
F_13 ( V_4 -> V_75 . V_77 ) ;
V_68 = F_40 ( V_4 -> V_75 . V_77 ) + V_68 ;
F_11 ( V_2 -> V_7 . V_38 ) ;
F_12 ( V_2 -> V_7 . V_38 , 0x08 , F_15 ( V_68 ) ) ;
F_12 ( V_2 -> V_7 . V_38 , 0x0c , F_16 ( V_68 ) ) ;
F_12 ( V_2 -> V_7 . V_38 , 0x10 , 0x0000face ) ;
F_12 ( V_2 -> V_7 . V_38 , 0x30 , 0xfffff902 ) ;
F_12 ( V_2 -> V_7 . V_38 , 0x48 , F_15 ( V_56 ) ) ;
F_12 ( V_2 -> V_7 . V_38 , 0x4c , F_16 ( V_56 ) |
( V_57 << 16 ) ) ;
F_12 ( V_2 -> V_7 . V_38 , 0x84 , 0x20400000 ) ;
F_12 ( V_2 -> V_7 . V_38 , 0x94 , 0x30000001 ) ;
F_12 ( V_2 -> V_7 . V_38 , 0x9c , 0x00000100 ) ;
F_12 ( V_2 -> V_7 . V_38 , 0xac , 0x0000001f ) ;
F_12 ( V_2 -> V_7 . V_38 , 0xe8 , V_2 -> V_7 . V_16 ) ;
F_12 ( V_2 -> V_7 . V_38 , 0xb8 , 0xf8000000 ) ;
F_12 ( V_2 -> V_7 . V_38 , 0xf8 , 0x10003080 ) ;
F_12 ( V_2 -> V_7 . V_38 , 0xfc , 0x10000010 ) ;
F_13 ( V_2 -> V_7 . V_38 ) ;
return 0 ;
}
int
F_41 ( struct V_78 * V_7 , const struct V_58 * V_59 ,
void * V_79 , T_1 V_80 , struct V_45 * * V_60 )
{
struct V_45 * V_81 = V_59 -> V_81 ;
union {
struct V_82 V_83 ;
} * args = V_79 ;
struct V_3 * V_4 = V_3 ( V_7 ) ;
int V_14 = - V_62 ;
F_42 ( V_81 , L_2 , V_80 ) ;
if ( ! ( V_14 = F_43 ( V_14 , & V_79 , & V_80 , args -> V_83 , 0 , 0 , false ) ) ) {
F_42 ( V_81 , L_3
L_4 ,
args -> V_83 . V_84 , args -> V_83 . V_46 , args -> V_83 . V_56 ,
args -> V_83 . V_57 , args -> V_83 . V_65 ) ;
return F_32 ( V_85 , V_4 ,
& args -> V_83 . V_65 ,
& args -> V_83 . V_16 ,
args -> V_83 . V_46 ,
args -> V_83 . V_56 ,
args -> V_83 . V_57 ,
V_59 , V_60 ) ;
}
return V_14 ;
}
