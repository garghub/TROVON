static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
int V_5 = 0 ;
if ( F_2 ( 14 , V_6 , L_1 ) ) {
F_3 ( V_7 L_2 ) ;
V_5 = - 1 ;
goto exit;
}
if ( F_2 ( 15 , V_6 , L_3 ) ) {
F_3 ( V_7 L_4 ) ;
F_4 ( 14 ) ;
V_5 = - 1 ;
goto exit;
}
exit:
return V_5 ;
}
static void F_5 ( struct V_1 * V_2 )
{
F_4 ( 15 ) ;
F_4 ( 14 ) ;
}
static int F_6 ( struct V_1 * V_2 )
{
F_7 ( 14 , 1 ) ;
F_7 ( 15 , 1 ) ;
return 0 ;
}
static void F_8 ( struct V_1 * V_2 )
{
F_7 ( 14 , 0 ) ;
F_7 ( 15 , 0 ) ;
}
static int F_9 ( struct V_8 * V_9 )
{
F_10 ( & V_10 ) ;
return 0 ;
}
