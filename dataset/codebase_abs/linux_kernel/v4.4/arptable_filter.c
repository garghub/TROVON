static unsigned int
F_1 ( void * V_1 , struct V_2 * V_3 ,
const struct V_4 * V_5 )
{
return F_2 ( V_3 , V_5 , V_5 -> V_6 -> V_7 . V_8 ) ;
}
static int T_1 F_3 ( struct V_6 * V_6 )
{
struct V_9 * V_10 ;
V_10 = F_4 ( & V_11 ) ;
if ( V_10 == NULL )
return - V_12 ;
V_6 -> V_7 . V_8 =
F_5 ( V_6 , & V_11 , V_10 ) ;
F_6 ( V_10 ) ;
return F_7 ( V_6 -> V_7 . V_8 ) ;
}
static void T_2 F_8 ( struct V_6 * V_6 )
{
F_9 ( V_6 -> V_7 . V_8 ) ;
}
static int T_3 F_10 ( void )
{
int V_13 ;
V_13 = F_11 ( & V_14 ) ;
if ( V_13 < 0 )
return V_13 ;
V_15 = F_12 ( & V_11 , F_1 ) ;
if ( F_13 ( V_15 ) ) {
V_13 = F_14 ( V_15 ) ;
goto V_16;
}
return V_13 ;
V_16:
F_15 ( & V_14 ) ;
return V_13 ;
}
static void T_4 F_16 ( void )
{
F_17 ( & V_11 , V_15 ) ;
F_15 ( & V_14 ) ;
}
