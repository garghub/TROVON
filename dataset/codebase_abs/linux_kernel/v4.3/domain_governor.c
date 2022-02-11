static int F_1 ( struct V_1 * V_2 , void * V_3 )
{
T_1 * V_4 = V_3 ;
T_2 V_5 = - 1 ;
if ( V_2 -> V_6 . V_7 && V_2 -> V_6 . V_7 -> V_8 )
V_5 = F_2 ( V_2 ) -> V_9 . V_10 ;
if ( V_5 < 0 ) {
V_5 = F_3 ( V_2 ) ;
V_5 *= V_11 ;
}
if ( V_5 == 0 )
return 0 ;
if ( V_5 < * V_4 || * V_4 == 0 )
* V_4 = V_5 ;
return 0 ;
}
static bool F_4 ( struct V_1 * V_2 )
{
struct V_12 * V_9 = & F_2 ( V_2 ) -> V_9 ;
unsigned long V_13 ;
T_1 V_5 ;
F_5 ( V_2 , L_1 , V_14 ) ;
F_6 ( & V_2 -> V_6 . V_15 , V_13 ) ;
if ( ! V_9 -> V_16 ) {
bool V_17 = V_9 -> V_18 ;
F_7 ( & V_2 -> V_6 . V_15 , V_13 ) ;
return V_17 ;
}
V_9 -> V_16 = false ;
V_9 -> V_18 = false ;
V_9 -> V_10 = - 1 ;
V_5 = F_8 ( V_2 ) ;
F_7 ( & V_2 -> V_6 . V_15 , V_13 ) ;
if ( V_5 < 0 )
return false ;
V_5 *= V_11 ;
if ( ! V_2 -> V_6 . V_19 )
F_9 ( V_2 , & V_5 ,
F_1 ) ;
if ( V_5 > 0 ) {
V_5 -= V_9 -> V_20 +
V_9 -> V_21 +
V_9 -> V_22 +
V_9 -> V_23 ;
if ( V_5 == 0 )
return false ;
}
V_9 -> V_10 = V_5 ;
V_9 -> V_18 = V_5 >= 0 ;
return V_9 -> V_18 ;
}
static bool F_10 ( struct V_24 * V_25 )
{
struct V_26 * V_27 = F_11 ( V_25 ) ;
struct V_28 * V_29 ;
struct V_30 * V_31 ;
T_1 V_32 ;
T_1 V_33 ;
if ( V_27 -> V_34 ) {
struct V_28 * V_29 ;
F_12 (link, &genpd->slave_links, slave_node)
V_29 -> V_35 -> V_34 = true ;
V_27 -> V_34 = false ;
V_27 -> V_36 = false ;
V_27 -> V_37 = - 1 ;
} else {
return V_27 -> V_36 ;
}
V_33 = V_27 -> V_38 +
V_27 -> V_39 ;
V_32 = - 1 ;
F_12 (link, &genpd->master_links, master_node) {
struct V_26 * V_40 = V_29 -> V_41 ;
T_1 V_42 = V_40 -> V_37 ;
if ( V_42 < 0 )
continue;
if ( V_42 <= V_33 )
return false ;
if ( V_32 > V_42 || V_32 < 0 )
V_32 = V_42 ;
}
F_12 (pdd, &genpd->dev_list, list_node) {
struct V_12 * V_9 ;
T_1 V_5 ;
if ( ! V_31 -> V_2 -> V_43 )
continue;
V_9 = & F_13 ( V_31 ) -> V_9 ;
V_5 = V_9 -> V_10 ;
if ( V_5 < 0 ) {
V_5 = F_3 ( V_31 -> V_2 ) ;
V_5 *= V_11 ;
}
if ( V_5 == 0 )
continue;
if ( V_5 <= V_33 )
return false ;
if ( V_32 > V_5 || V_32 < 0 )
V_32 = V_5 ;
}
V_27 -> V_36 = true ;
if ( V_32 < 0 )
return true ;
V_27 -> V_37 = V_32 - V_27 -> V_39 ;
return true ;
}
static bool F_14 ( struct V_24 * V_44 )
{
return false ;
}
