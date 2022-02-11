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
F_8 ( V_2 , F_9 ( V_2 ) ) ;
F_10 ( V_2 , F_11 ( V_2 ) ) ;
F_12 ( V_2 , - V_7 -> V_12 . V_13 ) ;
V_2 -> V_14 = V_2 -> V_15 +
F_13 ( struct V_3 , V_16 ) ;
V_2 -> V_17 = V_2 -> V_15 + sizeof( * V_10 ) ;
V_10 = F_14 ( V_2 ) ;
V_10 -> V_18 = 5 ;
V_10 -> V_19 = 4 ;
V_10 -> V_16 = F_15 ( F_7 ( V_2 ) -> V_20 -> V_21 ) ;
if ( V_7 -> V_12 . V_22 & V_23 )
V_10 -> V_5 = 0 ;
else
V_10 -> V_5 = F_4 ( V_2 ) -> V_5 ;
V_10 -> V_5 = F_16 ( V_10 -> V_5 ,
F_4 ( V_2 ) -> V_5 ) ;
V_11 = V_7 -> V_12 . V_11 ;
if ( V_11 & V_24 )
F_17 ( V_10 ) ;
V_10 -> V_25 = ( V_11 & V_26 ) ?
0 : ( F_4 ( V_2 ) -> V_25 & F_18 ( V_27 ) ) ;
V_10 -> V_28 = F_19 ( V_9 -> V_29 ) ;
V_10 -> V_30 = V_7 -> V_12 . V_30 . V_31 ;
V_10 -> V_32 = V_7 -> V_33 . V_32 . V_31 ;
F_20 ( F_21 ( V_9 -> V_34 ) , V_2 , NULL ) ;
return 0 ;
}
static int F_22 ( struct V_6 * V_7 , struct V_1 * V_2 )
{
int V_35 = - V_36 ;
if ( F_4 ( V_2 ) -> V_16 != V_37 )
goto V_38;
if ( ! F_23 ( V_2 , sizeof( struct V_3 ) ) )
goto V_38;
V_35 = F_24 ( V_2 , V_39 ) ;
if ( V_35 )
goto V_38;
if ( V_7 -> V_12 . V_11 & V_40 )
F_25 ( F_4 ( V_2 ) -> V_5 , F_2 ( V_2 ) ) ;
if ( ! ( V_7 -> V_12 . V_11 & V_24 ) )
F_1 ( V_2 ) ;
F_26 ( V_2 ) ;
F_27 ( V_2 ) ;
V_35 = 0 ;
V_38:
return V_35 ;
}
static struct V_1 * F_28 ( struct V_6 * V_7 ,
struct V_1 * V_2 ,
T_1 V_41 )
{
F_29 ( V_2 , V_2 -> V_42 ) ;
return F_30 ( V_2 , V_41 ) ;
}
static void F_31 ( struct V_6 * V_7 , struct V_1 * V_2 )
{
struct V_43 * V_44 = V_43 ( V_2 ) ;
if ( V_44 -> V_11 & V_45 ) {
V_2 -> V_15 = V_2 -> V_15 - V_7 -> V_12 . V_13 ;
V_2 -> V_17 = V_2 -> V_15 +
sizeof( struct V_3 ) ;
}
F_32 ( V_2 ) ;
F_33 ( V_2 , V_2 -> V_42 + V_7 -> V_12 . V_13 ) ;
}
static int T_2 F_34 ( void )
{
return F_35 ( & V_46 , V_47 ) ;
}
static void T_3 F_36 ( void )
{
int V_35 ;
V_35 = F_37 ( & V_46 , V_47 ) ;
F_38 ( V_35 ) ;
}
