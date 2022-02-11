T_1 * F_1 ( void )
{
return ( & V_1 ) ;
}
static int F_2 ( int V_2 , unsigned char * V_3 ,
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
if ( ( V_5 -> V_25 == NULL ) && ( V_5 -> V_26 & V_27 ) )
{
if ( ( V_5 -> V_25 = F_14 () ) != NULL )
if ( ! F_15 ( V_5 -> V_25 , V_5 -> V_17 , V_15 ) )
goto V_16;
}
if ( ! V_5 -> V_28 -> V_29 ( & V_8 , & V_7 , V_5 -> V_30 , V_5 -> V_17 , V_15 ,
V_5 -> V_25 ) ) goto V_16;
V_10 = F_5 ( & V_8 ) ;
V_9 = F_16 ( & V_8 , & ( V_4 [ V_12 - V_10 ] ) ) ;
for ( V_11 = 0 ; V_11 < ( V_12 - V_9 ) ; V_11 ++ )
V_4 [ V_11 ] = 0 ;
V_13 = V_12 ;
V_16:
if ( V_15 != NULL ) F_17 ( V_15 ) ;
F_18 ( & V_7 ) ;
F_18 ( & V_8 ) ;
if ( V_14 != NULL )
{
memset ( V_14 , 0 , V_12 ) ;
F_19 ( V_14 ) ;
}
return ( V_13 ) ;
}
static int F_20 ( int V_2 , unsigned char * V_3 ,
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
F_7 ( V_31 , V_19 ) ;
goto V_16;
}
switch ( V_6 )
{
case V_20 :
V_9 = F_21 ( V_14 , V_12 , V_3 , V_2 ) ;
break;
case V_23 :
V_9 = F_12 ( V_14 , V_12 , V_3 , V_2 ) ;
break;
case V_22 :
default:
F_7 ( V_31 , V_24 ) ;
goto V_16;
}
if ( V_9 <= 0 ) goto V_16;
if ( F_13 ( V_14 , V_12 , & V_7 ) == NULL ) goto V_16;
if ( ( V_5 -> V_26 & V_32 ) && ( V_5 -> V_33 == NULL ) )
F_22 ( V_5 , V_15 ) ;
if ( V_5 -> V_26 & V_32 )
if ( ! F_23 ( & V_7 , V_5 -> V_33 , V_15 ) ) goto V_16;
if ( ( V_5 -> V_26 & V_34 ) ||
( ( V_5 -> V_35 != NULL ) &&
( V_5 -> V_36 != NULL ) &&
( V_5 -> V_37 != NULL ) &&
( V_5 -> V_38 != NULL ) &&
( V_5 -> V_39 != NULL ) ) )
{ if ( ! V_5 -> V_28 -> V_40 ( & V_8 , & V_7 , V_5 ) ) goto V_16; }
else
{
if ( ! V_5 -> V_28 -> V_29 ( & V_8 , & V_7 , V_5 -> V_41 , V_5 -> V_17 , V_15 , NULL ) ) goto V_16;
}
if ( V_5 -> V_26 & V_32 )
if ( ! F_24 ( & V_8 , V_5 -> V_33 , V_15 ) ) goto V_16;
V_10 = F_5 ( & V_8 ) ;
V_9 = F_16 ( & V_8 , & ( V_4 [ V_12 - V_10 ] ) ) ;
for ( V_11 = 0 ; V_11 < ( V_12 - V_9 ) ; V_11 ++ )
V_4 [ V_11 ] = 0 ;
V_13 = V_12 ;
V_16:
if ( V_15 != NULL ) F_17 ( V_15 ) ;
F_18 ( & V_8 ) ;
F_18 ( & V_7 ) ;
if ( V_14 != NULL )
{
memset ( V_14 , 0 , V_12 ) ;
F_19 ( V_14 ) ;
}
return ( V_13 ) ;
}
static int F_25 ( int V_2 , unsigned char * V_3 ,
unsigned char * V_4 , T_2 * V_5 , int V_6 )
{
T_3 V_7 , V_8 ;
int V_10 , V_12 = 0 , V_13 = - 1 ;
unsigned char * V_35 ;
unsigned char * V_14 = NULL ;
T_4 * V_15 = NULL ;
F_3 ( & V_7 ) ;
F_3 ( & V_8 ) ;
V_15 = F_4 () ;
if ( V_15 == NULL ) goto V_16;
V_12 = F_5 ( V_5 -> V_17 ) ;
if ( ( V_14 = ( unsigned char * ) F_6 ( V_12 ) ) == NULL )
{
F_7 ( V_42 , V_19 ) ;
goto V_16;
}
if ( V_2 > V_12 )
{
F_7 ( V_42 , V_43 ) ;
goto V_16;
}
if ( F_13 ( V_3 , ( int ) V_2 , & V_7 ) == NULL ) goto V_16;
if ( ( V_5 -> V_26 & V_32 ) && ( V_5 -> V_33 == NULL ) )
F_22 ( V_5 , V_15 ) ;
if ( V_5 -> V_26 & V_32 )
if ( ! F_23 ( & V_7 , V_5 -> V_33 , V_15 ) ) goto V_16;
if ( ( V_5 -> V_26 & V_34 ) ||
( ( V_5 -> V_35 != NULL ) &&
( V_5 -> V_36 != NULL ) &&
( V_5 -> V_37 != NULL ) &&
( V_5 -> V_38 != NULL ) &&
( V_5 -> V_39 != NULL ) ) )
{ if ( ! V_5 -> V_28 -> V_40 ( & V_8 , & V_7 , V_5 ) ) goto V_16; }
else
{
if ( ! V_5 -> V_28 -> V_29 ( & V_8 , & V_7 , V_5 -> V_41 , V_5 -> V_17 , V_15 , NULL ) )
goto V_16;
}
if ( V_5 -> V_26 & V_32 )
if ( ! F_24 ( & V_8 , V_5 -> V_33 , V_15 ) ) goto V_16;
V_35 = V_14 ;
V_10 = F_16 ( & V_8 , V_35 ) ;
switch ( V_6 )
{
case V_20 :
V_13 = F_26 ( V_4 , V_12 , V_14 , V_10 , V_12 ) ;
break;
#ifndef F_9
case V_21 :
V_13 = F_27 ( V_4 , V_12 , V_14 , V_10 , V_12 , NULL , 0 ) ;
break;
#endif
case V_22 :
V_13 = F_28 ( V_4 , V_12 , V_14 , V_10 , V_12 ) ;
break;
case V_23 :
V_13 = F_29 ( V_4 , V_12 , V_14 , V_10 , V_12 ) ;
break;
default:
F_7 ( V_42 , V_24 ) ;
goto V_16;
}
if ( V_13 < 0 )
F_7 ( V_42 , V_44 ) ;
V_16:
if ( V_15 != NULL ) F_17 ( V_15 ) ;
F_18 ( & V_7 ) ;
F_18 ( & V_8 ) ;
if ( V_14 != NULL )
{
memset ( V_14 , 0 , V_12 ) ;
F_19 ( V_14 ) ;
}
return ( V_13 ) ;
}
static int F_30 ( int V_2 , unsigned char * V_3 ,
unsigned char * V_4 , T_2 * V_5 , int V_6 )
{
T_3 V_7 , V_8 ;
int V_9 , V_12 = 0 , V_13 = - 1 ;
unsigned char * V_35 ;
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
F_7 ( V_45 , V_19 ) ;
goto V_16;
}
if ( V_2 > V_12 )
{
F_7 ( V_45 , V_43 ) ;
goto V_16;
}
if ( F_13 ( V_3 , V_2 , & V_7 ) == NULL ) goto V_16;
if ( ( V_5 -> V_25 == NULL ) && ( V_5 -> V_26 & V_27 ) )
{
if ( ( V_5 -> V_25 = F_14 () ) != NULL )
if ( ! F_15 ( V_5 -> V_25 , V_5 -> V_17 , V_15 ) )
goto V_16;
}
if ( ! V_5 -> V_28 -> V_29 ( & V_8 , & V_7 , V_5 -> V_30 , V_5 -> V_17 , V_15 ,
V_5 -> V_25 ) ) goto V_16;
V_35 = V_14 ;
V_9 = F_16 ( & V_8 , V_35 ) ;
switch ( V_6 )
{
case V_20 :
V_13 = F_31 ( V_4 , V_12 , V_14 , V_9 , V_12 ) ;
break;
case V_23 :
V_13 = F_29 ( V_4 , V_12 , V_14 , V_9 , V_12 ) ;
break;
default:
F_7 ( V_45 , V_24 ) ;
goto V_16;
}
if ( V_13 < 0 )
F_7 ( V_45 , V_44 ) ;
V_16:
if ( V_15 != NULL ) F_17 ( V_15 ) ;
F_18 ( & V_7 ) ;
F_18 ( & V_8 ) ;
if ( V_14 != NULL )
{
memset ( V_14 , 0 , V_12 ) ;
F_19 ( V_14 ) ;
}
return ( V_13 ) ;
}
static int F_32 ( T_3 * V_46 , T_3 * V_47 , T_2 * V_5 )
{
T_3 V_48 , V_49 ;
int V_8 = 0 ;
T_4 * V_15 ;
if ( ( V_15 = F_4 () ) == NULL ) goto V_16;
F_3 ( & V_49 ) ;
F_3 ( & V_48 ) ;
if ( V_5 -> V_26 & V_50 )
{
if ( V_5 -> V_51 == NULL )
{
if ( ( V_5 -> V_51 = F_14 () ) != NULL )
if ( ! F_15 ( V_5 -> V_51 , V_5 -> V_35 ,
V_15 ) )
goto V_16;
}
if ( V_5 -> V_52 == NULL )
{
if ( ( V_5 -> V_52 = F_14 () ) != NULL )
if ( ! F_15 ( V_5 -> V_52 , V_5 -> V_36 ,
V_15 ) )
goto V_16;
}
}
if ( ! F_33 ( & V_48 , V_47 , V_5 -> V_36 , V_15 ) ) goto V_16;
if ( ! V_5 -> V_28 -> V_29 ( & V_49 , & V_48 , V_5 -> V_38 , V_5 -> V_36 , V_15 ,
V_5 -> V_52 ) ) goto V_16;
if ( ! F_33 ( & V_48 , V_47 , V_5 -> V_35 , V_15 ) ) goto V_16;
if ( ! V_5 -> V_28 -> V_29 ( V_46 , & V_48 , V_5 -> V_37 , V_5 -> V_35 , V_15 ,
V_5 -> V_51 ) ) goto V_16;
if ( ! F_34 ( V_46 , V_46 , & V_49 ) ) goto V_16;
if ( V_46 -> V_53 )
if ( ! F_35 ( V_46 , V_46 , V_5 -> V_35 ) ) goto V_16;
if ( ! F_36 ( & V_48 , V_46 , V_5 -> V_39 , V_15 ) ) goto V_16;
if ( ! F_33 ( V_46 , & V_48 , V_5 -> V_35 , V_15 ) ) goto V_16;
if ( V_46 -> V_53 )
if ( ! F_35 ( V_46 , V_46 , V_5 -> V_35 ) ) goto V_16;
if ( ! F_36 ( & V_48 , V_46 , V_5 -> V_36 , V_15 ) ) goto V_16;
if ( ! F_35 ( V_46 , & V_48 , & V_49 ) ) goto V_16;
V_8 = 1 ;
V_16:
F_18 ( & V_49 ) ;
F_18 ( & V_48 ) ;
F_17 ( V_15 ) ;
return ( V_8 ) ;
}
static int F_37 ( T_2 * V_5 )
{
V_5 -> V_26 |= V_27 | V_50 ;
return ( 1 ) ;
}
static int F_38 ( T_2 * V_5 )
{
if ( V_5 -> V_25 != NULL )
F_39 ( V_5 -> V_25 ) ;
if ( V_5 -> V_51 != NULL )
F_39 ( V_5 -> V_51 ) ;
if ( V_5 -> V_52 != NULL )
F_39 ( V_5 -> V_52 ) ;
return ( 1 ) ;
}
