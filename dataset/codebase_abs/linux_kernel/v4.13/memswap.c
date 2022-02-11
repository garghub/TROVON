void F_1 ( void * V_1 , int V_2 )
{
T_1 * V_3 = V_1 ;
while ( V_2 > 0 ) {
* V_3 = F_2 ( * V_3 ) ;
V_2 -= sizeof( T_1 ) ;
++ V_3 ;
}
}
void F_3 ( void * V_1 , int V_2 )
{
T_2 * V_3 = V_1 ;
while ( V_2 > 0 ) {
* V_3 = F_4 ( * V_3 ) ;
V_2 -= sizeof( T_2 ) ;
++ V_3 ;
}
}
