int F_1 ( unsigned long V_1 , unsigned long V_2 )
{
struct V_3 * V_4 , * V_5 ;
F_2 ( L_1 ,
V_1 , V_2 ) ;
while ( V_2 > 0 ) {
unsigned int V_6 ;
V_4 = F_3 ( sizeof( struct V_3 ) , V_7 ) ;
if ( ! V_4 )
goto Error;
F_4 ( & V_4 -> V_8 , & V_9 ) ;
V_4 -> V_10 = V_1 ;
V_6 = V_11 - ( V_1 & ~ V_12 ) ;
V_4 -> V_2 = ( V_2 < V_6 ) ? V_2 : V_6 ;
V_1 += V_4 -> V_2 ;
V_2 -= V_4 -> V_2 ;
}
return 0 ;
Error:
F_5 (entry, next, &nvs_list, node) {
F_6 ( & V_4 -> V_8 ) ;
F_7 ( V_4 ) ;
}
return - V_13 ;
}
void F_8 ( void )
{
struct V_3 * V_4 ;
F_9 (entry, &nvs_list, node)
if ( V_4 -> V_14 ) {
F_10 ( ( unsigned long ) V_4 -> V_14 ) ;
V_4 -> V_14 = NULL ;
if ( V_4 -> V_15 ) {
if ( V_4 -> V_16 ) {
F_11 ( V_4 -> V_15 ) ;
V_4 -> V_16 = false ;
} else {
F_12 ( V_4 -> V_15 ,
V_4 -> V_2 ) ;
}
V_4 -> V_15 = NULL ;
}
}
}
int F_13 ( void )
{
struct V_3 * V_4 ;
F_9 (entry, &nvs_list, node) {
V_4 -> V_14 = ( void * ) F_14 ( V_7 ) ;
if ( ! V_4 -> V_14 ) {
F_8 () ;
return - V_13 ;
}
}
return 0 ;
}
int F_15 ( void )
{
struct V_3 * V_4 ;
F_16 ( V_17 L_2 ) ;
F_9 (entry, &nvs_list, node)
if ( V_4 -> V_14 ) {
unsigned long V_18 = V_4 -> V_10 ;
unsigned int V_2 = V_4 -> V_2 ;
V_4 -> V_15 = F_17 ( V_18 , V_2 ) ;
if ( ! V_4 -> V_15 ) {
V_4 -> V_15 = F_18 ( V_18 , V_2 ) ;
V_4 -> V_16 = ! ! V_4 -> V_15 ;
}
if ( ! V_4 -> V_15 ) {
F_8 () ;
return - V_13 ;
}
memcpy ( V_4 -> V_14 , V_4 -> V_15 , V_4 -> V_2 ) ;
}
return 0 ;
}
void F_19 ( void )
{
struct V_3 * V_4 ;
F_16 ( V_17 L_3 ) ;
F_9 (entry, &nvs_list, node)
if ( V_4 -> V_14 )
memcpy ( V_4 -> V_15 , V_4 -> V_14 , V_4 -> V_2 ) ;
}
