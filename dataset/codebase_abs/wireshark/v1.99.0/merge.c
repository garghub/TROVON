T_1
F_1 ( int V_1 , char * const * V_2 ,
T_2 * * V_3 , int * V_4 , T_3 * * V_5 ,
int * V_6 )
{
T_4 V_7 ;
T_4 V_8 ;
T_5 V_9 = V_1 * sizeof( T_2 ) ;
T_2 * V_10 ;
T_6 V_11 ;
V_10 = ( T_2 * ) F_2 ( V_9 ) ;
* V_3 = V_10 ;
for ( V_7 = 0 ; V_7 < V_1 ; V_7 ++ ) {
V_10 [ V_7 ] . V_12 = V_2 [ V_7 ] ;
V_10 [ V_7 ] . V_13 = F_3 ( V_2 [ V_7 ] , V_14 , V_4 , V_5 , FALSE ) ;
V_10 [ V_7 ] . V_15 = 0 ;
V_10 [ V_7 ] . V_16 = V_17 ;
V_10 [ V_7 ] . V_18 = 0 ;
if ( ! V_10 [ V_7 ] . V_13 ) {
for ( V_8 = 0 ; V_8 < V_7 ; V_8 ++ )
F_4 ( V_10 [ V_8 ] . V_13 ) ;
* V_6 = V_7 ;
return FALSE ;
}
V_11 = F_5 ( V_10 [ V_7 ] . V_13 , V_4 ) ;
if ( V_11 == - 1 ) {
for ( V_8 = 0 ; V_8 + 1 > V_8 && V_8 <= V_7 ; V_8 ++ )
F_4 ( V_10 [ V_8 ] . V_13 ) ;
* V_6 = V_7 ;
return FALSE ;
}
V_10 [ V_7 ] . V_11 = V_11 ;
}
return TRUE ;
}
void
F_6 ( int V_19 , T_2 V_3 [] )
{
int V_7 ;
for ( V_7 = 0 ; V_7 < V_19 ; V_7 ++ ) {
F_4 ( V_3 [ V_7 ] . V_13 ) ;
}
}
int
F_7 ( int V_19 , T_2 V_10 [] )
{
int V_7 ;
int V_20 ;
V_20 = F_8 ( V_10 [ 0 ] . V_13 ) ;
for ( V_7 = 1 ; V_7 < V_19 ; V_7 ++ ) {
int V_21 = F_8 ( V_10 [ V_7 ] . V_13 ) ;
if ( V_20 != V_21 ) {
V_20 = V_22 ;
break;
}
}
return V_20 ;
}
int
F_9 ( int V_19 , T_2 V_3 [] )
{
int V_7 ;
int V_23 = 0 ;
int V_24 ;
for ( V_7 = 0 ; V_7 < V_19 ; V_7 ++ ) {
V_24 = F_10 ( V_3 [ V_7 ] . V_13 ) ;
if ( V_24 == 0 ) {
V_24 = V_25 ;
}
if ( V_24 > V_23 )
V_23 = V_24 ;
}
return V_23 ;
}
static T_1
F_11 ( T_7 * V_26 , T_7 * V_27 )
{
if ( V_26 -> V_28 > V_27 -> V_28 ) {
return FALSE ;
} else if ( V_26 -> V_28 < V_27 -> V_28 ) {
return TRUE ;
} else if ( V_26 -> V_29 > V_27 -> V_29 ) {
return FALSE ;
}
return TRUE ;
}
T_2 *
F_12 ( int V_1 , T_2 V_3 [] ,
int * V_4 , T_3 * * V_5 )
{
int V_7 ;
int V_30 = - 1 ;
T_7 V_31 = { sizeof( V_32 ) > sizeof( int ) ? V_33 : V_34 , V_34 } ;
struct V_35 * V_36 ;
for ( V_7 = 0 ; V_7 < V_1 ; V_7 ++ ) {
if ( V_3 [ V_7 ] . V_16 == V_17 ) {
if ( ! F_13 ( V_3 [ V_7 ] . V_13 , V_4 , V_5 , & V_3 [ V_7 ] . V_15 ) ) {
if ( * V_4 != 0 ) {
V_3 [ V_7 ] . V_16 = V_37 ;
return & V_3 [ V_7 ] ;
}
V_3 [ V_7 ] . V_16 = V_38 ;
} else
V_3 [ V_7 ] . V_16 = V_39 ;
}
if ( V_3 [ V_7 ] . V_16 == V_39 ) {
V_36 = F_14 ( V_3 [ V_7 ] . V_13 ) ;
if ( F_11 ( & V_36 -> V_40 , & V_31 ) ) {
V_31 = V_36 -> V_40 ;
V_30 = V_7 ;
}
}
}
if ( V_30 == - 1 ) {
* V_4 = 0 ;
return NULL ;
}
V_3 [ V_30 ] . V_16 = V_17 ;
V_3 [ V_30 ] . V_18 ++ ;
* V_4 = 0 ;
return & V_3 [ V_30 ] ;
}
T_2 *
F_15 ( int V_1 , T_2 V_3 [] ,
int * V_4 , T_3 * * V_5 )
{
int V_7 ;
for ( V_7 = 0 ; V_7 < V_1 ; V_7 ++ ) {
if ( V_3 [ V_7 ] . V_16 == V_38 )
continue;
if ( F_13 ( V_3 [ V_7 ] . V_13 , V_4 , V_5 , & V_3 [ V_7 ] . V_15 ) )
break;
if ( * V_4 != 0 ) {
V_3 [ V_7 ] . V_16 = V_37 ;
return & V_3 [ V_7 ] ;
}
V_3 [ V_7 ] . V_16 = V_38 ;
}
if ( V_7 == V_1 ) {
* V_4 = 0 ;
return NULL ;
}
* V_4 = 0 ;
return & V_3 [ V_7 ] ;
}
