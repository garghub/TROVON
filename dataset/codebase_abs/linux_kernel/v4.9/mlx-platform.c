static int T_1 F_1 ( const struct V_1 * V_2 )
{
int V_3 ;
for ( V_3 = 0 ; V_3 < F_2 ( V_4 ) ; V_3 ++ ) {
V_4 [ V_3 ] . V_5 = V_6 [ V_3 ] ;
V_4 [ V_3 ] . V_7 =
F_2 ( V_6 [ V_3 ] ) ;
}
return 1 ;
}
static int T_1 F_3 ( const struct V_1 * V_2 )
{
int V_3 ;
for ( V_3 = 0 ; V_3 < F_2 ( V_4 ) ; V_3 ++ ) {
V_4 [ V_3 ] . V_5 = V_8 ;
V_4 [ V_3 ] . V_7 =
F_2 ( V_8 ) ;
}
return 1 ;
}
static int T_1 F_4 ( void )
{
struct V_9 * V_10 ;
int V_3 , V_11 ;
if ( ! F_5 ( V_12 ) )
return - V_13 ;
V_14 = F_6 ( V_15 , - 1 ,
V_16 ,
F_2 ( V_16 ) ) ;
if ( F_7 ( V_14 ) )
return F_8 ( V_14 ) ;
V_10 = F_9 ( & V_14 -> V_17 , sizeof( struct V_9 ) ,
V_18 ) ;
if ( ! V_10 ) {
V_11 = - V_19 ;
goto V_20;
}
F_10 ( V_14 , V_10 ) ;
V_10 -> V_21 = F_6 ( L_1 , - 1 ,
NULL , 0 ) ;
if ( F_7 ( V_10 -> V_21 ) ) {
V_11 = F_8 ( V_10 -> V_21 ) ;
goto V_20;
} ;
for ( V_3 = 0 ; V_3 < F_2 ( V_4 ) ; V_3 ++ ) {
V_10 -> V_22 [ V_3 ] = F_11 (
& V_14 -> V_17 ,
L_2 , V_3 , NULL ,
0 , & V_4 [ V_3 ] ,
sizeof( V_4 [ V_3 ] ) ) ;
if ( F_7 ( V_10 -> V_22 [ V_3 ] ) ) {
V_11 = F_8 ( V_10 -> V_22 [ V_3 ] ) ;
goto V_23;
}
}
return 0 ;
V_23:
for ( V_3 -- ; V_3 > 0 ; V_3 -- )
F_12 ( V_10 -> V_22 [ V_3 ] ) ;
F_12 ( V_10 -> V_21 ) ;
V_20:
F_12 ( V_14 ) ;
return V_11 ;
}
static void T_2 F_13 ( void )
{
struct V_9 * V_10 = F_14 ( V_14 ) ;
int V_3 ;
for ( V_3 = F_2 ( V_4 ) - 1 ; V_3 >= 0 ; V_3 -- )
F_12 ( V_10 -> V_22 [ V_3 ] ) ;
F_12 ( V_10 -> V_21 ) ;
F_12 ( V_14 ) ;
}
