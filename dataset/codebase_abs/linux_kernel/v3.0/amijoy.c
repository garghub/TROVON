static T_1 F_1 ( int V_1 , void * V_2 )
{
int V_3 , V_4 = 0 , V_5 = 0 ;
for ( V_3 = 0 ; V_3 < 2 ; V_3 ++ )
if ( V_6 [ V_3 ] ) {
switch ( V_3 ) {
case 0 : V_4 = ~ V_7 . V_8 ; V_5 = ( ~ V_9 . V_10 >> 6 ) & 1 ; break;
case 1 : V_4 = ~ V_7 . V_11 ; V_5 = ( ~ V_9 . V_10 >> 7 ) & 1 ; break;
}
F_2 ( V_12 [ V_3 ] , V_13 , V_5 ) ;
F_3 ( V_12 [ V_3 ] , V_14 , ( ( V_4 >> 1 ) & 1 ) - ( ( V_4 >> 9 ) & 1 ) ) ;
V_4 = ~ ( V_4 ^ ( V_4 << 1 ) ) ;
F_3 ( V_12 [ V_3 ] , V_15 , ( ( V_4 >> 1 ) & 1 ) - ( ( V_4 >> 9 ) & 1 ) ) ;
F_4 ( V_12 [ V_3 ] ) ;
}
return V_16 ;
}
static int F_5 ( struct V_17 * V_18 )
{
int V_19 ;
V_19 = F_6 ( & V_20 ) ;
if ( V_19 )
return V_19 ;
if ( ! V_21 && F_7 ( V_22 , F_1 , 0 , L_1 , F_1 ) ) {
F_8 ( V_23 L_2 , V_22 ) ;
V_19 = - V_24 ;
goto V_25;
}
V_21 ++ ;
V_25:
F_9 ( & V_20 ) ;
return V_19 ;
}
static void F_10 ( struct V_17 * V_18 )
{
F_11 ( & V_20 ) ;
if ( ! -- V_21 )
F_12 ( V_22 , F_1 ) ;
F_9 ( & V_20 ) ;
}
static int T_2 F_13 ( void )
{
int V_3 , V_26 ;
int V_19 ;
for ( V_3 = 0 ; V_3 < 2 ; V_3 ++ ) {
if ( ! V_6 [ V_3 ] )
continue;
V_12 [ V_3 ] = F_14 () ;
if ( ! V_12 [ V_3 ] ) {
V_19 = - V_27 ;
goto V_28;
}
if ( ! F_15 ( V_29 + 10 + V_3 * 2 , 2 , L_3 ) ) {
F_16 ( V_12 [ V_3 ] ) ;
V_19 = - V_24 ;
goto V_28;
}
V_12 [ V_3 ] -> V_30 = L_4 ;
V_12 [ V_3 ] -> V_31 = V_32 [ V_3 ] ;
V_12 [ V_3 ] -> V_33 . V_34 = V_35 ;
V_12 [ V_3 ] -> V_33 . V_36 = 0x0001 ;
V_12 [ V_3 ] -> V_33 . V_37 = 0x0003 ;
V_12 [ V_3 ] -> V_33 . V_38 = 0x0100 ;
V_12 [ V_3 ] -> V_39 = F_5 ;
V_12 [ V_3 ] -> V_40 = F_10 ;
V_12 [ V_3 ] -> V_41 [ 0 ] = F_17 ( V_42 ) | F_17 ( V_43 ) ;
V_12 [ V_3 ] -> V_44 [ 0 ] = F_17 ( V_14 ) | F_17 ( V_15 ) ;
V_12 [ V_3 ] -> V_45 [ F_18 ( V_46 ) ] = F_17 ( V_46 ) |
F_17 ( V_47 ) | F_17 ( V_48 ) ;
for ( V_26 = 0 ; V_26 < 2 ; V_26 ++ ) {
F_19 ( V_12 [ V_3 ] , V_14 + V_26 ,
- 1 , 1 , 0 , 0 ) ;
}
V_19 = F_20 ( V_12 [ V_3 ] ) ;
if ( V_19 ) {
F_16 ( V_12 [ V_3 ] ) ;
goto V_28;
}
}
return 0 ;
V_28: while ( -- V_3 >= 0 )
if ( V_6 [ V_3 ] ) {
F_21 ( V_12 [ V_3 ] ) ;
F_22 ( V_29 + 10 + V_3 * 2 , 2 ) ;
}
return V_19 ;
}
static void T_3 F_23 ( void )
{
int V_3 ;
for ( V_3 = 0 ; V_3 < 2 ; V_3 ++ )
if ( V_6 [ V_3 ] ) {
F_21 ( V_12 [ V_3 ] ) ;
F_22 ( V_29 + 10 + V_3 * 2 , 2 ) ;
}
}
