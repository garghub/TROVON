static struct V_1 * F_1 ( struct V_2 * V_3 , int V_4 )
{
struct V_5 * V_6 = F_2 ( V_3 ) ;
struct V_7 * V_8 ;
struct V_9 * V_10 ;
struct V_1 * V_1 = NULL ;
V_8 = V_6 -> V_11 + F_3 ( V_4 ) ;
F_4 ( & V_6 -> V_12 ) ;
F_5 (i, head, i_dir_hash) {
F_6 ( V_10 -> V_13 . V_14 != V_3 ) ;
if ( V_10 -> V_4 != V_4 )
continue;
V_1 = F_7 ( & V_10 -> V_13 ) ;
if ( V_1 )
break;
}
F_8 ( & V_6 -> V_12 ) ;
return V_1 ;
}
static struct V_1 * F_9 ( struct V_2 * V_3 ,
T_1 V_15 , T_2 V_16 )
{
struct V_1 * V_1 ;
if ( ( V_15 < V_17 ) || ( V_15 == V_18 ) )
return NULL ;
V_1 = F_10 ( V_3 , V_15 ) ;
if ( V_1 && V_16 && ( V_1 -> V_19 != V_16 ) ) {
F_11 ( V_1 ) ;
V_1 = NULL ;
}
return V_1 ;
}
struct V_20 * F_12 ( struct V_2 * V_3 , struct V_21 * V_21 ,
int V_22 , int V_23 )
{
return F_13 ( V_3 , V_21 , V_22 , V_23 ,
F_9 ) ;
}
struct V_20 * F_14 ( struct V_2 * V_3 , struct V_21 * V_21 ,
int V_22 , int V_23 )
{
return F_15 ( V_3 , V_21 , V_22 , V_23 ,
F_9 ) ;
}
struct V_20 * F_16 ( struct V_20 * V_24 )
{
struct V_2 * V_3 = V_24 -> V_25 ;
struct V_26 * V_27 = NULL ;
struct V_28 * V_29 ;
struct V_1 * V_30 = NULL ;
if ( ! F_17 ( V_24 -> V_31 , & V_27 , & V_29 ) ) {
int V_32 = F_18 ( F_2 ( V_3 ) , V_29 ) ;
V_30 = F_1 ( V_3 , V_32 ) ;
}
F_19 ( V_27 ) ;
return F_20 ( V_30 ) ;
}
