static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
struct V_5 * V_6 ;
int V_7 ;
V_4 = F_2 ( sizeof( struct V_3 ) , V_8 ) ;
if ( ! V_4 )
return - V_9 ;
V_6 = F_3 ( V_2 , V_10 , 0 ) ;
if ( ! V_6 ) {
V_7 = - V_11 ;
goto V_12;
}
V_4 -> V_13 = F_4 ( V_2 , 0 ) ;
if ( V_4 -> V_13 < 0 ) {
V_7 = V_4 -> V_13 ;
goto V_12;
}
V_4 -> V_14 = V_2 -> V_14 ;
V_4 -> V_15 = 0 ;
V_4 -> V_16 = V_2 -> V_14 . V_17 ;
V_7 = - V_9 ;
V_4 -> V_6 = F_5 ( V_6 -> V_18 , F_6 ( V_6 ) ) ;
if ( ! V_4 -> V_6 )
goto V_12;
F_7 ( V_2 , V_4 ) ;
V_7 = F_8 ( V_4 ) ;
if ( V_7 )
goto V_19;
return V_7 ;
V_19:
F_9 ( V_4 -> V_6 ) ;
V_12:
F_10 ( V_4 ) ;
return V_7 ;
}
static int T_1 F_11 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_12 ( V_2 ) ;
F_7 ( V_2 , NULL ) ;
F_13 ( V_4 ) ;
F_9 ( V_4 -> V_6 ) ;
F_10 ( V_4 ) ;
return 0 ;
}
static int F_14 ( struct V_20 * V_14 )
{
int V_7 ;
struct V_3 * V_4 = F_15 ( V_14 ) ;
V_7 = F_16 ( V_4 ) ;
if ( V_7 )
return V_7 ;
return 0 ;
}
static int F_17 ( struct V_20 * V_14 )
{
int V_7 ;
struct V_3 * V_4 = F_15 ( V_14 ) ;
V_7 = F_18 ( V_4 ) ;
if ( V_7 )
return V_7 ;
return 0 ;
}
static int T_2 F_19 ( void )
{
return F_20 ( & V_21 , F_1 ) ;
}
static void T_1 F_21 ( void )
{
F_22 ( & V_21 ) ;
}
