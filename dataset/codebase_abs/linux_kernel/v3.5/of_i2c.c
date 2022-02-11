void F_1 ( struct V_1 * V_2 )
{
void * V_3 ;
struct V_4 * V_5 ;
if ( ! V_2 -> V_6 . V_7 )
return;
F_2 ( & V_2 -> V_6 , L_1 ) ;
F_3 (adap->dev.of_node, node) {
struct V_8 V_9 = {} ;
struct V_10 V_11 = {} ;
const T_1 * V_12 ;
int V_13 ;
F_2 ( & V_2 -> V_6 , L_2 , V_5 -> V_14 ) ;
if ( F_4 ( V_5 , V_9 . type , sizeof( V_9 . type ) ) < 0 ) {
F_5 ( & V_2 -> V_6 , L_3 ,
V_5 -> V_14 ) ;
continue;
}
V_12 = F_6 ( V_5 , L_4 , & V_13 ) ;
if ( ! V_12 || ( V_13 < sizeof( int ) ) ) {
F_5 ( & V_2 -> V_6 , L_5 ,
V_5 -> V_14 ) ;
continue;
}
V_9 . V_12 = F_7 ( V_12 ) ;
if ( V_9 . V_12 > ( 1 << 10 ) - 1 ) {
F_5 ( & V_2 -> V_6 , L_6 ,
V_9 . V_12 , V_5 -> V_14 ) ;
continue;
}
V_9 . V_15 = F_8 ( V_5 , 0 ) ;
V_9 . V_7 = F_9 ( V_5 ) ;
V_9 . V_16 = & V_11 ;
F_10 ( L_7 , V_17 , V_9 . type ) ;
V_3 = F_11 ( V_2 , & V_9 ) ;
if ( V_3 == NULL ) {
F_5 ( & V_2 -> V_6 , L_8 ,
V_5 -> V_14 ) ;
F_12 ( V_5 ) ;
F_13 ( V_9 . V_15 ) ;
continue;
}
}
}
static int F_14 ( struct V_18 * V_6 , void * V_19 )
{
return V_6 -> V_7 == V_19 ;
}
struct V_20 * F_15 ( struct V_4 * V_5 )
{
struct V_18 * V_6 ;
V_6 = F_16 ( & V_21 , NULL , V_5 ,
F_14 ) ;
if ( ! V_6 )
return NULL ;
return F_17 ( V_6 ) ;
}
struct V_1 * F_18 ( struct V_4 * V_5 )
{
struct V_18 * V_6 ;
V_6 = F_16 ( & V_21 , NULL , V_5 ,
F_14 ) ;
if ( ! V_6 )
return NULL ;
return F_19 ( V_6 ) ;
}
