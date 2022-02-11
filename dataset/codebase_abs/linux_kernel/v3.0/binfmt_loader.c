static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_6 = (struct V_5 * ) V_2 -> V_7 ;
unsigned long V_8 ;
struct V_9 * V_9 ;
int V_10 ;
if ( V_6 -> V_11 . V_12 != 0x183 || ( V_6 -> V_11 . V_13 & 0x3000 ) != 0x3000 )
return - V_14 ;
if ( V_2 -> V_8 )
return - V_14 ;
F_2 ( V_2 -> V_9 ) ;
F_3 ( V_2 -> V_9 ) ;
V_2 -> V_9 = NULL ;
V_8 = V_2 -> V_15 -> V_16 - sizeof( void * ) ;
V_9 = F_4 ( L_1 ) ;
V_10 = F_5 ( V_9 ) ;
if ( F_6 ( V_9 ) )
return V_10 ;
V_2 -> V_17 = V_6 -> V_18 . V_19 < 0x100000000UL ;
V_2 -> V_9 = V_9 ;
V_2 -> V_8 = V_8 ;
V_10 = F_7 ( V_2 ) ;
if ( V_10 < 0 )
return V_10 ;
return F_8 ( V_2 , V_4 ) ;
}
static int T_1 F_9 ( void )
{
return F_10 ( & V_20 ) ;
}
