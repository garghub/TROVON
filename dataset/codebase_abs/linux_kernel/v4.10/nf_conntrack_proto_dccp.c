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
enum V_50 * V_51 ,
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
static void F_28 ( struct V_81 * V_82 ,
const struct V_9 * V_10 )
{
F_29 ( V_82 , L_10 ,
F_13 ( V_10 -> V_14 . V_15 . V_5 . V_16 ) ,
F_13 ( V_10 -> V_18 . V_15 . V_5 . V_16 ) ) ;
}
static void F_30 ( struct V_81 * V_82 , struct V_21 * V_3 )
{
F_29 ( V_82 , L_11 , V_83 [ V_3 -> V_35 . V_5 . V_26 ] ) ;
}
static int F_31 ( struct V_6 * V_7 , struct V_84 * V_85 ,
struct V_21 * V_3 )
{
struct V_84 * V_86 ;
F_20 ( & V_3 -> V_63 ) ;
V_86 = F_32 ( V_7 , V_87 | V_88 ) ;
if ( ! V_86 )
goto V_89;
if ( F_33 ( V_7 , V_90 , V_3 -> V_35 . V_5 . V_26 ) ||
F_33 ( V_7 , V_91 ,
V_3 -> V_35 . V_5 . V_36 [ V_37 ] ) ||
F_34 ( V_7 , V_92 ,
F_35 ( V_3 -> V_35 . V_5 . V_43 ) ,
V_93 ) )
goto V_89;
F_36 ( V_7 , V_86 ) ;
F_23 ( & V_3 -> V_63 ) ;
return 0 ;
V_89:
F_23 ( & V_3 -> V_63 ) ;
return - 1 ;
}
static int F_37 ( struct V_84 * V_94 [] , struct V_21 * V_3 )
{
struct V_84 * V_95 = V_94 [ V_87 ] ;
struct V_84 * V_96 [ V_97 + 1 ] ;
int V_98 ;
if ( ! V_95 )
return 0 ;
V_98 = F_38 ( V_96 , V_97 , V_95 ,
V_99 ) ;
if ( V_98 < 0 )
return V_98 ;
if ( ! V_96 [ V_90 ] ||
! V_96 [ V_91 ] ||
F_39 ( V_96 [ V_91 ] ) > V_100 ||
F_39 ( V_96 [ V_90 ] ) >= V_69 ) {
return - V_101 ;
}
F_20 ( & V_3 -> V_63 ) ;
V_3 -> V_35 . V_5 . V_26 = F_39 ( V_96 [ V_90 ] ) ;
if ( F_39 ( V_96 [ V_91 ] ) == V_28 ) {
V_3 -> V_35 . V_5 . V_36 [ V_37 ] = V_28 ;
V_3 -> V_35 . V_5 . V_36 [ V_38 ] = V_39 ;
} else {
V_3 -> V_35 . V_5 . V_36 [ V_37 ] = V_39 ;
V_3 -> V_35 . V_5 . V_36 [ V_38 ] = V_28 ;
}
if ( V_96 [ V_92 ] ) {
V_3 -> V_35 . V_5 . V_43 =
F_40 ( F_41 ( V_96 [ V_92 ] ) ) ;
}
F_23 ( & V_3 -> V_63 ) ;
return 0 ;
}
static int F_42 ( void )
{
return F_43 ( 0 )
+ F_44 ( V_99 , V_97 + 1 ) ;
}
static int F_45 ( struct V_84 * V_96 [] ,
struct V_2 * V_2 , void * V_102 )
{
struct V_1 * V_23 = F_1 ( V_2 ) ;
unsigned int * V_22 = V_102 ;
int V_103 ;
for ( V_103 = 0 ; V_103 < V_104 ; V_103 ++ )
V_22 [ V_103 ] = V_23 -> V_49 [ V_103 ] ;
for ( V_103 = V_105 + 1 ; V_103 < V_106 + 1 ; V_103 ++ ) {
if ( V_96 [ V_103 ] ) {
V_22 [ V_103 ] = F_14 ( F_46 ( V_96 [ V_103 ] ) ) * V_107 ;
}
}
return 0 ;
}
static int
F_47 ( struct V_6 * V_7 , const void * V_102 )
{
const unsigned int * V_22 = V_102 ;
int V_103 ;
for ( V_103 = V_105 + 1 ; V_103 < V_106 + 1 ; V_103 ++ ) {
if ( F_48 ( V_7 , V_103 , F_49 ( V_22 [ V_103 ] / V_107 ) ) )
goto V_89;
}
return 0 ;
V_89:
return - V_108 ;
}
static int F_50 ( struct V_2 * V_2 , struct V_109 * V_110 ,
struct V_1 * V_23 )
{
#ifdef F_51
if ( V_110 -> V_111 )
return 0 ;
V_110 -> V_111 = F_52 ( V_112 ,
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
static int F_53 ( struct V_2 * V_2 , T_3 V_35 )
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
return F_50 ( V_2 , V_110 , V_23 ) ;
}
