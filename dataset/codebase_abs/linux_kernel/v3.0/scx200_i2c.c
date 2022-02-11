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
F_8 ( V_5 L_1 ) ;
if ( ! F_9 () ) {
F_10 (KERN_ERR NAME L_2 ) ;
return - V_6 ;
}
F_8 ( V_5 L_3 , V_3 , V_4 ) ;
if ( V_3 == - 1 || V_4 == - 1 || V_3 == V_4 ) {
F_10 (KERN_ERR NAME L_4 ) ;
return - V_7 ;
}
F_11 ( V_3 , ~ 2 , 5 ) ;
F_11 ( V_4 , ~ 2 , 5 ) ;
if ( F_12 ( & V_8 ) < 0 ) {
F_10 (KERN_ERR NAME L_5 ,
scx200_i2c_ops.name) ;
return - V_6 ;
}
return 0 ;
}
static void F_13 ( void )
{
F_14 ( & V_8 ) ;
}
