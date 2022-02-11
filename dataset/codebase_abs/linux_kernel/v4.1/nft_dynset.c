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
if ( V_8 -> V_4 != NULL )
F_7 ( F_8 ( V_10 ) , V_8 -> V_4 ) ;
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
struct V_1 * V_2 ;
T_1 V_11 ;
int V_39 ;
if ( V_38 [ V_40 ] == NULL ||
V_38 [ V_41 ] == NULL ||
V_38 [ V_42 ] == NULL )
return - V_43 ;
V_2 = F_13 ( V_36 -> V_44 , V_38 [ V_40 ] ) ;
if ( F_14 ( V_2 ) ) {
if ( V_38 [ V_45 ] )
V_2 = F_15 ( V_36 -> V_46 ,
V_38 [ V_45 ] ) ;
if ( F_14 ( V_2 ) )
return F_16 ( V_2 ) ;
}
if ( V_2 -> V_47 & V_48 )
return - V_49 ;
V_8 -> V_26 = F_17 ( F_18 ( V_38 [ V_41 ] ) ) ;
switch ( V_8 -> V_26 ) {
case V_50 :
break;
case V_27 :
if ( ! ( V_2 -> V_47 & V_51 ) )
return - V_52 ;
break;
default:
return - V_52 ;
}
V_11 = 0 ;
if ( V_38 [ V_53 ] != NULL ) {
if ( ! ( V_2 -> V_47 & V_51 ) )
return - V_43 ;
V_11 = F_19 ( F_20 ( V_38 [ V_53 ] ) ) ;
}
V_8 -> V_17 = F_21 ( V_38 [ V_42 ] ) ;
V_39 = F_22 ( V_8 -> V_17 , V_2 -> V_54 ) ; ;
if ( V_39 < 0 )
return V_39 ;
if ( V_38 [ V_55 ] != NULL ) {
if ( ! ( V_2 -> V_47 & V_56 ) )
return - V_43 ;
if ( V_2 -> V_57 == V_58 )
return - V_52 ;
V_8 -> V_18 = F_21 ( V_38 [ V_55 ] ) ;
V_39 = F_22 ( V_8 -> V_18 , V_2 -> V_59 ) ;
if ( V_39 < 0 )
return V_39 ;
} else if ( V_2 -> V_47 & V_56 )
return - V_43 ;
if ( V_38 [ V_60 ] != NULL ) {
if ( ! ( V_2 -> V_47 & V_61 ) )
return - V_43 ;
if ( ! ( V_2 -> V_47 & V_62 ) )
return - V_52 ;
V_8 -> V_4 = F_23 ( V_36 , V_38 [ V_60 ] ) ;
if ( F_14 ( V_8 -> V_4 ) )
return F_16 ( V_8 -> V_4 ) ;
V_39 = - V_52 ;
if ( ! ( V_8 -> V_4 -> V_23 -> type -> V_47 & V_63 ) )
goto V_64;
} else if ( V_2 -> V_47 & V_61 )
return - V_43 ;
F_24 ( & V_8 -> V_15 ) ;
F_25 ( & V_8 -> V_15 , V_65 , V_2 -> V_54 ) ;
if ( V_2 -> V_47 & V_56 )
F_25 ( & V_8 -> V_15 , V_66 , V_2 -> V_59 ) ;
if ( V_8 -> V_4 != NULL )
F_25 ( & V_8 -> V_15 , V_25 ,
V_8 -> V_4 -> V_23 -> V_13 ) ;
if ( V_2 -> V_47 & V_51 ) {
if ( V_11 || V_2 -> V_11 )
F_26 ( & V_8 -> V_15 , V_28 ) ;
}
V_8 -> V_11 = V_11 ;
V_39 = F_27 ( V_36 , V_2 , & V_8 -> V_67 ) ;
if ( V_39 < 0 )
goto V_64;
V_8 -> V_2 = V_2 ;
return 0 ;
V_64:
if ( V_8 -> V_4 != NULL )
F_28 ( V_36 , V_8 -> V_4 ) ;
return V_39 ;
}
static void F_29 ( const struct V_35 * V_36 ,
const struct V_3 * V_4 )
{
struct V_7 * V_8 = F_2 ( V_4 ) ;
F_30 ( V_36 , V_8 -> V_2 , & V_8 -> V_67 ) ;
if ( V_8 -> V_4 != NULL )
F_28 ( V_36 , V_8 -> V_4 ) ;
}
static int F_31 ( struct V_68 * V_69 , const struct V_3 * V_4 )
{
const struct V_7 * V_8 = F_2 ( V_4 ) ;
if ( F_32 ( V_69 , V_42 , V_8 -> V_17 ) )
goto V_70;
if ( V_8 -> V_2 -> V_47 & V_56 &&
F_32 ( V_69 , V_55 , V_8 -> V_18 ) )
goto V_70;
if ( F_33 ( V_69 , V_41 , F_34 ( V_8 -> V_26 ) ) )
goto V_70;
if ( F_35 ( V_69 , V_40 , V_8 -> V_2 -> V_71 ) )
goto V_70;
if ( F_36 ( V_69 , V_53 , F_37 ( V_8 -> V_11 ) ) )
goto V_70;
if ( V_8 -> V_4 && F_38 ( V_69 , V_60 , V_8 -> V_4 ) )
goto V_70;
return 0 ;
V_70:
return - 1 ;
}
int T_2 F_39 ( void )
{
return F_40 ( & V_72 ) ;
}
void F_41 ( void )
{
F_42 ( & V_72 ) ;
}
