static unsigned int
F_1 ( const struct V_1 * V_2 , struct V_3 * V_4 ,
const struct V_5 * V_6 )
{
const struct V_7 * V_7 = F_2 ( V_6 -> V_8 ? V_6 -> V_8 : V_6 -> V_9 ) ;
return F_3 ( V_4 , V_2 -> V_10 , V_6 , V_7 -> V_11 . V_12 ) ;
}
static int T_1 F_4 ( struct V_7 * V_7 )
{
struct V_13 * V_14 ;
V_14 = F_5 ( & V_15 ) ;
if ( V_14 == NULL )
return - V_16 ;
( (struct V_17 * ) V_14 -> V_18 ) [ 1 ] . V_19 . V_20 =
V_21 ? - V_22 - 1 : - V_23 - 1 ;
V_7 -> V_11 . V_12 =
F_6 ( V_7 , & V_15 , V_14 ) ;
F_7 ( V_14 ) ;
return F_8 ( V_7 -> V_11 . V_12 ) ;
}
static void T_2 F_9 ( struct V_7 * V_7 )
{
F_10 ( V_7 , V_7 -> V_11 . V_12 ) ;
}
static int T_3 F_11 ( void )
{
int V_24 ;
V_24 = F_12 ( & V_25 ) ;
if ( V_24 < 0 )
return V_24 ;
V_26 = F_13 ( & V_15 , F_1 ) ;
if ( F_14 ( V_26 ) ) {
V_24 = F_15 ( V_26 ) ;
goto V_27;
}
return V_24 ;
V_27:
F_16 ( & V_25 ) ;
return V_24 ;
}
static void T_4 F_17 ( void )
{
F_18 ( & V_15 , V_26 ) ;
F_16 ( & V_25 ) ;
}
