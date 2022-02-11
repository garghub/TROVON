static unsigned int
F_1 ( const struct V_1 * V_2 , struct V_3 * V_4 ,
const struct V_5 * V_6 , const struct V_5 * V_7 ,
int (* F_2)( struct V_3 * ) )
{
const struct V_8 * V_8 = F_3 ( ( V_6 != NULL ) ? V_6 : V_7 ) ;
return F_4 ( V_4 , V_2 -> V_9 , V_6 , V_7 ,
V_8 -> V_10 . V_11 ) ;
}
static int T_1 F_5 ( struct V_8 * V_8 )
{
struct V_12 * V_13 ;
V_13 = F_6 ( & V_14 ) ;
if ( V_13 == NULL )
return - V_15 ;
( (struct V_16 * ) V_13 -> V_17 ) [ 1 ] . V_18 . V_19 =
V_20 ? - V_21 - 1 : - V_22 - 1 ;
V_8 -> V_10 . V_11 =
F_7 ( V_8 , & V_14 , V_13 ) ;
F_8 ( V_13 ) ;
return F_9 ( V_8 -> V_10 . V_11 ) ;
}
static void T_2 F_10 ( struct V_8 * V_8 )
{
F_11 ( V_8 , V_8 -> V_10 . V_11 ) ;
}
static int T_3 F_12 ( void )
{
int V_23 ;
V_23 = F_13 ( & V_24 ) ;
if ( V_23 < 0 )
return V_23 ;
V_25 = F_14 ( & V_14 , F_1 ) ;
if ( F_15 ( V_25 ) ) {
V_23 = F_16 ( V_25 ) ;
goto V_26;
}
return V_23 ;
V_26:
F_17 ( & V_24 ) ;
return V_23 ;
}
static void T_4 F_18 ( void )
{
F_19 ( & V_14 , V_25 ) ;
F_17 ( & V_24 ) ;
}
