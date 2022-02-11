void F_1 ( T_1 V_1 , void * V_2 )
{
unsigned long V_3 ;
F_2 ( V_3 ) ;
F_3 ( V_4 , ! V_5 ) ;
V_5 = 1 ;
V_6 = V_1 ;
V_7 = V_2 ;
F_4 ( V_3 ) ;
}
void F_5 ( void )
{
unsigned long V_3 ;
F_2 ( V_3 ) ;
V_5 = 0 ;
V_6 = NULL ;
V_7 = NULL ;
F_6 ( & V_4 ) ;
F_4 ( V_3 ) ;
}
int F_7 ( void )
{
return F_8 ( & V_4 ) ;
}
int F_9 ( void )
{
return V_5 ;
}
void T_2 F_10 ( void )
{
V_6 = NULL ;
if ( F_11 ( V_8 , V_9 , V_10 | V_11 ,
L_1 , V_9 ) )
F_12 ( L_2 ) ;
}
static T_3 V_9 ( int V_12 , void * V_13 )
{
if ( V_6 )
(* V_6)( V_12 , V_7 ) ;
return V_14 ;
}
