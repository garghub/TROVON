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
static T_1 F_11 ( T_1 V_7 , T_1 V_8 , T_1 V_9 , T_1 V_10 , T_1 V_11 )
{
void * V_12 = ( void * ) ( long ) V_7 ;
int V_4 , V_13 = ( int ) V_8 ;
void * V_14 = ( void * ) ( long ) V_9 ;
V_4 = F_12 ( V_12 , V_14 , V_13 ) ;
if ( F_4 ( V_4 < 0 ) )
memset ( V_12 , 0 , V_13 ) ;
return V_4 ;
}
static T_1 F_13 ( T_1 V_7 , T_1 V_8 , T_1 V_9 , T_1 V_10 , T_1 V_11 )
{
void * V_14 = ( void * ) ( long ) V_7 ;
void * V_15 = ( void * ) ( long ) V_8 ;
int V_13 = ( int ) V_9 ;
if ( F_4 ( F_14 () ||
V_16 -> V_17 & ( V_18 | V_19 ) ) )
return - V_20 ;
if ( F_4 ( F_15 ( F_16 () , V_21 ) ) )
return - V_20 ;
if ( ! F_17 ( V_22 , V_14 , V_13 ) )
return - V_20 ;
return F_18 ( V_14 , V_15 , V_13 ) ;
}
static const struct V_23 * F_19 ( void )
{
F_20 ( L_1 ,
V_16 -> V_24 , F_21 ( V_16 ) ) ;
return & V_25 ;
}
static T_1 F_22 ( T_1 V_7 , T_1 V_26 , T_1 V_9 , T_1 V_10 , T_1 V_11 )
{
char * V_27 = ( char * ) ( long ) V_7 ;
bool V_28 = false ;
int V_29 [ 3 ] = {} ;
int V_30 = 0 ;
T_1 V_31 ;
char V_32 [ 64 ] ;
int V_33 ;
if ( V_27 [ -- V_26 ] != 0 )
return - V_34 ;
for ( V_33 = 0 ; V_33 < V_26 ; V_33 ++ ) {
if ( ( ! isprint ( V_27 [ V_33 ] ) && ! isspace ( V_27 [ V_33 ] ) ) || ! isascii ( V_27 [ V_33 ] ) )
return - V_34 ;
if ( V_27 [ V_33 ] != '%' )
continue;
if ( V_30 >= 3 )
return - V_34 ;
V_33 ++ ;
if ( V_27 [ V_33 ] == 'l' ) {
V_29 [ V_30 ] ++ ;
V_33 ++ ;
} else if ( V_27 [ V_33 ] == 'p' || V_27 [ V_33 ] == 's' ) {
V_29 [ V_30 ] ++ ;
V_33 ++ ;
if ( ! isspace ( V_27 [ V_33 ] ) && ! ispunct ( V_27 [ V_33 ] ) && V_27 [ V_33 ] != 0 )
return - V_34 ;
V_30 ++ ;
if ( V_27 [ V_33 - 1 ] == 's' ) {
if ( V_28 )
return - V_34 ;
V_28 = true ;
switch ( V_30 ) {
case 1 :
V_31 = V_9 ;
V_9 = ( long ) V_32 ;
break;
case 2 :
V_31 = V_10 ;
V_10 = ( long ) V_32 ;
break;
case 3 :
V_31 = V_11 ;
V_11 = ( long ) V_32 ;
break;
}
V_32 [ 0 ] = 0 ;
F_23 ( V_32 ,
( void * ) ( long ) V_31 ,
sizeof( V_32 ) ) ;
}
continue;
}
if ( V_27 [ V_33 ] == 'l' ) {
V_29 [ V_30 ] ++ ;
V_33 ++ ;
}
if ( V_27 [ V_33 ] != 'd' && V_27 [ V_33 ] != 'u' && V_27 [ V_33 ] != 'x' )
return - V_34 ;
V_30 ++ ;
}
return F_24 ( 1 , V_27 ,
V_29 [ 0 ] == 2 ? V_9 : V_29 [ 0 ] == 1 ? ( long ) V_9 : ( V_35 ) V_9 ,
V_29 [ 1 ] == 2 ? V_10 : V_29 [ 1 ] == 1 ? ( long ) V_10 : ( V_35 ) V_10 ,
V_29 [ 2 ] == 2 ? V_11 : V_29 [ 2 ] == 1 ? ( long ) V_11 : ( V_35 ) V_11 ) ;
}
const struct V_23 * F_25 ( void )
{
F_26 () ;
return & V_36 ;
}
static T_1 F_27 ( T_1 V_7 , T_1 V_17 , T_1 V_9 , T_1 V_10 , T_1 V_11 )
{
struct V_37 * V_38 = (struct V_37 * ) ( unsigned long ) V_7 ;
struct V_39 * V_40 = F_28 ( V_38 , struct V_39 , V_38 ) ;
unsigned int V_41 = F_29 () ;
T_1 V_42 = V_17 & V_43 ;
struct V_44 * V_45 ;
struct V_46 * V_47 ;
if ( F_4 ( V_17 & ~ ( V_43 ) ) )
return - V_34 ;
if ( V_42 == V_48 )
V_42 = V_41 ;
if ( F_4 ( V_42 >= V_40 -> V_38 . V_49 ) )
return - V_50 ;
V_45 = F_30 ( V_40 -> V_51 [ V_42 ] ) ;
if ( ! V_45 )
return - V_52 ;
V_47 = V_45 -> V_47 ;
if ( F_4 ( V_47 -> V_53 . type != V_54 &&
V_47 -> V_53 . type != V_55 ) )
return - V_34 ;
if ( F_4 ( V_47 -> V_56 != V_41 || V_47 -> V_57 -> V_58 ) )
return - V_34 ;
return F_31 ( V_47 ) ;
}
static T_2 T_1
F_32 ( struct V_59 * V_60 , struct V_37 * V_38 ,
T_1 V_17 , struct V_61 * V_62 )
{
struct V_39 * V_40 = F_28 ( V_38 , struct V_39 , V_38 ) ;
unsigned int V_41 = F_29 () ;
T_1 V_42 = V_17 & V_43 ;
struct V_63 V_64 ;
struct V_44 * V_45 ;
struct V_46 * V_47 ;
if ( V_42 == V_48 )
V_42 = V_41 ;
if ( F_4 ( V_42 >= V_40 -> V_38 . V_49 ) )
return - V_50 ;
V_45 = F_30 ( V_40 -> V_51 [ V_42 ] ) ;
if ( ! V_45 )
return - V_52 ;
V_47 = V_45 -> V_47 ;
if ( F_4 ( V_47 -> V_53 . type != V_65 ||
V_47 -> V_53 . V_66 != V_67 ) )
return - V_34 ;
if ( F_4 ( V_47 -> V_56 != V_41 ) )
return - V_68 ;
F_33 ( & V_64 , 0 , 0 ) ;
V_64 . V_62 = V_62 ;
F_34 ( V_47 , & V_64 , V_60 ) ;
return 0 ;
}
static T_1 F_35 ( T_1 V_7 , T_1 V_8 , T_1 V_17 , T_1 V_10 , T_1 V_13 )
{
struct V_59 * V_60 = (struct V_59 * ) ( long ) V_7 ;
struct V_37 * V_38 = (struct V_37 * ) ( long ) V_8 ;
void * V_69 = ( void * ) ( long ) V_10 ;
struct V_61 V_62 = {
. V_70 = {
. V_13 = V_13 ,
. V_69 = V_69 ,
} ,
} ;
if ( F_4 ( V_17 & ~ ( V_43 ) ) )
return - V_34 ;
return F_32 ( V_60 , V_38 , V_17 , & V_62 ) ;
}
T_1 F_36 ( struct V_37 * V_38 , T_1 V_17 , void * V_71 , T_1 V_72 ,
void * V_3 , T_1 V_73 , T_3 V_74 )
{
struct V_59 * V_60 = F_37 ( & V_75 ) ;
struct V_76 V_70 = {
. V_77 = V_74 ,
. V_13 = V_73 ,
. V_69 = V_3 ,
} ;
struct V_61 V_62 = {
. V_70 = {
{
. V_78 = V_73 ? & V_70 : NULL ,
} ,
. V_13 = V_72 ,
. V_69 = V_71 ,
} ,
} ;
F_38 ( V_60 ) ;
return F_32 ( V_60 , V_38 , V_17 , & V_62 ) ;
}
static T_1 F_39 ( T_1 V_7 , T_1 V_8 , T_1 V_9 , T_1 V_10 , T_1 V_11 )
{
return ( long ) V_16 ;
}
static const struct V_23 * F_40 ( enum V_79 V_80 )
{
switch ( V_80 ) {
case V_81 :
return & V_82 ;
case V_83 :
return & V_84 ;
case V_85 :
return & V_86 ;
case V_87 :
return & V_88 ;
case V_89 :
return & V_90 ;
case V_91 :
return & V_92 ;
case V_93 :
return & V_94 ;
case V_95 :
return & V_96 ;
case V_97 :
return & V_98 ;
case V_99 :
return & V_100 ;
case V_101 :
return F_25 () ;
case V_102 :
return & V_103 ;
case V_104 :
return & V_105 ;
case V_106 :
return F_19 () ;
default:
return NULL ;
}
}
static const struct V_23 * F_41 ( enum V_79 V_80 )
{
switch ( V_80 ) {
case V_107 :
return & V_108 ;
case V_109 :
return & V_110 ;
default:
return F_40 ( V_80 ) ;
}
}
static bool F_42 ( int V_111 , int V_13 , enum V_112 type ,
enum V_113 * V_114 )
{
if ( V_111 < 0 || V_111 >= sizeof( struct V_59 ) )
return false ;
if ( type != V_115 )
return false ;
if ( V_111 % V_13 != 0 )
return false ;
return true ;
}
static T_1 F_43 ( T_1 V_7 , T_1 V_8 , T_1 V_42 , T_1 V_10 , T_1 V_13 )
{
T_1 V_3 = * ( long * ) ( V_116 ) V_7 ;
return F_35 ( V_3 , V_8 , V_42 , V_10 , V_13 ) ;
}
static T_1 F_44 ( T_1 V_7 , T_1 V_8 , T_1 V_9 , T_1 V_10 , T_1 V_11 )
{
T_1 V_3 = * ( long * ) ( V_116 ) V_7 ;
return F_45 ( V_3 , V_8 , V_9 , V_10 , V_11 ) ;
}
static const struct V_23 * F_46 ( enum V_79 V_80 )
{
switch ( V_80 ) {
case V_107 :
return & V_117 ;
case V_109 :
return & V_118 ;
default:
return F_40 ( V_80 ) ;
}
}
static bool F_47 ( int V_111 , int V_13 , enum V_112 type ,
enum V_113 * V_114 )
{
if ( V_111 < sizeof( void * ) || V_111 >= V_119 )
return false ;
if ( type != V_115 )
return false ;
if ( V_111 % V_13 != 0 )
return false ;
return true ;
}
static int T_4 F_48 ( void )
{
F_49 ( & V_120 ) ;
F_49 ( & V_121 ) ;
return 0 ;
}
