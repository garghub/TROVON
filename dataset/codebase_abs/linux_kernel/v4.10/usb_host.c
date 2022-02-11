int F_1 ( T_1 * V_1 , int V_2 ,
int V_3 )
{
char V_4 [ 32 ] ;
int V_5 ;
if ( V_3 )
snprintf ( V_4 , sizeof( V_4 ) , L_1 ,
V_2 ) ;
else
snprintf ( V_4 , sizeof( V_4 ) , L_2 ,
V_2 ) ;
V_5 = F_2 ( ( V_6 ) V_4 , 0 ) ;
if ( V_5 < 0 ) {
if ( V_5 >= V_7 && V_5 <= V_8 )
return V_5 ;
else
return - V_9 ;
}
V_1 -> V_5 = V_5 ;
V_1 -> V_10 =
( void V_11 * ) F_3 ( V_5 , 0 , V_12 ) ;
if ( V_1 -> V_10 == NULL ) {
F_4 ( V_1 -> V_5 ) ;
return - V_9 ;
}
return 0 ;
}
int F_5 ( T_1 * V_1 )
{
F_6 ( ( void V_11 V_13 * ) ( V_1 -> V_10 ) ) ;
F_4 ( V_1 -> V_5 ) ;
V_1 -> V_10 = NULL ;
V_1 -> V_5 = - 1 ;
return 0 ;
}
void * F_7 ( T_1 * V_1 )
{
return V_1 -> V_10 ;
}
T_2 F_8 ( T_1 * V_1 )
{
return V_12 ;
}
