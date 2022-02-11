static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_6 = V_2 -> V_6 ;
if ( V_4 -> V_7 . V_8 > V_9 ||
V_4 -> V_7 . V_10 > V_9 ) {
F_2 ( V_6 -> V_11 ) ;
return - V_12 ;
}
if ( ! V_4 -> V_13 )
F_2 ( V_6 -> V_11 ) ;
if ( V_4 -> V_14 & V_15 )
F_3 ( V_6 -> V_11 ,
V_4 -> V_7 . V_16 , V_4 -> V_7 . V_17 ) ;
if ( V_4 -> V_14 & V_18 ) {
T_1 V_19 = V_4 -> V_7 . V_20 ? 0xf : 0x0 ;
T_1 V_21 = V_4 -> V_7 . V_22 ? 0xf : 0x0 ;
F_4 ( V_6 -> V_23 , 8 , V_21 ) ;
F_5 ( V_6 -> V_23 , V_21 ) ;
F_6 ( V_6 -> V_23 , V_19 ) ;
}
if ( V_4 -> V_14 & ( V_24 | V_25 | V_26 ) )
F_7 ( V_6 -> V_11 ,
V_4 -> V_7 . V_27 , V_4 -> V_28 , V_4 -> V_29 ,
V_4 -> V_7 . V_10 , V_4 -> V_7 . V_8 ) ;
if ( V_4 -> V_13 )
F_8 ( V_6 -> V_11 ) ;
return 0 ;
}
static int F_9 ( int V_30 , struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_6 ;
T_1 V_31 = V_30 ? 0x00 : 0x0f ;
F_4 ( V_6 -> V_23 , 1 , V_31 ) ;
return 0 ;
}
static int F_10 ( struct V_32 * V_33 )
{
struct V_34 * V_35 = F_11 ( V_33 ) ;
T_2 V_36 , V_37 ;
struct V_1 * V_2 ;
struct V_5 * V_6 ;
int V_38 ;
V_2 = F_12 ( sizeof( struct V_5 ) , V_33 ) ;
if ( ! V_2 ) {
F_13 ( V_39 L_1 , F_14 ( V_33 ) ) ;
return - V_40 ;
}
V_6 = V_2 -> V_6 ;
F_15 ( V_33 , V_2 ) ;
V_2 -> V_41 = & V_42 ;
V_2 -> V_43 = V_44 ;
V_2 -> V_45 = V_46 ;
V_2 -> V_47 = V_48 ;
V_36 = V_35 -> V_49 . V_36 ;
V_37 = V_35 -> V_49 . V_50 - V_36 + 1 ;
if ( ! F_16 ( V_36 , V_37 , F_14 ( V_33 ) ) ) {
F_13 ( V_39 L_2 ,
F_14 ( V_33 ) ) ;
V_38 = - V_51 ;
goto V_52;
}
V_2 -> V_43 . V_53 = V_36 + V_54 ;
V_6 -> V_55 = F_17 ( V_2 -> V_43 . V_53 , V_2 -> V_43 . V_56 ) ;
if ( ! V_6 -> V_55 ) {
F_13 ( V_39 L_3 , F_14 ( V_33 ) ) ;
V_38 = - V_40 ;
goto V_57;
}
V_6 -> V_23 = V_6 -> V_55 - V_54 + V_54 ;
V_6 -> V_11 = V_6 -> V_55 - V_54 + V_58 ;
V_2 -> V_43 . V_59 = V_36 + V_60 ;
V_2 -> V_61 = F_17 ( V_2 -> V_43 . V_59 ,
V_2 -> V_43 . V_62 ) ;
if ( ! V_2 -> V_61 ) {
F_13 ( V_39 L_4 , F_14 ( V_33 ) ) ;
V_38 = - V_40 ;
goto V_63;
}
V_2 -> V_64 = V_2 -> V_43 . V_62 ;
F_4 ( V_6 -> V_23 , 0 , 0x0 ) ;
F_5 ( V_6 -> V_23 , 0xf ) ;
F_2 ( V_6 -> V_11 ) ;
F_18 ( V_6 -> V_11 ) ;
V_38 = F_19 ( V_2 ) ;
if ( V_38 < 0 ) {
F_13 ( V_39 L_5 ,
F_14 ( V_33 ) ) ;
goto V_65;
}
F_20 ( V_33 ) ;
F_21 ( L_6 ,
V_2 -> V_66 , V_2 -> V_43 . V_67 , F_14 ( V_33 ) ) ;
return 0 ;
V_65:
F_22 ( V_2 -> V_61 ) ;
V_63:
F_22 ( V_6 -> V_55 ) ;
V_57:
F_23 ( V_36 , V_37 ) ;
V_52:
F_24 ( V_2 ) ;
return V_38 ;
}
static int T_3 F_25 ( struct V_32 * V_33 )
{
struct V_34 * V_35 = F_11 ( V_33 ) ;
struct V_1 * V_2 = F_26 ( V_33 ) ;
struct V_5 * V_6 = V_2 -> V_6 ;
T_2 V_36 , V_37 ;
F_27 ( V_33 ) ;
F_28 ( V_2 ) ;
F_22 ( V_2 -> V_61 ) ;
F_22 ( V_6 -> V_55 ) ;
V_36 = V_35 -> V_49 . V_36 ;
V_37 = V_35 -> V_49 . V_50 - V_36 + 1 ;
F_23 ( V_36 , V_37 ) ;
F_24 ( V_2 ) ;
return 0 ;
}
static int T_4 F_29 ( void )
{
#ifndef F_30
if ( F_31 ( L_7 , NULL ) )
return - V_68 ;
#endif
return F_32 ( & V_69 ) ;
}
static void T_3 F_33 ( void )
{
F_34 ( & V_69 ) ;
}
