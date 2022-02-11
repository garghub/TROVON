static void F_1 ( void )
{
int V_1 ;
struct V_2 * V_3 ;
struct V_2 * * V_4 = F_2 ( F_3 () ) ;
if ( V_4 == NULL || * V_4 == NULL )
return;
V_3 = * V_4 ;
if ( V_3 -> V_5 == 1 && F_4 () == 0 ) {
for ( V_1 = 0 ; V_1 < V_6 ; V_1 ++ ) {
F_5 ( & V_7 [ V_1 ] . V_8 ) ;
F_5 ( & V_7 [ V_1 ] . V_9 ) ;
}
V_3 -> V_5 = 0 ;
}
}
void F_6 ( void )
{
F_7 ( F_3 () ) ;
}
int T_1 F_8 ( void )
{
struct V_10 * V_11 ;
int V_1 , V_12 ;
if ( ! V_13 ) {
F_9 ( L_1 ) ;
return - V_14 ;
}
if ( F_10 () - F_3 () < 1 ) {
F_9 ( L_2
L_3 ) ;
return - V_14 ;
}
V_15 = F_11 ( 0 , V_16 , & V_17 ) ;
if ( V_15 < 0 ) {
F_12 ( L_4 ) ;
return V_15 ;
}
for ( V_1 = 0 ; V_1 < V_6 ; V_1 ++ ) {
F_13 ( & V_7 [ V_1 ] . V_9 ) ;
F_13 ( & V_7 [ V_1 ] . V_8 ) ;
F_14 ( & V_7 [ V_1 ] . V_18 , 0 ) ;
F_15 ( & V_7 [ V_1 ] . V_19 ) ;
V_11 = F_16 ( V_20 , NULL , F_17 ( V_15 , V_1 ) , NULL ,
L_5 , V_16 , V_1 ) ;
if ( F_18 ( V_11 ) ) {
while ( V_1 -- )
F_19 ( V_20 , F_17 ( V_15 , V_1 ) ) ;
V_12 = F_20 ( V_11 ) ;
goto V_21;
}
}
V_22 . V_23 = V_24 ;
V_22 . V_25 = V_26 ;
F_21 ( F_3 () , & V_22 ) ;
if ( V_27 ) {
V_28 = F_1 ;
} else {
F_12 ( L_6 ) ;
V_12 = - V_14 ;
goto V_29;
}
return 0 ;
V_29:
for ( V_1 = 0 ; V_1 < V_6 ; V_1 ++ )
F_19 ( V_20 , F_17 ( V_15 , V_1 ) ) ;
V_21:
F_22 ( V_15 , V_16 ) ;
return V_12 ;
}
void T_2 F_23 ( void )
{
int V_1 ;
for ( V_1 = 0 ; V_1 < V_6 ; V_1 ++ )
F_19 ( V_20 , F_17 ( V_15 , V_1 ) ) ;
F_22 ( V_15 , V_16 ) ;
V_28 = NULL ;
}
