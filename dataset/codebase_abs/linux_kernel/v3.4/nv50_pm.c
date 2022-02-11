static T_1
F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
switch ( V_4 -> V_6 ) {
case 0x50 :
case 0x84 :
case 0x86 :
case 0x98 :
case 0xa0 :
return F_2 ( V_2 , 0x004700 ) ;
case 0x92 :
case 0x94 :
case 0x96 :
return F_2 ( V_2 , 0x004800 ) ;
default:
return 0x00000000 ;
}
}
static T_1
F_3 ( struct V_1 * V_2 , T_1 V_7 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_1 V_8 , V_9 = F_4 ( V_2 , V_10 ) ;
T_1 V_11 = F_2 ( V_2 , 0x00e18c ) ;
int V_12 , V_13 , V_14 , V_15 ;
switch ( V_4 -> V_6 ) {
case 0x50 :
case 0xa0 :
switch ( V_7 ) {
case 0x4020 :
case 0x4028 : V_15 = ! ! ( V_11 & 0x00000004 ) ; break;
case 0x4008 : V_15 = ! ! ( V_11 & 0x00000008 ) ; break;
case 0x4030 : V_15 = 0 ; break;
default:
F_5 ( V_2 , L_1 , V_7 ) ;
return 0 ;
}
V_8 = F_2 ( V_2 , 0x00e81c + ( V_15 * 0x0c ) ) ;
V_9 *= ( V_8 & 0x01000000 ) ? 2 : 4 ;
V_12 = ( V_8 & 0x00070000 ) >> 16 ;
V_13 = ( ( V_8 & 0x0000ff00 ) >> 8 ) + 1 ;
V_14 = ( ( V_8 & 0x000000ff ) >> 0 ) + 1 ;
break;
case 0x84 :
case 0x86 :
case 0x92 :
V_8 = F_2 ( V_2 , 0x00e81c ) ;
V_12 = ( V_8 & 0x00070000 ) >> 16 ;
V_13 = ( V_8 & 0x0000ff00 ) >> 8 ;
V_14 = ( V_8 & 0x000000ff ) >> 0 ;
break;
case 0x94 :
case 0x96 :
case 0x98 :
V_11 = F_2 ( V_2 , 0x00c050 ) ;
switch ( V_7 ) {
case 0x4020 : V_11 = ( V_11 & 0x00000003 ) >> 0 ; break;
case 0x4008 : V_11 = ( V_11 & 0x0000000c ) >> 2 ; break;
case 0x4028 : V_11 = ( V_11 & 0x00001800 ) >> 11 ; break;
case 0x4030 : V_11 = 3 ; break;
default:
F_5 ( V_2 , L_1 , V_7 ) ;
return 0 ;
}
switch ( V_11 ) {
case 0 : V_15 = 1 ; break;
case 1 : return F_4 ( V_2 , V_10 ) ;
case 2 : return F_4 ( V_2 , V_16 ) ;
case 3 : V_15 = 0 ; break;
}
V_8 = F_2 ( V_2 , 0x00e81c + ( V_15 * 0x28 ) ) ;
V_12 = ( F_2 ( V_2 , 0x00e824 + ( V_15 * 0x28 ) ) >> 16 ) & 7 ;
V_12 += ( V_8 & 0x00070000 ) >> 16 ;
V_13 = ( V_8 & 0x0000ff00 ) >> 8 ;
V_14 = ( V_8 & 0x000000ff ) >> 0 ;
break;
default:
F_6 ( 1 ) ;
}
if ( V_14 )
return ( V_9 * V_13 / V_14 ) >> V_12 ;
return 0 ;
}
static T_1
F_7 ( struct V_1 * V_2 , T_1 V_7 )
{
T_1 V_17 , V_18 = F_2 ( V_2 , 0x00c040 ) ;
switch ( V_7 ) {
case 0x004028 :
V_17 = ! ! ( V_18 & 0x00200000 ) ;
break;
case 0x004020 :
V_17 = ! ! ( V_18 & 0x00400000 ) ;
break;
case 0x004008 :
V_17 = ! ! ( V_18 & 0x00010000 ) ;
break;
case 0x004030 :
V_17 = ! ! ( V_18 & 0x02000000 ) ;
break;
case 0x00e810 :
return F_4 ( V_2 , V_10 ) ;
default:
F_5 ( V_2 , L_2 , V_7 ) ;
return 0 ;
}
if ( V_17 )
return F_4 ( V_2 , V_16 ) ;
return F_3 ( V_2 , V_7 ) ;
}
static T_1
F_8 ( struct V_1 * V_2 , T_1 V_7 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_1 V_18 = F_2 ( V_2 , 0x00c040 ) ;
T_1 V_19 = F_2 ( V_2 , V_7 + 0 ) ;
T_1 V_8 = F_2 ( V_2 , V_7 + 4 ) ;
T_1 V_9 = F_7 ( V_2 , V_7 ) ;
T_1 V_20 = 0 ;
int V_21 , V_22 , V_23 , V_24 ;
if ( V_7 == 0x004028 && ( V_18 & 0x00100000 ) ) {
if ( V_4 -> V_6 != 0xa0 )
return F_4 ( V_2 , V_25 ) ;
}
V_22 = ( V_8 & 0xff000000 ) >> 24 ;
V_24 = ( V_8 & 0x00ff0000 ) >> 16 ;
V_21 = ( V_8 & 0x0000ff00 ) >> 8 ;
V_23 = ( V_8 & 0x000000ff ) ;
if ( ( V_19 & 0x80000000 ) && V_23 ) {
V_20 = V_9 * V_21 / V_23 ;
if ( ( V_19 & 0x40000100 ) == 0x40000000 ) {
if ( V_24 )
V_20 = V_20 * V_22 / V_24 ;
else
V_20 = 0 ;
}
}
return V_20 ;
}
static T_1
F_4 ( struct V_1 * V_2 , enum V_26 V_17 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_1 V_18 = F_2 ( V_2 , 0x00c040 ) ;
T_1 V_12 = 0 ;
switch ( V_17 ) {
case V_10 :
return V_4 -> V_27 ;
case V_16 :
return 100000 ;
case V_28 :
return F_4 ( V_2 , V_16 ) * 27778 / 10000 ;
case V_29 :
return F_4 ( V_2 , V_28 ) * 3 ;
case V_30 :
return F_4 ( V_2 , V_28 ) * 3 / 2 ;
case V_31 :
switch ( V_18 & 0x30000000 ) {
case 0x00000000 : return F_4 ( V_2 , V_16 ) ;
case 0x10000000 : break;
case 0x20000000 :
case 0x30000000 : return F_4 ( V_2 , V_28 ) ;
}
break;
case V_32 :
if ( ! ( V_18 & 0x00100000 ) )
V_12 = ( F_2 ( V_2 , 0x004028 ) & 0x00070000 ) >> 16 ;
switch ( V_18 & 0x00000003 ) {
case 0x00000000 : return F_4 ( V_2 , V_10 ) >> V_12 ;
case 0x00000001 : return F_4 ( V_2 , V_25 ) ;
case 0x00000002 : return F_8 ( V_2 , 0x004020 ) >> V_12 ;
case 0x00000003 : return F_8 ( V_2 , 0x004028 ) >> V_12 ;
}
break;
case V_33 :
V_12 = ( F_2 ( V_2 , 0x004020 ) & 0x00070000 ) >> 16 ;
switch ( V_18 & 0x00000030 ) {
case 0x00000000 :
if ( V_18 & 0x00000080 )
return F_4 ( V_2 , V_31 ) >> V_12 ;
return F_4 ( V_2 , V_10 ) >> V_12 ;
case 0x00000010 : break;
case 0x00000020 : return F_8 ( V_2 , 0x004028 ) >> V_12 ;
case 0x00000030 : return F_8 ( V_2 , 0x004020 ) >> V_12 ;
}
break;
case V_34 :
V_12 = ( F_2 ( V_2 , 0x004008 ) & 0x00070000 ) >> 16 ;
if ( F_2 ( V_2 , 0x004008 ) & 0x00000200 ) {
switch ( V_18 & 0x0000c000 ) {
case 0x00000000 :
return F_4 ( V_2 , V_10 ) >> V_12 ;
case 0x00008000 :
case 0x0000c000 :
return F_4 ( V_2 , V_16 ) >> V_12 ;
}
} else {
return F_8 ( V_2 , 0x004008 ) >> V_12 ;
}
break;
case V_35 :
V_12 = ( F_1 ( V_2 ) & 0x00000700 ) >> 8 ;
switch ( V_4 -> V_6 ) {
case 0x84 :
case 0x86 :
case 0x92 :
case 0x94 :
case 0x96 :
case 0xa0 :
switch ( V_18 & 0x00000c00 ) {
case 0x00000000 :
if ( V_4 -> V_6 == 0xa0 )
return F_4 ( V_2 , V_32 ) >> V_12 ;
return F_4 ( V_2 , V_10 ) >> V_12 ;
case 0x00000400 :
return 0 ;
case 0x00000800 :
if ( V_18 & 0x01000000 )
return F_8 ( V_2 , 0x004028 ) >> V_12 ;
return F_8 ( V_2 , 0x004030 ) >> V_12 ;
case 0x00000c00 :
return F_4 ( V_2 , V_32 ) >> V_12 ;
}
break;
case 0x98 :
switch ( V_18 & 0x00000c00 ) {
case 0x00000000 :
return F_4 ( V_2 , V_32 ) >> V_12 ;
case 0x00000400 :
return 0 ;
case 0x00000800 :
return F_4 ( V_2 , V_30 ) >> V_12 ;
case 0x00000c00 :
return F_4 ( V_2 , V_34 ) >> V_12 ;
}
break;
}
break;
case V_25 :
switch ( V_4 -> V_6 ) {
case 0x50 :
case 0xa0 :
return F_8 ( V_2 , 0x00e810 ) >> 2 ;
case 0x84 :
case 0x86 :
case 0x92 :
case 0x94 :
case 0x96 :
case 0x98 :
V_12 = ( F_1 ( V_2 ) & 0x00000007 ) >> 0 ;
switch ( V_18 & 0x0c000000 ) {
case 0x00000000 : return F_4 ( V_2 , V_16 ) ;
case 0x04000000 : break;
case 0x08000000 : return F_4 ( V_2 , V_28 ) ;
case 0x0c000000 :
return F_4 ( V_2 , V_29 ) >> V_12 ;
}
break;
default:
break;
}
default:
break;
}
F_9 ( V_2 , L_3 , V_17 , V_18 ) ;
return 0 ;
}
int
F_10 ( struct V_1 * V_2 , struct V_36 * V_37 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
if ( V_4 -> V_6 == 0xaa ||
V_4 -> V_6 == 0xac )
return 0 ;
V_37 -> V_38 = F_4 ( V_2 , V_32 ) ;
V_37 -> V_39 = F_4 ( V_2 , V_33 ) ;
V_37 -> V_40 = F_4 ( V_2 , V_34 ) ;
if ( V_4 -> V_6 != 0x50 ) {
V_37 -> V_41 = F_4 ( V_2 , V_35 ) ;
V_37 -> V_42 = F_4 ( V_2 , V_25 ) ;
}
return 0 ;
}
static T_1
F_11 ( struct V_1 * V_2 , T_1 V_43 , struct V_44 * V_45 ,
T_1 V_20 , int * V_21 , int * V_23 , int * V_46 )
{
struct V_47 V_8 ;
int V_48 ;
V_48 = F_12 ( V_2 , V_43 , V_45 ) ;
if ( V_48 )
return 0 ;
V_45 -> V_49 . V_50 = 0 ;
V_45 -> V_51 = F_7 ( V_2 , V_43 ) ;
if ( ! V_45 -> V_51 )
return 0 ;
V_48 = F_13 ( V_2 , V_45 , V_20 , & V_8 ) ;
if ( V_48 == 0 )
return 0 ;
* V_21 = V_8 . V_21 ;
* V_23 = V_8 . V_23 ;
* V_46 = V_8 . V_46 ;
return V_48 ;
}
static inline T_1
F_14 ( T_1 V_17 , T_1 V_52 , int * div )
{
T_1 V_53 = V_17 , V_54 = V_17 ;
for ( * div = 0 ; * div <= 7 ; ( * div ) ++ ) {
if ( V_53 <= V_52 ) {
V_54 = V_53 << ( * div ? 1 : 0 ) ;
break;
}
V_53 >>= 1 ;
}
if ( V_52 - V_53 <= V_54 - V_52 )
return V_53 ;
( * div ) -- ;
return V_54 ;
}
static inline T_1
F_15 ( T_1 V_55 , T_1 V_56 )
{
return ( ( V_55 / 1000 ) == ( V_56 / 1000 ) ) ;
}
static void
F_16 ( struct V_57 * V_58 )
{
struct V_59 * V_60 = V_58 -> V_61 ;
struct V_62 * V_63 = & V_60 -> V_64 ;
F_17 ( V_63 , 0x1002d4 , 0x00000001 ) ;
}
static void
F_18 ( struct V_57 * V_58 )
{
struct V_59 * V_60 = V_58 -> V_61 ;
struct V_62 * V_63 = & V_60 -> V_64 ;
F_17 ( V_63 , 0x1002d0 , 0x00000001 ) ;
}
static void
F_19 ( struct V_57 * V_58 , bool V_65 )
{
struct V_59 * V_60 = V_58 -> V_61 ;
struct V_62 * V_63 = & V_60 -> V_64 ;
F_17 ( V_63 , 0x100210 , V_65 ? 0x80000000 : 0x00000000 ) ;
}
static void
F_20 ( struct V_57 * V_58 , bool V_65 )
{
struct V_59 * V_60 = V_58 -> V_61 ;
struct V_62 * V_63 = & V_60 -> V_64 ;
F_17 ( V_63 , 0x1002dc , V_65 ? 0x00000001 : 0x00000000 ) ;
}
static void
F_21 ( struct V_57 * V_58 , T_1 V_66 )
{
struct V_59 * V_60 = V_58 -> V_61 ;
struct V_62 * V_63 = & V_60 -> V_64 ;
if ( V_66 > 1000 )
F_22 ( V_63 , ( V_66 + 500 ) / 1000 ) ;
}
static T_1
F_23 ( struct V_57 * V_58 , int V_67 )
{
if ( V_67 <= 1 )
return F_2 ( V_58 -> V_2 , 0x1002c0 + ( ( V_67 - 0 ) * 4 ) ) ;
if ( V_67 <= 3 )
return F_2 ( V_58 -> V_2 , 0x1002e0 + ( ( V_67 - 2 ) * 4 ) ) ;
return 0 ;
}
static void
F_24 ( struct V_57 * V_58 , int V_67 , T_1 V_68 )
{
struct V_3 * V_4 = V_58 -> V_2 -> V_5 ;
struct V_59 * V_60 = V_58 -> V_61 ;
struct V_62 * V_63 = & V_60 -> V_64 ;
if ( V_67 <= 1 ) {
if ( V_4 -> V_69 )
F_17 ( V_63 , 0x1002c8 + ( ( V_67 - 0 ) * 4 ) , V_68 ) ;
F_17 ( V_63 , 0x1002c0 + ( ( V_67 - 0 ) * 4 ) , V_68 ) ;
} else
if ( V_67 <= 3 ) {
if ( V_4 -> V_69 )
F_17 ( V_63 , 0x1002e8 + ( ( V_67 - 2 ) * 4 ) , V_68 ) ;
F_17 ( V_63 , 0x1002e0 + ( ( V_67 - 2 ) * 4 ) , V_68 ) ;
}
}
static void
F_25 ( struct V_57 * V_58 )
{
struct V_59 * V_60 = V_58 -> V_61 ;
struct V_62 * V_63 = & V_60 -> V_64 ;
T_1 V_19 = F_2 ( V_58 -> V_2 , 0x004008 ) ;
V_60 -> V_70 = F_2 ( V_58 -> V_2 , 0x00c040 ) ;
V_60 -> V_70 &= ~ 0xc0000000 ;
V_60 -> V_70 |= 0x0000c000 ;
F_17 ( V_63 , 0xc040 , V_60 -> V_70 ) ;
F_17 ( V_63 , 0x4008 , V_19 | 0x00000200 ) ;
if ( V_60 -> V_71 & 0x80000000 )
F_17 ( V_63 , 0x400c , V_60 -> V_72 ) ;
F_17 ( V_63 , 0x4008 , V_60 -> V_71 ) ;
}
static void
F_26 ( struct V_57 * V_58 )
{
struct V_1 * V_2 = V_58 -> V_2 ;
struct V_59 * V_60 = V_58 -> V_61 ;
struct V_36 * V_37 = V_60 -> V_37 ;
struct V_62 * V_63 = & V_60 -> V_64 ;
int V_73 ;
for ( V_73 = 0 ; V_73 < 9 ; V_73 ++ ) {
T_1 V_43 = 0x100220 + ( V_73 * 4 ) ;
T_1 V_74 = F_2 ( V_2 , V_43 ) ;
if ( V_74 != V_37 -> V_75 . V_43 [ V_73 ] )
F_17 ( V_63 , V_43 , V_37 -> V_75 . V_43 [ V_73 ] ) ;
}
}
static int
F_27 ( struct V_1 * V_2 , struct V_36 * V_37 ,
struct V_59 * V_60 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_1 V_76 = F_28 ( V_2 ) ;
struct V_57 V_58 = {
. V_2 = V_2 ,
. V_77 = F_16 ,
. V_78 = F_18 ,
. V_79 = F_19 ,
. V_80 = F_20 ,
. V_81 = F_21 ,
. V_82 = F_23 ,
. V_83 = F_24 ,
. V_84 = F_25 ,
. V_85 = F_26 ,
. V_61 = V_60
} ;
struct V_62 * V_63 = & V_60 -> V_64 ;
struct V_44 V_45 ;
int V_13 , V_14 , V_12 ;
int V_48 ;
V_60 -> V_71 = F_2 ( V_2 , 0x004008 ) ;
V_60 -> V_71 &= ~ 0x81ff0200 ;
if ( F_15 ( V_37 -> V_40 , F_4 ( V_2 , V_16 ) ) ) {
V_60 -> V_71 |= 0x00000200 | ( V_45 . V_86 << 19 ) ;
} else {
V_48 = F_11 ( V_2 , 0x4008 , & V_45 , V_37 -> V_40 , & V_13 , & V_14 , & V_12 ) ;
if ( V_48 == 0 )
return - V_87 ;
V_60 -> V_71 |= 0x80000000 | ( V_12 << 22 ) | ( V_12 << 16 ) ;
V_60 -> V_71 |= V_45 . V_86 << 19 ;
V_60 -> V_72 = ( V_13 << 8 ) | V_14 ;
}
F_29 ( V_63 ) ;
if ( V_76 ) {
F_30 ( V_63 , V_76 , 0x00 ) ;
F_30 ( V_63 , V_76 , 0x01 ) ;
}
if ( V_4 -> V_6 >= 0x92 )
F_17 ( V_63 , 0x611200 , 0x00003300 ) ;
F_31 ( V_63 , 0x10 , 0 ) ;
F_30 ( V_63 , 0x00 , 0x01 ) ;
V_48 = F_32 ( & V_58 , V_37 ) ;
if ( V_48 )
return V_48 ;
F_31 ( V_63 , 0x10 , 1 ) ;
F_30 ( V_63 , 0x00 , 0x00 ) ;
if ( V_4 -> V_6 >= 0x92 )
F_17 ( V_63 , 0x611200 , 0x00003330 ) ;
F_33 ( V_63 ) ;
return 0 ;
}
void *
F_34 ( struct V_1 * V_2 , struct V_36 * V_37 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_59 * V_60 ;
struct V_62 * V_63 ;
struct V_44 V_45 ;
T_1 V_88 , V_18 , V_89 , V_19 ;
int V_20 , V_48 = - V_87 ;
int V_13 , V_14 , V_90 , V_91 ;
if ( V_4 -> V_6 == 0xaa ||
V_4 -> V_6 == 0xac )
return F_35 ( - V_92 ) ;
V_60 = F_36 ( sizeof( * V_60 ) , V_93 ) ;
if ( ! V_60 )
return F_35 ( - V_94 ) ;
V_60 -> V_37 = V_37 ;
V_60 -> V_64 . V_95 = 0 ;
if ( V_37 -> V_40 ) {
V_48 = F_27 ( V_2 , V_37 , V_60 ) ;
if ( V_48 )
goto error;
V_60 -> V_96 = V_37 -> V_97 ;
}
V_89 = F_1 ( V_2 ) ;
V_18 = V_60 -> V_70 ;
V_63 = & V_60 -> V_98 ;
F_29 ( V_63 ) ;
F_31 ( V_63 , 0x10 , 0 ) ;
F_30 ( V_63 , 0x00 , 0x01 ) ;
if ( V_37 -> V_41 ) {
V_18 &= ~ 0x00000c00 ;
V_89 &= ~ 0x00000700 ;
}
if ( V_37 -> V_42 ) {
V_18 &= ~ 0x0c000000 ;
V_89 &= ~ 0x00000007 ;
}
F_17 ( V_63 , 0x00c040 , V_18 ) ;
if ( V_37 -> V_41 ) {
V_20 = F_14 ( V_37 -> V_38 , V_37 -> V_41 , & V_90 ) ;
if ( V_4 -> V_6 != 0x98 )
V_88 = F_8 ( V_2 , 0x004030 ) ;
else
V_88 = F_4 ( V_2 , V_30 ) ;
V_88 = F_14 ( V_88 , V_37 -> V_41 , & V_91 ) ;
if ( abs ( ( int ) V_37 -> V_41 - V_20 ) <=
abs ( ( int ) V_37 -> V_41 - V_88 ) ) {
if ( V_4 -> V_6 != 0x98 )
V_18 |= 0x00000c00 ;
V_89 |= V_90 << 8 ;
} else {
V_18 |= 0x00000800 ;
V_89 |= V_91 << 8 ;
}
}
if ( V_37 -> V_42 ) {
if ( F_15 ( V_37 -> V_42 , F_4 ( V_2 , V_16 ) ) ) {
V_18 |= 0x00000000 ;
} else
if ( F_15 ( V_37 -> V_42 , F_4 ( V_2 , V_28 ) ) ) {
V_18 |= 0x08000000 ;
} else {
V_20 = F_4 ( V_2 , V_28 ) * 3 ;
V_20 = F_14 ( V_20 , V_37 -> V_42 , & V_90 ) ;
V_18 |= 0x0c000000 ;
V_89 |= V_90 ;
}
}
switch ( V_4 -> V_6 ) {
case 0x92 :
case 0x94 :
case 0x96 :
F_17 ( V_63 , 0x004800 , V_89 ) ;
break;
default:
F_17 ( V_63 , 0x004700 , V_89 ) ;
break;
}
F_17 ( V_63 , 0x00c040 , V_18 ) ;
if ( V_4 -> V_6 < 0x92 )
V_18 = ( V_18 & ~ 0x001000b0 ) | 0x00100080 ;
else
V_18 = ( V_18 & ~ 0x000000b3 ) | 0x00000081 ;
F_17 ( V_63 , 0x00c040 , V_18 ) ;
V_20 = F_11 ( V_2 , 0x4028 , & V_45 , V_37 -> V_38 , & V_13 , & V_14 , & V_90 ) ;
if ( V_20 == 0 )
goto error;
V_19 = F_2 ( V_2 , 0x004028 ) & ~ 0xc03f0100 ;
V_18 &= ~ 0x00100000 ;
V_18 |= 3 ;
F_17 ( V_63 , 0x004028 , 0x80000000 | ( V_90 << 19 ) | ( V_90 << 16 ) | V_19 ) ;
F_17 ( V_63 , 0x00402c , ( V_13 << 8 ) | V_14 ) ;
V_19 = F_2 ( V_2 , 0x004020 ) & ~ 0xc03f0100 ;
if ( V_90 -- && V_37 -> V_39 == ( V_37 -> V_38 << 1 ) ) {
F_17 ( V_63 , 0x004020 , ( V_90 << 19 ) | ( V_90 << 16 ) | V_19 ) ;
F_17 ( V_63 , 0x00c040 , 0x00000020 | V_18 ) ;
} else {
V_20 = F_11 ( V_2 , 0x4020 , & V_45 , V_37 -> V_39 , & V_13 , & V_14 , & V_90 ) ;
if ( V_20 == 0 )
goto error;
V_19 |= 0x80000000 ;
F_17 ( V_63 , 0x004020 , ( V_90 << 19 ) | ( V_90 << 16 ) | V_19 ) ;
F_17 ( V_63 , 0x004024 , ( V_13 << 8 ) | V_14 ) ;
F_17 ( V_63 , 0x00c040 , 0x00000030 | V_18 ) ;
}
F_31 ( V_63 , 0x10 , 1 ) ;
F_30 ( V_63 , 0x00 , 0x00 ) ;
F_33 ( V_63 ) ;
return V_60 ;
error:
F_37 ( V_60 ) ;
return F_35 ( V_48 ) ;
}
static int
F_38 ( struct V_1 * V_2 , struct V_62 * V_63 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_1 V_99 , V_100 ;
int V_73 ;
if ( V_4 -> V_6 < 0x94 ) {
V_99 = 0x001400 ;
V_100 = 0x00000003 ;
} else {
V_99 = 0x080000 ;
V_100 = 0x00000001 ;
}
F_39 ( V_2 , 0x001098 , 0x00000008 , 0x00000000 ) ;
F_40 ( V_2 , 0x001304 , 0x00000000 ) ;
if ( V_4 -> V_6 >= 0x92 )
F_40 ( V_2 , 0x001318 , 0x00000000 ) ;
for ( V_73 = 0 ; V_73 < V_63 -> V_95 / 4 ; V_73 ++ )
F_40 ( V_2 , V_99 + ( V_73 * 4 ) , V_63 -> V_101 . T_1 [ V_73 ] ) ;
F_39 ( V_2 , 0x001098 , 0x00000018 , 0x00000018 ) ;
F_40 ( V_2 , 0x00130c , V_100 ) ;
if ( ! F_41 ( V_2 , 0x001308 , 0x00000100 , 0x00000000 ) ) {
F_5 ( V_2 , L_4 ) ;
F_5 ( V_2 , L_5 , F_2 ( V_2 , 0x001308 ) ) ;
for ( V_73 = 0 ; V_73 < V_63 -> V_95 / 4 ; V_73 ++ ) {
F_5 ( V_2 , L_6 , 0x1400 + ( V_73 * 4 ) ,
F_2 ( V_2 , 0x001400 + ( V_73 * 4 ) ) ) ;
}
return - V_102 ;
}
return 0 ;
}
int
F_42 ( struct V_1 * V_2 , void * V_68 )
{
struct V_59 * V_60 = V_68 ;
struct V_103 V_14 ;
int V_48 = - V_104 ;
F_39 ( V_2 , 0x002504 , 0x00000001 , 0x00000001 ) ;
if ( ! F_41 ( V_2 , 0x002504 , 0x00000010 , 0x00000010 ) )
goto V_105;
if ( ! F_41 ( V_2 , 0x00251c , 0x0000003f , 0x0000003f ) )
goto V_105;
if ( V_60 -> V_64 . V_95 ) {
if ( ! F_43 ( V_2 , 'M' , & V_14 ) && V_14 . V_106 == 1 ) {
if ( V_14 . V_107 >= 6 )
F_44 ( V_2 , F_45 ( V_14 . V_68 [ 5 ] ) ) ;
if ( V_14 . V_107 >= 8 )
F_44 ( V_2 , F_45 ( V_14 . V_68 [ 7 ] ) ) ;
if ( V_14 . V_107 >= 10 )
F_44 ( V_2 , F_45 ( V_14 . V_68 [ 9 ] ) ) ;
F_44 ( V_2 , V_60 -> V_96 ) ;
}
V_48 = F_38 ( V_2 , & V_60 -> V_64 ) ;
if ( V_48 )
goto V_105;
}
V_48 = F_38 ( V_2 , & V_60 -> V_98 ) ;
V_105:
F_39 ( V_2 , 0x002504 , 0x00000001 , 0x00000000 ) ;
F_37 ( V_60 ) ;
return V_48 ;
}
static int
F_46 ( struct V_1 * V_2 , int * line , int * V_19 , int * V_108 )
{
if ( * line == 0x04 ) {
* V_19 = 0x00e100 ;
* line = 4 ;
* V_108 = 0 ;
} else
if ( * line == 0x09 ) {
* V_19 = 0x00e100 ;
* line = 9 ;
* V_108 = 1 ;
} else
if ( * line == 0x10 ) {
* V_19 = 0x00e28c ;
* line = 0 ;
* V_108 = 0 ;
} else {
F_5 ( V_2 , L_7 , * line ) ;
return - V_92 ;
}
return 0 ;
}
int
F_47 ( struct V_1 * V_2 , int line , T_1 * V_89 , T_1 * V_109 )
{
int V_19 , V_15 , V_48 = F_46 ( V_2 , & line , & V_19 , & V_15 ) ;
if ( V_48 )
return V_48 ;
if ( F_2 ( V_2 , V_19 ) & ( 1 << line ) ) {
* V_89 = F_2 ( V_2 , 0x00e114 + ( V_15 * 8 ) ) ;
* V_109 = F_2 ( V_2 , 0x00e118 + ( V_15 * 8 ) ) ;
return 0 ;
}
return - V_87 ;
}
int
F_48 ( struct V_1 * V_2 , int line , T_1 V_89 , T_1 V_109 )
{
int V_19 , V_15 , V_48 = F_46 ( V_2 , & line , & V_19 , & V_15 ) ;
if ( V_48 )
return V_48 ;
F_39 ( V_2 , V_19 , 0x00010001 << line , 0x00000001 << line ) ;
F_40 ( V_2 , 0x00e114 + ( V_15 * 8 ) , V_89 ) ;
F_40 ( V_2 , 0x00e118 + ( V_15 * 8 ) , V_109 | 0x80000000 ) ;
return 0 ;
}
