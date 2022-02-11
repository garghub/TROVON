static const struct V_1 * F_1 ( unsigned long V_2 )
{
if ( ( V_2 >= ( unsigned long ) & V_3 ) &&
( V_2 <= ( unsigned long ) & V_4 ) )
return & V_5 ;
return NULL ;
}
static int F_2 ( const void * V_6 , const void * V_7 )
{
const struct V_1 * V_8 = V_7 ;
unsigned long V_9 = * ( unsigned long * ) V_6 ;
if ( V_9 > V_8 -> V_10 )
return 1 ;
if ( V_9 < V_8 -> V_10 )
return - 1 ;
return 0 ;
}
const struct V_1 *
F_3 ( const struct V_1 * V_11 ,
const T_1 V_12 ,
unsigned long V_13 )
{
const struct V_1 * V_14 ;
V_14 = F_1 ( V_13 ) ;
if ( V_14 )
return V_14 ;
return bsearch ( & V_13 , V_11 , V_12 ,
sizeof( struct V_1 ) , F_2 ) ;
}
int F_4 ( struct V_15 * V_16 )
{
const struct V_1 * V_17 ;
V_17 = F_5 ( V_16 -> V_18 ) ;
if ( V_17 ) {
V_16 -> V_18 = V_17 -> V_17 ;
return 1 ;
}
return 0 ;
}
