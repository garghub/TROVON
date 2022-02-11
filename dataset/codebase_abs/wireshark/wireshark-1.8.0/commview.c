int F_1 ( T_1 * V_1 , int * V_2 , T_2 * * V_3 )
{
T_3 V_4 ;
if( ! F_2 ( & V_4 , V_1 -> V_5 , V_2 , V_3 ) )
return - 1 ;
if( V_4 . V_6 != 0 ||
V_4 . V_7 < 1970 || V_4 . V_7 >= 2038 ||
V_4 . V_8 < 1 || V_4 . V_8 > 12 ||
V_4 . V_9 < 1 || V_4 . V_9 > 31 ||
V_4 . V_10 > 23 ||
V_4 . V_11 > 59 ||
V_4 . V_12 > 60 ||
V_4 . V_13 > 100 ||
( V_4 . V_14 & V_15 ) != 0 ||
( ( V_4 . V_14 & V_16 ) != V_17 &&
( V_4 . V_14 & V_16 ) != V_18 &&
( V_4 . V_14 & V_16 ) != V_19 ) )
return 0 ;
if ( F_3 ( V_1 -> V_5 , 0 , V_20 , V_2 ) == - 1 )
return - 1 ;
V_1 -> V_21 = V_22 ;
V_1 -> V_23 = V_24 ;
V_1 -> V_25 = V_26 ;
V_1 -> V_27 = V_28 ;
V_1 -> V_29 = V_30 ;
return 1 ;
}
static void
F_4 ( T_3 * V_31 , union V_32
* V_33 )
{
switch( V_31 -> V_14 & V_16 ) {
case V_17 :
V_33 -> V_34 . V_35 = - 1 ;
break;
case V_18 :
V_33 -> V_36 . V_35 = - 1 ;
V_33 -> V_36 . V_37 = V_31 -> V_37 ;
V_33 -> V_36 . V_38 = V_31 -> V_39 ;
V_33 -> V_36 . V_40 = V_31 -> V_13 ;
break;
default :
break;
}
}
static T_4
V_22 ( T_1 * V_1 , int * V_2 , T_2 * * V_3 , T_5 * V_41 )
{
T_3 V_4 ;
struct V_42 V_42 ;
int V_43 ;
* V_41 = F_5 ( V_1 -> V_5 ) ;
if( ! F_2 ( & V_4 , V_1 -> V_5 , V_2 , V_3 ) )
return FALSE ;
switch( V_4 . V_14 & V_16 ) {
case V_17 :
V_1 -> V_44 . V_45 = V_46 ;
break;
case V_18 :
V_1 -> V_44 . V_45 = V_47 ;
break;
case V_19 :
V_1 -> V_44 . V_45 = V_48 ;
break;
default :
* V_2 = V_49 ;
* V_3 = F_6 ( L_1 ,
V_4 . V_14 & V_16 ) ;
return FALSE ;
}
F_4 ( & V_4 , & V_1 -> V_33 ) ;
F_7 ( V_1 -> V_50 , V_4 . V_51 ) ;
V_43 = F_8 ( F_9 ( V_1 -> V_50 ) ,
V_4 . V_51 , V_1 -> V_5 ) ;
if( V_43 != V_4 . V_51 ) {
* V_2 = F_10 ( V_1 -> V_5 , V_3 ) ;
if( * V_2 == 0 )
* V_2 = V_52 ;
return FALSE ;
}
V_42 . V_53 = V_4 . V_7 - 1900 ;
V_42 . V_54 = V_4 . V_8 - 1 ;
V_42 . V_55 = V_4 . V_9 ;
V_42 . V_56 = V_4 . V_10 ;
V_42 . V_57 = V_4 . V_11 ;
V_42 . V_58 = V_4 . V_12 ;
V_42 . V_59 = - 1 ;
V_1 -> V_44 . V_60 = V_61 ;
V_1 -> V_44 . V_62 = V_4 . V_51 ;
V_1 -> V_44 . V_63 = V_4 . V_51 ;
V_1 -> V_44 . V_64 . V_65 = mktime ( & V_42 ) ;
V_1 -> V_44 . V_64 . V_66 = V_4 . V_67 * 1000 ;
return TRUE ;
}
static T_4
V_24 ( T_1 * V_1 , T_5 V_68 , union V_32
* V_33 , T_6 * V_69 , int V_70 , int * V_2 ,
T_2 * * V_3 )
{
T_3 V_4 ;
int V_43 ;
if( F_3 ( V_1 -> V_71 , V_68 , V_20 , V_2 ) == - 1 )
return FALSE ;
if( ! F_2 ( & V_4 , V_1 -> V_71 , V_2 , V_3 ) ) {
if( * V_2 == 0 )
* V_2 = V_52 ;
return FALSE ;
}
if( V_70 != V_4 . V_51 ) {
* V_2 = V_49 ;
* V_3 = F_6 ( L_2 , V_4 . V_51 , V_70 ) ;
return FALSE ;
}
F_4 ( & V_4 , V_33 ) ;
V_43 = F_8 ( V_69 , V_4 . V_51 , V_1 -> V_71 ) ;
if( V_43 != V_4 . V_51 ) {
* V_2 = F_10 ( V_1 -> V_71 , V_3 ) ;
if( * V_2 == 0 )
* V_2 = V_52 ;
return FALSE ;
}
return TRUE ;
}
static T_4
F_2 ( T_3 * V_4 , T_7 V_5 , int * V_2 ,
T_2 * * V_3 )
{
F_11 ( & V_4 -> V_51 , 2 , V_5 , V_2 , V_3 ) ;
F_11 ( & V_4 -> V_72 , 2 , V_5 , V_2 , V_3 ) ;
F_11 ( & V_4 -> V_6 , 1 , V_5 , V_2 , V_3 ) ;
F_11 ( & V_4 -> V_7 , 2 , V_5 , V_2 , V_3 ) ;
F_11 ( & V_4 -> V_8 , 1 , V_5 , V_2 , V_3 ) ;
F_11 ( & V_4 -> V_9 , 1 , V_5 , V_2 , V_3 ) ;
F_11 ( & V_4 -> V_10 , 1 , V_5 , V_2 , V_3 ) ;
F_11 ( & V_4 -> V_11 , 1 , V_5 , V_2 , V_3 ) ;
F_11 ( & V_4 -> V_12 , 1 , V_5 , V_2 , V_3 ) ;
F_11 ( & V_4 -> V_67 , 4 , V_5 , V_2 , V_3 ) ;
F_11 ( & V_4 -> V_14 , 1 , V_5 , V_2 , V_3 ) ;
F_11 ( & V_4 -> V_13 , 1 , V_5 , V_2 , V_3 ) ;
F_11 ( & V_4 -> V_39 , 1 , V_5 , V_2 , V_3 ) ;
F_11 ( & V_4 -> V_73 , 1 , V_5 , V_2 , V_3 ) ;
F_11 ( & V_4 -> V_37 , 1 , V_5 , V_2 , V_3 ) ;
F_11 ( & V_4 -> V_74 , 1 , V_5 , V_2 , V_3 ) ;
F_11 ( & V_4 -> V_75 , 1 , V_5 , V_2 , V_3 ) ;
F_11 ( & V_4 -> V_76 , 1 , V_5 , V_2 , V_3 ) ;
V_4 -> V_51 = F_12 ( V_4 -> V_51 ) ;
V_4 -> V_72 = F_12 ( V_4 -> V_72 ) ;
V_4 -> V_7 = F_12 ( V_4 -> V_7 ) ;
V_4 -> V_67 = F_13 ( V_4 -> V_67 ) ;
return TRUE ;
}
int F_14 ( int V_77 )
{
switch ( V_77 ) {
case V_46 :
case V_78 :
case V_47 :
case V_48 :
case V_28 :
return 0 ;
default:
return V_79 ;
}
}
T_4 F_15 ( T_8 * V_80 , int * V_2 V_81 )
{
V_80 -> V_82 = V_83 ;
V_80 -> V_84 = NULL ;
V_80 -> V_85 = 0 ;
return TRUE ;
}
static T_4 V_83 ( T_8 * V_80 ,
const struct V_86 * V_44 ,
const union V_32 * V_33 ,
const T_6 * V_69 , int * V_2 )
{
T_3 V_4 ;
struct V_42 * V_42 ;
memset ( & V_4 , 0 , sizeof( V_4 ) ) ;
V_4 . V_51 = F_16 ( ( V_87 ) V_44 -> V_63 ) ;
V_4 . V_72 = F_16 ( ( V_87 ) V_44 -> V_63 ) ;
V_4 . V_6 = 0 ;
V_42 = localtime ( & V_44 -> V_64 . V_65 ) ;
V_4 . V_7 = V_42 -> V_53 + 1900 ;
V_4 . V_8 = V_42 -> V_54 + 1 ;
V_4 . V_9 = V_42 -> V_55 ;
V_4 . V_10 = V_42 -> V_56 ;
V_4 . V_11 = V_42 -> V_57 ;
V_4 . V_12 = V_42 -> V_58 ;
V_4 . V_67 = F_17 ( V_44 -> V_64 . V_66 / 1000 ) ;
switch( V_44 -> V_45 ) {
case V_46 :
V_4 . V_14 |= V_17 ;
break;
case V_78 :
V_4 . V_14 |= V_18 ;
break;
case V_47 :
V_4 . V_14 |= V_18 ;
V_4 . V_37 = V_33 -> V_36 . V_37 ;
V_4 . V_39 = V_33 -> V_36 . V_38 ;
V_4 . V_13 = V_33 -> V_36 . V_40 ;
break;
case V_48 :
V_4 . V_14 |= V_19 ;
break;
default :
* V_2 = V_79 ;
return FALSE ;
}
if ( ! F_18 ( V_80 , & V_4 . V_51 , 2 , V_2 ) )
return FALSE ;
if ( ! F_18 ( V_80 , & V_4 . V_72 , 2 , V_2 ) )
return FALSE ;
if ( ! F_18 ( V_80 , & V_4 . V_6 , 1 , V_2 ) )
return FALSE ;
if ( ! F_18 ( V_80 , & V_4 . V_7 , 2 , V_2 ) )
return FALSE ;
if ( ! F_18 ( V_80 , & V_4 . V_8 , 1 , V_2 ) )
return FALSE ;
if ( ! F_18 ( V_80 , & V_4 . V_9 , 1 , V_2 ) )
return FALSE ;
if ( ! F_18 ( V_80 , & V_4 . V_10 , 1 , V_2 ) )
return FALSE ;
if ( ! F_18 ( V_80 , & V_4 . V_11 , 1 , V_2 ) )
return FALSE ;
if ( ! F_18 ( V_80 , & V_4 . V_12 , 1 , V_2 ) )
return FALSE ;
if ( ! F_18 ( V_80 , & V_4 . V_67 , 4 , V_2 ) )
return FALSE ;
if ( ! F_18 ( V_80 , & V_4 . V_14 , 1 , V_2 ) )
return FALSE ;
if ( ! F_18 ( V_80 , & V_4 . V_13 , 1 , V_2 ) )
return FALSE ;
if ( ! F_18 ( V_80 , & V_4 . V_39 , 1 , V_2 ) )
return FALSE ;
if ( ! F_18 ( V_80 , & V_4 . V_73 , 1 , V_2 ) )
return FALSE ;
if ( ! F_18 ( V_80 , & V_4 . V_37 , 1 , V_2 ) )
return FALSE ;
if ( ! F_18 ( V_80 , & V_4 . V_74 , 1 , V_2 ) )
return FALSE ;
if ( ! F_18 ( V_80 , & V_4 . V_75 , 2 , V_2 ) )
return FALSE ;
if ( ! F_18 ( V_80 , & V_4 . V_76 , 2 , V_2 ) )
return FALSE ;
V_80 -> V_85 += V_88 ;
if ( ! F_18 ( V_80 , V_69 , V_44 -> V_63 , V_2 ) )
return FALSE ;
V_80 -> V_85 += V_44 -> V_63 ;
return TRUE ;
}
