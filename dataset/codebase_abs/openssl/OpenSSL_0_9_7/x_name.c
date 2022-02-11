static int F_1 ( T_1 * * V_1 , const T_2 * V_2 )
{
T_3 * V_3 = NULL ;
V_3 = F_2 ( sizeof( T_3 ) ) ;
if( ! V_3 ) goto V_4;
if ( ( V_3 -> V_5 = F_3 () ) == NULL )
goto V_4;
if( ( V_3 -> V_6 = F_4 () ) == NULL ) goto V_4;
V_3 -> V_7 = 1 ;
* V_1 = ( T_1 * ) V_3 ;
return 1 ;
V_4:
F_5 ( V_8 , V_9 ) ;
if ( V_3 )
{
if ( V_3 -> V_5 )
F_6 ( V_3 -> V_5 ) ;
F_7 ( V_3 ) ;
}
return 0 ;
}
static void F_8 ( T_1 * * V_10 , const T_2 * V_2 )
{
T_3 * V_11 ;
if( ! V_10 || ! * V_10 )
return;
V_11 = ( T_3 * ) * V_10 ;
F_9 ( V_11 -> V_6 ) ;
F_10 ( V_11 -> V_5 , V_12 ) ;
F_7 ( V_11 ) ;
* V_10 = NULL ;
}
static void F_11 ( void * V_11 )
{
F_12 ( V_11 ) ;
}
static int F_13 ( T_1 * * V_1 , unsigned char * * V_13 , long V_14 , const T_2 * V_2 ,
int V_15 , int V_16 , char V_17 , T_4 * V_18 )
{
unsigned char * V_19 = * V_13 , * V_20 ;
T_5 * V_21 = NULL ;
int V_22 , V_23 , V_3 ;
T_3 * V_24 = NULL ;
F_14 ( V_25 ) * V_5 ;
V_25 * V_26 ;
V_20 = V_19 ;
V_3 = F_15 ( ( T_1 * * ) & V_21 , & V_19 , V_14 , F_16 ( V_27 ) ,
V_15 , V_16 , V_17 , V_18 ) ;
if( V_3 <= 0 ) return V_3 ;
if( * V_1 ) F_8 ( V_1 , NULL ) ;
if( ! F_1 ( ( T_1 * * ) & V_24 , NULL ) ) goto V_28;
if( ! F_17 ( V_24 -> V_6 , V_19 - V_20 ) ) goto V_28;
memcpy ( V_24 -> V_6 -> V_29 , V_20 , V_19 - V_20 ) ;
for( V_22 = 0 ; V_22 < F_18 ( V_21 ) ; V_22 ++ ) {
V_5 = ( F_14 ( V_25 ) * ) F_19 ( V_21 , V_22 ) ;
for( V_23 = 0 ; V_23 < F_20 ( V_5 ) ; V_23 ++ ) {
V_26 = F_21 ( V_5 , V_23 ) ;
V_26 -> V_30 = V_22 ;
if( ! F_22 ( V_24 -> V_5 , V_26 ) )
goto V_28;
}
F_6 ( V_5 ) ;
}
F_12 ( V_21 ) ;
V_24 -> V_7 = 0 ;
* V_1 = ( T_1 * ) V_24 ;
* V_13 = V_19 ;
return V_3 ;
V_28:
F_5 ( V_31 , V_32 ) ;
return 0 ;
}
static int F_23 ( T_1 * * V_1 , unsigned char * * V_33 , const T_2 * V_2 , int V_15 , int V_16 )
{
int V_3 ;
T_3 * V_11 = ( T_3 * ) * V_1 ;
if( V_11 -> V_7 ) {
V_3 = F_24 ( ( T_3 * ) V_11 ) ;
if( V_3 < 0 ) return V_3 ;
}
V_3 = V_11 -> V_6 -> V_34 ;
if( V_33 != NULL ) {
memcpy ( * V_33 , V_11 -> V_6 -> V_29 , V_3 ) ;
* V_33 += V_3 ;
}
return V_3 ;
}
static int F_24 ( T_3 * V_11 )
{
T_5 * V_21 = NULL ;
int V_14 ;
unsigned char * V_19 ;
F_14 ( V_25 ) * V_5 = NULL ;
V_25 * V_26 ;
int V_22 , V_30 = - 1 ;
V_21 = F_25 () ;
if( ! V_21 ) goto V_4;
for( V_22 = 0 ; V_22 < F_20 ( V_11 -> V_5 ) ; V_22 ++ ) {
V_26 = F_21 ( V_11 -> V_5 , V_22 ) ;
if( V_26 -> V_30 != V_30 ) {
V_5 = F_3 () ;
if( ! V_5 ) goto V_4;
if( ! F_26 ( V_21 , ( char * ) V_5 ) ) goto V_4;
V_30 = V_26 -> V_30 ;
}
if( ! F_22 ( V_5 , V_26 ) ) goto V_4;
}
V_14 = F_27 ( ( T_1 * * ) & V_21 , NULL , F_16 ( V_27 ) , - 1 , - 1 ) ;
if ( ! F_17 ( V_11 -> V_6 , V_14 ) ) goto V_4;
V_19 = ( unsigned char * ) V_11 -> V_6 -> V_29 ;
F_27 ( ( T_1 * * ) & V_21 , & V_19 , F_16 ( V_27 ) , - 1 , - 1 ) ;
F_28 ( V_21 , F_11 ) ;
V_11 -> V_7 = 0 ;
return V_14 ;
V_4:
F_28 ( V_21 , F_11 ) ;
F_5 ( V_31 , V_9 ) ;
return - 1 ;
}
int F_29 ( T_3 * * V_35 , T_3 * V_36 )
{
T_3 * V_13 ;
if ( ! V_35 || ! V_36 ) return ( 0 ) ;
if ( * V_35 != V_36 )
{
V_13 = F_30 ( V_36 ) ;
if ( V_13 != NULL )
{
F_31 ( * V_35 ) ;
* V_35 = V_13 ;
}
}
return ( * V_35 != NULL ) ;
}
