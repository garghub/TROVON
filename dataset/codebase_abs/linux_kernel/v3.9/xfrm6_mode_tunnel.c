static inline void F_1 ( struct V_1 * V_2 )
{
const struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_3 * V_5 = F_3 ( V_2 ) ;
if ( F_4 ( F_5 ( V_4 ) ) )
F_6 ( V_5 ) ;
}
static int F_7 ( struct V_6 * V_7 , struct V_1 * V_2 )
{
struct V_8 * V_9 = F_8 ( V_2 ) ;
struct V_3 * V_10 ;
int V_11 ;
F_9 ( V_2 , - V_7 -> V_12 . V_13 ) ;
V_2 -> V_14 = V_2 -> V_15 +
F_10 ( struct V_3 , V_16 ) ;
V_2 -> V_17 = V_2 -> V_15 + sizeof( * V_10 ) ;
V_10 = F_2 ( V_2 ) ;
V_10 -> V_18 = 6 ;
memcpy ( V_10 -> V_19 , F_11 ( V_2 ) -> V_19 ,
sizeof( V_10 -> V_19 ) ) ;
V_10 -> V_16 = F_12 ( F_8 ( V_2 ) -> V_20 -> V_21 ) ;
V_11 = F_11 ( V_2 ) -> V_22 ;
V_11 = F_13 ( V_11 , V_11 ) ;
if ( V_7 -> V_12 . V_23 & V_24 )
V_11 &= ~ V_25 ;
F_14 ( V_10 , 0 , V_11 ) ;
V_10 -> V_26 = F_15 ( V_9 -> V_27 ) ;
V_10 -> V_28 = * (struct V_29 * ) & V_7 -> V_12 . V_28 ;
V_10 -> V_30 = * (struct V_29 * ) & V_7 -> V_31 . V_30 ;
return 0 ;
}
static int F_16 ( struct V_6 * V_7 , struct V_1 * V_2 )
{
int V_32 = - V_33 ;
if ( F_11 ( V_2 ) -> V_34 != V_35 )
goto V_36;
if ( ! F_17 ( V_2 , sizeof( struct V_3 ) ) )
goto V_36;
V_32 = F_18 ( V_2 , V_37 ) ;
if ( V_32 )
goto V_36;
if ( V_7 -> V_12 . V_23 & V_38 )
F_19 ( F_5 ( F_2 ( V_2 ) ) ,
F_3 ( V_2 ) ) ;
if ( ! ( V_7 -> V_12 . V_23 & V_24 ) )
F_1 ( V_2 ) ;
F_20 ( V_2 ) ;
F_21 ( V_2 ) ;
V_32 = 0 ;
V_36:
return V_32 ;
}
static int T_1 F_22 ( void )
{
return F_23 ( & V_39 , V_40 ) ;
}
static void T_2 F_24 ( void )
{
int V_32 ;
V_32 = F_25 ( & V_39 , V_40 ) ;
F_26 ( V_32 ) ;
}
