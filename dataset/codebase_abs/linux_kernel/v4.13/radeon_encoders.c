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
static void F_7 ( struct V_8 * V_8 ,
struct V_48 * V_49 )
{
struct V_3 * V_4 = V_8 -> V_50 . V_4 ;
struct V_5 * V_6 = V_4 -> V_7 ;
bool V_51 = false ;
if ( ! ( V_8 -> V_14 & ( V_15 ) ) )
return;
if ( V_52 == 0 ) {
return;
} else if ( V_52 == 1 ) {
V_51 = true ;
} else if ( V_52 == - 1 ) {
if ( ( V_6 -> V_53 -> V_54 == 0x9583 ) &&
( V_6 -> V_53 -> V_55 == 0x1734 ) &&
( V_6 -> V_53 -> V_56 == 0x1107 ) )
V_51 = false ;
#ifndef F_8
else if ( V_6 -> V_12 < V_13 )
V_51 = false ;
#endif
else
V_51 = true ;
}
if ( V_51 ) {
if ( V_6 -> V_57 )
F_9 ( V_8 , V_49 ) ;
else
F_10 ( V_8 , V_49 ) ;
}
}
void
F_11 ( struct V_3 * V_4 )
{
struct V_48 * V_49 ;
struct V_58 * V_58 ;
struct V_1 * V_2 ;
struct V_8 * V_8 ;
F_3 (connector, &dev->mode_config.connector_list, head) {
V_58 = F_12 ( V_49 ) ;
F_3 (encoder, &dev->mode_config.encoder_list, head) {
V_8 = F_2 ( V_2 ) ;
if ( V_8 -> V_14 & V_58 -> V_14 ) {
F_13 ( V_49 , V_2 ) ;
if ( V_8 -> V_14 & ( V_15 ) )
F_7 ( V_8 , V_49 ) ;
}
}
}
}
void F_14 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_8 * V_8 = F_2 ( V_2 ) ;
struct V_48 * V_49 ;
F_3 (connector, &dev->mode_config.connector_list, head) {
if ( V_49 -> V_2 == V_2 ) {
struct V_58 * V_58 = F_12 ( V_49 ) ;
V_8 -> V_59 = V_8 -> V_14 & V_58 -> V_14 ;
F_15 ( L_1 ,
V_8 -> V_59 , V_8 -> V_14 ,
V_58 -> V_14 , V_2 -> V_60 ) ;
}
}
}
struct V_48 *
F_16 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_8 * V_8 = F_2 ( V_2 ) ;
struct V_48 * V_49 ;
struct V_58 * V_58 ;
F_3 (connector, &dev->mode_config.connector_list, head) {
V_58 = F_12 ( V_49 ) ;
if ( V_8 -> V_61 ) {
struct V_62 * V_63 ;
if ( ! V_58 -> V_64 )
continue;
V_63 = V_8 -> V_65 ;
if ( V_63 -> V_49 == V_58 -> V_66 )
return V_49 ;
} else if ( V_8 -> V_59 & V_58 -> V_14 )
return V_49 ;
}
return NULL ;
}
struct V_48 *
F_17 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_8 * V_8 = F_2 ( V_2 ) ;
struct V_48 * V_49 ;
struct V_58 * V_58 ;
F_3 (connector, &dev->mode_config.connector_list, head) {
V_58 = F_12 ( V_49 ) ;
if ( V_8 -> V_14 & V_58 -> V_14 )
return V_49 ;
}
return NULL ;
}
struct V_1 * F_18 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_8 * V_8 = F_2 ( V_2 ) ;
struct V_1 * V_67 ;
struct V_8 * V_68 ;
if ( V_8 -> V_69 )
return NULL ;
F_3 (other_encoder, &dev->mode_config.encoder_list, head) {
if ( V_67 == V_2 )
continue;
V_68 = F_2 ( V_67 ) ;
if ( V_68 -> V_69 &&
( V_8 -> V_14 & V_68 -> V_14 ) )
return V_67 ;
}
return NULL ;
}
T_3 F_19 ( struct V_1 * V_2 )
{
struct V_1 * V_67 = F_18 ( V_2 ) ;
if ( V_67 ) {
struct V_8 * V_8 = F_2 ( V_67 ) ;
switch ( V_8 -> V_70 ) {
case V_71 :
case V_72 :
return V_8 -> V_70 ;
default:
return V_73 ;
}
}
return V_73 ;
}
void F_20 ( struct V_1 * V_2 ,
struct V_74 * V_75 )
{
struct V_8 * V_8 = F_2 ( V_2 ) ;
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_74 * V_76 = & V_8 -> V_76 ;
unsigned V_77 = V_76 -> V_78 - V_76 -> V_79 ;
unsigned V_80 = V_76 -> V_81 - V_76 -> V_82 ;
unsigned V_83 = V_76 -> V_84 - V_76 -> V_79 ;
unsigned V_85 = V_76 -> V_86 - V_76 -> V_82 ;
unsigned V_87 = V_76 -> V_88 - V_76 -> V_84 ;
unsigned V_89 = V_76 -> V_90 - V_76 -> V_86 ;
V_75 -> clock = V_76 -> clock ;
V_75 -> V_91 = V_76 -> V_91 ;
if ( F_6 ( V_6 ) ) {
V_75 -> V_79 = V_76 -> V_79 ;
V_75 -> V_82 = V_76 -> V_82 ;
}
V_75 -> V_78 = V_76 -> V_79 + V_77 ;
V_75 -> V_84 = V_76 -> V_79 + V_83 ;
V_75 -> V_88 = V_75 -> V_84 + V_87 ;
V_75 -> V_81 = V_76 -> V_82 + V_80 ;
V_75 -> V_86 = V_76 -> V_82 + V_85 ;
V_75 -> V_90 = V_75 -> V_86 + V_89 ;
F_21 ( V_75 , V_92 ) ;
if ( F_6 ( V_6 ) ) {
V_75 -> V_93 = V_76 -> V_79 ;
V_75 -> V_94 = V_76 -> V_82 ;
}
V_75 -> V_95 = V_75 -> V_93 + V_77 ;
V_75 -> V_96 = V_75 -> V_93 + V_83 ;
V_75 -> V_97 = V_75 -> V_96 + V_87 ;
V_75 -> V_98 = V_75 -> V_94 + V_80 ;
V_75 -> V_99 = V_75 -> V_94 + V_85 ;
V_75 -> V_100 = V_75 -> V_99 + V_89 ;
}
bool F_22 ( struct V_1 * V_2 ,
T_4 V_101 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_48 * V_49 ;
struct V_58 * V_58 ;
struct V_102 * V_103 ;
V_49 = F_16 ( V_2 ) ;
if ( ! V_49 )
V_49 = F_17 ( V_2 ) ;
V_58 = F_12 ( V_49 ) ;
switch ( V_49 -> V_104 ) {
case V_105 :
case V_106 :
if ( V_58 -> V_107 ) {
if ( F_23 ( V_6 ) && F_24 ( F_25 ( V_49 ) ) ) {
if ( V_101 > 340000 )
return true ;
else
return false ;
} else {
if ( V_101 > 165000 )
return true ;
else
return false ;
}
} else
return false ;
case V_108 :
case V_109 :
case V_110 :
if ( V_58 -> V_64 )
return false ;
V_103 = V_58 -> V_111 ;
if ( ( V_103 -> V_112 == V_113 ) ||
( V_103 -> V_112 == V_114 ) )
return false ;
else {
if ( F_23 ( V_6 ) && F_24 ( F_25 ( V_49 ) ) ) {
if ( V_101 > 340000 )
return true ;
else
return false ;
} else {
if ( V_101 > 165000 )
return true ;
else
return false ;
}
}
default:
return false ;
}
}
bool F_26 ( struct V_1 * V_2 )
{
struct V_8 * V_8 = F_2 ( V_2 ) ;
switch ( V_8 -> V_70 ) {
case V_115 :
case V_116 :
case V_117 :
case V_118 :
case V_119 :
case V_120 :
case V_121 :
case V_122 :
case V_123 :
case V_124 :
case V_125 :
case V_126 :
return true ;
default:
return false ;
}
}
