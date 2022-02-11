static const char * F_1 ( void )
{
switch ( F_2 ( F_3 ( V_1 ) ) ) {
case V_2 :
case V_3 :
return L_1 ;
case V_4 :
return L_2 ;
case V_5 :
return L_3 ;
case V_6 :
return L_4 ;
case V_7 :
case V_8 :
return L_5 ;
default:
return L_6 ;
}
}
const char * F_4 ( void )
{
return F_1 () ;
}
void T_1 F_5 ( void )
{
int V_9 ;
switch ( F_6 () ) {
case V_10 :
V_9 = F_7 () ;
break;
case V_11 :
V_9 = F_8 () ;
break;
case V_12 :
V_9 = F_9 () ;
break;
default:
F_10 ( L_7 ) ;
V_9 = - V_13 ;
}
if ( V_9 )
F_11 ( L_8 ) ;
}
int T_1 F_12 ( void )
{
int V_14 = F_2 ( F_3 ( V_1 ) ) ;
if ( V_14 == V_6 )
return F_13 ( 0 ) ;
else if ( ( V_14 == V_7 ) ||
( V_14 == V_8 ) )
return F_13 ( 1 ) ;
return 0 ;
}
int T_1 F_14 ( void )
{
switch ( F_2 ( F_3 ( V_1 ) ) ) {
case V_2 :
case V_3 :
case V_4 :
return F_15 () ;
case V_5 :
return F_16 () ;
case V_6 :
case V_7 :
case V_8 :
return F_17 () ;
}
return 0 ;
}
