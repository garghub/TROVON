static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
V_4 -> V_5 = 5 ;
V_4 -> V_6 = 4 ;
V_4 -> V_7 = F_3 ( V_2 ) -> V_7 ;
V_4 -> V_8 = F_3 ( V_2 ) -> V_8 ;
V_4 -> V_9 = F_3 ( V_2 ) -> V_9 ;
V_4 -> V_10 = F_3 ( V_2 ) -> V_10 ;
V_4 -> V_11 = F_3 ( V_2 ) -> V_11 ;
}
static int F_4 ( struct V_12 * V_13 , struct V_1 * V_2 )
{
struct V_14 * V_15 ;
struct V_3 * V_16 ;
int V_17 , V_18 ;
V_17 = 0 ;
V_18 = F_3 ( V_2 ) -> V_18 ;
if ( F_5 ( V_18 ) )
V_17 += V_19 - ( V_18 & 4 ) ;
F_6 ( V_2 , - V_13 -> V_20 . V_21 -
V_17 + ( F_3 ( V_2 ) -> V_5 - sizeof( * V_16 ) ) ) ;
if ( V_13 -> V_22 . V_23 != V_24 )
V_2 -> V_25 += V_19 ;
V_2 -> V_26 = V_2 -> V_25 +
F_7 ( struct V_3 , V_7 ) ;
V_2 -> V_27 = V_2 -> V_25 + sizeof( * V_16 ) ;
F_1 ( V_2 ) ;
V_15 = F_8 ( V_2 , F_3 ( V_2 ) -> V_5 - V_17 ) ;
V_16 = F_2 ( V_2 ) ;
if ( F_5 ( V_18 ) ) {
F_9 ( V_18 < 0 ) ;
V_15 -> V_28 = 4 - ( V_18 & 4 ) ;
V_15 -> V_17 = V_18 / 8 ;
V_15 -> V_29 = V_16 -> V_7 ;
if ( V_15 -> V_28 )
memset ( V_15 + 1 , V_30 , V_15 -> V_28 ) ;
V_16 -> V_7 = V_31 ;
V_16 -> V_5 = sizeof( struct V_3 ) / 4 ;
}
V_16 -> V_32 = V_13 -> V_20 . V_32 . V_33 ;
V_16 -> V_34 = V_13 -> V_9 . V_34 . V_33 ;
return 0 ;
}
static int F_10 ( struct V_12 * V_13 , struct V_1 * V_2 )
{
struct V_3 * V_4 ;
int V_18 = 0 ;
int V_35 = - V_36 ;
if ( F_5 ( F_3 ( V_2 ) -> V_7 == V_31 ) ) {
struct V_14 * V_15 ;
int V_37 ;
if ( ! F_11 ( V_2 , sizeof( * V_15 ) ) )
goto V_38;
V_15 = (struct V_14 * ) V_2 -> V_39 ;
V_37 = sizeof( * V_15 ) + V_15 -> V_28 ;
V_18 = V_15 -> V_17 * 8 + ( V_19 - V_37 ) ;
if ( V_18 < 0 || V_18 & 3 || V_18 > 250 )
goto V_38;
F_3 ( V_2 ) -> V_7 = V_15 -> V_29 ;
if ( ! F_11 ( V_2 , V_37 ) )
goto V_38;
F_8 ( V_2 , V_37 ) ;
}
F_12 ( V_2 , sizeof( * V_4 ) ) ;
F_13 ( V_2 ) ;
F_14 ( V_2 ) ;
F_1 ( V_2 ) ;
V_4 = F_2 ( V_2 ) ;
V_4 -> V_5 += V_18 / 4 ;
V_4 -> V_40 = F_15 ( V_2 -> V_41 ) ;
V_4 -> V_34 = V_13 -> V_22 . V_34 . V_33 ;
V_4 -> V_32 = V_13 -> V_22 . V_32 . V_33 ;
V_4 -> V_42 = 0 ;
V_4 -> V_42 = F_16 ( F_17 ( V_2 ) , V_4 -> V_5 ) ;
V_35 = 0 ;
V_38:
return V_35 ;
}
static int T_1 F_18 ( void )
{
return F_19 ( & V_43 , V_44 ) ;
}
static void T_2 F_20 ( void )
{
int V_35 ;
V_35 = F_21 ( & V_43 , V_44 ) ;
F_9 ( V_35 ) ;
}
