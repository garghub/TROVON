static T_1
F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = V_5 ( V_2 ) ;
switch ( F_3 ( V_6 -> V_4 ) -> V_7 ) {
case 0x50 :
case 0x84 :
case 0x86 :
case 0x98 :
case 0xa0 :
return F_4 ( V_4 , 0x004700 ) ;
case 0x92 :
case 0x94 :
case 0x96 :
return F_4 ( V_4 , 0x004800 ) ;
default:
return 0x00000000 ;
}
}
static T_1
F_5 ( struct V_1 * V_2 , T_1 V_8 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = V_5 ( V_2 ) ;
T_1 V_9 , V_10 = F_6 ( V_2 , V_11 ) ;
T_1 V_12 = F_4 ( V_4 , 0x00e18c ) ;
int V_13 , V_14 , V_15 , V_16 ;
switch ( F_3 ( V_6 -> V_4 ) -> V_7 ) {
case 0x50 :
case 0xa0 :
switch ( V_8 ) {
case 0x4020 :
case 0x4028 : V_16 = ! ! ( V_12 & 0x00000004 ) ; break;
case 0x4008 : V_16 = ! ! ( V_12 & 0x00000008 ) ; break;
case 0x4030 : V_16 = 0 ; break;
default:
F_7 ( V_6 , L_1 , V_8 ) ;
return 0 ;
}
V_9 = F_4 ( V_4 , 0x00e81c + ( V_16 * 0x0c ) ) ;
V_10 *= ( V_9 & 0x01000000 ) ? 2 : 4 ;
V_13 = ( V_9 & 0x00070000 ) >> 16 ;
V_14 = ( ( V_9 & 0x0000ff00 ) >> 8 ) + 1 ;
V_15 = ( ( V_9 & 0x000000ff ) >> 0 ) + 1 ;
break;
case 0x84 :
case 0x86 :
case 0x92 :
V_9 = F_4 ( V_4 , 0x00e81c ) ;
V_13 = ( V_9 & 0x00070000 ) >> 16 ;
V_14 = ( V_9 & 0x0000ff00 ) >> 8 ;
V_15 = ( V_9 & 0x000000ff ) >> 0 ;
break;
case 0x94 :
case 0x96 :
case 0x98 :
V_12 = F_4 ( V_4 , 0x00c050 ) ;
switch ( V_8 ) {
case 0x4020 : V_12 = ( V_12 & 0x00000003 ) >> 0 ; break;
case 0x4008 : V_12 = ( V_12 & 0x0000000c ) >> 2 ; break;
case 0x4028 : V_12 = ( V_12 & 0x00001800 ) >> 11 ; break;
case 0x4030 : V_12 = 3 ; break;
default:
F_7 ( V_6 , L_1 , V_8 ) ;
return 0 ;
}
switch ( V_12 ) {
case 0 : V_16 = 1 ; break;
case 1 : return F_6 ( V_2 , V_11 ) ;
case 2 : return F_6 ( V_2 , V_17 ) ;
case 3 : V_16 = 0 ; break;
}
V_9 = F_4 ( V_4 , 0x00e81c + ( V_16 * 0x28 ) ) ;
V_13 = ( F_4 ( V_4 , 0x00e824 + ( V_16 * 0x28 ) ) >> 16 ) & 7 ;
V_13 += ( V_9 & 0x00070000 ) >> 16 ;
V_14 = ( V_9 & 0x0000ff00 ) >> 8 ;
V_15 = ( V_9 & 0x000000ff ) >> 0 ;
break;
default:
F_8 ( 1 ) ;
}
if ( V_15 )
return ( V_10 * V_14 / V_15 ) >> V_13 ;
return 0 ;
}
static T_1
F_9 ( struct V_1 * V_2 , T_1 V_8 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = V_5 ( V_2 ) ;
T_1 V_18 , V_19 = F_4 ( V_4 , 0x00c040 ) ;
switch ( V_8 ) {
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
return F_6 ( V_2 , V_11 ) ;
default:
F_7 ( V_6 , L_2 , V_8 ) ;
return 0 ;
}
if ( V_18 )
return F_6 ( V_2 , V_17 ) ;
return F_5 ( V_2 , V_8 ) ;
}
static T_1
F_10 ( struct V_1 * V_2 , T_1 V_8 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = V_5 ( V_2 ) ;
T_1 V_19 = F_4 ( V_4 , 0x00c040 ) ;
T_1 V_20 = F_4 ( V_4 , V_8 + 0 ) ;
T_1 V_9 = F_4 ( V_4 , V_8 + 4 ) ;
T_1 V_10 = F_9 ( V_2 , V_8 ) ;
T_1 V_21 = 0 ;
int V_22 , V_23 , V_24 , V_25 ;
if ( V_8 == 0x004028 && ( V_19 & 0x00100000 ) ) {
if ( F_3 ( V_6 -> V_4 ) -> V_7 != 0xa0 )
return F_6 ( V_2 , V_26 ) ;
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
static T_1
F_6 ( struct V_1 * V_2 , enum V_27 V_18 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = V_5 ( V_2 ) ;
T_1 V_19 = F_4 ( V_4 , 0x00c040 ) ;
T_1 V_13 = 0 ;
switch ( V_18 ) {
case V_11 :
return V_4 -> V_28 ;
case V_17 :
return 100000 ;
case V_29 :
return F_6 ( V_2 , V_17 ) * 27778 / 10000 ;
case V_30 :
return F_6 ( V_2 , V_29 ) * 3 ;
case V_31 :
return F_6 ( V_2 , V_29 ) * 3 / 2 ;
case V_32 :
switch ( V_19 & 0x30000000 ) {
case 0x00000000 : return F_6 ( V_2 , V_17 ) ;
case 0x10000000 : break;
case 0x20000000 :
case 0x30000000 : return F_6 ( V_2 , V_29 ) ;
}
break;
case V_33 :
if ( ! ( V_19 & 0x00100000 ) )
V_13 = ( F_4 ( V_4 , 0x004028 ) & 0x00070000 ) >> 16 ;
switch ( V_19 & 0x00000003 ) {
case 0x00000000 : return F_6 ( V_2 , V_11 ) >> V_13 ;
case 0x00000001 : return F_6 ( V_2 , V_26 ) ;
case 0x00000002 : return F_10 ( V_2 , 0x004020 ) >> V_13 ;
case 0x00000003 : return F_10 ( V_2 , 0x004028 ) >> V_13 ;
}
break;
case V_34 :
V_13 = ( F_4 ( V_4 , 0x004020 ) & 0x00070000 ) >> 16 ;
switch ( V_19 & 0x00000030 ) {
case 0x00000000 :
if ( V_19 & 0x00000080 )
return F_6 ( V_2 , V_32 ) >> V_13 ;
return F_6 ( V_2 , V_11 ) >> V_13 ;
case 0x00000010 : break;
case 0x00000020 : return F_10 ( V_2 , 0x004028 ) >> V_13 ;
case 0x00000030 : return F_10 ( V_2 , 0x004020 ) >> V_13 ;
}
break;
case V_35 :
V_13 = ( F_4 ( V_4 , 0x004008 ) & 0x00070000 ) >> 16 ;
if ( F_4 ( V_4 , 0x004008 ) & 0x00000200 ) {
switch ( V_19 & 0x0000c000 ) {
case 0x00000000 :
return F_6 ( V_2 , V_11 ) >> V_13 ;
case 0x00008000 :
case 0x0000c000 :
return F_6 ( V_2 , V_17 ) >> V_13 ;
}
} else {
return F_10 ( V_2 , 0x004008 ) >> V_13 ;
}
break;
case V_36 :
V_13 = ( F_1 ( V_2 ) & 0x00000700 ) >> 8 ;
switch ( F_3 ( V_6 -> V_4 ) -> V_7 ) {
case 0x84 :
case 0x86 :
case 0x92 :
case 0x94 :
case 0x96 :
case 0xa0 :
switch ( V_19 & 0x00000c00 ) {
case 0x00000000 :
if ( F_3 ( V_6 -> V_4 ) -> V_7 == 0xa0 )
return F_6 ( V_2 , V_33 ) >> V_13 ;
return F_6 ( V_2 , V_11 ) >> V_13 ;
case 0x00000400 :
return 0 ;
case 0x00000800 :
if ( V_19 & 0x01000000 )
return F_10 ( V_2 , 0x004028 ) >> V_13 ;
return F_10 ( V_2 , 0x004030 ) >> V_13 ;
case 0x00000c00 :
return F_6 ( V_2 , V_33 ) >> V_13 ;
}
break;
case 0x98 :
switch ( V_19 & 0x00000c00 ) {
case 0x00000000 :
return F_6 ( V_2 , V_33 ) >> V_13 ;
case 0x00000400 :
return 0 ;
case 0x00000800 :
return F_6 ( V_2 , V_31 ) >> V_13 ;
case 0x00000c00 :
return F_6 ( V_2 , V_35 ) >> V_13 ;
}
break;
}
break;
case V_26 :
switch ( F_3 ( V_6 -> V_4 ) -> V_7 ) {
case 0x50 :
case 0xa0 :
return F_10 ( V_2 , 0x00e810 ) >> 2 ;
case 0x84 :
case 0x86 :
case 0x92 :
case 0x94 :
case 0x96 :
case 0x98 :
V_13 = ( F_1 ( V_2 ) & 0x00000007 ) >> 0 ;
switch ( V_19 & 0x0c000000 ) {
case 0x00000000 : return F_6 ( V_2 , V_17 ) ;
case 0x04000000 : break;
case 0x08000000 : return F_6 ( V_2 , V_29 ) ;
case 0x0c000000 :
return F_6 ( V_2 , V_30 ) >> V_13 ;
}
break;
default:
break;
}
default:
break;
}
F_11 ( V_6 , L_3 , V_18 , V_19 ) ;
return 0 ;
}
int
F_12 ( struct V_1 * V_2 , struct V_37 * V_38 )
{
struct V_5 * V_6 = V_5 ( V_2 ) ;
if ( F_3 ( V_6 -> V_4 ) -> V_7 == 0xaa ||
F_3 ( V_6 -> V_4 ) -> V_7 == 0xac )
return 0 ;
V_38 -> V_39 = F_6 ( V_2 , V_33 ) ;
V_38 -> V_40 = F_6 ( V_2 , V_34 ) ;
V_38 -> V_41 = F_6 ( V_2 , V_35 ) ;
if ( F_3 ( V_6 -> V_4 ) -> V_7 != 0x50 ) {
V_38 -> V_42 = F_6 ( V_2 , V_36 ) ;
V_38 -> V_43 = F_6 ( V_2 , V_26 ) ;
}
return 0 ;
}
static T_1
F_13 ( struct V_1 * V_2 , T_1 V_44 , struct V_45 * V_46 ,
T_1 V_21 , int * V_22 , int * V_24 , int * V_47 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_48 * V_49 = V_48 ( V_4 ) ;
struct V_50 * V_51 = V_50 ( V_4 ) ;
struct V_52 V_9 ;
int V_53 ;
V_53 = F_14 ( V_49 , V_44 , V_46 ) ;
if ( V_53 )
return 0 ;
V_46 -> V_54 . V_55 = 0 ;
V_46 -> V_56 = F_9 ( V_2 , V_44 ) ;
if ( ! V_46 -> V_56 )
return 0 ;
V_53 = V_51 -> V_57 ( V_51 , V_46 , V_21 , & V_9 ) ;
if ( V_53 == 0 )
return 0 ;
* V_22 = V_9 . V_22 ;
* V_24 = V_9 . V_24 ;
* V_47 = V_9 . V_47 ;
return V_53 ;
}
static inline T_1
F_15 ( T_1 V_18 , T_1 V_58 , int * div )
{
T_1 V_59 = V_18 , V_60 = V_18 ;
for ( * div = 0 ; * div <= 7 ; ( * div ) ++ ) {
if ( V_59 <= V_58 ) {
V_60 = V_59 << ( * div ? 1 : 0 ) ;
break;
}
V_59 >>= 1 ;
}
if ( V_58 - V_59 <= V_60 - V_58 )
return V_59 ;
( * div ) -- ;
return V_60 ;
}
static inline T_1
F_16 ( T_1 V_61 , T_1 V_62 )
{
return ( ( V_61 / 1000 ) == ( V_62 / 1000 ) ) ;
}
static void
F_17 ( struct V_63 * V_64 )
{
struct V_65 * V_66 = V_64 -> V_67 ;
struct V_68 * V_69 = & V_66 -> V_70 ;
F_18 ( V_69 , 0x1002d4 , 0x00000001 ) ;
}
static void
F_19 ( struct V_63 * V_64 )
{
struct V_65 * V_66 = V_64 -> V_67 ;
struct V_68 * V_69 = & V_66 -> V_70 ;
F_18 ( V_69 , 0x1002d0 , 0x00000001 ) ;
}
static void
F_20 ( struct V_63 * V_64 , bool V_71 )
{
struct V_65 * V_66 = V_64 -> V_67 ;
struct V_68 * V_69 = & V_66 -> V_70 ;
F_18 ( V_69 , 0x100210 , V_71 ? 0x80000000 : 0x00000000 ) ;
}
static void
F_21 ( struct V_63 * V_64 , bool V_71 )
{
struct V_65 * V_66 = V_64 -> V_67 ;
struct V_68 * V_69 = & V_66 -> V_70 ;
F_18 ( V_69 , 0x1002dc , V_71 ? 0x00000001 : 0x00000000 ) ;
}
static void
F_22 ( struct V_63 * V_64 , T_1 V_72 )
{
struct V_65 * V_66 = V_64 -> V_67 ;
struct V_68 * V_69 = & V_66 -> V_70 ;
if ( V_72 > 1000 )
F_23 ( V_69 , ( V_72 + 500 ) / 1000 ) ;
}
static T_1
F_24 ( struct V_63 * V_64 , int V_73 )
{
struct V_3 * V_4 = F_2 ( V_64 -> V_2 ) ;
if ( V_73 <= 1 )
return F_4 ( V_4 , 0x1002c0 + ( ( V_73 - 0 ) * 4 ) ) ;
if ( V_73 <= 3 )
return F_4 ( V_4 , 0x1002e0 + ( ( V_73 - 2 ) * 4 ) ) ;
return 0 ;
}
static void
F_25 ( struct V_63 * V_64 , int V_73 , T_1 V_74 )
{
struct V_3 * V_4 = F_2 ( V_64 -> V_2 ) ;
struct V_75 * V_76 = V_75 ( V_4 ) ;
struct V_65 * V_66 = V_64 -> V_67 ;
struct V_68 * V_69 = & V_66 -> V_70 ;
if ( V_73 <= 1 ) {
if ( V_76 -> V_77 . V_78 > 1 )
F_18 ( V_69 , 0x1002c8 + ( ( V_73 - 0 ) * 4 ) , V_74 ) ;
F_18 ( V_69 , 0x1002c0 + ( ( V_73 - 0 ) * 4 ) , V_74 ) ;
} else
if ( V_73 <= 3 ) {
if ( V_76 -> V_77 . V_78 > 1 )
F_18 ( V_69 , 0x1002e8 + ( ( V_73 - 2 ) * 4 ) , V_74 ) ;
F_18 ( V_69 , 0x1002e0 + ( ( V_73 - 2 ) * 4 ) , V_74 ) ;
}
}
static void
F_26 ( struct V_63 * V_64 )
{
struct V_3 * V_4 = F_2 ( V_64 -> V_2 ) ;
struct V_65 * V_66 = V_64 -> V_67 ;
struct V_68 * V_69 = & V_66 -> V_70 ;
T_1 V_20 = F_4 ( V_4 , 0x004008 ) ;
V_66 -> V_79 = F_4 ( V_4 , 0x00c040 ) ;
V_66 -> V_79 &= ~ 0xc0000000 ;
V_66 -> V_79 |= 0x0000c000 ;
F_18 ( V_69 , 0xc040 , V_66 -> V_79 ) ;
F_18 ( V_69 , 0x4008 , V_20 | 0x00000200 ) ;
if ( V_66 -> V_80 & 0x80000000 )
F_18 ( V_69 , 0x400c , V_66 -> V_81 ) ;
F_18 ( V_69 , 0x4008 , V_66 -> V_80 ) ;
}
static void
F_27 ( struct V_63 * V_64 )
{
struct V_3 * V_4 = F_2 ( V_64 -> V_2 ) ;
struct V_65 * V_66 = V_64 -> V_67 ;
struct V_37 * V_38 = V_66 -> V_38 ;
struct V_68 * V_69 = & V_66 -> V_70 ;
int V_82 ;
for ( V_82 = 0 ; V_82 < 9 ; V_82 ++ ) {
T_1 V_44 = 0x100220 + ( V_82 * 4 ) ;
T_1 V_83 = F_4 ( V_4 , V_44 ) ;
if ( V_83 != V_38 -> V_84 . V_44 [ V_82 ] )
F_18 ( V_69 , V_44 , V_38 -> V_84 . V_44 [ V_82 ] ) ;
}
}
static int
F_28 ( struct V_1 * V_2 , struct V_37 * V_38 ,
struct V_65 * V_66 )
{
struct V_5 * V_6 = V_5 ( V_2 ) ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
T_1 V_85 = 0 ;
struct V_63 V_64 = {
. V_2 = V_2 ,
. V_86 = F_17 ,
. V_87 = F_19 ,
. V_88 = F_20 ,
. V_89 = F_21 ,
. V_90 = F_22 ,
. V_91 = F_24 ,
. V_92 = F_25 ,
. V_93 = F_26 ,
. V_94 = F_27 ,
. V_67 = V_66
} ;
struct V_68 * V_69 = & V_66 -> V_70 ;
struct V_45 V_46 ;
int V_14 , V_15 , V_13 ;
int V_53 ;
V_66 -> V_80 = F_4 ( V_4 , 0x004008 ) ;
V_66 -> V_80 &= ~ 0x81ff0200 ;
if ( F_16 ( V_38 -> V_41 , F_6 ( V_2 , V_17 ) ) ) {
V_66 -> V_80 |= 0x00000200 | ( V_46 . V_95 << 19 ) ;
} else {
V_53 = F_13 ( V_2 , 0x4008 , & V_46 , V_38 -> V_41 , & V_14 , & V_15 , & V_13 ) ;
if ( V_53 == 0 )
return - V_96 ;
V_66 -> V_80 |= 0x80000000 | ( V_13 << 22 ) | ( V_13 << 16 ) ;
V_66 -> V_80 |= V_46 . V_95 << 19 ;
V_66 -> V_81 = ( V_14 << 8 ) | V_15 ;
}
F_29 ( V_69 ) ;
if ( V_85 ) {
F_30 ( V_69 , V_85 , 0x00 ) ;
F_30 ( V_69 , V_85 , 0x01 ) ;
}
if ( F_3 ( V_6 -> V_4 ) -> V_7 >= 0x92 )
F_18 ( V_69 , 0x611200 , 0x00003300 ) ;
F_31 ( V_69 , 0x10 , 0 ) ;
F_30 ( V_69 , 0x00 , 0x01 ) ;
V_53 = F_32 ( & V_64 , V_38 ) ;
if ( V_53 )
return V_53 ;
F_31 ( V_69 , 0x10 , 1 ) ;
F_30 ( V_69 , 0x00 , 0x00 ) ;
if ( F_3 ( V_6 -> V_4 ) -> V_7 >= 0x92 )
F_18 ( V_69 , 0x611200 , 0x00003330 ) ;
F_33 ( V_69 ) ;
return 0 ;
}
void *
F_34 ( struct V_1 * V_2 , struct V_37 * V_38 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = V_5 ( V_2 ) ;
struct V_65 * V_66 ;
struct V_68 * V_69 ;
struct V_45 V_46 ;
T_1 V_97 , V_19 , V_98 , V_20 ;
int V_21 , V_53 = - V_96 ;
int V_14 , V_15 , V_99 , V_100 ;
if ( F_3 ( V_6 -> V_4 ) -> V_7 == 0xaa ||
F_3 ( V_6 -> V_4 ) -> V_7 == 0xac )
return F_35 ( - V_101 ) ;
V_66 = F_36 ( sizeof( * V_66 ) , V_102 ) ;
if ( ! V_66 )
return F_35 ( - V_103 ) ;
V_66 -> V_38 = V_38 ;
V_66 -> V_70 . V_104 = 0 ;
if ( V_38 -> V_41 ) {
V_53 = F_28 ( V_2 , V_38 , V_66 ) ;
if ( V_53 )
goto error;
V_66 -> V_105 = V_38 -> V_106 ;
}
V_98 = F_1 ( V_2 ) ;
V_19 = V_66 -> V_79 ;
V_69 = & V_66 -> V_107 ;
F_29 ( V_69 ) ;
F_31 ( V_69 , 0x10 , 0 ) ;
F_30 ( V_69 , 0x00 , 0x01 ) ;
if ( V_38 -> V_42 ) {
V_19 &= ~ 0x00000c00 ;
V_98 &= ~ 0x00000700 ;
}
if ( V_38 -> V_43 ) {
V_19 &= ~ 0x0c000000 ;
V_98 &= ~ 0x00000007 ;
}
F_18 ( V_69 , 0x00c040 , V_19 ) ;
if ( V_38 -> V_42 ) {
V_21 = F_15 ( V_38 -> V_39 , V_38 -> V_42 , & V_99 ) ;
if ( F_3 ( V_6 -> V_4 ) -> V_7 != 0x98 )
V_97 = F_10 ( V_2 , 0x004030 ) ;
else
V_97 = F_6 ( V_2 , V_31 ) ;
V_97 = F_15 ( V_97 , V_38 -> V_42 , & V_100 ) ;
if ( abs ( ( int ) V_38 -> V_42 - V_21 ) <=
abs ( ( int ) V_38 -> V_42 - V_97 ) ) {
if ( F_3 ( V_6 -> V_4 ) -> V_7 != 0x98 )
V_19 |= 0x00000c00 ;
V_98 |= V_99 << 8 ;
} else {
V_19 |= 0x00000800 ;
V_98 |= V_100 << 8 ;
}
}
if ( V_38 -> V_43 ) {
if ( F_16 ( V_38 -> V_43 , F_6 ( V_2 , V_17 ) ) ) {
V_19 |= 0x00000000 ;
} else
if ( F_16 ( V_38 -> V_43 , F_6 ( V_2 , V_29 ) ) ) {
V_19 |= 0x08000000 ;
} else {
V_21 = F_6 ( V_2 , V_29 ) * 3 ;
V_21 = F_15 ( V_21 , V_38 -> V_43 , & V_99 ) ;
V_19 |= 0x0c000000 ;
V_98 |= V_99 ;
}
}
switch ( F_3 ( V_6 -> V_4 ) -> V_7 ) {
case 0x92 :
case 0x94 :
case 0x96 :
F_18 ( V_69 , 0x004800 , V_98 ) ;
break;
default:
F_18 ( V_69 , 0x004700 , V_98 ) ;
break;
}
F_18 ( V_69 , 0x00c040 , V_19 ) ;
if ( F_3 ( V_6 -> V_4 ) -> V_7 < 0x92 )
V_19 = ( V_19 & ~ 0x001000b0 ) | 0x00100080 ;
else
V_19 = ( V_19 & ~ 0x000000b3 ) | 0x00000081 ;
F_18 ( V_69 , 0x00c040 , V_19 ) ;
V_21 = F_13 ( V_2 , 0x4028 , & V_46 , V_38 -> V_39 , & V_14 , & V_15 , & V_99 ) ;
if ( V_21 == 0 )
goto error;
V_20 = F_4 ( V_4 , 0x004028 ) & ~ 0xc03f0100 ;
V_19 &= ~ 0x00100000 ;
V_19 |= 3 ;
F_18 ( V_69 , 0x004028 , 0x80000000 | ( V_99 << 19 ) | ( V_99 << 16 ) | V_20 ) ;
F_18 ( V_69 , 0x00402c , ( V_14 << 8 ) | V_15 ) ;
V_20 = F_4 ( V_4 , 0x004020 ) & ~ 0xc03f0100 ;
if ( V_99 -- && V_38 -> V_40 == ( V_38 -> V_39 << 1 ) ) {
F_18 ( V_69 , 0x004020 , ( V_99 << 19 ) | ( V_99 << 16 ) | V_20 ) ;
F_18 ( V_69 , 0x00c040 , 0x00000020 | V_19 ) ;
} else {
V_21 = F_13 ( V_2 , 0x4020 , & V_46 , V_38 -> V_40 , & V_14 , & V_15 , & V_99 ) ;
if ( V_21 == 0 )
goto error;
V_20 |= 0x80000000 ;
F_18 ( V_69 , 0x004020 , ( V_99 << 19 ) | ( V_99 << 16 ) | V_20 ) ;
F_18 ( V_69 , 0x004024 , ( V_14 << 8 ) | V_15 ) ;
F_18 ( V_69 , 0x00c040 , 0x00000030 | V_19 ) ;
}
F_31 ( V_69 , 0x10 , 1 ) ;
F_30 ( V_69 , 0x00 , 0x00 ) ;
F_33 ( V_69 ) ;
return V_66 ;
error:
F_37 ( V_66 ) ;
return F_35 ( V_53 ) ;
}
static int
F_38 ( struct V_1 * V_2 , struct V_68 * V_69 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = V_5 ( V_2 ) ;
T_1 V_108 , V_109 ;
int V_82 ;
if ( F_3 ( V_6 -> V_4 ) -> V_7 < 0x94 ) {
V_108 = 0x001400 ;
V_109 = 0x00000003 ;
} else {
V_108 = 0x080000 ;
V_109 = 0x00000001 ;
}
F_39 ( V_4 , 0x001098 , 0x00000008 , 0x00000000 ) ;
F_40 ( V_4 , 0x001304 , 0x00000000 ) ;
if ( F_3 ( V_6 -> V_4 ) -> V_7 >= 0x92 )
F_40 ( V_4 , 0x001318 , 0x00000000 ) ;
for ( V_82 = 0 ; V_82 < V_69 -> V_104 / 4 ; V_82 ++ )
F_40 ( V_4 , V_108 + ( V_82 * 4 ) , V_69 -> V_110 . T_1 [ V_82 ] ) ;
F_39 ( V_4 , 0x001098 , 0x00000018 , 0x00000018 ) ;
F_40 ( V_4 , 0x00130c , V_109 ) ;
if ( ! F_41 ( V_4 , 0x001308 , 0x00000100 , 0x00000000 ) ) {
F_7 ( V_6 , L_4 ) ;
F_7 ( V_6 , L_5 , F_4 ( V_4 , 0x001308 ) ) ;
for ( V_82 = 0 ; V_82 < V_69 -> V_104 / 4 ; V_82 ++ ) {
F_7 ( V_6 , L_6 , 0x1400 + ( V_82 * 4 ) ,
F_4 ( V_4 , 0x001400 + ( V_82 * 4 ) ) ) ;
}
return - V_111 ;
}
return 0 ;
}
int
F_42 ( struct V_1 * V_2 , void * V_74 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_65 * V_66 = V_74 ;
struct V_112 V_15 ;
int V_53 = - V_113 ;
F_39 ( V_4 , 0x002504 , 0x00000001 , 0x00000001 ) ;
if ( ! F_41 ( V_4 , 0x002504 , 0x00000010 , 0x00000010 ) )
goto V_114;
if ( ! F_41 ( V_4 , 0x00251c , 0x0000003f , 0x0000003f ) )
goto V_114;
#define F_43 ( V_61 , V_62 ) nouveau_bios_run_init_table((a), (b), NULL, 0)
if ( V_66 -> V_70 . V_104 ) {
if ( ! F_44 ( V_2 , 'M' , & V_15 ) && V_15 . V_115 == 1 ) {
if ( V_15 . V_116 >= 6 )
F_43 ( V_2 , F_45 ( V_15 . V_74 [ 5 ] ) ) ;
if ( V_15 . V_116 >= 8 )
F_43 ( V_2 , F_45 ( V_15 . V_74 [ 7 ] ) ) ;
if ( V_15 . V_116 >= 10 )
F_43 ( V_2 , F_45 ( V_15 . V_74 [ 9 ] ) ) ;
F_43 ( V_2 , V_66 -> V_105 ) ;
}
V_53 = F_38 ( V_2 , & V_66 -> V_70 ) ;
if ( V_53 )
goto V_114;
}
V_53 = F_38 ( V_2 , & V_66 -> V_107 ) ;
V_114:
F_39 ( V_4 , 0x002504 , 0x00000001 , 0x00000000 ) ;
F_37 ( V_66 ) ;
return V_53 ;
}
