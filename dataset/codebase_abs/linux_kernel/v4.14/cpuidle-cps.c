static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 , int V_5 )
{
enum V_6 V_7 ;
int V_8 ;
if ( F_2 ( 0 , V_2 -> V_9 ) && ( V_5 > V_10 ) )
V_5 = V_10 ;
switch ( V_5 ) {
case V_10 :
V_7 = V_11 ;
break;
case V_12 :
V_7 = V_13 ;
break;
case V_14 :
V_7 = V_15 ;
break;
default:
F_3 () ;
return - V_16 ;
}
if ( ( V_7 == V_15 ) && F_4 () )
return - V_17 ;
V_8 = F_5 ( V_7 ) ;
if ( V_7 == V_15 )
F_6 () ;
return V_8 ? : V_5 ;
}
static void T_1 F_7 ( void )
{
int V_9 ;
struct V_1 * V_18 ;
F_8 (cpu) {
V_18 = & F_9 ( V_19 , V_9 ) ;
F_10 ( V_18 ) ;
}
F_11 ( & V_20 ) ;
}
static int T_1 F_12 ( void )
{
int V_8 , V_9 , V_21 ;
struct V_1 * V_18 ;
if ( ! F_13 ( V_15 ) )
V_20 . V_22 = V_12 + 1 ;
if ( ! F_13 ( V_13 ) )
V_20 . V_22 = V_10 + 1 ;
if ( ! F_13 ( V_11 ) )
V_20 . V_22 = V_23 + 1 ;
if ( V_20 . V_22 < V_24 ) {
F_14 ( L_1 ) ;
switch ( V_20 . V_22 - 1 ) {
case V_23 :
F_15 ( L_2 ) ;
break;
case V_10 :
F_15 ( L_3 ) ;
break;
case V_12 :
F_15 ( L_4 ) ;
break;
}
}
if ( V_25 )
for ( V_21 = V_10 ; V_21 < V_20 . V_22 ; V_21 ++ )
V_20 . V_26 [ V_21 ] . V_27 |= V_28 ;
V_8 = F_16 ( & V_20 ) ;
if ( V_8 ) {
F_17 ( L_5 ) ;
return V_8 ;
}
F_8 (cpu) {
V_18 = & F_9 ( V_19 , V_9 ) ;
V_18 -> V_9 = V_9 ;
#ifdef F_18
F_19 ( & V_18 -> V_29 , & V_30 [ V_9 ] ) ;
#endif
V_8 = F_20 ( V_18 ) ;
if ( V_8 ) {
F_17 ( L_6 ,
V_9 ) ;
goto V_31;
}
}
return 0 ;
V_31:
F_7 () ;
return V_8 ;
}
