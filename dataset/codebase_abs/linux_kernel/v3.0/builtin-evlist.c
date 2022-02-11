static int F_1 ( void )
{
struct V_1 * V_2 ;
struct V_3 * V_4 ;
V_2 = F_2 ( V_5 , V_6 , 0 , false , NULL ) ;
if ( V_2 == NULL )
return - V_7 ;
F_3 (pos, &session->evlist->entries, node)
printf ( L_1 , F_4 ( V_4 ) ) ;
F_5 ( V_2 ) ;
return 0 ;
}
int F_6 ( int V_8 , const char * * V_9 , const char * T_1 V_10 )
{
V_8 = F_7 ( V_8 , V_9 , V_11 , V_12 , 0 ) ;
if ( V_8 )
F_8 ( V_12 , V_11 ) ;
return F_1 () ;
}
