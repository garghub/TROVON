int T_1 F_1 ( void )
{
int V_1 ;
unsigned int V_2 ;
struct V_3 * V_4 ;
struct V_5 * V_6 = & V_7 ;
V_1 = F_2 ( & V_7 ) ;
if ( V_1 ) {
F_3 ( L_1 ) ;
return V_1 ;
}
F_4 (cpu) {
V_4 = & F_5 ( V_8 , V_2 ) ;
V_4 -> V_2 = V_2 ;
V_4 -> V_9 = V_6 -> V_9 ;
V_1 = F_6 ( V_4 ) ;
if ( V_1 ) {
F_3 ( L_2 ,
V_2 ) ;
return V_1 ;
}
}
return 0 ;
}
