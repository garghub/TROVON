const T_1 * F_1 ( void )
{
return ( & V_1 ) ;
}
static int F_2 ( T_2 * V_2 )
{
T_3 * V_3 ;
V_2 -> V_4 = 0 ;
V_2 -> V_5 = ( int ) V_6 ;
V_2 -> V_7 = 0 ;
if ( ( V_3 = F_3 () ) == NULL )
return ( 0 ) ;
V_2 -> V_8 = ( char * ) V_3 ;
V_3 -> V_9 = V_10 ;
V_2 -> V_11 = 1 ;
return ( 1 ) ;
}
static T_3 * F_3 ( void )
{
T_3 * V_12 ;
if ( ( V_12 = F_4 ( sizeof( * V_12 ) ) ) == NULL )
return ( NULL ) ;
V_12 -> V_13 = V_14 ;
V_12 -> V_15 = ( int ) V_6 ;
return ( V_12 ) ;
}
static void F_5 ( T_3 * V_16 )
{
if ( V_16 == NULL )
return;
F_6 ( V_16 -> V_17 ) ;
F_6 ( V_16 -> V_18 ) ;
F_7 ( V_16 -> V_19 ) ;
F_6 ( V_16 -> V_20 ) ;
F_6 ( V_16 -> V_21 ) ;
F_6 ( V_16 -> V_22 ) ;
F_6 ( V_16 -> V_23 ) ;
F_8 ( V_16 -> V_24 ) ;
F_6 ( V_16 ) ;
}
static void F_9 ( T_2 * V_25 )
{
T_3 * V_26 ;
V_26 = ( T_3 * ) V_25 -> V_8 ;
if ( V_26 -> V_15 != ( int ) V_6 ) {
V_11 ( V_26 -> V_15 , 2 ) ;
F_10 ( V_26 -> V_15 ) ;
V_26 -> V_15 = ( int ) V_6 ;
V_25 -> V_5 = ( int ) V_6 ;
}
}
static int F_11 ( T_2 * V_16 )
{
T_3 * V_27 ;
if ( V_16 == NULL )
return ( 0 ) ;
V_27 = ( T_3 * ) V_16 -> V_8 ;
if ( V_16 -> V_11 ) {
F_9 ( V_16 ) ;
F_5 ( V_27 ) ;
V_16 -> V_8 = NULL ;
V_16 -> V_7 = 0 ;
V_16 -> V_4 = 0 ;
}
return ( 1 ) ;
}
static int F_12 ( T_2 * V_28 , T_3 * V_26 )
{
T_2 * V_25 = NULL , * V_29 ;
int V_30 = - 1 , V_12 = - 1 ;
for (; ; ) {
switch ( V_26 -> V_9 ) {
case V_10 :
if ( V_26 -> V_17 == NULL && V_26 -> V_18 == NULL ) {
F_13 ( V_31 , V_32 ) ;
F_14 ( 4 ,
L_1 , V_26 -> V_17 ,
L_2 , V_26 -> V_18 ) ;
goto V_33;
}
F_6 ( V_26 -> V_20 ) ;
V_26 -> V_20 = NULL ;
F_6 ( V_26 -> V_21 ) ;
V_26 -> V_21 = NULL ;
F_6 ( V_26 -> V_22 ) ;
V_26 -> V_22 = NULL ;
F_6 ( V_26 -> V_23 ) ;
V_26 -> V_23 = NULL ;
V_26 -> V_9 = V_34 ;
break;
case V_34 :
{
int V_35 = V_36 ;
switch ( V_26 -> V_13 ) {
case V_37 :
if ( 1 ) {
#ifdef F_15
V_35 = F_15 ;
} else {
#endif
F_13 ( V_31 , V_38 ) ;
goto V_33;
}
break;
case V_39 :
V_35 = V_40 ;
break;
case V_14 :
V_35 = V_36 ;
break;
default:
F_13 ( V_31 , V_41 ) ;
goto V_33;
}
if ( F_16 ( V_26 -> V_17 , V_26 -> V_18 , V_42 ,
V_35 , V_43 , & V_26 -> V_19 ) == 0 )
goto V_33;
}
if ( V_26 -> V_19 == NULL ) {
F_13 ( V_31 , V_44 ) ;
goto V_33;
}
V_26 -> V_45 = V_26 -> V_19 ;
V_26 -> V_9 = V_46 ;
break;
case V_46 :
V_12 = F_17 ( F_18 ( V_26 -> V_45 ) ,
F_19 ( V_26 -> V_45 ) ,
F_20 ( V_26 -> V_45 ) , 0 ) ;
if ( V_12 == ( int ) V_6 ) {
F_21 ( V_47 , F_22 () ) ;
F_14 ( 4 ,
L_1 , V_26 -> V_17 ,
L_2 , V_26 -> V_18 ) ;
F_13 ( V_31 , V_48 ) ;
goto V_33;
}
V_26 -> V_15 = V_12 ;
V_28 -> V_5 = V_12 ;
V_26 -> V_9 = V_49 ;
break;
case V_49 :
{
if ( ! F_23 ( V_26 -> V_15 ,
F_24 ( V_26 -> V_45 ) ,
V_26 -> V_50 ) ) {
F_25 ( V_26 -> V_15 ) ;
goto V_33;
}
}
{
union V_51 V_52 ;
V_52 . V_53 = & V_26 -> V_54 ;
if ( ! F_26 ( V_26 -> V_15 , V_55 ,
& V_52 ) ) {
F_25 ( V_26 -> V_15 ) ;
goto V_33;
}
}
V_26 -> V_20 =
F_27 ( & V_26 -> V_54 , 1 ) ;
V_26 -> V_21 =
F_28 ( & V_26 -> V_54 , 1 ) ;
V_26 -> V_9 = V_56 ;
V_30 = - 1 ;
V_12 = 1 ;
goto V_57;
case V_56 :
if ( V_28 -> V_58 != NULL ) {
V_26 -> V_9 = V_59 ;
break;
}
F_29 ( V_28 ) ;
V_28 -> V_60 = 0 ;
V_30 = F_30 ( V_26 -> V_15 , & V_26 -> V_61 ,
V_26 -> V_62 ) ;
if ( V_30 < 0 ) {
if ( F_31 ( V_30 ) ) {
F_32 ( V_28 ) ;
V_28 -> V_60 = V_63 ;
goto V_57;
}
}
if ( V_30 < 0 ) {
V_12 = V_30 ;
goto V_33;
}
V_25 = F_33 ( V_30 , V_64 ) ;
if ( V_25 == NULL )
goto V_33;
F_34 ( V_25 , F_35 ( V_28 ) ) ;
F_36 ( V_25 , F_37 ( V_28 ) ) ;
if ( V_26 -> V_24 != NULL ) {
if ( ( V_29 = F_38 ( V_26 -> V_24 ) ) == NULL )
goto V_33;
if ( ! F_39 ( V_29 , V_25 ) )
goto V_33;
V_25 = V_29 ;
}
if ( F_39 ( V_28 , V_25 ) == NULL )
goto V_33;
V_26 -> V_22 =
F_27 ( & V_26 -> V_61 , 1 ) ;
V_26 -> V_23 =
F_28 ( & V_26 -> V_61 , 1 ) ;
V_26 -> V_9 = V_59 ;
V_25 = NULL ;
V_12 = 1 ;
goto V_57;
case V_59 :
if ( V_28 -> V_58 == NULL ) {
V_26 -> V_9 = V_56 ;
break;
}
V_12 = 1 ;
goto V_57;
default:
V_12 = 0 ;
goto V_57;
}
}
V_33:
if ( V_25 != NULL )
F_8 ( V_25 ) ;
else if ( V_30 >= 0 )
F_25 ( V_30 ) ;
V_57:
return V_12 ;
}
static int F_40 ( T_2 * V_28 , char * V_65 , int V_66 )
{
int V_12 = 0 ;
T_3 * V_27 ;
F_29 ( V_28 ) ;
V_27 = ( T_3 * ) V_28 -> V_8 ;
while ( V_28 -> V_58 == NULL ) {
V_12 = F_12 ( V_28 , V_27 ) ;
if ( V_12 <= 0 )
return ( V_12 ) ;
}
V_12 = F_41 ( V_28 -> V_58 , V_65 , V_66 ) ;
F_42 ( V_28 ) ;
return ( V_12 ) ;
}
static int F_43 ( T_2 * V_28 , const char * V_67 , int V_68 )
{
int V_12 ;
T_3 * V_27 ;
F_29 ( V_28 ) ;
V_27 = ( T_3 * ) V_28 -> V_8 ;
while ( V_28 -> V_58 == NULL ) {
V_12 = F_12 ( V_28 , V_27 ) ;
if ( V_12 <= 0 )
return ( V_12 ) ;
}
V_12 = F_44 ( V_28 -> V_58 , V_67 , V_68 ) ;
F_42 ( V_28 ) ;
return ( V_12 ) ;
}
static long F_45 ( T_2 * V_28 , int V_69 , long V_5 , void * V_8 )
{
int * V_70 ;
long V_12 = 1 ;
T_3 * V_27 ;
char * * V_71 ;
V_27 = ( T_3 * ) V_28 -> V_8 ;
switch ( V_69 ) {
case V_72 :
V_12 = 0 ;
V_27 -> V_9 = V_10 ;
F_9 ( V_28 ) ;
F_7 ( V_27 -> V_19 ) ;
V_27 -> V_19 = NULL ;
V_28 -> V_7 = 0 ;
break;
case V_73 :
V_12 = ( long ) F_12 ( V_28 , V_27 ) ;
break;
case V_74 :
if ( V_8 != NULL ) {
if ( V_5 == 0 ) {
char * V_75 = V_27 -> V_18 ;
F_6 ( V_27 -> V_17 ) ;
V_27 -> V_17 = NULL ;
V_12 = F_46 ( V_8 ,
& V_27 -> V_17 ,
& V_27 -> V_18 ,
V_76 ) ;
if ( V_75 != V_27 -> V_18 )
F_6 ( V_75 ) ;
V_28 -> V_4 = 1 ;
} else if ( V_5 == 1 ) {
F_6 ( V_27 -> V_18 ) ;
V_27 -> V_18 = F_47 ( V_8 ) ;
V_28 -> V_4 = 1 ;
} else if ( V_5 == 2 ) {
V_27 -> V_50 |= V_77 ;
} else if ( V_5 == 3 ) {
F_8 ( V_27 -> V_24 ) ;
V_27 -> V_24 = ( T_2 * ) V_8 ;
} else if ( V_5 == 4 ) {
V_27 -> V_13 = * ( int * ) V_8 ;
}
} else {
if ( V_5 == 2 ) {
V_27 -> V_50 &= ~ V_77 ;
}
}
break;
case V_78 :
if ( V_5 != 0 )
V_27 -> V_62 |= V_77 ;
else
V_27 -> V_62 &= ~ V_77 ;
break;
case V_79 :
V_28 -> V_4 = 1 ;
V_28 -> V_5 = * ( ( int * ) V_8 ) ;
V_27 -> V_15 = V_28 -> V_5 ;
V_27 -> V_9 = V_56 ;
V_28 -> V_11 = ( int ) V_5 ;
V_28 -> V_4 = 1 ;
break;
case V_80 :
if ( V_28 -> V_4 ) {
V_70 = ( int * ) V_8 ;
if ( V_70 != NULL )
* V_70 = V_27 -> V_15 ;
V_12 = V_27 -> V_15 ;
} else
V_12 = - 1 ;
break;
case V_81 :
if ( V_28 -> V_4 ) {
if ( V_5 == 0 && V_8 != NULL ) {
V_71 = ( char * * ) V_8 ;
* V_71 = V_27 -> V_20 ;
} else if ( V_5 == 1 && V_8 != NULL ) {
V_71 = ( char * * ) V_8 ;
* V_71 = V_27 -> V_21 ;
} else if ( V_5 == 2 && V_8 != NULL ) {
V_71 = ( char * * ) V_8 ;
* V_71 = V_27 -> V_22 ;
} else if ( V_5 == 3 && V_8 != NULL ) {
V_71 = ( char * * ) V_8 ;
* V_71 = V_27 -> V_23 ;
} else if ( V_5 == 4 ) {
switch ( F_18 ( V_27 -> V_45 ) ) {
#ifdef F_15
case F_15 :
V_12 = V_37 ;
break;
#endif
case V_40 :
V_12 = V_39 ;
break;
case 0 :
V_12 = V_27 -> V_13 ;
break;
default:
V_12 = - 1 ;
break;
}
} else
V_12 = - 1 ;
} else
V_12 = - 1 ;
break;
case V_82 :
V_12 = V_28 -> V_11 ;
break;
case V_83 :
V_28 -> V_11 = ( int ) V_5 ;
break;
case V_84 :
case V_85 :
V_12 = 0 ;
break;
case V_86 :
break;
case V_87 :
V_27 -> V_50 = ( int ) V_5 ;
break;
case V_88 :
V_12 = ( long ) V_27 -> V_50 ;
break;
case V_89 :
break;
default:
V_12 = 0 ;
break;
}
return ( V_12 ) ;
}
static int F_48 ( T_2 * V_90 , const char * V_91 )
{
int V_92 , V_12 ;
V_92 = strlen ( V_91 ) ;
V_12 = F_43 ( V_90 , V_91 , V_92 ) ;
return ( V_12 ) ;
}
T_2 * F_49 ( const char * V_91 )
{
T_2 * V_12 ;
V_12 = F_50 ( F_1 () ) ;
if ( V_12 == NULL )
return ( NULL ) ;
if ( F_51 ( V_12 , V_91 ) )
return ( V_12 ) ;
F_8 ( V_12 ) ;
return ( NULL ) ;
}
