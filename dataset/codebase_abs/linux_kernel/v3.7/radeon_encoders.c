static T_1 F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_8 * V_8 = F_2 ( V_2 ) ;
struct V_1 * V_9 ;
T_1 V_10 = 0 ;
int V_11 ;
if ( V_6 -> V_12 >= V_13 )
return V_10 ;
if ( V_8 -> V_14 & V_15 )
return V_10 ;
if ( V_8 -> V_14 & V_16 )
return V_10 ;
V_11 = - 1 ;
F_3 (clone_encoder, &dev->mode_config.encoder_list, head) {
struct V_8 * V_17 = F_2 ( V_9 ) ;
V_11 ++ ;
if ( V_9 == V_2 )
continue;
if ( V_17 -> V_14 & ( V_15 ) )
continue;
if ( V_17 -> V_14 & V_16 )
continue;
else
V_10 |= ( 1 << V_11 ) ;
}
return V_10 ;
}
void F_4 ( struct V_3 * V_4 )
{
struct V_1 * V_2 ;
F_3 (encoder, &dev->mode_config.encoder_list, head) {
V_2 -> V_18 = F_1 ( V_2 ) ;
}
}
T_1
F_5 ( struct V_3 * V_4 , T_1 V_19 , T_2 V_20 )
{
struct V_5 * V_6 = V_4 -> V_7 ;
T_1 V_21 = 0 ;
switch ( V_19 ) {
case V_22 :
case V_23 :
case V_24 :
case V_25 :
case V_26 :
switch ( V_20 ) {
case 1 :
if ( ( V_6 -> V_12 == V_27 ) ||
( V_6 -> V_12 == V_28 ) ||
( V_6 -> V_12 == V_29 ) )
V_21 = V_30 ;
else if ( F_6 ( V_6 ) )
V_21 = V_31 ;
else
V_21 = V_32 ;
break;
case 2 :
if ( F_6 ( V_6 ) )
V_21 = V_33 ;
else {
V_21 = V_30 ;
}
break;
case 3 :
if ( F_6 ( V_6 ) )
V_21 = V_34 ;
else
V_21 = V_35 ;
break;
}
break;
case V_36 :
if ( F_6 ( V_6 ) )
V_21 = V_37 ;
else
V_21 = V_38 ;
break;
case V_39 :
if ( ( V_6 -> V_12 == V_27 ) ||
( V_6 -> V_12 == V_28 ) ||
( V_6 -> V_12 == V_29 ) )
V_21 = V_35 ;
else if ( F_6 ( V_6 ) )
V_21 = V_40 ;
else
V_21 = V_41 ;
break;
case V_42 :
case V_16 :
if ( ( V_6 -> V_12 == V_43 ) ||
( V_6 -> V_12 == V_44 ) ||
( V_6 -> V_12 == V_45 ) )
V_21 = V_46 ;
else if ( F_6 ( V_6 ) )
V_21 = V_34 ;
else
V_21 = V_35 ;
break;
case V_47 :
V_21 = V_37 ;
break;
}
return V_21 ;
}
void
F_7 ( struct V_3 * V_4 )
{
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_48 * V_49 ;
struct V_50 * V_50 ;
struct V_1 * V_2 ;
struct V_8 * V_8 ;
F_3 (connector, &dev->mode_config.connector_list, head) {
V_50 = F_8 ( V_49 ) ;
F_3 (encoder, &dev->mode_config.encoder_list, head) {
V_8 = F_2 ( V_2 ) ;
if ( V_8 -> V_14 & V_50 -> V_14 ) {
F_9 ( V_49 , V_2 ) ;
if ( V_8 -> V_14 & ( V_15 ) ) {
if ( V_6 -> V_51 )
F_10 ( V_8 , V_49 ) ;
else
F_11 ( V_8 , V_49 ) ;
V_6 -> V_52 . V_53 = V_8 ;
}
}
}
}
}
void F_12 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_8 * V_8 = F_2 ( V_2 ) ;
struct V_48 * V_49 ;
F_3 (connector, &dev->mode_config.connector_list, head) {
if ( V_49 -> V_2 == V_2 ) {
struct V_50 * V_50 = F_8 ( V_49 ) ;
V_8 -> V_54 = V_8 -> V_14 & V_50 -> V_14 ;
F_13 ( L_1 ,
V_8 -> V_54 , V_8 -> V_14 ,
V_50 -> V_14 , V_2 -> V_55 ) ;
}
}
}
struct V_48 *
F_14 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_8 * V_8 = F_2 ( V_2 ) ;
struct V_48 * V_49 ;
struct V_50 * V_50 ;
F_3 (connector, &dev->mode_config.connector_list, head) {
V_50 = F_8 ( V_49 ) ;
if ( V_8 -> V_54 & V_50 -> V_14 )
return V_49 ;
}
return NULL ;
}
struct V_48 *
F_15 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_8 * V_8 = F_2 ( V_2 ) ;
struct V_48 * V_49 ;
struct V_50 * V_50 ;
F_3 (connector, &dev->mode_config.connector_list, head) {
V_50 = F_8 ( V_49 ) ;
if ( V_8 -> V_14 & V_50 -> V_14 )
return V_49 ;
}
return NULL ;
}
struct V_1 * F_16 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_8 * V_8 = F_2 ( V_2 ) ;
struct V_1 * V_56 ;
struct V_8 * V_57 ;
if ( V_8 -> V_58 )
return NULL ;
F_3 (other_encoder, &dev->mode_config.encoder_list, head) {
if ( V_56 == V_2 )
continue;
V_57 = F_2 ( V_56 ) ;
if ( V_57 -> V_58 &&
( V_8 -> V_14 & V_57 -> V_14 ) )
return V_56 ;
}
return NULL ;
}
T_3 F_17 ( struct V_1 * V_2 )
{
struct V_1 * V_56 = F_16 ( V_2 ) ;
if ( V_56 ) {
struct V_8 * V_8 = F_2 ( V_56 ) ;
switch ( V_8 -> V_59 ) {
case V_60 :
case V_61 :
return V_8 -> V_59 ;
default:
return V_62 ;
}
}
return V_62 ;
}
void F_18 ( struct V_1 * V_2 ,
struct V_63 * V_64 )
{
struct V_8 * V_8 = F_2 ( V_2 ) ;
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_63 * V_65 = & V_8 -> V_65 ;
unsigned V_66 = V_65 -> V_67 - V_65 -> V_68 ;
unsigned V_69 = V_65 -> V_70 - V_65 -> V_71 ;
unsigned V_72 = V_65 -> V_73 - V_65 -> V_68 ;
unsigned V_74 = V_65 -> V_75 - V_65 -> V_71 ;
unsigned V_76 = V_65 -> V_77 - V_65 -> V_73 ;
unsigned V_78 = V_65 -> V_79 - V_65 -> V_75 ;
V_64 -> clock = V_65 -> clock ;
V_64 -> V_80 = V_65 -> V_80 ;
if ( F_6 ( V_6 ) ) {
V_64 -> V_68 = V_65 -> V_68 ;
V_64 -> V_71 = V_65 -> V_71 ;
}
V_64 -> V_67 = V_65 -> V_68 + V_66 ;
V_64 -> V_73 = V_65 -> V_68 + V_72 ;
V_64 -> V_77 = V_64 -> V_73 + V_76 ;
V_64 -> V_70 = V_65 -> V_71 + V_69 ;
V_64 -> V_75 = V_65 -> V_71 + V_74 ;
V_64 -> V_79 = V_64 -> V_75 + V_78 ;
F_19 ( V_64 , V_81 ) ;
if ( F_6 ( V_6 ) ) {
V_64 -> V_82 = V_65 -> V_68 ;
V_64 -> V_83 = V_65 -> V_71 ;
}
V_64 -> V_84 = V_64 -> V_82 + V_66 ;
V_64 -> V_85 = V_64 -> V_82 + V_72 ;
V_64 -> V_86 = V_64 -> V_85 + V_76 ;
V_64 -> V_87 = V_64 -> V_83 + V_69 ;
V_64 -> V_88 = V_64 -> V_83 + V_74 ;
V_64 -> V_89 = V_64 -> V_88 + V_78 ;
}
bool F_20 ( struct V_1 * V_2 ,
T_4 V_90 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_48 * V_49 ;
struct V_50 * V_50 ;
struct V_91 * V_92 ;
V_49 = F_14 ( V_2 ) ;
if ( ! V_49 )
V_49 = F_15 ( V_2 ) ;
V_50 = F_8 ( V_49 ) ;
switch ( V_49 -> V_93 ) {
case V_94 :
case V_95 :
if ( V_50 -> V_96 ) {
if ( F_21 ( V_6 ) && F_22 ( V_50 -> V_97 ) ) {
if ( V_90 > 340000 )
return true ;
else
return false ;
} else {
if ( V_90 > 165000 )
return true ;
else
return false ;
}
} else
return false ;
case V_98 :
case V_99 :
case V_100 :
V_92 = V_50 -> V_101 ;
if ( ( V_92 -> V_102 == V_103 ) ||
( V_92 -> V_102 == V_104 ) )
return false ;
else {
if ( F_21 ( V_6 ) && F_22 ( V_50 -> V_97 ) ) {
if ( V_90 > 340000 )
return true ;
else
return false ;
} else {
if ( V_90 > 165000 )
return true ;
else
return false ;
}
}
default:
return false ;
}
}
