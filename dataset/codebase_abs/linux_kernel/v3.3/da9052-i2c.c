static int F_1 ( struct V_1 * V_1 )
{
int V_2 , V_3 ;
V_3 = F_2 ( V_1 -> V_4 , V_5 , & V_2 ) ;
if ( V_3 < 0 )
return V_3 ;
if ( V_2 & V_6 ) {
V_2 &= ~ V_6 ;
V_3 = F_3 ( V_1 -> V_4 , V_5 ,
V_2 ) ;
if ( V_3 < 0 )
return V_3 ;
}
return 0 ;
}
static int T_1 F_4 ( struct V_7 * V_8 ,
const struct V_9 * V_10 )
{
struct V_1 * V_1 ;
int V_3 ;
V_1 = F_5 ( sizeof( struct V_1 ) , V_11 ) ;
if ( ! V_1 )
return - V_12 ;
if ( ! F_6 ( V_8 -> V_13 ,
V_14 ) ) {
F_7 ( & V_8 -> V_15 , L_1 ,
V_16 ) ;
V_3 = - V_17 ;
goto V_18;
}
V_1 -> V_15 = & V_8 -> V_15 ;
V_1 -> V_19 = V_8 -> V_20 ;
F_8 ( V_8 , V_1 ) ;
V_1 -> V_4 = F_9 ( V_8 , & V_21 ) ;
if ( F_10 ( V_1 -> V_4 ) ) {
V_3 = F_11 ( V_1 -> V_4 ) ;
F_12 ( & V_8 -> V_15 , L_2 ,
V_3 ) ;
goto V_18;
}
V_3 = F_1 ( V_1 ) ;
if ( V_3 < 0 )
goto V_18;
V_3 = F_13 ( V_1 , V_10 -> V_22 ) ;
if ( V_3 != 0 )
goto V_18;
return 0 ;
V_18:
F_14 ( V_1 ) ;
return V_3 ;
}
static int F_15 ( struct V_7 * V_8 )
{
struct V_1 * V_1 = F_16 ( V_8 ) ;
F_17 ( V_1 ) ;
F_14 ( V_1 ) ;
return 0 ;
}
static int T_2 F_18 ( void )
{
int V_3 ;
V_3 = F_19 ( & V_23 ) ;
if ( V_3 != 0 ) {
F_20 ( L_3 , V_3 ) ;
return V_3 ;
}
return 0 ;
}
static void T_3 F_21 ( void )
{
F_22 ( & V_23 ) ;
}
