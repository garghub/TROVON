int F_1 ( const unsigned int V_1 , const char * V_2 , int V_3 ,
const char * V_4 , int V_5 )
{
if ( V_1 >= V_6 )
return - V_7 ;
if ( ! V_8 [ V_1 ] ) {
V_8 [ V_1 ] =
F_2 ( & V_9 , V_10 [ V_1 ] , NULL ) ;
if ( F_3 ( V_8 [ V_1 ] ) ) {
int V_11 = F_4 ( V_8 [ V_1 ] ) ;
F_5 ( L_1 , V_10 [ V_1 ] , V_11 ) ;
V_8 [ V_1 ] = NULL ;
return V_11 ;
}
}
return F_6 ( V_8 [ V_1 ] , V_2 , V_3 , V_4 , V_5 ) ;
}
