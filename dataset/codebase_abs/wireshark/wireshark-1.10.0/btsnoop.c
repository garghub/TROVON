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
T_5 V_33 ;
T_5 V_34 ;
T_5 V_35 ;
int V_4 ;
struct V_36 V_7 ;
T_4 V_37 ;
* V_32 = F_7 ( V_1 -> V_12 ) ;
V_10 = V_11 ;
V_4 = F_3 ( & V_7 , sizeof V_7 , V_1 -> V_12 ) ;
if ( V_4 != sizeof V_7 ) {
* V_2 = F_4 ( V_1 -> V_12 , V_3 ) ;
if ( * V_2 == 0 && V_4 != 0 )
* V_2 = V_13 ;
return FALSE ;
}
V_33 = F_5 ( V_7 . V_38 ) ;
V_35 = F_5 ( V_7 . V_39 ) ;
V_34 = F_5 ( V_7 . V_34 ) ;
if ( V_33 > V_40 ) {
* V_2 = V_41 ;
* V_3 = F_6 ( L_5 ,
V_33 , V_40 ) ;
return FALSE ;
}
F_8 ( V_1 -> V_42 , V_33 ) ;
if ( ! F_9 ( V_1 -> V_12 , F_10 ( V_1 -> V_42 ) ,
V_33 , V_2 , V_3 ) ) {
return FALSE ;
}
V_37 = F_11 ( V_7 . V_43 ) ;
V_37 -= V_44 ;
V_1 -> V_45 . V_46 = V_47 | V_48 ;
V_1 -> V_45 . V_37 . V_49 = ( V_50 ) ( V_37 / 1000000 ) ;
V_1 -> V_45 . V_37 . V_51 = ( V_50 ) ( ( V_37 % 1000000 ) * 1000 ) ;
V_1 -> V_45 . V_52 = V_33 ;
V_1 -> V_45 . V_53 = V_35 ;
if( V_1 -> V_8 == V_22 )
{
V_1 -> V_45 . V_54 . V_55 . V_56 = ( V_34 & V_57 ) ? FALSE : TRUE ;
}
else if( V_1 -> V_8 == V_18 )
{
V_1 -> V_45 . V_54 . V_58 . V_56 = ( V_34 & V_57 ) ? FALSE : TRUE ;
if( V_34 & V_59 )
{
if( V_1 -> V_45 . V_54 . V_58 . V_56 )
{
V_1 -> V_45 . V_54 . V_58 . V_60 = V_61 ;
}
else
{
V_1 -> V_45 . V_54 . V_58 . V_60 = V_62 ;
}
}
else
{
V_1 -> V_45 . V_54 . V_58 . V_60 = V_63 ;
}
}
return TRUE ;
}
static T_3 V_26 ( T_1 * V_1 , T_4 V_64 ,
struct V_65 * V_45 , T_6 * V_66 , int V_67 ,
int * V_2 , T_2 * * V_3 ) {
union V_68 * V_54 = & V_45 -> V_54 ;
int V_4 ;
struct V_36 V_7 ;
T_5 V_34 ;
if ( F_12 ( V_1 -> V_69 , V_64 , V_70 , V_2 ) == - 1 )
return FALSE ;
V_10 = V_11 ;
V_4 = F_3 ( & V_7 , sizeof V_7 , V_1 -> V_69 ) ;
if ( V_4 != sizeof V_7 ) {
* V_2 = F_4 ( V_1 -> V_69 , V_3 ) ;
if ( * V_2 == 0 && V_4 != 0 )
* V_2 = V_13 ;
return FALSE ;
}
V_34 = F_5 ( V_7 . V_34 ) ;
if ( ! F_9 ( V_1 -> V_69 , V_66 , V_67 , V_2 , V_3 ) )
return FALSE ;
if( V_1 -> V_8 == V_22 )
{
V_54 -> V_55 . V_56 = ( V_34 & V_57 ) ? FALSE : TRUE ;
}
else if( V_1 -> V_8 == V_18 )
{
V_54 -> V_58 . V_56 = ( V_34 & V_57 ) ? FALSE : TRUE ;
if( V_34 & V_59 )
{
if( V_54 -> V_58 . V_56 )
{
V_54 -> V_58 . V_60 = V_61 ;
}
else
{
V_54 -> V_58 . V_60 = V_62 ;
}
}
else
{
V_54 -> V_58 . V_60 = V_63 ;
}
}
return TRUE ;
}
static T_3
F_9 ( T_7 V_12 , T_6 * V_66 , int V_67 , int * V_2 ,
T_2 * * V_3 )
{
int V_4 ;
V_10 = V_11 ;
V_4 = F_3 ( V_66 , V_67 , V_12 ) ;
if ( V_4 != V_67 ) {
* V_2 = F_4 ( V_12 , V_3 ) ;
if ( * V_2 == 0 )
* V_2 = V_13 ;
return FALSE ;
}
return TRUE ;
}
int F_13 ( int V_71 )
{
if ( V_71 == V_72 )
return V_73 ;
if ( V_71 != V_22 )
return V_74 ;
return 0 ;
}
static T_6 F_14 ( T_6 V_75 , T_3 V_56 , T_6 * V_34 )
{
T_6 V_76 ;
for ( V_76 = 0 ; V_76 < F_15 ( V_77 ) ; ++ V_76 )
{
if ( V_77 [ V_76 ] . V_75 == V_75 &&
V_77 [ V_76 ] . V_56 == V_56 )
{
* V_34 = V_77 [ V_76 ] . V_34 ;
return TRUE ;
}
}
return FALSE ;
}
static T_3 F_16 ( T_8 * T_9 V_78 ,
const struct V_65 * V_45 ,
const union V_68 * V_54 ,
const T_6 * V_66 , int * V_2 ,
struct V_36 * V_79 )
{
T_4 V_43 ;
T_4 V_51 ;
T_6 V_34 = 0 ;
if ( ! F_14 ( * V_66 , V_54 -> V_55 . V_56 , & V_34 ) ) {
* V_2 = V_15 ;
return FALSE ;
}
V_51 = V_45 -> V_37 . V_51 ;
V_43 = ( ( T_4 ) V_45 -> V_37 . V_49 * 1000000 ) + ( V_51 / 1000 ) ;
V_43 += V_44 ;
V_79 -> V_34 = F_17 ( V_34 ) ;
V_79 -> V_80 = F_17 ( 0 ) ;
V_79 -> V_43 = F_18 ( V_43 ) ;
return TRUE ;
}
static T_3 F_19 ( T_8 * T_9 ,
const struct V_65 * V_45 ,
const T_6 * V_66 , int * V_2 )
{
const union V_68 * V_54 = & V_45 -> V_54 ;
struct V_36 V_79 ;
if ( ! F_16 ( T_9 , V_45 , V_54 , V_66 , V_2 , & V_79 ) )
return FALSE ;
V_79 . V_38 = F_17 ( V_45 -> V_52 - 1 ) ;
V_79 . V_39 = F_17 ( V_45 -> V_53 - 1 ) ;
if ( ! F_20 ( T_9 , & V_79 , sizeof V_79 , V_2 ) )
return FALSE ;
T_9 -> V_81 += sizeof V_79 ;
++ V_66 ;
if ( ! F_20 ( T_9 , V_66 , V_45 -> V_52 - 1 , V_2 ) )
return FALSE ;
T_9 -> V_81 += V_45 -> V_52 - 1 ;
return TRUE ;
}
static T_3 F_21 ( T_8 * T_9 ,
const struct V_65 * V_45 ,
const T_6 * V_66 , int * V_2 )
{
const union V_68 * V_54 = & V_45 -> V_54 ;
struct V_36 V_79 ;
if ( ! F_16 ( T_9 , V_45 , V_54 , V_66 , V_2 , & V_79 ) )
return FALSE ;
V_79 . V_38 = F_17 ( V_45 -> V_52 ) ;
V_79 . V_39 = F_17 ( V_45 -> V_53 ) ;
if ( ! F_20 ( T_9 , & V_79 , sizeof V_79 , V_2 ) )
return FALSE ;
T_9 -> V_81 += sizeof V_79 ;
if ( ! F_20 ( T_9 , V_66 , V_45 -> V_52 , V_2 ) )
return FALSE ;
T_9 -> V_81 += V_45 -> V_52 ;
return TRUE ;
}
T_3 F_22 ( T_8 * T_9 , int * V_2 )
{
struct V_6 V_82 ;
T_9 -> V_83 = F_19 ;
T_9 -> V_84 = NULL ;
switch ( T_9 -> V_30 ) {
case V_31 :
T_9 -> V_28 = V_29 ;
break;
default:
* V_2 = V_85 ;
return FALSE ;
}
if ( ! F_20 ( T_9 , F_2 , sizeof F_2 , V_2 ) )
return FALSE ;
T_9 -> V_81 += sizeof F_2 ;
V_82 . V_14 = F_17 ( 1 ) ;
V_82 . V_16 = F_17 ( V_17 ) ;
if ( ! F_20 ( T_9 , & V_82 , sizeof V_82 , V_2 ) )
return FALSE ;
T_9 -> V_81 += sizeof V_82 ;
return TRUE ;
}
T_3 F_23 ( T_8 * T_9 , int * V_2 )
{
struct V_6 V_82 ;
T_9 -> V_83 = F_21 ;
T_9 -> V_84 = NULL ;
switch ( T_9 -> V_30 ) {
case V_31 :
T_9 -> V_28 = V_29 ;
break;
default:
* V_2 = V_85 ;
return FALSE ;
}
if ( ! F_20 ( T_9 , F_2 , sizeof F_2 , V_2 ) )
return FALSE ;
T_9 -> V_81 += sizeof F_2 ;
V_82 . V_14 = F_17 ( 1 ) ;
V_82 . V_16 = F_17 ( V_21 ) ;
if ( ! F_20 ( T_9 , & V_82 , sizeof V_82 , V_2 ) )
return FALSE ;
T_9 -> V_81 += sizeof V_82 ;
return TRUE ;
}
