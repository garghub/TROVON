static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_6 * V_7 = V_4 -> V_7 ;
struct V_6 * V_8 = V_4 -> V_8 ;
int V_9 ;
F_2 ( V_7 , V_10 ,
12000000 , V_11 ) ;
V_9 = F_3 ( V_7 , V_12 |
V_13 | V_14 ) ;
if ( V_9 < 0 )
goto V_15;
V_9 = F_3 ( V_8 , V_12 |
V_13 | V_14 ) ;
if ( V_9 < 0 )
goto V_15;
V_9 = 0 ;
V_15:
return V_9 ;
}
static int T_1 F_4 ( struct V_16 * V_17 )
{
const struct V_18 * V_19 = F_5 ( V_17 ) ;
struct V_20 * V_21 ;
V_21 = V_22 [ V_19 -> V_23 ] ;
V_21 -> V_24 = & V_17 -> V_24 ;
return F_6 ( V_21 ) ;
}
static int T_2 F_7 ( struct V_16 * V_17 )
{
struct V_20 * V_21 = F_8 ( V_17 ) ;
F_9 ( V_21 ) ;
return 0 ;
}
static int T_3 F_10 ( void )
{
return F_11 ( & V_25 ) ;
}
static void T_4 F_12 ( void )
{
F_13 ( & V_25 ) ;
}
