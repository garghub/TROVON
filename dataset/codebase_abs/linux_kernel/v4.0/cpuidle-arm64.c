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
V_6 = F_4 ( V_5 ) ;
F_5 () ;
}
return V_6 ? - 1 : V_5 ;
}
static int T_1 F_6 ( void )
{
int V_7 , V_6 ;
struct V_3 * V_4 = & V_8 ;
V_6 = F_7 ( V_4 , V_9 , 1 ) ;
if ( V_6 <= 0 )
return V_6 ? : - V_10 ;
F_8 (cpu) {
V_6 = F_9 ( V_7 ) ;
if ( V_6 ) {
F_10 ( L_1 , V_7 ) ;
return V_6 ;
}
}
return F_11 ( V_4 , NULL ) ;
}
