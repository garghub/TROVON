static struct V_1 *
F_1 ( struct V_2 * V_3 , T_1 V_4 )
{
struct V_1 * V_5 ;
F_2 (handle, &namedb->list, node) {
if ( V_5 -> V_4 == V_4 )
return V_5 ;
}
return NULL ;
}
static struct V_1 *
F_3 ( struct V_2 * V_3 , T_2 V_6 )
{
struct V_1 * V_5 ;
F_2 (handle, &namedb->list, node) {
if ( F_4 ( V_5 -> V_7 ) == V_6 )
return V_5 ;
}
return NULL ;
}
static struct V_1 *
F_5 ( struct V_2 * V_3 , T_3 V_8 )
{
struct V_1 * V_5 ;
F_2 (handle, &namedb->list, node) {
if ( F_6 ( V_5 -> V_7 , V_9 ) ) {
if ( F_7 ( V_5 -> V_7 ) -> V_10 == V_8 )
return V_5 ;
}
}
return NULL ;
}
static struct V_1 *
F_8 ( struct V_2 * V_3 , T_1 V_11 )
{
struct V_1 * V_5 ;
F_2 (handle, &namedb->list, node) {
if ( F_6 ( V_5 -> V_7 , V_9 ) ) {
if ( F_7 ( V_5 -> V_7 ) -> V_12 &&
F_7 ( V_5 -> V_7 ) -> V_12 -> V_13 == V_11 )
return V_5 ;
}
}
return NULL ;
}
int
F_9 ( struct V_2 * V_3 , T_1 V_4 ,
struct V_14 * V_7 ,
struct V_1 * V_5 )
{
int V_15 = - V_16 ;
F_10 ( & V_3 -> V_17 ) ;
if ( ! F_1 ( V_3 , V_4 ) ) {
F_11 ( V_7 , & V_5 -> V_7 ) ;
V_5 -> V_3 = V_3 ;
F_12 ( & V_5 -> V_12 , & V_3 -> V_18 ) ;
V_15 = 0 ;
}
F_13 ( & V_3 -> V_17 ) ;
return V_15 ;
}
void
F_14 ( struct V_1 * V_5 )
{
struct V_2 * V_3 = V_5 -> V_3 ;
struct V_14 * V_7 = V_5 -> V_7 ;
F_10 ( & V_3 -> V_17 ) ;
F_15 ( & V_5 -> V_12 ) ;
F_13 ( & V_3 -> V_17 ) ;
F_11 ( NULL , & V_7 ) ;
}
struct V_1 *
F_16 ( struct V_2 * V_3 , T_1 V_4 )
{
struct V_1 * V_5 ;
F_17 ( & V_3 -> V_17 ) ;
V_5 = F_1 ( V_3 , V_4 ) ;
if ( V_5 == NULL )
F_18 ( & V_3 -> V_17 ) ;
return V_5 ;
}
struct V_1 *
F_19 ( struct V_2 * V_3 , T_2 V_6 )
{
struct V_1 * V_5 ;
F_17 ( & V_3 -> V_17 ) ;
V_5 = F_3 ( V_3 , V_6 ) ;
if ( V_5 == NULL )
F_18 ( & V_3 -> V_17 ) ;
return V_5 ;
}
struct V_1 *
F_20 ( struct V_2 * V_3 , T_3 V_8 )
{
struct V_1 * V_5 ;
F_17 ( & V_3 -> V_17 ) ;
V_5 = F_5 ( V_3 , V_8 ) ;
if ( V_5 == NULL )
F_18 ( & V_3 -> V_17 ) ;
return V_5 ;
}
struct V_1 *
F_21 ( struct V_2 * V_3 , T_1 V_11 )
{
struct V_1 * V_5 ;
F_17 ( & V_3 -> V_17 ) ;
V_5 = F_8 ( V_3 , V_11 ) ;
if ( V_5 == NULL )
F_18 ( & V_3 -> V_17 ) ;
return V_5 ;
}
void
F_22 ( struct V_1 * V_5 )
{
if ( V_5 )
F_18 ( & V_5 -> V_3 -> V_17 ) ;
}
int
F_23 ( struct V_14 * V_19 , struct V_14 * V_20 ,
struct V_21 * V_6 , T_1 V_22 ,
struct V_21 * V_23 , T_3 V_24 ,
int V_25 , void * * V_26 )
{
struct V_2 * V_3 ;
int V_15 ;
V_15 = F_24 ( V_19 , V_20 , V_6 , V_22 |
V_27 , V_23 , V_24 ,
V_25 , V_26 ) ;
V_3 = * V_26 ;
if ( V_15 )
return V_15 ;
F_25 ( & V_3 -> V_17 ) ;
F_26 ( & V_3 -> V_18 ) ;
return 0 ;
}
int
F_27 ( struct V_14 * V_19 , struct V_14 * V_20 ,
struct V_21 * V_6 , void * V_28 , T_1 V_29 ,
struct V_14 * * V_26 )
{
struct V_2 * V_7 ;
int V_15 ;
V_15 = F_28 ( V_19 , V_20 , V_6 , 0 , NULL , 0 , & V_7 ) ;
* V_26 = F_29 ( V_7 ) ;
if ( V_15 )
return V_15 ;
return 0 ;
}
