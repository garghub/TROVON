static inline struct V_1 * F_1 ( struct V_2 * V_2 )
{
return F_2 ( V_2 , V_3 ) ;
}
static bool F_3 ( const struct V_4 * V_5 , unsigned int V_6 ,
struct V_2 * V_2 , struct V_7 * V_8 )
{
struct V_9 V_10 , * V_11 ;
V_11 = F_4 ( V_5 , V_6 , sizeof( V_10 ) , & V_10 ) ;
if ( V_11 == NULL )
return false ;
V_8 -> V_12 . V_13 . V_14 . V_15 = V_11 -> V_16 ;
V_8 -> V_17 . V_13 . V_14 . V_15 = V_11 -> V_18 ;
return true ;
}
static bool F_5 ( struct V_7 * V_19 ,
const struct V_7 * V_8 )
{
V_19 -> V_12 . V_13 . V_14 . V_15 = V_8 -> V_17 . V_13 . V_14 . V_15 ;
V_19 -> V_17 . V_13 . V_14 . V_15 = V_8 -> V_12 . V_13 . V_14 . V_15 ;
return true ;
}
static bool F_6 ( struct V_20 * V_21 , const struct V_4 * V_5 ,
unsigned int V_6 , unsigned int * V_22 )
{
struct V_2 * V_2 = F_7 ( V_21 ) ;
struct V_1 * V_23 ;
struct V_9 V_24 , * V_11 ;
const char * V_25 ;
T_1 V_26 ;
V_11 = F_4 ( V_5 , V_6 , sizeof( V_24 ) , & V_24 ) ;
F_8 ( V_11 == NULL ) ;
V_26 = V_27 [ V_28 ] [ V_11 -> V_29 ] [ V_30 ] ;
switch ( V_26 ) {
default:
V_23 = F_1 ( V_2 ) ;
if ( V_23 -> V_31 == 0 ) {
V_25 = L_1 ;
goto V_32;
}
case V_33 :
break;
case V_34 :
V_25 = L_2 ;
goto V_32;
}
V_21 -> V_35 . V_14 . V_36 [ V_37 ] = V_28 ;
V_21 -> V_35 . V_14 . V_36 [ V_38 ] = V_39 ;
V_21 -> V_35 . V_14 . V_26 = V_30 ;
V_21 -> V_35 . V_14 . V_40 = V_41 ;
V_21 -> V_35 . V_14 . V_42 = V_37 ;
V_21 -> V_35 . V_14 . V_43 = 0 ;
return true ;
V_32:
if ( F_9 ( V_2 , V_44 ) )
F_10 ( V_2 , F_11 ( V_21 ) , 0 , V_5 , NULL , NULL ,
NULL , L_3 , V_25 ) ;
return false ;
}
static T_2 F_12 ( const struct V_9 * V_11 )
{
const struct V_45 * V_46 ;
V_46 = ( void * ) V_11 + F_13 ( V_11 ) ;
return ( ( T_2 ) F_14 ( V_46 -> V_47 ) << 32 ) +
F_15 ( V_46 -> V_48 ) ;
}
static unsigned int * F_16 ( struct V_2 * V_2 )
{
return F_1 ( V_2 ) -> V_49 ;
}
static int F_17 ( struct V_20 * V_21 , const struct V_4 * V_5 ,
unsigned int V_6 , enum V_50 V_51 ,
T_1 V_52 , unsigned int V_53 ,
unsigned int * V_22 )
{
struct V_2 * V_2 = F_7 ( V_21 ) ;
enum V_54 V_55 = F_18 ( V_51 ) ;
struct V_9 V_24 , * V_11 ;
T_1 type , V_56 , V_57 ;
enum V_58 V_36 ;
V_11 = F_4 ( V_5 , V_6 , sizeof( V_24 ) , & V_24 ) ;
F_8 ( V_11 == NULL ) ;
type = V_11 -> V_29 ;
if ( type == V_59 &&
! F_19 ( V_60 , & V_21 -> V_61 ) ) {
F_20 ( V_21 , V_51 , V_5 ) ;
return V_62 ;
}
F_21 ( & V_21 -> V_63 ) ;
V_36 = V_21 -> V_35 . V_14 . V_36 [ V_55 ] ;
V_56 = V_21 -> V_35 . V_14 . V_26 ;
V_57 = V_27 [ V_36 ] [ type ] [ V_56 ] ;
switch ( V_57 ) {
case V_33 :
if ( V_56 == V_64 &&
V_36 == V_39 ) {
V_21 -> V_35 . V_14 . V_36 [ V_55 ] = V_28 ;
V_21 -> V_35 . V_14 . V_36 [ ! V_55 ] = V_39 ;
}
break;
case V_65 :
if ( V_56 == V_33 )
V_21 -> V_35 . V_14 . V_43 = F_22 ( V_11 ) ;
break;
case V_66 :
if ( V_56 == V_65 &&
type == V_67 &&
F_12 ( V_11 ) == V_21 -> V_35 . V_14 . V_43 )
F_23 ( V_68 , & V_21 -> V_61 ) ;
break;
case V_69 :
if ( V_21 -> V_35 . V_14 . V_42 == ! V_55 &&
V_21 -> V_35 . V_14 . V_40 == V_41 &&
type == V_70 ) {
V_21 -> V_35 . V_14 . V_36 [ ! V_55 ] = V_28 ;
V_21 -> V_35 . V_14 . V_36 [ V_55 ] = V_39 ;
V_21 -> V_35 . V_14 . V_43 = F_22 ( V_11 ) ;
V_57 = V_65 ;
break;
}
V_21 -> V_35 . V_14 . V_42 = V_55 ;
V_21 -> V_35 . V_14 . V_40 = type ;
F_24 ( & V_21 -> V_63 ) ;
if ( F_9 ( V_2 , V_44 ) )
F_10 ( V_2 , V_52 , 0 , V_5 , NULL , NULL , NULL ,
L_4 ) ;
return V_62 ;
case V_34 :
F_24 ( & V_21 -> V_63 ) ;
if ( F_9 ( V_2 , V_44 ) )
F_10 ( V_2 , V_52 , 0 , V_5 , NULL , NULL , NULL ,
L_2 ) ;
return - V_62 ;
}
V_21 -> V_35 . V_14 . V_42 = V_55 ;
V_21 -> V_35 . V_14 . V_40 = type ;
V_21 -> V_35 . V_14 . V_26 = V_57 ;
F_24 ( & V_21 -> V_63 ) ;
if ( V_57 != V_56 )
F_25 ( V_71 , V_21 ) ;
F_26 ( V_21 , V_51 , V_5 , V_22 [ V_57 ] ) ;
return V_62 ;
}
static int F_27 ( struct V_2 * V_2 , struct V_20 * V_72 ,
struct V_4 * V_5 , unsigned int V_6 ,
enum V_50 * V_51 ,
T_1 V_52 , unsigned int V_53 )
{
struct V_9 V_24 , * V_11 ;
unsigned int V_73 = V_5 -> V_74 - V_6 ;
unsigned int V_75 ;
const char * V_25 ;
V_11 = F_4 ( V_5 , V_6 , sizeof( V_24 ) , & V_24 ) ;
if ( V_11 == NULL ) {
V_25 = L_5 ;
goto V_32;
}
if ( V_11 -> V_76 * 4 < sizeof( struct V_9 ) ||
V_11 -> V_76 * 4 > V_73 ) {
V_25 = L_6 ;
goto V_32;
}
V_75 = V_73 ;
if ( V_11 -> V_77 ) {
V_75 = ( V_11 -> V_77 - 1 ) * 4 ;
if ( V_75 > V_73 ) {
V_25 = L_7 ;
goto V_32;
}
}
if ( V_2 -> V_21 . V_78 && V_53 == V_79 &&
F_28 ( V_5 , V_53 , V_6 , V_75 , V_44 ,
V_52 ) ) {
V_25 = L_8 ;
goto V_32;
}
if ( V_11 -> V_29 >= V_80 ) {
V_25 = L_9 ;
goto V_32;
}
return V_62 ;
V_32:
if ( F_9 ( V_2 , V_44 ) )
F_10 ( V_2 , V_52 , 0 , V_5 , NULL , NULL , NULL , L_3 , V_25 ) ;
return - V_62 ;
}
static void F_29 ( struct V_81 * V_82 ,
const struct V_7 * V_8 )
{
F_30 ( V_82 , L_10 ,
F_14 ( V_8 -> V_12 . V_13 . V_14 . V_15 ) ,
F_14 ( V_8 -> V_17 . V_13 . V_14 . V_15 ) ) ;
}
static void F_31 ( struct V_81 * V_82 , struct V_20 * V_21 )
{
F_30 ( V_82 , L_11 , V_83 [ V_21 -> V_35 . V_14 . V_26 ] ) ;
}
static int F_32 ( struct V_4 * V_5 , struct V_84 * V_85 ,
struct V_20 * V_21 )
{
struct V_84 * V_86 ;
F_21 ( & V_21 -> V_63 ) ;
V_86 = F_33 ( V_5 , V_87 | V_88 ) ;
if ( ! V_86 )
goto V_89;
if ( F_34 ( V_5 , V_90 , V_21 -> V_35 . V_14 . V_26 ) ||
F_34 ( V_5 , V_91 ,
V_21 -> V_35 . V_14 . V_36 [ V_37 ] ) ||
F_35 ( V_5 , V_92 ,
F_36 ( V_21 -> V_35 . V_14 . V_43 ) ,
V_93 ) )
goto V_89;
F_37 ( V_5 , V_86 ) ;
F_24 ( & V_21 -> V_63 ) ;
return 0 ;
V_89:
F_24 ( & V_21 -> V_63 ) ;
return - 1 ;
}
static int F_38 ( struct V_84 * V_94 [] , struct V_20 * V_21 )
{
struct V_84 * V_95 = V_94 [ V_87 ] ;
struct V_84 * V_96 [ V_97 + 1 ] ;
int V_98 ;
if ( ! V_95 )
return 0 ;
V_98 = F_39 ( V_96 , V_97 , V_95 ,
V_99 ) ;
if ( V_98 < 0 )
return V_98 ;
if ( ! V_96 [ V_90 ] ||
! V_96 [ V_91 ] ||
F_40 ( V_96 [ V_91 ] ) > V_100 ||
F_40 ( V_96 [ V_90 ] ) >= V_69 ) {
return - V_101 ;
}
F_21 ( & V_21 -> V_63 ) ;
V_21 -> V_35 . V_14 . V_26 = F_40 ( V_96 [ V_90 ] ) ;
if ( F_40 ( V_96 [ V_91 ] ) == V_28 ) {
V_21 -> V_35 . V_14 . V_36 [ V_37 ] = V_28 ;
V_21 -> V_35 . V_14 . V_36 [ V_38 ] = V_39 ;
} else {
V_21 -> V_35 . V_14 . V_36 [ V_37 ] = V_39 ;
V_21 -> V_35 . V_14 . V_36 [ V_38 ] = V_28 ;
}
if ( V_96 [ V_92 ] ) {
V_21 -> V_35 . V_14 . V_43 =
F_41 ( F_42 ( V_96 [ V_92 ] ) ) ;
}
F_24 ( & V_21 -> V_63 ) ;
return 0 ;
}
static int F_43 ( void )
{
return F_44 ( 0 )
+ F_45 ( V_99 , V_97 + 1 ) ;
}
static int F_46 ( struct V_84 * V_96 [] ,
struct V_2 * V_2 , void * V_102 )
{
struct V_1 * V_23 = F_1 ( V_2 ) ;
unsigned int * V_22 = V_102 ;
int V_103 ;
for ( V_103 = 0 ; V_103 < V_104 ; V_103 ++ )
V_22 [ V_103 ] = V_23 -> V_49 [ V_103 ] ;
for ( V_103 = V_105 + 1 ; V_103 < V_106 + 1 ; V_103 ++ ) {
if ( V_96 [ V_103 ] ) {
V_22 [ V_103 ] = F_15 ( F_47 ( V_96 [ V_103 ] ) ) * V_107 ;
}
}
return 0 ;
}
static int
F_48 ( struct V_4 * V_5 , const void * V_102 )
{
const unsigned int * V_22 = V_102 ;
int V_103 ;
for ( V_103 = V_105 + 1 ; V_103 < V_106 + 1 ; V_103 ++ ) {
if ( F_49 ( V_5 , V_103 , F_50 ( V_22 [ V_103 ] / V_107 ) ) )
goto V_89;
}
return 0 ;
V_89:
return - V_108 ;
}
static int F_51 ( struct V_2 * V_2 , struct V_109 * V_110 ,
struct V_1 * V_23 )
{
#ifdef F_52
if ( V_110 -> V_111 )
return 0 ;
V_110 -> V_111 = F_53 ( V_112 ,
sizeof( V_112 ) ,
V_113 ) ;
if ( ! V_110 -> V_111 )
return - V_114 ;
V_110 -> V_111 [ 0 ] . V_102 = & V_23 -> V_49 [ V_33 ] ;
V_110 -> V_111 [ 1 ] . V_102 = & V_23 -> V_49 [ V_65 ] ;
V_110 -> V_111 [ 2 ] . V_102 = & V_23 -> V_49 [ V_66 ] ;
V_110 -> V_111 [ 3 ] . V_102 = & V_23 -> V_49 [ V_115 ] ;
V_110 -> V_111 [ 4 ] . V_102 = & V_23 -> V_49 [ V_116 ] ;
V_110 -> V_111 [ 5 ] . V_102 = & V_23 -> V_49 [ V_117 ] ;
V_110 -> V_111 [ 6 ] . V_102 = & V_23 -> V_49 [ V_64 ] ;
V_110 -> V_111 [ 7 ] . V_102 = & V_23 -> V_31 ;
if ( V_2 -> V_118 != & V_119 )
V_110 -> V_111 [ 0 ] . V_120 = NULL ;
#endif
return 0 ;
}
static int F_54 ( struct V_2 * V_2 , T_3 V_35 )
{
struct V_1 * V_23 = F_1 ( V_2 ) ;
struct V_109 * V_110 = & V_23 -> V_110 ;
if ( ! V_110 -> V_121 ) {
V_23 -> V_31 = 1 ;
V_23 -> V_49 [ V_33 ] = 2 * V_122 ;
V_23 -> V_49 [ V_65 ] = 4 * V_122 ;
V_23 -> V_49 [ V_66 ] = 4 * V_122 ;
V_23 -> V_49 [ V_115 ] = 12 * 3600 * V_107 ;
V_23 -> V_49 [ V_116 ] = 64 * V_107 ;
V_23 -> V_49 [ V_117 ] = 64 * V_107 ;
V_23 -> V_49 [ V_64 ] = 2 * V_122 ;
}
return F_51 ( V_2 , V_110 , V_23 ) ;
}
static T_4 int F_55 ( struct V_2 * V_2 )
{
int V_123 = 0 ;
V_123 = F_56 ( V_2 , & V_124 ) ;
if ( V_123 < 0 ) {
F_57 ( L_12 ) ;
goto V_125;
}
V_123 = F_56 ( V_2 , & V_126 ) ;
if ( V_123 < 0 ) {
F_57 ( L_13 ) ;
goto V_127;
}
return 0 ;
V_127:
F_58 ( V_2 , & V_124 ) ;
V_125:
return V_123 ;
}
static T_5 void F_59 ( struct V_2 * V_2 )
{
F_58 ( V_2 , & V_126 ) ;
F_58 ( V_2 , & V_124 ) ;
}
static int T_6 F_60 ( void )
{
int V_123 ;
V_123 = F_61 ( & V_128 ) ;
if ( V_123 < 0 )
goto V_129;
V_123 = F_62 ( & V_124 ) ;
if ( V_123 < 0 )
goto V_130;
V_123 = F_62 ( & V_126 ) ;
if ( V_123 < 0 )
goto V_131;
return 0 ;
V_131:
F_63 ( & V_124 ) ;
V_130:
F_64 ( & V_128 ) ;
V_129:
return V_123 ;
}
static void T_7 F_65 ( void )
{
F_63 ( & V_126 ) ;
F_63 ( & V_124 ) ;
F_64 ( & V_128 ) ;
}
