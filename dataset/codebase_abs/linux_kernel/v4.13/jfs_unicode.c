int F_1 ( char * V_1 , const T_1 * V_2 ,
int V_3 , struct V_4 * V_5 )
{
int V_6 ;
int V_7 = 0 ;
static int V_8 = 5 ;
int V_9 = ! ! V_8 ;
if ( V_5 ) {
for ( V_6 = 0 ; ( V_6 < V_3 ) && V_2 [ V_6 ] ; V_6 ++ ) {
int V_10 ;
V_10 =
V_5 -> V_11 ( F_2 ( V_2 [ V_6 ] ) ,
& V_1 [ V_7 ] ,
V_12 ) ;
if ( V_10 > 0 )
V_7 += V_10 ;
else
V_1 [ V_7 ++ ] = '?' ;
}
} else {
for ( V_6 = 0 ; ( V_6 < V_3 ) && V_2 [ V_6 ] ; V_6 ++ ) {
if ( F_3 ( F_2 ( V_2 [ V_6 ] ) & 0xff00 ) ) {
V_1 [ V_6 ] = '?' ;
if ( F_3 ( V_9 ) ) {
V_9 -- ;
V_8 -- ;
F_4 ( V_13
L_1 ,
F_2 ( V_2 [ V_6 ] ) ) ;
F_4 ( V_13
L_2 ) ;
}
}
else
V_1 [ V_6 ] = ( char ) ( F_2 ( V_2 [ V_6 ] ) ) ;
}
V_7 = V_6 ;
}
V_1 [ V_7 ] = 0 ;
return V_7 ;
}
static int F_5 ( T_2 * V_1 , const unsigned char * V_2 , int V_3 ,
struct V_4 * V_5 )
{
int V_10 ;
int V_6 ;
if ( V_5 ) {
for ( V_6 = 0 ; V_3 && * V_2 ; V_6 ++ , V_2 += V_10 , V_3 -= V_10 )
{
V_10 = V_5 -> V_14 ( V_2 , V_3 , & V_1 [ V_6 ] ) ;
if ( V_10 < 1 ) {
F_6 ( L_3 ,
V_10 ) ;
F_6 ( L_4 ,
V_5 -> V_15 , * V_2 ) ;
return V_10 ;
}
}
} else {
for ( V_6 = 0 ; ( V_6 < V_3 ) && V_2 [ V_6 ] ; V_6 ++ )
V_1 [ V_6 ] = ( T_2 ) V_2 [ V_6 ] ;
}
V_1 [ V_6 ] = 0 ;
return V_6 ;
}
int F_7 ( struct V_16 * V_17 , struct V_18 * V_18 )
{
struct V_4 * V_19 = F_8 ( V_18 -> V_20 ) -> V_19 ;
int V_21 = V_18 -> V_22 . V_3 ;
if ( V_21 > V_23 )
return - V_24 ;
V_17 -> V_25 =
F_9 ( ( V_21 + 1 ) * sizeof( T_2 ) , V_26 ) ;
if ( V_17 -> V_25 == NULL )
return - V_27 ;
V_17 -> V_28 = F_5 ( V_17 -> V_25 , V_18 -> V_22 . V_25 ,
V_21 , V_19 ) ;
if ( V_17 -> V_28 < 0 ) {
F_10 ( V_17 -> V_25 ) ;
return V_17 -> V_28 ;
}
return 0 ;
}
