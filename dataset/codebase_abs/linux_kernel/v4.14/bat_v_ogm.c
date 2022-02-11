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
unsigned char * V_35 ;
int V_36 ;
T_2 V_37 = 0 ;
int V_38 ;
V_13 = F_19 ( V_30 , struct V_31 , V_14 . V_30 ) ;
V_3 = F_19 ( V_13 , struct V_2 , V_13 ) ;
if ( F_9 ( & V_3 -> V_39 ) == V_40 )
goto V_41;
V_35 = V_3 -> V_13 . V_35 ;
V_36 = V_3 -> V_13 . V_36 ;
F_20 ( V_3 ) ;
V_37 = F_21 ( V_3 , & V_35 ,
& V_36 ,
V_42 ) ;
V_3 -> V_13 . V_35 = V_35 ;
V_3 -> V_13 . V_36 = V_36 ;
V_19 = F_22 ( NULL , V_28 + V_36 ) ;
if ( ! V_19 )
goto V_43;
F_23 ( V_19 , V_28 ) ;
F_24 ( V_19 , V_35 , V_36 ) ;
V_33 = (struct V_32 * ) V_19 -> V_44 ;
V_33 -> V_45 = F_25 ( F_9 ( & V_3 -> V_13 . V_46 ) ) ;
F_26 ( & V_3 -> V_13 . V_46 ) ;
V_33 -> V_37 = F_27 ( V_37 ) ;
F_28 () ;
F_29 (hard_iface, &batadv_hardif_list, list) {
if ( V_21 -> V_22 != V_3 -> V_22 )
continue;
if ( ! F_30 ( & V_21 -> V_7 ) )
continue;
V_38 = F_31 ( V_21 , NULL , NULL ) ;
if ( V_38 ) {
char * type ;
switch ( V_38 ) {
case V_47 :
type = L_1 ;
break;
case V_48 :
type = L_2 ;
break;
case V_49 :
type = L_3 ;
break;
default:
type = L_4 ;
}
F_32 ( V_50 , V_3 , L_5 ,
V_21 -> V_51 -> V_52 , type ) ;
F_33 ( V_21 ) ;
continue;
}
F_32 ( V_50 , V_3 ,
L_6 ,
V_33 -> V_53 , F_34 ( V_33 -> V_45 ) ,
F_34 ( V_33 -> V_54 ) , V_33 -> V_55 ,
V_21 -> V_51 -> V_52 ,
V_21 -> V_51 -> V_56 ) ;
V_34 = F_35 ( V_19 , V_57 ) ;
if ( ! V_34 ) {
F_33 ( V_21 ) ;
break;
}
F_13 ( V_34 , V_21 ) ;
F_33 ( V_21 ) ;
}
F_36 () ;
F_37 ( V_19 ) ;
V_43:
F_7 ( V_3 ) ;
V_41:
return;
}
int F_38 ( struct V_20 * V_21 )
{
struct V_2 * V_3 = F_14 ( V_21 -> V_22 ) ;
F_7 ( V_3 ) ;
return 0 ;
}
void F_39 ( struct V_20 * V_58 )
{
struct V_2 * V_3 = F_14 ( V_58 -> V_22 ) ;
struct V_32 * V_33 ;
if ( ! V_3 -> V_13 . V_35 )
return;
V_33 = (struct V_32 * ) V_3 -> V_13 . V_35 ;
F_40 ( V_33 -> V_53 , V_58 -> V_51 -> V_56 ) ;
}
static T_3 F_41 ( struct V_2 * V_3 ,
struct V_20 * V_59 ,
struct V_20 * V_60 ,
T_3 V_54 )
{
int V_61 = F_9 ( & V_3 -> V_61 ) ;
int V_62 = V_63 ;
if ( V_60 == V_64 )
return V_54 ;
if ( ( V_54 > 10 ) &&
( V_59 == V_60 ) &&
! ( V_59 -> V_13 . V_65 & V_66 ) )
return V_54 / 2 ;
return V_54 * ( V_62 - V_61 ) / V_62 ;
}
static void F_42 ( struct V_2 * V_3 ,
const struct V_32 * V_67 ,
struct V_1 * V_5 ,
struct V_68 * V_69 ,
struct V_20 * V_59 ,
struct V_20 * V_60 )
{
struct V_70 * V_71 = NULL ;
struct V_72 * V_73 = NULL ;
struct V_68 * V_74 = NULL ;
struct V_32 * V_75 ;
unsigned char * V_76 ;
struct V_18 * V_19 ;
T_4 V_77 ;
T_2 V_37 ;
if ( V_60 == V_64 )
goto V_41;
V_73 = F_43 ( V_5 , V_60 ) ;
if ( ! V_73 )
goto V_41;
V_74 = F_44 ( V_5 , V_60 ) ;
if ( V_69 != V_74 )
goto V_41;
if ( V_73 -> V_78 == F_34 ( V_67 -> V_45 ) )
goto V_41;
V_73 -> V_78 = F_34 ( V_67 -> V_45 ) ;
if ( V_67 -> V_55 <= 1 ) {
F_32 ( V_50 , V_3 , L_7 ) ;
goto V_41;
}
V_71 = F_45 ( V_69 , V_60 ) ;
if ( ! V_71 )
goto V_41;
V_37 = F_46 ( V_67 -> V_37 ) ;
V_77 = V_42 + V_37 ;
V_19 = F_22 ( V_60 -> V_51 ,
V_28 + V_77 ) ;
if ( ! V_19 )
goto V_41;
F_23 ( V_19 , V_28 ) ;
V_76 = F_24 ( V_19 , V_67 , V_77 ) ;
V_75 = (struct V_32 * ) V_76 ;
V_75 -> V_54 = F_25 ( V_71 -> V_13 . V_54 ) ;
V_75 -> V_55 -- ;
F_32 ( V_50 , V_3 ,
L_8 ,
V_60 -> V_51 -> V_52 , F_34 ( V_75 -> V_54 ) ,
V_75 -> V_55 , V_59 -> V_51 -> V_52 ) ;
F_13 ( V_19 , V_60 ) ;
V_41:
if ( V_73 )
F_47 ( V_73 ) ;
if ( V_74 )
F_48 ( V_74 ) ;
if ( V_71 )
F_49 ( V_71 ) ;
}
static int F_50 ( struct V_2 * V_3 ,
const struct V_32 * V_79 ,
struct V_1 * V_5 ,
struct V_68 * V_69 ,
struct V_20 * V_59 ,
struct V_20 * V_60 )
{
struct V_72 * V_73 ;
struct V_70 * V_71 = NULL ;
bool V_80 = false ;
int V_38 = - V_81 ;
T_3 V_82 ;
T_5 V_83 ;
V_73 = F_43 ( V_5 , V_60 ) ;
if ( ! V_73 )
goto V_41;
V_83 = F_34 ( V_79 -> V_45 ) - V_73 -> V_84 ;
if ( ! F_51 ( & V_5 -> V_85 ) &&
F_52 ( V_3 , V_83 ,
V_86 ,
& V_73 -> V_87 ,
& V_80 ) ) {
F_32 ( V_50 , V_3 ,
L_9 ,
V_79 -> V_53 ) ;
F_32 ( V_50 , V_3 ,
L_10 ,
V_73 -> V_87 , V_88 ) ;
goto V_41;
}
if ( ( V_83 < 0 ) && ! V_80 )
goto V_41;
V_69 -> V_89 = V_88 ;
V_5 -> V_89 = V_88 ;
V_73 -> V_84 = F_34 ( V_79 -> V_45 ) ;
V_73 -> V_90 = V_79 -> V_55 ;
V_71 = F_53 ( V_69 , V_60 ) ;
if ( ! V_71 )
goto V_41;
V_82 = F_41 ( V_3 , V_59 ,
V_60 ,
F_34 ( V_79 -> V_54 ) ) ;
V_71 -> V_13 . V_54 = V_82 ;
V_71 -> V_13 . V_91 = F_34 ( V_79 -> V_45 ) ;
V_71 -> V_90 = V_79 -> V_55 ;
if ( V_83 > 0 || V_80 )
V_38 = 1 ;
else
V_38 = 0 ;
V_41:
if ( V_73 )
F_47 ( V_73 ) ;
if ( V_71 )
F_49 ( V_71 ) ;
return V_38 ;
}
static bool F_54 ( struct V_2 * V_3 ,
const struct V_92 * V_92 ,
const struct V_32 * V_79 ,
struct V_1 * V_5 ,
struct V_68 * V_69 ,
struct V_20 * V_59 ,
struct V_20 * V_60 )
{
struct V_68 * V_74 = NULL ;
struct V_1 * V_93 ;
struct V_68 * V_94 = NULL ;
struct V_70 * V_95 = NULL , * V_71 = NULL ;
T_3 V_96 , V_97 ;
T_3 V_98 ;
T_3 V_99 ;
T_5 V_100 ;
bool V_101 = false ;
V_93 = F_1 ( V_3 , V_92 -> V_102 ) ;
if ( ! V_93 )
goto V_41;
V_94 = F_44 ( V_93 ,
V_60 ) ;
V_74 = F_44 ( V_5 , V_60 ) ;
if ( V_74 && V_74 -> V_5 != V_5 && ! V_94 ) {
F_32 ( V_50 , V_3 ,
L_11 ) ;
goto V_41;
}
V_101 = true ;
F_32 ( V_50 , V_3 ,
L_12 ) ;
if ( V_74 == V_69 )
goto V_41;
if ( V_74 ) {
V_95 = F_45 ( V_74 , V_60 ) ;
V_71 = F_45 ( V_69 , V_60 ) ;
if ( ! V_95 || ! V_71 )
goto V_41;
V_99 = V_71 -> V_13 . V_91 ;
V_98 = V_95 -> V_13 . V_91 ;
V_100 = V_99 - V_98 ;
V_96 = V_95 -> V_13 . V_54 ;
V_97 = V_71 -> V_13 . V_54 ;
if ( ( V_100 < V_103 ) &&
( V_96 >= V_97 ) )
goto V_41;
}
F_55 ( V_3 , V_5 , V_60 , V_69 ) ;
V_41:
if ( V_74 )
F_48 ( V_74 ) ;
if ( V_94 )
F_48 ( V_94 ) ;
if ( V_93 )
F_6 ( V_93 ) ;
if ( V_95 )
F_49 ( V_95 ) ;
if ( V_71 )
F_49 ( V_71 ) ;
return V_101 ;
}
static void
F_56 ( struct V_2 * V_3 ,
const struct V_92 * V_92 ,
const struct V_32 * V_79 ,
struct V_1 * V_5 ,
struct V_68 * V_69 ,
struct V_20 * V_59 ,
struct V_20 * V_60 )
{
int V_104 ;
bool V_101 ;
V_104 = F_50 ( V_3 , V_79 , V_5 ,
V_69 , V_59 ,
V_60 ) ;
if ( V_104 < 0 )
return;
if ( ( V_104 > 0 ) && ( V_60 == V_64 ) )
F_57 ( V_3 , true , V_5 ,
NULL , NULL ,
( unsigned char * ) ( V_79 + 1 ) ,
F_46 ( V_79 -> V_37 ) ) ;
V_101 = F_54 ( V_3 , V_92 , V_79 , V_5 ,
V_69 , V_59 ,
V_60 ) ;
if ( V_101 )
F_42 ( V_3 , V_79 , V_5 , V_69 ,
V_59 , V_60 ) ;
}
static bool F_58 ( int V_105 , int V_77 ,
T_6 V_37 )
{
int V_106 = 0 ;
V_106 += V_105 + V_42 ;
V_106 += F_46 ( V_37 ) ;
return ( V_106 <= V_77 ) &&
( V_106 <= V_107 ) ;
}
static void F_59 ( const struct V_18 * V_19 , int V_108 ,
struct V_20 * V_59 )
{
struct V_2 * V_3 = F_14 ( V_59 -> V_22 ) ;
struct V_92 * V_92 ;
struct V_1 * V_5 = NULL ;
struct V_109 * V_110 = NULL ;
struct V_68 * V_69 = NULL ;
struct V_20 * V_21 ;
struct V_32 * V_33 ;
T_3 V_111 , V_112 , V_82 ;
int V_38 ;
V_92 = F_60 ( V_19 ) ;
V_33 = (struct V_32 * ) ( V_19 -> V_44 + V_108 ) ;
V_111 = F_34 ( V_33 -> V_54 ) ;
F_32 ( V_50 , V_3 ,
L_13 ,
V_92 -> V_102 , V_59 -> V_51 -> V_52 ,
V_59 -> V_51 -> V_56 , V_33 -> V_53 ,
F_34 ( V_33 -> V_45 ) , V_111 , V_33 -> V_55 ,
V_33 -> V_113 , F_46 ( V_33 -> V_37 ) ) ;
if ( V_111 == 0 ) {
F_32 ( V_50 , V_3 ,
L_14 ) ;
return;
}
V_110 = F_61 ( V_59 , V_92 -> V_102 ) ;
if ( ! V_110 ) {
F_32 ( V_50 , V_3 ,
L_11 ) ;
goto V_41;
}
V_5 = F_1 ( V_3 , V_33 -> V_53 ) ;
if ( ! V_5 )
return;
V_69 = F_62 ( V_5 , V_59 ,
V_92 -> V_102 ) ;
if ( ! V_69 )
goto V_41;
V_112 = F_63 ( & V_110 -> V_13 . V_54 ) ;
V_82 = F_64 ( T_3 , V_112 , V_111 ) ;
V_33 -> V_54 = F_25 ( V_82 ) ;
F_56 ( V_3 , V_92 , V_33 , V_5 ,
V_69 , V_59 ,
V_64 ) ;
F_28 () ;
F_29 (hard_iface, &batadv_hardif_list, list) {
if ( V_21 -> V_23 != V_24 )
continue;
if ( V_21 -> V_22 != V_3 -> V_22 )
continue;
if ( ! F_30 ( & V_21 -> V_7 ) )
continue;
V_38 = F_31 ( V_21 ,
V_33 -> V_53 ,
V_110 -> V_53 ) ;
if ( V_38 ) {
char * type ;
switch ( V_38 ) {
case V_47 :
type = L_1 ;
break;
case V_48 :
type = L_2 ;
break;
case V_49 :
type = L_3 ;
break;
default:
type = L_4 ;
}
F_32 ( V_50 , V_3 , L_15 ,
V_33 -> V_53 , V_21 -> V_51 -> V_52 ,
type ) ;
F_33 ( V_21 ) ;
continue;
}
F_56 ( V_3 , V_92 , V_33 ,
V_5 , V_69 ,
V_59 , V_21 ) ;
F_33 ( V_21 ) ;
}
F_36 () ;
V_41:
if ( V_5 )
F_6 ( V_5 ) ;
if ( V_69 )
F_48 ( V_69 ) ;
if ( V_110 )
F_65 ( V_110 ) ;
}
int F_66 ( struct V_18 * V_19 ,
struct V_20 * V_59 )
{
struct V_2 * V_3 = F_14 ( V_59 -> V_22 ) ;
struct V_32 * V_33 ;
struct V_92 * V_92 = F_60 ( V_19 ) ;
int V_108 ;
T_1 * V_114 ;
int V_38 = V_115 ;
if ( strcmp ( V_3 -> V_116 -> V_52 , L_16 ) != 0 )
goto V_117;
if ( ! F_67 ( V_19 , V_59 , V_42 ) )
goto V_117;
if ( F_68 ( V_3 , V_92 -> V_102 ) )
goto V_117;
V_33 = (struct V_32 * ) V_19 -> V_44 ;
if ( F_68 ( V_3 , V_33 -> V_53 ) )
goto V_117;
F_15 ( V_3 , V_118 ) ;
F_16 ( V_3 , V_119 ,
V_19 -> V_27 + V_28 ) ;
V_108 = 0 ;
V_33 = (struct V_32 * ) V_19 -> V_44 ;
while ( F_58 ( V_108 , F_69 ( V_19 ) ,
V_33 -> V_37 ) ) {
F_59 ( V_19 , V_108 , V_59 ) ;
V_108 += V_42 ;
V_108 += F_46 ( V_33 -> V_37 ) ;
V_114 = V_19 -> V_44 + V_108 ;
V_33 = (struct V_32 * ) V_114 ;
}
V_38 = V_120 ;
V_117:
if ( V_38 == V_120 )
F_37 ( V_19 ) ;
else
F_70 ( V_19 ) ;
return V_38 ;
}
int F_71 ( struct V_2 * V_3 )
{
struct V_32 * V_33 ;
unsigned char * V_35 ;
T_3 V_121 ;
V_3 -> V_13 . V_36 = V_42 ;
V_35 = F_72 ( V_3 -> V_13 . V_36 , V_57 ) ;
if ( ! V_35 )
return - V_122 ;
V_3 -> V_13 . V_35 = V_35 ;
V_33 = (struct V_32 * ) V_35 ;
V_33 -> V_123 = V_124 ;
V_33 -> V_113 = V_125 ;
V_33 -> V_55 = V_126 ;
V_33 -> V_65 = V_127 ;
V_33 -> V_54 = F_25 ( V_128 ) ;
F_73 ( & V_121 , sizeof( V_121 ) ) ;
F_74 ( & V_3 -> V_13 . V_46 , V_121 ) ;
F_75 ( & V_3 -> V_13 . V_14 , F_18 ) ;
return 0 ;
}
void F_76 ( struct V_2 * V_3 )
{
F_77 ( & V_3 -> V_13 . V_14 ) ;
F_78 ( V_3 -> V_13 . V_35 ) ;
V_3 -> V_13 . V_35 = NULL ;
V_3 -> V_13 . V_36 = 0 ;
}
