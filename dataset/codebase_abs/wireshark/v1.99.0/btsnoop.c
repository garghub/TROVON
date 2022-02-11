int F_1 ( T_1 * V_1 , int * V_2 , T_2 * * V_3 )
{
char V_4 [ sizeof F_2 ] ;
struct V_5 V_6 ;
int V_7 = V_8 ;
V_9 = V_10 ;
if ( ! F_3 ( V_1 -> V_11 , V_4 , sizeof V_4 , V_2 , V_3 ) ) {
if ( * V_2 != V_12 )
return - 1 ;
return 0 ;
}
if ( memcmp ( V_4 , F_2 , sizeof F_2 ) != 0 ) {
return 0 ;
}
V_9 = V_10 ;
if ( ! F_3 ( V_1 -> V_11 , & V_6 , sizeof V_6 , V_2 , V_3 ) )
return - 1 ;
V_6 . V_13 = F_4 ( V_6 . V_13 ) ;
if ( V_6 . V_13 != 1 ) {
* V_2 = V_14 ;
* V_3 = F_5 ( L_1 , V_6 . V_13 ) ;
return - 1 ;
}
V_6 . V_15 = F_4 ( V_6 . V_15 ) ;
switch ( V_6 . V_15 ) {
case V_16 :
V_7 = V_17 ;
break;
case V_18 :
V_7 = V_19 ;
break;
case V_20 :
* V_2 = V_14 ;
* V_3 = F_5 ( L_2 ) ;
return - 1 ;
case V_21 :
* V_2 = V_14 ;
* V_3 = F_5 ( L_3 ) ;
return - 1 ;
case V_22 :
V_7 = V_23 ;
break;
case V_24 :
* V_2 = V_14 ;
* V_3 = F_5 ( L_4 ) ;
return - 1 ;
default:
* V_2 = V_14 ;
* V_3 = F_5 ( L_5 , V_6 . V_15 ) ;
return - 1 ;
}
V_1 -> V_25 = V_26 ;
V_1 -> V_27 = V_28 ;
V_1 -> V_7 = V_7 ;
V_1 -> V_29 = 0 ;
V_1 -> V_30 = V_31 ;
V_1 -> V_32 = V_33 ;
return 1 ;
}
static T_3 V_26 ( T_1 * V_1 , int * V_2 , T_2 * * V_3 ,
T_4 * V_34 )
{
* V_34 = F_6 ( V_1 -> V_11 ) ;
return F_7 ( V_1 , V_1 -> V_11 , & V_1 -> V_35 , V_1 -> V_36 ,
V_2 , V_3 ) ;
}
static T_3 V_28 ( T_1 * V_1 , T_4 V_37 ,
struct V_38 * V_35 , T_5 * V_39 , int * V_2 , T_2 * * V_3 )
{
if ( F_8 ( V_1 -> V_40 , V_37 , V_41 , V_2 ) == - 1 )
return FALSE ;
return F_7 ( V_1 , V_1 -> V_40 , V_35 , V_39 , V_2 , V_3 ) ;
}
static T_3 F_7 ( T_1 * V_1 , T_6 V_11 ,
struct V_38 * V_35 , T_5 * V_39 , int * V_2 , T_2 * * V_3 )
{
struct V_42 V_6 ;
T_7 V_43 ;
T_7 V_44 ;
T_7 V_45 ;
T_4 V_46 ;
V_9 = V_10 ;
if ( ! F_9 ( V_11 , & V_6 , sizeof V_6 , V_2 , V_3 ) )
return FALSE ;
V_43 = F_4 ( V_6 . V_47 ) ;
V_45 = F_4 ( V_6 . V_48 ) ;
V_44 = F_4 ( V_6 . V_44 ) ;
if ( V_43 > V_49 ) {
* V_2 = V_50 ;
* V_3 = F_5 ( L_6 ,
V_43 , V_49 ) ;
return FALSE ;
}
V_46 = F_10 ( V_6 . V_51 ) ;
V_46 -= V_52 ;
V_35 -> V_53 = V_54 ;
V_35 -> V_55 = V_56 | V_57 ;
V_35 -> V_46 . V_58 = ( V_59 ) ( V_46 / 1000000 ) ;
V_35 -> V_46 . V_60 = ( V_59 ) ( ( V_46 % 1000000 ) * 1000 ) ;
V_35 -> V_61 = V_43 ;
V_35 -> V_62 = V_45 ;
if( V_1 -> V_7 == V_19 )
{
V_35 -> V_63 . V_64 . V_65 = ( V_44 & V_66 ) ? FALSE : TRUE ;
} else if( V_1 -> V_7 == V_17 ) {
V_35 -> V_63 . V_67 . V_65 = ( V_44 & V_66 ) ? FALSE : TRUE ;
if( V_44 & V_68 )
{
if( V_35 -> V_63 . V_67 . V_65 )
{
V_35 -> V_63 . V_67 . V_69 = V_70 ;
}
else
{
V_35 -> V_63 . V_67 . V_69 = V_71 ;
}
}
else
{
V_35 -> V_63 . V_67 . V_69 = V_72 ;
}
} else if ( V_1 -> V_7 == V_23 ) {
V_35 -> V_63 . V_73 . V_74 = V_44 & 0xFFFF ;
V_35 -> V_63 . V_73 . V_75 = V_44 >> 16 ;
}
return F_11 ( V_11 , V_39 , V_35 -> V_61 , V_2 , V_3 ) ;
}
int F_12 ( int V_76 )
{
if ( V_76 == V_77 )
return V_78 ;
if ( V_76 != V_19 && V_76 != V_23 )
return V_79 ;
return 0 ;
}
static T_8 F_13 ( T_8 V_80 , T_3 V_65 , T_8 * V_44 )
{
T_8 V_81 ;
for ( V_81 = 0 ; V_81 < F_14 ( V_82 ) ; ++ V_81 )
{
if ( V_82 [ V_81 ] . V_80 == V_80 &&
V_82 [ V_81 ] . V_65 == V_65 )
{
* V_44 = V_82 [ V_81 ] . V_44 ;
return TRUE ;
}
}
return FALSE ;
}
static T_3 F_15 ( T_9 * T_10 V_83 ,
const struct V_38 * V_35 ,
const union V_84 * V_63 ,
const T_8 * V_85 , int * V_2 ,
struct V_42 * V_86 )
{
T_4 V_51 ;
T_4 V_60 ;
T_8 V_44 = 0 ;
if ( ! F_13 ( * V_85 , V_63 -> V_64 . V_65 , & V_44 ) ) {
* V_2 = V_14 ;
return FALSE ;
}
V_60 = V_35 -> V_46 . V_60 ;
V_51 = ( ( T_4 ) V_35 -> V_46 . V_58 * 1000000 ) + ( V_60 / 1000 ) ;
V_51 += V_52 ;
V_86 -> V_44 = F_16 ( V_44 ) ;
V_86 -> V_87 = F_16 ( 0 ) ;
V_86 -> V_51 = F_17 ( V_51 ) ;
return TRUE ;
}
static T_3 F_18 ( T_9 * T_10 ,
const struct V_38 * V_35 ,
const T_8 * V_85 , int * V_2 )
{
const union V_84 * V_63 = & V_35 -> V_63 ;
struct V_42 V_86 ;
if ( V_35 -> V_53 != V_54 ) {
* V_2 = V_88 ;
return FALSE ;
}
if ( V_35 -> V_61 - 1 > V_49 ) {
* V_2 = V_89 ;
return FALSE ;
}
if ( ! F_15 ( T_10 , V_35 , V_63 , V_85 , V_2 , & V_86 ) )
return FALSE ;
V_86 . V_47 = F_16 ( V_35 -> V_61 - 1 ) ;
V_86 . V_48 = F_16 ( V_35 -> V_62 - 1 ) ;
if ( ! F_19 ( T_10 , & V_86 , sizeof V_86 , V_2 ) )
return FALSE ;
T_10 -> V_90 += sizeof V_86 ;
++ V_85 ;
if ( ! F_19 ( T_10 , V_85 , V_35 -> V_61 - 1 , V_2 ) )
return FALSE ;
T_10 -> V_90 += V_35 -> V_61 - 1 ;
return TRUE ;
}
static T_3 F_20 ( T_9 * T_10 ,
const struct V_38 * V_35 ,
const T_8 * V_85 , int * V_2 )
{
const union V_84 * V_63 = & V_35 -> V_63 ;
struct V_42 V_86 ;
if ( V_35 -> V_53 != V_54 ) {
* V_2 = V_88 ;
return FALSE ;
}
if ( V_35 -> V_61 > V_49 ) {
* V_2 = V_89 ;
return FALSE ;
}
if ( ! F_15 ( T_10 , V_35 , V_63 , V_85 , V_2 , & V_86 ) )
return FALSE ;
V_86 . V_47 = F_16 ( V_35 -> V_61 ) ;
V_86 . V_48 = F_16 ( V_35 -> V_62 ) ;
if ( ! F_19 ( T_10 , & V_86 , sizeof V_86 , V_2 ) )
return FALSE ;
T_10 -> V_90 += sizeof V_86 ;
if ( ! F_19 ( T_10 , V_85 , V_35 -> V_61 , V_2 ) )
return FALSE ;
T_10 -> V_90 += V_35 -> V_61 ;
return TRUE ;
}
T_3 F_21 ( T_9 * T_10 , int * V_2 )
{
struct V_5 V_91 ;
T_10 -> V_92 = F_18 ;
T_10 -> V_93 = NULL ;
switch ( T_10 -> V_32 ) {
case V_33 :
T_10 -> V_94 = V_31 ;
break;
default:
* V_2 = V_95 ;
return FALSE ;
}
if ( ! F_19 ( T_10 , F_2 , sizeof F_2 , V_2 ) )
return FALSE ;
T_10 -> V_90 += sizeof F_2 ;
V_91 . V_13 = F_16 ( 1 ) ;
V_91 . V_15 = F_16 ( V_16 ) ;
if ( ! F_19 ( T_10 , & V_91 , sizeof V_91 , V_2 ) )
return FALSE ;
T_10 -> V_90 += sizeof V_91 ;
return TRUE ;
}
T_3 F_22 ( T_9 * T_10 , int * V_2 )
{
struct V_5 V_91 ;
T_10 -> V_92 = F_20 ;
T_10 -> V_93 = NULL ;
switch ( T_10 -> V_32 ) {
case V_33 :
T_10 -> V_94 = V_31 ;
break;
default:
* V_2 = V_95 ;
return FALSE ;
}
if ( ! F_19 ( T_10 , F_2 , sizeof F_2 , V_2 ) )
return FALSE ;
T_10 -> V_90 += sizeof F_2 ;
V_91 . V_13 = F_16 ( 1 ) ;
V_91 . V_15 = F_16 ( V_18 ) ;
if ( ! F_19 ( T_10 , & V_91 , sizeof V_91 , V_2 ) )
return FALSE ;
T_10 -> V_90 += sizeof V_91 ;
return TRUE ;
}
