static void F_1 ( struct V_1 * V_2 , int V_3 ,
bool V_4 )
{
unsigned int V_5 , V_6 , V_7 ;
unsigned int V_8 ;
V_3 ++ ;
V_6 = V_3 / 32 ;
V_7 = V_3 % 32 ;
if ( V_6 <= 3 )
V_5 = V_9 + V_6 * sizeof( int * ) ;
else
V_5 = V_10 + ( V_6 - 4 ) * sizeof( int * ) ;
V_8 = F_2 ( V_2 , V_5 ) ;
if ( V_4 )
V_8 &= ~ ( 0x1 << V_7 ) ;
else
V_8 |= 0x1 << V_7 ;
F_3 ( V_2 , V_8 , V_5 ) ;
}
static int F_4 ( struct V_11 * V_12 )
{
return F_5 ( V_12 , & V_13 ) ;
}
static int T_1 F_6 ( void )
{
return F_7 ( & V_14 ) ;
}
