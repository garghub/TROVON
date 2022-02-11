static void
F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_3 ( V_2 ) ;
struct V_5 * V_6 = V_2 -> V_6 ;
struct V_7 * V_8 = F_2 ( V_6 ) -> V_9 ;
int V_10 ;
if ( ! V_4 -> V_11 )
return;
F_3 ( F_4 ( V_4 -> V_11 ) , true ) ;
F_5 ( V_6 , L_1 , V_4 -> V_12 ) ;
V_10 = F_6 ( V_8 , 4 ) ;
if ( V_10 ) {
F_7 ( V_6 , L_2 ) ;
return;
}
F_8 ( V_8 , 0 , F_9 ( V_4 -> V_12 , V_13 ) , 1 ) ;
F_10 ( V_8 , 0 ) ;
F_8 ( V_8 , 0 , V_14 , 1 ) ;
F_10 ( V_8 , 0 ) ;
V_4 -> V_11 = NULL ;
V_4 -> V_15 = V_16 ;
}
static void
F_11 ( struct V_1 * V_2 , int V_17 )
{
struct V_5 * V_6 = V_2 -> V_6 ;
struct V_3 * V_4 = V_3 ( V_2 ) ;
struct V_1 * V_18 ;
T_1 V_19 ;
int V_12 = V_4 -> V_12 ;
F_5 ( V_6 , L_3 , V_12 , V_4 -> V_20 -> type , V_17 ) ;
V_4 -> V_15 = V_17 ;
F_12 (enc, &dev->mode_config.encoder_list, head) {
struct V_3 * V_21 = V_3 ( V_18 ) ;
if ( V_21 == V_4 ||
( V_21 -> V_20 -> type != V_22 &&
V_21 -> V_20 -> type != V_23 &&
V_21 -> V_20 -> type != V_24 ) ||
V_21 -> V_20 -> V_12 != V_4 -> V_20 -> V_12 )
continue;
if ( V_21 -> V_15 == V_25 )
return;
}
if ( ! F_13 ( V_6 , F_14 ( V_12 ) ,
V_26 , 0 ) ) {
F_7 ( V_6 , L_4 , V_12 ) ;
F_7 ( V_6 , L_5 , V_12 ,
F_15 ( V_6 , F_14 ( V_12 ) ) ) ;
}
V_19 = F_15 ( V_6 , F_14 ( V_12 ) ) ;
if ( V_17 == V_25 )
V_19 |= V_27 ;
else
V_19 &= ~ V_27 ;
F_16 ( V_6 , F_14 ( V_12 ) , V_19 |
V_26 ) ;
if ( ! F_13 ( V_6 , F_17 ( V_12 ) ,
V_28 , 0 ) ) {
F_7 ( V_6 , L_6 , V_12 ) ;
F_7 ( V_6 , L_7 , V_12 ,
F_15 ( V_6 , F_17 ( V_12 ) ) ) ;
}
if ( V_4 -> V_20 -> type == V_24 ) {
struct V_29 * V_30 ;
V_30 = F_18 ( V_6 , V_4 -> V_20 -> V_31 ) ;
if ( ! V_30 )
return;
if ( V_17 == V_25 ) {
T_2 V_32 = V_33 ;
F_19 ( V_30 , 8 , V_34 , & V_32 , 1 ) ;
F_20 ( V_2 ) ;
} else {
T_2 V_32 = V_35 ;
F_19 ( V_30 , 8 , V_34 , & V_32 , 1 ) ;
}
}
}
static void
F_21 ( struct V_1 * V_2 )
{
F_7 ( V_2 -> V_6 , L_8 ) ;
}
static void
F_22 ( struct V_1 * V_2 )
{
F_7 ( V_2 -> V_6 , L_8 ) ;
}
static bool
F_23 ( struct V_1 * V_2 , struct V_36 * V_17 ,
struct V_36 * V_37 )
{
struct V_3 * V_4 = V_3 ( V_2 ) ;
struct V_38 * V_39 ;
F_5 ( V_2 -> V_6 , L_9 , V_4 -> V_12 ) ;
V_39 = F_24 ( V_4 ) ;
if ( ! V_39 ) {
F_7 ( V_2 -> V_6 , L_10 ) ;
return false ;
}
if ( V_39 -> V_40 != V_41 &&
V_39 -> V_42 ) {
int V_43 = V_37 -> V_44 . V_43 ;
* V_37 = * V_39 -> V_42 ;
V_37 -> V_44 . V_43 = V_43 ;
}
return true ;
}
static void
F_25 ( struct V_1 * V_2 )
{
}
static void
F_26 ( struct V_1 * V_2 )
{
}
static void
F_27 ( struct V_1 * V_2 , struct V_36 * V_17 ,
struct V_36 * V_37 )
{
struct V_7 * V_8 = F_2 ( V_2 -> V_6 ) -> V_9 ;
struct V_3 * V_4 = V_3 ( V_2 ) ;
struct V_5 * V_6 = V_2 -> V_6 ;
struct F_4 * V_11 = F_4 ( V_2 -> V_11 ) ;
T_1 V_45 = 0 ;
int V_10 ;
F_5 ( V_6 , L_11 ,
V_4 -> V_12 , V_4 -> V_20 -> type , V_11 -> V_46 ) ;
F_11 ( V_2 , V_25 ) ;
switch ( V_4 -> V_20 -> type ) {
case V_22 :
if ( V_4 -> V_20 -> V_47 . V_48 & 1 ) {
if ( V_37 -> clock < 165000 )
V_45 = 0x0100 ;
else
V_45 = 0x0500 ;
} else
V_45 = 0x0200 ;
break;
case V_24 :
V_45 |= ( V_4 -> V_49 . V_50 << 16 ) ;
if ( V_4 -> V_20 -> V_47 . V_48 & 1 )
V_45 |= 0x00000800 ;
else
V_45 |= 0x00000900 ;
break;
default:
break;
}
if ( V_11 -> V_46 == 1 )
V_45 |= V_51 ;
else
V_45 |= V_52 ;
if ( V_37 -> V_53 & V_54 )
V_45 |= V_55 ;
if ( V_37 -> V_53 & V_56 )
V_45 |= V_57 ;
V_10 = F_6 ( V_8 , 2 ) ;
if ( V_10 ) {
F_7 ( V_6 , L_12 ) ;
return;
}
F_8 ( V_8 , 0 , F_9 ( V_4 -> V_12 , V_13 ) , 1 ) ;
F_10 ( V_8 , V_45 ) ;
V_4 -> V_11 = V_2 -> V_11 ;
}
static struct V_58 *
F_28 ( struct V_1 * V_2 )
{
return V_3 ( V_2 ) -> V_11 ;
}
static void
F_29 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_3 ( V_2 ) ;
if ( ! V_2 )
return;
F_5 ( V_2 -> V_6 , L_13 ) ;
F_30 ( V_2 ) ;
F_31 ( V_4 ) ;
}
int
F_32 ( struct V_59 * V_39 , struct V_60 * V_61 )
{
struct V_3 * V_4 = NULL ;
struct V_5 * V_6 = V_39 -> V_6 ;
struct V_1 * V_2 ;
int type ;
F_5 ( V_6 , L_13 ) ;
switch ( V_61 -> type ) {
case V_22 :
case V_24 :
type = V_62 ;
break;
case V_23 :
type = V_63 ;
break;
default:
return - V_64 ;
}
V_4 = F_33 ( sizeof( * V_4 ) , V_65 ) ;
if ( ! V_4 )
return - V_66 ;
V_2 = F_34 ( V_4 ) ;
V_4 -> V_20 = V_61 ;
V_4 -> V_12 = F_35 ( V_61 -> V_12 ) - 1 ;
V_4 -> V_15 = V_16 ;
F_36 ( V_6 , V_2 , & V_67 , type ) ;
F_37 ( V_2 , & V_68 ) ;
V_2 -> V_69 = V_61 -> V_70 ;
V_2 -> V_71 = 0 ;
if ( V_4 -> V_20 -> type == V_24 ) {
int V_12 = V_4 -> V_12 , V_48 = ! ( V_61 -> V_72 . V_73 . V_48 & 1 ) ;
T_1 V_74 ;
V_74 = F_15 ( V_6 , 0x61c700 + ( V_12 * 0x800 ) ) ;
if ( ! V_74 )
V_74 = F_15 ( V_6 , 0x610798 + ( V_12 * 8 ) ) ;
switch ( ( V_74 & 0x00000f00 ) >> 8 ) {
case 8 :
case 9 :
V_4 -> V_49 . V_50 = ( V_74 & 0x000f0000 ) >> 16 ;
V_74 = F_15 ( V_6 , F_38 ( V_12 , V_48 ) ) ;
V_4 -> V_49 . V_75 = V_74 & 0x000001fc ;
V_74 = F_15 ( V_6 , F_39 ( V_12 , V_48 ) ) ;
V_4 -> V_49 . V_76 = V_74 & 0x010f7f3f ;
break;
default:
break;
}
if ( ! V_4 -> V_49 . V_50 )
V_4 -> V_49 . V_50 = 5 ;
}
F_40 ( V_39 , V_2 ) ;
return 0 ;
}
