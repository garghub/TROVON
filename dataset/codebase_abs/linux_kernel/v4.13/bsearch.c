void * bsearch ( const void * V_1 , const void * V_2 , T_1 V_3 , T_1 V_4 ,
int (* F_1)( const void * V_1 , const void * V_5 ) )
{
const char * V_6 ;
int V_7 ;
while ( V_3 > 0 ) {
V_6 = V_2 + ( V_3 >> 1 ) * V_4 ;
V_7 = F_1 ( V_1 , V_6 ) ;
if ( V_7 == 0 )
return ( void * ) V_6 ;
if ( V_7 > 0 ) {
V_2 = V_6 + V_4 ;
V_3 -- ;
}
V_3 >>= 1 ;
}
return NULL ;
}
