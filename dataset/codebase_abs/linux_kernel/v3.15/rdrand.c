static int T_1 F_1 ( char * V_1 )
{
F_2 ( V_2 ) ;
F_2 ( V_3 ) ;
return 1 ;
}
void F_3 ( struct V_4 * V_5 )
{
#ifdef F_4
unsigned long V_6 ;
int V_7 , V_8 , V_9 ;
if ( ! F_5 ( V_5 , V_2 ) )
return;
for ( V_8 = V_7 = 0 ; V_7 < V_10 ; V_7 ++ ) {
V_9 = F_6 ( & V_6 ) ;
if ( V_9 )
V_8 ++ ;
}
if ( V_8 != V_10 )
F_7 ( V_5 , V_2 ) ;
#endif
}
