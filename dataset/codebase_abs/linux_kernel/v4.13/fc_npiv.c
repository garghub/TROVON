struct V_1 * F_1 ( struct V_2 * V_3 , int V_4 )
{
struct V_5 * V_6 = F_2 ( V_3 ) ;
struct V_1 * V_7 = F_3 ( V_6 ) ;
struct V_1 * V_8 ;
V_8 = F_4 ( V_6 -> V_9 , V_4 ) ;
if ( ! V_8 )
return V_8 ;
V_8 -> V_3 = V_3 ;
V_3 -> V_10 = V_8 ;
F_5 ( & V_7 -> V_11 ) ;
F_6 ( & V_8 -> V_12 , & V_7 -> V_13 ) ;
F_7 ( & V_7 -> V_11 ) ;
return V_8 ;
}
struct V_1 * F_8 ( struct V_1 * V_7 , T_1 V_14 )
{
struct V_1 * V_15 = NULL ;
struct V_1 * V_8 ;
if ( V_7 -> V_14 == V_14 )
return V_7 ;
if ( V_14 == V_16 )
return V_7 ;
F_5 ( & V_7 -> V_11 ) ;
F_9 (vn_port, &n_port->vports, list) {
if ( V_8 -> V_14 == V_14 ) {
V_15 = V_8 ;
break;
}
}
F_7 ( & V_7 -> V_11 ) ;
return V_15 ;
}
static void F_10 ( struct V_1 * V_7 ,
struct V_1 * V_8 )
{
struct V_2 * V_3 = V_8 -> V_3 ;
if ( V_8 -> V_17 == V_18 )
return;
if ( V_7 -> V_17 == V_19 ) {
if ( V_7 -> V_20 ) {
F_11 ( V_3 , V_21 ) ;
F_12 ( V_8 ) ;
} else {
F_11 ( V_3 , V_22 ) ;
F_13 ( V_8 ) ;
}
} else {
F_11 ( V_3 , V_23 ) ;
F_13 ( V_8 ) ;
}
}
void F_14 ( struct V_1 * V_8 )
{
struct V_2 * V_3 = V_8 -> V_3 ;
struct V_5 * V_6 = F_2 ( V_3 ) ;
struct V_1 * V_7 = F_3 ( V_6 ) ;
F_5 ( & V_7 -> V_11 ) ;
F_15 ( & V_8 -> V_11 , V_24 ) ;
F_10 ( V_7 , V_8 ) ;
F_7 ( & V_8 -> V_11 ) ;
F_7 ( & V_7 -> V_11 ) ;
}
void F_16 ( struct V_1 * V_7 )
{
struct V_1 * V_8 ;
F_9 (vn_port, &n_port->vports, list) {
F_15 ( & V_8 -> V_11 , V_24 ) ;
F_10 ( V_7 , V_8 ) ;
F_7 ( & V_8 -> V_11 ) ;
}
}
