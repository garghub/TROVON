void T_1 F_1 ( int V_1 ,
unsigned V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 ;
struct V_7 V_8 ;
struct V_3 * V_9 ;
int V_10 ;
V_9 = F_2 ( V_4 , V_2 * sizeof( * V_9 ) , V_11 ) ;
if ( ! V_9 )
return;
V_6 = F_3 ( L_1 , V_1 ) ;
if ( ! V_6 )
goto V_12;
memset ( & V_8 , 0 , sizeof( V_8 ) ) ;
V_8 . V_2 = V_2 ;
V_8 . V_4 = V_9 ;
V_10 = F_4 ( V_6 , & V_8 , sizeof( V_8 ) ) ;
if ( V_10 )
goto V_13;
V_10 = F_5 ( V_6 ) ;
if ( V_10 )
goto V_13;
return;
V_13:
F_6 ( V_6 ) ;
V_12:
F_7 ( V_9 ) ;
}
