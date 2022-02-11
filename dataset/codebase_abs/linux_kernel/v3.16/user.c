static int F_1 ( struct V_1 * V_1 , struct V_2 * V_3 )
{
struct V_4 * V_5 ;
int error ;
if ( ! F_2 () )
return - V_6 ;
F_3 () ;
if ( ! F_4 ( & V_7 , - 1 , 0 ) ) {
error = - V_8 ;
goto V_9;
}
if ( ( V_3 -> V_10 & V_11 ) == V_12 ) {
F_5 ( & V_7 ) ;
error = - V_13 ;
goto V_9;
}
F_6 ( V_1 , V_3 ) ;
V_5 = & V_14 ;
V_3 -> V_15 = V_5 ;
memset ( & V_5 -> V_16 , 0 , sizeof( struct V_17 ) ) ;
if ( ( V_3 -> V_10 & V_11 ) == V_18 ) {
V_5 -> V_19 = V_20 ?
F_7 ( V_20 , 0 , NULL ) : - 1 ;
V_5 -> V_21 = V_18 ;
V_5 -> V_22 = false ;
error = F_8 ( V_23 ) ;
if ( error )
F_8 ( V_24 ) ;
} else {
F_9 () ;
V_5 -> V_19 = - 1 ;
V_5 -> V_21 = V_25 ;
error = F_8 ( V_26 ) ;
if ( ! error ) {
error = F_10 () ;
V_5 -> V_22 = ! error ;
}
if ( error )
F_8 ( V_27 ) ;
}
if ( error )
F_5 ( & V_7 ) ;
V_5 -> V_28 = false ;
V_5 -> V_29 = false ;
V_5 -> V_30 = false ;
V_9:
F_11 () ;
return error ;
}
static int F_12 ( struct V_1 * V_1 , struct V_2 * V_3 )
{
struct V_4 * V_5 ;
F_3 () ;
F_13 () ;
V_5 = V_3 -> V_15 ;
F_14 ( V_5 -> V_19 ) ;
if ( V_5 -> V_28 ) {
F_15 () ;
F_16 () ;
F_17 () ;
} else if ( V_5 -> V_22 ) {
F_16 () ;
}
F_8 ( V_5 -> V_21 == V_18 ?
V_24 : V_27 ) ;
F_5 ( & V_7 ) ;
F_11 () ;
return 0 ;
}
static T_1 F_18 ( struct V_2 * V_3 , char T_2 * V_31 ,
T_3 V_32 , T_4 * V_33 )
{
struct V_4 * V_5 ;
T_1 V_34 ;
T_4 V_35 = * V_33 & ~ V_36 ;
F_3 () ;
V_5 = V_3 -> V_15 ;
if ( ! V_5 -> V_29 ) {
V_34 = - V_37 ;
goto V_9;
}
if ( ! V_35 ) {
V_34 = F_19 ( & V_5 -> V_16 ) ;
if ( V_34 <= 0 )
goto V_9;
} else {
V_34 = V_38 - V_35 ;
}
V_34 = F_20 ( V_31 , V_32 , & V_35 ,
F_21 ( V_5 -> V_16 ) , V_34 ) ;
if ( V_34 > 0 )
* V_33 += V_34 ;
V_9:
F_11 () ;
return V_34 ;
}
static T_1 F_22 ( struct V_2 * V_3 , const char T_2 * V_31 ,
T_3 V_32 , T_4 * V_33 )
{
struct V_4 * V_5 ;
T_1 V_34 ;
T_4 V_35 = * V_33 & ~ V_36 ;
F_3 () ;
V_5 = V_3 -> V_15 ;
if ( ! V_35 ) {
V_34 = F_23 ( & V_5 -> V_16 ) ;
if ( V_34 <= 0 )
goto V_39;
} else {
V_34 = V_38 - V_35 ;
}
V_34 = F_24 ( F_21 ( V_5 -> V_16 ) , V_34 , & V_35 ,
V_31 , V_32 ) ;
if ( V_34 > 0 )
* V_33 += V_34 ;
V_39:
F_11 () ;
return V_34 ;
}
static long F_25 ( struct V_2 * V_3 , unsigned int V_40 ,
unsigned long V_41 )
{
int error = 0 ;
struct V_4 * V_5 ;
T_4 V_42 ;
T_5 V_43 ;
if ( F_26 ( V_40 ) != V_44 )
return - V_45 ;
if ( F_27 ( V_40 ) > V_46 )
return - V_45 ;
if ( ! F_28 ( V_47 ) )
return - V_6 ;
if ( ! F_29 ( & V_48 ) )
return - V_8 ;
F_30 () ;
V_5 = V_3 -> V_15 ;
switch ( V_40 ) {
case V_49 :
if ( V_5 -> V_28 )
break;
F_31 ( L_1 ) ;
F_32 () ;
F_31 ( L_2 ) ;
error = F_33 () ;
if ( error )
break;
error = F_10 () ;
if ( error )
F_17 () ;
else
V_5 -> V_28 = true ;
break;
case V_50 :
if ( ! V_5 -> V_28 || V_5 -> V_29 )
break;
F_15 () ;
F_16 () ;
V_5 -> V_22 = false ;
F_17 () ;
V_5 -> V_28 = false ;
break;
case V_51 :
if ( V_5 -> V_21 != V_18 || ! V_5 -> V_28 || V_5 -> V_29 ) {
error = - V_6 ;
break;
}
F_15 () ;
error = F_34 ( V_5 -> V_30 ) ;
if ( ! error ) {
error = F_35 ( V_52 , ( int T_2 * ) V_41 ) ;
V_5 -> V_29 = ! V_53 && ! error ;
V_53 = false ;
}
break;
case V_54 :
F_36 ( & V_5 -> V_16 ) ;
if ( V_5 -> V_21 != V_25 || ! V_5 -> V_28 ||
! F_37 ( & V_5 -> V_16 ) ) {
error = - V_6 ;
break;
}
error = F_38 ( V_5 -> V_30 ) ;
break;
case V_55 :
F_13 () ;
memset ( & V_5 -> V_16 , 0 , sizeof( struct V_17 ) ) ;
V_5 -> V_29 = false ;
F_39 () ;
break;
case V_56 :
V_57 = V_41 ;
break;
case V_58 :
if ( ! V_5 -> V_29 ) {
error = - V_37 ;
break;
}
V_42 = F_40 () ;
V_42 <<= V_59 ;
error = F_35 ( V_42 , ( T_4 T_2 * ) V_41 ) ;
break;
case V_60 :
V_42 = F_41 ( V_5 -> V_19 , 1 ) ;
V_42 <<= V_59 ;
error = F_35 ( V_42 , ( T_4 T_2 * ) V_41 ) ;
break;
case V_61 :
if ( V_5 -> V_19 < 0 || V_5 -> V_19 >= V_62 ) {
error = - V_63 ;
break;
}
V_43 = F_42 ( V_5 -> V_19 ) ;
if ( V_43 ) {
V_43 <<= V_59 ;
error = F_35 ( V_43 , ( T_4 T_2 * ) V_41 ) ;
} else {
error = - V_64 ;
}
break;
case V_65 :
if ( V_5 -> V_19 < 0 || V_5 -> V_19 >= V_62 ) {
error = - V_63 ;
break;
}
F_14 ( V_5 -> V_19 ) ;
break;
case V_66 :
if ( ! V_5 -> V_28 ) {
error = - V_6 ;
break;
}
error = F_43 ( V_67 ) ;
V_5 -> V_29 = false ;
break;
case V_68 :
V_5 -> V_30 = ! ! V_41 ;
break;
case V_69 :
if ( V_5 -> V_30 )
error = F_44 () ;
break;
case V_70 :
if ( F_45 () ) {
error = - V_6 ;
} else {
struct V_71 V_72 ;
T_6 V_73 ;
error = F_46 ( & V_72 , ( void T_2 * ) V_41 ,
sizeof( struct V_71 ) ) ;
if ( error ) {
error = - V_74 ;
break;
}
V_73 = F_47 ( V_72 . V_75 ) ;
if ( V_73 ) {
V_43 = V_72 . V_43 ;
V_5 -> V_19 = F_7 ( V_73 , V_43 , NULL ) ;
if ( V_5 -> V_19 < 0 )
error = - V_63 ;
} else {
V_5 -> V_19 = - 1 ;
error = - V_76 ;
}
}
break;
default:
error = - V_45 ;
}
F_48 () ;
F_49 ( & V_48 ) ;
return error ;
}
static long
F_50 ( struct V_2 * V_2 , unsigned int V_40 , unsigned long V_41 )
{
F_51 ( sizeof( T_4 ) != sizeof( V_77 ) ) ;
switch ( V_40 ) {
case V_58 :
case V_60 :
case V_61 : {
V_77 T_2 * V_78 = F_52 ( V_41 ) ;
T_4 V_43 ;
T_7 V_79 ;
int V_80 ;
V_79 = F_53 () ;
F_54 ( V_81 ) ;
V_80 = F_25 ( V_2 , V_40 , ( unsigned long ) & V_43 ) ;
F_54 ( V_79 ) ;
if ( ! V_80 && F_35 ( V_43 , V_78 ) )
V_80 = - V_74 ;
return V_80 ;
}
case V_51 :
return F_25 ( V_2 , V_40 ,
( unsigned long ) F_52 ( V_41 ) ) ;
case V_70 : {
struct V_82 T_2 * V_83 =
F_52 ( V_41 ) ;
struct V_71 V_72 ;
T_7 V_79 ;
int V_80 ;
V_80 = F_55 ( V_72 . V_43 , & V_83 -> V_43 ) ;
V_80 |= F_55 ( V_72 . V_75 , & V_83 -> V_75 ) ;
if ( V_80 )
return - V_74 ;
V_79 = F_53 () ;
F_54 ( V_81 ) ;
V_80 = F_25 ( V_2 , V_70 ,
( unsigned long ) & V_72 ) ;
F_54 ( V_79 ) ;
return V_80 ;
}
default:
return F_25 ( V_2 , V_40 , V_41 ) ;
}
}
static int T_8 F_56 ( void )
{
return F_57 ( & V_84 ) ;
}
