T_1 * F_1 ( const unsigned char * V_1 , int V_2 , T_2 * V_3 )
{
T_3 * V_4 = NULL , * V_5 = NULL , * V_6 = NULL ;
T_3 V_7 ;
T_3 V_8 ;
T_4 * V_9 = NULL ;
int V_10 , V_11 = V_12 ;
T_1 * V_13 = NULL ;
F_2 ( & V_7 ) ;
F_2 ( & V_8 ) ;
V_6 = F_3 () ;
if ( V_6 == NULL ) goto V_14;
V_10 = F_4 ( V_3 -> V_15 ) ;
if ( ( V_2 > V_10 ) || ( V_2 > 50 ) )
{
V_11 = V_16 ;
goto V_14;
}
V_9 = F_5 () ;
if ( V_9 == NULL ) goto V_14;
if ( ( V_3 -> V_4 == NULL ) || ( V_3 -> V_5 == NULL ) )
{
if ( ! F_6 ( V_3 , V_9 , & V_4 , & V_5 ) ) goto V_14;
}
else
{
V_4 = V_3 -> V_4 ;
V_3 -> V_4 = NULL ;
V_5 = V_3 -> V_5 ;
V_3 -> V_5 = NULL ;
}
if ( F_7 ( V_1 , V_2 , & V_7 ) == NULL ) goto V_14;
if ( ! F_8 ( & V_8 , V_3 -> V_17 , V_5 , V_3 -> V_15 , V_9 ) ) goto V_14;
if ( ! F_9 ( V_6 , & V_8 , & V_7 ) ) goto V_14;
if ( F_10 ( V_6 , V_3 -> V_15 ) > 0 )
F_11 ( V_6 , V_6 , V_3 -> V_15 ) ;
if ( ! F_8 ( V_6 , V_6 , V_4 , V_3 -> V_15 , V_9 ) ) goto V_14;
V_13 = F_12 () ;
if ( V_13 == NULL ) goto V_14;
V_13 -> V_5 = V_5 ;
V_13 -> V_6 = V_6 ;
V_14:
if ( ! V_13 )
{
F_13 ( V_18 , V_11 ) ;
F_14 ( V_5 ) ;
F_14 ( V_6 ) ;
}
if ( V_9 != NULL ) F_15 ( V_9 ) ;
F_16 ( & V_7 ) ;
F_16 ( & V_8 ) ;
if ( V_4 != NULL )
F_16 ( V_4 ) ;
return ( V_13 ) ;
}
int F_17 ( int type , const unsigned char * V_1 , int V_2 , unsigned char * V_19 ,
unsigned int * V_20 , T_2 * V_3 )
{
T_1 * V_6 ;
V_6 = F_1 ( V_1 , V_2 , V_3 ) ;
if ( V_6 == NULL )
{
* V_20 = 0 ;
return ( 0 ) ;
}
* V_20 = F_18 ( V_6 , & V_19 ) ;
F_19 ( V_6 ) ;
return ( 1 ) ;
}
int F_6 ( T_2 * V_3 , T_4 * V_21 , T_3 * * V_22 , T_3 * * V_23 )
{
T_4 * V_9 ;
T_3 V_24 , * V_4 = NULL , * V_5 = NULL ;
int V_13 = 0 ;
if ( V_21 == NULL )
{
if ( ( V_9 = F_5 () ) == NULL ) goto V_14;
}
else
V_9 = V_21 ;
F_2 ( & V_24 ) ;
if ( ( V_5 = F_3 () ) == NULL ) goto V_14;
V_4 = NULL ;
for (; ; )
{
if ( ! F_20 ( & V_24 , F_21 ( V_3 -> V_15 ) , 1 , 0 ) ) goto V_14;
if ( F_10 ( & V_24 , V_3 -> V_15 ) >= 0 )
F_11 ( & V_24 , & V_24 , V_3 -> V_15 ) ;
if ( ! F_22 ( & V_24 ) ) break;
}
if ( ( V_3 -> V_25 == NULL ) && ( V_3 -> V_26 & V_27 ) )
{
if ( ( V_3 -> V_25 = ( char * ) F_23 () ) != NULL )
if ( ! F_24 ( ( V_28 * ) V_3 -> V_25 ,
V_3 -> V_29 , V_9 ) ) goto V_14;
}
if ( ! F_25 ( V_5 , V_3 -> V_30 , & V_24 , V_3 -> V_29 , V_9 ,
( V_28 * ) V_3 -> V_25 ) ) goto V_14;
if ( ! F_26 ( V_5 , V_5 , V_3 -> V_15 , V_9 ) ) goto V_14;
if ( ( V_4 = F_27 ( NULL , & V_24 , V_3 -> V_15 , V_9 ) ) == NULL ) goto V_14;
if ( * V_22 != NULL ) F_16 ( * V_22 ) ;
* V_22 = V_4 ;
V_4 = NULL ;
if ( * V_23 != NULL ) F_16 ( * V_23 ) ;
* V_23 = V_5 ;
V_13 = 1 ;
V_14:
if ( ! V_13 )
{
F_13 ( V_31 , V_12 ) ;
if ( V_4 != NULL ) F_16 ( V_4 ) ;
if ( V_5 != NULL ) F_16 ( V_5 ) ;
}
if ( V_21 == NULL ) F_15 ( V_9 ) ;
if ( V_4 != NULL ) F_16 ( V_4 ) ;
F_16 ( & V_24 ) ;
return ( V_13 ) ;
}
