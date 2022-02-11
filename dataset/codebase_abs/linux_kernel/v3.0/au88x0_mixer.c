static int T_1 F_1 ( T_2 * V_1 )
{
struct V_2 * V_3 ;
struct V_4 V_5 ;
int V_6 ;
static struct V_7 V_8 = {
. V_9 = V_10 ,
. V_11 = V_12 ,
} ;
if ( ( V_6 = V_2 ( V_1 -> V_13 , 0 , & V_8 , NULL , & V_3 ) ) < 0 )
return V_6 ;
memset ( & V_5 , 0 , sizeof( V_5 ) ) ;
V_5 . V_14 = V_1 ;
V_5 . V_15 = V_16 ;
V_6 = F_2 ( V_3 , & V_5 , & V_1 -> V_17 ) ;
V_1 -> V_18 = ( ( V_1 -> V_17 == NULL ) ? 0 : ( V_1 -> V_17 -> V_19 & 0x80 ) ) ;
return V_6 ;
}
