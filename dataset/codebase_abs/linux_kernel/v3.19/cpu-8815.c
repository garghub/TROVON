static void T_1 F_1 ( void )
{
F_2 ( V_1 , F_3 ( V_1 ) ) ;
}
static void F_4 ( enum V_2 V_3 , const char * V_4 )
{
void T_2 * V_5 = F_5 ( V_6 , V_7 ) ;
F_6 ( 1 , V_5 + 0x18 ) ;
}
static int T_1 F_7 ( void )
{
struct V_8 * V_9 ;
int V_10 , V_11 ;
V_9 = F_8 ( L_1 ) ;
if ( ! V_9 ) {
F_9 ( L_2 ) ;
return 0 ;
}
V_10 = F_10 ( V_9 , 0 ) ;
if ( V_10 < 0 ) {
F_9 ( L_3 ) ;
return 0 ;
}
V_11 = F_11 ( V_10 , L_4 ) ;
if ( V_11 ) {
F_9 ( L_5 , V_10 ) ;
return - V_12 ;
}
V_11 = F_12 ( V_10 , 0 ) ;
if ( V_11 ) {
F_9 ( L_6 , V_10 ) ;
return V_11 ;
}
F_9 ( L_7 , V_10 ) ;
return 0 ;
}
