static T_1
F_1 ( void * V_1 , T_1 V_2 , T_1 V_3 , struct V_4 * V_5 )
{
struct V_6 * V_7 = V_1 ;
T_1 V_8 ;
if ( V_2 + V_3 <= 0x00100000 ) {
for ( V_8 = V_2 ; V_8 < V_2 + V_3 ; V_8 += 4 )
* ( T_1 * ) & V_5 -> V_1 [ V_8 ] = F_2 ( V_7 , 0x300000 + V_8 ) ;
return V_3 ;
}
return 0 ;
}
static void
F_3 ( void * V_1 )
{
struct V_6 * V_7 = V_1 ;
F_4 ( V_7 -> V_9 , true ) ;
}
static void *
F_5 ( struct V_4 * V_5 , const char * V_10 )
{
struct V_6 * V_7 = V_5 -> V_11 . V_7 ;
if ( V_7 -> V_12 == V_13 && V_7 -> V_14 >= 0x4c )
return F_6 ( - V_15 ) ;
F_4 ( V_7 -> V_9 , false ) ;
return V_7 ;
}
