void F_1 ( struct V_1 * V_2 )
{
memset ( V_2 , 0 , sizeof( struct V_1 ) ) ;
F_2 ( & V_2 -> V_3 ) ;
F_2 ( & V_2 -> V_4 ) ;
F_2 ( & V_2 -> V_5 ) ;
F_3 ( & V_2 -> V_6 ) ;
}
void F_4 ( struct V_1 * V_2 )
{
struct V_7 * V_8 , * V_9 ;
F_5 (ei, n, &buf->isoc_list, link_order)
F_6 ( V_8 ) ;
F_5 (ei, n, &buf->order_list, link_order)
F_6 ( V_8 ) ;
}
struct V_7 * F_7 ( struct V_1 * V_2 )
{
struct V_7 * V_8 ;
V_8 = F_8 ( V_10 , V_11 ) ;
if ( V_8 ) {
F_2 ( & V_8 -> V_12 ) ;
F_2 ( & V_8 -> V_13 ) ;
}
return V_8 ;
}
void F_9 ( struct V_1 * V_2 , struct V_7 * V_8 )
{
if ( V_8 )
F_10 ( V_10 , V_8 ) ;
}
void F_11 ( struct V_1 * V_2 , struct V_14 * V_15 )
{
struct V_7 * V_8 , * V_9 ;
F_12 ( & V_2 -> V_6 ) ;
F_5 (ei, n, list->next, link)
F_9 ( V_2 , V_8 ) ;
F_13 ( & V_2 -> V_6 ) ;
}
int F_14 ( struct V_1 * V_2 , T_1 V_16 , int V_17 )
{
struct V_18 * V_19 ;
F_15 ( V_20 , L_1 , V_21 , V_16 ) ;
V_19 = F_16 ( sizeof( struct V_18 ) , V_11 ) ;
if ( V_19 == NULL )
return - V_22 ;
F_17 ( & V_19 -> V_23 , 1 ) ;
V_19 -> V_16 = V_16 ;
V_19 -> V_17 = V_17 ;
F_2 ( & V_19 -> V_24 ) ;
F_12 ( & V_2 -> V_6 ) ;
F_18 ( & V_19 -> V_12 , & V_2 -> V_3 ) ;
F_13 ( & V_2 -> V_6 ) ;
return 0 ;
}
int F_19 ( struct V_1 * V_2 , T_1 V_16 )
{
struct V_14 * V_25 , * V_9 ;
struct V_18 * V_19 = NULL ;
F_15 ( V_20 , L_1 , V_21 , V_16 ) ;
F_12 ( & V_2 -> V_6 ) ;
F_20 (e, &buf->stream_list) {
V_19 = F_21 ( V_25 , struct V_18 , V_12 ) ;
if ( V_19 -> V_16 == V_16 ) {
F_22 ( V_25 ) ;
break;
}
V_19 = NULL ;
}
if ( ! V_19 ) {
F_13 ( & V_2 -> V_6 ) ;
return - 1 ;
}
F_23 (e, n, &st->elt_list) {
struct V_7 * V_8 =
F_21 ( V_25 , struct V_7 , V_12 ) ;
F_24 ( & V_8 -> V_12 ) ;
F_24 ( & V_8 -> V_13 ) ;
V_19 -> V_26 -= V_8 -> V_27 ;
F_15 ( V_28 , L_2 ,
V_19 -> V_26 , V_8 -> V_27 , F_25 ( & V_19 -> V_23 ) ) ;
F_26 ( V_19 ) ;
F_9 ( V_2 , V_8 ) ;
}
F_13 ( & V_2 -> V_6 ) ;
F_26 ( V_19 ) ;
return 0 ;
}
void F_27 ( struct V_18 * V_19 )
{
F_28 ( & V_19 -> V_23 ) ;
}
void F_26 ( struct V_18 * V_19 )
{
if ( F_29 ( & V_19 -> V_23 ) ) {
F_15 ( V_20 , L_3 ) ;
F_6 ( V_19 ) ;
}
}
int F_30 ( struct V_1 * V_2 , T_1 V_29 , T_1 V_16 ,
struct V_7 * V_8 )
{
struct V_18 * V_19 = NULL ;
struct V_14 * V_25 ;
if ( V_16 ) {
F_20 (e, &buf->stream_list) {
V_19 = F_21 ( V_25 , struct V_18 , V_12 ) ;
if ( V_19 -> V_16 == V_16 )
break;
}
if ( V_25 == & V_2 -> V_3 ) {
return - 1 ;
}
}
if ( V_19 ) {
struct V_30 * V_31 = (struct V_30 * )
& V_8 -> V_32 [ sizeof( struct V_33 ) ] ;
if ( ( V_31 -> V_34 == V_35 ) && ( V_31 -> type
== V_36 ) &&
( V_31 -> V_37 == V_38 ) ) {
T_1 V_39 = V_31 -> V_40 ;
V_31 -> V_40 = V_19 -> V_40 ;
V_19 -> V_40 += V_39 ;
}
F_27 ( V_19 ) ;
V_8 -> V_41 = V_19 ;
V_19 -> V_26 += V_8 -> V_27 ;
F_18 ( & V_8 -> V_12 , & V_19 -> V_24 ) ;
F_15 ( V_28 , L_4 , V_19 -> V_26 , V_8 -> V_27 ) ;
while ( ( V_19 -> V_26 > V_19 -> V_17 ) &&
! F_31 ( & V_19 -> V_24 ) ) {
struct V_7 * V_42 =
F_32 ( & V_19 -> V_24 ,
struct V_7 , V_12 ) ;
F_24 ( & V_42 -> V_12 ) ;
F_24 ( & V_42 -> V_13 ) ;
V_19 -> V_26 -= V_42 -> V_27 ;
F_9 ( V_2 , V_42 ) ;
F_26 ( V_19 ) ;
}
}
F_18 ( & V_8 -> V_13 , V_29 ?
& V_2 -> V_5 : & V_2 -> V_4 ) ;
return 0 ;
}
int F_33 ( struct V_1 * V_2 , T_1 V_29 , unsigned * V_43 ,
unsigned V_44 , struct V_14 * V_15 )
{
int V_45 = 0 ;
struct V_14 * V_46 ;
struct V_7 * V_8 , * V_9 ;
F_12 ( & V_2 -> V_6 ) ;
if ( V_29 )
V_46 = & V_2 -> V_5 ;
else
V_46 = & V_2 -> V_4 ;
F_5 (ei, n, el, link_order) {
if ( ( * V_43 + V_8 -> V_27 ) <= V_44 ) {
struct V_47 * V_48 = (struct V_47 * )
& V_8 -> V_32 [ sizeof( struct V_33 ) ] ;
V_48 -> V_49 = V_2 -> V_50 [ V_8 -> V_34 ] ++ ;
if ( V_2 -> V_50 [ V_8 -> V_34 ] == 0 )
V_2 -> V_50 [ V_8 -> V_34 ] = 1 ;
* V_43 += V_8 -> V_27 ;
F_22 ( & V_8 -> V_12 ) ;
F_22 ( & V_8 -> V_13 ) ;
if ( V_8 -> V_41 ) {
V_8 -> V_41 -> V_26 -= V_8 -> V_27 ;
F_15 ( V_28 , L_5 ,
V_8 -> V_41 -> V_26 , V_8 -> V_27 ) ;
F_26 ( V_8 -> V_41 ) ;
V_8 -> V_41 = NULL ;
}
F_2 ( & V_8 -> V_13 ) ;
F_18 ( & V_8 -> V_12 , V_15 ) ;
V_45 ++ ;
} else {
break;
}
}
F_13 ( & V_2 -> V_6 ) ;
return V_45 ;
}
int F_34 ( struct V_1 * V_2 )
{
return ! F_31 ( & V_2 -> V_4 ) ;
}
