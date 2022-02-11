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
void
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
F_66 ( V_75 , V_111 ) ;
if ( ! V_14 -> V_134 )
F_86 ( V_14 , V_75 , V_56 -> V_179 ) ;
return 0 ;
}
if ( V_118 -> V_76 & V_138 ) {
if ( F_99 ( V_14 , V_35 ,
& V_208 ) ) {
F_90 ( V_14 , F_91 ( V_42
L_2 , V_14 -> V_43 ,
__FILE__ , __LINE__ , V_44 ) ) ;
return 1 ;
}
if ( V_208 && F_100 ( V_14 ,
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
V_219 ) {
F_75 ( V_220 , V_75 ,
L_33 ,
V_117 -> V_122 -> V_35 ) ;
V_117 -> V_221 = 1 ;
V_206 = L_34 ;
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
F_75 ( V_144 , V_75 , L_35 \
L_36 ,
V_206 , V_35 , ( unsigned long long ) V_54 -> V_17 ,
V_54 -> V_222 , ( unsigned long long ) V_54 -> V_20 ) ;
if ( V_54 -> V_78 != 0 )
F_75 ( V_144 , V_75 ,
L_37 ,
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
F_101 ( V_75 ) ;
F_94 ( V_14 , V_75 ) ;
}
return 0 ;
}
int
F_102 ( struct V_110 * V_75 , struct V_223 * V_224 ,
T_13 V_225 , int V_226 [] )
{
int V_227 ;
int V_228 ;
T_13 V_229 ;
T_14 V_230 ;
V_227 = 64 ;
V_228 = 32 ;
V_230 = V_227 * V_228 ;
V_229 = V_225 ;
F_103 ( V_229 , V_230 ) ;
if ( ( T_14 ) V_225 >= 0x200000 ) {
V_227 = 255 ;
V_228 = 63 ;
V_230 = V_227 * V_228 ;
V_229 = V_225 ;
F_103 ( V_229 , V_230 ) ;
}
V_226 [ 0 ] = V_227 ;
V_226 [ 1 ] = V_228 ;
V_226 [ 2 ] = V_229 ;
return 0 ;
}
static void
F_104 ( struct V_13 * V_14 , T_6 V_231 )
{
char * V_232 ;
switch ( V_231 ) {
case V_233 :
V_232 = L_38 ;
break;
case V_234 :
V_232 = L_39 ;
break;
case V_235 :
V_232 = L_40 ;
break;
case V_236 :
V_232 = L_41 ;
break;
case V_237 :
V_232 = L_42 ;
break;
case V_238 :
V_232 = L_43 ;
break;
case 0xA :
V_232 = L_44 ;
break;
case V_239 :
V_232 = L_45 ;
break;
default:
V_232 = L_46 ;
break;
}
F_91 ( V_42 L_47 ,
V_14 -> V_43 , V_231 , V_232 ) ;
}
static T_6
F_105 ( struct V_13 * V_14 , T_4 V_102 , T_6 V_240 , T_10 V_241 )
{
T_15 * V_37 ;
if ( V_14 -> V_242 . V_243 == V_244 )
return 1 ;
if ( V_14 -> V_242 . V_102 != V_102 )
return 1 ;
F_106 ( V_14 ) ;
V_14 -> V_242 . V_243 |= V_245 ;
V_37 = F_107 ( V_14 , V_241 ) ;
if ( V_37 ) {
memcpy ( V_14 -> V_242 . V_241 , V_37 , V_37 -> V_246 * 4 ) ;
V_14 -> V_242 . V_243 |= V_247 ;
}
V_14 -> V_242 . V_243 &= ~ V_248 ;
F_108 ( & V_14 -> V_242 . V_249 ) ;
return 1 ;
}
void
F_109 ( struct V_13 * V_14 , T_4 V_35 )
{
struct V_116 * V_117 ;
struct V_110 * V_75 ;
T_6 V_250 = 0 ;
F_110 (sdev, ioc->shost) {
if ( V_250 )
continue;
V_117 = V_75 -> V_120 ;
if ( ! V_117 )
continue;
if ( V_117 -> V_122 -> V_35 == V_35 ) {
V_117 -> V_122 -> V_251 = 1 ;
V_250 = 1 ;
V_14 -> V_252 = 1 ;
}
}
}
void
F_111 ( struct V_13 * V_14 , T_4 V_35 )
{
struct V_116 * V_117 ;
struct V_110 * V_75 ;
T_6 V_250 = 0 ;
F_110 (sdev, ioc->shost) {
if ( V_250 )
continue;
V_117 = V_75 -> V_120 ;
if ( ! V_117 )
continue;
if ( V_117 -> V_122 -> V_35 == V_35 ) {
V_117 -> V_122 -> V_251 = 0 ;
V_250 = 1 ;
V_14 -> V_252 = 0 ;
}
}
}
int
F_112 ( struct V_13 * V_14 , T_4 V_35 , T_16 V_88 ,
T_16 V_87 , T_16 V_109 , T_6 type , T_4 V_253 , T_14 V_254 ,
enum V_255 V_256 )
{
T_17 * V_257 ;
T_18 * V_37 ;
T_4 V_102 = 0 ;
T_10 V_258 ;
unsigned long V_259 ;
struct V_260 * V_103 = NULL ;
int V_28 ;
T_4 V_261 = 0 ;
if ( V_256 == V_262 )
F_113 ( & V_14 -> V_242 . V_263 ) ;
if ( V_14 -> V_242 . V_243 != V_244 ) {
F_13 ( V_42 L_48 ,
V_44 , V_14 -> V_43 ) ;
V_28 = V_264 ;
goto V_265;
}
if ( V_14 -> V_82 || V_14 -> V_266 ||
V_14 -> V_267 ) {
F_13 ( V_42 L_49 ,
V_44 , V_14 -> V_43 ) ;
V_28 = V_264 ;
goto V_265;
}
V_258 = F_114 ( V_14 , 0 ) ;
if ( V_258 & V_268 ) {
F_115 ( V_14 , F_13 ( V_42
L_50 , V_14 -> V_43 ) ) ;
V_28 = F_116 ( V_14 , V_269 ,
V_270 ) ;
V_28 = ( ! V_28 ) ? V_271 : V_264 ;
goto V_265;
}
if ( ( V_258 & V_272 ) == V_273 ) {
F_117 ( V_14 , V_258 &
V_274 ) ;
V_28 = F_116 ( V_14 , V_269 ,
V_270 ) ;
V_28 = ( ! V_28 ) ? V_271 : V_264 ;
goto V_265;
}
V_102 = F_118 ( V_14 , V_14 -> V_275 ) ;
if ( ! V_102 ) {
F_25 ( V_42 L_51 ,
V_14 -> V_43 , V_44 ) ;
V_28 = V_264 ;
goto V_265;
}
if ( type == V_276 )
V_103 = & V_14 -> V_103 [ V_253 - 1 ] ;
F_119 ( V_14 , F_13 ( V_42
L_52 ,
V_14 -> V_43 , V_35 , type , V_253 ) ) ;
V_14 -> V_242 . V_243 = V_248 ;
V_257 = F_120 ( V_14 , V_102 ) ;
V_14 -> V_242 . V_102 = V_102 ;
memset ( V_257 , 0 , sizeof( T_17 ) ) ;
memset ( V_14 -> V_242 . V_241 , 0 , sizeof( T_18 ) ) ;
V_257 -> V_277 = V_278 ;
V_257 -> V_200 = F_121 ( V_35 ) ;
V_257 -> V_279 = type ;
V_257 -> V_280 = F_121 ( V_253 ) ;
F_122 ( V_109 , (struct V_281 * ) V_257 -> V_282 ) ;
F_109 ( V_14 , V_35 ) ;
F_123 ( & V_14 -> V_242 . V_249 ) ;
if ( ( type == V_276 ) &&
( V_103 -> V_283 < V_14 -> V_284 ) )
V_261 = V_103 -> V_283 ;
else
V_261 = 0 ;
F_124 ( V_14 , V_102 , V_261 ) ;
V_259 = F_125 ( & V_14 -> V_242 . V_249 , V_254 * V_285 ) ;
if ( ! ( V_14 -> V_242 . V_243 & V_245 ) ) {
F_25 ( V_42 L_53 ,
V_14 -> V_43 , V_44 ) ;
F_126 ( V_257 ,
sizeof( T_17 ) / 4 ) ;
if ( ! ( V_14 -> V_242 . V_243 & V_286 ) ) {
V_28 = F_116 ( V_14 , V_269 ,
V_270 ) ;
V_28 = ( ! V_28 ) ? V_271 : V_264 ;
V_14 -> V_242 . V_243 = V_244 ;
F_111 ( V_14 , V_35 ) ;
goto V_265;
}
}
if ( V_14 -> V_242 . V_243 & V_247 ) {
F_127 ( V_14 , V_287 ) ;
V_37 = V_14 -> V_242 . V_241 ;
F_119 ( V_14 , F_13 ( V_42 L_54 \
L_55 ,
V_14 -> V_43 , F_21 ( V_37 -> V_46 ) ,
F_78 ( V_37 -> V_288 ) ,
F_78 ( V_37 -> V_289 ) ) ) ;
if ( V_14 -> V_15 & V_290 ) {
F_104 ( V_14 , V_37 -> V_291 ) ;
if ( V_37 -> V_46 )
F_126 ( V_257 ,
sizeof( T_17 ) / 4 ) ;
}
}
switch ( type ) {
case V_276 :
V_28 = V_271 ;
if ( V_103 -> V_104 == NULL )
break;
V_28 = V_264 ;
break;
case V_292 :
if ( F_64 ( V_14 , V_87 , V_88 ) )
V_28 = V_264 ;
else
V_28 = V_271 ;
break;
case V_293 :
case V_294 :
if ( F_65 ( V_14 , V_87 , V_109 , V_88 ) )
V_28 = V_264 ;
else
V_28 = V_271 ;
break;
case V_295 :
V_28 = V_271 ;
break;
default:
V_28 = V_264 ;
break;
}
F_111 ( V_14 , V_35 ) ;
V_14 -> V_242 . V_243 = V_244 ;
if ( V_256 == V_262 )
F_128 ( & V_14 -> V_242 . V_263 ) ;
return V_28 ;
V_265:
if ( V_256 == V_262 )
F_128 ( & V_14 -> V_242 . V_263 ) ;
return V_28 ;
}
static void
F_129 ( struct V_13 * V_14 , struct V_101 * V_104 )
{
struct V_126 * V_85 = V_104 -> V_51 -> V_296 ;
struct V_72 * V_297 = V_85 -> V_120 ;
struct V_53 * V_54 = NULL ;
unsigned long V_76 ;
char * V_298 = NULL ;
if ( ! V_297 )
return;
if ( V_14 -> V_218 )
V_298 = L_56 ;
else
V_298 = L_57 ;
F_130 ( V_104 ) ;
if ( V_297 -> V_76 & V_123 ) {
F_131 ( V_144 , V_85 ,
L_58 ,
V_298 , V_297 -> V_35 ,
V_298 , ( unsigned long long ) V_297 -> V_17 ) ;
} else {
F_32 ( & V_14 -> V_74 , V_76 ) ;
V_54 = F_28 ( V_14 , V_297 ) ;
if ( V_54 ) {
if ( V_297 -> V_76 &
V_138 ) {
F_131 ( V_144 , V_85 ,
L_59
L_60 ,
V_54 -> V_208 ,
( unsigned long long ) V_54 -> V_209 ) ;
}
F_131 ( V_144 , V_85 ,
L_61 ,
V_54 -> V_35 ,
( unsigned long long ) V_54 -> V_17 ,
V_54 -> V_222 ) ;
if ( V_54 -> V_78 != 0 )
F_131 ( V_144 , V_85 ,
L_62 ,
( unsigned long long )
V_54 -> V_22 ,
V_54 -> V_26 ) ;
if ( V_54 -> V_79 [ 0 ] != '\0' )
F_131 ( V_144 , V_85 ,
L_63 ,
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
L_64 , V_104 ) ;
F_129 ( V_14 , V_104 ) ;
V_117 = V_104 -> V_51 -> V_120 ;
if ( ! V_117 || ! V_117 -> V_122 ) {
F_75 ( V_144 , V_104 -> V_51 ,
L_65 , V_104 ) ;
V_104 -> V_299 = V_300 << 16 ;
V_104 -> V_301 ( V_104 ) ;
V_2 = V_271 ;
goto V_89;
}
V_102 = F_63 ( V_14 , V_104 ) ;
if ( ! V_102 ) {
V_104 -> V_299 = V_302 << 16 ;
V_2 = V_271 ;
goto V_89;
}
if ( V_117 -> V_122 -> V_76 &
V_138 ||
V_117 -> V_122 -> V_76 & V_123 ) {
V_104 -> V_299 = V_302 << 16 ;
V_2 = V_264 ;
goto V_89;
}
F_133 ( V_14 ) ;
V_35 = V_117 -> V_122 -> V_35 ;
V_2 = F_112 ( V_14 , V_35 , V_104 -> V_51 -> V_88 ,
V_104 -> V_51 -> V_87 , V_104 -> V_51 -> V_109 ,
V_276 , V_102 , 30 , V_262 ) ;
V_89:
F_75 ( V_144 , V_104 -> V_51 , L_66 ,
( ( V_2 == V_271 ) ? L_67 : L_68 ) , V_104 ) ;
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
struct V_126 * V_85 = V_104 -> V_51 -> V_296 ;
struct V_72 * V_303 = V_85 -> V_120 ;
F_75 ( V_144 , V_104 -> V_51 ,
L_69 , V_104 ) ;
F_129 ( V_14 , V_104 ) ;
V_117 = V_104 -> V_51 -> V_120 ;
if ( ! V_117 || ! V_117 -> V_122 ) {
F_75 ( V_144 , V_104 -> V_51 ,
L_65 , V_104 ) ;
V_104 -> V_299 = V_300 << 16 ;
V_104 -> V_301 ( V_104 ) ;
V_2 = V_271 ;
goto V_89;
}
V_35 = 0 ;
if ( V_117 -> V_122 -> V_76 &
V_138 ) {
V_54 = F_31 ( V_14 ,
V_303 ) ;
if ( V_54 )
V_35 = V_54 -> V_208 ;
} else
V_35 = V_117 -> V_122 -> V_35 ;
if ( ! V_35 ) {
V_104 -> V_299 = V_302 << 16 ;
V_2 = V_264 ;
goto V_89;
}
V_2 = F_112 ( V_14 , V_35 , V_104 -> V_51 -> V_88 ,
V_104 -> V_51 -> V_87 , V_104 -> V_51 -> V_109 ,
V_294 , 0 , 30 , V_262 ) ;
V_89:
F_75 ( V_144 , V_104 -> V_51 , L_70 ,
( ( V_2 == V_271 ) ? L_67 : L_68 ) , V_104 ) ;
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
struct V_126 * V_85 = V_104 -> V_51 -> V_296 ;
struct V_72 * V_303 = V_85 -> V_120 ;
F_131 ( V_144 , V_85 , L_71 ,
V_104 ) ;
F_129 ( V_14 , V_104 ) ;
V_117 = V_104 -> V_51 -> V_120 ;
if ( ! V_117 || ! V_117 -> V_122 ) {
F_131 ( V_144 , V_85 , L_72 ,
V_104 ) ;
V_104 -> V_299 = V_300 << 16 ;
V_104 -> V_301 ( V_104 ) ;
V_2 = V_271 ;
goto V_89;
}
V_35 = 0 ;
if ( V_117 -> V_122 -> V_76 &
V_138 ) {
V_54 = F_31 ( V_14 ,
V_303 ) ;
if ( V_54 )
V_35 = V_54 -> V_208 ;
} else
V_35 = V_117 -> V_122 -> V_35 ;
if ( ! V_35 ) {
V_104 -> V_299 = V_302 << 16 ;
V_2 = V_264 ;
goto V_89;
}
V_2 = F_112 ( V_14 , V_35 , V_104 -> V_51 -> V_88 ,
V_104 -> V_51 -> V_87 , 0 , V_292 , 0 ,
30 , V_262 ) ;
V_89:
F_131 ( V_144 , V_85 , L_73 ,
( ( V_2 == V_271 ) ? L_67 : L_68 ) , V_104 ) ;
if ( V_54 )
F_41 ( V_54 ) ;
return V_2 ;
}
int
F_136 ( struct V_101 * V_104 )
{
struct V_13 * V_14 = F_67 ( V_104 -> V_51 -> V_114 ) ;
int V_2 , V_304 ;
F_13 ( V_42 L_74 ,
V_14 -> V_43 , V_104 ) ;
F_130 ( V_104 ) ;
if ( V_14 -> V_57 ) {
F_13 ( V_42 L_75 ,
V_14 -> V_43 ) ;
V_2 = V_264 ;
goto V_89;
}
V_304 = F_116 ( V_14 , V_269 ,
V_270 ) ;
V_2 = ( V_304 < 0 ) ? V_264 : V_271 ;
V_89:
F_13 ( V_42 L_76 ,
V_14 -> V_43 , ( ( V_2 == V_271 ) ? L_67 : L_68 ) , V_104 ) ;
return V_2 ;
}
static void
F_137 ( struct V_13 * V_14 , struct V_3 * V_7 )
{
unsigned long V_76 ;
if ( V_14 -> V_305 == NULL )
return;
F_32 ( & V_14 -> V_306 , V_76 ) ;
F_4 ( V_7 ) ;
F_138 ( & V_7 -> V_81 ) ;
F_47 ( & V_7 -> V_81 , & V_14 -> V_307 ) ;
F_139 ( & V_7 -> V_308 , V_309 ) ;
F_4 ( V_7 ) ;
F_140 ( V_14 -> V_305 , & V_7 -> V_308 ) ;
F_33 ( & V_14 -> V_306 , V_76 ) ;
}
static void
F_141 ( struct V_13 * V_14 , struct V_3
* V_7 )
{
unsigned long V_76 ;
F_32 ( & V_14 -> V_306 , V_76 ) ;
if ( ! F_39 ( & V_7 -> V_81 ) ) {
F_40 ( & V_7 -> V_81 ) ;
F_6 ( V_7 ) ;
}
F_33 ( & V_14 -> V_306 , V_76 ) ;
}
void
F_142 ( struct V_13 * V_14 ,
struct V_310 * V_311 )
{
struct V_3 * V_7 ;
T_4 V_193 ;
if ( V_14 -> V_57 )
return;
V_193 = sizeof( * V_311 ) ;
V_7 = F_8 ( V_193 ) ;
if ( ! V_7 )
return;
V_7 -> V_312 = V_313 ;
V_7 -> V_14 = V_14 ;
memcpy ( V_7 -> V_311 , V_311 , sizeof( * V_311 ) ) ;
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
V_7 -> V_312 = V_314 ;
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
V_7 -> V_312 = V_315 ;
V_7 -> V_14 = V_14 ;
F_137 ( V_14 , V_7 ) ;
F_6 ( V_7 ) ;
}
static struct V_3 * F_145 ( struct V_13 * V_14 )
{
unsigned long V_76 ;
struct V_3 * V_7 = NULL ;
F_32 ( & V_14 -> V_306 , V_76 ) ;
if ( ! F_39 ( & V_14 -> V_307 ) ) {
V_7 = F_146 ( & V_14 -> V_307 ,
struct V_3 , V_81 ) ;
F_40 ( & V_7 -> V_81 ) ;
}
F_33 ( & V_14 -> V_306 , V_76 ) ;
return V_7 ;
}
static void
F_147 ( struct V_13 * V_14 )
{
struct V_3 * V_7 ;
if ( F_39 ( & V_14 -> V_307 ) ||
! V_14 -> V_305 || F_148 () )
return;
while ( ( V_7 = F_145 ( V_14 ) ) ) {
if ( F_149 ( & V_7 -> V_316 ) )
F_6 ( V_7 ) ;
F_6 ( V_7 ) ;
}
}
static void
F_150 ( struct V_110 * V_75 ,
struct V_116 * V_117 )
{
int V_2 = 0 ;
F_75 ( V_144 , V_75 , L_77 ,
V_117 -> V_122 -> V_35 ) ;
V_117 -> V_317 = 1 ;
V_2 = F_151 ( V_75 ) ;
if ( V_2 == - V_318 )
F_75 ( V_220 , V_75 ,
L_78 ,
V_117 -> V_122 -> V_35 , V_2 ) ;
}
static void
F_152 ( struct V_110 * V_75 ,
struct V_116 * V_117 )
{
int V_2 = 0 ;
F_75 ( V_220 , V_75 , L_79
L_80 , V_117 -> V_122 -> V_35 ) ;
V_117 -> V_317 = 0 ;
V_2 = F_153 ( V_75 , V_319 ) ;
if ( V_2 == - V_318 ) {
F_75 ( V_220 , V_75 ,
L_81
L_82 ,
V_117 -> V_122 -> V_35 , V_2 ) ;
V_117 -> V_317 = 1 ;
V_2 = F_151 ( V_75 ) ;
if ( V_2 )
F_75 ( V_220 , V_75 , L_83
L_84 ,
V_117 -> V_122 -> V_35 , V_2 ) ;
V_117 -> V_317 = 0 ;
V_2 = F_153 ( V_75 , V_319 ) ;
if ( V_2 )
F_75 ( V_220 , V_75 , L_85
L_86 ,
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
if ( ! V_117 -> V_317 )
continue;
F_46 ( V_14 , F_75 ( V_144 , V_75 ,
L_87 ,
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
if ( V_117 -> V_317 )
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
if ( V_117 -> V_317 )
continue;
if ( V_117 -> V_221 ) {
F_75 ( V_144 , V_75 ,
L_88 ,
V_44 , V_117 -> V_122 -> V_35 ) ;
continue;
}
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
if ( V_117 -> V_317 )
continue;
if ( V_54 -> V_320 )
continue;
if ( V_117 -> V_221 ) {
F_75 ( V_144 , V_75 ,
L_88 ,
V_44 , V_117 -> V_122 -> V_35 ) ;
continue;
}
F_150 ( V_75 , V_117 ) ;
}
F_41 ( V_54 ) ;
}
static void
F_158 ( struct V_13 * V_14 ,
struct V_92 * V_93 )
{
struct V_321 * V_322 ;
struct V_53 * V_54 ;
struct V_92 * V_323 ;
unsigned long V_76 ;
if ( ! V_93 )
return;
F_15 (mpt3sas_port,
&sas_expander->sas_port_list, port_list) {
if ( V_322 -> V_324 . V_325 ==
V_326 ) {
F_32 ( & V_14 -> V_74 , V_76 ) ;
V_54 = F_34 ( V_14 ,
V_322 -> V_324 . V_17 ) ;
if ( V_54 ) {
F_159 ( V_54 -> V_35 ,
V_14 -> V_327 ) ;
F_41 ( V_54 ) ;
}
F_33 ( & V_14 -> V_74 , V_76 ) ;
}
}
F_15 (mpt3sas_port,
&sas_expander->sas_port_list, port_list) {
if ( V_322 -> V_324 . V_325 ==
V_328 ||
V_322 -> V_324 . V_325 ==
V_329 ) {
V_323 =
F_58 (
V_14 , V_322 -> V_324 . V_17 ) ;
F_158 ( V_14 ,
V_323 ) ;
}
}
}
static void
F_160 ( struct V_13 * V_14 ,
T_19 * V_311 )
{
int V_106 ;
T_4 V_35 ;
T_4 V_330 ;
for ( V_106 = 0 ; V_106 < V_311 -> V_331 ; V_106 ++ ) {
V_35 = F_21 ( V_311 -> V_332 [ V_106 ] . V_333 ) ;
if ( ! V_35 )
continue;
V_330 = V_311 -> V_332 [ V_106 ] . V_334 &
V_335 ;
if ( V_330 == V_336 )
F_157 ( V_14 , V_35 ) ;
}
}
static void
F_161 ( struct V_13 * V_14 , T_4 V_35 )
{
T_17 * V_257 ;
T_4 V_102 ;
struct V_53 * V_54 = NULL ;
struct V_72 * V_118 = NULL ;
T_1 V_17 = 0 ;
unsigned long V_76 ;
struct V_337 * V_338 ;
T_10 V_258 ;
if ( V_14 -> V_266 ) {
F_46 ( V_14 , F_13 ( V_42
L_89 ,
V_44 , V_14 -> V_43 , V_35 ) ) ;
return;
} else if ( V_14 -> V_267 ) {
F_46 ( V_14 , F_13 ( V_42
L_90 ,
V_44 , V_14 -> V_43 ,
V_35 ) ) ;
return;
}
V_258 = F_114 ( V_14 , 1 ) ;
if ( V_258 != V_339 ) {
F_46 ( V_14 , F_13 ( V_42
L_91 ,
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
V_118 -> V_340 = 1 ;
V_17 = V_54 -> V_17 ;
}
F_33 ( & V_14 -> V_74 , V_76 ) ;
if ( V_118 ) {
F_46 ( V_14 , F_13 ( V_42
L_92 ,
V_14 -> V_43 , V_35 ,
( unsigned long long ) V_17 ) ) ;
if ( V_54 -> V_78 != 0 )
F_46 ( V_14 , F_13 ( V_42
L_93
L_94 , V_14 -> V_43 , ( unsigned long long )
V_54 -> V_22 ,
V_54 -> V_26 ) ) ;
if ( V_54 -> V_79 [ 0 ] != '\0' )
F_46 ( V_14 , F_13 ( V_42
L_95
L_96 , V_14 -> V_43 ,
V_54 -> V_80 ,
V_54 -> V_79 ) ) ;
F_155 ( V_14 , V_17 ) ;
V_118 -> V_35 = V_132 ;
}
V_102 = F_118 ( V_14 , V_14 -> V_341 ) ;
if ( ! V_102 ) {
V_338 = F_9 ( sizeof( * V_338 ) , V_8 ) ;
if ( ! V_338 )
goto V_89;
F_138 ( & V_338 -> V_81 ) ;
V_338 -> V_35 = V_35 ;
F_47 ( & V_338 -> V_81 , & V_14 -> V_342 ) ;
F_46 ( V_14 , F_13 ( V_42
L_97 ,
V_14 -> V_43 , V_35 ) ) ;
goto V_89;
}
F_46 ( V_14 , F_13 ( V_42
L_98 ,
V_14 -> V_43 , V_35 , V_102 ,
V_14 -> V_341 ) ) ;
V_257 = F_120 ( V_14 , V_102 ) ;
memset ( V_257 , 0 , sizeof( T_17 ) ) ;
V_257 -> V_277 = V_278 ;
V_257 -> V_200 = F_121 ( V_35 ) ;
V_257 -> V_279 = V_292 ;
F_124 ( V_14 , V_102 , 0 ) ;
F_127 ( V_14 , V_343 ) ;
V_89:
if ( V_54 )
F_41 ( V_54 ) ;
}
static T_6
F_162 ( struct V_13 * V_14 , T_4 V_102 , T_6 V_240 ,
T_10 V_241 )
{
T_4 V_35 ;
T_17 * V_344 ;
T_18 * V_37 =
F_107 ( V_14 , V_241 ) ;
T_20 * V_257 ;
T_4 V_345 ;
T_10 V_258 ;
struct V_346 * V_347 ;
if ( V_14 -> V_266 ) {
F_46 ( V_14 , F_13 ( V_42
L_99 , V_44 , V_14 -> V_43 ) ) ;
return 1 ;
} else if ( V_14 -> V_267 ) {
F_46 ( V_14 , F_13 ( V_42
L_100 , V_44 ,
V_14 -> V_43 ) ) ;
return 1 ;
}
V_258 = F_114 ( V_14 , 1 ) ;
if ( V_258 != V_339 ) {
F_46 ( V_14 , F_13 ( V_42
L_101 , V_44 , V_14 -> V_43 ) ) ;
return 1 ;
}
if ( F_163 ( ! V_37 ) ) {
F_25 ( V_42 L_102 ,
V_14 -> V_43 , __FILE__ , __LINE__ , V_44 ) ;
return 1 ;
}
V_344 = F_120 ( V_14 , V_102 ) ;
V_35 = F_21 ( V_344 -> V_200 ) ;
if ( V_35 != F_21 ( V_37 -> V_200 ) ) {
F_46 ( V_14 , F_25 ( V_42
L_103 ,
V_14 -> V_43 , V_35 ,
F_21 ( V_37 -> V_200 ) , V_102 ) ) ;
return 0 ;
}
F_127 ( V_14 , V_287 ) ;
F_46 ( V_14 , F_13 ( V_42
L_104
L_105 , V_14 -> V_43 ,
V_35 , V_102 , F_21 ( V_37 -> V_46 ) ,
F_78 ( V_37 -> V_288 ) ,
F_78 ( V_37 -> V_289 ) ) ) ;
V_345 = F_164 ( V_14 , V_14 -> V_348 ) ;
if ( ! V_345 ) {
V_347 = F_9 ( sizeof( * V_347 ) , V_8 ) ;
if ( ! V_347 )
return F_165 ( V_14 , V_102 ) ;
F_138 ( & V_347 -> V_81 ) ;
V_347 -> V_35 = V_344 -> V_200 ;
F_47 ( & V_347 -> V_81 , & V_14 -> V_349 ) ;
F_46 ( V_14 , F_13 ( V_42
L_106 ,
V_14 -> V_43 , V_35 ) ) ;
return F_165 ( V_14 , V_102 ) ;
}
F_46 ( V_14 , F_13 ( V_42
L_107 ,
V_14 -> V_43 , V_35 , V_345 ,
V_14 -> V_348 ) ) ;
V_257 = F_120 ( V_14 , V_345 ) ;
memset ( V_257 , 0 , sizeof( T_20 ) ) ;
V_257 -> V_277 = V_350 ;
V_257 -> V_351 = V_352 ;
V_257 -> V_200 = V_344 -> V_200 ;
F_166 ( V_14 , V_345 ) ;
return F_165 ( V_14 , V_102 ) ;
}
static T_6
F_167 ( struct V_13 * V_14 , T_4 V_102 ,
T_6 V_240 , T_10 V_241 )
{
T_21 * V_37 =
F_107 ( V_14 , V_241 ) ;
if ( F_168 ( V_37 ) ) {
F_46 ( V_14 , F_13 ( V_42
L_108
L_109 ,
V_14 -> V_43 , F_21 ( V_37 -> V_200 ) , V_102 ,
F_21 ( V_37 -> V_46 ) ,
F_78 ( V_37 -> V_288 ) ) ) ;
} else {
F_25 ( V_42 L_102 ,
V_14 -> V_43 , __FILE__ , __LINE__ , V_44 ) ;
}
return F_169 ( V_14 , V_102 ) ;
}
static void
F_170 ( struct V_13 * V_14 , T_4 V_35 )
{
T_17 * V_257 ;
T_4 V_102 ;
struct V_337 * V_338 ;
if ( V_14 -> V_82 || V_14 -> V_266 ||
V_14 -> V_267 ) {
F_46 ( V_14 , F_13 ( V_42
L_49 ,
V_44 , V_14 -> V_43 ) ) ;
return;
}
V_102 = F_118 ( V_14 , V_14 -> V_353 ) ;
if ( ! V_102 ) {
V_338 = F_9 ( sizeof( * V_338 ) , V_8 ) ;
if ( ! V_338 )
return;
F_138 ( & V_338 -> V_81 ) ;
V_338 -> V_35 = V_35 ;
F_47 ( & V_338 -> V_81 , & V_14 -> V_354 ) ;
F_46 ( V_14 , F_13 ( V_42
L_97 ,
V_14 -> V_43 , V_35 ) ) ;
return;
}
F_46 ( V_14 , F_13 ( V_42
L_98 ,
V_14 -> V_43 , V_35 , V_102 ,
V_14 -> V_353 ) ) ;
V_257 = F_120 ( V_14 , V_102 ) ;
memset ( V_257 , 0 , sizeof( T_17 ) ) ;
V_257 -> V_277 = V_278 ;
V_257 -> V_200 = F_121 ( V_35 ) ;
V_257 -> V_279 = V_292 ;
F_124 ( V_14 , V_102 , 0 ) ;
}
static T_6
F_171 ( struct V_13 * V_14 , T_4 V_102 ,
T_6 V_240 , T_10 V_241 )
{
T_4 V_35 ;
T_17 * V_344 ;
T_18 * V_37 =
F_107 ( V_14 , V_241 ) ;
if ( V_14 -> V_82 || V_14 -> V_266 ||
V_14 -> V_267 ) {
F_46 ( V_14 , F_13 ( V_42
L_49 ,
V_44 , V_14 -> V_43 ) ) ;
return 1 ;
}
if ( F_163 ( ! V_37 ) ) {
F_25 ( V_42 L_102 ,
V_14 -> V_43 , __FILE__ , __LINE__ , V_44 ) ;
return 1 ;
}
V_344 = F_120 ( V_14 , V_102 ) ;
V_35 = F_21 ( V_344 -> V_200 ) ;
if ( V_35 != F_21 ( V_37 -> V_200 ) ) {
F_46 ( V_14 , F_25 ( V_42
L_103 ,
V_14 -> V_43 , V_35 ,
F_21 ( V_37 -> V_200 ) , V_102 ) ) ;
return 0 ;
}
F_46 ( V_14 , F_13 ( V_42
L_104
L_105 , V_14 -> V_43 ,
V_35 , V_102 , F_21 ( V_37 -> V_46 ) ,
F_78 ( V_37 -> V_288 ) ,
F_78 ( V_37 -> V_289 ) ) ) ;
return F_165 ( V_14 , V_102 ) ;
}
void
F_172 ( struct V_13 * V_14 , T_4 V_102 , T_4 V_312 ,
T_10 V_355 )
{
T_22 * V_356 ;
int V_106 = V_102 - V_14 -> V_357 ;
unsigned long V_76 ;
F_32 ( & V_14 -> V_105 , V_76 ) ;
V_14 -> V_358 [ V_106 ] . V_359 = V_14 -> V_360 ;
F_33 ( & V_14 -> V_105 , V_76 ) ;
F_46 ( V_14 , F_13 ( V_42
L_110 ,
V_14 -> V_43 , F_21 ( V_312 ) , V_102 ,
V_14 -> V_360 ) ) ;
V_356 = F_120 ( V_14 , V_102 ) ;
memset ( V_356 , 0 , sizeof( T_22 ) ) ;
V_356 -> V_277 = V_361 ;
V_356 -> V_362 = V_312 ;
V_356 -> V_363 = V_355 ;
V_356 -> V_364 = 0 ;
V_356 -> V_365 = 0 ;
F_166 ( V_14 , V_102 ) ;
}
void
F_173 ( struct V_13 * V_14 ,
T_4 V_102 , T_4 V_35 )
{
T_20 * V_257 ;
T_10 V_258 ;
int V_106 = V_102 - V_14 -> V_357 ;
unsigned long V_76 ;
if ( V_14 -> V_266 ) {
F_46 ( V_14 , F_13 ( V_42
L_99 ,
V_44 , V_14 -> V_43 ) ) ;
return;
} else if ( V_14 -> V_267 ) {
F_46 ( V_14 , F_13 ( V_42
L_100 ,
V_44 , V_14 -> V_43 ) ) ;
return;
}
V_258 = F_114 ( V_14 , 1 ) ;
if ( V_258 != V_339 ) {
F_46 ( V_14 , F_13 ( V_42
L_101 ,
V_44 , V_14 -> V_43 ) ) ;
return;
}
F_32 ( & V_14 -> V_105 , V_76 ) ;
V_14 -> V_358 [ V_106 ] . V_359 = V_14 -> V_348 ;
F_33 ( & V_14 -> V_105 , V_76 ) ;
F_46 ( V_14 , F_13 ( V_42
L_107 ,
V_14 -> V_43 , F_21 ( V_35 ) , V_102 ,
V_14 -> V_348 ) ) ;
V_257 = F_120 ( V_14 , V_102 ) ;
memset ( V_257 , 0 , sizeof( T_20 ) ) ;
V_257 -> V_277 = V_350 ;
V_257 -> V_351 = V_352 ;
V_257 -> V_200 = V_35 ;
F_166 ( V_14 , V_102 ) ;
}
T_6
F_169 ( struct V_13 * V_14 , T_4 V_102 )
{
struct V_346 * V_347 ;
struct V_366 * V_367 ;
if ( ! F_39 ( & V_14 -> V_368 ) ) {
V_367 = F_174 ( V_14 -> V_368 . V_369 ,
struct V_366 , V_81 ) ;
F_172 ( V_14 , V_102 ,
V_367 -> V_362 , V_367 -> V_363 ) ;
F_56 ( & V_367 -> V_81 ) ;
F_2 ( V_367 ) ;
return 0 ;
}
if ( ! F_39 ( & V_14 -> V_349 ) ) {
V_347 = F_174 ( V_14 -> V_349 . V_369 ,
struct V_346 , V_81 ) ;
F_173 ( V_14 , V_102 ,
V_347 -> V_35 ) ;
F_56 ( & V_347 -> V_81 ) ;
F_2 ( V_347 ) ;
return 0 ;
}
return 1 ;
}
static T_6
F_165 ( struct V_13 * V_14 , T_4 V_102 )
{
struct V_337 * V_338 ;
if ( ! F_39 ( & V_14 -> V_354 ) ) {
V_338 = F_174 ( V_14 -> V_354 . V_369 ,
struct V_337 , V_81 ) ;
F_175 ( V_14 , V_102 ) ;
F_170 ( V_14 , V_338 -> V_35 ) ;
F_56 ( & V_338 -> V_81 ) ;
F_2 ( V_338 ) ;
return 0 ;
}
if ( ! F_39 ( & V_14 -> V_342 ) ) {
V_338 = F_174 ( V_14 -> V_342 . V_369 ,
struct V_337 , V_81 ) ;
F_175 ( V_14 , V_102 ) ;
F_161 ( V_14 , V_338 -> V_35 ) ;
F_56 ( & V_338 -> V_81 ) ;
F_2 ( V_338 ) ;
return 0 ;
}
return 1 ;
}
static void
F_176 ( struct V_13 * V_14 ,
T_19 * V_311 )
{
struct V_3 * V_7 ;
T_19 * V_370 ;
T_4 V_371 ;
struct V_92 * V_93 ;
unsigned long V_76 ;
int V_106 , V_330 ;
T_4 V_35 ;
for ( V_106 = 0 ; V_106 < V_311 -> V_331 ; V_106 ++ ) {
V_35 = F_21 ( V_311 -> V_332 [ V_106 ] . V_333 ) ;
if ( ! V_35 )
continue;
V_330 = V_311 -> V_332 [ V_106 ] . V_334 &
V_335 ;
if ( V_330 == V_372 )
F_161 ( V_14 , V_35 ) ;
}
V_371 = F_21 ( V_311 -> V_373 ) ;
if ( V_371 < V_14 -> V_39 . V_40 ) {
F_160 ( V_14 , V_311 ) ;
return;
}
if ( V_311 -> V_374 ==
V_375 ) {
F_32 ( & V_14 -> V_94 , V_76 ) ;
V_93 = F_57 ( V_14 ,
V_371 ) ;
F_158 ( V_14 , V_93 ) ;
F_33 ( & V_14 -> V_94 , V_76 ) ;
do {
V_35 = F_177 ( V_14 -> V_327 ,
V_14 -> V_202 . V_376 ) ;
if ( V_35 < V_14 -> V_202 . V_376 )
F_157 ( V_14 , V_35 ) ;
} while ( F_178 ( V_35 , V_14 -> V_327 ) );
} else if ( V_311 -> V_374 == V_377 )
F_160 ( V_14 , V_311 ) ;
if ( V_311 -> V_374 != V_378 )
return;
F_32 ( & V_14 -> V_306 , V_76 ) ;
F_15 (fw_event, &ioc->fw_event_list, list) {
if ( V_7 -> V_312 != V_379 ||
V_7 -> V_380 )
continue;
V_370 = ( T_19 * )
V_7 -> V_311 ;
if ( V_370 -> V_374 ==
V_381 ||
V_370 -> V_374 ==
V_377 ) {
if ( F_21 ( V_370 -> V_373 ) ==
V_371 ) {
F_46 ( V_14 , F_13 ( V_42
L_111 , V_14 -> V_43 ) ) ;
V_7 -> V_380 = 1 ;
}
}
}
F_33 ( & V_14 -> V_306 , V_76 ) ;
}
static void
F_179 ( struct V_13 * V_14 , T_4 V_35 )
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
V_118 -> V_340 = 1 ;
F_46 ( V_14 , F_13 ( V_42
L_112
L_113 , V_14 -> V_43 , V_35 ,
( unsigned long long ) V_56 -> V_60 ) ) ;
}
F_33 ( & V_14 -> V_90 , V_76 ) ;
}
static void
F_180 ( T_4 V_35 , T_4 * V_382 , T_4 * V_383 )
{
if ( ! V_35 || V_35 == * V_382 || V_35 == * V_383 )
return;
if ( ! * V_382 )
* V_382 = V_35 ;
else if ( ! * V_383 )
* V_383 = V_35 ;
}
static void
F_181 ( struct V_13 * V_14 ,
T_23 * V_311 )
{
T_24 * V_384 ;
int V_106 ;
T_4 V_35 , V_208 , V_382 , V_383 ;
struct V_337 * V_338 ;
V_382 = 0 ;
V_383 = 0 ;
if ( V_14 -> V_134 )
return;
V_384 = ( T_24 * ) & V_311 -> V_385 [ 0 ] ;
for ( V_106 = 0 ; V_106 < V_311 -> V_386 ; V_106 ++ , V_384 ++ ) {
if ( F_78 ( V_311 -> V_145 ) &
V_387 )
continue;
if ( V_384 -> V_388 ==
V_389 ||
V_384 -> V_388 ==
V_390 ) {
V_208 = F_21 ( V_384 -> V_391 ) ;
F_179 ( V_14 , V_208 ) ;
F_180 ( V_208 , & V_382 , & V_383 ) ;
}
}
V_384 = ( T_24 * ) & V_311 -> V_385 [ 0 ] ;
for ( V_106 = 0 ; V_106 < V_311 -> V_386 ; V_106 ++ , V_384 ++ ) {
if ( F_78 ( V_311 -> V_145 ) &
V_387 )
continue;
if ( V_384 -> V_388 == V_392 ) {
V_208 = F_21 ( V_384 -> V_391 ) ;
F_180 ( V_208 , & V_382 , & V_383 ) ;
}
}
if ( V_382 )
F_170 ( V_14 , V_382 ) ;
if ( V_383 )
F_170 ( V_14 , V_383 ) ;
V_384 = ( T_24 * ) & V_311 -> V_385 [ 0 ] ;
for ( V_106 = 0 ; V_106 < V_311 -> V_386 ; V_106 ++ , V_384 ++ ) {
if ( V_384 -> V_388 != V_392 )
continue;
V_35 = F_21 ( V_384 -> V_393 ) ;
V_208 = F_21 ( V_384 -> V_391 ) ;
F_182 ( V_35 , V_14 -> V_137 ) ;
if ( ! V_208 )
F_161 ( V_14 , V_35 ) ;
else if ( V_208 == V_382 || V_208 == V_383 ) {
V_338 = F_9 ( sizeof( * V_338 ) , V_8 ) ;
F_183 ( ! V_338 ) ;
F_138 ( & V_338 -> V_81 ) ;
V_338 -> V_35 = V_35 ;
F_47 ( & V_338 -> V_81 , & V_14 -> V_342 ) ;
F_46 ( V_14 , F_13 ( V_42
L_97 , V_14 -> V_43 ,
V_35 ) ) ;
} else
F_161 ( V_14 , V_35 ) ;
}
}
static void
F_184 ( struct V_13 * V_14 ,
T_25 * V_311 )
{
T_10 V_167 ;
if ( V_311 -> V_388 != V_394 )
return;
V_167 = F_78 ( V_311 -> V_395 ) ;
if ( V_167 == V_177 || V_167 ==
V_176 )
F_179 ( V_14 ,
F_21 ( V_311 -> V_391 ) ) ;
}
static void
F_185 ( struct V_13 * V_14 ,
T_26 * V_311 )
{
if ( V_14 -> V_396 >= V_311 -> V_397 ) {
F_25 ( V_42 L_114
L_115 , V_14 -> V_43 ,
( ( F_21 ( V_311 -> V_398 ) & 0x1 ) == 1 ) ? L_116 : L_117 ,
( ( F_21 ( V_311 -> V_398 ) & 0x2 ) == 2 ) ? L_118 : L_117 ,
( ( F_21 ( V_311 -> V_398 ) & 0x4 ) == 4 ) ? L_119 : L_117 ,
( ( F_21 ( V_311 -> V_398 ) & 0x8 ) == 8 ) ? L_120 : L_117 ,
V_311 -> V_397 ) ;
F_25 ( V_42 L_121 ,
V_14 -> V_43 , V_311 -> V_399 ) ;
}
}
static void
F_186 ( struct V_13 * V_14 )
{
struct V_101 * V_104 ;
T_4 V_102 ;
T_4 V_400 = 0 ;
for ( V_102 = 1 ; V_102 <= V_14 -> V_107 ; V_102 ++ ) {
V_104 = F_62 ( V_14 , V_102 ) ;
if ( ! V_104 )
continue;
V_400 ++ ;
F_175 ( V_14 , V_102 ) ;
F_187 ( V_104 ) ;
if ( V_14 -> V_267 )
V_104 -> V_299 = V_300 << 16 ;
else
V_104 -> V_299 = V_302 << 16 ;
V_104 -> V_301 ( V_104 ) ;
}
F_119 ( V_14 , F_13 ( V_42 L_122 ,
V_14 -> V_43 , V_400 ) ) ;
}
static void
F_188 ( struct V_13 * V_14 , struct V_101 * V_104 ,
T_27 * V_257 )
{
T_4 V_401 ;
unsigned char V_402 = F_189 ( V_104 ) ;
unsigned char V_403 = F_190 ( V_104 ) ;
T_28 * V_404 =
( T_28 * ) V_257 ;
if ( V_403 == V_405 || V_402 == V_406 )
return;
if ( V_402 == V_407 )
V_401 = V_408 ;
else if ( V_402 == V_409 )
V_401 = V_410 ;
else
return;
switch ( V_403 ) {
case V_411 :
case V_412 :
V_401 |= V_413 |
V_414 |
V_415 ;
V_257 -> V_416 . V_417 . V_418 =
F_191 ( F_192 ( V_104 ) ) ;
break;
case V_419 :
V_401 |= V_415 ;
break;
}
V_404 -> V_420 =
F_121 ( V_104 -> V_51 -> V_421 ) ;
V_257 -> V_422 = F_121 ( V_401 ) ;
}
static void
F_193 ( struct V_101 * V_104 , T_4 V_38 )
{
T_6 V_423 ;
switch ( V_38 ) {
case V_424 :
V_423 = 0x01 ;
break;
case V_425 :
V_423 = 0x02 ;
break;
case V_426 :
V_423 = 0x03 ;
break;
default:
V_423 = 0x00 ;
break;
}
F_194 ( 0 , V_104 -> V_427 , V_428 , 0x10 ,
V_423 ) ;
V_104 -> V_299 = V_429 << 24 | ( V_430 << 16 ) |
V_431 ;
}
int
F_195 ( struct V_112 * V_113 , struct V_101 * V_104 )
{
struct V_13 * V_14 = F_67 ( V_113 ) ;
struct V_116 * V_117 ;
struct V_72 * V_118 ;
struct V_55 * V_56 ;
T_27 * V_257 ;
T_10 V_432 ;
T_4 V_102 ;
T_4 V_35 ;
if ( V_14 -> V_15 & V_433 )
F_130 ( V_104 ) ;
V_117 = V_104 -> V_51 -> V_120 ;
if ( ! V_117 || ! V_117 -> V_122 ) {
V_104 -> V_299 = V_300 << 16 ;
V_104 -> V_301 ( V_104 ) ;
return 0 ;
}
if ( V_14 -> V_267 || V_14 -> V_266 ) {
V_104 -> V_299 = V_300 << 16 ;
V_104 -> V_301 ( V_104 ) ;
return 0 ;
}
V_118 = V_117 -> V_122 ;
V_35 = V_118 -> V_35 ;
if ( V_35 == V_132 ) {
V_104 -> V_299 = V_300 << 16 ;
V_104 -> V_301 ( V_104 ) ;
return 0 ;
}
if ( V_14 -> V_82 || V_14 -> V_434 )
return V_435 ;
else if ( V_118 -> V_340 ) {
V_104 -> V_299 = V_300 << 16 ;
V_104 -> V_301 ( V_104 ) ;
return 0 ;
} else if ( V_118 -> V_251 ||
V_117 -> V_317 )
return V_436 ;
if ( V_104 -> V_437 == V_438 )
V_432 = V_439 ;
else if ( V_104 -> V_437 == V_440 )
V_432 = V_441 ;
else
V_432 = V_442 ;
V_432 |= V_443 ;
if ( ! V_14 -> V_134 && ! F_79 ( & V_104 -> V_51 -> V_191 )
&& F_96 ( V_104 -> V_51 ) && V_104 -> V_444 != 32 )
V_432 |= V_445 ;
V_102 = F_196 ( V_14 , V_14 -> V_446 , V_104 ) ;
if ( ! V_102 ) {
F_25 ( V_42 L_51 ,
V_14 -> V_43 , V_44 ) ;
goto V_89;
}
V_257 = F_120 ( V_14 , V_102 ) ;
memset ( V_257 , 0 , sizeof( T_27 ) ) ;
F_188 ( V_14 , V_104 , V_257 ) ;
if ( V_104 -> V_444 == 32 )
V_432 |= 4 << V_447 ;
V_257 -> V_277 = V_448 ;
if ( V_117 -> V_122 -> V_76 &
V_138 )
V_257 -> V_277 = V_449 ;
else
V_257 -> V_277 = V_448 ;
V_257 -> V_200 = F_121 ( V_35 ) ;
V_257 -> V_450 = F_197 ( F_198 ( V_104 ) ) ;
V_257 -> V_451 = F_197 ( V_432 ) ;
V_257 -> V_452 = F_121 ( V_104 -> V_444 ) ;
V_257 -> V_453 = V_454 ;
V_257 -> V_455 = V_456 ;
V_257 -> V_457 =
F_199 ( V_14 , V_102 ) ;
V_257 -> V_458 = F_92 ( T_27 , V_459 ) / 4 ;
F_122 ( V_117 -> V_109 , (struct V_281 * )
V_257 -> V_282 ) ;
memcpy ( V_257 -> V_416 . V_460 , V_104 -> V_461 , V_104 -> V_444 ) ;
if ( V_257 -> V_450 ) {
if ( V_14 -> V_462 ( V_14 , V_104 , V_102 ) ) {
F_175 ( V_14 , V_102 ) ;
goto V_89;
}
} else
V_14 -> V_463 ( V_14 , & V_257 -> V_459 ) ;
V_56 = V_118 -> V_56 ;
if ( V_56 && V_56 -> V_464 )
F_200 ( V_14 , V_104 , V_56 , V_257 ,
V_102 ) ;
if ( F_168 ( V_257 -> V_277 == V_448 ) ) {
if ( V_118 -> V_76 & V_140 ) {
V_257 -> V_452 = F_121 ( V_104 -> V_444 |
V_465 ) ;
F_201 ( V_14 , V_102 , V_35 ) ;
} else
F_202 ( V_14 , V_102 ,
F_21 ( V_257 -> V_200 ) ) ;
} else
F_166 ( V_14 , V_102 ) ;
return 0 ;
V_89:
return V_435 ;
}
static void
F_203 ( char * V_427 , struct V_466 * V_467 )
{
if ( ( V_427 [ 0 ] & 0x7F ) >= 0x72 ) {
V_467 -> V_468 = V_427 [ 1 ] & 0x0F ;
V_467 -> V_469 = V_427 [ 2 ] ;
V_467 -> V_423 = V_427 [ 3 ] ;
} else {
V_467 -> V_468 = V_427 [ 2 ] & 0x0F ;
V_467 -> V_469 = V_427 [ 12 ] ;
V_467 -> V_423 = V_427 [ 13 ] ;
}
}
static void
F_204 ( struct V_13 * V_14 , struct V_101 * V_104 ,
T_29 * V_37 , T_4 V_102 )
{
T_10 V_470 ;
T_6 * V_471 ;
T_4 V_38 = F_21 ( V_37 -> V_46 ) &
V_47 ;
T_6 V_472 = V_37 -> V_473 ;
T_6 V_474 = V_37 -> V_475 ;
char * V_476 = NULL ;
char * V_477 = NULL ;
char * V_478 = V_14 -> V_479 ;
T_10 V_480 = F_78 ( V_37 -> V_288 ) ;
struct V_53 * V_54 = NULL ;
struct V_126 * V_85 = V_104 -> V_51 -> V_296 ;
struct V_72 * V_297 = V_85 -> V_120 ;
char * V_298 = NULL ;
if ( ! V_297 )
return;
if ( V_14 -> V_218 )
V_298 = L_56 ;
else
V_298 = L_57 ;
if ( V_480 == 0x31170000 )
return;
switch ( V_38 ) {
case V_48 :
V_476 = L_123 ;
break;
case V_481 :
V_476 = L_124 ;
break;
case V_482 :
V_476 = L_125 ;
break;
case V_483 :
V_476 = L_126 ;
break;
case V_484 :
V_476 = L_127 ;
break;
case V_485 :
V_476 = L_128 ;
break;
case V_486 :
V_476 = L_129 ;
break;
case V_487 :
V_476 = L_130 ;
break;
case V_488 :
V_476 = L_131 ;
break;
case V_489 :
V_476 = L_132 ;
break;
case V_490 :
V_476 = L_133 ;
break;
case V_491 :
V_476 = L_134 ;
break;
case V_492 :
V_476 = L_135 ;
break;
case V_493 :
V_476 = L_136 ;
break;
case V_424 :
V_476 = L_137 ;
break;
case V_426 :
V_476 = L_138 ;
break;
case V_425 :
V_476 = L_139 ;
break;
case V_494 :
V_476 = L_140 ;
break;
default:
V_476 = L_46 ;
break;
}
switch ( V_474 ) {
case V_495 :
V_477 = L_141 ;
break;
case V_496 :
V_477 = L_142 ;
break;
case V_497 :
V_477 = L_143 ;
break;
case V_498 :
V_477 = L_144 ;
break;
case V_499 :
V_477 = L_145 ;
break;
case V_500 :
V_477 = L_146 ;
break;
case V_501 :
V_477 = L_147 ;
break;
case V_502 :
V_477 = L_148 ;
break;
case V_503 :
V_477 = L_149 ;
break;
case V_504 :
V_477 = L_150 ;
break;
case V_505 :
V_477 = L_151 ;
break;
default:
V_477 = L_46 ;
break;
}
V_478 [ 0 ] = '\0' ;
if ( ! V_472 )
V_478 = L_117 ;
if ( V_472 & V_506 )
strcat ( V_478 , L_152 ) ;
if ( V_472 & V_507 )
strcat ( V_478 , L_153 ) ;
if ( V_472 & V_508 )
strcat ( V_478 , L_154 ) ;
if ( V_472 & V_509 )
strcat ( V_478 , L_155 ) ;
if ( V_472 & V_510 )
strcat ( V_478 , L_156 ) ;
F_130 ( V_104 ) ;
if ( V_297 -> V_76 & V_123 ) {
F_91 ( V_42 L_157 , V_14 -> V_43 ,
V_298 , ( unsigned long long ) V_297 -> V_17 ) ;
} else {
V_54 = F_31 ( V_14 , V_297 ) ;
if ( V_54 ) {
F_91 ( V_42
L_158 ,
V_14 -> V_43 , ( unsigned long long )
V_54 -> V_17 , V_54 -> V_222 ) ;
if ( V_54 -> V_78 != 0 )
F_91 ( V_42
L_159
L_160 , V_14 -> V_43 ,
( unsigned long long )
V_54 -> V_22 ,
V_54 -> V_26 ) ;
if ( V_54 -> V_79 [ 0 ] )
F_91 ( V_42
L_161
L_96 , V_14 -> V_43 ,
V_54 -> V_80 ,
V_54 -> V_79 ) ;
F_41 ( V_54 ) ;
}
}
F_91 ( V_42
L_162 ,
V_14 -> V_43 , F_21 ( V_37 -> V_200 ) ,
V_476 , V_38 , V_102 ) ;
F_91 ( V_42
L_163 ,
V_14 -> V_43 , F_198 ( V_104 ) , V_104 -> V_511 ,
F_205 ( V_104 ) ) ;
F_91 ( V_42
L_164 ,
V_14 -> V_43 , F_21 ( V_37 -> V_512 ) ,
F_78 ( V_37 -> V_513 ) , V_104 -> V_299 ) ;
F_91 ( V_42
L_165 ,
V_14 -> V_43 , V_477 ,
V_474 , V_478 , V_472 ) ;
if ( V_472 & V_510 ) {
struct V_466 V_467 ;
F_203 ( V_104 -> V_427 , & V_467 ) ;
F_91 ( V_42
L_166 ,
V_14 -> V_43 , V_467 . V_468 ,
V_467 . V_469 , V_467 . V_423 , F_78 ( V_37 -> V_514 ) ) ;
}
if ( V_472 & V_506 ) {
V_470 = F_78 ( V_37 -> V_515 ) ;
V_471 = ( T_6 * ) & V_470 ;
F_104 ( V_14 , V_471 [ 0 ] ) ;
}
}
static void
F_206 ( struct V_13 * V_14 , T_4 V_35 )
{
T_30 V_37 ;
T_31 V_257 ;
struct V_53 * V_54 ;
V_54 = F_37 ( V_14 , V_35 ) ;
if ( ! V_54 )
return;
memset ( & V_257 , 0 , sizeof( T_31 ) ) ;
V_257 . V_277 = V_516 ;
V_257 . V_517 = V_518 ;
V_257 . V_519 =
F_197 ( V_520 ) ;
V_257 . V_200 = F_121 ( V_35 ) ;
V_257 . V_145 = V_521 ;
if ( ( F_207 ( V_14 , & V_37 ,
& V_257 ) ) != 0 ) {
F_25 ( V_42 L_2 , V_14 -> V_43 ,
__FILE__ , __LINE__ , V_44 ) ;
goto V_89;
}
V_54 -> V_522 = 1 ;
if ( V_37 . V_46 || V_37 . V_288 ) {
F_46 ( V_14 , F_13 ( V_42
L_167 ,
V_14 -> V_43 , F_21 ( V_37 . V_46 ) ,
F_78 ( V_37 . V_288 ) ) ) ;
goto V_89;
}
V_89:
F_41 ( V_54 ) ;
}
static void
F_208 ( struct V_13 * V_14 ,
struct V_53 * V_54 )
{
T_30 V_37 ;
T_31 V_257 ;
memset ( & V_257 , 0 , sizeof( T_31 ) ) ;
V_257 . V_277 = V_516 ;
V_257 . V_517 = V_518 ;
V_257 . V_519 = 0 ;
V_257 . V_523 = F_121 ( V_54 -> V_26 ) ;
V_257 . V_200 = 0 ;
V_257 . V_524 = F_121 ( V_54 -> V_78 ) ;
V_257 . V_145 = V_525 ;
if ( ( F_207 ( V_14 , & V_37 ,
& V_257 ) ) != 0 ) {
F_209 ( V_42 L_2 , V_14 -> V_43 ,
__FILE__ , __LINE__ , V_44 ) ;
return;
}
if ( V_37 . V_46 || V_37 . V_288 ) {
F_46 ( V_14 , F_209 ( V_42
L_167 ,
V_14 -> V_43 , F_21 ( V_37 . V_46 ) ,
F_78 ( V_37 . V_288 ) ) ) ;
return;
}
}
static void
F_210 ( struct V_13 * V_14 , T_4 V_35 )
{
struct V_3 * V_7 ;
V_7 = F_8 ( 0 ) ;
if ( ! V_7 )
return;
V_7 -> V_312 = V_526 ;
V_7 -> V_527 = V_35 ;
V_7 -> V_14 = V_14 ;
F_137 ( V_14 , V_7 ) ;
F_6 ( V_7 ) ;
}
static void
F_211 ( struct V_13 * V_14 , T_4 V_35 )
{
struct V_126 * V_85 ;
struct V_72 * V_118 ;
T_32 * V_528 ;
T_33 * V_311 ;
struct V_53 * V_54 ;
T_34 V_193 ;
unsigned long V_76 ;
F_32 ( & V_14 -> V_74 , V_76 ) ;
V_54 = F_36 ( V_14 , V_35 ) ;
if ( ! V_54 )
goto V_529;
V_85 = V_54 -> V_85 ;
V_118 = V_85 -> V_120 ;
if ( ( V_118 -> V_76 & V_138 ) ||
( ( V_118 -> V_76 & V_123 ) ) )
goto V_529;
if ( V_54 -> V_78 != 0 )
F_131 ( V_144 , V_85 , L_168
L_169 ,
( unsigned long long ) V_54 -> V_22 ,
V_54 -> V_26 ) ;
if ( V_54 -> V_79 [ 0 ] != '\0' )
F_131 ( V_220 , V_85 , L_168
L_170 ,
V_54 -> V_80 ,
V_54 -> V_79 ) ;
F_33 ( & V_14 -> V_74 , V_76 ) ;
if ( V_14 -> V_530 -> V_531 == V_532 )
F_210 ( V_14 , V_35 ) ;
V_193 = F_92 ( T_32 , V_533 ) +
sizeof( T_33 ) ;
V_528 = F_9 ( V_193 , V_130 ) ;
if ( ! V_528 ) {
F_25 ( V_42 L_2 ,
V_14 -> V_43 , __FILE__ , __LINE__ , V_44 ) ;
goto V_89;
}
V_528 -> V_277 = V_534 ;
V_528 -> V_362 =
F_121 ( V_535 ) ;
V_528 -> V_246 = V_193 / 4 ;
V_528 -> V_536 =
F_121 ( sizeof( T_33 ) / 4 ) ;
V_311 = ( T_33 * )
V_528 -> V_533 ;
V_311 -> V_388 = V_537 ;
V_311 -> V_538 = 0x5D ;
V_311 -> V_200 = F_121 ( V_35 ) ;
V_311 -> V_19 = F_212 ( V_118 -> V_17 ) ;
F_213 ( V_14 , V_528 ) ;
F_2 ( V_528 ) ;
V_89:
if ( V_54 )
F_41 ( V_54 ) ;
return;
V_529:
F_33 ( & V_14 -> V_74 , V_76 ) ;
goto V_89;
}
static T_6
F_214 ( struct V_13 * V_14 , T_4 V_102 , T_6 V_240 , T_10 V_241 )
{
T_27 * V_257 ;
T_29 * V_37 ;
struct V_101 * V_104 ;
T_4 V_38 ;
T_10 V_539 ;
T_6 V_472 ;
T_6 V_474 ;
T_10 V_480 ;
struct V_116 * V_117 ;
T_10 V_231 = 0 ;
unsigned long V_76 ;
V_37 = F_107 ( V_14 , V_241 ) ;
V_104 = F_62 ( V_14 , V_102 ) ;
if ( V_104 == NULL )
return 1 ;
V_257 = F_120 ( V_14 , V_102 ) ;
if ( V_37 == NULL ) {
V_104 -> V_299 = V_540 << 16 ;
goto V_89;
}
V_117 = V_104 -> V_51 -> V_120 ;
if ( ! V_117 || ! V_117 -> V_122 ||
V_117 -> V_122 -> V_340 ) {
V_104 -> V_299 = V_300 << 16 ;
goto V_89;
}
V_38 = F_21 ( V_37 -> V_46 ) ;
if ( F_215 ( V_14 , V_102 ) &&
( ( V_38 & V_47 )
!= V_489 ) ) {
F_32 ( & V_14 -> V_105 , V_76 ) ;
V_14 -> V_103 [ V_102 - 1 ] . V_104 = V_104 ;
F_33 ( & V_14 -> V_105 , V_76 ) ;
F_216 ( V_14 , V_102 , 0 ) ;
memcpy ( V_257 -> V_416 . V_460 , V_104 -> V_461 , V_104 -> V_444 ) ;
V_257 -> V_200 =
F_121 ( V_117 -> V_122 -> V_35 ) ;
F_202 ( V_14 , V_102 ,
V_117 -> V_122 -> V_35 ) ;
return 0 ;
}
V_472 = V_37 -> V_473 ;
if ( V_472 & V_506 )
V_231 =
F_78 ( V_37 -> V_515 ) & 0xFF ;
if ( ! V_117 -> V_541 ) {
V_117 -> V_541 ++ ;
if ( ! V_14 -> V_134 &&
! F_79 ( & V_104 -> V_51 -> V_191 ) &&
F_96 ( V_104 -> V_51 ) &&
V_231 == V_234 ) {
F_217 ( V_104 -> V_51 ) ;
F_75 ( V_144 , V_104 -> V_51 , L_171 ) ;
}
}
V_539 = F_78 ( V_37 -> V_513 ) ;
F_218 ( V_104 , F_198 ( V_104 ) - V_539 ) ;
if ( V_38 & V_542 )
V_480 = F_78 ( V_37 -> V_288 ) ;
else
V_480 = 0 ;
V_38 &= V_47 ;
V_474 = V_37 -> V_475 ;
if ( V_38 == V_486 && V_539 == 0 &&
( V_474 == V_498 ||
V_474 == V_501 ||
V_474 == V_503 ) ) {
V_38 = V_48 ;
}
if ( V_472 & V_510 ) {
struct V_466 V_467 ;
const void * V_543 = F_219 ( V_14 ,
V_102 ) ;
T_10 V_193 = F_220 ( T_10 , V_456 ,
F_78 ( V_37 -> V_514 ) ) ;
memcpy ( V_104 -> V_427 , V_543 , V_193 ) ;
F_203 ( V_104 -> V_427 , & V_467 ) ;
if ( V_467 . V_469 == 0x5D )
F_211 ( V_14 ,
F_21 ( V_37 -> V_200 ) ) ;
F_221 ( V_14 , V_467 . V_468 , V_467 . V_469 , V_467 . V_423 ) ;
if ( ! ( V_14 -> V_15 & V_544 ) &&
( ( V_104 -> V_427 [ 2 ] == V_545 ) ||
( V_104 -> V_427 [ 2 ] == V_546 ) ||
( V_104 -> V_427 [ 2 ] == V_547 ) ) )
F_204 ( V_14 , V_104 , V_37 , V_102 ) ;
}
switch ( V_38 ) {
case V_548 :
case V_549 :
V_104 -> V_299 = V_550 ;
break;
case V_484 :
V_104 -> V_299 = V_300 << 16 ;
break;
case V_492 :
if ( V_117 -> V_317 ) {
V_104 -> V_299 = V_551 << 16 ;
goto V_89;
}
if ( V_480 == 0x31110630 ) {
if ( V_104 -> V_552 > 2 ) {
V_104 -> V_299 = V_300 << 16 ;
F_222 ( V_104 -> V_51 ,
V_553 ) ;
} else {
V_104 -> V_299 = V_554 << 16 ;
V_104 -> V_51 -> V_555 = 1 ;
}
break;
} else if ( V_480 == V_556 ) {
V_104 -> V_299 = V_302 << 16 ;
break;
}
V_104 -> V_299 = V_554 << 16 ;
break;
case V_489 :
case V_493 :
V_104 -> V_299 = V_302 << 16 ;
break;
case V_490 :
if ( ( V_539 == 0 ) || ( V_104 -> V_511 > V_539 ) )
V_104 -> V_299 = V_554 << 16 ;
else
V_104 -> V_299 = ( V_540 << 16 ) | V_474 ;
break;
case V_486 :
V_104 -> V_299 = ( V_540 << 16 ) | V_474 ;
if ( ( V_472 & V_510 ) )
break;
if ( V_539 < V_104 -> V_511 ) {
if ( V_474 == V_550 )
V_104 -> V_299 = V_550 ;
else
V_104 -> V_299 = V_554 << 16 ;
} else if ( V_472 & ( V_509 |
V_508 ) )
V_104 -> V_299 = V_554 << 16 ;
else if ( V_472 & V_507 )
V_104 -> V_299 = V_302 << 16 ;
else if ( ! V_539 && V_104 -> V_461 [ 0 ] == V_557 ) {
V_37 -> V_473 = V_510 ;
V_37 -> V_475 = V_431 ;
V_104 -> V_299 = ( V_429 << 24 ) |
V_431 ;
V_104 -> V_427 [ 0 ] = 0x70 ;
V_104 -> V_427 [ 2 ] = V_428 ;
V_104 -> V_427 [ 12 ] = 0x20 ;
V_104 -> V_427 [ 13 ] = 0 ;
}
break;
case V_485 :
F_218 ( V_104 , 0 ) ;
case V_482 :
case V_48 :
V_104 -> V_299 = ( V_540 << 16 ) | V_474 ;
if ( V_231 ==
V_234 ||
( V_472 & ( V_509 |
V_508 ) ) )
V_104 -> V_299 = V_554 << 16 ;
else if ( V_472 & V_507 )
V_104 -> V_299 = V_302 << 16 ;
break;
case V_424 :
case V_426 :
case V_425 :
F_193 ( V_104 , V_38 ) ;
break;
case V_488 :
case V_481 :
case V_558 :
case V_559 :
case V_560 :
case V_561 :
case V_487 :
case V_491 :
case V_494 :
default:
V_104 -> V_299 = V_554 << 16 ;
break;
}
if ( V_104 -> V_299 && ( V_14 -> V_15 & V_544 ) )
F_204 ( V_14 , V_104 , V_37 , V_102 ) ;
V_89:
F_187 ( V_104 ) ;
V_104 -> V_301 ( V_104 ) ;
return 1 ;
}
static void
F_223 ( struct V_13 * V_14 )
{
T_4 V_193 ;
T_4 V_38 ;
int V_106 ;
T_9 V_37 ;
T_35 * V_562 = NULL ;
T_4 V_563 ;
T_6 V_564 ;
F_119 ( V_14 , F_13 ( V_42
L_172 ,
V_14 -> V_43 , ( unsigned long long ) V_14 -> V_39 . V_17 ) ) ;
V_193 = F_92 ( T_35 , V_565 ) + ( V_14 -> V_39 . V_40
* sizeof( V_566 ) ) ;
V_562 = F_9 ( V_193 , V_130 ) ;
if ( ! V_562 ) {
F_25 ( V_42 L_2 ,
V_14 -> V_43 , __FILE__ , __LINE__ , V_44 ) ;
return;
}
if ( ( F_224 ( V_14 , & V_37 ,
V_562 , V_193 ) ) != 0 )
goto V_89;
V_38 = F_21 ( V_37 . V_46 ) & V_47 ;
if ( V_38 != V_48 )
goto V_89;
for ( V_106 = 0 ; V_106 < V_14 -> V_39 . V_40 ; V_106 ++ ) {
V_564 = V_562 -> V_565 [ V_106 ] . V_567 >> 4 ;
if ( V_106 == 0 )
V_14 -> V_39 . V_35 = F_21 ( V_562 ->
V_565 [ 0 ] . V_568 ) ;
V_14 -> V_39 . V_222 [ V_106 ] . V_35 = V_14 -> V_39 . V_35 ;
V_563 = F_21 ( V_562 -> V_565 [ V_106 ] .
V_333 ) ;
if ( V_563 && V_564 < V_569 )
V_564 = V_569 ;
F_225 ( V_14 , V_14 -> V_39 . V_17 ,
V_563 , V_106 , V_564 ) ;
}
V_89:
F_2 ( V_562 ) ;
}
static void
F_226 ( struct V_13 * V_14 )
{
int V_106 ;
T_9 V_37 ;
T_35 * V_562 = NULL ;
T_36 * V_570 = NULL ;
T_37 V_571 ;
T_8 V_36 ;
T_38 V_572 ;
T_4 V_38 ;
T_4 V_193 ;
T_6 V_573 ;
F_227 ( V_14 , & V_14 -> V_39 . V_40 ) ;
if ( ! V_14 -> V_39 . V_40 ) {
F_25 ( V_42 L_2 ,
V_14 -> V_43 , __FILE__ , __LINE__ , V_44 ) ;
return;
}
V_193 = F_92 ( T_35 , V_565 ) + ( V_14 -> V_39 . V_40 *
sizeof( V_566 ) ) ;
V_562 = F_9 ( V_193 , V_130 ) ;
if ( ! V_562 ) {
F_25 ( V_42 L_2 ,
V_14 -> V_43 , __FILE__ , __LINE__ , V_44 ) ;
return;
}
if ( ( F_224 ( V_14 , & V_37 ,
V_562 , V_193 ) ) ) {
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
V_193 = F_92 ( T_36 , V_565 ) + ( V_14 -> V_39 . V_40 *
sizeof( V_574 ) ) ;
V_570 = F_9 ( V_193 , V_130 ) ;
if ( ! V_570 ) {
F_25 ( V_42 L_2 ,
V_14 -> V_43 , __FILE__ , __LINE__ , V_44 ) ;
goto V_89;
}
if ( ( F_228 ( V_14 , & V_37 ,
V_570 , V_193 ) ) ) {
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
V_14 -> V_575 =
V_570 -> V_576 ;
V_573 =
V_570 -> V_577 ;
if ( V_573 & V_578 )
V_14 -> V_573 = ( V_573 &
V_579 ) * 16 ;
else
V_14 -> V_573 = V_573 &
V_579 ;
V_14 -> V_39 . V_580 = & V_14 -> V_113 -> V_581 ;
V_14 -> V_39 . V_222 = F_229 ( V_14 -> V_39 . V_40 ,
sizeof( struct V_582 ) , V_130 ) ;
if ( ! V_14 -> V_39 . V_222 ) {
F_25 ( V_42 L_2 ,
V_14 -> V_43 , __FILE__ , __LINE__ , V_44 ) ;
goto V_89;
}
for ( V_106 = 0 ; V_106 < V_14 -> V_39 . V_40 ; V_106 ++ ) {
if ( ( F_230 ( V_14 , & V_37 , & V_571 ,
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
V_14 -> V_39 . V_35 = F_21 ( V_562 ->
V_565 [ 0 ] . V_568 ) ;
V_14 -> V_39 . V_222 [ V_106 ] . V_35 = V_14 -> V_39 . V_35 ;
V_14 -> V_39 . V_222 [ V_106 ] . V_583 = V_106 ;
F_231 ( V_14 , & V_14 -> V_39 . V_222 [ V_106 ] ,
V_571 , V_14 -> V_39 . V_580 ) ;
}
if ( ( F_24 ( V_14 , & V_37 , & V_36 ,
V_41 , V_14 -> V_39 . V_35 ) ) ) {
F_25 ( V_42 L_2 ,
V_14 -> V_43 , __FILE__ , __LINE__ , V_44 ) ;
goto V_89;
}
V_14 -> V_39 . V_78 =
F_21 ( V_36 . V_524 ) ;
V_14 -> V_39 . V_17 = F_18 ( V_36 . V_19 ) ;
F_13 ( V_42
L_173 ,
V_14 -> V_43 , V_14 -> V_39 . V_35 ,
( unsigned long long ) V_14 -> V_39 . V_17 ,
V_14 -> V_39 . V_40 ) ;
if ( V_14 -> V_39 . V_78 ) {
if ( ! ( F_232 ( V_14 , & V_37 ,
& V_572 , V_584 ,
V_14 -> V_39 . V_78 ) ) )
V_14 -> V_39 . V_22 =
F_18 ( V_572 . V_24 ) ;
}
V_89:
F_2 ( V_570 ) ;
F_2 ( V_562 ) ;
}
static int
F_233 ( struct V_13 * V_14 , T_4 V_35 )
{
struct V_92 * V_93 ;
T_9 V_37 ;
T_39 V_585 ;
T_40 V_586 ;
T_38 V_572 ;
T_10 V_38 ;
T_4 V_587 ;
T_1 V_17 , V_84 = 0 ;
int V_106 ;
unsigned long V_76 ;
struct V_321 * V_322 = NULL ;
int V_28 = 0 ;
if ( ! V_35 )
return - 1 ;
if ( V_14 -> V_82 || V_14 -> V_267 )
return - 1 ;
if ( ( F_234 ( V_14 , & V_37 , & V_585 ,
V_588 , V_35 ) ) ) {
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
V_587 = F_21 ( V_585 . V_589 ) ;
if ( F_23 ( V_14 , V_587 , & V_84 )
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
V_28 = F_233 ( V_14 , V_587 ) ;
if ( V_28 != 0 )
return V_28 ;
}
}
F_32 ( & V_14 -> V_94 , V_76 ) ;
V_17 = F_18 ( V_585 . V_19 ) ;
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
V_93 -> V_40 = V_585 . V_590 ;
V_93 -> V_84 = V_84 ;
V_93 -> V_17 = V_17 ;
F_13 ( V_42 L_174 \
L_175 , V_14 -> V_43 ,
V_35 , V_587 , ( unsigned long long )
V_93 -> V_17 , V_93 -> V_40 ) ;
if ( ! V_93 -> V_40 )
goto V_591;
V_93 -> V_222 = F_229 ( V_93 -> V_40 ,
sizeof( struct V_582 ) , V_130 ) ;
if ( ! V_93 -> V_222 ) {
F_25 ( V_42 L_2 ,
V_14 -> V_43 , __FILE__ , __LINE__ , V_44 ) ;
V_28 = - 1 ;
goto V_591;
}
F_138 ( & V_93 -> V_592 ) ;
V_322 = F_48 ( V_14 , V_35 ,
V_84 ) ;
if ( ! V_322 ) {
F_25 ( V_42 L_2 ,
V_14 -> V_43 , __FILE__ , __LINE__ , V_44 ) ;
V_28 = - 1 ;
goto V_591;
}
V_93 -> V_580 = & V_322 -> V_129 -> V_127 ;
for ( V_106 = 0 ; V_106 < V_93 -> V_40 ; V_106 ++ ) {
if ( ( F_235 ( V_14 , & V_37 ,
& V_586 , V_106 , V_35 ) ) ) {
F_25 ( V_42 L_2 ,
V_14 -> V_43 , __FILE__ , __LINE__ , V_44 ) ;
V_28 = - 1 ;
goto V_591;
}
V_93 -> V_222 [ V_106 ] . V_35 = V_35 ;
V_93 -> V_222 [ V_106 ] . V_583 = V_106 ;
if ( ( F_236 ( V_14 ,
& V_93 -> V_222 [ V_106 ] , V_586 ,
V_93 -> V_580 ) ) ) {
F_25 ( V_42 L_2 ,
V_14 -> V_43 , __FILE__ , __LINE__ , V_44 ) ;
V_28 = - 1 ;
goto V_591;
}
}
if ( V_93 -> V_78 ) {
if ( ! ( F_232 ( V_14 , & V_37 ,
& V_572 , V_584 ,
V_93 -> V_78 ) ) )
V_93 -> V_22 =
F_18 ( V_572 . V_24 ) ;
}
F_59 ( V_14 , V_93 ) ;
return 0 ;
V_591:
if ( V_322 )
F_49 ( V_14 , V_93 -> V_17 ,
V_84 ) ;
F_2 ( V_93 ) ;
return V_28 ;
}
void
F_237 ( struct V_13 * V_14 , T_1 V_17 )
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
F_238 ( V_14 , V_93 ) ;
}
static T_6
F_239 ( struct V_13 * V_14 , T_4 V_102 , T_6 V_240 , T_10 V_241 )
{
T_15 * V_37 ;
V_37 = F_107 ( V_14 , V_241 ) ;
if ( V_14 -> V_593 . V_243 == V_244 )
return 1 ;
if ( V_14 -> V_593 . V_102 != V_102 )
return 1 ;
V_14 -> V_593 . V_243 |= V_245 ;
if ( V_37 ) {
memcpy ( V_14 -> V_593 . V_241 , V_37 ,
V_37 -> V_246 * 4 ) ;
V_14 -> V_593 . V_243 |= V_247 ;
}
V_14 -> V_593 . V_243 &= ~ V_248 ;
F_108 ( & V_14 -> V_593 . V_249 ) ;
return 1 ;
}
static T_6
F_240 ( struct V_13 * V_14 , T_1 V_17 ,
T_4 V_35 , T_6 V_594 )
{
T_6 V_28 = 1 ;
char * V_232 = NULL ;
switch ( V_594 ) {
case V_595 :
case V_596 :
V_28 = 0 ;
break;
case V_597 :
V_232 = L_176 ;
break;
case V_598 :
V_232 = L_177 ;
break;
case V_599 :
V_232 = L_178 ;
break;
case V_600 :
V_232 = L_179 ;
break;
case V_601 :
V_232 = L_180 ;
break;
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
case V_612 :
case V_613 :
V_232 = L_181 ;
break;
default:
V_232 = L_46 ;
break;
}
if ( ! V_28 )
return 0 ;
F_25 ( V_42
L_182 ,
V_14 -> V_43 , V_232 , ( unsigned long long ) V_17 , V_35 ) ;
return V_28 ;
}
static void
F_241 ( struct V_13 * V_14 ,
T_1 V_614 , T_4 V_35 , T_6 V_615 , T_6 V_564 )
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
if ( V_615 != V_36 . V_616 )
return;
V_96 = F_78 ( V_36 . V_146 ) ;
if ( ! ( F_60 ( V_96 ) ) )
return;
F_32 ( & V_14 -> V_74 , V_76 ) ;
V_17 = F_18 ( V_36 . V_19 ) ;
V_54 = F_34 ( V_14 ,
V_17 ) ;
if ( ! V_54 )
goto V_529;
if ( F_163 ( V_54 -> V_35 != V_35 ) ) {
V_85 = V_54 -> V_85 ;
V_118 = V_85 -> V_120 ;
F_131 ( V_144 , V_85 ,
L_183 ,
V_54 -> V_35 , V_35 ) ;
V_118 -> V_35 = V_35 ;
V_54 -> V_35 = V_35 ;
if ( V_36 . V_145 &
V_617 ) {
V_54 -> V_80 =
F_21 ( V_36 . V_618 ) ;
memcpy ( & V_54 -> V_79 [ 0 ] ,
& V_36 . V_619 [ 0 ] , 4 ) ;
} else {
V_54 -> V_80 = 0 ;
V_54 -> V_79 [ 0 ] = '\0' ;
}
}
if ( ! ( F_21 ( V_36 . V_145 ) &
V_620 ) ) {
F_25 ( V_42
L_184 ,
V_14 -> V_43 , V_35 ) ;
goto V_529;
}
if ( F_240 ( V_14 , V_17 , V_35 ,
V_36 . V_621 ) )
goto V_529;
F_33 ( & V_14 -> V_74 , V_76 ) ;
F_155 ( V_14 , V_17 ) ;
if ( V_54 )
F_41 ( V_54 ) ;
return;
V_529:
F_33 ( & V_14 -> V_74 , V_76 ) ;
if ( V_54 )
F_41 ( V_54 ) ;
}
static int
F_242 ( struct V_13 * V_14 , T_4 V_35 , T_6 V_622 ,
T_6 V_623 )
{
T_9 V_37 ;
T_8 V_36 ;
T_38 V_572 ;
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
V_620 ) ) {
F_25 ( V_42 L_185 ,
V_14 -> V_43 , V_35 ) ;
return - 1 ;
}
if ( F_240 ( V_14 , V_17 , V_35 ,
V_36 . V_621 ) )
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
F_21 ( V_36 . V_589 ) ,
& V_54 -> V_84 ) != 0 )
F_25 ( V_42 L_2 ,
V_14 -> V_43 , __FILE__ , __LINE__ , V_44 ) ;
V_54 -> V_78 =
F_21 ( V_36 . V_524 ) ;
if ( V_54 -> V_78 != 0 )
V_54 -> V_26 =
F_21 ( V_36 . V_523 ) ;
V_54 -> V_96 = V_96 ;
V_54 -> V_17 = V_17 ;
V_54 -> V_222 = V_36 . V_616 ;
V_54 -> V_139 = ( F_21 ( V_36 . V_145 ) &
V_624 ) ? 1 : 0 ;
if ( V_36 . V_145 & V_617 ) {
V_54 -> V_80 =
F_21 ( V_36 . V_618 ) ;
memcpy ( & V_54 -> V_79 [ 0 ] ,
& V_36 . V_619 [ 0 ] , 4 ) ;
} else {
V_54 -> V_80 = 0 ;
V_54 -> V_79 [ 0 ] = '\0' ;
}
if ( V_54 -> V_78 && ! ( F_232 (
V_14 , & V_37 , & V_572 , V_584 ,
V_54 -> V_78 ) ) )
V_54 -> V_22 =
F_18 ( V_572 . V_24 ) ;
V_54 -> V_20 = F_18 ( V_36 . V_21 ) ;
if ( V_14 -> V_625 )
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
if ( ( V_14 -> V_530 -> V_531 == V_532 ) &&
( V_54 -> V_522 ) ) {
F_208 ( V_14 , V_54 ) ;
V_54 -> V_522 = 0 ;
}
F_46 ( V_14 , F_13 ( V_42
L_186 ,
V_14 -> V_43 , V_44 ,
V_54 -> V_35 , ( unsigned long long )
V_54 -> V_17 ) ) ;
if ( V_54 -> V_78 != 0 )
F_46 ( V_14 , F_13 ( V_42
L_187 ,
V_14 -> V_43 , V_44 ,
( unsigned long long ) V_54 -> V_22 ,
V_54 -> V_26 ) ) ;
if ( V_54 -> V_79 [ 0 ] != '\0' )
F_46 ( V_14 , F_13 ( V_42
L_188 ,
V_14 -> V_43 , V_44 ,
V_54 -> V_80 ,
V_54 -> V_79 ) ) ;
if ( V_54 -> V_85 && V_54 -> V_85 -> V_120 ) {
V_118 = V_54 -> V_85 -> V_120 ;
V_118 -> V_340 = 1 ;
F_155 ( V_14 , V_54 -> V_17 ) ;
V_118 -> V_35 =
V_132 ;
}
if ( ! V_14 -> V_626 )
F_49 ( V_14 ,
V_54 -> V_17 ,
V_54 -> V_84 ) ;
F_13 ( V_42
L_7 ,
V_14 -> V_43 , V_54 -> V_35 ,
( unsigned long long ) V_54 -> V_17 ) ;
if ( V_54 -> V_78 != 0 )
F_13 ( V_42
L_189 ,
V_14 -> V_43 ,
( unsigned long long ) V_54 -> V_22 ,
V_54 -> V_26 ) ;
if ( V_54 -> V_79 [ 0 ] != '\0' )
F_13 ( V_42
L_9 ,
V_14 -> V_43 , V_54 -> V_80 ,
V_54 -> V_79 ) ;
F_46 ( V_14 , F_13 ( V_42
L_190 ,
V_14 -> V_43 , V_44 ,
V_54 -> V_35 , ( unsigned long long )
V_54 -> V_17 ) ) ;
if ( V_54 -> V_78 != 0 )
F_46 ( V_14 , F_13 ( V_42
L_191 ,
V_14 -> V_43 , V_44 ,
( unsigned long long ) V_54 -> V_22 ,
V_54 -> V_26 ) ) ;
if ( V_54 -> V_79 [ 0 ] != '\0' )
F_46 ( V_14 , F_13 ( V_42
L_192 ,
V_14 -> V_43 , V_44 , V_54 -> V_80 ,
V_54 -> V_79 ) ) ;
}
static void
F_243 ( struct V_13 * V_14 ,
T_19 * V_311 )
{
int V_106 ;
T_4 V_35 ;
T_4 V_330 ;
T_6 V_615 ;
char * V_627 = NULL ;
T_6 V_564 , V_628 ;
switch ( V_311 -> V_374 ) {
case V_381 :
V_627 = L_193 ;
break;
case V_378 :
V_627 = L_194 ;
break;
case V_377 :
case 0 :
V_627 = L_195 ;
break;
case V_375 :
V_627 = L_196 ;
break;
default:
V_627 = L_197 ;
break;
}
F_13 ( V_42 L_198 ,
V_14 -> V_43 , V_627 ) ;
F_13 ( L_199 \
L_200 ,
F_21 ( V_311 -> V_373 ) ,
F_21 ( V_311 -> V_524 ) ,
V_311 -> V_629 , V_311 -> V_331 ) ;
for ( V_106 = 0 ; V_106 < V_311 -> V_331 ; V_106 ++ ) {
V_35 = F_21 ( V_311 -> V_332 [ V_106 ] . V_333 ) ;
if ( ! V_35 )
continue;
V_615 = V_311 -> V_629 + V_106 ;
V_330 = V_311 -> V_332 [ V_106 ] . V_334 &
V_335 ;
switch ( V_330 ) {
case V_630 :
V_627 = L_201 ;
break;
case V_372 :
V_627 = L_202 ;
break;
case V_336 :
V_627 = L_203 ;
break;
case V_631 :
V_627 = L_204 ;
break;
case V_632 :
V_627 = L_205 ;
break;
default:
V_627 = L_46 ;
break;
}
V_564 = V_311 -> V_332 [ V_106 ] . V_633 >> 4 ;
V_628 = V_311 -> V_332 [ V_106 ] . V_633 & 0xF ;
F_13 ( L_206 \
L_207 , V_615 ,
V_35 , V_627 , V_564 , V_628 ) ;
}
}
static int
F_244 ( struct V_13 * V_14 ,
struct V_3 * V_7 )
{
int V_106 ;
T_4 V_587 , V_35 ;
T_4 V_330 ;
T_6 V_615 , V_634 ;
struct V_92 * V_93 ;
T_1 V_17 ;
unsigned long V_76 ;
T_6 V_564 , V_628 ;
T_19 * V_311 =
( T_19 * )
V_7 -> V_311 ;
if ( V_14 -> V_15 & V_635 )
F_243 ( V_14 , V_311 ) ;
if ( V_14 -> V_82 || V_14 -> V_266 || V_14 -> V_267 )
return 0 ;
if ( ! V_14 -> V_39 . V_40 )
F_226 ( V_14 ) ;
else
F_223 ( V_14 ) ;
if ( V_7 -> V_380 ) {
F_46 ( V_14 , F_13 ( V_42
L_208 , V_14 -> V_43 ) ) ;
return 0 ;
}
V_587 = F_21 ( V_311 -> V_373 ) ;
if ( V_311 -> V_374 == V_381 )
if ( F_233 ( V_14 , V_587 ) != 0 )
return 0 ;
F_32 ( & V_14 -> V_94 , V_76 ) ;
V_93 = F_57 ( V_14 ,
V_587 ) ;
if ( V_93 ) {
V_17 = V_93 -> V_17 ;
V_634 = V_93 -> V_40 ;
} else if ( V_587 < V_14 -> V_39 . V_40 ) {
V_17 = V_14 -> V_39 . V_17 ;
V_634 = V_14 -> V_39 . V_40 ;
} else {
F_33 ( & V_14 -> V_94 , V_76 ) ;
return 0 ;
}
F_33 ( & V_14 -> V_94 , V_76 ) ;
for ( V_106 = 0 ; V_106 < V_311 -> V_331 ; V_106 ++ ) {
if ( V_7 -> V_380 ) {
F_46 ( V_14 , F_13 ( V_42
L_208 , V_14 -> V_43 ) ) ;
return 0 ;
}
if ( V_14 -> V_266 || V_14 -> V_267 )
return 0 ;
V_615 = V_311 -> V_629 + V_106 ;
if ( V_615 >= V_634 )
continue;
V_330 = V_311 -> V_332 [ V_106 ] . V_334 &
V_335 ;
if ( ( V_311 -> V_332 [ V_106 ] . V_334 &
V_636 ) && ( V_330 !=
V_372 ) )
continue;
V_35 = F_21 ( V_311 -> V_332 [ V_106 ] . V_333 ) ;
if ( ! V_35 )
continue;
V_564 = V_311 -> V_332 [ V_106 ] . V_633 >> 4 ;
V_628 = V_311 -> V_332 [ V_106 ] . V_633 & 0xF ;
switch ( V_330 ) {
case V_631 :
if ( V_14 -> V_82 )
break;
if ( V_564 == V_628 )
break;
F_225 ( V_14 , V_17 ,
V_35 , V_615 , V_564 ) ;
if ( V_564 < V_569 )
break;
F_241 ( V_14 , V_17 , V_35 ,
V_615 , V_564 ) ;
case V_630 :
if ( V_14 -> V_82 )
break;
F_225 ( V_14 , V_17 ,
V_35 , V_615 , V_564 ) ;
F_242 ( V_14 , V_35 , V_615 , 0 ) ;
break;
case V_372 :
F_42 ( V_14 , V_35 ) ;
break;
}
}
if ( V_311 -> V_374 == V_378 &&
V_93 )
F_237 ( V_14 , V_17 ) ;
return 0 ;
}
static void
F_245 ( struct V_13 * V_14 ,
T_33 * V_311 )
{
char * V_637 = NULL ;
switch ( V_311 -> V_388 ) {
case V_537 :
V_637 = L_209 ;
break;
case V_638 :
V_637 = L_210 ;
break;
case V_639 :
V_637 = L_211 ;
break;
case V_640 :
V_637 = L_212 ;
break;
case V_641 :
V_637 = L_213 ;
break;
case V_642 :
V_637 = L_214 ;
break;
case V_643 :
V_637 = L_215 ;
break;
case V_644 :
V_637 = L_216 ;
break;
case V_645 :
V_637 = L_217 ;
break;
case V_646 :
V_637 = L_218 ;
break;
case V_647 :
V_637 = L_219 ;
break;
case V_648 :
V_637 = L_220 ;
break;
case V_649 :
V_637 = L_221 ;
break;
default:
V_637 = L_222 ;
break;
}
F_13 ( V_42 L_223
L_224 ,
V_14 -> V_43 , V_637 , F_21 ( V_311 -> V_200 ) ,
( unsigned long long ) F_18 ( V_311 -> V_19 ) ,
F_21 ( V_311 -> V_512 ) ) ;
if ( V_311 -> V_388 == V_537 )
F_13 ( V_42 L_225 , V_14 -> V_43 ,
V_311 -> V_538 , V_311 -> V_650 ) ;
F_13 ( L_226 ) ;
}
static void
F_246 ( struct V_13 * V_14 ,
struct V_3 * V_7 )
{
struct V_72 * V_303 ;
struct V_53 * V_54 ;
T_1 V_17 ;
unsigned long V_76 ;
T_33 * V_311 =
( T_33 * )
V_7 -> V_311 ;
if ( V_14 -> V_15 & V_635 )
F_245 ( V_14 ,
V_311 ) ;
if ( ( V_14 -> V_202 . V_651 >> 8 ) < 0xC )
return;
if ( V_311 -> V_388 !=
V_639 &&
V_311 -> V_388 !=
V_645 )
return;
F_32 ( & V_14 -> V_74 , V_76 ) ;
V_17 = F_18 ( V_311 -> V_19 ) ;
V_54 = F_34 ( V_14 ,
V_17 ) ;
if ( ! V_54 || ! V_54 -> V_85 )
goto V_89;
V_303 = V_54 -> V_85 -> V_120 ;
if ( ! V_303 )
goto V_89;
if ( V_311 -> V_388 ==
V_639 )
V_303 -> V_251 = 1 ;
else
V_303 -> V_251 = 0 ;
V_89:
if ( V_54 )
F_41 ( V_54 ) ;
F_33 ( & V_14 -> V_74 , V_76 ) ;
}
static void
F_247 ( struct V_13 * V_14 ,
T_41 * V_311 )
{
char * V_637 = NULL ;
switch ( V_311 -> V_388 ) {
case V_652 :
V_637 = L_227 ;
break;
case V_653 :
V_637 = L_228 ;
break;
default:
V_637 = L_222 ;
break;
}
F_13 ( V_42 L_229
L_230
L_231 , V_14 -> V_43 , V_637 ,
F_21 ( V_311 -> V_524 ) ,
( unsigned long long ) F_18 ( V_311 -> V_24 ) ,
F_21 ( V_311 -> V_654 ) ) ;
}
static void
F_248 ( struct V_13 * V_14 ,
struct V_3 * V_7 )
{
if ( V_14 -> V_15 & V_635 )
F_247 ( V_14 ,
( T_41 * )
V_7 -> V_311 ) ;
}
static void
F_249 ( struct V_13 * V_14 ,
struct V_3 * V_7 )
{
struct V_101 * V_104 ;
struct V_110 * V_75 ;
T_4 V_102 , V_35 ;
T_10 V_109 ;
struct V_116 * V_117 ;
T_10 V_655 ;
T_10 V_656 ;
T_18 * V_37 ;
T_42 * V_311 =
( T_42 * )
V_7 -> V_311 ;
T_4 V_38 ;
unsigned long V_76 ;
int V_2 ;
T_6 V_657 = 0 ;
T_6 V_658 ;
F_113 ( & V_14 -> V_242 . V_263 ) ;
F_13 ( V_42
L_232 ,
V_14 -> V_43 , V_44 , V_311 -> V_616 ,
V_311 -> V_659 ) ;
F_156 ( V_14 ) ;
F_32 ( & V_14 -> V_105 , V_76 ) ;
V_37 = V_14 -> V_242 . V_241 ;
V_660:
if ( V_657 ++ == 5 ) {
F_46 ( V_14 , F_13 ( V_42 L_233 ,
V_14 -> V_43 , V_44 ) ) ;
goto V_89;
} else if ( V_657 > 1 )
F_46 ( V_14 , F_13 ( V_42 L_234 ,
V_14 -> V_43 , V_44 , V_657 - 1 ) ) ;
V_655 = 0 ;
V_656 = 0 ;
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
V_656 ++ ;
if ( V_14 -> V_82 )
goto V_89;
F_33 ( & V_14 -> V_105 , V_76 ) ;
V_2 = F_112 ( V_14 , V_35 , 0 , 0 , V_109 ,
V_295 , V_102 , 30 ,
V_661 ) ;
if ( V_2 == V_264 ) {
F_75 ( V_220 , V_75 ,
L_235
L_236 , V_104 ) ;
F_32 ( & V_14 -> V_105 , V_76 ) ;
goto V_660;
}
V_38 = F_21 ( V_37 -> V_46 )
& V_47 ;
if ( V_38 != V_48 ) {
F_75 ( V_220 , V_75 ,
L_237 ,
V_38 , V_104 ) ;
F_32 ( & V_14 -> V_105 , V_76 ) ;
goto V_660;
}
if ( V_37 -> V_291 ==
V_237 ||
V_37 -> V_291 ==
V_239 ) {
F_32 ( & V_14 -> V_105 , V_76 ) ;
continue;
}
V_658 = 0 ;
V_662:
if ( V_658 ++ == 60 ) {
F_46 ( V_14 , F_13 ( V_42
L_238 , V_14 -> V_43 ,
V_44 ) ) ;
F_32 ( & V_14 -> V_105 , V_76 ) ;
goto V_660;
}
if ( V_14 -> V_82 )
goto V_663;
V_2 = F_112 ( V_14 , V_35 , V_75 -> V_88 , V_75 -> V_87 ,
V_75 -> V_109 , V_276 , V_102 , 30 ,
V_661 ) ;
if ( V_2 == V_264 ) {
F_75 ( V_220 , V_75 ,
L_239
L_240 , V_104 ) ;
goto V_662;
}
if ( V_658 > 1 )
F_75 ( V_220 , V_75 ,
L_241
L_242 ,
V_658 - 1 , V_104 ) ;
V_655 += F_78 ( V_37 -> V_289 ) ;
F_32 ( & V_14 -> V_105 , V_76 ) ;
}
if ( V_14 -> V_664 ) {
F_46 ( V_14 , F_13 ( V_42
L_243 ,
V_14 -> V_43 , V_44 ) ) ;
V_14 -> V_664 = 0 ;
goto V_660;
}
V_89:
F_33 ( & V_14 -> V_105 , V_76 ) ;
V_663:
F_46 ( V_14 , F_13 ( V_42
L_244 ,
V_14 -> V_43 , V_44 , V_656 , V_655 ) ) ;
V_14 -> V_665 = 0 ;
if ( ! V_14 -> V_82 )
F_154 ( V_14 ) ;
F_128 ( & V_14 -> V_242 . V_263 ) ;
}
static void
F_250 ( struct V_13 * V_14 ,
struct V_3 * V_7 )
{
T_43 * V_311 =
( T_43 * ) V_7 -> V_311 ;
if ( V_14 -> V_15 & V_635 ) {
F_13 ( V_42 L_245 , V_14 -> V_43 ,
( V_311 -> V_388 == V_666 ) ?
L_246 : L_247 ) ;
if ( V_311 -> V_667 )
F_13 ( L_248 ,
F_78 ( V_311 -> V_667 ) ) ;
F_13 ( L_226 ) ;
}
if ( V_311 -> V_388 == V_666 &&
! V_14 -> V_39 . V_40 ) {
if ( V_668 > 0 && V_14 -> V_82 ) {
while ( V_14 -> V_82 )
F_251 ( 1 ) ;
}
F_226 ( V_14 ) ;
}
}
static int
F_252 ( struct V_13 * V_14 , T_4 V_35 , T_6 V_669 )
{
T_44 * V_257 ;
T_45 * V_37 ;
T_4 V_102 ;
T_6 V_670 = 0 ;
int V_28 = 0 ;
T_4 V_38 ;
T_10 V_480 ;
if ( V_14 -> V_159 == V_160 )
return V_28 ;
F_113 ( & V_14 -> V_593 . V_263 ) ;
if ( V_14 -> V_593 . V_243 != V_244 ) {
F_25 ( V_42 L_249 ,
V_14 -> V_43 , V_44 ) ;
V_28 = - V_671 ;
goto V_89;
}
V_14 -> V_593 . V_243 = V_248 ;
V_102 = F_164 ( V_14 , V_14 -> V_672 ) ;
if ( ! V_102 ) {
F_25 ( V_42 L_51 ,
V_14 -> V_43 , V_44 ) ;
V_14 -> V_593 . V_243 = V_244 ;
V_28 = - V_671 ;
goto V_89;
}
V_257 = F_120 ( V_14 , V_102 ) ;
V_14 -> V_593 . V_102 = V_102 ;
memset ( V_257 , 0 , sizeof( T_44 ) ) ;
V_257 -> V_277 = V_673 ;
V_257 -> V_517 = V_674 ;
V_257 -> V_199 = V_669 ;
F_46 ( V_14 , F_13 ( V_42 L_250\
L_251 , V_14 -> V_43 ,
V_35 , V_669 ) ) ;
F_123 ( & V_14 -> V_593 . V_249 ) ;
F_166 ( V_14 , V_102 ) ;
F_125 ( & V_14 -> V_593 . V_249 , 10 * V_285 ) ;
if ( ! ( V_14 -> V_593 . V_243 & V_245 ) ) {
F_25 ( V_42 L_53 ,
V_14 -> V_43 , V_44 ) ;
if ( ! ( V_14 -> V_593 . V_243 & V_286 ) )
V_670 = 1 ;
V_28 = - V_675 ;
goto V_89;
}
if ( V_14 -> V_593 . V_243 & V_247 ) {
V_37 = V_14 -> V_593 . V_241 ;
V_38 = F_21 ( V_37 -> V_46 ) ;
if ( V_38 & V_542 )
V_480 = F_78 ( V_37 -> V_288 ) ;
else
V_480 = 0 ;
V_38 &= V_47 ;
if ( V_38 != V_48 ) {
F_46 ( V_14 , F_13 ( V_42
L_252
L_253 , V_14 -> V_43 , V_38 ,
V_480 ) ) ;
V_28 = - V_675 ;
} else
F_46 ( V_14 , F_13 ( V_42
L_254 ,
V_14 -> V_43 ) ) ;
}
V_89:
V_14 -> V_593 . V_243 = V_244 ;
F_128 ( & V_14 -> V_593 . V_263 ) ;
if ( V_670 )
F_116 ( V_14 , V_269 ,
V_270 ) ;
return V_28 ;
}
static void
F_253 ( struct V_110 * V_75 , void * V_143 )
{
int V_28 ;
V_75 -> V_143 = V_143 ? 1 : 0 ;
F_75 ( V_144 , V_75 , L_255 ,
V_75 -> V_143 ? L_256 : L_257 ) ;
V_28 = F_254 ( V_75 ) ;
}
static void
F_255 ( struct V_13 * V_14 ,
T_24 * V_384 )
{
struct V_55 * V_56 ;
unsigned long V_76 ;
T_1 V_60 ;
T_4 V_35 = F_21 ( V_384 -> V_391 ) ;
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
V_56 -> V_87 = V_14 -> V_676 ++ ;
V_56 -> V_88 = V_133 ;
V_56 -> V_35 = V_35 ;
V_56 -> V_60 = V_60 ;
F_54 ( V_14 , V_56 ) ;
if ( ! V_14 -> V_625 ) {
V_28 = F_256 ( V_14 -> V_113 , V_133 ,
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
F_257 ( struct V_13 * V_14 , T_4 V_35 )
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
V_118 -> V_340 = 1 ;
}
F_13 ( V_42 L_258 ,
V_14 -> V_43 , V_56 -> V_35 ,
( unsigned long long ) V_56 -> V_60 ) ;
F_56 ( & V_56 -> V_81 ) ;
F_2 ( V_56 ) ;
}
F_33 ( & V_14 -> V_90 , V_76 ) ;
if ( V_85 )
F_258 ( & V_85 -> V_127 ) ;
}
static void
F_259 ( struct V_13 * V_14 ,
T_24 * V_384 )
{
struct V_53 * V_54 ;
struct V_126 * V_85 = NULL ;
struct V_72 * V_118 ;
unsigned long V_76 ;
T_4 V_35 = F_21 ( V_384 -> V_393 ) ;
F_32 ( & V_14 -> V_74 , V_76 ) ;
V_54 = F_36 ( V_14 , V_35 ) ;
if ( V_54 ) {
V_54 -> V_208 = 0 ;
V_54 -> V_209 = 0 ;
F_182 ( V_35 , V_14 -> V_137 ) ;
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
F_260 ( V_85 , NULL , F_253 ) ;
F_41 ( V_54 ) ;
}
static void
F_261 ( struct V_13 * V_14 ,
T_24 * V_384 )
{
struct V_53 * V_54 ;
struct V_126 * V_85 = NULL ;
struct V_72 * V_118 ;
unsigned long V_76 ;
T_4 V_35 = F_21 ( V_384 -> V_393 ) ;
T_4 V_208 = 0 ;
T_1 V_209 = 0 ;
F_99 ( V_14 , V_35 , & V_208 ) ;
if ( V_208 )
F_100 ( V_14 , V_208 ,
& V_209 ) ;
F_32 ( & V_14 -> V_74 , V_76 ) ;
V_54 = F_36 ( V_14 , V_35 ) ;
if ( V_54 ) {
F_159 ( V_35 , V_14 -> V_137 ) ;
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
F_252 ( V_14 , V_35 , V_384 -> V_199 ) ;
if ( V_85 )
F_260 ( V_85 , ( void * ) 1 , F_253 ) ;
F_41 ( V_54 ) ;
}
static void
F_262 ( struct V_13 * V_14 ,
T_24 * V_384 )
{
T_4 V_35 = F_21 ( V_384 -> V_393 ) ;
F_42 ( V_14 , V_35 ) ;
}
static void
F_263 ( struct V_13 * V_14 ,
T_24 * V_384 )
{
struct V_53 * V_54 ;
T_4 V_35 = F_21 ( V_384 -> V_393 ) ;
T_9 V_37 ;
T_8 V_36 ;
T_10 V_38 ;
T_1 V_17 ;
T_4 V_587 ;
F_159 ( V_35 , V_14 -> V_137 ) ;
V_54 = F_37 ( V_14 , V_35 ) ;
if ( V_54 ) {
F_252 ( V_14 , V_35 , V_384 -> V_199 ) ;
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
V_587 = F_21 ( V_36 . V_589 ) ;
if ( ! F_23 ( V_14 , V_587 , & V_17 ) )
F_225 ( V_14 , V_17 , V_35 ,
V_36 . V_616 , V_569 ) ;
F_252 ( V_14 , V_35 , V_384 -> V_199 ) ;
F_242 ( V_14 , V_35 , 0 , 1 ) ;
}
static void
F_264 ( struct V_13 * V_14 ,
T_23 * V_311 )
{
T_24 * V_384 ;
T_6 V_677 ;
int V_106 ;
char * V_637 = NULL , * V_678 = NULL ;
V_384 = ( T_24 * ) & V_311 -> V_385 [ 0 ] ;
F_13 ( V_42 L_259 ,
V_14 -> V_43 , ( F_78 ( V_311 -> V_145 ) &
V_387 ) ?
L_260 : L_261 , V_311 -> V_386 ) ;
for ( V_106 = 0 ; V_106 < V_311 -> V_386 ; V_106 ++ , V_384 ++ ) {
switch ( V_384 -> V_388 ) {
case V_679 :
V_637 = L_193 ;
break;
case V_390 :
V_637 = L_194 ;
break;
case V_680 :
V_637 = L_262 ;
break;
case V_681 :
V_637 = L_263 ;
break;
case V_392 :
V_637 = L_264 ;
break;
case V_682 :
V_637 = L_265 ;
break;
case V_389 :
V_637 = L_266 ;
break;
case V_683 :
V_637 = L_267 ;
break;
case V_684 :
V_637 = L_268 ;
break;
default:
V_637 = L_222 ;
break;
}
V_677 = F_21 ( V_384 -> V_685 ) &
V_686 ;
switch ( V_677 ) {
case V_687 :
V_678 = L_57 ;
break;
case V_688 :
V_678 = L_269 ;
break;
case V_689 :
V_678 = L_270 ;
break;
default:
V_678 = L_271 ;
break;
}
F_13 ( L_272 \
L_273 , V_678 ,
V_637 , F_21 ( V_384 -> V_391 ) ,
F_21 ( V_384 -> V_393 ) ,
V_384 -> V_199 ) ;
}
}
static void
F_265 ( struct V_13 * V_14 ,
struct V_3 * V_7 )
{
T_24 * V_384 ;
int V_106 ;
T_6 V_690 ;
T_23 * V_311 =
( T_23 * )
V_7 -> V_311 ;
if ( ( V_14 -> V_15 & V_635 ) &&
( ! V_14 -> V_218 ) )
F_264 ( V_14 , V_311 ) ;
V_690 = ( F_78 ( V_311 -> V_145 ) &
V_387 ) ? 1 : 0 ;
V_384 = ( T_24 * ) & V_311 -> V_385 [ 0 ] ;
if ( V_14 -> V_82 &&
V_14 -> V_159 != V_160 ) {
for ( V_106 = 0 ; V_106 < V_311 -> V_386 ; V_106 ++ , V_384 ++ ) {
if ( V_384 -> V_388 == V_681 )
F_252 ( V_14 ,
F_21 ( V_384 -> V_393 ) ,
V_384 -> V_199 ) ;
}
return;
}
for ( V_106 = 0 ; V_106 < V_311 -> V_386 ; V_106 ++ , V_384 ++ ) {
switch ( V_384 -> V_388 ) {
case V_682 :
case V_679 :
if ( ! V_690 )
F_255 ( V_14 , V_384 ) ;
break;
case V_389 :
case V_390 :
if ( ! V_690 )
F_257 ( V_14 ,
F_21 ( V_384 -> V_391 ) ) ;
break;
case V_683 :
if ( ! V_14 -> V_134 )
F_261 ( V_14 , V_384 ) ;
break;
case V_684 :
if ( ! V_14 -> V_134 )
F_259 ( V_14 , V_384 ) ;
break;
case V_681 :
if ( ! V_14 -> V_134 )
F_263 ( V_14 , V_384 ) ;
break;
case V_392 :
if ( ! V_14 -> V_134 )
F_262 ( V_14 , V_384 ) ;
break;
}
}
}
static void
F_266 ( struct V_13 * V_14 ,
struct V_3 * V_7 )
{
T_1 V_60 ;
unsigned long V_76 ;
struct V_55 * V_56 ;
T_4 V_35 ;
T_10 V_167 ;
int V_28 ;
T_25 * V_311 =
( T_25 * ) V_7 -> V_311 ;
if ( V_14 -> V_82 )
return;
if ( V_311 -> V_388 != V_394 )
return;
V_35 = F_21 ( V_311 -> V_391 ) ;
V_167 = F_78 ( V_311 -> V_395 ) ;
if ( ! V_14 -> V_218 )
F_46 ( V_14 , F_13 ( V_42
L_274 ,
V_14 -> V_43 , V_44 , V_35 ,
F_78 ( V_311 -> V_691 ) , V_167 ) ) ;
switch ( V_167 ) {
case V_177 :
case V_176 :
F_257 ( V_14 , V_35 ) ;
break;
case V_172 :
case V_174 :
case V_171 :
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
V_56 -> V_87 = V_14 -> V_676 ++ ;
V_56 -> V_88 = V_133 ;
V_56 -> V_35 = V_35 ;
V_56 -> V_60 = V_60 ;
F_54 ( V_14 , V_56 ) ;
V_28 = F_256 ( V_14 -> V_113 , V_133 ,
V_56 -> V_87 , 0 ) ;
if ( V_28 )
F_55 ( V_14 , V_56 ) ;
break;
case V_692 :
default:
break;
}
}
static void
F_267 ( struct V_13 * V_14 ,
struct V_3 * V_7 )
{
T_4 V_35 , V_587 ;
T_10 V_167 ;
struct V_53 * V_54 ;
T_9 V_37 ;
T_8 V_36 ;
T_10 V_38 ;
T_46 * V_311 =
( T_46 * ) V_7 -> V_311 ;
T_1 V_17 ;
if ( V_14 -> V_82 )
return;
if ( V_311 -> V_388 != V_693 )
return;
V_35 = F_21 ( V_311 -> V_393 ) ;
V_167 = F_78 ( V_311 -> V_395 ) ;
if ( ! V_14 -> V_218 )
F_46 ( V_14 , F_13 ( V_42
L_274 ,
V_14 -> V_43 , V_44 , V_35 ,
F_78 ( V_311 -> V_691 ) , V_167 ) ) ;
switch ( V_167 ) {
case V_694 :
case V_695 :
case V_696 :
case V_697 :
case V_698 :
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
V_587 = F_21 ( V_36 . V_589 ) ;
if ( ! F_23 ( V_14 , V_587 , & V_17 ) )
F_225 ( V_14 , V_17 , V_35 ,
V_36 . V_616 , V_569 ) ;
F_242 ( V_14 , V_35 , 0 , 1 ) ;
break;
case V_699 :
case V_700 :
case V_701 :
default:
break;
}
}
static void
F_268 ( struct V_13 * V_14 ,
T_47 * V_311 )
{
char * V_637 = NULL ;
switch ( V_311 -> V_702 ) {
case V_703 :
V_637 = L_275 ;
break;
case V_704 :
V_637 = L_276 ;
break;
case V_705 :
V_637 = L_277 ;
break;
case V_706 :
V_637 = L_278 ;
break;
case V_707 :
V_637 = L_279 ;
break;
}
if ( ! V_637 )
return;
F_13 ( V_42 L_280 \
L_281 ,
V_14 -> V_43 , V_637 ,
F_21 ( V_311 -> V_391 ) ,
V_311 -> V_708 ) ;
}
static void
F_269 ( struct V_13 * V_14 ,
struct V_3 * V_7 )
{
T_47 * V_311 =
( T_47 * )
V_7 -> V_311 ;
static struct V_55 * V_56 ;
unsigned long V_76 ;
T_4 V_35 ;
if ( ( V_14 -> V_15 & V_635 ) &&
( ! V_14 -> V_218 ) )
F_268 ( V_14 ,
V_311 ) ;
if ( V_311 -> V_702 == V_703 ) {
F_32 ( & V_14 -> V_90 , V_76 ) ;
V_35 = F_21 ( V_311 -> V_391 ) ;
V_56 = F_52 ( V_14 , V_35 ) ;
if ( V_56 )
V_56 -> V_155 =
V_311 -> V_708 ;
F_33 ( & V_14 -> V_90 , V_76 ) ;
}
}
static void
F_270 ( struct V_13 * V_14 )
{
struct V_116 * V_117 ;
struct V_110 * V_75 ;
F_110 (sdev, ioc->shost) {
V_117 = V_75 -> V_120 ;
if ( V_117 && V_117 -> V_122 )
V_117 -> V_122 -> V_340 = 1 ;
}
}
static void
F_271 ( struct V_13 * V_14 ,
T_8 * V_36 )
{
struct V_72 * V_118 = NULL ;
struct V_126 * V_85 ;
struct V_53 * V_54 ;
unsigned long V_76 ;
F_32 ( & V_14 -> V_74 , V_76 ) ;
F_15 (sas_device, &ioc->sas_device_list, list) {
if ( ( V_54 -> V_17 == V_36 -> V_19 ) &&
( V_54 -> V_26 == V_36 -> V_523 ) ) {
V_54 -> V_709 = 1 ;
V_85 = V_54 -> V_85 ;
if ( V_85 && V_85 -> V_120 ) {
V_118 = V_85 -> V_120 ;
V_118 -> V_251 = 0 ;
V_118 -> V_340 = 0 ;
} else
V_118 = NULL ;
if ( V_85 ) {
F_131 ( V_144 , V_85 ,
L_282 ,
V_36 -> V_200 ,
( unsigned long long )
V_54 -> V_17 ) ;
if ( V_54 -> V_78 != 0 )
F_131 ( V_144 , V_85 ,
L_283
L_94 ,
( unsigned long long )
V_54 -> V_22 ,
V_54 -> V_26 ) ;
}
if ( V_36 -> V_145 &
V_617 ) {
V_54 -> V_80 =
F_21 ( V_36 -> V_618 ) ;
memcpy ( & V_54 -> V_79 [ 0 ] ,
& V_36 -> V_619 [ 0 ] , 4 ) ;
} else {
V_54 -> V_80 = 0 ;
V_54 -> V_79 [ 0 ] = '\0' ;
}
if ( V_54 -> V_35 == V_36 -> V_200 )
goto V_89;
F_13 ( L_284 ,
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
F_272 ( struct V_13 * V_14 )
{
T_8 V_36 ;
T_9 V_37 ;
T_4 V_38 ;
T_4 V_35 ;
T_10 V_96 ;
F_13 ( V_42 L_285 , V_14 -> V_43 ) ;
if ( F_39 ( & V_14 -> V_83 ) )
goto V_89;
V_35 = 0xFFFF ;
while ( ! ( F_24 ( V_14 , & V_37 ,
& V_36 , V_710 ,
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
V_36 . V_523 = F_21 ( V_36 . V_523 ) ;
F_271 ( V_14 , & V_36 ) ;
}
V_89:
F_13 ( V_42 L_286 ,
V_14 -> V_43 ) ;
}
static void
F_273 ( struct V_13 * V_14 , T_1 V_60 ,
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
V_118 -> V_340 = 0 ;
} else
V_118 = NULL ;
V_56 -> V_709 = 1 ;
F_33 ( & V_14 -> V_90 , V_76 ) ;
F_131 ( V_144 , V_56 -> V_85 ,
L_287 , V_35 ,
( unsigned long long ) V_56 -> V_60 ) ;
F_98 ( V_14 , V_56 ) ;
F_32 ( & V_14 -> V_90 , V_76 ) ;
if ( V_56 -> V_35 == V_35 ) {
F_33 ( & V_14 -> V_90 ,
V_76 ) ;
return;
}
F_13 ( L_284 ,
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
F_274 ( struct V_13 * V_14 )
{
T_48 V_711 ;
T_11 V_712 ;
T_12 V_192 ;
T_9 V_37 ;
T_4 V_38 ;
T_4 V_35 ;
T_6 V_669 ;
if ( ! V_14 -> V_713 )
return;
F_13 ( V_42 L_288 ,
V_14 -> V_43 ) ;
if ( F_39 ( & V_14 -> V_91 ) )
goto V_89;
V_35 = 0xFFFF ;
while ( ! ( F_275 ( V_14 , & V_37 ,
& V_711 , V_714 , V_35 ) ) ) {
V_38 = F_21 ( V_37 . V_46 ) &
V_47 ;
if ( V_38 != V_48 )
break;
V_35 = F_21 ( V_711 . V_200 ) ;
if ( F_82 ( V_14 , & V_37 ,
& V_712 , V_156 , V_35 ,
sizeof( T_11 ) ) )
continue;
if ( V_712 . V_170 == V_171 ||
V_712 . V_170 == V_172 ||
V_712 . V_170 == V_174 )
F_273 ( V_14 ,
F_18 ( V_711 . V_715 ) , V_35 ) ;
}
if ( ! V_14 -> V_134 ) {
V_669 = 0xFF ;
memset ( V_14 -> V_137 , 0 , V_14 -> V_716 ) ;
while ( ! ( F_93 ( V_14 , & V_37 ,
& V_192 , V_717 ,
V_669 ) ) ) {
V_38 = F_21 ( V_37 . V_46 ) &
V_47 ;
if ( V_38 != V_48 )
break;
V_669 = V_192 . V_199 ;
V_35 = F_21 ( V_192 . V_200 ) ;
F_159 ( V_35 , V_14 -> V_137 ) ;
}
}
V_89:
F_13 ( V_42 L_289 ,
V_14 -> V_43 ) ;
}
static void
F_276 ( struct V_13 * V_14 , T_1 V_17 ,
T_4 V_35 )
{
struct V_92 * V_93 ;
unsigned long V_76 ;
int V_106 ;
F_32 ( & V_14 -> V_94 , V_76 ) ;
F_15 (sas_expander, &ioc->sas_expander_list, list) {
if ( V_93 -> V_17 != V_17 )
continue;
V_93 -> V_709 = 1 ;
if ( V_93 -> V_35 == V_35 )
goto V_89;
F_13 ( L_290 \
L_291 ,
( unsigned long long ) V_93 -> V_17 ,
V_93 -> V_35 , V_35 ) ;
V_93 -> V_35 = V_35 ;
for ( V_106 = 0 ; V_106 < V_93 -> V_40 ; V_106 ++ )
V_93 -> V_222 [ V_106 ] . V_35 = V_35 ;
goto V_89;
}
V_89:
F_33 ( & V_14 -> V_94 , V_76 ) ;
}
static void
F_277 ( struct V_13 * V_14 )
{
T_39 V_585 ;
T_9 V_37 ;
T_4 V_38 ;
T_1 V_17 ;
T_4 V_35 ;
F_13 ( V_42 L_292 , V_14 -> V_43 ) ;
if ( F_39 ( & V_14 -> V_95 ) )
goto V_89;
V_35 = 0xFFFF ;
while ( ! ( F_234 ( V_14 , & V_37 , & V_585 ,
V_718 , V_35 ) ) ) {
V_38 = F_21 ( V_37 . V_46 ) &
V_47 ;
if ( V_38 != V_48 )
break;
V_35 = F_21 ( V_585 . V_200 ) ;
V_17 = F_18 ( V_585 . V_19 ) ;
F_13 ( L_293 ,
V_35 ,
( unsigned long long ) V_17 ) ;
F_276 ( V_14 , V_17 , V_35 ) ;
}
V_89:
F_13 ( V_42 L_294 , V_14 -> V_43 ) ;
}
static void
F_278 ( struct V_13 * V_14 )
{
struct V_53 * V_54 , * V_719 ;
struct V_92 * V_93 , * V_720 ;
struct V_55 * V_56 , * V_721 ;
struct V_722 V_723 ;
unsigned long V_76 ;
F_279 ( V_724 ) ;
F_13 ( V_42 L_295 ,
V_14 -> V_43 ) ;
F_13 ( V_42 L_296 ,
V_14 -> V_43 ) ;
F_32 ( & V_14 -> V_74 , V_76 ) ;
F_280 (sas_device, sas_device_next,
&ioc->sas_device_list, list) {
if ( ! V_54 -> V_709 )
F_281 ( & V_54 -> V_81 , & V_724 ) ;
else
V_54 -> V_709 = 0 ;
}
F_33 ( & V_14 -> V_74 , V_76 ) ;
F_280 (sas_device, sas_device_next, &head, list) {
F_43 ( V_14 , V_54 ) ;
F_40 ( & V_54 -> V_81 ) ;
F_41 ( V_54 ) ;
}
if ( V_14 -> V_713 ) {
F_13 ( V_42 L_297 ,
V_14 -> V_43 ) ;
F_280 (raid_device, raid_device_next,
&ioc->raid_device_list, list) {
if ( ! V_56 -> V_709 )
F_257 ( V_14 ,
V_56 -> V_35 ) ;
else
V_56 -> V_709 = 0 ;
}
}
F_13 ( V_42 L_298 ,
V_14 -> V_43 ) ;
F_32 ( & V_14 -> V_94 , V_76 ) ;
F_138 ( & V_723 ) ;
F_280 (sas_expander, sas_expander_next,
&ioc->sas_expander_list, list) {
if ( ! V_93 -> V_709 )
F_281 ( & V_93 -> V_81 , & V_723 ) ;
else
V_93 -> V_709 = 0 ;
}
F_33 ( & V_14 -> V_94 , V_76 ) ;
F_280 (sas_expander, sas_expander_next, &tmp_list,
list) {
F_56 ( & V_93 -> V_81 ) ;
F_238 ( V_14 , V_93 ) ;
}
F_13 ( V_42 L_299 ,
V_14 -> V_43 ) ;
F_154 ( V_14 ) ;
}
static void
F_282 ( struct V_13 * V_14 ,
struct V_92 * V_93 , T_4 V_35 )
{
T_40 V_586 ;
T_9 V_37 ;
int V_106 ;
for ( V_106 = 0 ; V_106 < V_93 -> V_40 ; V_106 ++ ) {
if ( ( F_235 ( V_14 , & V_37 ,
& V_586 , V_106 , V_35 ) ) ) {
F_25 ( V_42 L_2 ,
V_14 -> V_43 , __FILE__ , __LINE__ , V_44 ) ;
return;
}
F_225 ( V_14 , V_93 -> V_17 ,
F_21 ( V_586 . V_333 ) , V_106 ,
V_586 . V_567 >> 4 ) ;
}
}
static void
F_283 ( struct V_13 * V_14 )
{
T_39 V_585 ;
T_8 V_36 ;
T_48 V_711 ;
T_11 V_712 ;
T_12 V_192 ;
T_24 V_384 ;
T_9 V_37 ;
T_6 V_669 ;
T_4 V_38 ;
T_4 V_35 , V_587 ;
T_1 V_17 ;
struct V_53 * V_54 ;
struct V_92 * V_725 ;
static struct V_55 * V_56 ;
T_6 V_726 ;
unsigned long V_76 ;
F_13 ( V_42 L_300 , V_14 -> V_43 ) ;
F_223 ( V_14 ) ;
F_13 ( V_42 L_301 , V_14 -> V_43 ) ;
V_35 = 0xFFFF ;
while ( ! ( F_234 ( V_14 , & V_37 , & V_585 ,
V_718 , V_35 ) ) ) {
V_38 = F_21 ( V_37 . V_46 ) &
V_47 ;
if ( V_38 != V_48 ) {
F_13 ( V_42 L_302 \
L_303 ,
V_14 -> V_43 , V_38 ,
F_78 ( V_37 . V_288 ) ) ;
break;
}
V_35 = F_21 ( V_585 . V_200 ) ;
F_32 ( & V_14 -> V_94 , V_76 ) ;
V_725 = F_58 (
V_14 , F_18 ( V_585 . V_19 ) ) ;
F_33 ( & V_14 -> V_94 , V_76 ) ;
if ( V_725 )
F_282 ( V_14 , V_725 ,
V_35 ) ;
else {
F_13 ( V_42 L_304 \
L_305 , V_14 -> V_43 ,
V_35 , ( unsigned long long )
F_18 ( V_585 . V_19 ) ) ;
F_233 ( V_14 , V_35 ) ;
F_13 ( V_42 L_306 \
L_305 , V_14 -> V_43 ,
V_35 , ( unsigned long long )
F_18 ( V_585 . V_19 ) ) ;
}
}
F_13 ( V_42 L_307 ,
V_14 -> V_43 ) ;
if ( ! V_14 -> V_713 )
goto V_727;
F_13 ( V_42 L_308 , V_14 -> V_43 ) ;
V_669 = 0xFF ;
while ( ! ( F_93 ( V_14 , & V_37 ,
& V_192 , V_717 ,
V_669 ) ) ) {
V_38 = F_21 ( V_37 . V_46 ) &
V_47 ;
if ( V_38 != V_48 ) {
F_13 ( V_42 L_309\
L_303 ,
V_14 -> V_43 , V_38 ,
F_78 ( V_37 . V_288 ) ) ;
break;
}
V_669 = V_192 . V_199 ;
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
F_13 ( V_42 L_310 \
L_303 ,
V_14 -> V_43 , V_38 ,
F_78 ( V_37 . V_288 ) ) ;
break;
}
V_587 = F_21 ( V_36 . V_589 ) ;
if ( ! F_23 ( V_14 , V_587 ,
& V_17 ) ) {
F_13 ( V_42 L_311 \
L_312 ,
V_14 -> V_43 , V_35 , ( unsigned long long )
F_18 ( V_36 . V_19 ) ) ;
F_225 ( V_14 , V_17 ,
V_35 , V_36 . V_616 ,
V_569 ) ;
F_159 ( V_35 , V_14 -> V_137 ) ;
V_726 = 0 ;
while ( F_242 ( V_14 , V_35 , V_726 ++ ,
1 ) ) {
F_251 ( 1 ) ;
}
F_13 ( V_42 L_313 \
L_312 ,
V_14 -> V_43 , V_35 , ( unsigned long long )
F_18 ( V_36 . V_19 ) ) ;
}
}
F_13 ( V_42 L_314 ,
V_14 -> V_43 ) ;
F_13 ( V_42 L_315 , V_14 -> V_43 ) ;
V_35 = 0xFFFF ;
while ( ! ( F_275 ( V_14 , & V_37 ,
& V_711 , V_714 , V_35 ) ) ) {
V_38 = F_21 ( V_37 . V_46 ) &
V_47 ;
if ( V_38 != V_48 ) {
F_13 ( V_42 L_316 \
L_303 ,
V_14 -> V_43 , V_38 ,
F_78 ( V_37 . V_288 ) ) ;
break;
}
V_35 = F_21 ( V_711 . V_200 ) ;
F_32 ( & V_14 -> V_90 , V_76 ) ;
V_56 = F_53 ( V_14 ,
F_18 ( V_711 . V_715 ) ) ;
F_33 ( & V_14 -> V_90 , V_76 ) ;
if ( V_56 )
continue;
if ( F_82 ( V_14 , & V_37 ,
& V_712 , V_156 , V_35 ,
sizeof( T_11 ) ) )
continue;
V_38 = F_21 ( V_37 . V_46 ) &
V_47 ;
if ( V_38 != V_48 ) {
F_13 ( V_42 L_316 \
L_303 ,
V_14 -> V_43 , V_38 ,
F_78 ( V_37 . V_288 ) ) ;
break;
}
if ( V_712 . V_170 == V_171 ||
V_712 . V_170 == V_172 ||
V_712 . V_170 == V_174 ) {
memset ( & V_384 , 0 , sizeof( T_24 ) ) ;
V_384 . V_388 = V_679 ;
V_384 . V_391 = V_711 . V_200 ;
F_13 ( V_42
L_317 ,
V_14 -> V_43 , V_711 . V_200 ) ;
F_255 ( V_14 , & V_384 ) ;
F_13 ( V_42
L_318 ,
V_14 -> V_43 , V_711 . V_200 ) ;
}
}
F_13 ( V_42 L_319 ,
V_14 -> V_43 ) ;
V_727:
F_13 ( V_42 L_320 ,
V_14 -> V_43 ) ;
V_35 = 0xFFFF ;
while ( ! ( F_24 ( V_14 , & V_37 ,
& V_36 , V_710 ,
V_35 ) ) ) {
V_38 = F_21 ( V_37 . V_46 ) &
V_47 ;
if ( V_38 != V_48 ) {
F_13 ( V_42 L_321\
L_322 ,
V_14 -> V_43 , V_38 ,
F_78 ( V_37 . V_288 ) ) ;
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
V_587 = F_21 ( V_36 . V_589 ) ;
if ( ! F_23 ( V_14 , V_587 , & V_17 ) ) {
F_13 ( V_42 L_323 \
L_305 , V_14 -> V_43 ,
V_35 , ( unsigned long long )
F_18 ( V_36 . V_19 ) ) ;
F_225 ( V_14 , V_17 , V_35 ,
V_36 . V_616 , V_569 ) ;
V_726 = 0 ;
while ( F_242 ( V_14 , V_35 , V_726 ++ ,
0 ) ) {
F_251 ( 1 ) ;
}
F_13 ( V_42 L_324 \
L_305 , V_14 -> V_43 ,
V_35 , ( unsigned long long )
F_18 ( V_36 . V_19 ) ) ;
}
}
F_13 ( V_42 L_325 ,
V_14 -> V_43 ) ;
F_13 ( V_42 L_326 , V_14 -> V_43 ) ;
}
void
F_284 ( struct V_13 * V_14 , int V_728 )
{
switch ( V_728 ) {
case V_729 :
F_119 ( V_14 , F_13 ( V_42
L_327 , V_14 -> V_43 , V_44 ) ) ;
break;
case V_730 :
F_119 ( V_14 , F_13 ( V_42
L_328 , V_14 -> V_43 , V_44 ) ) ;
if ( V_14 -> V_593 . V_243 & V_248 ) {
V_14 -> V_593 . V_243 |= V_286 ;
F_175 ( V_14 , V_14 -> V_593 . V_102 ) ;
F_108 ( & V_14 -> V_593 . V_249 ) ;
}
if ( V_14 -> V_242 . V_243 & V_248 ) {
V_14 -> V_242 . V_243 |= V_286 ;
F_175 ( V_14 , V_14 -> V_242 . V_102 ) ;
F_108 ( & V_14 -> V_242 . V_249 ) ;
}
F_147 ( V_14 ) ;
F_186 ( V_14 ) ;
break;
case V_731 :
F_119 ( V_14 , F_13 ( V_42
L_329 , V_14 -> V_43 , V_44 ) ) ;
if ( ( ! V_14 -> V_57 ) && ! ( V_668 > 0 &&
! V_14 -> V_39 . V_40 ) ) {
F_270 ( V_14 ) ;
F_272 ( V_14 ) ;
F_274 ( V_14 ) ;
F_277 ( V_14 ) ;
F_143 ( V_14 ) ;
}
break;
}
}
static void
F_285 ( struct V_13 * V_14 , struct V_3 * V_7 )
{
F_141 ( V_14 , V_7 ) ;
if ( V_14 -> V_266 || V_14 -> V_267 ) {
F_6 ( V_7 ) ;
return;
}
switch ( V_7 -> V_312 ) {
case V_313 :
F_286 ( V_14 ,
(struct V_310 * )
V_7 -> V_311 ) ;
break;
case V_314 :
while ( F_287 ( V_14 -> V_113 ) ||
V_14 -> V_82 ) {
if ( V_14 -> V_266 )
goto V_89;
F_251 ( 1 ) ;
}
F_278 ( V_14 ) ;
F_283 ( V_14 ) ;
break;
case V_315 :
V_14 -> V_732 = 0 ;
if ( V_733 [ 0 ] != - 1 && V_733 [ 1 ] != - 1 )
F_288 ( V_14 , V_733 [ 0 ] ,
V_733 [ 1 ] ) ;
F_46 ( V_14 , F_13 ( V_42
L_330 ,
V_14 -> V_43 ) ) ;
break;
case V_526 :
F_206 ( V_14 , V_7 -> V_527 ) ;
break;
case V_379 :
F_244 ( V_14 , V_7 ) ;
break;
case V_535 :
F_246 ( V_14 , V_7 ) ;
break;
case V_734 :
F_250 ( V_14 , V_7 ) ;
break;
case V_735 :
F_249 ( V_14 , V_7 ) ;
break;
case V_736 :
F_248 ( V_14 ,
V_7 ) ;
break;
case V_737 :
F_265 ( V_14 , V_7 ) ;
break;
case V_738 :
F_266 ( V_14 , V_7 ) ;
break;
case V_739 :
F_267 ( V_14 , V_7 ) ;
break;
case V_740 :
F_269 ( V_14 , V_7 ) ;
break;
}
V_89:
F_6 ( V_7 ) ;
}
static void
V_309 ( struct V_741 * V_308 )
{
struct V_3 * V_7 = F_3 ( V_308 ,
struct V_3 , V_308 ) ;
F_285 ( V_7 -> V_14 , V_7 ) ;
}
T_6
F_289 ( struct V_13 * V_14 , T_6 V_240 ,
T_10 V_241 )
{
struct V_3 * V_7 ;
T_32 * V_37 ;
T_4 V_312 ;
T_4 V_193 ;
if ( V_14 -> V_266 || V_14 -> V_267 )
return 1 ;
V_37 = F_107 ( V_14 , V_241 ) ;
if ( F_163 ( ! V_37 ) ) {
F_25 ( V_42 L_102 ,
V_14 -> V_43 , __FILE__ , __LINE__ , V_44 ) ;
return 1 ;
}
V_312 = F_21 ( V_37 -> V_362 ) ;
if ( V_312 != V_742 )
F_290 ( V_14 , V_312 , 0 ) ;
switch ( V_312 ) {
case V_735 :
{
T_42 * V_743 =
( T_42 * )
V_37 -> V_533 ;
if ( V_743 -> V_744 !=
V_745 )
return 1 ;
if ( V_14 -> V_665 ) {
V_14 -> V_664 ++ ;
return 1 ;
} else
V_14 -> V_665 = 1 ;
break;
}
case V_379 :
F_176 ( V_14 ,
( T_19 * )
V_37 -> V_533 ) ;
break;
case V_737 :
F_181 ( V_14 ,
( T_23 * )
V_37 -> V_533 ) ;
break;
case V_738 :
F_184 ( V_14 ,
( T_25 * )
V_37 -> V_533 ) ;
break;
case V_742 :
{
T_49 * V_746 ;
T_10 * V_747 ;
if ( ! V_14 -> V_134 )
break;
V_746 = ( T_49 * )
V_37 -> V_533 ;
V_747 = ( T_10 * ) V_746 -> V_748 ;
if ( F_21 ( V_746 -> V_749 )
!= V_750 )
break;
switch ( F_78 ( * V_747 ) ) {
case V_751 :
F_91 ( V_42 L_331
L_332
L_333
L_334 , V_14 -> V_43 ) ;
break;
case V_752 :
F_91 ( V_42 L_331
L_335
L_336
L_337 , V_14 -> V_43 ) ;
break;
case V_753 :
F_25 ( V_42 L_338
L_339
L_340
L_341
L_337 , V_14 -> V_43 ) ;
break;
case V_754 :
F_25 ( V_42 L_338
L_342
L_343
L_344 ,
V_14 -> V_43 ) ;
break;
}
break;
}
case V_535 :
case V_740 :
case V_734 :
case V_736 :
case V_739 :
break;
case V_755 :
F_185 ( V_14 ,
( T_26 * )
V_37 -> V_533 ) ;
break;
default:
return 1 ;
}
V_193 = F_21 ( V_37 -> V_536 ) * 4 ;
V_7 = F_8 ( V_193 ) ;
if ( ! V_7 ) {
F_25 ( V_42 L_2 ,
V_14 -> V_43 , __FILE__ , __LINE__ , V_44 ) ;
return 1 ;
}
memcpy ( V_7 -> V_311 , V_37 -> V_533 , V_193 ) ;
V_7 -> V_14 = V_14 ;
V_7 -> V_364 = V_37 -> V_364 ;
V_7 -> V_365 = V_37 -> V_365 ;
V_7 -> V_312 = V_312 ;
F_137 ( V_14 , V_7 ) ;
F_6 ( V_7 ) ;
return 1 ;
}
static void
F_238 ( struct V_13 * V_14 ,
struct V_92 * V_93 )
{
struct V_321 * V_322 , * V_369 ;
F_280 (mpt3sas_port, next,
&sas_expander->sas_port_list, port_list) {
if ( V_14 -> V_82 )
return;
if ( V_322 -> V_324 . V_325 ==
V_326 )
F_44 ( V_14 ,
V_322 -> V_324 . V_17 ) ;
else if ( V_322 -> V_324 . V_325 ==
V_328 ||
V_322 -> V_324 . V_325 ==
V_329 )
F_237 ( V_14 ,
V_322 -> V_324 . V_17 ) ;
}
F_49 ( V_14 , V_93 -> V_17 ,
V_93 -> V_84 ) ;
F_13 ( V_42
L_345 ,
V_14 -> V_43 ,
V_93 -> V_35 , ( unsigned long long )
V_93 -> V_17 ) ;
F_2 ( V_93 -> V_222 ) ;
F_2 ( V_93 ) ;
}
static void
F_291 ( struct V_13 * V_14 )
{
T_44 * V_257 ;
T_45 * V_37 ;
T_4 V_102 ;
if ( ! V_14 -> V_713 )
return;
if ( F_39 ( & V_14 -> V_91 ) )
return;
F_113 ( & V_14 -> V_593 . V_263 ) ;
if ( V_14 -> V_593 . V_243 != V_244 ) {
F_25 ( V_42 L_249 ,
V_14 -> V_43 , V_44 ) ;
goto V_89;
}
V_14 -> V_593 . V_243 = V_248 ;
V_102 = F_164 ( V_14 , V_14 -> V_672 ) ;
if ( ! V_102 ) {
F_25 ( V_42 L_51 ,
V_14 -> V_43 , V_44 ) ;
V_14 -> V_593 . V_243 = V_244 ;
goto V_89;
}
V_257 = F_120 ( V_14 , V_102 ) ;
V_14 -> V_593 . V_102 = V_102 ;
memset ( V_257 , 0 , sizeof( T_44 ) ) ;
V_257 -> V_277 = V_673 ;
V_257 -> V_517 = V_756 ;
if ( ! V_14 -> V_218 )
F_13 ( V_42 L_346 , V_14 -> V_43 ) ;
F_123 ( & V_14 -> V_593 . V_249 ) ;
F_166 ( V_14 , V_102 ) ;
F_125 ( & V_14 -> V_593 . V_249 , 10 * V_285 ) ;
if ( ! ( V_14 -> V_593 . V_243 & V_245 ) ) {
F_25 ( V_42 L_53 ,
V_14 -> V_43 , V_44 ) ;
goto V_89;
}
if ( V_14 -> V_593 . V_243 & V_247 ) {
V_37 = V_14 -> V_593 . V_241 ;
if ( ! V_14 -> V_218 )
F_13 ( V_42 L_347
L_348 ,
V_14 -> V_43 , F_21 ( V_37 -> V_46 ) ,
F_78 ( V_37 -> V_288 ) ) ;
}
V_89:
V_14 -> V_593 . V_243 = V_244 ;
F_128 ( & V_14 -> V_593 . V_263 ) ;
}
void F_292 ( struct V_757 * V_530 )
{
struct V_112 * V_113 = F_293 ( V_530 ) ;
struct V_13 * V_14 = F_67 ( V_113 ) ;
struct V_321 * V_322 , * V_758 ;
struct V_55 * V_56 , * V_369 ;
struct V_72 * V_118 ;
struct V_759 * V_760 ;
unsigned long V_76 ;
V_14 -> V_266 = 1 ;
F_147 ( V_14 ) ;
F_32 ( & V_14 -> V_306 , V_76 ) ;
V_760 = V_14 -> V_305 ;
V_14 -> V_305 = NULL ;
F_33 ( & V_14 -> V_306 , V_76 ) ;
if ( V_760 )
F_294 ( V_760 ) ;
F_291 ( V_14 ) ;
F_280 (raid_device, next, &ioc->raid_device_list,
list) {
if ( V_56 -> V_85 ) {
V_118 =
V_56 -> V_85 -> V_120 ;
V_118 -> V_340 = 1 ;
F_258 ( & V_56 -> V_85 -> V_127 ) ;
}
F_13 ( V_42 L_258 ,
V_14 -> V_43 , V_56 -> V_35 ,
( unsigned long long ) V_56 -> V_60 ) ;
F_55 ( V_14 , V_56 ) ;
}
F_280 (mpt3sas_port, next_port,
&ioc->sas_hba.sas_port_list, port_list) {
if ( V_322 -> V_324 . V_325 ==
V_326 )
F_44 ( V_14 ,
V_322 -> V_324 . V_17 ) ;
else if ( V_322 -> V_324 . V_325 ==
V_328 ||
V_322 -> V_324 . V_325 ==
V_329 )
F_237 ( V_14 ,
V_322 -> V_324 . V_17 ) ;
}
if ( V_14 -> V_39 . V_40 ) {
F_2 ( V_14 -> V_39 . V_222 ) ;
V_14 -> V_39 . V_222 = NULL ;
V_14 -> V_39 . V_40 = 0 ;
}
F_295 ( V_113 ) ;
F_296 ( V_113 ) ;
F_297 ( V_14 ) ;
F_14 ( & V_16 ) ;
F_56 ( & V_14 -> V_81 ) ;
F_16 ( & V_16 ) ;
F_298 ( V_113 ) ;
}
void
F_299 ( struct V_757 * V_530 )
{
struct V_112 * V_113 = F_293 ( V_530 ) ;
struct V_13 * V_14 = F_67 ( V_113 ) ;
struct V_759 * V_760 ;
unsigned long V_76 ;
V_14 -> V_266 = 1 ;
F_147 ( V_14 ) ;
F_32 ( & V_14 -> V_306 , V_76 ) ;
V_760 = V_14 -> V_305 ;
V_14 -> V_305 = NULL ;
F_33 ( & V_14 -> V_306 , V_76 ) ;
if ( V_760 )
F_294 ( V_760 ) ;
F_291 ( V_14 ) ;
F_297 ( V_14 ) ;
}
static void
F_300 ( struct V_13 * V_14 )
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
V_28 = F_256 ( V_14 -> V_113 , V_133 ,
V_56 -> V_87 , 0 ) ;
if ( V_28 )
F_55 ( V_14 , V_56 ) ;
} else {
F_32 ( & V_14 -> V_74 , V_76 ) ;
V_54 = V_51 ;
V_35 = V_54 -> V_35 ;
V_84 = V_54 -> V_84 ;
V_17 = V_54 -> V_17 ;
F_281 ( & V_54 -> V_81 , & V_14 -> V_83 ) ;
F_33 ( & V_14 -> V_74 , V_76 ) ;
if ( V_14 -> V_626 )
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
F_301 ( struct V_13 * V_14 )
{
struct V_55 * V_56 , * V_761 ;
int V_28 ;
F_280 (raid_device, raid_next,
&ioc->raid_device_list, list) {
if ( V_56 -> V_85 )
continue;
V_28 = F_256 ( V_14 -> V_113 , V_133 ,
V_56 -> V_87 , 0 ) ;
if ( V_28 )
F_55 ( V_14 , V_56 ) ;
}
}
static struct V_53 * F_302 ( struct V_13 * V_14 )
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
static void F_303 ( struct V_13 * V_14 ,
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
F_304 ( struct V_13 * V_14 )
{
struct V_53 * V_54 ;
if ( V_14 -> V_626 )
return;
while ( ( V_54 = F_302 ( V_14 ) ) ) {
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
F_303 ( V_14 , V_54 ) ;
F_41 ( V_54 ) ;
}
}
static void
F_305 ( struct V_13 * V_14 )
{
T_4 V_762 ;
if ( ! ( V_14 -> V_202 . V_763 & V_764 ) )
return;
F_300 ( V_14 ) ;
if ( V_14 -> V_713 ) {
V_762 =
F_21 ( V_14 -> V_765 . V_766 ) &
V_767 ;
if ( V_762 ==
V_768 ) {
F_301 ( V_14 ) ;
F_304 ( V_14 ) ;
} else {
F_304 ( V_14 ) ;
F_301 ( V_14 ) ;
}
} else
F_304 ( V_14 ) ;
}
void
F_306 ( struct V_112 * V_113 )
{
struct V_13 * V_14 = F_67 ( V_113 ) ;
int V_28 ;
if ( V_769 != - 1 && V_769 != 0 )
F_307 ( V_14 , V_769 ) ;
if ( V_668 > 0 )
return;
V_14 -> V_732 = 1 ;
V_28 = F_308 ( V_14 ) ;
if ( V_28 != 0 )
F_13 ( V_42 L_349 , V_14 -> V_43 ) ;
}
int
F_309 ( struct V_112 * V_113 , unsigned long time )
{
struct V_13 * V_14 = F_67 ( V_113 ) ;
if ( V_668 > 0 ) {
V_14 -> V_57 = 0 ;
V_14 -> V_625 = 0 ;
return 1 ;
}
if ( time >= ( 300 * V_285 ) ) {
V_14 -> V_770 . V_243 = V_244 ;
F_13 ( V_42
L_350 ,
V_14 -> V_43 ) ;
V_14 -> V_57 = 0 ;
return 1 ;
}
if ( V_14 -> V_732 )
return 0 ;
if ( V_14 -> V_771 ) {
F_13 ( V_42
L_351 ,
V_14 -> V_43 , V_14 -> V_771 ) ;
V_14 -> V_57 = 0 ;
V_14 -> V_625 = 0 ;
V_14 -> V_266 = 1 ;
return 1 ;
}
F_13 ( V_42 L_352 , V_14 -> V_43 ) ;
V_14 -> V_770 . V_243 = V_244 ;
if ( V_14 -> V_625 ) {
V_14 -> V_625 = 0 ;
F_305 ( V_14 ) ;
}
F_310 ( V_14 ) ;
V_14 -> V_57 = 0 ;
return 1 ;
}
T_4
F_311 ( struct V_757 * V_530 )
{
switch ( V_530 -> V_51 ) {
case V_772 :
case V_773 :
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
return V_160 ;
case V_789 :
case V_790 :
case V_791 :
case V_792 :
case V_793 :
case V_794 :
return V_162 ;
case V_795 :
case V_796 :
case V_797 :
case V_798 :
case V_799 :
case V_800 :
case V_801 :
case V_802 :
case V_803 :
case V_804 :
return V_163 ;
}
return 0 ;
}
int
F_312 ( struct V_757 * V_530 , const struct V_805 * V_87 )
{
struct V_13 * V_14 ;
struct V_112 * V_113 = NULL ;
int V_806 ;
T_4 V_807 ;
V_807 = F_311 ( V_530 ) ;
if ( V_807 == 0 )
return - V_808 ;
if ( ( V_809 == 1 ) && ( V_807 != V_160 ) )
return - V_808 ;
if ( ( V_809 == 2 ) && ( ! ( V_807 == V_162
|| V_807 == V_163 ) ) )
return - V_808 ;
switch ( V_807 ) {
case V_160 :
V_113 = F_313 ( & V_810 ,
sizeof( struct V_13 ) ) ;
if ( ! V_113 )
return - V_808 ;
V_14 = F_67 ( V_113 ) ;
memset ( V_14 , 0 , sizeof( struct V_13 ) ) ;
V_14 -> V_159 = V_807 ;
V_14 -> V_87 = V_811 ++ ;
sprintf ( V_14 -> V_812 , L_353 , V_813 ) ;
if ( V_530 -> V_51 == V_772 ) {
V_14 -> V_134 = 1 ;
V_14 -> V_218 = 1 ;
} else
V_14 -> V_814 = V_815 ;
break;
case V_162 :
case V_163 :
V_113 = F_313 ( & V_816 ,
sizeof( struct V_13 ) ) ;
if ( ! V_113 )
return - V_808 ;
V_14 = F_67 ( V_113 ) ;
memset ( V_14 , 0 , sizeof( struct V_13 ) ) ;
V_14 -> V_159 = V_807 ;
V_14 -> V_87 = V_817 ++ ;
sprintf ( V_14 -> V_812 , L_353 , V_818 ) ;
if ( ( V_14 -> V_159 == V_162 &&
V_530 -> V_819 >= V_820 ) ||
( V_14 -> V_159 == V_163 ) )
V_14 -> V_821 = 1 ;
break;
default:
return - V_808 ;
}
F_138 ( & V_14 -> V_81 ) ;
F_14 ( & V_16 ) ;
F_47 ( & V_14 -> V_81 , & V_822 ) ;
F_16 ( & V_16 ) ;
V_14 -> V_113 = V_113 ;
V_14 -> V_530 = V_530 ;
V_14 -> V_446 = V_446 ;
V_14 -> V_275 = V_275 ;
V_14 -> V_823 = V_823 ;
V_14 -> V_360 = V_360 ;
V_14 -> V_824 = V_824 ;
V_14 -> V_825 = V_825 ;
V_14 -> V_672 = V_672 ;
V_14 -> V_826 = V_826 ;
V_14 -> V_341 = V_341 ;
V_14 -> V_353 = V_353 ;
V_14 -> V_348 = V_348 ;
V_14 -> V_15 = V_15 ;
V_14 -> V_827 = & F_186 ;
F_314 ( & V_14 -> V_828 ) ;
F_314 ( & V_14 -> V_829 ) ;
F_315 ( & V_14 -> V_830 ) ;
F_315 ( & V_14 -> V_105 ) ;
F_315 ( & V_14 -> V_74 ) ;
F_315 ( & V_14 -> V_94 ) ;
F_315 ( & V_14 -> V_306 ) ;
F_315 ( & V_14 -> V_90 ) ;
F_315 ( & V_14 -> V_831 ) ;
F_138 ( & V_14 -> V_83 ) ;
F_138 ( & V_14 -> V_86 ) ;
F_138 ( & V_14 -> V_95 ) ;
F_138 ( & V_14 -> V_307 ) ;
F_138 ( & V_14 -> V_91 ) ;
F_138 ( & V_14 -> V_39 . V_592 ) ;
F_138 ( & V_14 -> V_342 ) ;
F_138 ( & V_14 -> V_349 ) ;
F_138 ( & V_14 -> V_368 ) ;
F_138 ( & V_14 -> V_354 ) ;
F_138 ( & V_14 -> V_832 ) ;
sprintf ( V_14 -> V_43 , L_354 , V_14 -> V_812 , V_14 -> V_87 ) ;
V_113 -> V_833 = 32 ;
V_113 -> V_834 = V_834 ;
V_113 -> V_835 = V_836 ;
V_113 -> V_837 = V_14 -> V_87 ;
if ( V_838 != 0xFFFF ) {
if ( V_838 < 64 ) {
V_113 -> V_838 = 64 ;
F_91 ( V_42 L_355 \
L_356
L_357 , V_14 -> V_43 , V_838 ) ;
} else if ( V_838 > 32767 ) {
V_113 -> V_838 = 32767 ;
F_91 ( V_42 L_355 \
L_356
L_358 , V_14 -> V_43 ,
V_838 ) ;
} else {
V_113 -> V_838 = V_838 & 0xFFFE ;
F_13 ( V_42
L_359 ,
V_14 -> V_43 , V_113 -> V_838 ) ;
}
}
if ( V_839 > 0 )
F_316 ( V_113 , V_839 ) ;
else
F_316 ( V_113 , V_840
| V_841
| V_842 ) ;
F_317 ( V_113 , V_843 ) ;
snprintf ( V_14 -> V_844 , sizeof( V_14 -> V_844 ) ,
L_360 , V_14 -> V_812 , V_14 -> V_87 ) ;
V_14 -> V_305 = F_318 (
V_14 -> V_844 , V_845 ) ;
if ( ! V_14 -> V_305 ) {
F_25 ( V_42 L_2 ,
V_14 -> V_43 , __FILE__ , __LINE__ , V_44 ) ;
V_806 = - V_808 ;
goto V_846;
}
V_14 -> V_57 = 1 ;
if ( ( F_319 ( V_14 ) ) ) {
F_25 ( V_42 L_2 ,
V_14 -> V_43 , __FILE__ , __LINE__ , V_44 ) ;
V_806 = - V_808 ;
goto V_847;
}
if ( V_14 -> V_134 ) {
if ( V_14 -> V_814 == V_815 )
V_14 -> V_626 = 0 ;
else if ( V_14 -> V_814 == V_848 )
V_14 -> V_626 = 1 ;
else {
if ( F_320 ( V_14 ) )
V_14 -> V_626 = 1 ;
else
V_14 -> V_626 = 0 ;
}
} else
V_14 -> V_626 = 0 ;
V_806 = F_321 ( V_113 , & V_530 -> V_127 ) ;
if ( V_806 ) {
F_25 ( V_42 L_2 ,
V_14 -> V_43 , __FILE__ , __LINE__ , V_44 ) ;
goto V_849;
}
F_322 ( V_113 ) ;
return 0 ;
V_849:
F_297 ( V_14 ) ;
V_847:
F_294 ( V_14 -> V_305 ) ;
V_846:
F_14 ( & V_16 ) ;
F_56 ( & V_14 -> V_81 ) ;
F_16 ( & V_16 ) ;
F_298 ( V_113 ) ;
return V_806 ;
}
int
F_323 ( struct V_757 * V_530 , T_50 V_167 )
{
struct V_112 * V_113 = F_293 ( V_530 ) ;
struct V_13 * V_14 = F_67 ( V_113 ) ;
T_51 V_850 ;
F_324 ( V_14 ) ;
F_325 () ;
F_326 ( V_113 ) ;
V_850 = F_327 ( V_530 , V_167 ) ;
F_13 ( V_42
L_361 ,
V_14 -> V_43 , V_530 , F_328 ( V_530 ) , V_850 ) ;
F_329 ( V_530 ) ;
F_330 ( V_14 ) ;
F_331 ( V_530 , V_850 ) ;
return 0 ;
}
int
F_332 ( struct V_757 * V_530 )
{
struct V_112 * V_113 = F_293 ( V_530 ) ;
struct V_13 * V_14 = F_67 ( V_113 ) ;
T_51 V_850 = V_530 -> V_851 ;
int V_2 ;
F_13 ( V_42
L_362 ,
V_14 -> V_43 , V_530 , F_328 ( V_530 ) , V_850 ) ;
F_331 ( V_530 , V_852 ) ;
F_333 ( V_530 , V_852 , 0 ) ;
F_334 ( V_530 ) ;
V_14 -> V_530 = V_530 ;
V_2 = F_335 ( V_14 ) ;
if ( V_2 )
return V_2 ;
F_116 ( V_14 , V_269 , V_853 ) ;
F_336 ( V_113 ) ;
F_310 ( V_14 ) ;
return 0 ;
}
T_52
F_337 ( struct V_757 * V_530 , T_53 V_167 )
{
struct V_112 * V_113 = F_293 ( V_530 ) ;
struct V_13 * V_14 = F_67 ( V_113 ) ;
F_13 ( V_42 L_363 ,
V_14 -> V_43 , V_167 ) ;
switch ( V_167 ) {
case V_854 :
return V_855 ;
case V_856 :
V_14 -> V_267 = 1 ;
F_326 ( V_14 -> V_113 ) ;
F_324 ( V_14 ) ;
F_330 ( V_14 ) ;
return V_857 ;
case V_858 :
V_14 -> V_267 = 1 ;
F_324 ( V_14 ) ;
F_186 ( V_14 ) ;
return V_859 ;
}
return V_857 ;
}
T_52
F_338 ( struct V_757 * V_530 )
{
struct V_112 * V_113 = F_293 ( V_530 ) ;
struct V_13 * V_14 = F_67 ( V_113 ) ;
int V_28 ;
F_13 ( V_42 L_364 ,
V_14 -> V_43 ) ;
V_14 -> V_267 = 0 ;
V_14 -> V_530 = V_530 ;
F_334 ( V_530 ) ;
V_28 = F_335 ( V_14 ) ;
if ( V_28 )
return V_859 ;
V_28 = F_116 ( V_14 , V_269 ,
V_270 ) ;
F_91 ( V_42 L_365 , V_14 -> V_43 ,
( V_28 == 0 ) ? L_123 : L_366 ) ;
if ( ! V_28 )
return V_860 ;
else
return V_859 ;
}
void
F_339 ( struct V_757 * V_530 )
{
struct V_112 * V_113 = F_293 ( V_530 ) ;
struct V_13 * V_14 = F_67 ( V_113 ) ;
F_13 ( V_42 L_367 , V_14 -> V_43 ) ;
F_340 ( V_530 ) ;
F_310 ( V_14 ) ;
F_336 ( V_14 -> V_113 ) ;
}
T_52
F_341 ( struct V_757 * V_530 )
{
struct V_112 * V_113 = F_293 ( V_530 ) ;
struct V_13 * V_14 = F_67 ( V_113 ) ;
F_13 ( V_42 L_368 ,
V_14 -> V_43 ) ;
return V_857 ;
}
int
F_342 ( void )
{
V_811 = 0 ;
V_817 = 0 ;
F_343 () ;
V_446 = F_344 ( F_214 ) ;
V_275 = F_344 ( F_105 ) ;
V_360 = F_344 ( V_861 ) ;
V_824 = F_344 (
V_862 ) ;
V_825 = F_344 (
V_863 ) ;
V_672 = F_344 ( F_239 ) ;
V_826 = F_344 (
V_864 ) ;
V_823 = F_344 ( V_865 ) ;
V_341 = F_344 (
F_162 ) ;
V_353 = F_344 (
F_171 ) ;
V_348 = F_344 (
F_167 ) ;
return 0 ;
}
void
F_345 ( void )
{
F_346 ( V_446 ) ;
F_346 ( V_275 ) ;
F_346 ( V_360 ) ;
F_346 ( V_824 ) ;
F_346 ( V_825 ) ;
F_346 ( V_672 ) ;
F_346 ( V_826 ) ;
F_346 ( V_823 ) ;
F_346 ( V_341 ) ;
F_346 ( V_353 ) ;
F_346 ( V_348 ) ;
if ( V_809 != 1 )
F_347 ( V_164 ) ;
if ( V_809 != 2 )
F_347 ( V_161 ) ;
F_348 ( V_836 ) ;
}
static int T_54
F_349 ( void )
{
int error ;
F_13 ( L_369 , V_818 ,
V_866 ) ;
V_836 =
F_350 ( & V_867 ) ;
if ( ! V_836 )
return - V_808 ;
if ( V_809 != 1 ) {
V_164 =
F_351 ( & V_868 ) ;
if ( ! V_164 ) {
F_348 ( V_836 ) ;
return - V_808 ;
}
}
if ( V_809 != 2 ) {
V_161 =
F_351 ( & V_869 ) ;
if ( ! V_161 ) {
F_348 ( V_836 ) ;
return - V_808 ;
}
}
error = F_342 () ;
if ( error ) {
F_345 () ;
return error ;
}
F_352 ( V_809 ) ;
error = F_353 ( & V_870 ) ;
if ( error )
F_345 () ;
return error ;
}
static void T_55
F_354 ( void )
{
F_13 ( L_370 ,
V_866 ) ;
F_355 ( & V_870 ) ;
F_356 ( V_809 ) ;
F_345 () ;
}
