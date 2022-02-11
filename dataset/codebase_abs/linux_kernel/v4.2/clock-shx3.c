static unsigned long F_1 ( struct V_1 * V_1 )
{
return V_1 -> V_2 -> V_3 * 72 ;
}
int T_1 F_2 ( void )
{
int V_4 , V_5 = 0 ;
for ( V_4 = 0 ; V_4 < F_3 ( V_6 ) ; V_4 ++ )
V_5 |= F_4 ( V_6 [ V_4 ] ) ;
F_5 ( V_7 , F_3 ( V_7 ) ) ;
if ( ! V_5 )
V_5 = F_6 ( V_8 , F_3 ( V_8 ) ,
& V_9 ) ;
if ( ! V_5 )
V_5 = F_7 ( V_10 , V_11 ) ;
return V_5 ;
}
