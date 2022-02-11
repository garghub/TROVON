const T_1 * F_1 ( void )
{
return ( & V_1 ) ;
}
static int F_2 ( int V_2 , const unsigned char * V_3 ,
unsigned char * V_4 , T_2 * V_5 , int V_6 )
{
T_3 V_7 , V_8 ;
int V_9 , V_10 , V_11 , V_12 = 0 , V_13 = - 1 ;
unsigned char * V_14 = NULL ;
T_4 * V_15 = NULL ;
F_3 ( & V_7 ) ;
F_3 ( & V_8 ) ;
if ( ( V_15 = F_4 () ) == NULL ) goto V_16;
V_12 = F_5 ( V_5 -> V_17 ) ;
if ( ( V_14 = ( unsigned char * ) F_6 ( V_12 ) ) == NULL )
{
F_7 ( V_18 , V_19 ) ;
goto V_16;
}
switch ( V_6 )
{
case V_20 :
V_9 = F_8 ( V_14 , V_12 , V_3 , V_2 ) ;
break;
#ifndef F_9
case V_21 :
V_9 = F_10 ( V_14 , V_12 , V_3 , V_2 , NULL , 0 ) ;
break;
#endif
case V_22 :
V_9 = F_11 ( V_14 , V_12 , V_3 , V_2 ) ;
break;
case V_23 :
V_9 = F_12 ( V_14 , V_12 , V_3 , V_2 ) ;
break;
default:
F_7 ( V_18 , V_24 ) ;
goto V_16;
}
if ( V_9 <= 0 ) goto V_16;
if ( F_13 ( V_14 , V_12 , & V_7 ) == NULL ) goto V_16;
if ( F_14 ( & V_7 , V_5 -> V_17 ) >= 0 )
{
F_7 ( V_18 , V_25 ) ;
goto V_16;
}
if ( ( V_5 -> V_26 == NULL ) && ( V_5 -> V_27 & V_28 ) )
{
T_5 * V_29 ;
if ( ( V_29 = F_15 () ) == NULL )
goto V_16;
if ( ! F_16 ( V_29 , V_5 -> V_17 , V_15 ) )
{
F_17 ( V_29 ) ;
goto V_16;
}
if ( V_5 -> V_26 == NULL )
{
F_18 ( V_30 ) ;
if ( V_5 -> V_26 == NULL )
{
V_5 -> V_26 = V_29 ;
V_29 = NULL ;
}
F_19 ( V_30 ) ;
}
if ( V_29 )
F_17 ( V_29 ) ;
}
if ( ! V_5 -> V_31 -> V_32 ( & V_8 , & V_7 , V_5 -> V_33 , V_5 -> V_17 , V_15 ,
V_5 -> V_26 ) ) goto V_16;
V_10 = F_5 ( & V_8 ) ;
V_9 = F_20 ( & V_8 , & ( V_4 [ V_12 - V_10 ] ) ) ;
for ( V_11 = 0 ; V_11 < ( V_12 - V_9 ) ; V_11 ++ )
V_4 [ V_11 ] = 0 ;
V_13 = V_12 ;
V_16:
if ( V_15 != NULL ) F_21 ( V_15 ) ;
F_22 ( & V_7 ) ;
F_22 ( & V_8 ) ;
if ( V_14 != NULL )
{
F_23 ( V_14 , V_12 ) ;
F_24 ( V_14 ) ;
}
return ( V_13 ) ;
}
static int F_25 ( int V_2 , const unsigned char * V_3 ,
unsigned char * V_4 , T_2 * V_5 , int V_6 )
{
T_3 V_7 , V_8 ;
int V_9 , V_10 , V_11 , V_12 = 0 , V_13 = - 1 ;
unsigned char * V_14 = NULL ;
T_4 * V_15 = NULL ;
F_3 ( & V_7 ) ;
F_3 ( & V_8 ) ;
if ( ( V_15 = F_4 () ) == NULL ) goto V_16;
V_12 = F_5 ( V_5 -> V_17 ) ;
if ( ( V_14 = ( unsigned char * ) F_6 ( V_12 ) ) == NULL )
{
F_7 ( V_34 , V_19 ) ;
goto V_16;
}
switch ( V_6 )
{
case V_20 :
V_9 = F_26 ( V_14 , V_12 , V_3 , V_2 ) ;
break;
case V_23 :
V_9 = F_12 ( V_14 , V_12 , V_3 , V_2 ) ;
break;
case V_22 :
default:
F_7 ( V_34 , V_24 ) ;
goto V_16;
}
if ( V_9 <= 0 ) goto V_16;
if ( F_13 ( V_14 , V_12 , & V_7 ) == NULL ) goto V_16;
if ( F_14 ( & V_7 , V_5 -> V_17 ) >= 0 )
{
F_7 ( V_34 , V_25 ) ;
goto V_16;
}
if ( ( V_5 -> V_27 & V_35 ) && ( V_5 -> V_36 == NULL ) )
F_27 ( V_5 , V_15 ) ;
if ( V_5 -> V_27 & V_35 )
if ( ! F_28 ( & V_7 , V_5 -> V_36 , V_15 ) ) goto V_16;
if ( ( V_5 -> V_27 & V_37 ) ||
( ( V_5 -> V_38 != NULL ) &&
( V_5 -> V_39 != NULL ) &&
( V_5 -> V_40 != NULL ) &&
( V_5 -> V_41 != NULL ) &&
( V_5 -> V_42 != NULL ) ) )
{ if ( ! V_5 -> V_31 -> V_43 ( & V_8 , & V_7 , V_5 ) ) goto V_16; }
else
{
if ( ! V_5 -> V_31 -> V_32 ( & V_8 , & V_7 , V_5 -> V_44 , V_5 -> V_17 , V_15 , NULL ) ) goto V_16;
}
if ( V_5 -> V_27 & V_35 )
if ( ! F_29 ( & V_8 , V_5 -> V_36 , V_15 ) ) goto V_16;
V_10 = F_5 ( & V_8 ) ;
V_9 = F_20 ( & V_8 , & ( V_4 [ V_12 - V_10 ] ) ) ;
for ( V_11 = 0 ; V_11 < ( V_12 - V_9 ) ; V_11 ++ )
V_4 [ V_11 ] = 0 ;
V_13 = V_12 ;
V_16:
if ( V_15 != NULL ) F_21 ( V_15 ) ;
F_22 ( & V_8 ) ;
F_22 ( & V_7 ) ;
if ( V_14 != NULL )
{
F_23 ( V_14 , V_12 ) ;
F_24 ( V_14 ) ;
}
return ( V_13 ) ;
}
static int F_30 ( int V_2 , const unsigned char * V_3 ,
unsigned char * V_4 , T_2 * V_5 , int V_6 )
{
T_3 V_7 , V_8 ;
int V_10 , V_12 = 0 , V_13 = - 1 ;
unsigned char * V_38 ;
unsigned char * V_14 = NULL ;
T_4 * V_15 = NULL ;
F_3 ( & V_7 ) ;
F_3 ( & V_8 ) ;
V_15 = F_4 () ;
if ( V_15 == NULL ) goto V_16;
V_12 = F_5 ( V_5 -> V_17 ) ;
if ( ( V_14 = ( unsigned char * ) F_6 ( V_12 ) ) == NULL )
{
F_7 ( V_45 , V_19 ) ;
goto V_16;
}
if ( V_2 > V_12 )
{
F_7 ( V_45 , V_46 ) ;
goto V_16;
}
if ( F_13 ( V_3 , ( int ) V_2 , & V_7 ) == NULL ) goto V_16;
if ( F_14 ( & V_7 , V_5 -> V_17 ) >= 0 )
{
F_7 ( V_45 , V_25 ) ;
goto V_16;
}
if ( ( V_5 -> V_27 & V_35 ) && ( V_5 -> V_36 == NULL ) )
F_27 ( V_5 , V_15 ) ;
if ( V_5 -> V_27 & V_35 )
if ( ! F_28 ( & V_7 , V_5 -> V_36 , V_15 ) ) goto V_16;
if ( ( V_5 -> V_27 & V_37 ) ||
( ( V_5 -> V_38 != NULL ) &&
( V_5 -> V_39 != NULL ) &&
( V_5 -> V_40 != NULL ) &&
( V_5 -> V_41 != NULL ) &&
( V_5 -> V_42 != NULL ) ) )
{ if ( ! V_5 -> V_31 -> V_43 ( & V_8 , & V_7 , V_5 ) ) goto V_16; }
else
{
if ( ! V_5 -> V_31 -> V_32 ( & V_8 , & V_7 , V_5 -> V_44 , V_5 -> V_17 , V_15 , NULL ) )
goto V_16;
}
if ( V_5 -> V_27 & V_35 )
if ( ! F_29 ( & V_8 , V_5 -> V_36 , V_15 ) ) goto V_16;
V_38 = V_14 ;
V_10 = F_20 ( & V_8 , V_38 ) ;
switch ( V_6 )
{
case V_20 :
V_13 = F_31 ( V_4 , V_12 , V_14 , V_10 , V_12 ) ;
break;
#ifndef F_9
case V_21 :
V_13 = F_32 ( V_4 , V_12 , V_14 , V_10 , V_12 , NULL , 0 ) ;
break;
#endif
case V_22 :
V_13 = F_33 ( V_4 , V_12 , V_14 , V_10 , V_12 ) ;
break;
case V_23 :
V_13 = F_34 ( V_4 , V_12 , V_14 , V_10 , V_12 ) ;
break;
default:
F_7 ( V_45 , V_24 ) ;
goto V_16;
}
if ( V_13 < 0 )
F_7 ( V_45 , V_47 ) ;
V_16:
if ( V_15 != NULL ) F_21 ( V_15 ) ;
F_22 ( & V_7 ) ;
F_22 ( & V_8 ) ;
if ( V_14 != NULL )
{
F_23 ( V_14 , V_12 ) ;
F_24 ( V_14 ) ;
}
return ( V_13 ) ;
}
static int F_35 ( int V_2 , const unsigned char * V_3 ,
unsigned char * V_4 , T_2 * V_5 , int V_6 )
{
T_3 V_7 , V_8 ;
int V_9 , V_12 = 0 , V_13 = - 1 ;
unsigned char * V_38 ;
unsigned char * V_14 = NULL ;
T_4 * V_15 = NULL ;
F_3 ( & V_7 ) ;
F_3 ( & V_8 ) ;
V_15 = F_4 () ;
if ( V_15 == NULL ) goto V_16;
V_12 = F_5 ( V_5 -> V_17 ) ;
V_14 = ( unsigned char * ) F_6 ( V_12 ) ;
if ( V_14 == NULL )
{
F_7 ( V_48 , V_19 ) ;
goto V_16;
}
if ( V_2 > V_12 )
{
F_7 ( V_48 , V_46 ) ;
goto V_16;
}
if ( F_13 ( V_3 , V_2 , & V_7 ) == NULL ) goto V_16;
if ( F_14 ( & V_7 , V_5 -> V_17 ) >= 0 )
{
F_7 ( V_48 , V_25 ) ;
goto V_16;
}
if ( ( V_5 -> V_26 == NULL ) && ( V_5 -> V_27 & V_28 ) )
{
T_5 * V_29 ;
if ( ( V_29 = F_15 () ) == NULL )
goto V_16;
if ( ! F_16 ( V_29 , V_5 -> V_17 , V_15 ) )
{
F_17 ( V_29 ) ;
goto V_16;
}
if ( V_5 -> V_26 == NULL )
{
F_18 ( V_30 ) ;
if ( V_5 -> V_26 == NULL )
{
V_5 -> V_26 = V_29 ;
V_29 = NULL ;
}
F_19 ( V_30 ) ;
}
if ( V_29 )
F_17 ( V_29 ) ;
}
if ( ! V_5 -> V_31 -> V_32 ( & V_8 , & V_7 , V_5 -> V_33 , V_5 -> V_17 , V_15 ,
V_5 -> V_26 ) ) goto V_16;
V_38 = V_14 ;
V_9 = F_20 ( & V_8 , V_38 ) ;
switch ( V_6 )
{
case V_20 :
V_13 = F_36 ( V_4 , V_12 , V_14 , V_9 , V_12 ) ;
break;
case V_23 :
V_13 = F_34 ( V_4 , V_12 , V_14 , V_9 , V_12 ) ;
break;
default:
F_7 ( V_48 , V_24 ) ;
goto V_16;
}
if ( V_13 < 0 )
F_7 ( V_48 , V_47 ) ;
V_16:
if ( V_15 != NULL ) F_21 ( V_15 ) ;
F_22 ( & V_7 ) ;
F_22 ( & V_8 ) ;
if ( V_14 != NULL )
{
F_23 ( V_14 , V_12 ) ;
F_24 ( V_14 ) ;
}
return ( V_13 ) ;
}
static int F_37 ( T_3 * V_49 , const T_3 * V_50 , T_2 * V_5 )
{
T_3 V_51 , V_52 , V_53 ;
int V_8 = 0 ;
T_4 * V_15 ;
F_3 ( & V_52 ) ;
F_3 ( & V_51 ) ;
F_3 ( & V_53 ) ;
if ( ( V_15 = F_4 () ) == NULL ) goto V_16;
if ( V_5 -> V_27 & V_54 )
{
if ( V_5 -> V_55 == NULL )
{
T_5 * V_29 ;
if ( ( V_29 = F_15 () ) == NULL )
goto V_16;
if ( ! F_16 ( V_29 , V_5 -> V_38 , V_15 ) )
{
F_17 ( V_29 ) ;
goto V_16;
}
if ( V_5 -> V_55 == NULL )
{
F_18 ( V_30 ) ;
if ( V_5 -> V_55 == NULL )
{
V_5 -> V_55 = V_29 ;
V_29 = NULL ;
}
F_19 ( V_30 ) ;
}
if ( V_29 )
F_17 ( V_29 ) ;
}
if ( V_5 -> V_56 == NULL )
{
T_5 * V_29 ;
if ( ( V_29 = F_15 () ) == NULL )
goto V_16;
if ( ! F_16 ( V_29 , V_5 -> V_39 , V_15 ) )
{
F_17 ( V_29 ) ;
goto V_16;
}
if ( V_5 -> V_56 == NULL )
{
F_18 ( V_30 ) ;
if ( V_5 -> V_56 == NULL )
{
V_5 -> V_56 = V_29 ;
V_29 = NULL ;
}
F_19 ( V_30 ) ;
}
if ( V_29 )
F_17 ( V_29 ) ;
}
}
if ( ! F_38 ( & V_51 , V_50 , V_5 -> V_39 , V_15 ) ) goto V_16;
if ( ! V_5 -> V_31 -> V_32 ( & V_52 , & V_51 , V_5 -> V_41 , V_5 -> V_39 , V_15 ,
V_5 -> V_56 ) ) goto V_16;
if ( ! F_38 ( & V_51 , V_50 , V_5 -> V_38 , V_15 ) ) goto V_16;
if ( ! V_5 -> V_31 -> V_32 ( V_49 , & V_51 , V_5 -> V_40 , V_5 -> V_38 , V_15 ,
V_5 -> V_55 ) ) goto V_16;
if ( ! F_39 ( V_49 , V_49 , & V_52 ) ) goto V_16;
if ( V_49 -> V_57 )
if ( ! F_40 ( V_49 , V_49 , V_5 -> V_38 ) ) goto V_16;
if ( ! F_41 ( & V_51 , V_49 , V_5 -> V_42 , V_15 ) ) goto V_16;
if ( ! F_38 ( V_49 , & V_51 , V_5 -> V_38 , V_15 ) ) goto V_16;
if ( V_49 -> V_57 )
if ( ! F_40 ( V_49 , V_49 , V_5 -> V_38 ) ) goto V_16;
if ( ! F_41 ( & V_51 , V_49 , V_5 -> V_39 , V_15 ) ) goto V_16;
if ( ! F_40 ( V_49 , & V_51 , & V_52 ) ) goto V_16;
if ( V_5 -> V_33 && V_5 -> V_17 )
{
if ( ! V_5 -> V_31 -> V_32 ( & V_53 , V_49 , V_5 -> V_33 , V_5 -> V_17 , V_15 , NULL ) ) goto V_16;
if ( ! F_39 ( & V_53 , & V_53 , V_50 ) ) goto V_16;
if ( ! F_38 ( & V_53 , & V_53 , V_5 -> V_17 , V_15 ) ) goto V_16;
if ( V_53 . V_57 )
if ( ! F_40 ( & V_53 , & V_53 , V_5 -> V_17 ) ) goto V_16;
if ( ! F_42 ( & V_53 ) )
if ( ! V_5 -> V_31 -> V_32 ( V_49 , V_50 , V_5 -> V_44 , V_5 -> V_17 , V_15 , NULL ) ) goto V_16;
}
V_8 = 1 ;
V_16:
F_22 ( & V_52 ) ;
F_22 ( & V_51 ) ;
F_22 ( & V_53 ) ;
F_21 ( V_15 ) ;
return ( V_8 ) ;
}
static int F_43 ( T_2 * V_5 )
{
V_5 -> V_27 |= V_28 | V_54 ;
return ( 1 ) ;
}
static int F_44 ( T_2 * V_5 )
{
if ( V_5 -> V_26 != NULL )
F_17 ( V_5 -> V_26 ) ;
if ( V_5 -> V_55 != NULL )
F_17 ( V_5 -> V_55 ) ;
if ( V_5 -> V_56 != NULL )
F_17 ( V_5 -> V_56 ) ;
return ( 1 ) ;
}
