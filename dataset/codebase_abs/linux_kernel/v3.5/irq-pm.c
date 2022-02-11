int F_1 ( struct V_1 * V_2 , unsigned int V_3 )
{
unsigned long V_4 = 1 << ( V_2 -> V_5 - V_6 ) ;
if ( ! ( V_7 & V_4 ) )
return - V_8 ;
F_2 ( V_9 L_1 ,
V_3 ? L_2 : L_3 , V_2 -> V_5 ) ;
if ( ! V_3 )
V_10 |= V_4 ;
else
V_10 &= ~ V_4 ;
return 0 ;
}
int F_3 ( void )
{
unsigned int V_11 ;
for ( V_11 = 0 ; V_11 < F_4 ( V_12 ) ; V_11 ++ )
V_12 [ V_11 ] = F_5 ( V_13 + ( V_11 * 4 ) ) ;
for ( V_11 = 0 ; V_11 < F_4 ( V_14 ) ; V_11 ++ )
V_14 [ V_11 ] = F_5 ( V_15 + ( V_11 * 4 ) ) ;
F_6 ( V_16 , F_4 ( V_16 ) ) ;
V_17 = F_5 ( V_18 ) ;
return 0 ;
}
void F_7 ( void )
{
unsigned int V_11 ;
for ( V_11 = 0 ; V_11 < F_4 ( V_12 ) ; V_11 ++ )
F_8 ( V_12 [ V_11 ] , V_13 + ( V_11 * 4 ) ) ;
for ( V_11 = 0 ; V_11 < F_4 ( V_14 ) ; V_11 ++ )
F_8 ( V_14 [ V_11 ] , V_15 + ( V_11 * 4 ) ) ;
F_9 ( V_16 , F_4 ( V_16 ) ) ;
F_8 ( V_17 , V_18 ) ;
}
