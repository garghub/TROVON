T_1 * F_1 ( void )
{
return ( & V_1 ) ;
}
static int F_2 ( T_2 * V_2 )
{
T_3 * V_3 ;
V_2 -> V_4 = 0 ;
V_2 -> V_5 = V_6 ;
V_2 -> V_7 = 0 ;
if ( ( V_3 = F_3 () ) == NULL )
return ( 0 ) ;
V_2 -> V_8 = ( char * ) V_3 ;
V_3 -> V_9 = V_10 ;
V_2 -> V_11 = 1 ;
return ( 1 ) ;
}
T_3 * F_3 ( void )
{
T_3 * V_12 ;
if ( ( V_12 = ( T_3 * ) F_4 ( sizeof( T_3 ) ) ) == NULL )
return ( NULL ) ;
memset ( V_12 , 0 , sizeof( T_3 ) ) ;
V_12 -> V_13 = V_6 ;
V_12 -> V_14 = V_15 ;
return ( V_12 ) ;
}
void F_5 ( T_3 * V_16 )
{
if( V_16 == NULL )
return;
if ( V_16 -> V_17 != NULL ) F_6 ( V_16 -> V_17 ) ;
if ( V_16 -> V_18 != NULL ) F_6 ( V_16 -> V_18 ) ;
if ( V_16 -> V_19 != NULL ) F_7 ( V_16 -> V_19 ) ;
F_6 ( V_16 ) ;
}
static void F_8 ( T_2 * V_20 )
{
T_3 * V_21 ;
V_21 = ( T_3 * ) V_20 -> V_8 ;
if ( V_21 -> V_13 != V_6 )
{
V_11 ( V_21 -> V_13 , 2 ) ;
F_9 ( V_21 -> V_13 ) ;
V_21 -> V_13 = V_6 ;
V_20 -> V_5 = V_6 ;
}
}
static int F_10 ( T_2 * V_16 )
{
T_3 * V_22 ;
if ( V_16 == NULL ) return ( 0 ) ;
V_22 = ( T_3 * ) V_16 -> V_8 ;
if ( V_16 -> V_11 )
{
F_8 ( V_16 ) ;
F_5 ( V_22 ) ;
V_16 -> V_8 = NULL ;
V_16 -> V_7 = 0 ;
V_16 -> V_4 = 0 ;
}
return ( 1 ) ;
}
static int F_11 ( T_2 * V_23 , T_3 * V_21 )
{
T_2 * V_20 = NULL , * V_24 ;
int V_25 = - 1 ;
int V_26 ;
V_27:
switch ( V_21 -> V_9 )
{
case V_10 :
if ( V_21 -> V_17 == NULL )
{
F_12 ( V_28 , V_29 ) ;
return ( - 1 ) ;
}
V_25 = F_13 ( V_21 -> V_17 , V_21 -> V_14 ) ;
if ( V_25 == V_6 )
return ( - 1 ) ;
if ( V_21 -> V_30 )
{
if ( ! F_14 ( V_25 , 1 ) )
{
F_9 ( V_25 ) ;
F_12 ( V_28 , V_31 ) ;
return ( - 1 ) ;
}
}
V_21 -> V_13 = V_25 ;
V_23 -> V_5 = V_25 ;
V_21 -> V_9 = V_32 ;
return ( 1 ) ;
case V_32 :
if ( V_23 -> V_33 != NULL )
{
V_21 -> V_9 = V_34 ;
goto V_27;
}
V_26 = F_15 ( V_21 -> V_13 , & ( V_21 -> V_18 ) ) ;
if ( V_26 < 0 ) return ( V_26 ) ;
V_20 = F_16 ( V_26 , V_35 ) ;
if ( V_20 == NULL ) goto V_36;
F_17 ( V_20 , F_18 ( V_23 ) ) ;
F_19 ( V_20 , F_20 ( V_23 ) ) ;
if ( V_21 -> V_37 )
{
if ( ! F_14 ( V_26 , 1 ) )
{
F_12 ( V_28 , V_38 ) ;
goto V_36;
}
}
if ( V_21 -> V_19 != NULL )
{
if ( ( V_24 = F_21 ( V_21 -> V_19 ) ) == NULL )
goto V_36;
if ( ! F_22 ( V_24 , V_20 ) ) goto V_36;
V_20 = V_24 ;
}
if ( F_22 ( V_23 , V_20 ) == NULL ) goto V_36;
V_21 -> V_9 = V_34 ;
return ( 1 ) ;
V_36:
if ( V_20 != NULL )
F_7 ( V_20 ) ;
else if ( V_25 >= 0 )
F_9 ( V_25 ) ;
return ( 0 ) ;
case V_34 :
if ( V_23 -> V_33 == NULL )
{
V_21 -> V_9 = V_32 ;
goto V_27;
}
return ( 1 ) ;
default:
return ( 0 ) ;
}
}
static int F_23 ( T_2 * V_23 , char * V_39 , int V_40 )
{
int V_12 = 0 ;
T_3 * V_22 ;
F_24 ( V_23 ) ;
V_22 = ( T_3 * ) V_23 -> V_8 ;
while ( V_23 -> V_33 == NULL )
{
V_12 = F_11 ( V_23 , V_22 ) ;
if ( V_12 <= 0 ) return ( V_12 ) ;
}
V_12 = F_25 ( V_23 -> V_33 , V_39 , V_40 ) ;
F_26 ( V_23 ) ;
return ( V_12 ) ;
}
static int F_27 ( T_2 * V_23 , const char * V_41 , int V_42 )
{
int V_12 ;
T_3 * V_22 ;
F_24 ( V_23 ) ;
V_22 = ( T_3 * ) V_23 -> V_8 ;
while ( V_23 -> V_33 == NULL )
{
V_12 = F_11 ( V_23 , V_22 ) ;
if ( V_12 <= 0 ) return ( V_12 ) ;
}
V_12 = F_28 ( V_23 -> V_33 , V_41 , V_42 ) ;
F_26 ( V_23 ) ;
return ( V_12 ) ;
}
static long F_29 ( T_2 * V_23 , int V_43 , long V_5 , void * V_8 )
{
T_2 * V_24 ;
int * V_44 ;
long V_12 = 1 ;
T_3 * V_22 ;
char * * V_45 ;
V_22 = ( T_3 * ) V_23 -> V_8 ;
switch ( V_43 )
{
case V_46 :
V_12 = 0 ;
V_22 -> V_9 = V_10 ;
F_8 ( V_23 ) ;
V_23 -> V_7 = 0 ;
break;
case V_47 :
V_12 = ( long ) F_11 ( V_23 , V_22 ) ;
break;
case V_48 :
if ( V_8 != NULL )
{
if ( V_5 == 0 )
{
V_23 -> V_4 = 1 ;
if ( V_22 -> V_17 != NULL )
F_6 ( V_22 -> V_17 ) ;
V_22 -> V_17 = F_30 ( V_8 ) ;
}
else if ( V_5 == 1 )
{
V_22 -> V_30 = ( V_8 != NULL ) ;
}
else if ( V_5 == 2 )
{
if ( V_22 -> V_19 != NULL )
F_7 ( V_22 -> V_19 ) ;
V_22 -> V_19 = ( T_2 * ) V_8 ;
}
}
break;
case V_49 :
V_22 -> V_37 = ( int ) V_5 ;
break;
case V_50 :
V_23 -> V_4 = 1 ;
V_23 -> V_5 = * ( ( int * ) V_8 ) ;
V_22 -> V_13 = V_23 -> V_5 ;
V_22 -> V_9 = V_32 ;
V_23 -> V_11 = ( int ) V_5 ;
V_23 -> V_4 = 1 ;
break;
case V_51 :
if ( V_23 -> V_4 )
{
V_44 = ( int * ) V_8 ;
if ( V_44 != NULL )
* V_44 = V_22 -> V_13 ;
V_12 = V_22 -> V_13 ;
}
else
V_12 = - 1 ;
break;
case V_52 :
if ( V_23 -> V_4 )
{
if ( V_8 != NULL )
{
V_45 = ( char * * ) V_8 ;
* V_45 = V_22 -> V_17 ;
}
else
V_12 = - 1 ;
}
else
V_12 = - 1 ;
break;
case V_53 :
V_12 = V_23 -> V_11 ;
break;
case V_54 :
V_23 -> V_11 = ( int ) V_5 ;
break;
case V_55 :
case V_56 :
V_12 = 0 ;
break;
case V_57 :
break;
case V_58 :
V_22 -> V_14 = ( int ) V_5 ;
break;
case V_59 :
V_12 = ( long ) V_22 -> V_14 ;
break;
case V_60 :
V_24 = ( T_2 * ) V_8 ;
break;
default:
V_12 = 0 ;
break;
}
return ( V_12 ) ;
}
static int F_31 ( T_2 * V_61 , const char * V_62 )
{
int V_63 , V_12 ;
V_63 = strlen ( V_62 ) ;
V_12 = F_27 ( V_61 , V_62 , V_63 ) ;
return ( V_12 ) ;
}
T_2 * F_32 ( char * V_62 )
{
T_2 * V_12 ;
V_12 = F_33 ( F_1 () ) ;
if ( V_12 == NULL ) return ( NULL ) ;
if ( F_34 ( V_12 , V_62 ) )
return ( V_12 ) ;
else
{
F_7 ( V_12 ) ;
return ( NULL ) ;
}
}
