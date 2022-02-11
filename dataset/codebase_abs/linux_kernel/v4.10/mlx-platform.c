static int T_1 F_1 ( const struct V_1 * V_2 )
{
int V_3 ;
for ( V_3 = 0 ; V_3 < F_2 ( V_4 ) ; V_3 ++ ) {
V_4 [ V_3 ] . V_5 = V_6 [ V_3 ] ;
V_4 [ V_3 ] . V_7 =
F_2 ( V_6 [ V_3 ] ) ;
}
V_8 = & V_9 ;
return 1 ;
}
static int T_1 F_3 ( const struct V_1 * V_2 )
{
int V_3 ;
for ( V_3 = 0 ; V_3 < F_2 ( V_4 ) ; V_3 ++ ) {
V_4 [ V_3 ] . V_5 = V_10 ;
V_4 [ V_3 ] . V_7 =
F_2 ( V_10 ) ;
}
V_8 = & V_11 ;
return 1 ;
}
static int T_1 F_4 ( void )
{
struct V_12 * V_13 ;
int V_3 , V_14 ;
if ( ! F_5 ( V_15 ) )
return - V_16 ;
V_17 = F_6 ( V_18 , - 1 ,
V_19 ,
F_2 ( V_19 ) ) ;
if ( F_7 ( V_17 ) )
return F_8 ( V_17 ) ;
V_13 = F_9 ( & V_17 -> V_20 , sizeof( struct V_12 ) ,
V_21 ) ;
if ( ! V_13 ) {
V_14 = - V_22 ;
goto V_23;
}
F_10 ( V_17 , V_13 ) ;
V_13 -> V_24 = F_6 ( L_1 , - 1 ,
NULL , 0 ) ;
if ( F_7 ( V_13 -> V_24 ) ) {
V_14 = F_8 ( V_13 -> V_24 ) ;
goto V_23;
}
for ( V_3 = 0 ; V_3 < F_2 ( V_4 ) ; V_3 ++ ) {
V_13 -> V_25 [ V_3 ] = F_11 (
& V_17 -> V_20 ,
L_2 , V_3 , NULL ,
0 , & V_4 [ V_3 ] ,
sizeof( V_4 [ V_3 ] ) ) ;
if ( F_7 ( V_13 -> V_25 [ V_3 ] ) ) {
V_14 = F_8 ( V_13 -> V_25 [ V_3 ] ) ;
goto V_26;
}
}
V_13 -> V_27 = F_11 (
& V_17 -> V_20 , L_3 , - 1 ,
V_28 ,
F_2 ( V_28 ) ,
V_8 , sizeof( * V_8 ) ) ;
if ( F_7 ( V_13 -> V_27 ) ) {
V_14 = F_8 ( V_13 -> V_27 ) ;
goto V_26;
}
return 0 ;
V_26:
while ( -- V_3 >= 0 )
F_12 ( V_13 -> V_25 [ V_3 ] ) ;
F_12 ( V_13 -> V_24 ) ;
V_23:
F_12 ( V_17 ) ;
return V_14 ;
}
static void T_2 F_13 ( void )
{
struct V_12 * V_13 = F_14 ( V_17 ) ;
int V_3 ;
F_12 ( V_13 -> V_27 ) ;
for ( V_3 = F_2 ( V_4 ) - 1 ; V_3 >= 0 ; V_3 -- )
F_12 ( V_13 -> V_25 [ V_3 ] ) ;
F_12 ( V_13 -> V_24 ) ;
F_12 ( V_17 ) ;
}
