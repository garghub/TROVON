static void F_1 ( void * V_1 , int V_2 )
{
F_2 ( V_3 , V_2 ) ;
}
static void F_3 ( void * V_1 , int V_2 )
{
F_2 ( V_4 , V_2 ) ;
}
static int F_4 ( void * V_1 )
{
return F_5 ( V_3 ) ;
}
static int F_6 ( void * V_1 )
{
return F_5 ( V_4 ) ;
}
static int F_7 ( void )
{
F_8 ( L_1 ) ;
if ( ! F_9 () ) {
F_10 ( L_2 ) ;
return - V_5 ;
}
F_8 ( L_3 , V_3 , V_4 ) ;
if ( V_3 == - 1 || V_4 == - 1 || V_3 == V_4 ) {
F_10 ( L_4 ) ;
return - V_6 ;
}
F_11 ( V_3 , ~ 2 , 5 ) ;
F_11 ( V_4 , ~ 2 , 5 ) ;
if ( F_12 ( & V_7 ) < 0 ) {
F_10 ( L_5 , V_7 . V_8 ) ;
return - V_5 ;
}
return 0 ;
}
static void F_13 ( void )
{
F_14 ( & V_7 ) ;
}
