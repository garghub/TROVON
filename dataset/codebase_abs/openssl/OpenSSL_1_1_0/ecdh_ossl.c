int F_1 ( unsigned char * * V_1 , T_1 * V_2 ,
const T_2 * V_3 , const T_3 * V_4 )
{
if ( V_4 -> V_5 -> V_6 -> V_7 == NULL ) {
F_2 ( V_8 , V_9 ) ;
return 0 ;
}
return V_4 -> V_5 -> V_6 -> V_7 ( V_1 , V_2 , V_3 , V_4 ) ;
}
int F_3 ( unsigned char * * V_10 , T_1 * V_11 ,
const T_2 * V_3 , const T_3 * V_4 )
{
T_4 * V_12 ;
T_2 * V_13 = NULL ;
T_5 * V_14 = NULL , * V_15 = NULL ;
const T_5 * V_16 ;
const T_6 * V_5 ;
int V_17 = 0 ;
T_1 V_18 , V_19 ;
unsigned char * V_20 = NULL ;
if ( ( V_12 = F_4 () ) == NULL )
goto V_21;
F_5 ( V_12 ) ;
V_14 = F_6 ( V_12 ) ;
V_15 = F_6 ( V_12 ) ;
V_16 = F_7 ( V_4 ) ;
if ( V_16 == NULL ) {
F_2 ( V_22 , V_23 ) ;
goto V_21;
}
V_5 = F_8 ( V_4 ) ;
if ( F_9 ( V_4 ) & V_24 ) {
if ( ! F_10 ( V_5 , V_14 , NULL ) ||
! F_11 ( V_14 , V_14 , V_16 , V_12 ) ) {
F_2 ( V_22 , V_25 ) ;
goto V_21;
}
V_16 = V_14 ;
}
if ( ( V_13 = F_12 ( V_5 ) ) == NULL ) {
F_2 ( V_22 , V_25 ) ;
goto V_21;
}
if ( ! F_13 ( V_5 , V_13 , NULL , V_3 , V_16 , V_12 ) ) {
F_2 ( V_22 , V_26 ) ;
goto V_21;
}
if ( F_14 ( F_15 ( V_5 ) ) ==
V_27 ) {
if ( ! F_16 ( V_5 , V_13 , V_14 , V_15 , V_12 ) ) {
F_2 ( V_22 , V_26 ) ;
goto V_21;
}
}
#ifndef F_17
else {
if ( ! F_18 ( V_5 , V_13 , V_14 , V_15 , V_12 ) ) {
F_2 ( V_22 , V_26 ) ;
goto V_21;
}
}
#endif
V_18 = ( F_19 ( V_5 ) + 7 ) / 8 ;
V_19 = F_20 ( V_14 ) ;
if ( V_19 > V_18 ) {
F_2 ( V_22 , V_28 ) ;
goto V_21;
}
if ( ( V_20 = F_21 ( V_18 ) ) == NULL ) {
F_2 ( V_22 , V_25 ) ;
goto V_21;
}
memset ( V_20 , 0 , V_18 - V_19 ) ;
if ( V_19 != ( T_1 ) F_22 ( V_14 , V_20 + V_18 - V_19 ) ) {
F_2 ( V_22 , V_29 ) ;
goto V_21;
}
* V_10 = V_20 ;
* V_11 = V_18 ;
V_20 = NULL ;
V_17 = 1 ;
V_21:
F_23 ( V_13 ) ;
if ( V_12 )
F_24 ( V_12 ) ;
F_25 ( V_12 ) ;
F_26 ( V_20 ) ;
return V_17 ;
}
