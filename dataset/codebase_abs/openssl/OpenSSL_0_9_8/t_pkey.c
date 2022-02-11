int F_1 ( T_1 * V_1 , const T_2 * V_2 , int V_3 )
{
T_3 * V_4 ;
int V_5 ;
if ( ( V_4 = F_2 ( F_3 () ) ) == NULL )
{
F_4 ( V_6 , V_7 ) ;
return ( 0 ) ;
}
F_5 ( V_4 , V_1 , V_8 ) ;
V_5 = F_6 ( V_4 , V_2 , V_3 ) ;
F_7 ( V_4 ) ;
return ( V_5 ) ;
}
int F_6 ( T_3 * V_9 , const T_2 * V_2 , int V_3 )
{
char V_10 [ 128 ] ;
const char * V_11 ;
unsigned char * V_12 = NULL ;
int V_5 = 0 ;
T_4 V_13 = 0 , V_14 ;
if ( V_2 -> V_15 )
V_13 = ( T_4 ) F_8 ( V_2 -> V_15 ) ;
if ( V_2 -> V_16 )
if ( V_13 < ( V_14 = ( T_4 ) F_8 ( V_2 -> V_16 ) ) )
V_13 = V_14 ;
if ( V_2 -> V_17 )
if ( V_13 < ( V_14 = ( T_4 ) F_8 ( V_2 -> V_17 ) ) )
V_13 = V_14 ;
if ( V_2 -> V_18 )
if ( V_13 < ( V_14 = ( T_4 ) F_8 ( V_2 -> V_18 ) ) )
V_13 = V_14 ;
if ( V_2 -> V_19 )
if ( V_13 < ( V_14 = ( T_4 ) F_8 ( V_2 -> V_19 ) ) )
V_13 = V_14 ;
if ( V_2 -> V_20 )
if ( V_13 < ( V_14 = ( T_4 ) F_8 ( V_2 -> V_20 ) ) )
V_13 = V_14 ;
if ( V_2 -> V_21 )
if ( V_13 < ( V_14 = ( T_4 ) F_8 ( V_2 -> V_21 ) ) )
V_13 = V_14 ;
if ( V_2 -> V_22 )
if ( V_13 < ( V_14 = ( T_4 ) F_8 ( V_2 -> V_22 ) ) )
V_13 = V_14 ;
V_12 = ( unsigned char * ) F_9 ( V_13 + 10 ) ;
if ( V_12 == NULL )
{
F_4 ( V_23 , V_24 ) ;
goto V_25;
}
if ( V_2 -> V_17 != NULL )
{
if( ! F_10 ( V_9 , V_3 , 128 ) )
goto V_25;
if ( F_11 ( V_9 , L_1 , F_12 ( V_2 -> V_15 ) )
<= 0 ) goto V_25;
}
if ( V_2 -> V_17 == NULL )
F_13 ( V_10 , sizeof V_10 , L_2 , F_12 ( V_2 -> V_15 ) ) ;
else
F_14 ( V_10 , L_3 , sizeof V_10 ) ;
if ( ! F_15 ( V_9 , V_10 , V_2 -> V_15 , V_12 , V_3 ) ) goto V_25;
V_11 = ( V_2 -> V_17 == NULL ) ? L_4 : L_5 ;
if ( ! F_15 ( V_9 , V_11 , V_2 -> V_16 , V_12 , V_3 ) ) goto V_25;
if ( ! F_15 ( V_9 , L_6 , V_2 -> V_17 , V_12 , V_3 ) ) goto V_25;
if ( ! F_15 ( V_9 , L_7 , V_2 -> V_18 , V_12 , V_3 ) ) goto V_25;
if ( ! F_15 ( V_9 , L_8 , V_2 -> V_19 , V_12 , V_3 ) ) goto V_25;
if ( ! F_15 ( V_9 , L_9 , V_2 -> V_20 , V_12 , V_3 ) ) goto V_25;
if ( ! F_15 ( V_9 , L_10 , V_2 -> V_21 , V_12 , V_3 ) ) goto V_25;
if ( ! F_15 ( V_9 , L_11 , V_2 -> V_22 , V_12 , V_3 ) ) goto V_25;
V_5 = 1 ;
V_25:
if ( V_12 != NULL ) F_16 ( V_12 ) ;
return ( V_5 ) ;
}
int F_17 ( T_1 * V_1 , const T_5 * V_2 , int V_3 )
{
T_3 * V_4 ;
int V_5 ;
if ( ( V_4 = F_2 ( F_3 () ) ) == NULL )
{
F_18 ( V_26 , V_7 ) ;
return ( 0 ) ;
}
F_5 ( V_4 , V_1 , V_8 ) ;
V_5 = F_19 ( V_4 , V_2 , V_3 ) ;
F_7 ( V_4 ) ;
return ( V_5 ) ;
}
int F_19 ( T_3 * V_9 , const T_5 * V_2 , int V_3 )
{
unsigned char * V_12 = NULL ;
int V_5 = 0 ;
T_4 V_13 = 0 , V_14 ;
if ( V_2 -> V_18 )
V_13 = ( T_4 ) F_8 ( V_2 -> V_18 ) ;
if ( V_2 -> V_19 )
if ( V_13 < ( V_14 = ( T_4 ) F_8 ( V_2 -> V_19 ) ) )
V_13 = V_14 ;
if ( V_2 -> V_27 )
if ( V_13 < ( V_14 = ( T_4 ) F_8 ( V_2 -> V_27 ) ) )
V_13 = V_14 ;
if ( V_2 -> V_28 )
if ( V_13 < ( V_14 = ( T_4 ) F_8 ( V_2 -> V_28 ) ) )
V_13 = V_14 ;
if ( V_2 -> V_29 )
if ( V_13 < ( V_14 = ( T_4 ) F_8 ( V_2 -> V_29 ) ) )
V_13 = V_14 ;
V_12 = ( unsigned char * ) F_9 ( V_13 + 10 ) ;
if ( V_12 == NULL )
{
F_18 ( V_30 , V_24 ) ;
goto V_25;
}
if ( V_2 -> V_28 != NULL )
{
if( ! F_10 ( V_9 , V_3 , 128 ) )
goto V_25;
if ( F_11 ( V_9 , L_1 , F_12 ( V_2 -> V_18 ) )
<= 0 ) goto V_25;
}
if ( ( V_2 -> V_28 != NULL ) && ! F_15 ( V_9 , L_12 , V_2 -> V_28 , V_12 , V_3 ) )
goto V_25;
if ( ( V_2 -> V_29 != NULL ) && ! F_15 ( V_9 , L_13 , V_2 -> V_29 , V_12 , V_3 ) )
goto V_25;
if ( ( V_2 -> V_18 != NULL ) && ! F_15 ( V_9 , L_14 , V_2 -> V_18 , V_12 , V_3 ) ) goto V_25;
if ( ( V_2 -> V_19 != NULL ) && ! F_15 ( V_9 , L_15 , V_2 -> V_19 , V_12 , V_3 ) ) goto V_25;
if ( ( V_2 -> V_27 != NULL ) && ! F_15 ( V_9 , L_16 , V_2 -> V_27 , V_12 , V_3 ) ) goto V_25;
V_5 = 1 ;
V_25:
if ( V_12 != NULL ) F_16 ( V_12 ) ;
return ( V_5 ) ;
}
int F_20 ( T_1 * V_1 , const T_6 * V_2 , int V_3 )
{
T_3 * V_4 ;
int V_5 ;
if ( ( V_4 = F_2 ( F_3 () ) ) == NULL )
{
F_21 ( V_31 , V_7 ) ;
return ( 0 ) ;
}
F_5 ( V_4 , V_1 , V_8 ) ;
V_5 = F_22 ( V_4 , V_2 , V_3 ) ;
F_7 ( V_4 ) ;
return ( V_5 ) ;
}
int F_23 ( T_1 * V_1 , const T_7 * V_2 , int V_3 )
{
T_3 * V_4 ;
int V_5 ;
if ( ( V_4 = F_2 ( F_3 () ) ) == NULL )
{
F_21 ( V_32 , V_33 ) ;
return ( 0 ) ;
}
F_5 ( V_4 , V_1 , V_8 ) ;
V_5 = F_24 ( V_4 , V_2 , V_3 ) ;
F_7 ( V_4 ) ;
return ( V_5 ) ;
}
int F_22 ( T_3 * V_9 , const T_6 * V_2 , int V_3 )
{
unsigned char * V_34 = NULL ;
T_4 V_13 = 0 , V_14 ;
int V_5 = 0 , V_35 = V_33 ;
T_8 * V_36 = NULL ;
const T_9 * V_37 = NULL ;
T_10 * V_18 = NULL , * V_38 = NULL , * V_4 = NULL , * V_39 = NULL ,
* V_40 = NULL , * V_41 = NULL ;
const unsigned char * V_42 ;
T_4 V_43 = 0 ;
static const char * V_44 = L_17 ;
static const char * V_45 = L_18 ;
static const char * V_46 = L_19 ;
if ( ! V_2 )
{
V_35 = V_47 ;
goto V_25;
}
if ( F_25 ( V_2 ) )
{
int V_48 ;
if ( ! F_10 ( V_9 , V_3 , 128 ) )
goto V_25;
V_48 = F_26 ( V_2 ) ;
if ( V_48 == 0 )
goto V_25;
if ( F_11 ( V_9 , L_20 , F_27 ( V_48 ) ) <= 0 )
goto V_25;
if ( F_11 ( V_9 , L_21 ) <= 0 )
goto V_25;
}
else
{
int V_49 = 0 ;
T_11 V_50 ;
int V_51 = F_28 ( F_29 ( V_2 ) ) ;
if ( V_51 == V_52 )
V_49 = 1 ;
if ( ( V_18 = F_30 () ) == NULL || ( V_38 = F_30 () ) == NULL ||
( V_4 = F_30 () ) == NULL || ( V_40 = F_30 () ) == NULL ||
( V_41 = F_30 () ) == NULL )
{
V_35 = V_24 ;
goto V_25;
}
if ( V_49 )
{
if ( ! F_31 ( V_2 , V_18 , V_38 , V_4 , V_36 ) )
{
V_35 = V_53 ;
goto V_25;
}
}
else
{
if ( ! F_32 ( V_2 , V_18 , V_38 , V_4 , V_36 ) )
{
V_35 = V_53 ;
goto V_25;
}
}
if ( ( V_37 = F_33 ( V_2 ) ) == NULL )
{
V_35 = V_53 ;
goto V_25;
}
if ( ! F_34 ( V_2 , V_40 , NULL ) ||
! F_35 ( V_2 , V_41 , NULL ) )
{
V_35 = V_53 ;
goto V_25;
}
V_50 = F_36 ( V_2 ) ;
if ( ( V_39 = F_37 ( V_2 , V_37 ,
V_50 , NULL , V_36 ) ) == NULL )
{
V_35 = V_53 ;
goto V_25;
}
V_13 = ( T_4 ) F_8 ( V_18 ) ;
if ( V_13 < ( V_14 = ( T_4 ) F_8 ( V_38 ) ) )
V_13 = V_14 ;
if ( V_13 < ( V_14 = ( T_4 ) F_8 ( V_4 ) ) )
V_13 = V_14 ;
if ( V_13 < ( V_14 = ( T_4 ) F_8 ( V_39 ) ) )
V_13 = V_14 ;
if ( V_13 < ( V_14 = ( T_4 ) F_8 ( V_40 ) ) )
V_13 = V_14 ;
if ( V_13 < ( V_14 = ( T_4 ) F_8 ( V_41 ) ) )
V_13 = V_14 ;
if ( ( V_42 = F_38 ( V_2 ) ) != NULL )
V_43 = F_39 ( V_2 ) ;
V_13 += 10 ;
if ( ( V_34 = F_9 ( V_13 ) ) == NULL )
{
V_35 = V_24 ;
goto V_25;
}
if ( ! F_10 ( V_9 , V_3 , 128 ) )
goto V_25;
if ( F_11 ( V_9 , L_22 , F_27 ( V_51 ) )
<= 0 )
goto V_25;
if ( V_49 )
{
int V_54 = F_40 ( V_2 ) ;
if ( V_54 == 0 )
goto V_25;
if ( ! F_10 ( V_9 , V_3 , 128 ) )
goto V_25;
if ( F_11 ( V_9 , L_23 ,
F_27 ( V_54 ) ) <= 0 )
goto V_25;
if ( ( V_18 != NULL ) && ! F_15 ( V_9 , L_24 , V_18 , V_34 ,
V_3 ) )
goto V_25;
}
else
{
if ( ( V_18 != NULL ) && ! F_15 ( V_9 , L_25 , V_18 , V_34 , V_3 ) )
goto V_25;
}
if ( ( V_38 != NULL ) && ! F_15 ( V_9 , L_26 , V_38 , V_34 , V_3 ) )
goto V_25;
if ( ( V_4 != NULL ) && ! F_15 ( V_9 , L_27 , V_4 , V_34 , V_3 ) )
goto V_25;
if ( V_50 == V_55 )
{
if ( ( V_39 != NULL ) && ! F_15 ( V_9 , V_44 , V_39 ,
V_34 , V_3 ) )
goto V_25;
}
else if ( V_50 == V_56 )
{
if ( ( V_39 != NULL ) && ! F_15 ( V_9 , V_45 , V_39 ,
V_34 , V_3 ) )
goto V_25;
}
else
{
if ( ( V_39 != NULL ) && ! F_15 ( V_9 , V_46 , V_39 ,
V_34 , V_3 ) )
goto V_25;
}
if ( ( V_40 != NULL ) && ! F_15 ( V_9 , L_28 , V_40 ,
V_34 , V_3 ) ) goto V_25;
if ( ( V_41 != NULL ) && ! F_15 ( V_9 , L_29 , V_41 ,
V_34 , V_3 ) ) goto V_25;
if ( V_42 && ! F_41 ( V_9 , L_30 , V_42 , V_43 , V_3 ) )
goto V_25;
}
V_5 = 1 ;
V_25:
if ( ! V_5 )
F_21 ( V_57 , V_35 ) ;
if ( V_18 )
F_42 ( V_18 ) ;
if ( V_38 )
F_42 ( V_38 ) ;
if ( V_4 )
F_42 ( V_4 ) ;
if ( V_39 )
F_42 ( V_39 ) ;
if ( V_40 )
F_42 ( V_40 ) ;
if ( V_41 )
F_42 ( V_41 ) ;
if ( V_36 )
F_43 ( V_36 ) ;
if ( V_34 != NULL )
F_16 ( V_34 ) ;
return ( V_5 ) ;
}
int F_24 ( T_3 * V_9 , const T_7 * V_2 , int V_3 )
{
unsigned char * V_34 = NULL ;
T_4 V_13 = 0 , V_14 ;
int V_5 = 0 , V_35 = V_33 ;
T_10 * V_29 = NULL , * V_40 = NULL ;
T_8 * V_36 = NULL ;
const T_6 * V_58 ;
const T_9 * V_59 ;
const T_10 * V_28 ;
if ( V_2 == NULL || ( V_58 = F_44 ( V_2 ) ) == NULL )
{
V_35 = V_47 ;
goto V_25;
}
V_59 = F_45 ( V_2 ) ;
if ( ( V_29 = F_37 ( V_58 , V_59 ,
F_46 ( V_2 ) , NULL , V_36 ) ) == NULL )
{
V_35 = V_53 ;
goto V_25;
}
V_13 = ( T_4 ) F_8 ( V_29 ) ;
V_28 = F_47 ( V_2 ) ;
if ( V_28 != NULL )
{
if ( ( V_14 = ( T_4 ) F_8 ( V_28 ) ) > V_13 )
V_13 = V_14 ;
}
V_13 += 10 ;
if ( ( V_34 = F_9 ( V_13 ) ) == NULL )
{
V_35 = V_24 ;
goto V_25;
}
if ( V_28 != NULL )
{
if ( ! F_10 ( V_9 , V_3 , 128 ) )
goto V_25;
if ( ( V_40 = F_30 () ) == NULL )
goto V_25;
if ( ! F_34 ( V_58 , V_40 , NULL ) )
goto V_25;
if ( F_11 ( V_9 , L_1 ,
F_12 ( V_40 ) ) <= 0 ) goto V_25;
}
if ( ( V_28 != NULL ) && ! F_15 ( V_9 , L_12 , V_28 ,
V_34 , V_3 ) )
goto V_25;
if ( ( V_29 != NULL ) && ! F_15 ( V_9 , L_13 , V_29 ,
V_34 , V_3 ) )
goto V_25;
if ( ! F_22 ( V_9 , V_58 , V_3 ) )
goto V_25;
V_5 = 1 ;
V_25:
if ( ! V_5 )
F_21 ( V_60 , V_35 ) ;
if ( V_29 )
F_42 ( V_29 ) ;
if ( V_40 )
F_42 ( V_40 ) ;
if ( V_36 )
F_43 ( V_36 ) ;
if ( V_34 != NULL )
F_16 ( V_34 ) ;
return ( V_5 ) ;
}
static int F_15 ( T_3 * V_9 , const char * V_61 , const T_10 * V_62 , unsigned char * V_63 ,
int V_3 )
{
int V_15 , V_14 ;
const char * V_64 ;
if ( V_62 == NULL ) return ( 1 ) ;
V_64 = ( F_48 ( V_62 ) ) ? L_31 : L_32 ;
if( ! F_10 ( V_9 , V_3 , 128 ) )
return 0 ;
if ( F_49 ( V_62 ) )
{
if ( F_11 ( V_9 , L_33 , V_61 ) <= 0 )
return 0 ;
return 1 ;
}
if ( F_8 ( V_62 ) <= V_65 )
{
if ( F_11 ( V_9 , L_34 , V_61 , V_64 ,
( unsigned long ) V_62 -> V_17 [ 0 ] , V_64 , ( unsigned long ) V_62 -> V_17 [ 0 ] )
<= 0 ) return ( 0 ) ;
}
else
{
V_63 [ 0 ] = 0 ;
if ( F_11 ( V_9 , L_35 , V_61 ,
( V_64 [ 0 ] == '-' ) ? L_36 : L_32 ) <= 0 )
return ( 0 ) ;
V_15 = F_50 ( V_62 , & V_63 [ 1 ] ) ;
if ( V_63 [ 1 ] & 0x80 )
V_15 ++ ;
else V_63 ++ ;
for ( V_14 = 0 ; V_14 < V_15 ; V_14 ++ )
{
if ( ( V_14 % 15 ) == 0 )
{
if( F_51 ( V_9 , L_21 ) <= 0
|| ! F_10 ( V_9 , V_3 + 4 , 128 ) )
return 0 ;
}
if ( F_11 ( V_9 , L_37 , V_63 [ V_14 ] , ( ( V_14 + 1 ) == V_15 ) ? L_32 : L_38 )
<= 0 ) return ( 0 ) ;
}
if ( F_52 ( V_9 , L_21 , 1 ) <= 0 ) return ( 0 ) ;
}
return ( 1 ) ;
}
static int F_41 ( T_3 * V_1 , const char * V_66 , const unsigned char * V_63 ,
T_4 V_67 , int V_3 )
{
T_4 V_14 ;
char V_10 [ 128 ] ;
if ( V_63 == NULL )
return 1 ;
if ( V_3 )
{
if ( V_3 > 128 )
V_3 = 128 ;
memset ( V_10 , ' ' , V_3 ) ;
if ( F_52 ( V_1 , V_10 , V_3 ) <= 0 )
return 0 ;
}
if ( F_11 ( V_1 , L_39 , V_66 ) <= 0 )
return 0 ;
for ( V_14 = 0 ; V_14 < V_67 ; V_14 ++ )
{
if ( ( V_14 % 15 ) == 0 )
{
V_10 [ 0 ] = '\n' ;
memset ( & ( V_10 [ 1 ] ) , ' ' , V_3 + 4 ) ;
if ( F_52 ( V_1 , V_10 , V_3 + 1 + 4 ) <= 0 )
return 0 ;
}
if ( F_11 ( V_1 , L_37 , V_63 [ V_14 ] , ( ( V_14 + 1 ) == V_67 ) ? L_32 : L_38 ) <= 0 )
return 0 ;
}
if ( F_52 ( V_1 , L_21 , 1 ) <= 0 )
return 0 ;
return 1 ;
}
int F_53 ( T_1 * V_1 , const T_12 * V_2 )
{
T_3 * V_4 ;
int V_5 ;
if ( ( V_4 = F_2 ( F_3 () ) ) == NULL )
{
F_54 ( V_68 , V_7 ) ;
return ( 0 ) ;
}
F_5 ( V_4 , V_1 , V_8 ) ;
V_5 = F_55 ( V_4 , V_2 ) ;
F_7 ( V_4 ) ;
return ( V_5 ) ;
}
int F_55 ( T_3 * V_9 , const T_12 * V_2 )
{
unsigned char * V_12 = NULL ;
int V_35 = V_7 , V_5 = 0 ;
T_4 V_13 = 0 , V_14 ;
if ( V_2 -> V_18 )
V_13 = ( T_4 ) F_8 ( V_2 -> V_18 ) ;
if ( V_2 -> V_27 )
if ( V_13 < ( V_14 = ( T_4 ) F_8 ( V_2 -> V_27 ) ) )
V_13 = V_14 ;
V_12 = ( unsigned char * ) F_9 ( V_13 + 10 ) ;
if ( V_12 == NULL )
{
V_35 = V_24 ;
goto V_25;
}
if ( F_11 ( V_9 , L_40 ,
F_12 ( V_2 -> V_18 ) ) <= 0 )
goto V_25;
if ( ! F_15 ( V_9 , L_41 , V_2 -> V_18 , V_12 , 4 ) ) goto V_25;
if ( ! F_15 ( V_9 , L_42 , V_2 -> V_27 , V_12 , 4 ) ) goto V_25;
if ( V_2 -> V_69 != 0 )
{
if ( F_11 ( V_9 , L_43 ,
( int ) V_2 -> V_69 ) <= 0 ) goto V_25;
}
V_5 = 1 ;
if ( 0 )
{
V_25:
F_54 ( V_70 , V_35 ) ;
}
if ( V_12 != NULL ) F_16 ( V_12 ) ;
return ( V_5 ) ;
}
int F_56 ( T_1 * V_1 , const T_5 * V_2 )
{
T_3 * V_4 ;
int V_5 ;
if ( ( V_4 = F_2 ( F_3 () ) ) == NULL )
{
F_18 ( V_71 , V_7 ) ;
return ( 0 ) ;
}
F_5 ( V_4 , V_1 , V_8 ) ;
V_5 = F_57 ( V_4 , V_2 ) ;
F_7 ( V_4 ) ;
return ( V_5 ) ;
}
int F_57 ( T_3 * V_9 , const T_5 * V_2 )
{
unsigned char * V_12 = NULL ;
int V_35 = V_7 , V_5 = 0 ;
T_4 V_13 = 0 , V_14 ;
if ( V_2 -> V_18 )
V_13 = ( T_4 ) F_8 ( V_2 -> V_18 ) ;
if ( V_2 -> V_19 )
if ( V_13 < ( V_14 = ( T_4 ) F_8 ( V_2 -> V_19 ) ) )
V_13 = V_14 ;
if ( V_2 -> V_27 )
if ( V_13 < ( V_14 = ( T_4 ) F_8 ( V_2 -> V_27 ) ) )
V_13 = V_14 ;
V_12 = ( unsigned char * ) F_9 ( V_13 + 10 ) ;
if ( V_12 == NULL )
{
V_35 = V_24 ;
goto V_25;
}
if ( F_11 ( V_9 , L_44 ,
F_12 ( V_2 -> V_18 ) ) <= 0 )
goto V_25;
if ( ! F_15 ( V_9 , L_45 , V_2 -> V_18 , V_12 , 4 ) ) goto V_25;
if ( ! F_15 ( V_9 , L_46 , V_2 -> V_19 , V_12 , 4 ) ) goto V_25;
if ( ! F_15 ( V_9 , L_47 , V_2 -> V_27 , V_12 , 4 ) ) goto V_25;
V_5 = 1 ;
V_25:
if ( V_12 != NULL ) F_16 ( V_12 ) ;
F_18 ( V_72 , V_35 ) ;
return ( V_5 ) ;
}
int F_58 ( T_1 * V_1 , const T_7 * V_2 )
{
T_3 * V_4 ;
int V_5 ;
if ( ( V_4 = F_2 ( F_3 () ) ) == NULL )
{
F_21 ( V_73 , V_33 ) ;
return ( 0 ) ;
}
F_5 ( V_4 , V_1 , V_8 ) ;
V_5 = F_59 ( V_4 , V_2 ) ;
F_7 ( V_4 ) ;
return ( V_5 ) ;
}
int F_59 ( T_3 * V_9 , const T_7 * V_2 )
{
int V_35 = V_53 , V_5 = 0 ;
T_10 * V_40 = NULL ;
const T_6 * V_58 ;
if ( V_2 == NULL || ( V_58 = F_44 ( V_2 ) ) == NULL )
{
V_35 = V_47 ; ;
goto V_25;
}
if ( ( V_40 = F_30 () ) == NULL )
{
V_35 = V_24 ;
goto V_25;
}
if ( ! F_34 ( V_58 , V_40 , NULL ) )
{
V_35 = V_53 ;
goto V_25;
}
if ( F_11 ( V_9 , L_48 ,
F_12 ( V_40 ) ) <= 0 )
goto V_25;
if ( ! F_22 ( V_9 , V_58 , 4 ) )
goto V_25;
V_5 = 1 ;
V_25:
if ( V_40 )
F_42 ( V_40 ) ;
F_21 ( V_74 , V_35 ) ;
return ( V_5 ) ;
}
