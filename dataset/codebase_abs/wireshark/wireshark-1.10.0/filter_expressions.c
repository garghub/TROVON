struct V_1 *
F_1 ( const T_1 * V_2 , const T_1 * V_3 ,
const T_2 V_4 )
{
struct V_1 * V_5 ;
struct V_1 * V_6 ;
V_5 = (struct V_1 * ) F_2 ( sizeof( struct V_1 ) ) ;
memset ( V_5 , '\0' , sizeof( struct V_1 ) ) ;
V_5 -> V_7 = NULL ;
V_5 -> V_2 = F_3 ( V_2 ) ;
V_5 -> V_5 = F_3 ( V_3 ) ;
V_5 -> V_4 = V_4 ;
V_5 -> V_8 = FALSE ;
V_5 -> V_9 = 0 ;
V_5 -> V_10 = NULL ;
if ( * V_11 == NULL ) {
V_12 = V_5 ;
} else {
V_6 = * V_11 ;
while ( V_6 -> V_10 != NULL )
V_6 = V_6 -> V_10 ;
V_6 -> V_10 = V_5 ;
V_5 -> V_9 = V_6 -> V_9 + 1 ;
}
return ( V_5 ) ;
}
void
F_4 ( T_2 V_13 )
{
if ( V_13 )
V_14 . V_15 = V_11 ;
}
