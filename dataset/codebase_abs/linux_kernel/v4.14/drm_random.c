static inline T_1 F_1 ( T_1 V_1 , struct V_2 * V_3 )
{
return F_2 ( ( V_4 ) F_3 ( V_3 ) * V_1 ) ;
}
void F_4 ( unsigned int * V_5 , unsigned int V_6 ,
struct V_2 * V_3 )
{
unsigned int V_7 , V_8 ;
for ( V_7 = 0 ; V_7 < V_6 ; ++ V_7 ) {
F_5 ( sizeof( unsigned int ) > sizeof( T_1 ) ) ;
V_8 = F_1 ( V_6 , V_3 ) ;
F_6 ( V_5 [ V_7 ] , V_5 [ V_8 ] ) ;
}
}
unsigned int * F_7 ( unsigned int V_6 , struct V_2 * V_3 )
{
unsigned int * V_5 , V_7 ;
V_5 = F_8 ( V_6 , sizeof( * V_5 ) , V_9 ) ;
if ( ! V_5 )
return V_5 ;
for ( V_7 = 0 ; V_7 < V_6 ; V_7 ++ )
V_5 [ V_7 ] = V_7 ;
F_4 ( V_5 , V_6 , V_3 ) ;
return V_5 ;
}
