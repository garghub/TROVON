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
if ( V_8 -> V_1 && V_8 -> V_1 != V_1 )
continue;
if ( F_8 ( V_8 -> V_3 , V_11 ) ) {
if ( ! V_8 -> V_1 )
F_3 ( V_1 , V_8 ) ;
V_12 = 0 ;
break;
}
}
return V_12 ;
}
static int F_9 ( struct V_1 * V_1 )
{
struct V_14 * V_15 = V_1 -> V_15 ;
T_1 V_16 ;
int V_12 = 0 ;
if ( ! V_15 ) {
return V_1 -> V_5 -> V_17 ( V_1 -> V_3 , V_1 ) ;
}
for ( V_16 = 0 ; V_16 < V_15 -> V_18 ; V_16 ++ ) {
V_12 = F_7 ( V_1 ,
V_15 -> F_8 [ V_16 ] . V_19 ,
V_15 -> F_8 [ V_16 ] . V_20 ) ;
if ( V_12 )
break;
}
return V_12 ;
}
static void F_10 ( struct V_1 * V_1 )
{
while ( ! F_11 ( & V_1 -> V_10 ) ) {
struct V_7 * V_8 = F_12 ( & V_1 -> V_10 ,
struct V_7 , V_9 ) ;
F_13 ( V_8 -> V_1 != V_1 ) ;
F_5 ( V_1 , V_8 ) ;
}
}
static int F_14 ( struct V_1 * V_1 ,
struct V_7 * V_7 )
{
int V_12 ;
if ( V_1 -> V_21 )
return 0 ;
if ( F_9 ( V_1 ) ) {
V_12 = 0 ;
goto V_22;
}
if ( V_7 && V_7 -> V_1 != V_1 ) {
V_12 = 0 ;
goto V_22;
}
if ( ! F_15 ( V_1 -> V_3 , NULL , V_23 ) ) {
V_12 = - V_24 ;
goto V_22;
}
V_12 = V_1 -> V_5 -> V_25 ( V_1 -> V_3 ) ;
if ( V_12 < 0 ) {
F_16 ( V_1 -> V_3 , NULL ) ;
F_17 ( V_1 -> V_3 , L_1 , V_12 ) ;
goto V_22;
}
V_1 -> V_21 = true ;
return 1 ;
V_22:
F_10 ( V_1 ) ;
return V_12 ;
}
static int F_18 ( struct V_7 * V_7 )
{
struct V_1 * V_6 ;
int V_12 = 0 ;
F_2 (m, &masters, node) {
V_12 = F_14 ( V_6 , V_7 ) ;
if ( V_12 != 0 )
break;
}
return V_12 ;
}
static void F_19 ( struct V_1 * V_1 )
{
if ( V_1 -> V_21 ) {
V_1 -> V_5 -> V_26 ( V_1 -> V_3 ) ;
F_16 ( V_1 -> V_3 , NULL ) ;
V_1 -> V_21 = false ;
}
F_10 ( V_1 ) ;
}
static T_1 F_20 ( T_1 V_18 )
{
return F_21 ( struct V_14 , F_8 [ V_18 ] ) ;
}
static struct V_14 * F_22 ( struct V_2 * V_3 ,
struct V_14 * V_15 , T_1 V_18 )
{
struct V_14 * V_27 ;
if ( V_15 && V_15 -> V_28 == V_18 )
return V_15 ;
V_27 = F_23 ( V_3 , F_20 ( V_18 ) , V_23 ) ;
if ( ! V_27 )
return F_24 ( - V_24 ) ;
if ( V_15 ) {
memcpy ( V_27 , V_15 , F_20 ( F_25 ( V_15 -> V_18 , V_18 ) ) ) ;
F_26 ( V_3 , V_15 ) ;
} else {
V_27 -> V_18 = 0 ;
}
V_27 -> V_28 = V_18 ;
return V_27 ;
}
void F_27 ( struct V_2 * V_3 , struct V_14 * * V_29 ,
int (* F_8)( struct V_2 * , void * ) , void * V_11 )
{
struct V_14 * V_15 = * V_29 ;
if ( F_28 ( V_15 ) )
return;
if ( ! V_15 || V_15 -> V_18 == V_15 -> V_28 ) {
T_1 V_30 = V_15 ? V_15 -> V_28 + 16 : 15 ;
V_15 = F_22 ( V_3 , V_15 , V_30 ) ;
* V_29 = V_15 ;
if ( F_28 ( V_15 ) )
return;
}
V_15 -> F_8 [ V_15 -> V_18 ] . V_19 = F_8 ;
V_15 -> F_8 [ V_15 -> V_18 ] . V_20 = V_11 ;
V_15 -> V_18 ++ ;
}
int F_29 ( struct V_2 * V_3 ,
const struct V_4 * V_5 ,
struct V_14 * V_15 )
{
struct V_1 * V_1 ;
int V_12 ;
if ( V_5 -> V_17 && V_15 )
return - V_31 ;
if ( V_15 ) {
V_15 = F_22 ( V_3 , V_15 , V_15 -> V_18 ) ;
if ( F_28 ( V_15 ) )
return F_30 ( V_15 ) ;
}
V_1 = F_31 ( sizeof( * V_1 ) , V_23 ) ;
if ( ! V_1 )
return - V_24 ;
V_1 -> V_3 = V_3 ;
V_1 -> V_5 = V_5 ;
V_1 -> V_15 = V_15 ;
F_32 ( & V_1 -> V_10 ) ;
F_33 ( & V_32 ) ;
F_34 ( & V_1 -> V_33 , & V_34 ) ;
V_12 = F_14 ( V_1 , NULL ) ;
if ( V_12 < 0 ) {
F_6 ( & V_1 -> V_33 ) ;
F_35 ( V_1 ) ;
}
F_36 ( & V_32 ) ;
return V_12 < 0 ? V_12 : 0 ;
}
int F_37 ( struct V_2 * V_3 ,
const struct V_4 * V_5 )
{
return F_29 ( V_3 , V_5 , NULL ) ;
}
void F_38 ( struct V_2 * V_3 ,
const struct V_4 * V_5 )
{
struct V_1 * V_1 ;
F_33 ( & V_32 ) ;
V_1 = F_1 ( V_3 , V_5 ) ;
if ( V_1 ) {
F_19 ( V_1 ) ;
F_6 ( & V_1 -> V_33 ) ;
F_35 ( V_1 ) ;
}
F_36 ( & V_32 ) ;
}
static void F_39 ( struct V_7 * V_7 ,
struct V_1 * V_1 , void * V_20 )
{
F_13 ( ! V_7 -> V_21 ) ;
V_7 -> V_5 -> V_26 ( V_7 -> V_3 , V_1 -> V_3 , V_20 ) ;
V_7 -> V_21 = false ;
F_16 ( V_7 -> V_3 , V_7 ) ;
}
void F_40 ( struct V_2 * V_35 , void * V_20 )
{
struct V_1 * V_1 ;
struct V_7 * V_8 ;
F_13 ( ! F_41 ( & V_32 ) ) ;
V_1 = F_1 ( V_35 , NULL ) ;
if ( ! V_1 )
return;
F_42 (c, &master->components, master_node)
F_39 ( V_8 , V_1 , V_20 ) ;
}
static int F_43 ( struct V_7 * V_7 , struct V_1 * V_1 ,
void * V_20 )
{
int V_12 ;
if ( ! F_15 ( V_1 -> V_3 , NULL , V_23 ) )
return - V_24 ;
if ( ! F_15 ( V_7 -> V_3 , V_7 , V_23 ) ) {
F_16 ( V_1 -> V_3 , NULL ) ;
return - V_24 ;
}
F_44 ( V_1 -> V_3 , L_2 ,
F_45 ( V_7 -> V_3 ) , V_7 -> V_5 ) ;
V_12 = V_7 -> V_5 -> V_25 ( V_7 -> V_3 , V_1 -> V_3 , V_20 ) ;
if ( ! V_12 ) {
V_7 -> V_21 = true ;
F_46 ( V_7 -> V_3 , NULL ) ;
F_47 ( V_1 -> V_3 , NULL ) ;
F_17 ( V_1 -> V_3 , L_3 ,
F_45 ( V_7 -> V_3 ) , V_7 -> V_5 ) ;
} else {
F_16 ( V_7 -> V_3 , NULL ) ;
F_16 ( V_1 -> V_3 , NULL ) ;
F_48 ( V_1 -> V_3 , L_4 ,
F_45 ( V_7 -> V_3 ) , V_7 -> V_5 , V_12 ) ;
}
return V_12 ;
}
int F_49 ( struct V_2 * V_35 , void * V_20 )
{
struct V_1 * V_1 ;
struct V_7 * V_8 ;
int V_12 = 0 ;
F_13 ( ! F_41 ( & V_32 ) ) ;
V_1 = F_1 ( V_35 , NULL ) ;
if ( ! V_1 )
return - V_31 ;
F_2 (c, &master->components, master_node) {
V_12 = F_43 ( V_8 , V_1 , V_20 ) ;
if ( V_12 )
break;
}
if ( V_12 != 0 ) {
F_50 (c, &master->components,
master_node)
F_39 ( V_8 , V_1 , V_20 ) ;
}
return V_12 ;
}
int F_51 ( struct V_2 * V_3 , const struct V_36 * V_5 )
{
struct V_7 * V_7 ;
int V_12 ;
V_7 = F_31 ( sizeof( * V_7 ) , V_23 ) ;
if ( ! V_7 )
return - V_24 ;
V_7 -> V_5 = V_5 ;
V_7 -> V_3 = V_3 ;
F_44 ( V_3 , L_5 , V_5 ) ;
F_33 ( & V_32 ) ;
F_4 ( & V_7 -> V_33 , & V_37 ) ;
V_12 = F_18 ( V_7 ) ;
if ( V_12 < 0 ) {
F_6 ( & V_7 -> V_33 ) ;
F_35 ( V_7 ) ;
}
F_36 ( & V_32 ) ;
return V_12 < 0 ? V_12 : 0 ;
}
void F_52 ( struct V_2 * V_3 , const struct V_36 * V_5 )
{
struct V_7 * V_8 , * V_7 = NULL ;
F_33 ( & V_32 ) ;
F_2 (c, &component_list, node)
if ( V_8 -> V_3 == V_3 && V_8 -> V_5 == V_5 ) {
F_6 ( & V_8 -> V_33 ) ;
V_7 = V_8 ;
break;
}
if ( V_7 && V_7 -> V_1 )
F_19 ( V_7 -> V_1 ) ;
F_36 ( & V_32 ) ;
F_13 ( ! V_7 ) ;
F_35 ( V_7 ) ;
}
