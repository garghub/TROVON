static bool F_1 ( const struct V_1 * V_2 )
{
return F_2 ( ( F_3 ( V_2 ) -> V_3 & F_4 ( V_4 ) ) == 0 ) ||
V_2 -> V_5 ;
}
static bool F_5 ( const struct V_1 * V_2 , unsigned int V_6 )
{
if ( V_2 -> V_7 <= V_6 )
return false ;
if ( F_6 ( V_2 ) && F_7 ( V_2 ) <= V_6 )
return false ;
return true ;
}
static int F_8 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = & ( F_9 ( V_2 ) -> V_9 ) ;
F_10 ( F_11 ( F_12 ( V_2 ) -> V_10 ) , V_11 ) ;
F_13 ( F_11 ( F_12 ( V_2 ) -> V_10 ) , V_12 , V_2 -> V_7 ) ;
if ( F_2 ( V_9 -> V_13 ) )
F_14 ( V_2 ) ;
return F_15 ( V_2 ) ;
}
int F_16 ( struct V_1 * V_2 )
{
T_1 V_6 ;
struct V_14 * V_15 ;
struct V_16 * V_17 ;
struct V_8 * V_9 = & ( F_9 ( V_2 ) -> V_9 ) ;
if ( V_2 -> V_18 != V_19 )
goto V_20;
if ( F_17 ( V_2 ) )
goto V_20;
if ( ! F_18 ( NULL , V_21 , V_2 ) )
goto V_20;
if ( F_9 ( V_2 ) -> V_9 . V_22 && F_19 ( V_2 ) )
return V_23 ;
F_20 ( V_2 ) ;
if ( F_3 ( V_2 ) -> V_24 <= 1 )
goto V_25;
if ( ! F_21 ( V_2 ) )
goto V_20;
V_17 = F_22 ( V_2 ) ;
if ( V_9 -> V_26 && V_17 -> V_27 )
goto V_28;
F_9 ( V_2 ) -> V_29 |= V_30 ;
V_6 = F_23 ( & V_17 -> V_31 , true ) ;
if ( ! F_1 ( V_2 ) && F_5 ( V_2 , V_6 ) ) {
F_24 ( F_11 ( V_17 -> V_31 . V_10 ) , V_32 ) ;
F_25 ( V_2 , V_33 , V_34 ,
F_26 ( V_6 ) ) ;
goto V_20;
}
if ( F_27 ( V_2 , F_28 ( V_17 -> V_31 . V_10 ) + V_17 -> V_31 . V_35 ) )
goto V_20;
V_15 = F_3 ( V_2 ) ;
F_29 ( V_15 ) ;
if ( V_17 -> V_36 & V_37 && ! V_9 -> V_38 && ! F_30 ( V_2 ) )
F_31 ( V_2 ) ;
V_2 -> V_39 = F_32 ( V_15 -> V_40 ) ;
return F_33 ( V_41 , V_42 , V_2 , V_2 -> V_10 ,
V_17 -> V_31 . V_10 , F_8 ) ;
V_28:
F_25 ( V_2 , V_33 , V_43 , 0 ) ;
goto V_20;
V_25:
F_10 ( F_11 ( F_12 ( V_2 ) -> V_10 ) , V_44 ) ;
F_25 ( V_2 , V_45 , V_46 , 0 ) ;
V_20:
F_34 ( V_2 ) ;
return V_47 ;
}
