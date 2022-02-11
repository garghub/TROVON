void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 , * V_5 ;
struct V_6 V_7 ;
F_2 ( & V_7 ) ;
F_3 (connector, tmp,
&dev->mode_config.connector_list, head) {
if ( V_4 -> V_8 == V_9 ||
V_4 -> V_8 == V_10 ||
V_4 -> V_8 == V_11 )
F_4 ( & V_4 -> V_12 , & V_7 ) ;
}
F_5 ( & V_7 , & V_2 -> V_13 . V_14 ) ;
}
void F_6 ( struct V_15 * V_16 ,
const struct V_17 * V_18 )
{
const struct V_19 * V_20 ;
int V_21 ;
V_20 = V_19 ( V_18 -> V_22 ) ;
if ( ! V_20 || ! V_20 -> V_23 ) {
struct V_24 V_25 ;
F_7 ( L_1 ,
F_8 ( V_18 -> V_22 ,
& V_25 ) ) ;
V_16 -> V_23 = 0 ;
V_16 -> V_26 = 0 ;
} else {
V_16 -> V_23 = V_20 -> V_23 ;
V_16 -> V_26 = V_20 -> V_27 [ 0 ] * 8 ;
}
V_16 -> V_28 = V_18 -> V_28 ;
V_16 -> V_29 = V_18 -> V_29 ;
for ( V_21 = 0 ; V_21 < 4 ; V_21 ++ ) {
V_16 -> V_30 [ V_21 ] = V_18 -> V_30 [ V_21 ] ;
V_16 -> V_31 [ V_21 ] = V_18 -> V_31 [ V_21 ] ;
}
V_16 -> V_32 = V_18 -> V_32 [ 0 ] ;
V_16 -> V_22 = V_18 -> V_22 ;
V_16 -> V_33 = V_18 -> V_33 ;
}
static struct V_34 * F_9 ( struct V_1 * V_2 )
{
struct V_34 * V_35 ;
int V_36 ;
V_35 = F_10 ( sizeof( * V_35 ) , V_37 ) ;
if ( V_35 == NULL ) {
F_7 ( L_2 ) ;
return NULL ;
}
V_35 -> V_38 = true ;
V_36 = F_11 ( V_2 , V_35 , 0 ,
& V_39 ,
V_40 ,
F_12 ( V_40 ) ,
V_41 , NULL ) ;
if ( V_36 ) {
F_13 ( V_35 ) ;
V_35 = NULL ;
}
return V_35 ;
}
int F_14 ( struct V_1 * V_2 , struct V_42 * V_43 ,
const struct V_44 * V_45 )
{
struct V_34 * V_35 ;
V_35 = F_9 ( V_2 ) ;
return F_15 ( V_2 , V_43 , V_35 , NULL , V_45 ,
NULL ) ;
}
