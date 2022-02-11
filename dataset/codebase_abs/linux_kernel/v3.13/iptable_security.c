static unsigned int
F_1 ( const struct V_1 * V_2 , struct V_3 * V_4 ,
const struct V_5 * V_6 ,
const struct V_5 * V_7 ,
int (* F_2)( struct V_3 * ) )
{
const struct V_8 * V_8 ;
if ( V_2 -> V_9 == V_10 &&
( V_4 -> V_11 < sizeof( struct V_12 ) ||
F_3 ( V_4 ) < sizeof( struct V_12 ) ) )
return V_13 ;
V_8 = F_4 ( ( V_6 != NULL ) ? V_6 : V_7 ) ;
return F_5 ( V_4 , V_2 -> V_9 , V_6 , V_7 ,
V_8 -> V_14 . V_15 ) ;
}
static int T_1 F_6 ( struct V_8 * V_8 )
{
struct V_16 * V_17 ;
V_17 = F_7 ( & V_18 ) ;
if ( V_17 == NULL )
return - V_19 ;
V_8 -> V_14 . V_15 =
F_8 ( V_8 , & V_18 , V_17 ) ;
F_9 ( V_17 ) ;
return F_10 ( V_8 -> V_14 . V_15 ) ;
}
static void T_2 F_11 ( struct V_8 * V_8 )
{
F_12 ( V_8 , V_8 -> V_14 . V_15 ) ;
}
static int T_3 F_13 ( void )
{
int V_20 ;
V_20 = F_14 ( & V_21 ) ;
if ( V_20 < 0 )
return V_20 ;
V_22 = F_15 ( & V_18 , F_1 ) ;
if ( F_16 ( V_22 ) ) {
V_20 = F_17 ( V_22 ) ;
goto V_23;
}
return V_20 ;
V_23:
F_18 ( & V_21 ) ;
return V_20 ;
}
static void T_4 F_19 ( void )
{
F_20 ( & V_18 , V_22 ) ;
F_18 ( & V_21 ) ;
}
