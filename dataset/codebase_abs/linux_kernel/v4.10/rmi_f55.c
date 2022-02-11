static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_5 * V_6 = F_2 ( & V_4 -> V_7 ) ;
struct V_8 * V_9 ;
int error ;
V_9 = F_2 ( & V_2 -> V_7 ) ;
error = F_3 ( V_2 -> V_4 , V_2 -> V_10 . V_11 ,
& V_9 -> V_12 , sizeof( V_9 -> V_12 ) ) ;
if ( error ) {
F_4 ( & V_2 -> V_7 , L_1 ,
V_13 ) ;
return error ;
}
V_9 -> V_14 = V_9 -> V_12 [ V_15 ] ;
V_9 -> V_16 = V_9 -> V_12 [ V_17 ] ;
V_9 -> V_18 = V_9 -> V_14 ;
V_9 -> V_19 = V_9 -> V_14 ;
V_6 -> V_14 = V_9 -> V_18 ;
V_6 -> V_16 = V_9 -> V_18 ;
if ( V_9 -> V_12 [ V_20 ] & V_21 ) {
int V_22 , V_23 ;
T_1 V_24 [ 256 ] ;
error = F_3 ( V_2 -> V_4 ,
V_2 -> V_10 . V_25 + 1 ,
V_24 , V_9 -> V_14 ) ;
if ( ! error ) {
V_23 = 0 ;
for ( V_22 = 0 ; V_22 < V_9 -> V_14 ; V_22 ++ ) {
if ( V_24 [ V_22 ] != 0xff )
V_23 ++ ;
}
V_9 -> V_18 = V_23 ;
V_6 -> V_14 = V_23 ;
}
error = F_3 ( V_2 -> V_4 ,
V_2 -> V_10 . V_25 + 2 ,
V_24 , V_9 -> V_16 ) ;
if ( ! error ) {
V_23 = 0 ;
for ( V_22 = 0 ; V_22 < V_9 -> V_16 ; V_22 ++ ) {
if ( V_24 [ V_22 ] != 0xff )
V_23 ++ ;
}
V_9 -> V_19 = V_23 ;
V_6 -> V_16 = V_23 ;
}
}
F_5 ( V_26 , & V_2 -> V_7 , L_2 ,
V_9 -> V_18 , V_9 -> V_14 ) ;
F_5 ( V_26 , & V_2 -> V_7 , L_3 ,
V_9 -> V_19 , V_9 -> V_16 ) ;
return 0 ;
}
static int F_6 ( struct V_1 * V_2 )
{
struct V_8 * V_9 ;
V_9 = F_7 ( & V_2 -> V_7 , sizeof( struct V_8 ) , V_27 ) ;
if ( ! V_9 )
return - V_28 ;
V_9 -> V_2 = V_2 ;
F_8 ( & V_2 -> V_7 , V_9 ) ;
return F_1 ( V_2 ) ;
}
