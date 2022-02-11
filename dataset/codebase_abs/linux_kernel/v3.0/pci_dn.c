void * T_1 F_1 ( struct V_1 * V_2 , void * V_3 )
{
struct V_4 * V_5 = V_3 ;
const int * type =
F_2 ( V_2 , L_1 , NULL ) ;
const T_2 * V_6 ;
struct V_7 * V_8 ;
V_8 = F_3 ( sizeof( * V_8 ) , V_9 ) ;
if ( V_8 == NULL )
return NULL ;
V_2 -> V_3 = V_8 ;
V_8 -> V_10 = V_2 ;
V_8 -> V_5 = V_5 ;
V_6 = F_2 ( V_2 , L_2 , NULL ) ;
if ( V_6 ) {
V_8 -> V_11 = ( V_6 [ 0 ] >> 16 ) & 0xff ;
V_8 -> V_12 = ( V_6 [ 0 ] >> 8 ) & 0xff ;
}
V_8 -> V_13 = ( type && * type == 1 ) ;
return NULL ;
}
void * F_4 ( struct V_1 * V_14 , T_3 V_15 ,
void * V_3 )
{
struct V_1 * V_2 , * V_16 ;
void * V_17 ;
for ( V_2 = V_14 -> V_18 ; V_2 ; V_2 = V_16 ) {
const T_2 * V_19 ;
T_2 V_20 ;
V_16 = NULL ;
V_19 = F_2 ( V_2 , L_3 , NULL ) ;
V_20 = V_19 ? * V_19 : 0 ;
if ( V_15 && ( ( V_17 = V_15 ( V_2 , V_3 ) ) != NULL ) )
return V_17 ;
if ( V_2 -> V_18 && ( ( V_20 >> 8 ) == V_21 ||
( V_20 >> 8 ) == V_22 ) )
V_16 = V_2 -> V_18 ;
else if ( V_2 -> V_23 )
V_16 = V_2 -> V_23 ;
if ( ! V_16 ) {
do {
V_2 = V_2 -> V_24 ;
if ( V_2 == V_14 )
return NULL ;
} while ( V_2 -> V_23 == NULL );
V_16 = V_2 -> V_23 ;
}
}
return NULL ;
}
void T_1 F_5 ( struct V_4 * V_5 )
{
struct V_1 * V_2 = V_5 -> V_2 ;
struct V_7 * V_8 ;
F_1 ( V_2 , V_5 ) ;
V_8 = V_2 -> V_3 ;
if ( V_8 ) {
V_8 -> V_12 = V_8 -> V_11 = - 1 ;
V_8 -> V_5 = V_5 ;
}
F_4 ( V_2 , F_1 , V_5 ) ;
}
static void * F_6 ( struct V_1 * V_2 , void * V_3 )
{
int V_11 = ( ( unsigned long ) V_3 >> 8 ) & 0xff ;
int V_12 = ( ( unsigned long ) V_3 ) & 0xff ;
struct V_7 * V_25 = V_2 -> V_3 ;
if ( V_25 && ( V_12 == V_25 -> V_12 ) && ( V_11 == V_25 -> V_11 ) )
return V_2 ;
return NULL ;
}
struct V_1 * F_7 ( struct V_26 * V_27 )
{
struct V_4 * V_5 = V_27 -> V_28 ;
struct V_1 * V_2 ;
unsigned long V_29 = ( V_27 -> V_30 -> V_31 << 8 ) | V_27 -> V_12 ;
if ( F_8 ( ! V_5 ) )
return NULL ;
V_2 = F_4 ( V_5 -> V_2 , F_6 , ( void * ) V_29 ) ;
if ( V_2 )
V_27 -> V_27 . V_32 = V_2 ;
return V_2 ;
}
void T_4 F_9 ( void )
{
struct V_4 * V_5 , * V_33 ;
F_10 (phb, tmp, &hose_list, list_node)
F_5 ( V_5 ) ;
}
