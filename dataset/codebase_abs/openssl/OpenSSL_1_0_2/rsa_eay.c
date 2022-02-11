const T_1 * F_1 ( void )
{
return ( & V_1 ) ;
}
static int F_2 ( int V_2 , const unsigned char * V_3 ,
unsigned char * V_4 , T_2 * V_5 , int V_6 )
{
T_3 * V_7 , * V_8 ;
int V_9 , V_10 , V_11 , V_12 = 0 , V_13 = - 1 ;
unsigned char * V_14 = NULL ;
T_4 * V_15 = NULL ;
if ( F_3 ( V_5 -> V_16 ) > V_17 ) {
F_4 ( V_18 , V_19 ) ;
return - 1 ;
}
if ( F_5 ( V_5 -> V_16 , V_5 -> V_20 ) <= 0 ) {
F_4 ( V_18 , V_21 ) ;
return - 1 ;
}
if ( F_3 ( V_5 -> V_16 ) > V_22 ) {
if ( F_3 ( V_5 -> V_20 ) > V_23 ) {
F_4 ( V_18 , V_21 ) ;
return - 1 ;
}
}
if ( ( V_15 = F_6 () ) == NULL )
goto V_24;
F_7 ( V_15 ) ;
V_7 = F_8 ( V_15 ) ;
V_8 = F_8 ( V_15 ) ;
V_12 = F_9 ( V_5 -> V_16 ) ;
V_14 = F_10 ( V_12 ) ;
if ( ! V_7 || ! V_8 || ! V_14 ) {
F_4 ( V_18 , V_25 ) ;
goto V_24;
}
switch ( V_6 ) {
case V_26 :
V_9 = F_11 ( V_14 , V_12 , V_3 , V_2 ) ;
break;
# ifndef F_12
case V_27 :
V_9 = F_13 ( V_14 , V_12 , V_3 , V_2 , NULL , 0 ) ;
break;
# endif
case V_28 :
V_9 = F_14 ( V_14 , V_12 , V_3 , V_2 ) ;
break;
case V_29 :
V_9 = F_15 ( V_14 , V_12 , V_3 , V_2 ) ;
break;
default:
F_4 ( V_18 , V_30 ) ;
goto V_24;
}
if ( V_9 <= 0 )
goto V_24;
if ( F_16 ( V_14 , V_12 , V_7 ) == NULL )
goto V_24;
if ( F_5 ( V_7 , V_5 -> V_16 ) >= 0 ) {
F_4 ( V_18 ,
V_31 ) ;
goto V_24;
}
if ( V_5 -> V_32 & V_33 )
if ( ! F_17
( & V_5 -> V_34 , V_35 , V_5 -> V_16 , V_15 ) )
goto V_24;
if ( ! V_5 -> V_36 -> V_37 ( V_8 , V_7 , V_5 -> V_20 , V_5 -> V_16 , V_15 ,
V_5 -> V_34 ) )
goto V_24;
V_10 = F_9 ( V_8 ) ;
V_9 = F_18 ( V_8 , & ( V_4 [ V_12 - V_10 ] ) ) ;
for ( V_11 = 0 ; V_11 < ( V_12 - V_9 ) ; V_11 ++ )
V_4 [ V_11 ] = 0 ;
V_13 = V_12 ;
V_24:
if ( V_15 != NULL ) {
F_19 ( V_15 ) ;
F_20 ( V_15 ) ;
}
if ( V_14 != NULL ) {
F_21 ( V_14 , V_12 ) ;
F_22 ( V_14 ) ;
}
return ( V_13 ) ;
}
static T_5 * F_23 ( T_2 * V_5 , int * V_38 , T_4 * V_15 )
{
T_5 * V_8 ;
int V_39 = 0 ;
T_6 V_40 ;
F_24 ( V_35 ) ;
if ( V_5 -> V_41 == NULL ) {
F_25 ( V_35 ) ;
F_26 ( V_35 ) ;
V_39 = 1 ;
if ( V_5 -> V_41 == NULL )
V_5 -> V_41 = F_27 ( V_5 , V_15 ) ;
}
V_8 = V_5 -> V_41 ;
if ( V_8 == NULL )
goto V_24;
F_28 ( & V_40 ) ;
if ( ! F_29 ( & V_40 , F_30 ( V_8 ) ) ) {
* V_38 = 1 ;
} else {
* V_38 = 0 ;
if ( V_5 -> V_42 == NULL ) {
if ( ! V_39 ) {
F_25 ( V_35 ) ;
F_26 ( V_35 ) ;
V_39 = 1 ;
}
if ( V_5 -> V_42 == NULL )
V_5 -> V_42 = F_27 ( V_5 , V_15 ) ;
}
V_8 = V_5 -> V_42 ;
}
V_24:
if ( V_39 )
F_31 ( V_35 ) ;
else
F_25 ( V_35 ) ;
return V_8 ;
}
static int F_32 ( T_5 * V_43 , T_3 * V_7 , T_3 * V_44 ,
T_4 * V_15 )
{
if ( V_44 == NULL )
return F_33 ( V_7 , NULL , V_43 , V_15 ) ;
else {
int V_8 ;
F_26 ( V_45 ) ;
V_8 = F_33 ( V_7 , V_44 , V_43 , V_15 ) ;
F_31 ( V_45 ) ;
return V_8 ;
}
}
static int F_34 ( T_5 * V_43 , T_3 * V_7 , T_3 * V_44 ,
T_4 * V_15 )
{
return F_35 ( V_7 , V_44 , V_43 , V_15 ) ;
}
static int F_36 ( int V_2 , const unsigned char * V_3 ,
unsigned char * V_4 , T_2 * V_5 , int V_6 )
{
T_3 * V_7 , * V_8 , * V_46 ;
int V_9 , V_10 , V_11 , V_12 = 0 , V_13 = - 1 ;
unsigned char * V_14 = NULL ;
T_4 * V_15 = NULL ;
int V_47 = 0 ;
T_3 * V_44 = NULL ;
T_5 * V_41 = NULL ;
if ( ( V_15 = F_6 () ) == NULL )
goto V_24;
F_7 ( V_15 ) ;
V_7 = F_8 ( V_15 ) ;
V_8 = F_8 ( V_15 ) ;
V_12 = F_9 ( V_5 -> V_16 ) ;
V_14 = F_10 ( V_12 ) ;
if ( ! V_7 || ! V_8 || ! V_14 ) {
F_4 ( V_48 , V_25 ) ;
goto V_24;
}
switch ( V_6 ) {
case V_26 :
V_9 = F_37 ( V_14 , V_12 , V_3 , V_2 ) ;
break;
case V_49 :
V_9 = F_38 ( V_14 , V_12 , V_3 , V_2 ) ;
break;
case V_29 :
V_9 = F_15 ( V_14 , V_12 , V_3 , V_2 ) ;
break;
case V_28 :
default:
F_4 ( V_48 , V_30 ) ;
goto V_24;
}
if ( V_9 <= 0 )
goto V_24;
if ( F_16 ( V_14 , V_12 , V_7 ) == NULL )
goto V_24;
if ( F_5 ( V_7 , V_5 -> V_16 ) >= 0 ) {
F_4 ( V_48 ,
V_31 ) ;
goto V_24;
}
if ( ! ( V_5 -> V_32 & V_50 ) ) {
V_41 = F_23 ( V_5 , & V_47 , V_15 ) ;
if ( V_41 == NULL ) {
F_4 ( V_48 , V_51 ) ;
goto V_24;
}
}
if ( V_41 != NULL ) {
if ( ! V_47 && ( ( V_44 = F_8 ( V_15 ) ) == NULL ) ) {
F_4 ( V_48 , V_25 ) ;
goto V_24;
}
if ( ! F_32 ( V_41 , V_7 , V_44 , V_15 ) )
goto V_24;
}
if ( ( V_5 -> V_32 & V_52 ) ||
( ( V_5 -> V_53 != NULL ) &&
( V_5 -> V_54 != NULL ) &&
( V_5 -> V_55 != NULL ) && ( V_5 -> V_56 != NULL ) && ( V_5 -> V_57 != NULL ) ) ) {
if ( ! V_5 -> V_36 -> V_58 ( V_8 , V_7 , V_5 , V_15 ) )
goto V_24;
} else {
T_3 V_59 ;
T_3 * V_60 = NULL ;
if ( ! ( V_5 -> V_32 & V_61 ) ) {
F_39 ( & V_59 ) ;
V_60 = & V_59 ;
F_40 ( V_60 , V_5 -> V_60 , V_62 ) ;
} else
V_60 = V_5 -> V_60 ;
if ( V_5 -> V_32 & V_33 )
if ( ! F_17
( & V_5 -> V_34 , V_35 , V_5 -> V_16 , V_15 ) )
goto V_24;
if ( ! V_5 -> V_36 -> V_37 ( V_8 , V_7 , V_60 , V_5 -> V_16 , V_15 ,
V_5 -> V_34 ) )
goto V_24;
}
if ( V_41 )
if ( ! F_34 ( V_41 , V_8 , V_44 , V_15 ) )
goto V_24;
if ( V_6 == V_49 ) {
F_41 ( V_7 , V_5 -> V_16 , V_8 ) ;
if ( F_42 ( V_8 , V_7 ) > 0 )
V_46 = V_7 ;
else
V_46 = V_8 ;
} else
V_46 = V_8 ;
V_10 = F_9 ( V_46 ) ;
V_9 = F_18 ( V_46 , & ( V_4 [ V_12 - V_10 ] ) ) ;
for ( V_11 = 0 ; V_11 < ( V_12 - V_9 ) ; V_11 ++ )
V_4 [ V_11 ] = 0 ;
V_13 = V_12 ;
V_24:
if ( V_15 != NULL ) {
F_19 ( V_15 ) ;
F_20 ( V_15 ) ;
}
if ( V_14 != NULL ) {
F_21 ( V_14 , V_12 ) ;
F_22 ( V_14 ) ;
}
return ( V_13 ) ;
}
static int F_43 ( int V_2 , const unsigned char * V_3 ,
unsigned char * V_4 , T_2 * V_5 , int V_6 )
{
T_3 * V_7 , * V_8 ;
int V_10 , V_12 = 0 , V_13 = - 1 ;
unsigned char * V_53 ;
unsigned char * V_14 = NULL ;
T_4 * V_15 = NULL ;
int V_47 = 0 ;
T_3 * V_44 = NULL ;
T_5 * V_41 = NULL ;
if ( ( V_15 = F_6 () ) == NULL )
goto V_24;
F_7 ( V_15 ) ;
V_7 = F_8 ( V_15 ) ;
V_8 = F_8 ( V_15 ) ;
V_12 = F_9 ( V_5 -> V_16 ) ;
V_14 = F_10 ( V_12 ) ;
if ( ! V_7 || ! V_8 || ! V_14 ) {
F_4 ( V_63 , V_25 ) ;
goto V_24;
}
if ( V_2 > V_12 ) {
F_4 ( V_63 ,
V_64 ) ;
goto V_24;
}
if ( F_16 ( V_3 , ( int ) V_2 , V_7 ) == NULL )
goto V_24;
if ( F_5 ( V_7 , V_5 -> V_16 ) >= 0 ) {
F_4 ( V_63 ,
V_31 ) ;
goto V_24;
}
if ( ! ( V_5 -> V_32 & V_50 ) ) {
V_41 = F_23 ( V_5 , & V_47 , V_15 ) ;
if ( V_41 == NULL ) {
F_4 ( V_63 , V_51 ) ;
goto V_24;
}
}
if ( V_41 != NULL ) {
if ( ! V_47 && ( ( V_44 = F_8 ( V_15 ) ) == NULL ) ) {
F_4 ( V_63 , V_25 ) ;
goto V_24;
}
if ( ! F_32 ( V_41 , V_7 , V_44 , V_15 ) )
goto V_24;
}
if ( ( V_5 -> V_32 & V_52 ) ||
( ( V_5 -> V_53 != NULL ) &&
( V_5 -> V_54 != NULL ) &&
( V_5 -> V_55 != NULL ) && ( V_5 -> V_56 != NULL ) && ( V_5 -> V_57 != NULL ) ) ) {
if ( ! V_5 -> V_36 -> V_58 ( V_8 , V_7 , V_5 , V_15 ) )
goto V_24;
} else {
T_3 V_59 ;
T_3 * V_60 = NULL ;
if ( ! ( V_5 -> V_32 & V_61 ) ) {
V_60 = & V_59 ;
F_40 ( V_60 , V_5 -> V_60 , V_62 ) ;
} else
V_60 = V_5 -> V_60 ;
if ( V_5 -> V_32 & V_33 )
if ( ! F_17
( & V_5 -> V_34 , V_35 , V_5 -> V_16 , V_15 ) )
goto V_24;
if ( ! V_5 -> V_36 -> V_37 ( V_8 , V_7 , V_60 , V_5 -> V_16 , V_15 ,
V_5 -> V_34 ) )
goto V_24;
}
if ( V_41 )
if ( ! F_34 ( V_41 , V_8 , V_44 , V_15 ) )
goto V_24;
V_53 = V_14 ;
V_10 = F_18 ( V_8 , V_53 ) ;
switch ( V_6 ) {
case V_26 :
V_13 = F_44 ( V_4 , V_12 , V_14 , V_10 , V_12 ) ;
break;
# ifndef F_12
case V_27 :
V_13 = F_45 ( V_4 , V_12 , V_14 , V_10 , V_12 , NULL , 0 ) ;
break;
# endif
case V_28 :
V_13 = F_46 ( V_4 , V_12 , V_14 , V_10 , V_12 ) ;
break;
case V_29 :
V_13 = F_47 ( V_4 , V_12 , V_14 , V_10 , V_12 ) ;
break;
default:
F_4 ( V_63 , V_30 ) ;
goto V_24;
}
if ( V_13 < 0 )
F_4 ( V_63 , V_65 ) ;
V_24:
if ( V_15 != NULL ) {
F_19 ( V_15 ) ;
F_20 ( V_15 ) ;
}
if ( V_14 != NULL ) {
F_21 ( V_14 , V_12 ) ;
F_22 ( V_14 ) ;
}
return ( V_13 ) ;
}
static int F_48 ( int V_2 , const unsigned char * V_3 ,
unsigned char * V_4 , T_2 * V_5 , int V_6 )
{
T_3 * V_7 , * V_8 ;
int V_9 , V_12 = 0 , V_13 = - 1 ;
unsigned char * V_53 ;
unsigned char * V_14 = NULL ;
T_4 * V_15 = NULL ;
if ( F_3 ( V_5 -> V_16 ) > V_17 ) {
F_4 ( V_66 , V_19 ) ;
return - 1 ;
}
if ( F_5 ( V_5 -> V_16 , V_5 -> V_20 ) <= 0 ) {
F_4 ( V_66 , V_21 ) ;
return - 1 ;
}
if ( F_3 ( V_5 -> V_16 ) > V_22 ) {
if ( F_3 ( V_5 -> V_20 ) > V_23 ) {
F_4 ( V_66 , V_21 ) ;
return - 1 ;
}
}
if ( ( V_15 = F_6 () ) == NULL )
goto V_24;
F_7 ( V_15 ) ;
V_7 = F_8 ( V_15 ) ;
V_8 = F_8 ( V_15 ) ;
V_12 = F_9 ( V_5 -> V_16 ) ;
V_14 = F_10 ( V_12 ) ;
if ( ! V_7 || ! V_8 || ! V_14 ) {
F_4 ( V_66 , V_25 ) ;
goto V_24;
}
if ( V_2 > V_12 ) {
F_4 ( V_66 , V_64 ) ;
goto V_24;
}
if ( F_16 ( V_3 , V_2 , V_7 ) == NULL )
goto V_24;
if ( F_5 ( V_7 , V_5 -> V_16 ) >= 0 ) {
F_4 ( V_66 ,
V_31 ) ;
goto V_24;
}
if ( V_5 -> V_32 & V_33 )
if ( ! F_17
( & V_5 -> V_34 , V_35 , V_5 -> V_16 , V_15 ) )
goto V_24;
if ( ! V_5 -> V_36 -> V_37 ( V_8 , V_7 , V_5 -> V_20 , V_5 -> V_16 , V_15 ,
V_5 -> V_34 ) )
goto V_24;
if ( ( V_6 == V_49 ) && ( ( V_8 -> V_60 [ 0 ] & 0xf ) != 12 ) )
if ( ! F_41 ( V_8 , V_5 -> V_16 , V_8 ) )
goto V_24;
V_53 = V_14 ;
V_9 = F_18 ( V_8 , V_53 ) ;
switch ( V_6 ) {
case V_26 :
V_13 = F_49 ( V_4 , V_12 , V_14 , V_9 , V_12 ) ;
break;
case V_49 :
V_13 = F_50 ( V_4 , V_12 , V_14 , V_9 , V_12 ) ;
break;
case V_29 :
V_13 = F_47 ( V_4 , V_12 , V_14 , V_9 , V_12 ) ;
break;
default:
F_4 ( V_66 , V_30 ) ;
goto V_24;
}
if ( V_13 < 0 )
F_4 ( V_66 , V_65 ) ;
V_24:
if ( V_15 != NULL ) {
F_19 ( V_15 ) ;
F_20 ( V_15 ) ;
}
if ( V_14 != NULL ) {
F_21 ( V_14 , V_12 ) ;
F_22 ( V_14 ) ;
}
return ( V_13 ) ;
}
static int F_51 ( T_3 * V_67 , const T_3 * V_68 , T_2 * V_5 , T_4 * V_15 )
{
T_3 * V_69 , * V_70 , * V_71 ;
T_3 V_72 , V_73 , V_74 , V_75 ;
T_3 * V_55 , * V_56 , * V_76 , * V_77 ;
int V_8 = 0 ;
F_7 ( V_15 ) ;
V_69 = F_8 ( V_15 ) ;
V_70 = F_8 ( V_15 ) ;
V_71 = F_8 ( V_15 ) ;
{
T_3 V_78 , V_79 ;
T_3 * V_53 = NULL , * V_54 = NULL ;
if ( ! ( V_5 -> V_32 & V_61 ) ) {
F_39 ( & V_78 ) ;
V_53 = & V_78 ;
F_40 ( V_53 , V_5 -> V_53 , V_62 ) ;
F_39 ( & V_79 ) ;
V_54 = & V_79 ;
F_40 ( V_54 , V_5 -> V_54 , V_62 ) ;
} else {
V_53 = V_5 -> V_53 ;
V_54 = V_5 -> V_54 ;
}
if ( V_5 -> V_32 & V_80 ) {
if ( ! F_17
( & V_5 -> V_81 , V_35 , V_53 , V_15 ) )
goto V_24;
if ( ! F_17
( & V_5 -> V_82 , V_35 , V_54 , V_15 ) )
goto V_24;
}
}
if ( V_5 -> V_32 & V_33 )
if ( ! F_17
( & V_5 -> V_34 , V_35 , V_5 -> V_16 , V_15 ) )
goto V_24;
if ( ! ( V_5 -> V_32 & V_61 ) ) {
V_76 = & V_74 ;
F_40 ( V_76 , V_68 , V_62 ) ;
if ( ! F_52 ( V_69 , V_76 , V_5 -> V_54 , V_15 ) )
goto V_24;
} else {
if ( ! F_52 ( V_69 , V_68 , V_5 -> V_54 , V_15 ) )
goto V_24;
}
if ( ! ( V_5 -> V_32 & V_61 ) ) {
V_56 = & V_73 ;
F_40 ( V_56 , V_5 -> V_56 , V_62 ) ;
} else
V_56 = V_5 -> V_56 ;
if ( ! V_5 -> V_36 -> V_37 ( V_70 , V_69 , V_56 , V_5 -> V_54 , V_15 , V_5 -> V_82 ) )
goto V_24;
if ( ! ( V_5 -> V_32 & V_61 ) ) {
V_76 = & V_74 ;
F_40 ( V_76 , V_68 , V_62 ) ;
if ( ! F_52 ( V_69 , V_76 , V_5 -> V_53 , V_15 ) )
goto V_24;
} else {
if ( ! F_52 ( V_69 , V_68 , V_5 -> V_53 , V_15 ) )
goto V_24;
}
if ( ! ( V_5 -> V_32 & V_61 ) ) {
V_55 = & V_72 ;
F_40 ( V_55 , V_5 -> V_55 , V_62 ) ;
} else
V_55 = V_5 -> V_55 ;
if ( ! V_5 -> V_36 -> V_37 ( V_67 , V_69 , V_55 , V_5 -> V_53 , V_15 , V_5 -> V_81 ) )
goto V_24;
if ( ! F_41 ( V_67 , V_67 , V_70 ) )
goto V_24;
if ( F_53 ( V_67 ) )
if ( ! F_54 ( V_67 , V_67 , V_5 -> V_53 ) )
goto V_24;
if ( ! F_55 ( V_69 , V_67 , V_5 -> V_57 , V_15 ) )
goto V_24;
if ( ! ( V_5 -> V_32 & V_61 ) ) {
V_77 = & V_75 ;
F_40 ( V_77 , V_69 , V_62 ) ;
} else
V_77 = V_69 ;
if ( ! F_52 ( V_67 , V_77 , V_5 -> V_53 , V_15 ) )
goto V_24;
if ( F_53 ( V_67 ) )
if ( ! F_54 ( V_67 , V_67 , V_5 -> V_53 ) )
goto V_24;
if ( ! F_55 ( V_69 , V_67 , V_5 -> V_54 , V_15 ) )
goto V_24;
if ( ! F_54 ( V_67 , V_69 , V_70 ) )
goto V_24;
if ( V_5 -> V_20 && V_5 -> V_16 ) {
if ( ! V_5 -> V_36 -> V_37 ( V_71 , V_67 , V_5 -> V_20 , V_5 -> V_16 , V_15 ,
V_5 -> V_34 ) )
goto V_24;
if ( ! F_41 ( V_71 , V_71 , V_68 ) )
goto V_24;
if ( ! F_52 ( V_71 , V_71 , V_5 -> V_16 , V_15 ) )
goto V_24;
if ( F_53 ( V_71 ) )
if ( ! F_54 ( V_71 , V_71 , V_5 -> V_16 ) )
goto V_24;
if ( ! F_56 ( V_71 ) ) {
T_3 V_59 ;
T_3 * V_60 = NULL ;
if ( ! ( V_5 -> V_32 & V_61 ) ) {
V_60 = & V_59 ;
F_40 ( V_60 , V_5 -> V_60 , V_62 ) ;
} else
V_60 = V_5 -> V_60 ;
if ( ! V_5 -> V_36 -> V_37 ( V_67 , V_68 , V_60 , V_5 -> V_16 , V_15 ,
V_5 -> V_34 ) )
goto V_24;
}
}
V_8 = 1 ;
V_24:
F_19 ( V_15 ) ;
return ( V_8 ) ;
}
static int F_57 ( T_2 * V_5 )
{
V_5 -> V_32 |= V_33 | V_80 ;
return ( 1 ) ;
}
static int F_58 ( T_2 * V_5 )
{
if ( V_5 -> V_34 != NULL )
F_59 ( V_5 -> V_34 ) ;
if ( V_5 -> V_81 != NULL )
F_59 ( V_5 -> V_81 ) ;
if ( V_5 -> V_82 != NULL )
F_59 ( V_5 -> V_82 ) ;
return ( 1 ) ;
}
