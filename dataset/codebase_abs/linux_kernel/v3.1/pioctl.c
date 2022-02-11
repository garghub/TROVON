static int F_1 ( struct V_1 * V_1 , int V_2 )
{
return ( V_2 & V_3 ) ? - V_4 : 0 ;
}
static long F_2 ( struct V_5 * V_6 , unsigned int V_7 ,
unsigned long V_8 )
{
struct V_9 V_9 ;
int error ;
struct V_10 V_11 ;
struct V_1 * V_1 = V_6 -> V_12 -> V_13 ;
struct V_1 * V_14 = NULL ;
struct V_15 * V_16 ;
if ( F_3 ( & V_11 , ( void V_17 * ) V_8 , sizeof( V_11 ) ) )
return - V_18 ;
if ( V_11 . V_19 )
error = F_4 ( V_11 . V_9 , & V_9 ) ;
else
error = F_5 ( V_11 . V_9 , & V_9 ) ;
if ( error )
return error ;
V_14 = V_9 . V_20 -> V_13 ;
if ( V_14 -> V_21 != V_1 -> V_21 ) {
error = - V_18 ;
goto V_22;
}
V_16 = F_6 ( V_14 ) ;
error = F_7 ( V_1 -> V_21 , & ( V_16 -> V_23 ) , V_7 , & V_11 ) ;
V_22:
F_8 ( & V_9 ) ;
return error ;
}
