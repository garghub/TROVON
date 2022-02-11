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
int F_6 ( int V_1 , T_1 * V_5 )
{
unsigned long V_4 ;
F_4 ( V_4 ) ;
V_5 -> F_2 ( V_5 -> V_2 ) ;
F_5 ( V_4 ) ;
return 0 ;
}
int F_7 ( T_2 F_2 , void * V_2 , int V_3 )
{
unsigned long V_4 ;
F_4 ( V_4 ) ;
F_2 ( V_2 ) ;
F_5 ( V_4 ) ;
return 0 ;
}
void F_8 ( const struct V_6 * V_7 ,
T_2 F_2 , void * V_2 , bool V_3 )
{
unsigned long V_4 ;
if ( F_9 ( 0 , V_7 ) ) {
F_4 ( V_4 ) ;
F_2 ( V_2 ) ;
F_5 ( V_4 ) ;
}
}
void F_10 ( bool (* F_11)( int V_1 , void * V_2 ) ,
T_2 F_2 , void * V_2 , bool V_3 ,
T_3 V_8 )
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
int F_14 ( unsigned int V_1 , int (* F_2)( void * ) , void * V_9 , bool V_10 )
{
int V_11 ;
if ( V_1 != 0 )
return - V_12 ;
if ( V_10 )
F_15 ( 0 ) ;
V_11 = F_2 ( V_9 ) ;
if ( V_10 )
F_15 ( - 1 ) ;
return V_11 ;
}
