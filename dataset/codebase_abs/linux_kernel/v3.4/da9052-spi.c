static int T_1 F_1 ( struct V_1 * V_2 )
{
int V_3 ;
const struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_6 * V_6 = F_3 ( sizeof( struct V_6 ) , V_7 ) ;
if ( ! V_6 )
return - V_8 ;
V_2 -> V_9 = V_10 | V_11 ;
V_2 -> V_12 = 8 ;
F_4 ( V_2 ) ;
V_6 -> V_13 = & V_2 -> V_13 ;
V_6 -> V_14 = V_2 -> V_15 ;
F_5 ( & V_2 -> V_13 , V_6 ) ;
V_16 . V_17 = 1 ;
V_16 . V_18 = 0 ;
V_6 -> V_19 = F_6 ( V_2 , & V_16 ) ;
if ( F_7 ( V_6 -> V_19 ) ) {
V_3 = F_8 ( V_6 -> V_19 ) ;
F_9 ( & V_2 -> V_13 , L_1 ,
V_3 ) ;
goto V_20;
}
V_3 = F_10 ( V_6 , V_5 -> V_21 ) ;
if ( V_3 != 0 )
goto V_22;
return 0 ;
V_22:
F_11 ( V_6 -> V_19 ) ;
V_20:
F_12 ( V_6 ) ;
return V_3 ;
}
static int T_2 F_13 ( struct V_1 * V_2 )
{
struct V_6 * V_6 = F_14 ( & V_2 -> V_13 ) ;
F_15 ( V_6 ) ;
F_11 ( V_6 -> V_19 ) ;
F_12 ( V_6 ) ;
return 0 ;
}
static int T_3 F_16 ( void )
{
int V_3 ;
V_3 = F_17 ( & V_23 ) ;
if ( V_3 != 0 ) {
F_18 ( L_2 , V_3 ) ;
return V_3 ;
}
return 0 ;
}
static void T_4 F_19 ( void )
{
F_20 ( & V_23 ) ;
}
