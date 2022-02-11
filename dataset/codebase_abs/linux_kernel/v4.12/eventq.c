int F_1 (
T_1 * V_1 ,
T_2 * V_2 )
{
T_3 V_3 ;
int error ;
error = F_2 ( V_1 , & V_3 ) ;
if ( ! error )
F_3 ( V_3 , V_2 ) ;
return error ;
}
int F_4 (
T_1 * V_1 ,
T_2 V_4 ,
T_2 V_5 ,
T_2 V_6 ,
T_2 V_7 )
{
T_2 V_8 [ 4 ] ;
T_3 V_9 ;
int error = V_10 ;
V_8 [ 0 ] = V_4 ;
V_8 [ 1 ] = V_5 ;
V_8 [ 2 ] = V_6 ;
V_8 [ 3 ] = V_7 ;
F_5 ( V_8 , 4 , & V_9 ) ;
for ( ; ; ) {
error = F_6 ( V_1 , V_9 ) ;
if ( V_11 != error ) {
break;
}
F_7 () ;
}
return error ;
}
