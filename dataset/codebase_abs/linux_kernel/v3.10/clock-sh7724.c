static unsigned long F_1 ( struct V_1 * V_1 )
{
unsigned long V_2 = 0 ;
unsigned long div = 1 ;
if ( F_2 ( V_3 ) & 0x1000 )
V_2 = F_2 ( V_4 ) & 0x3ff ;
if ( F_2 ( V_4 ) & 0x4000 )
div = 2 ;
return ( V_1 -> V_5 -> V_6 * V_2 ) / div ;
}
static unsigned long F_3 ( struct V_1 * V_1 )
{
unsigned long V_2 = 1 ;
if ( F_2 ( V_3 ) & 0x4000 )
V_2 = ( ( ( F_2 ( V_7 ) >> 24 ) & 0x3f ) + 1 ) * 2 ;
return V_1 -> V_5 -> V_6 * V_2 ;
}
static unsigned long F_4 ( struct V_1 * V_1 )
{
return V_1 -> V_5 -> V_6 / 3 ;
}
static void F_5 ( struct V_1 * V_1 )
{
unsigned long V_8 ;
V_8 = F_2 ( V_7 ) ;
V_8 |= ( 1 << 31 ) ;
F_6 ( V_8 , V_7 ) ;
}
int T_1 F_7 ( void )
{
int V_9 , V_10 = 0 ;
if ( F_2 ( V_3 ) & 0x1000 )
V_11 . V_5 = & V_12 ;
else
V_11 . V_5 = & V_13 ;
for ( V_9 = 0 ; ! V_10 && ( V_9 < F_8 ( V_14 ) ) ; V_9 ++ )
V_10 = F_9 ( V_14 [ V_9 ] ) ;
F_10 ( V_15 , F_8 ( V_15 ) ) ;
if ( ! V_10 )
V_10 = F_11 ( V_16 , V_17 , & V_18 ) ;
if ( ! V_10 )
V_10 = F_12 ( V_19 , V_20 ) ;
if ( ! V_10 )
V_10 = F_13 ( V_21 , V_22 ) ;
return V_10 ;
}
