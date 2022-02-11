T_1 * F_1 ( T_2 * V_1 , T_1 * * V_2 , T_3 * V_3 , void * V_4 )
{
char * V_5 = NULL ;
const unsigned char * V_6 = NULL ;
unsigned char * V_7 = NULL ;
long V_8 ;
T_1 * V_9 = NULL ;
if ( ! F_2 ( & V_7 , & V_8 , & V_5 , V_10 , V_1 , V_3 , V_4 ) )
return NULL ;
V_6 = V_7 ;
if ( strcmp ( V_5 , V_11 ) == 0 )
V_9 = F_3 ( V_12 , V_2 , & V_6 , V_8 ) ;
else if ( strcmp ( V_5 , V_13 ) == 0 )
V_9 = F_3 ( V_14 , V_2 , & V_6 , V_8 ) ;
else if ( strcmp ( V_5 , V_15 ) == 0 )
V_9 = F_3 ( V_16 , V_2 , & V_6 , V_8 ) ;
else if ( strcmp ( V_5 , V_17 ) == 0 ) {
T_4 * V_18 ;
V_18 = F_4 ( NULL , & V_6 , V_8 ) ;
if( ! V_18 ) goto V_19;
V_9 = F_5 ( V_18 ) ;
if( V_2 ) {
if( * V_2 ) F_6 ( ( T_1 * ) * V_2 ) ;
* V_2 = V_9 ;
}
F_7 ( V_18 ) ;
} else if ( strcmp ( V_5 , V_20 ) == 0 ) {
T_4 * V_18 ;
T_5 * V_21 ;
int V_22 ;
char V_23 [ V_24 ] ;
V_21 = F_8 ( NULL , & V_6 , V_8 ) ;
if( ! V_21 ) goto V_19;
if ( V_3 ) V_22 = V_3 ( V_23 , V_24 , 0 , V_4 ) ;
else V_22 = F_9 ( V_23 , V_24 , 0 , V_4 ) ;
if ( V_22 <= 0 ) {
F_10 ( V_25 ,
V_26 ) ;
F_11 ( V_21 ) ;
goto V_27;
}
V_18 = F_12 ( V_21 , V_23 , V_22 ) ;
F_11 ( V_21 ) ;
if( ! V_18 ) goto V_19;
V_9 = F_5 ( V_18 ) ;
if( V_2 ) {
if( * V_2 ) F_6 ( ( T_1 * ) * V_2 ) ;
* V_2 = V_9 ;
}
F_7 ( V_18 ) ;
}
V_19:
if ( V_9 == NULL )
F_10 ( V_25 , V_28 ) ;
V_27:
F_13 ( V_5 ) ;
F_13 ( V_7 ) ;
return ( V_9 ) ;
}
T_1 * F_14 ( T_6 * V_29 , T_1 * * V_2 , T_3 * V_3 , void * V_4 )
{
T_2 * V_30 ;
T_1 * V_9 ;
if ( ( V_30 = F_15 ( F_16 () ) ) == NULL )
{
F_10 ( V_31 , V_32 ) ;
return ( 0 ) ;
}
F_17 ( V_30 , V_29 , V_33 ) ;
V_9 = F_1 ( V_30 , V_2 , V_3 , V_4 ) ;
F_18 ( V_30 ) ;
return ( V_9 ) ;
}
