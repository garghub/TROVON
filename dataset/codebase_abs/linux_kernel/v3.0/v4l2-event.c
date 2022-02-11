int F_1 ( struct V_1 * V_2 )
{
V_2 -> V_3 = F_2 ( sizeof( * V_2 -> V_3 ) , V_4 ) ;
if ( V_2 -> V_3 == NULL )
return - V_5 ;
F_3 ( & V_2 -> V_3 -> V_6 ) ;
F_4 ( & V_2 -> V_3 -> free ) ;
F_4 ( & V_2 -> V_3 -> V_7 ) ;
F_4 ( & V_2 -> V_3 -> V_8 ) ;
V_2 -> V_3 -> V_9 = - 1 ;
return 0 ;
}
int F_5 ( struct V_1 * V_2 , unsigned int V_10 )
{
struct V_11 * V_3 = V_2 -> V_3 ;
unsigned long V_12 ;
if ( ! V_3 ) {
F_6 ( 1 ) ;
return - V_5 ;
}
while ( V_3 -> V_13 < V_10 ) {
struct V_14 * V_15 ;
V_15 = F_2 ( sizeof( * V_15 ) , V_4 ) ;
if ( V_15 == NULL )
return - V_5 ;
F_7 ( & V_2 -> V_16 -> V_17 , V_12 ) ;
F_8 ( & V_15 -> V_18 , & V_3 -> free ) ;
V_3 -> V_13 ++ ;
F_9 ( & V_2 -> V_16 -> V_17 , V_12 ) ;
}
return 0 ;
}
void F_10 ( struct V_1 * V_2 )
{
struct V_11 * V_3 = V_2 -> V_3 ;
if ( ! V_3 )
return;
F_11 ( & V_3 -> free , struct V_14 , V_18 ) ;
F_11 ( & V_3 -> V_7 , struct V_14 , V_18 ) ;
F_11 ( & V_3 -> V_8 , struct V_19 , V_18 ) ;
F_12 ( V_3 ) ;
V_2 -> V_3 = NULL ;
}
static int F_13 ( struct V_1 * V_2 , struct V_20 * V_21 )
{
struct V_11 * V_3 = V_2 -> V_3 ;
struct V_14 * V_15 ;
unsigned long V_12 ;
F_7 ( & V_2 -> V_16 -> V_17 , V_12 ) ;
if ( F_14 ( & V_3 -> V_7 ) ) {
F_9 ( & V_2 -> V_16 -> V_17 , V_12 ) ;
return - V_22 ;
}
F_6 ( V_3 -> V_23 == 0 ) ;
V_15 = F_15 ( & V_3 -> V_7 , struct V_14 , V_18 ) ;
F_16 ( & V_15 -> V_18 , & V_3 -> free ) ;
V_3 -> V_23 -- ;
V_15 -> V_21 . V_24 = V_3 -> V_23 ;
* V_21 = V_15 -> V_21 ;
F_9 ( & V_2 -> V_16 -> V_17 , V_12 ) ;
return 0 ;
}
int F_17 ( struct V_1 * V_2 , struct V_20 * V_21 ,
int V_25 )
{
struct V_11 * V_3 = V_2 -> V_3 ;
int V_26 ;
if ( V_25 )
return F_13 ( V_2 , V_21 ) ;
if ( V_2 -> V_16 -> V_27 )
F_18 ( V_2 -> V_16 -> V_27 ) ;
do {
V_26 = F_19 ( V_3 -> V_6 ,
V_3 -> V_23 != 0 ) ;
if ( V_26 < 0 )
break;
V_26 = F_13 ( V_2 , V_21 ) ;
} while ( V_26 == - V_22 );
if ( V_2 -> V_16 -> V_27 )
F_20 ( V_2 -> V_16 -> V_27 ) ;
return V_26 ;
}
static struct V_19 * F_21 (
struct V_1 * V_2 , T_1 type )
{
struct V_11 * V_3 = V_2 -> V_3 ;
struct V_19 * V_28 ;
F_22 ( & V_2 -> V_16 -> V_17 ) ;
F_23 (sev, &events->subscribed, list) {
if ( V_28 -> type == type )
return V_28 ;
}
return NULL ;
}
void F_24 ( struct V_29 * V_16 , const struct V_20 * V_30 )
{
struct V_1 * V_2 ;
unsigned long V_12 ;
struct V_31 V_32 ;
F_25 ( & V_32 ) ;
F_7 ( & V_16 -> V_17 , V_12 ) ;
F_23 (fh, &vdev->fh_list, list) {
struct V_11 * V_3 = V_2 -> V_3 ;
struct V_14 * V_15 ;
if ( ! F_21 ( V_2 , V_30 -> type ) )
continue;
V_3 -> V_9 ++ ;
if ( F_14 ( & V_3 -> free ) )
continue;
V_15 = F_15 ( & V_3 -> free , struct V_14 , V_18 ) ;
V_15 -> V_21 . type = V_30 -> type ;
V_15 -> V_21 . V_33 = V_30 -> V_33 ;
V_15 -> V_21 . V_32 = V_32 ;
V_15 -> V_21 . V_9 = V_3 -> V_9 ;
F_26 ( & V_15 -> V_18 , & V_3 -> V_7 ) ;
V_3 -> V_23 ++ ;
F_27 ( & V_3 -> V_6 ) ;
}
F_9 ( & V_16 -> V_17 , V_12 ) ;
}
int F_28 ( struct V_1 * V_2 )
{
return V_2 -> V_3 -> V_23 ;
}
int F_29 ( struct V_1 * V_2 ,
struct V_34 * V_35 )
{
struct V_11 * V_3 = V_2 -> V_3 ;
struct V_19 * V_28 ;
unsigned long V_12 ;
if ( V_2 -> V_3 == NULL ) {
F_6 ( 1 ) ;
return - V_5 ;
}
V_28 = F_30 ( sizeof( * V_28 ) , V_4 ) ;
if ( ! V_28 )
return - V_5 ;
F_7 ( & V_2 -> V_16 -> V_17 , V_12 ) ;
if ( F_21 ( V_2 , V_35 -> type ) == NULL ) {
F_4 ( & V_28 -> V_18 ) ;
V_28 -> type = V_35 -> type ;
F_31 ( & V_28 -> V_18 , & V_3 -> V_8 ) ;
V_28 = NULL ;
}
F_9 ( & V_2 -> V_16 -> V_17 , V_12 ) ;
F_12 ( V_28 ) ;
return 0 ;
}
static void F_32 ( struct V_1 * V_2 )
{
struct V_11 * V_3 = V_2 -> V_3 ;
struct V_19 * V_28 ;
unsigned long V_12 ;
do {
V_28 = NULL ;
F_7 ( & V_2 -> V_16 -> V_17 , V_12 ) ;
if ( ! F_14 ( & V_3 -> V_8 ) ) {
V_28 = F_15 ( & V_3 -> V_8 ,
struct V_19 , V_18 ) ;
F_33 ( & V_28 -> V_18 ) ;
}
F_9 ( & V_2 -> V_16 -> V_17 , V_12 ) ;
F_12 ( V_28 ) ;
} while ( V_28 );
}
int F_34 ( struct V_1 * V_2 ,
struct V_34 * V_35 )
{
struct V_19 * V_28 ;
unsigned long V_12 ;
if ( V_35 -> type == V_36 ) {
F_32 ( V_2 ) ;
return 0 ;
}
F_7 ( & V_2 -> V_16 -> V_17 , V_12 ) ;
V_28 = F_21 ( V_2 , V_35 -> type ) ;
if ( V_28 != NULL )
F_33 ( & V_28 -> V_18 ) ;
F_9 ( & V_2 -> V_16 -> V_17 , V_12 ) ;
F_12 ( V_28 ) ;
return 0 ;
}
