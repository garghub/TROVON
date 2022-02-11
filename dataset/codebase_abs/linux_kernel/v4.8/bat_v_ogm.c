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
if ( ! F_29 ( & V_20 -> V_46 ) )
continue;
F_30 ( V_47 , V_3 ,
L_1 ,
V_32 -> V_48 , F_31 ( V_32 -> V_44 ) ,
F_31 ( V_32 -> V_49 ) , V_32 -> V_50 ,
V_20 -> V_51 -> V_52 ,
V_20 -> V_51 -> V_53 ) ;
V_33 = F_32 ( V_18 , V_54 ) ;
if ( ! V_33 ) {
F_33 ( V_20 ) ;
break;
}
F_12 ( V_33 , V_20 ) ;
F_33 ( V_20 ) ;
}
F_34 () ;
F_35 ( V_18 ) ;
V_42:
F_6 ( V_3 ) ;
V_40:
return;
}
int F_36 ( struct V_19 * V_20 )
{
struct V_2 * V_3 = F_13 ( V_20 -> V_21 ) ;
F_6 ( V_3 ) ;
return 0 ;
}
void F_37 ( struct V_19 * V_55 )
{
struct V_2 * V_3 = F_13 ( V_55 -> V_21 ) ;
struct V_31 * V_32 ;
if ( ! V_3 -> V_12 . V_34 )
return;
V_32 = (struct V_31 * ) V_3 -> V_12 . V_34 ;
F_38 ( V_32 -> V_48 , V_55 -> V_51 -> V_53 ) ;
}
static T_3 F_39 ( struct V_2 * V_3 ,
struct V_19 * V_56 ,
struct V_19 * V_57 ,
T_3 V_49 )
{
int V_58 = F_8 ( & V_3 -> V_58 ) ;
int V_59 = V_60 ;
if ( V_57 == V_61 )
return V_49 ;
if ( ( V_49 > 10 ) &&
( V_56 == V_57 ) &&
! ( V_56 -> V_12 . V_62 & V_63 ) )
return V_49 / 2 ;
return V_49 * ( V_59 - V_58 ) / V_59 ;
}
static void F_40 ( struct V_2 * V_3 ,
const struct V_31 * V_64 ,
struct V_1 * V_5 ,
struct V_65 * V_66 ,
struct V_19 * V_56 ,
struct V_19 * V_57 )
{
struct V_67 * V_68 = NULL ;
struct V_69 * V_70 = NULL ;
struct V_65 * V_71 = NULL ;
struct V_31 * V_72 ;
unsigned char * V_73 ;
struct V_17 * V_18 ;
T_4 V_74 ;
T_2 V_37 ;
if ( V_57 == V_61 )
goto V_40;
V_70 = F_41 ( V_5 , V_57 ) ;
if ( ! V_70 )
goto V_40;
V_71 = F_42 ( V_5 , V_57 ) ;
if ( V_66 != V_71 )
goto V_40;
if ( V_70 -> V_75 == F_31 ( V_64 -> V_44 ) )
goto V_40;
V_70 -> V_75 = F_31 ( V_64 -> V_44 ) ;
if ( V_64 -> V_50 <= 1 ) {
F_30 ( V_47 , V_3 , L_2 ) ;
goto V_40;
}
V_68 = F_43 ( V_66 , V_57 ) ;
if ( ! V_68 )
goto V_40;
V_37 = F_44 ( V_64 -> V_37 ) ;
V_74 = V_41 + V_37 ;
V_18 = F_21 ( V_57 -> V_51 ,
V_27 + V_74 ) ;
if ( ! V_18 )
goto V_40;
F_22 ( V_18 , V_27 ) ;
V_73 = F_23 ( V_18 , V_74 ) ;
memcpy ( V_73 , V_64 , V_74 ) ;
V_72 = (struct V_31 * ) V_73 ;
V_72 -> V_49 = F_24 ( V_68 -> V_12 . V_49 ) ;
V_72 -> V_50 -- ;
F_30 ( V_47 , V_3 ,
L_3 ,
V_57 -> V_51 -> V_52 , F_31 ( V_72 -> V_49 ) ,
V_72 -> V_50 , V_56 -> V_51 -> V_52 ) ;
F_12 ( V_18 , V_57 ) ;
V_40:
if ( V_70 )
F_45 ( V_70 ) ;
if ( V_71 )
F_46 ( V_71 ) ;
if ( V_68 )
F_47 ( V_68 ) ;
}
static int F_48 ( struct V_2 * V_3 ,
const struct V_31 * V_76 ,
struct V_1 * V_5 ,
struct V_65 * V_66 ,
struct V_19 * V_56 ,
struct V_19 * V_57 )
{
struct V_69 * V_70 = NULL ;
struct V_67 * V_68 = NULL ;
bool V_77 = false ;
int V_78 = - V_79 ;
T_3 V_80 ;
T_5 V_81 ;
V_70 = F_41 ( V_5 , V_57 ) ;
if ( ! V_70 )
goto V_40;
V_81 = F_31 ( V_76 -> V_44 ) - V_70 -> V_82 ;
if ( ! F_49 ( & V_5 -> V_83 ) &&
F_50 ( V_3 , V_81 ,
V_84 ,
& V_70 -> V_85 ,
& V_77 ) ) {
F_30 ( V_47 , V_3 ,
L_4 ,
V_76 -> V_48 ) ;
F_30 ( V_47 , V_3 ,
L_5 ,
V_70 -> V_85 , V_86 ) ;
goto V_40;
}
if ( ( V_81 < 0 ) && ! V_77 )
goto V_40;
V_66 -> V_87 = V_86 ;
V_5 -> V_87 = V_86 ;
V_70 -> V_82 = F_31 ( V_76 -> V_44 ) ;
V_70 -> V_88 = V_76 -> V_50 ;
V_68 = F_51 ( V_66 , V_57 ) ;
if ( ! V_68 )
goto V_40;
V_80 = F_39 ( V_3 , V_56 ,
V_57 ,
F_31 ( V_76 -> V_49 ) ) ;
V_68 -> V_12 . V_49 = V_80 ;
V_68 -> V_12 . V_89 = F_31 ( V_76 -> V_44 ) ;
V_68 -> V_88 = V_76 -> V_50 ;
if ( V_81 > 0 || V_77 )
V_78 = 1 ;
else
V_78 = 0 ;
V_40:
if ( V_70 )
F_45 ( V_70 ) ;
if ( V_68 )
F_47 ( V_68 ) ;
return V_78 ;
}
static bool F_52 ( struct V_2 * V_3 ,
const struct V_90 * V_90 ,
const struct V_31 * V_76 ,
struct V_1 * V_5 ,
struct V_65 * V_66 ,
struct V_19 * V_56 ,
struct V_19 * V_57 )
{
struct V_65 * V_71 = NULL ;
struct V_1 * V_91 = NULL ;
struct V_65 * V_92 = NULL ;
struct V_67 * V_93 = NULL , * V_68 = NULL ;
T_3 V_94 , V_95 ;
T_3 V_96 ;
T_3 V_97 ;
T_5 V_98 ;
bool V_99 = false ;
V_91 = F_1 ( V_3 , V_90 -> V_100 ) ;
if ( ! V_91 )
goto V_40;
V_92 = F_42 ( V_91 ,
V_57 ) ;
V_71 = F_42 ( V_5 , V_57 ) ;
if ( V_71 && V_71 -> V_5 != V_5 && ! V_92 ) {
F_30 ( V_47 , V_3 ,
L_6 ) ;
goto V_40;
}
V_99 = true ;
F_30 ( V_47 , V_3 ,
L_7 ) ;
if ( V_71 == V_66 )
goto V_40;
if ( V_71 ) {
V_93 = F_43 ( V_71 , V_57 ) ;
V_68 = F_43 ( V_66 , V_57 ) ;
if ( ! V_93 || ! V_68 )
goto V_40;
V_97 = V_68 -> V_12 . V_89 ;
V_96 = V_93 -> V_12 . V_89 ;
V_98 = V_97 - V_96 ;
V_94 = V_93 -> V_12 . V_49 ;
V_95 = V_68 -> V_12 . V_49 ;
if ( ( V_98 < V_101 ) &&
( V_94 >= V_95 ) )
goto V_40;
}
F_53 ( V_3 , V_5 , V_57 , V_66 ) ;
V_40:
if ( V_71 )
F_46 ( V_71 ) ;
if ( V_92 )
F_46 ( V_92 ) ;
if ( V_91 )
F_5 ( V_91 ) ;
if ( V_93 )
F_47 ( V_93 ) ;
if ( V_68 )
F_47 ( V_68 ) ;
return V_99 ;
}
static void
F_54 ( struct V_2 * V_3 ,
const struct V_90 * V_90 ,
const struct V_31 * V_76 ,
struct V_1 * V_5 ,
struct V_65 * V_66 ,
struct V_19 * V_56 ,
struct V_19 * V_57 )
{
int V_102 ;
bool V_99 ;
V_102 = F_48 ( V_3 , V_76 , V_5 ,
V_66 , V_56 ,
V_57 ) ;
if ( V_102 < 0 )
return;
if ( ( V_102 > 0 ) && ( V_57 == V_61 ) )
F_55 ( V_3 , true , V_5 ,
NULL , NULL ,
( unsigned char * ) ( V_76 + 1 ) ,
F_44 ( V_76 -> V_37 ) ) ;
V_99 = F_52 ( V_3 , V_90 , V_76 , V_5 ,
V_66 , V_56 ,
V_57 ) ;
if ( V_99 )
F_40 ( V_3 , V_76 , V_5 , V_66 ,
V_56 , V_57 ) ;
}
static bool F_56 ( int V_103 , int V_74 ,
T_6 V_37 )
{
int V_104 = 0 ;
V_104 += V_103 + V_41 ;
V_104 += F_44 ( V_37 ) ;
return ( V_104 <= V_74 ) &&
( V_104 <= V_105 ) ;
}
static void F_57 ( const struct V_17 * V_18 , int V_106 ,
struct V_19 * V_56 )
{
struct V_2 * V_3 = F_13 ( V_56 -> V_21 ) ;
struct V_90 * V_90 ;
struct V_1 * V_5 = NULL ;
struct V_107 * V_108 = NULL ;
struct V_65 * V_66 = NULL ;
struct V_19 * V_20 ;
struct V_31 * V_32 ;
T_3 V_109 , V_110 , V_80 ;
V_90 = F_58 ( V_18 ) ;
V_32 = (struct V_31 * ) ( V_18 -> V_43 + V_106 ) ;
V_109 = F_31 ( V_32 -> V_49 ) ;
F_30 ( V_47 , V_3 ,
L_8 ,
V_90 -> V_100 , V_56 -> V_51 -> V_52 ,
V_56 -> V_51 -> V_53 , V_32 -> V_48 ,
F_31 ( V_32 -> V_44 ) , V_109 , V_32 -> V_50 ,
V_32 -> V_111 , F_44 ( V_32 -> V_37 ) ) ;
if ( V_109 == 0 ) {
F_30 ( V_47 , V_3 ,
L_9 ) ;
return;
}
V_108 = F_59 ( V_56 , V_90 -> V_100 ) ;
if ( ! V_108 ) {
F_30 ( V_47 , V_3 ,
L_6 ) ;
goto V_40;
}
V_5 = F_1 ( V_3 , V_32 -> V_48 ) ;
if ( ! V_5 )
return;
V_66 = F_60 ( V_5 , V_56 ,
V_90 -> V_100 ) ;
if ( ! V_66 )
goto V_40;
V_110 = F_61 ( & V_108 -> V_12 . V_49 ) ;
V_80 = F_62 ( T_3 , V_110 , V_109 ) ;
V_32 -> V_49 = F_24 ( V_80 ) ;
F_54 ( V_3 , V_90 , V_32 , V_5 ,
V_66 , V_56 ,
V_61 ) ;
F_27 () ;
F_28 (hard_iface, &batadv_hardif_list, list) {
if ( V_20 -> V_22 != V_23 )
continue;
if ( V_20 -> V_21 != V_3 -> V_21 )
continue;
if ( ! F_29 ( & V_20 -> V_46 ) )
continue;
F_54 ( V_3 , V_90 , V_32 ,
V_5 , V_66 ,
V_56 , V_20 ) ;
F_33 ( V_20 ) ;
}
F_34 () ;
V_40:
if ( V_5 )
F_5 ( V_5 ) ;
if ( V_66 )
F_46 ( V_66 ) ;
if ( V_108 )
F_63 ( V_108 ) ;
}
int F_64 ( struct V_17 * V_18 ,
struct V_19 * V_56 )
{
struct V_2 * V_3 = F_13 ( V_56 -> V_21 ) ;
struct V_31 * V_32 ;
struct V_90 * V_90 = F_58 ( V_18 ) ;
int V_106 ;
T_1 * V_112 ;
int V_78 = V_113 ;
if ( strcmp ( V_3 -> V_114 -> V_52 , L_10 ) != 0 )
return V_113 ;
if ( ! F_65 ( V_18 , V_56 , V_41 ) )
return V_113 ;
if ( F_66 ( V_3 , V_90 -> V_100 ) )
return V_113 ;
V_32 = (struct V_31 * ) V_18 -> V_43 ;
if ( F_66 ( V_3 , V_32 -> V_48 ) )
return V_113 ;
F_14 ( V_3 , V_115 ) ;
F_15 ( V_3 , V_116 ,
V_18 -> V_26 + V_27 ) ;
V_106 = 0 ;
V_32 = (struct V_31 * ) V_18 -> V_43 ;
while ( F_56 ( V_106 , F_67 ( V_18 ) ,
V_32 -> V_37 ) ) {
F_57 ( V_18 , V_106 , V_56 ) ;
V_106 += V_41 ;
V_106 += F_44 ( V_32 -> V_37 ) ;
V_112 = V_18 -> V_43 + V_106 ;
V_32 = (struct V_31 * ) V_112 ;
}
V_78 = V_117 ;
F_35 ( V_18 ) ;
return V_78 ;
}
int F_68 ( struct V_2 * V_3 )
{
struct V_31 * V_32 ;
unsigned char * V_34 ;
T_3 V_118 ;
V_3 -> V_12 . V_36 = V_41 ;
V_34 = F_69 ( V_3 -> V_12 . V_36 , V_54 ) ;
if ( ! V_34 )
return - V_119 ;
V_3 -> V_12 . V_34 = V_34 ;
V_32 = (struct V_31 * ) V_34 ;
V_32 -> V_120 = V_121 ;
V_32 -> V_111 = V_122 ;
V_32 -> V_50 = V_123 ;
V_32 -> V_62 = V_124 ;
V_32 -> V_49 = F_24 ( V_125 ) ;
F_70 ( & V_118 , sizeof( V_118 ) ) ;
F_71 ( & V_3 -> V_12 . V_45 , V_118 ) ;
F_72 ( & V_3 -> V_12 . V_13 , F_17 ) ;
return 0 ;
}
void F_73 ( struct V_2 * V_3 )
{
F_74 ( & V_3 -> V_12 . V_13 ) ;
F_75 ( V_3 -> V_12 . V_34 ) ;
V_3 -> V_12 . V_34 = NULL ;
V_3 -> V_12 . V_36 = 0 ;
}
