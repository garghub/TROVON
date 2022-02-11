static int T_1 F_1 ( char * V_1 )
{
F_2 ( V_2 ) ;
return 1 ;
}
void F_3 ( struct V_3 * V_4 )
{
#ifdef F_4
unsigned long V_5 ;
int V_6 , V_7 , V_8 ;
if ( ! F_5 ( V_4 , V_2 ) )
return;
for ( V_7 = V_6 = 0 ; V_6 < V_9 ; V_6 ++ ) {
V_8 = F_6 ( & V_5 ) ;
if ( V_8 )
V_7 ++ ;
}
if ( V_7 != V_9 )
F_7 ( V_4 , V_2 ) ;
#endif
}
