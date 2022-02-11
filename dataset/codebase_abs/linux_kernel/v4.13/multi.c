static int F_1 ( struct V_1 * V_2 )
{
int V_3 ;
if ( F_2 ( V_2 -> V_4 -> V_5 ) ) {
V_2 -> V_6 = V_7 ;
V_2 -> V_8 |= V_9 ;
}
V_10 = F_3 ( V_11 ) ;
if ( F_4 ( V_10 ) )
return F_5 ( V_10 ) ;
V_3 = F_6 ( V_2 , V_10 ) ;
if ( V_3 < 0 )
goto V_12;
V_13 = F_3 ( V_14 ) ;
if ( F_4 ( V_13 ) ) {
V_3 = F_5 ( V_13 ) ;
goto V_15;
}
V_3 = F_6 ( V_2 , V_13 ) ;
if ( V_3 )
goto V_16;
V_17 = F_3 ( V_18 ) ;
if ( F_4 ( V_17 ) ) {
V_3 = F_5 ( V_17 ) ;
goto V_19;
}
V_3 = F_6 ( V_2 , V_17 ) ;
if ( V_3 )
goto V_20;
return 0 ;
V_20:
F_7 ( V_17 ) ;
V_19:
F_8 ( V_2 , V_13 ) ;
V_16:
F_7 ( V_13 ) ;
V_15:
F_8 ( V_2 , V_10 ) ;
V_12:
F_7 ( V_10 ) ;
return V_3 ;
}
static T_1 int F_9 ( struct V_21 * V_4 )
{
static struct V_1 V_22 = {
. V_23 = V_24 ,
. V_8 = V_25 ,
} ;
V_22 . V_26 = V_27 [ V_28 ] . V_29 ;
V_22 . V_30 = V_27 [ V_28 ] . V_31 ;
return F_10 ( V_4 , & V_22 , F_1 ) ;
}
static T_1 int F_9 ( struct V_21 * V_4 )
{
return 0 ;
}
static int F_11 ( struct V_1 * V_2 )
{
int V_3 ;
if ( F_2 ( V_2 -> V_4 -> V_5 ) ) {
V_2 -> V_6 = V_7 ;
V_2 -> V_8 |= V_9 ;
}
V_32 = F_3 ( V_33 ) ;
if ( F_4 ( V_32 ) )
return F_5 ( V_32 ) ;
V_3 = F_6 ( V_2 , V_32 ) ;
if ( V_3 < 0 )
goto V_34;
V_35 = F_3 ( V_14 ) ;
if ( F_4 ( V_35 ) ) {
V_3 = F_5 ( V_35 ) ;
goto V_15;
}
V_3 = F_6 ( V_2 , V_35 ) ;
if ( V_3 )
goto V_16;
V_36 = F_3 ( V_18 ) ;
if ( F_4 ( V_36 ) ) {
V_3 = F_5 ( V_36 ) ;
goto V_19;
}
V_3 = F_6 ( V_2 , V_36 ) ;
if ( V_3 )
goto V_20;
return 0 ;
V_20:
F_7 ( V_36 ) ;
V_19:
F_8 ( V_2 , V_35 ) ;
V_16:
F_7 ( V_35 ) ;
V_15:
F_8 ( V_2 , V_32 ) ;
V_34:
F_7 ( V_32 ) ;
return V_3 ;
}
static T_1 int F_12 ( struct V_21 * V_4 )
{
static struct V_1 V_22 = {
. V_23 = V_37 ,
. V_8 = V_25 ,
} ;
V_22 . V_26 = V_27 [ V_38 ] . V_29 ;
V_22 . V_30 = V_27 [ V_38 ] . V_31 ;
return F_10 ( V_4 , & V_22 , F_11 ) ;
}
static T_1 int F_12 ( struct V_21 * V_4 )
{
return 0 ;
}
static int T_1 F_13 ( struct V_21 * V_4 )
{
struct V_39 * V_5 = V_4 -> V_5 ;
#ifdef F_14
struct V_40 * V_41 ;
#endif
#ifdef F_15
struct V_42 * V_43 ;
#endif
struct V_44 * V_44 ;
struct V_45 V_22 ;
int V_46 ;
if ( ! F_16 ( V_4 -> V_5 ) ) {
F_17 ( & V_5 -> V_47 , L_1 ,
V_5 -> V_48 ) ;
return - V_49 ;
}
#ifdef F_14
V_33 = F_18 ( L_2 ) ;
if ( F_4 ( V_33 ) )
return F_5 ( V_33 ) ;
V_41 = F_19 ( V_33 , struct V_40 , V_50 ) ;
F_20 ( V_41 -> V_51 , V_52 ) ;
if ( ! F_21 ( V_41 -> V_51 , V_53 ) )
F_22 ( L_3 , V_53 ) ;
if ( ! F_23 ( V_41 -> V_51 , V_54 ) )
F_22 ( L_4 , V_54 ) ;
#endif
#ifdef F_15
V_11 = F_18 ( L_5 ) ;
if ( F_4 ( V_11 ) ) {
V_46 = F_5 ( V_11 ) ;
goto V_55;
}
V_43 = F_19 ( V_11 , struct V_42 , V_50 ) ;
F_20 ( V_43 -> V_51 , V_52 ) ;
if ( ! F_21 ( V_43 -> V_51 , V_53 ) )
F_22 ( L_3 , V_53 ) ;
if ( ! F_23 ( V_43 -> V_51 , V_54 ) )
F_22 ( L_4 , V_54 ) ;
#endif
#if ( V_56 F_14 && V_56 F_15 )
F_24 ( V_41 -> V_51 , V_4 -> V_5 ) ;
V_46 = F_25 ( V_41 -> V_51 ) ;
if ( V_46 )
goto V_57;
F_26 ( V_11 , V_41 -> V_51 ) ;
V_41 -> V_58 = true ;
#endif
V_14 = F_18 ( L_6 ) ;
if ( F_4 ( V_14 ) ) {
V_46 = F_5 ( V_14 ) ;
goto V_57;
}
V_18 = F_18 ( L_7 ) ;
if ( F_4 ( V_18 ) ) {
V_46 = F_5 ( V_18 ) ;
goto V_59;
}
F_27 ( & V_22 , & V_60 , V_61 ) ;
V_44 = F_28 ( V_18 ) ;
V_44 -> V_62 = true ;
V_46 = F_29 ( V_44 -> V_63 , V_61 ) ;
if ( V_46 )
goto V_64;
V_46 = F_30 ( V_44 -> V_63 , V_4 , V_22 . V_65 ) ;
if ( V_46 )
goto V_66;
F_31 ( V_44 -> V_63 , true ) ;
V_46 = F_32 ( V_44 -> V_63 , & V_22 ) ;
if ( V_46 )
goto V_66;
F_33 ( V_44 -> V_63 , V_22 . V_67 ,
V_22 . V_68 ) ;
V_46 = F_34 ( V_4 , V_27 ) ;
if ( F_35 ( V_46 < 0 ) )
goto V_69;
V_70 . V_71 = V_27 [ V_72 ] . V_31 ;
if ( F_2 ( V_5 ) && ! V_7 [ 0 ] ) {
struct V_73 * V_74 ;
V_74 = F_36 ( V_5 ) ;
if ( ! V_74 )
goto V_69;
F_37 ( V_5 , V_74 ) ;
V_7 [ 0 ] = V_74 ;
V_7 [ 1 ] = NULL ;
}
V_46 = F_9 ( V_4 ) ;
if ( F_35 ( V_46 < 0 ) )
goto V_75;
V_46 = F_12 ( V_4 ) ;
if ( F_35 ( V_46 < 0 ) )
goto V_75;
F_38 ( V_4 , & V_76 ) ;
F_39 ( & V_5 -> V_47 , V_77 L_8 ) ;
return 0 ;
V_75:
F_40 ( V_7 [ 0 ] ) ;
V_7 [ 0 ] = NULL ;
V_69:
F_41 ( V_44 -> V_63 ) ;
V_66:
F_42 ( V_44 -> V_63 ) ;
V_64:
F_43 ( V_18 ) ;
V_59:
F_43 ( V_14 ) ;
V_57:
#ifdef F_15
F_43 ( V_11 ) ;
V_55:
#endif
#ifdef F_14
F_43 ( V_33 ) ;
#endif
return V_46 ;
}
static int F_44 ( struct V_21 * V_4 )
{
#ifdef F_14
F_7 ( V_36 ) ;
#endif
#ifdef F_15
F_7 ( V_17 ) ;
#endif
F_43 ( V_18 ) ;
#ifdef F_14
F_7 ( V_35 ) ;
#endif
#ifdef F_15
F_7 ( V_13 ) ;
#endif
F_43 ( V_14 ) ;
#ifdef F_15
F_7 ( V_10 ) ;
F_43 ( V_11 ) ;
#endif
#ifdef F_14
F_7 ( V_32 ) ;
F_43 ( V_33 ) ;
#endif
F_40 ( V_7 [ 0 ] ) ;
V_7 [ 0 ] = NULL ;
return 0 ;
}
