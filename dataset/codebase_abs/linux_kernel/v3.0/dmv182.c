static int T_1 F_1 ( void )
{
struct V_1 * V_2 ;
int V_3 = F_2 ( V_4 ) ;
V_2 = V_4 ;
V_5 . V_6 = F_3 ( V_7 , V_5 . V_8 ) ;
if ( V_5 . V_6 == 0 ) {
F_4 ( L_1 ) ;
return - V_9 ;
}
F_5 ( & V_5 ) ;
V_10 = F_6 ( L_2 , & V_5 ) ;
if ( ! V_10 )
{
F_7 ( ( void * ) V_5 . V_6 ) ;
return - V_11 ;
}
F_4 ( V_12 L_3 ,
V_10 -> V_8 >> 20 , V_7 ) ;
V_10 -> V_13 = V_14 ;
F_8 ( V_10 , V_2 , V_3 ) ;
return 0 ;
}
static void T_2 F_9 ( void )
{
if ( V_10 )
{
F_10 ( V_10 ) ;
F_11 ( V_10 ) ;
}
if ( V_5 . V_6 )
{
F_7 ( ( void * ) V_5 . V_6 ) ;
V_5 . V_6 = 0 ;
}
return;
}
