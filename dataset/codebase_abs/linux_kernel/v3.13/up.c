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
void F_6 ( int V_1 , struct V_5 * V_6 ,
int V_3 )
{
unsigned long V_4 ;
F_4 ( V_4 ) ;
V_6 -> F_2 ( V_6 -> V_2 ) ;
F_5 ( V_4 ) ;
}
int F_7 ( T_1 F_2 , void * V_2 , int V_3 )
{
unsigned long V_4 ;
F_4 ( V_4 ) ;
F_2 ( V_2 ) ;
F_5 ( V_4 ) ;
return 0 ;
}
void F_8 ( const struct V_7 * V_8 ,
T_1 F_2 , void * V_2 , bool V_3 )
{
unsigned long V_4 ;
if ( F_9 ( 0 , V_8 ) ) {
F_4 ( V_4 ) ;
F_2 ( V_2 ) ;
F_5 ( V_4 ) ;
}
}
void F_10 ( bool (* F_11)( int V_1 , void * V_2 ) ,
T_1 F_2 , void * V_2 , bool V_3 ,
T_2 V_9 )
{
unsigned long V_4 ;
F_12 () ;
if ( F_11 ( 0 , V_2 ) ) {
F_4 ( V_4 ) ;
F_2 ( V_2 ) ;
F_5 ( V_4 ) ;
}
F_13 () ;
}
