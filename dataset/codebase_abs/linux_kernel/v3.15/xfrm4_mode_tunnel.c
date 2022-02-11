static inline void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
if ( F_3 ( F_4 ( V_2 ) -> V_5 ) )
F_5 ( V_4 ) ;
}
static int F_6 ( struct V_6 * V_7 , struct V_1 * V_2 )
{
struct V_8 * V_9 = F_7 ( V_2 ) ;
struct V_3 * V_10 ;
int V_11 ;
F_8 ( V_2 , - V_7 -> V_12 . V_13 ) ;
V_2 -> V_14 = V_2 -> V_15 +
F_9 ( struct V_3 , V_16 ) ;
V_2 -> V_17 = V_2 -> V_15 + sizeof( * V_10 ) ;
V_10 = F_10 ( V_2 ) ;
V_10 -> V_18 = 5 ;
V_10 -> V_19 = 4 ;
V_10 -> V_16 = F_11 ( F_7 ( V_2 ) -> V_20 -> V_21 ) ;
if ( V_7 -> V_12 . V_22 & V_23 )
V_10 -> V_5 = 0 ;
else
V_10 -> V_5 = F_4 ( V_2 ) -> V_5 ;
V_10 -> V_5 = F_12 ( V_10 -> V_5 ,
F_4 ( V_2 ) -> V_5 ) ;
V_11 = V_7 -> V_12 . V_11 ;
if ( V_11 & V_24 )
F_13 ( V_10 ) ;
V_10 -> V_25 = ( V_11 & V_26 ) ?
0 : ( F_4 ( V_2 ) -> V_25 & F_14 ( V_27 ) ) ;
F_15 ( V_2 , V_9 -> V_28 , NULL ) ;
V_10 -> V_29 = F_16 ( V_9 -> V_28 ) ;
V_10 -> V_30 = V_7 -> V_12 . V_30 . V_31 ;
V_10 -> V_32 = V_7 -> V_33 . V_32 . V_31 ;
return 0 ;
}
static int F_17 ( struct V_6 * V_7 , struct V_1 * V_2 )
{
int V_34 = - V_35 ;
if ( F_4 ( V_2 ) -> V_16 != V_36 )
goto V_37;
if ( ! F_18 ( V_2 , sizeof( struct V_3 ) ) )
goto V_37;
V_34 = F_19 ( V_2 , V_38 ) ;
if ( V_34 )
goto V_37;
if ( V_7 -> V_12 . V_11 & V_39 )
F_20 ( F_4 ( V_2 ) -> V_5 , F_2 ( V_2 ) ) ;
if ( ! ( V_7 -> V_12 . V_11 & V_24 ) )
F_1 ( V_2 ) ;
F_21 ( V_2 ) ;
F_22 ( V_2 ) ;
V_34 = 0 ;
V_37:
return V_34 ;
}
static int T_1 F_23 ( void )
{
return F_24 ( & V_40 , V_41 ) ;
}
static void T_2 F_25 ( void )
{
int V_34 ;
V_34 = F_26 ( & V_40 , V_41 ) ;
F_27 ( V_34 ) ;
}
