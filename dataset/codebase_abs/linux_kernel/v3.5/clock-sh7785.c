static unsigned long F_1 ( struct V_1 * V_1 )
{
int V_2 ;
V_2 = F_2 ( V_3 ) ? 36 : 72 ;
return V_1 -> V_4 -> V_5 * V_2 ;
}
int T_1 F_3 ( void )
{
int V_6 , V_7 = 0 ;
for ( V_6 = 0 ; V_6 < F_4 ( V_8 ) ; V_6 ++ )
V_7 |= F_5 ( V_8 [ V_6 ] ) ;
for ( V_6 = 0 ; V_6 < F_4 ( V_9 ) ; V_6 ++ )
F_6 ( & V_9 [ V_6 ] ) ;
if ( ! V_7 )
V_7 = F_7 ( V_10 , F_4 ( V_10 ) ,
& V_11 ) ;
if ( ! V_7 )
V_7 = F_8 ( V_12 , V_13 ) ;
return V_7 ;
}
