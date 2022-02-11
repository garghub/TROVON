unsigned int F_1 ( unsigned int V_1 , int V_2 )
{
int V_3 = F_2 ( V_1 , V_2 ) ;
if ( V_3 < 0 )
return 0 ;
F_3 ( V_3 ) ;
return V_3 ;
}
int F_4 ( void )
{
int V_3 = F_5 ( F_6 () ) ;
if ( V_3 >= 0 )
F_3 ( V_3 ) ;
return V_3 ;
}
void F_7 ( unsigned int V_3 )
{
F_8 ( V_3 ) ;
}
void F_9 ( struct V_4 * V_5 , unsigned int V_6 )
{
int V_7 ;
for ( V_7 = 0 ; V_7 < V_6 ; V_7 ++ )
F_10 ( F_11 ( V_5 [ V_7 ] . V_8 ) ) ;
}
