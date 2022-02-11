T_1 * F_1 ( int type , T_1 * * V_1 , const unsigned char * * V_2 ,
long V_3 )
{
T_1 * V_4 ;
const unsigned char * V_5 = * V_2 ;
if ( ( V_1 == NULL ) || ( * V_1 == NULL ) ) {
if ( ( V_4 = F_2 () ) == NULL ) {
F_3 ( V_6 , V_7 ) ;
return ( NULL ) ;
}
} else {
V_4 = * V_1 ;
#ifndef F_4
F_5 ( V_4 -> V_8 ) ;
V_4 -> V_8 = NULL ;
#endif
}
if ( ! F_6 ( V_4 , type ) ) {
F_3 ( V_6 , V_9 ) ;
goto V_10;
}
if ( ! V_4 -> V_11 -> V_12 ||
! V_4 -> V_11 -> V_12 ( V_4 , & V_5 , V_3 ) ) {
if ( V_4 -> V_11 -> V_13 ) {
T_1 * V_14 ;
T_2 * V_15 = NULL ;
V_15 = F_7 ( NULL , & V_5 , V_3 ) ;
if ( ! V_15 )
goto V_10;
V_14 = F_8 ( V_15 ) ;
F_9 ( V_15 ) ;
if ( V_14 == NULL )
goto V_10;
F_10 ( V_4 ) ;
V_4 = V_14 ;
} else {
F_3 ( V_6 , V_16 ) ;
goto V_10;
}
}
* V_2 = V_5 ;
if ( V_1 != NULL )
( * V_1 ) = V_4 ;
return ( V_4 ) ;
V_10:
if ( V_1 == NULL || * V_1 != V_4 )
F_10 ( V_4 ) ;
return ( NULL ) ;
}
T_1 * F_11 ( T_1 * * V_1 , const unsigned char * * V_2 ,
long V_3 )
{
F_12 ( V_17 ) * V_18 ;
const unsigned char * V_5 ;
int V_19 ;
V_5 = * V_2 ;
V_18 = F_13 ( NULL , & V_5 , V_3 ) ;
V_5 = * V_2 ;
if ( F_14 ( V_18 ) == 6 )
V_19 = V_20 ;
else if ( F_14 ( V_18 ) == 4 )
V_19 = V_21 ;
else if ( F_14 ( V_18 ) == 3 ) {
T_2 * V_15 = F_7 ( NULL , & V_5 , V_3 ) ;
T_1 * V_4 ;
F_15 ( V_18 , V_22 ) ;
if ( ! V_15 ) {
F_3 ( V_23 ,
V_24 ) ;
return NULL ;
}
V_4 = F_8 ( V_15 ) ;
F_9 ( V_15 ) ;
if ( V_4 == NULL )
return NULL ;
* V_2 = V_5 ;
if ( V_1 ) {
* V_1 = V_4 ;
}
return V_4 ;
} else
V_19 = V_25 ;
F_15 ( V_18 , V_22 ) ;
return F_1 ( V_19 , V_1 , V_2 , V_3 ) ;
}
