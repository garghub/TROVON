void F_1 ( const struct V_1 * V_2 ,
struct V_3 * V_4 ,
const struct V_5 * V_6 )
{
const struct V_7 * V_8 = F_2 ( V_2 ) ;
const struct V_9 * V_10 = V_6 -> V_10 ;
const struct V_11 * V_12 = V_6 -> V_12 , * V_13 = V_6 -> V_13 ;
T_1 * V_14 = & V_4 -> V_15 [ V_8 -> V_16 ] ;
switch ( V_8 -> V_17 ) {
case V_18 :
* V_14 = V_10 -> V_19 ;
break;
case V_20 :
* V_14 = 0 ;
* ( V_21 * ) V_14 = V_10 -> V_22 ;
break;
case V_23 :
* V_14 = V_6 -> V_24 -> V_25 ;
break;
case V_26 :
* V_14 = V_6 -> V_27 ;
break;
case V_28 :
* V_14 = V_10 -> V_29 ;
break;
case V_30 :
* V_14 = V_10 -> V_31 ;
break;
case V_32 :
if ( V_12 == NULL )
goto V_33;
* V_14 = V_12 -> V_34 ;
break;
case V_35 :
if ( V_13 == NULL )
goto V_33;
* V_14 = V_13 -> V_34 ;
break;
case V_36 :
if ( V_12 == NULL )
goto V_33;
strncpy ( ( char * ) V_14 , V_12 -> V_37 , V_38 ) ;
break;
case V_39 :
if ( V_13 == NULL )
goto V_33;
strncpy ( ( char * ) V_14 , V_13 -> V_37 , V_38 ) ;
break;
case V_40 :
if ( V_12 == NULL )
goto V_33;
* V_14 = 0 ;
* ( V_41 * ) V_14 = V_12 -> type ;
break;
case V_42 :
if ( V_13 == NULL )
goto V_33;
* V_14 = 0 ;
* ( V_41 * ) V_14 = V_13 -> type ;
break;
case V_43 :
if ( V_10 -> V_44 == NULL || ! F_3 ( V_10 -> V_44 ) )
goto V_33;
F_4 ( & V_10 -> V_44 -> V_45 ) ;
if ( V_10 -> V_44 -> V_46 == NULL ||
V_10 -> V_44 -> V_46 -> V_47 == NULL ) {
F_5 ( & V_10 -> V_44 -> V_45 ) ;
goto V_33;
}
* V_14 = F_6 ( & V_48 ,
V_10 -> V_44 -> V_46 -> V_47 -> V_49 -> V_50 ) ;
F_5 ( & V_10 -> V_44 -> V_45 ) ;
break;
case V_51 :
if ( V_10 -> V_44 == NULL || ! F_3 ( V_10 -> V_44 ) )
goto V_33;
F_4 ( & V_10 -> V_44 -> V_45 ) ;
if ( V_10 -> V_44 -> V_46 == NULL ||
V_10 -> V_44 -> V_46 -> V_47 == NULL ) {
F_5 ( & V_10 -> V_44 -> V_45 ) ;
goto V_33;
}
* V_14 = F_7 ( & V_48 ,
V_10 -> V_44 -> V_46 -> V_47 -> V_49 -> V_52 ) ;
F_5 ( & V_10 -> V_44 -> V_45 ) ;
break;
#ifdef F_8
case V_53 : {
const struct V_54 * V_55 = F_9 ( V_10 ) ;
if ( V_55 == NULL )
goto V_33;
* V_14 = V_55 -> V_56 ;
break;
}
#endif
#ifdef F_10
case V_57 :
* V_14 = V_10 -> V_58 ;
break;
#endif
case V_59 :
if ( V_10 -> V_60 != V_61 ) {
* V_14 = V_10 -> V_60 ;
break;
}
switch ( V_6 -> V_24 -> V_25 ) {
case V_62 :
if ( F_11 ( F_12 ( V_10 ) -> V_63 ) )
* V_14 = V_64 ;
else
* V_14 = V_65 ;
break;
case V_66 :
if ( F_13 ( V_10 ) -> V_63 . V_67 [ 0 ] == 0xFF )
* V_14 = V_64 ;
else
* V_14 = V_65 ;
break;
default:
F_14 ( 1 ) ;
goto V_33;
}
break;
case V_68 :
* V_14 = F_15 () ;
break;
case V_69 :
if ( V_12 == NULL )
goto V_33;
* V_14 = V_12 -> V_70 ;
break;
case V_71 :
if ( V_13 == NULL )
goto V_33;
* V_14 = V_13 -> V_70 ;
break;
case V_72 :
if ( V_10 -> V_44 == NULL || ! F_3 ( V_10 -> V_44 ) )
goto V_33;
* V_14 = V_10 -> V_44 -> V_73 ;
break;
default:
F_14 ( 1 ) ;
goto V_33;
}
return;
V_33:
V_4 -> V_74 . V_75 = V_76 ;
}
void F_16 ( const struct V_1 * V_2 ,
struct V_3 * V_4 ,
const struct V_5 * V_6 )
{
const struct V_7 * V_77 = F_2 ( V_2 ) ;
struct V_9 * V_10 = V_6 -> V_10 ;
T_1 V_78 = V_4 -> V_15 [ V_77 -> V_79 ] ;
switch ( V_77 -> V_17 ) {
case V_30 :
V_10 -> V_31 = V_78 ;
break;
case V_28 :
V_10 -> V_29 = V_78 ;
break;
case V_80 :
V_10 -> V_81 = 1 ;
break;
default:
F_14 ( 1 ) ;
}
}
int F_17 ( const struct V_82 * V_83 ,
const struct V_1 * V_2 ,
const struct V_84 * const V_85 [] )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
unsigned int V_19 ;
V_8 -> V_17 = F_18 ( F_19 ( V_85 [ V_86 ] ) ) ;
switch ( V_8 -> V_17 ) {
case V_20 :
case V_40 :
case V_42 :
V_19 = sizeof( V_41 ) ;
break;
case V_23 :
case V_26 :
case V_18 :
case V_28 :
case V_30 :
case V_32 :
case V_35 :
case V_43 :
case V_51 :
#ifdef F_8
case V_53 :
#endif
#ifdef F_10
case V_57 :
#endif
case V_59 :
case V_68 :
case V_69 :
case V_71 :
case V_72 :
V_19 = sizeof( T_1 ) ;
break;
case V_36 :
case V_39 :
V_19 = V_38 ;
break;
default:
return - V_87 ;
}
V_8 -> V_16 = F_20 ( V_85 [ V_88 ] ) ;
return F_21 ( V_83 , V_8 -> V_16 , NULL ,
V_89 , V_19 ) ;
}
int F_22 ( const struct V_82 * V_83 ,
const struct V_1 * V_2 ,
const struct V_84 * const V_85 [] )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
unsigned int V_19 ;
int V_33 ;
V_8 -> V_17 = F_18 ( F_19 ( V_85 [ V_86 ] ) ) ;
switch ( V_8 -> V_17 ) {
case V_30 :
case V_28 :
V_19 = sizeof( T_1 ) ;
break;
case V_80 :
V_19 = sizeof( V_90 ) ;
break;
default:
return - V_87 ;
}
V_8 -> V_79 = F_20 ( V_85 [ V_91 ] ) ;
V_33 = F_23 ( V_8 -> V_79 , V_19 ) ;
if ( V_33 < 0 )
return V_33 ;
return 0 ;
}
int F_24 ( struct V_9 * V_10 ,
const struct V_1 * V_2 )
{
const struct V_7 * V_8 = F_2 ( V_2 ) ;
if ( F_25 ( V_10 , V_86 , F_26 ( V_8 -> V_17 ) ) )
goto V_92;
if ( F_27 ( V_10 , V_88 , V_8 -> V_16 ) )
goto V_92;
return 0 ;
V_92:
return - 1 ;
}
int F_28 ( struct V_9 * V_10 ,
const struct V_1 * V_2 )
{
const struct V_7 * V_8 = F_2 ( V_2 ) ;
if ( F_25 ( V_10 , V_86 , F_26 ( V_8 -> V_17 ) ) )
goto V_92;
if ( F_27 ( V_10 , V_91 , V_8 -> V_79 ) )
goto V_92;
return 0 ;
V_92:
return - 1 ;
}
static const struct V_93 *
F_29 ( const struct V_82 * V_83 ,
const struct V_84 * const V_85 [] )
{
if ( V_85 [ V_86 ] == NULL )
return F_30 ( - V_94 ) ;
if ( V_85 [ V_88 ] && V_85 [ V_91 ] )
return F_30 ( - V_94 ) ;
if ( V_85 [ V_88 ] )
return & V_95 ;
if ( V_85 [ V_91 ] )
return & V_96 ;
return F_30 ( - V_94 ) ;
}
static int T_2 F_31 ( void )
{
return F_32 ( & V_97 ) ;
}
static void T_3 F_33 ( void )
{
F_34 ( & V_97 ) ;
}
