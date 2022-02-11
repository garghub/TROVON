static int T_1 F_1 ( unsigned int V_1 ,
T_2 V_2 , unsigned int V_3 )
{
int V_4 ;
V_4 = F_2 ( V_1 , 0 ) ;
if ( ! V_4 )
V_4 = F_3 ( V_1 , V_2 , V_3 ) ;
if ( ! V_4 )
V_4 = F_2 ( V_1 , 1 ) ;
return V_4 ;
}
int T_1 F_4 ( void )
{
int V_4 , V_5 ;
if ( ! F_5 () && ! F_6 () )
return 0 ;
switch ( F_7 () ) {
case V_6 :
V_7 . V_8 = 22 ;
break;
case V_9 :
V_7 . V_8 = 18 ;
break;
default:
return - V_10 ;
}
V_11 [ 0 ] . V_12 = F_8 ( V_13 ) ;
V_11 [ 0 ] . V_14 = V_11 [ 0 ] . V_12 +
V_15 - 1 ;
V_11 [ 4 ] . V_12 = F_9 ( V_16 ) ;
for ( V_5 = 0 ; V_5 < 3 ; V_5 ++ ) {
V_4 = F_1 ( V_17 [ V_5 ] . V_1 ,
V_17 [ V_5 ] . V_2 ,
V_17 [ V_5 ] . V_3 ) ;
if ( V_4 )
goto V_18;
}
return F_10 ( & V_19 ) ;
V_18:
F_11 ( L_1 ) ;
return V_4 ;
}
