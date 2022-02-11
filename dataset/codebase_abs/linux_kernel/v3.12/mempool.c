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
V_1 = F_8 ( sizeof( * V_1 ) , V_11 , V_12 ) ;
if ( ! V_1 )
return NULL ;
V_1 -> V_5 = F_9 ( V_4 * sizeof( void * ) ,
V_11 , V_12 ) ;
if ( ! V_1 -> V_5 ) {
F_5 ( V_1 ) ;
return NULL ;
}
F_10 ( & V_1 -> V_13 ) ;
V_1 -> V_4 = V_4 ;
V_1 -> V_6 = V_6 ;
F_11 ( & V_1 -> V_14 ) ;
V_1 -> V_15 = V_7 ;
V_1 -> free = V_8 ;
while ( V_1 -> V_3 < V_1 -> V_4 ) {
void * V_2 ;
V_2 = V_1 -> V_15 ( V_11 , V_1 -> V_6 ) ;
if ( F_12 ( ! V_2 ) ) {
F_4 ( V_1 ) ;
return NULL ;
}
F_1 ( V_1 , V_2 ) ;
}
return V_1 ;
}
int F_13 ( T_1 * V_1 , int V_16 , T_4 V_11 )
{
void * V_2 ;
void * * V_17 ;
unsigned long V_18 ;
F_2 ( V_16 <= 0 ) ;
F_14 ( & V_1 -> V_13 , V_18 ) ;
if ( V_16 <= V_1 -> V_4 ) {
while ( V_16 < V_1 -> V_3 ) {
V_2 = F_3 ( V_1 ) ;
F_15 ( & V_1 -> V_13 , V_18 ) ;
V_1 -> free ( V_2 , V_1 -> V_6 ) ;
F_14 ( & V_1 -> V_13 , V_18 ) ;
}
V_1 -> V_4 = V_16 ;
goto V_19;
}
F_15 ( & V_1 -> V_13 , V_18 ) ;
V_17 = F_16 ( V_16 * sizeof( * V_17 ) , V_11 ) ;
if ( ! V_17 )
return - V_20 ;
F_14 ( & V_1 -> V_13 , V_18 ) ;
if ( F_12 ( V_16 <= V_1 -> V_4 ) ) {
F_15 ( & V_1 -> V_13 , V_18 ) ;
F_5 ( V_17 ) ;
goto V_21;
}
memcpy ( V_17 , V_1 -> V_5 ,
V_1 -> V_3 * sizeof( * V_17 ) ) ;
F_5 ( V_1 -> V_5 ) ;
V_1 -> V_5 = V_17 ;
V_1 -> V_4 = V_16 ;
while ( V_1 -> V_3 < V_1 -> V_4 ) {
F_15 ( & V_1 -> V_13 , V_18 ) ;
V_2 = V_1 -> V_15 ( V_11 , V_1 -> V_6 ) ;
if ( ! V_2 )
goto V_21;
F_14 ( & V_1 -> V_13 , V_18 ) ;
if ( V_1 -> V_3 < V_1 -> V_4 ) {
F_1 ( V_1 , V_2 ) ;
} else {
F_15 ( & V_1 -> V_13 , V_18 ) ;
V_1 -> free ( V_2 , V_1 -> V_6 ) ;
goto V_21;
}
}
V_19:
F_15 ( & V_1 -> V_13 , V_18 ) ;
V_21:
return 0 ;
}
void * F_17 ( T_1 * V_1 , T_4 V_11 )
{
void * V_2 ;
unsigned long V_18 ;
T_5 V_14 ;
T_4 V_22 ;
F_18 ( V_11 & V_23 ) ;
V_11 |= V_24 ;
V_11 |= V_25 ;
V_11 |= V_26 ;
V_22 = V_11 & ~ ( V_23 | V_27 ) ;
V_28:
V_2 = V_1 -> V_15 ( V_22 , V_1 -> V_6 ) ;
if ( F_19 ( V_2 != NULL ) )
return V_2 ;
F_14 ( & V_1 -> V_13 , V_18 ) ;
if ( F_19 ( V_1 -> V_3 ) ) {
V_2 = F_3 ( V_1 ) ;
F_15 ( & V_1 -> V_13 , V_18 ) ;
F_20 () ;
return V_2 ;
}
if ( V_22 != V_11 ) {
F_15 ( & V_1 -> V_13 , V_18 ) ;
V_22 = V_11 ;
goto V_28;
}
if ( ! ( V_11 & V_23 ) ) {
F_15 ( & V_1 -> V_13 , V_18 ) ;
return NULL ;
}
F_21 ( & V_14 ) ;
F_22 ( & V_1 -> V_14 , & V_14 , V_29 ) ;
F_15 ( & V_1 -> V_13 , V_18 ) ;
F_23 ( 5 * V_30 ) ;
F_24 ( & V_1 -> V_14 , & V_14 ) ;
goto V_28;
}
void F_25 ( void * V_2 , T_1 * V_1 )
{
unsigned long V_18 ;
if ( F_12 ( V_2 == NULL ) )
return;
F_26 () ;
if ( V_1 -> V_3 < V_1 -> V_4 ) {
F_14 ( & V_1 -> V_13 , V_18 ) ;
if ( V_1 -> V_3 < V_1 -> V_4 ) {
F_1 ( V_1 , V_2 ) ;
F_15 ( & V_1 -> V_13 , V_18 ) ;
F_27 ( & V_1 -> V_14 ) ;
return;
}
F_15 ( & V_1 -> V_13 , V_18 ) ;
}
V_1 -> free ( V_2 , V_1 -> V_6 ) ;
}
void * F_28 ( T_4 V_11 , void * V_6 )
{
struct V_31 * V_32 = V_6 ;
return F_29 ( V_32 , V_11 ) ;
}
void F_30 ( void * V_2 , void * V_6 )
{
struct V_31 * V_32 = V_6 ;
F_31 ( V_32 , V_2 ) ;
}
void * F_32 ( T_4 V_11 , void * V_6 )
{
T_6 V_33 = ( T_6 ) V_6 ;
return F_16 ( V_33 , V_11 ) ;
}
void F_33 ( void * V_2 , void * V_6 )
{
F_5 ( V_2 ) ;
}
void * F_34 ( T_4 V_11 , void * V_6 )
{
int V_34 = ( int ) ( long ) V_6 ;
return F_35 ( V_11 , V_34 ) ;
}
void F_36 ( void * V_2 , void * V_6 )
{
int V_34 = ( int ) ( long ) V_6 ;
F_37 ( V_2 , V_34 ) ;
}
