static void F_1 ( struct V_1 * V_2 )
{
if ( V_2 -> V_3 == V_4 )
V_2 -> V_3 = V_5 ;
}
static int F_2 ( struct V_1 * V_2 )
{
int V_6 ;
V_6 = F_3 ( V_2 ) ;
if ( V_6 < 0 )
return V_6 ;
V_6 = F_4 ( V_2 ) ;
if ( V_6 < 0 )
F_5 ( V_2 ) ;
F_6 ( & V_2 -> V_7 . V_8 , 0 ) ;
return V_6 ;
}
static void F_7 ( struct V_1 * V_2 )
{
F_5 ( V_2 ) ;
}
static void F_8 ( struct V_1 * V_2 )
{
}
static void F_9 ( struct V_1 * V_2 )
{
F_10 ( V_2 ) ;
F_11 ( V_2 ) ;
}
static void
F_12 ( struct V_9 * V_10 )
{
F_13 ( & V_10 -> V_7 . V_11 ) ;
F_14 ( & V_10 -> V_7 . V_12 ,
V_13 ) ;
}
static void F_15 ( struct V_1 * V_2 )
{
}
static void F_16 ( struct V_14 * V_15 )
{
}
static void
F_17 ( struct V_16 * V_17 ,
struct V_1 * V_18 ,
struct V_19 * V_20 )
{
struct V_21 * V_22 ;
struct V_23 * V_24 ;
F_18 (neigh_node, &orig_node->neigh_list, list) {
V_24 = F_19 ( V_22 , V_18 ) ;
if ( ! V_24 )
continue;
F_20 ( V_20 , L_1 ,
V_22 -> V_25 ,
V_24 -> V_7 . V_11 / 10 ,
V_24 -> V_7 . V_11 % 10 ) ;
F_21 ( V_24 ) ;
}
}
static void
F_22 ( struct V_19 * V_20 ,
struct V_9 * V_10 )
{
int V_26 , V_27 ;
T_1 V_11 ;
V_26 = F_23 ( V_28 - V_10 -> V_29 ) / 1000 ;
V_27 = F_23 ( V_28 - V_10 -> V_29 ) % 1000 ;
V_11 = F_24 ( & V_10 -> V_7 . V_11 ) ;
F_20 ( V_20 , L_2 ,
V_10 -> V_25 , V_26 , V_27 , V_11 / 10 ,
V_11 % 10 , V_10 -> V_30 -> V_31 -> V_32 ) ;
}
static void F_25 ( struct V_33 * V_34 ,
struct V_19 * V_20 )
{
struct V_35 * V_31 = (struct V_35 * ) V_20 -> V_36 ;
struct V_9 * V_10 ;
struct V_1 * V_2 ;
int V_37 = 0 ;
F_20 ( V_20 , L_3 , L_4 ,
L_5 , L_6 , L_7 ) ;
F_26 () ;
F_27 (hard_iface, &batadv_hardif_list, list) {
if ( V_2 -> V_38 != V_31 )
continue;
F_18 (hardif_neigh,
&hard_iface->neigh_list, list) {
F_22 ( V_20 , V_10 ) ;
V_37 ++ ;
}
}
F_28 () ;
if ( V_37 == 0 )
F_29 ( V_20 , L_8 ) ;
}
static void F_30 ( struct V_33 * V_34 ,
struct V_19 * V_20 ,
struct V_1 * V_18 )
{
struct V_21 * V_22 ;
struct V_39 * V_40 = V_34 -> V_41 ;
int V_42 , V_43 ;
struct V_16 * V_17 ;
struct V_23 * V_24 ;
unsigned long V_44 ;
struct V_45 * V_46 ;
int V_37 = 0 ;
T_1 V_47 ;
F_20 ( V_20 , L_9 ,
L_10 , L_5 , L_6 , L_11 ,
L_12 , L_13 ) ;
for ( V_47 = 0 ; V_47 < V_40 -> V_48 ; V_47 ++ ) {
V_46 = & V_40 -> V_49 [ V_47 ] ;
F_26 () ;
F_18 (orig_node, head, hash_entry) {
V_22 = F_31 ( V_17 ,
V_18 ) ;
if ( ! V_22 )
continue;
V_24 = F_19 ( V_22 ,
V_18 ) ;
if ( ! V_24 )
goto V_50;
V_44 = V_28 - V_17 -> V_29 ;
V_42 = F_23 ( V_44 ) ;
V_43 = V_42 / 1000 ;
V_42 = V_42 % 1000 ;
F_20 ( V_20 , L_14 ,
V_17 -> V_51 , V_43 ,
V_42 ,
V_24 -> V_7 . V_11 / 10 ,
V_24 -> V_7 . V_11 % 10 ,
V_22 -> V_25 ,
V_22 -> V_30 -> V_31 -> V_32 ) ;
F_17 ( V_17 , V_18 , V_20 ) ;
F_29 ( V_20 , L_15 ) ;
V_37 ++ ;
V_50:
F_32 ( V_22 ) ;
if ( V_24 )
F_21 ( V_24 ) ;
}
F_28 () ;
}
if ( V_37 == 0 )
F_29 ( V_20 , L_8 ) ;
}
static int F_33 ( struct V_21 * V_52 ,
struct V_1 * V_53 ,
struct V_21 * V_54 ,
struct V_1 * V_55 )
{
struct V_23 * V_56 , * V_57 ;
V_56 = F_19 ( V_52 , V_53 ) ;
V_57 = F_19 ( V_54 , V_55 ) ;
if ( F_34 ( ! V_56 || ! V_57 ) )
return 0 ;
return V_56 -> V_7 . V_11 - V_57 -> V_7 . V_11 ;
}
static bool F_35 ( struct V_21 * V_52 ,
struct V_1 * V_53 ,
struct V_21 * V_54 ,
struct V_1 * V_55 )
{
struct V_23 * V_56 , * V_57 ;
T_1 V_58 ;
V_56 = F_19 ( V_52 , V_53 ) ;
V_57 = F_19 ( V_54 , V_55 ) ;
V_58 = V_56 -> V_7 . V_11 / 4 ;
V_58 = V_56 -> V_7 . V_11 - V_58 ;
return V_57 -> V_7 . V_11 > V_58 ;
}
int F_36 ( struct V_33 * V_34 )
{
return F_37 ( V_34 ) ;
}
void F_38 ( struct V_33 * V_34 )
{
F_39 ( V_34 ) ;
}
int T_2 F_40 ( void )
{
int V_6 ;
V_6 = F_41 ( V_59 ,
V_60 ) ;
if ( V_6 < 0 )
return V_6 ;
V_6 = F_41 ( V_61 ,
V_62 ) ;
if ( V_6 < 0 )
goto V_63;
V_6 = F_42 ( & V_64 ) ;
if ( V_6 < 0 )
goto V_65;
return V_6 ;
V_65:
F_43 ( V_61 ) ;
V_63:
F_43 ( V_59 ) ;
return V_6 ;
}
