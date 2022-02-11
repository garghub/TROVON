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
struct V_14 V_15 ;
T_1 V_16 ;
int V_17 ;
V_16 = F_2 ( & V_2 -> V_4 . V_18 ) ;
if ( V_16 != 0 )
return V_16 ;
if ( F_7 ( V_2 -> V_19 ) ) {
if ( V_2 -> V_19 -> V_20 ) {
V_17 = F_8 ( V_2 -> V_19 ,
V_10 -> V_21 , & V_15 ) ;
if ( V_17 == - V_22 ) {
return 0 ;
}
if ( ! V_17 )
return V_15 . V_23 / 100 ;
}
goto V_24;
}
memset ( & V_13 , 0 , sizeof( V_13 ) ) ;
F_9 () ;
V_17 = F_10 ( V_2 -> V_19 , & V_13 ) ;
F_11 () ;
if ( V_17 == 0 ) {
if ( V_13 . V_25 . V_26 == V_27 )
V_2 -> V_4 . V_28 |= V_29 ;
else
V_2 -> V_4 . V_28 &= ~ V_29 ;
V_16 = V_13 . V_25 . V_30 ;
if ( V_16 && ( V_16 != V_31 ) )
return V_16 * 10 ;
}
V_24:
if ( ! ( V_2 -> V_4 . V_28 & V_32 ) ) {
F_12 ( V_2 -> V_33 ,
L_1 ,
V_2 -> V_19 -> V_34 ,
V_35 / 10 ,
V_35 % 10 ) ;
V_2 -> V_4 . V_28 |= V_32 ;
}
return V_35 ;
}
void F_13 ( struct V_36 * V_37 )
{
struct V_38 * V_39 ;
struct V_9 * V_10 ;
V_39 = F_14 ( V_37 , struct V_38 ,
V_40 ) ;
V_10 = F_14 ( V_39 , struct V_9 ,
V_4 ) ;
F_15 ( & V_10 -> V_4 . V_16 ,
F_6 ( V_10 ) ) ;
F_16 ( V_10 ) ;
}
static bool
F_17 ( struct V_9 * V_10 )
{
struct V_1 * V_2 = V_10 -> V_11 ;
struct V_41 * V_42 = F_18 ( V_2 -> V_33 ) ;
unsigned long V_43 ;
struct V_44 * V_45 ;
int V_46 , V_47 ;
int V_48 ;
if ( ! F_7 ( V_2 -> V_19 ) )
return true ;
V_43 = F_19 ( V_49 - V_10 -> V_4 . V_50 ) ;
if ( V_43 <= V_51 )
return true ;
V_46 = F_20 ( int , sizeof( struct V_52 ) ,
V_53 ) ;
for ( V_47 = 0 ; V_47 < V_54 ; V_47 ++ ) {
V_48 = V_2 -> V_4 . V_55 -> V_56 ;
V_45 = F_21 ( V_2 -> V_4 . V_55 , 0 ,
V_46 - V_48 ,
V_57 ) ;
if ( ! V_45 )
return false ;
F_22 ( V_45 , V_46 - V_2 -> V_4 . V_55 -> V_56 ) ;
F_23 ( V_58 , V_42 ,
L_2 ,
V_2 -> V_19 -> V_34 , V_10 -> V_21 ) ;
F_24 ( V_45 , V_2 , V_10 -> V_21 ) ;
}
return true ;
}
static void F_25 ( struct V_36 * V_37 )
{
struct V_9 * V_59 ;
struct V_1 * V_2 ;
struct V_60 * V_4 ;
struct V_52 * V_61 ;
struct V_41 * V_42 ;
struct V_44 * V_45 ;
T_1 V_5 ;
V_4 = F_14 ( V_37 , struct V_60 , V_8 . V_37 ) ;
V_2 = F_14 ( V_4 , struct V_1 , V_4 ) ;
V_42 = F_18 ( V_2 -> V_33 ) ;
if ( F_2 ( & V_42 -> V_62 ) == V_63 )
goto V_64;
if ( ( V_2 -> V_65 == V_66 ) ||
( V_2 -> V_65 == V_67 ) )
goto V_64;
if ( V_2 -> V_65 != V_68 )
goto V_69;
V_45 = F_26 ( V_2 -> V_4 . V_55 , V_57 ) ;
if ( ! V_45 )
goto V_69;
V_61 = (struct V_52 * ) V_45 -> V_70 ;
V_61 -> V_71 = F_27 ( F_2 ( & V_2 -> V_4 . V_72 ) ) ;
V_5 = F_2 ( & V_2 -> V_4 . V_5 ) ;
V_61 -> V_5 = F_27 ( V_5 ) ;
F_23 ( V_58 , V_42 ,
L_3 ,
V_2 -> V_19 -> V_34 ,
F_2 ( & V_2 -> V_4 . V_72 ) ) ;
F_28 ( V_45 , V_2 ) ;
F_29 ( & V_2 -> V_4 . V_72 ) ;
F_30 () ;
F_31 (hardif_neigh, &hard_iface->neigh_list, list) {
if ( ! F_17 ( V_59 ) )
break;
if ( ! F_32 ( & V_59 -> V_73 ) )
continue;
F_33 ( V_7 ,
& V_59 -> V_4 . V_40 ) ;
}
F_34 () ;
V_69:
F_1 ( V_2 ) ;
V_64:
return;
}
int F_35 ( struct V_1 * V_2 )
{
struct V_52 * V_61 ;
unsigned char * V_74 ;
T_1 V_75 ;
T_2 V_76 ;
int V_77 = - V_78 ;
V_76 = V_79 + V_80 + V_81 ;
V_2 -> V_4 . V_55 = F_36 ( V_76 ) ;
if ( ! V_2 -> V_4 . V_55 )
goto V_64;
F_37 ( V_2 -> V_4 . V_55 , V_79 + V_80 ) ;
V_74 = F_38 ( V_2 -> V_4 . V_55 , V_81 ) ;
V_61 = (struct V_52 * ) V_74 ;
memset ( V_61 , 0 , V_81 ) ;
V_61 -> V_82 = V_83 ;
V_61 -> V_84 = V_85 ;
F_39 ( & V_75 , sizeof( V_75 ) ) ;
F_40 ( & V_2 -> V_4 . V_72 , V_75 ) ;
F_40 ( & V_2 -> V_4 . V_5 , 500 ) ;
V_2 -> V_4 . V_28 |= V_29 ;
V_2 -> V_4 . V_28 &= ~ V_32 ;
if ( F_7 ( V_2 -> V_19 ) )
V_2 -> V_4 . V_28 &= ~ V_29 ;
F_41 ( & V_2 -> V_4 . V_8 ,
F_25 ) ;
F_1 ( V_2 ) ;
V_77 = 0 ;
V_64:
return V_77 ;
}
void F_42 ( struct V_1 * V_2 )
{
F_43 ( & V_2 -> V_4 . V_8 ) ;
F_44 ( V_2 -> V_4 . V_55 ) ;
V_2 -> V_4 . V_55 = NULL ;
}
void F_45 ( struct V_1 * V_86 ,
struct V_1 * V_2 )
{
struct V_52 * V_61 ;
struct V_44 * V_45 ;
if ( ! V_2 -> V_4 . V_55 )
return;
V_45 = V_2 -> V_4 . V_55 ;
V_61 = (struct V_52 * ) V_45 -> V_70 ;
F_46 ( V_61 -> V_87 ,
V_86 -> V_19 -> V_88 ) ;
}
void F_47 ( struct V_1 * V_86 )
{
struct V_1 * V_2 ;
F_30 () ;
F_48 (hard_iface, &batadv_hardif_list, list) {
if ( V_86 -> V_33 != V_2 -> V_33 )
continue;
F_45 ( V_86 , V_2 ) ;
}
F_34 () ;
}
static void F_49 ( struct V_41 * V_42 ,
T_3 * V_89 ,
struct V_1 * V_11 ,
struct V_52 * V_61 )
{
struct V_90 * V_10 ;
struct V_91 * V_92 ;
struct V_9 * V_59 ;
T_4 V_93 ;
T_4 V_94 ;
V_92 = F_50 ( V_42 , V_61 -> V_87 ) ;
if ( ! V_92 )
return;
V_10 = F_51 ( V_92 , V_11 , V_89 ) ;
if ( ! V_10 )
goto V_95;
V_59 = F_52 ( V_11 , V_89 ) ;
if ( ! V_59 )
goto V_96;
V_94 = V_59 -> V_4 . V_94 ;
V_93 = F_53 ( V_61 -> V_71 ) - V_94 ;
if ( V_93 < 1 && V_93 > - V_97 )
goto V_98;
V_10 -> V_99 = V_49 ;
V_59 -> V_99 = V_49 ;
V_59 -> V_4 . V_94 = F_53 ( V_61 -> V_71 ) ;
V_59 -> V_4 . V_5 = F_53 ( V_61 -> V_5 ) ;
V_98:
if ( V_59 )
F_16 ( V_59 ) ;
V_96:
if ( V_10 )
F_54 ( V_10 ) ;
V_95:
if ( V_92 )
F_55 ( V_92 ) ;
}
int F_56 ( struct V_44 * V_45 ,
struct V_1 * V_11 )
{
struct V_41 * V_42 = F_18 ( V_11 -> V_33 ) ;
struct V_52 * V_61 ;
struct V_1 * V_100 ;
struct V_101 * V_101 = (struct V_101 * ) F_57 ( V_45 ) ;
bool V_17 ;
V_17 = F_58 ( V_45 , V_11 , V_81 ) ;
if ( ! V_17 )
return V_102 ;
if ( F_59 ( V_42 , V_101 -> V_103 ) )
return V_102 ;
if ( strcmp ( V_42 -> V_104 -> V_34 , L_4 ) != 0 )
return V_102 ;
V_61 = (struct V_52 * ) V_45 -> V_70 ;
F_23 ( V_58 , V_42 ,
L_5 ,
V_101 -> V_103 , F_53 ( V_61 -> V_71 ) ,
V_61 -> V_87 ) ;
V_100 = F_60 ( V_42 ) ;
if ( ! V_100 )
goto V_64;
F_49 ( V_42 , V_101 -> V_103 , V_11 ,
V_61 ) ;
V_64:
if ( V_100 )
F_61 ( V_100 ) ;
F_62 ( V_45 ) ;
return V_105 ;
}
