static int T_1 F_1 ( struct V_1 * V_2 )
{
int V_3 = 0 ;
V_3 = F_2 ( V_2 ) ;
if ( V_3 )
F_3 ( V_4 L_1 ) ;
V_3 = F_4 ( V_2 , V_5 [ V_6 ] ) ;
if ( V_3 )
F_3 ( V_4 L_2 , 0 ) ;
V_3 = F_4 ( V_2 , V_5 [ V_7 ] ) ;
if ( V_3 )
F_3 ( V_4 L_2 , 0 ) ;
V_3 = F_5 ( V_2 , V_5 [ V_8 ] ) ;
if ( V_3 )
F_3 ( V_4 L_3 ) ;
V_3 = F_6 ( V_2 , V_9 ) ;
if ( V_3 )
F_3 ( V_4 L_4 ) ;
return V_3 ;
}
static int T_1 F_7 ( struct V_10 * V_11 )
{
struct V_12 * V_13 = V_11 -> V_13 ;
int V_3 ;
int V_14 ;
V_3 = F_8 ( V_11 -> V_13 ) ;
if ( V_3 < 0 )
goto V_15;
for ( V_14 = 0 ; V_14 < V_16 ; V_14 ++ ) {
V_3 = F_9 ( & V_5 [ V_14 ] ) ;
if ( V_3 )
goto V_17;
}
V_3 = F_10 ( V_11 -> V_13 , V_9 ) ;
if ( V_3 < 0 )
goto V_17;
V_3 = F_11 ( V_11 , V_18 ) ;
if ( V_3 < 0 )
goto V_19;
V_20 . V_21 = V_18 [ V_22 ] . V_23 ;
V_20 . V_24 = V_18 [ V_25 ] . V_23 ;
V_3 = V_18 [ V_26 ] . V_23 ;
V_27 . V_28 = V_3 ;
V_29 . V_28 = V_3 ;
if ( ! F_12 ( V_13 ) )
goto V_19;
V_3 = F_13 ( V_11 , & V_27 ,
F_1 ) ;
if ( V_3 < 0 )
goto V_19;
V_3 = F_13 ( V_11 , & V_29 ,
F_1 ) ;
if ( V_3 < 0 )
goto V_19;
F_14 ( V_11 , & V_30 ) ;
F_15 ( & V_13 -> V_31 , L_5 , V_32 ) ;
return 0 ;
V_19:
F_16 () ;
V_17:
V_14 -- ;
while ( V_14 >= 0 )
F_17 ( V_5 [ V_14 -- ] ) ;
F_18 () ;
V_15:
return V_3 ;
}
static int T_2 F_19 ( struct V_10 * V_11 )
{
int V_33 ;
F_18 () ;
for ( V_33 = 0 ; V_33 < V_16 ; V_33 ++ )
F_17 ( V_5 [ V_33 ] ) ;
F_16 () ;
return 0 ;
}
static int T_1 F_20 ( void )
{
return F_21 ( & V_34 ) ;
}
static void T_2 F_22 ( void )
{
F_23 ( & V_34 ) ;
}
