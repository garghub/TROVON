static T_1
F_1 ( T_1 string )
{
return ( T_1 ) F_2 ( ( char * ) string ) ;
}
static void
F_3 ( T_1 V_1 )
{
F_4 ( V_1 ) ;
}
void
F_5 ( void )
{
static T_2 V_2 = {
V_3 ,
L_1 ,
F_1 ,
F_3 ,
} ;
static T_2 V_4 = {
V_5 ,
L_2 ,
F_1 ,
F_3 ,
} ;
F_6 ( & V_2 ) ;
F_6 ( & V_4 ) ;
}
