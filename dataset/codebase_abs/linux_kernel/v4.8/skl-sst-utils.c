int F_1 ( struct V_1 * V_2 , T_1 * V_3 ,
struct V_4 * V_5 )
{
struct V_6 * V_7 ;
T_2 * V_8 ;
V_8 = ( T_2 * ) V_3 ;
if ( F_2 ( & V_2 -> V_9 ) ) {
F_3 ( V_2 -> V_10 , L_1 ) ;
return - V_11 ;
}
F_4 (module, &ctx->uuid_list, list) {
if ( F_5 ( * V_8 , V_7 -> V_3 ) == 0 ) {
V_5 -> V_12 = V_7 -> V_13 ;
V_5 -> V_14 = V_7 -> V_14 ;
return 0 ;
}
}
return - V_11 ;
}
int F_6 ( struct V_15 * V_2 , unsigned int V_16 )
{
struct V_17 * V_18 ;
struct V_19 * V_20 ;
int V_21 , V_22 ;
T_2 * V_23 ;
const char * V_24 ;
struct V_1 * V_25 = V_2 -> V_26 ;
struct V_6 * V_7 ;
struct V_27 V_28 ;
unsigned int V_29 ;
V_28 . V_30 = V_2 -> V_31 -> V_30 ;
V_28 . V_32 = V_2 -> V_31 -> V_32 ;
F_7 ( & V_28 ) ;
V_24 = V_28 . V_30 ;
V_29 = sizeof( * V_18 ) + V_16 ;
if ( V_28 . V_32 <= V_29 ) {
F_3 ( V_2 -> V_10 , L_2 ) ;
return - V_11 ;
}
V_18 = (struct V_17 * ) ( V_24 + V_16 ) ;
V_29 += V_18 -> V_33 + sizeof( * V_20 ) ;
if ( V_28 . V_32 <= V_29 ) {
F_3 ( V_2 -> V_10 , L_3 ) ;
return - V_11 ;
}
V_20 = (struct V_19 * )
( V_24 + V_16 + V_18 -> V_33 ) ;
V_22 = V_18 -> V_34 ;
V_29 += V_22 * sizeof( * V_20 ) ;
if ( V_28 . V_32 <= V_29 ) {
F_3 ( V_2 -> V_10 , L_4 ) ;
return - V_11 ;
}
for ( V_21 = 0 ; V_21 < V_22 ; V_21 ++ , V_20 ++ ) {
V_7 = F_8 ( sizeof( * V_7 ) , V_35 ) ;
if ( ! V_7 )
return - V_36 ;
V_23 = ( T_2 * ) V_20 -> V_3 . V_13 ;
memcpy ( & V_7 -> V_3 , V_23 , sizeof( V_7 -> V_3 ) ) ;
V_7 -> V_13 = V_21 ;
V_7 -> V_14 = V_20 -> type . V_37 ;
F_9 ( & V_7 -> V_38 , & V_25 -> V_9 ) ;
F_10 ( V_2 -> V_10 ,
L_5 ,
& V_7 -> V_3 , V_7 -> V_13 , V_7 -> V_14 ) ;
}
return 0 ;
}
void F_11 ( struct V_1 * V_2 )
{
struct V_6 * V_3 , * V_39 ;
F_12 (uuid, _uuid, &ctx->uuid_list, list) {
F_13 ( & V_3 -> V_38 ) ;
F_14 ( V_3 ) ;
}
}
int F_7 ( struct V_27 * V_31 )
{
struct V_40 * V_41 ;
if ( V_31 -> V_32 < sizeof( V_41 ) ) {
F_15 ( L_6 , V_42 ) ;
return - V_11 ;
}
V_41 = (struct V_40 * ) V_31 -> V_30 ;
if ( V_41 -> V_13 == V_43 ) {
V_31 -> V_32 -= V_41 -> V_33 ;
V_31 -> V_30 += V_41 -> V_33 ;
}
return 0 ;
}
