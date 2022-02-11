STATIC unsigned long
F_1 (
struct V_1 * V_2 ,
unsigned long V_3 )
{
unsigned int V_4 ;
unsigned int V_5 = 0 ;
struct V_6 * V_7 ;
if ( ! V_2 -> V_8 )
return 0 ;
while ( V_2 -> V_8 <= V_3 - V_2 -> V_9 * V_2 -> V_10 ) {
V_7 = V_2 -> V_11 + V_2 -> V_12 ;
if ( ! F_2 ( V_7 ) )
F_3 ( V_7 , V_2 -> V_13 . V_14 ) ;
V_2 -> V_12 = ( V_2 -> V_12 + 1 ) % V_2 -> V_9 ;
V_2 -> V_8 += V_2 -> V_10 ;
if ( ++ V_5 == V_2 -> V_9 ) {
V_2 -> V_12 = 0 ;
V_2 -> V_8 = 0 ;
return 0 ;
}
}
for ( V_4 = 0 ; V_4 < V_2 -> V_9 ; V_4 ++ ) {
V_7 = V_2 -> V_11 + ( ( V_2 -> V_12 + V_4 ) % V_2 -> V_9 ) ;
if ( ! F_2 ( V_7 ) )
return V_2 -> V_8 +
( V_2 -> V_9 + V_4 ) * V_2 -> V_10 ;
}
V_2 -> V_12 = 0 ;
V_2 -> V_8 = 0 ;
return 0 ;
}
STATIC void
F_4 (
struct V_1 * V_2 ,
struct V_15 * V_16 )
{
unsigned int V_4 = 0 ;
unsigned long V_3 = V_17 ;
if ( ! F_1 ( V_2 , V_3 ) ) {
V_2 -> V_8 = V_3 ;
if ( ! V_2 -> V_18 ) {
V_2 -> V_18 = 1 ;
F_5 ( V_19 , & V_2 -> V_20 ,
V_2 -> V_9 * V_2 -> V_10 ) ;
}
} else {
V_4 = ( V_3 - V_2 -> V_8 ) / V_2 -> V_10 ;
V_4 = ( V_2 -> V_12 + V_4 ) % V_2 -> V_9 ;
}
F_6 ( & V_16 -> V_21 , V_2 -> V_11 + V_4 ) ;
}
STATIC void
F_7 (
struct V_1 * V_2 )
__releases( V_2 -> V_22 ) __acquires( V_2 -> V_22 )
{
struct V_15 * V_16 , * V_23 ;
struct V_6 V_24 ;
F_8 ( & V_24 ) ;
F_9 (elem, next, &mru->reap_list, list_node) {
F_10 ( & V_2 -> V_25 , V_16 -> V_26 ) ;
F_11 ( & V_16 -> V_21 , & V_24 ) ;
}
F_12 ( & V_2 -> V_22 ) ;
F_9 (elem, next, &tmp, list_node) {
F_13 ( & V_16 -> V_21 ) ;
V_2 -> V_27 ( V_16 ) ;
}
F_14 ( & V_2 -> V_22 ) ;
}
STATIC void
F_15 (
struct V_28 * V_20 )
{
struct V_1 * V_2 =
F_16 ( V_20 , struct V_1 , V_20 . V_20 ) ;
unsigned long V_3 , V_23 ;
ASSERT ( V_2 && V_2 -> V_11 ) ;
if ( ! V_2 || ! V_2 -> V_11 )
return;
F_14 ( & V_2 -> V_22 ) ;
V_23 = F_1 ( V_2 , V_17 ) ;
F_7 ( V_2 ) ;
V_2 -> V_18 = V_23 ;
if ( ( V_2 -> V_18 > 0 ) ) {
V_3 = V_17 ;
if ( V_23 <= V_3 )
V_23 = 0 ;
else
V_23 -= V_3 ;
F_5 ( V_19 , & V_2 -> V_20 , V_23 ) ;
}
F_12 ( & V_2 -> V_22 ) ;
}
int
F_17 ( void )
{
V_19 = F_18 ( L_1 , V_29 , 1 ) ;
if ( ! V_19 )
return - V_30 ;
return 0 ;
}
void
F_19 ( void )
{
F_20 ( V_19 ) ;
}
int
F_21 (
struct V_1 * * V_31 ,
unsigned int V_32 ,
unsigned int V_9 ,
T_1 V_27 )
{
struct V_1 * V_2 = NULL ;
int V_33 = 0 , V_4 ;
unsigned int V_10 ;
if ( V_31 )
* V_31 = NULL ;
if ( ! V_31 || ! V_9 || ! V_32 || ! V_27 )
return - V_34 ;
if ( ! ( V_10 = F_22 ( V_32 ) / V_9 ) )
return - V_34 ;
if ( ! ( V_2 = F_23 ( sizeof( * V_2 ) , V_35 ) ) )
return - V_30 ;
V_2 -> V_9 = V_9 + 1 ;
V_2 -> V_11 = F_23 ( V_2 -> V_9 * sizeof( * V_2 -> V_11 ) , V_35 ) ;
if ( ! V_2 -> V_11 ) {
V_33 = - V_30 ;
goto exit;
}
for ( V_4 = 0 ; V_4 < V_2 -> V_9 ; V_4 ++ )
F_8 ( V_2 -> V_11 + V_4 ) ;
F_24 ( & V_2 -> V_25 , V_36 ) ;
F_8 ( & V_2 -> V_13 ) ;
F_25 ( & V_2 -> V_22 ) ;
F_26 ( & V_2 -> V_20 , F_15 ) ;
V_2 -> V_10 = V_10 ;
V_2 -> V_27 = V_27 ;
* V_31 = V_2 ;
exit:
if ( V_33 && V_2 && V_2 -> V_11 )
F_27 ( V_2 -> V_11 ) ;
if ( V_33 && V_2 )
F_27 ( V_2 ) ;
return V_33 ;
}
static void
F_28 (
struct V_1 * V_2 )
{
if ( ! V_2 || ! V_2 -> V_11 )
return;
F_14 ( & V_2 -> V_22 ) ;
if ( V_2 -> V_18 ) {
F_12 ( & V_2 -> V_22 ) ;
F_29 ( & V_2 -> V_20 ) ;
F_14 ( & V_2 -> V_22 ) ;
}
F_1 ( V_2 , V_17 + V_2 -> V_9 * V_2 -> V_10 ) ;
F_7 ( V_2 ) ;
F_12 ( & V_2 -> V_22 ) ;
}
void
F_30 (
struct V_1 * V_2 )
{
if ( ! V_2 || ! V_2 -> V_11 )
return;
F_28 ( V_2 ) ;
F_27 ( V_2 -> V_11 ) ;
F_27 ( V_2 ) ;
}
int
F_31 (
struct V_1 * V_2 ,
unsigned long V_26 ,
struct V_15 * V_16 )
{
int error ;
ASSERT ( V_2 && V_2 -> V_11 ) ;
if ( ! V_2 || ! V_2 -> V_11 )
return - V_34 ;
if ( F_32 ( V_37 ) )
return - V_30 ;
F_8 ( & V_16 -> V_21 ) ;
V_16 -> V_26 = V_26 ;
F_14 ( & V_2 -> V_22 ) ;
error = F_33 ( & V_2 -> V_25 , V_26 , V_16 ) ;
F_34 () ;
if ( ! error )
F_4 ( V_2 , V_16 ) ;
F_12 ( & V_2 -> V_22 ) ;
return error ;
}
struct V_15 *
F_35 (
struct V_1 * V_2 ,
unsigned long V_26 )
{
struct V_15 * V_16 ;
ASSERT ( V_2 && V_2 -> V_11 ) ;
if ( ! V_2 || ! V_2 -> V_11 )
return NULL ;
F_14 ( & V_2 -> V_22 ) ;
V_16 = F_10 ( & V_2 -> V_25 , V_26 ) ;
if ( V_16 )
F_36 ( & V_16 -> V_21 ) ;
F_12 ( & V_2 -> V_22 ) ;
return V_16 ;
}
void
F_37 (
struct V_1 * V_2 ,
unsigned long V_26 )
{
struct V_15 * V_16 ;
V_16 = F_35 ( V_2 , V_26 ) ;
if ( V_16 )
V_2 -> V_27 ( V_16 ) ;
}
struct V_15 *
F_38 (
struct V_1 * V_2 ,
unsigned long V_26 )
{
struct V_15 * V_16 ;
ASSERT ( V_2 && V_2 -> V_11 ) ;
if ( ! V_2 || ! V_2 -> V_11 )
return NULL ;
F_14 ( & V_2 -> V_22 ) ;
V_16 = F_39 ( & V_2 -> V_25 , V_26 ) ;
if ( V_16 ) {
F_36 ( & V_16 -> V_21 ) ;
F_4 ( V_2 , V_16 ) ;
F_40 ( V_38 ) ;
} else
F_12 ( & V_2 -> V_22 ) ;
return V_16 ;
}
void
F_41 (
struct V_1 * V_2 )
__releases( V_2 -> V_22 )
{
F_12 ( & V_2 -> V_22 ) ;
}
