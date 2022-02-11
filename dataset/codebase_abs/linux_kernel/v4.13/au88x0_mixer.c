static int F_1 ( struct V_1 * V_2 , const char * V_3 )
{
struct V_4 V_5 ;
memset ( & V_5 , 0 , sizeof( V_5 ) ) ;
strcpy ( V_5 . V_3 , V_3 ) ;
V_5 . V_6 = V_7 ;
return F_2 ( V_2 , & V_5 ) ;
}
static int F_3 ( T_1 * V_8 )
{
struct V_9 * V_10 ;
struct V_11 V_12 ;
int V_13 ;
static struct V_14 V_15 = {
. V_16 = V_17 ,
. V_18 = V_19 ,
} ;
if ( ( V_13 = V_9 ( V_8 -> V_2 , 0 , & V_15 , NULL , & V_10 ) ) < 0 )
return V_13 ;
memset ( & V_12 , 0 , sizeof( V_12 ) ) ;
V_12 . V_20 = V_8 ;
V_12 . V_21 = V_22 ;
V_13 = F_4 ( V_10 , & V_12 , & V_8 -> V_23 ) ;
V_8 -> V_24 = ( ( V_8 -> V_23 == NULL ) ? 0 : ( V_8 -> V_23 -> V_25 & 0x80 ) ) ;
F_1 ( V_8 -> V_2 , L_1 ) ;
F_1 ( V_8 -> V_2 , L_2 ) ;
return V_13 ;
}
