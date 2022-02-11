void F_1 ( enum V_1 V_2 )
{
int V_3 = F_2 ( V_4 + V_5 ) ;
V_3 &= ~ V_6 ;
switch ( V_2 ) {
case V_7 :
if ( F_3 () )
V_3 |= V_8 ;
F_4 ( V_3 , V_4 + V_5 ) ;
break;
default:
F_5 ( L_1 , V_2 ) ;
return;
}
}
