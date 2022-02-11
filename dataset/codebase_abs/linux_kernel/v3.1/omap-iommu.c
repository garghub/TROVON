static int T_1 F_1 ( void )
{
int V_1 , V_2 ;
struct V_3 V_4 [] = {
{ . V_5 = V_6 } ,
{ . V_5 = V_7 } ,
} ;
if ( F_2 () ) {
V_8 = V_9 ;
V_10 = V_11 ;
V_12 = V_13 ;
} else if ( F_3 () ) {
V_8 = V_14 ;
V_10 = V_15 ;
V_12 = V_16 ;
} else
return - V_17 ;
for ( V_1 = 0 ; V_1 < V_12 ; V_1 ++ ) {
struct V_18 * V_19 ;
const struct V_20 * V_21 = & V_8 [ V_1 ] ;
V_19 = F_4 ( L_1 , V_1 ) ;
if ( ! V_19 ) {
V_2 = - V_22 ;
goto V_23;
}
V_4 [ 0 ] . V_24 = V_21 -> V_25 ;
V_4 [ 0 ] . V_26 = V_21 -> V_25 + V_27 - 1 ;
V_4 [ 1 ] . V_24 = V_4 [ 1 ] . V_26 = V_21 -> V_28 ;
V_2 = F_5 ( V_19 , V_4 ,
F_6 ( V_4 ) ) ;
if ( V_2 )
goto V_23;
V_2 = F_7 ( V_19 , & V_21 -> V_29 ,
sizeof( V_21 -> V_29 ) ) ;
if ( V_2 )
goto V_23;
V_2 = F_8 ( V_19 ) ;
if ( V_2 )
goto V_23;
V_10 [ V_1 ] = V_19 ;
}
return 0 ;
V_23:
while ( V_1 -- )
F_9 ( V_10 [ V_1 ] ) ;
return V_2 ;
}
static void T_2 F_10 ( void )
{
int V_1 ;
for ( V_1 = 0 ; V_1 < V_12 ; V_1 ++ )
F_11 ( V_10 [ V_1 ] ) ;
}
