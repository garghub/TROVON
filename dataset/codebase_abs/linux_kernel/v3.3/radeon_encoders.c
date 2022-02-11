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
struct V_48 * V_49 ;
struct V_50 * V_50 ;
struct V_1 * V_2 ;
struct V_8 * V_8 ;
F_3 (connector, &dev->mode_config.connector_list, head) {
V_50 = F_8 ( V_49 ) ;
F_3 (encoder, &dev->mode_config.encoder_list, head) {
V_8 = F_2 ( V_2 ) ;
if ( V_8 -> V_14 & V_50 -> V_14 )
F_9 ( V_49 , V_2 ) ;
}
}
}
void F_10 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_8 * V_8 = F_2 ( V_2 ) ;
struct V_48 * V_49 ;
F_3 (connector, &dev->mode_config.connector_list, head) {
if ( V_49 -> V_2 == V_2 ) {
struct V_50 * V_50 = F_8 ( V_49 ) ;
V_8 -> V_51 = V_8 -> V_14 & V_50 -> V_14 ;
F_11 ( L_1 ,
V_8 -> V_51 , V_8 -> V_14 ,
V_50 -> V_14 , V_2 -> V_52 ) ;
}
}
}
struct V_48 *
F_12 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_8 * V_8 = F_2 ( V_2 ) ;
struct V_48 * V_49 ;
struct V_50 * V_50 ;
F_3 (connector, &dev->mode_config.connector_list, head) {
V_50 = F_8 ( V_49 ) ;
if ( V_8 -> V_51 & V_50 -> V_14 )
return V_49 ;
}
return NULL ;
}
struct V_48 *
F_13 ( struct V_1 * V_2 )
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
struct V_1 * F_14 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_8 * V_8 = F_2 ( V_2 ) ;
struct V_1 * V_53 ;
struct V_8 * V_54 ;
if ( V_8 -> V_55 )
return NULL ;
F_3 (other_encoder, &dev->mode_config.encoder_list, head) {
if ( V_53 == V_2 )
continue;
V_54 = F_2 ( V_53 ) ;
if ( V_54 -> V_55 &&
( V_8 -> V_14 & V_54 -> V_14 ) )
return V_53 ;
}
return NULL ;
}
T_3 F_15 ( struct V_1 * V_2 )
{
struct V_1 * V_53 = F_14 ( V_2 ) ;
if ( V_53 ) {
struct V_8 * V_8 = F_2 ( V_53 ) ;
switch ( V_8 -> V_56 ) {
case V_57 :
case V_58 :
return V_8 -> V_56 ;
default:
return V_59 ;
}
}
return V_59 ;
}
void F_16 ( struct V_1 * V_2 ,
struct V_60 * V_61 )
{
struct V_8 * V_8 = F_2 ( V_2 ) ;
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_60 * V_62 = & V_8 -> V_62 ;
unsigned V_63 = V_62 -> V_64 - V_62 -> V_65 ;
unsigned V_66 = V_62 -> V_67 - V_62 -> V_68 ;
unsigned V_69 = V_62 -> V_70 - V_62 -> V_65 ;
unsigned V_71 = V_62 -> V_72 - V_62 -> V_68 ;
unsigned V_73 = V_62 -> V_74 - V_62 -> V_70 ;
unsigned V_75 = V_62 -> V_76 - V_62 -> V_72 ;
V_61 -> clock = V_62 -> clock ;
V_61 -> V_77 = V_62 -> V_77 ;
if ( F_6 ( V_6 ) ) {
V_61 -> V_65 = V_62 -> V_65 ;
V_61 -> V_68 = V_62 -> V_68 ;
}
V_61 -> V_64 = V_62 -> V_65 + V_63 ;
V_61 -> V_70 = V_62 -> V_65 + V_69 ;
V_61 -> V_74 = V_61 -> V_70 + V_73 ;
V_61 -> V_67 = V_62 -> V_68 + V_66 ;
V_61 -> V_72 = V_62 -> V_68 + V_71 ;
V_61 -> V_76 = V_61 -> V_72 + V_75 ;
F_17 ( V_61 , V_78 ) ;
if ( F_6 ( V_6 ) ) {
V_61 -> V_79 = V_62 -> V_65 ;
V_61 -> V_80 = V_62 -> V_68 ;
}
V_61 -> V_81 = V_61 -> V_79 + V_63 ;
V_61 -> V_82 = V_61 -> V_79 + V_69 ;
V_61 -> V_83 = V_61 -> V_82 + V_73 ;
V_61 -> V_84 = V_61 -> V_80 + V_66 ;
V_61 -> V_85 = V_61 -> V_80 + V_71 ;
V_61 -> V_86 = V_61 -> V_85 + V_75 ;
}
bool F_18 ( struct V_1 * V_2 ,
T_4 V_87 )
{
struct V_48 * V_49 ;
struct V_50 * V_50 ;
struct V_88 * V_89 ;
V_49 = F_12 ( V_2 ) ;
if ( ! V_49 )
V_49 = F_13 ( V_2 ) ;
V_50 = F_8 ( V_49 ) ;
switch ( V_49 -> V_90 ) {
case V_91 :
case V_92 :
if ( V_50 -> V_93 ) {
if ( 0 && F_19 ( V_50 -> V_94 ) ) {
if ( V_87 > 340000 )
return true ;
else
return false ;
} else {
if ( V_87 > 165000 )
return true ;
else
return false ;
}
} else
return false ;
case V_95 :
case V_96 :
case V_97 :
V_89 = V_50 -> V_98 ;
if ( ( V_89 -> V_99 == V_100 ) ||
( V_89 -> V_99 == V_101 ) )
return false ;
else {
if ( 0 && F_19 ( V_50 -> V_94 ) ) {
if ( V_87 > 340000 )
return true ;
else
return false ;
} else {
if ( V_87 > 165000 )
return true ;
else
return false ;
}
}
default:
return false ;
}
}
