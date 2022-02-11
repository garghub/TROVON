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
F_4 ( & V_4 ( V_2 ) -> V_6 , V_3 ) ;
}
int F_5 ( struct V_1 * V_2 , T_1 * V_8 )
{
struct V_4 * V_5 = V_4 ( V_2 ) ;
* V_8 = F_2 ( & V_5 -> V_9 ) ;
if ( * V_8 == - 1 )
return - V_7 ;
return 0 ;
}
int F_6 ( struct V_1 * V_2 , T_1 * V_8 )
{
T_2 V_10 ;
int V_11 ;
if ( F_7 ( V_2 ) ) {
V_11 = F_8 ( V_2 , 0 , & V_10 ,
V_12 , V_13 ,
V_14 ,
V_15 , V_16 ) ;
if ( V_11 )
return V_11 ;
* V_8 = F_9 ( & V_10 ) ;
return 0 ;
}
return F_5 ( V_2 , V_8 ) ;
}
void F_10 ( struct V_1 * V_2 , T_1 V_8 )
{
F_4 ( & V_4 ( V_2 ) -> V_9 , V_8 ) ;
}
void F_11 ( struct V_1 * V_2 , T_1 V_8 )
{
T_2 V_17 = 0 ;
int V_11 ;
if ( F_7 ( V_2 ) ) {
F_12 ( & V_17 , V_8 ) ;
V_11 = F_13 ( V_2 , V_17 , V_12 ,
V_13 , V_18 ,
V_15 , V_16 ) ;
if ( V_11 )
F_14 ( V_2 , L_1 , V_8 ) ;
} else
F_10 ( V_2 , V_8 ) ;
}
int F_15 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_4 ( V_2 ) ;
return F_16 ( & V_5 -> V_6 , V_2 -> V_19 . V_20 ,
( 1 << V_21 ) - 1 ,
V_2 -> V_19 . V_22 , 0 ) ;
}
void F_17 ( struct V_1 * V_2 )
{
F_18 ( & V_4 ( V_2 ) -> V_6 ) ;
}
int F_19 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_4 ( V_2 ) ;
return F_16 ( & V_5 -> V_9 , ( 1 << 16 ) ,
( 1 << 16 ) - 1 , V_2 -> V_19 . V_23 + 1 , 0 ) ;
}
void F_20 ( struct V_1 * V_2 )
{
F_18 ( & V_4 ( V_2 ) -> V_9 ) ;
}
int F_21 ( struct V_1 * V_2 , struct V_24 * V_25 )
{
int V_26 ;
V_25 -> V_27 = F_2 ( & V_4 ( V_2 ) -> V_28 . V_29 ) ;
if ( V_25 -> V_27 == - 1 )
return - V_7 ;
if ( F_22 ( V_2 ) )
V_26 = V_25 -> V_27 % ( ( int ) F_23 ( V_2 -> V_30 , 2 ) /
V_2 -> V_19 . V_31 ) ;
else
V_26 = V_25 -> V_27 ;
V_25 -> V_32 = ( F_24 ( V_2 -> V_30 , 2 ) >> V_33 ) + V_26 ;
V_25 -> V_34 = NULL ;
return 0 ;
}
void F_25 ( struct V_1 * V_2 , struct V_24 * V_25 )
{
F_4 ( & V_4 ( V_2 ) -> V_28 . V_29 , V_25 -> V_27 ) ;
}
int F_26 ( struct V_1 * V_2 , struct V_35 * V_36 )
{
struct V_4 * V_5 = V_4 ( V_2 ) ;
struct V_24 * V_25 ;
int V_11 = 0 ;
int V_37 ;
if ( ! V_5 -> V_38 )
return - V_7 ;
F_27 ( & V_5 -> V_39 ) ;
if ( ! F_28 ( & V_5 -> V_40 ) )
V_25 = F_29 ( V_5 -> V_40 . V_41 , struct V_24 , V_40 ) ;
else {
if ( F_30 ( & V_5 -> V_28 . V_29 ) < V_42 ) {
V_11 = - V_7 ;
goto V_43;
}
V_25 = F_31 ( sizeof *V_25 , V_44 ) ;
if ( ! V_25 ) {
V_11 = - V_7 ;
goto V_43;
}
V_11 = F_21 ( V_2 , V_25 ) ;
if ( V_11 )
goto V_45;
V_25 -> V_34 = F_32 ( V_25 -> V_32 << V_33 , V_46 ) ;
if ( ! V_25 -> V_34 ) {
V_11 = - V_7 ;
goto V_47;
}
V_25 -> V_48 = F_33 ( V_5 -> V_38 , V_25 -> V_27 << V_33 ) ;
if ( ! V_25 -> V_48 ) {
V_11 = - V_7 ;
goto V_49;
}
V_25 -> V_50 = 0 ;
F_34 ( & V_25 -> V_40 , & V_5 -> V_40 ) ;
}
V_36 -> V_25 = V_25 ;
V_37 = F_35 ( V_25 -> V_50 ) ;
V_25 -> V_50 |= 1 << V_37 ;
V_36 -> V_25 = V_25 ;
V_36 -> V_26 = 0 ;
V_36 -> V_51 = V_2 -> V_19 . V_52 / 2 ;
V_36 -> V_53 = V_25 -> V_48 + V_37 * V_2 -> V_19 . V_52 ;
if ( V_25 -> V_50 == ( 1 << V_2 -> V_19 . V_54 ) - 1 )
F_36 ( & V_25 -> V_40 ) ;
goto V_43;
V_49:
V_36 -> V_25 = NULL ;
F_37 ( V_25 -> V_34 ) ;
V_47:
F_25 ( V_2 , V_25 ) ;
V_45:
F_38 ( V_25 ) ;
V_43:
F_39 ( & V_5 -> V_39 ) ;
return V_11 ;
}
void F_40 ( struct V_1 * V_2 , struct V_35 * V_36 )
{
struct V_4 * V_5 = V_4 ( V_2 ) ;
int V_37 ;
if ( ! V_36 -> V_25 || ! V_36 -> V_25 -> V_48 )
return;
F_27 ( & V_5 -> V_39 ) ;
V_37 = ( V_36 -> V_53 - V_36 -> V_25 -> V_48 ) / V_2 -> V_19 . V_52 ;
V_36 -> V_25 -> V_50 &= ~ ( 1 << V_37 ) ;
if ( ! V_36 -> V_25 -> V_50 ) {
if ( ! F_28 ( & V_36 -> V_25 -> V_40 ) )
F_41 ( & V_36 -> V_25 -> V_40 ) ;
F_42 ( V_36 -> V_25 -> V_48 ) ;
F_37 ( V_36 -> V_25 -> V_34 ) ;
F_25 ( V_2 , V_36 -> V_25 ) ;
F_38 ( V_36 -> V_25 ) ;
} else if ( F_28 ( & V_36 -> V_25 -> V_40 ) )
F_34 ( & V_36 -> V_25 -> V_40 , & V_5 -> V_40 ) ;
F_39 ( & V_5 -> V_39 ) ;
}
int F_43 ( struct V_1 * V_2 )
{
if ( V_2 -> V_19 . V_55 <= 128 ) {
F_44 ( V_2 , L_2 ,
V_2 -> V_19 . V_55 ) ;
F_44 ( V_2 , L_3 ) ;
return - V_56 ;
}
return F_16 ( & V_4 ( V_2 ) -> V_28 . V_29 ,
V_2 -> V_19 . V_55 , V_2 -> V_19 . V_55 - 1 ,
V_2 -> V_19 . V_57 , 0 ) ;
}
void F_45 ( struct V_1 * V_2 )
{
F_18 ( & V_4 ( V_2 ) -> V_28 . V_29 ) ;
}
