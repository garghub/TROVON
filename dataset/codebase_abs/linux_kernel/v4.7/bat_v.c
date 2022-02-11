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
F_10 ( & V_2 -> V_11 . V_12 , 0 ) ;
return V_10 ;
}
static void F_11 ( struct V_1 * V_2 )
{
F_9 ( V_2 ) ;
}
static void F_12 ( struct V_1 * V_2 )
{
F_13 ( V_2 ) ;
F_14 ( V_2 ) ;
}
static void F_15 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 -> V_5 ) ;
struct V_1 * V_6 ;
V_6 = F_3 ( V_4 ) ;
if ( V_6 != V_2 )
goto V_13;
F_12 ( V_2 ) ;
V_13:
if ( V_6 )
F_5 ( V_6 ) ;
}
static void
F_16 ( struct V_14 * V_15 )
{
F_17 ( & V_15 -> V_11 . V_16 ) ;
F_18 ( & V_15 -> V_11 . V_17 ,
V_18 ) ;
}
static void F_19 ( struct V_1 * V_2 )
{
}
static void F_20 ( struct V_19 * V_20 )
{
}
static void
F_21 ( struct V_21 * V_22 ,
struct V_1 * V_23 ,
struct V_24 * V_25 )
{
struct V_26 * V_27 ;
struct V_28 * V_29 ;
F_22 (neigh_node, &orig_node->neigh_list, list) {
V_29 = F_23 ( V_27 , V_23 ) ;
if ( ! V_29 )
continue;
F_24 ( V_25 , L_1 ,
V_27 -> V_30 ,
V_29 -> V_11 . V_16 / 10 ,
V_29 -> V_11 . V_16 % 10 ) ;
F_25 ( V_29 ) ;
}
}
static void
F_26 ( struct V_24 * V_25 ,
struct V_14 * V_15 )
{
int V_31 , V_32 ;
T_1 V_16 ;
V_31 = F_27 ( V_33 - V_15 -> V_34 ) / 1000 ;
V_32 = F_27 ( V_33 - V_15 -> V_34 ) % 1000 ;
V_16 = F_28 ( & V_15 -> V_11 . V_16 ) ;
F_24 ( V_25 , L_2 ,
V_15 -> V_30 , V_31 , V_32 , V_16 / 10 ,
V_16 % 10 , V_15 -> V_35 -> V_36 -> V_37 ) ;
}
static void F_29 ( struct V_3 * V_4 ,
struct V_24 * V_25 )
{
struct V_38 * V_36 = (struct V_38 * ) V_25 -> V_39 ;
struct V_14 * V_15 ;
struct V_1 * V_2 ;
int V_40 = 0 ;
F_30 ( V_25 ,
L_3 ) ;
F_31 () ;
F_32 (hard_iface, &batadv_hardif_list, list) {
if ( V_2 -> V_5 != V_36 )
continue;
F_22 (hardif_neigh,
&hard_iface->neigh_list, list) {
F_26 ( V_25 , V_15 ) ;
V_40 ++ ;
}
}
F_33 () ;
if ( V_40 == 0 )
F_30 ( V_25 , L_4 ) ;
}
static void F_34 ( struct V_3 * V_4 ,
struct V_24 * V_25 ,
struct V_1 * V_23 )
{
struct V_26 * V_27 ;
struct V_41 * V_42 = V_4 -> V_43 ;
int V_44 , V_45 ;
struct V_21 * V_22 ;
struct V_28 * V_29 ;
unsigned long V_46 ;
struct V_47 * V_48 ;
int V_40 = 0 ;
T_1 V_49 ;
F_30 ( V_25 ,
L_5 ) ;
for ( V_49 = 0 ; V_49 < V_42 -> V_50 ; V_49 ++ ) {
V_48 = & V_42 -> V_51 [ V_49 ] ;
F_31 () ;
F_22 (orig_node, head, hash_entry) {
V_27 = F_35 ( V_22 ,
V_23 ) ;
if ( ! V_27 )
continue;
V_29 = F_23 ( V_27 ,
V_23 ) ;
if ( ! V_29 )
goto V_52;
V_46 = V_33 - V_22 -> V_34 ;
V_44 = F_27 ( V_46 ) ;
V_45 = V_44 / 1000 ;
V_44 = V_44 % 1000 ;
F_24 ( V_25 , L_6 ,
V_22 -> V_53 , V_45 ,
V_44 ,
V_29 -> V_11 . V_16 / 10 ,
V_29 -> V_11 . V_16 % 10 ,
V_27 -> V_30 ,
V_27 -> V_35 -> V_36 -> V_37 ) ;
F_21 ( V_22 , V_23 , V_25 ) ;
F_30 ( V_25 , L_7 ) ;
V_40 ++ ;
V_52:
F_36 ( V_27 ) ;
if ( V_29 )
F_25 ( V_29 ) ;
}
F_33 () ;
}
if ( V_40 == 0 )
F_30 ( V_25 , L_4 ) ;
}
static int F_37 ( struct V_26 * V_54 ,
struct V_1 * V_55 ,
struct V_26 * V_56 ,
struct V_1 * V_57 )
{
struct V_28 * V_58 , * V_59 ;
int V_10 = 0 ;
V_58 = F_23 ( V_54 , V_55 ) ;
if ( F_38 ( ! V_58 ) )
goto V_60;
V_59 = F_23 ( V_56 , V_57 ) ;
if ( F_38 ( ! V_59 ) )
goto V_61;
V_10 = V_58 -> V_11 . V_16 - V_59 -> V_11 . V_16 ;
F_25 ( V_59 ) ;
V_61:
F_25 ( V_58 ) ;
V_60:
return V_10 ;
}
static bool F_39 ( struct V_26 * V_54 ,
struct V_1 * V_55 ,
struct V_26 * V_56 ,
struct V_1 * V_57 )
{
struct V_28 * V_58 , * V_59 ;
T_1 V_62 ;
bool V_10 = false ;
V_58 = F_23 ( V_54 , V_55 ) ;
if ( F_38 ( ! V_58 ) )
goto V_60;
V_59 = F_23 ( V_56 , V_57 ) ;
if ( F_38 ( ! V_59 ) )
goto V_61;
V_62 = V_58 -> V_11 . V_16 / 4 ;
V_62 = V_58 -> V_11 . V_16 - V_62 ;
V_10 = V_59 -> V_11 . V_16 > V_62 ;
F_25 ( V_59 ) ;
V_61:
F_25 ( V_58 ) ;
V_60:
return V_10 ;
}
int F_40 ( struct V_3 * V_4 )
{
return F_41 ( V_4 ) ;
}
void F_42 ( struct V_3 * V_4 )
{
F_43 ( V_4 ) ;
}
int T_2 F_44 ( void )
{
int V_10 ;
V_10 = F_45 ( V_63 ,
V_64 ) ;
if ( V_10 < 0 )
return V_10 ;
V_10 = F_45 ( V_65 ,
V_66 ) ;
if ( V_10 < 0 )
goto V_67;
V_10 = F_46 ( & V_68 ) ;
if ( V_10 < 0 )
goto V_69;
return V_10 ;
V_69:
F_47 ( V_65 ) ;
V_67:
F_47 ( V_63 ) ;
return V_10 ;
}
