static int F_1 ( struct V_1 * V_2 )
{
void T_1 * V_3 = V_4 + V_5 ;
F_2 ( V_6 , V_3 ) ;
F_3 ( V_3 ) ;
return 0 ;
}
static int F_4 ( struct V_1 * V_2 )
{
void T_1 * V_3 = V_4 + V_5 ;
V_6 = F_3 ( V_3 ) ;
return 0 ;
}
static int F_5 ( const struct V_1 * V_2 , int clock )
{
int V_7 ;
int V_8 = 0 ;
int V_9 ;
int V_10 ;
V_9 = clock - V_11 [ 0 ] ;
V_9 = ( V_9 < 0 ) ? - V_9 : V_9 ;
for ( V_7 = 1 ; V_7 < V_12 ; ++ V_7 ) {
V_10 = clock - V_11 [ V_7 ] ;
V_10 = ( V_10 < 0 ) ? - V_10 : V_10 ;
if ( V_10 < V_9 ) {
V_8 = V_7 ;
V_9 = V_10 ;
}
}
return V_8 ;
}
static int F_6 ( const struct V_1 * V_2 , int clock )
{
return V_11 [ F_5 ( V_2 , clock ) ] ;
}
static int F_7 ( struct V_1 * V_2 , int clock )
{
void T_1 * V_3 = V_4 + V_5 ;
int V_13 ;
T_2 V_14 ;
V_13 = F_5 ( V_2 , clock ) ;
if ( V_11 [ V_13 ] != clock )
return - V_15 ;
V_14 = F_3 ( V_3 ) & ~ V_16 ;
V_14 = V_17 [ V_13 ] << V_18 ;
F_2 ( V_14 , V_3 ) ;
F_3 ( V_3 ) ;
return 0 ;
}
static int T_3 F_8 ( void )
{
int V_19 ;
T_2 V_20 ;
V_21 = F_9 ( V_22 ,
V_23 , NULL ) ;
if ( ! V_21 ) {
F_10 ( V_24
L_1 ) ;
return - V_25 ;
}
F_11 ( V_21 , V_26 , & V_20 ) ;
if ( ! ( V_20 & V_27 ) ) {
F_10 ( V_24
L_2 ) ;
F_12 ( V_21 ) ;
return - V_25 ;
}
F_11 ( V_21 , V_28 ,
& V_29 ) ;
V_4 =
F_13 ( V_29 , V_30 ) ;
if ( ! V_4 ) {
F_10 ( V_24
L_2 ) ;
F_12 ( V_21 ) ;
return - V_25 ;
}
V_19 = F_14 ( & V_31 ) ;
if ( V_19 ) {
F_10 ( V_24
L_3 ) ;
F_15 ( V_4 ) ;
F_12 ( V_21 ) ;
return V_19 ;
}
return 0 ;
}
static void T_4 F_16 ( void )
{
F_17 ( & V_31 ) ;
F_15 ( V_4 ) ;
F_12 ( V_21 ) ;
}
