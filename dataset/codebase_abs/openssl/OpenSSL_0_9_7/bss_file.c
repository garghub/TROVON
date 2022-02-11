T_1 * F_1 ( const char * V_1 , const char * V_2 )
{
T_1 * V_3 ;
T_2 * V_4 ;
if ( ( V_4 = fopen ( V_1 , V_2 ) ) == NULL )
{
F_2 ( V_5 , F_3 () ) ;
F_4 ( 5 , L_1 , V_1 , L_2 , V_2 , L_3 ) ;
if ( V_6 == V_7 )
F_5 ( V_8 , V_9 ) ;
else
F_5 ( V_8 , V_10 ) ;
return ( NULL ) ;
}
if ( ( V_3 = F_6 ( F_7 () ) ) == NULL )
return ( NULL ) ;
F_8 ( V_3 , V_4 , V_11 ) ;
return ( V_3 ) ;
}
T_1 * F_9 ( T_2 * V_12 , int V_13 )
{
T_1 * V_3 ;
if ( ( V_3 = F_6 ( F_10 () ) ) == NULL )
return ( NULL ) ;
F_8 ( V_3 , V_12 , V_13 ) ;
return ( V_3 ) ;
}
T_3 * F_10 ( void )
{
return ( & V_14 ) ;
}
static int T_4 F_11 ( T_1 * V_15 )
{
V_15 -> V_16 = 0 ;
V_15 -> V_17 = 0 ;
V_15 -> V_18 = NULL ;
return ( 1 ) ;
}
static int T_4 F_12 ( T_1 * V_19 )
{
if ( V_19 == NULL ) return ( 0 ) ;
if ( V_19 -> V_20 )
{
if ( ( V_19 -> V_16 ) && ( V_19 -> V_18 != NULL ) )
{
fclose ( ( T_2 * ) V_19 -> V_18 ) ;
V_19 -> V_18 = NULL ;
}
V_19 -> V_16 = 0 ;
}
return ( 1 ) ;
}
static int T_4 F_13 ( T_1 * V_21 , char * V_22 , int V_23 )
{
int V_3 = 0 ;
if ( V_21 -> V_16 && ( V_22 != NULL ) )
{
V_3 = fread ( V_22 , 1 , ( int ) V_23 , ( T_2 * ) V_21 -> V_18 ) ;
if( V_3 == 0 && ferror ( ( T_2 * ) V_21 -> V_18 ) )
{
F_2 ( V_24 , F_3 () ) ;
F_5 ( V_25 , V_10 ) ;
V_3 = - 1 ;
}
}
return ( V_3 ) ;
}
static int T_4 F_14 ( T_1 * V_21 , const char * V_26 , int V_27 )
{
int V_3 = 0 ;
if ( V_21 -> V_16 && ( V_26 != NULL ) )
{
if ( fwrite ( V_26 , ( int ) V_27 , 1 , ( T_2 * ) V_21 -> V_18 ) )
V_3 = V_27 ;
}
return ( V_3 ) ;
}
static long T_4 F_15 ( T_1 * V_21 , int V_28 , long V_17 , void * V_18 )
{
long V_3 = 1 ;
T_2 * V_29 = ( T_2 * ) V_21 -> V_18 ;
T_2 * * V_30 ;
char V_31 [ 4 ] ;
switch ( V_28 )
{
case V_32 :
case V_33 :
V_3 = ( long ) fseek ( V_29 , V_17 , 0 ) ;
break;
case V_34 :
V_3 = ( long ) feof ( V_29 ) ;
break;
case V_35 :
case V_36 :
V_3 = ftell ( V_29 ) ;
break;
case V_37 :
F_12 ( V_21 ) ;
V_21 -> V_20 = ( int ) V_17 & V_11 ;
V_21 -> V_18 = ( char * ) V_18 ;
V_21 -> V_16 = 1 ;
#if F_16 ( V_38 ) || F_16 ( V_39 )
if ( V_17 & V_40 )
F_17 ( fileno ( ( T_2 * ) V_18 ) , V_41 ) ;
else
F_17 ( fileno ( ( T_2 * ) V_18 ) , V_42 ) ;
#elif F_16 ( V_43 )
if ( V_17 & V_40 )
F_18 ( fileno ( ( T_2 * ) V_18 ) , V_44 ) ;
else
F_18 ( fileno ( ( T_2 * ) V_18 ) , V_45 ) ;
#endif
break;
case V_46 :
F_12 ( V_21 ) ;
V_21 -> V_20 = ( int ) V_17 & V_11 ;
if ( V_17 & V_47 )
{
if ( V_17 & V_48 )
strcpy ( V_31 , L_4 ) ;
else strcpy ( V_31 , L_5 ) ;
}
else if ( ( V_17 & V_48 ) && ( V_17 & V_49 ) )
strcpy ( V_31 , L_6 ) ;
else if ( V_17 & V_49 )
strcpy ( V_31 , L_7 ) ;
else if ( V_17 & V_48 )
strcpy ( V_31 , L_8 ) ;
else
{
F_5 ( V_50 , V_51 ) ;
V_3 = 0 ;
break;
}
#if F_16 ( V_38 ) || F_16 ( V_39 ) || F_16 ( V_43 )
if ( ! ( V_17 & V_40 ) )
strcat ( V_31 , L_9 ) ;
else
strcat ( V_31 , L_10 ) ;
#endif
V_29 = fopen ( V_18 , V_31 ) ;
if ( V_29 == NULL )
{
F_2 ( V_5 , F_3 () ) ;
F_4 ( 5 , L_1 , V_18 , L_2 , V_31 , L_3 ) ;
F_5 ( V_50 , V_10 ) ;
V_3 = 0 ;
break;
}
V_21 -> V_18 = ( char * ) V_29 ;
V_21 -> V_16 = 1 ;
break;
case V_52 :
if ( V_18 != NULL )
{
V_30 = ( T_2 * * ) V_18 ;
* V_30 = ( T_2 * ) V_21 -> V_18 ;
}
break;
case V_53 :
V_3 = ( long ) V_21 -> V_20 ;
break;
case V_54 :
V_21 -> V_20 = ( int ) V_17 ;
break;
case V_55 :
fflush ( ( T_2 * ) V_21 -> V_18 ) ;
break;
case V_56 :
V_3 = 1 ;
break;
case V_57 :
case V_58 :
case V_59 :
case V_60 :
default:
V_3 = 0 ;
break;
}
return ( V_3 ) ;
}
static int T_4 F_19 ( T_1 * V_61 , char * V_62 , int V_63 )
{
int V_3 = 0 ;
V_62 [ 0 ] = '\0' ;
fgets ( V_62 , V_63 , ( T_2 * ) V_61 -> V_18 ) ;
if ( V_62 [ 0 ] != '\0' )
V_3 = strlen ( V_62 ) ;
return ( V_3 ) ;
}
static int T_4 F_20 ( T_1 * V_61 , const char * V_64 )
{
int V_65 , V_3 ;
V_65 = strlen ( V_64 ) ;
V_3 = F_14 ( V_61 , V_64 , V_65 ) ;
return ( V_3 ) ;
}
