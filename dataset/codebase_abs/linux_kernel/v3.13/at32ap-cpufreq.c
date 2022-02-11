static unsigned int F_1 ( unsigned int V_1 )
{
if ( V_1 )
return 0 ;
return ( unsigned int ) ( ( F_2 ( V_2 ) + 500 ) / 1000 ) ;
}
static int F_3 ( struct V_3 * V_4 , unsigned int V_5 )
{
unsigned int V_6 , V_7 ;
V_6 = F_1 ( 0 ) ;
V_7 = V_8 [ V_5 ] . V_9 ;
if ( ! V_10 ) {
V_10 = V_6 ;
V_11 = V_12 . V_13 ;
}
if ( V_6 < V_7 )
V_12 . V_13 = F_4 (
V_11 , V_10 , V_7 ) ;
F_5 ( V_2 , V_7 * 1000 ) ;
if ( V_7 < V_6 )
V_12 . V_13 = F_4 (
V_11 , V_10 , V_7 ) ;
return 0 ;
}
static int F_6 ( struct V_3 * V_4 )
{
unsigned int V_9 , V_14 , V_15 ;
int V_16 , V_17 , V_18 ;
if ( V_4 -> V_1 != 0 )
return - V_19 ;
V_2 = F_7 ( NULL , L_1 ) ;
if ( F_8 ( V_2 ) ) {
F_9 ( L_2 ) ;
V_16 = F_10 ( V_2 ) ;
goto V_20;
}
V_15 = ( F_11 ( V_2 , 1 ) + 500 ) / 1000 ;
V_9 = ( F_11 ( V_2 , ~ 0UL ) + 500 ) / 1000 ;
V_4 -> V_21 . V_22 = 0 ;
V_17 = F_12 ( V_9 / V_15 ) + 1 ;
V_8 = F_13 ( V_17 * sizeof( struct V_23 ) ,
V_24 ) ;
if ( ! V_8 ) {
V_16 = - V_25 ;
goto V_26;
}
for ( V_18 = 0 ; V_18 < ( V_17 - 1 ) ; V_18 ++ ) {
V_14 = F_11 ( V_2 , V_9 * 1000 ) / 1000 ;
if ( V_14 != V_9 )
V_8 [ V_18 ] . V_9 = V_27 ;
else
V_8 [ V_18 ] . V_9 = V_9 ;
V_9 /= 2 ;
}
V_8 [ V_17 - 1 ] . V_9 = V_28 ;
V_16 = F_14 ( V_4 , V_8 ) ;
if ( ! V_16 ) {
F_15 ( L_3 ) ;
return 0 ;
}
F_16 ( V_8 ) ;
V_26:
F_17 ( V_2 ) ;
V_20:
return V_16 ;
}
static int T_1 F_18 ( void )
{
return F_19 ( & V_29 ) ;
}
