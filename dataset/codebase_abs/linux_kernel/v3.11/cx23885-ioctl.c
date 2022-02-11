int F_1 ( struct V_1 * V_1 , void * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = ( (struct V_7 * ) V_2 ) -> V_6 ;
if ( V_4 -> V_8 . V_9 > 1 )
return - V_10 ;
if ( V_4 -> V_8 . V_9 == 1 ) {
if ( V_6 -> V_11 == NULL )
return - V_10 ;
F_2 ( V_4 -> V_12 , L_1 , sizeof( V_4 -> V_12 ) ) ;
} else {
F_2 ( V_4 -> V_12 , V_6 -> V_13 . V_12 , sizeof( V_4 -> V_12 ) ) ;
}
return 0 ;
}
static int F_3 ( struct V_5 * V_6 ,
struct V_14 * V_15 )
{
T_1 V_16 ;
if ( V_6 -> V_11 == NULL )
return - V_10 ;
if ( ( V_15 -> V_15 & 0x3 ) != 0 || V_15 -> V_15 >= 0x10000 )
return - V_10 ;
if ( F_4 ( V_6 , ( V_17 ) V_15 -> V_15 , & V_16 ) )
return - V_10 ;
V_15 -> V_18 = 4 ;
V_15 -> V_19 = V_16 ;
return 0 ;
}
int F_5 ( struct V_1 * V_1 , void * V_2 ,
struct V_14 * V_15 )
{
struct V_5 * V_6 = ( (struct V_7 * ) V_2 ) -> V_6 ;
if ( V_15 -> V_8 . V_9 > 1 )
return - V_10 ;
if ( V_15 -> V_8 . V_9 )
return F_3 ( V_6 , V_15 ) ;
if ( ( V_15 -> V_15 & 0x3 ) != 0 || V_15 -> V_15 >= F_6 ( V_6 -> V_20 , 0 ) )
return - V_10 ;
V_15 -> V_18 = 4 ;
V_15 -> V_19 = F_7 ( V_15 -> V_15 ) ;
return 0 ;
}
static int F_8 ( struct V_5 * V_6 ,
const struct V_14 * V_15 )
{
if ( V_6 -> V_11 == NULL )
return - V_10 ;
if ( ( V_15 -> V_15 & 0x3 ) != 0 || V_15 -> V_15 >= 0x10000 )
return - V_10 ;
if ( F_9 ( V_6 , ( V_17 ) V_15 -> V_15 , ( T_1 ) V_15 -> V_19 ) )
return - V_10 ;
return 0 ;
}
int F_10 ( struct V_1 * V_1 , void * V_2 ,
const struct V_14 * V_15 )
{
struct V_5 * V_6 = ( (struct V_7 * ) V_2 ) -> V_6 ;
if ( V_15 -> V_8 . V_9 > 1 )
return - V_10 ;
if ( V_15 -> V_8 . V_9 )
return F_8 ( V_6 , V_15 ) ;
if ( ( V_15 -> V_15 & 0x3 ) != 0 || V_15 -> V_15 >= F_6 ( V_6 -> V_20 , 0 ) )
return - V_10 ;
F_11 ( V_15 -> V_15 , V_15 -> V_19 ) ;
return 0 ;
}
