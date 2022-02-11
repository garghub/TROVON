int F_1 ( const struct V_1 * V_2 , unsigned char V_3 )
{
if ( ! V_2 -> V_4 ) {
F_2 ( L_1 ,
V_3 ) ;
return - V_5 ;
}
return ! F_3 ( ( const struct V_1 * * ) & V_6 [ V_3 ] ,
NULL , V_2 ) ? 0 : - 1 ;
}
int F_4 ( const struct V_7 * V_2 , unsigned char V_3 )
{
return ! F_3 ( ( const struct V_7 * * ) & V_8 [ V_3 ] ,
NULL , V_2 ) ? 0 : - 1 ;
}
int F_5 ( const struct V_1 * V_2 , unsigned char V_3 )
{
int V_9 ;
V_9 = ( F_3 ( ( const struct V_1 * * ) & V_6 [ V_3 ] ,
V_2 , NULL ) == V_2 ) ? 0 : - 1 ;
F_6 () ;
return V_9 ;
}
int F_7 ( const struct V_7 * V_2 , unsigned char V_3 )
{
int V_9 ;
V_9 = ( F_3 ( ( const struct V_7 * * ) & V_8 [ V_3 ] ,
V_2 , NULL ) == V_2 ) ? 0 : - 1 ;
F_6 () ;
return V_9 ;
}
