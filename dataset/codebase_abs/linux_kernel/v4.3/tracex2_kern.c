int F_1 ( struct V_1 * V_2 )
{
long V_3 = 0 ;
long V_4 = 1 ;
long * V_5 ;
F_2 ( & V_3 , sizeof( V_3 ) , ( void * ) F_3 ( V_2 ) ) ;
V_5 = F_4 ( & V_6 , & V_3 ) ;
if ( V_5 )
* V_5 += 1 ;
else
F_5 ( & V_6 , & V_3 , & V_4 , V_7 ) ;
return 0 ;
}
static unsigned int F_6 ( unsigned int V_8 )
{
unsigned int V_9 ;
unsigned int V_10 ;
V_9 = ( V_8 > 0xFFFF ) << 4 ; V_8 >>= V_9 ;
V_10 = ( V_8 > 0xFF ) << 3 ; V_8 >>= V_10 ; V_9 |= V_10 ;
V_10 = ( V_8 > 0xF ) << 2 ; V_8 >>= V_10 ; V_9 |= V_10 ;
V_10 = ( V_8 > 0x3 ) << 1 ; V_8 >>= V_10 ; V_9 |= V_10 ;
V_9 |= ( V_8 >> 1 ) ;
return V_9 ;
}
static unsigned int F_7 ( unsigned long V_8 )
{
unsigned int V_11 = V_8 >> 32 ;
if ( V_11 )
return F_6 ( V_11 ) + 32 ;
else
return F_6 ( V_8 ) ;
}
int F_8 ( struct V_1 * V_2 )
{
long V_12 = F_9 ( V_2 ) ;
long V_4 = 1 ;
long * V_5 ;
struct V_13 V_14 = {} ;
V_14 . V_15 = F_7 ( V_12 ) ;
V_14 . V_16 = F_10 () ;
V_14 . V_17 = F_11 () ;
F_12 ( & V_14 . V_18 , sizeof( V_14 . V_18 ) ) ;
V_5 = F_4 ( & V_19 , & V_14 ) ;
if ( V_5 )
F_13 ( V_5 , 1 ) ;
else
F_5 ( & V_19 , & V_14 , & V_4 , V_7 ) ;
return 0 ;
}
