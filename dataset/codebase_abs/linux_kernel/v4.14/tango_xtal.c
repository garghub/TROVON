static unsigned long T_1 F_1 ( void )
{
return F_2 ( V_1 ) ;
}
static T_2 T_1 F_3 ( void )
{
return F_1 () ;
}
static int T_3 F_4 ( struct V_2 * V_3 )
{
struct V_4 * V_4 ;
int V_5 , V_6 ;
V_1 = F_5 ( V_3 , 0 ) ;
if ( V_1 == NULL ) {
F_6 ( L_1 , V_3 ) ;
return - V_7 ;
}
V_4 = F_7 ( V_3 , 0 ) ;
if ( F_8 ( V_4 ) ) {
F_6 ( L_2 , V_3 ) ;
return F_9 ( V_4 ) ;
}
V_5 = F_10 ( V_4 ) ;
V_8 . V_9 = V_5 ;
V_8 . V_10 = F_1 ;
V_6 = F_11 ( V_1 , L_3 , V_5 , 350 ,
32 , V_11 ) ;
if ( V_6 ) {
F_6 ( L_4 , V_3 ) ;
return V_6 ;
}
F_12 ( F_3 , 32 , V_5 ) ;
F_13 ( & V_8 ) ;
return 0 ;
}
