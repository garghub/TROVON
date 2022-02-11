void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 , * V_5 ;
struct V_6 V_7 ;
F_2 ( & V_7 ) ;
F_3 ( & V_2 -> V_8 . V_9 ) ;
F_4 (connector, tmp,
&dev->mode_config.connector_list, head) {
if ( V_4 -> V_10 == V_11 ||
V_4 -> V_10 == V_12 ||
V_4 -> V_10 == V_13 )
F_5 ( & V_4 -> V_14 , & V_7 ) ;
}
F_6 ( & V_7 , & V_2 -> V_8 . V_15 ) ;
F_7 ( & V_2 -> V_8 . V_9 ) ;
}
void F_8 ( struct V_1 * V_2 ,
struct V_16 * V_17 ,
const struct V_18 * V_19 )
{
int V_20 ;
V_17 -> V_2 = V_2 ;
V_17 -> V_21 = F_9 ( V_19 -> V_22 ) ;
V_17 -> V_23 = V_19 -> V_23 ;
V_17 -> V_24 = V_19 -> V_24 ;
for ( V_20 = 0 ; V_20 < 4 ; V_20 ++ ) {
V_17 -> V_25 [ V_20 ] = V_19 -> V_25 [ V_20 ] ;
V_17 -> V_26 [ V_20 ] = V_19 -> V_26 [ V_20 ] ;
}
V_17 -> V_27 = V_19 -> V_27 [ 0 ] ;
V_17 -> V_28 = V_19 -> V_28 ;
}
static struct V_29 * F_10 ( struct V_1 * V_2 )
{
struct V_29 * V_30 ;
int V_31 ;
V_30 = F_11 ( sizeof( * V_30 ) , V_32 ) ;
if ( V_30 == NULL ) {
F_12 ( L_1 ) ;
return NULL ;
}
V_30 -> V_33 = true ;
V_31 = F_13 ( V_2 , V_30 , 0 ,
& V_34 ,
V_35 ,
F_14 ( V_35 ) ,
V_36 , NULL ) ;
if ( V_31 ) {
F_15 ( V_30 ) ;
V_30 = NULL ;
}
return V_30 ;
}
int F_16 ( struct V_1 * V_2 , struct V_37 * V_38 ,
const struct V_39 * V_40 )
{
struct V_29 * V_30 ;
V_30 = F_10 ( V_2 ) ;
return F_17 ( V_2 , V_38 , V_30 , NULL , V_40 ,
NULL ) ;
}
