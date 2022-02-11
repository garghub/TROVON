void F_1 ( const struct V_1 * V_2 ,
struct V_3 * V_4 ,
const struct V_5 * V_6 )
{
const struct V_7 * V_8 = F_2 ( V_2 ) ;
const struct V_9 * V_10 = V_6 -> V_10 ;
const struct V_11 * V_12 = V_6 -> V_12 , * V_13 = V_6 -> V_13 ;
struct V_14 * V_15 ;
T_1 * V_16 = & V_4 -> V_17 [ V_8 -> V_18 ] ;
switch ( V_8 -> V_19 ) {
case V_20 :
* V_16 = V_10 -> V_21 ;
break;
case V_22 :
* V_16 = 0 ;
* ( V_23 * ) V_16 = V_10 -> V_24 ;
break;
case V_25 :
* V_16 = V_6 -> V_26 ;
break;
case V_27 :
* V_16 = V_6 -> V_28 ;
break;
case V_29 :
* V_16 = V_10 -> V_30 ;
break;
case V_31 :
* V_16 = V_10 -> V_32 ;
break;
case V_33 :
if ( V_12 == NULL )
goto V_34;
* V_16 = V_12 -> V_35 ;
break;
case V_36 :
if ( V_13 == NULL )
goto V_34;
* V_16 = V_13 -> V_35 ;
break;
case V_37 :
if ( V_12 == NULL )
goto V_34;
strncpy ( ( char * ) V_16 , V_12 -> V_38 , V_39 ) ;
break;
case V_40 :
if ( V_13 == NULL )
goto V_34;
strncpy ( ( char * ) V_16 , V_13 -> V_38 , V_39 ) ;
break;
case V_41 :
if ( V_12 == NULL )
goto V_34;
* V_16 = 0 ;
* ( V_42 * ) V_16 = V_12 -> type ;
break;
case V_43 :
if ( V_13 == NULL )
goto V_34;
* V_16 = 0 ;
* ( V_42 * ) V_16 = V_13 -> type ;
break;
case V_44 :
V_15 = F_3 ( V_10 ) ;
if ( ! V_15 || ! F_4 ( V_15 ) )
goto V_34;
F_5 ( & V_15 -> V_45 ) ;
if ( V_15 -> V_46 == NULL ||
V_15 -> V_46 -> V_47 == NULL ) {
F_6 ( & V_15 -> V_45 ) ;
goto V_34;
}
* V_16 = F_7 ( & V_48 ,
V_15 -> V_46 -> V_47 -> V_49 -> V_50 ) ;
F_6 ( & V_15 -> V_45 ) ;
break;
case V_51 :
V_15 = F_3 ( V_10 ) ;
if ( ! V_15 || ! F_4 ( V_15 ) )
goto V_34;
F_5 ( & V_15 -> V_45 ) ;
if ( V_15 -> V_46 == NULL ||
V_15 -> V_46 -> V_47 == NULL ) {
F_6 ( & V_15 -> V_45 ) ;
goto V_34;
}
* V_16 = F_8 ( & V_48 ,
V_15 -> V_46 -> V_47 -> V_49 -> V_52 ) ;
F_6 ( & V_15 -> V_45 ) ;
break;
#ifdef F_9
case V_53 : {
const struct V_54 * V_55 = F_10 ( V_10 ) ;
if ( V_55 == NULL )
goto V_34;
* V_16 = V_55 -> V_56 ;
break;
}
#endif
#ifdef F_11
case V_57 :
* V_16 = V_10 -> V_58 ;
break;
#endif
case V_59 :
if ( V_10 -> V_60 != V_61 ) {
* V_16 = V_10 -> V_60 ;
break;
}
switch ( V_6 -> V_26 ) {
case V_62 :
if ( F_12 ( F_13 ( V_10 ) -> V_63 ) )
* V_16 = V_64 ;
else
* V_16 = V_65 ;
break;
case V_66 :
if ( F_14 ( V_10 ) -> V_63 . V_67 [ 0 ] == 0xFF )
* V_16 = V_64 ;
else
* V_16 = V_65 ;
break;
default:
F_15 ( 1 ) ;
goto V_34;
}
break;
case V_68 :
* V_16 = F_16 () ;
break;
case V_69 :
if ( V_12 == NULL )
goto V_34;
* V_16 = V_12 -> V_70 ;
break;
case V_71 :
if ( V_13 == NULL )
goto V_34;
* V_16 = V_13 -> V_70 ;
break;
#ifdef F_17
case V_72 :
V_15 = F_3 ( V_10 ) ;
if ( ! V_15 || ! F_4 ( V_15 ) )
goto V_34;
* V_16 = V_15 -> V_73 ;
break;
#endif
default:
F_15 ( 1 ) ;
goto V_34;
}
return;
V_34:
V_4 -> V_74 . V_75 = V_76 ;
}
void F_18 ( const struct V_1 * V_2 ,
struct V_3 * V_4 ,
const struct V_5 * V_6 )
{
const struct V_7 * V_77 = F_2 ( V_2 ) ;
struct V_9 * V_10 = V_6 -> V_10 ;
T_1 V_78 = V_4 -> V_17 [ V_77 -> V_79 ] ;
switch ( V_77 -> V_19 ) {
case V_31 :
V_10 -> V_32 = V_78 ;
break;
case V_29 :
V_10 -> V_30 = V_78 ;
break;
case V_80 :
V_10 -> V_81 = 1 ;
break;
default:
F_15 ( 1 ) ;
}
}
int F_19 ( const struct V_82 * V_83 ,
const struct V_1 * V_2 ,
const struct V_84 * const V_85 [] )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
unsigned int V_21 ;
V_8 -> V_19 = F_20 ( F_21 ( V_85 [ V_86 ] ) ) ;
switch ( V_8 -> V_19 ) {
case V_22 :
case V_41 :
case V_43 :
V_21 = sizeof( V_42 ) ;
break;
case V_25 :
case V_27 :
case V_20 :
case V_29 :
case V_31 :
case V_33 :
case V_36 :
case V_44 :
case V_51 :
#ifdef F_9
case V_53 :
#endif
#ifdef F_11
case V_57 :
#endif
case V_59 :
case V_68 :
case V_69 :
case V_71 :
#ifdef F_17
case V_72 :
#endif
V_21 = sizeof( T_1 ) ;
break;
case V_37 :
case V_40 :
V_21 = V_39 ;
break;
default:
return - V_87 ;
}
V_8 -> V_18 = F_22 ( V_85 [ V_88 ] ) ;
return F_23 ( V_83 , V_8 -> V_18 , NULL ,
V_89 , V_21 ) ;
}
int F_24 ( const struct V_82 * V_83 ,
const struct V_1 * V_2 ,
const struct V_84 * const V_85 [] )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
unsigned int V_21 ;
int V_34 ;
V_8 -> V_19 = F_20 ( F_21 ( V_85 [ V_86 ] ) ) ;
switch ( V_8 -> V_19 ) {
case V_31 :
case V_29 :
V_21 = sizeof( T_1 ) ;
break;
case V_80 :
V_21 = sizeof( V_90 ) ;
break;
default:
return - V_87 ;
}
V_8 -> V_79 = F_22 ( V_85 [ V_91 ] ) ;
V_34 = F_25 ( V_8 -> V_79 , V_21 ) ;
if ( V_34 < 0 )
return V_34 ;
return 0 ;
}
int F_26 ( struct V_9 * V_10 ,
const struct V_1 * V_2 )
{
const struct V_7 * V_8 = F_2 ( V_2 ) ;
if ( F_27 ( V_10 , V_86 , F_28 ( V_8 -> V_19 ) ) )
goto V_92;
if ( F_29 ( V_10 , V_88 , V_8 -> V_18 ) )
goto V_92;
return 0 ;
V_92:
return - 1 ;
}
int F_30 ( struct V_9 * V_10 ,
const struct V_1 * V_2 )
{
const struct V_7 * V_8 = F_2 ( V_2 ) ;
if ( F_27 ( V_10 , V_86 , F_28 ( V_8 -> V_19 ) ) )
goto V_92;
if ( F_29 ( V_10 , V_91 , V_8 -> V_79 ) )
goto V_92;
return 0 ;
V_92:
return - 1 ;
}
static const struct V_93 *
F_31 ( const struct V_82 * V_83 ,
const struct V_84 * const V_85 [] )
{
if ( V_85 [ V_86 ] == NULL )
return F_32 ( - V_94 ) ;
if ( V_85 [ V_88 ] && V_85 [ V_91 ] )
return F_32 ( - V_94 ) ;
if ( V_85 [ V_88 ] )
return & V_95 ;
if ( V_85 [ V_91 ] )
return & V_96 ;
return F_32 ( - V_94 ) ;
}
static int T_2 F_33 ( void )
{
return F_34 ( & V_97 ) ;
}
static void T_3 F_35 ( void )
{
F_36 ( & V_97 ) ;
}
