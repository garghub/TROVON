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
static T_1 F_13 ( T_1 V_7 , T_1 V_15 , T_1 V_9 , T_1 V_10 , T_1 V_11 )
{
char * V_16 = ( char * ) ( long ) V_7 ;
bool V_17 = false ;
int V_18 [ 3 ] = {} ;
int V_19 = 0 ;
T_1 V_20 ;
char V_21 [ 64 ] ;
int V_22 ;
if ( V_16 [ -- V_15 ] != 0 )
return - V_23 ;
for ( V_22 = 0 ; V_22 < V_15 ; V_22 ++ ) {
if ( ( ! isprint ( V_16 [ V_22 ] ) && ! isspace ( V_16 [ V_22 ] ) ) || ! isascii ( V_16 [ V_22 ] ) )
return - V_23 ;
if ( V_16 [ V_22 ] != '%' )
continue;
if ( V_19 >= 3 )
return - V_23 ;
V_22 ++ ;
if ( V_16 [ V_22 ] == 'l' ) {
V_18 [ V_19 ] ++ ;
V_22 ++ ;
} else if ( V_16 [ V_22 ] == 'p' || V_16 [ V_22 ] == 's' ) {
V_18 [ V_19 ] ++ ;
V_22 ++ ;
if ( ! isspace ( V_16 [ V_22 ] ) && ! ispunct ( V_16 [ V_22 ] ) && V_16 [ V_22 ] != 0 )
return - V_23 ;
V_19 ++ ;
if ( V_16 [ V_22 - 1 ] == 's' ) {
if ( V_17 )
return - V_23 ;
V_17 = true ;
switch ( V_19 ) {
case 1 :
V_20 = V_9 ;
V_9 = ( long ) V_21 ;
break;
case 2 :
V_20 = V_10 ;
V_10 = ( long ) V_21 ;
break;
case 3 :
V_20 = V_11 ;
V_11 = ( long ) V_21 ;
break;
}
V_21 [ 0 ] = 0 ;
F_14 ( V_21 ,
( void * ) ( long ) V_20 ,
sizeof( V_21 ) ) ;
}
continue;
}
if ( V_16 [ V_22 ] == 'l' ) {
V_18 [ V_19 ] ++ ;
V_22 ++ ;
}
if ( V_16 [ V_22 ] != 'd' && V_16 [ V_22 ] != 'u' && V_16 [ V_22 ] != 'x' )
return - V_23 ;
V_19 ++ ;
}
return F_15 ( 1 , V_16 ,
V_18 [ 0 ] == 2 ? V_9 : V_18 [ 0 ] == 1 ? ( long ) V_9 : ( V_24 ) V_9 ,
V_18 [ 1 ] == 2 ? V_10 : V_18 [ 1 ] == 1 ? ( long ) V_10 : ( V_24 ) V_10 ,
V_18 [ 2 ] == 2 ? V_11 : V_18 [ 2 ] == 1 ? ( long ) V_11 : ( V_24 ) V_11 ) ;
}
const struct V_25 * F_16 ( void )
{
F_17 () ;
return & V_26 ;
}
static T_1 F_18 ( T_1 V_7 , T_1 V_27 , T_1 V_9 , T_1 V_10 , T_1 V_11 )
{
struct V_28 * V_29 = (struct V_28 * ) ( unsigned long ) V_7 ;
struct V_30 * V_31 = F_19 ( V_29 , struct V_30 , V_29 ) ;
struct V_32 * V_33 ;
struct V_34 * V_34 ;
if ( F_4 ( V_27 >= V_31 -> V_29 . V_35 ) )
return - V_36 ;
V_34 = F_20 ( V_31 -> V_37 [ V_27 ] ) ;
if ( F_4 ( ! V_34 ) )
return - V_38 ;
V_33 = V_34 -> V_39 ;
if ( V_33 -> V_40 != F_21 () ||
V_33 -> V_41 -> V_42 )
return - V_23 ;
if ( F_4 ( V_33 -> V_43 . type != V_44 &&
V_33 -> V_43 . type != V_45 ) )
return - V_23 ;
return F_22 ( V_33 ) ;
}
static T_1 F_23 ( T_1 V_7 , T_1 V_8 , T_1 V_46 , T_1 V_10 , T_1 V_13 )
{
struct V_47 * V_48 = (struct V_47 * ) ( long ) V_7 ;
struct V_28 * V_29 = (struct V_28 * ) ( long ) V_8 ;
struct V_30 * V_31 = F_19 ( V_29 , struct V_30 , V_29 ) ;
T_1 V_27 = V_46 & V_49 ;
void * V_50 = ( void * ) ( long ) V_10 ;
struct V_51 V_52 ;
struct V_32 * V_33 ;
struct V_34 * V_34 ;
struct V_53 V_54 = {
. V_13 = V_13 ,
. V_50 = V_50 ,
} ;
if ( F_4 ( V_46 & ~ ( V_49 ) ) )
return - V_23 ;
if ( V_27 == V_55 )
V_27 = F_24 () ;
if ( F_4 ( V_27 >= V_31 -> V_29 . V_35 ) )
return - V_36 ;
V_34 = F_20 ( V_31 -> V_37 [ V_27 ] ) ;
if ( F_4 ( ! V_34 ) )
return - V_38 ;
V_33 = V_34 -> V_39 ;
if ( F_4 ( V_33 -> V_43 . type != V_56 ||
V_33 -> V_43 . V_57 != V_58 ) )
return - V_23 ;
if ( F_4 ( V_33 -> V_40 != F_21 () ) )
return - V_59 ;
F_25 ( & V_52 , 0 , 0 ) ;
V_52 . V_54 = & V_54 ;
F_26 ( V_33 , & V_52 , V_48 ) ;
return 0 ;
}
static T_1 F_27 ( T_1 V_7 , T_1 V_8 , T_1 V_46 , T_1 V_10 , T_1 V_13 )
{
struct V_47 * V_48 = F_28 ( & V_60 ) ;
F_29 ( V_48 ) ;
return F_23 ( ( long ) V_48 , V_8 , V_46 , V_10 , V_13 ) ;
}
const struct V_25 * F_30 ( void )
{
return & V_61 ;
}
static const struct V_25 * F_31 ( enum V_62 V_63 )
{
switch ( V_63 ) {
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
return & V_77 ;
case V_78 :
return & V_79 ;
case V_80 :
return & V_81 ;
case V_82 :
return F_16 () ;
case V_83 :
return & V_84 ;
case V_85 :
return & V_86 ;
default:
return NULL ;
}
}
static const struct V_25 * F_32 ( enum V_62 V_63 )
{
switch ( V_63 ) {
case V_87 :
return & V_88 ;
case V_89 :
return & V_90 ;
default:
return F_31 ( V_63 ) ;
}
}
static bool F_33 ( int V_91 , int V_13 , enum V_92 type ,
enum V_93 * V_94 )
{
if ( V_91 < 0 || V_91 >= sizeof( struct V_47 ) )
return false ;
if ( type != V_95 )
return false ;
if ( V_91 % V_13 != 0 )
return false ;
return true ;
}
static T_1 F_34 ( T_1 V_7 , T_1 V_8 , T_1 V_27 , T_1 V_10 , T_1 V_13 )
{
T_1 V_3 = * ( long * ) ( V_96 ) V_7 ;
return F_23 ( V_3 , V_8 , V_27 , V_10 , V_13 ) ;
}
static T_1 F_35 ( T_1 V_7 , T_1 V_8 , T_1 V_9 , T_1 V_10 , T_1 V_11 )
{
T_1 V_3 = * ( long * ) ( V_96 ) V_7 ;
return F_36 ( V_3 , V_8 , V_9 , V_10 , V_11 ) ;
}
static const struct V_25 * F_37 ( enum V_62 V_63 )
{
switch ( V_63 ) {
case V_87 :
return & V_97 ;
case V_89 :
return & V_98 ;
default:
return F_31 ( V_63 ) ;
}
}
static bool F_38 ( int V_91 , int V_13 , enum V_92 type ,
enum V_93 * V_94 )
{
if ( V_91 < sizeof( void * ) || V_91 >= V_99 )
return false ;
if ( type != V_95 )
return false ;
if ( V_91 % V_13 != 0 )
return false ;
return true ;
}
static int T_2 F_39 ( void )
{
F_40 ( & V_100 ) ;
F_40 ( & V_101 ) ;
return 0 ;
}
