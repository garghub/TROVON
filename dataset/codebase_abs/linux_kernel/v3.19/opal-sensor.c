int F_1 ( T_1 V_1 , T_1 * V_2 )
{
int V_3 , V_4 ;
struct V_5 V_6 ;
T_2 V_7 ;
V_4 = F_2 () ;
if ( V_4 < 0 ) {
F_3 ( L_1 , V_8 ) ;
V_3 = V_4 ;
goto V_9;
}
F_4 ( & V_10 ) ;
V_3 = F_5 ( V_1 , V_4 , & V_7 ) ;
if ( V_3 != V_11 )
goto V_12;
V_3 = F_6 ( V_4 , & V_6 ) ;
if ( V_3 ) {
F_3 ( L_2 ,
V_8 , V_3 ) ;
goto V_12;
}
* V_2 = F_7 ( V_7 ) ;
V_3 = F_8 ( V_6 . V_13 [ 1 ] ) ;
V_12:
F_9 ( & V_10 ) ;
F_10 ( V_4 ) ;
V_9:
return V_3 ;
}
static T_3 int F_11 ( void )
{
struct V_14 * V_15 ;
struct V_16 * V_17 ;
V_17 = F_12 ( L_3 ) ;
if ( ! V_17 ) {
F_3 ( L_4 ) ;
return - V_18 ;
}
V_15 = F_13 ( V_17 , L_5 , NULL ) ;
F_14 ( V_17 ) ;
return F_15 ( V_15 ) ;
}
