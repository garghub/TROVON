static T_1
F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 . V_6 . V_4 ;
switch ( V_4 -> V_7 ) {
case 0x50 :
case 0x84 :
case 0x86 :
case 0x98 :
case 0xa0 :
return F_2 ( V_4 , 0x004700 ) ;
case 0x92 :
case 0x94 :
case 0x96 :
return F_2 ( V_4 , 0x004800 ) ;
default:
return 0x00000000 ;
}
}
static T_1
F_3 ( struct V_1 * V_2 , T_1 V_5 )
{
struct V_8 * V_6 = & V_2 -> V_5 . V_6 ;
struct V_3 * V_4 = V_6 -> V_4 ;
T_1 V_9 , V_10 = F_4 ( & V_2 -> V_5 , V_11 ) ;
T_1 V_12 = F_2 ( V_4 , 0x00e18c ) ;
int V_13 , V_14 , V_15 , V_16 ;
switch ( V_4 -> V_7 ) {
case 0x50 :
case 0xa0 :
switch ( V_5 ) {
case 0x4020 :
case 0x4028 : V_16 = ! ! ( V_12 & 0x00000004 ) ; break;
case 0x4008 : V_16 = ! ! ( V_12 & 0x00000008 ) ; break;
case 0x4030 : V_16 = 0 ; break;
default:
F_5 ( V_6 , L_1 , V_5 ) ;
return 0 ;
}
V_9 = F_2 ( V_4 , 0x00e81c + ( V_16 * 0x0c ) ) ;
V_10 *= ( V_9 & 0x01000000 ) ? 2 : 4 ;
V_13 = ( V_9 & 0x00070000 ) >> 16 ;
V_14 = ( ( V_9 & 0x0000ff00 ) >> 8 ) + 1 ;
V_15 = ( ( V_9 & 0x000000ff ) >> 0 ) + 1 ;
break;
case 0x84 :
case 0x86 :
case 0x92 :
V_9 = F_2 ( V_4 , 0x00e81c ) ;
V_13 = ( V_9 & 0x00070000 ) >> 16 ;
V_14 = ( V_9 & 0x0000ff00 ) >> 8 ;
V_15 = ( V_9 & 0x000000ff ) >> 0 ;
break;
case 0x94 :
case 0x96 :
case 0x98 :
V_12 = F_2 ( V_4 , 0x00c050 ) ;
switch ( V_5 ) {
case 0x4020 : V_12 = ( V_12 & 0x00000003 ) >> 0 ; break;
case 0x4008 : V_12 = ( V_12 & 0x0000000c ) >> 2 ; break;
case 0x4028 : V_12 = ( V_12 & 0x00001800 ) >> 11 ; break;
case 0x4030 : V_12 = 3 ; break;
default:
F_5 ( V_6 , L_1 , V_5 ) ;
return 0 ;
}
switch ( V_12 ) {
case 0 : V_16 = 1 ; break;
case 1 : return F_4 ( & V_2 -> V_5 , V_11 ) ;
case 2 : return F_4 ( & V_2 -> V_5 , V_17 ) ;
case 3 : V_16 = 0 ; break;
}
V_9 = F_2 ( V_4 , 0x00e81c + ( V_16 * 0x28 ) ) ;
V_13 = ( F_2 ( V_4 , 0x00e824 + ( V_16 * 0x28 ) ) >> 16 ) & 7 ;
V_13 += ( V_9 & 0x00070000 ) >> 16 ;
V_14 = ( V_9 & 0x0000ff00 ) >> 8 ;
V_15 = ( V_9 & 0x000000ff ) >> 0 ;
break;
default:
F_6 () ;
}
if ( V_15 )
return ( V_10 * V_14 / V_15 ) >> V_13 ;
return 0 ;
}
static T_1
F_7 ( struct V_1 * V_2 , T_1 V_5 )
{
struct V_8 * V_6 = & V_2 -> V_5 . V_6 ;
struct V_3 * V_4 = V_6 -> V_4 ;
T_1 V_18 , V_19 = F_2 ( V_4 , 0x00c040 ) ;
switch ( V_5 ) {
case 0x004028 :
V_18 = ! ! ( V_19 & 0x00200000 ) ;
break;
case 0x004020 :
V_18 = ! ! ( V_19 & 0x00400000 ) ;
break;
case 0x004008 :
V_18 = ! ! ( V_19 & 0x00010000 ) ;
break;
case 0x004030 :
V_18 = ! ! ( V_19 & 0x02000000 ) ;
break;
case 0x00e810 :
return F_4 ( & V_2 -> V_5 , V_11 ) ;
default:
F_5 ( V_6 , L_2 , V_5 ) ;
return 0 ;
}
if ( V_18 )
return F_4 ( & V_2 -> V_5 , V_17 ) ;
return F_3 ( V_2 , V_5 ) ;
}
static T_1
F_8 ( struct V_1 * V_2 , T_1 V_5 )
{
struct V_3 * V_4 = V_2 -> V_5 . V_6 . V_4 ;
T_1 V_19 = F_2 ( V_4 , 0x00c040 ) ;
T_1 V_20 = F_2 ( V_4 , V_5 + 0 ) ;
T_1 V_9 = F_2 ( V_4 , V_5 + 4 ) ;
T_1 V_10 = F_7 ( V_2 , V_5 ) ;
T_1 V_21 = 0 ;
int V_22 , V_23 , V_24 , V_25 ;
if ( V_5 == 0x004028 && ( V_19 & 0x00100000 ) ) {
if ( V_4 -> V_7 != 0xa0 )
return F_4 ( & V_2 -> V_5 , V_26 ) ;
}
V_23 = ( V_9 & 0xff000000 ) >> 24 ;
V_25 = ( V_9 & 0x00ff0000 ) >> 16 ;
V_22 = ( V_9 & 0x0000ff00 ) >> 8 ;
V_24 = ( V_9 & 0x000000ff ) ;
if ( ( V_20 & 0x80000000 ) && V_24 ) {
V_21 = V_10 * V_22 / V_24 ;
if ( ( V_20 & 0x40000100 ) == 0x40000000 ) {
if ( V_25 )
V_21 = V_21 * V_23 / V_25 ;
else
V_21 = 0 ;
}
}
return V_21 ;
}
int
F_9 ( struct V_27 * V_5 , enum V_28 V_18 )
{
struct V_1 * V_2 = V_1 ( V_5 ) ;
struct V_8 * V_6 = & V_2 -> V_5 . V_6 ;
struct V_3 * V_4 = V_6 -> V_4 ;
T_1 V_19 = F_2 ( V_4 , 0x00c040 ) ;
T_1 V_13 = 0 ;
switch ( V_18 ) {
case V_11 :
return V_4 -> V_29 ;
case V_17 :
return 100000 ;
case V_30 :
return F_10 ( ( V_31 ) F_4 ( & V_2 -> V_5 , V_17 ) * 27778 , 10000 ) ;
case V_32 :
return F_4 ( & V_2 -> V_5 , V_30 ) * 3 ;
case V_33 :
return F_4 ( & V_2 -> V_5 , V_30 ) * 3 / 2 ;
case V_34 :
switch ( V_19 & 0x30000000 ) {
case 0x00000000 : return F_4 ( & V_2 -> V_5 , V_17 ) ;
case 0x10000000 : break;
case 0x20000000 :
case 0x30000000 : return F_4 ( & V_2 -> V_5 , V_30 ) ;
}
break;
case V_35 :
if ( ! ( V_19 & 0x00100000 ) )
V_13 = ( F_2 ( V_4 , 0x004028 ) & 0x00070000 ) >> 16 ;
switch ( V_19 & 0x00000003 ) {
case 0x00000000 : return F_4 ( & V_2 -> V_5 , V_11 ) >> V_13 ;
case 0x00000001 : return F_4 ( & V_2 -> V_5 , V_26 ) ;
case 0x00000002 : return F_8 ( V_2 , 0x004020 ) >> V_13 ;
case 0x00000003 : return F_8 ( V_2 , 0x004028 ) >> V_13 ;
}
break;
case V_36 :
V_13 = ( F_2 ( V_4 , 0x004020 ) & 0x00070000 ) >> 16 ;
switch ( V_19 & 0x00000030 ) {
case 0x00000000 :
if ( V_19 & 0x00000080 )
return F_4 ( & V_2 -> V_5 , V_34 ) >> V_13 ;
return F_4 ( & V_2 -> V_5 , V_11 ) >> V_13 ;
case 0x00000010 : break;
case 0x00000020 : return F_8 ( V_2 , 0x004028 ) >> V_13 ;
case 0x00000030 : return F_8 ( V_2 , 0x004020 ) >> V_13 ;
}
break;
case V_37 :
V_13 = ( F_2 ( V_4 , 0x004008 ) & 0x00070000 ) >> 16 ;
if ( F_2 ( V_4 , 0x004008 ) & 0x00000200 ) {
switch ( V_19 & 0x0000c000 ) {
case 0x00000000 :
return F_4 ( & V_2 -> V_5 , V_11 ) >> V_13 ;
case 0x00008000 :
case 0x0000c000 :
return F_4 ( & V_2 -> V_5 , V_17 ) >> V_13 ;
}
} else {
return F_8 ( V_2 , 0x004008 ) >> V_13 ;
}
break;
case V_38 :
V_13 = ( F_1 ( V_2 ) & 0x00000700 ) >> 8 ;
switch ( V_4 -> V_7 ) {
case 0x84 :
case 0x86 :
case 0x92 :
case 0x94 :
case 0x96 :
case 0xa0 :
switch ( V_19 & 0x00000c00 ) {
case 0x00000000 :
if ( V_4 -> V_7 == 0xa0 )
return F_4 ( & V_2 -> V_5 , V_35 ) >> V_13 ;
return F_4 ( & V_2 -> V_5 , V_11 ) >> V_13 ;
case 0x00000400 :
return 0 ;
case 0x00000800 :
if ( V_19 & 0x01000000 )
return F_8 ( V_2 , 0x004028 ) >> V_13 ;
return F_8 ( V_2 , 0x004030 ) >> V_13 ;
case 0x00000c00 :
return F_4 ( & V_2 -> V_5 , V_35 ) >> V_13 ;
}
break;
case 0x98 :
switch ( V_19 & 0x00000c00 ) {
case 0x00000000 :
return F_4 ( & V_2 -> V_5 , V_35 ) >> V_13 ;
case 0x00000400 :
return 0 ;
case 0x00000800 :
return F_4 ( & V_2 -> V_5 , V_33 ) >> V_13 ;
case 0x00000c00 :
return F_4 ( & V_2 -> V_5 , V_37 ) >> V_13 ;
}
break;
}
break;
case V_26 :
switch ( V_4 -> V_7 ) {
case 0x50 :
case 0xa0 :
return F_8 ( V_2 , 0x00e810 ) >> 2 ;
case 0x84 :
case 0x86 :
case 0x92 :
case 0x94 :
case 0x96 :
case 0x98 :
V_13 = ( F_1 ( V_2 ) & 0x00000007 ) >> 0 ;
switch ( V_19 & 0x0c000000 ) {
case 0x00000000 : return F_4 ( & V_2 -> V_5 , V_17 ) ;
case 0x04000000 : break;
case 0x08000000 : return F_4 ( & V_2 -> V_5 , V_30 ) ;
case 0x0c000000 :
return F_4 ( & V_2 -> V_5 , V_32 ) >> V_13 ;
}
break;
default:
break;
}
default:
break;
}
F_11 ( V_6 , L_3 , V_18 , V_19 ) ;
return - V_39 ;
}
static T_1
F_12 ( struct V_1 * V_2 , T_1 V_40 , T_1 V_41 , int * V_14 , int * V_15 , int * V_13 )
{
struct V_8 * V_6 = & V_2 -> V_5 . V_6 ;
struct V_42 V_43 ;
int V_44 ;
V_44 = F_13 ( V_6 -> V_4 -> V_45 , V_40 , & V_43 ) ;
if ( V_44 )
return 0 ;
V_43 . V_46 . V_47 = 0 ;
V_43 . V_48 = F_7 ( V_2 , V_40 ) ;
if ( ! V_43 . V_48 )
return 0 ;
return F_14 ( V_6 , & V_43 , V_41 , V_14 , V_15 , NULL , NULL , V_13 ) ;
}
static inline T_1
F_15 ( T_1 V_18 , T_1 V_49 , int * div )
{
T_1 V_50 = V_18 , V_51 = V_18 ;
for ( * div = 0 ; * div <= 7 ; ( * div ) ++ ) {
if ( V_50 <= V_49 ) {
V_51 = V_50 << ( * div ? 1 : 0 ) ;
break;
}
V_50 >>= 1 ;
}
if ( V_49 - V_50 <= V_51 - V_49 )
return V_50 ;
( * div ) -- ;
return V_51 ;
}
static inline T_1
F_16 ( T_1 V_52 , T_1 V_53 )
{
return ( ( V_52 / 1000 ) == ( V_53 / 1000 ) ) ;
}
int
F_17 ( struct V_27 * V_5 , struct V_54 * V_55 )
{
struct V_1 * V_2 = V_1 ( V_5 ) ;
struct V_56 * V_57 = & V_2 -> V_57 ;
struct V_8 * V_6 = & V_2 -> V_5 . V_6 ;
struct V_3 * V_4 = V_6 -> V_4 ;
const int V_58 = V_55 -> V_59 [ V_36 ] ;
const int V_60 = V_55 -> V_59 [ V_35 ] ;
const int V_61 = V_55 -> V_59 [ V_38 ] ;
const int V_62 = V_55 -> V_59 [ V_26 ] ;
T_1 V_63 = 0 , V_64 = 0 ;
T_1 V_65 = 0 , V_66 = 0 ;
int V_14 , V_15 , V_67 , V_68 ;
int V_21 , V_69 ;
V_69 = F_18 ( V_57 , V_6 ) ;
if ( V_69 )
return V_69 ;
F_19 ( V_57 , V_70 , 0x00000001 ) ;
F_20 ( V_57 , 8000 ) ;
F_21 ( V_57 , 0x10 , 0x00 ) ;
F_22 ( V_57 , 0x00 , 0x01 ) ;
if ( V_61 ) {
V_21 = F_15 ( V_60 , V_61 , & V_67 ) ;
if ( V_4 -> V_7 != 0x98 )
V_69 = F_8 ( V_2 , 0x004030 ) ;
else
V_69 = F_4 ( & V_2 -> V_5 , V_33 ) ;
V_69 = F_15 ( V_69 , V_61 , & V_68 ) ;
if ( abs ( V_61 - V_21 ) <= abs ( V_61 - V_69 ) ) {
if ( V_4 -> V_7 != 0x98 )
V_64 |= 0x00000c00 ;
V_66 |= V_67 << 8 ;
} else {
V_64 |= 0x00000800 ;
V_66 |= V_68 << 8 ;
}
V_63 |= 0x00000c00 ;
V_65 |= 0x00000700 ;
}
if ( V_62 ) {
if ( F_16 ( V_62 , F_4 ( & V_2 -> V_5 , V_17 ) ) ) {
V_64 |= 0x00000000 ;
} else
if ( F_16 ( V_62 , F_4 ( & V_2 -> V_5 , V_30 ) ) ) {
V_64 |= 0x08000000 ;
} else {
V_21 = F_4 ( & V_2 -> V_5 , V_30 ) * 3 ;
F_15 ( V_21 , V_62 , & V_67 ) ;
V_64 |= 0x0c000000 ;
V_66 |= V_67 ;
}
V_63 |= 0x0c000000 ;
V_65 |= 0x00000007 ;
}
F_23 ( V_57 , V_19 , V_63 , 0x00000000 ) ;
F_23 ( V_57 , V_71 , V_65 , V_66 ) ;
F_23 ( V_57 , V_19 , V_63 , V_64 ) ;
if ( V_4 -> V_7 < 0x92 )
F_23 ( V_57 , V_19 , 0x001000b0 , 0x00100080 ) ;
else
F_23 ( V_57 , V_19 , 0x000000b3 , 0x00000081 ) ;
V_21 = F_12 ( V_2 , 0x4028 , V_60 , & V_14 , & V_15 , & V_67 ) ;
if ( V_21 == 0 )
return - V_72 ;
F_23 ( V_57 , V_73 [ 0 ] , 0xc03f0100 ,
0x80000000 | ( V_67 << 19 ) | ( V_67 << 16 ) ) ;
F_23 ( V_57 , V_73 [ 1 ] , 0x0000ffff , ( V_14 << 8 ) | V_15 ) ;
if ( V_67 -- && V_58 == ( V_60 << 1 ) ) {
F_23 ( V_57 , V_74 [ 0 ] , 0xc03f0100 , ( V_67 << 19 ) | ( V_67 << 16 ) ) ;
F_23 ( V_57 , V_19 , 0x00100033 , 0x00000023 ) ;
} else {
V_21 = F_12 ( V_2 , 0x4020 , V_58 , & V_14 , & V_15 , & V_67 ) ;
if ( V_21 == 0 )
return - V_72 ;
F_23 ( V_57 , V_74 [ 0 ] , 0xc03f0100 ,
0x80000000 | ( V_67 << 19 ) | ( V_67 << 16 ) ) ;
F_23 ( V_57 , V_74 [ 1 ] , 0x0000ffff , ( V_14 << 8 ) | V_15 ) ;
F_23 ( V_57 , V_19 , 0x00100033 , 0x00000033 ) ;
}
F_21 ( V_57 , 0x10 , 0x01 ) ;
F_22 ( V_57 , 0x00 , 0x00 ) ;
F_19 ( V_57 , V_70 , 0x00000000 ) ;
return 0 ;
}
int
F_24 ( struct V_27 * V_5 )
{
struct V_1 * V_2 = V_1 ( V_5 ) ;
return F_25 ( & V_2 -> V_57 , true ) ;
}
void
F_26 ( struct V_27 * V_5 )
{
struct V_1 * V_2 = V_1 ( V_5 ) ;
F_25 ( & V_2 -> V_57 , false ) ;
}
int
F_27 ( const struct V_75 * V_76 , struct V_3 * V_4 ,
int V_77 , bool V_78 , struct V_27 * * V_79 )
{
struct V_1 * V_2 ;
int V_44 ;
if ( ! ( V_2 = F_28 ( sizeof( * V_2 ) , V_80 ) ) )
return - V_81 ;
V_44 = F_29 ( V_76 , V_4 , V_77 , V_78 , & V_2 -> V_5 ) ;
* V_79 = & V_2 -> V_5 ;
if ( V_44 )
return V_44 ;
V_2 -> V_57 . V_82 = F_30 ( 0x002504 ) ;
V_2 -> V_57 . V_83 [ 0 ] = F_30 ( 0x004020 ) ;
V_2 -> V_57 . V_83 [ 1 ] = F_30 ( 0x004024 ) ;
V_2 -> V_57 . V_84 [ 0 ] = F_30 ( 0x004028 ) ;
V_2 -> V_57 . V_84 [ 1 ] = F_30 ( 0x00402c ) ;
switch ( V_4 -> V_7 ) {
case 0x92 :
case 0x94 :
case 0x96 :
V_2 -> V_57 . V_85 = F_30 ( 0x004800 ) ;
break;
default:
V_2 -> V_57 . V_85 = F_30 ( 0x004700 ) ;
break;
}
V_2 -> V_57 . V_86 = F_30 ( 0x00c040 ) ;
return 0 ;
}
int
F_31 ( struct V_3 * V_4 , int V_77 , struct V_27 * * V_79 )
{
return F_27 ( & V_1 , V_4 , V_77 , false , V_79 ) ;
}
