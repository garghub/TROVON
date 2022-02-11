static inline int F_1 ( unsigned long V_1 , unsigned long V_2 )
{
return 0 ;
}
int F_2 ( T_1 V_3 , T_1 V_4 )
{
struct V_5 * V_6 ;
V_6 = F_3 ( sizeof( * V_6 ) , V_7 ) ;
if ( ! V_6 )
return - V_8 ;
V_6 -> V_9 = V_3 ;
V_6 -> V_4 = V_4 ;
F_4 ( & V_6 -> V_10 , & V_11 ) ;
return F_1 ( V_3 , V_4 ) ;
}
int F_5 ( int (* F_6)( T_1 V_3 , T_1 V_4 , void * V_12 ) ,
void * V_12 )
{
int V_13 ;
struct V_5 * V_6 ;
F_7 (region, &nvs_region_list, node) {
V_13 = F_6 ( V_6 -> V_9 , V_6 -> V_4 , V_12 ) ;
if ( V_13 )
return V_13 ;
}
return 0 ;
}
static int F_1 ( unsigned long V_3 , unsigned long V_4 )
{
struct V_14 * V_15 , * V_16 ;
F_8 ( L_1 ,
V_3 , V_4 ) ;
while ( V_4 > 0 ) {
unsigned int V_17 ;
V_15 = F_9 ( sizeof( struct V_14 ) , V_7 ) ;
if ( ! V_15 )
goto Error;
F_4 ( & V_15 -> V_10 , & V_18 ) ;
V_15 -> V_9 = V_3 ;
V_17 = V_19 - ( V_3 & ~ V_20 ) ;
V_15 -> V_4 = ( V_4 < V_17 ) ? V_4 : V_17 ;
V_3 += V_15 -> V_4 ;
V_4 -= V_15 -> V_4 ;
}
return 0 ;
Error:
F_10 (entry, next, &nvs_list, node) {
F_11 ( & V_15 -> V_10 ) ;
F_12 ( V_15 ) ;
}
return - V_8 ;
}
void F_13 ( void )
{
struct V_14 * V_15 ;
F_7 (entry, &nvs_list, node)
if ( V_15 -> V_12 ) {
F_14 ( ( unsigned long ) V_15 -> V_12 ) ;
V_15 -> V_12 = NULL ;
if ( V_15 -> V_21 ) {
if ( V_15 -> V_22 ) {
F_15 ( V_15 -> V_21 ) ;
V_15 -> V_22 = false ;
} else {
F_16 ( V_15 -> V_21 ,
V_15 -> V_4 ) ;
}
V_15 -> V_21 = NULL ;
}
}
}
int F_17 ( void )
{
struct V_14 * V_15 ;
F_7 (entry, &nvs_list, node) {
V_15 -> V_12 = ( void * ) F_18 ( V_7 ) ;
if ( ! V_15 -> V_12 ) {
F_13 () ;
return - V_8 ;
}
}
return 0 ;
}
int F_19 ( void )
{
struct V_14 * V_15 ;
F_20 ( V_23 L_2 ) ;
F_7 (entry, &nvs_list, node)
if ( V_15 -> V_12 ) {
unsigned long V_24 = V_15 -> V_9 ;
unsigned int V_4 = V_15 -> V_4 ;
V_15 -> V_21 = F_21 ( V_24 , V_4 ) ;
if ( ! V_15 -> V_21 ) {
V_15 -> V_21 = F_22 ( V_24 , V_4 ) ;
V_15 -> V_22 = ! ! V_15 -> V_21 ;
}
if ( ! V_15 -> V_21 ) {
F_13 () ;
return - V_8 ;
}
memcpy ( V_15 -> V_12 , V_15 -> V_21 , V_15 -> V_4 ) ;
}
return 0 ;
}
void F_23 ( void )
{
struct V_14 * V_15 ;
F_20 ( V_23 L_3 ) ;
F_7 (entry, &nvs_list, node)
if ( V_15 -> V_12 )
memcpy ( V_15 -> V_21 , V_15 -> V_12 , V_15 -> V_4 ) ;
}
