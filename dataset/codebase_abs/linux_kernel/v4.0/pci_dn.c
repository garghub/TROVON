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
const T_1 * type = F_5 ( V_5 , L_1 , NULL ) ;
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
T_2 V_15 = F_8 ( V_9 , 1 ) ;
V_10 -> V_16 = ( V_15 >> 16 ) & 0xff ;
V_10 -> V_17 = ( V_15 >> 8 ) & 0xff ;
}
V_10 -> V_18 = ( type && F_8 ( type , 1 ) == 1 ) ;
return NULL ;
}
void * F_9 ( struct V_4 * V_19 , T_3 V_20 ,
void * V_6 )
{
struct V_4 * V_5 , * V_21 ;
void * V_22 ;
for ( V_5 = V_19 -> V_23 ; V_5 ; V_5 = V_21 ) {
const T_1 * V_24 ;
T_2 V_25 = 0 ;
V_21 = NULL ;
V_24 = F_5 ( V_5 , L_3 , NULL ) ;
if ( V_24 )
V_25 = F_8 ( V_24 , 1 ) ;
if ( V_20 && ( ( V_22 = V_20 ( V_5 , V_6 ) ) != NULL ) )
return V_22 ;
if ( V_5 -> V_23 && ( ( V_25 >> 8 ) == V_26 ||
( V_25 >> 8 ) == V_27 ) )
V_21 = V_5 -> V_23 ;
else if ( V_5 -> V_28 )
V_21 = V_5 -> V_28 ;
if ( ! V_21 ) {
do {
V_5 = V_5 -> V_29 ;
if ( V_5 == V_19 )
return NULL ;
} while ( V_5 -> V_28 == NULL );
V_21 = V_5 -> V_28 ;
}
}
return NULL ;
}
void F_10 ( struct V_7 * V_8 )
{
struct V_4 * V_5 = V_8 -> V_5 ;
struct V_1 * V_10 ;
F_4 ( V_5 , V_8 ) ;
V_10 = V_5 -> V_6 ;
if ( V_10 )
V_10 -> V_17 = V_10 -> V_16 = - 1 ;
F_9 ( V_5 , F_4 , V_8 ) ;
}
void T_4 F_11 ( void )
{
struct V_7 * V_8 , * V_30 ;
F_12 (phb, tmp, &hose_list, list_node)
F_10 ( V_8 ) ;
}
