void F_1 ( struct V_1 * V_2 )
{
unsigned V_3 ;
for ( V_3 = 0 ; V_3 < V_4 ; ++ V_3 )
V_2 -> V_5 [ V_3 ] = NULL ;
for ( V_3 = 0 ; V_3 < V_6 ; ++ V_3 )
V_2 -> V_7 [ V_3 ] = NULL ;
F_2 ( V_2 -> V_8 ) ;
V_2 -> V_9 = NULL ;
}
static bool F_3 ( struct V_10 * V_11 , struct V_12 * V_13 )
{
struct V_14 * V_15 = F_4 ( V_13 ) ;
struct V_16 * V_17 = F_5 ( V_13 ) ;
if ( V_15 )
return V_15 -> V_18 -> V_11 == V_11 ;
if ( V_17 ) {
struct V_19 * V_18 ;
V_18 = F_6 ( V_17 -> V_20 , struct V_19 , V_20 ) ;
return V_18 -> V_11 == V_11 ;
}
return false ;
}
static bool F_7 ( struct V_12 * V_13 , void * V_21 )
{
struct V_14 * V_15 = F_4 ( V_13 ) ;
struct V_16 * V_17 = F_5 ( V_13 ) ;
if ( V_17 )
return V_17 -> V_21 == V_21 ;
if ( V_15 )
return V_15 -> V_21 == V_21 ;
return false ;
}
int F_8 ( struct V_10 * V_11 , struct V_1 * V_2 ,
struct V_12 * V_13 )
{
struct V_22 * V_23 ;
struct V_14 * V_12 ;
struct V_14 * V_24 ;
struct V_12 * V_25 , * V_26 ;
if ( ! V_13 )
return 0 ;
if ( F_3 ( V_11 , V_13 ) &&
F_7 ( V_13 , V_27 ) ) {
if ( V_2 -> V_9 ) {
V_25 = V_2 -> V_9 ;
F_9 ( V_13 -> V_28 != V_25 -> V_28 ) ;
V_26 = ( V_13 -> V_29 - V_25 -> V_29 <= V_30 ) ? V_13 : V_25 ;
V_2 -> V_9 = F_10 ( V_26 ) ;
F_11 ( V_25 ) ;
} else
V_2 -> V_9 = F_10 ( V_13 ) ;
}
V_12 = F_4 ( V_13 ) ;
if ( ! V_12 || V_12 -> V_18 -> V_11 != V_11 ) {
F_12 (sync->fences, e, node, f->context) {
struct V_12 * V_31 ;
if ( F_13 ( V_23 -> V_12 -> V_28 != V_13 -> V_28 ) )
continue;
V_31 = F_10 ( F_14 ( V_23 -> V_12 , V_13 ) ) ;
if ( V_31 ) {
F_11 ( V_23 -> V_12 ) ;
V_23 -> V_12 = V_31 ;
}
return 0 ;
}
V_23 = F_15 ( sizeof( struct V_22 ) , V_32 ) ;
if ( ! V_23 )
return - V_33 ;
F_16 ( V_2 -> V_8 , & V_23 -> V_34 , V_13 -> V_28 ) ;
V_23 -> V_12 = F_10 ( V_13 ) ;
return 0 ;
}
V_24 = V_2 -> V_7 [ V_12 -> V_18 -> V_35 ] ;
V_2 -> V_7 [ V_12 -> V_18 -> V_35 ] = F_17 (
F_18 ( V_12 , V_24 ) ) ;
F_19 ( & V_24 ) ;
return 0 ;
}
static void * F_20 ( struct V_12 * V_13 )
{
struct V_14 * V_15 = F_4 ( V_13 ) ;
struct V_16 * V_17 = F_5 ( V_13 ) ;
if ( V_17 )
return V_17 -> V_21 ;
else if ( V_15 )
return V_15 -> V_21 ;
return V_36 ;
}
int F_21 ( struct V_10 * V_11 ,
struct V_1 * V_2 ,
struct V_37 * V_38 ,
void * V_21 )
{
struct V_39 * V_40 ;
struct V_12 * V_13 ;
void * V_41 ;
unsigned V_3 ;
int V_42 = 0 ;
if ( V_38 == NULL )
return - V_43 ;
V_13 = F_22 ( V_38 ) ;
V_42 = F_8 ( V_11 , V_2 , V_13 ) ;
V_40 = F_23 ( V_38 ) ;
if ( ! V_40 || V_42 )
return V_42 ;
for ( V_3 = 0 ; V_3 < V_40 -> V_44 ; ++ V_3 ) {
V_13 = F_24 ( V_40 -> V_45 [ V_3 ] ,
F_25 ( V_38 ) ) ;
if ( F_3 ( V_11 , V_13 ) ) {
V_41 = F_20 ( V_13 ) ;
if ( ( V_21 != V_46 ) &&
( V_41 != V_46 ) &&
( ( V_21 == V_27 ) !=
( V_41 == V_27 ) ) )
continue;
if ( V_21 != V_36 &&
V_41 == V_21 )
continue;
}
V_42 = F_8 ( V_11 , V_2 , V_13 ) ;
if ( V_42 )
break;
}
return V_42 ;
}
struct V_12 * F_26 ( struct V_1 * V_2 )
{
struct V_22 * V_23 ;
struct V_47 * V_25 ;
struct V_12 * V_13 ;
int V_3 ;
F_27 (sync->fences, i, tmp, e, node) {
V_13 = V_23 -> V_12 ;
F_28 ( & V_23 -> V_34 ) ;
F_29 ( V_23 ) ;
if ( ! F_30 ( V_13 ) )
return V_13 ;
F_11 ( V_13 ) ;
}
return NULL ;
}
int F_31 ( struct V_1 * V_2 )
{
struct V_22 * V_23 ;
struct V_47 * V_25 ;
int V_3 , V_42 ;
F_27 (sync->fences, i, tmp, e, node) {
V_42 = F_32 ( V_23 -> V_12 , false ) ;
if ( V_42 )
return V_42 ;
F_28 ( & V_23 -> V_34 ) ;
F_11 ( V_23 -> V_12 ) ;
F_29 ( V_23 ) ;
}
if ( V_48 )
return 0 ;
for ( V_3 = 0 ; V_3 < V_6 ; ++ V_3 ) {
struct V_14 * V_12 = V_2 -> V_7 [ V_3 ] ;
if ( ! V_12 )
continue;
V_42 = F_32 ( & V_12 -> V_49 , false ) ;
if ( V_42 )
return V_42 ;
}
return 0 ;
}
int F_33 ( struct V_1 * V_2 ,
struct V_19 * V_18 )
{
struct V_10 * V_11 = V_18 -> V_11 ;
unsigned V_50 = 0 ;
int V_3 , V_42 ;
for ( V_3 = 0 ; V_3 < V_6 ; ++ V_3 ) {
struct V_14 * V_12 = V_2 -> V_7 [ V_3 ] ;
struct V_51 * V_52 ;
struct V_19 * V_24 = V_11 -> V_53 [ V_3 ] ;
if ( ! F_34 ( V_12 , V_18 ) )
continue;
if ( ! V_24 -> V_54 ) {
F_35 ( V_11 -> V_55 , L_1 ) ;
return - V_43 ;
}
if ( V_56 || ! V_48 ||
( V_50 >= V_4 ) ) {
V_42 = F_32 ( & V_12 -> V_49 , false ) ;
if ( V_42 )
return V_42 ;
continue;
}
V_42 = F_36 ( V_11 , & V_52 ) ;
if ( V_42 )
return V_42 ;
V_2 -> V_5 [ V_50 ++ ] = V_52 ;
V_42 = F_37 ( V_24 , 16 ) ;
if ( V_42 )
return V_42 ;
if ( ! F_38 ( V_24 , V_52 ) ) {
F_39 ( V_24 ) ;
V_42 = F_32 ( & V_12 -> V_49 , false ) ;
if ( V_42 )
return V_42 ;
continue;
}
if ( ! F_40 ( V_18 , V_52 ) ) {
F_39 ( V_24 ) ;
V_42 = F_32 ( & V_12 -> V_49 , false ) ;
if ( V_42 )
return V_42 ;
continue;
}
F_41 ( V_24 ) ;
F_42 ( V_12 , V_18 ) ;
}
return 0 ;
}
void F_43 ( struct V_10 * V_11 ,
struct V_1 * V_2 ,
struct V_12 * V_12 )
{
struct V_22 * V_23 ;
struct V_47 * V_25 ;
unsigned V_3 ;
F_27 (sync->fences, i, tmp, e, node) {
F_28 ( & V_23 -> V_34 ) ;
F_11 ( V_23 -> V_12 ) ;
F_29 ( V_23 ) ;
}
for ( V_3 = 0 ; V_3 < V_4 ; ++ V_3 )
F_44 ( V_11 , & V_2 -> V_5 [ V_3 ] , V_12 ) ;
for ( V_3 = 0 ; V_3 < V_6 ; ++ V_3 )
F_19 ( & V_2 -> V_7 [ V_3 ] ) ;
F_11 ( V_2 -> V_9 ) ;
}
