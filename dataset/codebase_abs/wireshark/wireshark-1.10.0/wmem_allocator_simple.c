static void *
F_1 ( void * V_1 , const T_1 V_2 )
{
void * V_3 ;
T_2 * V_4 ;
V_4 = ( T_2 * ) V_1 ;
V_3 = F_2 ( V_2 ) ;
F_3 ( V_4 -> V_5 , V_3 , V_3 ) ;
return V_3 ;
}
static void
F_4 ( void * V_1 , void * V_6 )
{
T_3 V_7 ;
T_2 * V_4 ;
V_4 = ( T_2 * ) V_1 ;
V_7 = F_5 ( V_4 -> V_5 , V_6 ) ;
F_6 ( V_7 ) ;
}
static void *
F_7 ( void * V_1 , void * V_6 , const T_1 V_2 )
{
void * V_8 ;
T_2 * V_4 ;
V_4 = ( T_2 * ) V_1 ;
V_8 = F_8 ( V_6 , V_2 ) ;
if ( V_6 != V_8 ) {
F_9 ( V_4 -> V_5 , V_6 ) ;
F_3 ( V_4 -> V_5 , V_8 , V_8 ) ;
}
return V_8 ;
}
static void
F_10 ( void * V_1 )
{
T_2 * V_4 ;
V_4 = ( T_2 * ) V_1 ;
F_11 ( V_4 -> V_5 ) ;
}
static void
F_12 ( void * V_1 V_9 )
{
}
static void
F_13 ( T_4 * V_4 )
{
T_2 * V_10 ;
V_10 = ( T_2 * ) V_4 -> V_1 ;
F_14 ( V_10 -> V_5 ) ;
F_15 ( T_2 , V_10 ) ;
F_15 ( T_4 , V_4 ) ;
}
T_4 *
F_16 ( void )
{
T_4 * V_4 ;
T_2 * V_11 ;
V_4 = F_17 ( T_4 ) ;
V_11 = F_17 ( T_2 ) ;
V_4 -> V_1 = ( void * ) V_11 ;
V_4 -> V_12 = & F_1 ;
V_4 -> realloc = & F_7 ;
V_4 -> free = & F_4 ;
V_4 -> V_13 = & F_10 ;
V_4 -> V_14 = & F_12 ;
V_4 -> V_15 = & F_13 ;
V_11 -> V_5 = F_18 (
& V_16 , & V_17 , NULL , & V_18 ) ;
return V_4 ;
}
