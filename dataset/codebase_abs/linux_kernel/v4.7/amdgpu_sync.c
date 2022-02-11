void F_1 ( struct V_1 * V_2 )
{
F_2 ( V_2 -> V_3 ) ;
V_2 -> V_4 = NULL ;
}
static bool F_3 ( struct V_5 * V_6 , struct V_7 * V_8 )
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
static void F_7 ( struct V_7 * * V_16 , struct V_7 * V_7 )
{
if ( * V_16 && F_8 ( * V_16 , V_7 ) )
return;
F_9 ( * V_16 ) ;
* V_16 = F_10 ( V_7 ) ;
}
static bool F_11 ( struct V_1 * V_2 , struct V_7 * V_8 )
{
struct V_17 * V_18 ;
F_12 (sync->fences, e, node, f->context) {
if ( F_13 ( V_18 -> V_7 -> V_19 != V_8 -> V_19 ) )
continue;
F_7 ( & V_18 -> V_7 , V_8 ) ;
return true ;
}
return false ;
}
int F_14 ( struct V_5 * V_6 , struct V_1 * V_2 ,
struct V_7 * V_8 )
{
struct V_17 * V_18 ;
if ( ! V_8 )
return 0 ;
if ( F_3 ( V_6 , V_8 ) &&
F_6 ( V_8 ) == V_20 )
F_7 ( & V_2 -> V_4 , V_8 ) ;
if ( F_11 ( V_2 , V_8 ) )
return 0 ;
V_18 = F_15 ( V_21 , V_22 ) ;
if ( ! V_18 )
return - V_23 ;
F_16 ( V_2 -> V_3 , & V_18 -> V_24 , V_8 -> V_19 ) ;
V_18 -> V_7 = F_10 ( V_8 ) ;
return 0 ;
}
int F_17 ( struct V_5 * V_6 ,
struct V_1 * V_2 ,
struct V_25 * V_26 ,
void * V_14 )
{
struct V_27 * V_28 ;
struct V_7 * V_8 ;
void * V_29 ;
unsigned V_30 ;
int V_31 = 0 ;
if ( V_26 == NULL )
return - V_32 ;
V_8 = F_18 ( V_26 ) ;
V_31 = F_14 ( V_6 , V_2 , V_8 ) ;
V_28 = F_19 ( V_26 ) ;
if ( ! V_28 || V_31 )
return V_31 ;
for ( V_30 = 0 ; V_30 < V_28 -> V_33 ; ++ V_30 ) {
V_8 = F_20 ( V_28 -> V_34 [ V_30 ] ,
F_21 ( V_26 ) ) ;
if ( F_3 ( V_6 , V_8 ) ) {
V_29 = F_6 ( V_8 ) ;
if ( ( V_14 != V_15 ) &&
( V_29 != V_15 ) &&
( ( V_14 == V_20 ) !=
( V_29 == V_20 ) ) )
continue;
if ( V_14 != V_15 &&
V_29 == V_14 )
continue;
}
V_31 = F_14 ( V_6 , V_2 , V_8 ) ;
if ( V_31 )
break;
}
return V_31 ;
}
bool F_22 ( struct V_1 * V_2 )
{
struct V_17 * V_18 ;
struct V_35 * V_36 ;
int V_30 ;
F_23 (sync->fences, i, tmp, e, node) {
struct V_7 * V_8 = V_18 -> V_7 ;
if ( F_24 ( V_8 ) ) {
F_25 ( & V_18 -> V_24 ) ;
F_9 ( V_8 ) ;
F_26 ( V_21 , V_18 ) ;
continue;
}
return false ;
}
return true ;
}
int F_27 ( struct V_1 * V_37 , struct V_1 * V_38 ,
struct V_7 * V_7 )
{
struct V_17 * V_18 , * V_39 ;
struct V_35 * V_36 ;
int V_30 ;
V_39 = F_15 ( V_21 , V_22 ) ;
if ( ! V_39 )
return - V_23 ;
F_23 (src->fences, i, tmp, e, node) {
struct V_7 * V_8 = V_18 -> V_7 ;
F_25 ( & V_18 -> V_24 ) ;
if ( F_24 ( V_8 ) ) {
F_9 ( V_8 ) ;
F_26 ( V_21 , V_18 ) ;
continue;
}
if ( F_11 ( V_37 , V_8 ) ) {
F_26 ( V_21 , V_18 ) ;
continue;
}
F_16 ( V_37 -> V_3 , & V_18 -> V_24 , V_8 -> V_19 ) ;
}
F_16 ( V_38 -> V_3 , & V_39 -> V_24 , V_7 -> V_19 ) ;
V_39 -> V_7 = F_10 ( V_7 ) ;
return 0 ;
}
struct V_7 * F_28 ( struct V_1 * V_2 )
{
struct V_17 * V_18 ;
struct V_35 * V_36 ;
struct V_7 * V_8 ;
int V_30 ;
F_23 (sync->fences, i, tmp, e, node) {
V_8 = V_18 -> V_7 ;
F_25 ( & V_18 -> V_24 ) ;
F_26 ( V_21 , V_18 ) ;
if ( ! F_24 ( V_8 ) )
return V_8 ;
F_9 ( V_8 ) ;
}
return NULL ;
}
int F_29 ( struct V_1 * V_2 )
{
struct V_17 * V_18 ;
struct V_35 * V_36 ;
int V_30 , V_31 ;
F_23 (sync->fences, i, tmp, e, node) {
V_31 = F_30 ( V_18 -> V_7 , false ) ;
if ( V_31 )
return V_31 ;
F_25 ( & V_18 -> V_24 ) ;
F_9 ( V_18 -> V_7 ) ;
F_26 ( V_21 , V_18 ) ;
}
return 0 ;
}
void F_31 ( struct V_1 * V_2 )
{
struct V_17 * V_18 ;
struct V_35 * V_36 ;
unsigned V_30 ;
F_23 (sync->fences, i, tmp, e, node) {
F_25 ( & V_18 -> V_24 ) ;
F_9 ( V_18 -> V_7 ) ;
F_26 ( V_21 , V_18 ) ;
}
F_9 ( V_2 -> V_4 ) ;
}
int F_32 ( void )
{
V_21 = F_33 (
L_1 , sizeof( struct V_17 ) , 0 ,
V_40 , NULL ) ;
if ( ! V_21 )
return - V_23 ;
return 0 ;
}
void F_34 ( void )
{
F_35 ( V_21 ) ;
}
