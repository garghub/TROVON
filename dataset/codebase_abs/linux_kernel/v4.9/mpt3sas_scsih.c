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
static int
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
static int
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
if ( V_14 -> V_134 )
V_118 -> V_56 = V_56 ;
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
static void
F_73 ( struct V_126 * V_85 )
{
struct V_112 * V_113 = F_70 ( & V_85 -> V_127 ) ;
struct V_13 * V_14 = F_67 ( V_113 ) ;
struct V_72 * V_118 ;
struct V_53 * V_54 ;
struct V_55 * V_56 ;
unsigned long V_76 ;
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
static int
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
static void
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
static int
F_79 ( struct V_51 * V_127 )
{
struct V_110 * V_75 = F_80 ( V_127 ) ;
struct V_13 * V_14 = F_67 ( V_75 -> V_114 ) ;
if ( V_14 -> V_134 )
return 0 ;
return ( V_75 -> V_88 == V_133 ) ? 1 : 0 ;
}
static void
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
switch ( V_14 -> V_159 ) {
case V_160 :
F_83 ( V_161 , V_127 , V_155 ) ;
break;
case V_162 :
case V_163 :
F_83 ( V_164 , V_127 , V_155 ) ;
break;
}
}
static void
F_84 ( struct V_51 * V_127 )
{
struct V_110 * V_75 = F_80 ( V_127 ) ;
struct V_13 * V_14 = F_67 ( V_75 -> V_114 ) ;
static struct V_55 * V_56 ;
unsigned long V_76 ;
T_11 V_153 ;
T_9 V_37 ;
T_10 V_165 ;
enum V_166 V_167 = V_168 ;
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
V_165 = F_78 ( V_153 . V_157 ) ;
if ( V_165 & V_158 ) {
V_167 = V_169 ;
goto V_89;
}
switch ( V_153 . V_170 ) {
case V_171 :
case V_172 :
V_167 = V_173 ;
break;
case V_174 :
V_167 = V_175 ;
break;
case V_176 :
case V_177 :
V_167 = V_178 ;
break;
}
V_89:
switch ( V_14 -> V_159 ) {
case V_160 :
F_85 ( V_161 , V_127 , V_167 ) ;
break;
case V_162 :
case V_163 :
F_85 ( V_164 , V_127 , V_167 ) ;
break;
}
}
static void
F_86 ( struct V_13 * V_14 ,
struct V_110 * V_75 , T_6 V_179 )
{
enum V_180 V_181 = V_182 ;
switch ( V_179 ) {
case V_183 :
V_181 = V_184 ;
break;
case V_185 :
V_181 = V_186 ;
break;
case V_187 :
V_181 = V_188 ;
break;
case V_189 :
V_181 = V_190 ;
break;
}
switch ( V_14 -> V_159 ) {
case V_160 :
F_87 ( V_161 ,
& V_75 -> V_191 , V_181 ) ;
break;
case V_162 :
case V_163 :
F_87 ( V_164 ,
& V_75 -> V_191 , V_181 ) ;
break;
}
}
static int
F_88 ( struct V_13 * V_14 ,
struct V_55 * V_56 )
{
T_11 * V_153 ;
T_12 V_192 ;
T_8 V_36 ;
T_9 V_37 ;
T_4 V_193 ;
T_6 V_194 ;
if ( ( F_89 ( V_14 , V_56 -> V_35 ,
& V_194 ) ) || ! V_194 ) {
F_90 ( V_14 , F_91 ( V_42
L_2 , V_14 -> V_43 , __FILE__ , __LINE__ ,
V_44 ) ) ;
return 1 ;
}
V_56 -> V_194 = V_194 ;
V_193 = F_92 ( T_11 , V_195 ) + ( V_194 *
sizeof( V_196 ) ) ;
V_153 = F_9 ( V_193 , V_130 ) ;
if ( ! V_153 ) {
F_90 ( V_14 , F_91 ( V_42
L_2 , V_14 -> V_43 , __FILE__ , __LINE__ ,
V_44 ) ) ;
return 1 ;
}
if ( ( F_82 ( V_14 , & V_37 , V_153 ,
V_156 , V_56 -> V_35 , V_193 ) ) ) {
F_90 ( V_14 , F_91 ( V_42
L_2 , V_14 -> V_43 , __FILE__ , __LINE__ ,
V_44 ) ) ;
F_2 ( V_153 ) ;
return 1 ;
}
V_56 -> V_179 = V_153 -> V_197 ;
if ( ! ( F_93 ( V_14 , & V_37 ,
& V_192 , V_198 ,
V_153 -> V_195 [ 0 ] . V_199 ) ) ) {
if ( ! ( F_24 ( V_14 , & V_37 ,
& V_36 , V_41 ,
F_21 ( V_192 . V_200 ) ) ) ) {
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
if ( V_75 -> type != V_201 )
return;
if ( ! ( V_14 -> V_202 . V_203 & V_204 ) )
return;
F_95 ( V_75 ) ;
F_75 ( V_144 , V_75 , L_19 ,
F_96 ( V_75 ) ? L_20 : L_21 ) ;
return;
}
static int
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
T_6 V_205 = 0 ;
char * V_206 = L_22 ;
char * V_207 = L_22 ;
T_4 V_35 , V_208 = 0 ;
T_1 V_209 = 0 ;
V_111 = 1 ;
V_117 = V_75 -> V_120 ;
V_117 -> V_210 = 1 ;
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
V_111 = V_211 ;
V_206 = L_23 ;
} else {
V_111 = V_124 ;
if ( V_56 -> V_96 &
V_100 )
V_206 = L_24 ;
else
V_206 = L_25 ;
}
switch ( V_56 -> V_179 ) {
case V_183 :
V_207 = L_26 ;
break;
case V_187 :
V_111 = V_212 ;
if ( V_14 -> V_213 . V_214 &&
( F_78 ( V_14 -> V_213 . V_215 ) &
V_216 ) &&
! ( V_56 -> V_194 % 2 ) )
V_207 = L_27 ;
else
V_207 = L_28 ;
break;
case V_189 :
V_111 = V_212 ;
V_207 = L_29 ;
break;
case V_185 :
V_111 = V_212 ;
V_207 = L_27 ;
break;
case V_217 :
default:
V_111 = V_212 ;
V_207 = L_30 ;
break;
}
if ( ! V_14 -> V_218 )
F_75 ( V_144 , V_75 ,
L_31
L_32 ,
V_207 , V_56 -> V_35 ,
( unsigned long long ) V_56 -> V_60 ,
V_56 -> V_194 , V_206 ) ;
if ( V_113 -> V_219 > V_220 ) {
F_99 ( V_75 -> V_221 ,
V_220 ) ;
F_75 ( V_144 , V_75 ,
L_33 ,
V_220 ) ;
}
F_66 ( V_75 , V_111 ) ;
if ( ! V_14 -> V_134 )
F_86 ( V_14 , V_75 , V_56 -> V_179 ) ;
return 0 ;
}
if ( V_118 -> V_76 & V_138 ) {
if ( F_100 ( V_14 , V_35 ,
& V_208 ) ) {
F_90 ( V_14 , F_91 ( V_42
L_2 , V_14 -> V_43 ,
__FILE__ , __LINE__ , V_44 ) ) ;
return 1 ;
}
if ( V_208 && F_101 ( V_14 ,
V_208 , & V_209 ) ) {
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
V_54 -> V_208 = V_208 ;
V_54 -> V_209 = V_209 ;
if ( V_54 -> V_96 & V_98 ) {
V_111 = V_211 ;
V_205 = 1 ;
if ( V_54 -> V_96 &
V_222 ) {
F_75 ( V_223 , V_75 ,
L_34 ,
V_117 -> V_122 -> V_35 ) ;
V_117 -> V_224 = 1 ;
V_206 = L_35 ;
} else
V_206 = L_23 ;
} else {
V_111 = V_124 ;
if ( V_54 -> V_96 & V_99 )
V_206 = L_25 ;
else if ( V_54 -> V_96 &
V_100 )
V_206 = L_24 ;
}
F_75 ( V_144 , V_75 , L_36 \
L_37 ,
V_206 , V_35 , ( unsigned long long ) V_54 -> V_17 ,
V_54 -> V_225 , ( unsigned long long ) V_54 -> V_20 ) ;
if ( V_54 -> V_78 != 0 )
F_75 ( V_144 , V_75 ,
L_38 ,
V_206 , ( unsigned long long )
V_54 -> V_22 , V_54 -> V_26 ) ;
if ( V_54 -> V_79 [ 0 ] != '\0' )
F_75 ( V_144 , V_75 ,
L_12 ,
V_206 , V_54 -> V_80 ,
V_54 -> V_79 ) ;
F_41 ( V_54 ) ;
F_33 ( & V_14 -> V_74 , V_76 ) ;
if ( ! V_205 )
F_77 ( V_14 , V_35 , V_75 ) ;
F_66 ( V_75 , V_111 ) ;
if ( V_205 ) {
F_102 ( V_75 ) ;
F_94 ( V_14 , V_75 ) ;
}
return 0 ;
}
static int
F_103 ( struct V_110 * V_75 , struct V_226 * V_227 ,
T_13 V_228 , int V_229 [] )
{
int V_230 ;
int V_231 ;
T_13 V_232 ;
T_14 V_233 ;
V_230 = 64 ;
V_231 = 32 ;
V_233 = V_230 * V_231 ;
V_232 = V_228 ;
F_104 ( V_232 , V_233 ) ;
if ( ( T_14 ) V_228 >= 0x200000 ) {
V_230 = 255 ;
V_231 = 63 ;
V_233 = V_230 * V_231 ;
V_232 = V_228 ;
F_104 ( V_232 , V_233 ) ;
}
V_229 [ 0 ] = V_230 ;
V_229 [ 1 ] = V_231 ;
V_229 [ 2 ] = V_232 ;
return 0 ;
}
static void
F_105 ( struct V_13 * V_14 , T_6 V_234 )
{
char * V_235 ;
switch ( V_234 ) {
case V_236 :
V_235 = L_39 ;
break;
case V_237 :
V_235 = L_40 ;
break;
case V_238 :
V_235 = L_41 ;
break;
case V_239 :
V_235 = L_42 ;
break;
case V_240 :
V_235 = L_43 ;
break;
case V_241 :
V_235 = L_44 ;
break;
case 0xA :
V_235 = L_45 ;
break;
case V_242 :
V_235 = L_46 ;
break;
default:
V_235 = L_47 ;
break;
}
F_91 ( V_42 L_48 ,
V_14 -> V_43 , V_234 , V_235 ) ;
}
static T_6
F_106 ( struct V_13 * V_14 , T_4 V_102 , T_6 V_243 , T_10 V_244 )
{
T_15 * V_37 ;
if ( V_14 -> V_245 . V_246 == V_247 )
return 1 ;
if ( V_14 -> V_245 . V_102 != V_102 )
return 1 ;
V_14 -> V_245 . V_246 |= V_248 ;
V_37 = F_107 ( V_14 , V_244 ) ;
if ( V_37 ) {
memcpy ( V_14 -> V_245 . V_244 , V_37 , V_37 -> V_249 * 4 ) ;
V_14 -> V_245 . V_246 |= V_250 ;
}
V_14 -> V_245 . V_246 &= ~ V_251 ;
F_108 ( & V_14 -> V_245 . V_252 ) ;
return 1 ;
}
void
F_109 ( struct V_13 * V_14 , T_4 V_35 )
{
struct V_116 * V_117 ;
struct V_110 * V_75 ;
T_6 V_253 = 0 ;
F_110 (sdev, ioc->shost) {
if ( V_253 )
continue;
V_117 = V_75 -> V_120 ;
if ( ! V_117 )
continue;
if ( V_117 -> V_122 -> V_35 == V_35 ) {
V_117 -> V_122 -> V_254 = 1 ;
V_253 = 1 ;
V_14 -> V_255 = 1 ;
}
}
}
void
F_111 ( struct V_13 * V_14 , T_4 V_35 )
{
struct V_116 * V_117 ;
struct V_110 * V_75 ;
T_6 V_253 = 0 ;
F_110 (sdev, ioc->shost) {
if ( V_253 )
continue;
V_117 = V_75 -> V_120 ;
if ( ! V_117 )
continue;
if ( V_117 -> V_122 -> V_35 == V_35 ) {
V_117 -> V_122 -> V_254 = 0 ;
V_253 = 1 ;
V_14 -> V_255 = 0 ;
}
}
}
int
F_112 ( struct V_13 * V_14 , T_4 V_35 , T_16 V_88 ,
T_16 V_87 , T_16 V_109 , T_6 type , T_4 V_256 , T_14 V_257 )
{
T_17 * V_258 ;
T_18 * V_37 ;
T_4 V_102 = 0 ;
T_10 V_259 ;
struct V_260 * V_103 = NULL ;
int V_28 ;
T_4 V_261 = 0 ;
F_113 ( & V_14 -> V_245 . V_262 ) ;
if ( V_14 -> V_245 . V_246 != V_247 ) {
F_13 ( V_42 L_49 ,
V_44 , V_14 -> V_43 ) ;
return V_263 ;
}
if ( V_14 -> V_82 || V_14 -> V_264 ||
V_14 -> V_265 ) {
F_13 ( V_42 L_50 ,
V_44 , V_14 -> V_43 ) ;
return V_263 ;
}
V_259 = F_114 ( V_14 , 0 ) ;
if ( V_259 & V_266 ) {
F_115 ( V_14 , F_13 ( V_42
L_51 , V_14 -> V_43 ) ) ;
V_28 = F_116 ( V_14 , V_267 ) ;
return ( ! V_28 ) ? V_268 : V_263 ;
}
if ( ( V_259 & V_269 ) == V_270 ) {
F_117 ( V_14 , V_259 &
V_271 ) ;
V_28 = F_116 ( V_14 , V_267 ) ;
return ( ! V_28 ) ? V_268 : V_263 ;
}
V_102 = F_118 ( V_14 , V_14 -> V_272 ) ;
if ( ! V_102 ) {
F_25 ( V_42 L_52 ,
V_14 -> V_43 , V_44 ) ;
return V_263 ;
}
if ( type == V_273 )
V_103 = & V_14 -> V_103 [ V_256 - 1 ] ;
F_119 ( V_14 , F_13 ( V_42
L_53 ,
V_14 -> V_43 , V_35 , type , V_256 ) ) ;
V_14 -> V_245 . V_246 = V_251 ;
V_258 = F_120 ( V_14 , V_102 ) ;
V_14 -> V_245 . V_102 = V_102 ;
memset ( V_258 , 0 , sizeof( T_17 ) ) ;
memset ( V_14 -> V_245 . V_244 , 0 , sizeof( T_18 ) ) ;
V_258 -> V_274 = V_275 ;
V_258 -> V_200 = F_121 ( V_35 ) ;
V_258 -> V_276 = type ;
V_258 -> V_277 = F_121 ( V_256 ) ;
F_122 ( V_109 , (struct V_278 * ) V_258 -> V_279 ) ;
F_109 ( V_14 , V_35 ) ;
F_123 ( & V_14 -> V_245 . V_252 ) ;
if ( ( type == V_273 ) &&
( V_103 -> V_280 < V_14 -> V_281 ) )
V_261 = V_103 -> V_280 ;
else
V_261 = 0 ;
F_124 ( V_14 , V_102 , V_261 ) ;
F_125 ( & V_14 -> V_245 . V_252 , V_257 * V_282 ) ;
if ( ! ( V_14 -> V_245 . V_246 & V_248 ) ) {
F_25 ( V_42 L_54 ,
V_14 -> V_43 , V_44 ) ;
F_126 ( V_258 ,
sizeof( T_17 ) / 4 ) ;
if ( ! ( V_14 -> V_245 . V_246 & V_283 ) ) {
V_28 = F_116 ( V_14 ,
V_267 ) ;
V_28 = ( ! V_28 ) ? V_268 : V_263 ;
goto V_89;
}
}
F_127 ( V_14 ) ;
if ( V_14 -> V_245 . V_246 & V_250 ) {
F_128 ( V_14 , V_284 ) ;
V_37 = V_14 -> V_245 . V_244 ;
F_119 ( V_14 , F_13 ( V_42 L_55 \
L_56 ,
V_14 -> V_43 , F_21 ( V_37 -> V_46 ) ,
F_78 ( V_37 -> V_285 ) ,
F_78 ( V_37 -> V_286 ) ) ) ;
if ( V_14 -> V_15 & V_287 ) {
F_105 ( V_14 , V_37 -> V_288 ) ;
if ( V_37 -> V_46 )
F_126 ( V_258 ,
sizeof( T_17 ) / 4 ) ;
}
}
switch ( type ) {
case V_273 :
V_28 = V_268 ;
if ( V_103 -> V_104 == NULL )
break;
V_28 = V_263 ;
break;
case V_289 :
if ( F_64 ( V_14 , V_87 , V_88 ) )
V_28 = V_263 ;
else
V_28 = V_268 ;
break;
case V_290 :
case V_291 :
if ( F_65 ( V_14 , V_87 , V_109 , V_88 ) )
V_28 = V_263 ;
else
V_28 = V_268 ;
break;
case V_292 :
V_28 = V_268 ;
break;
default:
V_28 = V_263 ;
break;
}
V_89:
F_111 ( V_14 , V_35 ) ;
V_14 -> V_245 . V_246 = V_247 ;
return V_28 ;
}
int F_129 ( struct V_13 * V_14 , T_4 V_35 ,
T_16 V_88 , T_16 V_87 , T_16 V_109 , T_6 type , T_4 V_256 , T_14 V_257 )
{
int V_12 ;
F_130 ( & V_14 -> V_245 . V_262 ) ;
V_12 = F_112 ( V_14 , V_35 , V_88 , V_87 , V_109 , type ,
V_256 , V_257 ) ;
F_131 ( & V_14 -> V_245 . V_262 ) ;
return V_12 ;
}
static void
F_132 ( struct V_13 * V_14 , struct V_101 * V_104 )
{
struct V_126 * V_85 = V_104 -> V_51 -> V_293 ;
struct V_72 * V_294 = V_85 -> V_120 ;
struct V_53 * V_54 = NULL ;
unsigned long V_76 ;
char * V_295 = NULL ;
if ( ! V_294 )
return;
if ( V_14 -> V_218 )
V_295 = L_57 ;
else
V_295 = L_58 ;
F_133 ( V_104 ) ;
if ( V_294 -> V_76 & V_123 ) {
F_134 ( V_144 , V_85 ,
L_59 ,
V_295 , V_294 -> V_35 ,
V_295 , ( unsigned long long ) V_294 -> V_17 ) ;
} else {
F_32 ( & V_14 -> V_74 , V_76 ) ;
V_54 = F_28 ( V_14 , V_294 ) ;
if ( V_54 ) {
if ( V_294 -> V_76 &
V_138 ) {
F_134 ( V_144 , V_85 ,
L_60
L_61 ,
V_54 -> V_208 ,
( unsigned long long ) V_54 -> V_209 ) ;
}
F_134 ( V_144 , V_85 ,
L_62 ,
V_54 -> V_35 ,
( unsigned long long ) V_54 -> V_17 ,
V_54 -> V_225 ) ;
if ( V_54 -> V_78 != 0 )
F_134 ( V_144 , V_85 ,
L_63 ,
( unsigned long long )
V_54 -> V_22 ,
V_54 -> V_26 ) ;
if ( V_54 -> V_79 [ 0 ] != '\0' )
F_134 ( V_144 , V_85 ,
L_64 ,
V_54 -> V_80 ,
V_54 -> V_79 ) ;
F_41 ( V_54 ) ;
}
F_33 ( & V_14 -> V_74 , V_76 ) ;
}
}
static int
F_135 ( struct V_101 * V_104 )
{
struct V_13 * V_14 = F_67 ( V_104 -> V_51 -> V_114 ) ;
struct V_116 * V_117 ;
T_4 V_102 ;
T_4 V_35 ;
int V_2 ;
F_75 ( V_144 , V_104 -> V_51 ,
L_65 , V_104 ) ;
F_132 ( V_14 , V_104 ) ;
V_117 = V_104 -> V_51 -> V_120 ;
if ( ! V_117 || ! V_117 -> V_122 ) {
F_75 ( V_144 , V_104 -> V_51 ,
L_66 , V_104 ) ;
V_104 -> V_296 = V_297 << 16 ;
V_104 -> V_298 ( V_104 ) ;
V_2 = V_268 ;
goto V_89;
}
V_102 = F_63 ( V_14 , V_104 ) ;
if ( ! V_102 ) {
V_104 -> V_296 = V_299 << 16 ;
V_2 = V_268 ;
goto V_89;
}
if ( V_117 -> V_122 -> V_76 &
V_138 ||
V_117 -> V_122 -> V_76 & V_123 ) {
V_104 -> V_296 = V_299 << 16 ;
V_2 = V_263 ;
goto V_89;
}
F_136 ( V_14 ) ;
V_35 = V_117 -> V_122 -> V_35 ;
V_2 = F_129 ( V_14 , V_35 , V_104 -> V_51 -> V_88 ,
V_104 -> V_51 -> V_87 , V_104 -> V_51 -> V_109 ,
V_273 , V_102 , 30 ) ;
V_89:
F_75 ( V_144 , V_104 -> V_51 , L_67 ,
( ( V_2 == V_268 ) ? L_68 : L_69 ) , V_104 ) ;
return V_2 ;
}
static int
F_137 ( struct V_101 * V_104 )
{
struct V_13 * V_14 = F_67 ( V_104 -> V_51 -> V_114 ) ;
struct V_116 * V_117 ;
struct V_53 * V_54 = NULL ;
T_4 V_35 ;
int V_2 ;
struct V_126 * V_85 = V_104 -> V_51 -> V_293 ;
struct V_72 * V_300 = V_85 -> V_120 ;
F_75 ( V_144 , V_104 -> V_51 ,
L_70 , V_104 ) ;
F_132 ( V_14 , V_104 ) ;
V_117 = V_104 -> V_51 -> V_120 ;
if ( ! V_117 || ! V_117 -> V_122 ) {
F_75 ( V_144 , V_104 -> V_51 ,
L_66 , V_104 ) ;
V_104 -> V_296 = V_297 << 16 ;
V_104 -> V_298 ( V_104 ) ;
V_2 = V_268 ;
goto V_89;
}
V_35 = 0 ;
if ( V_117 -> V_122 -> V_76 &
V_138 ) {
V_54 = F_31 ( V_14 ,
V_300 ) ;
if ( V_54 )
V_35 = V_54 -> V_208 ;
} else
V_35 = V_117 -> V_122 -> V_35 ;
if ( ! V_35 ) {
V_104 -> V_296 = V_299 << 16 ;
V_2 = V_263 ;
goto V_89;
}
V_2 = F_129 ( V_14 , V_35 , V_104 -> V_51 -> V_88 ,
V_104 -> V_51 -> V_87 , V_104 -> V_51 -> V_109 ,
V_291 , 0 , 30 ) ;
V_89:
F_75 ( V_144 , V_104 -> V_51 , L_71 ,
( ( V_2 == V_268 ) ? L_68 : L_69 ) , V_104 ) ;
if ( V_54 )
F_41 ( V_54 ) ;
return V_2 ;
}
static int
F_138 ( struct V_101 * V_104 )
{
struct V_13 * V_14 = F_67 ( V_104 -> V_51 -> V_114 ) ;
struct V_116 * V_117 ;
struct V_53 * V_54 = NULL ;
T_4 V_35 ;
int V_2 ;
struct V_126 * V_85 = V_104 -> V_51 -> V_293 ;
struct V_72 * V_300 = V_85 -> V_120 ;
F_134 ( V_144 , V_85 , L_72 ,
V_104 ) ;
F_132 ( V_14 , V_104 ) ;
V_117 = V_104 -> V_51 -> V_120 ;
if ( ! V_117 || ! V_117 -> V_122 ) {
F_134 ( V_144 , V_85 , L_73 ,
V_104 ) ;
V_104 -> V_296 = V_297 << 16 ;
V_104 -> V_298 ( V_104 ) ;
V_2 = V_268 ;
goto V_89;
}
V_35 = 0 ;
if ( V_117 -> V_122 -> V_76 &
V_138 ) {
V_54 = F_31 ( V_14 ,
V_300 ) ;
if ( V_54 )
V_35 = V_54 -> V_208 ;
} else
V_35 = V_117 -> V_122 -> V_35 ;
if ( ! V_35 ) {
V_104 -> V_296 = V_299 << 16 ;
V_2 = V_263 ;
goto V_89;
}
V_2 = F_129 ( V_14 , V_35 , V_104 -> V_51 -> V_88 ,
V_104 -> V_51 -> V_87 , 0 , V_289 , 0 ,
30 ) ;
V_89:
F_134 ( V_144 , V_85 , L_74 ,
( ( V_2 == V_268 ) ? L_68 : L_69 ) , V_104 ) ;
if ( V_54 )
F_41 ( V_54 ) ;
return V_2 ;
}
static int
F_139 ( struct V_101 * V_104 )
{
struct V_13 * V_14 = F_67 ( V_104 -> V_51 -> V_114 ) ;
int V_2 , V_301 ;
F_13 ( V_42 L_75 ,
V_14 -> V_43 , V_104 ) ;
F_133 ( V_104 ) ;
if ( V_14 -> V_57 ) {
F_13 ( V_42 L_76 ,
V_14 -> V_43 ) ;
V_2 = V_263 ;
goto V_89;
}
V_301 = F_116 ( V_14 , V_267 ) ;
V_2 = ( V_301 < 0 ) ? V_263 : V_268 ;
V_89:
F_13 ( V_42 L_77 ,
V_14 -> V_43 , ( ( V_2 == V_268 ) ? L_68 : L_69 ) , V_104 ) ;
return V_2 ;
}
static void
F_140 ( struct V_13 * V_14 , struct V_3 * V_7 )
{
unsigned long V_76 ;
if ( V_14 -> V_302 == NULL )
return;
F_32 ( & V_14 -> V_303 , V_76 ) ;
F_4 ( V_7 ) ;
F_141 ( & V_7 -> V_81 ) ;
F_47 ( & V_7 -> V_81 , & V_14 -> V_304 ) ;
F_142 ( & V_7 -> V_305 , V_306 ) ;
F_4 ( V_7 ) ;
F_143 ( V_14 -> V_302 , & V_7 -> V_305 ) ;
F_33 ( & V_14 -> V_303 , V_76 ) ;
}
static void
F_144 ( struct V_13 * V_14 , struct V_3
* V_7 )
{
unsigned long V_76 ;
F_32 ( & V_14 -> V_303 , V_76 ) ;
if ( ! F_39 ( & V_7 -> V_81 ) ) {
F_40 ( & V_7 -> V_81 ) ;
F_6 ( V_7 ) ;
}
F_33 ( & V_14 -> V_303 , V_76 ) ;
}
void
F_145 ( struct V_13 * V_14 ,
struct V_307 * V_308 )
{
struct V_3 * V_7 ;
T_4 V_193 ;
if ( V_14 -> V_57 )
return;
V_193 = sizeof( * V_308 ) ;
V_7 = F_8 ( V_193 ) ;
if ( ! V_7 )
return;
V_7 -> V_309 = V_310 ;
V_7 -> V_14 = V_14 ;
memcpy ( V_7 -> V_308 , V_308 , sizeof( * V_308 ) ) ;
F_140 ( V_14 , V_7 ) ;
F_6 ( V_7 ) ;
}
static void
F_146 ( struct V_13 * V_14 )
{
struct V_3 * V_7 ;
if ( V_14 -> V_57 )
return;
V_7 = F_8 ( 0 ) ;
if ( ! V_7 )
return;
V_7 -> V_309 = V_311 ;
V_7 -> V_14 = V_14 ;
F_140 ( V_14 , V_7 ) ;
F_6 ( V_7 ) ;
}
void
F_147 ( struct V_13 * V_14 )
{
struct V_3 * V_7 ;
V_7 = F_8 ( 0 ) ;
if ( ! V_7 )
return;
V_7 -> V_309 = V_312 ;
V_7 -> V_14 = V_14 ;
F_140 ( V_14 , V_7 ) ;
F_6 ( V_7 ) ;
}
static struct V_3 * F_148 ( struct V_13 * V_14 )
{
unsigned long V_76 ;
struct V_3 * V_7 = NULL ;
F_32 ( & V_14 -> V_303 , V_76 ) ;
if ( ! F_39 ( & V_14 -> V_304 ) ) {
V_7 = F_149 ( & V_14 -> V_304 ,
struct V_3 , V_81 ) ;
F_40 ( & V_7 -> V_81 ) ;
}
F_33 ( & V_14 -> V_303 , V_76 ) ;
return V_7 ;
}
static void
F_150 ( struct V_13 * V_14 )
{
struct V_3 * V_7 ;
if ( F_39 ( & V_14 -> V_304 ) ||
! V_14 -> V_302 || F_151 () )
return;
while ( ( V_7 = F_148 ( V_14 ) ) ) {
if ( F_152 ( & V_7 -> V_305 ) )
F_6 ( V_7 ) ;
F_6 ( V_7 ) ;
}
}
static void
F_153 ( struct V_110 * V_75 ,
struct V_116 * V_117 )
{
int V_2 = 0 ;
F_75 ( V_144 , V_75 , L_78 ,
V_117 -> V_122 -> V_35 ) ;
V_117 -> V_313 = 1 ;
V_2 = F_154 ( V_75 ) ;
if ( V_2 == - V_314 )
F_75 ( V_223 , V_75 ,
L_79 ,
V_117 -> V_122 -> V_35 , V_2 ) ;
}
static void
F_155 ( struct V_110 * V_75 ,
struct V_116 * V_117 )
{
int V_2 = 0 ;
F_75 ( V_223 , V_75 , L_80
L_81 , V_117 -> V_122 -> V_35 ) ;
V_117 -> V_313 = 0 ;
V_2 = F_156 ( V_75 , V_315 ) ;
if ( V_2 == - V_314 ) {
F_75 ( V_223 , V_75 ,
L_82
L_83 ,
V_117 -> V_122 -> V_35 , V_2 ) ;
V_117 -> V_313 = 1 ;
V_2 = F_154 ( V_75 ) ;
if ( V_2 )
F_75 ( V_223 , V_75 , L_84
L_85 ,
V_117 -> V_122 -> V_35 , V_2 ) ;
V_117 -> V_313 = 0 ;
V_2 = F_156 ( V_75 , V_315 ) ;
if ( V_2 )
F_75 ( V_223 , V_75 , L_86
L_87 ,
V_117 -> V_122 -> V_35 , V_2 ) ;
}
}
static void
F_157 ( struct V_13 * V_14 )
{
struct V_116 * V_117 ;
struct V_110 * V_75 ;
F_110 (sdev, ioc->shost) {
V_117 = V_75 -> V_120 ;
if ( ! V_117 )
continue;
if ( ! V_117 -> V_313 )
continue;
F_46 ( V_14 , F_75 ( V_144 , V_75 ,
L_88 ,
V_117 -> V_122 -> V_35 ) ) ;
F_155 ( V_75 , V_117 ) ;
}
}
static void
F_158 ( struct V_13 * V_14 , T_1 V_17 )
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
if ( V_117 -> V_313 )
F_155 ( V_75 ,
V_117 ) ;
}
}
static void
F_159 ( struct V_13 * V_14 )
{
struct V_116 * V_117 ;
struct V_110 * V_75 ;
F_110 (sdev, ioc->shost) {
V_117 = V_75 -> V_120 ;
if ( ! V_117 )
continue;
if ( V_117 -> V_313 )
continue;
if ( V_117 -> V_224 ) {
F_75 ( V_144 , V_75 ,
L_89 ,
V_44 , V_117 -> V_122 -> V_35 ) ;
continue;
}
F_153 ( V_75 , V_117 ) ;
}
}
static void
F_160 ( struct V_13 * V_14 , T_4 V_35 )
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
if ( V_117 -> V_313 )
continue;
if ( V_54 -> V_316 )
continue;
if ( V_117 -> V_224 ) {
F_75 ( V_144 , V_75 ,
L_89 ,
V_44 , V_117 -> V_122 -> V_35 ) ;
continue;
}
F_153 ( V_75 , V_117 ) ;
}
F_41 ( V_54 ) ;
}
static void
F_161 ( struct V_13 * V_14 ,
struct V_92 * V_93 )
{
struct V_317 * V_318 ;
struct V_53 * V_54 ;
struct V_92 * V_319 ;
unsigned long V_76 ;
if ( ! V_93 )
return;
F_15 (mpt3sas_port,
&sas_expander->sas_port_list, port_list) {
if ( V_318 -> V_320 . V_321 ==
V_322 ) {
F_32 ( & V_14 -> V_74 , V_76 ) ;
V_54 = F_34 ( V_14 ,
V_318 -> V_320 . V_17 ) ;
if ( V_54 ) {
F_162 ( V_54 -> V_35 ,
V_14 -> V_323 ) ;
F_41 ( V_54 ) ;
}
F_33 ( & V_14 -> V_74 , V_76 ) ;
}
}
F_15 (mpt3sas_port,
&sas_expander->sas_port_list, port_list) {
if ( V_318 -> V_320 . V_321 ==
V_324 ||
V_318 -> V_320 . V_321 ==
V_325 ) {
V_319 =
F_58 (
V_14 , V_318 -> V_320 . V_17 ) ;
F_161 ( V_14 ,
V_319 ) ;
}
}
}
static void
F_163 ( struct V_13 * V_14 ,
T_19 * V_308 )
{
int V_106 ;
T_4 V_35 ;
T_4 V_326 ;
for ( V_106 = 0 ; V_106 < V_308 -> V_327 ; V_106 ++ ) {
V_35 = F_21 ( V_308 -> V_328 [ V_106 ] . V_329 ) ;
if ( ! V_35 )
continue;
V_326 = V_308 -> V_328 [ V_106 ] . V_330 &
V_331 ;
if ( V_326 == V_332 )
F_160 ( V_14 , V_35 ) ;
}
}
static void
F_164 ( struct V_13 * V_14 , T_4 V_35 )
{
T_17 * V_258 ;
T_4 V_102 ;
struct V_53 * V_54 = NULL ;
struct V_72 * V_118 = NULL ;
T_1 V_17 = 0 ;
unsigned long V_76 ;
struct V_333 * V_334 ;
T_10 V_259 ;
if ( V_14 -> V_264 ) {
F_46 ( V_14 , F_13 ( V_42
L_90 ,
V_44 , V_14 -> V_43 , V_35 ) ) ;
return;
} else if ( V_14 -> V_265 ) {
F_46 ( V_14 , F_13 ( V_42
L_91 ,
V_44 , V_14 -> V_43 ,
V_35 ) ) ;
return;
}
V_259 = F_114 ( V_14 , 1 ) ;
if ( V_259 != V_335 ) {
F_46 ( V_14 , F_13 ( V_42
L_92 ,
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
V_118 -> V_336 = 1 ;
V_17 = V_54 -> V_17 ;
}
F_33 ( & V_14 -> V_74 , V_76 ) ;
if ( V_118 ) {
F_46 ( V_14 , F_13 ( V_42
L_93 ,
V_14 -> V_43 , V_35 ,
( unsigned long long ) V_17 ) ) ;
if ( V_54 -> V_78 != 0 )
F_46 ( V_14 , F_13 ( V_42
L_94
L_95 , V_14 -> V_43 , ( unsigned long long )
V_54 -> V_22 ,
V_54 -> V_26 ) ) ;
if ( V_54 -> V_79 [ 0 ] != '\0' )
F_46 ( V_14 , F_13 ( V_42
L_96
L_97 , V_14 -> V_43 ,
V_54 -> V_80 ,
V_54 -> V_79 ) ) ;
F_158 ( V_14 , V_17 ) ;
V_118 -> V_35 = V_132 ;
}
V_102 = F_118 ( V_14 , V_14 -> V_337 ) ;
if ( ! V_102 ) {
V_334 = F_9 ( sizeof( * V_334 ) , V_8 ) ;
if ( ! V_334 )
goto V_89;
F_141 ( & V_334 -> V_81 ) ;
V_334 -> V_35 = V_35 ;
F_47 ( & V_334 -> V_81 , & V_14 -> V_338 ) ;
F_46 ( V_14 , F_13 ( V_42
L_98 ,
V_14 -> V_43 , V_35 ) ) ;
goto V_89;
}
F_46 ( V_14 , F_13 ( V_42
L_99 ,
V_14 -> V_43 , V_35 , V_102 ,
V_14 -> V_337 ) ) ;
V_258 = F_120 ( V_14 , V_102 ) ;
memset ( V_258 , 0 , sizeof( T_17 ) ) ;
V_258 -> V_274 = V_275 ;
V_258 -> V_200 = F_121 ( V_35 ) ;
V_258 -> V_276 = V_289 ;
F_124 ( V_14 , V_102 , 0 ) ;
F_128 ( V_14 , V_339 ) ;
V_89:
if ( V_54 )
F_41 ( V_54 ) ;
}
static T_6
F_165 ( struct V_13 * V_14 , T_4 V_102 , T_6 V_243 ,
T_10 V_244 )
{
T_4 V_35 ;
T_17 * V_340 ;
T_18 * V_37 =
F_107 ( V_14 , V_244 ) ;
T_20 * V_258 ;
T_4 V_341 ;
T_10 V_259 ;
struct V_342 * V_343 ;
if ( V_14 -> V_264 ) {
F_46 ( V_14 , F_13 ( V_42
L_100 , V_44 , V_14 -> V_43 ) ) ;
return 1 ;
} else if ( V_14 -> V_265 ) {
F_46 ( V_14 , F_13 ( V_42
L_101 , V_44 ,
V_14 -> V_43 ) ) ;
return 1 ;
}
V_259 = F_114 ( V_14 , 1 ) ;
if ( V_259 != V_335 ) {
F_46 ( V_14 , F_13 ( V_42
L_102 , V_44 , V_14 -> V_43 ) ) ;
return 1 ;
}
if ( F_166 ( ! V_37 ) ) {
F_25 ( V_42 L_103 ,
V_14 -> V_43 , __FILE__ , __LINE__ , V_44 ) ;
return 1 ;
}
V_340 = F_120 ( V_14 , V_102 ) ;
V_35 = F_21 ( V_340 -> V_200 ) ;
if ( V_35 != F_21 ( V_37 -> V_200 ) ) {
F_46 ( V_14 , F_25 ( V_42
L_104 ,
V_14 -> V_43 , V_35 ,
F_21 ( V_37 -> V_200 ) , V_102 ) ) ;
return 0 ;
}
F_128 ( V_14 , V_284 ) ;
F_46 ( V_14 , F_13 ( V_42
L_105
L_106 , V_14 -> V_43 ,
V_35 , V_102 , F_21 ( V_37 -> V_46 ) ,
F_78 ( V_37 -> V_285 ) ,
F_78 ( V_37 -> V_286 ) ) ) ;
V_341 = F_167 ( V_14 , V_14 -> V_344 ) ;
if ( ! V_341 ) {
V_343 = F_9 ( sizeof( * V_343 ) , V_8 ) ;
if ( ! V_343 )
return F_168 ( V_14 , V_102 ) ;
F_141 ( & V_343 -> V_81 ) ;
V_343 -> V_35 = V_340 -> V_200 ;
F_47 ( & V_343 -> V_81 , & V_14 -> V_345 ) ;
F_46 ( V_14 , F_13 ( V_42
L_107 ,
V_14 -> V_43 , V_35 ) ) ;
return F_168 ( V_14 , V_102 ) ;
}
F_46 ( V_14 , F_13 ( V_42
L_108 ,
V_14 -> V_43 , V_35 , V_341 ,
V_14 -> V_344 ) ) ;
V_258 = F_120 ( V_14 , V_341 ) ;
memset ( V_258 , 0 , sizeof( T_20 ) ) ;
V_258 -> V_274 = V_346 ;
V_258 -> V_347 = V_348 ;
V_258 -> V_200 = V_340 -> V_200 ;
F_169 ( V_14 , V_341 ) ;
return F_168 ( V_14 , V_102 ) ;
}
static T_6
F_170 ( struct V_13 * V_14 , T_4 V_102 ,
T_6 V_243 , T_10 V_244 )
{
T_21 * V_37 =
F_107 ( V_14 , V_244 ) ;
if ( F_171 ( V_37 ) ) {
F_46 ( V_14 , F_13 ( V_42
L_109
L_110 ,
V_14 -> V_43 , F_21 ( V_37 -> V_200 ) , V_102 ,
F_21 ( V_37 -> V_46 ) ,
F_78 ( V_37 -> V_285 ) ) ) ;
} else {
F_25 ( V_42 L_103 ,
V_14 -> V_43 , __FILE__ , __LINE__ , V_44 ) ;
}
return F_172 ( V_14 , V_102 ) ;
}
static void
F_173 ( struct V_13 * V_14 , T_4 V_35 )
{
T_17 * V_258 ;
T_4 V_102 ;
struct V_333 * V_334 ;
if ( V_14 -> V_82 || V_14 -> V_264 ||
V_14 -> V_265 ) {
F_46 ( V_14 , F_13 ( V_42
L_50 ,
V_44 , V_14 -> V_43 ) ) ;
return;
}
V_102 = F_118 ( V_14 , V_14 -> V_349 ) ;
if ( ! V_102 ) {
V_334 = F_9 ( sizeof( * V_334 ) , V_8 ) ;
if ( ! V_334 )
return;
F_141 ( & V_334 -> V_81 ) ;
V_334 -> V_35 = V_35 ;
F_47 ( & V_334 -> V_81 , & V_14 -> V_350 ) ;
F_46 ( V_14 , F_13 ( V_42
L_98 ,
V_14 -> V_43 , V_35 ) ) ;
return;
}
F_46 ( V_14 , F_13 ( V_42
L_99 ,
V_14 -> V_43 , V_35 , V_102 ,
V_14 -> V_349 ) ) ;
V_258 = F_120 ( V_14 , V_102 ) ;
memset ( V_258 , 0 , sizeof( T_17 ) ) ;
V_258 -> V_274 = V_275 ;
V_258 -> V_200 = F_121 ( V_35 ) ;
V_258 -> V_276 = V_289 ;
F_124 ( V_14 , V_102 , 0 ) ;
}
static T_6
F_174 ( struct V_13 * V_14 , T_4 V_102 ,
T_6 V_243 , T_10 V_244 )
{
T_4 V_35 ;
T_17 * V_340 ;
T_18 * V_37 =
F_107 ( V_14 , V_244 ) ;
if ( V_14 -> V_82 || V_14 -> V_264 ||
V_14 -> V_265 ) {
F_46 ( V_14 , F_13 ( V_42
L_50 ,
V_44 , V_14 -> V_43 ) ) ;
return 1 ;
}
if ( F_166 ( ! V_37 ) ) {
F_25 ( V_42 L_103 ,
V_14 -> V_43 , __FILE__ , __LINE__ , V_44 ) ;
return 1 ;
}
V_340 = F_120 ( V_14 , V_102 ) ;
V_35 = F_21 ( V_340 -> V_200 ) ;
if ( V_35 != F_21 ( V_37 -> V_200 ) ) {
F_46 ( V_14 , F_25 ( V_42
L_104 ,
V_14 -> V_43 , V_35 ,
F_21 ( V_37 -> V_200 ) , V_102 ) ) ;
return 0 ;
}
F_46 ( V_14 , F_13 ( V_42
L_105
L_106 , V_14 -> V_43 ,
V_35 , V_102 , F_21 ( V_37 -> V_46 ) ,
F_78 ( V_37 -> V_285 ) ,
F_78 ( V_37 -> V_286 ) ) ) ;
return F_168 ( V_14 , V_102 ) ;
}
static void
F_175 ( struct V_13 * V_14 , T_4 V_102 , T_4 V_309 ,
T_10 V_351 )
{
T_22 * V_352 ;
int V_106 = V_102 - V_14 -> V_353 ;
unsigned long V_76 ;
F_32 ( & V_14 -> V_105 , V_76 ) ;
V_14 -> V_354 [ V_106 ] . V_355 = V_14 -> V_356 ;
F_33 ( & V_14 -> V_105 , V_76 ) ;
F_46 ( V_14 , F_13 ( V_42
L_111 ,
V_14 -> V_43 , F_21 ( V_309 ) , V_102 ,
V_14 -> V_356 ) ) ;
V_352 = F_120 ( V_14 , V_102 ) ;
memset ( V_352 , 0 , sizeof( T_22 ) ) ;
V_352 -> V_274 = V_357 ;
V_352 -> V_358 = V_309 ;
V_352 -> V_359 = V_351 ;
V_352 -> V_360 = 0 ;
V_352 -> V_361 = 0 ;
F_169 ( V_14 , V_102 ) ;
}
static void
F_176 ( struct V_13 * V_14 ,
T_4 V_102 , T_4 V_35 )
{
T_20 * V_258 ;
T_10 V_259 ;
int V_106 = V_102 - V_14 -> V_353 ;
unsigned long V_76 ;
if ( V_14 -> V_264 ) {
F_46 ( V_14 , F_13 ( V_42
L_100 ,
V_44 , V_14 -> V_43 ) ) ;
return;
} else if ( V_14 -> V_265 ) {
F_46 ( V_14 , F_13 ( V_42
L_101 ,
V_44 , V_14 -> V_43 ) ) ;
return;
}
V_259 = F_114 ( V_14 , 1 ) ;
if ( V_259 != V_335 ) {
F_46 ( V_14 , F_13 ( V_42
L_102 ,
V_44 , V_14 -> V_43 ) ) ;
return;
}
F_32 ( & V_14 -> V_105 , V_76 ) ;
V_14 -> V_354 [ V_106 ] . V_355 = V_14 -> V_344 ;
F_33 ( & V_14 -> V_105 , V_76 ) ;
F_46 ( V_14 , F_13 ( V_42
L_108 ,
V_14 -> V_43 , F_21 ( V_35 ) , V_102 ,
V_14 -> V_344 ) ) ;
V_258 = F_120 ( V_14 , V_102 ) ;
memset ( V_258 , 0 , sizeof( T_20 ) ) ;
V_258 -> V_274 = V_346 ;
V_258 -> V_347 = V_348 ;
V_258 -> V_200 = V_35 ;
F_169 ( V_14 , V_102 ) ;
}
T_6
F_172 ( struct V_13 * V_14 , T_4 V_102 )
{
struct V_342 * V_343 ;
struct V_362 * V_363 ;
if ( ! F_39 ( & V_14 -> V_364 ) ) {
V_363 = F_177 ( V_14 -> V_364 . V_365 ,
struct V_362 , V_81 ) ;
F_175 ( V_14 , V_102 ,
V_363 -> V_358 , V_363 -> V_359 ) ;
F_56 ( & V_363 -> V_81 ) ;
F_2 ( V_363 ) ;
return 0 ;
}
if ( ! F_39 ( & V_14 -> V_345 ) ) {
V_343 = F_177 ( V_14 -> V_345 . V_365 ,
struct V_342 , V_81 ) ;
F_176 ( V_14 , V_102 ,
V_343 -> V_35 ) ;
F_56 ( & V_343 -> V_81 ) ;
F_2 ( V_343 ) ;
return 0 ;
}
return 1 ;
}
static T_6
F_168 ( struct V_13 * V_14 , T_4 V_102 )
{
struct V_333 * V_334 ;
if ( ! F_39 ( & V_14 -> V_350 ) ) {
V_334 = F_177 ( V_14 -> V_350 . V_365 ,
struct V_333 , V_81 ) ;
F_178 ( V_14 , V_102 ) ;
F_173 ( V_14 , V_334 -> V_35 ) ;
F_56 ( & V_334 -> V_81 ) ;
F_2 ( V_334 ) ;
return 0 ;
}
if ( ! F_39 ( & V_14 -> V_338 ) ) {
V_334 = F_177 ( V_14 -> V_338 . V_365 ,
struct V_333 , V_81 ) ;
F_178 ( V_14 , V_102 ) ;
F_164 ( V_14 , V_334 -> V_35 ) ;
F_56 ( & V_334 -> V_81 ) ;
F_2 ( V_334 ) ;
return 0 ;
}
return 1 ;
}
static void
F_179 ( struct V_13 * V_14 ,
T_19 * V_308 )
{
struct V_3 * V_7 ;
T_19 * V_366 ;
T_4 V_367 ;
struct V_92 * V_93 ;
unsigned long V_76 ;
int V_106 , V_326 ;
T_4 V_35 ;
for ( V_106 = 0 ; V_106 < V_308 -> V_327 ; V_106 ++ ) {
V_35 = F_21 ( V_308 -> V_328 [ V_106 ] . V_329 ) ;
if ( ! V_35 )
continue;
V_326 = V_308 -> V_328 [ V_106 ] . V_330 &
V_331 ;
if ( V_326 == V_368 )
F_164 ( V_14 , V_35 ) ;
}
V_367 = F_21 ( V_308 -> V_369 ) ;
if ( V_367 < V_14 -> V_39 . V_40 ) {
F_163 ( V_14 , V_308 ) ;
return;
}
if ( V_308 -> V_370 ==
V_371 ) {
F_32 ( & V_14 -> V_94 , V_76 ) ;
V_93 = F_57 ( V_14 ,
V_367 ) ;
F_161 ( V_14 , V_93 ) ;
F_33 ( & V_14 -> V_94 , V_76 ) ;
do {
V_35 = F_180 ( V_14 -> V_323 ,
V_14 -> V_202 . V_372 ) ;
if ( V_35 < V_14 -> V_202 . V_372 )
F_160 ( V_14 , V_35 ) ;
} while ( F_181 ( V_35 , V_14 -> V_323 ) );
} else if ( V_308 -> V_370 == V_373 )
F_163 ( V_14 , V_308 ) ;
if ( V_308 -> V_370 != V_374 )
return;
F_32 ( & V_14 -> V_303 , V_76 ) ;
F_15 (fw_event, &ioc->fw_event_list, list) {
if ( V_7 -> V_309 != V_375 ||
V_7 -> V_376 )
continue;
V_366 = ( T_19 * )
V_7 -> V_308 ;
if ( V_366 -> V_370 ==
V_377 ||
V_366 -> V_370 ==
V_373 ) {
if ( F_21 ( V_366 -> V_369 ) ==
V_367 ) {
F_46 ( V_14 , F_13 ( V_42
L_112 , V_14 -> V_43 ) ) ;
V_7 -> V_376 = 1 ;
}
}
}
F_33 ( & V_14 -> V_303 , V_76 ) ;
}
static void
F_182 ( struct V_13 * V_14 , T_4 V_35 )
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
V_118 -> V_336 = 1 ;
F_46 ( V_14 , F_13 ( V_42
L_113
L_114 , V_14 -> V_43 , V_35 ,
( unsigned long long ) V_56 -> V_60 ) ) ;
}
F_33 ( & V_14 -> V_90 , V_76 ) ;
}
static void
F_183 ( T_4 V_35 , T_4 * V_378 , T_4 * V_379 )
{
if ( ! V_35 || V_35 == * V_378 || V_35 == * V_379 )
return;
if ( ! * V_378 )
* V_378 = V_35 ;
else if ( ! * V_379 )
* V_379 = V_35 ;
}
static void
F_184 ( struct V_13 * V_14 ,
T_23 * V_308 )
{
T_24 * V_380 ;
int V_106 ;
T_4 V_35 , V_208 , V_378 , V_379 ;
struct V_333 * V_334 ;
V_378 = 0 ;
V_379 = 0 ;
if ( V_14 -> V_134 )
return;
V_380 = ( T_24 * ) & V_308 -> V_381 [ 0 ] ;
for ( V_106 = 0 ; V_106 < V_308 -> V_382 ; V_106 ++ , V_380 ++ ) {
if ( F_78 ( V_308 -> V_145 ) &
V_383 )
continue;
if ( V_380 -> V_384 ==
V_385 ||
V_380 -> V_384 ==
V_386 ) {
V_208 = F_21 ( V_380 -> V_387 ) ;
F_182 ( V_14 , V_208 ) ;
F_183 ( V_208 , & V_378 , & V_379 ) ;
}
}
V_380 = ( T_24 * ) & V_308 -> V_381 [ 0 ] ;
for ( V_106 = 0 ; V_106 < V_308 -> V_382 ; V_106 ++ , V_380 ++ ) {
if ( F_78 ( V_308 -> V_145 ) &
V_383 )
continue;
if ( V_380 -> V_384 == V_388 ) {
V_208 = F_21 ( V_380 -> V_387 ) ;
F_183 ( V_208 , & V_378 , & V_379 ) ;
}
}
if ( V_378 )
F_173 ( V_14 , V_378 ) ;
if ( V_379 )
F_173 ( V_14 , V_379 ) ;
V_380 = ( T_24 * ) & V_308 -> V_381 [ 0 ] ;
for ( V_106 = 0 ; V_106 < V_308 -> V_382 ; V_106 ++ , V_380 ++ ) {
if ( V_380 -> V_384 != V_388 )
continue;
V_35 = F_21 ( V_380 -> V_389 ) ;
V_208 = F_21 ( V_380 -> V_387 ) ;
F_185 ( V_35 , V_14 -> V_137 ) ;
if ( ! V_208 )
F_164 ( V_14 , V_35 ) ;
else if ( V_208 == V_378 || V_208 == V_379 ) {
V_334 = F_9 ( sizeof( * V_334 ) , V_8 ) ;
F_186 ( ! V_334 ) ;
F_141 ( & V_334 -> V_81 ) ;
V_334 -> V_35 = V_35 ;
F_47 ( & V_334 -> V_81 , & V_14 -> V_338 ) ;
F_46 ( V_14 , F_13 ( V_42
L_98 , V_14 -> V_43 ,
V_35 ) ) ;
} else
F_164 ( V_14 , V_35 ) ;
}
}
static void
F_187 ( struct V_13 * V_14 ,
T_25 * V_308 )
{
T_10 V_167 ;
if ( V_308 -> V_384 != V_390 )
return;
V_167 = F_78 ( V_308 -> V_391 ) ;
if ( V_167 == V_177 || V_167 ==
V_176 )
F_182 ( V_14 ,
F_21 ( V_308 -> V_387 ) ) ;
}
static void
F_188 ( struct V_13 * V_14 ,
T_26 * V_308 )
{
if ( V_14 -> V_392 >= V_308 -> V_393 ) {
F_25 ( V_42 L_115
L_116 , V_14 -> V_43 ,
( ( F_21 ( V_308 -> V_394 ) & 0x1 ) == 1 ) ? L_117 : L_118 ,
( ( F_21 ( V_308 -> V_394 ) & 0x2 ) == 2 ) ? L_119 : L_118 ,
( ( F_21 ( V_308 -> V_394 ) & 0x4 ) == 4 ) ? L_120 : L_118 ,
( ( F_21 ( V_308 -> V_394 ) & 0x8 ) == 8 ) ? L_121 : L_118 ,
V_308 -> V_393 ) ;
F_25 ( V_42 L_122 ,
V_14 -> V_43 , V_308 -> V_395 ) ;
}
}
static inline bool F_189 ( struct V_101 * V_104 )
{
return ( V_104 -> V_396 [ 0 ] == V_397 || V_104 -> V_396 [ 0 ] == V_398 ) ;
}
static void
F_190 ( struct V_13 * V_14 )
{
struct V_101 * V_104 ;
T_4 V_102 ;
T_4 V_399 = 0 ;
for ( V_102 = 1 ; V_102 <= V_14 -> V_107 ; V_102 ++ ) {
V_104 = F_62 ( V_14 , V_102 ) ;
if ( ! V_104 )
continue;
V_399 ++ ;
if ( F_189 ( V_104 ) )
F_156 ( V_104 -> V_51 ,
V_315 ) ;
F_178 ( V_14 , V_102 ) ;
F_191 ( V_104 ) ;
if ( V_14 -> V_265 )
V_104 -> V_296 = V_297 << 16 ;
else
V_104 -> V_296 = V_299 << 16 ;
V_104 -> V_298 ( V_104 ) ;
}
F_119 ( V_14 , F_13 ( V_42 L_123 ,
V_14 -> V_43 , V_399 ) ) ;
}
static void
F_192 ( struct V_13 * V_14 , struct V_101 * V_104 ,
T_27 * V_258 )
{
T_4 V_400 ;
unsigned char V_401 = F_193 ( V_104 ) ;
unsigned char V_402 = F_194 ( V_104 ) ;
T_28 * V_403 =
( T_28 * ) V_258 ;
if ( V_402 == V_404 || V_401 == V_405 )
return;
if ( V_401 == V_406 )
V_400 = V_407 ;
else if ( V_401 == V_408 )
V_400 = V_409 ;
else
return;
switch ( V_402 ) {
case V_410 :
case V_411 :
V_400 |= V_412 |
V_413 |
V_414 ;
V_258 -> V_415 . V_416 . V_417 =
F_195 ( F_196 ( V_104 ) ) ;
break;
case V_418 :
V_400 |= V_414 ;
break;
}
V_403 -> V_419 =
F_121 ( V_104 -> V_51 -> V_420 ) ;
V_258 -> V_421 = F_121 ( V_400 ) ;
}
static void
F_197 ( struct V_101 * V_104 , T_4 V_38 )
{
T_6 V_422 ;
switch ( V_38 ) {
case V_423 :
V_422 = 0x01 ;
break;
case V_424 :
V_422 = 0x02 ;
break;
case V_425 :
V_422 = 0x03 ;
break;
default:
V_422 = 0x00 ;
break;
}
F_198 ( 0 , V_104 -> V_426 , V_427 , 0x10 ,
V_422 ) ;
V_104 -> V_296 = V_428 << 24 | ( V_429 << 16 ) |
V_430 ;
}
static int
F_199 ( struct V_112 * V_113 , struct V_101 * V_104 )
{
struct V_13 * V_14 = F_67 ( V_113 ) ;
struct V_116 * V_117 ;
struct V_72 * V_118 ;
struct V_55 * V_56 ;
T_27 * V_258 ;
T_10 V_431 ;
T_4 V_102 ;
T_4 V_35 ;
if ( V_14 -> V_15 & V_432 )
F_133 ( V_104 ) ;
if ( F_189 ( V_104 ) )
F_154 ( V_104 -> V_51 ) ;
V_117 = V_104 -> V_51 -> V_120 ;
if ( ! V_117 || ! V_117 -> V_122 ) {
V_104 -> V_296 = V_297 << 16 ;
V_104 -> V_298 ( V_104 ) ;
return 0 ;
}
if ( V_14 -> V_265 || V_14 -> V_264 ) {
V_104 -> V_296 = V_297 << 16 ;
V_104 -> V_298 ( V_104 ) ;
return 0 ;
}
V_118 = V_117 -> V_122 ;
V_35 = V_118 -> V_35 ;
if ( V_35 == V_132 ) {
V_104 -> V_296 = V_297 << 16 ;
V_104 -> V_298 ( V_104 ) ;
return 0 ;
}
if ( V_14 -> V_82 || V_14 -> V_433 )
return V_434 ;
else if ( V_118 -> V_336 ) {
V_104 -> V_296 = V_297 << 16 ;
V_104 -> V_298 ( V_104 ) ;
return 0 ;
} else if ( V_118 -> V_254 ||
V_117 -> V_313 )
return V_435 ;
if ( V_104 -> V_436 == V_437 )
V_431 = V_438 ;
else if ( V_104 -> V_436 == V_439 )
V_431 = V_440 ;
else
V_431 = V_441 ;
V_431 |= V_442 ;
if ( ! V_14 -> V_134 && ! F_79 ( & V_104 -> V_51 -> V_191 )
&& F_96 ( V_104 -> V_51 ) && V_104 -> V_443 != 32 )
V_431 |= V_444 ;
V_102 = F_200 ( V_14 , V_14 -> V_445 , V_104 ) ;
if ( ! V_102 ) {
F_25 ( V_42 L_52 ,
V_14 -> V_43 , V_44 ) ;
goto V_89;
}
V_258 = F_120 ( V_14 , V_102 ) ;
memset ( V_258 , 0 , sizeof( T_27 ) ) ;
F_192 ( V_14 , V_104 , V_258 ) ;
if ( V_104 -> V_443 == 32 )
V_431 |= 4 << V_446 ;
V_258 -> V_274 = V_447 ;
if ( V_117 -> V_122 -> V_76 &
V_138 )
V_258 -> V_274 = V_448 ;
else
V_258 -> V_274 = V_447 ;
V_258 -> V_200 = F_121 ( V_35 ) ;
V_258 -> V_449 = F_201 ( F_202 ( V_104 ) ) ;
V_258 -> V_450 = F_201 ( V_431 ) ;
V_258 -> V_451 = F_121 ( V_104 -> V_443 ) ;
V_258 -> V_452 = V_453 ;
V_258 -> V_454 = V_455 ;
V_258 -> V_456 =
F_203 ( V_14 , V_102 ) ;
V_258 -> V_457 = F_92 ( T_27 , V_458 ) / 4 ;
F_122 ( V_117 -> V_109 , (struct V_278 * )
V_258 -> V_279 ) ;
memcpy ( V_258 -> V_415 . V_459 , V_104 -> V_396 , V_104 -> V_443 ) ;
if ( V_258 -> V_449 ) {
if ( V_14 -> V_460 ( V_14 , V_104 , V_102 ) ) {
F_178 ( V_14 , V_102 ) ;
goto V_89;
}
} else
V_14 -> V_461 ( V_14 , & V_258 -> V_458 ) ;
V_56 = V_118 -> V_56 ;
if ( V_56 && V_56 -> V_462 )
F_204 ( V_14 , V_104 , V_56 , V_258 ,
V_102 ) ;
if ( F_171 ( V_258 -> V_274 == V_447 ) ) {
if ( V_118 -> V_76 & V_140 ) {
V_258 -> V_451 = F_121 ( V_104 -> V_443 |
V_463 ) ;
F_205 ( V_14 , V_102 , V_35 ) ;
} else
F_206 ( V_14 , V_102 ,
F_21 ( V_258 -> V_200 ) ) ;
} else
F_169 ( V_14 , V_102 ) ;
return 0 ;
V_89:
return V_434 ;
}
static void
F_207 ( char * V_426 , struct V_464 * V_465 )
{
if ( ( V_426 [ 0 ] & 0x7F ) >= 0x72 ) {
V_465 -> V_466 = V_426 [ 1 ] & 0x0F ;
V_465 -> V_467 = V_426 [ 2 ] ;
V_465 -> V_422 = V_426 [ 3 ] ;
} else {
V_465 -> V_466 = V_426 [ 2 ] & 0x0F ;
V_465 -> V_467 = V_426 [ 12 ] ;
V_465 -> V_422 = V_426 [ 13 ] ;
}
}
static void
F_208 ( struct V_13 * V_14 , struct V_101 * V_104 ,
T_29 * V_37 , T_4 V_102 )
{
T_10 V_468 ;
T_6 * V_469 ;
T_4 V_38 = F_21 ( V_37 -> V_46 ) &
V_47 ;
T_6 V_470 = V_37 -> V_471 ;
T_6 V_472 = V_37 -> V_473 ;
char * V_474 = NULL ;
char * V_475 = NULL ;
char * V_476 = V_14 -> V_477 ;
T_10 V_478 = F_78 ( V_37 -> V_285 ) ;
struct V_53 * V_54 = NULL ;
struct V_126 * V_85 = V_104 -> V_51 -> V_293 ;
struct V_72 * V_294 = V_85 -> V_120 ;
char * V_295 = NULL ;
if ( ! V_294 )
return;
if ( V_14 -> V_218 )
V_295 = L_57 ;
else
V_295 = L_58 ;
if ( V_478 == 0x31170000 )
return;
switch ( V_38 ) {
case V_48 :
V_474 = L_124 ;
break;
case V_479 :
V_474 = L_125 ;
break;
case V_480 :
V_474 = L_126 ;
break;
case V_481 :
V_474 = L_127 ;
break;
case V_482 :
V_474 = L_128 ;
break;
case V_483 :
V_474 = L_129 ;
break;
case V_484 :
V_474 = L_130 ;
break;
case V_485 :
V_474 = L_131 ;
break;
case V_486 :
V_474 = L_132 ;
break;
case V_487 :
V_474 = L_133 ;
break;
case V_488 :
V_474 = L_134 ;
break;
case V_489 :
V_474 = L_135 ;
break;
case V_490 :
V_474 = L_136 ;
break;
case V_491 :
V_474 = L_137 ;
break;
case V_423 :
V_474 = L_138 ;
break;
case V_425 :
V_474 = L_139 ;
break;
case V_424 :
V_474 = L_140 ;
break;
case V_492 :
V_474 = L_141 ;
break;
default:
V_474 = L_47 ;
break;
}
switch ( V_472 ) {
case V_493 :
V_475 = L_142 ;
break;
case V_494 :
V_475 = L_143 ;
break;
case V_495 :
V_475 = L_144 ;
break;
case V_496 :
V_475 = L_145 ;
break;
case V_497 :
V_475 = L_146 ;
break;
case V_498 :
V_475 = L_147 ;
break;
case V_499 :
V_475 = L_148 ;
break;
case V_500 :
V_475 = L_149 ;
break;
case V_501 :
V_475 = L_150 ;
break;
case V_502 :
V_475 = L_151 ;
break;
case V_503 :
V_475 = L_152 ;
break;
default:
V_475 = L_47 ;
break;
}
V_476 [ 0 ] = '\0' ;
if ( ! V_470 )
V_476 = L_118 ;
if ( V_470 & V_504 )
strcat ( V_476 , L_153 ) ;
if ( V_470 & V_505 )
strcat ( V_476 , L_154 ) ;
if ( V_470 & V_506 )
strcat ( V_476 , L_155 ) ;
if ( V_470 & V_507 )
strcat ( V_476 , L_156 ) ;
if ( V_470 & V_508 )
strcat ( V_476 , L_157 ) ;
F_133 ( V_104 ) ;
if ( V_294 -> V_76 & V_123 ) {
F_91 ( V_42 L_158 , V_14 -> V_43 ,
V_295 , ( unsigned long long ) V_294 -> V_17 ) ;
} else {
V_54 = F_31 ( V_14 , V_294 ) ;
if ( V_54 ) {
F_91 ( V_42
L_159 ,
V_14 -> V_43 , ( unsigned long long )
V_54 -> V_17 , V_54 -> V_225 ) ;
if ( V_54 -> V_78 != 0 )
F_91 ( V_42
L_160
L_161 , V_14 -> V_43 ,
( unsigned long long )
V_54 -> V_22 ,
V_54 -> V_26 ) ;
if ( V_54 -> V_79 [ 0 ] )
F_91 ( V_42
L_162
L_97 , V_14 -> V_43 ,
V_54 -> V_80 ,
V_54 -> V_79 ) ;
F_41 ( V_54 ) ;
}
}
F_91 ( V_42
L_163 ,
V_14 -> V_43 , F_21 ( V_37 -> V_200 ) ,
V_474 , V_38 , V_102 ) ;
F_91 ( V_42
L_164 ,
V_14 -> V_43 , F_202 ( V_104 ) , V_104 -> V_509 ,
F_209 ( V_104 ) ) ;
F_91 ( V_42
L_165 ,
V_14 -> V_43 , F_21 ( V_37 -> V_510 ) ,
F_78 ( V_37 -> V_511 ) , V_104 -> V_296 ) ;
F_91 ( V_42
L_166 ,
V_14 -> V_43 , V_475 ,
V_472 , V_476 , V_470 ) ;
if ( V_470 & V_508 ) {
struct V_464 V_465 ;
F_207 ( V_104 -> V_426 , & V_465 ) ;
F_91 ( V_42
L_167 ,
V_14 -> V_43 , V_465 . V_466 ,
V_465 . V_467 , V_465 . V_422 , F_78 ( V_37 -> V_512 ) ) ;
}
if ( V_470 & V_504 ) {
V_468 = F_78 ( V_37 -> V_513 ) ;
V_469 = ( T_6 * ) & V_468 ;
F_105 ( V_14 , V_469 [ 0 ] ) ;
}
}
static void
F_210 ( struct V_13 * V_14 , T_4 V_35 )
{
T_30 V_37 ;
T_31 V_258 ;
struct V_53 * V_54 ;
V_54 = F_37 ( V_14 , V_35 ) ;
if ( ! V_54 )
return;
memset ( & V_258 , 0 , sizeof( T_31 ) ) ;
V_258 . V_274 = V_514 ;
V_258 . V_515 = V_516 ;
V_258 . V_517 =
F_201 ( V_518 ) ;
V_258 . V_200 = F_121 ( V_35 ) ;
V_258 . V_145 = V_519 ;
if ( ( F_211 ( V_14 , & V_37 ,
& V_258 ) ) != 0 ) {
F_25 ( V_42 L_2 , V_14 -> V_43 ,
__FILE__ , __LINE__ , V_44 ) ;
goto V_89;
}
V_54 -> V_520 = 1 ;
if ( V_37 . V_46 || V_37 . V_285 ) {
F_46 ( V_14 , F_13 ( V_42
L_168 ,
V_14 -> V_43 , F_21 ( V_37 . V_46 ) ,
F_78 ( V_37 . V_285 ) ) ) ;
goto V_89;
}
V_89:
F_41 ( V_54 ) ;
}
static void
F_212 ( struct V_13 * V_14 ,
struct V_53 * V_54 )
{
T_30 V_37 ;
T_31 V_258 ;
memset ( & V_258 , 0 , sizeof( T_31 ) ) ;
V_258 . V_274 = V_514 ;
V_258 . V_515 = V_516 ;
V_258 . V_517 = 0 ;
V_258 . V_521 = F_121 ( V_54 -> V_26 ) ;
V_258 . V_200 = 0 ;
V_258 . V_522 = F_121 ( V_54 -> V_78 ) ;
V_258 . V_145 = V_523 ;
if ( ( F_211 ( V_14 , & V_37 ,
& V_258 ) ) != 0 ) {
F_213 ( V_42 L_2 , V_14 -> V_43 ,
__FILE__ , __LINE__ , V_44 ) ;
return;
}
if ( V_37 . V_46 || V_37 . V_285 ) {
F_46 ( V_14 , F_213 ( V_42
L_168 ,
V_14 -> V_43 , F_21 ( V_37 . V_46 ) ,
F_78 ( V_37 . V_285 ) ) ) ;
return;
}
}
static void
F_214 ( struct V_13 * V_14 , T_4 V_35 )
{
struct V_3 * V_7 ;
V_7 = F_8 ( 0 ) ;
if ( ! V_7 )
return;
V_7 -> V_309 = V_524 ;
V_7 -> V_525 = V_35 ;
V_7 -> V_14 = V_14 ;
F_140 ( V_14 , V_7 ) ;
F_6 ( V_7 ) ;
}
static void
F_215 ( struct V_13 * V_14 , T_4 V_35 )
{
struct V_126 * V_85 ;
struct V_72 * V_118 ;
T_32 * V_526 ;
T_33 * V_308 ;
struct V_53 * V_54 ;
T_34 V_193 ;
unsigned long V_76 ;
F_32 ( & V_14 -> V_74 , V_76 ) ;
V_54 = F_36 ( V_14 , V_35 ) ;
if ( ! V_54 )
goto V_527;
V_85 = V_54 -> V_85 ;
V_118 = V_85 -> V_120 ;
if ( ( V_118 -> V_76 & V_138 ) ||
( ( V_118 -> V_76 & V_123 ) ) )
goto V_527;
if ( V_54 -> V_78 != 0 )
F_134 ( V_144 , V_85 , L_169
L_170 ,
( unsigned long long ) V_54 -> V_22 ,
V_54 -> V_26 ) ;
if ( V_54 -> V_79 [ 0 ] != '\0' )
F_134 ( V_223 , V_85 , L_169
L_171 ,
V_54 -> V_80 ,
V_54 -> V_79 ) ;
F_33 ( & V_14 -> V_74 , V_76 ) ;
if ( V_14 -> V_528 -> V_529 == V_530 )
F_214 ( V_14 , V_35 ) ;
V_193 = F_92 ( T_32 , V_531 ) +
sizeof( T_33 ) ;
V_526 = F_9 ( V_193 , V_130 ) ;
if ( ! V_526 ) {
F_25 ( V_42 L_2 ,
V_14 -> V_43 , __FILE__ , __LINE__ , V_44 ) ;
goto V_89;
}
V_526 -> V_274 = V_532 ;
V_526 -> V_358 =
F_121 ( V_533 ) ;
V_526 -> V_249 = V_193 / 4 ;
V_526 -> V_534 =
F_121 ( sizeof( T_33 ) / 4 ) ;
V_308 = ( T_33 * )
V_526 -> V_531 ;
V_308 -> V_384 = V_535 ;
V_308 -> V_536 = 0x5D ;
V_308 -> V_200 = F_121 ( V_35 ) ;
V_308 -> V_19 = F_216 ( V_118 -> V_17 ) ;
F_217 ( V_14 , V_526 ) ;
F_2 ( V_526 ) ;
V_89:
if ( V_54 )
F_41 ( V_54 ) ;
return;
V_527:
F_33 ( & V_14 -> V_74 , V_76 ) ;
goto V_89;
}
static T_6
F_218 ( struct V_13 * V_14 , T_4 V_102 , T_6 V_243 , T_10 V_244 )
{
T_27 * V_258 ;
T_29 * V_37 ;
struct V_101 * V_104 ;
T_4 V_38 ;
T_10 V_537 ;
T_6 V_470 ;
T_6 V_472 ;
T_10 V_478 ;
struct V_116 * V_117 ;
T_10 V_234 = 0 ;
unsigned long V_76 ;
V_37 = F_107 ( V_14 , V_244 ) ;
V_104 = F_62 ( V_14 , V_102 ) ;
if ( V_104 == NULL )
return 1 ;
if ( F_189 ( V_104 ) )
F_156 ( V_104 -> V_51 , V_315 ) ;
V_258 = F_120 ( V_14 , V_102 ) ;
if ( V_37 == NULL ) {
V_104 -> V_296 = V_538 << 16 ;
goto V_89;
}
V_117 = V_104 -> V_51 -> V_120 ;
if ( ! V_117 || ! V_117 -> V_122 ||
V_117 -> V_122 -> V_336 ) {
V_104 -> V_296 = V_297 << 16 ;
goto V_89;
}
V_38 = F_21 ( V_37 -> V_46 ) ;
if ( F_219 ( V_14 , V_102 ) &&
( ( V_38 & V_47 )
!= V_487 ) ) {
F_32 ( & V_14 -> V_105 , V_76 ) ;
V_14 -> V_103 [ V_102 - 1 ] . V_104 = V_104 ;
F_33 ( & V_14 -> V_105 , V_76 ) ;
F_220 ( V_14 , V_102 , 0 ) ;
memcpy ( V_258 -> V_415 . V_459 , V_104 -> V_396 , V_104 -> V_443 ) ;
V_258 -> V_200 =
F_121 ( V_117 -> V_122 -> V_35 ) ;
F_206 ( V_14 , V_102 ,
V_117 -> V_122 -> V_35 ) ;
return 0 ;
}
V_470 = V_37 -> V_471 ;
if ( V_470 & V_504 )
V_234 =
F_78 ( V_37 -> V_513 ) & 0xFF ;
if ( ! V_117 -> V_539 ) {
V_117 -> V_539 ++ ;
if ( ! V_14 -> V_134 &&
! F_79 ( & V_104 -> V_51 -> V_191 ) &&
F_96 ( V_104 -> V_51 ) &&
V_234 == V_237 ) {
F_221 ( V_104 -> V_51 ) ;
F_75 ( V_144 , V_104 -> V_51 , L_172 ) ;
}
}
V_537 = F_78 ( V_37 -> V_511 ) ;
F_222 ( V_104 , F_202 ( V_104 ) - V_537 ) ;
if ( V_38 & V_540 )
V_478 = F_78 ( V_37 -> V_285 ) ;
else
V_478 = 0 ;
V_38 &= V_47 ;
V_472 = V_37 -> V_473 ;
if ( V_38 == V_484 && V_537 == 0 &&
( V_472 == V_496 ||
V_472 == V_499 ||
V_472 == V_501 ) ) {
V_38 = V_48 ;
}
if ( V_470 & V_508 ) {
struct V_464 V_465 ;
const void * V_541 = F_223 ( V_14 ,
V_102 ) ;
T_10 V_193 = F_224 ( T_10 , V_455 ,
F_78 ( V_37 -> V_512 ) ) ;
memcpy ( V_104 -> V_426 , V_541 , V_193 ) ;
F_207 ( V_104 -> V_426 , & V_465 ) ;
if ( V_465 . V_467 == 0x5D )
F_215 ( V_14 ,
F_21 ( V_37 -> V_200 ) ) ;
F_225 ( V_14 , V_465 . V_466 , V_465 . V_467 , V_465 . V_422 ) ;
if ( ( V_14 -> V_15 & V_542 ) &&
( ( V_104 -> V_426 [ 2 ] == V_543 ) ||
( V_104 -> V_426 [ 2 ] == V_544 ) ||
( V_104 -> V_426 [ 2 ] == V_545 ) ) )
F_208 ( V_14 , V_104 , V_37 , V_102 ) ;
}
switch ( V_38 ) {
case V_546 :
case V_547 :
V_104 -> V_296 = V_548 ;
break;
case V_482 :
V_104 -> V_296 = V_297 << 16 ;
break;
case V_490 :
if ( V_117 -> V_313 ) {
V_104 -> V_296 = V_549 << 16 ;
goto V_89;
}
if ( V_478 == 0x31110630 ) {
if ( V_104 -> V_550 > 2 ) {
V_104 -> V_296 = V_297 << 16 ;
F_226 ( V_104 -> V_51 ,
V_551 ) ;
} else {
V_104 -> V_296 = V_552 << 16 ;
V_104 -> V_51 -> V_553 = 1 ;
}
break;
} else if ( V_478 == V_554 ) {
V_104 -> V_296 = V_299 << 16 ;
break;
}
V_104 -> V_296 = V_552 << 16 ;
break;
case V_487 :
case V_491 :
V_104 -> V_296 = V_299 << 16 ;
break;
case V_488 :
if ( ( V_537 == 0 ) || ( V_104 -> V_509 > V_537 ) )
V_104 -> V_296 = V_552 << 16 ;
else
V_104 -> V_296 = ( V_538 << 16 ) | V_472 ;
break;
case V_484 :
V_104 -> V_296 = ( V_538 << 16 ) | V_472 ;
if ( ( V_470 & V_508 ) )
break;
if ( V_537 < V_104 -> V_509 ) {
if ( V_472 == V_548 )
V_104 -> V_296 = V_548 ;
else
V_104 -> V_296 = V_552 << 16 ;
} else if ( V_470 & ( V_507 |
V_506 ) )
V_104 -> V_296 = V_552 << 16 ;
else if ( V_470 & V_505 )
V_104 -> V_296 = V_299 << 16 ;
else if ( ! V_537 && V_104 -> V_396 [ 0 ] == V_555 ) {
V_37 -> V_471 = V_508 ;
V_37 -> V_473 = V_430 ;
V_104 -> V_296 = ( V_428 << 24 ) |
V_430 ;
V_104 -> V_426 [ 0 ] = 0x70 ;
V_104 -> V_426 [ 2 ] = V_427 ;
V_104 -> V_426 [ 12 ] = 0x20 ;
V_104 -> V_426 [ 13 ] = 0 ;
}
break;
case V_483 :
F_222 ( V_104 , 0 ) ;
case V_480 :
case V_48 :
V_104 -> V_296 = ( V_538 << 16 ) | V_472 ;
if ( V_234 ==
V_237 ||
( V_470 & ( V_507 |
V_506 ) ) )
V_104 -> V_296 = V_552 << 16 ;
else if ( V_470 & V_505 )
V_104 -> V_296 = V_299 << 16 ;
break;
case V_423 :
case V_425 :
case V_424 :
F_197 ( V_104 , V_38 ) ;
break;
case V_486 :
case V_479 :
case V_556 :
case V_557 :
case V_558 :
case V_559 :
case V_485 :
case V_489 :
case V_492 :
default:
V_104 -> V_296 = V_552 << 16 ;
break;
}
if ( V_104 -> V_296 && ( V_14 -> V_15 & V_542 ) )
F_208 ( V_14 , V_104 , V_37 , V_102 ) ;
V_89:
F_191 ( V_104 ) ;
V_104 -> V_298 ( V_104 ) ;
return 1 ;
}
static void
F_227 ( struct V_13 * V_14 )
{
T_4 V_193 ;
T_4 V_38 ;
int V_106 ;
T_9 V_37 ;
T_35 * V_560 = NULL ;
T_4 V_561 ;
T_6 V_562 ;
F_119 ( V_14 , F_13 ( V_42
L_173 ,
V_14 -> V_43 , ( unsigned long long ) V_14 -> V_39 . V_17 ) ) ;
V_193 = F_92 ( T_35 , V_563 ) + ( V_14 -> V_39 . V_40
* sizeof( V_564 ) ) ;
V_560 = F_9 ( V_193 , V_130 ) ;
if ( ! V_560 ) {
F_25 ( V_42 L_2 ,
V_14 -> V_43 , __FILE__ , __LINE__ , V_44 ) ;
return;
}
if ( ( F_228 ( V_14 , & V_37 ,
V_560 , V_193 ) ) != 0 )
goto V_89;
V_38 = F_21 ( V_37 . V_46 ) & V_47 ;
if ( V_38 != V_48 )
goto V_89;
for ( V_106 = 0 ; V_106 < V_14 -> V_39 . V_40 ; V_106 ++ ) {
V_562 = V_560 -> V_563 [ V_106 ] . V_565 >> 4 ;
if ( V_106 == 0 )
V_14 -> V_39 . V_35 = F_21 ( V_560 ->
V_563 [ 0 ] . V_566 ) ;
V_14 -> V_39 . V_225 [ V_106 ] . V_35 = V_14 -> V_39 . V_35 ;
V_561 = F_21 ( V_560 -> V_563 [ V_106 ] .
V_329 ) ;
if ( V_561 && V_562 < V_567 )
V_562 = V_567 ;
F_229 ( V_14 , V_14 -> V_39 . V_17 ,
V_561 , V_106 , V_562 ) ;
}
V_89:
F_2 ( V_560 ) ;
}
static void
F_230 ( struct V_13 * V_14 )
{
int V_106 ;
T_9 V_37 ;
T_35 * V_560 = NULL ;
T_36 * V_568 = NULL ;
T_37 V_569 ;
T_8 V_36 ;
T_38 V_570 ;
T_4 V_38 ;
T_4 V_193 ;
T_6 V_571 ;
T_6 V_40 ;
F_231 ( V_14 , & V_40 ) ;
if ( ! V_40 ) {
F_25 ( V_42 L_2 ,
V_14 -> V_43 , __FILE__ , __LINE__ , V_44 ) ;
return;
}
V_14 -> V_39 . V_225 = F_232 ( V_40 ,
sizeof( struct V_572 ) , V_130 ) ;
if ( ! V_14 -> V_39 . V_225 ) {
F_25 ( V_42 L_2 ,
V_14 -> V_43 , __FILE__ , __LINE__ , V_44 ) ;
goto V_89;
}
V_14 -> V_39 . V_40 = V_40 ;
V_193 = F_92 ( T_35 , V_563 ) + ( V_14 -> V_39 . V_40 *
sizeof( V_564 ) ) ;
V_560 = F_9 ( V_193 , V_130 ) ;
if ( ! V_560 ) {
F_25 ( V_42 L_2 ,
V_14 -> V_43 , __FILE__ , __LINE__ , V_44 ) ;
return;
}
if ( ( F_228 ( V_14 , & V_37 ,
V_560 , V_193 ) ) ) {
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
V_193 = F_92 ( T_36 , V_563 ) + ( V_14 -> V_39 . V_40 *
sizeof( V_573 ) ) ;
V_568 = F_9 ( V_193 , V_130 ) ;
if ( ! V_568 ) {
F_25 ( V_42 L_2 ,
V_14 -> V_43 , __FILE__ , __LINE__ , V_44 ) ;
goto V_89;
}
if ( ( F_233 ( V_14 , & V_37 ,
V_568 , V_193 ) ) ) {
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
V_14 -> V_574 =
V_568 -> V_575 ;
V_571 =
V_568 -> V_576 ;
if ( V_571 & V_577 )
V_14 -> V_571 = ( V_571 &
V_578 ) * 16 ;
else
V_14 -> V_571 = V_571 &
V_578 ;
V_14 -> V_39 . V_579 = & V_14 -> V_113 -> V_580 ;
for ( V_106 = 0 ; V_106 < V_14 -> V_39 . V_40 ; V_106 ++ ) {
if ( ( F_234 ( V_14 , & V_37 , & V_569 ,
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
V_14 -> V_39 . V_35 = F_21 ( V_560 ->
V_563 [ 0 ] . V_566 ) ;
V_14 -> V_39 . V_225 [ V_106 ] . V_35 = V_14 -> V_39 . V_35 ;
V_14 -> V_39 . V_225 [ V_106 ] . V_581 = V_106 ;
F_235 ( V_14 , & V_14 -> V_39 . V_225 [ V_106 ] ,
V_569 , V_14 -> V_39 . V_579 ) ;
}
if ( ( F_24 ( V_14 , & V_37 , & V_36 ,
V_41 , V_14 -> V_39 . V_35 ) ) ) {
F_25 ( V_42 L_2 ,
V_14 -> V_43 , __FILE__ , __LINE__ , V_44 ) ;
goto V_89;
}
V_14 -> V_39 . V_78 =
F_21 ( V_36 . V_522 ) ;
V_14 -> V_39 . V_17 = F_18 ( V_36 . V_19 ) ;
F_13 ( V_42
L_174 ,
V_14 -> V_43 , V_14 -> V_39 . V_35 ,
( unsigned long long ) V_14 -> V_39 . V_17 ,
V_14 -> V_39 . V_40 ) ;
if ( V_14 -> V_39 . V_78 ) {
if ( ! ( F_236 ( V_14 , & V_37 ,
& V_570 , V_582 ,
V_14 -> V_39 . V_78 ) ) )
V_14 -> V_39 . V_22 =
F_18 ( V_570 . V_24 ) ;
}
V_89:
F_2 ( V_568 ) ;
F_2 ( V_560 ) ;
}
static int
F_237 ( struct V_13 * V_14 , T_4 V_35 )
{
struct V_92 * V_93 ;
T_9 V_37 ;
T_39 V_583 ;
T_40 V_584 ;
T_38 V_570 ;
T_10 V_38 ;
T_4 V_585 ;
T_1 V_17 , V_84 = 0 ;
int V_106 ;
unsigned long V_76 ;
struct V_317 * V_318 = NULL ;
int V_28 = 0 ;
if ( ! V_35 )
return - 1 ;
if ( V_14 -> V_82 || V_14 -> V_265 )
return - 1 ;
if ( ( F_238 ( V_14 , & V_37 , & V_583 ,
V_586 , V_35 ) ) ) {
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
V_585 = F_21 ( V_583 . V_587 ) ;
if ( F_23 ( V_14 , V_585 , & V_84 )
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
V_28 = F_237 ( V_14 , V_585 ) ;
if ( V_28 != 0 )
return V_28 ;
}
}
F_32 ( & V_14 -> V_94 , V_76 ) ;
V_17 = F_18 ( V_583 . V_19 ) ;
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
V_93 -> V_40 = V_583 . V_588 ;
V_93 -> V_84 = V_84 ;
V_93 -> V_17 = V_17 ;
F_13 ( V_42 L_175 \
L_176 , V_14 -> V_43 ,
V_35 , V_585 , ( unsigned long long )
V_93 -> V_17 , V_93 -> V_40 ) ;
if ( ! V_93 -> V_40 )
goto V_589;
V_93 -> V_225 = F_232 ( V_93 -> V_40 ,
sizeof( struct V_572 ) , V_130 ) ;
if ( ! V_93 -> V_225 ) {
F_25 ( V_42 L_2 ,
V_14 -> V_43 , __FILE__ , __LINE__ , V_44 ) ;
V_28 = - 1 ;
goto V_589;
}
F_141 ( & V_93 -> V_590 ) ;
V_318 = F_48 ( V_14 , V_35 ,
V_84 ) ;
if ( ! V_318 ) {
F_25 ( V_42 L_2 ,
V_14 -> V_43 , __FILE__ , __LINE__ , V_44 ) ;
V_28 = - 1 ;
goto V_589;
}
V_93 -> V_579 = & V_318 -> V_129 -> V_127 ;
for ( V_106 = 0 ; V_106 < V_93 -> V_40 ; V_106 ++ ) {
if ( ( F_239 ( V_14 , & V_37 ,
& V_584 , V_106 , V_35 ) ) ) {
F_25 ( V_42 L_2 ,
V_14 -> V_43 , __FILE__ , __LINE__ , V_44 ) ;
V_28 = - 1 ;
goto V_589;
}
V_93 -> V_225 [ V_106 ] . V_35 = V_35 ;
V_93 -> V_225 [ V_106 ] . V_581 = V_106 ;
if ( ( F_240 ( V_14 ,
& V_93 -> V_225 [ V_106 ] , V_584 ,
V_93 -> V_579 ) ) ) {
F_25 ( V_42 L_2 ,
V_14 -> V_43 , __FILE__ , __LINE__ , V_44 ) ;
V_28 = - 1 ;
goto V_589;
}
}
if ( V_93 -> V_78 ) {
if ( ! ( F_236 ( V_14 , & V_37 ,
& V_570 , V_582 ,
V_93 -> V_78 ) ) )
V_93 -> V_22 =
F_18 ( V_570 . V_24 ) ;
}
F_59 ( V_14 , V_93 ) ;
return 0 ;
V_589:
if ( V_318 )
F_49 ( V_14 , V_93 -> V_17 ,
V_84 ) ;
F_2 ( V_93 ) ;
return V_28 ;
}
void
F_241 ( struct V_13 * V_14 , T_1 V_17 )
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
F_242 ( V_14 , V_93 ) ;
}
static T_6
F_243 ( struct V_13 * V_14 , T_4 V_102 , T_6 V_243 , T_10 V_244 )
{
T_15 * V_37 ;
V_37 = F_107 ( V_14 , V_244 ) ;
if ( V_14 -> V_591 . V_246 == V_247 )
return 1 ;
if ( V_14 -> V_591 . V_102 != V_102 )
return 1 ;
V_14 -> V_591 . V_246 |= V_248 ;
if ( V_37 ) {
memcpy ( V_14 -> V_591 . V_244 , V_37 ,
V_37 -> V_249 * 4 ) ;
V_14 -> V_591 . V_246 |= V_250 ;
}
V_14 -> V_591 . V_246 &= ~ V_251 ;
F_108 ( & V_14 -> V_591 . V_252 ) ;
return 1 ;
}
static T_6
F_244 ( struct V_13 * V_14 , T_1 V_17 ,
T_4 V_35 , T_6 V_592 )
{
T_6 V_28 = 1 ;
char * V_235 = NULL ;
switch ( V_592 ) {
case V_593 :
case V_594 :
V_28 = 0 ;
break;
case V_595 :
V_235 = L_177 ;
break;
case V_596 :
V_235 = L_178 ;
break;
case V_597 :
V_235 = L_179 ;
break;
case V_598 :
V_235 = L_180 ;
break;
case V_599 :
V_235 = L_181 ;
break;
case V_600 :
case V_601 :
case V_602 :
case V_603 :
case V_604 :
case V_605 :
case V_606 :
case V_607 :
case V_608 :
case V_609 :
case V_610 :
case V_611 :
V_235 = L_182 ;
break;
default:
V_235 = L_47 ;
break;
}
if ( ! V_28 )
return 0 ;
F_25 ( V_42
L_183 ,
V_14 -> V_43 , V_235 , ( unsigned long long ) V_17 , V_35 ) ;
return V_28 ;
}
static void
F_245 ( struct V_13 * V_14 ,
T_1 V_612 , T_4 V_35 , T_6 V_613 , T_6 V_562 )
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
if ( V_613 != V_36 . V_614 )
return;
V_96 = F_78 ( V_36 . V_146 ) ;
if ( ! ( F_60 ( V_96 ) ) )
return;
F_32 ( & V_14 -> V_74 , V_76 ) ;
V_17 = F_18 ( V_36 . V_19 ) ;
V_54 = F_34 ( V_14 ,
V_17 ) ;
if ( ! V_54 )
goto V_527;
if ( F_166 ( V_54 -> V_35 != V_35 ) ) {
V_85 = V_54 -> V_85 ;
V_118 = V_85 -> V_120 ;
F_134 ( V_144 , V_85 ,
L_184 ,
V_54 -> V_35 , V_35 ) ;
V_118 -> V_35 = V_35 ;
V_54 -> V_35 = V_35 ;
if ( V_36 . V_145 &
V_615 ) {
V_54 -> V_80 =
F_21 ( V_36 . V_616 ) ;
memcpy ( V_54 -> V_79 ,
V_36 . V_617 , 4 ) ;
V_54 -> V_79 [ 4 ] = '\0' ;
} else {
V_54 -> V_80 = 0 ;
V_54 -> V_79 [ 0 ] = '\0' ;
}
}
if ( ! ( F_21 ( V_36 . V_145 ) &
V_618 ) ) {
F_25 ( V_42
L_185 ,
V_14 -> V_43 , V_35 ) ;
goto V_527;
}
if ( F_244 ( V_14 , V_17 , V_35 ,
V_36 . V_619 ) )
goto V_527;
F_33 ( & V_14 -> V_74 , V_76 ) ;
F_158 ( V_14 , V_17 ) ;
if ( V_54 )
F_41 ( V_54 ) ;
return;
V_527:
F_33 ( & V_14 -> V_74 , V_76 ) ;
if ( V_54 )
F_41 ( V_54 ) ;
}
static int
F_246 ( struct V_13 * V_14 , T_4 V_35 , T_6 V_620 ,
T_6 V_621 )
{
T_9 V_37 ;
T_8 V_36 ;
T_38 V_570 ;
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
V_618 ) ) {
F_25 ( V_42 L_186 ,
V_14 -> V_43 , V_35 ) ;
return - 1 ;
}
if ( F_244 ( V_14 , V_17 , V_35 ,
V_36 . V_619 ) )
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
F_21 ( V_36 . V_587 ) ,
& V_54 -> V_84 ) != 0 )
F_25 ( V_42 L_2 ,
V_14 -> V_43 , __FILE__ , __LINE__ , V_44 ) ;
V_54 -> V_78 =
F_21 ( V_36 . V_522 ) ;
if ( V_54 -> V_78 != 0 )
V_54 -> V_26 =
F_21 ( V_36 . V_521 ) ;
V_54 -> V_96 = V_96 ;
V_54 -> V_17 = V_17 ;
V_54 -> V_225 = V_36 . V_614 ;
V_54 -> V_139 = ( F_21 ( V_36 . V_145 ) &
V_622 ) ? 1 : 0 ;
if ( V_36 . V_145 & V_615 ) {
V_54 -> V_80 =
F_21 ( V_36 . V_616 ) ;
memcpy ( V_54 -> V_79 ,
V_36 . V_617 , 4 ) ;
V_54 -> V_79 [ 4 ] = '\0' ;
} else {
V_54 -> V_80 = 0 ;
V_54 -> V_79 [ 0 ] = '\0' ;
}
if ( V_54 -> V_78 && ! ( F_236 (
V_14 , & V_37 , & V_570 , V_582 ,
V_54 -> V_78 ) ) )
V_54 -> V_22 =
F_18 ( V_570 . V_24 ) ;
V_54 -> V_20 = F_18 ( V_36 . V_21 ) ;
if ( V_14 -> V_623 )
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
if ( ( V_14 -> V_528 -> V_529 == V_530 ) &&
( V_54 -> V_520 ) ) {
F_212 ( V_14 , V_54 ) ;
V_54 -> V_520 = 0 ;
}
F_46 ( V_14 , F_13 ( V_42
L_187 ,
V_14 -> V_43 , V_44 ,
V_54 -> V_35 , ( unsigned long long )
V_54 -> V_17 ) ) ;
if ( V_54 -> V_78 != 0 )
F_46 ( V_14 , F_13 ( V_42
L_188 ,
V_14 -> V_43 , V_44 ,
( unsigned long long ) V_54 -> V_22 ,
V_54 -> V_26 ) ) ;
if ( V_54 -> V_79 [ 0 ] != '\0' )
F_46 ( V_14 , F_13 ( V_42
L_189 ,
V_14 -> V_43 , V_44 ,
V_54 -> V_80 ,
V_54 -> V_79 ) ) ;
if ( V_54 -> V_85 && V_54 -> V_85 -> V_120 ) {
V_118 = V_54 -> V_85 -> V_120 ;
V_118 -> V_336 = 1 ;
F_158 ( V_14 , V_54 -> V_17 ) ;
V_118 -> V_35 =
V_132 ;
}
if ( ! V_14 -> V_624 )
F_49 ( V_14 ,
V_54 -> V_17 ,
V_54 -> V_84 ) ;
F_13 ( V_42
L_7 ,
V_14 -> V_43 , V_54 -> V_35 ,
( unsigned long long ) V_54 -> V_17 ) ;
if ( V_54 -> V_78 != 0 )
F_13 ( V_42
L_190 ,
V_14 -> V_43 ,
( unsigned long long ) V_54 -> V_22 ,
V_54 -> V_26 ) ;
if ( V_54 -> V_79 [ 0 ] != '\0' )
F_13 ( V_42
L_9 ,
V_14 -> V_43 , V_54 -> V_80 ,
V_54 -> V_79 ) ;
F_46 ( V_14 , F_13 ( V_42
L_191 ,
V_14 -> V_43 , V_44 ,
V_54 -> V_35 , ( unsigned long long )
V_54 -> V_17 ) ) ;
if ( V_54 -> V_78 != 0 )
F_46 ( V_14 , F_13 ( V_42
L_192 ,
V_14 -> V_43 , V_44 ,
( unsigned long long ) V_54 -> V_22 ,
V_54 -> V_26 ) ) ;
if ( V_54 -> V_79 [ 0 ] != '\0' )
F_46 ( V_14 , F_13 ( V_42
L_193 ,
V_14 -> V_43 , V_44 , V_54 -> V_80 ,
V_54 -> V_79 ) ) ;
}
static void
F_247 ( struct V_13 * V_14 ,
T_19 * V_308 )
{
int V_106 ;
T_4 V_35 ;
T_4 V_326 ;
T_6 V_613 ;
char * V_625 = NULL ;
T_6 V_562 , V_626 ;
switch ( V_308 -> V_370 ) {
case V_377 :
V_625 = L_194 ;
break;
case V_374 :
V_625 = L_195 ;
break;
case V_373 :
case 0 :
V_625 = L_196 ;
break;
case V_371 :
V_625 = L_197 ;
break;
default:
V_625 = L_198 ;
break;
}
F_13 ( V_42 L_199 ,
V_14 -> V_43 , V_625 ) ;
F_13 ( L_200 \
L_201 ,
F_21 ( V_308 -> V_369 ) ,
F_21 ( V_308 -> V_522 ) ,
V_308 -> V_627 , V_308 -> V_327 ) ;
for ( V_106 = 0 ; V_106 < V_308 -> V_327 ; V_106 ++ ) {
V_35 = F_21 ( V_308 -> V_328 [ V_106 ] . V_329 ) ;
if ( ! V_35 )
continue;
V_613 = V_308 -> V_627 + V_106 ;
V_326 = V_308 -> V_328 [ V_106 ] . V_330 &
V_331 ;
switch ( V_326 ) {
case V_628 :
V_625 = L_202 ;
break;
case V_368 :
V_625 = L_203 ;
break;
case V_332 :
V_625 = L_204 ;
break;
case V_629 :
V_625 = L_205 ;
break;
case V_630 :
V_625 = L_206 ;
break;
default:
V_625 = L_47 ;
break;
}
V_562 = V_308 -> V_328 [ V_106 ] . V_631 >> 4 ;
V_626 = V_308 -> V_328 [ V_106 ] . V_631 & 0xF ;
F_13 ( L_207 \
L_208 , V_613 ,
V_35 , V_625 , V_562 , V_626 ) ;
}
}
static int
F_248 ( struct V_13 * V_14 ,
struct V_3 * V_7 )
{
int V_106 ;
T_4 V_585 , V_35 ;
T_4 V_326 ;
T_6 V_613 , V_632 ;
struct V_92 * V_93 ;
T_1 V_17 ;
unsigned long V_76 ;
T_6 V_562 , V_626 ;
T_19 * V_308 =
( T_19 * )
V_7 -> V_308 ;
if ( V_14 -> V_15 & V_633 )
F_247 ( V_14 , V_308 ) ;
if ( V_14 -> V_82 || V_14 -> V_264 || V_14 -> V_265 )
return 0 ;
if ( ! V_14 -> V_39 . V_40 )
F_230 ( V_14 ) ;
else
F_227 ( V_14 ) ;
if ( V_7 -> V_376 ) {
F_46 ( V_14 , F_13 ( V_42
L_209 , V_14 -> V_43 ) ) ;
return 0 ;
}
V_585 = F_21 ( V_308 -> V_369 ) ;
if ( V_308 -> V_370 == V_377 )
if ( F_237 ( V_14 , V_585 ) != 0 )
return 0 ;
F_32 ( & V_14 -> V_94 , V_76 ) ;
V_93 = F_57 ( V_14 ,
V_585 ) ;
if ( V_93 ) {
V_17 = V_93 -> V_17 ;
V_632 = V_93 -> V_40 ;
} else if ( V_585 < V_14 -> V_39 . V_40 ) {
V_17 = V_14 -> V_39 . V_17 ;
V_632 = V_14 -> V_39 . V_40 ;
} else {
F_33 ( & V_14 -> V_94 , V_76 ) ;
return 0 ;
}
F_33 ( & V_14 -> V_94 , V_76 ) ;
for ( V_106 = 0 ; V_106 < V_308 -> V_327 ; V_106 ++ ) {
if ( V_7 -> V_376 ) {
F_46 ( V_14 , F_13 ( V_42
L_209 , V_14 -> V_43 ) ) ;
return 0 ;
}
if ( V_14 -> V_264 || V_14 -> V_265 )
return 0 ;
V_613 = V_308 -> V_627 + V_106 ;
if ( V_613 >= V_632 )
continue;
V_326 = V_308 -> V_328 [ V_106 ] . V_330 &
V_331 ;
if ( ( V_308 -> V_328 [ V_106 ] . V_330 &
V_634 ) && ( V_326 !=
V_368 ) )
continue;
V_35 = F_21 ( V_308 -> V_328 [ V_106 ] . V_329 ) ;
if ( ! V_35 )
continue;
V_562 = V_308 -> V_328 [ V_106 ] . V_631 >> 4 ;
V_626 = V_308 -> V_328 [ V_106 ] . V_631 & 0xF ;
switch ( V_326 ) {
case V_629 :
if ( V_14 -> V_82 )
break;
if ( V_562 == V_626 )
break;
F_229 ( V_14 , V_17 ,
V_35 , V_613 , V_562 ) ;
if ( V_562 < V_567 )
break;
F_245 ( V_14 , V_17 , V_35 ,
V_613 , V_562 ) ;
case V_628 :
if ( V_14 -> V_82 )
break;
F_229 ( V_14 , V_17 ,
V_35 , V_613 , V_562 ) ;
F_246 ( V_14 , V_35 , V_613 , 0 ) ;
break;
case V_368 :
F_42 ( V_14 , V_35 ) ;
break;
}
}
if ( V_308 -> V_370 == V_374 &&
V_93 )
F_241 ( V_14 , V_17 ) ;
return 0 ;
}
static void
F_249 ( struct V_13 * V_14 ,
T_33 * V_308 )
{
char * V_635 = NULL ;
switch ( V_308 -> V_384 ) {
case V_535 :
V_635 = L_210 ;
break;
case V_636 :
V_635 = L_211 ;
break;
case V_637 :
V_635 = L_212 ;
break;
case V_638 :
V_635 = L_213 ;
break;
case V_639 :
V_635 = L_214 ;
break;
case V_640 :
V_635 = L_215 ;
break;
case V_641 :
V_635 = L_216 ;
break;
case V_642 :
V_635 = L_217 ;
break;
case V_643 :
V_635 = L_218 ;
break;
case V_644 :
V_635 = L_219 ;
break;
case V_645 :
V_635 = L_220 ;
break;
case V_646 :
V_635 = L_221 ;
break;
case V_647 :
V_635 = L_222 ;
break;
default:
V_635 = L_223 ;
break;
}
F_13 ( V_42 L_224
L_225 ,
V_14 -> V_43 , V_635 , F_21 ( V_308 -> V_200 ) ,
( unsigned long long ) F_18 ( V_308 -> V_19 ) ,
F_21 ( V_308 -> V_510 ) ) ;
if ( V_308 -> V_384 == V_535 )
F_13 ( V_42 L_226 , V_14 -> V_43 ,
V_308 -> V_536 , V_308 -> V_648 ) ;
F_13 ( L_227 ) ;
}
static void
F_250 ( struct V_13 * V_14 ,
struct V_3 * V_7 )
{
struct V_72 * V_300 ;
struct V_53 * V_54 ;
T_1 V_17 ;
unsigned long V_76 ;
T_33 * V_308 =
( T_33 * )
V_7 -> V_308 ;
if ( V_14 -> V_15 & V_633 )
F_249 ( V_14 ,
V_308 ) ;
if ( ( V_14 -> V_202 . V_649 >> 8 ) < 0xC )
return;
if ( V_308 -> V_384 !=
V_637 &&
V_308 -> V_384 !=
V_643 )
return;
F_32 ( & V_14 -> V_74 , V_76 ) ;
V_17 = F_18 ( V_308 -> V_19 ) ;
V_54 = F_34 ( V_14 ,
V_17 ) ;
if ( ! V_54 || ! V_54 -> V_85 )
goto V_89;
V_300 = V_54 -> V_85 -> V_120 ;
if ( ! V_300 )
goto V_89;
if ( V_308 -> V_384 ==
V_637 )
V_300 -> V_254 = 1 ;
else
V_300 -> V_254 = 0 ;
V_89:
if ( V_54 )
F_41 ( V_54 ) ;
F_33 ( & V_14 -> V_74 , V_76 ) ;
}
static void
F_251 ( struct V_13 * V_14 ,
T_41 * V_308 )
{
char * V_635 = NULL ;
switch ( V_308 -> V_384 ) {
case V_650 :
V_635 = L_228 ;
break;
case V_651 :
V_635 = L_229 ;
break;
default:
V_635 = L_223 ;
break;
}
F_13 ( V_42 L_230
L_231
L_232 , V_14 -> V_43 , V_635 ,
F_21 ( V_308 -> V_522 ) ,
( unsigned long long ) F_18 ( V_308 -> V_24 ) ,
F_21 ( V_308 -> V_652 ) ) ;
}
static void
F_252 ( struct V_13 * V_14 ,
struct V_3 * V_7 )
{
if ( V_14 -> V_15 & V_633 )
F_251 ( V_14 ,
( T_41 * )
V_7 -> V_308 ) ;
}
static void
F_253 ( struct V_13 * V_14 ,
struct V_3 * V_7 )
{
struct V_101 * V_104 ;
struct V_110 * V_75 ;
T_4 V_102 , V_35 ;
T_10 V_109 ;
struct V_116 * V_117 ;
T_10 V_653 ;
T_10 V_654 ;
T_18 * V_37 ;
T_42 * V_308 =
( T_42 * )
V_7 -> V_308 ;
T_4 V_38 ;
unsigned long V_76 ;
int V_2 ;
T_6 V_655 = 0 ;
T_6 V_656 ;
F_130 ( & V_14 -> V_245 . V_262 ) ;
F_13 ( V_42
L_233 ,
V_14 -> V_43 , V_44 , V_308 -> V_614 ,
V_308 -> V_657 ) ;
F_159 ( V_14 ) ;
F_32 ( & V_14 -> V_105 , V_76 ) ;
V_37 = V_14 -> V_245 . V_244 ;
V_658:
if ( V_655 ++ == 5 ) {
F_46 ( V_14 , F_13 ( V_42 L_234 ,
V_14 -> V_43 , V_44 ) ) ;
goto V_89;
} else if ( V_655 > 1 )
F_46 ( V_14 , F_13 ( V_42 L_235 ,
V_14 -> V_43 , V_44 , V_655 - 1 ) ) ;
V_653 = 0 ;
V_654 = 0 ;
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
V_654 ++ ;
if ( V_14 -> V_82 )
goto V_89;
F_33 ( & V_14 -> V_105 , V_76 ) ;
V_2 = F_112 ( V_14 , V_35 , 0 , 0 , V_109 ,
V_292 , V_102 , 30 ) ;
if ( V_2 == V_263 ) {
F_75 ( V_223 , V_75 ,
L_236
L_237 , V_104 ) ;
F_32 ( & V_14 -> V_105 , V_76 ) ;
goto V_658;
}
V_38 = F_21 ( V_37 -> V_46 )
& V_47 ;
if ( V_38 != V_48 ) {
F_75 ( V_223 , V_75 ,
L_238 ,
V_38 , V_104 ) ;
F_32 ( & V_14 -> V_105 , V_76 ) ;
goto V_658;
}
if ( V_37 -> V_288 ==
V_240 ||
V_37 -> V_288 ==
V_242 ) {
F_32 ( & V_14 -> V_105 , V_76 ) ;
continue;
}
V_656 = 0 ;
V_659:
if ( V_656 ++ == 60 ) {
F_46 ( V_14 , F_13 ( V_42
L_239 , V_14 -> V_43 ,
V_44 ) ) ;
F_32 ( & V_14 -> V_105 , V_76 ) ;
goto V_658;
}
if ( V_14 -> V_82 )
goto V_660;
V_2 = F_112 ( V_14 , V_35 , V_75 -> V_88 , V_75 -> V_87 ,
V_75 -> V_109 , V_273 , V_102 ,
30 ) ;
if ( V_2 == V_263 ) {
F_75 ( V_223 , V_75 ,
L_240
L_241 , V_104 ) ;
goto V_659;
}
if ( V_656 > 1 )
F_75 ( V_223 , V_75 ,
L_242
L_243 ,
V_656 - 1 , V_104 ) ;
V_653 += F_78 ( V_37 -> V_286 ) ;
F_32 ( & V_14 -> V_105 , V_76 ) ;
}
if ( V_14 -> V_661 ) {
F_46 ( V_14 , F_13 ( V_42
L_244 ,
V_14 -> V_43 , V_44 ) ) ;
V_14 -> V_661 = 0 ;
goto V_658;
}
V_89:
F_33 ( & V_14 -> V_105 , V_76 ) ;
V_660:
F_46 ( V_14 , F_13 ( V_42
L_245 ,
V_14 -> V_43 , V_44 , V_654 , V_653 ) ) ;
V_14 -> V_662 = 0 ;
if ( ! V_14 -> V_82 )
F_157 ( V_14 ) ;
F_131 ( & V_14 -> V_245 . V_262 ) ;
}
static void
F_254 ( struct V_13 * V_14 ,
struct V_3 * V_7 )
{
T_43 * V_308 =
( T_43 * ) V_7 -> V_308 ;
if ( V_14 -> V_15 & V_633 ) {
F_13 ( V_42 L_246 , V_14 -> V_43 ,
( V_308 -> V_384 == V_663 ) ?
L_247 : L_248 ) ;
if ( V_308 -> V_664 )
F_13 ( L_249 ,
F_78 ( V_308 -> V_664 ) ) ;
F_13 ( L_227 ) ;
}
if ( V_308 -> V_384 == V_663 &&
! V_14 -> V_39 . V_40 ) {
if ( V_665 > 0 && V_14 -> V_82 ) {
while ( V_14 -> V_82 )
F_255 ( 1 ) ;
}
F_230 ( V_14 ) ;
}
}
static int
F_256 ( struct V_13 * V_14 , T_4 V_35 , T_6 V_666 )
{
T_44 * V_258 ;
T_45 * V_37 ;
T_4 V_102 ;
T_6 V_667 = 0 ;
int V_28 = 0 ;
T_4 V_38 ;
T_10 V_478 ;
if ( V_14 -> V_159 == V_160 )
return V_28 ;
F_130 ( & V_14 -> V_591 . V_262 ) ;
if ( V_14 -> V_591 . V_246 != V_247 ) {
F_25 ( V_42 L_250 ,
V_14 -> V_43 , V_44 ) ;
V_28 = - V_668 ;
goto V_89;
}
V_14 -> V_591 . V_246 = V_251 ;
V_102 = F_167 ( V_14 , V_14 -> V_669 ) ;
if ( ! V_102 ) {
F_25 ( V_42 L_52 ,
V_14 -> V_43 , V_44 ) ;
V_14 -> V_591 . V_246 = V_247 ;
V_28 = - V_668 ;
goto V_89;
}
V_258 = F_120 ( V_14 , V_102 ) ;
V_14 -> V_591 . V_102 = V_102 ;
memset ( V_258 , 0 , sizeof( T_44 ) ) ;
V_258 -> V_274 = V_670 ;
V_258 -> V_515 = V_671 ;
V_258 -> V_199 = V_666 ;
F_46 ( V_14 , F_13 ( V_42 L_251\
L_252 , V_14 -> V_43 ,
V_35 , V_666 ) ) ;
F_123 ( & V_14 -> V_591 . V_252 ) ;
F_169 ( V_14 , V_102 ) ;
F_125 ( & V_14 -> V_591 . V_252 , 10 * V_282 ) ;
if ( ! ( V_14 -> V_591 . V_246 & V_248 ) ) {
F_25 ( V_42 L_54 ,
V_14 -> V_43 , V_44 ) ;
if ( ! ( V_14 -> V_591 . V_246 & V_283 ) )
V_667 = 1 ;
V_28 = - V_672 ;
goto V_89;
}
if ( V_14 -> V_591 . V_246 & V_250 ) {
V_37 = V_14 -> V_591 . V_244 ;
V_38 = F_21 ( V_37 -> V_46 ) ;
if ( V_38 & V_540 )
V_478 = F_78 ( V_37 -> V_285 ) ;
else
V_478 = 0 ;
V_38 &= V_47 ;
if ( V_38 != V_48 ) {
F_46 ( V_14 , F_13 ( V_42
L_253
L_254 , V_14 -> V_43 , V_38 ,
V_478 ) ) ;
V_28 = - V_672 ;
} else
F_46 ( V_14 , F_13 ( V_42
L_255 ,
V_14 -> V_43 ) ) ;
}
V_89:
V_14 -> V_591 . V_246 = V_247 ;
F_131 ( & V_14 -> V_591 . V_262 ) ;
if ( V_667 )
F_116 ( V_14 , V_267 ) ;
return V_28 ;
}
static void
F_257 ( struct V_110 * V_75 , void * V_143 )
{
V_75 -> V_143 = V_143 ? 1 : 0 ;
F_75 ( V_144 , V_75 , L_256 ,
V_75 -> V_143 ? L_257 : L_258 ) ;
F_258 ( F_259 ( V_75 ) ) ;
}
static void
F_260 ( struct V_13 * V_14 ,
T_24 * V_380 )
{
struct V_55 * V_56 ;
unsigned long V_76 ;
T_1 V_60 ;
T_4 V_35 = F_21 ( V_380 -> V_387 ) ;
int V_28 ;
F_101 ( V_14 , V_35 , & V_60 ) ;
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
V_56 -> V_87 = V_14 -> V_673 ++ ;
V_56 -> V_88 = V_133 ;
V_56 -> V_35 = V_35 ;
V_56 -> V_60 = V_60 ;
F_54 ( V_14 , V_56 ) ;
if ( ! V_14 -> V_623 ) {
V_28 = F_261 ( V_14 -> V_113 , V_133 ,
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
F_262 ( struct V_13 * V_14 , T_4 V_35 )
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
V_118 -> V_336 = 1 ;
}
F_13 ( V_42 L_259 ,
V_14 -> V_43 , V_56 -> V_35 ,
( unsigned long long ) V_56 -> V_60 ) ;
F_56 ( & V_56 -> V_81 ) ;
F_2 ( V_56 ) ;
}
F_33 ( & V_14 -> V_90 , V_76 ) ;
if ( V_85 )
F_263 ( & V_85 -> V_127 ) ;
}
static void
F_264 ( struct V_13 * V_14 ,
T_24 * V_380 )
{
struct V_53 * V_54 ;
struct V_126 * V_85 = NULL ;
struct V_72 * V_118 ;
unsigned long V_76 ;
T_4 V_35 = F_21 ( V_380 -> V_389 ) ;
F_32 ( & V_14 -> V_74 , V_76 ) ;
V_54 = F_36 ( V_14 , V_35 ) ;
if ( V_54 ) {
V_54 -> V_208 = 0 ;
V_54 -> V_209 = 0 ;
F_185 ( V_35 , V_14 -> V_137 ) ;
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
F_265 ( V_85 , NULL , F_257 ) ;
F_41 ( V_54 ) ;
}
static void
F_266 ( struct V_13 * V_14 ,
T_24 * V_380 )
{
struct V_53 * V_54 ;
struct V_126 * V_85 = NULL ;
struct V_72 * V_118 ;
unsigned long V_76 ;
T_4 V_35 = F_21 ( V_380 -> V_389 ) ;
T_4 V_208 = 0 ;
T_1 V_209 = 0 ;
F_100 ( V_14 , V_35 , & V_208 ) ;
if ( V_208 )
F_101 ( V_14 , V_208 ,
& V_209 ) ;
F_32 ( & V_14 -> V_74 , V_76 ) ;
V_54 = F_36 ( V_14 , V_35 ) ;
if ( V_54 ) {
F_162 ( V_35 , V_14 -> V_137 ) ;
if ( V_54 -> V_85 && V_54 -> V_85 -> V_120 ) {
V_85 = V_54 -> V_85 ;
V_118 = V_85 -> V_120 ;
V_118 -> V_76 |=
V_138 ;
V_54 -> V_208 = V_208 ;
V_54 -> V_209 = V_209 ;
}
}
F_33 ( & V_14 -> V_74 , V_76 ) ;
if ( ! V_54 )
return;
F_256 ( V_14 , V_35 , V_380 -> V_199 ) ;
if ( V_85 )
F_265 ( V_85 , ( void * ) 1 , F_257 ) ;
F_41 ( V_54 ) ;
}
static void
F_267 ( struct V_13 * V_14 ,
T_24 * V_380 )
{
T_4 V_35 = F_21 ( V_380 -> V_389 ) ;
F_42 ( V_14 , V_35 ) ;
}
static void
F_268 ( struct V_13 * V_14 ,
T_24 * V_380 )
{
struct V_53 * V_54 ;
T_4 V_35 = F_21 ( V_380 -> V_389 ) ;
T_9 V_37 ;
T_8 V_36 ;
T_10 V_38 ;
T_1 V_17 ;
T_4 V_585 ;
F_162 ( V_35 , V_14 -> V_137 ) ;
V_54 = F_37 ( V_14 , V_35 ) ;
if ( V_54 ) {
F_256 ( V_14 , V_35 , V_380 -> V_199 ) ;
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
V_585 = F_21 ( V_36 . V_587 ) ;
if ( ! F_23 ( V_14 , V_585 , & V_17 ) )
F_229 ( V_14 , V_17 , V_35 ,
V_36 . V_614 , V_567 ) ;
F_256 ( V_14 , V_35 , V_380 -> V_199 ) ;
F_246 ( V_14 , V_35 , 0 , 1 ) ;
}
static void
F_269 ( struct V_13 * V_14 ,
T_23 * V_308 )
{
T_24 * V_380 ;
T_6 V_674 ;
int V_106 ;
char * V_635 = NULL , * V_675 = NULL ;
V_380 = ( T_24 * ) & V_308 -> V_381 [ 0 ] ;
F_13 ( V_42 L_260 ,
V_14 -> V_43 , ( F_78 ( V_308 -> V_145 ) &
V_383 ) ?
L_261 : L_262 , V_308 -> V_382 ) ;
for ( V_106 = 0 ; V_106 < V_308 -> V_382 ; V_106 ++ , V_380 ++ ) {
switch ( V_380 -> V_384 ) {
case V_676 :
V_635 = L_194 ;
break;
case V_386 :
V_635 = L_195 ;
break;
case V_677 :
V_635 = L_263 ;
break;
case V_678 :
V_635 = L_264 ;
break;
case V_388 :
V_635 = L_265 ;
break;
case V_679 :
V_635 = L_266 ;
break;
case V_385 :
V_635 = L_267 ;
break;
case V_680 :
V_635 = L_268 ;
break;
case V_681 :
V_635 = L_269 ;
break;
default:
V_635 = L_223 ;
break;
}
V_674 = F_21 ( V_380 -> V_682 ) &
V_683 ;
switch ( V_674 ) {
case V_684 :
V_675 = L_58 ;
break;
case V_685 :
V_675 = L_270 ;
break;
case V_686 :
V_675 = L_271 ;
break;
default:
V_675 = L_272 ;
break;
}
F_13 ( L_273 \
L_274 , V_675 ,
V_635 , F_21 ( V_380 -> V_387 ) ,
F_21 ( V_380 -> V_389 ) ,
V_380 -> V_199 ) ;
}
}
static void
F_270 ( struct V_13 * V_14 ,
struct V_3 * V_7 )
{
T_24 * V_380 ;
int V_106 ;
T_6 V_687 ;
T_23 * V_308 =
( T_23 * )
V_7 -> V_308 ;
if ( ( V_14 -> V_15 & V_633 ) &&
( ! V_14 -> V_218 ) )
F_269 ( V_14 , V_308 ) ;
V_687 = ( F_78 ( V_308 -> V_145 ) &
V_383 ) ? 1 : 0 ;
V_380 = ( T_24 * ) & V_308 -> V_381 [ 0 ] ;
if ( V_14 -> V_82 &&
V_14 -> V_159 != V_160 ) {
for ( V_106 = 0 ; V_106 < V_308 -> V_382 ; V_106 ++ , V_380 ++ ) {
if ( V_380 -> V_384 == V_678 )
F_256 ( V_14 ,
F_21 ( V_380 -> V_389 ) ,
V_380 -> V_199 ) ;
}
return;
}
for ( V_106 = 0 ; V_106 < V_308 -> V_382 ; V_106 ++ , V_380 ++ ) {
switch ( V_380 -> V_384 ) {
case V_679 :
case V_676 :
if ( ! V_687 )
F_260 ( V_14 , V_380 ) ;
break;
case V_385 :
case V_386 :
if ( ! V_687 )
F_262 ( V_14 ,
F_21 ( V_380 -> V_387 ) ) ;
break;
case V_680 :
if ( ! V_14 -> V_134 )
F_266 ( V_14 , V_380 ) ;
break;
case V_681 :
if ( ! V_14 -> V_134 )
F_264 ( V_14 , V_380 ) ;
break;
case V_678 :
if ( ! V_14 -> V_134 )
F_268 ( V_14 , V_380 ) ;
break;
case V_388 :
if ( ! V_14 -> V_134 )
F_267 ( V_14 , V_380 ) ;
break;
}
}
}
static void
F_271 ( struct V_13 * V_14 ,
struct V_3 * V_7 )
{
T_1 V_60 ;
unsigned long V_76 ;
struct V_55 * V_56 ;
T_4 V_35 ;
T_10 V_167 ;
int V_28 ;
T_25 * V_308 =
( T_25 * ) V_7 -> V_308 ;
if ( V_14 -> V_82 )
return;
if ( V_308 -> V_384 != V_390 )
return;
V_35 = F_21 ( V_308 -> V_387 ) ;
V_167 = F_78 ( V_308 -> V_391 ) ;
if ( ! V_14 -> V_218 )
F_46 ( V_14 , F_13 ( V_42
L_275 ,
V_14 -> V_43 , V_44 , V_35 ,
F_78 ( V_308 -> V_688 ) , V_167 ) ) ;
switch ( V_167 ) {
case V_177 :
case V_176 :
F_262 ( V_14 , V_35 ) ;
break;
case V_172 :
case V_174 :
case V_171 :
F_32 ( & V_14 -> V_90 , V_76 ) ;
V_56 = F_52 ( V_14 , V_35 ) ;
F_33 ( & V_14 -> V_90 , V_76 ) ;
if ( V_56 )
break;
F_101 ( V_14 , V_35 , & V_60 ) ;
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
V_56 -> V_87 = V_14 -> V_673 ++ ;
V_56 -> V_88 = V_133 ;
V_56 -> V_35 = V_35 ;
V_56 -> V_60 = V_60 ;
F_54 ( V_14 , V_56 ) ;
V_28 = F_261 ( V_14 -> V_113 , V_133 ,
V_56 -> V_87 , 0 ) ;
if ( V_28 )
F_55 ( V_14 , V_56 ) ;
break;
case V_689 :
default:
break;
}
}
static void
F_272 ( struct V_13 * V_14 ,
struct V_3 * V_7 )
{
T_4 V_35 , V_585 ;
T_10 V_167 ;
struct V_53 * V_54 ;
T_9 V_37 ;
T_8 V_36 ;
T_10 V_38 ;
T_46 * V_308 =
( T_46 * ) V_7 -> V_308 ;
T_1 V_17 ;
if ( V_14 -> V_82 )
return;
if ( V_308 -> V_384 != V_690 )
return;
V_35 = F_21 ( V_308 -> V_389 ) ;
V_167 = F_78 ( V_308 -> V_391 ) ;
if ( ! V_14 -> V_218 )
F_46 ( V_14 , F_13 ( V_42
L_275 ,
V_14 -> V_43 , V_44 , V_35 ,
F_78 ( V_308 -> V_688 ) , V_167 ) ) ;
switch ( V_167 ) {
case V_691 :
case V_692 :
case V_693 :
case V_694 :
case V_695 :
if ( ! V_14 -> V_134 )
F_162 ( V_35 , V_14 -> V_137 ) ;
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
V_585 = F_21 ( V_36 . V_587 ) ;
if ( ! F_23 ( V_14 , V_585 , & V_17 ) )
F_229 ( V_14 , V_17 , V_35 ,
V_36 . V_614 , V_567 ) ;
F_246 ( V_14 , V_35 , 0 , 1 ) ;
break;
case V_696 :
case V_697 :
case V_698 :
default:
break;
}
}
static void
F_273 ( struct V_13 * V_14 ,
T_47 * V_308 )
{
char * V_635 = NULL ;
switch ( V_308 -> V_699 ) {
case V_700 :
V_635 = L_276 ;
break;
case V_701 :
V_635 = L_277 ;
break;
case V_702 :
V_635 = L_278 ;
break;
case V_703 :
V_635 = L_279 ;
break;
case V_704 :
V_635 = L_280 ;
break;
}
if ( ! V_635 )
return;
F_13 ( V_42 L_281 \
L_282 ,
V_14 -> V_43 , V_635 ,
F_21 ( V_308 -> V_387 ) ,
V_308 -> V_705 ) ;
}
static void
F_274 ( struct V_13 * V_14 ,
struct V_3 * V_7 )
{
T_47 * V_308 =
( T_47 * )
V_7 -> V_308 ;
static struct V_55 * V_56 ;
unsigned long V_76 ;
T_4 V_35 ;
if ( ( V_14 -> V_15 & V_633 ) &&
( ! V_14 -> V_218 ) )
F_273 ( V_14 ,
V_308 ) ;
if ( V_308 -> V_699 == V_700 ) {
F_32 ( & V_14 -> V_90 , V_76 ) ;
V_35 = F_21 ( V_308 -> V_387 ) ;
V_56 = F_52 ( V_14 , V_35 ) ;
if ( V_56 )
V_56 -> V_155 =
V_308 -> V_705 ;
F_33 ( & V_14 -> V_90 , V_76 ) ;
}
}
static void
F_275 ( struct V_13 * V_14 )
{
struct V_116 * V_117 ;
struct V_110 * V_75 ;
F_110 (sdev, ioc->shost) {
V_117 = V_75 -> V_120 ;
if ( V_117 && V_117 -> V_122 )
V_117 -> V_122 -> V_336 = 1 ;
}
}
static void
F_276 ( struct V_13 * V_14 ,
T_8 * V_36 )
{
struct V_72 * V_118 = NULL ;
struct V_126 * V_85 ;
struct V_53 * V_54 ;
unsigned long V_76 ;
F_32 ( & V_14 -> V_74 , V_76 ) ;
F_15 (sas_device, &ioc->sas_device_list, list) {
if ( ( V_54 -> V_17 == V_36 -> V_19 ) &&
( V_54 -> V_26 == V_36 -> V_521 ) ) {
V_54 -> V_706 = 1 ;
V_85 = V_54 -> V_85 ;
if ( V_85 && V_85 -> V_120 ) {
V_118 = V_85 -> V_120 ;
V_118 -> V_254 = 0 ;
V_118 -> V_336 = 0 ;
} else
V_118 = NULL ;
if ( V_85 ) {
F_134 ( V_144 , V_85 ,
L_283 ,
V_36 -> V_200 ,
( unsigned long long )
V_54 -> V_17 ) ;
if ( V_54 -> V_78 != 0 )
F_134 ( V_144 , V_85 ,
L_284
L_95 ,
( unsigned long long )
V_54 -> V_22 ,
V_54 -> V_26 ) ;
}
if ( V_36 -> V_145 &
V_615 ) {
V_54 -> V_80 =
F_21 ( V_36 -> V_616 ) ;
memcpy ( & V_54 -> V_79 [ 0 ] ,
& V_36 -> V_617 [ 0 ] , 4 ) ;
} else {
V_54 -> V_80 = 0 ;
V_54 -> V_79 [ 0 ] = '\0' ;
}
if ( V_54 -> V_35 == V_36 -> V_200 )
goto V_89;
F_13 ( L_285 ,
V_54 -> V_35 ) ;
V_54 -> V_35 = V_36 -> V_200 ;
if ( V_118 )
V_118 -> V_35 =
V_36 -> V_200 ;
goto V_89;
}
}
V_89:
F_33 ( & V_14 -> V_74 , V_76 ) ;
}
static void
F_277 ( struct V_13 * V_14 )
{
T_8 V_36 ;
T_9 V_37 ;
T_4 V_38 ;
T_4 V_35 ;
T_10 V_96 ;
F_13 ( V_42 L_286 , V_14 -> V_43 ) ;
if ( F_39 ( & V_14 -> V_83 ) )
goto V_89;
V_35 = 0xFFFF ;
while ( ! ( F_24 ( V_14 , & V_37 ,
& V_36 , V_707 ,
V_35 ) ) ) {
V_38 = F_21 ( V_37 . V_46 ) &
V_47 ;
if ( V_38 != V_48 )
break;
V_35 = V_36 . V_200 =
F_21 ( V_36 . V_200 ) ;
V_96 = F_78 ( V_36 . V_146 ) ;
if ( ! ( F_60 ( V_96 ) ) )
continue;
V_36 . V_19 =
F_18 ( V_36 . V_19 ) ;
V_36 . V_521 = F_21 ( V_36 . V_521 ) ;
F_276 ( V_14 , & V_36 ) ;
}
V_89:
F_13 ( V_42 L_287 ,
V_14 -> V_43 ) ;
}
static void
F_278 ( struct V_13 * V_14 , T_1 V_60 ,
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
V_118 -> V_336 = 0 ;
} else
V_118 = NULL ;
V_56 -> V_706 = 1 ;
F_33 ( & V_14 -> V_90 , V_76 ) ;
F_134 ( V_144 , V_56 -> V_85 ,
L_288 , V_35 ,
( unsigned long long ) V_56 -> V_60 ) ;
F_98 ( V_14 , V_56 ) ;
F_32 ( & V_14 -> V_90 , V_76 ) ;
if ( V_56 -> V_35 == V_35 ) {
F_33 ( & V_14 -> V_90 ,
V_76 ) ;
return;
}
F_13 ( L_285 ,
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
F_279 ( struct V_13 * V_14 )
{
T_48 V_708 ;
T_11 V_709 ;
T_12 V_192 ;
T_9 V_37 ;
T_4 V_38 ;
T_4 V_35 ;
T_6 V_666 ;
if ( ! V_14 -> V_710 )
return;
F_13 ( V_42 L_289 ,
V_14 -> V_43 ) ;
if ( F_39 ( & V_14 -> V_91 ) )
goto V_89;
V_35 = 0xFFFF ;
while ( ! ( F_280 ( V_14 , & V_37 ,
& V_708 , V_711 , V_35 ) ) ) {
V_38 = F_21 ( V_37 . V_46 ) &
V_47 ;
if ( V_38 != V_48 )
break;
V_35 = F_21 ( V_708 . V_200 ) ;
if ( F_82 ( V_14 , & V_37 ,
& V_709 , V_156 , V_35 ,
sizeof( T_11 ) ) )
continue;
if ( V_709 . V_170 == V_171 ||
V_709 . V_170 == V_172 ||
V_709 . V_170 == V_174 )
F_278 ( V_14 ,
F_18 ( V_708 . V_712 ) , V_35 ) ;
}
if ( ! V_14 -> V_134 ) {
V_666 = 0xFF ;
memset ( V_14 -> V_137 , 0 , V_14 -> V_713 ) ;
while ( ! ( F_93 ( V_14 , & V_37 ,
& V_192 , V_714 ,
V_666 ) ) ) {
V_38 = F_21 ( V_37 . V_46 ) &
V_47 ;
if ( V_38 != V_48 )
break;
V_666 = V_192 . V_199 ;
V_35 = F_21 ( V_192 . V_200 ) ;
F_162 ( V_35 , V_14 -> V_137 ) ;
}
}
V_89:
F_13 ( V_42 L_290 ,
V_14 -> V_43 ) ;
}
static void
F_281 ( struct V_13 * V_14 , T_1 V_17 ,
T_4 V_35 )
{
struct V_92 * V_93 ;
unsigned long V_76 ;
int V_106 ;
F_32 ( & V_14 -> V_94 , V_76 ) ;
F_15 (sas_expander, &ioc->sas_expander_list, list) {
if ( V_93 -> V_17 != V_17 )
continue;
V_93 -> V_706 = 1 ;
if ( V_93 -> V_35 == V_35 )
goto V_89;
F_13 ( L_291 \
L_292 ,
( unsigned long long ) V_93 -> V_17 ,
V_93 -> V_35 , V_35 ) ;
V_93 -> V_35 = V_35 ;
for ( V_106 = 0 ; V_106 < V_93 -> V_40 ; V_106 ++ )
V_93 -> V_225 [ V_106 ] . V_35 = V_35 ;
goto V_89;
}
V_89:
F_33 ( & V_14 -> V_94 , V_76 ) ;
}
static void
F_282 ( struct V_13 * V_14 )
{
T_39 V_583 ;
T_9 V_37 ;
T_4 V_38 ;
T_1 V_17 ;
T_4 V_35 ;
F_13 ( V_42 L_293 , V_14 -> V_43 ) ;
if ( F_39 ( & V_14 -> V_95 ) )
goto V_89;
V_35 = 0xFFFF ;
while ( ! ( F_238 ( V_14 , & V_37 , & V_583 ,
V_715 , V_35 ) ) ) {
V_38 = F_21 ( V_37 . V_46 ) &
V_47 ;
if ( V_38 != V_48 )
break;
V_35 = F_21 ( V_583 . V_200 ) ;
V_17 = F_18 ( V_583 . V_19 ) ;
F_13 ( L_294 ,
V_35 ,
( unsigned long long ) V_17 ) ;
F_281 ( V_14 , V_17 , V_35 ) ;
}
V_89:
F_13 ( V_42 L_295 , V_14 -> V_43 ) ;
}
static void
F_283 ( struct V_13 * V_14 )
{
struct V_53 * V_54 , * V_716 ;
struct V_92 * V_93 , * V_717 ;
struct V_55 * V_56 , * V_718 ;
struct V_719 V_720 ;
unsigned long V_76 ;
F_284 ( V_721 ) ;
F_13 ( V_42 L_296 ,
V_14 -> V_43 ) ;
F_13 ( V_42 L_297 ,
V_14 -> V_43 ) ;
F_32 ( & V_14 -> V_74 , V_76 ) ;
F_285 (sas_device, sas_device_next,
&ioc->sas_device_list, list) {
if ( ! V_54 -> V_706 )
F_286 ( & V_54 -> V_81 , & V_721 ) ;
else
V_54 -> V_706 = 0 ;
}
F_33 ( & V_14 -> V_74 , V_76 ) ;
F_285 (sas_device, sas_device_next, &head, list) {
F_43 ( V_14 , V_54 ) ;
F_40 ( & V_54 -> V_81 ) ;
F_41 ( V_54 ) ;
}
if ( V_14 -> V_710 ) {
F_13 ( V_42 L_298 ,
V_14 -> V_43 ) ;
F_285 (raid_device, raid_device_next,
&ioc->raid_device_list, list) {
if ( ! V_56 -> V_706 )
F_262 ( V_14 ,
V_56 -> V_35 ) ;
else
V_56 -> V_706 = 0 ;
}
}
F_13 ( V_42 L_299 ,
V_14 -> V_43 ) ;
F_32 ( & V_14 -> V_94 , V_76 ) ;
F_141 ( & V_720 ) ;
F_285 (sas_expander, sas_expander_next,
&ioc->sas_expander_list, list) {
if ( ! V_93 -> V_706 )
F_286 ( & V_93 -> V_81 , & V_720 ) ;
else
V_93 -> V_706 = 0 ;
}
F_33 ( & V_14 -> V_94 , V_76 ) ;
F_285 (sas_expander, sas_expander_next, &tmp_list,
list) {
F_56 ( & V_93 -> V_81 ) ;
F_242 ( V_14 , V_93 ) ;
}
F_13 ( V_42 L_300 ,
V_14 -> V_43 ) ;
F_157 ( V_14 ) ;
}
static void
F_287 ( struct V_13 * V_14 ,
struct V_92 * V_93 , T_4 V_35 )
{
T_40 V_584 ;
T_9 V_37 ;
int V_106 ;
for ( V_106 = 0 ; V_106 < V_93 -> V_40 ; V_106 ++ ) {
if ( ( F_239 ( V_14 , & V_37 ,
& V_584 , V_106 , V_35 ) ) ) {
F_25 ( V_42 L_2 ,
V_14 -> V_43 , __FILE__ , __LINE__ , V_44 ) ;
return;
}
F_229 ( V_14 , V_93 -> V_17 ,
F_21 ( V_584 . V_329 ) , V_106 ,
V_584 . V_565 >> 4 ) ;
}
}
static void
F_288 ( struct V_13 * V_14 )
{
T_39 V_583 ;
T_8 V_36 ;
T_48 V_708 ;
T_11 V_709 ;
T_12 V_192 ;
T_24 V_380 ;
T_9 V_37 ;
T_6 V_666 ;
T_4 V_38 ;
T_4 V_35 , V_585 ;
T_1 V_17 ;
struct V_53 * V_54 ;
struct V_92 * V_722 ;
static struct V_55 * V_56 ;
T_6 V_723 ;
unsigned long V_76 ;
F_13 ( V_42 L_301 , V_14 -> V_43 ) ;
F_227 ( V_14 ) ;
F_13 ( V_42 L_302 , V_14 -> V_43 ) ;
V_35 = 0xFFFF ;
while ( ! ( F_238 ( V_14 , & V_37 , & V_583 ,
V_715 , V_35 ) ) ) {
V_38 = F_21 ( V_37 . V_46 ) &
V_47 ;
if ( V_38 != V_48 ) {
F_13 ( V_42 L_303 \
L_304 ,
V_14 -> V_43 , V_38 ,
F_78 ( V_37 . V_285 ) ) ;
break;
}
V_35 = F_21 ( V_583 . V_200 ) ;
F_32 ( & V_14 -> V_94 , V_76 ) ;
V_722 = F_58 (
V_14 , F_18 ( V_583 . V_19 ) ) ;
F_33 ( & V_14 -> V_94 , V_76 ) ;
if ( V_722 )
F_287 ( V_14 , V_722 ,
V_35 ) ;
else {
F_13 ( V_42 L_305 \
L_306 , V_14 -> V_43 ,
V_35 , ( unsigned long long )
F_18 ( V_583 . V_19 ) ) ;
F_237 ( V_14 , V_35 ) ;
F_13 ( V_42 L_307 \
L_306 , V_14 -> V_43 ,
V_35 , ( unsigned long long )
F_18 ( V_583 . V_19 ) ) ;
}
}
F_13 ( V_42 L_308 ,
V_14 -> V_43 ) ;
if ( ! V_14 -> V_710 )
goto V_724;
F_13 ( V_42 L_309 , V_14 -> V_43 ) ;
V_666 = 0xFF ;
while ( ! ( F_93 ( V_14 , & V_37 ,
& V_192 , V_714 ,
V_666 ) ) ) {
V_38 = F_21 ( V_37 . V_46 ) &
V_47 ;
if ( V_38 != V_48 ) {
F_13 ( V_42 L_310\
L_304 ,
V_14 -> V_43 , V_38 ,
F_78 ( V_37 . V_285 ) ) ;
break;
}
V_666 = V_192 . V_199 ;
V_35 = F_21 ( V_192 . V_200 ) ;
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
F_13 ( V_42 L_311 \
L_304 ,
V_14 -> V_43 , V_38 ,
F_78 ( V_37 . V_285 ) ) ;
break;
}
V_585 = F_21 ( V_36 . V_587 ) ;
if ( ! F_23 ( V_14 , V_585 ,
& V_17 ) ) {
F_13 ( V_42 L_312 \
L_313 ,
V_14 -> V_43 , V_35 , ( unsigned long long )
F_18 ( V_36 . V_19 ) ) ;
F_229 ( V_14 , V_17 ,
V_35 , V_36 . V_614 ,
V_567 ) ;
F_162 ( V_35 , V_14 -> V_137 ) ;
V_723 = 0 ;
while ( F_246 ( V_14 , V_35 , V_723 ++ ,
1 ) ) {
F_255 ( 1 ) ;
}
F_13 ( V_42 L_314 \
L_313 ,
V_14 -> V_43 , V_35 , ( unsigned long long )
F_18 ( V_36 . V_19 ) ) ;
}
}
F_13 ( V_42 L_315 ,
V_14 -> V_43 ) ;
F_13 ( V_42 L_316 , V_14 -> V_43 ) ;
V_35 = 0xFFFF ;
while ( ! ( F_280 ( V_14 , & V_37 ,
& V_708 , V_711 , V_35 ) ) ) {
V_38 = F_21 ( V_37 . V_46 ) &
V_47 ;
if ( V_38 != V_48 ) {
F_13 ( V_42 L_317 \
L_304 ,
V_14 -> V_43 , V_38 ,
F_78 ( V_37 . V_285 ) ) ;
break;
}
V_35 = F_21 ( V_708 . V_200 ) ;
F_32 ( & V_14 -> V_90 , V_76 ) ;
V_56 = F_53 ( V_14 ,
F_18 ( V_708 . V_712 ) ) ;
F_33 ( & V_14 -> V_90 , V_76 ) ;
if ( V_56 )
continue;
if ( F_82 ( V_14 , & V_37 ,
& V_709 , V_156 , V_35 ,
sizeof( T_11 ) ) )
continue;
V_38 = F_21 ( V_37 . V_46 ) &
V_47 ;
if ( V_38 != V_48 ) {
F_13 ( V_42 L_317 \
L_304 ,
V_14 -> V_43 , V_38 ,
F_78 ( V_37 . V_285 ) ) ;
break;
}
if ( V_709 . V_170 == V_171 ||
V_709 . V_170 == V_172 ||
V_709 . V_170 == V_174 ) {
memset ( & V_380 , 0 , sizeof( T_24 ) ) ;
V_380 . V_384 = V_676 ;
V_380 . V_387 = V_708 . V_200 ;
F_13 ( V_42
L_318 ,
V_14 -> V_43 , V_708 . V_200 ) ;
F_260 ( V_14 , & V_380 ) ;
F_13 ( V_42
L_319 ,
V_14 -> V_43 , V_708 . V_200 ) ;
}
}
F_13 ( V_42 L_320 ,
V_14 -> V_43 ) ;
V_724:
F_13 ( V_42 L_321 ,
V_14 -> V_43 ) ;
V_35 = 0xFFFF ;
while ( ! ( F_24 ( V_14 , & V_37 ,
& V_36 , V_707 ,
V_35 ) ) ) {
V_38 = F_21 ( V_37 . V_46 ) &
V_47 ;
if ( V_38 != V_48 ) {
F_13 ( V_42 L_322\
L_323 ,
V_14 -> V_43 , V_38 ,
F_78 ( V_37 . V_285 ) ) ;
break;
}
V_35 = F_21 ( V_36 . V_200 ) ;
if ( ! ( F_60 (
F_78 ( V_36 . V_146 ) ) ) )
continue;
V_54 = F_35 ( V_14 ,
F_18 ( V_36 . V_19 ) ) ;
if ( V_54 ) {
F_41 ( V_54 ) ;
continue;
}
V_585 = F_21 ( V_36 . V_587 ) ;
if ( ! F_23 ( V_14 , V_585 , & V_17 ) ) {
F_13 ( V_42 L_324 \
L_306 , V_14 -> V_43 ,
V_35 , ( unsigned long long )
F_18 ( V_36 . V_19 ) ) ;
F_229 ( V_14 , V_17 , V_35 ,
V_36 . V_614 , V_567 ) ;
V_723 = 0 ;
while ( F_246 ( V_14 , V_35 , V_723 ++ ,
0 ) ) {
F_255 ( 1 ) ;
}
F_13 ( V_42 L_325 \
L_306 , V_14 -> V_43 ,
V_35 , ( unsigned long long )
F_18 ( V_36 . V_19 ) ) ;
}
}
F_13 ( V_42 L_326 ,
V_14 -> V_43 ) ;
F_13 ( V_42 L_327 , V_14 -> V_43 ) ;
}
void
F_289 ( struct V_13 * V_14 , int V_725 )
{
switch ( V_725 ) {
case V_726 :
F_119 ( V_14 , F_13 ( V_42
L_328 , V_14 -> V_43 , V_44 ) ) ;
break;
case V_727 :
F_119 ( V_14 , F_13 ( V_42
L_329 , V_14 -> V_43 , V_44 ) ) ;
if ( V_14 -> V_591 . V_246 & V_251 ) {
V_14 -> V_591 . V_246 |= V_283 ;
F_178 ( V_14 , V_14 -> V_591 . V_102 ) ;
F_108 ( & V_14 -> V_591 . V_252 ) ;
}
if ( V_14 -> V_245 . V_246 & V_251 ) {
V_14 -> V_245 . V_246 |= V_283 ;
F_178 ( V_14 , V_14 -> V_245 . V_102 ) ;
F_108 ( & V_14 -> V_245 . V_252 ) ;
}
F_150 ( V_14 ) ;
F_190 ( V_14 ) ;
break;
case V_728 :
F_119 ( V_14 , F_13 ( V_42
L_330 , V_14 -> V_43 , V_44 ) ) ;
if ( ( ! V_14 -> V_57 ) && ! ( V_665 > 0 &&
! V_14 -> V_39 . V_40 ) ) {
F_275 ( V_14 ) ;
F_277 ( V_14 ) ;
F_279 ( V_14 ) ;
F_282 ( V_14 ) ;
F_146 ( V_14 ) ;
}
break;
}
}
static void
F_290 ( struct V_13 * V_14 , struct V_3 * V_7 )
{
F_144 ( V_14 , V_7 ) ;
if ( V_14 -> V_264 || V_14 -> V_265 ) {
F_6 ( V_7 ) ;
return;
}
switch ( V_7 -> V_309 ) {
case V_310 :
F_291 ( V_14 ,
(struct V_307 * )
V_7 -> V_308 ) ;
break;
case V_311 :
while ( F_292 ( V_14 -> V_113 ) ||
V_14 -> V_82 ) {
if ( V_14 -> V_264 )
goto V_89;
F_255 ( 1 ) ;
}
F_283 ( V_14 ) ;
F_288 ( V_14 ) ;
break;
case V_312 :
V_14 -> V_729 = 0 ;
if ( V_730 [ 0 ] != - 1 && V_730 [ 1 ] != - 1 )
F_293 ( V_14 , V_730 [ 0 ] ,
V_730 [ 1 ] ) ;
F_46 ( V_14 , F_13 ( V_42
L_331 ,
V_14 -> V_43 ) ) ;
break;
case V_524 :
F_210 ( V_14 , V_7 -> V_525 ) ;
break;
case V_375 :
F_248 ( V_14 , V_7 ) ;
break;
case V_533 :
F_250 ( V_14 , V_7 ) ;
break;
case V_731 :
F_254 ( V_14 , V_7 ) ;
break;
case V_732 :
F_253 ( V_14 , V_7 ) ;
break;
case V_733 :
F_252 ( V_14 ,
V_7 ) ;
break;
case V_734 :
F_270 ( V_14 , V_7 ) ;
break;
case V_735 :
F_271 ( V_14 , V_7 ) ;
break;
case V_736 :
F_272 ( V_14 , V_7 ) ;
break;
case V_737 :
F_274 ( V_14 , V_7 ) ;
break;
}
V_89:
F_6 ( V_7 ) ;
}
static void
V_306 ( struct V_738 * V_305 )
{
struct V_3 * V_7 = F_3 ( V_305 ,
struct V_3 , V_305 ) ;
F_290 ( V_7 -> V_14 , V_7 ) ;
}
T_6
F_294 ( struct V_13 * V_14 , T_6 V_243 ,
T_10 V_244 )
{
struct V_3 * V_7 ;
T_32 * V_37 ;
T_4 V_309 ;
T_4 V_193 ;
T_49 * V_739 ;
if ( V_14 -> V_264 || V_14 -> V_265 )
return 1 ;
V_37 = F_107 ( V_14 , V_244 ) ;
if ( F_166 ( ! V_37 ) ) {
F_25 ( V_42 L_103 ,
V_14 -> V_43 , __FILE__ , __LINE__ , V_44 ) ;
return 1 ;
}
V_309 = F_21 ( V_37 -> V_358 ) ;
if ( V_309 != V_740 )
F_295 ( V_14 , V_309 , 0 ) ;
switch ( V_309 ) {
case V_732 :
{
T_42 * V_741 =
( T_42 * )
V_37 -> V_531 ;
if ( V_741 -> V_742 !=
V_743 )
return 1 ;
if ( V_14 -> V_662 ) {
V_14 -> V_661 ++ ;
return 1 ;
} else
V_14 -> V_662 = 1 ;
break;
}
case V_375 :
F_179 ( V_14 ,
( T_19 * )
V_37 -> V_531 ) ;
break;
case V_734 :
F_184 ( V_14 ,
( T_23 * )
V_37 -> V_531 ) ;
break;
case V_735 :
F_187 ( V_14 ,
( T_25 * )
V_37 -> V_531 ) ;
break;
case V_740 :
{
T_50 * V_744 ;
T_10 * V_745 ;
if ( ! V_14 -> V_134 )
break;
V_744 = ( T_50 * )
V_37 -> V_531 ;
V_745 = ( T_10 * ) V_744 -> V_746 ;
if ( F_21 ( V_744 -> V_747 )
!= V_748 )
break;
switch ( F_78 ( * V_745 ) ) {
case V_749 :
F_91 ( V_42 L_332
L_333
L_334
L_335 , V_14 -> V_43 ) ;
break;
case V_750 :
F_91 ( V_42 L_332
L_336
L_337
L_338 , V_14 -> V_43 ) ;
break;
case V_751 :
F_25 ( V_42 L_339
L_340
L_341
L_342
L_338 , V_14 -> V_43 ) ;
break;
case V_752 :
F_25 ( V_42 L_339
L_343
L_344
L_345 ,
V_14 -> V_43 ) ;
break;
}
break;
}
case V_533 :
case V_737 :
case V_731 :
case V_733 :
case V_736 :
break;
case V_753 :
F_188 ( V_14 ,
( T_26 * )
V_37 -> V_531 ) ;
break;
case V_754 :
V_739 =
( T_49 * ) V_37 -> V_531 ;
if ( V_739 -> V_384 ==
V_755 ) {
F_13 ( V_42 L_346 ,
V_14 -> V_43 , V_739 -> V_756 ) ;
F_13 ( L_347 ) ;
F_13 ( L_348 ) ;
F_13 ( L_349 ,
V_739 -> V_757 ) ;
}
break;
default:
return 1 ;
}
V_193 = F_21 ( V_37 -> V_534 ) * 4 ;
V_7 = F_8 ( V_193 ) ;
if ( ! V_7 ) {
F_25 ( V_42 L_2 ,
V_14 -> V_43 , __FILE__ , __LINE__ , V_44 ) ;
return 1 ;
}
memcpy ( V_7 -> V_308 , V_37 -> V_531 , V_193 ) ;
V_7 -> V_14 = V_14 ;
V_7 -> V_360 = V_37 -> V_360 ;
V_7 -> V_361 = V_37 -> V_361 ;
V_7 -> V_309 = V_309 ;
F_140 ( V_14 , V_7 ) ;
F_6 ( V_7 ) ;
return 1 ;
}
static void
F_242 ( struct V_13 * V_14 ,
struct V_92 * V_93 )
{
struct V_317 * V_318 , * V_365 ;
F_285 (mpt3sas_port, next,
&sas_expander->sas_port_list, port_list) {
if ( V_14 -> V_82 )
return;
if ( V_318 -> V_320 . V_321 ==
V_322 )
F_44 ( V_14 ,
V_318 -> V_320 . V_17 ) ;
else if ( V_318 -> V_320 . V_321 ==
V_324 ||
V_318 -> V_320 . V_321 ==
V_325 )
F_241 ( V_14 ,
V_318 -> V_320 . V_17 ) ;
}
F_49 ( V_14 , V_93 -> V_17 ,
V_93 -> V_84 ) ;
F_13 ( V_42
L_350 ,
V_14 -> V_43 ,
V_93 -> V_35 , ( unsigned long long )
V_93 -> V_17 ) ;
F_2 ( V_93 -> V_225 ) ;
F_2 ( V_93 ) ;
}
static void
F_296 ( struct V_13 * V_14 )
{
T_44 * V_258 ;
T_45 * V_37 ;
T_4 V_102 ;
if ( ! V_14 -> V_710 )
return;
if ( F_39 ( & V_14 -> V_91 ) )
return;
F_130 ( & V_14 -> V_591 . V_262 ) ;
if ( V_14 -> V_591 . V_246 != V_247 ) {
F_25 ( V_42 L_250 ,
V_14 -> V_43 , V_44 ) ;
goto V_89;
}
V_14 -> V_591 . V_246 = V_251 ;
V_102 = F_167 ( V_14 , V_14 -> V_669 ) ;
if ( ! V_102 ) {
F_25 ( V_42 L_52 ,
V_14 -> V_43 , V_44 ) ;
V_14 -> V_591 . V_246 = V_247 ;
goto V_89;
}
V_258 = F_120 ( V_14 , V_102 ) ;
V_14 -> V_591 . V_102 = V_102 ;
memset ( V_258 , 0 , sizeof( T_44 ) ) ;
V_258 -> V_274 = V_670 ;
V_258 -> V_515 = V_758 ;
if ( ! V_14 -> V_218 )
F_13 ( V_42 L_351 , V_14 -> V_43 ) ;
F_123 ( & V_14 -> V_591 . V_252 ) ;
F_169 ( V_14 , V_102 ) ;
F_125 ( & V_14 -> V_591 . V_252 , 10 * V_282 ) ;
if ( ! ( V_14 -> V_591 . V_246 & V_248 ) ) {
F_25 ( V_42 L_54 ,
V_14 -> V_43 , V_44 ) ;
goto V_89;
}
if ( V_14 -> V_591 . V_246 & V_250 ) {
V_37 = V_14 -> V_591 . V_244 ;
if ( ! V_14 -> V_218 )
F_13 ( V_42 L_352
L_353 ,
V_14 -> V_43 , F_21 ( V_37 -> V_46 ) ,
F_78 ( V_37 -> V_285 ) ) ;
}
V_89:
V_14 -> V_591 . V_246 = V_247 ;
F_131 ( & V_14 -> V_591 . V_262 ) ;
}
static void F_297 ( struct V_759 * V_528 )
{
struct V_112 * V_113 = F_298 ( V_528 ) ;
struct V_13 * V_14 = F_67 ( V_113 ) ;
struct V_317 * V_318 , * V_760 ;
struct V_55 * V_56 , * V_365 ;
struct V_72 * V_118 ;
struct V_761 * V_762 ;
unsigned long V_76 ;
V_14 -> V_264 = 1 ;
F_150 ( V_14 ) ;
F_32 ( & V_14 -> V_303 , V_76 ) ;
V_762 = V_14 -> V_302 ;
V_14 -> V_302 = NULL ;
F_33 ( & V_14 -> V_303 , V_76 ) ;
if ( V_762 )
F_299 ( V_762 ) ;
F_296 ( V_14 ) ;
F_285 (raid_device, next, &ioc->raid_device_list,
list) {
if ( V_56 -> V_85 ) {
V_118 =
V_56 -> V_85 -> V_120 ;
V_118 -> V_336 = 1 ;
F_263 ( & V_56 -> V_85 -> V_127 ) ;
}
F_13 ( V_42 L_259 ,
V_14 -> V_43 , V_56 -> V_35 ,
( unsigned long long ) V_56 -> V_60 ) ;
F_55 ( V_14 , V_56 ) ;
}
F_285 (mpt3sas_port, next_port,
&ioc->sas_hba.sas_port_list, port_list) {
if ( V_318 -> V_320 . V_321 ==
V_322 )
F_44 ( V_14 ,
V_318 -> V_320 . V_17 ) ;
else if ( V_318 -> V_320 . V_321 ==
V_324 ||
V_318 -> V_320 . V_321 ==
V_325 )
F_241 ( V_14 ,
V_318 -> V_320 . V_17 ) ;
}
if ( V_14 -> V_39 . V_40 ) {
F_2 ( V_14 -> V_39 . V_225 ) ;
V_14 -> V_39 . V_225 = NULL ;
V_14 -> V_39 . V_40 = 0 ;
}
F_300 ( V_113 ) ;
F_301 ( V_113 ) ;
F_302 ( V_14 ) ;
F_14 ( & V_16 ) ;
F_56 ( & V_14 -> V_81 ) ;
F_16 ( & V_16 ) ;
F_303 ( V_113 ) ;
}
static void
F_304 ( struct V_759 * V_528 )
{
struct V_112 * V_113 = F_298 ( V_528 ) ;
struct V_13 * V_14 = F_67 ( V_113 ) ;
struct V_761 * V_762 ;
unsigned long V_76 ;
V_14 -> V_264 = 1 ;
F_150 ( V_14 ) ;
F_32 ( & V_14 -> V_303 , V_76 ) ;
V_762 = V_14 -> V_302 ;
V_14 -> V_302 = NULL ;
F_33 ( & V_14 -> V_303 , V_76 ) ;
if ( V_762 )
F_299 ( V_762 ) ;
F_296 ( V_14 ) ;
F_302 ( V_14 ) ;
}
static void
F_305 ( struct V_13 * V_14 )
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
V_28 = F_261 ( V_14 -> V_113 , V_133 ,
V_56 -> V_87 , 0 ) ;
if ( V_28 )
F_55 ( V_14 , V_56 ) ;
} else {
F_32 ( & V_14 -> V_74 , V_76 ) ;
V_54 = V_51 ;
V_35 = V_54 -> V_35 ;
V_84 = V_54 -> V_84 ;
V_17 = V_54 -> V_17 ;
F_286 ( & V_54 -> V_81 , & V_14 -> V_83 ) ;
F_33 ( & V_14 -> V_74 , V_76 ) ;
if ( V_14 -> V_624 )
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
F_306 ( struct V_13 * V_14 )
{
struct V_55 * V_56 , * V_763 ;
int V_28 ;
F_285 (raid_device, raid_next,
&ioc->raid_device_list, list) {
if ( V_56 -> V_85 )
continue;
V_28 = F_261 ( V_14 -> V_113 , V_133 ,
V_56 -> V_87 , 0 ) ;
if ( V_28 )
F_55 ( V_14 , V_56 ) ;
}
}
static struct V_53 * F_307 ( struct V_13 * V_14 )
{
struct V_53 * V_54 = NULL ;
unsigned long V_76 ;
F_32 ( & V_14 -> V_74 , V_76 ) ;
if ( ! F_39 ( & V_14 -> V_86 ) ) {
V_54 = F_149 ( & V_14 -> V_86 ,
struct V_53 , V_81 ) ;
F_30 ( V_54 ) ;
}
F_33 ( & V_14 -> V_74 , V_76 ) ;
return V_54 ;
}
static void F_308 ( struct V_13 * V_14 ,
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
F_309 ( struct V_13 * V_14 )
{
struct V_53 * V_54 ;
if ( V_14 -> V_624 )
return;
while ( ( V_54 = F_307 ( V_14 ) ) ) {
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
F_308 ( V_14 , V_54 ) ;
F_41 ( V_54 ) ;
}
}
static void
F_310 ( struct V_13 * V_14 )
{
T_4 V_764 ;
if ( ! ( V_14 -> V_202 . V_765 & V_766 ) )
return;
F_305 ( V_14 ) ;
if ( V_14 -> V_710 ) {
V_764 =
F_21 ( V_14 -> V_767 . V_768 ) &
V_769 ;
if ( V_764 ==
V_770 ) {
F_306 ( V_14 ) ;
F_309 ( V_14 ) ;
} else {
F_309 ( V_14 ) ;
F_306 ( V_14 ) ;
}
} else
F_309 ( V_14 ) ;
}
static void
F_311 ( struct V_112 * V_113 )
{
struct V_13 * V_14 = F_67 ( V_113 ) ;
int V_28 ;
if ( V_771 != - 1 && V_771 != 0 )
F_312 ( V_14 , V_771 ) ;
if ( V_665 > 0 )
return;
V_14 -> V_729 = 1 ;
V_28 = F_313 ( V_14 ) ;
if ( V_28 != 0 )
F_13 ( V_42 L_354 , V_14 -> V_43 ) ;
}
static int
F_314 ( struct V_112 * V_113 , unsigned long time )
{
struct V_13 * V_14 = F_67 ( V_113 ) ;
if ( V_665 > 0 ) {
V_14 -> V_57 = 0 ;
V_14 -> V_623 = 0 ;
return 1 ;
}
if ( time >= ( 300 * V_282 ) ) {
V_14 -> V_772 . V_246 = V_247 ;
F_13 ( V_42
L_355 ,
V_14 -> V_43 ) ;
V_14 -> V_57 = 0 ;
return 1 ;
}
if ( V_14 -> V_729 )
return 0 ;
if ( V_14 -> V_773 ) {
F_13 ( V_42
L_356 ,
V_14 -> V_43 , V_14 -> V_773 ) ;
V_14 -> V_57 = 0 ;
V_14 -> V_623 = 0 ;
V_14 -> V_264 = 1 ;
return 1 ;
}
F_13 ( V_42 L_357 , V_14 -> V_43 ) ;
V_14 -> V_772 . V_246 = V_247 ;
if ( V_14 -> V_623 ) {
V_14 -> V_623 = 0 ;
F_310 ( V_14 ) ;
}
F_315 ( V_14 ) ;
V_14 -> V_57 = 0 ;
return 1 ;
}
static T_4
F_316 ( struct V_759 * V_528 )
{
switch ( V_528 -> V_51 ) {
case V_774 :
case V_775 :
case V_776 :
case V_777 :
case V_778 :
case V_779 :
case V_780 :
case V_781 :
case V_782 :
case V_783 :
case V_784 :
case V_785 :
case V_786 :
case V_787 :
case V_788 :
case V_789 :
case V_790 :
return V_160 ;
case V_791 :
case V_792 :
case V_793 :
case V_794 :
case V_795 :
case V_796 :
return V_162 ;
case V_797 :
case V_798 :
case V_799 :
case V_800 :
case V_801 :
case V_802 :
case V_803 :
case V_804 :
case V_805 :
case V_806 :
return V_163 ;
}
return 0 ;
}
static int
F_317 ( struct V_759 * V_528 , const struct V_807 * V_87 )
{
struct V_13 * V_14 ;
struct V_112 * V_113 = NULL ;
int V_808 ;
T_4 V_809 ;
V_809 = F_316 ( V_528 ) ;
if ( V_809 == 0 )
return - V_810 ;
if ( ( V_811 == 1 ) && ( V_809 != V_160 ) )
return - V_810 ;
if ( ( V_811 == 2 ) && ( ! ( V_809 == V_162
|| V_809 == V_163 ) ) )
return - V_810 ;
switch ( V_809 ) {
case V_160 :
V_113 = F_318 ( & V_812 ,
sizeof( struct V_13 ) ) ;
if ( ! V_113 )
return - V_810 ;
V_14 = F_67 ( V_113 ) ;
memset ( V_14 , 0 , sizeof( struct V_13 ) ) ;
V_14 -> V_159 = V_809 ;
V_14 -> V_87 = V_813 ++ ;
sprintf ( V_14 -> V_814 , L_358 , V_815 ) ;
if ( V_528 -> V_51 == V_774 ) {
V_14 -> V_134 = 1 ;
V_14 -> V_218 = 1 ;
} else
V_14 -> V_816 = V_817 ;
break;
case V_162 :
case V_163 :
V_113 = F_318 ( & V_818 ,
sizeof( struct V_13 ) ) ;
if ( ! V_113 )
return - V_810 ;
V_14 = F_67 ( V_113 ) ;
memset ( V_14 , 0 , sizeof( struct V_13 ) ) ;
V_14 -> V_159 = V_809 ;
V_14 -> V_87 = V_819 ++ ;
sprintf ( V_14 -> V_814 , L_358 , V_820 ) ;
if ( ( V_14 -> V_159 == V_162 &&
V_528 -> V_821 >= V_822 ) ||
( V_14 -> V_159 == V_163 ) )
V_14 -> V_823 = 1 ;
break;
default:
return - V_810 ;
}
F_141 ( & V_14 -> V_81 ) ;
F_14 ( & V_16 ) ;
F_47 ( & V_14 -> V_81 , & V_824 ) ;
F_16 ( & V_16 ) ;
V_14 -> V_113 = V_113 ;
V_14 -> V_528 = V_528 ;
V_14 -> V_445 = V_445 ;
V_14 -> V_272 = V_272 ;
V_14 -> V_825 = V_825 ;
V_14 -> V_356 = V_356 ;
V_14 -> V_826 = V_826 ;
V_14 -> V_827 = V_827 ;
V_14 -> V_669 = V_669 ;
V_14 -> V_828 = V_828 ;
V_14 -> V_337 = V_337 ;
V_14 -> V_349 = V_349 ;
V_14 -> V_344 = V_344 ;
V_14 -> V_15 = V_15 ;
V_14 -> V_829 = & F_190 ;
F_319 ( & V_14 -> V_830 ) ;
F_319 ( & V_14 -> V_831 ) ;
F_320 ( & V_14 -> V_832 ) ;
F_320 ( & V_14 -> V_105 ) ;
F_320 ( & V_14 -> V_74 ) ;
F_320 ( & V_14 -> V_94 ) ;
F_320 ( & V_14 -> V_303 ) ;
F_320 ( & V_14 -> V_90 ) ;
F_320 ( & V_14 -> V_833 ) ;
F_141 ( & V_14 -> V_83 ) ;
F_141 ( & V_14 -> V_86 ) ;
F_141 ( & V_14 -> V_95 ) ;
F_141 ( & V_14 -> V_304 ) ;
F_141 ( & V_14 -> V_91 ) ;
F_141 ( & V_14 -> V_39 . V_590 ) ;
F_141 ( & V_14 -> V_338 ) ;
F_141 ( & V_14 -> V_345 ) ;
F_141 ( & V_14 -> V_364 ) ;
F_141 ( & V_14 -> V_350 ) ;
F_141 ( & V_14 -> V_834 ) ;
sprintf ( V_14 -> V_43 , L_359 , V_14 -> V_814 , V_14 -> V_87 ) ;
V_113 -> V_835 = 32 ;
V_113 -> V_836 = V_836 ;
V_113 -> V_837 = V_838 ;
V_113 -> V_839 = V_14 -> V_87 ;
if ( V_219 != 0xFFFF ) {
if ( V_219 < 64 ) {
V_113 -> V_219 = 64 ;
F_91 ( V_42 L_360 \
L_361
L_362 , V_14 -> V_43 , V_219 ) ;
} else if ( V_219 > 32767 ) {
V_113 -> V_219 = 32767 ;
F_91 ( V_42 L_360 \
L_361
L_363 , V_14 -> V_43 ,
V_219 ) ;
} else {
V_113 -> V_219 = V_219 & 0xFFFE ;
F_13 ( V_42
L_364 ,
V_14 -> V_43 , V_113 -> V_219 ) ;
}
}
if ( V_840 > 0 )
F_321 ( V_113 , V_840 ) ;
else
F_321 ( V_113 , V_841
| V_842
| V_843 ) ;
F_322 ( V_113 , V_844 ) ;
snprintf ( V_14 -> V_845 , sizeof( V_14 -> V_845 ) ,
L_365 , V_14 -> V_814 , V_14 -> V_87 ) ;
V_14 -> V_302 = F_323 (
V_14 -> V_845 , V_846 ) ;
if ( ! V_14 -> V_302 ) {
F_25 ( V_42 L_2 ,
V_14 -> V_43 , __FILE__ , __LINE__ , V_44 ) ;
V_808 = - V_810 ;
goto V_847;
}
V_14 -> V_57 = 1 ;
if ( ( F_324 ( V_14 ) ) ) {
F_25 ( V_42 L_2 ,
V_14 -> V_43 , __FILE__ , __LINE__ , V_44 ) ;
V_808 = - V_810 ;
goto V_848;
}
if ( V_14 -> V_134 ) {
if ( V_14 -> V_816 == V_817 )
V_14 -> V_624 = 0 ;
else if ( V_14 -> V_816 == V_849 )
V_14 -> V_624 = 1 ;
else {
if ( F_325 ( V_14 ) )
V_14 -> V_624 = 1 ;
else
V_14 -> V_624 = 0 ;
}
} else
V_14 -> V_624 = 0 ;
V_808 = F_326 ( V_113 , & V_528 -> V_127 ) ;
if ( V_808 ) {
F_25 ( V_42 L_2 ,
V_14 -> V_43 , __FILE__ , __LINE__ , V_44 ) ;
goto V_850;
}
F_327 ( V_113 ) ;
return 0 ;
V_850:
F_302 ( V_14 ) ;
V_848:
F_299 ( V_14 -> V_302 ) ;
V_847:
F_14 ( & V_16 ) ;
F_56 ( & V_14 -> V_81 ) ;
F_16 ( & V_16 ) ;
F_303 ( V_113 ) ;
return V_808 ;
}
static int
F_328 ( struct V_759 * V_528 , T_51 V_167 )
{
struct V_112 * V_113 = F_298 ( V_528 ) ;
struct V_13 * V_14 = F_67 ( V_113 ) ;
T_52 V_851 ;
F_329 ( V_14 ) ;
F_330 () ;
F_331 ( V_113 ) ;
V_851 = F_332 ( V_528 , V_167 ) ;
F_13 ( V_42
L_366 ,
V_14 -> V_43 , V_528 , F_333 ( V_528 ) , V_851 ) ;
F_334 ( V_528 ) ;
F_335 ( V_14 ) ;
F_336 ( V_528 , V_851 ) ;
return 0 ;
}
static int
F_337 ( struct V_759 * V_528 )
{
struct V_112 * V_113 = F_298 ( V_528 ) ;
struct V_13 * V_14 = F_67 ( V_113 ) ;
T_52 V_851 = V_528 -> V_852 ;
int V_2 ;
F_13 ( V_42
L_367 ,
V_14 -> V_43 , V_528 , F_333 ( V_528 ) , V_851 ) ;
F_336 ( V_528 , V_853 ) ;
F_338 ( V_528 , V_853 , 0 ) ;
F_339 ( V_528 ) ;
V_14 -> V_528 = V_528 ;
V_2 = F_340 ( V_14 ) ;
if ( V_2 )
return V_2 ;
F_116 ( V_14 , V_854 ) ;
F_341 ( V_113 ) ;
F_315 ( V_14 ) ;
return 0 ;
}
static T_53
F_342 ( struct V_759 * V_528 , T_54 V_167 )
{
struct V_112 * V_113 = F_298 ( V_528 ) ;
struct V_13 * V_14 = F_67 ( V_113 ) ;
F_13 ( V_42 L_368 ,
V_14 -> V_43 , V_167 ) ;
switch ( V_167 ) {
case V_855 :
return V_856 ;
case V_857 :
V_14 -> V_265 = 1 ;
F_331 ( V_14 -> V_113 ) ;
F_329 ( V_14 ) ;
F_335 ( V_14 ) ;
return V_858 ;
case V_859 :
V_14 -> V_265 = 1 ;
F_329 ( V_14 ) ;
F_190 ( V_14 ) ;
return V_860 ;
}
return V_858 ;
}
static T_53
F_343 ( struct V_759 * V_528 )
{
struct V_112 * V_113 = F_298 ( V_528 ) ;
struct V_13 * V_14 = F_67 ( V_113 ) ;
int V_28 ;
F_13 ( V_42 L_369 ,
V_14 -> V_43 ) ;
V_14 -> V_265 = 0 ;
V_14 -> V_528 = V_528 ;
F_339 ( V_528 ) ;
V_28 = F_340 ( V_14 ) ;
if ( V_28 )
return V_860 ;
V_28 = F_116 ( V_14 , V_267 ) ;
F_91 ( V_42 L_370 , V_14 -> V_43 ,
( V_28 == 0 ) ? L_124 : L_371 ) ;
if ( ! V_28 )
return V_861 ;
else
return V_860 ;
}
static void
F_344 ( struct V_759 * V_528 )
{
struct V_112 * V_113 = F_298 ( V_528 ) ;
struct V_13 * V_14 = F_67 ( V_113 ) ;
F_13 ( V_42 L_372 , V_14 -> V_43 ) ;
F_345 ( V_528 ) ;
F_315 ( V_14 ) ;
F_341 ( V_14 -> V_113 ) ;
}
static T_53
F_346 ( struct V_759 * V_528 )
{
struct V_112 * V_113 = F_298 ( V_528 ) ;
struct V_13 * V_14 = F_67 ( V_113 ) ;
F_13 ( V_42 L_373 ,
V_14 -> V_43 ) ;
return V_861 ;
}
static int
F_347 ( void )
{
V_813 = 0 ;
V_819 = 0 ;
F_348 () ;
V_445 = F_349 ( F_218 ) ;
V_272 = F_349 ( F_106 ) ;
V_356 = F_349 ( V_862 ) ;
V_826 = F_349 (
V_863 ) ;
V_827 = F_349 (
V_864 ) ;
V_669 = F_349 ( F_243 ) ;
V_828 = F_349 (
V_865 ) ;
V_825 = F_349 ( V_866 ) ;
V_337 = F_349 (
F_165 ) ;
V_349 = F_349 (
F_174 ) ;
V_344 = F_349 (
F_170 ) ;
return 0 ;
}
static void
F_350 ( void )
{
F_351 ( V_445 ) ;
F_351 ( V_272 ) ;
F_351 ( V_356 ) ;
F_351 ( V_826 ) ;
F_351 ( V_827 ) ;
F_351 ( V_669 ) ;
F_351 ( V_828 ) ;
F_351 ( V_825 ) ;
F_351 ( V_337 ) ;
F_351 ( V_349 ) ;
F_351 ( V_344 ) ;
if ( V_811 != 1 )
F_352 ( V_164 ) ;
if ( V_811 != 2 )
F_352 ( V_161 ) ;
F_353 ( V_838 ) ;
}
static int T_55
F_354 ( void )
{
int error ;
F_13 ( L_374 , V_820 ,
V_867 ) ;
V_838 =
F_355 ( & V_868 ) ;
if ( ! V_838 )
return - V_810 ;
if ( V_811 != 1 ) {
V_164 =
F_356 ( & V_869 ) ;
if ( ! V_164 ) {
F_353 ( V_838 ) ;
return - V_810 ;
}
}
if ( V_811 != 2 ) {
V_161 =
F_356 ( & V_870 ) ;
if ( ! V_161 ) {
F_353 ( V_838 ) ;
return - V_810 ;
}
}
error = F_347 () ;
if ( error ) {
F_350 () ;
return error ;
}
F_357 ( V_811 ) ;
error = F_358 ( & V_871 ) ;
if ( error )
F_350 () ;
return error ;
}
static void T_56
F_359 ( void )
{
F_13 ( L_375 ,
V_867 ) ;
F_360 ( & V_871 ) ;
F_361 ( V_811 ) ;
F_350 () ;
}
