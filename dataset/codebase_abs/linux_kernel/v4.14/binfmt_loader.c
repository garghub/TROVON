static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = (struct V_3 * ) V_2 -> V_5 ;
unsigned long V_6 ;
struct V_7 * V_7 ;
int V_8 ;
if ( V_4 -> V_9 . V_10 != 0x183 || ( V_4 -> V_9 . V_11 & 0x3000 ) != 0x3000 )
return - V_12 ;
if ( V_2 -> V_6 )
return - V_12 ;
F_2 ( V_2 -> V_7 ) ;
F_3 ( V_2 -> V_7 ) ;
V_2 -> V_7 = NULL ;
V_6 = V_2 -> V_13 -> V_14 - sizeof( void * ) ;
V_7 = F_4 ( L_1 ) ;
V_8 = F_5 ( V_7 ) ;
if ( F_6 ( V_7 ) )
return V_8 ;
V_2 -> V_15 = V_4 -> V_16 . V_17 < 0x100000000UL ;
V_2 -> V_7 = V_7 ;
V_2 -> V_6 = V_6 ;
V_8 = F_7 ( V_2 ) ;
if ( V_8 < 0 )
return V_8 ;
return F_8 ( V_2 ) ;
}
static int T_1 F_9 ( void )
{
F_10 ( & V_18 ) ;
return 0 ;
}
