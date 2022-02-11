static unsigned int
F_1 ( void * V_1 , struct V_2 * V_3 ,
const struct V_4 * V_5 )
{
if ( V_5 -> V_6 == V_7 &&
( V_3 -> V_8 < sizeof( struct V_9 ) ||
F_2 ( V_3 ) < sizeof( struct V_9 ) ) )
return V_10 ;
return F_3 ( V_3 , V_5 , V_5 -> V_11 -> V_12 . V_13 ) ;
}
static int T_1 F_4 ( struct V_11 * V_11 )
{
struct V_14 * V_15 ;
V_15 = F_5 ( & V_16 ) ;
if ( V_15 == NULL )
return - V_17 ;
V_11 -> V_12 . V_13 =
F_6 ( V_11 , & V_16 , V_15 ) ;
F_7 ( V_15 ) ;
return F_8 ( V_11 -> V_12 . V_13 ) ;
}
static void T_2 F_9 ( struct V_11 * V_11 )
{
F_10 ( V_11 , V_11 -> V_12 . V_13 ) ;
}
static int T_3 F_11 ( void )
{
int V_18 ;
V_18 = F_12 ( & V_19 ) ;
if ( V_18 < 0 )
return V_18 ;
V_20 = F_13 ( & V_16 , F_1 ) ;
if ( F_14 ( V_20 ) ) {
V_18 = F_15 ( V_20 ) ;
F_16 ( & V_19 ) ;
}
return V_18 ;
}
static void T_4 F_17 ( void )
{
F_18 ( & V_16 , V_20 ) ;
F_16 ( & V_19 ) ;
}
