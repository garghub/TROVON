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
F_20 ( V_2 , V_4 -> V_35 . V_36 ) ;
} else {
T_2 V_32 = V_37 ;
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
F_23 ( struct V_1 * V_2 , struct V_38 * V_17 ,
struct V_38 * V_39 )
{
struct V_3 * V_4 = V_3 ( V_2 ) ;
struct V_40 * V_41 ;
F_5 ( V_2 -> V_6 , L_9 , V_4 -> V_12 ) ;
V_41 = F_24 ( V_4 ) ;
if ( ! V_41 ) {
F_7 ( V_2 -> V_6 , L_10 ) ;
return false ;
}
if ( V_41 -> V_42 != V_43 &&
V_41 -> V_44 ) {
int V_45 = V_39 -> V_46 . V_45 ;
* V_39 = * V_41 -> V_44 ;
V_39 -> V_46 . V_45 = V_45 ;
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
F_27 ( struct V_1 * V_2 , struct V_38 * V_17 ,
struct V_38 * V_39 )
{
struct V_7 * V_8 = F_2 ( V_2 -> V_6 ) -> V_9 ;
struct V_3 * V_4 = V_3 ( V_2 ) ;
struct V_5 * V_6 = V_2 -> V_6 ;
struct F_4 * V_11 = F_4 ( V_2 -> V_11 ) ;
struct V_40 * V_47 ;
T_1 V_48 = 0 ;
int V_10 ;
F_5 ( V_6 , L_11 ,
V_4 -> V_12 , V_4 -> V_20 -> type , V_11 -> V_49 ) ;
switch ( V_4 -> V_20 -> type ) {
case V_22 :
if ( V_4 -> V_20 -> V_50 . V_51 & 1 ) {
if ( V_39 -> clock < 165000 )
V_48 = 0x0100 ;
else
V_48 = 0x0500 ;
} else
V_48 = 0x0200 ;
break;
case V_24 :
V_47 = F_24 ( V_4 ) ;
if ( V_47 && V_47 -> V_46 . V_52 . V_53 == 6 ) {
V_4 -> V_35 . V_36 = V_11 -> V_17 -> clock * 18 / 8 ;
V_48 |= 0x00020000 ;
} else {
V_4 -> V_35 . V_36 = V_11 -> V_17 -> clock * 24 / 8 ;
V_48 |= 0x00050000 ;
}
if ( V_4 -> V_20 -> V_50 . V_51 & 1 )
V_48 |= 0x00000800 ;
else
V_48 |= 0x00000900 ;
break;
default:
break;
}
if ( V_11 -> V_49 == 1 )
V_48 |= V_54 ;
else
V_48 |= V_55 ;
if ( V_39 -> V_56 & V_57 )
V_48 |= V_58 ;
if ( V_39 -> V_56 & V_59 )
V_48 |= V_60 ;
F_11 ( V_2 , V_25 ) ;
V_10 = F_6 ( V_8 , 2 ) ;
if ( V_10 ) {
F_7 ( V_6 , L_12 ) ;
return;
}
F_8 ( V_8 , 0 , F_9 ( V_4 -> V_12 , V_13 ) , 1 ) ;
F_10 ( V_8 , V_48 ) ;
V_4 -> V_11 = V_2 -> V_11 ;
}
static struct V_61 *
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
F_32 ( struct V_62 * V_41 , struct V_63 * V_64 )
{
struct V_3 * V_4 = NULL ;
struct V_5 * V_6 = V_41 -> V_6 ;
struct V_1 * V_2 ;
int type ;
F_5 ( V_6 , L_13 ) ;
switch ( V_64 -> type ) {
case V_22 :
case V_24 :
type = V_65 ;
break;
case V_23 :
type = V_66 ;
break;
default:
return - V_67 ;
}
V_4 = F_33 ( sizeof( * V_4 ) , V_68 ) ;
if ( ! V_4 )
return - V_69 ;
V_2 = F_34 ( V_4 ) ;
V_4 -> V_20 = V_64 ;
V_4 -> V_12 = F_35 ( V_64 -> V_12 ) - 1 ;
V_4 -> V_15 = V_16 ;
F_36 ( V_6 , V_2 , & V_70 , type ) ;
F_37 ( V_2 , & V_71 ) ;
V_2 -> V_72 = V_64 -> V_73 ;
V_2 -> V_74 = 0 ;
F_38 ( V_41 , V_2 ) ;
return 0 ;
}
