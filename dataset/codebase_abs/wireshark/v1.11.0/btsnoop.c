int F_1 ( T_1 * V_1 , int * V_2 , T_2 * * V_3 )
{
int V_4 ;
char V_5 [ sizeof F_2 ] ;
struct V_6 V_7 ;
int V_8 = V_9 ;
V_10 = V_11 ;
V_4 = F_3 ( V_5 , sizeof V_5 , V_1 -> V_12 ) ;
if ( V_4 != sizeof V_5 ) {
* V_2 = F_4 ( V_1 -> V_12 , V_3 ) ;
if ( * V_2 != 0 && * V_2 != V_13 )
return - 1 ;
return 0 ;
}
if ( memcmp ( V_5 , F_2 , sizeof F_2 ) != 0 ) {
return 0 ;
}
V_10 = V_11 ;
V_4 = F_3 ( & V_7 , sizeof V_7 , V_1 -> V_12 ) ;
if ( V_4 != sizeof V_7 ) {
* V_2 = F_4 ( V_1 -> V_12 , V_3 ) ;
if ( * V_2 == 0 )
* V_2 = V_13 ;
return - 1 ;
}
V_7 . V_14 = F_5 ( V_7 . V_14 ) ;
if ( V_7 . V_14 != 1 ) {
* V_2 = V_15 ;
* V_3 = F_6 ( L_1 , V_7 . V_14 ) ;
return - 1 ;
}
V_7 . V_16 = F_5 ( V_7 . V_16 ) ;
switch ( V_7 . V_16 ) {
case V_17 :
V_8 = V_18 ;
break;
case V_19 :
* V_2 = V_15 ;
* V_3 = F_6 ( L_2 ) ;
return - 1 ;
case V_20 :
* V_2 = V_15 ;
* V_3 = F_6 ( L_3 ) ;
return - 1 ;
case V_21 :
V_8 = V_22 ;
break;
default:
* V_2 = V_15 ;
* V_3 = F_6 ( L_4 , V_7 . V_16 ) ;
return - 1 ;
}
V_1 -> V_23 = V_24 ;
V_1 -> V_25 = V_26 ;
V_1 -> V_8 = V_8 ;
V_1 -> V_27 = 0 ;
V_1 -> V_28 = V_29 ;
V_1 -> V_30 = V_31 ;
return 1 ;
}
static T_3 V_24 ( T_1 * V_1 , int * V_2 , T_2 * * V_3 ,
T_4 * V_32 )
{
* V_32 = F_7 ( V_1 -> V_12 ) ;
return F_8 ( V_1 , V_1 -> V_12 , & V_1 -> V_33 , V_1 -> V_34 ,
V_2 , V_3 ) ;
}
static T_3 V_26 ( T_1 * V_1 , T_4 V_35 ,
struct V_36 * V_33 , T_5 * V_37 , int T_6 V_38 ,
int * V_2 , T_2 * * V_3 )
{
if ( F_9 ( V_1 -> V_39 , V_35 , V_40 , V_2 ) == - 1 )
return FALSE ;
return F_8 ( V_1 , V_1 -> V_39 , V_33 , V_37 , V_2 , V_3 ) ;
}
static T_3 F_8 ( T_1 * V_1 , T_7 V_12 ,
struct V_36 * V_33 , T_5 * V_37 , int * V_2 , T_2 * * V_3 )
{
int V_4 ;
struct V_41 V_7 ;
T_8 V_42 ;
T_8 V_43 ;
T_8 V_44 ;
T_4 V_45 ;
V_10 = V_11 ;
V_4 = F_3 ( & V_7 , sizeof V_7 , V_12 ) ;
if ( V_4 != sizeof V_7 ) {
* V_2 = F_4 ( V_12 , V_3 ) ;
if ( * V_2 == 0 && V_4 != 0 )
* V_2 = V_13 ;
return FALSE ;
}
V_42 = F_5 ( V_7 . V_46 ) ;
V_44 = F_5 ( V_7 . V_47 ) ;
V_43 = F_5 ( V_7 . V_43 ) ;
if ( V_42 > V_48 ) {
* V_2 = V_49 ;
* V_3 = F_6 ( L_5 ,
V_42 , V_48 ) ;
return FALSE ;
}
V_45 = F_10 ( V_7 . V_50 ) ;
V_45 -= V_51 ;
V_33 -> V_52 = V_53 | V_54 ;
V_33 -> V_45 . V_55 = ( V_56 ) ( V_45 / 1000000 ) ;
V_33 -> V_45 . V_57 = ( V_56 ) ( ( V_45 % 1000000 ) * 1000 ) ;
V_33 -> V_58 = V_42 ;
V_33 -> V_59 = V_44 ;
if( V_1 -> V_8 == V_22 )
{
V_33 -> V_60 . V_61 . V_62 = ( V_43 & V_63 ) ? FALSE : TRUE ;
}
else if( V_1 -> V_8 == V_18 )
{
V_33 -> V_60 . V_64 . V_62 = ( V_43 & V_63 ) ? FALSE : TRUE ;
if( V_43 & V_65 )
{
if( V_33 -> V_60 . V_64 . V_62 )
{
V_33 -> V_60 . V_64 . V_66 = V_67 ;
}
else
{
V_33 -> V_60 . V_64 . V_66 = V_68 ;
}
}
else
{
V_33 -> V_60 . V_64 . V_66 = V_69 ;
}
}
return F_11 ( V_12 , V_37 , V_33 -> V_58 , V_2 , V_3 ) ;
}
int F_12 ( int V_70 )
{
if ( V_70 == V_71 )
return V_72 ;
if ( V_70 != V_22 )
return V_73 ;
return 0 ;
}
static T_9 F_13 ( T_9 V_74 , T_3 V_62 , T_9 * V_43 )
{
T_9 V_75 ;
for ( V_75 = 0 ; V_75 < F_14 ( V_76 ) ; ++ V_75 )
{
if ( V_76 [ V_75 ] . V_74 == V_74 &&
V_76 [ V_75 ] . V_62 == V_62 )
{
* V_43 = V_76 [ V_75 ] . V_43 ;
return TRUE ;
}
}
return FALSE ;
}
static T_3 F_15 ( T_10 * T_11 V_38 ,
const struct V_36 * V_33 ,
const union V_77 * V_60 ,
const T_9 * V_78 , int * V_2 ,
struct V_41 * V_79 )
{
T_4 V_50 ;
T_4 V_57 ;
T_9 V_43 = 0 ;
if ( ! F_13 ( * V_78 , V_60 -> V_61 . V_62 , & V_43 ) ) {
* V_2 = V_15 ;
return FALSE ;
}
V_57 = V_33 -> V_45 . V_57 ;
V_50 = ( ( T_4 ) V_33 -> V_45 . V_55 * 1000000 ) + ( V_57 / 1000 ) ;
V_50 += V_51 ;
V_79 -> V_43 = F_16 ( V_43 ) ;
V_79 -> V_80 = F_16 ( 0 ) ;
V_79 -> V_50 = F_17 ( V_50 ) ;
return TRUE ;
}
static T_3 F_18 ( T_10 * T_11 ,
const struct V_36 * V_33 ,
const T_9 * V_78 , int * V_2 )
{
const union V_77 * V_60 = & V_33 -> V_60 ;
struct V_41 V_79 ;
if ( ! F_15 ( T_11 , V_33 , V_60 , V_78 , V_2 , & V_79 ) )
return FALSE ;
V_79 . V_46 = F_16 ( V_33 -> V_58 - 1 ) ;
V_79 . V_47 = F_16 ( V_33 -> V_59 - 1 ) ;
if ( ! F_19 ( T_11 , & V_79 , sizeof V_79 , V_2 ) )
return FALSE ;
T_11 -> V_81 += sizeof V_79 ;
++ V_78 ;
if ( ! F_19 ( T_11 , V_78 , V_33 -> V_58 - 1 , V_2 ) )
return FALSE ;
T_11 -> V_81 += V_33 -> V_58 - 1 ;
return TRUE ;
}
static T_3 F_20 ( T_10 * T_11 ,
const struct V_36 * V_33 ,
const T_9 * V_78 , int * V_2 )
{
const union V_77 * V_60 = & V_33 -> V_60 ;
struct V_41 V_79 ;
if ( ! F_15 ( T_11 , V_33 , V_60 , V_78 , V_2 , & V_79 ) )
return FALSE ;
V_79 . V_46 = F_16 ( V_33 -> V_58 ) ;
V_79 . V_47 = F_16 ( V_33 -> V_59 ) ;
if ( ! F_19 ( T_11 , & V_79 , sizeof V_79 , V_2 ) )
return FALSE ;
T_11 -> V_81 += sizeof V_79 ;
if ( ! F_19 ( T_11 , V_78 , V_33 -> V_58 , V_2 ) )
return FALSE ;
T_11 -> V_81 += V_33 -> V_58 ;
return TRUE ;
}
T_3 F_21 ( T_10 * T_11 , int * V_2 )
{
struct V_6 V_82 ;
T_11 -> V_83 = F_18 ;
T_11 -> V_84 = NULL ;
switch ( T_11 -> V_30 ) {
case V_31 :
T_11 -> V_28 = V_29 ;
break;
default:
* V_2 = V_85 ;
return FALSE ;
}
if ( ! F_19 ( T_11 , F_2 , sizeof F_2 , V_2 ) )
return FALSE ;
T_11 -> V_81 += sizeof F_2 ;
V_82 . V_14 = F_16 ( 1 ) ;
V_82 . V_16 = F_16 ( V_17 ) ;
if ( ! F_19 ( T_11 , & V_82 , sizeof V_82 , V_2 ) )
return FALSE ;
T_11 -> V_81 += sizeof V_82 ;
return TRUE ;
}
T_3 F_22 ( T_10 * T_11 , int * V_2 )
{
struct V_6 V_82 ;
T_11 -> V_83 = F_20 ;
T_11 -> V_84 = NULL ;
switch ( T_11 -> V_30 ) {
case V_31 :
T_11 -> V_28 = V_29 ;
break;
default:
* V_2 = V_85 ;
return FALSE ;
}
if ( ! F_19 ( T_11 , F_2 , sizeof F_2 , V_2 ) )
return FALSE ;
T_11 -> V_81 += sizeof F_2 ;
V_82 . V_14 = F_16 ( 1 ) ;
V_82 . V_16 = F_16 ( V_21 ) ;
if ( ! F_19 ( T_11 , & V_82 , sizeof V_82 , V_2 ) )
return FALSE ;
T_11 -> V_81 += sizeof V_82 ;
return TRUE ;
}
