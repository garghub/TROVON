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
unsigned int V_56 ;
if ( ! V_55 ) {
memset ( V_21 , 0 , V_57 ) ;
return;
}
V_56 = V_55 -> V_58 * sizeof( long ) ;
memcpy ( V_21 , V_55 -> V_59 , V_56 ) ;
if ( V_56 < V_57 )
memset ( ( ( char * ) V_21 ) + V_56 , 0 ,
V_57 - V_56 ) ;
return;
}
#endif
case V_8 :
case V_60 : {
const struct V_61 * V_62 = F_17 ( V_27 ) ;
T_1 V_63 = 0 ;
if ( V_62 )
V_63 = F_1 ( V_62 -> V_64 ,
V_20 -> V_36 , V_20 -> V_65 ) ;
memcpy ( V_21 , & V_63 , sizeof( V_63 ) ) ;
return;
}
default:
break;
}
V_31 = & V_27 -> V_66 [ V_20 -> V_65 ] . V_31 ;
switch ( V_20 -> V_36 ) {
case V_67 :
* V_21 = F_18 ( V_27 ) ;
return;
case V_68 :
memcpy ( V_21 , V_31 -> V_69 . V_70 . V_71 ,
F_18 ( V_27 ) == V_72 ? 4 : 16 ) ;
return;
case V_73 :
memcpy ( V_21 , V_31 -> V_74 . V_70 . V_71 ,
F_18 ( V_27 ) == V_72 ? 4 : 16 ) ;
return;
case V_75 :
* V_21 = F_19 ( V_27 ) ;
return;
case V_76 :
* V_21 = ( V_77 V_78 ) V_31 -> V_69 . V_79 . V_71 ;
return;
case V_80 :
* V_21 = ( V_77 V_78 ) V_31 -> V_74 . V_79 . V_71 ;
return;
default:
break;
}
return;
V_40:
V_16 -> V_81 . V_82 = V_83 ;
}
static void F_20 ( const struct V_13 * V_14 ,
struct V_15 * V_16 ,
const struct V_17 * V_18 )
{
const struct V_19 * V_20 = F_4 ( V_14 ) ;
struct V_84 * V_35 = V_18 -> V_35 ;
#ifdef F_9
T_2 V_85 = V_16 -> V_22 [ V_20 -> V_86 ] ;
#endif
enum V_24 V_25 ;
struct V_26 * V_27 ;
V_27 = F_5 ( V_35 , & V_25 ) ;
if ( V_27 == NULL )
return;
switch ( V_20 -> V_36 ) {
#ifdef F_9
case V_44 :
if ( V_27 -> V_45 != V_85 ) {
V_27 -> V_45 = V_85 ;
F_21 ( V_87 , V_27 ) ;
}
break;
#endif
#ifdef F_15
case V_53 :
F_22 ( V_27 ,
& V_16 -> V_22 [ V_20 -> V_86 ] ,
& V_16 -> V_22 [ V_20 -> V_86 ] ,
V_57 / sizeof( T_2 ) ) ;
break;
#endif
default:
break;
}
}
static int F_23 ( T_3 V_88 )
{
int V_40 ;
if ( V_88 == V_89 ) {
V_40 = F_24 ( V_72 ) ;
if ( V_40 < 0 )
goto V_90;
V_40 = F_24 ( V_91 ) ;
if ( V_40 < 0 )
goto V_92;
} else {
V_40 = F_24 ( V_88 ) ;
if ( V_40 < 0 )
goto V_90;
}
return 0 ;
V_92:
F_25 ( V_72 ) ;
V_90:
return V_40 ;
}
static void F_26 ( T_3 V_88 )
{
if ( V_88 == V_89 ) {
F_25 ( V_72 ) ;
F_25 ( V_91 ) ;
} else
F_25 ( V_88 ) ;
}
static int F_27 ( const struct V_93 * V_94 ,
const struct V_13 * V_14 ,
const struct V_95 * const V_96 [] )
{
struct V_19 * V_20 = F_4 ( V_14 ) ;
unsigned int V_97 ;
int V_40 ;
V_20 -> V_36 = F_28 ( F_29 ( V_96 [ V_98 ] ) ) ;
switch ( V_20 -> V_36 ) {
case V_41 :
if ( V_96 [ V_99 ] != NULL )
return - V_100 ;
V_97 = sizeof( V_101 ) ;
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
if ( V_96 [ V_99 ] != NULL )
return - V_100 ;
V_97 = sizeof( T_2 ) ;
break;
#ifdef F_15
case V_53 :
if ( V_96 [ V_99 ] != NULL )
return - V_100 ;
V_97 = V_57 ;
break;
#endif
case V_49 :
if ( V_96 [ V_99 ] != NULL )
return - V_100 ;
V_97 = V_52 ;
break;
case V_67 :
case V_75 :
if ( V_96 [ V_99 ] == NULL )
return - V_100 ;
V_97 = sizeof( V_101 ) ;
break;
case V_68 :
case V_73 :
if ( V_96 [ V_99 ] == NULL )
return - V_100 ;
switch ( V_94 -> V_102 -> V_88 ) {
case V_72 :
V_97 = F_30 ( struct V_30 ,
V_69 . V_70 . V_103 ) ;
break;
case V_91 :
case V_89 :
V_97 = F_30 ( struct V_30 ,
V_69 . V_70 . V_104 ) ;
break;
default:
return - V_105 ;
}
break;
case V_76 :
case V_80 :
if ( V_96 [ V_99 ] == NULL )
return - V_100 ;
V_97 = F_30 ( struct V_30 , V_69 . V_79 . V_71 ) ;
break;
case V_8 :
case V_60 :
if ( V_96 [ V_99 ] == NULL )
V_20 -> V_65 = V_7 ;
V_97 = sizeof( T_1 ) ;
break;
default:
return - V_106 ;
}
if ( V_96 [ V_99 ] != NULL ) {
V_20 -> V_65 = F_31 ( V_96 [ V_99 ] ) ;
switch ( V_20 -> V_65 ) {
case V_11 :
case V_12 :
break;
default:
return - V_100 ;
}
}
V_20 -> V_23 = F_32 ( V_96 [ V_107 ] ) ;
V_40 = F_33 ( V_94 , V_20 -> V_23 , NULL ,
V_108 , V_97 ) ;
if ( V_40 < 0 )
return V_40 ;
V_40 = F_23 ( V_94 -> V_102 -> V_88 ) ;
if ( V_40 < 0 )
return V_40 ;
return 0 ;
}
static int F_34 ( const struct V_93 * V_94 ,
const struct V_13 * V_14 ,
const struct V_95 * const V_96 [] )
{
struct V_19 * V_20 = F_4 ( V_14 ) ;
unsigned int V_97 ;
int V_40 ;
V_20 -> V_36 = F_28 ( F_29 ( V_96 [ V_98 ] ) ) ;
switch ( V_20 -> V_36 ) {
#ifdef F_9
case V_44 :
V_97 = F_30 ( struct V_26 , V_45 ) ;
break;
#endif
#ifdef F_15
case V_53 :
if ( V_96 [ V_99 ] )
return - V_100 ;
V_97 = V_57 ;
V_40 = F_35 ( V_94 -> V_109 , ( V_97 * V_110 ) - 1 ) ;
if ( V_40 )
return V_40 ;
break;
#endif
default:
return - V_106 ;
}
V_20 -> V_86 = F_32 ( V_96 [ V_111 ] ) ;
V_40 = F_36 ( V_20 -> V_86 , V_97 ) ;
if ( V_40 < 0 )
return V_40 ;
V_40 = F_23 ( V_94 -> V_102 -> V_88 ) ;
if ( V_40 < 0 )
return V_40 ;
return 0 ;
}
static void F_37 ( const struct V_93 * V_94 ,
const struct V_13 * V_14 )
{
struct V_19 * V_20 = F_4 ( V_14 ) ;
switch ( V_20 -> V_36 ) {
#ifdef F_15
case V_53 :
F_38 ( V_94 -> V_109 ) ;
break;
#endif
default:
break;
}
F_26 ( V_94 -> V_102 -> V_88 ) ;
}
static int F_39 ( struct V_84 * V_35 , const struct V_13 * V_14 )
{
const struct V_19 * V_20 = F_4 ( V_14 ) ;
if ( F_40 ( V_35 , V_107 , V_20 -> V_23 ) )
goto V_112;
if ( F_41 ( V_35 , V_98 , F_42 ( V_20 -> V_36 ) ) )
goto V_112;
switch ( V_20 -> V_36 ) {
case V_67 :
case V_75 :
case V_68 :
case V_73 :
case V_76 :
case V_80 :
if ( F_43 ( V_35 , V_99 , V_20 -> V_65 ) )
goto V_112;
break;
case V_8 :
case V_60 :
if ( V_20 -> V_65 < V_7 &&
F_43 ( V_35 , V_99 , V_20 -> V_65 ) )
goto V_112;
break;
default:
break;
}
return 0 ;
V_112:
return - 1 ;
}
static int F_44 ( struct V_84 * V_35 , const struct V_13 * V_14 )
{
const struct V_19 * V_20 = F_4 ( V_14 ) ;
if ( F_40 ( V_35 , V_111 , V_20 -> V_86 ) )
goto V_112;
if ( F_41 ( V_35 , V_98 , F_42 ( V_20 -> V_36 ) ) )
goto V_112;
return 0 ;
V_112:
return - 1 ;
}
static const struct V_113 *
F_45 ( const struct V_93 * V_94 ,
const struct V_95 * const V_96 [] )
{
if ( V_96 [ V_98 ] == NULL )
return F_46 ( - V_100 ) ;
if ( V_96 [ V_107 ] && V_96 [ V_111 ] )
return F_46 ( - V_100 ) ;
if ( V_96 [ V_107 ] )
return & V_114 ;
if ( V_96 [ V_111 ] )
return & V_115 ;
return F_46 ( - V_100 ) ;
}
static int T_4 F_47 ( void )
{
F_48 ( V_57 > V_116 ) ;
return F_49 ( & V_117 ) ;
}
static void T_5 F_50 ( void )
{
F_51 ( & V_117 ) ;
}
