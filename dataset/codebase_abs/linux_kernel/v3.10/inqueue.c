void F_1 ( struct V_1 * V_2 )
{
F_2 ( & V_2 -> V_3 ) ;
V_2 -> V_4 = NULL ;
F_3 ( & V_2 -> V_5 , NULL ) ;
}
void F_4 ( struct V_1 * V_2 )
{
struct V_6 * V_7 , * V_8 ;
F_5 (chunk, tmp, &queue->in_chunk_list, list) {
F_6 ( & V_7 -> V_9 ) ;
F_7 ( V_7 ) ;
}
if ( V_2 -> V_4 ) {
F_7 ( V_2 -> V_4 ) ;
V_2 -> V_4 = NULL ;
}
}
void F_8 ( struct V_1 * V_10 , struct V_6 * V_7 )
{
if ( V_7 -> V_11 -> V_12 ) {
F_7 ( V_7 ) ;
return;
}
F_9 ( & V_7 -> V_9 , & V_10 -> V_3 ) ;
if ( V_7 -> V_13 )
V_7 -> V_13 -> V_14 . V_15 ++ ;
V_10 -> V_5 . V_16 ( & V_10 -> V_5 ) ;
}
struct V_17 * F_10 ( struct V_1 * V_2 )
{
struct V_6 * V_7 ;
T_1 * V_18 = NULL ;
V_7 = V_2 -> V_4 ;
if ( V_7 -> V_19 ||
V_7 -> V_20 ||
V_7 -> V_21 )
return NULL ;
V_18 = ( T_1 * ) V_7 -> V_22 ;
return V_18 ;
}
struct V_6 * F_11 ( struct V_1 * V_2 )
{
struct V_6 * V_7 ;
T_1 * V_18 = NULL ;
if ( ( V_7 = V_2 -> V_4 ) ) {
if ( V_7 -> V_19 ||
V_7 -> V_20 ||
V_7 -> V_21 ) {
F_7 ( V_7 ) ;
V_7 = V_2 -> V_4 = NULL ;
} else {
V_18 = ( T_1 * ) V_7 -> V_22 ;
F_12 ( V_7 -> V_23 ,
V_7 -> V_22 - V_7 -> V_23 -> V_24 ) ;
if ( F_13 ( V_7 -> V_23 ) < sizeof( T_1 ) ) {
F_7 ( V_7 ) ;
V_7 = V_2 -> V_4 = NULL ;
}
}
}
if ( ! V_7 ) {
struct V_25 * V_26 ;
if ( F_14 ( & V_2 -> V_3 ) )
return NULL ;
V_26 = V_2 -> V_3 . V_27 ;
V_7 = V_2 -> V_4 =
F_15 ( V_26 , struct V_6 , V_9 ) ;
F_6 ( V_26 ) ;
V_7 -> V_19 = 1 ;
V_18 = ( T_1 * ) V_7 -> V_23 -> V_24 ;
V_7 -> V_28 = 0 ;
}
V_7 -> V_29 = V_18 ;
V_7 -> V_22 = ( ( V_30 * ) V_18 ) + F_16 ( F_17 ( V_18 -> V_31 ) ) ;
if ( F_18 ( F_19 ( V_7 -> V_23 ) ) ) {
if ( V_7 -> V_22 > F_20 ( V_7 -> V_23 ) )
V_7 -> V_22 = F_20 ( V_7 -> V_23 ) ;
}
F_12 ( V_7 -> V_23 , sizeof( T_1 ) ) ;
V_7 -> V_32 . V_33 = NULL ;
if ( V_7 -> V_22 < F_20 ( V_7 -> V_23 ) ) {
V_7 -> V_19 = 0 ;
} else if ( V_7 -> V_22 > F_20 ( V_7 -> V_23 ) ) {
F_7 ( V_7 ) ;
V_7 = V_2 -> V_4 = NULL ;
return NULL ;
} else {
V_7 -> V_20 = 1 ;
}
F_21 ( L_1
L_2 , V_7 ,
F_22 ( F_23 ( V_7 -> V_29 -> type ) ) ,
F_17 ( V_7 -> V_29 -> V_31 ) , V_7 -> V_23 -> V_34 ) ;
return V_7 ;
}
void F_24 ( struct V_1 * V_10 , T_2 V_35 )
{
F_3 ( & V_10 -> V_5 , V_35 ) ;
}
