static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 -> V_5 ) ;
struct V_1 * V_6 ;
V_6 = F_3 ( V_4 ) ;
if ( V_6 ) {
F_4 ( V_6 , V_2 ) ;
F_5 ( V_6 ) ;
}
if ( V_2 -> V_7 == V_8 )
V_2 -> V_7 = V_9 ;
}
static int F_6 ( struct V_1 * V_2 )
{
int V_10 ;
V_10 = F_7 ( V_2 ) ;
if ( V_10 < 0 )
return V_10 ;
V_10 = F_8 ( V_2 ) ;
if ( V_10 < 0 )
F_9 ( V_2 ) ;
return V_10 ;
}
static void F_10 ( struct V_1 * V_2 )
{
F_9 ( V_2 ) ;
}
static void F_11 ( struct V_1 * V_2 )
{
F_12 ( V_2 ) ;
F_13 ( V_2 ) ;
}
static void F_14 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 -> V_5 ) ;
struct V_1 * V_6 ;
V_6 = F_3 ( V_4 ) ;
if ( V_6 != V_2 )
goto V_11;
F_11 ( V_2 ) ;
V_11:
if ( V_6 )
F_5 ( V_6 ) ;
}
static void
F_15 ( struct V_12 * V_13 )
{
F_16 ( & V_13 -> V_14 . V_15 ) ;
F_17 ( & V_13 -> V_14 . V_16 ,
V_17 ) ;
}
static void
F_18 ( struct V_18 * V_19 ,
struct V_1 * V_20 ,
struct V_21 * V_22 )
{
struct V_23 * V_24 ;
struct V_25 * V_26 ;
F_19 (neigh_node, &orig_node->neigh_list, list) {
V_26 = F_20 ( V_24 , V_20 ) ;
if ( ! V_26 )
continue;
F_21 ( V_22 , L_1 ,
V_24 -> V_27 ,
V_26 -> V_14 . V_15 / 10 ,
V_26 -> V_14 . V_15 % 10 ) ;
F_22 ( V_26 ) ;
}
}
static void
F_23 ( struct V_21 * V_22 ,
struct V_12 * V_13 )
{
int V_28 , V_29 ;
T_1 V_15 ;
V_28 = F_24 ( V_30 - V_13 -> V_31 ) / 1000 ;
V_29 = F_24 ( V_30 - V_13 -> V_31 ) % 1000 ;
V_15 = F_25 ( & V_13 -> V_14 . V_15 ) ;
F_21 ( V_22 , L_2 ,
V_13 -> V_27 , V_28 , V_29 , V_15 / 10 ,
V_15 % 10 , V_13 -> V_32 -> V_33 -> V_34 ) ;
}
static void F_26 ( struct V_3 * V_4 ,
struct V_21 * V_22 )
{
struct V_35 * V_33 = (struct V_35 * ) V_22 -> V_36 ;
struct V_12 * V_13 ;
struct V_1 * V_2 ;
int V_37 = 0 ;
F_27 ( V_22 ,
L_3 ) ;
F_28 () ;
F_29 (hard_iface, &batadv_hardif_list, list) {
if ( V_2 -> V_5 != V_33 )
continue;
F_19 (hardif_neigh,
&hard_iface->neigh_list, list) {
F_23 ( V_22 , V_13 ) ;
V_37 ++ ;
}
}
F_30 () ;
if ( V_37 == 0 )
F_27 ( V_22 , L_4 ) ;
}
static void F_31 ( struct V_3 * V_4 ,
struct V_21 * V_22 ,
struct V_1 * V_20 )
{
struct V_23 * V_24 ;
struct V_38 * V_39 = V_4 -> V_40 ;
int V_41 , V_42 ;
struct V_18 * V_19 ;
struct V_25 * V_26 ;
unsigned long V_43 ;
struct V_44 * V_45 ;
int V_37 = 0 ;
T_1 V_46 ;
F_27 ( V_22 ,
L_5 ) ;
for ( V_46 = 0 ; V_46 < V_39 -> V_47 ; V_46 ++ ) {
V_45 = & V_39 -> V_48 [ V_46 ] ;
F_28 () ;
F_19 (orig_node, head, hash_entry) {
V_24 = F_32 ( V_19 ,
V_20 ) ;
if ( ! V_24 )
continue;
V_26 = F_20 ( V_24 ,
V_20 ) ;
if ( ! V_26 )
goto V_49;
V_43 = V_30 - V_19 -> V_31 ;
V_41 = F_24 ( V_43 ) ;
V_42 = V_41 / 1000 ;
V_41 = V_41 % 1000 ;
F_21 ( V_22 , L_6 ,
V_19 -> V_50 , V_42 ,
V_41 ,
V_26 -> V_14 . V_15 / 10 ,
V_26 -> V_14 . V_15 % 10 ,
V_24 -> V_27 ,
V_24 -> V_32 -> V_33 -> V_34 ) ;
F_18 ( V_19 , V_20 , V_22 ) ;
F_27 ( V_22 , L_7 ) ;
V_37 ++ ;
V_49:
F_33 ( V_24 ) ;
if ( V_26 )
F_22 ( V_26 ) ;
}
F_30 () ;
}
if ( V_37 == 0 )
F_27 ( V_22 , L_4 ) ;
}
static int F_34 ( struct V_23 * V_51 ,
struct V_1 * V_52 ,
struct V_23 * V_53 ,
struct V_1 * V_54 )
{
struct V_25 * V_55 , * V_56 ;
int V_10 = 0 ;
V_55 = F_20 ( V_51 , V_52 ) ;
if ( F_35 ( ! V_55 ) )
goto V_57;
V_56 = F_20 ( V_53 , V_54 ) ;
if ( F_35 ( ! V_56 ) )
goto V_58;
V_10 = V_55 -> V_14 . V_15 - V_56 -> V_14 . V_15 ;
F_22 ( V_56 ) ;
V_58:
F_22 ( V_55 ) ;
V_57:
return V_10 ;
}
static bool F_36 ( struct V_23 * V_51 ,
struct V_1 * V_52 ,
struct V_23 * V_53 ,
struct V_1 * V_54 )
{
struct V_25 * V_55 , * V_56 ;
T_1 V_59 ;
bool V_10 = false ;
V_55 = F_20 ( V_51 , V_52 ) ;
if ( F_35 ( ! V_55 ) )
goto V_57;
V_56 = F_20 ( V_53 , V_54 ) ;
if ( F_35 ( ! V_56 ) )
goto V_58;
V_59 = V_55 -> V_14 . V_15 / 4 ;
V_59 = V_55 -> V_14 . V_15 - V_59 ;
V_10 = V_56 -> V_14 . V_15 > V_59 ;
F_22 ( V_56 ) ;
V_58:
F_22 ( V_55 ) ;
V_57:
return V_10 ;
}
void F_37 ( struct V_1 * V_2 )
{
F_38 ( & V_2 -> V_14 . V_60 , 0 ) ;
F_38 ( & V_2 -> V_14 . V_61 , 500 ) ;
}
int F_39 ( struct V_3 * V_4 )
{
return F_40 ( V_4 ) ;
}
void F_41 ( struct V_3 * V_4 )
{
F_42 ( V_4 ) ;
}
int T_2 F_43 ( void )
{
int V_10 ;
V_10 = F_44 ( V_62 ,
V_63 ) ;
if ( V_10 < 0 )
return V_10 ;
V_10 = F_44 ( V_64 ,
V_65 ) ;
if ( V_10 < 0 )
goto V_66;
V_10 = F_45 ( & V_67 ) ;
if ( V_10 < 0 )
goto V_68;
return V_10 ;
V_68:
F_46 ( V_64 ) ;
V_66:
F_46 ( V_62 ) ;
return V_10 ;
}
