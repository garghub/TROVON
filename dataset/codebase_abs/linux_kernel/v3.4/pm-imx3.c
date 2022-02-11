void F_1 ( enum V_1 V_2 )
{
int V_3 = F_2 ( V_4 ) ;
V_3 &= ~ V_5 ;
switch ( V_2 ) {
case V_6 :
if ( F_3 () )
V_3 |= V_7 ;
F_4 ( V_3 , V_4 ) ;
break;
default:
F_5 ( L_1 , V_2 ) ;
return;
}
}
