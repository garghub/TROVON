int F_1 ( struct V_1 * V_2 )
{
unsigned long V_3 = V_4 + V_5 ;
int V_6 = 1 ;
if ( F_2 ( V_2 -> V_7 ) )
return 0 ;
if ( ( F_3 ( V_8 ) == V_9 ) &&
( ( F_3 ( V_10 ) & V_11 ) == 0 ) )
return 0 ;
do {
V_6 = ( F_3 ( V_8 ) != V_9 ) ;
} while ( V_6 && ! F_4 ( V_4 , V_3 ) );
if ( V_6 )
return - V_12 ;
do {
V_6 = ( ( F_3 ( V_10 ) &
V_11 ) != 0 ) ;
} while ( V_6 && ! F_4 ( V_4 , V_3 ) );
return ( V_6 ) ? - V_12 : 0 ;
}
