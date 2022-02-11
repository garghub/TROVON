static void T_1 F_1 ( void )
{
struct V_1 * V_2 ;
struct V_3 V_4 , * V_5 = & V_4 ;
const char * V_6 = L_1 ;
const char * V_7 = L_2 ;
int V_8 = - V_9 ;
int V_10 = 0 ;
struct {
struct V_11 V_12 ;
char V_13 [ V_14 ] ;
} V_15 ;
memset ( V_5 , 0 , sizeof( * V_5 ) ) ;
memset ( & V_15 , 0 , sizeof( V_15 ) ) ;
V_5 -> V_16 = & V_15 . V_12 ;
V_5 -> V_16 -> V_17 = V_18 ;
V_5 -> V_16 -> V_19 = V_20 ;
if ( V_21 ) {
V_8 = F_2 ( & V_15 . V_12 ) ;
if ( V_8 < 0 ) {
V_7 = L_3 ;
goto V_22;
}
}
V_8 = F_3 ( V_5 , NULL , V_23 ,
NULL , 0 , & V_2 ) ;
if ( V_8 < 0 )
return;
V_8 = F_4 ( V_2 , V_10 , NULL ,
V_23 ) ;
if ( V_8 < 0 )
F_5 ( V_2 ) ;
return;
V_22:
F_6 ( V_24 , NULL , V_23 , V_6 ,
V_7 , V_8 , 0 ) ;
}
int T_1 F_7 ( void )
{
T_2 V_25 [ V_14 ] ;
int V_26 ;
V_21 = 0 ;
V_26 = F_8 ( V_27 , 0 , V_25 ) ;
if ( V_26 == 0 )
V_21 = 1 ;
if ( ! V_21 )
F_9 ( L_4 ) ;
V_26 = F_10 () ;
if ( V_26 )
return V_26 ;
V_26 = F_11 () ;
if ( V_26 != 0 )
return V_26 ;
F_1 () ;
F_12 () ;
return F_13 () ;
}
