static unsigned long F_1 ( struct V_1 * V_1 )
{
int V_2 = 12 ;
T_1 V_3 = F_2 ( V_4 ) ;
if ( ( V_3 & V_5 ) & V_6 )
V_2 = 16 ;
return V_1 -> V_7 -> V_8 * V_2 ;
}
int T_2 F_3 ( void )
{
int V_9 , V_10 = 0 ;
for ( V_9 = 0 ; V_9 < F_4 ( V_11 ) ; V_9 ++ )
V_10 |= F_5 ( V_11 [ V_9 ] ) ;
F_6 ( V_12 , F_4 ( V_12 ) ) ;
if ( ! V_10 )
V_10 = F_7 ( V_13 , F_4 ( V_13 ) ,
& V_14 ) ;
if ( ! V_10 )
V_10 = F_8 ( V_15 , V_16 ) ;
return V_10 ;
}
