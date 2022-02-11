static int T_1 F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
int V_5 = 0 ;
V_5 = F_2 ( V_2 ) ;
if ( V_5 )
F_3 ( V_6 L_1 ) ;
V_5 = F_4 ( V_2 , V_7 [ V_8 ] ) ;
if ( V_5 )
F_3 ( V_6 L_2 , 0 ) ;
V_5 = F_4 ( V_2 , V_7 [ V_9 ] ) ;
if ( V_5 )
F_3 ( V_6 L_2 , 0 ) ;
V_4 = F_5 ( V_10 ) ;
if ( F_6 ( V_4 ) )
return F_7 ( V_4 ) ;
V_5 = F_8 ( V_2 , V_4 ) ;
if ( V_5 )
goto V_11;
V_5 = F_9 ( V_2 , V_12 , V_13 ) ;
if ( V_5 ) {
F_10 ( L_3 , V_5 ) ;
goto V_14;
}
if ( V_2 == & V_15 )
V_16 = V_4 ;
else
V_17 = V_4 ;
return V_5 ;
V_14:
F_11 ( V_2 , V_4 ) ;
V_11:
F_12 ( V_4 ) ;
return V_5 ;
}
static int T_1 F_13 ( struct V_18 * V_19 )
{
struct V_20 * V_21 = V_19 -> V_21 ;
int V_5 ;
int V_22 ;
V_5 = F_14 ( V_19 -> V_21 ) ;
if ( V_5 < 0 )
goto V_23;
for ( V_22 = 0 ; V_22 < V_24 ; V_22 ++ ) {
V_5 = F_15 ( & V_7 [ V_22 ] ) ;
if ( V_5 )
goto V_25;
}
V_13 = F_16 ( V_19 -> V_21 , V_12 ) ;
if ( F_6 ( V_13 ) ) {
V_5 = F_7 ( V_13 ) ;
goto V_25;
}
V_5 = F_17 ( V_19 , V_26 ) ;
if ( V_5 < 0 )
goto V_27;
V_28 . V_29 = V_26 [ V_30 ] . V_31 ;
V_28 . V_32 = V_26 [ V_33 ] . V_31 ;
V_5 = V_26 [ V_34 ] . V_31 ;
V_15 . V_35 = V_5 ;
V_36 . V_35 = V_5 ;
if ( ! F_18 ( V_21 ) )
goto V_27;
V_10 = F_19 ( L_4 ) ;
if ( F_6 ( V_10 ) )
goto V_27;
V_5 = F_20 ( V_19 , & V_15 ,
F_1 ) ;
if ( V_5 < 0 )
goto V_37;
V_5 = F_20 ( V_19 , & V_36 ,
F_1 ) ;
if ( V_5 < 0 )
goto V_38;
F_21 ( V_19 , & V_39 ) ;
F_22 ( & V_21 -> V_40 , L_5 , V_41 ) ;
return 0 ;
V_38:
F_12 ( V_16 ) ;
V_37:
F_23 ( V_10 ) ;
V_27:
F_24 ( V_13 ) ;
V_25:
V_22 -- ;
while ( V_22 >= 0 )
F_25 ( V_7 [ V_22 -- ] ) ;
F_26 () ;
V_23:
return V_5 ;
}
static int T_2 F_27 ( struct V_18 * V_19 )
{
int V_42 ;
F_12 ( V_16 ) ;
F_12 ( V_17 ) ;
F_23 ( V_10 ) ;
F_26 () ;
for ( V_42 = 0 ; V_42 < V_24 ; V_42 ++ )
F_25 ( V_7 [ V_42 ] ) ;
F_24 ( V_13 ) ;
return 0 ;
}
static int T_1 F_28 ( void )
{
return F_29 ( & V_43 ) ;
}
static void T_2 F_30 ( void )
{
F_31 ( & V_43 ) ;
}
