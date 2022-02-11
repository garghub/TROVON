int F_1 ( T_1 * V_1 , int * V_2 , T_2 * * V_3 )
{
T_3 V_4 ;
if( ! F_2 ( & V_4 , V_1 -> V_5 , V_2 , V_3 ) ) {
if ( * V_2 != 0 && * V_2 != V_6 )
return - 1 ;
return 0 ;
}
if( V_4 . V_7 != 0 ||
V_4 . V_8 < 1970 || V_4 . V_8 >= 2038 ||
V_4 . V_9 < 1 || V_4 . V_9 > 12 ||
V_4 . V_10 < 1 || V_4 . V_10 > 31 ||
V_4 . V_11 > 23 ||
V_4 . V_12 > 59 ||
V_4 . V_13 > 60 ||
V_4 . V_14 > 100 ||
( V_4 . V_15 & V_16 ) != 0 ||
( ( V_4 . V_15 & V_17 ) != V_18 &&
( V_4 . V_15 & V_17 ) != V_19 &&
( V_4 . V_15 & V_17 ) != V_20 ) )
return 0 ;
if ( F_3 ( V_1 -> V_5 , 0 , V_21 , V_2 ) == - 1 )
return - 1 ;
V_1 -> V_22 = V_23 ;
V_1 -> V_24 = V_25 ;
V_1 -> V_26 = V_27 ;
V_1 -> V_28 = V_29 ;
V_1 -> V_30 = V_31 ;
return 1 ;
}
static int
F_4 ( T_4 V_5 , struct V_32 * V_33 , T_5 * V_34 ,
int * V_2 , T_2 * * V_3 )
{
T_3 V_4 ;
struct V_35 V_35 ;
if( ! F_2 ( & V_4 , V_5 , V_2 , V_3 ) )
return FALSE ;
switch( V_4 . V_15 & V_17 ) {
case V_18 :
V_33 -> V_36 = V_37 ;
V_33 -> V_38 . V_39 . V_40 = - 1 ;
break;
case V_19 :
V_33 -> V_36 = V_41 ;
V_33 -> V_38 . V_42 . V_40 = - 1 ;
V_33 -> V_38 . V_42 . V_43 = V_4 . V_43 ;
V_33 -> V_38 . V_42 . V_44 =
V_4 . V_45 | ( V_4 . V_46 << 8 ) ;
V_33 -> V_38 . V_42 . V_47 = V_4 . V_14 ;
break;
case V_20 :
V_33 -> V_36 = V_48 ;
break;
default :
* V_2 = V_49 ;
* V_3 = F_5 ( L_1 ,
V_4 . V_15 & V_17 ) ;
return FALSE ;
}
V_35 . V_50 = V_4 . V_8 - 1900 ;
V_35 . V_51 = V_4 . V_9 - 1 ;
V_35 . V_52 = V_4 . V_10 ;
V_35 . V_53 = V_4 . V_11 ;
V_35 . V_54 = V_4 . V_12 ;
V_35 . V_55 = V_4 . V_13 ;
V_35 . V_56 = - 1 ;
V_33 -> V_57 = V_58 ;
V_33 -> V_59 = V_60 ;
V_33 -> V_61 = V_4 . V_62 ;
V_33 -> V_63 = V_4 . V_62 ;
V_33 -> V_64 . V_65 = mktime ( & V_35 ) ;
V_33 -> V_64 . V_66 = V_4 . V_67 * 1000 ;
return F_6 ( V_5 , V_34 , V_33 -> V_63 , V_2 , V_3 ) ;
}
static T_6
V_23 ( T_1 * V_1 , int * V_2 , T_2 * * V_3 , T_7 * V_68 )
{
* V_68 = F_7 ( V_1 -> V_5 ) ;
return F_4 ( V_1 -> V_5 , & V_1 -> V_33 , V_1 -> V_69 , V_2 ,
V_3 ) ;
}
static T_6
V_25 ( T_1 * V_1 , T_7 V_70 , struct V_32 * V_33 ,
T_5 * V_34 , int * V_2 , T_2 * * V_3 )
{
if( F_3 ( V_1 -> V_71 , V_70 , V_21 , V_2 ) == - 1 )
return FALSE ;
return F_4 ( V_1 -> V_71 , V_33 , V_34 , V_2 , V_3 ) ;
}
static T_6
F_2 ( T_3 * V_4 , T_4 V_5 , int * V_2 ,
T_2 * * V_3 )
{
F_8 ( & V_4 -> V_62 , 2 , V_5 , V_2 , V_3 ) ;
F_8 ( & V_4 -> V_72 , 2 , V_5 , V_2 , V_3 ) ;
F_8 ( & V_4 -> V_7 , 1 , V_5 , V_2 , V_3 ) ;
F_8 ( & V_4 -> V_8 , 2 , V_5 , V_2 , V_3 ) ;
F_8 ( & V_4 -> V_9 , 1 , V_5 , V_2 , V_3 ) ;
F_8 ( & V_4 -> V_10 , 1 , V_5 , V_2 , V_3 ) ;
F_8 ( & V_4 -> V_11 , 1 , V_5 , V_2 , V_3 ) ;
F_8 ( & V_4 -> V_12 , 1 , V_5 , V_2 , V_3 ) ;
F_8 ( & V_4 -> V_13 , 1 , V_5 , V_2 , V_3 ) ;
F_8 ( & V_4 -> V_67 , 4 , V_5 , V_2 , V_3 ) ;
F_8 ( & V_4 -> V_15 , 1 , V_5 , V_2 , V_3 ) ;
F_8 ( & V_4 -> V_14 , 1 , V_5 , V_2 , V_3 ) ;
F_8 ( & V_4 -> V_45 , 1 , V_5 , V_2 , V_3 ) ;
F_8 ( & V_4 -> V_73 , 1 , V_5 , V_2 , V_3 ) ;
F_8 ( & V_4 -> V_43 , 1 , V_5 , V_2 , V_3 ) ;
F_8 ( & V_4 -> V_46 , 1 , V_5 , V_2 , V_3 ) ;
F_8 ( & V_4 -> V_74 , 1 , V_5 , V_2 , V_3 ) ;
F_8 ( & V_4 -> V_75 , 1 , V_5 , V_2 , V_3 ) ;
V_4 -> V_62 = F_9 ( V_4 -> V_62 ) ;
V_4 -> V_72 = F_9 ( V_4 -> V_72 ) ;
V_4 -> V_8 = F_9 ( V_4 -> V_8 ) ;
V_4 -> V_67 = F_10 ( V_4 -> V_67 ) ;
return TRUE ;
}
int F_11 ( int V_76 )
{
switch ( V_76 ) {
case V_37 :
case V_77 :
case V_41 :
case V_48 :
case V_29 :
return 0 ;
default:
return V_78 ;
}
}
T_6 F_12 ( T_8 * V_79 , int * V_2 V_80 )
{
V_79 -> V_81 = V_82 ;
V_79 -> V_83 = NULL ;
V_79 -> V_84 = 0 ;
return TRUE ;
}
static T_6 V_82 ( T_8 * V_79 ,
const struct V_32 * V_33 ,
const T_9 * V_85 , int * V_2 )
{
T_3 V_4 ;
struct V_35 * V_35 ;
if ( V_33 -> V_57 != V_58 ) {
* V_2 = V_86 ;
return FALSE ;
}
if ( V_33 -> V_63 > 65535 ) {
* V_2 = V_87 ;
return FALSE ;
}
memset ( & V_4 , 0 , sizeof( V_4 ) ) ;
V_4 . V_62 = F_13 ( ( V_88 ) V_33 -> V_63 ) ;
V_4 . V_72 = F_13 ( ( V_88 ) V_33 -> V_63 ) ;
V_4 . V_7 = 0 ;
V_35 = localtime ( & V_33 -> V_64 . V_65 ) ;
V_4 . V_8 = V_35 -> V_50 + 1900 ;
V_4 . V_9 = V_35 -> V_51 + 1 ;
V_4 . V_10 = V_35 -> V_52 ;
V_4 . V_11 = V_35 -> V_53 ;
V_4 . V_12 = V_35 -> V_54 ;
V_4 . V_13 = V_35 -> V_55 ;
V_4 . V_67 = F_14 ( V_33 -> V_64 . V_66 / 1000 ) ;
switch( V_33 -> V_36 ) {
case V_37 :
V_4 . V_15 |= V_18 ;
break;
case V_77 :
V_4 . V_15 |= V_19 ;
break;
case V_41 :
V_4 . V_15 |= V_19 ;
V_4 . V_43 = V_33 -> V_38 . V_42 . V_43 ;
V_4 . V_45 = ( T_9 ) ( V_33 -> V_38 . V_42 . V_44 & 0xFF ) ;
V_4 . V_46 = ( T_9 ) ( ( V_33 -> V_38 . V_42 . V_44 >> 8 ) & 0xFF ) ;
V_4 . V_14 = V_33 -> V_38 . V_42 . V_47 ;
break;
case V_48 :
V_4 . V_15 |= V_20 ;
break;
default :
* V_2 = V_78 ;
return FALSE ;
}
if ( ! F_15 ( V_79 , & V_4 . V_62 , 2 , V_2 ) )
return FALSE ;
if ( ! F_15 ( V_79 , & V_4 . V_72 , 2 , V_2 ) )
return FALSE ;
if ( ! F_15 ( V_79 , & V_4 . V_7 , 1 , V_2 ) )
return FALSE ;
if ( ! F_15 ( V_79 , & V_4 . V_8 , 2 , V_2 ) )
return FALSE ;
if ( ! F_15 ( V_79 , & V_4 . V_9 , 1 , V_2 ) )
return FALSE ;
if ( ! F_15 ( V_79 , & V_4 . V_10 , 1 , V_2 ) )
return FALSE ;
if ( ! F_15 ( V_79 , & V_4 . V_11 , 1 , V_2 ) )
return FALSE ;
if ( ! F_15 ( V_79 , & V_4 . V_12 , 1 , V_2 ) )
return FALSE ;
if ( ! F_15 ( V_79 , & V_4 . V_13 , 1 , V_2 ) )
return FALSE ;
if ( ! F_15 ( V_79 , & V_4 . V_67 , 4 , V_2 ) )
return FALSE ;
if ( ! F_15 ( V_79 , & V_4 . V_15 , 1 , V_2 ) )
return FALSE ;
if ( ! F_15 ( V_79 , & V_4 . V_14 , 1 , V_2 ) )
return FALSE ;
if ( ! F_15 ( V_79 , & V_4 . V_45 , 1 , V_2 ) )
return FALSE ;
if ( ! F_15 ( V_79 , & V_4 . V_73 , 1 , V_2 ) )
return FALSE ;
if ( ! F_15 ( V_79 , & V_4 . V_43 , 1 , V_2 ) )
return FALSE ;
if ( ! F_15 ( V_79 , & V_4 . V_46 , 1 , V_2 ) )
return FALSE ;
if ( ! F_15 ( V_79 , & V_4 . V_74 , 2 , V_2 ) )
return FALSE ;
if ( ! F_15 ( V_79 , & V_4 . V_75 , 2 , V_2 ) )
return FALSE ;
V_79 -> V_84 += V_89 ;
if ( ! F_15 ( V_79 , V_85 , V_33 -> V_63 , V_2 ) )
return FALSE ;
V_79 -> V_84 += V_33 -> V_63 ;
return TRUE ;
}
