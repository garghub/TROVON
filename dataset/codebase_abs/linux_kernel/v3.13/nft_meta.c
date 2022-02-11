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
V_15 -> V_4 [ 0 ] = V_11 -> V_24 ;
break;
case V_25 :
V_15 -> V_4 [ 0 ] = V_11 -> V_26 ;
break;
case V_27 :
if ( V_13 == NULL )
goto V_28;
V_15 -> V_4 [ 0 ] = V_13 -> V_29 ;
break;
case V_30 :
if ( V_14 == NULL )
goto V_28;
V_15 -> V_4 [ 0 ] = V_14 -> V_29 ;
break;
case V_31 :
if ( V_13 == NULL )
goto V_28;
strncpy ( ( char * ) V_15 -> V_4 , V_13 -> V_32 , sizeof( V_15 -> V_4 ) ) ;
break;
case V_33 :
if ( V_14 == NULL )
goto V_28;
strncpy ( ( char * ) V_15 -> V_4 , V_14 -> V_32 , sizeof( V_15 -> V_4 ) ) ;
break;
case V_34 :
if ( V_13 == NULL )
goto V_28;
* ( V_35 * ) V_15 -> V_4 = V_13 -> type ;
break;
case V_36 :
if ( V_14 == NULL )
goto V_28;
* ( V_35 * ) V_15 -> V_4 = V_14 -> type ;
break;
case V_37 :
if ( V_11 -> V_38 == NULL || V_11 -> V_38 -> V_39 == V_40 )
goto V_28;
F_3 ( & V_11 -> V_38 -> V_41 ) ;
if ( V_11 -> V_38 -> V_42 == NULL ||
V_11 -> V_38 -> V_42 -> V_43 == NULL ) {
F_4 ( & V_11 -> V_38 -> V_41 ) ;
goto V_28;
}
V_15 -> V_4 [ 0 ] =
F_5 ( & V_44 ,
V_11 -> V_38 -> V_42 -> V_43 -> V_45 -> V_46 ) ;
F_4 ( & V_11 -> V_38 -> V_41 ) ;
break;
case V_47 :
if ( V_11 -> V_38 == NULL || V_11 -> V_38 -> V_39 == V_40 )
goto V_28;
F_3 ( & V_11 -> V_38 -> V_41 ) ;
if ( V_11 -> V_38 -> V_42 == NULL ||
V_11 -> V_38 -> V_42 -> V_43 == NULL ) {
F_4 ( & V_11 -> V_38 -> V_41 ) ;
goto V_28;
}
V_15 -> V_4 [ 0 ] =
F_6 ( & V_44 ,
V_11 -> V_38 -> V_42 -> V_43 -> V_45 -> V_48 ) ;
F_4 ( & V_11 -> V_38 -> V_41 ) ;
break;
#ifdef F_7
case V_49 : {
const struct V_50 * V_51 = F_8 ( V_11 ) ;
if ( V_51 == NULL )
goto V_28;
V_15 -> V_4 [ 0 ] = V_51 -> V_52 ;
break;
}
#endif
#ifdef F_9
case V_53 :
V_15 -> V_4 [ 0 ] = V_11 -> V_54 ;
break;
#endif
default:
F_10 ( 1 ) ;
goto V_28;
}
return;
V_28:
V_4 [ V_55 ] . V_56 = V_57 ;
}
static int F_11 ( const struct V_58 * V_59 , const struct V_1 * V_2 ,
const struct V_60 * const V_61 [] )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
int V_28 ;
if ( V_61 [ V_62 ] == NULL ||
V_61 [ V_63 ] == NULL )
return - V_64 ;
V_9 -> V_17 = F_12 ( F_13 ( V_61 [ V_63 ] ) ) ;
switch ( V_9 -> V_17 ) {
case V_18 :
case V_20 :
case V_23 :
case V_25 :
case V_27 :
case V_30 :
case V_31 :
case V_33 :
case V_34 :
case V_36 :
case V_37 :
case V_47 :
#ifdef F_7
case V_49 :
#endif
#ifdef F_9
case V_53 :
#endif
break;
default:
return - V_65 ;
}
V_9 -> V_16 = F_12 ( F_13 ( V_61 [ V_62 ] ) ) ;
V_28 = F_14 ( V_9 -> V_16 ) ;
if ( V_28 < 0 )
return V_28 ;
return F_15 ( V_59 , V_9 -> V_16 , NULL , V_66 ) ;
}
static int F_16 ( struct V_10 * V_11 , const struct V_1 * V_2 )
{
const struct V_8 * V_9 = F_2 ( V_2 ) ;
if ( F_17 ( V_11 , V_62 , F_18 ( V_9 -> V_16 ) ) )
goto V_67;
if ( F_17 ( V_11 , V_63 , F_18 ( V_9 -> V_17 ) ) )
goto V_67;
return 0 ;
V_67:
return - 1 ;
}
static int T_1 F_19 ( void )
{
return F_20 ( & V_68 ) ;
}
static void T_2 F_21 ( void )
{
F_22 ( & V_68 ) ;
}
