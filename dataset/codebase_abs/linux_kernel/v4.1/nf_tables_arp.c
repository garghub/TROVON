static unsigned int
F_1 ( const struct V_1 * V_2 ,
struct V_3 * V_4 ,
const struct V_5 * V_6 )
{
struct V_7 V_8 ;
F_2 ( & V_8 , V_2 , V_4 , V_6 ) ;
return F_3 ( & V_8 , V_2 ) ;
}
static int F_4 ( struct V_9 * V_9 )
{
V_9 -> V_10 . V_11 = F_5 ( sizeof( struct V_12 ) , V_13 ) ;
if ( V_9 -> V_10 . V_11 == NULL )
return - V_14 ;
memcpy ( V_9 -> V_10 . V_11 , & V_15 , sizeof( V_15 ) ) ;
if ( F_6 ( V_9 , V_9 -> V_10 . V_11 ) < 0 )
goto V_16;
return 0 ;
V_16:
F_7 ( V_9 -> V_10 . V_11 ) ;
return - V_14 ;
}
static void F_8 ( struct V_9 * V_9 )
{
F_9 ( V_9 -> V_10 . V_11 ) ;
F_7 ( V_9 -> V_10 . V_11 ) ;
}
static int T_1 F_10 ( void )
{
int V_17 ;
F_11 ( & V_18 ) ;
V_17 = F_12 ( & V_19 ) ;
if ( V_17 < 0 )
F_13 ( & V_18 ) ;
return V_17 ;
}
static void T_2 F_14 ( void )
{
F_15 ( & V_19 ) ;
F_13 ( & V_18 ) ;
}
