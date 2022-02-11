T_1 * F_1 ( const char * V_1 , const char * V_2 )
{
T_1 * V_3 ;
T_2 * V_4 ;
if ( ( V_4 = fopen ( V_1 , V_2 ) ) == NULL )
{
F_2 ( V_5 , F_3 () ) ;
F_4 ( 5 , L_1 , V_1 , L_2 , V_2 , L_3 ) ;
F_5 ( V_6 , V_7 ) ;
return ( NULL ) ;
}
if ( ( V_3 = F_6 ( F_7 () ) ) == NULL )
return ( NULL ) ;
F_8 ( V_3 , V_4 , V_8 ) ;
return ( V_3 ) ;
}
T_1 * F_9 ( T_2 * V_9 , int V_10 )
{
T_1 * V_3 ;
if ( ( V_3 = F_6 ( F_10 () ) ) == NULL )
return ( NULL ) ;
F_8 ( V_3 , V_9 , V_10 ) ;
return ( V_3 ) ;
}
T_3 * F_10 ( void )
{
return ( & V_11 ) ;
}
static int T_4 F_11 ( T_1 * V_12 )
{
V_12 -> V_13 = 0 ;
V_12 -> V_14 = 0 ;
V_12 -> V_15 = NULL ;
return ( 1 ) ;
}
static int T_4 F_12 ( T_1 * V_16 )
{
if ( V_16 == NULL ) return ( 0 ) ;
if ( V_16 -> V_17 )
{
if ( ( V_16 -> V_13 ) && ( V_16 -> V_15 != NULL ) )
{
fclose ( ( T_2 * ) V_16 -> V_15 ) ;
V_16 -> V_15 = NULL ;
}
V_16 -> V_13 = 0 ;
}
return ( 1 ) ;
}
static int T_4 F_13 ( T_1 * V_18 , char * V_19 , int V_20 )
{
int V_3 = 0 ;
if ( V_18 -> V_13 && ( V_19 != NULL ) )
{
V_3 = fread ( V_19 , 1 , ( int ) V_20 , ( T_2 * ) V_18 -> V_15 ) ;
}
return ( V_3 ) ;
}
static int T_4 F_14 ( T_1 * V_18 , char * V_21 , int V_22 )
{
int V_3 = 0 ;
if ( V_18 -> V_13 && ( V_21 != NULL ) )
{
if ( fwrite ( V_21 , ( int ) V_22 , 1 , ( T_2 * ) V_18 -> V_15 ) )
V_3 = V_22 ;
}
return ( V_3 ) ;
}
static long T_4 F_15 ( T_1 * V_18 , int V_23 , long V_14 , char * V_15 )
{
long V_3 = 1 ;
T_2 * V_24 = ( T_2 * ) V_18 -> V_15 ;
T_2 * * V_25 ;
char V_26 [ 4 ] ;
switch ( V_23 )
{
case V_27 :
case V_28 :
V_3 = ( long ) fseek ( V_24 , V_14 , 0 ) ;
break;
case V_29 :
V_3 = ( long ) feof ( V_24 ) ;
break;
case V_30 :
case V_31 :
V_3 = ftell ( V_24 ) ;
break;
case V_32 :
F_12 ( V_18 ) ;
V_18 -> V_17 = ( int ) V_14 & V_8 ;
V_18 -> V_15 = ( char * ) V_15 ;
V_18 -> V_13 = 1 ;
#if F_16 ( V_33 ) || F_16 ( V_34 )
if ( V_14 & V_35 )
F_17 ( fileno ( ( T_2 * ) V_15 ) , V_36 ) ;
else
F_17 ( fileno ( ( T_2 * ) V_15 ) , V_37 ) ;
#endif
break;
case V_38 :
F_12 ( V_18 ) ;
V_18 -> V_17 = ( int ) V_14 & V_8 ;
if ( V_14 & V_39 )
{
if ( V_14 & V_40 )
strcpy ( V_26 , L_4 ) ;
else strcpy ( V_26 , L_5 ) ;
}
else if ( ( V_14 & V_40 ) && ( V_14 & V_41 ) )
strcpy ( V_26 , L_6 ) ;
else if ( V_14 & V_41 )
strcpy ( V_26 , L_7 ) ;
else if ( V_14 & V_40 )
strcpy ( V_26 , L_8 ) ;
else
{
F_5 ( V_42 , V_43 ) ;
V_3 = 0 ;
break;
}
#if F_16 ( V_33 ) || F_16 ( V_34 )
if ( ! ( V_14 & V_35 ) )
strcat ( V_26 , L_9 ) ;
else
strcat ( V_26 , L_10 ) ;
#endif
V_24 = fopen ( V_15 , V_26 ) ;
if ( V_24 == NULL )
{
F_2 ( V_5 , F_3 () ) ;
F_4 ( 5 , L_1 , V_15 , L_2 , V_26 , L_3 ) ;
F_5 ( V_42 , V_7 ) ;
V_3 = 0 ;
break;
}
V_18 -> V_15 = ( char * ) V_24 ;
V_18 -> V_13 = 1 ;
break;
case V_44 :
if ( V_15 != NULL )
{
V_25 = ( T_2 * * ) V_15 ;
* V_25 = ( T_2 * ) V_18 -> V_15 ;
}
break;
case V_45 :
V_3 = ( long ) V_18 -> V_17 ;
break;
case V_46 :
V_18 -> V_17 = ( int ) V_14 ;
break;
case V_47 :
fflush ( ( T_2 * ) V_18 -> V_15 ) ;
break;
case V_48 :
V_3 = 1 ;
break;
case V_49 :
case V_50 :
case V_51 :
case V_52 :
default:
V_3 = 0 ;
break;
}
return ( V_3 ) ;
}
static int T_4 F_18 ( T_1 * V_53 , char * V_54 , int V_55 )
{
int V_3 = 0 ;
V_54 [ 0 ] = '\0' ;
fgets ( V_54 , V_55 , ( T_2 * ) V_53 -> V_15 ) ;
if ( V_54 [ 0 ] != '\0' )
V_3 = strlen ( V_54 ) ;
return ( V_3 ) ;
}
static int T_4 F_19 ( T_1 * V_53 , char * V_56 )
{
int V_57 , V_3 ;
V_57 = strlen ( V_56 ) ;
V_3 = F_14 ( V_53 , V_56 , V_57 ) ;
return ( V_3 ) ;
}
