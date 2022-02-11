static T_1 F_1 ( struct V_1 * V_2 )
{
return F_2 ( V_2 -> V_3 ) / 1000 ;
}
static int F_3 ( struct V_4 * V_5 )
{
struct V_1 * V_2 = F_4 ( V_5 ) ;
struct V_6 * V_7 ;
int V_8 , V_9 ;
if ( ! F_5 ( & V_5 -> V_2 ) )
return - V_10 ;
V_9 = F_6 ( F_5 ( & V_5 -> V_2 ) , & V_7 ) ;
if ( V_9 )
return - V_10 ;
V_2 -> V_11 . V_12 = - 1 ;
if ( V_7 -> V_13 . V_14 && ! F_7 ( V_7 -> V_13 . V_14 , 0 , & V_8 ) )
V_2 -> V_11 . V_12 = V_8 ;
V_2 -> V_15 = 32 ;
V_2 -> V_16 = 32 ;
return 0 ;
}
static inline int F_3 ( struct V_4 * V_5 )
{
return - V_10 ;
}
static int F_8 ( struct V_4 * V_5 )
{
struct V_1 * V_2 ;
struct V_17 * V_18 ;
struct V_19 * V_20 , * V_21 ;
int V_22 , V_23 ;
V_20 = F_9 ( V_5 , V_24 , 0 ) ;
if ( ! V_20 ) {
F_10 ( & V_5 -> V_2 , L_1 ) ;
return - V_25 ;
}
V_22 = F_11 ( V_5 , 0 ) ;
if ( V_22 < 0 ) {
F_10 ( & V_5 -> V_2 , L_2 ) ;
return V_22 ;
}
V_21 = F_12 ( V_20 -> V_26 , F_13 ( V_20 ) ,
V_5 -> V_27 ) ;
if ( ! V_21 ) {
F_10 ( & V_5 -> V_2 , L_3 ) ;
return - V_28 ;
}
V_2 = F_14 ( sizeof( struct V_1 ) , V_29 ) ;
if ( ! V_2 ) {
V_23 = - V_30 ;
goto V_31;
}
F_15 ( & V_2 -> V_32 ) ;
F_16 ( & V_2 -> V_33 ) ;
V_2 -> V_2 = F_17 ( & V_5 -> V_2 ) ;
V_2 -> V_22 = V_22 ;
F_18 ( V_5 , V_2 ) ;
V_2 -> V_3 = F_19 ( & V_5 -> V_2 , NULL ) ;
V_2 -> V_34 = F_1 ;
if ( F_20 ( V_2 -> V_3 ) ) {
V_23 = - V_10 ;
goto V_35;
}
F_21 ( V_2 -> V_3 ) ;
V_2 -> V_36 =
V_37 |
V_38 |
V_39 |
V_40 |
V_41 |
V_42 ;
V_2 -> V_43 = V_44 | V_45 |
V_46 | V_47 ;
V_2 -> V_48 = F_22 ( V_20 -> V_26 , F_13 ( V_20 ) ) ;
if ( V_2 -> V_48 == NULL ) {
F_10 ( & V_5 -> V_2 , L_4 ) ;
V_23 = - V_28 ;
goto V_49;
}
V_23 = F_3 ( V_5 ) ;
if ( V_23 ) {
T_1 V_50 = F_23 ( V_2 ) ;
V_2 -> V_15 = ( ( V_50 >> 16 ) & 0xff ) + 1 ;
V_2 -> V_16 = ( ( V_50 >> 8 ) & 0xff ) + 1 ;
V_2 -> V_11 . V_12 = V_5 -> V_51 ;
}
V_23 = F_24 ( V_2 ) ;
if ( V_23 )
goto V_52;
F_25 ( V_2 ) ;
V_23 = F_26 ( V_2 -> V_22 , V_53 , V_54 , V_5 -> V_27 , V_2 ) ;
if ( V_23 ) {
F_10 ( & V_5 -> V_2 , L_5 , V_2 -> V_22 ) ;
goto V_52;
}
V_18 = & V_2 -> V_11 ;
F_27 ( V_18 , V_2 ) ;
V_18 -> V_55 = V_56 ;
V_18 -> V_57 = V_58 ;
F_28 ( V_18 -> V_27 , L_6 ,
sizeof( V_18 -> V_27 ) ) ;
V_18 -> V_59 = & V_60 ;
V_18 -> V_2 . V_61 = & V_5 -> V_2 ;
V_18 -> V_2 . V_62 = V_5 -> V_2 . V_62 ;
V_23 = F_29 ( V_18 ) ;
if ( V_23 ) {
F_10 ( & V_5 -> V_2 , L_7 ) ;
goto V_63;
}
F_30 ( V_18 ) ;
F_31 ( V_18 ) ;
F_32 ( & V_5 -> V_2 ) ;
F_33 ( & V_5 -> V_2 ) ;
F_34 ( & V_5 -> V_2 ) ;
return 0 ;
V_63:
F_35 ( V_2 -> V_22 , V_2 ) ;
V_52:
F_36 ( V_2 -> V_48 ) ;
V_49:
F_37 ( V_2 -> V_3 ) ;
F_38 ( V_2 -> V_3 ) ;
V_2 -> V_3 = NULL ;
V_35:
F_39 ( & V_5 -> V_2 ) ;
F_40 ( V_2 ) ;
V_31:
F_41 ( V_20 -> V_26 , F_13 ( V_20 ) ) ;
return V_23 ;
}
static int F_42 ( struct V_4 * V_5 )
{
struct V_1 * V_2 = F_4 ( V_5 ) ;
struct V_19 * V_20 ;
F_43 ( & V_5 -> V_2 ) ;
F_44 ( & V_2 -> V_11 ) ;
F_39 ( & V_5 -> V_2 ) ;
F_37 ( V_2 -> V_3 ) ;
F_38 ( V_2 -> V_3 ) ;
V_2 -> V_3 = NULL ;
F_45 ( V_2 ) ;
F_35 ( V_2 -> V_22 , V_2 ) ;
F_40 ( V_2 ) ;
F_34 ( & V_5 -> V_2 ) ;
F_46 ( & V_5 -> V_2 ) ;
V_20 = F_9 ( V_5 , V_24 , 0 ) ;
F_41 ( V_20 -> V_26 , F_13 ( V_20 ) ) ;
return 0 ;
}
static int F_47 ( struct V_64 * V_2 )
{
struct V_4 * V_5 = F_48 ( V_2 ) ;
struct V_1 * V_65 = F_4 ( V_5 ) ;
F_37 ( V_65 -> V_3 ) ;
return 0 ;
}
static int F_49 ( struct V_64 * V_2 )
{
struct V_4 * V_5 = F_48 ( V_2 ) ;
struct V_1 * V_65 = F_4 ( V_5 ) ;
F_21 ( V_65 -> V_3 ) ;
F_24 ( V_65 ) ;
return 0 ;
}
static int T_2 F_50 ( void )
{
return F_51 ( & V_66 , F_8 ) ;
}
static void T_3 F_52 ( void )
{
F_53 ( & V_66 ) ;
}
