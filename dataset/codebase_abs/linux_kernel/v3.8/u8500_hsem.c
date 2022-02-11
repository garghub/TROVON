static int F_1 ( struct V_1 * V_2 )
{
void T_1 * V_3 = V_2 -> V_4 ;
F_2 ( V_5 , V_3 ) ;
return ( V_5 == ( 0x0F & F_3 ( V_3 ) ) ) ;
}
static void F_4 ( struct V_1 * V_2 )
{
void T_1 * V_3 = V_2 -> V_4 ;
F_2 ( V_6 , V_3 ) ;
}
static void F_5 ( struct V_1 * V_2 )
{
F_6 ( 50 ) ;
}
static int F_7 ( struct V_7 * V_8 )
{
struct V_9 * V_10 = V_8 -> V_11 . V_12 ;
struct V_13 * V_14 ;
struct V_1 * V_15 ;
struct V_16 * V_17 ;
void T_1 * V_18 ;
int V_19 , V_20 , V_21 = V_22 ;
T_2 V_23 ;
if ( ! V_10 )
return - V_24 ;
V_17 = F_8 ( V_8 , V_25 , 0 ) ;
if ( ! V_17 )
return - V_24 ;
V_18 = F_9 ( V_17 -> V_26 , F_10 ( V_17 ) ) ;
if ( ! V_18 )
return - V_27 ;
V_23 = F_3 ( V_18 + V_28 ) ;
F_2 ( ( V_23 & ~ V_29 ) , V_18 + V_28 ) ;
F_2 ( 0xFFFF , V_18 + V_30 ) ;
V_14 = F_11 ( sizeof( * V_14 ) + V_21 * sizeof( * V_15 ) , V_31 ) ;
if ( ! V_14 ) {
V_20 = - V_27 ;
goto V_32;
}
F_12 ( V_8 , V_14 ) ;
for ( V_19 = 0 , V_15 = & V_14 -> V_2 [ 0 ] ; V_19 < V_21 ; V_19 ++ , V_15 ++ )
V_15 -> V_4 = V_18 + V_33 + sizeof( V_34 ) * V_19 ;
F_13 ( & V_8 -> V_11 ) ;
V_20 = F_14 ( V_14 , & V_8 -> V_11 , & V_35 ,
V_10 -> V_36 , V_21 ) ;
if ( V_20 )
goto V_37;
return 0 ;
V_37:
F_15 ( & V_8 -> V_11 ) ;
F_16 ( V_14 ) ;
V_32:
F_17 ( V_18 ) ;
return V_20 ;
}
static int F_18 ( struct V_7 * V_8 )
{
struct V_13 * V_14 = F_19 ( V_8 ) ;
void T_1 * V_18 = V_14 -> V_2 [ 0 ] . V_4 - V_33 ;
int V_20 ;
F_2 ( 0xFFFF , V_18 + V_30 ) ;
V_20 = F_20 ( V_14 ) ;
if ( V_20 ) {
F_21 ( & V_8 -> V_11 , L_1 , V_38 , V_20 ) ;
return V_20 ;
}
F_15 ( & V_8 -> V_11 ) ;
F_17 ( V_18 ) ;
F_16 ( V_14 ) ;
return 0 ;
}
static int T_3 F_22 ( void )
{
return F_23 ( & V_39 ) ;
}
static void T_4 F_24 ( void )
{
F_25 ( & V_39 ) ;
}
