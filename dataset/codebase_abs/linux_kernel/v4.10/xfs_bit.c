int
F_1 ( T_1 * V_1 , T_1 V_2 )
{
T_1 V_3 ;
for ( V_3 = 0 ; V_3 < V_2 ; V_3 ++ ) {
if ( V_1 [ V_3 ] != 0 )
return 0 ;
}
return 1 ;
}
int
F_2 ( T_1 * V_1 , T_1 V_2 , T_1 V_4 )
{
T_1 * V_5 = ( ( unsigned int * ) V_1 ) + ( V_4 >> V_6 ) ;
T_1 V_7 = 0 ;
T_1 V_8 ;
V_2 <<= V_6 ;
ASSERT ( V_4 < V_2 ) ;
V_2 -= V_4 & ~ ( V_9 - 1 ) ;
V_4 &= ( V_9 - 1 ) ;
if ( V_4 ) {
V_8 = * V_5 ++ ;
V_8 |= ( ~ 0U >> ( V_9 - V_4 ) ) ;
if ( V_8 != ~ 0U )
goto V_10;
V_7 += V_9 ;
V_2 -= V_9 ;
}
while ( V_2 ) {
if ( ( V_8 = * V_5 ++ ) != ~ 0U )
goto V_10;
V_7 += V_9 ;
V_2 -= V_9 ;
}
return V_7 - V_4 ;
V_10:
return V_7 + F_3 ( V_8 ) - V_4 ;
}
int F_4 ( T_1 * V_1 , T_1 V_2 , T_1 V_4 )
{
T_1 * V_5 = ( ( unsigned int * ) V_1 ) + ( V_4 >> V_6 ) ;
T_1 V_7 = V_4 & ~ ( V_9 - 1 ) ;
T_1 V_8 ;
V_2 <<= V_6 ;
if ( V_4 >= V_2 )
return - 1 ;
V_2 -= V_7 ;
V_4 &= ( V_9 - 1 ) ;
if ( V_4 ) {
V_8 = * V_5 ++ ;
V_8 &= ( ~ 0U << V_4 ) ;
if ( V_8 != 0U )
goto V_10;
V_7 += V_9 ;
V_2 -= V_9 ;
}
while ( V_2 ) {
if ( ( V_8 = * V_5 ++ ) != 0U )
goto V_10;
V_7 += V_9 ;
V_2 -= V_9 ;
}
return - 1 ;
V_10:
return V_7 + F_5 ( V_8 ) - 1 ;
}
