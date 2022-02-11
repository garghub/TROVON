static inline int F_1 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
return F_3 ( V_6 , V_3 , V_4 ) ;
}
static inline int F_4 ( struct V_1 * V_2 , T_1 V_3 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
return F_5 ( V_6 , V_3 ) ;
}
static int F_6 ( struct V_1 * V_2 , struct V_7 * V_3 )
{
V_3 -> V_8 = F_4 ( V_2 , V_3 -> V_3 & 0xffff ) ;
V_3 -> V_9 = 1 ;
return 0 ;
}
static int F_7 ( struct V_1 * V_2 , const struct V_7 * V_3 )
{
F_1 ( V_2 , V_3 -> V_3 & 0xffff , V_3 -> V_8 & 0xff ) ;
return 0 ;
}
static int F_8 ( struct V_5 * V_6 ,
const struct V_10 * V_11 )
{
struct V_1 * V_2 ;
unsigned V_12 ;
if ( ! F_9 ( V_6 -> V_13 , V_14 ) )
return - V_15 ;
if ( ( F_5 ( V_6 , 0x1c ) & 0xf0 ) != 0xe0 )
return - V_16 ;
F_10 ( V_6 , L_1 ,
V_6 -> V_17 << 1 , V_6 -> V_13 -> V_18 ) ;
V_2 = F_11 ( sizeof( struct V_1 ) , V_19 ) ;
if ( V_2 == NULL )
return - V_20 ;
F_12 ( V_2 , V_6 , & V_21 ) ;
F_1 ( V_2 , 0x0d , 0x00 ) ;
F_1 ( V_2 , 0x0e , 0x00 ) ;
F_1 ( V_2 , 0x0b , 0x00 ) ;
for ( V_12 = 1 ; V_12 <= 8 ; V_12 ++ )
F_1 ( V_2 , V_12 , 0xd2 ) ;
F_1 ( V_2 , 0x0a , 0x00 ) ;
return 0 ;
}
static int F_13 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = F_14 ( V_6 ) ;
F_15 ( V_2 ) ;
F_16 ( V_2 ) ;
return 0 ;
}
