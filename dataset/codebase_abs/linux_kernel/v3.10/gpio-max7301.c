static int F_1 ( struct V_1 * V_2 , unsigned int V_3 ,
unsigned int V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
T_1 V_7 = ( ( V_3 & 0x7F ) << 8 ) | ( V_4 & 0xFF ) ;
return F_3 ( V_6 , ( const V_8 * ) & V_7 , sizeof( V_7 ) ) ;
}
static int F_4 ( struct V_1 * V_2 , unsigned int V_3 )
{
int V_9 ;
T_1 V_7 ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
V_7 = 0x8000 | ( V_3 << 8 ) ;
V_9 = F_3 ( V_6 , ( const V_8 * ) & V_7 , sizeof( V_7 ) ) ;
if ( V_9 )
return V_9 ;
V_9 = F_5 ( V_6 , ( V_8 * ) & V_7 , sizeof( V_7 ) ) ;
if ( V_9 )
return V_9 ;
return V_7 & 0xff ;
}
static int F_6 ( struct V_5 * V_6 )
{
struct V_10 * V_11 ;
int V_9 ;
if ( V_6 -> V_2 . V_12 )
V_6 -> V_13 = 16 ;
V_9 = F_7 ( V_6 ) ;
if ( V_9 < 0 )
return V_9 ;
V_11 = F_8 ( & V_6 -> V_2 , sizeof( struct V_10 ) , V_14 ) ;
if ( ! V_11 )
return - V_15 ;
V_11 -> V_16 = F_4 ;
V_11 -> V_17 = F_1 ;
V_11 -> V_2 = & V_6 -> V_2 ;
V_9 = F_9 ( V_11 ) ;
return V_9 ;
}
static int F_10 ( struct V_5 * V_6 )
{
return F_11 ( & V_6 -> V_2 ) ;
}
static int T_2 F_12 ( void )
{
return F_13 ( & V_18 ) ;
}
static void T_3 F_14 ( void )
{
F_15 ( & V_18 ) ;
}
