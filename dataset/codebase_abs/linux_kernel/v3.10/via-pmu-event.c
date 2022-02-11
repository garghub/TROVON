static int T_1 F_1 ( void )
{
int V_1 ;
if ( F_2 () != V_2 )
return - V_3 ;
V_4 = F_3 () ;
if ( ! V_4 )
return - V_5 ;
V_4 -> V_6 = L_1 ;
V_4 -> V_7 . V_8 = V_9 ;
V_4 -> V_7 . V_10 = 0x0001 ;
V_4 -> V_7 . V_11 = 0x0001 ;
V_4 -> V_7 . V_12 = 0x0100 ;
F_4 ( V_13 , V_4 -> V_14 ) ;
F_4 ( V_15 , V_4 -> V_14 ) ;
F_4 ( V_16 , V_4 -> V_17 ) ;
F_4 ( V_18 , V_4 -> V_19 ) ;
V_1 = F_5 ( V_4 ) ;
if ( V_1 )
F_6 ( V_4 ) ;
return V_1 ;
}
void F_7 ( int V_20 , int V_21 )
{
if ( F_8 ( ! V_4 ) )
return;
switch ( V_20 ) {
case V_22 :
F_9 ( V_4 , V_16 , V_21 ) ;
break;
case V_23 :
F_10 ( V_4 , V_18 , V_21 ) ;
break;
default:
return;
}
F_11 ( V_4 ) ;
}
