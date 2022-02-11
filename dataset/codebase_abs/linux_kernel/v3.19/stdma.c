int F_1 ( T_1 V_1 , void * V_2 )
{
unsigned long V_3 ;
F_2 ( V_3 ) ;
if ( V_4 ) {
F_3 ( V_3 ) ;
return 0 ;
}
V_4 = 1 ;
V_5 = V_1 ;
V_6 = V_2 ;
F_3 ( V_3 ) ;
return 1 ;
}
void F_4 ( T_1 V_1 , void * V_2 )
{
F_5 ( V_7 , F_1 ( V_1 , V_2 ) ) ;
}
void F_6 ( void )
{
unsigned long V_3 ;
F_2 ( V_3 ) ;
V_4 = 0 ;
V_5 = NULL ;
V_6 = NULL ;
F_7 ( & V_7 ) ;
F_3 ( V_3 ) ;
}
int F_8 ( T_1 V_1 )
{
unsigned long V_3 ;
int V_8 ;
F_2 ( V_3 ) ;
V_8 = V_4 && ( V_5 == V_1 ) ;
F_3 ( V_3 ) ;
return V_8 ;
}
int F_9 ( void )
{
return V_4 ;
}
void T_2 F_10 ( void )
{
V_5 = NULL ;
if ( F_11 ( V_9 , V_10 , V_11 | V_12 ,
L_1 , V_10 ) )
F_12 ( L_2 ) ;
}
static T_3 V_10 ( int V_13 , void * V_14 )
{
if ( V_5 )
(* V_5)( V_13 , V_6 ) ;
return V_15 ;
}
