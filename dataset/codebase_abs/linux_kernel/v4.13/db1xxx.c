static const char * F_1 ( void )
{
switch ( F_2 ( F_3 ( V_1 ) ) ) {
case V_2 :
return L_1 ;
case V_3 :
return L_2 ;
case V_4 :
return L_3 ;
case V_5 :
case V_6 :
return L_4 ;
case V_7 :
return L_5 ;
case V_8 :
case V_9 :
return L_6 ;
case V_10 :
return L_7 ;
case V_11 :
return L_8 ;
case V_12 :
return L_9 ;
case V_13 :
case V_14 :
return L_10 ;
default:
return L_11 ;
}
}
const char * F_4 ( void )
{
return F_1 () ;
}
void T_1 F_5 ( void )
{
int V_15 ;
switch ( F_6 () ) {
case V_16 :
case V_17 :
case V_18 :
V_15 = F_7 () ;
break;
case V_19 :
V_15 = F_8 () ;
break;
case V_20 :
V_15 = F_9 () ;
break;
case V_21 :
V_15 = F_10 () ;
break;
default:
F_11 ( L_12 ) ;
V_15 = - V_22 ;
}
if ( V_15 )
F_12 ( L_13 ) ;
}
static int T_1 F_13 ( void )
{
int V_23 = F_2 ( F_3 ( V_1 ) ) ;
if ( V_23 == V_12 )
return F_14 ( 0 ) ;
else if ( ( V_23 == V_13 ) ||
( V_23 == V_14 ) )
return F_14 ( 1 ) ;
else if ( ( V_23 == V_3 ) || ( V_23 == V_5 ) ||
( V_23 == V_6 ) )
return F_15 () ;
return 0 ;
}
static int T_1 F_16 ( void )
{
switch ( F_2 ( F_3 ( V_1 ) ) ) {
case V_2 :
case V_3 :
case V_4 :
case V_5 :
case V_6 :
case V_7 :
return F_17 () ;
case V_8 :
case V_9 :
case V_10 :
return F_18 () ;
case V_11 :
return F_19 () ;
case V_12 :
case V_13 :
case V_14 :
return F_20 () ;
}
return 0 ;
}
