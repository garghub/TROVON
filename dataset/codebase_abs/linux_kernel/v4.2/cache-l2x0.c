static int T_1 F_1 ( void )
{
int V_1 ;
struct V_2 * V_3 ;
void T_2 * V_4 ;
V_3 = F_2 ( NULL , NULL , L_1 ) ;
V_4 = F_3 ( V_3 , 0 ) ;
F_4 ( V_3 ) ;
if ( ! V_4 )
return - V_5 ;
for ( V_1 = 0 ; V_1 < 8 ; V_1 ++ ) {
F_5 ( 0x0 , V_4 + V_6 +
V_1 * V_7 ) ;
F_5 ( 0x0 , V_4 + V_8 +
V_1 * V_7 ) ;
}
F_6 ( V_4 ) ;
return 0 ;
}
static void F_7 ( unsigned long V_9 , unsigned V_10 )
{
}
static int T_1 F_8 ( void )
{
if ( ! ( ( F_9 () || F_10 () ) ) )
return - V_5 ;
F_1 () ;
V_11 . V_12 = F_7 ;
F_11 ( 0 , ~ 0 ) ;
return 0 ;
}
