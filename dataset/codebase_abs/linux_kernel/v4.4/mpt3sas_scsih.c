static void F_1 ( struct V_1 * V_2 )
{
F_2 ( F_3 ( V_2 , struct V_3 , V_4 ) ) ;
}
static void F_4 ( struct V_3 * V_5 )
{
F_5 ( & V_5 -> V_4 ) ;
}
static void F_6 ( struct V_3 * V_5 )
{
F_7 ( & V_5 -> V_4 , F_1 ) ;
}
static struct V_3 * F_8 ( int V_6 )
{
struct V_3 * V_7 ;
V_7 = F_9 ( sizeof( * V_7 ) + V_6 , V_8 ) ;
if ( ! V_7 )
return NULL ;
F_10 ( & V_7 -> V_4 ) ;
return V_7 ;
}
static int
F_11 ( const char * V_9 , struct V_10 * V_11 )
{
int V_12 = F_12 ( V_9 , V_11 ) ;
struct V_13 * V_14 ;
if ( V_12 )
return V_12 ;
F_13 ( L_1 , V_15 ) ;
F_14 ( & V_16 ) ;
F_15 (ioc, &mpt3sas_ioc_list, list)
V_14 -> V_15 = V_15 ;
F_16 ( & V_16 ) ;
return 0 ;
}
static inline int
F_17 ( T_1 V_17 ,
T_2 * V_18 )
{
return ( V_17 == F_18 ( V_18 -> V_19 ) ) ? 1 : 0 ;
}
static inline int
F_19 ( T_1 V_20 ,
T_3 * V_18 )
{
return ( V_20 == F_18 ( V_18 -> V_21 ) ) ? 1 : 0 ;
}
static inline int
F_20 ( T_1 V_22 , T_4 V_23 ,
T_5 * V_18 )
{
return ( V_22 == F_18 ( V_18 ->
V_24 ) && V_23 == F_21 ( V_18 ->
V_25 ) ) ? 1 : 0 ;
}
static int
F_22 ( T_1 V_17 , T_1 V_20 ,
T_1 V_22 , T_4 V_26 , T_6 V_27 ,
T_7 * V_18 )
{
int V_28 = 0 ;
switch ( V_27 ) {
case V_29 :
if ( ! V_17 )
break;
V_28 = F_17 (
V_17 , & V_18 -> V_30 ) ;
break;
case V_31 :
if ( ! V_22 )
break;
V_28 = F_20 (
V_22 ,
V_26 , & V_18 -> V_32 ) ;
break;
case V_33 :
if ( ! V_20 )
break;
V_28 = F_19 (
V_20 , & V_18 -> V_21 ) ;
break;
case V_34 :
break;
}
return V_28 ;
}
static int
F_23 ( struct V_13 * V_14 , T_4 V_35 ,
T_1 * V_17 )
{
T_8 V_36 ;
T_9 V_37 ;
T_10 V_38 ;
* V_17 = 0 ;
if ( V_35 <= V_14 -> V_39 . V_40 ) {
* V_17 = V_14 -> V_39 . V_17 ;
return 0 ;
}
if ( ( F_24 ( V_14 , & V_37 , & V_36 ,
V_41 , V_35 ) ) ) {
F_25 ( V_42 L_2 , V_14 -> V_43 ,
__FILE__ , __LINE__ , V_44 ) ;
return - V_45 ;
}
V_38 = F_21 ( V_37 . V_46 ) & V_47 ;
if ( V_38 == V_48 ) {
* V_17 = F_18 ( V_36 . V_19 ) ;
return 0 ;
}
if ( V_38 == V_49 )
return - V_45 ;
F_25 ( V_42
L_3 ,
V_14 -> V_43 , V_35 , V_38 ,
__FILE__ , __LINE__ , V_44 ) ;
return - V_50 ;
}
static void
F_26 ( struct V_13 * V_14 ,
void * V_51 , T_6 V_52 )
{
struct V_53 * V_54 ;
struct V_55 * V_56 ;
T_1 V_17 ;
T_1 V_20 ;
T_1 V_22 ;
T_4 V_26 ;
if ( ! V_14 -> V_57 )
return;
if ( ! V_14 -> V_58 . V_59 )
return;
if ( ! V_52 ) {
V_54 = V_51 ;
V_17 = V_54 -> V_17 ;
V_20 = V_54 -> V_20 ;
V_22 = V_54 -> V_22 ;
V_26 = V_54 -> V_26 ;
} else {
V_56 = V_51 ;
V_17 = V_56 -> V_60 ;
V_20 = 0 ;
V_22 = 0 ;
V_26 = 0 ;
}
if ( ! V_14 -> V_61 . V_51 ) {
if ( F_22 ( V_17 , V_20 ,
V_22 , V_26 ,
( V_14 -> V_62 . V_63 &
V_64 ) ,
& V_14 -> V_62 . V_65 ) ) {
F_27 ( V_14 , F_13 ( V_42
L_4 ,
V_14 -> V_43 , V_44 ,
( unsigned long long ) V_17 ) ) ;
V_14 -> V_61 . V_51 = V_51 ;
V_14 -> V_61 . V_52 = V_52 ;
}
}
if ( ! V_14 -> V_66 . V_51 ) {
if ( F_22 ( V_17 , V_20 ,
V_22 , V_26 ,
( V_14 -> V_62 . V_67 &
V_64 ) ,
& V_14 -> V_62 . V_68 ) ) {
F_27 ( V_14 , F_13 ( V_42
L_5 ,
V_14 -> V_43 , V_44 ,
( unsigned long long ) V_17 ) ) ;
V_14 -> V_66 . V_51 = V_51 ;
V_14 -> V_66 . V_52 = V_52 ;
}
}
if ( ! V_14 -> V_69 . V_51 ) {
if ( F_22 ( V_17 , V_20 ,
V_22 , V_26 ,
( V_14 -> V_62 . V_70 &
V_64 ) ,
& V_14 -> V_62 . V_71 ) ) {
F_27 ( V_14 , F_13 ( V_42
L_6 ,
V_14 -> V_43 , V_44 ,
( unsigned long long ) V_17 ) ) ;
V_14 -> V_69 . V_51 = V_51 ;
V_14 -> V_69 . V_52 = V_52 ;
}
}
}
static struct V_53 *
F_28 ( struct V_13 * V_14 ,
struct V_72 * V_73 )
{
struct V_53 * V_12 ;
F_29 ( & V_14 -> V_74 ) ;
V_12 = V_73 -> V_75 ;
if ( V_12 )
F_30 ( V_12 ) ;
return V_12 ;
}
static struct V_53 *
F_31 ( struct V_13 * V_14 ,
struct V_72 * V_73 )
{
struct V_53 * V_12 ;
unsigned long V_76 ;
F_32 ( & V_14 -> V_74 , V_76 ) ;
V_12 = F_28 ( V_14 , V_73 ) ;
F_33 ( & V_14 -> V_74 , V_76 ) ;
return V_12 ;
}
struct V_53 *
F_34 ( struct V_13 * V_14 ,
T_1 V_17 )
{
struct V_53 * V_54 ;
F_29 ( & V_14 -> V_74 ) ;
F_15 (sas_device, &ioc->sas_device_list, list)
if ( V_54 -> V_17 == V_17 )
goto V_77;
F_15 (sas_device, &ioc->sas_device_init_list, list)
if ( V_54 -> V_17 == V_17 )
goto V_77;
return NULL ;
V_77:
F_30 ( V_54 ) ;
return V_54 ;
}
struct V_53 *
F_35 ( struct V_13 * V_14 ,
T_1 V_17 )
{
struct V_53 * V_54 ;
unsigned long V_76 ;
F_32 ( & V_14 -> V_74 , V_76 ) ;
V_54 = F_34 ( V_14 ,
V_17 ) ;
F_33 ( & V_14 -> V_74 , V_76 ) ;
return V_54 ;
}
static struct V_53 *
F_36 ( struct V_13 * V_14 , T_4 V_35 )
{
struct V_53 * V_54 ;
F_29 ( & V_14 -> V_74 ) ;
F_15 (sas_device, &ioc->sas_device_list, list)
if ( V_54 -> V_35 == V_35 )
goto V_77;
F_15 (sas_device, &ioc->sas_device_init_list, list)
if ( V_54 -> V_35 == V_35 )
goto V_77;
return NULL ;
V_77:
F_30 ( V_54 ) ;
return V_54 ;
}
static struct V_53 *
F_37 ( struct V_13 * V_14 , T_4 V_35 )
{
struct V_53 * V_54 ;
unsigned long V_76 ;
F_32 ( & V_14 -> V_74 , V_76 ) ;
V_54 = F_36 ( V_14 , V_35 ) ;
F_33 ( & V_14 -> V_74 , V_76 ) ;
return V_54 ;
}
static void
F_38 ( struct V_13 * V_14 ,
struct V_53 * V_54 )
{
unsigned long V_76 ;
if ( ! V_54 )
return;
F_13 ( V_42
L_7 ,
V_14 -> V_43 , V_54 -> V_35 ,
( unsigned long long ) V_54 -> V_17 ) ;
if ( V_54 -> V_78 != 0 )
F_13 ( V_42
L_8 ,
V_14 -> V_43 , ( unsigned long long )
V_54 -> V_22 , V_54 -> V_26 ) ;
if ( V_54 -> V_79 [ 0 ] != '\0' )
F_13 ( V_42
L_9 ,
V_14 -> V_43 , V_54 -> V_80 ,
V_54 -> V_79 ) ;
F_32 ( & V_14 -> V_74 , V_76 ) ;
if ( ! F_39 ( & V_54 -> V_81 ) ) {
F_40 ( & V_54 -> V_81 ) ;
F_41 ( V_54 ) ;
}
F_33 ( & V_14 -> V_74 , V_76 ) ;
}
static void
F_42 ( struct V_13 * V_14 , T_4 V_35 )
{
struct V_53 * V_54 ;
unsigned long V_76 ;
if ( V_14 -> V_82 )
return;
F_32 ( & V_14 -> V_74 , V_76 ) ;
V_54 = F_36 ( V_14 , V_35 ) ;
if ( V_54 ) {
F_40 ( & V_54 -> V_81 ) ;
F_41 ( V_54 ) ;
}
F_33 ( & V_14 -> V_74 , V_76 ) ;
if ( V_54 ) {
F_43 ( V_14 , V_54 ) ;
F_41 ( V_54 ) ;
}
}
void
F_44 ( struct V_13 * V_14 ,
T_1 V_17 )
{
struct V_53 * V_54 ;
unsigned long V_76 ;
if ( V_14 -> V_82 )
return;
F_32 ( & V_14 -> V_74 , V_76 ) ;
V_54 = F_34 ( V_14 , V_17 ) ;
if ( V_54 ) {
F_40 ( & V_54 -> V_81 ) ;
F_41 ( V_54 ) ;
}
F_33 ( & V_14 -> V_74 , V_76 ) ;
if ( V_54 ) {
F_43 ( V_14 , V_54 ) ;
F_41 ( V_54 ) ;
}
}
static void
F_45 ( struct V_13 * V_14 ,
struct V_53 * V_54 )
{
unsigned long V_76 ;
F_46 ( V_14 , F_13 ( V_42
L_10 ,
V_14 -> V_43 , V_44 , V_54 -> V_35 ,
( unsigned long long ) V_54 -> V_17 ) ) ;
if ( V_54 -> V_78 != 0 )
F_46 ( V_14 , F_13 ( V_42
L_11 ,
V_14 -> V_43 , V_44 , ( unsigned long long )
V_54 -> V_22 , V_54 -> V_26 ) ) ;
if ( V_54 -> V_79 [ 0 ] != '\0' )
F_46 ( V_14 , F_13 ( V_42
L_12 ,
V_14 -> V_43 , V_44 ,
V_54 -> V_80 , V_54 -> V_79 ) ) ;
F_32 ( & V_14 -> V_74 , V_76 ) ;
F_30 ( V_54 ) ;
F_47 ( & V_54 -> V_81 , & V_14 -> V_83 ) ;
F_33 ( & V_14 -> V_74 , V_76 ) ;
if ( ! F_48 ( V_14 , V_54 -> V_35 ,
V_54 -> V_84 ) ) {
F_38 ( V_14 , V_54 ) ;
} else if ( ! V_54 -> V_85 ) {
if ( ! V_14 -> V_57 ) {
F_49 ( V_14 ,
V_54 -> V_17 ,
V_54 -> V_84 ) ;
F_38 ( V_14 , V_54 ) ;
}
}
}
static void
F_50 ( struct V_13 * V_14 ,
struct V_53 * V_54 )
{
unsigned long V_76 ;
F_46 ( V_14 , F_13 ( V_42
L_10 , V_14 -> V_43 ,
V_44 , V_54 -> V_35 ,
( unsigned long long ) V_54 -> V_17 ) ) ;
if ( V_54 -> V_78 != 0 )
F_46 ( V_14 , F_13 ( V_42
L_11 ,
V_14 -> V_43 , V_44 , ( unsigned long long )
V_54 -> V_22 , V_54 -> V_26 ) ) ;
if ( V_54 -> V_79 [ 0 ] != '\0' )
F_46 ( V_14 , F_13 ( V_42
L_12 ,
V_14 -> V_43 , V_44 , V_54 -> V_80 ,
V_54 -> V_79 ) ) ;
F_32 ( & V_14 -> V_74 , V_76 ) ;
F_30 ( V_54 ) ;
F_47 ( & V_54 -> V_81 , & V_14 -> V_86 ) ;
F_26 ( V_14 , V_54 , 0 ) ;
F_33 ( & V_14 -> V_74 , V_76 ) ;
}
static struct V_55 *
F_51 ( struct V_13 * V_14 , int V_87 , int V_88 )
{
struct V_55 * V_56 , * V_2 ;
V_2 = NULL ;
F_15 (raid_device, &ioc->raid_device_list, list) {
if ( V_56 -> V_87 == V_87 && V_56 -> V_88 == V_88 ) {
V_2 = V_56 ;
goto V_89;
}
}
V_89:
return V_2 ;
}
struct V_55 *
F_52 ( struct V_13 * V_14 , T_4 V_35 )
{
struct V_55 * V_56 , * V_2 ;
V_2 = NULL ;
F_15 (raid_device, &ioc->raid_device_list, list) {
if ( V_56 -> V_35 != V_35 )
continue;
V_2 = V_56 ;
goto V_89;
}
V_89:
return V_2 ;
}
static struct V_55 *
F_53 ( struct V_13 * V_14 , T_1 V_60 )
{
struct V_55 * V_56 , * V_2 ;
V_2 = NULL ;
F_15 (raid_device, &ioc->raid_device_list, list) {
if ( V_56 -> V_60 != V_60 )
continue;
V_2 = V_56 ;
goto V_89;
}
V_89:
return V_2 ;
}
static void
F_54 ( struct V_13 * V_14 ,
struct V_55 * V_56 )
{
unsigned long V_76 ;
F_46 ( V_14 , F_13 ( V_42
L_13 , V_14 -> V_43 , V_44 ,
V_56 -> V_35 , ( unsigned long long ) V_56 -> V_60 ) ) ;
F_32 ( & V_14 -> V_90 , V_76 ) ;
F_47 ( & V_56 -> V_81 , & V_14 -> V_91 ) ;
F_33 ( & V_14 -> V_90 , V_76 ) ;
}
static void
F_55 ( struct V_13 * V_14 ,
struct V_55 * V_56 )
{
unsigned long V_76 ;
F_32 ( & V_14 -> V_90 , V_76 ) ;
F_56 ( & V_56 -> V_81 ) ;
F_2 ( V_56 ) ;
F_33 ( & V_14 -> V_90 , V_76 ) ;
}
struct V_92 *
F_57 ( struct V_13 * V_14 , T_4 V_35 )
{
struct V_92 * V_93 , * V_2 ;
V_2 = NULL ;
F_15 (sas_expander, &ioc->sas_expander_list, list) {
if ( V_93 -> V_35 != V_35 )
continue;
V_2 = V_93 ;
goto V_89;
}
V_89:
return V_2 ;
}
struct V_92 *
F_58 ( struct V_13 * V_14 ,
T_1 V_17 )
{
struct V_92 * V_93 , * V_2 ;
V_2 = NULL ;
F_15 (sas_expander, &ioc->sas_expander_list, list) {
if ( V_93 -> V_17 != V_17 )
continue;
V_2 = V_93 ;
goto V_89;
}
V_89:
return V_2 ;
}
static void
F_59 ( struct V_13 * V_14 ,
struct V_92 * V_93 )
{
unsigned long V_76 ;
F_32 ( & V_14 -> V_94 , V_76 ) ;
F_47 ( & V_93 -> V_81 , & V_14 -> V_95 ) ;
F_33 ( & V_14 -> V_94 , V_76 ) ;
}
static int
F_60 ( T_10 V_96 )
{
if ( V_96 & V_97 &&
( ( V_96 & V_98 ) |
( V_96 & V_99 ) |
( V_96 & V_100 ) ) )
return 1 ;
else
return 0 ;
}
static struct V_101 *
F_61 ( struct V_13 * V_14 , T_4 V_102 )
{
return V_14 -> V_103 [ V_102 - 1 ] . V_104 ;
}
static inline struct V_101 *
F_62 ( struct V_13 * V_14 , T_4 V_102 )
{
unsigned long V_76 ;
struct V_101 * V_104 ;
F_32 ( & V_14 -> V_105 , V_76 ) ;
V_104 = V_14 -> V_103 [ V_102 - 1 ] . V_104 ;
V_14 -> V_103 [ V_102 - 1 ] . V_104 = NULL ;
F_33 ( & V_14 -> V_105 , V_76 ) ;
return V_104 ;
}
static T_4
F_63 ( struct V_13 * V_14 , struct V_101
* V_104 )
{
T_4 V_102 ;
unsigned long V_76 ;
int V_106 ;
F_32 ( & V_14 -> V_105 , V_76 ) ;
V_102 = 0 ;
for ( V_106 = 0 ; V_106 < V_14 -> V_107 ; V_106 ++ ) {
if ( V_14 -> V_103 [ V_106 ] . V_104 == V_104 ) {
V_102 = V_14 -> V_103 [ V_106 ] . V_102 ;
goto V_89;
}
}
V_89:
F_33 ( & V_14 -> V_105 , V_76 ) ;
return V_102 ;
}
static T_6
F_64 ( struct V_13 * V_14 , int V_87 ,
int V_88 )
{
T_6 V_108 ;
unsigned long V_76 ;
int V_106 ;
F_32 ( & V_14 -> V_105 , V_76 ) ;
V_108 = 0 ;
for ( V_106 = 0 ; V_106 < V_14 -> V_107 ; V_106 ++ ) {
if ( V_14 -> V_103 [ V_106 ] . V_104 &&
( V_14 -> V_103 [ V_106 ] . V_104 -> V_51 -> V_87 == V_87 &&
V_14 -> V_103 [ V_106 ] . V_104 -> V_51 -> V_88 == V_88 ) ) {
V_108 = 1 ;
goto V_89;
}
}
V_89:
F_33 ( & V_14 -> V_105 , V_76 ) ;
return V_108 ;
}
static T_6
F_65 ( struct V_13 * V_14 , int V_87 ,
unsigned int V_109 , int V_88 )
{
T_6 V_108 ;
unsigned long V_76 ;
int V_106 ;
F_32 ( & V_14 -> V_105 , V_76 ) ;
V_108 = 0 ;
for ( V_106 = 0 ; V_106 < V_14 -> V_107 ; V_106 ++ ) {
if ( V_14 -> V_103 [ V_106 ] . V_104 &&
( V_14 -> V_103 [ V_106 ] . V_104 -> V_51 -> V_87 == V_87 &&
V_14 -> V_103 [ V_106 ] . V_104 -> V_51 -> V_88 == V_88 &&
V_14 -> V_103 [ V_106 ] . V_104 -> V_51 -> V_109 == V_109 ) ) {
V_108 = 1 ;
goto V_89;
}
}
V_89:
F_33 ( & V_14 -> V_105 , V_76 ) ;
return V_108 ;
}
int
F_66 ( struct V_110 * V_75 , int V_111 )
{
struct V_112 * V_113 = V_75 -> V_114 ;
int V_115 ;
struct V_13 * V_14 = F_67 ( V_113 ) ;
struct V_116 * V_117 ;
struct V_72 * V_118 ;
struct V_53 * V_54 ;
unsigned long V_76 ;
V_115 = V_113 -> V_119 ;
V_117 = V_75 -> V_120 ;
if ( ! V_117 )
goto V_121;
V_118 = V_117 -> V_122 ;
if ( ! V_118 )
goto V_121;
if ( ( V_118 -> V_76 & V_123 ) )
goto V_121;
F_32 ( & V_14 -> V_74 , V_76 ) ;
V_54 = F_28 ( V_14 , V_118 ) ;
if ( V_54 ) {
if ( V_54 -> V_96 & V_100 )
V_115 = V_124 ;
F_41 ( V_54 ) ;
}
F_33 ( & V_14 -> V_74 , V_76 ) ;
V_121:
if ( ! V_75 -> V_125 )
V_115 = 1 ;
if ( V_111 > V_115 )
V_111 = V_115 ;
return F_68 ( V_75 , V_111 ) ;
}
int
F_69 ( struct V_126 * V_85 )
{
struct V_112 * V_113 = F_70 ( & V_85 -> V_127 ) ;
struct V_13 * V_14 = F_67 ( V_113 ) ;
struct V_72 * V_118 ;
struct V_53 * V_54 ;
struct V_55 * V_56 ;
unsigned long V_76 ;
struct V_128 * V_129 ;
V_118 = F_9 ( sizeof( * V_118 ) ,
V_130 ) ;
if ( ! V_118 )
return - V_131 ;
V_85 -> V_120 = V_118 ;
V_118 -> V_85 = V_85 ;
V_118 -> V_35 = V_132 ;
if ( V_85 -> V_88 == V_133 ) {
F_32 ( & V_14 -> V_90 , V_76 ) ;
V_56 = F_51 ( V_14 , V_85 -> V_87 ,
V_85 -> V_88 ) ;
if ( V_56 ) {
V_118 -> V_35 = V_56 -> V_35 ;
V_118 -> V_17 = V_56 -> V_60 ;
V_118 -> V_76 |= V_123 ;
V_118 -> V_56 = V_56 ;
if ( V_14 -> V_134 )
V_56 -> V_85 = V_85 ;
}
F_33 ( & V_14 -> V_90 , V_76 ) ;
return 0 ;
}
F_32 ( & V_14 -> V_74 , V_76 ) ;
V_129 = F_71 ( V_85 -> V_127 . V_135 ) ;
V_54 = F_34 ( V_14 ,
V_129 -> V_136 . V_17 ) ;
if ( V_54 ) {
V_118 -> V_35 = V_54 -> V_35 ;
V_118 -> V_17 = V_54 -> V_17 ;
V_118 -> V_75 = V_54 ;
V_54 -> V_85 = V_85 ;
V_54 -> V_87 = V_85 -> V_87 ;
V_54 -> V_88 = V_85 -> V_88 ;
if ( F_72 ( V_54 -> V_35 , V_14 -> V_137 ) )
V_118 -> V_76 |=
V_138 ;
if ( V_54 -> V_139 )
V_118 -> V_76 |= V_140 ;
}
F_33 ( & V_14 -> V_74 , V_76 ) ;
return 0 ;
}
void
F_73 ( struct V_126 * V_85 )
{
struct V_112 * V_113 = F_70 ( & V_85 -> V_127 ) ;
struct V_13 * V_14 = F_67 ( V_113 ) ;
struct V_72 * V_118 ;
struct V_53 * V_54 ;
struct V_55 * V_56 ;
unsigned long V_76 ;
struct V_128 * V_129 ;
V_118 = V_85 -> V_120 ;
if ( ! V_118 )
return;
if ( V_85 -> V_88 == V_133 ) {
F_32 ( & V_14 -> V_90 , V_76 ) ;
V_56 = F_51 ( V_14 , V_85 -> V_87 ,
V_85 -> V_88 ) ;
if ( V_56 ) {
V_56 -> V_85 = NULL ;
V_56 -> V_75 = NULL ;
}
F_33 ( & V_14 -> V_90 , V_76 ) ;
goto V_89;
}
F_32 ( & V_14 -> V_74 , V_76 ) ;
V_129 = F_71 ( V_85 -> V_127 . V_135 ) ;
V_54 = F_28 ( V_14 , V_118 ) ;
if ( V_54 && ( V_54 -> V_85 == V_85 ) &&
( V_54 -> V_87 == V_85 -> V_87 ) &&
( V_54 -> V_88 == V_85 -> V_88 ) )
V_54 -> V_85 = NULL ;
if ( V_54 ) {
V_118 -> V_75 = NULL ;
F_41 ( V_54 ) ;
F_41 ( V_54 ) ;
}
F_33 ( & V_14 -> V_74 , V_76 ) ;
V_89:
F_2 ( V_118 ) ;
V_85 -> V_120 = NULL ;
}
int
F_74 ( struct V_110 * V_75 )
{
struct V_112 * V_113 ;
struct V_13 * V_14 ;
struct V_72 * V_118 ;
struct V_116 * V_117 ;
struct V_126 * V_85 ;
struct V_55 * V_56 ;
struct V_53 * V_54 ;
unsigned long V_76 ;
V_117 = F_9 ( sizeof( * V_117 ) ,
V_130 ) ;
if ( ! V_117 )
return - V_131 ;
V_117 -> V_109 = V_75 -> V_109 ;
V_117 -> V_76 = V_141 ;
V_85 = V_126 ( V_75 ) ;
V_118 = V_85 -> V_120 ;
V_118 -> V_142 ++ ;
V_117 -> V_122 = V_118 ;
V_75 -> V_120 = V_117 ;
if ( ( V_118 -> V_76 & V_138 ) )
V_75 -> V_143 = 1 ;
V_113 = F_70 ( & V_85 -> V_127 ) ;
V_14 = F_67 ( V_113 ) ;
if ( V_85 -> V_88 == V_133 ) {
F_32 ( & V_14 -> V_90 , V_76 ) ;
V_56 = F_51 ( V_14 ,
V_85 -> V_87 , V_85 -> V_88 ) ;
if ( V_56 )
V_56 -> V_75 = V_75 ;
F_33 ( & V_14 -> V_90 , V_76 ) ;
}
if ( ! ( V_118 -> V_76 & V_123 ) ) {
F_32 ( & V_14 -> V_74 , V_76 ) ;
V_54 = F_34 ( V_14 ,
V_118 -> V_17 ) ;
if ( V_54 && ( V_54 -> V_85 == NULL ) ) {
F_75 ( V_144 , V_75 ,
L_14 ,
V_44 , __LINE__ ) ;
V_54 -> V_85 = V_85 ;
}
if ( V_54 )
F_41 ( V_54 ) ;
F_33 ( & V_14 -> V_74 , V_76 ) ;
}
return 0 ;
}
void
F_76 ( struct V_110 * V_75 )
{
struct V_72 * V_118 ;
struct V_126 * V_85 ;
struct V_112 * V_113 ;
struct V_13 * V_14 ;
struct V_53 * V_54 ;
unsigned long V_76 ;
if ( ! V_75 -> V_120 )
return;
V_85 = V_126 ( V_75 ) ;
V_118 = V_85 -> V_120 ;
V_118 -> V_142 -- ;
V_113 = F_70 ( & V_85 -> V_127 ) ;
V_14 = F_67 ( V_113 ) ;
if ( ! ( V_118 -> V_76 & V_123 ) ) {
F_32 ( & V_14 -> V_74 , V_76 ) ;
V_54 = F_28 ( V_14 ,
V_118 ) ;
if ( V_54 && ! V_118 -> V_142 )
V_54 -> V_85 = NULL ;
if ( V_54 )
F_41 ( V_54 ) ;
F_33 ( & V_14 -> V_74 , V_76 ) ;
}
F_2 ( V_75 -> V_120 ) ;
V_75 -> V_120 = NULL ;
}
static void
F_77 ( struct V_13 * V_14 ,
T_4 V_35 , struct V_110 * V_75 )
{
T_9 V_37 ;
T_8 V_36 ;
T_10 V_38 ;
T_4 V_76 ;
T_10 V_96 ;
if ( ( F_24 ( V_14 , & V_37 , & V_36 ,
V_41 , V_35 ) ) ) {
F_25 ( V_42 L_2 ,
V_14 -> V_43 , __FILE__ , __LINE__ , V_44 ) ;
return;
}
V_38 = F_21 ( V_37 . V_46 ) &
V_47 ;
if ( V_38 != V_48 ) {
F_25 ( V_42 L_2 ,
V_14 -> V_43 , __FILE__ , __LINE__ , V_44 ) ;
return;
}
V_76 = F_21 ( V_36 . V_145 ) ;
V_96 = F_78 ( V_36 . V_146 ) ;
F_75 ( V_144 , V_75 ,
L_15
L_16 ,
( V_96 & V_147 ) ? L_17 : L_18 ,
( V_76 & V_148 ) ? L_17 : L_18 ,
( V_76 & V_149 ) ? L_17 :
L_18 ,
( V_76 & V_150 ) ? L_17 : L_18 ,
( V_76 & V_151 ) ? L_17 : L_18 ,
( V_76 & V_152 ) ? L_17 : L_18 ) ;
}
int
F_79 ( struct V_51 * V_127 )
{
struct V_110 * V_75 = F_80 ( V_127 ) ;
struct V_13 * V_14 = F_67 ( V_75 -> V_114 ) ;
if ( V_14 -> V_134 )
return 0 ;
return ( V_75 -> V_88 == V_133 ) ? 1 : 0 ;
}
void
F_81 ( struct V_51 * V_127 )
{
struct V_110 * V_75 = F_80 ( V_127 ) ;
struct V_13 * V_14 = F_67 ( V_75 -> V_114 ) ;
static struct V_55 * V_56 ;
unsigned long V_76 ;
T_11 V_153 ;
T_9 V_37 ;
T_10 V_154 ;
T_6 V_155 ;
T_4 V_35 ;
V_155 = 0 ;
V_35 = 0 ;
if ( V_14 -> V_134 )
goto V_89;
F_32 ( & V_14 -> V_90 , V_76 ) ;
V_56 = F_51 ( V_14 , V_75 -> V_87 ,
V_75 -> V_88 ) ;
if ( V_56 ) {
V_35 = V_56 -> V_35 ;
V_155 = V_56 -> V_155 ;
}
F_33 ( & V_14 -> V_90 , V_76 ) ;
if ( ! V_35 )
goto V_89;
if ( F_82 ( V_14 , & V_37 , & V_153 ,
V_156 , V_35 ,
sizeof( T_11 ) ) ) {
F_25 ( V_42 L_2 ,
V_14 -> V_43 , __FILE__ , __LINE__ , V_44 ) ;
V_155 = 0 ;
goto V_89;
}
V_154 = F_78 ( V_153 . V_157 ) ;
if ( ! ( V_154 &
V_158 ) )
V_155 = 0 ;
V_89:
if ( V_14 -> V_159 == V_160 )
F_83 ( V_161 , V_127 , V_155 ) ;
if ( V_14 -> V_159 == V_162 )
F_83 ( V_163 , V_127 , V_155 ) ;
}
void
F_84 ( struct V_51 * V_127 )
{
struct V_110 * V_75 = F_80 ( V_127 ) ;
struct V_13 * V_14 = F_67 ( V_75 -> V_114 ) ;
static struct V_55 * V_56 ;
unsigned long V_76 ;
T_11 V_153 ;
T_9 V_37 ;
T_10 V_164 ;
enum V_165 V_166 = V_167 ;
T_4 V_35 = 0 ;
F_32 ( & V_14 -> V_90 , V_76 ) ;
V_56 = F_51 ( V_14 , V_75 -> V_87 ,
V_75 -> V_88 ) ;
if ( V_56 )
V_35 = V_56 -> V_35 ;
F_33 ( & V_14 -> V_90 , V_76 ) ;
if ( ! V_56 )
goto V_89;
if ( F_82 ( V_14 , & V_37 , & V_153 ,
V_156 , V_35 ,
sizeof( T_11 ) ) ) {
F_25 ( V_42 L_2 ,
V_14 -> V_43 , __FILE__ , __LINE__ , V_44 ) ;
goto V_89;
}
V_164 = F_78 ( V_153 . V_157 ) ;
if ( V_164 & V_158 ) {
V_166 = V_168 ;
goto V_89;
}
switch ( V_153 . V_169 ) {
case V_170 :
case V_171 :
V_166 = V_172 ;
break;
case V_173 :
V_166 = V_174 ;
break;
case V_175 :
case V_176 :
V_166 = V_177 ;
break;
}
V_89:
if ( V_14 -> V_159 == V_160 )
F_85 ( V_161 , V_127 , V_166 ) ;
if ( V_14 -> V_159 == V_162 )
F_85 ( V_163 , V_127 , V_166 ) ;
}
static void
F_86 ( struct V_13 * V_14 ,
struct V_110 * V_75 , T_6 V_178 )
{
enum V_179 V_180 = V_181 ;
switch ( V_178 ) {
case V_182 :
V_180 = V_183 ;
break;
case V_184 :
V_180 = V_185 ;
break;
case V_186 :
V_180 = V_187 ;
break;
case V_188 :
V_180 = V_189 ;
break;
}
if ( V_14 -> V_159 == V_160 )
F_87 ( V_161 ,
& V_75 -> V_190 , V_180 ) ;
if ( V_14 -> V_159 == V_162 )
F_87 ( V_163 ,
& V_75 -> V_190 , V_180 ) ;
}
static int
F_88 ( struct V_13 * V_14 ,
struct V_55 * V_56 )
{
T_11 * V_153 ;
T_12 V_191 ;
T_8 V_36 ;
T_9 V_37 ;
T_4 V_192 ;
T_6 V_193 ;
if ( ( F_89 ( V_14 , V_56 -> V_35 ,
& V_193 ) ) || ! V_193 ) {
F_90 ( V_14 , F_91 ( V_42
L_2 , V_14 -> V_43 , __FILE__ , __LINE__ ,
V_44 ) ) ;
return 1 ;
}
V_56 -> V_193 = V_193 ;
V_192 = F_92 ( T_11 , V_194 ) + ( V_193 *
sizeof( V_195 ) ) ;
V_153 = F_9 ( V_192 , V_130 ) ;
if ( ! V_153 ) {
F_90 ( V_14 , F_91 ( V_42
L_2 , V_14 -> V_43 , __FILE__ , __LINE__ ,
V_44 ) ) ;
return 1 ;
}
if ( ( F_82 ( V_14 , & V_37 , V_153 ,
V_156 , V_56 -> V_35 , V_192 ) ) ) {
F_90 ( V_14 , F_91 ( V_42
L_2 , V_14 -> V_43 , __FILE__ , __LINE__ ,
V_44 ) ) ;
F_2 ( V_153 ) ;
return 1 ;
}
V_56 -> V_178 = V_153 -> V_196 ;
if ( ! ( F_93 ( V_14 , & V_37 ,
& V_191 , V_197 ,
V_153 -> V_194 [ 0 ] . V_198 ) ) ) {
if ( ! ( F_24 ( V_14 , & V_37 ,
& V_36 , V_41 ,
F_21 ( V_191 . V_199 ) ) ) ) {
V_56 -> V_96 =
F_78 ( V_36 . V_146 ) ;
}
}
F_2 ( V_153 ) ;
return 0 ;
}
static void
F_94 ( struct V_13 * V_14 , struct V_110 * V_75 )
{
if ( V_75 -> type != V_200 )
return;
if ( ! ( V_14 -> V_201 . V_202 & V_203 ) )
return;
F_95 ( V_75 ) ;
F_75 ( V_144 , V_75 , L_19 ,
F_96 ( V_75 ) ? L_20 : L_21 ) ;
return;
}
int
F_97 ( struct V_110 * V_75 )
{
struct V_112 * V_113 = V_75 -> V_114 ;
struct V_13 * V_14 = F_67 ( V_113 ) ;
struct V_116 * V_117 ;
struct V_72 * V_118 ;
struct V_53 * V_54 ;
struct V_55 * V_56 ;
unsigned long V_76 ;
int V_111 ;
T_6 V_204 = 0 ;
char * V_205 = L_22 ;
char * V_206 = L_22 ;
T_4 V_35 , V_207 = 0 ;
T_1 V_208 = 0 ;
V_111 = 1 ;
V_117 = V_75 -> V_120 ;
V_117 -> V_209 = 1 ;
V_117 -> V_76 &= ~ V_141 ;
V_118 = V_117 -> V_122 ;
V_35 = V_118 -> V_35 ;
if ( V_118 -> V_76 & V_123 ) {
F_32 ( & V_14 -> V_90 , V_76 ) ;
V_56 = F_52 ( V_14 , V_35 ) ;
F_33 ( & V_14 -> V_90 , V_76 ) ;
if ( ! V_56 ) {
F_90 ( V_14 , F_91 ( V_42
L_2 , V_14 -> V_43 , __FILE__ ,
__LINE__ , V_44 ) ) ;
return 1 ;
}
if ( F_88 ( V_14 , V_56 ) ) {
F_90 ( V_14 , F_91 ( V_42
L_2 , V_14 -> V_43 , __FILE__ ,
__LINE__ , V_44 ) ) ;
return 1 ;
}
F_98 ( V_14 , V_56 ) ;
if ( V_56 -> V_96 &
V_98 ) {
V_111 = V_210 ;
V_205 = L_23 ;
} else {
V_111 = V_124 ;
if ( V_56 -> V_96 &
V_100 )
V_205 = L_24 ;
else
V_205 = L_25 ;
}
switch ( V_56 -> V_178 ) {
case V_182 :
V_206 = L_26 ;
break;
case V_186 :
V_111 = V_211 ;
if ( V_14 -> V_212 . V_213 &&
( F_78 ( V_14 -> V_212 . V_214 ) &
V_215 ) &&
! ( V_56 -> V_193 % 2 ) )
V_206 = L_27 ;
else
V_206 = L_28 ;
break;
case V_188 :
V_111 = V_211 ;
V_206 = L_29 ;
break;
case V_184 :
V_111 = V_211 ;
V_206 = L_27 ;
break;
case V_216 :
default:
V_111 = V_211 ;
V_206 = L_30 ;
break;
}
if ( ! V_14 -> V_217 )
F_75 ( V_144 , V_75 ,
L_31
L_32 ,
V_206 , V_56 -> V_35 ,
( unsigned long long ) V_56 -> V_60 ,
V_56 -> V_193 , V_205 ) ;
F_66 ( V_75 , V_111 ) ;
if ( ! V_14 -> V_134 )
F_86 ( V_14 , V_75 , V_56 -> V_178 ) ;
return 0 ;
}
if ( V_118 -> V_76 & V_138 ) {
if ( F_99 ( V_14 , V_35 ,
& V_207 ) ) {
F_90 ( V_14 , F_91 ( V_42
L_2 , V_14 -> V_43 ,
__FILE__ , __LINE__ , V_44 ) ) ;
return 1 ;
}
if ( V_207 && F_100 ( V_14 ,
V_207 , & V_208 ) ) {
F_90 ( V_14 , F_91 ( V_42
L_2 , V_14 -> V_43 ,
__FILE__ , __LINE__ , V_44 ) ) ;
return 1 ;
}
}
F_32 ( & V_14 -> V_74 , V_76 ) ;
V_54 = F_34 ( V_14 ,
V_117 -> V_122 -> V_17 ) ;
if ( ! V_54 ) {
F_33 ( & V_14 -> V_74 , V_76 ) ;
F_90 ( V_14 , F_91 ( V_42
L_2 , V_14 -> V_43 , __FILE__ , __LINE__ ,
V_44 ) ) ;
return 1 ;
}
V_54 -> V_207 = V_207 ;
V_54 -> V_208 = V_208 ;
if ( V_54 -> V_96 & V_98 ) {
V_111 = V_210 ;
V_204 = 1 ;
V_205 = L_23 ;
} else {
V_111 = V_124 ;
if ( V_54 -> V_96 & V_99 )
V_205 = L_25 ;
else if ( V_54 -> V_96 &
V_100 )
V_205 = L_24 ;
}
F_75 ( V_144 , V_75 , L_33 \
L_34 ,
V_205 , V_35 , ( unsigned long long ) V_54 -> V_17 ,
V_54 -> V_218 , ( unsigned long long ) V_54 -> V_20 ) ;
if ( V_54 -> V_78 != 0 )
F_75 ( V_144 , V_75 ,
L_35 ,
V_205 , ( unsigned long long )
V_54 -> V_22 , V_54 -> V_26 ) ;
if ( V_54 -> V_79 [ 0 ] != '\0' )
F_75 ( V_144 , V_75 ,
L_12 ,
V_205 , V_54 -> V_80 ,
V_54 -> V_79 ) ;
F_41 ( V_54 ) ;
F_33 ( & V_14 -> V_74 , V_76 ) ;
if ( ! V_204 )
F_77 ( V_14 , V_35 , V_75 ) ;
F_66 ( V_75 , V_111 ) ;
if ( V_204 ) {
F_101 ( V_75 ) ;
F_94 ( V_14 , V_75 ) ;
}
return 0 ;
}
int
F_102 ( struct V_110 * V_75 , struct V_219 * V_220 ,
T_13 V_221 , int V_222 [] )
{
int V_223 ;
int V_224 ;
T_13 V_225 ;
T_14 V_226 ;
V_223 = 64 ;
V_224 = 32 ;
V_226 = V_223 * V_224 ;
V_225 = V_221 ;
F_103 ( V_225 , V_226 ) ;
if ( ( T_14 ) V_221 >= 0x200000 ) {
V_223 = 255 ;
V_224 = 63 ;
V_226 = V_223 * V_224 ;
V_225 = V_221 ;
F_103 ( V_225 , V_226 ) ;
}
V_222 [ 0 ] = V_223 ;
V_222 [ 1 ] = V_224 ;
V_222 [ 2 ] = V_225 ;
return 0 ;
}
static void
F_104 ( struct V_13 * V_14 , T_6 V_227 )
{
char * V_228 ;
switch ( V_227 ) {
case V_229 :
V_228 = L_36 ;
break;
case V_230 :
V_228 = L_37 ;
break;
case V_231 :
V_228 = L_38 ;
break;
case V_232 :
V_228 = L_39 ;
break;
case V_233 :
V_228 = L_40 ;
break;
case V_234 :
V_228 = L_41 ;
break;
case 0xA :
V_228 = L_42 ;
break;
case V_235 :
V_228 = L_43 ;
break;
default:
V_228 = L_44 ;
break;
}
F_91 ( V_42 L_45 ,
V_14 -> V_43 , V_227 , V_228 ) ;
}
static T_6
F_105 ( struct V_13 * V_14 , T_4 V_102 , T_6 V_236 , T_10 V_237 )
{
T_15 * V_37 ;
if ( V_14 -> V_238 . V_239 == V_240 )
return 1 ;
if ( V_14 -> V_238 . V_102 != V_102 )
return 1 ;
F_106 ( V_14 ) ;
V_14 -> V_238 . V_239 |= V_241 ;
V_37 = F_107 ( V_14 , V_237 ) ;
if ( V_37 ) {
memcpy ( V_14 -> V_238 . V_237 , V_37 , V_37 -> V_242 * 4 ) ;
V_14 -> V_238 . V_239 |= V_243 ;
}
V_14 -> V_238 . V_239 &= ~ V_244 ;
F_108 ( & V_14 -> V_238 . V_245 ) ;
return 1 ;
}
void
F_109 ( struct V_13 * V_14 , T_4 V_35 )
{
struct V_116 * V_117 ;
struct V_110 * V_75 ;
T_6 V_246 = 0 ;
F_110 (sdev, ioc->shost) {
if ( V_246 )
continue;
V_117 = V_75 -> V_120 ;
if ( ! V_117 )
continue;
if ( V_117 -> V_122 -> V_35 == V_35 ) {
V_117 -> V_122 -> V_247 = 1 ;
V_246 = 1 ;
V_14 -> V_248 = 1 ;
}
}
}
void
F_111 ( struct V_13 * V_14 , T_4 V_35 )
{
struct V_116 * V_117 ;
struct V_110 * V_75 ;
T_6 V_246 = 0 ;
F_110 (sdev, ioc->shost) {
if ( V_246 )
continue;
V_117 = V_75 -> V_120 ;
if ( ! V_117 )
continue;
if ( V_117 -> V_122 -> V_35 == V_35 ) {
V_117 -> V_122 -> V_247 = 0 ;
V_246 = 1 ;
V_14 -> V_248 = 0 ;
}
}
}
int
F_112 ( struct V_13 * V_14 , T_4 V_35 , T_16 V_88 ,
T_16 V_87 , T_16 V_109 , T_6 type , T_4 V_249 , T_14 V_250 ,
enum V_251 V_252 )
{
T_17 * V_253 ;
T_18 * V_37 ;
T_4 V_102 = 0 ;
T_10 V_254 ;
unsigned long V_255 ;
struct V_256 * V_103 = NULL ;
int V_28 ;
if ( V_252 == V_257 )
F_113 ( & V_14 -> V_238 . V_258 ) ;
if ( V_14 -> V_238 . V_239 != V_240 ) {
F_13 ( V_42 L_46 ,
V_44 , V_14 -> V_43 ) ;
V_28 = V_259 ;
goto V_260;
}
if ( V_14 -> V_82 || V_14 -> V_261 ||
V_14 -> V_262 ) {
F_13 ( V_42 L_47 ,
V_44 , V_14 -> V_43 ) ;
V_28 = V_259 ;
goto V_260;
}
V_254 = F_114 ( V_14 , 0 ) ;
if ( V_254 & V_263 ) {
F_115 ( V_14 , F_13 ( V_42
L_48 , V_14 -> V_43 ) ) ;
V_28 = F_116 ( V_14 , V_264 ,
V_265 ) ;
V_28 = ( ! V_28 ) ? V_266 : V_259 ;
goto V_260;
}
if ( ( V_254 & V_267 ) == V_268 ) {
F_117 ( V_14 , V_254 &
V_269 ) ;
V_28 = F_116 ( V_14 , V_264 ,
V_265 ) ;
V_28 = ( ! V_28 ) ? V_266 : V_259 ;
goto V_260;
}
V_102 = F_118 ( V_14 , V_14 -> V_270 ) ;
if ( ! V_102 ) {
F_25 ( V_42 L_49 ,
V_14 -> V_43 , V_44 ) ;
V_28 = V_259 ;
goto V_260;
}
if ( type == V_271 )
V_103 = & V_14 -> V_103 [ V_249 - 1 ] ;
F_119 ( V_14 , F_13 ( V_42
L_50 ,
V_14 -> V_43 , V_35 , type , V_249 ) ) ;
V_14 -> V_238 . V_239 = V_244 ;
V_253 = F_120 ( V_14 , V_102 ) ;
V_14 -> V_238 . V_102 = V_102 ;
memset ( V_253 , 0 , sizeof( T_17 ) ) ;
memset ( V_14 -> V_238 . V_237 , 0 , sizeof( T_18 ) ) ;
V_253 -> V_272 = V_273 ;
V_253 -> V_199 = F_121 ( V_35 ) ;
V_253 -> V_274 = type ;
V_253 -> V_275 = F_121 ( V_249 ) ;
F_122 ( V_109 , (struct V_276 * ) V_253 -> V_277 ) ;
F_109 ( V_14 , V_35 ) ;
F_123 ( & V_14 -> V_238 . V_245 ) ;
F_124 ( V_14 , V_102 ) ;
V_255 = F_125 ( & V_14 -> V_238 . V_245 , V_250 * V_278 ) ;
if ( ! ( V_14 -> V_238 . V_239 & V_241 ) ) {
F_25 ( V_42 L_51 ,
V_14 -> V_43 , V_44 ) ;
F_126 ( V_253 ,
sizeof( T_17 ) / 4 ) ;
if ( ! ( V_14 -> V_238 . V_239 & V_279 ) ) {
V_28 = F_116 ( V_14 , V_264 ,
V_265 ) ;
V_28 = ( ! V_28 ) ? V_266 : V_259 ;
V_14 -> V_238 . V_239 = V_240 ;
F_111 ( V_14 , V_35 ) ;
goto V_260;
}
}
if ( V_14 -> V_238 . V_239 & V_243 ) {
F_127 ( V_14 , V_280 ) ;
V_37 = V_14 -> V_238 . V_237 ;
F_119 ( V_14 , F_13 ( V_42 L_52 \
L_53 ,
V_14 -> V_43 , F_21 ( V_37 -> V_46 ) ,
F_78 ( V_37 -> V_281 ) ,
F_78 ( V_37 -> V_282 ) ) ) ;
if ( V_14 -> V_15 & V_283 ) {
F_104 ( V_14 , V_37 -> V_284 ) ;
if ( V_37 -> V_46 )
F_126 ( V_253 ,
sizeof( T_17 ) / 4 ) ;
}
}
switch ( type ) {
case V_271 :
V_28 = V_266 ;
if ( V_103 -> V_104 == NULL )
break;
V_28 = V_259 ;
break;
case V_285 :
if ( F_64 ( V_14 , V_87 , V_88 ) )
V_28 = V_259 ;
else
V_28 = V_266 ;
break;
case V_286 :
case V_287 :
if ( F_65 ( V_14 , V_87 , V_109 , V_88 ) )
V_28 = V_259 ;
else
V_28 = V_266 ;
break;
case V_288 :
V_28 = V_266 ;
break;
default:
V_28 = V_259 ;
break;
}
F_111 ( V_14 , V_35 ) ;
V_14 -> V_238 . V_239 = V_240 ;
if ( V_252 == V_257 )
F_128 ( & V_14 -> V_238 . V_258 ) ;
return V_28 ;
V_260:
if ( V_252 == V_257 )
F_128 ( & V_14 -> V_238 . V_258 ) ;
return V_28 ;
}
static void
F_129 ( struct V_13 * V_14 , struct V_101 * V_104 )
{
struct V_126 * V_85 = V_104 -> V_51 -> V_289 ;
struct V_72 * V_290 = V_85 -> V_120 ;
struct V_53 * V_54 = NULL ;
unsigned long V_76 ;
char * V_291 = NULL ;
if ( ! V_290 )
return;
if ( V_14 -> V_217 )
V_291 = L_54 ;
else
V_291 = L_55 ;
F_130 ( V_104 ) ;
if ( V_290 -> V_76 & V_123 ) {
F_131 ( V_144 , V_85 ,
L_56 ,
V_291 , V_290 -> V_35 ,
V_291 , ( unsigned long long ) V_290 -> V_17 ) ;
} else {
F_32 ( & V_14 -> V_74 , V_76 ) ;
V_54 = F_28 ( V_14 , V_290 ) ;
if ( V_54 ) {
if ( V_290 -> V_76 &
V_138 ) {
F_131 ( V_144 , V_85 ,
L_57
L_58 ,
V_54 -> V_207 ,
( unsigned long long ) V_54 -> V_208 ) ;
}
F_131 ( V_144 , V_85 ,
L_59 ,
V_54 -> V_35 ,
( unsigned long long ) V_54 -> V_17 ,
V_54 -> V_218 ) ;
if ( V_54 -> V_78 != 0 )
F_131 ( V_144 , V_85 ,
L_60 ,
( unsigned long long )
V_54 -> V_22 ,
V_54 -> V_26 ) ;
if ( V_54 -> V_79 )
F_131 ( V_144 , V_85 ,
L_61 ,
V_54 -> V_80 ,
V_54 -> V_79 ) ;
F_41 ( V_54 ) ;
}
F_33 ( & V_14 -> V_74 , V_76 ) ;
}
}
int
F_132 ( struct V_101 * V_104 )
{
struct V_13 * V_14 = F_67 ( V_104 -> V_51 -> V_114 ) ;
struct V_116 * V_117 ;
T_4 V_102 ;
T_4 V_35 ;
int V_2 ;
F_75 ( V_144 , V_104 -> V_51 ,
L_62 , V_104 ) ;
F_129 ( V_14 , V_104 ) ;
V_117 = V_104 -> V_51 -> V_120 ;
if ( ! V_117 || ! V_117 -> V_122 ) {
F_75 ( V_144 , V_104 -> V_51 ,
L_63 , V_104 ) ;
V_104 -> V_292 = V_293 << 16 ;
V_104 -> V_294 ( V_104 ) ;
V_2 = V_266 ;
goto V_89;
}
V_102 = F_63 ( V_14 , V_104 ) ;
if ( ! V_102 ) {
V_104 -> V_292 = V_295 << 16 ;
V_2 = V_266 ;
goto V_89;
}
if ( V_117 -> V_122 -> V_76 &
V_138 ||
V_117 -> V_122 -> V_76 & V_123 ) {
V_104 -> V_292 = V_295 << 16 ;
V_2 = V_259 ;
goto V_89;
}
F_133 ( V_14 ) ;
V_35 = V_117 -> V_122 -> V_35 ;
V_2 = F_112 ( V_14 , V_35 , V_104 -> V_51 -> V_88 ,
V_104 -> V_51 -> V_87 , V_104 -> V_51 -> V_109 ,
V_271 , V_102 , 30 , V_257 ) ;
V_89:
F_75 ( V_144 , V_104 -> V_51 , L_64 ,
( ( V_2 == V_266 ) ? L_65 : L_66 ) , V_104 ) ;
return V_2 ;
}
int
F_134 ( struct V_101 * V_104 )
{
struct V_13 * V_14 = F_67 ( V_104 -> V_51 -> V_114 ) ;
struct V_116 * V_117 ;
struct V_53 * V_54 = NULL ;
T_4 V_35 ;
int V_2 ;
struct V_126 * V_85 = V_104 -> V_51 -> V_289 ;
struct V_72 * V_296 = V_85 -> V_120 ;
F_75 ( V_144 , V_104 -> V_51 ,
L_67 , V_104 ) ;
F_129 ( V_14 , V_104 ) ;
V_117 = V_104 -> V_51 -> V_120 ;
if ( ! V_117 || ! V_117 -> V_122 ) {
F_75 ( V_144 , V_104 -> V_51 ,
L_63 , V_104 ) ;
V_104 -> V_292 = V_293 << 16 ;
V_104 -> V_294 ( V_104 ) ;
V_2 = V_266 ;
goto V_89;
}
V_35 = 0 ;
if ( V_117 -> V_122 -> V_76 &
V_138 ) {
V_54 = F_31 ( V_14 ,
V_296 ) ;
if ( V_54 )
V_35 = V_54 -> V_207 ;
} else
V_35 = V_117 -> V_122 -> V_35 ;
if ( ! V_35 ) {
V_104 -> V_292 = V_295 << 16 ;
V_2 = V_259 ;
goto V_89;
}
V_2 = F_112 ( V_14 , V_35 , V_104 -> V_51 -> V_88 ,
V_104 -> V_51 -> V_87 , V_104 -> V_51 -> V_109 ,
V_287 , 0 , 30 , V_257 ) ;
V_89:
F_75 ( V_144 , V_104 -> V_51 , L_68 ,
( ( V_2 == V_266 ) ? L_65 : L_66 ) , V_104 ) ;
if ( V_54 )
F_41 ( V_54 ) ;
return V_2 ;
}
int
F_135 ( struct V_101 * V_104 )
{
struct V_13 * V_14 = F_67 ( V_104 -> V_51 -> V_114 ) ;
struct V_116 * V_117 ;
struct V_53 * V_54 = NULL ;
T_4 V_35 ;
int V_2 ;
struct V_126 * V_85 = V_104 -> V_51 -> V_289 ;
struct V_72 * V_296 = V_85 -> V_120 ;
F_131 ( V_144 , V_85 , L_69 ,
V_104 ) ;
F_129 ( V_14 , V_104 ) ;
V_117 = V_104 -> V_51 -> V_120 ;
if ( ! V_117 || ! V_117 -> V_122 ) {
F_131 ( V_144 , V_85 , L_70 ,
V_104 ) ;
V_104 -> V_292 = V_293 << 16 ;
V_104 -> V_294 ( V_104 ) ;
V_2 = V_266 ;
goto V_89;
}
V_35 = 0 ;
if ( V_117 -> V_122 -> V_76 &
V_138 ) {
V_54 = F_31 ( V_14 ,
V_296 ) ;
if ( V_54 )
V_35 = V_54 -> V_207 ;
} else
V_35 = V_117 -> V_122 -> V_35 ;
if ( ! V_35 ) {
V_104 -> V_292 = V_295 << 16 ;
V_2 = V_259 ;
goto V_89;
}
V_2 = F_112 ( V_14 , V_35 , V_104 -> V_51 -> V_88 ,
V_104 -> V_51 -> V_87 , 0 , V_285 , 0 ,
30 , V_257 ) ;
V_89:
F_131 ( V_144 , V_85 , L_71 ,
( ( V_2 == V_266 ) ? L_65 : L_66 ) , V_104 ) ;
if ( V_54 )
F_41 ( V_54 ) ;
return V_2 ;
}
int
F_136 ( struct V_101 * V_104 )
{
struct V_13 * V_14 = F_67 ( V_104 -> V_51 -> V_114 ) ;
int V_2 , V_297 ;
F_13 ( V_42 L_72 ,
V_14 -> V_43 , V_104 ) ;
F_130 ( V_104 ) ;
if ( V_14 -> V_57 ) {
F_13 ( V_42 L_73 ,
V_14 -> V_43 ) ;
V_2 = V_259 ;
goto V_89;
}
V_297 = F_116 ( V_14 , V_264 ,
V_265 ) ;
V_2 = ( V_297 < 0 ) ? V_259 : V_266 ;
V_89:
F_13 ( V_42 L_74 ,
V_14 -> V_43 , ( ( V_2 == V_266 ) ? L_65 : L_66 ) , V_104 ) ;
return V_2 ;
}
static void
F_137 ( struct V_13 * V_14 , struct V_3 * V_7 )
{
unsigned long V_76 ;
if ( V_14 -> V_298 == NULL )
return;
F_32 ( & V_14 -> V_299 , V_76 ) ;
F_4 ( V_7 ) ;
F_138 ( & V_7 -> V_81 ) ;
F_47 ( & V_7 -> V_81 , & V_14 -> V_300 ) ;
F_139 ( & V_7 -> V_301 , V_302 ) ;
F_4 ( V_7 ) ;
F_140 ( V_14 -> V_298 , & V_7 -> V_301 ) ;
F_33 ( & V_14 -> V_299 , V_76 ) ;
}
static void
F_141 ( struct V_13 * V_14 , struct V_3
* V_7 )
{
unsigned long V_76 ;
F_32 ( & V_14 -> V_299 , V_76 ) ;
if ( ! F_39 ( & V_7 -> V_81 ) ) {
F_40 ( & V_7 -> V_81 ) ;
F_6 ( V_7 ) ;
}
F_33 ( & V_14 -> V_299 , V_76 ) ;
}
void
F_142 ( struct V_13 * V_14 ,
struct V_303 * V_304 )
{
struct V_3 * V_7 ;
T_4 V_192 ;
if ( V_14 -> V_57 )
return;
V_192 = sizeof( * V_304 ) ;
V_7 = F_8 ( V_192 ) ;
if ( ! V_7 )
return;
V_7 -> V_305 = V_306 ;
V_7 -> V_14 = V_14 ;
memcpy ( V_7 -> V_304 , V_304 , sizeof( * V_304 ) ) ;
F_137 ( V_14 , V_7 ) ;
F_6 ( V_7 ) ;
}
static void
F_143 ( struct V_13 * V_14 )
{
struct V_3 * V_7 ;
if ( V_14 -> V_57 )
return;
V_7 = F_8 ( 0 ) ;
if ( ! V_7 )
return;
V_7 -> V_305 = V_307 ;
V_7 -> V_14 = V_14 ;
F_137 ( V_14 , V_7 ) ;
F_6 ( V_7 ) ;
}
void
F_144 ( struct V_13 * V_14 )
{
struct V_3 * V_7 ;
V_7 = F_8 ( 0 ) ;
if ( ! V_7 )
return;
V_7 -> V_305 = V_308 ;
V_7 -> V_14 = V_14 ;
F_137 ( V_14 , V_7 ) ;
F_6 ( V_7 ) ;
}
static struct V_3 * F_145 ( struct V_13 * V_14 )
{
unsigned long V_76 ;
struct V_3 * V_7 = NULL ;
F_32 ( & V_14 -> V_299 , V_76 ) ;
if ( ! F_39 ( & V_14 -> V_300 ) ) {
V_7 = F_146 ( & V_14 -> V_300 ,
struct V_3 , V_81 ) ;
F_40 ( & V_7 -> V_81 ) ;
}
F_33 ( & V_14 -> V_299 , V_76 ) ;
return V_7 ;
}
static void
F_147 ( struct V_13 * V_14 )
{
struct V_3 * V_7 ;
if ( F_39 ( & V_14 -> V_300 ) ||
! V_14 -> V_298 || F_148 () )
return;
while ( ( V_7 = F_145 ( V_14 ) ) ) {
if ( F_149 ( & V_7 -> V_309 ) )
F_6 ( V_7 ) ;
F_6 ( V_7 ) ;
}
}
static void
F_150 ( struct V_110 * V_75 ,
struct V_116 * V_117 )
{
int V_2 = 0 ;
F_75 ( V_144 , V_75 , L_75 ,
V_117 -> V_122 -> V_35 ) ;
V_117 -> V_310 = 1 ;
V_2 = F_151 ( V_75 ) ;
if ( V_2 == - V_311 )
F_75 ( V_312 , V_75 ,
L_76 ,
V_117 -> V_122 -> V_35 , V_2 ) ;
}
static void
F_152 ( struct V_110 * V_75 ,
struct V_116 * V_117 )
{
int V_2 = 0 ;
F_75 ( V_312 , V_75 , L_77
L_78 , V_117 -> V_122 -> V_35 ) ;
V_117 -> V_310 = 0 ;
V_2 = F_153 ( V_75 , V_313 ) ;
if ( V_2 == - V_311 ) {
F_75 ( V_312 , V_75 ,
L_79
L_80 ,
V_117 -> V_122 -> V_35 , V_2 ) ;
V_117 -> V_310 = 1 ;
V_2 = F_151 ( V_75 ) ;
if ( V_2 )
F_75 ( V_312 , V_75 , L_81
L_82 ,
V_117 -> V_122 -> V_35 , V_2 ) ;
V_117 -> V_310 = 0 ;
V_2 = F_153 ( V_75 , V_313 ) ;
if ( V_2 )
F_75 ( V_312 , V_75 , L_83
L_84 ,
V_117 -> V_122 -> V_35 , V_2 ) ;
}
}
static void
F_154 ( struct V_13 * V_14 )
{
struct V_116 * V_117 ;
struct V_110 * V_75 ;
F_110 (sdev, ioc->shost) {
V_117 = V_75 -> V_120 ;
if ( ! V_117 )
continue;
if ( ! V_117 -> V_310 )
continue;
F_46 ( V_14 , F_75 ( V_144 , V_75 ,
L_85 ,
V_117 -> V_122 -> V_35 ) ) ;
F_152 ( V_75 , V_117 ) ;
}
}
static void
F_155 ( struct V_13 * V_14 , T_1 V_17 )
{
struct V_116 * V_117 ;
struct V_110 * V_75 ;
F_110 (sdev, ioc->shost) {
V_117 = V_75 -> V_120 ;
if ( ! V_117 )
continue;
if ( V_117 -> V_122 -> V_17
!= V_17 )
continue;
if ( V_117 -> V_310 )
F_152 ( V_75 ,
V_117 ) ;
}
}
static void
F_156 ( struct V_13 * V_14 )
{
struct V_116 * V_117 ;
struct V_110 * V_75 ;
F_110 (sdev, ioc->shost) {
V_117 = V_75 -> V_120 ;
if ( ! V_117 )
continue;
if ( V_117 -> V_310 )
continue;
F_150 ( V_75 , V_117 ) ;
}
}
static void
F_157 ( struct V_13 * V_14 , T_4 V_35 )
{
struct V_116 * V_117 ;
struct V_110 * V_75 ;
struct V_53 * V_54 ;
V_54 = F_37 ( V_14 , V_35 ) ;
if ( ! V_54 )
return;
F_110 (sdev, ioc->shost) {
V_117 = V_75 -> V_120 ;
if ( ! V_117 )
continue;
if ( V_117 -> V_122 -> V_35 != V_35 )
continue;
if ( V_117 -> V_310 )
continue;
if ( V_54 -> V_314 )
continue;
F_150 ( V_75 , V_117 ) ;
}
F_41 ( V_54 ) ;
}
static void
F_158 ( struct V_13 * V_14 ,
struct V_92 * V_93 )
{
struct V_315 * V_316 ;
struct V_53 * V_54 ;
struct V_92 * V_317 ;
unsigned long V_76 ;
if ( ! V_93 )
return;
F_15 (mpt3sas_port,
&sas_expander->sas_port_list, port_list) {
if ( V_316 -> V_318 . V_319 ==
V_320 ) {
F_32 ( & V_14 -> V_74 , V_76 ) ;
V_54 = F_34 ( V_14 ,
V_316 -> V_318 . V_17 ) ;
if ( V_54 ) {
F_159 ( V_54 -> V_35 ,
V_14 -> V_321 ) ;
F_41 ( V_54 ) ;
}
F_33 ( & V_14 -> V_74 , V_76 ) ;
}
}
F_15 (mpt3sas_port,
&sas_expander->sas_port_list, port_list) {
if ( V_316 -> V_318 . V_319 ==
V_322 ||
V_316 -> V_318 . V_319 ==
V_323 ) {
V_317 =
F_58 (
V_14 , V_316 -> V_318 . V_17 ) ;
F_158 ( V_14 ,
V_317 ) ;
}
}
}
static void
F_160 ( struct V_13 * V_14 ,
T_19 * V_304 )
{
int V_106 ;
T_4 V_35 ;
T_4 V_324 ;
for ( V_106 = 0 ; V_106 < V_304 -> V_325 ; V_106 ++ ) {
V_35 = F_21 ( V_304 -> V_326 [ V_106 ] . V_327 ) ;
if ( ! V_35 )
continue;
V_324 = V_304 -> V_326 [ V_106 ] . V_328 &
V_329 ;
if ( V_324 == V_330 )
F_157 ( V_14 , V_35 ) ;
}
}
static void
F_161 ( struct V_13 * V_14 , T_4 V_35 )
{
T_17 * V_253 ;
T_4 V_102 ;
struct V_53 * V_54 = NULL ;
struct V_72 * V_118 = NULL ;
T_1 V_17 = 0 ;
unsigned long V_76 ;
struct V_331 * V_332 ;
T_10 V_254 ;
if ( V_14 -> V_261 ) {
F_46 ( V_14 , F_13 ( V_42
L_86 ,
V_44 , V_14 -> V_43 , V_35 ) ) ;
return;
} else if ( V_14 -> V_262 ) {
F_46 ( V_14 , F_13 ( V_42
L_87 ,
V_44 , V_14 -> V_43 ,
V_35 ) ) ;
return;
}
V_254 = F_114 ( V_14 , 1 ) ;
if ( V_254 != V_333 ) {
F_46 ( V_14 , F_13 ( V_42
L_88 ,
V_44 , V_14 -> V_43 ,
V_35 ) ) ;
return;
}
if ( F_72 ( V_35 , V_14 -> V_137 ) )
return;
F_32 ( & V_14 -> V_74 , V_76 ) ;
V_54 = F_36 ( V_14 , V_35 ) ;
if ( V_54 && V_54 -> V_85 &&
V_54 -> V_85 -> V_120 ) {
V_118 = V_54 -> V_85 -> V_120 ;
V_118 -> V_334 = 1 ;
V_17 = V_54 -> V_17 ;
}
F_33 ( & V_14 -> V_74 , V_76 ) ;
if ( V_118 ) {
F_46 ( V_14 , F_13 ( V_42
L_89 ,
V_14 -> V_43 , V_35 ,
( unsigned long long ) V_17 ) ) ;
if ( V_54 -> V_78 != 0 )
F_46 ( V_14 , F_13 ( V_42
L_90
L_91 , V_14 -> V_43 , ( unsigned long long )
V_54 -> V_22 ,
V_54 -> V_26 ) ) ;
if ( V_54 -> V_79 )
F_46 ( V_14 , F_13 ( V_42
L_92
L_93 , V_14 -> V_43 ,
V_54 -> V_80 ,
V_54 -> V_79 ) ) ;
F_155 ( V_14 , V_17 ) ;
V_118 -> V_35 = V_132 ;
}
V_102 = F_118 ( V_14 , V_14 -> V_335 ) ;
if ( ! V_102 ) {
V_332 = F_9 ( sizeof( * V_332 ) , V_8 ) ;
if ( ! V_332 )
goto V_89;
F_138 ( & V_332 -> V_81 ) ;
V_332 -> V_35 = V_35 ;
F_47 ( & V_332 -> V_81 , & V_14 -> V_336 ) ;
F_46 ( V_14 , F_13 ( V_42
L_94 ,
V_14 -> V_43 , V_35 ) ) ;
goto V_89;
}
F_46 ( V_14 , F_13 ( V_42
L_95 ,
V_14 -> V_43 , V_35 , V_102 ,
V_14 -> V_335 ) ) ;
V_253 = F_120 ( V_14 , V_102 ) ;
memset ( V_253 , 0 , sizeof( T_17 ) ) ;
V_253 -> V_272 = V_273 ;
V_253 -> V_199 = F_121 ( V_35 ) ;
V_253 -> V_274 = V_285 ;
F_124 ( V_14 , V_102 ) ;
F_127 ( V_14 , V_337 ) ;
V_89:
if ( V_54 )
F_41 ( V_54 ) ;
}
static T_6
F_162 ( struct V_13 * V_14 , T_4 V_102 , T_6 V_236 ,
T_10 V_237 )
{
T_4 V_35 ;
T_17 * V_338 ;
T_18 * V_37 =
F_107 ( V_14 , V_237 ) ;
T_20 * V_253 ;
T_4 V_339 ;
T_10 V_254 ;
if ( V_14 -> V_261 ) {
F_46 ( V_14 , F_13 ( V_42
L_96 , V_44 , V_14 -> V_43 ) ) ;
return 1 ;
} else if ( V_14 -> V_262 ) {
F_46 ( V_14 , F_13 ( V_42
L_97 , V_44 ,
V_14 -> V_43 ) ) ;
return 1 ;
}
V_254 = F_114 ( V_14 , 1 ) ;
if ( V_254 != V_333 ) {
F_46 ( V_14 , F_13 ( V_42
L_98 , V_44 , V_14 -> V_43 ) ) ;
return 1 ;
}
if ( F_163 ( ! V_37 ) ) {
F_25 ( V_42 L_99 ,
V_14 -> V_43 , __FILE__ , __LINE__ , V_44 ) ;
return 1 ;
}
V_338 = F_120 ( V_14 , V_102 ) ;
V_35 = F_21 ( V_338 -> V_199 ) ;
if ( V_35 != F_21 ( V_37 -> V_199 ) ) {
F_46 ( V_14 , F_25 ( V_42
L_100 ,
V_14 -> V_43 , V_35 ,
F_21 ( V_37 -> V_199 ) , V_102 ) ) ;
return 0 ;
}
F_127 ( V_14 , V_280 ) ;
F_46 ( V_14 , F_13 ( V_42
L_101
L_102 , V_14 -> V_43 ,
V_35 , V_102 , F_21 ( V_37 -> V_46 ) ,
F_78 ( V_37 -> V_281 ) ,
F_78 ( V_37 -> V_282 ) ) ) ;
V_339 = F_164 ( V_14 , V_14 -> V_340 ) ;
if ( ! V_339 ) {
F_25 ( V_42 L_49 ,
V_14 -> V_43 , V_44 ) ;
return 1 ;
}
F_46 ( V_14 , F_13 ( V_42
L_103 ,
V_14 -> V_43 , V_35 , V_339 ,
V_14 -> V_340 ) ) ;
V_253 = F_120 ( V_14 , V_339 ) ;
memset ( V_253 , 0 , sizeof( T_20 ) ) ;
V_253 -> V_272 = V_341 ;
V_253 -> V_342 = V_343 ;
V_253 -> V_199 = V_338 -> V_199 ;
F_165 ( V_14 , V_339 ) ;
return F_166 ( V_14 , V_102 ) ;
}
static T_6
F_167 ( struct V_13 * V_14 , T_4 V_102 ,
T_6 V_236 , T_10 V_237 )
{
T_21 * V_37 =
F_107 ( V_14 , V_237 ) ;
if ( F_168 ( V_37 ) ) {
F_46 ( V_14 , F_13 ( V_42
L_104
L_105 ,
V_14 -> V_43 , F_21 ( V_37 -> V_199 ) , V_102 ,
F_21 ( V_37 -> V_46 ) ,
F_78 ( V_37 -> V_281 ) ) ) ;
} else {
F_25 ( V_42 L_99 ,
V_14 -> V_43 , __FILE__ , __LINE__ , V_44 ) ;
}
return 1 ;
}
static void
F_169 ( struct V_13 * V_14 , T_4 V_35 )
{
T_17 * V_253 ;
T_4 V_102 ;
struct V_331 * V_332 ;
if ( V_14 -> V_82 || V_14 -> V_261 ||
V_14 -> V_262 ) {
F_46 ( V_14 , F_13 ( V_42
L_47 ,
V_44 , V_14 -> V_43 ) ) ;
return;
}
V_102 = F_118 ( V_14 , V_14 -> V_344 ) ;
if ( ! V_102 ) {
V_332 = F_9 ( sizeof( * V_332 ) , V_8 ) ;
if ( ! V_332 )
return;
F_138 ( & V_332 -> V_81 ) ;
V_332 -> V_35 = V_35 ;
F_47 ( & V_332 -> V_81 , & V_14 -> V_345 ) ;
F_46 ( V_14 , F_13 ( V_42
L_94 ,
V_14 -> V_43 , V_35 ) ) ;
return;
}
F_46 ( V_14 , F_13 ( V_42
L_95 ,
V_14 -> V_43 , V_35 , V_102 ,
V_14 -> V_344 ) ) ;
V_253 = F_120 ( V_14 , V_102 ) ;
memset ( V_253 , 0 , sizeof( T_17 ) ) ;
V_253 -> V_272 = V_273 ;
V_253 -> V_199 = F_121 ( V_35 ) ;
V_253 -> V_274 = V_285 ;
F_124 ( V_14 , V_102 ) ;
}
static T_6
F_170 ( struct V_13 * V_14 , T_4 V_102 ,
T_6 V_236 , T_10 V_237 )
{
T_4 V_35 ;
T_17 * V_338 ;
T_18 * V_37 =
F_107 ( V_14 , V_237 ) ;
if ( V_14 -> V_82 || V_14 -> V_261 ||
V_14 -> V_262 ) {
F_46 ( V_14 , F_13 ( V_42
L_47 ,
V_44 , V_14 -> V_43 ) ) ;
return 1 ;
}
if ( F_163 ( ! V_37 ) ) {
F_25 ( V_42 L_99 ,
V_14 -> V_43 , __FILE__ , __LINE__ , V_44 ) ;
return 1 ;
}
V_338 = F_120 ( V_14 , V_102 ) ;
V_35 = F_21 ( V_338 -> V_199 ) ;
if ( V_35 != F_21 ( V_37 -> V_199 ) ) {
F_46 ( V_14 , F_25 ( V_42
L_100 ,
V_14 -> V_43 , V_35 ,
F_21 ( V_37 -> V_199 ) , V_102 ) ) ;
return 0 ;
}
F_46 ( V_14 , F_13 ( V_42
L_101
L_102 , V_14 -> V_43 ,
V_35 , V_102 , F_21 ( V_37 -> V_46 ) ,
F_78 ( V_37 -> V_281 ) ,
F_78 ( V_37 -> V_282 ) ) ) ;
return F_166 ( V_14 , V_102 ) ;
}
static T_6
F_166 ( struct V_13 * V_14 , T_4 V_102 )
{
struct V_331 * V_332 ;
if ( ! F_39 ( & V_14 -> V_345 ) ) {
V_332 = F_171 ( V_14 -> V_345 . V_346 ,
struct V_331 , V_81 ) ;
F_172 ( V_14 , V_102 ) ;
F_169 ( V_14 , V_332 -> V_35 ) ;
F_56 ( & V_332 -> V_81 ) ;
F_2 ( V_332 ) ;
return 0 ;
}
if ( ! F_39 ( & V_14 -> V_336 ) ) {
V_332 = F_171 ( V_14 -> V_336 . V_346 ,
struct V_331 , V_81 ) ;
F_172 ( V_14 , V_102 ) ;
F_161 ( V_14 , V_332 -> V_35 ) ;
F_56 ( & V_332 -> V_81 ) ;
F_2 ( V_332 ) ;
return 0 ;
}
return 1 ;
}
static void
F_173 ( struct V_13 * V_14 ,
T_19 * V_304 )
{
struct V_3 * V_7 ;
T_19 * V_347 ;
T_4 V_348 ;
struct V_92 * V_93 ;
unsigned long V_76 ;
int V_106 , V_324 ;
T_4 V_35 ;
for ( V_106 = 0 ; V_106 < V_304 -> V_325 ; V_106 ++ ) {
V_35 = F_21 ( V_304 -> V_326 [ V_106 ] . V_327 ) ;
if ( ! V_35 )
continue;
V_324 = V_304 -> V_326 [ V_106 ] . V_328 &
V_329 ;
if ( V_324 == V_349 )
F_161 ( V_14 , V_35 ) ;
}
V_348 = F_21 ( V_304 -> V_350 ) ;
if ( V_348 < V_14 -> V_39 . V_40 ) {
F_160 ( V_14 , V_304 ) ;
return;
}
if ( V_304 -> V_351 ==
V_352 ) {
F_32 ( & V_14 -> V_94 , V_76 ) ;
V_93 = F_57 ( V_14 ,
V_348 ) ;
F_158 ( V_14 , V_93 ) ;
F_33 ( & V_14 -> V_94 , V_76 ) ;
do {
V_35 = F_174 ( V_14 -> V_321 ,
V_14 -> V_201 . V_353 ) ;
if ( V_35 < V_14 -> V_201 . V_353 )
F_157 ( V_14 , V_35 ) ;
} while ( F_175 ( V_35 , V_14 -> V_321 ) );
} else if ( V_304 -> V_351 == V_354 )
F_160 ( V_14 , V_304 ) ;
if ( V_304 -> V_351 != V_355 )
return;
F_32 ( & V_14 -> V_299 , V_76 ) ;
F_15 (fw_event, &ioc->fw_event_list, list) {
if ( V_7 -> V_305 != V_356 ||
V_7 -> V_357 )
continue;
V_347 = ( T_19 * )
V_7 -> V_304 ;
if ( V_347 -> V_351 ==
V_358 ||
V_347 -> V_351 ==
V_354 ) {
if ( F_21 ( V_347 -> V_350 ) ==
V_348 ) {
F_46 ( V_14 , F_13 ( V_42
L_106 , V_14 -> V_43 ) ) ;
V_7 -> V_357 = 1 ;
}
}
}
F_33 ( & V_14 -> V_299 , V_76 ) ;
}
static void
F_176 ( struct V_13 * V_14 , T_4 V_35 )
{
struct V_55 * V_56 ;
struct V_72 * V_118 ;
unsigned long V_76 ;
F_32 ( & V_14 -> V_90 , V_76 ) ;
V_56 = F_52 ( V_14 , V_35 ) ;
if ( V_56 && V_56 -> V_85 &&
V_56 -> V_85 -> V_120 ) {
V_118 =
V_56 -> V_85 -> V_120 ;
V_118 -> V_334 = 1 ;
F_46 ( V_14 , F_13 ( V_42
L_107
L_108 , V_14 -> V_43 , V_35 ,
( unsigned long long ) V_56 -> V_60 ) ) ;
}
F_33 ( & V_14 -> V_90 , V_76 ) ;
}
static void
F_177 ( T_4 V_35 , T_4 * V_359 , T_4 * V_360 )
{
if ( ! V_35 || V_35 == * V_359 || V_35 == * V_360 )
return;
if ( ! * V_359 )
* V_359 = V_35 ;
else if ( ! * V_360 )
* V_360 = V_35 ;
}
static void
F_178 ( struct V_13 * V_14 ,
T_22 * V_304 )
{
T_23 * V_361 ;
int V_106 ;
T_4 V_35 , V_207 , V_359 , V_360 ;
struct V_331 * V_332 ;
V_359 = 0 ;
V_360 = 0 ;
if ( V_14 -> V_134 )
return;
V_361 = ( T_23 * ) & V_304 -> V_362 [ 0 ] ;
for ( V_106 = 0 ; V_106 < V_304 -> V_363 ; V_106 ++ , V_361 ++ ) {
if ( F_78 ( V_304 -> V_145 ) &
V_364 )
continue;
if ( V_361 -> V_365 ==
V_366 ||
V_361 -> V_365 ==
V_367 ) {
V_207 = F_21 ( V_361 -> V_368 ) ;
F_176 ( V_14 , V_207 ) ;
F_177 ( V_207 , & V_359 , & V_360 ) ;
}
}
V_361 = ( T_23 * ) & V_304 -> V_362 [ 0 ] ;
for ( V_106 = 0 ; V_106 < V_304 -> V_363 ; V_106 ++ , V_361 ++ ) {
if ( F_78 ( V_304 -> V_145 ) &
V_364 )
continue;
if ( V_361 -> V_365 == V_369 ) {
V_207 = F_21 ( V_361 -> V_368 ) ;
F_177 ( V_207 , & V_359 , & V_360 ) ;
}
}
if ( V_359 )
F_169 ( V_14 , V_359 ) ;
if ( V_360 )
F_169 ( V_14 , V_360 ) ;
V_361 = ( T_23 * ) & V_304 -> V_362 [ 0 ] ;
for ( V_106 = 0 ; V_106 < V_304 -> V_363 ; V_106 ++ , V_361 ++ ) {
if ( V_361 -> V_365 != V_369 )
continue;
V_35 = F_21 ( V_361 -> V_370 ) ;
V_207 = F_21 ( V_361 -> V_368 ) ;
F_179 ( V_35 , V_14 -> V_137 ) ;
if ( ! V_207 )
F_161 ( V_14 , V_35 ) ;
else if ( V_207 == V_359 || V_207 == V_360 ) {
V_332 = F_9 ( sizeof( * V_332 ) , V_8 ) ;
F_180 ( ! V_332 ) ;
F_138 ( & V_332 -> V_81 ) ;
V_332 -> V_35 = V_35 ;
F_47 ( & V_332 -> V_81 , & V_14 -> V_336 ) ;
F_46 ( V_14 , F_13 ( V_42
L_94 , V_14 -> V_43 ,
V_35 ) ) ;
} else
F_161 ( V_14 , V_35 ) ;
}
}
static void
F_181 ( struct V_13 * V_14 ,
T_24 * V_304 )
{
T_10 V_166 ;
if ( V_304 -> V_365 != V_371 )
return;
V_166 = F_78 ( V_304 -> V_372 ) ;
if ( V_166 == V_176 || V_166 ==
V_175 )
F_176 ( V_14 ,
F_21 ( V_304 -> V_368 ) ) ;
}
static void
F_182 ( struct V_13 * V_14 ,
T_25 * V_304 )
{
if ( V_14 -> V_373 >= V_304 -> V_374 ) {
F_25 ( V_42 L_109
L_110 , V_14 -> V_43 ,
( ( F_21 ( V_304 -> V_375 ) & 0x1 ) == 1 ) ? L_111 : L_112 ,
( ( F_21 ( V_304 -> V_375 ) & 0x2 ) == 2 ) ? L_113 : L_112 ,
( ( F_21 ( V_304 -> V_375 ) & 0x4 ) == 4 ) ? L_114 : L_112 ,
( ( F_21 ( V_304 -> V_375 ) & 0x8 ) == 8 ) ? L_115 : L_112 ,
V_304 -> V_374 ) ;
F_25 ( V_42 L_116 ,
V_14 -> V_43 , V_304 -> V_376 ) ;
}
}
static void
F_183 ( struct V_13 * V_14 )
{
struct V_101 * V_104 ;
T_4 V_102 ;
T_4 V_377 = 0 ;
for ( V_102 = 1 ; V_102 <= V_14 -> V_107 ; V_102 ++ ) {
V_104 = F_62 ( V_14 , V_102 ) ;
if ( ! V_104 )
continue;
V_377 ++ ;
F_172 ( V_14 , V_102 ) ;
F_184 ( V_104 ) ;
if ( V_14 -> V_262 )
V_104 -> V_292 = V_293 << 16 ;
else
V_104 -> V_292 = V_295 << 16 ;
V_104 -> V_294 ( V_104 ) ;
}
F_119 ( V_14 , F_13 ( V_42 L_117 ,
V_14 -> V_43 , V_377 ) ) ;
}
static void
F_185 ( struct V_13 * V_14 , struct V_101 * V_104 ,
T_26 * V_253 )
{
T_4 V_378 ;
unsigned char V_379 = F_186 ( V_104 ) ;
unsigned char V_380 = F_187 ( V_104 ) ;
T_27 * V_381 =
( T_27 * ) V_253 ;
if ( V_380 == V_382 || V_379 == V_383 )
return;
if ( V_379 == V_384 )
V_378 = V_385 ;
else if ( V_379 == V_386 )
V_378 = V_387 ;
else
return;
switch ( V_380 ) {
case V_388 :
case V_389 :
V_378 |= V_390 |
V_391 |
V_392 ;
V_253 -> V_393 . V_394 . V_395 =
F_188 ( F_189 ( V_104 ) ) ;
break;
case V_396 :
V_378 |= V_392 ;
break;
}
V_381 -> V_397 =
F_121 ( V_104 -> V_51 -> V_398 ) ;
V_253 -> V_399 = F_121 ( V_378 ) ;
}
static void
F_190 ( struct V_101 * V_104 , T_4 V_38 )
{
T_6 V_400 ;
switch ( V_38 ) {
case V_401 :
V_400 = 0x01 ;
break;
case V_402 :
V_400 = 0x02 ;
break;
case V_403 :
V_400 = 0x03 ;
break;
default:
V_400 = 0x00 ;
break;
}
F_191 ( 0 , V_104 -> V_404 , V_405 , 0x10 ,
V_400 ) ;
V_104 -> V_292 = V_406 << 24 | ( V_407 << 16 ) |
V_408 ;
}
int
F_192 ( struct V_112 * V_113 , struct V_101 * V_104 )
{
struct V_13 * V_14 = F_67 ( V_113 ) ;
struct V_116 * V_117 ;
struct V_72 * V_118 ;
struct V_55 * V_56 ;
T_26 * V_253 ;
T_10 V_409 ;
T_4 V_102 ;
T_4 V_35 ;
if ( V_14 -> V_15 & V_410 )
F_130 ( V_104 ) ;
V_117 = V_104 -> V_51 -> V_120 ;
if ( ! V_117 || ! V_117 -> V_122 ) {
V_104 -> V_292 = V_293 << 16 ;
V_104 -> V_294 ( V_104 ) ;
return 0 ;
}
if ( V_14 -> V_262 || V_14 -> V_261 ) {
V_104 -> V_292 = V_293 << 16 ;
V_104 -> V_294 ( V_104 ) ;
return 0 ;
}
V_118 = V_117 -> V_122 ;
V_35 = V_118 -> V_35 ;
if ( V_35 == V_132 ) {
V_104 -> V_292 = V_293 << 16 ;
V_104 -> V_294 ( V_104 ) ;
return 0 ;
}
if ( V_14 -> V_82 || V_14 -> V_411 )
return V_412 ;
else if ( V_118 -> V_334 ) {
V_104 -> V_292 = V_293 << 16 ;
V_104 -> V_294 ( V_104 ) ;
return 0 ;
} else if ( V_118 -> V_247 ||
V_117 -> V_310 )
return V_413 ;
if ( V_104 -> V_414 == V_415 )
V_409 = V_416 ;
else if ( V_104 -> V_414 == V_417 )
V_409 = V_418 ;
else
V_409 = V_419 ;
V_409 |= V_420 ;
if ( ! V_14 -> V_134 && ! F_79 ( & V_104 -> V_51 -> V_190 )
&& F_96 ( V_104 -> V_51 ) && V_104 -> V_421 != 32 )
V_409 |= V_422 ;
V_102 = F_193 ( V_14 , V_14 -> V_423 , V_104 ) ;
if ( ! V_102 ) {
F_25 ( V_42 L_49 ,
V_14 -> V_43 , V_44 ) ;
goto V_89;
}
V_253 = F_120 ( V_14 , V_102 ) ;
memset ( V_253 , 0 , sizeof( T_26 ) ) ;
F_185 ( V_14 , V_104 , V_253 ) ;
if ( V_104 -> V_421 == 32 )
V_409 |= 4 << V_424 ;
V_253 -> V_272 = V_425 ;
if ( V_117 -> V_122 -> V_76 &
V_138 )
V_253 -> V_272 = V_426 ;
else
V_253 -> V_272 = V_425 ;
V_253 -> V_199 = F_121 ( V_35 ) ;
V_253 -> V_427 = F_194 ( F_195 ( V_104 ) ) ;
V_253 -> V_428 = F_194 ( V_409 ) ;
V_253 -> V_429 = F_121 ( V_104 -> V_421 ) ;
V_253 -> V_430 = V_431 ;
V_253 -> V_432 = V_433 ;
V_253 -> V_434 =
F_196 ( V_14 , V_102 ) ;
V_253 -> V_435 = F_92 ( T_26 , V_436 ) / 4 ;
F_122 ( V_117 -> V_109 , (struct V_276 * )
V_253 -> V_277 ) ;
memcpy ( V_253 -> V_393 . V_437 , V_104 -> V_438 , V_104 -> V_421 ) ;
if ( V_253 -> V_427 ) {
if ( V_14 -> V_439 ( V_14 , V_104 , V_102 ) ) {
F_172 ( V_14 , V_102 ) ;
goto V_89;
}
} else
V_14 -> V_440 ( V_14 , & V_253 -> V_436 ) ;
V_56 = V_118 -> V_56 ;
if ( V_56 && V_56 -> V_441 )
F_197 ( V_14 , V_104 , V_56 , V_253 ,
V_102 ) ;
if ( F_168 ( V_253 -> V_272 == V_425 ) ) {
if ( V_118 -> V_76 & V_140 ) {
V_253 -> V_429 = F_121 ( V_104 -> V_421 |
V_442 ) ;
F_198 ( V_14 , V_102 , V_35 ) ;
} else
F_199 ( V_14 , V_102 ,
F_21 ( V_253 -> V_199 ) ) ;
} else
F_165 ( V_14 , V_102 ) ;
return 0 ;
V_89:
return V_412 ;
}
static void
F_200 ( char * V_404 , struct V_443 * V_444 )
{
if ( ( V_404 [ 0 ] & 0x7F ) >= 0x72 ) {
V_444 -> V_445 = V_404 [ 1 ] & 0x0F ;
V_444 -> V_446 = V_404 [ 2 ] ;
V_444 -> V_400 = V_404 [ 3 ] ;
} else {
V_444 -> V_445 = V_404 [ 2 ] & 0x0F ;
V_444 -> V_446 = V_404 [ 12 ] ;
V_444 -> V_400 = V_404 [ 13 ] ;
}
}
static void
F_201 ( struct V_13 * V_14 , struct V_101 * V_104 ,
T_28 * V_37 , T_4 V_102 )
{
T_10 V_447 ;
T_6 * V_448 ;
T_4 V_38 = F_21 ( V_37 -> V_46 ) &
V_47 ;
T_6 V_449 = V_37 -> V_450 ;
T_6 V_451 = V_37 -> V_452 ;
char * V_453 = NULL ;
char * V_454 = NULL ;
char * V_455 = V_14 -> V_456 ;
T_10 V_457 = F_78 ( V_37 -> V_281 ) ;
struct V_53 * V_54 = NULL ;
struct V_126 * V_85 = V_104 -> V_51 -> V_289 ;
struct V_72 * V_290 = V_85 -> V_120 ;
char * V_291 = NULL ;
if ( ! V_290 )
return;
if ( V_14 -> V_217 )
V_291 = L_54 ;
else
V_291 = L_55 ;
if ( V_457 == 0x31170000 )
return;
switch ( V_38 ) {
case V_48 :
V_453 = L_118 ;
break;
case V_458 :
V_453 = L_119 ;
break;
case V_459 :
V_453 = L_120 ;
break;
case V_460 :
V_453 = L_121 ;
break;
case V_461 :
V_453 = L_122 ;
break;
case V_462 :
V_453 = L_123 ;
break;
case V_463 :
V_453 = L_124 ;
break;
case V_464 :
V_453 = L_125 ;
break;
case V_465 :
V_453 = L_126 ;
break;
case V_466 :
V_453 = L_127 ;
break;
case V_467 :
V_453 = L_128 ;
break;
case V_468 :
V_453 = L_129 ;
break;
case V_469 :
V_453 = L_130 ;
break;
case V_470 :
V_453 = L_131 ;
break;
case V_401 :
V_453 = L_132 ;
break;
case V_403 :
V_453 = L_133 ;
break;
case V_402 :
V_453 = L_134 ;
break;
default:
V_453 = L_44 ;
break;
}
switch ( V_451 ) {
case V_471 :
V_454 = L_135 ;
break;
case V_472 :
V_454 = L_136 ;
break;
case V_473 :
V_454 = L_137 ;
break;
case V_474 :
V_454 = L_138 ;
break;
case V_475 :
V_454 = L_139 ;
break;
case V_476 :
V_454 = L_140 ;
break;
case V_477 :
V_454 = L_141 ;
break;
case V_478 :
V_454 = L_142 ;
break;
case V_479 :
V_454 = L_143 ;
break;
case V_480 :
V_454 = L_144 ;
break;
case V_481 :
V_454 = L_145 ;
break;
default:
V_454 = L_44 ;
break;
}
V_455 [ 0 ] = '\0' ;
if ( ! V_449 )
V_455 = L_112 ;
if ( V_449 & V_482 )
strcat ( V_455 , L_146 ) ;
if ( V_449 & V_483 )
strcat ( V_455 , L_147 ) ;
if ( V_449 & V_484 )
strcat ( V_455 , L_148 ) ;
if ( V_449 & V_485 )
strcat ( V_455 , L_149 ) ;
if ( V_449 & V_486 )
strcat ( V_455 , L_150 ) ;
F_130 ( V_104 ) ;
if ( V_290 -> V_76 & V_123 ) {
F_91 ( V_42 L_151 , V_14 -> V_43 ,
V_291 , ( unsigned long long ) V_290 -> V_17 ) ;
} else {
V_54 = F_31 ( V_14 , V_290 ) ;
if ( V_54 ) {
F_91 ( V_42
L_152 ,
V_14 -> V_43 , ( unsigned long long )
V_54 -> V_17 , V_54 -> V_218 ) ;
if ( V_54 -> V_78 != 0 )
F_91 ( V_42
L_153
L_154 , V_14 -> V_43 ,
( unsigned long long )
V_54 -> V_22 ,
V_54 -> V_26 ) ;
if ( V_54 -> V_79 [ 0 ] )
F_91 ( V_42
L_155
L_93 , V_14 -> V_43 ,
V_54 -> V_80 ,
V_54 -> V_79 ) ;
F_41 ( V_54 ) ;
}
}
F_91 ( V_42
L_156 ,
V_14 -> V_43 , F_21 ( V_37 -> V_199 ) ,
V_453 , V_38 , V_102 ) ;
F_91 ( V_42
L_157 ,
V_14 -> V_43 , F_195 ( V_104 ) , V_104 -> V_487 ,
F_202 ( V_104 ) ) ;
F_91 ( V_42
L_158 ,
V_14 -> V_43 , F_21 ( V_37 -> V_488 ) ,
F_78 ( V_37 -> V_489 ) , V_104 -> V_292 ) ;
F_91 ( V_42
L_159 ,
V_14 -> V_43 , V_454 ,
V_451 , V_455 , V_449 ) ;
if ( V_449 & V_486 ) {
struct V_443 V_444 ;
F_200 ( V_104 -> V_404 , & V_444 ) ;
F_91 ( V_42
L_160 ,
V_14 -> V_43 , V_444 . V_445 ,
V_444 . V_446 , V_444 . V_400 , F_78 ( V_37 -> V_490 ) ) ;
}
if ( V_449 & V_482 ) {
V_447 = F_78 ( V_37 -> V_491 ) ;
V_448 = ( T_6 * ) & V_447 ;
F_104 ( V_14 , V_448 [ 0 ] ) ;
}
}
static void
F_203 ( struct V_13 * V_14 , T_4 V_35 )
{
T_29 V_37 ;
T_30 V_253 ;
struct V_53 * V_54 ;
V_54 = F_37 ( V_14 , V_35 ) ;
if ( ! V_54 )
return;
memset ( & V_253 , 0 , sizeof( T_30 ) ) ;
V_253 . V_272 = V_492 ;
V_253 . V_493 = V_494 ;
V_253 . V_495 =
F_194 ( V_496 ) ;
V_253 . V_199 = F_121 ( V_35 ) ;
V_253 . V_145 = V_497 ;
if ( ( F_204 ( V_14 , & V_37 ,
& V_253 ) ) != 0 ) {
F_25 ( V_42 L_2 , V_14 -> V_43 ,
__FILE__ , __LINE__ , V_44 ) ;
goto V_89;
}
V_54 -> V_498 = 1 ;
if ( V_37 . V_46 || V_37 . V_281 ) {
F_46 ( V_14 , F_13 ( V_42
L_161 ,
V_14 -> V_43 , F_21 ( V_37 . V_46 ) ,
F_78 ( V_37 . V_281 ) ) ) ;
goto V_89;
}
V_89:
F_41 ( V_54 ) ;
}
static void
F_205 ( struct V_13 * V_14 ,
struct V_53 * V_54 )
{
T_29 V_37 ;
T_30 V_253 ;
memset ( & V_253 , 0 , sizeof( T_30 ) ) ;
V_253 . V_272 = V_492 ;
V_253 . V_493 = V_494 ;
V_253 . V_495 = 0 ;
V_253 . V_499 = F_121 ( V_54 -> V_26 ) ;
V_253 . V_199 = 0 ;
V_253 . V_500 = F_121 ( V_54 -> V_78 ) ;
V_253 . V_145 = V_501 ;
if ( ( F_204 ( V_14 , & V_37 ,
& V_253 ) ) != 0 ) {
F_206 ( V_42 L_2 , V_14 -> V_43 ,
__FILE__ , __LINE__ , V_44 ) ;
return;
}
if ( V_37 . V_46 || V_37 . V_281 ) {
F_46 ( V_14 , F_206 ( V_42
L_161 ,
V_14 -> V_43 , F_21 ( V_37 . V_46 ) ,
F_78 ( V_37 . V_281 ) ) ) ;
return;
}
}
static void
F_207 ( struct V_13 * V_14 , T_4 V_35 )
{
struct V_3 * V_7 ;
V_7 = F_8 ( 0 ) ;
if ( ! V_7 )
return;
V_7 -> V_305 = V_502 ;
V_7 -> V_503 = V_35 ;
V_7 -> V_14 = V_14 ;
F_137 ( V_14 , V_7 ) ;
F_6 ( V_7 ) ;
}
static void
F_208 ( struct V_13 * V_14 , T_4 V_35 )
{
struct V_126 * V_85 ;
struct V_72 * V_118 ;
T_31 * V_504 ;
T_32 * V_304 ;
struct V_53 * V_54 ;
T_33 V_192 ;
unsigned long V_76 ;
F_32 ( & V_14 -> V_74 , V_76 ) ;
V_54 = F_36 ( V_14 , V_35 ) ;
if ( ! V_54 )
goto V_505;
V_85 = V_54 -> V_85 ;
V_118 = V_85 -> V_120 ;
if ( ( V_118 -> V_76 & V_138 ) ||
( ( V_118 -> V_76 & V_123 ) ) )
goto V_505;
if ( V_54 -> V_78 != 0 )
F_131 ( V_144 , V_85 , L_162
L_163 ,
( unsigned long long ) V_54 -> V_22 ,
V_54 -> V_26 ) ;
if ( V_54 -> V_79 [ 0 ] != '\0' )
F_131 ( V_312 , V_85 , L_162
L_164 ,
V_54 -> V_80 ,
V_54 -> V_79 ) ;
F_33 ( & V_14 -> V_74 , V_76 ) ;
if ( V_14 -> V_506 -> V_507 == V_508 )
F_207 ( V_14 , V_35 ) ;
V_192 = F_92 ( T_31 , V_509 ) +
sizeof( T_32 ) ;
V_504 = F_9 ( V_192 , V_130 ) ;
if ( ! V_504 ) {
F_25 ( V_42 L_2 ,
V_14 -> V_43 , __FILE__ , __LINE__ , V_44 ) ;
goto V_89;
}
V_504 -> V_272 = V_510 ;
V_504 -> V_511 =
F_121 ( V_512 ) ;
V_504 -> V_242 = V_192 / 4 ;
V_504 -> V_513 =
F_121 ( sizeof( T_32 ) / 4 ) ;
V_304 = ( T_32 * )
V_504 -> V_509 ;
V_304 -> V_365 = V_514 ;
V_304 -> V_515 = 0x5D ;
V_304 -> V_199 = F_121 ( V_35 ) ;
V_304 -> V_19 = F_209 ( V_118 -> V_17 ) ;
F_210 ( V_14 , V_504 ) ;
F_2 ( V_504 ) ;
V_89:
if ( V_54 )
F_41 ( V_54 ) ;
return;
V_505:
F_33 ( & V_14 -> V_74 , V_76 ) ;
goto V_89;
}
static T_6
F_211 ( struct V_13 * V_14 , T_4 V_102 , T_6 V_236 , T_10 V_237 )
{
T_26 * V_253 ;
T_28 * V_37 ;
struct V_101 * V_104 ;
T_4 V_38 ;
T_10 V_516 ;
T_6 V_449 ;
T_6 V_451 ;
T_10 V_457 ;
struct V_116 * V_117 ;
T_10 V_227 = 0 ;
unsigned long V_76 ;
V_37 = F_107 ( V_14 , V_237 ) ;
V_104 = F_62 ( V_14 , V_102 ) ;
if ( V_104 == NULL )
return 1 ;
V_253 = F_120 ( V_14 , V_102 ) ;
if ( V_37 == NULL ) {
V_104 -> V_292 = V_517 << 16 ;
goto V_89;
}
V_117 = V_104 -> V_51 -> V_120 ;
if ( ! V_117 || ! V_117 -> V_122 ||
V_117 -> V_122 -> V_334 ) {
V_104 -> V_292 = V_293 << 16 ;
goto V_89;
}
V_38 = F_21 ( V_37 -> V_46 ) ;
if ( F_212 ( V_14 , V_102 ) &&
( ( V_38 & V_47 )
!= V_466 ) ) {
F_32 ( & V_14 -> V_105 , V_76 ) ;
V_14 -> V_103 [ V_102 - 1 ] . V_104 = V_104 ;
F_33 ( & V_14 -> V_105 , V_76 ) ;
F_213 ( V_14 , V_102 , 0 ) ;
memcpy ( V_253 -> V_393 . V_437 , V_104 -> V_438 , V_104 -> V_421 ) ;
V_253 -> V_199 =
F_121 ( V_117 -> V_122 -> V_35 ) ;
F_199 ( V_14 , V_102 ,
V_117 -> V_122 -> V_35 ) ;
return 0 ;
}
V_449 = V_37 -> V_450 ;
if ( V_449 & V_482 )
V_227 =
F_78 ( V_37 -> V_491 ) & 0xFF ;
if ( ! V_117 -> V_518 ) {
V_117 -> V_518 ++ ;
if ( ! V_14 -> V_134 &&
! F_79 ( & V_104 -> V_51 -> V_190 ) &&
F_96 ( V_104 -> V_51 ) &&
V_227 == V_230 ) {
F_214 ( V_104 -> V_51 ) ;
F_75 ( V_144 , V_104 -> V_51 , L_165 ) ;
}
}
V_516 = F_78 ( V_37 -> V_489 ) ;
F_215 ( V_104 , F_195 ( V_104 ) - V_516 ) ;
if ( V_38 & V_519 )
V_457 = F_78 ( V_37 -> V_281 ) ;
else
V_457 = 0 ;
V_38 &= V_47 ;
V_451 = V_37 -> V_452 ;
if ( V_38 == V_463 && V_516 == 0 &&
( V_451 == V_474 ||
V_451 == V_477 ||
V_451 == V_479 ) ) {
V_38 = V_48 ;
}
if ( V_449 & V_486 ) {
struct V_443 V_444 ;
const void * V_520 = F_216 ( V_14 ,
V_102 ) ;
T_10 V_192 = F_217 ( T_10 , V_433 ,
F_78 ( V_37 -> V_490 ) ) ;
memcpy ( V_104 -> V_404 , V_520 , V_192 ) ;
F_200 ( V_104 -> V_404 , & V_444 ) ;
if ( V_444 . V_446 == 0x5D )
F_208 ( V_14 ,
F_21 ( V_37 -> V_199 ) ) ;
F_218 ( V_14 , V_444 . V_445 , V_444 . V_446 , V_444 . V_400 ) ;
if ( ! ( V_14 -> V_15 & V_521 ) &&
( ( V_104 -> V_404 [ 2 ] == V_522 ) ||
( V_104 -> V_404 [ 2 ] == V_523 ) ||
( V_104 -> V_404 [ 2 ] == V_524 ) ) )
F_201 ( V_14 , V_104 , V_37 , V_102 ) ;
}
switch ( V_38 ) {
case V_525 :
case V_526 :
V_104 -> V_292 = V_527 ;
break;
case V_461 :
V_104 -> V_292 = V_293 << 16 ;
break;
case V_469 :
if ( V_117 -> V_310 ) {
V_104 -> V_292 = V_528 << 16 ;
goto V_89;
}
if ( V_457 == 0x31110630 ) {
if ( V_104 -> V_529 > 2 ) {
V_104 -> V_292 = V_293 << 16 ;
F_219 ( V_104 -> V_51 ,
V_530 ) ;
} else {
V_104 -> V_292 = V_531 << 16 ;
V_104 -> V_51 -> V_532 = 1 ;
}
break;
} else if ( V_457 == V_533 ) {
V_104 -> V_292 = V_295 << 16 ;
break;
}
V_104 -> V_292 = V_531 << 16 ;
break;
case V_466 :
case V_470 :
V_104 -> V_292 = V_295 << 16 ;
break;
case V_467 :
if ( ( V_516 == 0 ) || ( V_104 -> V_487 > V_516 ) )
V_104 -> V_292 = V_531 << 16 ;
else
V_104 -> V_292 = ( V_517 << 16 ) | V_451 ;
break;
case V_463 :
V_104 -> V_292 = ( V_517 << 16 ) | V_451 ;
if ( ( V_449 & V_486 ) )
break;
if ( V_516 < V_104 -> V_487 ) {
if ( V_451 == V_527 )
V_104 -> V_292 = V_527 ;
else
V_104 -> V_292 = V_531 << 16 ;
} else if ( V_449 & ( V_485 |
V_484 ) )
V_104 -> V_292 = V_531 << 16 ;
else if ( V_449 & V_483 )
V_104 -> V_292 = V_295 << 16 ;
else if ( ! V_516 && V_104 -> V_438 [ 0 ] == V_534 ) {
V_37 -> V_450 = V_486 ;
V_37 -> V_452 = V_408 ;
V_104 -> V_292 = ( V_406 << 24 ) |
V_408 ;
V_104 -> V_404 [ 0 ] = 0x70 ;
V_104 -> V_404 [ 2 ] = V_405 ;
V_104 -> V_404 [ 12 ] = 0x20 ;
V_104 -> V_404 [ 13 ] = 0 ;
}
break;
case V_462 :
F_215 ( V_104 , 0 ) ;
case V_459 :
case V_48 :
V_104 -> V_292 = ( V_517 << 16 ) | V_451 ;
if ( V_227 ==
V_230 ||
( V_449 & ( V_485 |
V_484 ) ) )
V_104 -> V_292 = V_531 << 16 ;
else if ( V_449 & V_483 )
V_104 -> V_292 = V_295 << 16 ;
break;
case V_401 :
case V_403 :
case V_402 :
F_190 ( V_104 , V_38 ) ;
break;
case V_465 :
case V_458 :
case V_535 :
case V_536 :
case V_537 :
case V_538 :
case V_464 :
case V_468 :
default:
V_104 -> V_292 = V_531 << 16 ;
break;
}
if ( V_104 -> V_292 && ( V_14 -> V_15 & V_521 ) )
F_201 ( V_14 , V_104 , V_37 , V_102 ) ;
V_89:
F_184 ( V_104 ) ;
V_104 -> V_294 ( V_104 ) ;
return 1 ;
}
static void
F_220 ( struct V_13 * V_14 )
{
T_4 V_192 ;
T_4 V_38 ;
int V_106 ;
T_9 V_37 ;
T_34 * V_539 = NULL ;
T_4 V_540 ;
T_6 V_541 ;
F_119 ( V_14 , F_13 ( V_42
L_166 ,
V_14 -> V_43 , ( unsigned long long ) V_14 -> V_39 . V_17 ) ) ;
V_192 = F_92 ( T_34 , V_542 ) + ( V_14 -> V_39 . V_40
* sizeof( V_543 ) ) ;
V_539 = F_9 ( V_192 , V_130 ) ;
if ( ! V_539 ) {
F_25 ( V_42 L_2 ,
V_14 -> V_43 , __FILE__ , __LINE__ , V_44 ) ;
return;
}
if ( ( F_221 ( V_14 , & V_37 ,
V_539 , V_192 ) ) != 0 )
goto V_89;
V_38 = F_21 ( V_37 . V_46 ) & V_47 ;
if ( V_38 != V_48 )
goto V_89;
for ( V_106 = 0 ; V_106 < V_14 -> V_39 . V_40 ; V_106 ++ ) {
V_541 = V_539 -> V_542 [ V_106 ] . V_544 >> 4 ;
if ( V_106 == 0 )
V_14 -> V_39 . V_35 = F_21 ( V_539 ->
V_542 [ 0 ] . V_545 ) ;
V_14 -> V_39 . V_218 [ V_106 ] . V_35 = V_14 -> V_39 . V_35 ;
V_540 = F_21 ( V_539 -> V_542 [ V_106 ] .
V_327 ) ;
if ( V_540 && V_541 < V_546 )
V_541 = V_546 ;
F_222 ( V_14 , V_14 -> V_39 . V_17 ,
V_540 , V_106 , V_541 ) ;
}
V_89:
F_2 ( V_539 ) ;
}
static void
F_223 ( struct V_13 * V_14 )
{
int V_106 ;
T_9 V_37 ;
T_34 * V_539 = NULL ;
T_35 * V_547 = NULL ;
T_36 V_548 ;
T_8 V_36 ;
T_37 V_549 ;
T_4 V_38 ;
T_4 V_192 ;
T_6 V_550 ;
F_224 ( V_14 , & V_14 -> V_39 . V_40 ) ;
if ( ! V_14 -> V_39 . V_40 ) {
F_25 ( V_42 L_2 ,
V_14 -> V_43 , __FILE__ , __LINE__ , V_44 ) ;
return;
}
V_192 = F_92 ( T_34 , V_542 ) + ( V_14 -> V_39 . V_40 *
sizeof( V_543 ) ) ;
V_539 = F_9 ( V_192 , V_130 ) ;
if ( ! V_539 ) {
F_25 ( V_42 L_2 ,
V_14 -> V_43 , __FILE__ , __LINE__ , V_44 ) ;
return;
}
if ( ( F_221 ( V_14 , & V_37 ,
V_539 , V_192 ) ) ) {
F_25 ( V_42 L_2 ,
V_14 -> V_43 , __FILE__ , __LINE__ , V_44 ) ;
goto V_89;
}
V_38 = F_21 ( V_37 . V_46 ) &
V_47 ;
if ( V_38 != V_48 ) {
F_25 ( V_42 L_2 ,
V_14 -> V_43 , __FILE__ , __LINE__ , V_44 ) ;
goto V_89;
}
V_192 = F_92 ( T_35 , V_542 ) + ( V_14 -> V_39 . V_40 *
sizeof( V_551 ) ) ;
V_547 = F_9 ( V_192 , V_130 ) ;
if ( ! V_547 ) {
F_25 ( V_42 L_2 ,
V_14 -> V_43 , __FILE__ , __LINE__ , V_44 ) ;
goto V_89;
}
if ( ( F_225 ( V_14 , & V_37 ,
V_547 , V_192 ) ) ) {
F_25 ( V_42 L_2 ,
V_14 -> V_43 , __FILE__ , __LINE__ , V_44 ) ;
goto V_89;
}
V_38 = F_21 ( V_37 . V_46 ) &
V_47 ;
if ( V_38 != V_48 ) {
F_25 ( V_42 L_2 ,
V_14 -> V_43 , __FILE__ , __LINE__ , V_44 ) ;
goto V_89;
}
V_14 -> V_552 =
V_547 -> V_553 ;
V_550 =
V_547 -> V_554 ;
if ( V_550 & V_555 )
V_14 -> V_550 = ( V_550 &
V_556 ) * 16 ;
else
V_14 -> V_550 = V_550 &
V_556 ;
V_14 -> V_39 . V_557 = & V_14 -> V_113 -> V_558 ;
V_14 -> V_39 . V_218 = F_226 ( V_14 -> V_39 . V_40 ,
sizeof( struct V_559 ) , V_130 ) ;
if ( ! V_14 -> V_39 . V_218 ) {
F_25 ( V_42 L_2 ,
V_14 -> V_43 , __FILE__ , __LINE__ , V_44 ) ;
goto V_89;
}
for ( V_106 = 0 ; V_106 < V_14 -> V_39 . V_40 ; V_106 ++ ) {
if ( ( F_227 ( V_14 , & V_37 , & V_548 ,
V_106 ) ) ) {
F_25 ( V_42 L_2 ,
V_14 -> V_43 , __FILE__ , __LINE__ , V_44 ) ;
goto V_89;
}
V_38 = F_21 ( V_37 . V_46 ) &
V_47 ;
if ( V_38 != V_48 ) {
F_25 ( V_42 L_2 ,
V_14 -> V_43 , __FILE__ , __LINE__ , V_44 ) ;
goto V_89;
}
if ( V_106 == 0 )
V_14 -> V_39 . V_35 = F_21 ( V_539 ->
V_542 [ 0 ] . V_545 ) ;
V_14 -> V_39 . V_218 [ V_106 ] . V_35 = V_14 -> V_39 . V_35 ;
V_14 -> V_39 . V_218 [ V_106 ] . V_560 = V_106 ;
F_228 ( V_14 , & V_14 -> V_39 . V_218 [ V_106 ] ,
V_548 , V_14 -> V_39 . V_557 ) ;
}
if ( ( F_24 ( V_14 , & V_37 , & V_36 ,
V_41 , V_14 -> V_39 . V_35 ) ) ) {
F_25 ( V_42 L_2 ,
V_14 -> V_43 , __FILE__ , __LINE__ , V_44 ) ;
goto V_89;
}
V_14 -> V_39 . V_78 =
F_21 ( V_36 . V_500 ) ;
V_14 -> V_39 . V_17 = F_18 ( V_36 . V_19 ) ;
F_13 ( V_42
L_167 ,
V_14 -> V_43 , V_14 -> V_39 . V_35 ,
( unsigned long long ) V_14 -> V_39 . V_17 ,
V_14 -> V_39 . V_40 ) ;
if ( V_14 -> V_39 . V_78 ) {
if ( ! ( F_229 ( V_14 , & V_37 ,
& V_549 , V_561 ,
V_14 -> V_39 . V_78 ) ) )
V_14 -> V_39 . V_22 =
F_18 ( V_549 . V_24 ) ;
}
V_89:
F_2 ( V_547 ) ;
F_2 ( V_539 ) ;
}
static int
F_230 ( struct V_13 * V_14 , T_4 V_35 )
{
struct V_92 * V_93 ;
T_9 V_37 ;
T_38 V_562 ;
T_39 V_563 ;
T_37 V_549 ;
T_10 V_38 ;
T_4 V_564 ;
T_1 V_17 , V_84 = 0 ;
int V_106 ;
unsigned long V_76 ;
struct V_315 * V_316 = NULL ;
int V_28 = 0 ;
if ( ! V_35 )
return - 1 ;
if ( V_14 -> V_82 || V_14 -> V_262 )
return - 1 ;
if ( ( F_231 ( V_14 , & V_37 , & V_562 ,
V_565 , V_35 ) ) ) {
F_25 ( V_42 L_2 ,
V_14 -> V_43 , __FILE__ , __LINE__ , V_44 ) ;
return - 1 ;
}
V_38 = F_21 ( V_37 . V_46 ) &
V_47 ;
if ( V_38 != V_48 ) {
F_25 ( V_42 L_2 ,
V_14 -> V_43 , __FILE__ , __LINE__ , V_44 ) ;
return - 1 ;
}
V_564 = F_21 ( V_562 . V_566 ) ;
if ( F_23 ( V_14 , V_564 , & V_84 )
!= 0 ) {
F_25 ( V_42 L_2 ,
V_14 -> V_43 , __FILE__ , __LINE__ , V_44 ) ;
return - 1 ;
}
if ( V_84 != V_14 -> V_39 . V_17 ) {
F_32 ( & V_14 -> V_94 , V_76 ) ;
V_93 = F_58 ( V_14 ,
V_84 ) ;
F_33 ( & V_14 -> V_94 , V_76 ) ;
if ( ! V_93 ) {
V_28 = F_230 ( V_14 , V_564 ) ;
if ( V_28 != 0 )
return V_28 ;
}
}
F_32 ( & V_14 -> V_94 , V_76 ) ;
V_17 = F_18 ( V_562 . V_19 ) ;
V_93 = F_58 ( V_14 ,
V_17 ) ;
F_33 ( & V_14 -> V_94 , V_76 ) ;
if ( V_93 )
return 0 ;
V_93 = F_9 ( sizeof( struct V_92 ) ,
V_130 ) ;
if ( ! V_93 ) {
F_25 ( V_42 L_2 ,
V_14 -> V_43 , __FILE__ , __LINE__ , V_44 ) ;
return - 1 ;
}
V_93 -> V_35 = V_35 ;
V_93 -> V_40 = V_562 . V_567 ;
V_93 -> V_84 = V_84 ;
V_93 -> V_17 = V_17 ;
F_13 ( V_42 L_168 \
L_169 , V_14 -> V_43 ,
V_35 , V_564 , ( unsigned long long )
V_93 -> V_17 , V_93 -> V_40 ) ;
if ( ! V_93 -> V_40 )
goto V_568;
V_93 -> V_218 = F_226 ( V_93 -> V_40 ,
sizeof( struct V_559 ) , V_130 ) ;
if ( ! V_93 -> V_218 ) {
F_25 ( V_42 L_2 ,
V_14 -> V_43 , __FILE__ , __LINE__ , V_44 ) ;
V_28 = - 1 ;
goto V_568;
}
F_138 ( & V_93 -> V_569 ) ;
V_316 = F_48 ( V_14 , V_35 ,
V_84 ) ;
if ( ! V_316 ) {
F_25 ( V_42 L_2 ,
V_14 -> V_43 , __FILE__ , __LINE__ , V_44 ) ;
V_28 = - 1 ;
goto V_568;
}
V_93 -> V_557 = & V_316 -> V_129 -> V_127 ;
for ( V_106 = 0 ; V_106 < V_93 -> V_40 ; V_106 ++ ) {
if ( ( F_232 ( V_14 , & V_37 ,
& V_563 , V_106 , V_35 ) ) ) {
F_25 ( V_42 L_2 ,
V_14 -> V_43 , __FILE__ , __LINE__ , V_44 ) ;
V_28 = - 1 ;
goto V_568;
}
V_93 -> V_218 [ V_106 ] . V_35 = V_35 ;
V_93 -> V_218 [ V_106 ] . V_560 = V_106 ;
if ( ( F_233 ( V_14 ,
& V_93 -> V_218 [ V_106 ] , V_563 ,
V_93 -> V_557 ) ) ) {
F_25 ( V_42 L_2 ,
V_14 -> V_43 , __FILE__ , __LINE__ , V_44 ) ;
V_28 = - 1 ;
goto V_568;
}
}
if ( V_93 -> V_78 ) {
if ( ! ( F_229 ( V_14 , & V_37 ,
& V_549 , V_561 ,
V_93 -> V_78 ) ) )
V_93 -> V_22 =
F_18 ( V_549 . V_24 ) ;
}
F_59 ( V_14 , V_93 ) ;
return 0 ;
V_568:
if ( V_316 )
F_49 ( V_14 , V_93 -> V_17 ,
V_84 ) ;
F_2 ( V_93 ) ;
return V_28 ;
}
void
F_234 ( struct V_13 * V_14 , T_1 V_17 )
{
struct V_92 * V_93 ;
unsigned long V_76 ;
if ( V_14 -> V_82 )
return;
F_32 ( & V_14 -> V_94 , V_76 ) ;
V_93 = F_58 ( V_14 ,
V_17 ) ;
if ( V_93 )
F_56 ( & V_93 -> V_81 ) ;
F_33 ( & V_14 -> V_94 , V_76 ) ;
if ( V_93 )
F_235 ( V_14 , V_93 ) ;
}
static T_6
F_236 ( struct V_13 * V_14 , T_4 V_102 , T_6 V_236 , T_10 V_237 )
{
T_15 * V_37 ;
V_37 = F_107 ( V_14 , V_237 ) ;
if ( V_14 -> V_570 . V_239 == V_240 )
return 1 ;
if ( V_14 -> V_570 . V_102 != V_102 )
return 1 ;
V_14 -> V_570 . V_239 |= V_241 ;
if ( V_37 ) {
memcpy ( V_14 -> V_570 . V_237 , V_37 ,
V_37 -> V_242 * 4 ) ;
V_14 -> V_570 . V_239 |= V_243 ;
}
V_14 -> V_570 . V_239 &= ~ V_244 ;
F_108 ( & V_14 -> V_570 . V_245 ) ;
return 1 ;
}
static T_6
F_237 ( struct V_13 * V_14 , T_1 V_17 ,
T_4 V_35 , T_6 V_571 )
{
T_6 V_28 = 1 ;
char * V_228 = NULL ;
switch ( V_571 ) {
case V_572 :
case V_573 :
V_28 = 0 ;
break;
case V_574 :
V_228 = L_170 ;
break;
case V_575 :
V_228 = L_171 ;
break;
case V_576 :
V_228 = L_172 ;
break;
case V_577 :
V_228 = L_173 ;
break;
case V_578 :
V_228 = L_174 ;
break;
case V_579 :
case V_580 :
case V_581 :
case V_582 :
case V_583 :
case V_584 :
case V_585 :
case V_586 :
case V_587 :
case V_588 :
case V_589 :
case V_590 :
V_228 = L_175 ;
break;
default:
V_228 = L_44 ;
break;
}
if ( ! V_28 )
return 0 ;
F_25 ( V_42
L_176 ,
V_14 -> V_43 , V_228 , ( unsigned long long ) V_17 , V_35 ) ;
return V_28 ;
}
static void
F_238 ( struct V_13 * V_14 ,
T_1 V_591 , T_4 V_35 , T_6 V_592 , T_6 V_541 )
{
T_9 V_37 ;
T_8 V_36 ;
struct V_53 * V_54 ;
T_10 V_38 ;
unsigned long V_76 ;
T_1 V_17 ;
struct V_126 * V_85 ;
struct V_72 * V_118 ;
T_10 V_96 ;
if ( ( F_24 ( V_14 , & V_37 , & V_36 ,
V_41 , V_35 ) ) )
return;
V_38 = F_21 ( V_37 . V_46 ) & V_47 ;
if ( V_38 != V_48 )
return;
if ( V_592 != V_36 . V_593 )
return;
V_96 = F_78 ( V_36 . V_146 ) ;
if ( ! ( F_60 ( V_96 ) ) )
return;
F_32 ( & V_14 -> V_74 , V_76 ) ;
V_17 = F_18 ( V_36 . V_19 ) ;
V_54 = F_34 ( V_14 ,
V_17 ) ;
if ( ! V_54 )
goto V_505;
if ( F_163 ( V_54 -> V_35 != V_35 ) ) {
V_85 = V_54 -> V_85 ;
V_118 = V_85 -> V_120 ;
F_131 ( V_144 , V_85 ,
L_177 ,
V_54 -> V_35 , V_35 ) ;
V_118 -> V_35 = V_35 ;
V_54 -> V_35 = V_35 ;
if ( V_36 . V_145 &
V_594 ) {
V_54 -> V_80 =
F_21 ( V_36 . V_595 ) ;
memcpy ( & V_54 -> V_79 [ 0 ] ,
& V_36 . V_596 [ 0 ] , 4 ) ;
} else {
V_54 -> V_80 = 0 ;
V_54 -> V_79 [ 0 ] = '\0' ;
}
}
if ( ! ( F_21 ( V_36 . V_145 ) &
V_597 ) ) {
F_25 ( V_42
L_178 ,
V_14 -> V_43 , V_35 ) ;
goto V_505;
}
if ( F_237 ( V_14 , V_17 , V_35 ,
V_36 . V_598 ) )
goto V_505;
F_33 ( & V_14 -> V_74 , V_76 ) ;
F_155 ( V_14 , V_17 ) ;
if ( V_54 )
F_41 ( V_54 ) ;
return;
V_505:
F_33 ( & V_14 -> V_74 , V_76 ) ;
if ( V_54 )
F_41 ( V_54 ) ;
}
static int
F_239 ( struct V_13 * V_14 , T_4 V_35 , T_6 V_599 ,
T_6 V_600 )
{
T_9 V_37 ;
T_8 V_36 ;
T_37 V_549 ;
struct V_53 * V_54 ;
T_10 V_38 ;
T_1 V_17 ;
T_10 V_96 ;
if ( ( F_24 ( V_14 , & V_37 , & V_36 ,
V_41 , V_35 ) ) ) {
F_25 ( V_42 L_2 ,
V_14 -> V_43 , __FILE__ , __LINE__ , V_44 ) ;
return - 1 ;
}
V_38 = F_21 ( V_37 . V_46 ) &
V_47 ;
if ( V_38 != V_48 ) {
F_25 ( V_42 L_2 ,
V_14 -> V_43 , __FILE__ , __LINE__ , V_44 ) ;
return - 1 ;
}
V_96 = F_78 ( V_36 . V_146 ) ;
if ( ! ( F_60 ( V_96 ) ) )
return - 1 ;
V_17 = F_18 ( V_36 . V_19 ) ;
if ( ! ( F_21 ( V_36 . V_145 ) &
V_597 ) ) {
F_25 ( V_42 L_179 ,
V_14 -> V_43 , V_35 ) ;
return - 1 ;
}
if ( F_237 ( V_14 , V_17 , V_35 ,
V_36 . V_598 ) )
return - 1 ;
V_54 = F_35 ( V_14 ,
V_17 ) ;
if ( V_54 ) {
F_41 ( V_54 ) ;
return - 1 ;
}
V_54 = F_9 ( sizeof( struct V_53 ) ,
V_130 ) ;
if ( ! V_54 ) {
F_25 ( V_42 L_2 ,
V_14 -> V_43 , __FILE__ , __LINE__ , V_44 ) ;
return 0 ;
}
F_10 ( & V_54 -> V_4 ) ;
V_54 -> V_35 = V_35 ;
if ( F_23 ( V_14 ,
F_21 ( V_36 . V_566 ) ,
& V_54 -> V_84 ) != 0 )
F_25 ( V_42 L_2 ,
V_14 -> V_43 , __FILE__ , __LINE__ , V_44 ) ;
V_54 -> V_78 =
F_21 ( V_36 . V_500 ) ;
if ( V_54 -> V_78 != 0 )
V_54 -> V_26 =
F_21 ( V_36 . V_499 ) ;
V_54 -> V_96 = V_96 ;
V_54 -> V_17 = V_17 ;
V_54 -> V_218 = V_36 . V_593 ;
V_54 -> V_139 = ( F_21 ( V_36 . V_145 ) &
V_601 ) ? 1 : 0 ;
if ( V_36 . V_145 & V_594 ) {
V_54 -> V_80 =
F_21 ( V_36 . V_595 ) ;
memcpy ( & V_54 -> V_79 [ 0 ] ,
& V_36 . V_596 [ 0 ] , 4 ) ;
} else {
V_54 -> V_80 = 0 ;
V_54 -> V_79 [ 0 ] = '\0' ;
}
if ( V_54 -> V_78 && ! ( F_229 (
V_14 , & V_37 , & V_549 , V_561 ,
V_54 -> V_78 ) ) )
V_54 -> V_22 =
F_18 ( V_549 . V_24 ) ;
V_54 -> V_20 = F_18 ( V_36 . V_21 ) ;
if ( V_14 -> V_602 )
F_50 ( V_14 , V_54 ) ;
else
F_45 ( V_14 , V_54 ) ;
F_41 ( V_54 ) ;
return 0 ;
}
static void
F_43 ( struct V_13 * V_14 ,
struct V_53 * V_54 )
{
struct V_72 * V_118 ;
if ( ( V_14 -> V_506 -> V_507 == V_508 ) &&
( V_54 -> V_498 ) ) {
F_205 ( V_14 , V_54 ) ;
V_54 -> V_498 = 0 ;
}
F_46 ( V_14 , F_13 ( V_42
L_180 ,
V_14 -> V_43 , V_44 ,
V_54 -> V_35 , ( unsigned long long )
V_54 -> V_17 ) ) ;
if ( V_54 -> V_78 != 0 )
F_46 ( V_14 , F_13 ( V_42
L_181 ,
V_14 -> V_43 , V_44 ,
( unsigned long long ) V_54 -> V_22 ,
V_54 -> V_26 ) ) ;
if ( V_54 -> V_79 [ 0 ] != '\0' )
F_46 ( V_14 , F_13 ( V_42
L_182 ,
V_14 -> V_43 , V_44 ,
V_54 -> V_80 ,
V_54 -> V_79 ) ) ;
if ( V_54 -> V_85 && V_54 -> V_85 -> V_120 ) {
V_118 = V_54 -> V_85 -> V_120 ;
V_118 -> V_334 = 1 ;
F_155 ( V_14 , V_54 -> V_17 ) ;
V_118 -> V_35 =
V_132 ;
}
if ( ! V_14 -> V_603 )
F_49 ( V_14 ,
V_54 -> V_17 ,
V_54 -> V_84 ) ;
F_13 ( V_42
L_7 ,
V_14 -> V_43 , V_54 -> V_35 ,
( unsigned long long ) V_54 -> V_17 ) ;
if ( V_54 -> V_78 != 0 )
F_13 ( V_42
L_183 ,
V_14 -> V_43 ,
( unsigned long long ) V_54 -> V_22 ,
V_54 -> V_26 ) ;
if ( V_54 -> V_79 [ 0 ] != '\0' )
F_13 ( V_42
L_9 ,
V_14 -> V_43 , V_54 -> V_80 ,
V_54 -> V_79 ) ;
F_46 ( V_14 , F_13 ( V_42
L_184 ,
V_14 -> V_43 , V_44 ,
V_54 -> V_35 , ( unsigned long long )
V_54 -> V_17 ) ) ;
if ( V_54 -> V_78 != 0 )
F_46 ( V_14 , F_13 ( V_42
L_185 ,
V_14 -> V_43 , V_44 ,
( unsigned long long ) V_54 -> V_22 ,
V_54 -> V_26 ) ) ;
if ( V_54 -> V_79 [ 0 ] != '\0' )
F_46 ( V_14 , F_13 ( V_42
L_186 ,
V_14 -> V_43 , V_44 , V_54 -> V_80 ,
V_54 -> V_79 ) ) ;
}
static void
F_240 ( struct V_13 * V_14 ,
T_19 * V_304 )
{
int V_106 ;
T_4 V_35 ;
T_4 V_324 ;
T_6 V_592 ;
char * V_604 = NULL ;
T_6 V_541 , V_605 ;
switch ( V_304 -> V_351 ) {
case V_358 :
V_604 = L_187 ;
break;
case V_355 :
V_604 = L_188 ;
break;
case V_354 :
case 0 :
V_604 = L_189 ;
break;
case V_352 :
V_604 = L_190 ;
break;
default:
V_604 = L_191 ;
break;
}
F_13 ( V_42 L_192 ,
V_14 -> V_43 , V_604 ) ;
F_13 ( L_193 \
L_194 ,
F_21 ( V_304 -> V_350 ) ,
F_21 ( V_304 -> V_500 ) ,
V_304 -> V_606 , V_304 -> V_325 ) ;
for ( V_106 = 0 ; V_106 < V_304 -> V_325 ; V_106 ++ ) {
V_35 = F_21 ( V_304 -> V_326 [ V_106 ] . V_327 ) ;
if ( ! V_35 )
continue;
V_592 = V_304 -> V_606 + V_106 ;
V_324 = V_304 -> V_326 [ V_106 ] . V_328 &
V_329 ;
switch ( V_324 ) {
case V_607 :
V_604 = L_195 ;
break;
case V_349 :
V_604 = L_196 ;
break;
case V_330 :
V_604 = L_197 ;
break;
case V_608 :
V_604 = L_198 ;
break;
case V_609 :
V_604 = L_199 ;
break;
default:
V_604 = L_44 ;
break;
}
V_541 = V_304 -> V_326 [ V_106 ] . V_610 >> 4 ;
V_605 = V_304 -> V_326 [ V_106 ] . V_610 & 0xF ;
F_13 ( L_200 \
L_201 , V_592 ,
V_35 , V_604 , V_541 , V_605 ) ;
}
}
static int
F_241 ( struct V_13 * V_14 ,
struct V_3 * V_7 )
{
int V_106 ;
T_4 V_564 , V_35 ;
T_4 V_324 ;
T_6 V_592 , V_611 ;
struct V_92 * V_93 ;
T_1 V_17 ;
unsigned long V_76 ;
T_6 V_541 , V_605 ;
T_19 * V_304 =
( T_19 * )
V_7 -> V_304 ;
if ( V_14 -> V_15 & V_612 )
F_240 ( V_14 , V_304 ) ;
if ( V_14 -> V_82 || V_14 -> V_261 || V_14 -> V_262 )
return 0 ;
if ( ! V_14 -> V_39 . V_40 )
F_223 ( V_14 ) ;
else
F_220 ( V_14 ) ;
if ( V_7 -> V_357 ) {
F_46 ( V_14 , F_13 ( V_42
L_202 , V_14 -> V_43 ) ) ;
return 0 ;
}
V_564 = F_21 ( V_304 -> V_350 ) ;
if ( V_304 -> V_351 == V_358 )
if ( F_230 ( V_14 , V_564 ) != 0 )
return 0 ;
F_32 ( & V_14 -> V_94 , V_76 ) ;
V_93 = F_57 ( V_14 ,
V_564 ) ;
if ( V_93 ) {
V_17 = V_93 -> V_17 ;
V_611 = V_93 -> V_40 ;
} else if ( V_564 < V_14 -> V_39 . V_40 ) {
V_17 = V_14 -> V_39 . V_17 ;
V_611 = V_14 -> V_39 . V_40 ;
} else {
F_33 ( & V_14 -> V_94 , V_76 ) ;
return 0 ;
}
F_33 ( & V_14 -> V_94 , V_76 ) ;
for ( V_106 = 0 ; V_106 < V_304 -> V_325 ; V_106 ++ ) {
if ( V_7 -> V_357 ) {
F_46 ( V_14 , F_13 ( V_42
L_202 , V_14 -> V_43 ) ) ;
return 0 ;
}
if ( V_14 -> V_261 || V_14 -> V_262 )
return 0 ;
V_592 = V_304 -> V_606 + V_106 ;
if ( V_592 >= V_611 )
continue;
V_324 = V_304 -> V_326 [ V_106 ] . V_328 &
V_329 ;
if ( ( V_304 -> V_326 [ V_106 ] . V_328 &
V_613 ) && ( V_324 !=
V_349 ) )
continue;
V_35 = F_21 ( V_304 -> V_326 [ V_106 ] . V_327 ) ;
if ( ! V_35 )
continue;
V_541 = V_304 -> V_326 [ V_106 ] . V_610 >> 4 ;
V_605 = V_304 -> V_326 [ V_106 ] . V_610 & 0xF ;
switch ( V_324 ) {
case V_608 :
if ( V_14 -> V_82 )
break;
if ( V_541 == V_605 )
break;
F_222 ( V_14 , V_17 ,
V_35 , V_592 , V_541 ) ;
if ( V_541 < V_546 )
break;
F_238 ( V_14 , V_17 , V_35 ,
V_592 , V_541 ) ;
case V_607 :
if ( V_14 -> V_82 )
break;
F_222 ( V_14 , V_17 ,
V_35 , V_592 , V_541 ) ;
F_239 ( V_14 , V_35 , V_592 , 0 ) ;
break;
case V_349 :
F_42 ( V_14 , V_35 ) ;
break;
}
}
if ( V_304 -> V_351 == V_355 &&
V_93 )
F_234 ( V_14 , V_17 ) ;
return 0 ;
}
static void
F_242 ( struct V_13 * V_14 ,
T_32 * V_304 )
{
char * V_614 = NULL ;
switch ( V_304 -> V_365 ) {
case V_514 :
V_614 = L_203 ;
break;
case V_615 :
V_614 = L_204 ;
break;
case V_616 :
V_614 = L_205 ;
break;
case V_617 :
V_614 = L_206 ;
break;
case V_618 :
V_614 = L_207 ;
break;
case V_619 :
V_614 = L_208 ;
break;
case V_620 :
V_614 = L_209 ;
break;
case V_621 :
V_614 = L_210 ;
break;
case V_622 :
V_614 = L_211 ;
break;
case V_623 :
V_614 = L_212 ;
break;
case V_624 :
V_614 = L_213 ;
break;
case V_625 :
V_614 = L_214 ;
break;
case V_626 :
V_614 = L_215 ;
break;
default:
V_614 = L_216 ;
break;
}
F_13 ( V_42 L_217
L_218 ,
V_14 -> V_43 , V_614 , F_21 ( V_304 -> V_199 ) ,
( unsigned long long ) F_18 ( V_304 -> V_19 ) ,
F_21 ( V_304 -> V_488 ) ) ;
if ( V_304 -> V_365 == V_514 )
F_13 ( V_42 L_219 , V_14 -> V_43 ,
V_304 -> V_515 , V_304 -> V_627 ) ;
F_13 ( L_220 ) ;
}
static void
F_243 ( struct V_13 * V_14 ,
struct V_3 * V_7 )
{
struct V_72 * V_296 ;
struct V_53 * V_54 ;
T_1 V_17 ;
unsigned long V_76 ;
T_32 * V_304 =
( T_32 * )
V_7 -> V_304 ;
if ( V_14 -> V_15 & V_612 )
F_242 ( V_14 ,
V_304 ) ;
if ( ( V_14 -> V_201 . V_628 >> 8 ) < 0xC )
return;
if ( V_304 -> V_365 !=
V_616 &&
V_304 -> V_365 !=
V_622 )
return;
F_32 ( & V_14 -> V_74 , V_76 ) ;
V_17 = F_18 ( V_304 -> V_19 ) ;
V_54 = F_34 ( V_14 ,
V_17 ) ;
if ( ! V_54 || ! V_54 -> V_85 )
goto V_89;
V_296 = V_54 -> V_85 -> V_120 ;
if ( ! V_296 )
goto V_89;
if ( V_304 -> V_365 ==
V_616 )
V_296 -> V_247 = 1 ;
else
V_296 -> V_247 = 0 ;
V_89:
if ( V_54 )
F_41 ( V_54 ) ;
F_33 ( & V_14 -> V_74 , V_76 ) ;
}
static void
F_244 ( struct V_13 * V_14 ,
T_40 * V_304 )
{
char * V_614 = NULL ;
switch ( V_304 -> V_365 ) {
case V_629 :
V_614 = L_221 ;
break;
case V_630 :
V_614 = L_222 ;
break;
default:
V_614 = L_216 ;
break;
}
F_13 ( V_42 L_223
L_224
L_225 , V_14 -> V_43 , V_614 ,
F_21 ( V_304 -> V_500 ) ,
( unsigned long long ) F_18 ( V_304 -> V_24 ) ,
F_21 ( V_304 -> V_631 ) ) ;
}
static void
F_245 ( struct V_13 * V_14 ,
struct V_3 * V_7 )
{
if ( V_14 -> V_15 & V_612 )
F_244 ( V_14 ,
( T_40 * )
V_7 -> V_304 ) ;
}
static void
F_246 ( struct V_13 * V_14 ,
struct V_3 * V_7 )
{
struct V_101 * V_104 ;
struct V_110 * V_75 ;
T_4 V_102 , V_35 ;
T_10 V_109 ;
struct V_116 * V_117 ;
T_10 V_632 ;
T_10 V_633 ;
T_18 * V_37 ;
T_41 * V_304 =
( T_41 * )
V_7 -> V_304 ;
T_4 V_38 ;
unsigned long V_76 ;
int V_2 ;
T_6 V_634 = 0 ;
T_6 V_635 ;
F_113 ( & V_14 -> V_238 . V_258 ) ;
F_13 ( V_42
L_226 ,
V_14 -> V_43 , V_44 , V_304 -> V_593 ,
V_304 -> V_636 ) ;
F_156 ( V_14 ) ;
F_32 ( & V_14 -> V_105 , V_76 ) ;
V_37 = V_14 -> V_238 . V_237 ;
V_637:
if ( V_634 ++ == 5 ) {
F_46 ( V_14 , F_13 ( V_42 L_227 ,
V_14 -> V_43 , V_44 ) ) ;
goto V_89;
} else if ( V_634 > 1 )
F_46 ( V_14 , F_13 ( V_42 L_228 ,
V_14 -> V_43 , V_44 , V_634 - 1 ) ) ;
V_632 = 0 ;
V_633 = 0 ;
for ( V_102 = 1 ; V_102 <= V_14 -> V_107 ; V_102 ++ ) {
if ( V_14 -> V_82 )
goto V_89;
V_104 = F_61 ( V_14 , V_102 ) ;
if ( ! V_104 )
continue;
V_75 = V_104 -> V_51 ;
V_117 = V_75 -> V_120 ;
if ( ! V_117 || ! V_117 -> V_122 )
continue;
if ( V_117 -> V_122 -> V_76 &
V_138 )
continue;
if ( V_117 -> V_122 -> V_76 &
V_123 )
continue;
V_35 = V_117 -> V_122 -> V_35 ;
V_109 = V_117 -> V_109 ;
V_633 ++ ;
if ( V_14 -> V_82 )
goto V_89;
F_33 ( & V_14 -> V_105 , V_76 ) ;
V_2 = F_112 ( V_14 , V_35 , 0 , 0 , V_109 ,
V_288 , V_102 , 30 ,
V_638 ) ;
if ( V_2 == V_259 ) {
F_75 ( V_312 , V_75 ,
L_229
L_230 , V_104 ) ;
F_32 ( & V_14 -> V_105 , V_76 ) ;
goto V_637;
}
V_38 = F_21 ( V_37 -> V_46 )
& V_47 ;
if ( V_38 != V_48 ) {
F_75 ( V_312 , V_75 ,
L_231 ,
V_38 , V_104 ) ;
F_32 ( & V_14 -> V_105 , V_76 ) ;
goto V_637;
}
if ( V_37 -> V_284 ==
V_233 ||
V_37 -> V_284 ==
V_235 ) {
F_32 ( & V_14 -> V_105 , V_76 ) ;
continue;
}
V_635 = 0 ;
V_639:
if ( V_635 ++ == 60 ) {
F_46 ( V_14 , F_13 ( V_42
L_232 , V_14 -> V_43 ,
V_44 ) ) ;
F_32 ( & V_14 -> V_105 , V_76 ) ;
goto V_637;
}
if ( V_14 -> V_82 )
goto V_640;
V_2 = F_112 ( V_14 , V_35 , V_75 -> V_88 , V_75 -> V_87 ,
V_75 -> V_109 , V_271 , V_102 , 30 ,
V_638 ) ;
if ( V_2 == V_259 ) {
F_75 ( V_312 , V_75 ,
L_233
L_234 , V_104 ) ;
goto V_639;
}
if ( V_635 > 1 )
F_75 ( V_312 , V_75 ,
L_235
L_236 ,
V_635 - 1 , V_104 ) ;
V_632 += F_78 ( V_37 -> V_282 ) ;
F_32 ( & V_14 -> V_105 , V_76 ) ;
}
if ( V_14 -> V_641 ) {
F_46 ( V_14 , F_13 ( V_42
L_237 ,
V_14 -> V_43 , V_44 ) ) ;
V_14 -> V_641 = 0 ;
goto V_637;
}
V_89:
F_33 ( & V_14 -> V_105 , V_76 ) ;
V_640:
F_46 ( V_14 , F_13 ( V_42
L_238 ,
V_14 -> V_43 , V_44 , V_633 , V_632 ) ) ;
V_14 -> V_642 = 0 ;
if ( ! V_14 -> V_82 )
F_154 ( V_14 ) ;
F_128 ( & V_14 -> V_238 . V_258 ) ;
}
static void
F_247 ( struct V_13 * V_14 ,
struct V_3 * V_7 )
{
T_42 * V_304 =
( T_42 * ) V_7 -> V_304 ;
if ( V_14 -> V_15 & V_612 ) {
F_13 ( V_42 L_239 , V_14 -> V_43 ,
( V_304 -> V_365 == V_643 ) ?
L_240 : L_241 ) ;
if ( V_304 -> V_644 )
F_13 ( L_242 ,
F_78 ( V_304 -> V_644 ) ) ;
F_13 ( L_220 ) ;
}
if ( V_304 -> V_365 == V_643 &&
! V_14 -> V_39 . V_40 ) {
if ( V_645 > 0 && V_14 -> V_82 ) {
while ( V_14 -> V_82 )
F_248 ( 1 ) ;
}
F_223 ( V_14 ) ;
}
}
static int
F_249 ( struct V_13 * V_14 , T_4 V_35 , T_6 V_646 )
{
T_43 * V_253 ;
T_44 * V_37 ;
T_4 V_102 ;
T_6 V_647 = 0 ;
int V_28 = 0 ;
T_4 V_38 ;
T_10 V_457 ;
if ( V_14 -> V_159 == V_160 )
return V_28 ;
F_113 ( & V_14 -> V_570 . V_258 ) ;
if ( V_14 -> V_570 . V_239 != V_240 ) {
F_25 ( V_42 L_243 ,
V_14 -> V_43 , V_44 ) ;
V_28 = - V_648 ;
goto V_89;
}
V_14 -> V_570 . V_239 = V_244 ;
V_102 = F_164 ( V_14 , V_14 -> V_649 ) ;
if ( ! V_102 ) {
F_25 ( V_42 L_49 ,
V_14 -> V_43 , V_44 ) ;
V_14 -> V_570 . V_239 = V_240 ;
V_28 = - V_648 ;
goto V_89;
}
V_253 = F_120 ( V_14 , V_102 ) ;
V_14 -> V_570 . V_102 = V_102 ;
memset ( V_253 , 0 , sizeof( T_43 ) ) ;
V_253 -> V_272 = V_650 ;
V_253 -> V_493 = V_651 ;
V_253 -> V_198 = V_646 ;
F_46 ( V_14 , F_13 ( V_42 L_244\
L_245 , V_14 -> V_43 ,
V_35 , V_646 ) ) ;
F_123 ( & V_14 -> V_570 . V_245 ) ;
F_165 ( V_14 , V_102 ) ;
F_125 ( & V_14 -> V_570 . V_245 , 10 * V_278 ) ;
if ( ! ( V_14 -> V_570 . V_239 & V_241 ) ) {
F_25 ( V_42 L_51 ,
V_14 -> V_43 , V_44 ) ;
if ( ! ( V_14 -> V_570 . V_239 & V_279 ) )
V_647 = 1 ;
V_28 = - V_652 ;
goto V_89;
}
if ( V_14 -> V_570 . V_239 & V_243 ) {
V_37 = V_14 -> V_570 . V_237 ;
V_38 = F_21 ( V_37 -> V_46 ) ;
if ( V_38 & V_519 )
V_457 = F_78 ( V_37 -> V_281 ) ;
else
V_457 = 0 ;
V_38 &= V_47 ;
if ( V_38 != V_48 ) {
F_46 ( V_14 , F_13 ( V_42
L_246
L_247 , V_14 -> V_43 , V_38 ,
V_457 ) ) ;
V_28 = - V_652 ;
} else
F_46 ( V_14 , F_13 ( V_42
L_248 ,
V_14 -> V_43 ) ) ;
}
V_89:
V_14 -> V_570 . V_239 = V_240 ;
F_128 ( & V_14 -> V_570 . V_258 ) ;
if ( V_647 )
F_116 ( V_14 , V_264 ,
V_265 ) ;
return V_28 ;
}
static void
F_250 ( struct V_110 * V_75 , void * V_143 )
{
int V_28 ;
V_75 -> V_143 = V_143 ? 1 : 0 ;
F_75 ( V_144 , V_75 , L_249 ,
V_75 -> V_143 ? L_250 : L_251 ) ;
V_28 = F_251 ( V_75 ) ;
}
static void
F_252 ( struct V_13 * V_14 ,
T_23 * V_361 )
{
struct V_55 * V_56 ;
unsigned long V_76 ;
T_1 V_60 ;
T_4 V_35 = F_21 ( V_361 -> V_368 ) ;
int V_28 ;
F_100 ( V_14 , V_35 , & V_60 ) ;
if ( ! V_60 ) {
F_25 ( V_42
L_2 , V_14 -> V_43 ,
__FILE__ , __LINE__ , V_44 ) ;
return;
}
F_32 ( & V_14 -> V_90 , V_76 ) ;
V_56 = F_53 ( V_14 , V_60 ) ;
F_33 ( & V_14 -> V_90 , V_76 ) ;
if ( V_56 )
return;
V_56 = F_9 ( sizeof( struct V_55 ) , V_130 ) ;
if ( ! V_56 ) {
F_25 ( V_42
L_2 , V_14 -> V_43 ,
__FILE__ , __LINE__ , V_44 ) ;
return;
}
V_56 -> V_87 = V_14 -> V_653 ++ ;
V_56 -> V_88 = V_133 ;
V_56 -> V_35 = V_35 ;
V_56 -> V_60 = V_60 ;
F_54 ( V_14 , V_56 ) ;
if ( ! V_14 -> V_602 ) {
V_28 = F_253 ( V_14 -> V_113 , V_133 ,
V_56 -> V_87 , 0 ) ;
if ( V_28 )
F_55 ( V_14 , V_56 ) ;
} else {
F_32 ( & V_14 -> V_90 , V_76 ) ;
F_26 ( V_14 , V_56 , 1 ) ;
F_33 ( & V_14 -> V_90 , V_76 ) ;
}
}
static void
F_254 ( struct V_13 * V_14 , T_4 V_35 )
{
struct V_55 * V_56 ;
unsigned long V_76 ;
struct V_72 * V_118 ;
struct V_126 * V_85 = NULL ;
F_32 ( & V_14 -> V_90 , V_76 ) ;
V_56 = F_52 ( V_14 , V_35 ) ;
if ( V_56 ) {
if ( V_56 -> V_85 ) {
V_85 = V_56 -> V_85 ;
V_118 = V_85 -> V_120 ;
V_118 -> V_334 = 1 ;
}
F_13 ( V_42 L_252 ,
V_14 -> V_43 , V_56 -> V_35 ,
( unsigned long long ) V_56 -> V_60 ) ;
F_56 ( & V_56 -> V_81 ) ;
F_2 ( V_56 ) ;
}
F_33 ( & V_14 -> V_90 , V_76 ) ;
if ( V_85 )
F_255 ( & V_85 -> V_127 ) ;
}
static void
F_256 ( struct V_13 * V_14 ,
T_23 * V_361 )
{
struct V_53 * V_54 ;
struct V_126 * V_85 = NULL ;
struct V_72 * V_118 ;
unsigned long V_76 ;
T_4 V_35 = F_21 ( V_361 -> V_370 ) ;
F_32 ( & V_14 -> V_74 , V_76 ) ;
V_54 = F_36 ( V_14 , V_35 ) ;
if ( V_54 ) {
V_54 -> V_207 = 0 ;
V_54 -> V_208 = 0 ;
F_179 ( V_35 , V_14 -> V_137 ) ;
if ( V_54 -> V_85 && V_54 -> V_85 -> V_120 ) {
V_85 = V_54 -> V_85 ;
V_118 = V_85 -> V_120 ;
V_118 -> V_76 &=
~ V_138 ;
}
}
F_33 ( & V_14 -> V_74 , V_76 ) ;
if ( ! V_54 )
return;
if ( V_85 )
F_257 ( V_85 , NULL , F_250 ) ;
F_41 ( V_54 ) ;
}
static void
F_258 ( struct V_13 * V_14 ,
T_23 * V_361 )
{
struct V_53 * V_54 ;
struct V_126 * V_85 = NULL ;
struct V_72 * V_118 ;
unsigned long V_76 ;
T_4 V_35 = F_21 ( V_361 -> V_370 ) ;
T_4 V_207 = 0 ;
T_1 V_208 = 0 ;
F_99 ( V_14 , V_35 , & V_207 ) ;
if ( V_207 )
F_100 ( V_14 , V_207 ,
& V_208 ) ;
F_32 ( & V_14 -> V_74 , V_76 ) ;
V_54 = F_36 ( V_14 , V_35 ) ;
if ( V_54 ) {
F_159 ( V_35 , V_14 -> V_137 ) ;
if ( V_54 -> V_85 && V_54 -> V_85 -> V_120 ) {
V_85 = V_54 -> V_85 ;
V_118 = V_85 -> V_120 ;
V_118 -> V_76 |=
V_138 ;
V_54 -> V_207 = V_207 ;
V_54 -> V_208 = V_208 ;
}
}
F_33 ( & V_14 -> V_74 , V_76 ) ;
if ( ! V_54 )
return;
F_249 ( V_14 , V_35 , V_361 -> V_198 ) ;
if ( V_85 )
F_257 ( V_85 , ( void * ) 1 , F_250 ) ;
F_41 ( V_54 ) ;
}
static void
F_259 ( struct V_13 * V_14 ,
T_23 * V_361 )
{
T_4 V_35 = F_21 ( V_361 -> V_370 ) ;
F_42 ( V_14 , V_35 ) ;
}
static void
F_260 ( struct V_13 * V_14 ,
T_23 * V_361 )
{
struct V_53 * V_54 ;
T_4 V_35 = F_21 ( V_361 -> V_370 ) ;
T_9 V_37 ;
T_8 V_36 ;
T_10 V_38 ;
T_1 V_17 ;
T_4 V_564 ;
F_159 ( V_35 , V_14 -> V_137 ) ;
V_54 = F_37 ( V_14 , V_35 ) ;
if ( V_54 ) {
F_249 ( V_14 , V_35 , V_361 -> V_198 ) ;
F_41 ( V_54 ) ;
return;
}
if ( ( F_24 ( V_14 , & V_37 , & V_36 ,
V_41 , V_35 ) ) ) {
F_25 ( V_42 L_2 ,
V_14 -> V_43 , __FILE__ , __LINE__ , V_44 ) ;
return;
}
V_38 = F_21 ( V_37 . V_46 ) &
V_47 ;
if ( V_38 != V_48 ) {
F_25 ( V_42 L_2 ,
V_14 -> V_43 , __FILE__ , __LINE__ , V_44 ) ;
return;
}
V_564 = F_21 ( V_36 . V_566 ) ;
if ( ! F_23 ( V_14 , V_564 , & V_17 ) )
F_222 ( V_14 , V_17 , V_35 ,
V_36 . V_593 , V_546 ) ;
F_249 ( V_14 , V_35 , V_361 -> V_198 ) ;
F_239 ( V_14 , V_35 , 0 , 1 ) ;
}
static void
F_261 ( struct V_13 * V_14 ,
T_22 * V_304 )
{
T_23 * V_361 ;
T_6 V_654 ;
int V_106 ;
char * V_614 = NULL , * V_655 = NULL ;
V_361 = ( T_23 * ) & V_304 -> V_362 [ 0 ] ;
F_13 ( V_42 L_253 ,
V_14 -> V_43 , ( F_78 ( V_304 -> V_145 ) &
V_364 ) ?
L_254 : L_255 , V_304 -> V_363 ) ;
for ( V_106 = 0 ; V_106 < V_304 -> V_363 ; V_106 ++ , V_361 ++ ) {
switch ( V_361 -> V_365 ) {
case V_656 :
V_614 = L_187 ;
break;
case V_367 :
V_614 = L_188 ;
break;
case V_657 :
V_614 = L_256 ;
break;
case V_658 :
V_614 = L_257 ;
break;
case V_369 :
V_614 = L_258 ;
break;
case V_659 :
V_614 = L_259 ;
break;
case V_366 :
V_614 = L_260 ;
break;
case V_660 :
V_614 = L_261 ;
break;
case V_661 :
V_614 = L_262 ;
break;
default:
V_614 = L_216 ;
break;
}
V_654 = F_21 ( V_361 -> V_662 ) &
V_663 ;
switch ( V_654 ) {
case V_664 :
V_655 = L_55 ;
break;
case V_665 :
V_655 = L_263 ;
break;
case V_666 :
V_655 = L_264 ;
break;
default:
V_655 = L_265 ;
break;
}
F_13 ( L_266 \
L_267 , V_655 ,
V_614 , F_21 ( V_361 -> V_368 ) ,
F_21 ( V_361 -> V_370 ) ,
V_361 -> V_198 ) ;
}
}
static void
F_262 ( struct V_13 * V_14 ,
struct V_3 * V_7 )
{
T_23 * V_361 ;
int V_106 ;
T_6 V_667 ;
T_22 * V_304 =
( T_22 * )
V_7 -> V_304 ;
if ( ( V_14 -> V_15 & V_612 ) &&
( ! V_14 -> V_217 ) )
F_261 ( V_14 , V_304 ) ;
V_667 = ( F_78 ( V_304 -> V_145 ) &
V_364 ) ? 1 : 0 ;
V_361 = ( T_23 * ) & V_304 -> V_362 [ 0 ] ;
if ( V_14 -> V_82 &&
V_14 -> V_159 != V_160 ) {
for ( V_106 = 0 ; V_106 < V_304 -> V_363 ; V_106 ++ , V_361 ++ ) {
if ( V_361 -> V_365 == V_658 )
F_249 ( V_14 ,
F_21 ( V_361 -> V_370 ) ,
V_361 -> V_198 ) ;
}
return;
}
for ( V_106 = 0 ; V_106 < V_304 -> V_363 ; V_106 ++ , V_361 ++ ) {
switch ( V_361 -> V_365 ) {
case V_659 :
case V_656 :
if ( ! V_667 )
F_252 ( V_14 , V_361 ) ;
break;
case V_366 :
case V_367 :
if ( ! V_667 )
F_254 ( V_14 ,
F_21 ( V_361 -> V_368 ) ) ;
break;
case V_660 :
if ( ! V_14 -> V_134 )
F_258 ( V_14 , V_361 ) ;
break;
case V_661 :
if ( ! V_14 -> V_134 )
F_256 ( V_14 , V_361 ) ;
break;
case V_658 :
if ( ! V_14 -> V_134 )
F_260 ( V_14 , V_361 ) ;
break;
case V_369 :
if ( ! V_14 -> V_134 )
F_259 ( V_14 , V_361 ) ;
break;
}
}
}
static void
F_263 ( struct V_13 * V_14 ,
struct V_3 * V_7 )
{
T_1 V_60 ;
unsigned long V_76 ;
struct V_55 * V_56 ;
T_4 V_35 ;
T_10 V_166 ;
int V_28 ;
T_24 * V_304 =
( T_24 * ) V_7 -> V_304 ;
if ( V_14 -> V_82 )
return;
if ( V_304 -> V_365 != V_371 )
return;
V_35 = F_21 ( V_304 -> V_368 ) ;
V_166 = F_78 ( V_304 -> V_372 ) ;
if ( ! V_14 -> V_217 )
F_46 ( V_14 , F_13 ( V_42
L_268 ,
V_14 -> V_43 , V_44 , V_35 ,
F_78 ( V_304 -> V_668 ) , V_166 ) ) ;
switch ( V_166 ) {
case V_176 :
case V_175 :
F_254 ( V_14 , V_35 ) ;
break;
case V_171 :
case V_173 :
case V_170 :
F_32 ( & V_14 -> V_90 , V_76 ) ;
V_56 = F_52 ( V_14 , V_35 ) ;
F_33 ( & V_14 -> V_90 , V_76 ) ;
if ( V_56 )
break;
F_100 ( V_14 , V_35 , & V_60 ) ;
if ( ! V_60 ) {
F_25 ( V_42
L_2 , V_14 -> V_43 ,
__FILE__ , __LINE__ , V_44 ) ;
break;
}
V_56 = F_9 ( sizeof( struct V_55 ) , V_130 ) ;
if ( ! V_56 ) {
F_25 ( V_42
L_2 , V_14 -> V_43 ,
__FILE__ , __LINE__ , V_44 ) ;
break;
}
V_56 -> V_87 = V_14 -> V_653 ++ ;
V_56 -> V_88 = V_133 ;
V_56 -> V_35 = V_35 ;
V_56 -> V_60 = V_60 ;
F_54 ( V_14 , V_56 ) ;
V_28 = F_253 ( V_14 -> V_113 , V_133 ,
V_56 -> V_87 , 0 ) ;
if ( V_28 )
F_55 ( V_14 , V_56 ) ;
break;
case V_669 :
default:
break;
}
}
static void
F_264 ( struct V_13 * V_14 ,
struct V_3 * V_7 )
{
T_4 V_35 , V_564 ;
T_10 V_166 ;
struct V_53 * V_54 ;
T_9 V_37 ;
T_8 V_36 ;
T_10 V_38 ;
T_45 * V_304 =
( T_45 * ) V_7 -> V_304 ;
T_1 V_17 ;
if ( V_14 -> V_82 )
return;
if ( V_304 -> V_365 != V_670 )
return;
V_35 = F_21 ( V_304 -> V_370 ) ;
V_166 = F_78 ( V_304 -> V_372 ) ;
if ( ! V_14 -> V_217 )
F_46 ( V_14 , F_13 ( V_42
L_268 ,
V_14 -> V_43 , V_44 , V_35 ,
F_78 ( V_304 -> V_668 ) , V_166 ) ) ;
switch ( V_166 ) {
case V_671 :
case V_672 :
case V_673 :
case V_674 :
case V_675 :
if ( ! V_14 -> V_134 )
F_159 ( V_35 , V_14 -> V_137 ) ;
V_54 = F_37 ( V_14 , V_35 ) ;
if ( V_54 ) {
F_41 ( V_54 ) ;
return;
}
if ( ( F_24 ( V_14 , & V_37 ,
& V_36 , V_41 ,
V_35 ) ) ) {
F_25 ( V_42 L_2 ,
V_14 -> V_43 , __FILE__ , __LINE__ , V_44 ) ;
return;
}
V_38 = F_21 ( V_37 . V_46 ) &
V_47 ;
if ( V_38 != V_48 ) {
F_25 ( V_42 L_2 ,
V_14 -> V_43 , __FILE__ , __LINE__ , V_44 ) ;
return;
}
V_564 = F_21 ( V_36 . V_566 ) ;
if ( ! F_23 ( V_14 , V_564 , & V_17 ) )
F_222 ( V_14 , V_17 , V_35 ,
V_36 . V_593 , V_546 ) ;
F_239 ( V_14 , V_35 , 0 , 1 ) ;
break;
case V_676 :
case V_677 :
case V_678 :
default:
break;
}
}
static void
F_265 ( struct V_13 * V_14 ,
T_46 * V_304 )
{
char * V_614 = NULL ;
switch ( V_304 -> V_679 ) {
case V_680 :
V_614 = L_269 ;
break;
case V_681 :
V_614 = L_270 ;
break;
case V_682 :
V_614 = L_271 ;
break;
case V_683 :
V_614 = L_272 ;
break;
case V_684 :
V_614 = L_273 ;
break;
}
if ( ! V_614 )
return;
F_13 ( V_42 L_274 \
L_275 ,
V_14 -> V_43 , V_614 ,
F_21 ( V_304 -> V_368 ) ,
V_304 -> V_685 ) ;
}
static void
F_266 ( struct V_13 * V_14 ,
struct V_3 * V_7 )
{
T_46 * V_304 =
( T_46 * )
V_7 -> V_304 ;
static struct V_55 * V_56 ;
unsigned long V_76 ;
T_4 V_35 ;
if ( ( V_14 -> V_15 & V_612 ) &&
( ! V_14 -> V_217 ) )
F_265 ( V_14 ,
V_304 ) ;
if ( V_304 -> V_679 == V_680 ) {
F_32 ( & V_14 -> V_90 , V_76 ) ;
V_35 = F_21 ( V_304 -> V_368 ) ;
V_56 = F_52 ( V_14 , V_35 ) ;
if ( V_56 )
V_56 -> V_155 =
V_304 -> V_685 ;
F_33 ( & V_14 -> V_90 , V_76 ) ;
}
}
static void
F_267 ( struct V_13 * V_14 )
{
struct V_116 * V_117 ;
struct V_110 * V_75 ;
F_110 (sdev, ioc->shost) {
V_117 = V_75 -> V_120 ;
if ( V_117 && V_117 -> V_122 )
V_117 -> V_122 -> V_334 = 1 ;
}
}
static void
F_268 ( struct V_13 * V_14 ,
T_8 * V_36 )
{
struct V_72 * V_118 = NULL ;
struct V_126 * V_85 ;
struct V_53 * V_54 ;
unsigned long V_76 ;
F_32 ( & V_14 -> V_74 , V_76 ) ;
F_15 (sas_device, &ioc->sas_device_list, list) {
if ( ( V_54 -> V_17 == V_36 -> V_19 ) &&
( V_54 -> V_26 == V_36 -> V_499 ) ) {
V_54 -> V_686 = 1 ;
V_85 = V_54 -> V_85 ;
if ( V_85 && V_85 -> V_120 ) {
V_118 = V_85 -> V_120 ;
V_118 -> V_247 = 0 ;
V_118 -> V_334 = 0 ;
} else
V_118 = NULL ;
if ( V_85 ) {
F_131 ( V_144 , V_85 ,
L_276 ,
V_36 -> V_199 ,
( unsigned long long )
V_54 -> V_17 ) ;
if ( V_54 -> V_78 != 0 )
F_131 ( V_144 , V_85 ,
L_277
L_91 ,
( unsigned long long )
V_54 -> V_22 ,
V_54 -> V_26 ) ;
}
if ( V_36 -> V_145 &
V_594 ) {
V_54 -> V_80 =
F_21 ( V_36 -> V_595 ) ;
memcpy ( & V_54 -> V_79 [ 0 ] ,
& V_36 -> V_596 [ 0 ] , 4 ) ;
} else {
V_54 -> V_80 = 0 ;
V_54 -> V_79 [ 0 ] = '\0' ;
}
if ( V_54 -> V_35 == V_36 -> V_199 )
goto V_89;
F_13 ( L_278 ,
V_54 -> V_35 ) ;
V_54 -> V_35 = V_36 -> V_199 ;
if ( V_118 )
V_118 -> V_35 =
V_36 -> V_199 ;
goto V_89;
}
}
V_89:
F_33 ( & V_14 -> V_74 , V_76 ) ;
}
static void
F_269 ( struct V_13 * V_14 )
{
T_8 V_36 ;
T_9 V_37 ;
T_4 V_38 ;
T_4 V_35 ;
T_10 V_96 ;
F_13 ( V_42 L_279 , V_14 -> V_43 ) ;
if ( F_39 ( & V_14 -> V_83 ) )
goto V_89;
V_35 = 0xFFFF ;
while ( ! ( F_24 ( V_14 , & V_37 ,
& V_36 , V_687 ,
V_35 ) ) ) {
V_38 = F_21 ( V_37 . V_46 ) &
V_47 ;
if ( V_38 != V_48 )
break;
V_35 = V_36 . V_199 =
F_21 ( V_36 . V_199 ) ;
V_96 = F_78 ( V_36 . V_146 ) ;
if ( ! ( F_60 ( V_96 ) ) )
continue;
V_36 . V_19 =
F_18 ( V_36 . V_19 ) ;
V_36 . V_499 = F_21 ( V_36 . V_499 ) ;
F_268 ( V_14 , & V_36 ) ;
}
V_89:
F_13 ( V_42 L_280 ,
V_14 -> V_43 ) ;
}
static void
F_270 ( struct V_13 * V_14 , T_1 V_60 ,
T_4 V_35 )
{
struct V_72 * V_118 = NULL ;
struct V_126 * V_85 ;
struct V_55 * V_56 ;
unsigned long V_76 ;
F_32 ( & V_14 -> V_90 , V_76 ) ;
F_15 (raid_device, &ioc->raid_device_list, list) {
if ( V_56 -> V_60 == V_60 && V_56 -> V_85 ) {
V_85 = V_56 -> V_85 ;
if ( V_85 && V_85 -> V_120 ) {
V_118 = V_85 -> V_120 ;
V_118 -> V_334 = 0 ;
} else
V_118 = NULL ;
V_56 -> V_686 = 1 ;
F_33 ( & V_14 -> V_90 , V_76 ) ;
F_131 ( V_144 , V_56 -> V_85 ,
L_281 , V_35 ,
( unsigned long long ) V_56 -> V_60 ) ;
F_98 ( V_14 , V_56 ) ;
F_32 ( & V_14 -> V_90 , V_76 ) ;
if ( V_56 -> V_35 == V_35 ) {
F_33 ( & V_14 -> V_90 ,
V_76 ) ;
return;
}
F_13 ( L_278 ,
V_56 -> V_35 ) ;
V_56 -> V_35 = V_35 ;
if ( V_118 )
V_118 -> V_35 = V_35 ;
F_33 ( & V_14 -> V_90 , V_76 ) ;
return;
}
}
F_33 ( & V_14 -> V_90 , V_76 ) ;
}
static void
F_271 ( struct V_13 * V_14 )
{
T_47 V_688 ;
T_11 V_689 ;
T_12 V_191 ;
T_9 V_37 ;
T_4 V_38 ;
T_4 V_35 ;
T_6 V_646 ;
if ( ! V_14 -> V_690 )
return;
F_13 ( V_42 L_282 ,
V_14 -> V_43 ) ;
if ( F_39 ( & V_14 -> V_91 ) )
goto V_89;
V_35 = 0xFFFF ;
while ( ! ( F_272 ( V_14 , & V_37 ,
& V_688 , V_691 , V_35 ) ) ) {
V_38 = F_21 ( V_37 . V_46 ) &
V_47 ;
if ( V_38 != V_48 )
break;
V_35 = F_21 ( V_688 . V_199 ) ;
if ( F_82 ( V_14 , & V_37 ,
& V_689 , V_156 , V_35 ,
sizeof( T_11 ) ) )
continue;
if ( V_689 . V_169 == V_170 ||
V_689 . V_169 == V_171 ||
V_689 . V_169 == V_173 )
F_270 ( V_14 ,
F_18 ( V_688 . V_692 ) , V_35 ) ;
}
if ( ! V_14 -> V_134 ) {
V_646 = 0xFF ;
memset ( V_14 -> V_137 , 0 , V_14 -> V_693 ) ;
while ( ! ( F_93 ( V_14 , & V_37 ,
& V_191 , V_694 ,
V_646 ) ) ) {
V_38 = F_21 ( V_37 . V_46 ) &
V_47 ;
if ( V_38 != V_48 )
break;
V_646 = V_191 . V_198 ;
V_35 = F_21 ( V_191 . V_199 ) ;
F_159 ( V_35 , V_14 -> V_137 ) ;
}
}
V_89:
F_13 ( V_42 L_283 ,
V_14 -> V_43 ) ;
}
static void
F_273 ( struct V_13 * V_14 , T_1 V_17 ,
T_4 V_35 )
{
struct V_92 * V_93 ;
unsigned long V_76 ;
int V_106 ;
F_32 ( & V_14 -> V_94 , V_76 ) ;
F_15 (sas_expander, &ioc->sas_expander_list, list) {
if ( V_93 -> V_17 != V_17 )
continue;
V_93 -> V_686 = 1 ;
if ( V_93 -> V_35 == V_35 )
goto V_89;
F_13 ( L_284 \
L_285 ,
( unsigned long long ) V_93 -> V_17 ,
V_93 -> V_35 , V_35 ) ;
V_93 -> V_35 = V_35 ;
for ( V_106 = 0 ; V_106 < V_93 -> V_40 ; V_106 ++ )
V_93 -> V_218 [ V_106 ] . V_35 = V_35 ;
goto V_89;
}
V_89:
F_33 ( & V_14 -> V_94 , V_76 ) ;
}
static void
F_274 ( struct V_13 * V_14 )
{
T_38 V_562 ;
T_9 V_37 ;
T_4 V_38 ;
T_1 V_17 ;
T_4 V_35 ;
F_13 ( V_42 L_286 , V_14 -> V_43 ) ;
if ( F_39 ( & V_14 -> V_95 ) )
goto V_89;
V_35 = 0xFFFF ;
while ( ! ( F_231 ( V_14 , & V_37 , & V_562 ,
V_695 , V_35 ) ) ) {
V_38 = F_21 ( V_37 . V_46 ) &
V_47 ;
if ( V_38 != V_48 )
break;
V_35 = F_21 ( V_562 . V_199 ) ;
V_17 = F_18 ( V_562 . V_19 ) ;
F_13 ( L_287 ,
V_35 ,
( unsigned long long ) V_17 ) ;
F_273 ( V_14 , V_17 , V_35 ) ;
}
V_89:
F_13 ( V_42 L_288 , V_14 -> V_43 ) ;
}
static void
F_275 ( struct V_13 * V_14 )
{
struct V_53 * V_54 , * V_696 ;
struct V_92 * V_93 , * V_697 ;
struct V_55 * V_56 , * V_698 ;
struct V_699 V_700 ;
unsigned long V_76 ;
F_276 ( V_701 ) ;
F_13 ( V_42 L_289 ,
V_14 -> V_43 ) ;
F_13 ( V_42 L_290 ,
V_14 -> V_43 ) ;
F_32 ( & V_14 -> V_74 , V_76 ) ;
F_277 (sas_device, sas_device_next,
&ioc->sas_device_list, list) {
if ( ! V_54 -> V_686 )
F_278 ( & V_54 -> V_81 , & V_701 ) ;
else
V_54 -> V_686 = 0 ;
}
F_33 ( & V_14 -> V_74 , V_76 ) ;
F_277 (sas_device, sas_device_next, &head, list) {
F_43 ( V_14 , V_54 ) ;
F_40 ( & V_54 -> V_81 ) ;
F_41 ( V_54 ) ;
}
if ( V_14 -> V_690 ) {
F_13 ( V_42 L_291 ,
V_14 -> V_43 ) ;
F_277 (raid_device, raid_device_next,
&ioc->raid_device_list, list) {
if ( ! V_56 -> V_686 )
F_254 ( V_14 ,
V_56 -> V_35 ) ;
else
V_56 -> V_686 = 0 ;
}
}
F_13 ( V_42 L_292 ,
V_14 -> V_43 ) ;
F_32 ( & V_14 -> V_94 , V_76 ) ;
F_138 ( & V_700 ) ;
F_277 (sas_expander, sas_expander_next,
&ioc->sas_expander_list, list) {
if ( ! V_93 -> V_686 )
F_278 ( & V_93 -> V_81 , & V_700 ) ;
else
V_93 -> V_686 = 0 ;
}
F_33 ( & V_14 -> V_94 , V_76 ) ;
F_277 (sas_expander, sas_expander_next, &tmp_list,
list) {
F_56 ( & V_93 -> V_81 ) ;
F_235 ( V_14 , V_93 ) ;
}
F_13 ( V_42 L_293 ,
V_14 -> V_43 ) ;
F_154 ( V_14 ) ;
}
static void
F_279 ( struct V_13 * V_14 ,
struct V_92 * V_93 , T_4 V_35 )
{
T_39 V_563 ;
T_9 V_37 ;
int V_106 ;
for ( V_106 = 0 ; V_106 < V_93 -> V_40 ; V_106 ++ ) {
if ( ( F_232 ( V_14 , & V_37 ,
& V_563 , V_106 , V_35 ) ) ) {
F_25 ( V_42 L_2 ,
V_14 -> V_43 , __FILE__ , __LINE__ , V_44 ) ;
return;
}
F_222 ( V_14 , V_93 -> V_17 ,
F_21 ( V_563 . V_327 ) , V_106 ,
V_563 . V_544 >> 4 ) ;
}
}
static void
F_280 ( struct V_13 * V_14 )
{
T_38 V_562 ;
T_8 V_36 ;
T_47 V_688 ;
T_11 V_689 ;
T_12 V_191 ;
T_23 V_361 ;
T_9 V_37 ;
T_6 V_646 ;
T_4 V_38 ;
T_4 V_35 , V_564 ;
T_1 V_17 ;
struct V_53 * V_54 ;
struct V_92 * V_702 ;
static struct V_55 * V_56 ;
T_6 V_703 ;
unsigned long V_76 ;
F_13 ( V_42 L_294 , V_14 -> V_43 ) ;
F_220 ( V_14 ) ;
F_13 ( V_42 L_295 , V_14 -> V_43 ) ;
V_35 = 0xFFFF ;
while ( ! ( F_231 ( V_14 , & V_37 , & V_562 ,
V_695 , V_35 ) ) ) {
V_38 = F_21 ( V_37 . V_46 ) &
V_47 ;
if ( V_38 != V_48 ) {
F_13 ( V_42 L_296 \
L_297 ,
V_14 -> V_43 , V_38 ,
F_78 ( V_37 . V_281 ) ) ;
break;
}
V_35 = F_21 ( V_562 . V_199 ) ;
F_32 ( & V_14 -> V_94 , V_76 ) ;
V_702 = F_58 (
V_14 , F_18 ( V_562 . V_19 ) ) ;
F_33 ( & V_14 -> V_94 , V_76 ) ;
if ( V_702 )
F_279 ( V_14 , V_702 ,
V_35 ) ;
else {
F_13 ( V_42 L_298 \
L_299 , V_14 -> V_43 ,
V_35 , ( unsigned long long )
F_18 ( V_562 . V_19 ) ) ;
F_230 ( V_14 , V_35 ) ;
F_13 ( V_42 L_300 \
L_299 , V_14 -> V_43 ,
V_35 , ( unsigned long long )
F_18 ( V_562 . V_19 ) ) ;
}
}
F_13 ( V_42 L_301 ,
V_14 -> V_43 ) ;
if ( ! V_14 -> V_690 )
goto V_704;
F_13 ( V_42 L_302 , V_14 -> V_43 ) ;
V_646 = 0xFF ;
while ( ! ( F_93 ( V_14 , & V_37 ,
& V_191 , V_694 ,
V_646 ) ) ) {
V_38 = F_21 ( V_37 . V_46 ) &
V_47 ;
if ( V_38 != V_48 ) {
F_13 ( V_42 L_303\
L_297 ,
V_14 -> V_43 , V_38 ,
F_78 ( V_37 . V_281 ) ) ;
break;
}
V_646 = V_191 . V_198 ;
V_35 = F_21 ( V_191 . V_199 ) ;
V_54 = F_37 ( V_14 , V_35 ) ;
if ( V_54 ) {
F_41 ( V_54 ) ;
continue;
}
if ( F_24 ( V_14 , & V_37 ,
& V_36 , V_41 ,
V_35 ) != 0 )
continue;
V_38 = F_21 ( V_37 . V_46 ) &
V_47 ;
if ( V_38 != V_48 ) {
F_13 ( V_42 L_304 \
L_297 ,
V_14 -> V_43 , V_38 ,
F_78 ( V_37 . V_281 ) ) ;
break;
}
V_564 = F_21 ( V_36 . V_566 ) ;
if ( ! F_23 ( V_14 , V_564 ,
& V_17 ) ) {
F_13 ( V_42 L_305 \
L_306 ,
V_14 -> V_43 , V_35 , ( unsigned long long )
F_18 ( V_36 . V_19 ) ) ;
F_222 ( V_14 , V_17 ,
V_35 , V_36 . V_593 ,
V_546 ) ;
F_159 ( V_35 , V_14 -> V_137 ) ;
V_703 = 0 ;
while ( F_239 ( V_14 , V_35 , V_703 ++ ,
1 ) ) {
F_248 ( 1 ) ;
}
F_13 ( V_42 L_307 \
L_306 ,
V_14 -> V_43 , V_35 , ( unsigned long long )
F_18 ( V_36 . V_19 ) ) ;
}
}
F_13 ( V_42 L_308 ,
V_14 -> V_43 ) ;
F_13 ( V_42 L_309 , V_14 -> V_43 ) ;
V_35 = 0xFFFF ;
while ( ! ( F_272 ( V_14 , & V_37 ,
& V_688 , V_691 , V_35 ) ) ) {
V_38 = F_21 ( V_37 . V_46 ) &
V_47 ;
if ( V_38 != V_48 ) {
F_13 ( V_42 L_310 \
L_297 ,
V_14 -> V_43 , V_38 ,
F_78 ( V_37 . V_281 ) ) ;
break;
}
V_35 = F_21 ( V_688 . V_199 ) ;
F_32 ( & V_14 -> V_90 , V_76 ) ;
V_56 = F_53 ( V_14 ,
F_18 ( V_688 . V_692 ) ) ;
F_33 ( & V_14 -> V_90 , V_76 ) ;
if ( V_56 )
continue;
if ( F_82 ( V_14 , & V_37 ,
& V_689 , V_156 , V_35 ,
sizeof( T_11 ) ) )
continue;
V_38 = F_21 ( V_37 . V_46 ) &
V_47 ;
if ( V_38 != V_48 ) {
F_13 ( V_42 L_310 \
L_297 ,
V_14 -> V_43 , V_38 ,
F_78 ( V_37 . V_281 ) ) ;
break;
}
if ( V_689 . V_169 == V_170 ||
V_689 . V_169 == V_171 ||
V_689 . V_169 == V_173 ) {
memset ( & V_361 , 0 , sizeof( T_23 ) ) ;
V_361 . V_365 = V_656 ;
V_361 . V_368 = V_688 . V_199 ;
F_13 ( V_42
L_311 ,
V_14 -> V_43 , V_688 . V_199 ) ;
F_252 ( V_14 , & V_361 ) ;
F_13 ( V_42
L_312 ,
V_14 -> V_43 , V_688 . V_199 ) ;
}
}
F_13 ( V_42 L_313 ,
V_14 -> V_43 ) ;
V_704:
F_13 ( V_42 L_314 ,
V_14 -> V_43 ) ;
V_35 = 0xFFFF ;
while ( ! ( F_24 ( V_14 , & V_37 ,
& V_36 , V_687 ,
V_35 ) ) ) {
V_38 = F_21 ( V_37 . V_46 ) &
V_47 ;
if ( V_38 != V_48 ) {
F_13 ( V_42 L_315\
L_316 ,
V_14 -> V_43 , V_38 ,
F_78 ( V_37 . V_281 ) ) ;
break;
}
V_35 = F_21 ( V_36 . V_199 ) ;
if ( ! ( F_60 (
F_78 ( V_36 . V_146 ) ) ) )
continue;
V_54 = F_35 ( V_14 ,
F_18 ( V_36 . V_19 ) ) ;
if ( V_54 ) {
F_41 ( V_54 ) ;
continue;
}
V_564 = F_21 ( V_36 . V_566 ) ;
if ( ! F_23 ( V_14 , V_564 , & V_17 ) ) {
F_13 ( V_42 L_317 \
L_299 , V_14 -> V_43 ,
V_35 , ( unsigned long long )
F_18 ( V_36 . V_19 ) ) ;
F_222 ( V_14 , V_17 , V_35 ,
V_36 . V_593 , V_546 ) ;
V_703 = 0 ;
while ( F_239 ( V_14 , V_35 , V_703 ++ ,
0 ) ) {
F_248 ( 1 ) ;
}
F_13 ( V_42 L_318 \
L_299 , V_14 -> V_43 ,
V_35 , ( unsigned long long )
F_18 ( V_36 . V_19 ) ) ;
}
}
F_13 ( V_42 L_319 ,
V_14 -> V_43 ) ;
F_13 ( V_42 L_320 , V_14 -> V_43 ) ;
}
void
F_281 ( struct V_13 * V_14 , int V_705 )
{
switch ( V_705 ) {
case V_706 :
F_119 ( V_14 , F_13 ( V_42
L_321 , V_14 -> V_43 , V_44 ) ) ;
break;
case V_707 :
F_119 ( V_14 , F_13 ( V_42
L_322 , V_14 -> V_43 , V_44 ) ) ;
if ( V_14 -> V_570 . V_239 & V_244 ) {
V_14 -> V_570 . V_239 |= V_279 ;
F_172 ( V_14 , V_14 -> V_570 . V_102 ) ;
F_108 ( & V_14 -> V_570 . V_245 ) ;
}
if ( V_14 -> V_238 . V_239 & V_244 ) {
V_14 -> V_238 . V_239 |= V_279 ;
F_172 ( V_14 , V_14 -> V_238 . V_102 ) ;
F_108 ( & V_14 -> V_238 . V_245 ) ;
}
F_147 ( V_14 ) ;
F_183 ( V_14 ) ;
break;
case V_708 :
F_119 ( V_14 , F_13 ( V_42
L_323 , V_14 -> V_43 , V_44 ) ) ;
if ( ( ! V_14 -> V_57 ) && ! ( V_645 > 0 &&
! V_14 -> V_39 . V_40 ) ) {
F_267 ( V_14 ) ;
F_269 ( V_14 ) ;
F_271 ( V_14 ) ;
F_274 ( V_14 ) ;
F_143 ( V_14 ) ;
}
break;
}
}
static void
F_282 ( struct V_13 * V_14 , struct V_3 * V_7 )
{
F_141 ( V_14 , V_7 ) ;
if ( V_14 -> V_261 || V_14 -> V_262 ) {
F_6 ( V_7 ) ;
return;
}
switch ( V_7 -> V_305 ) {
case V_306 :
F_283 ( V_14 ,
(struct V_303 * )
V_7 -> V_304 ) ;
break;
case V_307 :
while ( F_284 ( V_14 -> V_113 ) ||
V_14 -> V_82 ) {
if ( V_14 -> V_261 )
goto V_89;
F_248 ( 1 ) ;
}
F_275 ( V_14 ) ;
F_280 ( V_14 ) ;
break;
case V_308 :
V_14 -> V_709 = 0 ;
if ( V_710 [ 0 ] != - 1 && V_710 [ 1 ] != - 1 )
F_285 ( V_14 , V_710 [ 0 ] ,
V_710 [ 1 ] ) ;
F_46 ( V_14 , F_13 ( V_42
L_324 ,
V_14 -> V_43 ) ) ;
break;
case V_502 :
F_203 ( V_14 , V_7 -> V_503 ) ;
break;
case V_356 :
F_241 ( V_14 , V_7 ) ;
break;
case V_512 :
F_243 ( V_14 , V_7 ) ;
break;
case V_711 :
F_247 ( V_14 , V_7 ) ;
break;
case V_712 :
F_246 ( V_14 , V_7 ) ;
break;
case V_713 :
F_245 ( V_14 ,
V_7 ) ;
break;
case V_714 :
F_262 ( V_14 , V_7 ) ;
break;
case V_715 :
F_263 ( V_14 , V_7 ) ;
break;
case V_716 :
F_264 ( V_14 , V_7 ) ;
break;
case V_717 :
F_266 ( V_14 , V_7 ) ;
break;
}
V_89:
F_6 ( V_7 ) ;
}
static void
V_302 ( struct V_718 * V_301 )
{
struct V_3 * V_7 = F_3 ( V_301 ,
struct V_3 , V_301 ) ;
F_282 ( V_7 -> V_14 , V_7 ) ;
}
T_6
F_286 ( struct V_13 * V_14 , T_6 V_236 ,
T_10 V_237 )
{
struct V_3 * V_7 ;
T_31 * V_37 ;
T_4 V_305 ;
T_4 V_192 ;
if ( V_14 -> V_261 || V_14 -> V_262 )
return 1 ;
V_37 = F_107 ( V_14 , V_237 ) ;
if ( F_163 ( ! V_37 ) ) {
F_25 ( V_42 L_99 ,
V_14 -> V_43 , __FILE__ , __LINE__ , V_44 ) ;
return 1 ;
}
V_305 = F_21 ( V_37 -> V_511 ) ;
if ( V_305 != V_719 )
F_287 ( V_14 , V_305 , 0 ) ;
switch ( V_305 ) {
case V_712 :
{
T_41 * V_720 =
( T_41 * )
V_37 -> V_509 ;
if ( V_720 -> V_721 !=
V_722 )
return 1 ;
if ( V_14 -> V_642 ) {
V_14 -> V_641 ++ ;
return 1 ;
} else
V_14 -> V_642 = 1 ;
break;
}
case V_356 :
F_173 ( V_14 ,
( T_19 * )
V_37 -> V_509 ) ;
break;
case V_714 :
F_178 ( V_14 ,
( T_22 * )
V_37 -> V_509 ) ;
break;
case V_715 :
F_181 ( V_14 ,
( T_24 * )
V_37 -> V_509 ) ;
break;
case V_719 :
{
T_48 * V_723 ;
T_10 * V_724 ;
if ( ! V_14 -> V_134 )
break;
V_723 = ( T_48 * )
V_37 -> V_509 ;
V_724 = ( T_10 * ) V_723 -> V_725 ;
if ( F_21 ( V_723 -> V_726 )
!= V_727 )
break;
switch ( F_78 ( * V_724 ) ) {
case V_728 :
F_91 ( V_42 L_325
L_326
L_327
L_328 , V_14 -> V_43 ) ;
break;
case V_729 :
F_91 ( V_42 L_325
L_329
L_330
L_331 , V_14 -> V_43 ) ;
break;
case V_730 :
F_25 ( V_42 L_332
L_333
L_334
L_335
L_331 , V_14 -> V_43 ) ;
break;
case V_731 :
F_25 ( V_42 L_332
L_336
L_337
L_338 ,
V_14 -> V_43 ) ;
break;
}
break;
}
case V_512 :
case V_717 :
case V_711 :
case V_713 :
case V_716 :
break;
case V_732 :
F_182 ( V_14 ,
( T_25 * )
V_37 -> V_509 ) ;
break;
default:
return 1 ;
}
V_192 = F_21 ( V_37 -> V_513 ) * 4 ;
V_7 = F_8 ( V_192 ) ;
if ( ! V_7 ) {
F_25 ( V_42 L_2 ,
V_14 -> V_43 , __FILE__ , __LINE__ , V_44 ) ;
return 1 ;
}
memcpy ( V_7 -> V_304 , V_37 -> V_509 , V_192 ) ;
V_7 -> V_14 = V_14 ;
V_7 -> V_733 = V_37 -> V_733 ;
V_7 -> V_734 = V_37 -> V_734 ;
V_7 -> V_305 = V_305 ;
F_137 ( V_14 , V_7 ) ;
F_6 ( V_7 ) ;
return 1 ;
}
static void
F_235 ( struct V_13 * V_14 ,
struct V_92 * V_93 )
{
struct V_315 * V_316 , * V_346 ;
F_277 (mpt3sas_port, next,
&sas_expander->sas_port_list, port_list) {
if ( V_14 -> V_82 )
return;
if ( V_316 -> V_318 . V_319 ==
V_320 )
F_44 ( V_14 ,
V_316 -> V_318 . V_17 ) ;
else if ( V_316 -> V_318 . V_319 ==
V_322 ||
V_316 -> V_318 . V_319 ==
V_323 )
F_234 ( V_14 ,
V_316 -> V_318 . V_17 ) ;
}
F_49 ( V_14 , V_93 -> V_17 ,
V_93 -> V_84 ) ;
F_13 ( V_42
L_339 ,
V_14 -> V_43 ,
V_93 -> V_35 , ( unsigned long long )
V_93 -> V_17 ) ;
F_2 ( V_93 -> V_218 ) ;
F_2 ( V_93 ) ;
}
static void
F_288 ( struct V_13 * V_14 )
{
T_43 * V_253 ;
T_44 * V_37 ;
T_4 V_102 ;
if ( ! V_14 -> V_690 )
return;
if ( F_39 ( & V_14 -> V_91 ) )
return;
F_113 ( & V_14 -> V_570 . V_258 ) ;
if ( V_14 -> V_570 . V_239 != V_240 ) {
F_25 ( V_42 L_243 ,
V_14 -> V_43 , V_44 ) ;
goto V_89;
}
V_14 -> V_570 . V_239 = V_244 ;
V_102 = F_164 ( V_14 , V_14 -> V_649 ) ;
if ( ! V_102 ) {
F_25 ( V_42 L_49 ,
V_14 -> V_43 , V_44 ) ;
V_14 -> V_570 . V_239 = V_240 ;
goto V_89;
}
V_253 = F_120 ( V_14 , V_102 ) ;
V_14 -> V_570 . V_102 = V_102 ;
memset ( V_253 , 0 , sizeof( T_43 ) ) ;
V_253 -> V_272 = V_650 ;
V_253 -> V_493 = V_735 ;
if ( ! V_14 -> V_217 )
F_13 ( V_42 L_340 , V_14 -> V_43 ) ;
F_123 ( & V_14 -> V_570 . V_245 ) ;
F_165 ( V_14 , V_102 ) ;
F_125 ( & V_14 -> V_570 . V_245 , 10 * V_278 ) ;
if ( ! ( V_14 -> V_570 . V_239 & V_241 ) ) {
F_25 ( V_42 L_51 ,
V_14 -> V_43 , V_44 ) ;
goto V_89;
}
if ( V_14 -> V_570 . V_239 & V_243 ) {
V_37 = V_14 -> V_570 . V_237 ;
if ( ! V_14 -> V_217 )
F_13 ( V_42 L_341
L_342 ,
V_14 -> V_43 , F_21 ( V_37 -> V_46 ) ,
F_78 ( V_37 -> V_281 ) ) ;
}
V_89:
V_14 -> V_570 . V_239 = V_240 ;
F_128 ( & V_14 -> V_570 . V_258 ) ;
}
void F_289 ( struct V_736 * V_506 )
{
struct V_112 * V_113 = F_290 ( V_506 ) ;
struct V_13 * V_14 = F_67 ( V_113 ) ;
struct V_315 * V_316 , * V_737 ;
struct V_55 * V_56 , * V_346 ;
struct V_72 * V_118 ;
struct V_738 * V_739 ;
unsigned long V_76 ;
V_14 -> V_261 = 1 ;
F_147 ( V_14 ) ;
F_32 ( & V_14 -> V_299 , V_76 ) ;
V_739 = V_14 -> V_298 ;
V_14 -> V_298 = NULL ;
F_33 ( & V_14 -> V_299 , V_76 ) ;
if ( V_739 )
F_291 ( V_739 ) ;
F_288 ( V_14 ) ;
F_277 (raid_device, next, &ioc->raid_device_list,
list) {
if ( V_56 -> V_85 ) {
V_118 =
V_56 -> V_85 -> V_120 ;
V_118 -> V_334 = 1 ;
F_255 ( & V_56 -> V_85 -> V_127 ) ;
}
F_13 ( V_42 L_252 ,
V_14 -> V_43 , V_56 -> V_35 ,
( unsigned long long ) V_56 -> V_60 ) ;
F_55 ( V_14 , V_56 ) ;
}
F_277 (mpt3sas_port, next_port,
&ioc->sas_hba.sas_port_list, port_list) {
if ( V_316 -> V_318 . V_319 ==
V_320 )
F_44 ( V_14 ,
V_316 -> V_318 . V_17 ) ;
else if ( V_316 -> V_318 . V_319 ==
V_322 ||
V_316 -> V_318 . V_319 ==
V_323 )
F_234 ( V_14 ,
V_316 -> V_318 . V_17 ) ;
}
if ( V_14 -> V_39 . V_40 ) {
F_2 ( V_14 -> V_39 . V_218 ) ;
V_14 -> V_39 . V_218 = NULL ;
V_14 -> V_39 . V_40 = 0 ;
}
F_292 ( V_113 ) ;
F_293 ( V_113 ) ;
F_294 ( V_14 ) ;
F_14 ( & V_16 ) ;
F_56 ( & V_14 -> V_81 ) ;
F_16 ( & V_16 ) ;
F_295 ( V_113 ) ;
}
void
F_296 ( struct V_736 * V_506 )
{
struct V_112 * V_113 = F_290 ( V_506 ) ;
struct V_13 * V_14 = F_67 ( V_113 ) ;
struct V_738 * V_739 ;
unsigned long V_76 ;
V_14 -> V_261 = 1 ;
F_147 ( V_14 ) ;
F_32 ( & V_14 -> V_299 , V_76 ) ;
V_739 = V_14 -> V_298 ;
V_14 -> V_298 = NULL ;
F_33 ( & V_14 -> V_299 , V_76 ) ;
if ( V_739 )
F_291 ( V_739 ) ;
F_288 ( V_14 ) ;
F_294 ( V_14 ) ;
}
static void
F_297 ( struct V_13 * V_14 )
{
T_6 V_52 ;
void * V_51 ;
struct V_53 * V_54 ;
struct V_55 * V_56 ;
T_4 V_35 ;
T_1 V_84 ;
T_1 V_17 ;
unsigned long V_76 ;
int V_28 ;
if ( ! V_14 -> V_58 . V_59 )
return;
V_51 = NULL ;
V_52 = 0 ;
if ( V_14 -> V_61 . V_51 ) {
V_51 = V_14 -> V_61 . V_51 ;
V_52 = V_14 -> V_61 . V_52 ;
} else if ( V_14 -> V_66 . V_51 ) {
V_51 = V_14 -> V_66 . V_51 ;
V_52 = V_14 -> V_66 . V_52 ;
} else if ( V_14 -> V_69 . V_51 ) {
V_51 = V_14 -> V_69 . V_51 ;
V_52 = V_14 -> V_69 . V_52 ;
}
if ( ! V_51 )
return;
if ( V_52 ) {
V_56 = V_51 ;
V_28 = F_253 ( V_14 -> V_113 , V_133 ,
V_56 -> V_87 , 0 ) ;
if ( V_28 )
F_55 ( V_14 , V_56 ) ;
} else {
F_32 ( & V_14 -> V_74 , V_76 ) ;
V_54 = V_51 ;
V_35 = V_54 -> V_35 ;
V_84 = V_54 -> V_84 ;
V_17 = V_54 -> V_17 ;
F_278 ( & V_54 -> V_81 , & V_14 -> V_83 ) ;
F_33 ( & V_14 -> V_74 , V_76 ) ;
if ( V_14 -> V_603 )
return;
if ( ! F_48 ( V_14 , V_35 ,
V_84 ) ) {
F_38 ( V_14 , V_54 ) ;
} else if ( ! V_54 -> V_85 ) {
if ( ! V_14 -> V_57 ) {
F_49 ( V_14 ,
V_17 ,
V_84 ) ;
F_38 ( V_14 , V_54 ) ;
}
}
}
}
static void
F_298 ( struct V_13 * V_14 )
{
struct V_55 * V_56 , * V_740 ;
int V_28 ;
F_277 (raid_device, raid_next,
&ioc->raid_device_list, list) {
if ( V_56 -> V_85 )
continue;
V_28 = F_253 ( V_14 -> V_113 , V_133 ,
V_56 -> V_87 , 0 ) ;
if ( V_28 )
F_55 ( V_14 , V_56 ) ;
}
}
static struct V_53 * F_299 ( struct V_13 * V_14 )
{
struct V_53 * V_54 = NULL ;
unsigned long V_76 ;
F_32 ( & V_14 -> V_74 , V_76 ) ;
if ( ! F_39 ( & V_14 -> V_86 ) ) {
V_54 = F_146 ( & V_14 -> V_86 ,
struct V_53 , V_81 ) ;
F_30 ( V_54 ) ;
}
F_33 ( & V_14 -> V_74 , V_76 ) ;
return V_54 ;
}
static void F_300 ( struct V_13 * V_14 ,
struct V_53 * V_54 )
{
unsigned long V_76 ;
F_32 ( & V_14 -> V_74 , V_76 ) ;
if ( ! F_39 ( & V_54 -> V_81 ) ) {
F_40 ( & V_54 -> V_81 ) ;
F_41 ( V_54 ) ;
}
F_30 ( V_54 ) ;
F_47 ( & V_54 -> V_81 , & V_14 -> V_83 ) ;
F_33 ( & V_14 -> V_74 , V_76 ) ;
}
static void
F_301 ( struct V_13 * V_14 )
{
struct V_53 * V_54 ;
if ( V_14 -> V_603 )
return;
while ( ( V_54 = F_299 ( V_14 ) ) ) {
if ( ! F_48 ( V_14 , V_54 -> V_35 ,
V_54 -> V_84 ) ) {
F_38 ( V_14 , V_54 ) ;
F_41 ( V_54 ) ;
continue;
} else if ( ! V_54 -> V_85 ) {
if ( ! V_14 -> V_57 ) {
F_49 ( V_14 ,
V_54 -> V_17 ,
V_54 -> V_84 ) ;
F_38 ( V_14 , V_54 ) ;
F_41 ( V_54 ) ;
continue;
}
}
F_300 ( V_14 , V_54 ) ;
F_41 ( V_54 ) ;
}
}
static void
F_302 ( struct V_13 * V_14 )
{
T_4 V_741 ;
if ( ! ( V_14 -> V_201 . V_742 & V_743 ) )
return;
F_297 ( V_14 ) ;
if ( V_14 -> V_690 ) {
V_741 =
F_21 ( V_14 -> V_744 . V_745 ) &
V_746 ;
if ( V_741 ==
V_747 ) {
F_298 ( V_14 ) ;
F_301 ( V_14 ) ;
} else {
F_301 ( V_14 ) ;
F_298 ( V_14 ) ;
}
} else
F_301 ( V_14 ) ;
}
void
F_303 ( struct V_112 * V_113 )
{
struct V_13 * V_14 = F_67 ( V_113 ) ;
int V_28 ;
if ( V_748 != - 1 && V_748 != 0 )
F_304 ( V_14 , V_748 ) ;
if ( V_645 > 0 )
return;
V_14 -> V_709 = 1 ;
V_28 = F_305 ( V_14 ) ;
if ( V_28 != 0 )
F_13 ( V_42 L_343 , V_14 -> V_43 ) ;
}
int
F_306 ( struct V_112 * V_113 , unsigned long time )
{
struct V_13 * V_14 = F_67 ( V_113 ) ;
if ( V_645 > 0 ) {
V_14 -> V_57 = 0 ;
V_14 -> V_602 = 0 ;
return 1 ;
}
if ( time >= ( 300 * V_278 ) ) {
V_14 -> V_749 . V_239 = V_240 ;
F_13 ( V_42
L_344 ,
V_14 -> V_43 ) ;
V_14 -> V_57 = 0 ;
return 1 ;
}
if ( V_14 -> V_709 )
return 0 ;
if ( V_14 -> V_750 ) {
F_13 ( V_42
L_345 ,
V_14 -> V_43 , V_14 -> V_750 ) ;
V_14 -> V_57 = 0 ;
V_14 -> V_602 = 0 ;
V_14 -> V_261 = 1 ;
return 1 ;
}
F_13 ( V_42 L_346 , V_14 -> V_43 ) ;
V_14 -> V_749 . V_239 = V_240 ;
if ( V_14 -> V_602 ) {
V_14 -> V_602 = 0 ;
F_302 ( V_14 ) ;
}
F_307 ( V_14 ) ;
V_14 -> V_57 = 0 ;
return 1 ;
}
T_4
F_308 ( struct V_736 * V_506 )
{
switch ( V_506 -> V_51 ) {
case V_751 :
case V_752 :
case V_753 :
case V_754 :
case V_755 :
case V_756 :
case V_757 :
case V_758 :
case V_759 :
case V_760 :
case V_761 :
case V_762 :
case V_763 :
case V_764 :
case V_765 :
case V_766 :
case V_767 :
return V_160 ;
case V_768 :
case V_769 :
case V_770 :
case V_771 :
case V_772 :
case V_773 :
return V_162 ;
}
return 0 ;
}
int
F_309 ( struct V_736 * V_506 , const struct V_774 * V_87 )
{
struct V_13 * V_14 ;
struct V_112 * V_113 = NULL ;
int V_775 ;
T_4 V_776 ;
V_776 = F_308 ( V_506 ) ;
if ( V_776 == 0 )
return - V_777 ;
if ( ( V_778 == 1 ) && ( V_776 != V_160 ) )
return - V_777 ;
if ( ( V_778 == 2 ) && ( V_776 != V_162 ) )
return - V_777 ;
switch ( V_776 ) {
case V_160 :
V_113 = F_310 ( & V_779 ,
sizeof( struct V_13 ) ) ;
if ( ! V_113 )
return - V_777 ;
V_14 = F_67 ( V_113 ) ;
memset ( V_14 , 0 , sizeof( struct V_13 ) ) ;
V_14 -> V_159 = V_776 ;
V_14 -> V_87 = V_780 ++ ;
sprintf ( V_14 -> V_781 , L_347 , V_782 ) ;
if ( V_506 -> V_51 == V_751 ) {
V_14 -> V_134 = 1 ;
V_14 -> V_217 = 1 ;
} else
V_14 -> V_783 = V_784 ;
break;
case V_162 :
V_113 = F_310 ( & V_785 ,
sizeof( struct V_13 ) ) ;
if ( ! V_113 )
return - V_777 ;
V_14 = F_67 ( V_113 ) ;
memset ( V_14 , 0 , sizeof( struct V_13 ) ) ;
V_14 -> V_159 = V_776 ;
V_14 -> V_87 = V_786 ++ ;
sprintf ( V_14 -> V_781 , L_347 , V_787 ) ;
if ( V_506 -> V_788 >= V_789 )
V_14 -> V_790 = 1 ;
break;
default:
return - V_777 ;
}
F_138 ( & V_14 -> V_81 ) ;
F_14 ( & V_16 ) ;
F_47 ( & V_14 -> V_81 , & V_791 ) ;
F_16 ( & V_16 ) ;
V_14 -> V_113 = V_113 ;
V_14 -> V_506 = V_506 ;
V_14 -> V_423 = V_423 ;
V_14 -> V_270 = V_270 ;
V_14 -> V_792 = V_792 ;
V_14 -> V_793 = V_793 ;
V_14 -> V_794 = V_794 ;
V_14 -> V_795 = V_795 ;
V_14 -> V_649 = V_649 ;
V_14 -> V_796 = V_796 ;
V_14 -> V_335 = V_335 ;
V_14 -> V_344 = V_344 ;
V_14 -> V_340 = V_340 ;
V_14 -> V_15 = V_15 ;
V_14 -> V_797 = & F_183 ;
F_311 ( & V_14 -> V_798 ) ;
F_311 ( & V_14 -> V_799 ) ;
F_312 ( & V_14 -> V_800 ) ;
F_312 ( & V_14 -> V_105 ) ;
F_312 ( & V_14 -> V_74 ) ;
F_312 ( & V_14 -> V_94 ) ;
F_312 ( & V_14 -> V_299 ) ;
F_312 ( & V_14 -> V_90 ) ;
F_312 ( & V_14 -> V_801 ) ;
F_138 ( & V_14 -> V_83 ) ;
F_138 ( & V_14 -> V_86 ) ;
F_138 ( & V_14 -> V_95 ) ;
F_138 ( & V_14 -> V_300 ) ;
F_138 ( & V_14 -> V_91 ) ;
F_138 ( & V_14 -> V_39 . V_569 ) ;
F_138 ( & V_14 -> V_336 ) ;
F_138 ( & V_14 -> V_345 ) ;
F_138 ( & V_14 -> V_802 ) ;
sprintf ( V_14 -> V_43 , L_348 , V_14 -> V_781 , V_14 -> V_87 ) ;
V_113 -> V_803 = 32 ;
V_113 -> V_804 = V_804 ;
V_113 -> V_805 = V_806 ;
V_113 -> V_807 = V_14 -> V_87 ;
if ( V_808 != 0xFFFF ) {
if ( V_808 < 64 ) {
V_113 -> V_808 = 64 ;
F_91 ( V_42 L_349 \
L_350
L_351 , V_14 -> V_43 , V_808 ) ;
} else if ( V_808 > 32767 ) {
V_113 -> V_808 = 32767 ;
F_91 ( V_42 L_349 \
L_350
L_352 , V_14 -> V_43 ,
V_808 ) ;
} else {
V_113 -> V_808 = V_808 & 0xFFFE ;
F_13 ( V_42
L_353 ,
V_14 -> V_43 , V_113 -> V_808 ) ;
}
}
if ( V_809 > 0 )
F_313 ( V_113 , V_809 ) ;
else
F_313 ( V_113 , V_810
| V_811
| V_812 ) ;
F_314 ( V_113 , V_813 ) ;
snprintf ( V_14 -> V_814 , sizeof( V_14 -> V_814 ) ,
L_354 , V_14 -> V_781 , V_14 -> V_87 ) ;
V_14 -> V_298 = F_315 (
V_14 -> V_814 , V_815 ) ;
if ( ! V_14 -> V_298 ) {
F_25 ( V_42 L_2 ,
V_14 -> V_43 , __FILE__ , __LINE__ , V_44 ) ;
V_775 = - V_777 ;
goto V_816;
}
V_14 -> V_57 = 1 ;
if ( ( F_316 ( V_14 ) ) ) {
F_25 ( V_42 L_2 ,
V_14 -> V_43 , __FILE__ , __LINE__ , V_44 ) ;
V_775 = - V_777 ;
goto V_817;
}
if ( V_14 -> V_134 ) {
if ( V_14 -> V_783 == V_784 )
V_14 -> V_603 = 0 ;
else if ( V_14 -> V_783 == V_818 )
V_14 -> V_603 = 1 ;
else {
if ( F_317 ( V_14 ) )
V_14 -> V_603 = 1 ;
else
V_14 -> V_603 = 0 ;
}
} else
V_14 -> V_603 = 0 ;
V_775 = F_318 ( V_113 , & V_506 -> V_127 ) ;
if ( V_775 ) {
F_25 ( V_42 L_2 ,
V_14 -> V_43 , __FILE__ , __LINE__ , V_44 ) ;
goto V_819;
}
F_319 ( V_113 ) ;
return 0 ;
V_819:
F_294 ( V_14 ) ;
V_817:
F_291 ( V_14 -> V_298 ) ;
V_816:
F_14 ( & V_16 ) ;
F_56 ( & V_14 -> V_81 ) ;
F_16 ( & V_16 ) ;
F_295 ( V_113 ) ;
return V_775 ;
}
int
F_320 ( struct V_736 * V_506 , T_49 V_166 )
{
struct V_112 * V_113 = F_290 ( V_506 ) ;
struct V_13 * V_14 = F_67 ( V_113 ) ;
T_50 V_820 ;
F_321 ( V_14 ) ;
F_322 () ;
F_323 ( V_113 ) ;
V_820 = F_324 ( V_506 , V_166 ) ;
F_13 ( V_42
L_355 ,
V_14 -> V_43 , V_506 , F_325 ( V_506 ) , V_820 ) ;
F_326 ( V_506 ) ;
F_327 ( V_14 ) ;
F_328 ( V_506 , V_820 ) ;
return 0 ;
}
int
F_329 ( struct V_736 * V_506 )
{
struct V_112 * V_113 = F_290 ( V_506 ) ;
struct V_13 * V_14 = F_67 ( V_113 ) ;
T_50 V_820 = V_506 -> V_821 ;
int V_2 ;
F_13 ( V_42
L_356 ,
V_14 -> V_43 , V_506 , F_325 ( V_506 ) , V_820 ) ;
F_328 ( V_506 , V_822 ) ;
F_330 ( V_506 , V_822 , 0 ) ;
F_331 ( V_506 ) ;
V_14 -> V_506 = V_506 ;
V_2 = F_332 ( V_14 ) ;
if ( V_2 )
return V_2 ;
F_116 ( V_14 , V_264 , V_823 ) ;
F_333 ( V_113 ) ;
F_307 ( V_14 ) ;
return 0 ;
}
T_51
F_334 ( struct V_736 * V_506 , T_52 V_166 )
{
struct V_112 * V_113 = F_290 ( V_506 ) ;
struct V_13 * V_14 = F_67 ( V_113 ) ;
F_13 ( V_42 L_357 ,
V_14 -> V_43 , V_166 ) ;
switch ( V_166 ) {
case V_824 :
return V_825 ;
case V_826 :
V_14 -> V_262 = 1 ;
F_323 ( V_14 -> V_113 ) ;
F_321 ( V_14 ) ;
F_327 ( V_14 ) ;
return V_827 ;
case V_828 :
V_14 -> V_262 = 1 ;
F_321 ( V_14 ) ;
F_183 ( V_14 ) ;
return V_829 ;
}
return V_827 ;
}
T_51
F_335 ( struct V_736 * V_506 )
{
struct V_112 * V_113 = F_290 ( V_506 ) ;
struct V_13 * V_14 = F_67 ( V_113 ) ;
int V_28 ;
F_13 ( V_42 L_358 ,
V_14 -> V_43 ) ;
V_14 -> V_262 = 0 ;
V_14 -> V_506 = V_506 ;
F_331 ( V_506 ) ;
V_28 = F_332 ( V_14 ) ;
if ( V_28 )
return V_829 ;
V_28 = F_116 ( V_14 , V_264 ,
V_265 ) ;
F_91 ( V_42 L_359 , V_14 -> V_43 ,
( V_28 == 0 ) ? L_118 : L_360 ) ;
if ( ! V_28 )
return V_830 ;
else
return V_829 ;
}
void
F_336 ( struct V_736 * V_506 )
{
struct V_112 * V_113 = F_290 ( V_506 ) ;
struct V_13 * V_14 = F_67 ( V_113 ) ;
F_13 ( V_42 L_361 , V_14 -> V_43 ) ;
F_337 ( V_506 ) ;
F_307 ( V_14 ) ;
F_333 ( V_14 -> V_113 ) ;
}
T_51
F_338 ( struct V_736 * V_506 )
{
struct V_112 * V_113 = F_290 ( V_506 ) ;
struct V_13 * V_14 = F_67 ( V_113 ) ;
F_13 ( V_42 L_362 ,
V_14 -> V_43 ) ;
return V_827 ;
}
int
F_339 ( void )
{
V_780 = 0 ;
V_786 = 0 ;
F_340 () ;
V_423 = F_341 ( F_211 ) ;
V_270 = F_341 ( F_105 ) ;
V_793 = F_341 ( V_831 ) ;
V_794 = F_341 (
V_832 ) ;
V_795 = F_341 (
V_833 ) ;
V_649 = F_341 ( F_236 ) ;
V_796 = F_341 (
V_834 ) ;
V_792 = F_341 ( V_835 ) ;
V_335 = F_341 (
F_162 ) ;
V_344 = F_341 (
F_170 ) ;
V_340 = F_341 (
F_167 ) ;
return 0 ;
}
void
F_342 ( void )
{
F_343 ( V_423 ) ;
F_343 ( V_270 ) ;
F_343 ( V_793 ) ;
F_343 ( V_794 ) ;
F_343 ( V_795 ) ;
F_343 ( V_649 ) ;
F_343 ( V_796 ) ;
F_343 ( V_792 ) ;
F_343 ( V_335 ) ;
F_343 ( V_344 ) ;
F_343 ( V_340 ) ;
if ( V_778 != 1 )
F_344 ( V_163 ) ;
if ( V_778 != 2 )
F_344 ( V_161 ) ;
F_345 ( V_806 ) ;
}
static int T_53
F_346 ( void )
{
int error ;
F_13 ( L_363 , V_787 ,
V_836 ) ;
V_806 =
F_347 ( & V_837 ) ;
if ( ! V_806 )
return - V_777 ;
if ( V_778 != 1 ) {
V_163 =
F_348 ( & V_838 ) ;
if ( ! V_163 ) {
F_345 ( V_806 ) ;
return - V_777 ;
}
}
if ( V_778 != 2 ) {
V_161 =
F_348 ( & V_839 ) ;
if ( ! V_161 ) {
F_345 ( V_806 ) ;
return - V_777 ;
}
}
error = F_339 () ;
if ( error ) {
F_342 () ;
return error ;
}
F_349 ( V_778 ) ;
error = F_350 ( & V_840 ) ;
if ( error )
F_342 () ;
return error ;
}
static void T_54
F_351 ( void )
{
F_13 ( L_364 ,
V_836 ) ;
F_352 ( & V_840 ) ;
F_353 ( V_778 ) ;
F_342 () ;
}
