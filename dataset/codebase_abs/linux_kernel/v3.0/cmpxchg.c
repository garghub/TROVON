unsigned long F_1 ( volatile void * V_1 , T_1 V_2 , T_1 V_3 )
{
T_1 V_4 ;
unsigned long V_5 ;
F_2 ( V_5 ) ;
V_4 = * ( T_1 * ) V_1 ;
if ( V_4 == V_2 )
* ( T_1 * ) V_1 = V_3 ;
F_3 ( V_5 ) ;
return V_4 ;
}
unsigned long F_4 ( volatile void * V_1 , T_2 V_2 , T_2 V_3 )
{
T_2 V_4 ;
unsigned long V_5 ;
F_2 ( V_5 ) ;
V_4 = * ( T_2 * ) V_1 ;
if ( V_4 == V_2 )
* ( T_2 * ) V_1 = V_3 ;
F_3 ( V_5 ) ;
return V_4 ;
}
unsigned long F_5 ( volatile void * V_1 , T_3 V_2 , T_3 V_3 )
{
T_3 V_4 ;
unsigned long V_5 ;
F_2 ( V_5 ) ;
V_4 = * ( T_3 * ) V_1 ;
if ( V_4 == V_2 )
* ( T_3 * ) V_1 = V_3 ;
F_3 ( V_5 ) ;
return V_4 ;
}
