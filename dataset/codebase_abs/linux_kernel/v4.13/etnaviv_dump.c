static void F_1 ( struct V_1 * V_2 ,
T_1 type , void * V_3 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
V_5 -> V_6 = F_2 ( V_7 ) ;
V_5 -> type = F_2 ( type ) ;
V_5 -> V_8 = F_2 ( V_2 -> V_9 - V_2 -> V_10 ) ;
V_5 -> V_11 = F_2 ( V_3 - V_2 -> V_9 ) ;
V_2 -> V_5 ++ ;
V_2 -> V_9 += V_5 -> V_11 ;
}
static void F_3 ( struct V_1 * V_2 ,
struct V_12 * V_13 )
{
struct V_14 * V_15 = V_2 -> V_9 ;
unsigned int V_16 ;
for ( V_16 = 0 ; V_16 < F_4 ( V_14 ) ; V_16 ++ , V_15 ++ ) {
V_15 -> V_15 = V_14 [ V_16 ] ;
V_15 -> V_17 = F_5 ( V_13 , V_14 [ V_16 ] ) ;
}
F_1 ( V_2 , V_18 , V_15 ) ;
}
static void F_6 ( struct V_1 * V_2 ,
struct V_12 * V_13 , T_2 V_19 )
{
F_7 ( V_13 -> V_20 , V_2 -> V_9 ) ;
F_1 ( V_2 , V_21 , V_2 -> V_9 + V_19 ) ;
}
static void F_8 ( struct V_1 * V_2 , T_1 type ,
void * V_22 , T_2 V_23 , T_3 V_24 )
{
memcpy ( V_2 -> V_9 , V_22 , V_23 ) ;
V_2 -> V_5 -> V_24 = F_9 ( V_24 ) ;
F_1 ( V_2 , type , V_2 -> V_9 + V_23 ) ;
}
void F_10 ( struct V_12 * V_13 )
{
struct V_1 V_2 ;
struct V_25 * V_26 ;
struct V_27 * V_28 ;
struct V_29 * V_30 ;
unsigned int V_31 , V_32 ;
T_2 V_11 , V_19 ;
T_4 * V_33 , * V_34 ;
V_19 = F_11 ( V_13 -> V_20 ) ;
V_31 = 4 ;
V_32 = 0 ;
V_11 = F_4 ( V_14 ) *
sizeof( struct V_14 ) +
V_19 + V_13 -> V_35 -> V_23 ;
F_12 (cmd, &gpu->active_cmd_list, node) {
V_11 += V_30 -> V_23 ;
V_31 ++ ;
}
F_12 (vram, &gpu->mmu->mappings, mmu_node) {
if ( ! V_26 -> V_36 )
continue;
V_28 = V_26 -> V_37 ;
V_11 += V_28 -> V_38 . V_23 ;
V_32 += V_28 -> V_38 . V_23 >> V_39 ;
V_31 ++ ;
}
if ( V_32 ) {
V_11 += V_32 * sizeof( T_4 ) ;
V_31 ++ ;
}
V_11 += sizeof( * V_2 . V_5 ) * V_31 ;
V_2 . V_10 = F_13 ( V_11 , V_40 | V_41 | V_42 ,
V_43 ) ;
if ( ! V_2 . V_10 ) {
F_14 ( V_13 -> V_44 , L_1 ) ;
return;
}
V_2 . V_5 = V_2 . V_10 ;
V_2 . V_9 = & V_2 . V_5 [ V_31 ] ;
memset ( V_2 . V_5 , 0 , V_2 . V_9 - V_2 . V_10 ) ;
F_3 ( & V_2 , V_13 ) ;
F_6 ( & V_2 , V_13 , V_19 ) ;
F_8 ( & V_2 , V_45 , V_13 -> V_35 -> V_46 ,
V_13 -> V_35 -> V_23 ,
F_15 ( V_13 -> V_35 ) ) ;
F_12 (cmd, &gpu->active_cmd_list, node)
F_8 ( & V_2 , V_47 , V_30 -> V_46 ,
V_30 -> V_23 , F_15 ( V_30 ) ) ;
if ( V_32 ) {
V_34 = V_33 = V_2 . V_9 ;
memset ( V_33 , 0 , sizeof( * V_33 ) * V_32 ) ;
F_1 ( & V_2 , V_48 ,
V_33 + V_32 ) ;
} else {
V_34 = V_33 = NULL ;
}
F_12 (vram, &gpu->mmu->mappings, mmu_node) {
struct V_49 * * V_50 ;
void * V_46 ;
if ( V_26 -> V_36 == 0 )
continue;
V_28 = V_26 -> V_37 ;
F_16 ( & V_28 -> V_51 ) ;
V_50 = F_17 ( V_28 ) ;
F_18 ( & V_28 -> V_51 ) ;
if ( V_50 ) {
int V_52 ;
V_2 . V_5 -> V_9 [ 0 ] = V_33 - V_34 ;
for ( V_52 = 0 ; V_52 < V_28 -> V_38 . V_23 > > V_39 ; V_52 ++ )
* V_33 ++ = F_9 ( F_19 ( * V_50 ++ ) ) ;
}
V_2 . V_5 -> V_24 = F_9 ( V_26 -> V_24 ) ;
V_46 = F_20 ( & V_28 -> V_38 ) ;
if ( V_46 )
memcpy ( V_2 . V_9 , V_46 , V_28 -> V_38 . V_23 ) ;
F_1 ( & V_2 , V_53 , V_2 . V_9 +
V_28 -> V_38 . V_23 ) ;
}
F_1 ( & V_2 , V_54 , V_2 . V_9 ) ;
F_21 ( V_13 -> V_44 , V_2 . V_10 , V_2 . V_9 - V_2 . V_10 , V_40 ) ;
}
