T_1 * F_1 ( void * V_1 , const T_2 * V_2 , T_1 * * V_3 )
{
T_1 * V_4 ;
if ( V_3 == NULL || * V_3 == NULL ) {
if ( ( V_4 = F_2 () ) == NULL ) {
F_3 ( V_5 , V_6 ) ;
return NULL ;
}
} else {
V_4 = * V_3 ;
}
F_4 ( V_4 -> V_7 ) ;
V_4 -> V_7 = NULL ;
if ( ( V_4 -> V_8 = F_5 ( V_1 , & V_4 -> V_7 , V_2 ) ) == 0 ) {
F_3 ( V_5 , V_9 ) ;
goto V_10;
}
if ( V_4 -> V_7 == NULL ) {
F_3 ( V_5 , V_6 ) ;
goto V_10;
}
if ( V_3 != NULL && * V_3 == NULL )
* V_3 = V_4 ;
return V_4 ;
V_10:
if ( V_3 == NULL || * V_3 == NULL )
F_6 ( V_4 ) ;
return NULL ;
}
void * F_7 ( const T_1 * V_3 , const T_2 * V_2 )
{
const unsigned char * V_11 ;
void * V_12 ;
V_11 = V_3 -> V_7 ;
if ( ( V_12 = F_8 ( NULL , & V_11 , V_3 -> V_8 , V_2 ) ) == NULL )
F_3 ( V_13 , V_14 ) ;
return V_12 ;
}
