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
V_17 -> V_21 = F_9 ( V_2 , V_19 ) ;
V_17 -> V_22 = V_19 -> V_22 ;
V_17 -> V_23 = V_19 -> V_23 ;
for ( V_20 = 0 ; V_20 < 4 ; V_20 ++ ) {
V_17 -> V_24 [ V_20 ] = V_19 -> V_24 [ V_20 ] ;
V_17 -> V_25 [ V_20 ] = V_19 -> V_25 [ V_20 ] ;
}
V_17 -> V_26 = V_19 -> V_26 [ 0 ] ;
V_17 -> V_27 = V_19 -> V_27 ;
}
static struct V_28 * F_10 ( struct V_1 * V_2 )
{
struct V_28 * V_29 ;
int V_30 ;
V_29 = F_11 ( sizeof( * V_29 ) , V_31 ) ;
if ( V_29 == NULL ) {
F_12 ( L_1 ) ;
return NULL ;
}
V_29 -> V_32 = true ;
V_30 = F_13 ( V_2 , V_29 , 0 ,
& V_33 ,
V_34 ,
F_14 ( V_34 ) ,
NULL ,
V_35 , NULL ) ;
if ( V_30 ) {
F_15 ( V_29 ) ;
V_29 = NULL ;
}
return V_29 ;
}
int F_16 ( struct V_1 * V_2 , struct V_36 * V_37 ,
const struct V_38 * V_39 )
{
struct V_28 * V_29 ;
V_29 = F_10 ( V_2 ) ;
return F_17 ( V_2 , V_37 , V_29 , NULL , V_39 ,
NULL ) ;
}
