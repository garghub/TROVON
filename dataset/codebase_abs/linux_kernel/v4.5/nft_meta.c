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
* V_16 = F_18 ( & V_15 -> V_73 ) ;
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
static bool F_19 ( T_1 V_77 )
{
return V_77 == V_78 || V_77 == V_65 ||
V_77 == V_64 || V_77 == V_79 ;
}
void F_20 ( const struct V_1 * V_2 ,
struct V_3 * V_4 ,
const struct V_5 * V_6 )
{
const struct V_7 * V_80 = F_2 ( V_2 ) ;
struct V_9 * V_10 = V_6 -> V_10 ;
T_1 V_81 = V_4 -> V_17 [ V_80 -> V_82 ] ;
switch ( V_80 -> V_19 ) {
case V_31 :
V_10 -> V_32 = V_81 ;
break;
case V_29 :
V_10 -> V_30 = V_81 ;
break;
case V_59 :
if ( V_10 -> V_60 != V_81 &&
F_19 ( V_81 ) && F_19 ( V_10 -> V_60 ) )
V_10 -> V_60 = V_81 ;
break;
case V_83 :
V_10 -> V_84 = 1 ;
break;
default:
F_15 ( 1 ) ;
}
}
int F_21 ( const struct V_85 * V_86 ,
const struct V_1 * V_2 ,
const struct V_87 * const V_88 [] )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
unsigned int V_21 ;
V_8 -> V_19 = F_22 ( F_23 ( V_88 [ V_89 ] ) ) ;
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
return - V_90 ;
}
V_8 -> V_18 = F_24 ( V_88 [ V_91 ] ) ;
return F_25 ( V_86 , V_8 -> V_18 , NULL ,
V_92 , V_21 ) ;
}
static int F_26 ( const struct V_85 * V_86 )
{
unsigned int V_93 ;
switch ( V_86 -> V_94 -> V_95 ) {
case V_96 :
V_93 = 1 << V_97 ;
break;
case V_98 :
V_93 = 1 << V_99 ;
break;
default:
return - V_90 ;
}
return F_27 ( V_86 -> V_100 , V_93 ) ;
}
int F_28 ( const struct V_85 * V_86 ,
const struct V_1 * V_2 ,
const struct V_87 * const V_88 [] )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
unsigned int V_21 ;
int V_34 ;
V_8 -> V_19 = F_22 ( F_23 ( V_88 [ V_89 ] ) ) ;
switch ( V_8 -> V_19 ) {
case V_31 :
case V_29 :
V_21 = sizeof( T_1 ) ;
break;
case V_83 :
V_21 = sizeof( V_101 ) ;
break;
case V_59 :
V_34 = F_26 ( V_86 ) ;
if ( V_34 )
return V_34 ;
V_21 = sizeof( V_101 ) ;
break;
default:
return - V_90 ;
}
V_8 -> V_82 = F_24 ( V_88 [ V_102 ] ) ;
V_34 = F_29 ( V_8 -> V_82 , V_21 ) ;
if ( V_34 < 0 )
return V_34 ;
if ( V_8 -> V_19 == V_83 )
F_30 ( & V_103 ) ;
return 0 ;
}
int F_31 ( struct V_9 * V_10 ,
const struct V_1 * V_2 )
{
const struct V_7 * V_8 = F_2 ( V_2 ) ;
if ( F_32 ( V_10 , V_89 , F_33 ( V_8 -> V_19 ) ) )
goto V_104;
if ( F_34 ( V_10 , V_91 , V_8 -> V_18 ) )
goto V_104;
return 0 ;
V_104:
return - 1 ;
}
int F_35 ( struct V_9 * V_10 ,
const struct V_1 * V_2 )
{
const struct V_7 * V_8 = F_2 ( V_2 ) ;
if ( F_32 ( V_10 , V_89 , F_33 ( V_8 -> V_19 ) ) )
goto V_104;
if ( F_34 ( V_10 , V_102 , V_8 -> V_82 ) )
goto V_104;
return 0 ;
V_104:
return - 1 ;
}
void F_36 ( const struct V_85 * V_86 ,
const struct V_1 * V_2 )
{
const struct V_7 * V_8 = F_2 ( V_2 ) ;
if ( V_8 -> V_19 == V_83 )
F_37 ( & V_103 ) ;
}
static const struct V_105 *
F_38 ( const struct V_85 * V_86 ,
const struct V_87 * const V_88 [] )
{
if ( V_88 [ V_89 ] == NULL )
return F_39 ( - V_106 ) ;
if ( V_88 [ V_91 ] && V_88 [ V_102 ] )
return F_39 ( - V_106 ) ;
if ( V_88 [ V_91 ] )
return & V_107 ;
if ( V_88 [ V_102 ] )
return & V_108 ;
return F_39 ( - V_106 ) ;
}
static int T_2 F_40 ( void )
{
return F_41 ( & V_109 ) ;
}
static void T_3 F_42 ( void )
{
F_43 ( & V_109 ) ;
}
