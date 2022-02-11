static T_1 F_1 ( const char * V_1 )
{
void T_2 * V_2 ;
struct V_3 * V_4 ;
T_1 V_5 ;
V_4 = F_2 ( NULL , NULL , V_1 ) ;
V_2 = F_3 ( V_4 , 0 ) ;
F_4 ( ! V_2 ) ;
V_5 = F_5 ( V_2 + V_6 ) & 0xff ;
F_6 ( V_2 ) ;
return V_5 ;
}
static int F_7 ( void )
{
T_1 V_7 = F_1 ( L_1 ) ;
switch ( V_7 ) {
case 0x0 :
return V_8 ;
case 0x10 :
return V_9 ;
default:
return V_10 ;
}
}
int F_8 ( void )
{
if ( V_11 == - 1 )
V_11 = F_7 () ;
return V_11 ;
}
int T_3 F_9 ( void )
{
if ( F_8 () < V_9 &&
( V_12 & V_13 ) ) {
V_12 &= ~ V_13 ;
F_10 ( L_2 ) ;
}
return 0 ;
}
static int F_11 ( void )
{
T_1 V_7 = F_1 ( L_3 ) ;
switch ( V_7 ) {
case 0x0 :
return V_14 ;
case 0x2 :
return V_8 ;
case 0x3 :
return V_15 ;
default:
return V_10 ;
}
}
int F_12 ( void )
{
if ( V_11 == - 1 )
V_11 = F_11 () ;
return V_11 ;
}
