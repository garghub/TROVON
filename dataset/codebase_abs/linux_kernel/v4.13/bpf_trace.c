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
struct V_21 * V_22 = F_18 ( & V_23 ) ;
unsigned int V_24 = F_19 () ;
T_2 V_25 = V_16 & V_26 ;
struct V_27 * V_28 ;
struct V_29 * V_30 ;
if ( V_25 == V_31 )
V_25 = V_24 ;
if ( F_4 ( V_25 >= V_20 -> V_15 . V_32 ) )
return - V_33 ;
V_28 = F_20 ( V_20 -> V_34 [ V_25 ] ) ;
if ( ! V_28 )
return - V_35 ;
V_30 = V_28 -> V_30 ;
if ( F_4 ( V_30 -> V_36 . type != V_37 ||
V_30 -> V_36 . V_38 != V_39 ) )
return - V_40 ;
if ( F_4 ( V_30 -> V_41 != V_24 ) )
return - V_42 ;
F_21 ( V_22 , 0 , 0 ) ;
V_22 -> V_18 = V_18 ;
F_22 ( V_30 , V_22 , V_13 ) ;
return 0 ;
}
T_2 F_23 ( struct V_14 * V_15 , T_2 V_16 , void * V_43 , T_2 V_44 ,
void * V_3 , T_2 V_45 , T_3 V_46 )
{
struct V_12 * V_13 = F_18 ( & V_47 ) ;
struct V_48 V_49 = {
. V_50 = V_46 ,
. V_51 = V_45 ,
. V_52 = V_3 ,
} ;
struct V_17 V_18 = {
. V_49 = {
{
. V_53 = V_45 ? & V_49 : NULL ,
} ,
. V_51 = V_44 ,
. V_52 = V_43 ,
} ,
} ;
F_24 ( V_13 ) ;
return F_16 ( V_13 , V_15 , V_16 , & V_18 ) ;
}
static const struct V_7 * F_25 ( enum V_54 V_55 )
{
switch ( V_55 ) {
case V_56 :
return & V_57 ;
case V_58 :
return & V_59 ;
case V_60 :
return & V_61 ;
case V_62 :
return & V_63 ;
case V_64 :
return & V_65 ;
case V_66 :
return & V_67 ;
case V_68 :
return & V_69 ;
case V_70 :
return & V_71 ;
case V_72 :
return & V_73 ;
case V_74 :
return & V_75 ;
case V_76 :
return F_14 () ;
case V_77 :
return & V_78 ;
case V_79 :
return & V_80 ;
case V_81 :
return & V_82 ;
case V_83 :
return F_11 () ;
case V_84 :
return & V_85 ;
case V_86 :
return & V_87 ;
case V_88 :
return & V_89 ;
default:
return NULL ;
}
}
static const struct V_7 * F_26 ( enum V_54 V_55 )
{
switch ( V_55 ) {
case V_90 :
return & V_91 ;
case V_92 :
return & V_93 ;
default:
return F_25 ( V_55 ) ;
}
}
static bool F_27 ( int V_94 , int V_51 , enum V_95 type ,
struct V_96 * V_97 )
{
if ( V_94 < 0 || V_94 >= sizeof( struct V_12 ) )
return false ;
if ( type != V_98 )
return false ;
if ( V_94 % V_51 != 0 )
return false ;
if ( V_94 + V_51 > sizeof( struct V_12 ) )
return false ;
return true ;
}
static const struct V_7 * F_28 ( enum V_54 V_55 )
{
switch ( V_55 ) {
case V_90 :
return & V_99 ;
case V_92 :
return & V_100 ;
default:
return F_25 ( V_55 ) ;
}
}
static bool F_29 ( int V_94 , int V_51 , enum V_95 type ,
struct V_96 * V_97 )
{
if ( V_94 < sizeof( void * ) || V_94 >= V_101 )
return false ;
if ( type != V_98 )
return false ;
if ( V_94 % V_51 != 0 )
return false ;
F_30 ( V_101 % sizeof( V_102 ) ) ;
return true ;
}
static bool F_31 ( int V_94 , int V_51 , enum V_95 type ,
struct V_96 * V_97 )
{
const int V_103 = F_32 ( struct V_104 ,
V_105 ) ;
if ( V_94 < 0 || V_94 >= sizeof( struct V_104 ) )
return false ;
if ( type != V_98 )
return false ;
if ( V_94 % V_51 != 0 )
return false ;
switch ( V_94 ) {
case F_33 ( struct V_104 , V_105 ) :
F_34 ( V_97 , V_103 ) ;
if ( ! F_35 ( V_94 , V_51 , V_103 ) )
return false ;
break;
default:
if ( V_51 != sizeof( long ) )
return false ;
}
return true ;
}
static T_4 F_36 ( enum V_95 type ,
const struct V_106 * V_107 ,
struct V_106 * V_108 ,
struct V_1 * V_2 , T_4 * V_109 )
{
struct V_106 * V_110 = V_108 ;
switch ( V_107 -> V_94 ) {
case F_37 ( struct V_104 , V_105 ) :
* V_110 ++ = F_38 ( F_39 ( struct V_111 ,
V_52 ) , V_107 -> V_112 , V_107 -> V_113 ,
F_37 ( struct V_111 , V_52 ) ) ;
* V_110 ++ = F_38 ( V_114 , V_107 -> V_112 , V_107 -> V_112 ,
F_40 ( struct V_21 , V_115 , 8 ,
V_109 ) ) ;
break;
default:
* V_110 ++ = F_38 ( F_39 ( struct V_111 ,
V_13 ) , V_107 -> V_112 , V_107 -> V_113 ,
F_37 ( struct V_111 , V_13 ) ) ;
* V_110 ++ = F_38 ( F_41 ( long ) , V_107 -> V_112 , V_107 -> V_112 ,
V_107 -> V_94 ) ;
break;
}
return V_110 - V_108 ;
}
