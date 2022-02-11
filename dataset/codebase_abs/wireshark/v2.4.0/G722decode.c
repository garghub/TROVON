void *
F_1 ( void )
{
T_1 * V_1 ;
V_1 = F_2 ( NULL , 64000 , 0 ) ;
return V_1 ;
}
void
F_3 ( void * V_2 )
{
T_1 * V_1 = ( T_1 * ) V_2 ;
if ( ! V_1 ) {
return;
}
F_4 ( V_1 ) ;
}
unsigned
F_5 ( void * V_2 V_3 )
{
return 1 ;
}
unsigned
F_6 ( void * V_2 V_3 )
{
return 16000 ;
}
T_2
F_7 ( void * V_2 , const void * V_4 , T_2 V_5 , void * V_6 ,
T_2 * V_7 )
{
T_1 * V_1 = ( T_1 * ) V_2 ;
if ( ! V_1 ) {
return 0 ;
}
if ( ! V_6 || ! V_7 ) {
return 4 * V_5 ;
}
* V_7 = 2 * F_8 ( V_1 , ( V_8 * ) V_6 , ( const V_9 * ) V_4 , ( int ) V_5 ) ;
return * V_7 ;
}
