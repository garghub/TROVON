static struct V_1 * F_1 ( struct V_1 * V_2 , int V_3 , int V_4 ,
struct V_5 * V_6 )
{
if ( V_3 > V_2 -> V_3 ) {
struct V_1 * V_7 = F_2 ( sizeof( * V_7 ) ,
V_8 ) ;
if ( ! V_7 )
goto V_9;
V_7 -> V_3 = V_3 ;
V_7 -> V_4 = V_2 -> V_4 - ( V_3 - V_2 -> V_3 ) ;
V_7 -> V_6 = NULL ;
V_7 -> V_10 = V_2 -> V_10 ;
V_7 -> V_11 = V_2 ;
V_2 -> V_10 -> V_11 = V_7 ;
V_2 -> V_10 = V_7 ;
V_2 -> V_4 -= V_7 -> V_4 ;
V_2 = V_7 ;
}
if ( V_4 < V_2 -> V_4 ) {
struct V_1 * V_7 = F_2 ( sizeof( * V_7 ) ,
V_8 ) ;
if ( ! V_7 )
goto V_9;
V_7 -> V_3 = V_3 + V_4 ;
V_7 -> V_4 = V_2 -> V_4 - V_4 ;
V_7 -> V_6 = NULL ;
V_7 -> V_10 = V_2 -> V_10 ;
V_7 -> V_11 = V_2 ;
V_2 -> V_10 -> V_11 = V_7 ;
V_2 -> V_10 = V_7 ;
V_2 -> V_4 = V_4 ;
}
V_9:
V_2 -> V_6 = V_6 ;
return V_2 ;
}
static struct V_1 * F_3 ( struct V_1 * V_12 , int V_4 ,
int V_13 , struct V_5 * V_6 )
{
struct V_1 * V_2 ;
int V_14 = ( 1 << V_13 ) - 1 ;
F_4 (p, heap) {
int V_3 = ( V_2 -> V_3 + V_14 ) & ~ V_14 ;
if ( V_2 -> V_6 == NULL && V_3 + V_4 <= V_2 -> V_3 + V_2 -> V_4 )
return F_1 ( V_2 , V_3 , V_4 , V_6 ) ;
}
return NULL ;
}
static struct V_1 * F_5 ( struct V_1 * V_12 , int V_3 )
{
struct V_1 * V_2 ;
F_4 (p, heap)
if ( V_2 -> V_3 == V_3 )
return V_2 ;
return NULL ;
}
static void F_6 ( struct V_1 * V_2 )
{
V_2 -> V_6 = NULL ;
if ( V_2 -> V_10 -> V_6 == NULL ) {
struct V_1 * V_15 = V_2 -> V_10 ;
V_2 -> V_4 += V_15 -> V_4 ;
V_2 -> V_10 = V_15 -> V_10 ;
V_2 -> V_10 -> V_11 = V_2 ;
F_7 ( V_15 ) ;
}
if ( V_2 -> V_11 -> V_6 == NULL ) {
struct V_1 * V_15 = V_2 -> V_11 ;
V_15 -> V_4 += V_2 -> V_4 ;
V_15 -> V_10 = V_2 -> V_10 ;
V_15 -> V_10 -> V_11 = V_15 ;
F_7 ( V_2 ) ;
}
}
static int F_8 ( struct V_1 * * V_12 , int V_3 , int V_4 )
{
struct V_1 * V_16 = F_2 ( sizeof( * V_16 ) , V_8 ) ;
if ( ! V_16 )
return - V_17 ;
* V_12 = F_9 ( sizeof( * * V_12 ) , V_8 ) ;
if ( ! * V_12 ) {
F_7 ( V_16 ) ;
return - V_17 ;
}
V_16 -> V_3 = V_3 ;
V_16 -> V_4 = V_4 ;
V_16 -> V_6 = NULL ;
V_16 -> V_10 = V_16 -> V_11 = * V_12 ;
( * V_12 ) -> V_6 = (struct V_5 * ) - 1 ;
( * V_12 ) -> V_10 = ( * V_12 ) -> V_11 = V_16 ;
return 0 ;
}
void F_10 ( struct V_5 * V_6 , struct V_1 * V_12 )
{
struct V_1 * V_2 ;
if ( ! V_12 || ! V_12 -> V_10 )
return;
F_4 (p, heap) {
if ( V_2 -> V_6 == V_6 )
V_2 -> V_6 = NULL ;
}
F_4 (p, heap) {
while ( V_2 -> V_6 == NULL && V_2 -> V_10 -> V_6 == NULL ) {
struct V_1 * V_15 = V_2 -> V_10 ;
V_2 -> V_4 += V_15 -> V_4 ;
V_2 -> V_10 = V_15 -> V_10 ;
V_2 -> V_10 -> V_11 = V_2 ;
F_7 ( V_15 ) ;
}
}
}
void F_11 ( struct V_1 * * V_12 )
{
struct V_1 * V_2 ;
if ( ! * V_12 )
return;
for ( V_2 = ( * V_12 ) -> V_10 ; V_2 != * V_12 ; ) {
struct V_1 * V_15 = V_2 ;
V_2 = V_2 -> V_10 ;
F_7 ( V_15 ) ;
}
F_7 ( * V_12 ) ;
* V_12 = NULL ;
}
static struct V_1 * * F_12 ( T_1 * V_18 , int V_19 )
{
switch ( V_19 ) {
case V_20 :
return & V_18 -> V_21 ;
case V_22 :
return & V_18 -> V_23 ;
default:
return NULL ;
}
}
int F_13 ( struct V_24 * V_25 , void * V_26 , struct V_5 * V_6 )
{
T_1 * V_18 = V_25 -> V_27 ;
T_2 * V_28 = V_26 ;
struct V_1 * V_29 , * * V_12 ;
if ( ! V_18 ) {
F_14 ( L_1 ) ;
return - V_30 ;
}
V_12 = F_12 ( V_18 , V_28 -> V_19 ) ;
if ( ! V_12 || ! * V_12 )
return - V_31 ;
if ( V_28 -> V_32 < 12 )
V_28 -> V_32 = 12 ;
V_29 = F_3 ( * V_12 , V_28 -> V_4 , V_28 -> V_32 , V_6 ) ;
if ( ! V_29 )
return - V_17 ;
if ( F_15 ( V_28 -> V_33 , & V_29 -> V_3 ,
sizeof( int ) ) ) {
F_14 ( L_2 ) ;
return - V_31 ;
}
return 0 ;
}
int F_16 ( struct V_24 * V_25 , void * V_26 , struct V_5 * V_6 )
{
T_1 * V_18 = V_25 -> V_27 ;
T_3 * V_34 = V_26 ;
struct V_1 * V_29 , * * V_12 ;
if ( ! V_18 ) {
F_14 ( L_1 ) ;
return - V_30 ;
}
V_12 = F_12 ( V_18 , V_34 -> V_19 ) ;
if ( ! V_12 || ! * V_12 )
return - V_31 ;
V_29 = F_5 ( * V_12 , V_34 -> V_33 ) ;
if ( ! V_29 )
return - V_31 ;
if ( V_29 -> V_6 != V_6 )
return - V_35 ;
F_6 ( V_29 ) ;
return 0 ;
}
int F_17 ( struct V_24 * V_25 , void * V_26 , struct V_5 * V_6 )
{
T_1 * V_18 = V_25 -> V_27 ;
T_4 * V_36 = V_26 ;
struct V_1 * * V_12 ;
if ( ! V_18 ) {
F_14 ( L_1 ) ;
return - V_30 ;
}
V_12 = F_12 ( V_18 , V_36 -> V_19 ) ;
if ( ! V_12 )
return - V_31 ;
if ( * V_12 ) {
F_14 ( L_3 ) ;
return - V_31 ;
}
return F_8 ( V_12 , V_36 -> V_3 , V_36 -> V_4 ) ;
}
