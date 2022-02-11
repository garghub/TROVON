static T_1
F_1 ( struct V_1 * V_2 , struct V_3 * V_4 , T_2 V_5 )
{
struct V_6 * V_7 = V_6 ( V_2 ) ;
static const T_2 V_8 [] = { 24 , 16 , 8 , 0 } ;
static const T_2 V_9 [] = { 16 , 8 , 0 , 24 } ;
if ( F_2 ( V_7 -> V_10 ) -> V_11 == 0xaf )
return V_8 [ V_5 ] ;
return V_9 [ V_5 ] ;
}
static void
F_3 ( struct V_1 * V_2 , struct V_3 * V_4 , T_2 V_12 )
{
struct V_13 * V_10 = F_4 ( V_2 ) ;
T_1 V_14 = F_5 ( V_4 -> V_14 ) - 1 , V_15 = ! ( V_4 -> V_16 . V_15 & 1 ) ;
F_6 ( V_10 , F_7 ( V_14 , V_15 ) , 0x0f000000 , V_12 << 24 ) ;
}
static void
F_8 ( struct V_1 * V_2 , struct V_3 * V_4 ,
T_2 V_5 , T_2 V_17 , T_2 V_18 )
{
struct V_13 * V_10 = F_4 ( V_2 ) ;
struct V_6 * V_7 = V_6 ( V_2 ) ;
T_1 V_14 = F_5 ( V_4 -> V_14 ) - 1 , V_15 = ! ( V_4 -> V_16 . V_15 & 1 ) ;
T_1 V_19 = F_1 ( V_2 , V_4 , V_5 ) ;
T_1 V_20 = 0x000000ff << V_19 ;
T_2 * V_21 , * V_22 , * V_23 ;
V_21 = F_9 ( V_2 , V_4 , & V_22 ) ;
if ( ! V_21 || ( V_21 [ 0 ] != 0x20 && V_21 [ 0 ] != 0x21 ) ) {
F_10 ( V_7 , L_1 ) ;
return;
}
V_23 = V_22 + V_21 [ 4 ] ;
while ( V_23 [ 0 ] != V_17 || V_23 [ 1 ] != V_18 ) {
V_23 += V_21 [ 5 ] ;
if ( V_23 >= V_22 + V_21 [ 4 ] + V_22 [ 4 ] * V_21 [ 5 ] )
return;
}
F_6 ( V_10 , F_11 ( V_14 , V_15 ) , V_20 , V_23 [ 2 ] << V_19 ) ;
F_6 ( V_10 , F_12 ( V_14 , V_15 ) , V_20 , V_23 [ 3 ] << V_19 ) ;
F_6 ( V_10 , F_13 ( V_14 , V_15 ) , 0x0000ff00 , V_23 [ 4 ] << 8 ) ;
}
static void
F_14 ( struct V_1 * V_2 , struct V_3 * V_4 , int V_24 ,
int V_25 , T_1 V_26 , bool V_27 )
{
struct V_13 * V_10 = F_4 ( V_2 ) ;
struct V_6 * V_7 = V_6 ( V_2 ) ;
T_1 V_14 = F_5 ( V_4 -> V_14 ) - 1 , V_15 = ! ( V_4 -> V_16 . V_15 & 1 ) ;
T_1 V_28 = F_15 ( V_10 , F_7 ( V_14 , V_15 ) ) & ~ 0x001f4000 ;
T_1 V_29 = F_15 ( V_10 , 0x614300 + ( V_14 * 0x800 ) ) & ~ 0x000c0000 ;
T_2 * V_21 , * V_22 , V_20 ;
int V_30 ;
V_21 = F_9 ( V_2 , V_4 , & V_22 ) ;
if ( ! V_21 || ( V_21 [ 0 ] != 0x20 && V_21 [ 0 ] != 0x21 ) ) {
F_10 ( V_7 , L_1 ) ;
return;
}
V_22 = F_16 ( V_2 , V_22 [ 10 ] ) ;
if ( V_22 ) {
while ( V_26 < F_17 ( V_22 [ 0 ] ) * 10 )
V_22 += 4 ;
F_18 ( V_2 , F_17 ( V_22 [ 2 ] ) , V_4 , V_24 ) ;
}
V_28 |= ( ( 1 << V_25 ) - 1 ) << 16 ;
if ( V_27 )
V_28 |= 0x00004000 ;
if ( V_26 > 162000 )
V_29 |= 0x00040000 ;
F_19 ( V_10 , 0x614300 + ( V_14 * 0x800 ) , V_29 ) ;
F_19 ( V_10 , F_7 ( V_14 , V_15 ) , V_28 ) ;
V_20 = 0 ;
for ( V_30 = 0 ; V_30 < V_25 ; V_30 ++ )
V_20 |= 1 << ( F_1 ( V_2 , V_4 , V_30 ) >> 3 ) ;
F_6 ( V_10 , F_13 ( V_14 , V_15 ) , 0x0000000f , V_20 ) ;
}
static void
F_20 ( struct V_1 * V_2 , T_1 V_14 , T_1 V_15 , T_1 * V_31 , T_1 * V_32 )
{
struct V_13 * V_10 = F_4 ( V_2 ) ;
T_1 V_28 = F_15 ( V_10 , F_7 ( V_14 , V_15 ) ) & 0x000f0000 ;
T_1 V_29 = F_15 ( V_10 , 0x614300 + ( V_14 * 0x800 ) ) ;
if ( V_29 & 0x000c0000 )
* V_32 = 270000 ;
else
* V_32 = 162000 ;
if ( V_28 > 0x00030000 ) * V_31 = 4 ;
else if ( V_28 > 0x00010000 ) * V_31 = 2 ;
else * V_31 = 1 ;
}
void
F_21 ( struct V_1 * V_2 , int V_14 , int V_15 , T_1 V_33 , T_1 V_34 )
{
struct V_13 * V_10 = F_4 ( V_2 ) ;
struct V_6 * V_7 = V_6 ( V_2 ) ;
const T_1 V_35 = 100000 ;
int V_36 = 0 , V_37 = 0 , V_38 = 0 , V_39 = 0 ;
int V_40 , V_41 , V_42 , V_43 ;
T_3 V_44 , V_45 , V_46 ;
T_1 V_47 = 64 * V_35 ;
T_1 V_25 , V_26 , V_48 ;
F_20 ( V_2 , V_14 , V_15 , & V_25 , & V_26 ) ;
V_44 = ( V_33 * V_34 / 8 ) / V_25 ;
V_45 = V_44 * V_35 ;
V_48 = F_22 ( V_45 , V_26 ) ;
for ( V_40 = 64 ; V_40 >= 32 ; V_40 -- ) {
T_1 V_49 = V_45 * V_40 ;
T_1 V_50 , V_51 ;
V_41 = V_49 / V_35 ;
V_50 = V_41 * V_35 ;
V_51 = V_49 - V_50 ;
if ( V_51 ) {
if ( V_51 >= ( V_35 / 2 ) ) {
V_42 = V_35 / ( V_35 - V_51 ) ;
if ( V_35 - ( V_42 * V_51 ) )
V_42 ++ ;
if ( V_42 <= 15 ) {
V_43 = 1 ;
V_50 += V_35 - ( V_35 / V_42 ) ;
} else {
V_43 = 0 ;
V_42 = 1 ;
V_50 += V_35 ;
}
} else {
V_43 = 0 ;
V_42 = F_23 ( ( int ) ( V_35 / V_51 ) , 15 ) ;
V_50 += V_35 / V_42 ;
}
V_51 = V_50 - V_49 ;
} else {
V_43 = 0 ;
V_42 = 1 ;
V_41 -- ;
}
if ( V_51 < V_47 ) {
V_47 = V_51 ;
V_36 = V_40 ;
V_39 = V_43 ;
V_38 = V_42 ;
V_37 = V_41 ;
if ( V_51 == 0 )
break;
}
}
if ( ! V_36 ) {
F_10 ( V_7 , L_2 ) ;
return;
}
V_46 = ( V_35 - V_45 ) * V_36 ;
V_46 *= V_45 ;
V_48 = F_22 ( V_46 , V_35 ) ;
V_48 = F_22 ( V_46 , V_35 ) ;
V_46 += 6 ;
F_6 ( V_10 , F_7 ( V_14 , V_15 ) , 0x000001fc , V_36 << 2 ) ;
F_6 ( V_10 , F_24 ( V_14 , V_15 ) , 0x010f7f3f , V_39 << 24 |
V_38 << 16 |
V_37 << 8 |
V_46 ) ;
}
static void
F_25 ( struct V_52 * V_53 )
{
struct V_54 * V_55 = V_54 ( V_53 ) ;
struct V_6 * V_7 = V_6 ( V_53 -> V_2 ) ;
struct V_1 * V_2 = V_53 -> V_2 ;
struct V_56 * V_57 = F_26 ( V_2 ) -> V_58 ;
int V_59 ;
if ( ! V_55 -> V_24 )
return;
F_27 ( F_28 ( V_55 -> V_24 ) , true ) ;
F_29 ( V_7 , L_3 , V_55 -> V_14 ) ;
V_59 = F_30 ( V_57 , 4 ) ;
if ( V_59 ) {
F_10 ( V_7 , L_4 ) ;
return;
}
F_31 ( V_57 , 0 , F_32 ( V_55 -> V_14 , V_60 ) , 1 ) ;
F_33 ( V_57 , 0 ) ;
F_31 ( V_57 , 0 , V_61 , 1 ) ;
F_33 ( V_57 , 0 ) ;
F_34 ( V_53 , NULL ) ;
V_55 -> V_24 = NULL ;
V_55 -> V_62 = V_63 ;
}
static void
F_35 ( struct V_52 * V_53 , int V_64 )
{
struct V_13 * V_10 = F_4 ( V_53 -> V_2 ) ;
struct V_6 * V_7 = V_6 ( V_53 -> V_2 ) ;
struct V_1 * V_2 = V_53 -> V_2 ;
struct V_54 * V_55 = V_54 ( V_53 ) ;
struct V_52 * V_65 ;
T_4 V_66 ;
int V_14 = V_55 -> V_14 ;
F_29 ( V_7 , L_5 , V_14 , V_55 -> V_4 -> type , V_64 ) ;
V_55 -> V_62 = V_64 ;
F_36 (enc, &dev->mode_config.encoder_list, head) {
struct V_54 * V_67 = V_54 ( V_65 ) ;
if ( V_67 == V_55 ||
( V_67 -> V_4 -> type != V_68 &&
V_67 -> V_4 -> type != V_69 &&
V_67 -> V_4 -> type != V_70 ) ||
V_67 -> V_4 -> V_14 != V_55 -> V_4 -> V_14 )
continue;
if ( V_67 -> V_62 == V_71 )
return;
}
if ( ! F_37 ( V_10 , F_38 ( V_14 ) ,
V_72 , 0 ) ) {
F_10 ( V_7 , L_6 , V_14 ) ;
F_10 ( V_7 , L_7 , V_14 ,
F_15 ( V_10 , F_38 ( V_14 ) ) ) ;
}
V_66 = F_15 ( V_10 , F_38 ( V_14 ) ) ;
if ( V_64 == V_71 )
V_66 |= V_73 ;
else
V_66 &= ~ V_73 ;
F_19 ( V_10 , F_38 ( V_14 ) , V_66 |
V_72 ) ;
if ( ! F_37 ( V_10 , F_39 ( V_14 ) ,
V_74 , 0 ) ) {
F_10 ( V_7 , L_8 , V_14 ) ;
F_10 ( V_7 , L_9 , V_14 ,
F_15 ( V_10 , F_39 ( V_14 ) ) ) ;
}
if ( V_55 -> V_4 -> type == V_70 ) {
struct V_75 V_76 = {
. V_77 = F_14 ,
. V_78 = F_3 ,
. V_79 = F_8
} ;
F_40 ( V_53 , V_64 , V_55 -> V_80 . V_81 , & V_76 ) ;
}
}
static void
F_41 ( struct V_52 * V_53 )
{
struct V_6 * V_7 = V_6 ( V_53 -> V_2 ) ;
F_10 ( V_7 , L_10 ) ;
}
static void
F_42 ( struct V_52 * V_53 )
{
struct V_6 * V_7 = V_6 ( V_53 -> V_2 ) ;
F_10 ( V_7 , L_10 ) ;
}
static bool
F_43 ( struct V_52 * V_53 ,
const struct V_82 * V_64 ,
struct V_82 * V_83 )
{
struct V_6 * V_7 = V_6 ( V_53 -> V_2 ) ;
struct V_54 * V_55 = V_54 ( V_53 ) ;
struct V_84 * V_85 ;
F_29 ( V_7 , L_11 , V_55 -> V_14 ) ;
V_85 = F_44 ( V_55 ) ;
if ( ! V_85 ) {
F_10 ( V_7 , L_12 ) ;
return false ;
}
if ( V_85 -> V_86 != V_87 &&
V_85 -> V_88 )
F_45 ( V_83 , V_85 -> V_88 ) ;
return true ;
}
static void
F_46 ( struct V_52 * V_53 )
{
struct V_54 * V_55 = V_54 ( V_53 ) ;
F_25 ( V_53 ) ;
if ( V_55 -> V_4 -> type == V_70 ) {
F_47 ( V_53 -> V_2 ) ;
}
}
static void
F_48 ( struct V_52 * V_53 )
{
}
static void
F_49 ( struct V_52 * V_53 , struct V_82 * V_89 ,
struct V_82 * V_64 )
{
struct V_56 * V_57 = F_26 ( V_53 -> V_2 ) -> V_58 ;
struct V_54 * V_55 = V_54 ( V_53 ) ;
struct V_6 * V_7 = V_6 ( V_53 -> V_2 ) ;
struct F_28 * V_24 = F_28 ( V_53 -> V_24 ) ;
struct V_84 * V_90 ;
T_4 V_91 = 0 ;
int V_59 ;
F_29 ( V_7 , L_13 ,
V_55 -> V_14 , V_55 -> V_4 -> type , V_24 -> V_92 ) ;
V_55 -> V_24 = V_53 -> V_24 ;
switch ( V_55 -> V_4 -> type ) {
case V_68 :
if ( V_55 -> V_4 -> V_16 . V_15 & 1 ) {
if ( V_64 -> clock < 165000 )
V_91 = 0x0100 ;
else
V_91 = 0x0500 ;
} else
V_91 = 0x0200 ;
F_34 ( V_53 , V_64 ) ;
break;
case V_70 :
V_90 = F_44 ( V_55 ) ;
if ( V_90 && V_90 -> V_93 . V_94 . V_95 == 6 ) {
V_55 -> V_80 . V_81 = V_64 -> clock * 18 / 8 ;
V_91 |= 0x00020000 ;
} else {
V_55 -> V_80 . V_81 = V_64 -> clock * 24 / 8 ;
V_91 |= 0x00050000 ;
}
if ( V_55 -> V_4 -> V_16 . V_15 & 1 )
V_91 |= 0x00000800 ;
else
V_91 |= 0x00000900 ;
break;
default:
break;
}
if ( V_24 -> V_92 == 1 )
V_91 |= V_96 ;
else
V_91 |= V_97 ;
if ( V_64 -> V_98 & V_99 )
V_91 |= V_100 ;
if ( V_64 -> V_98 & V_101 )
V_91 |= V_102 ;
F_35 ( V_53 , V_71 ) ;
V_59 = F_30 ( V_57 , 2 ) ;
if ( V_59 ) {
F_10 ( V_7 , L_14 ) ;
V_55 -> V_24 = NULL ;
return;
}
F_31 ( V_57 , 0 , F_32 ( V_55 -> V_14 , V_60 ) , 1 ) ;
F_33 ( V_57 , V_91 ) ;
}
static struct V_103 *
F_50 ( struct V_52 * V_53 )
{
return V_54 ( V_53 ) -> V_24 ;
}
static void
F_51 ( struct V_52 * V_53 )
{
struct V_54 * V_55 = V_54 ( V_53 ) ;
struct V_6 * V_7 = V_6 ( V_53 -> V_2 ) ;
F_29 ( V_7 , L_15 ) ;
F_52 ( V_53 ) ;
F_53 ( V_55 ) ;
}
int
F_54 ( struct V_104 * V_85 , struct V_3 * V_22 )
{
struct V_54 * V_55 = NULL ;
struct V_1 * V_2 = V_85 -> V_2 ;
struct V_6 * V_7 = V_6 ( V_2 ) ;
struct V_52 * V_53 ;
int type ;
F_29 ( V_7 , L_15 ) ;
switch ( V_22 -> type ) {
case V_68 :
case V_70 :
type = V_105 ;
break;
case V_69 :
type = V_106 ;
break;
default:
return - V_107 ;
}
V_55 = F_55 ( sizeof( * V_55 ) , V_108 ) ;
if ( ! V_55 )
return - V_109 ;
V_53 = F_56 ( V_55 ) ;
V_55 -> V_4 = V_22 ;
V_55 -> V_14 = F_5 ( V_22 -> V_14 ) - 1 ;
V_55 -> V_62 = V_63 ;
F_57 ( V_2 , V_53 , & V_110 , type ) ;
F_58 ( V_53 , & V_111 ) ;
V_53 -> V_112 = V_22 -> V_113 ;
V_53 -> V_114 = 0 ;
F_59 ( V_85 , V_53 ) ;
return 0 ;
}
