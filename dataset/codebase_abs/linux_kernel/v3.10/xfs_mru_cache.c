STATIC unsigned long
F_1 (
T_1 * V_1 ,
unsigned long V_2 )
{
unsigned int V_3 ;
unsigned int V_4 = 0 ;
struct V_5 * V_6 ;
if ( ! V_1 -> V_7 )
return 0 ;
while ( V_1 -> V_7 <= V_2 - V_1 -> V_8 * V_1 -> V_9 ) {
V_6 = V_1 -> V_10 + V_1 -> V_11 ;
if ( ! F_2 ( V_6 ) )
F_3 ( V_6 , V_1 -> V_12 . V_13 ) ;
V_1 -> V_11 = ( V_1 -> V_11 + 1 ) % V_1 -> V_8 ;
V_1 -> V_7 += V_1 -> V_9 ;
if ( ++ V_4 == V_1 -> V_8 ) {
V_1 -> V_11 = 0 ;
V_1 -> V_7 = 0 ;
return 0 ;
}
}
for ( V_3 = 0 ; V_3 < V_1 -> V_8 ; V_3 ++ ) {
V_6 = V_1 -> V_10 + ( ( V_1 -> V_11 + V_3 ) % V_1 -> V_8 ) ;
if ( ! F_2 ( V_6 ) )
return V_1 -> V_7 +
( V_1 -> V_8 + V_3 ) * V_1 -> V_9 ;
}
V_1 -> V_11 = 0 ;
V_1 -> V_7 = 0 ;
return 0 ;
}
STATIC void
F_4 (
T_1 * V_1 ,
T_2 * V_14 )
{
unsigned int V_3 = 0 ;
unsigned long V_2 = V_15 ;
if ( ! F_1 ( V_1 , V_2 ) ) {
V_1 -> V_7 = V_2 ;
if ( ! V_1 -> V_16 ) {
V_1 -> V_16 = 1 ;
F_5 ( V_17 , & V_1 -> V_18 ,
V_1 -> V_8 * V_1 -> V_9 ) ;
}
} else {
V_3 = ( V_2 - V_1 -> V_7 ) / V_1 -> V_9 ;
V_3 = ( V_1 -> V_11 + V_3 ) % V_1 -> V_8 ;
}
F_6 ( & V_14 -> V_19 , V_1 -> V_10 + V_3 ) ;
}
STATIC void
F_7 (
T_1 * V_1 ) __releases( V_1 -> V_20 ) __acquires( V_1 -> V_20 )
{
T_2 * V_14 , * V_21 ;
struct V_5 V_22 ;
F_8 ( & V_22 ) ;
F_9 (elem, next, &mru->reap_list, list_node) {
F_10 ( & V_1 -> V_23 , V_14 -> V_24 ) ;
F_11 ( & V_14 -> V_19 , & V_22 ) ;
}
F_12 ( & V_1 -> V_20 ) ;
F_9 (elem, next, &tmp, list_node) {
F_13 ( & V_14 -> V_19 ) ;
V_1 -> V_25 ( V_14 -> V_24 , V_14 -> V_26 ) ;
F_14 ( V_27 , V_14 ) ;
}
F_15 ( & V_1 -> V_20 ) ;
}
STATIC void
F_16 (
struct V_28 * V_18 )
{
T_1 * V_1 = F_17 ( V_18 , T_1 , V_18 . V_18 ) ;
unsigned long V_2 , V_21 ;
ASSERT ( V_1 && V_1 -> V_10 ) ;
if ( ! V_1 || ! V_1 -> V_10 )
return;
F_15 ( & V_1 -> V_20 ) ;
V_21 = F_1 ( V_1 , V_15 ) ;
F_7 ( V_1 ) ;
V_1 -> V_16 = V_21 ;
if ( ( V_1 -> V_16 > 0 ) ) {
V_2 = V_15 ;
if ( V_21 <= V_2 )
V_21 = 0 ;
else
V_21 -= V_2 ;
F_5 ( V_17 , & V_1 -> V_18 , V_21 ) ;
}
F_12 ( & V_1 -> V_20 ) ;
}
int
F_18 ( void )
{
V_27 = F_19 ( sizeof( T_2 ) ,
L_1 ) ;
if ( ! V_27 )
goto V_29;
V_17 = F_20 ( L_2 , V_30 , 1 ) ;
if ( ! V_17 )
goto V_31;
return 0 ;
V_31:
F_21 ( V_27 ) ;
V_29:
return - V_32 ;
}
void
F_22 ( void )
{
F_23 ( V_17 ) ;
F_21 ( V_27 ) ;
}
int
F_24 (
T_1 * * V_33 ,
unsigned int V_34 ,
unsigned int V_8 ,
T_3 V_25 )
{
T_1 * V_1 = NULL ;
int V_35 = 0 , V_3 ;
unsigned int V_9 ;
if ( V_33 )
* V_33 = NULL ;
if ( ! V_33 || ! V_8 || ! V_34 || ! V_25 )
return V_36 ;
if ( ! ( V_9 = F_25 ( V_34 ) / V_8 ) )
return V_36 ;
if ( ! ( V_1 = F_26 ( sizeof( * V_1 ) , V_37 ) ) )
return V_32 ;
V_1 -> V_8 = V_8 + 1 ;
V_1 -> V_10 = F_26 ( V_1 -> V_8 * sizeof( * V_1 -> V_10 ) , V_37 ) ;
if ( ! V_1 -> V_10 ) {
V_35 = V_32 ;
goto exit;
}
for ( V_3 = 0 ; V_3 < V_1 -> V_8 ; V_3 ++ )
F_8 ( V_1 -> V_10 + V_3 ) ;
F_27 ( & V_1 -> V_23 , V_38 ) ;
F_8 ( & V_1 -> V_12 ) ;
F_28 ( & V_1 -> V_20 ) ;
F_29 ( & V_1 -> V_18 , F_16 ) ;
V_1 -> V_9 = V_9 ;
V_1 -> V_25 = V_25 ;
* V_33 = V_1 ;
exit:
if ( V_35 && V_1 && V_1 -> V_10 )
F_30 ( V_1 -> V_10 ) ;
if ( V_35 && V_1 )
F_30 ( V_1 ) ;
return V_35 ;
}
static void
F_31 (
T_1 * V_1 )
{
if ( ! V_1 || ! V_1 -> V_10 )
return;
F_15 ( & V_1 -> V_20 ) ;
if ( V_1 -> V_16 ) {
F_12 ( & V_1 -> V_20 ) ;
F_32 ( & V_1 -> V_18 ) ;
F_15 ( & V_1 -> V_20 ) ;
}
F_1 ( V_1 , V_15 + V_1 -> V_8 * V_1 -> V_9 ) ;
F_7 ( V_1 ) ;
F_12 ( & V_1 -> V_20 ) ;
}
void
F_33 (
T_1 * V_1 )
{
if ( ! V_1 || ! V_1 -> V_10 )
return;
F_31 ( V_1 ) ;
F_30 ( V_1 -> V_10 ) ;
F_30 ( V_1 ) ;
}
int
F_34 (
T_1 * V_1 ,
unsigned long V_24 ,
void * V_26 )
{
T_2 * V_14 ;
ASSERT ( V_1 && V_1 -> V_10 ) ;
if ( ! V_1 || ! V_1 -> V_10 )
return V_36 ;
V_14 = F_35 ( V_27 , V_37 ) ;
if ( ! V_14 )
return V_32 ;
if ( F_36 ( V_39 ) ) {
F_14 ( V_27 , V_14 ) ;
return V_32 ;
}
F_8 ( & V_14 -> V_19 ) ;
V_14 -> V_24 = V_24 ;
V_14 -> V_26 = V_26 ;
F_15 ( & V_1 -> V_20 ) ;
F_37 ( & V_1 -> V_23 , V_24 , V_14 ) ;
F_38 () ;
F_4 ( V_1 , V_14 ) ;
F_12 ( & V_1 -> V_20 ) ;
return 0 ;
}
void *
F_39 (
T_1 * V_1 ,
unsigned long V_24 )
{
T_2 * V_14 ;
void * V_26 = NULL ;
ASSERT ( V_1 && V_1 -> V_10 ) ;
if ( ! V_1 || ! V_1 -> V_10 )
return NULL ;
F_15 ( & V_1 -> V_20 ) ;
V_14 = F_10 ( & V_1 -> V_23 , V_24 ) ;
if ( V_14 ) {
V_26 = V_14 -> V_26 ;
F_40 ( & V_14 -> V_19 ) ;
}
F_12 ( & V_1 -> V_20 ) ;
if ( V_14 )
F_14 ( V_27 , V_14 ) ;
return V_26 ;
}
void
F_41 (
T_1 * V_1 ,
unsigned long V_24 )
{
void * V_26 = F_39 ( V_1 , V_24 ) ;
if ( V_26 )
V_1 -> V_25 ( V_24 , V_26 ) ;
}
void *
F_42 (
T_1 * V_1 ,
unsigned long V_24 )
{
T_2 * V_14 ;
ASSERT ( V_1 && V_1 -> V_10 ) ;
if ( ! V_1 || ! V_1 -> V_10 )
return NULL ;
F_15 ( & V_1 -> V_20 ) ;
V_14 = F_43 ( & V_1 -> V_23 , V_24 ) ;
if ( V_14 ) {
F_40 ( & V_14 -> V_19 ) ;
F_4 ( V_1 , V_14 ) ;
F_44 ( V_40 ) ;
} else
F_12 ( & V_1 -> V_20 ) ;
return V_14 ? V_14 -> V_26 : NULL ;
}
void
F_45 (
T_1 * V_1 ) __releases( V_1 -> V_20 )
{
F_12 ( & V_1 -> V_20 ) ;
}
