static void F_1 ( void )
{
F_2 ( V_1 ) ;
F_3 ( NULL , NULL ) ;
}
T_1 void F_4 ( void )
{
int V_2 ;
int V_3 ;
int V_4 ;
F_5 () ;
V_5:
V_4 = F_6 () ;
V_3 = F_7 ( & V_6 , - 1 , V_4 ) ;
if ( V_3 == - 1 ) {
V_2 = 0 ;
} else if ( V_3 == V_4 ) {
V_2 = 1 ;
} else {
F_8 () ;
goto V_5;
}
F_1 () ;
if ( ! V_2 )
F_9 ( & V_6 , - 1 ) ;
F_10 () ;
}
T_1 void F_4 ( void )
{
F_1 () ;
}
