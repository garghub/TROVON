static T_1 F_1 ( const struct V_1 * V_2 ,
enum V_3 V_4 ,
enum V_5 V_6 )
{
if ( V_6 < V_7 )
return V_4 == V_8 ? F_2 ( & V_2 [ V_6 ] . V_9 ) :
F_2 ( & V_2 [ V_6 ] . V_10 ) ;
return F_1 ( V_2 , V_4 , V_11 ) +
F_1 ( V_2 , V_4 , V_12 ) ;
}
static void F_3 ( const struct V_13 * V_14 ,
struct V_15 * V_16 ,
const struct V_17 * V_18 )
{
const struct V_19 * V_20 = F_4 ( V_14 ) ;
T_2 * V_21 = & V_16 -> V_22 [ V_20 -> V_23 ] ;
enum V_24 V_25 ;
const struct V_26 * V_27 ;
const struct V_28 * V_29 ;
const struct V_30 * V_31 ;
const struct V_32 * V_33 ;
unsigned int V_34 ;
V_27 = F_5 ( V_18 -> V_35 , & V_25 ) ;
switch ( V_20 -> V_36 ) {
case V_37 :
if ( V_27 == NULL )
V_34 = V_38 ;
else if ( F_6 ( V_27 ) )
V_34 = V_39 ;
else
V_34 = F_7 ( V_25 ) ;
* V_21 = V_34 ;
return;
default:
break;
}
if ( V_27 == NULL )
goto V_40;
switch ( V_20 -> V_36 ) {
case V_41 :
* V_21 = F_8 ( V_25 ) ;
return;
case V_42 :
* V_21 = V_27 -> V_43 ;
return;
#ifdef F_9
case V_44 :
* V_21 = V_27 -> V_45 ;
return;
#endif
#ifdef F_10
case V_46 :
* V_21 = V_27 -> V_47 ;
return;
#endif
case V_48 :
* V_21 = F_11 ( F_12 ( V_27 ) ) ;
return;
case V_49 :
if ( V_27 -> V_50 == NULL )
goto V_40;
V_29 = F_13 ( V_27 -> V_50 ) ;
if ( V_29 == NULL )
goto V_40;
V_33 = F_14 ( V_29 -> V_33 ) ;
if ( V_33 == NULL )
goto V_40;
strncpy ( ( char * ) V_21 , V_33 -> V_51 , V_52 ) ;
return;
#ifdef F_15
case V_53 : {
struct V_54 * V_55 = F_16 ( V_27 ) ;
if ( V_55 )
memcpy ( V_21 , V_55 -> V_56 , V_57 ) ;
else
memset ( V_21 , 0 , V_57 ) ;
return;
}
#endif
case V_8 :
case V_58 : {
const struct V_59 * V_60 = F_17 ( V_27 ) ;
T_1 V_61 = 0 ;
if ( V_60 )
V_61 = F_1 ( V_60 -> V_62 ,
V_20 -> V_36 , V_20 -> V_63 ) ;
memcpy ( V_21 , & V_61 , sizeof( V_61 ) ) ;
return;
}
case V_64 :
* V_21 = F_18 ( V_27 ) ;
return;
case V_65 :
* V_21 = F_19 ( V_27 ) ;
return;
default:
break;
}
V_31 = & V_27 -> V_66 [ V_20 -> V_63 ] . V_31 ;
switch ( V_20 -> V_36 ) {
case V_67 :
memcpy ( V_21 , V_31 -> V_68 . V_69 . V_70 ,
F_18 ( V_27 ) == V_71 ? 4 : 16 ) ;
return;
case V_72 :
memcpy ( V_21 , V_31 -> V_73 . V_69 . V_70 ,
F_18 ( V_27 ) == V_71 ? 4 : 16 ) ;
return;
case V_74 :
* V_21 = ( V_75 V_76 ) V_31 -> V_68 . V_77 . V_70 ;
return;
case V_78 :
* V_21 = ( V_75 V_76 ) V_31 -> V_73 . V_77 . V_70 ;
return;
default:
break;
}
return;
V_40:
V_16 -> V_79 . V_80 = V_81 ;
}
static void F_20 ( const struct V_13 * V_14 ,
struct V_15 * V_16 ,
const struct V_17 * V_18 )
{
const struct V_19 * V_20 = F_4 ( V_14 ) ;
struct V_82 * V_35 = V_18 -> V_35 ;
#ifdef F_9
T_2 V_83 = V_16 -> V_22 [ V_20 -> V_84 ] ;
#endif
enum V_24 V_25 ;
struct V_26 * V_27 ;
V_27 = F_5 ( V_35 , & V_25 ) ;
if ( V_27 == NULL )
return;
switch ( V_20 -> V_36 ) {
#ifdef F_9
case V_44 :
if ( V_27 -> V_45 != V_83 ) {
V_27 -> V_45 = V_83 ;
F_21 ( V_85 , V_27 ) ;
}
break;
#endif
#ifdef F_15
case V_53 :
F_22 ( V_27 ,
& V_16 -> V_22 [ V_20 -> V_84 ] ,
& V_16 -> V_22 [ V_20 -> V_84 ] ,
V_57 / sizeof( T_2 ) ) ;
break;
#endif
default:
break;
}
}
static int F_23 ( struct V_86 * V_86 , T_3 V_87 )
{
int V_40 ;
if ( V_87 == V_88 ) {
V_40 = F_24 ( V_86 , V_71 ) ;
if ( V_40 < 0 )
goto V_89;
V_40 = F_24 ( V_86 , V_90 ) ;
if ( V_40 < 0 )
goto V_91;
} else {
V_40 = F_24 ( V_86 , V_87 ) ;
if ( V_40 < 0 )
goto V_89;
}
return 0 ;
V_91:
F_25 ( V_86 , V_71 ) ;
V_89:
return V_40 ;
}
static void F_26 ( struct V_86 * V_86 , T_3 V_87 )
{
if ( V_87 == V_88 ) {
F_25 ( V_86 , V_71 ) ;
F_25 ( V_86 , V_90 ) ;
} else
F_25 ( V_86 , V_87 ) ;
}
static int F_27 ( const struct V_92 * V_93 ,
const struct V_13 * V_14 ,
const struct V_94 * const V_95 [] )
{
struct V_19 * V_20 = F_4 ( V_14 ) ;
unsigned int V_96 ;
int V_40 ;
V_20 -> V_36 = F_28 ( F_29 ( V_95 [ V_97 ] ) ) ;
switch ( V_20 -> V_36 ) {
case V_41 :
if ( V_95 [ V_98 ] != NULL )
return - V_99 ;
V_96 = sizeof( V_100 ) ;
break;
case V_37 :
case V_42 :
#ifdef F_9
case V_44 :
#endif
#ifdef F_10
case V_46 :
#endif
case V_48 :
if ( V_95 [ V_98 ] != NULL )
return - V_99 ;
V_96 = sizeof( T_2 ) ;
break;
#ifdef F_15
case V_53 :
if ( V_95 [ V_98 ] != NULL )
return - V_99 ;
V_96 = V_57 ;
break;
#endif
case V_49 :
if ( V_95 [ V_98 ] != NULL )
return - V_99 ;
V_96 = V_52 ;
break;
case V_64 :
case V_65 :
V_96 = sizeof( V_100 ) ;
break;
case V_67 :
case V_72 :
if ( V_95 [ V_98 ] == NULL )
return - V_99 ;
switch ( V_93 -> V_101 -> V_87 ) {
case V_71 :
V_96 = F_30 ( struct V_30 ,
V_68 . V_69 . V_102 ) ;
break;
case V_90 :
case V_88 :
V_96 = F_30 ( struct V_30 ,
V_68 . V_69 . V_103 ) ;
break;
default:
return - V_104 ;
}
break;
case V_74 :
case V_78 :
if ( V_95 [ V_98 ] == NULL )
return - V_99 ;
V_96 = F_30 ( struct V_30 , V_68 . V_77 . V_70 ) ;
break;
case V_8 :
case V_58 :
if ( V_95 [ V_98 ] == NULL )
V_20 -> V_63 = V_7 ;
V_96 = sizeof( T_1 ) ;
break;
default:
return - V_105 ;
}
if ( V_95 [ V_98 ] != NULL ) {
V_20 -> V_63 = F_31 ( V_95 [ V_98 ] ) ;
switch ( V_20 -> V_63 ) {
case V_11 :
case V_12 :
break;
default:
return - V_99 ;
}
}
V_20 -> V_23 = F_32 ( V_95 [ V_106 ] ) ;
V_40 = F_33 ( V_93 , V_20 -> V_23 , NULL ,
V_107 , V_96 ) ;
if ( V_40 < 0 )
return V_40 ;
V_40 = F_23 ( V_93 -> V_86 , V_93 -> V_101 -> V_87 ) ;
if ( V_40 < 0 )
return V_40 ;
if ( V_20 -> V_36 == V_8 || V_20 -> V_36 == V_58 )
F_34 ( V_93 -> V_86 , true ) ;
return 0 ;
}
static int F_35 ( const struct V_92 * V_93 ,
const struct V_13 * V_14 ,
const struct V_94 * const V_95 [] )
{
struct V_19 * V_20 = F_4 ( V_14 ) ;
bool V_108 = false ;
unsigned int V_96 ;
int V_40 ;
V_20 -> V_36 = F_28 ( F_29 ( V_95 [ V_97 ] ) ) ;
switch ( V_20 -> V_36 ) {
#ifdef F_9
case V_44 :
if ( V_95 [ V_98 ] )
return - V_99 ;
V_96 = F_30 ( struct V_26 , V_45 ) ;
break;
#endif
#ifdef F_15
case V_53 :
if ( V_95 [ V_98 ] )
return - V_99 ;
V_96 = V_57 ;
V_40 = F_36 ( V_93 -> V_86 , ( V_96 * V_109 ) - 1 ) ;
if ( V_40 )
return V_40 ;
V_108 = true ;
break;
#endif
default:
return - V_105 ;
}
V_20 -> V_84 = F_32 ( V_95 [ V_110 ] ) ;
V_40 = F_37 ( V_20 -> V_84 , V_96 ) ;
if ( V_40 < 0 )
goto V_89;
V_40 = F_23 ( V_93 -> V_86 , V_93 -> V_101 -> V_87 ) ;
if ( V_40 < 0 )
goto V_89;
return 0 ;
V_89:
if ( V_108 )
F_38 ( V_93 -> V_86 ) ;
return V_40 ;
}
static void F_39 ( const struct V_92 * V_93 ,
const struct V_13 * V_14 )
{
F_25 ( V_93 -> V_86 , V_93 -> V_101 -> V_87 ) ;
}
static void F_40 ( const struct V_92 * V_93 ,
const struct V_13 * V_14 )
{
struct V_19 * V_20 = F_4 ( V_14 ) ;
switch ( V_20 -> V_36 ) {
#ifdef F_15
case V_53 :
F_38 ( V_93 -> V_86 ) ;
break;
#endif
default:
break;
}
F_26 ( V_93 -> V_86 , V_93 -> V_101 -> V_87 ) ;
}
static int F_41 ( struct V_82 * V_35 , const struct V_13 * V_14 )
{
const struct V_19 * V_20 = F_4 ( V_14 ) ;
if ( F_42 ( V_35 , V_106 , V_20 -> V_23 ) )
goto V_111;
if ( F_43 ( V_35 , V_97 , F_44 ( V_20 -> V_36 ) ) )
goto V_111;
switch ( V_20 -> V_36 ) {
case V_67 :
case V_72 :
case V_74 :
case V_78 :
if ( F_45 ( V_35 , V_98 , V_20 -> V_63 ) )
goto V_111;
break;
case V_8 :
case V_58 :
if ( V_20 -> V_63 < V_7 &&
F_45 ( V_35 , V_98 , V_20 -> V_63 ) )
goto V_111;
break;
default:
break;
}
return 0 ;
V_111:
return - 1 ;
}
static int F_46 ( struct V_82 * V_35 , const struct V_13 * V_14 )
{
const struct V_19 * V_20 = F_4 ( V_14 ) ;
if ( F_42 ( V_35 , V_110 , V_20 -> V_84 ) )
goto V_111;
if ( F_43 ( V_35 , V_97 , F_44 ( V_20 -> V_36 ) ) )
goto V_111;
return 0 ;
V_111:
return - 1 ;
}
static const struct V_112 *
F_47 ( const struct V_92 * V_93 ,
const struct V_94 * const V_95 [] )
{
if ( V_95 [ V_97 ] == NULL )
return F_48 ( - V_99 ) ;
if ( V_95 [ V_106 ] && V_95 [ V_110 ] )
return F_48 ( - V_99 ) ;
if ( V_95 [ V_106 ] )
return & V_113 ;
if ( V_95 [ V_110 ] )
return & V_114 ;
return F_48 ( - V_99 ) ;
}
static void F_49 ( const struct V_13 * V_14 ,
struct V_15 * V_16 ,
const struct V_17 * V_18 )
{
struct V_82 * V_35 = V_18 -> V_35 ;
enum V_24 V_25 ;
struct V_26 * V_27 ;
V_27 = F_5 ( V_18 -> V_35 , & V_25 ) ;
if ( V_27 )
return;
V_27 = F_50 () ;
F_51 ( & V_27 -> V_115 . V_116 ) ;
V_35 -> V_117 = & V_27 -> V_115 ;
V_35 -> V_118 = V_119 ;
}
static int T_4 F_52 ( void )
{
int V_40 ;
F_53 ( V_57 > V_120 ) ;
V_40 = F_54 ( & V_121 ) ;
if ( V_40 < 0 )
return V_40 ;
V_40 = F_54 ( & V_122 ) ;
if ( V_40 < 0 )
goto V_89;
return 0 ;
V_89:
F_55 ( & V_121 ) ;
return V_40 ;
}
static void T_5 F_56 ( void )
{
F_55 ( & V_122 ) ;
F_55 ( & V_121 ) ;
}
