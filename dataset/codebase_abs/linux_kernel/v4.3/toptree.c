struct V_1 * F_1 ( int V_2 , int V_3 )
{
struct V_1 * V_4 = F_2 ( sizeof( struct V_1 ) , V_5 ) ;
if ( ! V_4 )
return V_4 ;
F_3 ( & V_4 -> V_6 ) ;
F_3 ( & V_4 -> V_7 ) ;
F_4 ( & V_4 -> V_8 ) ;
V_4 -> V_2 = V_2 ;
V_4 -> V_3 = V_3 ;
return V_4 ;
}
static void F_5 ( struct V_1 * V_9 )
{
struct V_1 * V_10 ;
F_6 ( & V_9 -> V_7 ) ;
V_10 = V_9 -> V_11 ;
V_9 -> V_11 = NULL ;
F_7 ( V_10 ) ;
}
void F_8 ( struct V_1 * V_9 )
{
struct V_1 * V_12 , * V_13 ;
if ( V_9 -> V_11 )
F_5 ( V_9 ) ;
F_9 (child, tmp, cand)
F_8 ( V_12 ) ;
F_10 ( V_9 ) ;
}
void F_7 ( struct V_1 * V_9 )
{
struct V_1 * V_12 ;
F_4 ( & V_9 -> V_8 ) ;
F_11 (child, &cand->children, sibling)
F_12 ( & V_9 -> V_8 , & V_9 -> V_8 , & V_12 -> V_8 ) ;
if ( V_9 -> V_11 )
F_7 ( V_9 -> V_11 ) ;
}
static int F_13 ( struct V_1 * V_9 , struct V_1 * V_14 )
{
if ( ! V_9 || ! V_14 )
return - 1 ;
if ( V_14 -> V_2 != ( V_9 -> V_2 + 1 ) )
return - 1 ;
F_14 ( & V_9 -> V_7 , & V_14 -> V_6 ) ;
V_9 -> V_11 = V_14 ;
F_7 ( V_14 ) ;
return 0 ;
}
static void F_15 ( struct V_1 * V_9 , struct V_1 * V_14 )
{
struct V_1 * V_12 , * V_13 ;
F_9 (child, tmp, cand)
F_16 ( V_12 , V_14 ) ;
}
void F_17 ( struct V_1 * V_9 )
{
struct V_1 * V_12 , * V_13 , * V_15 ;
if ( V_9 -> V_2 < 2 )
return;
V_15 = F_1 ( V_9 -> V_2 , 0 ) ;
F_9 (child, tmp, cand) {
struct V_1 * V_16 ;
if ( ! F_18 ( & V_12 -> V_8 ) ) {
V_16 = F_19 ( V_15 , V_12 -> V_3 ) ;
F_15 ( V_12 , V_16 ) ;
}
F_8 ( V_12 ) ;
}
F_15 ( V_15 , V_9 ) ;
F_8 ( V_15 ) ;
F_20 (child, cand)
F_17 ( V_12 ) ;
}
void F_16 ( struct V_1 * V_9 , struct V_1 * V_14 )
{
struct V_1 * V_17 , * V_18 , * V_19 , * V_13 ;
if ( V_9 -> V_2 + 1 == V_14 -> V_2 ) {
F_5 ( V_9 ) ;
F_13 ( V_9 , V_14 ) ;
return;
}
V_18 = NULL ;
V_19 = V_9 ;
V_17 = NULL ;
do {
V_13 = V_17 ;
V_17 = F_1 ( V_19 -> V_2 + 1 ,
V_19 -> V_11 -> V_3 ) ;
F_13 ( V_13 , V_17 ) ;
if ( ! V_18 )
V_18 = V_17 ;
V_19 = V_19 -> V_11 ;
} while ( V_17 -> V_2 < ( V_14 -> V_2 - 1 ) );
F_5 ( V_9 ) ;
F_13 ( V_9 , V_18 ) ;
F_13 ( V_17 , V_14 ) ;
}
struct V_1 * F_19 ( struct V_1 * V_9 , int V_3 )
{
struct V_1 * V_12 ;
F_20 (child, cand)
if ( V_12 -> V_3 == V_3 )
return V_12 ;
V_12 = F_1 ( V_9 -> V_2 - 1 , V_3 ) ;
F_13 ( V_12 , V_9 ) ;
return V_12 ;
}
struct V_1 * F_21 ( struct V_1 * V_20 , int V_2 )
{
struct V_1 * V_12 , * V_13 ;
if ( V_20 -> V_2 == V_2 )
return V_20 ;
if ( ! F_22 ( & V_20 -> V_6 ) ) {
F_11 (child, &context->children, sibling) {
V_13 = F_21 ( V_12 , V_2 ) ;
if ( V_13 )
return V_13 ;
}
}
return NULL ;
}
static struct V_1 * F_23 ( struct V_1 * V_21 )
{
if ( V_21 -> V_11 == NULL )
return NULL ;
if ( V_21 == F_24 ( & V_21 -> V_11 -> V_6 ,
struct V_1 , V_7 ) )
return NULL ;
return (struct V_1 * ) F_25 ( V_21 , V_7 ) ;
}
struct V_1 * F_26 ( struct V_1 * V_21 , struct V_1 * V_20 ,
int V_2 )
{
struct V_1 * V_22 , * V_13 ;
if ( ! V_21 )
return NULL ;
if ( V_20 -> V_2 == V_2 )
return NULL ;
V_13 = F_23 ( V_21 ) ;
if ( V_13 != NULL )
return V_13 ;
V_22 = V_21 ;
while ( V_22 -> V_2 < V_20 -> V_2 - 1 ) {
V_22 = V_22 -> V_11 ;
V_13 = F_23 ( V_22 ) ;
if ( V_13 != NULL ) {
V_13 = F_21 ( V_13 , V_2 ) ;
if ( V_13 != NULL )
return V_13 ;
}
}
return NULL ;
}
int F_27 ( struct V_1 * V_20 , int V_2 )
{
struct V_1 * V_21 ;
int V_23 = 0 ;
F_28 (cur, context, level)
V_23 ++ ;
return V_23 ;
}
