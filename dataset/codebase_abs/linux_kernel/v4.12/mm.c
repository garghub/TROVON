void
F_1 ( struct V_1 * V_2 , const char * V_3 )
{
struct V_4 * V_5 ;
F_2 ( L_1 , V_3 ) ;
F_2 ( L_2 ) ;
F_3 (node, &mm->nodes, nl_entry) {
F_2 ( L_3 ,
V_5 -> V_6 , V_5 -> V_7 , V_5 -> type ) ;
}
F_2 ( L_4 ) ;
F_3 (node, &mm->free, fl_entry) {
F_2 ( L_3 ,
V_5 -> V_6 , V_5 -> V_7 , V_5 -> type ) ;
}
}
void
F_4 ( struct V_1 * V_2 , struct V_4 * * V_8 )
{
struct V_4 * V_9 = * V_8 ;
if ( V_9 ) {
struct V_4 * V_10 = V_5 ( V_9 , V_10 ) ;
struct V_4 * V_11 = V_5 ( V_9 , V_11 ) ;
if ( V_10 && V_10 -> type == V_12 ) {
V_10 -> V_7 += V_9 -> V_7 ;
F_5 ( & V_9 -> V_13 ) ;
F_6 ( V_9 ) ; V_9 = V_10 ;
}
if ( V_11 && V_11 -> type == V_12 ) {
V_11 -> V_6 = V_9 -> V_6 ;
V_11 -> V_7 += V_9 -> V_7 ;
if ( V_9 -> type == V_12 )
F_5 ( & V_9 -> V_14 ) ;
F_5 ( & V_9 -> V_13 ) ;
F_6 ( V_9 ) ; V_9 = NULL ;
}
if ( V_9 && V_9 -> type != V_12 ) {
F_3 (prev, &mm->free, fl_entry) {
if ( V_9 -> V_6 < V_10 -> V_6 )
break;
}
F_7 ( & V_9 -> V_14 , & V_10 -> V_14 ) ;
V_9 -> type = V_12 ;
}
}
* V_8 = NULL ;
}
static struct V_4 *
F_8 ( struct V_1 * V_2 , struct V_4 * V_15 , T_1 V_16 )
{
struct V_4 * V_17 ;
if ( V_15 -> V_7 == V_16 )
return V_15 ;
V_17 = F_9 ( sizeof( * V_17 ) , V_18 ) ;
if ( F_10 ( V_17 == NULL ) )
return NULL ;
V_17 -> V_6 = V_15 -> V_6 ;
V_17 -> V_7 = V_16 ;
V_17 -> V_19 = V_15 -> V_19 ;
V_17 -> type = V_15 -> type ;
V_15 -> V_6 += V_16 ;
V_15 -> V_7 -= V_16 ;
F_7 ( & V_17 -> V_13 , & V_15 -> V_13 ) ;
if ( V_17 -> type == V_12 )
F_7 ( & V_17 -> V_14 , & V_15 -> V_14 ) ;
return V_17 ;
}
int
F_11 ( struct V_1 * V_2 , T_2 V_19 , T_2 type , T_1 V_20 , T_1 V_21 ,
T_1 V_22 , struct V_4 * * V_23 )
{
struct V_4 * V_10 , * V_9 , * V_11 ;
T_1 V_24 = V_22 - 1 ;
T_1 V_25 ;
T_1 V_26 , V_27 ;
F_12 ( type == V_12 || type == V_28 ) ;
F_3 (this, &mm->free, fl_entry) {
if ( F_10 ( V_19 != V_29 ) ) {
if ( V_9 -> V_19 != V_19 )
continue;
}
V_27 = V_9 -> V_6 + V_9 -> V_7 ;
V_26 = V_9 -> V_6 ;
V_10 = V_5 ( V_9 , V_10 ) ;
if ( V_10 && V_10 -> type != type )
V_26 = F_13 ( V_26 , V_2 -> V_30 ) ;
V_11 = V_5 ( V_9 , V_11 ) ;
if ( V_11 && V_11 -> type != type )
V_27 = F_14 ( V_27 , V_2 -> V_30 ) ;
V_26 = ( V_26 + V_24 ) & ~ V_24 ;
V_27 &= ~ V_24 ;
if ( V_26 > V_27 || V_27 - V_26 < V_21 )
continue;
V_25 = V_26 - V_9 -> V_6 ;
if ( V_25 && ! F_8 ( V_2 , V_9 , V_25 ) )
return - V_31 ;
V_9 = F_8 ( V_2 , V_9 , F_15 ( V_20 , V_27 - V_26 ) ) ;
if ( ! V_9 )
return - V_31 ;
V_9 -> V_11 = NULL ;
V_9 -> type = type ;
F_5 ( & V_9 -> V_14 ) ;
* V_23 = V_9 ;
return 0 ;
}
return - V_32 ;
}
static struct V_4 *
F_16 ( struct V_1 * V_2 , struct V_4 * V_15 , T_1 V_16 )
{
struct V_4 * V_17 ;
if ( V_15 -> V_7 == V_16 )
return V_15 ;
V_17 = F_9 ( sizeof( * V_17 ) , V_18 ) ;
if ( F_10 ( V_17 == NULL ) )
return NULL ;
V_15 -> V_7 -= V_16 ;
V_17 -> V_6 = V_15 -> V_6 + V_15 -> V_7 ;
V_17 -> V_7 = V_16 ;
V_17 -> V_19 = V_15 -> V_19 ;
V_17 -> type = V_15 -> type ;
F_17 ( & V_17 -> V_13 , & V_15 -> V_13 ) ;
if ( V_17 -> type == V_12 )
F_17 ( & V_17 -> V_14 , & V_15 -> V_14 ) ;
return V_17 ;
}
int
F_18 ( struct V_1 * V_2 , T_2 V_19 , T_2 type , T_1 V_20 , T_1 V_21 ,
T_1 V_22 , struct V_4 * * V_23 )
{
struct V_4 * V_10 , * V_9 , * V_11 ;
T_1 V_24 = V_22 - 1 ;
F_12 ( type == V_12 || type == V_28 ) ;
F_19 (this, &mm->free, fl_entry) {
T_1 V_27 = V_9 -> V_6 + V_9 -> V_7 ;
T_1 V_26 = V_9 -> V_6 ;
T_1 V_33 = 0 , V_15 ;
if ( F_10 ( V_19 != V_29 ) ) {
if ( V_9 -> V_19 != V_19 )
continue;
}
V_10 = V_5 ( V_9 , V_10 ) ;
if ( V_10 && V_10 -> type != type )
V_26 = F_13 ( V_26 , V_2 -> V_30 ) ;
V_11 = V_5 ( V_9 , V_11 ) ;
if ( V_11 && V_11 -> type != type ) {
V_27 = F_14 ( V_27 , V_2 -> V_30 ) ;
V_33 = V_11 -> V_6 - V_27 ;
}
V_26 = ( V_26 + V_24 ) & ~ V_24 ;
V_15 = V_27 - V_26 ;
if ( V_26 > V_27 || V_15 < V_21 )
continue;
V_15 = F_15 ( V_15 , V_20 ) ;
V_26 = ( V_27 - V_15 ) & ~ V_24 ;
V_33 += ( V_27 - V_26 ) - V_15 ;
if ( V_33 && ! F_16 ( V_2 , V_9 , V_33 ) )
return - V_31 ;
V_9 = F_16 ( V_2 , V_9 , V_15 ) ;
if ( ! V_9 )
return - V_31 ;
V_9 -> V_11 = NULL ;
V_9 -> type = type ;
F_5 ( & V_9 -> V_14 ) ;
* V_23 = V_9 ;
return 0 ;
}
return - V_32 ;
}
int
F_20 ( struct V_1 * V_2 , T_1 V_6 , T_1 V_7 , T_1 V_34 )
{
struct V_4 * V_5 , * V_10 ;
T_1 V_11 ;
if ( F_21 ( V_2 ) ) {
V_10 = F_22 ( & V_2 -> V_35 , F_23 ( * V_5 ) , V_13 ) ;
V_11 = V_10 -> V_6 + V_10 -> V_7 ;
if ( V_11 != V_6 ) {
F_12 ( V_11 > V_6 ) ;
if ( ! ( V_5 = F_24 ( sizeof( * V_5 ) , V_18 ) ) )
return - V_31 ;
V_5 -> type = V_28 ;
V_5 -> V_6 = V_11 ;
V_5 -> V_7 = V_6 - V_11 ;
F_7 ( & V_5 -> V_13 , & V_2 -> V_35 ) ;
}
F_12 ( V_34 != V_2 -> V_30 ) ;
} else {
F_25 ( & V_2 -> V_35 ) ;
F_25 ( & V_2 -> free ) ;
V_2 -> V_30 = V_34 ;
V_2 -> V_36 = 0 ;
}
V_5 = F_24 ( sizeof( * V_5 ) , V_18 ) ;
if ( ! V_5 )
return - V_31 ;
if ( V_7 ) {
V_5 -> V_6 = F_13 ( V_6 , V_2 -> V_30 ) ;
V_5 -> V_7 = F_14 ( V_6 + V_7 , V_2 -> V_30 ) ;
V_5 -> V_7 -= V_5 -> V_6 ;
}
F_7 ( & V_5 -> V_13 , & V_2 -> V_35 ) ;
F_7 ( & V_5 -> V_14 , & V_2 -> free ) ;
V_5 -> V_19 = ++ V_2 -> V_36 ;
return 0 ;
}
int
F_26 ( struct V_1 * V_2 )
{
struct V_4 * V_5 , * V_37 ;
int V_35 = 0 ;
if ( ! F_21 ( V_2 ) )
return 0 ;
F_3 (node, &mm->nodes, nl_entry) {
if ( V_5 -> type != V_28 ) {
if ( ++ V_35 > V_2 -> V_36 ) {
F_1 ( V_2 , L_5 ) ;
return - V_38 ;
}
}
}
F_27 (node, temp, &mm->nodes, nl_entry) {
F_5 ( & V_5 -> V_13 ) ;
F_6 ( V_5 ) ;
}
V_2 -> V_36 = 0 ;
return 0 ;
}
