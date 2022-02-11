int F_1 ( struct V_1 * V_2 )
{
long V_3 = 0 ;
long V_4 = 1 ;
long * V_5 ;
F_2 ( & V_3 , sizeof( V_3 ) , ( void * ) V_2 -> V_6 ) ;
V_5 = F_3 ( & V_7 , & V_3 ) ;
if ( V_5 )
* V_5 += 1 ;
else
F_4 ( & V_7 , & V_3 , & V_4 , V_8 ) ;
return 0 ;
}
static unsigned int F_5 ( unsigned int V_9 )
{
unsigned int V_10 ;
unsigned int V_11 ;
V_10 = ( V_9 > 0xFFFF ) << 4 ; V_9 >>= V_10 ;
V_11 = ( V_9 > 0xFF ) << 3 ; V_9 >>= V_11 ; V_10 |= V_11 ;
V_11 = ( V_9 > 0xF ) << 2 ; V_9 >>= V_11 ; V_10 |= V_11 ;
V_11 = ( V_9 > 0x3 ) << 1 ; V_9 >>= V_11 ; V_10 |= V_11 ;
V_10 |= ( V_9 >> 1 ) ;
return V_10 ;
}
static unsigned int F_6 ( unsigned long V_9 )
{
unsigned int V_12 = V_9 >> 32 ;
if ( V_12 )
return F_5 ( V_12 ) + 32 ;
else
return F_5 ( V_9 ) ;
}
int F_7 ( struct V_1 * V_2 )
{
long V_13 = V_2 -> V_14 ;
long V_4 = 1 ;
long * V_5 ;
struct V_15 V_16 = {} ;
V_16 . V_17 = F_6 ( V_13 ) ;
V_16 . V_18 = F_8 () ;
V_16 . V_19 = F_9 () ;
F_10 ( & V_16 . V_20 , sizeof( V_16 . V_20 ) ) ;
V_5 = F_3 ( & V_21 , & V_16 ) ;
if ( V_5 )
F_11 ( V_5 , 1 ) ;
else
F_4 ( & V_21 , & V_16 , & V_4 , V_8 ) ;
return 0 ;
}
