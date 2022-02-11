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
V_7 = V_2 -> V_4 ;
if ( V_7 ) {
if ( V_7 -> V_19 ||
V_7 -> V_20 ||
V_7 -> V_21 ) {
if ( V_7 -> V_23 == V_7 -> V_24 ) {
V_7 -> V_24 = F_12 ( V_7 -> V_24 ) -> V_25 ;
goto V_26;
}
if ( V_7 -> V_24 -> V_27 ) {
V_7 -> V_24 = V_7 -> V_24 -> V_27 ;
goto V_26;
}
if ( V_7 -> V_23 )
V_7 -> V_24 = V_7 -> V_23 ;
F_7 ( V_7 ) ;
V_7 = V_2 -> V_4 = NULL ;
} else {
V_18 = ( T_1 * ) V_7 -> V_22 ;
F_13 ( V_7 -> V_24 , V_7 -> V_22 - V_7 -> V_24 -> V_28 ) ;
}
}
if ( ! V_7 ) {
struct V_29 * V_30 ;
V_31:
V_30 = F_14 ( & V_2 -> V_3 ) ;
if ( ! V_30 )
return NULL ;
V_7 = F_15 ( V_30 , struct V_6 , V_9 ) ;
if ( ( F_12 ( V_7 -> V_24 ) -> V_32 & V_33 ) == V_33 ) {
if ( F_12 ( V_7 -> V_24 ) -> V_25 )
V_7 -> V_23 = V_7 -> V_24 ;
if ( V_7 -> V_23 && V_7 -> V_24 -> V_34 == V_7 -> V_24 -> V_35 )
V_7 -> V_24 = F_12 ( V_7 -> V_24 ) -> V_25 ;
if ( F_16 ( ! V_7 -> V_24 ) ) {
F_17 ( F_18 ( V_7 -> V_24 -> V_36 ) , V_37 ) ;
F_7 ( V_7 ) ;
goto V_31;
}
}
if ( V_7 -> V_13 )
F_19 ( V_7 -> V_13 -> V_38 . V_39 , V_7 -> V_24 ) ;
V_2 -> V_4 = V_7 ;
V_26:
V_18 = ( T_1 * ) V_7 -> V_24 -> V_28 ;
V_7 -> V_19 = 1 ;
V_7 -> V_40 = 0 ;
V_7 -> V_21 = 0 ;
V_7 -> V_41 = 0 ;
V_7 -> V_42 = 0 ;
V_7 -> V_20 = 0 ;
if ( V_7 -> V_23 ) {
struct V_43
* V_44 = F_20 ( V_7 -> V_24 ) ,
* V_45 = F_20 ( V_7 -> V_23 ) ;
V_44 -> V_7 = V_45 -> V_7 ;
V_44 -> V_46 = V_45 -> V_46 ;
}
}
V_7 -> V_47 = V_18 ;
V_7 -> V_22 = ( ( V_48 * ) V_18 ) + F_21 ( F_22 ( V_18 -> V_49 ) ) ;
F_13 ( V_7 -> V_24 , sizeof( T_1 ) ) ;
V_7 -> V_50 . V_51 = NULL ;
if ( V_7 -> V_22 + sizeof( T_1 ) <
F_23 ( V_7 -> V_24 ) ) {
V_7 -> V_19 = 0 ;
} else if ( V_7 -> V_22 > F_23 ( V_7 -> V_24 ) ) {
V_7 -> V_21 = 1 ;
V_7 -> V_22 = F_23 ( V_7 -> V_24 ) ;
} else {
V_7 -> V_20 = 1 ;
}
F_24 ( L_1 ,
V_7 , F_25 ( F_26 ( V_7 -> V_47 -> type ) ) ,
F_22 ( V_7 -> V_47 -> V_49 ) , V_7 -> V_24 -> V_35 ) ;
return V_7 ;
}
void F_27 ( struct V_1 * V_10 , T_2 V_52 )
{
F_3 ( & V_10 -> V_5 , V_52 ) ;
}
