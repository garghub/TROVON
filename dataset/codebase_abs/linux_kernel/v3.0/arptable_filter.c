static unsigned int
F_1 ( unsigned int V_1 , struct V_2 * V_3 ,
const struct V_4 * V_5 , const struct V_4 * V_6 ,
int (* F_2)( struct V_2 * ) )
{
const struct V_7 * V_7 = F_3 ( ( V_5 != NULL ) ? V_5 : V_6 ) ;
return F_4 ( V_3 , V_1 , V_5 , V_6 , V_7 -> V_8 . V_9 ) ;
}
static int T_1 F_5 ( struct V_7 * V_7 )
{
struct V_10 * V_11 ;
V_11 = F_6 ( & V_12 ) ;
if ( V_11 == NULL )
return - V_13 ;
V_7 -> V_8 . V_9 =
F_7 ( V_7 , & V_12 , V_11 ) ;
F_8 ( V_11 ) ;
if ( F_9 ( V_7 -> V_8 . V_9 ) )
return F_10 ( V_7 -> V_8 . V_9 ) ;
return 0 ;
}
static void T_2 F_11 ( struct V_7 * V_7 )
{
F_12 ( V_7 -> V_8 . V_9 ) ;
}
static int T_3 F_13 ( void )
{
int V_14 ;
V_14 = F_14 ( & V_15 ) ;
if ( V_14 < 0 )
return V_14 ;
V_16 = F_15 ( & V_12 , F_1 ) ;
if ( F_9 ( V_16 ) ) {
V_14 = F_10 ( V_16 ) ;
goto V_17;
}
return V_14 ;
V_17:
F_16 ( & V_15 ) ;
return V_14 ;
}
static void T_4 F_17 ( void )
{
F_18 ( & V_12 , V_16 ) ;
F_16 ( & V_15 ) ;
}
