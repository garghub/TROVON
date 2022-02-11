static unsigned int
F_1 ( void * V_1 ,
struct V_2 * V_3 ,
const struct V_4 * V_5 )
{
struct V_6 V_7 ;
F_2 ( & V_7 , V_3 , V_5 ) ;
return F_3 ( & V_7 , V_1 ) ;
}
static int F_4 ( struct V_8 * V_8 )
{
V_8 -> V_9 . V_10 = F_5 ( sizeof( struct V_11 ) , V_12 ) ;
if ( V_8 -> V_9 . V_10 == NULL )
return - V_13 ;
memcpy ( V_8 -> V_9 . V_10 , & V_14 , sizeof( V_14 ) ) ;
if ( F_6 ( V_8 , V_8 -> V_9 . V_10 ) < 0 )
goto V_15;
return 0 ;
V_15:
F_7 ( V_8 -> V_9 . V_10 ) ;
return - V_13 ;
}
static void F_8 ( struct V_8 * V_8 )
{
F_9 ( V_8 , V_8 -> V_9 . V_10 ) ;
F_7 ( V_8 -> V_9 . V_10 ) ;
}
static int T_1 F_10 ( void )
{
int V_16 ;
V_16 = F_11 ( & V_17 ) ;
if ( V_16 < 0 )
return V_16 ;
V_16 = F_12 ( & V_18 ) ;
if ( V_16 < 0 )
F_13 ( & V_17 ) ;
return V_16 ;
}
static void T_2 F_14 ( void )
{
F_15 ( & V_18 ) ;
F_13 ( & V_17 ) ;
}
