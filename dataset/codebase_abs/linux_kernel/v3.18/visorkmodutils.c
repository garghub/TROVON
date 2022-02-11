void * F_1 ( T_1 V_1 )
{
return F_2 ( V_1 , V_2 | V_3 ) ;
}
static T_2 T_3
F_3 ( void )
{
unsigned int V_4 , V_5 , V_6 , V_7 ;
if ( V_8 ) {
F_4 ( V_9 , & V_4 , & V_5 , & V_6 , & V_7 ) ;
return ( V_5 == V_10 ) &&
( V_6 == V_11 ) &&
( V_7 == V_12 ) ;
} else
return 0 ;
}
static T_2 int
F_5 ( void )
{
if ( F_3 () ) {
V_13 = TRUE ;
return 0 ;
} else
return - V_14 ;
}
static T_4 void
F_6 ( void )
{
}
