static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 , int V_5 )
{
return F_2 ( V_6 , V_5 ) ;
}
static int T_1 F_3 ( void )
{
int V_7 , V_8 ;
struct V_3 * V_4 ;
struct V_1 * V_2 ;
F_4 (cpu) {
V_4 = F_5 ( & V_9 , sizeof( * V_4 ) , V_10 ) ;
if ( ! V_4 ) {
V_8 = - V_11 ;
goto V_12;
}
V_4 -> V_13 = (struct V_13 * ) F_6 ( V_7 ) ;
V_8 = F_7 ( V_4 , V_14 , 1 ) ;
if ( V_8 <= 0 ) {
V_8 = V_8 ? : - V_15 ;
goto V_12;
}
V_8 = F_8 ( V_4 ) ;
if ( V_8 ) {
F_9 ( L_1 ) ;
goto V_12;
}
V_8 = F_10 ( V_7 ) ;
if ( V_8 == - V_16 )
continue;
if ( V_8 ) {
F_9 ( L_2 , V_7 ) ;
goto V_12;
}
V_2 = F_11 ( sizeof( * V_2 ) , V_10 ) ;
if ( ! V_2 ) {
F_9 ( L_3 ) ;
V_8 = - V_11 ;
goto V_12;
}
V_2 -> V_7 = V_7 ;
V_8 = F_12 ( V_2 ) ;
if ( V_8 ) {
F_9 ( L_4 ,
V_7 ) ;
F_13 ( V_2 ) ;
goto V_12;
}
}
return 0 ;
V_12:
while ( -- V_7 >= 0 ) {
V_2 = F_14 ( V_17 , V_7 ) ;
F_15 ( V_2 ) ;
F_13 ( V_2 ) ;
V_4 = F_16 () ;
F_17 ( V_4 ) ;
F_13 ( V_4 ) ;
}
return V_8 ;
}
