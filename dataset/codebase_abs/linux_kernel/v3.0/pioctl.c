static int F_1 ( struct V_1 * V_1 , int V_2 , unsigned int V_3 )
{
return ( V_2 & V_4 ) ? - V_5 : 0 ;
}
static long F_2 ( struct V_6 * V_7 , unsigned int V_8 ,
unsigned long V_9 )
{
struct V_10 V_10 ;
int error ;
struct V_11 V_12 ;
struct V_1 * V_1 = V_7 -> V_13 -> V_14 ;
struct V_1 * V_15 = NULL ;
struct V_16 * V_17 ;
if ( F_3 ( & V_12 , ( void V_18 * ) V_9 , sizeof( V_12 ) ) )
return - V_19 ;
if ( V_12 . V_20 )
error = F_4 ( V_12 . V_10 , & V_10 ) ;
else
error = F_5 ( V_12 . V_10 , & V_10 ) ;
if ( error )
return error ;
V_15 = V_10 . V_21 -> V_14 ;
if ( V_15 -> V_22 != V_1 -> V_22 ) {
error = - V_19 ;
goto V_23;
}
V_17 = F_6 ( V_15 ) ;
error = F_7 ( V_1 -> V_22 , & ( V_17 -> V_24 ) , V_8 , & V_12 ) ;
V_23:
F_8 ( & V_10 ) ;
return error ;
}
