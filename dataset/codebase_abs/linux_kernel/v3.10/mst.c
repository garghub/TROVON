int F_1 ( T_1 * V_1 , const T_2 V_2 )
{
T_3 V_3 , V_4 , V_5 ;
T_3 * V_6 , * V_7 ;
V_3 = F_2 ( V_1 -> V_3 ) ;
V_4 = F_2 ( V_1 -> V_4 ) - 1 ;
if ( V_2 & ( V_8 - 1 ) ||
V_3 & 1 ||
V_3 + ( V_4 * 2 ) > V_2 ||
( V_2 >> V_9 ) != V_4 )
return 0 ;
V_6 = ( T_3 * ) V_1 + V_3 / sizeof( T_3 ) ;
V_5 = * V_6 ;
V_7 = ( T_3 * ) V_1 + V_8 / sizeof( T_3 ) - 1 ;
while ( V_4 -- ) {
if ( * V_7 != V_5 ) {
V_1 -> V_10 = V_11 ;
return - V_12 ;
}
V_7 += V_8 / sizeof( T_3 ) ;
}
V_4 = F_2 ( V_1 -> V_4 ) - 1 ;
V_7 = ( T_3 * ) V_1 + V_8 / sizeof( T_3 ) - 1 ;
while ( V_4 -- ) {
* V_7 = * ( ++ V_6 ) ;
V_7 += V_8 / sizeof( T_3 ) ;
}
return 0 ;
}
int F_3 ( T_1 * V_1 , const T_2 V_2 )
{
T_4 * V_6 , * V_7 ;
T_3 V_3 , V_4 , V_5 ;
T_4 V_13 ;
if ( ! V_1 || F_4 ( V_1 -> V_10 ) ||
F_5 ( V_1 -> V_10 ) )
return - V_12 ;
V_3 = F_2 ( V_1 -> V_3 ) ;
V_4 = F_2 ( V_1 -> V_4 ) - 1 ;
if ( V_2 & ( V_8 - 1 ) ||
V_3 & 1 ||
V_3 + ( V_4 * 2 ) > V_2 ||
( V_2 >> V_9 ) != V_4 )
return - V_12 ;
V_6 = ( T_4 * ) ( ( V_14 * ) V_1 + V_3 ) ;
V_5 = F_6 ( V_6 ) + 1 ;
if ( V_5 == 0xffff || ! V_5 )
V_5 = 1 ;
V_13 = F_7 ( V_5 ) ;
* V_6 = V_13 ;
V_7 = ( T_4 * ) V_1 + V_8 / sizeof( T_4 ) - 1 ;
while ( V_4 -- ) {
* ( ++ V_6 ) = * V_7 ;
* V_7 = V_13 ;
V_7 += V_8 / sizeof( T_4 ) ;
}
return 0 ;
}
void F_8 ( T_1 * V_1 )
{
T_4 * V_6 , * V_7 ;
T_3 V_3 = F_2 ( V_1 -> V_3 ) ;
T_3 V_4 = F_2 ( V_1 -> V_4 ) - 1 ;
V_6 = ( T_4 * ) V_1 + V_3 / sizeof( T_4 ) ;
V_7 = ( T_4 * ) V_1 + V_8 / sizeof( T_4 ) - 1 ;
while ( V_4 -- ) {
* V_7 = * ( ++ V_6 ) ;
V_7 += V_8 / sizeof( T_4 ) ;
}
}
