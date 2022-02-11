static unsigned int F_1 ( unsigned int V_1 )
{
unsigned int V_2 ;
unsigned int V_3 ;
V_2 = ( V_1 > 0xFFFF ) << 4 ; V_1 >>= V_2 ;
V_3 = ( V_1 > 0xFF ) << 3 ; V_1 >>= V_3 ; V_2 |= V_3 ;
V_3 = ( V_1 > 0xF ) << 2 ; V_1 >>= V_3 ; V_2 |= V_3 ;
V_3 = ( V_1 > 0x3 ) << 1 ; V_1 >>= V_3 ; V_2 |= V_3 ;
V_2 |= ( V_1 >> 1 ) ;
return V_2 ;
}
static unsigned int F_2 ( unsigned long V_1 )
{
unsigned int V_4 = V_1 >> 32 ;
if ( V_4 )
return F_1 ( V_4 ) + 32 ;
else
return F_1 ( V_1 ) ;
}
int F_3 ( struct V_5 * V_6 )
{
T_1 * V_7 , V_8 , V_9 = 1 ;
V_8 = F_2 ( V_6 -> V_10 ) ;
V_7 = F_4 ( & V_11 , & V_8 ) ;
if ( V_7 )
F_5 ( V_7 , 1 ) ;
else
F_6 ( & V_11 , & V_8 , & V_9 , V_12 ) ;
return V_13 ;
}
