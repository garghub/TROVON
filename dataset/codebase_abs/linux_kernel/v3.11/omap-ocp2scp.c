static int F_1 ( struct V_1 * V_2 , void * V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
F_3 ( V_5 ) ;
return 0 ;
}
static int F_4 ( struct V_4 * V_5 )
{
int V_6 ;
struct V_7 * V_8 = V_5 -> V_2 . V_9 ;
if ( V_8 ) {
V_6 = F_5 ( V_8 , NULL , NULL , & V_5 -> V_2 ) ;
if ( V_6 ) {
F_6 ( & V_5 -> V_2 ,
L_1 ) ;
goto V_10;
}
}
F_7 ( & V_5 -> V_2 ) ;
return 0 ;
V_10:
F_8 ( & V_5 -> V_2 , NULL , F_1 ) ;
return V_6 ;
}
static int F_9 ( struct V_4 * V_5 )
{
F_10 ( & V_5 -> V_2 ) ;
F_8 ( & V_5 -> V_2 , NULL , F_1 ) ;
return 0 ;
}
