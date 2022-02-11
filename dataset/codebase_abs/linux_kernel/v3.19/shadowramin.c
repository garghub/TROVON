static T_1
F_1 ( void * V_1 , T_1 V_2 , T_1 V_3 , struct V_4 * V_5 )
{
T_1 V_6 ;
if ( V_2 + V_3 <= 0x00100000 ) {
for ( V_6 = V_2 ; V_6 < V_2 + V_3 ; V_6 += 4 )
* ( T_1 * ) & V_5 -> V_1 [ V_6 ] = F_2 ( V_5 , 0x700000 + V_6 ) ;
return V_3 ;
}
return 0 ;
}
static void
F_3 ( void * V_1 )
{
struct V_7 * V_7 = V_1 ;
if ( V_7 ) {
F_4 ( V_7 -> V_5 , 0x001700 , V_7 -> V_8 ) ;
F_5 ( V_7 ) ;
}
}
static void *
F_6 ( struct V_4 * V_5 , const char * V_9 )
{
struct V_7 * V_7 = NULL ;
T_2 V_10 = 0 ;
if ( F_7 ( V_5 ) -> V_11 < V_12 )
return NULL ;
if ( F_7 ( V_5 ) -> V_11 >= V_13 )
V_10 = F_2 ( V_5 , 0x021c04 ) ;
else
if ( F_7 ( V_5 ) -> V_11 >= V_14 )
V_10 = F_2 ( V_5 , 0x022500 ) ;
if ( V_10 & 0x00000001 ) {
F_8 ( V_5 , L_1 ) ;
return F_9 ( - V_15 ) ;
}
V_10 = F_2 ( V_5 , 0x619f04 ) ;
if ( ! ( V_10 & 0x00000008 ) ) {
F_8 ( V_5 , L_2 ) ;
return F_9 ( - V_15 ) ;
}
if ( ( V_10 & 0x00000003 ) != 1 ) {
F_8 ( V_5 , L_3 ) ;
return F_9 ( - V_15 ) ;
}
V_10 = ( V_10 & 0xffffff00 ) << 8 ;
if ( ! V_10 ) {
V_10 = ( T_2 ) F_2 ( V_5 , 0x001700 ) << 16 ;
V_10 += 0xf0000 ;
}
if ( ! ( V_7 = F_10 ( sizeof( * V_7 ) , V_16 ) ) ) {
F_11 ( V_5 , L_4 ) ;
return F_9 ( - V_17 ) ;
}
V_7 -> V_5 = V_5 ;
V_7 -> V_8 = F_2 ( V_5 , 0x001700 ) ;
F_4 ( V_5 , 0x001700 , V_10 >> 16 ) ;
return V_7 ;
}
