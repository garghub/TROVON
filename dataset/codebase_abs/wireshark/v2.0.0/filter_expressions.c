struct V_1 *
F_1 ( const T_1 * V_2 , const T_1 * V_3 ,
const T_2 V_4 )
{
struct V_1 * V_5 ;
struct V_1 * V_6 ;
V_5 = (struct V_1 * ) F_2 ( sizeof( struct V_1 ) ) ;
V_5 -> V_2 = F_3 ( V_2 ) ;
V_5 -> V_5 = F_3 ( V_3 ) ;
V_5 -> V_4 = V_4 ;
if ( * V_7 == NULL ) {
V_8 = V_5 ;
} else {
V_6 = * V_7 ;
while ( V_6 -> V_9 != NULL )
V_6 = V_6 -> V_9 ;
V_6 -> V_9 = V_5 ;
V_5 -> V_10 = V_6 -> V_10 + 1 ;
}
return ( V_5 ) ;
}
void
F_4 ( T_2 V_11 )
{
if ( V_11 )
V_12 . V_13 = V_7 ;
}
void
F_5 ( struct V_1 * V_14 )
{
if ( V_14 == NULL )
return;
F_5 ( V_14 -> V_9 ) ;
F_6 ( V_14 -> V_2 ) ;
F_6 ( V_14 -> V_5 ) ;
}
