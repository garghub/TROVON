void
F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_6 * V_7 ;
struct V_8 * V_8 ;
struct V_9 * V_10 ;
struct V_11 * V_11 ;
F_2 (connector, &dev->mode_config.connector_list, head) {
V_8 = F_3 ( V_7 ) ;
F_2 (encoder, &dev->mode_config.encoder_list, head) {
V_11 = F_4 ( V_10 ) ;
if ( V_11 -> V_12 & V_8 -> V_12 ) {
F_5 ( V_7 , V_10 ) ;
if ( V_11 -> V_12 & ( V_13 ) ) {
F_6 ( V_11 , V_7 ) ;
V_4 -> V_14 . V_15 = V_11 ;
}
}
}
}
}
void F_7 ( struct V_9 * V_10 )
{
struct V_1 * V_2 = V_10 -> V_2 ;
struct V_11 * V_11 = F_4 ( V_10 ) ;
struct V_6 * V_7 ;
F_2 (connector, &dev->mode_config.connector_list, head) {
if ( V_7 -> V_10 == V_10 ) {
struct V_8 * V_8 = F_3 ( V_7 ) ;
V_11 -> V_16 = V_11 -> V_12 & V_8 -> V_12 ;
F_8 ( L_1 ,
V_11 -> V_16 , V_11 -> V_12 ,
V_8 -> V_12 , V_10 -> V_17 ) ;
}
}
}
struct V_6 *
F_9 ( struct V_9 * V_10 )
{
struct V_1 * V_2 = V_10 -> V_2 ;
struct V_11 * V_11 = F_4 ( V_10 ) ;
struct V_6 * V_7 ;
struct V_8 * V_8 ;
F_2 (connector, &dev->mode_config.connector_list, head) {
V_8 = F_3 ( V_7 ) ;
if ( V_11 -> V_16 & V_8 -> V_12 )
return V_7 ;
}
return NULL ;
}
struct V_6 *
F_10 ( struct V_9 * V_10 )
{
struct V_1 * V_2 = V_10 -> V_2 ;
struct V_11 * V_11 = F_4 ( V_10 ) ;
struct V_6 * V_7 ;
struct V_8 * V_8 ;
F_2 (connector, &dev->mode_config.connector_list, head) {
V_8 = F_3 ( V_7 ) ;
if ( V_11 -> V_12 & V_8 -> V_12 )
return V_7 ;
}
return NULL ;
}
struct V_9 * F_11 ( struct V_9 * V_10 )
{
struct V_1 * V_2 = V_10 -> V_2 ;
struct V_11 * V_11 = F_4 ( V_10 ) ;
struct V_9 * V_18 ;
struct V_11 * V_19 ;
if ( V_11 -> V_20 )
return NULL ;
F_2 (other_encoder, &dev->mode_config.encoder_list, head) {
if ( V_18 == V_10 )
continue;
V_19 = F_4 ( V_18 ) ;
if ( V_19 -> V_20 &&
( V_11 -> V_12 & V_19 -> V_12 ) )
return V_18 ;
}
return NULL ;
}
T_1 F_12 ( struct V_9 * V_10 )
{
struct V_9 * V_18 = F_11 ( V_10 ) ;
if ( V_18 ) {
struct V_11 * V_11 = F_4 ( V_18 ) ;
switch ( V_11 -> V_21 ) {
case V_22 :
case V_23 :
return V_11 -> V_21 ;
default:
return V_24 ;
}
}
return V_24 ;
}
void F_13 ( struct V_9 * V_10 ,
struct V_25 * V_26 )
{
struct V_11 * V_11 = F_4 ( V_10 ) ;
struct V_25 * V_27 = & V_11 -> V_27 ;
unsigned V_28 = V_27 -> V_29 - V_27 -> V_30 ;
unsigned V_31 = V_27 -> V_32 - V_27 -> V_33 ;
unsigned V_34 = V_27 -> V_35 - V_27 -> V_30 ;
unsigned V_36 = V_27 -> V_37 - V_27 -> V_33 ;
unsigned V_38 = V_27 -> V_39 - V_27 -> V_35 ;
unsigned V_40 = V_27 -> V_41 - V_27 -> V_37 ;
V_26 -> clock = V_27 -> clock ;
V_26 -> V_42 = V_27 -> V_42 ;
V_26 -> V_30 = V_27 -> V_30 ;
V_26 -> V_33 = V_27 -> V_33 ;
V_26 -> V_29 = V_27 -> V_30 + V_28 ;
V_26 -> V_35 = V_27 -> V_30 + V_34 ;
V_26 -> V_39 = V_26 -> V_35 + V_38 ;
V_26 -> V_32 = V_27 -> V_33 + V_31 ;
V_26 -> V_37 = V_27 -> V_33 + V_36 ;
V_26 -> V_41 = V_26 -> V_37 + V_40 ;
F_14 ( V_26 , V_43 ) ;
V_26 -> V_44 = V_27 -> V_30 ;
V_26 -> V_45 = V_27 -> V_33 ;
V_26 -> V_46 = V_26 -> V_44 + V_28 ;
V_26 -> V_47 = V_26 -> V_44 + V_34 ;
V_26 -> V_48 = V_26 -> V_47 + V_38 ;
V_26 -> V_49 = V_26 -> V_45 + V_31 ;
V_26 -> V_50 = V_26 -> V_45 + V_36 ;
V_26 -> V_51 = V_26 -> V_50 + V_40 ;
}
bool F_15 ( struct V_9 * V_10 ,
T_2 V_52 )
{
struct V_6 * V_7 ;
struct V_8 * V_8 ;
struct V_53 * V_54 ;
V_7 = F_9 ( V_10 ) ;
if ( ! V_7 )
V_7 = F_10 ( V_10 ) ;
V_8 = F_3 ( V_7 ) ;
switch ( V_7 -> V_55 ) {
case V_56 :
case V_57 :
if ( V_8 -> V_58 ) {
if ( F_16 ( F_17 ( V_7 ) ) ) {
if ( V_52 > 340000 )
return true ;
else
return false ;
} else {
if ( V_52 > 165000 )
return true ;
else
return false ;
}
} else
return false ;
case V_59 :
case V_60 :
case V_61 :
V_54 = V_8 -> V_62 ;
if ( ( V_54 -> V_63 == V_64 ) ||
( V_54 -> V_63 == V_65 ) )
return false ;
else {
if ( F_16 ( F_17 ( V_7 ) ) ) {
if ( V_52 > 340000 )
return true ;
else
return false ;
} else {
if ( V_52 > 165000 )
return true ;
else
return false ;
}
}
default:
return false ;
}
}
