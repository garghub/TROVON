T_1 F_1 ( T_1 V_1 , T_2 V_2 , T_2 * V_3 )
{
T_3 V_4 ;
if ( V_1 < 0 ) {
V_4 = F_2 ( - V_1 , abs ( V_2 ) , ( V_5 * ) V_3 ) ;
* V_3 = - * V_3 ;
if ( V_2 > 0 )
V_4 = - V_4 ;
} else {
V_4 = F_2 ( V_1 , abs ( V_2 ) , ( V_5 * ) V_3 ) ;
if ( V_2 < 0 )
V_4 = - V_4 ;
}
return V_4 ;
}
T_3 F_3 ( T_3 V_1 , T_3 V_2 , T_3 * V_3 )
{
V_5 V_6 = V_2 >> 32 ;
T_3 V_7 ;
if ( V_6 == 0 ) {
V_5 V_8 ;
V_7 = F_2 ( V_1 , V_2 , & V_8 ) ;
* V_3 = V_8 ;
} else {
int V_9 = 1 + F_4 ( V_6 ) ;
V_7 = F_5 ( V_1 >> V_9 , V_2 >> V_9 ) ;
if ( V_7 != 0 )
V_7 -- ;
* V_3 = V_1 - V_7 * V_2 ;
if ( * V_3 >= V_2 ) {
V_7 ++ ;
* V_3 -= V_2 ;
}
}
return V_7 ;
}
T_3 F_6 ( T_3 V_1 , T_3 V_2 )
{
V_5 V_6 = V_2 >> 32 ;
T_3 V_7 ;
if ( V_6 == 0 ) {
V_7 = F_5 ( V_1 , V_2 ) ;
} else {
int V_9 = 1 + F_4 ( V_6 ) ;
V_7 = F_5 ( V_1 >> V_9 , V_2 >> V_9 ) ;
if ( V_7 != 0 )
V_7 -- ;
if ( ( V_1 - V_7 * V_2 ) >= V_2 )
V_7 ++ ;
}
return V_7 ;
}
T_1 F_7 ( T_1 V_1 , T_1 V_2 )
{
T_1 V_7 , V_10 ;
V_7 = F_6 ( F_8 ( V_1 ) , F_8 ( V_2 ) ) ;
V_10 = ( V_1 ^ V_2 ) >> 63 ;
return ( V_7 ^ V_10 ) - V_10 ;
}
V_5 F_9 ( T_3 V_1 , V_5 V_2 , T_3 * V_3 )
{
return F_10 ( V_1 , V_2 , V_3 ) ;
}
