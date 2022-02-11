void F_1 ( T_1 * V_1 )
{
V_1 -> V_2 = 0 ;
V_1 -> V_3 = 0 ;
}
T_2 F_2 ( T_1 * V_1 )
{
if( V_1 -> V_2 == 0 && V_1 -> V_3 == 0 ) {
return TRUE ;
} else {
return FALSE ;
}
}
void F_3 ( T_1 * V_1 )
{
V_1 -> V_2 = 0 ;
V_1 -> V_3 = V_4 ;
}
T_2 F_4 ( T_1 * V_1 )
{
if( V_1 -> V_2 == 0 && V_1 -> V_3 == V_4 ) {
return TRUE ;
} else {
return FALSE ;
}
}
void F_5 ( T_1 * V_5 , const T_1 * V_6 )
{
V_5 -> V_2 = V_6 -> V_2 ;
V_5 -> V_3 = V_6 -> V_3 ;
}
void F_6 ( T_1 * V_7 , const T_1 * V_6 , const T_1 * V_5 )
{
if ( V_6 -> V_2 == V_5 -> V_2 ) {
V_7 -> V_2 = 0 ;
V_7 -> V_3 = V_6 -> V_3 - V_5 -> V_3 ;
} else if ( V_6 -> V_2 <= V_5 -> V_2 ) {
V_7 -> V_2 = V_6 -> V_2 - V_5 -> V_2 ;
V_7 -> V_3 = V_6 -> V_3 - V_5 -> V_3 ;
if( V_7 -> V_3 > 0 ) {
V_7 -> V_3 -= V_8 ;
V_7 -> V_2 ++ ;
}
} else {
V_7 -> V_2 = V_6 -> V_2 - V_5 -> V_2 ;
V_7 -> V_3 = V_6 -> V_3 - V_5 -> V_3 ;
if( V_7 -> V_3 < 0 ) {
V_7 -> V_3 += V_8 ;
V_7 -> V_2 -- ;
}
}
}
void F_7 ( T_1 * V_9 , const T_1 * V_5 , const T_1 * V_6 )
{
V_9 -> V_2 = V_5 -> V_2 + V_6 -> V_2 ;
V_9 -> V_3 = V_5 -> V_3 + V_6 -> V_3 ;
if( V_9 -> V_3 >= V_8 || ( V_9 -> V_3 > 0 && V_9 -> V_2 < 0 ) ) {
V_9 -> V_3 -= V_8 ;
V_9 -> V_2 ++ ;
} else if( V_9 -> V_3 <= - V_8 || ( V_9 -> V_3 < 0 && V_9 -> V_2 > 0 ) ) {
V_9 -> V_3 += V_8 ;
V_9 -> V_2 -- ;
}
}
int F_8 ( const T_1 * V_5 , const T_1 * V_6 )
{
if ( V_5 -> V_2 == V_6 -> V_2 ) {
return V_5 -> V_3 - V_6 -> V_3 ;
} else {
return ( int ) ( V_5 -> V_2 - V_6 -> V_2 ) ;
}
}
double F_9 ( const T_1 * V_1 )
{
return ( ( double ) V_1 -> V_2 * 1000 + ( double ) V_1 -> V_3 / 1000000 ) ;
}
double F_10 ( const T_1 * V_1 )
{
return ( ( double ) V_1 -> V_2 + ( double ) V_1 -> V_3 / 1000000000 ) ;
}
double F_11 ( const struct V_10 * V_1 )
{
return ( ( double ) V_1 -> V_2 + ( double ) V_1 -> V_3 / 1000000000 ) ;
}
