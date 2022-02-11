static unsigned int
F_1 ( const struct V_1 * V_2 ,
struct V_3 * V_4 ,
const struct V_5 * V_6 ,
const struct V_5 * V_7 ,
int (* F_2)( struct V_3 * ) )
{
struct V_8 V_9 ;
F_3 ( & V_9 , V_2 , V_4 , V_6 , V_7 ) ;
return F_4 ( & V_9 , V_2 ) ;
}
static int F_5 ( struct V_10 * V_10 )
{
V_10 -> V_11 . V_12 = F_6 ( sizeof( struct V_13 ) , V_14 ) ;
if ( V_10 -> V_11 . V_12 == NULL )
return - V_15 ;
memcpy ( V_10 -> V_11 . V_12 , & V_16 , sizeof( V_16 ) ) ;
if ( F_7 ( V_10 , V_10 -> V_11 . V_12 ) < 0 )
goto V_17;
return 0 ;
V_17:
F_8 ( V_10 -> V_11 . V_12 ) ;
return - V_15 ;
}
static void F_9 ( struct V_10 * V_10 )
{
F_10 ( V_10 -> V_11 . V_12 ) ;
F_8 ( V_10 -> V_11 . V_12 ) ;
}
static int T_1 F_11 ( void )
{
int V_18 ;
F_12 ( & V_19 ) ;
V_18 = F_13 ( & V_20 ) ;
if ( V_18 < 0 )
F_14 ( & V_19 ) ;
return V_18 ;
}
static void T_2 F_15 ( void )
{
F_16 ( & V_20 ) ;
F_14 ( & V_19 ) ;
}
