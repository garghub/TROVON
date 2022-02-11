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
default:
return - 1 ;
} ;
if ( F_2 ( V_4 , V_5 , V_3 ) )
return - 1 ;
return 0 ;
}
static int F_3 ( unsigned int V_2 , double * V_14 ,
unsigned int V_4 )
{
* V_14 = 0.0 ;
if ( ! V_15 [ V_4 ] )
return - 1 ;
* V_14 = ( 100.0 *
( V_16 [ V_2 ] [ V_4 ] - V_17 [ V_2 ] [ V_4 ] ) ) /
( V_18 - V_19 ) ;
F_4 ( L_1 ,
V_20 [ V_2 ] . V_21 , V_17 [ V_2 ] [ V_4 ] ,
V_16 [ V_2 ] [ V_4 ] , V_4 ) ;
F_4 ( L_2 ,
V_20 [ V_2 ] . V_21 ,
( unsigned long long ) V_18 - V_19 ,
V_16 [ V_2 ] [ V_4 ] - V_17 [ V_2 ] [ V_4 ] ,
* V_14 , V_4 ) ;
return 0 ;
}
static int F_5 ( void )
{
int V_22 , V_4 ;
unsigned long long V_3 ;
for ( V_22 = 0 ; V_22 < V_23 ; V_22 ++ ) {
for ( V_4 = 0 ; V_4 < V_24 ; V_4 ++ ) {
F_1 ( V_22 , & V_3 , V_4 ) ;
V_17 [ V_22 ] [ V_4 ] = V_3 ;
}
}
F_1 ( V_12 , & V_19 , V_25 ) ;
return 0 ;
}
static int F_6 ( void )
{
unsigned long long V_3 ;
int V_22 , V_4 ;
F_1 ( V_12 , & V_18 , V_25 ) ;
for ( V_22 = 0 ; V_22 < V_23 ; V_22 ++ ) {
for ( V_4 = 0 ; V_4 < V_24 ; V_4 ++ ) {
V_15 [ V_4 ] = ! F_1 ( V_22 , & V_3 , V_4 ) ;
V_16 [ V_22 ] [ V_4 ] = V_3 ;
}
}
return 0 ;
}
static struct V_26 * F_7 ( void )
{
int V_22 ;
if ( V_27 . V_28 != V_29
|| V_27 . V_30 != 6 )
return NULL ;
switch ( V_27 . V_31 ) {
case 0x2A :
case 0x2D :
case 0x3A :
case 0x3E :
case 0x3C :
case 0x3F :
case 0x45 :
case 0x46 :
break;
default:
return NULL ;
}
V_15 = calloc ( V_24 , sizeof( int ) ) ;
for ( V_22 = 0 ; V_22 < V_23 ; V_22 ++ ) {
V_17 [ V_22 ] = calloc ( V_24 ,
sizeof( unsigned long long ) ) ;
V_16 [ V_22 ] = calloc ( V_24 ,
sizeof( unsigned long long ) ) ;
}
V_32 . V_33 = strlen ( V_32 . V_21 ) ;
return & V_32 ;
}
void F_8 ( void )
{
int V_22 ;
free ( V_15 ) ;
for ( V_22 = 0 ; V_22 < V_23 ; V_22 ++ ) {
free ( V_17 [ V_22 ] ) ;
free ( V_16 [ V_22 ] ) ;
}
}
