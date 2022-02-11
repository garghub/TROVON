static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 , int V_5 )
{
T_1 V_6 , exit ;
T_2 V_7 ;
F_2 () ;
F_3 () ;
V_6 = F_4 () ;
F_5 () ;
exit = F_6 ( F_4 () , V_6 ) ;
V_7 = F_7 ( exit ) ;
F_8 () ;
F_9 () ;
V_2 -> V_8 = V_7 ;
return V_5 ;
}
static int T_3 F_10 ( void )
{
int V_9 ;
unsigned int V_10 ;
struct V_1 * V_2 ;
struct V_3 * V_4 = & V_11 ;
V_9 = F_11 ( & V_11 ) ;
if ( V_9 ) {
F_12 ( L_1 ) ;
return V_9 ;
}
F_13 (cpu) {
V_2 = & F_14 ( V_12 , V_10 ) ;
V_2 -> V_10 = V_10 ;
V_2 -> V_13 = V_4 -> V_13 ;
V_9 = F_15 ( V_2 ) ;
if ( V_9 ) {
F_12 ( L_2 ,
V_10 ) ;
return V_9 ;
}
}
return 0 ;
}
