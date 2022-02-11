static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 , int V_5 )
{
return F_2 ( V_6 , V_5 ) ;
}
static int T_1 F_3 ( void )
{
int V_7 , V_8 ;
struct V_3 * V_4 = & V_9 ;
struct V_1 * V_2 ;
V_8 = F_4 ( V_4 , V_10 , 1 ) ;
if ( V_8 <= 0 )
return V_8 ? : - V_11 ;
V_8 = F_5 ( V_4 ) ;
if ( V_8 ) {
F_6 ( L_1 ) ;
return V_8 ;
}
F_7 (cpu) {
V_8 = F_8 ( V_7 ) ;
if ( V_8 == - V_12 )
continue;
if ( V_8 ) {
F_6 ( L_2 , V_7 ) ;
goto V_13;
}
V_2 = F_9 ( sizeof( * V_2 ) , V_14 ) ;
if ( ! V_2 ) {
F_6 ( L_3 ) ;
goto V_13;
}
V_2 -> V_7 = V_7 ;
V_8 = F_10 ( V_2 ) ;
if ( V_8 ) {
F_6 ( L_4 ,
V_7 ) ;
F_11 ( V_2 ) ;
goto V_13;
}
}
return 0 ;
V_13:
while ( -- V_7 >= 0 ) {
V_2 = F_12 ( V_15 , V_7 ) ;
F_13 ( V_2 ) ;
F_11 ( V_2 ) ;
}
F_14 ( V_4 ) ;
return V_8 ;
}
