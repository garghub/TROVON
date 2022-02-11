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
F_8 ( V_21 , F_9 ( V_25 ) ) ;
return;
case V_42 :
* V_21 = V_27 -> V_43 ;
return;
#ifdef F_10
case V_44 :
* V_21 = V_27 -> V_45 ;
return;
#endif
#ifdef F_11
case V_46 :
* V_21 = V_27 -> V_47 ;
return;
#endif
case V_48 :
* V_21 = F_12 ( F_13 ( V_27 ) ) ;
return;
case V_49 :
if ( V_27 -> V_50 == NULL )
goto V_40;
V_29 = F_14 ( V_27 -> V_50 ) ;
if ( V_29 == NULL )
goto V_40;
V_33 = F_15 ( V_29 -> V_33 ) ;
if ( V_33 == NULL )
goto V_40;
strncpy ( ( char * ) V_21 , V_33 -> V_51 , V_52 ) ;
return;
#ifdef F_16
case V_53 : {
struct V_54 * V_55 = F_17 ( V_27 ) ;
if ( V_55 )
memcpy ( V_21 , V_55 -> V_56 , V_57 ) ;
else
memset ( V_21 , 0 , V_57 ) ;
return;
}
#endif
case V_8 :
case V_58 : {
const struct V_59 * V_60 = F_18 ( V_27 ) ;
T_1 V_61 = 0 ;
if ( V_60 )
V_61 = F_1 ( V_60 -> V_62 ,
V_20 -> V_36 , V_20 -> V_63 ) ;
memcpy ( V_21 , & V_61 , sizeof( V_61 ) ) ;
return;
}
case V_64 : {
const struct V_59 * V_60 = F_18 ( V_27 ) ;
T_1 V_65 = 0 , V_66 = 0 , V_67 = 0 ;
if ( V_60 ) {
V_67 = F_1 ( V_60 -> V_62 ,
V_58 , V_20 -> V_63 ) ;
V_66 = F_1 ( V_60 -> V_62 ,
V_8 , V_20 -> V_63 ) ;
if ( V_67 != 0 )
V_65 = F_19 ( V_66 , V_67 ) ;
}
memcpy ( V_21 , & V_65 , sizeof( V_65 ) ) ;
return;
}
case V_68 :
F_8 ( V_21 , F_20 ( V_27 ) ) ;
return;
case V_69 :
F_8 ( V_21 , F_21 ( V_27 ) ) ;
return;
#ifdef F_22
case V_70 : {
const struct V_71 * V_72 = F_23 ( V_27 ) ;
T_3 V_73 ;
if ( V_20 -> V_63 < V_7 )
V_73 = F_24 ( V_72 , V_20 -> V_63 ) ;
else
V_73 = V_72 -> V_74 ;
F_25 ( V_21 , V_73 ) ;
return;
}
#endif
default:
break;
}
V_31 = & V_27 -> V_75 [ V_20 -> V_63 ] . V_31 ;
switch ( V_20 -> V_36 ) {
case V_76 :
memcpy ( V_21 , V_31 -> V_77 . V_78 . V_79 ,
F_20 ( V_27 ) == V_80 ? 4 : 16 ) ;
return;
case V_81 :
memcpy ( V_21 , V_31 -> V_82 . V_78 . V_79 ,
F_20 ( V_27 ) == V_80 ? 4 : 16 ) ;
return;
case V_83 :
F_25 ( V_21 , ( V_84 T_3 ) V_31 -> V_77 . V_85 . V_79 ) ;
return;
case V_86 :
F_25 ( V_21 , ( V_84 T_3 ) V_31 -> V_82 . V_85 . V_79 ) ;
return;
default:
break;
}
return;
V_40:
V_16 -> V_87 . V_88 = V_89 ;
}
static void F_26 ( const struct V_13 * V_14 ,
struct V_15 * V_16 ,
const struct V_17 * V_18 )
{
struct V_71 V_72 = { . V_63 = V_90 } ;
const struct V_19 * V_20 = F_4 ( V_14 ) ;
struct V_91 * V_35 = V_18 -> V_35 ;
enum V_24 V_25 ;
T_3 V_92 = F_27 ( & V_16 -> V_22 [ V_20 -> V_93 ] ) ;
struct V_26 * V_27 ;
V_27 = F_5 ( V_35 , & V_25 ) ;
if ( V_27 )
return;
V_72 . V_74 = V_92 ;
switch ( V_20 -> V_63 ) {
case V_11 :
V_72 . V_63 = V_94 ;
break;
case V_12 :
V_72 . V_63 = V_95 ;
break;
default:
break;
}
V_27 = F_28 ( V_96 ) ;
if ( F_29 ( F_30 ( & V_27 -> V_97 . V_98 ) == 1 ) ) {
F_31 ( V_27 , & V_72 ) ;
} else {
V_27 = F_32 ( F_33 ( V_18 ) , & V_72 , V_99 ) ;
if ( ! V_27 ) {
V_16 -> V_87 . V_88 = V_100 ;
return;
}
}
F_34 ( & V_27 -> V_97 . V_98 ) ;
F_35 ( V_35 , V_27 , V_101 ) ;
}
static void F_36 ( const struct V_13 * V_14 ,
struct V_15 * V_16 ,
const struct V_17 * V_18 )
{
const struct V_19 * V_20 = F_4 ( V_14 ) ;
struct V_91 * V_35 = V_18 -> V_35 ;
#ifdef F_10
T_2 V_92 = V_16 -> V_22 [ V_20 -> V_93 ] ;
#endif
enum V_24 V_25 ;
struct V_26 * V_27 ;
V_27 = F_5 ( V_35 , & V_25 ) ;
if ( V_27 == NULL )
return;
switch ( V_20 -> V_36 ) {
#ifdef F_10
case V_44 :
if ( V_27 -> V_45 != V_92 ) {
V_27 -> V_45 = V_92 ;
F_37 ( V_102 , V_27 ) ;
}
break;
#endif
#ifdef F_16
case V_53 :
F_38 ( V_27 ,
& V_16 -> V_22 [ V_20 -> V_93 ] ,
& V_16 -> V_22 [ V_20 -> V_93 ] ,
V_57 / sizeof( T_2 ) ) ;
break;
#endif
default:
break;
}
}
static int F_39 ( struct V_103 * V_103 , T_4 V_104 )
{
int V_40 ;
if ( V_104 == V_105 ) {
V_40 = F_40 ( V_103 , V_80 ) ;
if ( V_40 < 0 )
goto V_106;
V_40 = F_40 ( V_103 , V_107 ) ;
if ( V_40 < 0 )
goto V_108;
} else {
V_40 = F_40 ( V_103 , V_104 ) ;
if ( V_40 < 0 )
goto V_106;
}
return 0 ;
V_108:
F_41 ( V_103 , V_80 ) ;
V_106:
return V_40 ;
}
static void F_42 ( struct V_103 * V_103 , T_4 V_104 )
{
if ( V_104 == V_105 ) {
F_41 ( V_103 , V_80 ) ;
F_41 ( V_103 , V_107 ) ;
} else
F_41 ( V_103 , V_104 ) ;
}
static void F_43 ( void )
{
struct V_26 * V_27 ;
int V_109 ;
F_44 (cpu) {
V_27 = F_45 ( V_96 , V_109 ) ;
if ( ! V_27 )
break;
F_46 ( V_27 ) ;
F_45 ( V_96 , V_109 ) = NULL ;
}
}
static bool F_47 ( void )
{
struct V_71 V_72 = { . V_74 = 0 } ;
struct V_26 * V_110 ;
int V_109 ;
if ( V_111 )
return true ;
F_44 (cpu) {
V_110 = F_32 ( & V_112 , & V_72 , V_113 ) ;
if ( ! V_110 ) {
F_43 () ;
return false ;
}
F_48 ( & V_110 -> V_97 . V_98 , 1 ) ;
F_45 ( V_96 , V_109 ) = V_110 ;
}
return true ;
}
static int F_49 ( const struct V_114 * V_115 ,
const struct V_13 * V_14 ,
const struct V_116 * const V_117 [] )
{
struct V_19 * V_20 = F_4 ( V_14 ) ;
unsigned int V_118 ;
int V_40 ;
V_20 -> V_36 = F_50 ( F_51 ( V_117 [ V_119 ] ) ) ;
V_20 -> V_63 = V_7 ;
switch ( V_20 -> V_36 ) {
case V_41 :
if ( V_117 [ V_120 ] != NULL )
return - V_121 ;
V_118 = sizeof( V_122 ) ;
break;
case V_37 :
case V_42 :
#ifdef F_10
case V_44 :
#endif
#ifdef F_11
case V_46 :
#endif
case V_48 :
if ( V_117 [ V_120 ] != NULL )
return - V_121 ;
V_118 = sizeof( T_2 ) ;
break;
#ifdef F_16
case V_53 :
if ( V_117 [ V_120 ] != NULL )
return - V_121 ;
V_118 = V_57 ;
break;
#endif
case V_49 :
if ( V_117 [ V_120 ] != NULL )
return - V_121 ;
V_118 = V_52 ;
break;
case V_68 :
case V_69 :
V_118 = sizeof( V_122 ) ;
break;
case V_76 :
case V_81 :
if ( V_117 [ V_120 ] == NULL )
return - V_121 ;
switch ( V_115 -> V_123 -> V_104 ) {
case V_80 :
V_118 = F_52 ( struct V_30 ,
V_77 . V_78 . V_124 ) ;
break;
case V_107 :
case V_105 :
V_118 = F_52 ( struct V_30 ,
V_77 . V_78 . V_125 ) ;
break;
default:
return - V_126 ;
}
break;
case V_83 :
case V_86 :
if ( V_117 [ V_120 ] == NULL )
return - V_121 ;
V_118 = F_52 ( struct V_30 , V_77 . V_85 . V_79 ) ;
break;
case V_8 :
case V_58 :
case V_64 :
V_118 = sizeof( T_1 ) ;
break;
#ifdef F_22
case V_70 :
V_118 = sizeof( T_3 ) ;
break;
#endif
default:
return - V_127 ;
}
if ( V_117 [ V_120 ] != NULL ) {
V_20 -> V_63 = F_53 ( V_117 [ V_120 ] ) ;
switch ( V_20 -> V_63 ) {
case V_11 :
case V_12 :
break;
default:
return - V_121 ;
}
}
V_20 -> V_23 = F_54 ( V_117 [ V_128 ] ) ;
V_40 = F_55 ( V_115 , V_20 -> V_23 , NULL ,
V_129 , V_118 ) ;
if ( V_40 < 0 )
return V_40 ;
V_40 = F_39 ( V_115 -> V_103 , V_115 -> V_123 -> V_104 ) ;
if ( V_40 < 0 )
return V_40 ;
if ( V_20 -> V_36 == V_8 ||
V_20 -> V_36 == V_58 ||
V_20 -> V_36 == V_64 )
F_56 ( V_115 -> V_103 , true ) ;
return 0 ;
}
static void F_57 ( const struct V_114 * V_115 , struct V_19 * V_20 )
{
switch ( V_20 -> V_36 ) {
#ifdef F_16
case V_53 :
F_58 ( V_115 -> V_103 ) ;
break;
#endif
#ifdef F_22
case V_70 :
if ( -- V_111 == 0 )
F_43 () ;
#endif
default:
break;
}
}
static int F_59 ( const struct V_114 * V_115 ,
const struct V_13 * V_14 ,
const struct V_116 * const V_117 [] )
{
struct V_19 * V_20 = F_4 ( V_14 ) ;
unsigned int V_118 ;
int V_40 ;
V_20 -> V_63 = V_7 ;
V_20 -> V_36 = F_50 ( F_51 ( V_117 [ V_119 ] ) ) ;
switch ( V_20 -> V_36 ) {
#ifdef F_10
case V_44 :
if ( V_117 [ V_120 ] )
return - V_121 ;
V_118 = F_52 ( struct V_26 , V_45 ) ;
break;
#endif
#ifdef F_16
case V_53 :
if ( V_117 [ V_120 ] )
return - V_121 ;
V_118 = V_57 ;
V_40 = F_60 ( V_115 -> V_103 , ( V_118 * V_130 ) - 1 ) ;
if ( V_40 )
return V_40 ;
break;
#endif
#ifdef F_22
case V_70 :
if ( ! F_47 () )
return - V_131 ;
V_111 ++ ;
V_118 = sizeof( T_3 ) ;
break;
#endif
default:
return - V_127 ;
}
if ( V_117 [ V_120 ] ) {
V_20 -> V_63 = F_53 ( V_117 [ V_120 ] ) ;
switch ( V_20 -> V_63 ) {
case V_11 :
case V_12 :
break;
default:
V_40 = - V_121 ;
goto V_106;
}
}
V_20 -> V_93 = F_54 ( V_117 [ V_132 ] ) ;
V_40 = F_61 ( V_20 -> V_93 , V_118 ) ;
if ( V_40 < 0 )
goto V_106;
V_40 = F_39 ( V_115 -> V_103 , V_115 -> V_123 -> V_104 ) ;
if ( V_40 < 0 )
goto V_106;
return 0 ;
V_106:
F_57 ( V_115 , V_20 ) ;
return V_40 ;
}
static void F_62 ( const struct V_114 * V_115 ,
const struct V_13 * V_14 )
{
F_41 ( V_115 -> V_103 , V_115 -> V_123 -> V_104 ) ;
}
static void F_63 ( const struct V_114 * V_115 ,
const struct V_13 * V_14 )
{
struct V_19 * V_20 = F_4 ( V_14 ) ;
F_57 ( V_115 , V_20 ) ;
F_42 ( V_115 -> V_103 , V_115 -> V_123 -> V_104 ) ;
}
static int F_64 ( struct V_91 * V_35 , const struct V_13 * V_14 )
{
const struct V_19 * V_20 = F_4 ( V_14 ) ;
if ( F_65 ( V_35 , V_128 , V_20 -> V_23 ) )
goto V_133;
if ( F_66 ( V_35 , V_119 , F_67 ( V_20 -> V_36 ) ) )
goto V_133;
switch ( V_20 -> V_36 ) {
case V_76 :
case V_81 :
case V_83 :
case V_86 :
if ( F_68 ( V_35 , V_120 , V_20 -> V_63 ) )
goto V_133;
break;
case V_8 :
case V_58 :
case V_64 :
case V_70 :
if ( V_20 -> V_63 < V_7 &&
F_68 ( V_35 , V_120 , V_20 -> V_63 ) )
goto V_133;
break;
default:
break;
}
return 0 ;
V_133:
return - 1 ;
}
static int F_69 ( struct V_91 * V_35 , const struct V_13 * V_14 )
{
const struct V_19 * V_20 = F_4 ( V_14 ) ;
if ( F_65 ( V_35 , V_132 , V_20 -> V_93 ) )
goto V_133;
if ( F_66 ( V_35 , V_119 , F_67 ( V_20 -> V_36 ) ) )
goto V_133;
switch ( V_20 -> V_36 ) {
case V_70 :
if ( V_20 -> V_63 < V_7 &&
F_68 ( V_35 , V_120 , V_20 -> V_63 ) )
goto V_133;
break;
default:
break;
}
return 0 ;
V_133:
return - 1 ;
}
static const struct V_134 *
F_70 ( const struct V_114 * V_115 ,
const struct V_116 * const V_117 [] )
{
if ( V_117 [ V_119 ] == NULL )
return F_71 ( - V_121 ) ;
if ( V_117 [ V_128 ] && V_117 [ V_132 ] )
return F_71 ( - V_121 ) ;
if ( V_117 [ V_128 ] )
return & V_135 ;
if ( V_117 [ V_132 ] ) {
#ifdef F_22
if ( F_51 ( V_117 [ V_119 ] ) == F_67 ( V_70 ) )
return & V_136 ;
#endif
return & V_137 ;
}
return F_71 ( - V_121 ) ;
}
static void F_72 ( const struct V_13 * V_14 ,
struct V_15 * V_16 ,
const struct V_17 * V_18 )
{
struct V_91 * V_35 = V_18 -> V_35 ;
enum V_24 V_25 ;
struct V_26 * V_27 ;
V_27 = F_5 ( V_18 -> V_35 , & V_25 ) ;
if ( V_27 )
return;
V_27 = F_73 () ;
F_34 ( & V_27 -> V_97 . V_98 ) ;
F_35 ( V_35 , V_27 , V_101 ) ;
}
static int T_5 F_74 ( void )
{
int V_40 ;
F_75 ( V_57 > V_138 ) ;
V_40 = F_76 ( & V_139 ) ;
if ( V_40 < 0 )
return V_40 ;
V_40 = F_76 ( & V_140 ) ;
if ( V_40 < 0 )
goto V_106;
return 0 ;
V_106:
F_77 ( & V_139 ) ;
return V_40 ;
}
static void T_6 F_78 ( void )
{
F_77 ( & V_140 ) ;
F_77 ( & V_139 ) ;
}
