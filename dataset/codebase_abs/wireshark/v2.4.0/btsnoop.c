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
* V_3 = F_6 ( L_2 ) ;
return V_11 ;
case V_21 :
* V_2 = V_14 ;
* V_3 = F_6 ( L_3 ) ;
return V_11 ;
case V_22 :
V_7 = V_23 ;
break;
case V_24 :
* V_2 = V_14 ;
* V_3 = F_6 ( L_4 ) ;
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
* V_35 = F_7 ( V_1 -> V_9 ) ;
return F_8 ( V_1 , V_1 -> V_9 , & V_1 -> V_36 , V_1 -> V_37 ,
V_2 , V_3 ) ;
}
static T_4 V_28 ( T_2 * V_1 , T_5 V_38 ,
struct V_39 * V_36 , T_6 * V_40 , int * V_2 , T_3 * * V_3 )
{
if ( F_9 ( V_1 -> V_41 , V_38 , V_42 , V_2 ) == - 1 )
return FALSE ;
return F_8 ( V_1 , V_1 -> V_41 , V_36 , V_40 , V_2 , V_3 ) ;
}
static T_4 F_8 ( T_2 * V_1 , T_7 V_9 ,
struct V_39 * V_36 , T_6 * V_40 , int * V_2 , T_3 * * V_3 )
{
struct V_43 V_6 ;
T_8 V_44 ;
T_8 V_45 ;
T_8 V_46 ;
T_5 V_47 ;
if ( ! F_10 ( V_9 , & V_6 , sizeof V_6 , V_2 , V_3 ) )
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
V_47 = F_11 ( V_6 . V_52 ) ;
V_47 -= V_53 ;
V_36 -> V_54 = V_55 ;
V_36 -> V_56 = V_57 | V_58 ;
V_36 -> V_47 . V_59 = ( V_60 ) ( V_47 / 1000000 ) ;
V_36 -> V_47 . V_61 = ( V_60 ) ( ( V_47 % 1000000 ) * 1000 ) ;
V_36 -> V_62 = V_44 ;
V_36 -> V_63 = V_46 ;
if( V_1 -> V_7 == V_19 )
{
V_36 -> V_64 . V_65 . V_66 = ( V_45 & V_67 ) ? FALSE : TRUE ;
} else if( V_1 -> V_7 == V_17 ) {
V_36 -> V_64 . V_68 . V_66 = ( V_45 & V_67 ) ? FALSE : TRUE ;
if( V_45 & V_69 )
{
if( V_36 -> V_64 . V_68 . V_66 )
{
V_36 -> V_64 . V_68 . V_70 = V_71 ;
}
else
{
V_36 -> V_64 . V_68 . V_70 = V_72 ;
}
}
else
{
V_36 -> V_64 . V_68 . V_70 = V_73 ;
}
} else if ( V_1 -> V_7 == V_23 ) {
V_36 -> V_64 . V_74 . V_75 = V_45 & 0xFFFF ;
V_36 -> V_64 . V_74 . V_76 = V_45 >> 16 ;
}
return F_12 ( V_9 , V_40 , V_36 -> V_62 , V_2 , V_3 ) ;
}
int F_13 ( int V_77 )
{
if ( V_77 == V_78 )
return V_79 ;
if ( V_77 != V_19 && V_77 != V_23 )
return V_80 ;
return 0 ;
}
static T_9 F_14 ( T_9 V_81 , T_4 V_66 , T_9 * V_45 )
{
T_9 V_82 ;
for ( V_82 = 0 ; V_82 < F_15 ( V_83 ) ; ++ V_82 )
{
if ( V_83 [ V_82 ] . V_81 == V_81 &&
V_83 [ V_82 ] . V_66 == V_66 )
{
* V_45 = V_83 [ V_82 ] . V_45 ;
return TRUE ;
}
}
return FALSE ;
}
static T_4 F_16 (
const struct V_39 * V_36 ,
const union V_84 * V_64 ,
const T_9 * V_85 , int * V_2 , T_3 * * V_3 ,
struct V_43 * V_86 )
{
T_5 V_52 ;
T_5 V_61 ;
T_9 V_45 = 0 ;
if ( ! F_14 ( * V_85 , V_64 -> V_65 . V_66 , & V_45 ) ) {
* V_2 = V_87 ;
* V_3 = F_5 ( L_7 ,
* V_85 ,
V_64 -> V_65 . V_66 ? L_8 : L_9 ) ;
return FALSE ;
}
V_61 = V_36 -> V_47 . V_61 ;
V_52 = ( ( T_5 ) V_36 -> V_47 . V_59 * 1000000 ) + ( V_61 / 1000 ) ;
V_52 += V_53 ;
V_86 -> V_45 = F_17 ( V_45 ) ;
V_86 -> V_88 = F_17 ( 0 ) ;
V_86 -> V_52 = F_18 ( V_52 ) ;
return TRUE ;
}
static T_4 F_19 ( T_10 * V_89 ,
const struct V_39 * V_36 ,
const T_9 * V_85 , int * V_2 , T_3 * * V_3 )
{
const union V_84 * V_64 = & V_36 -> V_64 ;
struct V_43 V_86 ;
if ( V_36 -> V_54 != V_55 ) {
* V_2 = V_90 ;
return FALSE ;
}
if ( V_36 -> V_62 - 1 > V_50 ) {
* V_2 = V_91 ;
return FALSE ;
}
if ( ! F_16 ( V_36 , V_64 , V_85 , V_2 , V_3 ,
& V_86 ) )
return FALSE ;
V_86 . V_48 = F_17 ( V_36 -> V_62 - 1 ) ;
V_86 . V_49 = F_17 ( V_36 -> V_63 - 1 ) ;
if ( ! F_20 ( V_89 , & V_86 , sizeof V_86 , V_2 ) )
return FALSE ;
V_89 -> V_92 += sizeof V_86 ;
++ V_85 ;
if ( ! F_20 ( V_89 , V_85 , V_36 -> V_62 - 1 , V_2 ) )
return FALSE ;
V_89 -> V_92 += V_36 -> V_62 - 1 ;
return TRUE ;
}
static T_4 F_21 ( T_10 * V_89 ,
const struct V_39 * V_36 ,
const T_9 * V_85 , int * V_2 , T_3 * * V_3 )
{
const union V_84 * V_64 = & V_36 -> V_64 ;
struct V_43 V_86 ;
if ( V_36 -> V_54 != V_55 ) {
* V_2 = V_90 ;
return FALSE ;
}
if ( V_36 -> V_62 > V_50 ) {
* V_2 = V_91 ;
return FALSE ;
}
if ( ! F_16 ( V_36 , V_64 , V_85 , V_2 , V_3 ,
& V_86 ) )
return FALSE ;
V_86 . V_48 = F_17 ( V_36 -> V_62 ) ;
V_86 . V_49 = F_17 ( V_36 -> V_63 ) ;
if ( ! F_20 ( V_89 , & V_86 , sizeof V_86 , V_2 ) )
return FALSE ;
V_89 -> V_92 += sizeof V_86 ;
if ( ! F_20 ( V_89 , V_85 , V_36 -> V_62 , V_2 ) )
return FALSE ;
V_89 -> V_92 += V_36 -> V_62 ;
return TRUE ;
}
T_4 F_22 ( T_10 * V_89 , int * V_2 )
{
struct V_5 V_93 ;
V_89 -> V_94 = F_19 ;
if ( ! F_20 ( V_89 , F_2 , sizeof F_2 , V_2 ) )
return FALSE ;
V_89 -> V_92 += sizeof F_2 ;
V_93 . V_13 = F_17 ( 1 ) ;
V_93 . V_15 = F_17 ( V_16 ) ;
if ( ! F_20 ( V_89 , & V_93 , sizeof V_93 , V_2 ) )
return FALSE ;
V_89 -> V_92 += sizeof V_93 ;
return TRUE ;
}
T_4 F_23 ( T_10 * V_89 , int * V_2 )
{
struct V_5 V_93 ;
V_89 -> V_94 = F_21 ;
if ( ! F_20 ( V_89 , F_2 , sizeof F_2 , V_2 ) )
return FALSE ;
V_89 -> V_92 += sizeof F_2 ;
V_93 . V_13 = F_17 ( 1 ) ;
V_93 . V_15 = F_17 ( V_18 ) ;
if ( ! F_20 ( V_89 , & V_93 , sizeof V_93 , V_2 ) )
return FALSE ;
V_89 -> V_92 += sizeof V_93 ;
return TRUE ;
}
