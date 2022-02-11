int F_1 ( const T_1 * V_1 , unsigned char * * V_2 ,
int (* F_2) ( char * V_3 , int V_4 , const char * V_5 ,
int V_6 ) )
{
return F_3 ( V_1 , V_2 , F_2 , 0 ) ;
}
int F_3 ( const T_1 * V_1 , unsigned char * * V_2 ,
int (* F_2) ( char * V_3 , int V_4 , const char * V_5 ,
int V_6 ) , int V_7 )
{
int V_8 , V_9 , V_10 = 0 ;
int V_11 , V_12 , V_13 ;
T_2 * V_14 = NULL ;
T_3 * V_15 = NULL ;
unsigned char V_3 [ 256 ] , * V_16 ;
unsigned char V_17 [ V_18 ] ;
T_4 V_19 ;
F_4 ( & V_19 ) ;
if ( V_1 == NULL )
return ( 0 ) ;
if ( ( V_14 = F_5 () ) == NULL )
goto V_20;
if ( ( V_15 = F_6 () ) == NULL )
goto V_20;
V_14 -> V_21 = 0 ;
V_14 -> V_22 -> V_23 = F_7 ( V_24 ) ;
if ( ( V_14 -> V_22 -> V_25 = F_8 () ) == NULL )
goto V_20;
V_14 -> V_22 -> V_25 -> type = V_26 ;
V_11 = F_9 ( V_1 , NULL ) ;
V_14 -> V_27 -> V_28 = V_11 ;
V_12 = F_10 ( V_14 , NULL ) ;
V_15 -> V_15 -> V_29 -> V_28 = V_12 ;
V_15 -> V_30 -> V_28 = 11 ;
V_15 -> V_15 -> V_22 -> V_23 = F_7 ( V_31 ) ;
if ( ( V_15 -> V_15 -> V_22 -> V_25 = F_8 () ) == NULL )
goto V_20;
V_15 -> V_15 -> V_22 -> V_25 -> type = V_26 ;
if ( V_2 == NULL ) {
V_13 = F_11 ( V_15 , NULL ) ;
F_12 ( V_14 ) ;
F_13 ( V_15 ) ;
return V_13 ;
}
if ( ( V_16 = ( unsigned char * ) F_14 ( V_11 ) ) == NULL ) {
F_15 ( V_32 , V_33 ) ;
goto V_20;
}
V_14 -> V_27 -> V_34 = V_16 ;
F_9 ( V_1 , & V_16 ) ;
if ( ( V_16 = F_14 ( V_12 ) ) == NULL ) {
F_15 ( V_32 , V_33 ) ;
goto V_20;
}
if ( ! F_16 ( V_15 -> V_30 , L_1 , - 1 ) ) {
F_15 ( V_32 , V_33 ) ;
goto V_20;
}
V_15 -> V_15 -> V_29 -> V_34 = V_16 ;
F_10 ( V_14 , & V_16 ) ;
F_17 ( V_14 -> V_27 -> V_34 , V_11 ) ;
if ( F_2 == NULL )
F_2 = V_35 ;
V_8 = F_2 ( ( char * ) V_3 , 256 , L_2 , 1 ) ;
if ( V_8 != 0 ) {
F_15 ( V_32 , V_36 ) ;
goto V_20;
}
V_8 = strlen ( ( char * ) V_3 ) ;
if ( V_7 ) {
if ( ! F_18 ( V_3 , V_8 , V_3 , NULL , F_19 () , NULL ) )
goto V_20;
memcpy ( V_3 + 16 , L_3 , 10 ) ;
V_8 = 26 ;
}
if ( ! F_20 ( F_21 () , F_19 () , NULL , V_3 , V_8 , 1 , V_17 , NULL ) )
goto V_20;
F_17 ( V_3 , 256 ) ;
V_16 = V_15 -> V_15 -> V_29 -> V_34 ;
if ( ! F_22 ( & V_19 , F_21 () , NULL , V_17 , NULL ) )
goto V_20;
if ( ! F_23 ( & V_19 , V_16 , & V_8 , V_16 , V_12 ) )
goto V_20;
if ( ! F_24 ( & V_19 , V_16 + V_8 , & V_9 ) )
goto V_20;
V_10 = F_11 ( V_15 , V_2 ) ;
V_20:
F_25 ( & V_19 ) ;
F_13 ( V_15 ) ;
F_12 ( V_14 ) ;
return ( V_10 ) ;
}
T_1 * F_26 ( T_1 * * V_1 , const unsigned char * * V_2 , long V_28 ,
int (* F_2) ( char * V_3 , int V_4 , const char * V_5 ,
int V_6 ) )
{
return F_27 ( V_1 , V_2 , V_28 , F_2 , 0 ) ;
}
T_1 * F_27 ( T_1 * * V_1 , const unsigned char * * V_2 , long V_28 ,
int (* F_2) ( char * V_3 , int V_4 , const char * V_5 ,
int V_6 ) , int V_7 )
{
T_1 * V_10 = NULL ;
const unsigned char * V_37 ;
T_3 * V_15 = NULL ;
V_37 = * V_2 ;
V_15 = F_28 ( NULL , & V_37 , V_28 ) ;
if ( ! V_15 ) {
F_15 ( V_38 , V_39 ) ;
return NULL ;
}
if ( ( V_15 -> V_30 -> V_28 != 11 ) || ( strncmp ( L_1 ,
( char * ) V_15 -> V_30 -> V_34 ,
11 ) != 0 ) ) {
F_15 ( V_38 , V_40 ) ;
F_13 ( V_15 ) ;
return NULL ;
}
if ( F_29 ( V_15 -> V_15 -> V_22 -> V_23 ) != V_31 ) {
F_15 ( V_38 , V_41 ) ;
goto V_20;
}
if ( F_2 == NULL )
F_2 = V_35 ;
if ( ( V_10 = F_30 ( V_1 , V_15 -> V_15 -> V_29 , F_2 , V_7 ) ) == NULL )
goto V_20;
* V_2 = V_37 ;
V_20:
F_13 ( V_15 ) ;
return V_10 ;
}
static T_1 * F_30 ( T_1 * * V_1 , T_5 * V_30 ,
int (* F_2) ( char * V_3 , int V_4 , const char * V_5 ,
int V_6 ) , int V_7 )
{
T_2 * V_14 = NULL ;
T_1 * V_10 = NULL ;
int V_8 , V_9 ;
unsigned char V_3 [ 256 ] ;
const unsigned char * V_16 ;
unsigned char V_17 [ V_18 ] ;
T_4 V_19 ;
F_4 ( & V_19 ) ;
V_8 = F_2 ( ( char * ) V_3 , 256 , L_2 , 0 ) ;
if ( V_8 != 0 ) {
F_15 ( V_42 , V_36 ) ;
goto V_20;
}
V_8 = strlen ( ( char * ) V_3 ) ;
if ( V_7 ) {
if ( ! F_18 ( V_3 , V_8 , V_3 , NULL , F_19 () , NULL ) )
goto V_20;
memcpy ( V_3 + 16 , L_3 , 10 ) ;
V_8 = 26 ;
}
if ( ! F_20 ( F_21 () , F_19 () , NULL , V_3 , V_8 , 1 , V_17 , NULL ) )
goto V_20;
F_17 ( V_3 , 256 ) ;
if ( ! F_31 ( & V_19 , F_21 () , NULL , V_17 , NULL ) )
goto V_20;
if ( ! F_32 ( & V_19 , V_30 -> V_34 , & V_8 , V_30 -> V_34 , V_30 -> V_28 ) )
goto V_20;
if ( ! F_33 ( & V_19 , & ( V_30 -> V_34 [ V_8 ] ) , & V_9 ) )
goto V_20;
V_30 -> V_28 = V_8 + V_9 ;
V_16 = V_30 -> V_34 ;
if ( ( V_14 = F_34 ( NULL , & V_16 , V_30 -> V_28 ) ) == NULL ) {
F_15 ( V_42 ,
V_43 ) ;
goto V_20;
}
V_16 = V_14 -> V_27 -> V_34 ;
if ( ( V_10 = F_35 ( V_1 , & V_16 , V_14 -> V_27 -> V_28 ) ) == NULL ) {
F_15 ( V_42 , V_44 ) ;
goto V_20;
}
V_20:
F_25 ( & V_19 ) ;
F_12 ( V_14 ) ;
return ( V_10 ) ;
}
