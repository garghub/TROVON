static int F_1 ( T_1 V_1 , T_1 V_2 )
{
F_2 ( V_3 [ V_1 ] . V_4 , V_2 , true ) ;
return 0 ;
}
static int F_3 ( void * V_5 , struct V_6 * V_7 ,
void * V_8 )
{
V_7 -> V_4 = F_4 ( V_9 , V_5 , V_8 ) ;
if ( ! V_7 -> V_4 )
return - V_10 ;
else
return 0 ;
}
static int T_2 F_5 ( void )
{
int V_11 , V_12 ;
for ( V_11 = 0 ; V_11 < V_13 ; V_11 ++ ) {
V_3 [ V_11 ] . V_14 = V_15 ;
V_3 [ V_11 ] . V_16 = V_17 ;
if ( ( ( char * ) V_3 [ V_11 ] . V_14 == NULL )
|| ( V_3 [ V_11 ] . V_16 <= 0 ) ) {
F_6 ( L_1
L_2
L_3 ) ;
V_12 = - V_18 ;
goto V_19;
}
F_7 ( L_4
L_5 , V_11 , ( char * ) V_3 [ V_11 ] . V_14 ) ;
V_3 [ V_11 ] . V_20 = V_11 ;
V_3 [ V_11 ] . V_21 = F_1 ;
V_3 [ V_11 ] . V_22 = F_3 ;
V_12 = F_8 ( & V_3 [ V_11 ] ) ;
if ( V_12 ) {
F_6 ( L_6
L_7
L_8 , V_12 , V_11 ) ;
goto V_19;
}
}
return 0 ;
V_19:
for ( V_11 = 0 ; V_11 < V_13 ; V_11 ++ ) {
if ( V_3 [ V_11 ] . V_23 )
F_9 ( V_3 [ V_11 ] . V_23 ) ;
}
return V_12 ;
}
static void T_3 F_10 ( void )
{
int V_11 ;
for ( V_11 = 0 ; V_11 < V_13 ; V_11 ++ ) {
F_11 ( V_3 [ V_11 ] . V_23 ) ;
F_12 ( ( void * ) V_3 [ V_11 ] . V_14 ) ;
}
}
