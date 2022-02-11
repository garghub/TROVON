static int F_1 ( struct V_1 * V_1 , struct V_2 * V_3 )
{
struct V_4 * V_5 ;
int error ;
F_2 ( & V_6 ) ;
if ( ! F_3 ( & V_7 , - 1 , 0 ) ) {
error = - V_8 ;
goto V_9;
}
if ( ( V_3 -> V_10 & V_11 ) == V_12 ) {
F_4 ( & V_7 ) ;
error = - V_13 ;
goto V_9;
}
if( F_5 () ) {
F_4 ( & V_7 ) ;
error = - V_14 ;
goto V_9;
}
F_6 ( V_1 , V_3 ) ;
V_5 = & V_15 ;
V_3 -> V_16 = V_5 ;
memset ( & V_5 -> V_17 , 0 , sizeof( struct V_18 ) ) ;
if ( ( V_3 -> V_10 & V_11 ) == V_19 ) {
V_5 -> V_20 = V_21 ?
F_7 ( V_21 , 0 , NULL ) : - 1 ;
V_5 -> V_22 = V_19 ;
error = F_8 ( V_23 ) ;
if ( error )
F_8 ( V_24 ) ;
} else {
F_9 () ;
F_10 () ;
V_5 -> V_20 = - 1 ;
V_5 -> V_22 = V_25 ;
error = F_8 ( V_26 ) ;
if ( error )
F_8 ( V_27 ) ;
}
if ( error ) {
F_11 () ;
F_4 ( & V_7 ) ;
}
V_5 -> V_28 = 0 ;
V_5 -> V_29 = 0 ;
V_5 -> V_30 = 0 ;
V_9:
F_12 ( & V_6 ) ;
return error ;
}
static int F_13 ( struct V_1 * V_1 , struct V_2 * V_3 )
{
struct V_4 * V_5 ;
F_2 ( & V_6 ) ;
F_14 () ;
F_11 () ;
V_5 = V_3 -> V_16 ;
F_15 ( V_5 -> V_20 ) ;
if ( V_5 -> V_28 ) {
F_16 () ;
F_17 () ;
}
F_8 ( V_5 -> V_22 == V_19 ?
V_24 : V_27 ) ;
F_4 ( & V_7 ) ;
F_12 ( & V_6 ) ;
return 0 ;
}
static T_1 F_18 ( struct V_2 * V_3 , char T_2 * V_31 ,
T_3 V_32 , T_4 * V_33 )
{
struct V_4 * V_5 ;
T_1 V_34 ;
T_4 V_35 = * V_33 & ~ V_36 ;
F_2 ( & V_6 ) ;
V_5 = V_3 -> V_16 ;
if ( ! V_5 -> V_29 ) {
V_34 = - V_37 ;
goto V_9;
}
if ( ! V_35 ) {
V_34 = F_19 ( & V_5 -> V_17 ) ;
if ( V_34 <= 0 )
goto V_9;
} else {
V_34 = V_38 - V_35 ;
}
V_34 = F_20 ( V_31 , V_32 , & V_35 ,
F_21 ( V_5 -> V_17 ) , V_34 ) ;
if ( V_34 > 0 )
* V_33 += V_34 ;
V_9:
F_12 ( & V_6 ) ;
return V_34 ;
}
static T_1 F_22 ( struct V_2 * V_3 , const char T_2 * V_31 ,
T_3 V_32 , T_4 * V_33 )
{
struct V_4 * V_5 ;
T_1 V_34 ;
T_4 V_35 = * V_33 & ~ V_36 ;
F_2 ( & V_6 ) ;
V_5 = V_3 -> V_16 ;
if ( ! V_35 ) {
V_34 = F_23 ( & V_5 -> V_17 ) ;
if ( V_34 <= 0 )
goto V_39;
} else {
V_34 = V_38 - V_35 ;
}
V_34 = F_24 ( F_21 ( V_5 -> V_17 ) , V_34 , & V_35 ,
V_31 , V_32 ) ;
if ( V_34 > 0 )
* V_33 += V_34 ;
V_39:
F_12 ( & V_6 ) ;
return V_34 ;
}
static void F_25 ( unsigned int V_40 )
{
if ( F_26 () )
F_27 ( V_41 L_1
L_2
L_3 ,
F_28 ( 0 ) , V_40 ) ;
}
static long F_29 ( struct V_2 * V_3 , unsigned int V_40 ,
unsigned long V_42 )
{
int error = 0 ;
struct V_4 * V_5 ;
T_4 V_43 ;
T_5 V_44 ;
if ( F_30 ( V_40 ) != V_45 )
return - V_46 ;
if ( F_31 ( V_40 ) > V_47 )
return - V_46 ;
if ( ! F_32 ( V_48 ) )
return - V_49 ;
if ( ! F_33 ( & V_6 ) )
return - V_8 ;
V_5 = V_3 -> V_16 ;
switch ( V_40 ) {
case V_50 :
if ( V_5 -> V_28 )
break;
F_27 ( L_4 ) ;
F_34 () ;
F_27 ( L_5 ) ;
error = F_35 () ;
if ( error )
break;
error = F_36 () ;
if ( error ) {
F_17 () ;
F_37 () ;
}
if ( ! error )
V_5 -> V_28 = 1 ;
break;
case V_51 :
if ( ! V_5 -> V_28 || V_5 -> V_29 )
break;
F_16 () ;
F_17 () ;
F_37 () ;
V_5 -> V_28 = 0 ;
break;
case V_52 :
F_25 ( V_40 ) ;
case V_53 :
if ( V_5 -> V_22 != V_19 || ! V_5 -> V_28 || V_5 -> V_29 ) {
error = - V_49 ;
break;
}
F_16 () ;
error = F_38 ( V_5 -> V_30 ) ;
if ( ! error )
error = F_39 ( V_54 , ( int T_2 * ) V_42 ) ;
if ( ! error )
V_5 -> V_29 = 1 ;
break;
case V_55 :
F_40 ( & V_5 -> V_17 ) ;
if ( V_5 -> V_22 != V_25 || ! V_5 -> V_28 ||
! F_41 ( & V_5 -> V_17 ) ) {
error = - V_49 ;
break;
}
error = F_42 ( V_5 -> V_30 ) ;
break;
case V_56 :
F_14 () ;
memset ( & V_5 -> V_17 , 0 , sizeof( struct V_18 ) ) ;
V_5 -> V_29 = 0 ;
break;
case V_57 :
F_25 ( V_40 ) ;
case V_58 :
V_59 = V_42 ;
break;
case V_60 :
if ( ! V_5 -> V_29 ) {
error = - V_37 ;
break;
}
V_43 = F_43 () ;
V_43 <<= V_61 ;
error = F_39 ( V_43 , ( T_4 T_2 * ) V_42 ) ;
break;
case V_62 :
F_25 ( V_40 ) ;
case V_63 :
V_43 = F_44 ( V_5 -> V_20 , 1 ) ;
V_43 <<= V_61 ;
error = F_39 ( V_43 , ( T_4 T_2 * ) V_42 ) ;
break;
case V_64 :
F_25 ( V_40 ) ;
case V_65 :
if ( V_5 -> V_20 < 0 || V_5 -> V_20 >= V_66 ) {
error = - V_67 ;
break;
}
V_44 = F_45 ( V_5 -> V_20 ) ;
if ( V_44 ) {
V_44 <<= V_61 ;
error = F_39 ( V_44 , ( T_4 T_2 * ) V_42 ) ;
} else {
error = - V_68 ;
}
break;
case V_69 :
if ( V_5 -> V_20 < 0 || V_5 -> V_20 >= V_66 ) {
error = - V_67 ;
break;
}
F_15 ( V_5 -> V_20 ) ;
break;
case V_70 :
F_25 ( V_40 ) ;
if ( ! F_46 () ) {
if ( F_47 ( V_42 ) ) {
V_5 -> V_20 = F_7 ( F_47 ( V_42 ) ,
0 , NULL ) ;
if ( V_5 -> V_20 < 0 )
error = - V_67 ;
} else {
V_5 -> V_20 = - 1 ;
error = - V_71 ;
}
} else {
error = - V_49 ;
}
break;
case V_72 :
if ( ! V_5 -> V_28 ) {
error = - V_49 ;
break;
}
error = F_48 ( V_73 ) ;
V_5 -> V_29 = 0 ;
break;
case V_74 :
V_5 -> V_30 = ! ! V_42 ;
break;
case V_75 :
if ( V_5 -> V_30 )
error = F_49 () ;
break;
case V_76 :
F_25 ( V_40 ) ;
error = - V_71 ;
switch ( V_42 ) {
case V_77 :
V_5 -> V_30 = 1 ;
error = 0 ;
break;
case V_78 :
if ( V_5 -> V_30 )
error = F_49 () ;
break;
case V_79 :
if ( V_5 -> V_30 )
error = 0 ;
break;
default:
F_27 ( V_80 L_6 , V_42 ) ;
}
break;
case V_81 :
if ( F_46 () ) {
error = - V_49 ;
} else {
struct V_82 V_83 ;
T_6 V_84 ;
error = F_50 ( & V_83 , ( void T_2 * ) V_42 ,
sizeof( struct V_82 ) ) ;
if ( error ) {
error = - V_85 ;
break;
}
V_84 = F_51 ( V_83 . V_86 ) ;
if ( V_84 ) {
V_44 = V_83 . V_44 ;
V_5 -> V_20 = F_7 ( V_84 , V_44 , NULL ) ;
if ( V_5 -> V_20 < 0 )
error = - V_67 ;
} else {
V_5 -> V_20 = - 1 ;
error = - V_71 ;
}
}
break;
default:
error = - V_46 ;
}
F_12 ( & V_6 ) ;
return error ;
}
static int T_7 F_52 ( void )
{
return F_53 ( & V_87 ) ;
}
