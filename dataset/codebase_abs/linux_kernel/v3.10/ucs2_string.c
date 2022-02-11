unsigned long
F_1 ( const T_1 * V_1 , T_2 V_2 )
{
unsigned long V_3 = 0 ;
while ( * V_1 ++ != 0 && V_3 < V_2 )
V_3 ++ ;
return V_3 ;
}
unsigned long
F_2 ( const T_1 * V_1 )
{
return F_1 ( V_1 , ~ 0UL ) ;
}
unsigned long
F_3 ( const T_1 * V_4 , unsigned long V_2 )
{
return F_1 ( V_4 , V_2 / sizeof( T_1 ) ) * sizeof( T_1 ) ;
}
int
F_4 ( const T_1 * V_5 , const T_1 * V_6 , T_2 V_7 )
{
while ( 1 ) {
if ( V_7 == 0 )
return 0 ;
if ( * V_5 < * V_6 )
return - 1 ;
if ( * V_5 > * V_6 )
return 1 ;
if ( * V_5 == 0 )
return 0 ;
V_5 ++ ;
V_6 ++ ;
V_7 -- ;
}
}
