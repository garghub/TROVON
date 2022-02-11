static bool F_1 ( const struct V_1 * V_2 , unsigned int V_3 )
{
if ( V_2 -> V_4 <= V_3 )
return false ;
if ( F_2 ( ( F_3 ( V_2 ) -> V_5 & F_4 ( V_6 ) ) == 0 ) )
return false ;
if ( F_2 ( F_5 ( V_2 ) -> V_7 > V_3 ) )
return true ;
if ( V_2 -> V_8 )
return false ;
if ( F_6 ( V_2 ) && F_7 ( V_2 ) <= V_3 )
return false ;
return true ;
}
static int F_8 ( struct V_9 * V_10 , struct V_1 * V_2 )
{
struct V_11 * V_12 = & ( F_5 ( V_2 ) -> V_12 ) ;
F_9 ( F_10 ( F_11 ( V_2 ) -> V_13 ) , V_14 ) ;
F_12 ( F_10 ( F_11 ( V_2 ) -> V_13 ) , V_15 , V_2 -> V_4 ) ;
if ( F_2 ( V_12 -> V_16 ) )
F_13 ( V_2 ) ;
F_14 ( V_2 ) ;
return F_15 ( V_10 , V_2 ) ;
}
int F_16 ( struct V_1 * V_2 )
{
T_1 V_3 ;
struct V_17 * V_18 ;
struct V_19 * V_20 ;
struct V_11 * V_12 = & ( F_5 ( V_2 ) -> V_12 ) ;
if ( V_2 -> V_21 != V_22 )
goto V_23;
if ( F_2 ( V_2 -> V_10 ) )
goto V_23;
if ( F_17 ( V_2 ) )
goto V_23;
if ( ! F_18 ( NULL , V_24 , V_2 ) )
goto V_23;
if ( F_5 ( V_2 ) -> V_12 . V_25 && F_19 ( V_2 ) )
return V_26 ;
F_20 ( V_2 ) ;
if ( F_3 ( V_2 ) -> V_27 <= 1 )
goto V_28;
if ( ! F_21 ( V_2 ) )
goto V_23;
V_20 = F_22 ( V_2 ) ;
if ( V_12 -> V_29 && V_20 -> V_30 )
goto V_31;
F_5 ( V_2 ) -> V_32 |= V_33 ;
V_3 = F_23 ( & V_20 -> V_34 , true ) ;
if ( F_1 ( V_2 , V_3 ) ) {
F_24 ( F_10 ( V_20 -> V_34 . V_13 ) , V_35 ) ;
F_25 ( V_2 , V_36 , V_37 ,
F_26 ( V_3 ) ) ;
goto V_23;
}
if ( F_27 ( V_2 , F_28 ( V_20 -> V_34 . V_13 ) + V_20 -> V_34 . V_38 ) )
goto V_23;
V_18 = F_3 ( V_2 ) ;
F_29 ( V_18 ) ;
if ( F_5 ( V_2 ) -> V_32 & V_39 && ! V_12 -> V_40 &&
! F_30 ( V_2 ) )
F_31 ( V_2 ) ;
V_2 -> V_41 = F_32 ( V_18 -> V_42 ) ;
return F_33 ( V_43 , V_44 , NULL , V_2 ,
V_2 -> V_13 , V_20 -> V_34 . V_13 , F_8 ) ;
V_31:
F_25 ( V_2 , V_36 , V_45 , 0 ) ;
goto V_23;
V_28:
F_9 ( F_10 ( F_11 ( V_2 ) -> V_13 ) , V_46 ) ;
F_25 ( V_2 , V_47 , V_48 , 0 ) ;
V_23:
F_34 ( V_2 ) ;
return V_49 ;
}
