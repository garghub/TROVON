static int F_1 ( struct V_1 * V_1 , struct V_2 * V_3 )
{
struct V_4 * V_5 ;
int error ;
F_2 () ;
if ( ! F_3 ( & V_6 , - 1 , 0 ) ) {
error = - V_7 ;
goto V_8;
}
if ( ( V_3 -> V_9 & V_10 ) == V_11 ) {
F_4 ( & V_6 ) ;
error = - V_12 ;
goto V_8;
}
if( F_5 () ) {
F_4 ( & V_6 ) ;
error = - V_13 ;
goto V_8;
}
F_6 ( V_1 , V_3 ) ;
V_5 = & V_14 ;
V_3 -> V_15 = V_5 ;
memset ( & V_5 -> V_16 , 0 , sizeof( struct V_17 ) ) ;
if ( ( V_3 -> V_9 & V_10 ) == V_18 ) {
V_5 -> V_19 = V_20 ?
F_7 ( V_20 , 0 , NULL ) : - 1 ;
V_5 -> V_21 = V_18 ;
error = F_8 ( V_22 ) ;
if ( error )
F_8 ( V_23 ) ;
} else {
F_9 () ;
F_10 () ;
V_5 -> V_19 = - 1 ;
V_5 -> V_21 = V_24 ;
error = F_8 ( V_25 ) ;
if ( error )
F_8 ( V_26 ) ;
}
if ( error ) {
F_11 () ;
F_4 ( & V_6 ) ;
}
V_5 -> V_27 = 0 ;
V_5 -> V_28 = 0 ;
V_5 -> V_29 = 0 ;
V_8:
F_12 () ;
return error ;
}
static int F_13 ( struct V_1 * V_1 , struct V_2 * V_3 )
{
struct V_4 * V_5 ;
F_2 () ;
F_14 () ;
F_11 () ;
V_5 = V_3 -> V_15 ;
F_15 ( V_5 -> V_19 ) ;
if ( V_5 -> V_27 ) {
F_16 () ;
F_17 () ;
}
F_8 ( V_5 -> V_21 == V_18 ?
V_23 : V_26 ) ;
F_4 ( & V_6 ) ;
F_12 () ;
return 0 ;
}
static T_1 F_18 ( struct V_2 * V_3 , char T_2 * V_30 ,
T_3 V_31 , T_4 * V_32 )
{
struct V_4 * V_5 ;
T_1 V_33 ;
T_4 V_34 = * V_32 & ~ V_35 ;
F_2 () ;
V_5 = V_3 -> V_15 ;
if ( ! V_5 -> V_28 ) {
V_33 = - V_36 ;
goto V_8;
}
if ( ! V_34 ) {
V_33 = F_19 ( & V_5 -> V_16 ) ;
if ( V_33 <= 0 )
goto V_8;
} else {
V_33 = V_37 - V_34 ;
}
V_33 = F_20 ( V_30 , V_31 , & V_34 ,
F_21 ( V_5 -> V_16 ) , V_33 ) ;
if ( V_33 > 0 )
* V_32 += V_33 ;
V_8:
F_12 () ;
return V_33 ;
}
static T_1 F_22 ( struct V_2 * V_3 , const char T_2 * V_30 ,
T_3 V_31 , T_4 * V_32 )
{
struct V_4 * V_5 ;
T_1 V_33 ;
T_4 V_34 = * V_32 & ~ V_35 ;
F_2 () ;
V_5 = V_3 -> V_15 ;
if ( ! V_34 ) {
V_33 = F_23 ( & V_5 -> V_16 ) ;
if ( V_33 <= 0 )
goto V_38;
} else {
V_33 = V_37 - V_34 ;
}
V_33 = F_24 ( F_21 ( V_5 -> V_16 ) , V_33 , & V_34 ,
V_30 , V_31 ) ;
if ( V_33 > 0 )
* V_32 += V_33 ;
V_38:
F_12 () ;
return V_33 ;
}
static long F_25 ( struct V_2 * V_3 , unsigned int V_39 ,
unsigned long V_40 )
{
int error = 0 ;
struct V_4 * V_5 ;
T_4 V_41 ;
T_5 V_42 ;
if ( F_26 ( V_39 ) != V_43 )
return - V_44 ;
if ( F_27 ( V_39 ) > V_45 )
return - V_44 ;
if ( ! F_28 ( V_46 ) )
return - V_47 ;
if ( ! F_29 ( & V_48 ) )
return - V_7 ;
V_5 = V_3 -> V_15 ;
switch ( V_39 ) {
case V_49 :
if ( V_5 -> V_27 )
break;
F_30 ( L_1 ) ;
F_31 () ;
F_30 ( L_2 ) ;
error = F_32 () ;
if ( error )
break;
error = F_33 () ;
if ( error )
F_34 () ;
else
V_5 -> V_27 = 1 ;
break;
case V_50 :
if ( ! V_5 -> V_27 || V_5 -> V_28 )
break;
F_16 () ;
F_17 () ;
F_34 () ;
V_5 -> V_27 = 0 ;
break;
case V_51 :
if ( V_5 -> V_21 != V_18 || ! V_5 -> V_27 || V_5 -> V_28 ) {
error = - V_47 ;
break;
}
F_16 () ;
error = F_35 ( V_5 -> V_29 ) ;
if ( error ) {
F_36 () ;
} else {
error = F_37 ( V_52 , ( int T_2 * ) V_40 ) ;
if ( ! error && ! V_53 )
V_5 -> V_28 = 1 ;
if ( V_53 ) {
V_53 = false ;
F_36 () ;
}
}
break;
case V_54 :
F_38 ( & V_5 -> V_16 ) ;
if ( V_5 -> V_21 != V_24 || ! V_5 -> V_27 ||
! F_39 ( & V_5 -> V_16 ) ) {
error = - V_47 ;
break;
}
error = F_40 ( V_5 -> V_29 ) ;
break;
case V_55 :
F_14 () ;
memset ( & V_5 -> V_16 , 0 , sizeof( struct V_17 ) ) ;
V_5 -> V_28 = 0 ;
F_36 () ;
break;
case V_56 :
V_57 = V_40 ;
break;
case V_58 :
if ( ! V_5 -> V_28 ) {
error = - V_36 ;
break;
}
V_41 = F_41 () ;
V_41 <<= V_59 ;
error = F_37 ( V_41 , ( T_4 T_2 * ) V_40 ) ;
break;
case V_60 :
V_41 = F_42 ( V_5 -> V_19 , 1 ) ;
V_41 <<= V_59 ;
error = F_37 ( V_41 , ( T_4 T_2 * ) V_40 ) ;
break;
case V_61 :
if ( V_5 -> V_19 < 0 || V_5 -> V_19 >= V_62 ) {
error = - V_63 ;
break;
}
V_42 = F_43 ( V_5 -> V_19 ) ;
if ( V_42 ) {
V_42 <<= V_59 ;
error = F_37 ( V_42 , ( T_4 T_2 * ) V_40 ) ;
} else {
error = - V_64 ;
}
break;
case V_65 :
if ( V_5 -> V_19 < 0 || V_5 -> V_19 >= V_62 ) {
error = - V_63 ;
break;
}
F_15 ( V_5 -> V_19 ) ;
break;
case V_66 :
if ( ! V_5 -> V_27 ) {
error = - V_47 ;
break;
}
error = F_44 ( V_67 ) ;
V_5 -> V_28 = 0 ;
break;
case V_68 :
V_5 -> V_29 = ! ! V_40 ;
break;
case V_69 :
if ( V_5 -> V_29 )
error = F_45 () ;
break;
case V_70 :
if ( F_46 () ) {
error = - V_47 ;
} else {
struct V_71 V_72 ;
T_6 V_73 ;
error = F_47 ( & V_72 , ( void T_2 * ) V_40 ,
sizeof( struct V_71 ) ) ;
if ( error ) {
error = - V_74 ;
break;
}
V_73 = F_48 ( V_72 . V_75 ) ;
if ( V_73 ) {
V_42 = V_72 . V_42 ;
V_5 -> V_19 = F_7 ( V_73 , V_42 , NULL ) ;
if ( V_5 -> V_19 < 0 )
error = - V_63 ;
} else {
V_5 -> V_19 = - 1 ;
error = - V_76 ;
}
}
break;
default:
error = - V_44 ;
}
F_49 ( & V_48 ) ;
return error ;
}
static long
F_50 ( struct V_2 * V_2 , unsigned int V_39 , unsigned long V_40 )
{
F_51 ( sizeof( T_4 ) != sizeof( V_77 ) ) ;
switch ( V_39 ) {
case V_58 :
case V_60 :
case V_61 : {
V_77 T_2 * V_78 = F_52 ( V_40 ) ;
T_4 V_42 ;
T_7 V_79 ;
int V_80 ;
V_79 = F_53 () ;
F_54 ( V_81 ) ;
V_80 = F_25 ( V_2 , V_39 , ( unsigned long ) & V_42 ) ;
F_54 ( V_79 ) ;
if ( ! V_80 && F_37 ( V_42 , V_78 ) )
V_80 = - V_74 ;
return V_80 ;
}
case V_51 :
return F_25 ( V_2 , V_39 ,
( unsigned long ) F_52 ( V_40 ) ) ;
case V_70 : {
struct V_82 T_2 * V_83 =
F_52 ( V_40 ) ;
struct V_71 V_72 ;
T_7 V_79 ;
int V_80 ;
V_80 = F_55 ( V_72 . V_42 , & V_83 -> V_42 ) ;
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
return F_25 ( V_2 , V_39 , V_40 ) ;
}
}
static int T_8 F_56 ( void )
{
return F_57 ( & V_84 ) ;
}
