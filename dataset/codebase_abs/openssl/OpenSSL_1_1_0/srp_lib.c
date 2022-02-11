static T_1 * F_1 ( const T_1 * V_1 , const T_1 * V_2 )
{
unsigned char V_3 [ V_4 ] ;
unsigned char * V_5 = NULL ;
T_2 * V_6 = NULL ;
int V_7 ;
int V_8 = F_2 ( V_1 ) ;
T_1 * V_9 = NULL ;
if ( F_3 ( V_2 , V_1 ) >= 0 )
return NULL ;
V_6 = F_4 () ;
if ( V_6 == NULL )
return NULL ;
if ( ( V_5 = F_5 ( V_8 ) ) == NULL )
goto V_10;
F_6 ( V_1 , V_5 ) ;
if ( ! F_7 ( V_6 , F_8 () , NULL )
|| ! F_9 ( V_6 , V_5 , V_8 ) )
goto V_10;
memset ( V_5 , 0 , V_8 ) ;
V_7 = F_6 ( V_2 , V_5 ) ;
if ( ! F_9 ( V_6 , V_5 + V_7 , V_8 - V_7 )
|| ! F_9 ( V_6 , V_5 , V_7 ) )
goto V_10;
if ( ! F_10 ( V_6 , V_3 , NULL ) )
goto V_10;
V_9 = F_11 ( V_3 , sizeof( V_3 ) , NULL ) ;
V_10:
F_12 ( V_5 ) ;
F_13 ( V_6 ) ;
return V_9 ;
}
T_1 * F_14 ( const T_1 * V_11 , const T_1 * V_12 , const T_1 * V_1 )
{
T_1 * V_13 = NULL ;
unsigned char V_14 [ V_4 ] ;
unsigned char * V_15 = NULL ;
T_2 * V_6 = NULL ;
int V_8 ;
if ( ( V_11 == NULL ) || ( V_12 == NULL ) || ( V_1 == NULL ) )
return NULL ;
if ( F_3 ( V_11 , V_1 ) >= 0 || F_3 ( V_12 , V_1 ) >= 0 )
return NULL ;
V_8 = F_2 ( V_1 ) ;
V_6 = F_4 () ;
if ( V_6 == NULL )
return NULL ;
if ( ( V_15 = F_5 ( 2 * V_8 ) ) == NULL )
goto V_10;
memset ( V_15 , 0 , V_8 ) ;
if ( ! F_7 ( V_6 , F_8 () , NULL )
|| ! F_9 ( V_6 , V_15 + F_6 ( V_11 , V_15 + V_8 ) , V_8 )
|| ! F_9 ( V_6 , V_15 + F_6 ( V_12 , V_15 + V_8 ) , V_8 ) )
goto V_10;
if ( ! F_10 ( V_6 , V_14 , NULL ) )
goto V_10;
if ( ( V_13 = F_11 ( V_14 , sizeof( V_14 ) , NULL ) ) == NULL )
goto V_10;
if ( F_15 ( V_13 ) ) {
F_16 ( V_13 ) ;
V_13 = NULL ;
}
V_10:
F_12 ( V_15 ) ;
F_13 ( V_6 ) ;
return V_13 ;
}
T_1 * F_17 ( const T_1 * V_11 , const T_1 * V_16 , const T_1 * V_13 ,
const T_1 * V_17 , const T_1 * V_1 )
{
T_1 * V_5 = NULL , * V_18 = NULL ;
T_3 * V_19 ;
if ( V_13 == NULL || V_11 == NULL || V_16 == NULL || V_17 == NULL || V_1 == NULL )
return NULL ;
if ( ( V_19 = F_18 () ) == NULL || ( V_5 = F_19 () ) == NULL )
goto V_10;
if ( ! F_20 ( V_5 , V_16 , V_13 , V_1 , V_19 ) )
goto V_10;
if ( ! F_21 ( V_5 , V_11 , V_5 , V_1 , V_19 ) )
goto V_10;
V_18 = F_19 () ;
if ( V_18 != NULL && ! F_20 ( V_18 , V_5 , V_17 , V_1 , V_19 ) ) {
F_16 ( V_18 ) ;
V_18 = NULL ;
}
V_10:
F_22 ( V_19 ) ;
F_23 ( V_5 ) ;
return V_18 ;
}
T_1 * F_24 ( const T_1 * V_17 , const T_1 * V_1 , const T_1 * V_2 ,
const T_1 * V_16 )
{
T_1 * V_20 = NULL , * V_21 = NULL ;
T_1 * V_12 = NULL , * V_22 = NULL ;
T_3 * V_19 ;
if ( V_17 == NULL || V_1 == NULL || V_2 == NULL || V_16 == NULL ||
( V_19 = F_18 () ) == NULL )
return NULL ;
if ( ( V_20 = F_19 () ) == NULL ||
( V_21 = F_19 () ) == NULL || ( V_12 = F_19 () ) == NULL )
goto V_10;
if ( ! F_20 ( V_21 , V_2 , V_17 , V_1 , V_19 )
|| ( V_22 = F_1 ( V_1 , V_2 ) ) == NULL
|| ! F_21 ( V_20 , V_16 , V_22 , V_1 , V_19 )
|| ! F_25 ( V_12 , V_21 , V_20 , V_1 , V_19 ) ) {
F_16 ( V_12 ) ;
V_12 = NULL ;
}
V_10:
F_22 ( V_19 ) ;
F_23 ( V_20 ) ;
F_23 ( V_21 ) ;
F_16 ( V_22 ) ;
return V_12 ;
}
T_1 * F_26 ( const T_1 * V_23 , const char * V_24 , const char * V_25 )
{
unsigned char V_26 [ V_4 ] ;
T_2 * V_6 ;
unsigned char * V_27 = NULL ;
T_1 * V_9 = NULL ;
if ( ( V_23 == NULL ) || ( V_24 == NULL ) || ( V_25 == NULL ) )
return NULL ;
V_6 = F_4 () ;
if ( V_6 == NULL )
return NULL ;
if ( ( V_27 = F_5 ( F_2 ( V_23 ) ) ) == NULL )
goto V_10;
if ( ! F_7 ( V_6 , F_8 () , NULL )
|| ! F_9 ( V_6 , V_24 , strlen ( V_24 ) )
|| ! F_9 ( V_6 , L_1 , 1 )
|| ! F_9 ( V_6 , V_25 , strlen ( V_25 ) )
|| ! F_10 ( V_6 , V_26 , NULL )
|| ! F_7 ( V_6 , F_8 () , NULL ) )
goto V_10;
F_6 ( V_23 , V_27 ) ;
if ( ! F_9 ( V_6 , V_27 , F_2 ( V_23 ) ) )
goto V_10;
if ( ! F_9 ( V_6 , V_26 , sizeof( V_26 ) )
|| ! F_10 ( V_6 , V_26 , NULL ) )
goto V_10;
V_9 = F_11 ( V_26 , sizeof( V_26 ) , NULL ) ;
V_10:
F_12 ( V_27 ) ;
F_13 ( V_6 ) ;
return V_9 ;
}
T_1 * F_27 ( const T_1 * V_28 , const T_1 * V_1 , const T_1 * V_2 )
{
T_3 * V_19 ;
T_1 * V_11 = NULL ;
if ( V_28 == NULL || V_1 == NULL || V_2 == NULL || ( V_19 = F_18 () ) == NULL )
return NULL ;
if ( ( V_11 = F_19 () ) != NULL && ! F_20 ( V_11 , V_2 , V_28 , V_1 , V_19 ) ) {
F_16 ( V_11 ) ;
V_11 = NULL ;
}
F_22 ( V_19 ) ;
return V_11 ;
}
T_1 * F_28 ( const T_1 * V_1 , const T_1 * V_12 , const T_1 * V_2 ,
const T_1 * V_29 , const T_1 * V_28 , const T_1 * V_13 )
{
T_1 * V_5 = NULL , * V_30 = NULL , * V_31 = NULL , * V_22 = NULL , * V_32 = NULL ;
T_3 * V_19 ;
if ( V_13 == NULL || V_12 == NULL || V_1 == NULL || V_2 == NULL || V_29 == NULL
|| V_28 == NULL || ( V_19 = F_18 () ) == NULL )
return NULL ;
if ( ( V_5 = F_19 () ) == NULL ||
( V_30 = F_19 () ) == NULL ||
( V_31 = F_19 () ) == NULL )
goto V_10;
if ( ! F_20 ( V_5 , V_2 , V_29 , V_1 , V_19 ) )
goto V_10;
if ( ( V_22 = F_1 ( V_1 , V_2 ) ) == NULL )
goto V_10;
if ( ! F_21 ( V_30 , V_5 , V_22 , V_1 , V_19 ) )
goto V_10;
if ( ! F_29 ( V_5 , V_12 , V_30 , V_1 , V_19 ) )
goto V_10;
if ( ! F_30 ( V_31 , V_13 , V_29 , V_19 ) )
goto V_10;
if ( ! F_31 ( V_30 , V_28 , V_31 ) )
goto V_10;
V_32 = F_19 () ;
if ( V_32 != NULL && ! F_20 ( V_32 , V_5 , V_30 , V_1 , V_19 ) ) {
F_16 ( V_32 ) ;
V_32 = NULL ;
}
V_10:
F_22 ( V_19 ) ;
F_23 ( V_5 ) ;
F_23 ( V_30 ) ;
F_23 ( V_31 ) ;
F_16 ( V_22 ) ;
return V_32 ;
}
int F_32 ( const T_1 * V_12 , const T_1 * V_1 )
{
T_1 * V_33 ;
T_3 * V_19 ;
int V_34 = 0 ;
if ( V_12 == NULL || V_1 == NULL || ( V_19 = F_18 () ) == NULL )
return 0 ;
if ( ( V_33 = F_19 () ) == NULL )
goto V_10;
if ( ! F_33 ( V_33 , V_12 , V_1 , V_19 ) )
goto V_10;
V_34 = ! F_15 ( V_33 ) ;
V_10:
F_22 ( V_19 ) ;
F_16 ( V_33 ) ;
return V_34 ;
}
int F_34 ( const T_1 * V_11 , const T_1 * V_1 )
{
return F_32 ( V_11 , V_1 ) ;
}
char * F_35 ( const T_1 * V_2 , const T_1 * V_1 )
{
T_4 V_35 ;
if ( ( V_2 == NULL ) || ( V_1 == NULL ) )
return 0 ;
for ( V_35 = 0 ; V_35 < V_36 ; V_35 ++ ) {
if ( F_36 ( V_37 [ V_35 ] . V_2 , V_2 ) == 0 && F_36 ( V_37 [ V_35 ] . V_1 , V_1 ) == 0 )
return V_37 [ V_35 ] . V_38 ;
}
return NULL ;
}
T_5 * F_37 ( const char * V_38 )
{
T_4 V_35 ;
if ( V_38 == NULL )
return V_37 ;
for ( V_35 = 0 ; V_35 < V_36 ; V_35 ++ ) {
if ( strcmp ( V_37 [ V_35 ] . V_38 , V_38 ) == 0 )
return V_37 + V_35 ;
}
return NULL ;
}
