static int F_1 ( struct V_1 * V_1 , struct V_2 * V_3 )
{
struct V_4 * V_5 ;
int error , V_6 = 0 ;
if ( ! F_2 () )
return - V_7 ;
F_3 () ;
if ( ! F_4 ( & V_8 , - 1 , 0 ) ) {
error = - V_9 ;
goto V_10;
}
if ( ( V_3 -> V_11 & V_12 ) == V_13 ) {
F_5 ( & V_8 ) ;
error = - V_14 ;
goto V_10;
}
F_6 ( V_1 , V_3 ) ;
V_5 = & V_15 ;
V_3 -> V_16 = V_5 ;
memset ( & V_5 -> V_17 , 0 , sizeof( struct V_18 ) ) ;
if ( ( V_3 -> V_11 & V_12 ) == V_19 ) {
V_5 -> V_20 = V_21 ?
F_7 ( V_21 , 0 , NULL ) : - 1 ;
V_5 -> V_22 = V_19 ;
V_5 -> V_23 = false ;
error = F_8 ( V_24 , - 1 , & V_6 ) ;
if ( error )
F_8 ( V_25 , -- V_6 , NULL ) ;
} else {
F_9 () ;
V_5 -> V_20 = - 1 ;
V_5 -> V_22 = V_26 ;
error = F_8 ( V_27 , - 1 , & V_6 ) ;
if ( ! error ) {
error = F_10 () ;
V_5 -> V_23 = ! error ;
} else
V_6 -- ;
if ( error )
F_8 ( V_28 , V_6 , NULL ) ;
}
if ( error )
F_5 ( & V_8 ) ;
V_5 -> V_29 = false ;
V_5 -> V_30 = false ;
V_5 -> V_31 = false ;
V_10:
F_11 () ;
return error ;
}
static int F_12 ( struct V_1 * V_1 , struct V_2 * V_3 )
{
struct V_4 * V_5 ;
F_3 () ;
F_13 () ;
V_5 = V_3 -> V_16 ;
F_14 ( V_5 -> V_20 ) ;
if ( V_5 -> V_29 ) {
F_15 () ;
F_16 () ;
F_17 () ;
} else if ( V_5 -> V_23 ) {
F_16 () ;
}
F_18 ( V_5 -> V_22 == V_19 ?
V_25 : V_28 ) ;
F_5 ( & V_8 ) ;
F_11 () ;
return 0 ;
}
static T_1 F_19 ( struct V_2 * V_3 , char T_2 * V_32 ,
T_3 V_33 , T_4 * V_34 )
{
struct V_4 * V_5 ;
T_1 V_35 ;
T_4 V_36 = * V_34 & ~ V_37 ;
F_3 () ;
V_5 = V_3 -> V_16 ;
if ( ! V_5 -> V_30 ) {
V_35 = - V_38 ;
goto V_10;
}
if ( ! V_36 ) {
V_35 = F_20 ( & V_5 -> V_17 ) ;
if ( V_35 <= 0 )
goto V_10;
} else {
V_35 = V_39 - V_36 ;
}
V_35 = F_21 ( V_32 , V_33 , & V_36 ,
F_22 ( V_5 -> V_17 ) , V_35 ) ;
if ( V_35 > 0 )
* V_34 += V_35 ;
V_10:
F_11 () ;
return V_35 ;
}
static T_1 F_23 ( struct V_2 * V_3 , const char T_2 * V_32 ,
T_3 V_33 , T_4 * V_34 )
{
struct V_4 * V_5 ;
T_1 V_35 ;
T_4 V_36 = * V_34 & ~ V_37 ;
F_3 () ;
V_5 = V_3 -> V_16 ;
if ( ! V_36 ) {
V_35 = F_24 ( & V_5 -> V_17 ) ;
if ( V_35 <= 0 )
goto V_40;
} else {
V_35 = V_39 - V_36 ;
}
V_35 = F_25 ( F_22 ( V_5 -> V_17 ) , V_35 , & V_36 ,
V_32 , V_33 ) ;
if ( V_35 > 0 )
* V_34 += V_35 ;
V_40:
F_11 () ;
return V_35 ;
}
static long F_26 ( struct V_2 * V_3 , unsigned int V_41 ,
unsigned long V_42 )
{
int error = 0 ;
struct V_4 * V_5 ;
T_4 V_43 ;
T_5 V_44 ;
if ( F_27 ( V_41 ) != V_45 )
return - V_46 ;
if ( F_28 ( V_41 ) > V_47 )
return - V_46 ;
if ( ! F_29 ( V_48 ) )
return - V_7 ;
if ( ! F_30 ( & V_49 ) )
return - V_9 ;
F_31 () ;
V_5 = V_3 -> V_16 ;
switch ( V_41 ) {
case V_50 :
if ( V_5 -> V_29 )
break;
F_32 ( L_1 ) ;
F_33 () ;
F_32 ( L_2 ) ;
error = F_34 () ;
if ( error )
break;
error = F_10 () ;
if ( error )
F_17 () ;
else
V_5 -> V_29 = true ;
break;
case V_51 :
if ( ! V_5 -> V_29 || V_5 -> V_30 )
break;
F_15 () ;
F_16 () ;
V_5 -> V_23 = false ;
F_17 () ;
V_5 -> V_29 = false ;
break;
case V_52 :
if ( V_5 -> V_22 != V_19 || ! V_5 -> V_29 || V_5 -> V_30 ) {
error = - V_7 ;
break;
}
F_15 () ;
error = F_35 ( V_5 -> V_31 ) ;
if ( ! error ) {
error = F_36 ( V_53 , ( int T_2 * ) V_42 ) ;
V_5 -> V_30 = ! V_54 && ! error ;
V_54 = false ;
}
break;
case V_55 :
F_37 ( & V_5 -> V_17 ) ;
if ( V_5 -> V_22 != V_26 || ! V_5 -> V_29 ||
! F_38 ( & V_5 -> V_17 ) ) {
error = - V_7 ;
break;
}
error = F_39 ( V_5 -> V_31 ) ;
break;
case V_56 :
F_13 () ;
memset ( & V_5 -> V_17 , 0 , sizeof( struct V_18 ) ) ;
V_5 -> V_30 = false ;
F_40 () ;
break;
case V_57 :
V_58 = V_42 ;
break;
case V_59 :
if ( ! V_5 -> V_30 ) {
error = - V_38 ;
break;
}
V_43 = F_41 () ;
V_43 <<= V_60 ;
error = F_36 ( V_43 , ( T_4 T_2 * ) V_42 ) ;
break;
case V_61 :
V_43 = F_42 ( V_5 -> V_20 , 1 ) ;
V_43 <<= V_60 ;
error = F_36 ( V_43 , ( T_4 T_2 * ) V_42 ) ;
break;
case V_62 :
if ( V_5 -> V_20 < 0 || V_5 -> V_20 >= V_63 ) {
error = - V_64 ;
break;
}
V_44 = F_43 ( V_5 -> V_20 ) ;
if ( V_44 ) {
V_44 <<= V_60 ;
error = F_36 ( V_44 , ( T_4 T_2 * ) V_42 ) ;
} else {
error = - V_65 ;
}
break;
case V_66 :
if ( V_5 -> V_20 < 0 || V_5 -> V_20 >= V_63 ) {
error = - V_64 ;
break;
}
F_14 ( V_5 -> V_20 ) ;
break;
case V_67 :
if ( ! V_5 -> V_29 ) {
error = - V_7 ;
break;
}
error = F_44 ( V_68 ) ;
V_5 -> V_30 = false ;
break;
case V_69 :
V_5 -> V_31 = ! ! V_42 ;
break;
case V_70 :
if ( V_5 -> V_31 )
error = F_45 () ;
break;
case V_71 :
if ( F_46 () ) {
error = - V_7 ;
} else {
struct V_72 V_73 ;
T_6 V_74 ;
error = F_47 ( & V_73 , ( void T_2 * ) V_42 ,
sizeof( struct V_72 ) ) ;
if ( error ) {
error = - V_75 ;
break;
}
V_74 = F_48 ( V_73 . V_76 ) ;
if ( V_74 ) {
V_44 = V_73 . V_44 ;
V_5 -> V_20 = F_7 ( V_74 , V_44 , NULL ) ;
if ( V_5 -> V_20 < 0 )
error = - V_64 ;
} else {
V_5 -> V_20 = - 1 ;
error = - V_77 ;
}
}
break;
default:
error = - V_46 ;
}
F_49 () ;
F_50 ( & V_49 ) ;
return error ;
}
static long
F_51 ( struct V_2 * V_2 , unsigned int V_41 , unsigned long V_42 )
{
F_52 ( sizeof( T_4 ) != sizeof( V_78 ) ) ;
switch ( V_41 ) {
case V_59 :
case V_61 :
case V_62 : {
V_78 T_2 * V_79 = F_53 ( V_42 ) ;
T_4 V_44 ;
T_7 V_80 ;
int V_81 ;
V_80 = F_54 () ;
F_55 ( V_82 ) ;
V_81 = F_26 ( V_2 , V_41 , ( unsigned long ) & V_44 ) ;
F_55 ( V_80 ) ;
if ( ! V_81 && F_36 ( V_44 , V_79 ) )
V_81 = - V_75 ;
return V_81 ;
}
case V_52 :
return F_26 ( V_2 , V_41 ,
( unsigned long ) F_53 ( V_42 ) ) ;
case V_71 : {
struct V_83 T_2 * V_84 =
F_53 ( V_42 ) ;
struct V_72 V_73 ;
T_7 V_80 ;
int V_81 ;
V_81 = F_56 ( V_73 . V_44 , & V_84 -> V_44 ) ;
V_81 |= F_56 ( V_73 . V_76 , & V_84 -> V_76 ) ;
if ( V_81 )
return - V_75 ;
V_80 = F_54 () ;
F_55 ( V_82 ) ;
V_81 = F_26 ( V_2 , V_71 ,
( unsigned long ) & V_73 ) ;
F_55 ( V_80 ) ;
return V_81 ;
}
default:
return F_26 ( V_2 , V_41 , V_42 ) ;
}
}
static int T_8 F_57 ( void )
{
return F_58 ( & V_85 ) ;
}
