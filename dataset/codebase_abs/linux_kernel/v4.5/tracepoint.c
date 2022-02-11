static void F_1 ( int V_1 )
{
F_2 ( & V_2 , V_1 ) ;
F_3 () ;
}
static void F_4 ( void * V_3 )
{
unsigned long V_4 ;
F_5 ( V_4 ) ;
F_6 () ;
F_7 ( V_4 ) ;
}
void F_8 ( void )
{
F_9 ( & V_5 ) ;
if ( ! V_6 ) {
F_1 ( 1 ) ;
F_10 ( F_4 , NULL , 0 ) ;
F_4 ( NULL ) ;
}
V_6 ++ ;
F_11 ( & V_5 ) ;
}
void F_12 ( void )
{
F_9 ( & V_5 ) ;
V_6 -- ;
if ( ! V_6 ) {
F_1 ( 0 ) ;
F_10 ( F_4 , NULL , 0 ) ;
F_4 ( NULL ) ;
}
F_11 ( & V_5 ) ;
}
