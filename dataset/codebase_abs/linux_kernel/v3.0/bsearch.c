void * bsearch ( const void * V_1 , const void * V_2 , T_1 V_3 , T_1 V_4 ,
int (* F_1)( const void * V_1 , const void * V_5 ) )
{
T_1 V_6 = 0 , V_7 = V_3 ;
int V_8 ;
while ( V_6 < V_7 ) {
T_1 V_9 = V_6 + ( V_7 - V_6 ) / 2 ;
V_8 = F_1 ( V_1 , V_2 + V_9 * V_4 ) ;
if ( V_8 < 0 )
V_7 = V_9 ;
else if ( V_8 > 0 )
V_6 = V_9 + 1 ;
else
return ( void * ) V_2 + V_9 * V_4 ;
}
return NULL ;
}
