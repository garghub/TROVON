void F_1 ( struct V_1 * V_2 )
{
F_2 ( & V_2 -> V_3 ) ;
F_2 ( & V_2 -> V_4 ) ;
F_3 ( V_2 -> V_5 ) ;
}
int
F_4 ( struct V_1 * V_2 , unsigned int V_6 ,
unsigned int V_7 , unsigned int V_8 )
{
int V_9 = 0 ;
V_2 -> V_5 = F_5 ( V_6 , sizeof( * V_2 -> V_5 ) , V_10 ) ;
if ( ! V_2 -> V_5 ) {
V_9 = - V_11 ;
goto V_12;
}
V_2 -> V_6 = V_6 ;
F_6 ( & V_2 -> V_13 ) ;
V_9 = F_7 ( & V_2 -> V_4 , V_8 ) ;
if ( V_9 )
goto V_14;
V_9 = F_7 ( & V_2 -> V_3 , V_7 ) ;
if ( ! V_9 )
goto V_12;
F_2 ( & V_2 -> V_4 ) ;
V_14:
F_3 ( V_2 -> V_5 ) ;
V_12:
return V_9 ;
}
static void * F_8 ( void * V_15 , unsigned long V_16 ,
unsigned V_17 )
{
struct V_18 * V_5 = (struct V_18 * ) V_15 ;
struct V_19 * V_20 ;
V_20 = F_9 ( V_5 , V_16 , V_17 , 1 ) ;
if ( ! V_20 ) {
return NULL ;
}
V_20 = F_10 ( V_20 , V_16 , V_17 ) ;
return V_20 ;
}
static void F_11 ( void * V_15 , void * V_21 )
{
struct V_19 * V_22 = (struct V_19 * ) V_21 ;
F_12 ( V_22 ) ;
}
static void F_13 ( void * V_15 )
{
struct V_18 * V_5 = (struct V_18 * ) V_15 ;
F_14 ( V_5 ) ;
F_3 ( V_5 ) ;
}
static unsigned long F_15 ( void * V_15 , void * V_21 )
{
struct V_19 * V_22 = (struct V_19 * ) V_21 ;
return V_22 -> V_23 ;
}
int
F_16 ( struct V_1 * V_2 , unsigned int V_24 ,
unsigned long V_23 , unsigned long V_16 )
{
struct V_25 * V_26 ;
struct V_18 * V_5 ;
int V_9 ;
F_17 ( V_24 >= V_2 -> V_6 ) ;
V_26 = & V_2 -> V_5 [ V_24 ] ;
V_5 = F_18 ( sizeof( * V_5 ) , V_10 ) ;
if ( ! V_5 ) {
return - V_11 ;
}
V_26 -> V_15 = V_5 ;
V_9 = F_19 ( V_5 , V_23 , V_16 ) ;
if ( V_9 ) {
F_3 ( V_5 ) ;
return V_9 ;
}
V_26 -> V_27 = F_8 ;
V_26 -> free = F_11 ;
V_26 -> V_28 = F_13 ;
V_26 -> V_29 = F_15 ;
return 0 ;
}
int
F_20 ( struct V_1 * V_2 , unsigned int V_24 ,
struct V_25 * V_30 )
{
F_17 ( V_24 >= V_2 -> V_6 ) ;
V_2 -> V_5 [ V_24 ] = * V_30 ;
return 0 ;
}
static struct V_31 * F_21 ( struct V_1 * V_2 ,
unsigned long V_32 )
{
int V_9 ;
struct V_33 * V_34 ;
struct V_31 * V_35 ;
V_9 = F_22 ( & V_2 -> V_4 , V_32 , & V_34 ) ;
if ( ! V_9 ) {
return F_23 ( V_34 , struct V_31 ,
V_36 ) ;
}
V_35 = F_18 ( sizeof( * V_35 ) , V_10 ) ;
if ( ! V_35 )
goto V_12;
F_6 ( & V_35 -> V_37 ) ;
V_35 -> V_36 . V_38 = V_32 ;
if ( F_24 ( & V_2 -> V_4 , & V_35 -> V_36 ) )
goto V_14;
F_25 ( & V_35 -> V_39 , & V_2 -> V_13 ) ;
return V_35 ;
V_14:
F_3 ( V_35 ) ;
V_12:
return NULL ;
}
struct V_40 * F_26 ( struct V_1 * V_2 , unsigned int V_24 ,
unsigned long V_16 , unsigned V_17 ,
unsigned long V_32 )
{
void * V_20 ;
struct V_25 * V_26 ;
struct V_31 * V_35 ;
struct V_40 * V_41 ;
F_17 ( V_24 >= V_2 -> V_6 ) ;
V_26 = & V_2 -> V_5 [ V_24 ] ;
V_20 = V_26 -> V_27 ( V_26 -> V_15 , V_16 , V_17 ) ;
if ( ! V_20 ) {
return NULL ;
}
V_41 = F_18 ( sizeof( * V_41 ) , V_10 ) ;
if ( ! V_41 )
goto V_12;
V_41 -> V_42 = V_20 ;
V_41 -> V_5 = V_26 ;
V_41 -> V_2 = V_2 ;
if ( F_27
( & V_2 -> V_3 , & V_41 -> V_43 ,
( unsigned long ) V_41 , 32 , 0 , 0 ) )
goto V_14;
V_35 = F_21 ( V_2 , V_32 ) ;
if ( ! V_35 )
goto V_44;
F_25 ( & V_41 -> V_45 , & V_35 -> V_37 ) ;
return V_41 ;
V_44:
F_28 ( & V_2 -> V_3 , & V_41 -> V_43 ) ;
V_14:
F_3 ( V_41 ) ;
V_12:
V_26 -> free ( V_26 -> V_15 , V_20 ) ;
return NULL ;
}
static void F_29 ( struct V_40 * V_46 )
{
struct V_1 * V_2 = V_46 -> V_2 ;
F_30 ( & V_46 -> V_45 ) ;
F_28 ( & V_2 -> V_3 , & V_46 -> V_43 ) ;
V_46 -> V_5 -> free ( V_46 -> V_5 -> V_15 , V_46 -> V_42 ) ;
F_3 ( V_46 ) ;
}
int F_31 ( struct V_1 * V_2 , unsigned int V_38 )
{
struct V_33 * V_47 ;
struct V_40 * V_48 ;
if ( F_22 ( & V_2 -> V_3 , V_38 , & V_47 ) )
return - V_49 ;
V_48 = F_23 ( V_47 , struct V_40 ,
V_43 ) ;
F_29 ( V_48 ) ;
return 0 ;
}
static void F_32 ( struct V_1 * V_2 ,
struct V_31 * V_35 )
{
F_30 ( & V_35 -> V_39 ) ;
F_28 ( & V_2 -> V_4 , & V_35 -> V_36 ) ;
F_3 ( V_35 ) ;
}
int F_33 ( struct V_1 * V_2 , unsigned long V_32 )
{
struct V_33 * V_47 ;
struct V_31 * V_35 ;
if ( F_22 ( & V_2 -> V_4 , V_32 , & V_47 ) ) {
return - 1 ;
}
V_35 = F_23 ( V_47 , struct V_31 , V_36 ) ;
if ( V_35 -> V_37 . V_50 == & V_35 -> V_37 ) {
F_32 ( V_2 , V_35 ) ;
return - 1 ;
}
return 0 ;
}
static void F_34 ( struct V_1 * V_2 ,
struct V_31 * V_35 )
{
struct V_40 * V_51 , * V_50 ;
F_35 (entry, next, &owner_item->mem_blocks,
owner_list) {
F_29 ( V_51 ) ;
}
F_32 ( V_2 , V_35 ) ;
}
void F_36 ( struct V_1 * V_2 , unsigned long V_32 )
{
struct V_33 * V_47 ;
struct V_31 * V_35 ;
if ( F_22 ( & V_2 -> V_4 , V_32 , & V_47 ) ) {
return;
}
V_35 = F_23 ( V_47 , struct V_31 , V_36 ) ;
F_34 ( V_2 , V_35 ) ;
}
void F_37 ( struct V_1 * V_2 )
{
struct V_31 * V_51 , * V_50 ;
unsigned int V_52 ;
struct V_25 * V_26 ;
F_35 (entry, next, &sman->owner_items, sman_list) {
F_34 ( V_2 , V_51 ) ;
}
if ( V_2 -> V_5 ) {
for ( V_52 = 0 ; V_52 < V_2 -> V_6 ; ++ V_52 ) {
V_26 = & V_2 -> V_5 [ V_52 ] ;
if ( V_26 -> V_15 ) {
V_26 -> V_28 ( V_26 -> V_15 ) ;
V_26 -> V_15 = NULL ;
}
}
}
}
