static struct V_1 * F_1 ( struct V_2 * V_3 ,
const struct V_4 * V_5 )
{
struct V_1 * V_6 ;
F_2 (m, &masters, node)
if ( V_6 -> V_3 == V_3 && ( ! V_5 || V_6 -> V_5 == V_5 ) )
return V_6 ;
return NULL ;
}
static struct V_7 * F_3 ( struct V_1 * V_1 ,
int (* F_4)( struct V_2 * , void * ) , void * V_8 )
{
struct V_7 * V_9 ;
F_2 (c, &component_list, node) {
if ( V_9 -> V_1 && V_9 -> V_1 != V_1 )
continue;
if ( F_4 ( V_9 -> V_3 , V_8 ) )
return V_9 ;
}
return NULL ;
}
static int F_5 ( struct V_1 * V_1 )
{
struct V_10 * V_11 = V_1 -> V_11 ;
T_1 V_12 ;
int V_13 = 0 ;
for ( V_12 = 0 ; V_12 < V_11 -> V_14 ; V_12 ++ ) {
struct V_15 * V_16 = & V_11 -> F_4 [ V_12 ] ;
struct V_7 * V_9 ;
F_6 ( V_1 -> V_3 , L_1 , V_12 ) ;
if ( V_11 -> F_4 [ V_12 ] . V_7 )
continue;
V_9 = F_3 ( V_1 , V_16 -> F_4 , V_16 -> V_17 ) ;
if ( ! V_9 ) {
V_13 = - V_18 ;
break;
}
F_6 ( V_1 -> V_3 , L_2 , F_7 ( V_9 -> V_3 ) , ! ! V_9 -> V_1 ) ;
V_11 -> F_4 [ V_12 ] . V_19 = ! ! V_9 -> V_1 ;
V_11 -> F_4 [ V_12 ] . V_7 = V_9 ;
V_9 -> V_1 = V_1 ;
}
return V_13 ;
}
static void F_8 ( struct V_1 * V_1 , struct V_7 * V_9 )
{
T_1 V_12 ;
for ( V_12 = 0 ; V_12 < V_1 -> V_11 -> V_14 ; V_12 ++ )
if ( V_1 -> V_11 -> F_4 [ V_12 ] . V_7 == V_9 )
V_1 -> V_11 -> F_4 [ V_12 ] . V_7 = NULL ;
}
static int F_9 ( struct V_1 * V_1 ,
struct V_7 * V_7 )
{
int V_13 ;
F_6 ( V_1 -> V_3 , L_3 ) ;
if ( F_5 ( V_1 ) ) {
F_6 ( V_1 -> V_3 , L_4 ) ;
return 0 ;
}
if ( V_7 && V_7 -> V_1 != V_1 ) {
F_6 ( V_1 -> V_3 , L_5 ,
F_7 ( V_7 -> V_3 ) ) ;
return 0 ;
}
if ( ! F_10 ( V_1 -> V_3 , NULL , V_20 ) )
return - V_21 ;
V_13 = V_1 -> V_5 -> V_22 ( V_1 -> V_3 ) ;
if ( V_13 < 0 ) {
F_11 ( V_1 -> V_3 , NULL ) ;
F_12 ( V_1 -> V_3 , L_6 , V_13 ) ;
return V_13 ;
}
V_1 -> V_23 = true ;
return 1 ;
}
static int F_13 ( struct V_7 * V_7 )
{
struct V_1 * V_6 ;
int V_13 = 0 ;
F_2 (m, &masters, node) {
if ( ! V_6 -> V_23 ) {
V_13 = F_9 ( V_6 , V_7 ) ;
if ( V_13 != 0 )
break;
}
}
return V_13 ;
}
static void F_14 ( struct V_1 * V_1 )
{
if ( V_1 -> V_23 ) {
V_1 -> V_5 -> V_24 ( V_1 -> V_3 ) ;
F_11 ( V_1 -> V_3 , NULL ) ;
V_1 -> V_23 = false ;
}
}
static void F_15 ( struct V_2 * V_1 ,
struct V_10 * V_11 )
{
unsigned int V_12 ;
for ( V_12 = 0 ; V_12 < V_11 -> V_14 ; V_12 ++ ) {
struct V_15 * V_16 = & V_11 -> F_4 [ V_12 ] ;
if ( V_16 -> V_25 )
V_16 -> V_25 ( V_1 , V_16 -> V_17 ) ;
}
F_16 ( V_11 -> F_4 ) ;
}
static void F_17 ( struct V_2 * V_3 , void * V_26 )
{
F_15 ( V_3 , V_26 ) ;
}
static int F_18 ( struct V_2 * V_3 ,
struct V_10 * V_11 , T_1 V_14 )
{
struct V_15 * V_27 ;
if ( V_11 -> V_28 == V_14 )
return 0 ;
V_27 = F_19 ( V_14 , sizeof( * V_27 ) , V_20 ) ;
if ( ! V_27 )
return - V_21 ;
if ( V_11 -> F_4 ) {
memcpy ( V_27 , V_11 -> F_4 , sizeof( * V_27 ) *
F_20 ( V_11 -> V_14 , V_14 ) ) ;
F_16 ( V_11 -> F_4 ) ;
}
V_11 -> F_4 = V_27 ;
V_11 -> V_28 = V_14 ;
return 0 ;
}
void F_21 ( struct V_2 * V_1 ,
struct V_10 * * V_29 ,
void (* V_25)( struct V_2 * , void * ) ,
int (* F_4)( struct V_2 * , void * ) , void * V_8 )
{
struct V_10 * V_11 = * V_29 ;
if ( F_22 ( V_11 ) )
return;
if ( ! V_11 ) {
V_11 = F_23 ( F_17 ,
sizeof( * V_11 ) , V_20 ) ;
if ( ! V_11 ) {
* V_29 = F_24 ( - V_21 ) ;
return;
}
F_25 ( V_1 , V_11 ) ;
* V_29 = V_11 ;
}
if ( V_11 -> V_14 == V_11 -> V_28 ) {
T_1 V_30 = V_11 -> V_28 + 16 ;
int V_13 ;
V_13 = F_18 ( V_1 , V_11 , V_30 ) ;
if ( V_13 ) {
* V_29 = F_24 ( V_13 ) ;
return;
}
}
V_11 -> F_4 [ V_11 -> V_14 ] . F_4 = F_4 ;
V_11 -> F_4 [ V_11 -> V_14 ] . V_25 = V_25 ;
V_11 -> F_4 [ V_11 -> V_14 ] . V_17 = V_8 ;
V_11 -> F_4 [ V_11 -> V_14 ] . V_7 = NULL ;
V_11 -> V_14 ++ ;
}
static void F_26 ( struct V_1 * V_1 )
{
struct V_10 * V_11 = V_1 -> V_11 ;
int V_12 ;
F_27 ( & V_1 -> V_31 ) ;
if ( V_11 ) {
for ( V_12 = 0 ; V_12 < V_11 -> V_14 ; V_12 ++ ) {
struct V_7 * V_9 = V_11 -> F_4 [ V_12 ] . V_7 ;
if ( V_9 )
V_9 -> V_1 = NULL ;
}
}
F_16 ( V_1 ) ;
}
int F_28 ( struct V_2 * V_3 ,
const struct V_4 * V_5 ,
struct V_10 * V_11 )
{
struct V_1 * V_1 ;
int V_13 ;
V_13 = F_18 ( V_3 , V_11 , V_11 -> V_14 ) ;
if ( V_13 )
return V_13 ;
V_1 = F_29 ( sizeof( * V_1 ) , V_20 ) ;
if ( ! V_1 )
return - V_21 ;
V_1 -> V_3 = V_3 ;
V_1 -> V_5 = V_5 ;
V_1 -> V_11 = V_11 ;
F_30 ( & V_32 ) ;
F_31 ( & V_1 -> V_31 , & V_33 ) ;
V_13 = F_9 ( V_1 , NULL ) ;
if ( V_13 < 0 )
F_26 ( V_1 ) ;
F_32 ( & V_32 ) ;
return V_13 < 0 ? V_13 : 0 ;
}
void F_33 ( struct V_2 * V_3 ,
const struct V_4 * V_5 )
{
struct V_1 * V_1 ;
F_30 ( & V_32 ) ;
V_1 = F_1 ( V_3 , V_5 ) ;
if ( V_1 ) {
F_14 ( V_1 ) ;
F_26 ( V_1 ) ;
}
F_32 ( & V_32 ) ;
}
static void F_34 ( struct V_7 * V_7 ,
struct V_1 * V_1 , void * V_17 )
{
F_35 ( ! V_7 -> V_23 ) ;
V_7 -> V_5 -> V_24 ( V_7 -> V_3 , V_1 -> V_3 , V_17 ) ;
V_7 -> V_23 = false ;
F_11 ( V_7 -> V_3 , V_7 ) ;
}
void F_36 ( struct V_2 * V_34 , void * V_17 )
{
struct V_1 * V_1 ;
struct V_7 * V_9 ;
T_1 V_12 ;
F_35 ( ! F_37 ( & V_32 ) ) ;
V_1 = F_1 ( V_34 , NULL ) ;
if ( ! V_1 )
return;
for ( V_12 = V_1 -> V_11 -> V_14 ; V_12 -- ; )
if ( ! V_1 -> V_11 -> F_4 [ V_12 ] . V_19 ) {
V_9 = V_1 -> V_11 -> F_4 [ V_12 ] . V_7 ;
F_34 ( V_9 , V_1 , V_17 ) ;
}
}
static int F_38 ( struct V_7 * V_7 , struct V_1 * V_1 ,
void * V_17 )
{
int V_13 ;
if ( ! F_10 ( V_1 -> V_3 , NULL , V_20 ) )
return - V_21 ;
if ( ! F_10 ( V_7 -> V_3 , V_7 , V_20 ) ) {
F_11 ( V_1 -> V_3 , NULL ) ;
return - V_21 ;
}
F_6 ( V_1 -> V_3 , L_7 ,
F_7 ( V_7 -> V_3 ) , V_7 -> V_5 ) ;
V_13 = V_7 -> V_5 -> V_22 ( V_7 -> V_3 , V_1 -> V_3 , V_17 ) ;
if ( ! V_13 ) {
V_7 -> V_23 = true ;
F_39 ( V_7 -> V_3 , NULL ) ;
F_40 ( V_1 -> V_3 , NULL ) ;
F_12 ( V_1 -> V_3 , L_8 ,
F_7 ( V_7 -> V_3 ) , V_7 -> V_5 ) ;
} else {
F_11 ( V_7 -> V_3 , NULL ) ;
F_11 ( V_1 -> V_3 , NULL ) ;
F_41 ( V_1 -> V_3 , L_9 ,
F_7 ( V_7 -> V_3 ) , V_7 -> V_5 , V_13 ) ;
}
return V_13 ;
}
int F_42 ( struct V_2 * V_34 , void * V_17 )
{
struct V_1 * V_1 ;
struct V_7 * V_9 ;
T_1 V_12 ;
int V_13 = 0 ;
F_35 ( ! F_37 ( & V_32 ) ) ;
V_1 = F_1 ( V_34 , NULL ) ;
if ( ! V_1 )
return - V_35 ;
for ( V_12 = 0 ; V_12 < V_1 -> V_11 -> V_14 ; V_12 ++ )
if ( ! V_1 -> V_11 -> F_4 [ V_12 ] . V_19 ) {
V_9 = V_1 -> V_11 -> F_4 [ V_12 ] . V_7 ;
V_13 = F_38 ( V_9 , V_1 , V_17 ) ;
if ( V_13 )
break;
}
if ( V_13 != 0 ) {
for (; V_12 -- ; )
if ( ! V_1 -> V_11 -> F_4 [ V_12 ] . V_19 ) {
V_9 = V_1 -> V_11 -> F_4 [ V_12 ] . V_7 ;
F_34 ( V_9 , V_1 , V_17 ) ;
}
}
return V_13 ;
}
int F_43 ( struct V_2 * V_3 , const struct V_36 * V_5 )
{
struct V_7 * V_7 ;
int V_13 ;
V_7 = F_29 ( sizeof( * V_7 ) , V_20 ) ;
if ( ! V_7 )
return - V_21 ;
V_7 -> V_5 = V_5 ;
V_7 -> V_3 = V_3 ;
F_6 ( V_3 , L_10 , V_5 ) ;
F_30 ( & V_32 ) ;
F_44 ( & V_7 -> V_31 , & V_37 ) ;
V_13 = F_13 ( V_7 ) ;
if ( V_13 < 0 ) {
if ( V_7 -> V_1 )
F_8 ( V_7 -> V_1 , V_7 ) ;
F_27 ( & V_7 -> V_31 ) ;
F_16 ( V_7 ) ;
}
F_32 ( & V_32 ) ;
return V_13 < 0 ? V_13 : 0 ;
}
void F_45 ( struct V_2 * V_3 , const struct V_36 * V_5 )
{
struct V_7 * V_9 , * V_7 = NULL ;
F_30 ( & V_32 ) ;
F_2 (c, &component_list, node)
if ( V_9 -> V_3 == V_3 && V_9 -> V_5 == V_5 ) {
F_27 ( & V_9 -> V_31 ) ;
V_7 = V_9 ;
break;
}
if ( V_7 && V_7 -> V_1 ) {
F_14 ( V_7 -> V_1 ) ;
F_8 ( V_7 -> V_1 , V_7 ) ;
}
F_32 ( & V_32 ) ;
F_35 ( ! V_7 ) ;
F_16 ( V_7 ) ;
}
