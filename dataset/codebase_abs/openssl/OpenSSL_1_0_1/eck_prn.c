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
int F_8 ( T_1 * V_1 , const T_4 * V_2 , int V_3 )
{
T_3 * V_4 ;
int V_5 ;
if ( ( V_4 = F_2 ( F_3 () ) ) == NULL )
{
F_4 ( V_9 , V_10 ) ;
return ( 0 ) ;
}
F_5 ( V_4 , V_1 , V_8 ) ;
V_5 = F_9 ( V_4 , V_2 , V_3 ) ;
F_7 ( V_4 ) ;
return ( V_5 ) ;
}
int F_10 ( T_1 * V_1 , const T_4 * V_2 )
{
T_3 * V_4 ;
int V_5 ;
if ( ( V_4 = F_2 ( F_3 () ) ) == NULL )
{
F_4 ( V_11 , V_10 ) ;
return ( 0 ) ;
}
F_5 ( V_4 , V_1 , V_8 ) ;
V_5 = F_11 ( V_4 , V_2 ) ;
F_7 ( V_4 ) ;
return ( V_5 ) ;
}
int F_9 ( T_3 * V_12 , const T_4 * V_2 , int V_3 )
{
T_5 * V_13 ;
int V_5 ;
V_13 = F_12 () ;
if ( ! V_13 || ! F_13 ( V_13 , ( T_4 * ) V_2 ) )
return 0 ;
V_5 = F_14 ( V_12 , V_13 , V_3 , NULL ) ;
F_15 ( V_13 ) ;
return V_5 ;
}
int F_11 ( T_3 * V_12 , const T_4 * V_2 )
{
T_5 * V_13 ;
int V_5 ;
V_13 = F_12 () ;
if ( ! V_13 || ! F_13 ( V_13 , ( T_4 * ) V_2 ) )
return 0 ;
V_5 = F_16 ( V_12 , V_13 , 4 , NULL ) ;
F_15 ( V_13 ) ;
return V_5 ;
}
int F_6 ( T_3 * V_12 , const T_2 * V_2 , int V_3 )
{
unsigned char * V_14 = NULL ;
T_6 V_15 = 0 , V_16 ;
int V_5 = 0 , V_17 = V_10 ;
T_7 * V_18 = NULL ;
const T_8 * V_19 = NULL ;
T_9 * V_20 = NULL , * V_21 = NULL , * V_4 = NULL , * V_22 = NULL ,
* V_23 = NULL , * V_24 = NULL ;
const unsigned char * V_25 ;
T_6 V_26 = 0 ;
static const char * V_27 = L_1 ;
static const char * V_28 = L_2 ;
static const char * V_29 = L_3 ;
if ( ! V_2 )
{
V_17 = V_30 ;
goto V_31;
}
V_18 = F_17 () ;
if ( V_18 == NULL )
{
V_17 = V_32 ;
goto V_31;
}
if ( F_18 ( V_2 ) )
{
int V_33 ;
if ( ! F_19 ( V_12 , V_3 , 128 ) )
goto V_31;
V_33 = F_20 ( V_2 ) ;
if ( V_33 == 0 )
goto V_31;
if ( F_21 ( V_12 , L_4 , F_22 ( V_33 ) ) <= 0 )
goto V_31;
if ( F_21 ( V_12 , L_5 ) <= 0 )
goto V_31;
}
else
{
int V_34 = 0 ;
T_10 V_35 ;
int V_36 = F_23 ( F_24 ( V_2 ) ) ;
if ( V_36 == V_37 )
V_34 = 1 ;
if ( ( V_20 = F_25 () ) == NULL || ( V_21 = F_25 () ) == NULL ||
( V_4 = F_25 () ) == NULL || ( V_23 = F_25 () ) == NULL ||
( V_24 = F_25 () ) == NULL )
{
V_17 = V_32 ;
goto V_31;
}
#ifndef F_26
if ( V_34 )
{
if ( ! F_27 ( V_2 , V_20 , V_21 , V_4 , V_18 ) )
{
V_17 = V_38 ;
goto V_31;
}
}
else
#endif
{
if ( ! F_28 ( V_2 , V_20 , V_21 , V_4 , V_18 ) )
{
V_17 = V_38 ;
goto V_31;
}
}
if ( ( V_19 = F_29 ( V_2 ) ) == NULL )
{
V_17 = V_38 ;
goto V_31;
}
if ( ! F_30 ( V_2 , V_23 , NULL ) ||
! F_31 ( V_2 , V_24 , NULL ) )
{
V_17 = V_38 ;
goto V_31;
}
V_35 = F_32 ( V_2 ) ;
if ( ( V_22 = F_33 ( V_2 , V_19 ,
V_35 , NULL , V_18 ) ) == NULL )
{
V_17 = V_38 ;
goto V_31;
}
V_15 = ( T_6 ) F_34 ( V_20 ) ;
if ( V_15 < ( V_16 = ( T_6 ) F_34 ( V_21 ) ) )
V_15 = V_16 ;
if ( V_15 < ( V_16 = ( T_6 ) F_34 ( V_4 ) ) )
V_15 = V_16 ;
if ( V_15 < ( V_16 = ( T_6 ) F_34 ( V_22 ) ) )
V_15 = V_16 ;
if ( V_15 < ( V_16 = ( T_6 ) F_34 ( V_23 ) ) )
V_15 = V_16 ;
if ( V_15 < ( V_16 = ( T_6 ) F_34 ( V_24 ) ) )
V_15 = V_16 ;
if ( ( V_25 = F_35 ( V_2 ) ) != NULL )
V_26 = F_36 ( V_2 ) ;
V_15 += 10 ;
if ( ( V_14 = F_37 ( V_15 ) ) == NULL )
{
V_17 = V_32 ;
goto V_31;
}
if ( ! F_19 ( V_12 , V_3 , 128 ) )
goto V_31;
if ( F_21 ( V_12 , L_6 , F_22 ( V_36 ) )
<= 0 )
goto V_31;
if ( V_34 )
{
int V_39 = F_38 ( V_2 ) ;
if ( V_39 == 0 )
goto V_31;
if ( ! F_19 ( V_12 , V_3 , 128 ) )
goto V_31;
if ( F_21 ( V_12 , L_7 ,
F_22 ( V_39 ) ) <= 0 )
goto V_31;
if ( ( V_20 != NULL ) && ! F_39 ( V_12 , L_8 , V_20 , V_14 ,
V_3 ) )
goto V_31;
}
else
{
if ( ( V_20 != NULL ) && ! F_39 ( V_12 , L_9 , V_20 , V_14 , V_3 ) )
goto V_31;
}
if ( ( V_21 != NULL ) && ! F_39 ( V_12 , L_10 , V_21 , V_14 , V_3 ) )
goto V_31;
if ( ( V_4 != NULL ) && ! F_39 ( V_12 , L_11 , V_4 , V_14 , V_3 ) )
goto V_31;
if ( V_35 == V_40 )
{
if ( ( V_22 != NULL ) && ! F_39 ( V_12 , V_27 , V_22 ,
V_14 , V_3 ) )
goto V_31;
}
else if ( V_35 == V_41 )
{
if ( ( V_22 != NULL ) && ! F_39 ( V_12 , V_28 , V_22 ,
V_14 , V_3 ) )
goto V_31;
}
else
{
if ( ( V_22 != NULL ) && ! F_39 ( V_12 , V_29 , V_22 ,
V_14 , V_3 ) )
goto V_31;
}
if ( ( V_23 != NULL ) && ! F_39 ( V_12 , L_12 , V_23 ,
V_14 , V_3 ) ) goto V_31;
if ( ( V_24 != NULL ) && ! F_39 ( V_12 , L_13 , V_24 ,
V_14 , V_3 ) ) goto V_31;
if ( V_25 && ! F_40 ( V_12 , L_14 , V_25 , V_26 , V_3 ) )
goto V_31;
}
V_5 = 1 ;
V_31:
if ( ! V_5 )
F_4 ( V_42 , V_17 ) ;
if ( V_20 )
F_41 ( V_20 ) ;
if ( V_21 )
F_41 ( V_21 ) ;
if ( V_4 )
F_41 ( V_4 ) ;
if ( V_22 )
F_41 ( V_22 ) ;
if ( V_23 )
F_41 ( V_23 ) ;
if ( V_24 )
F_41 ( V_24 ) ;
if ( V_18 )
F_42 ( V_18 ) ;
if ( V_14 != NULL )
F_43 ( V_14 ) ;
return ( V_5 ) ;
}
static int F_40 ( T_3 * V_1 , const char * V_43 , const unsigned char * V_44 ,
T_6 V_45 , int V_3 )
{
T_6 V_16 ;
char V_46 [ 128 ] ;
if ( V_44 == NULL )
return 1 ;
if ( V_3 )
{
if ( V_3 > 128 )
V_3 = 128 ;
memset ( V_46 , ' ' , V_3 ) ;
if ( F_44 ( V_1 , V_46 , V_3 ) <= 0 )
return 0 ;
}
if ( F_21 ( V_1 , L_15 , V_43 ) <= 0 )
return 0 ;
for ( V_16 = 0 ; V_16 < V_45 ; V_16 ++ )
{
if ( ( V_16 % 15 ) == 0 )
{
V_46 [ 0 ] = '\n' ;
memset ( & ( V_46 [ 1 ] ) , ' ' , V_3 + 4 ) ;
if ( F_44 ( V_1 , V_46 , V_3 + 1 + 4 ) <= 0 )
return 0 ;
}
if ( F_21 ( V_1 , L_16 , V_44 [ V_16 ] , ( ( V_16 + 1 ) == V_45 ) ? L_17 : L_18 ) <= 0 )
return 0 ;
}
if ( F_44 ( V_1 , L_5 , 1 ) <= 0 )
return 0 ;
return 1 ;
}
