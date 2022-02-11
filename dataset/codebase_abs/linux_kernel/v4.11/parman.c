static int F_1 ( struct V_1 * V_1 )
{
unsigned long V_2 = V_1 -> V_3 +
V_1 -> V_4 -> V_5 ;
int V_6 ;
V_6 = V_1 -> V_4 -> V_7 ( V_1 -> V_8 , V_2 ) ;
if ( V_6 )
return V_6 ;
V_1 -> V_3 = V_2 ;
return 0 ;
}
static int F_2 ( struct V_1 * V_1 )
{
unsigned long V_2 = V_1 -> V_3 -
V_1 -> V_4 -> V_5 ;
int V_6 ;
if ( V_2 < V_1 -> V_4 -> V_9 )
return 0 ;
V_6 = V_1 -> V_4 -> V_7 ( V_1 -> V_8 , V_2 ) ;
if ( V_6 )
return V_6 ;
V_1 -> V_3 = V_2 ;
return 0 ;
}
static bool F_3 ( struct V_10 * V_11 )
{
return ! F_4 ( & V_11 -> V_12 ) ;
}
static struct V_13 * F_5 ( struct V_10 * V_11 )
{
return F_6 ( & V_11 -> V_12 ,
F_7 ( struct V_13 ) , V_14 ) ;
}
static unsigned long F_8 ( struct V_10 * V_11 )
{
return F_5 ( V_11 ) -> V_15 ;
}
static struct V_13 * F_9 ( struct V_10 * V_11 )
{
return F_10 ( & V_11 -> V_12 ,
F_7 ( struct V_13 ) , V_14 ) ;
}
static unsigned long F_11 ( struct V_10 * V_11 )
{
return F_9 ( V_11 ) -> V_15 ;
}
static unsigned long F_12 ( struct V_1 * V_1 ,
struct V_10 * V_11 )
{
F_13 (prio, &parman->prio_list, list) {
if ( ! F_3 ( V_11 ) )
continue;
return F_11 ( V_11 ) + 1 ;
}
return 0 ;
}
static void F_14 ( struct V_1 * V_1 , struct V_10 * V_11 ,
struct V_13 * V_16 , unsigned long V_17 ,
unsigned long V_18 )
{
V_1 -> V_4 -> V_19 ( V_1 -> V_8 , V_16 -> V_15 , V_17 , V_18 ) ;
}
static void F_15 ( struct V_1 * V_1 ,
struct V_10 * V_11 )
{
struct V_13 * V_16 ;
unsigned long V_17 ;
if ( ! F_3 ( V_11 ) )
return;
V_16 = F_5 ( V_11 ) ;
V_17 = F_11 ( V_11 ) + 1 ;
F_14 ( V_1 , V_11 , V_16 , V_17 , 1 ) ;
F_16 ( & V_16 -> V_14 , & V_11 -> V_12 ) ;
V_16 -> V_15 = V_17 ;
}
static void F_17 ( struct V_1 * V_1 ,
struct V_10 * V_11 )
{
struct V_13 * V_16 ;
unsigned long V_17 ;
if ( ! F_3 ( V_11 ) )
return;
V_16 = F_9 ( V_11 ) ;
V_17 = F_8 ( V_11 ) - 1 ;
F_14 ( V_1 , V_11 , V_16 , V_17 , 1 ) ;
F_18 ( & V_16 -> V_14 , & V_11 -> V_12 ) ;
V_16 -> V_15 = V_17 ;
}
static void F_19 ( struct V_1 * V_1 ,
struct V_10 * V_11 ,
struct V_13 * V_16 )
{
struct V_13 * V_20 ;
unsigned long V_17 ;
V_20 = F_9 ( V_11 ) ;
if ( V_20 == V_16 ) {
F_20 ( & V_16 -> V_14 ) ;
return;
}
V_17 = V_16 -> V_15 ;
F_14 ( V_1 , V_11 , V_20 , V_17 , 1 ) ;
F_20 ( & V_20 -> V_14 ) ;
F_21 ( & V_16 -> V_14 , & V_20 -> V_14 ) ;
V_20 -> V_15 = V_17 ;
}
static int F_22 ( struct V_1 * V_1 ,
struct V_10 * V_11 ,
struct V_13 * V_16 )
{
struct V_10 * V_21 ;
unsigned long V_22 ;
int V_6 ;
if ( V_1 -> V_18 + 1 > V_1 -> V_3 ) {
V_6 = F_1 ( V_1 ) ;
if ( V_6 )
return V_6 ;
}
V_22 = F_12 ( V_1 , V_11 ) ;
F_23 (prio2, &parman->prio_list, list) {
if ( V_21 == V_11 )
break;
F_15 ( V_1 , V_21 ) ;
}
V_16 -> V_15 = V_22 ;
F_24 ( & V_16 -> V_14 , & V_11 -> V_12 ) ;
V_1 -> V_18 ++ ;
return 0 ;
}
static void F_25 ( struct V_1 * V_1 ,
struct V_10 * V_11 ,
struct V_13 * V_16 )
{
F_19 ( V_1 , V_11 , V_16 ) ;
F_26 (prio, &parman->prio_list, list)
F_17 ( V_1 , V_11 ) ;
V_1 -> V_18 -- ;
if ( V_1 -> V_3 - V_1 -> V_18 >= V_1 -> V_4 -> V_5 )
F_2 ( V_1 ) ;
}
struct V_1 * F_27 ( const struct V_23 * V_4 , void * V_8 )
{
struct V_1 * V_1 ;
V_1 = F_28 ( sizeof( * V_1 ) , V_24 ) ;
if ( ! V_1 )
return NULL ;
F_29 ( & V_1 -> V_25 ) ;
V_1 -> V_4 = V_4 ;
V_1 -> V_8 = V_8 ;
V_1 -> V_3 = V_4 -> V_9 ;
V_1 -> V_26 = V_27 [ V_4 -> V_26 ] ;
return V_1 ;
}
void F_30 ( struct V_1 * V_1 )
{
F_31 ( ! F_4 ( & V_1 -> V_25 ) ) ;
F_32 ( V_1 ) ;
}
void F_33 ( struct V_1 * V_1 , struct V_10 * V_11 ,
unsigned long V_28 )
{
struct V_10 * V_21 ;
struct V_29 * V_30 ;
F_29 ( & V_11 -> V_12 ) ;
V_11 -> V_28 = V_28 ;
F_34 (pos, &parman->prio_list) {
V_21 = F_35 ( V_30 , F_7 ( * V_21 ) , V_14 ) ;
if ( V_21 -> V_28 > V_11 -> V_28 )
break;
}
F_24 ( & V_11 -> V_14 , V_30 ) ;
}
void F_36 ( struct V_10 * V_11 )
{
F_31 ( F_3 ( V_11 ) ) ;
F_20 ( & V_11 -> V_14 ) ;
}
int F_37 ( struct V_1 * V_1 , struct V_10 * V_11 ,
struct V_13 * V_16 )
{
return V_1 -> V_26 -> V_31 ( V_1 , V_11 , V_16 ) ;
}
void F_38 ( struct V_1 * V_1 , struct V_10 * V_11 ,
struct V_13 * V_16 )
{
V_1 -> V_26 -> V_32 ( V_1 , V_11 , V_16 ) ;
}
