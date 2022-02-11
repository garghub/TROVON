static int F_1 ( struct V_1 * V_2 , unsigned int V_3 )
{
unsigned int V_4 , V_5 ;
V_4 = V_2 -> V_6 ;
V_5 = V_7 [ V_3 ] . V_8 ;
if ( ! V_9 ) {
V_9 = V_4 ;
V_10 = V_11 . V_12 ;
}
if ( V_4 < V_5 )
V_11 . V_12 = F_2 (
V_10 , V_9 , V_5 ) ;
F_3 ( V_2 -> V_13 , V_5 * 1000 ) ;
if ( V_5 < V_4 )
V_11 . V_12 = F_2 (
V_10 , V_9 , V_5 ) ;
return 0 ;
}
static int F_4 ( struct V_1 * V_2 )
{
unsigned int V_8 , V_14 , V_15 ;
struct V_13 * V_16 ;
int V_17 , V_18 , V_19 ;
if ( V_2 -> V_20 != 0 )
return - V_21 ;
V_16 = F_5 ( NULL , L_1 ) ;
if ( F_6 ( V_16 ) ) {
F_7 ( L_2 ) ;
V_17 = F_8 ( V_16 ) ;
goto V_22;
}
V_15 = ( F_9 ( V_16 , 1 ) + 500 ) / 1000 ;
V_8 = ( F_9 ( V_16 , ~ 0UL ) + 500 ) / 1000 ;
V_2 -> V_23 . V_24 = 0 ;
V_18 = F_10 ( V_8 / V_15 ) + 1 ;
V_7 = F_11 ( V_18 * sizeof( struct V_25 ) ,
V_26 ) ;
if ( ! V_7 ) {
V_17 = - V_27 ;
goto V_28;
}
for ( V_19 = 0 ; V_19 < ( V_18 - 1 ) ; V_19 ++ ) {
V_14 = F_9 ( V_16 , V_8 * 1000 ) / 1000 ;
if ( V_14 != V_8 )
V_7 [ V_19 ] . V_8 = V_29 ;
else
V_7 [ V_19 ] . V_8 = V_8 ;
V_8 /= 2 ;
}
V_2 -> V_13 = V_16 ;
V_7 [ V_18 - 1 ] . V_8 = V_30 ;
V_17 = F_12 ( V_2 , V_7 ) ;
if ( ! V_17 ) {
F_13 ( L_3 ) ;
return 0 ;
}
F_14 ( V_7 ) ;
V_28:
F_15 ( V_16 ) ;
V_22:
return V_17 ;
}
static int T_1 F_16 ( void )
{
return F_17 ( & V_31 ) ;
}
