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
unsigned V_23 = 0 ;
* V_20 = NULL ;
for ( V_21 = 0 ; V_21 < F_2 ( V_24 ) ; V_21 ++ ) {
if ( V_24 [ V_21 ] . V_25 == V_22 )
return V_26 + V_23 ;
V_23 += V_24 [ V_21 ] . V_27 ;
}
for ( V_21 = 0 ; V_28 [ V_21 ] . V_20 ; V_21 ++ ) {
if ( V_28 [ V_21 ] . V_29 == V_18 &&
V_19 >= V_28 [ V_21 ] . V_30 &&
V_19 <= V_28 [ V_21 ] . V_31 ) {
* V_20 = V_28 [ V_21 ] . V_20 ;
return V_28 [ V_21 ] . V_32 ;
}
}
return NULL ;
}
const char * F_5 ( int V_33 )
{
const char * V_34 = NULL ;
int V_35 = F_6 ( V_33 ) ;
if ( V_35 < F_2 ( V_36 ) )
V_34 = V_36 [ V_35 ] ;
return V_34 ;
}
const char * F_7 ( int V_33 )
{
const char * V_37 = NULL ;
int V_38 = F_8 ( V_33 ) ;
if ( V_38 < F_2 ( V_39 ) )
V_37 = V_39 [ V_38 ] ;
return V_37 ;
}
const char * F_9 ( int V_33 )
{
const struct V_7 * V_8 = V_40 ;
int V_10 ;
for ( V_10 = 0 ; V_10 < F_2 ( V_40 ) ; ++ V_10 , ++ V_8 ) {
if ( V_33 == V_8 -> V_14 )
return V_8 -> V_15 ;
}
return NULL ;
}
