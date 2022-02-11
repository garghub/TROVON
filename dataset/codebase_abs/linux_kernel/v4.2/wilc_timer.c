T_1 F_1 ( T_2 * V_1 ,
T_3 V_2 , T_4 * V_3 )
{
T_1 V_4 = V_5 ;
F_2 ( V_1 , ( void (*) ( unsigned long ) ) V_2 , 0 ) ;
return V_4 ;
}
T_1 F_3 ( T_2 * V_1 ,
T_4 * V_3 )
{
T_1 V_4 = V_6 ;
if ( V_1 != NULL ) {
V_4 = F_4 ( V_1 ) ;
V_1 = NULL ;
}
return V_4 ;
}
T_1 F_5 ( T_2 * V_1 , T_5 V_7 ,
void * V_8 , T_4 * V_3 )
{
T_1 V_4 = V_6 ;
if ( V_1 != NULL ) {
V_1 -> V_9 = ( unsigned long ) V_8 ;
V_4 = F_6 ( V_1 , ( V_10 + F_7 ( V_7 ) ) ) ;
}
return V_4 ;
}
T_1 F_8 ( T_2 * V_1 ,
T_4 * V_3 )
{
T_1 V_4 = V_6 ;
if ( V_1 != NULL )
V_4 = F_9 ( V_1 ) ;
return V_4 ;
}
