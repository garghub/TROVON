static inline void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
if ( F_3 ( F_4 ( V_2 ) -> V_5 ) )
F_5 ( V_2 , V_4 ) ;
}
static int F_6 ( struct V_6 * V_7 , struct V_1 * V_2 )
{
struct V_8 * V_9 = F_7 ( V_2 ) ;
struct V_3 * V_10 ;
int V_11 ;
F_8 ( V_2 , F_9 ( V_2 ) ) ;
F_10 ( V_2 , F_11 ( V_2 ) ) ;
F_12 ( V_2 , - V_7 -> V_12 . V_13 ) ;
V_2 -> V_14 = V_2 -> V_15 +
F_13 ( struct V_3 , V_16 ) ;
V_2 -> V_17 = V_2 -> V_15 + sizeof( * V_10 ) ;
V_10 = F_14 ( V_2 ) ;
V_10 -> V_18 = 6 ;
memcpy ( V_10 -> V_19 , F_4 ( V_2 ) -> V_19 ,
sizeof( V_10 -> V_19 ) ) ;
V_10 -> V_16 = F_15 ( F_7 ( V_2 ) -> V_20 -> V_21 ) ;
if ( V_7 -> V_12 . V_22 & V_23 )
V_11 = 0 ;
else
V_11 = F_4 ( V_2 ) -> V_5 ;
V_11 = F_16 ( V_11 , F_4 ( V_2 ) -> V_5 ) ;
if ( V_7 -> V_12 . V_24 & V_25 )
V_11 &= ~ V_26 ;
F_17 ( V_10 , 0 , V_11 ) ;
V_10 -> V_27 = F_18 ( V_9 -> V_28 ) ;
V_10 -> V_29 = * (struct V_30 * ) & V_7 -> V_12 . V_29 ;
V_10 -> V_31 = * (struct V_30 * ) & V_7 -> V_32 . V_31 ;
return 0 ;
}
static int F_19 ( struct V_6 * V_7 , struct V_1 * V_2 )
{
int V_33 = - V_34 ;
if ( F_4 ( V_2 ) -> V_35 != V_36 )
goto V_37;
if ( ! F_20 ( V_2 , sizeof( struct V_3 ) ) )
goto V_37;
V_33 = F_21 ( V_2 , V_38 ) ;
if ( V_33 )
goto V_37;
if ( V_7 -> V_12 . V_24 & V_39 )
F_22 ( F_23 ( F_14 ( V_2 ) ) ,
F_2 ( V_2 ) ) ;
if ( ! ( V_7 -> V_12 . V_24 & V_25 ) )
F_1 ( V_2 ) ;
F_24 ( V_2 ) ;
F_25 ( V_2 ) ;
V_33 = 0 ;
V_37:
return V_33 ;
}
static struct V_1 * F_26 ( struct V_6 * V_7 ,
struct V_1 * V_2 ,
T_1 V_40 )
{
F_27 ( V_2 , V_2 -> V_41 ) ;
return F_28 ( V_2 , V_40 ) ;
}
static void F_29 ( struct V_6 * V_7 , struct V_1 * V_2 )
{
struct V_42 * V_43 = V_42 ( V_2 ) ;
if ( V_43 -> V_24 & V_44 ) {
V_2 -> V_15 = V_2 -> V_15 - V_7 -> V_12 . V_13 ;
V_2 -> V_17 = V_2 -> V_15 + sizeof( struct V_3 ) ;
}
F_30 ( V_2 ) ;
F_31 ( V_2 , V_2 -> V_41 + V_7 -> V_12 . V_13 ) ;
}
static int T_2 F_32 ( void )
{
return F_33 ( & V_45 , V_46 ) ;
}
static void T_3 F_34 ( void )
{
int V_33 ;
V_33 = F_35 ( & V_45 , V_46 ) ;
F_36 ( V_33 ) ;
}
