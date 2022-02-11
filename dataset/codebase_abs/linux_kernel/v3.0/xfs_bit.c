int
F_1 ( T_1 * V_1 , T_1 V_2 )
{
T_1 V_3 ;
T_1 V_4 = 0 ;
for ( V_3 = 0 ; V_3 < V_2 ; V_3 ++ ) {
V_4 |= V_1 [ V_3 ] ;
}
return ( V_4 == 0 ) ;
}
int
F_2 ( T_1 * V_1 , T_1 V_2 , T_1 V_5 )
{
T_1 * V_6 = ( ( unsigned int * ) V_1 ) + ( V_5 >> V_7 ) ;
T_1 V_8 = 0 ;
T_1 V_9 ;
V_2 <<= V_7 ;
ASSERT ( V_5 < V_2 ) ;
V_2 -= V_5 & ~ ( V_10 - 1 ) ;
V_5 &= ( V_10 - 1 ) ;
if ( V_5 ) {
V_9 = * V_6 ++ ;
V_9 |= ( ~ 0U >> ( V_10 - V_5 ) ) ;
if ( V_9 != ~ 0U )
goto V_11;
V_8 += V_10 ;
V_2 -= V_10 ;
}
while ( V_2 ) {
if ( ( V_9 = * V_6 ++ ) != ~ 0U )
goto V_11;
V_8 += V_10 ;
V_2 -= V_10 ;
}
return V_8 - V_5 ;
V_11:
return V_8 + F_3 ( V_9 ) - V_5 ;
}
int F_4 ( T_1 * V_1 , T_1 V_2 , T_1 V_5 )
{
T_1 * V_6 = ( ( unsigned int * ) V_1 ) + ( V_5 >> V_7 ) ;
T_1 V_8 = V_5 & ~ ( V_10 - 1 ) ;
T_1 V_9 ;
V_2 <<= V_7 ;
if ( V_5 >= V_2 )
return - 1 ;
V_2 -= V_8 ;
V_5 &= ( V_10 - 1 ) ;
if ( V_5 ) {
V_9 = * V_6 ++ ;
V_9 &= ( ~ 0U << V_5 ) ;
if ( V_9 != 0U )
goto V_11;
V_8 += V_10 ;
V_2 -= V_10 ;
}
while ( V_2 ) {
if ( ( V_9 = * V_6 ++ ) != 0U )
goto V_11;
V_8 += V_10 ;
V_2 -= V_10 ;
}
return - 1 ;
V_11:
return V_8 + F_5 ( V_9 ) - 1 ;
}
