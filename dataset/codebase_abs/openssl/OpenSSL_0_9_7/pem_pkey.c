T_1 * F_1 ( T_2 * V_1 , T_1 * * V_2 , T_3 * V_3 , void * V_4 )
{
char * V_5 = NULL ;
unsigned char * V_6 = NULL , * V_7 = NULL ;
long V_8 ;
T_1 * V_9 = NULL ;
if ( ! F_2 ( & V_7 , & V_8 , & V_5 , V_10 , V_1 , V_3 , V_4 ) )
return NULL ;
V_6 = V_7 ;
if ( strcmp ( V_5 , V_11 ) == 0 )
V_9 = F_3 ( V_12 , V_2 , & V_6 , V_8 ) ;
else if ( strcmp ( V_5 , V_13 ) == 0 )
V_9 = F_3 ( V_14 , V_2 , & V_6 , V_8 ) ;
else if ( strcmp ( V_5 , V_15 ) == 0 ) {
T_4 * V_16 ;
V_16 = F_4 ( NULL , & V_6 , V_8 ) ;
if( ! V_16 ) goto V_17;
V_9 = F_5 ( V_16 ) ;
F_6 ( V_16 ) ;
} else if ( strcmp ( V_5 , V_18 ) == 0 ) {
T_4 * V_16 ;
T_5 * V_19 ;
int V_20 ;
char V_21 [ V_22 ] ;
V_19 = F_7 ( NULL , & V_6 , V_8 ) ;
if( ! V_19 ) goto V_17;
if ( V_3 ) V_20 = V_3 ( V_21 , V_22 , 0 , V_4 ) ;
else V_20 = F_8 ( V_21 , V_22 , 0 , V_4 ) ;
if ( V_20 <= 0 ) {
F_9 ( V_23 ,
V_24 ) ;
goto V_25;
}
V_16 = F_10 ( V_19 , V_21 , V_20 ) ;
F_11 ( V_19 ) ;
if( ! V_16 ) goto V_17;
V_9 = F_5 ( V_16 ) ;
if( V_2 ) {
if( * V_2 ) F_12 ( ( T_1 * ) * V_2 ) ;
* V_2 = V_9 ;
}
F_6 ( V_16 ) ;
}
V_17:
if ( V_9 == NULL )
F_9 ( V_23 , V_26 ) ;
V_25:
F_13 ( V_5 ) ;
F_13 ( V_7 ) ;
return ( V_9 ) ;
}
T_1 * F_14 ( T_6 * V_27 , T_1 * * V_2 , T_3 * V_3 , void * V_4 )
{
T_2 * V_28 ;
T_1 * V_9 ;
if ( ( V_28 = F_15 ( F_16 () ) ) == NULL )
{
F_9 ( V_29 , V_30 ) ;
return ( 0 ) ;
}
F_17 ( V_28 , V_27 , V_31 ) ;
V_9 = F_1 ( V_28 , V_2 , V_3 , V_4 ) ;
F_18 ( V_28 ) ;
return ( V_9 ) ;
}
