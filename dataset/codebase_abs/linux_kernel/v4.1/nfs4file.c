static int
F_1 ( struct V_1 * V_1 , struct V_2 * V_3 )
{
struct V_4 * V_5 ;
struct V_6 * V_6 = V_3 -> V_7 . V_6 ;
struct V_6 * V_8 = NULL ;
struct V_1 * V_9 ;
unsigned V_10 = V_3 -> V_11 ;
struct V_12 V_13 ;
int V_14 = 0 ;
int V_15 ;
F_2 ( L_1 , V_6 ) ;
if ( ( V_10 & V_16 ) == 3 )
V_10 -- ;
V_10 &= ~ ( V_17 | V_18 ) ;
V_8 = F_3 ( V_6 ) ;
V_9 = F_4 ( V_8 ) ;
V_5 = F_5 ( V_3 -> V_7 . V_6 , V_3 -> V_19 ) ;
V_15 = F_6 ( V_5 ) ;
if ( F_7 ( V_5 ) )
goto V_20;
V_13 . V_21 = V_22 ;
if ( V_10 & V_23 ) {
V_13 . V_21 |= V_24 ;
V_13 . V_25 = 0 ;
F_8 ( V_1 ) ;
}
V_1 = F_9 ( V_9 ) -> F_10 ( V_9 , V_5 , V_10 , & V_13 , & V_14 ) ;
if ( F_7 ( V_1 ) ) {
V_15 = F_6 ( V_1 ) ;
switch ( V_15 ) {
case - V_26 :
case - V_27 :
case - V_28 :
case - V_29 :
case - V_30 :
goto V_31;
default:
goto V_32;
}
}
if ( V_1 != F_4 ( V_6 ) )
goto V_32;
F_11 ( V_6 , F_12 ( V_9 ) ) ;
F_13 ( V_3 , V_5 ) ;
F_14 ( V_1 , V_3 ) ;
V_15 = 0 ;
V_31:
F_15 ( V_5 ) ;
V_20:
F_16 ( V_8 ) ;
return V_15 ;
V_32:
F_17 ( V_6 ) ;
V_15 = - V_33 ;
goto V_31;
}
static int
F_18 ( struct V_2 * V_2 , T_1 V_34 , T_1 V_35 , int V_36 )
{
int V_37 ;
struct V_1 * V_1 = F_19 ( V_2 ) ;
F_20 ( V_1 ) ;
F_21 ( V_1 ) ;
do {
V_37 = F_22 ( V_1 -> V_38 , V_34 , V_35 ) ;
if ( V_37 != 0 )
break;
F_23 ( & V_1 -> V_39 ) ;
V_37 = F_24 ( V_2 , V_34 , V_35 , V_36 ) ;
if ( ! V_37 )
V_37 = F_25 ( V_1 , ! ! V_36 ) ;
F_26 ( & V_1 -> V_39 ) ;
V_34 = 0 ;
V_35 = V_40 ;
} while ( V_37 == - V_41 );
F_27 ( V_1 , V_37 ) ;
return V_37 ;
}
static T_1 F_28 ( struct V_2 * V_42 , T_1 V_43 , int V_44 )
{
T_1 V_37 ;
switch ( V_44 ) {
case V_45 :
case V_46 :
V_37 = F_29 ( V_42 , V_43 , V_44 ) ;
if ( V_37 != - V_47 )
return V_37 ;
default:
return F_30 ( V_42 , V_43 , V_44 ) ;
}
}
static long F_31 ( struct V_2 * V_42 , int V_48 , T_1 V_43 , T_1 V_49 )
{
struct V_1 * V_1 = F_19 ( V_42 ) ;
long V_37 ;
if ( ! F_32 ( V_1 -> V_50 ) )
return - V_51 ;
if ( ( V_48 != 0 ) && ( V_48 != ( V_52 | V_53 ) ) )
return - V_51 ;
V_37 = F_33 ( V_1 , V_43 + V_49 ) ;
if ( V_37 < 0 )
return V_37 ;
if ( V_48 & V_52 )
return F_34 ( V_42 , V_43 , V_49 ) ;
return F_35 ( V_42 , V_43 , V_49 ) ;
}
