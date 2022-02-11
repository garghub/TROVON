static struct V_1 * F_1 ( struct V_2 * V_3 ,
const struct V_4 * V_5 )
{
struct V_1 * V_6 ;
F_2 (m, &masters, node)
if ( V_6 -> V_3 == V_3 && ( ! V_5 || V_6 -> V_5 == V_5 ) )
return V_6 ;
return NULL ;
}
static void F_3 ( struct V_1 * V_1 , struct V_7 * V_8 )
{
V_8 -> V_1 = V_1 ;
F_4 ( & V_8 -> V_9 , & V_1 -> V_10 ) ;
}
static void F_5 ( struct V_1 * V_1 , struct V_7 * V_8 )
{
F_6 ( & V_8 -> V_9 ) ;
V_8 -> V_1 = NULL ;
}
int F_7 ( struct V_1 * V_1 ,
int (* F_8)( struct V_2 * , void * ) , void * V_11 )
{
struct V_7 * V_8 ;
int V_12 = - V_13 ;
F_2 (c, &component_list, node) {
if ( V_8 -> V_1 )
continue;
if ( F_8 ( V_8 -> V_3 , V_11 ) ) {
F_3 ( V_1 , V_8 ) ;
V_12 = 0 ;
break;
}
}
return V_12 ;
}
static void F_9 ( struct V_1 * V_1 )
{
while ( ! F_10 ( & V_1 -> V_10 ) ) {
struct V_7 * V_8 = F_11 ( & V_1 -> V_10 ,
struct V_7 , V_9 ) ;
F_12 ( V_8 -> V_1 != V_1 ) ;
F_5 ( V_1 , V_8 ) ;
}
}
static int F_13 ( struct V_1 * V_1 ,
struct V_7 * V_7 )
{
int V_12 = 0 ;
if ( ! V_1 -> V_14 ) {
if ( V_1 -> V_5 -> V_15 ( V_1 -> V_3 , V_1 ) ) {
F_9 ( V_1 ) ;
V_12 = 0 ;
goto V_16;
}
if ( V_7 && V_7 -> V_1 != V_1 ) {
F_9 ( V_1 ) ;
V_12 = 0 ;
goto V_16;
}
if ( ! F_14 ( V_1 -> V_3 , NULL , V_17 ) ) {
V_12 = - V_18 ;
goto V_16;
}
V_12 = V_1 -> V_5 -> V_19 ( V_1 -> V_3 ) ;
if ( V_12 < 0 ) {
F_15 ( V_1 -> V_3 , NULL ) ;
F_16 ( V_1 -> V_3 , L_1 , V_12 ) ;
F_9 ( V_1 ) ;
goto V_16;
}
V_1 -> V_14 = true ;
V_12 = 1 ;
}
V_16:
return V_12 ;
}
static int F_17 ( struct V_7 * V_7 )
{
struct V_1 * V_6 ;
int V_12 = 0 ;
F_2 (m, &masters, node) {
V_12 = F_13 ( V_6 , V_7 ) ;
if ( V_12 != 0 )
break;
}
return V_12 ;
}
static void F_18 ( struct V_1 * V_1 )
{
if ( V_1 -> V_14 ) {
V_1 -> V_5 -> V_20 ( V_1 -> V_3 ) ;
F_15 ( V_1 -> V_3 , NULL ) ;
V_1 -> V_14 = false ;
}
F_9 ( V_1 ) ;
}
int F_19 ( struct V_2 * V_3 ,
const struct V_4 * V_5 )
{
struct V_1 * V_1 ;
int V_12 ;
V_1 = F_20 ( sizeof( * V_1 ) , V_17 ) ;
if ( ! V_1 )
return - V_18 ;
V_1 -> V_3 = V_3 ;
V_1 -> V_5 = V_5 ;
F_21 ( & V_1 -> V_10 ) ;
F_22 ( & V_21 ) ;
F_23 ( & V_1 -> V_22 , & V_23 ) ;
V_12 = F_13 ( V_1 , NULL ) ;
if ( V_12 < 0 ) {
F_6 ( & V_1 -> V_22 ) ;
F_24 ( V_1 ) ;
}
F_25 ( & V_21 ) ;
return V_12 < 0 ? V_12 : 0 ;
}
void F_26 ( struct V_2 * V_3 ,
const struct V_4 * V_5 )
{
struct V_1 * V_1 ;
F_22 ( & V_21 ) ;
V_1 = F_1 ( V_3 , V_5 ) ;
if ( V_1 ) {
F_18 ( V_1 ) ;
F_6 ( & V_1 -> V_22 ) ;
F_24 ( V_1 ) ;
}
F_25 ( & V_21 ) ;
}
static void F_27 ( struct V_7 * V_7 ,
struct V_1 * V_1 , void * V_24 )
{
F_12 ( ! V_7 -> V_14 ) ;
V_7 -> V_5 -> V_20 ( V_7 -> V_3 , V_1 -> V_3 , V_24 ) ;
V_7 -> V_14 = false ;
F_15 ( V_7 -> V_3 , V_7 ) ;
}
void F_28 ( struct V_2 * V_25 , void * V_24 )
{
struct V_1 * V_1 ;
struct V_7 * V_8 ;
F_12 ( ! F_29 ( & V_21 ) ) ;
V_1 = F_1 ( V_25 , NULL ) ;
if ( ! V_1 )
return;
F_30 (c, &master->components, master_node)
F_27 ( V_8 , V_1 , V_24 ) ;
}
static int F_31 ( struct V_7 * V_7 , struct V_1 * V_1 ,
void * V_24 )
{
int V_12 ;
if ( ! F_14 ( V_1 -> V_3 , NULL , V_17 ) )
return - V_18 ;
if ( ! F_14 ( V_7 -> V_3 , V_7 , V_17 ) ) {
F_15 ( V_1 -> V_3 , NULL ) ;
return - V_18 ;
}
F_32 ( V_1 -> V_3 , L_2 ,
F_33 ( V_7 -> V_3 ) , V_7 -> V_5 ) ;
V_12 = V_7 -> V_5 -> V_19 ( V_7 -> V_3 , V_1 -> V_3 , V_24 ) ;
if ( ! V_12 ) {
V_7 -> V_14 = true ;
F_34 ( V_7 -> V_3 , NULL ) ;
F_35 ( V_1 -> V_3 , NULL ) ;
F_16 ( V_1 -> V_3 , L_3 ,
F_33 ( V_7 -> V_3 ) , V_7 -> V_5 ) ;
} else {
F_15 ( V_7 -> V_3 , NULL ) ;
F_15 ( V_1 -> V_3 , NULL ) ;
F_36 ( V_1 -> V_3 , L_4 ,
F_33 ( V_7 -> V_3 ) , V_7 -> V_5 , V_12 ) ;
}
return V_12 ;
}
int F_37 ( struct V_2 * V_25 , void * V_24 )
{
struct V_1 * V_1 ;
struct V_7 * V_8 ;
int V_12 = 0 ;
F_12 ( ! F_29 ( & V_21 ) ) ;
V_1 = F_1 ( V_25 , NULL ) ;
if ( ! V_1 )
return - V_26 ;
F_2 (c, &master->components, master_node) {
V_12 = F_31 ( V_8 , V_1 , V_24 ) ;
if ( V_12 )
break;
}
if ( V_12 != 0 ) {
F_38 (c, &master->components,
master_node)
F_27 ( V_8 , V_1 , V_24 ) ;
}
return V_12 ;
}
int F_39 ( struct V_2 * V_3 , const struct V_27 * V_5 )
{
struct V_7 * V_7 ;
int V_12 ;
V_7 = F_20 ( sizeof( * V_7 ) , V_17 ) ;
if ( ! V_7 )
return - V_18 ;
V_7 -> V_5 = V_5 ;
V_7 -> V_3 = V_3 ;
F_32 ( V_3 , L_5 , V_5 ) ;
F_22 ( & V_21 ) ;
F_4 ( & V_7 -> V_22 , & V_28 ) ;
V_12 = F_17 ( V_7 ) ;
if ( V_12 < 0 ) {
F_6 ( & V_7 -> V_22 ) ;
F_24 ( V_7 ) ;
}
F_25 ( & V_21 ) ;
return V_12 < 0 ? V_12 : 0 ;
}
void F_40 ( struct V_2 * V_3 , const struct V_27 * V_5 )
{
struct V_7 * V_8 , * V_7 = NULL ;
F_22 ( & V_21 ) ;
F_2 (c, &component_list, node)
if ( V_8 -> V_3 == V_3 && V_8 -> V_5 == V_5 ) {
F_6 ( & V_8 -> V_22 ) ;
V_7 = V_8 ;
break;
}
if ( V_7 && V_7 -> V_1 )
F_18 ( V_7 -> V_1 ) ;
F_25 ( & V_21 ) ;
F_12 ( ! V_7 ) ;
F_24 ( V_7 ) ;
}
