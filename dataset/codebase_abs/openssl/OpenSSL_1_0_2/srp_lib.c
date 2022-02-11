static T_1 * F_1 ( T_1 * V_1 , T_1 * V_2 )
{
unsigned char V_3 [ V_4 ] ;
unsigned char * V_5 ;
T_2 V_6 ;
int V_7 ;
int V_8 = F_2 ( V_1 ) ;
if ( F_3 ( V_2 , V_1 ) >= 0 )
return NULL ;
if ( ( V_5 = F_4 ( V_8 ) ) == NULL )
return NULL ;
F_5 ( V_1 , V_5 ) ;
F_6 ( & V_6 ) ;
F_7 ( & V_6 , F_8 () , NULL ) ;
F_9 ( & V_6 , V_5 , V_8 ) ;
memset ( V_5 , 0 , V_8 ) ;
V_7 = F_5 ( V_2 , V_5 ) ;
F_9 ( & V_6 , V_5 + V_7 , V_8 - V_7 ) ;
F_9 ( & V_6 , V_5 , V_7 ) ;
F_10 ( V_5 ) ;
F_11 ( & V_6 , V_3 , NULL ) ;
F_12 ( & V_6 ) ;
return F_13 ( V_3 , sizeof( V_3 ) , NULL ) ;
}
T_1 * F_14 ( T_1 * V_9 , T_1 * V_10 , T_1 * V_1 )
{
T_1 * V_11 ;
unsigned char V_12 [ V_4 ] ;
unsigned char * V_13 ;
T_2 V_6 ;
int V_8 ;
if ( ( V_9 == NULL ) || ( V_10 == NULL ) || ( V_1 == NULL ) )
return NULL ;
if ( F_3 ( V_9 , V_1 ) >= 0 || F_3 ( V_10 , V_1 ) >= 0 )
return NULL ;
V_8 = F_2 ( V_1 ) ;
if ( ( V_13 = F_4 ( 2 * V_8 ) ) == NULL )
return NULL ;
memset ( V_13 , 0 , V_8 ) ;
F_6 ( & V_6 ) ;
F_7 ( & V_6 , F_8 () , NULL ) ;
F_9 ( & V_6 , V_13 + F_5 ( V_9 , V_13 + V_8 ) , V_8 ) ;
F_9 ( & V_6 , V_13 + F_5 ( V_10 , V_13 + V_8 ) , V_8 ) ;
F_10 ( V_13 ) ;
F_11 ( & V_6 , V_12 , NULL ) ;
F_12 ( & V_6 ) ;
if ( ! ( V_11 = F_13 ( V_12 , sizeof( V_12 ) , NULL ) ) )
return NULL ;
if ( ! F_15 ( V_11 ) )
return V_11 ;
F_16 ( V_11 ) ;
return NULL ;
}
T_1 * F_17 ( T_1 * V_9 , T_1 * V_14 , T_1 * V_11 , T_1 * V_15 ,
T_1 * V_1 )
{
T_1 * V_5 = NULL , * V_16 = NULL ;
T_3 * V_17 ;
if ( V_11 == NULL || V_9 == NULL || V_14 == NULL || V_15 == NULL || V_1 == NULL )
return NULL ;
if ( ( V_17 = F_18 () ) == NULL ||
( V_5 = F_19 () ) == NULL || ( V_16 = F_19 () ) == NULL )
goto V_18;
if ( ! F_20 ( V_5 , V_14 , V_11 , V_1 , V_17 ) )
goto V_18;
if ( ! F_21 ( V_5 , V_9 , V_5 , V_1 , V_17 ) )
goto V_18;
if ( ! F_20 ( V_16 , V_5 , V_15 , V_1 , V_17 ) )
goto V_18;
V_18:
F_22 ( V_17 ) ;
F_23 ( V_5 ) ;
return V_16 ;
}
T_1 * F_24 ( T_1 * V_15 , T_1 * V_1 , T_1 * V_2 , T_1 * V_14 )
{
T_1 * V_19 = NULL , * V_20 = NULL ;
T_1 * V_10 = NULL , * V_21 = NULL ;
T_3 * V_17 ;
if ( V_15 == NULL || V_1 == NULL || V_2 == NULL || V_14 == NULL ||
( V_17 = F_18 () ) == NULL )
return NULL ;
if ( ( V_19 = F_19 () ) == NULL ||
( V_20 = F_19 () ) == NULL || ( V_10 = F_19 () ) == NULL )
goto V_18;
if ( ! F_20 ( V_20 , V_2 , V_15 , V_1 , V_17 ) ||
! ( V_21 = F_1 ( V_1 , V_2 ) ) ||
! F_21 ( V_19 , V_14 , V_21 , V_1 , V_17 ) ||
! F_25 ( V_10 , V_20 , V_19 , V_1 , V_17 ) ) {
F_16 ( V_10 ) ;
V_10 = NULL ;
}
V_18:
F_22 ( V_17 ) ;
F_23 ( V_19 ) ;
F_23 ( V_20 ) ;
F_16 ( V_21 ) ;
return V_10 ;
}
T_1 * F_26 ( T_1 * V_22 , const char * V_23 , const char * V_24 )
{
unsigned char V_25 [ V_4 ] ;
T_2 V_6 ;
unsigned char * V_26 ;
if ( ( V_22 == NULL ) || ( V_23 == NULL ) || ( V_24 == NULL ) )
return NULL ;
if ( ( V_26 = F_4 ( F_2 ( V_22 ) ) ) == NULL )
return NULL ;
F_6 ( & V_6 ) ;
F_7 ( & V_6 , F_8 () , NULL ) ;
F_9 ( & V_6 , V_23 , strlen ( V_23 ) ) ;
F_9 ( & V_6 , L_1 , 1 ) ;
F_9 ( & V_6 , V_24 , strlen ( V_24 ) ) ;
F_11 ( & V_6 , V_25 , NULL ) ;
F_7 ( & V_6 , F_8 () , NULL ) ;
F_5 ( V_22 , V_26 ) ;
F_9 ( & V_6 , V_26 , F_2 ( V_22 ) ) ;
F_10 ( V_26 ) ;
F_9 ( & V_6 , V_25 , sizeof( V_25 ) ) ;
F_11 ( & V_6 , V_25 , NULL ) ;
F_12 ( & V_6 ) ;
return F_13 ( V_25 , sizeof( V_25 ) , NULL ) ;
}
T_1 * F_27 ( T_1 * V_27 , T_1 * V_1 , T_1 * V_2 )
{
T_3 * V_17 ;
T_1 * V_9 = NULL ;
if ( V_27 == NULL || V_1 == NULL || V_2 == NULL ||
( V_17 = F_18 () ) == NULL )
return NULL ;
if ( ( V_9 = F_19 () ) != NULL && ! F_20 ( V_9 , V_2 , V_27 , V_1 , V_17 ) ) {
F_16 ( V_9 ) ;
V_9 = NULL ;
}
F_22 ( V_17 ) ;
return V_9 ;
}
T_1 * F_28 ( T_1 * V_1 , T_1 * V_10 , T_1 * V_2 , T_1 * V_28 ,
T_1 * V_27 , T_1 * V_11 )
{
T_1 * V_5 = NULL , * V_29 = NULL , * V_30 = NULL , * V_21 = NULL , * V_31 = NULL ;
T_3 * V_17 ;
if ( V_11 == NULL || V_10 == NULL || V_1 == NULL || V_2 == NULL || V_28 == NULL
|| V_27 == NULL || ( V_17 = F_18 () ) == NULL )
return NULL ;
if ( ( V_5 = F_19 () ) == NULL ||
( V_29 = F_19 () ) == NULL ||
( V_30 = F_19 () ) == NULL || ( V_31 = F_19 () ) == NULL )
goto V_18;
if ( ! F_20 ( V_5 , V_2 , V_28 , V_1 , V_17 ) )
goto V_18;
if ( ! ( V_21 = F_1 ( V_1 , V_2 ) ) )
goto V_18;
if ( ! F_21 ( V_29 , V_5 , V_21 , V_1 , V_17 ) )
goto V_18;
if ( ! F_29 ( V_5 , V_10 , V_29 , V_1 , V_17 ) )
goto V_18;
if ( ! F_21 ( V_30 , V_11 , V_28 , V_1 , V_17 ) )
goto V_18;
if ( ! F_25 ( V_29 , V_27 , V_30 , V_1 , V_17 ) )
goto V_18;
if ( ! F_20 ( V_31 , V_5 , V_29 , V_1 , V_17 ) )
goto V_18;
V_18:
F_22 ( V_17 ) ;
F_23 ( V_5 ) ;
F_23 ( V_29 ) ;
F_23 ( V_30 ) ;
F_16 ( V_21 ) ;
return V_31 ;
}
int F_30 ( T_1 * V_10 , T_1 * V_1 )
{
T_1 * V_32 ;
T_3 * V_17 ;
int V_33 = 0 ;
if ( V_10 == NULL || V_1 == NULL || ( V_17 = F_18 () ) == NULL )
return 0 ;
if ( ( V_32 = F_19 () ) == NULL )
goto V_18;
if ( ! F_31 ( V_32 , V_10 , V_1 , V_17 ) )
goto V_18;
V_33 = ! F_15 ( V_32 ) ;
V_18:
F_22 ( V_17 ) ;
F_16 ( V_32 ) ;
return V_33 ;
}
int F_32 ( T_1 * V_9 , T_1 * V_1 )
{
return F_30 ( V_9 , V_1 ) ;
}
char * F_33 ( T_1 * V_2 , T_1 * V_1 )
{
T_4 V_34 ;
if ( ( V_2 == NULL ) || ( V_1 == NULL ) )
return 0 ;
F_34 ( V_2 ) ;
F_34 ( V_1 ) ;
for ( V_34 = 0 ; V_34 < V_35 ; V_34 ++ ) {
if ( F_35 ( V_36 [ V_34 ] . V_2 , V_2 ) == 0 && F_35 ( V_36 [ V_34 ] . V_1 , V_1 ) == 0 )
return V_36 [ V_34 ] . V_37 ;
}
return NULL ;
}
T_5 * F_36 ( const char * V_37 )
{
T_4 V_34 ;
if ( V_37 == NULL )
return V_36 ;
for ( V_34 = 0 ; V_34 < V_35 ; V_34 ++ ) {
if ( strcmp ( V_36 [ V_34 ] . V_37 , V_37 ) == 0 )
return V_36 + V_34 ;
}
return NULL ;
}
