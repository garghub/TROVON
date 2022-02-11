int F_1 ( int V_1 , void (* F_2) ( void * V_2 ) , void * V_2 ,
int V_3 )
{
unsigned long V_4 ;
F_3 ( V_1 != 0 ) ;
F_4 ( V_4 ) ;
F_2 ( V_2 ) ;
F_5 ( V_4 ) ;
return 0 ;
}
int F_6 ( T_1 F_2 , void * V_2 , int V_3 )
{
unsigned long V_4 ;
F_4 ( V_4 ) ;
F_2 ( V_2 ) ;
F_5 ( V_4 ) ;
return 0 ;
}
void F_7 ( const struct V_5 * V_6 ,
T_1 F_2 , void * V_2 , bool V_3 )
{
unsigned long V_4 ;
if ( F_8 ( 0 , V_6 ) ) {
F_4 ( V_4 ) ;
F_2 ( V_2 ) ;
F_5 ( V_4 ) ;
}
}
void F_9 ( bool (* F_10)( int V_1 , void * V_2 ) ,
T_1 F_2 , void * V_2 , bool V_3 ,
T_2 V_7 )
{
unsigned long V_4 ;
F_11 () ;
if ( F_10 ( 0 , V_2 ) ) {
F_4 ( V_4 ) ;
F_2 ( V_2 ) ;
F_5 ( V_4 ) ;
}
F_12 () ;
}
