static T_1
F_1 ( void * V_1 , T_1 V_2 , T_1 V_3 , struct V_4 * V_5 )
{
T_1 V_6 ;
if ( V_2 + V_3 <= 0x00100000 ) {
for ( V_6 = V_2 ; V_6 < V_2 + V_3 ; V_6 += 4 )
* ( T_1 * ) & V_5 -> V_1 [ V_6 ] = F_2 ( V_5 , 0x300000 + V_6 ) ;
return V_3 ;
}
return 0 ;
}
static void
F_3 ( void * V_1 )
{
struct V_4 * V_5 = V_1 ;
if ( F_4 ( V_5 ) -> V_7 < V_8 )
F_5 ( V_5 , 0x001850 , 0x00000001 , 0x00000001 ) ;
else
F_5 ( V_5 , 0x088050 , 0x00000001 , 0x00000001 ) ;
}
static void *
F_6 ( struct V_4 * V_5 , const char * V_9 )
{
if ( F_4 ( V_5 ) -> V_7 < V_8 ) {
if ( F_4 ( V_5 ) -> V_7 == V_10 &&
F_4 ( V_5 ) -> V_11 >= 0x4c )
return F_7 ( - V_12 ) ;
F_5 ( V_5 , 0x001850 , 0x00000001 , 0x00000000 ) ;
} else {
F_5 ( V_5 , 0x088050 , 0x00000001 , 0x00000000 ) ;
}
return V_5 ;
}
