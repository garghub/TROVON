static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
F_2 ( V_4 , - F_3 ( V_4 ) ) ;
return 0 ;
}
static int F_4 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
return F_5 ( V_4 ) -> V_5 ;
}
static int F_6 ( struct V_1 * V_2 )
{
if ( V_2 -> V_6 . V_7 != V_8 )
return - V_9 ;
if ( V_2 -> V_10 )
return - V_9 ;
V_2 -> V_6 . V_11 = sizeof( struct V_12 ) ;
return 0 ;
}
static void F_7 ( struct V_1 * V_2 )
{
}
static int F_8 ( struct V_3 * V_4 )
{
return F_9 ( V_4 , V_13 , F_5 ( V_4 ) -> V_14 ) ;
}
static int F_10 ( struct V_3 * V_4 , T_1 V_15 )
{
return - V_16 ;
}
static int T_2 F_11 ( void )
{
if ( F_12 ( & V_17 , V_18 ) < 0 ) {
F_13 ( V_19 L_1 ) ;
return - V_20 ;
}
if ( F_14 ( & V_21 , V_18 ) ) {
F_13 ( V_19 L_2 ) ;
F_15 ( & V_17 , V_18 ) ;
return - V_20 ;
}
#if F_16 ( V_22 )
if ( F_14 ( & V_23 , V_24 ) ) {
F_13 ( V_19 L_3 ) ;
F_17 ( & V_21 , V_18 ) ;
F_15 ( & V_17 , V_18 ) ;
return - V_20 ;
}
#endif
return 0 ;
}
static void T_3 F_18 ( void )
{
#if F_16 ( V_22 )
if ( F_17 ( & V_23 , V_24 ) )
F_13 ( V_19 L_4 ) ;
#endif
if ( F_17 ( & V_21 , V_18 ) )
F_13 ( V_19 L_5 ) ;
if ( F_15 ( & V_17 , V_18 ) < 0 )
F_13 ( V_19 L_6 ) ;
}
