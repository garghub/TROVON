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
if ( F_4 ( V_27 >= V_31 -> V_29 . V_34 ) )
return - V_35 ;
V_33 = (struct V_32 * ) V_31 -> V_36 [ V_27 ] ;
if ( ! V_33 )
return - V_37 ;
return F_20 ( V_33 ) ;
}
static const struct V_25 * F_21 ( enum V_38 V_39 )
{
switch ( V_39 ) {
case V_40 :
return & V_41 ;
case V_42 :
return & V_43 ;
case V_44 :
return & V_45 ;
case V_46 :
return & V_47 ;
case V_48 :
return & V_49 ;
case V_50 :
return & V_51 ;
case V_52 :
return & V_53 ;
case V_54 :
return & V_55 ;
case V_56 :
return & V_57 ;
case V_58 :
return F_16 () ;
case V_59 :
return & V_60 ;
case V_61 :
return & V_62 ;
default:
return NULL ;
}
}
static bool F_22 ( int V_63 , int V_13 , enum V_64 type )
{
if ( V_63 < 0 || V_63 >= sizeof( struct V_65 ) )
return false ;
if ( type != V_66 )
return false ;
if ( V_63 % V_13 != 0 )
return false ;
return true ;
}
static int T_2 F_23 ( void )
{
F_24 ( & V_67 ) ;
return 0 ;
}
