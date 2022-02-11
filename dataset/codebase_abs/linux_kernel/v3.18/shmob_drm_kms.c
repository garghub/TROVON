const struct V_1 * V_1 ( T_1 V_2 )
{
unsigned int V_3 ;
for ( V_3 = 0 ; V_3 < F_1 ( V_4 ) ; ++ V_3 ) {
if ( V_4 [ V_3 ] . V_2 == V_2 )
return & V_4 [ V_3 ] ;
}
return NULL ;
}
static struct V_5 *
F_2 ( struct V_6 * V_7 , struct V_8 * V_9 ,
struct V_10 * V_11 )
{
const struct V_1 * V_12 ;
V_12 = V_1 ( V_11 -> V_13 ) ;
if ( V_12 == NULL ) {
F_3 ( V_7 -> V_7 , L_1 ,
V_11 -> V_13 ) ;
return F_4 ( - V_14 ) ;
}
if ( V_11 -> V_15 [ 0 ] & 7 || V_11 -> V_15 [ 0 ] >= 65536 ) {
F_3 ( V_7 -> V_7 , L_2 ,
V_11 -> V_15 [ 0 ] ) ;
return F_4 ( - V_14 ) ;
}
if ( V_12 -> V_16 ) {
unsigned int V_17 = V_12 -> V_18 == 24 ? 2 : 1 ;
if ( V_11 -> V_15 [ 1 ] != V_11 -> V_15 [ 0 ] * V_17 ) {
F_3 ( V_7 -> V_7 ,
L_3 ) ;
return F_4 ( - V_14 ) ;
}
}
return F_5 ( V_7 , V_9 , V_11 ) ;
}
int F_6 ( struct V_19 * V_20 )
{
F_7 ( V_20 -> V_21 ) ;
F_8 ( V_20 ) ;
F_9 ( V_20 ) ;
F_10 ( V_20 , & V_20 -> V_22 . V_22 ) ;
F_11 ( V_20 -> V_21 ) ;
V_20 -> V_21 -> V_23 . V_24 = 0 ;
V_20 -> V_21 -> V_23 . V_25 = 0 ;
V_20 -> V_21 -> V_23 . V_26 = 4095 ;
V_20 -> V_21 -> V_23 . V_27 = 4095 ;
V_20 -> V_21 -> V_23 . V_28 = & V_29 ;
F_12 ( V_20 -> V_21 ) ;
return 0 ;
}
