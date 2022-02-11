static T_1
F_1 ( struct V_1 * V_2 , struct V_3 * V_4 , T_2 V_5 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
static const T_2 V_9 [] = { 24 , 16 , 8 , 0 } ;
static const T_2 V_10 [] = { 16 , 8 , 0 , 24 } ;
if ( V_7 -> V_11 == 0xaf )
return V_9 [ V_5 ] ;
return V_10 [ V_5 ] ;
}
static void
F_2 ( struct V_1 * V_2 , struct V_3 * V_4 , T_2 V_12 )
{
T_1 V_13 = F_3 ( V_4 -> V_13 ) - 1 , V_14 = ! ( V_4 -> V_15 . V_14 & 1 ) ;
F_4 ( V_2 , F_5 ( V_13 , V_14 ) , 0x0f000000 , V_12 << 24 ) ;
}
static void
F_6 ( struct V_1 * V_2 , struct V_3 * V_4 ,
T_2 V_5 , T_2 V_16 , T_2 V_17 )
{
T_1 V_13 = F_3 ( V_4 -> V_13 ) - 1 , V_14 = ! ( V_4 -> V_15 . V_14 & 1 ) ;
T_1 V_18 = F_1 ( V_2 , V_4 , V_5 ) ;
T_1 V_19 = 0x000000ff << V_18 ;
T_2 * V_20 , * V_21 , * V_22 ;
V_20 = F_7 ( V_2 , V_4 , & V_21 ) ;
if ( ! V_20 || ( V_20 [ 0 ] != 0x20 && V_20 [ 0 ] != 0x21 ) ) {
F_8 ( V_2 , L_1 ) ;
return;
}
V_22 = V_21 + V_20 [ 4 ] ;
while ( V_22 [ 0 ] != V_16 || V_22 [ 1 ] != V_17 ) {
V_22 += V_20 [ 5 ] ;
if ( V_22 >= V_21 + V_20 [ 4 ] + V_21 [ 4 ] * V_20 [ 5 ] )
return;
}
F_4 ( V_2 , F_9 ( V_13 , V_14 ) , V_19 , V_22 [ 2 ] << V_18 ) ;
F_4 ( V_2 , F_10 ( V_13 , V_14 ) , V_19 , V_22 [ 3 ] << V_18 ) ;
F_4 ( V_2 , F_11 ( V_13 , V_14 ) , 0x0000ff00 , V_22 [ 4 ] << 8 ) ;
}
static void
F_12 ( struct V_1 * V_2 , struct V_3 * V_4 , int V_23 ,
int V_24 , T_1 V_25 , bool V_26 )
{
T_1 V_13 = F_3 ( V_4 -> V_13 ) - 1 , V_14 = ! ( V_4 -> V_15 . V_14 & 1 ) ;
T_1 V_27 = F_13 ( V_2 , F_5 ( V_13 , V_14 ) ) & ~ 0x001f4000 ;
T_1 V_28 = F_13 ( V_2 , 0x614300 + ( V_13 * 0x800 ) ) & ~ 0x000c0000 ;
T_2 * V_20 , * V_21 , V_19 ;
int V_29 ;
V_20 = F_7 ( V_2 , V_4 , & V_21 ) ;
if ( ! V_20 || ( V_20 [ 0 ] != 0x20 && V_20 [ 0 ] != 0x21 ) ) {
F_8 ( V_2 , L_1 ) ;
return;
}
V_21 = F_14 ( V_2 , V_21 [ 10 ] ) ;
if ( V_21 ) {
while ( V_25 < F_15 ( V_21 [ 0 ] ) * 10 )
V_21 += 4 ;
F_16 ( V_2 , F_15 ( V_21 [ 2 ] ) , V_4 , V_23 ) ;
}
V_27 |= ( ( 1 << V_24 ) - 1 ) << 16 ;
if ( V_26 )
V_27 |= 0x00004000 ;
if ( V_25 > 162000 )
V_28 |= 0x00040000 ;
F_17 ( V_2 , 0x614300 + ( V_13 * 0x800 ) , V_28 ) ;
F_17 ( V_2 , F_5 ( V_13 , V_14 ) , V_27 ) ;
V_19 = 0 ;
for ( V_29 = 0 ; V_29 < V_24 ; V_29 ++ )
V_19 |= 1 << ( F_1 ( V_2 , V_4 , V_29 ) >> 3 ) ;
F_4 ( V_2 , F_11 ( V_13 , V_14 ) , 0x0000000f , V_19 ) ;
}
static void
F_18 ( struct V_1 * V_2 , T_1 V_13 , T_1 V_14 , T_1 * V_30 , T_1 * V_31 )
{
T_1 V_27 = F_13 ( V_2 , F_5 ( V_13 , V_14 ) ) & 0x000f0000 ;
T_1 V_28 = F_13 ( V_2 , 0x614300 + ( V_13 * 0x800 ) ) ;
if ( V_28 & 0x000c0000 )
* V_31 = 270000 ;
else
* V_31 = 162000 ;
if ( V_27 > 0x00030000 ) * V_30 = 4 ;
else if ( V_27 > 0x00010000 ) * V_30 = 2 ;
else * V_30 = 1 ;
}
void
F_19 ( struct V_1 * V_2 , int V_13 , int V_14 , T_1 V_32 , T_1 V_33 )
{
const T_1 V_34 = 100000 ;
int V_35 = 0 , V_36 = 0 , V_37 = 0 , V_38 = 0 ;
int V_39 , V_40 , V_41 , V_42 ;
T_3 V_43 , V_44 , V_45 ;
T_1 V_46 = 64 * V_34 ;
T_1 V_24 , V_25 , V_47 ;
F_18 ( V_2 , V_13 , V_14 , & V_24 , & V_25 ) ;
V_43 = ( V_32 * V_33 / 8 ) / V_24 ;
V_44 = V_43 * V_34 ;
V_47 = F_20 ( V_44 , V_25 ) ;
for ( V_39 = 64 ; V_39 >= 32 ; V_39 -- ) {
T_1 V_48 = V_44 * V_39 ;
T_1 V_49 , V_50 ;
V_40 = V_48 / V_34 ;
V_49 = V_40 * V_34 ;
V_50 = V_48 - V_49 ;
if ( V_50 ) {
if ( V_50 >= ( V_34 / 2 ) ) {
V_41 = V_34 / ( V_34 - V_50 ) ;
if ( V_34 - ( V_41 * V_50 ) )
V_41 ++ ;
if ( V_41 <= 15 ) {
V_42 = 1 ;
V_49 += V_34 - ( V_34 / V_41 ) ;
} else {
V_42 = 0 ;
V_41 = 1 ;
V_49 += V_34 ;
}
} else {
V_42 = 0 ;
V_41 = F_21 ( ( int ) ( V_34 / V_50 ) , 15 ) ;
V_49 += V_34 / V_41 ;
}
V_50 = V_49 - V_48 ;
} else {
V_42 = 0 ;
V_41 = 1 ;
V_40 -- ;
}
if ( V_50 < V_46 ) {
V_46 = V_50 ;
V_35 = V_39 ;
V_38 = V_42 ;
V_37 = V_41 ;
V_36 = V_40 ;
if ( V_50 == 0 )
break;
}
}
if ( ! V_35 ) {
F_8 ( V_2 , L_2 ) ;
return;
}
V_45 = ( V_34 - V_44 ) * V_35 ;
V_45 *= V_44 ;
V_47 = F_20 ( V_45 , V_34 ) ;
V_47 = F_20 ( V_45 , V_34 ) ;
V_45 += 6 ;
F_4 ( V_2 , F_5 ( V_13 , V_14 ) , 0x000001fc , V_35 << 2 ) ;
F_4 ( V_2 , F_22 ( V_13 , V_14 ) , 0x010f7f3f , V_38 << 24 |
V_37 << 16 |
V_36 << 8 |
V_45 ) ;
}
static void
F_23 ( struct V_51 * V_52 )
{
struct V_53 * V_54 = V_53 ( V_52 ) ;
struct V_1 * V_2 = V_52 -> V_2 ;
struct V_55 * V_56 = F_24 ( V_2 ) -> V_57 ;
int V_58 ;
if ( ! V_54 -> V_23 )
return;
F_25 ( F_26 ( V_54 -> V_23 ) , true ) ;
F_27 ( V_2 , L_3 , V_54 -> V_13 ) ;
V_58 = F_28 ( V_56 , 4 ) ;
if ( V_58 ) {
F_8 ( V_2 , L_4 ) ;
return;
}
F_29 ( V_56 , 0 , F_30 ( V_54 -> V_13 , V_59 ) , 1 ) ;
F_31 ( V_56 , 0 ) ;
F_29 ( V_56 , 0 , V_60 , 1 ) ;
F_31 ( V_56 , 0 ) ;
F_32 ( V_52 , NULL ) ;
V_54 -> V_23 = NULL ;
V_54 -> V_61 = V_62 ;
}
static void
F_33 ( struct V_51 * V_52 , int V_63 )
{
struct V_1 * V_2 = V_52 -> V_2 ;
struct V_53 * V_54 = V_53 ( V_52 ) ;
struct V_51 * V_64 ;
T_4 V_65 ;
int V_13 = V_54 -> V_13 ;
F_27 ( V_2 , L_5 , V_13 , V_54 -> V_4 -> type , V_63 ) ;
V_54 -> V_61 = V_63 ;
F_34 (enc, &dev->mode_config.encoder_list, head) {
struct V_53 * V_66 = V_53 ( V_64 ) ;
if ( V_66 == V_54 ||
( V_66 -> V_4 -> type != V_67 &&
V_66 -> V_4 -> type != V_68 &&
V_66 -> V_4 -> type != V_69 ) ||
V_66 -> V_4 -> V_13 != V_54 -> V_4 -> V_13 )
continue;
if ( V_66 -> V_61 == V_70 )
return;
}
if ( ! F_35 ( V_2 , F_36 ( V_13 ) ,
V_71 , 0 ) ) {
F_8 ( V_2 , L_6 , V_13 ) ;
F_8 ( V_2 , L_7 , V_13 ,
F_13 ( V_2 , F_36 ( V_13 ) ) ) ;
}
V_65 = F_13 ( V_2 , F_36 ( V_13 ) ) ;
if ( V_63 == V_70 )
V_65 |= V_72 ;
else
V_65 &= ~ V_72 ;
F_17 ( V_2 , F_36 ( V_13 ) , V_65 |
V_71 ) ;
if ( ! F_35 ( V_2 , F_37 ( V_13 ) ,
V_73 , 0 ) ) {
F_8 ( V_2 , L_8 , V_13 ) ;
F_8 ( V_2 , L_9 , V_13 ,
F_13 ( V_2 , F_37 ( V_13 ) ) ) ;
}
if ( V_54 -> V_4 -> type == V_69 ) {
struct V_74 V_75 = {
. V_76 = F_12 ,
. V_77 = F_2 ,
. V_78 = F_6
} ;
F_38 ( V_52 , V_63 , V_54 -> V_79 . V_80 , & V_75 ) ;
}
}
static void
F_39 ( struct V_51 * V_52 )
{
F_8 ( V_52 -> V_2 , L_10 ) ;
}
static void
F_40 ( struct V_51 * V_52 )
{
F_8 ( V_52 -> V_2 , L_10 ) ;
}
static bool
F_41 ( struct V_51 * V_52 , struct V_81 * V_63 ,
struct V_81 * V_82 )
{
struct V_53 * V_54 = V_53 ( V_52 ) ;
struct V_83 * V_84 ;
F_27 ( V_52 -> V_2 , L_11 , V_54 -> V_13 ) ;
V_84 = F_42 ( V_54 ) ;
if ( ! V_84 ) {
F_8 ( V_52 -> V_2 , L_12 ) ;
return false ;
}
if ( V_84 -> V_85 != V_86 &&
V_84 -> V_87 )
F_43 ( V_82 , V_84 -> V_87 ) ;
return true ;
}
static void
F_44 ( struct V_51 * V_52 )
{
struct V_53 * V_54 = V_53 ( V_52 ) ;
F_23 ( V_52 ) ;
if ( V_54 -> V_4 -> type == V_69 ) {
F_45 ( V_52 -> V_2 ) ;
}
}
static void
F_46 ( struct V_51 * V_52 )
{
}
static void
F_47 ( struct V_51 * V_52 , struct V_81 * V_88 ,
struct V_81 * V_63 )
{
struct V_55 * V_56 = F_24 ( V_52 -> V_2 ) -> V_57 ;
struct V_53 * V_54 = V_53 ( V_52 ) ;
struct V_1 * V_2 = V_52 -> V_2 ;
struct F_26 * V_23 = F_26 ( V_52 -> V_23 ) ;
struct V_83 * V_89 ;
T_4 V_90 = 0 ;
int V_58 ;
F_27 ( V_2 , L_13 ,
V_54 -> V_13 , V_54 -> V_4 -> type , V_23 -> V_91 ) ;
V_54 -> V_23 = V_52 -> V_23 ;
switch ( V_54 -> V_4 -> type ) {
case V_67 :
if ( V_54 -> V_4 -> V_15 . V_14 & 1 ) {
if ( V_63 -> clock < 165000 )
V_90 = 0x0100 ;
else
V_90 = 0x0500 ;
} else
V_90 = 0x0200 ;
F_32 ( V_52 , V_63 ) ;
break;
case V_69 :
V_89 = F_42 ( V_54 ) ;
if ( V_89 && V_89 -> V_92 . V_93 . V_94 == 6 ) {
V_54 -> V_79 . V_80 = V_63 -> clock * 18 / 8 ;
V_90 |= 0x00020000 ;
} else {
V_54 -> V_79 . V_80 = V_63 -> clock * 24 / 8 ;
V_90 |= 0x00050000 ;
}
if ( V_54 -> V_4 -> V_15 . V_14 & 1 )
V_90 |= 0x00000800 ;
else
V_90 |= 0x00000900 ;
break;
default:
break;
}
if ( V_23 -> V_91 == 1 )
V_90 |= V_95 ;
else
V_90 |= V_96 ;
if ( V_63 -> V_97 & V_98 )
V_90 |= V_99 ;
if ( V_63 -> V_97 & V_100 )
V_90 |= V_101 ;
F_33 ( V_52 , V_70 ) ;
V_58 = F_28 ( V_56 , 2 ) ;
if ( V_58 ) {
F_8 ( V_2 , L_14 ) ;
V_54 -> V_23 = NULL ;
return;
}
F_29 ( V_56 , 0 , F_30 ( V_54 -> V_13 , V_59 ) , 1 ) ;
F_31 ( V_56 , V_90 ) ;
}
static struct V_102 *
F_48 ( struct V_51 * V_52 )
{
return V_53 ( V_52 ) -> V_23 ;
}
static void
F_49 ( struct V_51 * V_52 )
{
struct V_53 * V_54 = V_53 ( V_52 ) ;
if ( ! V_52 )
return;
F_27 ( V_52 -> V_2 , L_15 ) ;
F_50 ( V_52 ) ;
F_51 ( V_54 ) ;
}
int
F_52 ( struct V_103 * V_84 , struct V_3 * V_21 )
{
struct V_53 * V_54 = NULL ;
struct V_1 * V_2 = V_84 -> V_2 ;
struct V_51 * V_52 ;
int type ;
F_27 ( V_2 , L_15 ) ;
switch ( V_21 -> type ) {
case V_67 :
case V_69 :
type = V_104 ;
break;
case V_68 :
type = V_105 ;
break;
default:
return - V_106 ;
}
V_54 = F_53 ( sizeof( * V_54 ) , V_107 ) ;
if ( ! V_54 )
return - V_108 ;
V_52 = F_54 ( V_54 ) ;
V_54 -> V_4 = V_21 ;
V_54 -> V_13 = F_3 ( V_21 -> V_13 ) - 1 ;
V_54 -> V_61 = V_62 ;
F_55 ( V_2 , V_52 , & V_109 , type ) ;
F_56 ( V_52 , & V_110 ) ;
V_52 -> V_111 = V_21 -> V_112 ;
V_52 -> V_113 = 0 ;
F_57 ( V_84 , V_52 ) ;
return 0 ;
}
