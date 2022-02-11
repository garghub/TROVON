int F_1 ( struct V_1 * V_2 )
{
void * V_3 = ( void * ) ( long ) V_2 -> V_3 ;
struct V_4 * V_5 = V_3 ;
struct V_6 * V_7 = V_3 + sizeof( * V_5 ) ;
struct V_8 * V_9 = V_3 + sizeof( * V_5 ) + sizeof( * V_7 ) ;
void * V_10 = ( void * ) ( long ) V_2 -> V_10 ;
if ( V_3 + sizeof( * V_5 ) + sizeof( * V_7 ) + sizeof( * V_9 ) > V_10 )
return 0 ;
if ( V_5 -> V_11 != F_2 ( V_12 ) )
return 0 ;
if ( V_7 -> V_13 != V_14 || V_7 -> V_15 != 5 )
return 0 ;
if ( F_3 ( V_7 ) )
return 0 ;
if ( V_9 -> V_16 == F_2 ( V_17 ) )
return V_18 ;
return 0 ;
}
