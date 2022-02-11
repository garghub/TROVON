static void F_1 ( struct V_1 * V_2 , int V_3 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
if ( ! V_3 )
return;
F_2 ( V_2 , V_5 , V_7 , V_8 ) ;
}
static void F_3 ( struct V_9 * V_9 )
{
struct V_4 * V_5 = V_9 -> V_10 ;
if ( V_9 -> V_11 == V_8 &&
memcmp ( V_9 -> V_12 , V_7 ,
V_8 ) == 0 ) {
F_4 ( V_5 ) ;
F_5 ( V_5 , V_13 ) ;
return;
}
F_6 ( V_9 ) ;
}
static int T_1 F_7 ( void )
{
int V_14 ;
V_14 = F_8 ( & V_15 ) ;
if ( V_14 )
return V_14 ;
V_14 = F_9 ( & V_16 ) ;
if ( V_14 )
F_10 ( & V_15 ) ;
return V_14 ;
}
static void T_2 F_11 ( void )
{
F_12 ( & V_16 ) ;
F_10 ( & V_15 ) ;
}
