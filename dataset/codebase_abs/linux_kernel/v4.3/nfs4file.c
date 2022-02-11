static int
F_1 ( struct V_1 * V_1 , struct V_2 * V_3 )
{
struct V_4 * V_5 ;
struct V_6 * V_6 = V_3 -> V_7 . V_6 ;
struct V_6 * V_8 = NULL ;
struct V_1 * V_9 ;
unsigned V_10 = V_3 -> V_11 ;
struct V_12 V_13 ;
int V_14 ;
F_2 ( L_1 , V_6 ) ;
V_14 = F_3 ( V_10 ) ;
if ( V_14 )
return V_14 ;
if ( ( V_10 & V_15 ) == 3 )
V_10 -- ;
V_10 &= ~ ( V_16 | V_17 ) ;
V_8 = F_4 ( V_6 ) ;
V_9 = F_5 ( V_8 ) ;
V_5 = F_6 ( V_3 -> V_7 . V_6 , V_3 -> V_18 ) ;
V_14 = F_7 ( V_5 ) ;
if ( F_8 ( V_5 ) )
goto V_19;
V_13 . V_20 = V_21 ;
if ( V_10 & V_22 ) {
V_13 . V_20 |= V_23 ;
V_13 . V_24 = 0 ;
F_9 ( V_1 ) ;
}
V_1 = F_10 ( V_9 ) -> F_11 ( V_9 , V_5 , V_10 , & V_13 , NULL ) ;
if ( F_8 ( V_1 ) ) {
V_14 = F_7 ( V_1 ) ;
switch ( V_14 ) {
case - V_25 :
case - V_26 :
case - V_27 :
case - V_28 :
case - V_29 :
goto V_30;
default:
goto V_31;
}
}
if ( V_1 != F_5 ( V_6 ) )
goto V_31;
F_12 ( V_6 , F_13 ( V_9 ) ) ;
F_14 ( V_3 , V_5 ) ;
F_15 ( V_1 , V_3 ) ;
V_14 = 0 ;
V_30:
F_16 ( V_5 ) ;
V_19:
F_17 ( V_8 ) ;
return V_14 ;
V_31:
F_18 ( V_6 ) ;
V_14 = - V_32 ;
goto V_30;
}
static int
F_19 ( struct V_2 * V_2 , T_1 V_33 )
{
struct V_1 * V_1 = F_20 ( V_2 ) ;
F_2 ( L_2 , V_2 ) ;
F_21 ( V_1 , V_34 ) ;
if ( ( V_2 -> V_18 & V_35 ) == 0 )
return 0 ;
if ( ! F_22 ( V_1 ) )
return F_23 ( V_2 -> V_36 ) ;
return F_24 ( V_2 , 0 ) ;
}
static int
F_25 ( struct V_2 * V_2 , T_2 V_37 , T_2 V_38 , int V_39 )
{
int V_40 ;
struct V_1 * V_1 = F_20 ( V_2 ) ;
F_26 ( V_1 ) ;
F_27 ( V_1 ) ;
do {
V_40 = F_28 ( V_1 -> V_41 , V_37 , V_38 ) ;
if ( V_40 != 0 )
break;
F_29 ( & V_1 -> V_42 ) ;
V_40 = F_30 ( V_2 , V_37 , V_38 , V_39 ) ;
if ( ! V_40 )
V_40 = F_31 ( V_1 , ! ! V_39 ) ;
F_32 ( & V_1 -> V_42 ) ;
V_37 = 0 ;
V_38 = V_43 ;
} while ( V_40 == - V_44 );
F_33 ( V_1 , V_40 ) ;
return V_40 ;
}
static T_2 F_34 ( struct V_2 * V_45 , T_2 V_46 , int V_47 )
{
T_2 V_40 ;
switch ( V_47 ) {
case V_48 :
case V_49 :
V_40 = F_35 ( V_45 , V_46 , V_47 ) ;
if ( V_40 != - V_50 )
return V_40 ;
default:
return F_36 ( V_45 , V_46 , V_47 ) ;
}
}
static long F_37 ( struct V_2 * V_45 , int V_51 , T_2 V_46 , T_2 V_52 )
{
struct V_1 * V_1 = F_20 ( V_45 ) ;
long V_40 ;
if ( ! F_38 ( V_1 -> V_53 ) )
return - V_54 ;
if ( ( V_51 != 0 ) && ( V_51 != ( V_55 | V_56 ) ) )
return - V_54 ;
V_40 = F_39 ( V_1 , V_46 + V_52 ) ;
if ( V_40 < 0 )
return V_40 ;
if ( V_51 & V_55 )
return F_40 ( V_45 , V_46 , V_52 ) ;
return F_41 ( V_45 , V_46 , V_52 ) ;
}
