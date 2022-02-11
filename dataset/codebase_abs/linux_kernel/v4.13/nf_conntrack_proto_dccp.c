static inline struct V_1 * F_1 ( struct V_2 * V_2 )
{
return & V_2 -> V_3 . V_4 . V_5 ;
}
static bool F_2 ( const struct V_6 * V_7 , unsigned int V_8 ,
struct V_2 * V_2 , struct V_9 * V_10 )
{
struct V_11 V_12 , * V_13 ;
V_13 = F_3 ( V_7 , V_8 , 4 , & V_12 ) ;
if ( V_13 == NULL )
return false ;
V_10 -> V_14 . V_15 . V_5 . V_16 = V_13 -> V_17 ;
V_10 -> V_18 . V_15 . V_5 . V_16 = V_13 -> V_19 ;
return true ;
}
static bool F_4 ( struct V_9 * V_20 ,
const struct V_9 * V_10 )
{
V_20 -> V_14 . V_15 . V_5 . V_16 = V_10 -> V_18 . V_15 . V_5 . V_16 ;
V_20 -> V_18 . V_15 . V_5 . V_16 = V_10 -> V_14 . V_15 . V_5 . V_16 ;
return true ;
}
static bool F_5 ( struct V_21 * V_3 , const struct V_6 * V_7 ,
unsigned int V_8 , unsigned int * V_22 )
{
struct V_2 * V_2 = F_6 ( V_3 ) ;
struct V_1 * V_23 ;
struct V_11 V_24 , * V_13 ;
const char * V_25 ;
T_1 V_26 ;
V_13 = F_3 ( V_7 , V_8 , sizeof( V_24 ) , & V_24 ) ;
F_7 ( V_13 == NULL ) ;
V_26 = V_27 [ V_28 ] [ V_13 -> V_29 ] [ V_30 ] ;
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
V_3 -> V_35 . V_5 . V_36 [ V_37 ] = V_28 ;
V_3 -> V_35 . V_5 . V_36 [ V_38 ] = V_39 ;
V_3 -> V_35 . V_5 . V_26 = V_30 ;
V_3 -> V_35 . V_5 . V_40 = V_41 ;
V_3 -> V_35 . V_5 . V_42 = V_37 ;
V_3 -> V_35 . V_5 . V_43 = 0 ;
return true ;
V_32:
if ( F_8 ( V_2 , V_44 ) )
F_9 ( V_2 , F_10 ( V_3 ) , 0 , V_7 , NULL , NULL ,
NULL , L_3 , V_25 ) ;
return false ;
}
static T_2 F_11 ( const struct V_11 * V_13 )
{
const struct V_45 * V_46 ;
V_46 = ( void * ) V_13 + F_12 ( V_13 ) ;
return ( ( T_2 ) F_13 ( V_46 -> V_47 ) << 32 ) +
F_14 ( V_46 -> V_48 ) ;
}
static unsigned int * F_15 ( struct V_2 * V_2 )
{
return F_1 ( V_2 ) -> V_49 ;
}
static int F_16 ( struct V_21 * V_3 , const struct V_6 * V_7 ,
unsigned int V_8 , enum V_50 V_51 ,
T_1 V_52 , unsigned int V_53 ,
unsigned int * V_22 )
{
struct V_2 * V_2 = F_6 ( V_3 ) ;
enum V_54 V_55 = F_17 ( V_51 ) ;
struct V_11 V_24 , * V_13 ;
T_1 type , V_56 , V_57 ;
enum V_58 V_36 ;
V_13 = F_3 ( V_7 , V_8 , sizeof( V_24 ) , & V_24 ) ;
F_7 ( V_13 == NULL ) ;
type = V_13 -> V_29 ;
if ( type == V_59 &&
! F_18 ( V_60 , & V_3 -> V_61 ) ) {
F_19 ( V_3 , V_51 , V_7 ) ;
return V_62 ;
}
F_20 ( & V_3 -> V_63 ) ;
V_36 = V_3 -> V_35 . V_5 . V_36 [ V_55 ] ;
V_56 = V_3 -> V_35 . V_5 . V_26 ;
V_57 = V_27 [ V_36 ] [ type ] [ V_56 ] ;
switch ( V_57 ) {
case V_33 :
if ( V_56 == V_64 &&
V_36 == V_39 ) {
V_3 -> V_35 . V_5 . V_36 [ V_55 ] = V_28 ;
V_3 -> V_35 . V_5 . V_36 [ ! V_55 ] = V_39 ;
}
break;
case V_65 :
if ( V_56 == V_33 )
V_3 -> V_35 . V_5 . V_43 = F_21 ( V_13 ) ;
break;
case V_66 :
if ( V_56 == V_65 &&
type == V_67 &&
F_11 ( V_13 ) == V_3 -> V_35 . V_5 . V_43 )
F_22 ( V_68 , & V_3 -> V_61 ) ;
break;
case V_69 :
if ( V_3 -> V_35 . V_5 . V_42 == ! V_55 &&
V_3 -> V_35 . V_5 . V_40 == V_41 &&
type == V_70 ) {
V_3 -> V_35 . V_5 . V_36 [ ! V_55 ] = V_28 ;
V_3 -> V_35 . V_5 . V_36 [ V_55 ] = V_39 ;
V_3 -> V_35 . V_5 . V_43 = F_21 ( V_13 ) ;
V_57 = V_65 ;
break;
}
V_3 -> V_35 . V_5 . V_42 = V_55 ;
V_3 -> V_35 . V_5 . V_40 = type ;
F_23 ( & V_3 -> V_63 ) ;
if ( F_8 ( V_2 , V_44 ) )
F_9 ( V_2 , V_52 , 0 , V_7 , NULL , NULL , NULL ,
L_4 ) ;
return V_62 ;
case V_34 :
F_23 ( & V_3 -> V_63 ) ;
if ( F_8 ( V_2 , V_44 ) )
F_9 ( V_2 , V_52 , 0 , V_7 , NULL , NULL , NULL ,
L_2 ) ;
return - V_62 ;
}
V_3 -> V_35 . V_5 . V_42 = V_55 ;
V_3 -> V_35 . V_5 . V_40 = type ;
V_3 -> V_35 . V_5 . V_26 = V_57 ;
F_23 ( & V_3 -> V_63 ) ;
if ( V_57 != V_56 )
F_24 ( V_71 , V_3 ) ;
F_25 ( V_3 , V_51 , V_7 , V_22 [ V_57 ] ) ;
return V_62 ;
}
static int F_26 ( struct V_2 * V_2 , struct V_21 * V_72 ,
struct V_6 * V_7 , unsigned int V_8 ,
T_1 V_52 , unsigned int V_53 )
{
struct V_11 V_24 , * V_13 ;
unsigned int V_73 = V_7 -> V_74 - V_8 ;
unsigned int V_75 ;
const char * V_25 ;
V_13 = F_3 ( V_7 , V_8 , sizeof( V_24 ) , & V_24 ) ;
if ( V_13 == NULL ) {
V_25 = L_5 ;
goto V_32;
}
if ( V_13 -> V_76 * 4 < sizeof( struct V_11 ) ||
V_13 -> V_76 * 4 > V_73 ) {
V_25 = L_6 ;
goto V_32;
}
V_75 = V_73 ;
if ( V_13 -> V_77 ) {
V_75 = ( V_13 -> V_77 - 1 ) * 4 ;
if ( V_75 > V_73 ) {
V_25 = L_7 ;
goto V_32;
}
}
if ( V_2 -> V_3 . V_78 && V_53 == V_79 &&
F_27 ( V_7 , V_53 , V_8 , V_75 , V_44 ,
V_52 ) ) {
V_25 = L_8 ;
goto V_32;
}
if ( V_13 -> V_29 >= V_80 ) {
V_25 = L_9 ;
goto V_32;
}
return V_62 ;
V_32:
if ( F_8 ( V_2 , V_44 ) )
F_9 ( V_2 , V_52 , 0 , V_7 , NULL , NULL , NULL , L_3 , V_25 ) ;
return - V_62 ;
}
static bool F_28 ( const struct V_21 * V_3 )
{
switch ( V_3 -> V_35 . V_5 . V_26 ) {
case V_81 :
case V_82 :
case V_64 :
return true ;
default:
break;
}
return false ;
}
static void F_29 ( struct V_83 * V_84 ,
const struct V_9 * V_10 )
{
F_30 ( V_84 , L_10 ,
F_13 ( V_10 -> V_14 . V_15 . V_5 . V_16 ) ,
F_13 ( V_10 -> V_18 . V_15 . V_5 . V_16 ) ) ;
}
static void F_31 ( struct V_83 * V_84 , struct V_21 * V_3 )
{
F_30 ( V_84 , L_11 , V_85 [ V_3 -> V_35 . V_5 . V_26 ] ) ;
}
static int F_32 ( struct V_6 * V_7 , struct V_86 * V_87 ,
struct V_21 * V_3 )
{
struct V_86 * V_88 ;
F_20 ( & V_3 -> V_63 ) ;
V_88 = F_33 ( V_7 , V_89 | V_90 ) ;
if ( ! V_88 )
goto V_91;
if ( F_34 ( V_7 , V_92 , V_3 -> V_35 . V_5 . V_26 ) ||
F_34 ( V_7 , V_93 ,
V_3 -> V_35 . V_5 . V_36 [ V_37 ] ) ||
F_35 ( V_7 , V_94 ,
F_36 ( V_3 -> V_35 . V_5 . V_43 ) ,
V_95 ) )
goto V_91;
F_37 ( V_7 , V_88 ) ;
F_23 ( & V_3 -> V_63 ) ;
return 0 ;
V_91:
F_23 ( & V_3 -> V_63 ) ;
return - 1 ;
}
static int F_38 ( struct V_86 * V_96 [] , struct V_21 * V_3 )
{
struct V_86 * V_97 = V_96 [ V_89 ] ;
struct V_86 * V_98 [ V_99 + 1 ] ;
int V_100 ;
if ( ! V_97 )
return 0 ;
V_100 = F_39 ( V_98 , V_99 , V_97 ,
V_101 , NULL ) ;
if ( V_100 < 0 )
return V_100 ;
if ( ! V_98 [ V_92 ] ||
! V_98 [ V_93 ] ||
F_40 ( V_98 [ V_93 ] ) > V_102 ||
F_40 ( V_98 [ V_92 ] ) >= V_69 ) {
return - V_103 ;
}
F_20 ( & V_3 -> V_63 ) ;
V_3 -> V_35 . V_5 . V_26 = F_40 ( V_98 [ V_92 ] ) ;
if ( F_40 ( V_98 [ V_93 ] ) == V_28 ) {
V_3 -> V_35 . V_5 . V_36 [ V_37 ] = V_28 ;
V_3 -> V_35 . V_5 . V_36 [ V_38 ] = V_39 ;
} else {
V_3 -> V_35 . V_5 . V_36 [ V_37 ] = V_39 ;
V_3 -> V_35 . V_5 . V_36 [ V_38 ] = V_28 ;
}
if ( V_98 [ V_94 ] ) {
V_3 -> V_35 . V_5 . V_43 =
F_41 ( F_42 ( V_98 [ V_94 ] ) ) ;
}
F_23 ( & V_3 -> V_63 ) ;
return 0 ;
}
static int F_43 ( void )
{
return F_44 ( 0 )
+ F_45 ( V_101 , V_99 + 1 ) ;
}
static int F_46 ( struct V_86 * V_98 [] ,
struct V_2 * V_2 , void * V_104 )
{
struct V_1 * V_23 = F_1 ( V_2 ) ;
unsigned int * V_22 = V_104 ;
int V_105 ;
for ( V_105 = 0 ; V_105 < V_106 ; V_105 ++ )
V_22 [ V_105 ] = V_23 -> V_49 [ V_105 ] ;
for ( V_105 = V_107 + 1 ; V_105 < V_108 + 1 ; V_105 ++ ) {
if ( V_98 [ V_105 ] ) {
V_22 [ V_105 ] = F_14 ( F_47 ( V_98 [ V_105 ] ) ) * V_109 ;
}
}
return 0 ;
}
static int
F_48 ( struct V_6 * V_7 , const void * V_104 )
{
const unsigned int * V_22 = V_104 ;
int V_105 ;
for ( V_105 = V_107 + 1 ; V_105 < V_108 + 1 ; V_105 ++ ) {
if ( F_49 ( V_7 , V_105 , F_50 ( V_22 [ V_105 ] / V_109 ) ) )
goto V_91;
}
return 0 ;
V_91:
return - V_110 ;
}
static int F_51 ( struct V_2 * V_2 , struct V_111 * V_112 ,
struct V_1 * V_23 )
{
#ifdef F_52
if ( V_112 -> V_113 )
return 0 ;
V_112 -> V_113 = F_53 ( V_114 ,
sizeof( V_114 ) ,
V_115 ) ;
if ( ! V_112 -> V_113 )
return - V_116 ;
V_112 -> V_113 [ 0 ] . V_104 = & V_23 -> V_49 [ V_33 ] ;
V_112 -> V_113 [ 1 ] . V_104 = & V_23 -> V_49 [ V_65 ] ;
V_112 -> V_113 [ 2 ] . V_104 = & V_23 -> V_49 [ V_66 ] ;
V_112 -> V_113 [ 3 ] . V_104 = & V_23 -> V_49 [ V_117 ] ;
V_112 -> V_113 [ 4 ] . V_104 = & V_23 -> V_49 [ V_81 ] ;
V_112 -> V_113 [ 5 ] . V_104 = & V_23 -> V_49 [ V_82 ] ;
V_112 -> V_113 [ 6 ] . V_104 = & V_23 -> V_49 [ V_64 ] ;
V_112 -> V_113 [ 7 ] . V_104 = & V_23 -> V_31 ;
if ( V_2 -> V_118 != & V_119 )
V_112 -> V_113 [ 0 ] . V_120 = NULL ;
#endif
return 0 ;
}
static int F_54 ( struct V_2 * V_2 , T_3 V_35 )
{
struct V_1 * V_23 = F_1 ( V_2 ) ;
struct V_111 * V_112 = & V_23 -> V_112 ;
if ( ! V_112 -> V_121 ) {
V_23 -> V_31 = 1 ;
V_23 -> V_49 [ V_33 ] = 2 * V_122 ;
V_23 -> V_49 [ V_65 ] = 4 * V_122 ;
V_23 -> V_49 [ V_66 ] = 4 * V_122 ;
V_23 -> V_49 [ V_117 ] = 12 * 3600 * V_109 ;
V_23 -> V_49 [ V_81 ] = 64 * V_109 ;
V_23 -> V_49 [ V_82 ] = 64 * V_109 ;
V_23 -> V_49 [ V_64 ] = 2 * V_122 ;
}
return F_51 ( V_2 , V_112 , V_23 ) ;
}
static struct V_111 * F_55 ( struct V_2 * V_2 )
{
return & V_2 -> V_3 . V_4 . V_5 . V_112 ;
}
