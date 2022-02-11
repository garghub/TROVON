static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 , int V_5 )
{
int V_6 ;
if ( ! V_5 ) {
F_2 () ;
return V_5 ;
}
V_6 = F_3 () ;
if ( ! V_6 ) {
F_4 ( V_5 ) ;
F_5 () ;
}
return V_6 ? - 1 : V_5 ;
}
static int T_1 F_6 ( void )
{
int V_7 , V_6 ;
struct V_3 * V_4 = & V_8 ;
struct V_1 * V_2 ;
V_6 = F_7 ( V_4 , V_9 , 1 ) ;
if ( V_6 <= 0 )
return V_6 ? : - V_10 ;
V_6 = F_8 ( V_4 ) ;
if ( V_6 ) {
F_9 ( L_1 ) ;
return V_6 ;
}
F_10 (cpu) {
V_6 = F_11 ( V_7 ) ;
if ( V_6 == - V_11 )
continue;
if ( V_6 ) {
F_9 ( L_2 , V_7 ) ;
goto V_12;
}
V_2 = F_12 ( sizeof( * V_2 ) , V_13 ) ;
if ( ! V_2 ) {
F_9 ( L_3 ) ;
goto V_12;
}
V_2 -> V_7 = V_7 ;
V_6 = F_13 ( V_2 ) ;
if ( V_6 ) {
F_9 ( L_4 ,
V_7 ) ;
F_14 ( V_2 ) ;
goto V_12;
}
}
return 0 ;
V_12:
while ( -- V_7 >= 0 ) {
V_2 = F_15 ( V_14 , V_7 ) ;
F_16 ( V_2 ) ;
F_14 ( V_2 ) ;
}
F_17 ( V_4 ) ;
return V_6 ;
}
