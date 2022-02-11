static int
F_1 ( const char * V_1 , struct V_2 * V_3 )
{
int V_4 = F_2 ( V_1 , V_3 ) ;
struct V_5 * V_6 ;
if ( V_4 )
return V_4 ;
F_3 ( L_1 , V_7 ) ;
F_4 (ioc, &mpt3sas_ioc_list, list)
V_6 -> V_7 = V_7 ;
return 0 ;
}
static inline int
F_5 ( T_1 V_8 ,
T_2 * V_9 )
{
return ( V_8 == F_6 ( V_9 -> V_10 ) ) ? 1 : 0 ;
}
static inline int
F_7 ( T_1 V_11 ,
T_3 * V_9 )
{
return ( V_11 == F_6 ( V_9 -> V_12 ) ) ? 1 : 0 ;
}
static inline int
F_8 ( T_1 V_13 , T_4 V_14 ,
T_5 * V_9 )
{
return ( V_13 == F_6 ( V_9 ->
V_15 ) && V_14 == F_9 ( V_9 ->
V_16 ) ) ? 1 : 0 ;
}
static int
F_10 ( T_1 V_8 , T_1 V_11 ,
T_1 V_13 , T_4 V_17 , T_6 V_18 ,
T_7 * V_9 )
{
int V_19 = 0 ;
switch ( V_18 ) {
case V_20 :
if ( ! V_8 )
break;
V_19 = F_5 (
V_8 , & V_9 -> V_21 ) ;
break;
case V_22 :
if ( ! V_13 )
break;
V_19 = F_8 (
V_13 ,
V_17 , & V_9 -> V_23 ) ;
break;
case V_24 :
if ( ! V_11 )
break;
V_19 = F_7 (
V_11 , & V_9 -> V_12 ) ;
break;
case V_25 :
break;
}
return V_19 ;
}
static int
F_11 ( struct V_5 * V_6 , T_4 V_26 ,
T_1 * V_8 )
{
T_8 V_27 ;
T_9 V_28 ;
T_10 V_29 ;
* V_8 = 0 ;
if ( V_26 <= V_6 -> V_30 . V_31 ) {
* V_8 = V_6 -> V_30 . V_8 ;
return 0 ;
}
if ( ( F_12 ( V_6 , & V_28 , & V_27 ,
V_32 , V_26 ) ) ) {
F_13 ( V_33 L_2 , V_6 -> V_34 ,
__FILE__ , __LINE__ , V_35 ) ;
return - V_36 ;
}
V_29 = F_9 ( V_28 . V_37 ) & V_38 ;
if ( V_29 == V_39 ) {
* V_8 = F_6 ( V_27 . V_10 ) ;
return 0 ;
}
if ( V_29 == V_40 )
return - V_36 ;
F_13 ( V_33
L_3 ,
V_6 -> V_34 , V_26 , V_29 ,
__FILE__ , __LINE__ , V_35 ) ;
return - V_41 ;
}
static void
F_14 ( struct V_5 * V_6 ,
void * V_42 , T_6 V_43 )
{
struct V_44 * V_45 ;
struct V_46 * V_47 ;
T_1 V_8 ;
T_1 V_11 ;
T_1 V_13 ;
T_4 V_17 ;
if ( ! V_6 -> V_48 )
return;
if ( ! V_6 -> V_49 . V_50 )
return;
if ( ! V_43 ) {
V_45 = V_42 ;
V_8 = V_45 -> V_8 ;
V_11 = V_45 -> V_11 ;
V_13 = V_45 -> V_13 ;
V_17 = V_45 -> V_17 ;
} else {
V_47 = V_42 ;
V_8 = V_47 -> V_51 ;
V_11 = 0 ;
V_13 = 0 ;
V_17 = 0 ;
}
if ( ! V_6 -> V_52 . V_42 ) {
if ( F_10 ( V_8 , V_11 ,
V_13 , V_17 ,
( V_6 -> V_53 . V_54 &
V_55 ) ,
& V_6 -> V_53 . V_56 ) ) {
F_15 ( V_6 , F_3 ( V_33
L_4 ,
V_6 -> V_34 , V_35 ,
( unsigned long long ) V_8 ) ) ;
V_6 -> V_52 . V_42 = V_42 ;
V_6 -> V_52 . V_43 = V_43 ;
}
}
if ( ! V_6 -> V_57 . V_42 ) {
if ( F_10 ( V_8 , V_11 ,
V_13 , V_17 ,
( V_6 -> V_53 . V_58 &
V_55 ) ,
& V_6 -> V_53 . V_59 ) ) {
F_15 ( V_6 , F_3 ( V_33
L_5 ,
V_6 -> V_34 , V_35 ,
( unsigned long long ) V_8 ) ) ;
V_6 -> V_57 . V_42 = V_42 ;
V_6 -> V_57 . V_43 = V_43 ;
}
}
if ( ! V_6 -> V_60 . V_42 ) {
if ( F_10 ( V_8 , V_11 ,
V_13 , V_17 ,
( V_6 -> V_53 . V_61 &
V_55 ) ,
& V_6 -> V_53 . V_62 ) ) {
F_15 ( V_6 , F_3 ( V_33
L_6 ,
V_6 -> V_34 , V_35 ,
( unsigned long long ) V_8 ) ) ;
V_6 -> V_60 . V_42 = V_42 ;
V_6 -> V_60 . V_43 = V_43 ;
}
}
}
struct V_44 *
F_16 ( struct V_5 * V_6 ,
T_1 V_8 )
{
struct V_44 * V_45 ;
F_4 (sas_device, &ioc->sas_device_list, list)
if ( V_45 -> V_8 == V_8 )
return V_45 ;
F_4 (sas_device, &ioc->sas_device_init_list, list)
if ( V_45 -> V_8 == V_8 )
return V_45 ;
return NULL ;
}
static struct V_44 *
F_17 ( struct V_5 * V_6 , T_4 V_26 )
{
struct V_44 * V_45 ;
F_4 (sas_device, &ioc->sas_device_list, list)
if ( V_45 -> V_26 == V_26 )
return V_45 ;
F_4 (sas_device, &ioc->sas_device_init_list, list)
if ( V_45 -> V_26 == V_26 )
return V_45 ;
return NULL ;
}
static void
F_18 ( struct V_5 * V_6 ,
struct V_44 * V_45 )
{
unsigned long V_63 ;
if ( ! V_45 )
return;
F_3 ( V_33
L_7 ,
V_6 -> V_34 , V_45 -> V_26 ,
( unsigned long long ) V_45 -> V_8 ) ;
if ( V_45 -> V_64 != 0 )
F_3 ( V_33
L_8 ,
V_6 -> V_34 , ( unsigned long long )
V_45 -> V_13 , V_45 -> V_17 ) ;
if ( V_45 -> V_65 [ 0 ] != '\0' )
F_3 ( V_33
L_9 ,
V_6 -> V_34 , V_45 -> V_66 ,
V_45 -> V_65 ) ;
F_19 ( & V_6 -> V_67 , V_63 ) ;
F_20 ( & V_45 -> V_68 ) ;
F_21 ( V_45 ) ;
F_22 ( & V_6 -> V_67 , V_63 ) ;
}
static void
F_23 ( struct V_5 * V_6 , T_4 V_26 )
{
struct V_44 * V_45 ;
unsigned long V_63 ;
if ( V_6 -> V_69 )
return;
F_19 ( & V_6 -> V_67 , V_63 ) ;
V_45 = F_17 ( V_6 , V_26 ) ;
if ( V_45 )
F_20 ( & V_45 -> V_68 ) ;
F_22 ( & V_6 -> V_67 , V_63 ) ;
if ( V_45 )
F_24 ( V_6 , V_45 ) ;
}
void
F_25 ( struct V_5 * V_6 ,
T_1 V_8 )
{
struct V_44 * V_45 ;
unsigned long V_63 ;
if ( V_6 -> V_69 )
return;
F_19 ( & V_6 -> V_67 , V_63 ) ;
V_45 = F_16 ( V_6 ,
V_8 ) ;
if ( V_45 )
F_20 ( & V_45 -> V_68 ) ;
F_22 ( & V_6 -> V_67 , V_63 ) ;
if ( V_45 )
F_24 ( V_6 , V_45 ) ;
}
static void
F_26 ( struct V_5 * V_6 ,
struct V_44 * V_45 )
{
unsigned long V_63 ;
F_27 ( V_6 , F_3 ( V_33
L_10 ,
V_6 -> V_34 , V_35 , V_45 -> V_26 ,
( unsigned long long ) V_45 -> V_8 ) ) ;
if ( V_45 -> V_64 != 0 )
F_27 ( V_6 , F_3 ( V_33
L_11 ,
V_6 -> V_34 , V_35 , ( unsigned long long )
V_45 -> V_13 , V_45 -> V_17 ) ) ;
if ( V_45 -> V_65 [ 0 ] != '\0' )
F_27 ( V_6 , F_3 ( V_33
L_12 ,
V_6 -> V_34 , V_35 ,
V_45 -> V_66 , V_45 -> V_65 ) ) ;
F_19 ( & V_6 -> V_67 , V_63 ) ;
F_28 ( & V_45 -> V_68 , & V_6 -> V_70 ) ;
F_22 ( & V_6 -> V_67 , V_63 ) ;
if ( ! F_29 ( V_6 , V_45 -> V_26 ,
V_45 -> V_71 ) ) {
F_18 ( V_6 , V_45 ) ;
} else if ( ! V_45 -> V_72 ) {
if ( ! V_6 -> V_48 ) {
F_30 ( V_6 ,
V_45 -> V_8 ,
V_45 -> V_71 ) ;
F_18 ( V_6 , V_45 ) ;
}
}
}
static void
F_31 ( struct V_5 * V_6 ,
struct V_44 * V_45 )
{
unsigned long V_63 ;
F_27 ( V_6 , F_3 ( V_33
L_10 , V_6 -> V_34 ,
V_35 , V_45 -> V_26 ,
( unsigned long long ) V_45 -> V_8 ) ) ;
if ( V_45 -> V_64 != 0 )
F_27 ( V_6 , F_3 ( V_33
L_11 ,
V_6 -> V_34 , V_35 , ( unsigned long long )
V_45 -> V_13 , V_45 -> V_17 ) ) ;
if ( V_45 -> V_65 [ 0 ] != '\0' )
F_27 ( V_6 , F_3 ( V_33
L_12 ,
V_6 -> V_34 , V_35 , V_45 -> V_66 ,
V_45 -> V_65 ) ) ;
F_19 ( & V_6 -> V_67 , V_63 ) ;
F_28 ( & V_45 -> V_68 , & V_6 -> V_73 ) ;
F_14 ( V_6 , V_45 , 0 ) ;
F_22 ( & V_6 -> V_67 , V_63 ) ;
}
static struct V_46 *
F_32 ( struct V_5 * V_6 , int V_74 , int V_75 )
{
struct V_46 * V_47 , * V_76 ;
V_76 = NULL ;
F_4 (raid_device, &ioc->raid_device_list, list) {
if ( V_47 -> V_74 == V_74 && V_47 -> V_75 == V_75 ) {
V_76 = V_47 ;
goto V_77;
}
}
V_77:
return V_76 ;
}
static struct V_46 *
F_33 ( struct V_5 * V_6 , T_4 V_26 )
{
struct V_46 * V_47 , * V_76 ;
V_76 = NULL ;
F_4 (raid_device, &ioc->raid_device_list, list) {
if ( V_47 -> V_26 != V_26 )
continue;
V_76 = V_47 ;
goto V_77;
}
V_77:
return V_76 ;
}
static struct V_46 *
F_34 ( struct V_5 * V_6 , T_1 V_51 )
{
struct V_46 * V_47 , * V_76 ;
V_76 = NULL ;
F_4 (raid_device, &ioc->raid_device_list, list) {
if ( V_47 -> V_51 != V_51 )
continue;
V_76 = V_47 ;
goto V_77;
}
V_77:
return V_76 ;
}
static void
F_35 ( struct V_5 * V_6 ,
struct V_46 * V_47 )
{
unsigned long V_63 ;
F_27 ( V_6 , F_3 ( V_33
L_13 , V_6 -> V_34 , V_35 ,
V_47 -> V_26 , ( unsigned long long ) V_47 -> V_51 ) ) ;
F_19 ( & V_6 -> V_78 , V_63 ) ;
F_28 ( & V_47 -> V_68 , & V_6 -> V_79 ) ;
F_22 ( & V_6 -> V_78 , V_63 ) ;
}
static void
F_36 ( struct V_5 * V_6 ,
struct V_46 * V_47 )
{
unsigned long V_63 ;
F_19 ( & V_6 -> V_78 , V_63 ) ;
F_20 ( & V_47 -> V_68 ) ;
F_21 ( V_47 ) ;
F_22 ( & V_6 -> V_78 , V_63 ) ;
}
struct V_80 *
F_37 ( struct V_5 * V_6 , T_4 V_26 )
{
struct V_80 * V_81 , * V_76 ;
V_76 = NULL ;
F_4 (sas_expander, &ioc->sas_expander_list, list) {
if ( V_81 -> V_26 != V_26 )
continue;
V_76 = V_81 ;
goto V_77;
}
V_77:
return V_76 ;
}
struct V_80 *
F_38 ( struct V_5 * V_6 ,
T_1 V_8 )
{
struct V_80 * V_81 , * V_76 ;
V_76 = NULL ;
F_4 (sas_expander, &ioc->sas_expander_list, list) {
if ( V_81 -> V_8 != V_8 )
continue;
V_76 = V_81 ;
goto V_77;
}
V_77:
return V_76 ;
}
static void
F_39 ( struct V_5 * V_6 ,
struct V_80 * V_81 )
{
unsigned long V_63 ;
F_19 ( & V_6 -> V_82 , V_63 ) ;
F_28 ( & V_81 -> V_68 , & V_6 -> V_83 ) ;
F_22 ( & V_6 -> V_82 , V_63 ) ;
}
static int
F_40 ( T_10 V_84 )
{
if ( V_84 & V_85 &&
( ( V_84 & V_86 ) |
( V_84 & V_87 ) |
( V_84 & V_88 ) ) )
return 1 ;
else
return 0 ;
}
static struct V_89 *
F_41 ( struct V_5 * V_6 , T_4 V_90 )
{
return V_6 -> V_91 [ V_90 - 1 ] . V_92 ;
}
static inline struct V_89 *
F_42 ( struct V_5 * V_6 , T_4 V_90 )
{
unsigned long V_63 ;
struct V_89 * V_92 ;
F_19 ( & V_6 -> V_93 , V_63 ) ;
V_92 = V_6 -> V_91 [ V_90 - 1 ] . V_92 ;
V_6 -> V_91 [ V_90 - 1 ] . V_92 = NULL ;
F_22 ( & V_6 -> V_93 , V_63 ) ;
return V_92 ;
}
static T_4
F_43 ( struct V_5 * V_6 , struct V_89
* V_92 )
{
T_4 V_90 ;
unsigned long V_63 ;
int V_94 ;
F_19 ( & V_6 -> V_93 , V_63 ) ;
V_90 = 0 ;
for ( V_94 = 0 ; V_94 < V_6 -> V_95 ; V_94 ++ ) {
if ( V_6 -> V_91 [ V_94 ] . V_92 == V_92 ) {
V_90 = V_6 -> V_91 [ V_94 ] . V_90 ;
goto V_77;
}
}
V_77:
F_22 ( & V_6 -> V_93 , V_63 ) ;
return V_90 ;
}
static T_6
F_44 ( struct V_5 * V_6 , int V_74 ,
int V_75 )
{
T_6 V_96 ;
unsigned long V_63 ;
int V_94 ;
F_19 ( & V_6 -> V_93 , V_63 ) ;
V_96 = 0 ;
for ( V_94 = 0 ; V_94 < V_6 -> V_95 ; V_94 ++ ) {
if ( V_6 -> V_91 [ V_94 ] . V_92 &&
( V_6 -> V_91 [ V_94 ] . V_92 -> V_42 -> V_74 == V_74 &&
V_6 -> V_91 [ V_94 ] . V_92 -> V_42 -> V_75 == V_75 ) ) {
V_96 = 1 ;
goto V_77;
}
}
V_77:
F_22 ( & V_6 -> V_93 , V_63 ) ;
return V_96 ;
}
static T_6
F_45 ( struct V_5 * V_6 , int V_74 ,
unsigned int V_97 , int V_75 )
{
T_6 V_96 ;
unsigned long V_63 ;
int V_94 ;
F_19 ( & V_6 -> V_93 , V_63 ) ;
V_96 = 0 ;
for ( V_94 = 0 ; V_94 < V_6 -> V_95 ; V_94 ++ ) {
if ( V_6 -> V_91 [ V_94 ] . V_92 &&
( V_6 -> V_91 [ V_94 ] . V_92 -> V_42 -> V_74 == V_74 &&
V_6 -> V_91 [ V_94 ] . V_92 -> V_42 -> V_75 == V_75 &&
V_6 -> V_91 [ V_94 ] . V_92 -> V_42 -> V_97 == V_97 ) ) {
V_96 = 1 ;
goto V_77;
}
}
V_77:
F_22 ( & V_6 -> V_93 , V_63 ) ;
return V_96 ;
}
static int
F_46 ( struct V_98 * V_99 , int V_100 )
{
struct V_101 * V_102 = V_99 -> V_103 ;
int V_104 ;
struct V_5 * V_6 = F_47 ( V_102 ) ;
struct V_105 * V_106 ;
struct V_107 * V_108 ;
struct V_44 * V_45 ;
unsigned long V_63 ;
V_104 = V_102 -> V_109 ;
V_106 = V_99 -> V_110 ;
if ( ! V_106 )
goto V_111;
V_108 = V_106 -> V_112 ;
if ( ! V_108 )
goto V_111;
if ( ( V_108 -> V_63 & V_113 ) )
goto V_111;
F_19 ( & V_6 -> V_67 , V_63 ) ;
V_45 = F_16 ( V_6 ,
V_106 -> V_112 -> V_8 ) ;
if ( V_45 && V_45 -> V_84 &
V_88 )
V_104 = V_114 ;
F_22 ( & V_6 -> V_67 , V_63 ) ;
V_111:
if ( ! V_99 -> V_115 )
V_104 = 1 ;
if ( V_100 > V_104 )
V_100 = V_104 ;
return F_48 ( V_99 , V_100 ) ;
}
static int
F_49 ( struct V_116 * V_72 )
{
struct V_101 * V_102 = F_50 ( & V_72 -> V_117 ) ;
struct V_5 * V_6 = F_47 ( V_102 ) ;
struct V_107 * V_108 ;
struct V_44 * V_45 ;
struct V_46 * V_47 ;
unsigned long V_63 ;
struct V_118 * V_119 ;
V_108 = F_51 ( sizeof( * V_108 ) ,
V_120 ) ;
if ( ! V_108 )
return - V_121 ;
V_72 -> V_110 = V_108 ;
V_108 -> V_72 = V_72 ;
V_108 -> V_26 = V_122 ;
if ( V_72 -> V_75 == V_123 ) {
F_19 ( & V_6 -> V_78 , V_63 ) ;
V_47 = F_32 ( V_6 , V_72 -> V_74 ,
V_72 -> V_75 ) ;
if ( V_47 ) {
V_108 -> V_26 = V_47 -> V_26 ;
V_108 -> V_8 = V_47 -> V_51 ;
V_108 -> V_63 |= V_113 ;
V_47 -> V_72 = V_72 ;
}
F_22 ( & V_6 -> V_78 , V_63 ) ;
return 0 ;
}
F_19 ( & V_6 -> V_67 , V_63 ) ;
V_119 = F_52 ( V_72 -> V_117 . V_124 ) ;
V_45 = F_16 ( V_6 ,
V_119 -> V_125 . V_8 ) ;
if ( V_45 ) {
V_108 -> V_26 = V_45 -> V_26 ;
V_108 -> V_8 = V_45 -> V_8 ;
V_45 -> V_72 = V_72 ;
V_45 -> V_74 = V_72 -> V_74 ;
V_45 -> V_75 = V_72 -> V_75 ;
if ( F_53 ( V_45 -> V_26 , V_6 -> V_126 ) )
V_108 -> V_63 |=
V_127 ;
if ( V_45 -> V_128 )
V_108 -> V_63 |= V_129 ;
}
F_22 ( & V_6 -> V_67 , V_63 ) ;
return 0 ;
}
static void
F_54 ( struct V_116 * V_72 )
{
struct V_101 * V_102 = F_50 ( & V_72 -> V_117 ) ;
struct V_5 * V_6 = F_47 ( V_102 ) ;
struct V_107 * V_108 ;
struct V_44 * V_45 ;
struct V_46 * V_47 ;
unsigned long V_63 ;
struct V_118 * V_119 ;
V_108 = V_72 -> V_110 ;
if ( ! V_108 )
return;
if ( V_72 -> V_75 == V_123 ) {
F_19 ( & V_6 -> V_78 , V_63 ) ;
V_47 = F_32 ( V_6 , V_72 -> V_74 ,
V_72 -> V_75 ) ;
if ( V_47 ) {
V_47 -> V_72 = NULL ;
V_47 -> V_99 = NULL ;
}
F_22 ( & V_6 -> V_78 , V_63 ) ;
goto V_77;
}
F_19 ( & V_6 -> V_67 , V_63 ) ;
V_119 = F_52 ( V_72 -> V_117 . V_124 ) ;
V_45 = F_16 ( V_6 ,
V_119 -> V_125 . V_8 ) ;
if ( V_45 && ( V_45 -> V_72 == V_72 ) &&
( V_45 -> V_74 == V_72 -> V_74 ) &&
( V_45 -> V_75 == V_72 -> V_75 ) )
V_45 -> V_72 = NULL ;
F_22 ( & V_6 -> V_67 , V_63 ) ;
V_77:
F_21 ( V_108 ) ;
V_72 -> V_110 = NULL ;
}
static int
F_55 ( struct V_98 * V_99 )
{
struct V_101 * V_102 ;
struct V_5 * V_6 ;
struct V_107 * V_108 ;
struct V_105 * V_106 ;
struct V_116 * V_72 ;
struct V_46 * V_47 ;
struct V_44 * V_45 ;
unsigned long V_63 ;
V_106 = F_51 ( sizeof( * V_106 ) ,
V_120 ) ;
if ( ! V_106 )
return - V_121 ;
V_106 -> V_97 = V_99 -> V_97 ;
V_106 -> V_63 = V_130 ;
V_72 = V_116 ( V_99 ) ;
V_108 = V_72 -> V_110 ;
V_108 -> V_131 ++ ;
V_106 -> V_112 = V_108 ;
V_99 -> V_110 = V_106 ;
if ( ( V_108 -> V_63 & V_127 ) )
V_99 -> V_132 = 1 ;
V_102 = F_50 ( & V_72 -> V_117 ) ;
V_6 = F_47 ( V_102 ) ;
if ( V_72 -> V_75 == V_123 ) {
F_19 ( & V_6 -> V_78 , V_63 ) ;
V_47 = F_32 ( V_6 ,
V_72 -> V_74 , V_72 -> V_75 ) ;
if ( V_47 )
V_47 -> V_99 = V_99 ;
F_22 ( & V_6 -> V_78 , V_63 ) ;
}
if ( ! ( V_108 -> V_63 & V_113 ) ) {
F_19 ( & V_6 -> V_67 , V_63 ) ;
V_45 = F_16 ( V_6 ,
V_108 -> V_8 ) ;
if ( V_45 && ( V_45 -> V_72 == NULL ) ) {
F_56 ( V_133 , V_99 ,
L_14 ,
V_35 , __LINE__ ) ;
V_45 -> V_72 = V_72 ;
}
F_22 ( & V_6 -> V_67 , V_63 ) ;
}
return 0 ;
}
static void
F_57 ( struct V_98 * V_99 )
{
struct V_107 * V_108 ;
struct V_116 * V_72 ;
struct V_101 * V_102 ;
struct V_5 * V_6 ;
struct V_44 * V_45 ;
unsigned long V_63 ;
if ( ! V_99 -> V_110 )
return;
V_72 = V_116 ( V_99 ) ;
V_108 = V_72 -> V_110 ;
V_108 -> V_131 -- ;
V_102 = F_50 ( & V_72 -> V_117 ) ;
V_6 = F_47 ( V_102 ) ;
if ( ! ( V_108 -> V_63 & V_113 ) ) {
F_19 ( & V_6 -> V_67 , V_63 ) ;
V_45 = F_16 ( V_6 ,
V_108 -> V_8 ) ;
if ( V_45 && ! V_108 -> V_131 )
V_45 -> V_72 = NULL ;
F_22 ( & V_6 -> V_67 , V_63 ) ;
}
F_21 ( V_99 -> V_110 ) ;
V_99 -> V_110 = NULL ;
}
static void
F_58 ( struct V_5 * V_6 ,
T_4 V_26 , struct V_98 * V_99 )
{
T_9 V_28 ;
T_8 V_27 ;
T_10 V_29 ;
T_4 V_63 ;
T_10 V_84 ;
if ( ( F_12 ( V_6 , & V_28 , & V_27 ,
V_32 , V_26 ) ) ) {
F_13 ( V_33 L_2 ,
V_6 -> V_34 , __FILE__ , __LINE__ , V_35 ) ;
return;
}
V_29 = F_9 ( V_28 . V_37 ) &
V_38 ;
if ( V_29 != V_39 ) {
F_13 ( V_33 L_2 ,
V_6 -> V_34 , __FILE__ , __LINE__ , V_35 ) ;
return;
}
V_63 = F_9 ( V_27 . V_134 ) ;
V_84 = F_59 ( V_27 . V_135 ) ;
F_56 ( V_133 , V_99 ,
L_15
L_16 ,
( V_84 & V_136 ) ? L_17 : L_18 ,
( V_63 & V_137 ) ? L_17 : L_18 ,
( V_63 & V_138 ) ? L_17 :
L_18 ,
( V_63 & V_139 ) ? L_17 : L_18 ,
( V_63 & V_140 ) ? L_17 : L_18 ,
( V_63 & V_141 ) ? L_17 : L_18 ) ;
}
static int
F_60 ( struct V_42 * V_117 )
{
struct V_98 * V_99 = F_61 ( V_117 ) ;
return ( V_99 -> V_75 == V_123 ) ? 1 : 0 ;
}
static void
F_62 ( struct V_42 * V_117 )
{
struct V_98 * V_99 = F_61 ( V_117 ) ;
struct V_5 * V_6 = F_47 ( V_99 -> V_103 ) ;
static struct V_46 * V_47 ;
unsigned long V_63 ;
T_11 V_142 ;
T_9 V_28 ;
T_10 V_143 ;
T_6 V_144 ;
T_4 V_26 ;
V_144 = 0 ;
V_26 = 0 ;
F_19 ( & V_6 -> V_78 , V_63 ) ;
V_47 = F_32 ( V_6 , V_99 -> V_74 ,
V_99 -> V_75 ) ;
if ( V_47 ) {
V_26 = V_47 -> V_26 ;
V_144 = V_47 -> V_144 ;
}
F_22 ( & V_6 -> V_78 , V_63 ) ;
if ( ! V_26 )
goto V_77;
if ( F_63 ( V_6 , & V_28 , & V_142 ,
V_145 , V_26 ,
sizeof( T_11 ) ) ) {
F_13 ( V_33 L_2 ,
V_6 -> V_34 , __FILE__ , __LINE__ , V_35 ) ;
V_144 = 0 ;
goto V_77;
}
V_143 = F_59 ( V_142 . V_146 ) ;
if ( ! ( V_143 &
V_147 ) )
V_144 = 0 ;
V_77:
F_64 ( V_148 , V_117 , V_144 ) ;
}
static void
F_65 ( struct V_42 * V_117 )
{
struct V_98 * V_99 = F_61 ( V_117 ) ;
struct V_5 * V_6 = F_47 ( V_99 -> V_103 ) ;
static struct V_46 * V_47 ;
unsigned long V_63 ;
T_11 V_142 ;
T_9 V_28 ;
T_10 V_149 ;
enum V_150 V_151 = V_152 ;
T_4 V_26 = 0 ;
F_19 ( & V_6 -> V_78 , V_63 ) ;
V_47 = F_32 ( V_6 , V_99 -> V_74 ,
V_99 -> V_75 ) ;
if ( V_47 )
V_26 = V_47 -> V_26 ;
F_22 ( & V_6 -> V_78 , V_63 ) ;
if ( ! V_47 )
goto V_77;
if ( F_63 ( V_6 , & V_28 , & V_142 ,
V_145 , V_26 ,
sizeof( T_11 ) ) ) {
F_13 ( V_33 L_2 ,
V_6 -> V_34 , __FILE__ , __LINE__ , V_35 ) ;
goto V_77;
}
V_149 = F_59 ( V_142 . V_146 ) ;
if ( V_149 & V_147 ) {
V_151 = V_153 ;
goto V_77;
}
switch ( V_142 . V_154 ) {
case V_155 :
case V_156 :
V_151 = V_157 ;
break;
case V_158 :
V_151 = V_159 ;
break;
case V_160 :
case V_161 :
V_151 = V_162 ;
break;
}
V_77:
F_66 ( V_148 , V_117 , V_151 ) ;
}
static void
F_67 ( struct V_98 * V_99 , T_6 V_163 )
{
enum V_164 V_165 = V_166 ;
switch ( V_163 ) {
case V_167 :
V_165 = V_168 ;
break;
case V_169 :
V_165 = V_170 ;
break;
case V_171 :
V_165 = V_172 ;
break;
case V_173 :
V_165 = V_174 ;
break;
}
F_68 ( V_148 , & V_99 -> V_175 , V_165 ) ;
}
static int
F_69 ( struct V_5 * V_6 ,
struct V_46 * V_47 )
{
T_11 * V_142 ;
T_12 V_176 ;
T_8 V_27 ;
T_9 V_28 ;
T_4 V_177 ;
T_6 V_178 ;
if ( ( F_70 ( V_6 , V_47 -> V_26 ,
& V_178 ) ) || ! V_178 ) {
F_71 ( V_6 , F_72 ( V_33
L_2 , V_6 -> V_34 , __FILE__ , __LINE__ ,
V_35 ) ) ;
return 1 ;
}
V_47 -> V_178 = V_178 ;
V_177 = F_73 ( T_11 , V_179 ) + ( V_178 *
sizeof( V_180 ) ) ;
V_142 = F_51 ( V_177 , V_120 ) ;
if ( ! V_142 ) {
F_71 ( V_6 , F_72 ( V_33
L_2 , V_6 -> V_34 , __FILE__ , __LINE__ ,
V_35 ) ) ;
return 1 ;
}
if ( ( F_63 ( V_6 , & V_28 , V_142 ,
V_145 , V_47 -> V_26 , V_177 ) ) ) {
F_71 ( V_6 , F_72 ( V_33
L_2 , V_6 -> V_34 , __FILE__ , __LINE__ ,
V_35 ) ) ;
F_21 ( V_142 ) ;
return 1 ;
}
V_47 -> V_163 = V_142 -> V_181 ;
if ( ! ( F_74 ( V_6 , & V_28 ,
& V_176 , V_182 ,
V_142 -> V_179 [ 0 ] . V_183 ) ) ) {
if ( ! ( F_12 ( V_6 , & V_28 ,
& V_27 , V_32 ,
F_9 ( V_176 . V_184 ) ) ) ) {
V_47 -> V_84 =
F_59 ( V_27 . V_135 ) ;
}
}
F_21 ( V_142 ) ;
return 0 ;
}
static void
F_75 ( struct V_5 * V_6 , struct V_98 * V_99 )
{
if ( V_99 -> type != V_185 )
return;
if ( ! ( V_6 -> V_186 . V_187 & V_188 ) )
return;
F_76 ( V_99 ) ;
F_56 ( V_133 , V_99 , L_19 ,
F_77 ( V_99 ) ? L_20 : L_21 ) ;
return;
}
static int
F_78 ( struct V_98 * V_99 )
{
struct V_101 * V_102 = V_99 -> V_103 ;
struct V_5 * V_6 = F_47 ( V_102 ) ;
struct V_105 * V_106 ;
struct V_107 * V_108 ;
struct V_44 * V_45 ;
struct V_46 * V_47 ;
unsigned long V_63 ;
int V_100 ;
T_6 V_189 = 0 ;
char * V_190 = L_22 ;
char * V_191 = L_22 ;
T_4 V_26 , V_192 = 0 ;
T_1 V_193 = 0 ;
V_100 = 1 ;
V_106 = V_99 -> V_110 ;
V_106 -> V_194 = 1 ;
V_106 -> V_63 &= ~ V_130 ;
V_108 = V_106 -> V_112 ;
V_26 = V_108 -> V_26 ;
if ( V_108 -> V_63 & V_113 ) {
F_19 ( & V_6 -> V_78 , V_63 ) ;
V_47 = F_33 ( V_6 , V_26 ) ;
F_22 ( & V_6 -> V_78 , V_63 ) ;
if ( ! V_47 ) {
F_71 ( V_6 , F_72 ( V_33
L_2 , V_6 -> V_34 , __FILE__ ,
__LINE__ , V_35 ) ) ;
return 1 ;
}
if ( F_69 ( V_6 , V_47 ) ) {
F_71 ( V_6 , F_72 ( V_33
L_2 , V_6 -> V_34 , __FILE__ ,
__LINE__ , V_35 ) ) ;
return 1 ;
}
if ( V_47 -> V_84 &
V_86 ) {
V_100 = V_195 ;
V_190 = L_23 ;
} else {
V_100 = V_114 ;
if ( V_47 -> V_84 &
V_88 )
V_190 = L_24 ;
else
V_190 = L_25 ;
}
switch ( V_47 -> V_163 ) {
case V_167 :
V_191 = L_26 ;
break;
case V_171 :
V_100 = V_196 ;
if ( V_6 -> V_197 . V_198 &&
( F_59 ( V_6 -> V_197 . V_199 ) &
V_200 ) &&
! ( V_47 -> V_178 % 2 ) )
V_191 = L_27 ;
else
V_191 = L_28 ;
break;
case V_173 :
V_100 = V_196 ;
V_191 = L_29 ;
break;
case V_169 :
V_100 = V_196 ;
V_191 = L_27 ;
break;
case V_201 :
default:
V_100 = V_196 ;
V_191 = L_30 ;
break;
}
F_56 ( V_133 , V_99 ,
L_31 ,
V_191 , V_47 -> V_26 ,
( unsigned long long ) V_47 -> V_51 ,
V_47 -> V_178 , V_190 ) ;
F_46 ( V_99 , V_100 ) ;
F_67 ( V_99 , V_47 -> V_163 ) ;
return 0 ;
}
if ( V_108 -> V_63 & V_127 ) {
if ( F_79 ( V_6 , V_26 ,
& V_192 ) ) {
F_71 ( V_6 , F_72 ( V_33
L_2 , V_6 -> V_34 ,
__FILE__ , __LINE__ , V_35 ) ) ;
return 1 ;
}
if ( V_192 && F_80 ( V_6 ,
V_192 , & V_193 ) ) {
F_71 ( V_6 , F_72 ( V_33
L_2 , V_6 -> V_34 ,
__FILE__ , __LINE__ , V_35 ) ) ;
return 1 ;
}
}
F_19 ( & V_6 -> V_67 , V_63 ) ;
V_45 = F_16 ( V_6 ,
V_106 -> V_112 -> V_8 ) ;
if ( ! V_45 ) {
F_22 ( & V_6 -> V_67 , V_63 ) ;
F_71 ( V_6 , F_72 ( V_33
L_2 , V_6 -> V_34 , __FILE__ , __LINE__ ,
V_35 ) ) ;
return 1 ;
}
V_45 -> V_192 = V_192 ;
V_45 -> V_193 = V_193 ;
if ( V_45 -> V_84 & V_86 ) {
V_100 = V_195 ;
V_189 = 1 ;
V_190 = L_23 ;
} else {
V_100 = V_114 ;
if ( V_45 -> V_84 & V_87 )
V_190 = L_25 ;
else if ( V_45 -> V_84 &
V_88 )
V_190 = L_24 ;
}
F_56 ( V_133 , V_99 , L_32 \
L_33 ,
V_190 , V_26 , ( unsigned long long ) V_45 -> V_8 ,
V_45 -> V_202 , ( unsigned long long ) V_45 -> V_11 ) ;
if ( V_45 -> V_64 != 0 )
F_56 ( V_133 , V_99 ,
L_34 ,
V_190 , ( unsigned long long )
V_45 -> V_13 , V_45 -> V_17 ) ;
if ( V_45 -> V_65 [ 0 ] != '\0' )
F_56 ( V_133 , V_99 ,
L_12 ,
V_190 , V_45 -> V_66 ,
V_45 -> V_65 ) ;
F_22 ( & V_6 -> V_67 , V_63 ) ;
if ( ! V_189 )
F_58 ( V_6 , V_26 , V_99 ) ;
F_46 ( V_99 , V_100 ) ;
if ( V_189 ) {
F_81 ( V_99 ) ;
F_75 ( V_6 , V_99 ) ;
}
return 0 ;
}
static int
F_82 ( struct V_98 * V_99 , struct V_203 * V_204 ,
T_13 V_205 , int V_206 [] )
{
int V_207 ;
int V_208 ;
T_13 V_209 ;
T_14 V_210 ;
V_207 = 64 ;
V_208 = 32 ;
V_210 = V_207 * V_208 ;
V_209 = V_205 ;
F_83 ( V_209 , V_210 ) ;
if ( ( T_14 ) V_205 >= 0x200000 ) {
V_207 = 255 ;
V_208 = 63 ;
V_210 = V_207 * V_208 ;
V_209 = V_205 ;
F_83 ( V_209 , V_210 ) ;
}
V_206 [ 0 ] = V_207 ;
V_206 [ 1 ] = V_208 ;
V_206 [ 2 ] = V_209 ;
return 0 ;
}
static void
F_84 ( struct V_5 * V_6 , T_6 V_211 )
{
char * V_212 ;
switch ( V_211 ) {
case V_213 :
V_212 = L_35 ;
break;
case V_214 :
V_212 = L_36 ;
break;
case V_215 :
V_212 = L_37 ;
break;
case V_216 :
V_212 = L_38 ;
break;
case V_217 :
V_212 = L_39 ;
break;
case V_218 :
V_212 = L_40 ;
break;
case 0xA :
V_212 = L_41 ;
break;
case V_219 :
V_212 = L_42 ;
break;
default:
V_212 = L_43 ;
break;
}
F_72 ( V_33 L_44 ,
V_6 -> V_34 , V_211 , V_212 ) ;
}
static T_6
F_85 ( struct V_5 * V_6 , T_4 V_90 , T_6 V_220 , T_10 V_221 )
{
T_15 * V_28 ;
if ( V_6 -> V_222 . V_223 == V_224 )
return 1 ;
if ( V_6 -> V_222 . V_90 != V_90 )
return 1 ;
F_86 ( V_6 ) ;
V_6 -> V_222 . V_223 |= V_225 ;
V_28 = F_87 ( V_6 , V_221 ) ;
if ( V_28 ) {
memcpy ( V_6 -> V_222 . V_221 , V_28 , V_28 -> V_226 * 4 ) ;
V_6 -> V_222 . V_223 |= V_227 ;
}
V_6 -> V_222 . V_223 &= ~ V_228 ;
F_88 ( & V_6 -> V_222 . V_229 ) ;
return 1 ;
}
void
F_89 ( struct V_5 * V_6 , T_4 V_26 )
{
struct V_105 * V_106 ;
struct V_98 * V_99 ;
T_6 V_230 = 0 ;
F_90 (sdev, ioc->shost) {
if ( V_230 )
continue;
V_106 = V_99 -> V_110 ;
if ( ! V_106 )
continue;
if ( V_106 -> V_112 -> V_26 == V_26 ) {
V_106 -> V_112 -> V_231 = 1 ;
V_230 = 1 ;
V_6 -> V_232 = 1 ;
}
}
}
void
F_91 ( struct V_5 * V_6 , T_4 V_26 )
{
struct V_105 * V_106 ;
struct V_98 * V_99 ;
T_6 V_230 = 0 ;
F_90 (sdev, ioc->shost) {
if ( V_230 )
continue;
V_106 = V_99 -> V_110 ;
if ( ! V_106 )
continue;
if ( V_106 -> V_112 -> V_26 == V_26 ) {
V_106 -> V_112 -> V_231 = 0 ;
V_230 = 1 ;
V_6 -> V_232 = 0 ;
}
}
}
int
F_92 ( struct V_5 * V_6 , T_4 V_26 , T_16 V_75 ,
T_16 V_74 , T_16 V_97 , T_6 type , T_4 V_233 , T_14 V_234 ,
enum V_235 V_236 )
{
T_17 * V_237 ;
T_18 * V_28 ;
T_4 V_90 = 0 ;
T_10 V_238 ;
unsigned long V_239 ;
struct V_240 * V_91 = NULL ;
int V_19 ;
if ( V_236 == V_241 )
F_93 ( & V_6 -> V_222 . V_242 ) ;
if ( V_6 -> V_222 . V_223 != V_224 ) {
F_3 ( V_33 L_45 ,
V_35 , V_6 -> V_34 ) ;
V_19 = V_243 ;
goto V_244;
}
if ( V_6 -> V_69 || V_6 -> V_245 ||
V_6 -> V_246 ) {
F_3 ( V_33 L_46 ,
V_35 , V_6 -> V_34 ) ;
V_19 = V_243 ;
goto V_244;
}
V_238 = F_94 ( V_6 , 0 ) ;
if ( V_238 & V_247 ) {
F_95 ( V_6 , F_3 ( V_33
L_47 , V_6 -> V_34 ) ) ;
V_19 = F_96 ( V_6 , V_248 ,
V_249 ) ;
V_19 = ( ! V_19 ) ? V_250 : V_243 ;
goto V_244;
}
if ( ( V_238 & V_251 ) == V_252 ) {
F_97 ( V_6 , V_238 &
V_253 ) ;
V_19 = F_96 ( V_6 , V_248 ,
V_249 ) ;
V_19 = ( ! V_19 ) ? V_250 : V_243 ;
goto V_244;
}
V_90 = F_98 ( V_6 , V_6 -> V_254 ) ;
if ( ! V_90 ) {
F_13 ( V_33 L_48 ,
V_6 -> V_34 , V_35 ) ;
V_19 = V_243 ;
goto V_244;
}
if ( type == V_255 )
V_91 = & V_6 -> V_91 [ V_233 - 1 ] ;
F_99 ( V_6 , F_3 ( V_33
L_49 ,
V_6 -> V_34 , V_26 , type , V_233 ) ) ;
V_6 -> V_222 . V_223 = V_228 ;
V_237 = F_100 ( V_6 , V_90 ) ;
V_6 -> V_222 . V_90 = V_90 ;
memset ( V_237 , 0 , sizeof( T_17 ) ) ;
memset ( V_6 -> V_222 . V_221 , 0 , sizeof( T_18 ) ) ;
V_237 -> V_256 = V_257 ;
V_237 -> V_184 = F_101 ( V_26 ) ;
V_237 -> V_258 = type ;
V_237 -> V_259 = F_101 ( V_233 ) ;
F_102 ( V_97 , (struct V_260 * ) V_237 -> V_261 ) ;
F_89 ( V_6 , V_26 ) ;
F_103 ( & V_6 -> V_222 . V_229 ) ;
F_104 ( V_6 , V_90 ) ;
V_239 = F_105 ( & V_6 -> V_222 . V_229 , V_234 * V_262 ) ;
if ( ! ( V_6 -> V_222 . V_223 & V_225 ) ) {
F_13 ( V_33 L_50 ,
V_6 -> V_34 , V_35 ) ;
F_106 ( V_237 ,
sizeof( T_17 ) / 4 ) ;
if ( ! ( V_6 -> V_222 . V_223 & V_263 ) ) {
V_19 = F_96 ( V_6 , V_248 ,
V_249 ) ;
V_19 = ( ! V_19 ) ? V_250 : V_243 ;
V_6 -> V_222 . V_223 = V_224 ;
F_91 ( V_6 , V_26 ) ;
goto V_244;
}
}
if ( V_6 -> V_222 . V_223 & V_227 ) {
F_107 ( V_6 , V_264 ) ;
V_28 = V_6 -> V_222 . V_221 ;
F_99 ( V_6 , F_3 ( V_33 L_51 \
L_52 ,
V_6 -> V_34 , F_9 ( V_28 -> V_37 ) ,
F_59 ( V_28 -> V_265 ) ,
F_59 ( V_28 -> V_266 ) ) ) ;
if ( V_6 -> V_7 & V_267 ) {
F_84 ( V_6 , V_28 -> V_268 ) ;
if ( V_28 -> V_37 )
F_106 ( V_237 ,
sizeof( T_17 ) / 4 ) ;
}
}
switch ( type ) {
case V_255 :
V_19 = V_250 ;
if ( V_91 -> V_92 == NULL )
break;
V_19 = V_243 ;
break;
case V_269 :
if ( F_44 ( V_6 , V_74 , V_75 ) )
V_19 = V_243 ;
else
V_19 = V_250 ;
break;
case V_270 :
case V_271 :
if ( F_45 ( V_6 , V_74 , V_97 , V_75 ) )
V_19 = V_243 ;
else
V_19 = V_250 ;
break;
case V_272 :
V_19 = V_250 ;
break;
default:
V_19 = V_243 ;
break;
}
F_91 ( V_6 , V_26 ) ;
V_6 -> V_222 . V_223 = V_224 ;
if ( V_236 == V_241 )
F_108 ( & V_6 -> V_222 . V_242 ) ;
return V_19 ;
V_244:
if ( V_236 == V_241 )
F_108 ( & V_6 -> V_222 . V_242 ) ;
return V_19 ;
}
static void
F_109 ( struct V_5 * V_6 , struct V_89 * V_92 )
{
struct V_116 * V_72 = V_92 -> V_42 -> V_273 ;
struct V_107 * V_274 = V_72 -> V_110 ;
struct V_44 * V_45 = NULL ;
unsigned long V_63 ;
char * V_275 = NULL ;
if ( ! V_274 )
return;
V_275 = L_53 ;
F_110 ( V_92 ) ;
if ( V_274 -> V_63 & V_113 ) {
F_111 ( V_133 , V_72 ,
L_54 ,
V_275 , V_274 -> V_26 ,
V_275 , ( unsigned long long ) V_274 -> V_8 ) ;
} else {
F_19 ( & V_6 -> V_67 , V_63 ) ;
V_45 = F_16 ( V_6 ,
V_274 -> V_8 ) ;
if ( V_45 ) {
if ( V_274 -> V_63 &
V_127 ) {
F_111 ( V_133 , V_72 ,
L_55
L_56 ,
V_45 -> V_192 ,
( unsigned long long ) V_45 -> V_193 ) ;
}
F_111 ( V_133 , V_72 ,
L_57 ,
V_45 -> V_26 ,
( unsigned long long ) V_45 -> V_8 ,
V_45 -> V_202 ) ;
if ( V_45 -> V_64 != 0 )
F_111 ( V_133 , V_72 ,
L_58 ,
( unsigned long long )
V_45 -> V_13 ,
V_45 -> V_17 ) ;
if ( V_45 -> V_65 )
F_111 ( V_133 , V_72 ,
L_59 ,
V_45 -> V_66 ,
V_45 -> V_65 ) ;
}
F_22 ( & V_6 -> V_67 , V_63 ) ;
}
}
static int
F_112 ( struct V_89 * V_92 )
{
struct V_5 * V_6 = F_47 ( V_92 -> V_42 -> V_103 ) ;
struct V_105 * V_106 ;
T_4 V_90 ;
T_4 V_26 ;
int V_76 ;
F_56 ( V_133 , V_92 -> V_42 ,
L_60 , V_92 ) ;
F_109 ( V_6 , V_92 ) ;
V_106 = V_92 -> V_42 -> V_110 ;
if ( ! V_106 || ! V_106 -> V_112 ) {
F_56 ( V_133 , V_92 -> V_42 ,
L_61 , V_92 ) ;
V_92 -> V_276 = V_277 << 16 ;
V_92 -> V_278 ( V_92 ) ;
V_76 = V_250 ;
goto V_77;
}
V_90 = F_43 ( V_6 , V_92 ) ;
if ( ! V_90 ) {
V_92 -> V_276 = V_279 << 16 ;
V_76 = V_250 ;
goto V_77;
}
if ( V_106 -> V_112 -> V_63 &
V_127 ||
V_106 -> V_112 -> V_63 & V_113 ) {
V_92 -> V_276 = V_279 << 16 ;
V_76 = V_243 ;
goto V_77;
}
F_113 ( V_6 ) ;
V_26 = V_106 -> V_112 -> V_26 ;
V_76 = F_92 ( V_6 , V_26 , V_92 -> V_42 -> V_75 ,
V_92 -> V_42 -> V_74 , V_92 -> V_42 -> V_97 ,
V_255 , V_90 , 30 , V_241 ) ;
V_77:
F_56 ( V_133 , V_92 -> V_42 , L_62 ,
( ( V_76 == V_250 ) ? L_63 : L_64 ) , V_92 ) ;
return V_76 ;
}
static int
F_114 ( struct V_89 * V_92 )
{
struct V_5 * V_6 = F_47 ( V_92 -> V_42 -> V_103 ) ;
struct V_105 * V_106 ;
struct V_44 * V_45 ;
unsigned long V_63 ;
T_4 V_26 ;
int V_76 ;
F_56 ( V_133 , V_92 -> V_42 ,
L_65 , V_92 ) ;
F_109 ( V_6 , V_92 ) ;
V_106 = V_92 -> V_42 -> V_110 ;
if ( ! V_106 || ! V_106 -> V_112 ) {
F_56 ( V_133 , V_92 -> V_42 ,
L_61 , V_92 ) ;
V_92 -> V_276 = V_277 << 16 ;
V_92 -> V_278 ( V_92 ) ;
V_76 = V_250 ;
goto V_77;
}
V_26 = 0 ;
if ( V_106 -> V_112 -> V_63 &
V_127 ) {
F_19 ( & V_6 -> V_67 , V_63 ) ;
V_45 = F_17 ( V_6 ,
V_106 -> V_112 -> V_26 ) ;
if ( V_45 )
V_26 = V_45 -> V_192 ;
F_22 ( & V_6 -> V_67 , V_63 ) ;
} else
V_26 = V_106 -> V_112 -> V_26 ;
if ( ! V_26 ) {
V_92 -> V_276 = V_279 << 16 ;
V_76 = V_243 ;
goto V_77;
}
V_76 = F_92 ( V_6 , V_26 , V_92 -> V_42 -> V_75 ,
V_92 -> V_42 -> V_74 , V_92 -> V_42 -> V_97 ,
V_271 , 0 , 30 , V_241 ) ;
V_77:
F_56 ( V_133 , V_92 -> V_42 , L_66 ,
( ( V_76 == V_250 ) ? L_63 : L_64 ) , V_92 ) ;
return V_76 ;
}
static int
F_115 ( struct V_89 * V_92 )
{
struct V_5 * V_6 = F_47 ( V_92 -> V_42 -> V_103 ) ;
struct V_105 * V_106 ;
struct V_44 * V_45 ;
unsigned long V_63 ;
T_4 V_26 ;
int V_76 ;
struct V_116 * V_72 = V_92 -> V_42 -> V_273 ;
F_111 ( V_133 , V_72 , L_67 ,
V_92 ) ;
F_109 ( V_6 , V_92 ) ;
V_106 = V_92 -> V_42 -> V_110 ;
if ( ! V_106 || ! V_106 -> V_112 ) {
F_111 ( V_133 , V_72 , L_68 ,
V_92 ) ;
V_92 -> V_276 = V_277 << 16 ;
V_92 -> V_278 ( V_92 ) ;
V_76 = V_250 ;
goto V_77;
}
V_26 = 0 ;
if ( V_106 -> V_112 -> V_63 &
V_127 ) {
F_19 ( & V_6 -> V_67 , V_63 ) ;
V_45 = F_17 ( V_6 ,
V_106 -> V_112 -> V_26 ) ;
if ( V_45 )
V_26 = V_45 -> V_192 ;
F_22 ( & V_6 -> V_67 , V_63 ) ;
} else
V_26 = V_106 -> V_112 -> V_26 ;
if ( ! V_26 ) {
V_92 -> V_276 = V_279 << 16 ;
V_76 = V_243 ;
goto V_77;
}
V_76 = F_92 ( V_6 , V_26 , V_92 -> V_42 -> V_75 ,
V_92 -> V_42 -> V_74 , 0 , V_269 , 0 ,
30 , V_241 ) ;
V_77:
F_111 ( V_133 , V_72 , L_69 ,
( ( V_76 == V_250 ) ? L_63 : L_64 ) , V_92 ) ;
return V_76 ;
}
static int
F_116 ( struct V_89 * V_92 )
{
struct V_5 * V_6 = F_47 ( V_92 -> V_42 -> V_103 ) ;
int V_76 , V_280 ;
F_3 ( V_33 L_70 ,
V_6 -> V_34 , V_92 ) ;
F_110 ( V_92 ) ;
if ( V_6 -> V_48 ) {
F_3 ( V_33 L_71 ,
V_6 -> V_34 ) ;
V_76 = V_243 ;
goto V_77;
}
V_280 = F_96 ( V_6 , V_248 ,
V_249 ) ;
V_76 = ( V_280 < 0 ) ? V_243 : V_250 ;
V_77:
F_3 ( V_33 L_72 ,
V_6 -> V_34 , ( ( V_76 == V_250 ) ? L_63 : L_64 ) , V_92 ) ;
return V_76 ;
}
static void
F_117 ( struct V_5 * V_6 , struct V_281 * V_282 )
{
unsigned long V_63 ;
if ( V_6 -> V_283 == NULL )
return;
F_19 ( & V_6 -> V_284 , V_63 ) ;
F_118 ( & V_282 -> V_68 ) ;
F_28 ( & V_282 -> V_68 , & V_6 -> V_285 ) ;
F_119 ( & V_282 -> V_286 , V_287 ) ;
F_120 ( V_6 -> V_283 , & V_282 -> V_286 ) ;
F_22 ( & V_6 -> V_284 , V_63 ) ;
}
static void
F_121 ( struct V_5 * V_6 , struct V_281
* V_282 )
{
unsigned long V_63 ;
F_19 ( & V_6 -> V_284 , V_63 ) ;
F_20 ( & V_282 -> V_68 ) ;
F_21 ( V_282 ) ;
F_22 ( & V_6 -> V_284 , V_63 ) ;
}
void
F_122 ( struct V_5 * V_6 ,
struct V_288 * V_289 )
{
struct V_281 * V_282 ;
if ( V_6 -> V_48 )
return;
V_282 = F_51 ( sizeof( * V_282 ) + sizeof( * V_289 ) ,
V_290 ) ;
if ( ! V_282 )
return;
V_282 -> V_291 = V_292 ;
V_282 -> V_6 = V_6 ;
memcpy ( V_282 -> V_289 , V_289 , sizeof( * V_289 ) ) ;
F_117 ( V_6 , V_282 ) ;
}
static void
F_123 ( struct V_5 * V_6 )
{
struct V_281 * V_282 ;
if ( V_6 -> V_48 )
return;
V_282 = F_51 ( sizeof( struct V_281 ) , V_290 ) ;
if ( ! V_282 )
return;
V_282 -> V_291 = V_293 ;
V_282 -> V_6 = V_6 ;
F_117 ( V_6 , V_282 ) ;
}
void
F_124 ( struct V_5 * V_6 )
{
struct V_281 * V_282 ;
V_282 = F_51 ( sizeof( struct V_281 ) , V_290 ) ;
if ( ! V_282 )
return;
V_282 -> V_291 = V_294 ;
V_282 -> V_6 = V_6 ;
F_117 ( V_6 , V_282 ) ;
}
static void
F_125 ( struct V_5 * V_6 )
{
struct V_281 * V_282 , * V_295 ;
if ( F_126 ( & V_6 -> V_285 ) ||
! V_6 -> V_283 || F_127 () )
return;
F_128 (fw_event, next, &ioc->fw_event_list, list) {
if ( F_129 ( & V_282 -> V_296 ) ) {
F_121 ( V_6 , V_282 ) ;
continue;
}
}
}
static void
F_130 ( struct V_98 * V_99 ,
struct V_105 * V_106 )
{
int V_76 = 0 ;
F_56 ( V_133 , V_99 , L_73 ,
V_106 -> V_112 -> V_26 ) ;
V_106 -> V_297 = 1 ;
V_76 = F_131 ( V_99 ) ;
if ( V_76 == - V_298 )
F_56 ( V_299 , V_99 ,
L_74 ,
V_106 -> V_112 -> V_26 , V_76 ) ;
}
static void
F_132 ( struct V_98 * V_99 ,
struct V_105 * V_106 )
{
int V_76 = 0 ;
F_56 ( V_299 , V_99 , L_75
L_76 , V_106 -> V_112 -> V_26 ) ;
V_106 -> V_297 = 0 ;
V_76 = F_133 ( V_99 , V_300 ) ;
if ( V_76 == - V_298 ) {
F_56 ( V_299 , V_99 ,
L_77
L_78 ,
V_106 -> V_112 -> V_26 , V_76 ) ;
V_106 -> V_297 = 1 ;
V_76 = F_131 ( V_99 ) ;
if ( V_76 )
F_56 ( V_299 , V_99 , L_79
L_80 ,
V_106 -> V_112 -> V_26 , V_76 ) ;
V_106 -> V_297 = 0 ;
V_76 = F_133 ( V_99 , V_300 ) ;
if ( V_76 )
F_56 ( V_299 , V_99 , L_81
L_82 ,
V_106 -> V_112 -> V_26 , V_76 ) ;
}
}
static void
F_134 ( struct V_5 * V_6 )
{
struct V_105 * V_106 ;
struct V_98 * V_99 ;
F_90 (sdev, ioc->shost) {
V_106 = V_99 -> V_110 ;
if ( ! V_106 )
continue;
if ( ! V_106 -> V_297 )
continue;
F_27 ( V_6 , F_56 ( V_133 , V_99 ,
L_83 ,
V_106 -> V_112 -> V_26 ) ) ;
F_132 ( V_99 , V_106 ) ;
}
}
static void
F_135 ( struct V_5 * V_6 , T_1 V_8 )
{
struct V_105 * V_106 ;
struct V_98 * V_99 ;
F_90 (sdev, ioc->shost) {
V_106 = V_99 -> V_110 ;
if ( ! V_106 )
continue;
if ( V_106 -> V_112 -> V_8
!= V_8 )
continue;
if ( V_106 -> V_297 )
F_132 ( V_99 ,
V_106 ) ;
}
}
static void
F_136 ( struct V_5 * V_6 )
{
struct V_105 * V_106 ;
struct V_98 * V_99 ;
F_90 (sdev, ioc->shost) {
V_106 = V_99 -> V_110 ;
if ( ! V_106 )
continue;
if ( V_106 -> V_297 )
continue;
F_130 ( V_99 , V_106 ) ;
}
}
static void
F_137 ( struct V_5 * V_6 , T_4 V_26 )
{
struct V_105 * V_106 ;
struct V_98 * V_99 ;
struct V_44 * V_45 ;
V_45 = F_17 ( V_6 , V_26 ) ;
if ( ! V_45 )
return;
F_90 (sdev, ioc->shost) {
V_106 = V_99 -> V_110 ;
if ( ! V_106 )
continue;
if ( V_106 -> V_112 -> V_26 != V_26 )
continue;
if ( V_106 -> V_297 )
continue;
if ( V_45 -> V_301 )
continue;
F_130 ( V_99 , V_106 ) ;
}
}
static void
F_138 ( struct V_5 * V_6 ,
struct V_80 * V_81 )
{
struct V_302 * V_303 ;
struct V_44 * V_45 ;
struct V_80 * V_304 ;
unsigned long V_63 ;
if ( ! V_81 )
return;
F_4 (mpt3sas_port,
&sas_expander->sas_port_list, port_list) {
if ( V_303 -> V_305 . V_306 ==
V_307 ) {
F_19 ( & V_6 -> V_67 , V_63 ) ;
V_45 =
F_16 ( V_6 ,
V_303 -> V_305 . V_8 ) ;
if ( V_45 )
F_139 ( V_45 -> V_26 ,
V_6 -> V_308 ) ;
F_22 ( & V_6 -> V_67 , V_63 ) ;
}
}
F_4 (mpt3sas_port,
&sas_expander->sas_port_list, port_list) {
if ( V_303 -> V_305 . V_306 ==
V_309 ||
V_303 -> V_305 . V_306 ==
V_310 ) {
V_304 =
F_38 (
V_6 , V_303 -> V_305 . V_8 ) ;
F_138 ( V_6 ,
V_304 ) ;
}
}
}
static void
F_140 ( struct V_5 * V_6 ,
T_19 * V_289 )
{
int V_94 ;
T_4 V_26 ;
T_4 V_311 ;
for ( V_94 = 0 ; V_94 < V_289 -> V_312 ; V_94 ++ ) {
V_26 = F_9 ( V_289 -> V_313 [ V_94 ] . V_314 ) ;
if ( ! V_26 )
continue;
V_311 = V_289 -> V_313 [ V_94 ] . V_315 &
V_316 ;
if ( V_311 == V_317 )
F_137 ( V_6 , V_26 ) ;
}
}
static void
F_141 ( struct V_5 * V_6 , T_4 V_26 )
{
T_17 * V_237 ;
T_4 V_90 ;
struct V_44 * V_45 ;
struct V_107 * V_108 = NULL ;
T_1 V_8 = 0 ;
unsigned long V_63 ;
struct V_318 * V_319 ;
T_10 V_238 ;
if ( V_6 -> V_245 ) {
F_27 ( V_6 , F_3 ( V_33
L_84 ,
V_35 , V_6 -> V_34 , V_26 ) ) ;
return;
} else if ( V_6 -> V_246 ) {
F_27 ( V_6 , F_3 ( V_33
L_85 ,
V_35 , V_6 -> V_34 ,
V_26 ) ) ;
return;
}
V_238 = F_94 ( V_6 , 1 ) ;
if ( V_238 != V_320 ) {
F_27 ( V_6 , F_3 ( V_33
L_86 ,
V_35 , V_6 -> V_34 ,
V_26 ) ) ;
return;
}
if ( F_53 ( V_26 , V_6 -> V_126 ) )
return;
F_19 ( & V_6 -> V_67 , V_63 ) ;
V_45 = F_17 ( V_6 , V_26 ) ;
if ( V_45 && V_45 -> V_72 &&
V_45 -> V_72 -> V_110 ) {
V_108 = V_45 -> V_72 -> V_110 ;
V_108 -> V_321 = 1 ;
V_8 = V_45 -> V_8 ;
}
F_22 ( & V_6 -> V_67 , V_63 ) ;
if ( V_108 ) {
F_27 ( V_6 , F_3 ( V_33
L_87 ,
V_6 -> V_34 , V_26 ,
( unsigned long long ) V_8 ) ) ;
if ( V_45 -> V_64 != 0 )
F_27 ( V_6 , F_3 ( V_33
L_88
L_89 , V_6 -> V_34 , ( unsigned long long )
V_45 -> V_13 ,
V_45 -> V_17 ) ) ;
if ( V_45 -> V_65 )
F_27 ( V_6 , F_3 ( V_33
L_90
L_91 , V_6 -> V_34 ,
V_45 -> V_66 ,
V_45 -> V_65 ) ) ;
F_135 ( V_6 , V_8 ) ;
V_108 -> V_26 = V_122 ;
}
V_90 = F_98 ( V_6 , V_6 -> V_322 ) ;
if ( ! V_90 ) {
V_319 = F_51 ( sizeof( * V_319 ) , V_290 ) ;
if ( ! V_319 )
return;
F_118 ( & V_319 -> V_68 ) ;
V_319 -> V_26 = V_26 ;
F_28 ( & V_319 -> V_68 , & V_6 -> V_323 ) ;
F_27 ( V_6 , F_3 ( V_33
L_92 ,
V_6 -> V_34 , V_26 ) ) ;
return;
}
F_27 ( V_6 , F_3 ( V_33
L_93 ,
V_6 -> V_34 , V_26 , V_90 ,
V_6 -> V_322 ) ) ;
V_237 = F_100 ( V_6 , V_90 ) ;
memset ( V_237 , 0 , sizeof( T_17 ) ) ;
V_237 -> V_256 = V_257 ;
V_237 -> V_184 = F_101 ( V_26 ) ;
V_237 -> V_258 = V_269 ;
F_104 ( V_6 , V_90 ) ;
F_107 ( V_6 , V_324 ) ;
}
static T_6
F_142 ( struct V_5 * V_6 , T_4 V_90 , T_6 V_220 ,
T_10 V_221 )
{
T_4 V_26 ;
T_17 * V_325 ;
T_18 * V_28 =
F_87 ( V_6 , V_221 ) ;
T_20 * V_237 ;
T_4 V_326 ;
T_10 V_238 ;
if ( V_6 -> V_245 ) {
F_27 ( V_6 , F_3 ( V_33
L_94 , V_35 , V_6 -> V_34 ) ) ;
return 1 ;
} else if ( V_6 -> V_246 ) {
F_27 ( V_6 , F_3 ( V_33
L_95 , V_35 ,
V_6 -> V_34 ) ) ;
return 1 ;
}
V_238 = F_94 ( V_6 , 1 ) ;
if ( V_238 != V_320 ) {
F_27 ( V_6 , F_3 ( V_33
L_96 , V_35 , V_6 -> V_34 ) ) ;
return 1 ;
}
if ( F_143 ( ! V_28 ) ) {
F_13 ( V_33 L_97 ,
V_6 -> V_34 , __FILE__ , __LINE__ , V_35 ) ;
return 1 ;
}
V_325 = F_100 ( V_6 , V_90 ) ;
V_26 = F_9 ( V_325 -> V_184 ) ;
if ( V_26 != F_9 ( V_28 -> V_184 ) ) {
F_27 ( V_6 , F_13 ( V_33
L_98 ,
V_6 -> V_34 , V_26 ,
F_9 ( V_28 -> V_184 ) , V_90 ) ) ;
return 0 ;
}
F_107 ( V_6 , V_264 ) ;
F_27 ( V_6 , F_3 ( V_33
L_99
L_100 , V_6 -> V_34 ,
V_26 , V_90 , F_9 ( V_28 -> V_37 ) ,
F_59 ( V_28 -> V_265 ) ,
F_59 ( V_28 -> V_266 ) ) ) ;
V_326 = F_144 ( V_6 , V_6 -> V_327 ) ;
if ( ! V_326 ) {
F_13 ( V_33 L_48 ,
V_6 -> V_34 , V_35 ) ;
return 1 ;
}
F_27 ( V_6 , F_3 ( V_33
L_101 ,
V_6 -> V_34 , V_26 , V_326 ,
V_6 -> V_327 ) ) ;
V_237 = F_100 ( V_6 , V_326 ) ;
memset ( V_237 , 0 , sizeof( T_20 ) ) ;
V_237 -> V_256 = V_328 ;
V_237 -> V_329 = V_330 ;
V_237 -> V_184 = V_325 -> V_184 ;
F_145 ( V_6 , V_326 ) ;
return F_146 ( V_6 , V_90 ) ;
}
static T_6
F_147 ( struct V_5 * V_6 , T_4 V_90 ,
T_6 V_220 , T_10 V_221 )
{
T_21 * V_28 =
F_87 ( V_6 , V_221 ) ;
if ( F_148 ( V_28 ) ) {
F_27 ( V_6 , F_3 ( V_33
L_102
L_103 ,
V_6 -> V_34 , F_9 ( V_28 -> V_184 ) , V_90 ,
F_9 ( V_28 -> V_37 ) ,
F_59 ( V_28 -> V_265 ) ) ) ;
} else {
F_13 ( V_33 L_97 ,
V_6 -> V_34 , __FILE__ , __LINE__ , V_35 ) ;
}
return 1 ;
}
static void
F_149 ( struct V_5 * V_6 , T_4 V_26 )
{
T_17 * V_237 ;
T_4 V_90 ;
struct V_318 * V_319 ;
if ( V_6 -> V_69 || V_6 -> V_245 ||
V_6 -> V_246 ) {
F_27 ( V_6 , F_3 ( V_33
L_46 ,
V_35 , V_6 -> V_34 ) ) ;
return;
}
V_90 = F_98 ( V_6 , V_6 -> V_331 ) ;
if ( ! V_90 ) {
V_319 = F_51 ( sizeof( * V_319 ) , V_290 ) ;
if ( ! V_319 )
return;
F_118 ( & V_319 -> V_68 ) ;
V_319 -> V_26 = V_26 ;
F_28 ( & V_319 -> V_68 , & V_6 -> V_332 ) ;
F_27 ( V_6 , F_3 ( V_33
L_92 ,
V_6 -> V_34 , V_26 ) ) ;
return;
}
F_27 ( V_6 , F_3 ( V_33
L_93 ,
V_6 -> V_34 , V_26 , V_90 ,
V_6 -> V_331 ) ) ;
V_237 = F_100 ( V_6 , V_90 ) ;
memset ( V_237 , 0 , sizeof( T_17 ) ) ;
V_237 -> V_256 = V_257 ;
V_237 -> V_184 = F_101 ( V_26 ) ;
V_237 -> V_258 = V_269 ;
F_104 ( V_6 , V_90 ) ;
}
static T_6
F_150 ( struct V_5 * V_6 , T_4 V_90 ,
T_6 V_220 , T_10 V_221 )
{
T_4 V_26 ;
T_17 * V_325 ;
T_18 * V_28 =
F_87 ( V_6 , V_221 ) ;
if ( V_6 -> V_69 || V_6 -> V_245 ||
V_6 -> V_246 ) {
F_27 ( V_6 , F_3 ( V_33
L_46 ,
V_35 , V_6 -> V_34 ) ) ;
return 1 ;
}
if ( F_143 ( ! V_28 ) ) {
F_13 ( V_33 L_97 ,
V_6 -> V_34 , __FILE__ , __LINE__ , V_35 ) ;
return 1 ;
}
V_325 = F_100 ( V_6 , V_90 ) ;
V_26 = F_9 ( V_325 -> V_184 ) ;
if ( V_26 != F_9 ( V_28 -> V_184 ) ) {
F_27 ( V_6 , F_13 ( V_33
L_98 ,
V_6 -> V_34 , V_26 ,
F_9 ( V_28 -> V_184 ) , V_90 ) ) ;
return 0 ;
}
F_27 ( V_6 , F_3 ( V_33
L_99
L_100 , V_6 -> V_34 ,
V_26 , V_90 , F_9 ( V_28 -> V_37 ) ,
F_59 ( V_28 -> V_265 ) ,
F_59 ( V_28 -> V_266 ) ) ) ;
return F_146 ( V_6 , V_90 ) ;
}
static T_6
F_146 ( struct V_5 * V_6 , T_4 V_90 )
{
struct V_318 * V_319 ;
if ( ! F_126 ( & V_6 -> V_332 ) ) {
V_319 = F_151 ( V_6 -> V_332 . V_295 ,
struct V_318 , V_68 ) ;
F_152 ( V_6 , V_90 ) ;
F_149 ( V_6 , V_319 -> V_26 ) ;
F_20 ( & V_319 -> V_68 ) ;
F_21 ( V_319 ) ;
return 0 ;
}
if ( ! F_126 ( & V_6 -> V_323 ) ) {
V_319 = F_151 ( V_6 -> V_323 . V_295 ,
struct V_318 , V_68 ) ;
F_152 ( V_6 , V_90 ) ;
F_141 ( V_6 , V_319 -> V_26 ) ;
F_20 ( & V_319 -> V_68 ) ;
F_21 ( V_319 ) ;
return 0 ;
}
return 1 ;
}
static void
F_153 ( struct V_5 * V_6 ,
T_19 * V_289 )
{
struct V_281 * V_282 ;
T_19 * V_333 ;
T_4 V_334 ;
struct V_80 * V_81 ;
unsigned long V_63 ;
int V_94 , V_311 ;
T_4 V_26 ;
for ( V_94 = 0 ; V_94 < V_289 -> V_312 ; V_94 ++ ) {
V_26 = F_9 ( V_289 -> V_313 [ V_94 ] . V_314 ) ;
if ( ! V_26 )
continue;
V_311 = V_289 -> V_313 [ V_94 ] . V_315 &
V_316 ;
if ( V_311 == V_335 )
F_141 ( V_6 , V_26 ) ;
}
V_334 = F_9 ( V_289 -> V_336 ) ;
if ( V_334 < V_6 -> V_30 . V_31 ) {
F_140 ( V_6 , V_289 ) ;
return;
}
if ( V_289 -> V_337 ==
V_338 ) {
F_19 ( & V_6 -> V_82 , V_63 ) ;
V_81 = F_37 ( V_6 ,
V_334 ) ;
F_138 ( V_6 , V_81 ) ;
F_22 ( & V_6 -> V_82 , V_63 ) ;
do {
V_26 = F_154 ( V_6 -> V_308 ,
V_6 -> V_186 . V_339 ) ;
if ( V_26 < V_6 -> V_186 . V_339 )
F_137 ( V_6 , V_26 ) ;
} while ( F_155 ( V_26 , V_6 -> V_308 ) );
} else if ( V_289 -> V_337 == V_340 )
F_140 ( V_6 , V_289 ) ;
if ( V_289 -> V_337 != V_341 )
return;
F_19 ( & V_6 -> V_284 , V_63 ) ;
F_4 (fw_event, &ioc->fw_event_list, list) {
if ( V_282 -> V_291 != V_342 ||
V_282 -> V_343 )
continue;
V_333 = ( T_19 * )
V_282 -> V_289 ;
if ( V_333 -> V_337 ==
V_344 ||
V_333 -> V_337 ==
V_340 ) {
if ( F_9 ( V_333 -> V_336 ) ==
V_334 ) {
F_27 ( V_6 , F_3 ( V_33
L_104 , V_6 -> V_34 ) ) ;
V_282 -> V_343 = 1 ;
}
}
}
F_22 ( & V_6 -> V_284 , V_63 ) ;
}
static void
F_156 ( struct V_5 * V_6 , T_4 V_26 )
{
struct V_46 * V_47 ;
struct V_107 * V_108 ;
unsigned long V_63 ;
F_19 ( & V_6 -> V_78 , V_63 ) ;
V_47 = F_33 ( V_6 , V_26 ) ;
if ( V_47 && V_47 -> V_72 &&
V_47 -> V_72 -> V_110 ) {
V_108 =
V_47 -> V_72 -> V_110 ;
V_108 -> V_321 = 1 ;
F_27 ( V_6 , F_3 ( V_33
L_105
L_106 , V_6 -> V_34 , V_26 ,
( unsigned long long ) V_47 -> V_51 ) ) ;
}
F_22 ( & V_6 -> V_78 , V_63 ) ;
}
static void
F_157 ( T_4 V_26 , T_4 * V_345 , T_4 * V_346 )
{
if ( ! V_26 || V_26 == * V_345 || V_26 == * V_346 )
return;
if ( ! * V_345 )
* V_345 = V_26 ;
else if ( ! * V_346 )
* V_346 = V_26 ;
}
static void
F_158 ( struct V_5 * V_6 ,
T_22 * V_289 )
{
T_23 * V_347 ;
int V_94 ;
T_4 V_26 , V_192 , V_345 , V_346 ;
struct V_318 * V_319 ;
V_345 = 0 ;
V_346 = 0 ;
V_347 = ( T_23 * ) & V_289 -> V_348 [ 0 ] ;
for ( V_94 = 0 ; V_94 < V_289 -> V_349 ; V_94 ++ , V_347 ++ ) {
if ( F_59 ( V_289 -> V_134 ) &
V_350 )
continue;
if ( V_347 -> V_351 ==
V_352 ||
V_347 -> V_351 ==
V_353 ) {
V_192 = F_9 ( V_347 -> V_354 ) ;
F_156 ( V_6 , V_192 ) ;
F_157 ( V_192 , & V_345 , & V_346 ) ;
}
}
V_347 = ( T_23 * ) & V_289 -> V_348 [ 0 ] ;
for ( V_94 = 0 ; V_94 < V_289 -> V_349 ; V_94 ++ , V_347 ++ ) {
if ( F_59 ( V_289 -> V_134 ) &
V_350 )
continue;
if ( V_347 -> V_351 == V_355 ) {
V_192 = F_9 ( V_347 -> V_354 ) ;
F_157 ( V_192 , & V_345 , & V_346 ) ;
}
}
if ( V_345 )
F_149 ( V_6 , V_345 ) ;
if ( V_346 )
F_149 ( V_6 , V_346 ) ;
V_347 = ( T_23 * ) & V_289 -> V_348 [ 0 ] ;
for ( V_94 = 0 ; V_94 < V_289 -> V_349 ; V_94 ++ , V_347 ++ ) {
if ( V_347 -> V_351 != V_355 )
continue;
V_26 = F_9 ( V_347 -> V_356 ) ;
V_192 = F_9 ( V_347 -> V_354 ) ;
F_159 ( V_26 , V_6 -> V_126 ) ;
if ( ! V_192 )
F_141 ( V_6 , V_26 ) ;
else if ( V_192 == V_345 || V_192 == V_346 ) {
V_319 = F_51 ( sizeof( * V_319 ) , V_290 ) ;
F_160 ( ! V_319 ) ;
F_118 ( & V_319 -> V_68 ) ;
V_319 -> V_26 = V_26 ;
F_28 ( & V_319 -> V_68 , & V_6 -> V_323 ) ;
F_27 ( V_6 , F_3 ( V_33
L_92 , V_6 -> V_34 ,
V_26 ) ) ;
} else
F_141 ( V_6 , V_26 ) ;
}
}
static void
F_161 ( struct V_5 * V_6 ,
T_24 * V_289 )
{
T_10 V_151 ;
if ( V_289 -> V_351 != V_357 )
return;
V_151 = F_59 ( V_289 -> V_358 ) ;
if ( V_151 == V_161 || V_151 ==
V_160 )
F_156 ( V_6 ,
F_9 ( V_289 -> V_354 ) ) ;
}
static void
F_162 ( struct V_5 * V_6 ,
T_25 * V_289 )
{
if ( V_6 -> V_359 >= V_289 -> V_360 ) {
F_13 ( V_33 L_107
L_108 , V_6 -> V_34 ,
( ( F_9 ( V_289 -> V_361 ) & 0x1 ) == 1 ) ? L_109 : L_110 ,
( ( F_9 ( V_289 -> V_361 ) & 0x2 ) == 2 ) ? L_111 : L_110 ,
( ( F_9 ( V_289 -> V_361 ) & 0x4 ) == 4 ) ? L_112 : L_110 ,
( ( F_9 ( V_289 -> V_361 ) & 0x8 ) == 8 ) ? L_113 : L_110 ,
V_289 -> V_360 ) ;
F_13 ( V_33 L_114 ,
V_6 -> V_34 , V_289 -> V_362 ) ;
}
}
static void
F_163 ( struct V_5 * V_6 )
{
struct V_89 * V_92 ;
T_4 V_90 ;
T_4 V_363 = 0 ;
for ( V_90 = 1 ; V_90 <= V_6 -> V_95 ; V_90 ++ ) {
V_92 = F_42 ( V_6 , V_90 ) ;
if ( ! V_92 )
continue;
V_363 ++ ;
F_152 ( V_6 , V_90 ) ;
F_164 ( V_92 ) ;
if ( V_6 -> V_246 )
V_92 -> V_276 = V_277 << 16 ;
else
V_92 -> V_276 = V_279 << 16 ;
V_92 -> V_278 ( V_92 ) ;
}
F_99 ( V_6 , F_3 ( V_33 L_115 ,
V_6 -> V_34 , V_363 ) ) ;
}
static void
F_165 ( struct V_5 * V_6 , struct V_89 * V_92 ,
T_26 * V_237 )
{
T_4 V_364 ;
unsigned char V_365 = F_166 ( V_92 ) ;
unsigned char V_366 = F_167 ( V_92 ) ;
T_27 * V_367 =
( T_27 * ) V_237 ;
if ( V_366 == V_368 || V_365 == V_369 )
return;
if ( V_365 == V_370 )
V_364 = V_371 ;
else if ( V_365 == V_372 )
V_364 = V_373 ;
else
return;
switch ( V_366 ) {
case V_374 :
case V_375 :
V_364 |= V_376 |
V_377 |
V_378 ;
V_237 -> V_379 . V_380 . V_381 =
F_168 ( F_169 ( V_92 ) ) ;
break;
case V_382 :
V_364 |= V_378 ;
break;
}
V_367 -> V_383 =
F_101 ( V_92 -> V_42 -> V_384 ) ;
V_237 -> V_385 = F_101 ( V_364 ) ;
}
static void
F_170 ( struct V_89 * V_92 , T_4 V_29 )
{
T_6 V_386 ;
switch ( V_29 ) {
case V_387 :
V_386 = 0x01 ;
break;
case V_388 :
V_386 = 0x02 ;
break;
case V_389 :
V_386 = 0x03 ;
break;
default:
V_386 = 0x00 ;
break;
}
F_171 ( 0 , V_92 -> V_390 , V_391 , 0x10 ,
V_386 ) ;
V_92 -> V_276 = V_392 << 24 | ( V_393 << 16 ) |
V_394 ;
}
static int
F_172 ( struct V_101 * V_102 , struct V_89 * V_92 )
{
struct V_5 * V_6 = F_47 ( V_102 ) ;
struct V_105 * V_106 ;
struct V_107 * V_108 ;
T_26 * V_237 ;
T_10 V_395 ;
T_4 V_90 ;
T_4 V_26 ;
#ifdef F_173
if ( V_6 -> V_7 & V_396 )
F_110 ( V_92 ) ;
#endif
V_106 = V_92 -> V_42 -> V_110 ;
if ( ! V_106 || ! V_106 -> V_112 ) {
V_92 -> V_276 = V_277 << 16 ;
V_92 -> V_278 ( V_92 ) ;
return 0 ;
}
if ( V_6 -> V_246 || V_6 -> V_245 ) {
V_92 -> V_276 = V_277 << 16 ;
V_92 -> V_278 ( V_92 ) ;
return 0 ;
}
V_108 = V_106 -> V_112 ;
V_26 = V_108 -> V_26 ;
if ( V_26 == V_122 ) {
V_92 -> V_276 = V_277 << 16 ;
V_92 -> V_278 ( V_92 ) ;
return 0 ;
}
if ( V_6 -> V_69 || V_6 -> V_397 )
return V_398 ;
else if ( V_108 -> V_321 ) {
V_92 -> V_276 = V_277 << 16 ;
V_92 -> V_278 ( V_92 ) ;
return 0 ;
} else if ( V_108 -> V_231 ||
V_106 -> V_297 )
return V_399 ;
if ( V_92 -> V_400 == V_401 )
V_395 = V_402 ;
else if ( V_92 -> V_400 == V_403 )
V_395 = V_404 ;
else
V_395 = V_405 ;
V_395 |= V_406 ;
if ( ( V_106 -> V_63 & V_407 ) &&
V_92 -> V_408 != 32 )
V_395 |= V_409 ;
V_90 = F_174 ( V_6 , V_6 -> V_410 , V_92 ) ;
if ( ! V_90 ) {
F_13 ( V_33 L_48 ,
V_6 -> V_34 , V_35 ) ;
goto V_77;
}
V_237 = F_100 ( V_6 , V_90 ) ;
memset ( V_237 , 0 , sizeof( T_26 ) ) ;
F_165 ( V_6 , V_92 , V_237 ) ;
if ( V_92 -> V_408 == 32 )
V_395 |= 4 << V_411 ;
V_237 -> V_256 = V_412 ;
if ( V_106 -> V_112 -> V_63 &
V_127 )
V_237 -> V_256 = V_413 ;
else
V_237 -> V_256 = V_412 ;
V_237 -> V_184 = F_101 ( V_26 ) ;
V_237 -> V_414 = F_175 ( F_176 ( V_92 ) ) ;
V_237 -> V_415 = F_175 ( V_395 ) ;
V_237 -> V_416 = F_101 ( V_92 -> V_408 ) ;
V_237 -> V_417 = V_418 ;
V_237 -> V_419 = V_420 ;
V_237 -> V_421 =
F_177 ( V_6 , V_90 ) ;
V_237 -> V_422 = F_73 ( T_26 , V_423 ) / 4 ;
F_102 ( V_106 -> V_97 , (struct V_260 * )
V_237 -> V_261 ) ;
memcpy ( V_237 -> V_379 . V_424 , V_92 -> V_425 , V_92 -> V_408 ) ;
if ( V_237 -> V_414 ) {
if ( V_6 -> V_426 ( V_6 , V_92 , V_90 ) ) {
F_152 ( V_6 , V_90 ) ;
goto V_77;
}
} else
V_6 -> V_427 ( V_6 , & V_237 -> V_423 ) ;
if ( F_148 ( V_237 -> V_256 == V_412 ) ) {
if ( V_108 -> V_63 & V_129 ) {
V_237 -> V_416 = F_101 ( V_92 -> V_408 |
V_428 ) ;
F_178 ( V_6 , V_90 , V_26 ) ;
} else
F_179 ( V_6 , V_90 , V_26 ) ;
} else
F_145 ( V_6 , V_90 ) ;
return 0 ;
V_77:
return V_398 ;
}
static void
F_180 ( char * V_390 , struct V_429 * V_430 )
{
if ( ( V_390 [ 0 ] & 0x7F ) >= 0x72 ) {
V_430 -> V_431 = V_390 [ 1 ] & 0x0F ;
V_430 -> V_432 = V_390 [ 2 ] ;
V_430 -> V_386 = V_390 [ 3 ] ;
} else {
V_430 -> V_431 = V_390 [ 2 ] & 0x0F ;
V_430 -> V_432 = V_390 [ 12 ] ;
V_430 -> V_386 = V_390 [ 13 ] ;
}
}
static void
F_181 ( struct V_5 * V_6 , struct V_89 * V_92 ,
T_28 * V_28 , T_4 V_90 )
{
T_10 V_433 ;
T_6 * V_434 ;
T_4 V_29 = F_9 ( V_28 -> V_37 ) &
V_38 ;
T_6 V_435 = V_28 -> V_436 ;
T_6 V_437 = V_28 -> V_438 ;
char * V_439 = NULL ;
char * V_440 = NULL ;
char * V_441 = V_6 -> V_442 ;
T_10 V_443 = F_59 ( V_28 -> V_265 ) ;
struct V_44 * V_45 = NULL ;
unsigned long V_63 ;
struct V_116 * V_72 = V_92 -> V_42 -> V_273 ;
struct V_107 * V_274 = V_72 -> V_110 ;
char * V_275 = NULL ;
if ( ! V_274 )
return;
V_275 = L_53 ;
if ( V_443 == 0x31170000 )
return;
switch ( V_29 ) {
case V_39 :
V_439 = L_116 ;
break;
case V_444 :
V_439 = L_117 ;
break;
case V_445 :
V_439 = L_118 ;
break;
case V_446 :
V_439 = L_119 ;
break;
case V_447 :
V_439 = L_120 ;
break;
case V_448 :
V_439 = L_121 ;
break;
case V_449 :
V_439 = L_122 ;
break;
case V_450 :
V_439 = L_123 ;
break;
case V_451 :
V_439 = L_124 ;
break;
case V_452 :
V_439 = L_125 ;
break;
case V_453 :
V_439 = L_126 ;
break;
case V_454 :
V_439 = L_127 ;
break;
case V_455 :
V_439 = L_128 ;
break;
case V_456 :
V_439 = L_129 ;
break;
case V_387 :
V_439 = L_130 ;
break;
case V_389 :
V_439 = L_131 ;
break;
case V_388 :
V_439 = L_132 ;
break;
default:
V_439 = L_43 ;
break;
}
switch ( V_437 ) {
case V_457 :
V_440 = L_133 ;
break;
case V_458 :
V_440 = L_134 ;
break;
case V_459 :
V_440 = L_135 ;
break;
case V_460 :
V_440 = L_136 ;
break;
case V_461 :
V_440 = L_137 ;
break;
case V_462 :
V_440 = L_138 ;
break;
case V_463 :
V_440 = L_139 ;
break;
case V_464 :
V_440 = L_140 ;
break;
case V_465 :
V_440 = L_141 ;
break;
case V_466 :
V_440 = L_142 ;
break;
case V_467 :
V_440 = L_143 ;
break;
default:
V_440 = L_43 ;
break;
}
V_441 [ 0 ] = '\0' ;
if ( ! V_435 )
V_441 = L_110 ;
if ( V_435 & V_468 )
strcat ( V_441 , L_144 ) ;
if ( V_435 & V_469 )
strcat ( V_441 , L_145 ) ;
if ( V_435 & V_470 )
strcat ( V_441 , L_146 ) ;
if ( V_435 & V_471 )
strcat ( V_441 , L_147 ) ;
if ( V_435 & V_472 )
strcat ( V_441 , L_148 ) ;
F_110 ( V_92 ) ;
if ( V_274 -> V_63 & V_113 ) {
F_72 ( V_33 L_149 , V_6 -> V_34 ,
V_275 , ( unsigned long long ) V_274 -> V_8 ) ;
} else {
F_19 ( & V_6 -> V_67 , V_63 ) ;
V_45 = F_16 ( V_6 ,
V_274 -> V_8 ) ;
if ( V_45 ) {
F_72 ( V_33
L_150 ,
V_6 -> V_34 , ( unsigned long long )
V_45 -> V_8 , V_45 -> V_202 ) ;
if ( V_45 -> V_64 != 0 )
F_72 ( V_33
L_151
L_152 , V_6 -> V_34 ,
( unsigned long long )
V_45 -> V_13 ,
V_45 -> V_17 ) ;
if ( V_45 -> V_65 [ 0 ] )
F_72 ( V_33
L_153
L_91 , V_6 -> V_34 ,
V_45 -> V_66 ,
V_45 -> V_65 ) ;
}
F_22 ( & V_6 -> V_67 , V_63 ) ;
}
F_72 ( V_33
L_154 ,
V_6 -> V_34 , F_9 ( V_28 -> V_184 ) ,
V_439 , V_29 , V_90 ) ;
F_72 ( V_33
L_155 ,
V_6 -> V_34 , F_176 ( V_92 ) , V_92 -> V_473 ,
F_182 ( V_92 ) ) ;
F_72 ( V_33
L_156 ,
V_6 -> V_34 , F_9 ( V_28 -> V_474 ) ,
F_59 ( V_28 -> V_475 ) , V_92 -> V_276 ) ;
F_72 ( V_33
L_157 ,
V_6 -> V_34 , V_440 ,
V_437 , V_441 , V_435 ) ;
if ( V_435 & V_472 ) {
struct V_429 V_430 ;
F_180 ( V_92 -> V_390 , & V_430 ) ;
F_72 ( V_33
L_158 ,
V_6 -> V_34 , V_430 . V_431 ,
V_430 . V_432 , V_430 . V_386 , F_59 ( V_28 -> V_476 ) ) ;
}
if ( V_435 & V_468 ) {
V_433 = F_59 ( V_28 -> V_477 ) ;
V_434 = ( T_6 * ) & V_433 ;
F_84 ( V_6 , V_434 [ 0 ] ) ;
}
}
static void
F_183 ( struct V_5 * V_6 , T_4 V_26 )
{
T_29 V_28 ;
T_30 V_237 ;
struct V_44 * V_45 ;
V_45 = F_17 ( V_6 , V_26 ) ;
if ( ! V_45 )
return;
memset ( & V_237 , 0 , sizeof( T_30 ) ) ;
V_237 . V_256 = V_478 ;
V_237 . V_479 = V_480 ;
V_237 . V_481 =
F_175 ( V_482 ) ;
V_237 . V_184 = F_101 ( V_26 ) ;
V_237 . V_134 = V_483 ;
if ( ( F_184 ( V_6 , & V_28 ,
& V_237 ) ) != 0 ) {
F_13 ( V_33 L_2 , V_6 -> V_34 ,
__FILE__ , __LINE__ , V_35 ) ;
return;
}
V_45 -> V_484 = 1 ;
if ( V_28 . V_37 || V_28 . V_265 ) {
F_27 ( V_6 , F_3 ( V_33
L_159 ,
V_6 -> V_34 , F_9 ( V_28 . V_37 ) ,
F_59 ( V_28 . V_265 ) ) ) ;
return;
}
}
static void
F_185 ( struct V_5 * V_6 ,
struct V_44 * V_45 )
{
T_29 V_28 ;
T_30 V_237 ;
memset ( & V_237 , 0 , sizeof( T_30 ) ) ;
V_237 . V_256 = V_478 ;
V_237 . V_479 = V_480 ;
V_237 . V_481 = 0 ;
V_237 . V_485 = F_101 ( V_45 -> V_17 ) ;
V_237 . V_184 = 0 ;
V_237 . V_486 = F_101 ( V_45 -> V_64 ) ;
V_237 . V_134 = V_487 ;
if ( ( F_184 ( V_6 , & V_28 ,
& V_237 ) ) != 0 ) {
F_186 ( V_33 L_2 , V_6 -> V_34 ,
__FILE__ , __LINE__ , V_35 ) ;
return;
}
if ( V_28 . V_37 || V_28 . V_265 ) {
F_27 ( V_6 , F_186 ( V_33
L_159 ,
V_6 -> V_34 , F_9 ( V_28 . V_37 ) ,
F_59 ( V_28 . V_265 ) ) ) ;
return;
}
}
static void
F_187 ( struct V_5 * V_6 , T_4 V_26 )
{
struct V_281 * V_282 ;
V_282 = F_51 ( sizeof( struct V_281 ) , V_290 ) ;
if ( ! V_282 )
return;
V_282 -> V_291 = V_488 ;
V_282 -> V_489 = V_26 ;
V_282 -> V_6 = V_6 ;
F_117 ( V_6 , V_282 ) ;
}
static void
F_188 ( struct V_5 * V_6 , T_4 V_26 )
{
struct V_116 * V_72 ;
struct V_107 * V_108 ;
T_31 * V_490 ;
T_32 * V_289 ;
struct V_44 * V_45 ;
T_33 V_177 ;
unsigned long V_63 ;
F_19 ( & V_6 -> V_67 , V_63 ) ;
V_45 = F_17 ( V_6 , V_26 ) ;
if ( ! V_45 ) {
F_22 ( & V_6 -> V_67 , V_63 ) ;
return;
}
V_72 = V_45 -> V_72 ;
V_108 = V_72 -> V_110 ;
if ( ( V_108 -> V_63 & V_127 ) ||
( ( V_108 -> V_63 & V_113 ) ) ) {
F_22 ( & V_6 -> V_67 , V_63 ) ;
return;
}
if ( V_45 -> V_64 != 0 )
F_111 ( V_133 , V_72 , L_160
L_161 ,
( unsigned long long ) V_45 -> V_13 ,
V_45 -> V_17 ) ;
if ( V_45 -> V_65 [ 0 ] != '\0' )
F_111 ( V_299 , V_72 , L_160
L_162 ,
V_45 -> V_66 ,
V_45 -> V_65 ) ;
F_22 ( & V_6 -> V_67 , V_63 ) ;
if ( V_6 -> V_491 -> V_492 == V_493 )
F_187 ( V_6 , V_26 ) ;
V_177 = F_73 ( T_31 , V_494 ) +
sizeof( T_32 ) ;
V_490 = F_51 ( V_177 , V_120 ) ;
if ( ! V_490 ) {
F_13 ( V_33 L_2 ,
V_6 -> V_34 , __FILE__ , __LINE__ , V_35 ) ;
return;
}
V_490 -> V_256 = V_495 ;
V_490 -> V_496 =
F_101 ( V_497 ) ;
V_490 -> V_226 = V_177 / 4 ;
V_490 -> V_498 =
F_101 ( sizeof( T_32 ) / 4 ) ;
V_289 = ( T_32 * )
V_490 -> V_494 ;
V_289 -> V_351 = V_499 ;
V_289 -> V_500 = 0x5D ;
V_289 -> V_184 = F_101 ( V_26 ) ;
V_289 -> V_10 = F_189 ( V_108 -> V_8 ) ;
F_190 ( V_6 , V_490 ) ;
F_21 ( V_490 ) ;
}
static T_6
F_191 ( struct V_5 * V_6 , T_4 V_90 , T_6 V_220 , T_10 V_221 )
{
T_26 * V_237 ;
T_28 * V_28 ;
struct V_89 * V_92 ;
T_4 V_29 ;
T_10 V_501 ;
T_6 V_435 ;
T_6 V_437 ;
T_10 V_443 ;
struct V_105 * V_106 ;
T_10 V_211 = 0 ;
V_28 = F_87 ( V_6 , V_221 ) ;
V_92 = F_42 ( V_6 , V_90 ) ;
if ( V_92 == NULL )
return 1 ;
V_237 = F_100 ( V_6 , V_90 ) ;
if ( V_28 == NULL ) {
V_92 -> V_276 = V_502 << 16 ;
goto V_77;
}
V_106 = V_92 -> V_42 -> V_110 ;
if ( ! V_106 || ! V_106 -> V_112 ||
V_106 -> V_112 -> V_321 ) {
V_92 -> V_276 = V_277 << 16 ;
goto V_77;
}
V_29 = F_9 ( V_28 -> V_37 ) ;
V_435 = V_28 -> V_436 ;
if ( V_435 & V_468 )
V_211 =
F_59 ( V_28 -> V_477 ) & 0xFF ;
if ( ! V_106 -> V_503 ) {
V_106 -> V_503 ++ ;
if ( ( V_106 -> V_63 & V_407 ) &&
V_211 == V_214 )
V_106 -> V_63 &=
~ V_407 ;
}
V_501 = F_59 ( V_28 -> V_475 ) ;
F_192 ( V_92 , F_176 ( V_92 ) - V_501 ) ;
if ( V_29 & V_504 )
V_443 = F_59 ( V_28 -> V_265 ) ;
else
V_443 = 0 ;
V_29 &= V_38 ;
V_437 = V_28 -> V_438 ;
if ( V_29 == V_449 && V_501 == 0 &&
( V_437 == V_460 ||
V_437 == V_463 ||
V_437 == V_465 ) ) {
V_29 = V_39 ;
}
if ( V_435 & V_472 ) {
struct V_429 V_430 ;
const void * V_505 = F_193 ( V_6 ,
V_90 ) ;
T_10 V_177 = F_194 ( T_10 , V_420 ,
F_59 ( V_28 -> V_476 ) ) ;
memcpy ( V_92 -> V_390 , V_505 , V_177 ) ;
F_180 ( V_92 -> V_390 , & V_430 ) ;
if ( V_430 . V_432 == 0x5D )
F_188 ( V_6 ,
F_9 ( V_28 -> V_184 ) ) ;
F_195 ( V_6 , V_430 . V_431 , V_430 . V_432 , V_430 . V_386 ) ;
#ifdef F_173
if ( ! ( V_6 -> V_7 & V_506 ) &&
( ( V_92 -> V_390 [ 2 ] == V_507 ) ||
( V_92 -> V_390 [ 2 ] == V_508 ) ||
( V_92 -> V_390 [ 2 ] == V_509 ) ) )
F_181 ( V_6 , V_92 , V_28 , V_90 ) ;
#endif
}
switch ( V_29 ) {
case V_510 :
case V_511 :
V_92 -> V_276 = V_512 ;
break;
case V_447 :
V_92 -> V_276 = V_277 << 16 ;
break;
case V_455 :
if ( V_106 -> V_297 ) {
V_92 -> V_276 = V_513 << 16 ;
goto V_77;
}
if ( V_443 == 0x31110630 ) {
if ( V_92 -> V_514 > 2 ) {
V_92 -> V_276 = V_277 << 16 ;
F_196 ( V_92 -> V_42 ,
V_515 ) ;
} else {
V_92 -> V_276 = V_516 << 16 ;
V_92 -> V_42 -> V_517 = 1 ;
}
break;
} else if ( V_443 == V_518 ) {
V_92 -> V_276 = V_279 << 16 ;
break;
}
V_92 -> V_276 = V_516 << 16 ;
break;
case V_452 :
case V_456 :
V_92 -> V_276 = V_279 << 16 ;
break;
case V_453 :
if ( ( V_501 == 0 ) || ( V_92 -> V_473 > V_501 ) )
V_92 -> V_276 = V_516 << 16 ;
else
V_92 -> V_276 = ( V_502 << 16 ) | V_437 ;
break;
case V_449 :
V_92 -> V_276 = ( V_502 << 16 ) | V_437 ;
if ( ( V_435 & V_472 ) )
break;
if ( V_501 < V_92 -> V_473 ) {
if ( V_437 == V_512 )
V_92 -> V_276 = V_512 ;
else
V_92 -> V_276 = V_516 << 16 ;
} else if ( V_435 & ( V_471 |
V_470 ) )
V_92 -> V_276 = V_516 << 16 ;
else if ( V_435 & V_469 )
V_92 -> V_276 = V_279 << 16 ;
else if ( ! V_501 && V_92 -> V_425 [ 0 ] == V_519 ) {
V_28 -> V_436 = V_472 ;
V_28 -> V_438 = V_394 ;
V_92 -> V_276 = ( V_392 << 24 ) |
V_394 ;
V_92 -> V_390 [ 0 ] = 0x70 ;
V_92 -> V_390 [ 2 ] = V_391 ;
V_92 -> V_390 [ 12 ] = 0x20 ;
V_92 -> V_390 [ 13 ] = 0 ;
}
break;
case V_448 :
F_192 ( V_92 , 0 ) ;
case V_445 :
case V_39 :
V_92 -> V_276 = ( V_502 << 16 ) | V_437 ;
if ( V_211 ==
V_214 ||
( V_435 & ( V_471 |
V_470 ) ) )
V_92 -> V_276 = V_516 << 16 ;
else if ( V_435 & V_469 )
V_92 -> V_276 = V_279 << 16 ;
break;
case V_387 :
case V_389 :
case V_388 :
F_170 ( V_92 , V_29 ) ;
break;
case V_451 :
case V_444 :
case V_520 :
case V_521 :
case V_522 :
case V_523 :
case V_450 :
case V_454 :
default:
V_92 -> V_276 = V_516 << 16 ;
break;
}
#ifdef F_173
if ( V_92 -> V_276 && ( V_6 -> V_7 & V_506 ) )
F_181 ( V_6 , V_92 , V_28 , V_90 ) ;
#endif
V_77:
F_164 ( V_92 ) ;
V_92 -> V_278 ( V_92 ) ;
return 1 ;
}
static void
F_197 ( struct V_5 * V_6 )
{
T_4 V_177 ;
T_4 V_29 ;
int V_94 ;
T_9 V_28 ;
T_34 * V_524 = NULL ;
T_4 V_525 ;
T_6 V_526 ;
F_99 ( V_6 , F_3 ( V_33
L_163 ,
V_6 -> V_34 , ( unsigned long long ) V_6 -> V_30 . V_8 ) ) ;
V_177 = F_73 ( T_34 , V_527 ) + ( V_6 -> V_30 . V_31
* sizeof( V_528 ) ) ;
V_524 = F_51 ( V_177 , V_120 ) ;
if ( ! V_524 ) {
F_13 ( V_33 L_2 ,
V_6 -> V_34 , __FILE__ , __LINE__ , V_35 ) ;
return;
}
if ( ( F_198 ( V_6 , & V_28 ,
V_524 , V_177 ) ) != 0 )
goto V_77;
V_29 = F_9 ( V_28 . V_37 ) & V_38 ;
if ( V_29 != V_39 )
goto V_77;
for ( V_94 = 0 ; V_94 < V_6 -> V_30 . V_31 ; V_94 ++ ) {
V_526 = V_524 -> V_527 [ V_94 ] . V_529 >> 4 ;
if ( V_94 == 0 )
V_6 -> V_30 . V_26 = F_9 ( V_524 ->
V_527 [ 0 ] . V_530 ) ;
V_6 -> V_30 . V_202 [ V_94 ] . V_26 = V_6 -> V_30 . V_26 ;
V_525 = F_9 ( V_524 -> V_527 [ V_94 ] .
V_314 ) ;
if ( V_525 && V_526 < V_531 )
V_526 = V_531 ;
F_199 ( V_6 , V_6 -> V_30 . V_8 ,
V_525 , V_94 , V_526 ) ;
}
V_77:
F_21 ( V_524 ) ;
}
static void
F_200 ( struct V_5 * V_6 )
{
int V_94 ;
T_9 V_28 ;
T_34 * V_524 = NULL ;
T_35 * V_532 = NULL ;
T_36 V_533 ;
T_8 V_27 ;
T_37 V_534 ;
T_4 V_29 ;
T_4 V_177 ;
T_6 V_535 ;
F_201 ( V_6 , & V_6 -> V_30 . V_31 ) ;
if ( ! V_6 -> V_30 . V_31 ) {
F_13 ( V_33 L_2 ,
V_6 -> V_34 , __FILE__ , __LINE__ , V_35 ) ;
return;
}
V_177 = F_73 ( T_34 , V_527 ) + ( V_6 -> V_30 . V_31 *
sizeof( V_528 ) ) ;
V_524 = F_51 ( V_177 , V_120 ) ;
if ( ! V_524 ) {
F_13 ( V_33 L_2 ,
V_6 -> V_34 , __FILE__ , __LINE__ , V_35 ) ;
return;
}
if ( ( F_198 ( V_6 , & V_28 ,
V_524 , V_177 ) ) ) {
F_13 ( V_33 L_2 ,
V_6 -> V_34 , __FILE__ , __LINE__ , V_35 ) ;
goto V_77;
}
V_29 = F_9 ( V_28 . V_37 ) &
V_38 ;
if ( V_29 != V_39 ) {
F_13 ( V_33 L_2 ,
V_6 -> V_34 , __FILE__ , __LINE__ , V_35 ) ;
goto V_77;
}
V_177 = F_73 ( T_35 , V_527 ) + ( V_6 -> V_30 . V_31 *
sizeof( V_536 ) ) ;
V_532 = F_51 ( V_177 , V_120 ) ;
if ( ! V_532 ) {
F_13 ( V_33 L_2 ,
V_6 -> V_34 , __FILE__ , __LINE__ , V_35 ) ;
goto V_77;
}
if ( ( F_202 ( V_6 , & V_28 ,
V_532 , V_177 ) ) ) {
F_13 ( V_33 L_2 ,
V_6 -> V_34 , __FILE__ , __LINE__ , V_35 ) ;
goto V_77;
}
V_29 = F_9 ( V_28 . V_37 ) &
V_38 ;
if ( V_29 != V_39 ) {
F_13 ( V_33 L_2 ,
V_6 -> V_34 , __FILE__ , __LINE__ , V_35 ) ;
goto V_77;
}
V_6 -> V_537 =
V_532 -> V_538 ;
V_535 =
V_532 -> V_539 ;
if ( V_535 & V_540 )
V_6 -> V_535 = ( V_535 &
V_541 ) * 16 ;
else
V_6 -> V_535 = V_535 &
V_541 ;
V_6 -> V_30 . V_542 = & V_6 -> V_102 -> V_543 ;
V_6 -> V_30 . V_202 = F_203 ( V_6 -> V_30 . V_31 ,
sizeof( struct V_544 ) , V_120 ) ;
if ( ! V_6 -> V_30 . V_202 ) {
F_13 ( V_33 L_2 ,
V_6 -> V_34 , __FILE__ , __LINE__ , V_35 ) ;
goto V_77;
}
for ( V_94 = 0 ; V_94 < V_6 -> V_30 . V_31 ; V_94 ++ ) {
if ( ( F_204 ( V_6 , & V_28 , & V_533 ,
V_94 ) ) ) {
F_13 ( V_33 L_2 ,
V_6 -> V_34 , __FILE__ , __LINE__ , V_35 ) ;
goto V_77;
}
V_29 = F_9 ( V_28 . V_37 ) &
V_38 ;
if ( V_29 != V_39 ) {
F_13 ( V_33 L_2 ,
V_6 -> V_34 , __FILE__ , __LINE__ , V_35 ) ;
goto V_77;
}
if ( V_94 == 0 )
V_6 -> V_30 . V_26 = F_9 ( V_524 ->
V_527 [ 0 ] . V_530 ) ;
V_6 -> V_30 . V_202 [ V_94 ] . V_26 = V_6 -> V_30 . V_26 ;
V_6 -> V_30 . V_202 [ V_94 ] . V_545 = V_94 ;
F_205 ( V_6 , & V_6 -> V_30 . V_202 [ V_94 ] ,
V_533 , V_6 -> V_30 . V_542 ) ;
}
if ( ( F_12 ( V_6 , & V_28 , & V_27 ,
V_32 , V_6 -> V_30 . V_26 ) ) ) {
F_13 ( V_33 L_2 ,
V_6 -> V_34 , __FILE__ , __LINE__ , V_35 ) ;
goto V_77;
}
V_6 -> V_30 . V_64 =
F_9 ( V_27 . V_486 ) ;
V_6 -> V_30 . V_8 = F_6 ( V_27 . V_10 ) ;
F_3 ( V_33
L_164 ,
V_6 -> V_34 , V_6 -> V_30 . V_26 ,
( unsigned long long ) V_6 -> V_30 . V_8 ,
V_6 -> V_30 . V_31 ) ;
if ( V_6 -> V_30 . V_64 ) {
if ( ! ( F_206 ( V_6 , & V_28 ,
& V_534 , V_546 ,
V_6 -> V_30 . V_64 ) ) )
V_6 -> V_30 . V_13 =
F_6 ( V_534 . V_15 ) ;
}
V_77:
F_21 ( V_532 ) ;
F_21 ( V_524 ) ;
}
static int
F_207 ( struct V_5 * V_6 , T_4 V_26 )
{
struct V_80 * V_81 ;
T_9 V_28 ;
T_38 V_547 ;
T_39 V_548 ;
T_37 V_534 ;
T_10 V_29 ;
T_4 V_549 ;
T_1 V_8 , V_71 = 0 ;
int V_94 ;
unsigned long V_63 ;
struct V_302 * V_303 = NULL ;
int V_19 = 0 ;
if ( ! V_26 )
return - 1 ;
if ( V_6 -> V_69 || V_6 -> V_246 )
return - 1 ;
if ( ( F_208 ( V_6 , & V_28 , & V_547 ,
V_550 , V_26 ) ) ) {
F_13 ( V_33 L_2 ,
V_6 -> V_34 , __FILE__ , __LINE__ , V_35 ) ;
return - 1 ;
}
V_29 = F_9 ( V_28 . V_37 ) &
V_38 ;
if ( V_29 != V_39 ) {
F_13 ( V_33 L_2 ,
V_6 -> V_34 , __FILE__ , __LINE__ , V_35 ) ;
return - 1 ;
}
V_549 = F_9 ( V_547 . V_551 ) ;
if ( F_11 ( V_6 , V_549 , & V_71 )
!= 0 ) {
F_13 ( V_33 L_2 ,
V_6 -> V_34 , __FILE__ , __LINE__ , V_35 ) ;
return - 1 ;
}
if ( V_71 != V_6 -> V_30 . V_8 ) {
F_19 ( & V_6 -> V_82 , V_63 ) ;
V_81 = F_38 ( V_6 ,
V_71 ) ;
F_22 ( & V_6 -> V_82 , V_63 ) ;
if ( ! V_81 ) {
V_19 = F_207 ( V_6 , V_549 ) ;
if ( V_19 != 0 )
return V_19 ;
}
}
F_19 ( & V_6 -> V_82 , V_63 ) ;
V_8 = F_6 ( V_547 . V_10 ) ;
V_81 = F_38 ( V_6 ,
V_8 ) ;
F_22 ( & V_6 -> V_82 , V_63 ) ;
if ( V_81 )
return 0 ;
V_81 = F_51 ( sizeof( struct V_80 ) ,
V_120 ) ;
if ( ! V_81 ) {
F_13 ( V_33 L_2 ,
V_6 -> V_34 , __FILE__ , __LINE__ , V_35 ) ;
return - 1 ;
}
V_81 -> V_26 = V_26 ;
V_81 -> V_31 = V_547 . V_552 ;
V_81 -> V_71 = V_71 ;
V_81 -> V_8 = V_8 ;
F_3 ( V_33 L_165 \
L_166 , V_6 -> V_34 ,
V_26 , V_549 , ( unsigned long long )
V_81 -> V_8 , V_81 -> V_31 ) ;
if ( ! V_81 -> V_31 )
goto V_553;
V_81 -> V_202 = F_203 ( V_81 -> V_31 ,
sizeof( struct V_544 ) , V_120 ) ;
if ( ! V_81 -> V_202 ) {
F_13 ( V_33 L_2 ,
V_6 -> V_34 , __FILE__ , __LINE__ , V_35 ) ;
V_19 = - 1 ;
goto V_553;
}
F_118 ( & V_81 -> V_554 ) ;
V_303 = F_29 ( V_6 , V_26 ,
V_71 ) ;
if ( ! V_303 ) {
F_13 ( V_33 L_2 ,
V_6 -> V_34 , __FILE__ , __LINE__ , V_35 ) ;
V_19 = - 1 ;
goto V_553;
}
V_81 -> V_542 = & V_303 -> V_119 -> V_117 ;
for ( V_94 = 0 ; V_94 < V_81 -> V_31 ; V_94 ++ ) {
if ( ( F_209 ( V_6 , & V_28 ,
& V_548 , V_94 , V_26 ) ) ) {
F_13 ( V_33 L_2 ,
V_6 -> V_34 , __FILE__ , __LINE__ , V_35 ) ;
V_19 = - 1 ;
goto V_553;
}
V_81 -> V_202 [ V_94 ] . V_26 = V_26 ;
V_81 -> V_202 [ V_94 ] . V_545 = V_94 ;
if ( ( F_210 ( V_6 ,
& V_81 -> V_202 [ V_94 ] , V_548 ,
V_81 -> V_542 ) ) ) {
F_13 ( V_33 L_2 ,
V_6 -> V_34 , __FILE__ , __LINE__ , V_35 ) ;
V_19 = - 1 ;
goto V_553;
}
}
if ( V_81 -> V_64 ) {
if ( ! ( F_206 ( V_6 , & V_28 ,
& V_534 , V_546 ,
V_81 -> V_64 ) ) )
V_81 -> V_13 =
F_6 ( V_534 . V_15 ) ;
}
F_39 ( V_6 , V_81 ) ;
return 0 ;
V_553:
if ( V_303 )
F_30 ( V_6 , V_81 -> V_8 ,
V_71 ) ;
F_21 ( V_81 ) ;
return V_19 ;
}
void
F_211 ( struct V_5 * V_6 , T_1 V_8 )
{
struct V_80 * V_81 ;
unsigned long V_63 ;
if ( V_6 -> V_69 )
return;
F_19 ( & V_6 -> V_82 , V_63 ) ;
V_81 = F_38 ( V_6 ,
V_8 ) ;
if ( V_81 )
F_20 ( & V_81 -> V_68 ) ;
F_22 ( & V_6 -> V_82 , V_63 ) ;
if ( V_81 )
F_212 ( V_6 , V_81 ) ;
}
static T_6
F_213 ( struct V_5 * V_6 , T_4 V_90 , T_6 V_220 , T_10 V_221 )
{
T_15 * V_28 ;
V_28 = F_87 ( V_6 , V_221 ) ;
if ( V_6 -> V_555 . V_223 == V_224 )
return 1 ;
if ( V_6 -> V_555 . V_90 != V_90 )
return 1 ;
V_6 -> V_555 . V_223 |= V_225 ;
if ( V_28 ) {
memcpy ( V_6 -> V_555 . V_221 , V_28 ,
V_28 -> V_226 * 4 ) ;
V_6 -> V_555 . V_223 |= V_227 ;
}
V_6 -> V_555 . V_223 &= ~ V_228 ;
F_88 ( & V_6 -> V_555 . V_229 ) ;
return 1 ;
}
static T_6
F_214 ( struct V_5 * V_6 , T_1 V_8 ,
T_4 V_26 , T_6 V_556 )
{
T_6 V_19 = 1 ;
char * V_212 = NULL ;
switch ( V_556 ) {
case V_557 :
case V_558 :
V_19 = 0 ;
break;
case V_559 :
V_212 = L_167 ;
break;
case V_560 :
V_212 = L_168 ;
break;
case V_561 :
V_212 = L_169 ;
break;
case V_562 :
V_212 = L_170 ;
break;
case V_563 :
V_212 = L_171 ;
break;
case V_564 :
case V_565 :
case V_566 :
case V_567 :
case V_568 :
case V_569 :
case V_570 :
case V_571 :
case V_572 :
case V_573 :
case V_574 :
case V_575 :
V_212 = L_172 ;
break;
default:
V_212 = L_43 ;
break;
}
if ( ! V_19 )
return 0 ;
F_13 ( V_33
L_173 ,
V_6 -> V_34 , V_212 , ( unsigned long long ) V_8 , V_26 ) ;
return V_19 ;
}
static void
F_215 ( struct V_5 * V_6 ,
T_1 V_576 , T_4 V_26 , T_6 V_577 , T_6 V_526 )
{
T_9 V_28 ;
T_8 V_27 ;
struct V_44 * V_45 ;
T_10 V_29 ;
unsigned long V_63 ;
T_1 V_8 ;
struct V_116 * V_72 ;
struct V_107 * V_108 ;
T_10 V_84 ;
if ( ( F_12 ( V_6 , & V_28 , & V_27 ,
V_32 , V_26 ) ) )
return;
V_29 = F_9 ( V_28 . V_37 ) & V_38 ;
if ( V_29 != V_39 )
return;
if ( V_577 != V_27 . V_578 )
return;
V_84 = F_59 ( V_27 . V_135 ) ;
if ( ! ( F_40 ( V_84 ) ) )
return;
F_19 ( & V_6 -> V_67 , V_63 ) ;
V_8 = F_6 ( V_27 . V_10 ) ;
V_45 = F_16 ( V_6 ,
V_8 ) ;
if ( ! V_45 ) {
F_22 ( & V_6 -> V_67 , V_63 ) ;
return;
}
if ( F_143 ( V_45 -> V_26 != V_26 ) ) {
V_72 = V_45 -> V_72 ;
V_108 = V_72 -> V_110 ;
F_111 ( V_133 , V_72 ,
L_174 ,
V_45 -> V_26 , V_26 ) ;
V_108 -> V_26 = V_26 ;
V_45 -> V_26 = V_26 ;
if ( V_27 . V_134 &
V_579 ) {
V_45 -> V_66 =
F_9 ( V_27 . V_580 ) ;
memcpy ( & V_45 -> V_65 [ 0 ] ,
& V_27 . V_581 [ 0 ] , 4 ) ;
} else {
V_45 -> V_66 = 0 ;
V_45 -> V_65 [ 0 ] = '\0' ;
}
}
if ( ! ( F_9 ( V_27 . V_134 ) &
V_582 ) ) {
F_13 ( V_33
L_175 ,
V_6 -> V_34 , V_26 ) ;
F_22 ( & V_6 -> V_67 , V_63 ) ;
return;
}
if ( F_214 ( V_6 , V_8 , V_26 ,
V_27 . V_583 ) ) {
F_22 ( & V_6 -> V_67 , V_63 ) ;
return;
}
F_22 ( & V_6 -> V_67 , V_63 ) ;
F_135 ( V_6 , V_8 ) ;
}
static int
F_216 ( struct V_5 * V_6 , T_4 V_26 , T_6 V_584 ,
T_6 V_585 )
{
T_9 V_28 ;
T_8 V_27 ;
T_37 V_534 ;
struct V_44 * V_45 ;
T_10 V_29 ;
T_1 V_8 ;
T_10 V_84 ;
unsigned long V_63 ;
if ( ( F_12 ( V_6 , & V_28 , & V_27 ,
V_32 , V_26 ) ) ) {
F_13 ( V_33 L_2 ,
V_6 -> V_34 , __FILE__ , __LINE__ , V_35 ) ;
return - 1 ;
}
V_29 = F_9 ( V_28 . V_37 ) &
V_38 ;
if ( V_29 != V_39 ) {
F_13 ( V_33 L_2 ,
V_6 -> V_34 , __FILE__ , __LINE__ , V_35 ) ;
return - 1 ;
}
V_84 = F_59 ( V_27 . V_135 ) ;
if ( ! ( F_40 ( V_84 ) ) )
return - 1 ;
V_8 = F_6 ( V_27 . V_10 ) ;
if ( ! ( F_9 ( V_27 . V_134 ) &
V_582 ) ) {
F_13 ( V_33 L_176 ,
V_6 -> V_34 , V_26 ) ;
return - 1 ;
}
if ( F_214 ( V_6 , V_8 , V_26 ,
V_27 . V_583 ) )
return - 1 ;
F_19 ( & V_6 -> V_67 , V_63 ) ;
V_45 = F_16 ( V_6 ,
V_8 ) ;
F_22 ( & V_6 -> V_67 , V_63 ) ;
if ( V_45 )
return - 1 ;
V_45 = F_51 ( sizeof( struct V_44 ) ,
V_120 ) ;
if ( ! V_45 ) {
F_13 ( V_33 L_2 ,
V_6 -> V_34 , __FILE__ , __LINE__ , V_35 ) ;
return 0 ;
}
V_45 -> V_26 = V_26 ;
if ( F_11 ( V_6 ,
F_9 ( V_27 . V_551 ) ,
& V_45 -> V_71 ) != 0 )
F_13 ( V_33 L_2 ,
V_6 -> V_34 , __FILE__ , __LINE__ , V_35 ) ;
V_45 -> V_64 =
F_9 ( V_27 . V_486 ) ;
if ( V_45 -> V_64 != 0 )
V_45 -> V_17 =
F_9 ( V_27 . V_485 ) ;
V_45 -> V_84 = V_84 ;
V_45 -> V_8 = V_8 ;
V_45 -> V_202 = V_27 . V_578 ;
V_45 -> V_128 = ( F_9 ( V_27 . V_134 ) &
V_586 ) ? 1 : 0 ;
if ( V_27 . V_134 & V_579 ) {
V_45 -> V_66 =
F_9 ( V_27 . V_580 ) ;
memcpy ( & V_45 -> V_65 [ 0 ] ,
& V_27 . V_581 [ 0 ] , 4 ) ;
} else {
V_45 -> V_66 = 0 ;
V_45 -> V_65 [ 0 ] = '\0' ;
}
if ( V_45 -> V_64 && ! ( F_206 (
V_6 , & V_28 , & V_534 , V_546 ,
V_45 -> V_64 ) ) )
V_45 -> V_13 =
F_6 ( V_534 . V_15 ) ;
V_45 -> V_11 = F_6 ( V_27 . V_12 ) ;
if ( V_6 -> V_587 )
F_31 ( V_6 , V_45 ) ;
else
F_26 ( V_6 , V_45 ) ;
return 0 ;
}
static void
F_24 ( struct V_5 * V_6 ,
struct V_44 * V_45 )
{
struct V_107 * V_108 ;
if ( ( V_6 -> V_491 -> V_492 == V_493 ) &&
( V_45 -> V_484 ) ) {
F_185 ( V_6 , V_45 ) ;
V_45 -> V_484 = 0 ;
}
F_27 ( V_6 , F_3 ( V_33
L_177 ,
V_6 -> V_34 , V_35 ,
V_45 -> V_26 , ( unsigned long long )
V_45 -> V_8 ) ) ;
if ( V_45 -> V_64 != 0 )
F_27 ( V_6 , F_3 ( V_33
L_178 ,
V_6 -> V_34 , V_35 ,
( unsigned long long ) V_45 -> V_13 ,
V_45 -> V_17 ) ) ;
if ( V_45 -> V_65 [ 0 ] != '\0' )
F_27 ( V_6 , F_3 ( V_33
L_179 ,
V_6 -> V_34 , V_35 ,
V_45 -> V_66 ,
V_45 -> V_65 ) ) ;
if ( V_45 -> V_72 && V_45 -> V_72 -> V_110 ) {
V_108 = V_45 -> V_72 -> V_110 ;
V_108 -> V_321 = 1 ;
F_135 ( V_6 , V_45 -> V_8 ) ;
V_108 -> V_26 =
V_122 ;
}
F_30 ( V_6 ,
V_45 -> V_8 ,
V_45 -> V_71 ) ;
F_3 ( V_33
L_7 ,
V_6 -> V_34 , V_45 -> V_26 ,
( unsigned long long ) V_45 -> V_8 ) ;
if ( V_45 -> V_64 != 0 )
F_3 ( V_33
L_180 ,
V_6 -> V_34 ,
( unsigned long long ) V_45 -> V_13 ,
V_45 -> V_17 ) ;
if ( V_45 -> V_65 [ 0 ] != '\0' )
F_3 ( V_33
L_9 ,
V_6 -> V_34 , V_45 -> V_66 ,
V_45 -> V_65 ) ;
F_27 ( V_6 , F_3 ( V_33
L_181 ,
V_6 -> V_34 , V_35 ,
V_45 -> V_26 , ( unsigned long long )
V_45 -> V_8 ) ) ;
if ( V_45 -> V_64 != 0 )
F_27 ( V_6 , F_3 ( V_33
L_182 ,
V_6 -> V_34 , V_35 ,
( unsigned long long ) V_45 -> V_13 ,
V_45 -> V_17 ) ) ;
if ( V_45 -> V_65 [ 0 ] != '\0' )
F_27 ( V_6 , F_3 ( V_33
L_183 ,
V_6 -> V_34 , V_35 , V_45 -> V_66 ,
V_45 -> V_65 ) ) ;
F_21 ( V_45 ) ;
}
static void
F_217 ( struct V_5 * V_6 ,
T_19 * V_289 )
{
int V_94 ;
T_4 V_26 ;
T_4 V_311 ;
T_6 V_577 ;
char * V_588 = NULL ;
T_6 V_526 , V_589 ;
switch ( V_289 -> V_337 ) {
case V_344 :
V_588 = L_184 ;
break;
case V_341 :
V_588 = L_185 ;
break;
case V_340 :
case 0 :
V_588 = L_186 ;
break;
case V_338 :
V_588 = L_187 ;
break;
default:
V_588 = L_188 ;
break;
}
F_3 ( V_33 L_189 ,
V_6 -> V_34 , V_588 ) ;
F_3 ( L_190 \
L_191 ,
F_9 ( V_289 -> V_336 ) ,
F_9 ( V_289 -> V_486 ) ,
V_289 -> V_590 , V_289 -> V_312 ) ;
for ( V_94 = 0 ; V_94 < V_289 -> V_312 ; V_94 ++ ) {
V_26 = F_9 ( V_289 -> V_313 [ V_94 ] . V_314 ) ;
if ( ! V_26 )
continue;
V_577 = V_289 -> V_590 + V_94 ;
V_311 = V_289 -> V_313 [ V_94 ] . V_315 &
V_316 ;
switch ( V_311 ) {
case V_591 :
V_588 = L_192 ;
break;
case V_335 :
V_588 = L_193 ;
break;
case V_317 :
V_588 = L_194 ;
break;
case V_592 :
V_588 = L_195 ;
break;
case V_593 :
V_588 = L_196 ;
break;
default:
V_588 = L_43 ;
break;
}
V_526 = V_289 -> V_313 [ V_94 ] . V_594 >> 4 ;
V_589 = V_289 -> V_313 [ V_94 ] . V_594 & 0xF ;
F_3 ( L_197 \
L_198 , V_577 ,
V_26 , V_588 , V_526 , V_589 ) ;
}
}
static int
F_218 ( struct V_5 * V_6 ,
struct V_281 * V_282 )
{
int V_94 ;
T_4 V_549 , V_26 ;
T_4 V_311 ;
T_6 V_577 , V_595 ;
struct V_80 * V_81 ;
T_1 V_8 ;
unsigned long V_63 ;
T_6 V_526 , V_589 ;
T_19 * V_289 =
( T_19 * )
V_282 -> V_289 ;
#ifdef F_173
if ( V_6 -> V_7 & V_596 )
F_217 ( V_6 , V_289 ) ;
#endif
if ( V_6 -> V_69 || V_6 -> V_245 || V_6 -> V_246 )
return 0 ;
if ( ! V_6 -> V_30 . V_31 )
F_200 ( V_6 ) ;
else
F_197 ( V_6 ) ;
if ( V_282 -> V_343 ) {
F_27 ( V_6 , F_3 ( V_33
L_199 , V_6 -> V_34 ) ) ;
return 0 ;
}
V_549 = F_9 ( V_289 -> V_336 ) ;
if ( V_289 -> V_337 == V_344 )
if ( F_207 ( V_6 , V_549 ) != 0 )
return 0 ;
F_19 ( & V_6 -> V_82 , V_63 ) ;
V_81 = F_37 ( V_6 ,
V_549 ) ;
if ( V_81 ) {
V_8 = V_81 -> V_8 ;
V_595 = V_81 -> V_31 ;
} else if ( V_549 < V_6 -> V_30 . V_31 ) {
V_8 = V_6 -> V_30 . V_8 ;
V_595 = V_6 -> V_30 . V_31 ;
} else {
F_22 ( & V_6 -> V_82 , V_63 ) ;
return 0 ;
}
F_22 ( & V_6 -> V_82 , V_63 ) ;
for ( V_94 = 0 ; V_94 < V_289 -> V_312 ; V_94 ++ ) {
if ( V_282 -> V_343 ) {
F_27 ( V_6 , F_3 ( V_33
L_199 , V_6 -> V_34 ) ) ;
return 0 ;
}
if ( V_6 -> V_245 || V_6 -> V_246 )
return 0 ;
V_577 = V_289 -> V_590 + V_94 ;
if ( V_577 >= V_595 )
continue;
V_311 = V_289 -> V_313 [ V_94 ] . V_315 &
V_316 ;
if ( ( V_289 -> V_313 [ V_94 ] . V_315 &
V_597 ) && ( V_311 !=
V_335 ) )
continue;
V_26 = F_9 ( V_289 -> V_313 [ V_94 ] . V_314 ) ;
if ( ! V_26 )
continue;
V_526 = V_289 -> V_313 [ V_94 ] . V_594 >> 4 ;
V_589 = V_289 -> V_313 [ V_94 ] . V_594 & 0xF ;
switch ( V_311 ) {
case V_592 :
if ( V_6 -> V_69 )
break;
if ( V_526 == V_589 )
break;
F_199 ( V_6 , V_8 ,
V_26 , V_577 , V_526 ) ;
if ( V_526 < V_531 )
break;
F_215 ( V_6 , V_8 , V_26 ,
V_577 , V_526 ) ;
case V_591 :
if ( V_6 -> V_69 )
break;
F_199 ( V_6 , V_8 ,
V_26 , V_577 , V_526 ) ;
F_216 ( V_6 , V_26 , V_577 , 0 ) ;
break;
case V_335 :
F_23 ( V_6 , V_26 ) ;
break;
}
}
if ( V_289 -> V_337 == V_341 &&
V_81 )
F_211 ( V_6 , V_8 ) ;
return 0 ;
}
static void
F_219 ( struct V_5 * V_6 ,
T_32 * V_289 )
{
char * V_598 = NULL ;
switch ( V_289 -> V_351 ) {
case V_499 :
V_598 = L_200 ;
break;
case V_599 :
V_598 = L_201 ;
break;
case V_600 :
V_598 = L_202 ;
break;
case V_601 :
V_598 = L_203 ;
break;
case V_602 :
V_598 = L_204 ;
break;
case V_603 :
V_598 = L_205 ;
break;
case V_604 :
V_598 = L_206 ;
break;
case V_605 :
V_598 = L_207 ;
break;
case V_606 :
V_598 = L_208 ;
break;
case V_607 :
V_598 = L_209 ;
break;
case V_608 :
V_598 = L_210 ;
break;
case V_609 :
V_598 = L_211 ;
break;
case V_610 :
V_598 = L_212 ;
break;
default:
V_598 = L_213 ;
break;
}
F_3 ( V_33 L_214
L_215 ,
V_6 -> V_34 , V_598 , F_9 ( V_289 -> V_184 ) ,
( unsigned long long ) F_6 ( V_289 -> V_10 ) ,
F_9 ( V_289 -> V_474 ) ) ;
if ( V_289 -> V_351 == V_499 )
F_3 ( V_33 L_216 , V_6 -> V_34 ,
V_289 -> V_500 , V_289 -> V_611 ) ;
F_3 ( L_217 ) ;
}
static void
F_220 ( struct V_5 * V_6 ,
struct V_281 * V_282 )
{
struct V_107 * V_612 ;
struct V_44 * V_45 ;
T_1 V_8 ;
unsigned long V_63 ;
T_32 * V_289 =
( T_32 * )
V_282 -> V_289 ;
#ifdef F_173
if ( V_6 -> V_7 & V_596 )
F_219 ( V_6 ,
V_289 ) ;
#endif
if ( ( V_6 -> V_186 . V_613 >> 8 ) < 0xC )
return;
if ( V_289 -> V_351 !=
V_600 &&
V_289 -> V_351 !=
V_606 )
return;
F_19 ( & V_6 -> V_67 , V_63 ) ;
V_8 = F_6 ( V_289 -> V_10 ) ;
V_45 = F_16 ( V_6 ,
V_8 ) ;
if ( ! V_45 || ! V_45 -> V_72 ) {
F_22 ( & V_6 -> V_67 , V_63 ) ;
return;
}
V_612 = V_45 -> V_72 -> V_110 ;
if ( ! V_612 ) {
F_22 ( & V_6 -> V_67 , V_63 ) ;
return;
}
if ( V_289 -> V_351 ==
V_600 )
V_612 -> V_231 = 1 ;
else
V_612 -> V_231 = 0 ;
F_22 ( & V_6 -> V_67 , V_63 ) ;
}
static void
F_221 ( struct V_5 * V_6 ,
T_40 * V_289 )
{
char * V_598 = NULL ;
switch ( V_289 -> V_351 ) {
case V_614 :
V_598 = L_218 ;
break;
case V_615 :
V_598 = L_219 ;
break;
default:
V_598 = L_213 ;
break;
}
F_3 ( V_33 L_220
L_221
L_222 , V_6 -> V_34 , V_598 ,
F_9 ( V_289 -> V_486 ) ,
( unsigned long long ) F_6 ( V_289 -> V_15 ) ,
F_9 ( V_289 -> V_616 ) ) ;
}
static void
F_222 ( struct V_5 * V_6 ,
struct V_281 * V_282 )
{
#ifdef F_173
if ( V_6 -> V_7 & V_596 )
F_221 ( V_6 ,
( T_40 * )
V_282 -> V_289 ) ;
#endif
}
static void
F_223 ( struct V_5 * V_6 ,
struct V_281 * V_282 )
{
struct V_89 * V_92 ;
struct V_98 * V_99 ;
T_4 V_90 , V_26 ;
T_10 V_97 ;
struct V_105 * V_106 ;
T_10 V_617 ;
T_10 V_618 ;
T_18 * V_28 ;
T_41 * V_289 =
( T_41 * )
V_282 -> V_289 ;
T_4 V_29 ;
unsigned long V_63 ;
int V_76 ;
T_6 V_619 = 0 ;
T_6 V_620 ;
F_93 ( & V_6 -> V_222 . V_242 ) ;
F_3 ( V_33
L_223 ,
V_6 -> V_34 , V_35 , V_289 -> V_578 ,
V_289 -> V_621 ) ;
F_136 ( V_6 ) ;
F_19 ( & V_6 -> V_93 , V_63 ) ;
V_28 = V_6 -> V_222 . V_221 ;
V_622:
if ( V_619 ++ == 5 ) {
F_27 ( V_6 , F_3 ( V_33 L_224 ,
V_6 -> V_34 , V_35 ) ) ;
goto V_77;
} else if ( V_619 > 1 )
F_27 ( V_6 , F_3 ( V_33 L_225 ,
V_6 -> V_34 , V_35 , V_619 - 1 ) ) ;
V_617 = 0 ;
V_618 = 0 ;
for ( V_90 = 1 ; V_90 <= V_6 -> V_95 ; V_90 ++ ) {
if ( V_6 -> V_69 )
goto V_77;
V_92 = F_41 ( V_6 , V_90 ) ;
if ( ! V_92 )
continue;
V_99 = V_92 -> V_42 ;
V_106 = V_99 -> V_110 ;
if ( ! V_106 || ! V_106 -> V_112 )
continue;
if ( V_106 -> V_112 -> V_63 &
V_127 )
continue;
if ( V_106 -> V_112 -> V_63 &
V_113 )
continue;
V_26 = V_106 -> V_112 -> V_26 ;
V_97 = V_106 -> V_97 ;
V_618 ++ ;
if ( V_6 -> V_69 )
goto V_77;
F_22 ( & V_6 -> V_93 , V_63 ) ;
V_76 = F_92 ( V_6 , V_26 , 0 , 0 , V_97 ,
V_272 , V_90 , 30 ,
V_623 ) ;
if ( V_76 == V_243 ) {
F_56 ( V_299 , V_99 ,
L_226
L_227 , V_92 ) ;
F_19 ( & V_6 -> V_93 , V_63 ) ;
goto V_622;
}
V_29 = F_9 ( V_28 -> V_37 )
& V_38 ;
if ( V_29 != V_39 ) {
F_56 ( V_299 , V_99 ,
L_228 ,
V_29 , V_92 ) ;
F_19 ( & V_6 -> V_93 , V_63 ) ;
goto V_622;
}
if ( V_28 -> V_268 ==
V_217 ||
V_28 -> V_268 ==
V_219 ) {
F_19 ( & V_6 -> V_93 , V_63 ) ;
continue;
}
V_620 = 0 ;
V_624:
if ( V_620 ++ == 60 ) {
F_27 ( V_6 , F_3 ( V_33
L_229 , V_6 -> V_34 ,
V_35 ) ) ;
F_19 ( & V_6 -> V_93 , V_63 ) ;
goto V_622;
}
if ( V_6 -> V_69 )
goto V_625;
V_76 = F_92 ( V_6 , V_26 , V_99 -> V_75 , V_99 -> V_74 ,
V_99 -> V_97 , V_255 , V_90 , 30 ,
V_623 ) ;
if ( V_76 == V_243 ) {
F_56 ( V_299 , V_99 ,
L_230
L_231 , V_92 ) ;
goto V_624;
}
if ( V_620 > 1 )
F_56 ( V_299 , V_99 ,
L_232
L_233 ,
V_620 - 1 , V_92 ) ;
V_617 += F_59 ( V_28 -> V_266 ) ;
F_19 ( & V_6 -> V_93 , V_63 ) ;
}
if ( V_6 -> V_626 ) {
F_27 ( V_6 , F_3 ( V_33
L_234 ,
V_6 -> V_34 , V_35 ) ) ;
V_6 -> V_626 = 0 ;
goto V_622;
}
V_77:
F_22 ( & V_6 -> V_93 , V_63 ) ;
V_625:
F_27 ( V_6 , F_3 ( V_33
L_235 ,
V_6 -> V_34 , V_35 , V_618 , V_617 ) ) ;
V_6 -> V_627 = 0 ;
if ( ! V_6 -> V_69 )
F_134 ( V_6 ) ;
F_108 ( & V_6 -> V_222 . V_242 ) ;
}
static void
F_224 ( struct V_5 * V_6 ,
struct V_281 * V_282 )
{
T_42 * V_289 =
( T_42 * ) V_282 -> V_289 ;
#ifdef F_173
if ( V_6 -> V_7 & V_596 ) {
F_3 ( V_33 L_236 , V_6 -> V_34 ,
( V_289 -> V_351 == V_628 ) ?
L_237 : L_238 ) ;
if ( V_289 -> V_629 )
F_3 ( L_239 ,
F_59 ( V_289 -> V_629 ) ) ;
F_3 ( L_217 ) ;
}
#endif
if ( V_289 -> V_351 == V_628 &&
! V_6 -> V_30 . V_31 ) {
if ( V_630 > 0 && V_6 -> V_69 ) {
while ( V_6 -> V_69 )
F_225 ( 1 ) ;
}
F_200 ( V_6 ) ;
}
}
static int
F_226 ( struct V_5 * V_6 , T_4 V_26 , T_6 V_631 )
{
T_43 * V_237 ;
T_44 * V_28 ;
T_4 V_90 ;
T_6 V_632 = 0 ;
int V_19 = 0 ;
T_4 V_29 ;
T_10 V_443 ;
F_93 ( & V_6 -> V_555 . V_242 ) ;
if ( V_6 -> V_555 . V_223 != V_224 ) {
F_13 ( V_33 L_240 ,
V_6 -> V_34 , V_35 ) ;
V_19 = - V_633 ;
goto V_77;
}
V_6 -> V_555 . V_223 = V_228 ;
V_90 = F_144 ( V_6 , V_6 -> V_634 ) ;
if ( ! V_90 ) {
F_13 ( V_33 L_48 ,
V_6 -> V_34 , V_35 ) ;
V_6 -> V_555 . V_223 = V_224 ;
V_19 = - V_633 ;
goto V_77;
}
V_237 = F_100 ( V_6 , V_90 ) ;
V_6 -> V_555 . V_90 = V_90 ;
memset ( V_237 , 0 , sizeof( T_43 ) ) ;
V_237 -> V_256 = V_635 ;
V_237 -> V_479 = V_636 ;
V_237 -> V_183 = V_631 ;
F_27 ( V_6 , F_3 ( V_33 L_241\
L_242 , V_6 -> V_34 ,
V_26 , V_631 ) ) ;
F_103 ( & V_6 -> V_555 . V_229 ) ;
F_145 ( V_6 , V_90 ) ;
F_105 ( & V_6 -> V_555 . V_229 , 10 * V_262 ) ;
if ( ! ( V_6 -> V_555 . V_223 & V_225 ) ) {
F_13 ( V_33 L_50 ,
V_6 -> V_34 , V_35 ) ;
if ( ! ( V_6 -> V_555 . V_223 & V_263 ) )
V_632 = 1 ;
V_19 = - V_637 ;
goto V_77;
}
if ( V_6 -> V_555 . V_223 & V_227 ) {
V_28 = V_6 -> V_555 . V_221 ;
V_29 = F_9 ( V_28 -> V_37 ) ;
if ( V_29 & V_504 )
V_443 = F_59 ( V_28 -> V_265 ) ;
else
V_443 = 0 ;
V_29 &= V_38 ;
if ( V_29 != V_39 ) {
F_27 ( V_6 , F_3 ( V_33
L_243
L_244 , V_6 -> V_34 , V_29 ,
V_443 ) ) ;
V_19 = - V_637 ;
} else
F_27 ( V_6 , F_3 ( V_33
L_245 ,
V_6 -> V_34 ) ) ;
}
V_77:
V_6 -> V_555 . V_223 = V_224 ;
F_108 ( & V_6 -> V_555 . V_242 ) ;
if ( V_632 )
F_96 ( V_6 , V_248 ,
V_249 ) ;
return V_19 ;
}
static void
F_227 ( struct V_98 * V_99 , void * V_132 )
{
int V_19 ;
V_99 -> V_132 = V_132 ? 1 : 0 ;
F_56 ( V_133 , V_99 , L_246 ,
V_99 -> V_132 ? L_247 : L_248 ) ;
V_19 = F_228 ( V_99 ) ;
}
static void
F_229 ( struct V_5 * V_6 ,
T_23 * V_347 )
{
struct V_46 * V_47 ;
unsigned long V_63 ;
T_1 V_51 ;
T_4 V_26 = F_9 ( V_347 -> V_354 ) ;
int V_19 ;
F_80 ( V_6 , V_26 , & V_51 ) ;
if ( ! V_51 ) {
F_13 ( V_33
L_2 , V_6 -> V_34 ,
__FILE__ , __LINE__ , V_35 ) ;
return;
}
F_19 ( & V_6 -> V_78 , V_63 ) ;
V_47 = F_34 ( V_6 , V_51 ) ;
F_22 ( & V_6 -> V_78 , V_63 ) ;
if ( V_47 )
return;
V_47 = F_51 ( sizeof( struct V_46 ) , V_120 ) ;
if ( ! V_47 ) {
F_13 ( V_33
L_2 , V_6 -> V_34 ,
__FILE__ , __LINE__ , V_35 ) ;
return;
}
V_47 -> V_74 = V_6 -> V_638 ++ ;
V_47 -> V_75 = V_123 ;
V_47 -> V_26 = V_26 ;
V_47 -> V_51 = V_51 ;
F_35 ( V_6 , V_47 ) ;
if ( ! V_6 -> V_587 ) {
V_19 = F_230 ( V_6 -> V_102 , V_123 ,
V_47 -> V_74 , 0 ) ;
if ( V_19 )
F_36 ( V_6 , V_47 ) ;
} else {
F_19 ( & V_6 -> V_78 , V_63 ) ;
F_14 ( V_6 , V_47 , 1 ) ;
F_22 ( & V_6 -> V_78 , V_63 ) ;
}
}
static void
F_231 ( struct V_5 * V_6 , T_4 V_26 )
{
struct V_46 * V_47 ;
unsigned long V_63 ;
struct V_107 * V_108 ;
struct V_116 * V_72 = NULL ;
F_19 ( & V_6 -> V_78 , V_63 ) ;
V_47 = F_33 ( V_6 , V_26 ) ;
if ( V_47 ) {
if ( V_47 -> V_72 ) {
V_72 = V_47 -> V_72 ;
V_108 = V_72 -> V_110 ;
V_108 -> V_321 = 1 ;
}
F_3 ( V_33 L_249 ,
V_6 -> V_34 , V_47 -> V_26 ,
( unsigned long long ) V_47 -> V_51 ) ;
F_20 ( & V_47 -> V_68 ) ;
F_21 ( V_47 ) ;
}
F_22 ( & V_6 -> V_78 , V_63 ) ;
if ( V_72 )
F_232 ( & V_72 -> V_117 ) ;
}
static void
F_233 ( struct V_5 * V_6 ,
T_23 * V_347 )
{
struct V_44 * V_45 ;
struct V_116 * V_72 = NULL ;
struct V_107 * V_108 ;
unsigned long V_63 ;
T_4 V_26 = F_9 ( V_347 -> V_356 ) ;
F_19 ( & V_6 -> V_67 , V_63 ) ;
V_45 = F_17 ( V_6 , V_26 ) ;
if ( V_45 ) {
V_45 -> V_192 = 0 ;
V_45 -> V_193 = 0 ;
F_159 ( V_26 , V_6 -> V_126 ) ;
if ( V_45 -> V_72 && V_45 -> V_72 -> V_110 ) {
V_72 = V_45 -> V_72 ;
V_108 = V_72 -> V_110 ;
V_108 -> V_63 &=
~ V_127 ;
}
}
F_22 ( & V_6 -> V_67 , V_63 ) ;
if ( ! V_45 )
return;
if ( V_72 )
F_234 ( V_72 , NULL , F_227 ) ;
}
static void
F_235 ( struct V_5 * V_6 ,
T_23 * V_347 )
{
struct V_44 * V_45 ;
struct V_116 * V_72 = NULL ;
struct V_107 * V_108 ;
unsigned long V_63 ;
T_4 V_26 = F_9 ( V_347 -> V_356 ) ;
T_4 V_192 = 0 ;
T_1 V_193 = 0 ;
F_79 ( V_6 , V_26 , & V_192 ) ;
if ( V_192 )
F_80 ( V_6 , V_192 ,
& V_193 ) ;
F_19 ( & V_6 -> V_67 , V_63 ) ;
V_45 = F_17 ( V_6 , V_26 ) ;
if ( V_45 ) {
F_139 ( V_26 , V_6 -> V_126 ) ;
if ( V_45 -> V_72 && V_45 -> V_72 -> V_110 ) {
V_72 = V_45 -> V_72 ;
V_108 = V_72 -> V_110 ;
V_108 -> V_63 |=
V_127 ;
V_45 -> V_192 = V_192 ;
V_45 -> V_193 = V_193 ;
}
}
F_22 ( & V_6 -> V_67 , V_63 ) ;
if ( ! V_45 )
return;
F_226 ( V_6 , V_26 , V_347 -> V_183 ) ;
if ( V_72 )
F_234 ( V_72 , ( void * ) 1 , F_227 ) ;
}
static void
F_236 ( struct V_5 * V_6 ,
T_23 * V_347 )
{
T_4 V_26 = F_9 ( V_347 -> V_356 ) ;
F_23 ( V_6 , V_26 ) ;
}
static void
F_237 ( struct V_5 * V_6 ,
T_23 * V_347 )
{
struct V_44 * V_45 ;
unsigned long V_63 ;
T_4 V_26 = F_9 ( V_347 -> V_356 ) ;
T_9 V_28 ;
T_8 V_27 ;
T_10 V_29 ;
T_1 V_8 ;
T_4 V_549 ;
F_139 ( V_26 , V_6 -> V_126 ) ;
F_19 ( & V_6 -> V_67 , V_63 ) ;
V_45 = F_17 ( V_6 , V_26 ) ;
F_22 ( & V_6 -> V_67 , V_63 ) ;
if ( V_45 ) {
F_226 ( V_6 , V_26 , V_347 -> V_183 ) ;
return;
}
if ( ( F_12 ( V_6 , & V_28 , & V_27 ,
V_32 , V_26 ) ) ) {
F_13 ( V_33 L_2 ,
V_6 -> V_34 , __FILE__ , __LINE__ , V_35 ) ;
return;
}
V_29 = F_9 ( V_28 . V_37 ) &
V_38 ;
if ( V_29 != V_39 ) {
F_13 ( V_33 L_2 ,
V_6 -> V_34 , __FILE__ , __LINE__ , V_35 ) ;
return;
}
V_549 = F_9 ( V_27 . V_551 ) ;
if ( ! F_11 ( V_6 , V_549 , & V_8 ) )
F_199 ( V_6 , V_8 , V_26 ,
V_27 . V_578 , V_531 ) ;
F_226 ( V_6 , V_26 , V_347 -> V_183 ) ;
F_216 ( V_6 , V_26 , 0 , 1 ) ;
}
static void
F_238 ( struct V_5 * V_6 ,
T_22 * V_289 )
{
T_23 * V_347 ;
T_6 V_639 ;
int V_94 ;
char * V_598 = NULL , * V_640 = NULL ;
V_347 = ( T_23 * ) & V_289 -> V_348 [ 0 ] ;
F_3 ( V_33 L_250 ,
V_6 -> V_34 , ( F_59 ( V_289 -> V_134 ) &
V_350 ) ?
L_251 : L_252 , V_289 -> V_349 ) ;
for ( V_94 = 0 ; V_94 < V_289 -> V_349 ; V_94 ++ , V_347 ++ ) {
switch ( V_347 -> V_351 ) {
case V_641 :
V_598 = L_184 ;
break;
case V_353 :
V_598 = L_185 ;
break;
case V_642 :
V_598 = L_253 ;
break;
case V_643 :
V_598 = L_254 ;
break;
case V_355 :
V_598 = L_255 ;
break;
case V_644 :
V_598 = L_256 ;
break;
case V_352 :
V_598 = L_257 ;
break;
case V_645 :
V_598 = L_258 ;
break;
case V_646 :
V_598 = L_259 ;
break;
default:
V_598 = L_213 ;
break;
}
V_639 = F_9 ( V_347 -> V_647 ) &
V_648 ;
switch ( V_639 ) {
case V_649 :
V_640 = L_53 ;
break;
case V_650 :
V_640 = L_260 ;
break;
case V_651 :
V_640 = L_261 ;
break;
default:
V_640 = L_262 ;
break;
}
F_3 ( L_263 \
L_264 , V_640 ,
V_598 , F_9 ( V_347 -> V_354 ) ,
F_9 ( V_347 -> V_356 ) ,
V_347 -> V_183 ) ;
}
}
static void
F_239 ( struct V_5 * V_6 ,
struct V_281 * V_282 )
{
T_23 * V_347 ;
int V_94 ;
T_6 V_652 ;
T_22 * V_289 =
( T_22 * )
V_282 -> V_289 ;
#ifdef F_173
if ( V_6 -> V_7 & V_596 )
F_238 ( V_6 , V_289 ) ;
#endif
V_652 = ( F_59 ( V_289 -> V_134 ) &
V_350 ) ? 1 : 0 ;
V_347 = ( T_23 * ) & V_289 -> V_348 [ 0 ] ;
if ( V_6 -> V_69 ) {
for ( V_94 = 0 ; V_94 < V_289 -> V_349 ; V_94 ++ , V_347 ++ ) {
if ( V_347 -> V_351 == V_643 )
F_226 ( V_6 ,
F_9 ( V_347 -> V_356 ) ,
V_347 -> V_183 ) ;
}
return;
}
for ( V_94 = 0 ; V_94 < V_289 -> V_349 ; V_94 ++ , V_347 ++ ) {
switch ( V_347 -> V_351 ) {
case V_644 :
case V_641 :
if ( ! V_652 )
F_229 ( V_6 , V_347 ) ;
break;
case V_352 :
case V_353 :
if ( ! V_652 )
F_231 ( V_6 ,
F_9 ( V_347 -> V_354 ) ) ;
break;
case V_645 :
F_235 ( V_6 , V_347 ) ;
break;
case V_646 :
F_233 ( V_6 , V_347 ) ;
break;
case V_643 :
F_237 ( V_6 , V_347 ) ;
break;
case V_355 :
F_236 ( V_6 , V_347 ) ;
break;
}
}
}
static void
F_240 ( struct V_5 * V_6 ,
struct V_281 * V_282 )
{
T_1 V_51 ;
unsigned long V_63 ;
struct V_46 * V_47 ;
T_4 V_26 ;
T_10 V_151 ;
int V_19 ;
T_24 * V_289 =
( T_24 * ) V_282 -> V_289 ;
if ( V_6 -> V_69 )
return;
if ( V_289 -> V_351 != V_357 )
return;
V_26 = F_9 ( V_289 -> V_354 ) ;
V_151 = F_59 ( V_289 -> V_358 ) ;
F_27 ( V_6 , F_3 ( V_33
L_265 ,
V_6 -> V_34 , V_35 , V_26 ,
F_59 ( V_289 -> V_653 ) , V_151 ) ) ;
switch ( V_151 ) {
case V_161 :
case V_160 :
F_231 ( V_6 , V_26 ) ;
break;
case V_156 :
case V_158 :
case V_155 :
F_19 ( & V_6 -> V_78 , V_63 ) ;
V_47 = F_33 ( V_6 , V_26 ) ;
F_22 ( & V_6 -> V_78 , V_63 ) ;
if ( V_47 )
break;
F_80 ( V_6 , V_26 , & V_51 ) ;
if ( ! V_51 ) {
F_13 ( V_33
L_2 , V_6 -> V_34 ,
__FILE__ , __LINE__ , V_35 ) ;
break;
}
V_47 = F_51 ( sizeof( struct V_46 ) , V_120 ) ;
if ( ! V_47 ) {
F_13 ( V_33
L_2 , V_6 -> V_34 ,
__FILE__ , __LINE__ , V_35 ) ;
break;
}
V_47 -> V_74 = V_6 -> V_638 ++ ;
V_47 -> V_75 = V_123 ;
V_47 -> V_26 = V_26 ;
V_47 -> V_51 = V_51 ;
F_35 ( V_6 , V_47 ) ;
V_19 = F_230 ( V_6 -> V_102 , V_123 ,
V_47 -> V_74 , 0 ) ;
if ( V_19 )
F_36 ( V_6 , V_47 ) ;
break;
case V_654 :
default:
break;
}
}
static void
F_241 ( struct V_5 * V_6 ,
struct V_281 * V_282 )
{
T_4 V_26 , V_549 ;
T_10 V_151 ;
struct V_44 * V_45 ;
unsigned long V_63 ;
T_9 V_28 ;
T_8 V_27 ;
T_10 V_29 ;
T_45 * V_289 =
( T_45 * ) V_282 -> V_289 ;
T_1 V_8 ;
if ( V_6 -> V_69 )
return;
if ( V_289 -> V_351 != V_655 )
return;
V_26 = F_9 ( V_289 -> V_356 ) ;
V_151 = F_59 ( V_289 -> V_358 ) ;
F_27 ( V_6 , F_3 ( V_33
L_265 ,
V_6 -> V_34 , V_35 , V_26 ,
F_59 ( V_289 -> V_653 ) , V_151 ) ) ;
switch ( V_151 ) {
case V_656 :
case V_657 :
case V_658 :
case V_659 :
case V_660 :
F_139 ( V_26 , V_6 -> V_126 ) ;
F_19 ( & V_6 -> V_67 , V_63 ) ;
V_45 = F_17 ( V_6 , V_26 ) ;
F_22 ( & V_6 -> V_67 , V_63 ) ;
if ( V_45 )
return;
if ( ( F_12 ( V_6 , & V_28 ,
& V_27 , V_32 ,
V_26 ) ) ) {
F_13 ( V_33 L_2 ,
V_6 -> V_34 , __FILE__ , __LINE__ , V_35 ) ;
return;
}
V_29 = F_9 ( V_28 . V_37 ) &
V_38 ;
if ( V_29 != V_39 ) {
F_13 ( V_33 L_2 ,
V_6 -> V_34 , __FILE__ , __LINE__ , V_35 ) ;
return;
}
V_549 = F_9 ( V_27 . V_551 ) ;
if ( ! F_11 ( V_6 , V_549 , & V_8 ) )
F_199 ( V_6 , V_8 , V_26 ,
V_27 . V_578 , V_531 ) ;
F_216 ( V_6 , V_26 , 0 , 1 ) ;
break;
case V_661 :
case V_662 :
case V_663 :
default:
break;
}
}
static void
F_242 ( struct V_5 * V_6 ,
T_46 * V_289 )
{
char * V_598 = NULL ;
switch ( V_289 -> V_664 ) {
case V_665 :
V_598 = L_266 ;
break;
case V_666 :
V_598 = L_267 ;
break;
case V_667 :
V_598 = L_268 ;
break;
case V_668 :
V_598 = L_269 ;
break;
case V_669 :
V_598 = L_270 ;
break;
}
if ( ! V_598 )
return;
F_3 ( V_33 L_271 \
L_272 ,
V_6 -> V_34 , V_598 ,
F_9 ( V_289 -> V_354 ) ,
V_289 -> V_670 ) ;
}
static void
F_243 ( struct V_5 * V_6 ,
struct V_281 * V_282 )
{
T_46 * V_289 =
( T_46 * )
V_282 -> V_289 ;
static struct V_46 * V_47 ;
unsigned long V_63 ;
T_4 V_26 ;
#ifdef F_173
if ( V_6 -> V_7 & V_596 )
F_242 ( V_6 ,
V_289 ) ;
#endif
if ( V_289 -> V_664 == V_665 ) {
F_19 ( & V_6 -> V_78 , V_63 ) ;
V_26 = F_9 ( V_289 -> V_354 ) ;
V_47 = F_33 ( V_6 , V_26 ) ;
if ( V_47 )
V_47 -> V_144 =
V_289 -> V_670 ;
F_22 ( & V_6 -> V_78 , V_63 ) ;
}
}
static void
F_244 ( struct V_5 * V_6 )
{
struct V_105 * V_106 ;
struct V_98 * V_99 ;
F_90 (sdev, ioc->shost) {
V_106 = V_99 -> V_110 ;
if ( V_106 && V_106 -> V_112 )
V_106 -> V_112 -> V_321 = 1 ;
}
}
static void
F_245 ( struct V_5 * V_6 ,
T_8 * V_27 )
{
struct V_107 * V_108 = NULL ;
struct V_116 * V_72 ;
struct V_44 * V_45 ;
unsigned long V_63 ;
F_19 ( & V_6 -> V_67 , V_63 ) ;
F_4 (sas_device, &ioc->sas_device_list, list) {
if ( ( V_45 -> V_8 == V_27 -> V_10 ) &&
( V_45 -> V_17 == V_27 -> V_485 ) ) {
V_45 -> V_671 = 1 ;
V_72 = V_45 -> V_72 ;
if ( V_72 && V_72 -> V_110 ) {
V_108 = V_72 -> V_110 ;
V_108 -> V_231 = 0 ;
V_108 -> V_321 = 0 ;
} else
V_108 = NULL ;
if ( V_72 ) {
F_111 ( V_133 , V_72 ,
L_273 ,
V_27 -> V_184 ,
( unsigned long long )
V_45 -> V_8 ) ;
if ( V_45 -> V_64 != 0 )
F_111 ( V_133 , V_72 ,
L_274
L_89 ,
( unsigned long long )
V_45 -> V_13 ,
V_45 -> V_17 ) ;
}
if ( V_27 -> V_134 &
V_579 ) {
V_45 -> V_66 =
F_9 ( V_27 -> V_580 ) ;
memcpy ( & V_45 -> V_65 [ 0 ] ,
& V_27 -> V_581 [ 0 ] , 4 ) ;
} else {
V_45 -> V_66 = 0 ;
V_45 -> V_65 [ 0 ] = '\0' ;
}
if ( V_45 -> V_26 == V_27 -> V_184 )
goto V_77;
F_3 ( L_275 ,
V_45 -> V_26 ) ;
V_45 -> V_26 = V_27 -> V_184 ;
if ( V_108 )
V_108 -> V_26 =
V_27 -> V_184 ;
goto V_77;
}
}
V_77:
F_22 ( & V_6 -> V_67 , V_63 ) ;
}
static void
F_246 ( struct V_5 * V_6 )
{
T_8 V_27 ;
T_9 V_28 ;
T_4 V_29 ;
T_4 V_26 ;
T_10 V_84 ;
F_3 ( V_33 L_276 , V_6 -> V_34 ) ;
if ( F_126 ( & V_6 -> V_70 ) )
goto V_77;
V_26 = 0xFFFF ;
while ( ! ( F_12 ( V_6 , & V_28 ,
& V_27 , V_672 ,
V_26 ) ) ) {
V_29 = F_9 ( V_28 . V_37 ) &
V_38 ;
if ( V_29 != V_39 )
break;
V_26 = V_27 . V_184 =
F_9 ( V_27 . V_184 ) ;
V_84 = F_59 ( V_27 . V_135 ) ;
if ( ! ( F_40 ( V_84 ) ) )
continue;
V_27 . V_10 =
F_6 ( V_27 . V_10 ) ;
V_27 . V_485 = F_9 ( V_27 . V_485 ) ;
F_245 ( V_6 , & V_27 ) ;
}
V_77:
F_3 ( V_33 L_277 ,
V_6 -> V_34 ) ;
}
static void
F_247 ( struct V_5 * V_6 , T_1 V_51 ,
T_4 V_26 )
{
struct V_107 * V_108 ;
struct V_116 * V_72 ;
struct V_46 * V_47 ;
unsigned long V_63 ;
F_19 ( & V_6 -> V_78 , V_63 ) ;
F_4 (raid_device, &ioc->raid_device_list, list) {
if ( V_47 -> V_51 == V_51 && V_47 -> V_72 ) {
V_72 = V_47 -> V_72 ;
if ( V_72 && V_72 -> V_110 ) {
V_108 = V_72 -> V_110 ;
V_108 -> V_321 = 0 ;
} else
V_108 = NULL ;
V_47 -> V_671 = 1 ;
F_22 ( & V_6 -> V_78 , V_63 ) ;
F_111 ( V_133 , V_47 -> V_72 ,
L_278 , V_26 ,
( unsigned long long ) V_47 -> V_51 ) ;
F_19 ( & V_6 -> V_78 , V_63 ) ;
if ( V_47 -> V_26 == V_26 ) {
F_22 ( & V_6 -> V_78 ,
V_63 ) ;
return;
}
F_3 ( L_275 ,
V_47 -> V_26 ) ;
V_47 -> V_26 = V_26 ;
if ( V_108 )
V_108 -> V_26 = V_26 ;
F_22 ( & V_6 -> V_78 , V_63 ) ;
return;
}
}
F_22 ( & V_6 -> V_78 , V_63 ) ;
}
static void
F_248 ( struct V_5 * V_6 )
{
T_47 V_673 ;
T_11 V_674 ;
T_12 V_176 ;
T_9 V_28 ;
T_4 V_29 ;
T_4 V_26 ;
T_6 V_631 ;
if ( ! V_6 -> V_675 )
return;
F_3 ( V_33 L_279 ,
V_6 -> V_34 ) ;
if ( F_126 ( & V_6 -> V_79 ) )
goto V_77;
V_26 = 0xFFFF ;
while ( ! ( F_249 ( V_6 , & V_28 ,
& V_673 , V_676 , V_26 ) ) ) {
V_29 = F_9 ( V_28 . V_37 ) &
V_38 ;
if ( V_29 != V_39 )
break;
V_26 = F_9 ( V_673 . V_184 ) ;
if ( F_63 ( V_6 , & V_28 ,
& V_674 , V_145 , V_26 ,
sizeof( T_11 ) ) )
continue;
if ( V_674 . V_154 == V_155 ||
V_674 . V_154 == V_156 ||
V_674 . V_154 == V_158 )
F_247 ( V_6 ,
F_6 ( V_673 . V_677 ) , V_26 ) ;
}
V_631 = 0xFF ;
memset ( V_6 -> V_126 , 0 , V_6 -> V_678 ) ;
while ( ! ( F_74 ( V_6 , & V_28 ,
& V_176 , V_679 ,
V_631 ) ) ) {
V_29 = F_9 ( V_28 . V_37 ) &
V_38 ;
if ( V_29 != V_39 )
break;
V_631 = V_176 . V_183 ;
V_26 = F_9 ( V_176 . V_184 ) ;
F_139 ( V_26 , V_6 -> V_126 ) ;
}
V_77:
F_3 ( V_33 L_280 ,
V_6 -> V_34 ) ;
}
static void
F_250 ( struct V_5 * V_6 , T_1 V_8 ,
T_4 V_26 )
{
struct V_80 * V_81 ;
unsigned long V_63 ;
int V_94 ;
F_19 ( & V_6 -> V_82 , V_63 ) ;
F_4 (sas_expander, &ioc->sas_expander_list, list) {
if ( V_81 -> V_8 != V_8 )
continue;
V_81 -> V_671 = 1 ;
if ( V_81 -> V_26 == V_26 )
goto V_77;
F_3 ( L_281 \
L_282 ,
( unsigned long long ) V_81 -> V_8 ,
V_81 -> V_26 , V_26 ) ;
V_81 -> V_26 = V_26 ;
for ( V_94 = 0 ; V_94 < V_81 -> V_31 ; V_94 ++ )
V_81 -> V_202 [ V_94 ] . V_26 = V_26 ;
goto V_77;
}
V_77:
F_22 ( & V_6 -> V_82 , V_63 ) ;
}
static void
F_251 ( struct V_5 * V_6 )
{
T_38 V_547 ;
T_9 V_28 ;
T_4 V_29 ;
T_1 V_8 ;
T_4 V_26 ;
F_3 ( V_33 L_283 , V_6 -> V_34 ) ;
if ( F_126 ( & V_6 -> V_83 ) )
goto V_77;
V_26 = 0xFFFF ;
while ( ! ( F_208 ( V_6 , & V_28 , & V_547 ,
V_680 , V_26 ) ) ) {
V_29 = F_9 ( V_28 . V_37 ) &
V_38 ;
if ( V_29 != V_39 )
break;
V_26 = F_9 ( V_547 . V_184 ) ;
V_8 = F_6 ( V_547 . V_10 ) ;
F_3 ( L_284 ,
V_26 ,
( unsigned long long ) V_8 ) ;
F_250 ( V_6 , V_8 , V_26 ) ;
}
V_77:
F_3 ( V_33 L_285 , V_6 -> V_34 ) ;
}
static void
F_252 ( struct V_5 * V_6 )
{
struct V_44 * V_45 , * V_681 ;
struct V_80 * V_81 , * V_682 ;
struct V_46 * V_47 , * V_683 ;
struct V_684 V_685 ;
unsigned long V_63 ;
F_3 ( V_33 L_286 ,
V_6 -> V_34 ) ;
F_3 ( V_33 L_287 ,
V_6 -> V_34 ) ;
F_128 (sas_device, sas_device_next,
&ioc->sas_device_list, list) {
if ( ! V_45 -> V_671 )
F_25 ( V_6 ,
V_45 -> V_8 ) ;
else
V_45 -> V_671 = 0 ;
}
if ( V_6 -> V_675 ) {
F_3 ( V_33 L_288 ,
V_6 -> V_34 ) ;
F_128 (raid_device, raid_device_next,
&ioc->raid_device_list, list) {
if ( ! V_47 -> V_671 )
F_231 ( V_6 ,
V_47 -> V_26 ) ;
else
V_47 -> V_671 = 0 ;
}
}
F_3 ( V_33 L_289 ,
V_6 -> V_34 ) ;
F_19 ( & V_6 -> V_82 , V_63 ) ;
F_118 ( & V_685 ) ;
F_128 (sas_expander, sas_expander_next,
&ioc->sas_expander_list, list) {
if ( ! V_81 -> V_671 )
F_253 ( & V_81 -> V_68 , & V_685 ) ;
else
V_81 -> V_671 = 0 ;
}
F_22 ( & V_6 -> V_82 , V_63 ) ;
F_128 (sas_expander, sas_expander_next, &tmp_list,
list) {
F_20 ( & V_81 -> V_68 ) ;
F_212 ( V_6 , V_81 ) ;
}
F_3 ( V_33 L_290 ,
V_6 -> V_34 ) ;
F_134 ( V_6 ) ;
}
static void
F_254 ( struct V_5 * V_6 ,
struct V_80 * V_81 , T_4 V_26 )
{
T_39 V_548 ;
T_9 V_28 ;
int V_94 ;
for ( V_94 = 0 ; V_94 < V_81 -> V_31 ; V_94 ++ ) {
if ( ( F_209 ( V_6 , & V_28 ,
& V_548 , V_94 , V_26 ) ) ) {
F_13 ( V_33 L_2 ,
V_6 -> V_34 , __FILE__ , __LINE__ , V_35 ) ;
return;
}
F_199 ( V_6 , V_81 -> V_8 ,
F_9 ( V_548 . V_314 ) , V_94 ,
V_548 . V_529 >> 4 ) ;
}
}
static void
F_255 ( struct V_5 * V_6 )
{
T_38 V_547 ;
T_8 V_27 ;
T_47 V_673 ;
T_11 V_674 ;
T_12 V_176 ;
T_23 V_347 ;
T_9 V_28 ;
T_6 V_631 ;
T_4 V_29 ;
T_4 V_26 , V_549 ;
T_1 V_8 ;
struct V_44 * V_45 ;
struct V_80 * V_686 ;
static struct V_46 * V_47 ;
T_6 V_687 ;
unsigned long V_63 ;
F_3 ( V_33 L_291 , V_6 -> V_34 ) ;
F_197 ( V_6 ) ;
F_3 ( V_33 L_292 , V_6 -> V_34 ) ;
V_26 = 0xFFFF ;
while ( ! ( F_208 ( V_6 , & V_28 , & V_547 ,
V_680 , V_26 ) ) ) {
V_29 = F_9 ( V_28 . V_37 ) &
V_38 ;
if ( V_29 != V_39 ) {
F_3 ( V_33 L_293 \
L_294 ,
V_6 -> V_34 , V_29 ,
F_59 ( V_28 . V_265 ) ) ;
break;
}
V_26 = F_9 ( V_547 . V_184 ) ;
F_19 ( & V_6 -> V_82 , V_63 ) ;
V_686 = F_38 (
V_6 , F_6 ( V_547 . V_10 ) ) ;
F_22 ( & V_6 -> V_82 , V_63 ) ;
if ( V_686 )
F_254 ( V_6 , V_686 ,
V_26 ) ;
else {
F_3 ( V_33 L_295 \
L_296 , V_6 -> V_34 ,
V_26 , ( unsigned long long )
F_6 ( V_547 . V_10 ) ) ;
F_207 ( V_6 , V_26 ) ;
F_3 ( V_33 L_297 \
L_296 , V_6 -> V_34 ,
V_26 , ( unsigned long long )
F_6 ( V_547 . V_10 ) ) ;
}
}
F_3 ( V_33 L_298 ,
V_6 -> V_34 ) ;
if ( ! V_6 -> V_675 )
goto V_688;
F_3 ( V_33 L_299 , V_6 -> V_34 ) ;
V_631 = 0xFF ;
while ( ! ( F_74 ( V_6 , & V_28 ,
& V_176 , V_679 ,
V_631 ) ) ) {
V_29 = F_9 ( V_28 . V_37 ) &
V_38 ;
if ( V_29 != V_39 ) {
F_3 ( V_33 L_300\
L_294 ,
V_6 -> V_34 , V_29 ,
F_59 ( V_28 . V_265 ) ) ;
break;
}
V_631 = V_176 . V_183 ;
V_26 = F_9 ( V_176 . V_184 ) ;
F_19 ( & V_6 -> V_67 , V_63 ) ;
V_45 = F_17 ( V_6 , V_26 ) ;
F_22 ( & V_6 -> V_67 , V_63 ) ;
if ( V_45 )
continue;
if ( F_12 ( V_6 , & V_28 ,
& V_27 , V_32 ,
V_26 ) != 0 )
continue;
V_29 = F_9 ( V_28 . V_37 ) &
V_38 ;
if ( V_29 != V_39 ) {
F_3 ( V_33 L_301 \
L_294 ,
V_6 -> V_34 , V_29 ,
F_59 ( V_28 . V_265 ) ) ;
break;
}
V_549 = F_9 ( V_27 . V_551 ) ;
if ( ! F_11 ( V_6 , V_549 ,
& V_8 ) ) {
F_3 ( V_33 L_302 \
L_303 ,
V_6 -> V_34 , V_26 , ( unsigned long long )
F_6 ( V_27 . V_10 ) ) ;
F_199 ( V_6 , V_8 ,
V_26 , V_27 . V_578 ,
V_531 ) ;
F_139 ( V_26 , V_6 -> V_126 ) ;
V_687 = 0 ;
while ( F_216 ( V_6 , V_26 , V_687 ++ ,
1 ) ) {
F_225 ( 1 ) ;
}
F_3 ( V_33 L_304 \
L_303 ,
V_6 -> V_34 , V_26 , ( unsigned long long )
F_6 ( V_27 . V_10 ) ) ;
}
}
F_3 ( V_33 L_305 ,
V_6 -> V_34 ) ;
F_3 ( V_33 L_306 , V_6 -> V_34 ) ;
V_26 = 0xFFFF ;
while ( ! ( F_249 ( V_6 , & V_28 ,
& V_673 , V_676 , V_26 ) ) ) {
V_29 = F_9 ( V_28 . V_37 ) &
V_38 ;
if ( V_29 != V_39 ) {
F_3 ( V_33 L_307 \
L_294 ,
V_6 -> V_34 , V_29 ,
F_59 ( V_28 . V_265 ) ) ;
break;
}
V_26 = F_9 ( V_673 . V_184 ) ;
F_19 ( & V_6 -> V_78 , V_63 ) ;
V_47 = F_34 ( V_6 ,
F_6 ( V_673 . V_677 ) ) ;
F_22 ( & V_6 -> V_78 , V_63 ) ;
if ( V_47 )
continue;
if ( F_63 ( V_6 , & V_28 ,
& V_674 , V_145 , V_26 ,
sizeof( T_11 ) ) )
continue;
V_29 = F_9 ( V_28 . V_37 ) &
V_38 ;
if ( V_29 != V_39 ) {
F_3 ( V_33 L_307 \
L_294 ,
V_6 -> V_34 , V_29 ,
F_59 ( V_28 . V_265 ) ) ;
break;
}
if ( V_674 . V_154 == V_155 ||
V_674 . V_154 == V_156 ||
V_674 . V_154 == V_158 ) {
memset ( & V_347 , 0 , sizeof( T_23 ) ) ;
V_347 . V_351 = V_641 ;
V_347 . V_354 = V_673 . V_184 ;
F_3 ( V_33
L_308 ,
V_6 -> V_34 , V_673 . V_184 ) ;
F_229 ( V_6 , & V_347 ) ;
F_3 ( V_33
L_309 ,
V_6 -> V_34 , V_673 . V_184 ) ;
}
}
F_3 ( V_33 L_310 ,
V_6 -> V_34 ) ;
V_688:
F_3 ( V_33 L_311 ,
V_6 -> V_34 ) ;
V_26 = 0xFFFF ;
while ( ! ( F_12 ( V_6 , & V_28 ,
& V_27 , V_672 ,
V_26 ) ) ) {
V_29 = F_9 ( V_28 . V_37 ) &
V_38 ;
if ( V_29 != V_39 ) {
F_3 ( V_33 L_312\
L_313 ,
V_6 -> V_34 , V_29 ,
F_59 ( V_28 . V_265 ) ) ;
break;
}
V_26 = F_9 ( V_27 . V_184 ) ;
if ( ! ( F_40 (
F_59 ( V_27 . V_135 ) ) ) )
continue;
F_19 ( & V_6 -> V_67 , V_63 ) ;
V_45 = F_16 ( V_6 ,
F_6 ( V_27 . V_10 ) ) ;
F_22 ( & V_6 -> V_67 , V_63 ) ;
if ( V_45 )
continue;
V_549 = F_9 ( V_27 . V_551 ) ;
if ( ! F_11 ( V_6 , V_549 , & V_8 ) ) {
F_3 ( V_33 L_314 \
L_296 , V_6 -> V_34 ,
V_26 , ( unsigned long long )
F_6 ( V_27 . V_10 ) ) ;
F_199 ( V_6 , V_8 , V_26 ,
V_27 . V_578 , V_531 ) ;
V_687 = 0 ;
while ( F_216 ( V_6 , V_26 , V_687 ++ ,
0 ) ) {
F_225 ( 1 ) ;
}
F_3 ( V_33 L_315 \
L_296 , V_6 -> V_34 ,
V_26 , ( unsigned long long )
F_6 ( V_27 . V_10 ) ) ;
}
}
F_3 ( V_33 L_316 ,
V_6 -> V_34 ) ;
F_3 ( V_33 L_317 , V_6 -> V_34 ) ;
}
void
F_256 ( struct V_5 * V_6 , int V_689 )
{
switch ( V_689 ) {
case V_690 :
F_99 ( V_6 , F_3 ( V_33
L_318 , V_6 -> V_34 , V_35 ) ) ;
break;
case V_691 :
F_99 ( V_6 , F_3 ( V_33
L_319 , V_6 -> V_34 , V_35 ) ) ;
if ( V_6 -> V_555 . V_223 & V_228 ) {
V_6 -> V_555 . V_223 |= V_263 ;
F_152 ( V_6 , V_6 -> V_555 . V_90 ) ;
F_88 ( & V_6 -> V_555 . V_229 ) ;
}
if ( V_6 -> V_222 . V_223 & V_228 ) {
V_6 -> V_222 . V_223 |= V_263 ;
F_152 ( V_6 , V_6 -> V_222 . V_90 ) ;
F_88 ( & V_6 -> V_222 . V_229 ) ;
}
F_125 ( V_6 ) ;
F_163 ( V_6 ) ;
break;
case V_692 :
F_99 ( V_6 , F_3 ( V_33
L_320 , V_6 -> V_34 , V_35 ) ) ;
if ( ( ! V_6 -> V_48 ) && ! ( V_630 > 0 &&
! V_6 -> V_30 . V_31 ) ) {
F_244 ( V_6 ) ;
F_246 ( V_6 ) ;
F_248 ( V_6 ) ;
F_251 ( V_6 ) ;
F_123 ( V_6 ) ;
}
break;
}
}
static void
F_257 ( struct V_5 * V_6 , struct V_281 * V_282 )
{
if ( V_6 -> V_245 ||
V_6 -> V_246 ) {
F_121 ( V_6 , V_282 ) ;
return;
}
switch ( V_282 -> V_291 ) {
case V_292 :
F_258 ( V_6 ,
(struct V_288 * )
V_282 -> V_289 ) ;
break;
case V_293 :
while ( F_259 ( V_6 -> V_102 ) || V_6 -> V_69 )
F_225 ( 1 ) ;
F_252 ( V_6 ) ;
F_255 ( V_6 ) ;
break;
case V_294 :
V_6 -> V_693 = 0 ;
if ( V_694 [ 0 ] != - 1 && V_694 [ 1 ] != - 1 )
F_260 ( V_6 , V_694 [ 0 ] ,
V_694 [ 1 ] ) ;
F_27 ( V_6 , F_3 ( V_33
L_321 ,
V_6 -> V_34 ) ) ;
break;
case V_488 :
F_183 ( V_6 , V_282 -> V_489 ) ;
break;
case V_342 :
F_218 ( V_6 , V_282 ) ;
break;
case V_497 :
F_220 ( V_6 , V_282 ) ;
break;
case V_695 :
F_224 ( V_6 , V_282 ) ;
break;
case V_696 :
F_223 ( V_6 , V_282 ) ;
break;
case V_697 :
F_222 ( V_6 ,
V_282 ) ;
break;
case V_698 :
F_239 ( V_6 , V_282 ) ;
break;
case V_699 :
F_240 ( V_6 , V_282 ) ;
break;
case V_700 :
F_241 ( V_6 , V_282 ) ;
break;
case V_701 :
F_243 ( V_6 , V_282 ) ;
break;
}
F_121 ( V_6 , V_282 ) ;
}
static void
V_287 ( struct V_702 * V_286 )
{
struct V_281 * V_282 = F_261 ( V_286 ,
struct V_281 , V_286 ) ;
F_257 ( V_282 -> V_6 , V_282 ) ;
}
T_6
F_262 ( struct V_5 * V_6 , T_6 V_220 ,
T_10 V_221 )
{
struct V_281 * V_282 ;
T_31 * V_28 ;
T_4 V_291 ;
T_4 V_177 ;
if ( V_6 -> V_245 || V_6 -> V_246 )
return 1 ;
V_28 = F_87 ( V_6 , V_221 ) ;
if ( F_143 ( ! V_28 ) ) {
F_13 ( V_33 L_97 ,
V_6 -> V_34 , __FILE__ , __LINE__ , V_35 ) ;
return 1 ;
}
V_291 = F_9 ( V_28 -> V_496 ) ;
if ( V_291 != V_703 )
F_263 ( V_6 , V_291 , 0 ) ;
switch ( V_291 ) {
case V_696 :
{
T_41 * V_704 =
( T_41 * )
V_28 -> V_494 ;
if ( V_704 -> V_705 !=
V_706 )
return 1 ;
if ( V_6 -> V_627 ) {
V_6 -> V_626 ++ ;
return 1 ;
} else
V_6 -> V_627 = 1 ;
break;
}
case V_342 :
F_153 ( V_6 ,
( T_19 * )
V_28 -> V_494 ) ;
break;
case V_698 :
F_158 ( V_6 ,
( T_22 * )
V_28 -> V_494 ) ;
break;
case V_699 :
F_161 ( V_6 ,
( T_24 * )
V_28 -> V_494 ) ;
break;
case V_497 :
case V_701 :
case V_695 :
case V_697 :
case V_700 :
break;
case V_707 :
F_162 ( V_6 ,
( T_25 * )
V_28 -> V_494 ) ;
break;
default:
return 1 ;
}
V_177 = F_9 ( V_28 -> V_498 ) * 4 ;
V_282 = F_51 ( sizeof( * V_282 ) + V_177 , V_290 ) ;
if ( ! V_282 ) {
F_13 ( V_33 L_2 ,
V_6 -> V_34 , __FILE__ , __LINE__ , V_35 ) ;
return 1 ;
}
memcpy ( V_282 -> V_289 , V_28 -> V_494 , V_177 ) ;
V_282 -> V_6 = V_6 ;
V_282 -> V_708 = V_28 -> V_708 ;
V_282 -> V_709 = V_28 -> V_709 ;
V_282 -> V_291 = V_291 ;
F_117 ( V_6 , V_282 ) ;
return 1 ;
}
static void
F_212 ( struct V_5 * V_6 ,
struct V_80 * V_81 )
{
struct V_302 * V_303 , * V_295 ;
F_128 (mpt3sas_port, next,
&sas_expander->sas_port_list, port_list) {
if ( V_6 -> V_69 )
return;
if ( V_303 -> V_305 . V_306 ==
V_307 )
F_25 ( V_6 ,
V_303 -> V_305 . V_8 ) ;
else if ( V_303 -> V_305 . V_306 ==
V_309 ||
V_303 -> V_305 . V_306 ==
V_310 )
F_211 ( V_6 ,
V_303 -> V_305 . V_8 ) ;
}
F_30 ( V_6 , V_81 -> V_8 ,
V_81 -> V_71 ) ;
F_3 ( V_33
L_322 ,
V_6 -> V_34 ,
V_81 -> V_26 , ( unsigned long long )
V_81 -> V_8 ) ;
F_21 ( V_81 -> V_202 ) ;
F_21 ( V_81 ) ;
}
static void
F_264 ( struct V_5 * V_6 )
{
T_43 * V_237 ;
T_44 * V_28 ;
T_4 V_90 ;
if ( ! V_6 -> V_675 )
return;
if ( F_126 ( & V_6 -> V_79 ) )
return;
F_93 ( & V_6 -> V_555 . V_242 ) ;
if ( V_6 -> V_555 . V_223 != V_224 ) {
F_13 ( V_33 L_240 ,
V_6 -> V_34 , V_35 ) ;
goto V_77;
}
V_6 -> V_555 . V_223 = V_228 ;
V_90 = F_144 ( V_6 , V_6 -> V_634 ) ;
if ( ! V_90 ) {
F_13 ( V_33 L_48 ,
V_6 -> V_34 , V_35 ) ;
V_6 -> V_555 . V_223 = V_224 ;
goto V_77;
}
V_237 = F_100 ( V_6 , V_90 ) ;
V_6 -> V_555 . V_90 = V_90 ;
memset ( V_237 , 0 , sizeof( T_43 ) ) ;
V_237 -> V_256 = V_635 ;
V_237 -> V_479 = V_710 ;
F_3 ( V_33 L_323 , V_6 -> V_34 ) ;
F_103 ( & V_6 -> V_555 . V_229 ) ;
F_145 ( V_6 , V_90 ) ;
F_105 ( & V_6 -> V_555 . V_229 , 10 * V_262 ) ;
if ( ! ( V_6 -> V_555 . V_223 & V_225 ) ) {
F_13 ( V_33 L_50 ,
V_6 -> V_34 , V_35 ) ;
goto V_77;
}
if ( V_6 -> V_555 . V_223 & V_227 ) {
V_28 = V_6 -> V_555 . V_221 ;
F_3 ( V_33
L_324 ,
V_6 -> V_34 , F_9 ( V_28 -> V_37 ) ,
F_59 ( V_28 -> V_265 ) ) ;
}
V_77:
V_6 -> V_555 . V_223 = V_224 ;
F_108 ( & V_6 -> V_555 . V_242 ) ;
}
static void F_265 ( struct V_711 * V_491 )
{
struct V_101 * V_102 = F_266 ( V_491 ) ;
struct V_5 * V_6 = F_47 ( V_102 ) ;
struct V_302 * V_303 , * V_712 ;
struct V_46 * V_47 , * V_295 ;
struct V_107 * V_108 ;
struct V_713 * V_714 ;
unsigned long V_63 ;
V_6 -> V_245 = 1 ;
F_125 ( V_6 ) ;
F_19 ( & V_6 -> V_284 , V_63 ) ;
V_714 = V_6 -> V_283 ;
V_6 -> V_283 = NULL ;
F_22 ( & V_6 -> V_284 , V_63 ) ;
if ( V_714 )
F_267 ( V_714 ) ;
F_264 ( V_6 ) ;
F_128 (raid_device, next, &ioc->raid_device_list,
list) {
if ( V_47 -> V_72 ) {
V_108 =
V_47 -> V_72 -> V_110 ;
V_108 -> V_321 = 1 ;
F_232 ( & V_47 -> V_72 -> V_117 ) ;
}
F_3 ( V_33 L_249 ,
V_6 -> V_34 , V_47 -> V_26 ,
( unsigned long long ) V_47 -> V_51 ) ;
F_36 ( V_6 , V_47 ) ;
}
F_128 (mpt3sas_port, next_port,
&ioc->sas_hba.sas_port_list, port_list) {
if ( V_303 -> V_305 . V_306 ==
V_307 )
F_25 ( V_6 ,
V_303 -> V_305 . V_8 ) ;
else if ( V_303 -> V_305 . V_306 ==
V_309 ||
V_303 -> V_305 . V_306 ==
V_310 )
F_211 ( V_6 ,
V_303 -> V_305 . V_8 ) ;
}
if ( V_6 -> V_30 . V_31 ) {
F_21 ( V_6 -> V_30 . V_202 ) ;
V_6 -> V_30 . V_202 = NULL ;
V_6 -> V_30 . V_31 = 0 ;
}
F_268 ( V_102 ) ;
F_269 ( V_102 ) ;
F_270 ( V_6 ) ;
F_20 ( & V_6 -> V_68 ) ;
F_271 ( V_102 ) ;
}
static void
F_272 ( struct V_711 * V_491 )
{
struct V_101 * V_102 = F_266 ( V_491 ) ;
struct V_5 * V_6 = F_47 ( V_102 ) ;
struct V_713 * V_714 ;
unsigned long V_63 ;
V_6 -> V_245 = 1 ;
F_125 ( V_6 ) ;
F_19 ( & V_6 -> V_284 , V_63 ) ;
V_714 = V_6 -> V_283 ;
V_6 -> V_283 = NULL ;
F_22 ( & V_6 -> V_284 , V_63 ) ;
if ( V_714 )
F_267 ( V_714 ) ;
F_264 ( V_6 ) ;
F_270 ( V_6 ) ;
}
static void
F_273 ( struct V_5 * V_6 )
{
T_6 V_43 ;
void * V_42 ;
struct V_44 * V_45 ;
struct V_46 * V_47 ;
T_4 V_26 ;
T_1 V_71 ;
T_1 V_8 ;
unsigned long V_63 ;
int V_19 ;
if ( ! V_6 -> V_49 . V_50 )
return;
V_42 = NULL ;
V_43 = 0 ;
if ( V_6 -> V_52 . V_42 ) {
V_42 = V_6 -> V_52 . V_42 ;
V_43 = V_6 -> V_52 . V_43 ;
} else if ( V_6 -> V_57 . V_42 ) {
V_42 = V_6 -> V_57 . V_42 ;
V_43 = V_6 -> V_57 . V_43 ;
} else if ( V_6 -> V_60 . V_42 ) {
V_42 = V_6 -> V_60 . V_42 ;
V_43 = V_6 -> V_60 . V_43 ;
}
if ( ! V_42 )
return;
if ( V_43 ) {
V_47 = V_42 ;
V_19 = F_230 ( V_6 -> V_102 , V_123 ,
V_47 -> V_74 , 0 ) ;
if ( V_19 )
F_36 ( V_6 , V_47 ) ;
} else {
F_19 ( & V_6 -> V_67 , V_63 ) ;
V_45 = V_42 ;
V_26 = V_45 -> V_26 ;
V_71 = V_45 -> V_71 ;
V_8 = V_45 -> V_8 ;
F_253 ( & V_45 -> V_68 , & V_6 -> V_70 ) ;
F_22 ( & V_6 -> V_67 , V_63 ) ;
if ( ! F_29 ( V_6 , V_26 ,
V_71 ) ) {
F_18 ( V_6 , V_45 ) ;
} else if ( ! V_45 -> V_72 ) {
if ( ! V_6 -> V_48 ) {
F_30 ( V_6 ,
V_8 ,
V_71 ) ;
F_18 ( V_6 , V_45 ) ;
}
}
}
}
static void
F_274 ( struct V_5 * V_6 )
{
struct V_46 * V_47 , * V_715 ;
int V_19 ;
F_128 (raid_device, raid_next,
&ioc->raid_device_list, list) {
if ( V_47 -> V_72 )
continue;
V_19 = F_230 ( V_6 -> V_102 , V_123 ,
V_47 -> V_74 , 0 ) ;
if ( V_19 )
F_36 ( V_6 , V_47 ) ;
}
}
static void
F_275 ( struct V_5 * V_6 )
{
struct V_44 * V_45 , * V_295 ;
unsigned long V_63 ;
F_128 (sas_device, next, &ioc->sas_device_init_list,
list) {
if ( ! F_29 ( V_6 , V_45 -> V_26 ,
V_45 -> V_71 ) ) {
F_20 ( & V_45 -> V_68 ) ;
F_21 ( V_45 ) ;
continue;
} else if ( ! V_45 -> V_72 ) {
if ( ! V_6 -> V_48 ) {
F_30 ( V_6 ,
V_45 -> V_8 ,
V_45 -> V_71 ) ;
F_20 ( & V_45 -> V_68 ) ;
F_21 ( V_45 ) ;
continue;
}
}
F_19 ( & V_6 -> V_67 , V_63 ) ;
F_253 ( & V_45 -> V_68 , & V_6 -> V_70 ) ;
F_22 ( & V_6 -> V_67 , V_63 ) ;
}
}
static void
F_276 ( struct V_5 * V_6 )
{
T_4 V_716 ;
if ( ! ( V_6 -> V_186 . V_717 & V_718 ) )
return;
F_273 ( V_6 ) ;
if ( V_6 -> V_675 ) {
V_716 =
F_9 ( V_6 -> V_719 . V_720 ) &
V_721 ;
if ( V_716 ==
V_722 ) {
F_274 ( V_6 ) ;
F_275 ( V_6 ) ;
} else {
F_275 ( V_6 ) ;
F_274 ( V_6 ) ;
}
} else
F_275 ( V_6 ) ;
}
static void
F_277 ( struct V_101 * V_102 )
{
struct V_5 * V_6 = F_47 ( V_102 ) ;
int V_19 ;
if ( V_723 != - 1 && V_723 != 0 )
F_278 ( V_6 , V_723 ) ;
if ( V_630 > 0 )
return;
V_6 -> V_693 = 1 ;
V_19 = F_279 ( V_6 ) ;
if ( V_19 != 0 )
F_3 ( V_33 L_325 , V_6 -> V_34 ) ;
}
static int
F_280 ( struct V_101 * V_102 , unsigned long time )
{
struct V_5 * V_6 = F_47 ( V_102 ) ;
if ( V_630 > 0 ) {
V_6 -> V_48 = 0 ;
V_6 -> V_587 = 0 ;
return 1 ;
}
if ( time >= ( 300 * V_262 ) ) {
V_6 -> V_724 . V_223 = V_224 ;
F_3 ( V_33
L_326 ,
V_6 -> V_34 ) ;
V_6 -> V_48 = 0 ;
return 1 ;
}
if ( V_6 -> V_693 )
return 0 ;
if ( V_6 -> V_725 ) {
F_3 ( V_33
L_327 ,
V_6 -> V_34 , V_6 -> V_725 ) ;
V_6 -> V_48 = 0 ;
V_6 -> V_587 = 0 ;
V_6 -> V_245 = 1 ;
return 1 ;
}
F_3 ( V_33 L_328 , V_6 -> V_34 ) ;
V_6 -> V_724 . V_223 = V_224 ;
if ( V_6 -> V_587 ) {
V_6 -> V_587 = 0 ;
F_276 ( V_6 ) ;
}
F_281 ( V_6 ) ;
V_6 -> V_48 = 0 ;
return 1 ;
}
static int
F_282 ( struct V_711 * V_491 , const struct V_726 * V_74 )
{
struct V_5 * V_6 ;
struct V_101 * V_102 ;
int V_727 ;
V_102 = F_283 ( & V_728 ,
sizeof( struct V_5 ) ) ;
if ( ! V_102 )
return - V_729 ;
V_6 = F_47 ( V_102 ) ;
memset ( V_6 , 0 , sizeof( struct V_5 ) ) ;
F_118 ( & V_6 -> V_68 ) ;
F_28 ( & V_6 -> V_68 , & V_730 ) ;
V_6 -> V_102 = V_102 ;
V_6 -> V_74 = V_731 ++ ;
sprintf ( V_6 -> V_34 , L_329 , V_732 , V_6 -> V_74 ) ;
V_6 -> V_491 = V_491 ;
V_6 -> V_410 = V_410 ;
V_6 -> V_254 = V_254 ;
V_6 -> V_733 = V_733 ;
V_6 -> V_734 = V_734 ;
V_6 -> V_735 = V_735 ;
V_6 -> V_736 = V_736 ;
V_6 -> V_634 = V_634 ;
V_6 -> V_737 = V_737 ;
V_6 -> V_322 = V_322 ;
V_6 -> V_331 = V_331 ;
V_6 -> V_327 = V_327 ;
V_6 -> V_7 = V_7 ;
V_6 -> V_738 = & F_163 ;
F_284 ( & V_6 -> V_739 ) ;
F_285 ( & V_6 -> V_740 ) ;
F_285 ( & V_6 -> V_93 ) ;
F_285 ( & V_6 -> V_67 ) ;
F_285 ( & V_6 -> V_82 ) ;
F_285 ( & V_6 -> V_284 ) ;
F_285 ( & V_6 -> V_78 ) ;
F_285 ( & V_6 -> V_741 ) ;
F_118 ( & V_6 -> V_70 ) ;
F_118 ( & V_6 -> V_73 ) ;
F_118 ( & V_6 -> V_83 ) ;
F_118 ( & V_6 -> V_285 ) ;
F_118 ( & V_6 -> V_79 ) ;
F_118 ( & V_6 -> V_30 . V_554 ) ;
F_118 ( & V_6 -> V_323 ) ;
F_118 ( & V_6 -> V_332 ) ;
F_118 ( & V_6 -> V_742 ) ;
V_102 -> V_743 = 32 ;
V_102 -> V_744 = V_744 ;
V_102 -> V_745 = V_746 ;
V_102 -> V_747 = V_6 -> V_74 ;
if ( V_748 != 0xFFFF ) {
if ( V_748 < 64 ) {
V_102 -> V_748 = 64 ;
F_72 ( V_33 L_330 \
L_331
L_332 , V_6 -> V_34 , V_748 ) ;
} else if ( V_748 > 32767 ) {
V_102 -> V_748 = 32767 ;
F_72 ( V_33 L_330 \
L_331
L_333 , V_6 -> V_34 ,
V_748 ) ;
} else {
V_102 -> V_748 = V_748 & 0xFFFE ;
F_3 ( V_33
L_334 ,
V_6 -> V_34 , V_102 -> V_748 ) ;
}
}
if ( V_749 > 0 )
F_286 ( V_102 , V_749 ) ;
else
F_286 ( V_102 , V_750
| V_751
| V_752 ) ;
F_287 ( V_102 , V_753 ) ;
snprintf ( V_6 -> V_754 , sizeof( V_6 -> V_754 ) ,
L_335 , V_6 -> V_74 ) ;
V_6 -> V_283 = F_288 (
V_6 -> V_754 , V_755 ) ;
if ( ! V_6 -> V_283 ) {
F_13 ( V_33 L_2 ,
V_6 -> V_34 , __FILE__ , __LINE__ , V_35 ) ;
V_727 = - V_729 ;
goto V_756;
}
V_6 -> V_48 = 1 ;
if ( ( F_289 ( V_6 ) ) ) {
F_13 ( V_33 L_2 ,
V_6 -> V_34 , __FILE__ , __LINE__ , V_35 ) ;
V_727 = - V_729 ;
goto V_757;
}
V_727 = F_290 ( V_102 , & V_491 -> V_117 ) ;
if ( V_727 ) {
F_13 ( V_33 L_2 ,
V_6 -> V_34 , __FILE__ , __LINE__ , V_35 ) ;
goto V_758;
}
F_291 ( V_102 ) ;
return 0 ;
V_758:
F_270 ( V_6 ) ;
V_757:
F_267 ( V_6 -> V_283 ) ;
V_756:
F_20 ( & V_6 -> V_68 ) ;
F_271 ( V_102 ) ;
return V_727 ;
}
static int
F_292 ( struct V_711 * V_491 , T_48 V_151 )
{
struct V_101 * V_102 = F_266 ( V_491 ) ;
struct V_5 * V_6 = F_47 ( V_102 ) ;
T_49 V_759 ;
F_293 ( V_6 ) ;
F_294 () ;
F_295 ( V_102 ) ;
V_759 = F_296 ( V_491 , V_151 ) ;
F_3 ( V_33
L_336 ,
V_6 -> V_34 , V_491 , F_297 ( V_491 ) , V_759 ) ;
F_298 ( V_491 ) ;
F_299 ( V_6 ) ;
F_300 ( V_491 , V_759 ) ;
return 0 ;
}
static int
F_301 ( struct V_711 * V_491 )
{
struct V_101 * V_102 = F_266 ( V_491 ) ;
struct V_5 * V_6 = F_47 ( V_102 ) ;
T_49 V_759 = V_491 -> V_760 ;
int V_76 ;
F_3 ( V_33
L_337 ,
V_6 -> V_34 , V_491 , F_297 ( V_491 ) , V_759 ) ;
F_300 ( V_491 , V_761 ) ;
F_302 ( V_491 , V_761 , 0 ) ;
F_303 ( V_491 ) ;
V_6 -> V_491 = V_491 ;
V_76 = F_304 ( V_6 ) ;
if ( V_76 )
return V_76 ;
F_96 ( V_6 , V_248 , V_762 ) ;
F_305 ( V_102 ) ;
F_281 ( V_6 ) ;
return 0 ;
}
static T_50
F_306 ( struct V_711 * V_491 , T_51 V_151 )
{
struct V_101 * V_102 = F_266 ( V_491 ) ;
struct V_5 * V_6 = F_47 ( V_102 ) ;
F_3 ( V_33 L_338 ,
V_6 -> V_34 , V_151 ) ;
switch ( V_151 ) {
case V_763 :
return V_764 ;
case V_765 :
V_6 -> V_246 = 1 ;
F_295 ( V_6 -> V_102 ) ;
F_293 ( V_6 ) ;
F_299 ( V_6 ) ;
return V_766 ;
case V_767 :
V_6 -> V_246 = 1 ;
F_293 ( V_6 ) ;
F_163 ( V_6 ) ;
return V_768 ;
}
return V_766 ;
}
static T_50
F_307 ( struct V_711 * V_491 )
{
struct V_101 * V_102 = F_266 ( V_491 ) ;
struct V_5 * V_6 = F_47 ( V_102 ) ;
int V_19 ;
F_3 ( V_33 L_339 ,
V_6 -> V_34 ) ;
V_6 -> V_246 = 0 ;
V_6 -> V_491 = V_491 ;
F_303 ( V_491 ) ;
V_19 = F_304 ( V_6 ) ;
if ( V_19 )
return V_768 ;
V_19 = F_96 ( V_6 , V_248 ,
V_249 ) ;
F_72 ( V_33 L_340 , V_6 -> V_34 ,
( V_19 == 0 ) ? L_116 : L_341 ) ;
if ( ! V_19 )
return V_769 ;
else
return V_768 ;
}
static void
F_308 ( struct V_711 * V_491 )
{
struct V_101 * V_102 = F_266 ( V_491 ) ;
struct V_5 * V_6 = F_47 ( V_102 ) ;
F_3 ( V_33 L_342 , V_6 -> V_34 ) ;
F_309 ( V_491 ) ;
F_281 ( V_6 ) ;
F_305 ( V_6 -> V_102 ) ;
}
static T_50
F_310 ( struct V_711 * V_491 )
{
struct V_101 * V_102 = F_266 ( V_491 ) ;
struct V_5 * V_6 = F_47 ( V_102 ) ;
F_3 ( V_33 L_343 ,
V_6 -> V_34 ) ;
return V_766 ;
}
static int T_52
F_311 ( void )
{
int error ;
V_731 = 0 ;
F_3 ( L_344 , V_732 ,
V_770 ) ;
V_746 =
F_312 ( & V_771 ) ;
if ( ! V_746 )
return - V_729 ;
V_148 = F_313 ( & V_772 ) ;
if ( ! V_148 ) {
F_314 ( V_746 ) ;
return - V_729 ;
}
F_315 () ;
V_410 = F_316 ( F_191 ) ;
V_254 = F_316 ( F_85 ) ;
V_734 = F_316 ( V_773 ) ;
V_735 = F_316 (
V_774 ) ;
V_736 = F_316 (
V_775 ) ;
V_634 = F_316 ( F_213 ) ;
V_737 = F_316 (
V_776 ) ;
V_733 = F_316 ( V_777 ) ;
V_322 = F_316 (
F_142 ) ;
V_331 = F_316 (
F_150 ) ;
V_327 = F_316 (
F_147 ) ;
F_317 () ;
error = F_318 ( & V_778 ) ;
if ( error ) {
F_319 ( V_148 ) ;
F_314 ( V_746 ) ;
}
return error ;
}
static void T_53
F_320 ( void )
{
F_3 ( L_345 ,
V_770 ) ;
F_321 () ;
F_322 ( & V_778 ) ;
F_323 ( V_410 ) ;
F_323 ( V_254 ) ;
F_323 ( V_734 ) ;
F_323 ( V_735 ) ;
F_323 ( V_736 ) ;
F_323 ( V_634 ) ;
F_323 ( V_737 ) ;
F_323 ( V_733 ) ;
F_323 ( V_322 ) ;
F_323 ( V_331 ) ;
F_323 ( V_327 ) ;
F_319 ( V_148 ) ;
F_314 ( V_746 ) ;
}
