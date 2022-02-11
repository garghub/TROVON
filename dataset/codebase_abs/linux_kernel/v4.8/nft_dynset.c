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
if ( V_12 == NULL ) {
if ( V_2 -> V_13 )
F_5 ( & V_2 -> V_14 ) ;
return NULL ;
}
V_10 = F_6 ( V_2 , V_12 ) ;
if ( V_8 -> V_4 != NULL &&
F_7 ( F_8 ( V_10 ) , V_8 -> V_4 ) < 0 )
return NULL ;
return V_12 ;
}
static void F_9 ( const struct V_3 * V_4 ,
struct V_5 * V_6 ,
const struct V_20 * V_21 )
{
const struct V_7 * V_8 = F_2 ( V_4 ) ;
struct V_1 * V_2 = V_8 -> V_2 ;
const struct V_9 * V_10 ;
const struct V_3 * V_22 ;
T_1 V_11 ;
if ( V_2 -> V_23 -> V_24 ( V_2 , & V_6 -> V_16 [ V_8 -> V_17 ] , F_1 ,
V_4 , V_6 , & V_10 ) ) {
V_22 = NULL ;
if ( F_10 ( V_10 , V_25 ) )
V_22 = F_8 ( V_10 ) ;
if ( V_8 -> V_26 == V_27 &&
F_10 ( V_10 , V_28 ) ) {
V_11 = V_8 -> V_11 ? : V_2 -> V_11 ;
* F_11 ( V_10 ) = V_29 + V_11 ;
} else if ( V_22 == NULL )
goto V_30;
if ( V_22 != NULL )
V_22 -> V_23 -> V_31 ( V_22 , V_6 , V_21 ) ;
return;
}
V_30:
V_6 -> V_32 . V_33 = V_34 ;
}
static int F_12 ( const struct V_35 * V_36 ,
const struct V_3 * V_4 ,
const struct V_37 * const V_38 [] )
{
struct V_7 * V_8 = F_2 ( V_4 ) ;
T_2 V_39 = F_13 ( V_36 -> V_40 ) ;
struct V_1 * V_2 ;
T_1 V_11 ;
int V_41 ;
if ( V_38 [ V_42 ] == NULL ||
V_38 [ V_43 ] == NULL ||
V_38 [ V_44 ] == NULL )
return - V_45 ;
V_2 = F_14 ( V_36 -> V_46 , V_38 [ V_42 ] ,
V_39 ) ;
if ( F_15 ( V_2 ) ) {
if ( V_38 [ V_47 ] )
V_2 = F_16 ( V_36 -> V_40 ,
V_38 [ V_47 ] ,
V_39 ) ;
if ( F_15 ( V_2 ) )
return F_17 ( V_2 ) ;
}
if ( V_2 -> V_48 & V_49 )
return - V_50 ;
V_8 -> V_26 = F_18 ( F_19 ( V_38 [ V_43 ] ) ) ;
switch ( V_8 -> V_26 ) {
case V_51 :
break;
case V_27 :
if ( ! ( V_2 -> V_48 & V_52 ) )
return - V_53 ;
break;
default:
return - V_53 ;
}
V_11 = 0 ;
if ( V_38 [ V_54 ] != NULL ) {
if ( ! ( V_2 -> V_48 & V_52 ) )
return - V_45 ;
V_11 = F_20 ( F_21 ( V_38 [ V_54 ] ) ) ;
}
V_8 -> V_17 = F_22 ( V_38 [ V_44 ] ) ;
V_41 = F_23 ( V_8 -> V_17 , V_2 -> V_55 ) ; ;
if ( V_41 < 0 )
return V_41 ;
if ( V_38 [ V_56 ] != NULL ) {
if ( ! ( V_2 -> V_48 & V_57 ) )
return - V_45 ;
if ( V_2 -> V_58 == V_59 )
return - V_53 ;
V_8 -> V_18 = F_22 ( V_38 [ V_56 ] ) ;
V_41 = F_23 ( V_8 -> V_18 , V_2 -> V_60 ) ;
if ( V_41 < 0 )
return V_41 ;
} else if ( V_2 -> V_48 & V_57 )
return - V_45 ;
if ( V_38 [ V_61 ] != NULL ) {
if ( ! ( V_2 -> V_48 & V_62 ) )
return - V_45 ;
if ( ! ( V_2 -> V_48 & V_63 ) )
return - V_53 ;
V_8 -> V_4 = F_24 ( V_36 , V_38 [ V_61 ] ) ;
if ( F_15 ( V_8 -> V_4 ) )
return F_17 ( V_8 -> V_4 ) ;
V_41 = - V_53 ;
if ( ! ( V_8 -> V_4 -> V_23 -> type -> V_48 & V_64 ) )
goto V_65;
} else if ( V_2 -> V_48 & V_62 )
return - V_45 ;
F_25 ( & V_8 -> V_15 ) ;
F_26 ( & V_8 -> V_15 , V_66 , V_2 -> V_55 ) ;
if ( V_2 -> V_48 & V_57 )
F_26 ( & V_8 -> V_15 , V_67 , V_2 -> V_60 ) ;
if ( V_8 -> V_4 != NULL )
F_26 ( & V_8 -> V_15 , V_25 ,
V_8 -> V_4 -> V_23 -> V_13 ) ;
if ( V_2 -> V_48 & V_52 ) {
if ( V_11 || V_2 -> V_11 )
F_27 ( & V_8 -> V_15 , V_28 ) ;
}
V_8 -> V_11 = V_11 ;
V_41 = F_28 ( V_36 , V_2 , & V_8 -> V_68 ) ;
if ( V_41 < 0 )
goto V_65;
V_8 -> V_2 = V_2 ;
return 0 ;
V_65:
if ( V_8 -> V_4 != NULL )
F_29 ( V_36 , V_8 -> V_4 ) ;
return V_41 ;
}
static void F_30 ( const struct V_35 * V_36 ,
const struct V_3 * V_4 )
{
struct V_7 * V_8 = F_2 ( V_4 ) ;
F_31 ( V_36 , V_8 -> V_2 , & V_8 -> V_68 ) ;
if ( V_8 -> V_4 != NULL )
F_29 ( V_36 , V_8 -> V_4 ) ;
}
static int F_32 ( struct V_69 * V_70 , const struct V_3 * V_4 )
{
const struct V_7 * V_8 = F_2 ( V_4 ) ;
if ( F_33 ( V_70 , V_44 , V_8 -> V_17 ) )
goto V_71;
if ( V_8 -> V_2 -> V_48 & V_57 &&
F_33 ( V_70 , V_56 , V_8 -> V_18 ) )
goto V_71;
if ( F_34 ( V_70 , V_43 , F_35 ( V_8 -> V_26 ) ) )
goto V_71;
if ( F_36 ( V_70 , V_42 , V_8 -> V_2 -> V_72 ) )
goto V_71;
if ( F_37 ( V_70 , V_54 , F_38 ( V_8 -> V_11 ) ,
V_73 ) )
goto V_71;
if ( V_8 -> V_4 && F_39 ( V_70 , V_61 , V_8 -> V_4 ) )
goto V_71;
return 0 ;
V_71:
return - 1 ;
}
int T_3 F_40 ( void )
{
return F_41 ( & V_74 ) ;
}
void F_42 ( void )
{
F_43 ( & V_74 ) ;
}
