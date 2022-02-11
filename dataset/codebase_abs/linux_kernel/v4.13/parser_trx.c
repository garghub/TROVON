static const char * F_1 ( struct V_1 * V_2 ,
T_1 V_3 )
{
T_2 V_4 ;
T_1 V_5 ;
int V_6 ;
V_6 = F_2 ( V_2 , V_3 , sizeof( V_4 ) , & V_5 ,
( V_7 * ) & V_4 ) ;
if ( V_6 && ! F_3 ( V_6 ) ) {
F_4 ( L_1 ,
V_3 , V_6 ) ;
goto V_8;
}
if ( V_4 == V_9 )
return L_2 ;
V_8:
return L_3 ;
}
static int F_5 ( struct V_1 * V_10 ,
const struct V_11 * * V_12 ,
struct V_13 * V_14 )
{
struct V_11 * V_15 ;
struct V_11 * V_16 ;
struct V_17 V_18 ;
T_1 V_5 ;
V_7 V_19 = 0 , V_20 = 0 ;
int V_6 ;
V_15 = F_6 ( sizeof( struct V_11 ) * V_21 ,
V_22 ) ;
if ( ! V_15 )
return - V_23 ;
V_6 = F_2 ( V_10 , 0 , sizeof( V_18 ) , & V_5 , ( V_7 * ) & V_18 ) ;
if ( V_6 ) {
F_4 ( L_4 , V_6 ) ;
F_7 ( V_15 ) ;
return V_6 ;
}
if ( V_18 . V_24 != V_25 ) {
F_7 ( V_15 ) ;
return - V_26 ;
}
if ( V_18 . V_3 [ 2 ] ) {
V_16 = & V_15 [ V_19 ++ ] ;
V_16 -> V_27 = L_5 ;
V_16 -> V_3 = V_18 . V_3 [ V_20 ] ;
V_20 ++ ;
}
if ( V_18 . V_3 [ V_20 ] ) {
V_16 = & V_15 [ V_19 ++ ] ;
V_16 -> V_27 = L_6 ;
V_16 -> V_3 = V_18 . V_3 [ V_20 ] ;
V_20 ++ ;
}
if ( V_18 . V_3 [ V_20 ] ) {
V_16 = & V_15 [ V_19 ++ ] ;
V_16 -> V_27 = F_1 ( V_10 , V_18 . V_3 [ V_20 ] ) ;
V_16 -> V_3 = V_18 . V_3 [ V_20 ] ;
V_20 ++ ;
}
for ( V_20 = 0 ; V_20 < V_19 ; V_20 ++ ) {
T_3 V_28 = ( V_20 < V_19 - 1 ) ?
V_15 [ V_20 + 1 ] . V_3 : V_10 -> V_29 ;
V_15 [ V_20 ] . V_29 = V_28 - V_15 [ V_20 ] . V_3 ;
}
* V_12 = V_15 ;
return V_20 ;
}
