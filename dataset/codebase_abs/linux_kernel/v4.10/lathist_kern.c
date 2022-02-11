int F_1 ( struct V_1 * V_2 )
{
int V_3 = F_2 () ;
T_1 * V_4 = F_3 ( & V_5 , & V_3 ) ;
if ( V_4 )
* V_4 = F_4 () ;
return 0 ;
}
static unsigned int F_5 ( unsigned int V_6 )
{
unsigned int V_7 ;
unsigned int V_8 ;
V_7 = ( V_6 > 0xFFFF ) << 4 ; V_6 >>= V_7 ;
V_8 = ( V_6 > 0xFF ) << 3 ; V_6 >>= V_8 ; V_7 |= V_8 ;
V_8 = ( V_6 > 0xF ) << 2 ; V_6 >>= V_8 ; V_7 |= V_8 ;
V_8 = ( V_6 > 0x3 ) << 1 ; V_6 >>= V_8 ; V_7 |= V_8 ;
V_7 |= ( V_6 >> 1 ) ;
return V_7 ;
}
static unsigned int F_6 ( unsigned long V_6 )
{
unsigned int V_9 = V_6 >> 32 ;
if ( V_9 )
return F_5 ( V_9 ) + 32 ;
else
return F_5 ( V_6 ) ;
}
int F_7 ( struct V_1 * V_2 )
{
T_1 * V_4 , V_10 , V_11 ;
int V_12 , V_3 ;
long * V_13 ;
V_3 = F_2 () ;
V_4 = F_3 ( & V_5 , & V_3 ) ;
if ( ! V_4 )
return 0 ;
V_10 = F_4 () ;
V_11 = F_6 ( V_10 - * V_4 ) ;
if ( V_11 > V_14 - 1 )
V_11 = V_14 - 1 ;
V_12 = V_3 * V_14 + V_11 ;
V_13 = F_3 ( & V_15 , & V_12 ) ;
if ( V_13 )
F_8 ( ( long * ) V_13 , 1 ) ;
return 0 ;
}
