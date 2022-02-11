T_1 F_1 ( T_2 * V_1 , int * V_2 , T_3 * * V_3 )
{
char V_4 [ sizeof F_2 ] ;
struct V_5 V_6 ;
int V_7 = V_8 ;
if ( ! F_3 ( V_1 -> V_9 , V_4 , sizeof V_4 , V_2 , V_3 ) ) {
if ( * V_2 != V_10 )
return V_11 ;
return V_12 ;
}
if ( memcmp ( V_4 , F_2 , sizeof F_2 ) != 0 ) {
return V_12 ;
}
if ( ! F_3 ( V_1 -> V_9 , & V_6 , sizeof V_6 , V_2 , V_3 ) )
return V_11 ;
V_6 . V_13 = F_4 ( V_6 . V_13 ) ;
if ( V_6 . V_13 != 1 ) {
* V_2 = V_14 ;
* V_3 = F_5 ( L_1 , V_6 . V_13 ) ;
return V_11 ;
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
return V_11 ;
case V_21 :
* V_2 = V_14 ;
* V_3 = F_5 ( L_3 ) ;
return V_11 ;
case V_22 :
V_7 = V_23 ;
break;
case V_24 :
* V_2 = V_14 ;
* V_3 = F_5 ( L_4 ) ;
return V_11 ;
default:
* V_2 = V_14 ;
* V_3 = F_5 ( L_5 , V_6 . V_15 ) ;
return V_11 ;
}
V_1 -> V_25 = V_26 ;
V_1 -> V_27 = V_28 ;
V_1 -> V_7 = V_7 ;
V_1 -> V_29 = 0 ;
V_1 -> V_30 = V_31 ;
V_1 -> V_32 = V_33 ;
return V_34 ;
}
static T_4 V_26 ( T_2 * V_1 , int * V_2 , T_3 * * V_3 ,
T_5 * V_35 )
{
* V_35 = F_6 ( V_1 -> V_9 ) ;
return F_7 ( V_1 , V_1 -> V_9 , & V_1 -> V_36 , V_1 -> V_37 ,
V_2 , V_3 ) ;
}
static T_4 V_28 ( T_2 * V_1 , T_5 V_38 ,
struct V_39 * V_36 , T_6 * V_40 , int * V_2 , T_3 * * V_3 )
{
if ( F_8 ( V_1 -> V_41 , V_38 , V_42 , V_2 ) == - 1 )
return FALSE ;
return F_7 ( V_1 , V_1 -> V_41 , V_36 , V_40 , V_2 , V_3 ) ;
}
static T_4 F_7 ( T_2 * V_1 , T_7 V_9 ,
struct V_39 * V_36 , T_6 * V_40 , int * V_2 , T_3 * * V_3 )
{
struct V_43 V_6 ;
T_8 V_44 ;
T_8 V_45 ;
T_8 V_46 ;
T_5 V_47 ;
if ( ! F_9 ( V_9 , & V_6 , sizeof V_6 , V_2 , V_3 ) )
return FALSE ;
V_44 = F_4 ( V_6 . V_48 ) ;
V_46 = F_4 ( V_6 . V_49 ) ;
V_45 = F_4 ( V_6 . V_45 ) ;
if ( V_44 > V_50 ) {
* V_2 = V_51 ;
* V_3 = F_5 ( L_6 ,
V_44 , V_50 ) ;
return FALSE ;
}
V_47 = F_10 ( V_6 . V_52 ) ;
V_47 -= V_53 ;
V_36 -> V_54 = V_55 ;
V_36 -> V_56 = V_1 -> V_7 ;
V_36 -> V_57 = V_58 | V_59 ;
V_36 -> V_47 . V_60 = ( V_61 ) ( V_47 / 1000000 ) ;
V_36 -> V_47 . V_62 = ( V_61 ) ( ( V_47 % 1000000 ) * 1000 ) ;
V_36 -> V_63 = V_44 ;
V_36 -> V_64 = V_46 ;
if( V_1 -> V_7 == V_19 )
{
V_36 -> V_65 . V_66 . V_67 = ( V_45 & V_68 ) ? FALSE : TRUE ;
} else if( V_1 -> V_7 == V_17 ) {
V_36 -> V_65 . V_69 . V_67 = ( V_45 & V_68 ) ? FALSE : TRUE ;
if( V_45 & V_70 )
{
if( V_36 -> V_65 . V_69 . V_67 )
{
V_36 -> V_65 . V_69 . V_71 = V_72 ;
}
else
{
V_36 -> V_65 . V_69 . V_71 = V_73 ;
}
}
else
{
V_36 -> V_65 . V_69 . V_71 = V_74 ;
}
} else if ( V_1 -> V_7 == V_23 ) {
V_36 -> V_65 . V_75 . V_76 = V_45 & 0xFFFF ;
V_36 -> V_65 . V_75 . V_77 = V_45 >> 16 ;
}
return F_11 ( V_9 , V_40 , V_36 -> V_63 , V_2 , V_3 ) ;
}
int F_12 ( int V_78 )
{
if ( V_78 == V_79 )
return V_80 ;
if ( V_78 != V_19 && V_78 != V_23 )
return V_81 ;
return 0 ;
}
static T_9 F_13 ( T_9 V_82 , T_4 V_67 , T_9 * V_45 )
{
T_9 V_83 ;
for ( V_83 = 0 ; V_83 < F_14 ( V_84 ) ; ++ V_83 )
{
if ( V_84 [ V_83 ] . V_82 == V_82 &&
V_84 [ V_83 ] . V_67 == V_67 )
{
* V_45 = V_84 [ V_83 ] . V_45 ;
return TRUE ;
}
}
return FALSE ;
}
static T_4 F_15 (
const struct V_39 * V_36 ,
const union V_85 * V_65 ,
const T_9 * V_86 , int * V_2 , T_3 * * V_3 ,
struct V_43 * V_87 )
{
T_5 V_52 ;
T_5 V_62 ;
T_9 V_45 = 0 ;
if ( ! F_13 ( * V_86 , V_65 -> V_66 . V_67 , & V_45 ) ) {
* V_2 = V_88 ;
* V_3 = F_5 ( L_7 ,
* V_86 ,
V_65 -> V_66 . V_67 ? L_8 : L_9 ) ;
return FALSE ;
}
V_62 = V_36 -> V_47 . V_62 ;
V_52 = ( ( T_5 ) V_36 -> V_47 . V_60 * 1000000 ) + ( V_62 / 1000 ) ;
V_52 += V_53 ;
V_87 -> V_45 = F_16 ( V_45 ) ;
V_87 -> V_89 = F_16 ( 0 ) ;
V_87 -> V_52 = F_17 ( V_52 ) ;
return TRUE ;
}
static T_4 F_18 ( T_10 * V_90 ,
const struct V_39 * V_36 ,
const T_9 * V_86 , int * V_2 , T_3 * * V_3 )
{
const union V_85 * V_65 = & V_36 -> V_65 ;
struct V_43 V_87 ;
if ( V_36 -> V_54 != V_55 ) {
* V_2 = V_91 ;
return FALSE ;
}
if ( V_36 -> V_63 - 1 > V_50 ) {
* V_2 = V_92 ;
return FALSE ;
}
if ( ! F_15 ( V_36 , V_65 , V_86 , V_2 , V_3 ,
& V_87 ) )
return FALSE ;
V_87 . V_48 = F_16 ( V_36 -> V_63 - 1 ) ;
V_87 . V_49 = F_16 ( V_36 -> V_64 - 1 ) ;
if ( ! F_19 ( V_90 , & V_87 , sizeof V_87 , V_2 ) )
return FALSE ;
V_90 -> V_93 += sizeof V_87 ;
++ V_86 ;
if ( ! F_19 ( V_90 , V_86 , V_36 -> V_63 - 1 , V_2 ) )
return FALSE ;
V_90 -> V_93 += V_36 -> V_63 - 1 ;
return TRUE ;
}
static T_4 F_20 ( T_10 * V_90 ,
const struct V_39 * V_36 ,
const T_9 * V_86 , int * V_2 , T_3 * * V_3 )
{
const union V_85 * V_65 = & V_36 -> V_65 ;
struct V_43 V_87 ;
if ( V_36 -> V_54 != V_55 ) {
* V_2 = V_91 ;
return FALSE ;
}
if ( V_36 -> V_63 > V_50 ) {
* V_2 = V_92 ;
return FALSE ;
}
if ( ! F_15 ( V_36 , V_65 , V_86 , V_2 , V_3 ,
& V_87 ) )
return FALSE ;
V_87 . V_48 = F_16 ( V_36 -> V_63 ) ;
V_87 . V_49 = F_16 ( V_36 -> V_64 ) ;
if ( ! F_19 ( V_90 , & V_87 , sizeof V_87 , V_2 ) )
return FALSE ;
V_90 -> V_93 += sizeof V_87 ;
if ( ! F_19 ( V_90 , V_86 , V_36 -> V_63 , V_2 ) )
return FALSE ;
V_90 -> V_93 += V_36 -> V_63 ;
return TRUE ;
}
T_4 F_21 ( T_10 * V_90 , int * V_2 )
{
struct V_5 V_94 ;
V_90 -> V_95 = F_18 ;
switch ( V_90 -> V_32 ) {
case V_33 :
V_90 -> V_96 = V_31 ;
break;
default:
* V_2 = V_97 ;
return FALSE ;
}
if ( ! F_19 ( V_90 , F_2 , sizeof F_2 , V_2 ) )
return FALSE ;
V_90 -> V_93 += sizeof F_2 ;
V_94 . V_13 = F_16 ( 1 ) ;
V_94 . V_15 = F_16 ( V_16 ) ;
if ( ! F_19 ( V_90 , & V_94 , sizeof V_94 , V_2 ) )
return FALSE ;
V_90 -> V_93 += sizeof V_94 ;
return TRUE ;
}
T_4 F_22 ( T_10 * V_90 , int * V_2 )
{
struct V_5 V_94 ;
V_90 -> V_95 = F_20 ;
switch ( V_90 -> V_32 ) {
case V_33 :
V_90 -> V_96 = V_31 ;
break;
default:
* V_2 = V_97 ;
return FALSE ;
}
if ( ! F_19 ( V_90 , F_2 , sizeof F_2 , V_2 ) )
return FALSE ;
V_90 -> V_93 += sizeof F_2 ;
V_94 . V_13 = F_16 ( 1 ) ;
V_94 . V_15 = F_16 ( V_18 ) ;
if ( ! F_19 ( V_90 , & V_94 , sizeof V_94 , V_2 ) )
return FALSE ;
V_90 -> V_93 += sizeof V_94 ;
return TRUE ;
}
