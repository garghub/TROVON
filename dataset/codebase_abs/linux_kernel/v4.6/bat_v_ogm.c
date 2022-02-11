struct V_1 * F_1 ( struct V_2 * V_3 ,
const T_1 * V_4 )
{
struct V_1 * V_5 ;
int V_6 ;
V_5 = F_2 ( V_3 , V_4 ) ;
if ( V_5 )
return V_5 ;
V_5 = F_3 ( V_3 , V_4 ) ;
if ( ! V_5 )
return NULL ;
V_6 = F_4 ( V_3 -> V_7 , V_8 ,
V_9 , V_5 ,
& V_5 -> V_10 ) ;
if ( V_6 != 0 ) {
F_5 ( V_5 ) ;
F_5 ( V_5 ) ;
V_5 = NULL ;
}
return V_5 ;
}
static void F_6 ( struct V_2 * V_3 )
{
unsigned long V_11 ;
if ( F_7 ( & V_3 -> V_12 . V_13 ) )
return;
V_11 = F_8 ( & V_3 -> V_14 ) - V_15 ;
V_11 += F_9 () % ( 2 * V_15 ) ;
F_10 ( V_16 , & V_3 -> V_12 . V_13 ,
F_11 ( V_11 ) ) ;
}
static void F_12 ( struct V_17 * V_18 ,
struct V_19 * V_20 )
{
struct V_2 * V_3 = F_13 ( V_20 -> V_21 ) ;
if ( V_20 -> V_22 != V_23 )
return;
F_14 ( V_3 , V_24 ) ;
F_15 ( V_3 , V_25 ,
V_18 -> V_26 + V_27 ) ;
F_16 ( V_18 , V_20 ) ;
}
static void F_17 ( struct V_28 * V_29 )
{
struct V_19 * V_20 ;
struct V_30 * V_12 ;
struct V_2 * V_3 ;
struct V_31 * V_32 ;
struct V_17 * V_18 , * V_33 ;
unsigned char * V_34 , * V_35 ;
int V_36 ;
T_2 V_37 = 0 ;
V_12 = F_18 ( V_29 , struct V_30 , V_13 . V_29 ) ;
V_3 = F_18 ( V_12 , struct V_2 , V_12 ) ;
if ( F_8 ( & V_3 -> V_38 ) == V_39 )
goto V_40;
V_34 = V_3 -> V_12 . V_34 ;
V_36 = V_3 -> V_12 . V_36 ;
F_19 ( V_3 ) ;
V_37 = F_20 ( V_3 , & V_34 ,
& V_36 ,
V_41 ) ;
V_3 -> V_12 . V_34 = V_34 ;
V_3 -> V_12 . V_36 = V_36 ;
V_18 = F_21 ( NULL , V_27 + V_36 ) ;
if ( ! V_18 )
goto V_42;
F_22 ( V_18 , V_27 ) ;
V_35 = F_23 ( V_18 , V_36 ) ;
memcpy ( V_35 , V_34 , V_36 ) ;
V_32 = (struct V_31 * ) V_18 -> V_43 ;
V_32 -> V_44 = F_24 ( F_8 ( & V_3 -> V_12 . V_45 ) ) ;
F_25 ( & V_3 -> V_12 . V_45 ) ;
V_32 -> V_37 = F_26 ( V_37 ) ;
F_27 () ;
F_28 (hard_iface, &batadv_hardif_list, list) {
if ( V_20 -> V_21 != V_3 -> V_21 )
continue;
F_29 ( V_46 , V_3 ,
L_1 ,
V_32 -> V_47 , F_30 ( V_32 -> V_44 ) ,
F_30 ( V_32 -> V_48 ) , V_32 -> V_49 ,
V_20 -> V_50 -> V_51 ,
V_20 -> V_50 -> V_52 ) ;
V_33 = F_31 ( V_18 , V_53 ) ;
if ( ! V_33 )
break;
F_12 ( V_33 , V_20 ) ;
}
F_32 () ;
F_33 ( V_18 ) ;
V_42:
F_6 ( V_3 ) ;
V_40:
return;
}
int F_34 ( struct V_19 * V_20 )
{
struct V_2 * V_3 = F_13 ( V_20 -> V_21 ) ;
F_6 ( V_3 ) ;
return 0 ;
}
void F_35 ( struct V_19 * V_54 )
{
struct V_2 * V_3 = F_13 ( V_54 -> V_21 ) ;
struct V_31 * V_32 ;
if ( ! V_3 -> V_12 . V_34 )
return;
V_32 = (struct V_31 * ) V_3 -> V_12 . V_34 ;
F_36 ( V_32 -> V_47 , V_54 -> V_50 -> V_52 ) ;
}
static void
F_37 ( struct V_2 * V_3 ,
struct V_1 * V_5 ,
struct V_55 * V_56 ,
const struct V_31 * V_57 ,
struct V_19 * V_58 )
{
struct V_59 * V_60 = NULL , * V_61 = NULL ;
struct V_55 * V_62 = NULL ;
T_3 V_63 ;
T_4 V_64 ;
T_4 V_65 ;
T_4 V_66 , V_67 ;
F_29 ( V_46 , V_3 ,
L_2 ) ;
V_62 = F_38 ( V_5 , V_58 ) ;
if ( V_62 == V_56 )
goto V_40;
if ( V_62 ) {
V_60 = F_39 ( V_62 , V_58 ) ;
V_61 = F_39 ( V_56 , V_58 ) ;
if ( ! V_60 || ! V_61 )
goto V_40;
V_64 = V_61 -> V_12 . V_68 ;
V_65 = V_60 -> V_12 . V_68 ;
V_63 = V_64 - V_65 ;
V_66 = V_60 -> V_12 . V_48 ;
V_67 = V_61 -> V_12 . V_48 ;
if ( ( V_63 < V_69 ) &&
( V_66 >= V_67 ) )
goto V_40;
}
F_40 ( V_3 , V_5 , V_58 , V_56 ) ;
V_40:
if ( V_60 )
F_41 ( V_60 ) ;
if ( V_61 )
F_41 ( V_61 ) ;
if ( V_62 )
F_42 ( V_62 ) ;
}
static T_4 F_43 ( struct V_2 * V_3 ,
struct V_19 * V_70 ,
struct V_19 * V_58 ,
T_4 V_48 )
{
int V_71 = F_8 ( & V_3 -> V_71 ) ;
int V_72 = V_73 ;
if ( V_58 == V_74 )
return V_48 ;
if ( ( V_48 > 10 ) &&
( V_70 == V_58 ) &&
! ( V_70 -> V_12 . V_75 & V_76 ) )
return V_48 / 2 ;
return V_48 * ( V_72 - V_71 ) / V_72 ;
}
static void F_44 ( struct V_2 * V_3 ,
const struct V_31 * V_77 ,
T_4 V_48 ,
struct V_19 * V_70 ,
struct V_19 * V_58 )
{
struct V_31 * V_78 ;
unsigned char * V_79 ;
struct V_17 * V_18 ;
T_5 V_80 ;
T_2 V_37 ;
if ( V_77 -> V_49 <= 1 ) {
F_29 ( V_46 , V_3 , L_3 ) ;
return;
}
V_37 = F_45 ( V_77 -> V_37 ) ;
V_80 = V_41 + V_37 ;
V_18 = F_21 ( V_58 -> V_50 ,
V_27 + V_80 ) ;
if ( ! V_18 )
return;
F_22 ( V_18 , V_27 ) ;
V_79 = F_23 ( V_18 , V_80 ) ;
memcpy ( V_79 , V_77 , V_80 ) ;
V_78 = (struct V_31 * ) V_79 ;
V_78 -> V_48 = F_24 ( V_48 ) ;
V_78 -> V_49 -- ;
F_29 ( V_46 , V_3 ,
L_4 ,
V_58 -> V_50 -> V_51 , V_48 , V_78 -> V_49 ,
V_70 -> V_50 -> V_51 ) ;
F_12 ( V_18 , V_58 ) ;
}
static int F_46 ( struct V_2 * V_3 ,
const struct V_31 * V_57 ,
struct V_1 * V_5 ,
struct V_55 * V_56 ,
struct V_19 * V_70 ,
struct V_19 * V_58 )
{
struct V_81 * V_82 = NULL ;
struct V_59 * V_61 = NULL ;
bool V_83 = false ;
int V_84 = - V_85 ;
T_4 V_86 ;
T_3 V_87 ;
V_82 = F_47 ( V_5 , V_58 ) ;
if ( ! V_82 )
goto V_40;
V_87 = F_30 ( V_57 -> V_44 ) - V_82 -> V_88 ;
if ( ! F_48 ( & V_5 -> V_89 ) &&
F_49 ( V_3 , V_87 ,
V_90 ,
& V_82 -> V_91 ,
& V_83 ) ) {
F_29 ( V_46 , V_3 ,
L_5 ,
V_57 -> V_47 ) ;
F_29 ( V_46 , V_3 ,
L_6 ,
V_82 -> V_91 , V_92 ) ;
goto V_40;
}
if ( ( V_87 < 0 ) && ! V_83 )
goto V_40;
V_56 -> V_93 = V_92 ;
V_5 -> V_93 = V_92 ;
V_82 -> V_88 = F_30 ( V_57 -> V_44 ) ;
V_82 -> V_94 = V_57 -> V_49 ;
V_61 = F_50 ( V_56 , V_58 ) ;
if ( ! V_61 )
goto V_40;
V_86 = F_43 ( V_3 , V_70 ,
V_58 ,
F_30 ( V_57 -> V_48 ) ) ;
V_61 -> V_12 . V_48 = V_86 ;
V_61 -> V_12 . V_68 = F_30 ( V_57 -> V_44 ) ;
V_61 -> V_94 = V_57 -> V_49 ;
if ( V_87 > 0 || V_83 )
V_84 = 1 ;
else
V_84 = 0 ;
V_40:
if ( V_82 )
F_51 ( V_82 ) ;
if ( V_61 )
F_41 ( V_61 ) ;
return V_84 ;
}
static void F_52 ( struct V_2 * V_3 ,
const struct V_95 * V_95 ,
const struct V_31 * V_57 ,
struct V_1 * V_5 ,
struct V_55 * V_56 ,
struct V_19 * V_70 ,
struct V_19 * V_58 )
{
struct V_55 * V_62 = NULL ;
struct V_59 * V_61 = NULL ;
struct V_1 * V_96 = NULL ;
struct V_81 * V_82 = NULL ;
struct V_55 * V_97 = NULL ;
V_61 = F_39 ( V_56 , V_58 ) ;
if ( ! V_61 )
goto V_40;
V_96 = F_1 ( V_3 , V_95 -> V_98 ) ;
if ( ! V_96 )
goto V_40;
V_97 = F_38 ( V_96 ,
V_58 ) ;
V_62 = F_38 ( V_5 , V_58 ) ;
if ( V_62 && V_62 -> V_5 != V_5 && ! V_97 ) {
F_29 ( V_46 , V_3 ,
L_7 ) ;
goto V_40;
}
if ( V_62 )
F_42 ( V_62 ) ;
F_37 ( V_3 , V_5 , V_56 , V_57 ,
V_58 ) ;
V_82 = F_47 ( V_5 , V_58 ) ;
if ( ! V_82 )
goto V_40;
if ( V_82 -> V_99 == F_30 ( V_57 -> V_44 ) )
goto V_40;
V_62 = F_38 ( V_5 , V_58 ) ;
if ( V_56 != V_62 )
goto V_40;
if ( V_58 != V_74 ) {
V_82 -> V_99 = F_30 ( V_57 -> V_44 ) ;
F_44 ( V_3 , V_57 ,
V_61 -> V_12 . V_48 ,
V_70 , V_58 ) ;
}
V_40:
if ( V_82 )
F_51 ( V_82 ) ;
if ( V_62 )
F_42 ( V_62 ) ;
if ( V_97 )
F_42 ( V_97 ) ;
if ( V_96 )
F_5 ( V_96 ) ;
if ( V_61 )
F_41 ( V_61 ) ;
}
static void
F_53 ( struct V_2 * V_3 ,
const struct V_95 * V_95 ,
const struct V_31 * V_57 ,
struct V_1 * V_5 ,
struct V_55 * V_56 ,
struct V_19 * V_70 ,
struct V_19 * V_58 )
{
int V_100 ;
V_100 = F_46 ( V_3 , V_57 , V_5 ,
V_56 , V_70 ,
V_58 ) ;
if ( V_100 < 0 )
return;
if ( ( V_100 > 0 ) && ( V_58 == V_74 ) )
F_54 ( V_3 , true , V_5 ,
NULL , NULL ,
( unsigned char * ) ( V_57 + 1 ) ,
F_45 ( V_57 -> V_37 ) ) ;
F_52 ( V_3 , V_95 , V_57 , V_5 ,
V_56 , V_70 , V_58 ) ;
}
static bool F_55 ( int V_101 , int V_80 ,
T_6 V_37 )
{
int V_102 = 0 ;
V_102 += V_101 + V_41 ;
V_102 += F_45 ( V_37 ) ;
return ( V_102 <= V_80 ) &&
( V_102 <= V_103 ) ;
}
static void F_56 ( const struct V_17 * V_18 , int V_104 ,
struct V_19 * V_70 )
{
struct V_2 * V_3 = F_13 ( V_70 -> V_21 ) ;
struct V_95 * V_95 ;
struct V_1 * V_5 = NULL ;
struct V_105 * V_106 = NULL ;
struct V_55 * V_56 = NULL ;
struct V_19 * V_20 ;
struct V_31 * V_32 ;
T_4 V_107 , V_108 , V_86 ;
V_95 = F_57 ( V_18 ) ;
V_32 = (struct V_31 * ) ( V_18 -> V_43 + V_104 ) ;
V_107 = F_30 ( V_32 -> V_48 ) ;
F_29 ( V_46 , V_3 ,
L_8 ,
V_95 -> V_98 , V_70 -> V_50 -> V_51 ,
V_70 -> V_50 -> V_52 , V_32 -> V_47 ,
F_30 ( V_32 -> V_44 ) , V_107 , V_32 -> V_49 ,
V_32 -> V_109 , F_45 ( V_32 -> V_37 ) ) ;
if ( V_107 == 0 ) {
F_29 ( V_46 , V_3 ,
L_9 ) ;
return;
}
V_106 = F_58 ( V_70 , V_95 -> V_98 ) ;
if ( ! V_106 ) {
F_29 ( V_46 , V_3 ,
L_7 ) ;
goto V_40;
}
V_5 = F_1 ( V_3 , V_32 -> V_47 ) ;
if ( ! V_5 )
return;
V_56 = F_59 ( V_5 , V_70 ,
V_95 -> V_98 ) ;
if ( ! V_56 )
goto V_40;
V_108 = F_60 ( & V_106 -> V_12 . V_48 ) ;
V_86 = F_61 ( T_4 , V_108 , V_107 ) ;
V_32 -> V_48 = F_24 ( V_86 ) ;
F_53 ( V_3 , V_95 , V_32 , V_5 ,
V_56 , V_70 ,
V_74 ) ;
F_27 () ;
F_28 (hard_iface, &batadv_hardif_list, list) {
if ( V_20 -> V_22 != V_23 )
continue;
if ( V_20 -> V_21 != V_3 -> V_21 )
continue;
F_53 ( V_3 , V_95 , V_32 ,
V_5 , V_56 ,
V_70 , V_20 ) ;
}
F_32 () ;
V_40:
if ( V_5 )
F_5 ( V_5 ) ;
if ( V_56 )
F_42 ( V_56 ) ;
if ( V_106 )
F_62 ( V_106 ) ;
}
int F_63 ( struct V_17 * V_18 ,
struct V_19 * V_70 )
{
struct V_2 * V_3 = F_13 ( V_70 -> V_21 ) ;
struct V_31 * V_32 ;
struct V_95 * V_95 = F_57 ( V_18 ) ;
int V_104 ;
T_1 * V_110 ;
int V_84 = V_111 ;
if ( strcmp ( V_3 -> V_112 -> V_51 , L_10 ) != 0 )
return V_111 ;
if ( ! F_64 ( V_18 , V_70 , V_41 ) )
return V_111 ;
if ( F_65 ( V_3 , V_95 -> V_98 ) )
return V_111 ;
V_32 = (struct V_31 * ) V_18 -> V_43 ;
if ( F_65 ( V_3 , V_32 -> V_47 ) )
return V_111 ;
F_14 ( V_3 , V_113 ) ;
F_15 ( V_3 , V_114 ,
V_18 -> V_26 + V_27 ) ;
V_104 = 0 ;
V_32 = (struct V_31 * ) V_18 -> V_43 ;
while ( F_55 ( V_104 , F_66 ( V_18 ) ,
V_32 -> V_37 ) ) {
F_56 ( V_18 , V_104 , V_70 ) ;
V_104 += V_41 ;
V_104 += F_45 ( V_32 -> V_37 ) ;
V_110 = V_18 -> V_43 + V_104 ;
V_32 = (struct V_31 * ) V_110 ;
}
V_84 = V_115 ;
F_33 ( V_18 ) ;
return V_84 ;
}
int F_67 ( struct V_2 * V_3 )
{
struct V_31 * V_32 ;
unsigned char * V_34 ;
T_4 V_116 ;
V_3 -> V_12 . V_36 = V_41 ;
V_34 = F_68 ( V_3 -> V_12 . V_36 , V_53 ) ;
if ( ! V_34 )
return - V_117 ;
V_3 -> V_12 . V_34 = V_34 ;
V_32 = (struct V_31 * ) V_34 ;
V_32 -> V_118 = V_119 ;
V_32 -> V_109 = V_120 ;
V_32 -> V_49 = V_121 ;
V_32 -> V_75 = V_122 ;
V_32 -> V_48 = F_24 ( V_123 ) ;
F_69 ( & V_116 , sizeof( V_116 ) ) ;
F_70 ( & V_3 -> V_12 . V_45 , V_116 ) ;
F_71 ( & V_3 -> V_12 . V_13 , F_17 ) ;
return 0 ;
}
void F_72 ( struct V_2 * V_3 )
{
F_73 ( & V_3 -> V_12 . V_13 ) ;
F_74 ( V_3 -> V_12 . V_34 ) ;
V_3 -> V_12 . V_34 = NULL ;
V_3 -> V_12 . V_36 = 0 ;
}
