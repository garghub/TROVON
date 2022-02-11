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
V_9 = V_8 -> V_19 ;
V_5 = F_4 ( V_3 -> V_7 . V_6 , V_3 -> V_20 ) ;
V_15 = F_5 ( V_5 ) ;
if ( F_6 ( V_5 ) )
goto V_21;
V_13 . V_22 = V_23 ;
if ( V_10 & V_24 ) {
V_13 . V_22 |= V_25 ;
V_13 . V_26 = 0 ;
F_7 ( V_1 ) ;
}
V_1 = F_8 ( V_9 ) -> F_9 ( V_9 , V_5 , V_10 , & V_13 , & V_14 ) ;
if ( F_6 ( V_1 ) ) {
V_15 = F_5 ( V_1 ) ;
switch ( V_15 ) {
case - V_27 :
case - V_28 :
case - V_29 :
case - V_30 :
case - V_31 :
goto V_32;
default:
goto V_33;
}
}
if ( V_1 != V_6 -> V_19 )
goto V_33;
F_10 ( V_6 , F_11 ( V_9 ) ) ;
F_12 ( V_3 , V_5 ) ;
F_13 ( V_1 , V_3 ) ;
V_15 = 0 ;
V_32:
F_14 ( V_5 ) ;
V_21:
F_15 ( V_8 ) ;
return V_15 ;
V_33:
F_16 ( V_6 ) ;
V_15 = - V_34 ;
goto V_32;
}
static int
F_17 ( struct V_2 * V_2 , T_1 V_35 , T_1 V_36 , int V_37 )
{
int V_38 ;
struct V_1 * V_1 = F_18 ( V_2 ) ;
do {
V_38 = F_19 ( V_1 -> V_39 , V_35 , V_36 ) ;
if ( V_38 != 0 )
break;
F_20 ( & V_1 -> V_40 ) ;
V_38 = F_21 ( V_2 , V_35 , V_36 , V_37 ) ;
if ( ! V_38 )
V_38 = F_22 ( V_1 , true ) ;
F_23 ( & V_1 -> V_40 ) ;
V_35 = 0 ;
V_36 = V_41 ;
} while ( V_38 == - V_42 );
return V_38 ;
}
static T_1 F_24 ( struct V_2 * V_43 , T_1 V_44 , int V_45 )
{
T_1 V_38 ;
switch ( V_45 ) {
case V_46 :
case V_47 :
V_38 = F_25 ( V_43 , V_44 , V_45 ) ;
if ( V_38 != - V_48 )
return V_38 ;
default:
return F_26 ( V_43 , V_44 , V_45 ) ;
}
}
static long F_27 ( struct V_2 * V_43 , int V_49 , T_1 V_44 , T_1 V_50 )
{
struct V_1 * V_1 = F_18 ( V_43 ) ;
long V_38 ;
if ( ! F_28 ( V_1 -> V_51 ) )
return - V_52 ;
if ( ( V_49 != 0 ) && ( V_49 != ( V_53 | V_54 ) ) )
return - V_52 ;
V_38 = F_29 ( V_1 , V_44 + V_50 ) ;
if ( V_38 < 0 )
return V_38 ;
F_20 ( & V_1 -> V_40 ) ;
if ( V_49 & V_53 )
V_38 = F_30 ( V_43 , V_44 , V_50 ) ;
else
V_38 = F_31 ( V_43 , V_44 , V_50 ) ;
F_23 ( & V_1 -> V_40 ) ;
F_32 ( V_1 ) ;
return V_38 ;
}
