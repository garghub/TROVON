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
V_8 = V_20 ;
break;
case V_21 :
* V_2 = V_15 ;
* V_3 = F_6 ( L_2 ) ;
return - 1 ;
case V_22 :
* V_2 = V_15 ;
* V_3 = F_6 ( L_3 ) ;
return - 1 ;
case V_23 :
V_8 = V_24 ;
break;
case V_25 :
* V_2 = V_15 ;
* V_3 = F_6 ( L_4 ) ;
return - 1 ;
default:
* V_2 = V_15 ;
* V_3 = F_6 ( L_5 , V_7 . V_16 ) ;
return - 1 ;
}
V_1 -> V_26 = V_27 ;
V_1 -> V_28 = V_29 ;
V_1 -> V_8 = V_8 ;
V_1 -> V_30 = 0 ;
V_1 -> V_31 = V_32 ;
V_1 -> V_33 = V_34 ;
return 1 ;
}
static T_3 V_27 ( T_1 * V_1 , int * V_2 , T_2 * * V_3 ,
T_4 * V_35 )
{
* V_35 = F_7 ( V_1 -> V_12 ) ;
return F_8 ( V_1 , V_1 -> V_12 , & V_1 -> V_36 , V_1 -> V_37 ,
V_2 , V_3 ) ;
}
static T_3 V_29 ( T_1 * V_1 , T_4 V_38 ,
struct V_39 * V_36 , T_5 * V_40 , int * V_2 , T_2 * * V_3 )
{
if ( F_9 ( V_1 -> V_41 , V_38 , V_42 , V_2 ) == - 1 )
return FALSE ;
return F_8 ( V_1 , V_1 -> V_41 , V_36 , V_40 , V_2 , V_3 ) ;
}
static T_3 F_8 ( T_1 * V_1 , T_6 V_12 ,
struct V_39 * V_36 , T_5 * V_40 , int * V_2 , T_2 * * V_3 )
{
int V_4 ;
struct V_43 V_7 ;
T_7 V_44 ;
T_7 V_45 ;
T_7 V_46 ;
T_4 V_47 ;
V_10 = V_11 ;
V_4 = F_3 ( & V_7 , sizeof V_7 , V_12 ) ;
if ( V_4 != sizeof V_7 ) {
* V_2 = F_4 ( V_12 , V_3 ) ;
if ( * V_2 == 0 && V_4 != 0 )
* V_2 = V_13 ;
return FALSE ;
}
V_44 = F_5 ( V_7 . V_48 ) ;
V_46 = F_5 ( V_7 . V_49 ) ;
V_45 = F_5 ( V_7 . V_45 ) ;
if ( V_44 > V_50 ) {
* V_2 = V_51 ;
* V_3 = F_6 ( L_6 ,
V_44 , V_50 ) ;
return FALSE ;
}
V_47 = F_10 ( V_7 . V_52 ) ;
V_47 -= V_53 ;
V_36 -> V_54 = V_55 ;
V_36 -> V_56 = V_57 | V_58 ;
V_36 -> V_47 . V_59 = ( V_60 ) ( V_47 / 1000000 ) ;
V_36 -> V_47 . V_61 = ( V_60 ) ( ( V_47 % 1000000 ) * 1000 ) ;
V_36 -> V_62 = V_44 ;
V_36 -> V_63 = V_46 ;
if( V_1 -> V_8 == V_20 )
{
V_36 -> V_64 . V_65 . V_66 = ( V_45 & V_67 ) ? FALSE : TRUE ;
} else if( V_1 -> V_8 == V_18 ) {
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
} else if ( V_1 -> V_8 == V_24 ) {
V_36 -> V_64 . V_74 . V_75 = V_45 & 0xFFFF ;
V_36 -> V_64 . V_74 . V_76 = V_45 >> 16 ;
}
return F_11 ( V_12 , V_40 , V_36 -> V_62 , V_2 , V_3 ) ;
}
int F_12 ( int V_77 )
{
if ( V_77 == V_78 )
return V_79 ;
if ( V_77 != V_20 && V_77 != V_24 )
return V_80 ;
return 0 ;
}
static T_8 F_13 ( T_8 V_81 , T_3 V_66 , T_8 * V_45 )
{
T_8 V_82 ;
for ( V_82 = 0 ; V_82 < F_14 ( V_83 ) ; ++ V_82 )
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
static T_3 F_15 ( T_9 * T_10 V_84 ,
const struct V_39 * V_36 ,
const union V_85 * V_64 ,
const T_8 * V_86 , int * V_2 ,
struct V_43 * V_87 )
{
T_4 V_52 ;
T_4 V_61 ;
T_8 V_45 = 0 ;
if ( ! F_13 ( * V_86 , V_64 -> V_65 . V_66 , & V_45 ) ) {
* V_2 = V_15 ;
return FALSE ;
}
V_61 = V_36 -> V_47 . V_61 ;
V_52 = ( ( T_4 ) V_36 -> V_47 . V_59 * 1000000 ) + ( V_61 / 1000 ) ;
V_52 += V_53 ;
V_87 -> V_45 = F_16 ( V_45 ) ;
V_87 -> V_88 = F_16 ( 0 ) ;
V_87 -> V_52 = F_17 ( V_52 ) ;
return TRUE ;
}
static T_3 F_18 ( T_9 * T_10 ,
const struct V_39 * V_36 ,
const T_8 * V_86 , int * V_2 )
{
const union V_85 * V_64 = & V_36 -> V_64 ;
struct V_43 V_87 ;
if ( V_36 -> V_54 != V_55 ) {
* V_2 = V_89 ;
return FALSE ;
}
if ( V_36 -> V_62 - 1 > V_50 ) {
* V_2 = V_90 ;
return FALSE ;
}
if ( ! F_15 ( T_10 , V_36 , V_64 , V_86 , V_2 , & V_87 ) )
return FALSE ;
V_87 . V_48 = F_16 ( V_36 -> V_62 - 1 ) ;
V_87 . V_49 = F_16 ( V_36 -> V_63 - 1 ) ;
if ( ! F_19 ( T_10 , & V_87 , sizeof V_87 , V_2 ) )
return FALSE ;
T_10 -> V_91 += sizeof V_87 ;
++ V_86 ;
if ( ! F_19 ( T_10 , V_86 , V_36 -> V_62 - 1 , V_2 ) )
return FALSE ;
T_10 -> V_91 += V_36 -> V_62 - 1 ;
return TRUE ;
}
static T_3 F_20 ( T_9 * T_10 ,
const struct V_39 * V_36 ,
const T_8 * V_86 , int * V_2 )
{
const union V_85 * V_64 = & V_36 -> V_64 ;
struct V_43 V_87 ;
if ( V_36 -> V_54 != V_55 ) {
* V_2 = V_89 ;
return FALSE ;
}
if ( V_36 -> V_62 > V_50 ) {
* V_2 = V_90 ;
return FALSE ;
}
if ( ! F_15 ( T_10 , V_36 , V_64 , V_86 , V_2 , & V_87 ) )
return FALSE ;
V_87 . V_48 = F_16 ( V_36 -> V_62 ) ;
V_87 . V_49 = F_16 ( V_36 -> V_63 ) ;
if ( ! F_19 ( T_10 , & V_87 , sizeof V_87 , V_2 ) )
return FALSE ;
T_10 -> V_91 += sizeof V_87 ;
if ( ! F_19 ( T_10 , V_86 , V_36 -> V_62 , V_2 ) )
return FALSE ;
T_10 -> V_91 += V_36 -> V_62 ;
return TRUE ;
}
T_3 F_21 ( T_9 * T_10 , int * V_2 )
{
struct V_6 V_92 ;
T_10 -> V_93 = F_18 ;
T_10 -> V_94 = NULL ;
switch ( T_10 -> V_33 ) {
case V_34 :
T_10 -> V_31 = V_32 ;
break;
default:
* V_2 = V_95 ;
return FALSE ;
}
if ( ! F_19 ( T_10 , F_2 , sizeof F_2 , V_2 ) )
return FALSE ;
T_10 -> V_91 += sizeof F_2 ;
V_92 . V_14 = F_16 ( 1 ) ;
V_92 . V_16 = F_16 ( V_17 ) ;
if ( ! F_19 ( T_10 , & V_92 , sizeof V_92 , V_2 ) )
return FALSE ;
T_10 -> V_91 += sizeof V_92 ;
return TRUE ;
}
T_3 F_22 ( T_9 * T_10 , int * V_2 )
{
struct V_6 V_92 ;
T_10 -> V_93 = F_20 ;
T_10 -> V_94 = NULL ;
switch ( T_10 -> V_33 ) {
case V_34 :
T_10 -> V_31 = V_32 ;
break;
default:
* V_2 = V_95 ;
return FALSE ;
}
if ( ! F_19 ( T_10 , F_2 , sizeof F_2 , V_2 ) )
return FALSE ;
T_10 -> V_91 += sizeof F_2 ;
V_92 . V_14 = F_16 ( 1 ) ;
V_92 . V_16 = F_16 ( V_19 ) ;
if ( ! F_19 ( T_10 , & V_92 , sizeof V_92 , V_2 ) )
return FALSE ;
T_10 -> V_91 += sizeof V_92 ;
return TRUE ;
}
