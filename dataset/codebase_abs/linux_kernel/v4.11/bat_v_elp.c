static void F_1 ( struct V_1 * V_2 )
{
unsigned int V_3 ;
V_3 = F_2 ( & V_2 -> V_4 . V_5 ) - V_6 ;
V_3 += F_3 () % ( 2 * V_6 ) ;
F_4 ( V_7 , & V_2 -> V_4 . V_8 ,
F_5 ( V_3 ) ) ;
}
static T_1 F_6 ( struct V_9 * V_10 )
{
struct V_1 * V_2 = V_10 -> V_11 ;
struct V_12 V_13 ;
struct V_14 * V_15 ;
struct V_16 V_17 ;
T_1 V_18 ;
int V_19 ;
V_18 = F_2 ( & V_2 -> V_4 . V_20 ) ;
if ( V_18 != 0 )
return V_18 ;
if ( F_7 ( V_2 ) ) {
if ( ! F_8 ( V_2 ) )
goto V_21;
V_15 = F_9 ( V_2 -> V_22 ) ;
if ( ! V_15 )
goto V_21;
V_19 = F_10 ( V_15 , V_10 -> V_23 , & V_17 ) ;
F_11 ( V_15 ) ;
if ( V_19 == - V_24 ) {
return 0 ;
}
if ( ! V_19 )
return V_17 . V_25 / 100 ;
}
memset ( & V_13 , 0 , sizeof( V_13 ) ) ;
F_12 () ;
V_19 = F_13 ( V_2 -> V_22 , & V_13 ) ;
F_14 () ;
if ( V_19 == 0 ) {
if ( V_13 . V_26 . V_27 == V_28 )
V_2 -> V_4 . V_29 |= V_30 ;
else
V_2 -> V_4 . V_29 &= ~ V_30 ;
V_18 = V_13 . V_26 . V_31 ;
if ( V_18 && ( V_18 != V_32 ) )
return V_18 * 10 ;
}
V_21:
if ( ! ( V_2 -> V_4 . V_29 & V_33 ) ) {
F_15 ( V_2 -> V_34 ,
L_1 ,
V_2 -> V_22 -> V_35 ,
V_36 / 10 ,
V_36 % 10 ) ;
V_2 -> V_4 . V_29 |= V_33 ;
}
return V_36 ;
}
void F_16 ( struct V_37 * V_38 )
{
struct V_39 * V_40 ;
struct V_9 * V_10 ;
V_40 = F_17 ( V_38 , struct V_39 ,
V_41 ) ;
V_10 = F_17 ( V_40 , struct V_9 ,
V_4 ) ;
F_18 ( & V_10 -> V_4 . V_18 ,
F_6 ( V_10 ) ) ;
F_19 ( V_10 ) ;
}
static bool
F_20 ( struct V_9 * V_10 )
{
struct V_1 * V_2 = V_10 -> V_11 ;
struct V_42 * V_43 = F_21 ( V_2 -> V_34 ) ;
unsigned long V_44 ;
struct V_45 * V_46 ;
int V_47 , V_48 ;
int V_49 ;
if ( ! F_7 ( V_2 ) )
return true ;
V_44 = F_22 ( V_50 - V_10 -> V_4 . V_51 ) ;
if ( V_44 <= V_52 )
return true ;
V_47 = F_23 ( int , sizeof( struct V_53 ) ,
V_54 ) ;
for ( V_48 = 0 ; V_48 < V_55 ; V_48 ++ ) {
V_49 = V_2 -> V_4 . V_56 -> V_57 ;
V_46 = F_24 ( V_2 -> V_4 . V_56 , 0 ,
V_47 - V_49 ,
V_58 ) ;
if ( ! V_46 )
return false ;
F_25 ( V_46 , V_47 - V_2 -> V_4 . V_56 -> V_57 ) ;
F_26 ( V_59 , V_43 ,
L_2 ,
V_2 -> V_22 -> V_35 , V_10 -> V_23 ) ;
F_27 ( V_46 , V_2 , V_10 -> V_23 ) ;
}
return true ;
}
static void F_28 ( struct V_37 * V_38 )
{
struct V_9 * V_60 ;
struct V_1 * V_2 ;
struct V_61 * V_4 ;
struct V_53 * V_62 ;
struct V_42 * V_43 ;
struct V_45 * V_46 ;
T_1 V_5 ;
V_4 = F_17 ( V_38 , struct V_61 , V_8 . V_38 ) ;
V_2 = F_17 ( V_4 , struct V_1 , V_4 ) ;
V_43 = F_21 ( V_2 -> V_34 ) ;
if ( F_2 ( & V_43 -> V_63 ) == V_64 )
goto V_65;
if ( ( V_2 -> V_66 == V_67 ) ||
( V_2 -> V_66 == V_68 ) )
goto V_65;
if ( V_2 -> V_66 != V_69 )
goto V_70;
V_46 = F_29 ( V_2 -> V_4 . V_56 , V_58 ) ;
if ( ! V_46 )
goto V_70;
V_62 = (struct V_53 * ) V_46 -> V_71 ;
V_62 -> V_72 = F_30 ( F_2 ( & V_2 -> V_4 . V_73 ) ) ;
V_5 = F_2 ( & V_2 -> V_4 . V_5 ) ;
V_62 -> V_5 = F_30 ( V_5 ) ;
F_26 ( V_59 , V_43 ,
L_3 ,
V_2 -> V_22 -> V_35 ,
F_2 ( & V_2 -> V_4 . V_73 ) ) ;
F_31 ( V_46 , V_2 ) ;
F_32 ( & V_2 -> V_4 . V_73 ) ;
F_33 () ;
F_34 (hardif_neigh, &hard_iface->neigh_list, list) {
if ( ! F_20 ( V_60 ) )
break;
if ( ! F_35 ( & V_60 -> V_74 ) )
continue;
F_36 ( V_7 ,
& V_60 -> V_4 . V_41 ) ;
}
F_37 () ;
V_70:
F_1 ( V_2 ) ;
V_65:
return;
}
int F_38 ( struct V_1 * V_2 )
{
struct V_53 * V_62 ;
unsigned char * V_75 ;
T_1 V_76 ;
T_2 V_77 ;
int V_78 = - V_79 ;
V_77 = V_80 + V_81 + V_82 ;
V_2 -> V_4 . V_56 = F_39 ( V_77 ) ;
if ( ! V_2 -> V_4 . V_56 )
goto V_65;
F_40 ( V_2 -> V_4 . V_56 , V_80 + V_81 ) ;
V_75 = F_25 ( V_2 -> V_4 . V_56 , V_82 ) ;
V_62 = (struct V_53 * ) V_75 ;
memset ( V_62 , 0 , V_82 ) ;
V_62 -> V_83 = V_84 ;
V_62 -> V_85 = V_86 ;
F_41 ( & V_76 , sizeof( V_76 ) ) ;
F_42 ( & V_2 -> V_4 . V_73 , V_76 ) ;
V_2 -> V_4 . V_29 |= V_30 ;
V_2 -> V_4 . V_29 &= ~ V_33 ;
if ( F_7 ( V_2 ) )
V_2 -> V_4 . V_29 &= ~ V_30 ;
F_43 ( & V_2 -> V_4 . V_8 ,
F_28 ) ;
F_1 ( V_2 ) ;
V_78 = 0 ;
V_65:
return V_78 ;
}
void F_44 ( struct V_1 * V_2 )
{
F_45 ( & V_2 -> V_4 . V_8 ) ;
F_46 ( V_2 -> V_4 . V_56 ) ;
V_2 -> V_4 . V_56 = NULL ;
}
void F_47 ( struct V_1 * V_87 ,
struct V_1 * V_2 )
{
struct V_53 * V_62 ;
struct V_45 * V_46 ;
if ( ! V_2 -> V_4 . V_56 )
return;
V_46 = V_2 -> V_4 . V_56 ;
V_62 = (struct V_53 * ) V_46 -> V_71 ;
F_48 ( V_62 -> V_88 ,
V_87 -> V_22 -> V_89 ) ;
}
void F_49 ( struct V_1 * V_87 )
{
struct V_1 * V_2 ;
F_33 () ;
F_50 (hard_iface, &batadv_hardif_list, list) {
if ( V_87 -> V_34 != V_2 -> V_34 )
continue;
F_47 ( V_87 , V_2 ) ;
}
F_37 () ;
}
static void F_51 ( struct V_42 * V_43 ,
T_3 * V_90 ,
struct V_1 * V_11 ,
struct V_53 * V_62 )
{
struct V_91 * V_10 ;
struct V_92 * V_93 ;
struct V_9 * V_60 ;
T_4 V_94 ;
T_4 V_95 ;
V_93 = F_52 ( V_43 , V_62 -> V_88 ) ;
if ( ! V_93 )
return;
V_10 = F_53 ( V_93 ,
V_11 , V_90 ) ;
if ( ! V_10 )
goto V_96;
V_60 = F_54 ( V_11 , V_90 ) ;
if ( ! V_60 )
goto V_97;
V_95 = V_60 -> V_4 . V_95 ;
V_94 = F_55 ( V_62 -> V_72 ) - V_95 ;
if ( V_94 < 1 && V_94 > - V_98 )
goto V_99;
V_10 -> V_100 = V_50 ;
V_60 -> V_100 = V_50 ;
V_60 -> V_4 . V_95 = F_55 ( V_62 -> V_72 ) ;
V_60 -> V_4 . V_5 = F_55 ( V_62 -> V_5 ) ;
V_99:
if ( V_60 )
F_19 ( V_60 ) ;
V_97:
if ( V_10 )
F_56 ( V_10 ) ;
V_96:
if ( V_93 )
F_57 ( V_93 ) ;
}
int F_58 ( struct V_45 * V_46 ,
struct V_1 * V_11 )
{
struct V_42 * V_43 = F_21 ( V_11 -> V_34 ) ;
struct V_53 * V_62 ;
struct V_1 * V_101 ;
struct V_102 * V_102 = (struct V_102 * ) F_59 ( V_46 ) ;
bool V_78 ;
int V_19 = V_103 ;
V_78 = F_60 ( V_46 , V_11 , V_82 ) ;
if ( ! V_78 )
goto V_104;
if ( F_61 ( V_43 , V_102 -> V_105 ) )
goto V_104;
if ( strcmp ( V_43 -> V_106 -> V_35 , L_4 ) != 0 )
goto V_104;
V_62 = (struct V_53 * ) V_46 -> V_71 ;
F_26 ( V_59 , V_43 ,
L_5 ,
V_102 -> V_105 , F_55 ( V_62 -> V_72 ) ,
V_62 -> V_88 ) ;
V_101 = F_62 ( V_43 ) ;
if ( ! V_101 )
goto V_104;
F_51 ( V_43 , V_102 -> V_105 , V_11 ,
V_62 ) ;
V_19 = V_107 ;
F_63 ( V_101 ) ;
V_104:
if ( V_19 == V_107 )
F_64 ( V_46 ) ;
else
F_65 ( V_46 ) ;
return V_19 ;
}
