void F_1 ( void )
{
F_2 ( & V_1 ) ;
}
void F_3 ( void )
{
F_4 ( & V_1 ) ;
}
void F_1 ( void )
{
V_2 ++ ;
}
void F_3 ( void )
{
V_2 -- ;
}
void F_5 ( unsigned long V_3 , unsigned long * args )
{
unsigned long V_4 ;
unsigned int * V_5 ;
F_6 ( V_4 ) ;
V_5 = & F_7 ( V_6 ) ;
if ( * V_5 )
goto V_7;
( * V_5 ) ++ ;
F_8 () ;
F_9 ( V_3 , args ) ;
( * V_5 ) -- ;
V_7:
F_10 ( V_4 ) ;
}
void F_11 ( long V_3 , unsigned long V_8 )
{
unsigned long V_4 ;
unsigned int * V_5 ;
F_6 ( V_4 ) ;
V_5 = & F_7 ( V_6 ) ;
if ( * V_5 )
goto V_7;
( * V_5 ) ++ ;
F_12 ( V_3 , V_8 ) ;
F_13 () ;
( * V_5 ) -- ;
V_7:
F_10 ( V_4 ) ;
}
