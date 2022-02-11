void F_1 ( struct V_1 * V_2 )
{
F_2 ( & V_2 -> V_3 ) ;
V_2 -> V_4 = NULL ;
F_3 ( & V_2 -> V_5 , NULL ) ;
V_2 -> V_6 = 0 ;
}
void F_4 ( struct V_1 * V_2 )
{
struct V_7 * V_8 , * V_9 ;
F_5 (chunk, tmp, &queue->in_chunk_list, list) {
F_6 ( & V_8 -> V_10 ) ;
F_7 ( V_8 ) ;
}
if ( V_2 -> V_4 ) {
F_7 ( V_2 -> V_4 ) ;
V_2 -> V_4 = NULL ;
}
if ( V_2 -> V_6 ) {
F_8 ( V_2 ) ;
}
}
void F_9 ( struct V_1 * V_11 , struct V_7 * V_8 )
{
if ( V_8 -> V_12 -> V_13 ) {
F_7 ( V_8 ) ;
return;
}
F_10 ( & V_8 -> V_10 , & V_11 -> V_3 ) ;
if ( V_8 -> V_14 )
V_8 -> V_14 -> V_15 . V_16 ++ ;
V_11 -> V_5 . V_17 ( & V_11 -> V_5 ) ;
}
struct V_18 * F_11 ( struct V_1 * V_2 )
{
struct V_7 * V_8 ;
T_1 * V_19 = NULL ;
V_8 = V_2 -> V_4 ;
if ( V_8 -> V_20 ||
V_8 -> V_21 ||
V_8 -> V_22 )
return NULL ;
V_19 = ( T_1 * ) V_8 -> V_23 ;
return V_19 ;
}
struct V_7 * F_12 ( struct V_1 * V_2 )
{
struct V_7 * V_8 ;
T_1 * V_19 = NULL ;
if ( ( V_8 = V_2 -> V_4 ) ) {
if ( V_8 -> V_20 ||
V_8 -> V_21 ||
V_8 -> V_22 ) {
F_7 ( V_8 ) ;
V_8 = V_2 -> V_4 = NULL ;
} else {
V_19 = ( T_1 * ) V_8 -> V_23 ;
F_13 ( V_8 -> V_24 ,
V_8 -> V_23 - V_8 -> V_24 -> V_25 ) ;
if ( F_14 ( V_8 -> V_24 ) < sizeof( T_1 ) ) {
F_7 ( V_8 ) ;
V_8 = V_2 -> V_4 = NULL ;
}
}
}
if ( ! V_8 ) {
struct V_26 * V_27 ;
if ( F_15 ( & V_2 -> V_3 ) )
return NULL ;
V_27 = V_2 -> V_3 . V_28 ;
V_8 = V_2 -> V_4 =
F_16 ( V_27 , struct V_7 , V_10 ) ;
F_6 ( V_27 ) ;
V_8 -> V_20 = 1 ;
V_19 = ( T_1 * ) V_8 -> V_24 -> V_25 ;
V_8 -> V_29 = 0 ;
}
V_8 -> V_30 = V_19 ;
V_8 -> V_23 = ( ( V_31 * ) V_19 ) + F_17 ( F_18 ( V_19 -> V_32 ) ) ;
if ( F_19 ( F_20 ( V_8 -> V_24 ) ) ) {
if ( V_8 -> V_23 > F_21 ( V_8 -> V_24 ) )
V_8 -> V_23 = F_21 ( V_8 -> V_24 ) ;
}
F_13 ( V_8 -> V_24 , sizeof( T_1 ) ) ;
V_8 -> V_33 . V_34 = NULL ;
if ( V_8 -> V_23 < F_21 ( V_8 -> V_24 ) ) {
V_8 -> V_20 = 0 ;
} else if ( V_8 -> V_23 > F_21 ( V_8 -> V_24 ) ) {
F_7 ( V_8 ) ;
V_8 = V_2 -> V_4 = NULL ;
return NULL ;
} else {
V_8 -> V_21 = 1 ;
}
F_22 ( L_1
L_2 , V_8 ,
F_23 ( F_24 ( V_8 -> V_30 -> type ) ) ,
F_18 ( V_8 -> V_30 -> V_32 ) , V_8 -> V_24 -> V_35 ) ;
return V_8 ;
}
void F_25 ( struct V_1 * V_11 , T_2 V_36 )
{
F_3 ( & V_11 -> V_5 , V_36 ) ;
}
