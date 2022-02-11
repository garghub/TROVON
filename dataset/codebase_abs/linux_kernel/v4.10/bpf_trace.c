unsigned int F_1 ( struct V_1 * V_2 , void * V_3 )
{
unsigned int V_4 ;
if ( F_2 () )
return 1 ;
F_3 () ;
if ( F_4 ( F_5 ( V_5 ) != 1 ) ) {
V_4 = 0 ;
goto V_6;
}
F_6 () ;
V_4 = F_7 ( V_2 , V_3 ) ;
F_8 () ;
V_6:
F_9 ( V_5 ) ;
F_10 () ;
return V_4 ;
}
static const struct V_7 * F_11 ( void )
{
F_12 ( L_1 ,
V_8 -> V_9 , F_13 ( V_8 ) ) ;
return & V_10 ;
}
const struct V_7 * F_14 ( void )
{
F_15 () ;
return & V_11 ;
}
static T_1 T_2
F_16 ( struct V_12 * V_13 , struct V_14 * V_15 ,
T_2 V_16 , struct V_17 * V_18 )
{
struct V_19 * V_20 = F_17 ( V_15 , struct V_19 , V_15 ) ;
unsigned int V_21 = F_18 () ;
T_2 V_22 = V_16 & V_23 ;
struct V_24 V_25 ;
struct V_26 * V_27 ;
struct V_28 * V_29 ;
if ( V_22 == V_30 )
V_22 = V_21 ;
if ( F_4 ( V_22 >= V_20 -> V_15 . V_31 ) )
return - V_32 ;
V_27 = F_19 ( V_20 -> V_33 [ V_22 ] ) ;
if ( ! V_27 )
return - V_34 ;
V_29 = V_27 -> V_29 ;
if ( F_4 ( V_29 -> V_35 . type != V_36 ||
V_29 -> V_35 . V_37 != V_38 ) )
return - V_39 ;
if ( F_4 ( V_29 -> V_40 != V_21 ) )
return - V_41 ;
F_20 ( & V_25 , 0 , 0 ) ;
V_25 . V_18 = V_18 ;
F_21 ( V_29 , & V_25 , V_13 ) ;
return 0 ;
}
T_2 F_22 ( struct V_14 * V_15 , T_2 V_16 , void * V_42 , T_2 V_43 ,
void * V_3 , T_2 V_44 , T_3 V_45 )
{
struct V_12 * V_13 = F_23 ( & V_46 ) ;
struct V_47 V_48 = {
. V_49 = V_45 ,
. V_50 = V_44 ,
. V_51 = V_3 ,
} ;
struct V_17 V_18 = {
. V_48 = {
{
. V_52 = V_44 ? & V_48 : NULL ,
} ,
. V_50 = V_43 ,
. V_51 = V_42 ,
} ,
} ;
F_24 ( V_13 ) ;
return F_16 ( V_13 , V_15 , V_16 , & V_18 ) ;
}
static const struct V_7 * F_25 ( enum V_53 V_54 )
{
switch ( V_54 ) {
case V_55 :
return & V_56 ;
case V_57 :
return & V_58 ;
case V_59 :
return & V_60 ;
case V_61 :
return & V_62 ;
case V_63 :
return & V_64 ;
case V_65 :
return & V_66 ;
case V_67 :
return & V_68 ;
case V_69 :
return & V_70 ;
case V_71 :
return & V_72 ;
case V_73 :
return & V_74 ;
case V_75 :
return F_14 () ;
case V_76 :
return & V_77 ;
case V_78 :
return & V_79 ;
case V_80 :
return & V_81 ;
case V_82 :
return F_11 () ;
case V_83 :
return & V_84 ;
case V_85 :
return & V_86 ;
default:
return NULL ;
}
}
static const struct V_7 * F_26 ( enum V_53 V_54 )
{
switch ( V_54 ) {
case V_87 :
return & V_88 ;
case V_89 :
return & V_90 ;
default:
return F_25 ( V_54 ) ;
}
}
static bool F_27 ( int V_91 , int V_50 , enum V_92 type ,
enum V_93 * V_94 )
{
if ( V_91 < 0 || V_91 >= sizeof( struct V_12 ) )
return false ;
if ( type != V_95 )
return false ;
if ( V_91 % V_50 != 0 )
return false ;
return true ;
}
static const struct V_7 * F_28 ( enum V_53 V_54 )
{
switch ( V_54 ) {
case V_87 :
return & V_96 ;
case V_89 :
return & V_97 ;
default:
return F_25 ( V_54 ) ;
}
}
static bool F_29 ( int V_91 , int V_50 , enum V_92 type ,
enum V_93 * V_94 )
{
if ( V_91 < sizeof( void * ) || V_91 >= V_98 )
return false ;
if ( type != V_95 )
return false ;
if ( V_91 % V_50 != 0 )
return false ;
return true ;
}
static bool F_30 ( int V_91 , int V_50 , enum V_92 type ,
enum V_93 * V_94 )
{
if ( V_91 < 0 || V_91 >= sizeof( struct V_99 ) )
return false ;
if ( type != V_95 )
return false ;
if ( V_91 % V_50 != 0 )
return false ;
if ( V_91 == F_31 ( struct V_99 , V_100 ) ) {
if ( V_50 != sizeof( T_2 ) )
return false ;
} else {
if ( V_50 != sizeof( long ) )
return false ;
}
return true ;
}
static T_4 F_32 ( enum V_92 type , int V_101 ,
int V_102 , int V_103 ,
struct V_104 * V_105 ,
struct V_1 * V_2 )
{
struct V_104 * V_106 = V_105 ;
switch ( V_103 ) {
case F_31 ( struct V_99 , V_100 ) :
F_33 ( F_34 ( struct V_24 , V_107 ) != sizeof( T_2 ) ) ;
* V_106 ++ = F_35 ( F_36 ( struct V_108 ,
V_51 ) , V_101 , V_102 ,
F_31 ( struct V_108 , V_51 ) ) ;
* V_106 ++ = F_35 ( V_109 , V_101 , V_101 ,
F_31 ( struct V_24 , V_107 ) ) ;
break;
default:
* V_106 ++ = F_35 ( F_36 ( struct V_108 ,
V_13 ) , V_101 , V_102 ,
F_31 ( struct V_108 , V_13 ) ) ;
* V_106 ++ = F_35 ( F_37 ( long ) , V_101 , V_101 , V_103 ) ;
break;
}
return V_106 - V_105 ;
}
static int T_5 F_38 ( void )
{
F_39 ( & V_110 ) ;
F_39 ( & V_111 ) ;
F_39 ( & V_112 ) ;
return 0 ;
}
