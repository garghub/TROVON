static T_1
F_1 ( void * V_1 , T_1 V_2 , T_1 V_3 , struct V_4 * V_5 )
{
struct V_6 * V_7 = V_5 -> V_8 . V_7 ;
T_1 V_9 ;
if ( V_2 + V_3 <= 0x00100000 ) {
for ( V_9 = V_2 ; V_9 < V_2 + V_3 ; V_9 += 4 )
* ( T_1 * ) & V_5 -> V_1 [ V_9 ] = F_2 ( V_7 , 0x700000 + V_9 ) ;
return V_3 ;
}
return 0 ;
}
static void
F_3 ( void * V_1 )
{
struct V_10 * V_10 = V_1 ;
if ( V_10 ) {
struct V_6 * V_7 = V_10 -> V_5 -> V_8 . V_7 ;
F_4 ( V_7 , 0x001700 , V_10 -> V_11 ) ;
F_5 ( V_10 ) ;
}
}
static void *
F_6 ( struct V_4 * V_5 , const char * V_12 )
{
struct V_13 * V_8 = & V_5 -> V_8 ;
struct V_6 * V_7 = V_8 -> V_7 ;
struct V_10 * V_10 = NULL ;
T_2 V_14 = 0 ;
if ( V_7 -> V_15 < V_16 )
return NULL ;
if ( V_7 -> V_15 >= V_17 )
V_14 = F_2 ( V_7 , 0x021c04 ) ;
else
if ( V_7 -> V_15 >= V_18 )
V_14 = F_2 ( V_7 , 0x022500 ) ;
if ( V_14 & 0x00000001 ) {
F_7 ( V_8 , L_1 ) ;
return F_8 ( - V_19 ) ;
}
V_14 = F_2 ( V_7 , 0x619f04 ) ;
if ( ! ( V_14 & 0x00000008 ) ) {
F_7 ( V_8 , L_2 ) ;
return F_8 ( - V_19 ) ;
}
if ( ( V_14 & 0x00000003 ) != 1 ) {
F_7 ( V_8 , L_3 ) ;
return F_8 ( - V_19 ) ;
}
V_14 = ( V_14 & 0xffffff00 ) << 8 ;
if ( ! V_14 ) {
V_14 = ( T_2 ) F_2 ( V_7 , 0x001700 ) << 16 ;
V_14 += 0xf0000 ;
}
if ( ! ( V_10 = F_9 ( sizeof( * V_10 ) , V_20 ) ) ) {
F_10 ( V_8 , L_4 ) ;
return F_8 ( - V_21 ) ;
}
V_10 -> V_5 = V_5 ;
V_10 -> V_11 = F_2 ( V_7 , 0x001700 ) ;
F_4 ( V_7 , 0x001700 , V_14 >> 16 ) ;
return V_10 ;
}
