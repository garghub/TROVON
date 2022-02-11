static unsigned long F_1 ( struct V_1 * V_1 )
{
return V_1 -> V_2 -> V_3 * V_4 ;
}
static unsigned long F_2 ( struct V_1 * V_1 )
{
return V_1 -> V_2 -> V_3 / 8 ;
}
static unsigned long F_3 ( struct V_1 * V_1 )
{
return V_1 -> V_2 -> V_3 / 4 ;
}
int T_1 F_4 ( void )
{
int V_5 , V_6 = 0 ;
for ( V_5 = 0 ; ! V_6 && ( V_5 < F_5 ( V_7 ) ) ; V_5 ++ )
V_6 = F_6 ( V_7 [ V_5 ] ) ;
F_7 ( V_8 , F_5 ( V_8 ) ) ;
if ( ! V_6 )
V_6 = F_8 ( V_9 , V_10 , & V_11 ) ;
if ( ! V_6 )
V_6 = F_9 ( V_12 , V_13 ) ;
return V_6 ;
}
