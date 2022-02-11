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
if ( V_27 )
V_34 = F_6 ( V_25 ) ;
else if ( V_25 == V_38 )
V_34 = V_39 ;
else
V_34 = V_40 ;
* V_21 = V_34 ;
return;
default:
break;
}
if ( V_27 == NULL )
goto V_41;
switch ( V_20 -> V_36 ) {
case V_42 :
F_7 ( V_21 , F_8 ( V_25 ) ) ;
return;
case V_43 :
* V_21 = V_27 -> V_44 ;
return;
#ifdef F_9
case V_45 :
* V_21 = V_27 -> V_46 ;
return;
#endif
#ifdef F_10
case V_47 :
* V_21 = V_27 -> V_48 ;
return;
#endif
case V_49 :
* V_21 = F_11 ( F_12 ( V_27 ) ) ;
return;
case V_50 :
if ( V_27 -> V_51 == NULL )
goto V_41;
V_29 = F_13 ( V_27 -> V_51 ) ;
if ( V_29 == NULL )
goto V_41;
V_33 = F_14 ( V_29 -> V_33 ) ;
if ( V_33 == NULL )
goto V_41;
strncpy ( ( char * ) V_21 , V_33 -> V_52 , V_53 ) ;
return;
#ifdef F_15
case V_54 : {
struct V_55 * V_56 = F_16 ( V_27 ) ;
if ( V_56 )
memcpy ( V_21 , V_56 -> V_57 , V_58 ) ;
else
memset ( V_21 , 0 , V_58 ) ;
return;
}
#endif
case V_8 :
case V_59 : {
const struct V_60 * V_61 = F_17 ( V_27 ) ;
T_1 V_62 = 0 ;
if ( V_61 )
V_62 = F_1 ( V_61 -> V_63 ,
V_20 -> V_36 , V_20 -> V_64 ) ;
memcpy ( V_21 , & V_62 , sizeof( V_62 ) ) ;
return;
}
case V_65 : {
const struct V_60 * V_61 = F_17 ( V_27 ) ;
T_1 V_66 = 0 , V_67 = 0 , V_68 = 0 ;
if ( V_61 ) {
V_68 = F_1 ( V_61 -> V_63 ,
V_59 , V_20 -> V_64 ) ;
V_67 = F_1 ( V_61 -> V_63 ,
V_8 , V_20 -> V_64 ) ;
if ( V_68 != 0 )
V_66 = F_18 ( V_67 , V_68 ) ;
}
memcpy ( V_21 , & V_66 , sizeof( V_66 ) ) ;
return;
}
case V_69 :
F_7 ( V_21 , F_19 ( V_27 ) ) ;
return;
case V_70 :
F_7 ( V_21 , F_20 ( V_27 ) ) ;
return;
#ifdef F_21
case V_71 : {
const struct V_72 * V_73 = F_22 ( V_27 ) ;
T_3 V_74 ;
if ( V_20 -> V_64 < V_7 )
V_74 = F_23 ( V_73 , V_20 -> V_64 ) ;
else
V_74 = V_73 -> V_75 ;
F_24 ( V_21 , V_74 ) ;
return;
}
#endif
default:
break;
}
V_31 = & V_27 -> V_76 [ V_20 -> V_64 ] . V_31 ;
switch ( V_20 -> V_36 ) {
case V_77 :
memcpy ( V_21 , V_31 -> V_78 . V_79 . V_80 ,
F_19 ( V_27 ) == V_81 ? 4 : 16 ) ;
return;
case V_82 :
memcpy ( V_21 , V_31 -> V_83 . V_79 . V_80 ,
F_19 ( V_27 ) == V_81 ? 4 : 16 ) ;
return;
case V_84 :
F_24 ( V_21 , ( V_85 T_3 ) V_31 -> V_78 . V_86 . V_80 ) ;
return;
case V_87 :
F_24 ( V_21 , ( V_85 T_3 ) V_31 -> V_83 . V_86 . V_80 ) ;
return;
default:
break;
}
return;
V_41:
V_16 -> V_88 . V_89 = V_90 ;
}
static void F_25 ( const struct V_13 * V_14 ,
struct V_15 * V_16 ,
const struct V_17 * V_18 )
{
struct V_72 V_73 = { . V_64 = V_91 } ;
const struct V_19 * V_20 = F_4 ( V_14 ) ;
struct V_92 * V_35 = V_18 -> V_35 ;
enum V_24 V_25 ;
T_3 V_93 = F_26 ( & V_16 -> V_22 [ V_20 -> V_94 ] ) ;
struct V_26 * V_27 ;
V_27 = F_5 ( V_35 , & V_25 ) ;
if ( V_27 )
return;
V_73 . V_75 = V_93 ;
switch ( V_20 -> V_64 ) {
case V_11 :
V_73 . V_64 = V_95 ;
break;
case V_12 :
V_73 . V_64 = V_96 ;
break;
default:
break;
}
V_27 = F_27 ( V_97 ) ;
if ( F_28 ( F_29 ( & V_27 -> V_98 . V_99 ) == 1 ) ) {
F_30 ( V_27 , & V_73 ) ;
} else {
V_27 = F_31 ( F_32 ( V_18 ) , & V_73 , V_100 ) ;
if ( ! V_27 ) {
V_16 -> V_88 . V_89 = V_101 ;
return;
}
}
F_33 ( & V_27 -> V_98 . V_99 ) ;
F_34 ( V_35 , V_27 , V_102 ) ;
}
static void F_35 ( const struct V_13 * V_14 ,
struct V_15 * V_16 ,
const struct V_17 * V_18 )
{
const struct V_19 * V_20 = F_4 ( V_14 ) ;
struct V_92 * V_35 = V_18 -> V_35 ;
#ifdef F_9
T_2 V_93 = V_16 -> V_22 [ V_20 -> V_94 ] ;
#endif
enum V_24 V_25 ;
struct V_26 * V_27 ;
V_27 = F_5 ( V_35 , & V_25 ) ;
if ( V_27 == NULL || F_36 ( V_27 ) )
return;
switch ( V_20 -> V_36 ) {
#ifdef F_9
case V_45 :
if ( V_27 -> V_46 != V_93 ) {
V_27 -> V_46 = V_93 ;
F_37 ( V_103 , V_27 ) ;
}
break;
#endif
#ifdef F_15
case V_54 :
F_38 ( V_27 ,
& V_16 -> V_22 [ V_20 -> V_94 ] ,
& V_16 -> V_22 [ V_20 -> V_94 ] ,
V_58 / sizeof( T_2 ) ) ;
break;
#endif
#ifdef F_39
case V_104 : {
struct V_105 * V_106 = F_40 ( V_27 ) ;
T_2 V_107 = V_16 -> V_22 [ V_20 -> V_94 ] ;
if ( V_106 ) {
if ( V_106 -> V_107 != V_107 )
V_106 -> V_107 = V_107 ;
break;
}
if ( V_107 && ! F_41 ( V_27 ) )
F_42 ( V_27 , V_107 , 0 , V_100 ) ;
break;
}
#endif
default:
break;
}
}
static int F_43 ( struct V_108 * V_108 , T_4 V_109 )
{
int V_41 ;
if ( V_109 == V_110 ) {
V_41 = F_44 ( V_108 , V_81 ) ;
if ( V_41 < 0 )
goto V_111;
V_41 = F_44 ( V_108 , V_112 ) ;
if ( V_41 < 0 )
goto V_113;
} else {
V_41 = F_44 ( V_108 , V_109 ) ;
if ( V_41 < 0 )
goto V_111;
}
return 0 ;
V_113:
F_45 ( V_108 , V_81 ) ;
V_111:
return V_41 ;
}
static void F_46 ( struct V_108 * V_108 , T_4 V_109 )
{
if ( V_109 == V_110 ) {
F_45 ( V_108 , V_81 ) ;
F_45 ( V_108 , V_112 ) ;
} else
F_45 ( V_108 , V_109 ) ;
}
static void F_47 ( void )
{
struct V_26 * V_27 ;
int V_114 ;
F_48 (cpu) {
V_27 = F_49 ( V_97 , V_114 ) ;
if ( ! V_27 )
break;
F_50 ( V_27 ) ;
F_49 ( V_97 , V_114 ) = NULL ;
}
}
static bool F_51 ( void )
{
struct V_72 V_73 = { . V_75 = 0 } ;
struct V_26 * V_115 ;
int V_114 ;
if ( V_116 )
return true ;
F_48 (cpu) {
V_115 = F_31 ( & V_117 , & V_73 , V_118 ) ;
if ( ! V_115 ) {
F_47 () ;
return false ;
}
F_52 ( & V_115 -> V_98 . V_99 , 1 ) ;
F_49 ( V_97 , V_114 ) = V_115 ;
}
return true ;
}
static int F_53 ( const struct V_119 * V_120 ,
const struct V_13 * V_14 ,
const struct V_121 * const V_122 [] )
{
struct V_19 * V_20 = F_4 ( V_14 ) ;
unsigned int V_123 ;
int V_41 ;
V_20 -> V_36 = F_54 ( F_55 ( V_122 [ V_124 ] ) ) ;
V_20 -> V_64 = V_7 ;
switch ( V_20 -> V_36 ) {
case V_42 :
if ( V_122 [ V_125 ] != NULL )
return - V_126 ;
V_123 = sizeof( V_127 ) ;
break;
case V_37 :
case V_43 :
#ifdef F_9
case V_45 :
#endif
#ifdef F_10
case V_47 :
#endif
case V_49 :
if ( V_122 [ V_125 ] != NULL )
return - V_126 ;
V_123 = sizeof( T_2 ) ;
break;
#ifdef F_15
case V_54 :
if ( V_122 [ V_125 ] != NULL )
return - V_126 ;
V_123 = V_58 ;
break;
#endif
case V_50 :
if ( V_122 [ V_125 ] != NULL )
return - V_126 ;
V_123 = V_53 ;
break;
case V_69 :
case V_70 :
V_123 = sizeof( V_127 ) ;
break;
case V_77 :
case V_82 :
if ( V_122 [ V_125 ] == NULL )
return - V_126 ;
switch ( V_120 -> V_128 -> V_109 ) {
case V_81 :
V_123 = F_56 ( struct V_30 ,
V_78 . V_79 . V_129 ) ;
break;
case V_112 :
case V_110 :
V_123 = F_56 ( struct V_30 ,
V_78 . V_79 . V_130 ) ;
break;
default:
return - V_131 ;
}
break;
case V_84 :
case V_87 :
if ( V_122 [ V_125 ] == NULL )
return - V_126 ;
V_123 = F_56 ( struct V_30 , V_78 . V_86 . V_80 ) ;
break;
case V_8 :
case V_59 :
case V_65 :
V_123 = sizeof( T_1 ) ;
break;
#ifdef F_21
case V_71 :
V_123 = sizeof( T_3 ) ;
break;
#endif
default:
return - V_132 ;
}
if ( V_122 [ V_125 ] != NULL ) {
V_20 -> V_64 = F_57 ( V_122 [ V_125 ] ) ;
switch ( V_20 -> V_64 ) {
case V_11 :
case V_12 :
break;
default:
return - V_126 ;
}
}
V_20 -> V_23 = F_58 ( V_122 [ V_133 ] ) ;
V_41 = F_59 ( V_120 , V_20 -> V_23 , NULL ,
V_134 , V_123 ) ;
if ( V_41 < 0 )
return V_41 ;
V_41 = F_43 ( V_120 -> V_108 , V_120 -> V_128 -> V_109 ) ;
if ( V_41 < 0 )
return V_41 ;
if ( V_20 -> V_36 == V_8 ||
V_20 -> V_36 == V_59 ||
V_20 -> V_36 == V_65 )
F_60 ( V_120 -> V_108 , true ) ;
return 0 ;
}
static void F_61 ( const struct V_119 * V_120 , struct V_19 * V_20 )
{
switch ( V_20 -> V_36 ) {
#ifdef F_15
case V_54 :
F_62 ( V_120 -> V_108 ) ;
break;
#endif
#ifdef F_21
case V_71 :
if ( -- V_116 == 0 )
F_47 () ;
#endif
default:
break;
}
}
static int F_63 ( const struct V_119 * V_120 ,
const struct V_13 * V_14 ,
const struct V_121 * const V_122 [] )
{
struct V_19 * V_20 = F_4 ( V_14 ) ;
unsigned int V_123 ;
int V_41 ;
V_20 -> V_64 = V_7 ;
V_20 -> V_36 = F_54 ( F_55 ( V_122 [ V_124 ] ) ) ;
switch ( V_20 -> V_36 ) {
#ifdef F_9
case V_45 :
if ( V_122 [ V_125 ] )
return - V_126 ;
V_123 = F_56 ( struct V_26 , V_46 ) ;
break;
#endif
#ifdef F_15
case V_54 :
if ( V_122 [ V_125 ] )
return - V_126 ;
V_123 = V_58 ;
V_41 = F_64 ( V_120 -> V_108 , ( V_123 * V_135 ) - 1 ) ;
if ( V_41 )
return V_41 ;
break;
#endif
#ifdef F_21
case V_71 :
if ( ! F_51 () )
return - V_136 ;
V_116 ++ ;
V_123 = sizeof( T_3 ) ;
break;
#endif
#ifdef F_39
case V_104 :
if ( V_122 [ V_125 ] )
return - V_126 ;
V_123 = sizeof( T_2 ) ;
break;
#endif
default:
return - V_132 ;
}
if ( V_122 [ V_125 ] ) {
V_20 -> V_64 = F_57 ( V_122 [ V_125 ] ) ;
switch ( V_20 -> V_64 ) {
case V_11 :
case V_12 :
break;
default:
V_41 = - V_126 ;
goto V_111;
}
}
V_20 -> V_94 = F_58 ( V_122 [ V_137 ] ) ;
V_41 = F_65 ( V_20 -> V_94 , V_123 ) ;
if ( V_41 < 0 )
goto V_111;
V_41 = F_43 ( V_120 -> V_108 , V_120 -> V_128 -> V_109 ) ;
if ( V_41 < 0 )
goto V_111;
return 0 ;
V_111:
F_61 ( V_120 , V_20 ) ;
return V_41 ;
}
static void F_66 ( const struct V_119 * V_120 ,
const struct V_13 * V_14 )
{
F_45 ( V_120 -> V_108 , V_120 -> V_128 -> V_109 ) ;
}
static void F_67 ( const struct V_119 * V_120 ,
const struct V_13 * V_14 )
{
struct V_19 * V_20 = F_4 ( V_14 ) ;
F_61 ( V_120 , V_20 ) ;
F_46 ( V_120 -> V_108 , V_120 -> V_128 -> V_109 ) ;
}
static int F_68 ( struct V_92 * V_35 , const struct V_13 * V_14 )
{
const struct V_19 * V_20 = F_4 ( V_14 ) ;
if ( F_69 ( V_35 , V_133 , V_20 -> V_23 ) )
goto V_138;
if ( F_70 ( V_35 , V_124 , F_71 ( V_20 -> V_36 ) ) )
goto V_138;
switch ( V_20 -> V_36 ) {
case V_77 :
case V_82 :
case V_84 :
case V_87 :
if ( F_72 ( V_35 , V_125 , V_20 -> V_64 ) )
goto V_138;
break;
case V_8 :
case V_59 :
case V_65 :
case V_71 :
if ( V_20 -> V_64 < V_7 &&
F_72 ( V_35 , V_125 , V_20 -> V_64 ) )
goto V_138;
break;
default:
break;
}
return 0 ;
V_138:
return - 1 ;
}
static int F_73 ( struct V_92 * V_35 , const struct V_13 * V_14 )
{
const struct V_19 * V_20 = F_4 ( V_14 ) ;
if ( F_69 ( V_35 , V_137 , V_20 -> V_94 ) )
goto V_138;
if ( F_70 ( V_35 , V_124 , F_71 ( V_20 -> V_36 ) ) )
goto V_138;
switch ( V_20 -> V_36 ) {
case V_71 :
if ( V_20 -> V_64 < V_7 &&
F_72 ( V_35 , V_125 , V_20 -> V_64 ) )
goto V_138;
break;
default:
break;
}
return 0 ;
V_138:
return - 1 ;
}
static const struct V_139 *
F_74 ( const struct V_119 * V_120 ,
const struct V_121 * const V_122 [] )
{
if ( V_122 [ V_124 ] == NULL )
return F_75 ( - V_126 ) ;
if ( V_122 [ V_133 ] && V_122 [ V_137 ] )
return F_75 ( - V_126 ) ;
if ( V_122 [ V_133 ] )
return & V_140 ;
if ( V_122 [ V_137 ] ) {
#ifdef F_21
if ( F_55 ( V_122 [ V_124 ] ) == F_71 ( V_71 ) )
return & V_141 ;
#endif
return & V_142 ;
}
return F_75 ( - V_126 ) ;
}
static void F_76 ( const struct V_13 * V_14 ,
struct V_15 * V_16 ,
const struct V_17 * V_18 )
{
struct V_92 * V_35 = V_18 -> V_35 ;
enum V_24 V_25 ;
struct V_26 * V_27 ;
V_27 = F_5 ( V_18 -> V_35 , & V_25 ) ;
if ( V_27 || V_25 == V_38 )
return;
F_34 ( V_35 , V_27 , V_38 ) ;
}
static int F_77 ( const struct V_119 * V_120 ,
const struct V_121 * const V_122 [] ,
struct V_143 * V_144 )
{
struct V_145 * V_20 = F_78 ( V_144 ) ;
struct V_32 * V_146 , * V_147 ;
char V_52 [ V_53 ] ;
int V_109 = V_120 -> V_128 -> V_109 ;
if ( ! V_122 [ V_148 ] || ! V_122 [ V_149 ] )
return - V_126 ;
V_20 -> V_150 = F_57 ( V_122 [ V_149 ] ) ;
if ( ! V_20 -> V_150 )
return - V_151 ;
F_79 ( V_52 , V_122 [ V_148 ] , sizeof( V_52 ) ) ;
if ( V_122 [ V_152 ] )
V_109 = F_80 ( F_81 ( V_122 [ V_152 ] ) ) ;
V_146 = NULL ;
V_147 = NULL ;
switch ( V_109 ) {
case V_81 :
if ( V_120 -> V_128 -> V_109 == V_112 )
return - V_126 ;
V_146 = F_82 ( V_52 , V_109 ,
V_20 -> V_150 ) ;
break;
case V_112 :
if ( V_120 -> V_128 -> V_109 == V_81 )
return - V_126 ;
V_147 = F_82 ( V_52 , V_109 ,
V_20 -> V_150 ) ;
break;
case V_153 :
case V_154 :
case V_110 :
V_146 = F_82 ( V_52 , V_81 ,
V_20 -> V_150 ) ;
V_147 = F_82 ( V_52 , V_112 ,
V_20 -> V_150 ) ;
break;
default:
return - V_131 ;
}
if ( ! V_146 && ! V_147 )
return - V_151 ;
V_20 -> V_155 = V_146 ;
V_20 -> V_156 = V_147 ;
return 0 ;
}
static void F_83 ( struct V_143 * V_144 )
{
struct V_145 * V_20 = F_78 ( V_144 ) ;
if ( V_20 -> V_155 )
F_84 ( V_20 -> V_155 ) ;
if ( V_20 -> V_156 )
F_84 ( V_20 -> V_156 ) ;
}
static void F_85 ( struct V_143 * V_144 ,
struct V_15 * V_16 ,
const struct V_17 * V_18 )
{
const struct V_145 * V_20 = F_78 ( V_144 ) ;
struct V_26 * V_27 = (struct V_26 * ) F_86 ( V_18 -> V_35 ) ;
struct V_32 * V_157 = NULL ;
struct V_28 * V_29 ;
if ( ! V_27 ||
F_41 ( V_27 ) ||
F_36 ( V_27 ) ||
V_20 -> V_150 != F_20 ( V_27 ) )
return;
switch ( F_19 ( V_27 ) ) {
case V_81 :
V_157 = V_20 -> V_155 ;
break;
case V_112 :
V_157 = V_20 -> V_156 ;
break;
default:
F_87 ( 1 ) ;
return;
}
if ( ! V_157 )
return;
if ( F_88 ( V_158 , & V_27 -> V_44 ) )
return;
V_29 = F_89 ( V_27 , V_157 , V_100 ) ;
if ( V_29 ) {
F_90 ( V_29 -> V_33 , V_157 ) ;
F_91 ( V_158 , & V_27 -> V_44 ) ;
}
}
static int F_92 ( struct V_92 * V_35 ,
struct V_143 * V_144 , bool V_159 )
{
const struct V_145 * V_20 = F_78 ( V_144 ) ;
const struct V_32 * V_33 = V_20 -> V_155 ;
T_3 V_109 ;
if ( F_93 ( V_35 , V_148 , V_33 -> V_52 ) )
return - 1 ;
if ( F_72 ( V_35 , V_149 , V_20 -> V_150 ) )
return - 1 ;
if ( V_20 -> V_155 && V_20 -> V_156 )
V_109 = V_110 ;
else if ( V_20 -> V_156 )
V_109 = V_112 ;
else
V_109 = V_81 ;
if ( F_94 ( V_35 , V_152 , F_95 ( V_109 ) ) )
return - 1 ;
return 0 ;
}
static int T_5 F_96 ( void )
{
int V_41 ;
F_97 ( V_58 > V_160 ) ;
V_41 = F_98 ( & V_161 ) ;
if ( V_41 < 0 )
return V_41 ;
V_41 = F_98 ( & V_162 ) ;
if ( V_41 < 0 )
goto V_111;
V_41 = F_99 ( & V_145 ) ;
if ( V_41 < 0 )
goto V_113;
return 0 ;
V_113:
F_100 ( & V_162 ) ;
V_111:
F_100 ( & V_161 ) ;
return V_41 ;
}
static void T_6 F_101 ( void )
{
F_102 ( & V_145 ) ;
F_100 ( & V_162 ) ;
F_100 ( & V_161 ) ;
}
