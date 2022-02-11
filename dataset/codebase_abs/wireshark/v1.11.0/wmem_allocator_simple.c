static void *
F_1 ( void * V_1 , const T_1 V_2 )
{
void * V_3 ;
T_2 * V_4 ;
V_4 = ( T_2 * ) V_1 ;
V_3 = F_2 ( NULL , V_2 ) ;
F_3 ( V_4 -> V_5 , V_3 , V_3 ) ;
return V_3 ;
}
static void
F_4 ( T_3 V_6 )
{
F_5 ( NULL , V_6 ) ;
}
static void
F_6 ( void * V_1 , void * V_6 )
{
T_4 V_7 ;
T_2 * V_4 ;
V_4 = ( T_2 * ) V_1 ;
V_7 = F_7 ( V_4 -> V_5 , V_6 ) ;
F_8 ( V_7 ) ;
}
static void *
F_9 ( void * V_1 , void * V_6 , const T_1 V_2 )
{ void * V_8 ;
T_2 * V_4 ;
V_4 = ( T_2 * ) V_1 ;
V_8 = F_10 ( NULL , V_6 , V_2 ) ;
if ( V_6 != V_8 ) {
F_11 ( V_4 -> V_5 , V_6 ) ;
F_3 ( V_4 -> V_5 , V_8 , V_8 ) ;
}
return V_8 ;
}
static void
F_12 ( void * V_1 )
{
T_2 * V_4 ;
V_4 = ( T_2 * ) V_1 ;
F_13 ( V_4 -> V_5 ) ;
}
static void
F_14 ( void * V_1 V_9 )
{
}
static void
F_15 ( void * V_1 )
{
T_2 * V_4 ;
V_4 = ( T_2 * ) V_1 ;
F_16 ( V_4 -> V_5 ) ;
F_5 ( NULL , V_4 ) ;
}
void
F_17 ( T_5 * V_4 )
{
T_2 * V_10 ;
V_10 = F_18 ( NULL , T_2 ) ;
V_4 -> V_11 = & F_1 ;
V_4 -> realloc = & F_9 ;
V_4 -> free = & F_6 ;
V_4 -> V_12 = & F_12 ;
V_4 -> V_13 = & F_14 ;
V_4 -> V_14 = & F_15 ;
V_4 -> V_1 = ( void * ) V_10 ;
V_10 -> V_5 = F_19 (
& V_15 , & V_16 , NULL , & F_4 ) ;
}
