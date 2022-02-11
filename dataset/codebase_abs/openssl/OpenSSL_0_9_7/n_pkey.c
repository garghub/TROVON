int F_1 ( const T_1 * V_1 , unsigned char * * V_2 , int (* F_2)() )
{
return F_3 ( V_1 , V_2 , F_2 , 0 ) ;
}
int F_3 ( const T_1 * V_1 , unsigned char * * V_2 , int (* F_2)() , int V_3 )
{
int V_4 , V_5 , V_6 = 0 ;
int V_7 , V_8 , V_9 ;
T_2 * V_10 = NULL ;
T_3 * V_11 = NULL ;
unsigned char V_12 [ 256 ] , * V_13 ;
unsigned char V_14 [ V_15 ] ;
T_4 V_16 ;
if ( V_1 == NULL ) return ( 0 ) ;
if ( ( V_10 = F_4 () ) == NULL ) goto V_17;
if ( ( V_11 = F_5 () ) == NULL ) goto V_17;
V_10 -> V_18 = 0 ;
V_10 -> V_19 -> V_20 = F_6 ( V_21 ) ;
if ( ( V_10 -> V_19 -> V_22 = F_7 () ) == NULL ) goto V_17;
V_10 -> V_19 -> V_22 -> type = V_23 ;
V_7 = F_8 ( V_1 , NULL ) ;
V_10 -> V_24 -> V_25 = V_7 ;
V_8 = F_9 ( V_10 , NULL ) ;
V_11 -> V_11 -> V_26 -> V_25 = V_8 ;
V_11 -> V_27 -> V_25 = 11 ;
V_11 -> V_11 -> V_19 -> V_20 = F_6 ( V_28 ) ;
if ( ( V_11 -> V_11 -> V_19 -> V_22 = F_7 () ) == NULL ) goto V_17;
V_11 -> V_11 -> V_19 -> V_22 -> type = V_23 ;
if ( V_2 == NULL )
{
V_9 = F_10 ( V_11 , NULL ) ;
F_11 ( V_10 ) ;
F_12 ( V_11 ) ;
return V_9 ;
}
if ( ( V_13 = ( unsigned char * ) F_13 ( V_7 ) ) == NULL )
{
F_14 ( V_29 , V_30 ) ;
goto V_17;
}
V_10 -> V_24 -> V_31 = V_13 ;
F_8 ( V_1 , & V_13 ) ;
if ( ( V_13 = F_13 ( V_8 ) ) == NULL )
{
F_14 ( V_29 , V_30 ) ;
goto V_17;
}
if ( ! F_15 ( V_11 -> V_27 , L_1 , - 1 ) )
{
F_14 ( V_29 , V_30 ) ;
goto V_17;
}
V_11 -> V_11 -> V_26 -> V_31 = V_13 ;
F_9 ( V_10 , & V_13 ) ;
F_16 ( V_10 -> V_24 -> V_31 , V_7 ) ;
if ( F_2 == NULL )
F_2 = V_32 ;
V_4 = F_2 ( V_12 , 256 , L_2 , 1 ) ;
if ( V_4 != 0 )
{
F_14 ( V_29 , V_33 ) ;
goto V_17;
}
V_4 = strlen ( ( char * ) V_12 ) ;
if( V_3 ) {
F_17 ( V_12 , V_4 , V_12 , NULL , F_18 () , NULL ) ;
memcpy ( V_12 + 16 , L_3 , 10 ) ;
V_4 = 26 ;
}
F_19 ( F_20 () , F_18 () , NULL , V_12 , V_4 , 1 , V_14 , NULL ) ;
F_16 ( V_12 , 256 ) ;
V_13 = V_11 -> V_11 -> V_26 -> V_31 ;
F_21 ( & V_16 ) ;
F_22 ( & V_16 , F_20 () , NULL , V_14 , NULL ) ;
F_23 ( & V_16 , V_13 , & V_4 , V_13 , V_8 ) ;
F_24 ( & V_16 , V_13 + V_4 , & V_5 ) ;
F_25 ( & V_16 ) ;
V_6 = F_10 ( V_11 , V_2 ) ;
V_17:
F_12 ( V_11 ) ;
F_11 ( V_10 ) ;
return ( V_6 ) ;
}
T_1 * F_26 ( T_1 * * V_1 , const unsigned char * * V_2 , long V_25 , int (* F_2)() )
{
return F_27 ( V_1 , V_2 , V_25 , F_2 , 0 ) ;
}
T_1 * F_27 ( T_1 * * V_1 , const unsigned char * * V_2 , long V_25 , int (* F_2)() , int V_3 )
{
T_1 * V_6 = NULL ;
const unsigned char * V_34 , * V_35 ;
T_3 * V_11 = NULL ;
V_34 = * V_2 ;
V_11 = F_28 ( NULL , & V_34 , V_25 ) ;
if( ! V_11 ) {
F_14 ( V_36 , V_37 ) ;
return NULL ;
}
if ( ( V_11 -> V_27 -> V_25 != 11 ) || ( strncmp ( L_1 ,
( char * ) V_11 -> V_27 -> V_31 , 11 ) != 0 ) )
{
F_14 ( V_36 , V_38 ) ;
F_12 ( V_11 ) ;
return NULL ;
}
if ( F_29 ( V_11 -> V_11 -> V_19 -> V_20 ) != V_28 )
{
F_14 ( V_39 , V_40 ) ;
goto V_17;
}
V_35 = V_11 -> V_11 -> V_26 -> V_31 ;
if ( F_2 == NULL )
F_2 = V_32 ;
if ( ( V_6 = F_30 ( V_1 , V_11 -> V_11 -> V_26 , F_2 , V_3 ) ) == NULL ) goto V_17;
* V_2 = V_34 ;
V_17:
F_12 ( V_11 ) ;
return V_6 ;
}
static T_1 * F_30 ( T_1 * * V_1 , T_5 * V_27 ,
int (* F_2)() , int V_3 )
{
T_2 * V_10 = NULL ;
T_1 * V_6 = NULL ;
int V_4 , V_5 ;
unsigned char V_12 [ 256 ] ;
const unsigned char * V_13 ;
unsigned char V_14 [ V_15 ] ;
T_4 V_16 ;
V_4 = F_2 ( V_12 , 256 , L_2 , 0 ) ;
if ( V_4 != 0 )
{
F_14 ( V_39 , V_33 ) ;
goto V_17;
}
V_4 = strlen ( ( char * ) V_12 ) ;
if( V_3 ) {
F_17 ( V_12 , V_4 , V_12 , NULL , F_18 () , NULL ) ;
memcpy ( V_12 + 16 , L_3 , 10 ) ;
V_4 = 26 ;
}
F_19 ( F_20 () , F_18 () , NULL , V_12 , V_4 , 1 , V_14 , NULL ) ;
F_16 ( V_12 , 256 ) ;
F_21 ( & V_16 ) ;
F_31 ( & V_16 , F_20 () , NULL , V_14 , NULL ) ;
F_32 ( & V_16 , V_27 -> V_31 , & V_4 , V_27 -> V_31 , V_27 -> V_25 ) ;
F_33 ( & V_16 , & ( V_27 -> V_31 [ V_4 ] ) , & V_5 ) ;
F_25 ( & V_16 ) ;
V_27 -> V_25 = V_4 + V_5 ;
V_13 = V_27 -> V_31 ;
if ( ( V_10 = F_34 ( NULL , & V_13 , V_27 -> V_25 ) ) == NULL )
{
F_14 ( V_39 , V_41 ) ;
goto V_17;
}
V_13 = V_10 -> V_24 -> V_31 ;
if ( ( V_6 = F_35 ( V_1 , & V_13 , V_10 -> V_24 -> V_25 ) ) == NULL )
{
F_14 ( V_39 , V_42 ) ;
goto V_17;
}
V_17:
F_11 ( V_10 ) ;
return ( V_6 ) ;
}
