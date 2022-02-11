static int F_1 ( struct V_1 * V_2 ,
unsigned long V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
int V_6 = V_3 >> 8 ;
int V_7 = F_3 ( V_3 & 0x1f ) ;
F_4 ( V_7 , V_5 -> V_8 + V_6 ) ;
F_5 ( 10 ) ;
return 0 ;
}
static int F_6 ( struct V_1 * V_2 ,
const struct V_9 * V_10 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
unsigned V_6 , V_11 ;
if ( F_7 ( V_10 -> V_12 != V_2 -> V_13 ) )
return - V_14 ;
V_6 = V_10 -> args [ 0 ] ;
V_11 = V_10 -> args [ 1 ] ;
if ( V_6 >= V_5 -> V_15 )
return - V_14 ;
if ( V_11 >= V_16 )
return - V_14 ;
return ( V_6 << 8 ) | V_11 ;
}
static int F_8 ( struct V_17 * V_18 )
{
struct V_4 * V_5 ;
struct V_19 V_20 ;
T_1 V_15 ;
int V_21 ;
V_5 = F_9 ( sizeof( * V_5 ) , V_22 ) ;
if ( ! V_5 )
return - V_23 ;
V_21 = F_10 ( V_18 , 0 , & V_20 ) ;
if ( V_21 )
goto V_24;
V_15 = F_11 ( & V_20 ) ;
V_5 -> V_8 = F_12 ( V_20 . V_25 , V_15 ) ;
if ( ! V_5 -> V_8 ) {
V_21 = - V_23 ;
goto V_24;
}
V_5 -> V_15 = V_15 ;
V_5 -> V_2 . V_26 = V_27 ;
V_5 -> V_2 . V_28 = & V_29 ;
V_5 -> V_2 . V_30 = V_18 ;
V_5 -> V_2 . V_13 = 2 ;
V_5 -> V_2 . V_31 = F_6 ;
F_13 ( & V_5 -> V_2 ) ;
return 0 ;
V_24:
F_14 ( V_5 ) ;
return V_21 ;
}
static int T_2 F_15 ( void )
{
struct V_17 * V_18 ;
int V_21 ;
F_16 (np, berlin_reset_of_match) {
V_21 = F_8 ( V_18 ) ;
if ( V_21 )
return V_21 ;
}
return 0 ;
}
