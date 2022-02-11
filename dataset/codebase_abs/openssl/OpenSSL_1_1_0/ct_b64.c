static int F_1 ( const char * V_1 , unsigned char * * V_2 )
{
T_1 V_3 = strlen ( V_1 ) ;
int V_4 ;
unsigned char * V_5 = NULL ;
if ( V_3 == 0 ) {
* V_2 = NULL ;
return 0 ;
}
V_4 = ( V_3 / 4 ) * 3 ;
V_5 = F_2 ( V_4 ) ;
if ( V_5 == NULL ) {
F_3 ( V_6 , V_7 ) ;
goto V_8;
}
V_4 = F_4 ( V_5 , ( unsigned char * ) V_1 , V_3 ) ;
if ( V_4 < 0 ) {
F_3 ( V_6 , V_9 ) ;
goto V_8;
}
* V_2 = V_5 ;
return V_4 ;
V_8:
F_5 ( V_5 ) ;
return - 1 ;
}
T_2 * F_6 ( unsigned char V_10 , const char * V_11 ,
T_3 V_12 , T_4 V_13 ,
const char * V_14 ,
const char * V_15 )
{
T_2 * V_16 = F_7 () ;
unsigned char * V_17 = NULL ;
int V_18 ;
if ( V_16 == NULL ) {
F_3 ( V_19 , V_7 ) ;
return NULL ;
}
if ( ! F_8 ( V_16 , V_10 ) ) {
F_3 ( V_19 , V_20 ) ;
goto V_8;
}
V_18 = F_1 ( V_11 , & V_17 ) ;
if ( V_18 < 0 ) {
F_3 ( V_19 , V_21 ) ;
goto V_8;
}
if ( ! F_9 ( V_16 , V_17 , V_18 ) )
goto V_8;
V_17 = NULL ;
V_18 = F_1 ( V_14 , & V_17 ) ;
if ( V_18 < 0 ) {
F_3 ( V_19 , V_21 ) ;
goto V_8;
}
F_10 ( V_16 , V_17 , V_18 ) ;
V_17 = NULL ;
V_18 = F_1 ( V_15 , & V_17 ) ;
if ( V_18 < 0 ) {
F_3 ( V_19 , V_21 ) ;
goto V_8;
}
if ( F_11 ( V_16 , ( const unsigned char * * ) & V_17 , V_18 ) <= 0 )
goto V_8;
F_5 ( V_17 ) ;
V_17 = NULL ;
F_12 ( V_16 , V_13 ) ;
if ( ! F_13 ( V_16 , V_12 ) )
goto V_8;
return V_16 ;
V_8:
F_5 ( V_17 ) ;
F_14 ( V_16 ) ;
return NULL ;
}
int F_15 ( T_5 * * V_22 , const char * V_23 , const char * V_24 )
{
unsigned char * V_25 = NULL ;
int V_26 = F_1 ( V_23 , & V_25 ) ;
const unsigned char * V_27 ;
T_6 * V_28 = NULL ;
if ( V_22 == NULL ) {
F_3 ( V_29 , V_30 ) ;
return 0 ;
}
if ( V_26 <= 0 ) {
F_3 ( V_29 , V_31 ) ;
return 0 ;
}
V_27 = V_25 ;
V_28 = F_16 ( NULL , & V_27 , V_26 ) ;
F_5 ( V_25 ) ;
if ( V_28 == NULL ) {
F_3 ( V_29 , V_31 ) ;
return 0 ;
}
* V_22 = F_17 ( V_28 , V_24 ) ;
if ( * V_22 == NULL ) {
F_18 ( V_28 ) ;
return 0 ;
}
return 1 ;
}
