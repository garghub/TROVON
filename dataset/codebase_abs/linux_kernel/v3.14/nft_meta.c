static void F_1 ( const struct V_1 * V_2 ,
struct V_3 V_4 [ V_5 + 1 ] ,
const struct V_6 * V_7 )
{
const struct V_8 * V_9 = F_2 ( V_2 ) ;
const struct V_10 * V_11 = V_7 -> V_11 ;
const struct V_12 * V_13 = V_7 -> V_13 , * V_14 = V_7 -> V_14 ;
struct V_3 * V_15 = & V_4 [ V_9 -> V_16 ] ;
switch ( V_9 -> V_17 ) {
case V_18 :
V_15 -> V_4 [ 0 ] = V_11 -> V_19 ;
break;
case V_20 :
* ( V_21 * ) V_15 -> V_4 = V_11 -> V_22 ;
break;
case V_23 :
V_15 -> V_4 [ 0 ] = V_7 -> V_24 -> V_25 ;
break;
case V_26 :
V_15 -> V_4 [ 0 ] = V_7 -> V_27 ;
break;
case V_28 :
V_15 -> V_4 [ 0 ] = V_11 -> V_29 ;
break;
case V_30 :
V_15 -> V_4 [ 0 ] = V_11 -> V_31 ;
break;
case V_32 :
if ( V_13 == NULL )
goto V_33;
V_15 -> V_4 [ 0 ] = V_13 -> V_34 ;
break;
case V_35 :
if ( V_14 == NULL )
goto V_33;
V_15 -> V_4 [ 0 ] = V_14 -> V_34 ;
break;
case V_36 :
if ( V_13 == NULL )
goto V_33;
strncpy ( ( char * ) V_15 -> V_4 , V_13 -> V_37 , sizeof( V_15 -> V_4 ) ) ;
break;
case V_38 :
if ( V_14 == NULL )
goto V_33;
strncpy ( ( char * ) V_15 -> V_4 , V_14 -> V_37 , sizeof( V_15 -> V_4 ) ) ;
break;
case V_39 :
if ( V_13 == NULL )
goto V_33;
* ( V_40 * ) V_15 -> V_4 = V_13 -> type ;
break;
case V_41 :
if ( V_14 == NULL )
goto V_33;
* ( V_40 * ) V_15 -> V_4 = V_14 -> type ;
break;
case V_42 :
if ( V_11 -> V_43 == NULL || V_11 -> V_43 -> V_44 == V_45 )
goto V_33;
F_3 ( & V_11 -> V_43 -> V_46 ) ;
if ( V_11 -> V_43 -> V_47 == NULL ||
V_11 -> V_43 -> V_47 -> V_48 == NULL ) {
F_4 ( & V_11 -> V_43 -> V_46 ) ;
goto V_33;
}
V_15 -> V_4 [ 0 ] =
F_5 ( & V_49 ,
V_11 -> V_43 -> V_47 -> V_48 -> V_50 -> V_51 ) ;
F_4 ( & V_11 -> V_43 -> V_46 ) ;
break;
case V_52 :
if ( V_11 -> V_43 == NULL || V_11 -> V_43 -> V_44 == V_45 )
goto V_33;
F_3 ( & V_11 -> V_43 -> V_46 ) ;
if ( V_11 -> V_43 -> V_47 == NULL ||
V_11 -> V_43 -> V_47 -> V_48 == NULL ) {
F_4 ( & V_11 -> V_43 -> V_46 ) ;
goto V_33;
}
V_15 -> V_4 [ 0 ] =
F_6 ( & V_49 ,
V_11 -> V_43 -> V_47 -> V_48 -> V_50 -> V_53 ) ;
F_4 ( & V_11 -> V_43 -> V_46 ) ;
break;
#ifdef F_7
case V_54 : {
const struct V_55 * V_56 = F_8 ( V_11 ) ;
if ( V_56 == NULL )
goto V_33;
V_15 -> V_4 [ 0 ] = V_56 -> V_57 ;
break;
}
#endif
#ifdef F_9
case V_58 :
V_15 -> V_4 [ 0 ] = V_11 -> V_59 ;
break;
#endif
default:
F_10 ( 1 ) ;
goto V_33;
}
return;
V_33:
V_4 [ V_60 ] . V_61 = V_62 ;
}
static void F_11 ( const struct V_1 * V_2 ,
struct V_3 V_4 [ V_5 + 1 ] ,
const struct V_6 * V_7 )
{
const struct V_8 * V_63 = F_2 ( V_2 ) ;
struct V_10 * V_11 = V_7 -> V_11 ;
T_1 V_64 = V_4 [ V_63 -> V_65 ] . V_4 [ 0 ] ;
switch ( V_63 -> V_17 ) {
case V_30 :
V_11 -> V_31 = V_64 ;
break;
case V_28 :
V_11 -> V_29 = V_64 ;
break;
case V_66 :
V_11 -> V_67 = 1 ;
break;
default:
F_10 ( 1 ) ;
}
}
static int F_12 ( T_2 V_17 )
{
switch ( V_17 ) {
case V_30 :
case V_28 :
case V_66 :
return 0 ;
default:
return - V_68 ;
}
}
static int F_13 ( T_2 V_17 )
{
switch ( V_17 ) {
case V_18 :
case V_20 :
case V_23 :
case V_26 :
case V_28 :
case V_30 :
case V_32 :
case V_35 :
case V_36 :
case V_38 :
case V_39 :
case V_41 :
case V_42 :
case V_52 :
#ifdef F_7
case V_54 :
#endif
#ifdef F_9
case V_58 :
#endif
return 0 ;
default:
return - V_68 ;
}
}
static int F_14 ( const struct V_69 * V_70 , const struct V_1 * V_2 ,
const struct V_71 * const V_72 [] )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
int V_33 ;
V_9 -> V_17 = F_15 ( F_16 ( V_72 [ V_73 ] ) ) ;
if ( V_72 [ V_74 ] ) {
V_33 = F_13 ( V_9 -> V_17 ) ;
if ( V_33 < 0 )
return V_33 ;
V_9 -> V_16 = F_15 ( F_16 ( V_72 [ V_74 ] ) ) ;
V_33 = F_17 ( V_9 -> V_16 ) ;
if ( V_33 < 0 )
return V_33 ;
return F_18 ( V_70 , V_9 -> V_16 , NULL ,
V_75 ) ;
}
V_33 = F_12 ( V_9 -> V_17 ) ;
if ( V_33 < 0 )
return V_33 ;
V_9 -> V_65 = F_15 ( F_16 ( V_72 [ V_76 ] ) ) ;
V_33 = F_19 ( V_9 -> V_65 ) ;
if ( V_33 < 0 )
return V_33 ;
return 0 ;
}
static int F_20 ( struct V_10 * V_11 ,
const struct V_1 * V_2 )
{
const struct V_8 * V_9 = F_2 ( V_2 ) ;
if ( F_21 ( V_11 , V_73 , F_22 ( V_9 -> V_17 ) ) )
goto V_77;
if ( F_21 ( V_11 , V_74 , F_22 ( V_9 -> V_16 ) ) )
goto V_77;
return 0 ;
V_77:
return - 1 ;
}
static int F_23 ( struct V_10 * V_11 ,
const struct V_1 * V_2 )
{
const struct V_8 * V_9 = F_2 ( V_2 ) ;
if ( F_21 ( V_11 , V_73 , F_22 ( V_9 -> V_17 ) ) )
goto V_77;
if ( F_21 ( V_11 , V_76 , F_22 ( V_9 -> V_65 ) ) )
goto V_77;
return 0 ;
V_77:
return - 1 ;
}
static const struct V_78 *
F_24 ( const struct V_69 * V_70 ,
const struct V_71 * const V_72 [] )
{
if ( V_72 [ V_73 ] == NULL )
return F_25 ( - V_79 ) ;
if ( V_72 [ V_74 ] && V_72 [ V_76 ] )
return F_25 ( - V_79 ) ;
if ( V_72 [ V_74 ] )
return & V_80 ;
if ( V_72 [ V_76 ] )
return & V_81 ;
return F_25 ( - V_79 ) ;
}
static int T_3 F_26 ( void )
{
return F_27 ( & V_82 ) ;
}
static void T_4 F_28 ( void )
{
F_29 ( & V_82 ) ;
}
