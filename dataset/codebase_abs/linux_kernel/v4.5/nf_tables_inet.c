static void F_1 ( struct V_1 * V_2 , unsigned int V_3 )
{
struct V_4 * V_5 ;
if ( V_3 == 1 )
V_5 = & V_6 ;
else
V_5 = & V_7 ;
V_2 -> V_8 = V_5 -> V_9 ;
if ( V_5 -> V_10 [ V_2 -> V_11 ] )
V_2 -> V_12 = V_5 -> V_10 [ V_2 -> V_11 ] ;
}
static int T_1 F_2 ( struct V_13 * V_13 )
{
V_13 -> V_14 . V_15 = F_3 ( sizeof( struct V_4 ) , V_16 ) ;
if ( V_13 -> V_14 . V_15 == NULL )
return - V_17 ;
memcpy ( V_13 -> V_14 . V_15 , & V_18 , sizeof( V_18 ) ) ;
if ( F_4 ( V_13 , V_13 -> V_14 . V_15 ) < 0 )
goto V_19;
return 0 ;
V_19:
F_5 ( V_13 -> V_14 . V_15 ) ;
return - V_17 ;
}
static void T_2 F_6 ( struct V_13 * V_13 )
{
F_7 ( V_13 , V_13 -> V_14 . V_15 ) ;
F_5 ( V_13 -> V_14 . V_15 ) ;
}
static int T_3 F_8 ( void )
{
int V_20 ;
F_9 ( & V_21 ) ;
V_20 = F_10 ( & V_22 ) ;
if ( V_20 < 0 )
F_11 ( & V_21 ) ;
return V_20 ;
}
static void T_4 F_12 ( void )
{
F_13 ( & V_22 ) ;
F_11 ( & V_21 ) ;
}
