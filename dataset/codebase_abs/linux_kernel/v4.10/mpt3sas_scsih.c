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
if ( V_14 -> V_84 ) {
F_48 ( V_54 -> V_35 , V_14 -> V_85 ) ;
return;
}
if ( ! F_49 ( V_14 , V_54 -> V_35 ,
V_54 -> V_86 ) ) {
F_38 ( V_14 , V_54 ) ;
} else if ( ! V_54 -> V_87 ) {
if ( ! V_14 -> V_57 ) {
F_50 ( V_14 ,
V_54 -> V_17 ,
V_54 -> V_86 ) ;
F_38 ( V_14 , V_54 ) ;
}
} else
F_48 ( V_54 -> V_35 , V_14 -> V_85 ) ;
}
static void
F_51 ( struct V_13 * V_14 ,
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
F_47 ( & V_54 -> V_81 , & V_14 -> V_88 ) ;
F_26 ( V_14 , V_54 , 0 ) ;
F_33 ( & V_14 -> V_74 , V_76 ) ;
}
static struct V_55 *
F_52 ( struct V_13 * V_14 , int V_89 , int V_90 )
{
struct V_55 * V_56 , * V_2 ;
V_2 = NULL ;
F_15 (raid_device, &ioc->raid_device_list, list) {
if ( V_56 -> V_89 == V_89 && V_56 -> V_90 == V_90 ) {
V_2 = V_56 ;
goto V_91;
}
}
V_91:
return V_2 ;
}
struct V_55 *
F_53 ( struct V_13 * V_14 , T_4 V_35 )
{
struct V_55 * V_56 , * V_2 ;
V_2 = NULL ;
F_15 (raid_device, &ioc->raid_device_list, list) {
if ( V_56 -> V_35 != V_35 )
continue;
V_2 = V_56 ;
goto V_91;
}
V_91:
return V_2 ;
}
static struct V_55 *
F_54 ( struct V_13 * V_14 , T_1 V_60 )
{
struct V_55 * V_56 , * V_2 ;
V_2 = NULL ;
F_15 (raid_device, &ioc->raid_device_list, list) {
if ( V_56 -> V_60 != V_60 )
continue;
V_2 = V_56 ;
goto V_91;
}
V_91:
return V_2 ;
}
static void
F_55 ( struct V_13 * V_14 ,
struct V_55 * V_56 )
{
unsigned long V_76 ;
F_46 ( V_14 , F_13 ( V_42
L_13 , V_14 -> V_43 , V_44 ,
V_56 -> V_35 , ( unsigned long long ) V_56 -> V_60 ) ) ;
F_32 ( & V_14 -> V_92 , V_76 ) ;
F_47 ( & V_56 -> V_81 , & V_14 -> V_93 ) ;
F_33 ( & V_14 -> V_92 , V_76 ) ;
}
static void
F_56 ( struct V_13 * V_14 ,
struct V_55 * V_56 )
{
unsigned long V_76 ;
F_32 ( & V_14 -> V_92 , V_76 ) ;
F_57 ( & V_56 -> V_81 ) ;
F_2 ( V_56 ) ;
F_33 ( & V_14 -> V_92 , V_76 ) ;
}
struct V_94 *
F_58 ( struct V_13 * V_14 , T_4 V_35 )
{
struct V_94 * V_95 , * V_2 ;
V_2 = NULL ;
F_15 (sas_expander, &ioc->sas_expander_list, list) {
if ( V_95 -> V_35 != V_35 )
continue;
V_2 = V_95 ;
goto V_91;
}
V_91:
return V_2 ;
}
struct V_94 *
F_59 ( struct V_13 * V_14 ,
T_1 V_17 )
{
struct V_94 * V_95 , * V_2 ;
V_2 = NULL ;
F_15 (sas_expander, &ioc->sas_expander_list, list) {
if ( V_95 -> V_17 != V_17 )
continue;
V_2 = V_95 ;
goto V_91;
}
V_91:
return V_2 ;
}
static void
F_60 ( struct V_13 * V_14 ,
struct V_94 * V_95 )
{
unsigned long V_76 ;
F_32 ( & V_14 -> V_96 , V_76 ) ;
F_47 ( & V_95 -> V_81 , & V_14 -> V_97 ) ;
F_33 ( & V_14 -> V_96 , V_76 ) ;
}
static int
F_61 ( T_10 V_98 )
{
if ( V_98 & V_99 &&
( ( V_98 & V_100 ) |
( V_98 & V_101 ) |
( V_98 & V_102 ) ) )
return 1 ;
else
return 0 ;
}
static struct V_103 *
F_62 ( struct V_13 * V_14 , T_4 V_104 )
{
return V_14 -> V_105 [ V_104 - 1 ] . V_106 ;
}
static inline struct V_103 *
F_63 ( struct V_13 * V_14 , T_4 V_104 )
{
unsigned long V_76 ;
struct V_103 * V_106 ;
F_32 ( & V_14 -> V_107 , V_76 ) ;
V_106 = V_14 -> V_105 [ V_104 - 1 ] . V_106 ;
V_14 -> V_105 [ V_104 - 1 ] . V_106 = NULL ;
F_33 ( & V_14 -> V_107 , V_76 ) ;
return V_106 ;
}
static T_4
F_64 ( struct V_13 * V_14 , struct V_103
* V_106 )
{
T_4 V_104 ;
unsigned long V_76 ;
int V_108 ;
F_32 ( & V_14 -> V_107 , V_76 ) ;
V_104 = 0 ;
for ( V_108 = 0 ; V_108 < V_14 -> V_109 ; V_108 ++ ) {
if ( V_14 -> V_105 [ V_108 ] . V_106 == V_106 ) {
V_104 = V_14 -> V_105 [ V_108 ] . V_104 ;
goto V_91;
}
}
V_91:
F_33 ( & V_14 -> V_107 , V_76 ) ;
return V_104 ;
}
static T_6
F_65 ( struct V_13 * V_14 , int V_89 ,
int V_90 )
{
T_6 V_110 ;
unsigned long V_76 ;
int V_108 ;
F_32 ( & V_14 -> V_107 , V_76 ) ;
V_110 = 0 ;
for ( V_108 = 0 ; V_108 < V_14 -> V_109 ; V_108 ++ ) {
if ( V_14 -> V_105 [ V_108 ] . V_106 &&
( V_14 -> V_105 [ V_108 ] . V_106 -> V_51 -> V_89 == V_89 &&
V_14 -> V_105 [ V_108 ] . V_106 -> V_51 -> V_90 == V_90 ) ) {
V_110 = 1 ;
goto V_91;
}
}
V_91:
F_33 ( & V_14 -> V_107 , V_76 ) ;
return V_110 ;
}
static T_6
F_66 ( struct V_13 * V_14 , int V_89 ,
unsigned int V_111 , int V_90 )
{
T_6 V_110 ;
unsigned long V_76 ;
int V_108 ;
F_32 ( & V_14 -> V_107 , V_76 ) ;
V_110 = 0 ;
for ( V_108 = 0 ; V_108 < V_14 -> V_109 ; V_108 ++ ) {
if ( V_14 -> V_105 [ V_108 ] . V_106 &&
( V_14 -> V_105 [ V_108 ] . V_106 -> V_51 -> V_89 == V_89 &&
V_14 -> V_105 [ V_108 ] . V_106 -> V_51 -> V_90 == V_90 &&
V_14 -> V_105 [ V_108 ] . V_106 -> V_51 -> V_111 == V_111 ) ) {
V_110 = 1 ;
goto V_91;
}
}
V_91:
F_33 ( & V_14 -> V_107 , V_76 ) ;
return V_110 ;
}
static int
F_67 ( struct V_112 * V_75 , int V_113 )
{
struct V_114 * V_115 = V_75 -> V_116 ;
int V_117 ;
struct V_13 * V_14 = F_68 ( V_115 ) ;
struct V_118 * V_119 ;
struct V_72 * V_120 ;
struct V_53 * V_54 ;
unsigned long V_76 ;
V_117 = V_115 -> V_121 ;
V_119 = V_75 -> V_122 ;
if ( ! V_119 )
goto V_123;
V_120 = V_119 -> V_124 ;
if ( ! V_120 )
goto V_123;
if ( ( V_120 -> V_76 & V_125 ) )
goto V_123;
F_32 ( & V_14 -> V_74 , V_76 ) ;
V_54 = F_28 ( V_14 , V_120 ) ;
if ( V_54 ) {
if ( V_54 -> V_98 & V_102 )
V_117 = V_126 ;
F_41 ( V_54 ) ;
}
F_33 ( & V_14 -> V_74 , V_76 ) ;
V_123:
if ( ! V_75 -> V_127 )
V_117 = 1 ;
if ( V_113 > V_117 )
V_113 = V_117 ;
return F_69 ( V_75 , V_113 ) ;
}
static int
F_70 ( struct V_128 * V_87 )
{
struct V_114 * V_115 = F_71 ( & V_87 -> V_129 ) ;
struct V_13 * V_14 = F_68 ( V_115 ) ;
struct V_72 * V_120 ;
struct V_53 * V_54 ;
struct V_55 * V_56 ;
unsigned long V_76 ;
struct V_130 * V_131 ;
V_120 = F_9 ( sizeof( * V_120 ) ,
V_132 ) ;
if ( ! V_120 )
return - V_133 ;
V_87 -> V_122 = V_120 ;
V_120 -> V_87 = V_87 ;
V_120 -> V_35 = V_134 ;
if ( V_87 -> V_90 == V_135 ) {
F_32 ( & V_14 -> V_92 , V_76 ) ;
V_56 = F_52 ( V_14 , V_87 -> V_89 ,
V_87 -> V_90 ) ;
if ( V_56 ) {
V_120 -> V_35 = V_56 -> V_35 ;
V_120 -> V_17 = V_56 -> V_60 ;
V_120 -> V_76 |= V_125 ;
if ( V_14 -> V_136 )
V_120 -> V_56 = V_56 ;
V_56 -> V_87 = V_87 ;
}
F_33 ( & V_14 -> V_92 , V_76 ) ;
return 0 ;
}
F_32 ( & V_14 -> V_74 , V_76 ) ;
V_131 = F_72 ( V_87 -> V_129 . V_137 ) ;
V_54 = F_34 ( V_14 ,
V_131 -> V_138 . V_17 ) ;
if ( V_54 ) {
V_120 -> V_35 = V_54 -> V_35 ;
V_120 -> V_17 = V_54 -> V_17 ;
V_120 -> V_75 = V_54 ;
V_54 -> V_87 = V_87 ;
V_54 -> V_89 = V_87 -> V_89 ;
V_54 -> V_90 = V_87 -> V_90 ;
if ( F_73 ( V_54 -> V_35 , V_14 -> V_139 ) )
V_120 -> V_76 |=
V_140 ;
if ( V_54 -> V_141 )
V_120 -> V_76 |= V_142 ;
}
F_33 ( & V_14 -> V_74 , V_76 ) ;
return 0 ;
}
static void
F_74 ( struct V_128 * V_87 )
{
struct V_114 * V_115 = F_71 ( & V_87 -> V_129 ) ;
struct V_13 * V_14 = F_68 ( V_115 ) ;
struct V_72 * V_120 ;
struct V_53 * V_54 ;
struct V_55 * V_56 ;
unsigned long V_76 ;
V_120 = V_87 -> V_122 ;
if ( ! V_120 )
return;
if ( V_87 -> V_90 == V_135 ) {
F_32 ( & V_14 -> V_92 , V_76 ) ;
V_56 = F_52 ( V_14 , V_87 -> V_89 ,
V_87 -> V_90 ) ;
if ( V_56 ) {
V_56 -> V_87 = NULL ;
V_56 -> V_75 = NULL ;
}
F_33 ( & V_14 -> V_92 , V_76 ) ;
goto V_91;
}
F_32 ( & V_14 -> V_74 , V_76 ) ;
V_54 = F_28 ( V_14 , V_120 ) ;
if ( V_54 && ( V_54 -> V_87 == V_87 ) &&
( V_54 -> V_89 == V_87 -> V_89 ) &&
( V_54 -> V_90 == V_87 -> V_90 ) )
V_54 -> V_87 = NULL ;
if ( V_54 ) {
V_120 -> V_75 = NULL ;
F_41 ( V_54 ) ;
F_41 ( V_54 ) ;
}
F_33 ( & V_14 -> V_74 , V_76 ) ;
V_91:
F_2 ( V_120 ) ;
V_87 -> V_122 = NULL ;
}
static int
F_75 ( struct V_112 * V_75 )
{
struct V_114 * V_115 ;
struct V_13 * V_14 ;
struct V_72 * V_120 ;
struct V_118 * V_119 ;
struct V_128 * V_87 ;
struct V_55 * V_56 ;
struct V_53 * V_54 ;
unsigned long V_76 ;
V_119 = F_9 ( sizeof( * V_119 ) ,
V_132 ) ;
if ( ! V_119 )
return - V_133 ;
V_119 -> V_111 = V_75 -> V_111 ;
V_119 -> V_76 = V_143 ;
V_87 = V_128 ( V_75 ) ;
V_120 = V_87 -> V_122 ;
V_120 -> V_144 ++ ;
V_119 -> V_124 = V_120 ;
V_75 -> V_122 = V_119 ;
if ( ( V_120 -> V_76 & V_140 ) )
V_75 -> V_145 = 1 ;
V_115 = F_71 ( & V_87 -> V_129 ) ;
V_14 = F_68 ( V_115 ) ;
if ( V_87 -> V_90 == V_135 ) {
F_32 ( & V_14 -> V_92 , V_76 ) ;
V_56 = F_52 ( V_14 ,
V_87 -> V_89 , V_87 -> V_90 ) ;
if ( V_56 )
V_56 -> V_75 = V_75 ;
F_33 ( & V_14 -> V_92 , V_76 ) ;
}
if ( ! ( V_120 -> V_76 & V_125 ) ) {
F_32 ( & V_14 -> V_74 , V_76 ) ;
V_54 = F_34 ( V_14 ,
V_120 -> V_17 ) ;
if ( V_54 && ( V_54 -> V_87 == NULL ) ) {
F_76 ( V_146 , V_75 ,
L_14 ,
V_44 , __LINE__ ) ;
V_54 -> V_87 = V_87 ;
}
if ( V_54 )
F_41 ( V_54 ) ;
F_33 ( & V_14 -> V_74 , V_76 ) ;
}
return 0 ;
}
static void
F_77 ( struct V_112 * V_75 )
{
struct V_72 * V_120 ;
struct V_128 * V_87 ;
struct V_114 * V_115 ;
struct V_13 * V_14 ;
struct V_53 * V_54 ;
unsigned long V_76 ;
if ( ! V_75 -> V_122 )
return;
V_87 = V_128 ( V_75 ) ;
V_120 = V_87 -> V_122 ;
V_120 -> V_144 -- ;
V_115 = F_71 ( & V_87 -> V_129 ) ;
V_14 = F_68 ( V_115 ) ;
if ( ! ( V_120 -> V_76 & V_125 ) ) {
F_32 ( & V_14 -> V_74 , V_76 ) ;
V_54 = F_28 ( V_14 ,
V_120 ) ;
if ( V_54 && ! V_120 -> V_144 )
V_54 -> V_87 = NULL ;
if ( V_54 )
F_41 ( V_54 ) ;
F_33 ( & V_14 -> V_74 , V_76 ) ;
}
F_2 ( V_75 -> V_122 ) ;
V_75 -> V_122 = NULL ;
}
static void
F_78 ( struct V_13 * V_14 ,
T_4 V_35 , struct V_112 * V_75 )
{
T_9 V_37 ;
T_8 V_36 ;
T_10 V_38 ;
T_4 V_76 ;
T_10 V_98 ;
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
V_76 = F_21 ( V_36 . V_147 ) ;
V_98 = F_79 ( V_36 . V_148 ) ;
F_76 ( V_146 , V_75 ,
L_15
L_16 ,
( V_98 & V_149 ) ? L_17 : L_18 ,
( V_76 & V_150 ) ? L_17 : L_18 ,
( V_76 & V_151 ) ? L_17 :
L_18 ,
( V_76 & V_152 ) ? L_17 : L_18 ,
( V_76 & V_153 ) ? L_17 : L_18 ,
( V_76 & V_154 ) ? L_17 : L_18 ) ;
}
static int
F_80 ( struct V_51 * V_129 )
{
struct V_112 * V_75 = F_81 ( V_129 ) ;
struct V_13 * V_14 = F_68 ( V_75 -> V_116 ) ;
if ( V_14 -> V_136 )
return 0 ;
return ( V_75 -> V_90 == V_135 ) ? 1 : 0 ;
}
static void
F_82 ( struct V_51 * V_129 )
{
struct V_112 * V_75 = F_81 ( V_129 ) ;
struct V_13 * V_14 = F_68 ( V_75 -> V_116 ) ;
static struct V_55 * V_56 ;
unsigned long V_76 ;
T_11 V_155 ;
T_9 V_37 ;
T_10 V_156 ;
T_6 V_157 ;
T_4 V_35 ;
V_157 = 0 ;
V_35 = 0 ;
if ( V_14 -> V_136 )
goto V_91;
F_32 ( & V_14 -> V_92 , V_76 ) ;
V_56 = F_52 ( V_14 , V_75 -> V_89 ,
V_75 -> V_90 ) ;
if ( V_56 ) {
V_35 = V_56 -> V_35 ;
V_157 = V_56 -> V_157 ;
}
F_33 ( & V_14 -> V_92 , V_76 ) ;
if ( ! V_35 )
goto V_91;
if ( F_83 ( V_14 , & V_37 , & V_155 ,
V_158 , V_35 ,
sizeof( T_11 ) ) ) {
F_25 ( V_42 L_2 ,
V_14 -> V_43 , __FILE__ , __LINE__ , V_44 ) ;
V_157 = 0 ;
goto V_91;
}
V_156 = F_79 ( V_155 . V_159 ) ;
if ( ! ( V_156 &
V_160 ) )
V_157 = 0 ;
V_91:
switch ( V_14 -> V_161 ) {
case V_162 :
F_84 ( V_163 , V_129 , V_157 ) ;
break;
case V_164 :
case V_165 :
F_84 ( V_166 , V_129 , V_157 ) ;
break;
}
}
static void
F_85 ( struct V_51 * V_129 )
{
struct V_112 * V_75 = F_81 ( V_129 ) ;
struct V_13 * V_14 = F_68 ( V_75 -> V_116 ) ;
static struct V_55 * V_56 ;
unsigned long V_76 ;
T_11 V_155 ;
T_9 V_37 ;
T_10 V_167 ;
enum V_168 V_169 = V_170 ;
T_4 V_35 = 0 ;
F_32 ( & V_14 -> V_92 , V_76 ) ;
V_56 = F_52 ( V_14 , V_75 -> V_89 ,
V_75 -> V_90 ) ;
if ( V_56 )
V_35 = V_56 -> V_35 ;
F_33 ( & V_14 -> V_92 , V_76 ) ;
if ( ! V_56 )
goto V_91;
if ( F_83 ( V_14 , & V_37 , & V_155 ,
V_158 , V_35 ,
sizeof( T_11 ) ) ) {
F_25 ( V_42 L_2 ,
V_14 -> V_43 , __FILE__ , __LINE__ , V_44 ) ;
goto V_91;
}
V_167 = F_79 ( V_155 . V_159 ) ;
if ( V_167 & V_160 ) {
V_169 = V_171 ;
goto V_91;
}
switch ( V_155 . V_172 ) {
case V_173 :
case V_174 :
V_169 = V_175 ;
break;
case V_176 :
V_169 = V_177 ;
break;
case V_178 :
case V_179 :
V_169 = V_180 ;
break;
}
V_91:
switch ( V_14 -> V_161 ) {
case V_162 :
F_86 ( V_163 , V_129 , V_169 ) ;
break;
case V_164 :
case V_165 :
F_86 ( V_166 , V_129 , V_169 ) ;
break;
}
}
static void
F_87 ( struct V_13 * V_14 ,
struct V_112 * V_75 , T_6 V_181 )
{
enum V_182 V_183 = V_184 ;
switch ( V_181 ) {
case V_185 :
V_183 = V_186 ;
break;
case V_187 :
V_183 = V_188 ;
break;
case V_189 :
V_183 = V_190 ;
break;
case V_191 :
V_183 = V_192 ;
break;
}
switch ( V_14 -> V_161 ) {
case V_162 :
F_88 ( V_163 ,
& V_75 -> V_193 , V_183 ) ;
break;
case V_164 :
case V_165 :
F_88 ( V_166 ,
& V_75 -> V_193 , V_183 ) ;
break;
}
}
static int
F_89 ( struct V_13 * V_14 ,
struct V_55 * V_56 )
{
T_11 * V_155 ;
T_12 V_194 ;
T_8 V_36 ;
T_9 V_37 ;
T_4 V_195 ;
T_6 V_196 ;
if ( ( F_90 ( V_14 , V_56 -> V_35 ,
& V_196 ) ) || ! V_196 ) {
F_91 ( V_14 , F_92 ( V_42
L_2 , V_14 -> V_43 , __FILE__ , __LINE__ ,
V_44 ) ) ;
return 1 ;
}
V_56 -> V_196 = V_196 ;
V_195 = F_93 ( T_11 , V_197 ) + ( V_196 *
sizeof( V_198 ) ) ;
V_155 = F_9 ( V_195 , V_132 ) ;
if ( ! V_155 ) {
F_91 ( V_14 , F_92 ( V_42
L_2 , V_14 -> V_43 , __FILE__ , __LINE__ ,
V_44 ) ) ;
return 1 ;
}
if ( ( F_83 ( V_14 , & V_37 , V_155 ,
V_158 , V_56 -> V_35 , V_195 ) ) ) {
F_91 ( V_14 , F_92 ( V_42
L_2 , V_14 -> V_43 , __FILE__ , __LINE__ ,
V_44 ) ) ;
F_2 ( V_155 ) ;
return 1 ;
}
V_56 -> V_181 = V_155 -> V_199 ;
if ( ! ( F_94 ( V_14 , & V_37 ,
& V_194 , V_200 ,
V_155 -> V_197 [ 0 ] . V_201 ) ) ) {
if ( ! ( F_24 ( V_14 , & V_37 ,
& V_36 , V_41 ,
F_21 ( V_194 . V_202 ) ) ) ) {
V_56 -> V_98 =
F_79 ( V_36 . V_148 ) ;
}
}
F_2 ( V_155 ) ;
return 0 ;
}
static void
F_95 ( struct V_13 * V_14 , struct V_112 * V_75 )
{
if ( V_75 -> type != V_203 )
return;
if ( ! ( V_14 -> V_204 . V_205 & V_206 ) )
return;
F_96 ( V_75 ) ;
F_76 ( V_146 , V_75 , L_19 ,
F_97 ( V_75 ) ? L_20 : L_21 ) ;
return;
}
static int
F_98 ( struct V_112 * V_75 )
{
struct V_114 * V_115 = V_75 -> V_116 ;
struct V_13 * V_14 = F_68 ( V_115 ) ;
struct V_118 * V_119 ;
struct V_72 * V_120 ;
struct V_53 * V_54 ;
struct V_55 * V_56 ;
unsigned long V_76 ;
int V_113 ;
T_6 V_207 = 0 ;
char * V_208 = L_22 ;
char * V_209 = L_22 ;
T_4 V_35 , V_210 = 0 ;
T_1 V_211 = 0 ;
V_113 = 1 ;
V_119 = V_75 -> V_122 ;
V_119 -> V_212 = 1 ;
V_119 -> V_76 &= ~ V_143 ;
V_120 = V_119 -> V_124 ;
V_35 = V_120 -> V_35 ;
if ( V_120 -> V_76 & V_125 ) {
F_32 ( & V_14 -> V_92 , V_76 ) ;
V_56 = F_53 ( V_14 , V_35 ) ;
F_33 ( & V_14 -> V_92 , V_76 ) ;
if ( ! V_56 ) {
F_91 ( V_14 , F_92 ( V_42
L_2 , V_14 -> V_43 , __FILE__ ,
__LINE__ , V_44 ) ) ;
return 1 ;
}
if ( F_89 ( V_14 , V_56 ) ) {
F_91 ( V_14 , F_92 ( V_42
L_2 , V_14 -> V_43 , __FILE__ ,
__LINE__ , V_44 ) ) ;
return 1 ;
}
F_99 ( V_14 , V_56 ) ;
if ( V_56 -> V_98 &
V_100 ) {
V_113 = V_213 ;
V_208 = L_23 ;
} else {
V_113 = V_126 ;
if ( V_56 -> V_98 &
V_102 )
V_208 = L_24 ;
else
V_208 = L_25 ;
}
switch ( V_56 -> V_181 ) {
case V_185 :
V_209 = L_26 ;
break;
case V_189 :
V_113 = V_214 ;
if ( V_14 -> V_215 . V_216 &&
( F_79 ( V_14 -> V_215 . V_217 ) &
V_218 ) &&
! ( V_56 -> V_196 % 2 ) )
V_209 = L_27 ;
else
V_209 = L_28 ;
break;
case V_191 :
V_113 = V_214 ;
V_209 = L_29 ;
break;
case V_187 :
V_113 = V_214 ;
V_209 = L_27 ;
break;
case V_219 :
default:
V_113 = V_214 ;
V_209 = L_30 ;
break;
}
if ( ! V_14 -> V_220 )
F_76 ( V_146 , V_75 ,
L_31
L_32 ,
V_209 , V_56 -> V_35 ,
( unsigned long long ) V_56 -> V_60 ,
V_56 -> V_196 , V_208 ) ;
if ( V_115 -> V_221 > V_222 ) {
F_100 ( V_75 -> V_223 ,
V_222 ) ;
F_76 ( V_146 , V_75 ,
L_33 ,
V_222 ) ;
}
F_67 ( V_75 , V_113 ) ;
if ( ! V_14 -> V_136 )
F_87 ( V_14 , V_75 , V_56 -> V_181 ) ;
return 0 ;
}
if ( V_120 -> V_76 & V_140 ) {
if ( F_101 ( V_14 , V_35 ,
& V_210 ) ) {
F_91 ( V_14 , F_92 ( V_42
L_2 , V_14 -> V_43 ,
__FILE__ , __LINE__ , V_44 ) ) ;
return 1 ;
}
if ( V_210 && F_102 ( V_14 ,
V_210 , & V_211 ) ) {
F_91 ( V_14 , F_92 ( V_42
L_2 , V_14 -> V_43 ,
__FILE__ , __LINE__ , V_44 ) ) ;
return 1 ;
}
}
F_32 ( & V_14 -> V_74 , V_76 ) ;
V_54 = F_34 ( V_14 ,
V_119 -> V_124 -> V_17 ) ;
if ( ! V_54 ) {
F_33 ( & V_14 -> V_74 , V_76 ) ;
F_91 ( V_14 , F_92 ( V_42
L_2 , V_14 -> V_43 , __FILE__ , __LINE__ ,
V_44 ) ) ;
return 1 ;
}
V_54 -> V_210 = V_210 ;
V_54 -> V_211 = V_211 ;
if ( V_54 -> V_98 & V_100 ) {
V_113 = V_213 ;
V_207 = 1 ;
if ( V_54 -> V_98 &
V_224 ) {
F_76 ( V_225 , V_75 ,
L_34 ,
V_119 -> V_124 -> V_35 ) ;
V_119 -> V_226 = 1 ;
V_208 = L_35 ;
} else
V_208 = L_23 ;
} else {
V_113 = V_126 ;
if ( V_54 -> V_98 & V_101 )
V_208 = L_25 ;
else if ( V_54 -> V_98 &
V_102 )
V_208 = L_24 ;
}
F_76 ( V_146 , V_75 , L_36 \
L_37 ,
V_208 , V_35 , ( unsigned long long ) V_54 -> V_17 ,
V_54 -> V_227 , ( unsigned long long ) V_54 -> V_20 ) ;
if ( V_54 -> V_78 != 0 )
F_76 ( V_146 , V_75 ,
L_38 ,
V_208 , ( unsigned long long )
V_54 -> V_22 , V_54 -> V_26 ) ;
if ( V_54 -> V_79 [ 0 ] != '\0' )
F_76 ( V_146 , V_75 ,
L_12 ,
V_208 , V_54 -> V_80 ,
V_54 -> V_79 ) ;
F_41 ( V_54 ) ;
F_33 ( & V_14 -> V_74 , V_76 ) ;
if ( ! V_207 )
F_78 ( V_14 , V_35 , V_75 ) ;
F_67 ( V_75 , V_113 ) ;
if ( V_207 ) {
F_103 ( V_75 ) ;
F_95 ( V_14 , V_75 ) ;
}
return 0 ;
}
static int
F_104 ( struct V_112 * V_75 , struct V_228 * V_229 ,
T_13 V_230 , int V_231 [] )
{
int V_232 ;
int V_233 ;
T_13 V_234 ;
T_14 V_235 ;
V_232 = 64 ;
V_233 = 32 ;
V_235 = V_232 * V_233 ;
V_234 = V_230 ;
F_105 ( V_234 , V_235 ) ;
if ( ( T_14 ) V_230 >= 0x200000 ) {
V_232 = 255 ;
V_233 = 63 ;
V_235 = V_232 * V_233 ;
V_234 = V_230 ;
F_105 ( V_234 , V_235 ) ;
}
V_231 [ 0 ] = V_232 ;
V_231 [ 1 ] = V_233 ;
V_231 [ 2 ] = V_234 ;
return 0 ;
}
static void
F_106 ( struct V_13 * V_14 , T_6 V_236 )
{
char * V_237 ;
switch ( V_236 ) {
case V_238 :
V_237 = L_39 ;
break;
case V_239 :
V_237 = L_40 ;
break;
case V_240 :
V_237 = L_41 ;
break;
case V_241 :
V_237 = L_42 ;
break;
case V_242 :
V_237 = L_43 ;
break;
case V_243 :
V_237 = L_44 ;
break;
case 0xA :
V_237 = L_45 ;
break;
case V_244 :
V_237 = L_46 ;
break;
default:
V_237 = L_47 ;
break;
}
F_92 ( V_42 L_48 ,
V_14 -> V_43 , V_236 , V_237 ) ;
}
static T_6
F_107 ( struct V_13 * V_14 , T_4 V_104 , T_6 V_245 , T_10 V_246 )
{
T_15 * V_37 ;
if ( V_14 -> V_247 . V_248 == V_249 )
return 1 ;
if ( V_14 -> V_247 . V_104 != V_104 )
return 1 ;
V_14 -> V_247 . V_248 |= V_250 ;
V_37 = F_108 ( V_14 , V_246 ) ;
if ( V_37 ) {
memcpy ( V_14 -> V_247 . V_246 , V_37 , V_37 -> V_251 * 4 ) ;
V_14 -> V_247 . V_248 |= V_252 ;
}
V_14 -> V_247 . V_248 &= ~ V_253 ;
F_109 ( & V_14 -> V_247 . V_254 ) ;
return 1 ;
}
void
F_110 ( struct V_13 * V_14 , T_4 V_35 )
{
struct V_118 * V_119 ;
struct V_112 * V_75 ;
T_6 V_255 = 0 ;
F_111 (sdev, ioc->shost) {
if ( V_255 )
continue;
V_119 = V_75 -> V_122 ;
if ( ! V_119 )
continue;
if ( V_119 -> V_124 -> V_35 == V_35 ) {
V_119 -> V_124 -> V_256 = 1 ;
V_255 = 1 ;
V_14 -> V_257 = 1 ;
}
}
}
void
F_112 ( struct V_13 * V_14 , T_4 V_35 )
{
struct V_118 * V_119 ;
struct V_112 * V_75 ;
T_6 V_255 = 0 ;
F_111 (sdev, ioc->shost) {
if ( V_255 )
continue;
V_119 = V_75 -> V_122 ;
if ( ! V_119 )
continue;
if ( V_119 -> V_124 -> V_35 == V_35 ) {
V_119 -> V_124 -> V_256 = 0 ;
V_255 = 1 ;
V_14 -> V_257 = 0 ;
}
}
}
int
F_113 ( struct V_13 * V_14 , T_4 V_35 , T_16 V_90 ,
T_16 V_89 , T_16 V_111 , T_6 type , T_4 V_258 , T_14 V_259 )
{
T_17 * V_260 ;
T_18 * V_37 ;
T_4 V_104 = 0 ;
T_10 V_261 ;
struct V_262 * V_105 = NULL ;
int V_28 ;
T_4 V_263 = 0 ;
F_114 ( & V_14 -> V_247 . V_264 ) ;
if ( V_14 -> V_247 . V_248 != V_249 ) {
F_13 ( V_42 L_49 ,
V_44 , V_14 -> V_43 ) ;
return V_265 ;
}
if ( V_14 -> V_82 || V_14 -> V_266 ||
V_14 -> V_267 ) {
F_13 ( V_42 L_50 ,
V_44 , V_14 -> V_43 ) ;
return V_265 ;
}
V_261 = F_115 ( V_14 , 0 ) ;
if ( V_261 & V_268 ) {
F_116 ( V_14 , F_13 ( V_42
L_51 , V_14 -> V_43 ) ) ;
V_28 = F_117 ( V_14 , V_269 ) ;
return ( ! V_28 ) ? V_270 : V_265 ;
}
if ( ( V_261 & V_271 ) == V_272 ) {
F_118 ( V_14 , V_261 &
V_273 ) ;
V_28 = F_117 ( V_14 , V_269 ) ;
return ( ! V_28 ) ? V_270 : V_265 ;
}
V_104 = F_119 ( V_14 , V_14 -> V_274 ) ;
if ( ! V_104 ) {
F_25 ( V_42 L_52 ,
V_14 -> V_43 , V_44 ) ;
return V_265 ;
}
if ( type == V_275 )
V_105 = & V_14 -> V_105 [ V_258 - 1 ] ;
F_120 ( V_14 , F_13 ( V_42
L_53 ,
V_14 -> V_43 , V_35 , type , V_258 ) ) ;
V_14 -> V_247 . V_248 = V_253 ;
V_260 = F_121 ( V_14 , V_104 ) ;
V_14 -> V_247 . V_104 = V_104 ;
memset ( V_260 , 0 , sizeof( T_17 ) ) ;
memset ( V_14 -> V_247 . V_246 , 0 , sizeof( T_18 ) ) ;
V_260 -> V_276 = V_277 ;
V_260 -> V_202 = F_122 ( V_35 ) ;
V_260 -> V_278 = type ;
V_260 -> V_279 = F_122 ( V_258 ) ;
F_123 ( V_111 , (struct V_280 * ) V_260 -> V_281 ) ;
F_110 ( V_14 , V_35 ) ;
F_124 ( & V_14 -> V_247 . V_254 ) ;
if ( ( type == V_275 ) &&
( V_105 -> V_282 < V_14 -> V_283 ) )
V_263 = V_105 -> V_282 ;
else
V_263 = 0 ;
V_14 -> V_284 ( V_14 , V_104 , V_263 ) ;
F_125 ( & V_14 -> V_247 . V_254 , V_259 * V_285 ) ;
if ( ! ( V_14 -> V_247 . V_248 & V_250 ) ) {
F_25 ( V_42 L_54 ,
V_14 -> V_43 , V_44 ) ;
F_126 ( V_260 ,
sizeof( T_17 ) / 4 ) ;
if ( ! ( V_14 -> V_247 . V_248 & V_286 ) ) {
V_28 = F_117 ( V_14 ,
V_269 ) ;
V_28 = ( ! V_28 ) ? V_270 : V_265 ;
goto V_91;
}
}
F_127 ( V_14 ) ;
if ( V_14 -> V_247 . V_248 & V_252 ) {
F_128 ( V_14 , V_287 ) ;
V_37 = V_14 -> V_247 . V_246 ;
F_120 ( V_14 , F_13 ( V_42 L_55 \
L_56 ,
V_14 -> V_43 , F_21 ( V_37 -> V_46 ) ,
F_79 ( V_37 -> V_288 ) ,
F_79 ( V_37 -> V_289 ) ) ) ;
if ( V_14 -> V_15 & V_290 ) {
F_106 ( V_14 , V_37 -> V_291 ) ;
if ( V_37 -> V_46 )
F_126 ( V_260 ,
sizeof( T_17 ) / 4 ) ;
}
}
switch ( type ) {
case V_275 :
V_28 = V_270 ;
if ( V_105 -> V_106 == NULL )
break;
V_28 = V_265 ;
break;
case V_292 :
if ( F_65 ( V_14 , V_89 , V_90 ) )
V_28 = V_265 ;
else
V_28 = V_270 ;
break;
case V_293 :
case V_294 :
if ( F_66 ( V_14 , V_89 , V_111 , V_90 ) )
V_28 = V_265 ;
else
V_28 = V_270 ;
break;
case V_295 :
V_28 = V_270 ;
break;
default:
V_28 = V_265 ;
break;
}
V_91:
F_112 ( V_14 , V_35 ) ;
V_14 -> V_247 . V_248 = V_249 ;
return V_28 ;
}
int F_129 ( struct V_13 * V_14 , T_4 V_35 ,
T_16 V_90 , T_16 V_89 , T_16 V_111 , T_6 type , T_4 V_258 , T_14 V_259 )
{
int V_12 ;
F_130 ( & V_14 -> V_247 . V_264 ) ;
V_12 = F_113 ( V_14 , V_35 , V_90 , V_89 , V_111 , type ,
V_258 , V_259 ) ;
F_131 ( & V_14 -> V_247 . V_264 ) ;
return V_12 ;
}
static void
F_132 ( struct V_13 * V_14 , struct V_103 * V_106 )
{
struct V_128 * V_87 = V_106 -> V_51 -> V_296 ;
struct V_72 * V_297 = V_87 -> V_122 ;
struct V_53 * V_54 = NULL ;
unsigned long V_76 ;
char * V_298 = NULL ;
if ( ! V_297 )
return;
if ( V_14 -> V_220 )
V_298 = L_57 ;
else
V_298 = L_58 ;
F_133 ( V_106 ) ;
if ( V_297 -> V_76 & V_125 ) {
F_134 ( V_146 , V_87 ,
L_59 ,
V_298 , V_297 -> V_35 ,
V_298 , ( unsigned long long ) V_297 -> V_17 ) ;
} else {
F_32 ( & V_14 -> V_74 , V_76 ) ;
V_54 = F_28 ( V_14 , V_297 ) ;
if ( V_54 ) {
if ( V_297 -> V_76 &
V_140 ) {
F_134 ( V_146 , V_87 ,
L_60
L_61 ,
V_54 -> V_210 ,
( unsigned long long ) V_54 -> V_211 ) ;
}
F_134 ( V_146 , V_87 ,
L_62 ,
V_54 -> V_35 ,
( unsigned long long ) V_54 -> V_17 ,
V_54 -> V_227 ) ;
if ( V_54 -> V_78 != 0 )
F_134 ( V_146 , V_87 ,
L_63 ,
( unsigned long long )
V_54 -> V_22 ,
V_54 -> V_26 ) ;
if ( V_54 -> V_79 [ 0 ] != '\0' )
F_134 ( V_146 , V_87 ,
L_64 ,
V_54 -> V_80 ,
V_54 -> V_79 ) ;
F_41 ( V_54 ) ;
}
F_33 ( & V_14 -> V_74 , V_76 ) ;
}
}
static int
F_135 ( struct V_103 * V_106 )
{
struct V_13 * V_14 = F_68 ( V_106 -> V_51 -> V_116 ) ;
struct V_118 * V_119 ;
T_4 V_104 ;
T_4 V_35 ;
int V_2 ;
F_76 ( V_146 , V_106 -> V_51 ,
L_65 , V_106 ) ;
F_132 ( V_14 , V_106 ) ;
V_119 = V_106 -> V_51 -> V_122 ;
if ( ! V_119 || ! V_119 -> V_124 ) {
F_76 ( V_146 , V_106 -> V_51 ,
L_66 , V_106 ) ;
V_106 -> V_299 = V_300 << 16 ;
V_106 -> V_301 ( V_106 ) ;
V_2 = V_270 ;
goto V_91;
}
V_104 = F_64 ( V_14 , V_106 ) ;
if ( ! V_104 ) {
V_106 -> V_299 = V_302 << 16 ;
V_2 = V_270 ;
goto V_91;
}
if ( V_119 -> V_124 -> V_76 &
V_140 ||
V_119 -> V_124 -> V_76 & V_125 ) {
V_106 -> V_299 = V_302 << 16 ;
V_2 = V_265 ;
goto V_91;
}
F_136 ( V_14 ) ;
V_35 = V_119 -> V_124 -> V_35 ;
V_2 = F_129 ( V_14 , V_35 , V_106 -> V_51 -> V_90 ,
V_106 -> V_51 -> V_89 , V_106 -> V_51 -> V_111 ,
V_275 , V_104 , 30 ) ;
V_91:
F_76 ( V_146 , V_106 -> V_51 , L_67 ,
( ( V_2 == V_270 ) ? L_68 : L_69 ) , V_106 ) ;
return V_2 ;
}
static int
F_137 ( struct V_103 * V_106 )
{
struct V_13 * V_14 = F_68 ( V_106 -> V_51 -> V_116 ) ;
struct V_118 * V_119 ;
struct V_53 * V_54 = NULL ;
T_4 V_35 ;
int V_2 ;
struct V_128 * V_87 = V_106 -> V_51 -> V_296 ;
struct V_72 * V_303 = V_87 -> V_122 ;
F_76 ( V_146 , V_106 -> V_51 ,
L_70 , V_106 ) ;
F_132 ( V_14 , V_106 ) ;
V_119 = V_106 -> V_51 -> V_122 ;
if ( ! V_119 || ! V_119 -> V_124 ) {
F_76 ( V_146 , V_106 -> V_51 ,
L_66 , V_106 ) ;
V_106 -> V_299 = V_300 << 16 ;
V_106 -> V_301 ( V_106 ) ;
V_2 = V_270 ;
goto V_91;
}
V_35 = 0 ;
if ( V_119 -> V_124 -> V_76 &
V_140 ) {
V_54 = F_31 ( V_14 ,
V_303 ) ;
if ( V_54 )
V_35 = V_54 -> V_210 ;
} else
V_35 = V_119 -> V_124 -> V_35 ;
if ( ! V_35 ) {
V_106 -> V_299 = V_302 << 16 ;
V_2 = V_265 ;
goto V_91;
}
V_2 = F_129 ( V_14 , V_35 , V_106 -> V_51 -> V_90 ,
V_106 -> V_51 -> V_89 , V_106 -> V_51 -> V_111 ,
V_294 , 0 , 30 ) ;
V_91:
F_76 ( V_146 , V_106 -> V_51 , L_71 ,
( ( V_2 == V_270 ) ? L_68 : L_69 ) , V_106 ) ;
if ( V_54 )
F_41 ( V_54 ) ;
return V_2 ;
}
static int
F_138 ( struct V_103 * V_106 )
{
struct V_13 * V_14 = F_68 ( V_106 -> V_51 -> V_116 ) ;
struct V_118 * V_119 ;
struct V_53 * V_54 = NULL ;
T_4 V_35 ;
int V_2 ;
struct V_128 * V_87 = V_106 -> V_51 -> V_296 ;
struct V_72 * V_303 = V_87 -> V_122 ;
F_134 ( V_146 , V_87 , L_72 ,
V_106 ) ;
F_132 ( V_14 , V_106 ) ;
V_119 = V_106 -> V_51 -> V_122 ;
if ( ! V_119 || ! V_119 -> V_124 ) {
F_134 ( V_146 , V_87 , L_73 ,
V_106 ) ;
V_106 -> V_299 = V_300 << 16 ;
V_106 -> V_301 ( V_106 ) ;
V_2 = V_270 ;
goto V_91;
}
V_35 = 0 ;
if ( V_119 -> V_124 -> V_76 &
V_140 ) {
V_54 = F_31 ( V_14 ,
V_303 ) ;
if ( V_54 )
V_35 = V_54 -> V_210 ;
} else
V_35 = V_119 -> V_124 -> V_35 ;
if ( ! V_35 ) {
V_106 -> V_299 = V_302 << 16 ;
V_2 = V_265 ;
goto V_91;
}
V_2 = F_129 ( V_14 , V_35 , V_106 -> V_51 -> V_90 ,
V_106 -> V_51 -> V_89 , 0 , V_292 , 0 ,
30 ) ;
V_91:
F_134 ( V_146 , V_87 , L_74 ,
( ( V_2 == V_270 ) ? L_68 : L_69 ) , V_106 ) ;
if ( V_54 )
F_41 ( V_54 ) ;
return V_2 ;
}
static int
F_139 ( struct V_103 * V_106 )
{
struct V_13 * V_14 = F_68 ( V_106 -> V_51 -> V_116 ) ;
int V_2 , V_304 ;
F_13 ( V_42 L_75 ,
V_14 -> V_43 , V_106 ) ;
F_133 ( V_106 ) ;
if ( V_14 -> V_57 ) {
F_13 ( V_42 L_76 ,
V_14 -> V_43 ) ;
V_2 = V_265 ;
goto V_91;
}
V_304 = F_117 ( V_14 , V_269 ) ;
V_2 = ( V_304 < 0 ) ? V_265 : V_270 ;
V_91:
F_13 ( V_42 L_77 ,
V_14 -> V_43 , ( ( V_2 == V_270 ) ? L_68 : L_69 ) , V_106 ) ;
return V_2 ;
}
static void
F_140 ( struct V_13 * V_14 , struct V_3 * V_7 )
{
unsigned long V_76 ;
if ( V_14 -> V_305 == NULL )
return;
F_32 ( & V_14 -> V_306 , V_76 ) ;
F_4 ( V_7 ) ;
F_141 ( & V_7 -> V_81 ) ;
F_47 ( & V_7 -> V_81 , & V_14 -> V_307 ) ;
F_142 ( & V_7 -> V_308 , V_309 ) ;
F_4 ( V_7 ) ;
F_143 ( V_14 -> V_305 , & V_7 -> V_308 ) ;
F_33 ( & V_14 -> V_306 , V_76 ) ;
}
static void
F_144 ( struct V_13 * V_14 , struct V_3
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
F_145 ( struct V_13 * V_14 ,
struct V_310 * V_311 )
{
struct V_3 * V_7 ;
T_4 V_195 ;
if ( V_14 -> V_57 )
return;
V_195 = sizeof( * V_311 ) ;
V_7 = F_8 ( V_195 ) ;
if ( ! V_7 )
return;
V_7 -> V_312 = V_313 ;
V_7 -> V_14 = V_14 ;
memcpy ( V_7 -> V_311 , V_311 , sizeof( * V_311 ) ) ;
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
V_7 -> V_312 = V_314 ;
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
V_7 -> V_312 = V_315 ;
V_7 -> V_14 = V_14 ;
F_140 ( V_14 , V_7 ) ;
F_6 ( V_7 ) ;
}
static struct V_3 * F_148 ( struct V_13 * V_14 )
{
unsigned long V_76 ;
struct V_3 * V_7 = NULL ;
F_32 ( & V_14 -> V_306 , V_76 ) ;
if ( ! F_39 ( & V_14 -> V_307 ) ) {
V_7 = F_149 ( & V_14 -> V_307 ,
struct V_3 , V_81 ) ;
F_40 ( & V_7 -> V_81 ) ;
}
F_33 ( & V_14 -> V_306 , V_76 ) ;
return V_7 ;
}
static void
F_150 ( struct V_13 * V_14 )
{
struct V_3 * V_7 ;
if ( F_39 ( & V_14 -> V_307 ) ||
! V_14 -> V_305 || F_151 () )
return;
while ( ( V_7 = F_148 ( V_14 ) ) ) {
if ( F_152 ( & V_7 -> V_308 ) )
F_6 ( V_7 ) ;
F_6 ( V_7 ) ;
}
}
static void
F_153 ( struct V_112 * V_75 ,
struct V_118 * V_119 )
{
int V_2 = 0 ;
F_76 ( V_146 , V_75 , L_78 ,
V_119 -> V_124 -> V_35 ) ;
V_119 -> V_316 = 1 ;
V_2 = F_154 ( V_75 ) ;
if ( V_2 == - V_317 )
F_76 ( V_225 , V_75 ,
L_79 ,
V_2 , V_119 -> V_124 -> V_35 ) ;
}
static void
F_155 ( struct V_112 * V_75 ,
struct V_118 * V_119 )
{
int V_2 = 0 ;
F_76 ( V_225 , V_75 , L_80
L_81 , V_119 -> V_124 -> V_35 ) ;
V_119 -> V_316 = 0 ;
V_2 = F_156 ( V_75 , V_318 ) ;
if ( V_2 == - V_317 ) {
F_76 ( V_225 , V_75 ,
L_82
L_83 ,
V_2 , V_119 -> V_124 -> V_35 ) ;
V_119 -> V_316 = 1 ;
V_2 = F_154 ( V_75 ) ;
if ( V_2 )
F_76 ( V_225 , V_75 , L_84
L_85 ,
V_2 , V_119 -> V_124 -> V_35 ) ;
V_119 -> V_316 = 0 ;
V_2 = F_156 ( V_75 , V_318 ) ;
if ( V_2 )
F_76 ( V_225 , V_75 , L_86
L_87 ,
V_2 , V_119 -> V_124 -> V_35 ) ;
}
}
static void
F_157 ( struct V_13 * V_14 )
{
struct V_118 * V_119 ;
struct V_112 * V_75 ;
F_111 (sdev, ioc->shost) {
V_119 = V_75 -> V_122 ;
if ( ! V_119 )
continue;
if ( ! V_119 -> V_316 )
continue;
F_46 ( V_14 , F_76 ( V_146 , V_75 ,
L_88 ,
V_119 -> V_124 -> V_35 ) ) ;
F_155 ( V_75 , V_119 ) ;
}
}
static void
F_158 ( struct V_13 * V_14 , T_1 V_17 )
{
struct V_118 * V_119 ;
struct V_112 * V_75 ;
F_111 (sdev, ioc->shost) {
V_119 = V_75 -> V_122 ;
if ( ! V_119 )
continue;
if ( V_119 -> V_124 -> V_17
!= V_17 )
continue;
if ( V_119 -> V_316 )
F_155 ( V_75 ,
V_119 ) ;
}
}
static void
F_159 ( struct V_13 * V_14 )
{
struct V_118 * V_119 ;
struct V_112 * V_75 ;
F_111 (sdev, ioc->shost) {
V_119 = V_75 -> V_122 ;
if ( ! V_119 )
continue;
if ( V_119 -> V_316 )
continue;
if ( V_119 -> V_226 ) {
F_76 ( V_146 , V_75 ,
L_89 ,
V_44 , V_119 -> V_124 -> V_35 ) ;
continue;
}
F_153 ( V_75 , V_119 ) ;
}
}
static void
F_160 ( struct V_13 * V_14 , T_4 V_35 )
{
struct V_118 * V_119 ;
struct V_112 * V_75 ;
struct V_53 * V_54 ;
V_54 = F_37 ( V_14 , V_35 ) ;
if ( ! V_54 )
return;
F_111 (sdev, ioc->shost) {
V_119 = V_75 -> V_122 ;
if ( ! V_119 )
continue;
if ( V_119 -> V_124 -> V_35 != V_35 )
continue;
if ( V_119 -> V_316 )
continue;
if ( V_54 -> V_319 )
continue;
if ( V_119 -> V_226 ) {
F_76 ( V_146 , V_75 ,
L_89 ,
V_44 , V_119 -> V_124 -> V_35 ) ;
continue;
}
F_153 ( V_75 , V_119 ) ;
}
F_41 ( V_54 ) ;
}
static void
F_161 ( struct V_13 * V_14 ,
struct V_94 * V_95 )
{
struct V_320 * V_321 ;
struct V_53 * V_54 ;
struct V_94 * V_322 ;
unsigned long V_76 ;
if ( ! V_95 )
return;
F_15 (mpt3sas_port,
&sas_expander->sas_port_list, port_list) {
if ( V_321 -> V_323 . V_324 ==
V_325 ) {
F_32 ( & V_14 -> V_74 , V_76 ) ;
V_54 = F_34 ( V_14 ,
V_321 -> V_323 . V_17 ) ;
if ( V_54 ) {
F_162 ( V_54 -> V_35 ,
V_14 -> V_326 ) ;
F_41 ( V_54 ) ;
}
F_33 ( & V_14 -> V_74 , V_76 ) ;
}
}
F_15 (mpt3sas_port,
&sas_expander->sas_port_list, port_list) {
if ( V_321 -> V_323 . V_324 ==
V_327 ||
V_321 -> V_323 . V_324 ==
V_328 ) {
V_322 =
F_59 (
V_14 , V_321 -> V_323 . V_17 ) ;
F_161 ( V_14 ,
V_322 ) ;
}
}
}
static void
F_163 ( struct V_13 * V_14 ,
T_19 * V_311 )
{
int V_108 ;
T_4 V_35 ;
T_4 V_329 ;
for ( V_108 = 0 ; V_108 < V_311 -> V_330 ; V_108 ++ ) {
V_35 = F_21 ( V_311 -> V_331 [ V_108 ] . V_332 ) ;
if ( ! V_35 )
continue;
V_329 = V_311 -> V_331 [ V_108 ] . V_333 &
V_334 ;
if ( V_329 == V_335 )
F_160 ( V_14 , V_35 ) ;
}
}
static void
F_164 ( struct V_13 * V_14 , T_4 V_35 )
{
T_17 * V_260 ;
T_4 V_104 ;
struct V_53 * V_54 = NULL ;
struct V_72 * V_120 = NULL ;
T_1 V_17 = 0 ;
unsigned long V_76 ;
struct V_336 * V_337 ;
T_10 V_261 ;
if ( V_14 -> V_266 ) {
F_46 ( V_14 , F_13 ( V_42
L_90 ,
V_44 , V_14 -> V_43 , V_35 ) ) ;
return;
} else if ( V_14 -> V_267 ) {
F_46 ( V_14 , F_13 ( V_42
L_91 ,
V_44 , V_14 -> V_43 ,
V_35 ) ) ;
return;
}
V_261 = F_115 ( V_14 , 1 ) ;
if ( V_261 != V_338 ) {
F_46 ( V_14 , F_13 ( V_42
L_92 ,
V_44 , V_14 -> V_43 ,
V_35 ) ) ;
return;
}
if ( F_73 ( V_35 , V_14 -> V_139 ) )
return;
F_48 ( V_35 , V_14 -> V_85 ) ;
F_32 ( & V_14 -> V_74 , V_76 ) ;
V_54 = F_36 ( V_14 , V_35 ) ;
if ( V_54 && V_54 -> V_87 &&
V_54 -> V_87 -> V_122 ) {
V_120 = V_54 -> V_87 -> V_122 ;
V_120 -> V_339 = 1 ;
V_17 = V_54 -> V_17 ;
}
F_33 ( & V_14 -> V_74 , V_76 ) ;
if ( V_120 ) {
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
V_120 -> V_35 = V_134 ;
}
V_104 = F_119 ( V_14 , V_14 -> V_340 ) ;
if ( ! V_104 ) {
V_337 = F_9 ( sizeof( * V_337 ) , V_8 ) ;
if ( ! V_337 )
goto V_91;
F_141 ( & V_337 -> V_81 ) ;
V_337 -> V_35 = V_35 ;
F_47 ( & V_337 -> V_81 , & V_14 -> V_341 ) ;
F_46 ( V_14 , F_13 ( V_42
L_98 ,
V_14 -> V_43 , V_35 ) ) ;
goto V_91;
}
F_46 ( V_14 , F_13 ( V_42
L_99 ,
V_14 -> V_43 , V_35 , V_104 ,
V_14 -> V_340 ) ) ;
V_260 = F_121 ( V_14 , V_104 ) ;
memset ( V_260 , 0 , sizeof( T_17 ) ) ;
V_260 -> V_276 = V_277 ;
V_260 -> V_202 = F_122 ( V_35 ) ;
V_260 -> V_278 = V_292 ;
F_162 ( V_35 , V_14 -> V_342 ) ;
V_14 -> V_284 ( V_14 , V_104 , 0 ) ;
F_128 ( V_14 , V_343 ) ;
V_91:
if ( V_54 )
F_41 ( V_54 ) ;
}
static T_6
F_165 ( struct V_13 * V_14 , T_4 V_104 , T_6 V_245 ,
T_10 V_246 )
{
T_4 V_35 ;
T_17 * V_344 ;
T_18 * V_37 =
F_108 ( V_14 , V_246 ) ;
T_20 * V_260 ;
T_4 V_345 ;
T_10 V_261 ;
struct V_346 * V_347 ;
if ( V_14 -> V_266 ) {
F_46 ( V_14 , F_13 ( V_42
L_100 , V_44 , V_14 -> V_43 ) ) ;
return 1 ;
} else if ( V_14 -> V_267 ) {
F_46 ( V_14 , F_13 ( V_42
L_101 , V_44 ,
V_14 -> V_43 ) ) ;
return 1 ;
}
V_261 = F_115 ( V_14 , 1 ) ;
if ( V_261 != V_338 ) {
F_46 ( V_14 , F_13 ( V_42
L_102 , V_44 , V_14 -> V_43 ) ) ;
return 1 ;
}
if ( F_166 ( ! V_37 ) ) {
F_25 ( V_42 L_103 ,
V_14 -> V_43 , __FILE__ , __LINE__ , V_44 ) ;
return 1 ;
}
V_344 = F_121 ( V_14 , V_104 ) ;
V_35 = F_21 ( V_344 -> V_202 ) ;
if ( V_35 != F_21 ( V_37 -> V_202 ) ) {
F_46 ( V_14 , F_25 ( V_42
L_104 ,
V_14 -> V_43 , V_35 ,
F_21 ( V_37 -> V_202 ) , V_104 ) ) ;
return 0 ;
}
F_128 ( V_14 , V_287 ) ;
F_46 ( V_14 , F_13 ( V_42
L_105
L_106 , V_14 -> V_43 ,
V_35 , V_104 , F_21 ( V_37 -> V_46 ) ,
F_79 ( V_37 -> V_288 ) ,
F_79 ( V_37 -> V_289 ) ) ) ;
V_345 = F_167 ( V_14 , V_14 -> V_348 ) ;
if ( ! V_345 ) {
V_347 = F_9 ( sizeof( * V_347 ) , V_8 ) ;
if ( ! V_347 )
return F_168 ( V_14 , V_104 ) ;
F_141 ( & V_347 -> V_81 ) ;
V_347 -> V_35 = V_344 -> V_202 ;
F_47 ( & V_347 -> V_81 , & V_14 -> V_349 ) ;
F_46 ( V_14 , F_13 ( V_42
L_107 ,
V_14 -> V_43 , V_35 ) ) ;
return F_168 ( V_14 , V_104 ) ;
}
F_46 ( V_14 , F_13 ( V_42
L_108 ,
V_14 -> V_43 , V_35 , V_345 ,
V_14 -> V_348 ) ) ;
V_260 = F_121 ( V_14 , V_345 ) ;
memset ( V_260 , 0 , sizeof( T_20 ) ) ;
V_260 -> V_276 = V_350 ;
V_260 -> V_351 = V_352 ;
V_260 -> V_202 = V_344 -> V_202 ;
V_14 -> V_353 ( V_14 , V_345 ) ;
return F_168 ( V_14 , V_104 ) ;
}
static T_6
F_169 ( struct V_13 * V_14 , T_4 V_104 ,
T_6 V_245 , T_10 V_246 )
{
T_21 * V_37 =
F_108 ( V_14 , V_246 ) ;
if ( F_170 ( V_37 ) ) {
F_46 ( V_14 , F_13 ( V_42
L_109
L_110 ,
V_14 -> V_43 , F_21 ( V_37 -> V_202 ) , V_104 ,
F_21 ( V_37 -> V_46 ) ,
F_79 ( V_37 -> V_288 ) ) ) ;
if ( F_21 ( V_37 -> V_46 ) ==
V_48 ) {
F_48 ( F_21 ( V_37 -> V_202 ) ,
V_14 -> V_342 ) ;
}
} else {
F_25 ( V_42 L_103 ,
V_14 -> V_43 , __FILE__ , __LINE__ , V_44 ) ;
}
return F_171 ( V_14 , V_104 ) ;
}
static void
F_172 ( struct V_13 * V_14 , T_4 V_35 )
{
T_17 * V_260 ;
T_4 V_104 ;
struct V_336 * V_337 ;
if ( V_14 -> V_82 || V_14 -> V_266 ||
V_14 -> V_267 ) {
F_46 ( V_14 , F_13 ( V_42
L_50 ,
V_44 , V_14 -> V_43 ) ) ;
return;
}
V_104 = F_119 ( V_14 , V_14 -> V_354 ) ;
if ( ! V_104 ) {
V_337 = F_9 ( sizeof( * V_337 ) , V_8 ) ;
if ( ! V_337 )
return;
F_141 ( & V_337 -> V_81 ) ;
V_337 -> V_35 = V_35 ;
F_47 ( & V_337 -> V_81 , & V_14 -> V_355 ) ;
F_46 ( V_14 , F_13 ( V_42
L_98 ,
V_14 -> V_43 , V_35 ) ) ;
return;
}
F_46 ( V_14 , F_13 ( V_42
L_99 ,
V_14 -> V_43 , V_35 , V_104 ,
V_14 -> V_354 ) ) ;
V_260 = F_121 ( V_14 , V_104 ) ;
memset ( V_260 , 0 , sizeof( T_17 ) ) ;
V_260 -> V_276 = V_277 ;
V_260 -> V_202 = F_122 ( V_35 ) ;
V_260 -> V_278 = V_292 ;
V_14 -> V_284 ( V_14 , V_104 , 0 ) ;
}
static T_6
F_173 ( struct V_13 * V_14 , T_4 V_104 ,
T_6 V_245 , T_10 V_246 )
{
T_4 V_35 ;
T_17 * V_344 ;
T_18 * V_37 =
F_108 ( V_14 , V_246 ) ;
if ( V_14 -> V_82 || V_14 -> V_266 ||
V_14 -> V_267 ) {
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
V_344 = F_121 ( V_14 , V_104 ) ;
V_35 = F_21 ( V_344 -> V_202 ) ;
if ( V_35 != F_21 ( V_37 -> V_202 ) ) {
F_46 ( V_14 , F_25 ( V_42
L_104 ,
V_14 -> V_43 , V_35 ,
F_21 ( V_37 -> V_202 ) , V_104 ) ) ;
return 0 ;
}
F_46 ( V_14 , F_13 ( V_42
L_105
L_106 , V_14 -> V_43 ,
V_35 , V_104 , F_21 ( V_37 -> V_46 ) ,
F_79 ( V_37 -> V_288 ) ,
F_79 ( V_37 -> V_289 ) ) ) ;
return F_168 ( V_14 , V_104 ) ;
}
static void
F_174 ( struct V_13 * V_14 , T_4 V_104 , T_4 V_312 ,
T_10 V_356 )
{
T_22 * V_357 ;
int V_108 = V_104 - V_14 -> V_358 ;
unsigned long V_76 ;
F_32 ( & V_14 -> V_107 , V_76 ) ;
V_14 -> V_359 [ V_108 ] . V_360 = V_14 -> V_361 ;
F_33 ( & V_14 -> V_107 , V_76 ) ;
F_46 ( V_14 , F_13 ( V_42
L_111 ,
V_14 -> V_43 , F_21 ( V_312 ) , V_104 ,
V_14 -> V_361 ) ) ;
V_357 = F_121 ( V_14 , V_104 ) ;
memset ( V_357 , 0 , sizeof( T_22 ) ) ;
V_357 -> V_276 = V_362 ;
V_357 -> V_363 = V_312 ;
V_357 -> V_364 = V_356 ;
V_357 -> V_365 = 0 ;
V_357 -> V_366 = 0 ;
V_14 -> V_353 ( V_14 , V_104 ) ;
}
static void
F_175 ( struct V_13 * V_14 ,
T_4 V_104 , T_4 V_35 )
{
T_20 * V_260 ;
T_10 V_261 ;
int V_108 = V_104 - V_14 -> V_358 ;
unsigned long V_76 ;
if ( V_14 -> V_266 ) {
F_46 ( V_14 , F_13 ( V_42
L_100 ,
V_44 , V_14 -> V_43 ) ) ;
return;
} else if ( V_14 -> V_267 ) {
F_46 ( V_14 , F_13 ( V_42
L_101 ,
V_44 , V_14 -> V_43 ) ) ;
return;
}
V_261 = F_115 ( V_14 , 1 ) ;
if ( V_261 != V_338 ) {
F_46 ( V_14 , F_13 ( V_42
L_102 ,
V_44 , V_14 -> V_43 ) ) ;
return;
}
F_32 ( & V_14 -> V_107 , V_76 ) ;
V_14 -> V_359 [ V_108 ] . V_360 = V_14 -> V_348 ;
F_33 ( & V_14 -> V_107 , V_76 ) ;
F_46 ( V_14 , F_13 ( V_42
L_108 ,
V_14 -> V_43 , F_21 ( V_35 ) , V_104 ,
V_14 -> V_348 ) ) ;
V_260 = F_121 ( V_14 , V_104 ) ;
memset ( V_260 , 0 , sizeof( T_20 ) ) ;
V_260 -> V_276 = V_350 ;
V_260 -> V_351 = V_352 ;
V_260 -> V_202 = V_35 ;
V_14 -> V_353 ( V_14 , V_104 ) ;
}
T_6
F_171 ( struct V_13 * V_14 , T_4 V_104 )
{
struct V_346 * V_347 ;
struct V_367 * V_368 ;
if ( ! F_39 ( & V_14 -> V_369 ) ) {
V_368 = F_176 ( V_14 -> V_369 . V_370 ,
struct V_367 , V_81 ) ;
F_174 ( V_14 , V_104 ,
V_368 -> V_363 , V_368 -> V_364 ) ;
F_57 ( & V_368 -> V_81 ) ;
F_2 ( V_368 ) ;
return 0 ;
}
if ( ! F_39 ( & V_14 -> V_349 ) ) {
V_347 = F_176 ( V_14 -> V_349 . V_370 ,
struct V_346 , V_81 ) ;
F_175 ( V_14 , V_104 ,
V_347 -> V_35 ) ;
F_57 ( & V_347 -> V_81 ) ;
F_2 ( V_347 ) ;
return 0 ;
}
return 1 ;
}
static T_6
F_168 ( struct V_13 * V_14 , T_4 V_104 )
{
struct V_336 * V_337 ;
if ( ! F_39 ( & V_14 -> V_355 ) ) {
V_337 = F_176 ( V_14 -> V_355 . V_370 ,
struct V_336 , V_81 ) ;
F_177 ( V_14 , V_104 ) ;
F_172 ( V_14 , V_337 -> V_35 ) ;
F_57 ( & V_337 -> V_81 ) ;
F_2 ( V_337 ) ;
return 0 ;
}
if ( ! F_39 ( & V_14 -> V_341 ) ) {
V_337 = F_176 ( V_14 -> V_341 . V_370 ,
struct V_336 , V_81 ) ;
F_177 ( V_14 , V_104 ) ;
F_164 ( V_14 , V_337 -> V_35 ) ;
F_57 ( & V_337 -> V_81 ) ;
F_2 ( V_337 ) ;
return 0 ;
}
return 1 ;
}
static void
F_178 ( struct V_13 * V_14 ,
T_19 * V_311 )
{
struct V_3 * V_7 ;
T_19 * V_371 ;
T_4 V_372 ;
struct V_94 * V_95 ;
unsigned long V_76 ;
int V_108 , V_329 ;
T_4 V_35 ;
for ( V_108 = 0 ; V_108 < V_311 -> V_330 ; V_108 ++ ) {
V_35 = F_21 ( V_311 -> V_331 [ V_108 ] . V_332 ) ;
if ( ! V_35 )
continue;
V_329 = V_311 -> V_331 [ V_108 ] . V_333 &
V_334 ;
if ( V_329 == V_373 )
F_164 ( V_14 , V_35 ) ;
}
V_372 = F_21 ( V_311 -> V_374 ) ;
if ( V_372 < V_14 -> V_39 . V_40 ) {
F_163 ( V_14 , V_311 ) ;
return;
}
if ( V_311 -> V_375 ==
V_376 ) {
F_32 ( & V_14 -> V_96 , V_76 ) ;
V_95 = F_58 ( V_14 ,
V_372 ) ;
F_161 ( V_14 , V_95 ) ;
F_33 ( & V_14 -> V_96 , V_76 ) ;
do {
V_35 = F_179 ( V_14 -> V_326 ,
V_14 -> V_204 . V_377 ) ;
if ( V_35 < V_14 -> V_204 . V_377 )
F_160 ( V_14 , V_35 ) ;
} while ( F_180 ( V_35 , V_14 -> V_326 ) );
} else if ( V_311 -> V_375 == V_378 )
F_163 ( V_14 , V_311 ) ;
if ( V_311 -> V_375 != V_379 )
return;
F_32 ( & V_14 -> V_306 , V_76 ) ;
F_15 (fw_event, &ioc->fw_event_list, list) {
if ( V_7 -> V_312 != V_380 ||
V_7 -> V_381 )
continue;
V_371 = ( T_19 * )
V_7 -> V_311 ;
if ( V_371 -> V_375 ==
V_382 ||
V_371 -> V_375 ==
V_378 ) {
if ( F_21 ( V_371 -> V_374 ) ==
V_372 ) {
F_46 ( V_14 , F_13 ( V_42
L_112 , V_14 -> V_43 ) ) ;
V_7 -> V_381 = 1 ;
}
}
}
F_33 ( & V_14 -> V_306 , V_76 ) ;
}
static void
F_181 ( struct V_13 * V_14 , T_4 V_35 )
{
struct V_55 * V_56 ;
struct V_72 * V_120 ;
unsigned long V_76 ;
F_32 ( & V_14 -> V_92 , V_76 ) ;
V_56 = F_53 ( V_14 , V_35 ) ;
if ( V_56 && V_56 -> V_87 &&
V_56 -> V_87 -> V_122 ) {
V_120 =
V_56 -> V_87 -> V_122 ;
V_120 -> V_339 = 1 ;
F_46 ( V_14 , F_13 ( V_42
L_113
L_114 , V_14 -> V_43 , V_35 ,
( unsigned long long ) V_56 -> V_60 ) ) ;
}
F_33 ( & V_14 -> V_92 , V_76 ) ;
}
static void
F_182 ( T_4 V_35 , T_4 * V_383 , T_4 * V_384 )
{
if ( ! V_35 || V_35 == * V_383 || V_35 == * V_384 )
return;
if ( ! * V_383 )
* V_383 = V_35 ;
else if ( ! * V_384 )
* V_384 = V_35 ;
}
static void
F_183 ( struct V_13 * V_14 ,
T_23 * V_311 )
{
T_24 * V_385 ;
int V_108 ;
T_4 V_35 , V_210 , V_383 , V_384 ;
struct V_336 * V_337 ;
V_383 = 0 ;
V_384 = 0 ;
if ( V_14 -> V_136 )
return;
V_385 = ( T_24 * ) & V_311 -> V_386 [ 0 ] ;
for ( V_108 = 0 ; V_108 < V_311 -> V_387 ; V_108 ++ , V_385 ++ ) {
if ( F_79 ( V_311 -> V_147 ) &
V_388 )
continue;
if ( V_385 -> V_389 ==
V_390 ||
V_385 -> V_389 ==
V_391 ) {
V_210 = F_21 ( V_385 -> V_392 ) ;
F_181 ( V_14 , V_210 ) ;
F_182 ( V_210 , & V_383 , & V_384 ) ;
}
}
V_385 = ( T_24 * ) & V_311 -> V_386 [ 0 ] ;
for ( V_108 = 0 ; V_108 < V_311 -> V_387 ; V_108 ++ , V_385 ++ ) {
if ( F_79 ( V_311 -> V_147 ) &
V_388 )
continue;
if ( V_385 -> V_389 == V_393 ) {
V_210 = F_21 ( V_385 -> V_392 ) ;
F_182 ( V_210 , & V_383 , & V_384 ) ;
}
}
if ( V_383 )
F_172 ( V_14 , V_383 ) ;
if ( V_384 )
F_172 ( V_14 , V_384 ) ;
V_385 = ( T_24 * ) & V_311 -> V_386 [ 0 ] ;
for ( V_108 = 0 ; V_108 < V_311 -> V_387 ; V_108 ++ , V_385 ++ ) {
if ( V_385 -> V_389 != V_393 )
continue;
V_35 = F_21 ( V_385 -> V_394 ) ;
V_210 = F_21 ( V_385 -> V_392 ) ;
F_48 ( V_35 , V_14 -> V_139 ) ;
if ( ! V_210 )
F_164 ( V_14 , V_35 ) ;
else if ( V_210 == V_383 || V_210 == V_384 ) {
V_337 = F_9 ( sizeof( * V_337 ) , V_8 ) ;
F_184 ( ! V_337 ) ;
F_141 ( & V_337 -> V_81 ) ;
V_337 -> V_35 = V_35 ;
F_47 ( & V_337 -> V_81 , & V_14 -> V_341 ) ;
F_46 ( V_14 , F_13 ( V_42
L_98 , V_14 -> V_43 ,
V_35 ) ) ;
} else
F_164 ( V_14 , V_35 ) ;
}
}
static void
F_185 ( struct V_13 * V_14 ,
T_25 * V_311 )
{
T_10 V_169 ;
if ( V_311 -> V_389 != V_395 )
return;
V_169 = F_79 ( V_311 -> V_396 ) ;
if ( V_169 == V_179 || V_169 ==
V_178 )
F_181 ( V_14 ,
F_21 ( V_311 -> V_392 ) ) ;
}
static void
F_186 ( struct V_13 * V_14 ,
T_26 * V_311 )
{
if ( V_14 -> V_397 >= V_311 -> V_398 ) {
F_25 ( V_42 L_115
L_116 , V_14 -> V_43 ,
( ( F_21 ( V_311 -> V_399 ) & 0x1 ) == 1 ) ? L_117 : L_118 ,
( ( F_21 ( V_311 -> V_399 ) & 0x2 ) == 2 ) ? L_119 : L_118 ,
( ( F_21 ( V_311 -> V_399 ) & 0x4 ) == 4 ) ? L_120 : L_118 ,
( ( F_21 ( V_311 -> V_399 ) & 0x8 ) == 8 ) ? L_121 : L_118 ,
V_311 -> V_398 ) ;
F_25 ( V_42 L_122 ,
V_14 -> V_43 , V_311 -> V_400 ) ;
}
}
static int F_187 ( struct V_103 * V_106 , bool V_401 )
{
struct V_118 * V_402 = V_106 -> V_51 -> V_122 ;
if ( V_106 -> V_403 [ 0 ] != V_404 && V_106 -> V_403 [ 0 ] != V_405 )
return 0 ;
if ( V_401 )
return F_188 ( 0 , & V_402 -> V_406 ) ;
F_48 ( 0 , & V_402 -> V_406 ) ;
return 0 ;
}
static void
F_189 ( struct V_13 * V_14 )
{
struct V_103 * V_106 ;
T_4 V_104 ;
T_4 V_407 = 0 ;
for ( V_104 = 1 ; V_104 <= V_14 -> V_109 ; V_104 ++ ) {
V_106 = F_63 ( V_14 , V_104 ) ;
if ( ! V_106 )
continue;
V_407 ++ ;
F_187 ( V_106 , false ) ;
F_177 ( V_14 , V_104 ) ;
F_190 ( V_106 ) ;
if ( V_14 -> V_267 )
V_106 -> V_299 = V_300 << 16 ;
else
V_106 -> V_299 = V_302 << 16 ;
V_106 -> V_301 ( V_106 ) ;
}
F_120 ( V_14 , F_13 ( V_42 L_123 ,
V_14 -> V_43 , V_407 ) ) ;
}
static void
F_191 ( struct V_13 * V_14 , struct V_103 * V_106 ,
T_27 * V_260 )
{
T_4 V_408 ;
unsigned char V_409 = F_192 ( V_106 ) ;
unsigned char V_410 = F_193 ( V_106 ) ;
T_28 * V_411 =
( T_28 * ) V_260 ;
if ( V_410 == V_412 || V_409 == V_413 )
return;
if ( V_409 == V_414 )
V_408 = V_415 ;
else if ( V_409 == V_416 )
V_408 = V_417 ;
else
return;
switch ( V_410 ) {
case V_418 :
case V_419 :
V_408 |= V_420 |
V_421 |
V_422 ;
V_260 -> V_423 . V_424 . V_425 =
F_194 ( F_195 ( V_106 ) ) ;
break;
case V_426 :
V_408 |= V_422 ;
break;
}
V_411 -> V_427 =
F_122 ( V_106 -> V_51 -> V_428 ) ;
if ( V_14 -> V_429 )
V_408 |= V_430 ;
V_260 -> V_431 = F_122 ( V_408 ) ;
}
static void
F_196 ( struct V_103 * V_106 , T_4 V_38 )
{
T_6 V_432 ;
switch ( V_38 ) {
case V_433 :
V_432 = 0x01 ;
break;
case V_434 :
V_432 = 0x02 ;
break;
case V_435 :
V_432 = 0x03 ;
break;
default:
V_432 = 0x00 ;
break;
}
F_197 ( 0 , V_106 -> V_436 , V_437 , 0x10 ,
V_432 ) ;
V_106 -> V_299 = V_438 << 24 | ( V_439 << 16 ) |
V_440 ;
}
static int
F_198 ( struct V_114 * V_115 , struct V_103 * V_106 )
{
struct V_13 * V_14 = F_68 ( V_115 ) ;
struct V_118 * V_119 ;
struct V_72 * V_120 ;
struct V_55 * V_56 ;
struct V_441 * V_442 = V_106 -> V_441 ;
int V_443 ;
T_27 * V_260 ;
T_10 V_444 ;
T_4 V_104 ;
T_4 V_35 ;
if ( V_14 -> V_15 & V_445 )
F_133 ( V_106 ) ;
V_119 = V_106 -> V_51 -> V_122 ;
if ( ! V_119 || ! V_119 -> V_124 ) {
V_106 -> V_299 = V_300 << 16 ;
V_106 -> V_301 ( V_106 ) ;
return 0 ;
}
if ( V_14 -> V_267 || V_14 -> V_266 ) {
V_106 -> V_299 = V_300 << 16 ;
V_106 -> V_301 ( V_106 ) ;
return 0 ;
}
do {
if ( F_73 ( 0 , & V_119 -> V_406 ) ) {
V_106 -> V_299 = V_446 ;
V_106 -> V_301 ( V_106 ) ;
return 0 ;
}
} while ( F_187 ( V_106 , true ) );
V_120 = V_119 -> V_124 ;
V_35 = V_120 -> V_35 ;
if ( V_35 == V_134 ) {
V_106 -> V_299 = V_300 << 16 ;
V_106 -> V_301 ( V_106 ) ;
return 0 ;
}
if ( V_14 -> V_82 || V_14 -> V_447 )
return V_448 ;
else if ( V_120 -> V_339 ) {
V_106 -> V_299 = V_300 << 16 ;
V_106 -> V_301 ( V_106 ) ;
return 0 ;
} else if ( V_120 -> V_256 ||
V_119 -> V_316 )
return V_449 ;
if ( V_106 -> V_450 == V_451 )
V_444 = V_452 ;
else if ( V_106 -> V_450 == V_453 )
V_444 = V_454 ;
else
V_444 = V_455 ;
V_444 |= V_456 ;
if ( V_119 -> V_457 ) {
V_443 = F_199 ( F_200 ( V_442 ) ) ;
if ( V_443 == V_458 )
V_444 |= 1 << V_459 ;
}
if ( ! V_14 -> V_136 && ! F_80 ( & V_106 -> V_51 -> V_193 )
&& F_97 ( V_106 -> V_51 ) && V_106 -> V_460 != 32 )
V_444 |= V_461 ;
V_104 = F_201 ( V_14 , V_14 -> V_462 , V_106 ) ;
if ( ! V_104 ) {
F_25 ( V_42 L_52 ,
V_14 -> V_43 , V_44 ) ;
goto V_91;
}
V_260 = F_121 ( V_14 , V_104 ) ;
memset ( V_260 , 0 , sizeof( T_27 ) ) ;
F_191 ( V_14 , V_106 , V_260 ) ;
if ( V_106 -> V_460 == 32 )
V_444 |= 4 << V_463 ;
V_260 -> V_276 = V_464 ;
if ( V_119 -> V_124 -> V_76 &
V_140 )
V_260 -> V_276 = V_465 ;
else
V_260 -> V_276 = V_464 ;
V_260 -> V_202 = F_122 ( V_35 ) ;
V_260 -> V_466 = F_202 ( F_203 ( V_106 ) ) ;
V_260 -> V_467 = F_202 ( V_444 ) ;
V_260 -> V_468 = F_122 ( V_106 -> V_460 ) ;
V_260 -> V_469 = V_470 ;
V_260 -> V_471 = V_472 ;
V_260 -> V_473 =
F_204 ( V_14 , V_104 ) ;
V_260 -> V_474 = F_93 ( T_27 , V_475 ) / 4 ;
F_123 ( V_119 -> V_111 , (struct V_280 * )
V_260 -> V_281 ) ;
memcpy ( V_260 -> V_423 . V_476 , V_106 -> V_403 , V_106 -> V_460 ) ;
if ( V_260 -> V_466 ) {
if ( V_14 -> V_477 ( V_14 , V_106 , V_104 ) ) {
F_177 ( V_14 , V_104 ) ;
goto V_91;
}
} else
V_14 -> V_478 ( V_14 , & V_260 -> V_475 ) ;
V_56 = V_120 -> V_56 ;
if ( V_56 && V_56 -> V_479 )
F_205 ( V_14 , V_106 , V_56 , V_260 ,
V_104 ) ;
if ( F_170 ( V_260 -> V_276 == V_464 ) ) {
if ( V_120 -> V_76 & V_142 ) {
V_260 -> V_468 = F_122 ( V_106 -> V_460 |
V_480 ) ;
V_14 -> V_481 ( V_14 , V_104 , V_35 ) ;
} else
V_14 -> V_482 ( V_14 , V_104 ,
F_21 ( V_260 -> V_202 ) ) ;
} else
V_14 -> V_353 ( V_14 , V_104 ) ;
return 0 ;
V_91:
return V_448 ;
}
static void
F_206 ( char * V_436 , struct V_483 * V_484 )
{
if ( ( V_436 [ 0 ] & 0x7F ) >= 0x72 ) {
V_484 -> V_485 = V_436 [ 1 ] & 0x0F ;
V_484 -> V_486 = V_436 [ 2 ] ;
V_484 -> V_432 = V_436 [ 3 ] ;
} else {
V_484 -> V_485 = V_436 [ 2 ] & 0x0F ;
V_484 -> V_486 = V_436 [ 12 ] ;
V_484 -> V_432 = V_436 [ 13 ] ;
}
}
static void
F_207 ( struct V_13 * V_14 , struct V_103 * V_106 ,
T_29 * V_37 , T_4 V_104 )
{
T_10 V_487 ;
T_6 * V_488 ;
T_4 V_38 = F_21 ( V_37 -> V_46 ) &
V_47 ;
T_6 V_489 = V_37 -> V_490 ;
T_6 V_491 = V_37 -> V_492 ;
char * V_493 = NULL ;
char * V_494 = NULL ;
char * V_495 = V_14 -> V_496 ;
T_10 V_497 = F_79 ( V_37 -> V_288 ) ;
struct V_53 * V_54 = NULL ;
struct V_128 * V_87 = V_106 -> V_51 -> V_296 ;
struct V_72 * V_297 = V_87 -> V_122 ;
char * V_298 = NULL ;
if ( ! V_297 )
return;
if ( V_14 -> V_220 )
V_298 = L_57 ;
else
V_298 = L_58 ;
if ( V_497 == 0x31170000 )
return;
switch ( V_38 ) {
case V_48 :
V_493 = L_124 ;
break;
case V_498 :
V_493 = L_125 ;
break;
case V_499 :
V_493 = L_126 ;
break;
case V_500 :
V_493 = L_127 ;
break;
case V_501 :
V_493 = L_128 ;
break;
case V_502 :
V_493 = L_129 ;
break;
case V_503 :
V_493 = L_130 ;
break;
case V_504 :
V_493 = L_131 ;
break;
case V_505 :
V_493 = L_132 ;
break;
case V_506 :
V_493 = L_133 ;
break;
case V_507 :
V_493 = L_134 ;
break;
case V_508 :
V_493 = L_135 ;
break;
case V_509 :
V_493 = L_136 ;
break;
case V_510 :
V_493 = L_137 ;
break;
case V_433 :
V_493 = L_138 ;
break;
case V_435 :
V_493 = L_139 ;
break;
case V_434 :
V_493 = L_140 ;
break;
case V_511 :
V_493 = L_141 ;
break;
default:
V_493 = L_47 ;
break;
}
switch ( V_491 ) {
case V_512 :
V_494 = L_142 ;
break;
case V_513 :
V_494 = L_143 ;
break;
case V_514 :
V_494 = L_144 ;
break;
case V_515 :
V_494 = L_145 ;
break;
case V_516 :
V_494 = L_146 ;
break;
case V_517 :
V_494 = L_147 ;
break;
case V_518 :
V_494 = L_148 ;
break;
case V_519 :
V_494 = L_149 ;
break;
case V_520 :
V_494 = L_150 ;
break;
case V_521 :
V_494 = L_151 ;
break;
case V_522 :
V_494 = L_152 ;
break;
default:
V_494 = L_47 ;
break;
}
V_495 [ 0 ] = '\0' ;
if ( ! V_489 )
V_495 = L_118 ;
if ( V_489 & V_523 )
strcat ( V_495 , L_153 ) ;
if ( V_489 & V_524 )
strcat ( V_495 , L_154 ) ;
if ( V_489 & V_525 )
strcat ( V_495 , L_155 ) ;
if ( V_489 & V_526 )
strcat ( V_495 , L_156 ) ;
if ( V_489 & V_527 )
strcat ( V_495 , L_157 ) ;
F_133 ( V_106 ) ;
if ( V_297 -> V_76 & V_125 ) {
F_92 ( V_42 L_158 , V_14 -> V_43 ,
V_298 , ( unsigned long long ) V_297 -> V_17 ) ;
} else {
V_54 = F_31 ( V_14 , V_297 ) ;
if ( V_54 ) {
F_92 ( V_42
L_159 ,
V_14 -> V_43 , ( unsigned long long )
V_54 -> V_17 , V_54 -> V_227 ) ;
if ( V_54 -> V_78 != 0 )
F_92 ( V_42
L_160
L_161 , V_14 -> V_43 ,
( unsigned long long )
V_54 -> V_22 ,
V_54 -> V_26 ) ;
if ( V_54 -> V_79 [ 0 ] )
F_92 ( V_42
L_162
L_97 , V_14 -> V_43 ,
V_54 -> V_80 ,
V_54 -> V_79 ) ;
F_41 ( V_54 ) ;
}
}
F_92 ( V_42
L_163 ,
V_14 -> V_43 , F_21 ( V_37 -> V_202 ) ,
V_493 , V_38 , V_104 ) ;
F_92 ( V_42
L_164 ,
V_14 -> V_43 , F_203 ( V_106 ) , V_106 -> V_528 ,
F_208 ( V_106 ) ) ;
F_92 ( V_42
L_165 ,
V_14 -> V_43 , F_21 ( V_37 -> V_529 ) ,
F_79 ( V_37 -> V_530 ) , V_106 -> V_299 ) ;
F_92 ( V_42
L_166 ,
V_14 -> V_43 , V_494 ,
V_491 , V_495 , V_489 ) ;
if ( V_489 & V_527 ) {
struct V_483 V_484 ;
F_206 ( V_106 -> V_436 , & V_484 ) ;
F_92 ( V_42
L_167 ,
V_14 -> V_43 , V_484 . V_485 ,
V_484 . V_486 , V_484 . V_432 , F_79 ( V_37 -> V_531 ) ) ;
}
if ( V_489 & V_523 ) {
V_487 = F_79 ( V_37 -> V_532 ) ;
V_488 = ( T_6 * ) & V_487 ;
F_106 ( V_14 , V_488 [ 0 ] ) ;
}
}
static void
F_209 ( struct V_13 * V_14 , T_4 V_35 )
{
T_30 V_37 ;
T_31 V_260 ;
struct V_53 * V_54 ;
V_54 = F_37 ( V_14 , V_35 ) ;
if ( ! V_54 )
return;
memset ( & V_260 , 0 , sizeof( T_31 ) ) ;
V_260 . V_276 = V_533 ;
V_260 . V_534 = V_535 ;
V_260 . V_536 =
F_202 ( V_537 ) ;
V_260 . V_202 = F_122 ( V_35 ) ;
V_260 . V_147 = V_538 ;
if ( ( F_210 ( V_14 , & V_37 ,
& V_260 ) ) != 0 ) {
F_25 ( V_42 L_2 , V_14 -> V_43 ,
__FILE__ , __LINE__ , V_44 ) ;
goto V_91;
}
V_54 -> V_539 = 1 ;
if ( V_37 . V_46 || V_37 . V_288 ) {
F_46 ( V_14 , F_13 ( V_42
L_168 ,
V_14 -> V_43 , F_21 ( V_37 . V_46 ) ,
F_79 ( V_37 . V_288 ) ) ) ;
goto V_91;
}
V_91:
F_41 ( V_54 ) ;
}
static void
F_211 ( struct V_13 * V_14 ,
struct V_53 * V_54 )
{
T_30 V_37 ;
T_31 V_260 ;
memset ( & V_260 , 0 , sizeof( T_31 ) ) ;
V_260 . V_276 = V_533 ;
V_260 . V_534 = V_535 ;
V_260 . V_536 = 0 ;
V_260 . V_540 = F_122 ( V_54 -> V_26 ) ;
V_260 . V_202 = 0 ;
V_260 . V_541 = F_122 ( V_54 -> V_78 ) ;
V_260 . V_147 = V_542 ;
if ( ( F_210 ( V_14 , & V_37 ,
& V_260 ) ) != 0 ) {
F_212 ( V_42 L_2 , V_14 -> V_43 ,
__FILE__ , __LINE__ , V_44 ) ;
return;
}
if ( V_37 . V_46 || V_37 . V_288 ) {
F_46 ( V_14 , F_212 ( V_42
L_168 ,
V_14 -> V_43 , F_21 ( V_37 . V_46 ) ,
F_79 ( V_37 . V_288 ) ) ) ;
return;
}
}
static void
F_213 ( struct V_13 * V_14 , T_4 V_35 )
{
struct V_3 * V_7 ;
V_7 = F_8 ( 0 ) ;
if ( ! V_7 )
return;
V_7 -> V_312 = V_543 ;
V_7 -> V_544 = V_35 ;
V_7 -> V_14 = V_14 ;
F_140 ( V_14 , V_7 ) ;
F_6 ( V_7 ) ;
}
static void
F_214 ( struct V_13 * V_14 , T_4 V_35 )
{
struct V_128 * V_87 ;
struct V_72 * V_120 ;
T_32 * V_545 ;
T_33 * V_311 ;
struct V_53 * V_54 ;
T_34 V_195 ;
unsigned long V_76 ;
F_32 ( & V_14 -> V_74 , V_76 ) ;
V_54 = F_36 ( V_14 , V_35 ) ;
if ( ! V_54 )
goto V_546;
V_87 = V_54 -> V_87 ;
V_120 = V_87 -> V_122 ;
if ( ( V_120 -> V_76 & V_140 ) ||
( ( V_120 -> V_76 & V_125 ) ) )
goto V_546;
if ( V_54 -> V_78 != 0 )
F_134 ( V_146 , V_87 , L_169
L_170 ,
( unsigned long long ) V_54 -> V_22 ,
V_54 -> V_26 ) ;
if ( V_54 -> V_79 [ 0 ] != '\0' )
F_134 ( V_225 , V_87 , L_169
L_171 ,
V_54 -> V_80 ,
V_54 -> V_79 ) ;
F_33 ( & V_14 -> V_74 , V_76 ) ;
if ( V_14 -> V_547 -> V_548 == V_549 )
F_213 ( V_14 , V_35 ) ;
V_195 = F_93 ( T_32 , V_550 ) +
sizeof( T_33 ) ;
V_545 = F_9 ( V_195 , V_132 ) ;
if ( ! V_545 ) {
F_25 ( V_42 L_2 ,
V_14 -> V_43 , __FILE__ , __LINE__ , V_44 ) ;
goto V_91;
}
V_545 -> V_276 = V_551 ;
V_545 -> V_363 =
F_122 ( V_552 ) ;
V_545 -> V_251 = V_195 / 4 ;
V_545 -> V_553 =
F_122 ( sizeof( T_33 ) / 4 ) ;
V_311 = ( T_33 * )
V_545 -> V_550 ;
V_311 -> V_389 = V_554 ;
V_311 -> V_555 = 0x5D ;
V_311 -> V_202 = F_122 ( V_35 ) ;
V_311 -> V_19 = F_215 ( V_120 -> V_17 ) ;
F_216 ( V_14 , V_545 ) ;
F_2 ( V_545 ) ;
V_91:
if ( V_54 )
F_41 ( V_54 ) ;
return;
V_546:
F_33 ( & V_14 -> V_74 , V_76 ) ;
goto V_91;
}
static T_6
F_217 ( struct V_13 * V_14 , T_4 V_104 , T_6 V_245 , T_10 V_246 )
{
T_27 * V_260 ;
T_29 * V_37 ;
struct V_103 * V_106 ;
T_4 V_38 ;
T_10 V_556 ;
T_6 V_489 ;
T_6 V_491 ;
T_10 V_497 ;
struct V_118 * V_119 ;
T_10 V_236 = 0 ;
unsigned long V_76 ;
unsigned int V_557 ;
V_37 = F_108 ( V_14 , V_246 ) ;
V_106 = F_63 ( V_14 , V_104 ) ;
if ( V_106 == NULL )
return 1 ;
F_187 ( V_106 , false ) ;
V_260 = F_121 ( V_14 , V_104 ) ;
if ( V_37 == NULL ) {
V_106 -> V_299 = V_558 << 16 ;
goto V_91;
}
V_119 = V_106 -> V_51 -> V_122 ;
if ( ! V_119 || ! V_119 -> V_124 ||
V_119 -> V_124 -> V_339 ) {
V_106 -> V_299 = V_300 << 16 ;
goto V_91;
}
V_38 = F_21 ( V_37 -> V_46 ) ;
if ( F_218 ( V_14 , V_104 ) &&
( ( V_38 & V_47 )
!= V_506 ) ) {
F_32 ( & V_14 -> V_107 , V_76 ) ;
V_14 -> V_105 [ V_104 - 1 ] . V_106 = V_106 ;
F_33 ( & V_14 -> V_107 , V_76 ) ;
F_219 ( V_14 , V_104 , 0 ) ;
memcpy ( V_260 -> V_423 . V_476 , V_106 -> V_403 , V_106 -> V_460 ) ;
V_260 -> V_202 =
F_122 ( V_119 -> V_124 -> V_35 ) ;
V_14 -> V_482 ( V_14 , V_104 ,
V_119 -> V_124 -> V_35 ) ;
return 0 ;
}
V_489 = V_37 -> V_490 ;
if ( V_489 & V_523 )
V_236 =
F_79 ( V_37 -> V_532 ) & 0xFF ;
if ( ! V_119 -> V_559 ) {
V_119 -> V_559 ++ ;
if ( ! V_14 -> V_136 &&
! F_80 ( & V_106 -> V_51 -> V_193 ) &&
F_97 ( V_106 -> V_51 ) &&
V_236 == V_239 ) {
F_220 ( V_106 -> V_51 ) ;
F_76 ( V_146 , V_106 -> V_51 , L_172 ) ;
}
}
V_556 = F_79 ( V_37 -> V_530 ) ;
V_557 = V_106 -> V_51 -> V_428 ;
if ( F_166 ( V_106 -> V_441 -> V_560 == V_561 && V_557 &&
V_556 % V_557 ) ) {
F_76 ( V_146 , V_106 -> V_51 ,
L_173 ,
V_556 , V_557 ) ;
V_556 = F_221 ( V_556 , V_557 ) ;
}
F_222 ( V_106 , F_203 ( V_106 ) - V_556 ) ;
if ( V_38 & V_562 )
V_497 = F_79 ( V_37 -> V_288 ) ;
else
V_497 = 0 ;
V_38 &= V_47 ;
V_491 = V_37 -> V_492 ;
if ( V_38 == V_503 && V_556 == 0 &&
( V_491 == V_515 ||
V_491 == V_518 ||
V_491 == V_520 ) ) {
V_38 = V_48 ;
}
if ( V_489 & V_527 ) {
struct V_483 V_484 ;
const void * V_563 = F_223 ( V_14 ,
V_104 ) ;
T_10 V_195 = F_224 ( T_10 , V_472 ,
F_79 ( V_37 -> V_531 ) ) ;
memcpy ( V_106 -> V_436 , V_563 , V_195 ) ;
F_206 ( V_106 -> V_436 , & V_484 ) ;
if ( V_484 . V_486 == 0x5D )
F_214 ( V_14 ,
F_21 ( V_37 -> V_202 ) ) ;
F_225 ( V_14 , V_484 . V_485 , V_484 . V_486 , V_484 . V_432 ) ;
if ( ( V_14 -> V_15 & V_564 ) &&
( ( V_106 -> V_436 [ 2 ] == V_565 ) ||
( V_106 -> V_436 [ 2 ] == V_566 ) ||
( V_106 -> V_436 [ 2 ] == V_567 ) ) )
F_207 ( V_14 , V_106 , V_37 , V_104 ) ;
}
switch ( V_38 ) {
case V_568 :
case V_569 :
V_106 -> V_299 = V_446 ;
break;
case V_501 :
V_106 -> V_299 = V_300 << 16 ;
break;
case V_509 :
if ( V_119 -> V_316 ) {
V_106 -> V_299 = V_570 << 16 ;
goto V_91;
}
if ( V_497 == 0x31110630 ) {
if ( V_106 -> V_571 > 2 ) {
V_106 -> V_299 = V_300 << 16 ;
F_226 ( V_106 -> V_51 ,
V_572 ) ;
} else {
V_106 -> V_299 = V_573 << 16 ;
V_106 -> V_51 -> V_574 = 1 ;
}
break;
} else if ( V_497 == V_575 ) {
V_106 -> V_299 = V_302 << 16 ;
break;
}
V_106 -> V_299 = V_573 << 16 ;
break;
case V_506 :
case V_510 :
V_106 -> V_299 = V_302 << 16 ;
break;
case V_507 :
if ( ( V_556 == 0 ) || ( V_106 -> V_528 > V_556 ) )
V_106 -> V_299 = V_573 << 16 ;
else
V_106 -> V_299 = ( V_558 << 16 ) | V_491 ;
break;
case V_503 :
V_106 -> V_299 = ( V_558 << 16 ) | V_491 ;
if ( ( V_489 & V_527 ) )
break;
if ( V_556 < V_106 -> V_528 ) {
if ( V_491 == V_446 )
V_106 -> V_299 = V_446 ;
else
V_106 -> V_299 = V_573 << 16 ;
} else if ( V_489 & ( V_526 |
V_525 ) )
V_106 -> V_299 = V_573 << 16 ;
else if ( V_489 & V_524 )
V_106 -> V_299 = V_302 << 16 ;
else if ( ! V_556 && V_106 -> V_403 [ 0 ] == V_576 ) {
V_37 -> V_490 = V_527 ;
V_37 -> V_492 = V_440 ;
V_106 -> V_299 = ( V_438 << 24 ) |
V_440 ;
V_106 -> V_436 [ 0 ] = 0x70 ;
V_106 -> V_436 [ 2 ] = V_437 ;
V_106 -> V_436 [ 12 ] = 0x20 ;
V_106 -> V_436 [ 13 ] = 0 ;
}
break;
case V_502 :
F_222 ( V_106 , 0 ) ;
case V_499 :
case V_48 :
V_106 -> V_299 = ( V_558 << 16 ) | V_491 ;
if ( V_236 ==
V_239 ||
( V_489 & ( V_526 |
V_525 ) ) )
V_106 -> V_299 = V_573 << 16 ;
else if ( V_489 & V_524 )
V_106 -> V_299 = V_302 << 16 ;
break;
case V_433 :
case V_435 :
case V_434 :
F_196 ( V_106 , V_38 ) ;
break;
case V_505 :
case V_498 :
case V_577 :
case V_578 :
case V_579 :
case V_580 :
case V_504 :
case V_508 :
case V_511 :
default:
V_106 -> V_299 = V_573 << 16 ;
break;
}
if ( V_106 -> V_299 && ( V_14 -> V_15 & V_564 ) )
F_207 ( V_14 , V_106 , V_37 , V_104 ) ;
V_91:
F_190 ( V_106 ) ;
V_106 -> V_301 ( V_106 ) ;
return 1 ;
}
static void
F_227 ( struct V_13 * V_14 )
{
T_4 V_195 ;
T_4 V_38 ;
int V_108 ;
T_9 V_37 ;
T_35 * V_581 = NULL ;
T_4 V_582 ;
T_6 V_583 ;
F_120 ( V_14 , F_13 ( V_42
L_174 ,
V_14 -> V_43 , ( unsigned long long ) V_14 -> V_39 . V_17 ) ) ;
V_195 = F_93 ( T_35 , V_584 ) + ( V_14 -> V_39 . V_40
* sizeof( V_585 ) ) ;
V_581 = F_9 ( V_195 , V_132 ) ;
if ( ! V_581 ) {
F_25 ( V_42 L_2 ,
V_14 -> V_43 , __FILE__ , __LINE__ , V_44 ) ;
return;
}
if ( ( F_228 ( V_14 , & V_37 ,
V_581 , V_195 ) ) != 0 )
goto V_91;
V_38 = F_21 ( V_37 . V_46 ) & V_47 ;
if ( V_38 != V_48 )
goto V_91;
for ( V_108 = 0 ; V_108 < V_14 -> V_39 . V_40 ; V_108 ++ ) {
V_583 = V_581 -> V_584 [ V_108 ] . V_586 >> 4 ;
if ( V_108 == 0 )
V_14 -> V_39 . V_35 = F_21 ( V_581 ->
V_584 [ 0 ] . V_587 ) ;
V_14 -> V_39 . V_227 [ V_108 ] . V_35 = V_14 -> V_39 . V_35 ;
V_582 = F_21 ( V_581 -> V_584 [ V_108 ] .
V_332 ) ;
if ( V_582 && V_583 < V_588 )
V_583 = V_588 ;
F_229 ( V_14 , V_14 -> V_39 . V_17 ,
V_582 , V_108 , V_583 ) ;
}
V_91:
F_2 ( V_581 ) ;
}
static void
F_230 ( struct V_13 * V_14 )
{
int V_108 ;
T_9 V_37 ;
T_35 * V_581 = NULL ;
T_36 * V_589 = NULL ;
T_37 V_590 ;
T_8 V_36 ;
T_38 V_591 ;
T_4 V_38 ;
T_4 V_195 ;
T_6 V_592 ;
T_6 V_40 ;
F_231 ( V_14 , & V_40 ) ;
if ( ! V_40 ) {
F_25 ( V_42 L_2 ,
V_14 -> V_43 , __FILE__ , __LINE__ , V_44 ) ;
return;
}
V_14 -> V_39 . V_227 = F_232 ( V_40 ,
sizeof( struct V_593 ) , V_132 ) ;
if ( ! V_14 -> V_39 . V_227 ) {
F_25 ( V_42 L_2 ,
V_14 -> V_43 , __FILE__ , __LINE__ , V_44 ) ;
goto V_91;
}
V_14 -> V_39 . V_40 = V_40 ;
V_195 = F_93 ( T_35 , V_584 ) + ( V_14 -> V_39 . V_40 *
sizeof( V_585 ) ) ;
V_581 = F_9 ( V_195 , V_132 ) ;
if ( ! V_581 ) {
F_25 ( V_42 L_2 ,
V_14 -> V_43 , __FILE__ , __LINE__ , V_44 ) ;
return;
}
if ( ( F_228 ( V_14 , & V_37 ,
V_581 , V_195 ) ) ) {
F_25 ( V_42 L_2 ,
V_14 -> V_43 , __FILE__ , __LINE__ , V_44 ) ;
goto V_91;
}
V_38 = F_21 ( V_37 . V_46 ) &
V_47 ;
if ( V_38 != V_48 ) {
F_25 ( V_42 L_2 ,
V_14 -> V_43 , __FILE__ , __LINE__ , V_44 ) ;
goto V_91;
}
V_195 = F_93 ( T_36 , V_584 ) + ( V_14 -> V_39 . V_40 *
sizeof( V_594 ) ) ;
V_589 = F_9 ( V_195 , V_132 ) ;
if ( ! V_589 ) {
F_25 ( V_42 L_2 ,
V_14 -> V_43 , __FILE__ , __LINE__ , V_44 ) ;
goto V_91;
}
if ( ( F_233 ( V_14 , & V_37 ,
V_589 , V_195 ) ) ) {
F_25 ( V_42 L_2 ,
V_14 -> V_43 , __FILE__ , __LINE__ , V_44 ) ;
goto V_91;
}
V_38 = F_21 ( V_37 . V_46 ) &
V_47 ;
if ( V_38 != V_48 ) {
F_25 ( V_42 L_2 ,
V_14 -> V_43 , __FILE__ , __LINE__ , V_44 ) ;
goto V_91;
}
V_14 -> V_595 =
V_589 -> V_596 ;
V_592 =
V_589 -> V_597 ;
if ( V_592 & V_598 )
V_14 -> V_592 = ( V_592 &
V_599 ) * 16 ;
else
V_14 -> V_592 = V_592 &
V_599 ;
V_14 -> V_39 . V_600 = & V_14 -> V_115 -> V_601 ;
for ( V_108 = 0 ; V_108 < V_14 -> V_39 . V_40 ; V_108 ++ ) {
if ( ( F_234 ( V_14 , & V_37 , & V_590 ,
V_108 ) ) ) {
F_25 ( V_42 L_2 ,
V_14 -> V_43 , __FILE__ , __LINE__ , V_44 ) ;
goto V_91;
}
V_38 = F_21 ( V_37 . V_46 ) &
V_47 ;
if ( V_38 != V_48 ) {
F_25 ( V_42 L_2 ,
V_14 -> V_43 , __FILE__ , __LINE__ , V_44 ) ;
goto V_91;
}
if ( V_108 == 0 )
V_14 -> V_39 . V_35 = F_21 ( V_581 ->
V_584 [ 0 ] . V_587 ) ;
V_14 -> V_39 . V_227 [ V_108 ] . V_35 = V_14 -> V_39 . V_35 ;
V_14 -> V_39 . V_227 [ V_108 ] . V_602 = V_108 ;
F_235 ( V_14 , & V_14 -> V_39 . V_227 [ V_108 ] ,
V_590 , V_14 -> V_39 . V_600 ) ;
}
if ( ( F_24 ( V_14 , & V_37 , & V_36 ,
V_41 , V_14 -> V_39 . V_35 ) ) ) {
F_25 ( V_42 L_2 ,
V_14 -> V_43 , __FILE__ , __LINE__ , V_44 ) ;
goto V_91;
}
V_14 -> V_39 . V_78 =
F_21 ( V_36 . V_541 ) ;
V_14 -> V_39 . V_17 = F_18 ( V_36 . V_19 ) ;
F_13 ( V_42
L_175 ,
V_14 -> V_43 , V_14 -> V_39 . V_35 ,
( unsigned long long ) V_14 -> V_39 . V_17 ,
V_14 -> V_39 . V_40 ) ;
if ( V_14 -> V_39 . V_78 ) {
if ( ! ( F_236 ( V_14 , & V_37 ,
& V_591 , V_603 ,
V_14 -> V_39 . V_78 ) ) )
V_14 -> V_39 . V_22 =
F_18 ( V_591 . V_24 ) ;
}
V_91:
F_2 ( V_589 ) ;
F_2 ( V_581 ) ;
}
static int
F_237 ( struct V_13 * V_14 , T_4 V_35 )
{
struct V_94 * V_95 ;
T_9 V_37 ;
T_39 V_604 ;
T_40 V_605 ;
T_38 V_591 ;
T_10 V_38 ;
T_4 V_606 ;
T_1 V_17 , V_86 = 0 ;
int V_108 ;
unsigned long V_76 ;
struct V_320 * V_321 = NULL ;
int V_28 = 0 ;
if ( ! V_35 )
return - 1 ;
if ( V_14 -> V_82 || V_14 -> V_267 )
return - 1 ;
if ( ( F_238 ( V_14 , & V_37 , & V_604 ,
V_607 , V_35 ) ) ) {
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
V_606 = F_21 ( V_604 . V_608 ) ;
if ( F_23 ( V_14 , V_606 , & V_86 )
!= 0 ) {
F_25 ( V_42 L_2 ,
V_14 -> V_43 , __FILE__ , __LINE__ , V_44 ) ;
return - 1 ;
}
if ( V_86 != V_14 -> V_39 . V_17 ) {
F_32 ( & V_14 -> V_96 , V_76 ) ;
V_95 = F_59 ( V_14 ,
V_86 ) ;
F_33 ( & V_14 -> V_96 , V_76 ) ;
if ( ! V_95 ) {
V_28 = F_237 ( V_14 , V_606 ) ;
if ( V_28 != 0 )
return V_28 ;
}
}
F_32 ( & V_14 -> V_96 , V_76 ) ;
V_17 = F_18 ( V_604 . V_19 ) ;
V_95 = F_59 ( V_14 ,
V_17 ) ;
F_33 ( & V_14 -> V_96 , V_76 ) ;
if ( V_95 )
return 0 ;
V_95 = F_9 ( sizeof( struct V_94 ) ,
V_132 ) ;
if ( ! V_95 ) {
F_25 ( V_42 L_2 ,
V_14 -> V_43 , __FILE__ , __LINE__ , V_44 ) ;
return - 1 ;
}
V_95 -> V_35 = V_35 ;
V_95 -> V_40 = V_604 . V_609 ;
V_95 -> V_86 = V_86 ;
V_95 -> V_17 = V_17 ;
F_13 ( V_42 L_176 \
L_177 , V_14 -> V_43 ,
V_35 , V_606 , ( unsigned long long )
V_95 -> V_17 , V_95 -> V_40 ) ;
if ( ! V_95 -> V_40 )
goto V_610;
V_95 -> V_227 = F_232 ( V_95 -> V_40 ,
sizeof( struct V_593 ) , V_132 ) ;
if ( ! V_95 -> V_227 ) {
F_25 ( V_42 L_2 ,
V_14 -> V_43 , __FILE__ , __LINE__ , V_44 ) ;
V_28 = - 1 ;
goto V_610;
}
F_141 ( & V_95 -> V_611 ) ;
V_321 = F_49 ( V_14 , V_35 ,
V_86 ) ;
if ( ! V_321 ) {
F_25 ( V_42 L_2 ,
V_14 -> V_43 , __FILE__ , __LINE__ , V_44 ) ;
V_28 = - 1 ;
goto V_610;
}
V_95 -> V_600 = & V_321 -> V_131 -> V_129 ;
for ( V_108 = 0 ; V_108 < V_95 -> V_40 ; V_108 ++ ) {
if ( ( F_239 ( V_14 , & V_37 ,
& V_605 , V_108 , V_35 ) ) ) {
F_25 ( V_42 L_2 ,
V_14 -> V_43 , __FILE__ , __LINE__ , V_44 ) ;
V_28 = - 1 ;
goto V_610;
}
V_95 -> V_227 [ V_108 ] . V_35 = V_35 ;
V_95 -> V_227 [ V_108 ] . V_602 = V_108 ;
if ( ( F_240 ( V_14 ,
& V_95 -> V_227 [ V_108 ] , V_605 ,
V_95 -> V_600 ) ) ) {
F_25 ( V_42 L_2 ,
V_14 -> V_43 , __FILE__ , __LINE__ , V_44 ) ;
V_28 = - 1 ;
goto V_610;
}
}
if ( V_95 -> V_78 ) {
if ( ! ( F_236 ( V_14 , & V_37 ,
& V_591 , V_603 ,
V_95 -> V_78 ) ) )
V_95 -> V_22 =
F_18 ( V_591 . V_24 ) ;
}
F_60 ( V_14 , V_95 ) ;
return 0 ;
V_610:
if ( V_321 )
F_50 ( V_14 , V_95 -> V_17 ,
V_86 ) ;
F_2 ( V_95 ) ;
return V_28 ;
}
void
F_241 ( struct V_13 * V_14 , T_1 V_17 )
{
struct V_94 * V_95 ;
unsigned long V_76 ;
if ( V_14 -> V_82 )
return;
F_32 ( & V_14 -> V_96 , V_76 ) ;
V_95 = F_59 ( V_14 ,
V_17 ) ;
if ( V_95 )
F_57 ( & V_95 -> V_81 ) ;
F_33 ( & V_14 -> V_96 , V_76 ) ;
if ( V_95 )
F_242 ( V_14 , V_95 ) ;
}
static T_6
F_243 ( struct V_13 * V_14 , T_4 V_104 , T_6 V_245 , T_10 V_246 )
{
T_15 * V_37 ;
V_37 = F_108 ( V_14 , V_246 ) ;
if ( V_14 -> V_612 . V_248 == V_249 )
return 1 ;
if ( V_14 -> V_612 . V_104 != V_104 )
return 1 ;
V_14 -> V_612 . V_248 |= V_250 ;
if ( V_37 ) {
memcpy ( V_14 -> V_612 . V_246 , V_37 ,
V_37 -> V_251 * 4 ) ;
V_14 -> V_612 . V_248 |= V_252 ;
}
V_14 -> V_612 . V_248 &= ~ V_253 ;
F_109 ( & V_14 -> V_612 . V_254 ) ;
return 1 ;
}
static T_6
F_244 ( struct V_13 * V_14 , T_1 V_17 ,
T_4 V_35 , T_6 V_613 )
{
T_6 V_28 = 1 ;
char * V_237 = NULL ;
switch ( V_613 ) {
case V_614 :
case V_615 :
V_28 = 0 ;
break;
case V_616 :
V_237 = L_178 ;
break;
case V_617 :
V_237 = L_179 ;
break;
case V_618 :
V_237 = L_180 ;
break;
case V_619 :
V_237 = L_181 ;
break;
case V_620 :
V_237 = L_182 ;
break;
case V_621 :
case V_622 :
case V_623 :
case V_624 :
case V_625 :
case V_626 :
case V_627 :
case V_628 :
case V_629 :
case V_630 :
case V_631 :
case V_632 :
V_237 = L_183 ;
break;
default:
V_237 = L_47 ;
break;
}
if ( ! V_28 )
return 0 ;
F_25 ( V_42
L_184 ,
V_14 -> V_43 , V_237 , ( unsigned long long ) V_17 , V_35 ) ;
return V_28 ;
}
static void
F_245 ( struct V_13 * V_14 ,
T_1 V_633 , T_4 V_35 , T_6 V_634 , T_6 V_583 )
{
T_9 V_37 ;
T_8 V_36 ;
struct V_53 * V_54 ;
T_10 V_38 ;
unsigned long V_76 ;
T_1 V_17 ;
struct V_128 * V_87 ;
struct V_72 * V_120 ;
T_10 V_98 ;
if ( ( F_24 ( V_14 , & V_37 , & V_36 ,
V_41 , V_35 ) ) )
return;
V_38 = F_21 ( V_37 . V_46 ) & V_47 ;
if ( V_38 != V_48 )
return;
if ( V_634 != V_36 . V_635 )
return;
V_98 = F_79 ( V_36 . V_148 ) ;
if ( ! ( F_61 ( V_98 ) ) )
return;
F_32 ( & V_14 -> V_74 , V_76 ) ;
V_17 = F_18 ( V_36 . V_19 ) ;
V_54 = F_34 ( V_14 ,
V_17 ) ;
if ( ! V_54 )
goto V_546;
if ( F_166 ( V_54 -> V_35 != V_35 ) ) {
V_87 = V_54 -> V_87 ;
V_120 = V_87 -> V_122 ;
F_134 ( V_146 , V_87 ,
L_185 ,
V_54 -> V_35 , V_35 ) ;
V_120 -> V_35 = V_35 ;
V_54 -> V_35 = V_35 ;
if ( F_21 ( V_36 . V_147 ) &
V_636 ) {
V_54 -> V_80 =
V_36 . V_637 ;
memcpy ( V_54 -> V_79 ,
V_36 . V_638 , 4 ) ;
V_54 -> V_79 [ 4 ] = '\0' ;
} else {
V_54 -> V_80 = 0 ;
V_54 -> V_79 [ 0 ] = '\0' ;
}
}
if ( ! ( F_21 ( V_36 . V_147 ) &
V_639 ) ) {
F_25 ( V_42
L_186 ,
V_14 -> V_43 , V_35 ) ;
goto V_546;
}
if ( F_244 ( V_14 , V_17 , V_35 ,
V_36 . V_640 ) )
goto V_546;
F_33 ( & V_14 -> V_74 , V_76 ) ;
F_158 ( V_14 , V_17 ) ;
if ( V_54 )
F_41 ( V_54 ) ;
return;
V_546:
F_33 ( & V_14 -> V_74 , V_76 ) ;
if ( V_54 )
F_41 ( V_54 ) ;
}
static int
F_246 ( struct V_13 * V_14 , T_4 V_35 , T_6 V_641 ,
T_6 V_642 )
{
T_9 V_37 ;
T_8 V_36 ;
T_38 V_591 ;
struct V_53 * V_54 ;
T_10 V_38 ;
T_1 V_17 ;
T_10 V_98 ;
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
V_98 = F_79 ( V_36 . V_148 ) ;
if ( ! ( F_61 ( V_98 ) ) )
return - 1 ;
F_162 ( V_35 , V_14 -> V_85 ) ;
V_17 = F_18 ( V_36 . V_19 ) ;
if ( ! ( F_21 ( V_36 . V_147 ) &
V_639 ) ) {
F_25 ( V_42 L_187 ,
V_14 -> V_43 , V_35 ) ;
return - 1 ;
}
if ( F_244 ( V_14 , V_17 , V_35 ,
V_36 . V_640 ) )
return - 1 ;
V_54 = F_35 ( V_14 ,
V_17 ) ;
if ( V_54 ) {
F_48 ( V_35 , V_14 -> V_85 ) ;
F_41 ( V_54 ) ;
return - 1 ;
}
V_54 = F_9 ( sizeof( struct V_53 ) ,
V_132 ) ;
if ( ! V_54 ) {
F_25 ( V_42 L_2 ,
V_14 -> V_43 , __FILE__ , __LINE__ , V_44 ) ;
return 0 ;
}
F_10 ( & V_54 -> V_4 ) ;
V_54 -> V_35 = V_35 ;
if ( F_23 ( V_14 ,
F_21 ( V_36 . V_608 ) ,
& V_54 -> V_86 ) != 0 )
F_25 ( V_42 L_2 ,
V_14 -> V_43 , __FILE__ , __LINE__ , V_44 ) ;
V_54 -> V_78 =
F_21 ( V_36 . V_541 ) ;
if ( V_54 -> V_78 != 0 )
V_54 -> V_26 =
F_21 ( V_36 . V_540 ) ;
V_54 -> V_98 = V_98 ;
V_54 -> V_17 = V_17 ;
V_54 -> V_227 = V_36 . V_635 ;
V_54 -> V_141 = ( F_21 ( V_36 . V_147 ) &
V_643 ) ? 1 : 0 ;
if ( F_21 ( V_36 . V_147 )
& V_636 ) {
V_54 -> V_80 =
V_36 . V_637 ;
memcpy ( V_54 -> V_79 ,
V_36 . V_638 , 4 ) ;
V_54 -> V_79 [ 4 ] = '\0' ;
} else {
V_54 -> V_80 = 0 ;
V_54 -> V_79 [ 0 ] = '\0' ;
}
if ( V_54 -> V_78 && ! ( F_236 (
V_14 , & V_37 , & V_591 , V_603 ,
V_54 -> V_78 ) ) )
V_54 -> V_22 =
F_18 ( V_591 . V_24 ) ;
V_54 -> V_20 = F_18 ( V_36 . V_21 ) ;
if ( V_14 -> V_644 )
F_51 ( V_14 , V_54 ) ;
else
F_45 ( V_14 , V_54 ) ;
F_41 ( V_54 ) ;
return 0 ;
}
static void
F_43 ( struct V_13 * V_14 ,
struct V_53 * V_54 )
{
struct V_72 * V_120 ;
if ( ( V_14 -> V_547 -> V_548 == V_549 ) &&
( V_54 -> V_539 ) ) {
F_211 ( V_14 , V_54 ) ;
V_54 -> V_539 = 0 ;
}
F_46 ( V_14 , F_13 ( V_42
L_188 ,
V_14 -> V_43 , V_44 ,
V_54 -> V_35 , ( unsigned long long )
V_54 -> V_17 ) ) ;
if ( V_54 -> V_78 != 0 )
F_46 ( V_14 , F_13 ( V_42
L_189 ,
V_14 -> V_43 , V_44 ,
( unsigned long long ) V_54 -> V_22 ,
V_54 -> V_26 ) ) ;
if ( V_54 -> V_79 [ 0 ] != '\0' )
F_46 ( V_14 , F_13 ( V_42
L_190 ,
V_14 -> V_43 , V_44 ,
V_54 -> V_80 ,
V_54 -> V_79 ) ) ;
if ( V_54 -> V_87 && V_54 -> V_87 -> V_122 ) {
V_120 = V_54 -> V_87 -> V_122 ;
V_120 -> V_339 = 1 ;
F_158 ( V_14 , V_54 -> V_17 ) ;
V_120 -> V_35 =
V_134 ;
}
if ( ! V_14 -> V_84 )
F_50 ( V_14 ,
V_54 -> V_17 ,
V_54 -> V_86 ) ;
F_13 ( V_42
L_7 ,
V_14 -> V_43 , V_54 -> V_35 ,
( unsigned long long ) V_54 -> V_17 ) ;
if ( V_54 -> V_78 != 0 )
F_13 ( V_42
L_191 ,
V_14 -> V_43 ,
( unsigned long long ) V_54 -> V_22 ,
V_54 -> V_26 ) ;
if ( V_54 -> V_79 [ 0 ] != '\0' )
F_13 ( V_42
L_9 ,
V_14 -> V_43 , V_54 -> V_80 ,
V_54 -> V_79 ) ;
F_46 ( V_14 , F_13 ( V_42
L_192 ,
V_14 -> V_43 , V_44 ,
V_54 -> V_35 , ( unsigned long long )
V_54 -> V_17 ) ) ;
if ( V_54 -> V_78 != 0 )
F_46 ( V_14 , F_13 ( V_42
L_193 ,
V_14 -> V_43 , V_44 ,
( unsigned long long ) V_54 -> V_22 ,
V_54 -> V_26 ) ) ;
if ( V_54 -> V_79 [ 0 ] != '\0' )
F_46 ( V_14 , F_13 ( V_42
L_194 ,
V_14 -> V_43 , V_44 , V_54 -> V_80 ,
V_54 -> V_79 ) ) ;
}
static void
F_247 ( struct V_13 * V_14 ,
T_19 * V_311 )
{
int V_108 ;
T_4 V_35 ;
T_4 V_329 ;
T_6 V_634 ;
char * V_645 = NULL ;
T_6 V_583 , V_646 ;
switch ( V_311 -> V_375 ) {
case V_382 :
V_645 = L_195 ;
break;
case V_379 :
V_645 = L_196 ;
break;
case V_378 :
case 0 :
V_645 = L_197 ;
break;
case V_376 :
V_645 = L_198 ;
break;
default:
V_645 = L_199 ;
break;
}
F_13 ( V_42 L_200 ,
V_14 -> V_43 , V_645 ) ;
F_13 ( L_201 \
L_202 ,
F_21 ( V_311 -> V_374 ) ,
F_21 ( V_311 -> V_541 ) ,
V_311 -> V_647 , V_311 -> V_330 ) ;
for ( V_108 = 0 ; V_108 < V_311 -> V_330 ; V_108 ++ ) {
V_35 = F_21 ( V_311 -> V_331 [ V_108 ] . V_332 ) ;
if ( ! V_35 )
continue;
V_634 = V_311 -> V_647 + V_108 ;
V_329 = V_311 -> V_331 [ V_108 ] . V_333 &
V_334 ;
switch ( V_329 ) {
case V_648 :
V_645 = L_203 ;
break;
case V_373 :
V_645 = L_204 ;
break;
case V_335 :
V_645 = L_205 ;
break;
case V_649 :
V_645 = L_206 ;
break;
case V_650 :
V_645 = L_207 ;
break;
default:
V_645 = L_47 ;
break;
}
V_583 = V_311 -> V_331 [ V_108 ] . V_651 >> 4 ;
V_646 = V_311 -> V_331 [ V_108 ] . V_651 & 0xF ;
F_13 ( L_208 \
L_209 , V_634 ,
V_35 , V_645 , V_583 , V_646 ) ;
}
}
static int
F_248 ( struct V_13 * V_14 ,
struct V_3 * V_7 )
{
int V_108 ;
T_4 V_606 , V_35 ;
T_4 V_329 ;
T_6 V_634 , V_652 ;
struct V_94 * V_95 ;
T_1 V_17 ;
unsigned long V_76 ;
T_6 V_583 , V_646 ;
T_19 * V_311 =
( T_19 * )
V_7 -> V_311 ;
if ( V_14 -> V_15 & V_653 )
F_247 ( V_14 , V_311 ) ;
if ( V_14 -> V_82 || V_14 -> V_266 || V_14 -> V_267 )
return 0 ;
if ( ! V_14 -> V_39 . V_40 )
F_230 ( V_14 ) ;
else
F_227 ( V_14 ) ;
if ( V_7 -> V_381 ) {
F_46 ( V_14 , F_13 ( V_42
L_210 , V_14 -> V_43 ) ) ;
return 0 ;
}
V_606 = F_21 ( V_311 -> V_374 ) ;
if ( V_311 -> V_375 == V_382 )
if ( F_237 ( V_14 , V_606 ) != 0 )
return 0 ;
F_32 ( & V_14 -> V_96 , V_76 ) ;
V_95 = F_58 ( V_14 ,
V_606 ) ;
if ( V_95 ) {
V_17 = V_95 -> V_17 ;
V_652 = V_95 -> V_40 ;
} else if ( V_606 < V_14 -> V_39 . V_40 ) {
V_17 = V_14 -> V_39 . V_17 ;
V_652 = V_14 -> V_39 . V_40 ;
} else {
F_33 ( & V_14 -> V_96 , V_76 ) ;
return 0 ;
}
F_33 ( & V_14 -> V_96 , V_76 ) ;
for ( V_108 = 0 ; V_108 < V_311 -> V_330 ; V_108 ++ ) {
if ( V_7 -> V_381 ) {
F_46 ( V_14 , F_13 ( V_42
L_210 , V_14 -> V_43 ) ) ;
return 0 ;
}
if ( V_14 -> V_266 || V_14 -> V_267 )
return 0 ;
V_634 = V_311 -> V_647 + V_108 ;
if ( V_634 >= V_652 )
continue;
V_329 = V_311 -> V_331 [ V_108 ] . V_333 &
V_334 ;
if ( ( V_311 -> V_331 [ V_108 ] . V_333 &
V_654 ) && ( V_329 !=
V_373 ) )
continue;
V_35 = F_21 ( V_311 -> V_331 [ V_108 ] . V_332 ) ;
if ( ! V_35 )
continue;
V_583 = V_311 -> V_331 [ V_108 ] . V_651 >> 4 ;
V_646 = V_311 -> V_331 [ V_108 ] . V_651 & 0xF ;
switch ( V_329 ) {
case V_649 :
if ( V_14 -> V_82 )
break;
if ( V_583 == V_646 )
break;
F_229 ( V_14 , V_17 ,
V_35 , V_634 , V_583 ) ;
if ( V_583 < V_588 )
break;
F_245 ( V_14 , V_17 , V_35 ,
V_634 , V_583 ) ;
if ( ! F_73 ( V_35 , V_14 -> V_85 ) )
break;
case V_648 :
if ( V_14 -> V_82 )
break;
F_229 ( V_14 , V_17 ,
V_35 , V_634 , V_583 ) ;
F_246 ( V_14 , V_35 , V_634 , 0 ) ;
break;
case V_373 :
F_42 ( V_14 , V_35 ) ;
break;
}
}
if ( V_311 -> V_375 == V_379 &&
V_95 )
F_241 ( V_14 , V_17 ) ;
return 0 ;
}
static void
F_249 ( struct V_13 * V_14 ,
T_33 * V_311 )
{
char * V_655 = NULL ;
switch ( V_311 -> V_389 ) {
case V_554 :
V_655 = L_211 ;
break;
case V_656 :
V_655 = L_212 ;
break;
case V_657 :
V_655 = L_213 ;
break;
case V_658 :
V_655 = L_214 ;
break;
case V_659 :
V_655 = L_215 ;
break;
case V_660 :
V_655 = L_216 ;
break;
case V_661 :
V_655 = L_217 ;
break;
case V_662 :
V_655 = L_218 ;
break;
case V_663 :
V_655 = L_219 ;
break;
case V_664 :
V_655 = L_220 ;
break;
case V_665 :
V_655 = L_221 ;
break;
case V_666 :
V_655 = L_222 ;
break;
case V_667 :
V_655 = L_223 ;
break;
default:
V_655 = L_224 ;
break;
}
F_13 ( V_42 L_225
L_226 ,
V_14 -> V_43 , V_655 , F_21 ( V_311 -> V_202 ) ,
( unsigned long long ) F_18 ( V_311 -> V_19 ) ,
F_21 ( V_311 -> V_529 ) ) ;
if ( V_311 -> V_389 == V_554 )
F_13 ( V_42 L_227 , V_14 -> V_43 ,
V_311 -> V_555 , V_311 -> V_668 ) ;
F_13 ( L_228 ) ;
}
static void
F_250 ( struct V_13 * V_14 ,
struct V_3 * V_7 )
{
struct V_72 * V_303 ;
struct V_53 * V_54 ;
T_1 V_17 ;
unsigned long V_76 ;
T_33 * V_311 =
( T_33 * )
V_7 -> V_311 ;
if ( V_14 -> V_15 & V_653 )
F_249 ( V_14 ,
V_311 ) ;
if ( ( V_14 -> V_204 . V_669 >> 8 ) < 0xC )
return;
if ( V_311 -> V_389 !=
V_657 &&
V_311 -> V_389 !=
V_663 )
return;
F_32 ( & V_14 -> V_74 , V_76 ) ;
V_17 = F_18 ( V_311 -> V_19 ) ;
V_54 = F_34 ( V_14 ,
V_17 ) ;
if ( ! V_54 || ! V_54 -> V_87 )
goto V_91;
V_303 = V_54 -> V_87 -> V_122 ;
if ( ! V_303 )
goto V_91;
if ( V_311 -> V_389 ==
V_657 )
V_303 -> V_256 = 1 ;
else
V_303 -> V_256 = 0 ;
V_91:
if ( V_54 )
F_41 ( V_54 ) ;
F_33 ( & V_14 -> V_74 , V_76 ) ;
}
static void
F_251 ( struct V_13 * V_14 ,
T_41 * V_311 )
{
char * V_655 = NULL ;
switch ( V_311 -> V_389 ) {
case V_670 :
V_655 = L_229 ;
break;
case V_671 :
V_655 = L_230 ;
break;
default:
V_655 = L_224 ;
break;
}
F_13 ( V_42 L_231
L_232
L_233 , V_14 -> V_43 , V_655 ,
F_21 ( V_311 -> V_541 ) ,
( unsigned long long ) F_18 ( V_311 -> V_24 ) ,
F_21 ( V_311 -> V_672 ) ) ;
}
static void
F_252 ( struct V_13 * V_14 ,
struct V_3 * V_7 )
{
if ( V_14 -> V_15 & V_653 )
F_251 ( V_14 ,
( T_41 * )
V_7 -> V_311 ) ;
}
static void
F_253 ( struct V_13 * V_14 ,
struct V_3 * V_7 )
{
struct V_103 * V_106 ;
struct V_112 * V_75 ;
T_4 V_104 , V_35 ;
T_10 V_111 ;
struct V_118 * V_119 ;
T_10 V_673 ;
T_10 V_674 ;
T_18 * V_37 ;
T_42 * V_311 =
( T_42 * )
V_7 -> V_311 ;
T_4 V_38 ;
unsigned long V_76 ;
int V_2 ;
T_6 V_675 = 0 ;
T_6 V_676 ;
F_130 ( & V_14 -> V_247 . V_264 ) ;
F_13 ( V_42
L_234 ,
V_14 -> V_43 , V_44 , V_311 -> V_635 ,
V_311 -> V_677 ) ;
F_159 ( V_14 ) ;
F_32 ( & V_14 -> V_107 , V_76 ) ;
V_37 = V_14 -> V_247 . V_246 ;
V_678:
if ( V_675 ++ == 5 ) {
F_46 ( V_14 , F_13 ( V_42 L_235 ,
V_14 -> V_43 , V_44 ) ) ;
goto V_91;
} else if ( V_675 > 1 )
F_46 ( V_14 , F_13 ( V_42 L_236 ,
V_14 -> V_43 , V_44 , V_675 - 1 ) ) ;
V_673 = 0 ;
V_674 = 0 ;
for ( V_104 = 1 ; V_104 <= V_14 -> V_109 ; V_104 ++ ) {
if ( V_14 -> V_82 )
goto V_91;
V_106 = F_62 ( V_14 , V_104 ) ;
if ( ! V_106 )
continue;
V_75 = V_106 -> V_51 ;
V_119 = V_75 -> V_122 ;
if ( ! V_119 || ! V_119 -> V_124 )
continue;
if ( V_119 -> V_124 -> V_76 &
V_140 )
continue;
if ( V_119 -> V_124 -> V_76 &
V_125 )
continue;
V_35 = V_119 -> V_124 -> V_35 ;
V_111 = V_119 -> V_111 ;
V_674 ++ ;
if ( V_14 -> V_82 )
goto V_91;
F_33 ( & V_14 -> V_107 , V_76 ) ;
V_2 = F_113 ( V_14 , V_35 , 0 , 0 , V_111 ,
V_295 , V_104 , 30 ) ;
if ( V_2 == V_265 ) {
F_76 ( V_225 , V_75 ,
L_237
L_238 , V_106 ) ;
F_32 ( & V_14 -> V_107 , V_76 ) ;
goto V_678;
}
V_38 = F_21 ( V_37 -> V_46 )
& V_47 ;
if ( V_38 != V_48 ) {
F_76 ( V_225 , V_75 ,
L_239 ,
V_38 , V_106 ) ;
F_32 ( & V_14 -> V_107 , V_76 ) ;
goto V_678;
}
if ( V_37 -> V_291 ==
V_242 ||
V_37 -> V_291 ==
V_244 ) {
F_32 ( & V_14 -> V_107 , V_76 ) ;
continue;
}
V_676 = 0 ;
V_679:
if ( V_676 ++ == 60 ) {
F_46 ( V_14 , F_13 ( V_42
L_240 , V_14 -> V_43 ,
V_44 ) ) ;
F_32 ( & V_14 -> V_107 , V_76 ) ;
goto V_678;
}
if ( V_14 -> V_82 )
goto V_680;
V_2 = F_113 ( V_14 , V_35 , V_75 -> V_90 , V_75 -> V_89 ,
V_75 -> V_111 , V_275 , V_104 ,
30 ) ;
if ( V_2 == V_265 ) {
F_76 ( V_225 , V_75 ,
L_241
L_242 , V_106 ) ;
goto V_679;
}
if ( V_676 > 1 )
F_76 ( V_225 , V_75 ,
L_243
L_244 ,
V_676 - 1 , V_106 ) ;
V_673 += F_79 ( V_37 -> V_289 ) ;
F_32 ( & V_14 -> V_107 , V_76 ) ;
}
if ( V_14 -> V_681 ) {
F_46 ( V_14 , F_13 ( V_42
L_245 ,
V_14 -> V_43 , V_44 ) ) ;
V_14 -> V_681 = 0 ;
goto V_678;
}
V_91:
F_33 ( & V_14 -> V_107 , V_76 ) ;
V_680:
F_46 ( V_14 , F_13 ( V_42
L_246 ,
V_14 -> V_43 , V_44 , V_674 , V_673 ) ) ;
V_14 -> V_682 = 0 ;
if ( ! V_14 -> V_82 )
F_157 ( V_14 ) ;
F_131 ( & V_14 -> V_247 . V_264 ) ;
}
static void
F_254 ( struct V_13 * V_14 ,
struct V_3 * V_7 )
{
T_43 * V_311 =
( T_43 * ) V_7 -> V_311 ;
if ( V_14 -> V_15 & V_653 ) {
F_13 ( V_42 L_247 , V_14 -> V_43 ,
( V_311 -> V_389 == V_683 ) ?
L_248 : L_249 ) ;
if ( V_311 -> V_684 )
F_13 ( L_250 ,
F_79 ( V_311 -> V_684 ) ) ;
F_13 ( L_228 ) ;
}
if ( V_311 -> V_389 == V_683 &&
! V_14 -> V_39 . V_40 ) {
if ( V_685 > 0 && V_14 -> V_82 ) {
while ( V_14 -> V_82 )
F_255 ( 1 ) ;
}
F_230 ( V_14 ) ;
}
}
static int
F_256 ( struct V_13 * V_14 , T_4 V_35 , T_6 V_686 )
{
T_44 * V_260 ;
T_45 * V_37 ;
T_4 V_104 ;
T_6 V_687 = 0 ;
int V_28 = 0 ;
T_4 V_38 ;
T_10 V_497 ;
if ( V_14 -> V_161 == V_162 )
return V_28 ;
F_130 ( & V_14 -> V_612 . V_264 ) ;
if ( V_14 -> V_612 . V_248 != V_249 ) {
F_25 ( V_42 L_251 ,
V_14 -> V_43 , V_44 ) ;
V_28 = - V_688 ;
goto V_91;
}
V_14 -> V_612 . V_248 = V_253 ;
V_104 = F_167 ( V_14 , V_14 -> V_689 ) ;
if ( ! V_104 ) {
F_25 ( V_42 L_52 ,
V_14 -> V_43 , V_44 ) ;
V_14 -> V_612 . V_248 = V_249 ;
V_28 = - V_688 ;
goto V_91;
}
V_260 = F_121 ( V_14 , V_104 ) ;
V_14 -> V_612 . V_104 = V_104 ;
memset ( V_260 , 0 , sizeof( T_44 ) ) ;
V_260 -> V_276 = V_690 ;
V_260 -> V_534 = V_691 ;
V_260 -> V_201 = V_686 ;
F_46 ( V_14 , F_13 ( V_42 L_252\
L_253 , V_14 -> V_43 ,
V_35 , V_686 ) ) ;
F_124 ( & V_14 -> V_612 . V_254 ) ;
V_14 -> V_353 ( V_14 , V_104 ) ;
F_125 ( & V_14 -> V_612 . V_254 , 10 * V_285 ) ;
if ( ! ( V_14 -> V_612 . V_248 & V_250 ) ) {
F_25 ( V_42 L_54 ,
V_14 -> V_43 , V_44 ) ;
if ( ! ( V_14 -> V_612 . V_248 & V_286 ) )
V_687 = 1 ;
V_28 = - V_692 ;
goto V_91;
}
if ( V_14 -> V_612 . V_248 & V_252 ) {
V_37 = V_14 -> V_612 . V_246 ;
V_38 = F_21 ( V_37 -> V_46 ) ;
if ( V_38 & V_562 )
V_497 = F_79 ( V_37 -> V_288 ) ;
else
V_497 = 0 ;
V_38 &= V_47 ;
if ( V_38 != V_48 ) {
F_46 ( V_14 , F_13 ( V_42
L_254
L_255 , V_14 -> V_43 , V_38 ,
V_497 ) ) ;
V_28 = - V_692 ;
} else
F_46 ( V_14 , F_13 ( V_42
L_256 ,
V_14 -> V_43 ) ) ;
}
V_91:
V_14 -> V_612 . V_248 = V_249 ;
F_131 ( & V_14 -> V_612 . V_264 ) ;
if ( V_687 )
F_117 ( V_14 , V_269 ) ;
return V_28 ;
}
static void
F_257 ( struct V_112 * V_75 , void * V_145 )
{
V_75 -> V_145 = V_145 ? 1 : 0 ;
F_76 ( V_146 , V_75 , L_257 ,
V_75 -> V_145 ? L_258 : L_259 ) ;
F_258 ( F_259 ( V_75 ) ) ;
}
static void
F_260 ( struct V_13 * V_14 ,
T_24 * V_385 )
{
struct V_55 * V_56 ;
unsigned long V_76 ;
T_1 V_60 ;
T_4 V_35 = F_21 ( V_385 -> V_392 ) ;
int V_28 ;
F_102 ( V_14 , V_35 , & V_60 ) ;
if ( ! V_60 ) {
F_25 ( V_42
L_2 , V_14 -> V_43 ,
__FILE__ , __LINE__ , V_44 ) ;
return;
}
F_32 ( & V_14 -> V_92 , V_76 ) ;
V_56 = F_54 ( V_14 , V_60 ) ;
F_33 ( & V_14 -> V_92 , V_76 ) ;
if ( V_56 )
return;
V_56 = F_9 ( sizeof( struct V_55 ) , V_132 ) ;
if ( ! V_56 ) {
F_25 ( V_42
L_2 , V_14 -> V_43 ,
__FILE__ , __LINE__ , V_44 ) ;
return;
}
V_56 -> V_89 = V_14 -> V_693 ++ ;
V_56 -> V_90 = V_135 ;
V_56 -> V_35 = V_35 ;
V_56 -> V_60 = V_60 ;
F_55 ( V_14 , V_56 ) ;
if ( ! V_14 -> V_644 ) {
V_28 = F_261 ( V_14 -> V_115 , V_135 ,
V_56 -> V_89 , 0 ) ;
if ( V_28 )
F_56 ( V_14 , V_56 ) ;
} else {
F_32 ( & V_14 -> V_92 , V_76 ) ;
F_26 ( V_14 , V_56 , 1 ) ;
F_33 ( & V_14 -> V_92 , V_76 ) ;
}
}
static void
F_262 ( struct V_13 * V_14 , T_4 V_35 )
{
struct V_55 * V_56 ;
unsigned long V_76 ;
struct V_72 * V_120 ;
struct V_128 * V_87 = NULL ;
F_32 ( & V_14 -> V_92 , V_76 ) ;
V_56 = F_53 ( V_14 , V_35 ) ;
if ( V_56 ) {
if ( V_56 -> V_87 ) {
V_87 = V_56 -> V_87 ;
V_120 = V_87 -> V_122 ;
V_120 -> V_339 = 1 ;
}
F_13 ( V_42 L_260 ,
V_14 -> V_43 , V_56 -> V_35 ,
( unsigned long long ) V_56 -> V_60 ) ;
F_57 ( & V_56 -> V_81 ) ;
F_2 ( V_56 ) ;
}
F_33 ( & V_14 -> V_92 , V_76 ) ;
if ( V_87 )
F_263 ( & V_87 -> V_129 ) ;
}
static void
F_264 ( struct V_13 * V_14 ,
T_24 * V_385 )
{
struct V_53 * V_54 ;
struct V_128 * V_87 = NULL ;
struct V_72 * V_120 ;
unsigned long V_76 ;
T_4 V_35 = F_21 ( V_385 -> V_394 ) ;
F_32 ( & V_14 -> V_74 , V_76 ) ;
V_54 = F_36 ( V_14 , V_35 ) ;
if ( V_54 ) {
V_54 -> V_210 = 0 ;
V_54 -> V_211 = 0 ;
F_48 ( V_35 , V_14 -> V_139 ) ;
if ( V_54 -> V_87 && V_54 -> V_87 -> V_122 ) {
V_87 = V_54 -> V_87 ;
V_120 = V_87 -> V_122 ;
V_120 -> V_76 &=
~ V_140 ;
}
}
F_33 ( & V_14 -> V_74 , V_76 ) ;
if ( ! V_54 )
return;
if ( V_87 )
F_265 ( V_87 , NULL , F_257 ) ;
F_41 ( V_54 ) ;
}
static void
F_266 ( struct V_13 * V_14 ,
T_24 * V_385 )
{
struct V_53 * V_54 ;
struct V_128 * V_87 = NULL ;
struct V_72 * V_120 ;
unsigned long V_76 ;
T_4 V_35 = F_21 ( V_385 -> V_394 ) ;
T_4 V_210 = 0 ;
T_1 V_211 = 0 ;
F_101 ( V_14 , V_35 , & V_210 ) ;
if ( V_210 )
F_102 ( V_14 , V_210 ,
& V_211 ) ;
F_32 ( & V_14 -> V_74 , V_76 ) ;
V_54 = F_36 ( V_14 , V_35 ) ;
if ( V_54 ) {
F_162 ( V_35 , V_14 -> V_139 ) ;
if ( V_54 -> V_87 && V_54 -> V_87 -> V_122 ) {
V_87 = V_54 -> V_87 ;
V_120 = V_87 -> V_122 ;
V_120 -> V_76 |=
V_140 ;
V_54 -> V_210 = V_210 ;
V_54 -> V_211 = V_211 ;
}
}
F_33 ( & V_14 -> V_74 , V_76 ) ;
if ( ! V_54 )
return;
F_256 ( V_14 , V_35 , V_385 -> V_201 ) ;
if ( V_87 )
F_265 ( V_87 , ( void * ) 1 , F_257 ) ;
F_41 ( V_54 ) ;
}
static void
F_267 ( struct V_13 * V_14 ,
T_24 * V_385 )
{
T_4 V_35 = F_21 ( V_385 -> V_394 ) ;
F_42 ( V_14 , V_35 ) ;
}
static void
F_268 ( struct V_13 * V_14 ,
T_24 * V_385 )
{
struct V_53 * V_54 ;
T_4 V_35 = F_21 ( V_385 -> V_394 ) ;
T_9 V_37 ;
T_8 V_36 ;
T_10 V_38 ;
T_1 V_17 ;
T_4 V_606 ;
F_162 ( V_35 , V_14 -> V_139 ) ;
V_54 = F_37 ( V_14 , V_35 ) ;
if ( V_54 ) {
F_256 ( V_14 , V_35 , V_385 -> V_201 ) ;
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
V_606 = F_21 ( V_36 . V_608 ) ;
if ( ! F_23 ( V_14 , V_606 , & V_17 ) )
F_229 ( V_14 , V_17 , V_35 ,
V_36 . V_635 , V_588 ) ;
F_256 ( V_14 , V_35 , V_385 -> V_201 ) ;
F_246 ( V_14 , V_35 , 0 , 1 ) ;
}
static void
F_269 ( struct V_13 * V_14 ,
T_23 * V_311 )
{
T_24 * V_385 ;
T_6 V_694 ;
int V_108 ;
char * V_655 = NULL , * V_695 = NULL ;
V_385 = ( T_24 * ) & V_311 -> V_386 [ 0 ] ;
F_13 ( V_42 L_261 ,
V_14 -> V_43 , ( F_79 ( V_311 -> V_147 ) &
V_388 ) ?
L_262 : L_263 , V_311 -> V_387 ) ;
for ( V_108 = 0 ; V_108 < V_311 -> V_387 ; V_108 ++ , V_385 ++ ) {
switch ( V_385 -> V_389 ) {
case V_696 :
V_655 = L_195 ;
break;
case V_391 :
V_655 = L_196 ;
break;
case V_697 :
V_655 = L_264 ;
break;
case V_698 :
V_655 = L_265 ;
break;
case V_393 :
V_655 = L_266 ;
break;
case V_699 :
V_655 = L_267 ;
break;
case V_390 :
V_655 = L_268 ;
break;
case V_700 :
V_655 = L_269 ;
break;
case V_701 :
V_655 = L_270 ;
break;
default:
V_655 = L_224 ;
break;
}
V_694 = F_21 ( V_385 -> V_702 ) &
V_703 ;
switch ( V_694 ) {
case V_704 :
V_695 = L_58 ;
break;
case V_705 :
V_695 = L_271 ;
break;
case V_706 :
V_695 = L_272 ;
break;
default:
V_695 = L_273 ;
break;
}
F_13 ( L_274 \
L_275 , V_695 ,
V_655 , F_21 ( V_385 -> V_392 ) ,
F_21 ( V_385 -> V_394 ) ,
V_385 -> V_201 ) ;
}
}
static void
F_270 ( struct V_13 * V_14 ,
struct V_3 * V_7 )
{
T_24 * V_385 ;
int V_108 ;
T_6 V_707 ;
T_23 * V_311 =
( T_23 * )
V_7 -> V_311 ;
if ( ( V_14 -> V_15 & V_653 ) &&
( ! V_14 -> V_220 ) )
F_269 ( V_14 , V_311 ) ;
V_707 = ( F_79 ( V_311 -> V_147 ) &
V_388 ) ? 1 : 0 ;
V_385 = ( T_24 * ) & V_311 -> V_386 [ 0 ] ;
if ( V_14 -> V_82 &&
V_14 -> V_161 != V_162 ) {
for ( V_108 = 0 ; V_108 < V_311 -> V_387 ; V_108 ++ , V_385 ++ ) {
if ( V_385 -> V_389 == V_698 )
F_256 ( V_14 ,
F_21 ( V_385 -> V_394 ) ,
V_385 -> V_201 ) ;
}
return;
}
for ( V_108 = 0 ; V_108 < V_311 -> V_387 ; V_108 ++ , V_385 ++ ) {
switch ( V_385 -> V_389 ) {
case V_699 :
case V_696 :
if ( ! V_707 )
F_260 ( V_14 , V_385 ) ;
break;
case V_390 :
case V_391 :
if ( ! V_707 )
F_262 ( V_14 ,
F_21 ( V_385 -> V_392 ) ) ;
break;
case V_700 :
if ( ! V_14 -> V_136 )
F_266 ( V_14 , V_385 ) ;
break;
case V_701 :
if ( ! V_14 -> V_136 )
F_264 ( V_14 , V_385 ) ;
break;
case V_698 :
if ( ! V_14 -> V_136 )
F_268 ( V_14 , V_385 ) ;
break;
case V_393 :
if ( ! V_14 -> V_136 )
F_267 ( V_14 , V_385 ) ;
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
T_10 V_169 ;
int V_28 ;
T_25 * V_311 =
( T_25 * ) V_7 -> V_311 ;
if ( V_14 -> V_82 )
return;
if ( V_311 -> V_389 != V_395 )
return;
V_35 = F_21 ( V_311 -> V_392 ) ;
V_169 = F_79 ( V_311 -> V_396 ) ;
if ( ! V_14 -> V_220 )
F_46 ( V_14 , F_13 ( V_42
L_276 ,
V_14 -> V_43 , V_44 , V_35 ,
F_79 ( V_311 -> V_708 ) , V_169 ) ) ;
switch ( V_169 ) {
case V_179 :
case V_178 :
F_262 ( V_14 , V_35 ) ;
break;
case V_174 :
case V_176 :
case V_173 :
F_32 ( & V_14 -> V_92 , V_76 ) ;
V_56 = F_53 ( V_14 , V_35 ) ;
F_33 ( & V_14 -> V_92 , V_76 ) ;
if ( V_56 )
break;
F_102 ( V_14 , V_35 , & V_60 ) ;
if ( ! V_60 ) {
F_25 ( V_42
L_2 , V_14 -> V_43 ,
__FILE__ , __LINE__ , V_44 ) ;
break;
}
V_56 = F_9 ( sizeof( struct V_55 ) , V_132 ) ;
if ( ! V_56 ) {
F_25 ( V_42
L_2 , V_14 -> V_43 ,
__FILE__ , __LINE__ , V_44 ) ;
break;
}
V_56 -> V_89 = V_14 -> V_693 ++ ;
V_56 -> V_90 = V_135 ;
V_56 -> V_35 = V_35 ;
V_56 -> V_60 = V_60 ;
F_55 ( V_14 , V_56 ) ;
V_28 = F_261 ( V_14 -> V_115 , V_135 ,
V_56 -> V_89 , 0 ) ;
if ( V_28 )
F_56 ( V_14 , V_56 ) ;
break;
case V_709 :
default:
break;
}
}
static void
F_272 ( struct V_13 * V_14 ,
struct V_3 * V_7 )
{
T_4 V_35 , V_606 ;
T_10 V_169 ;
struct V_53 * V_54 ;
T_9 V_37 ;
T_8 V_36 ;
T_10 V_38 ;
T_46 * V_311 =
( T_46 * ) V_7 -> V_311 ;
T_1 V_17 ;
if ( V_14 -> V_82 )
return;
if ( V_311 -> V_389 != V_710 )
return;
V_35 = F_21 ( V_311 -> V_394 ) ;
V_169 = F_79 ( V_311 -> V_396 ) ;
if ( ! V_14 -> V_220 )
F_46 ( V_14 , F_13 ( V_42
L_276 ,
V_14 -> V_43 , V_44 , V_35 ,
F_79 ( V_311 -> V_708 ) , V_169 ) ) ;
switch ( V_169 ) {
case V_711 :
case V_712 :
case V_713 :
case V_714 :
case V_715 :
if ( ! V_14 -> V_136 )
F_162 ( V_35 , V_14 -> V_139 ) ;
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
V_606 = F_21 ( V_36 . V_608 ) ;
if ( ! F_23 ( V_14 , V_606 , & V_17 ) )
F_229 ( V_14 , V_17 , V_35 ,
V_36 . V_635 , V_588 ) ;
F_246 ( V_14 , V_35 , 0 , 1 ) ;
break;
case V_716 :
case V_717 :
case V_718 :
default:
break;
}
}
static void
F_273 ( struct V_13 * V_14 ,
T_47 * V_311 )
{
char * V_655 = NULL ;
switch ( V_311 -> V_719 ) {
case V_720 :
V_655 = L_277 ;
break;
case V_721 :
V_655 = L_278 ;
break;
case V_722 :
V_655 = L_279 ;
break;
case V_723 :
V_655 = L_280 ;
break;
case V_724 :
V_655 = L_281 ;
break;
}
if ( ! V_655 )
return;
F_13 ( V_42 L_282 \
L_283 ,
V_14 -> V_43 , V_655 ,
F_21 ( V_311 -> V_392 ) ,
V_311 -> V_725 ) ;
}
static void
F_274 ( struct V_13 * V_14 ,
struct V_3 * V_7 )
{
T_47 * V_311 =
( T_47 * )
V_7 -> V_311 ;
static struct V_55 * V_56 ;
unsigned long V_76 ;
T_4 V_35 ;
if ( ( V_14 -> V_15 & V_653 ) &&
( ! V_14 -> V_220 ) )
F_273 ( V_14 ,
V_311 ) ;
if ( V_311 -> V_719 == V_720 ) {
F_32 ( & V_14 -> V_92 , V_76 ) ;
V_35 = F_21 ( V_311 -> V_392 ) ;
V_56 = F_53 ( V_14 , V_35 ) ;
if ( V_56 )
V_56 -> V_157 =
V_311 -> V_725 ;
F_33 ( & V_14 -> V_92 , V_76 ) ;
}
}
static void
F_275 ( struct V_13 * V_14 )
{
struct V_118 * V_119 ;
struct V_112 * V_75 ;
F_111 (sdev, ioc->shost) {
V_119 = V_75 -> V_122 ;
if ( V_119 && V_119 -> V_124 )
V_119 -> V_124 -> V_339 = 1 ;
}
}
static void
F_276 ( struct V_13 * V_14 ,
T_8 * V_36 )
{
struct V_72 * V_120 = NULL ;
struct V_128 * V_87 ;
struct V_53 * V_54 ;
unsigned long V_76 ;
F_32 ( & V_14 -> V_74 , V_76 ) ;
F_15 (sas_device, &ioc->sas_device_list, list) {
if ( ( V_54 -> V_17 == V_36 -> V_19 ) &&
( V_54 -> V_26 == V_36 -> V_540 ) ) {
V_54 -> V_726 = 1 ;
V_87 = V_54 -> V_87 ;
if ( V_87 && V_87 -> V_122 ) {
V_120 = V_87 -> V_122 ;
V_120 -> V_256 = 0 ;
V_120 -> V_339 = 0 ;
} else
V_120 = NULL ;
if ( V_87 ) {
F_134 ( V_146 , V_87 ,
L_284 ,
V_36 -> V_202 ,
( unsigned long long )
V_54 -> V_17 ) ;
if ( V_54 -> V_78 != 0 )
F_134 ( V_146 , V_87 ,
L_285
L_95 ,
( unsigned long long )
V_54 -> V_22 ,
V_54 -> V_26 ) ;
}
if ( V_36 -> V_147 &
V_636 ) {
V_54 -> V_80 =
V_36 -> V_637 ;
memcpy ( & V_54 -> V_79 [ 0 ] ,
& V_36 -> V_638 [ 0 ] , 4 ) ;
} else {
V_54 -> V_80 = 0 ;
V_54 -> V_79 [ 0 ] = '\0' ;
}
if ( V_54 -> V_35 == V_36 -> V_202 )
goto V_91;
F_13 ( L_286 ,
V_54 -> V_35 ) ;
V_54 -> V_35 = V_36 -> V_202 ;
if ( V_120 )
V_120 -> V_35 =
V_36 -> V_202 ;
goto V_91;
}
}
V_91:
F_33 ( & V_14 -> V_74 , V_76 ) ;
}
static void
F_277 ( struct V_13 * V_14 )
{
T_8 V_36 ;
T_9 V_37 ;
T_4 V_38 ;
T_4 V_35 ;
T_10 V_98 ;
F_13 ( V_42 L_287 , V_14 -> V_43 ) ;
if ( F_39 ( & V_14 -> V_83 ) )
goto V_91;
V_35 = 0xFFFF ;
while ( ! ( F_24 ( V_14 , & V_37 ,
& V_36 , V_727 ,
V_35 ) ) ) {
V_38 = F_21 ( V_37 . V_46 ) &
V_47 ;
if ( V_38 != V_48 )
break;
V_35 = V_36 . V_202 =
F_21 ( V_36 . V_202 ) ;
V_98 = F_79 ( V_36 . V_148 ) ;
if ( ! ( F_61 ( V_98 ) ) )
continue;
V_36 . V_19 =
F_18 ( V_36 . V_19 ) ;
V_36 . V_540 = F_21 ( V_36 . V_540 ) ;
V_36 . V_147 = F_21 ( V_36 . V_147 ) ;
F_276 ( V_14 , & V_36 ) ;
}
V_91:
F_13 ( V_42 L_288 ,
V_14 -> V_43 ) ;
}
static void
F_278 ( struct V_13 * V_14 , T_1 V_60 ,
T_4 V_35 )
{
struct V_72 * V_120 = NULL ;
struct V_128 * V_87 ;
struct V_55 * V_56 ;
unsigned long V_76 ;
F_32 ( & V_14 -> V_92 , V_76 ) ;
F_15 (raid_device, &ioc->raid_device_list, list) {
if ( V_56 -> V_60 == V_60 && V_56 -> V_87 ) {
V_87 = V_56 -> V_87 ;
if ( V_87 && V_87 -> V_122 ) {
V_120 = V_87 -> V_122 ;
V_120 -> V_339 = 0 ;
} else
V_120 = NULL ;
V_56 -> V_726 = 1 ;
F_33 ( & V_14 -> V_92 , V_76 ) ;
F_134 ( V_146 , V_56 -> V_87 ,
L_289 , V_35 ,
( unsigned long long ) V_56 -> V_60 ) ;
F_99 ( V_14 , V_56 ) ;
F_32 ( & V_14 -> V_92 , V_76 ) ;
if ( V_56 -> V_35 == V_35 ) {
F_33 ( & V_14 -> V_92 ,
V_76 ) ;
return;
}
F_13 ( L_286 ,
V_56 -> V_35 ) ;
V_56 -> V_35 = V_35 ;
if ( V_120 )
V_120 -> V_35 = V_35 ;
F_33 ( & V_14 -> V_92 , V_76 ) ;
return;
}
}
F_33 ( & V_14 -> V_92 , V_76 ) ;
}
static void
F_279 ( struct V_13 * V_14 )
{
T_48 V_728 ;
T_11 V_729 ;
T_12 V_194 ;
T_9 V_37 ;
T_4 V_38 ;
T_4 V_35 ;
T_6 V_686 ;
if ( ! V_14 -> V_730 )
return;
F_13 ( V_42 L_290 ,
V_14 -> V_43 ) ;
if ( F_39 ( & V_14 -> V_93 ) )
goto V_91;
V_35 = 0xFFFF ;
while ( ! ( F_280 ( V_14 , & V_37 ,
& V_728 , V_731 , V_35 ) ) ) {
V_38 = F_21 ( V_37 . V_46 ) &
V_47 ;
if ( V_38 != V_48 )
break;
V_35 = F_21 ( V_728 . V_202 ) ;
if ( F_83 ( V_14 , & V_37 ,
& V_729 , V_158 , V_35 ,
sizeof( T_11 ) ) )
continue;
if ( V_729 . V_172 == V_173 ||
V_729 . V_172 == V_174 ||
V_729 . V_172 == V_176 )
F_278 ( V_14 ,
F_18 ( V_728 . V_732 ) , V_35 ) ;
}
if ( ! V_14 -> V_136 ) {
V_686 = 0xFF ;
memset ( V_14 -> V_139 , 0 , V_14 -> V_733 ) ;
while ( ! ( F_94 ( V_14 , & V_37 ,
& V_194 , V_734 ,
V_686 ) ) ) {
V_38 = F_21 ( V_37 . V_46 ) &
V_47 ;
if ( V_38 != V_48 )
break;
V_686 = V_194 . V_201 ;
V_35 = F_21 ( V_194 . V_202 ) ;
F_162 ( V_35 , V_14 -> V_139 ) ;
}
}
V_91:
F_13 ( V_42 L_291 ,
V_14 -> V_43 ) ;
}
static void
F_281 ( struct V_13 * V_14 , T_1 V_17 ,
T_4 V_35 )
{
struct V_94 * V_95 ;
unsigned long V_76 ;
int V_108 ;
F_32 ( & V_14 -> V_96 , V_76 ) ;
F_15 (sas_expander, &ioc->sas_expander_list, list) {
if ( V_95 -> V_17 != V_17 )
continue;
V_95 -> V_726 = 1 ;
if ( V_95 -> V_35 == V_35 )
goto V_91;
F_13 ( L_292 \
L_293 ,
( unsigned long long ) V_95 -> V_17 ,
V_95 -> V_35 , V_35 ) ;
V_95 -> V_35 = V_35 ;
for ( V_108 = 0 ; V_108 < V_95 -> V_40 ; V_108 ++ )
V_95 -> V_227 [ V_108 ] . V_35 = V_35 ;
goto V_91;
}
V_91:
F_33 ( & V_14 -> V_96 , V_76 ) ;
}
static void
F_282 ( struct V_13 * V_14 )
{
T_39 V_604 ;
T_9 V_37 ;
T_4 V_38 ;
T_1 V_17 ;
T_4 V_35 ;
F_13 ( V_42 L_294 , V_14 -> V_43 ) ;
if ( F_39 ( & V_14 -> V_97 ) )
goto V_91;
V_35 = 0xFFFF ;
while ( ! ( F_238 ( V_14 , & V_37 , & V_604 ,
V_735 , V_35 ) ) ) {
V_38 = F_21 ( V_37 . V_46 ) &
V_47 ;
if ( V_38 != V_48 )
break;
V_35 = F_21 ( V_604 . V_202 ) ;
V_17 = F_18 ( V_604 . V_19 ) ;
F_13 ( L_295 ,
V_35 ,
( unsigned long long ) V_17 ) ;
F_281 ( V_14 , V_17 , V_35 ) ;
}
V_91:
F_13 ( V_42 L_296 , V_14 -> V_43 ) ;
}
static void
F_283 ( struct V_13 * V_14 )
{
struct V_53 * V_54 , * V_736 ;
struct V_94 * V_95 , * V_737 ;
struct V_55 * V_56 , * V_738 ;
struct V_739 V_740 ;
unsigned long V_76 ;
F_284 ( V_741 ) ;
F_13 ( V_42 L_297 ,
V_14 -> V_43 ) ;
F_13 ( V_42 L_298 ,
V_14 -> V_43 ) ;
F_32 ( & V_14 -> V_74 , V_76 ) ;
F_285 (sas_device, sas_device_next,
&ioc->sas_device_list, list) {
if ( ! V_54 -> V_726 )
F_286 ( & V_54 -> V_81 , & V_741 ) ;
else
V_54 -> V_726 = 0 ;
}
F_33 ( & V_14 -> V_74 , V_76 ) ;
F_285 (sas_device, sas_device_next, &head, list) {
F_43 ( V_14 , V_54 ) ;
F_40 ( & V_54 -> V_81 ) ;
F_41 ( V_54 ) ;
}
if ( V_14 -> V_730 ) {
F_13 ( V_42 L_299 ,
V_14 -> V_43 ) ;
F_285 (raid_device, raid_device_next,
&ioc->raid_device_list, list) {
if ( ! V_56 -> V_726 )
F_262 ( V_14 ,
V_56 -> V_35 ) ;
else
V_56 -> V_726 = 0 ;
}
}
F_13 ( V_42 L_300 ,
V_14 -> V_43 ) ;
F_32 ( & V_14 -> V_96 , V_76 ) ;
F_141 ( & V_740 ) ;
F_285 (sas_expander, sas_expander_next,
&ioc->sas_expander_list, list) {
if ( ! V_95 -> V_726 )
F_286 ( & V_95 -> V_81 , & V_740 ) ;
else
V_95 -> V_726 = 0 ;
}
F_33 ( & V_14 -> V_96 , V_76 ) ;
F_285 (sas_expander, sas_expander_next, &tmp_list,
list) {
F_57 ( & V_95 -> V_81 ) ;
F_242 ( V_14 , V_95 ) ;
}
F_13 ( V_42 L_301 ,
V_14 -> V_43 ) ;
F_157 ( V_14 ) ;
}
static void
F_287 ( struct V_13 * V_14 ,
struct V_94 * V_95 , T_4 V_35 )
{
T_40 V_605 ;
T_9 V_37 ;
int V_108 ;
for ( V_108 = 0 ; V_108 < V_95 -> V_40 ; V_108 ++ ) {
if ( ( F_239 ( V_14 , & V_37 ,
& V_605 , V_108 , V_35 ) ) ) {
F_25 ( V_42 L_2 ,
V_14 -> V_43 , __FILE__ , __LINE__ , V_44 ) ;
return;
}
F_229 ( V_14 , V_95 -> V_17 ,
F_21 ( V_605 . V_332 ) , V_108 ,
V_605 . V_586 >> 4 ) ;
}
}
static void
F_288 ( struct V_13 * V_14 )
{
T_39 V_604 ;
T_8 V_36 ;
T_48 V_728 ;
T_11 V_729 ;
T_12 V_194 ;
T_24 V_385 ;
T_9 V_37 ;
T_6 V_686 ;
T_4 V_38 ;
T_4 V_35 , V_606 ;
T_1 V_17 ;
struct V_53 * V_54 ;
struct V_94 * V_742 ;
static struct V_55 * V_56 ;
T_6 V_743 ;
unsigned long V_76 ;
F_13 ( V_42 L_302 , V_14 -> V_43 ) ;
F_227 ( V_14 ) ;
F_13 ( V_42 L_303 , V_14 -> V_43 ) ;
V_35 = 0xFFFF ;
while ( ! ( F_238 ( V_14 , & V_37 , & V_604 ,
V_735 , V_35 ) ) ) {
V_38 = F_21 ( V_37 . V_46 ) &
V_47 ;
if ( V_38 != V_48 ) {
F_13 ( V_42 L_304 \
L_305 ,
V_14 -> V_43 , V_38 ,
F_79 ( V_37 . V_288 ) ) ;
break;
}
V_35 = F_21 ( V_604 . V_202 ) ;
F_32 ( & V_14 -> V_96 , V_76 ) ;
V_742 = F_59 (
V_14 , F_18 ( V_604 . V_19 ) ) ;
F_33 ( & V_14 -> V_96 , V_76 ) ;
if ( V_742 )
F_287 ( V_14 , V_742 ,
V_35 ) ;
else {
F_13 ( V_42 L_306 \
L_307 , V_14 -> V_43 ,
V_35 , ( unsigned long long )
F_18 ( V_604 . V_19 ) ) ;
F_237 ( V_14 , V_35 ) ;
F_13 ( V_42 L_308 \
L_307 , V_14 -> V_43 ,
V_35 , ( unsigned long long )
F_18 ( V_604 . V_19 ) ) ;
}
}
F_13 ( V_42 L_309 ,
V_14 -> V_43 ) ;
if ( ! V_14 -> V_730 )
goto V_744;
F_13 ( V_42 L_310 , V_14 -> V_43 ) ;
V_686 = 0xFF ;
while ( ! ( F_94 ( V_14 , & V_37 ,
& V_194 , V_734 ,
V_686 ) ) ) {
V_38 = F_21 ( V_37 . V_46 ) &
V_47 ;
if ( V_38 != V_48 ) {
F_13 ( V_42 L_311\
L_305 ,
V_14 -> V_43 , V_38 ,
F_79 ( V_37 . V_288 ) ) ;
break;
}
V_686 = V_194 . V_201 ;
V_35 = F_21 ( V_194 . V_202 ) ;
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
F_13 ( V_42 L_312 \
L_305 ,
V_14 -> V_43 , V_38 ,
F_79 ( V_37 . V_288 ) ) ;
break;
}
V_606 = F_21 ( V_36 . V_608 ) ;
if ( ! F_23 ( V_14 , V_606 ,
& V_17 ) ) {
F_13 ( V_42 L_313 \
L_314 ,
V_14 -> V_43 , V_35 , ( unsigned long long )
F_18 ( V_36 . V_19 ) ) ;
F_229 ( V_14 , V_17 ,
V_35 , V_36 . V_635 ,
V_588 ) ;
F_162 ( V_35 , V_14 -> V_139 ) ;
V_743 = 0 ;
while ( F_246 ( V_14 , V_35 , V_743 ++ ,
1 ) ) {
F_255 ( 1 ) ;
}
F_13 ( V_42 L_315 \
L_314 ,
V_14 -> V_43 , V_35 , ( unsigned long long )
F_18 ( V_36 . V_19 ) ) ;
}
}
F_13 ( V_42 L_316 ,
V_14 -> V_43 ) ;
F_13 ( V_42 L_317 , V_14 -> V_43 ) ;
V_35 = 0xFFFF ;
while ( ! ( F_280 ( V_14 , & V_37 ,
& V_728 , V_731 , V_35 ) ) ) {
V_38 = F_21 ( V_37 . V_46 ) &
V_47 ;
if ( V_38 != V_48 ) {
F_13 ( V_42 L_318 \
L_305 ,
V_14 -> V_43 , V_38 ,
F_79 ( V_37 . V_288 ) ) ;
break;
}
V_35 = F_21 ( V_728 . V_202 ) ;
F_32 ( & V_14 -> V_92 , V_76 ) ;
V_56 = F_54 ( V_14 ,
F_18 ( V_728 . V_732 ) ) ;
F_33 ( & V_14 -> V_92 , V_76 ) ;
if ( V_56 )
continue;
if ( F_83 ( V_14 , & V_37 ,
& V_729 , V_158 , V_35 ,
sizeof( T_11 ) ) )
continue;
V_38 = F_21 ( V_37 . V_46 ) &
V_47 ;
if ( V_38 != V_48 ) {
F_13 ( V_42 L_318 \
L_305 ,
V_14 -> V_43 , V_38 ,
F_79 ( V_37 . V_288 ) ) ;
break;
}
if ( V_729 . V_172 == V_173 ||
V_729 . V_172 == V_174 ||
V_729 . V_172 == V_176 ) {
memset ( & V_385 , 0 , sizeof( T_24 ) ) ;
V_385 . V_389 = V_696 ;
V_385 . V_392 = V_728 . V_202 ;
F_13 ( V_42
L_319 ,
V_14 -> V_43 , V_728 . V_202 ) ;
F_260 ( V_14 , & V_385 ) ;
F_13 ( V_42
L_320 ,
V_14 -> V_43 , V_728 . V_202 ) ;
}
}
F_13 ( V_42 L_321 ,
V_14 -> V_43 ) ;
V_744:
F_13 ( V_42 L_322 ,
V_14 -> V_43 ) ;
V_35 = 0xFFFF ;
while ( ! ( F_24 ( V_14 , & V_37 ,
& V_36 , V_727 ,
V_35 ) ) ) {
V_38 = F_21 ( V_37 . V_46 ) &
V_47 ;
if ( V_38 != V_48 ) {
F_13 ( V_42 L_323\
L_324 ,
V_14 -> V_43 , V_38 ,
F_79 ( V_37 . V_288 ) ) ;
break;
}
V_35 = F_21 ( V_36 . V_202 ) ;
if ( ! ( F_61 (
F_79 ( V_36 . V_148 ) ) ) )
continue;
V_54 = F_35 ( V_14 ,
F_18 ( V_36 . V_19 ) ) ;
if ( V_54 ) {
F_41 ( V_54 ) ;
continue;
}
V_606 = F_21 ( V_36 . V_608 ) ;
if ( ! F_23 ( V_14 , V_606 , & V_17 ) ) {
F_13 ( V_42 L_325 \
L_307 , V_14 -> V_43 ,
V_35 , ( unsigned long long )
F_18 ( V_36 . V_19 ) ) ;
F_229 ( V_14 , V_17 , V_35 ,
V_36 . V_635 , V_588 ) ;
V_743 = 0 ;
while ( F_246 ( V_14 , V_35 , V_743 ++ ,
0 ) ) {
F_255 ( 1 ) ;
}
F_13 ( V_42 L_326 \
L_307 , V_14 -> V_43 ,
V_35 , ( unsigned long long )
F_18 ( V_36 . V_19 ) ) ;
}
}
F_13 ( V_42 L_327 ,
V_14 -> V_43 ) ;
F_13 ( V_42 L_328 , V_14 -> V_43 ) ;
}
void
F_289 ( struct V_13 * V_14 , int V_745 )
{
switch ( V_745 ) {
case V_746 :
F_120 ( V_14 , F_13 ( V_42
L_329 , V_14 -> V_43 , V_44 ) ) ;
break;
case V_747 :
F_120 ( V_14 , F_13 ( V_42
L_330 , V_14 -> V_43 , V_44 ) ) ;
if ( V_14 -> V_612 . V_248 & V_253 ) {
V_14 -> V_612 . V_248 |= V_286 ;
F_177 ( V_14 , V_14 -> V_612 . V_104 ) ;
F_109 ( & V_14 -> V_612 . V_254 ) ;
}
if ( V_14 -> V_247 . V_248 & V_253 ) {
V_14 -> V_247 . V_248 |= V_286 ;
F_177 ( V_14 , V_14 -> V_247 . V_104 ) ;
F_109 ( & V_14 -> V_247 . V_254 ) ;
}
memset ( V_14 -> V_85 , 0 , V_14 -> V_748 ) ;
memset ( V_14 -> V_342 , 0 ,
V_14 -> V_749 ) ;
F_150 ( V_14 ) ;
F_189 ( V_14 ) ;
break;
case V_750 :
F_120 ( V_14 , F_13 ( V_42
L_331 , V_14 -> V_43 , V_44 ) ) ;
if ( ( ! V_14 -> V_57 ) && ! ( V_685 > 0 &&
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
if ( V_14 -> V_266 || V_14 -> V_267 ) {
F_6 ( V_7 ) ;
return;
}
switch ( V_7 -> V_312 ) {
case V_313 :
F_291 ( V_14 ,
(struct V_310 * )
V_7 -> V_311 ) ;
break;
case V_314 :
while ( F_292 ( V_14 -> V_115 ) ||
V_14 -> V_82 ) {
if ( V_14 -> V_266 )
goto V_91;
F_255 ( 1 ) ;
}
F_283 ( V_14 ) ;
F_288 ( V_14 ) ;
break;
case V_315 :
V_14 -> V_751 = 0 ;
if ( V_752 [ 0 ] != - 1 && V_752 [ 1 ] != - 1 )
F_293 ( V_14 , V_752 [ 0 ] ,
V_752 [ 1 ] ) ;
F_46 ( V_14 , F_13 ( V_42
L_332 ,
V_14 -> V_43 ) ) ;
break;
case V_543 :
F_209 ( V_14 , V_7 -> V_544 ) ;
break;
case V_380 :
F_248 ( V_14 , V_7 ) ;
break;
case V_552 :
F_250 ( V_14 , V_7 ) ;
break;
case V_753 :
F_254 ( V_14 , V_7 ) ;
break;
case V_754 :
F_253 ( V_14 , V_7 ) ;
break;
case V_755 :
F_252 ( V_14 ,
V_7 ) ;
break;
case V_756 :
F_270 ( V_14 , V_7 ) ;
break;
case V_757 :
F_271 ( V_14 , V_7 ) ;
break;
case V_758 :
F_272 ( V_14 , V_7 ) ;
break;
case V_759 :
F_274 ( V_14 , V_7 ) ;
break;
}
V_91:
F_6 ( V_7 ) ;
}
static void
V_309 ( struct V_760 * V_308 )
{
struct V_3 * V_7 = F_3 ( V_308 ,
struct V_3 , V_308 ) ;
F_290 ( V_7 -> V_14 , V_7 ) ;
}
T_6
F_294 ( struct V_13 * V_14 , T_6 V_245 ,
T_10 V_246 )
{
struct V_3 * V_7 ;
T_32 * V_37 ;
T_4 V_312 ;
T_4 V_195 ;
T_49 * V_761 ;
if ( V_14 -> V_266 || V_14 -> V_267 )
return 1 ;
V_37 = F_108 ( V_14 , V_246 ) ;
if ( F_166 ( ! V_37 ) ) {
F_25 ( V_42 L_103 ,
V_14 -> V_43 , __FILE__ , __LINE__ , V_44 ) ;
return 1 ;
}
V_312 = F_21 ( V_37 -> V_363 ) ;
if ( V_312 != V_762 )
F_295 ( V_14 , V_312 , 0 ) ;
switch ( V_312 ) {
case V_754 :
{
T_42 * V_763 =
( T_42 * )
V_37 -> V_550 ;
if ( V_763 -> V_764 !=
V_765 )
return 1 ;
if ( V_14 -> V_682 ) {
V_14 -> V_681 ++ ;
return 1 ;
} else
V_14 -> V_682 = 1 ;
break;
}
case V_380 :
F_178 ( V_14 ,
( T_19 * )
V_37 -> V_550 ) ;
break;
case V_756 :
F_183 ( V_14 ,
( T_23 * )
V_37 -> V_550 ) ;
break;
case V_757 :
F_185 ( V_14 ,
( T_25 * )
V_37 -> V_550 ) ;
break;
case V_762 :
{
T_50 * V_766 ;
T_10 * V_767 ;
if ( ! V_14 -> V_136 )
break;
V_766 = ( T_50 * )
V_37 -> V_550 ;
V_767 = ( T_10 * ) V_766 -> V_768 ;
if ( F_21 ( V_766 -> V_769 )
!= V_770 )
break;
switch ( F_79 ( * V_767 ) ) {
case V_771 :
F_92 ( V_42 L_333
L_334
L_335
L_336 , V_14 -> V_43 ) ;
break;
case V_772 :
F_92 ( V_42 L_333
L_337
L_338
L_339 , V_14 -> V_43 ) ;
break;
case V_773 :
F_25 ( V_42 L_340
L_341
L_342
L_343
L_339 , V_14 -> V_43 ) ;
break;
case V_774 :
F_25 ( V_42 L_340
L_344
L_345
L_346 ,
V_14 -> V_43 ) ;
break;
}
break;
}
case V_552 :
case V_759 :
case V_753 :
case V_755 :
case V_758 :
break;
case V_775 :
F_186 ( V_14 ,
( T_26 * )
V_37 -> V_550 ) ;
break;
case V_776 :
V_761 =
( T_49 * ) V_37 -> V_550 ;
if ( V_761 -> V_389 ==
V_777 ) {
F_13 ( V_42 L_347 ,
V_14 -> V_43 , V_761 -> V_778 ) ;
F_13 ( L_348 ) ;
F_13 ( L_349 ) ;
F_13 ( L_350 ,
V_761 -> V_779 ) ;
}
break;
default:
return 1 ;
}
V_195 = F_21 ( V_37 -> V_553 ) * 4 ;
V_7 = F_8 ( V_195 ) ;
if ( ! V_7 ) {
F_25 ( V_42 L_2 ,
V_14 -> V_43 , __FILE__ , __LINE__ , V_44 ) ;
return 1 ;
}
memcpy ( V_7 -> V_311 , V_37 -> V_550 , V_195 ) ;
V_7 -> V_14 = V_14 ;
V_7 -> V_365 = V_37 -> V_365 ;
V_7 -> V_366 = V_37 -> V_366 ;
V_7 -> V_312 = V_312 ;
F_140 ( V_14 , V_7 ) ;
F_6 ( V_7 ) ;
return 1 ;
}
static void
F_242 ( struct V_13 * V_14 ,
struct V_94 * V_95 )
{
struct V_320 * V_321 , * V_370 ;
F_285 (mpt3sas_port, next,
&sas_expander->sas_port_list, port_list) {
if ( V_14 -> V_82 )
return;
if ( V_321 -> V_323 . V_324 ==
V_325 )
F_44 ( V_14 ,
V_321 -> V_323 . V_17 ) ;
else if ( V_321 -> V_323 . V_324 ==
V_327 ||
V_321 -> V_323 . V_324 ==
V_328 )
F_241 ( V_14 ,
V_321 -> V_323 . V_17 ) ;
}
F_50 ( V_14 , V_95 -> V_17 ,
V_95 -> V_86 ) ;
F_13 ( V_42
L_351 ,
V_14 -> V_43 ,
V_95 -> V_35 , ( unsigned long long )
V_95 -> V_17 ) ;
F_2 ( V_95 -> V_227 ) ;
F_2 ( V_95 ) ;
}
static void
F_296 ( struct V_13 * V_14 )
{
T_44 * V_260 ;
T_45 * V_37 ;
T_4 V_104 ;
if ( ! V_14 -> V_730 )
return;
if ( F_39 ( & V_14 -> V_93 ) )
return;
F_130 ( & V_14 -> V_612 . V_264 ) ;
if ( V_14 -> V_612 . V_248 != V_249 ) {
F_25 ( V_42 L_251 ,
V_14 -> V_43 , V_44 ) ;
goto V_91;
}
V_14 -> V_612 . V_248 = V_253 ;
V_104 = F_167 ( V_14 , V_14 -> V_689 ) ;
if ( ! V_104 ) {
F_25 ( V_42 L_52 ,
V_14 -> V_43 , V_44 ) ;
V_14 -> V_612 . V_248 = V_249 ;
goto V_91;
}
V_260 = F_121 ( V_14 , V_104 ) ;
V_14 -> V_612 . V_104 = V_104 ;
memset ( V_260 , 0 , sizeof( T_44 ) ) ;
V_260 -> V_276 = V_690 ;
V_260 -> V_534 = V_780 ;
if ( ! V_14 -> V_220 )
F_13 ( V_42 L_352 , V_14 -> V_43 ) ;
F_124 ( & V_14 -> V_612 . V_254 ) ;
V_14 -> V_353 ( V_14 , V_104 ) ;
F_125 ( & V_14 -> V_612 . V_254 , 10 * V_285 ) ;
if ( ! ( V_14 -> V_612 . V_248 & V_250 ) ) {
F_25 ( V_42 L_54 ,
V_14 -> V_43 , V_44 ) ;
goto V_91;
}
if ( V_14 -> V_612 . V_248 & V_252 ) {
V_37 = V_14 -> V_612 . V_246 ;
if ( ! V_14 -> V_220 )
F_13 ( V_42 L_353
L_354 ,
V_14 -> V_43 , F_21 ( V_37 -> V_46 ) ,
F_79 ( V_37 -> V_288 ) ) ;
}
V_91:
V_14 -> V_612 . V_248 = V_249 ;
F_131 ( & V_14 -> V_612 . V_264 ) ;
}
static void F_297 ( struct V_781 * V_547 )
{
struct V_114 * V_115 = F_298 ( V_547 ) ;
struct V_13 * V_14 = F_68 ( V_115 ) ;
struct V_320 * V_321 , * V_782 ;
struct V_55 * V_56 , * V_370 ;
struct V_72 * V_120 ;
struct V_783 * V_784 ;
unsigned long V_76 ;
V_14 -> V_266 = 1 ;
F_150 ( V_14 ) ;
F_32 ( & V_14 -> V_306 , V_76 ) ;
V_784 = V_14 -> V_305 ;
V_14 -> V_305 = NULL ;
F_33 ( & V_14 -> V_306 , V_76 ) ;
if ( V_784 )
F_299 ( V_784 ) ;
F_296 ( V_14 ) ;
F_285 (raid_device, next, &ioc->raid_device_list,
list) {
if ( V_56 -> V_87 ) {
V_120 =
V_56 -> V_87 -> V_122 ;
V_120 -> V_339 = 1 ;
F_263 ( & V_56 -> V_87 -> V_129 ) ;
}
F_13 ( V_42 L_260 ,
V_14 -> V_43 , V_56 -> V_35 ,
( unsigned long long ) V_56 -> V_60 ) ;
F_56 ( V_14 , V_56 ) ;
}
F_285 (mpt3sas_port, next_port,
&ioc->sas_hba.sas_port_list, port_list) {
if ( V_321 -> V_323 . V_324 ==
V_325 )
F_44 ( V_14 ,
V_321 -> V_323 . V_17 ) ;
else if ( V_321 -> V_323 . V_324 ==
V_327 ||
V_321 -> V_323 . V_324 ==
V_328 )
F_241 ( V_14 ,
V_321 -> V_323 . V_17 ) ;
}
if ( V_14 -> V_39 . V_40 ) {
F_2 ( V_14 -> V_39 . V_227 ) ;
V_14 -> V_39 . V_227 = NULL ;
V_14 -> V_39 . V_40 = 0 ;
}
F_300 ( V_115 ) ;
F_301 ( V_115 ) ;
F_302 ( V_14 ) ;
F_14 ( & V_16 ) ;
F_57 ( & V_14 -> V_81 ) ;
F_16 ( & V_16 ) ;
F_303 ( V_115 ) ;
}
static void
F_304 ( struct V_781 * V_547 )
{
struct V_114 * V_115 = F_298 ( V_547 ) ;
struct V_13 * V_14 = F_68 ( V_115 ) ;
struct V_783 * V_784 ;
unsigned long V_76 ;
V_14 -> V_266 = 1 ;
F_150 ( V_14 ) ;
F_32 ( & V_14 -> V_306 , V_76 ) ;
V_784 = V_14 -> V_305 ;
V_14 -> V_305 = NULL ;
F_33 ( & V_14 -> V_306 , V_76 ) ;
if ( V_784 )
F_299 ( V_784 ) ;
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
T_1 V_86 ;
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
V_28 = F_261 ( V_14 -> V_115 , V_135 ,
V_56 -> V_89 , 0 ) ;
if ( V_28 )
F_56 ( V_14 , V_56 ) ;
} else {
F_32 ( & V_14 -> V_74 , V_76 ) ;
V_54 = V_51 ;
V_35 = V_54 -> V_35 ;
V_86 = V_54 -> V_86 ;
V_17 = V_54 -> V_17 ;
F_286 ( & V_54 -> V_81 , & V_14 -> V_83 ) ;
F_33 ( & V_14 -> V_74 , V_76 ) ;
if ( V_14 -> V_84 )
return;
if ( ! F_49 ( V_14 , V_35 ,
V_86 ) ) {
F_38 ( V_14 , V_54 ) ;
} else if ( ! V_54 -> V_87 ) {
if ( ! V_14 -> V_57 ) {
F_50 ( V_14 ,
V_17 ,
V_86 ) ;
F_38 ( V_14 , V_54 ) ;
}
}
}
}
static void
F_306 ( struct V_13 * V_14 )
{
struct V_55 * V_56 , * V_785 ;
int V_28 ;
F_285 (raid_device, raid_next,
&ioc->raid_device_list, list) {
if ( V_56 -> V_87 )
continue;
V_28 = F_261 ( V_14 -> V_115 , V_135 ,
V_56 -> V_89 , 0 ) ;
if ( V_28 )
F_56 ( V_14 , V_56 ) ;
}
}
static struct V_53 * F_307 ( struct V_13 * V_14 )
{
struct V_53 * V_54 = NULL ;
unsigned long V_76 ;
F_32 ( & V_14 -> V_74 , V_76 ) ;
if ( ! F_39 ( & V_14 -> V_88 ) ) {
V_54 = F_149 ( & V_14 -> V_88 ,
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
if ( V_14 -> V_84 )
return;
while ( ( V_54 = F_307 ( V_14 ) ) ) {
if ( ! F_49 ( V_14 , V_54 -> V_35 ,
V_54 -> V_86 ) ) {
F_38 ( V_14 , V_54 ) ;
F_41 ( V_54 ) ;
continue;
} else if ( ! V_54 -> V_87 ) {
if ( ! V_14 -> V_57 ) {
F_50 ( V_14 ,
V_54 -> V_17 ,
V_54 -> V_86 ) ;
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
T_4 V_786 ;
if ( ! ( V_14 -> V_204 . V_787 & V_788 ) )
return;
F_305 ( V_14 ) ;
if ( V_14 -> V_730 ) {
V_786 =
F_21 ( V_14 -> V_789 . V_790 ) &
V_791 ;
if ( V_786 ==
V_792 ) {
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
F_311 ( struct V_114 * V_115 )
{
struct V_13 * V_14 = F_68 ( V_115 ) ;
int V_28 ;
if ( V_793 != - 1 && V_793 != 0 )
F_312 ( V_14 , V_793 ) ;
if ( V_685 > 0 )
return;
V_14 -> V_751 = 1 ;
V_28 = F_313 ( V_14 ) ;
if ( V_28 != 0 )
F_13 ( V_42 L_355 , V_14 -> V_43 ) ;
}
static int
F_314 ( struct V_114 * V_115 , unsigned long time )
{
struct V_13 * V_14 = F_68 ( V_115 ) ;
if ( V_685 > 0 ) {
V_14 -> V_57 = 0 ;
V_14 -> V_644 = 0 ;
return 1 ;
}
if ( time >= ( 300 * V_285 ) ) {
V_14 -> V_794 . V_248 = V_249 ;
F_13 ( V_42
L_356 ,
V_14 -> V_43 ) ;
V_14 -> V_57 = 0 ;
return 1 ;
}
if ( V_14 -> V_751 )
return 0 ;
if ( V_14 -> V_795 ) {
F_13 ( V_42
L_357 ,
V_14 -> V_43 , V_14 -> V_795 ) ;
V_14 -> V_57 = 0 ;
V_14 -> V_644 = 0 ;
V_14 -> V_266 = 1 ;
return 1 ;
}
F_13 ( V_42 L_358 , V_14 -> V_43 ) ;
V_14 -> V_794 . V_248 = V_249 ;
if ( V_14 -> V_644 ) {
V_14 -> V_644 = 0 ;
F_310 ( V_14 ) ;
}
F_315 ( V_14 ) ;
V_14 -> V_57 = 0 ;
return 1 ;
}
static T_4
F_316 ( struct V_781 * V_547 )
{
switch ( V_547 -> V_51 ) {
case V_796 :
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
case V_807 :
case V_808 :
case V_809 :
case V_810 :
case V_811 :
case V_812 :
return V_162 ;
case V_813 :
case V_814 :
case V_815 :
case V_816 :
case V_817 :
case V_818 :
return V_164 ;
case V_819 :
case V_820 :
case V_821 :
case V_822 :
case V_823 :
case V_824 :
case V_825 :
case V_826 :
case V_827 :
case V_828 :
case V_829 :
case V_830 :
case V_831 :
case V_832 :
case V_833 :
case V_834 :
return V_165 ;
}
return 0 ;
}
static int
F_317 ( struct V_781 * V_547 , const struct V_835 * V_89 )
{
struct V_13 * V_14 ;
struct V_114 * V_115 = NULL ;
int V_836 ;
T_4 V_837 ;
V_837 = F_316 ( V_547 ) ;
if ( V_837 == 0 )
return - V_838 ;
if ( ( V_839 == 1 ) && ( V_837 != V_162 ) )
return - V_838 ;
if ( ( V_839 == 2 ) && ( ! ( V_837 == V_164
|| V_837 == V_165 ) ) )
return - V_838 ;
switch ( V_837 ) {
case V_162 :
F_318 ( V_547 , V_840 |
V_841 | V_842 ) ;
V_115 = F_319 ( & V_843 ,
sizeof( struct V_13 ) ) ;
if ( ! V_115 )
return - V_838 ;
V_14 = F_68 ( V_115 ) ;
memset ( V_14 , 0 , sizeof( struct V_13 ) ) ;
V_14 -> V_161 = V_837 ;
V_14 -> V_89 = V_844 ++ ;
sprintf ( V_14 -> V_845 , L_359 , V_846 ) ;
if ( V_547 -> V_51 == V_796 ) {
V_14 -> V_136 = 1 ;
V_14 -> V_220 = 1 ;
} else
V_14 -> V_847 = V_848 ;
break;
case V_164 :
case V_165 :
V_115 = F_319 ( & V_849 ,
sizeof( struct V_13 ) ) ;
if ( ! V_115 )
return - V_838 ;
V_14 = F_68 ( V_115 ) ;
memset ( V_14 , 0 , sizeof( struct V_13 ) ) ;
V_14 -> V_161 = V_837 ;
V_14 -> V_89 = V_850 ++ ;
sprintf ( V_14 -> V_845 , L_359 , V_851 ) ;
switch ( V_547 -> V_51 ) {
case V_829 :
case V_830 :
case V_831 :
case V_832 :
case V_833 :
case V_834 :
V_14 -> V_429 = 1 ;
break;
default:
V_14 -> V_429 = 0 ;
}
if ( ( V_14 -> V_161 == V_164 &&
V_547 -> V_852 >= V_853 ) ||
( V_14 -> V_161 == V_165 ) ) {
V_14 -> V_854 = 1 ;
if ( V_14 -> V_429 )
V_14 -> V_855 =
V_856 ;
else
V_14 -> V_855 =
V_857 ;
}
break;
default:
return - V_838 ;
}
F_141 ( & V_14 -> V_81 ) ;
F_14 ( & V_16 ) ;
F_47 ( & V_14 -> V_81 , & V_858 ) ;
F_16 ( & V_16 ) ;
V_14 -> V_115 = V_115 ;
V_14 -> V_547 = V_547 ;
V_14 -> V_462 = V_462 ;
V_14 -> V_274 = V_274 ;
V_14 -> V_859 = V_859 ;
V_14 -> V_361 = V_361 ;
V_14 -> V_860 = V_860 ;
V_14 -> V_861 = V_861 ;
V_14 -> V_689 = V_689 ;
V_14 -> V_862 = V_862 ;
V_14 -> V_340 = V_340 ;
V_14 -> V_354 = V_354 ;
V_14 -> V_348 = V_348 ;
V_14 -> V_15 = V_15 ;
V_14 -> V_863 = & F_189 ;
F_320 ( & V_14 -> V_864 ) ;
F_320 ( & V_14 -> V_865 ) ;
F_321 ( & V_14 -> V_866 ) ;
F_321 ( & V_14 -> V_107 ) ;
F_321 ( & V_14 -> V_74 ) ;
F_321 ( & V_14 -> V_96 ) ;
F_321 ( & V_14 -> V_306 ) ;
F_321 ( & V_14 -> V_92 ) ;
F_321 ( & V_14 -> V_867 ) ;
F_141 ( & V_14 -> V_83 ) ;
F_141 ( & V_14 -> V_88 ) ;
F_141 ( & V_14 -> V_97 ) ;
F_141 ( & V_14 -> V_307 ) ;
F_141 ( & V_14 -> V_93 ) ;
F_141 ( & V_14 -> V_39 . V_611 ) ;
F_141 ( & V_14 -> V_341 ) ;
F_141 ( & V_14 -> V_349 ) ;
F_141 ( & V_14 -> V_369 ) ;
F_141 ( & V_14 -> V_355 ) ;
F_141 ( & V_14 -> V_868 ) ;
sprintf ( V_14 -> V_43 , L_360 , V_14 -> V_845 , V_14 -> V_89 ) ;
V_115 -> V_869 = 32 ;
V_115 -> V_870 = V_870 ;
V_115 -> V_871 = V_872 ;
V_115 -> V_873 = V_14 -> V_89 ;
if ( V_221 != 0xFFFF ) {
if ( V_221 < 64 ) {
V_115 -> V_221 = 64 ;
F_92 ( V_42 L_361 \
L_362
L_363 , V_14 -> V_43 , V_221 ) ;
} else if ( V_221 > 32767 ) {
V_115 -> V_221 = 32767 ;
F_92 ( V_42 L_361 \
L_362
L_364 , V_14 -> V_43 ,
V_221 ) ;
} else {
V_115 -> V_221 = V_221 & 0xFFFE ;
F_13 ( V_42
L_365 ,
V_14 -> V_43 , V_115 -> V_221 ) ;
}
}
if ( V_874 > 0 )
F_322 ( V_115 , V_874 ) ;
else
F_322 ( V_115 , V_875
| V_876
| V_877 ) ;
F_323 ( V_115 , V_878 ) ;
snprintf ( V_14 -> V_879 , sizeof( V_14 -> V_879 ) ,
L_366 , V_14 -> V_845 , V_14 -> V_89 ) ;
V_14 -> V_305 = F_324 (
V_14 -> V_879 , V_880 ) ;
if ( ! V_14 -> V_305 ) {
F_25 ( V_42 L_2 ,
V_14 -> V_43 , __FILE__ , __LINE__ , V_44 ) ;
V_836 = - V_838 ;
goto V_881;
}
V_14 -> V_57 = 1 ;
if ( ( F_325 ( V_14 ) ) ) {
F_25 ( V_42 L_2 ,
V_14 -> V_43 , __FILE__ , __LINE__ , V_44 ) ;
V_836 = - V_838 ;
goto V_882;
}
if ( V_14 -> V_136 ) {
if ( V_14 -> V_847 == V_848 )
V_14 -> V_84 = 0 ;
else if ( V_14 -> V_847 == V_883 )
V_14 -> V_84 = 1 ;
else {
if ( F_326 ( V_14 ) )
V_14 -> V_84 = 1 ;
else
V_14 -> V_84 = 0 ;
}
} else
V_14 -> V_84 = 0 ;
V_836 = F_327 ( V_115 , & V_547 -> V_129 ) ;
if ( V_836 ) {
F_25 ( V_42 L_2 ,
V_14 -> V_43 , __FILE__ , __LINE__ , V_44 ) ;
goto V_884;
}
F_328 ( V_115 ) ;
return 0 ;
V_884:
F_302 ( V_14 ) ;
V_882:
F_299 ( V_14 -> V_305 ) ;
V_881:
F_14 ( & V_16 ) ;
F_57 ( & V_14 -> V_81 ) ;
F_16 ( & V_16 ) ;
F_303 ( V_115 ) ;
return V_836 ;
}
static int
F_329 ( struct V_781 * V_547 , T_51 V_169 )
{
struct V_114 * V_115 = F_298 ( V_547 ) ;
struct V_13 * V_14 = F_68 ( V_115 ) ;
T_52 V_885 ;
F_330 ( V_14 ) ;
F_331 () ;
F_332 ( V_115 ) ;
V_885 = F_333 ( V_547 , V_169 ) ;
F_13 ( V_42
L_367 ,
V_14 -> V_43 , V_547 , F_334 ( V_547 ) , V_885 ) ;
F_335 ( V_547 ) ;
F_336 ( V_14 ) ;
F_337 ( V_547 , V_885 ) ;
return 0 ;
}
static int
F_338 ( struct V_781 * V_547 )
{
struct V_114 * V_115 = F_298 ( V_547 ) ;
struct V_13 * V_14 = F_68 ( V_115 ) ;
T_52 V_885 = V_547 -> V_886 ;
int V_2 ;
F_13 ( V_42
L_368 ,
V_14 -> V_43 , V_547 , F_334 ( V_547 ) , V_885 ) ;
F_337 ( V_547 , V_887 ) ;
F_339 ( V_547 , V_887 , 0 ) ;
F_340 ( V_547 ) ;
V_14 -> V_547 = V_547 ;
V_2 = F_341 ( V_14 ) ;
if ( V_2 )
return V_2 ;
F_117 ( V_14 , V_888 ) ;
F_342 ( V_115 ) ;
F_315 ( V_14 ) ;
return 0 ;
}
static T_53
F_343 ( struct V_781 * V_547 , T_54 V_169 )
{
struct V_114 * V_115 = F_298 ( V_547 ) ;
struct V_13 * V_14 = F_68 ( V_115 ) ;
F_13 ( V_42 L_369 ,
V_14 -> V_43 , V_169 ) ;
switch ( V_169 ) {
case V_889 :
return V_890 ;
case V_891 :
V_14 -> V_267 = 1 ;
F_332 ( V_14 -> V_115 ) ;
F_330 ( V_14 ) ;
F_336 ( V_14 ) ;
return V_892 ;
case V_893 :
V_14 -> V_267 = 1 ;
F_330 ( V_14 ) ;
F_189 ( V_14 ) ;
return V_894 ;
}
return V_892 ;
}
static T_53
F_344 ( struct V_781 * V_547 )
{
struct V_114 * V_115 = F_298 ( V_547 ) ;
struct V_13 * V_14 = F_68 ( V_115 ) ;
int V_28 ;
F_13 ( V_42 L_370 ,
V_14 -> V_43 ) ;
V_14 -> V_267 = 0 ;
V_14 -> V_547 = V_547 ;
F_340 ( V_547 ) ;
V_28 = F_341 ( V_14 ) ;
if ( V_28 )
return V_894 ;
V_28 = F_117 ( V_14 , V_269 ) ;
F_92 ( V_42 L_371 , V_14 -> V_43 ,
( V_28 == 0 ) ? L_124 : L_372 ) ;
if ( ! V_28 )
return V_895 ;
else
return V_894 ;
}
static void
F_345 ( struct V_781 * V_547 )
{
struct V_114 * V_115 = F_298 ( V_547 ) ;
struct V_13 * V_14 = F_68 ( V_115 ) ;
F_13 ( V_42 L_373 , V_14 -> V_43 ) ;
F_346 ( V_547 ) ;
F_315 ( V_14 ) ;
F_342 ( V_14 -> V_115 ) ;
}
static T_53
F_347 ( struct V_781 * V_547 )
{
struct V_114 * V_115 = F_298 ( V_547 ) ;
struct V_13 * V_14 = F_68 ( V_115 ) ;
F_13 ( V_42 L_374 ,
V_14 -> V_43 ) ;
return V_895 ;
}
bool F_348 ( struct V_112 * V_75 )
{
unsigned char * V_896 ;
bool V_897 = false ;
if ( ! F_349 ( V_75 ) )
return V_897 ;
V_896 = F_350 ( V_898 , V_132 ) ;
if ( ! V_896 )
return V_897 ;
if ( ! F_351 ( V_75 , 0x89 , V_896 , V_898 ) )
V_897 = ( V_896 [ 213 ] >> 4 ) & 1 ;
F_2 ( V_896 ) ;
return V_897 ;
}
static int
F_352 ( void )
{
V_844 = 0 ;
V_850 = 0 ;
F_353 () ;
V_462 = F_354 ( F_217 ) ;
V_274 = F_354 ( F_107 ) ;
V_361 = F_354 ( V_899 ) ;
V_860 = F_354 (
V_900 ) ;
V_861 = F_354 (
V_901 ) ;
V_689 = F_354 ( F_243 ) ;
V_862 = F_354 (
V_902 ) ;
V_859 = F_354 ( V_903 ) ;
V_340 = F_354 (
F_165 ) ;
V_354 = F_354 (
F_173 ) ;
V_348 = F_354 (
F_169 ) ;
return 0 ;
}
static void
F_355 ( void )
{
F_356 ( V_462 ) ;
F_356 ( V_274 ) ;
F_356 ( V_361 ) ;
F_356 ( V_860 ) ;
F_356 ( V_861 ) ;
F_356 ( V_689 ) ;
F_356 ( V_862 ) ;
F_356 ( V_859 ) ;
F_356 ( V_340 ) ;
F_356 ( V_354 ) ;
F_356 ( V_348 ) ;
if ( V_839 != 1 )
F_357 ( V_166 ) ;
if ( V_839 != 2 )
F_357 ( V_163 ) ;
F_358 ( V_872 ) ;
}
static int T_55
F_359 ( void )
{
int error ;
F_13 ( L_375 , V_851 ,
V_904 ) ;
V_872 =
F_360 ( & V_905 ) ;
if ( ! V_872 )
return - V_838 ;
if ( V_839 != 1 ) {
V_166 =
F_361 ( & V_906 ) ;
if ( ! V_166 ) {
F_358 ( V_872 ) ;
return - V_838 ;
}
}
if ( V_839 != 2 ) {
V_163 =
F_361 ( & V_907 ) ;
if ( ! V_163 ) {
F_358 ( V_872 ) ;
return - V_838 ;
}
}
error = F_352 () ;
if ( error ) {
F_355 () ;
return error ;
}
F_362 ( V_839 ) ;
error = F_363 ( & V_908 ) ;
if ( error )
F_355 () ;
return error ;
}
static void T_56
F_364 ( void )
{
F_13 ( L_376 ,
V_904 ) ;
F_365 ( & V_908 ) ;
F_366 ( V_839 ) ;
F_355 () ;
}
