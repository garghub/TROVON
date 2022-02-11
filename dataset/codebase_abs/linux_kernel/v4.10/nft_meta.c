void F_1 ( const struct V_1 * V_2 ,
struct V_3 * V_4 ,
const struct V_5 * V_6 )
{
const struct V_7 * V_8 = F_2 ( V_2 ) ;
const struct V_9 * V_10 = V_6 -> V_10 ;
const struct V_11 * V_12 = F_3 ( V_6 ) , * V_13 = F_4 ( V_6 ) ;
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
* V_16 = F_5 ( V_6 ) ;
break;
case V_26 :
if ( ! V_6 -> V_27 )
goto V_28;
* V_16 = V_6 -> V_29 ;
break;
case V_30 :
* V_16 = V_10 -> V_31 ;
break;
case V_32 :
* V_16 = V_10 -> V_33 ;
break;
case V_34 :
if ( V_12 == NULL )
goto V_28;
* V_16 = V_12 -> V_35 ;
break;
case V_36 :
if ( V_13 == NULL )
goto V_28;
* V_16 = V_13 -> V_35 ;
break;
case V_37 :
if ( V_12 == NULL )
goto V_28;
strncpy ( ( char * ) V_16 , V_12 -> V_38 , V_39 ) ;
break;
case V_40 :
if ( V_13 == NULL )
goto V_28;
strncpy ( ( char * ) V_16 , V_13 -> V_38 , V_39 ) ;
break;
case V_41 :
if ( V_12 == NULL )
goto V_28;
* V_16 = 0 ;
* ( V_42 * ) V_16 = V_12 -> type ;
break;
case V_43 :
if ( V_13 == NULL )
goto V_28;
* V_16 = 0 ;
* ( V_42 * ) V_16 = V_13 -> type ;
break;
case V_44 :
V_15 = F_6 ( V_10 ) ;
if ( ! V_15 || ! F_7 ( V_15 ) )
goto V_28;
F_8 ( & V_15 -> V_45 ) ;
if ( V_15 -> V_46 == NULL ||
V_15 -> V_46 -> V_47 == NULL ) {
F_9 ( & V_15 -> V_45 ) ;
goto V_28;
}
* V_16 = F_10 ( & V_48 ,
V_15 -> V_46 -> V_47 -> V_49 -> V_50 ) ;
F_9 ( & V_15 -> V_45 ) ;
break;
case V_51 :
V_15 = F_6 ( V_10 ) ;
if ( ! V_15 || ! F_7 ( V_15 ) )
goto V_28;
F_8 ( & V_15 -> V_45 ) ;
if ( V_15 -> V_46 == NULL ||
V_15 -> V_46 -> V_47 == NULL ) {
F_9 ( & V_15 -> V_45 ) ;
goto V_28;
}
* V_16 = F_11 ( & V_48 ,
V_15 -> V_46 -> V_47 -> V_49 -> V_52 ) ;
F_9 ( & V_15 -> V_45 ) ;
break;
#ifdef F_12
case V_53 : {
const struct V_54 * V_55 = F_13 ( V_10 ) ;
if ( V_55 == NULL )
goto V_28;
* V_16 = V_55 -> V_56 ;
break;
}
#endif
#ifdef F_14
case V_57 :
* V_16 = V_10 -> V_58 ;
break;
#endif
case V_59 :
if ( V_10 -> V_60 != V_61 ) {
* V_16 = V_10 -> V_60 ;
break;
}
switch ( F_5 ( V_6 ) ) {
case V_62 :
if ( F_15 ( F_16 ( V_10 ) -> V_63 ) )
* V_16 = V_64 ;
else
* V_16 = V_65 ;
break;
case V_66 :
if ( F_17 ( V_10 ) -> V_63 . V_67 [ 0 ] == 0xFF )
* V_16 = V_64 ;
else
* V_16 = V_65 ;
break;
default:
F_18 ( 1 ) ;
goto V_28;
}
break;
case V_68 :
* V_16 = F_19 () ;
break;
case V_69 :
if ( V_12 == NULL )
goto V_28;
* V_16 = V_12 -> V_70 ;
break;
case V_71 :
if ( V_13 == NULL )
goto V_28;
* V_16 = V_13 -> V_70 ;
break;
#ifdef F_20
case V_72 :
V_15 = F_6 ( V_10 ) ;
if ( ! V_15 || ! F_7 ( V_15 ) )
goto V_28;
* V_16 = F_21 ( & V_15 -> V_73 ) ;
break;
#endif
case V_74 : {
struct V_75 * V_76 = F_22 ( & V_77 ) ;
* V_16 = F_23 ( V_76 ) ;
break;
}
default:
F_18 ( 1 ) ;
goto V_28;
}
return;
V_28:
V_4 -> V_78 . V_79 = V_80 ;
}
void F_24 ( const struct V_1 * V_2 ,
struct V_3 * V_4 ,
const struct V_5 * V_6 )
{
const struct V_7 * V_81 = F_2 ( V_2 ) ;
struct V_9 * V_10 = V_6 -> V_10 ;
T_1 V_82 = V_4 -> V_17 [ V_81 -> V_83 ] ;
switch ( V_81 -> V_19 ) {
case V_32 :
V_10 -> V_33 = V_82 ;
break;
case V_30 :
V_10 -> V_31 = V_82 ;
break;
case V_59 :
if ( V_10 -> V_60 != V_82 &&
F_25 ( V_82 ) && F_25 ( V_10 -> V_60 ) )
V_10 -> V_60 = V_82 ;
break;
case V_84 :
V_10 -> V_85 = ! ! V_82 ;
break;
default:
F_18 ( 1 ) ;
}
}
int F_26 ( const struct V_86 * V_87 ,
const struct V_1 * V_2 ,
const struct V_88 * const V_89 [] )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
unsigned int V_21 ;
V_8 -> V_19 = F_27 ( F_28 ( V_89 [ V_90 ] ) ) ;
switch ( V_8 -> V_19 ) {
case V_22 :
case V_41 :
case V_43 :
V_21 = sizeof( V_42 ) ;
break;
case V_25 :
case V_26 :
case V_20 :
case V_30 :
case V_32 :
case V_34 :
case V_36 :
case V_44 :
case V_51 :
#ifdef F_12
case V_53 :
#endif
#ifdef F_14
case V_57 :
#endif
case V_59 :
case V_68 :
case V_69 :
case V_71 :
#ifdef F_20
case V_72 :
#endif
V_21 = sizeof( T_1 ) ;
break;
case V_37 :
case V_40 :
V_21 = V_39 ;
break;
case V_74 :
F_29 ( & V_77 ) ;
V_21 = sizeof( T_1 ) ;
break;
default:
return - V_91 ;
}
V_8 -> V_18 = F_30 ( V_89 [ V_92 ] ) ;
return F_31 ( V_87 , V_8 -> V_18 , NULL ,
V_93 , V_21 ) ;
}
int F_32 ( const struct V_86 * V_87 ,
const struct V_1 * V_2 ,
const struct V_94 * * V_17 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
unsigned int V_95 ;
if ( V_8 -> V_19 != V_59 )
return 0 ;
switch ( V_87 -> V_96 -> V_97 ) {
case V_98 :
V_95 = 1 << V_99 ;
break;
case V_100 :
V_95 = 1 << V_101 ;
break;
case V_62 :
case V_66 :
case V_102 :
V_95 = 1 << V_103 ;
break;
default:
return - V_91 ;
}
return F_33 ( V_87 -> V_104 , V_95 ) ;
}
int F_34 ( const struct V_86 * V_87 ,
const struct V_1 * V_2 ,
const struct V_88 * const V_89 [] )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
unsigned int V_21 ;
int V_28 ;
V_8 -> V_19 = F_27 ( F_28 ( V_89 [ V_90 ] ) ) ;
switch ( V_8 -> V_19 ) {
case V_32 :
case V_30 :
V_21 = sizeof( T_1 ) ;
break;
case V_84 :
V_21 = sizeof( V_105 ) ;
break;
case V_59 :
V_21 = sizeof( V_105 ) ;
break;
default:
return - V_91 ;
}
V_28 = F_32 ( V_87 , V_2 , NULL ) ;
if ( V_28 < 0 )
return V_28 ;
V_8 -> V_83 = F_30 ( V_89 [ V_106 ] ) ;
V_28 = F_35 ( V_8 -> V_83 , V_21 ) ;
if ( V_28 < 0 )
return V_28 ;
if ( V_8 -> V_19 == V_84 )
F_36 ( & V_107 ) ;
return 0 ;
}
int F_37 ( struct V_9 * V_10 ,
const struct V_1 * V_2 )
{
const struct V_7 * V_8 = F_2 ( V_2 ) ;
if ( F_38 ( V_10 , V_90 , F_39 ( V_8 -> V_19 ) ) )
goto V_108;
if ( F_40 ( V_10 , V_92 , V_8 -> V_18 ) )
goto V_108;
return 0 ;
V_108:
return - 1 ;
}
int F_41 ( struct V_9 * V_10 ,
const struct V_1 * V_2 )
{
const struct V_7 * V_8 = F_2 ( V_2 ) ;
if ( F_38 ( V_10 , V_90 , F_39 ( V_8 -> V_19 ) ) )
goto V_108;
if ( F_40 ( V_10 , V_106 , V_8 -> V_83 ) )
goto V_108;
return 0 ;
V_108:
return - 1 ;
}
void F_42 ( const struct V_86 * V_87 ,
const struct V_1 * V_2 )
{
const struct V_7 * V_8 = F_2 ( V_2 ) ;
if ( V_8 -> V_19 == V_84 )
F_43 ( & V_107 ) ;
}
static const struct V_109 *
F_44 ( const struct V_86 * V_87 ,
const struct V_88 * const V_89 [] )
{
if ( V_89 [ V_90 ] == NULL )
return F_45 ( - V_110 ) ;
if ( V_89 [ V_92 ] && V_89 [ V_106 ] )
return F_45 ( - V_110 ) ;
if ( V_89 [ V_92 ] )
return & V_111 ;
if ( V_89 [ V_106 ] )
return & V_112 ;
return F_45 ( - V_110 ) ;
}
static int T_2 F_46 ( void )
{
return F_47 ( & V_113 ) ;
}
static void T_3 F_48 ( void )
{
F_49 ( & V_113 ) ;
}
