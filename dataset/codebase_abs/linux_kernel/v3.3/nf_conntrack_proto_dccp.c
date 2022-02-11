static inline struct V_1 * F_1 ( struct V_2 * V_2 )
{
return F_2 ( V_2 , V_3 ) ;
}
static bool F_3 ( const struct V_4 * V_5 , unsigned int V_6 ,
struct V_7 * V_8 )
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
unsigned int V_6 )
{
struct V_2 * V_2 = F_7 ( V_21 ) ;
struct V_1 * V_22 ;
struct V_9 V_23 , * V_11 ;
const char * V_24 ;
T_1 V_25 ;
V_11 = F_4 ( V_5 , V_6 , sizeof( V_23 ) , & V_11 ) ;
F_8 ( V_11 == NULL ) ;
V_25 = V_26 [ V_27 ] [ V_11 -> V_28 ] [ V_29 ] ;
switch ( V_25 ) {
default:
V_22 = F_1 ( V_2 ) ;
if ( V_22 -> V_30 == 0 ) {
V_24 = L_1 ;
goto V_31;
}
case V_32 :
break;
case V_33 :
V_24 = L_2 ;
goto V_31;
}
V_21 -> V_34 . V_14 . V_35 [ V_36 ] = V_27 ;
V_21 -> V_34 . V_14 . V_35 [ V_37 ] = V_38 ;
V_21 -> V_34 . V_14 . V_25 = V_29 ;
V_21 -> V_34 . V_14 . V_39 = V_40 ;
V_21 -> V_34 . V_14 . V_41 = V_36 ;
V_21 -> V_34 . V_14 . V_42 = 0 ;
return true ;
V_31:
if ( F_9 ( V_2 , V_43 ) )
F_10 ( F_11 ( V_21 ) , 0 , V_5 , NULL , NULL , NULL , V_24 ) ;
return false ;
}
static T_2 F_12 ( const struct V_9 * V_11 )
{
const struct V_44 * V_45 ;
V_45 = ( void * ) V_11 + F_13 ( V_11 ) ;
return ( ( T_2 ) F_14 ( V_45 -> V_46 ) << 32 ) +
F_15 ( V_45 -> V_47 ) ;
}
static int F_16 ( struct V_20 * V_21 , const struct V_4 * V_5 ,
unsigned int V_6 , enum V_48 V_49 ,
T_1 V_50 , unsigned int V_51 )
{
struct V_2 * V_2 = F_7 ( V_21 ) ;
struct V_1 * V_22 ;
enum V_52 V_53 = F_17 ( V_49 ) ;
struct V_9 V_23 , * V_11 ;
T_1 type , V_54 , V_55 ;
enum V_56 V_35 ;
V_11 = F_4 ( V_5 , V_6 , sizeof( V_23 ) , & V_11 ) ;
F_8 ( V_11 == NULL ) ;
type = V_11 -> V_28 ;
if ( type == V_57 &&
! F_18 ( V_58 , & V_21 -> V_59 ) ) {
F_19 ( V_21 , V_49 , V_5 ) ;
return V_60 ;
}
F_20 ( & V_21 -> V_61 ) ;
V_35 = V_21 -> V_34 . V_14 . V_35 [ V_53 ] ;
V_54 = V_21 -> V_34 . V_14 . V_25 ;
V_55 = V_26 [ V_35 ] [ type ] [ V_54 ] ;
switch ( V_55 ) {
case V_32 :
if ( V_54 == V_62 &&
V_35 == V_38 ) {
V_21 -> V_34 . V_14 . V_35 [ V_53 ] = V_27 ;
V_21 -> V_34 . V_14 . V_35 [ ! V_53 ] = V_38 ;
}
break;
case V_63 :
if ( V_54 == V_32 )
V_21 -> V_34 . V_14 . V_42 = F_21 ( V_11 ) ;
break;
case V_64 :
if ( V_54 == V_63 &&
type == V_65 &&
F_12 ( V_11 ) == V_21 -> V_34 . V_14 . V_42 )
F_22 ( V_66 , & V_21 -> V_59 ) ;
break;
case V_67 :
if ( V_21 -> V_34 . V_14 . V_41 == ! V_53 &&
V_21 -> V_34 . V_14 . V_39 == V_40 &&
type == V_68 ) {
V_21 -> V_34 . V_14 . V_35 [ ! V_53 ] = V_27 ;
V_21 -> V_34 . V_14 . V_35 [ V_53 ] = V_38 ;
V_21 -> V_34 . V_14 . V_42 = F_21 ( V_11 ) ;
V_55 = V_63 ;
break;
}
V_21 -> V_34 . V_14 . V_41 = V_53 ;
V_21 -> V_34 . V_14 . V_39 = type ;
F_23 ( & V_21 -> V_61 ) ;
if ( F_9 ( V_2 , V_43 ) )
F_10 ( V_50 , 0 , V_5 , NULL , NULL , NULL ,
L_3 ) ;
return V_60 ;
case V_33 :
F_23 ( & V_21 -> V_61 ) ;
if ( F_9 ( V_2 , V_43 ) )
F_10 ( V_50 , 0 , V_5 , NULL , NULL , NULL ,
L_2 ) ;
return - V_60 ;
}
V_21 -> V_34 . V_14 . V_41 = V_53 ;
V_21 -> V_34 . V_14 . V_39 = type ;
V_21 -> V_34 . V_14 . V_25 = V_55 ;
F_23 ( & V_21 -> V_61 ) ;
if ( V_55 != V_54 )
F_24 ( V_69 , V_21 ) ;
V_22 = F_1 ( V_2 ) ;
F_25 ( V_21 , V_49 , V_5 , V_22 -> V_70 [ V_55 ] ) ;
return V_60 ;
}
static int F_26 ( struct V_2 * V_2 , struct V_20 * V_71 ,
struct V_4 * V_5 , unsigned int V_6 ,
enum V_48 * V_49 ,
T_1 V_50 , unsigned int V_51 )
{
struct V_9 V_23 , * V_11 ;
unsigned int V_72 = V_5 -> V_73 - V_6 ;
unsigned int V_74 ;
const char * V_24 ;
V_11 = F_4 ( V_5 , V_6 , sizeof( V_23 ) , & V_11 ) ;
if ( V_11 == NULL ) {
V_24 = L_4 ;
goto V_31;
}
if ( V_11 -> V_75 * 4 < sizeof( struct V_9 ) ||
V_11 -> V_75 * 4 > V_72 ) {
V_24 = L_5 ;
goto V_31;
}
V_74 = V_72 ;
if ( V_11 -> V_76 ) {
V_74 = ( V_11 -> V_76 - 1 ) * 4 ;
if ( V_74 > V_72 ) {
V_24 = L_6 ;
goto V_31;
}
}
if ( V_2 -> V_21 . V_77 && V_51 == V_78 &&
F_27 ( V_5 , V_51 , V_6 , V_74 , V_43 ,
V_50 ) ) {
V_24 = L_7 ;
goto V_31;
}
if ( V_11 -> V_28 >= V_79 ) {
V_24 = L_8 ;
goto V_31;
}
return V_60 ;
V_31:
if ( F_9 ( V_2 , V_43 ) )
F_10 ( V_50 , 0 , V_5 , NULL , NULL , NULL , V_24 ) ;
return - V_60 ;
}
static int F_28 ( struct V_80 * V_81 ,
const struct V_7 * V_8 )
{
return F_29 ( V_81 , L_9 ,
F_14 ( V_8 -> V_12 . V_13 . V_14 . V_15 ) ,
F_14 ( V_8 -> V_17 . V_13 . V_14 . V_15 ) ) ;
}
static int F_30 ( struct V_80 * V_81 , struct V_20 * V_21 )
{
return F_29 ( V_81 , L_10 , V_82 [ V_21 -> V_34 . V_14 . V_25 ] ) ;
}
static int F_31 ( struct V_4 * V_5 , struct V_83 * V_84 ,
struct V_20 * V_21 )
{
struct V_83 * V_85 ;
F_20 ( & V_21 -> V_61 ) ;
V_85 = F_32 ( V_5 , V_86 | V_87 ) ;
if ( ! V_85 )
goto V_88;
F_33 ( V_5 , V_89 , V_21 -> V_34 . V_14 . V_25 ) ;
F_33 ( V_5 , V_90 ,
V_21 -> V_34 . V_14 . V_35 [ V_36 ] ) ;
F_34 ( V_5 , V_91 ,
F_35 ( V_21 -> V_34 . V_14 . V_42 ) ) ;
F_36 ( V_5 , V_85 ) ;
F_23 ( & V_21 -> V_61 ) ;
return 0 ;
V_88:
F_23 ( & V_21 -> V_61 ) ;
return - 1 ;
}
static int F_37 ( struct V_83 * V_92 [] , struct V_20 * V_21 )
{
struct V_83 * V_93 = V_92 [ V_86 ] ;
struct V_83 * V_94 [ V_95 + 1 ] ;
int V_96 ;
if ( ! V_93 )
return 0 ;
V_96 = F_38 ( V_94 , V_95 , V_93 ,
V_97 ) ;
if ( V_96 < 0 )
return V_96 ;
if ( ! V_94 [ V_89 ] ||
! V_94 [ V_90 ] ||
F_39 ( V_94 [ V_90 ] ) > V_98 ||
F_39 ( V_94 [ V_89 ] ) >= V_67 ) {
return - V_99 ;
}
F_20 ( & V_21 -> V_61 ) ;
V_21 -> V_34 . V_14 . V_25 = F_39 ( V_94 [ V_89 ] ) ;
if ( F_39 ( V_94 [ V_90 ] ) == V_27 ) {
V_21 -> V_34 . V_14 . V_35 [ V_36 ] = V_27 ;
V_21 -> V_34 . V_14 . V_35 [ V_37 ] = V_38 ;
} else {
V_21 -> V_34 . V_14 . V_35 [ V_36 ] = V_38 ;
V_21 -> V_34 . V_14 . V_35 [ V_37 ] = V_27 ;
}
if ( V_94 [ V_91 ] ) {
V_21 -> V_34 . V_14 . V_42 =
F_40 ( F_41 ( V_94 [ V_91 ] ) ) ;
}
F_23 ( & V_21 -> V_61 ) ;
return 0 ;
}
static int F_42 ( void )
{
return F_43 ( 0 )
+ F_44 ( V_97 , V_95 + 1 ) ;
}
static T_3 int F_45 ( struct V_2 * V_2 )
{
struct V_1 * V_22 = F_1 ( V_2 ) ;
V_22 -> V_30 = 1 ;
V_22 -> V_70 [ V_32 ] = 2 * V_100 ;
V_22 -> V_70 [ V_63 ] = 4 * V_100 ;
V_22 -> V_70 [ V_64 ] = 4 * V_100 ;
V_22 -> V_70 [ V_101 ] = 12 * 3600 * V_102 ;
V_22 -> V_70 [ V_103 ] = 64 * V_102 ;
V_22 -> V_70 [ V_104 ] = 64 * V_102 ;
V_22 -> V_70 [ V_62 ] = 2 * V_100 ;
#ifdef F_46
V_22 -> V_105 = F_47 ( V_106 ,
sizeof( V_106 ) , V_107 ) ;
if ( ! V_22 -> V_105 )
return - V_108 ;
V_22 -> V_105 [ 0 ] . V_109 = & V_22 -> V_70 [ V_32 ] ;
V_22 -> V_105 [ 1 ] . V_109 = & V_22 -> V_70 [ V_63 ] ;
V_22 -> V_105 [ 2 ] . V_109 = & V_22 -> V_70 [ V_64 ] ;
V_22 -> V_105 [ 3 ] . V_109 = & V_22 -> V_70 [ V_101 ] ;
V_22 -> V_105 [ 4 ] . V_109 = & V_22 -> V_70 [ V_103 ] ;
V_22 -> V_105 [ 5 ] . V_109 = & V_22 -> V_70 [ V_104 ] ;
V_22 -> V_105 [ 6 ] . V_109 = & V_22 -> V_70 [ V_62 ] ;
V_22 -> V_105 [ 7 ] . V_109 = & V_22 -> V_30 ;
V_22 -> V_110 = F_48 ( V_2 ,
V_111 , V_22 -> V_105 ) ;
if ( ! V_22 -> V_110 ) {
F_49 ( V_22 -> V_105 ) ;
return - V_108 ;
}
#endif
return 0 ;
}
static T_4 void F_50 ( struct V_2 * V_2 )
{
struct V_1 * V_22 = F_1 ( V_2 ) ;
#ifdef F_46
F_51 ( V_22 -> V_110 ) ;
F_49 ( V_22 -> V_105 ) ;
#endif
}
static int T_5 F_52 ( void )
{
int V_96 ;
V_96 = F_53 ( & V_112 ) ;
if ( V_96 < 0 )
goto V_113;
V_96 = F_54 ( & V_114 ) ;
if ( V_96 < 0 )
goto V_115;
V_96 = F_54 ( & V_116 ) ;
if ( V_96 < 0 )
goto V_117;
return 0 ;
V_117:
F_55 ( & V_114 ) ;
V_115:
F_56 ( & V_112 ) ;
V_113:
return V_96 ;
}
static void T_6 F_57 ( void )
{
F_56 ( & V_112 ) ;
F_55 ( & V_116 ) ;
F_55 ( & V_114 ) ;
}
