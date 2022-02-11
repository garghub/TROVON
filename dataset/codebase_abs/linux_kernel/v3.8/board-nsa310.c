static void F_1 ( void )
{
F_2 ( V_1 , 1 ) ;
}
static int T_1 F_3 ( unsigned int V_2 , unsigned long V_3 ,
const char * V_4 )
{
int V_5 ;
V_5 = F_4 ( V_2 , V_3 , V_4 ) ;
if ( V_5 )
F_5 ( L_1 ,
V_2 , V_4 , V_5 ) ;
return V_5 ;
}
static void T_1 F_6 ( void )
{
int V_5 ;
V_5 = F_3 ( V_1 , V_6 ,
L_2 ) ;
if ( ! V_5 )
V_7 = F_1 ;
F_3 ( V_8 , V_6 ,
L_3 ) ;
}
void T_1 F_7 ( void )
{
T_2 V_9 , V_10 ;
F_8 ( V_11 ) ;
F_6 () ;
F_9 ( & V_9 , & V_10 ) ;
F_10 ( 0 , F_11 ( V_12 ) ) ;
}
static int T_1 F_12 ( void )
{
if ( F_13 ( L_4 ) )
F_14 ( V_13 ) ;
return 0 ;
}
