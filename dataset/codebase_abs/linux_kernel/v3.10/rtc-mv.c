static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
void T_1 * V_7 = V_6 -> V_7 ;
T_2 V_8 ;
V_8 = ( F_3 ( V_4 -> V_9 ) << V_10 ) |
( F_3 ( V_4 -> V_11 ) << V_12 ) |
( F_3 ( V_4 -> V_13 ) << V_14 ) |
( F_3 ( V_4 -> V_15 ) << V_16 ) ;
F_4 ( V_8 , V_7 + V_17 ) ;
V_8 = ( F_3 ( V_4 -> V_18 ) << V_19 ) |
( F_3 ( V_4 -> V_20 + 1 ) << V_21 ) |
( F_3 ( V_4 -> V_22 % 100 ) << V_23 ) ;
F_4 ( V_8 , V_7 + V_24 ) ;
return 0 ;
}
static int F_5 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
void T_1 * V_7 = V_6 -> V_7 ;
T_2 V_3 , V_25 ;
unsigned int V_26 , V_27 , V_28 , V_29 , V_30 , V_31 , V_32 ;
V_3 = F_6 ( V_7 + V_17 ) ;
V_25 = F_6 ( V_7 + V_24 ) ;
V_31 = V_3 & 0x7f ;
V_30 = ( V_3 >> V_12 ) & 0x7f ;
V_29 = ( V_3 >> V_14 ) & 0x3f ;
V_32 = ( V_3 >> V_16 ) & 0x7 ;
V_28 = V_25 & 0x3f ;
V_27 = ( V_25 >> V_21 ) & 0x3f ;
V_26 = ( V_25 >> V_23 ) & 0xff ;
V_4 -> V_9 = F_7 ( V_31 ) ;
V_4 -> V_11 = F_7 ( V_30 ) ;
V_4 -> V_13 = F_7 ( V_29 ) ;
V_4 -> V_18 = F_7 ( V_28 ) ;
V_4 -> V_15 = F_7 ( V_32 ) ;
V_4 -> V_20 = F_7 ( V_27 ) - 1 ;
V_4 -> V_22 = F_7 ( V_26 ) + 100 ;
return F_8 ( V_4 ) ;
}
static int F_9 ( struct V_1 * V_2 , struct V_33 * V_34 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
void T_1 * V_7 = V_6 -> V_7 ;
T_2 V_3 , V_25 ;
unsigned int V_26 , V_27 , V_28 , V_29 , V_30 , V_31 , V_32 ;
V_3 = F_6 ( V_7 + V_35 ) ;
V_25 = F_6 ( V_7 + V_36 ) ;
V_31 = V_3 & 0x7f ;
V_30 = ( V_3 >> V_12 ) & 0x7f ;
V_29 = ( V_3 >> V_14 ) & 0x3f ;
V_32 = ( V_3 >> V_16 ) & 0x7 ;
V_28 = V_25 & 0x3f ;
V_27 = ( V_25 >> V_21 ) & 0x3f ;
V_26 = ( V_25 >> V_23 ) & 0xff ;
V_34 -> time . V_9 = F_7 ( V_31 ) ;
V_34 -> time . V_11 = F_7 ( V_30 ) ;
V_34 -> time . V_13 = F_7 ( V_29 ) ;
V_34 -> time . V_18 = F_7 ( V_28 ) ;
V_34 -> time . V_15 = F_7 ( V_32 ) ;
V_34 -> time . V_20 = F_7 ( V_27 ) - 1 ;
V_34 -> time . V_22 = F_7 ( V_26 ) + 100 ;
if ( F_8 ( & V_34 -> time ) < 0 ) {
F_10 ( V_2 , L_1 ) ;
F_11 ( 0 , & V_34 -> time ) ;
}
V_34 -> V_37 = ! ! F_6 ( V_7 + V_38 ) ;
return 0 ;
}
static int F_12 ( struct V_1 * V_2 , struct V_33 * V_34 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
void T_1 * V_7 = V_6 -> V_7 ;
T_2 V_8 = 0 ;
if ( V_34 -> time . V_9 >= 0 )
V_8 |= ( V_39 | F_3 ( V_34 -> time . V_9 ) )
<< V_10 ;
if ( V_34 -> time . V_11 >= 0 )
V_8 |= ( V_39 | F_3 ( V_34 -> time . V_11 ) )
<< V_12 ;
if ( V_34 -> time . V_13 >= 0 )
V_8 |= ( V_39 | F_3 ( V_34 -> time . V_13 ) )
<< V_14 ;
F_4 ( V_8 , V_7 + V_35 ) ;
if ( V_34 -> time . V_18 >= 0 )
V_8 = ( V_39 | F_3 ( V_34 -> time . V_18 ) )
<< V_19 ;
else
V_8 = 0 ;
if ( V_34 -> time . V_20 >= 0 )
V_8 |= ( V_39 | F_3 ( V_34 -> time . V_20 + 1 ) )
<< V_21 ;
if ( V_34 -> time . V_22 >= 0 )
V_8 |= ( V_39 | F_3 ( V_34 -> time . V_22 % 100 ) )
<< V_23 ;
F_4 ( V_8 , V_7 + V_36 ) ;
F_4 ( 0 , V_7 + V_40 ) ;
F_4 ( V_34 -> V_37 ? 1 : 0 ,
V_7 + V_38 ) ;
return 0 ;
}
static int F_13 ( struct V_1 * V_2 , unsigned int V_37 )
{
struct V_41 * V_42 = F_14 ( V_2 ) ;
struct V_5 * V_6 = F_15 ( V_42 ) ;
void T_1 * V_7 = V_6 -> V_7 ;
if ( V_6 -> V_43 < 0 )
return - V_44 ;
if ( V_37 )
F_4 ( 1 , V_7 + V_38 ) ;
else
F_4 ( 0 , V_7 + V_38 ) ;
return 0 ;
}
static T_3 F_16 ( int V_43 , void * V_45 )
{
struct V_5 * V_6 = V_45 ;
void T_1 * V_7 = V_6 -> V_7 ;
if ( ! F_6 ( V_7 + V_40 ) )
return V_46 ;
F_4 ( 0 , V_7 + V_40 ) ;
F_17 ( V_6 -> V_47 , 1 , V_48 | V_49 ) ;
return V_50 ;
}
static int T_4 F_18 ( struct V_41 * V_42 )
{
struct V_51 * V_52 ;
struct V_5 * V_6 ;
T_5 V_53 ;
T_2 V_3 ;
int V_54 = 0 ;
V_52 = F_19 ( V_42 , V_55 , 0 ) ;
if ( ! V_52 )
return - V_56 ;
V_6 = F_20 ( & V_42 -> V_2 , sizeof( * V_6 ) , V_57 ) ;
if ( ! V_6 )
return - V_58 ;
V_53 = F_21 ( V_52 ) ;
if ( ! F_22 ( & V_42 -> V_2 , V_52 -> V_59 , V_53 ,
V_42 -> V_60 ) )
return - V_61 ;
V_6 -> V_7 = F_23 ( & V_42 -> V_2 , V_52 -> V_59 , V_53 ) ;
if ( ! V_6 -> V_7 )
return - V_58 ;
V_6 -> V_62 = F_24 ( & V_42 -> V_2 , NULL ) ;
if ( ! F_25 ( V_6 -> V_62 ) )
F_26 ( V_6 -> V_62 ) ;
V_3 = F_6 ( V_6 -> V_7 + V_17 ) ;
if ( V_3 & V_63 ) {
F_10 ( & V_42 -> V_2 , L_2 ) ;
V_54 = - V_44 ;
goto V_64;
}
if ( V_3 == 0x01000000 ) {
F_27 ( 1 ) ;
V_3 = F_6 ( V_6 -> V_7 + V_17 ) ;
if ( V_3 == 0x01000000 ) {
F_10 ( & V_42 -> V_2 , L_3 ) ;
V_54 = - V_56 ;
goto V_64;
}
}
V_6 -> V_43 = F_28 ( V_42 , 0 ) ;
F_29 ( V_42 , V_6 ) ;
if ( V_6 -> V_43 >= 0 ) {
F_30 ( & V_42 -> V_2 , 1 ) ;
V_6 -> V_47 = F_31 ( & V_42 -> V_2 , V_42 -> V_60 ,
& V_65 ,
V_66 ) ;
} else {
V_6 -> V_47 = F_31 ( & V_42 -> V_2 , V_42 -> V_60 ,
& V_67 , V_66 ) ;
}
if ( F_25 ( V_6 -> V_47 ) ) {
V_54 = F_32 ( V_6 -> V_47 ) ;
goto V_64;
}
if ( V_6 -> V_43 >= 0 ) {
F_4 ( 0 , V_6 -> V_7 + V_38 ) ;
if ( F_33 ( & V_42 -> V_2 , V_6 -> V_43 , F_16 ,
V_68 ,
V_42 -> V_60 , V_6 ) < 0 ) {
F_34 ( & V_42 -> V_2 , L_4 ) ;
V_6 -> V_43 = - 1 ;
}
}
return 0 ;
V_64:
if ( ! F_25 ( V_6 -> V_62 ) )
F_35 ( V_6 -> V_62 ) ;
return V_54 ;
}
static int T_6 F_36 ( struct V_41 * V_42 )
{
struct V_5 * V_6 = F_15 ( V_42 ) ;
if ( V_6 -> V_43 >= 0 )
F_30 ( & V_42 -> V_2 , 0 ) ;
if ( ! F_25 ( V_6 -> V_62 ) )
F_35 ( V_6 -> V_62 ) ;
return 0 ;
}
