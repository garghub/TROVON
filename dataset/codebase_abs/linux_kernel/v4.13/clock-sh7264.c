static unsigned long F_1 ( struct V_1 * V_1 )
{
unsigned long V_2 = V_1 -> V_3 -> V_2 / V_4 ;
return V_2 * V_5 [ ( F_2 ( V_6 ) >> 8 ) & 1 ] ;
}
int T_1 F_3 ( void )
{
int V_7 , V_8 = 0 ;
if ( F_4 ( V_9 ) ) {
if ( F_4 ( V_10 ) )
V_4 = 3 ;
else
V_4 = 4 ;
} else
V_4 = 1 ;
for ( V_7 = 0 ; ! V_8 && ( V_7 < F_5 ( V_11 ) ) ; V_7 ++ )
V_8 = F_6 ( V_11 [ V_7 ] ) ;
F_7 ( V_12 , F_5 ( V_12 ) ) ;
if ( ! V_8 )
V_8 = F_8 ( V_13 , V_14 , & V_15 ) ;
if ( ! V_8 )
V_8 = F_9 ( V_16 , V_17 ) ;
return V_8 ;
}
