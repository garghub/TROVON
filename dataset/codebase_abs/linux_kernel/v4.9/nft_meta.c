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
if ( ! V_6 -> V_28 )
goto V_29;
* V_16 = V_6 -> V_30 ;
break;
case V_31 :
* V_16 = V_10 -> V_32 ;
break;
case V_33 :
* V_16 = V_10 -> V_34 ;
break;
case V_35 :
if ( V_12 == NULL )
goto V_29;
* V_16 = V_12 -> V_36 ;
break;
case V_37 :
if ( V_13 == NULL )
goto V_29;
* V_16 = V_13 -> V_36 ;
break;
case V_38 :
if ( V_12 == NULL )
goto V_29;
strncpy ( ( char * ) V_16 , V_12 -> V_39 , V_40 ) ;
break;
case V_41 :
if ( V_13 == NULL )
goto V_29;
strncpy ( ( char * ) V_16 , V_13 -> V_39 , V_40 ) ;
break;
case V_42 :
if ( V_12 == NULL )
goto V_29;
* V_16 = 0 ;
* ( V_43 * ) V_16 = V_12 -> type ;
break;
case V_44 :
if ( V_13 == NULL )
goto V_29;
* V_16 = 0 ;
* ( V_43 * ) V_16 = V_13 -> type ;
break;
case V_45 :
V_15 = F_3 ( V_10 ) ;
if ( ! V_15 || ! F_4 ( V_15 ) )
goto V_29;
F_5 ( & V_15 -> V_46 ) ;
if ( V_15 -> V_47 == NULL ||
V_15 -> V_47 -> V_48 == NULL ) {
F_6 ( & V_15 -> V_46 ) ;
goto V_29;
}
* V_16 = F_7 ( & V_49 ,
V_15 -> V_47 -> V_48 -> V_50 -> V_51 ) ;
F_6 ( & V_15 -> V_46 ) ;
break;
case V_52 :
V_15 = F_3 ( V_10 ) ;
if ( ! V_15 || ! F_4 ( V_15 ) )
goto V_29;
F_5 ( & V_15 -> V_46 ) ;
if ( V_15 -> V_47 == NULL ||
V_15 -> V_47 -> V_48 == NULL ) {
F_6 ( & V_15 -> V_46 ) ;
goto V_29;
}
* V_16 = F_8 ( & V_49 ,
V_15 -> V_47 -> V_48 -> V_50 -> V_53 ) ;
F_6 ( & V_15 -> V_46 ) ;
break;
#ifdef F_9
case V_54 : {
const struct V_55 * V_56 = F_10 ( V_10 ) ;
if ( V_56 == NULL )
goto V_29;
* V_16 = V_56 -> V_57 ;
break;
}
#endif
#ifdef F_11
case V_58 :
* V_16 = V_10 -> V_59 ;
break;
#endif
case V_60 :
if ( V_10 -> V_61 != V_62 ) {
* V_16 = V_10 -> V_61 ;
break;
}
switch ( V_6 -> V_26 ) {
case V_63 :
if ( F_12 ( F_13 ( V_10 ) -> V_64 ) )
* V_16 = V_65 ;
else
* V_16 = V_66 ;
break;
case V_67 :
if ( F_14 ( V_10 ) -> V_64 . V_68 [ 0 ] == 0xFF )
* V_16 = V_65 ;
else
* V_16 = V_66 ;
break;
default:
F_15 ( 1 ) ;
goto V_29;
}
break;
case V_69 :
* V_16 = F_16 () ;
break;
case V_70 :
if ( V_12 == NULL )
goto V_29;
* V_16 = V_12 -> V_71 ;
break;
case V_72 :
if ( V_13 == NULL )
goto V_29;
* V_16 = V_13 -> V_71 ;
break;
#ifdef F_17
case V_73 :
V_15 = F_3 ( V_10 ) ;
if ( ! V_15 || ! F_4 ( V_15 ) )
goto V_29;
* V_16 = F_18 ( & V_15 -> V_74 ) ;
break;
#endif
case V_75 : {
struct V_76 * V_77 = F_19 ( & V_78 ) ;
* V_16 = F_20 ( V_77 ) ;
break;
}
default:
F_15 ( 1 ) ;
goto V_29;
}
return;
V_29:
V_4 -> V_79 . V_80 = V_81 ;
}
void F_21 ( const struct V_1 * V_2 ,
struct V_3 * V_4 ,
const struct V_5 * V_6 )
{
const struct V_7 * V_82 = F_2 ( V_2 ) ;
struct V_9 * V_10 = V_6 -> V_10 ;
T_1 V_83 = V_4 -> V_17 [ V_82 -> V_84 ] ;
switch ( V_82 -> V_19 ) {
case V_33 :
V_10 -> V_34 = V_83 ;
break;
case V_31 :
V_10 -> V_32 = V_83 ;
break;
case V_60 :
if ( V_10 -> V_61 != V_83 &&
F_22 ( V_83 ) && F_22 ( V_10 -> V_61 ) )
V_10 -> V_61 = V_83 ;
break;
case V_85 :
V_10 -> V_86 = ! ! V_83 ;
break;
default:
F_15 ( 1 ) ;
}
}
int F_23 ( const struct V_87 * V_88 ,
const struct V_1 * V_2 ,
const struct V_89 * const V_90 [] )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
unsigned int V_21 ;
V_8 -> V_19 = F_24 ( F_25 ( V_90 [ V_91 ] ) ) ;
switch ( V_8 -> V_19 ) {
case V_22 :
case V_42 :
case V_44 :
V_21 = sizeof( V_43 ) ;
break;
case V_25 :
case V_27 :
case V_20 :
case V_31 :
case V_33 :
case V_35 :
case V_37 :
case V_45 :
case V_52 :
#ifdef F_9
case V_54 :
#endif
#ifdef F_11
case V_58 :
#endif
case V_60 :
case V_69 :
case V_70 :
case V_72 :
#ifdef F_17
case V_73 :
#endif
V_21 = sizeof( T_1 ) ;
break;
case V_38 :
case V_41 :
V_21 = V_40 ;
break;
case V_75 :
F_26 ( & V_78 ) ;
V_21 = sizeof( T_1 ) ;
break;
default:
return - V_92 ;
}
V_8 -> V_18 = F_27 ( V_90 [ V_93 ] ) ;
return F_28 ( V_88 , V_8 -> V_18 , NULL ,
V_94 , V_21 ) ;
}
int F_29 ( const struct V_87 * V_88 ,
const struct V_1 * V_2 ,
const struct V_95 * * V_17 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
unsigned int V_96 ;
if ( V_8 -> V_19 != V_60 )
return 0 ;
switch ( V_88 -> V_97 -> V_98 ) {
case V_99 :
V_96 = 1 << V_100 ;
break;
case V_101 :
V_96 = 1 << V_102 ;
break;
default:
return - V_92 ;
}
return F_30 ( V_88 -> V_103 , V_96 ) ;
}
int F_31 ( const struct V_87 * V_88 ,
const struct V_1 * V_2 ,
const struct V_89 * const V_90 [] )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
unsigned int V_21 ;
int V_29 ;
V_8 -> V_19 = F_24 ( F_25 ( V_90 [ V_91 ] ) ) ;
switch ( V_8 -> V_19 ) {
case V_33 :
case V_31 :
V_21 = sizeof( T_1 ) ;
break;
case V_85 :
V_21 = sizeof( V_104 ) ;
break;
case V_60 :
V_21 = sizeof( V_104 ) ;
break;
default:
return - V_92 ;
}
V_29 = F_29 ( V_88 , V_2 , NULL ) ;
if ( V_29 < 0 )
return V_29 ;
V_8 -> V_84 = F_27 ( V_90 [ V_105 ] ) ;
V_29 = F_32 ( V_8 -> V_84 , V_21 ) ;
if ( V_29 < 0 )
return V_29 ;
if ( V_8 -> V_19 == V_85 )
F_33 ( & V_106 ) ;
return 0 ;
}
int F_34 ( struct V_9 * V_10 ,
const struct V_1 * V_2 )
{
const struct V_7 * V_8 = F_2 ( V_2 ) ;
if ( F_35 ( V_10 , V_91 , F_36 ( V_8 -> V_19 ) ) )
goto V_107;
if ( F_37 ( V_10 , V_93 , V_8 -> V_18 ) )
goto V_107;
return 0 ;
V_107:
return - 1 ;
}
int F_38 ( struct V_9 * V_10 ,
const struct V_1 * V_2 )
{
const struct V_7 * V_8 = F_2 ( V_2 ) ;
if ( F_35 ( V_10 , V_91 , F_36 ( V_8 -> V_19 ) ) )
goto V_107;
if ( F_37 ( V_10 , V_105 , V_8 -> V_84 ) )
goto V_107;
return 0 ;
V_107:
return - 1 ;
}
void F_39 ( const struct V_87 * V_88 ,
const struct V_1 * V_2 )
{
const struct V_7 * V_8 = F_2 ( V_2 ) ;
if ( V_8 -> V_19 == V_85 )
F_40 ( & V_106 ) ;
}
static const struct V_108 *
F_41 ( const struct V_87 * V_88 ,
const struct V_89 * const V_90 [] )
{
if ( V_90 [ V_91 ] == NULL )
return F_42 ( - V_109 ) ;
if ( V_90 [ V_93 ] && V_90 [ V_105 ] )
return F_42 ( - V_109 ) ;
if ( V_90 [ V_93 ] )
return & V_110 ;
if ( V_90 [ V_105 ] )
return & V_111 ;
return F_42 ( - V_109 ) ;
}
static int T_2 F_43 ( void )
{
return F_44 ( & V_112 ) ;
}
static void T_3 F_45 ( void )
{
F_46 ( & V_112 ) ;
}
