static int F_1 ( struct V_1 * V_1 )
{
V_1 -> V_2 . V_3 = F_2 ( sizeof( struct V_4 ) , V_5 ) ;
if ( V_1 -> V_2 . V_3 == NULL )
return - V_6 ;
memcpy ( V_1 -> V_2 . V_3 , & V_7 , sizeof( V_7 ) ) ;
if ( F_3 ( V_1 , V_1 -> V_2 . V_3 ) < 0 )
goto V_8;
return 0 ;
V_8:
F_4 ( V_1 -> V_2 . V_3 ) ;
return - V_6 ;
}
static void F_5 ( struct V_1 * V_1 )
{
F_6 ( V_1 -> V_2 . V_3 ) ;
F_4 ( V_1 -> V_2 . V_3 ) ;
}
static unsigned int
F_7 ( const struct V_9 * V_10 ,
struct V_11 * V_12 ,
const struct V_13 * V_14 ,
const struct V_13 * V_15 ,
int (* F_8)( struct V_11 * ) )
{
struct V_16 V_17 ;
F_9 ( & V_17 , V_10 , V_12 , V_14 , V_15 ) ;
return F_10 ( & V_17 , V_10 ) ;
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
