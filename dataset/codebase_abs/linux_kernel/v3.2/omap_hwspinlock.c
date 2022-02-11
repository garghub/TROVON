static int F_1 ( struct V_1 * V_2 )
{
void T_1 * V_3 = V_2 -> V_4 ;
return ( V_5 == F_2 ( V_3 ) ) ;
}
static void F_3 ( struct V_1 * V_2 )
{
void T_1 * V_3 = V_2 -> V_4 ;
F_4 ( V_5 , V_3 ) ;
}
static void F_5 ( struct V_1 * V_2 )
{
F_6 ( 50 ) ;
}
static int T_2 F_7 ( struct V_6 * V_7 )
{
struct V_8 * V_9 = V_7 -> V_10 . V_11 ;
struct V_12 * V_13 ;
struct V_1 * V_14 ;
struct V_15 * V_16 ;
void T_1 * V_17 ;
int V_18 , V_19 , V_20 ;
if ( ! V_9 )
return - V_21 ;
V_16 = F_8 ( V_7 , V_22 , 0 ) ;
if ( ! V_16 )
return - V_21 ;
V_17 = F_9 ( V_16 -> V_23 , F_10 ( V_16 ) ) ;
if ( ! V_17 )
return - V_24 ;
V_19 = F_2 ( V_17 + V_25 ) ;
V_19 >>= V_26 ;
if ( F_11 ( V_19 & 0xf ) != 1 || V_19 > 8 ) {
V_20 = - V_27 ;
goto V_28;
}
V_18 = V_19 * 32 ;
V_13 = F_12 ( sizeof( * V_13 ) + V_18 * sizeof( * V_14 ) , V_29 ) ;
if ( ! V_13 ) {
V_20 = - V_24 ;
goto V_28;
}
F_13 ( V_7 , V_13 ) ;
for ( V_19 = 0 , V_14 = & V_13 -> V_2 [ 0 ] ; V_19 < V_18 ; V_19 ++ , V_14 ++ )
V_14 -> V_4 = V_17 + V_30 + sizeof( V_31 ) * V_19 ;
F_14 ( & V_7 -> V_10 ) ;
V_20 = F_15 ( V_13 , & V_7 -> V_10 , & V_32 ,
V_9 -> V_33 , V_18 ) ;
if ( V_20 )
goto V_34;
return 0 ;
V_34:
F_16 ( & V_7 -> V_10 ) ;
F_17 ( V_13 ) ;
V_28:
F_18 ( V_17 ) ;
return V_20 ;
}
static int T_3 F_19 ( struct V_6 * V_7 )
{
struct V_12 * V_13 = F_20 ( V_7 ) ;
void T_1 * V_17 = V_13 -> V_2 [ 0 ] . V_4 - V_30 ;
int V_20 ;
V_20 = F_21 ( V_13 ) ;
if ( V_20 ) {
F_22 ( & V_7 -> V_10 , L_1 , V_35 , V_20 ) ;
return V_20 ;
}
F_16 ( & V_7 -> V_10 ) ;
F_18 ( V_17 ) ;
F_17 ( V_13 ) ;
return 0 ;
}
static int T_4 F_23 ( void )
{
return F_24 ( & V_36 ) ;
}
static void T_5 F_25 ( void )
{
F_26 ( & V_36 ) ;
}
