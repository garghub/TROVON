static struct V_1 * F_1 ( struct V_2 * V_3 ,
struct V_4 * V_5 )
{
T_1 V_6 = V_3 -> args [ 0 ] ;
T_2 V_7 ;
struct V_1 * V_8 ;
if ( V_3 -> V_9 != 1 )
return NULL ;
F_2 ( V_7 ) ;
F_3 ( V_10 , V_7 ) ;
V_8 = F_4 ( V_7 , V_11 , ( void * ) V_6 ) ;
if ( V_8 )
F_5 ( V_8 ) -> V_12 = V_6 ;
return V_8 ;
}
static int F_6 ( struct V_13 * V_14 )
{
const struct V_15 * V_16 = V_14 -> V_17 . V_18 ;
int V_19 ;
if ( ! V_16 )
return - V_20 ;
V_19 = F_7 ( V_14 -> V_17 . V_21 ,
F_1 , V_14 ) ;
if ( V_19 < 0 )
return V_19 ;
V_19 = F_8 ( V_14 -> V_17 . V_21 , NULL , V_16 , & V_14 -> V_17 ) ;
if ( V_19 < 0 )
F_9 ( V_14 -> V_17 . V_21 ) ;
return V_19 ;
}
