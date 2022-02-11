static void F_1 ( struct V_1 * V_2 , T_1 V_3 , T_2 * V_4 )
{
while ( V_2 != NULL ) {
if ( V_2 -> V_5 != NULL )
F_1 ( V_2 -> V_5 , V_3 , V_4 ) ;
if ( ( V_2 -> V_6 & V_7 )
== V_7 ) {
F_2 ( L_1 ,
( unsigned long ) V_2 -> V_8 ,
( unsigned long ) V_2 -> V_9 ) ;
V_4 = ( V_3 ) ( V_2 , V_4 ) ;
}
V_2 = V_2 -> V_10 ;
}
}
static void F_3 ( T_1 V_3 , T_2 * V_4 )
{
F_1 ( & V_11 , V_3 , V_4 ) ;
}
static T_2 * F_4 ( struct V_1 * V_12 , T_2 * V_13 )
{
T_2 V_14 = ( T_2 ) F_5 ( V_12 ) ;
V_14 += V_15 - 1 ;
V_14 /= V_15 ;
F_2 ( L_2 ,
( unsigned long ) V_12 -> V_8 , ( unsigned long ) V_12 -> V_9 , V_14 ) ;
* V_13 += V_14 * sizeof( T_2 ) ;
return V_13 ;
}
void F_6 ( void )
{
V_16 = 0 ;
F_3 ( F_4 , & V_16 ) ;
F_2 ( L_3 , V_16 ) ;
V_17 = F_7 ( V_16 + 4 , V_18 ) ;
if ( V_17 == NULL )
F_8 ( V_19 L_4 ) ;
}
static T_2 * F_9 ( struct V_1 * V_12 , T_2 * V_13 )
{
unsigned long V_20 , V_21 ;
for ( V_20 = V_12 -> V_8 ; V_20 < V_12 -> V_9 ;
V_20 += V_15 ) {
V_21 = V_12 -> V_9 - V_20 ;
if ( V_21 > V_15 )
V_21 = V_15 ;
* V_13 = F_10 ( ~ 0 , F_11 ( V_20 ) , V_21 ) ;
V_13 ++ ;
}
return V_13 ;
}
void F_12 ( void )
{
if ( V_17 != NULL )
F_3 ( F_9 , V_17 ) ;
}
static inline int F_13 ( void * V_2 , int V_14 , void * V_22 , T_3 V_23 )
{
if ( ( V_22 + V_23 ) < V_2 )
return 0 ;
if ( V_22 > ( V_2 + V_14 ) )
return 0 ;
return 1 ;
}
static T_2 * F_14 ( struct V_1 * V_12 , T_2 * V_13 )
{
unsigned long V_20 ;
unsigned long V_21 ;
void * V_24 ;
void * V_2 ;
T_2 V_25 ;
V_24 = ( void * ) ( ( T_2 ) & V_25 & ~ V_26 ) ;
for ( V_20 = V_12 -> V_8 ; V_20 < V_12 -> V_9 ;
V_20 += V_15 ) {
V_21 = V_12 -> V_9 - V_20 ;
if ( V_21 > V_15 )
V_21 = V_15 ;
V_2 = F_11 ( V_20 ) ;
if ( F_13 ( V_2 , V_21 , V_24 , 4096 ) ) {
F_2 ( L_5 , V_20 ) ;
goto V_27;
}
if ( F_13 ( V_2 , V_21 , V_17 , V_16 ) ) {
F_2 ( L_6 , V_20 ) ;
goto V_27;
}
V_25 = F_10 ( ~ 0 , V_2 , V_21 ) ;
if ( V_25 != * V_13 ) {
F_8 ( V_19 L_7
L_8 , V_20 , V_25 , * V_13 ) ;
F_2 ( L_9 ,
V_20 , V_25 , * V_13 ) ;
}
V_27:
V_13 ++ ;
}
return V_13 ;
}
void F_15 ( void )
{
if ( V_17 != NULL )
F_3 ( F_14 , V_17 ) ;
}
void F_16 ( void )
{
F_17 ( V_17 ) ;
V_17 = NULL ;
}
