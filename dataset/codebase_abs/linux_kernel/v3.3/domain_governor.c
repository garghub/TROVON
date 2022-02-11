bool F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = & F_2 ( V_2 ) -> V_4 ;
F_3 ( V_2 , L_1 , V_5 ) ;
if ( V_2 -> V_6 . V_7 < 0 || V_4 -> V_8 == 0 )
return true ;
return V_4 -> V_9 + V_4 -> V_10 < V_4 -> V_8
&& V_4 -> V_8 < V_2 -> V_6 . V_7 ;
}
static bool F_4 ( struct V_11 * V_12 )
{
struct V_13 * V_14 = F_5 ( V_12 ) ;
struct V_15 * V_16 ;
struct V_17 * V_18 ;
T_1 V_19 ;
T_1 V_20 ;
T_2 V_21 = F_6 () ;
V_20 = V_14 -> V_22 +
V_14 -> V_23 ;
F_7 (pdd, &genpd->dev_list, list_node) {
if ( V_18 -> V_2 -> V_24 )
V_20 +=
F_8 ( V_18 ) -> V_4 . V_25 ;
}
F_7 (link, &genpd->master_links, master_node) {
struct V_13 * V_26 = V_16 -> V_27 ;
T_1 V_28 = V_26 -> V_29 ;
if ( V_28 < 0 )
continue;
V_28 -= F_9 ( F_10 ( V_21 ,
V_26 -> V_30 ) ) ;
if ( V_28 <= V_20 )
return false ;
}
V_19 = - 1 ;
F_7 (pdd, &genpd->dev_list, list_node) {
struct V_3 * V_4 ;
struct V_1 * V_2 = V_18 -> V_2 ;
T_1 V_31 ;
if ( ! V_2 -> V_24 || V_2 -> V_6 . V_7 < 0 )
continue;
V_4 = & F_8 ( V_18 ) -> V_4 ;
V_31 = V_2 -> V_6 . V_7 -
( V_4 -> V_10 + V_4 -> V_32 +
F_9 ( F_10 ( V_21 ,
V_2 -> V_6 . V_33 ) ) ) ;
if ( V_31 <= V_20 )
return false ;
if ( V_19 > V_31
|| V_19 < 0 )
V_19 = V_31 ;
}
if ( V_19 < 0 ) {
V_14 -> V_29 = - 1 ;
return true ;
}
V_19 -= V_14 -> V_23 ;
if ( V_14 -> V_8 >
V_19 - V_14 -> V_22 )
return false ;
V_14 -> V_29 = V_19 ;
return true ;
}
static bool F_11 ( struct V_11 * V_34 )
{
return false ;
}
bool F_1 ( struct V_1 * V_2 )
{
return false ;
}
