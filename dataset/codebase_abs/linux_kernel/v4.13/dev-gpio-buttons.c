void T_1 F_1 ( int V_1 ,
unsigned V_2 ,
unsigned V_3 ,
struct V_4 * V_5 )
{
struct V_6 * V_7 ;
struct V_8 V_9 ;
struct V_4 * V_10 ;
int V_11 ;
V_10 = F_2 ( V_5 , V_3 * sizeof( * V_10 ) , V_12 ) ;
if ( ! V_10 )
return;
V_7 = F_3 ( L_1 , V_1 ) ;
if ( ! V_7 )
goto V_13;
memset ( & V_9 , 0 , sizeof( V_9 ) ) ;
V_9 . V_2 = V_2 ;
V_9 . V_3 = V_3 ;
V_9 . V_5 = V_10 ;
V_11 = F_4 ( V_7 , & V_9 , sizeof( V_9 ) ) ;
if ( V_11 )
goto V_14;
V_11 = F_5 ( V_7 ) ;
if ( V_11 )
goto V_14;
return;
V_14:
F_6 ( V_7 ) ;
V_13:
F_7 ( V_10 ) ;
}
