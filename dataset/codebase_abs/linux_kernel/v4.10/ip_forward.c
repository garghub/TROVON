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
if ( F_6 ( V_2 ) && F_7 ( V_2 , V_3 ) )
return false ;
return true ;
}
static int F_8 ( struct V_9 * V_9 , struct V_10 * V_11 , struct V_1 * V_2 )
{
struct V_12 * V_13 = & ( F_5 ( V_2 ) -> V_13 ) ;
F_9 ( V_9 , V_14 ) ;
F_10 ( V_9 , V_15 , V_2 -> V_4 ) ;
if ( F_2 ( V_13 -> V_16 ) )
F_11 ( V_2 ) ;
return F_12 ( V_9 , V_11 , V_2 ) ;
}
int F_13 ( struct V_1 * V_2 )
{
T_1 V_3 ;
struct V_17 * V_18 ;
struct V_19 * V_20 ;
struct V_12 * V_13 = & ( F_5 ( V_2 ) -> V_13 ) ;
struct V_9 * V_9 ;
if ( V_2 -> V_21 != V_22 )
goto V_23;
if ( F_2 ( V_2 -> V_11 ) )
goto V_23;
if ( F_14 ( V_2 ) )
goto V_23;
if ( ! F_15 ( NULL , V_24 , V_2 ) )
goto V_23;
if ( F_5 ( V_2 ) -> V_13 . V_25 && F_16 ( V_2 ) )
return V_26 ;
F_17 ( V_2 ) ;
V_9 = F_18 ( V_2 -> V_27 ) ;
if ( F_3 ( V_2 ) -> V_28 <= 1 )
goto V_29;
if ( ! F_19 ( V_2 ) )
goto V_23;
V_20 = F_20 ( V_2 ) ;
if ( V_13 -> V_30 && V_20 -> V_31 )
goto V_32;
F_5 ( V_2 ) -> V_33 |= V_34 ;
V_3 = F_21 ( & V_20 -> V_35 , true ) ;
if ( F_1 ( V_2 , V_3 ) ) {
F_22 ( V_9 , V_36 ) ;
F_23 ( V_2 , V_37 , V_38 ,
F_24 ( V_3 ) ) ;
goto V_23;
}
if ( F_25 ( V_2 , F_26 ( V_20 -> V_35 . V_27 ) + V_20 -> V_35 . V_39 ) )
goto V_23;
V_18 = F_3 ( V_2 ) ;
F_27 ( V_18 ) ;
if ( F_5 ( V_2 ) -> V_33 & V_40 && ! V_13 -> V_41 &&
! F_28 ( V_2 ) )
F_29 ( V_2 ) ;
V_2 -> V_42 = F_30 ( V_18 -> V_43 ) ;
return F_31 ( V_44 , V_45 ,
V_9 , NULL , V_2 , V_2 -> V_27 , V_20 -> V_35 . V_27 ,
F_8 ) ;
V_32:
F_23 ( V_2 , V_37 , V_46 , 0 ) ;
goto V_23;
V_29:
F_9 ( V_9 , V_47 ) ;
F_23 ( V_2 , V_48 , V_49 , 0 ) ;
V_23:
F_32 ( V_2 ) ;
return V_50 ;
}
