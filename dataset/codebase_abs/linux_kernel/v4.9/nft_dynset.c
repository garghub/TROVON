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
} else if ( V_24 == NULL )
goto V_32;
if ( V_24 != NULL )
V_24 -> V_25 -> V_33 ( V_24 , V_6 , V_23 ) ;
if ( V_8 -> V_34 )
V_6 -> V_35 . V_36 = V_37 ;
return;
}
V_32:
if ( ! V_8 -> V_34 )
V_6 -> V_35 . V_36 = V_37 ;
}
static int F_13 ( const struct V_38 * V_39 ,
const struct V_3 * V_4 ,
const struct V_40 * const V_41 [] )
{
struct V_7 * V_8 = F_2 ( V_4 ) ;
T_2 V_42 = F_14 ( V_39 -> V_43 ) ;
struct V_1 * V_2 ;
T_1 V_11 ;
int V_44 ;
if ( V_41 [ V_45 ] == NULL ||
V_41 [ V_46 ] == NULL ||
V_41 [ V_47 ] == NULL )
return - V_48 ;
if ( V_41 [ V_49 ] ) {
T_3 V_50 = F_15 ( F_16 ( V_41 [ V_49 ] ) ) ;
if ( V_50 & ~ V_51 )
return - V_48 ;
if ( V_50 & V_51 )
V_8 -> V_34 = true ;
}
V_2 = F_17 ( V_39 -> V_52 , V_41 [ V_45 ] ,
V_42 ) ;
if ( F_18 ( V_2 ) ) {
if ( V_41 [ V_53 ] )
V_2 = F_19 ( V_39 -> V_43 ,
V_41 [ V_53 ] ,
V_42 ) ;
if ( F_18 ( V_2 ) )
return F_20 ( V_2 ) ;
}
if ( V_2 -> V_25 -> V_26 == NULL )
return - V_54 ;
if ( V_2 -> V_50 & V_55 )
return - V_56 ;
V_8 -> V_28 = F_15 ( F_16 ( V_41 [ V_46 ] ) ) ;
switch ( V_8 -> V_28 ) {
case V_57 :
break;
case V_29 :
if ( ! ( V_2 -> V_50 & V_58 ) )
return - V_54 ;
break;
default:
return - V_54 ;
}
V_11 = 0 ;
if ( V_41 [ V_59 ] != NULL ) {
if ( ! ( V_2 -> V_50 & V_58 ) )
return - V_48 ;
V_11 = F_21 ( F_22 ( F_23 (
V_41 [ V_59 ] ) ) ) ;
}
V_8 -> V_17 = F_24 ( V_41 [ V_47 ] ) ;
V_44 = F_25 ( V_8 -> V_17 , V_2 -> V_60 ) ; ;
if ( V_44 < 0 )
return V_44 ;
if ( V_41 [ V_61 ] != NULL ) {
if ( ! ( V_2 -> V_50 & V_62 ) )
return - V_48 ;
if ( V_2 -> V_63 == V_64 )
return - V_54 ;
V_8 -> V_18 = F_24 ( V_41 [ V_61 ] ) ;
V_44 = F_25 ( V_8 -> V_18 , V_2 -> V_65 ) ;
if ( V_44 < 0 )
return V_44 ;
} else if ( V_2 -> V_50 & V_62 )
return - V_48 ;
if ( V_41 [ V_66 ] != NULL ) {
if ( ! ( V_2 -> V_50 & V_67 ) )
return - V_48 ;
if ( ! ( V_2 -> V_50 & V_68 ) )
return - V_54 ;
V_8 -> V_4 = F_26 ( V_39 , V_41 [ V_66 ] ) ;
if ( F_18 ( V_8 -> V_4 ) )
return F_20 ( V_8 -> V_4 ) ;
V_44 = - V_54 ;
if ( ! ( V_8 -> V_4 -> V_25 -> type -> V_50 & V_69 ) )
goto V_20;
} else if ( V_2 -> V_50 & V_67 )
return - V_48 ;
F_27 ( & V_8 -> V_15 ) ;
F_28 ( & V_8 -> V_15 , V_70 , V_2 -> V_60 ) ;
if ( V_2 -> V_50 & V_62 )
F_28 ( & V_8 -> V_15 , V_71 , V_2 -> V_65 ) ;
if ( V_8 -> V_4 != NULL )
F_28 ( & V_8 -> V_15 , V_27 ,
V_8 -> V_4 -> V_25 -> V_13 ) ;
if ( V_2 -> V_50 & V_58 ) {
if ( V_11 || V_2 -> V_11 )
F_29 ( & V_8 -> V_15 , V_30 ) ;
}
V_8 -> V_11 = V_11 ;
V_44 = F_30 ( V_39 , V_2 , & V_8 -> V_72 ) ;
if ( V_44 < 0 )
goto V_20;
V_8 -> V_2 = V_2 ;
return 0 ;
V_20:
if ( V_8 -> V_4 != NULL )
F_31 ( V_39 , V_8 -> V_4 ) ;
return V_44 ;
}
static void F_32 ( const struct V_38 * V_39 ,
const struct V_3 * V_4 )
{
struct V_7 * V_8 = F_2 ( V_4 ) ;
F_33 ( V_39 , V_8 -> V_2 , & V_8 -> V_72 ) ;
if ( V_8 -> V_4 != NULL )
F_31 ( V_39 , V_8 -> V_4 ) ;
}
static int F_34 ( struct V_73 * V_74 , const struct V_3 * V_4 )
{
const struct V_7 * V_8 = F_2 ( V_4 ) ;
T_3 V_50 = V_8 -> V_34 ? V_51 : 0 ;
if ( F_35 ( V_74 , V_47 , V_8 -> V_17 ) )
goto V_75;
if ( V_8 -> V_2 -> V_50 & V_62 &&
F_35 ( V_74 , V_61 , V_8 -> V_18 ) )
goto V_75;
if ( F_36 ( V_74 , V_46 , F_37 ( V_8 -> V_28 ) ) )
goto V_75;
if ( F_38 ( V_74 , V_45 , V_8 -> V_2 -> V_76 ) )
goto V_75;
if ( F_39 ( V_74 , V_59 ,
F_40 ( F_41 ( V_8 -> V_11 ) ) ,
V_77 ) )
goto V_75;
if ( V_8 -> V_4 && F_42 ( V_74 , V_66 , V_8 -> V_4 ) )
goto V_75;
if ( F_36 ( V_74 , V_49 , F_37 ( V_50 ) ) )
goto V_75;
return 0 ;
V_75:
return - 1 ;
}
int T_4 F_43 ( void )
{
return F_44 ( & V_78 ) ;
}
void F_45 ( void )
{
F_46 ( & V_78 ) ;
}
