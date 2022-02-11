static void F_1 ( const struct V_1 * V_2 ,
struct V_3 V_4 [ V_5 + 1 ] ,
const struct V_6 * V_7 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
struct V_10 V_11 ;
unsigned int V_12 ;
memset ( & V_11 , 0 , sizeof( V_11 ) ) ;
V_11 . V_13 = V_9 -> V_13 ;
V_12 = F_3 ( V_7 -> V_14 , V_7 -> V_15 -> V_16 ,
& V_11 , V_7 -> V_17 ) ;
V_4 [ V_18 ] . V_12 = V_12 ;
}
static int T_1 F_4 ( void )
{
int V_19 ;
V_19 = F_5 ( & V_20 ) ;
if ( V_19 < 0 )
return V_19 ;
F_6 () ;
return V_19 ;
}
static void T_2 F_7 ( void )
{
F_8 ( & V_20 ) ;
F_9 () ;
}
