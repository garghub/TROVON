static unsigned long F_1 ( struct V_1 * V_1 )
{
int V_2 ;
V_2 = ( V_3 . V_4 () & 0xf ) < 3 ? 64 : 32 ;
return V_1 -> V_5 -> V_6 * V_2 ;
}
int T_1 F_2 ( void )
{
int V_7 , V_8 = 0 ;
for ( V_7 = 0 ; V_7 < F_3 ( V_9 ) ; V_7 ++ )
V_8 |= F_4 ( V_9 [ V_7 ] ) ;
for ( V_7 = 0 ; V_7 < F_3 ( V_10 ) ; V_7 ++ )
F_5 ( & V_10 [ V_7 ] ) ;
if ( ! V_8 )
V_8 = F_6 ( V_11 , F_3 ( V_11 ) ,
& V_12 ) ;
if ( ! V_8 )
V_8 = F_7 ( V_13 , V_14 ) ;
return V_8 ;
}
