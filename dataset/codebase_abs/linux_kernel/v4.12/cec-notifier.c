struct V_1 * F_1 ( struct V_2 * V_3 )
{
struct V_1 * V_4 ;
F_2 ( & V_5 ) ;
F_3 (n, &cec_notifiers, head) {
if ( V_4 -> V_3 == V_3 ) {
F_4 ( & V_4 -> V_6 ) ;
F_5 ( & V_5 ) ;
return V_4 ;
}
}
V_4 = F_6 ( sizeof( * V_4 ) , V_7 ) ;
if ( ! V_4 )
goto V_8;
V_4 -> V_3 = V_3 ;
V_4 -> V_9 = V_10 ;
F_7 ( & V_4 -> V_11 ) ;
F_8 ( & V_4 -> V_6 ) ;
F_9 ( & V_4 -> V_12 , & V_13 ) ;
V_8:
F_5 ( & V_5 ) ;
return V_4 ;
}
static void F_10 ( struct V_6 * V_6 )
{
struct V_1 * V_4 =
F_11 ( V_6 , struct V_1 , V_6 ) ;
F_12 ( & V_4 -> V_12 ) ;
F_13 ( V_4 ) ;
}
void F_14 ( struct V_1 * V_4 )
{
F_2 ( & V_5 ) ;
F_15 ( & V_4 -> V_6 , F_10 ) ;
F_5 ( & V_5 ) ;
}
void F_16 ( struct V_1 * V_4 , T_1 V_14 )
{
F_2 ( & V_4 -> V_11 ) ;
V_4 -> V_9 = V_14 ;
if ( V_4 -> V_15 )
V_4 -> V_15 ( V_4 -> V_16 , V_4 -> V_9 ) ;
F_5 ( & V_4 -> V_11 ) ;
}
void F_17 ( struct V_1 * V_4 ,
const struct V_17 * V_17 )
{
T_1 V_14 = V_10 ;
if ( V_17 && V_17 -> V_18 )
V_14 = F_18 ( ( const V_19 * ) V_17 ,
V_20 * ( V_17 -> V_18 + 1 ) , NULL ) ;
F_16 ( V_4 , V_14 ) ;
}
void F_19 ( struct V_1 * V_4 ,
struct V_21 * V_22 ,
void (* V_15)( struct V_21 * V_22 , T_1 V_14 ) )
{
F_4 ( & V_4 -> V_6 ) ;
F_2 ( & V_4 -> V_11 ) ;
V_4 -> V_16 = V_22 ;
V_4 -> V_15 = V_15 ;
V_4 -> V_15 ( V_22 , V_4 -> V_9 ) ;
F_5 ( & V_4 -> V_11 ) ;
}
void F_20 ( struct V_1 * V_4 )
{
F_2 ( & V_4 -> V_11 ) ;
V_4 -> V_15 = NULL ;
F_5 ( & V_4 -> V_11 ) ;
F_14 ( V_4 ) ;
}
