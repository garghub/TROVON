static unsigned long F_1 ( struct V_1 * V_1 )
{
unsigned long V_2 ;
if ( F_2 ( V_3 ) & 0x1000 )
V_2 = F_2 ( V_4 ) ;
else
V_2 = 0 ;
return V_1 -> V_5 -> V_6 * V_2 ;
}
static unsigned long F_3 ( struct V_1 * V_1 )
{
unsigned long V_2 = 1 ;
unsigned long div = 1 ;
if ( F_2 ( V_3 ) & 0x4000 )
V_2 = ( ( ( F_2 ( V_7 ) >> 24 ) & 0x1f ) + 1 ) ;
else
div = 2 ;
return ( V_1 -> V_5 -> V_6 * V_2 ) / div ;
}
int T_1 F_4 ( void )
{
int V_8 , V_9 = 0 ;
if ( F_2 ( V_3 ) & 0x1000 )
V_10 . V_5 = & V_11 ;
else
V_10 . V_5 = & V_12 ;
for ( V_8 = 0 ; ! V_9 && ( V_8 < F_5 ( V_13 ) ) ; V_8 ++ )
V_9 |= F_6 ( V_13 [ V_8 ] ) ;
F_7 ( V_14 , F_5 ( V_14 ) ) ;
if ( ! V_9 )
V_9 = F_8 ( V_15 , V_16 , & V_17 ) ;
if ( ! V_9 )
V_9 = F_9 ( V_18 ,
V_19 , & V_17 ) ;
if ( ! V_9 )
V_9 = F_10 ( V_20 ,
V_21 , & V_17 ) ;
if ( ! V_9 )
V_9 = F_11 ( V_22 , V_23 ) ;
if ( ! V_9 )
V_9 = F_12 ( V_24 , V_25 ) ;
return V_9 ;
}
