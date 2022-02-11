enum V_1
F_1 ( struct V_2 * V_2 )
{
void * V_3 = NULL ;
T_1 V_4 = 0 ;
if ( F_2 ( V_2 ) != V_5 )
return V_6 ;
if ( F_3 ( V_2 ) != V_5 )
return V_7 ;
F_4 ( V_2 , V_8 ) ;
V_3 = V_2 -> V_3 ;
F_5 ( V_3 , V_9 , V_10 ,
L_1 , V_11 ) ;
V_4 |= ( V_12 |
( 0x3 << V_13 ) ) ;
if ( F_6 ( V_3 , V_14 + 3 ) ==
0x20 ) {
V_4 |= ( V_15 << V_16 ) ;
} else {
if ( ( F_6 ( V_3 , V_17 ) &
0x3 ) == 0x1 )
V_4 |= V_18
<< V_16 ;
else
V_4 |= V_19
<< V_16 ;
}
F_7 ( V_3 , V_20 , V_4 ) ;
F_8 (
V_3 , V_21 ,
F_9 ( V_3 , V_21 ) |
V_22 ) ;
F_5 ( V_3 , V_9 , V_10 ,
L_2 , V_11 ) ;
return V_5 ;
}
enum V_1
F_10 ( struct V_2 * V_2 )
{
void * V_3 = NULL ;
if ( F_2 ( V_2 ) != V_5 )
return V_6 ;
if ( F_3 ( V_2 ) != V_5 )
return V_7 ;
F_4 ( V_2 , V_23 ) ;
V_3 = V_2 -> V_3 ;
F_5 ( V_3 , V_9 , V_10 ,
L_1 , V_11 ) ;
F_5 ( V_3 , V_9 , V_10 ,
L_2 , V_11 ) ;
return V_5 ;
}
enum V_1
F_11 ( struct V_2 * V_2 ,
struct V_24 * V_25 )
{
T_1 V_26 ;
T_1 V_27 = 0 , V_28 = 0 , V_29 = 0 ;
void * V_3 = NULL ;
struct V_30 * V_30 ;
if ( F_2 ( V_2 ) != V_5 )
return V_6 ;
if ( F_3 ( V_2 ) != V_5 )
return V_7 ;
F_4 ( V_2 ,
V_31 ) ;
V_3 = V_2 -> V_3 ;
V_30 = (struct V_30 * ) V_2 -> V_30 ;
F_5 ( V_3 , V_9 , V_10 ,
L_1 , V_11 ) ;
V_26 =
F_12 ( V_2 , V_32 + 3 ) ;
V_29 = F_12 ( V_2 , V_33 ) ;
switch ( V_25 -> V_34 ) {
case V_35 :
V_29 &= ~ V_36 ;
break;
case V_37 :
V_29 |= V_36 ;
V_26 |= F_13 ( 7 ) ;
break;
case V_38 :
V_29 |= V_36 ;
V_26 &= ~ F_13 ( 7 ) ;
break;
default:
F_14 ( L_3 , V_11 ) ;
V_29 &= ~ V_36 ;
break;
}
if ( ! V_25 -> V_39 . V_40 ) {
if ( F_6 ( V_3 , V_14 + 3 ) ==
0x20 ) {
V_27 = 0x5 ;
V_28 = 0xA ;
} else {
V_27 = 0x5 ;
V_28 = 0x20 ;
}
} else {
V_27 = V_25 -> V_39 . V_27 ;
V_28 = V_25 -> V_39 . V_28 ;
}
F_15 ( V_2 , V_33 , V_29 ) ;
F_15 ( V_2 , V_32 + 3 ,
V_26 ) ;
F_16 ( V_2 , V_32 ,
( V_41 ) ( V_27 | ( V_28 << V_42 ) ) ) ;
F_5 ( V_3 , V_9 , V_10 ,
L_2 , V_11 ) ;
return V_5 ;
}
T_1 F_17 ( struct V_2 * V_2 ,
T_2 V_43 )
{
T_1 V_4 ;
void * V_3 = NULL ;
struct V_30 * V_30 ;
if ( F_2 ( V_2 ) != V_5 )
return V_6 ;
if ( F_3 ( V_2 ) != V_5 )
return V_7 ;
V_3 = V_2 -> V_3 ;
V_30 = (struct V_30 * ) V_2 -> V_30 ;
V_4 = F_6 ( V_3 , V_43 ) ;
return V_4 ;
}
enum V_1
F_18 ( struct V_2 * V_2 ,
T_2 V_43 , T_1 V_44 )
{
void * V_3 = NULL ;
struct V_30 * V_30 ;
if ( F_2 ( V_2 ) != V_5 )
return V_6 ;
if ( F_3 ( V_2 ) != V_5 )
return V_7 ;
V_3 = V_2 -> V_3 ;
V_30 = (struct V_30 * ) V_2 -> V_30 ;
F_7 ( V_3 , V_43 , V_44 ) ;
return V_5 ;
}
V_41 F_19 ( struct V_2 * V_2 ,
T_2 V_43 )
{
void * V_3 = NULL ;
struct V_30 * V_30 ;
union {
V_41 V_45 ;
T_1 V_46 [ 2 ] ;
} V_47 = { 0x0000 } ;
if ( F_2 ( V_2 ) != V_5 )
return V_6 ;
if ( F_3 ( V_2 ) != V_5 )
return V_7 ;
V_3 = V_2 -> V_3 ;
V_30 = (struct V_30 * ) V_2 -> V_30 ;
V_47 . V_45 = F_9 ( V_3 , V_43 ) ;
return V_47 . V_45 ;
}
enum V_1
F_20 ( struct V_2 * V_2 ,
T_2 V_43 , V_41 V_44 )
{
void * V_3 = NULL ;
struct V_30 * V_30 ;
if ( F_2 ( V_2 ) != V_5 )
return V_6 ;
if ( F_3 ( V_2 ) != V_5 )
return V_7 ;
V_3 = V_2 -> V_3 ;
V_30 = (struct V_30 * ) V_2 -> V_30 ;
F_8 ( V_3 , V_43 , V_44 ) ;
return V_5 ;
}
T_2 F_21 ( struct V_2 * V_2 ,
T_2 V_43 )
{
void * V_3 = NULL ;
struct V_30 * V_30 ;
union {
T_2 V_48 ;
T_1 V_46 [ 4 ] ;
} V_49 = { 0x00000000 } ;
if ( F_2 ( V_2 ) != V_5 )
return V_6 ;
if ( F_3 ( V_2 ) != V_5 )
return V_7 ;
V_3 = V_2 -> V_3 ;
V_30 = (struct V_30 * ) V_2 -> V_30 ;
V_49 . V_48 = F_22 ( V_3 , V_43 ) ;
return V_49 . V_48 ;
}
enum V_1
F_23 ( struct V_2 * V_2 ,
T_2 V_43 , T_2 V_44 )
{
void * V_3 = NULL ;
struct V_30 * V_30 ;
if ( F_2 ( V_2 ) != V_5 )
return V_6 ;
if ( F_3 ( V_2 ) != V_5 )
return V_7 ;
V_3 = V_2 -> V_3 ;
V_30 = (struct V_30 * ) V_2 -> V_30 ;
F_24 ( V_3 , V_43 , V_44 ) ;
return V_5 ;
}
enum V_1
F_25 ( struct V_2 * V_2 ,
T_1 V_50 )
{
void * V_3 = NULL ;
struct V_30 * V_30 ;
if ( F_2 ( V_2 ) != V_5 )
return V_6 ;
if ( F_3 ( V_2 ) != V_5 )
return V_7 ;
F_4 ( V_2 , V_51 ) ;
V_3 = V_2 -> V_3 ;
V_30 = (struct V_30 * ) V_2 -> V_30 ;
V_2 -> V_52 = V_50 ;
return V_5 ;
}
enum V_1
F_26 ( struct V_2 * V_2 ,
T_1 * V_53 , T_2 V_54 , T_1 * V_55 )
{
void * V_3 = NULL ;
struct V_30 * V_30 ;
enum V_56 V_57 ;
enum V_58 V_59 ;
if ( F_2 ( V_2 ) != V_5 )
return V_6 ;
if ( F_3 ( V_2 ) != V_5 )
return V_7 ;
F_4 ( V_2 ,
V_60 ) ;
V_3 = V_2 -> V_3 ;
V_30 = (struct V_30 * ) V_2 -> V_30 ;
F_5 ( V_3 , V_9 , V_10 ,
L_1 , V_11 ) ;
if ( ! V_53 ) {
F_14 ( L_4 ) ;
return V_61 ;
}
if ( V_54 == 0 ) {
F_14 ( L_5 ) ;
return V_62 ;
}
V_57 = (enum V_56 ) F_27 ( V_53 ) ;
switch ( V_57 ) {
case V_63 :
case V_64 :
V_59 =
V_2 -> V_65 [ V_66 ] ;
break;
case V_67 :
case V_68 :
V_59 =
V_2 -> V_65 [ V_69 ] ;
break;
case V_70 :
case V_71 :
V_59 =
V_2 -> V_65 [ V_72 ] ;
break;
case V_73 :
case V_74 :
V_59 =
V_2 -> V_65 [ V_75 ] ;
break;
case V_76 :
V_59 =
V_2 -> V_65 [ V_77 ] ;
break;
case V_78 :
case V_79 :
case V_80 :
V_59 = V_81 ;
break;
default:
F_14 ( L_6 ) ;
return V_82 ;
}
switch ( V_59 ) {
case V_81 :
* V_55 = 0 ;
break;
case V_83 :
* V_55 = 1 ;
break;
case V_84 :
* V_55 = 2 ;
break;
case V_85 :
* V_55 = 3 ;
break;
default:
F_14 ( L_7 ) ;
return V_86 ;
}
F_5 ( V_3 , V_9 , V_10 ,
L_2 , V_11 ) ;
return V_5 ;
}
enum V_1 F_28 (
struct V_2 * V_2 , T_1 V_87 , V_41 V_88 )
{
struct V_30 * V_30 ;
void * V_3 = NULL ;
if ( F_2 ( V_2 ) != V_5 )
return V_6 ;
if ( F_3 ( V_2 ) != V_5 )
return V_7 ;
F_4 ( V_2 , V_89 ) ;
V_3 = V_2 -> V_3 ;
V_30 = (struct V_30 * ) V_2 -> V_30 ;
F_5 (
V_3 , V_9 , V_10 ,
L_1 , V_11 ) ;
F_5 (
V_3 , V_9 , V_10 ,
L_8 , V_11 ) ;
F_5 (
V_3 , V_9 , V_10 ,
L_2 , V_11 ) ;
return V_5 ;
}
