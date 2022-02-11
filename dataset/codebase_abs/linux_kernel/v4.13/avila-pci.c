void T_1 F_1 ( void )
{
F_2 ( F_3 ( V_1 ) , V_2 ) ;
F_2 ( F_3 ( V_3 ) , V_2 ) ;
F_2 ( F_3 ( V_4 ) , V_2 ) ;
F_2 ( F_3 ( V_5 ) , V_2 ) ;
F_4 () ;
}
static int T_1 F_5 ( const struct V_6 * V_7 , T_2 V_8 , T_2 V_9 )
{
static int V_10 [ V_11 ] = {
F_3 ( V_1 ) ,
F_3 ( V_3 ) ,
F_3 ( V_4 ) ,
F_3 (INTD)
} ;
if ( V_8 >= 1 &&
V_8 <= ( F_6 () ? V_12 : V_13 ) &&
V_9 >= 1 && V_9 <= V_11 )
return V_10 [ ( V_8 + V_9 - 2 ) % 4 ] ;
return - 1 ;
}
int T_1 F_7 ( void )
{
if ( F_8 () || F_6 () )
F_9 ( & V_14 ) ;
return 0 ;
}
