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
#ifdef F_4
V_8 -> V_11 = V_12 ;
#endif
V_6 = F_2 ( V_2 , L_2 , NULL ) ;
if ( V_6 ) {
V_8 -> V_13 = ( V_6 [ 0 ] >> 16 ) & 0xff ;
V_8 -> V_14 = ( V_6 [ 0 ] >> 8 ) & 0xff ;
}
V_8 -> V_15 = ( type && * type == 1 ) ;
return NULL ;
}
void * F_5 ( struct V_1 * V_16 , T_3 V_17 ,
void * V_3 )
{
struct V_1 * V_2 , * V_18 ;
void * V_19 ;
for ( V_2 = V_16 -> V_20 ; V_2 ; V_2 = V_18 ) {
const T_2 * V_21 ;
T_2 V_22 ;
V_18 = NULL ;
V_21 = F_2 ( V_2 , L_3 , NULL ) ;
V_22 = V_21 ? * V_21 : 0 ;
if ( V_17 && ( ( V_19 = V_17 ( V_2 , V_3 ) ) != NULL ) )
return V_19 ;
if ( V_2 -> V_20 && ( ( V_22 >> 8 ) == V_23 ||
( V_22 >> 8 ) == V_24 ) )
V_18 = V_2 -> V_20 ;
else if ( V_2 -> V_25 )
V_18 = V_2 -> V_25 ;
if ( ! V_18 ) {
do {
V_2 = V_2 -> V_26 ;
if ( V_2 == V_16 )
return NULL ;
} while ( V_2 -> V_25 == NULL );
V_18 = V_2 -> V_25 ;
}
}
return NULL ;
}
void T_1 F_6 ( struct V_4 * V_5 )
{
struct V_1 * V_2 = V_5 -> V_2 ;
struct V_7 * V_8 ;
F_1 ( V_2 , V_5 ) ;
V_8 = V_2 -> V_3 ;
if ( V_8 ) {
V_8 -> V_14 = V_8 -> V_13 = - 1 ;
V_8 -> V_5 = V_5 ;
}
F_5 ( V_2 , F_1 , V_5 ) ;
}
void T_4 F_7 ( void )
{
struct V_4 * V_5 , * V_27 ;
F_8 (phb, tmp, &hose_list, list_node)
F_6 ( V_5 ) ;
}
