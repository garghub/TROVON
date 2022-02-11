static unsigned int
F_1 ( const struct V_1 * V_2 , struct V_3 * V_4 ,
const struct V_5 * V_6 )
{
const struct V_7 * V_7 = F_2 ( V_6 -> V_8 ? V_6 -> V_8 : V_6 -> V_9 ) ;
return F_3 ( V_4 , V_2 -> V_10 , V_6 ,
V_7 -> V_11 . V_12 ) ;
}
static int T_1 F_4 ( struct V_7 * V_7 )
{
struct V_13 * V_14 ;
V_14 = F_5 ( & V_15 ) ;
if ( V_14 == NULL )
return - V_16 ;
V_7 -> V_11 . V_12 =
F_6 ( V_7 , & V_15 , V_14 ) ;
F_7 ( V_14 ) ;
return F_8 ( V_7 -> V_11 . V_12 ) ;
}
static void T_2 F_9 ( struct V_7 * V_7 )
{
F_10 ( V_7 -> V_11 . V_12 ) ;
}
static int T_3 F_11 ( void )
{
int V_17 ;
V_17 = F_12 ( & V_18 ) ;
if ( V_17 < 0 )
return V_17 ;
V_19 = F_13 ( & V_15 , F_1 ) ;
if ( F_14 ( V_19 ) ) {
V_17 = F_15 ( V_19 ) ;
goto V_20;
}
return V_17 ;
V_20:
F_16 ( & V_18 ) ;
return V_17 ;
}
static void T_4 F_17 ( void )
{
F_18 ( & V_15 , V_19 ) ;
F_16 ( & V_18 ) ;
}
