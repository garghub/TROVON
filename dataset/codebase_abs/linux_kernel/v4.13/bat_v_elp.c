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
if ( V_19 )
goto V_21;
if ( ! ( V_17 . V_25 & F_12 ( V_26 ) ) )
goto V_21;
return V_17 . V_27 / 100 ;
}
memset ( & V_13 , 0 , sizeof( V_13 ) ) ;
F_13 () ;
V_19 = F_14 ( V_2 -> V_22 , & V_13 ) ;
F_15 () ;
if ( V_19 == 0 ) {
if ( V_13 . V_28 . V_29 == V_30 )
V_2 -> V_4 . V_31 |= V_32 ;
else
V_2 -> V_4 . V_31 &= ~ V_32 ;
V_18 = V_13 . V_28 . V_33 ;
if ( V_18 && ( V_18 != V_34 ) )
return V_18 * 10 ;
}
V_21:
if ( ! ( V_2 -> V_4 . V_31 & V_35 ) ) {
F_16 ( V_2 -> V_36 ,
L_1 ,
V_2 -> V_22 -> V_37 ,
V_38 / 10 ,
V_38 % 10 ) ;
V_2 -> V_4 . V_31 |= V_35 ;
}
return V_38 ;
}
void F_17 ( struct V_39 * V_40 )
{
struct V_41 * V_42 ;
struct V_9 * V_10 ;
V_42 = F_18 ( V_40 , struct V_41 ,
V_43 ) ;
V_10 = F_18 ( V_42 , struct V_9 ,
V_4 ) ;
F_19 ( & V_10 -> V_4 . V_18 ,
F_6 ( V_10 ) ) ;
F_20 ( V_10 ) ;
}
static bool
F_21 ( struct V_9 * V_10 )
{
struct V_1 * V_2 = V_10 -> V_11 ;
struct V_44 * V_45 = F_22 ( V_2 -> V_36 ) ;
unsigned long V_46 ;
struct V_47 * V_48 ;
int V_49 , V_50 ;
int V_51 ;
if ( ! F_7 ( V_2 ) )
return true ;
V_46 = F_23 ( V_52 - V_10 -> V_4 . V_53 ) ;
if ( V_46 <= V_54 )
return true ;
V_49 = F_24 ( int , sizeof( struct V_55 ) ,
V_56 ) ;
for ( V_50 = 0 ; V_50 < V_57 ; V_50 ++ ) {
V_51 = V_2 -> V_4 . V_58 -> V_59 ;
V_48 = F_25 ( V_2 -> V_4 . V_58 , 0 ,
V_49 - V_51 ,
V_60 ) ;
if ( ! V_48 )
return false ;
F_26 ( V_48 , V_49 - V_2 -> V_4 . V_58 -> V_59 ) ;
F_27 ( V_61 , V_45 ,
L_2 ,
V_2 -> V_22 -> V_37 , V_10 -> V_23 ) ;
F_28 ( V_48 , V_2 , V_10 -> V_23 ) ;
}
return true ;
}
static void F_29 ( struct V_39 * V_40 )
{
struct V_9 * V_62 ;
struct V_1 * V_2 ;
struct V_63 * V_4 ;
struct V_55 * V_64 ;
struct V_44 * V_45 ;
struct V_47 * V_48 ;
T_1 V_5 ;
V_4 = F_18 ( V_40 , struct V_63 , V_8 . V_40 ) ;
V_2 = F_18 ( V_4 , struct V_1 , V_4 ) ;
V_45 = F_22 ( V_2 -> V_36 ) ;
if ( F_2 ( & V_45 -> V_65 ) == V_66 )
goto V_67;
if ( ( V_2 -> V_68 == V_69 ) ||
( V_2 -> V_68 == V_70 ) )
goto V_67;
if ( V_2 -> V_68 != V_71 )
goto V_72;
V_48 = F_30 ( V_2 -> V_4 . V_58 , V_60 ) ;
if ( ! V_48 )
goto V_72;
V_64 = (struct V_55 * ) V_48 -> V_73 ;
V_64 -> V_74 = F_31 ( F_2 ( & V_2 -> V_4 . V_75 ) ) ;
V_5 = F_2 ( & V_2 -> V_4 . V_5 ) ;
V_64 -> V_5 = F_31 ( V_5 ) ;
F_27 ( V_61 , V_45 ,
L_3 ,
V_2 -> V_22 -> V_37 ,
F_2 ( & V_2 -> V_4 . V_75 ) ) ;
F_32 ( V_48 , V_2 ) ;
F_33 ( & V_2 -> V_4 . V_75 ) ;
F_34 () ;
F_35 (hardif_neigh, &hard_iface->neigh_list, list) {
if ( ! F_21 ( V_62 ) )
break;
if ( ! F_36 ( & V_62 -> V_76 ) )
continue;
F_37 ( V_7 ,
& V_62 -> V_4 . V_43 ) ;
}
F_38 () ;
V_72:
F_1 ( V_2 ) ;
V_67:
return;
}
int F_39 ( struct V_1 * V_2 )
{
struct V_55 * V_64 ;
unsigned char * V_77 ;
T_1 V_78 ;
T_2 V_79 ;
int V_80 = - V_81 ;
V_79 = V_82 + V_83 + V_84 ;
V_2 -> V_4 . V_58 = F_40 ( V_79 ) ;
if ( ! V_2 -> V_4 . V_58 )
goto V_67;
F_41 ( V_2 -> V_4 . V_58 , V_82 + V_83 ) ;
V_77 = F_42 ( V_2 -> V_4 . V_58 , V_84 ) ;
V_64 = (struct V_55 * ) V_77 ;
V_64 -> V_85 = V_86 ;
V_64 -> V_87 = V_88 ;
F_43 ( & V_78 , sizeof( V_78 ) ) ;
F_44 ( & V_2 -> V_4 . V_75 , V_78 ) ;
V_2 -> V_4 . V_31 |= V_32 ;
V_2 -> V_4 . V_31 &= ~ V_35 ;
if ( F_7 ( V_2 ) )
V_2 -> V_4 . V_31 &= ~ V_32 ;
F_45 ( & V_2 -> V_4 . V_8 ,
F_29 ) ;
F_1 ( V_2 ) ;
V_80 = 0 ;
V_67:
return V_80 ;
}
void F_46 ( struct V_1 * V_2 )
{
F_47 ( & V_2 -> V_4 . V_8 ) ;
F_48 ( V_2 -> V_4 . V_58 ) ;
V_2 -> V_4 . V_58 = NULL ;
}
void F_49 ( struct V_1 * V_89 ,
struct V_1 * V_2 )
{
struct V_55 * V_64 ;
struct V_47 * V_48 ;
if ( ! V_2 -> V_4 . V_58 )
return;
V_48 = V_2 -> V_4 . V_58 ;
V_64 = (struct V_55 * ) V_48 -> V_73 ;
F_50 ( V_64 -> V_90 ,
V_89 -> V_22 -> V_91 ) ;
}
void F_51 ( struct V_1 * V_89 )
{
struct V_1 * V_2 ;
F_34 () ;
F_52 (hard_iface, &batadv_hardif_list, list) {
if ( V_89 -> V_36 != V_2 -> V_36 )
continue;
F_49 ( V_89 , V_2 ) ;
}
F_38 () ;
}
static void F_53 ( struct V_44 * V_45 ,
T_3 * V_92 ,
struct V_1 * V_11 ,
struct V_55 * V_64 )
{
struct V_93 * V_10 ;
struct V_94 * V_95 ;
struct V_9 * V_62 ;
T_4 V_96 ;
T_4 V_97 ;
V_95 = F_54 ( V_45 , V_64 -> V_90 ) ;
if ( ! V_95 )
return;
V_10 = F_55 ( V_95 ,
V_11 , V_92 ) ;
if ( ! V_10 )
goto V_98;
V_62 = F_56 ( V_11 , V_92 ) ;
if ( ! V_62 )
goto V_99;
V_97 = V_62 -> V_4 . V_97 ;
V_96 = F_57 ( V_64 -> V_74 ) - V_97 ;
if ( V_96 < 1 && V_96 > - V_100 )
goto V_101;
V_10 -> V_102 = V_52 ;
V_62 -> V_102 = V_52 ;
V_62 -> V_4 . V_97 = F_57 ( V_64 -> V_74 ) ;
V_62 -> V_4 . V_5 = F_57 ( V_64 -> V_5 ) ;
V_101:
if ( V_62 )
F_20 ( V_62 ) ;
V_99:
if ( V_10 )
F_58 ( V_10 ) ;
V_98:
if ( V_95 )
F_59 ( V_95 ) ;
}
int F_60 ( struct V_47 * V_48 ,
struct V_1 * V_11 )
{
struct V_44 * V_45 = F_22 ( V_11 -> V_36 ) ;
struct V_55 * V_64 ;
struct V_1 * V_103 ;
struct V_104 * V_104 = (struct V_104 * ) F_61 ( V_48 ) ;
bool V_80 ;
int V_19 = V_105 ;
V_80 = F_62 ( V_48 , V_11 , V_84 ) ;
if ( ! V_80 )
goto V_106;
if ( F_63 ( V_45 , V_104 -> V_107 ) )
goto V_106;
if ( strcmp ( V_45 -> V_108 -> V_37 , L_4 ) != 0 )
goto V_106;
V_64 = (struct V_55 * ) V_48 -> V_73 ;
F_27 ( V_61 , V_45 ,
L_5 ,
V_104 -> V_107 , F_57 ( V_64 -> V_74 ) ,
V_64 -> V_90 ) ;
V_103 = F_64 ( V_45 ) ;
if ( ! V_103 )
goto V_106;
F_53 ( V_45 , V_104 -> V_107 , V_11 ,
V_64 ) ;
V_19 = V_109 ;
F_65 ( V_103 ) ;
V_106:
if ( V_19 == V_109 )
F_66 ( V_48 ) ;
else
F_67 ( V_48 ) ;
return V_19 ;
}
