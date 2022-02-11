static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 )
{
struct V_7 * V_8 = (struct V_7 * ) V_4 -> V_9 ;
const unsigned char * V_10 = F_2 ( V_2 ) ;
if ( V_6 ) {
if ( V_6 -> V_10 )
V_10 = V_6 -> V_10 ;
V_10 += ( V_6 -> V_11 & V_8 -> V_12 ) ;
}
V_10 += V_8 -> V_13 ;
if ( ! F_3 ( V_2 , V_10 , sizeof( V_14 ) ) )
return 0 ;
return ! ( ( ( * ( V_15 * ) V_10 ) ^ V_8 -> V_16 ) & V_8 -> V_17 ) ;
}
static int T_1 F_4 ( void )
{
return F_5 ( & V_18 ) ;
}
static void T_2 F_6 ( void )
{
F_7 ( & V_18 ) ;
}
