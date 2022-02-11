static int F_1 ( struct V_1 * V_2 )
{
return 0 ;
}
static int F_2 ( struct V_1 * V_2 )
{
return 0 ;
}
static int T_1 F_3 ( struct V_1 * V_2 )
{
F_4 ( V_2 ) ;
return 0 ;
}
int F_5 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = NULL ;
int V_5 ;
V_2 = F_6 ( L_1 , ++ V_6 ) ;
if ( ! V_2 )
return - V_7 ;
V_8 . V_9 = * V_4 ;
V_5 = F_7 ( V_2 , & V_8 ,
sizeof( V_8 ) ) ;
if ( V_5 ) {
F_8 ( V_10
L_2 , V_11 ) ;
goto V_12;
}
V_5 = F_9 ( V_2 ) ;
if ( V_5 ) {
F_8 ( V_10
L_3 , V_11 ) ;
goto V_12;
}
return 0 ;
V_12:
F_10 ( V_2 ) ;
return V_5 ;
}
static int T_1 F_11 ( void )
{
return F_12 ( & V_13 ) ;
}
