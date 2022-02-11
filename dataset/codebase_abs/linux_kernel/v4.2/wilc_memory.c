void * F_1 ( T_1 V_1 , T_2 * V_2 ,
char * V_3 , T_1 V_4 )
{
if ( V_1 > 0 ) {
return F_2 ( V_1 , V_5 ) ;
} else {
return NULL ;
}
}
void * F_3 ( T_1 V_1 , T_2 * V_2 ,
char * V_3 , T_1 V_4 )
{
return F_4 ( V_1 , 1 , V_6 ) ;
}
void * F_5 ( void * V_7 , T_1 V_8 ,
T_2 * V_2 , char * V_3 , T_1 V_4 )
{
if ( V_8 == 0 ) {
F_6 ( V_7 ) ;
return NULL ;
} else if ( V_7 == NULL ) {
return F_2 ( V_8 , V_6 ) ;
} else {
return F_7 ( V_7 , V_8 , V_6 ) ;
}
}
void F_8 ( const void * V_9 , T_2 * V_2 ,
char * V_3 , T_1 V_4 )
{
F_6 ( V_9 ) ;
}
