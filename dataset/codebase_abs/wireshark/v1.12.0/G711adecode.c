void *
F_1 ( void )
{
return NULL ;
}
void
F_2 ( void * T_1 V_1 )
{
}
int
F_3 ( void * T_1 V_1 )
{
return 1 ;
}
int
F_4 ( void * T_1 V_1 )
{
return 8000 ;
}
int
F_5 ( void * T_1 V_1 , const void * V_2 , int V_3 , void * V_4 ,
int * V_5 )
{
const T_2 * V_6 = ( const T_2 * ) V_2 ;
T_3 * V_7 = ( T_3 * ) V_4 ;
int V_8 ;
if ( ! V_4 || ! V_5 ) {
return V_3 * 2 ;
}
for ( V_8 = 0 ; V_8 < V_3 ; V_8 ++ )
{
V_7 [ V_8 ] = V_9 [ V_6 [ V_8 ] ] ;
}
* V_5 = V_3 * 2 ;
return V_3 * 2 ;
}
