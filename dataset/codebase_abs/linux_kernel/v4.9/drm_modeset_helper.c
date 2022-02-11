void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 , * V_5 ;
struct V_6 V_7 ;
F_2 ( & V_7 ) ;
F_3 (connector, tmp,
&dev->mode_config.connector_list, head) {
if ( V_4 -> V_8 == V_9 ||
V_4 -> V_8 == V_10 )
F_4 ( & V_4 -> V_11 , & V_7 ) ;
}
F_5 ( & V_7 , & V_2 -> V_12 . V_13 ) ;
}
void F_6 ( struct V_14 * V_15 ,
const struct V_16 * V_17 )
{
int V_18 ;
V_15 -> V_19 = V_17 -> V_19 ;
V_15 -> V_20 = V_17 -> V_20 ;
for ( V_18 = 0 ; V_18 < 4 ; V_18 ++ ) {
V_15 -> V_21 [ V_18 ] = V_17 -> V_21 [ V_18 ] ;
V_15 -> V_22 [ V_18 ] = V_17 -> V_22 [ V_18 ] ;
V_15 -> V_23 [ V_18 ] = V_17 -> V_23 [ V_18 ] ;
}
F_7 ( V_17 -> V_24 , & V_15 -> V_25 ,
& V_15 -> V_26 ) ;
V_15 -> V_24 = V_17 -> V_24 ;
V_15 -> V_27 = V_17 -> V_27 ;
}
static struct V_28 * F_8 ( struct V_1 * V_2 )
{
struct V_28 * V_29 ;
int V_30 ;
V_29 = F_9 ( sizeof( * V_29 ) , V_31 ) ;
if ( V_29 == NULL ) {
F_10 ( L_1 ) ;
return NULL ;
}
V_29 -> V_32 = true ;
V_30 = F_11 ( V_2 , V_29 , 0 ,
& V_33 ,
V_34 ,
F_12 ( V_34 ) ,
V_35 , NULL ) ;
if ( V_30 ) {
F_13 ( V_29 ) ;
V_29 = NULL ;
}
return V_29 ;
}
int F_14 ( struct V_1 * V_2 , struct V_36 * V_37 ,
const struct V_38 * V_39 )
{
struct V_28 * V_29 ;
V_29 = F_8 ( V_2 ) ;
return F_15 ( V_2 , V_37 , V_29 , NULL , V_39 ,
NULL ) ;
}
