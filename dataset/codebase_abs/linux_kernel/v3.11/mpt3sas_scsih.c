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
static void
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
F_48 ( V_96 , F_49 ( V_96 ) , V_97 ) ;
}
static int
F_50 ( struct V_95 * V_96 , int V_97 , int V_113 )
{
if ( V_113 == V_114 || V_113 == V_115 )
F_46 ( V_96 , V_97 ) ;
else if ( V_113 == V_116 )
F_51 ( V_96 , V_97 ) ;
else
return - V_117 ;
if ( V_96 -> V_118 > 7 )
F_52 ( V_119 , V_96 , L_9 \
L_10 ,
V_96 -> V_120 , V_96 -> V_112 , V_96 -> V_121 ,
V_96 -> V_122 , V_96 -> V_123 ,
( V_96 -> V_124 [ 7 ] & 2 ) >> 1 ) ;
return V_96 -> V_120 ;
}
static int
F_53 ( struct V_95 * V_96 , int V_125 )
{
if ( V_96 -> V_112 ) {
F_54 ( V_96 , V_125 ) ;
if ( V_125 )
F_55 ( V_96 , V_96 -> V_120 ) ;
else
F_56 ( V_96 , V_96 -> V_120 ) ;
} else
V_125 = 0 ;
return V_125 ;
}
static int
F_57 ( struct V_126 * V_69 )
{
struct V_98 * V_99 = F_58 ( & V_69 -> V_127 ) ;
struct V_5 * V_6 = F_47 ( V_99 ) ;
struct V_104 * V_105 ;
struct V_44 * V_45 ;
struct V_46 * V_47 ;
unsigned long V_63 ;
struct V_128 * V_129 ;
V_105 = F_59 ( sizeof( struct V_126 ) , V_130 ) ;
if ( ! V_105 )
return - V_131 ;
V_69 -> V_107 = V_105 ;
V_105 -> V_69 = V_69 ;
V_105 -> V_26 = V_132 ;
if ( V_69 -> V_72 == V_133 ) {
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
V_129 = F_60 ( V_69 -> V_127 . V_134 ) ;
V_45 = F_16 ( V_6 ,
V_129 -> V_135 . V_8 ) ;
if ( V_45 ) {
V_105 -> V_26 = V_45 -> V_26 ;
V_105 -> V_8 = V_45 -> V_8 ;
V_45 -> V_69 = V_69 ;
V_45 -> V_71 = V_69 -> V_71 ;
V_45 -> V_72 = V_69 -> V_72 ;
if ( F_61 ( V_45 -> V_26 , V_6 -> V_136 ) )
V_105 -> V_63 |=
V_137 ;
if ( V_45 -> V_138 )
V_105 -> V_63 |= V_139 ;
}
F_22 ( & V_6 -> V_64 , V_63 ) ;
return 0 ;
}
static void
F_62 ( struct V_126 * V_69 )
{
struct V_98 * V_99 = F_58 ( & V_69 -> V_127 ) ;
struct V_5 * V_6 = F_47 ( V_99 ) ;
struct V_104 * V_105 ;
struct V_44 * V_45 ;
struct V_46 * V_47 ;
unsigned long V_63 ;
struct V_128 * V_129 ;
V_105 = V_69 -> V_107 ;
if ( ! V_105 )
return;
if ( V_69 -> V_72 == V_133 ) {
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
V_129 = F_60 ( V_69 -> V_127 . V_134 ) ;
V_45 = F_16 ( V_6 ,
V_129 -> V_135 . V_8 ) ;
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
F_63 ( struct V_95 * V_96 )
{
struct V_98 * V_99 ;
struct V_5 * V_6 ;
struct V_104 * V_105 ;
struct V_102 * V_103 ;
struct V_126 * V_69 ;
struct V_46 * V_47 ;
struct V_44 * V_45 ;
unsigned long V_63 ;
V_103 = F_59 ( sizeof( struct V_95 ) , V_130 ) ;
if ( ! V_103 )
return - V_131 ;
V_103 -> V_94 = V_96 -> V_94 ;
V_103 -> V_63 = V_140 ;
V_69 = V_126 ( V_96 ) ;
V_105 = V_69 -> V_107 ;
V_105 -> V_141 ++ ;
V_103 -> V_109 = V_105 ;
V_96 -> V_107 = V_103 ;
if ( ( V_105 -> V_63 & V_137 ) )
V_96 -> V_142 = 1 ;
V_99 = F_58 ( & V_69 -> V_127 ) ;
V_6 = F_47 ( V_99 ) ;
if ( V_69 -> V_72 == V_133 ) {
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
F_52 ( V_119 , V_96 ,
L_11 ,
V_35 , __LINE__ ) ;
V_45 -> V_69 = V_69 ;
}
F_22 ( & V_6 -> V_64 , V_63 ) ;
}
return 0 ;
}
static void
F_64 ( struct V_95 * V_96 )
{
struct V_104 * V_105 ;
struct V_126 * V_69 ;
struct V_98 * V_99 ;
struct V_5 * V_6 ;
struct V_44 * V_45 ;
unsigned long V_63 ;
if ( ! V_96 -> V_107 )
return;
V_69 = V_126 ( V_96 ) ;
V_105 = V_69 -> V_107 ;
V_105 -> V_141 -- ;
V_99 = F_58 ( & V_69 -> V_127 ) ;
V_6 = F_47 ( V_99 ) ;
if ( ! ( V_105 -> V_63 & V_110 ) ) {
F_19 ( & V_6 -> V_64 , V_63 ) ;
V_45 = F_16 ( V_6 ,
V_105 -> V_8 ) ;
if ( V_45 && ! V_105 -> V_141 )
V_45 -> V_69 = NULL ;
F_22 ( & V_6 -> V_64 , V_63 ) ;
}
F_21 ( V_96 -> V_107 ) ;
V_96 -> V_107 = NULL ;
}
static void
F_65 ( struct V_5 * V_6 ,
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
V_63 = F_9 ( V_27 . V_143 ) ;
V_81 = F_66 ( V_27 . V_144 ) ;
F_52 ( V_119 , V_96 ,
L_12
L_13 ,
( V_81 & V_145 ) ? L_14 : L_15 ,
( V_63 & V_146 ) ? L_14 : L_15 ,
( V_63 & V_147 ) ? L_14 :
L_15 ,
( V_63 & V_148 ) ? L_14 : L_15 ,
( V_63 & V_149 ) ? L_14 : L_15 ,
( V_63 & V_150 ) ? L_14 : L_15 ) ;
}
static int
F_67 ( struct V_42 * V_127 )
{
struct V_95 * V_96 = F_68 ( V_127 ) ;
return ( V_96 -> V_72 == V_133 ) ? 1 : 0 ;
}
static void
F_69 ( struct V_42 * V_127 )
{
struct V_95 * V_96 = F_68 ( V_127 ) ;
struct V_5 * V_6 = F_47 ( V_96 -> V_100 ) ;
static struct V_46 * V_47 ;
unsigned long V_63 ;
T_11 V_151 ;
T_9 V_28 ;
T_10 V_152 ;
T_6 V_153 ;
T_4 V_26 ;
V_153 = 0 ;
V_26 = 0 ;
F_19 ( & V_6 -> V_75 , V_63 ) ;
V_47 = F_32 ( V_6 , V_96 -> V_71 ,
V_96 -> V_72 ) ;
if ( V_47 ) {
V_26 = V_47 -> V_26 ;
V_153 = V_47 -> V_153 ;
}
F_22 ( & V_6 -> V_75 , V_63 ) ;
if ( ! V_26 )
goto V_74;
if ( F_70 ( V_6 , & V_28 , & V_151 ,
V_154 , V_26 ,
sizeof( T_11 ) ) ) {
F_13 ( V_33 L_2 ,
V_6 -> V_34 , __FILE__ , __LINE__ , V_35 ) ;
V_153 = 0 ;
goto V_74;
}
V_152 = F_66 ( V_151 . V_155 ) ;
if ( ! ( V_152 &
V_156 ) )
V_153 = 0 ;
V_74:
F_71 ( V_157 , V_127 , V_153 ) ;
}
static void
F_72 ( struct V_42 * V_127 )
{
struct V_95 * V_96 = F_68 ( V_127 ) ;
struct V_5 * V_6 = F_47 ( V_96 -> V_100 ) ;
static struct V_46 * V_47 ;
unsigned long V_63 ;
T_11 V_151 ;
T_9 V_28 ;
T_10 V_158 ;
enum V_159 V_160 = V_161 ;
T_4 V_26 = 0 ;
F_19 ( & V_6 -> V_75 , V_63 ) ;
V_47 = F_32 ( V_6 , V_96 -> V_71 ,
V_96 -> V_72 ) ;
if ( V_47 )
V_26 = V_47 -> V_26 ;
F_22 ( & V_6 -> V_75 , V_63 ) ;
if ( ! V_47 )
goto V_74;
if ( F_70 ( V_6 , & V_28 , & V_151 ,
V_154 , V_26 ,
sizeof( T_11 ) ) ) {
F_13 ( V_33 L_2 ,
V_6 -> V_34 , __FILE__ , __LINE__ , V_35 ) ;
goto V_74;
}
V_158 = F_66 ( V_151 . V_155 ) ;
if ( V_158 & V_156 ) {
V_160 = V_162 ;
goto V_74;
}
switch ( V_151 . V_163 ) {
case V_164 :
case V_165 :
V_160 = V_166 ;
break;
case V_167 :
V_160 = V_168 ;
break;
case V_169 :
case V_170 :
V_160 = V_171 ;
break;
}
V_74:
F_73 ( V_157 , V_127 , V_160 ) ;
}
static void
F_74 ( struct V_95 * V_96 , T_6 V_172 )
{
enum V_173 V_174 = V_175 ;
switch ( V_172 ) {
case V_176 :
V_174 = V_177 ;
break;
case V_178 :
V_174 = V_179 ;
break;
case V_180 :
V_174 = V_181 ;
break;
case V_182 :
V_174 = V_183 ;
break;
}
F_75 ( V_157 , & V_96 -> V_184 , V_174 ) ;
}
static int
F_76 ( struct V_5 * V_6 ,
struct V_46 * V_47 )
{
T_11 * V_151 ;
T_12 V_185 ;
T_8 V_27 ;
T_9 V_28 ;
T_4 V_186 ;
T_6 V_187 ;
if ( ( F_77 ( V_6 , V_47 -> V_26 ,
& V_187 ) ) || ! V_187 ) {
F_78 ( V_6 , F_79 ( V_33
L_2 , V_6 -> V_34 , __FILE__ , __LINE__ ,
V_35 ) ) ;
return 1 ;
}
V_47 -> V_187 = V_187 ;
V_186 = F_80 ( T_11 , V_188 ) + ( V_187 *
sizeof( V_189 ) ) ;
V_151 = F_59 ( V_186 , V_130 ) ;
if ( ! V_151 ) {
F_78 ( V_6 , F_79 ( V_33
L_2 , V_6 -> V_34 , __FILE__ , __LINE__ ,
V_35 ) ) ;
return 1 ;
}
if ( ( F_70 ( V_6 , & V_28 , V_151 ,
V_154 , V_47 -> V_26 , V_186 ) ) ) {
F_78 ( V_6 , F_79 ( V_33
L_2 , V_6 -> V_34 , __FILE__ , __LINE__ ,
V_35 ) ) ;
F_21 ( V_151 ) ;
return 1 ;
}
V_47 -> V_172 = V_151 -> V_190 ;
if ( ! ( F_81 ( V_6 , & V_28 ,
& V_185 , V_191 ,
V_151 -> V_188 [ 0 ] . V_192 ) ) ) {
if ( ! ( F_12 ( V_6 , & V_28 ,
& V_27 , V_32 ,
F_9 ( V_185 . V_193 ) ) ) ) {
V_47 -> V_81 =
F_66 ( V_27 . V_144 ) ;
}
}
F_21 ( V_151 ) ;
return 0 ;
}
static void
F_82 ( struct V_5 * V_6 , struct V_95 * V_96 )
{
if ( V_96 -> type != V_194 )
return;
if ( ! ( V_6 -> V_195 . V_196 & V_197 ) )
return;
F_83 ( V_96 ) ;
F_52 ( V_119 , V_96 , L_16 ,
F_84 ( V_96 ) ? L_17 : L_18 ) ;
return;
}
static int
F_85 ( struct V_95 * V_96 )
{
struct V_98 * V_99 = V_96 -> V_100 ;
struct V_5 * V_6 = F_47 ( V_99 ) ;
struct V_102 * V_103 ;
struct V_104 * V_105 ;
struct V_44 * V_45 ;
struct V_46 * V_47 ;
unsigned long V_63 ;
int V_97 ;
T_6 V_198 = 0 ;
char * V_199 = L_19 ;
char * V_200 = L_19 ;
T_4 V_26 , V_201 = 0 ;
T_1 V_202 = 0 ;
V_97 = 1 ;
V_103 = V_96 -> V_107 ;
V_103 -> V_203 = 1 ;
V_103 -> V_63 &= ~ V_140 ;
V_105 = V_103 -> V_109 ;
V_26 = V_105 -> V_26 ;
if ( V_105 -> V_63 & V_110 ) {
F_19 ( & V_6 -> V_75 , V_63 ) ;
V_47 = F_33 ( V_6 , V_26 ) ;
F_22 ( & V_6 -> V_75 , V_63 ) ;
if ( ! V_47 ) {
F_78 ( V_6 , F_79 ( V_33
L_2 , V_6 -> V_34 , __FILE__ ,
__LINE__ , V_35 ) ) ;
return 1 ;
}
if ( F_76 ( V_6 , V_47 ) ) {
F_78 ( V_6 , F_79 ( V_33
L_2 , V_6 -> V_34 , __FILE__ ,
__LINE__ , V_35 ) ) ;
return 1 ;
}
if ( V_47 -> V_81 &
V_83 ) {
V_97 = V_204 ;
V_199 = L_20 ;
} else {
V_97 = V_111 ;
if ( V_47 -> V_81 &
V_85 )
V_199 = L_21 ;
else
V_199 = L_22 ;
}
switch ( V_47 -> V_172 ) {
case V_176 :
V_200 = L_23 ;
break;
case V_180 :
V_97 = V_205 ;
if ( V_6 -> V_206 . V_207 &&
( F_66 ( V_6 -> V_206 . V_208 ) &
V_209 ) &&
! ( V_47 -> V_187 % 2 ) )
V_200 = L_24 ;
else
V_200 = L_25 ;
break;
case V_182 :
V_97 = V_205 ;
V_200 = L_26 ;
break;
case V_178 :
V_97 = V_205 ;
V_200 = L_24 ;
break;
case V_210 :
default:
V_97 = V_205 ;
V_200 = L_27 ;
break;
}
F_52 ( V_119 , V_96 ,
L_28 ,
V_200 , V_47 -> V_26 ,
( unsigned long long ) V_47 -> V_51 ,
V_47 -> V_187 , V_199 ) ;
F_50 ( V_96 , V_97 , V_114 ) ;
F_74 ( V_96 , V_47 -> V_172 ) ;
return 0 ;
}
if ( V_105 -> V_63 & V_137 ) {
if ( F_86 ( V_6 , V_26 ,
& V_201 ) ) {
F_78 ( V_6 , F_79 ( V_33
L_2 , V_6 -> V_34 ,
__FILE__ , __LINE__ , V_35 ) ) ;
return 1 ;
}
if ( V_201 && F_87 ( V_6 ,
V_201 , & V_202 ) ) {
F_78 ( V_6 , F_79 ( V_33
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
F_78 ( V_6 , F_79 ( V_33
L_2 , V_6 -> V_34 , __FILE__ , __LINE__ ,
V_35 ) ) ;
return 1 ;
}
V_45 -> V_201 = V_201 ;
V_45 -> V_202 = V_202 ;
if ( V_45 -> V_81 & V_83 ) {
V_97 = V_204 ;
V_198 = 1 ;
V_199 = L_20 ;
} else {
V_97 = V_111 ;
if ( V_45 -> V_81 & V_84 )
V_199 = L_22 ;
else if ( V_45 -> V_81 &
V_85 )
V_199 = L_21 ;
}
F_52 ( V_119 , V_96 , L_29 \
L_30 ,
V_199 , V_26 , ( unsigned long long ) V_45 -> V_8 ,
V_45 -> V_211 , ( unsigned long long ) V_45 -> V_11 ) ;
F_52 ( V_119 , V_96 ,
L_31 ,
V_199 , ( unsigned long long )
V_45 -> V_13 , V_45 -> V_17 ) ;
F_22 ( & V_6 -> V_64 , V_63 ) ;
if ( ! V_198 )
F_65 ( V_6 , V_26 , V_96 ) ;
F_50 ( V_96 , V_97 , V_114 ) ;
if ( V_198 ) {
F_88 ( V_96 ) ;
F_82 ( V_6 , V_96 ) ;
}
return 0 ;
}
static int
F_89 ( struct V_95 * V_96 , struct V_212 * V_213 ,
T_13 V_214 , int V_215 [] )
{
int V_216 ;
int V_217 ;
T_13 V_218 ;
T_14 V_219 ;
V_216 = 64 ;
V_217 = 32 ;
V_219 = V_216 * V_217 ;
V_218 = V_214 ;
F_90 ( V_218 , V_219 ) ;
if ( ( T_14 ) V_214 >= 0x200000 ) {
V_216 = 255 ;
V_217 = 63 ;
V_219 = V_216 * V_217 ;
V_218 = V_214 ;
F_90 ( V_218 , V_219 ) ;
}
V_215 [ 0 ] = V_216 ;
V_215 [ 1 ] = V_217 ;
V_215 [ 2 ] = V_218 ;
return 0 ;
}
static void
F_91 ( struct V_5 * V_6 , T_6 V_220 )
{
char * V_221 ;
switch ( V_220 ) {
case V_222 :
V_221 = L_32 ;
break;
case V_223 :
V_221 = L_33 ;
break;
case V_224 :
V_221 = L_34 ;
break;
case V_225 :
V_221 = L_35 ;
break;
case V_226 :
V_221 = L_36 ;
break;
case V_227 :
V_221 = L_37 ;
break;
case 0xA :
V_221 = L_38 ;
break;
case V_228 :
V_221 = L_39 ;
break;
default:
V_221 = L_40 ;
break;
}
F_79 ( V_33 L_41 ,
V_6 -> V_34 , V_220 , V_221 ) ;
}
static T_6
F_92 ( struct V_5 * V_6 , T_4 V_87 , T_6 V_229 , T_10 V_230 )
{
T_15 * V_28 ;
if ( V_6 -> V_231 . V_232 == V_233 )
return 1 ;
if ( V_6 -> V_231 . V_87 != V_87 )
return 1 ;
F_93 ( V_6 ) ;
V_6 -> V_231 . V_232 |= V_234 ;
V_28 = F_94 ( V_6 , V_230 ) ;
if ( V_28 ) {
memcpy ( V_6 -> V_231 . V_230 , V_28 , V_28 -> V_235 * 4 ) ;
V_6 -> V_231 . V_232 |= V_236 ;
}
V_6 -> V_231 . V_232 &= ~ V_237 ;
F_95 ( & V_6 -> V_231 . V_238 ) ;
return 1 ;
}
void
F_96 ( struct V_5 * V_6 , T_4 V_26 )
{
struct V_102 * V_103 ;
struct V_95 * V_96 ;
T_6 V_239 = 0 ;
F_97 (sdev, ioc->shost) {
if ( V_239 )
continue;
V_103 = V_96 -> V_107 ;
if ( ! V_103 )
continue;
if ( V_103 -> V_109 -> V_26 == V_26 ) {
V_103 -> V_109 -> V_240 = 1 ;
V_239 = 1 ;
V_6 -> V_241 = 1 ;
}
}
}
void
F_98 ( struct V_5 * V_6 , T_4 V_26 )
{
struct V_102 * V_103 ;
struct V_95 * V_96 ;
T_6 V_239 = 0 ;
F_97 (sdev, ioc->shost) {
if ( V_239 )
continue;
V_103 = V_96 -> V_107 ;
if ( ! V_103 )
continue;
if ( V_103 -> V_109 -> V_26 == V_26 ) {
V_103 -> V_109 -> V_240 = 0 ;
V_239 = 1 ;
V_6 -> V_241 = 0 ;
}
}
}
int
F_99 ( struct V_5 * V_6 , T_4 V_26 , T_16 V_72 ,
T_16 V_71 , T_16 V_94 , T_6 type , T_4 V_242 , T_14 V_243 ,
unsigned long V_244 , enum V_245 V_246 )
{
T_17 * V_247 ;
T_18 * V_28 ;
T_4 V_87 = 0 ;
T_10 V_248 ;
unsigned long V_249 ;
struct V_250 * V_88 = NULL ;
int V_19 ;
if ( V_246 == V_251 )
F_100 ( & V_6 -> V_231 . V_252 ) ;
if ( V_6 -> V_231 . V_232 != V_233 ) {
F_3 ( V_33 L_42 ,
V_35 , V_6 -> V_34 ) ;
V_19 = V_253 ;
goto V_254;
}
if ( V_6 -> V_66 || V_6 -> V_255 ||
V_6 -> V_256 ) {
F_3 ( V_33 L_43 ,
V_35 , V_6 -> V_34 ) ;
V_19 = V_253 ;
goto V_254;
}
V_248 = F_101 ( V_6 , 0 ) ;
if ( V_248 & V_257 ) {
F_102 ( V_6 , F_3 ( V_33
L_44 , V_6 -> V_34 ) ) ;
V_19 = F_103 ( V_6 , V_258 ,
V_259 ) ;
V_19 = ( ! V_19 ) ? V_260 : V_253 ;
goto V_254;
}
if ( ( V_248 & V_261 ) == V_262 ) {
F_104 ( V_6 , V_248 &
V_263 ) ;
V_19 = F_103 ( V_6 , V_258 ,
V_259 ) ;
V_19 = ( ! V_19 ) ? V_260 : V_253 ;
goto V_254;
}
V_87 = F_105 ( V_6 , V_6 -> V_264 ) ;
if ( ! V_87 ) {
F_13 ( V_33 L_45 ,
V_6 -> V_34 , V_35 ) ;
V_19 = V_253 ;
goto V_254;
}
if ( type == V_265 )
V_88 = & V_6 -> V_88 [ V_242 - 1 ] ;
F_106 ( V_6 , F_3 ( V_33
L_46 ,
V_6 -> V_34 , V_26 , type , V_242 ) ) ;
V_6 -> V_231 . V_232 = V_237 ;
V_247 = F_107 ( V_6 , V_87 ) ;
V_6 -> V_231 . V_87 = V_87 ;
memset ( V_247 , 0 , sizeof( T_17 ) ) ;
memset ( V_6 -> V_231 . V_230 , 0 , sizeof( T_18 ) ) ;
V_247 -> V_266 = V_267 ;
V_247 -> V_193 = F_108 ( V_26 ) ;
V_247 -> V_268 = type ;
V_247 -> V_269 = F_108 ( V_242 ) ;
F_109 ( V_94 , (struct V_270 * ) V_247 -> V_271 ) ;
F_96 ( V_6 , V_26 ) ;
F_110 ( & V_6 -> V_231 . V_238 ) ;
F_111 ( V_6 , V_87 ) ;
V_249 = F_112 ( & V_6 -> V_231 . V_238 , V_243 * V_272 ) ;
if ( ! ( V_6 -> V_231 . V_232 & V_234 ) ) {
F_13 ( V_33 L_47 ,
V_6 -> V_34 , V_35 ) ;
F_113 ( V_247 ,
sizeof( T_17 ) / 4 ) ;
if ( ! ( V_6 -> V_231 . V_232 & V_273 ) ) {
V_19 = F_103 ( V_6 , V_258 ,
V_259 ) ;
V_19 = ( ! V_19 ) ? V_260 : V_253 ;
V_6 -> V_231 . V_232 = V_233 ;
F_98 ( V_6 , V_26 ) ;
goto V_254;
}
}
if ( V_6 -> V_231 . V_232 & V_236 ) {
F_114 ( V_6 , V_274 ) ;
V_28 = V_6 -> V_231 . V_230 ;
F_106 ( V_6 , F_3 ( V_33 L_48 \
L_49 ,
V_6 -> V_34 , F_9 ( V_28 -> V_37 ) ,
F_66 ( V_28 -> V_275 ) ,
F_66 ( V_28 -> V_276 ) ) ) ;
if ( V_6 -> V_7 & V_277 ) {
F_91 ( V_6 , V_28 -> V_278 ) ;
if ( V_28 -> V_37 )
F_113 ( V_247 ,
sizeof( T_17 ) / 4 ) ;
}
}
switch ( type ) {
case V_265 :
V_19 = V_260 ;
if ( V_88 -> V_89 == NULL )
break;
V_19 = V_253 ;
break;
case V_279 :
if ( F_44 ( V_6 , V_71 , V_72 ) )
V_19 = V_253 ;
else
V_19 = V_260 ;
break;
case V_280 :
case V_281 :
if ( F_45 ( V_6 , V_71 , V_94 , V_72 ) )
V_19 = V_253 ;
else
V_19 = V_260 ;
break;
case V_282 :
V_19 = V_260 ;
break;
default:
V_19 = V_253 ;
break;
}
F_98 ( V_6 , V_26 ) ;
V_6 -> V_231 . V_232 = V_233 ;
if ( V_246 == V_251 )
F_115 ( & V_6 -> V_231 . V_252 ) ;
return V_19 ;
V_254:
if ( V_246 == V_251 )
F_115 ( & V_6 -> V_231 . V_252 ) ;
return V_19 ;
}
static void
F_116 ( struct V_5 * V_6 , struct V_86 * V_89 )
{
struct V_126 * V_69 = V_89 -> V_42 -> V_283 ;
struct V_104 * V_284 = V_69 -> V_107 ;
struct V_44 * V_45 = NULL ;
unsigned long V_63 ;
char * V_285 = NULL ;
if ( ! V_284 )
return;
V_285 = L_50 ;
F_117 ( V_89 ) ;
if ( V_284 -> V_63 & V_110 ) {
F_118 ( V_119 , V_69 ,
L_51 ,
V_285 , V_284 -> V_26 ,
V_285 , ( unsigned long long ) V_284 -> V_8 ) ;
} else {
F_19 ( & V_6 -> V_64 , V_63 ) ;
V_45 = F_16 ( V_6 ,
V_284 -> V_8 ) ;
if ( V_45 ) {
if ( V_284 -> V_63 &
V_137 ) {
F_118 ( V_119 , V_69 ,
L_52
L_53 ,
V_45 -> V_201 ,
( unsigned long long ) V_45 -> V_202 ) ;
}
F_118 ( V_119 , V_69 ,
L_54 ,
V_45 -> V_26 ,
( unsigned long long ) V_45 -> V_8 ,
V_45 -> V_211 ) ;
F_118 ( V_119 , V_69 ,
L_55 ,
( unsigned long long ) V_45 -> V_13 ,
V_45 -> V_17 ) ;
}
F_22 ( & V_6 -> V_64 , V_63 ) ;
}
}
static int
F_119 ( struct V_86 * V_89 )
{
struct V_5 * V_6 = F_47 ( V_89 -> V_42 -> V_100 ) ;
struct V_102 * V_103 ;
T_4 V_87 ;
T_4 V_26 ;
int V_73 ;
F_52 ( V_119 , V_89 -> V_42 ,
L_56 , V_89 ) ;
F_116 ( V_6 , V_89 ) ;
V_103 = V_89 -> V_42 -> V_107 ;
if ( ! V_103 || ! V_103 -> V_109 ) {
F_52 ( V_119 , V_89 -> V_42 ,
L_57 , V_89 ) ;
V_89 -> V_286 = V_287 << 16 ;
V_89 -> V_288 ( V_89 ) ;
V_73 = V_260 ;
goto V_74;
}
V_87 = F_43 ( V_6 , V_89 ) ;
if ( ! V_87 ) {
V_89 -> V_286 = V_289 << 16 ;
V_73 = V_260 ;
goto V_74;
}
if ( V_103 -> V_109 -> V_63 &
V_137 ||
V_103 -> V_109 -> V_63 & V_110 ) {
V_89 -> V_286 = V_289 << 16 ;
V_73 = V_253 ;
goto V_74;
}
F_120 ( V_6 ) ;
V_26 = V_103 -> V_109 -> V_26 ;
V_73 = F_99 ( V_6 , V_26 , V_89 -> V_42 -> V_72 ,
V_89 -> V_42 -> V_71 , V_89 -> V_42 -> V_94 ,
V_265 , V_87 , 30 ,
V_89 -> V_244 , V_251 ) ;
V_74:
F_52 ( V_119 , V_89 -> V_42 , L_58 ,
( ( V_73 == V_260 ) ? L_59 : L_60 ) , V_89 ) ;
return V_73 ;
}
static int
F_121 ( struct V_86 * V_89 )
{
struct V_5 * V_6 = F_47 ( V_89 -> V_42 -> V_100 ) ;
struct V_102 * V_103 ;
struct V_44 * V_45 ;
unsigned long V_63 ;
T_4 V_26 ;
int V_73 ;
F_52 ( V_119 , V_89 -> V_42 ,
L_61 , V_89 ) ;
F_116 ( V_6 , V_89 ) ;
V_103 = V_89 -> V_42 -> V_107 ;
if ( ! V_103 || ! V_103 -> V_109 ) {
F_52 ( V_119 , V_89 -> V_42 ,
L_57 , V_89 ) ;
V_89 -> V_286 = V_287 << 16 ;
V_89 -> V_288 ( V_89 ) ;
V_73 = V_260 ;
goto V_74;
}
V_26 = 0 ;
if ( V_103 -> V_109 -> V_63 &
V_137 ) {
F_19 ( & V_6 -> V_64 , V_63 ) ;
V_45 = F_17 ( V_6 ,
V_103 -> V_109 -> V_26 ) ;
if ( V_45 )
V_26 = V_45 -> V_201 ;
F_22 ( & V_6 -> V_64 , V_63 ) ;
} else
V_26 = V_103 -> V_109 -> V_26 ;
if ( ! V_26 ) {
V_89 -> V_286 = V_289 << 16 ;
V_73 = V_253 ;
goto V_74;
}
V_73 = F_99 ( V_6 , V_26 , V_89 -> V_42 -> V_72 ,
V_89 -> V_42 -> V_71 , V_89 -> V_42 -> V_94 ,
V_281 , 0 , 30 , 0 ,
V_251 ) ;
V_74:
F_52 ( V_119 , V_89 -> V_42 , L_62 ,
( ( V_73 == V_260 ) ? L_59 : L_60 ) , V_89 ) ;
return V_73 ;
}
static int
F_122 ( struct V_86 * V_89 )
{
struct V_5 * V_6 = F_47 ( V_89 -> V_42 -> V_100 ) ;
struct V_102 * V_103 ;
struct V_44 * V_45 ;
unsigned long V_63 ;
T_4 V_26 ;
int V_73 ;
struct V_126 * V_69 = V_89 -> V_42 -> V_283 ;
F_118 ( V_119 , V_69 , L_63 ,
V_89 ) ;
F_116 ( V_6 , V_89 ) ;
V_103 = V_89 -> V_42 -> V_107 ;
if ( ! V_103 || ! V_103 -> V_109 ) {
F_118 ( V_119 , V_69 , L_64 ,
V_89 ) ;
V_89 -> V_286 = V_287 << 16 ;
V_89 -> V_288 ( V_89 ) ;
V_73 = V_260 ;
goto V_74;
}
V_26 = 0 ;
if ( V_103 -> V_109 -> V_63 &
V_137 ) {
F_19 ( & V_6 -> V_64 , V_63 ) ;
V_45 = F_17 ( V_6 ,
V_103 -> V_109 -> V_26 ) ;
if ( V_45 )
V_26 = V_45 -> V_201 ;
F_22 ( & V_6 -> V_64 , V_63 ) ;
} else
V_26 = V_103 -> V_109 -> V_26 ;
if ( ! V_26 ) {
V_89 -> V_286 = V_289 << 16 ;
V_73 = V_253 ;
goto V_74;
}
V_73 = F_99 ( V_6 , V_26 , V_89 -> V_42 -> V_72 ,
V_89 -> V_42 -> V_71 , 0 , V_279 , 0 ,
30 , 0 , V_251 ) ;
V_74:
F_118 ( V_119 , V_69 , L_65 ,
( ( V_73 == V_260 ) ? L_59 : L_60 ) , V_89 ) ;
return V_73 ;
}
static int
F_123 ( struct V_86 * V_89 )
{
struct V_5 * V_6 = F_47 ( V_89 -> V_42 -> V_100 ) ;
int V_73 , V_290 ;
F_3 ( V_33 L_66 ,
V_6 -> V_34 , V_89 ) ;
F_117 ( V_89 ) ;
V_290 = F_103 ( V_6 , V_258 ,
V_259 ) ;
V_73 = ( V_290 < 0 ) ? V_253 : V_260 ;
F_3 ( V_33 L_67 ,
V_6 -> V_34 , ( ( V_73 == V_260 ) ? L_59 : L_60 ) , V_89 ) ;
return V_73 ;
}
static void
F_124 ( struct V_5 * V_6 , struct V_291 * V_292 )
{
unsigned long V_63 ;
if ( V_6 -> V_293 == NULL )
return;
F_19 ( & V_6 -> V_294 , V_63 ) ;
F_125 ( & V_292 -> V_65 ) ;
F_28 ( & V_292 -> V_65 , & V_6 -> V_295 ) ;
F_126 ( & V_292 -> V_296 , V_297 ) ;
F_127 ( V_6 -> V_293 , & V_292 -> V_296 ) ;
F_22 ( & V_6 -> V_294 , V_63 ) ;
}
static void
F_128 ( struct V_5 * V_6 , struct V_291
* V_292 )
{
unsigned long V_63 ;
F_19 ( & V_6 -> V_294 , V_63 ) ;
F_20 ( & V_292 -> V_65 ) ;
F_21 ( V_292 -> V_298 ) ;
F_21 ( V_292 ) ;
F_22 ( & V_6 -> V_294 , V_63 ) ;
}
void
F_129 ( struct V_5 * V_6 ,
struct V_299 * V_298 )
{
struct V_291 * V_292 ;
if ( V_6 -> V_48 )
return;
V_292 = F_59 ( sizeof( struct V_291 ) , V_300 ) ;
if ( ! V_292 )
return;
V_292 -> V_298 = F_59 ( sizeof( * V_298 ) , V_300 ) ;
if ( ! V_292 -> V_298 )
return;
V_292 -> V_301 = V_302 ;
V_292 -> V_6 = V_6 ;
memcpy ( V_292 -> V_298 , V_298 , sizeof( * V_298 ) ) ;
F_124 ( V_6 , V_292 ) ;
}
static void
F_130 ( struct V_5 * V_6 )
{
struct V_291 * V_292 ;
if ( V_6 -> V_48 )
return;
V_292 = F_59 ( sizeof( struct V_291 ) , V_300 ) ;
if ( ! V_292 )
return;
V_292 -> V_301 = V_303 ;
V_292 -> V_6 = V_6 ;
F_124 ( V_6 , V_292 ) ;
}
void
F_131 ( struct V_5 * V_6 )
{
struct V_291 * V_292 ;
V_292 = F_59 ( sizeof( struct V_291 ) , V_300 ) ;
if ( ! V_292 )
return;
V_292 -> V_301 = V_304 ;
V_292 -> V_6 = V_6 ;
F_124 ( V_6 , V_292 ) ;
}
static void
F_132 ( struct V_5 * V_6 )
{
struct V_291 * V_292 , * V_305 ;
if ( F_133 ( & V_6 -> V_295 ) ||
! V_6 -> V_293 || F_134 () )
return;
F_135 (fw_event, next, &ioc->fw_event_list, list) {
if ( F_136 ( & V_292 -> V_306 ) ) {
F_128 ( V_6 , V_292 ) ;
continue;
}
V_292 -> V_307 = 1 ;
}
}
static void
F_137 ( struct V_5 * V_6 )
{
struct V_102 * V_103 ;
struct V_95 * V_96 ;
F_97 (sdev, ioc->shost) {
V_103 = V_96 -> V_107 ;
if ( ! V_103 )
continue;
if ( ! V_103 -> V_308 )
continue;
V_103 -> V_308 = 0 ;
F_27 ( V_6 , F_52 ( V_119 , V_96 ,
L_68 ,
V_103 -> V_109 -> V_26 ) ) ;
F_138 ( V_96 , V_309 ) ;
}
}
static void
F_139 ( struct V_5 * V_6 , T_1 V_8 )
{
struct V_102 * V_103 ;
struct V_95 * V_96 ;
F_97 (sdev, ioc->shost) {
V_103 = V_96 -> V_107 ;
if ( ! V_103 )
continue;
if ( V_103 -> V_109 -> V_8
!= V_8 )
continue;
if ( V_103 -> V_308 ) {
V_103 -> V_308 = 0 ;
F_138 ( V_96 , V_309 ) ;
}
}
}
static void
F_140 ( struct V_5 * V_6 )
{
struct V_102 * V_103 ;
struct V_95 * V_96 ;
F_97 (sdev, ioc->shost) {
V_103 = V_96 -> V_107 ;
if ( ! V_103 )
continue;
if ( V_103 -> V_308 )
continue;
V_103 -> V_308 = 1 ;
F_141 ( V_96 ) ;
F_52 ( V_119 , V_96 , L_69 ,
V_103 -> V_109 -> V_26 ) ;
}
}
static void
F_142 ( struct V_5 * V_6 , T_4 V_26 )
{
struct V_102 * V_103 ;
struct V_95 * V_96 ;
F_97 (sdev, ioc->shost) {
V_103 = V_96 -> V_107 ;
if ( ! V_103 )
continue;
if ( V_103 -> V_109 -> V_26 != V_26 )
continue;
if ( V_103 -> V_308 )
continue;
V_103 -> V_308 = 1 ;
F_141 ( V_96 ) ;
F_52 ( V_119 , V_96 ,
L_69 , V_26 ) ;
}
}
static void
F_143 ( struct V_5 * V_6 ,
struct V_77 * V_78 )
{
struct V_310 * V_311 ;
struct V_44 * V_45 ;
struct V_77 * V_312 ;
unsigned long V_63 ;
if ( ! V_78 )
return;
F_4 (mpt3sas_port,
&sas_expander->sas_port_list, port_list) {
if ( V_311 -> V_313 . V_314 ==
V_315 ) {
F_19 ( & V_6 -> V_64 , V_63 ) ;
V_45 =
F_16 ( V_6 ,
V_311 -> V_313 . V_8 ) ;
if ( V_45 )
F_144 ( V_45 -> V_26 ,
V_6 -> V_316 ) ;
F_22 ( & V_6 -> V_64 , V_63 ) ;
}
}
F_4 (mpt3sas_port,
&sas_expander->sas_port_list, port_list) {
if ( V_311 -> V_313 . V_314 ==
V_317 ||
V_311 -> V_313 . V_314 ==
V_318 ) {
V_312 =
F_38 (
V_6 , V_311 -> V_313 . V_8 ) ;
F_143 ( V_6 ,
V_312 ) ;
}
}
}
static void
F_145 ( struct V_5 * V_6 ,
T_19 * V_298 )
{
int V_91 ;
T_4 V_26 ;
T_4 V_319 ;
for ( V_91 = 0 ; V_91 < V_298 -> V_320 ; V_91 ++ ) {
V_26 = F_9 ( V_298 -> V_321 [ V_91 ] . V_322 ) ;
if ( ! V_26 )
continue;
V_319 = V_298 -> V_321 [ V_91 ] . V_323 &
V_324 ;
if ( V_319 == V_325 )
F_142 ( V_6 , V_26 ) ;
}
}
static void
F_146 ( struct V_5 * V_6 , T_4 V_26 )
{
T_17 * V_247 ;
T_4 V_87 ;
struct V_44 * V_45 ;
struct V_104 * V_105 = NULL ;
T_1 V_8 = 0 ;
unsigned long V_63 ;
struct V_326 * V_327 ;
T_10 V_248 ;
if ( V_6 -> V_255 ) {
F_27 ( V_6 , F_3 ( V_33
L_70 ,
V_35 , V_6 -> V_34 , V_26 ) ) ;
return;
} else if ( V_6 -> V_256 ) {
F_27 ( V_6 , F_3 ( V_33
L_71 ,
V_35 , V_6 -> V_34 ,
V_26 ) ) ;
return;
}
V_248 = F_101 ( V_6 , 1 ) ;
if ( V_248 != V_328 ) {
F_27 ( V_6 , F_3 ( V_33
L_72 ,
V_35 , V_6 -> V_34 ,
V_26 ) ) ;
return;
}
if ( F_61 ( V_26 , V_6 -> V_136 ) )
return;
F_19 ( & V_6 -> V_64 , V_63 ) ;
V_45 = F_17 ( V_6 , V_26 ) ;
if ( V_45 && V_45 -> V_69 &&
V_45 -> V_69 -> V_107 ) {
V_105 = V_45 -> V_69 -> V_107 ;
V_105 -> V_329 = 1 ;
V_8 = V_45 -> V_8 ;
}
F_22 ( & V_6 -> V_64 , V_63 ) ;
if ( V_105 ) {
F_27 ( V_6 , F_3 ( V_33
L_73 ,
V_6 -> V_34 , V_26 ,
( unsigned long long ) V_8 ) ) ;
F_139 ( V_6 , V_8 ) ;
V_105 -> V_26 = V_132 ;
}
V_87 = F_105 ( V_6 , V_6 -> V_330 ) ;
if ( ! V_87 ) {
V_327 = F_59 ( sizeof( * V_327 ) , V_300 ) ;
if ( ! V_327 )
return;
F_125 ( & V_327 -> V_65 ) ;
V_327 -> V_26 = V_26 ;
F_28 ( & V_327 -> V_65 , & V_6 -> V_331 ) ;
F_27 ( V_6 , F_3 ( V_33
L_74 ,
V_6 -> V_34 , V_26 ) ) ;
return;
}
F_27 ( V_6 , F_3 ( V_33
L_75 ,
V_6 -> V_34 , V_26 , V_87 ,
V_6 -> V_330 ) ) ;
V_247 = F_107 ( V_6 , V_87 ) ;
memset ( V_247 , 0 , sizeof( T_17 ) ) ;
V_247 -> V_266 = V_267 ;
V_247 -> V_193 = F_108 ( V_26 ) ;
V_247 -> V_268 = V_279 ;
F_111 ( V_6 , V_87 ) ;
F_114 ( V_6 , V_332 ) ;
}
static T_6
F_147 ( struct V_5 * V_6 , T_4 V_87 , T_6 V_229 ,
T_10 V_230 )
{
T_4 V_26 ;
T_17 * V_333 ;
T_18 * V_28 =
F_94 ( V_6 , V_230 ) ;
T_20 * V_247 ;
T_4 V_334 ;
T_10 V_248 ;
if ( V_6 -> V_255 ) {
F_27 ( V_6 , F_3 ( V_33
L_76 , V_35 , V_6 -> V_34 ) ) ;
return 1 ;
} else if ( V_6 -> V_256 ) {
F_27 ( V_6 , F_3 ( V_33
L_77 , V_35 ,
V_6 -> V_34 ) ) ;
return 1 ;
}
V_248 = F_101 ( V_6 , 1 ) ;
if ( V_248 != V_328 ) {
F_27 ( V_6 , F_3 ( V_33
L_78 , V_35 , V_6 -> V_34 ) ) ;
return 1 ;
}
if ( F_148 ( ! V_28 ) ) {
F_13 ( V_33 L_79 ,
V_6 -> V_34 , __FILE__ , __LINE__ , V_35 ) ;
return 1 ;
}
V_333 = F_107 ( V_6 , V_87 ) ;
V_26 = F_9 ( V_333 -> V_193 ) ;
if ( V_26 != F_9 ( V_28 -> V_193 ) ) {
F_27 ( V_6 , F_13 ( V_33
L_80 ,
V_6 -> V_34 , V_26 ,
F_9 ( V_28 -> V_193 ) , V_87 ) ) ;
return 0 ;
}
F_114 ( V_6 , V_274 ) ;
F_27 ( V_6 , F_3 ( V_33
L_81
L_82 , V_6 -> V_34 ,
V_26 , V_87 , F_9 ( V_28 -> V_37 ) ,
F_66 ( V_28 -> V_275 ) ,
F_66 ( V_28 -> V_276 ) ) ) ;
V_334 = F_149 ( V_6 , V_6 -> V_335 ) ;
if ( ! V_334 ) {
F_13 ( V_33 L_45 ,
V_6 -> V_34 , V_35 ) ;
return 1 ;
}
F_27 ( V_6 , F_3 ( V_33
L_83 ,
V_6 -> V_34 , V_26 , V_334 ,
V_6 -> V_335 ) ) ;
V_247 = F_107 ( V_6 , V_334 ) ;
memset ( V_247 , 0 , sizeof( T_20 ) ) ;
V_247 -> V_266 = V_336 ;
V_247 -> V_337 = V_338 ;
V_247 -> V_193 = V_333 -> V_193 ;
F_150 ( V_6 , V_334 ) ;
return F_151 ( V_6 , V_87 ) ;
}
static T_6
F_152 ( struct V_5 * V_6 , T_4 V_87 ,
T_6 V_229 , T_10 V_230 )
{
T_21 * V_28 =
F_94 ( V_6 , V_230 ) ;
if ( F_153 ( V_28 ) ) {
F_27 ( V_6 , F_3 ( V_33
L_84
L_85 ,
V_6 -> V_34 , F_9 ( V_28 -> V_193 ) , V_87 ,
F_9 ( V_28 -> V_37 ) ,
F_66 ( V_28 -> V_275 ) ) ) ;
} else {
F_13 ( V_33 L_79 ,
V_6 -> V_34 , __FILE__ , __LINE__ , V_35 ) ;
}
return 1 ;
}
static void
F_154 ( struct V_5 * V_6 , T_4 V_26 )
{
T_17 * V_247 ;
T_4 V_87 ;
struct V_326 * V_327 ;
if ( V_6 -> V_66 || V_6 -> V_255 ||
V_6 -> V_256 ) {
F_27 ( V_6 , F_3 ( V_33
L_43 ,
V_35 , V_6 -> V_34 ) ) ;
return;
}
V_87 = F_105 ( V_6 , V_6 -> V_339 ) ;
if ( ! V_87 ) {
V_327 = F_59 ( sizeof( * V_327 ) , V_300 ) ;
if ( ! V_327 )
return;
F_125 ( & V_327 -> V_65 ) ;
V_327 -> V_26 = V_26 ;
F_28 ( & V_327 -> V_65 , & V_6 -> V_340 ) ;
F_27 ( V_6 , F_3 ( V_33
L_74 ,
V_6 -> V_34 , V_26 ) ) ;
return;
}
F_27 ( V_6 , F_3 ( V_33
L_75 ,
V_6 -> V_34 , V_26 , V_87 ,
V_6 -> V_339 ) ) ;
V_247 = F_107 ( V_6 , V_87 ) ;
memset ( V_247 , 0 , sizeof( T_17 ) ) ;
V_247 -> V_266 = V_267 ;
V_247 -> V_193 = F_108 ( V_26 ) ;
V_247 -> V_268 = V_279 ;
F_111 ( V_6 , V_87 ) ;
}
static T_6
F_155 ( struct V_5 * V_6 , T_4 V_87 ,
T_6 V_229 , T_10 V_230 )
{
T_4 V_26 ;
T_17 * V_333 ;
T_18 * V_28 =
F_94 ( V_6 , V_230 ) ;
if ( V_6 -> V_66 || V_6 -> V_255 ||
V_6 -> V_256 ) {
F_27 ( V_6 , F_3 ( V_33
L_43 ,
V_35 , V_6 -> V_34 ) ) ;
return 1 ;
}
if ( F_148 ( ! V_28 ) ) {
F_13 ( V_33 L_79 ,
V_6 -> V_34 , __FILE__ , __LINE__ , V_35 ) ;
return 1 ;
}
V_333 = F_107 ( V_6 , V_87 ) ;
V_26 = F_9 ( V_333 -> V_193 ) ;
if ( V_26 != F_9 ( V_28 -> V_193 ) ) {
F_27 ( V_6 , F_13 ( V_33
L_80 ,
V_6 -> V_34 , V_26 ,
F_9 ( V_28 -> V_193 ) , V_87 ) ) ;
return 0 ;
}
F_27 ( V_6 , F_3 ( V_33
L_81
L_82 , V_6 -> V_34 ,
V_26 , V_87 , F_9 ( V_28 -> V_37 ) ,
F_66 ( V_28 -> V_275 ) ,
F_66 ( V_28 -> V_276 ) ) ) ;
return F_151 ( V_6 , V_87 ) ;
}
static T_6
F_151 ( struct V_5 * V_6 , T_4 V_87 )
{
struct V_326 * V_327 ;
if ( ! F_133 ( & V_6 -> V_340 ) ) {
V_327 = F_156 ( V_6 -> V_340 . V_305 ,
struct V_326 , V_65 ) ;
F_157 ( V_6 , V_87 ) ;
F_154 ( V_6 , V_327 -> V_26 ) ;
F_20 ( & V_327 -> V_65 ) ;
F_21 ( V_327 ) ;
return 0 ;
}
if ( ! F_133 ( & V_6 -> V_331 ) ) {
V_327 = F_156 ( V_6 -> V_331 . V_305 ,
struct V_326 , V_65 ) ;
F_157 ( V_6 , V_87 ) ;
F_146 ( V_6 , V_327 -> V_26 ) ;
F_20 ( & V_327 -> V_65 ) ;
F_21 ( V_327 ) ;
return 0 ;
}
return 1 ;
}
static void
F_158 ( struct V_5 * V_6 ,
T_19 * V_298 )
{
struct V_291 * V_292 ;
T_19 * V_341 ;
T_4 V_342 ;
struct V_77 * V_78 ;
unsigned long V_63 ;
int V_91 , V_319 ;
T_4 V_26 ;
for ( V_91 = 0 ; V_91 < V_298 -> V_320 ; V_91 ++ ) {
V_26 = F_9 ( V_298 -> V_321 [ V_91 ] . V_322 ) ;
if ( ! V_26 )
continue;
V_319 = V_298 -> V_321 [ V_91 ] . V_323 &
V_324 ;
if ( V_319 == V_343 )
F_146 ( V_6 , V_26 ) ;
}
V_342 = F_9 ( V_298 -> V_344 ) ;
if ( V_342 < V_6 -> V_30 . V_31 ) {
F_145 ( V_6 , V_298 ) ;
return;
}
if ( V_298 -> V_345 ==
V_346 ) {
F_19 ( & V_6 -> V_79 , V_63 ) ;
V_78 = F_37 ( V_6 ,
V_342 ) ;
F_143 ( V_6 , V_78 ) ;
F_22 ( & V_6 -> V_79 , V_63 ) ;
do {
V_26 = F_159 ( V_6 -> V_316 ,
V_6 -> V_195 . V_347 ) ;
if ( V_26 < V_6 -> V_195 . V_347 )
F_142 ( V_6 , V_26 ) ;
} while ( F_160 ( V_26 , V_6 -> V_316 ) );
} else if ( V_298 -> V_345 == V_348 )
F_145 ( V_6 , V_298 ) ;
if ( V_298 -> V_345 != V_349 )
return;
F_19 ( & V_6 -> V_294 , V_63 ) ;
F_4 (fw_event, &ioc->fw_event_list, list) {
if ( V_292 -> V_301 != V_350 ||
V_292 -> V_351 )
continue;
V_341 = V_292 -> V_298 ;
if ( V_341 -> V_345 ==
V_352 ||
V_341 -> V_345 ==
V_348 ) {
if ( F_9 ( V_341 -> V_344 ) ==
V_342 ) {
F_27 ( V_6 , F_3 ( V_33
L_86 , V_6 -> V_34 ) ) ;
V_292 -> V_351 = 1 ;
}
}
}
F_22 ( & V_6 -> V_294 , V_63 ) ;
}
static void
F_161 ( struct V_5 * V_6 , T_4 V_26 )
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
V_105 -> V_329 = 1 ;
F_27 ( V_6 , F_3 ( V_33
L_87
L_88 , V_6 -> V_34 , V_26 ,
( unsigned long long ) V_47 -> V_51 ) ) ;
}
F_22 ( & V_6 -> V_75 , V_63 ) ;
}
static void
F_162 ( T_4 V_26 , T_4 * V_353 , T_4 * V_354 )
{
if ( ! V_26 || V_26 == * V_353 || V_26 == * V_354 )
return;
if ( ! * V_353 )
* V_353 = V_26 ;
else if ( ! * V_354 )
* V_354 = V_26 ;
}
static void
F_163 ( struct V_5 * V_6 ,
T_22 * V_298 )
{
T_23 * V_355 ;
int V_91 ;
T_4 V_26 , V_201 , V_353 , V_354 ;
struct V_326 * V_327 ;
V_353 = 0 ;
V_354 = 0 ;
V_355 = ( T_23 * ) & V_298 -> V_356 [ 0 ] ;
for ( V_91 = 0 ; V_91 < V_298 -> V_357 ; V_91 ++ , V_355 ++ ) {
if ( F_66 ( V_298 -> V_143 ) &
V_358 )
continue;
if ( V_355 -> V_359 ==
V_360 ||
V_355 -> V_359 ==
V_361 ) {
V_201 = F_9 ( V_355 -> V_362 ) ;
F_161 ( V_6 , V_201 ) ;
F_162 ( V_201 , & V_353 , & V_354 ) ;
}
}
V_355 = ( T_23 * ) & V_298 -> V_356 [ 0 ] ;
for ( V_91 = 0 ; V_91 < V_298 -> V_357 ; V_91 ++ , V_355 ++ ) {
if ( F_66 ( V_298 -> V_143 ) &
V_358 )
continue;
if ( V_355 -> V_359 == V_363 ) {
V_201 = F_9 ( V_355 -> V_362 ) ;
F_162 ( V_201 , & V_353 , & V_354 ) ;
}
}
if ( V_353 )
F_154 ( V_6 , V_353 ) ;
if ( V_354 )
F_154 ( V_6 , V_354 ) ;
V_355 = ( T_23 * ) & V_298 -> V_356 [ 0 ] ;
for ( V_91 = 0 ; V_91 < V_298 -> V_357 ; V_91 ++ , V_355 ++ ) {
if ( V_355 -> V_359 != V_363 )
continue;
V_26 = F_9 ( V_355 -> V_364 ) ;
V_201 = F_9 ( V_355 -> V_362 ) ;
F_164 ( V_26 , V_6 -> V_136 ) ;
if ( ! V_201 )
F_146 ( V_6 , V_26 ) ;
else if ( V_201 == V_353 || V_201 == V_354 ) {
V_327 = F_59 ( sizeof( * V_327 ) , V_300 ) ;
F_165 ( ! V_327 ) ;
F_125 ( & V_327 -> V_65 ) ;
V_327 -> V_26 = V_26 ;
F_28 ( & V_327 -> V_65 , & V_6 -> V_331 ) ;
F_27 ( V_6 , F_3 ( V_33
L_74 , V_6 -> V_34 ,
V_26 ) ) ;
} else
F_146 ( V_6 , V_26 ) ;
}
}
static void
F_166 ( struct V_5 * V_6 ,
T_24 * V_298 )
{
T_10 V_160 ;
if ( V_298 -> V_359 != V_365 )
return;
V_160 = F_66 ( V_298 -> V_366 ) ;
if ( V_160 == V_170 || V_160 ==
V_169 )
F_161 ( V_6 ,
F_9 ( V_298 -> V_362 ) ) ;
}
static void
F_167 ( struct V_5 * V_6 )
{
struct V_86 * V_89 ;
T_4 V_87 ;
T_4 V_367 = 0 ;
for ( V_87 = 1 ; V_87 <= V_6 -> V_92 ; V_87 ++ ) {
V_89 = F_42 ( V_6 , V_87 ) ;
if ( ! V_89 )
continue;
V_367 ++ ;
F_157 ( V_6 , V_87 ) ;
F_168 ( V_89 ) ;
if ( V_6 -> V_256 )
V_89 -> V_286 = V_287 << 16 ;
else
V_89 -> V_286 = V_289 << 16 ;
V_89 -> V_288 ( V_89 ) ;
}
F_106 ( V_6 , F_3 ( V_33 L_89 ,
V_6 -> V_34 , V_367 ) ) ;
}
static void
F_169 ( struct V_5 * V_6 , struct V_86 * V_89 ,
T_25 * V_247 )
{
T_4 V_368 ;
unsigned char V_369 = F_170 ( V_89 ) ;
unsigned char V_370 = F_171 ( V_89 ) ;
T_26 * V_371 =
( T_26 * ) V_247 ;
if ( V_370 == V_372 || V_369 == V_373 )
return;
if ( V_369 == V_374 )
V_368 = V_375 ;
else if ( V_369 == V_376 )
V_368 = V_377 ;
else
return;
switch ( V_370 ) {
case V_378 :
case V_379 :
V_368 |= V_380 |
V_381 |
V_382 ;
V_247 -> V_383 . V_384 . V_385 =
F_172 ( F_173 ( V_89 ) ) ;
break;
case V_386 :
V_368 |= V_382 ;
break;
}
V_371 -> V_387 =
F_108 ( V_89 -> V_42 -> V_388 ) ;
V_247 -> V_389 = F_108 ( V_368 ) ;
}
static void
F_174 ( struct V_86 * V_89 , T_4 V_29 )
{
T_6 V_390 ;
switch ( V_29 ) {
case V_391 :
V_390 = 0x01 ;
break;
case V_392 :
V_390 = 0x02 ;
break;
case V_393 :
V_390 = 0x03 ;
break;
default:
V_390 = 0x00 ;
break;
}
F_175 ( 0 , V_89 -> V_394 , V_395 , 0x10 ,
V_390 ) ;
V_89 -> V_286 = V_396 << 24 | ( V_397 << 16 ) |
V_398 ;
}
static int
F_176 ( struct V_86 * V_89 , void (* V_238)( struct V_86 * ) )
{
struct V_5 * V_6 = F_47 ( V_89 -> V_42 -> V_100 ) ;
struct V_102 * V_103 ;
struct V_104 * V_105 ;
T_25 * V_247 ;
T_10 V_399 ;
T_4 V_87 ;
T_4 V_26 ;
#ifdef F_177
if ( V_6 -> V_7 & V_400 )
F_117 ( V_89 ) ;
#endif
V_89 -> V_288 = V_238 ;
V_103 = V_89 -> V_42 -> V_107 ;
if ( ! V_103 || ! V_103 -> V_109 ) {
V_89 -> V_286 = V_287 << 16 ;
V_89 -> V_288 ( V_89 ) ;
return 0 ;
}
if ( V_6 -> V_256 || V_6 -> V_255 ) {
V_89 -> V_286 = V_287 << 16 ;
V_89 -> V_288 ( V_89 ) ;
return 0 ;
}
V_105 = V_103 -> V_109 ;
V_26 = V_105 -> V_26 ;
if ( V_26 == V_132 ) {
V_89 -> V_286 = V_287 << 16 ;
V_89 -> V_288 ( V_89 ) ;
return 0 ;
}
if ( V_6 -> V_66 || V_6 -> V_401 )
return V_402 ;
else if ( V_105 -> V_329 ) {
V_89 -> V_286 = V_287 << 16 ;
V_89 -> V_288 ( V_89 ) ;
return 0 ;
} else if ( V_105 -> V_240 ||
V_103 -> V_308 )
return V_403 ;
if ( V_89 -> V_404 == V_405 )
V_399 = V_406 ;
else if ( V_89 -> V_404 == V_407 )
V_399 = V_408 ;
else
V_399 = V_409 ;
if ( ! ( V_103 -> V_63 & V_140 ) ) {
if ( V_89 -> V_42 -> V_112 ) {
if ( V_89 -> V_42 -> V_122 )
V_399 |= V_410 ;
else
V_399 |= V_411 ;
} else
V_399 |= V_411 ;
} else
V_399 |= V_411 ;
if ( ( V_103 -> V_63 & V_412 ) &&
V_89 -> V_413 != 32 )
V_399 |= V_414 ;
V_87 = F_178 ( V_6 , V_6 -> V_415 , V_89 ) ;
if ( ! V_87 ) {
F_13 ( V_33 L_45 ,
V_6 -> V_34 , V_35 ) ;
goto V_74;
}
V_247 = F_107 ( V_6 , V_87 ) ;
memset ( V_247 , 0 , sizeof( T_25 ) ) ;
F_169 ( V_6 , V_89 , V_247 ) ;
if ( V_89 -> V_413 == 32 )
V_399 |= 4 << V_416 ;
V_247 -> V_266 = V_417 ;
if ( V_103 -> V_109 -> V_63 &
V_137 )
V_247 -> V_266 = V_418 ;
else
V_247 -> V_266 = V_417 ;
V_247 -> V_193 = F_108 ( V_26 ) ;
V_247 -> V_419 = F_179 ( F_180 ( V_89 ) ) ;
V_247 -> V_420 = F_179 ( V_399 ) ;
V_247 -> V_421 = F_108 ( V_89 -> V_413 ) ;
V_247 -> V_422 = V_423 ;
V_247 -> V_424 = V_425 ;
V_247 -> V_426 =
F_181 ( V_6 , V_87 ) ;
V_247 -> V_427 = F_80 ( T_25 , V_428 ) / 4 ;
F_109 ( V_103 -> V_94 , (struct V_270 * )
V_247 -> V_271 ) ;
memcpy ( V_247 -> V_383 . V_429 , V_89 -> V_430 , V_89 -> V_413 ) ;
if ( V_247 -> V_419 ) {
if ( V_6 -> V_431 ( V_6 , V_89 , V_87 ) ) {
F_157 ( V_6 , V_87 ) ;
goto V_74;
}
} else
V_6 -> V_432 ( V_6 , & V_247 -> V_428 ) ;
if ( F_153 ( V_247 -> V_266 == V_417 ) ) {
if ( V_105 -> V_63 & V_139 ) {
V_247 -> V_421 = F_108 ( V_89 -> V_413 |
V_433 ) ;
F_182 ( V_6 , V_87 , V_26 ) ;
} else
F_183 ( V_6 , V_87 , V_26 ) ;
} else
F_150 ( V_6 , V_87 ) ;
return 0 ;
V_74:
return V_402 ;
}
void
F_184 ( struct V_5 * V_6 , struct V_86 * V_89 ,
T_27 * V_28 , T_4 V_87 )
{
T_10 V_434 ;
T_6 * V_435 ;
T_4 V_29 = F_9 ( V_28 -> V_37 ) &
V_38 ;
T_6 V_436 = V_28 -> V_437 ;
T_6 V_438 = V_28 -> V_439 ;
char * V_440 = NULL ;
char * V_441 = NULL ;
char * V_442 = V_6 -> V_443 ;
T_10 V_444 = F_66 ( V_28 -> V_275 ) ;
struct V_44 * V_45 = NULL ;
unsigned long V_63 ;
struct V_126 * V_69 = V_89 -> V_42 -> V_283 ;
struct V_104 * V_284 = V_69 -> V_107 ;
char * V_285 = NULL ;
if ( ! V_284 )
return;
V_285 = L_50 ;
if ( V_444 == 0x31170000 )
return;
switch ( V_29 ) {
case V_39 :
V_440 = L_90 ;
break;
case V_445 :
V_440 = L_91 ;
break;
case V_446 :
V_440 = L_92 ;
break;
case V_447 :
V_440 = L_93 ;
break;
case V_448 :
V_440 = L_94 ;
break;
case V_449 :
V_440 = L_95 ;
break;
case V_450 :
V_440 = L_96 ;
break;
case V_451 :
V_440 = L_97 ;
break;
case V_452 :
V_440 = L_98 ;
break;
case V_453 :
V_440 = L_99 ;
break;
case V_454 :
V_440 = L_100 ;
break;
case V_455 :
V_440 = L_101 ;
break;
case V_456 :
V_440 = L_102 ;
break;
case V_457 :
V_440 = L_103 ;
break;
case V_391 :
V_440 = L_104 ;
break;
case V_393 :
V_440 = L_105 ;
break;
case V_392 :
V_440 = L_106 ;
break;
default:
V_440 = L_40 ;
break;
}
switch ( V_438 ) {
case V_458 :
V_441 = L_107 ;
break;
case V_459 :
V_441 = L_108 ;
break;
case V_460 :
V_441 = L_109 ;
break;
case V_461 :
V_441 = L_110 ;
break;
case V_462 :
V_441 = L_111 ;
break;
case V_463 :
V_441 = L_112 ;
break;
case V_464 :
V_441 = L_113 ;
break;
case V_465 :
V_441 = L_114 ;
break;
case V_466 :
V_441 = L_115 ;
break;
case V_467 :
V_441 = L_116 ;
break;
case V_468 :
V_441 = L_117 ;
break;
default:
V_441 = L_40 ;
break;
}
V_442 [ 0 ] = '\0' ;
if ( ! V_436 )
V_442 = L_118 ;
if ( V_436 & V_469 )
strcat ( V_442 , L_119 ) ;
if ( V_436 & V_470 )
strcat ( V_442 , L_120 ) ;
if ( V_436 & V_471 )
strcat ( V_442 , L_121 ) ;
if ( V_436 & V_472 )
strcat ( V_442 , L_122 ) ;
if ( V_436 & V_473 )
strcat ( V_442 , L_123 ) ;
F_117 ( V_89 ) ;
if ( V_284 -> V_63 & V_110 ) {
F_79 ( V_33 L_124 , V_6 -> V_34 ,
V_285 , ( unsigned long long ) V_284 -> V_8 ) ;
} else {
F_19 ( & V_6 -> V_64 , V_63 ) ;
V_45 = F_16 ( V_6 ,
V_284 -> V_8 ) ;
if ( V_45 ) {
F_79 ( V_33
L_125 ,
V_6 -> V_34 , ( unsigned long long )
V_45 -> V_8 , V_45 -> V_211 ) ;
F_79 ( V_33
L_126 ,
V_6 -> V_34 , ( unsigned long long )
V_45 -> V_13 , V_45 -> V_17 ) ;
}
F_22 ( & V_6 -> V_64 , V_63 ) ;
}
F_79 ( V_33
L_127 ,
V_6 -> V_34 , F_9 ( V_28 -> V_193 ) ,
V_440 , V_29 , V_87 ) ;
F_79 ( V_33
L_128 ,
V_6 -> V_34 , F_180 ( V_89 ) , V_89 -> V_474 ,
F_185 ( V_89 ) ) ;
F_79 ( V_33
L_129 ,
V_6 -> V_34 , F_9 ( V_28 -> V_475 ) ,
F_66 ( V_28 -> V_476 ) , V_89 -> V_286 ) ;
F_79 ( V_33
L_130 ,
V_6 -> V_34 , V_441 ,
V_438 , V_442 , V_436 ) ;
if ( V_436 & V_473 ) {
struct V_477 V_478 ;
F_186 ( V_89 -> V_394 , & V_478 ) ;
F_79 ( V_33
L_131 ,
V_6 -> V_34 , V_478 . V_479 ,
V_478 . V_480 , V_478 . V_390 , F_66 ( V_28 -> V_481 ) ) ;
}
if ( V_436 & V_469 ) {
V_434 = F_66 ( V_28 -> V_482 ) ;
V_435 = ( T_6 * ) & V_434 ;
F_91 ( V_6 , V_435 [ 0 ] ) ;
}
}
static void
F_187 ( struct V_5 * V_6 , T_4 V_26 )
{
T_28 V_28 ;
T_29 V_247 ;
memset ( & V_247 , 0 , sizeof( T_29 ) ) ;
V_247 . V_266 = V_483 ;
V_247 . V_484 = V_485 ;
V_247 . V_486 =
F_179 ( V_487 ) ;
V_247 . V_193 = F_108 ( V_26 ) ;
V_247 . V_143 = V_488 ;
if ( ( F_188 ( V_6 , & V_28 ,
& V_247 ) ) != 0 ) {
F_13 ( V_33 L_2 , V_6 -> V_34 ,
__FILE__ , __LINE__ , V_35 ) ;
return;
}
if ( V_28 . V_37 || V_28 . V_275 ) {
F_27 ( V_6 , F_3 ( V_33
L_132 ,
V_6 -> V_34 , F_9 ( V_28 . V_37 ) ,
F_66 ( V_28 . V_275 ) ) ) ;
return;
}
}
static void
F_189 ( struct V_5 * V_6 , T_4 V_26 )
{
struct V_291 * V_292 ;
V_292 = F_59 ( sizeof( struct V_291 ) , V_300 ) ;
if ( ! V_292 )
return;
V_292 -> V_301 = V_489 ;
V_292 -> V_490 = V_26 ;
V_292 -> V_6 = V_6 ;
F_124 ( V_6 , V_292 ) ;
}
static void
F_190 ( struct V_5 * V_6 , T_4 V_26 )
{
struct V_126 * V_69 ;
struct V_104 * V_105 ;
T_30 * V_491 ;
T_31 * V_298 ;
struct V_44 * V_45 ;
T_32 V_186 ;
unsigned long V_63 ;
F_19 ( & V_6 -> V_64 , V_63 ) ;
V_45 = F_17 ( V_6 , V_26 ) ;
if ( ! V_45 ) {
F_22 ( & V_6 -> V_64 , V_63 ) ;
return;
}
V_69 = V_45 -> V_69 ;
V_105 = V_69 -> V_107 ;
if ( ( V_105 -> V_63 & V_137 ) ||
( ( V_105 -> V_63 & V_110 ) ) ) {
F_22 ( & V_6 -> V_64 , V_63 ) ;
return;
}
F_118 ( V_492 , V_69 , L_133 ) ;
F_22 ( & V_6 -> V_64 , V_63 ) ;
if ( V_6 -> V_493 -> V_494 == V_495 )
F_189 ( V_6 , V_26 ) ;
V_186 = F_80 ( T_30 , V_496 ) +
sizeof( T_31 ) ;
V_491 = F_59 ( V_186 , V_130 ) ;
if ( ! V_491 ) {
F_13 ( V_33 L_2 ,
V_6 -> V_34 , __FILE__ , __LINE__ , V_35 ) ;
return;
}
V_491 -> V_266 = V_497 ;
V_491 -> V_498 =
F_108 ( V_499 ) ;
V_491 -> V_235 = V_186 / 4 ;
V_491 -> V_500 =
F_108 ( sizeof( T_31 ) / 4 ) ;
V_298 = ( T_31 * )
V_491 -> V_496 ;
V_298 -> V_359 = V_501 ;
V_298 -> V_502 = 0x5D ;
V_298 -> V_193 = F_108 ( V_26 ) ;
V_298 -> V_10 = F_191 ( V_105 -> V_8 ) ;
F_192 ( V_6 , V_491 ) ;
F_21 ( V_491 ) ;
}
static T_6
F_193 ( struct V_5 * V_6 , T_4 V_87 , T_6 V_229 , T_10 V_230 )
{
T_25 * V_247 ;
T_27 * V_28 ;
struct V_86 * V_89 ;
T_4 V_29 ;
T_10 V_503 ;
T_6 V_436 ;
T_6 V_438 ;
T_10 V_444 ;
struct V_102 * V_103 ;
T_10 V_220 = 0 ;
V_28 = F_94 ( V_6 , V_230 ) ;
V_89 = F_42 ( V_6 , V_87 ) ;
if ( V_89 == NULL )
return 1 ;
V_247 = F_107 ( V_6 , V_87 ) ;
if ( V_28 == NULL ) {
V_89 -> V_286 = V_504 << 16 ;
goto V_74;
}
V_103 = V_89 -> V_42 -> V_107 ;
if ( ! V_103 || ! V_103 -> V_109 ||
V_103 -> V_109 -> V_329 ) {
V_89 -> V_286 = V_287 << 16 ;
goto V_74;
}
V_29 = F_9 ( V_28 -> V_37 ) ;
V_436 = V_28 -> V_437 ;
if ( V_436 & V_469 )
V_220 =
F_66 ( V_28 -> V_482 ) & 0xFF ;
if ( ! V_103 -> V_505 ) {
V_103 -> V_505 ++ ;
if ( ( V_103 -> V_63 & V_412 ) &&
V_220 == V_223 )
V_103 -> V_63 &=
~ V_412 ;
}
V_503 = F_66 ( V_28 -> V_476 ) ;
F_194 ( V_89 , F_180 ( V_89 ) - V_503 ) ;
if ( V_29 & V_506 )
V_444 = F_66 ( V_28 -> V_275 ) ;
else
V_444 = 0 ;
V_29 &= V_38 ;
V_438 = V_28 -> V_439 ;
if ( V_29 == V_450 && V_503 == 0 &&
( V_438 == V_461 ||
V_438 == V_464 ||
V_438 == V_466 ) ) {
V_29 = V_39 ;
}
if ( V_436 & V_473 ) {
struct V_477 V_478 ;
const void * V_507 = F_195 ( V_6 ,
V_87 ) ;
T_10 V_186 = F_196 ( T_10 , V_425 ,
F_66 ( V_28 -> V_481 ) ) ;
memcpy ( V_89 -> V_394 , V_507 , V_186 ) ;
F_186 ( V_89 -> V_394 , & V_478 ) ;
if ( V_478 . V_480 == 0x5D )
F_190 ( V_6 ,
F_9 ( V_28 -> V_193 ) ) ;
F_197 ( V_6 , V_478 . V_479 , V_478 . V_480 , V_478 . V_390 ) ;
}
switch ( V_29 ) {
case V_508 :
case V_509 :
V_89 -> V_286 = V_510 ;
break;
case V_448 :
V_89 -> V_286 = V_287 << 16 ;
break;
case V_456 :
if ( V_103 -> V_308 ) {
V_89 -> V_286 = V_511 << 16 ;
goto V_74;
}
if ( V_444 == 0x31110630 ) {
if ( V_89 -> V_512 > 2 ) {
V_89 -> V_286 = V_287 << 16 ;
F_198 ( V_89 -> V_42 ,
V_513 ) ;
} else {
V_89 -> V_286 = V_514 << 16 ;
V_89 -> V_42 -> V_515 = 1 ;
}
break;
}
V_89 -> V_286 = V_514 << 16 ;
break;
case V_453 :
case V_457 :
V_89 -> V_286 = V_289 << 16 ;
break;
case V_454 :
if ( ( V_503 == 0 ) || ( V_89 -> V_474 > V_503 ) )
V_89 -> V_286 = V_514 << 16 ;
else
V_89 -> V_286 = ( V_504 << 16 ) | V_438 ;
break;
case V_450 :
V_89 -> V_286 = ( V_504 << 16 ) | V_438 ;
if ( ( V_436 & V_473 ) )
break;
if ( V_503 < V_89 -> V_474 ) {
if ( V_438 == V_510 )
V_89 -> V_286 = V_510 ;
else
V_89 -> V_286 = V_514 << 16 ;
} else if ( V_436 & ( V_472 |
V_471 ) )
V_89 -> V_286 = V_514 << 16 ;
else if ( V_436 & V_470 )
V_89 -> V_286 = V_289 << 16 ;
else if ( ! V_503 && V_89 -> V_430 [ 0 ] == V_516 ) {
V_28 -> V_437 = V_473 ;
V_28 -> V_439 = V_398 ;
V_89 -> V_286 = ( V_396 << 24 ) |
V_398 ;
V_89 -> V_394 [ 0 ] = 0x70 ;
V_89 -> V_394 [ 2 ] = V_395 ;
V_89 -> V_394 [ 12 ] = 0x20 ;
V_89 -> V_394 [ 13 ] = 0 ;
}
break;
case V_449 :
F_194 ( V_89 , 0 ) ;
case V_446 :
case V_39 :
V_89 -> V_286 = ( V_504 << 16 ) | V_438 ;
if ( V_220 ==
V_223 ||
( V_436 & ( V_472 |
V_471 ) ) )
V_89 -> V_286 = V_514 << 16 ;
else if ( V_436 & V_470 )
V_89 -> V_286 = V_289 << 16 ;
break;
case V_391 :
case V_393 :
case V_392 :
F_174 ( V_89 , V_29 ) ;
break;
case V_452 :
case V_445 :
case V_517 :
case V_518 :
case V_519 :
case V_520 :
case V_451 :
case V_455 :
default:
V_89 -> V_286 = V_514 << 16 ;
break;
}
#ifdef F_177
if ( V_89 -> V_286 && ( V_6 -> V_7 & V_521 ) )
F_184 ( V_6 , V_89 , V_28 , V_87 ) ;
#endif
V_74:
F_168 ( V_89 ) ;
V_89 -> V_288 ( V_89 ) ;
return 1 ;
}
static void
F_199 ( struct V_5 * V_6 )
{
T_4 V_186 ;
T_4 V_29 ;
int V_91 ;
T_9 V_28 ;
T_33 * V_522 = NULL ;
T_4 V_523 ;
T_6 V_524 ;
F_106 ( V_6 , F_3 ( V_33
L_134 ,
V_6 -> V_34 , ( unsigned long long ) V_6 -> V_30 . V_8 ) ) ;
V_186 = F_80 ( T_33 , V_525 ) + ( V_6 -> V_30 . V_31
* sizeof( V_526 ) ) ;
V_522 = F_59 ( V_186 , V_130 ) ;
if ( ! V_522 ) {
F_13 ( V_33 L_2 ,
V_6 -> V_34 , __FILE__ , __LINE__ , V_35 ) ;
return;
}
if ( ( F_200 ( V_6 , & V_28 ,
V_522 , V_186 ) ) != 0 )
goto V_74;
V_29 = F_9 ( V_28 . V_37 ) & V_38 ;
if ( V_29 != V_39 )
goto V_74;
for ( V_91 = 0 ; V_91 < V_6 -> V_30 . V_31 ; V_91 ++ ) {
V_524 = V_522 -> V_525 [ V_91 ] . V_527 >> 4 ;
if ( V_91 == 0 )
V_6 -> V_30 . V_26 = F_9 ( V_522 ->
V_525 [ 0 ] . V_528 ) ;
V_6 -> V_30 . V_211 [ V_91 ] . V_26 = V_6 -> V_30 . V_26 ;
V_523 = F_9 ( V_522 -> V_525 [ V_91 ] .
V_322 ) ;
if ( V_523 && V_524 < V_529 )
V_524 = V_529 ;
F_201 ( V_6 , V_6 -> V_30 . V_8 ,
V_523 , V_91 , V_524 ) ;
}
V_74:
F_21 ( V_522 ) ;
}
static void
F_202 ( struct V_5 * V_6 )
{
int V_91 ;
T_9 V_28 ;
T_33 * V_522 = NULL ;
T_34 * V_530 = NULL ;
T_35 V_531 ;
T_8 V_27 ;
T_36 V_532 ;
T_4 V_29 ;
T_4 V_186 ;
T_6 V_533 ;
F_203 ( V_6 , & V_6 -> V_30 . V_31 ) ;
if ( ! V_6 -> V_30 . V_31 ) {
F_13 ( V_33 L_2 ,
V_6 -> V_34 , __FILE__ , __LINE__ , V_35 ) ;
return;
}
V_186 = F_80 ( T_33 , V_525 ) + ( V_6 -> V_30 . V_31 *
sizeof( V_526 ) ) ;
V_522 = F_59 ( V_186 , V_130 ) ;
if ( ! V_522 ) {
F_13 ( V_33 L_2 ,
V_6 -> V_34 , __FILE__ , __LINE__ , V_35 ) ;
return;
}
if ( ( F_200 ( V_6 , & V_28 ,
V_522 , V_186 ) ) ) {
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
V_186 = F_80 ( T_34 , V_525 ) + ( V_6 -> V_30 . V_31 *
sizeof( V_534 ) ) ;
V_530 = F_59 ( V_186 , V_130 ) ;
if ( ! V_530 ) {
F_13 ( V_33 L_2 ,
V_6 -> V_34 , __FILE__ , __LINE__ , V_35 ) ;
goto V_74;
}
if ( ( F_204 ( V_6 , & V_28 ,
V_530 , V_186 ) ) ) {
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
V_6 -> V_535 =
V_530 -> V_536 ;
V_533 =
V_530 -> V_537 ;
if ( V_533 & V_538 )
V_6 -> V_533 = ( V_533 &
V_539 ) * 16 ;
else
V_6 -> V_533 = V_533 &
V_539 ;
V_6 -> V_30 . V_540 = & V_6 -> V_99 -> V_541 ;
V_6 -> V_30 . V_211 = F_205 ( V_6 -> V_30 . V_31 ,
sizeof( struct V_542 ) , V_130 ) ;
if ( ! V_6 -> V_30 . V_211 ) {
F_13 ( V_33 L_2 ,
V_6 -> V_34 , __FILE__ , __LINE__ , V_35 ) ;
goto V_74;
}
for ( V_91 = 0 ; V_91 < V_6 -> V_30 . V_31 ; V_91 ++ ) {
if ( ( F_206 ( V_6 , & V_28 , & V_531 ,
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
V_6 -> V_30 . V_26 = F_9 ( V_522 ->
V_525 [ 0 ] . V_528 ) ;
V_6 -> V_30 . V_211 [ V_91 ] . V_26 = V_6 -> V_30 . V_26 ;
V_6 -> V_30 . V_211 [ V_91 ] . V_543 = V_91 ;
F_207 ( V_6 , & V_6 -> V_30 . V_211 [ V_91 ] ,
V_531 , V_6 -> V_30 . V_540 ) ;
}
if ( ( F_12 ( V_6 , & V_28 , & V_27 ,
V_32 , V_6 -> V_30 . V_26 ) ) ) {
F_13 ( V_33 L_2 ,
V_6 -> V_34 , __FILE__ , __LINE__ , V_35 ) ;
goto V_74;
}
V_6 -> V_30 . V_544 =
F_9 ( V_27 . V_545 ) ;
V_6 -> V_30 . V_8 = F_6 ( V_27 . V_10 ) ;
F_3 ( V_33
L_135 ,
V_6 -> V_34 , V_6 -> V_30 . V_26 ,
( unsigned long long ) V_6 -> V_30 . V_8 ,
V_6 -> V_30 . V_31 ) ;
if ( V_6 -> V_30 . V_544 ) {
if ( ! ( F_208 ( V_6 , & V_28 ,
& V_532 , V_546 ,
V_6 -> V_30 . V_544 ) ) )
V_6 -> V_30 . V_13 =
F_6 ( V_532 . V_15 ) ;
}
V_74:
F_21 ( V_530 ) ;
F_21 ( V_522 ) ;
}
static int
F_209 ( struct V_5 * V_6 , T_4 V_26 )
{
struct V_77 * V_78 ;
T_9 V_28 ;
T_37 V_547 ;
T_38 V_548 ;
T_36 V_532 ;
T_10 V_29 ;
T_4 V_549 ;
T_1 V_8 , V_68 = 0 ;
int V_91 ;
unsigned long V_63 ;
struct V_310 * V_311 = NULL ;
int V_19 = 0 ;
if ( ! V_26 )
return - 1 ;
if ( V_6 -> V_66 || V_6 -> V_256 )
return - 1 ;
if ( ( F_210 ( V_6 , & V_28 , & V_547 ,
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
if ( F_11 ( V_6 , V_549 , & V_68 )
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
V_19 = F_209 ( V_6 , V_549 ) ;
if ( V_19 != 0 )
return V_19 ;
}
}
F_19 ( & V_6 -> V_79 , V_63 ) ;
V_8 = F_6 ( V_547 . V_10 ) ;
V_78 = F_38 ( V_6 ,
V_8 ) ;
F_22 ( & V_6 -> V_79 , V_63 ) ;
if ( V_78 )
return 0 ;
V_78 = F_59 ( sizeof( struct V_77 ) ,
V_130 ) ;
if ( ! V_78 ) {
F_13 ( V_33 L_2 ,
V_6 -> V_34 , __FILE__ , __LINE__ , V_35 ) ;
return - 1 ;
}
V_78 -> V_26 = V_26 ;
V_78 -> V_31 = V_547 . V_552 ;
V_78 -> V_68 = V_68 ;
V_78 -> V_8 = V_8 ;
F_3 ( V_33 L_136 \
L_137 , V_6 -> V_34 ,
V_26 , V_549 , ( unsigned long long )
V_78 -> V_8 , V_78 -> V_31 ) ;
if ( ! V_78 -> V_31 )
goto V_553;
V_78 -> V_211 = F_205 ( V_78 -> V_31 ,
sizeof( struct V_542 ) , V_130 ) ;
if ( ! V_78 -> V_211 ) {
F_13 ( V_33 L_2 ,
V_6 -> V_34 , __FILE__ , __LINE__ , V_35 ) ;
V_19 = - 1 ;
goto V_553;
}
F_125 ( & V_78 -> V_554 ) ;
V_311 = F_29 ( V_6 , V_26 ,
V_68 ) ;
if ( ! V_311 ) {
F_13 ( V_33 L_2 ,
V_6 -> V_34 , __FILE__ , __LINE__ , V_35 ) ;
V_19 = - 1 ;
goto V_553;
}
V_78 -> V_540 = & V_311 -> V_129 -> V_127 ;
for ( V_91 = 0 ; V_91 < V_78 -> V_31 ; V_91 ++ ) {
if ( ( F_211 ( V_6 , & V_28 ,
& V_548 , V_91 , V_26 ) ) ) {
F_13 ( V_33 L_2 ,
V_6 -> V_34 , __FILE__ , __LINE__ , V_35 ) ;
V_19 = - 1 ;
goto V_553;
}
V_78 -> V_211 [ V_91 ] . V_26 = V_26 ;
V_78 -> V_211 [ V_91 ] . V_543 = V_91 ;
if ( ( F_212 ( V_6 ,
& V_78 -> V_211 [ V_91 ] , V_548 ,
V_78 -> V_540 ) ) ) {
F_13 ( V_33 L_2 ,
V_6 -> V_34 , __FILE__ , __LINE__ , V_35 ) ;
V_19 = - 1 ;
goto V_553;
}
}
if ( V_78 -> V_544 ) {
if ( ! ( F_208 ( V_6 , & V_28 ,
& V_532 , V_546 ,
V_78 -> V_544 ) ) )
V_78 -> V_13 =
F_6 ( V_532 . V_15 ) ;
}
F_39 ( V_6 , V_78 ) ;
return 0 ;
V_553:
if ( V_311 )
F_30 ( V_6 , V_78 -> V_8 ,
V_68 ) ;
F_21 ( V_78 ) ;
return V_19 ;
}
void
F_213 ( struct V_5 * V_6 , T_1 V_8 )
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
F_214 ( V_6 , V_78 ) ;
}
static T_6
F_215 ( struct V_5 * V_6 , T_4 V_87 , T_6 V_229 , T_10 V_230 )
{
T_15 * V_28 ;
V_28 = F_94 ( V_6 , V_230 ) ;
if ( V_6 -> V_555 . V_232 == V_233 )
return 1 ;
if ( V_6 -> V_555 . V_87 != V_87 )
return 1 ;
V_6 -> V_555 . V_232 |= V_234 ;
if ( V_28 ) {
memcpy ( V_6 -> V_555 . V_230 , V_28 ,
V_28 -> V_235 * 4 ) ;
V_6 -> V_555 . V_232 |= V_236 ;
}
V_6 -> V_555 . V_232 &= ~ V_237 ;
F_95 ( & V_6 -> V_555 . V_238 ) ;
return 1 ;
}
static T_6
F_216 ( struct V_5 * V_6 , T_1 V_8 ,
T_4 V_26 , T_6 V_556 )
{
T_6 V_19 = 1 ;
char * V_221 = NULL ;
switch ( V_556 ) {
case V_557 :
case V_558 :
V_19 = 0 ;
break;
case V_559 :
V_221 = L_138 ;
break;
case V_560 :
V_221 = L_139 ;
break;
case V_561 :
V_221 = L_140 ;
break;
case V_562 :
V_221 = L_141 ;
break;
case V_563 :
V_221 = L_142 ;
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
V_221 = L_143 ;
break;
default:
V_221 = L_40 ;
break;
}
if ( ! V_19 )
return 0 ;
F_13 ( V_33
L_144 ,
V_6 -> V_34 , V_221 , ( unsigned long long ) V_8 , V_26 ) ;
return V_19 ;
}
static void
F_217 ( struct V_5 * V_6 ,
T_1 V_576 , T_4 V_26 , T_6 V_577 , T_6 V_524 )
{
T_9 V_28 ;
T_8 V_27 ;
struct V_44 * V_45 ;
T_10 V_29 ;
unsigned long V_63 ;
T_1 V_8 ;
struct V_126 * V_69 ;
struct V_104 * V_105 ;
T_10 V_81 ;
if ( ( F_12 ( V_6 , & V_28 , & V_27 ,
V_32 , V_26 ) ) )
return;
V_29 = F_9 ( V_28 . V_37 ) & V_38 ;
if ( V_29 != V_39 )
return;
if ( V_577 != V_27 . V_578 )
return;
V_81 = F_66 ( V_27 . V_144 ) ;
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
if ( F_148 ( V_45 -> V_26 != V_26 ) ) {
V_69 = V_45 -> V_69 ;
V_105 = V_69 -> V_107 ;
F_118 ( V_119 , V_69 ,
L_145 ,
V_45 -> V_26 , V_26 ) ;
V_105 -> V_26 = V_26 ;
V_45 -> V_26 = V_26 ;
}
if ( ! ( F_9 ( V_27 . V_143 ) &
V_579 ) ) {
F_13 ( V_33
L_146 ,
V_6 -> V_34 , V_26 ) ;
F_22 ( & V_6 -> V_64 , V_63 ) ;
return;
}
if ( F_216 ( V_6 , V_8 , V_26 ,
V_27 . V_580 ) ) {
F_22 ( & V_6 -> V_64 , V_63 ) ;
return;
}
F_22 ( & V_6 -> V_64 , V_63 ) ;
F_139 ( V_6 , V_8 ) ;
}
static int
F_218 ( struct V_5 * V_6 , T_4 V_26 , T_6 V_581 ,
T_6 V_582 )
{
T_9 V_28 ;
T_8 V_27 ;
T_36 V_532 ;
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
V_81 = F_66 ( V_27 . V_144 ) ;
if ( ! ( F_40 ( V_81 ) ) )
return - 1 ;
V_8 = F_6 ( V_27 . V_10 ) ;
if ( ! ( F_9 ( V_27 . V_143 ) &
V_579 ) ) {
F_13 ( V_33 L_147 ,
V_6 -> V_34 , V_26 ) ;
return - 1 ;
}
if ( F_216 ( V_6 , V_8 , V_26 ,
V_27 . V_580 ) )
return - 1 ;
F_19 ( & V_6 -> V_64 , V_63 ) ;
V_45 = F_16 ( V_6 ,
V_8 ) ;
F_22 ( & V_6 -> V_64 , V_63 ) ;
if ( V_45 )
return - 1 ;
V_45 = F_59 ( sizeof( struct V_44 ) ,
V_130 ) ;
if ( ! V_45 ) {
F_13 ( V_33 L_2 ,
V_6 -> V_34 , __FILE__ , __LINE__ , V_35 ) ;
return 0 ;
}
V_45 -> V_26 = V_26 ;
if ( F_11 ( V_6 ,
F_9 ( V_27 . V_551 ) ,
& V_45 -> V_68 ) != 0 )
F_13 ( V_33 L_2 ,
V_6 -> V_34 , __FILE__ , __LINE__ , V_35 ) ;
V_45 -> V_544 =
F_9 ( V_27 . V_545 ) ;
V_45 -> V_17 =
F_9 ( V_27 . V_583 ) ;
V_45 -> V_81 = V_81 ;
V_45 -> V_8 = V_8 ;
V_45 -> V_211 = V_27 . V_578 ;
V_45 -> V_138 = ( F_9 ( V_27 . V_143 ) &
V_584 ) ? 1 : 0 ;
if ( V_45 -> V_544 && ! ( F_208 (
V_6 , & V_28 , & V_532 , V_546 ,
V_45 -> V_544 ) ) )
V_45 -> V_13 =
F_6 ( V_532 . V_15 ) ;
V_45 -> V_11 = F_6 ( V_27 . V_12 ) ;
if ( V_6 -> V_585 )
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
F_27 ( V_6 , F_3 ( V_33
L_148 ,
V_6 -> V_34 , V_35 ,
V_45 -> V_26 , ( unsigned long long )
V_45 -> V_8 ) ) ;
if ( V_45 -> V_69 && V_45 -> V_69 -> V_107 ) {
V_105 = V_45 -> V_69 -> V_107 ;
V_105 -> V_329 = 1 ;
F_139 ( V_6 , V_45 -> V_8 ) ;
V_105 -> V_26 =
V_132 ;
}
F_30 ( V_6 ,
V_45 -> V_8 ,
V_45 -> V_68 ) ;
F_3 ( V_33
L_149 ,
V_6 -> V_34 , V_45 -> V_26 ,
( unsigned long long ) V_45 -> V_8 ) ;
F_27 ( V_6 , F_3 ( V_33
L_150 ,
V_6 -> V_34 , V_35 ,
V_45 -> V_26 , ( unsigned long long )
V_45 -> V_8 ) ) ;
F_21 ( V_45 ) ;
}
static void
F_219 ( struct V_5 * V_6 ,
T_19 * V_298 )
{
int V_91 ;
T_4 V_26 ;
T_4 V_319 ;
T_6 V_577 ;
char * V_586 = NULL ;
T_6 V_524 , V_587 ;
switch ( V_298 -> V_345 ) {
case V_352 :
V_586 = L_151 ;
break;
case V_349 :
V_586 = L_152 ;
break;
case V_348 :
case 0 :
V_586 = L_153 ;
break;
case V_346 :
V_586 = L_154 ;
break;
default:
V_586 = L_155 ;
break;
}
F_3 ( V_33 L_156 ,
V_6 -> V_34 , V_586 ) ;
F_3 ( L_157 \
L_158 ,
F_9 ( V_298 -> V_344 ) ,
F_9 ( V_298 -> V_545 ) ,
V_298 -> V_588 , V_298 -> V_320 ) ;
for ( V_91 = 0 ; V_91 < V_298 -> V_320 ; V_91 ++ ) {
V_26 = F_9 ( V_298 -> V_321 [ V_91 ] . V_322 ) ;
if ( ! V_26 )
continue;
V_577 = V_298 -> V_588 + V_91 ;
V_319 = V_298 -> V_321 [ V_91 ] . V_323 &
V_324 ;
switch ( V_319 ) {
case V_589 :
V_586 = L_159 ;
break;
case V_343 :
V_586 = L_160 ;
break;
case V_325 :
V_586 = L_161 ;
break;
case V_590 :
V_586 = L_162 ;
break;
case V_591 :
V_586 = L_163 ;
break;
default:
V_586 = L_40 ;
break;
}
V_524 = V_298 -> V_321 [ V_91 ] . V_592 >> 4 ;
V_587 = V_298 -> V_321 [ V_91 ] . V_592 & 0xF ;
F_3 ( L_164 \
L_165 , V_577 ,
V_26 , V_586 , V_524 , V_587 ) ;
}
}
static int
F_220 ( struct V_5 * V_6 ,
struct V_291 * V_292 )
{
int V_91 ;
T_4 V_549 , V_26 ;
T_4 V_319 ;
T_6 V_577 , V_593 ;
struct V_77 * V_78 ;
T_1 V_8 ;
unsigned long V_63 ;
T_6 V_524 , V_587 ;
T_19 * V_298 = V_292 -> V_298 ;
#ifdef F_177
if ( V_6 -> V_7 & V_594 )
F_219 ( V_6 , V_298 ) ;
#endif
if ( V_6 -> V_66 || V_6 -> V_255 || V_6 -> V_256 )
return 0 ;
if ( ! V_6 -> V_30 . V_31 )
F_202 ( V_6 ) ;
else
F_199 ( V_6 ) ;
if ( V_292 -> V_351 ) {
F_27 ( V_6 , F_3 ( V_33
L_166 , V_6 -> V_34 ) ) ;
return 0 ;
}
V_549 = F_9 ( V_298 -> V_344 ) ;
if ( V_298 -> V_345 == V_352 )
if ( F_209 ( V_6 , V_549 ) != 0 )
return 0 ;
F_19 ( & V_6 -> V_79 , V_63 ) ;
V_78 = F_37 ( V_6 ,
V_549 ) ;
if ( V_78 ) {
V_8 = V_78 -> V_8 ;
V_593 = V_78 -> V_31 ;
} else if ( V_549 < V_6 -> V_30 . V_31 ) {
V_8 = V_6 -> V_30 . V_8 ;
V_593 = V_6 -> V_30 . V_31 ;
} else {
F_22 ( & V_6 -> V_79 , V_63 ) ;
return 0 ;
}
F_22 ( & V_6 -> V_79 , V_63 ) ;
for ( V_91 = 0 ; V_91 < V_298 -> V_320 ; V_91 ++ ) {
if ( V_292 -> V_351 ) {
F_27 ( V_6 , F_3 ( V_33
L_166 , V_6 -> V_34 ) ) ;
return 0 ;
}
if ( V_6 -> V_255 || V_6 -> V_256 )
return 0 ;
V_577 = V_298 -> V_588 + V_91 ;
if ( V_577 >= V_593 )
continue;
V_319 = V_298 -> V_321 [ V_91 ] . V_323 &
V_324 ;
if ( ( V_298 -> V_321 [ V_91 ] . V_323 &
V_595 ) && ( V_319 !=
V_343 ) )
continue;
V_26 = F_9 ( V_298 -> V_321 [ V_91 ] . V_322 ) ;
if ( ! V_26 )
continue;
V_524 = V_298 -> V_321 [ V_91 ] . V_592 >> 4 ;
V_587 = V_298 -> V_321 [ V_91 ] . V_592 & 0xF ;
switch ( V_319 ) {
case V_590 :
if ( V_6 -> V_66 )
break;
if ( V_524 == V_587 )
break;
F_201 ( V_6 , V_8 ,
V_26 , V_577 , V_524 ) ;
if ( V_524 < V_529 )
break;
F_217 ( V_6 , V_8 , V_26 ,
V_577 , V_524 ) ;
case V_589 :
if ( V_6 -> V_66 )
break;
F_201 ( V_6 , V_8 ,
V_26 , V_577 , V_524 ) ;
F_218 ( V_6 , V_26 , V_577 , 0 ) ;
break;
case V_343 :
F_23 ( V_6 , V_26 ) ;
break;
}
}
if ( V_298 -> V_345 == V_349 &&
V_78 )
F_213 ( V_6 , V_8 ) ;
return 0 ;
}
static void
F_221 ( struct V_5 * V_6 ,
T_31 * V_298 )
{
char * V_596 = NULL ;
switch ( V_298 -> V_359 ) {
case V_501 :
V_596 = L_167 ;
break;
case V_597 :
V_596 = L_168 ;
break;
case V_598 :
V_596 = L_169 ;
break;
case V_599 :
V_596 = L_170 ;
break;
case V_600 :
V_596 = L_171 ;
break;
case V_601 :
V_596 = L_172 ;
break;
case V_602 :
V_596 = L_173 ;
break;
case V_603 :
V_596 = L_174 ;
break;
case V_604 :
V_596 = L_175 ;
break;
case V_605 :
V_596 = L_176 ;
break;
case V_606 :
V_596 = L_177 ;
break;
case V_607 :
V_596 = L_178 ;
break;
case V_608 :
V_596 = L_179 ;
break;
default:
V_596 = L_180 ;
break;
}
F_3 ( V_33 L_181
L_182 ,
V_6 -> V_34 , V_596 , F_9 ( V_298 -> V_193 ) ,
( unsigned long long ) F_6 ( V_298 -> V_10 ) ,
F_9 ( V_298 -> V_475 ) ) ;
if ( V_298 -> V_359 == V_501 )
F_3 ( V_33 L_183 , V_6 -> V_34 ,
V_298 -> V_502 , V_298 -> V_609 ) ;
F_3 ( L_184 ) ;
}
static void
F_222 ( struct V_5 * V_6 ,
struct V_291 * V_292 )
{
struct V_104 * V_610 ;
struct V_44 * V_45 ;
T_1 V_8 ;
unsigned long V_63 ;
T_31 * V_298 =
V_292 -> V_298 ;
#ifdef F_177
if ( V_6 -> V_7 & V_594 )
F_221 ( V_6 ,
V_298 ) ;
#endif
if ( ( V_6 -> V_195 . V_611 >> 8 ) < 0xC )
return;
if ( V_298 -> V_359 !=
V_598 &&
V_298 -> V_359 !=
V_604 )
return;
F_19 ( & V_6 -> V_64 , V_63 ) ;
V_8 = F_6 ( V_298 -> V_10 ) ;
V_45 = F_16 ( V_6 ,
V_8 ) ;
if ( ! V_45 || ! V_45 -> V_69 ) {
F_22 ( & V_6 -> V_64 , V_63 ) ;
return;
}
V_610 = V_45 -> V_69 -> V_107 ;
if ( ! V_610 ) {
F_22 ( & V_6 -> V_64 , V_63 ) ;
return;
}
if ( V_298 -> V_359 ==
V_598 )
V_610 -> V_240 = 1 ;
else
V_610 -> V_240 = 0 ;
F_22 ( & V_6 -> V_64 , V_63 ) ;
}
static void
F_223 ( struct V_5 * V_6 ,
T_39 * V_298 )
{
char * V_596 = NULL ;
switch ( V_298 -> V_359 ) {
case V_612 :
V_596 = L_185 ;
break;
case V_613 :
V_596 = L_186 ;
break;
default:
V_596 = L_180 ;
break;
}
F_3 ( V_33 L_187
L_188
L_189 , V_6 -> V_34 , V_596 ,
F_9 ( V_298 -> V_545 ) ,
( unsigned long long ) F_6 ( V_298 -> V_15 ) ,
F_9 ( V_298 -> V_614 ) ) ;
}
static void
F_224 ( struct V_5 * V_6 ,
struct V_291 * V_292 )
{
#ifdef F_177
if ( V_6 -> V_7 & V_594 )
F_223 ( V_6 ,
V_292 -> V_298 ) ;
#endif
}
static void
F_225 ( struct V_5 * V_6 ,
struct V_291 * V_292 )
{
struct V_86 * V_89 ;
struct V_95 * V_96 ;
T_4 V_87 , V_26 ;
T_10 V_94 ;
struct V_102 * V_103 ;
T_10 V_615 ;
T_10 V_616 ;
T_18 * V_28 ;
T_40 * V_298 = V_292 -> V_298 ;
T_4 V_29 ;
unsigned long V_63 ;
int V_73 ;
T_6 V_617 = 0 ;
T_6 V_618 ;
F_100 ( & V_6 -> V_231 . V_252 ) ;
F_3 ( V_33
L_190 ,
V_6 -> V_34 , V_35 , V_298 -> V_578 ,
V_298 -> V_619 ) ;
F_140 ( V_6 ) ;
F_19 ( & V_6 -> V_90 , V_63 ) ;
V_28 = V_6 -> V_231 . V_230 ;
V_620:
if ( V_617 ++ == 5 ) {
F_27 ( V_6 , F_3 ( V_33 L_191 ,
V_6 -> V_34 , V_35 ) ) ;
goto V_74;
} else if ( V_617 > 1 )
F_27 ( V_6 , F_3 ( V_33 L_192 ,
V_6 -> V_34 , V_35 , V_617 - 1 ) ) ;
V_615 = 0 ;
V_616 = 0 ;
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
V_137 )
continue;
if ( V_103 -> V_109 -> V_63 &
V_110 )
continue;
V_26 = V_103 -> V_109 -> V_26 ;
V_94 = V_103 -> V_94 ;
V_616 ++ ;
if ( V_6 -> V_66 )
goto V_74;
F_22 ( & V_6 -> V_90 , V_63 ) ;
V_73 = F_99 ( V_6 , V_26 , 0 , 0 , V_94 ,
V_282 , V_87 , 30 , 0 ,
V_621 ) ;
if ( V_73 == V_253 ) {
F_52 ( V_492 , V_96 ,
L_193
L_194 , V_89 ) ;
F_19 ( & V_6 -> V_90 , V_63 ) ;
goto V_620;
}
V_29 = F_9 ( V_28 -> V_37 )
& V_38 ;
if ( V_29 != V_39 ) {
F_52 ( V_492 , V_96 ,
L_195 ,
V_29 , V_89 ) ;
F_19 ( & V_6 -> V_90 , V_63 ) ;
goto V_620;
}
if ( V_28 -> V_278 ==
V_226 ||
V_28 -> V_278 ==
V_228 ) {
F_19 ( & V_6 -> V_90 , V_63 ) ;
continue;
}
V_618 = 0 ;
V_622:
if ( V_618 ++ == 60 ) {
F_27 ( V_6 , F_3 ( V_33
L_196 , V_6 -> V_34 ,
V_35 ) ) ;
F_19 ( & V_6 -> V_90 , V_63 ) ;
goto V_620;
}
if ( V_6 -> V_66 )
goto V_623;
V_73 = F_99 ( V_6 , V_26 , V_96 -> V_72 , V_96 -> V_71 ,
V_96 -> V_94 , V_265 , V_87 , 30 ,
V_89 -> V_244 , V_621 ) ;
if ( V_73 == V_253 ) {
F_52 ( V_492 , V_96 ,
L_197
L_198 , V_89 ) ;
goto V_622;
}
if ( V_618 > 1 )
F_52 ( V_492 , V_96 ,
L_199
L_200 ,
V_618 - 1 , V_89 ) ;
V_615 += F_66 ( V_28 -> V_276 ) ;
F_19 ( & V_6 -> V_90 , V_63 ) ;
}
if ( V_6 -> V_624 ) {
F_27 ( V_6 , F_3 ( V_33
L_201 ,
V_6 -> V_34 , V_35 ) ) ;
V_6 -> V_624 = 0 ;
goto V_620;
}
V_74:
F_22 ( & V_6 -> V_90 , V_63 ) ;
V_623:
F_27 ( V_6 , F_3 ( V_33
L_202 ,
V_6 -> V_34 , V_35 , V_616 , V_615 ) ) ;
V_6 -> V_625 = 0 ;
if ( ! V_6 -> V_66 )
F_137 ( V_6 ) ;
F_115 ( & V_6 -> V_231 . V_252 ) ;
}
static void
F_226 ( struct V_5 * V_6 ,
struct V_291 * V_292 )
{
T_41 * V_298 = V_292 -> V_298 ;
#ifdef F_177
if ( V_6 -> V_7 & V_594 ) {
F_3 ( V_33 L_203 , V_6 -> V_34 ,
( V_298 -> V_359 == V_626 ) ?
L_204 : L_205 ) ;
if ( V_298 -> V_627 )
F_3 ( L_206 ,
F_66 ( V_298 -> V_627 ) ) ;
F_3 ( L_184 ) ;
}
#endif
if ( V_298 -> V_359 == V_626 &&
! V_6 -> V_30 . V_31 ) {
if ( V_628 > 0 && V_6 -> V_66 ) {
while ( V_6 -> V_66 )
F_227 ( 1 ) ;
}
F_202 ( V_6 ) ;
}
}
static int
F_228 ( struct V_5 * V_6 , T_4 V_26 , T_6 V_629 )
{
T_42 * V_247 ;
T_43 * V_28 ;
T_4 V_87 ;
T_6 V_630 = 0 ;
int V_19 = 0 ;
T_4 V_29 ;
T_10 V_444 ;
F_100 ( & V_6 -> V_555 . V_252 ) ;
if ( V_6 -> V_555 . V_232 != V_233 ) {
F_13 ( V_33 L_207 ,
V_6 -> V_34 , V_35 ) ;
V_19 = - V_631 ;
goto V_74;
}
V_6 -> V_555 . V_232 = V_237 ;
V_87 = F_149 ( V_6 , V_6 -> V_632 ) ;
if ( ! V_87 ) {
F_13 ( V_33 L_45 ,
V_6 -> V_34 , V_35 ) ;
V_6 -> V_555 . V_232 = V_233 ;
V_19 = - V_631 ;
goto V_74;
}
V_247 = F_107 ( V_6 , V_87 ) ;
V_6 -> V_555 . V_87 = V_87 ;
memset ( V_247 , 0 , sizeof( T_42 ) ) ;
V_247 -> V_266 = V_633 ;
V_247 -> V_484 = V_634 ;
V_247 -> V_192 = V_629 ;
F_27 ( V_6 , F_3 ( V_33 L_208\
L_209 , V_6 -> V_34 ,
V_26 , V_629 ) ) ;
F_110 ( & V_6 -> V_555 . V_238 ) ;
F_150 ( V_6 , V_87 ) ;
F_112 ( & V_6 -> V_555 . V_238 , 10 * V_272 ) ;
if ( ! ( V_6 -> V_555 . V_232 & V_234 ) ) {
F_13 ( V_33 L_47 ,
V_6 -> V_34 , V_35 ) ;
if ( ! ( V_6 -> V_555 . V_232 & V_273 ) )
V_630 = 1 ;
V_19 = - V_635 ;
goto V_74;
}
if ( V_6 -> V_555 . V_232 & V_236 ) {
V_28 = V_6 -> V_555 . V_230 ;
V_29 = F_9 ( V_28 -> V_37 ) ;
if ( V_29 & V_506 )
V_444 = F_66 ( V_28 -> V_275 ) ;
else
V_444 = 0 ;
V_29 &= V_38 ;
if ( V_29 != V_39 ) {
F_27 ( V_6 , F_3 ( V_33
L_210
L_211 , V_6 -> V_34 , V_29 ,
V_444 ) ) ;
V_19 = - V_635 ;
} else
F_27 ( V_6 , F_3 ( V_33
L_212 ,
V_6 -> V_34 ) ) ;
}
V_74:
V_6 -> V_555 . V_232 = V_233 ;
F_115 ( & V_6 -> V_555 . V_252 ) ;
if ( V_630 )
F_103 ( V_6 , V_258 ,
V_259 ) ;
return V_19 ;
}
static void
F_229 ( struct V_95 * V_96 , void * V_142 )
{
int V_19 ;
V_96 -> V_142 = V_142 ? 1 : 0 ;
F_52 ( V_119 , V_96 , L_213 ,
V_96 -> V_142 ? L_214 : L_215 ) ;
V_19 = F_230 ( V_96 ) ;
}
static void
F_231 ( struct V_5 * V_6 ,
T_23 * V_355 )
{
struct V_46 * V_47 ;
unsigned long V_63 ;
T_1 V_51 ;
T_4 V_26 = F_9 ( V_355 -> V_362 ) ;
int V_19 ;
F_87 ( V_6 , V_26 , & V_51 ) ;
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
V_47 = F_59 ( sizeof( struct V_46 ) , V_130 ) ;
if ( ! V_47 ) {
F_13 ( V_33
L_2 , V_6 -> V_34 ,
__FILE__ , __LINE__ , V_35 ) ;
return;
}
V_47 -> V_71 = V_6 -> V_636 ++ ;
V_47 -> V_72 = V_133 ;
V_47 -> V_26 = V_26 ;
V_47 -> V_51 = V_51 ;
F_35 ( V_6 , V_47 ) ;
if ( ! V_6 -> V_585 ) {
V_19 = F_232 ( V_6 -> V_99 , V_133 ,
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
F_233 ( struct V_5 * V_6 , T_4 V_26 )
{
struct V_46 * V_47 ;
unsigned long V_63 ;
struct V_104 * V_105 ;
struct V_126 * V_69 = NULL ;
F_19 ( & V_6 -> V_75 , V_63 ) ;
V_47 = F_33 ( V_6 , V_26 ) ;
if ( V_47 ) {
if ( V_47 -> V_69 ) {
V_69 = V_47 -> V_69 ;
V_105 = V_69 -> V_107 ;
V_105 -> V_329 = 1 ;
}
F_3 ( V_33 L_216 ,
V_6 -> V_34 , V_47 -> V_26 ,
( unsigned long long ) V_47 -> V_51 ) ;
F_20 ( & V_47 -> V_65 ) ;
F_21 ( V_47 ) ;
}
F_22 ( & V_6 -> V_75 , V_63 ) ;
if ( V_69 )
F_234 ( & V_69 -> V_127 ) ;
}
static void
F_235 ( struct V_5 * V_6 ,
T_23 * V_355 )
{
struct V_44 * V_45 ;
struct V_126 * V_69 = NULL ;
struct V_104 * V_105 ;
unsigned long V_63 ;
T_4 V_26 = F_9 ( V_355 -> V_364 ) ;
F_19 ( & V_6 -> V_64 , V_63 ) ;
V_45 = F_17 ( V_6 , V_26 ) ;
if ( V_45 ) {
V_45 -> V_201 = 0 ;
V_45 -> V_202 = 0 ;
F_164 ( V_26 , V_6 -> V_136 ) ;
if ( V_45 -> V_69 && V_45 -> V_69 -> V_107 ) {
V_69 = V_45 -> V_69 ;
V_105 = V_69 -> V_107 ;
V_105 -> V_63 &=
~ V_137 ;
}
}
F_22 ( & V_6 -> V_64 , V_63 ) ;
if ( ! V_45 )
return;
if ( V_69 )
F_236 ( V_69 , NULL , F_229 ) ;
}
static void
F_237 ( struct V_5 * V_6 ,
T_23 * V_355 )
{
struct V_44 * V_45 ;
struct V_126 * V_69 = NULL ;
struct V_104 * V_105 ;
unsigned long V_63 ;
T_4 V_26 = F_9 ( V_355 -> V_364 ) ;
T_4 V_201 = 0 ;
T_1 V_202 = 0 ;
F_86 ( V_6 , V_26 , & V_201 ) ;
if ( V_201 )
F_87 ( V_6 , V_201 ,
& V_202 ) ;
F_19 ( & V_6 -> V_64 , V_63 ) ;
V_45 = F_17 ( V_6 , V_26 ) ;
if ( V_45 ) {
F_144 ( V_26 , V_6 -> V_136 ) ;
if ( V_45 -> V_69 && V_45 -> V_69 -> V_107 ) {
V_69 = V_45 -> V_69 ;
V_105 = V_69 -> V_107 ;
V_105 -> V_63 |=
V_137 ;
V_45 -> V_201 = V_201 ;
V_45 -> V_202 = V_202 ;
}
}
F_22 ( & V_6 -> V_64 , V_63 ) ;
if ( ! V_45 )
return;
F_228 ( V_6 , V_26 , V_355 -> V_192 ) ;
if ( V_69 )
F_236 ( V_69 , ( void * ) 1 , F_229 ) ;
}
static void
F_238 ( struct V_5 * V_6 ,
T_23 * V_355 )
{
T_4 V_26 = F_9 ( V_355 -> V_364 ) ;
F_23 ( V_6 , V_26 ) ;
}
static void
F_239 ( struct V_5 * V_6 ,
T_23 * V_355 )
{
struct V_44 * V_45 ;
unsigned long V_63 ;
T_4 V_26 = F_9 ( V_355 -> V_364 ) ;
T_9 V_28 ;
T_8 V_27 ;
T_10 V_29 ;
T_1 V_8 ;
T_4 V_549 ;
F_144 ( V_26 , V_6 -> V_136 ) ;
F_19 ( & V_6 -> V_64 , V_63 ) ;
V_45 = F_17 ( V_6 , V_26 ) ;
F_22 ( & V_6 -> V_64 , V_63 ) ;
if ( V_45 ) {
F_228 ( V_6 , V_26 , V_355 -> V_192 ) ;
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
F_201 ( V_6 , V_8 , V_26 ,
V_27 . V_578 , V_529 ) ;
F_228 ( V_6 , V_26 , V_355 -> V_192 ) ;
F_218 ( V_6 , V_26 , 0 , 1 ) ;
}
static void
F_240 ( struct V_5 * V_6 ,
T_22 * V_298 )
{
T_23 * V_355 ;
T_6 V_637 ;
int V_91 ;
char * V_596 = NULL , * V_638 = NULL ;
V_355 = ( T_23 * ) & V_298 -> V_356 [ 0 ] ;
F_3 ( V_33 L_217 ,
V_6 -> V_34 , ( F_66 ( V_298 -> V_143 ) &
V_358 ) ?
L_218 : L_219 , V_298 -> V_357 ) ;
for ( V_91 = 0 ; V_91 < V_298 -> V_357 ; V_91 ++ , V_355 ++ ) {
switch ( V_355 -> V_359 ) {
case V_639 :
V_596 = L_151 ;
break;
case V_361 :
V_596 = L_152 ;
break;
case V_640 :
V_596 = L_220 ;
break;
case V_641 :
V_596 = L_221 ;
break;
case V_363 :
V_596 = L_222 ;
break;
case V_642 :
V_596 = L_223 ;
break;
case V_360 :
V_596 = L_224 ;
break;
case V_643 :
V_596 = L_225 ;
break;
case V_644 :
V_596 = L_226 ;
break;
default:
V_596 = L_180 ;
break;
}
V_637 = F_9 ( V_355 -> V_645 ) &
V_646 ;
switch ( V_637 ) {
case V_647 :
V_638 = L_50 ;
break;
case V_648 :
V_638 = L_227 ;
break;
case V_649 :
V_638 = L_228 ;
break;
default:
V_638 = L_229 ;
break;
}
F_3 ( L_230 \
L_231 , V_638 ,
V_596 , F_9 ( V_355 -> V_362 ) ,
F_9 ( V_355 -> V_364 ) ,
V_355 -> V_192 ) ;
}
}
static void
F_241 ( struct V_5 * V_6 ,
struct V_291 * V_292 )
{
T_23 * V_355 ;
int V_91 ;
T_6 V_650 ;
T_22 * V_298 = V_292 -> V_298 ;
#ifdef F_177
if ( V_6 -> V_7 & V_594 )
F_240 ( V_6 , V_298 ) ;
#endif
V_650 = ( F_66 ( V_298 -> V_143 ) &
V_358 ) ? 1 : 0 ;
V_355 = ( T_23 * ) & V_298 -> V_356 [ 0 ] ;
if ( V_6 -> V_66 ) {
for ( V_91 = 0 ; V_91 < V_298 -> V_357 ; V_91 ++ , V_355 ++ ) {
if ( V_355 -> V_359 == V_641 )
F_228 ( V_6 ,
F_9 ( V_355 -> V_364 ) ,
V_355 -> V_192 ) ;
}
return;
}
for ( V_91 = 0 ; V_91 < V_298 -> V_357 ; V_91 ++ , V_355 ++ ) {
switch ( V_355 -> V_359 ) {
case V_642 :
case V_639 :
if ( ! V_650 )
F_231 ( V_6 , V_355 ) ;
break;
case V_360 :
case V_361 :
if ( ! V_650 )
F_233 ( V_6 ,
F_9 ( V_355 -> V_362 ) ) ;
break;
case V_643 :
F_237 ( V_6 , V_355 ) ;
break;
case V_644 :
F_235 ( V_6 , V_355 ) ;
break;
case V_641 :
F_239 ( V_6 , V_355 ) ;
break;
case V_363 :
F_238 ( V_6 , V_355 ) ;
break;
}
}
}
static void
F_242 ( struct V_5 * V_6 ,
struct V_291 * V_292 )
{
T_1 V_51 ;
unsigned long V_63 ;
struct V_46 * V_47 ;
T_4 V_26 ;
T_10 V_160 ;
int V_19 ;
T_24 * V_298 = V_292 -> V_298 ;
if ( V_6 -> V_66 )
return;
if ( V_298 -> V_359 != V_365 )
return;
V_26 = F_9 ( V_298 -> V_362 ) ;
V_160 = F_66 ( V_298 -> V_366 ) ;
F_27 ( V_6 , F_3 ( V_33
L_232 ,
V_6 -> V_34 , V_35 , V_26 ,
F_66 ( V_298 -> V_651 ) , V_160 ) ) ;
switch ( V_160 ) {
case V_170 :
case V_169 :
F_233 ( V_6 , V_26 ) ;
break;
case V_165 :
case V_167 :
case V_164 :
F_19 ( & V_6 -> V_75 , V_63 ) ;
V_47 = F_33 ( V_6 , V_26 ) ;
F_22 ( & V_6 -> V_75 , V_63 ) ;
if ( V_47 )
break;
F_87 ( V_6 , V_26 , & V_51 ) ;
if ( ! V_51 ) {
F_13 ( V_33
L_2 , V_6 -> V_34 ,
__FILE__ , __LINE__ , V_35 ) ;
break;
}
V_47 = F_59 ( sizeof( struct V_46 ) , V_130 ) ;
if ( ! V_47 ) {
F_13 ( V_33
L_2 , V_6 -> V_34 ,
__FILE__ , __LINE__ , V_35 ) ;
break;
}
V_47 -> V_71 = V_6 -> V_636 ++ ;
V_47 -> V_72 = V_133 ;
V_47 -> V_26 = V_26 ;
V_47 -> V_51 = V_51 ;
F_35 ( V_6 , V_47 ) ;
V_19 = F_232 ( V_6 -> V_99 , V_133 ,
V_47 -> V_71 , 0 ) ;
if ( V_19 )
F_36 ( V_6 , V_47 ) ;
break;
case V_652 :
default:
break;
}
}
static void
F_243 ( struct V_5 * V_6 ,
struct V_291 * V_292 )
{
T_4 V_26 , V_549 ;
T_10 V_160 ;
struct V_44 * V_45 ;
unsigned long V_63 ;
T_9 V_28 ;
T_8 V_27 ;
T_10 V_29 ;
T_44 * V_298 = V_292 -> V_298 ;
T_1 V_8 ;
if ( V_6 -> V_66 )
return;
if ( V_298 -> V_359 != V_653 )
return;
V_26 = F_9 ( V_298 -> V_364 ) ;
V_160 = F_66 ( V_298 -> V_366 ) ;
F_27 ( V_6 , F_3 ( V_33
L_232 ,
V_6 -> V_34 , V_35 , V_26 ,
F_66 ( V_298 -> V_651 ) , V_160 ) ) ;
switch ( V_160 ) {
case V_654 :
case V_655 :
case V_656 :
case V_657 :
case V_658 :
F_144 ( V_26 , V_6 -> V_136 ) ;
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
V_549 = F_9 ( V_27 . V_551 ) ;
if ( ! F_11 ( V_6 , V_549 , & V_8 ) )
F_201 ( V_6 , V_8 , V_26 ,
V_27 . V_578 , V_529 ) ;
F_218 ( V_6 , V_26 , 0 , 1 ) ;
break;
case V_659 :
case V_660 :
case V_661 :
default:
break;
}
}
static void
F_244 ( struct V_5 * V_6 ,
T_45 * V_298 )
{
char * V_596 = NULL ;
switch ( V_298 -> V_662 ) {
case V_663 :
V_596 = L_233 ;
break;
case V_664 :
V_596 = L_234 ;
break;
case V_665 :
V_596 = L_235 ;
break;
case V_666 :
V_596 = L_236 ;
break;
case V_667 :
V_596 = L_237 ;
break;
}
if ( ! V_596 )
return;
F_3 ( V_33 L_238 \
L_239 ,
V_6 -> V_34 , V_596 ,
F_9 ( V_298 -> V_362 ) ,
V_298 -> V_668 ) ;
}
static void
F_245 ( struct V_5 * V_6 ,
struct V_291 * V_292 )
{
T_45 * V_298 = V_292 -> V_298 ;
static struct V_46 * V_47 ;
unsigned long V_63 ;
T_4 V_26 ;
#ifdef F_177
if ( V_6 -> V_7 & V_594 )
F_244 ( V_6 ,
V_298 ) ;
#endif
if ( V_298 -> V_662 == V_663 ) {
F_19 ( & V_6 -> V_75 , V_63 ) ;
V_26 = F_9 ( V_298 -> V_362 ) ;
V_47 = F_33 ( V_6 , V_26 ) ;
if ( V_47 )
V_47 -> V_153 =
V_298 -> V_668 ;
F_22 ( & V_6 -> V_75 , V_63 ) ;
}
}
static void
F_246 ( struct V_5 * V_6 )
{
struct V_102 * V_103 ;
struct V_95 * V_96 ;
F_97 (sdev, ioc->shost) {
V_103 = V_96 -> V_107 ;
if ( V_103 && V_103 -> V_109 )
V_103 -> V_109 -> V_329 = 1 ;
}
}
static void
F_247 ( struct V_5 * V_6 , T_1 V_8 ,
T_4 V_17 , T_4 V_26 )
{
struct V_104 * V_105 = NULL ;
struct V_126 * V_69 ;
struct V_44 * V_45 ;
unsigned long V_63 ;
F_19 ( & V_6 -> V_64 , V_63 ) ;
F_4 (sas_device, &ioc->sas_device_list, list) {
if ( V_45 -> V_8 == V_8 &&
V_45 -> V_17 == V_17 ) {
V_45 -> V_669 = 1 ;
V_69 = V_45 -> V_69 ;
if ( V_69 && V_69 -> V_107 ) {
V_105 = V_69 -> V_107 ;
V_105 -> V_240 = 0 ;
V_105 -> V_329 = 0 ;
} else
V_105 = NULL ;
if ( V_69 )
F_118 ( V_119 , V_69 ,
L_240
L_241
L_242 , V_26 ,
( unsigned long long ) V_45 -> V_8 ,
( unsigned long long )
V_45 -> V_13 ,
V_45 -> V_17 ) ;
if ( V_45 -> V_26 == V_26 )
goto V_74;
F_3 ( L_243 ,
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
F_248 ( struct V_5 * V_6 )
{
T_8 V_27 ;
T_9 V_28 ;
T_4 V_29 ;
T_4 V_26 ;
T_10 V_81 ;
F_3 ( V_33 L_244 , V_6 -> V_34 ) ;
if ( F_133 ( & V_6 -> V_67 ) )
goto V_74;
V_26 = 0xFFFF ;
while ( ! ( F_12 ( V_6 , & V_28 ,
& V_27 , V_670 ,
V_26 ) ) ) {
V_29 = F_9 ( V_28 . V_37 ) &
V_38 ;
if ( V_29 != V_39 )
break;
V_26 = F_9 ( V_27 . V_193 ) ;
V_81 = F_66 ( V_27 . V_144 ) ;
if ( ! ( F_40 ( V_81 ) ) )
continue;
F_247 ( V_6 ,
F_6 ( V_27 . V_10 ) ,
F_9 ( V_27 . V_583 ) , V_26 ) ;
}
V_74:
F_3 ( V_33 L_245 ,
V_6 -> V_34 ) ;
}
static void
F_249 ( struct V_5 * V_6 , T_1 V_51 ,
T_4 V_26 )
{
struct V_104 * V_105 ;
struct V_126 * V_69 ;
struct V_46 * V_47 ;
unsigned long V_63 ;
F_19 ( & V_6 -> V_75 , V_63 ) ;
F_4 (raid_device, &ioc->raid_device_list, list) {
if ( V_47 -> V_51 == V_51 && V_47 -> V_69 ) {
V_69 = V_47 -> V_69 ;
if ( V_69 && V_69 -> V_107 ) {
V_105 = V_69 -> V_107 ;
V_105 -> V_329 = 0 ;
} else
V_105 = NULL ;
V_47 -> V_669 = 1 ;
F_22 ( & V_6 -> V_75 , V_63 ) ;
F_118 ( V_119 , V_47 -> V_69 ,
L_246 , V_26 ,
( unsigned long long ) V_47 -> V_51 ) ;
F_19 ( & V_6 -> V_75 , V_63 ) ;
if ( V_47 -> V_26 == V_26 ) {
F_22 ( & V_6 -> V_75 ,
V_63 ) ;
return;
}
F_3 ( L_243 ,
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
F_250 ( struct V_5 * V_6 )
{
T_46 V_671 ;
T_11 V_672 ;
T_12 V_185 ;
T_9 V_28 ;
T_4 V_29 ;
T_4 V_26 ;
T_6 V_629 ;
if ( ! V_6 -> V_673 )
return;
F_3 ( V_33 L_247 ,
V_6 -> V_34 ) ;
if ( F_133 ( & V_6 -> V_76 ) )
goto V_74;
V_26 = 0xFFFF ;
while ( ! ( F_251 ( V_6 , & V_28 ,
& V_671 , V_674 , V_26 ) ) ) {
V_29 = F_9 ( V_28 . V_37 ) &
V_38 ;
if ( V_29 != V_39 )
break;
V_26 = F_9 ( V_671 . V_193 ) ;
if ( F_70 ( V_6 , & V_28 ,
& V_672 , V_154 , V_26 ,
sizeof( T_11 ) ) )
continue;
if ( V_672 . V_163 == V_164 ||
V_672 . V_163 == V_165 ||
V_672 . V_163 == V_167 )
F_249 ( V_6 ,
F_6 ( V_671 . V_675 ) , V_26 ) ;
}
V_629 = 0xFF ;
memset ( V_6 -> V_136 , 0 , V_6 -> V_676 ) ;
while ( ! ( F_81 ( V_6 , & V_28 ,
& V_185 , V_677 ,
V_629 ) ) ) {
V_29 = F_9 ( V_28 . V_37 ) &
V_38 ;
if ( V_29 != V_39 )
break;
V_629 = V_185 . V_192 ;
V_26 = F_9 ( V_185 . V_193 ) ;
F_144 ( V_26 , V_6 -> V_136 ) ;
}
V_74:
F_3 ( V_33 L_248 ,
V_6 -> V_34 ) ;
}
static void
F_252 ( struct V_5 * V_6 , T_1 V_8 ,
T_4 V_26 )
{
struct V_77 * V_78 ;
unsigned long V_63 ;
int V_91 ;
F_19 ( & V_6 -> V_79 , V_63 ) ;
F_4 (sas_expander, &ioc->sas_expander_list, list) {
if ( V_78 -> V_8 != V_8 )
continue;
V_78 -> V_669 = 1 ;
if ( V_78 -> V_26 == V_26 )
goto V_74;
F_3 ( L_249 \
L_250 ,
( unsigned long long ) V_78 -> V_8 ,
V_78 -> V_26 , V_26 ) ;
V_78 -> V_26 = V_26 ;
for ( V_91 = 0 ; V_91 < V_78 -> V_31 ; V_91 ++ )
V_78 -> V_211 [ V_91 ] . V_26 = V_26 ;
goto V_74;
}
V_74:
F_22 ( & V_6 -> V_79 , V_63 ) ;
}
static void
F_253 ( struct V_5 * V_6 )
{
T_37 V_547 ;
T_9 V_28 ;
T_4 V_29 ;
T_1 V_8 ;
T_4 V_26 ;
F_3 ( V_33 L_251 , V_6 -> V_34 ) ;
if ( F_133 ( & V_6 -> V_80 ) )
goto V_74;
V_26 = 0xFFFF ;
while ( ! ( F_210 ( V_6 , & V_28 , & V_547 ,
V_678 , V_26 ) ) ) {
V_29 = F_9 ( V_28 . V_37 ) &
V_38 ;
if ( V_29 != V_39 )
break;
V_26 = F_9 ( V_547 . V_193 ) ;
V_8 = F_6 ( V_547 . V_10 ) ;
F_3 ( L_252 ,
V_26 ,
( unsigned long long ) V_8 ) ;
F_252 ( V_6 , V_8 , V_26 ) ;
}
V_74:
F_3 ( V_33 L_253 , V_6 -> V_34 ) ;
}
static void
F_254 ( struct V_5 * V_6 )
{
struct V_44 * V_45 , * V_679 ;
struct V_77 * V_78 , * V_680 ;
struct V_46 * V_47 , * V_681 ;
struct V_682 V_683 ;
unsigned long V_63 ;
F_3 ( V_33 L_254 ,
V_6 -> V_34 ) ;
F_3 ( V_33 L_255 ,
V_6 -> V_34 ) ;
F_135 (sas_device, sas_device_next,
&ioc->sas_device_list, list) {
if ( ! V_45 -> V_669 )
F_25 ( V_6 ,
V_45 -> V_8 ) ;
else
V_45 -> V_669 = 0 ;
}
if ( V_6 -> V_673 ) {
F_3 ( V_33 L_256 ,
V_6 -> V_34 ) ;
F_135 (raid_device, raid_device_next,
&ioc->raid_device_list, list) {
if ( ! V_47 -> V_669 )
F_233 ( V_6 ,
V_47 -> V_26 ) ;
else
V_47 -> V_669 = 0 ;
}
}
F_3 ( V_33 L_257 ,
V_6 -> V_34 ) ;
F_19 ( & V_6 -> V_79 , V_63 ) ;
F_125 ( & V_683 ) ;
F_135 (sas_expander, sas_expander_next,
&ioc->sas_expander_list, list) {
if ( ! V_78 -> V_669 )
F_255 ( & V_78 -> V_65 , & V_683 ) ;
else
V_78 -> V_669 = 0 ;
}
F_22 ( & V_6 -> V_79 , V_63 ) ;
F_135 (sas_expander, sas_expander_next, &tmp_list,
list) {
F_20 ( & V_78 -> V_65 ) ;
F_214 ( V_6 , V_78 ) ;
}
F_3 ( V_33 L_258 ,
V_6 -> V_34 ) ;
F_137 ( V_6 ) ;
}
static void
F_256 ( struct V_5 * V_6 ,
struct V_77 * V_78 , T_4 V_26 )
{
T_38 V_548 ;
T_9 V_28 ;
int V_91 ;
for ( V_91 = 0 ; V_91 < V_78 -> V_31 ; V_91 ++ ) {
if ( ( F_211 ( V_6 , & V_28 ,
& V_548 , V_91 , V_26 ) ) ) {
F_13 ( V_33 L_2 ,
V_6 -> V_34 , __FILE__ , __LINE__ , V_35 ) ;
return;
}
F_201 ( V_6 , V_78 -> V_8 ,
F_9 ( V_548 . V_322 ) , V_91 ,
V_548 . V_527 >> 4 ) ;
}
}
static void
F_257 ( struct V_5 * V_6 )
{
T_37 V_547 ;
T_8 V_27 ;
T_46 V_671 ;
T_11 V_672 ;
T_12 V_185 ;
T_23 V_355 ;
T_9 V_28 ;
T_6 V_629 ;
T_4 V_29 ;
T_4 V_26 , V_549 ;
T_1 V_8 ;
struct V_44 * V_45 ;
struct V_77 * V_684 ;
static struct V_46 * V_47 ;
T_6 V_685 ;
unsigned long V_63 ;
F_3 ( V_33 L_259 , V_6 -> V_34 ) ;
F_199 ( V_6 ) ;
F_3 ( V_33 L_260 , V_6 -> V_34 ) ;
V_26 = 0xFFFF ;
while ( ! ( F_210 ( V_6 , & V_28 , & V_547 ,
V_678 , V_26 ) ) ) {
V_29 = F_9 ( V_28 . V_37 ) &
V_38 ;
if ( V_29 != V_39 ) {
F_3 ( V_33 L_261 \
L_262 ,
V_6 -> V_34 , V_29 ,
F_66 ( V_28 . V_275 ) ) ;
break;
}
V_26 = F_9 ( V_547 . V_193 ) ;
F_19 ( & V_6 -> V_79 , V_63 ) ;
V_684 = F_38 (
V_6 , F_6 ( V_547 . V_10 ) ) ;
F_22 ( & V_6 -> V_79 , V_63 ) ;
if ( V_684 )
F_256 ( V_6 , V_684 ,
V_26 ) ;
else {
F_3 ( V_33 L_263 \
L_264 , V_6 -> V_34 ,
V_26 , ( unsigned long long )
F_6 ( V_547 . V_10 ) ) ;
F_209 ( V_6 , V_26 ) ;
F_3 ( V_33 L_265 \
L_264 , V_6 -> V_34 ,
V_26 , ( unsigned long long )
F_6 ( V_547 . V_10 ) ) ;
}
}
F_3 ( V_33 L_266 ,
V_6 -> V_34 ) ;
if ( ! V_6 -> V_673 )
goto V_686;
F_3 ( V_33 L_267 , V_6 -> V_34 ) ;
V_629 = 0xFF ;
while ( ! ( F_81 ( V_6 , & V_28 ,
& V_185 , V_677 ,
V_629 ) ) ) {
V_29 = F_9 ( V_28 . V_37 ) &
V_38 ;
if ( V_29 != V_39 ) {
F_3 ( V_33 L_268\
L_262 ,
V_6 -> V_34 , V_29 ,
F_66 ( V_28 . V_275 ) ) ;
break;
}
V_629 = V_185 . V_192 ;
V_26 = F_9 ( V_185 . V_193 ) ;
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
F_3 ( V_33 L_269 \
L_262 ,
V_6 -> V_34 , V_29 ,
F_66 ( V_28 . V_275 ) ) ;
break;
}
V_549 = F_9 ( V_27 . V_551 ) ;
if ( ! F_11 ( V_6 , V_549 ,
& V_8 ) ) {
F_3 ( V_33 L_270 \
L_271 ,
V_6 -> V_34 , V_26 , ( unsigned long long )
F_6 ( V_27 . V_10 ) ) ;
F_201 ( V_6 , V_8 ,
V_26 , V_27 . V_578 ,
V_529 ) ;
F_144 ( V_26 , V_6 -> V_136 ) ;
V_685 = 0 ;
while ( F_218 ( V_6 , V_26 , V_685 ++ ,
1 ) ) {
F_227 ( 1 ) ;
}
F_3 ( V_33 L_272 \
L_271 ,
V_6 -> V_34 , V_26 , ( unsigned long long )
F_6 ( V_27 . V_10 ) ) ;
}
}
F_3 ( V_33 L_273 ,
V_6 -> V_34 ) ;
F_3 ( V_33 L_274 , V_6 -> V_34 ) ;
V_26 = 0xFFFF ;
while ( ! ( F_251 ( V_6 , & V_28 ,
& V_671 , V_674 , V_26 ) ) ) {
V_29 = F_9 ( V_28 . V_37 ) &
V_38 ;
if ( V_29 != V_39 ) {
F_3 ( V_33 L_275 \
L_262 ,
V_6 -> V_34 , V_29 ,
F_66 ( V_28 . V_275 ) ) ;
break;
}
V_26 = F_9 ( V_671 . V_193 ) ;
F_19 ( & V_6 -> V_75 , V_63 ) ;
V_47 = F_34 ( V_6 ,
F_6 ( V_671 . V_675 ) ) ;
F_22 ( & V_6 -> V_75 , V_63 ) ;
if ( V_47 )
continue;
if ( F_70 ( V_6 , & V_28 ,
& V_672 , V_154 , V_26 ,
sizeof( T_11 ) ) )
continue;
V_29 = F_9 ( V_28 . V_37 ) &
V_38 ;
if ( V_29 != V_39 ) {
F_3 ( V_33 L_275 \
L_262 ,
V_6 -> V_34 , V_29 ,
F_66 ( V_28 . V_275 ) ) ;
break;
}
if ( V_672 . V_163 == V_164 ||
V_672 . V_163 == V_165 ||
V_672 . V_163 == V_167 ) {
memset ( & V_355 , 0 , sizeof( T_23 ) ) ;
V_355 . V_359 = V_639 ;
V_355 . V_362 = V_671 . V_193 ;
F_3 ( V_33
L_276 ,
V_6 -> V_34 , V_671 . V_193 ) ;
F_231 ( V_6 , & V_355 ) ;
F_3 ( V_33
L_277 ,
V_6 -> V_34 , V_671 . V_193 ) ;
}
}
F_3 ( V_33 L_278 ,
V_6 -> V_34 ) ;
V_686:
F_3 ( V_33 L_279 ,
V_6 -> V_34 ) ;
V_26 = 0xFFFF ;
while ( ! ( F_12 ( V_6 , & V_28 ,
& V_27 , V_670 ,
V_26 ) ) ) {
V_29 = F_9 ( V_28 . V_37 ) &
V_38 ;
if ( V_29 != V_39 ) {
F_3 ( V_33 L_280\
L_281 ,
V_6 -> V_34 , V_29 ,
F_66 ( V_28 . V_275 ) ) ;
break;
}
V_26 = F_9 ( V_27 . V_193 ) ;
if ( ! ( F_40 (
F_66 ( V_27 . V_144 ) ) ) )
continue;
F_19 ( & V_6 -> V_64 , V_63 ) ;
V_45 = F_16 ( V_6 ,
F_6 ( V_27 . V_10 ) ) ;
F_22 ( & V_6 -> V_64 , V_63 ) ;
if ( V_45 )
continue;
V_549 = F_9 ( V_27 . V_551 ) ;
if ( ! F_11 ( V_6 , V_549 , & V_8 ) ) {
F_3 ( V_33 L_282 \
L_264 , V_6 -> V_34 ,
V_26 , ( unsigned long long )
F_6 ( V_27 . V_10 ) ) ;
F_201 ( V_6 , V_8 , V_26 ,
V_27 . V_578 , V_529 ) ;
V_685 = 0 ;
while ( F_218 ( V_6 , V_26 , V_685 ++ ,
0 ) ) {
F_227 ( 1 ) ;
}
F_3 ( V_33 L_283 \
L_264 , V_6 -> V_34 ,
V_26 , ( unsigned long long )
F_6 ( V_27 . V_10 ) ) ;
}
}
F_3 ( V_33 L_284 ,
V_6 -> V_34 ) ;
F_3 ( V_33 L_285 , V_6 -> V_34 ) ;
}
void
F_258 ( struct V_5 * V_6 , int V_687 )
{
switch ( V_687 ) {
case V_688 :
F_106 ( V_6 , F_3 ( V_33
L_286 , V_6 -> V_34 , V_35 ) ) ;
break;
case V_689 :
F_106 ( V_6 , F_3 ( V_33
L_287 , V_6 -> V_34 , V_35 ) ) ;
if ( V_6 -> V_555 . V_232 & V_237 ) {
V_6 -> V_555 . V_232 |= V_273 ;
F_157 ( V_6 , V_6 -> V_555 . V_87 ) ;
F_95 ( & V_6 -> V_555 . V_238 ) ;
}
if ( V_6 -> V_231 . V_232 & V_237 ) {
V_6 -> V_231 . V_232 |= V_273 ;
F_157 ( V_6 , V_6 -> V_231 . V_87 ) ;
F_95 ( & V_6 -> V_231 . V_238 ) ;
}
F_132 ( V_6 ) ;
F_167 ( V_6 ) ;
break;
case V_690 :
F_106 ( V_6 , F_3 ( V_33
L_288 , V_6 -> V_34 , V_35 ) ) ;
if ( ( ! V_6 -> V_48 ) && ! ( V_628 > 0 &&
! V_6 -> V_30 . V_31 ) ) {
F_246 ( V_6 ) ;
F_248 ( V_6 ) ;
F_250 ( V_6 ) ;
F_253 ( V_6 ) ;
F_130 ( V_6 ) ;
}
break;
}
}
static void
F_259 ( struct V_5 * V_6 , struct V_291 * V_292 )
{
if ( V_6 -> V_255 || V_292 -> V_307 ||
V_6 -> V_256 ) {
F_128 ( V_6 , V_292 ) ;
return;
}
switch ( V_292 -> V_301 ) {
case V_302 :
F_260 ( V_6 , V_292 -> V_298 ) ;
break;
case V_303 :
while ( F_261 ( V_6 -> V_99 ) || V_6 -> V_66 )
F_227 ( 1 ) ;
F_254 ( V_6 ) ;
F_257 ( V_6 ) ;
break;
case V_304 :
V_6 -> V_691 = 0 ;
if ( V_692 [ 0 ] != - 1 && V_692 [ 1 ] != - 1 )
F_262 ( V_6 , V_692 [ 0 ] ,
V_692 [ 1 ] ) ;
F_27 ( V_6 , F_3 ( V_33
L_289 ,
V_6 -> V_34 ) ) ;
break;
case V_489 :
F_187 ( V_6 , V_292 -> V_490 ) ;
break;
case V_350 :
F_220 ( V_6 , V_292 ) ;
break;
case V_499 :
F_222 ( V_6 , V_292 ) ;
break;
case V_693 :
F_226 ( V_6 , V_292 ) ;
break;
case V_694 :
F_225 ( V_6 , V_292 ) ;
break;
case V_695 :
F_224 ( V_6 ,
V_292 ) ;
break;
case V_696 :
F_241 ( V_6 , V_292 ) ;
break;
case V_697 :
F_242 ( V_6 , V_292 ) ;
break;
case V_698 :
F_243 ( V_6 , V_292 ) ;
break;
case V_699 :
F_245 ( V_6 , V_292 ) ;
break;
}
F_128 ( V_6 , V_292 ) ;
}
static void
V_297 ( struct V_700 * V_296 )
{
struct V_291 * V_292 = F_263 ( V_296 ,
struct V_291 , V_296 ) ;
F_259 ( V_292 -> V_6 , V_292 ) ;
}
T_6
F_264 ( struct V_5 * V_6 , T_6 V_229 ,
T_10 V_230 )
{
struct V_291 * V_292 ;
T_30 * V_28 ;
T_4 V_301 ;
T_4 V_186 ;
if ( V_6 -> V_255 || V_6 -> V_256 )
return 1 ;
V_28 = F_94 ( V_6 , V_230 ) ;
if ( F_148 ( ! V_28 ) ) {
F_13 ( V_33 L_79 ,
V_6 -> V_34 , __FILE__ , __LINE__ , V_35 ) ;
return 1 ;
}
V_301 = F_9 ( V_28 -> V_498 ) ;
if ( V_301 != V_701 )
F_265 ( V_6 , V_301 , 0 ) ;
switch ( V_301 ) {
case V_694 :
{
T_40 * V_702 =
( T_40 * )
V_28 -> V_496 ;
if ( V_702 -> V_703 !=
V_704 )
return 1 ;
if ( V_6 -> V_625 ) {
V_6 -> V_624 ++ ;
return 1 ;
} else
V_6 -> V_625 = 1 ;
break;
}
case V_350 :
F_158 ( V_6 ,
( T_19 * )
V_28 -> V_496 ) ;
break;
case V_696 :
F_163 ( V_6 ,
( T_22 * )
V_28 -> V_496 ) ;
break;
case V_697 :
F_166 ( V_6 ,
( T_24 * )
V_28 -> V_496 ) ;
break;
case V_499 :
case V_699 :
case V_693 :
case V_695 :
case V_698 :
break;
default:
return 1 ;
}
V_292 = F_59 ( sizeof( struct V_291 ) , V_300 ) ;
if ( ! V_292 ) {
F_13 ( V_33 L_2 ,
V_6 -> V_34 , __FILE__ , __LINE__ , V_35 ) ;
return 1 ;
}
V_186 = F_9 ( V_28 -> V_500 ) * 4 ;
V_292 -> V_298 = F_59 ( V_186 , V_300 ) ;
if ( ! V_292 -> V_298 ) {
F_13 ( V_33 L_2 ,
V_6 -> V_34 , __FILE__ , __LINE__ , V_35 ) ;
F_21 ( V_292 ) ;
return 1 ;
}
memcpy ( V_292 -> V_298 , V_28 -> V_496 , V_186 ) ;
V_292 -> V_6 = V_6 ;
V_292 -> V_705 = V_28 -> V_705 ;
V_292 -> V_706 = V_28 -> V_706 ;
V_292 -> V_301 = V_301 ;
F_124 ( V_6 , V_292 ) ;
return 1 ;
}
static void
F_214 ( struct V_5 * V_6 ,
struct V_77 * V_78 )
{
struct V_310 * V_311 , * V_305 ;
F_135 (mpt3sas_port, next,
&sas_expander->sas_port_list, port_list) {
if ( V_6 -> V_66 )
return;
if ( V_311 -> V_313 . V_314 ==
V_315 )
F_25 ( V_6 ,
V_311 -> V_313 . V_8 ) ;
else if ( V_311 -> V_313 . V_314 ==
V_317 ||
V_311 -> V_313 . V_314 ==
V_318 )
F_213 ( V_6 ,
V_311 -> V_313 . V_8 ) ;
}
F_30 ( V_6 , V_78 -> V_8 ,
V_78 -> V_68 ) ;
F_3 ( V_33
L_290 ,
V_6 -> V_34 ,
V_78 -> V_26 , ( unsigned long long )
V_78 -> V_8 ) ;
F_21 ( V_78 -> V_211 ) ;
F_21 ( V_78 ) ;
}
static void
F_266 ( struct V_5 * V_6 )
{
T_42 * V_247 ;
T_43 * V_28 ;
T_4 V_87 ;
if ( ! V_6 -> V_673 )
return;
if ( F_133 ( & V_6 -> V_76 ) )
return;
F_100 ( & V_6 -> V_555 . V_252 ) ;
if ( V_6 -> V_555 . V_232 != V_233 ) {
F_13 ( V_33 L_207 ,
V_6 -> V_34 , V_35 ) ;
goto V_74;
}
V_6 -> V_555 . V_232 = V_237 ;
V_87 = F_149 ( V_6 , V_6 -> V_632 ) ;
if ( ! V_87 ) {
F_13 ( V_33 L_45 ,
V_6 -> V_34 , V_35 ) ;
V_6 -> V_555 . V_232 = V_233 ;
goto V_74;
}
V_247 = F_107 ( V_6 , V_87 ) ;
V_6 -> V_555 . V_87 = V_87 ;
memset ( V_247 , 0 , sizeof( T_42 ) ) ;
V_247 -> V_266 = V_633 ;
V_247 -> V_484 = V_707 ;
F_3 ( V_33 L_291 , V_6 -> V_34 ) ;
F_110 ( & V_6 -> V_555 . V_238 ) ;
F_150 ( V_6 , V_87 ) ;
F_112 ( & V_6 -> V_555 . V_238 , 10 * V_272 ) ;
if ( ! ( V_6 -> V_555 . V_232 & V_234 ) ) {
F_13 ( V_33 L_47 ,
V_6 -> V_34 , V_35 ) ;
goto V_74;
}
if ( V_6 -> V_555 . V_232 & V_236 ) {
V_28 = V_6 -> V_555 . V_230 ;
F_3 ( V_33
L_292 ,
V_6 -> V_34 , F_9 ( V_28 -> V_37 ) ,
F_66 ( V_28 -> V_275 ) ) ;
}
V_74:
V_6 -> V_555 . V_232 = V_233 ;
F_115 ( & V_6 -> V_555 . V_252 ) ;
}
static void F_267 ( struct V_708 * V_493 )
{
struct V_98 * V_99 = F_268 ( V_493 ) ;
struct V_5 * V_6 = F_47 ( V_99 ) ;
struct V_310 * V_311 , * V_709 ;
struct V_46 * V_47 , * V_305 ;
struct V_104 * V_105 ;
struct V_710 * V_711 ;
unsigned long V_63 ;
V_6 -> V_255 = 1 ;
F_132 ( V_6 ) ;
F_19 ( & V_6 -> V_294 , V_63 ) ;
V_711 = V_6 -> V_293 ;
V_6 -> V_293 = NULL ;
F_22 ( & V_6 -> V_294 , V_63 ) ;
if ( V_711 )
F_269 ( V_711 ) ;
F_266 ( V_6 ) ;
F_135 (raid_device, next, &ioc->raid_device_list,
list) {
if ( V_47 -> V_69 ) {
V_105 =
V_47 -> V_69 -> V_107 ;
V_105 -> V_329 = 1 ;
F_234 ( & V_47 -> V_69 -> V_127 ) ;
}
F_3 ( V_33 L_216 ,
V_6 -> V_34 , V_47 -> V_26 ,
( unsigned long long ) V_47 -> V_51 ) ;
F_36 ( V_6 , V_47 ) ;
}
F_135 (mpt3sas_port, next_port,
&ioc->sas_hba.sas_port_list, port_list) {
if ( V_311 -> V_313 . V_314 ==
V_315 )
F_25 ( V_6 ,
V_311 -> V_313 . V_8 ) ;
else if ( V_311 -> V_313 . V_314 ==
V_317 ||
V_311 -> V_313 . V_314 ==
V_318 )
F_213 ( V_6 ,
V_311 -> V_313 . V_8 ) ;
}
if ( V_6 -> V_30 . V_31 ) {
F_21 ( V_6 -> V_30 . V_211 ) ;
V_6 -> V_30 . V_211 = NULL ;
V_6 -> V_30 . V_31 = 0 ;
}
F_270 ( V_99 ) ;
F_271 ( V_6 ) ;
F_20 ( & V_6 -> V_65 ) ;
F_272 ( V_99 ) ;
F_273 ( V_99 ) ;
}
static void
F_274 ( struct V_708 * V_493 )
{
struct V_98 * V_99 = F_268 ( V_493 ) ;
struct V_5 * V_6 = F_47 ( V_99 ) ;
struct V_710 * V_711 ;
unsigned long V_63 ;
V_6 -> V_255 = 1 ;
F_132 ( V_6 ) ;
F_19 ( & V_6 -> V_294 , V_63 ) ;
V_711 = V_6 -> V_293 ;
V_6 -> V_293 = NULL ;
F_22 ( & V_6 -> V_294 , V_63 ) ;
if ( V_711 )
F_269 ( V_711 ) ;
F_266 ( V_6 ) ;
F_271 ( V_6 ) ;
}
static void
F_275 ( struct V_5 * V_6 )
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
V_19 = F_232 ( V_6 -> V_99 , V_133 ,
V_47 -> V_71 , 0 ) ;
if ( V_19 )
F_36 ( V_6 , V_47 ) ;
} else {
F_19 ( & V_6 -> V_64 , V_63 ) ;
V_45 = V_42 ;
V_26 = V_45 -> V_26 ;
V_68 = V_45 -> V_68 ;
V_8 = V_45 -> V_8 ;
F_255 ( & V_45 -> V_65 , & V_6 -> V_67 ) ;
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
F_276 ( struct V_5 * V_6 )
{
struct V_46 * V_47 , * V_712 ;
int V_19 ;
F_135 (raid_device, raid_next,
&ioc->raid_device_list, list) {
if ( V_47 -> V_69 )
continue;
V_19 = F_232 ( V_6 -> V_99 , V_133 ,
V_47 -> V_71 , 0 ) ;
if ( V_19 )
F_36 ( V_6 , V_47 ) ;
}
}
static void
F_277 ( struct V_5 * V_6 )
{
struct V_44 * V_45 , * V_305 ;
unsigned long V_63 ;
F_135 (sas_device, next, &ioc->sas_device_init_list,
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
F_255 ( & V_45 -> V_65 , & V_6 -> V_67 ) ;
F_22 ( & V_6 -> V_64 , V_63 ) ;
}
}
static void
F_278 ( struct V_5 * V_6 )
{
T_4 V_713 ;
if ( ! ( V_6 -> V_195 . V_714 & V_715 ) )
return;
F_275 ( V_6 ) ;
if ( V_6 -> V_673 ) {
V_713 =
F_9 ( V_6 -> V_716 . V_717 ) &
V_718 ;
if ( V_713 ==
V_719 ) {
F_276 ( V_6 ) ;
F_277 ( V_6 ) ;
} else {
F_277 ( V_6 ) ;
F_276 ( V_6 ) ;
}
} else
F_277 ( V_6 ) ;
}
static void
F_279 ( struct V_98 * V_99 )
{
struct V_5 * V_6 = F_47 ( V_99 ) ;
int V_19 ;
if ( V_720 != - 1 && V_720 != 0 )
F_280 ( V_6 , V_720 ) ;
if ( V_628 > 0 )
return;
V_6 -> V_691 = 1 ;
V_19 = F_281 ( V_6 ) ;
if ( V_19 != 0 )
F_3 ( V_33 L_293 , V_6 -> V_34 ) ;
}
static int
F_282 ( struct V_98 * V_99 , unsigned long time )
{
struct V_5 * V_6 = F_47 ( V_99 ) ;
if ( V_628 > 0 ) {
V_6 -> V_48 = 0 ;
V_6 -> V_585 = 0 ;
return 1 ;
}
if ( time >= ( 300 * V_272 ) ) {
V_6 -> V_721 . V_232 = V_233 ;
F_3 ( V_33
L_294 ,
V_6 -> V_34 ) ;
V_6 -> V_48 = 0 ;
return 1 ;
}
if ( V_6 -> V_691 )
return 0 ;
if ( V_6 -> V_722 ) {
F_3 ( V_33
L_295 ,
V_6 -> V_34 , V_6 -> V_722 ) ;
V_6 -> V_48 = 0 ;
V_6 -> V_585 = 0 ;
V_6 -> V_255 = 1 ;
return 1 ;
}
F_3 ( V_33 L_296 , V_6 -> V_34 ) ;
V_6 -> V_721 . V_232 = V_233 ;
if ( V_6 -> V_585 ) {
V_6 -> V_585 = 0 ;
F_278 ( V_6 ) ;
}
F_283 ( V_6 ) ;
V_6 -> V_48 = 0 ;
return 1 ;
}
static int
F_284 ( struct V_708 * V_493 , const struct V_723 * V_71 )
{
struct V_5 * V_6 ;
struct V_98 * V_99 ;
V_99 = F_285 ( & V_724 ,
sizeof( struct V_5 ) ) ;
if ( ! V_99 )
return - V_725 ;
V_6 = F_47 ( V_99 ) ;
memset ( V_6 , 0 , sizeof( struct V_5 ) ) ;
F_125 ( & V_6 -> V_65 ) ;
F_28 ( & V_6 -> V_65 , & V_726 ) ;
V_6 -> V_99 = V_99 ;
V_6 -> V_71 = V_727 ++ ;
sprintf ( V_6 -> V_34 , L_297 , V_728 , V_6 -> V_71 ) ;
V_6 -> V_493 = V_493 ;
V_6 -> V_415 = V_415 ;
V_6 -> V_264 = V_264 ;
V_6 -> V_729 = V_729 ;
V_6 -> V_730 = V_730 ;
V_6 -> V_731 = V_731 ;
V_6 -> V_732 = V_732 ;
V_6 -> V_632 = V_632 ;
V_6 -> V_733 = V_733 ;
V_6 -> V_330 = V_330 ;
V_6 -> V_339 = V_339 ;
V_6 -> V_335 = V_335 ;
V_6 -> V_7 = V_7 ;
V_6 -> V_734 = & F_167 ;
F_286 ( & V_6 -> V_735 ) ;
F_287 ( & V_6 -> V_736 ) ;
F_287 ( & V_6 -> V_90 ) ;
F_287 ( & V_6 -> V_64 ) ;
F_287 ( & V_6 -> V_79 ) ;
F_287 ( & V_6 -> V_294 ) ;
F_287 ( & V_6 -> V_75 ) ;
F_287 ( & V_6 -> V_737 ) ;
F_125 ( & V_6 -> V_67 ) ;
F_125 ( & V_6 -> V_70 ) ;
F_125 ( & V_6 -> V_80 ) ;
F_125 ( & V_6 -> V_295 ) ;
F_125 ( & V_6 -> V_76 ) ;
F_125 ( & V_6 -> V_30 . V_554 ) ;
F_125 ( & V_6 -> V_331 ) ;
F_125 ( & V_6 -> V_340 ) ;
V_99 -> V_738 = 32 ;
V_99 -> V_739 = V_739 ;
V_99 -> V_740 = V_741 ;
V_99 -> V_742 = V_6 -> V_71 ;
if ( V_743 != 0xFFFF ) {
if ( V_743 < 64 ) {
V_99 -> V_743 = 64 ;
F_79 ( V_33 L_298 \
L_299
L_300 , V_6 -> V_34 , V_743 ) ;
} else if ( V_743 > 32767 ) {
V_99 -> V_743 = 32767 ;
F_79 ( V_33 L_298 \
L_299
L_301 , V_6 -> V_34 ,
V_743 ) ;
} else {
V_99 -> V_743 = V_743 & 0xFFFE ;
F_3 ( V_33
L_302 ,
V_6 -> V_34 , V_99 -> V_743 ) ;
}
}
if ( ( F_288 ( V_99 , & V_493 -> V_127 ) ) ) {
F_13 ( V_33 L_2 ,
V_6 -> V_34 , __FILE__ , __LINE__ , V_35 ) ;
F_20 ( & V_6 -> V_65 ) ;
goto V_744;
}
if ( V_745 > 0 )
F_289 ( V_99 , V_745 ) ;
else
F_289 ( V_99 , V_746
| V_747
| V_748 ) ;
F_290 ( V_99 , V_749 ) ;
snprintf ( V_6 -> V_750 , sizeof( V_6 -> V_750 ) ,
L_303 , V_6 -> V_71 ) ;
V_6 -> V_293 = F_291 (
V_6 -> V_750 ) ;
if ( ! V_6 -> V_293 ) {
F_13 ( V_33 L_2 ,
V_6 -> V_34 , __FILE__ , __LINE__ , V_35 ) ;
goto V_751;
}
V_6 -> V_48 = 1 ;
if ( ( F_292 ( V_6 ) ) ) {
F_13 ( V_33 L_2 ,
V_6 -> V_34 , __FILE__ , __LINE__ , V_35 ) ;
goto V_752;
}
F_293 ( V_99 ) ;
return 0 ;
V_752:
F_269 ( V_6 -> V_293 ) ;
V_751:
F_20 ( & V_6 -> V_65 ) ;
F_272 ( V_99 ) ;
V_744:
F_273 ( V_99 ) ;
return - V_725 ;
}
static int
F_294 ( struct V_708 * V_493 , T_47 V_160 )
{
struct V_98 * V_99 = F_268 ( V_493 ) ;
struct V_5 * V_6 = F_47 ( V_99 ) ;
T_48 V_753 ;
F_295 ( V_6 ) ;
F_296 () ;
F_297 ( V_99 ) ;
V_753 = F_298 ( V_493 , V_160 ) ;
F_3 ( V_33
L_304 ,
V_6 -> V_34 , V_493 , F_299 ( V_493 ) , V_753 ) ;
F_300 ( V_493 ) ;
F_301 ( V_6 ) ;
F_302 ( V_493 , V_753 ) ;
return 0 ;
}
static int
F_303 ( struct V_708 * V_493 )
{
struct V_98 * V_99 = F_268 ( V_493 ) ;
struct V_5 * V_6 = F_47 ( V_99 ) ;
T_48 V_753 = V_493 -> V_754 ;
int V_73 ;
F_3 ( V_33
L_305 ,
V_6 -> V_34 , V_493 , F_299 ( V_493 ) , V_753 ) ;
F_302 ( V_493 , V_755 ) ;
F_304 ( V_493 , V_755 , 0 ) ;
F_305 ( V_493 ) ;
V_6 -> V_493 = V_493 ;
V_73 = F_306 ( V_6 ) ;
if ( V_73 )
return V_73 ;
F_103 ( V_6 , V_258 , V_756 ) ;
F_307 ( V_99 ) ;
F_283 ( V_6 ) ;
return 0 ;
}
static T_49
F_308 ( struct V_708 * V_493 , T_50 V_160 )
{
struct V_98 * V_99 = F_268 ( V_493 ) ;
struct V_5 * V_6 = F_47 ( V_99 ) ;
F_3 ( V_33 L_306 ,
V_6 -> V_34 , V_160 ) ;
switch ( V_160 ) {
case V_757 :
return V_758 ;
case V_759 :
V_6 -> V_256 = 1 ;
F_297 ( V_6 -> V_99 ) ;
F_295 ( V_6 ) ;
F_301 ( V_6 ) ;
return V_760 ;
case V_761 :
V_6 -> V_256 = 1 ;
F_295 ( V_6 ) ;
F_167 ( V_6 ) ;
return V_762 ;
}
return V_760 ;
}
static T_49
F_309 ( struct V_708 * V_493 )
{
struct V_98 * V_99 = F_268 ( V_493 ) ;
struct V_5 * V_6 = F_47 ( V_99 ) ;
int V_19 ;
F_3 ( V_33 L_307 ,
V_6 -> V_34 ) ;
V_6 -> V_256 = 0 ;
V_6 -> V_493 = V_493 ;
F_305 ( V_493 ) ;
V_19 = F_306 ( V_6 ) ;
if ( V_19 )
return V_762 ;
V_19 = F_103 ( V_6 , V_258 ,
V_259 ) ;
F_79 ( V_33 L_308 , V_6 -> V_34 ,
( V_19 == 0 ) ? L_90 : L_309 ) ;
if ( ! V_19 )
return V_763 ;
else
return V_762 ;
}
static void
F_310 ( struct V_708 * V_493 )
{
struct V_98 * V_99 = F_268 ( V_493 ) ;
struct V_5 * V_6 = F_47 ( V_99 ) ;
F_3 ( V_33 L_310 , V_6 -> V_34 ) ;
F_311 ( V_493 ) ;
F_283 ( V_6 ) ;
F_307 ( V_6 -> V_99 ) ;
}
static T_49
F_312 ( struct V_708 * V_493 )
{
struct V_98 * V_99 = F_268 ( V_493 ) ;
struct V_5 * V_6 = F_47 ( V_99 ) ;
F_3 ( V_33 L_311 ,
V_6 -> V_34 ) ;
return V_760 ;
}
static int T_51
F_313 ( void )
{
int error ;
V_727 = 0 ;
F_3 ( L_312 , V_728 ,
V_764 ) ;
V_741 =
F_314 ( & V_765 ) ;
if ( ! V_741 )
return - V_725 ;
V_157 = F_315 ( & V_766 ) ;
if ( ! V_157 ) {
F_316 ( V_741 ) ;
return - V_725 ;
}
F_317 () ;
V_415 = F_318 ( F_193 ) ;
V_264 = F_318 ( F_92 ) ;
V_730 = F_318 ( V_767 ) ;
V_731 = F_318 (
V_768 ) ;
V_732 = F_318 (
V_769 ) ;
V_632 = F_318 ( F_215 ) ;
V_733 = F_318 (
V_770 ) ;
V_729 = F_318 ( V_771 ) ;
V_330 = F_318 (
F_147 ) ;
V_339 = F_318 (
F_155 ) ;
V_335 = F_318 (
F_152 ) ;
F_319 () ;
error = F_320 ( & V_772 ) ;
if ( error ) {
F_321 ( V_157 ) ;
F_316 ( V_741 ) ;
}
return error ;
}
static void T_52
F_322 ( void )
{
F_3 ( L_313 ,
V_764 ) ;
F_323 () ;
F_324 ( & V_772 ) ;
F_325 ( V_415 ) ;
F_325 ( V_264 ) ;
F_325 ( V_730 ) ;
F_325 ( V_731 ) ;
F_325 ( V_732 ) ;
F_325 ( V_632 ) ;
F_325 ( V_733 ) ;
F_325 ( V_729 ) ;
F_325 ( V_330 ) ;
F_325 ( V_339 ) ;
F_325 ( V_335 ) ;
F_321 ( V_157 ) ;
F_316 ( V_741 ) ;
}
