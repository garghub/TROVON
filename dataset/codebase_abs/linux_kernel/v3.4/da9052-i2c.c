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
goto V_22;
V_3 = F_13 ( V_1 , V_10 -> V_23 ) ;
if ( V_3 != 0 )
goto V_22;
return 0 ;
V_22:
F_14 ( V_1 -> V_4 ) ;
V_18:
F_15 ( V_1 ) ;
return V_3 ;
}
static int T_2 F_16 ( struct V_7 * V_8 )
{
struct V_1 * V_1 = F_17 ( V_8 ) ;
F_18 ( V_1 ) ;
F_14 ( V_1 -> V_4 ) ;
F_15 ( V_1 ) ;
return 0 ;
}
static int T_3 F_19 ( void )
{
int V_3 ;
V_3 = F_20 ( & V_24 ) ;
if ( V_3 != 0 ) {
F_21 ( L_3 , V_3 ) ;
return V_3 ;
}
return 0 ;
}
static void T_4 F_22 ( void )
{
F_23 ( & V_24 ) ;
}
