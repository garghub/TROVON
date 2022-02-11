static unsigned int
F_1 ( unsigned int V_1 , struct V_2 * V_3 ,
const struct V_4 * V_5 , const struct V_4 * V_6 ,
int (* F_2)( struct V_2 * ) )
{
const struct V_7 * V_7 ;
if ( V_1 == V_8 &&
( V_3 -> V_9 < sizeof( struct V_10 ) ||
F_3 ( V_3 ) < sizeof( struct V_10 ) ) )
return V_11 ;
V_7 = F_4 ( ( V_5 != NULL ) ? V_5 : V_6 ) ;
return F_5 ( V_3 , V_1 , V_5 , V_6 , V_7 -> V_12 . V_13 ) ;
}
static int T_1 F_6 ( struct V_7 * V_7 )
{
struct V_14 * V_15 ;
V_15 = F_7 ( & V_16 ) ;
if ( V_15 == NULL )
return - V_17 ;
V_7 -> V_12 . V_13 =
F_8 ( V_7 , & V_16 , V_15 ) ;
F_9 ( V_15 ) ;
return F_10 ( V_7 -> V_12 . V_13 ) ;
}
static void T_2 F_11 ( struct V_7 * V_7 )
{
F_12 ( V_7 , V_7 -> V_12 . V_13 ) ;
}
static int T_3 F_13 ( void )
{
int V_18 ;
V_18 = F_14 ( & V_19 ) ;
if ( V_18 < 0 )
return V_18 ;
V_20 = F_15 ( & V_16 , F_1 ) ;
if ( F_16 ( V_20 ) ) {
V_18 = F_17 ( V_20 ) ;
F_18 ( & V_19 ) ;
}
return V_18 ;
}
static void T_4 F_19 ( void )
{
F_20 ( & V_16 , V_20 ) ;
F_18 ( & V_19 ) ;
}
