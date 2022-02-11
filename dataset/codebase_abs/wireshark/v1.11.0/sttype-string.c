static T_1
F_1 ( T_1 string )
{
return ( T_1 ) F_2 ( ( char * ) string ) ;
}
static T_1
F_3 ( T_2 string )
{
return ( T_1 ) F_2 ( ( const char * ) string ) ;
}
static void
F_4 ( T_1 V_1 )
{
F_5 ( V_1 ) ;
}
void
F_6 ( void )
{
static T_3 V_2 = {
V_3 ,
L_1 ,
F_1 ,
F_4 ,
F_3
} ;
static T_3 V_4 = {
V_5 ,
L_2 ,
F_1 ,
F_4 ,
F_3
} ;
F_7 ( & V_2 ) ;
F_7 ( & V_4 ) ;
}
