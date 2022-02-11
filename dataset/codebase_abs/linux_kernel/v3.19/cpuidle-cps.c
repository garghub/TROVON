static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 , int V_5 )
{
enum V_6 V_7 ;
int V_8 ;
if ( ! V_9 [ V_2 -> V_10 ] . V_11 && ( V_5 > V_12 ) )
V_5 = V_12 ;
switch ( V_5 ) {
case V_12 :
V_7 = V_13 ;
break;
case V_14 :
V_7 = V_15 ;
break;
case V_16 :
V_7 = V_17 ;
break;
default:
F_2 () ;
return - V_18 ;
}
if ( ( V_7 == V_17 ) && F_3 () )
return - V_19 ;
V_8 = F_4 ( V_7 ) ;
if ( V_7 == V_17 )
F_5 () ;
return V_8 ? : V_5 ;
}
static void T_1 F_6 ( void )
{
int V_10 ;
struct V_1 * V_20 ;
F_7 (cpu) {
V_20 = & F_8 ( V_21 , V_10 ) ;
F_9 ( V_20 ) ;
}
F_10 ( & V_22 ) ;
}
static int T_1 F_11 ( void )
{
int V_8 , V_10 , V_11 , V_23 ;
struct V_1 * V_20 ;
if ( ! F_12 ( V_17 ) )
V_22 . V_24 = V_14 + 1 ;
if ( ! F_12 ( V_15 ) )
V_22 . V_24 = V_12 + 1 ;
if ( ! F_12 ( V_13 ) )
V_22 . V_24 = V_25 + 1 ;
if ( V_22 . V_24 < V_26 ) {
F_13 ( L_1 ) ;
switch ( V_22 . V_24 - 1 ) {
case V_25 :
F_14 ( L_2 ) ;
break;
case V_12 :
F_14 ( L_3 ) ;
break;
case V_14 :
F_14 ( L_4 ) ;
break;
}
}
if ( V_27 )
for ( V_23 = V_12 ; V_23 < V_22 . V_24 ; V_23 ++ )
V_22 . V_28 [ V_23 ] . V_29 |= V_30 ;
V_8 = F_15 ( & V_22 ) ;
if ( V_8 ) {
F_16 ( L_5 ) ;
return V_8 ;
}
F_7 (cpu) {
V_11 = V_9 [ V_10 ] . V_11 ;
V_20 = & F_8 ( V_21 , V_10 ) ;
V_20 -> V_10 = V_10 ;
#ifdef F_17
F_18 ( & V_20 -> V_31 , & V_32 [ V_10 ] ) ;
#endif
V_8 = F_19 ( V_20 ) ;
if ( V_8 ) {
F_16 ( L_6 ,
V_10 ) ;
goto V_33;
}
}
return 0 ;
V_33:
F_6 () ;
return V_8 ;
}
