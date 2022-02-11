static int F_1 ( struct V_1 * V_2 ,
const struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 ;
struct V_9 * V_10 [ 2 ] ;
int V_11 , V_12 ;
F_3 ( V_13 L_1 ,
F_4 ( V_6 -> V_14 . V_15 ) ,
F_4 ( V_6 -> V_14 . V_16 ) ,
V_17 ) ;
V_8 = F_5 ( sizeof( struct V_7 ) , V_18 ) ;
if ( ! V_8 )
return - V_19 ;
V_8 -> V_17 = V_17 ;
V_8 -> V_20 = V_6 ;
V_8 -> V_21 . V_22 = V_23 ;
V_8 -> V_21 . V_24 . V_25 = V_8 ;
V_8 -> V_21 . V_24 . V_26 = V_27 ;
for ( V_12 = 0 ; V_12 < 2 ; V_12 ++ ) {
V_8 -> V_28 [ V_12 ] . V_8 = V_8 ;
V_8 -> V_28 [ V_12 ] . V_29 = V_12 ;
V_8 -> V_28 [ V_12 ] . V_10 . V_24 . V_25 = & V_8 -> V_28 [ V_12 ] ;
V_8 -> V_28 [ V_12 ] . V_10 . V_24 . V_26 = V_30 ;
}
V_11 = F_6 ( V_8 ) ;
if ( V_11 < 0 )
goto V_31;
V_11 = F_7 ( V_8 ) ;
if ( V_11 < 0 )
goto V_32;
V_11 = F_8 ( & V_8 -> V_28 [ 0 ] ) ;
if ( V_11 < 0 )
goto V_33;
V_11 = F_8 ( & V_8 -> V_28 [ 1 ] ) ;
if ( V_11 < 0 )
goto V_34;
for ( V_12 = 0 ; V_12 < 2 ; V_12 ++ )
V_10 [ V_12 ] = & V_8 -> V_28 [ V_12 ] . V_10 ;
if ( F_9 ( & V_8 -> V_21 , V_10 , L_2 ,
V_35 ) != 0 )
goto V_36;
F_10 ( V_8 ) ;
F_11 ( V_2 , V_8 ) ;
return 0 ;
V_36:
F_12 ( & V_8 -> V_28 [ 1 ] ) ;
V_34:
F_12 ( & V_8 -> V_28 [ 0 ] ) ;
V_33:
F_13 ( V_8 ) ;
V_32:
F_14 ( V_8 ) ;
V_31:
F_15 ( V_8 ) ;
return - V_37 ;
}
static void F_16 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = F_17 ( V_2 ) ;
F_18 ( 1 , L_3 ) ;
F_11 ( V_2 , NULL ) ;
if ( ! V_8 )
return;
F_19 ( V_8 ) ;
F_12 ( & V_8 -> V_28 [ 1 ] ) ;
F_12 ( & V_8 -> V_28 [ 0 ] ) ;
F_13 ( V_8 ) ;
F_20 ( 2 ) ;
F_14 ( V_8 ) ;
F_21 ( & V_8 -> V_21 ) ;
F_15 ( V_8 ) ;
}
static int T_1 F_22 ( void )
{
int V_11 ;
#ifdef F_23
V_38 = V_39 ;
#endif
F_3 ( V_13 L_4 ) ;
V_11 = F_24 () ;
if ( V_11 < 0 )
goto V_40;
V_11 = F_25 ( & V_41 ) ;
if ( V_11 < 0 )
goto V_42;
return 0 ;
V_42:
F_26 () ;
V_40:
return V_11 ;
}
static void T_2 F_27 ( void )
{
F_28 ( & V_41 ) ;
F_26 () ;
}
