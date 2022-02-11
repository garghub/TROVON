static unsigned long F_1 ( struct V_1 * V_1 )
{
return V_1 -> V_2 -> V_3 * 4 ;
}
void T_1 F_2 ( void )
{
int V_4 , V_5 = 0 ;
for ( V_4 = 0 ; ! V_5 && ( V_4 < F_3 ( V_6 ) ) ; V_4 ++ )
V_5 = F_4 ( V_6 [ V_4 ] ) ;
if ( ! V_5 )
V_5 = F_5 ( V_7 , V_8 , & V_9 ) ;
if ( ! V_5 )
V_5 = F_6 ( V_10 , V_11 ) ;
for ( V_4 = 0 ; ! V_5 && ( V_4 < F_3 ( V_12 ) ) ; V_4 ++ )
V_5 = F_4 ( V_12 [ V_4 ] ) ;
F_7 ( V_13 , F_3 ( V_13 ) ) ;
if ( ! V_5 )
F_8 () ;
else
F_9 ( L_1 ) ;
}
