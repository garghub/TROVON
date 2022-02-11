int F_1 ( struct V_1 * V_2 , unsigned int V_3 )
{
unsigned long V_4 = 1 << V_2 -> V_5 ;
if ( ! ( V_6 & V_4 ) )
return - V_7 ;
F_2 ( L_1 ,
V_3 ? L_2 : L_3 , V_2 -> V_5 ) ;
if ( ! V_3 )
V_8 |= V_4 ;
else
V_8 &= ~ V_4 ;
return 0 ;
}
static int F_3 ( void )
{
unsigned int V_9 ;
for ( V_9 = 0 ; V_9 < F_4 ( V_10 ) ; V_9 ++ )
V_10 [ V_9 ] = F_5 ( V_11 + ( V_9 * 4 ) ) ;
for ( V_9 = 0 ; V_9 < F_4 ( V_12 ) ; V_9 ++ )
V_12 [ V_9 ] = F_5 ( V_13 + ( V_9 * 4 ) ) ;
F_6 ( V_14 , F_4 ( V_14 ) ) ;
V_15 = F_5 ( V_16 ) ;
return 0 ;
}
static void F_7 ( void )
{
unsigned int V_9 ;
for ( V_9 = 0 ; V_9 < F_4 ( V_10 ) ; V_9 ++ )
F_8 ( V_10 [ V_9 ] , V_11 + ( V_9 * 4 ) ) ;
for ( V_9 = 0 ; V_9 < F_4 ( V_12 ) ; V_9 ++ )
F_8 ( V_12 [ V_9 ] , V_13 + ( V_9 * 4 ) ) ;
F_9 ( V_14 , F_4 ( V_14 ) ) ;
F_8 ( V_15 , V_16 ) ;
}
static int F_10 ( void )
{
F_6 ( V_17 , F_4 ( V_17 ) ) ;
return 0 ;
}
static void F_11 ( void )
{
F_9 ( V_17 , F_4 ( V_17 ) ) ;
}
