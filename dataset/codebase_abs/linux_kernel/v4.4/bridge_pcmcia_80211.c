static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
int V_5 = - V_6 ;
int V_7 = 0 ;
V_4 = F_2 ( sizeof( * V_4 ) , V_8 ) ;
if ( ! V_4 )
goto V_9;
V_5 = - V_10 ;
V_2 -> V_11 |= V_12 ;
V_2 -> V_13 [ 2 ] -> V_14 |= V_15 | V_16 |
V_17 ;
V_2 -> V_13 [ 2 ] -> V_18 = 0 ;
V_2 -> V_13 [ 2 ] -> V_19 = V_20 ;
V_7 = F_3 ( V_2 , V_2 -> V_13 [ 2 ] , 250 ) ;
if ( V_7 != 0 )
goto V_21;
V_7 = F_4 ( V_2 , V_2 -> V_13 [ 2 ] , 0 ) ;
if ( V_7 != 0 )
goto V_22;
if ( ! V_2 -> V_23 )
goto V_22;
V_7 = F_5 ( V_2 ) ;
if ( V_7 != 0 )
goto V_22;
V_5 = F_6 ( V_4 , V_2 , V_2 -> V_13 [ 2 ] -> V_18 ) ;
if ( V_5 )
goto V_22;
V_2 -> V_24 = V_4 ;
return 0 ;
V_22:
F_7 ( V_2 ) ;
V_21:
F_8 ( V_4 ) ;
V_9:
F_9 ( L_1 , V_7 , V_5 ) ;
return V_5 ;
}
static void F_10 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_24 ;
F_11 ( V_4 ) ;
F_7 ( V_2 ) ;
F_8 ( V_4 ) ;
V_2 -> V_24 = NULL ;
}
static int F_12 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_24 ;
return F_13 ( V_4 ) ;
}
static int F_14 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_24 ;
return F_15 ( V_4 ) ;
}
int F_16 ( void )
{
return F_17 ( & V_25 ) ;
}
void F_18 ( void )
{
F_19 ( & V_25 ) ;
}
