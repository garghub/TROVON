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
struct V_1 * V_1 = F_3 ( V_6 ) ;
struct V_1 * V_12 = NULL ;
struct V_13 * V_14 ;
if ( F_4 ( & V_11 , ( void V_15 * ) V_8 , sizeof( V_11 ) ) )
return - V_16 ;
if ( V_11 . V_17 )
error = F_5 ( V_11 . V_9 , & V_9 ) ;
else
error = F_6 ( V_11 . V_9 , & V_9 ) ;
if ( error )
return error ;
V_12 = V_9 . V_18 -> V_19 ;
if ( V_12 -> V_20 != V_1 -> V_20 ) {
error = - V_16 ;
goto V_21;
}
V_14 = F_7 ( V_12 ) ;
error = F_8 ( V_1 -> V_20 , & ( V_14 -> V_22 ) , V_7 , & V_11 ) ;
V_21:
F_9 ( & V_9 ) ;
return error ;
}
