static int T_1 F_1 ( void )
{
struct V_1 * V_2 ;
struct V_3 * V_4 ;
unsigned int V_5 ;
int V_6 ;
V_2 = F_2 ( L_1 , - 1 ) ;
if ( ! V_2 )
return - V_7 ;
switch ( F_3 () ) {
case V_8 :
case V_9 :
V_2 -> V_10 . V_11 = V_12 ;
V_4 = V_13 ;
V_5 = F_4 ( V_13 ) ;
break;
case V_14 :
case V_15 :
case V_16 :
V_2 -> V_10 . V_11 = V_17 ;
V_4 = V_18 ;
V_5 = F_4 ( V_18 ) ;
break;
default:
V_6 = - V_19 ;
goto V_20;
}
V_6 = F_5 ( V_2 , V_4 , V_5 ) ;
if ( V_6 )
goto V_20;
V_6 = F_6 ( V_2 ) ;
if ( V_6 )
goto V_20;
return 0 ;
V_20:
F_7 ( V_2 ) ;
return V_6 ;
}
void T_1 F_8 ( void )
{
struct V_21 V_22 ;
struct V_3 * V_4 ;
unsigned int * type ;
int V_23 ;
switch ( F_3 () ) {
case V_8 :
case V_9 :
type = V_12 ;
V_4 = V_13 ;
break;
case V_14 :
case V_15 :
case V_16 :
type = V_17 ;
V_4 = V_18 ;
break;
default:
return;
}
for ( V_23 = 0 ; V_23 < V_24 ; V_23 ++ ) {
V_22 . line = V_23 ;
V_22 . type = type [ V_23 ] ;
if ( V_22 . type == V_25 )
break;
V_22 . V_26 = V_4 [ V_23 ] . V_27 ;
V_22 . V_28 = ( unsigned char V_29 * ) F_9 ( V_4 [ V_23 ] . V_27 ) ;
F_10 ( & V_22 ) ;
}
}
