static unsigned long F_1 ( struct V_1 * V_1 )
{
return V_1 -> V_2 -> V_3 / 2 ;
}
static unsigned long F_2 ( struct V_1 * V_1 )
{
unsigned long V_4 = 1 ;
if ( F_3 ( V_5 ) & ( 1 << 14 ) )
V_4 = ( ( ( F_3 ( V_6 ) >> 24 ) & 0x3f ) + 1 ) * 2 ;
return V_1 -> V_2 -> V_3 * V_4 ;
}
static unsigned long F_4 ( struct V_1 * V_1 )
{
unsigned long V_4 = 1 ;
if ( F_3 ( V_7 ) & ( 1 << 31 ) )
V_4 = ( ( ( F_3 ( V_7 ) >> 24 ) & 0x3f ) + 1 ) * 2 ;
return V_1 -> V_2 -> V_3 * V_4 ;
}
static void F_5 ( struct V_1 * V_1 )
{
unsigned long V_8 ;
V_8 = F_3 ( V_9 ) ;
V_8 |= ( 1 << 31 ) ;
F_6 ( V_8 , V_9 ) ;
}
void T_1 F_7 ( void )
{
int V_10 , V_11 = 0 ;
for ( V_10 = 0 ; ! V_11 && ( V_10 < F_8 ( V_12 ) ) ; V_10 ++ )
V_11 = F_9 ( V_12 [ V_10 ] ) ;
if ( ! V_11 )
V_11 = F_10 ( V_13 , V_14 , & V_15 ) ;
if ( ! V_11 )
V_11 = F_11 ( V_16 , V_17 ) ;
if ( ! V_11 )
V_11 = F_12 ( V_18 , V_19 ) ;
F_13 ( V_20 , F_8 ( V_20 ) ) ;
if ( ! V_11 )
F_14 () ;
else
F_15 ( L_1 ) ;
}
