int F_1 ( unsigned int V_1 , void * V_2 )
{
int V_3 , V_4 ;
if ( ! V_5 || ! V_6 ) {
F_2 ( L_1 ) ;
return 1 ;
}
V_4 = F_3 ( V_1 ) ;
F_4 ( F_5 ( V_2 ) , V_5 +
F_6 ( V_4 ) ) ;
V_3 = F_7 ( V_6 + F_8 ( V_4 ) ) ;
V_3 &= ( ~ 0x1 ) ;
F_4 ( V_3 , V_6 + F_8 ( V_4 ) ) ;
return 0 ;
}
static int T_1 F_9 ( void )
{
struct V_7 * V_8 ;
V_8 = F_10 ( NULL , V_9 ) ;
if ( V_8 ) {
F_11 ( L_2 ) ;
V_5 = F_12 ( V_8 , 0 ) ;
V_6 = F_12 ( V_8 , 1 ) ;
F_13 ( V_8 ) ;
}
return 0 ;
}
