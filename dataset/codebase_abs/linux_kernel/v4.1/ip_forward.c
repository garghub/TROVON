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
static int F_8 ( struct V_8 * V_9 , struct V_1 * V_2 )
{
struct V_10 * V_11 = & ( F_9 ( V_2 ) -> V_11 ) ;
F_10 ( F_11 ( F_12 ( V_2 ) -> V_12 ) , V_13 ) ;
F_13 ( F_11 ( F_12 ( V_2 ) -> V_12 ) , V_14 , V_2 -> V_7 ) ;
if ( F_2 ( V_11 -> V_15 ) )
F_14 ( V_2 ) ;
F_15 ( V_2 ) ;
return F_16 ( V_9 , V_2 ) ;
}
int F_17 ( struct V_1 * V_2 )
{
T_1 V_6 ;
struct V_16 * V_17 ;
struct V_18 * V_19 ;
struct V_10 * V_11 = & ( F_9 ( V_2 ) -> V_11 ) ;
if ( V_2 -> V_20 != V_21 )
goto V_22;
if ( F_2 ( V_2 -> V_9 ) )
goto V_22;
if ( F_18 ( V_2 ) )
goto V_22;
if ( ! F_19 ( NULL , V_23 , V_2 ) )
goto V_22;
if ( F_9 ( V_2 ) -> V_11 . V_24 && F_20 ( V_2 ) )
return V_25 ;
F_21 ( V_2 ) ;
if ( F_3 ( V_2 ) -> V_26 <= 1 )
goto V_27;
if ( ! F_22 ( V_2 ) )
goto V_22;
V_19 = F_23 ( V_2 ) ;
if ( V_11 -> V_28 && V_19 -> V_29 )
goto V_30;
F_9 ( V_2 ) -> V_31 |= V_32 ;
V_6 = F_24 ( & V_19 -> V_33 , true ) ;
if ( ! F_1 ( V_2 ) && F_5 ( V_2 , V_6 ) ) {
F_25 ( F_11 ( V_19 -> V_33 . V_12 ) , V_34 ) ;
F_26 ( V_2 , V_35 , V_36 ,
F_27 ( V_6 ) ) ;
goto V_22;
}
if ( F_28 ( V_2 , F_29 ( V_19 -> V_33 . V_12 ) + V_19 -> V_33 . V_37 ) )
goto V_22;
V_17 = F_3 ( V_2 ) ;
F_30 ( V_17 ) ;
if ( F_9 ( V_2 ) -> V_31 & V_38 && ! V_11 -> V_39 &&
! F_31 ( V_2 ) )
F_32 ( V_2 ) ;
V_2 -> V_40 = F_33 ( V_17 -> V_41 ) ;
return F_34 ( V_42 , V_43 , NULL , V_2 ,
V_2 -> V_12 , V_19 -> V_33 . V_12 , F_8 ) ;
V_30:
F_26 ( V_2 , V_35 , V_44 , 0 ) ;
goto V_22;
V_27:
F_10 ( F_11 ( F_12 ( V_2 ) -> V_12 ) , V_45 ) ;
F_26 ( V_2 , V_46 , V_47 , 0 ) ;
V_22:
F_35 ( V_2 ) ;
return V_48 ;
}
