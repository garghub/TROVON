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
int V_39 ;
V_13 = F_19 ( V_30 , struct V_31 , V_14 . V_30 ) ;
V_3 = F_19 ( V_13 , struct V_2 , V_13 ) ;
if ( F_9 ( & V_3 -> V_40 ) == V_41 )
goto V_42;
V_35 = V_3 -> V_13 . V_35 ;
V_37 = V_3 -> V_13 . V_37 ;
F_20 ( V_3 ) ;
V_38 = F_21 ( V_3 , & V_35 ,
& V_37 ,
V_43 ) ;
V_3 -> V_13 . V_35 = V_35 ;
V_3 -> V_13 . V_37 = V_37 ;
V_19 = F_22 ( NULL , V_28 + V_37 ) ;
if ( ! V_19 )
goto V_44;
F_23 ( V_19 , V_28 ) ;
V_36 = F_24 ( V_19 , V_37 ) ;
memcpy ( V_36 , V_35 , V_37 ) ;
V_33 = (struct V_32 * ) V_19 -> V_45 ;
V_33 -> V_46 = F_25 ( F_9 ( & V_3 -> V_13 . V_47 ) ) ;
F_26 ( & V_3 -> V_13 . V_47 ) ;
V_33 -> V_38 = F_27 ( V_38 ) ;
F_28 () ;
F_29 (hard_iface, &batadv_hardif_list, list) {
if ( V_21 -> V_22 != V_3 -> V_22 )
continue;
if ( ! F_30 ( & V_21 -> V_7 ) )
continue;
V_39 = F_31 ( V_21 , NULL , NULL ) ;
if ( V_39 ) {
char * type ;
switch ( V_39 ) {
case V_48 :
type = L_1 ;
break;
case V_49 :
type = L_2 ;
break;
case V_50 :
type = L_3 ;
break;
default:
type = L_4 ;
}
F_32 ( V_51 , V_3 , L_5 ,
V_21 -> V_52 -> V_53 , type ) ;
F_33 ( V_21 ) ;
continue;
}
F_32 ( V_51 , V_3 ,
L_6 ,
V_33 -> V_54 , F_34 ( V_33 -> V_46 ) ,
F_34 ( V_33 -> V_55 ) , V_33 -> V_56 ,
V_21 -> V_52 -> V_53 ,
V_21 -> V_52 -> V_57 ) ;
V_34 = F_35 ( V_19 , V_58 ) ;
if ( ! V_34 ) {
F_33 ( V_21 ) ;
break;
}
F_13 ( V_34 , V_21 ) ;
F_33 ( V_21 ) ;
}
F_36 () ;
F_37 ( V_19 ) ;
V_44:
F_7 ( V_3 ) ;
V_42:
return;
}
int F_38 ( struct V_20 * V_21 )
{
struct V_2 * V_3 = F_14 ( V_21 -> V_22 ) ;
F_7 ( V_3 ) ;
return 0 ;
}
void F_39 ( struct V_20 * V_59 )
{
struct V_2 * V_3 = F_14 ( V_59 -> V_22 ) ;
struct V_32 * V_33 ;
if ( ! V_3 -> V_13 . V_35 )
return;
V_33 = (struct V_32 * ) V_3 -> V_13 . V_35 ;
F_40 ( V_33 -> V_54 , V_59 -> V_52 -> V_57 ) ;
}
static T_3 F_41 ( struct V_2 * V_3 ,
struct V_20 * V_60 ,
struct V_20 * V_61 ,
T_3 V_55 )
{
int V_62 = F_9 ( & V_3 -> V_62 ) ;
int V_63 = V_64 ;
if ( V_61 == V_65 )
return V_55 ;
if ( ( V_55 > 10 ) &&
( V_60 == V_61 ) &&
! ( V_60 -> V_13 . V_66 & V_67 ) )
return V_55 / 2 ;
return V_55 * ( V_63 - V_62 ) / V_63 ;
}
static void F_42 ( struct V_2 * V_3 ,
const struct V_32 * V_68 ,
struct V_1 * V_5 ,
struct V_69 * V_70 ,
struct V_20 * V_60 ,
struct V_20 * V_61 )
{
struct V_71 * V_72 = NULL ;
struct V_73 * V_74 = NULL ;
struct V_69 * V_75 = NULL ;
struct V_32 * V_76 ;
unsigned char * V_77 ;
struct V_18 * V_19 ;
T_4 V_78 ;
T_2 V_38 ;
if ( V_61 == V_65 )
goto V_42;
V_74 = F_43 ( V_5 , V_61 ) ;
if ( ! V_74 )
goto V_42;
V_75 = F_44 ( V_5 , V_61 ) ;
if ( V_70 != V_75 )
goto V_42;
if ( V_74 -> V_79 == F_34 ( V_68 -> V_46 ) )
goto V_42;
V_74 -> V_79 = F_34 ( V_68 -> V_46 ) ;
if ( V_68 -> V_56 <= 1 ) {
F_32 ( V_51 , V_3 , L_7 ) ;
goto V_42;
}
V_72 = F_45 ( V_70 , V_61 ) ;
if ( ! V_72 )
goto V_42;
V_38 = F_46 ( V_68 -> V_38 ) ;
V_78 = V_43 + V_38 ;
V_19 = F_22 ( V_61 -> V_52 ,
V_28 + V_78 ) ;
if ( ! V_19 )
goto V_42;
F_23 ( V_19 , V_28 ) ;
V_77 = F_24 ( V_19 , V_78 ) ;
memcpy ( V_77 , V_68 , V_78 ) ;
V_76 = (struct V_32 * ) V_77 ;
V_76 -> V_55 = F_25 ( V_72 -> V_13 . V_55 ) ;
V_76 -> V_56 -- ;
F_32 ( V_51 , V_3 ,
L_8 ,
V_61 -> V_52 -> V_53 , F_34 ( V_76 -> V_55 ) ,
V_76 -> V_56 , V_60 -> V_52 -> V_53 ) ;
F_13 ( V_19 , V_61 ) ;
V_42:
if ( V_74 )
F_47 ( V_74 ) ;
if ( V_75 )
F_48 ( V_75 ) ;
if ( V_72 )
F_49 ( V_72 ) ;
}
static int F_50 ( struct V_2 * V_3 ,
const struct V_32 * V_80 ,
struct V_1 * V_5 ,
struct V_69 * V_70 ,
struct V_20 * V_60 ,
struct V_20 * V_61 )
{
struct V_73 * V_74 ;
struct V_71 * V_72 = NULL ;
bool V_81 = false ;
int V_39 = - V_82 ;
T_3 V_83 ;
T_5 V_84 ;
V_74 = F_43 ( V_5 , V_61 ) ;
if ( ! V_74 )
goto V_42;
V_84 = F_34 ( V_80 -> V_46 ) - V_74 -> V_85 ;
if ( ! F_51 ( & V_5 -> V_86 ) &&
F_52 ( V_3 , V_84 ,
V_87 ,
& V_74 -> V_88 ,
& V_81 ) ) {
F_32 ( V_51 , V_3 ,
L_9 ,
V_80 -> V_54 ) ;
F_32 ( V_51 , V_3 ,
L_10 ,
V_74 -> V_88 , V_89 ) ;
goto V_42;
}
if ( ( V_84 < 0 ) && ! V_81 )
goto V_42;
V_70 -> V_90 = V_89 ;
V_5 -> V_90 = V_89 ;
V_74 -> V_85 = F_34 ( V_80 -> V_46 ) ;
V_74 -> V_91 = V_80 -> V_56 ;
V_72 = F_53 ( V_70 , V_61 ) ;
if ( ! V_72 )
goto V_42;
V_83 = F_41 ( V_3 , V_60 ,
V_61 ,
F_34 ( V_80 -> V_55 ) ) ;
V_72 -> V_13 . V_55 = V_83 ;
V_72 -> V_13 . V_92 = F_34 ( V_80 -> V_46 ) ;
V_72 -> V_91 = V_80 -> V_56 ;
if ( V_84 > 0 || V_81 )
V_39 = 1 ;
else
V_39 = 0 ;
V_42:
if ( V_74 )
F_47 ( V_74 ) ;
if ( V_72 )
F_49 ( V_72 ) ;
return V_39 ;
}
static bool F_54 ( struct V_2 * V_3 ,
const struct V_93 * V_93 ,
const struct V_32 * V_80 ,
struct V_1 * V_5 ,
struct V_69 * V_70 ,
struct V_20 * V_60 ,
struct V_20 * V_61 )
{
struct V_69 * V_75 = NULL ;
struct V_1 * V_94 ;
struct V_69 * V_95 = NULL ;
struct V_71 * V_96 = NULL , * V_72 = NULL ;
T_3 V_97 , V_98 ;
T_3 V_99 ;
T_3 V_100 ;
T_5 V_101 ;
bool V_102 = false ;
V_94 = F_1 ( V_3 , V_93 -> V_103 ) ;
if ( ! V_94 )
goto V_42;
V_95 = F_44 ( V_94 ,
V_61 ) ;
V_75 = F_44 ( V_5 , V_61 ) ;
if ( V_75 && V_75 -> V_5 != V_5 && ! V_95 ) {
F_32 ( V_51 , V_3 ,
L_11 ) ;
goto V_42;
}
V_102 = true ;
F_32 ( V_51 , V_3 ,
L_12 ) ;
if ( V_75 == V_70 )
goto V_42;
if ( V_75 ) {
V_96 = F_45 ( V_75 , V_61 ) ;
V_72 = F_45 ( V_70 , V_61 ) ;
if ( ! V_96 || ! V_72 )
goto V_42;
V_100 = V_72 -> V_13 . V_92 ;
V_99 = V_96 -> V_13 . V_92 ;
V_101 = V_100 - V_99 ;
V_97 = V_96 -> V_13 . V_55 ;
V_98 = V_72 -> V_13 . V_55 ;
if ( ( V_101 < V_104 ) &&
( V_97 >= V_98 ) )
goto V_42;
}
F_55 ( V_3 , V_5 , V_61 , V_70 ) ;
V_42:
if ( V_75 )
F_48 ( V_75 ) ;
if ( V_95 )
F_48 ( V_95 ) ;
if ( V_94 )
F_6 ( V_94 ) ;
if ( V_96 )
F_49 ( V_96 ) ;
if ( V_72 )
F_49 ( V_72 ) ;
return V_102 ;
}
static void
F_56 ( struct V_2 * V_3 ,
const struct V_93 * V_93 ,
const struct V_32 * V_80 ,
struct V_1 * V_5 ,
struct V_69 * V_70 ,
struct V_20 * V_60 ,
struct V_20 * V_61 )
{
int V_105 ;
bool V_102 ;
V_105 = F_50 ( V_3 , V_80 , V_5 ,
V_70 , V_60 ,
V_61 ) ;
if ( V_105 < 0 )
return;
if ( ( V_105 > 0 ) && ( V_61 == V_65 ) )
F_57 ( V_3 , true , V_5 ,
NULL , NULL ,
( unsigned char * ) ( V_80 + 1 ) ,
F_46 ( V_80 -> V_38 ) ) ;
V_102 = F_54 ( V_3 , V_93 , V_80 , V_5 ,
V_70 , V_60 ,
V_61 ) ;
if ( V_102 )
F_42 ( V_3 , V_80 , V_5 , V_70 ,
V_60 , V_61 ) ;
}
static bool F_58 ( int V_106 , int V_78 ,
T_6 V_38 )
{
int V_107 = 0 ;
V_107 += V_106 + V_43 ;
V_107 += F_46 ( V_38 ) ;
return ( V_107 <= V_78 ) &&
( V_107 <= V_108 ) ;
}
static void F_59 ( const struct V_18 * V_19 , int V_109 ,
struct V_20 * V_60 )
{
struct V_2 * V_3 = F_14 ( V_60 -> V_22 ) ;
struct V_93 * V_93 ;
struct V_1 * V_5 = NULL ;
struct V_110 * V_111 = NULL ;
struct V_69 * V_70 = NULL ;
struct V_20 * V_21 ;
struct V_32 * V_33 ;
T_3 V_112 , V_113 , V_83 ;
int V_39 ;
V_93 = F_60 ( V_19 ) ;
V_33 = (struct V_32 * ) ( V_19 -> V_45 + V_109 ) ;
V_112 = F_34 ( V_33 -> V_55 ) ;
F_32 ( V_51 , V_3 ,
L_13 ,
V_93 -> V_103 , V_60 -> V_52 -> V_53 ,
V_60 -> V_52 -> V_57 , V_33 -> V_54 ,
F_34 ( V_33 -> V_46 ) , V_112 , V_33 -> V_56 ,
V_33 -> V_114 , F_46 ( V_33 -> V_38 ) ) ;
if ( V_112 == 0 ) {
F_32 ( V_51 , V_3 ,
L_14 ) ;
return;
}
V_111 = F_61 ( V_60 , V_93 -> V_103 ) ;
if ( ! V_111 ) {
F_32 ( V_51 , V_3 ,
L_11 ) ;
goto V_42;
}
V_5 = F_1 ( V_3 , V_33 -> V_54 ) ;
if ( ! V_5 )
return;
V_70 = F_62 ( V_5 , V_60 ,
V_93 -> V_103 ) ;
if ( ! V_70 )
goto V_42;
V_113 = F_63 ( & V_111 -> V_13 . V_55 ) ;
V_83 = F_64 ( T_3 , V_113 , V_112 ) ;
V_33 -> V_55 = F_25 ( V_83 ) ;
F_56 ( V_3 , V_93 , V_33 , V_5 ,
V_70 , V_60 ,
V_65 ) ;
F_28 () ;
F_29 (hard_iface, &batadv_hardif_list, list) {
if ( V_21 -> V_23 != V_24 )
continue;
if ( V_21 -> V_22 != V_3 -> V_22 )
continue;
if ( ! F_30 ( & V_21 -> V_7 ) )
continue;
V_39 = F_31 ( V_21 ,
V_33 -> V_54 ,
V_111 -> V_54 ) ;
if ( V_39 ) {
char * type ;
switch ( V_39 ) {
case V_48 :
type = L_1 ;
break;
case V_49 :
type = L_2 ;
break;
case V_50 :
type = L_3 ;
break;
default:
type = L_4 ;
}
F_32 ( V_51 , V_3 , L_15 ,
V_33 -> V_54 , V_21 -> V_52 -> V_53 ,
type ) ;
F_33 ( V_21 ) ;
continue;
}
F_56 ( V_3 , V_93 , V_33 ,
V_5 , V_70 ,
V_60 , V_21 ) ;
F_33 ( V_21 ) ;
}
F_36 () ;
V_42:
if ( V_5 )
F_6 ( V_5 ) ;
if ( V_70 )
F_48 ( V_70 ) ;
if ( V_111 )
F_65 ( V_111 ) ;
}
int F_66 ( struct V_18 * V_19 ,
struct V_20 * V_60 )
{
struct V_2 * V_3 = F_14 ( V_60 -> V_22 ) ;
struct V_32 * V_33 ;
struct V_93 * V_93 = F_60 ( V_19 ) ;
int V_109 ;
T_1 * V_115 ;
int V_39 = V_116 ;
if ( strcmp ( V_3 -> V_117 -> V_53 , L_16 ) != 0 )
goto V_118;
if ( ! F_67 ( V_19 , V_60 , V_43 ) )
goto V_118;
if ( F_68 ( V_3 , V_93 -> V_103 ) )
goto V_118;
V_33 = (struct V_32 * ) V_19 -> V_45 ;
if ( F_68 ( V_3 , V_33 -> V_54 ) )
goto V_118;
F_15 ( V_3 , V_119 ) ;
F_16 ( V_3 , V_120 ,
V_19 -> V_27 + V_28 ) ;
V_109 = 0 ;
V_33 = (struct V_32 * ) V_19 -> V_45 ;
while ( F_58 ( V_109 , F_69 ( V_19 ) ,
V_33 -> V_38 ) ) {
F_59 ( V_19 , V_109 , V_60 ) ;
V_109 += V_43 ;
V_109 += F_46 ( V_33 -> V_38 ) ;
V_115 = V_19 -> V_45 + V_109 ;
V_33 = (struct V_32 * ) V_115 ;
}
V_39 = V_121 ;
V_118:
if ( V_39 == V_121 )
F_37 ( V_19 ) ;
else
F_70 ( V_19 ) ;
return V_39 ;
}
int F_71 ( struct V_2 * V_3 )
{
struct V_32 * V_33 ;
unsigned char * V_35 ;
T_3 V_122 ;
V_3 -> V_13 . V_37 = V_43 ;
V_35 = F_72 ( V_3 -> V_13 . V_37 , V_58 ) ;
if ( ! V_35 )
return - V_123 ;
V_3 -> V_13 . V_35 = V_35 ;
V_33 = (struct V_32 * ) V_35 ;
V_33 -> V_124 = V_125 ;
V_33 -> V_114 = V_126 ;
V_33 -> V_56 = V_127 ;
V_33 -> V_66 = V_128 ;
V_33 -> V_55 = F_25 ( V_129 ) ;
F_73 ( & V_122 , sizeof( V_122 ) ) ;
F_74 ( & V_3 -> V_13 . V_47 , V_122 ) ;
F_75 ( & V_3 -> V_13 . V_14 , F_18 ) ;
return 0 ;
}
void F_76 ( struct V_2 * V_3 )
{
F_77 ( & V_3 -> V_13 . V_14 ) ;
F_78 ( V_3 -> V_13 . V_35 ) ;
V_3 -> V_13 . V_35 = NULL ;
V_3 -> V_13 . V_37 = 0 ;
}
