static bool F_1 ( const struct V_1 * V_2 )
{
return F_2 ( ( F_3 ( V_2 ) -> V_3 & F_4 ( V_4 ) ) == 0 ) ||
! V_2 -> V_5 ;
}
static bool F_5 ( const struct V_1 * V_2 , unsigned int V_6 )
{
if ( V_2 -> V_7 <= V_6 || V_2 -> V_5 )
return false ;
if ( F_6 ( V_2 ) && F_7 ( V_2 ) <= V_6 )
return false ;
return true ;
}
static bool F_8 ( const struct V_1 * V_2 )
{
unsigned int V_6 ;
if ( V_2 -> V_5 || ! F_6 ( V_2 ) )
return false ;
V_6 = F_9 ( F_10 ( V_2 ) , true ) ;
return F_7 ( V_2 ) > V_6 ;
}
static int F_11 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = F_10 ( V_2 ) ;
T_1 V_10 ;
struct V_1 * V_11 ;
int V_12 = 0 ;
V_10 = F_12 ( V_2 , V_9 -> V_13 ) ;
V_11 = F_13 ( V_2 , V_10 & ~ V_14 ) ;
if ( F_14 ( V_11 ) ) {
F_15 ( V_2 ) ;
return - V_15 ;
}
F_16 ( V_2 ) ;
do {
struct V_1 * V_16 = V_11 -> V_17 ;
int V_18 ;
V_11 -> V_17 = NULL ;
V_18 = F_17 ( V_11 ) ;
if ( V_18 && V_12 == 0 )
V_12 = V_18 ;
V_11 = V_16 ;
} while ( V_11 );
return V_12 ;
}
static int F_18 ( struct V_1 * V_2 )
{
struct V_19 * V_20 = & ( F_19 ( V_2 ) -> V_20 ) ;
F_20 ( F_21 ( F_10 ( V_2 ) -> V_13 ) , V_21 ) ;
F_22 ( F_21 ( F_10 ( V_2 ) -> V_13 ) , V_22 , V_2 -> V_7 ) ;
if ( F_2 ( V_20 -> V_23 ) )
F_23 ( V_2 ) ;
if ( F_8 ( V_2 ) )
return F_11 ( V_2 ) ;
return F_17 ( V_2 ) ;
}
int F_24 ( struct V_1 * V_2 )
{
T_2 V_6 ;
struct V_24 * V_25 ;
struct V_26 * V_27 ;
struct V_19 * V_20 = & ( F_19 ( V_2 ) -> V_20 ) ;
if ( F_25 ( V_2 ) )
goto V_28;
if ( ! F_26 ( NULL , V_29 , V_2 ) )
goto V_28;
if ( F_19 ( V_2 ) -> V_20 . V_30 && F_27 ( V_2 ) )
return V_31 ;
if ( V_2 -> V_32 != V_33 )
goto V_28;
F_28 ( V_2 ) ;
if ( F_3 ( V_2 ) -> V_34 <= 1 )
goto V_35;
if ( ! F_29 ( V_2 ) )
goto V_28;
V_27 = F_30 ( V_2 ) ;
if ( V_20 -> V_36 && V_27 -> V_37 )
goto V_38;
F_19 ( V_2 ) -> V_39 |= V_40 ;
V_6 = F_9 ( & V_27 -> V_9 , true ) ;
if ( ! F_1 ( V_2 ) && F_5 ( V_2 , V_6 ) ) {
F_31 ( F_21 ( V_27 -> V_9 . V_13 ) , V_41 ) ;
F_32 ( V_2 , V_42 , V_43 ,
F_33 ( V_6 ) ) ;
goto V_28;
}
if ( F_34 ( V_2 , F_35 ( V_27 -> V_9 . V_13 ) + V_27 -> V_9 . V_44 ) )
goto V_28;
V_25 = F_3 ( V_2 ) ;
F_36 ( V_25 ) ;
if ( V_27 -> V_45 & V_46 && ! V_20 -> V_47 && ! F_37 ( V_2 ) )
F_38 ( V_2 ) ;
V_2 -> V_48 = F_39 ( V_25 -> V_49 ) ;
return F_40 ( V_50 , V_51 , V_2 , V_2 -> V_13 ,
V_27 -> V_9 . V_13 , F_18 ) ;
V_38:
F_32 ( V_2 , V_42 , V_52 , 0 ) ;
goto V_28;
V_35:
F_20 ( F_21 ( F_10 ( V_2 ) -> V_13 ) , V_53 ) ;
F_32 ( V_2 , V_54 , V_55 , 0 ) ;
V_28:
F_15 ( V_2 ) ;
return V_56 ;
}
