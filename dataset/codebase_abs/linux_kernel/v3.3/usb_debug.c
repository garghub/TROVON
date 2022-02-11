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
return;
}
F_5 ( V_9 ) ;
}
static int T_1 F_6 ( void )
{
int V_13 ;
V_13 = F_7 ( & V_14 ) ;
if ( V_13 )
return V_13 ;
V_13 = F_8 ( & V_15 ) ;
if ( V_13 )
F_9 ( & V_14 ) ;
return V_13 ;
}
static void T_2 F_10 ( void )
{
F_11 ( & V_15 ) ;
F_9 ( & V_14 ) ;
}
