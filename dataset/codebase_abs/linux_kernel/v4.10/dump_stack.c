static void F_1 ( void )
{
F_2 ( V_1 ) ;
F_3 ( NULL , NULL ) ;
}
T_1 T_2 void F_4 ( void )
{
unsigned long V_2 ;
int V_3 ;
int V_4 ;
int V_5 ;
V_6:
F_5 ( V_2 ) ;
V_5 = F_6 () ;
V_4 = F_7 ( & V_7 , - 1 , V_5 ) ;
if ( V_4 == - 1 ) {
V_3 = 0 ;
} else if ( V_4 == V_5 ) {
V_3 = 1 ;
} else {
F_8 ( V_2 ) ;
F_9 () ;
goto V_6;
}
F_1 () ;
if ( ! V_3 )
F_10 ( & V_7 , - 1 ) ;
F_8 ( V_2 ) ;
}
T_1 T_2 void F_4 ( void )
{
F_1 () ;
}
