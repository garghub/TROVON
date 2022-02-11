static unsigned int
F_1 ( const struct V_1 * V_2 , struct V_3 * V_4 ,
const struct V_5 * V_6 )
{
const struct V_7 * V_7 ;
if ( V_2 -> V_8 == V_9 &&
( V_4 -> V_10 < sizeof( struct V_11 ) ||
F_2 ( V_4 ) < sizeof( struct V_11 ) ) )
return V_12 ;
V_7 = F_3 ( V_6 -> V_13 ? V_6 -> V_13 : V_6 -> V_14 ) ;
return F_4 ( V_4 , V_2 -> V_8 , V_6 , V_7 -> V_15 . V_16 ) ;
}
static int T_1 F_5 ( struct V_7 * V_7 )
{
struct V_17 * V_18 ;
V_18 = F_6 ( & V_19 ) ;
if ( V_18 == NULL )
return - V_20 ;
( (struct V_21 * ) V_18 -> V_22 ) [ 1 ] . V_23 . V_24 =
V_25 ? - V_12 - 1 : - V_26 - 1 ;
V_7 -> V_15 . V_16 =
F_7 ( V_7 , & V_19 , V_18 ) ;
F_8 ( V_18 ) ;
return F_9 ( V_7 -> V_15 . V_16 ) ;
}
static void T_2 F_10 ( struct V_7 * V_7 )
{
F_11 ( V_7 , V_7 -> V_15 . V_16 ) ;
}
static int T_3 F_12 ( void )
{
int V_27 ;
V_27 = F_13 ( & V_28 ) ;
if ( V_27 < 0 )
return V_27 ;
V_29 = F_14 ( & V_19 , F_1 ) ;
if ( F_15 ( V_29 ) ) {
V_27 = F_16 ( V_29 ) ;
F_17 ( & V_28 ) ;
}
return V_27 ;
}
static void T_4 F_18 ( void )
{
F_19 ( & V_19 , V_29 ) ;
F_17 ( & V_28 ) ;
}
