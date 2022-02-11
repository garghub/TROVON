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
int V_13 = ( int ) V_8 ;
void * V_14 = ( void * ) ( long ) V_9 ;
return F_12 ( V_12 , V_14 , V_13 ) ;
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
V_34 = (struct V_34 * ) V_31 -> V_37 [ V_27 ] ;
if ( F_4 ( ! V_34 ) )
return - V_38 ;
V_33 = V_34 -> V_39 ;
if ( V_33 -> V_40 != F_20 () ||
V_33 -> V_41 -> V_42 )
return - V_23 ;
return F_21 ( V_33 ) ;
}
static T_1 F_22 ( T_1 V_7 , T_1 V_8 , T_1 V_27 , T_1 V_10 , T_1 V_13 )
{
struct V_43 * V_44 = (struct V_43 * ) ( long ) V_7 ;
struct V_28 * V_29 = (struct V_28 * ) ( long ) V_8 ;
struct V_30 * V_31 = F_19 ( V_29 , struct V_30 , V_29 ) ;
void * V_45 = ( void * ) ( long ) V_10 ;
struct V_46 V_47 ;
struct V_32 * V_33 ;
struct V_34 * V_34 ;
struct V_48 V_49 = {
. V_13 = V_13 ,
. V_45 = V_45 ,
} ;
if ( F_4 ( V_27 >= V_31 -> V_29 . V_35 ) )
return - V_36 ;
V_34 = (struct V_34 * ) V_31 -> V_37 [ V_27 ] ;
if ( F_4 ( ! V_34 ) )
return - V_38 ;
V_33 = V_34 -> V_39 ;
if ( F_4 ( V_33 -> V_50 . type != V_51 ||
V_33 -> V_50 . V_52 != V_53 ) )
return - V_23 ;
if ( F_4 ( V_33 -> V_40 != F_20 () ) )
return - V_54 ;
F_23 ( & V_47 , 0 , 0 ) ;
V_47 . V_49 = & V_49 ;
F_24 ( V_33 , & V_47 , V_44 ) ;
return 0 ;
}
static const struct V_25 * F_25 ( enum V_55 V_56 )
{
switch ( V_56 ) {
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
return F_16 () ;
case V_76 :
return & V_77 ;
case V_78 :
return & V_79 ;
case V_80 :
return & V_81 ;
default:
return NULL ;
}
}
static bool F_26 ( int V_82 , int V_13 , enum V_83 type )
{
if ( V_82 < 0 || V_82 >= sizeof( struct V_43 ) )
return false ;
if ( type != V_84 )
return false ;
if ( V_82 % V_13 != 0 )
return false ;
return true ;
}
static int T_2 F_27 ( void )
{
F_28 ( & V_85 ) ;
return 0 ;
}
