static void F_1 ( struct V_1 * V_2 ,
struct V_3 * * V_4 )
{
const T_1 * V_5 , * V_6 , * V_7 ;
const T_1 * V_8 , * V_9 ;
struct V_10 * V_11 = & ( * V_4 ) -> V_11 ;
V_11 -> V_12 = F_2 ( V_2 , L_1 , NULL ) ;
V_5 = F_2 ( V_2 , L_2 , NULL ) ;
if ( V_5 )
V_11 -> V_5 = F_3 ( * V_5 ) ;
V_6 = F_2 ( V_2 , L_3 , NULL ) ;
if ( V_6 )
V_11 -> V_6 = F_3 ( * V_6 ) ;
if ( V_11 -> V_5 != V_11 -> V_6 )
V_11 -> V_13 |= V_14 ;
if ( V_5 && V_6 && V_11 -> V_5 == V_11 -> V_6 )
V_11 -> V_15 = true ;
V_7 = F_2 ( V_2 , L_4 , NULL ) ;
if ( V_7 )
V_11 -> V_7 = F_3 ( * V_7 ) ;
V_8 = F_2 ( V_2 , L_5 , NULL ) ;
if ( V_8 )
V_11 -> V_8 = F_3 ( * V_8 ) ;
V_9 = F_2 ( V_2 , L_6 , NULL ) ;
if ( V_9 )
V_11 -> V_9 = F_3 ( * V_9 ) ;
if ( V_11 -> V_8 != V_11 -> V_9 )
V_11 -> V_13 |= V_16 ;
if ( F_4 ( V_2 , L_7 , NULL ) )
V_11 -> V_17 = true ;
if ( F_4 ( V_2 , L_8 , NULL ) )
V_11 -> V_18 = true ;
else
V_11 -> V_13 |= V_19 ;
}
struct V_3 * F_5 ( struct V_20 * V_21 ,
struct V_1 * V_22 )
{
struct V_3 * V_4 ;
if ( ! V_22 )
return NULL ;
V_4 = F_6 ( V_21 , sizeof( * V_4 ) , V_23 ) ;
if ( ! V_4 )
return NULL ;
F_1 ( V_22 , & V_4 ) ;
return V_4 ;
}
