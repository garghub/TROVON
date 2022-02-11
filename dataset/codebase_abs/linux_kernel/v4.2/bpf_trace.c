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
int V_17 [ 3 ] = {} ;
int V_18 = 0 ;
int V_19 ;
if ( V_16 [ -- V_15 ] != 0 )
return - V_20 ;
for ( V_19 = 0 ; V_19 < V_15 ; V_19 ++ ) {
if ( ( ! isprint ( V_16 [ V_19 ] ) && ! isspace ( V_16 [ V_19 ] ) ) || ! isascii ( V_16 [ V_19 ] ) )
return - V_20 ;
if ( V_16 [ V_19 ] != '%' )
continue;
if ( V_18 >= 3 )
return - V_20 ;
V_19 ++ ;
if ( V_16 [ V_19 ] == 'l' ) {
V_17 [ V_18 ] ++ ;
V_19 ++ ;
} else if ( V_16 [ V_19 ] == 'p' ) {
V_17 [ V_18 ] ++ ;
V_19 ++ ;
if ( ! isspace ( V_16 [ V_19 ] ) && ! ispunct ( V_16 [ V_19 ] ) && V_16 [ V_19 ] != 0 )
return - V_20 ;
V_18 ++ ;
continue;
}
if ( V_16 [ V_19 ] == 'l' ) {
V_17 [ V_18 ] ++ ;
V_19 ++ ;
}
if ( V_16 [ V_19 ] != 'd' && V_16 [ V_19 ] != 'u' && V_16 [ V_19 ] != 'x' )
return - V_20 ;
V_18 ++ ;
}
return F_14 ( 1 , V_16 ,
V_17 [ 0 ] == 2 ? V_9 : V_17 [ 0 ] == 1 ? ( long ) V_9 : ( V_21 ) V_9 ,
V_17 [ 1 ] == 2 ? V_10 : V_17 [ 1 ] == 1 ? ( long ) V_10 : ( V_21 ) V_10 ,
V_17 [ 2 ] == 2 ? V_11 : V_17 [ 2 ] == 1 ? ( long ) V_11 : ( V_21 ) V_11 ) ;
}
const struct V_22 * F_15 ( void )
{
F_16 () ;
return & V_23 ;
}
static const struct V_22 * F_17 ( enum V_24 V_25 )
{
switch ( V_25 ) {
case V_26 :
return & V_27 ;
case V_28 :
return & V_29 ;
case V_30 :
return & V_31 ;
case V_32 :
return & V_33 ;
case V_34 :
return & V_35 ;
case V_36 :
return & V_37 ;
case V_38 :
return & V_39 ;
case V_40 :
return & V_41 ;
case V_42 :
return & V_43 ;
case V_44 :
return F_15 () ;
case V_45 :
return & V_46 ;
default:
return NULL ;
}
}
static bool F_18 ( int V_47 , int V_13 , enum V_48 type )
{
if ( V_47 < 0 || V_47 >= sizeof( struct V_49 ) )
return false ;
if ( type != V_50 )
return false ;
if ( V_47 % V_13 != 0 )
return false ;
return true ;
}
static int T_2 F_19 ( void )
{
F_20 ( & V_51 ) ;
return 0 ;
}
