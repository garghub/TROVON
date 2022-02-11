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
static T_1 F_13 ( T_1 V_7 , T_1 V_8 , T_1 V_9 , T_1 V_10 , T_1 V_11 )
{
return F_14 () ;
}
static T_1 F_15 ( T_1 V_7 , T_1 V_15 , T_1 V_9 , T_1 V_10 , T_1 V_11 )
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
return F_16 ( 1 , V_16 ,
V_17 [ 0 ] == 2 ? V_9 : V_17 [ 0 ] == 1 ? ( long ) V_9 : ( V_21 ) V_9 ,
V_17 [ 1 ] == 2 ? V_10 : V_17 [ 1 ] == 1 ? ( long ) V_10 : ( V_21 ) V_10 ,
V_17 [ 2 ] == 2 ? V_11 : V_17 [ 2 ] == 1 ? ( long ) V_11 : ( V_21 ) V_11 ) ;
}
static const struct V_22 * F_17 ( enum V_23 V_24 )
{
switch ( V_24 ) {
case V_25 :
return & V_26 ;
case V_27 :
return & V_28 ;
case V_29 :
return & V_30 ;
case V_31 :
return & V_32 ;
case V_33 :
return & V_34 ;
case V_35 :
F_18 () ;
return & V_36 ;
default:
return NULL ;
}
}
static bool F_19 ( int V_37 , int V_13 , enum V_38 type )
{
if ( V_37 < 0 || V_37 >= sizeof( struct V_39 ) )
return false ;
if ( type != V_40 )
return false ;
if ( V_37 % V_13 != 0 )
return false ;
return true ;
}
static int T_2 F_20 ( void )
{
F_21 ( & V_41 ) ;
return 0 ;
}
