int
F_1 ( struct V_1 * V_2 , bool V_3 )
{
struct V_4 * V_5 = ( void * ) V_2 ;
F_2 ( L_1 ) ;
V_5 -> V_6 = NULL ;
return F_3 ( & V_5 -> V_7 , V_3 ) ;
}
int
F_4 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = ( void * ) V_2 ;
F_2 ( L_2 , V_5 -> V_8 -> V_9 ) ;
V_5 -> V_6 = V_5 -> V_8 ;
return F_5 ( & V_5 -> V_7 ) ;
}
int
F_6 ( struct V_1 * V_10 ,
struct V_1 * V_11 ,
struct V_12 * V_13 , int V_9 ,
int V_14 , void * * V_15 )
{
struct V_16 * V_17 = V_16 ( V_10 ) ;
struct V_18 * V_6 ;
struct V_4 * V_5 ;
int V_19 ;
F_7 (port, &i2c->ports, head) {
V_5 = V_4 ( V_6 ) ;
if ( V_5 -> V_9 == V_9 ) {
F_8 ( & F_9 ( V_5 ) -> V_20 ) ;
* V_15 = V_5 ;
return 1 ;
}
}
V_19 = F_10 ( V_10 , V_11 , V_13 , 0 , V_14 , V_15 ) ;
V_5 = * V_15 ;
if ( V_19 )
return V_19 ;
V_5 -> V_9 = V_9 ;
return 0 ;
}
int
F_11 ( struct V_1 * V_10 , struct V_1 * V_11 ,
struct V_12 * V_13 , void * V_21 , T_1 V_9 ,
struct V_1 * * V_15 )
{
struct V_4 * V_5 ;
int V_19 ;
V_19 = F_12 ( V_10 , V_11 , V_13 , V_9 , & V_5 ) ;
* V_15 = F_9 ( V_5 ) ;
return V_19 ;
}
