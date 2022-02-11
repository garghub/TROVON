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
F_4 ( & V_5 -> V_7 ) ;
V_6 = F_5 ( V_3 -> V_8 , V_9 ,
V_10 , V_5 ,
& V_5 -> V_11 ) ;
if ( V_6 != 0 ) {
F_6 ( V_5 ) ;
F_6 ( V_5 ) ;
V_5 = NULL ;
}
return V_5 ;
}
static void F_7 ( struct V_2 * V_3 )
{
unsigned long V_12 ;
if ( F_8 ( & V_3 -> V_13 . V_14 ) )
return;
V_12 = F_9 ( & V_3 -> V_15 ) - V_16 ;
V_12 += F_10 () % ( 2 * V_16 ) ;
F_11 ( V_17 , & V_3 -> V_13 . V_14 ,
F_12 ( V_12 ) ) ;
}
static void F_13 ( struct V_18 * V_19 ,
struct V_20 * V_21 )
{
struct V_2 * V_3 = F_14 ( V_21 -> V_22 ) ;
if ( V_21 -> V_23 != V_24 )
return;
F_15 ( V_3 , V_25 ) ;
F_16 ( V_3 , V_26 ,
V_19 -> V_27 + V_28 ) ;
F_17 ( V_19 , V_21 ) ;
}
static void F_18 ( struct V_29 * V_30 )
{
struct V_20 * V_21 ;
struct V_31 * V_13 ;
struct V_2 * V_3 ;
struct V_32 * V_33 ;
struct V_18 * V_19 , * V_34 ;
unsigned char * V_35 , * V_36 ;
int V_37 ;
T_2 V_38 = 0 ;
V_13 = F_19 ( V_30 , struct V_31 , V_14 . V_30 ) ;
V_3 = F_19 ( V_13 , struct V_2 , V_13 ) ;
if ( F_9 ( & V_3 -> V_39 ) == V_40 )
goto V_41;
V_35 = V_3 -> V_13 . V_35 ;
V_37 = V_3 -> V_13 . V_37 ;
F_20 ( V_3 ) ;
V_38 = F_21 ( V_3 , & V_35 ,
& V_37 ,
V_42 ) ;
V_3 -> V_13 . V_35 = V_35 ;
V_3 -> V_13 . V_37 = V_37 ;
V_19 = F_22 ( NULL , V_28 + V_37 ) ;
if ( ! V_19 )
goto V_43;
F_23 ( V_19 , V_28 ) ;
V_36 = F_24 ( V_19 , V_37 ) ;
memcpy ( V_36 , V_35 , V_37 ) ;
V_33 = (struct V_32 * ) V_19 -> V_44 ;
V_33 -> V_45 = F_25 ( F_9 ( & V_3 -> V_13 . V_46 ) ) ;
F_26 ( & V_3 -> V_13 . V_46 ) ;
V_33 -> V_38 = F_27 ( V_38 ) ;
F_28 () ;
F_29 (hard_iface, &batadv_hardif_list, list) {
if ( V_21 -> V_22 != V_3 -> V_22 )
continue;
if ( ! F_30 ( & V_21 -> V_7 ) )
continue;
F_31 ( V_47 , V_3 ,
L_1 ,
V_33 -> V_48 , F_32 ( V_33 -> V_45 ) ,
F_32 ( V_33 -> V_49 ) , V_33 -> V_50 ,
V_21 -> V_51 -> V_52 ,
V_21 -> V_51 -> V_53 ) ;
V_34 = F_33 ( V_19 , V_54 ) ;
if ( ! V_34 ) {
F_34 ( V_21 ) ;
break;
}
F_13 ( V_34 , V_21 ) ;
F_34 ( V_21 ) ;
}
F_35 () ;
F_36 ( V_19 ) ;
V_43:
F_7 ( V_3 ) ;
V_41:
return;
}
int F_37 ( struct V_20 * V_21 )
{
struct V_2 * V_3 = F_14 ( V_21 -> V_22 ) ;
F_7 ( V_3 ) ;
return 0 ;
}
void F_38 ( struct V_20 * V_55 )
{
struct V_2 * V_3 = F_14 ( V_55 -> V_22 ) ;
struct V_32 * V_33 ;
if ( ! V_3 -> V_13 . V_35 )
return;
V_33 = (struct V_32 * ) V_3 -> V_13 . V_35 ;
F_39 ( V_33 -> V_48 , V_55 -> V_51 -> V_53 ) ;
}
static T_3 F_40 ( struct V_2 * V_3 ,
struct V_20 * V_56 ,
struct V_20 * V_57 ,
T_3 V_49 )
{
int V_58 = F_9 ( & V_3 -> V_58 ) ;
int V_59 = V_60 ;
if ( V_57 == V_61 )
return V_49 ;
if ( ( V_49 > 10 ) &&
( V_56 == V_57 ) &&
! ( V_56 -> V_13 . V_62 & V_63 ) )
return V_49 / 2 ;
return V_49 * ( V_59 - V_58 ) / V_59 ;
}
static void F_41 ( struct V_2 * V_3 ,
const struct V_32 * V_64 ,
struct V_1 * V_5 ,
struct V_65 * V_66 ,
struct V_20 * V_56 ,
struct V_20 * V_57 )
{
struct V_67 * V_68 = NULL ;
struct V_69 * V_70 = NULL ;
struct V_65 * V_71 = NULL ;
struct V_32 * V_72 ;
unsigned char * V_73 ;
struct V_18 * V_19 ;
T_4 V_74 ;
T_2 V_38 ;
if ( V_57 == V_61 )
goto V_41;
V_70 = F_42 ( V_5 , V_57 ) ;
if ( ! V_70 )
goto V_41;
V_71 = F_43 ( V_5 , V_57 ) ;
if ( V_66 != V_71 )
goto V_41;
if ( V_70 -> V_75 == F_32 ( V_64 -> V_45 ) )
goto V_41;
V_70 -> V_75 = F_32 ( V_64 -> V_45 ) ;
if ( V_64 -> V_50 <= 1 ) {
F_31 ( V_47 , V_3 , L_2 ) ;
goto V_41;
}
V_68 = F_44 ( V_66 , V_57 ) ;
if ( ! V_68 )
goto V_41;
V_38 = F_45 ( V_64 -> V_38 ) ;
V_74 = V_42 + V_38 ;
V_19 = F_22 ( V_57 -> V_51 ,
V_28 + V_74 ) ;
if ( ! V_19 )
goto V_41;
F_23 ( V_19 , V_28 ) ;
V_73 = F_24 ( V_19 , V_74 ) ;
memcpy ( V_73 , V_64 , V_74 ) ;
V_72 = (struct V_32 * ) V_73 ;
V_72 -> V_49 = F_25 ( V_68 -> V_13 . V_49 ) ;
V_72 -> V_50 -- ;
F_31 ( V_47 , V_3 ,
L_3 ,
V_57 -> V_51 -> V_52 , F_32 ( V_72 -> V_49 ) ,
V_72 -> V_50 , V_56 -> V_51 -> V_52 ) ;
F_13 ( V_19 , V_57 ) ;
V_41:
if ( V_70 )
F_46 ( V_70 ) ;
if ( V_71 )
F_47 ( V_71 ) ;
if ( V_68 )
F_48 ( V_68 ) ;
}
static int F_49 ( struct V_2 * V_3 ,
const struct V_32 * V_76 ,
struct V_1 * V_5 ,
struct V_65 * V_66 ,
struct V_20 * V_56 ,
struct V_20 * V_57 )
{
struct V_69 * V_70 = NULL ;
struct V_67 * V_68 = NULL ;
bool V_77 = false ;
int V_78 = - V_79 ;
T_3 V_80 ;
T_5 V_81 ;
V_70 = F_42 ( V_5 , V_57 ) ;
if ( ! V_70 )
goto V_41;
V_81 = F_32 ( V_76 -> V_45 ) - V_70 -> V_82 ;
if ( ! F_50 ( & V_5 -> V_83 ) &&
F_51 ( V_3 , V_81 ,
V_84 ,
& V_70 -> V_85 ,
& V_77 ) ) {
F_31 ( V_47 , V_3 ,
L_4 ,
V_76 -> V_48 ) ;
F_31 ( V_47 , V_3 ,
L_5 ,
V_70 -> V_85 , V_86 ) ;
goto V_41;
}
if ( ( V_81 < 0 ) && ! V_77 )
goto V_41;
V_66 -> V_87 = V_86 ;
V_5 -> V_87 = V_86 ;
V_70 -> V_82 = F_32 ( V_76 -> V_45 ) ;
V_70 -> V_88 = V_76 -> V_50 ;
V_68 = F_52 ( V_66 , V_57 ) ;
if ( ! V_68 )
goto V_41;
V_80 = F_40 ( V_3 , V_56 ,
V_57 ,
F_32 ( V_76 -> V_49 ) ) ;
V_68 -> V_13 . V_49 = V_80 ;
V_68 -> V_13 . V_89 = F_32 ( V_76 -> V_45 ) ;
V_68 -> V_88 = V_76 -> V_50 ;
if ( V_81 > 0 || V_77 )
V_78 = 1 ;
else
V_78 = 0 ;
V_41:
if ( V_70 )
F_46 ( V_70 ) ;
if ( V_68 )
F_48 ( V_68 ) ;
return V_78 ;
}
static bool F_53 ( struct V_2 * V_3 ,
const struct V_90 * V_90 ,
const struct V_32 * V_76 ,
struct V_1 * V_5 ,
struct V_65 * V_66 ,
struct V_20 * V_56 ,
struct V_20 * V_57 )
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
goto V_41;
V_92 = F_43 ( V_91 ,
V_57 ) ;
V_71 = F_43 ( V_5 , V_57 ) ;
if ( V_71 && V_71 -> V_5 != V_5 && ! V_92 ) {
F_31 ( V_47 , V_3 ,
L_6 ) ;
goto V_41;
}
V_99 = true ;
F_31 ( V_47 , V_3 ,
L_7 ) ;
if ( V_71 == V_66 )
goto V_41;
if ( V_71 ) {
V_93 = F_44 ( V_71 , V_57 ) ;
V_68 = F_44 ( V_66 , V_57 ) ;
if ( ! V_93 || ! V_68 )
goto V_41;
V_97 = V_68 -> V_13 . V_89 ;
V_96 = V_93 -> V_13 . V_89 ;
V_98 = V_97 - V_96 ;
V_94 = V_93 -> V_13 . V_49 ;
V_95 = V_68 -> V_13 . V_49 ;
if ( ( V_98 < V_101 ) &&
( V_94 >= V_95 ) )
goto V_41;
}
F_54 ( V_3 , V_5 , V_57 , V_66 ) ;
V_41:
if ( V_71 )
F_47 ( V_71 ) ;
if ( V_92 )
F_47 ( V_92 ) ;
if ( V_91 )
F_6 ( V_91 ) ;
if ( V_93 )
F_48 ( V_93 ) ;
if ( V_68 )
F_48 ( V_68 ) ;
return V_99 ;
}
static void
F_55 ( struct V_2 * V_3 ,
const struct V_90 * V_90 ,
const struct V_32 * V_76 ,
struct V_1 * V_5 ,
struct V_65 * V_66 ,
struct V_20 * V_56 ,
struct V_20 * V_57 )
{
int V_102 ;
bool V_99 ;
V_102 = F_49 ( V_3 , V_76 , V_5 ,
V_66 , V_56 ,
V_57 ) ;
if ( V_102 < 0 )
return;
if ( ( V_102 > 0 ) && ( V_57 == V_61 ) )
F_56 ( V_3 , true , V_5 ,
NULL , NULL ,
( unsigned char * ) ( V_76 + 1 ) ,
F_45 ( V_76 -> V_38 ) ) ;
V_99 = F_53 ( V_3 , V_90 , V_76 , V_5 ,
V_66 , V_56 ,
V_57 ) ;
if ( V_99 )
F_41 ( V_3 , V_76 , V_5 , V_66 ,
V_56 , V_57 ) ;
}
static bool F_57 ( int V_103 , int V_74 ,
T_6 V_38 )
{
int V_104 = 0 ;
V_104 += V_103 + V_42 ;
V_104 += F_45 ( V_38 ) ;
return ( V_104 <= V_74 ) &&
( V_104 <= V_105 ) ;
}
static void F_58 ( const struct V_18 * V_19 , int V_106 ,
struct V_20 * V_56 )
{
struct V_2 * V_3 = F_14 ( V_56 -> V_22 ) ;
struct V_90 * V_90 ;
struct V_1 * V_5 = NULL ;
struct V_107 * V_108 = NULL ;
struct V_65 * V_66 = NULL ;
struct V_20 * V_21 ;
struct V_32 * V_33 ;
T_3 V_109 , V_110 , V_80 ;
V_90 = F_59 ( V_19 ) ;
V_33 = (struct V_32 * ) ( V_19 -> V_44 + V_106 ) ;
V_109 = F_32 ( V_33 -> V_49 ) ;
F_31 ( V_47 , V_3 ,
L_8 ,
V_90 -> V_100 , V_56 -> V_51 -> V_52 ,
V_56 -> V_51 -> V_53 , V_33 -> V_48 ,
F_32 ( V_33 -> V_45 ) , V_109 , V_33 -> V_50 ,
V_33 -> V_111 , F_45 ( V_33 -> V_38 ) ) ;
if ( V_109 == 0 ) {
F_31 ( V_47 , V_3 ,
L_9 ) ;
return;
}
V_108 = F_60 ( V_56 , V_90 -> V_100 ) ;
if ( ! V_108 ) {
F_31 ( V_47 , V_3 ,
L_6 ) ;
goto V_41;
}
V_5 = F_1 ( V_3 , V_33 -> V_48 ) ;
if ( ! V_5 )
return;
V_66 = F_61 ( V_5 , V_56 ,
V_90 -> V_100 ) ;
if ( ! V_66 )
goto V_41;
V_110 = F_62 ( & V_108 -> V_13 . V_49 ) ;
V_80 = F_63 ( T_3 , V_110 , V_109 ) ;
V_33 -> V_49 = F_25 ( V_80 ) ;
F_55 ( V_3 , V_90 , V_33 , V_5 ,
V_66 , V_56 ,
V_61 ) ;
F_28 () ;
F_29 (hard_iface, &batadv_hardif_list, list) {
if ( V_21 -> V_23 != V_24 )
continue;
if ( V_21 -> V_22 != V_3 -> V_22 )
continue;
if ( ! F_30 ( & V_21 -> V_7 ) )
continue;
F_55 ( V_3 , V_90 , V_33 ,
V_5 , V_66 ,
V_56 , V_21 ) ;
F_34 ( V_21 ) ;
}
F_35 () ;
V_41:
if ( V_5 )
F_6 ( V_5 ) ;
if ( V_66 )
F_47 ( V_66 ) ;
if ( V_108 )
F_64 ( V_108 ) ;
}
int F_65 ( struct V_18 * V_19 ,
struct V_20 * V_56 )
{
struct V_2 * V_3 = F_14 ( V_56 -> V_22 ) ;
struct V_32 * V_33 ;
struct V_90 * V_90 = F_59 ( V_19 ) ;
int V_106 ;
T_1 * V_112 ;
int V_78 = V_113 ;
if ( strcmp ( V_3 -> V_114 -> V_52 , L_10 ) != 0 )
return V_113 ;
if ( ! F_66 ( V_19 , V_56 , V_42 ) )
return V_113 ;
if ( F_67 ( V_3 , V_90 -> V_100 ) )
return V_113 ;
V_33 = (struct V_32 * ) V_19 -> V_44 ;
if ( F_67 ( V_3 , V_33 -> V_48 ) )
return V_113 ;
F_15 ( V_3 , V_115 ) ;
F_16 ( V_3 , V_116 ,
V_19 -> V_27 + V_28 ) ;
V_106 = 0 ;
V_33 = (struct V_32 * ) V_19 -> V_44 ;
while ( F_57 ( V_106 , F_68 ( V_19 ) ,
V_33 -> V_38 ) ) {
F_58 ( V_19 , V_106 , V_56 ) ;
V_106 += V_42 ;
V_106 += F_45 ( V_33 -> V_38 ) ;
V_112 = V_19 -> V_44 + V_106 ;
V_33 = (struct V_32 * ) V_112 ;
}
V_78 = V_117 ;
F_36 ( V_19 ) ;
return V_78 ;
}
int F_69 ( struct V_2 * V_3 )
{
struct V_32 * V_33 ;
unsigned char * V_35 ;
T_3 V_118 ;
V_3 -> V_13 . V_37 = V_42 ;
V_35 = F_70 ( V_3 -> V_13 . V_37 , V_54 ) ;
if ( ! V_35 )
return - V_119 ;
V_3 -> V_13 . V_35 = V_35 ;
V_33 = (struct V_32 * ) V_35 ;
V_33 -> V_120 = V_121 ;
V_33 -> V_111 = V_122 ;
V_33 -> V_50 = V_123 ;
V_33 -> V_62 = V_124 ;
V_33 -> V_49 = F_25 ( V_125 ) ;
F_71 ( & V_118 , sizeof( V_118 ) ) ;
F_72 ( & V_3 -> V_13 . V_46 , V_118 ) ;
F_73 ( & V_3 -> V_13 . V_14 , F_18 ) ;
return 0 ;
}
void F_74 ( struct V_2 * V_3 )
{
F_75 ( & V_3 -> V_13 . V_14 ) ;
F_76 ( V_3 -> V_13 . V_35 ) ;
V_3 -> V_13 . V_35 = NULL ;
V_3 -> V_13 . V_37 = 0 ;
}
