static struct V_1 * F_1 ( struct V_2 * V_3 , int V_4 )
{
struct V_5 * V_6 = F_2 ( V_3 ) ;
struct V_7 * V_8 ;
struct V_9 * V_10 ;
struct V_11 * V_12 ;
struct V_1 * V_1 = NULL ;
V_8 = V_6 -> V_13 + F_3 ( V_4 ) ;
F_4 ( & V_6 -> V_14 ) ;
F_5 (i, _p, head, i_dir_hash) {
F_6 ( V_12 -> V_15 . V_16 != V_3 ) ;
if ( V_12 -> V_4 != V_4 )
continue;
V_1 = F_7 ( & V_12 -> V_15 ) ;
if ( V_1 )
break;
}
F_8 ( & V_6 -> V_14 ) ;
return V_1 ;
}
static struct V_1 * F_9 ( struct V_2 * V_3 ,
T_1 V_17 , T_2 V_18 )
{
struct V_1 * V_1 ;
if ( ( V_17 < V_19 ) || ( V_17 == V_20 ) )
return NULL ;
V_1 = F_10 ( V_3 , V_17 ) ;
if ( V_1 && V_18 && ( V_1 -> V_21 != V_18 ) ) {
F_11 ( V_1 ) ;
V_1 = NULL ;
}
return V_1 ;
}
struct V_22 * F_12 ( struct V_2 * V_3 , struct V_23 * V_23 ,
int V_24 , int V_25 )
{
return F_13 ( V_3 , V_23 , V_24 , V_25 ,
F_9 ) ;
}
struct V_22 * F_14 ( struct V_2 * V_3 , struct V_23 * V_23 ,
int V_24 , int V_25 )
{
return F_15 ( V_3 , V_23 , V_24 , V_25 ,
F_9 ) ;
}
struct V_22 * F_16 ( struct V_22 * V_26 )
{
struct V_2 * V_3 = V_26 -> V_27 ;
struct V_28 * V_29 = NULL ;
struct V_30 * V_31 ;
struct V_1 * V_32 = NULL ;
if ( ! F_17 ( V_26 -> V_33 , & V_29 , & V_31 ) ) {
int V_34 = F_18 ( F_2 ( V_3 ) , V_31 ) ;
V_32 = F_1 ( V_3 , V_34 ) ;
}
F_19 ( V_29 ) ;
return F_20 ( V_32 ) ;
}
