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
static void F_8 ( struct V_12 * * V_22 , struct V_12 * V_12 )
{
if ( * V_22 && F_9 ( * V_22 , V_12 ) )
return;
F_10 ( * V_22 ) ;
* V_22 = F_11 ( V_12 ) ;
}
int F_12 ( struct V_10 * V_11 , struct V_1 * V_2 ,
struct V_12 * V_13 )
{
struct V_23 * V_24 ;
struct V_14 * V_12 ;
if ( ! V_13 )
return 0 ;
if ( F_3 ( V_11 , V_13 ) &&
F_7 ( V_13 , V_25 ) )
F_8 ( & V_2 -> V_9 , V_13 ) ;
V_12 = F_4 ( V_13 ) ;
if ( ! V_12 || V_12 -> V_18 -> V_11 != V_11 ) {
F_13 (sync->fences, e, node, f->context) {
if ( F_14 ( V_24 -> V_12 -> V_26 != V_13 -> V_26 ) )
continue;
F_8 ( & V_24 -> V_12 , V_13 ) ;
return 0 ;
}
V_24 = F_15 ( sizeof( struct V_23 ) , V_27 ) ;
if ( ! V_24 )
return - V_28 ;
F_16 ( V_2 -> V_8 , & V_24 -> V_29 , V_13 -> V_26 ) ;
V_24 -> V_12 = F_11 ( V_13 ) ;
return 0 ;
}
F_8 ( & V_2 -> V_7 [ V_12 -> V_18 -> V_30 ] , V_13 ) ;
return 0 ;
}
static void * F_17 ( struct V_12 * V_13 )
{
struct V_14 * V_15 = F_4 ( V_13 ) ;
struct V_16 * V_17 = F_5 ( V_13 ) ;
if ( V_17 )
return V_17 -> V_21 ;
else if ( V_15 )
return V_15 -> V_21 ;
return V_31 ;
}
int F_18 ( struct V_10 * V_11 ,
struct V_1 * V_2 ,
struct V_32 * V_33 ,
void * V_21 )
{
struct V_34 * V_35 ;
struct V_12 * V_13 ;
void * V_36 ;
unsigned V_3 ;
int V_37 = 0 ;
if ( V_33 == NULL )
return - V_38 ;
V_13 = F_19 ( V_33 ) ;
V_37 = F_12 ( V_11 , V_2 , V_13 ) ;
V_35 = F_20 ( V_33 ) ;
if ( ! V_35 || V_37 )
return V_37 ;
for ( V_3 = 0 ; V_3 < V_35 -> V_39 ; ++ V_3 ) {
V_13 = F_21 ( V_35 -> V_40 [ V_3 ] ,
F_22 ( V_33 ) ) ;
if ( F_3 ( V_11 , V_13 ) ) {
V_36 = F_17 ( V_13 ) ;
if ( ( V_21 != V_31 ) &&
( V_36 != V_31 ) &&
( ( V_21 == V_25 ) !=
( V_36 == V_25 ) ) )
continue;
if ( V_21 != V_31 &&
V_36 == V_21 )
continue;
}
V_37 = F_12 ( V_11 , V_2 , V_13 ) ;
if ( V_37 )
break;
}
return V_37 ;
}
struct V_12 * F_23 ( struct V_1 * V_2 )
{
struct V_23 * V_24 ;
struct V_41 * V_42 ;
struct V_12 * V_13 ;
int V_3 ;
F_24 (sync->fences, i, tmp, e, node) {
V_13 = V_24 -> V_12 ;
F_25 ( & V_24 -> V_29 ) ;
F_26 ( V_24 ) ;
if ( ! F_27 ( V_13 ) )
return V_13 ;
F_10 ( V_13 ) ;
}
return NULL ;
}
int F_28 ( struct V_1 * V_2 )
{
struct V_23 * V_24 ;
struct V_41 * V_42 ;
int V_3 , V_37 ;
F_24 (sync->fences, i, tmp, e, node) {
V_37 = F_29 ( V_24 -> V_12 , false ) ;
if ( V_37 )
return V_37 ;
F_25 ( & V_24 -> V_29 ) ;
F_10 ( V_24 -> V_12 ) ;
F_26 ( V_24 ) ;
}
if ( V_43 )
return 0 ;
for ( V_3 = 0 ; V_3 < V_6 ; ++ V_3 ) {
struct V_12 * V_12 = V_2 -> V_7 [ V_3 ] ;
if ( ! V_12 )
continue;
V_37 = F_29 ( V_12 , false ) ;
if ( V_37 )
return V_37 ;
}
return 0 ;
}
int F_30 ( struct V_1 * V_2 ,
struct V_19 * V_18 )
{
struct V_10 * V_11 = V_18 -> V_11 ;
unsigned V_44 = 0 ;
int V_3 , V_37 ;
for ( V_3 = 0 ; V_3 < V_6 ; ++ V_3 ) {
struct V_19 * V_45 = V_11 -> V_46 [ V_3 ] ;
struct V_47 * V_48 ;
struct V_14 * V_12 ;
if ( ! V_2 -> V_7 [ V_3 ] )
continue;
V_12 = F_4 ( V_2 -> V_7 [ V_3 ] ) ;
if ( ! F_31 ( V_12 , V_18 ) )
continue;
if ( ! V_45 -> V_49 ) {
F_32 ( V_11 -> V_50 , L_1 ) ;
return - V_38 ;
}
if ( V_51 || ! V_43 ) {
V_37 = F_29 ( & V_12 -> V_52 , true ) ;
if ( V_37 )
return V_37 ;
continue;
}
if ( V_44 >= V_4 ) {
V_37 = F_29 ( & V_12 -> V_52 , false ) ;
if ( V_37 )
return V_37 ;
continue;
}
V_37 = F_33 ( V_11 , & V_48 ) ;
if ( V_37 )
return V_37 ;
V_2 -> V_5 [ V_44 ++ ] = V_48 ;
V_37 = F_34 ( V_45 , 16 ) ;
if ( V_37 )
return V_37 ;
if ( ! F_35 ( V_45 , V_48 ) ) {
F_36 ( V_45 ) ;
V_37 = F_29 ( & V_12 -> V_52 , false ) ;
if ( V_37 )
return V_37 ;
continue;
}
if ( ! F_37 ( V_18 , V_48 ) ) {
F_36 ( V_45 ) ;
V_37 = F_29 ( & V_12 -> V_52 , false ) ;
if ( V_37 )
return V_37 ;
continue;
}
F_38 ( V_45 ) ;
F_39 ( V_12 , V_18 ) ;
}
return 0 ;
}
void F_40 ( struct V_10 * V_11 ,
struct V_1 * V_2 ,
struct V_12 * V_12 )
{
struct V_23 * V_24 ;
struct V_41 * V_42 ;
unsigned V_3 ;
F_24 (sync->fences, i, tmp, e, node) {
F_25 ( & V_24 -> V_29 ) ;
F_10 ( V_24 -> V_12 ) ;
F_26 ( V_24 ) ;
}
for ( V_3 = 0 ; V_3 < V_4 ; ++ V_3 )
F_41 ( V_11 , & V_2 -> V_5 [ V_3 ] , V_12 ) ;
for ( V_3 = 0 ; V_3 < V_6 ; ++ V_3 )
F_10 ( V_2 -> V_7 [ V_3 ] ) ;
F_10 ( V_2 -> V_9 ) ;
}
