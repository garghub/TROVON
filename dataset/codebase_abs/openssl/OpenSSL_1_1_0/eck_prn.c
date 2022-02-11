int F_1 ( T_1 * V_1 , const T_2 * V_2 , int V_3 )
{
T_3 * V_4 ;
int V_5 ;
if ( ( V_4 = F_2 ( F_3 () ) ) == NULL ) {
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
if ( ( V_4 = F_2 ( F_3 () ) ) == NULL ) {
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
if ( ( V_4 = F_2 ( F_3 () ) ) == NULL ) {
F_4 ( V_11 , V_10 ) ;
return ( 0 ) ;
}
F_5 ( V_4 , V_1 , V_8 ) ;
V_5 = F_11 ( V_4 , V_2 ) ;
F_7 ( V_4 ) ;
return ( V_5 ) ;
}
int F_6 ( T_3 * V_12 , const T_2 * V_2 , int V_3 )
{
int V_5 = 0 , V_13 = V_10 ;
T_5 * V_14 = NULL ;
const T_6 * V_15 = NULL ;
T_7 * V_16 = NULL , * V_17 = NULL , * V_4 = NULL , * V_18 = NULL ;
const T_7 * V_19 = NULL , * V_20 = NULL ;
const unsigned char * V_21 ;
T_8 V_22 = 0 ;
static const char * V_23 = L_1 ;
static const char * V_24 = L_2 ;
static const char * V_25 = L_3 ;
if ( ! V_2 ) {
V_13 = V_26 ;
goto V_27;
}
V_14 = F_12 () ;
if ( V_14 == NULL ) {
V_13 = V_28 ;
goto V_27;
}
if ( F_13 ( V_2 ) ) {
int V_29 ;
const char * V_30 ;
if ( ! F_14 ( V_12 , V_3 , 128 ) )
goto V_27;
V_29 = F_15 ( V_2 ) ;
if ( V_29 == 0 )
goto V_27;
if ( F_16 ( V_12 , L_4 , F_17 ( V_29 ) ) <= 0 )
goto V_27;
if ( F_16 ( V_12 , L_5 ) <= 0 )
goto V_27;
V_30 = F_18 ( V_29 ) ;
if ( V_30 ) {
if ( ! F_14 ( V_12 , V_3 , 128 ) )
goto V_27;
if ( F_16 ( V_12 , L_6 , V_30 ) <= 0 )
goto V_27;
}
} else {
int V_31 = 0 ;
T_9 V_32 ;
int V_33 = F_19 ( F_20 ( V_2 ) ) ;
if ( V_33 == V_34 )
V_31 = 1 ;
if ( ( V_16 = F_21 () ) == NULL || ( V_17 = F_21 () ) == NULL ||
( V_4 = F_21 () ) == NULL ) {
V_13 = V_28 ;
goto V_27;
}
#ifndef F_22
if ( V_31 ) {
if ( ! F_23 ( V_2 , V_16 , V_17 , V_4 , V_14 ) ) {
V_13 = V_35 ;
goto V_27;
}
} else
#endif
{
if ( ! F_24 ( V_2 , V_16 , V_17 , V_4 , V_14 ) ) {
V_13 = V_35 ;
goto V_27;
}
}
if ( ( V_15 = F_25 ( V_2 ) ) == NULL ) {
V_13 = V_35 ;
goto V_27;
}
V_19 = F_26 ( V_2 ) ;
V_20 = F_27 ( V_2 ) ;
if ( V_19 == NULL ) {
V_13 = V_35 ;
goto V_27;
}
V_32 = F_28 ( V_2 ) ;
if ( ( V_18 = F_29 ( V_2 , V_15 , V_32 , NULL , V_14 ) ) == NULL ) {
V_13 = V_35 ;
goto V_27;
}
if ( ( V_21 = F_30 ( V_2 ) ) != NULL )
V_22 = F_31 ( V_2 ) ;
if ( ! F_14 ( V_12 , V_3 , 128 ) )
goto V_27;
if ( F_16 ( V_12 , L_7 , F_17 ( V_33 ) )
<= 0 )
goto V_27;
if ( V_31 ) {
int V_36 = F_32 ( V_2 ) ;
if ( V_36 == 0 )
goto V_27;
if ( ! F_14 ( V_12 , V_3 , 128 ) )
goto V_27;
if ( F_16 ( V_12 , L_8 ,
F_17 ( V_36 ) ) <= 0 )
goto V_27;
if ( ( V_16 != NULL ) && ! F_33 ( V_12 , L_9 , V_16 , NULL ,
V_3 ) )
goto V_27;
} else {
if ( ( V_16 != NULL ) && ! F_33 ( V_12 , L_10 , V_16 , NULL , V_3 ) )
goto V_27;
}
if ( ( V_17 != NULL ) && ! F_33 ( V_12 , L_11 , V_17 , NULL , V_3 ) )
goto V_27;
if ( ( V_4 != NULL ) && ! F_33 ( V_12 , L_12 , V_4 , NULL , V_3 ) )
goto V_27;
if ( V_32 == V_37 ) {
if ( ( V_18 != NULL ) && ! F_33 ( V_12 , V_23 , V_18 ,
NULL , V_3 ) )
goto V_27;
} else if ( V_32 == V_38 ) {
if ( ( V_18 != NULL ) && ! F_33 ( V_12 , V_24 , V_18 ,
NULL , V_3 ) )
goto V_27;
} else {
if ( ( V_18 != NULL ) && ! F_33 ( V_12 , V_25 , V_18 ,
NULL , V_3 ) )
goto V_27;
}
if ( ( V_19 != NULL ) && ! F_33 ( V_12 , L_13 , V_19 ,
NULL , V_3 ) )
goto V_27;
if ( ( V_20 != NULL ) && ! F_33 ( V_12 , L_14 , V_20 ,
NULL , V_3 ) )
goto V_27;
if ( V_21 && ! F_34 ( V_12 , L_15 , V_21 , V_22 , V_3 ) )
goto V_27;
}
V_5 = 1 ;
V_27:
if ( ! V_5 )
F_4 ( V_39 , V_13 ) ;
F_35 ( V_16 ) ;
F_35 ( V_17 ) ;
F_35 ( V_4 ) ;
F_35 ( V_18 ) ;
F_36 ( V_14 ) ;
return ( V_5 ) ;
}
static int F_34 ( T_3 * V_1 , const char * V_40 , const unsigned char * V_41 ,
T_8 V_42 , int V_3 )
{
T_8 V_43 ;
char V_44 [ 128 ] ;
if ( V_41 == NULL )
return 1 ;
if ( V_3 > 0 ) {
if ( V_3 > 128 )
V_3 = 128 ;
memset ( V_44 , ' ' , V_3 ) ;
if ( F_37 ( V_1 , V_44 , V_3 ) <= 0 )
return 0 ;
} else {
V_3 = 0 ;
}
if ( F_16 ( V_1 , L_16 , V_40 ) <= 0 )
return 0 ;
for ( V_43 = 0 ; V_43 < V_42 ; V_43 ++ ) {
if ( ( V_43 % 15 ) == 0 ) {
V_44 [ 0 ] = '\n' ;
memset ( & ( V_44 [ 1 ] ) , ' ' , V_3 + 4 ) ;
if ( F_37 ( V_1 , V_44 , V_3 + 1 + 4 ) <= 0 )
return 0 ;
}
if ( F_16 ( V_1 , L_17 , V_41 [ V_43 ] , ( ( V_43 + 1 ) == V_42 ) ? L_18 : L_19 ) <=
0 )
return 0 ;
}
if ( F_37 ( V_1 , L_5 , 1 ) <= 0 )
return 0 ;
return 1 ;
}
