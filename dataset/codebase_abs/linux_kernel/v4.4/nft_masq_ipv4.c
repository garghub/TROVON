static void F_1 ( const struct V_1 * V_2 ,
struct V_3 * V_4 ,
const struct V_5 * V_6 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
struct V_9 V_10 ;
memset ( & V_10 , 0 , sizeof( V_10 ) ) ;
V_10 . V_11 = V_8 -> V_11 ;
V_4 -> V_12 . V_13 = F_3 ( V_6 -> V_14 , V_6 -> V_15 ,
& V_10 , V_6 -> V_16 ) ;
}
static int T_1 F_4 ( void )
{
int V_17 ;
V_17 = F_5 ( & V_18 ) ;
if ( V_17 < 0 )
return V_17 ;
F_6 () ;
return V_17 ;
}
static void T_2 F_7 ( void )
{
F_8 ( & V_18 ) ;
F_9 () ;
}
