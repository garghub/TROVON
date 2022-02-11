void F_1 ( const struct V_1 * V_2 ,
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
case V_60 :
if ( V_11 -> V_61 != V_62 ) {
V_15 -> V_4 [ 0 ] = V_11 -> V_61 ;
break;
}
switch ( V_7 -> V_24 -> V_25 ) {
case V_63 :
if ( F_10 ( F_11 ( V_11 ) -> V_64 ) )
V_15 -> V_4 [ 0 ] = V_65 ;
else
V_15 -> V_4 [ 0 ] = V_66 ;
break;
case V_67 :
if ( F_12 ( V_11 ) -> V_64 . V_68 [ 0 ] == 0xFF )
V_15 -> V_4 [ 0 ] = V_65 ;
else
V_15 -> V_4 [ 0 ] = V_66 ;
break;
default:
F_13 ( 1 ) ;
goto V_33;
}
break;
case V_69 :
V_15 -> V_4 [ 0 ] = F_14 () ;
break;
case V_70 :
if ( V_13 == NULL )
goto V_33;
V_15 -> V_4 [ 0 ] = V_13 -> V_71 ;
break;
case V_72 :
if ( V_14 == NULL )
goto V_33;
V_15 -> V_4 [ 0 ] = V_14 -> V_71 ;
break;
default:
F_13 ( 1 ) ;
goto V_33;
}
return;
V_33:
V_4 [ V_73 ] . V_74 = V_75 ;
}
void F_15 ( const struct V_1 * V_2 ,
struct V_3 V_4 [ V_5 + 1 ] ,
const struct V_6 * V_7 )
{
const struct V_8 * V_76 = F_2 ( V_2 ) ;
struct V_10 * V_11 = V_7 -> V_11 ;
T_1 V_77 = V_4 [ V_76 -> V_78 ] . V_4 [ 0 ] ;
switch ( V_76 -> V_17 ) {
case V_30 :
V_11 -> V_31 = V_77 ;
break;
case V_28 :
V_11 -> V_29 = V_77 ;
break;
case V_79 :
V_11 -> V_80 = 1 ;
break;
default:
F_13 ( 1 ) ;
}
}
int F_16 ( const struct V_81 * V_82 ,
const struct V_1 * V_2 ,
const struct V_83 * const V_84 [] )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
int V_33 ;
V_9 -> V_17 = F_17 ( F_18 ( V_84 [ V_85 ] ) ) ;
switch ( V_9 -> V_17 ) {
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
case V_60 :
case V_69 :
case V_70 :
case V_72 :
break;
default:
return - V_86 ;
}
V_9 -> V_16 = F_17 ( F_18 ( V_84 [ V_87 ] ) ) ;
V_33 = F_19 ( V_9 -> V_16 ) ;
if ( V_33 < 0 )
return V_33 ;
V_33 = F_20 ( V_82 , V_9 -> V_16 , NULL , V_88 ) ;
if ( V_33 < 0 )
return V_33 ;
return 0 ;
}
int F_21 ( const struct V_81 * V_82 ,
const struct V_1 * V_2 ,
const struct V_83 * const V_84 [] )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
int V_33 ;
V_9 -> V_17 = F_17 ( F_18 ( V_84 [ V_85 ] ) ) ;
switch ( V_9 -> V_17 ) {
case V_30 :
case V_28 :
case V_79 :
break;
default:
return - V_86 ;
}
V_9 -> V_78 = F_17 ( F_18 ( V_84 [ V_89 ] ) ) ;
V_33 = F_22 ( V_9 -> V_78 ) ;
if ( V_33 < 0 )
return V_33 ;
return 0 ;
}
int F_23 ( struct V_10 * V_11 ,
const struct V_1 * V_2 )
{
const struct V_8 * V_9 = F_2 ( V_2 ) ;
if ( F_24 ( V_11 , V_85 , F_25 ( V_9 -> V_17 ) ) )
goto V_90;
if ( F_24 ( V_11 , V_87 , F_25 ( V_9 -> V_16 ) ) )
goto V_90;
return 0 ;
V_90:
return - 1 ;
}
int F_26 ( struct V_10 * V_11 ,
const struct V_1 * V_2 )
{
const struct V_8 * V_9 = F_2 ( V_2 ) ;
if ( F_24 ( V_11 , V_85 , F_25 ( V_9 -> V_17 ) ) )
goto V_90;
if ( F_24 ( V_11 , V_89 , F_25 ( V_9 -> V_78 ) ) )
goto V_90;
return 0 ;
V_90:
return - 1 ;
}
static const struct V_91 *
F_27 ( const struct V_81 * V_82 ,
const struct V_83 * const V_84 [] )
{
if ( V_84 [ V_85 ] == NULL )
return F_28 ( - V_92 ) ;
if ( V_84 [ V_87 ] && V_84 [ V_89 ] )
return F_28 ( - V_92 ) ;
if ( V_84 [ V_87 ] )
return & V_93 ;
if ( V_84 [ V_89 ] )
return & V_94 ;
return F_28 ( - V_92 ) ;
}
static int T_2 F_29 ( void )
{
return F_30 ( & V_95 ) ;
}
static void T_3 F_31 ( void )
{
F_32 ( & V_95 ) ;
}
