static int F_1 ( enum V_1 V_2 , unsigned long long * V_3 ,
unsigned int V_4 )
{
int V_5 ;
switch ( V_2 ) {
case V_6 :
V_5 = V_7 ;
break;
case V_8 :
V_5 = V_9 ;
break;
case V_10 :
V_5 = V_11 ;
break;
case V_12 :
V_5 = V_13 ;
break;
case V_14 :
V_5 = V_15 ;
break;
default:
return - 1 ;
} ;
if ( F_2 ( V_4 , V_5 , V_3 ) )
return - 1 ;
return 0 ;
}
static int F_3 ( unsigned int V_2 , double * V_16 ,
unsigned int V_4 )
{
* V_16 = 0.0 ;
if ( ! V_17 [ V_4 ] )
return - 1 ;
* V_16 = ( 100.0 *
( V_18 [ V_2 ] [ V_4 ] - V_19 [ V_2 ] [ V_4 ] ) ) /
( V_20 - V_21 ) ;
F_4 ( L_1 ,
V_22 [ V_2 ] . V_23 , V_19 [ V_2 ] [ V_4 ] ,
V_18 [ V_2 ] [ V_4 ] , V_4 ) ;
F_4 ( L_2 ,
V_22 [ V_2 ] . V_23 ,
( unsigned long long ) V_20 - V_21 ,
V_18 [ V_2 ] [ V_4 ] - V_19 [ V_2 ] [ V_4 ] ,
* V_16 , V_4 ) ;
return 0 ;
}
static int F_5 ( void )
{
int V_24 , V_4 ;
unsigned long long V_25 , V_3 ;
F_1 ( V_14 , & V_21 , V_26 ) ;
for ( V_24 = 0 ; V_24 < V_27 ; V_24 ++ ) {
for ( V_4 = 0 ; V_4 < V_28 ; V_4 ++ ) {
V_17 [ V_4 ] = ! F_1 ( V_24 , & V_3 , V_4 ) ;
V_19 [ V_24 ] [ V_4 ] = V_3 ;
}
}
F_1 ( V_14 , & V_25 , V_26 ) ;
F_4 ( L_3 , V_25 - V_21 ) ;
return 0 ;
}
static int F_6 ( void )
{
unsigned long long V_3 ;
unsigned long long V_25 ;
int V_24 , V_4 ;
F_1 ( V_14 , & V_20 , V_26 ) ;
for ( V_24 = 0 ; V_24 < V_27 ; V_24 ++ ) {
for ( V_4 = 0 ; V_4 < V_28 ; V_4 ++ ) {
V_17 [ V_4 ] = ! F_1 ( V_24 , & V_3 , V_4 ) ;
V_18 [ V_24 ] [ V_4 ] = V_3 ;
}
}
F_1 ( V_14 , & V_25 , V_26 ) ;
F_4 ( L_3 , V_25 - V_20 ) ;
return 0 ;
}
struct V_29 * F_7 ( void )
{
int V_24 ;
if ( V_30 . V_31 != V_32 )
return NULL ;
if ( ! ( V_30 . V_33 & V_34 ) )
return NULL ;
if ( ! ( V_30 . V_33 & V_35 ) )
return NULL ;
V_17 = calloc ( V_28 , sizeof( int ) ) ;
for ( V_24 = 0 ; V_24 < V_27 ; V_24 ++ ) {
V_19 [ V_24 ] = calloc ( V_28 ,
sizeof( unsigned long long ) ) ;
V_18 [ V_24 ] = calloc ( V_28 ,
sizeof( unsigned long long ) ) ;
}
V_36 . V_37 = strlen ( V_36 . V_23 ) ;
return & V_36 ;
}
void F_8 ( void )
{
int V_24 ;
for ( V_24 = 0 ; V_24 < V_27 ; V_24 ++ ) {
free ( V_19 [ V_24 ] ) ;
free ( V_18 [ V_24 ] ) ;
}
free ( V_17 ) ;
}
