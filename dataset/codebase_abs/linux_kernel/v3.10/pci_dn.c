struct V_1 * F_1 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = F_2 ( V_3 ) ;
if ( ! V_5 )
return NULL ;
return F_3 ( V_5 ) ;
}
void * F_4 ( struct V_4 * V_5 , void * V_6 )
{
struct V_7 * V_8 = V_6 ;
const int * type =
F_5 ( V_5 , L_1 , NULL ) ;
const T_1 * V_9 ;
struct V_1 * V_10 ;
V_10 = F_6 ( sizeof( * V_10 ) , V_11 ) ;
if ( V_10 == NULL )
return NULL ;
V_5 -> V_6 = V_10 ;
V_10 -> V_12 = V_5 ;
V_10 -> V_8 = V_8 ;
#ifdef F_7
V_10 -> V_13 = V_14 ;
#endif
V_9 = F_5 ( V_5 , L_2 , NULL ) ;
if ( V_9 ) {
V_10 -> V_15 = ( V_9 [ 0 ] >> 16 ) & 0xff ;
V_10 -> V_16 = ( V_9 [ 0 ] >> 8 ) & 0xff ;
}
V_10 -> V_17 = ( type && * type == 1 ) ;
return NULL ;
}
void * F_8 ( struct V_4 * V_18 , T_2 V_19 ,
void * V_6 )
{
struct V_4 * V_5 , * V_20 ;
void * V_21 ;
for ( V_5 = V_18 -> V_22 ; V_5 ; V_5 = V_20 ) {
const T_1 * V_23 ;
T_1 V_24 ;
V_20 = NULL ;
V_23 = F_5 ( V_5 , L_3 , NULL ) ;
V_24 = V_23 ? * V_23 : 0 ;
if ( V_19 && ( ( V_21 = V_19 ( V_5 , V_6 ) ) != NULL ) )
return V_21 ;
if ( V_5 -> V_22 && ( ( V_24 >> 8 ) == V_25 ||
( V_24 >> 8 ) == V_26 ) )
V_20 = V_5 -> V_22 ;
else if ( V_5 -> V_27 )
V_20 = V_5 -> V_27 ;
if ( ! V_20 ) {
do {
V_5 = V_5 -> V_28 ;
if ( V_5 == V_18 )
return NULL ;
} while ( V_5 -> V_27 == NULL );
V_20 = V_5 -> V_27 ;
}
}
return NULL ;
}
void F_9 ( struct V_7 * V_8 )
{
struct V_4 * V_5 = V_8 -> V_5 ;
struct V_1 * V_10 ;
F_4 ( V_5 , V_8 ) ;
V_10 = V_5 -> V_6 ;
if ( V_10 ) {
V_10 -> V_16 = V_10 -> V_15 = - 1 ;
V_10 -> V_8 = V_8 ;
}
F_8 ( V_5 , F_4 , V_8 ) ;
}
void T_3 F_10 ( void )
{
struct V_7 * V_8 , * V_29 ;
F_11 (phb, tmp, &hose_list, list_node)
F_9 ( V_8 ) ;
}
