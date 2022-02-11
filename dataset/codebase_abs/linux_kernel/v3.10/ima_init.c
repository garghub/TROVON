static void T_1 F_1 ( void )
{
struct V_1 * V_2 ;
const char * V_3 = L_1 ;
const char * V_4 = L_2 ;
int V_5 = - V_6 ;
int V_7 = 1 ;
V_2 = F_2 ( sizeof( * V_2 ) , V_8 ) ;
if ( ! V_2 )
goto V_9;
memset ( & V_2 -> V_10 , 0 , sizeof( V_2 -> V_10 ) ) ;
strncpy ( V_2 -> V_10 . V_11 , V_12 ,
V_13 ) ;
if ( V_14 ) {
V_7 = 0 ;
V_5 = F_3 ( V_2 -> V_10 . V_15 ) ;
if ( V_5 < 0 ) {
V_4 = L_3 ;
F_4 ( V_2 ) ;
goto V_9;
}
}
V_5 = F_5 ( V_2 , V_7 , NULL ) ;
if ( V_5 < 0 )
F_4 ( V_2 ) ;
return;
V_9:
F_6 ( V_16 , NULL , V_12 , V_3 ,
V_4 , V_5 , 0 ) ;
}
int T_1 F_7 ( void )
{
T_2 V_17 [ V_18 ] ;
int V_19 ;
V_14 = 0 ;
V_19 = F_8 ( V_20 , 0 , V_17 ) ;
if ( V_19 == 0 )
V_14 = 1 ;
if ( ! V_14 )
F_9 ( L_4 ) ;
V_19 = F_10 () ;
if ( V_19 )
return V_19 ;
F_1 () ;
F_11 () ;
return F_12 () ;
}
