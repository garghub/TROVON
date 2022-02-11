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
F_8 ( V_3 , V_11 ) ;
F_9 ( V_3 , V_4 , V_12 ) ;
return ( V_3 ) ;
}
T_1 * F_10 ( T_2 * V_13 , int V_14 )
{
T_1 * V_3 ;
if ( ( V_3 = F_6 ( F_11 () ) ) == NULL )
return ( NULL ) ;
F_12 ( V_3 , V_11 ) ;
F_9 ( V_3 , V_13 , V_14 ) ;
return ( V_3 ) ;
}
T_3 * F_11 ( void )
{
return ( & V_15 ) ;
}
static int T_4 F_13 ( T_1 * V_16 )
{
V_16 -> V_17 = 0 ;
V_16 -> V_18 = 0 ;
V_16 -> V_19 = NULL ;
V_16 -> V_20 = V_11 ;
return ( 1 ) ;
}
static int T_4 F_14 ( T_1 * V_21 )
{
if ( V_21 == NULL ) return ( 0 ) ;
if ( V_21 -> V_22 )
{
if ( ( V_21 -> V_17 ) && ( V_21 -> V_19 != NULL ) )
{
if ( V_21 -> V_20 & V_11 )
F_15 ( V_21 -> V_19 ) ;
else
fclose ( V_21 -> V_19 ) ;
V_21 -> V_19 = NULL ;
V_21 -> V_20 = V_11 ;
}
V_21 -> V_17 = 0 ;
}
return ( 1 ) ;
}
static int T_4 F_16 ( T_1 * V_23 , char * V_24 , int V_25 )
{
int V_3 = 0 ;
if ( V_23 -> V_17 && ( V_24 != NULL ) )
{
if ( V_23 -> V_20 & V_11 )
V_3 = F_17 ( V_24 , 1 , ( int ) V_25 , V_23 -> V_19 ) ;
else
V_3 = fread ( V_24 , 1 , ( int ) V_25 , ( T_2 * ) V_23 -> V_19 ) ;
if( V_3 == 0 && ( V_23 -> V_20 & V_11 ) ? F_18 ( ( T_2 * ) V_23 -> V_19 ) : ferror ( ( T_2 * ) V_23 -> V_19 ) )
{
F_2 ( V_26 , F_3 () ) ;
F_5 ( V_27 , V_10 ) ;
V_3 = - 1 ;
}
}
return ( V_3 ) ;
}
static int T_4 F_19 ( T_1 * V_23 , const char * V_28 , int V_29 )
{
int V_3 = 0 ;
if ( V_23 -> V_17 && ( V_28 != NULL ) )
{
if ( V_23 -> V_20 & V_11 )
V_3 = F_20 ( V_28 , ( int ) V_29 , 1 , V_23 -> V_19 ) ;
else
V_3 = fwrite ( V_28 , ( int ) V_29 , 1 , ( T_2 * ) V_23 -> V_19 ) ;
if ( V_3 )
V_3 = V_29 ;
}
return ( V_3 ) ;
}
static long T_4 F_21 ( T_1 * V_23 , int V_30 , long V_18 , void * V_19 )
{
long V_3 = 1 ;
T_2 * V_31 = ( T_2 * ) V_23 -> V_19 ;
T_2 * * V_32 ;
char V_33 [ 4 ] ;
switch ( V_30 )
{
case V_34 :
case V_35 :
if ( V_23 -> V_20 & V_11 )
V_3 = ( long ) F_22 ( V_23 -> V_19 , V_18 , 0 ) ;
else
V_3 = ( long ) fseek ( V_31 , V_18 , 0 ) ;
break;
case V_36 :
if ( V_23 -> V_20 & V_11 )
V_3 = ( long ) F_23 ( V_31 ) ;
else
V_3 = ( long ) feof ( V_31 ) ;
break;
case V_37 :
case V_38 :
if ( V_23 -> V_20 & V_11 )
V_3 = F_24 ( V_23 -> V_19 ) ;
else
V_3 = ftell ( V_31 ) ;
break;
case V_39 :
F_14 ( V_23 ) ;
V_23 -> V_22 = ( int ) V_18 & V_12 ;
V_23 -> V_19 = V_19 ;
V_23 -> V_17 = 1 ;
#if V_11 != 0
#if F_25 ( V_40 ) && F_25 ( V_41 ) && ! F_25 ( V_42 )
#define V_42 20
#endif
#if F_25 ( V_42 )
if ( ( V_43 ) V_19 >= ( V_43 ) V_44 &&
( V_43 ) V_19 < ( V_43 ) ( V_44 + V_42 ) )
F_8 ( V_23 , V_11 ) ;
#endif
#endif
#ifdef F_26
if ( V_23 -> V_20 & V_11 )
F_26 ( V_23 -> V_19 , V_18 & V_45 ? 't' : 'b' ) ;
else
#endif
{
#if F_25 ( V_46 )
int V_47 = fileno ( ( T_2 * ) V_19 ) ;
if ( V_18 & V_45 )
F_27 ( V_47 , V_48 ) ;
else
F_27 ( V_47 , V_49 ) ;
#elif F_25 ( V_50 ) && F_25 ( V_51 )
int V_47 = fileno ( ( T_2 * ) V_19 ) ;
if ( V_18 & V_45 )
F_27 ( V_47 , V_52 ) ;
else
F_27 ( V_47 , V_53 ) ;
#elif F_25 ( V_54 )
int V_47 = fileno ( ( T_2 * ) V_19 ) ;
if ( V_18 & V_45 )
F_27 ( V_47 , V_48 ) ;
else
{
if ( V_47 == V_55 || V_47 == V_56 )
{
if ( F_28 ( V_47 ) <= 0 )
F_27 ( V_47 , V_49 ) ;
}
else
F_27 ( V_47 , V_49 ) ;
}
#elif F_25 ( V_57 )
int V_47 = fileno ( ( T_2 * ) V_19 ) ;
if ( V_18 & V_45 )
F_29 ( V_47 , V_52 ) ;
else
F_29 ( V_47 , V_53 ) ;
#endif
}
break;
case V_58 :
F_14 ( V_23 ) ;
V_23 -> V_22 = ( int ) V_18 & V_12 ;
if ( V_18 & V_59 )
{
if ( V_18 & V_60 )
F_30 ( V_33 , L_4 , sizeof V_33 ) ;
else F_30 ( V_33 , L_5 , sizeof V_33 ) ;
}
else if ( ( V_18 & V_60 ) && ( V_18 & V_61 ) )
F_30 ( V_33 , L_6 , sizeof V_33 ) ;
else if ( V_18 & V_61 )
F_30 ( V_33 , L_7 , sizeof V_33 ) ;
else if ( V_18 & V_60 )
F_30 ( V_33 , L_8 , sizeof V_33 ) ;
else
{
F_5 ( V_62 , V_63 ) ;
V_3 = 0 ;
break;
}
#if F_25 ( V_54 ) || F_25 ( V_46 ) || F_25 ( V_57 ) || F_25 ( V_64 )
if ( ! ( V_18 & V_45 ) )
strcat ( V_33 , L_9 ) ;
else
strcat ( V_33 , L_10 ) ;
#endif
#if F_25 ( V_50 )
if ( ! ( V_18 & V_45 ) )
strcat ( V_33 , L_9 ) ;
else
strcat ( V_33 , L_10 ) ;
#endif
V_31 = fopen ( V_19 , V_33 ) ;
if ( V_31 == NULL )
{
F_2 ( V_5 , F_3 () ) ;
F_4 ( 5 , L_1 , V_19 , L_2 , V_33 , L_3 ) ;
F_5 ( V_62 , V_10 ) ;
V_3 = 0 ;
break;
}
V_23 -> V_19 = V_31 ;
V_23 -> V_17 = 1 ;
F_8 ( V_23 , V_11 ) ;
break;
case V_65 :
if ( V_19 != NULL )
{
V_32 = ( T_2 * * ) V_19 ;
* V_32 = ( T_2 * ) V_23 -> V_19 ;
}
break;
case V_66 :
V_3 = ( long ) V_23 -> V_22 ;
break;
case V_67 :
V_23 -> V_22 = ( int ) V_18 ;
break;
case V_68 :
if ( V_23 -> V_20 & V_11 )
F_31 ( V_23 -> V_19 ) ;
else
fflush ( ( T_2 * ) V_23 -> V_19 ) ;
break;
case V_69 :
V_3 = 1 ;
break;
case V_70 :
case V_71 :
case V_72 :
case V_73 :
default:
V_3 = 0 ;
break;
}
return ( V_3 ) ;
}
static int T_4 F_32 ( T_1 * V_74 , char * V_75 , int V_76 )
{
int V_3 = 0 ;
V_75 [ 0 ] = '\0' ;
fgets ( V_75 , V_76 , ( T_2 * ) V_74 -> V_19 ) ;
if ( V_75 [ 0 ] != '\0' )
V_3 = strlen ( V_75 ) ;
return ( V_3 ) ;
}
static int T_4 F_33 ( T_1 * V_74 , const char * V_77 )
{
int V_78 , V_3 ;
V_78 = strlen ( V_77 ) ;
V_3 = F_19 ( V_74 , V_77 , V_78 ) ;
return ( V_3 ) ;
}
