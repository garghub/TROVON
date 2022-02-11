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
int
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
T_16 V_87 , T_16 V_109 , T_6 type , T_4 V_256 , T_14 V_257 ,
enum V_258 V_259 )
{
T_17 * V_260 ;
T_18 * V_37 ;
T_4 V_102 = 0 ;
T_10 V_261 ;
unsigned long V_262 ;
struct V_263 * V_103 = NULL ;
int V_28 ;
T_4 V_264 = 0 ;
if ( V_259 == V_265 )
F_113 ( & V_14 -> V_245 . V_266 ) ;
if ( V_14 -> V_245 . V_246 != V_247 ) {
F_13 ( V_42 L_49 ,
V_44 , V_14 -> V_43 ) ;
V_28 = V_267 ;
goto V_268;
}
if ( V_14 -> V_82 || V_14 -> V_269 ||
V_14 -> V_270 ) {
F_13 ( V_42 L_50 ,
V_44 , V_14 -> V_43 ) ;
V_28 = V_267 ;
goto V_268;
}
V_261 = F_114 ( V_14 , 0 ) ;
if ( V_261 & V_271 ) {
F_115 ( V_14 , F_13 ( V_42
L_51 , V_14 -> V_43 ) ) ;
V_28 = F_116 ( V_14 , V_272 ,
V_273 ) ;
V_28 = ( ! V_28 ) ? V_274 : V_267 ;
goto V_268;
}
if ( ( V_261 & V_275 ) == V_276 ) {
F_117 ( V_14 , V_261 &
V_277 ) ;
V_28 = F_116 ( V_14 , V_272 ,
V_273 ) ;
V_28 = ( ! V_28 ) ? V_274 : V_267 ;
goto V_268;
}
V_102 = F_118 ( V_14 , V_14 -> V_278 ) ;
if ( ! V_102 ) {
F_25 ( V_42 L_52 ,
V_14 -> V_43 , V_44 ) ;
V_28 = V_267 ;
goto V_268;
}
if ( type == V_279 )
V_103 = & V_14 -> V_103 [ V_256 - 1 ] ;
F_119 ( V_14 , F_13 ( V_42
L_53 ,
V_14 -> V_43 , V_35 , type , V_256 ) ) ;
V_14 -> V_245 . V_246 = V_251 ;
V_260 = F_120 ( V_14 , V_102 ) ;
V_14 -> V_245 . V_102 = V_102 ;
memset ( V_260 , 0 , sizeof( T_17 ) ) ;
memset ( V_14 -> V_245 . V_244 , 0 , sizeof( T_18 ) ) ;
V_260 -> V_280 = V_281 ;
V_260 -> V_200 = F_121 ( V_35 ) ;
V_260 -> V_282 = type ;
V_260 -> V_283 = F_121 ( V_256 ) ;
F_122 ( V_109 , (struct V_284 * ) V_260 -> V_285 ) ;
F_109 ( V_14 , V_35 ) ;
F_123 ( & V_14 -> V_245 . V_252 ) ;
if ( ( type == V_279 ) &&
( V_103 -> V_286 < V_14 -> V_287 ) )
V_264 = V_103 -> V_286 ;
else
V_264 = 0 ;
F_124 ( V_14 , V_102 , V_264 ) ;
V_262 = F_125 ( & V_14 -> V_245 . V_252 , V_257 * V_288 ) ;
if ( ! ( V_14 -> V_245 . V_246 & V_248 ) ) {
F_25 ( V_42 L_54 ,
V_14 -> V_43 , V_44 ) ;
F_126 ( V_260 ,
sizeof( T_17 ) / 4 ) ;
if ( ! ( V_14 -> V_245 . V_246 & V_289 ) ) {
V_28 = F_116 ( V_14 , V_272 ,
V_273 ) ;
V_28 = ( ! V_28 ) ? V_274 : V_267 ;
V_14 -> V_245 . V_246 = V_247 ;
F_111 ( V_14 , V_35 ) ;
goto V_268;
}
}
F_127 ( V_14 ) ;
if ( V_14 -> V_245 . V_246 & V_250 ) {
F_128 ( V_14 , V_290 ) ;
V_37 = V_14 -> V_245 . V_244 ;
F_119 ( V_14 , F_13 ( V_42 L_55 \
L_56 ,
V_14 -> V_43 , F_21 ( V_37 -> V_46 ) ,
F_78 ( V_37 -> V_291 ) ,
F_78 ( V_37 -> V_292 ) ) ) ;
if ( V_14 -> V_15 & V_293 ) {
F_105 ( V_14 , V_37 -> V_294 ) ;
if ( V_37 -> V_46 )
F_126 ( V_260 ,
sizeof( T_17 ) / 4 ) ;
}
}
switch ( type ) {
case V_279 :
V_28 = V_274 ;
if ( V_103 -> V_104 == NULL )
break;
V_28 = V_267 ;
break;
case V_295 :
if ( F_64 ( V_14 , V_87 , V_88 ) )
V_28 = V_267 ;
else
V_28 = V_274 ;
break;
case V_296 :
case V_297 :
if ( F_65 ( V_14 , V_87 , V_109 , V_88 ) )
V_28 = V_267 ;
else
V_28 = V_274 ;
break;
case V_298 :
V_28 = V_274 ;
break;
default:
V_28 = V_267 ;
break;
}
F_111 ( V_14 , V_35 ) ;
V_14 -> V_245 . V_246 = V_247 ;
if ( V_259 == V_265 )
F_129 ( & V_14 -> V_245 . V_266 ) ;
return V_28 ;
V_268:
if ( V_259 == V_265 )
F_129 ( & V_14 -> V_245 . V_266 ) ;
return V_28 ;
}
static void
F_130 ( struct V_13 * V_14 , struct V_101 * V_104 )
{
struct V_126 * V_85 = V_104 -> V_51 -> V_299 ;
struct V_72 * V_300 = V_85 -> V_120 ;
struct V_53 * V_54 = NULL ;
unsigned long V_76 ;
char * V_301 = NULL ;
if ( ! V_300 )
return;
if ( V_14 -> V_218 )
V_301 = L_57 ;
else
V_301 = L_58 ;
F_131 ( V_104 ) ;
if ( V_300 -> V_76 & V_123 ) {
F_132 ( V_144 , V_85 ,
L_59 ,
V_301 , V_300 -> V_35 ,
V_301 , ( unsigned long long ) V_300 -> V_17 ) ;
} else {
F_32 ( & V_14 -> V_74 , V_76 ) ;
V_54 = F_28 ( V_14 , V_300 ) ;
if ( V_54 ) {
if ( V_300 -> V_76 &
V_138 ) {
F_132 ( V_144 , V_85 ,
L_60
L_61 ,
V_54 -> V_208 ,
( unsigned long long ) V_54 -> V_209 ) ;
}
F_132 ( V_144 , V_85 ,
L_62 ,
V_54 -> V_35 ,
( unsigned long long ) V_54 -> V_17 ,
V_54 -> V_225 ) ;
if ( V_54 -> V_78 != 0 )
F_132 ( V_144 , V_85 ,
L_63 ,
( unsigned long long )
V_54 -> V_22 ,
V_54 -> V_26 ) ;
if ( V_54 -> V_79 [ 0 ] != '\0' )
F_132 ( V_144 , V_85 ,
L_64 ,
V_54 -> V_80 ,
V_54 -> V_79 ) ;
F_41 ( V_54 ) ;
}
F_33 ( & V_14 -> V_74 , V_76 ) ;
}
}
int
F_133 ( struct V_101 * V_104 )
{
struct V_13 * V_14 = F_67 ( V_104 -> V_51 -> V_114 ) ;
struct V_116 * V_117 ;
T_4 V_102 ;
T_4 V_35 ;
int V_2 ;
F_75 ( V_144 , V_104 -> V_51 ,
L_65 , V_104 ) ;
F_130 ( V_14 , V_104 ) ;
V_117 = V_104 -> V_51 -> V_120 ;
if ( ! V_117 || ! V_117 -> V_122 ) {
F_75 ( V_144 , V_104 -> V_51 ,
L_66 , V_104 ) ;
V_104 -> V_302 = V_303 << 16 ;
V_104 -> V_304 ( V_104 ) ;
V_2 = V_274 ;
goto V_89;
}
V_102 = F_63 ( V_14 , V_104 ) ;
if ( ! V_102 ) {
V_104 -> V_302 = V_305 << 16 ;
V_2 = V_274 ;
goto V_89;
}
if ( V_117 -> V_122 -> V_76 &
V_138 ||
V_117 -> V_122 -> V_76 & V_123 ) {
V_104 -> V_302 = V_305 << 16 ;
V_2 = V_267 ;
goto V_89;
}
F_134 ( V_14 ) ;
V_35 = V_117 -> V_122 -> V_35 ;
V_2 = F_112 ( V_14 , V_35 , V_104 -> V_51 -> V_88 ,
V_104 -> V_51 -> V_87 , V_104 -> V_51 -> V_109 ,
V_279 , V_102 , 30 , V_265 ) ;
V_89:
F_75 ( V_144 , V_104 -> V_51 , L_67 ,
( ( V_2 == V_274 ) ? L_68 : L_69 ) , V_104 ) ;
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
struct V_126 * V_85 = V_104 -> V_51 -> V_299 ;
struct V_72 * V_306 = V_85 -> V_120 ;
F_75 ( V_144 , V_104 -> V_51 ,
L_70 , V_104 ) ;
F_130 ( V_14 , V_104 ) ;
V_117 = V_104 -> V_51 -> V_120 ;
if ( ! V_117 || ! V_117 -> V_122 ) {
F_75 ( V_144 , V_104 -> V_51 ,
L_66 , V_104 ) ;
V_104 -> V_302 = V_303 << 16 ;
V_104 -> V_304 ( V_104 ) ;
V_2 = V_274 ;
goto V_89;
}
V_35 = 0 ;
if ( V_117 -> V_122 -> V_76 &
V_138 ) {
V_54 = F_31 ( V_14 ,
V_306 ) ;
if ( V_54 )
V_35 = V_54 -> V_208 ;
} else
V_35 = V_117 -> V_122 -> V_35 ;
if ( ! V_35 ) {
V_104 -> V_302 = V_305 << 16 ;
V_2 = V_267 ;
goto V_89;
}
V_2 = F_112 ( V_14 , V_35 , V_104 -> V_51 -> V_88 ,
V_104 -> V_51 -> V_87 , V_104 -> V_51 -> V_109 ,
V_297 , 0 , 30 , V_265 ) ;
V_89:
F_75 ( V_144 , V_104 -> V_51 , L_71 ,
( ( V_2 == V_274 ) ? L_68 : L_69 ) , V_104 ) ;
if ( V_54 )
F_41 ( V_54 ) ;
return V_2 ;
}
int
F_136 ( struct V_101 * V_104 )
{
struct V_13 * V_14 = F_67 ( V_104 -> V_51 -> V_114 ) ;
struct V_116 * V_117 ;
struct V_53 * V_54 = NULL ;
T_4 V_35 ;
int V_2 ;
struct V_126 * V_85 = V_104 -> V_51 -> V_299 ;
struct V_72 * V_306 = V_85 -> V_120 ;
F_132 ( V_144 , V_85 , L_72 ,
V_104 ) ;
F_130 ( V_14 , V_104 ) ;
V_117 = V_104 -> V_51 -> V_120 ;
if ( ! V_117 || ! V_117 -> V_122 ) {
F_132 ( V_144 , V_85 , L_73 ,
V_104 ) ;
V_104 -> V_302 = V_303 << 16 ;
V_104 -> V_304 ( V_104 ) ;
V_2 = V_274 ;
goto V_89;
}
V_35 = 0 ;
if ( V_117 -> V_122 -> V_76 &
V_138 ) {
V_54 = F_31 ( V_14 ,
V_306 ) ;
if ( V_54 )
V_35 = V_54 -> V_208 ;
} else
V_35 = V_117 -> V_122 -> V_35 ;
if ( ! V_35 ) {
V_104 -> V_302 = V_305 << 16 ;
V_2 = V_267 ;
goto V_89;
}
V_2 = F_112 ( V_14 , V_35 , V_104 -> V_51 -> V_88 ,
V_104 -> V_51 -> V_87 , 0 , V_295 , 0 ,
30 , V_265 ) ;
V_89:
F_132 ( V_144 , V_85 , L_74 ,
( ( V_2 == V_274 ) ? L_68 : L_69 ) , V_104 ) ;
if ( V_54 )
F_41 ( V_54 ) ;
return V_2 ;
}
int
F_137 ( struct V_101 * V_104 )
{
struct V_13 * V_14 = F_67 ( V_104 -> V_51 -> V_114 ) ;
int V_2 , V_307 ;
F_13 ( V_42 L_75 ,
V_14 -> V_43 , V_104 ) ;
F_131 ( V_104 ) ;
if ( V_14 -> V_57 ) {
F_13 ( V_42 L_76 ,
V_14 -> V_43 ) ;
V_2 = V_267 ;
goto V_89;
}
V_307 = F_116 ( V_14 , V_272 ,
V_273 ) ;
V_2 = ( V_307 < 0 ) ? V_267 : V_274 ;
V_89:
F_13 ( V_42 L_77 ,
V_14 -> V_43 , ( ( V_2 == V_274 ) ? L_68 : L_69 ) , V_104 ) ;
return V_2 ;
}
static void
F_138 ( struct V_13 * V_14 , struct V_3 * V_7 )
{
unsigned long V_76 ;
if ( V_14 -> V_308 == NULL )
return;
F_32 ( & V_14 -> V_309 , V_76 ) ;
F_4 ( V_7 ) ;
F_139 ( & V_7 -> V_81 ) ;
F_47 ( & V_7 -> V_81 , & V_14 -> V_310 ) ;
F_140 ( & V_7 -> V_311 , V_312 ) ;
F_4 ( V_7 ) ;
F_141 ( V_14 -> V_308 , & V_7 -> V_311 ) ;
F_33 ( & V_14 -> V_309 , V_76 ) ;
}
static void
F_142 ( struct V_13 * V_14 , struct V_3
* V_7 )
{
unsigned long V_76 ;
F_32 ( & V_14 -> V_309 , V_76 ) ;
if ( ! F_39 ( & V_7 -> V_81 ) ) {
F_40 ( & V_7 -> V_81 ) ;
F_6 ( V_7 ) ;
}
F_33 ( & V_14 -> V_309 , V_76 ) ;
}
void
F_143 ( struct V_13 * V_14 ,
struct V_313 * V_314 )
{
struct V_3 * V_7 ;
T_4 V_193 ;
if ( V_14 -> V_57 )
return;
V_193 = sizeof( * V_314 ) ;
V_7 = F_8 ( V_193 ) ;
if ( ! V_7 )
return;
V_7 -> V_315 = V_316 ;
V_7 -> V_14 = V_14 ;
memcpy ( V_7 -> V_314 , V_314 , sizeof( * V_314 ) ) ;
F_138 ( V_14 , V_7 ) ;
F_6 ( V_7 ) ;
}
static void
F_144 ( struct V_13 * V_14 )
{
struct V_3 * V_7 ;
if ( V_14 -> V_57 )
return;
V_7 = F_8 ( 0 ) ;
if ( ! V_7 )
return;
V_7 -> V_315 = V_317 ;
V_7 -> V_14 = V_14 ;
F_138 ( V_14 , V_7 ) ;
F_6 ( V_7 ) ;
}
void
F_145 ( struct V_13 * V_14 )
{
struct V_3 * V_7 ;
V_7 = F_8 ( 0 ) ;
if ( ! V_7 )
return;
V_7 -> V_315 = V_318 ;
V_7 -> V_14 = V_14 ;
F_138 ( V_14 , V_7 ) ;
F_6 ( V_7 ) ;
}
static struct V_3 * F_146 ( struct V_13 * V_14 )
{
unsigned long V_76 ;
struct V_3 * V_7 = NULL ;
F_32 ( & V_14 -> V_309 , V_76 ) ;
if ( ! F_39 ( & V_14 -> V_310 ) ) {
V_7 = F_147 ( & V_14 -> V_310 ,
struct V_3 , V_81 ) ;
F_40 ( & V_7 -> V_81 ) ;
}
F_33 ( & V_14 -> V_309 , V_76 ) ;
return V_7 ;
}
static void
F_148 ( struct V_13 * V_14 )
{
struct V_3 * V_7 ;
if ( F_39 ( & V_14 -> V_310 ) ||
! V_14 -> V_308 || F_149 () )
return;
while ( ( V_7 = F_146 ( V_14 ) ) ) {
if ( F_150 ( & V_7 -> V_311 ) )
F_6 ( V_7 ) ;
F_6 ( V_7 ) ;
}
}
static void
F_151 ( struct V_110 * V_75 ,
struct V_116 * V_117 )
{
int V_2 = 0 ;
F_75 ( V_144 , V_75 , L_78 ,
V_117 -> V_122 -> V_35 ) ;
V_117 -> V_319 = 1 ;
V_2 = F_152 ( V_75 ) ;
if ( V_2 == - V_320 )
F_75 ( V_223 , V_75 ,
L_79 ,
V_117 -> V_122 -> V_35 , V_2 ) ;
}
static void
F_153 ( struct V_110 * V_75 ,
struct V_116 * V_117 )
{
int V_2 = 0 ;
F_75 ( V_223 , V_75 , L_80
L_81 , V_117 -> V_122 -> V_35 ) ;
V_117 -> V_319 = 0 ;
V_2 = F_154 ( V_75 , V_321 ) ;
if ( V_2 == - V_320 ) {
F_75 ( V_223 , V_75 ,
L_82
L_83 ,
V_117 -> V_122 -> V_35 , V_2 ) ;
V_117 -> V_319 = 1 ;
V_2 = F_152 ( V_75 ) ;
if ( V_2 )
F_75 ( V_223 , V_75 , L_84
L_85 ,
V_117 -> V_122 -> V_35 , V_2 ) ;
V_117 -> V_319 = 0 ;
V_2 = F_154 ( V_75 , V_321 ) ;
if ( V_2 )
F_75 ( V_223 , V_75 , L_86
L_87 ,
V_117 -> V_122 -> V_35 , V_2 ) ;
}
}
static void
F_155 ( struct V_13 * V_14 )
{
struct V_116 * V_117 ;
struct V_110 * V_75 ;
F_110 (sdev, ioc->shost) {
V_117 = V_75 -> V_120 ;
if ( ! V_117 )
continue;
if ( ! V_117 -> V_319 )
continue;
F_46 ( V_14 , F_75 ( V_144 , V_75 ,
L_88 ,
V_117 -> V_122 -> V_35 ) ) ;
F_153 ( V_75 , V_117 ) ;
}
}
static void
F_156 ( struct V_13 * V_14 , T_1 V_17 )
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
if ( V_117 -> V_319 )
F_153 ( V_75 ,
V_117 ) ;
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
if ( V_117 -> V_319 )
continue;
if ( V_117 -> V_224 ) {
F_75 ( V_144 , V_75 ,
L_89 ,
V_44 , V_117 -> V_122 -> V_35 ) ;
continue;
}
F_151 ( V_75 , V_117 ) ;
}
}
static void
F_158 ( struct V_13 * V_14 , T_4 V_35 )
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
if ( V_117 -> V_319 )
continue;
if ( V_54 -> V_322 )
continue;
if ( V_117 -> V_224 ) {
F_75 ( V_144 , V_75 ,
L_89 ,
V_44 , V_117 -> V_122 -> V_35 ) ;
continue;
}
F_151 ( V_75 , V_117 ) ;
}
F_41 ( V_54 ) ;
}
static void
F_159 ( struct V_13 * V_14 ,
struct V_92 * V_93 )
{
struct V_323 * V_324 ;
struct V_53 * V_54 ;
struct V_92 * V_325 ;
unsigned long V_76 ;
if ( ! V_93 )
return;
F_15 (mpt3sas_port,
&sas_expander->sas_port_list, port_list) {
if ( V_324 -> V_326 . V_327 ==
V_328 ) {
F_32 ( & V_14 -> V_74 , V_76 ) ;
V_54 = F_34 ( V_14 ,
V_324 -> V_326 . V_17 ) ;
if ( V_54 ) {
F_160 ( V_54 -> V_35 ,
V_14 -> V_329 ) ;
F_41 ( V_54 ) ;
}
F_33 ( & V_14 -> V_74 , V_76 ) ;
}
}
F_15 (mpt3sas_port,
&sas_expander->sas_port_list, port_list) {
if ( V_324 -> V_326 . V_327 ==
V_330 ||
V_324 -> V_326 . V_327 ==
V_331 ) {
V_325 =
F_58 (
V_14 , V_324 -> V_326 . V_17 ) ;
F_159 ( V_14 ,
V_325 ) ;
}
}
}
static void
F_161 ( struct V_13 * V_14 ,
T_19 * V_314 )
{
int V_106 ;
T_4 V_35 ;
T_4 V_332 ;
for ( V_106 = 0 ; V_106 < V_314 -> V_333 ; V_106 ++ ) {
V_35 = F_21 ( V_314 -> V_334 [ V_106 ] . V_335 ) ;
if ( ! V_35 )
continue;
V_332 = V_314 -> V_334 [ V_106 ] . V_336 &
V_337 ;
if ( V_332 == V_338 )
F_158 ( V_14 , V_35 ) ;
}
}
static void
F_162 ( struct V_13 * V_14 , T_4 V_35 )
{
T_17 * V_260 ;
T_4 V_102 ;
struct V_53 * V_54 = NULL ;
struct V_72 * V_118 = NULL ;
T_1 V_17 = 0 ;
unsigned long V_76 ;
struct V_339 * V_340 ;
T_10 V_261 ;
if ( V_14 -> V_269 ) {
F_46 ( V_14 , F_13 ( V_42
L_90 ,
V_44 , V_14 -> V_43 , V_35 ) ) ;
return;
} else if ( V_14 -> V_270 ) {
F_46 ( V_14 , F_13 ( V_42
L_91 ,
V_44 , V_14 -> V_43 ,
V_35 ) ) ;
return;
}
V_261 = F_114 ( V_14 , 1 ) ;
if ( V_261 != V_341 ) {
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
V_118 -> V_342 = 1 ;
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
F_156 ( V_14 , V_17 ) ;
V_118 -> V_35 = V_132 ;
}
V_102 = F_118 ( V_14 , V_14 -> V_343 ) ;
if ( ! V_102 ) {
V_340 = F_9 ( sizeof( * V_340 ) , V_8 ) ;
if ( ! V_340 )
goto V_89;
F_139 ( & V_340 -> V_81 ) ;
V_340 -> V_35 = V_35 ;
F_47 ( & V_340 -> V_81 , & V_14 -> V_344 ) ;
F_46 ( V_14 , F_13 ( V_42
L_98 ,
V_14 -> V_43 , V_35 ) ) ;
goto V_89;
}
F_46 ( V_14 , F_13 ( V_42
L_99 ,
V_14 -> V_43 , V_35 , V_102 ,
V_14 -> V_343 ) ) ;
V_260 = F_120 ( V_14 , V_102 ) ;
memset ( V_260 , 0 , sizeof( T_17 ) ) ;
V_260 -> V_280 = V_281 ;
V_260 -> V_200 = F_121 ( V_35 ) ;
V_260 -> V_282 = V_295 ;
F_124 ( V_14 , V_102 , 0 ) ;
F_128 ( V_14 , V_345 ) ;
V_89:
if ( V_54 )
F_41 ( V_54 ) ;
}
static T_6
F_163 ( struct V_13 * V_14 , T_4 V_102 , T_6 V_243 ,
T_10 V_244 )
{
T_4 V_35 ;
T_17 * V_346 ;
T_18 * V_37 =
F_107 ( V_14 , V_244 ) ;
T_20 * V_260 ;
T_4 V_347 ;
T_10 V_261 ;
struct V_348 * V_349 ;
if ( V_14 -> V_269 ) {
F_46 ( V_14 , F_13 ( V_42
L_100 , V_44 , V_14 -> V_43 ) ) ;
return 1 ;
} else if ( V_14 -> V_270 ) {
F_46 ( V_14 , F_13 ( V_42
L_101 , V_44 ,
V_14 -> V_43 ) ) ;
return 1 ;
}
V_261 = F_114 ( V_14 , 1 ) ;
if ( V_261 != V_341 ) {
F_46 ( V_14 , F_13 ( V_42
L_102 , V_44 , V_14 -> V_43 ) ) ;
return 1 ;
}
if ( F_164 ( ! V_37 ) ) {
F_25 ( V_42 L_103 ,
V_14 -> V_43 , __FILE__ , __LINE__ , V_44 ) ;
return 1 ;
}
V_346 = F_120 ( V_14 , V_102 ) ;
V_35 = F_21 ( V_346 -> V_200 ) ;
if ( V_35 != F_21 ( V_37 -> V_200 ) ) {
F_46 ( V_14 , F_25 ( V_42
L_104 ,
V_14 -> V_43 , V_35 ,
F_21 ( V_37 -> V_200 ) , V_102 ) ) ;
return 0 ;
}
F_128 ( V_14 , V_290 ) ;
F_46 ( V_14 , F_13 ( V_42
L_105
L_106 , V_14 -> V_43 ,
V_35 , V_102 , F_21 ( V_37 -> V_46 ) ,
F_78 ( V_37 -> V_291 ) ,
F_78 ( V_37 -> V_292 ) ) ) ;
V_347 = F_165 ( V_14 , V_14 -> V_350 ) ;
if ( ! V_347 ) {
V_349 = F_9 ( sizeof( * V_349 ) , V_8 ) ;
if ( ! V_349 )
return F_166 ( V_14 , V_102 ) ;
F_139 ( & V_349 -> V_81 ) ;
V_349 -> V_35 = V_346 -> V_200 ;
F_47 ( & V_349 -> V_81 , & V_14 -> V_351 ) ;
F_46 ( V_14 , F_13 ( V_42
L_107 ,
V_14 -> V_43 , V_35 ) ) ;
return F_166 ( V_14 , V_102 ) ;
}
F_46 ( V_14 , F_13 ( V_42
L_108 ,
V_14 -> V_43 , V_35 , V_347 ,
V_14 -> V_350 ) ) ;
V_260 = F_120 ( V_14 , V_347 ) ;
memset ( V_260 , 0 , sizeof( T_20 ) ) ;
V_260 -> V_280 = V_352 ;
V_260 -> V_353 = V_354 ;
V_260 -> V_200 = V_346 -> V_200 ;
F_167 ( V_14 , V_347 ) ;
return F_166 ( V_14 , V_102 ) ;
}
static T_6
F_168 ( struct V_13 * V_14 , T_4 V_102 ,
T_6 V_243 , T_10 V_244 )
{
T_21 * V_37 =
F_107 ( V_14 , V_244 ) ;
if ( F_169 ( V_37 ) ) {
F_46 ( V_14 , F_13 ( V_42
L_109
L_110 ,
V_14 -> V_43 , F_21 ( V_37 -> V_200 ) , V_102 ,
F_21 ( V_37 -> V_46 ) ,
F_78 ( V_37 -> V_291 ) ) ) ;
} else {
F_25 ( V_42 L_103 ,
V_14 -> V_43 , __FILE__ , __LINE__ , V_44 ) ;
}
return F_170 ( V_14 , V_102 ) ;
}
static void
F_171 ( struct V_13 * V_14 , T_4 V_35 )
{
T_17 * V_260 ;
T_4 V_102 ;
struct V_339 * V_340 ;
if ( V_14 -> V_82 || V_14 -> V_269 ||
V_14 -> V_270 ) {
F_46 ( V_14 , F_13 ( V_42
L_50 ,
V_44 , V_14 -> V_43 ) ) ;
return;
}
V_102 = F_118 ( V_14 , V_14 -> V_355 ) ;
if ( ! V_102 ) {
V_340 = F_9 ( sizeof( * V_340 ) , V_8 ) ;
if ( ! V_340 )
return;
F_139 ( & V_340 -> V_81 ) ;
V_340 -> V_35 = V_35 ;
F_47 ( & V_340 -> V_81 , & V_14 -> V_356 ) ;
F_46 ( V_14 , F_13 ( V_42
L_98 ,
V_14 -> V_43 , V_35 ) ) ;
return;
}
F_46 ( V_14 , F_13 ( V_42
L_99 ,
V_14 -> V_43 , V_35 , V_102 ,
V_14 -> V_355 ) ) ;
V_260 = F_120 ( V_14 , V_102 ) ;
memset ( V_260 , 0 , sizeof( T_17 ) ) ;
V_260 -> V_280 = V_281 ;
V_260 -> V_200 = F_121 ( V_35 ) ;
V_260 -> V_282 = V_295 ;
F_124 ( V_14 , V_102 , 0 ) ;
}
static T_6
F_172 ( struct V_13 * V_14 , T_4 V_102 ,
T_6 V_243 , T_10 V_244 )
{
T_4 V_35 ;
T_17 * V_346 ;
T_18 * V_37 =
F_107 ( V_14 , V_244 ) ;
if ( V_14 -> V_82 || V_14 -> V_269 ||
V_14 -> V_270 ) {
F_46 ( V_14 , F_13 ( V_42
L_50 ,
V_44 , V_14 -> V_43 ) ) ;
return 1 ;
}
if ( F_164 ( ! V_37 ) ) {
F_25 ( V_42 L_103 ,
V_14 -> V_43 , __FILE__ , __LINE__ , V_44 ) ;
return 1 ;
}
V_346 = F_120 ( V_14 , V_102 ) ;
V_35 = F_21 ( V_346 -> V_200 ) ;
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
F_78 ( V_37 -> V_291 ) ,
F_78 ( V_37 -> V_292 ) ) ) ;
return F_166 ( V_14 , V_102 ) ;
}
void
F_173 ( struct V_13 * V_14 , T_4 V_102 , T_4 V_315 ,
T_10 V_357 )
{
T_22 * V_358 ;
int V_106 = V_102 - V_14 -> V_359 ;
unsigned long V_76 ;
F_32 ( & V_14 -> V_105 , V_76 ) ;
V_14 -> V_360 [ V_106 ] . V_361 = V_14 -> V_362 ;
F_33 ( & V_14 -> V_105 , V_76 ) ;
F_46 ( V_14 , F_13 ( V_42
L_111 ,
V_14 -> V_43 , F_21 ( V_315 ) , V_102 ,
V_14 -> V_362 ) ) ;
V_358 = F_120 ( V_14 , V_102 ) ;
memset ( V_358 , 0 , sizeof( T_22 ) ) ;
V_358 -> V_280 = V_363 ;
V_358 -> V_364 = V_315 ;
V_358 -> V_365 = V_357 ;
V_358 -> V_366 = 0 ;
V_358 -> V_367 = 0 ;
F_167 ( V_14 , V_102 ) ;
}
void
F_174 ( struct V_13 * V_14 ,
T_4 V_102 , T_4 V_35 )
{
T_20 * V_260 ;
T_10 V_261 ;
int V_106 = V_102 - V_14 -> V_359 ;
unsigned long V_76 ;
if ( V_14 -> V_269 ) {
F_46 ( V_14 , F_13 ( V_42
L_100 ,
V_44 , V_14 -> V_43 ) ) ;
return;
} else if ( V_14 -> V_270 ) {
F_46 ( V_14 , F_13 ( V_42
L_101 ,
V_44 , V_14 -> V_43 ) ) ;
return;
}
V_261 = F_114 ( V_14 , 1 ) ;
if ( V_261 != V_341 ) {
F_46 ( V_14 , F_13 ( V_42
L_102 ,
V_44 , V_14 -> V_43 ) ) ;
return;
}
F_32 ( & V_14 -> V_105 , V_76 ) ;
V_14 -> V_360 [ V_106 ] . V_361 = V_14 -> V_350 ;
F_33 ( & V_14 -> V_105 , V_76 ) ;
F_46 ( V_14 , F_13 ( V_42
L_108 ,
V_14 -> V_43 , F_21 ( V_35 ) , V_102 ,
V_14 -> V_350 ) ) ;
V_260 = F_120 ( V_14 , V_102 ) ;
memset ( V_260 , 0 , sizeof( T_20 ) ) ;
V_260 -> V_280 = V_352 ;
V_260 -> V_353 = V_354 ;
V_260 -> V_200 = V_35 ;
F_167 ( V_14 , V_102 ) ;
}
T_6
F_170 ( struct V_13 * V_14 , T_4 V_102 )
{
struct V_348 * V_349 ;
struct V_368 * V_369 ;
if ( ! F_39 ( & V_14 -> V_370 ) ) {
V_369 = F_175 ( V_14 -> V_370 . V_371 ,
struct V_368 , V_81 ) ;
F_173 ( V_14 , V_102 ,
V_369 -> V_364 , V_369 -> V_365 ) ;
F_56 ( & V_369 -> V_81 ) ;
F_2 ( V_369 ) ;
return 0 ;
}
if ( ! F_39 ( & V_14 -> V_351 ) ) {
V_349 = F_175 ( V_14 -> V_351 . V_371 ,
struct V_348 , V_81 ) ;
F_174 ( V_14 , V_102 ,
V_349 -> V_35 ) ;
F_56 ( & V_349 -> V_81 ) ;
F_2 ( V_349 ) ;
return 0 ;
}
return 1 ;
}
static T_6
F_166 ( struct V_13 * V_14 , T_4 V_102 )
{
struct V_339 * V_340 ;
if ( ! F_39 ( & V_14 -> V_356 ) ) {
V_340 = F_175 ( V_14 -> V_356 . V_371 ,
struct V_339 , V_81 ) ;
F_176 ( V_14 , V_102 ) ;
F_171 ( V_14 , V_340 -> V_35 ) ;
F_56 ( & V_340 -> V_81 ) ;
F_2 ( V_340 ) ;
return 0 ;
}
if ( ! F_39 ( & V_14 -> V_344 ) ) {
V_340 = F_175 ( V_14 -> V_344 . V_371 ,
struct V_339 , V_81 ) ;
F_176 ( V_14 , V_102 ) ;
F_162 ( V_14 , V_340 -> V_35 ) ;
F_56 ( & V_340 -> V_81 ) ;
F_2 ( V_340 ) ;
return 0 ;
}
return 1 ;
}
static void
F_177 ( struct V_13 * V_14 ,
T_19 * V_314 )
{
struct V_3 * V_7 ;
T_19 * V_372 ;
T_4 V_373 ;
struct V_92 * V_93 ;
unsigned long V_76 ;
int V_106 , V_332 ;
T_4 V_35 ;
for ( V_106 = 0 ; V_106 < V_314 -> V_333 ; V_106 ++ ) {
V_35 = F_21 ( V_314 -> V_334 [ V_106 ] . V_335 ) ;
if ( ! V_35 )
continue;
V_332 = V_314 -> V_334 [ V_106 ] . V_336 &
V_337 ;
if ( V_332 == V_374 )
F_162 ( V_14 , V_35 ) ;
}
V_373 = F_21 ( V_314 -> V_375 ) ;
if ( V_373 < V_14 -> V_39 . V_40 ) {
F_161 ( V_14 , V_314 ) ;
return;
}
if ( V_314 -> V_376 ==
V_377 ) {
F_32 ( & V_14 -> V_94 , V_76 ) ;
V_93 = F_57 ( V_14 ,
V_373 ) ;
F_159 ( V_14 , V_93 ) ;
F_33 ( & V_14 -> V_94 , V_76 ) ;
do {
V_35 = F_178 ( V_14 -> V_329 ,
V_14 -> V_202 . V_378 ) ;
if ( V_35 < V_14 -> V_202 . V_378 )
F_158 ( V_14 , V_35 ) ;
} while ( F_179 ( V_35 , V_14 -> V_329 ) );
} else if ( V_314 -> V_376 == V_379 )
F_161 ( V_14 , V_314 ) ;
if ( V_314 -> V_376 != V_380 )
return;
F_32 ( & V_14 -> V_309 , V_76 ) ;
F_15 (fw_event, &ioc->fw_event_list, list) {
if ( V_7 -> V_315 != V_381 ||
V_7 -> V_382 )
continue;
V_372 = ( T_19 * )
V_7 -> V_314 ;
if ( V_372 -> V_376 ==
V_383 ||
V_372 -> V_376 ==
V_379 ) {
if ( F_21 ( V_372 -> V_375 ) ==
V_373 ) {
F_46 ( V_14 , F_13 ( V_42
L_112 , V_14 -> V_43 ) ) ;
V_7 -> V_382 = 1 ;
}
}
}
F_33 ( & V_14 -> V_309 , V_76 ) ;
}
static void
F_180 ( struct V_13 * V_14 , T_4 V_35 )
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
V_118 -> V_342 = 1 ;
F_46 ( V_14 , F_13 ( V_42
L_113
L_114 , V_14 -> V_43 , V_35 ,
( unsigned long long ) V_56 -> V_60 ) ) ;
}
F_33 ( & V_14 -> V_90 , V_76 ) ;
}
static void
F_181 ( T_4 V_35 , T_4 * V_384 , T_4 * V_385 )
{
if ( ! V_35 || V_35 == * V_384 || V_35 == * V_385 )
return;
if ( ! * V_384 )
* V_384 = V_35 ;
else if ( ! * V_385 )
* V_385 = V_35 ;
}
static void
F_182 ( struct V_13 * V_14 ,
T_23 * V_314 )
{
T_24 * V_386 ;
int V_106 ;
T_4 V_35 , V_208 , V_384 , V_385 ;
struct V_339 * V_340 ;
V_384 = 0 ;
V_385 = 0 ;
if ( V_14 -> V_134 )
return;
V_386 = ( T_24 * ) & V_314 -> V_387 [ 0 ] ;
for ( V_106 = 0 ; V_106 < V_314 -> V_388 ; V_106 ++ , V_386 ++ ) {
if ( F_78 ( V_314 -> V_145 ) &
V_389 )
continue;
if ( V_386 -> V_390 ==
V_391 ||
V_386 -> V_390 ==
V_392 ) {
V_208 = F_21 ( V_386 -> V_393 ) ;
F_180 ( V_14 , V_208 ) ;
F_181 ( V_208 , & V_384 , & V_385 ) ;
}
}
V_386 = ( T_24 * ) & V_314 -> V_387 [ 0 ] ;
for ( V_106 = 0 ; V_106 < V_314 -> V_388 ; V_106 ++ , V_386 ++ ) {
if ( F_78 ( V_314 -> V_145 ) &
V_389 )
continue;
if ( V_386 -> V_390 == V_394 ) {
V_208 = F_21 ( V_386 -> V_393 ) ;
F_181 ( V_208 , & V_384 , & V_385 ) ;
}
}
if ( V_384 )
F_171 ( V_14 , V_384 ) ;
if ( V_385 )
F_171 ( V_14 , V_385 ) ;
V_386 = ( T_24 * ) & V_314 -> V_387 [ 0 ] ;
for ( V_106 = 0 ; V_106 < V_314 -> V_388 ; V_106 ++ , V_386 ++ ) {
if ( V_386 -> V_390 != V_394 )
continue;
V_35 = F_21 ( V_386 -> V_395 ) ;
V_208 = F_21 ( V_386 -> V_393 ) ;
F_183 ( V_35 , V_14 -> V_137 ) ;
if ( ! V_208 )
F_162 ( V_14 , V_35 ) ;
else if ( V_208 == V_384 || V_208 == V_385 ) {
V_340 = F_9 ( sizeof( * V_340 ) , V_8 ) ;
F_184 ( ! V_340 ) ;
F_139 ( & V_340 -> V_81 ) ;
V_340 -> V_35 = V_35 ;
F_47 ( & V_340 -> V_81 , & V_14 -> V_344 ) ;
F_46 ( V_14 , F_13 ( V_42
L_98 , V_14 -> V_43 ,
V_35 ) ) ;
} else
F_162 ( V_14 , V_35 ) ;
}
}
static void
F_185 ( struct V_13 * V_14 ,
T_25 * V_314 )
{
T_10 V_167 ;
if ( V_314 -> V_390 != V_396 )
return;
V_167 = F_78 ( V_314 -> V_397 ) ;
if ( V_167 == V_177 || V_167 ==
V_176 )
F_180 ( V_14 ,
F_21 ( V_314 -> V_393 ) ) ;
}
static void
F_186 ( struct V_13 * V_14 ,
T_26 * V_314 )
{
if ( V_14 -> V_398 >= V_314 -> V_399 ) {
F_25 ( V_42 L_115
L_116 , V_14 -> V_43 ,
( ( F_21 ( V_314 -> V_400 ) & 0x1 ) == 1 ) ? L_117 : L_118 ,
( ( F_21 ( V_314 -> V_400 ) & 0x2 ) == 2 ) ? L_119 : L_118 ,
( ( F_21 ( V_314 -> V_400 ) & 0x4 ) == 4 ) ? L_120 : L_118 ,
( ( F_21 ( V_314 -> V_400 ) & 0x8 ) == 8 ) ? L_121 : L_118 ,
V_314 -> V_399 ) ;
F_25 ( V_42 L_122 ,
V_14 -> V_43 , V_314 -> V_401 ) ;
}
}
static void
F_187 ( struct V_13 * V_14 )
{
struct V_101 * V_104 ;
T_4 V_102 ;
T_4 V_402 = 0 ;
for ( V_102 = 1 ; V_102 <= V_14 -> V_107 ; V_102 ++ ) {
V_104 = F_62 ( V_14 , V_102 ) ;
if ( ! V_104 )
continue;
V_402 ++ ;
F_176 ( V_14 , V_102 ) ;
F_188 ( V_104 ) ;
if ( V_14 -> V_270 )
V_104 -> V_302 = V_303 << 16 ;
else
V_104 -> V_302 = V_305 << 16 ;
V_104 -> V_304 ( V_104 ) ;
}
F_119 ( V_14 , F_13 ( V_42 L_123 ,
V_14 -> V_43 , V_402 ) ) ;
}
static void
F_189 ( struct V_13 * V_14 , struct V_101 * V_104 ,
T_27 * V_260 )
{
T_4 V_403 ;
unsigned char V_404 = F_190 ( V_104 ) ;
unsigned char V_405 = F_191 ( V_104 ) ;
T_28 * V_406 =
( T_28 * ) V_260 ;
if ( V_405 == V_407 || V_404 == V_408 )
return;
if ( V_404 == V_409 )
V_403 = V_410 ;
else if ( V_404 == V_411 )
V_403 = V_412 ;
else
return;
switch ( V_405 ) {
case V_413 :
case V_414 :
V_403 |= V_415 |
V_416 |
V_417 ;
V_260 -> V_418 . V_419 . V_420 =
F_192 ( F_193 ( V_104 ) ) ;
break;
case V_421 :
V_403 |= V_417 ;
break;
}
V_406 -> V_422 =
F_121 ( V_104 -> V_51 -> V_423 ) ;
V_260 -> V_424 = F_121 ( V_403 ) ;
}
static void
F_194 ( struct V_101 * V_104 , T_4 V_38 )
{
T_6 V_425 ;
switch ( V_38 ) {
case V_426 :
V_425 = 0x01 ;
break;
case V_427 :
V_425 = 0x02 ;
break;
case V_428 :
V_425 = 0x03 ;
break;
default:
V_425 = 0x00 ;
break;
}
F_195 ( 0 , V_104 -> V_429 , V_430 , 0x10 ,
V_425 ) ;
V_104 -> V_302 = V_431 << 24 | ( V_432 << 16 ) |
V_433 ;
}
int
F_196 ( struct V_112 * V_113 , struct V_101 * V_104 )
{
struct V_13 * V_14 = F_67 ( V_113 ) ;
struct V_116 * V_117 ;
struct V_72 * V_118 ;
struct V_55 * V_56 ;
T_27 * V_260 ;
T_10 V_434 ;
T_4 V_102 ;
T_4 V_35 ;
if ( V_14 -> V_15 & V_435 )
F_131 ( V_104 ) ;
V_117 = V_104 -> V_51 -> V_120 ;
if ( ! V_117 || ! V_117 -> V_122 ) {
V_104 -> V_302 = V_303 << 16 ;
V_104 -> V_304 ( V_104 ) ;
return 0 ;
}
if ( V_14 -> V_270 || V_14 -> V_269 ) {
V_104 -> V_302 = V_303 << 16 ;
V_104 -> V_304 ( V_104 ) ;
return 0 ;
}
V_118 = V_117 -> V_122 ;
V_35 = V_118 -> V_35 ;
if ( V_35 == V_132 ) {
V_104 -> V_302 = V_303 << 16 ;
V_104 -> V_304 ( V_104 ) ;
return 0 ;
}
if ( V_14 -> V_82 || V_14 -> V_436 )
return V_437 ;
else if ( V_118 -> V_342 ) {
V_104 -> V_302 = V_303 << 16 ;
V_104 -> V_304 ( V_104 ) ;
return 0 ;
} else if ( V_118 -> V_254 ||
V_117 -> V_319 )
return V_438 ;
if ( V_104 -> V_439 == V_440 )
V_434 = V_441 ;
else if ( V_104 -> V_439 == V_442 )
V_434 = V_443 ;
else
V_434 = V_444 ;
V_434 |= V_445 ;
if ( ! V_14 -> V_134 && ! F_79 ( & V_104 -> V_51 -> V_191 )
&& F_96 ( V_104 -> V_51 ) && V_104 -> V_446 != 32 )
V_434 |= V_447 ;
V_102 = F_197 ( V_14 , V_14 -> V_448 , V_104 ) ;
if ( ! V_102 ) {
F_25 ( V_42 L_52 ,
V_14 -> V_43 , V_44 ) ;
goto V_89;
}
V_260 = F_120 ( V_14 , V_102 ) ;
memset ( V_260 , 0 , sizeof( T_27 ) ) ;
F_189 ( V_14 , V_104 , V_260 ) ;
if ( V_104 -> V_446 == 32 )
V_434 |= 4 << V_449 ;
V_260 -> V_280 = V_450 ;
if ( V_117 -> V_122 -> V_76 &
V_138 )
V_260 -> V_280 = V_451 ;
else
V_260 -> V_280 = V_450 ;
V_260 -> V_200 = F_121 ( V_35 ) ;
V_260 -> V_452 = F_198 ( F_199 ( V_104 ) ) ;
V_260 -> V_453 = F_198 ( V_434 ) ;
V_260 -> V_454 = F_121 ( V_104 -> V_446 ) ;
V_260 -> V_455 = V_456 ;
V_260 -> V_457 = V_458 ;
V_260 -> V_459 =
F_200 ( V_14 , V_102 ) ;
V_260 -> V_460 = F_92 ( T_27 , V_461 ) / 4 ;
F_122 ( V_117 -> V_109 , (struct V_284 * )
V_260 -> V_285 ) ;
memcpy ( V_260 -> V_418 . V_462 , V_104 -> V_463 , V_104 -> V_446 ) ;
if ( V_260 -> V_452 ) {
if ( V_14 -> V_464 ( V_14 , V_104 , V_102 ) ) {
F_176 ( V_14 , V_102 ) ;
goto V_89;
}
} else
V_14 -> V_465 ( V_14 , & V_260 -> V_461 ) ;
V_56 = V_118 -> V_56 ;
if ( V_56 && V_56 -> V_466 )
F_201 ( V_14 , V_104 , V_56 , V_260 ,
V_102 ) ;
if ( F_169 ( V_260 -> V_280 == V_450 ) ) {
if ( V_118 -> V_76 & V_140 ) {
V_260 -> V_454 = F_121 ( V_104 -> V_446 |
V_467 ) ;
F_202 ( V_14 , V_102 , V_35 ) ;
} else
F_203 ( V_14 , V_102 ,
F_21 ( V_260 -> V_200 ) ) ;
} else
F_167 ( V_14 , V_102 ) ;
return 0 ;
V_89:
return V_437 ;
}
static void
F_204 ( char * V_429 , struct V_468 * V_469 )
{
if ( ( V_429 [ 0 ] & 0x7F ) >= 0x72 ) {
V_469 -> V_470 = V_429 [ 1 ] & 0x0F ;
V_469 -> V_471 = V_429 [ 2 ] ;
V_469 -> V_425 = V_429 [ 3 ] ;
} else {
V_469 -> V_470 = V_429 [ 2 ] & 0x0F ;
V_469 -> V_471 = V_429 [ 12 ] ;
V_469 -> V_425 = V_429 [ 13 ] ;
}
}
static void
F_205 ( struct V_13 * V_14 , struct V_101 * V_104 ,
T_29 * V_37 , T_4 V_102 )
{
T_10 V_472 ;
T_6 * V_473 ;
T_4 V_38 = F_21 ( V_37 -> V_46 ) &
V_47 ;
T_6 V_474 = V_37 -> V_475 ;
T_6 V_476 = V_37 -> V_477 ;
char * V_478 = NULL ;
char * V_479 = NULL ;
char * V_480 = V_14 -> V_481 ;
T_10 V_482 = F_78 ( V_37 -> V_291 ) ;
struct V_53 * V_54 = NULL ;
struct V_126 * V_85 = V_104 -> V_51 -> V_299 ;
struct V_72 * V_300 = V_85 -> V_120 ;
char * V_301 = NULL ;
if ( ! V_300 )
return;
if ( V_14 -> V_218 )
V_301 = L_57 ;
else
V_301 = L_58 ;
if ( V_482 == 0x31170000 )
return;
switch ( V_38 ) {
case V_48 :
V_478 = L_124 ;
break;
case V_483 :
V_478 = L_125 ;
break;
case V_484 :
V_478 = L_126 ;
break;
case V_485 :
V_478 = L_127 ;
break;
case V_486 :
V_478 = L_128 ;
break;
case V_487 :
V_478 = L_129 ;
break;
case V_488 :
V_478 = L_130 ;
break;
case V_489 :
V_478 = L_131 ;
break;
case V_490 :
V_478 = L_132 ;
break;
case V_491 :
V_478 = L_133 ;
break;
case V_492 :
V_478 = L_134 ;
break;
case V_493 :
V_478 = L_135 ;
break;
case V_494 :
V_478 = L_136 ;
break;
case V_495 :
V_478 = L_137 ;
break;
case V_426 :
V_478 = L_138 ;
break;
case V_428 :
V_478 = L_139 ;
break;
case V_427 :
V_478 = L_140 ;
break;
case V_496 :
V_478 = L_141 ;
break;
default:
V_478 = L_47 ;
break;
}
switch ( V_476 ) {
case V_497 :
V_479 = L_142 ;
break;
case V_498 :
V_479 = L_143 ;
break;
case V_499 :
V_479 = L_144 ;
break;
case V_500 :
V_479 = L_145 ;
break;
case V_501 :
V_479 = L_146 ;
break;
case V_502 :
V_479 = L_147 ;
break;
case V_503 :
V_479 = L_148 ;
break;
case V_504 :
V_479 = L_149 ;
break;
case V_505 :
V_479 = L_150 ;
break;
case V_506 :
V_479 = L_151 ;
break;
case V_507 :
V_479 = L_152 ;
break;
default:
V_479 = L_47 ;
break;
}
V_480 [ 0 ] = '\0' ;
if ( ! V_474 )
V_480 = L_118 ;
if ( V_474 & V_508 )
strcat ( V_480 , L_153 ) ;
if ( V_474 & V_509 )
strcat ( V_480 , L_154 ) ;
if ( V_474 & V_510 )
strcat ( V_480 , L_155 ) ;
if ( V_474 & V_511 )
strcat ( V_480 , L_156 ) ;
if ( V_474 & V_512 )
strcat ( V_480 , L_157 ) ;
F_131 ( V_104 ) ;
if ( V_300 -> V_76 & V_123 ) {
F_91 ( V_42 L_158 , V_14 -> V_43 ,
V_301 , ( unsigned long long ) V_300 -> V_17 ) ;
} else {
V_54 = F_31 ( V_14 , V_300 ) ;
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
V_478 , V_38 , V_102 ) ;
F_91 ( V_42
L_164 ,
V_14 -> V_43 , F_199 ( V_104 ) , V_104 -> V_513 ,
F_206 ( V_104 ) ) ;
F_91 ( V_42
L_165 ,
V_14 -> V_43 , F_21 ( V_37 -> V_514 ) ,
F_78 ( V_37 -> V_515 ) , V_104 -> V_302 ) ;
F_91 ( V_42
L_166 ,
V_14 -> V_43 , V_479 ,
V_476 , V_480 , V_474 ) ;
if ( V_474 & V_512 ) {
struct V_468 V_469 ;
F_204 ( V_104 -> V_429 , & V_469 ) ;
F_91 ( V_42
L_167 ,
V_14 -> V_43 , V_469 . V_470 ,
V_469 . V_471 , V_469 . V_425 , F_78 ( V_37 -> V_516 ) ) ;
}
if ( V_474 & V_508 ) {
V_472 = F_78 ( V_37 -> V_517 ) ;
V_473 = ( T_6 * ) & V_472 ;
F_105 ( V_14 , V_473 [ 0 ] ) ;
}
}
static void
F_207 ( struct V_13 * V_14 , T_4 V_35 )
{
T_30 V_37 ;
T_31 V_260 ;
struct V_53 * V_54 ;
V_54 = F_37 ( V_14 , V_35 ) ;
if ( ! V_54 )
return;
memset ( & V_260 , 0 , sizeof( T_31 ) ) ;
V_260 . V_280 = V_518 ;
V_260 . V_519 = V_520 ;
V_260 . V_521 =
F_198 ( V_522 ) ;
V_260 . V_200 = F_121 ( V_35 ) ;
V_260 . V_145 = V_523 ;
if ( ( F_208 ( V_14 , & V_37 ,
& V_260 ) ) != 0 ) {
F_25 ( V_42 L_2 , V_14 -> V_43 ,
__FILE__ , __LINE__ , V_44 ) ;
goto V_89;
}
V_54 -> V_524 = 1 ;
if ( V_37 . V_46 || V_37 . V_291 ) {
F_46 ( V_14 , F_13 ( V_42
L_168 ,
V_14 -> V_43 , F_21 ( V_37 . V_46 ) ,
F_78 ( V_37 . V_291 ) ) ) ;
goto V_89;
}
V_89:
F_41 ( V_54 ) ;
}
static void
F_209 ( struct V_13 * V_14 ,
struct V_53 * V_54 )
{
T_30 V_37 ;
T_31 V_260 ;
memset ( & V_260 , 0 , sizeof( T_31 ) ) ;
V_260 . V_280 = V_518 ;
V_260 . V_519 = V_520 ;
V_260 . V_521 = 0 ;
V_260 . V_525 = F_121 ( V_54 -> V_26 ) ;
V_260 . V_200 = 0 ;
V_260 . V_526 = F_121 ( V_54 -> V_78 ) ;
V_260 . V_145 = V_527 ;
if ( ( F_208 ( V_14 , & V_37 ,
& V_260 ) ) != 0 ) {
F_210 ( V_42 L_2 , V_14 -> V_43 ,
__FILE__ , __LINE__ , V_44 ) ;
return;
}
if ( V_37 . V_46 || V_37 . V_291 ) {
F_46 ( V_14 , F_210 ( V_42
L_168 ,
V_14 -> V_43 , F_21 ( V_37 . V_46 ) ,
F_78 ( V_37 . V_291 ) ) ) ;
return;
}
}
static void
F_211 ( struct V_13 * V_14 , T_4 V_35 )
{
struct V_3 * V_7 ;
V_7 = F_8 ( 0 ) ;
if ( ! V_7 )
return;
V_7 -> V_315 = V_528 ;
V_7 -> V_529 = V_35 ;
V_7 -> V_14 = V_14 ;
F_138 ( V_14 , V_7 ) ;
F_6 ( V_7 ) ;
}
static void
F_212 ( struct V_13 * V_14 , T_4 V_35 )
{
struct V_126 * V_85 ;
struct V_72 * V_118 ;
T_32 * V_530 ;
T_33 * V_314 ;
struct V_53 * V_54 ;
T_34 V_193 ;
unsigned long V_76 ;
F_32 ( & V_14 -> V_74 , V_76 ) ;
V_54 = F_36 ( V_14 , V_35 ) ;
if ( ! V_54 )
goto V_531;
V_85 = V_54 -> V_85 ;
V_118 = V_85 -> V_120 ;
if ( ( V_118 -> V_76 & V_138 ) ||
( ( V_118 -> V_76 & V_123 ) ) )
goto V_531;
if ( V_54 -> V_78 != 0 )
F_132 ( V_144 , V_85 , L_169
L_170 ,
( unsigned long long ) V_54 -> V_22 ,
V_54 -> V_26 ) ;
if ( V_54 -> V_79 [ 0 ] != '\0' )
F_132 ( V_223 , V_85 , L_169
L_171 ,
V_54 -> V_80 ,
V_54 -> V_79 ) ;
F_33 ( & V_14 -> V_74 , V_76 ) ;
if ( V_14 -> V_532 -> V_533 == V_534 )
F_211 ( V_14 , V_35 ) ;
V_193 = F_92 ( T_32 , V_535 ) +
sizeof( T_33 ) ;
V_530 = F_9 ( V_193 , V_130 ) ;
if ( ! V_530 ) {
F_25 ( V_42 L_2 ,
V_14 -> V_43 , __FILE__ , __LINE__ , V_44 ) ;
goto V_89;
}
V_530 -> V_280 = V_536 ;
V_530 -> V_364 =
F_121 ( V_537 ) ;
V_530 -> V_249 = V_193 / 4 ;
V_530 -> V_538 =
F_121 ( sizeof( T_33 ) / 4 ) ;
V_314 = ( T_33 * )
V_530 -> V_535 ;
V_314 -> V_390 = V_539 ;
V_314 -> V_540 = 0x5D ;
V_314 -> V_200 = F_121 ( V_35 ) ;
V_314 -> V_19 = F_213 ( V_118 -> V_17 ) ;
F_214 ( V_14 , V_530 ) ;
F_2 ( V_530 ) ;
V_89:
if ( V_54 )
F_41 ( V_54 ) ;
return;
V_531:
F_33 ( & V_14 -> V_74 , V_76 ) ;
goto V_89;
}
static T_6
F_215 ( struct V_13 * V_14 , T_4 V_102 , T_6 V_243 , T_10 V_244 )
{
T_27 * V_260 ;
T_29 * V_37 ;
struct V_101 * V_104 ;
T_4 V_38 ;
T_10 V_541 ;
T_6 V_474 ;
T_6 V_476 ;
T_10 V_482 ;
struct V_116 * V_117 ;
T_10 V_234 = 0 ;
unsigned long V_76 ;
V_37 = F_107 ( V_14 , V_244 ) ;
V_104 = F_62 ( V_14 , V_102 ) ;
if ( V_104 == NULL )
return 1 ;
V_260 = F_120 ( V_14 , V_102 ) ;
if ( V_37 == NULL ) {
V_104 -> V_302 = V_542 << 16 ;
goto V_89;
}
V_117 = V_104 -> V_51 -> V_120 ;
if ( ! V_117 || ! V_117 -> V_122 ||
V_117 -> V_122 -> V_342 ) {
V_104 -> V_302 = V_303 << 16 ;
goto V_89;
}
V_38 = F_21 ( V_37 -> V_46 ) ;
if ( F_216 ( V_14 , V_102 ) &&
( ( V_38 & V_47 )
!= V_491 ) ) {
F_32 ( & V_14 -> V_105 , V_76 ) ;
V_14 -> V_103 [ V_102 - 1 ] . V_104 = V_104 ;
F_33 ( & V_14 -> V_105 , V_76 ) ;
F_217 ( V_14 , V_102 , 0 ) ;
memcpy ( V_260 -> V_418 . V_462 , V_104 -> V_463 , V_104 -> V_446 ) ;
V_260 -> V_200 =
F_121 ( V_117 -> V_122 -> V_35 ) ;
F_203 ( V_14 , V_102 ,
V_117 -> V_122 -> V_35 ) ;
return 0 ;
}
V_474 = V_37 -> V_475 ;
if ( V_474 & V_508 )
V_234 =
F_78 ( V_37 -> V_517 ) & 0xFF ;
if ( ! V_117 -> V_543 ) {
V_117 -> V_543 ++ ;
if ( ! V_14 -> V_134 &&
! F_79 ( & V_104 -> V_51 -> V_191 ) &&
F_96 ( V_104 -> V_51 ) &&
V_234 == V_237 ) {
F_218 ( V_104 -> V_51 ) ;
F_75 ( V_144 , V_104 -> V_51 , L_172 ) ;
}
}
V_541 = F_78 ( V_37 -> V_515 ) ;
F_219 ( V_104 , F_199 ( V_104 ) - V_541 ) ;
if ( V_38 & V_544 )
V_482 = F_78 ( V_37 -> V_291 ) ;
else
V_482 = 0 ;
V_38 &= V_47 ;
V_476 = V_37 -> V_477 ;
if ( V_38 == V_488 && V_541 == 0 &&
( V_476 == V_500 ||
V_476 == V_503 ||
V_476 == V_505 ) ) {
V_38 = V_48 ;
}
if ( V_474 & V_512 ) {
struct V_468 V_469 ;
const void * V_545 = F_220 ( V_14 ,
V_102 ) ;
T_10 V_193 = F_221 ( T_10 , V_458 ,
F_78 ( V_37 -> V_516 ) ) ;
memcpy ( V_104 -> V_429 , V_545 , V_193 ) ;
F_204 ( V_104 -> V_429 , & V_469 ) ;
if ( V_469 . V_471 == 0x5D )
F_212 ( V_14 ,
F_21 ( V_37 -> V_200 ) ) ;
F_222 ( V_14 , V_469 . V_470 , V_469 . V_471 , V_469 . V_425 ) ;
if ( ! ( V_14 -> V_15 & V_546 ) &&
( ( V_104 -> V_429 [ 2 ] == V_547 ) ||
( V_104 -> V_429 [ 2 ] == V_548 ) ||
( V_104 -> V_429 [ 2 ] == V_549 ) ) )
F_205 ( V_14 , V_104 , V_37 , V_102 ) ;
}
switch ( V_38 ) {
case V_550 :
case V_551 :
V_104 -> V_302 = V_552 ;
break;
case V_486 :
V_104 -> V_302 = V_303 << 16 ;
break;
case V_494 :
if ( V_117 -> V_319 ) {
V_104 -> V_302 = V_553 << 16 ;
goto V_89;
}
if ( V_482 == 0x31110630 ) {
if ( V_104 -> V_554 > 2 ) {
V_104 -> V_302 = V_303 << 16 ;
F_223 ( V_104 -> V_51 ,
V_555 ) ;
} else {
V_104 -> V_302 = V_556 << 16 ;
V_104 -> V_51 -> V_557 = 1 ;
}
break;
} else if ( V_482 == V_558 ) {
V_104 -> V_302 = V_305 << 16 ;
break;
}
V_104 -> V_302 = V_556 << 16 ;
break;
case V_491 :
case V_495 :
V_104 -> V_302 = V_305 << 16 ;
break;
case V_492 :
if ( ( V_541 == 0 ) || ( V_104 -> V_513 > V_541 ) )
V_104 -> V_302 = V_556 << 16 ;
else
V_104 -> V_302 = ( V_542 << 16 ) | V_476 ;
break;
case V_488 :
V_104 -> V_302 = ( V_542 << 16 ) | V_476 ;
if ( ( V_474 & V_512 ) )
break;
if ( V_541 < V_104 -> V_513 ) {
if ( V_476 == V_552 )
V_104 -> V_302 = V_552 ;
else
V_104 -> V_302 = V_556 << 16 ;
} else if ( V_474 & ( V_511 |
V_510 ) )
V_104 -> V_302 = V_556 << 16 ;
else if ( V_474 & V_509 )
V_104 -> V_302 = V_305 << 16 ;
else if ( ! V_541 && V_104 -> V_463 [ 0 ] == V_559 ) {
V_37 -> V_475 = V_512 ;
V_37 -> V_477 = V_433 ;
V_104 -> V_302 = ( V_431 << 24 ) |
V_433 ;
V_104 -> V_429 [ 0 ] = 0x70 ;
V_104 -> V_429 [ 2 ] = V_430 ;
V_104 -> V_429 [ 12 ] = 0x20 ;
V_104 -> V_429 [ 13 ] = 0 ;
}
break;
case V_487 :
F_219 ( V_104 , 0 ) ;
case V_484 :
case V_48 :
V_104 -> V_302 = ( V_542 << 16 ) | V_476 ;
if ( V_234 ==
V_237 ||
( V_474 & ( V_511 |
V_510 ) ) )
V_104 -> V_302 = V_556 << 16 ;
else if ( V_474 & V_509 )
V_104 -> V_302 = V_305 << 16 ;
break;
case V_426 :
case V_428 :
case V_427 :
F_194 ( V_104 , V_38 ) ;
break;
case V_490 :
case V_483 :
case V_560 :
case V_561 :
case V_562 :
case V_563 :
case V_489 :
case V_493 :
case V_496 :
default:
V_104 -> V_302 = V_556 << 16 ;
break;
}
if ( V_104 -> V_302 && ( V_14 -> V_15 & V_546 ) )
F_205 ( V_14 , V_104 , V_37 , V_102 ) ;
V_89:
F_188 ( V_104 ) ;
V_104 -> V_304 ( V_104 ) ;
return 1 ;
}
static void
F_224 ( struct V_13 * V_14 )
{
T_4 V_193 ;
T_4 V_38 ;
int V_106 ;
T_9 V_37 ;
T_35 * V_564 = NULL ;
T_4 V_565 ;
T_6 V_566 ;
F_119 ( V_14 , F_13 ( V_42
L_173 ,
V_14 -> V_43 , ( unsigned long long ) V_14 -> V_39 . V_17 ) ) ;
V_193 = F_92 ( T_35 , V_567 ) + ( V_14 -> V_39 . V_40
* sizeof( V_568 ) ) ;
V_564 = F_9 ( V_193 , V_130 ) ;
if ( ! V_564 ) {
F_25 ( V_42 L_2 ,
V_14 -> V_43 , __FILE__ , __LINE__ , V_44 ) ;
return;
}
if ( ( F_225 ( V_14 , & V_37 ,
V_564 , V_193 ) ) != 0 )
goto V_89;
V_38 = F_21 ( V_37 . V_46 ) & V_47 ;
if ( V_38 != V_48 )
goto V_89;
for ( V_106 = 0 ; V_106 < V_14 -> V_39 . V_40 ; V_106 ++ ) {
V_566 = V_564 -> V_567 [ V_106 ] . V_569 >> 4 ;
if ( V_106 == 0 )
V_14 -> V_39 . V_35 = F_21 ( V_564 ->
V_567 [ 0 ] . V_570 ) ;
V_14 -> V_39 . V_225 [ V_106 ] . V_35 = V_14 -> V_39 . V_35 ;
V_565 = F_21 ( V_564 -> V_567 [ V_106 ] .
V_335 ) ;
if ( V_565 && V_566 < V_571 )
V_566 = V_571 ;
F_226 ( V_14 , V_14 -> V_39 . V_17 ,
V_565 , V_106 , V_566 ) ;
}
V_89:
F_2 ( V_564 ) ;
}
static void
F_227 ( struct V_13 * V_14 )
{
int V_106 ;
T_9 V_37 ;
T_35 * V_564 = NULL ;
T_36 * V_572 = NULL ;
T_37 V_573 ;
T_8 V_36 ;
T_38 V_574 ;
T_4 V_38 ;
T_4 V_193 ;
T_6 V_575 ;
T_6 V_40 ;
F_228 ( V_14 , & V_40 ) ;
if ( ! V_40 ) {
F_25 ( V_42 L_2 ,
V_14 -> V_43 , __FILE__ , __LINE__ , V_44 ) ;
return;
}
V_14 -> V_39 . V_225 = F_229 ( V_40 ,
sizeof( struct V_576 ) , V_130 ) ;
if ( ! V_14 -> V_39 . V_225 ) {
F_25 ( V_42 L_2 ,
V_14 -> V_43 , __FILE__ , __LINE__ , V_44 ) ;
goto V_89;
}
V_14 -> V_39 . V_40 = V_40 ;
V_193 = F_92 ( T_35 , V_567 ) + ( V_14 -> V_39 . V_40 *
sizeof( V_568 ) ) ;
V_564 = F_9 ( V_193 , V_130 ) ;
if ( ! V_564 ) {
F_25 ( V_42 L_2 ,
V_14 -> V_43 , __FILE__ , __LINE__ , V_44 ) ;
return;
}
if ( ( F_225 ( V_14 , & V_37 ,
V_564 , V_193 ) ) ) {
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
V_193 = F_92 ( T_36 , V_567 ) + ( V_14 -> V_39 . V_40 *
sizeof( V_577 ) ) ;
V_572 = F_9 ( V_193 , V_130 ) ;
if ( ! V_572 ) {
F_25 ( V_42 L_2 ,
V_14 -> V_43 , __FILE__ , __LINE__ , V_44 ) ;
goto V_89;
}
if ( ( F_230 ( V_14 , & V_37 ,
V_572 , V_193 ) ) ) {
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
V_14 -> V_578 =
V_572 -> V_579 ;
V_575 =
V_572 -> V_580 ;
if ( V_575 & V_581 )
V_14 -> V_575 = ( V_575 &
V_582 ) * 16 ;
else
V_14 -> V_575 = V_575 &
V_582 ;
V_14 -> V_39 . V_583 = & V_14 -> V_113 -> V_584 ;
for ( V_106 = 0 ; V_106 < V_14 -> V_39 . V_40 ; V_106 ++ ) {
if ( ( F_231 ( V_14 , & V_37 , & V_573 ,
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
V_14 -> V_39 . V_35 = F_21 ( V_564 ->
V_567 [ 0 ] . V_570 ) ;
V_14 -> V_39 . V_225 [ V_106 ] . V_35 = V_14 -> V_39 . V_35 ;
V_14 -> V_39 . V_225 [ V_106 ] . V_585 = V_106 ;
F_232 ( V_14 , & V_14 -> V_39 . V_225 [ V_106 ] ,
V_573 , V_14 -> V_39 . V_583 ) ;
}
if ( ( F_24 ( V_14 , & V_37 , & V_36 ,
V_41 , V_14 -> V_39 . V_35 ) ) ) {
F_25 ( V_42 L_2 ,
V_14 -> V_43 , __FILE__ , __LINE__ , V_44 ) ;
goto V_89;
}
V_14 -> V_39 . V_78 =
F_21 ( V_36 . V_526 ) ;
V_14 -> V_39 . V_17 = F_18 ( V_36 . V_19 ) ;
F_13 ( V_42
L_174 ,
V_14 -> V_43 , V_14 -> V_39 . V_35 ,
( unsigned long long ) V_14 -> V_39 . V_17 ,
V_14 -> V_39 . V_40 ) ;
if ( V_14 -> V_39 . V_78 ) {
if ( ! ( F_233 ( V_14 , & V_37 ,
& V_574 , V_586 ,
V_14 -> V_39 . V_78 ) ) )
V_14 -> V_39 . V_22 =
F_18 ( V_574 . V_24 ) ;
}
V_89:
F_2 ( V_572 ) ;
F_2 ( V_564 ) ;
}
static int
F_234 ( struct V_13 * V_14 , T_4 V_35 )
{
struct V_92 * V_93 ;
T_9 V_37 ;
T_39 V_587 ;
T_40 V_588 ;
T_38 V_574 ;
T_10 V_38 ;
T_4 V_589 ;
T_1 V_17 , V_84 = 0 ;
int V_106 ;
unsigned long V_76 ;
struct V_323 * V_324 = NULL ;
int V_28 = 0 ;
if ( ! V_35 )
return - 1 ;
if ( V_14 -> V_82 || V_14 -> V_270 )
return - 1 ;
if ( ( F_235 ( V_14 , & V_37 , & V_587 ,
V_590 , V_35 ) ) ) {
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
V_589 = F_21 ( V_587 . V_591 ) ;
if ( F_23 ( V_14 , V_589 , & V_84 )
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
V_28 = F_234 ( V_14 , V_589 ) ;
if ( V_28 != 0 )
return V_28 ;
}
}
F_32 ( & V_14 -> V_94 , V_76 ) ;
V_17 = F_18 ( V_587 . V_19 ) ;
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
V_93 -> V_40 = V_587 . V_592 ;
V_93 -> V_84 = V_84 ;
V_93 -> V_17 = V_17 ;
F_13 ( V_42 L_175 \
L_176 , V_14 -> V_43 ,
V_35 , V_589 , ( unsigned long long )
V_93 -> V_17 , V_93 -> V_40 ) ;
if ( ! V_93 -> V_40 )
goto V_593;
V_93 -> V_225 = F_229 ( V_93 -> V_40 ,
sizeof( struct V_576 ) , V_130 ) ;
if ( ! V_93 -> V_225 ) {
F_25 ( V_42 L_2 ,
V_14 -> V_43 , __FILE__ , __LINE__ , V_44 ) ;
V_28 = - 1 ;
goto V_593;
}
F_139 ( & V_93 -> V_594 ) ;
V_324 = F_48 ( V_14 , V_35 ,
V_84 ) ;
if ( ! V_324 ) {
F_25 ( V_42 L_2 ,
V_14 -> V_43 , __FILE__ , __LINE__ , V_44 ) ;
V_28 = - 1 ;
goto V_593;
}
V_93 -> V_583 = & V_324 -> V_129 -> V_127 ;
for ( V_106 = 0 ; V_106 < V_93 -> V_40 ; V_106 ++ ) {
if ( ( F_236 ( V_14 , & V_37 ,
& V_588 , V_106 , V_35 ) ) ) {
F_25 ( V_42 L_2 ,
V_14 -> V_43 , __FILE__ , __LINE__ , V_44 ) ;
V_28 = - 1 ;
goto V_593;
}
V_93 -> V_225 [ V_106 ] . V_35 = V_35 ;
V_93 -> V_225 [ V_106 ] . V_585 = V_106 ;
if ( ( F_237 ( V_14 ,
& V_93 -> V_225 [ V_106 ] , V_588 ,
V_93 -> V_583 ) ) ) {
F_25 ( V_42 L_2 ,
V_14 -> V_43 , __FILE__ , __LINE__ , V_44 ) ;
V_28 = - 1 ;
goto V_593;
}
}
if ( V_93 -> V_78 ) {
if ( ! ( F_233 ( V_14 , & V_37 ,
& V_574 , V_586 ,
V_93 -> V_78 ) ) )
V_93 -> V_22 =
F_18 ( V_574 . V_24 ) ;
}
F_59 ( V_14 , V_93 ) ;
return 0 ;
V_593:
if ( V_324 )
F_49 ( V_14 , V_93 -> V_17 ,
V_84 ) ;
F_2 ( V_93 ) ;
return V_28 ;
}
void
F_238 ( struct V_13 * V_14 , T_1 V_17 )
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
F_239 ( V_14 , V_93 ) ;
}
static T_6
F_240 ( struct V_13 * V_14 , T_4 V_102 , T_6 V_243 , T_10 V_244 )
{
T_15 * V_37 ;
V_37 = F_107 ( V_14 , V_244 ) ;
if ( V_14 -> V_595 . V_246 == V_247 )
return 1 ;
if ( V_14 -> V_595 . V_102 != V_102 )
return 1 ;
V_14 -> V_595 . V_246 |= V_248 ;
if ( V_37 ) {
memcpy ( V_14 -> V_595 . V_244 , V_37 ,
V_37 -> V_249 * 4 ) ;
V_14 -> V_595 . V_246 |= V_250 ;
}
V_14 -> V_595 . V_246 &= ~ V_251 ;
F_108 ( & V_14 -> V_595 . V_252 ) ;
return 1 ;
}
static T_6
F_241 ( struct V_13 * V_14 , T_1 V_17 ,
T_4 V_35 , T_6 V_596 )
{
T_6 V_28 = 1 ;
char * V_235 = NULL ;
switch ( V_596 ) {
case V_597 :
case V_598 :
V_28 = 0 ;
break;
case V_599 :
V_235 = L_177 ;
break;
case V_600 :
V_235 = L_178 ;
break;
case V_601 :
V_235 = L_179 ;
break;
case V_602 :
V_235 = L_180 ;
break;
case V_603 :
V_235 = L_181 ;
break;
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
case V_614 :
case V_615 :
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
F_242 ( struct V_13 * V_14 ,
T_1 V_616 , T_4 V_35 , T_6 V_617 , T_6 V_566 )
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
if ( V_617 != V_36 . V_618 )
return;
V_96 = F_78 ( V_36 . V_146 ) ;
if ( ! ( F_60 ( V_96 ) ) )
return;
F_32 ( & V_14 -> V_74 , V_76 ) ;
V_17 = F_18 ( V_36 . V_19 ) ;
V_54 = F_34 ( V_14 ,
V_17 ) ;
if ( ! V_54 )
goto V_531;
if ( F_164 ( V_54 -> V_35 != V_35 ) ) {
V_85 = V_54 -> V_85 ;
V_118 = V_85 -> V_120 ;
F_132 ( V_144 , V_85 ,
L_184 ,
V_54 -> V_35 , V_35 ) ;
V_118 -> V_35 = V_35 ;
V_54 -> V_35 = V_35 ;
if ( V_36 . V_145 &
V_619 ) {
V_54 -> V_80 =
F_21 ( V_36 . V_620 ) ;
memcpy ( & V_54 -> V_79 [ 0 ] ,
& V_36 . V_621 [ 0 ] , 4 ) ;
} else {
V_54 -> V_80 = 0 ;
V_54 -> V_79 [ 0 ] = '\0' ;
}
}
if ( ! ( F_21 ( V_36 . V_145 ) &
V_622 ) ) {
F_25 ( V_42
L_185 ,
V_14 -> V_43 , V_35 ) ;
goto V_531;
}
if ( F_241 ( V_14 , V_17 , V_35 ,
V_36 . V_623 ) )
goto V_531;
F_33 ( & V_14 -> V_74 , V_76 ) ;
F_156 ( V_14 , V_17 ) ;
if ( V_54 )
F_41 ( V_54 ) ;
return;
V_531:
F_33 ( & V_14 -> V_74 , V_76 ) ;
if ( V_54 )
F_41 ( V_54 ) ;
}
static int
F_243 ( struct V_13 * V_14 , T_4 V_35 , T_6 V_624 ,
T_6 V_625 )
{
T_9 V_37 ;
T_8 V_36 ;
T_38 V_574 ;
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
V_622 ) ) {
F_25 ( V_42 L_186 ,
V_14 -> V_43 , V_35 ) ;
return - 1 ;
}
if ( F_241 ( V_14 , V_17 , V_35 ,
V_36 . V_623 ) )
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
F_21 ( V_36 . V_591 ) ,
& V_54 -> V_84 ) != 0 )
F_25 ( V_42 L_2 ,
V_14 -> V_43 , __FILE__ , __LINE__ , V_44 ) ;
V_54 -> V_78 =
F_21 ( V_36 . V_526 ) ;
if ( V_54 -> V_78 != 0 )
V_54 -> V_26 =
F_21 ( V_36 . V_525 ) ;
V_54 -> V_96 = V_96 ;
V_54 -> V_17 = V_17 ;
V_54 -> V_225 = V_36 . V_618 ;
V_54 -> V_139 = ( F_21 ( V_36 . V_145 ) &
V_626 ) ? 1 : 0 ;
if ( V_36 . V_145 & V_619 ) {
V_54 -> V_80 =
F_21 ( V_36 . V_620 ) ;
memcpy ( & V_54 -> V_79 [ 0 ] ,
& V_36 . V_621 [ 0 ] , 4 ) ;
} else {
V_54 -> V_80 = 0 ;
V_54 -> V_79 [ 0 ] = '\0' ;
}
if ( V_54 -> V_78 && ! ( F_233 (
V_14 , & V_37 , & V_574 , V_586 ,
V_54 -> V_78 ) ) )
V_54 -> V_22 =
F_18 ( V_574 . V_24 ) ;
V_54 -> V_20 = F_18 ( V_36 . V_21 ) ;
if ( V_14 -> V_627 )
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
if ( ( V_14 -> V_532 -> V_533 == V_534 ) &&
( V_54 -> V_524 ) ) {
F_209 ( V_14 , V_54 ) ;
V_54 -> V_524 = 0 ;
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
V_118 -> V_342 = 1 ;
F_156 ( V_14 , V_54 -> V_17 ) ;
V_118 -> V_35 =
V_132 ;
}
if ( ! V_14 -> V_628 )
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
F_244 ( struct V_13 * V_14 ,
T_19 * V_314 )
{
int V_106 ;
T_4 V_35 ;
T_4 V_332 ;
T_6 V_617 ;
char * V_629 = NULL ;
T_6 V_566 , V_630 ;
switch ( V_314 -> V_376 ) {
case V_383 :
V_629 = L_194 ;
break;
case V_380 :
V_629 = L_195 ;
break;
case V_379 :
case 0 :
V_629 = L_196 ;
break;
case V_377 :
V_629 = L_197 ;
break;
default:
V_629 = L_198 ;
break;
}
F_13 ( V_42 L_199 ,
V_14 -> V_43 , V_629 ) ;
F_13 ( L_200 \
L_201 ,
F_21 ( V_314 -> V_375 ) ,
F_21 ( V_314 -> V_526 ) ,
V_314 -> V_631 , V_314 -> V_333 ) ;
for ( V_106 = 0 ; V_106 < V_314 -> V_333 ; V_106 ++ ) {
V_35 = F_21 ( V_314 -> V_334 [ V_106 ] . V_335 ) ;
if ( ! V_35 )
continue;
V_617 = V_314 -> V_631 + V_106 ;
V_332 = V_314 -> V_334 [ V_106 ] . V_336 &
V_337 ;
switch ( V_332 ) {
case V_632 :
V_629 = L_202 ;
break;
case V_374 :
V_629 = L_203 ;
break;
case V_338 :
V_629 = L_204 ;
break;
case V_633 :
V_629 = L_205 ;
break;
case V_634 :
V_629 = L_206 ;
break;
default:
V_629 = L_47 ;
break;
}
V_566 = V_314 -> V_334 [ V_106 ] . V_635 >> 4 ;
V_630 = V_314 -> V_334 [ V_106 ] . V_635 & 0xF ;
F_13 ( L_207 \
L_208 , V_617 ,
V_35 , V_629 , V_566 , V_630 ) ;
}
}
static int
F_245 ( struct V_13 * V_14 ,
struct V_3 * V_7 )
{
int V_106 ;
T_4 V_589 , V_35 ;
T_4 V_332 ;
T_6 V_617 , V_636 ;
struct V_92 * V_93 ;
T_1 V_17 ;
unsigned long V_76 ;
T_6 V_566 , V_630 ;
T_19 * V_314 =
( T_19 * )
V_7 -> V_314 ;
if ( V_14 -> V_15 & V_637 )
F_244 ( V_14 , V_314 ) ;
if ( V_14 -> V_82 || V_14 -> V_269 || V_14 -> V_270 )
return 0 ;
if ( ! V_14 -> V_39 . V_40 )
F_227 ( V_14 ) ;
else
F_224 ( V_14 ) ;
if ( V_7 -> V_382 ) {
F_46 ( V_14 , F_13 ( V_42
L_209 , V_14 -> V_43 ) ) ;
return 0 ;
}
V_589 = F_21 ( V_314 -> V_375 ) ;
if ( V_314 -> V_376 == V_383 )
if ( F_234 ( V_14 , V_589 ) != 0 )
return 0 ;
F_32 ( & V_14 -> V_94 , V_76 ) ;
V_93 = F_57 ( V_14 ,
V_589 ) ;
if ( V_93 ) {
V_17 = V_93 -> V_17 ;
V_636 = V_93 -> V_40 ;
} else if ( V_589 < V_14 -> V_39 . V_40 ) {
V_17 = V_14 -> V_39 . V_17 ;
V_636 = V_14 -> V_39 . V_40 ;
} else {
F_33 ( & V_14 -> V_94 , V_76 ) ;
return 0 ;
}
F_33 ( & V_14 -> V_94 , V_76 ) ;
for ( V_106 = 0 ; V_106 < V_314 -> V_333 ; V_106 ++ ) {
if ( V_7 -> V_382 ) {
F_46 ( V_14 , F_13 ( V_42
L_209 , V_14 -> V_43 ) ) ;
return 0 ;
}
if ( V_14 -> V_269 || V_14 -> V_270 )
return 0 ;
V_617 = V_314 -> V_631 + V_106 ;
if ( V_617 >= V_636 )
continue;
V_332 = V_314 -> V_334 [ V_106 ] . V_336 &
V_337 ;
if ( ( V_314 -> V_334 [ V_106 ] . V_336 &
V_638 ) && ( V_332 !=
V_374 ) )
continue;
V_35 = F_21 ( V_314 -> V_334 [ V_106 ] . V_335 ) ;
if ( ! V_35 )
continue;
V_566 = V_314 -> V_334 [ V_106 ] . V_635 >> 4 ;
V_630 = V_314 -> V_334 [ V_106 ] . V_635 & 0xF ;
switch ( V_332 ) {
case V_633 :
if ( V_14 -> V_82 )
break;
if ( V_566 == V_630 )
break;
F_226 ( V_14 , V_17 ,
V_35 , V_617 , V_566 ) ;
if ( V_566 < V_571 )
break;
F_242 ( V_14 , V_17 , V_35 ,
V_617 , V_566 ) ;
case V_632 :
if ( V_14 -> V_82 )
break;
F_226 ( V_14 , V_17 ,
V_35 , V_617 , V_566 ) ;
F_243 ( V_14 , V_35 , V_617 , 0 ) ;
break;
case V_374 :
F_42 ( V_14 , V_35 ) ;
break;
}
}
if ( V_314 -> V_376 == V_380 &&
V_93 )
F_238 ( V_14 , V_17 ) ;
return 0 ;
}
static void
F_246 ( struct V_13 * V_14 ,
T_33 * V_314 )
{
char * V_639 = NULL ;
switch ( V_314 -> V_390 ) {
case V_539 :
V_639 = L_210 ;
break;
case V_640 :
V_639 = L_211 ;
break;
case V_641 :
V_639 = L_212 ;
break;
case V_642 :
V_639 = L_213 ;
break;
case V_643 :
V_639 = L_214 ;
break;
case V_644 :
V_639 = L_215 ;
break;
case V_645 :
V_639 = L_216 ;
break;
case V_646 :
V_639 = L_217 ;
break;
case V_647 :
V_639 = L_218 ;
break;
case V_648 :
V_639 = L_219 ;
break;
case V_649 :
V_639 = L_220 ;
break;
case V_650 :
V_639 = L_221 ;
break;
case V_651 :
V_639 = L_222 ;
break;
default:
V_639 = L_223 ;
break;
}
F_13 ( V_42 L_224
L_225 ,
V_14 -> V_43 , V_639 , F_21 ( V_314 -> V_200 ) ,
( unsigned long long ) F_18 ( V_314 -> V_19 ) ,
F_21 ( V_314 -> V_514 ) ) ;
if ( V_314 -> V_390 == V_539 )
F_13 ( V_42 L_226 , V_14 -> V_43 ,
V_314 -> V_540 , V_314 -> V_652 ) ;
F_13 ( L_227 ) ;
}
static void
F_247 ( struct V_13 * V_14 ,
struct V_3 * V_7 )
{
struct V_72 * V_306 ;
struct V_53 * V_54 ;
T_1 V_17 ;
unsigned long V_76 ;
T_33 * V_314 =
( T_33 * )
V_7 -> V_314 ;
if ( V_14 -> V_15 & V_637 )
F_246 ( V_14 ,
V_314 ) ;
if ( ( V_14 -> V_202 . V_653 >> 8 ) < 0xC )
return;
if ( V_314 -> V_390 !=
V_641 &&
V_314 -> V_390 !=
V_647 )
return;
F_32 ( & V_14 -> V_74 , V_76 ) ;
V_17 = F_18 ( V_314 -> V_19 ) ;
V_54 = F_34 ( V_14 ,
V_17 ) ;
if ( ! V_54 || ! V_54 -> V_85 )
goto V_89;
V_306 = V_54 -> V_85 -> V_120 ;
if ( ! V_306 )
goto V_89;
if ( V_314 -> V_390 ==
V_641 )
V_306 -> V_254 = 1 ;
else
V_306 -> V_254 = 0 ;
V_89:
if ( V_54 )
F_41 ( V_54 ) ;
F_33 ( & V_14 -> V_74 , V_76 ) ;
}
static void
F_248 ( struct V_13 * V_14 ,
T_41 * V_314 )
{
char * V_639 = NULL ;
switch ( V_314 -> V_390 ) {
case V_654 :
V_639 = L_228 ;
break;
case V_655 :
V_639 = L_229 ;
break;
default:
V_639 = L_223 ;
break;
}
F_13 ( V_42 L_230
L_231
L_232 , V_14 -> V_43 , V_639 ,
F_21 ( V_314 -> V_526 ) ,
( unsigned long long ) F_18 ( V_314 -> V_24 ) ,
F_21 ( V_314 -> V_656 ) ) ;
}
static void
F_249 ( struct V_13 * V_14 ,
struct V_3 * V_7 )
{
if ( V_14 -> V_15 & V_637 )
F_248 ( V_14 ,
( T_41 * )
V_7 -> V_314 ) ;
}
static void
F_250 ( struct V_13 * V_14 ,
struct V_3 * V_7 )
{
struct V_101 * V_104 ;
struct V_110 * V_75 ;
T_4 V_102 , V_35 ;
T_10 V_109 ;
struct V_116 * V_117 ;
T_10 V_657 ;
T_10 V_658 ;
T_18 * V_37 ;
T_42 * V_314 =
( T_42 * )
V_7 -> V_314 ;
T_4 V_38 ;
unsigned long V_76 ;
int V_2 ;
T_6 V_659 = 0 ;
T_6 V_660 ;
F_113 ( & V_14 -> V_245 . V_266 ) ;
F_13 ( V_42
L_233 ,
V_14 -> V_43 , V_44 , V_314 -> V_618 ,
V_314 -> V_661 ) ;
F_157 ( V_14 ) ;
F_32 ( & V_14 -> V_105 , V_76 ) ;
V_37 = V_14 -> V_245 . V_244 ;
V_662:
if ( V_659 ++ == 5 ) {
F_46 ( V_14 , F_13 ( V_42 L_234 ,
V_14 -> V_43 , V_44 ) ) ;
goto V_89;
} else if ( V_659 > 1 )
F_46 ( V_14 , F_13 ( V_42 L_235 ,
V_14 -> V_43 , V_44 , V_659 - 1 ) ) ;
V_657 = 0 ;
V_658 = 0 ;
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
V_658 ++ ;
if ( V_14 -> V_82 )
goto V_89;
F_33 ( & V_14 -> V_105 , V_76 ) ;
V_2 = F_112 ( V_14 , V_35 , 0 , 0 , V_109 ,
V_298 , V_102 , 30 ,
V_663 ) ;
if ( V_2 == V_267 ) {
F_75 ( V_223 , V_75 ,
L_236
L_237 , V_104 ) ;
F_32 ( & V_14 -> V_105 , V_76 ) ;
goto V_662;
}
V_38 = F_21 ( V_37 -> V_46 )
& V_47 ;
if ( V_38 != V_48 ) {
F_75 ( V_223 , V_75 ,
L_238 ,
V_38 , V_104 ) ;
F_32 ( & V_14 -> V_105 , V_76 ) ;
goto V_662;
}
if ( V_37 -> V_294 ==
V_240 ||
V_37 -> V_294 ==
V_242 ) {
F_32 ( & V_14 -> V_105 , V_76 ) ;
continue;
}
V_660 = 0 ;
V_664:
if ( V_660 ++ == 60 ) {
F_46 ( V_14 , F_13 ( V_42
L_239 , V_14 -> V_43 ,
V_44 ) ) ;
F_32 ( & V_14 -> V_105 , V_76 ) ;
goto V_662;
}
if ( V_14 -> V_82 )
goto V_665;
V_2 = F_112 ( V_14 , V_35 , V_75 -> V_88 , V_75 -> V_87 ,
V_75 -> V_109 , V_279 , V_102 , 30 ,
V_663 ) ;
if ( V_2 == V_267 ) {
F_75 ( V_223 , V_75 ,
L_240
L_241 , V_104 ) ;
goto V_664;
}
if ( V_660 > 1 )
F_75 ( V_223 , V_75 ,
L_242
L_243 ,
V_660 - 1 , V_104 ) ;
V_657 += F_78 ( V_37 -> V_292 ) ;
F_32 ( & V_14 -> V_105 , V_76 ) ;
}
if ( V_14 -> V_666 ) {
F_46 ( V_14 , F_13 ( V_42
L_244 ,
V_14 -> V_43 , V_44 ) ) ;
V_14 -> V_666 = 0 ;
goto V_662;
}
V_89:
F_33 ( & V_14 -> V_105 , V_76 ) ;
V_665:
F_46 ( V_14 , F_13 ( V_42
L_245 ,
V_14 -> V_43 , V_44 , V_658 , V_657 ) ) ;
V_14 -> V_667 = 0 ;
if ( ! V_14 -> V_82 )
F_155 ( V_14 ) ;
F_129 ( & V_14 -> V_245 . V_266 ) ;
}
static void
F_251 ( struct V_13 * V_14 ,
struct V_3 * V_7 )
{
T_43 * V_314 =
( T_43 * ) V_7 -> V_314 ;
if ( V_14 -> V_15 & V_637 ) {
F_13 ( V_42 L_246 , V_14 -> V_43 ,
( V_314 -> V_390 == V_668 ) ?
L_247 : L_248 ) ;
if ( V_314 -> V_669 )
F_13 ( L_249 ,
F_78 ( V_314 -> V_669 ) ) ;
F_13 ( L_227 ) ;
}
if ( V_314 -> V_390 == V_668 &&
! V_14 -> V_39 . V_40 ) {
if ( V_670 > 0 && V_14 -> V_82 ) {
while ( V_14 -> V_82 )
F_252 ( 1 ) ;
}
F_227 ( V_14 ) ;
}
}
static int
F_253 ( struct V_13 * V_14 , T_4 V_35 , T_6 V_671 )
{
T_44 * V_260 ;
T_45 * V_37 ;
T_4 V_102 ;
T_6 V_672 = 0 ;
int V_28 = 0 ;
T_4 V_38 ;
T_10 V_482 ;
if ( V_14 -> V_159 == V_160 )
return V_28 ;
F_113 ( & V_14 -> V_595 . V_266 ) ;
if ( V_14 -> V_595 . V_246 != V_247 ) {
F_25 ( V_42 L_250 ,
V_14 -> V_43 , V_44 ) ;
V_28 = - V_673 ;
goto V_89;
}
V_14 -> V_595 . V_246 = V_251 ;
V_102 = F_165 ( V_14 , V_14 -> V_674 ) ;
if ( ! V_102 ) {
F_25 ( V_42 L_52 ,
V_14 -> V_43 , V_44 ) ;
V_14 -> V_595 . V_246 = V_247 ;
V_28 = - V_673 ;
goto V_89;
}
V_260 = F_120 ( V_14 , V_102 ) ;
V_14 -> V_595 . V_102 = V_102 ;
memset ( V_260 , 0 , sizeof( T_44 ) ) ;
V_260 -> V_280 = V_675 ;
V_260 -> V_519 = V_676 ;
V_260 -> V_199 = V_671 ;
F_46 ( V_14 , F_13 ( V_42 L_251\
L_252 , V_14 -> V_43 ,
V_35 , V_671 ) ) ;
F_123 ( & V_14 -> V_595 . V_252 ) ;
F_167 ( V_14 , V_102 ) ;
F_125 ( & V_14 -> V_595 . V_252 , 10 * V_288 ) ;
if ( ! ( V_14 -> V_595 . V_246 & V_248 ) ) {
F_25 ( V_42 L_54 ,
V_14 -> V_43 , V_44 ) ;
if ( ! ( V_14 -> V_595 . V_246 & V_289 ) )
V_672 = 1 ;
V_28 = - V_677 ;
goto V_89;
}
if ( V_14 -> V_595 . V_246 & V_250 ) {
V_37 = V_14 -> V_595 . V_244 ;
V_38 = F_21 ( V_37 -> V_46 ) ;
if ( V_38 & V_544 )
V_482 = F_78 ( V_37 -> V_291 ) ;
else
V_482 = 0 ;
V_38 &= V_47 ;
if ( V_38 != V_48 ) {
F_46 ( V_14 , F_13 ( V_42
L_253
L_254 , V_14 -> V_43 , V_38 ,
V_482 ) ) ;
V_28 = - V_677 ;
} else
F_46 ( V_14 , F_13 ( V_42
L_255 ,
V_14 -> V_43 ) ) ;
}
V_89:
V_14 -> V_595 . V_246 = V_247 ;
F_129 ( & V_14 -> V_595 . V_266 ) ;
if ( V_672 )
F_116 ( V_14 , V_272 ,
V_273 ) ;
return V_28 ;
}
static void
F_254 ( struct V_110 * V_75 , void * V_143 )
{
int V_28 ;
V_75 -> V_143 = V_143 ? 1 : 0 ;
F_75 ( V_144 , V_75 , L_256 ,
V_75 -> V_143 ? L_257 : L_258 ) ;
V_28 = F_255 ( V_75 ) ;
}
static void
F_256 ( struct V_13 * V_14 ,
T_24 * V_386 )
{
struct V_55 * V_56 ;
unsigned long V_76 ;
T_1 V_60 ;
T_4 V_35 = F_21 ( V_386 -> V_393 ) ;
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
V_56 -> V_87 = V_14 -> V_678 ++ ;
V_56 -> V_88 = V_133 ;
V_56 -> V_35 = V_35 ;
V_56 -> V_60 = V_60 ;
F_54 ( V_14 , V_56 ) ;
if ( ! V_14 -> V_627 ) {
V_28 = F_257 ( V_14 -> V_113 , V_133 ,
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
F_258 ( struct V_13 * V_14 , T_4 V_35 )
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
V_118 -> V_342 = 1 ;
}
F_13 ( V_42 L_259 ,
V_14 -> V_43 , V_56 -> V_35 ,
( unsigned long long ) V_56 -> V_60 ) ;
F_56 ( & V_56 -> V_81 ) ;
F_2 ( V_56 ) ;
}
F_33 ( & V_14 -> V_90 , V_76 ) ;
if ( V_85 )
F_259 ( & V_85 -> V_127 ) ;
}
static void
F_260 ( struct V_13 * V_14 ,
T_24 * V_386 )
{
struct V_53 * V_54 ;
struct V_126 * V_85 = NULL ;
struct V_72 * V_118 ;
unsigned long V_76 ;
T_4 V_35 = F_21 ( V_386 -> V_395 ) ;
F_32 ( & V_14 -> V_74 , V_76 ) ;
V_54 = F_36 ( V_14 , V_35 ) ;
if ( V_54 ) {
V_54 -> V_208 = 0 ;
V_54 -> V_209 = 0 ;
F_183 ( V_35 , V_14 -> V_137 ) ;
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
F_261 ( V_85 , NULL , F_254 ) ;
F_41 ( V_54 ) ;
}
static void
F_262 ( struct V_13 * V_14 ,
T_24 * V_386 )
{
struct V_53 * V_54 ;
struct V_126 * V_85 = NULL ;
struct V_72 * V_118 ;
unsigned long V_76 ;
T_4 V_35 = F_21 ( V_386 -> V_395 ) ;
T_4 V_208 = 0 ;
T_1 V_209 = 0 ;
F_100 ( V_14 , V_35 , & V_208 ) ;
if ( V_208 )
F_101 ( V_14 , V_208 ,
& V_209 ) ;
F_32 ( & V_14 -> V_74 , V_76 ) ;
V_54 = F_36 ( V_14 , V_35 ) ;
if ( V_54 ) {
F_160 ( V_35 , V_14 -> V_137 ) ;
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
F_253 ( V_14 , V_35 , V_386 -> V_199 ) ;
if ( V_85 )
F_261 ( V_85 , ( void * ) 1 , F_254 ) ;
F_41 ( V_54 ) ;
}
static void
F_263 ( struct V_13 * V_14 ,
T_24 * V_386 )
{
T_4 V_35 = F_21 ( V_386 -> V_395 ) ;
F_42 ( V_14 , V_35 ) ;
}
static void
F_264 ( struct V_13 * V_14 ,
T_24 * V_386 )
{
struct V_53 * V_54 ;
T_4 V_35 = F_21 ( V_386 -> V_395 ) ;
T_9 V_37 ;
T_8 V_36 ;
T_10 V_38 ;
T_1 V_17 ;
T_4 V_589 ;
F_160 ( V_35 , V_14 -> V_137 ) ;
V_54 = F_37 ( V_14 , V_35 ) ;
if ( V_54 ) {
F_253 ( V_14 , V_35 , V_386 -> V_199 ) ;
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
V_589 = F_21 ( V_36 . V_591 ) ;
if ( ! F_23 ( V_14 , V_589 , & V_17 ) )
F_226 ( V_14 , V_17 , V_35 ,
V_36 . V_618 , V_571 ) ;
F_253 ( V_14 , V_35 , V_386 -> V_199 ) ;
F_243 ( V_14 , V_35 , 0 , 1 ) ;
}
static void
F_265 ( struct V_13 * V_14 ,
T_23 * V_314 )
{
T_24 * V_386 ;
T_6 V_679 ;
int V_106 ;
char * V_639 = NULL , * V_680 = NULL ;
V_386 = ( T_24 * ) & V_314 -> V_387 [ 0 ] ;
F_13 ( V_42 L_260 ,
V_14 -> V_43 , ( F_78 ( V_314 -> V_145 ) &
V_389 ) ?
L_261 : L_262 , V_314 -> V_388 ) ;
for ( V_106 = 0 ; V_106 < V_314 -> V_388 ; V_106 ++ , V_386 ++ ) {
switch ( V_386 -> V_390 ) {
case V_681 :
V_639 = L_194 ;
break;
case V_392 :
V_639 = L_195 ;
break;
case V_682 :
V_639 = L_263 ;
break;
case V_683 :
V_639 = L_264 ;
break;
case V_394 :
V_639 = L_265 ;
break;
case V_684 :
V_639 = L_266 ;
break;
case V_391 :
V_639 = L_267 ;
break;
case V_685 :
V_639 = L_268 ;
break;
case V_686 :
V_639 = L_269 ;
break;
default:
V_639 = L_223 ;
break;
}
V_679 = F_21 ( V_386 -> V_687 ) &
V_688 ;
switch ( V_679 ) {
case V_689 :
V_680 = L_58 ;
break;
case V_690 :
V_680 = L_270 ;
break;
case V_691 :
V_680 = L_271 ;
break;
default:
V_680 = L_272 ;
break;
}
F_13 ( L_273 \
L_274 , V_680 ,
V_639 , F_21 ( V_386 -> V_393 ) ,
F_21 ( V_386 -> V_395 ) ,
V_386 -> V_199 ) ;
}
}
static void
F_266 ( struct V_13 * V_14 ,
struct V_3 * V_7 )
{
T_24 * V_386 ;
int V_106 ;
T_6 V_692 ;
T_23 * V_314 =
( T_23 * )
V_7 -> V_314 ;
if ( ( V_14 -> V_15 & V_637 ) &&
( ! V_14 -> V_218 ) )
F_265 ( V_14 , V_314 ) ;
V_692 = ( F_78 ( V_314 -> V_145 ) &
V_389 ) ? 1 : 0 ;
V_386 = ( T_24 * ) & V_314 -> V_387 [ 0 ] ;
if ( V_14 -> V_82 &&
V_14 -> V_159 != V_160 ) {
for ( V_106 = 0 ; V_106 < V_314 -> V_388 ; V_106 ++ , V_386 ++ ) {
if ( V_386 -> V_390 == V_683 )
F_253 ( V_14 ,
F_21 ( V_386 -> V_395 ) ,
V_386 -> V_199 ) ;
}
return;
}
for ( V_106 = 0 ; V_106 < V_314 -> V_388 ; V_106 ++ , V_386 ++ ) {
switch ( V_386 -> V_390 ) {
case V_684 :
case V_681 :
if ( ! V_692 )
F_256 ( V_14 , V_386 ) ;
break;
case V_391 :
case V_392 :
if ( ! V_692 )
F_258 ( V_14 ,
F_21 ( V_386 -> V_393 ) ) ;
break;
case V_685 :
if ( ! V_14 -> V_134 )
F_262 ( V_14 , V_386 ) ;
break;
case V_686 :
if ( ! V_14 -> V_134 )
F_260 ( V_14 , V_386 ) ;
break;
case V_683 :
if ( ! V_14 -> V_134 )
F_264 ( V_14 , V_386 ) ;
break;
case V_394 :
if ( ! V_14 -> V_134 )
F_263 ( V_14 , V_386 ) ;
break;
}
}
}
static void
F_267 ( struct V_13 * V_14 ,
struct V_3 * V_7 )
{
T_1 V_60 ;
unsigned long V_76 ;
struct V_55 * V_56 ;
T_4 V_35 ;
T_10 V_167 ;
int V_28 ;
T_25 * V_314 =
( T_25 * ) V_7 -> V_314 ;
if ( V_14 -> V_82 )
return;
if ( V_314 -> V_390 != V_396 )
return;
V_35 = F_21 ( V_314 -> V_393 ) ;
V_167 = F_78 ( V_314 -> V_397 ) ;
if ( ! V_14 -> V_218 )
F_46 ( V_14 , F_13 ( V_42
L_275 ,
V_14 -> V_43 , V_44 , V_35 ,
F_78 ( V_314 -> V_693 ) , V_167 ) ) ;
switch ( V_167 ) {
case V_177 :
case V_176 :
F_258 ( V_14 , V_35 ) ;
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
V_56 -> V_87 = V_14 -> V_678 ++ ;
V_56 -> V_88 = V_133 ;
V_56 -> V_35 = V_35 ;
V_56 -> V_60 = V_60 ;
F_54 ( V_14 , V_56 ) ;
V_28 = F_257 ( V_14 -> V_113 , V_133 ,
V_56 -> V_87 , 0 ) ;
if ( V_28 )
F_55 ( V_14 , V_56 ) ;
break;
case V_694 :
default:
break;
}
}
static void
F_268 ( struct V_13 * V_14 ,
struct V_3 * V_7 )
{
T_4 V_35 , V_589 ;
T_10 V_167 ;
struct V_53 * V_54 ;
T_9 V_37 ;
T_8 V_36 ;
T_10 V_38 ;
T_46 * V_314 =
( T_46 * ) V_7 -> V_314 ;
T_1 V_17 ;
if ( V_14 -> V_82 )
return;
if ( V_314 -> V_390 != V_695 )
return;
V_35 = F_21 ( V_314 -> V_395 ) ;
V_167 = F_78 ( V_314 -> V_397 ) ;
if ( ! V_14 -> V_218 )
F_46 ( V_14 , F_13 ( V_42
L_275 ,
V_14 -> V_43 , V_44 , V_35 ,
F_78 ( V_314 -> V_693 ) , V_167 ) ) ;
switch ( V_167 ) {
case V_696 :
case V_697 :
case V_698 :
case V_699 :
case V_700 :
if ( ! V_14 -> V_134 )
F_160 ( V_35 , V_14 -> V_137 ) ;
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
V_589 = F_21 ( V_36 . V_591 ) ;
if ( ! F_23 ( V_14 , V_589 , & V_17 ) )
F_226 ( V_14 , V_17 , V_35 ,
V_36 . V_618 , V_571 ) ;
F_243 ( V_14 , V_35 , 0 , 1 ) ;
break;
case V_701 :
case V_702 :
case V_703 :
default:
break;
}
}
static void
F_269 ( struct V_13 * V_14 ,
T_47 * V_314 )
{
char * V_639 = NULL ;
switch ( V_314 -> V_704 ) {
case V_705 :
V_639 = L_276 ;
break;
case V_706 :
V_639 = L_277 ;
break;
case V_707 :
V_639 = L_278 ;
break;
case V_708 :
V_639 = L_279 ;
break;
case V_709 :
V_639 = L_280 ;
break;
}
if ( ! V_639 )
return;
F_13 ( V_42 L_281 \
L_282 ,
V_14 -> V_43 , V_639 ,
F_21 ( V_314 -> V_393 ) ,
V_314 -> V_710 ) ;
}
static void
F_270 ( struct V_13 * V_14 ,
struct V_3 * V_7 )
{
T_47 * V_314 =
( T_47 * )
V_7 -> V_314 ;
static struct V_55 * V_56 ;
unsigned long V_76 ;
T_4 V_35 ;
if ( ( V_14 -> V_15 & V_637 ) &&
( ! V_14 -> V_218 ) )
F_269 ( V_14 ,
V_314 ) ;
if ( V_314 -> V_704 == V_705 ) {
F_32 ( & V_14 -> V_90 , V_76 ) ;
V_35 = F_21 ( V_314 -> V_393 ) ;
V_56 = F_52 ( V_14 , V_35 ) ;
if ( V_56 )
V_56 -> V_155 =
V_314 -> V_710 ;
F_33 ( & V_14 -> V_90 , V_76 ) ;
}
}
static void
F_271 ( struct V_13 * V_14 )
{
struct V_116 * V_117 ;
struct V_110 * V_75 ;
F_110 (sdev, ioc->shost) {
V_117 = V_75 -> V_120 ;
if ( V_117 && V_117 -> V_122 )
V_117 -> V_122 -> V_342 = 1 ;
}
}
static void
F_272 ( struct V_13 * V_14 ,
T_8 * V_36 )
{
struct V_72 * V_118 = NULL ;
struct V_126 * V_85 ;
struct V_53 * V_54 ;
unsigned long V_76 ;
F_32 ( & V_14 -> V_74 , V_76 ) ;
F_15 (sas_device, &ioc->sas_device_list, list) {
if ( ( V_54 -> V_17 == V_36 -> V_19 ) &&
( V_54 -> V_26 == V_36 -> V_525 ) ) {
V_54 -> V_711 = 1 ;
V_85 = V_54 -> V_85 ;
if ( V_85 && V_85 -> V_120 ) {
V_118 = V_85 -> V_120 ;
V_118 -> V_254 = 0 ;
V_118 -> V_342 = 0 ;
} else
V_118 = NULL ;
if ( V_85 ) {
F_132 ( V_144 , V_85 ,
L_283 ,
V_36 -> V_200 ,
( unsigned long long )
V_54 -> V_17 ) ;
if ( V_54 -> V_78 != 0 )
F_132 ( V_144 , V_85 ,
L_284
L_95 ,
( unsigned long long )
V_54 -> V_22 ,
V_54 -> V_26 ) ;
}
if ( V_36 -> V_145 &
V_619 ) {
V_54 -> V_80 =
F_21 ( V_36 -> V_620 ) ;
memcpy ( & V_54 -> V_79 [ 0 ] ,
& V_36 -> V_621 [ 0 ] , 4 ) ;
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
F_273 ( struct V_13 * V_14 )
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
& V_36 , V_712 ,
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
V_36 . V_525 = F_21 ( V_36 . V_525 ) ;
F_272 ( V_14 , & V_36 ) ;
}
V_89:
F_13 ( V_42 L_287 ,
V_14 -> V_43 ) ;
}
static void
F_274 ( struct V_13 * V_14 , T_1 V_60 ,
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
V_118 -> V_342 = 0 ;
} else
V_118 = NULL ;
V_56 -> V_711 = 1 ;
F_33 ( & V_14 -> V_90 , V_76 ) ;
F_132 ( V_144 , V_56 -> V_85 ,
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
F_275 ( struct V_13 * V_14 )
{
T_48 V_713 ;
T_11 V_714 ;
T_12 V_192 ;
T_9 V_37 ;
T_4 V_38 ;
T_4 V_35 ;
T_6 V_671 ;
if ( ! V_14 -> V_715 )
return;
F_13 ( V_42 L_289 ,
V_14 -> V_43 ) ;
if ( F_39 ( & V_14 -> V_91 ) )
goto V_89;
V_35 = 0xFFFF ;
while ( ! ( F_276 ( V_14 , & V_37 ,
& V_713 , V_716 , V_35 ) ) ) {
V_38 = F_21 ( V_37 . V_46 ) &
V_47 ;
if ( V_38 != V_48 )
break;
V_35 = F_21 ( V_713 . V_200 ) ;
if ( F_82 ( V_14 , & V_37 ,
& V_714 , V_156 , V_35 ,
sizeof( T_11 ) ) )
continue;
if ( V_714 . V_170 == V_171 ||
V_714 . V_170 == V_172 ||
V_714 . V_170 == V_174 )
F_274 ( V_14 ,
F_18 ( V_713 . V_717 ) , V_35 ) ;
}
if ( ! V_14 -> V_134 ) {
V_671 = 0xFF ;
memset ( V_14 -> V_137 , 0 , V_14 -> V_718 ) ;
while ( ! ( F_93 ( V_14 , & V_37 ,
& V_192 , V_719 ,
V_671 ) ) ) {
V_38 = F_21 ( V_37 . V_46 ) &
V_47 ;
if ( V_38 != V_48 )
break;
V_671 = V_192 . V_199 ;
V_35 = F_21 ( V_192 . V_200 ) ;
F_160 ( V_35 , V_14 -> V_137 ) ;
}
}
V_89:
F_13 ( V_42 L_290 ,
V_14 -> V_43 ) ;
}
static void
F_277 ( struct V_13 * V_14 , T_1 V_17 ,
T_4 V_35 )
{
struct V_92 * V_93 ;
unsigned long V_76 ;
int V_106 ;
F_32 ( & V_14 -> V_94 , V_76 ) ;
F_15 (sas_expander, &ioc->sas_expander_list, list) {
if ( V_93 -> V_17 != V_17 )
continue;
V_93 -> V_711 = 1 ;
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
F_278 ( struct V_13 * V_14 )
{
T_39 V_587 ;
T_9 V_37 ;
T_4 V_38 ;
T_1 V_17 ;
T_4 V_35 ;
F_13 ( V_42 L_293 , V_14 -> V_43 ) ;
if ( F_39 ( & V_14 -> V_95 ) )
goto V_89;
V_35 = 0xFFFF ;
while ( ! ( F_235 ( V_14 , & V_37 , & V_587 ,
V_720 , V_35 ) ) ) {
V_38 = F_21 ( V_37 . V_46 ) &
V_47 ;
if ( V_38 != V_48 )
break;
V_35 = F_21 ( V_587 . V_200 ) ;
V_17 = F_18 ( V_587 . V_19 ) ;
F_13 ( L_294 ,
V_35 ,
( unsigned long long ) V_17 ) ;
F_277 ( V_14 , V_17 , V_35 ) ;
}
V_89:
F_13 ( V_42 L_295 , V_14 -> V_43 ) ;
}
static void
F_279 ( struct V_13 * V_14 )
{
struct V_53 * V_54 , * V_721 ;
struct V_92 * V_93 , * V_722 ;
struct V_55 * V_56 , * V_723 ;
struct V_724 V_725 ;
unsigned long V_76 ;
F_280 ( V_726 ) ;
F_13 ( V_42 L_296 ,
V_14 -> V_43 ) ;
F_13 ( V_42 L_297 ,
V_14 -> V_43 ) ;
F_32 ( & V_14 -> V_74 , V_76 ) ;
F_281 (sas_device, sas_device_next,
&ioc->sas_device_list, list) {
if ( ! V_54 -> V_711 )
F_282 ( & V_54 -> V_81 , & V_726 ) ;
else
V_54 -> V_711 = 0 ;
}
F_33 ( & V_14 -> V_74 , V_76 ) ;
F_281 (sas_device, sas_device_next, &head, list) {
F_43 ( V_14 , V_54 ) ;
F_40 ( & V_54 -> V_81 ) ;
F_41 ( V_54 ) ;
}
if ( V_14 -> V_715 ) {
F_13 ( V_42 L_298 ,
V_14 -> V_43 ) ;
F_281 (raid_device, raid_device_next,
&ioc->raid_device_list, list) {
if ( ! V_56 -> V_711 )
F_258 ( V_14 ,
V_56 -> V_35 ) ;
else
V_56 -> V_711 = 0 ;
}
}
F_13 ( V_42 L_299 ,
V_14 -> V_43 ) ;
F_32 ( & V_14 -> V_94 , V_76 ) ;
F_139 ( & V_725 ) ;
F_281 (sas_expander, sas_expander_next,
&ioc->sas_expander_list, list) {
if ( ! V_93 -> V_711 )
F_282 ( & V_93 -> V_81 , & V_725 ) ;
else
V_93 -> V_711 = 0 ;
}
F_33 ( & V_14 -> V_94 , V_76 ) ;
F_281 (sas_expander, sas_expander_next, &tmp_list,
list) {
F_56 ( & V_93 -> V_81 ) ;
F_239 ( V_14 , V_93 ) ;
}
F_13 ( V_42 L_300 ,
V_14 -> V_43 ) ;
F_155 ( V_14 ) ;
}
static void
F_283 ( struct V_13 * V_14 ,
struct V_92 * V_93 , T_4 V_35 )
{
T_40 V_588 ;
T_9 V_37 ;
int V_106 ;
for ( V_106 = 0 ; V_106 < V_93 -> V_40 ; V_106 ++ ) {
if ( ( F_236 ( V_14 , & V_37 ,
& V_588 , V_106 , V_35 ) ) ) {
F_25 ( V_42 L_2 ,
V_14 -> V_43 , __FILE__ , __LINE__ , V_44 ) ;
return;
}
F_226 ( V_14 , V_93 -> V_17 ,
F_21 ( V_588 . V_335 ) , V_106 ,
V_588 . V_569 >> 4 ) ;
}
}
static void
F_284 ( struct V_13 * V_14 )
{
T_39 V_587 ;
T_8 V_36 ;
T_48 V_713 ;
T_11 V_714 ;
T_12 V_192 ;
T_24 V_386 ;
T_9 V_37 ;
T_6 V_671 ;
T_4 V_38 ;
T_4 V_35 , V_589 ;
T_1 V_17 ;
struct V_53 * V_54 ;
struct V_92 * V_727 ;
static struct V_55 * V_56 ;
T_6 V_728 ;
unsigned long V_76 ;
F_13 ( V_42 L_301 , V_14 -> V_43 ) ;
F_224 ( V_14 ) ;
F_13 ( V_42 L_302 , V_14 -> V_43 ) ;
V_35 = 0xFFFF ;
while ( ! ( F_235 ( V_14 , & V_37 , & V_587 ,
V_720 , V_35 ) ) ) {
V_38 = F_21 ( V_37 . V_46 ) &
V_47 ;
if ( V_38 != V_48 ) {
F_13 ( V_42 L_303 \
L_304 ,
V_14 -> V_43 , V_38 ,
F_78 ( V_37 . V_291 ) ) ;
break;
}
V_35 = F_21 ( V_587 . V_200 ) ;
F_32 ( & V_14 -> V_94 , V_76 ) ;
V_727 = F_58 (
V_14 , F_18 ( V_587 . V_19 ) ) ;
F_33 ( & V_14 -> V_94 , V_76 ) ;
if ( V_727 )
F_283 ( V_14 , V_727 ,
V_35 ) ;
else {
F_13 ( V_42 L_305 \
L_306 , V_14 -> V_43 ,
V_35 , ( unsigned long long )
F_18 ( V_587 . V_19 ) ) ;
F_234 ( V_14 , V_35 ) ;
F_13 ( V_42 L_307 \
L_306 , V_14 -> V_43 ,
V_35 , ( unsigned long long )
F_18 ( V_587 . V_19 ) ) ;
}
}
F_13 ( V_42 L_308 ,
V_14 -> V_43 ) ;
if ( ! V_14 -> V_715 )
goto V_729;
F_13 ( V_42 L_309 , V_14 -> V_43 ) ;
V_671 = 0xFF ;
while ( ! ( F_93 ( V_14 , & V_37 ,
& V_192 , V_719 ,
V_671 ) ) ) {
V_38 = F_21 ( V_37 . V_46 ) &
V_47 ;
if ( V_38 != V_48 ) {
F_13 ( V_42 L_310\
L_304 ,
V_14 -> V_43 , V_38 ,
F_78 ( V_37 . V_291 ) ) ;
break;
}
V_671 = V_192 . V_199 ;
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
F_78 ( V_37 . V_291 ) ) ;
break;
}
V_589 = F_21 ( V_36 . V_591 ) ;
if ( ! F_23 ( V_14 , V_589 ,
& V_17 ) ) {
F_13 ( V_42 L_312 \
L_313 ,
V_14 -> V_43 , V_35 , ( unsigned long long )
F_18 ( V_36 . V_19 ) ) ;
F_226 ( V_14 , V_17 ,
V_35 , V_36 . V_618 ,
V_571 ) ;
F_160 ( V_35 , V_14 -> V_137 ) ;
V_728 = 0 ;
while ( F_243 ( V_14 , V_35 , V_728 ++ ,
1 ) ) {
F_252 ( 1 ) ;
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
while ( ! ( F_276 ( V_14 , & V_37 ,
& V_713 , V_716 , V_35 ) ) ) {
V_38 = F_21 ( V_37 . V_46 ) &
V_47 ;
if ( V_38 != V_48 ) {
F_13 ( V_42 L_317 \
L_304 ,
V_14 -> V_43 , V_38 ,
F_78 ( V_37 . V_291 ) ) ;
break;
}
V_35 = F_21 ( V_713 . V_200 ) ;
F_32 ( & V_14 -> V_90 , V_76 ) ;
V_56 = F_53 ( V_14 ,
F_18 ( V_713 . V_717 ) ) ;
F_33 ( & V_14 -> V_90 , V_76 ) ;
if ( V_56 )
continue;
if ( F_82 ( V_14 , & V_37 ,
& V_714 , V_156 , V_35 ,
sizeof( T_11 ) ) )
continue;
V_38 = F_21 ( V_37 . V_46 ) &
V_47 ;
if ( V_38 != V_48 ) {
F_13 ( V_42 L_317 \
L_304 ,
V_14 -> V_43 , V_38 ,
F_78 ( V_37 . V_291 ) ) ;
break;
}
if ( V_714 . V_170 == V_171 ||
V_714 . V_170 == V_172 ||
V_714 . V_170 == V_174 ) {
memset ( & V_386 , 0 , sizeof( T_24 ) ) ;
V_386 . V_390 = V_681 ;
V_386 . V_393 = V_713 . V_200 ;
F_13 ( V_42
L_318 ,
V_14 -> V_43 , V_713 . V_200 ) ;
F_256 ( V_14 , & V_386 ) ;
F_13 ( V_42
L_319 ,
V_14 -> V_43 , V_713 . V_200 ) ;
}
}
F_13 ( V_42 L_320 ,
V_14 -> V_43 ) ;
V_729:
F_13 ( V_42 L_321 ,
V_14 -> V_43 ) ;
V_35 = 0xFFFF ;
while ( ! ( F_24 ( V_14 , & V_37 ,
& V_36 , V_712 ,
V_35 ) ) ) {
V_38 = F_21 ( V_37 . V_46 ) &
V_47 ;
if ( V_38 != V_48 ) {
F_13 ( V_42 L_322\
L_323 ,
V_14 -> V_43 , V_38 ,
F_78 ( V_37 . V_291 ) ) ;
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
V_589 = F_21 ( V_36 . V_591 ) ;
if ( ! F_23 ( V_14 , V_589 , & V_17 ) ) {
F_13 ( V_42 L_324 \
L_306 , V_14 -> V_43 ,
V_35 , ( unsigned long long )
F_18 ( V_36 . V_19 ) ) ;
F_226 ( V_14 , V_17 , V_35 ,
V_36 . V_618 , V_571 ) ;
V_728 = 0 ;
while ( F_243 ( V_14 , V_35 , V_728 ++ ,
0 ) ) {
F_252 ( 1 ) ;
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
F_285 ( struct V_13 * V_14 , int V_730 )
{
switch ( V_730 ) {
case V_731 :
F_119 ( V_14 , F_13 ( V_42
L_328 , V_14 -> V_43 , V_44 ) ) ;
break;
case V_732 :
F_119 ( V_14 , F_13 ( V_42
L_329 , V_14 -> V_43 , V_44 ) ) ;
if ( V_14 -> V_595 . V_246 & V_251 ) {
V_14 -> V_595 . V_246 |= V_289 ;
F_176 ( V_14 , V_14 -> V_595 . V_102 ) ;
F_108 ( & V_14 -> V_595 . V_252 ) ;
}
if ( V_14 -> V_245 . V_246 & V_251 ) {
V_14 -> V_245 . V_246 |= V_289 ;
F_176 ( V_14 , V_14 -> V_245 . V_102 ) ;
F_108 ( & V_14 -> V_245 . V_252 ) ;
}
F_148 ( V_14 ) ;
F_187 ( V_14 ) ;
break;
case V_733 :
F_119 ( V_14 , F_13 ( V_42
L_330 , V_14 -> V_43 , V_44 ) ) ;
if ( ( ! V_14 -> V_57 ) && ! ( V_670 > 0 &&
! V_14 -> V_39 . V_40 ) ) {
F_271 ( V_14 ) ;
F_273 ( V_14 ) ;
F_275 ( V_14 ) ;
F_278 ( V_14 ) ;
F_144 ( V_14 ) ;
}
break;
}
}
static void
F_286 ( struct V_13 * V_14 , struct V_3 * V_7 )
{
F_142 ( V_14 , V_7 ) ;
if ( V_14 -> V_269 || V_14 -> V_270 ) {
F_6 ( V_7 ) ;
return;
}
switch ( V_7 -> V_315 ) {
case V_316 :
F_287 ( V_14 ,
(struct V_313 * )
V_7 -> V_314 ) ;
break;
case V_317 :
while ( F_288 ( V_14 -> V_113 ) ||
V_14 -> V_82 ) {
if ( V_14 -> V_269 )
goto V_89;
F_252 ( 1 ) ;
}
F_279 ( V_14 ) ;
F_284 ( V_14 ) ;
break;
case V_318 :
V_14 -> V_734 = 0 ;
if ( V_735 [ 0 ] != - 1 && V_735 [ 1 ] != - 1 )
F_289 ( V_14 , V_735 [ 0 ] ,
V_735 [ 1 ] ) ;
F_46 ( V_14 , F_13 ( V_42
L_331 ,
V_14 -> V_43 ) ) ;
break;
case V_528 :
F_207 ( V_14 , V_7 -> V_529 ) ;
break;
case V_381 :
F_245 ( V_14 , V_7 ) ;
break;
case V_537 :
F_247 ( V_14 , V_7 ) ;
break;
case V_736 :
F_251 ( V_14 , V_7 ) ;
break;
case V_737 :
F_250 ( V_14 , V_7 ) ;
break;
case V_738 :
F_249 ( V_14 ,
V_7 ) ;
break;
case V_739 :
F_266 ( V_14 , V_7 ) ;
break;
case V_740 :
F_267 ( V_14 , V_7 ) ;
break;
case V_741 :
F_268 ( V_14 , V_7 ) ;
break;
case V_742 :
F_270 ( V_14 , V_7 ) ;
break;
}
V_89:
F_6 ( V_7 ) ;
}
static void
V_312 ( struct V_743 * V_311 )
{
struct V_3 * V_7 = F_3 ( V_311 ,
struct V_3 , V_311 ) ;
F_286 ( V_7 -> V_14 , V_7 ) ;
}
T_6
F_290 ( struct V_13 * V_14 , T_6 V_243 ,
T_10 V_244 )
{
struct V_3 * V_7 ;
T_32 * V_37 ;
T_4 V_315 ;
T_4 V_193 ;
T_49 * V_744 ;
if ( V_14 -> V_269 || V_14 -> V_270 )
return 1 ;
V_37 = F_107 ( V_14 , V_244 ) ;
if ( F_164 ( ! V_37 ) ) {
F_25 ( V_42 L_103 ,
V_14 -> V_43 , __FILE__ , __LINE__ , V_44 ) ;
return 1 ;
}
V_315 = F_21 ( V_37 -> V_364 ) ;
if ( V_315 != V_745 )
F_291 ( V_14 , V_315 , 0 ) ;
switch ( V_315 ) {
case V_737 :
{
T_42 * V_746 =
( T_42 * )
V_37 -> V_535 ;
if ( V_746 -> V_747 !=
V_748 )
return 1 ;
if ( V_14 -> V_667 ) {
V_14 -> V_666 ++ ;
return 1 ;
} else
V_14 -> V_667 = 1 ;
break;
}
case V_381 :
F_177 ( V_14 ,
( T_19 * )
V_37 -> V_535 ) ;
break;
case V_739 :
F_182 ( V_14 ,
( T_23 * )
V_37 -> V_535 ) ;
break;
case V_740 :
F_185 ( V_14 ,
( T_25 * )
V_37 -> V_535 ) ;
break;
case V_745 :
{
T_50 * V_749 ;
T_10 * V_750 ;
if ( ! V_14 -> V_134 )
break;
V_749 = ( T_50 * )
V_37 -> V_535 ;
V_750 = ( T_10 * ) V_749 -> V_751 ;
if ( F_21 ( V_749 -> V_752 )
!= V_753 )
break;
switch ( F_78 ( * V_750 ) ) {
case V_754 :
F_91 ( V_42 L_332
L_333
L_334
L_335 , V_14 -> V_43 ) ;
break;
case V_755 :
F_91 ( V_42 L_332
L_336
L_337
L_338 , V_14 -> V_43 ) ;
break;
case V_756 :
F_25 ( V_42 L_339
L_340
L_341
L_342
L_338 , V_14 -> V_43 ) ;
break;
case V_757 :
F_25 ( V_42 L_339
L_343
L_344
L_345 ,
V_14 -> V_43 ) ;
break;
}
break;
}
case V_537 :
case V_742 :
case V_736 :
case V_738 :
case V_741 :
break;
case V_758 :
F_186 ( V_14 ,
( T_26 * )
V_37 -> V_535 ) ;
break;
case V_759 :
V_744 =
( T_49 * ) V_37 -> V_535 ;
if ( V_744 -> V_390 ==
V_760 ) {
F_13 ( V_42 L_346 ,
V_14 -> V_43 , V_744 -> V_761 ) ;
F_13 ( L_347 ) ;
F_13 ( L_348 ) ;
F_13 ( L_349 ,
V_744 -> V_762 ) ;
}
break;
default:
return 1 ;
}
V_193 = F_21 ( V_37 -> V_538 ) * 4 ;
V_7 = F_8 ( V_193 ) ;
if ( ! V_7 ) {
F_25 ( V_42 L_2 ,
V_14 -> V_43 , __FILE__ , __LINE__ , V_44 ) ;
return 1 ;
}
memcpy ( V_7 -> V_314 , V_37 -> V_535 , V_193 ) ;
V_7 -> V_14 = V_14 ;
V_7 -> V_366 = V_37 -> V_366 ;
V_7 -> V_367 = V_37 -> V_367 ;
V_7 -> V_315 = V_315 ;
F_138 ( V_14 , V_7 ) ;
F_6 ( V_7 ) ;
return 1 ;
}
static void
F_239 ( struct V_13 * V_14 ,
struct V_92 * V_93 )
{
struct V_323 * V_324 , * V_371 ;
F_281 (mpt3sas_port, next,
&sas_expander->sas_port_list, port_list) {
if ( V_14 -> V_82 )
return;
if ( V_324 -> V_326 . V_327 ==
V_328 )
F_44 ( V_14 ,
V_324 -> V_326 . V_17 ) ;
else if ( V_324 -> V_326 . V_327 ==
V_330 ||
V_324 -> V_326 . V_327 ==
V_331 )
F_238 ( V_14 ,
V_324 -> V_326 . V_17 ) ;
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
F_292 ( struct V_13 * V_14 )
{
T_44 * V_260 ;
T_45 * V_37 ;
T_4 V_102 ;
if ( ! V_14 -> V_715 )
return;
if ( F_39 ( & V_14 -> V_91 ) )
return;
F_113 ( & V_14 -> V_595 . V_266 ) ;
if ( V_14 -> V_595 . V_246 != V_247 ) {
F_25 ( V_42 L_250 ,
V_14 -> V_43 , V_44 ) ;
goto V_89;
}
V_14 -> V_595 . V_246 = V_251 ;
V_102 = F_165 ( V_14 , V_14 -> V_674 ) ;
if ( ! V_102 ) {
F_25 ( V_42 L_52 ,
V_14 -> V_43 , V_44 ) ;
V_14 -> V_595 . V_246 = V_247 ;
goto V_89;
}
V_260 = F_120 ( V_14 , V_102 ) ;
V_14 -> V_595 . V_102 = V_102 ;
memset ( V_260 , 0 , sizeof( T_44 ) ) ;
V_260 -> V_280 = V_675 ;
V_260 -> V_519 = V_763 ;
if ( ! V_14 -> V_218 )
F_13 ( V_42 L_351 , V_14 -> V_43 ) ;
F_123 ( & V_14 -> V_595 . V_252 ) ;
F_167 ( V_14 , V_102 ) ;
F_125 ( & V_14 -> V_595 . V_252 , 10 * V_288 ) ;
if ( ! ( V_14 -> V_595 . V_246 & V_248 ) ) {
F_25 ( V_42 L_54 ,
V_14 -> V_43 , V_44 ) ;
goto V_89;
}
if ( V_14 -> V_595 . V_246 & V_250 ) {
V_37 = V_14 -> V_595 . V_244 ;
if ( ! V_14 -> V_218 )
F_13 ( V_42 L_352
L_353 ,
V_14 -> V_43 , F_21 ( V_37 -> V_46 ) ,
F_78 ( V_37 -> V_291 ) ) ;
}
V_89:
V_14 -> V_595 . V_246 = V_247 ;
F_129 ( & V_14 -> V_595 . V_266 ) ;
}
void F_293 ( struct V_764 * V_532 )
{
struct V_112 * V_113 = F_294 ( V_532 ) ;
struct V_13 * V_14 = F_67 ( V_113 ) ;
struct V_323 * V_324 , * V_765 ;
struct V_55 * V_56 , * V_371 ;
struct V_72 * V_118 ;
struct V_766 * V_767 ;
unsigned long V_76 ;
V_14 -> V_269 = 1 ;
F_148 ( V_14 ) ;
F_32 ( & V_14 -> V_309 , V_76 ) ;
V_767 = V_14 -> V_308 ;
V_14 -> V_308 = NULL ;
F_33 ( & V_14 -> V_309 , V_76 ) ;
if ( V_767 )
F_295 ( V_767 ) ;
F_292 ( V_14 ) ;
F_281 (raid_device, next, &ioc->raid_device_list,
list) {
if ( V_56 -> V_85 ) {
V_118 =
V_56 -> V_85 -> V_120 ;
V_118 -> V_342 = 1 ;
F_259 ( & V_56 -> V_85 -> V_127 ) ;
}
F_13 ( V_42 L_259 ,
V_14 -> V_43 , V_56 -> V_35 ,
( unsigned long long ) V_56 -> V_60 ) ;
F_55 ( V_14 , V_56 ) ;
}
F_281 (mpt3sas_port, next_port,
&ioc->sas_hba.sas_port_list, port_list) {
if ( V_324 -> V_326 . V_327 ==
V_328 )
F_44 ( V_14 ,
V_324 -> V_326 . V_17 ) ;
else if ( V_324 -> V_326 . V_327 ==
V_330 ||
V_324 -> V_326 . V_327 ==
V_331 )
F_238 ( V_14 ,
V_324 -> V_326 . V_17 ) ;
}
if ( V_14 -> V_39 . V_40 ) {
F_2 ( V_14 -> V_39 . V_225 ) ;
V_14 -> V_39 . V_225 = NULL ;
V_14 -> V_39 . V_40 = 0 ;
}
F_296 ( V_113 ) ;
F_297 ( V_113 ) ;
F_298 ( V_14 ) ;
F_14 ( & V_16 ) ;
F_56 ( & V_14 -> V_81 ) ;
F_16 ( & V_16 ) ;
F_299 ( V_113 ) ;
}
void
F_300 ( struct V_764 * V_532 )
{
struct V_112 * V_113 = F_294 ( V_532 ) ;
struct V_13 * V_14 = F_67 ( V_113 ) ;
struct V_766 * V_767 ;
unsigned long V_76 ;
V_14 -> V_269 = 1 ;
F_148 ( V_14 ) ;
F_32 ( & V_14 -> V_309 , V_76 ) ;
V_767 = V_14 -> V_308 ;
V_14 -> V_308 = NULL ;
F_33 ( & V_14 -> V_309 , V_76 ) ;
if ( V_767 )
F_295 ( V_767 ) ;
F_292 ( V_14 ) ;
F_298 ( V_14 ) ;
}
static void
F_301 ( struct V_13 * V_14 )
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
V_28 = F_257 ( V_14 -> V_113 , V_133 ,
V_56 -> V_87 , 0 ) ;
if ( V_28 )
F_55 ( V_14 , V_56 ) ;
} else {
F_32 ( & V_14 -> V_74 , V_76 ) ;
V_54 = V_51 ;
V_35 = V_54 -> V_35 ;
V_84 = V_54 -> V_84 ;
V_17 = V_54 -> V_17 ;
F_282 ( & V_54 -> V_81 , & V_14 -> V_83 ) ;
F_33 ( & V_14 -> V_74 , V_76 ) ;
if ( V_14 -> V_628 )
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
F_302 ( struct V_13 * V_14 )
{
struct V_55 * V_56 , * V_768 ;
int V_28 ;
F_281 (raid_device, raid_next,
&ioc->raid_device_list, list) {
if ( V_56 -> V_85 )
continue;
V_28 = F_257 ( V_14 -> V_113 , V_133 ,
V_56 -> V_87 , 0 ) ;
if ( V_28 )
F_55 ( V_14 , V_56 ) ;
}
}
static struct V_53 * F_303 ( struct V_13 * V_14 )
{
struct V_53 * V_54 = NULL ;
unsigned long V_76 ;
F_32 ( & V_14 -> V_74 , V_76 ) ;
if ( ! F_39 ( & V_14 -> V_86 ) ) {
V_54 = F_147 ( & V_14 -> V_86 ,
struct V_53 , V_81 ) ;
F_30 ( V_54 ) ;
}
F_33 ( & V_14 -> V_74 , V_76 ) ;
return V_54 ;
}
static void F_304 ( struct V_13 * V_14 ,
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
F_305 ( struct V_13 * V_14 )
{
struct V_53 * V_54 ;
if ( V_14 -> V_628 )
return;
while ( ( V_54 = F_303 ( V_14 ) ) ) {
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
F_304 ( V_14 , V_54 ) ;
F_41 ( V_54 ) ;
}
}
static void
F_306 ( struct V_13 * V_14 )
{
T_4 V_769 ;
if ( ! ( V_14 -> V_202 . V_770 & V_771 ) )
return;
F_301 ( V_14 ) ;
if ( V_14 -> V_715 ) {
V_769 =
F_21 ( V_14 -> V_772 . V_773 ) &
V_774 ;
if ( V_769 ==
V_775 ) {
F_302 ( V_14 ) ;
F_305 ( V_14 ) ;
} else {
F_305 ( V_14 ) ;
F_302 ( V_14 ) ;
}
} else
F_305 ( V_14 ) ;
}
void
F_307 ( struct V_112 * V_113 )
{
struct V_13 * V_14 = F_67 ( V_113 ) ;
int V_28 ;
if ( V_776 != - 1 && V_776 != 0 )
F_308 ( V_14 , V_776 ) ;
if ( V_670 > 0 )
return;
V_14 -> V_734 = 1 ;
V_28 = F_309 ( V_14 ) ;
if ( V_28 != 0 )
F_13 ( V_42 L_354 , V_14 -> V_43 ) ;
}
int
F_310 ( struct V_112 * V_113 , unsigned long time )
{
struct V_13 * V_14 = F_67 ( V_113 ) ;
if ( V_670 > 0 ) {
V_14 -> V_57 = 0 ;
V_14 -> V_627 = 0 ;
return 1 ;
}
if ( time >= ( 300 * V_288 ) ) {
V_14 -> V_777 . V_246 = V_247 ;
F_13 ( V_42
L_355 ,
V_14 -> V_43 ) ;
V_14 -> V_57 = 0 ;
return 1 ;
}
if ( V_14 -> V_734 )
return 0 ;
if ( V_14 -> V_778 ) {
F_13 ( V_42
L_356 ,
V_14 -> V_43 , V_14 -> V_778 ) ;
V_14 -> V_57 = 0 ;
V_14 -> V_627 = 0 ;
V_14 -> V_269 = 1 ;
return 1 ;
}
F_13 ( V_42 L_357 , V_14 -> V_43 ) ;
V_14 -> V_777 . V_246 = V_247 ;
if ( V_14 -> V_627 ) {
V_14 -> V_627 = 0 ;
F_306 ( V_14 ) ;
}
F_311 ( V_14 ) ;
V_14 -> V_57 = 0 ;
return 1 ;
}
T_4
F_312 ( struct V_764 * V_532 )
{
switch ( V_532 -> V_51 ) {
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
case V_791 :
case V_792 :
case V_793 :
case V_794 :
case V_795 :
return V_160 ;
case V_796 :
case V_797 :
case V_798 :
case V_799 :
case V_800 :
case V_801 :
return V_162 ;
case V_802 :
case V_803 :
case V_804 :
case V_805 :
case V_806 :
case V_807 :
case V_808 :
case V_809 :
case V_810 :
case V_811 :
return V_163 ;
}
return 0 ;
}
int
F_313 ( struct V_764 * V_532 , const struct V_812 * V_87 )
{
struct V_13 * V_14 ;
struct V_112 * V_113 = NULL ;
int V_813 ;
T_4 V_814 ;
V_814 = F_312 ( V_532 ) ;
if ( V_814 == 0 )
return - V_815 ;
if ( ( V_816 == 1 ) && ( V_814 != V_160 ) )
return - V_815 ;
if ( ( V_816 == 2 ) && ( ! ( V_814 == V_162
|| V_814 == V_163 ) ) )
return - V_815 ;
switch ( V_814 ) {
case V_160 :
V_113 = F_314 ( & V_817 ,
sizeof( struct V_13 ) ) ;
if ( ! V_113 )
return - V_815 ;
V_14 = F_67 ( V_113 ) ;
memset ( V_14 , 0 , sizeof( struct V_13 ) ) ;
V_14 -> V_159 = V_814 ;
V_14 -> V_87 = V_818 ++ ;
sprintf ( V_14 -> V_819 , L_358 , V_820 ) ;
if ( V_532 -> V_51 == V_779 ) {
V_14 -> V_134 = 1 ;
V_14 -> V_218 = 1 ;
} else
V_14 -> V_821 = V_822 ;
break;
case V_162 :
case V_163 :
V_113 = F_314 ( & V_823 ,
sizeof( struct V_13 ) ) ;
if ( ! V_113 )
return - V_815 ;
V_14 = F_67 ( V_113 ) ;
memset ( V_14 , 0 , sizeof( struct V_13 ) ) ;
V_14 -> V_159 = V_814 ;
V_14 -> V_87 = V_824 ++ ;
sprintf ( V_14 -> V_819 , L_358 , V_825 ) ;
if ( ( V_14 -> V_159 == V_162 &&
V_532 -> V_826 >= V_827 ) ||
( V_14 -> V_159 == V_163 ) )
V_14 -> V_828 = 1 ;
break;
default:
return - V_815 ;
}
F_139 ( & V_14 -> V_81 ) ;
F_14 ( & V_16 ) ;
F_47 ( & V_14 -> V_81 , & V_829 ) ;
F_16 ( & V_16 ) ;
V_14 -> V_113 = V_113 ;
V_14 -> V_532 = V_532 ;
V_14 -> V_448 = V_448 ;
V_14 -> V_278 = V_278 ;
V_14 -> V_830 = V_830 ;
V_14 -> V_362 = V_362 ;
V_14 -> V_831 = V_831 ;
V_14 -> V_832 = V_832 ;
V_14 -> V_674 = V_674 ;
V_14 -> V_833 = V_833 ;
V_14 -> V_343 = V_343 ;
V_14 -> V_355 = V_355 ;
V_14 -> V_350 = V_350 ;
V_14 -> V_15 = V_15 ;
V_14 -> V_834 = & F_187 ;
F_315 ( & V_14 -> V_835 ) ;
F_315 ( & V_14 -> V_836 ) ;
F_316 ( & V_14 -> V_837 ) ;
F_316 ( & V_14 -> V_105 ) ;
F_316 ( & V_14 -> V_74 ) ;
F_316 ( & V_14 -> V_94 ) ;
F_316 ( & V_14 -> V_309 ) ;
F_316 ( & V_14 -> V_90 ) ;
F_316 ( & V_14 -> V_838 ) ;
F_139 ( & V_14 -> V_83 ) ;
F_139 ( & V_14 -> V_86 ) ;
F_139 ( & V_14 -> V_95 ) ;
F_139 ( & V_14 -> V_310 ) ;
F_139 ( & V_14 -> V_91 ) ;
F_139 ( & V_14 -> V_39 . V_594 ) ;
F_139 ( & V_14 -> V_344 ) ;
F_139 ( & V_14 -> V_351 ) ;
F_139 ( & V_14 -> V_370 ) ;
F_139 ( & V_14 -> V_356 ) ;
F_139 ( & V_14 -> V_839 ) ;
sprintf ( V_14 -> V_43 , L_359 , V_14 -> V_819 , V_14 -> V_87 ) ;
V_113 -> V_840 = 32 ;
V_113 -> V_841 = V_841 ;
V_113 -> V_842 = V_843 ;
V_113 -> V_844 = V_14 -> V_87 ;
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
if ( V_845 > 0 )
F_317 ( V_113 , V_845 ) ;
else
F_317 ( V_113 , V_846
| V_847
| V_848 ) ;
F_318 ( V_113 , V_849 ) ;
snprintf ( V_14 -> V_850 , sizeof( V_14 -> V_850 ) ,
L_365 , V_14 -> V_819 , V_14 -> V_87 ) ;
V_14 -> V_308 = F_319 (
V_14 -> V_850 , V_851 ) ;
if ( ! V_14 -> V_308 ) {
F_25 ( V_42 L_2 ,
V_14 -> V_43 , __FILE__ , __LINE__ , V_44 ) ;
V_813 = - V_815 ;
goto V_852;
}
V_14 -> V_57 = 1 ;
if ( ( F_320 ( V_14 ) ) ) {
F_25 ( V_42 L_2 ,
V_14 -> V_43 , __FILE__ , __LINE__ , V_44 ) ;
V_813 = - V_815 ;
goto V_853;
}
if ( V_14 -> V_134 ) {
if ( V_14 -> V_821 == V_822 )
V_14 -> V_628 = 0 ;
else if ( V_14 -> V_821 == V_854 )
V_14 -> V_628 = 1 ;
else {
if ( F_321 ( V_14 ) )
V_14 -> V_628 = 1 ;
else
V_14 -> V_628 = 0 ;
}
} else
V_14 -> V_628 = 0 ;
V_813 = F_322 ( V_113 , & V_532 -> V_127 ) ;
if ( V_813 ) {
F_25 ( V_42 L_2 ,
V_14 -> V_43 , __FILE__ , __LINE__ , V_44 ) ;
goto V_855;
}
F_323 ( V_113 ) ;
return 0 ;
V_855:
F_298 ( V_14 ) ;
V_853:
F_295 ( V_14 -> V_308 ) ;
V_852:
F_14 ( & V_16 ) ;
F_56 ( & V_14 -> V_81 ) ;
F_16 ( & V_16 ) ;
F_299 ( V_113 ) ;
return V_813 ;
}
int
F_324 ( struct V_764 * V_532 , T_51 V_167 )
{
struct V_112 * V_113 = F_294 ( V_532 ) ;
struct V_13 * V_14 = F_67 ( V_113 ) ;
T_52 V_856 ;
F_325 ( V_14 ) ;
F_326 () ;
F_327 ( V_113 ) ;
V_856 = F_328 ( V_532 , V_167 ) ;
F_13 ( V_42
L_366 ,
V_14 -> V_43 , V_532 , F_329 ( V_532 ) , V_856 ) ;
F_330 ( V_532 ) ;
F_331 ( V_14 ) ;
F_332 ( V_532 , V_856 ) ;
return 0 ;
}
int
F_333 ( struct V_764 * V_532 )
{
struct V_112 * V_113 = F_294 ( V_532 ) ;
struct V_13 * V_14 = F_67 ( V_113 ) ;
T_52 V_856 = V_532 -> V_857 ;
int V_2 ;
F_13 ( V_42
L_367 ,
V_14 -> V_43 , V_532 , F_329 ( V_532 ) , V_856 ) ;
F_332 ( V_532 , V_858 ) ;
F_334 ( V_532 , V_858 , 0 ) ;
F_335 ( V_532 ) ;
V_14 -> V_532 = V_532 ;
V_2 = F_336 ( V_14 ) ;
if ( V_2 )
return V_2 ;
F_116 ( V_14 , V_272 , V_859 ) ;
F_337 ( V_113 ) ;
F_311 ( V_14 ) ;
return 0 ;
}
T_53
F_338 ( struct V_764 * V_532 , T_54 V_167 )
{
struct V_112 * V_113 = F_294 ( V_532 ) ;
struct V_13 * V_14 = F_67 ( V_113 ) ;
F_13 ( V_42 L_368 ,
V_14 -> V_43 , V_167 ) ;
switch ( V_167 ) {
case V_860 :
return V_861 ;
case V_862 :
V_14 -> V_270 = 1 ;
F_327 ( V_14 -> V_113 ) ;
F_325 ( V_14 ) ;
F_331 ( V_14 ) ;
return V_863 ;
case V_864 :
V_14 -> V_270 = 1 ;
F_325 ( V_14 ) ;
F_187 ( V_14 ) ;
return V_865 ;
}
return V_863 ;
}
T_53
F_339 ( struct V_764 * V_532 )
{
struct V_112 * V_113 = F_294 ( V_532 ) ;
struct V_13 * V_14 = F_67 ( V_113 ) ;
int V_28 ;
F_13 ( V_42 L_369 ,
V_14 -> V_43 ) ;
V_14 -> V_270 = 0 ;
V_14 -> V_532 = V_532 ;
F_335 ( V_532 ) ;
V_28 = F_336 ( V_14 ) ;
if ( V_28 )
return V_865 ;
V_28 = F_116 ( V_14 , V_272 ,
V_273 ) ;
F_91 ( V_42 L_370 , V_14 -> V_43 ,
( V_28 == 0 ) ? L_124 : L_371 ) ;
if ( ! V_28 )
return V_866 ;
else
return V_865 ;
}
void
F_340 ( struct V_764 * V_532 )
{
struct V_112 * V_113 = F_294 ( V_532 ) ;
struct V_13 * V_14 = F_67 ( V_113 ) ;
F_13 ( V_42 L_372 , V_14 -> V_43 ) ;
F_341 ( V_532 ) ;
F_311 ( V_14 ) ;
F_337 ( V_14 -> V_113 ) ;
}
T_53
F_342 ( struct V_764 * V_532 )
{
struct V_112 * V_113 = F_294 ( V_532 ) ;
struct V_13 * V_14 = F_67 ( V_113 ) ;
F_13 ( V_42 L_373 ,
V_14 -> V_43 ) ;
return V_866 ;
}
int
F_343 ( void )
{
V_818 = 0 ;
V_824 = 0 ;
F_344 () ;
V_448 = F_345 ( F_215 ) ;
V_278 = F_345 ( F_106 ) ;
V_362 = F_345 ( V_867 ) ;
V_831 = F_345 (
V_868 ) ;
V_832 = F_345 (
V_869 ) ;
V_674 = F_345 ( F_240 ) ;
V_833 = F_345 (
V_870 ) ;
V_830 = F_345 ( V_871 ) ;
V_343 = F_345 (
F_163 ) ;
V_355 = F_345 (
F_172 ) ;
V_350 = F_345 (
F_168 ) ;
return 0 ;
}
void
F_346 ( void )
{
F_347 ( V_448 ) ;
F_347 ( V_278 ) ;
F_347 ( V_362 ) ;
F_347 ( V_831 ) ;
F_347 ( V_832 ) ;
F_347 ( V_674 ) ;
F_347 ( V_833 ) ;
F_347 ( V_830 ) ;
F_347 ( V_343 ) ;
F_347 ( V_355 ) ;
F_347 ( V_350 ) ;
if ( V_816 != 1 )
F_348 ( V_164 ) ;
if ( V_816 != 2 )
F_348 ( V_161 ) ;
F_349 ( V_843 ) ;
}
static int T_55
F_350 ( void )
{
int error ;
F_13 ( L_374 , V_825 ,
V_872 ) ;
V_843 =
F_351 ( & V_873 ) ;
if ( ! V_843 )
return - V_815 ;
if ( V_816 != 1 ) {
V_164 =
F_352 ( & V_874 ) ;
if ( ! V_164 ) {
F_349 ( V_843 ) ;
return - V_815 ;
}
}
if ( V_816 != 2 ) {
V_161 =
F_352 ( & V_875 ) ;
if ( ! V_161 ) {
F_349 ( V_843 ) ;
return - V_815 ;
}
}
error = F_343 () ;
if ( error ) {
F_346 () ;
return error ;
}
F_353 ( V_816 ) ;
error = F_354 ( & V_876 ) ;
if ( error )
F_346 () ;
return error ;
}
static void T_56
F_355 ( void )
{
F_13 ( L_375 ,
V_872 ) ;
F_356 ( & V_876 ) ;
F_357 ( V_816 ) ;
F_346 () ;
}
