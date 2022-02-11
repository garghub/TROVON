void F_1 ( struct V_1 * V_2 )
{
F_2 ( V_2 -> V_3 ) ;
V_2 -> V_4 = NULL ;
}
static bool F_3 ( struct V_5 * V_6 ,
struct V_7 * V_8 )
{
struct V_9 * V_10 = F_4 ( V_8 ) ;
if ( V_10 ) {
struct V_11 * V_12 ;
V_12 = F_5 ( V_10 -> V_13 , struct V_11 , V_13 ) ;
return V_12 -> V_6 == V_6 ;
}
return false ;
}
static void * F_6 ( struct V_7 * V_8 )
{
struct V_9 * V_10 = F_4 ( V_8 ) ;
if ( V_10 )
return V_10 -> V_14 ;
return V_15 ;
}
static void F_7 ( struct V_7 * * V_16 ,
struct V_7 * V_17 )
{
if ( * V_16 && F_8 ( * V_16 , V_17 ) )
return;
F_9 ( * V_16 ) ;
* V_16 = F_10 ( V_17 ) ;
}
static bool F_11 ( struct V_1 * V_2 , struct V_7 * V_8 )
{
struct V_18 * V_19 ;
F_12 (sync->fences, e, node, f->context) {
if ( F_13 ( V_19 -> V_17 -> V_20 != V_8 -> V_20 ) )
continue;
F_7 ( & V_19 -> V_17 , V_8 ) ;
return true ;
}
return false ;
}
int F_14 ( struct V_5 * V_6 , struct V_1 * V_2 ,
struct V_7 * V_8 )
{
struct V_18 * V_19 ;
if ( ! V_8 )
return 0 ;
if ( F_3 ( V_6 , V_8 ) &&
F_6 ( V_8 ) == V_21 )
F_7 ( & V_2 -> V_4 , V_8 ) ;
if ( F_11 ( V_2 , V_8 ) )
return 0 ;
V_19 = F_15 ( V_22 , V_23 ) ;
if ( ! V_19 )
return - V_24 ;
F_16 ( V_2 -> V_3 , & V_19 -> V_25 , V_8 -> V_20 ) ;
V_19 -> V_17 = F_10 ( V_8 ) ;
return 0 ;
}
int F_17 ( struct V_5 * V_6 ,
struct V_1 * V_2 ,
struct V_26 * V_27 ,
void * V_14 )
{
struct V_28 * V_29 ;
struct V_7 * V_8 ;
void * V_30 ;
unsigned V_31 ;
int V_32 = 0 ;
if ( V_27 == NULL )
return - V_33 ;
V_8 = F_18 ( V_27 ) ;
V_32 = F_14 ( V_6 , V_2 , V_8 ) ;
V_29 = F_19 ( V_27 ) ;
if ( ! V_29 || V_32 )
return V_32 ;
for ( V_31 = 0 ; V_31 < V_29 -> V_34 ; ++ V_31 ) {
V_8 = F_20 ( V_29 -> V_35 [ V_31 ] ,
F_21 ( V_27 ) ) ;
if ( F_3 ( V_6 , V_8 ) ) {
V_30 = F_6 ( V_8 ) ;
if ( ( V_14 != V_15 ) &&
( V_30 != V_15 ) &&
( ( V_14 == V_21 ) !=
( V_30 == V_21 ) ) )
continue;
if ( V_14 != V_15 &&
V_30 == V_14 )
continue;
}
V_32 = F_14 ( V_6 , V_2 , V_8 ) ;
if ( V_32 )
break;
}
return V_32 ;
}
struct V_7 * F_22 ( struct V_1 * V_2 ,
struct V_11 * V_12 )
{
struct V_18 * V_19 ;
struct V_36 * V_37 ;
int V_31 ;
F_23 (sync->fences, i, tmp, e, node) {
struct V_7 * V_8 = V_19 -> V_17 ;
struct V_9 * V_10 = F_4 ( V_8 ) ;
if ( V_12 && V_10 ) {
if ( V_10 -> V_13 == & V_12 -> V_13 ) {
if ( F_24 ( & V_10 -> V_38 ) )
continue;
return & V_10 -> V_38 ;
}
}
if ( F_24 ( V_8 ) ) {
F_25 ( & V_19 -> V_25 ) ;
F_9 ( V_8 ) ;
F_26 ( V_22 , V_19 ) ;
continue;
}
return V_8 ;
}
return NULL ;
}
struct V_7 * F_27 ( struct V_1 * V_2 )
{
struct V_18 * V_19 ;
struct V_36 * V_37 ;
struct V_7 * V_8 ;
int V_31 ;
F_23 (sync->fences, i, tmp, e, node) {
V_8 = V_19 -> V_17 ;
F_25 ( & V_19 -> V_25 ) ;
F_26 ( V_22 , V_19 ) ;
if ( ! F_24 ( V_8 ) )
return V_8 ;
F_9 ( V_8 ) ;
}
return NULL ;
}
void F_28 ( struct V_1 * V_2 )
{
struct V_18 * V_19 ;
struct V_36 * V_37 ;
unsigned V_31 ;
F_23 (sync->fences, i, tmp, e, node) {
F_25 ( & V_19 -> V_25 ) ;
F_9 ( V_19 -> V_17 ) ;
F_26 ( V_22 , V_19 ) ;
}
F_9 ( V_2 -> V_4 ) ;
}
int F_29 ( void )
{
V_22 = F_30 (
L_1 , sizeof( struct V_18 ) , 0 ,
V_39 , NULL ) ;
if ( ! V_22 )
return - V_24 ;
return 0 ;
}
void F_31 ( void )
{
F_32 ( V_22 ) ;
}
