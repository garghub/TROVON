static void F_1 ( T_1 * V_1 , void * V_2 )
{
F_2 ( V_1 -> V_3 >= V_1 -> V_4 ) ;
V_1 -> V_5 [ V_1 -> V_3 ++ ] = V_2 ;
}
static void * F_3 ( T_1 * V_1 )
{
F_2 ( V_1 -> V_3 <= 0 ) ;
return V_1 -> V_5 [ -- V_1 -> V_3 ] ;
}
void F_4 ( T_1 * V_1 )
{
while ( V_1 -> V_3 ) {
void * V_2 = F_3 ( V_1 ) ;
V_1 -> free ( V_2 , V_1 -> V_6 ) ;
}
F_5 ( V_1 -> V_5 ) ;
F_5 ( V_1 ) ;
}
T_1 * F_6 ( int V_4 , T_2 * V_7 ,
T_3 * V_8 , void * V_6 )
{
return F_7 ( V_4 , V_7 , V_8 , V_6 ,
V_9 , V_10 ) ;
}
T_1 * F_7 ( int V_4 , T_2 * V_7 ,
T_3 * V_8 , void * V_6 ,
T_4 V_11 , int V_12 )
{
T_1 * V_1 ;
V_1 = F_8 ( sizeof( * V_1 ) , V_11 | V_13 , V_12 ) ;
if ( ! V_1 )
return NULL ;
V_1 -> V_5 = F_8 ( V_4 * sizeof( void * ) ,
V_11 , V_12 ) ;
if ( ! V_1 -> V_5 ) {
F_5 ( V_1 ) ;
return NULL ;
}
F_9 ( & V_1 -> V_14 ) ;
V_1 -> V_4 = V_4 ;
V_1 -> V_6 = V_6 ;
F_10 ( & V_1 -> V_15 ) ;
V_1 -> V_16 = V_7 ;
V_1 -> free = V_8 ;
while ( V_1 -> V_3 < V_1 -> V_4 ) {
void * V_2 ;
V_2 = V_1 -> V_16 ( V_11 , V_1 -> V_6 ) ;
if ( F_11 ( ! V_2 ) ) {
F_4 ( V_1 ) ;
return NULL ;
}
F_1 ( V_1 , V_2 ) ;
}
return V_1 ;
}
int F_12 ( T_1 * V_1 , int V_17 , T_4 V_11 )
{
void * V_2 ;
void * * V_18 ;
unsigned long V_19 ;
F_2 ( V_17 <= 0 ) ;
F_13 ( & V_1 -> V_14 , V_19 ) ;
if ( V_17 <= V_1 -> V_4 ) {
while ( V_17 < V_1 -> V_3 ) {
V_2 = F_3 ( V_1 ) ;
F_14 ( & V_1 -> V_14 , V_19 ) ;
V_1 -> free ( V_2 , V_1 -> V_6 ) ;
F_13 ( & V_1 -> V_14 , V_19 ) ;
}
V_1 -> V_4 = V_17 ;
goto V_20;
}
F_14 ( & V_1 -> V_14 , V_19 ) ;
V_18 = F_15 ( V_17 * sizeof( * V_18 ) , V_11 ) ;
if ( ! V_18 )
return - V_21 ;
F_13 ( & V_1 -> V_14 , V_19 ) ;
if ( F_11 ( V_17 <= V_1 -> V_4 ) ) {
F_14 ( & V_1 -> V_14 , V_19 ) ;
F_5 ( V_18 ) ;
goto V_22;
}
memcpy ( V_18 , V_1 -> V_5 ,
V_1 -> V_3 * sizeof( * V_18 ) ) ;
F_5 ( V_1 -> V_5 ) ;
V_1 -> V_5 = V_18 ;
V_1 -> V_4 = V_17 ;
while ( V_1 -> V_3 < V_1 -> V_4 ) {
F_14 ( & V_1 -> V_14 , V_19 ) ;
V_2 = V_1 -> V_16 ( V_11 , V_1 -> V_6 ) ;
if ( ! V_2 )
goto V_22;
F_13 ( & V_1 -> V_14 , V_19 ) ;
if ( V_1 -> V_3 < V_1 -> V_4 ) {
F_1 ( V_1 , V_2 ) ;
} else {
F_14 ( & V_1 -> V_14 , V_19 ) ;
V_1 -> free ( V_2 , V_1 -> V_6 ) ;
goto V_22;
}
}
V_20:
F_14 ( & V_1 -> V_14 , V_19 ) ;
V_22:
return 0 ;
}
void * F_16 ( T_1 * V_1 , T_4 V_11 )
{
void * V_2 ;
unsigned long V_19 ;
T_5 V_15 ;
T_4 V_23 ;
F_17 ( V_11 & V_24 ) ;
V_11 |= V_25 ;
V_11 |= V_26 ;
V_11 |= V_27 ;
V_23 = V_11 & ~ ( V_24 | V_28 ) ;
V_29:
V_2 = V_1 -> V_16 ( V_23 , V_1 -> V_6 ) ;
if ( F_18 ( V_2 != NULL ) )
return V_2 ;
F_13 ( & V_1 -> V_14 , V_19 ) ;
if ( F_18 ( V_1 -> V_3 ) ) {
V_2 = F_3 ( V_1 ) ;
F_14 ( & V_1 -> V_14 , V_19 ) ;
F_19 () ;
return V_2 ;
}
if ( V_23 != V_11 ) {
F_14 ( & V_1 -> V_14 , V_19 ) ;
V_23 = V_11 ;
goto V_29;
}
if ( ! ( V_11 & V_24 ) ) {
F_14 ( & V_1 -> V_14 , V_19 ) ;
return NULL ;
}
F_20 ( & V_15 ) ;
F_21 ( & V_1 -> V_15 , & V_15 , V_30 ) ;
F_14 ( & V_1 -> V_14 , V_19 ) ;
F_22 ( 5 * V_31 ) ;
F_23 ( & V_1 -> V_15 , & V_15 ) ;
goto V_29;
}
void F_24 ( void * V_2 , T_1 * V_1 )
{
unsigned long V_19 ;
if ( F_11 ( V_2 == NULL ) )
return;
F_25 () ;
if ( V_1 -> V_3 < V_1 -> V_4 ) {
F_13 ( & V_1 -> V_14 , V_19 ) ;
if ( V_1 -> V_3 < V_1 -> V_4 ) {
F_1 ( V_1 , V_2 ) ;
F_14 ( & V_1 -> V_14 , V_19 ) ;
F_26 ( & V_1 -> V_15 ) ;
return;
}
F_14 ( & V_1 -> V_14 , V_19 ) ;
}
V_1 -> free ( V_2 , V_1 -> V_6 ) ;
}
void * F_27 ( T_4 V_11 , void * V_6 )
{
struct V_32 * V_33 = V_6 ;
return F_28 ( V_33 , V_11 ) ;
}
void F_29 ( void * V_2 , void * V_6 )
{
struct V_32 * V_33 = V_6 ;
F_30 ( V_33 , V_2 ) ;
}
void * F_31 ( T_4 V_11 , void * V_6 )
{
T_6 V_34 = ( T_6 ) V_6 ;
return F_15 ( V_34 , V_11 ) ;
}
void F_32 ( void * V_2 , void * V_6 )
{
F_5 ( V_2 ) ;
}
void * F_33 ( T_4 V_11 , void * V_6 )
{
int V_35 = ( int ) ( long ) V_6 ;
return F_34 ( V_11 , V_35 ) ;
}
void F_35 ( void * V_2 , void * V_6 )
{
int V_35 = ( int ) ( long ) V_6 ;
F_36 ( V_2 , V_35 ) ;
}
