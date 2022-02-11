int F_1 ( struct V_1 * V_1 , void * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_1 ) ;
if ( V_4 -> V_7 . V_8 > 1 )
return - V_9 ;
if ( V_4 -> V_7 . V_8 == 1 ) {
if ( V_6 -> V_10 == NULL )
return - V_9 ;
F_3 ( V_4 -> V_11 , L_1 , sizeof( V_4 -> V_11 ) ) ;
} else {
F_3 ( V_4 -> V_11 , V_6 -> V_12 . V_11 , sizeof( V_4 -> V_11 ) ) ;
}
return 0 ;
}
static int F_4 ( struct V_5 * V_6 ,
struct V_13 * V_14 )
{
T_1 V_15 ;
if ( V_6 -> V_10 == NULL )
return - V_9 ;
if ( ( V_14 -> V_14 & 0x3 ) != 0 || V_14 -> V_14 >= 0x10000 )
return - V_9 ;
if ( F_5 ( V_6 , ( V_16 ) V_14 -> V_14 , & V_15 ) )
return - V_9 ;
V_14 -> V_17 = 4 ;
V_14 -> V_18 = V_15 ;
return 0 ;
}
int F_6 ( struct V_1 * V_1 , void * V_2 ,
struct V_13 * V_14 )
{
struct V_5 * V_6 = F_2 ( V_1 ) ;
if ( V_14 -> V_7 . V_8 > 1 )
return - V_9 ;
if ( V_14 -> V_7 . V_8 )
return F_4 ( V_6 , V_14 ) ;
if ( ( V_14 -> V_14 & 0x3 ) != 0 || V_14 -> V_14 >= F_7 ( V_6 -> V_19 , 0 ) )
return - V_9 ;
V_14 -> V_17 = 4 ;
V_14 -> V_18 = F_8 ( V_14 -> V_14 ) ;
return 0 ;
}
static int F_9 ( struct V_5 * V_6 ,
const struct V_13 * V_14 )
{
if ( V_6 -> V_10 == NULL )
return - V_9 ;
if ( ( V_14 -> V_14 & 0x3 ) != 0 || V_14 -> V_14 >= 0x10000 )
return - V_9 ;
if ( F_10 ( V_6 , ( V_16 ) V_14 -> V_14 , ( T_1 ) V_14 -> V_18 ) )
return - V_9 ;
return 0 ;
}
int F_11 ( struct V_1 * V_1 , void * V_2 ,
const struct V_13 * V_14 )
{
struct V_5 * V_6 = F_2 ( V_1 ) ;
if ( V_14 -> V_7 . V_8 > 1 )
return - V_9 ;
if ( V_14 -> V_7 . V_8 )
return F_9 ( V_6 , V_14 ) ;
if ( ( V_14 -> V_14 & 0x3 ) != 0 || V_14 -> V_14 >= F_7 ( V_6 -> V_19 , 0 ) )
return - V_9 ;
F_12 ( V_14 -> V_14 , V_14 -> V_18 ) ;
return 0 ;
}
