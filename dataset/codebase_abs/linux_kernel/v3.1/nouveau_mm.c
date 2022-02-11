static inline void
F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
F_2 ( & V_4 -> V_5 ) ;
F_2 ( & V_4 -> V_6 ) ;
F_3 ( V_4 ) ;
}
static struct V_3 *
F_4 ( struct V_1 * V_2 , struct V_3 * V_4 , T_1 V_7 )
{
struct V_3 * V_8 ;
if ( V_4 -> V_9 == V_7 )
return V_4 ;
V_8 = F_5 ( sizeof( * V_8 ) , V_10 ) ;
if ( F_6 ( V_8 == NULL ) )
return NULL ;
V_8 -> V_11 = V_4 -> V_11 ;
V_8 -> V_9 = V_7 ;
V_8 -> type = V_4 -> type ;
V_4 -> V_11 += V_7 ;
V_4 -> V_9 -= V_7 ;
F_7 ( & V_8 -> V_5 , & V_4 -> V_5 ) ;
if ( V_8 -> type == 0 )
F_7 ( & V_8 -> V_6 , & V_4 -> V_6 ) ;
return V_8 ;
}
void
F_8 ( struct V_1 * V_2 , struct V_3 * V_12 )
{
struct V_3 * V_13 = F_9 ( V_12 , V_13 ) ;
struct V_3 * V_14 = F_9 ( V_12 , V_14 ) ;
F_10 ( & V_12 -> V_6 , & V_2 -> free ) ;
V_12 -> type = 0 ;
if ( V_13 && V_13 -> type == 0 ) {
V_13 -> V_9 += V_12 -> V_9 ;
F_1 ( V_2 , V_12 ) ;
V_12 = V_13 ;
}
if ( V_14 && V_14 -> type == 0 ) {
V_14 -> V_11 = V_12 -> V_11 ;
V_14 -> V_9 += V_12 -> V_9 ;
F_1 ( V_2 , V_12 ) ;
}
}
int
F_11 ( struct V_1 * V_2 , int type , T_1 V_7 , T_1 V_15 ,
T_1 V_16 , struct V_3 * * V_17 )
{
struct V_3 * V_13 , * V_12 , * V_14 ;
T_1 V_18 = V_15 ? V_15 : V_7 ;
T_1 V_19 = V_16 - 1 ;
T_1 V_20 ;
T_1 V_21 , V_22 ;
F_12 (this, &rmm->free, fl_entry) {
V_22 = V_12 -> V_11 + V_12 -> V_9 ;
V_21 = V_12 -> V_11 ;
V_13 = F_9 ( V_12 , V_13 ) ;
if ( V_13 && V_13 -> type != type )
V_21 = F_13 ( V_21 , V_2 -> V_23 ) ;
V_14 = F_9 ( V_12 , V_14 ) ;
if ( V_14 && V_14 -> type != type )
V_22 = F_14 ( V_22 , V_2 -> V_23 ) ;
V_21 = ( V_21 + V_19 ) & ~ V_19 ;
V_22 &= ~ V_19 ;
if ( V_21 > V_22 || V_22 - V_21 < V_18 )
continue;
V_20 = V_21 - V_12 -> V_11 ;
if ( V_20 && ! F_4 ( V_2 , V_12 , V_20 ) )
return - V_24 ;
V_12 = F_4 ( V_2 , V_12 , V_18 ( V_7 , V_22 - V_21 ) ) ;
if ( ! V_12 )
return - V_24 ;
V_12 -> type = type ;
F_2 ( & V_12 -> V_6 ) ;
* V_17 = V_12 ;
return 0 ;
}
return - V_25 ;
}
int
F_15 ( struct V_1 * * V_26 , T_1 V_11 , T_1 V_9 , T_1 V_27 )
{
struct V_1 * V_2 ;
struct V_3 * V_28 ;
V_28 = F_16 ( sizeof( * V_28 ) , V_10 ) ;
if ( ! V_28 )
return - V_24 ;
V_28 -> V_11 = F_13 ( V_11 , V_27 ) ;
V_28 -> V_9 = F_14 ( V_11 + V_9 , V_27 ) - V_28 -> V_11 ;
V_2 = F_16 ( sizeof( * V_2 ) , V_10 ) ;
if ( ! V_2 ) {
F_3 ( V_28 ) ;
return - V_24 ;
}
V_2 -> V_23 = V_27 ;
F_17 ( & V_2 -> V_29 ) ;
F_18 ( & V_2 -> V_30 ) ;
F_18 ( & V_2 -> free ) ;
F_10 ( & V_28 -> V_5 , & V_2 -> V_30 ) ;
F_10 ( & V_28 -> V_6 , & V_2 -> free ) ;
* V_26 = V_2 ;
return 0 ;
}
int
F_19 ( struct V_1 * * V_26 )
{
struct V_1 * V_2 = * V_26 ;
struct V_3 * F_9 , * V_28 =
F_20 ( & V_2 -> V_30 , struct V_3 , V_5 ) ;
if ( ! F_21 ( & V_2 -> V_30 ) ) {
F_22 ( V_31 L_1 ) ;
F_12 (node, &rmm->nodes, nl_entry) {
F_22 ( V_31 L_2 ,
F_9 -> type , F_9 -> V_11 , F_9 -> V_9 ) ;
}
F_23 ( 1 ) ;
return - V_32 ;
}
F_3 ( V_28 ) ;
F_3 ( V_2 ) ;
* V_26 = NULL ;
return 0 ;
}
