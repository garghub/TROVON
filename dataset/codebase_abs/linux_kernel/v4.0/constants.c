bool F_1 ( int V_1 , int V_2 ,
const char * * V_3 , const char * * V_4 )
{
struct V_5 * V_6 ;
const struct V_7 * V_8 = NULL ;
int V_9 , V_10 ;
* V_3 = NULL ;
if ( V_1 >= V_11 )
return false ;
if ( V_1 < F_2 ( V_12 ) )
* V_3 = V_12 [ V_1 ] ;
for ( V_6 = V_13 ; V_6 -> V_8 ; ++ V_6 ) {
if ( V_6 -> V_1 == V_1 ) {
V_8 = V_6 -> V_8 ;
V_9 = V_6 -> V_9 ;
break;
}
}
if ( ! V_8 )
return false ;
for ( V_10 = 0 ; V_10 < V_9 ; ++ V_10 , ++ V_8 ) {
if ( V_2 == V_8 -> V_14 )
break;
}
if ( V_10 < V_9 )
* V_4 = V_8 -> V_15 ;
return true ;
}
const char *
F_3 ( unsigned char V_16 ) {
if ( V_16 <= 0xE )
return V_17 [ V_16 ] ;
return NULL ;
}
const char *
F_4 ( unsigned char V_18 , unsigned char V_19 , const char * * V_20 )
{
int V_21 ;
unsigned short V_22 = ( ( V_18 << 8 ) | V_19 ) ;
* V_20 = NULL ;
for ( V_21 = 0 ; V_23 [ V_21 ] . V_24 ; V_21 ++ )
if ( V_23 [ V_21 ] . V_25 == V_22 )
return V_23 [ V_21 ] . V_24 ;
for ( V_21 = 0 ; V_26 [ V_21 ] . V_20 ; V_21 ++ ) {
if ( V_26 [ V_21 ] . V_27 == V_18 &&
V_19 >= V_26 [ V_21 ] . V_28 &&
V_19 <= V_26 [ V_21 ] . V_29 ) {
* V_20 = V_26 [ V_21 ] . V_20 ;
return V_26 [ V_21 ] . V_30 ;
}
}
return NULL ;
}
const char * F_5 ( int V_31 )
{
const char * V_32 = NULL ;
int V_33 = F_6 ( V_31 ) ;
if ( V_33 < F_2 ( V_34 ) )
V_32 = V_34 [ V_33 ] ;
return V_32 ;
}
const char * F_7 ( int V_31 )
{
const char * V_35 = NULL ;
int V_36 = F_8 ( V_31 ) ;
if ( V_36 < F_2 ( V_37 ) )
V_35 = V_37 [ V_36 ] ;
return V_35 ;
}
const char * F_9 ( int V_31 )
{
const struct V_7 * V_8 = V_38 ;
int V_10 ;
for ( V_10 = 0 ; V_10 < F_2 ( V_38 ) ; ++ V_10 , ++ V_8 ) {
if ( V_31 == V_8 -> V_14 )
return V_8 -> V_15 ;
}
return NULL ;
}
