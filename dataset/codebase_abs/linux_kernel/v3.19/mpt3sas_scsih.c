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
F_19 ( & V_6 -> V_64 , V_63 ) ;
F_20 ( & V_45 -> V_65 ) ;
F_21 ( V_45 ) ;
F_22 ( & V_6 -> V_64 , V_63 ) ;
}
static void
F_23 ( struct V_5 * V_6 , T_4 V_26 )
{
struct V_44 * V_45 ;
unsigned long V_63 ;
if ( V_6 -> V_66 )
return;
F_19 ( & V_6 -> V_64 , V_63 ) ;
V_45 = F_17 ( V_6 , V_26 ) ;
if ( V_45 )
F_20 ( & V_45 -> V_65 ) ;
F_22 ( & V_6 -> V_64 , V_63 ) ;
if ( V_45 )
F_24 ( V_6 , V_45 ) ;
}
void
F_25 ( struct V_5 * V_6 ,
T_1 V_8 )
{
struct V_44 * V_45 ;
unsigned long V_63 ;
if ( V_6 -> V_66 )
return;
F_19 ( & V_6 -> V_64 , V_63 ) ;
V_45 = F_16 ( V_6 ,
V_8 ) ;
if ( V_45 )
F_20 ( & V_45 -> V_65 ) ;
F_22 ( & V_6 -> V_64 , V_63 ) ;
if ( V_45 )
F_24 ( V_6 , V_45 ) ;
}
static void
F_26 ( struct V_5 * V_6 ,
struct V_44 * V_45 )
{
unsigned long V_63 ;
F_27 ( V_6 , F_3 ( V_33
L_7 ,
V_6 -> V_34 , V_35 , V_45 -> V_26 ,
( unsigned long long ) V_45 -> V_8 ) ) ;
F_19 ( & V_6 -> V_64 , V_63 ) ;
F_28 ( & V_45 -> V_65 , & V_6 -> V_67 ) ;
F_22 ( & V_6 -> V_64 , V_63 ) ;
if ( ! F_29 ( V_6 , V_45 -> V_26 ,
V_45 -> V_68 ) ) {
F_18 ( V_6 , V_45 ) ;
} else if ( ! V_45 -> V_69 ) {
if ( ! V_6 -> V_48 ) {
F_30 ( V_6 ,
V_45 -> V_8 ,
V_45 -> V_68 ) ;
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
L_7 , V_6 -> V_34 ,
V_35 , V_45 -> V_26 ,
( unsigned long long ) V_45 -> V_8 ) ) ;
F_19 ( & V_6 -> V_64 , V_63 ) ;
F_28 ( & V_45 -> V_65 , & V_6 -> V_70 ) ;
F_14 ( V_6 , V_45 , 0 ) ;
F_22 ( & V_6 -> V_64 , V_63 ) ;
}
static struct V_46 *
F_32 ( struct V_5 * V_6 , int V_71 , int V_72 )
{
struct V_46 * V_47 , * V_73 ;
V_73 = NULL ;
F_4 (raid_device, &ioc->raid_device_list, list) {
if ( V_47 -> V_71 == V_71 && V_47 -> V_72 == V_72 ) {
V_73 = V_47 ;
goto V_74;
}
}
V_74:
return V_73 ;
}
static struct V_46 *
F_33 ( struct V_5 * V_6 , T_4 V_26 )
{
struct V_46 * V_47 , * V_73 ;
V_73 = NULL ;
F_4 (raid_device, &ioc->raid_device_list, list) {
if ( V_47 -> V_26 != V_26 )
continue;
V_73 = V_47 ;
goto V_74;
}
V_74:
return V_73 ;
}
static struct V_46 *
F_34 ( struct V_5 * V_6 , T_1 V_51 )
{
struct V_46 * V_47 , * V_73 ;
V_73 = NULL ;
F_4 (raid_device, &ioc->raid_device_list, list) {
if ( V_47 -> V_51 != V_51 )
continue;
V_73 = V_47 ;
goto V_74;
}
V_74:
return V_73 ;
}
static void
F_35 ( struct V_5 * V_6 ,
struct V_46 * V_47 )
{
unsigned long V_63 ;
F_27 ( V_6 , F_3 ( V_33
L_8 , V_6 -> V_34 , V_35 ,
V_47 -> V_26 , ( unsigned long long ) V_47 -> V_51 ) ) ;
F_19 ( & V_6 -> V_75 , V_63 ) ;
F_28 ( & V_47 -> V_65 , & V_6 -> V_76 ) ;
F_22 ( & V_6 -> V_75 , V_63 ) ;
}
static void
F_36 ( struct V_5 * V_6 ,
struct V_46 * V_47 )
{
unsigned long V_63 ;
F_19 ( & V_6 -> V_75 , V_63 ) ;
F_20 ( & V_47 -> V_65 ) ;
F_21 ( V_47 ) ;
F_22 ( & V_6 -> V_75 , V_63 ) ;
}
struct V_77 *
F_37 ( struct V_5 * V_6 , T_4 V_26 )
{
struct V_77 * V_78 , * V_73 ;
V_73 = NULL ;
F_4 (sas_expander, &ioc->sas_expander_list, list) {
if ( V_78 -> V_26 != V_26 )
continue;
V_73 = V_78 ;
goto V_74;
}
V_74:
return V_73 ;
}
struct V_77 *
F_38 ( struct V_5 * V_6 ,
T_1 V_8 )
{
struct V_77 * V_78 , * V_73 ;
V_73 = NULL ;
F_4 (sas_expander, &ioc->sas_expander_list, list) {
if ( V_78 -> V_8 != V_8 )
continue;
V_73 = V_78 ;
goto V_74;
}
V_74:
return V_73 ;
}
static void
F_39 ( struct V_5 * V_6 ,
struct V_77 * V_78 )
{
unsigned long V_63 ;
F_19 ( & V_6 -> V_79 , V_63 ) ;
F_28 ( & V_78 -> V_65 , & V_6 -> V_80 ) ;
F_22 ( & V_6 -> V_79 , V_63 ) ;
}
static int
F_40 ( T_10 V_81 )
{
if ( V_81 & V_82 &&
( ( V_81 & V_83 ) |
( V_81 & V_84 ) |
( V_81 & V_85 ) ) )
return 1 ;
else
return 0 ;
}
static struct V_86 *
F_41 ( struct V_5 * V_6 , T_4 V_87 )
{
return V_6 -> V_88 [ V_87 - 1 ] . V_89 ;
}
static inline struct V_86 *
F_42 ( struct V_5 * V_6 , T_4 V_87 )
{
unsigned long V_63 ;
struct V_86 * V_89 ;
F_19 ( & V_6 -> V_90 , V_63 ) ;
V_89 = V_6 -> V_88 [ V_87 - 1 ] . V_89 ;
V_6 -> V_88 [ V_87 - 1 ] . V_89 = NULL ;
F_22 ( & V_6 -> V_90 , V_63 ) ;
return V_89 ;
}
static T_4
F_43 ( struct V_5 * V_6 , struct V_86
* V_89 )
{
T_4 V_87 ;
unsigned long V_63 ;
int V_91 ;
F_19 ( & V_6 -> V_90 , V_63 ) ;
V_87 = 0 ;
for ( V_91 = 0 ; V_91 < V_6 -> V_92 ; V_91 ++ ) {
if ( V_6 -> V_88 [ V_91 ] . V_89 == V_89 ) {
V_87 = V_6 -> V_88 [ V_91 ] . V_87 ;
goto V_74;
}
}
V_74:
F_22 ( & V_6 -> V_90 , V_63 ) ;
return V_87 ;
}
static T_6
F_44 ( struct V_5 * V_6 , int V_71 ,
int V_72 )
{
T_6 V_93 ;
unsigned long V_63 ;
int V_91 ;
F_19 ( & V_6 -> V_90 , V_63 ) ;
V_93 = 0 ;
for ( V_91 = 0 ; V_91 < V_6 -> V_92 ; V_91 ++ ) {
if ( V_6 -> V_88 [ V_91 ] . V_89 &&
( V_6 -> V_88 [ V_91 ] . V_89 -> V_42 -> V_71 == V_71 &&
V_6 -> V_88 [ V_91 ] . V_89 -> V_42 -> V_72 == V_72 ) ) {
V_93 = 1 ;
goto V_74;
}
}
V_74:
F_22 ( & V_6 -> V_90 , V_63 ) ;
return V_93 ;
}
static T_6
F_45 ( struct V_5 * V_6 , int V_71 ,
unsigned int V_94 , int V_72 )
{
T_6 V_93 ;
unsigned long V_63 ;
int V_91 ;
F_19 ( & V_6 -> V_90 , V_63 ) ;
V_93 = 0 ;
for ( V_91 = 0 ; V_91 < V_6 -> V_92 ; V_91 ++ ) {
if ( V_6 -> V_88 [ V_91 ] . V_89 &&
( V_6 -> V_88 [ V_91 ] . V_89 -> V_42 -> V_71 == V_71 &&
V_6 -> V_88 [ V_91 ] . V_89 -> V_42 -> V_72 == V_72 &&
V_6 -> V_88 [ V_91 ] . V_89 -> V_42 -> V_94 == V_94 ) ) {
V_93 = 1 ;
goto V_74;
}
}
V_74:
F_22 ( & V_6 -> V_90 , V_63 ) ;
return V_93 ;
}
static int
F_46 ( struct V_95 * V_96 , int V_97 )
{
struct V_98 * V_99 = V_96 -> V_100 ;
int V_101 ;
struct V_5 * V_6 = F_47 ( V_99 ) ;
struct V_102 * V_103 ;
struct V_104 * V_105 ;
struct V_44 * V_45 ;
unsigned long V_63 ;
V_101 = V_99 -> V_106 ;
V_103 = V_96 -> V_107 ;
if ( ! V_103 )
goto V_108;
V_105 = V_103 -> V_109 ;
if ( ! V_105 )
goto V_108;
if ( ( V_105 -> V_63 & V_110 ) )
goto V_108;
F_19 ( & V_6 -> V_64 , V_63 ) ;
V_45 = F_16 ( V_6 ,
V_103 -> V_109 -> V_8 ) ;
if ( V_45 && V_45 -> V_81 &
V_85 )
V_101 = V_111 ;
F_22 ( & V_6 -> V_64 , V_63 ) ;
V_108:
if ( ! V_96 -> V_112 )
V_101 = 1 ;
if ( V_97 > V_101 )
V_97 = V_101 ;
return F_48 ( V_96 , V_97 ) ;
}
static int
F_49 ( struct V_113 * V_69 )
{
struct V_98 * V_99 = F_50 ( & V_69 -> V_114 ) ;
struct V_5 * V_6 = F_47 ( V_99 ) ;
struct V_104 * V_105 ;
struct V_44 * V_45 ;
struct V_46 * V_47 ;
unsigned long V_63 ;
struct V_115 * V_116 ;
V_105 = F_51 ( sizeof( * V_105 ) ,
V_117 ) ;
if ( ! V_105 )
return - V_118 ;
V_69 -> V_107 = V_105 ;
V_105 -> V_69 = V_69 ;
V_105 -> V_26 = V_119 ;
if ( V_69 -> V_72 == V_120 ) {
F_19 ( & V_6 -> V_75 , V_63 ) ;
V_47 = F_32 ( V_6 , V_69 -> V_71 ,
V_69 -> V_72 ) ;
if ( V_47 ) {
V_105 -> V_26 = V_47 -> V_26 ;
V_105 -> V_8 = V_47 -> V_51 ;
V_105 -> V_63 |= V_110 ;
V_47 -> V_69 = V_69 ;
}
F_22 ( & V_6 -> V_75 , V_63 ) ;
return 0 ;
}
F_19 ( & V_6 -> V_64 , V_63 ) ;
V_116 = F_52 ( V_69 -> V_114 . V_121 ) ;
V_45 = F_16 ( V_6 ,
V_116 -> V_122 . V_8 ) ;
if ( V_45 ) {
V_105 -> V_26 = V_45 -> V_26 ;
V_105 -> V_8 = V_45 -> V_8 ;
V_45 -> V_69 = V_69 ;
V_45 -> V_71 = V_69 -> V_71 ;
V_45 -> V_72 = V_69 -> V_72 ;
if ( F_53 ( V_45 -> V_26 , V_6 -> V_123 ) )
V_105 -> V_63 |=
V_124 ;
if ( V_45 -> V_125 )
V_105 -> V_63 |= V_126 ;
}
F_22 ( & V_6 -> V_64 , V_63 ) ;
return 0 ;
}
static void
F_54 ( struct V_113 * V_69 )
{
struct V_98 * V_99 = F_50 ( & V_69 -> V_114 ) ;
struct V_5 * V_6 = F_47 ( V_99 ) ;
struct V_104 * V_105 ;
struct V_44 * V_45 ;
struct V_46 * V_47 ;
unsigned long V_63 ;
struct V_115 * V_116 ;
V_105 = V_69 -> V_107 ;
if ( ! V_105 )
return;
if ( V_69 -> V_72 == V_120 ) {
F_19 ( & V_6 -> V_75 , V_63 ) ;
V_47 = F_32 ( V_6 , V_69 -> V_71 ,
V_69 -> V_72 ) ;
if ( V_47 ) {
V_47 -> V_69 = NULL ;
V_47 -> V_96 = NULL ;
}
F_22 ( & V_6 -> V_75 , V_63 ) ;
goto V_74;
}
F_19 ( & V_6 -> V_64 , V_63 ) ;
V_116 = F_52 ( V_69 -> V_114 . V_121 ) ;
V_45 = F_16 ( V_6 ,
V_116 -> V_122 . V_8 ) ;
if ( V_45 && ( V_45 -> V_69 == V_69 ) &&
( V_45 -> V_71 == V_69 -> V_71 ) &&
( V_45 -> V_72 == V_69 -> V_72 ) )
V_45 -> V_69 = NULL ;
F_22 ( & V_6 -> V_64 , V_63 ) ;
V_74:
F_21 ( V_105 ) ;
V_69 -> V_107 = NULL ;
}
static int
F_55 ( struct V_95 * V_96 )
{
struct V_98 * V_99 ;
struct V_5 * V_6 ;
struct V_104 * V_105 ;
struct V_102 * V_103 ;
struct V_113 * V_69 ;
struct V_46 * V_47 ;
struct V_44 * V_45 ;
unsigned long V_63 ;
V_103 = F_51 ( sizeof( * V_103 ) ,
V_117 ) ;
if ( ! V_103 )
return - V_118 ;
V_103 -> V_94 = V_96 -> V_94 ;
V_103 -> V_63 = V_127 ;
V_69 = V_113 ( V_96 ) ;
V_105 = V_69 -> V_107 ;
V_105 -> V_128 ++ ;
V_103 -> V_109 = V_105 ;
V_96 -> V_107 = V_103 ;
if ( ( V_105 -> V_63 & V_124 ) )
V_96 -> V_129 = 1 ;
V_99 = F_50 ( & V_69 -> V_114 ) ;
V_6 = F_47 ( V_99 ) ;
if ( V_69 -> V_72 == V_120 ) {
F_19 ( & V_6 -> V_75 , V_63 ) ;
V_47 = F_32 ( V_6 ,
V_69 -> V_71 , V_69 -> V_72 ) ;
if ( V_47 )
V_47 -> V_96 = V_96 ;
F_22 ( & V_6 -> V_75 , V_63 ) ;
}
if ( ! ( V_105 -> V_63 & V_110 ) ) {
F_19 ( & V_6 -> V_64 , V_63 ) ;
V_45 = F_16 ( V_6 ,
V_105 -> V_8 ) ;
if ( V_45 && ( V_45 -> V_69 == NULL ) ) {
F_56 ( V_130 , V_96 ,
L_9 ,
V_35 , __LINE__ ) ;
V_45 -> V_69 = V_69 ;
}
F_22 ( & V_6 -> V_64 , V_63 ) ;
}
return 0 ;
}
static void
F_57 ( struct V_95 * V_96 )
{
struct V_104 * V_105 ;
struct V_113 * V_69 ;
struct V_98 * V_99 ;
struct V_5 * V_6 ;
struct V_44 * V_45 ;
unsigned long V_63 ;
if ( ! V_96 -> V_107 )
return;
V_69 = V_113 ( V_96 ) ;
V_105 = V_69 -> V_107 ;
V_105 -> V_128 -- ;
V_99 = F_50 ( & V_69 -> V_114 ) ;
V_6 = F_47 ( V_99 ) ;
if ( ! ( V_105 -> V_63 & V_110 ) ) {
F_19 ( & V_6 -> V_64 , V_63 ) ;
V_45 = F_16 ( V_6 ,
V_105 -> V_8 ) ;
if ( V_45 && ! V_105 -> V_128 )
V_45 -> V_69 = NULL ;
F_22 ( & V_6 -> V_64 , V_63 ) ;
}
F_21 ( V_96 -> V_107 ) ;
V_96 -> V_107 = NULL ;
}
static void
F_58 ( struct V_5 * V_6 ,
T_4 V_26 , struct V_95 * V_96 )
{
T_9 V_28 ;
T_8 V_27 ;
T_10 V_29 ;
T_4 V_63 ;
T_10 V_81 ;
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
V_63 = F_9 ( V_27 . V_131 ) ;
V_81 = F_59 ( V_27 . V_132 ) ;
F_56 ( V_130 , V_96 ,
L_10
L_11 ,
( V_81 & V_133 ) ? L_12 : L_13 ,
( V_63 & V_134 ) ? L_12 : L_13 ,
( V_63 & V_135 ) ? L_12 :
L_13 ,
( V_63 & V_136 ) ? L_12 : L_13 ,
( V_63 & V_137 ) ? L_12 : L_13 ,
( V_63 & V_138 ) ? L_12 : L_13 ) ;
}
static int
F_60 ( struct V_42 * V_114 )
{
struct V_95 * V_96 = F_61 ( V_114 ) ;
return ( V_96 -> V_72 == V_120 ) ? 1 : 0 ;
}
static void
F_62 ( struct V_42 * V_114 )
{
struct V_95 * V_96 = F_61 ( V_114 ) ;
struct V_5 * V_6 = F_47 ( V_96 -> V_100 ) ;
static struct V_46 * V_47 ;
unsigned long V_63 ;
T_11 V_139 ;
T_9 V_28 ;
T_10 V_140 ;
T_6 V_141 ;
T_4 V_26 ;
V_141 = 0 ;
V_26 = 0 ;
F_19 ( & V_6 -> V_75 , V_63 ) ;
V_47 = F_32 ( V_6 , V_96 -> V_71 ,
V_96 -> V_72 ) ;
if ( V_47 ) {
V_26 = V_47 -> V_26 ;
V_141 = V_47 -> V_141 ;
}
F_22 ( & V_6 -> V_75 , V_63 ) ;
if ( ! V_26 )
goto V_74;
if ( F_63 ( V_6 , & V_28 , & V_139 ,
V_142 , V_26 ,
sizeof( T_11 ) ) ) {
F_13 ( V_33 L_2 ,
V_6 -> V_34 , __FILE__ , __LINE__ , V_35 ) ;
V_141 = 0 ;
goto V_74;
}
V_140 = F_59 ( V_139 . V_143 ) ;
if ( ! ( V_140 &
V_144 ) )
V_141 = 0 ;
V_74:
F_64 ( V_145 , V_114 , V_141 ) ;
}
static void
F_65 ( struct V_42 * V_114 )
{
struct V_95 * V_96 = F_61 ( V_114 ) ;
struct V_5 * V_6 = F_47 ( V_96 -> V_100 ) ;
static struct V_46 * V_47 ;
unsigned long V_63 ;
T_11 V_139 ;
T_9 V_28 ;
T_10 V_146 ;
enum V_147 V_148 = V_149 ;
T_4 V_26 = 0 ;
F_19 ( & V_6 -> V_75 , V_63 ) ;
V_47 = F_32 ( V_6 , V_96 -> V_71 ,
V_96 -> V_72 ) ;
if ( V_47 )
V_26 = V_47 -> V_26 ;
F_22 ( & V_6 -> V_75 , V_63 ) ;
if ( ! V_47 )
goto V_74;
if ( F_63 ( V_6 , & V_28 , & V_139 ,
V_142 , V_26 ,
sizeof( T_11 ) ) ) {
F_13 ( V_33 L_2 ,
V_6 -> V_34 , __FILE__ , __LINE__ , V_35 ) ;
goto V_74;
}
V_146 = F_59 ( V_139 . V_143 ) ;
if ( V_146 & V_144 ) {
V_148 = V_150 ;
goto V_74;
}
switch ( V_139 . V_151 ) {
case V_152 :
case V_153 :
V_148 = V_154 ;
break;
case V_155 :
V_148 = V_156 ;
break;
case V_157 :
case V_158 :
V_148 = V_159 ;
break;
}
V_74:
F_66 ( V_145 , V_114 , V_148 ) ;
}
static void
F_67 ( struct V_95 * V_96 , T_6 V_160 )
{
enum V_161 V_162 = V_163 ;
switch ( V_160 ) {
case V_164 :
V_162 = V_165 ;
break;
case V_166 :
V_162 = V_167 ;
break;
case V_168 :
V_162 = V_169 ;
break;
case V_170 :
V_162 = V_171 ;
break;
}
F_68 ( V_145 , & V_96 -> V_172 , V_162 ) ;
}
static int
F_69 ( struct V_5 * V_6 ,
struct V_46 * V_47 )
{
T_11 * V_139 ;
T_12 V_173 ;
T_8 V_27 ;
T_9 V_28 ;
T_4 V_174 ;
T_6 V_175 ;
if ( ( F_70 ( V_6 , V_47 -> V_26 ,
& V_175 ) ) || ! V_175 ) {
F_71 ( V_6 , F_72 ( V_33
L_2 , V_6 -> V_34 , __FILE__ , __LINE__ ,
V_35 ) ) ;
return 1 ;
}
V_47 -> V_175 = V_175 ;
V_174 = F_73 ( T_11 , V_176 ) + ( V_175 *
sizeof( V_177 ) ) ;
V_139 = F_51 ( V_174 , V_117 ) ;
if ( ! V_139 ) {
F_71 ( V_6 , F_72 ( V_33
L_2 , V_6 -> V_34 , __FILE__ , __LINE__ ,
V_35 ) ) ;
return 1 ;
}
if ( ( F_63 ( V_6 , & V_28 , V_139 ,
V_142 , V_47 -> V_26 , V_174 ) ) ) {
F_71 ( V_6 , F_72 ( V_33
L_2 , V_6 -> V_34 , __FILE__ , __LINE__ ,
V_35 ) ) ;
F_21 ( V_139 ) ;
return 1 ;
}
V_47 -> V_160 = V_139 -> V_178 ;
if ( ! ( F_74 ( V_6 , & V_28 ,
& V_173 , V_179 ,
V_139 -> V_176 [ 0 ] . V_180 ) ) ) {
if ( ! ( F_12 ( V_6 , & V_28 ,
& V_27 , V_32 ,
F_9 ( V_173 . V_181 ) ) ) ) {
V_47 -> V_81 =
F_59 ( V_27 . V_132 ) ;
}
}
F_21 ( V_139 ) ;
return 0 ;
}
static void
F_75 ( struct V_5 * V_6 , struct V_95 * V_96 )
{
if ( V_96 -> type != V_182 )
return;
if ( ! ( V_6 -> V_183 . V_184 & V_185 ) )
return;
F_76 ( V_96 ) ;
F_56 ( V_130 , V_96 , L_14 ,
F_77 ( V_96 ) ? L_15 : L_16 ) ;
return;
}
static int
F_78 ( struct V_95 * V_96 )
{
struct V_98 * V_99 = V_96 -> V_100 ;
struct V_5 * V_6 = F_47 ( V_99 ) ;
struct V_102 * V_103 ;
struct V_104 * V_105 ;
struct V_44 * V_45 ;
struct V_46 * V_47 ;
unsigned long V_63 ;
int V_97 ;
T_6 V_186 = 0 ;
char * V_187 = L_17 ;
char * V_188 = L_17 ;
T_4 V_26 , V_189 = 0 ;
T_1 V_190 = 0 ;
V_97 = 1 ;
V_103 = V_96 -> V_107 ;
V_103 -> V_191 = 1 ;
V_103 -> V_63 &= ~ V_127 ;
V_105 = V_103 -> V_109 ;
V_26 = V_105 -> V_26 ;
if ( V_105 -> V_63 & V_110 ) {
F_19 ( & V_6 -> V_75 , V_63 ) ;
V_47 = F_33 ( V_6 , V_26 ) ;
F_22 ( & V_6 -> V_75 , V_63 ) ;
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
if ( V_47 -> V_81 &
V_83 ) {
V_97 = V_192 ;
V_187 = L_18 ;
} else {
V_97 = V_111 ;
if ( V_47 -> V_81 &
V_85 )
V_187 = L_19 ;
else
V_187 = L_20 ;
}
switch ( V_47 -> V_160 ) {
case V_164 :
V_188 = L_21 ;
break;
case V_168 :
V_97 = V_193 ;
if ( V_6 -> V_194 . V_195 &&
( F_59 ( V_6 -> V_194 . V_196 ) &
V_197 ) &&
! ( V_47 -> V_175 % 2 ) )
V_188 = L_22 ;
else
V_188 = L_23 ;
break;
case V_170 :
V_97 = V_193 ;
V_188 = L_24 ;
break;
case V_166 :
V_97 = V_193 ;
V_188 = L_22 ;
break;
case V_198 :
default:
V_97 = V_193 ;
V_188 = L_25 ;
break;
}
F_56 ( V_130 , V_96 ,
L_26 ,
V_188 , V_47 -> V_26 ,
( unsigned long long ) V_47 -> V_51 ,
V_47 -> V_175 , V_187 ) ;
F_46 ( V_96 , V_97 ) ;
F_67 ( V_96 , V_47 -> V_160 ) ;
return 0 ;
}
if ( V_105 -> V_63 & V_124 ) {
if ( F_79 ( V_6 , V_26 ,
& V_189 ) ) {
F_71 ( V_6 , F_72 ( V_33
L_2 , V_6 -> V_34 ,
__FILE__ , __LINE__ , V_35 ) ) ;
return 1 ;
}
if ( V_189 && F_80 ( V_6 ,
V_189 , & V_190 ) ) {
F_71 ( V_6 , F_72 ( V_33
L_2 , V_6 -> V_34 ,
__FILE__ , __LINE__ , V_35 ) ) ;
return 1 ;
}
}
F_19 ( & V_6 -> V_64 , V_63 ) ;
V_45 = F_16 ( V_6 ,
V_103 -> V_109 -> V_8 ) ;
if ( ! V_45 ) {
F_22 ( & V_6 -> V_64 , V_63 ) ;
F_71 ( V_6 , F_72 ( V_33
L_2 , V_6 -> V_34 , __FILE__ , __LINE__ ,
V_35 ) ) ;
return 1 ;
}
V_45 -> V_189 = V_189 ;
V_45 -> V_190 = V_190 ;
if ( V_45 -> V_81 & V_83 ) {
V_97 = V_192 ;
V_186 = 1 ;
V_187 = L_18 ;
} else {
V_97 = V_111 ;
if ( V_45 -> V_81 & V_84 )
V_187 = L_20 ;
else if ( V_45 -> V_81 &
V_85 )
V_187 = L_19 ;
}
F_56 ( V_130 , V_96 , L_27 \
L_28 ,
V_187 , V_26 , ( unsigned long long ) V_45 -> V_8 ,
V_45 -> V_199 , ( unsigned long long ) V_45 -> V_11 ) ;
F_56 ( V_130 , V_96 ,
L_29 ,
V_187 , ( unsigned long long )
V_45 -> V_13 , V_45 -> V_17 ) ;
F_22 ( & V_6 -> V_64 , V_63 ) ;
if ( ! V_186 )
F_58 ( V_6 , V_26 , V_96 ) ;
F_46 ( V_96 , V_97 ) ;
if ( V_186 ) {
F_81 ( V_96 ) ;
F_75 ( V_6 , V_96 ) ;
}
return 0 ;
}
static int
F_82 ( struct V_95 * V_96 , struct V_200 * V_201 ,
T_13 V_202 , int V_203 [] )
{
int V_204 ;
int V_205 ;
T_13 V_206 ;
T_14 V_207 ;
V_204 = 64 ;
V_205 = 32 ;
V_207 = V_204 * V_205 ;
V_206 = V_202 ;
F_83 ( V_206 , V_207 ) ;
if ( ( T_14 ) V_202 >= 0x200000 ) {
V_204 = 255 ;
V_205 = 63 ;
V_207 = V_204 * V_205 ;
V_206 = V_202 ;
F_83 ( V_206 , V_207 ) ;
}
V_203 [ 0 ] = V_204 ;
V_203 [ 1 ] = V_205 ;
V_203 [ 2 ] = V_206 ;
return 0 ;
}
static void
F_84 ( struct V_5 * V_6 , T_6 V_208 )
{
char * V_209 ;
switch ( V_208 ) {
case V_210 :
V_209 = L_30 ;
break;
case V_211 :
V_209 = L_31 ;
break;
case V_212 :
V_209 = L_32 ;
break;
case V_213 :
V_209 = L_33 ;
break;
case V_214 :
V_209 = L_34 ;
break;
case V_215 :
V_209 = L_35 ;
break;
case 0xA :
V_209 = L_36 ;
break;
case V_216 :
V_209 = L_37 ;
break;
default:
V_209 = L_38 ;
break;
}
F_72 ( V_33 L_39 ,
V_6 -> V_34 , V_208 , V_209 ) ;
}
static T_6
F_85 ( struct V_5 * V_6 , T_4 V_87 , T_6 V_217 , T_10 V_218 )
{
T_15 * V_28 ;
if ( V_6 -> V_219 . V_220 == V_221 )
return 1 ;
if ( V_6 -> V_219 . V_87 != V_87 )
return 1 ;
F_86 ( V_6 ) ;
V_6 -> V_219 . V_220 |= V_222 ;
V_28 = F_87 ( V_6 , V_218 ) ;
if ( V_28 ) {
memcpy ( V_6 -> V_219 . V_218 , V_28 , V_28 -> V_223 * 4 ) ;
V_6 -> V_219 . V_220 |= V_224 ;
}
V_6 -> V_219 . V_220 &= ~ V_225 ;
F_88 ( & V_6 -> V_219 . V_226 ) ;
return 1 ;
}
void
F_89 ( struct V_5 * V_6 , T_4 V_26 )
{
struct V_102 * V_103 ;
struct V_95 * V_96 ;
T_6 V_227 = 0 ;
F_90 (sdev, ioc->shost) {
if ( V_227 )
continue;
V_103 = V_96 -> V_107 ;
if ( ! V_103 )
continue;
if ( V_103 -> V_109 -> V_26 == V_26 ) {
V_103 -> V_109 -> V_228 = 1 ;
V_227 = 1 ;
V_6 -> V_229 = 1 ;
}
}
}
void
F_91 ( struct V_5 * V_6 , T_4 V_26 )
{
struct V_102 * V_103 ;
struct V_95 * V_96 ;
T_6 V_227 = 0 ;
F_90 (sdev, ioc->shost) {
if ( V_227 )
continue;
V_103 = V_96 -> V_107 ;
if ( ! V_103 )
continue;
if ( V_103 -> V_109 -> V_26 == V_26 ) {
V_103 -> V_109 -> V_228 = 0 ;
V_227 = 1 ;
V_6 -> V_229 = 0 ;
}
}
}
int
F_92 ( struct V_5 * V_6 , T_4 V_26 , T_16 V_72 ,
T_16 V_71 , T_16 V_94 , T_6 type , T_4 V_230 , T_14 V_231 ,
enum V_232 V_233 )
{
T_17 * V_234 ;
T_18 * V_28 ;
T_4 V_87 = 0 ;
T_10 V_235 ;
unsigned long V_236 ;
struct V_237 * V_88 = NULL ;
int V_19 ;
if ( V_233 == V_238 )
F_93 ( & V_6 -> V_219 . V_239 ) ;
if ( V_6 -> V_219 . V_220 != V_221 ) {
F_3 ( V_33 L_40 ,
V_35 , V_6 -> V_34 ) ;
V_19 = V_240 ;
goto V_241;
}
if ( V_6 -> V_66 || V_6 -> V_242 ||
V_6 -> V_243 ) {
F_3 ( V_33 L_41 ,
V_35 , V_6 -> V_34 ) ;
V_19 = V_240 ;
goto V_241;
}
V_235 = F_94 ( V_6 , 0 ) ;
if ( V_235 & V_244 ) {
F_95 ( V_6 , F_3 ( V_33
L_42 , V_6 -> V_34 ) ) ;
V_19 = F_96 ( V_6 , V_245 ,
V_246 ) ;
V_19 = ( ! V_19 ) ? V_247 : V_240 ;
goto V_241;
}
if ( ( V_235 & V_248 ) == V_249 ) {
F_97 ( V_6 , V_235 &
V_250 ) ;
V_19 = F_96 ( V_6 , V_245 ,
V_246 ) ;
V_19 = ( ! V_19 ) ? V_247 : V_240 ;
goto V_241;
}
V_87 = F_98 ( V_6 , V_6 -> V_251 ) ;
if ( ! V_87 ) {
F_13 ( V_33 L_43 ,
V_6 -> V_34 , V_35 ) ;
V_19 = V_240 ;
goto V_241;
}
if ( type == V_252 )
V_88 = & V_6 -> V_88 [ V_230 - 1 ] ;
F_99 ( V_6 , F_3 ( V_33
L_44 ,
V_6 -> V_34 , V_26 , type , V_230 ) ) ;
V_6 -> V_219 . V_220 = V_225 ;
V_234 = F_100 ( V_6 , V_87 ) ;
V_6 -> V_219 . V_87 = V_87 ;
memset ( V_234 , 0 , sizeof( T_17 ) ) ;
memset ( V_6 -> V_219 . V_218 , 0 , sizeof( T_18 ) ) ;
V_234 -> V_253 = V_254 ;
V_234 -> V_181 = F_101 ( V_26 ) ;
V_234 -> V_255 = type ;
V_234 -> V_256 = F_101 ( V_230 ) ;
F_102 ( V_94 , (struct V_257 * ) V_234 -> V_258 ) ;
F_89 ( V_6 , V_26 ) ;
F_103 ( & V_6 -> V_219 . V_226 ) ;
F_104 ( V_6 , V_87 ) ;
V_236 = F_105 ( & V_6 -> V_219 . V_226 , V_231 * V_259 ) ;
if ( ! ( V_6 -> V_219 . V_220 & V_222 ) ) {
F_13 ( V_33 L_45 ,
V_6 -> V_34 , V_35 ) ;
F_106 ( V_234 ,
sizeof( T_17 ) / 4 ) ;
if ( ! ( V_6 -> V_219 . V_220 & V_260 ) ) {
V_19 = F_96 ( V_6 , V_245 ,
V_246 ) ;
V_19 = ( ! V_19 ) ? V_247 : V_240 ;
V_6 -> V_219 . V_220 = V_221 ;
F_91 ( V_6 , V_26 ) ;
goto V_241;
}
}
if ( V_6 -> V_219 . V_220 & V_224 ) {
F_107 ( V_6 , V_261 ) ;
V_28 = V_6 -> V_219 . V_218 ;
F_99 ( V_6 , F_3 ( V_33 L_46 \
L_47 ,
V_6 -> V_34 , F_9 ( V_28 -> V_37 ) ,
F_59 ( V_28 -> V_262 ) ,
F_59 ( V_28 -> V_263 ) ) ) ;
if ( V_6 -> V_7 & V_264 ) {
F_84 ( V_6 , V_28 -> V_265 ) ;
if ( V_28 -> V_37 )
F_106 ( V_234 ,
sizeof( T_17 ) / 4 ) ;
}
}
switch ( type ) {
case V_252 :
V_19 = V_247 ;
if ( V_88 -> V_89 == NULL )
break;
V_19 = V_240 ;
break;
case V_266 :
if ( F_44 ( V_6 , V_71 , V_72 ) )
V_19 = V_240 ;
else
V_19 = V_247 ;
break;
case V_267 :
case V_268 :
if ( F_45 ( V_6 , V_71 , V_94 , V_72 ) )
V_19 = V_240 ;
else
V_19 = V_247 ;
break;
case V_269 :
V_19 = V_247 ;
break;
default:
V_19 = V_240 ;
break;
}
F_91 ( V_6 , V_26 ) ;
V_6 -> V_219 . V_220 = V_221 ;
if ( V_233 == V_238 )
F_108 ( & V_6 -> V_219 . V_239 ) ;
return V_19 ;
V_241:
if ( V_233 == V_238 )
F_108 ( & V_6 -> V_219 . V_239 ) ;
return V_19 ;
}
static void
F_109 ( struct V_5 * V_6 , struct V_86 * V_89 )
{
struct V_113 * V_69 = V_89 -> V_42 -> V_270 ;
struct V_104 * V_271 = V_69 -> V_107 ;
struct V_44 * V_45 = NULL ;
unsigned long V_63 ;
char * V_272 = NULL ;
if ( ! V_271 )
return;
V_272 = L_48 ;
F_110 ( V_89 ) ;
if ( V_271 -> V_63 & V_110 ) {
F_111 ( V_130 , V_69 ,
L_49 ,
V_272 , V_271 -> V_26 ,
V_272 , ( unsigned long long ) V_271 -> V_8 ) ;
} else {
F_19 ( & V_6 -> V_64 , V_63 ) ;
V_45 = F_16 ( V_6 ,
V_271 -> V_8 ) ;
if ( V_45 ) {
if ( V_271 -> V_63 &
V_124 ) {
F_111 ( V_130 , V_69 ,
L_50
L_51 ,
V_45 -> V_189 ,
( unsigned long long ) V_45 -> V_190 ) ;
}
F_111 ( V_130 , V_69 ,
L_52 ,
V_45 -> V_26 ,
( unsigned long long ) V_45 -> V_8 ,
V_45 -> V_199 ) ;
F_111 ( V_130 , V_69 ,
L_53 ,
( unsigned long long ) V_45 -> V_13 ,
V_45 -> V_17 ) ;
}
F_22 ( & V_6 -> V_64 , V_63 ) ;
}
}
static int
F_112 ( struct V_86 * V_89 )
{
struct V_5 * V_6 = F_47 ( V_89 -> V_42 -> V_100 ) ;
struct V_102 * V_103 ;
T_4 V_87 ;
T_4 V_26 ;
int V_73 ;
F_56 ( V_130 , V_89 -> V_42 ,
L_54 , V_89 ) ;
F_109 ( V_6 , V_89 ) ;
V_103 = V_89 -> V_42 -> V_107 ;
if ( ! V_103 || ! V_103 -> V_109 ) {
F_56 ( V_130 , V_89 -> V_42 ,
L_55 , V_89 ) ;
V_89 -> V_273 = V_274 << 16 ;
V_89 -> V_275 ( V_89 ) ;
V_73 = V_247 ;
goto V_74;
}
V_87 = F_43 ( V_6 , V_89 ) ;
if ( ! V_87 ) {
V_89 -> V_273 = V_276 << 16 ;
V_73 = V_247 ;
goto V_74;
}
if ( V_103 -> V_109 -> V_63 &
V_124 ||
V_103 -> V_109 -> V_63 & V_110 ) {
V_89 -> V_273 = V_276 << 16 ;
V_73 = V_240 ;
goto V_74;
}
F_113 ( V_6 ) ;
V_26 = V_103 -> V_109 -> V_26 ;
V_73 = F_92 ( V_6 , V_26 , V_89 -> V_42 -> V_72 ,
V_89 -> V_42 -> V_71 , V_89 -> V_42 -> V_94 ,
V_252 , V_87 , 30 , V_238 ) ;
V_74:
F_56 ( V_130 , V_89 -> V_42 , L_56 ,
( ( V_73 == V_247 ) ? L_57 : L_58 ) , V_89 ) ;
return V_73 ;
}
static int
F_114 ( struct V_86 * V_89 )
{
struct V_5 * V_6 = F_47 ( V_89 -> V_42 -> V_100 ) ;
struct V_102 * V_103 ;
struct V_44 * V_45 ;
unsigned long V_63 ;
T_4 V_26 ;
int V_73 ;
F_56 ( V_130 , V_89 -> V_42 ,
L_59 , V_89 ) ;
F_109 ( V_6 , V_89 ) ;
V_103 = V_89 -> V_42 -> V_107 ;
if ( ! V_103 || ! V_103 -> V_109 ) {
F_56 ( V_130 , V_89 -> V_42 ,
L_55 , V_89 ) ;
V_89 -> V_273 = V_274 << 16 ;
V_89 -> V_275 ( V_89 ) ;
V_73 = V_247 ;
goto V_74;
}
V_26 = 0 ;
if ( V_103 -> V_109 -> V_63 &
V_124 ) {
F_19 ( & V_6 -> V_64 , V_63 ) ;
V_45 = F_17 ( V_6 ,
V_103 -> V_109 -> V_26 ) ;
if ( V_45 )
V_26 = V_45 -> V_189 ;
F_22 ( & V_6 -> V_64 , V_63 ) ;
} else
V_26 = V_103 -> V_109 -> V_26 ;
if ( ! V_26 ) {
V_89 -> V_273 = V_276 << 16 ;
V_73 = V_240 ;
goto V_74;
}
V_73 = F_92 ( V_6 , V_26 , V_89 -> V_42 -> V_72 ,
V_89 -> V_42 -> V_71 , V_89 -> V_42 -> V_94 ,
V_268 , 0 , 30 , V_238 ) ;
V_74:
F_56 ( V_130 , V_89 -> V_42 , L_60 ,
( ( V_73 == V_247 ) ? L_57 : L_58 ) , V_89 ) ;
return V_73 ;
}
static int
F_115 ( struct V_86 * V_89 )
{
struct V_5 * V_6 = F_47 ( V_89 -> V_42 -> V_100 ) ;
struct V_102 * V_103 ;
struct V_44 * V_45 ;
unsigned long V_63 ;
T_4 V_26 ;
int V_73 ;
struct V_113 * V_69 = V_89 -> V_42 -> V_270 ;
F_111 ( V_130 , V_69 , L_61 ,
V_89 ) ;
F_109 ( V_6 , V_89 ) ;
V_103 = V_89 -> V_42 -> V_107 ;
if ( ! V_103 || ! V_103 -> V_109 ) {
F_111 ( V_130 , V_69 , L_62 ,
V_89 ) ;
V_89 -> V_273 = V_274 << 16 ;
V_89 -> V_275 ( V_89 ) ;
V_73 = V_247 ;
goto V_74;
}
V_26 = 0 ;
if ( V_103 -> V_109 -> V_63 &
V_124 ) {
F_19 ( & V_6 -> V_64 , V_63 ) ;
V_45 = F_17 ( V_6 ,
V_103 -> V_109 -> V_26 ) ;
if ( V_45 )
V_26 = V_45 -> V_189 ;
F_22 ( & V_6 -> V_64 , V_63 ) ;
} else
V_26 = V_103 -> V_109 -> V_26 ;
if ( ! V_26 ) {
V_89 -> V_273 = V_276 << 16 ;
V_73 = V_240 ;
goto V_74;
}
V_73 = F_92 ( V_6 , V_26 , V_89 -> V_42 -> V_72 ,
V_89 -> V_42 -> V_71 , 0 , V_266 , 0 ,
30 , V_238 ) ;
V_74:
F_111 ( V_130 , V_69 , L_63 ,
( ( V_73 == V_247 ) ? L_57 : L_58 ) , V_89 ) ;
return V_73 ;
}
static int
F_116 ( struct V_86 * V_89 )
{
struct V_5 * V_6 = F_47 ( V_89 -> V_42 -> V_100 ) ;
int V_73 , V_277 ;
F_3 ( V_33 L_64 ,
V_6 -> V_34 , V_89 ) ;
F_110 ( V_89 ) ;
V_277 = F_96 ( V_6 , V_245 ,
V_246 ) ;
V_73 = ( V_277 < 0 ) ? V_240 : V_247 ;
F_3 ( V_33 L_65 ,
V_6 -> V_34 , ( ( V_73 == V_247 ) ? L_57 : L_58 ) , V_89 ) ;
return V_73 ;
}
static void
F_117 ( struct V_5 * V_6 , struct V_278 * V_279 )
{
unsigned long V_63 ;
if ( V_6 -> V_280 == NULL )
return;
F_19 ( & V_6 -> V_281 , V_63 ) ;
F_118 ( & V_279 -> V_65 ) ;
F_28 ( & V_279 -> V_65 , & V_6 -> V_282 ) ;
F_119 ( & V_279 -> V_283 , V_284 ) ;
F_120 ( V_6 -> V_280 , & V_279 -> V_283 ) ;
F_22 ( & V_6 -> V_281 , V_63 ) ;
}
static void
F_121 ( struct V_5 * V_6 , struct V_278
* V_279 )
{
unsigned long V_63 ;
F_19 ( & V_6 -> V_281 , V_63 ) ;
F_20 ( & V_279 -> V_65 ) ;
F_21 ( V_279 ) ;
F_22 ( & V_6 -> V_281 , V_63 ) ;
}
void
F_122 ( struct V_5 * V_6 ,
struct V_285 * V_286 )
{
struct V_278 * V_279 ;
if ( V_6 -> V_48 )
return;
V_279 = F_51 ( sizeof( * V_279 ) + sizeof( * V_286 ) ,
V_287 ) ;
if ( ! V_279 )
return;
V_279 -> V_288 = V_289 ;
V_279 -> V_6 = V_6 ;
memcpy ( V_279 -> V_286 , V_286 , sizeof( * V_286 ) ) ;
F_117 ( V_6 , V_279 ) ;
}
static void
F_123 ( struct V_5 * V_6 )
{
struct V_278 * V_279 ;
if ( V_6 -> V_48 )
return;
V_279 = F_51 ( sizeof( struct V_278 ) , V_287 ) ;
if ( ! V_279 )
return;
V_279 -> V_288 = V_290 ;
V_279 -> V_6 = V_6 ;
F_117 ( V_6 , V_279 ) ;
}
void
F_124 ( struct V_5 * V_6 )
{
struct V_278 * V_279 ;
V_279 = F_51 ( sizeof( struct V_278 ) , V_287 ) ;
if ( ! V_279 )
return;
V_279 -> V_288 = V_291 ;
V_279 -> V_6 = V_6 ;
F_117 ( V_6 , V_279 ) ;
}
static void
F_125 ( struct V_5 * V_6 )
{
struct V_278 * V_279 , * V_292 ;
if ( F_126 ( & V_6 -> V_282 ) ||
! V_6 -> V_280 || F_127 () )
return;
F_128 (fw_event, next, &ioc->fw_event_list, list) {
if ( F_129 ( & V_279 -> V_293 ) ) {
F_121 ( V_6 , V_279 ) ;
continue;
}
}
}
static void
F_130 ( struct V_5 * V_6 )
{
struct V_102 * V_103 ;
struct V_95 * V_96 ;
F_90 (sdev, ioc->shost) {
V_103 = V_96 -> V_107 ;
if ( ! V_103 )
continue;
if ( ! V_103 -> V_294 )
continue;
V_103 -> V_294 = 0 ;
F_27 ( V_6 , F_56 ( V_130 , V_96 ,
L_66 ,
V_103 -> V_109 -> V_26 ) ) ;
F_131 ( V_96 , V_295 ) ;
}
}
static void
F_132 ( struct V_5 * V_6 , T_1 V_8 )
{
struct V_102 * V_103 ;
struct V_95 * V_96 ;
F_90 (sdev, ioc->shost) {
V_103 = V_96 -> V_107 ;
if ( ! V_103 )
continue;
if ( V_103 -> V_109 -> V_8
!= V_8 )
continue;
if ( V_103 -> V_294 ) {
V_103 -> V_294 = 0 ;
F_131 ( V_96 , V_295 ) ;
}
}
}
static void
F_133 ( struct V_5 * V_6 )
{
struct V_102 * V_103 ;
struct V_95 * V_96 ;
F_90 (sdev, ioc->shost) {
V_103 = V_96 -> V_107 ;
if ( ! V_103 )
continue;
if ( V_103 -> V_294 )
continue;
V_103 -> V_294 = 1 ;
F_134 ( V_96 ) ;
F_56 ( V_130 , V_96 , L_67 ,
V_103 -> V_109 -> V_26 ) ;
}
}
static void
F_135 ( struct V_5 * V_6 , T_4 V_26 )
{
struct V_102 * V_103 ;
struct V_95 * V_96 ;
F_90 (sdev, ioc->shost) {
V_103 = V_96 -> V_107 ;
if ( ! V_103 )
continue;
if ( V_103 -> V_109 -> V_26 != V_26 )
continue;
if ( V_103 -> V_294 )
continue;
V_103 -> V_294 = 1 ;
F_134 ( V_96 ) ;
F_56 ( V_130 , V_96 ,
L_67 , V_26 ) ;
}
}
static void
F_136 ( struct V_5 * V_6 ,
struct V_77 * V_78 )
{
struct V_296 * V_297 ;
struct V_44 * V_45 ;
struct V_77 * V_298 ;
unsigned long V_63 ;
if ( ! V_78 )
return;
F_4 (mpt3sas_port,
&sas_expander->sas_port_list, port_list) {
if ( V_297 -> V_299 . V_300 ==
V_301 ) {
F_19 ( & V_6 -> V_64 , V_63 ) ;
V_45 =
F_16 ( V_6 ,
V_297 -> V_299 . V_8 ) ;
if ( V_45 )
F_137 ( V_45 -> V_26 ,
V_6 -> V_302 ) ;
F_22 ( & V_6 -> V_64 , V_63 ) ;
}
}
F_4 (mpt3sas_port,
&sas_expander->sas_port_list, port_list) {
if ( V_297 -> V_299 . V_300 ==
V_303 ||
V_297 -> V_299 . V_300 ==
V_304 ) {
V_298 =
F_38 (
V_6 , V_297 -> V_299 . V_8 ) ;
F_136 ( V_6 ,
V_298 ) ;
}
}
}
static void
F_138 ( struct V_5 * V_6 ,
T_19 * V_286 )
{
int V_91 ;
T_4 V_26 ;
T_4 V_305 ;
for ( V_91 = 0 ; V_91 < V_286 -> V_306 ; V_91 ++ ) {
V_26 = F_9 ( V_286 -> V_307 [ V_91 ] . V_308 ) ;
if ( ! V_26 )
continue;
V_305 = V_286 -> V_307 [ V_91 ] . V_309 &
V_310 ;
if ( V_305 == V_311 )
F_135 ( V_6 , V_26 ) ;
}
}
static void
F_139 ( struct V_5 * V_6 , T_4 V_26 )
{
T_17 * V_234 ;
T_4 V_87 ;
struct V_44 * V_45 ;
struct V_104 * V_105 = NULL ;
T_1 V_8 = 0 ;
unsigned long V_63 ;
struct V_312 * V_313 ;
T_10 V_235 ;
if ( V_6 -> V_242 ) {
F_27 ( V_6 , F_3 ( V_33
L_68 ,
V_35 , V_6 -> V_34 , V_26 ) ) ;
return;
} else if ( V_6 -> V_243 ) {
F_27 ( V_6 , F_3 ( V_33
L_69 ,
V_35 , V_6 -> V_34 ,
V_26 ) ) ;
return;
}
V_235 = F_94 ( V_6 , 1 ) ;
if ( V_235 != V_314 ) {
F_27 ( V_6 , F_3 ( V_33
L_70 ,
V_35 , V_6 -> V_34 ,
V_26 ) ) ;
return;
}
if ( F_53 ( V_26 , V_6 -> V_123 ) )
return;
F_19 ( & V_6 -> V_64 , V_63 ) ;
V_45 = F_17 ( V_6 , V_26 ) ;
if ( V_45 && V_45 -> V_69 &&
V_45 -> V_69 -> V_107 ) {
V_105 = V_45 -> V_69 -> V_107 ;
V_105 -> V_315 = 1 ;
V_8 = V_45 -> V_8 ;
}
F_22 ( & V_6 -> V_64 , V_63 ) ;
if ( V_105 ) {
F_27 ( V_6 , F_3 ( V_33
L_71 ,
V_6 -> V_34 , V_26 ,
( unsigned long long ) V_8 ) ) ;
F_132 ( V_6 , V_8 ) ;
V_105 -> V_26 = V_119 ;
}
V_87 = F_98 ( V_6 , V_6 -> V_316 ) ;
if ( ! V_87 ) {
V_313 = F_51 ( sizeof( * V_313 ) , V_287 ) ;
if ( ! V_313 )
return;
F_118 ( & V_313 -> V_65 ) ;
V_313 -> V_26 = V_26 ;
F_28 ( & V_313 -> V_65 , & V_6 -> V_317 ) ;
F_27 ( V_6 , F_3 ( V_33
L_72 ,
V_6 -> V_34 , V_26 ) ) ;
return;
}
F_27 ( V_6 , F_3 ( V_33
L_73 ,
V_6 -> V_34 , V_26 , V_87 ,
V_6 -> V_316 ) ) ;
V_234 = F_100 ( V_6 , V_87 ) ;
memset ( V_234 , 0 , sizeof( T_17 ) ) ;
V_234 -> V_253 = V_254 ;
V_234 -> V_181 = F_101 ( V_26 ) ;
V_234 -> V_255 = V_266 ;
F_104 ( V_6 , V_87 ) ;
F_107 ( V_6 , V_318 ) ;
}
static T_6
F_140 ( struct V_5 * V_6 , T_4 V_87 , T_6 V_217 ,
T_10 V_218 )
{
T_4 V_26 ;
T_17 * V_319 ;
T_18 * V_28 =
F_87 ( V_6 , V_218 ) ;
T_20 * V_234 ;
T_4 V_320 ;
T_10 V_235 ;
if ( V_6 -> V_242 ) {
F_27 ( V_6 , F_3 ( V_33
L_74 , V_35 , V_6 -> V_34 ) ) ;
return 1 ;
} else if ( V_6 -> V_243 ) {
F_27 ( V_6 , F_3 ( V_33
L_75 , V_35 ,
V_6 -> V_34 ) ) ;
return 1 ;
}
V_235 = F_94 ( V_6 , 1 ) ;
if ( V_235 != V_314 ) {
F_27 ( V_6 , F_3 ( V_33
L_76 , V_35 , V_6 -> V_34 ) ) ;
return 1 ;
}
if ( F_141 ( ! V_28 ) ) {
F_13 ( V_33 L_77 ,
V_6 -> V_34 , __FILE__ , __LINE__ , V_35 ) ;
return 1 ;
}
V_319 = F_100 ( V_6 , V_87 ) ;
V_26 = F_9 ( V_319 -> V_181 ) ;
if ( V_26 != F_9 ( V_28 -> V_181 ) ) {
F_27 ( V_6 , F_13 ( V_33
L_78 ,
V_6 -> V_34 , V_26 ,
F_9 ( V_28 -> V_181 ) , V_87 ) ) ;
return 0 ;
}
F_107 ( V_6 , V_261 ) ;
F_27 ( V_6 , F_3 ( V_33
L_79
L_80 , V_6 -> V_34 ,
V_26 , V_87 , F_9 ( V_28 -> V_37 ) ,
F_59 ( V_28 -> V_262 ) ,
F_59 ( V_28 -> V_263 ) ) ) ;
V_320 = F_142 ( V_6 , V_6 -> V_321 ) ;
if ( ! V_320 ) {
F_13 ( V_33 L_43 ,
V_6 -> V_34 , V_35 ) ;
return 1 ;
}
F_27 ( V_6 , F_3 ( V_33
L_81 ,
V_6 -> V_34 , V_26 , V_320 ,
V_6 -> V_321 ) ) ;
V_234 = F_100 ( V_6 , V_320 ) ;
memset ( V_234 , 0 , sizeof( T_20 ) ) ;
V_234 -> V_253 = V_322 ;
V_234 -> V_323 = V_324 ;
V_234 -> V_181 = V_319 -> V_181 ;
F_143 ( V_6 , V_320 ) ;
return F_144 ( V_6 , V_87 ) ;
}
static T_6
F_145 ( struct V_5 * V_6 , T_4 V_87 ,
T_6 V_217 , T_10 V_218 )
{
T_21 * V_28 =
F_87 ( V_6 , V_218 ) ;
if ( F_146 ( V_28 ) ) {
F_27 ( V_6 , F_3 ( V_33
L_82
L_83 ,
V_6 -> V_34 , F_9 ( V_28 -> V_181 ) , V_87 ,
F_9 ( V_28 -> V_37 ) ,
F_59 ( V_28 -> V_262 ) ) ) ;
} else {
F_13 ( V_33 L_77 ,
V_6 -> V_34 , __FILE__ , __LINE__ , V_35 ) ;
}
return 1 ;
}
static void
F_147 ( struct V_5 * V_6 , T_4 V_26 )
{
T_17 * V_234 ;
T_4 V_87 ;
struct V_312 * V_313 ;
if ( V_6 -> V_66 || V_6 -> V_242 ||
V_6 -> V_243 ) {
F_27 ( V_6 , F_3 ( V_33
L_41 ,
V_35 , V_6 -> V_34 ) ) ;
return;
}
V_87 = F_98 ( V_6 , V_6 -> V_325 ) ;
if ( ! V_87 ) {
V_313 = F_51 ( sizeof( * V_313 ) , V_287 ) ;
if ( ! V_313 )
return;
F_118 ( & V_313 -> V_65 ) ;
V_313 -> V_26 = V_26 ;
F_28 ( & V_313 -> V_65 , & V_6 -> V_326 ) ;
F_27 ( V_6 , F_3 ( V_33
L_72 ,
V_6 -> V_34 , V_26 ) ) ;
return;
}
F_27 ( V_6 , F_3 ( V_33
L_73 ,
V_6 -> V_34 , V_26 , V_87 ,
V_6 -> V_325 ) ) ;
V_234 = F_100 ( V_6 , V_87 ) ;
memset ( V_234 , 0 , sizeof( T_17 ) ) ;
V_234 -> V_253 = V_254 ;
V_234 -> V_181 = F_101 ( V_26 ) ;
V_234 -> V_255 = V_266 ;
F_104 ( V_6 , V_87 ) ;
}
static T_6
F_148 ( struct V_5 * V_6 , T_4 V_87 ,
T_6 V_217 , T_10 V_218 )
{
T_4 V_26 ;
T_17 * V_319 ;
T_18 * V_28 =
F_87 ( V_6 , V_218 ) ;
if ( V_6 -> V_66 || V_6 -> V_242 ||
V_6 -> V_243 ) {
F_27 ( V_6 , F_3 ( V_33
L_41 ,
V_35 , V_6 -> V_34 ) ) ;
return 1 ;
}
if ( F_141 ( ! V_28 ) ) {
F_13 ( V_33 L_77 ,
V_6 -> V_34 , __FILE__ , __LINE__ , V_35 ) ;
return 1 ;
}
V_319 = F_100 ( V_6 , V_87 ) ;
V_26 = F_9 ( V_319 -> V_181 ) ;
if ( V_26 != F_9 ( V_28 -> V_181 ) ) {
F_27 ( V_6 , F_13 ( V_33
L_78 ,
V_6 -> V_34 , V_26 ,
F_9 ( V_28 -> V_181 ) , V_87 ) ) ;
return 0 ;
}
F_27 ( V_6 , F_3 ( V_33
L_79
L_80 , V_6 -> V_34 ,
V_26 , V_87 , F_9 ( V_28 -> V_37 ) ,
F_59 ( V_28 -> V_262 ) ,
F_59 ( V_28 -> V_263 ) ) ) ;
return F_144 ( V_6 , V_87 ) ;
}
static T_6
F_144 ( struct V_5 * V_6 , T_4 V_87 )
{
struct V_312 * V_313 ;
if ( ! F_126 ( & V_6 -> V_326 ) ) {
V_313 = F_149 ( V_6 -> V_326 . V_292 ,
struct V_312 , V_65 ) ;
F_150 ( V_6 , V_87 ) ;
F_147 ( V_6 , V_313 -> V_26 ) ;
F_20 ( & V_313 -> V_65 ) ;
F_21 ( V_313 ) ;
return 0 ;
}
if ( ! F_126 ( & V_6 -> V_317 ) ) {
V_313 = F_149 ( V_6 -> V_317 . V_292 ,
struct V_312 , V_65 ) ;
F_150 ( V_6 , V_87 ) ;
F_139 ( V_6 , V_313 -> V_26 ) ;
F_20 ( & V_313 -> V_65 ) ;
F_21 ( V_313 ) ;
return 0 ;
}
return 1 ;
}
static void
F_151 ( struct V_5 * V_6 ,
T_19 * V_286 )
{
struct V_278 * V_279 ;
T_19 * V_327 ;
T_4 V_328 ;
struct V_77 * V_78 ;
unsigned long V_63 ;
int V_91 , V_305 ;
T_4 V_26 ;
for ( V_91 = 0 ; V_91 < V_286 -> V_306 ; V_91 ++ ) {
V_26 = F_9 ( V_286 -> V_307 [ V_91 ] . V_308 ) ;
if ( ! V_26 )
continue;
V_305 = V_286 -> V_307 [ V_91 ] . V_309 &
V_310 ;
if ( V_305 == V_329 )
F_139 ( V_6 , V_26 ) ;
}
V_328 = F_9 ( V_286 -> V_330 ) ;
if ( V_328 < V_6 -> V_30 . V_31 ) {
F_138 ( V_6 , V_286 ) ;
return;
}
if ( V_286 -> V_331 ==
V_332 ) {
F_19 ( & V_6 -> V_79 , V_63 ) ;
V_78 = F_37 ( V_6 ,
V_328 ) ;
F_136 ( V_6 , V_78 ) ;
F_22 ( & V_6 -> V_79 , V_63 ) ;
do {
V_26 = F_152 ( V_6 -> V_302 ,
V_6 -> V_183 . V_333 ) ;
if ( V_26 < V_6 -> V_183 . V_333 )
F_135 ( V_6 , V_26 ) ;
} while ( F_153 ( V_26 , V_6 -> V_302 ) );
} else if ( V_286 -> V_331 == V_334 )
F_138 ( V_6 , V_286 ) ;
if ( V_286 -> V_331 != V_335 )
return;
F_19 ( & V_6 -> V_281 , V_63 ) ;
F_4 (fw_event, &ioc->fw_event_list, list) {
if ( V_279 -> V_288 != V_336 ||
V_279 -> V_337 )
continue;
V_327 = ( T_19 * )
V_279 -> V_286 ;
if ( V_327 -> V_331 ==
V_338 ||
V_327 -> V_331 ==
V_334 ) {
if ( F_9 ( V_327 -> V_330 ) ==
V_328 ) {
F_27 ( V_6 , F_3 ( V_33
L_84 , V_6 -> V_34 ) ) ;
V_279 -> V_337 = 1 ;
}
}
}
F_22 ( & V_6 -> V_281 , V_63 ) ;
}
static void
F_154 ( struct V_5 * V_6 , T_4 V_26 )
{
struct V_46 * V_47 ;
struct V_104 * V_105 ;
unsigned long V_63 ;
F_19 ( & V_6 -> V_75 , V_63 ) ;
V_47 = F_33 ( V_6 , V_26 ) ;
if ( V_47 && V_47 -> V_69 &&
V_47 -> V_69 -> V_107 ) {
V_105 =
V_47 -> V_69 -> V_107 ;
V_105 -> V_315 = 1 ;
F_27 ( V_6 , F_3 ( V_33
L_85
L_86 , V_6 -> V_34 , V_26 ,
( unsigned long long ) V_47 -> V_51 ) ) ;
}
F_22 ( & V_6 -> V_75 , V_63 ) ;
}
static void
F_155 ( T_4 V_26 , T_4 * V_339 , T_4 * V_340 )
{
if ( ! V_26 || V_26 == * V_339 || V_26 == * V_340 )
return;
if ( ! * V_339 )
* V_339 = V_26 ;
else if ( ! * V_340 )
* V_340 = V_26 ;
}
static void
F_156 ( struct V_5 * V_6 ,
T_22 * V_286 )
{
T_23 * V_341 ;
int V_91 ;
T_4 V_26 , V_189 , V_339 , V_340 ;
struct V_312 * V_313 ;
V_339 = 0 ;
V_340 = 0 ;
V_341 = ( T_23 * ) & V_286 -> V_342 [ 0 ] ;
for ( V_91 = 0 ; V_91 < V_286 -> V_343 ; V_91 ++ , V_341 ++ ) {
if ( F_59 ( V_286 -> V_131 ) &
V_344 )
continue;
if ( V_341 -> V_345 ==
V_346 ||
V_341 -> V_345 ==
V_347 ) {
V_189 = F_9 ( V_341 -> V_348 ) ;
F_154 ( V_6 , V_189 ) ;
F_155 ( V_189 , & V_339 , & V_340 ) ;
}
}
V_341 = ( T_23 * ) & V_286 -> V_342 [ 0 ] ;
for ( V_91 = 0 ; V_91 < V_286 -> V_343 ; V_91 ++ , V_341 ++ ) {
if ( F_59 ( V_286 -> V_131 ) &
V_344 )
continue;
if ( V_341 -> V_345 == V_349 ) {
V_189 = F_9 ( V_341 -> V_348 ) ;
F_155 ( V_189 , & V_339 , & V_340 ) ;
}
}
if ( V_339 )
F_147 ( V_6 , V_339 ) ;
if ( V_340 )
F_147 ( V_6 , V_340 ) ;
V_341 = ( T_23 * ) & V_286 -> V_342 [ 0 ] ;
for ( V_91 = 0 ; V_91 < V_286 -> V_343 ; V_91 ++ , V_341 ++ ) {
if ( V_341 -> V_345 != V_349 )
continue;
V_26 = F_9 ( V_341 -> V_350 ) ;
V_189 = F_9 ( V_341 -> V_348 ) ;
F_157 ( V_26 , V_6 -> V_123 ) ;
if ( ! V_189 )
F_139 ( V_6 , V_26 ) ;
else if ( V_189 == V_339 || V_189 == V_340 ) {
V_313 = F_51 ( sizeof( * V_313 ) , V_287 ) ;
F_158 ( ! V_313 ) ;
F_118 ( & V_313 -> V_65 ) ;
V_313 -> V_26 = V_26 ;
F_28 ( & V_313 -> V_65 , & V_6 -> V_317 ) ;
F_27 ( V_6 , F_3 ( V_33
L_72 , V_6 -> V_34 ,
V_26 ) ) ;
} else
F_139 ( V_6 , V_26 ) ;
}
}
static void
F_159 ( struct V_5 * V_6 ,
T_24 * V_286 )
{
T_10 V_148 ;
if ( V_286 -> V_345 != V_351 )
return;
V_148 = F_59 ( V_286 -> V_352 ) ;
if ( V_148 == V_158 || V_148 ==
V_157 )
F_154 ( V_6 ,
F_9 ( V_286 -> V_348 ) ) ;
}
static void
F_160 ( struct V_5 * V_6 )
{
struct V_86 * V_89 ;
T_4 V_87 ;
T_4 V_353 = 0 ;
for ( V_87 = 1 ; V_87 <= V_6 -> V_92 ; V_87 ++ ) {
V_89 = F_42 ( V_6 , V_87 ) ;
if ( ! V_89 )
continue;
V_353 ++ ;
F_150 ( V_6 , V_87 ) ;
F_161 ( V_89 ) ;
if ( V_6 -> V_243 )
V_89 -> V_273 = V_274 << 16 ;
else
V_89 -> V_273 = V_276 << 16 ;
V_89 -> V_275 ( V_89 ) ;
}
F_99 ( V_6 , F_3 ( V_33 L_87 ,
V_6 -> V_34 , V_353 ) ) ;
}
static void
F_162 ( struct V_5 * V_6 , struct V_86 * V_89 ,
T_25 * V_234 )
{
T_4 V_354 ;
unsigned char V_355 = F_163 ( V_89 ) ;
unsigned char V_356 = F_164 ( V_89 ) ;
T_26 * V_357 =
( T_26 * ) V_234 ;
if ( V_356 == V_358 || V_355 == V_359 )
return;
if ( V_355 == V_360 )
V_354 = V_361 ;
else if ( V_355 == V_362 )
V_354 = V_363 ;
else
return;
switch ( V_356 ) {
case V_364 :
case V_365 :
V_354 |= V_366 |
V_367 |
V_368 ;
V_234 -> V_369 . V_370 . V_371 =
F_165 ( F_166 ( V_89 ) ) ;
break;
case V_372 :
V_354 |= V_368 ;
break;
}
V_357 -> V_373 =
F_101 ( V_89 -> V_42 -> V_374 ) ;
V_234 -> V_375 = F_101 ( V_354 ) ;
}
static void
F_167 ( struct V_86 * V_89 , T_4 V_29 )
{
T_6 V_376 ;
switch ( V_29 ) {
case V_377 :
V_376 = 0x01 ;
break;
case V_378 :
V_376 = 0x02 ;
break;
case V_379 :
V_376 = 0x03 ;
break;
default:
V_376 = 0x00 ;
break;
}
F_168 ( 0 , V_89 -> V_380 , V_381 , 0x10 ,
V_376 ) ;
V_89 -> V_273 = V_382 << 24 | ( V_383 << 16 ) |
V_384 ;
}
static int
F_169 ( struct V_98 * V_99 , struct V_86 * V_89 )
{
struct V_5 * V_6 = F_47 ( V_99 ) ;
struct V_102 * V_103 ;
struct V_104 * V_105 ;
T_25 * V_234 ;
T_10 V_385 ;
T_4 V_87 ;
T_4 V_26 ;
#ifdef F_170
if ( V_6 -> V_7 & V_386 )
F_110 ( V_89 ) ;
#endif
V_103 = V_89 -> V_42 -> V_107 ;
if ( ! V_103 || ! V_103 -> V_109 ) {
V_89 -> V_273 = V_274 << 16 ;
V_89 -> V_275 ( V_89 ) ;
return 0 ;
}
if ( V_6 -> V_243 || V_6 -> V_242 ) {
V_89 -> V_273 = V_274 << 16 ;
V_89 -> V_275 ( V_89 ) ;
return 0 ;
}
V_105 = V_103 -> V_109 ;
V_26 = V_105 -> V_26 ;
if ( V_26 == V_119 ) {
V_89 -> V_273 = V_274 << 16 ;
V_89 -> V_275 ( V_89 ) ;
return 0 ;
}
if ( V_6 -> V_66 || V_6 -> V_387 )
return V_388 ;
else if ( V_105 -> V_315 ) {
V_89 -> V_273 = V_274 << 16 ;
V_89 -> V_275 ( V_89 ) ;
return 0 ;
} else if ( V_105 -> V_228 ||
V_103 -> V_294 )
return V_389 ;
if ( V_89 -> V_390 == V_391 )
V_385 = V_392 ;
else if ( V_89 -> V_390 == V_393 )
V_385 = V_394 ;
else
V_385 = V_395 ;
V_385 |= V_396 ;
if ( ( V_103 -> V_63 & V_397 ) &&
V_89 -> V_398 != 32 )
V_385 |= V_399 ;
V_87 = F_171 ( V_6 , V_6 -> V_400 , V_89 ) ;
if ( ! V_87 ) {
F_13 ( V_33 L_43 ,
V_6 -> V_34 , V_35 ) ;
goto V_74;
}
V_234 = F_100 ( V_6 , V_87 ) ;
memset ( V_234 , 0 , sizeof( T_25 ) ) ;
F_162 ( V_6 , V_89 , V_234 ) ;
if ( V_89 -> V_398 == 32 )
V_385 |= 4 << V_401 ;
V_234 -> V_253 = V_402 ;
if ( V_103 -> V_109 -> V_63 &
V_124 )
V_234 -> V_253 = V_403 ;
else
V_234 -> V_253 = V_402 ;
V_234 -> V_181 = F_101 ( V_26 ) ;
V_234 -> V_404 = F_172 ( F_173 ( V_89 ) ) ;
V_234 -> V_405 = F_172 ( V_385 ) ;
V_234 -> V_406 = F_101 ( V_89 -> V_398 ) ;
V_234 -> V_407 = V_408 ;
V_234 -> V_409 = V_410 ;
V_234 -> V_411 =
F_174 ( V_6 , V_87 ) ;
V_234 -> V_412 = F_73 ( T_25 , V_413 ) / 4 ;
F_102 ( V_103 -> V_94 , (struct V_257 * )
V_234 -> V_258 ) ;
memcpy ( V_234 -> V_369 . V_414 , V_89 -> V_415 , V_89 -> V_398 ) ;
if ( V_234 -> V_404 ) {
if ( V_6 -> V_416 ( V_6 , V_89 , V_87 ) ) {
F_150 ( V_6 , V_87 ) ;
goto V_74;
}
} else
V_6 -> V_417 ( V_6 , & V_234 -> V_413 ) ;
if ( F_146 ( V_234 -> V_253 == V_402 ) ) {
if ( V_105 -> V_63 & V_126 ) {
V_234 -> V_406 = F_101 ( V_89 -> V_398 |
V_418 ) ;
F_175 ( V_6 , V_87 , V_26 ) ;
} else
F_176 ( V_6 , V_87 , V_26 ) ;
} else
F_143 ( V_6 , V_87 ) ;
return 0 ;
V_74:
return V_388 ;
}
static void
F_177 ( char * V_380 , struct V_419 * V_420 )
{
if ( ( V_380 [ 0 ] & 0x7F ) >= 0x72 ) {
V_420 -> V_421 = V_380 [ 1 ] & 0x0F ;
V_420 -> V_422 = V_380 [ 2 ] ;
V_420 -> V_376 = V_380 [ 3 ] ;
} else {
V_420 -> V_421 = V_380 [ 2 ] & 0x0F ;
V_420 -> V_422 = V_380 [ 12 ] ;
V_420 -> V_376 = V_380 [ 13 ] ;
}
}
static void
F_178 ( struct V_5 * V_6 , struct V_86 * V_89 ,
T_27 * V_28 , T_4 V_87 )
{
T_10 V_423 ;
T_6 * V_424 ;
T_4 V_29 = F_9 ( V_28 -> V_37 ) &
V_38 ;
T_6 V_425 = V_28 -> V_426 ;
T_6 V_427 = V_28 -> V_428 ;
char * V_429 = NULL ;
char * V_430 = NULL ;
char * V_431 = V_6 -> V_432 ;
T_10 V_433 = F_59 ( V_28 -> V_262 ) ;
struct V_44 * V_45 = NULL ;
unsigned long V_63 ;
struct V_113 * V_69 = V_89 -> V_42 -> V_270 ;
struct V_104 * V_271 = V_69 -> V_107 ;
char * V_272 = NULL ;
if ( ! V_271 )
return;
V_272 = L_48 ;
if ( V_433 == 0x31170000 )
return;
switch ( V_29 ) {
case V_39 :
V_429 = L_88 ;
break;
case V_434 :
V_429 = L_89 ;
break;
case V_435 :
V_429 = L_90 ;
break;
case V_436 :
V_429 = L_91 ;
break;
case V_437 :
V_429 = L_92 ;
break;
case V_438 :
V_429 = L_93 ;
break;
case V_439 :
V_429 = L_94 ;
break;
case V_440 :
V_429 = L_95 ;
break;
case V_441 :
V_429 = L_96 ;
break;
case V_442 :
V_429 = L_97 ;
break;
case V_443 :
V_429 = L_98 ;
break;
case V_444 :
V_429 = L_99 ;
break;
case V_445 :
V_429 = L_100 ;
break;
case V_446 :
V_429 = L_101 ;
break;
case V_377 :
V_429 = L_102 ;
break;
case V_379 :
V_429 = L_103 ;
break;
case V_378 :
V_429 = L_104 ;
break;
default:
V_429 = L_38 ;
break;
}
switch ( V_427 ) {
case V_447 :
V_430 = L_105 ;
break;
case V_448 :
V_430 = L_106 ;
break;
case V_449 :
V_430 = L_107 ;
break;
case V_450 :
V_430 = L_108 ;
break;
case V_451 :
V_430 = L_109 ;
break;
case V_452 :
V_430 = L_110 ;
break;
case V_453 :
V_430 = L_111 ;
break;
case V_454 :
V_430 = L_112 ;
break;
case V_455 :
V_430 = L_113 ;
break;
case V_456 :
V_430 = L_114 ;
break;
case V_457 :
V_430 = L_115 ;
break;
default:
V_430 = L_38 ;
break;
}
V_431 [ 0 ] = '\0' ;
if ( ! V_425 )
V_431 = L_116 ;
if ( V_425 & V_458 )
strcat ( V_431 , L_117 ) ;
if ( V_425 & V_459 )
strcat ( V_431 , L_118 ) ;
if ( V_425 & V_460 )
strcat ( V_431 , L_119 ) ;
if ( V_425 & V_461 )
strcat ( V_431 , L_120 ) ;
if ( V_425 & V_462 )
strcat ( V_431 , L_121 ) ;
F_110 ( V_89 ) ;
if ( V_271 -> V_63 & V_110 ) {
F_72 ( V_33 L_122 , V_6 -> V_34 ,
V_272 , ( unsigned long long ) V_271 -> V_8 ) ;
} else {
F_19 ( & V_6 -> V_64 , V_63 ) ;
V_45 = F_16 ( V_6 ,
V_271 -> V_8 ) ;
if ( V_45 ) {
F_72 ( V_33
L_123 ,
V_6 -> V_34 , ( unsigned long long )
V_45 -> V_8 , V_45 -> V_199 ) ;
F_72 ( V_33
L_124 ,
V_6 -> V_34 , ( unsigned long long )
V_45 -> V_13 , V_45 -> V_17 ) ;
}
F_22 ( & V_6 -> V_64 , V_63 ) ;
}
F_72 ( V_33
L_125 ,
V_6 -> V_34 , F_9 ( V_28 -> V_181 ) ,
V_429 , V_29 , V_87 ) ;
F_72 ( V_33
L_126 ,
V_6 -> V_34 , F_173 ( V_89 ) , V_89 -> V_463 ,
F_179 ( V_89 ) ) ;
F_72 ( V_33
L_127 ,
V_6 -> V_34 , F_9 ( V_28 -> V_464 ) ,
F_59 ( V_28 -> V_465 ) , V_89 -> V_273 ) ;
F_72 ( V_33
L_128 ,
V_6 -> V_34 , V_430 ,
V_427 , V_431 , V_425 ) ;
if ( V_425 & V_462 ) {
struct V_419 V_420 ;
F_177 ( V_89 -> V_380 , & V_420 ) ;
F_72 ( V_33
L_129 ,
V_6 -> V_34 , V_420 . V_421 ,
V_420 . V_422 , V_420 . V_376 , F_59 ( V_28 -> V_466 ) ) ;
}
if ( V_425 & V_458 ) {
V_423 = F_59 ( V_28 -> V_467 ) ;
V_424 = ( T_6 * ) & V_423 ;
F_84 ( V_6 , V_424 [ 0 ] ) ;
}
}
static void
F_180 ( struct V_5 * V_6 , T_4 V_26 )
{
T_28 V_28 ;
T_29 V_234 ;
struct V_44 * V_45 ;
V_45 = F_17 ( V_6 , V_26 ) ;
if ( ! V_45 )
return;
memset ( & V_234 , 0 , sizeof( T_29 ) ) ;
V_234 . V_253 = V_468 ;
V_234 . V_469 = V_470 ;
V_234 . V_471 =
F_172 ( V_472 ) ;
V_234 . V_181 = F_101 ( V_26 ) ;
V_234 . V_131 = V_473 ;
if ( ( F_181 ( V_6 , & V_28 ,
& V_234 ) ) != 0 ) {
F_13 ( V_33 L_2 , V_6 -> V_34 ,
__FILE__ , __LINE__ , V_35 ) ;
return;
}
V_45 -> V_474 = 1 ;
if ( V_28 . V_37 || V_28 . V_262 ) {
F_27 ( V_6 , F_3 ( V_33
L_130 ,
V_6 -> V_34 , F_9 ( V_28 . V_37 ) ,
F_59 ( V_28 . V_262 ) ) ) ;
return;
}
}
static void
F_182 ( struct V_5 * V_6 ,
struct V_44 * V_45 )
{
T_28 V_28 ;
T_29 V_234 ;
memset ( & V_234 , 0 , sizeof( T_29 ) ) ;
V_234 . V_253 = V_468 ;
V_234 . V_469 = V_470 ;
V_234 . V_471 = 0 ;
V_234 . V_475 = F_101 ( V_45 -> V_17 ) ;
V_234 . V_181 = 0 ;
V_234 . V_476 = F_101 ( V_45 -> V_477 ) ;
V_234 . V_131 = V_478 ;
if ( ( F_181 ( V_6 , & V_28 ,
& V_234 ) ) != 0 ) {
F_183 ( V_33 L_2 , V_6 -> V_34 ,
__FILE__ , __LINE__ , V_35 ) ;
return;
}
if ( V_28 . V_37 || V_28 . V_262 ) {
F_27 ( V_6 , F_183 ( V_33
L_130 ,
V_6 -> V_34 , F_9 ( V_28 . V_37 ) ,
F_59 ( V_28 . V_262 ) ) ) ;
return;
}
}
static void
F_184 ( struct V_5 * V_6 , T_4 V_26 )
{
struct V_278 * V_279 ;
V_279 = F_51 ( sizeof( struct V_278 ) , V_287 ) ;
if ( ! V_279 )
return;
V_279 -> V_288 = V_479 ;
V_279 -> V_480 = V_26 ;
V_279 -> V_6 = V_6 ;
F_117 ( V_6 , V_279 ) ;
}
static void
F_185 ( struct V_5 * V_6 , T_4 V_26 )
{
struct V_113 * V_69 ;
struct V_104 * V_105 ;
T_30 * V_481 ;
T_31 * V_286 ;
struct V_44 * V_45 ;
T_32 V_174 ;
unsigned long V_63 ;
F_19 ( & V_6 -> V_64 , V_63 ) ;
V_45 = F_17 ( V_6 , V_26 ) ;
if ( ! V_45 ) {
F_22 ( & V_6 -> V_64 , V_63 ) ;
return;
}
V_69 = V_45 -> V_69 ;
V_105 = V_69 -> V_107 ;
if ( ( V_105 -> V_63 & V_124 ) ||
( ( V_105 -> V_63 & V_110 ) ) ) {
F_22 ( & V_6 -> V_64 , V_63 ) ;
return;
}
F_111 ( V_482 , V_69 , L_131 ) ;
F_22 ( & V_6 -> V_64 , V_63 ) ;
if ( V_6 -> V_483 -> V_484 == V_485 )
F_184 ( V_6 , V_26 ) ;
V_174 = F_73 ( T_30 , V_486 ) +
sizeof( T_31 ) ;
V_481 = F_51 ( V_174 , V_117 ) ;
if ( ! V_481 ) {
F_13 ( V_33 L_2 ,
V_6 -> V_34 , __FILE__ , __LINE__ , V_35 ) ;
return;
}
V_481 -> V_253 = V_487 ;
V_481 -> V_488 =
F_101 ( V_489 ) ;
V_481 -> V_223 = V_174 / 4 ;
V_481 -> V_490 =
F_101 ( sizeof( T_31 ) / 4 ) ;
V_286 = ( T_31 * )
V_481 -> V_486 ;
V_286 -> V_345 = V_491 ;
V_286 -> V_492 = 0x5D ;
V_286 -> V_181 = F_101 ( V_26 ) ;
V_286 -> V_10 = F_186 ( V_105 -> V_8 ) ;
F_187 ( V_6 , V_481 ) ;
F_21 ( V_481 ) ;
}
static T_6
F_188 ( struct V_5 * V_6 , T_4 V_87 , T_6 V_217 , T_10 V_218 )
{
T_25 * V_234 ;
T_27 * V_28 ;
struct V_86 * V_89 ;
T_4 V_29 ;
T_10 V_493 ;
T_6 V_425 ;
T_6 V_427 ;
T_10 V_433 ;
struct V_102 * V_103 ;
T_10 V_208 = 0 ;
V_28 = F_87 ( V_6 , V_218 ) ;
V_89 = F_42 ( V_6 , V_87 ) ;
if ( V_89 == NULL )
return 1 ;
V_234 = F_100 ( V_6 , V_87 ) ;
if ( V_28 == NULL ) {
V_89 -> V_273 = V_494 << 16 ;
goto V_74;
}
V_103 = V_89 -> V_42 -> V_107 ;
if ( ! V_103 || ! V_103 -> V_109 ||
V_103 -> V_109 -> V_315 ) {
V_89 -> V_273 = V_274 << 16 ;
goto V_74;
}
V_29 = F_9 ( V_28 -> V_37 ) ;
V_425 = V_28 -> V_426 ;
if ( V_425 & V_458 )
V_208 =
F_59 ( V_28 -> V_467 ) & 0xFF ;
if ( ! V_103 -> V_495 ) {
V_103 -> V_495 ++ ;
if ( ( V_103 -> V_63 & V_397 ) &&
V_208 == V_211 )
V_103 -> V_63 &=
~ V_397 ;
}
V_493 = F_59 ( V_28 -> V_465 ) ;
F_189 ( V_89 , F_173 ( V_89 ) - V_493 ) ;
if ( V_29 & V_496 )
V_433 = F_59 ( V_28 -> V_262 ) ;
else
V_433 = 0 ;
V_29 &= V_38 ;
V_427 = V_28 -> V_428 ;
if ( V_29 == V_439 && V_493 == 0 &&
( V_427 == V_450 ||
V_427 == V_453 ||
V_427 == V_455 ) ) {
V_29 = V_39 ;
}
if ( V_425 & V_462 ) {
struct V_419 V_420 ;
const void * V_497 = F_190 ( V_6 ,
V_87 ) ;
T_10 V_174 = F_191 ( T_10 , V_410 ,
F_59 ( V_28 -> V_466 ) ) ;
memcpy ( V_89 -> V_380 , V_497 , V_174 ) ;
F_177 ( V_89 -> V_380 , & V_420 ) ;
if ( V_420 . V_422 == 0x5D )
F_185 ( V_6 ,
F_9 ( V_28 -> V_181 ) ) ;
F_192 ( V_6 , V_420 . V_421 , V_420 . V_422 , V_420 . V_376 ) ;
}
switch ( V_29 ) {
case V_498 :
case V_499 :
V_89 -> V_273 = V_500 ;
break;
case V_437 :
V_89 -> V_273 = V_274 << 16 ;
break;
case V_445 :
if ( V_103 -> V_294 ) {
V_89 -> V_273 = V_501 << 16 ;
goto V_74;
}
if ( V_433 == 0x31110630 ) {
if ( V_89 -> V_502 > 2 ) {
V_89 -> V_273 = V_274 << 16 ;
F_193 ( V_89 -> V_42 ,
V_503 ) ;
} else {
V_89 -> V_273 = V_504 << 16 ;
V_89 -> V_42 -> V_505 = 1 ;
}
break;
}
V_89 -> V_273 = V_504 << 16 ;
break;
case V_442 :
case V_446 :
V_89 -> V_273 = V_276 << 16 ;
break;
case V_443 :
if ( ( V_493 == 0 ) || ( V_89 -> V_463 > V_493 ) )
V_89 -> V_273 = V_504 << 16 ;
else
V_89 -> V_273 = ( V_494 << 16 ) | V_427 ;
break;
case V_439 :
V_89 -> V_273 = ( V_494 << 16 ) | V_427 ;
if ( ( V_425 & V_462 ) )
break;
if ( V_493 < V_89 -> V_463 ) {
if ( V_427 == V_500 )
V_89 -> V_273 = V_500 ;
else
V_89 -> V_273 = V_504 << 16 ;
} else if ( V_425 & ( V_461 |
V_460 ) )
V_89 -> V_273 = V_504 << 16 ;
else if ( V_425 & V_459 )
V_89 -> V_273 = V_276 << 16 ;
else if ( ! V_493 && V_89 -> V_415 [ 0 ] == V_506 ) {
V_28 -> V_426 = V_462 ;
V_28 -> V_428 = V_384 ;
V_89 -> V_273 = ( V_382 << 24 ) |
V_384 ;
V_89 -> V_380 [ 0 ] = 0x70 ;
V_89 -> V_380 [ 2 ] = V_381 ;
V_89 -> V_380 [ 12 ] = 0x20 ;
V_89 -> V_380 [ 13 ] = 0 ;
}
break;
case V_438 :
F_189 ( V_89 , 0 ) ;
case V_435 :
case V_39 :
V_89 -> V_273 = ( V_494 << 16 ) | V_427 ;
if ( V_208 ==
V_211 ||
( V_425 & ( V_461 |
V_460 ) ) )
V_89 -> V_273 = V_504 << 16 ;
else if ( V_425 & V_459 )
V_89 -> V_273 = V_276 << 16 ;
break;
case V_377 :
case V_379 :
case V_378 :
F_167 ( V_89 , V_29 ) ;
break;
case V_441 :
case V_434 :
case V_507 :
case V_508 :
case V_509 :
case V_510 :
case V_440 :
case V_444 :
default:
V_89 -> V_273 = V_504 << 16 ;
break;
}
#ifdef F_170
if ( V_89 -> V_273 && ( V_6 -> V_7 & V_511 ) )
F_178 ( V_6 , V_89 , V_28 , V_87 ) ;
#endif
V_74:
F_161 ( V_89 ) ;
V_89 -> V_275 ( V_89 ) ;
return 1 ;
}
static void
F_194 ( struct V_5 * V_6 )
{
T_4 V_174 ;
T_4 V_29 ;
int V_91 ;
T_9 V_28 ;
T_33 * V_512 = NULL ;
T_4 V_513 ;
T_6 V_514 ;
F_99 ( V_6 , F_3 ( V_33
L_132 ,
V_6 -> V_34 , ( unsigned long long ) V_6 -> V_30 . V_8 ) ) ;
V_174 = F_73 ( T_33 , V_515 ) + ( V_6 -> V_30 . V_31
* sizeof( V_516 ) ) ;
V_512 = F_51 ( V_174 , V_117 ) ;
if ( ! V_512 ) {
F_13 ( V_33 L_2 ,
V_6 -> V_34 , __FILE__ , __LINE__ , V_35 ) ;
return;
}
if ( ( F_195 ( V_6 , & V_28 ,
V_512 , V_174 ) ) != 0 )
goto V_74;
V_29 = F_9 ( V_28 . V_37 ) & V_38 ;
if ( V_29 != V_39 )
goto V_74;
for ( V_91 = 0 ; V_91 < V_6 -> V_30 . V_31 ; V_91 ++ ) {
V_514 = V_512 -> V_515 [ V_91 ] . V_517 >> 4 ;
if ( V_91 == 0 )
V_6 -> V_30 . V_26 = F_9 ( V_512 ->
V_515 [ 0 ] . V_518 ) ;
V_6 -> V_30 . V_199 [ V_91 ] . V_26 = V_6 -> V_30 . V_26 ;
V_513 = F_9 ( V_512 -> V_515 [ V_91 ] .
V_308 ) ;
if ( V_513 && V_514 < V_519 )
V_514 = V_519 ;
F_196 ( V_6 , V_6 -> V_30 . V_8 ,
V_513 , V_91 , V_514 ) ;
}
V_74:
F_21 ( V_512 ) ;
}
static void
F_197 ( struct V_5 * V_6 )
{
int V_91 ;
T_9 V_28 ;
T_33 * V_512 = NULL ;
T_34 * V_520 = NULL ;
T_35 V_521 ;
T_8 V_27 ;
T_36 V_522 ;
T_4 V_29 ;
T_4 V_174 ;
T_6 V_523 ;
F_198 ( V_6 , & V_6 -> V_30 . V_31 ) ;
if ( ! V_6 -> V_30 . V_31 ) {
F_13 ( V_33 L_2 ,
V_6 -> V_34 , __FILE__ , __LINE__ , V_35 ) ;
return;
}
V_174 = F_73 ( T_33 , V_515 ) + ( V_6 -> V_30 . V_31 *
sizeof( V_516 ) ) ;
V_512 = F_51 ( V_174 , V_117 ) ;
if ( ! V_512 ) {
F_13 ( V_33 L_2 ,
V_6 -> V_34 , __FILE__ , __LINE__ , V_35 ) ;
return;
}
if ( ( F_195 ( V_6 , & V_28 ,
V_512 , V_174 ) ) ) {
F_13 ( V_33 L_2 ,
V_6 -> V_34 , __FILE__ , __LINE__ , V_35 ) ;
goto V_74;
}
V_29 = F_9 ( V_28 . V_37 ) &
V_38 ;
if ( V_29 != V_39 ) {
F_13 ( V_33 L_2 ,
V_6 -> V_34 , __FILE__ , __LINE__ , V_35 ) ;
goto V_74;
}
V_174 = F_73 ( T_34 , V_515 ) + ( V_6 -> V_30 . V_31 *
sizeof( V_524 ) ) ;
V_520 = F_51 ( V_174 , V_117 ) ;
if ( ! V_520 ) {
F_13 ( V_33 L_2 ,
V_6 -> V_34 , __FILE__ , __LINE__ , V_35 ) ;
goto V_74;
}
if ( ( F_199 ( V_6 , & V_28 ,
V_520 , V_174 ) ) ) {
F_13 ( V_33 L_2 ,
V_6 -> V_34 , __FILE__ , __LINE__ , V_35 ) ;
goto V_74;
}
V_29 = F_9 ( V_28 . V_37 ) &
V_38 ;
if ( V_29 != V_39 ) {
F_13 ( V_33 L_2 ,
V_6 -> V_34 , __FILE__ , __LINE__ , V_35 ) ;
goto V_74;
}
V_6 -> V_525 =
V_520 -> V_526 ;
V_523 =
V_520 -> V_527 ;
if ( V_523 & V_528 )
V_6 -> V_523 = ( V_523 &
V_529 ) * 16 ;
else
V_6 -> V_523 = V_523 &
V_529 ;
V_6 -> V_30 . V_530 = & V_6 -> V_99 -> V_531 ;
V_6 -> V_30 . V_199 = F_200 ( V_6 -> V_30 . V_31 ,
sizeof( struct V_532 ) , V_117 ) ;
if ( ! V_6 -> V_30 . V_199 ) {
F_13 ( V_33 L_2 ,
V_6 -> V_34 , __FILE__ , __LINE__ , V_35 ) ;
goto V_74;
}
for ( V_91 = 0 ; V_91 < V_6 -> V_30 . V_31 ; V_91 ++ ) {
if ( ( F_201 ( V_6 , & V_28 , & V_521 ,
V_91 ) ) ) {
F_13 ( V_33 L_2 ,
V_6 -> V_34 , __FILE__ , __LINE__ , V_35 ) ;
goto V_74;
}
V_29 = F_9 ( V_28 . V_37 ) &
V_38 ;
if ( V_29 != V_39 ) {
F_13 ( V_33 L_2 ,
V_6 -> V_34 , __FILE__ , __LINE__ , V_35 ) ;
goto V_74;
}
if ( V_91 == 0 )
V_6 -> V_30 . V_26 = F_9 ( V_512 ->
V_515 [ 0 ] . V_518 ) ;
V_6 -> V_30 . V_199 [ V_91 ] . V_26 = V_6 -> V_30 . V_26 ;
V_6 -> V_30 . V_199 [ V_91 ] . V_533 = V_91 ;
F_202 ( V_6 , & V_6 -> V_30 . V_199 [ V_91 ] ,
V_521 , V_6 -> V_30 . V_530 ) ;
}
if ( ( F_12 ( V_6 , & V_28 , & V_27 ,
V_32 , V_6 -> V_30 . V_26 ) ) ) {
F_13 ( V_33 L_2 ,
V_6 -> V_34 , __FILE__ , __LINE__ , V_35 ) ;
goto V_74;
}
V_6 -> V_30 . V_477 =
F_9 ( V_27 . V_476 ) ;
V_6 -> V_30 . V_8 = F_6 ( V_27 . V_10 ) ;
F_3 ( V_33
L_133 ,
V_6 -> V_34 , V_6 -> V_30 . V_26 ,
( unsigned long long ) V_6 -> V_30 . V_8 ,
V_6 -> V_30 . V_31 ) ;
if ( V_6 -> V_30 . V_477 ) {
if ( ! ( F_203 ( V_6 , & V_28 ,
& V_522 , V_534 ,
V_6 -> V_30 . V_477 ) ) )
V_6 -> V_30 . V_13 =
F_6 ( V_522 . V_15 ) ;
}
V_74:
F_21 ( V_520 ) ;
F_21 ( V_512 ) ;
}
static int
F_204 ( struct V_5 * V_6 , T_4 V_26 )
{
struct V_77 * V_78 ;
T_9 V_28 ;
T_37 V_535 ;
T_38 V_536 ;
T_36 V_522 ;
T_10 V_29 ;
T_4 V_537 ;
T_1 V_8 , V_68 = 0 ;
int V_91 ;
unsigned long V_63 ;
struct V_296 * V_297 = NULL ;
int V_19 = 0 ;
if ( ! V_26 )
return - 1 ;
if ( V_6 -> V_66 || V_6 -> V_243 )
return - 1 ;
if ( ( F_205 ( V_6 , & V_28 , & V_535 ,
V_538 , V_26 ) ) ) {
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
V_537 = F_9 ( V_535 . V_539 ) ;
if ( F_11 ( V_6 , V_537 , & V_68 )
!= 0 ) {
F_13 ( V_33 L_2 ,
V_6 -> V_34 , __FILE__ , __LINE__ , V_35 ) ;
return - 1 ;
}
if ( V_68 != V_6 -> V_30 . V_8 ) {
F_19 ( & V_6 -> V_79 , V_63 ) ;
V_78 = F_38 ( V_6 ,
V_68 ) ;
F_22 ( & V_6 -> V_79 , V_63 ) ;
if ( ! V_78 ) {
V_19 = F_204 ( V_6 , V_537 ) ;
if ( V_19 != 0 )
return V_19 ;
}
}
F_19 ( & V_6 -> V_79 , V_63 ) ;
V_8 = F_6 ( V_535 . V_10 ) ;
V_78 = F_38 ( V_6 ,
V_8 ) ;
F_22 ( & V_6 -> V_79 , V_63 ) ;
if ( V_78 )
return 0 ;
V_78 = F_51 ( sizeof( struct V_77 ) ,
V_117 ) ;
if ( ! V_78 ) {
F_13 ( V_33 L_2 ,
V_6 -> V_34 , __FILE__ , __LINE__ , V_35 ) ;
return - 1 ;
}
V_78 -> V_26 = V_26 ;
V_78 -> V_31 = V_535 . V_540 ;
V_78 -> V_68 = V_68 ;
V_78 -> V_8 = V_8 ;
F_3 ( V_33 L_134 \
L_135 , V_6 -> V_34 ,
V_26 , V_537 , ( unsigned long long )
V_78 -> V_8 , V_78 -> V_31 ) ;
if ( ! V_78 -> V_31 )
goto V_541;
V_78 -> V_199 = F_200 ( V_78 -> V_31 ,
sizeof( struct V_532 ) , V_117 ) ;
if ( ! V_78 -> V_199 ) {
F_13 ( V_33 L_2 ,
V_6 -> V_34 , __FILE__ , __LINE__ , V_35 ) ;
V_19 = - 1 ;
goto V_541;
}
F_118 ( & V_78 -> V_542 ) ;
V_297 = F_29 ( V_6 , V_26 ,
V_68 ) ;
if ( ! V_297 ) {
F_13 ( V_33 L_2 ,
V_6 -> V_34 , __FILE__ , __LINE__ , V_35 ) ;
V_19 = - 1 ;
goto V_541;
}
V_78 -> V_530 = & V_297 -> V_116 -> V_114 ;
for ( V_91 = 0 ; V_91 < V_78 -> V_31 ; V_91 ++ ) {
if ( ( F_206 ( V_6 , & V_28 ,
& V_536 , V_91 , V_26 ) ) ) {
F_13 ( V_33 L_2 ,
V_6 -> V_34 , __FILE__ , __LINE__ , V_35 ) ;
V_19 = - 1 ;
goto V_541;
}
V_78 -> V_199 [ V_91 ] . V_26 = V_26 ;
V_78 -> V_199 [ V_91 ] . V_533 = V_91 ;
if ( ( F_207 ( V_6 ,
& V_78 -> V_199 [ V_91 ] , V_536 ,
V_78 -> V_530 ) ) ) {
F_13 ( V_33 L_2 ,
V_6 -> V_34 , __FILE__ , __LINE__ , V_35 ) ;
V_19 = - 1 ;
goto V_541;
}
}
if ( V_78 -> V_477 ) {
if ( ! ( F_203 ( V_6 , & V_28 ,
& V_522 , V_534 ,
V_78 -> V_477 ) ) )
V_78 -> V_13 =
F_6 ( V_522 . V_15 ) ;
}
F_39 ( V_6 , V_78 ) ;
return 0 ;
V_541:
if ( V_297 )
F_30 ( V_6 , V_78 -> V_8 ,
V_68 ) ;
F_21 ( V_78 ) ;
return V_19 ;
}
void
F_208 ( struct V_5 * V_6 , T_1 V_8 )
{
struct V_77 * V_78 ;
unsigned long V_63 ;
if ( V_6 -> V_66 )
return;
F_19 ( & V_6 -> V_79 , V_63 ) ;
V_78 = F_38 ( V_6 ,
V_8 ) ;
if ( V_78 )
F_20 ( & V_78 -> V_65 ) ;
F_22 ( & V_6 -> V_79 , V_63 ) ;
if ( V_78 )
F_209 ( V_6 , V_78 ) ;
}
static T_6
F_210 ( struct V_5 * V_6 , T_4 V_87 , T_6 V_217 , T_10 V_218 )
{
T_15 * V_28 ;
V_28 = F_87 ( V_6 , V_218 ) ;
if ( V_6 -> V_543 . V_220 == V_221 )
return 1 ;
if ( V_6 -> V_543 . V_87 != V_87 )
return 1 ;
V_6 -> V_543 . V_220 |= V_222 ;
if ( V_28 ) {
memcpy ( V_6 -> V_543 . V_218 , V_28 ,
V_28 -> V_223 * 4 ) ;
V_6 -> V_543 . V_220 |= V_224 ;
}
V_6 -> V_543 . V_220 &= ~ V_225 ;
F_88 ( & V_6 -> V_543 . V_226 ) ;
return 1 ;
}
static T_6
F_211 ( struct V_5 * V_6 , T_1 V_8 ,
T_4 V_26 , T_6 V_544 )
{
T_6 V_19 = 1 ;
char * V_209 = NULL ;
switch ( V_544 ) {
case V_545 :
case V_546 :
V_19 = 0 ;
break;
case V_547 :
V_209 = L_136 ;
break;
case V_548 :
V_209 = L_137 ;
break;
case V_549 :
V_209 = L_138 ;
break;
case V_550 :
V_209 = L_139 ;
break;
case V_551 :
V_209 = L_140 ;
break;
case V_552 :
case V_553 :
case V_554 :
case V_555 :
case V_556 :
case V_557 :
case V_558 :
case V_559 :
case V_560 :
case V_561 :
case V_562 :
case V_563 :
V_209 = L_141 ;
break;
default:
V_209 = L_38 ;
break;
}
if ( ! V_19 )
return 0 ;
F_13 ( V_33
L_142 ,
V_6 -> V_34 , V_209 , ( unsigned long long ) V_8 , V_26 ) ;
return V_19 ;
}
static void
F_212 ( struct V_5 * V_6 ,
T_1 V_564 , T_4 V_26 , T_6 V_565 , T_6 V_514 )
{
T_9 V_28 ;
T_8 V_27 ;
struct V_44 * V_45 ;
T_10 V_29 ;
unsigned long V_63 ;
T_1 V_8 ;
struct V_113 * V_69 ;
struct V_104 * V_105 ;
T_10 V_81 ;
if ( ( F_12 ( V_6 , & V_28 , & V_27 ,
V_32 , V_26 ) ) )
return;
V_29 = F_9 ( V_28 . V_37 ) & V_38 ;
if ( V_29 != V_39 )
return;
if ( V_565 != V_27 . V_566 )
return;
V_81 = F_59 ( V_27 . V_132 ) ;
if ( ! ( F_40 ( V_81 ) ) )
return;
F_19 ( & V_6 -> V_64 , V_63 ) ;
V_8 = F_6 ( V_27 . V_10 ) ;
V_45 = F_16 ( V_6 ,
V_8 ) ;
if ( ! V_45 ) {
F_22 ( & V_6 -> V_64 , V_63 ) ;
return;
}
if ( F_141 ( V_45 -> V_26 != V_26 ) ) {
V_69 = V_45 -> V_69 ;
V_105 = V_69 -> V_107 ;
F_111 ( V_130 , V_69 ,
L_143 ,
V_45 -> V_26 , V_26 ) ;
V_105 -> V_26 = V_26 ;
V_45 -> V_26 = V_26 ;
}
if ( ! ( F_9 ( V_27 . V_131 ) &
V_567 ) ) {
F_13 ( V_33
L_144 ,
V_6 -> V_34 , V_26 ) ;
F_22 ( & V_6 -> V_64 , V_63 ) ;
return;
}
if ( F_211 ( V_6 , V_8 , V_26 ,
V_27 . V_568 ) ) {
F_22 ( & V_6 -> V_64 , V_63 ) ;
return;
}
F_22 ( & V_6 -> V_64 , V_63 ) ;
F_132 ( V_6 , V_8 ) ;
}
static int
F_213 ( struct V_5 * V_6 , T_4 V_26 , T_6 V_569 ,
T_6 V_570 )
{
T_9 V_28 ;
T_8 V_27 ;
T_36 V_522 ;
struct V_44 * V_45 ;
T_10 V_29 ;
T_1 V_8 ;
T_10 V_81 ;
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
V_81 = F_59 ( V_27 . V_132 ) ;
if ( ! ( F_40 ( V_81 ) ) )
return - 1 ;
V_8 = F_6 ( V_27 . V_10 ) ;
if ( ! ( F_9 ( V_27 . V_131 ) &
V_567 ) ) {
F_13 ( V_33 L_145 ,
V_6 -> V_34 , V_26 ) ;
return - 1 ;
}
if ( F_211 ( V_6 , V_8 , V_26 ,
V_27 . V_568 ) )
return - 1 ;
F_19 ( & V_6 -> V_64 , V_63 ) ;
V_45 = F_16 ( V_6 ,
V_8 ) ;
F_22 ( & V_6 -> V_64 , V_63 ) ;
if ( V_45 )
return - 1 ;
V_45 = F_51 ( sizeof( struct V_44 ) ,
V_117 ) ;
if ( ! V_45 ) {
F_13 ( V_33 L_2 ,
V_6 -> V_34 , __FILE__ , __LINE__ , V_35 ) ;
return 0 ;
}
V_45 -> V_26 = V_26 ;
if ( F_11 ( V_6 ,
F_9 ( V_27 . V_539 ) ,
& V_45 -> V_68 ) != 0 )
F_13 ( V_33 L_2 ,
V_6 -> V_34 , __FILE__ , __LINE__ , V_35 ) ;
V_45 -> V_477 =
F_9 ( V_27 . V_476 ) ;
V_45 -> V_17 =
F_9 ( V_27 . V_475 ) ;
V_45 -> V_81 = V_81 ;
V_45 -> V_8 = V_8 ;
V_45 -> V_199 = V_27 . V_566 ;
V_45 -> V_125 = ( F_9 ( V_27 . V_131 ) &
V_571 ) ? 1 : 0 ;
if ( V_45 -> V_477 && ! ( F_203 (
V_6 , & V_28 , & V_522 , V_534 ,
V_45 -> V_477 ) ) )
V_45 -> V_13 =
F_6 ( V_522 . V_15 ) ;
V_45 -> V_11 = F_6 ( V_27 . V_12 ) ;
if ( V_6 -> V_572 )
F_31 ( V_6 , V_45 ) ;
else
F_26 ( V_6 , V_45 ) ;
return 0 ;
}
static void
F_24 ( struct V_5 * V_6 ,
struct V_44 * V_45 )
{
struct V_104 * V_105 ;
if ( ( V_6 -> V_483 -> V_484 == V_485 ) &&
( V_45 -> V_474 ) ) {
F_182 ( V_6 , V_45 ) ;
V_45 -> V_474 = 0 ;
}
F_27 ( V_6 , F_3 ( V_33
L_146 ,
V_6 -> V_34 , V_35 ,
V_45 -> V_26 , ( unsigned long long )
V_45 -> V_8 ) ) ;
if ( V_45 -> V_69 && V_45 -> V_69 -> V_107 ) {
V_105 = V_45 -> V_69 -> V_107 ;
V_105 -> V_315 = 1 ;
F_132 ( V_6 , V_45 -> V_8 ) ;
V_105 -> V_26 =
V_119 ;
}
F_30 ( V_6 ,
V_45 -> V_8 ,
V_45 -> V_68 ) ;
F_3 ( V_33
L_147 ,
V_6 -> V_34 , V_45 -> V_26 ,
( unsigned long long ) V_45 -> V_8 ) ;
F_27 ( V_6 , F_3 ( V_33
L_148 ,
V_6 -> V_34 , V_35 ,
V_45 -> V_26 , ( unsigned long long )
V_45 -> V_8 ) ) ;
F_21 ( V_45 ) ;
}
static void
F_214 ( struct V_5 * V_6 ,
T_19 * V_286 )
{
int V_91 ;
T_4 V_26 ;
T_4 V_305 ;
T_6 V_565 ;
char * V_573 = NULL ;
T_6 V_514 , V_574 ;
switch ( V_286 -> V_331 ) {
case V_338 :
V_573 = L_149 ;
break;
case V_335 :
V_573 = L_150 ;
break;
case V_334 :
case 0 :
V_573 = L_151 ;
break;
case V_332 :
V_573 = L_152 ;
break;
default:
V_573 = L_153 ;
break;
}
F_3 ( V_33 L_154 ,
V_6 -> V_34 , V_573 ) ;
F_3 ( L_155 \
L_156 ,
F_9 ( V_286 -> V_330 ) ,
F_9 ( V_286 -> V_476 ) ,
V_286 -> V_575 , V_286 -> V_306 ) ;
for ( V_91 = 0 ; V_91 < V_286 -> V_306 ; V_91 ++ ) {
V_26 = F_9 ( V_286 -> V_307 [ V_91 ] . V_308 ) ;
if ( ! V_26 )
continue;
V_565 = V_286 -> V_575 + V_91 ;
V_305 = V_286 -> V_307 [ V_91 ] . V_309 &
V_310 ;
switch ( V_305 ) {
case V_576 :
V_573 = L_157 ;
break;
case V_329 :
V_573 = L_158 ;
break;
case V_311 :
V_573 = L_159 ;
break;
case V_577 :
V_573 = L_160 ;
break;
case V_578 :
V_573 = L_161 ;
break;
default:
V_573 = L_38 ;
break;
}
V_514 = V_286 -> V_307 [ V_91 ] . V_579 >> 4 ;
V_574 = V_286 -> V_307 [ V_91 ] . V_579 & 0xF ;
F_3 ( L_162 \
L_163 , V_565 ,
V_26 , V_573 , V_514 , V_574 ) ;
}
}
static int
F_215 ( struct V_5 * V_6 ,
struct V_278 * V_279 )
{
int V_91 ;
T_4 V_537 , V_26 ;
T_4 V_305 ;
T_6 V_565 , V_580 ;
struct V_77 * V_78 ;
T_1 V_8 ;
unsigned long V_63 ;
T_6 V_514 , V_574 ;
T_19 * V_286 =
( T_19 * )
V_279 -> V_286 ;
#ifdef F_170
if ( V_6 -> V_7 & V_581 )
F_214 ( V_6 , V_286 ) ;
#endif
if ( V_6 -> V_66 || V_6 -> V_242 || V_6 -> V_243 )
return 0 ;
if ( ! V_6 -> V_30 . V_31 )
F_197 ( V_6 ) ;
else
F_194 ( V_6 ) ;
if ( V_279 -> V_337 ) {
F_27 ( V_6 , F_3 ( V_33
L_164 , V_6 -> V_34 ) ) ;
return 0 ;
}
V_537 = F_9 ( V_286 -> V_330 ) ;
if ( V_286 -> V_331 == V_338 )
if ( F_204 ( V_6 , V_537 ) != 0 )
return 0 ;
F_19 ( & V_6 -> V_79 , V_63 ) ;
V_78 = F_37 ( V_6 ,
V_537 ) ;
if ( V_78 ) {
V_8 = V_78 -> V_8 ;
V_580 = V_78 -> V_31 ;
} else if ( V_537 < V_6 -> V_30 . V_31 ) {
V_8 = V_6 -> V_30 . V_8 ;
V_580 = V_6 -> V_30 . V_31 ;
} else {
F_22 ( & V_6 -> V_79 , V_63 ) ;
return 0 ;
}
F_22 ( & V_6 -> V_79 , V_63 ) ;
for ( V_91 = 0 ; V_91 < V_286 -> V_306 ; V_91 ++ ) {
if ( V_279 -> V_337 ) {
F_27 ( V_6 , F_3 ( V_33
L_164 , V_6 -> V_34 ) ) ;
return 0 ;
}
if ( V_6 -> V_242 || V_6 -> V_243 )
return 0 ;
V_565 = V_286 -> V_575 + V_91 ;
if ( V_565 >= V_580 )
continue;
V_305 = V_286 -> V_307 [ V_91 ] . V_309 &
V_310 ;
if ( ( V_286 -> V_307 [ V_91 ] . V_309 &
V_582 ) && ( V_305 !=
V_329 ) )
continue;
V_26 = F_9 ( V_286 -> V_307 [ V_91 ] . V_308 ) ;
if ( ! V_26 )
continue;
V_514 = V_286 -> V_307 [ V_91 ] . V_579 >> 4 ;
V_574 = V_286 -> V_307 [ V_91 ] . V_579 & 0xF ;
switch ( V_305 ) {
case V_577 :
if ( V_6 -> V_66 )
break;
if ( V_514 == V_574 )
break;
F_196 ( V_6 , V_8 ,
V_26 , V_565 , V_514 ) ;
if ( V_514 < V_519 )
break;
F_212 ( V_6 , V_8 , V_26 ,
V_565 , V_514 ) ;
case V_576 :
if ( V_6 -> V_66 )
break;
F_196 ( V_6 , V_8 ,
V_26 , V_565 , V_514 ) ;
F_213 ( V_6 , V_26 , V_565 , 0 ) ;
break;
case V_329 :
F_23 ( V_6 , V_26 ) ;
break;
}
}
if ( V_286 -> V_331 == V_335 &&
V_78 )
F_208 ( V_6 , V_8 ) ;
return 0 ;
}
static void
F_216 ( struct V_5 * V_6 ,
T_31 * V_286 )
{
char * V_583 = NULL ;
switch ( V_286 -> V_345 ) {
case V_491 :
V_583 = L_165 ;
break;
case V_584 :
V_583 = L_166 ;
break;
case V_585 :
V_583 = L_167 ;
break;
case V_586 :
V_583 = L_168 ;
break;
case V_587 :
V_583 = L_169 ;
break;
case V_588 :
V_583 = L_170 ;
break;
case V_589 :
V_583 = L_171 ;
break;
case V_590 :
V_583 = L_172 ;
break;
case V_591 :
V_583 = L_173 ;
break;
case V_592 :
V_583 = L_174 ;
break;
case V_593 :
V_583 = L_175 ;
break;
case V_594 :
V_583 = L_176 ;
break;
case V_595 :
V_583 = L_177 ;
break;
default:
V_583 = L_178 ;
break;
}
F_3 ( V_33 L_179
L_180 ,
V_6 -> V_34 , V_583 , F_9 ( V_286 -> V_181 ) ,
( unsigned long long ) F_6 ( V_286 -> V_10 ) ,
F_9 ( V_286 -> V_464 ) ) ;
if ( V_286 -> V_345 == V_491 )
F_3 ( V_33 L_181 , V_6 -> V_34 ,
V_286 -> V_492 , V_286 -> V_596 ) ;
F_3 ( L_182 ) ;
}
static void
F_217 ( struct V_5 * V_6 ,
struct V_278 * V_279 )
{
struct V_104 * V_597 ;
struct V_44 * V_45 ;
T_1 V_8 ;
unsigned long V_63 ;
T_31 * V_286 =
( T_31 * )
V_279 -> V_286 ;
#ifdef F_170
if ( V_6 -> V_7 & V_581 )
F_216 ( V_6 ,
V_286 ) ;
#endif
if ( ( V_6 -> V_183 . V_598 >> 8 ) < 0xC )
return;
if ( V_286 -> V_345 !=
V_585 &&
V_286 -> V_345 !=
V_591 )
return;
F_19 ( & V_6 -> V_64 , V_63 ) ;
V_8 = F_6 ( V_286 -> V_10 ) ;
V_45 = F_16 ( V_6 ,
V_8 ) ;
if ( ! V_45 || ! V_45 -> V_69 ) {
F_22 ( & V_6 -> V_64 , V_63 ) ;
return;
}
V_597 = V_45 -> V_69 -> V_107 ;
if ( ! V_597 ) {
F_22 ( & V_6 -> V_64 , V_63 ) ;
return;
}
if ( V_286 -> V_345 ==
V_585 )
V_597 -> V_228 = 1 ;
else
V_597 -> V_228 = 0 ;
F_22 ( & V_6 -> V_64 , V_63 ) ;
}
static void
F_218 ( struct V_5 * V_6 ,
T_39 * V_286 )
{
char * V_583 = NULL ;
switch ( V_286 -> V_345 ) {
case V_599 :
V_583 = L_183 ;
break;
case V_600 :
V_583 = L_184 ;
break;
default:
V_583 = L_178 ;
break;
}
F_3 ( V_33 L_185
L_186
L_187 , V_6 -> V_34 , V_583 ,
F_9 ( V_286 -> V_476 ) ,
( unsigned long long ) F_6 ( V_286 -> V_15 ) ,
F_9 ( V_286 -> V_601 ) ) ;
}
static void
F_219 ( struct V_5 * V_6 ,
struct V_278 * V_279 )
{
#ifdef F_170
if ( V_6 -> V_7 & V_581 )
F_218 ( V_6 ,
( T_39 * )
V_279 -> V_286 ) ;
#endif
}
static void
F_220 ( struct V_5 * V_6 ,
struct V_278 * V_279 )
{
struct V_86 * V_89 ;
struct V_95 * V_96 ;
T_4 V_87 , V_26 ;
T_10 V_94 ;
struct V_102 * V_103 ;
T_10 V_602 ;
T_10 V_603 ;
T_18 * V_28 ;
T_40 * V_286 =
( T_40 * )
V_279 -> V_286 ;
T_4 V_29 ;
unsigned long V_63 ;
int V_73 ;
T_6 V_604 = 0 ;
T_6 V_605 ;
F_93 ( & V_6 -> V_219 . V_239 ) ;
F_3 ( V_33
L_188 ,
V_6 -> V_34 , V_35 , V_286 -> V_566 ,
V_286 -> V_606 ) ;
F_133 ( V_6 ) ;
F_19 ( & V_6 -> V_90 , V_63 ) ;
V_28 = V_6 -> V_219 . V_218 ;
V_607:
if ( V_604 ++ == 5 ) {
F_27 ( V_6 , F_3 ( V_33 L_189 ,
V_6 -> V_34 , V_35 ) ) ;
goto V_74;
} else if ( V_604 > 1 )
F_27 ( V_6 , F_3 ( V_33 L_190 ,
V_6 -> V_34 , V_35 , V_604 - 1 ) ) ;
V_602 = 0 ;
V_603 = 0 ;
for ( V_87 = 1 ; V_87 <= V_6 -> V_92 ; V_87 ++ ) {
if ( V_6 -> V_66 )
goto V_74;
V_89 = F_41 ( V_6 , V_87 ) ;
if ( ! V_89 )
continue;
V_96 = V_89 -> V_42 ;
V_103 = V_96 -> V_107 ;
if ( ! V_103 || ! V_103 -> V_109 )
continue;
if ( V_103 -> V_109 -> V_63 &
V_124 )
continue;
if ( V_103 -> V_109 -> V_63 &
V_110 )
continue;
V_26 = V_103 -> V_109 -> V_26 ;
V_94 = V_103 -> V_94 ;
V_603 ++ ;
if ( V_6 -> V_66 )
goto V_74;
F_22 ( & V_6 -> V_90 , V_63 ) ;
V_73 = F_92 ( V_6 , V_26 , 0 , 0 , V_94 ,
V_269 , V_87 , 30 ,
V_608 ) ;
if ( V_73 == V_240 ) {
F_56 ( V_482 , V_96 ,
L_191
L_192 , V_89 ) ;
F_19 ( & V_6 -> V_90 , V_63 ) ;
goto V_607;
}
V_29 = F_9 ( V_28 -> V_37 )
& V_38 ;
if ( V_29 != V_39 ) {
F_56 ( V_482 , V_96 ,
L_193 ,
V_29 , V_89 ) ;
F_19 ( & V_6 -> V_90 , V_63 ) ;
goto V_607;
}
if ( V_28 -> V_265 ==
V_214 ||
V_28 -> V_265 ==
V_216 ) {
F_19 ( & V_6 -> V_90 , V_63 ) ;
continue;
}
V_605 = 0 ;
V_609:
if ( V_605 ++ == 60 ) {
F_27 ( V_6 , F_3 ( V_33
L_194 , V_6 -> V_34 ,
V_35 ) ) ;
F_19 ( & V_6 -> V_90 , V_63 ) ;
goto V_607;
}
if ( V_6 -> V_66 )
goto V_610;
V_73 = F_92 ( V_6 , V_26 , V_96 -> V_72 , V_96 -> V_71 ,
V_96 -> V_94 , V_252 , V_87 , 30 ,
V_608 ) ;
if ( V_73 == V_240 ) {
F_56 ( V_482 , V_96 ,
L_195
L_196 , V_89 ) ;
goto V_609;
}
if ( V_605 > 1 )
F_56 ( V_482 , V_96 ,
L_197
L_198 ,
V_605 - 1 , V_89 ) ;
V_602 += F_59 ( V_28 -> V_263 ) ;
F_19 ( & V_6 -> V_90 , V_63 ) ;
}
if ( V_6 -> V_611 ) {
F_27 ( V_6 , F_3 ( V_33
L_199 ,
V_6 -> V_34 , V_35 ) ) ;
V_6 -> V_611 = 0 ;
goto V_607;
}
V_74:
F_22 ( & V_6 -> V_90 , V_63 ) ;
V_610:
F_27 ( V_6 , F_3 ( V_33
L_200 ,
V_6 -> V_34 , V_35 , V_603 , V_602 ) ) ;
V_6 -> V_612 = 0 ;
if ( ! V_6 -> V_66 )
F_130 ( V_6 ) ;
F_108 ( & V_6 -> V_219 . V_239 ) ;
}
static void
F_221 ( struct V_5 * V_6 ,
struct V_278 * V_279 )
{
T_41 * V_286 =
( T_41 * ) V_279 -> V_286 ;
#ifdef F_170
if ( V_6 -> V_7 & V_581 ) {
F_3 ( V_33 L_201 , V_6 -> V_34 ,
( V_286 -> V_345 == V_613 ) ?
L_202 : L_203 ) ;
if ( V_286 -> V_614 )
F_3 ( L_204 ,
F_59 ( V_286 -> V_614 ) ) ;
F_3 ( L_182 ) ;
}
#endif
if ( V_286 -> V_345 == V_613 &&
! V_6 -> V_30 . V_31 ) {
if ( V_615 > 0 && V_6 -> V_66 ) {
while ( V_6 -> V_66 )
F_222 ( 1 ) ;
}
F_197 ( V_6 ) ;
}
}
static int
F_223 ( struct V_5 * V_6 , T_4 V_26 , T_6 V_616 )
{
T_42 * V_234 ;
T_43 * V_28 ;
T_4 V_87 ;
T_6 V_617 = 0 ;
int V_19 = 0 ;
T_4 V_29 ;
T_10 V_433 ;
F_93 ( & V_6 -> V_543 . V_239 ) ;
if ( V_6 -> V_543 . V_220 != V_221 ) {
F_13 ( V_33 L_205 ,
V_6 -> V_34 , V_35 ) ;
V_19 = - V_618 ;
goto V_74;
}
V_6 -> V_543 . V_220 = V_225 ;
V_87 = F_142 ( V_6 , V_6 -> V_619 ) ;
if ( ! V_87 ) {
F_13 ( V_33 L_43 ,
V_6 -> V_34 , V_35 ) ;
V_6 -> V_543 . V_220 = V_221 ;
V_19 = - V_618 ;
goto V_74;
}
V_234 = F_100 ( V_6 , V_87 ) ;
V_6 -> V_543 . V_87 = V_87 ;
memset ( V_234 , 0 , sizeof( T_42 ) ) ;
V_234 -> V_253 = V_620 ;
V_234 -> V_469 = V_621 ;
V_234 -> V_180 = V_616 ;
F_27 ( V_6 , F_3 ( V_33 L_206\
L_207 , V_6 -> V_34 ,
V_26 , V_616 ) ) ;
F_103 ( & V_6 -> V_543 . V_226 ) ;
F_143 ( V_6 , V_87 ) ;
F_105 ( & V_6 -> V_543 . V_226 , 10 * V_259 ) ;
if ( ! ( V_6 -> V_543 . V_220 & V_222 ) ) {
F_13 ( V_33 L_45 ,
V_6 -> V_34 , V_35 ) ;
if ( ! ( V_6 -> V_543 . V_220 & V_260 ) )
V_617 = 1 ;
V_19 = - V_622 ;
goto V_74;
}
if ( V_6 -> V_543 . V_220 & V_224 ) {
V_28 = V_6 -> V_543 . V_218 ;
V_29 = F_9 ( V_28 -> V_37 ) ;
if ( V_29 & V_496 )
V_433 = F_59 ( V_28 -> V_262 ) ;
else
V_433 = 0 ;
V_29 &= V_38 ;
if ( V_29 != V_39 ) {
F_27 ( V_6 , F_3 ( V_33
L_208
L_209 , V_6 -> V_34 , V_29 ,
V_433 ) ) ;
V_19 = - V_622 ;
} else
F_27 ( V_6 , F_3 ( V_33
L_210 ,
V_6 -> V_34 ) ) ;
}
V_74:
V_6 -> V_543 . V_220 = V_221 ;
F_108 ( & V_6 -> V_543 . V_239 ) ;
if ( V_617 )
F_96 ( V_6 , V_245 ,
V_246 ) ;
return V_19 ;
}
static void
F_224 ( struct V_95 * V_96 , void * V_129 )
{
int V_19 ;
V_96 -> V_129 = V_129 ? 1 : 0 ;
F_56 ( V_130 , V_96 , L_211 ,
V_96 -> V_129 ? L_212 : L_213 ) ;
V_19 = F_225 ( V_96 ) ;
}
static void
F_226 ( struct V_5 * V_6 ,
T_23 * V_341 )
{
struct V_46 * V_47 ;
unsigned long V_63 ;
T_1 V_51 ;
T_4 V_26 = F_9 ( V_341 -> V_348 ) ;
int V_19 ;
F_80 ( V_6 , V_26 , & V_51 ) ;
if ( ! V_51 ) {
F_13 ( V_33
L_2 , V_6 -> V_34 ,
__FILE__ , __LINE__ , V_35 ) ;
return;
}
F_19 ( & V_6 -> V_75 , V_63 ) ;
V_47 = F_34 ( V_6 , V_51 ) ;
F_22 ( & V_6 -> V_75 , V_63 ) ;
if ( V_47 )
return;
V_47 = F_51 ( sizeof( struct V_46 ) , V_117 ) ;
if ( ! V_47 ) {
F_13 ( V_33
L_2 , V_6 -> V_34 ,
__FILE__ , __LINE__ , V_35 ) ;
return;
}
V_47 -> V_71 = V_6 -> V_623 ++ ;
V_47 -> V_72 = V_120 ;
V_47 -> V_26 = V_26 ;
V_47 -> V_51 = V_51 ;
F_35 ( V_6 , V_47 ) ;
if ( ! V_6 -> V_572 ) {
V_19 = F_227 ( V_6 -> V_99 , V_120 ,
V_47 -> V_71 , 0 ) ;
if ( V_19 )
F_36 ( V_6 , V_47 ) ;
} else {
F_19 ( & V_6 -> V_75 , V_63 ) ;
F_14 ( V_6 , V_47 , 1 ) ;
F_22 ( & V_6 -> V_75 , V_63 ) ;
}
}
static void
F_228 ( struct V_5 * V_6 , T_4 V_26 )
{
struct V_46 * V_47 ;
unsigned long V_63 ;
struct V_104 * V_105 ;
struct V_113 * V_69 = NULL ;
F_19 ( & V_6 -> V_75 , V_63 ) ;
V_47 = F_33 ( V_6 , V_26 ) ;
if ( V_47 ) {
if ( V_47 -> V_69 ) {
V_69 = V_47 -> V_69 ;
V_105 = V_69 -> V_107 ;
V_105 -> V_315 = 1 ;
}
F_3 ( V_33 L_214 ,
V_6 -> V_34 , V_47 -> V_26 ,
( unsigned long long ) V_47 -> V_51 ) ;
F_20 ( & V_47 -> V_65 ) ;
F_21 ( V_47 ) ;
}
F_22 ( & V_6 -> V_75 , V_63 ) ;
if ( V_69 )
F_229 ( & V_69 -> V_114 ) ;
}
static void
F_230 ( struct V_5 * V_6 ,
T_23 * V_341 )
{
struct V_44 * V_45 ;
struct V_113 * V_69 = NULL ;
struct V_104 * V_105 ;
unsigned long V_63 ;
T_4 V_26 = F_9 ( V_341 -> V_350 ) ;
F_19 ( & V_6 -> V_64 , V_63 ) ;
V_45 = F_17 ( V_6 , V_26 ) ;
if ( V_45 ) {
V_45 -> V_189 = 0 ;
V_45 -> V_190 = 0 ;
F_157 ( V_26 , V_6 -> V_123 ) ;
if ( V_45 -> V_69 && V_45 -> V_69 -> V_107 ) {
V_69 = V_45 -> V_69 ;
V_105 = V_69 -> V_107 ;
V_105 -> V_63 &=
~ V_124 ;
}
}
F_22 ( & V_6 -> V_64 , V_63 ) ;
if ( ! V_45 )
return;
if ( V_69 )
F_231 ( V_69 , NULL , F_224 ) ;
}
static void
F_232 ( struct V_5 * V_6 ,
T_23 * V_341 )
{
struct V_44 * V_45 ;
struct V_113 * V_69 = NULL ;
struct V_104 * V_105 ;
unsigned long V_63 ;
T_4 V_26 = F_9 ( V_341 -> V_350 ) ;
T_4 V_189 = 0 ;
T_1 V_190 = 0 ;
F_79 ( V_6 , V_26 , & V_189 ) ;
if ( V_189 )
F_80 ( V_6 , V_189 ,
& V_190 ) ;
F_19 ( & V_6 -> V_64 , V_63 ) ;
V_45 = F_17 ( V_6 , V_26 ) ;
if ( V_45 ) {
F_137 ( V_26 , V_6 -> V_123 ) ;
if ( V_45 -> V_69 && V_45 -> V_69 -> V_107 ) {
V_69 = V_45 -> V_69 ;
V_105 = V_69 -> V_107 ;
V_105 -> V_63 |=
V_124 ;
V_45 -> V_189 = V_189 ;
V_45 -> V_190 = V_190 ;
}
}
F_22 ( & V_6 -> V_64 , V_63 ) ;
if ( ! V_45 )
return;
F_223 ( V_6 , V_26 , V_341 -> V_180 ) ;
if ( V_69 )
F_231 ( V_69 , ( void * ) 1 , F_224 ) ;
}
static void
F_233 ( struct V_5 * V_6 ,
T_23 * V_341 )
{
T_4 V_26 = F_9 ( V_341 -> V_350 ) ;
F_23 ( V_6 , V_26 ) ;
}
static void
F_234 ( struct V_5 * V_6 ,
T_23 * V_341 )
{
struct V_44 * V_45 ;
unsigned long V_63 ;
T_4 V_26 = F_9 ( V_341 -> V_350 ) ;
T_9 V_28 ;
T_8 V_27 ;
T_10 V_29 ;
T_1 V_8 ;
T_4 V_537 ;
F_137 ( V_26 , V_6 -> V_123 ) ;
F_19 ( & V_6 -> V_64 , V_63 ) ;
V_45 = F_17 ( V_6 , V_26 ) ;
F_22 ( & V_6 -> V_64 , V_63 ) ;
if ( V_45 ) {
F_223 ( V_6 , V_26 , V_341 -> V_180 ) ;
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
V_537 = F_9 ( V_27 . V_539 ) ;
if ( ! F_11 ( V_6 , V_537 , & V_8 ) )
F_196 ( V_6 , V_8 , V_26 ,
V_27 . V_566 , V_519 ) ;
F_223 ( V_6 , V_26 , V_341 -> V_180 ) ;
F_213 ( V_6 , V_26 , 0 , 1 ) ;
}
static void
F_235 ( struct V_5 * V_6 ,
T_22 * V_286 )
{
T_23 * V_341 ;
T_6 V_624 ;
int V_91 ;
char * V_583 = NULL , * V_625 = NULL ;
V_341 = ( T_23 * ) & V_286 -> V_342 [ 0 ] ;
F_3 ( V_33 L_215 ,
V_6 -> V_34 , ( F_59 ( V_286 -> V_131 ) &
V_344 ) ?
L_216 : L_217 , V_286 -> V_343 ) ;
for ( V_91 = 0 ; V_91 < V_286 -> V_343 ; V_91 ++ , V_341 ++ ) {
switch ( V_341 -> V_345 ) {
case V_626 :
V_583 = L_149 ;
break;
case V_347 :
V_583 = L_150 ;
break;
case V_627 :
V_583 = L_218 ;
break;
case V_628 :
V_583 = L_219 ;
break;
case V_349 :
V_583 = L_220 ;
break;
case V_629 :
V_583 = L_221 ;
break;
case V_346 :
V_583 = L_222 ;
break;
case V_630 :
V_583 = L_223 ;
break;
case V_631 :
V_583 = L_224 ;
break;
default:
V_583 = L_178 ;
break;
}
V_624 = F_9 ( V_341 -> V_632 ) &
V_633 ;
switch ( V_624 ) {
case V_634 :
V_625 = L_48 ;
break;
case V_635 :
V_625 = L_225 ;
break;
case V_636 :
V_625 = L_226 ;
break;
default:
V_625 = L_227 ;
break;
}
F_3 ( L_228 \
L_229 , V_625 ,
V_583 , F_9 ( V_341 -> V_348 ) ,
F_9 ( V_341 -> V_350 ) ,
V_341 -> V_180 ) ;
}
}
static void
F_236 ( struct V_5 * V_6 ,
struct V_278 * V_279 )
{
T_23 * V_341 ;
int V_91 ;
T_6 V_637 ;
T_22 * V_286 =
( T_22 * )
V_279 -> V_286 ;
#ifdef F_170
if ( V_6 -> V_7 & V_581 )
F_235 ( V_6 , V_286 ) ;
#endif
V_637 = ( F_59 ( V_286 -> V_131 ) &
V_344 ) ? 1 : 0 ;
V_341 = ( T_23 * ) & V_286 -> V_342 [ 0 ] ;
if ( V_6 -> V_66 ) {
for ( V_91 = 0 ; V_91 < V_286 -> V_343 ; V_91 ++ , V_341 ++ ) {
if ( V_341 -> V_345 == V_628 )
F_223 ( V_6 ,
F_9 ( V_341 -> V_350 ) ,
V_341 -> V_180 ) ;
}
return;
}
for ( V_91 = 0 ; V_91 < V_286 -> V_343 ; V_91 ++ , V_341 ++ ) {
switch ( V_341 -> V_345 ) {
case V_629 :
case V_626 :
if ( ! V_637 )
F_226 ( V_6 , V_341 ) ;
break;
case V_346 :
case V_347 :
if ( ! V_637 )
F_228 ( V_6 ,
F_9 ( V_341 -> V_348 ) ) ;
break;
case V_630 :
F_232 ( V_6 , V_341 ) ;
break;
case V_631 :
F_230 ( V_6 , V_341 ) ;
break;
case V_628 :
F_234 ( V_6 , V_341 ) ;
break;
case V_349 :
F_233 ( V_6 , V_341 ) ;
break;
}
}
}
static void
F_237 ( struct V_5 * V_6 ,
struct V_278 * V_279 )
{
T_1 V_51 ;
unsigned long V_63 ;
struct V_46 * V_47 ;
T_4 V_26 ;
T_10 V_148 ;
int V_19 ;
T_24 * V_286 =
( T_24 * ) V_279 -> V_286 ;
if ( V_6 -> V_66 )
return;
if ( V_286 -> V_345 != V_351 )
return;
V_26 = F_9 ( V_286 -> V_348 ) ;
V_148 = F_59 ( V_286 -> V_352 ) ;
F_27 ( V_6 , F_3 ( V_33
L_230 ,
V_6 -> V_34 , V_35 , V_26 ,
F_59 ( V_286 -> V_638 ) , V_148 ) ) ;
switch ( V_148 ) {
case V_158 :
case V_157 :
F_228 ( V_6 , V_26 ) ;
break;
case V_153 :
case V_155 :
case V_152 :
F_19 ( & V_6 -> V_75 , V_63 ) ;
V_47 = F_33 ( V_6 , V_26 ) ;
F_22 ( & V_6 -> V_75 , V_63 ) ;
if ( V_47 )
break;
F_80 ( V_6 , V_26 , & V_51 ) ;
if ( ! V_51 ) {
F_13 ( V_33
L_2 , V_6 -> V_34 ,
__FILE__ , __LINE__ , V_35 ) ;
break;
}
V_47 = F_51 ( sizeof( struct V_46 ) , V_117 ) ;
if ( ! V_47 ) {
F_13 ( V_33
L_2 , V_6 -> V_34 ,
__FILE__ , __LINE__ , V_35 ) ;
break;
}
V_47 -> V_71 = V_6 -> V_623 ++ ;
V_47 -> V_72 = V_120 ;
V_47 -> V_26 = V_26 ;
V_47 -> V_51 = V_51 ;
F_35 ( V_6 , V_47 ) ;
V_19 = F_227 ( V_6 -> V_99 , V_120 ,
V_47 -> V_71 , 0 ) ;
if ( V_19 )
F_36 ( V_6 , V_47 ) ;
break;
case V_639 :
default:
break;
}
}
static void
F_238 ( struct V_5 * V_6 ,
struct V_278 * V_279 )
{
T_4 V_26 , V_537 ;
T_10 V_148 ;
struct V_44 * V_45 ;
unsigned long V_63 ;
T_9 V_28 ;
T_8 V_27 ;
T_10 V_29 ;
T_44 * V_286 =
( T_44 * ) V_279 -> V_286 ;
T_1 V_8 ;
if ( V_6 -> V_66 )
return;
if ( V_286 -> V_345 != V_640 )
return;
V_26 = F_9 ( V_286 -> V_350 ) ;
V_148 = F_59 ( V_286 -> V_352 ) ;
F_27 ( V_6 , F_3 ( V_33
L_230 ,
V_6 -> V_34 , V_35 , V_26 ,
F_59 ( V_286 -> V_638 ) , V_148 ) ) ;
switch ( V_148 ) {
case V_641 :
case V_642 :
case V_643 :
case V_644 :
case V_645 :
F_137 ( V_26 , V_6 -> V_123 ) ;
F_19 ( & V_6 -> V_64 , V_63 ) ;
V_45 = F_17 ( V_6 , V_26 ) ;
F_22 ( & V_6 -> V_64 , V_63 ) ;
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
V_537 = F_9 ( V_27 . V_539 ) ;
if ( ! F_11 ( V_6 , V_537 , & V_8 ) )
F_196 ( V_6 , V_8 , V_26 ,
V_27 . V_566 , V_519 ) ;
F_213 ( V_6 , V_26 , 0 , 1 ) ;
break;
case V_646 :
case V_647 :
case V_648 :
default:
break;
}
}
static void
F_239 ( struct V_5 * V_6 ,
T_45 * V_286 )
{
char * V_583 = NULL ;
switch ( V_286 -> V_649 ) {
case V_650 :
V_583 = L_231 ;
break;
case V_651 :
V_583 = L_232 ;
break;
case V_652 :
V_583 = L_233 ;
break;
case V_653 :
V_583 = L_234 ;
break;
case V_654 :
V_583 = L_235 ;
break;
}
if ( ! V_583 )
return;
F_3 ( V_33 L_236 \
L_237 ,
V_6 -> V_34 , V_583 ,
F_9 ( V_286 -> V_348 ) ,
V_286 -> V_655 ) ;
}
static void
F_240 ( struct V_5 * V_6 ,
struct V_278 * V_279 )
{
T_45 * V_286 =
( T_45 * )
V_279 -> V_286 ;
static struct V_46 * V_47 ;
unsigned long V_63 ;
T_4 V_26 ;
#ifdef F_170
if ( V_6 -> V_7 & V_581 )
F_239 ( V_6 ,
V_286 ) ;
#endif
if ( V_286 -> V_649 == V_650 ) {
F_19 ( & V_6 -> V_75 , V_63 ) ;
V_26 = F_9 ( V_286 -> V_348 ) ;
V_47 = F_33 ( V_6 , V_26 ) ;
if ( V_47 )
V_47 -> V_141 =
V_286 -> V_655 ;
F_22 ( & V_6 -> V_75 , V_63 ) ;
}
}
static void
F_241 ( struct V_5 * V_6 )
{
struct V_102 * V_103 ;
struct V_95 * V_96 ;
F_90 (sdev, ioc->shost) {
V_103 = V_96 -> V_107 ;
if ( V_103 && V_103 -> V_109 )
V_103 -> V_109 -> V_315 = 1 ;
}
}
static void
F_242 ( struct V_5 * V_6 , T_1 V_8 ,
T_4 V_17 , T_4 V_26 )
{
struct V_104 * V_105 = NULL ;
struct V_113 * V_69 ;
struct V_44 * V_45 ;
unsigned long V_63 ;
F_19 ( & V_6 -> V_64 , V_63 ) ;
F_4 (sas_device, &ioc->sas_device_list, list) {
if ( V_45 -> V_8 == V_8 &&
V_45 -> V_17 == V_17 ) {
V_45 -> V_656 = 1 ;
V_69 = V_45 -> V_69 ;
if ( V_69 && V_69 -> V_107 ) {
V_105 = V_69 -> V_107 ;
V_105 -> V_228 = 0 ;
V_105 -> V_315 = 0 ;
} else
V_105 = NULL ;
if ( V_69 )
F_111 ( V_130 , V_69 ,
L_238
L_239
L_240 , V_26 ,
( unsigned long long ) V_45 -> V_8 ,
( unsigned long long )
V_45 -> V_13 ,
V_45 -> V_17 ) ;
if ( V_45 -> V_26 == V_26 )
goto V_74;
F_3 ( L_241 ,
V_45 -> V_26 ) ;
V_45 -> V_26 = V_26 ;
if ( V_105 )
V_105 -> V_26 = V_26 ;
goto V_74;
}
}
V_74:
F_22 ( & V_6 -> V_64 , V_63 ) ;
}
static void
F_243 ( struct V_5 * V_6 )
{
T_8 V_27 ;
T_9 V_28 ;
T_4 V_29 ;
T_4 V_26 ;
T_10 V_81 ;
F_3 ( V_33 L_242 , V_6 -> V_34 ) ;
if ( F_126 ( & V_6 -> V_67 ) )
goto V_74;
V_26 = 0xFFFF ;
while ( ! ( F_12 ( V_6 , & V_28 ,
& V_27 , V_657 ,
V_26 ) ) ) {
V_29 = F_9 ( V_28 . V_37 ) &
V_38 ;
if ( V_29 != V_39 )
break;
V_26 = F_9 ( V_27 . V_181 ) ;
V_81 = F_59 ( V_27 . V_132 ) ;
if ( ! ( F_40 ( V_81 ) ) )
continue;
F_242 ( V_6 ,
F_6 ( V_27 . V_10 ) ,
F_9 ( V_27 . V_475 ) , V_26 ) ;
}
V_74:
F_3 ( V_33 L_243 ,
V_6 -> V_34 ) ;
}
static void
F_244 ( struct V_5 * V_6 , T_1 V_51 ,
T_4 V_26 )
{
struct V_104 * V_105 ;
struct V_113 * V_69 ;
struct V_46 * V_47 ;
unsigned long V_63 ;
F_19 ( & V_6 -> V_75 , V_63 ) ;
F_4 (raid_device, &ioc->raid_device_list, list) {
if ( V_47 -> V_51 == V_51 && V_47 -> V_69 ) {
V_69 = V_47 -> V_69 ;
if ( V_69 && V_69 -> V_107 ) {
V_105 = V_69 -> V_107 ;
V_105 -> V_315 = 0 ;
} else
V_105 = NULL ;
V_47 -> V_656 = 1 ;
F_22 ( & V_6 -> V_75 , V_63 ) ;
F_111 ( V_130 , V_47 -> V_69 ,
L_244 , V_26 ,
( unsigned long long ) V_47 -> V_51 ) ;
F_19 ( & V_6 -> V_75 , V_63 ) ;
if ( V_47 -> V_26 == V_26 ) {
F_22 ( & V_6 -> V_75 ,
V_63 ) ;
return;
}
F_3 ( L_241 ,
V_47 -> V_26 ) ;
V_47 -> V_26 = V_26 ;
if ( V_105 )
V_105 -> V_26 = V_26 ;
F_22 ( & V_6 -> V_75 , V_63 ) ;
return;
}
}
F_22 ( & V_6 -> V_75 , V_63 ) ;
}
static void
F_245 ( struct V_5 * V_6 )
{
T_46 V_658 ;
T_11 V_659 ;
T_12 V_173 ;
T_9 V_28 ;
T_4 V_29 ;
T_4 V_26 ;
T_6 V_616 ;
if ( ! V_6 -> V_660 )
return;
F_3 ( V_33 L_245 ,
V_6 -> V_34 ) ;
if ( F_126 ( & V_6 -> V_76 ) )
goto V_74;
V_26 = 0xFFFF ;
while ( ! ( F_246 ( V_6 , & V_28 ,
& V_658 , V_661 , V_26 ) ) ) {
V_29 = F_9 ( V_28 . V_37 ) &
V_38 ;
if ( V_29 != V_39 )
break;
V_26 = F_9 ( V_658 . V_181 ) ;
if ( F_63 ( V_6 , & V_28 ,
& V_659 , V_142 , V_26 ,
sizeof( T_11 ) ) )
continue;
if ( V_659 . V_151 == V_152 ||
V_659 . V_151 == V_153 ||
V_659 . V_151 == V_155 )
F_244 ( V_6 ,
F_6 ( V_658 . V_662 ) , V_26 ) ;
}
V_616 = 0xFF ;
memset ( V_6 -> V_123 , 0 , V_6 -> V_663 ) ;
while ( ! ( F_74 ( V_6 , & V_28 ,
& V_173 , V_664 ,
V_616 ) ) ) {
V_29 = F_9 ( V_28 . V_37 ) &
V_38 ;
if ( V_29 != V_39 )
break;
V_616 = V_173 . V_180 ;
V_26 = F_9 ( V_173 . V_181 ) ;
F_137 ( V_26 , V_6 -> V_123 ) ;
}
V_74:
F_3 ( V_33 L_246 ,
V_6 -> V_34 ) ;
}
static void
F_247 ( struct V_5 * V_6 , T_1 V_8 ,
T_4 V_26 )
{
struct V_77 * V_78 ;
unsigned long V_63 ;
int V_91 ;
F_19 ( & V_6 -> V_79 , V_63 ) ;
F_4 (sas_expander, &ioc->sas_expander_list, list) {
if ( V_78 -> V_8 != V_8 )
continue;
V_78 -> V_656 = 1 ;
if ( V_78 -> V_26 == V_26 )
goto V_74;
F_3 ( L_247 \
L_248 ,
( unsigned long long ) V_78 -> V_8 ,
V_78 -> V_26 , V_26 ) ;
V_78 -> V_26 = V_26 ;
for ( V_91 = 0 ; V_91 < V_78 -> V_31 ; V_91 ++ )
V_78 -> V_199 [ V_91 ] . V_26 = V_26 ;
goto V_74;
}
V_74:
F_22 ( & V_6 -> V_79 , V_63 ) ;
}
static void
F_248 ( struct V_5 * V_6 )
{
T_37 V_535 ;
T_9 V_28 ;
T_4 V_29 ;
T_1 V_8 ;
T_4 V_26 ;
F_3 ( V_33 L_249 , V_6 -> V_34 ) ;
if ( F_126 ( & V_6 -> V_80 ) )
goto V_74;
V_26 = 0xFFFF ;
while ( ! ( F_205 ( V_6 , & V_28 , & V_535 ,
V_665 , V_26 ) ) ) {
V_29 = F_9 ( V_28 . V_37 ) &
V_38 ;
if ( V_29 != V_39 )
break;
V_26 = F_9 ( V_535 . V_181 ) ;
V_8 = F_6 ( V_535 . V_10 ) ;
F_3 ( L_250 ,
V_26 ,
( unsigned long long ) V_8 ) ;
F_247 ( V_6 , V_8 , V_26 ) ;
}
V_74:
F_3 ( V_33 L_251 , V_6 -> V_34 ) ;
}
static void
F_249 ( struct V_5 * V_6 )
{
struct V_44 * V_45 , * V_666 ;
struct V_77 * V_78 , * V_667 ;
struct V_46 * V_47 , * V_668 ;
struct V_669 V_670 ;
unsigned long V_63 ;
F_3 ( V_33 L_252 ,
V_6 -> V_34 ) ;
F_3 ( V_33 L_253 ,
V_6 -> V_34 ) ;
F_128 (sas_device, sas_device_next,
&ioc->sas_device_list, list) {
if ( ! V_45 -> V_656 )
F_25 ( V_6 ,
V_45 -> V_8 ) ;
else
V_45 -> V_656 = 0 ;
}
if ( V_6 -> V_660 ) {
F_3 ( V_33 L_254 ,
V_6 -> V_34 ) ;
F_128 (raid_device, raid_device_next,
&ioc->raid_device_list, list) {
if ( ! V_47 -> V_656 )
F_228 ( V_6 ,
V_47 -> V_26 ) ;
else
V_47 -> V_656 = 0 ;
}
}
F_3 ( V_33 L_255 ,
V_6 -> V_34 ) ;
F_19 ( & V_6 -> V_79 , V_63 ) ;
F_118 ( & V_670 ) ;
F_128 (sas_expander, sas_expander_next,
&ioc->sas_expander_list, list) {
if ( ! V_78 -> V_656 )
F_250 ( & V_78 -> V_65 , & V_670 ) ;
else
V_78 -> V_656 = 0 ;
}
F_22 ( & V_6 -> V_79 , V_63 ) ;
F_128 (sas_expander, sas_expander_next, &tmp_list,
list) {
F_20 ( & V_78 -> V_65 ) ;
F_209 ( V_6 , V_78 ) ;
}
F_3 ( V_33 L_256 ,
V_6 -> V_34 ) ;
F_130 ( V_6 ) ;
}
static void
F_251 ( struct V_5 * V_6 ,
struct V_77 * V_78 , T_4 V_26 )
{
T_38 V_536 ;
T_9 V_28 ;
int V_91 ;
for ( V_91 = 0 ; V_91 < V_78 -> V_31 ; V_91 ++ ) {
if ( ( F_206 ( V_6 , & V_28 ,
& V_536 , V_91 , V_26 ) ) ) {
F_13 ( V_33 L_2 ,
V_6 -> V_34 , __FILE__ , __LINE__ , V_35 ) ;
return;
}
F_196 ( V_6 , V_78 -> V_8 ,
F_9 ( V_536 . V_308 ) , V_91 ,
V_536 . V_517 >> 4 ) ;
}
}
static void
F_252 ( struct V_5 * V_6 )
{
T_37 V_535 ;
T_8 V_27 ;
T_46 V_658 ;
T_11 V_659 ;
T_12 V_173 ;
T_23 V_341 ;
T_9 V_28 ;
T_6 V_616 ;
T_4 V_29 ;
T_4 V_26 , V_537 ;
T_1 V_8 ;
struct V_44 * V_45 ;
struct V_77 * V_671 ;
static struct V_46 * V_47 ;
T_6 V_672 ;
unsigned long V_63 ;
F_3 ( V_33 L_257 , V_6 -> V_34 ) ;
F_194 ( V_6 ) ;
F_3 ( V_33 L_258 , V_6 -> V_34 ) ;
V_26 = 0xFFFF ;
while ( ! ( F_205 ( V_6 , & V_28 , & V_535 ,
V_665 , V_26 ) ) ) {
V_29 = F_9 ( V_28 . V_37 ) &
V_38 ;
if ( V_29 != V_39 ) {
F_3 ( V_33 L_259 \
L_260 ,
V_6 -> V_34 , V_29 ,
F_59 ( V_28 . V_262 ) ) ;
break;
}
V_26 = F_9 ( V_535 . V_181 ) ;
F_19 ( & V_6 -> V_79 , V_63 ) ;
V_671 = F_38 (
V_6 , F_6 ( V_535 . V_10 ) ) ;
F_22 ( & V_6 -> V_79 , V_63 ) ;
if ( V_671 )
F_251 ( V_6 , V_671 ,
V_26 ) ;
else {
F_3 ( V_33 L_261 \
L_262 , V_6 -> V_34 ,
V_26 , ( unsigned long long )
F_6 ( V_535 . V_10 ) ) ;
F_204 ( V_6 , V_26 ) ;
F_3 ( V_33 L_263 \
L_262 , V_6 -> V_34 ,
V_26 , ( unsigned long long )
F_6 ( V_535 . V_10 ) ) ;
}
}
F_3 ( V_33 L_264 ,
V_6 -> V_34 ) ;
if ( ! V_6 -> V_660 )
goto V_673;
F_3 ( V_33 L_265 , V_6 -> V_34 ) ;
V_616 = 0xFF ;
while ( ! ( F_74 ( V_6 , & V_28 ,
& V_173 , V_664 ,
V_616 ) ) ) {
V_29 = F_9 ( V_28 . V_37 ) &
V_38 ;
if ( V_29 != V_39 ) {
F_3 ( V_33 L_266\
L_260 ,
V_6 -> V_34 , V_29 ,
F_59 ( V_28 . V_262 ) ) ;
break;
}
V_616 = V_173 . V_180 ;
V_26 = F_9 ( V_173 . V_181 ) ;
F_19 ( & V_6 -> V_64 , V_63 ) ;
V_45 = F_17 ( V_6 , V_26 ) ;
F_22 ( & V_6 -> V_64 , V_63 ) ;
if ( V_45 )
continue;
if ( F_12 ( V_6 , & V_28 ,
& V_27 , V_32 ,
V_26 ) != 0 )
continue;
V_29 = F_9 ( V_28 . V_37 ) &
V_38 ;
if ( V_29 != V_39 ) {
F_3 ( V_33 L_267 \
L_260 ,
V_6 -> V_34 , V_29 ,
F_59 ( V_28 . V_262 ) ) ;
break;
}
V_537 = F_9 ( V_27 . V_539 ) ;
if ( ! F_11 ( V_6 , V_537 ,
& V_8 ) ) {
F_3 ( V_33 L_268 \
L_269 ,
V_6 -> V_34 , V_26 , ( unsigned long long )
F_6 ( V_27 . V_10 ) ) ;
F_196 ( V_6 , V_8 ,
V_26 , V_27 . V_566 ,
V_519 ) ;
F_137 ( V_26 , V_6 -> V_123 ) ;
V_672 = 0 ;
while ( F_213 ( V_6 , V_26 , V_672 ++ ,
1 ) ) {
F_222 ( 1 ) ;
}
F_3 ( V_33 L_270 \
L_269 ,
V_6 -> V_34 , V_26 , ( unsigned long long )
F_6 ( V_27 . V_10 ) ) ;
}
}
F_3 ( V_33 L_271 ,
V_6 -> V_34 ) ;
F_3 ( V_33 L_272 , V_6 -> V_34 ) ;
V_26 = 0xFFFF ;
while ( ! ( F_246 ( V_6 , & V_28 ,
& V_658 , V_661 , V_26 ) ) ) {
V_29 = F_9 ( V_28 . V_37 ) &
V_38 ;
if ( V_29 != V_39 ) {
F_3 ( V_33 L_273 \
L_260 ,
V_6 -> V_34 , V_29 ,
F_59 ( V_28 . V_262 ) ) ;
break;
}
V_26 = F_9 ( V_658 . V_181 ) ;
F_19 ( & V_6 -> V_75 , V_63 ) ;
V_47 = F_34 ( V_6 ,
F_6 ( V_658 . V_662 ) ) ;
F_22 ( & V_6 -> V_75 , V_63 ) ;
if ( V_47 )
continue;
if ( F_63 ( V_6 , & V_28 ,
& V_659 , V_142 , V_26 ,
sizeof( T_11 ) ) )
continue;
V_29 = F_9 ( V_28 . V_37 ) &
V_38 ;
if ( V_29 != V_39 ) {
F_3 ( V_33 L_273 \
L_260 ,
V_6 -> V_34 , V_29 ,
F_59 ( V_28 . V_262 ) ) ;
break;
}
if ( V_659 . V_151 == V_152 ||
V_659 . V_151 == V_153 ||
V_659 . V_151 == V_155 ) {
memset ( & V_341 , 0 , sizeof( T_23 ) ) ;
V_341 . V_345 = V_626 ;
V_341 . V_348 = V_658 . V_181 ;
F_3 ( V_33
L_274 ,
V_6 -> V_34 , V_658 . V_181 ) ;
F_226 ( V_6 , & V_341 ) ;
F_3 ( V_33
L_275 ,
V_6 -> V_34 , V_658 . V_181 ) ;
}
}
F_3 ( V_33 L_276 ,
V_6 -> V_34 ) ;
V_673:
F_3 ( V_33 L_277 ,
V_6 -> V_34 ) ;
V_26 = 0xFFFF ;
while ( ! ( F_12 ( V_6 , & V_28 ,
& V_27 , V_657 ,
V_26 ) ) ) {
V_29 = F_9 ( V_28 . V_37 ) &
V_38 ;
if ( V_29 != V_39 ) {
F_3 ( V_33 L_278\
L_279 ,
V_6 -> V_34 , V_29 ,
F_59 ( V_28 . V_262 ) ) ;
break;
}
V_26 = F_9 ( V_27 . V_181 ) ;
if ( ! ( F_40 (
F_59 ( V_27 . V_132 ) ) ) )
continue;
F_19 ( & V_6 -> V_64 , V_63 ) ;
V_45 = F_16 ( V_6 ,
F_6 ( V_27 . V_10 ) ) ;
F_22 ( & V_6 -> V_64 , V_63 ) ;
if ( V_45 )
continue;
V_537 = F_9 ( V_27 . V_539 ) ;
if ( ! F_11 ( V_6 , V_537 , & V_8 ) ) {
F_3 ( V_33 L_280 \
L_262 , V_6 -> V_34 ,
V_26 , ( unsigned long long )
F_6 ( V_27 . V_10 ) ) ;
F_196 ( V_6 , V_8 , V_26 ,
V_27 . V_566 , V_519 ) ;
V_672 = 0 ;
while ( F_213 ( V_6 , V_26 , V_672 ++ ,
0 ) ) {
F_222 ( 1 ) ;
}
F_3 ( V_33 L_281 \
L_262 , V_6 -> V_34 ,
V_26 , ( unsigned long long )
F_6 ( V_27 . V_10 ) ) ;
}
}
F_3 ( V_33 L_282 ,
V_6 -> V_34 ) ;
F_3 ( V_33 L_283 , V_6 -> V_34 ) ;
}
void
F_253 ( struct V_5 * V_6 , int V_674 )
{
switch ( V_674 ) {
case V_675 :
F_99 ( V_6 , F_3 ( V_33
L_284 , V_6 -> V_34 , V_35 ) ) ;
break;
case V_676 :
F_99 ( V_6 , F_3 ( V_33
L_285 , V_6 -> V_34 , V_35 ) ) ;
if ( V_6 -> V_543 . V_220 & V_225 ) {
V_6 -> V_543 . V_220 |= V_260 ;
F_150 ( V_6 , V_6 -> V_543 . V_87 ) ;
F_88 ( & V_6 -> V_543 . V_226 ) ;
}
if ( V_6 -> V_219 . V_220 & V_225 ) {
V_6 -> V_219 . V_220 |= V_260 ;
F_150 ( V_6 , V_6 -> V_219 . V_87 ) ;
F_88 ( & V_6 -> V_219 . V_226 ) ;
}
F_125 ( V_6 ) ;
F_160 ( V_6 ) ;
break;
case V_677 :
F_99 ( V_6 , F_3 ( V_33
L_286 , V_6 -> V_34 , V_35 ) ) ;
if ( ( ! V_6 -> V_48 ) && ! ( V_615 > 0 &&
! V_6 -> V_30 . V_31 ) ) {
F_241 ( V_6 ) ;
F_243 ( V_6 ) ;
F_245 ( V_6 ) ;
F_248 ( V_6 ) ;
F_123 ( V_6 ) ;
}
break;
}
}
static void
F_254 ( struct V_5 * V_6 , struct V_278 * V_279 )
{
if ( V_6 -> V_242 ||
V_6 -> V_243 ) {
F_121 ( V_6 , V_279 ) ;
return;
}
switch ( V_279 -> V_288 ) {
case V_289 :
F_255 ( V_6 ,
(struct V_285 * )
V_279 -> V_286 ) ;
break;
case V_290 :
while ( F_256 ( V_6 -> V_99 ) || V_6 -> V_66 )
F_222 ( 1 ) ;
F_249 ( V_6 ) ;
F_252 ( V_6 ) ;
break;
case V_291 :
V_6 -> V_678 = 0 ;
if ( V_679 [ 0 ] != - 1 && V_679 [ 1 ] != - 1 )
F_257 ( V_6 , V_679 [ 0 ] ,
V_679 [ 1 ] ) ;
F_27 ( V_6 , F_3 ( V_33
L_287 ,
V_6 -> V_34 ) ) ;
break;
case V_479 :
F_180 ( V_6 , V_279 -> V_480 ) ;
break;
case V_336 :
F_215 ( V_6 , V_279 ) ;
break;
case V_489 :
F_217 ( V_6 , V_279 ) ;
break;
case V_680 :
F_221 ( V_6 , V_279 ) ;
break;
case V_681 :
F_220 ( V_6 , V_279 ) ;
break;
case V_682 :
F_219 ( V_6 ,
V_279 ) ;
break;
case V_683 :
F_236 ( V_6 , V_279 ) ;
break;
case V_684 :
F_237 ( V_6 , V_279 ) ;
break;
case V_685 :
F_238 ( V_6 , V_279 ) ;
break;
case V_686 :
F_240 ( V_6 , V_279 ) ;
break;
}
F_121 ( V_6 , V_279 ) ;
}
static void
V_284 ( struct V_687 * V_283 )
{
struct V_278 * V_279 = F_258 ( V_283 ,
struct V_278 , V_283 ) ;
F_254 ( V_279 -> V_6 , V_279 ) ;
}
T_6
F_259 ( struct V_5 * V_6 , T_6 V_217 ,
T_10 V_218 )
{
struct V_278 * V_279 ;
T_30 * V_28 ;
T_4 V_288 ;
T_4 V_174 ;
if ( V_6 -> V_242 || V_6 -> V_243 )
return 1 ;
V_28 = F_87 ( V_6 , V_218 ) ;
if ( F_141 ( ! V_28 ) ) {
F_13 ( V_33 L_77 ,
V_6 -> V_34 , __FILE__ , __LINE__ , V_35 ) ;
return 1 ;
}
V_288 = F_9 ( V_28 -> V_488 ) ;
if ( V_288 != V_688 )
F_260 ( V_6 , V_288 , 0 ) ;
switch ( V_288 ) {
case V_681 :
{
T_40 * V_689 =
( T_40 * )
V_28 -> V_486 ;
if ( V_689 -> V_690 !=
V_691 )
return 1 ;
if ( V_6 -> V_612 ) {
V_6 -> V_611 ++ ;
return 1 ;
} else
V_6 -> V_612 = 1 ;
break;
}
case V_336 :
F_151 ( V_6 ,
( T_19 * )
V_28 -> V_486 ) ;
break;
case V_683 :
F_156 ( V_6 ,
( T_22 * )
V_28 -> V_486 ) ;
break;
case V_684 :
F_159 ( V_6 ,
( T_24 * )
V_28 -> V_486 ) ;
break;
case V_489 :
case V_686 :
case V_680 :
case V_682 :
case V_685 :
break;
default:
return 1 ;
}
V_174 = F_9 ( V_28 -> V_490 ) * 4 ;
V_279 = F_51 ( sizeof( * V_279 ) + V_174 , V_287 ) ;
if ( ! V_279 ) {
F_13 ( V_33 L_2 ,
V_6 -> V_34 , __FILE__ , __LINE__ , V_35 ) ;
return 1 ;
}
memcpy ( V_279 -> V_286 , V_28 -> V_486 , V_174 ) ;
V_279 -> V_6 = V_6 ;
V_279 -> V_692 = V_28 -> V_692 ;
V_279 -> V_693 = V_28 -> V_693 ;
V_279 -> V_288 = V_288 ;
F_117 ( V_6 , V_279 ) ;
return 1 ;
}
static void
F_209 ( struct V_5 * V_6 ,
struct V_77 * V_78 )
{
struct V_296 * V_297 , * V_292 ;
F_128 (mpt3sas_port, next,
&sas_expander->sas_port_list, port_list) {
if ( V_6 -> V_66 )
return;
if ( V_297 -> V_299 . V_300 ==
V_301 )
F_25 ( V_6 ,
V_297 -> V_299 . V_8 ) ;
else if ( V_297 -> V_299 . V_300 ==
V_303 ||
V_297 -> V_299 . V_300 ==
V_304 )
F_208 ( V_6 ,
V_297 -> V_299 . V_8 ) ;
}
F_30 ( V_6 , V_78 -> V_8 ,
V_78 -> V_68 ) ;
F_3 ( V_33
L_288 ,
V_6 -> V_34 ,
V_78 -> V_26 , ( unsigned long long )
V_78 -> V_8 ) ;
F_21 ( V_78 -> V_199 ) ;
F_21 ( V_78 ) ;
}
static void
F_261 ( struct V_5 * V_6 )
{
T_42 * V_234 ;
T_43 * V_28 ;
T_4 V_87 ;
if ( ! V_6 -> V_660 )
return;
if ( F_126 ( & V_6 -> V_76 ) )
return;
F_93 ( & V_6 -> V_543 . V_239 ) ;
if ( V_6 -> V_543 . V_220 != V_221 ) {
F_13 ( V_33 L_205 ,
V_6 -> V_34 , V_35 ) ;
goto V_74;
}
V_6 -> V_543 . V_220 = V_225 ;
V_87 = F_142 ( V_6 , V_6 -> V_619 ) ;
if ( ! V_87 ) {
F_13 ( V_33 L_43 ,
V_6 -> V_34 , V_35 ) ;
V_6 -> V_543 . V_220 = V_221 ;
goto V_74;
}
V_234 = F_100 ( V_6 , V_87 ) ;
V_6 -> V_543 . V_87 = V_87 ;
memset ( V_234 , 0 , sizeof( T_42 ) ) ;
V_234 -> V_253 = V_620 ;
V_234 -> V_469 = V_694 ;
F_3 ( V_33 L_289 , V_6 -> V_34 ) ;
F_103 ( & V_6 -> V_543 . V_226 ) ;
F_143 ( V_6 , V_87 ) ;
F_105 ( & V_6 -> V_543 . V_226 , 10 * V_259 ) ;
if ( ! ( V_6 -> V_543 . V_220 & V_222 ) ) {
F_13 ( V_33 L_45 ,
V_6 -> V_34 , V_35 ) ;
goto V_74;
}
if ( V_6 -> V_543 . V_220 & V_224 ) {
V_28 = V_6 -> V_543 . V_218 ;
F_3 ( V_33
L_290 ,
V_6 -> V_34 , F_9 ( V_28 -> V_37 ) ,
F_59 ( V_28 -> V_262 ) ) ;
}
V_74:
V_6 -> V_543 . V_220 = V_221 ;
F_108 ( & V_6 -> V_543 . V_239 ) ;
}
static void F_262 ( struct V_695 * V_483 )
{
struct V_98 * V_99 = F_263 ( V_483 ) ;
struct V_5 * V_6 = F_47 ( V_99 ) ;
struct V_296 * V_297 , * V_696 ;
struct V_46 * V_47 , * V_292 ;
struct V_104 * V_105 ;
struct V_697 * V_698 ;
unsigned long V_63 ;
V_6 -> V_242 = 1 ;
F_125 ( V_6 ) ;
F_19 ( & V_6 -> V_281 , V_63 ) ;
V_698 = V_6 -> V_280 ;
V_6 -> V_280 = NULL ;
F_22 ( & V_6 -> V_281 , V_63 ) ;
if ( V_698 )
F_264 ( V_698 ) ;
F_261 ( V_6 ) ;
F_128 (raid_device, next, &ioc->raid_device_list,
list) {
if ( V_47 -> V_69 ) {
V_105 =
V_47 -> V_69 -> V_107 ;
V_105 -> V_315 = 1 ;
F_229 ( & V_47 -> V_69 -> V_114 ) ;
}
F_3 ( V_33 L_214 ,
V_6 -> V_34 , V_47 -> V_26 ,
( unsigned long long ) V_47 -> V_51 ) ;
F_36 ( V_6 , V_47 ) ;
}
F_128 (mpt3sas_port, next_port,
&ioc->sas_hba.sas_port_list, port_list) {
if ( V_297 -> V_299 . V_300 ==
V_301 )
F_25 ( V_6 ,
V_297 -> V_299 . V_8 ) ;
else if ( V_297 -> V_299 . V_300 ==
V_303 ||
V_297 -> V_299 . V_300 ==
V_304 )
F_208 ( V_6 ,
V_297 -> V_299 . V_8 ) ;
}
if ( V_6 -> V_30 . V_31 ) {
F_21 ( V_6 -> V_30 . V_199 ) ;
V_6 -> V_30 . V_199 = NULL ;
V_6 -> V_30 . V_31 = 0 ;
}
F_265 ( V_99 ) ;
F_266 ( V_99 ) ;
F_267 ( V_6 ) ;
F_20 ( & V_6 -> V_65 ) ;
F_268 ( V_99 ) ;
}
static void
F_269 ( struct V_695 * V_483 )
{
struct V_98 * V_99 = F_263 ( V_483 ) ;
struct V_5 * V_6 = F_47 ( V_99 ) ;
struct V_697 * V_698 ;
unsigned long V_63 ;
V_6 -> V_242 = 1 ;
F_125 ( V_6 ) ;
F_19 ( & V_6 -> V_281 , V_63 ) ;
V_698 = V_6 -> V_280 ;
V_6 -> V_280 = NULL ;
F_22 ( & V_6 -> V_281 , V_63 ) ;
if ( V_698 )
F_264 ( V_698 ) ;
F_261 ( V_6 ) ;
F_267 ( V_6 ) ;
}
static void
F_270 ( struct V_5 * V_6 )
{
T_6 V_43 ;
void * V_42 ;
struct V_44 * V_45 ;
struct V_46 * V_47 ;
T_4 V_26 ;
T_1 V_68 ;
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
V_19 = F_227 ( V_6 -> V_99 , V_120 ,
V_47 -> V_71 , 0 ) ;
if ( V_19 )
F_36 ( V_6 , V_47 ) ;
} else {
F_19 ( & V_6 -> V_64 , V_63 ) ;
V_45 = V_42 ;
V_26 = V_45 -> V_26 ;
V_68 = V_45 -> V_68 ;
V_8 = V_45 -> V_8 ;
F_250 ( & V_45 -> V_65 , & V_6 -> V_67 ) ;
F_22 ( & V_6 -> V_64 , V_63 ) ;
if ( ! F_29 ( V_6 , V_26 ,
V_68 ) ) {
F_18 ( V_6 , V_45 ) ;
} else if ( ! V_45 -> V_69 ) {
if ( ! V_6 -> V_48 ) {
F_30 ( V_6 ,
V_8 ,
V_68 ) ;
F_18 ( V_6 , V_45 ) ;
}
}
}
}
static void
F_271 ( struct V_5 * V_6 )
{
struct V_46 * V_47 , * V_699 ;
int V_19 ;
F_128 (raid_device, raid_next,
&ioc->raid_device_list, list) {
if ( V_47 -> V_69 )
continue;
V_19 = F_227 ( V_6 -> V_99 , V_120 ,
V_47 -> V_71 , 0 ) ;
if ( V_19 )
F_36 ( V_6 , V_47 ) ;
}
}
static void
F_272 ( struct V_5 * V_6 )
{
struct V_44 * V_45 , * V_292 ;
unsigned long V_63 ;
F_128 (sas_device, next, &ioc->sas_device_init_list,
list) {
if ( ! F_29 ( V_6 , V_45 -> V_26 ,
V_45 -> V_68 ) ) {
F_20 ( & V_45 -> V_65 ) ;
F_21 ( V_45 ) ;
continue;
} else if ( ! V_45 -> V_69 ) {
if ( ! V_6 -> V_48 ) {
F_30 ( V_6 ,
V_45 -> V_8 ,
V_45 -> V_68 ) ;
F_20 ( & V_45 -> V_65 ) ;
F_21 ( V_45 ) ;
continue;
}
}
F_19 ( & V_6 -> V_64 , V_63 ) ;
F_250 ( & V_45 -> V_65 , & V_6 -> V_67 ) ;
F_22 ( & V_6 -> V_64 , V_63 ) ;
}
}
static void
F_273 ( struct V_5 * V_6 )
{
T_4 V_700 ;
if ( ! ( V_6 -> V_183 . V_701 & V_702 ) )
return;
F_270 ( V_6 ) ;
if ( V_6 -> V_660 ) {
V_700 =
F_9 ( V_6 -> V_703 . V_704 ) &
V_705 ;
if ( V_700 ==
V_706 ) {
F_271 ( V_6 ) ;
F_272 ( V_6 ) ;
} else {
F_272 ( V_6 ) ;
F_271 ( V_6 ) ;
}
} else
F_272 ( V_6 ) ;
}
static void
F_274 ( struct V_98 * V_99 )
{
struct V_5 * V_6 = F_47 ( V_99 ) ;
int V_19 ;
if ( V_707 != - 1 && V_707 != 0 )
F_275 ( V_6 , V_707 ) ;
if ( V_615 > 0 )
return;
V_6 -> V_678 = 1 ;
V_19 = F_276 ( V_6 ) ;
if ( V_19 != 0 )
F_3 ( V_33 L_291 , V_6 -> V_34 ) ;
}
static int
F_277 ( struct V_98 * V_99 , unsigned long time )
{
struct V_5 * V_6 = F_47 ( V_99 ) ;
if ( V_615 > 0 ) {
V_6 -> V_48 = 0 ;
V_6 -> V_572 = 0 ;
return 1 ;
}
if ( time >= ( 300 * V_259 ) ) {
V_6 -> V_708 . V_220 = V_221 ;
F_3 ( V_33
L_292 ,
V_6 -> V_34 ) ;
V_6 -> V_48 = 0 ;
return 1 ;
}
if ( V_6 -> V_678 )
return 0 ;
if ( V_6 -> V_709 ) {
F_3 ( V_33
L_293 ,
V_6 -> V_34 , V_6 -> V_709 ) ;
V_6 -> V_48 = 0 ;
V_6 -> V_572 = 0 ;
V_6 -> V_242 = 1 ;
return 1 ;
}
F_3 ( V_33 L_294 , V_6 -> V_34 ) ;
V_6 -> V_708 . V_220 = V_221 ;
if ( V_6 -> V_572 ) {
V_6 -> V_572 = 0 ;
F_273 ( V_6 ) ;
}
F_278 ( V_6 ) ;
V_6 -> V_48 = 0 ;
return 1 ;
}
static int
F_279 ( struct V_695 * V_483 , const struct V_710 * V_71 )
{
struct V_5 * V_6 ;
struct V_98 * V_99 ;
int V_711 ;
V_99 = F_280 ( & V_712 ,
sizeof( struct V_5 ) ) ;
if ( ! V_99 )
return - V_713 ;
V_6 = F_47 ( V_99 ) ;
memset ( V_6 , 0 , sizeof( struct V_5 ) ) ;
F_118 ( & V_6 -> V_65 ) ;
F_28 ( & V_6 -> V_65 , & V_714 ) ;
V_6 -> V_99 = V_99 ;
V_6 -> V_71 = V_715 ++ ;
sprintf ( V_6 -> V_34 , L_295 , V_716 , V_6 -> V_71 ) ;
V_6 -> V_483 = V_483 ;
V_6 -> V_400 = V_400 ;
V_6 -> V_251 = V_251 ;
V_6 -> V_717 = V_717 ;
V_6 -> V_718 = V_718 ;
V_6 -> V_719 = V_719 ;
V_6 -> V_720 = V_720 ;
V_6 -> V_619 = V_619 ;
V_6 -> V_721 = V_721 ;
V_6 -> V_316 = V_316 ;
V_6 -> V_325 = V_325 ;
V_6 -> V_321 = V_321 ;
V_6 -> V_7 = V_7 ;
V_6 -> V_722 = & F_160 ;
F_281 ( & V_6 -> V_723 ) ;
F_282 ( & V_6 -> V_724 ) ;
F_282 ( & V_6 -> V_90 ) ;
F_282 ( & V_6 -> V_64 ) ;
F_282 ( & V_6 -> V_79 ) ;
F_282 ( & V_6 -> V_281 ) ;
F_282 ( & V_6 -> V_75 ) ;
F_282 ( & V_6 -> V_725 ) ;
F_118 ( & V_6 -> V_67 ) ;
F_118 ( & V_6 -> V_70 ) ;
F_118 ( & V_6 -> V_80 ) ;
F_118 ( & V_6 -> V_282 ) ;
F_118 ( & V_6 -> V_76 ) ;
F_118 ( & V_6 -> V_30 . V_542 ) ;
F_118 ( & V_6 -> V_317 ) ;
F_118 ( & V_6 -> V_326 ) ;
F_118 ( & V_6 -> V_726 ) ;
V_99 -> V_727 = 32 ;
V_99 -> V_728 = V_728 ;
V_99 -> V_729 = V_730 ;
V_99 -> V_731 = V_6 -> V_71 ;
if ( V_732 != 0xFFFF ) {
if ( V_732 < 64 ) {
V_99 -> V_732 = 64 ;
F_72 ( V_33 L_296 \
L_297
L_298 , V_6 -> V_34 , V_732 ) ;
} else if ( V_732 > 32767 ) {
V_99 -> V_732 = 32767 ;
F_72 ( V_33 L_296 \
L_297
L_299 , V_6 -> V_34 ,
V_732 ) ;
} else {
V_99 -> V_732 = V_732 & 0xFFFE ;
F_3 ( V_33
L_300 ,
V_6 -> V_34 , V_99 -> V_732 ) ;
}
}
if ( V_733 > 0 )
F_283 ( V_99 , V_733 ) ;
else
F_283 ( V_99 , V_734
| V_735
| V_736 ) ;
F_284 ( V_99 , V_737 ) ;
snprintf ( V_6 -> V_738 , sizeof( V_6 -> V_738 ) ,
L_301 , V_6 -> V_71 ) ;
V_6 -> V_280 = F_285 (
V_6 -> V_738 ) ;
if ( ! V_6 -> V_280 ) {
F_13 ( V_33 L_2 ,
V_6 -> V_34 , __FILE__ , __LINE__ , V_35 ) ;
V_711 = - V_713 ;
goto V_739;
}
V_6 -> V_48 = 1 ;
if ( ( F_286 ( V_6 ) ) ) {
F_13 ( V_33 L_2 ,
V_6 -> V_34 , __FILE__ , __LINE__ , V_35 ) ;
V_711 = - V_713 ;
goto V_740;
}
V_711 = F_287 ( V_99 , & V_483 -> V_114 ) ;
if ( V_711 ) {
F_13 ( V_33 L_2 ,
V_6 -> V_34 , __FILE__ , __LINE__ , V_35 ) ;
goto V_741;
}
F_288 ( V_99 ) ;
return 0 ;
V_741:
F_267 ( V_6 ) ;
V_740:
F_264 ( V_6 -> V_280 ) ;
V_739:
F_20 ( & V_6 -> V_65 ) ;
F_268 ( V_99 ) ;
return V_711 ;
}
static int
F_289 ( struct V_695 * V_483 , T_47 V_148 )
{
struct V_98 * V_99 = F_263 ( V_483 ) ;
struct V_5 * V_6 = F_47 ( V_99 ) ;
T_48 V_742 ;
F_290 ( V_6 ) ;
F_291 () ;
F_292 ( V_99 ) ;
V_742 = F_293 ( V_483 , V_148 ) ;
F_3 ( V_33
L_302 ,
V_6 -> V_34 , V_483 , F_294 ( V_483 ) , V_742 ) ;
F_295 ( V_483 ) ;
F_296 ( V_6 ) ;
F_297 ( V_483 , V_742 ) ;
return 0 ;
}
static int
F_298 ( struct V_695 * V_483 )
{
struct V_98 * V_99 = F_263 ( V_483 ) ;
struct V_5 * V_6 = F_47 ( V_99 ) ;
T_48 V_742 = V_483 -> V_743 ;
int V_73 ;
F_3 ( V_33
L_303 ,
V_6 -> V_34 , V_483 , F_294 ( V_483 ) , V_742 ) ;
F_297 ( V_483 , V_744 ) ;
F_299 ( V_483 , V_744 , 0 ) ;
F_300 ( V_483 ) ;
V_6 -> V_483 = V_483 ;
V_73 = F_301 ( V_6 ) ;
if ( V_73 )
return V_73 ;
F_96 ( V_6 , V_245 , V_745 ) ;
F_302 ( V_99 ) ;
F_278 ( V_6 ) ;
return 0 ;
}
static T_49
F_303 ( struct V_695 * V_483 , T_50 V_148 )
{
struct V_98 * V_99 = F_263 ( V_483 ) ;
struct V_5 * V_6 = F_47 ( V_99 ) ;
F_3 ( V_33 L_304 ,
V_6 -> V_34 , V_148 ) ;
switch ( V_148 ) {
case V_746 :
return V_747 ;
case V_748 :
V_6 -> V_243 = 1 ;
F_292 ( V_6 -> V_99 ) ;
F_290 ( V_6 ) ;
F_296 ( V_6 ) ;
return V_749 ;
case V_750 :
V_6 -> V_243 = 1 ;
F_290 ( V_6 ) ;
F_160 ( V_6 ) ;
return V_751 ;
}
return V_749 ;
}
static T_49
F_304 ( struct V_695 * V_483 )
{
struct V_98 * V_99 = F_263 ( V_483 ) ;
struct V_5 * V_6 = F_47 ( V_99 ) ;
int V_19 ;
F_3 ( V_33 L_305 ,
V_6 -> V_34 ) ;
V_6 -> V_243 = 0 ;
V_6 -> V_483 = V_483 ;
F_300 ( V_483 ) ;
V_19 = F_301 ( V_6 ) ;
if ( V_19 )
return V_751 ;
V_19 = F_96 ( V_6 , V_245 ,
V_246 ) ;
F_72 ( V_33 L_306 , V_6 -> V_34 ,
( V_19 == 0 ) ? L_88 : L_307 ) ;
if ( ! V_19 )
return V_752 ;
else
return V_751 ;
}
static void
F_305 ( struct V_695 * V_483 )
{
struct V_98 * V_99 = F_263 ( V_483 ) ;
struct V_5 * V_6 = F_47 ( V_99 ) ;
F_3 ( V_33 L_308 , V_6 -> V_34 ) ;
F_306 ( V_483 ) ;
F_278 ( V_6 ) ;
F_302 ( V_6 -> V_99 ) ;
}
static T_49
F_307 ( struct V_695 * V_483 )
{
struct V_98 * V_99 = F_263 ( V_483 ) ;
struct V_5 * V_6 = F_47 ( V_99 ) ;
F_3 ( V_33 L_309 ,
V_6 -> V_34 ) ;
return V_749 ;
}
static int T_51
F_308 ( void )
{
int error ;
V_715 = 0 ;
F_3 ( L_310 , V_716 ,
V_753 ) ;
V_730 =
F_309 ( & V_754 ) ;
if ( ! V_730 )
return - V_713 ;
V_145 = F_310 ( & V_755 ) ;
if ( ! V_145 ) {
F_311 ( V_730 ) ;
return - V_713 ;
}
F_312 () ;
V_400 = F_313 ( F_188 ) ;
V_251 = F_313 ( F_85 ) ;
V_718 = F_313 ( V_756 ) ;
V_719 = F_313 (
V_757 ) ;
V_720 = F_313 (
V_758 ) ;
V_619 = F_313 ( F_210 ) ;
V_721 = F_313 (
V_759 ) ;
V_717 = F_313 ( V_760 ) ;
V_316 = F_313 (
F_140 ) ;
V_325 = F_313 (
F_148 ) ;
V_321 = F_313 (
F_145 ) ;
F_314 () ;
error = F_315 ( & V_761 ) ;
if ( error ) {
F_316 ( V_145 ) ;
F_311 ( V_730 ) ;
}
return error ;
}
static void T_52
F_317 ( void )
{
F_3 ( L_311 ,
V_753 ) ;
F_318 () ;
F_319 ( & V_761 ) ;
F_320 ( V_400 ) ;
F_320 ( V_251 ) ;
F_320 ( V_718 ) ;
F_320 ( V_719 ) ;
F_320 ( V_720 ) ;
F_320 ( V_619 ) ;
F_320 ( V_721 ) ;
F_320 ( V_717 ) ;
F_320 ( V_316 ) ;
F_320 ( V_325 ) ;
F_320 ( V_321 ) ;
F_316 ( V_145 ) ;
F_311 ( V_730 ) ;
}
