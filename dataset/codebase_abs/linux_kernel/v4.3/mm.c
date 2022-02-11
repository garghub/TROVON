void
F_1 ( struct V_1 * V_2 , const char * V_3 )
{
struct V_4 * V_5 ;
F_2 ( V_6 L_1 , V_3 ) ;
F_2 ( V_6 L_2 ) ;
F_3 (node, &mm->nodes, nl_entry) {
F_2 ( V_6 L_3 ,
V_5 -> V_7 , V_5 -> V_8 , V_5 -> type ) ;
}
F_2 ( V_6 L_4 ) ;
F_3 (node, &mm->free, fl_entry) {
F_2 ( V_6 L_3 ,
V_5 -> V_7 , V_5 -> V_8 , V_5 -> type ) ;
}
}
void
F_4 ( struct V_1 * V_2 , struct V_4 * * V_9 )
{
struct V_4 * V_10 = * V_9 ;
if ( V_10 ) {
struct V_4 * V_11 = V_5 ( V_10 , V_11 ) ;
struct V_4 * V_12 = V_5 ( V_10 , V_12 ) ;
if ( V_11 && V_11 -> type == V_13 ) {
V_11 -> V_8 += V_10 -> V_8 ;
F_5 ( & V_10 -> V_14 ) ;
F_6 ( V_10 ) ; V_10 = V_11 ;
}
if ( V_12 && V_12 -> type == V_13 ) {
V_12 -> V_7 = V_10 -> V_7 ;
V_12 -> V_8 += V_10 -> V_8 ;
if ( V_10 -> type == V_13 )
F_5 ( & V_10 -> V_15 ) ;
F_5 ( & V_10 -> V_14 ) ;
F_6 ( V_10 ) ; V_10 = NULL ;
}
if ( V_10 && V_10 -> type != V_13 ) {
F_3 (prev, &mm->free, fl_entry) {
if ( V_10 -> V_7 < V_11 -> V_7 )
break;
}
F_7 ( & V_10 -> V_15 , & V_11 -> V_15 ) ;
V_10 -> type = V_13 ;
}
}
* V_9 = NULL ;
}
static struct V_4 *
F_8 ( struct V_1 * V_2 , struct V_4 * V_16 , T_1 V_17 )
{
struct V_4 * V_18 ;
if ( V_16 -> V_8 == V_17 )
return V_16 ;
V_18 = F_9 ( sizeof( * V_18 ) , V_19 ) ;
if ( F_10 ( V_18 == NULL ) )
return NULL ;
V_18 -> V_7 = V_16 -> V_7 ;
V_18 -> V_8 = V_17 ;
V_18 -> V_20 = V_16 -> V_20 ;
V_18 -> type = V_16 -> type ;
V_16 -> V_7 += V_17 ;
V_16 -> V_8 -= V_17 ;
F_7 ( & V_18 -> V_14 , & V_16 -> V_14 ) ;
if ( V_18 -> type == V_13 )
F_7 ( & V_18 -> V_15 , & V_16 -> V_15 ) ;
return V_18 ;
}
int
F_11 ( struct V_1 * V_2 , T_2 V_20 , T_2 type , T_1 V_21 , T_1 V_22 ,
T_1 V_23 , struct V_4 * * V_24 )
{
struct V_4 * V_11 , * V_10 , * V_12 ;
T_1 V_25 = V_23 - 1 ;
T_1 V_26 ;
T_1 V_27 , V_28 ;
F_12 ( type == V_13 || type == V_29 ) ;
F_3 (this, &mm->free, fl_entry) {
if ( F_10 ( V_20 != V_30 ) ) {
if ( V_10 -> V_20 != V_20 )
continue;
}
V_28 = V_10 -> V_7 + V_10 -> V_8 ;
V_27 = V_10 -> V_7 ;
V_11 = V_5 ( V_10 , V_11 ) ;
if ( V_11 && V_11 -> type != type )
V_27 = F_13 ( V_27 , V_2 -> V_31 ) ;
V_12 = V_5 ( V_10 , V_12 ) ;
if ( V_12 && V_12 -> type != type )
V_28 = F_14 ( V_28 , V_2 -> V_31 ) ;
V_27 = ( V_27 + V_25 ) & ~ V_25 ;
V_28 &= ~ V_25 ;
if ( V_27 > V_28 || V_28 - V_27 < V_22 )
continue;
V_26 = V_27 - V_10 -> V_7 ;
if ( V_26 && ! F_8 ( V_2 , V_10 , V_26 ) )
return - V_32 ;
V_10 = F_8 ( V_2 , V_10 , F_15 ( V_21 , V_28 - V_27 ) ) ;
if ( ! V_10 )
return - V_32 ;
V_10 -> type = type ;
F_5 ( & V_10 -> V_15 ) ;
* V_24 = V_10 ;
return 0 ;
}
return - V_33 ;
}
static struct V_4 *
F_16 ( struct V_1 * V_2 , struct V_4 * V_16 , T_1 V_17 )
{
struct V_4 * V_18 ;
if ( V_16 -> V_8 == V_17 )
return V_16 ;
V_18 = F_9 ( sizeof( * V_18 ) , V_19 ) ;
if ( F_10 ( V_18 == NULL ) )
return NULL ;
V_16 -> V_8 -= V_17 ;
V_18 -> V_7 = V_16 -> V_7 + V_16 -> V_8 ;
V_18 -> V_8 = V_17 ;
V_18 -> V_20 = V_16 -> V_20 ;
V_18 -> type = V_16 -> type ;
F_17 ( & V_18 -> V_14 , & V_16 -> V_14 ) ;
if ( V_18 -> type == V_13 )
F_17 ( & V_18 -> V_15 , & V_16 -> V_15 ) ;
return V_18 ;
}
int
F_18 ( struct V_1 * V_2 , T_2 V_20 , T_2 type , T_1 V_21 , T_1 V_22 ,
T_1 V_23 , struct V_4 * * V_24 )
{
struct V_4 * V_11 , * V_10 , * V_12 ;
T_1 V_25 = V_23 - 1 ;
F_12 ( type == V_13 || type == V_29 ) ;
F_19 (this, &mm->free, fl_entry) {
T_1 V_28 = V_10 -> V_7 + V_10 -> V_8 ;
T_1 V_27 = V_10 -> V_7 ;
T_1 V_34 = 0 , V_16 ;
if ( F_10 ( V_20 != V_30 ) ) {
if ( V_10 -> V_20 != V_20 )
continue;
}
V_11 = V_5 ( V_10 , V_11 ) ;
if ( V_11 && V_11 -> type != type )
V_27 = F_13 ( V_27 , V_2 -> V_31 ) ;
V_12 = V_5 ( V_10 , V_12 ) ;
if ( V_12 && V_12 -> type != type ) {
V_28 = F_14 ( V_28 , V_2 -> V_31 ) ;
V_34 = V_12 -> V_7 - V_28 ;
}
V_27 = ( V_27 + V_25 ) & ~ V_25 ;
V_16 = V_28 - V_27 ;
if ( V_27 > V_28 || V_16 < V_22 )
continue;
V_16 = F_15 ( V_16 , V_21 ) ;
V_27 = ( V_28 - V_16 ) & ~ V_25 ;
V_34 += ( V_28 - V_27 ) - V_16 ;
if ( V_34 && ! F_16 ( V_2 , V_10 , V_34 ) )
return - V_32 ;
V_10 = F_16 ( V_2 , V_10 , V_16 ) ;
if ( ! V_10 )
return - V_32 ;
V_10 -> type = type ;
F_5 ( & V_10 -> V_15 ) ;
* V_24 = V_10 ;
return 0 ;
}
return - V_33 ;
}
int
F_20 ( struct V_1 * V_2 , T_1 V_7 , T_1 V_8 , T_1 V_35 )
{
struct V_4 * V_5 , * V_11 ;
T_1 V_12 ;
if ( F_21 ( V_2 ) ) {
V_11 = F_22 ( & V_2 -> V_36 , F_23 ( * V_5 ) , V_14 ) ;
V_12 = V_11 -> V_7 + V_11 -> V_8 ;
if ( V_12 != V_7 ) {
F_12 ( V_12 > V_7 ) ;
if ( ! ( V_5 = F_24 ( sizeof( * V_5 ) , V_19 ) ) )
return - V_32 ;
V_5 -> type = V_29 ;
V_5 -> V_7 = V_12 ;
V_5 -> V_8 = V_7 - V_12 ;
F_7 ( & V_5 -> V_14 , & V_2 -> V_36 ) ;
}
F_12 ( V_35 != V_2 -> V_31 ) ;
} else {
F_25 ( & V_2 -> V_36 ) ;
F_25 ( & V_2 -> free ) ;
V_2 -> V_31 = V_35 ;
V_2 -> V_37 = 0 ;
}
V_5 = F_24 ( sizeof( * V_5 ) , V_19 ) ;
if ( ! V_5 )
return - V_32 ;
if ( V_8 ) {
V_5 -> V_7 = F_13 ( V_7 , V_2 -> V_31 ) ;
V_5 -> V_8 = F_14 ( V_7 + V_8 , V_2 -> V_31 ) ;
V_5 -> V_8 -= V_5 -> V_7 ;
}
F_7 ( & V_5 -> V_14 , & V_2 -> V_36 ) ;
F_7 ( & V_5 -> V_15 , & V_2 -> free ) ;
V_5 -> V_20 = ++ V_2 -> V_37 ;
return 0 ;
}
int
F_26 ( struct V_1 * V_2 )
{
struct V_4 * V_5 , * V_38 ;
int V_36 = 0 ;
if ( ! F_21 ( V_2 ) )
return 0 ;
F_3 (node, &mm->nodes, nl_entry) {
if ( V_5 -> type != V_29 ) {
if ( ++ V_36 > V_2 -> V_37 ) {
F_1 ( V_2 , L_5 ) ;
return - V_39 ;
}
}
}
F_27 (node, temp, &mm->nodes, nl_entry) {
F_5 ( & V_5 -> V_14 ) ;
F_6 ( V_5 ) ;
}
V_2 -> V_37 = 0 ;
return 0 ;
}
