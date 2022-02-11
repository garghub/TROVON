static void F_1 ( struct V_1 * V_2 , T_1 V_3 , T_2 * V_4 )
{
while ( V_2 != NULL ) {
if ( V_2 -> V_5 != NULL )
F_1 ( V_2 -> V_5 , V_3 , V_4 ) ;
if ( ( V_2 -> V_6 & V_7 ) &&
strcmp ( V_2 -> V_8 , L_1 ) == 0 ) {
F_2 ( L_2 ,
( unsigned long ) V_2 -> V_9 ,
( unsigned long ) V_2 -> V_10 ) ;
V_4 = ( V_3 ) ( V_2 , V_4 ) ;
}
V_2 = V_2 -> V_11 ;
}
}
static void F_3 ( T_1 V_3 , T_2 * V_4 )
{
F_1 ( & V_12 , V_3 , V_4 ) ;
}
static T_2 * F_4 ( struct V_1 * V_13 , T_2 * V_14 )
{
T_2 V_15 = ( T_2 ) ( V_13 -> V_10 - V_13 -> V_9 ) + 1 ;
V_15 += V_16 - 1 ;
V_15 /= V_16 ;
F_2 ( L_3 ,
( unsigned long ) V_13 -> V_9 , ( unsigned long ) V_13 -> V_10 , V_15 ) ;
* V_14 += V_15 * sizeof( T_2 ) ;
return V_14 ;
}
void F_5 ( void )
{
V_17 = 0 ;
F_3 ( F_4 , & V_17 ) ;
F_2 ( L_4 , V_17 ) ;
V_18 = F_6 ( V_17 + 4 , V_19 ) ;
if ( V_18 == NULL )
F_7 ( V_20 L_5 ) ;
}
static T_2 * F_8 ( struct V_1 * V_13 , T_2 * V_14 )
{
unsigned long V_21 , V_22 ;
for ( V_21 = V_13 -> V_9 ; V_21 < V_13 -> V_10 ;
V_21 += V_16 ) {
V_22 = V_13 -> V_10 - V_21 ;
if ( V_22 > V_16 )
V_22 = V_16 ;
* V_14 = F_9 ( ~ 0 , F_10 ( V_21 ) , V_22 ) ;
V_14 ++ ;
}
return V_14 ;
}
void F_11 ( void )
{
if ( V_18 != NULL )
F_3 ( F_8 , V_18 ) ;
}
static inline int F_12 ( void * V_2 , int V_15 , void * V_23 , T_3 V_24 )
{
if ( ( V_23 + V_24 ) < V_2 )
return 0 ;
if ( V_23 > ( V_2 + V_15 ) )
return 0 ;
return 1 ;
}
static T_2 * F_13 ( struct V_1 * V_13 , T_2 * V_14 )
{
unsigned long V_21 ;
unsigned long V_22 ;
void * V_25 ;
void * V_2 ;
T_2 V_26 ;
V_25 = ( void * ) ( ( T_2 ) & V_26 & ~ V_27 ) ;
for ( V_21 = V_13 -> V_9 ; V_21 < V_13 -> V_10 ;
V_21 += V_16 ) {
V_22 = V_13 -> V_10 - V_21 ;
if ( V_22 > V_16 )
V_22 = V_16 ;
V_2 = F_10 ( V_21 ) ;
if ( F_12 ( V_2 , V_22 , V_25 , 4096 ) ) {
F_2 ( L_6 , V_21 ) ;
goto V_28;
}
if ( F_12 ( V_2 , V_22 , V_18 , V_17 ) ) {
F_2 ( L_7 , V_21 ) ;
goto V_28;
}
V_26 = F_9 ( ~ 0 , V_2 , V_22 ) ;
if ( V_26 != * V_14 ) {
F_7 ( V_20 L_8
L_9 , V_21 , V_26 , * V_14 ) ;
F_2 ( L_10 ,
V_21 , V_26 , * V_14 ) ;
}
V_28:
V_14 ++ ;
}
return V_14 ;
}
void F_14 ( void )
{
if ( V_18 != NULL )
F_3 ( F_13 , V_18 ) ;
}
void F_15 ( void )
{
F_16 ( V_18 ) ;
V_18 = NULL ;
}
