int F_1 ( struct V_1 * V_2 , T_1 * V_3 )
{
struct V_4 * V_5 = V_4 ( V_2 ) ;
* V_3 = F_2 ( & V_5 -> V_6 ) ;
if ( * V_3 == - 1 )
return - V_7 ;
return 0 ;
}
void F_3 ( struct V_1 * V_2 , T_1 V_3 )
{
F_4 ( & V_4 ( V_2 ) -> V_6 , V_3 , V_8 ) ;
}
int F_5 ( struct V_1 * V_2 , T_1 * V_9 )
{
struct V_4 * V_5 = V_4 ( V_2 ) ;
* V_9 = F_2 ( & V_5 -> V_10 ) ;
if ( * V_9 == - 1 )
return - V_7 ;
return 0 ;
}
int F_6 ( struct V_1 * V_2 , T_1 * V_9 )
{
T_2 V_11 ;
int V_12 ;
if ( F_7 ( V_2 ) ) {
V_12 = F_8 ( V_2 , 0 , & V_11 ,
V_13 , V_14 ,
V_15 ,
V_16 , V_17 ) ;
if ( V_12 )
return V_12 ;
* V_9 = F_9 ( & V_11 ) ;
return 0 ;
}
return F_5 ( V_2 , V_9 ) ;
}
void F_10 ( struct V_1 * V_2 , T_1 V_9 )
{
F_4 ( & V_4 ( V_2 ) -> V_10 , V_9 , V_8 ) ;
}
void F_11 ( struct V_1 * V_2 , T_1 V_9 )
{
T_2 V_18 = 0 ;
int V_12 ;
if ( F_7 ( V_2 ) ) {
F_12 ( & V_18 , V_9 ) ;
V_12 = F_13 ( V_2 , V_18 , V_13 ,
V_14 , V_19 ,
V_16 , V_17 ) ;
if ( V_12 )
F_14 ( V_2 , L_1 , V_9 ) ;
} else
F_10 ( V_2 , V_9 ) ;
}
int F_15 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_4 ( V_2 ) ;
return F_16 ( & V_5 -> V_6 , V_2 -> V_20 . V_21 ,
( 1 << V_22 ) - 1 ,
V_2 -> V_20 . V_23 , 0 ) ;
}
void F_17 ( struct V_1 * V_2 )
{
F_18 ( & V_4 ( V_2 ) -> V_6 ) ;
}
int F_19 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_4 ( V_2 ) ;
return F_16 ( & V_5 -> V_10 , ( 1 << 16 ) ,
( 1 << 16 ) - 1 , V_2 -> V_20 . V_24 + 1 , 0 ) ;
}
void F_20 ( struct V_1 * V_2 )
{
F_18 ( & V_4 ( V_2 ) -> V_10 ) ;
}
int F_21 ( struct V_1 * V_2 , struct V_25 * V_26 )
{
int V_27 ;
V_26 -> V_28 = F_2 ( & V_4 ( V_2 ) -> V_29 . V_30 ) ;
if ( V_26 -> V_28 == - 1 )
return - V_7 ;
if ( F_22 ( V_2 ) )
V_27 = V_26 -> V_28 % ( ( int ) F_23 ( V_2 -> V_31 -> V_32 ,
2 ) /
V_2 -> V_20 . V_33 ) ;
else
V_27 = V_26 -> V_28 ;
V_26 -> V_34 = ( F_24 ( V_2 -> V_31 -> V_32 , 2 ) >> V_35 )
+ V_27 ;
V_26 -> V_36 = NULL ;
return 0 ;
}
void F_25 ( struct V_1 * V_2 , struct V_25 * V_26 )
{
F_4 ( & V_4 ( V_2 ) -> V_29 . V_30 , V_26 -> V_28 , V_8 ) ;
}
int F_26 ( struct V_1 * V_2 , struct V_37 * V_38 , int V_39 )
{
struct V_4 * V_5 = V_4 ( V_2 ) ;
struct V_25 * V_26 ;
int V_12 = 0 ;
int V_40 ;
if ( ! V_5 -> V_41 )
return - V_7 ;
F_27 ( & V_5 -> V_42 ) ;
if ( ! F_28 ( & V_5 -> V_43 ) )
V_26 = F_29 ( V_5 -> V_43 . V_44 , struct V_25 , V_43 ) ;
else {
if ( F_30 ( & V_5 -> V_29 . V_30 ) < V_45 ) {
V_12 = - V_7 ;
goto V_46;
}
V_26 = F_31 ( sizeof( * V_26 ) , V_47 , V_39 ) ;
if ( ! V_26 ) {
V_26 = F_32 ( sizeof( * V_26 ) , V_47 ) ;
if ( ! V_26 ) {
V_12 = - V_7 ;
goto V_46;
}
}
V_12 = F_21 ( V_2 , V_26 ) ;
if ( V_12 )
goto V_48;
V_26 -> V_36 = F_33 ( V_26 -> V_34 << V_35 , V_49 ) ;
if ( ! V_26 -> V_36 ) {
V_12 = - V_7 ;
goto V_50;
}
V_26 -> V_51 = F_34 ( V_5 -> V_41 ,
V_26 -> V_28 << V_35 ,
V_49 ) ;
if ( ! V_26 -> V_51 ) {
V_12 = - V_7 ;
goto V_52;
}
V_26 -> V_53 = 0 ;
F_35 ( & V_26 -> V_43 , & V_5 -> V_43 ) ;
}
V_40 = F_36 ( V_26 -> V_53 ) ;
V_26 -> V_53 |= 1 << V_40 ;
V_38 -> V_26 = V_26 ;
V_38 -> V_27 = 0 ;
V_38 -> V_54 = V_2 -> V_20 . V_55 / 2 ;
V_38 -> V_56 = V_26 -> V_51 + V_40 * V_2 -> V_20 . V_55 ;
if ( V_26 -> V_53 == ( 1 << V_2 -> V_20 . V_57 ) - 1 )
F_37 ( & V_26 -> V_43 ) ;
goto V_46;
V_52:
V_38 -> V_26 = NULL ;
F_38 ( V_26 -> V_36 ) ;
V_50:
F_25 ( V_2 , V_26 ) ;
V_48:
F_39 ( V_26 ) ;
V_46:
F_40 ( & V_5 -> V_42 ) ;
return V_12 ;
}
void F_41 ( struct V_1 * V_2 , struct V_37 * V_38 )
{
struct V_4 * V_5 = V_4 ( V_2 ) ;
int V_40 ;
if ( ! V_38 -> V_26 || ! V_38 -> V_26 -> V_51 )
return;
F_27 ( & V_5 -> V_42 ) ;
V_40 = ( V_38 -> V_56 - V_38 -> V_26 -> V_51 ) / V_2 -> V_20 . V_55 ;
V_38 -> V_26 -> V_53 &= ~ ( 1 << V_40 ) ;
if ( ! V_38 -> V_26 -> V_53 ) {
if ( ! F_28 ( & V_38 -> V_26 -> V_43 ) )
F_42 ( & V_38 -> V_26 -> V_43 ) ;
F_43 ( V_38 -> V_26 -> V_51 ) ;
F_38 ( V_38 -> V_26 -> V_36 ) ;
F_25 ( V_2 , V_38 -> V_26 ) ;
F_39 ( V_38 -> V_26 ) ;
} else if ( F_28 ( & V_38 -> V_26 -> V_43 ) )
F_35 ( & V_38 -> V_26 -> V_43 , & V_5 -> V_43 ) ;
F_40 ( & V_5 -> V_42 ) ;
}
int F_44 ( struct V_1 * V_2 )
{
int V_58 = F_45 ( V_2 ) ;
F_46 ( V_2 , L_2 , V_2 -> V_59 ) ;
F_46 ( V_2 , L_3 , V_2 -> V_20 . V_60 ) ;
if ( V_2 -> V_20 . V_61 <= V_58 ) {
F_47 (
V_2 , L_4 ,
V_2 -> V_20 . V_61 , V_58 ) ;
F_47 ( V_2 , L_5 ) ;
return - V_62 ;
}
return F_16 ( & V_4 ( V_2 ) -> V_29 . V_30 ,
V_2 -> V_20 . V_61 , V_2 -> V_20 . V_61 - 1 ,
V_2 -> V_20 . V_60 , 0 ) ;
}
void F_48 ( struct V_1 * V_2 )
{
F_18 ( & V_4 ( V_2 ) -> V_29 . V_30 ) ;
}
