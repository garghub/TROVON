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
static T_4
F_4 ( const T_3 * V_32 , struct V_33 * V_34 )
{
union V_35 * V_36 = & V_34 -> V_36 ;
struct V_37 V_37 ;
V_34 -> V_38 = V_32 -> V_39 ;
V_34 -> V_40 = V_32 -> V_39 ;
V_37 . V_41 = V_32 -> V_8 - 1900 ;
V_37 . V_42 = V_32 -> V_9 - 1 ;
V_37 . V_43 = V_32 -> V_10 ;
V_37 . V_44 = V_32 -> V_11 ;
V_37 . V_45 = V_32 -> V_12 ;
V_37 . V_46 = V_32 -> V_13 ;
V_37 . V_47 = - 1 ;
V_34 -> V_48 . V_49 = mktime ( & V_37 ) ;
V_34 -> V_48 . V_50 = V_32 -> V_51 * 1000 ;
V_34 -> V_52 = V_53 ;
switch( V_32 -> V_15 & V_17 ) {
case V_18 :
V_34 -> V_54 = V_55 ;
V_36 -> V_56 . V_57 = - 1 ;
return TRUE ;
case V_19 :
V_34 -> V_54 = V_58 ;
V_36 -> V_59 . V_57 = - 1 ;
V_36 -> V_59 . V_60 = FALSE ;
V_36 -> V_59 . V_61 = V_32 -> V_61 ;
V_36 -> V_59 . V_62 =
V_32 -> V_63 | ( V_32 -> V_64 << 8 ) ;
V_36 -> V_59 . V_65 = V_32 -> V_14 ;
return TRUE ;
case V_20 :
V_34 -> V_54 = V_66 ;
return TRUE ;
}
return FALSE ;
}
static T_4
V_23 ( T_1 * V_1 , int * V_2 , T_2 * * V_3 , T_5 * V_67 )
{
T_3 V_4 ;
int V_68 ;
* V_67 = F_5 ( V_1 -> V_5 ) ;
if( ! F_2 ( & V_4 , V_1 -> V_5 , V_2 , V_3 ) )
return FALSE ;
if( ! F_4 ( & V_4 , & V_1 -> V_34 ) ) {
* V_2 = V_69 ;
* V_3 = F_6 ( L_1 ,
V_4 . V_15 & V_17 ) ;
return FALSE ;
}
F_7 ( V_1 -> V_70 , V_4 . V_39 ) ;
V_68 = F_8 ( F_9 ( V_1 -> V_70 ) ,
V_4 . V_39 , V_1 -> V_5 ) ;
if( V_68 != V_4 . V_39 ) {
* V_2 = F_10 ( V_1 -> V_5 , V_3 ) ;
if( * V_2 == 0 )
* V_2 = V_6 ;
return FALSE ;
}
return TRUE ;
}
static T_4
V_25 ( T_1 * V_1 , T_5 V_71 , struct V_33 * V_34 ,
T_6 * V_72 , int V_73 , int * V_2 ,
T_2 * * V_3 )
{
T_3 V_4 ;
int V_68 ;
if( F_3 ( V_1 -> V_74 , V_71 , V_21 , V_2 ) == - 1 )
return FALSE ;
if( ! F_2 ( & V_4 , V_1 -> V_74 , V_2 , V_3 ) ) {
if( * V_2 == 0 )
* V_2 = V_6 ;
return FALSE ;
}
if( ! F_4 ( & V_4 , V_34 ) ) {
* V_2 = V_69 ;
* V_3 = F_6 ( L_1 ,
V_4 . V_15 & V_17 ) ;
return FALSE ;
}
if( V_73 != ( int ) V_34 -> V_40 ) {
* V_2 = V_69 ;
* V_3 = F_6 ( L_2 , V_34 -> V_40 , V_73 ) ;
return FALSE ;
}
V_68 = F_8 ( V_72 , V_4 . V_39 , V_1 -> V_74 ) ;
if( V_68 != V_4 . V_39 ) {
* V_2 = F_10 ( V_1 -> V_74 , V_3 ) ;
if( * V_2 == 0 )
* V_2 = V_6 ;
return FALSE ;
}
return TRUE ;
}
static T_4
F_2 ( T_3 * V_4 , T_7 V_5 , int * V_2 ,
T_2 * * V_3 )
{
F_11 ( & V_4 -> V_39 , 2 , V_5 , V_2 , V_3 ) ;
F_11 ( & V_4 -> V_75 , 2 , V_5 , V_2 , V_3 ) ;
F_11 ( & V_4 -> V_7 , 1 , V_5 , V_2 , V_3 ) ;
F_11 ( & V_4 -> V_8 , 2 , V_5 , V_2 , V_3 ) ;
F_11 ( & V_4 -> V_9 , 1 , V_5 , V_2 , V_3 ) ;
F_11 ( & V_4 -> V_10 , 1 , V_5 , V_2 , V_3 ) ;
F_11 ( & V_4 -> V_11 , 1 , V_5 , V_2 , V_3 ) ;
F_11 ( & V_4 -> V_12 , 1 , V_5 , V_2 , V_3 ) ;
F_11 ( & V_4 -> V_13 , 1 , V_5 , V_2 , V_3 ) ;
F_11 ( & V_4 -> V_51 , 4 , V_5 , V_2 , V_3 ) ;
F_11 ( & V_4 -> V_15 , 1 , V_5 , V_2 , V_3 ) ;
F_11 ( & V_4 -> V_14 , 1 , V_5 , V_2 , V_3 ) ;
F_11 ( & V_4 -> V_63 , 1 , V_5 , V_2 , V_3 ) ;
F_11 ( & V_4 -> V_76 , 1 , V_5 , V_2 , V_3 ) ;
F_11 ( & V_4 -> V_61 , 1 , V_5 , V_2 , V_3 ) ;
F_11 ( & V_4 -> V_64 , 1 , V_5 , V_2 , V_3 ) ;
F_11 ( & V_4 -> V_77 , 1 , V_5 , V_2 , V_3 ) ;
F_11 ( & V_4 -> V_78 , 1 , V_5 , V_2 , V_3 ) ;
V_4 -> V_39 = F_12 ( V_4 -> V_39 ) ;
V_4 -> V_75 = F_12 ( V_4 -> V_75 ) ;
V_4 -> V_8 = F_12 ( V_4 -> V_8 ) ;
V_4 -> V_51 = F_13 ( V_4 -> V_51 ) ;
return TRUE ;
}
int F_14 ( int V_79 )
{
switch ( V_79 ) {
case V_55 :
case V_80 :
case V_58 :
case V_66 :
case V_29 :
return 0 ;
default:
return V_81 ;
}
}
T_4 F_15 ( T_8 * V_82 , int * V_2 V_83 )
{
V_82 -> V_84 = V_85 ;
V_82 -> V_86 = NULL ;
V_82 -> V_87 = 0 ;
return TRUE ;
}
static T_4 V_85 ( T_8 * V_82 ,
const struct V_33 * V_34 ,
const T_6 * V_72 , int * V_2 )
{
const union V_35 * V_36 = & V_34 -> V_36 ;
T_3 V_4 ;
struct V_37 * V_37 ;
memset ( & V_4 , 0 , sizeof( V_4 ) ) ;
V_4 . V_39 = F_16 ( ( V_88 ) V_34 -> V_40 ) ;
V_4 . V_75 = F_16 ( ( V_88 ) V_34 -> V_40 ) ;
V_4 . V_7 = 0 ;
V_37 = localtime ( & V_34 -> V_48 . V_49 ) ;
V_4 . V_8 = V_37 -> V_41 + 1900 ;
V_4 . V_9 = V_37 -> V_42 + 1 ;
V_4 . V_10 = V_37 -> V_43 ;
V_4 . V_11 = V_37 -> V_44 ;
V_4 . V_12 = V_37 -> V_45 ;
V_4 . V_13 = V_37 -> V_46 ;
V_4 . V_51 = F_17 ( V_34 -> V_48 . V_50 / 1000 ) ;
switch( V_34 -> V_54 ) {
case V_55 :
V_4 . V_15 |= V_18 ;
break;
case V_80 :
V_4 . V_15 |= V_19 ;
break;
case V_58 :
V_4 . V_15 |= V_19 ;
V_4 . V_61 = V_36 -> V_59 . V_61 ;
V_4 . V_63 = ( T_6 ) ( V_36 -> V_59 . V_62 & 0xFF ) ;
V_4 . V_64 = ( T_6 ) ( ( V_36 -> V_59 . V_62 >> 8 ) & 0xFF ) ;
V_4 . V_14 = V_36 -> V_59 . V_65 ;
break;
case V_66 :
V_4 . V_15 |= V_20 ;
break;
default :
* V_2 = V_81 ;
return FALSE ;
}
if ( ! F_18 ( V_82 , & V_4 . V_39 , 2 , V_2 ) )
return FALSE ;
if ( ! F_18 ( V_82 , & V_4 . V_75 , 2 , V_2 ) )
return FALSE ;
if ( ! F_18 ( V_82 , & V_4 . V_7 , 1 , V_2 ) )
return FALSE ;
if ( ! F_18 ( V_82 , & V_4 . V_8 , 2 , V_2 ) )
return FALSE ;
if ( ! F_18 ( V_82 , & V_4 . V_9 , 1 , V_2 ) )
return FALSE ;
if ( ! F_18 ( V_82 , & V_4 . V_10 , 1 , V_2 ) )
return FALSE ;
if ( ! F_18 ( V_82 , & V_4 . V_11 , 1 , V_2 ) )
return FALSE ;
if ( ! F_18 ( V_82 , & V_4 . V_12 , 1 , V_2 ) )
return FALSE ;
if ( ! F_18 ( V_82 , & V_4 . V_13 , 1 , V_2 ) )
return FALSE ;
if ( ! F_18 ( V_82 , & V_4 . V_51 , 4 , V_2 ) )
return FALSE ;
if ( ! F_18 ( V_82 , & V_4 . V_15 , 1 , V_2 ) )
return FALSE ;
if ( ! F_18 ( V_82 , & V_4 . V_14 , 1 , V_2 ) )
return FALSE ;
if ( ! F_18 ( V_82 , & V_4 . V_63 , 1 , V_2 ) )
return FALSE ;
if ( ! F_18 ( V_82 , & V_4 . V_76 , 1 , V_2 ) )
return FALSE ;
if ( ! F_18 ( V_82 , & V_4 . V_61 , 1 , V_2 ) )
return FALSE ;
if ( ! F_18 ( V_82 , & V_4 . V_64 , 1 , V_2 ) )
return FALSE ;
if ( ! F_18 ( V_82 , & V_4 . V_77 , 2 , V_2 ) )
return FALSE ;
if ( ! F_18 ( V_82 , & V_4 . V_78 , 2 , V_2 ) )
return FALSE ;
V_82 -> V_87 += V_89 ;
if ( ! F_18 ( V_82 , V_72 , V_34 -> V_40 , V_2 ) )
return FALSE ;
V_82 -> V_87 += V_34 -> V_40 ;
return TRUE ;
}
