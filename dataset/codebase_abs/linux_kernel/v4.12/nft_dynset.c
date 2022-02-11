static void * F_1 ( struct V_1 * V_2 , const struct V_3 * V_4 ,
struct V_5 * V_6 )
{
const struct V_7 * V_8 = F_2 ( V_4 ) ;
struct V_9 * V_10 ;
T_1 V_11 ;
void * V_12 ;
if ( V_2 -> V_13 && ! F_3 ( & V_2 -> V_14 , 1 , V_2 -> V_13 ) )
return NULL ;
V_11 = V_8 -> V_11 ? : V_2 -> V_11 ;
V_12 = F_4 ( V_2 , & V_8 -> V_15 ,
& V_6 -> V_16 [ V_8 -> V_17 ] ,
& V_6 -> V_16 [ V_8 -> V_18 ] ,
V_11 , V_19 ) ;
if ( V_12 == NULL )
goto V_20;
V_10 = F_5 ( V_2 , V_12 ) ;
if ( V_8 -> V_4 != NULL &&
F_6 ( F_7 ( V_10 ) , V_8 -> V_4 ) < 0 )
goto V_21;
return V_12 ;
V_21:
F_8 ( V_2 , V_12 , false ) ;
V_20:
if ( V_2 -> V_13 )
F_9 ( & V_2 -> V_14 ) ;
return NULL ;
}
static void F_10 ( const struct V_3 * V_4 ,
struct V_5 * V_6 ,
const struct V_22 * V_23 )
{
const struct V_7 * V_8 = F_2 ( V_4 ) ;
struct V_1 * V_2 = V_8 -> V_2 ;
const struct V_9 * V_10 ;
const struct V_3 * V_24 ;
T_1 V_11 ;
if ( V_2 -> V_25 -> V_26 ( V_2 , & V_6 -> V_16 [ V_8 -> V_17 ] , F_1 ,
V_4 , V_6 , & V_10 ) ) {
V_24 = NULL ;
if ( F_11 ( V_10 , V_27 ) )
V_24 = F_7 ( V_10 ) ;
if ( V_8 -> V_28 == V_29 &&
F_11 ( V_10 , V_30 ) ) {
V_11 = V_8 -> V_11 ? : V_2 -> V_11 ;
* F_12 ( V_10 ) = V_31 + V_11 ;
}
if ( V_24 != NULL )
V_24 -> V_25 -> V_32 ( V_24 , V_6 , V_23 ) ;
if ( V_8 -> V_33 )
V_6 -> V_34 . V_35 = V_36 ;
return;
}
if ( ! V_8 -> V_33 )
V_6 -> V_34 . V_35 = V_36 ;
}
static int F_13 ( const struct V_37 * V_38 ,
const struct V_3 * V_4 ,
const struct V_39 * const V_40 [] )
{
struct V_7 * V_8 = F_2 ( V_4 ) ;
T_2 V_41 = F_14 ( V_38 -> V_42 ) ;
struct V_1 * V_2 ;
T_1 V_11 ;
int V_43 ;
if ( V_40 [ V_44 ] == NULL ||
V_40 [ V_45 ] == NULL ||
V_40 [ V_46 ] == NULL )
return - V_47 ;
if ( V_40 [ V_48 ] ) {
T_3 V_49 = F_15 ( F_16 ( V_40 [ V_48 ] ) ) ;
if ( V_49 & ~ V_50 )
return - V_47 ;
if ( V_49 & V_50 )
V_8 -> V_33 = true ;
}
V_2 = F_17 ( V_38 -> V_42 , V_38 -> V_51 , V_40 [ V_44 ] ,
V_40 [ V_52 ] , V_41 ) ;
if ( F_18 ( V_2 ) )
return F_19 ( V_2 ) ;
if ( V_2 -> V_25 -> V_26 == NULL )
return - V_53 ;
if ( V_2 -> V_49 & V_54 )
return - V_55 ;
V_8 -> V_28 = F_15 ( F_16 ( V_40 [ V_45 ] ) ) ;
switch ( V_8 -> V_28 ) {
case V_56 :
break;
case V_29 :
if ( ! ( V_2 -> V_49 & V_57 ) )
return - V_53 ;
break;
default:
return - V_53 ;
}
V_11 = 0 ;
if ( V_40 [ V_58 ] != NULL ) {
if ( ! ( V_2 -> V_49 & V_57 ) )
return - V_47 ;
V_11 = F_20 ( F_21 ( F_22 (
V_40 [ V_58 ] ) ) ) ;
}
V_8 -> V_17 = F_23 ( V_40 [ V_46 ] ) ;
V_43 = F_24 ( V_8 -> V_17 , V_2 -> V_59 ) ; ;
if ( V_43 < 0 )
return V_43 ;
if ( V_40 [ V_60 ] != NULL ) {
if ( ! ( V_2 -> V_49 & V_61 ) )
return - V_47 ;
if ( V_2 -> V_62 == V_63 )
return - V_53 ;
V_8 -> V_18 = F_23 ( V_40 [ V_60 ] ) ;
V_43 = F_24 ( V_8 -> V_18 , V_2 -> V_64 ) ;
if ( V_43 < 0 )
return V_43 ;
} else if ( V_2 -> V_49 & V_61 )
return - V_47 ;
if ( V_40 [ V_65 ] != NULL ) {
if ( ! ( V_2 -> V_49 & V_66 ) )
return - V_47 ;
if ( ! ( V_2 -> V_49 & V_67 ) )
return - V_53 ;
V_8 -> V_4 = F_25 ( V_38 , V_40 [ V_65 ] ) ;
if ( F_18 ( V_8 -> V_4 ) )
return F_19 ( V_8 -> V_4 ) ;
V_43 = - V_53 ;
if ( ! ( V_8 -> V_4 -> V_25 -> type -> V_49 & V_68 ) )
goto V_20;
} else if ( V_2 -> V_49 & V_66 )
return - V_47 ;
F_26 ( & V_8 -> V_15 ) ;
F_27 ( & V_8 -> V_15 , V_69 , V_2 -> V_59 ) ;
if ( V_2 -> V_49 & V_61 )
F_27 ( & V_8 -> V_15 , V_70 , V_2 -> V_64 ) ;
if ( V_8 -> V_4 != NULL )
F_27 ( & V_8 -> V_15 , V_27 ,
V_8 -> V_4 -> V_25 -> V_13 ) ;
if ( V_2 -> V_49 & V_57 ) {
if ( V_11 || V_2 -> V_11 )
F_28 ( & V_8 -> V_15 , V_30 ) ;
}
V_8 -> V_11 = V_11 ;
V_43 = F_29 ( V_38 , V_2 , & V_8 -> V_71 ) ;
if ( V_43 < 0 )
goto V_20;
V_8 -> V_2 = V_2 ;
return 0 ;
V_20:
if ( V_8 -> V_4 != NULL )
F_30 ( V_38 , V_8 -> V_4 ) ;
return V_43 ;
}
static void F_31 ( const struct V_37 * V_38 ,
const struct V_3 * V_4 )
{
struct V_7 * V_8 = F_2 ( V_4 ) ;
F_32 ( V_38 , V_8 -> V_2 , & V_8 -> V_71 ) ;
if ( V_8 -> V_4 != NULL )
F_30 ( V_38 , V_8 -> V_4 ) ;
}
static int F_33 ( struct V_72 * V_73 , const struct V_3 * V_4 )
{
const struct V_7 * V_8 = F_2 ( V_4 ) ;
T_3 V_49 = V_8 -> V_33 ? V_50 : 0 ;
if ( F_34 ( V_73 , V_46 , V_8 -> V_17 ) )
goto V_74;
if ( V_8 -> V_2 -> V_49 & V_61 &&
F_34 ( V_73 , V_60 , V_8 -> V_18 ) )
goto V_74;
if ( F_35 ( V_73 , V_45 , F_36 ( V_8 -> V_28 ) ) )
goto V_74;
if ( F_37 ( V_73 , V_44 , V_8 -> V_2 -> V_75 ) )
goto V_74;
if ( F_38 ( V_73 , V_58 ,
F_39 ( F_40 ( V_8 -> V_11 ) ) ,
V_76 ) )
goto V_74;
if ( V_8 -> V_4 && F_41 ( V_73 , V_65 , V_8 -> V_4 ) )
goto V_74;
if ( F_35 ( V_73 , V_48 , F_36 ( V_49 ) ) )
goto V_74;
return 0 ;
V_74:
return - 1 ;
}
