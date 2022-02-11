static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
const T_1 * V_6 ;
unsigned int V_7 , V_8 [] = {
V_9 ,
V_10 ,
V_11 ,
} ;
if ( ! V_4 )
return;
V_6 = ( const T_1 * ) V_4 -> V_12 ;
if ( ! F_2 ( V_6 ) )
return;
for ( V_7 = 0 ; V_7 < 3 ; V_7 ++ ) {
F_3 ( V_2 , V_13 ,
V_14 ) ;
F_3 ( V_2 , V_15 ,
V_8 [ V_7 ] ) ;
F_3 ( V_2 , V_13 ,
V_16 ) ;
F_3 ( V_2 , V_15 ,
V_6 [ ( V_7 * 2 ) + 1 ] | ( V_6 [ ( V_7 * 2 ) ] << 8 ) ) ;
}
}
static int F_4 ( struct V_1 * V_2 )
{
int V_17 ;
T_2 V_18 ;
int V_19 ;
V_18 = V_20 | V_21 | V_22 |
V_23 | V_24 ;
V_17 = F_5 ( V_2 , V_25 ) ;
if ( V_17 < 0 )
return V_17 ;
if ( V_17 & V_26 )
V_18 |= V_27 ;
if ( V_17 & V_28 )
V_18 |= V_29 ;
if ( V_17 & V_30 )
V_18 |= V_31 ;
if ( V_17 & V_32 )
V_18 |= V_33 ;
if ( V_17 & V_34 )
V_18 |= V_35 ;
if ( V_17 & V_36 ) {
V_17 = F_5 ( V_2 , V_37 ) ;
if ( V_17 < 0 )
return V_17 ;
if ( V_17 & V_38 )
V_18 |= V_39 ;
if ( V_17 & V_40 )
V_18 |= V_41 ;
}
V_2 -> V_42 = V_18 ;
V_2 -> V_43 = V_18 ;
F_1 ( V_2 ) ;
V_19 = F_3 ( V_2 , V_44 , V_45 ) ;
V_19 = F_5 ( V_2 , V_46 ) ;
return 0 ;
}
static int T_3 F_6 ( void )
{
int V_47 ;
V_47 = F_7 ( & V_48 ) ;
if ( V_47 )
goto V_49;
V_47 = F_7 ( & V_50 ) ;
if ( V_47 )
goto V_51;
return 0 ;
V_51:
F_8 ( & V_48 ) ;
V_49:
return V_47 ;
}
static void T_4 F_9 ( void )
{
F_8 ( & V_48 ) ;
F_8 ( & V_50 ) ;
}
