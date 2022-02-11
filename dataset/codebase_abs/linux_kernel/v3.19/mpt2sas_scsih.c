static int
F_1 ( const char * V_1 , struct V_2 * V_3 )
{
int V_4 = F_2 ( V_1 , V_3 ) ;
struct V_5 * V_6 ;
if ( V_4 )
return V_4 ;
F_3 ( V_7 L_1 , V_8 ) ;
F_4 (ioc, &mpt2sas_ioc_list, list)
V_6 -> V_8 = V_8 ;
return 0 ;
}
static inline int
F_5 ( T_1 V_9 ,
T_2 * V_10 )
{
return ( V_9 == F_6 ( V_10 -> V_11 ) ) ? 1 : 0 ;
}
static inline int
F_7 ( T_1 V_12 ,
T_3 * V_10 )
{
return ( V_12 == F_6 ( V_10 -> V_13 ) ) ? 1 : 0 ;
}
static inline int
F_8 ( T_1 V_14 , T_4 V_15 ,
T_5 * V_10 )
{
return ( V_14 == F_6 ( V_10 ->
V_16 ) && V_15 == F_9 ( V_10 ->
V_17 ) ) ? 1 : 0 ;
}
static int
F_10 ( T_1 V_9 , T_1 V_12 ,
T_1 V_14 , T_4 V_18 , T_6 V_19 ,
T_7 * V_10 )
{
int V_20 = 0 ;
switch ( V_19 ) {
case V_21 :
if ( ! V_9 )
break;
V_20 = F_5 (
V_9 , & V_10 -> V_22 ) ;
break;
case V_23 :
if ( ! V_14 )
break;
V_20 = F_8 (
V_14 ,
V_18 , & V_10 -> V_24 ) ;
break;
case V_25 :
if ( ! V_12 )
break;
V_20 = F_7 (
V_12 , & V_10 -> V_13 ) ;
break;
case V_26 :
break;
}
return V_20 ;
}
static int
F_11 ( struct V_5 * V_6 , T_4 V_27 ,
T_1 * V_9 )
{
T_8 V_28 ;
T_9 V_29 ;
T_10 V_30 ;
* V_9 = 0 ;
if ( V_27 <= V_6 -> V_31 . V_32 ) {
* V_9 = V_6 -> V_31 . V_9 ;
return 0 ;
}
if ( ( F_12 ( V_6 , & V_29 , & V_28 ,
V_33 , V_27 ) ) ) {
F_3 ( V_34 L_2 , V_6 -> V_35 ,
__FILE__ , __LINE__ , V_36 ) ;
return - V_37 ;
}
V_30 = F_9 ( V_29 . V_38 ) & V_39 ;
if ( V_30 == V_40 ) {
* V_9 = F_6 ( V_28 . V_11 ) ;
return 0 ;
}
if ( V_30 == V_41 )
return - V_37 ;
F_3 ( V_34 L_3
L_2 , V_6 -> V_35 , V_27 , V_30 ,
__FILE__ , __LINE__ , V_36 ) ;
return - V_42 ;
}
static void
F_13 ( struct V_5 * V_6 ,
void * V_43 , T_6 V_44 )
{
struct V_45 * V_46 ;
struct V_47 * V_48 ;
T_1 V_9 ;
T_1 V_12 ;
T_1 V_14 ;
T_4 V_18 ;
if ( ! V_6 -> V_49 )
return;
if ( ! V_6 -> V_50 . V_51 )
return;
if ( ! V_44 ) {
V_46 = V_43 ;
V_9 = V_46 -> V_9 ;
V_12 = V_46 -> V_12 ;
V_14 = V_46 -> V_14 ;
V_18 = V_46 -> V_18 ;
} else {
V_48 = V_43 ;
V_9 = V_48 -> V_52 ;
V_12 = 0 ;
V_14 = 0 ;
V_18 = 0 ;
}
if ( ! V_6 -> V_53 . V_43 ) {
if ( F_10 ( V_9 , V_12 ,
V_14 , V_18 ,
( V_6 -> V_54 . V_55 &
V_56 ) ,
& V_6 -> V_54 . V_57 ) ) {
F_14 ( V_6 , F_3 ( V_58
L_4 ,
V_6 -> V_35 , V_36 ,
( unsigned long long ) V_9 ) ) ;
V_6 -> V_53 . V_43 = V_43 ;
V_6 -> V_53 . V_44 = V_44 ;
}
}
if ( ! V_6 -> V_59 . V_43 ) {
if ( F_10 ( V_9 , V_12 ,
V_14 , V_18 ,
( V_6 -> V_54 . V_60 &
V_56 ) ,
& V_6 -> V_54 . V_61 ) ) {
F_14 ( V_6 , F_3 ( V_58
L_5 ,
V_6 -> V_35 , V_36 ,
( unsigned long long ) V_9 ) ) ;
V_6 -> V_59 . V_43 = V_43 ;
V_6 -> V_59 . V_44 = V_44 ;
}
}
if ( ! V_6 -> V_62 . V_43 ) {
if ( F_10 ( V_9 , V_12 ,
V_14 , V_18 ,
( V_6 -> V_54 . V_63 &
V_56 ) ,
& V_6 -> V_54 . V_64 ) ) {
F_14 ( V_6 , F_3 ( V_58
L_6 ,
V_6 -> V_35 , V_36 ,
( unsigned long long ) V_9 ) ) ;
V_6 -> V_62 . V_43 = V_43 ;
V_6 -> V_62 . V_44 = V_44 ;
}
}
}
struct V_45 *
F_15 ( struct V_5 * V_6 ,
T_1 V_9 )
{
struct V_45 * V_46 ;
F_4 (sas_device, &ioc->sas_device_list, list)
if ( V_46 -> V_9 == V_9 )
return V_46 ;
F_4 (sas_device, &ioc->sas_device_init_list, list)
if ( V_46 -> V_9 == V_9 )
return V_46 ;
return NULL ;
}
static struct V_45 *
F_16 ( struct V_5 * V_6 , T_4 V_27 )
{
struct V_45 * V_46 ;
F_4 (sas_device, &ioc->sas_device_list, list)
if ( V_46 -> V_27 == V_27 )
return V_46 ;
F_4 (sas_device, &ioc->sas_device_init_list, list)
if ( V_46 -> V_27 == V_27 )
return V_46 ;
return NULL ;
}
static void
F_17 ( struct V_5 * V_6 ,
struct V_45 * V_46 )
{
unsigned long V_65 ;
if ( ! V_46 )
return;
F_18 ( & V_6 -> V_66 , V_65 ) ;
F_19 ( & V_46 -> V_67 ) ;
F_20 ( V_46 ) ;
F_21 ( & V_6 -> V_66 , V_65 ) ;
}
static void
F_22 ( struct V_5 * V_6 ,
struct V_45 * V_46 )
{
unsigned long V_65 ;
F_23 ( V_6 , F_3 ( V_58 L_7
L_8 , V_6 -> V_35 , V_36 ,
V_46 -> V_27 , ( unsigned long long ) V_46 -> V_9 ) ) ;
F_18 ( & V_6 -> V_66 , V_65 ) ;
F_24 ( & V_46 -> V_67 , & V_6 -> V_68 ) ;
F_21 ( & V_6 -> V_66 , V_65 ) ;
if ( ! F_25 ( V_6 , V_46 -> V_27 ,
V_46 -> V_69 ) ) {
F_17 ( V_6 , V_46 ) ;
} else if ( ! V_46 -> V_70 ) {
if ( ! V_6 -> V_49 ) {
F_26 ( V_6 ,
V_46 -> V_9 ,
V_46 -> V_69 ) ;
F_17 ( V_6 , V_46 ) ;
}
}
}
static void
F_27 ( struct V_5 * V_6 ,
struct V_45 * V_46 )
{
unsigned long V_65 ;
F_23 ( V_6 , F_3 ( V_58 L_7
L_8 , V_6 -> V_35 , V_36 ,
V_46 -> V_27 , ( unsigned long long ) V_46 -> V_9 ) ) ;
F_18 ( & V_6 -> V_66 , V_65 ) ;
F_24 ( & V_46 -> V_67 , & V_6 -> V_71 ) ;
F_13 ( V_6 , V_46 , 0 ) ;
F_21 ( & V_6 -> V_66 , V_65 ) ;
}
static struct V_47 *
F_28 ( struct V_5 * V_6 , int V_72 , int V_73 )
{
struct V_47 * V_48 , * V_74 ;
V_74 = NULL ;
F_4 (raid_device, &ioc->raid_device_list, list) {
if ( V_48 -> V_72 == V_72 && V_48 -> V_73 == V_73 ) {
V_74 = V_48 ;
goto V_75;
}
}
V_75:
return V_74 ;
}
static struct V_47 *
F_29 ( struct V_5 * V_6 , T_4 V_27 )
{
struct V_47 * V_48 , * V_74 ;
V_74 = NULL ;
F_4 (raid_device, &ioc->raid_device_list, list) {
if ( V_48 -> V_27 != V_27 )
continue;
V_74 = V_48 ;
goto V_75;
}
V_75:
return V_74 ;
}
static struct V_47 *
F_30 ( struct V_5 * V_6 , T_1 V_52 )
{
struct V_47 * V_48 , * V_74 ;
V_74 = NULL ;
F_4 (raid_device, &ioc->raid_device_list, list) {
if ( V_48 -> V_52 != V_52 )
continue;
V_74 = V_48 ;
goto V_75;
}
V_75:
return V_74 ;
}
static void
F_31 ( struct V_5 * V_6 ,
struct V_47 * V_48 )
{
unsigned long V_65 ;
F_23 ( V_6 , F_3 ( V_58 L_7
L_9 , V_6 -> V_35 , V_36 ,
V_48 -> V_27 , ( unsigned long long ) V_48 -> V_52 ) ) ;
F_18 ( & V_6 -> V_76 , V_65 ) ;
F_24 ( & V_48 -> V_67 , & V_6 -> V_77 ) ;
F_21 ( & V_6 -> V_76 , V_65 ) ;
}
static void
F_32 ( struct V_5 * V_6 ,
struct V_47 * V_48 )
{
unsigned long V_65 ;
F_18 ( & V_6 -> V_76 , V_65 ) ;
F_19 ( & V_48 -> V_67 ) ;
F_20 ( V_48 ) ;
F_21 ( & V_6 -> V_76 , V_65 ) ;
}
struct V_78 *
F_33 ( struct V_5 * V_6 , T_4 V_27 )
{
struct V_78 * V_79 , * V_74 ;
V_74 = NULL ;
F_4 (sas_expander, &ioc->sas_expander_list, list) {
if ( V_79 -> V_27 != V_27 )
continue;
V_74 = V_79 ;
goto V_75;
}
V_75:
return V_74 ;
}
struct V_78 *
F_34 ( struct V_5 * V_6 ,
T_1 V_9 )
{
struct V_78 * V_79 , * V_74 ;
V_74 = NULL ;
F_4 (sas_expander, &ioc->sas_expander_list, list) {
if ( V_79 -> V_9 != V_9 )
continue;
V_74 = V_79 ;
goto V_75;
}
V_75:
return V_74 ;
}
static void
F_35 ( struct V_5 * V_6 ,
struct V_78 * V_79 )
{
unsigned long V_65 ;
F_18 ( & V_6 -> V_80 , V_65 ) ;
F_24 ( & V_79 -> V_67 , & V_6 -> V_81 ) ;
F_21 ( & V_6 -> V_80 , V_65 ) ;
}
static int
F_36 ( T_10 V_82 )
{
if ( V_82 & V_83 &&
( ( V_82 & V_84 ) |
( V_82 & V_85 ) |
( V_82 & V_86 ) ) )
return 1 ;
else
return 0 ;
}
static struct V_87 *
F_37 ( struct V_5 * V_6 , T_4 V_88 )
{
return V_6 -> V_89 [ V_88 - 1 ] . V_90 ;
}
static inline struct V_87 *
F_38 ( struct V_5 * V_6 , T_4 V_88 )
{
unsigned long V_65 ;
struct V_87 * V_90 ;
F_18 ( & V_6 -> V_91 , V_65 ) ;
V_90 = V_6 -> V_89 [ V_88 - 1 ] . V_90 ;
V_6 -> V_89 [ V_88 - 1 ] . V_90 = NULL ;
F_21 ( & V_6 -> V_91 , V_65 ) ;
return V_90 ;
}
static T_4
F_39 ( struct V_5 * V_6 , struct V_87
* V_90 )
{
T_4 V_88 ;
unsigned long V_65 ;
int V_92 ;
F_18 ( & V_6 -> V_91 , V_65 ) ;
V_88 = 0 ;
for ( V_92 = 0 ; V_92 < V_6 -> V_93 ; V_92 ++ ) {
if ( V_6 -> V_89 [ V_92 ] . V_90 == V_90 ) {
V_88 = V_6 -> V_89 [ V_92 ] . V_88 ;
goto V_75;
}
}
V_75:
F_21 ( & V_6 -> V_91 , V_65 ) ;
return V_88 ;
}
static T_6
F_40 ( struct V_5 * V_6 , int V_72 ,
int V_73 )
{
T_6 V_94 ;
unsigned long V_65 ;
int V_92 ;
F_18 ( & V_6 -> V_91 , V_65 ) ;
V_94 = 0 ;
for ( V_92 = 0 ; V_92 < V_6 -> V_93 ; V_92 ++ ) {
if ( V_6 -> V_89 [ V_92 ] . V_90 &&
( V_6 -> V_89 [ V_92 ] . V_90 -> V_43 -> V_72 == V_72 &&
V_6 -> V_89 [ V_92 ] . V_90 -> V_43 -> V_73 == V_73 ) ) {
V_94 = 1 ;
goto V_75;
}
}
V_75:
F_21 ( & V_6 -> V_91 , V_65 ) ;
return V_94 ;
}
static T_6
F_41 ( struct V_5 * V_6 , int V_72 ,
unsigned int V_95 , int V_73 )
{
T_6 V_94 ;
unsigned long V_65 ;
int V_92 ;
F_18 ( & V_6 -> V_91 , V_65 ) ;
V_94 = 0 ;
for ( V_92 = 0 ; V_92 < V_6 -> V_93 ; V_92 ++ ) {
if ( V_6 -> V_89 [ V_92 ] . V_90 &&
( V_6 -> V_89 [ V_92 ] . V_90 -> V_43 -> V_72 == V_72 &&
V_6 -> V_89 [ V_92 ] . V_90 -> V_43 -> V_73 == V_73 &&
V_6 -> V_89 [ V_92 ] . V_90 -> V_43 -> V_95 == V_95 ) ) {
V_94 = 1 ;
goto V_75;
}
}
V_75:
F_21 ( & V_6 -> V_91 , V_65 ) ;
return V_94 ;
}
static struct V_96 *
F_42 ( struct V_5 * V_6 , T_4 V_88 )
{
struct V_96 * V_97 ;
unsigned long V_65 ;
F_18 ( & V_6 -> V_91 , V_65 ) ;
if ( F_43 ( & V_6 -> V_98 ) ) {
F_21 ( & V_6 -> V_91 , V_65 ) ;
F_44 ( V_6 , F_3 ( V_99 L_10
L_11 , V_6 -> V_35 ) ) ;
return NULL ;
}
V_97 = F_45 ( V_6 -> V_98 . V_100 ,
struct V_96 , V_101 ) ;
F_46 ( & V_97 -> V_101 ) ;
F_24 ( & V_97 -> V_101 ,
& V_6 -> V_89 [ V_88 - 1 ] . V_102 ) ;
F_21 ( & V_6 -> V_91 , V_65 ) ;
return V_97 ;
}
static int
F_47 ( struct V_5 * V_6 ,
struct V_87 * V_90 , T_4 V_88 )
{
T_11 * V_103 ;
T_12 V_104 ;
struct V_105 * V_106 ;
void * V_107 , * V_108 ;
T_10 V_109 ;
T_10 V_110 ;
T_10 V_111 ;
int V_112 ;
T_10 V_113 ;
T_10 V_114 ;
T_10 V_115 ;
T_10 V_116 ;
struct V_96 * V_97 ;
V_103 = F_48 ( V_6 , V_88 ) ;
V_114 = V_117 ;
if ( V_90 -> V_118 == V_119 )
V_114 |= V_120 ;
V_115 = ( V_114 | V_121 )
<< V_122 ;
V_116 = ( V_114 | V_121 |
V_123 | V_124 )
<< V_122 ;
V_114 = V_114 << V_122 ;
V_106 = F_49 ( V_90 ) ;
V_112 = F_50 ( V_90 ) ;
if ( V_112 < 0 ) {
F_51 ( V_125 , V_90 -> V_43 , L_12
L_13 , F_52 ( V_90 ) ) ;
return - V_126 ;
}
V_107 = & V_103 -> V_127 ;
V_113 = V_6 -> V_128 ;
if ( V_112 <= V_113 )
goto V_129;
V_103 -> V_130 = ( F_53 ( T_11 , V_127 ) +
( V_113 * V_6 -> V_131 ) ) / 4 ;
while ( V_113 ) {
if ( V_113 == 1 )
V_6 -> V_132 ( V_107 ,
V_115 | F_54 ( V_106 ) ,
F_55 ( V_106 ) ) ;
else
V_6 -> V_132 ( V_107 , V_114 |
F_54 ( V_106 ) , F_55 ( V_106 ) ) ;
V_106 = F_56 ( V_106 ) ;
V_107 += V_6 -> V_131 ;
V_112 -- ;
V_113 -- ;
}
V_111 = V_133 << V_122 ;
V_97 = F_42 ( V_6 , V_88 ) ;
if ( ! V_97 )
return - 1 ;
V_108 = V_97 -> V_134 ;
V_104 = V_97 -> V_135 ;
do {
V_113 = ( V_112 <=
V_6 -> V_136 ) ? V_112 :
V_6 -> V_136 ;
V_109 = ( V_112 == V_113 ) ?
0 : ( V_113 * V_6 -> V_131 ) / 4 ;
V_110 = V_113 * V_6 -> V_131 ;
if ( V_109 ) {
V_109 = V_109 <<
V_137 ;
V_110 += V_6 -> V_131 ;
}
V_6 -> V_132 ( V_107 , V_111 | V_109 |
V_110 , V_104 ) ;
V_107 = V_108 ;
if ( ! V_109 )
goto V_129;
while ( V_113 ) {
if ( V_113 == 1 )
V_6 -> V_132 ( V_107 ,
V_115 |
F_54 ( V_106 ) ,
F_55 ( V_106 ) ) ;
else
V_6 -> V_132 ( V_107 , V_114 |
F_54 ( V_106 ) ,
F_55 ( V_106 ) ) ;
V_106 = F_56 ( V_106 ) ;
V_107 += V_6 -> V_131 ;
V_112 -- ;
V_113 -- ;
}
V_97 = F_42 ( V_6 , V_88 ) ;
if ( ! V_97 )
return - 1 ;
V_108 = V_97 -> V_134 ;
V_104 = V_97 -> V_135 ;
} while ( 1 );
V_129:
while ( V_112 ) {
if ( V_112 == 1 )
V_6 -> V_132 ( V_107 , V_116 |
F_54 ( V_106 ) , F_55 ( V_106 ) ) ;
else
V_6 -> V_132 ( V_107 , V_114 |
F_54 ( V_106 ) , F_55 ( V_106 ) ) ;
V_106 = F_56 ( V_106 ) ;
V_107 += V_6 -> V_131 ;
V_112 -- ;
}
return 0 ;
}
static int
F_57 ( struct V_138 * V_139 , int V_140 )
{
struct V_141 * V_142 = V_139 -> V_143 ;
int V_144 ;
struct V_5 * V_6 = F_58 ( V_142 ) ;
struct V_145 * V_146 ;
struct V_147 * V_148 ;
struct V_45 * V_46 ;
unsigned long V_65 ;
V_144 = V_142 -> V_149 ;
V_146 = V_139 -> V_150 ;
if ( ! V_146 )
goto V_151;
V_148 = V_146 -> V_152 ;
if ( ! V_148 )
goto V_151;
if ( ( V_148 -> V_65 & V_153 ) )
goto V_151;
F_18 ( & V_6 -> V_66 , V_65 ) ;
V_46 = F_15 ( V_6 ,
V_146 -> V_152 -> V_9 ) ;
if ( V_46 && V_46 -> V_82 &
V_86 )
V_144 = V_154 ;
F_21 ( & V_6 -> V_66 , V_65 ) ;
V_151:
if ( ! V_139 -> V_155 )
V_144 = 1 ;
if ( V_140 > V_144 )
V_140 = V_144 ;
return F_59 ( V_139 , V_140 ) ;
}
static int
F_60 ( struct V_156 * V_70 )
{
struct V_141 * V_142 = F_61 ( & V_70 -> V_157 ) ;
struct V_5 * V_6 = F_58 ( V_142 ) ;
struct V_147 * V_148 ;
struct V_45 * V_46 ;
struct V_47 * V_48 ;
unsigned long V_65 ;
struct V_158 * V_159 ;
V_148 = F_62 ( sizeof( * V_148 ) ,
V_160 ) ;
if ( ! V_148 )
return - V_126 ;
V_70 -> V_150 = V_148 ;
V_148 -> V_70 = V_70 ;
V_148 -> V_27 = V_161 ;
if ( V_70 -> V_73 == V_162 ) {
F_18 ( & V_6 -> V_76 , V_65 ) ;
V_48 = F_28 ( V_6 , V_70 -> V_72 ,
V_70 -> V_73 ) ;
if ( V_48 ) {
V_148 -> V_27 = V_48 -> V_27 ;
V_148 -> V_9 = V_48 -> V_52 ;
V_148 -> V_65 |= V_153 ;
if ( V_6 -> V_163 )
V_148 -> V_48 = V_48 ;
V_48 -> V_70 = V_70 ;
}
F_21 ( & V_6 -> V_76 , V_65 ) ;
return 0 ;
}
F_18 ( & V_6 -> V_66 , V_65 ) ;
V_159 = F_63 ( V_70 -> V_157 . V_164 ) ;
V_46 = F_15 ( V_6 ,
V_159 -> V_165 . V_9 ) ;
if ( V_46 ) {
V_148 -> V_27 = V_46 -> V_27 ;
V_148 -> V_9 = V_46 -> V_9 ;
V_46 -> V_70 = V_70 ;
V_46 -> V_72 = V_70 -> V_72 ;
V_46 -> V_73 = V_70 -> V_73 ;
if ( F_64 ( V_46 -> V_27 , V_6 -> V_166 ) )
V_148 -> V_65 |=
V_167 ;
}
F_21 ( & V_6 -> V_66 , V_65 ) ;
return 0 ;
}
static void
F_65 ( struct V_156 * V_70 )
{
struct V_141 * V_142 = F_61 ( & V_70 -> V_157 ) ;
struct V_5 * V_6 = F_58 ( V_142 ) ;
struct V_147 * V_148 ;
struct V_45 * V_46 ;
struct V_47 * V_48 ;
unsigned long V_65 ;
struct V_158 * V_159 ;
V_148 = V_70 -> V_150 ;
if ( ! V_148 )
return;
if ( V_70 -> V_73 == V_162 ) {
F_18 ( & V_6 -> V_76 , V_65 ) ;
V_48 = F_28 ( V_6 , V_70 -> V_72 ,
V_70 -> V_73 ) ;
if ( V_48 ) {
V_48 -> V_70 = NULL ;
V_48 -> V_139 = NULL ;
}
F_21 ( & V_6 -> V_76 , V_65 ) ;
goto V_75;
}
F_18 ( & V_6 -> V_66 , V_65 ) ;
V_159 = F_63 ( V_70 -> V_157 . V_164 ) ;
V_46 = F_15 ( V_6 ,
V_159 -> V_165 . V_9 ) ;
if ( V_46 && ( V_46 -> V_70 == V_70 ) &&
( V_46 -> V_72 == V_70 -> V_72 ) &&
( V_46 -> V_73 == V_70 -> V_73 ) )
V_46 -> V_70 = NULL ;
F_21 ( & V_6 -> V_66 , V_65 ) ;
V_75:
F_20 ( V_148 ) ;
V_70 -> V_150 = NULL ;
}
static int
F_66 ( struct V_138 * V_139 )
{
struct V_141 * V_142 ;
struct V_5 * V_6 ;
struct V_147 * V_148 ;
struct V_145 * V_146 ;
struct V_156 * V_70 ;
struct V_47 * V_48 ;
struct V_45 * V_46 ;
unsigned long V_65 ;
V_146 = F_62 ( sizeof( * V_146 ) ,
V_160 ) ;
if ( ! V_146 )
return - V_126 ;
V_146 -> V_95 = V_139 -> V_95 ;
V_146 -> V_65 = V_168 ;
V_70 = V_156 ( V_139 ) ;
V_148 = V_70 -> V_150 ;
V_148 -> V_169 ++ ;
V_146 -> V_152 = V_148 ;
V_139 -> V_150 = V_146 ;
if ( ( V_148 -> V_65 & V_167 ) )
V_139 -> V_170 = 1 ;
V_142 = F_61 ( & V_70 -> V_157 ) ;
V_6 = F_58 ( V_142 ) ;
if ( V_70 -> V_73 == V_162 ) {
F_18 ( & V_6 -> V_76 , V_65 ) ;
V_48 = F_28 ( V_6 ,
V_70 -> V_72 , V_70 -> V_73 ) ;
if ( V_48 )
V_48 -> V_139 = V_139 ;
F_21 ( & V_6 -> V_76 , V_65 ) ;
}
if ( ! ( V_148 -> V_65 & V_153 ) ) {
F_18 ( & V_6 -> V_66 , V_65 ) ;
V_46 = F_15 ( V_6 ,
V_148 -> V_9 ) ;
if ( V_46 && ( V_46 -> V_70 == NULL ) ) {
F_51 ( V_7 , V_139 ,
L_14 ,
V_36 , __LINE__ ) ;
V_46 -> V_70 = V_70 ;
}
F_21 ( & V_6 -> V_66 , V_65 ) ;
}
return 0 ;
}
static void
F_67 ( struct V_138 * V_139 )
{
struct V_147 * V_148 ;
struct V_156 * V_70 ;
struct V_141 * V_142 ;
struct V_5 * V_6 ;
struct V_45 * V_46 ;
unsigned long V_65 ;
if ( ! V_139 -> V_150 )
return;
V_70 = V_156 ( V_139 ) ;
V_148 = V_70 -> V_150 ;
V_148 -> V_169 -- ;
V_142 = F_61 ( & V_70 -> V_157 ) ;
V_6 = F_58 ( V_142 ) ;
if ( ! ( V_148 -> V_65 & V_153 ) ) {
F_18 ( & V_6 -> V_66 , V_65 ) ;
V_46 = F_15 ( V_6 ,
V_148 -> V_9 ) ;
if ( V_46 && ! V_148 -> V_169 )
V_46 -> V_70 = NULL ;
F_21 ( & V_6 -> V_66 , V_65 ) ;
}
F_20 ( V_139 -> V_150 ) ;
V_139 -> V_150 = NULL ;
}
static void
F_68 ( struct V_5 * V_6 ,
T_4 V_27 , struct V_138 * V_139 )
{
T_9 V_29 ;
T_8 V_28 ;
T_10 V_30 ;
T_4 V_65 ;
T_10 V_82 ;
if ( ( F_12 ( V_6 , & V_29 , & V_28 ,
V_33 , V_27 ) ) ) {
F_3 ( V_34 L_2 ,
V_6 -> V_35 , __FILE__ , __LINE__ , V_36 ) ;
return;
}
V_30 = F_9 ( V_29 . V_38 ) &
V_39 ;
if ( V_30 != V_40 ) {
F_3 ( V_34 L_2 ,
V_6 -> V_35 , __FILE__ , __LINE__ , V_36 ) ;
return;
}
V_65 = F_9 ( V_28 . V_171 ) ;
V_82 = F_69 ( V_28 . V_172 ) ;
F_51 ( V_7 , V_139 ,
L_15
L_16 ,
( V_82 & V_173 ) ? L_17 : L_18 ,
( V_65 & V_174 ) ? L_17 : L_18 ,
( V_65 & V_175 ) ? L_17 :
L_18 ,
( V_65 & V_176 ) ? L_17 : L_18 ,
( V_65 & V_177 ) ? L_17 : L_18 ,
( V_65 & V_178 ) ? L_17 : L_18 ) ;
}
static int
F_70 ( struct V_43 * V_157 )
{
struct V_138 * V_139 = F_71 ( V_157 ) ;
struct V_5 * V_6 = F_58 ( V_139 -> V_143 ) ;
if ( V_6 -> V_163 )
return 0 ;
return ( V_139 -> V_73 == V_162 ) ? 1 : 0 ;
}
static void
F_72 ( struct V_43 * V_157 )
{
struct V_138 * V_139 = F_71 ( V_157 ) ;
struct V_5 * V_6 = F_58 ( V_139 -> V_143 ) ;
static struct V_47 * V_48 ;
unsigned long V_65 ;
T_13 V_179 ;
T_9 V_29 ;
T_10 V_180 ;
T_6 V_181 ;
T_4 V_27 ;
V_181 = 0 ;
V_27 = 0 ;
if ( V_6 -> V_163 )
goto V_75;
F_18 ( & V_6 -> V_76 , V_65 ) ;
V_48 = F_28 ( V_6 , V_139 -> V_72 ,
V_139 -> V_73 ) ;
if ( V_48 ) {
V_27 = V_48 -> V_27 ;
V_181 = V_48 -> V_181 ;
}
F_21 ( & V_6 -> V_76 , V_65 ) ;
if ( ! V_27 )
goto V_75;
if ( F_73 ( V_6 , & V_29 , & V_179 ,
V_182 , V_27 ,
sizeof( T_13 ) ) ) {
F_3 ( V_34 L_2 ,
V_6 -> V_35 , __FILE__ , __LINE__ , V_36 ) ;
V_181 = 0 ;
goto V_75;
}
V_180 = F_69 ( V_179 . V_183 ) ;
if ( ! ( V_180 &
V_184 ) )
V_181 = 0 ;
V_75:
F_74 ( V_185 , V_157 , V_181 ) ;
}
static void
F_75 ( struct V_43 * V_157 )
{
struct V_138 * V_139 = F_71 ( V_157 ) ;
struct V_5 * V_6 = F_58 ( V_139 -> V_143 ) ;
static struct V_47 * V_48 ;
unsigned long V_65 ;
T_13 V_179 ;
T_9 V_29 ;
T_10 V_186 ;
enum V_187 V_188 = V_189 ;
T_4 V_27 = 0 ;
F_18 ( & V_6 -> V_76 , V_65 ) ;
V_48 = F_28 ( V_6 , V_139 -> V_72 ,
V_139 -> V_73 ) ;
if ( V_48 )
V_27 = V_48 -> V_27 ;
F_21 ( & V_6 -> V_76 , V_65 ) ;
if ( ! V_48 )
goto V_75;
if ( F_73 ( V_6 , & V_29 , & V_179 ,
V_182 , V_27 ,
sizeof( T_13 ) ) ) {
F_3 ( V_34 L_2 ,
V_6 -> V_35 , __FILE__ , __LINE__ , V_36 ) ;
goto V_75;
}
V_186 = F_69 ( V_179 . V_183 ) ;
if ( V_186 & V_184 ) {
V_188 = V_190 ;
goto V_75;
}
switch ( V_179 . V_191 ) {
case V_192 :
case V_193 :
V_188 = V_194 ;
break;
case V_195 :
V_188 = V_196 ;
break;
case V_197 :
case V_198 :
V_188 = V_199 ;
break;
}
V_75:
F_76 ( V_185 , V_157 , V_188 ) ;
}
static void
F_77 ( struct V_138 * V_139 , T_6 V_200 )
{
enum V_201 V_202 = V_203 ;
switch ( V_200 ) {
case V_204 :
V_202 = V_205 ;
break;
case V_206 :
V_202 = V_207 ;
break;
case V_208 :
V_202 = V_209 ;
break;
case V_210 :
V_202 = V_211 ;
break;
}
F_78 ( V_185 , & V_139 -> V_212 , V_202 ) ;
}
static int
F_79 ( struct V_5 * V_6 ,
struct V_47 * V_48 )
{
T_13 * V_179 ;
T_14 V_213 ;
T_8 V_28 ;
T_9 V_29 ;
T_4 V_214 ;
T_6 V_215 ;
if ( ( F_80 ( V_6 , V_48 -> V_27 ,
& V_215 ) ) || ! V_215 ) {
F_44 ( V_6 , F_3 ( V_99
L_2 , V_6 -> V_35 , __FILE__ , __LINE__ ,
V_36 ) ) ;
return 1 ;
}
V_48 -> V_215 = V_215 ;
V_214 = F_53 ( T_13 , V_216 ) + ( V_215 *
sizeof( V_217 ) ) ;
V_179 = F_62 ( V_214 , V_160 ) ;
if ( ! V_179 ) {
F_44 ( V_6 , F_3 ( V_99
L_2 , V_6 -> V_35 , __FILE__ , __LINE__ ,
V_36 ) ) ;
return 1 ;
}
if ( ( F_73 ( V_6 , & V_29 , V_179 ,
V_182 , V_48 -> V_27 , V_214 ) ) ) {
F_44 ( V_6 , F_3 ( V_99
L_2 , V_6 -> V_35 , __FILE__ , __LINE__ ,
V_36 ) ) ;
F_20 ( V_179 ) ;
return 1 ;
}
V_48 -> V_200 = V_179 -> V_218 ;
if ( ! ( F_81 ( V_6 , & V_29 ,
& V_213 , V_219 ,
V_179 -> V_216 [ 0 ] . V_220 ) ) ) {
if ( ! ( F_12 ( V_6 , & V_29 ,
& V_28 , V_33 ,
F_9 ( V_213 . V_221 ) ) ) ) {
V_48 -> V_82 =
F_69 ( V_28 . V_172 ) ;
}
}
F_20 ( V_179 ) ;
return 0 ;
}
static void
F_82 ( struct V_5 * V_6 )
{
T_15 V_222 ;
T_9 V_29 ;
struct V_47 * V_48 ;
T_4 V_27 ;
T_4 V_30 ;
unsigned long V_65 ;
V_27 = 0xFFFF ;
while ( ! ( F_83 ( V_6 , & V_29 ,
& V_222 , V_223 , V_27 ) ) ) {
V_30 = F_9 ( V_29 . V_38 ) &
V_39 ;
if ( V_30 == V_41 )
break;
V_27 = F_9 ( V_222 . V_221 ) ;
F_18 ( & V_6 -> V_76 , V_65 ) ;
V_48 = F_29 ( V_6 , V_27 ) ;
if ( V_48 )
V_48 -> V_224 = 0 ;
F_21 ( & V_6 -> V_76 , V_65 ) ;
}
return;
}
static T_6
F_84 ( struct V_5 * V_6 )
{
T_15 V_222 ;
T_9 V_29 ;
T_4 V_27 ;
T_6 V_225 = 0 ;
T_4 V_30 ;
V_27 = 0xFFFF ;
while ( ! ( F_83 ( V_6 , & V_29 ,
& V_222 , V_223 , V_27 ) ) ) {
V_30 = F_9 ( V_29 . V_38 ) &
V_39 ;
if ( V_30 == V_41 )
break;
V_225 ++ ;
V_27 = F_9 ( V_222 . V_221 ) ;
}
return V_225 ;
}
static void
F_85 ( struct V_5 * V_6 ,
struct V_47 * V_48 )
{
T_13 * V_179 ;
T_14 V_213 ;
T_9 V_29 ;
T_4 V_214 ;
T_6 V_215 , V_226 ;
unsigned long V_227 , V_228 ;
T_6 V_229 , V_230 ;
T_1 V_231 ;
if ( ! V_6 -> V_163 )
return;
if ( V_6 -> V_232 == V_233 ) {
F_3 ( V_58 L_19
L_20 , V_6 -> V_35 ) ;
return;
}
if ( F_84 ( V_6 ) > 1 ) {
F_82 ( V_6 ) ;
F_3 ( V_58 L_19
L_21 , V_6 -> V_35 ) ;
return;
}
if ( ( F_80 ( V_6 , V_48 -> V_27 ,
& V_215 ) ) || ! V_215 ) {
F_3 ( V_58 L_19
L_22 , V_6 -> V_35 ) ;
return;
}
V_214 = F_53 ( T_13 , V_216 ) + ( V_215 *
sizeof( V_217 ) ) ;
V_179 = F_62 ( V_214 , V_160 ) ;
if ( ! V_179 ) {
F_3 ( V_58 L_19
L_23 , V_6 -> V_35 ) ;
return;
}
if ( ( F_73 ( V_6 , & V_29 , V_179 ,
V_182 , V_48 -> V_27 , V_214 ) ) ) {
F_3 ( V_58 L_19
L_24 , V_6 -> V_35 ) ;
F_20 ( V_179 ) ;
return;
}
if ( V_215 > V_234 ) {
F_3 ( V_99 L_19
L_25
L_26 , V_6 -> V_35 , V_48 -> V_27 ,
V_215 , V_234 ) ;
F_20 ( V_179 ) ;
return;
}
for ( V_226 = 0 ; V_226 < V_215 ; V_226 ++ ) {
if ( F_81 ( V_6 , & V_29 ,
& V_213 , V_219 ,
V_179 -> V_216 [ V_226 ] . V_220 ) ||
F_9 ( V_213 . V_221 ) ==
V_161 ) {
F_3 ( V_58 L_27
L_28
L_29 ,
V_6 -> V_35 , V_48 -> V_27 ,
V_179 -> V_216 [ V_226 ] . V_220 ) ;
goto V_235;
}
V_231 = F_6 ( V_213 . V_236 ) ;
if ( V_231 >> 32 ) {
F_3 ( V_58 L_27
L_28
L_30 ,
V_6 -> V_35 , V_48 -> V_27 ,
F_9 ( V_213 . V_221 ) ,
( unsigned long long ) V_231 ) ;
goto V_235;
}
V_48 -> V_237 [ V_226 ] = F_9 ( V_213 . V_221 ) ;
}
if ( V_48 -> V_200 != V_204 ) {
F_3 ( V_58 L_19
L_31
L_32 , V_6 -> V_35 ,
V_48 -> V_27 , V_48 -> V_200 ,
( F_69 ( V_179 -> V_238 ) *
F_9 ( V_179 -> V_239 ) ) / 1024 ,
F_9 ( V_179 -> V_239 ) ) ;
goto V_235;
}
V_227 = F_69 ( V_179 -> V_238 ) ;
V_229 = F_86 ( & V_227 , 32 ) ;
if ( V_229 == 32 ) {
F_3 ( V_58 L_19
L_33 ,
V_6 -> V_35 , V_48 -> V_27 ,
( F_69 ( V_179 -> V_238 ) *
F_9 ( V_179 -> V_239 ) ) / 1024 ) ;
goto V_235;
}
V_48 -> V_240 = V_229 ;
V_228 = F_9 ( V_179 -> V_239 ) ;
V_230 = F_86 ( & V_228 , 16 ) ;
if ( V_230 == 16 ) {
F_3 ( V_58 L_19
L_34 ,
V_6 -> V_35 , V_48 -> V_27 ,
F_9 ( V_179 -> V_239 ) ) ;
goto V_235;
}
V_48 -> V_241 = V_230 ;
V_48 -> V_224 = 1 ;
F_3 ( V_58 L_35
L_36 , V_6 -> V_35 , V_48 -> V_27 ) ;
V_48 -> V_242 = F_6 ( V_179 -> V_243 ) ;
V_48 -> V_227 = F_69 ( V_179 -> V_238 ) ;
V_48 -> V_228 = F_9 ( V_179 -> V_239 ) ;
F_20 ( V_179 ) ;
return;
V_235:
V_48 -> V_224 = 0 ;
for ( V_226 = 0 ; V_226 < V_215 ; V_226 ++ )
V_48 -> V_237 [ V_226 ] = 0 ;
F_20 ( V_179 ) ;
return;
}
static void
F_87 ( struct V_5 * V_6 , struct V_138 * V_139 )
{
if ( V_139 -> type != V_244 )
return;
if ( ! ( V_6 -> V_245 . V_246 & V_247 ) )
return;
F_88 ( V_139 ) ;
F_51 ( V_7 , V_139 , L_37 ,
F_89 ( V_139 ) ? L_38 : L_39 ) ;
return;
}
static int
F_90 ( struct V_138 * V_139 )
{
struct V_141 * V_142 = V_139 -> V_143 ;
struct V_5 * V_6 = F_58 ( V_142 ) ;
struct V_145 * V_146 ;
struct V_147 * V_148 ;
struct V_45 * V_46 ;
struct V_47 * V_48 ;
unsigned long V_65 ;
int V_140 ;
T_6 V_248 = 0 ;
char * V_249 = L_40 ;
char * V_250 = L_40 ;
T_4 V_27 , V_251 = 0 ;
T_1 V_252 = 0 ;
V_140 = 1 ;
V_146 = V_139 -> V_150 ;
V_146 -> V_253 = 1 ;
V_146 -> V_65 &= ~ V_168 ;
V_148 = V_146 -> V_152 ;
V_27 = V_148 -> V_27 ;
if ( V_148 -> V_65 & V_153 ) {
F_18 ( & V_6 -> V_76 , V_65 ) ;
V_48 = F_29 ( V_6 , V_27 ) ;
F_21 ( & V_6 -> V_76 , V_65 ) ;
if ( ! V_48 ) {
F_44 ( V_6 , F_3 ( V_99
L_2 , V_6 -> V_35 , __FILE__ ,
__LINE__ , V_36 ) ) ;
return 1 ;
}
if ( F_79 ( V_6 , V_48 ) ) {
F_44 ( V_6 , F_3 ( V_99
L_2 , V_6 -> V_35 , __FILE__ ,
__LINE__ , V_36 ) ) ;
return 1 ;
}
F_85 ( V_6 , V_48 ) ;
if ( V_48 -> V_82 &
V_84 ) {
V_140 = V_254 ;
V_249 = L_41 ;
} else {
V_140 = V_154 ;
if ( V_48 -> V_82 &
V_86 )
V_249 = L_42 ;
else
V_249 = L_43 ;
}
switch ( V_48 -> V_200 ) {
case V_204 :
V_250 = L_44 ;
break;
case V_208 :
V_140 = V_255 ;
if ( V_6 -> V_256 . V_257 &&
( F_69 ( V_6 -> V_256 . V_258 ) &
V_259 ) &&
! ( V_48 -> V_215 % 2 ) )
V_250 = L_45 ;
else
V_250 = L_46 ;
break;
case V_210 :
V_140 = V_255 ;
V_250 = L_47 ;
break;
case V_206 :
V_140 = V_255 ;
V_250 = L_45 ;
break;
case V_260 :
default:
V_140 = V_255 ;
V_250 = L_48 ;
break;
}
if ( ! V_6 -> V_261 )
F_51 ( V_7 , V_139 , L_49
L_50 ,
V_250 , V_48 -> V_27 ,
( unsigned long long ) V_48 -> V_52 ,
V_48 -> V_215 , V_249 ) ;
F_57 ( V_139 , V_140 ) ;
if ( ! V_6 -> V_163 )
F_77 ( V_139 , V_48 -> V_200 ) ;
return 0 ;
}
if ( V_148 -> V_65 & V_167 ) {
if ( F_91 ( V_6 , V_27 ,
& V_251 ) ) {
F_44 ( V_6 , F_3 ( V_99
L_2 , V_6 -> V_35 ,
__FILE__ , __LINE__ , V_36 ) ) ;
return 1 ;
}
if ( V_251 && F_92 ( V_6 ,
V_251 , & V_252 ) ) {
F_44 ( V_6 , F_3 ( V_99
L_2 , V_6 -> V_35 ,
__FILE__ , __LINE__ , V_36 ) ) ;
return 1 ;
}
}
F_18 ( & V_6 -> V_66 , V_65 ) ;
V_46 = F_15 ( V_6 ,
V_146 -> V_152 -> V_9 ) ;
if ( ! V_46 ) {
F_21 ( & V_6 -> V_66 , V_65 ) ;
F_44 ( V_6 , F_3 ( V_99
L_2 , V_6 -> V_35 , __FILE__ ,
__LINE__ , V_36 ) ) ;
return 1 ;
}
V_46 -> V_251 = V_251 ;
V_46 -> V_252 = V_252 ;
if ( V_46 -> V_82 & V_84 ) {
V_140 = V_254 ;
V_248 = 1 ;
V_249 = L_41 ;
} else {
V_140 = V_154 ;
if ( V_46 -> V_82 & V_85 )
V_249 = L_43 ;
else if ( V_46 -> V_82 &
V_86 )
V_249 = L_42 ;
}
F_51 ( V_7 , V_139 , L_49
L_51 ,
V_249 , V_46 -> V_27 ,
( unsigned long long ) V_46 -> V_9 ,
V_46 -> V_262 ,
( unsigned long long ) V_46 -> V_12 ) ;
F_51 ( V_7 , V_139 , L_52
L_53 , V_249 ,
( unsigned long long ) V_46 -> V_14 ,
V_46 -> V_18 ) ;
F_21 ( & V_6 -> V_66 , V_65 ) ;
if ( ! V_248 )
F_68 ( V_6 , V_27 , V_139 ) ;
F_57 ( V_139 , V_140 ) ;
if ( V_248 ) {
F_93 ( V_139 ) ;
F_87 ( V_6 , V_139 ) ;
}
return 0 ;
}
static int
F_94 ( struct V_138 * V_139 , struct V_263 * V_264 ,
T_16 V_265 , int V_266 [] )
{
int V_267 ;
int V_268 ;
T_16 V_269 ;
T_17 V_270 ;
V_267 = 64 ;
V_268 = 32 ;
V_270 = V_267 * V_268 ;
V_269 = V_265 ;
F_95 ( V_269 , V_270 ) ;
if ( ( T_17 ) V_265 >= 0x200000 ) {
V_267 = 255 ;
V_268 = 63 ;
V_270 = V_267 * V_268 ;
V_269 = V_265 ;
F_95 ( V_269 , V_270 ) ;
}
V_266 [ 0 ] = V_267 ;
V_266 [ 1 ] = V_268 ;
V_266 [ 2 ] = V_269 ;
return 0 ;
}
static void
F_96 ( struct V_5 * V_6 , T_6 V_271 )
{
char * V_272 ;
switch ( V_271 ) {
case V_273 :
V_272 = L_54 ;
break;
case V_274 :
V_272 = L_55 ;
break;
case V_275 :
V_272 = L_56 ;
break;
case V_276 :
V_272 = L_57 ;
break;
case V_277 :
V_272 = L_58 ;
break;
case V_278 :
V_272 = L_59 ;
break;
case 0xA :
V_272 = L_60 ;
break;
case V_279 :
V_272 = L_61 ;
break;
default:
V_272 = L_62 ;
break;
}
F_3 ( V_99 L_63 ,
V_6 -> V_35 , V_271 , V_272 ) ;
}
static T_6
F_97 ( struct V_5 * V_6 , T_4 V_88 , T_6 V_280 , T_10 V_281 )
{
T_18 * V_29 ;
if ( V_6 -> V_282 . V_283 == V_284 )
return 1 ;
if ( V_6 -> V_282 . V_88 != V_88 )
return 1 ;
F_98 ( V_6 ) ;
V_6 -> V_282 . V_283 |= V_285 ;
V_29 = F_99 ( V_6 , V_281 ) ;
if ( V_29 ) {
memcpy ( V_6 -> V_282 . V_281 , V_29 , V_29 -> V_286 * 4 ) ;
V_6 -> V_282 . V_283 |= V_287 ;
}
V_6 -> V_282 . V_283 &= ~ V_288 ;
F_100 ( & V_6 -> V_282 . V_289 ) ;
return 1 ;
}
void
F_101 ( struct V_5 * V_6 , T_4 V_27 )
{
struct V_145 * V_146 ;
struct V_138 * V_139 ;
T_6 V_290 = 0 ;
F_102 (sdev, ioc->shost) {
if ( V_290 )
continue;
V_146 = V_139 -> V_150 ;
if ( ! V_146 )
continue;
if ( V_146 -> V_152 -> V_27 == V_27 ) {
V_146 -> V_152 -> V_291 = 1 ;
V_290 = 1 ;
V_6 -> V_292 = 1 ;
}
}
}
void
F_103 ( struct V_5 * V_6 , T_4 V_27 )
{
struct V_145 * V_146 ;
struct V_138 * V_139 ;
T_6 V_290 = 0 ;
F_102 (sdev, ioc->shost) {
if ( V_290 )
continue;
V_146 = V_139 -> V_150 ;
if ( ! V_146 )
continue;
if ( V_146 -> V_152 -> V_27 == V_27 ) {
V_146 -> V_152 -> V_291 = 0 ;
V_290 = 1 ;
V_6 -> V_292 = 0 ;
}
}
}
int
F_104 ( struct V_5 * V_6 , T_4 V_27 , T_19 V_73 ,
T_19 V_72 , T_19 V_95 , T_6 type , T_4 V_293 , T_17 V_294 ,
enum V_295 V_296 )
{
T_20 * V_103 ;
T_21 * V_29 ;
T_4 V_88 = 0 ;
T_10 V_297 ;
unsigned long V_298 ;
struct V_299 * V_89 = NULL ;
int V_20 ;
if ( V_296 == V_300 )
F_105 ( & V_6 -> V_282 . V_301 ) ;
if ( V_6 -> V_282 . V_283 != V_284 ) {
F_3 ( V_58 L_64 ,
V_36 , V_6 -> V_35 ) ;
V_20 = V_302 ;
goto V_303;
}
if ( V_6 -> V_304 || V_6 -> V_305 ||
V_6 -> V_306 ) {
F_3 ( V_58 L_65 ,
V_36 , V_6 -> V_35 ) ;
V_20 = V_302 ;
goto V_303;
}
V_297 = F_106 ( V_6 , 0 ) ;
if ( V_297 & V_307 ) {
F_107 ( V_6 , F_3 ( V_58 L_66
L_67 , V_6 -> V_35 ) ) ;
V_20 = F_108 ( V_6 , V_308 ,
V_309 ) ;
V_20 = ( ! V_20 ) ? V_310 : V_302 ;
goto V_303;
}
if ( ( V_297 & V_311 ) == V_312 ) {
F_109 ( V_6 , V_297 &
V_313 ) ;
V_20 = F_108 ( V_6 , V_308 ,
V_309 ) ;
V_20 = ( ! V_20 ) ? V_310 : V_302 ;
goto V_303;
}
V_88 = F_110 ( V_6 , V_6 -> V_314 ) ;
if ( ! V_88 ) {
F_3 ( V_34 L_68 ,
V_6 -> V_35 , V_36 ) ;
V_20 = V_302 ;
goto V_303;
}
if ( type == V_315 )
V_89 = & V_6 -> V_89 [ V_293 - 1 ] ;
F_111 ( V_6 , F_3 ( V_58 L_69
L_70 , V_6 -> V_35 , V_27 , type ,
V_293 ) ) ;
V_6 -> V_282 . V_283 = V_288 ;
V_103 = F_48 ( V_6 , V_88 ) ;
V_6 -> V_282 . V_88 = V_88 ;
memset ( V_103 , 0 , sizeof( T_20 ) ) ;
memset ( V_6 -> V_282 . V_281 , 0 , sizeof( T_21 ) ) ;
V_103 -> V_316 = V_317 ;
V_103 -> V_221 = F_112 ( V_27 ) ;
V_103 -> V_318 = type ;
V_103 -> V_319 = F_112 ( V_293 ) ;
F_113 ( V_95 , (struct V_320 * ) V_103 -> V_321 ) ;
F_101 ( V_6 , V_27 ) ;
F_114 ( & V_6 -> V_282 . V_289 ) ;
F_115 ( V_6 , V_88 ) ;
V_298 = F_116 ( & V_6 -> V_282 . V_289 , V_294 * V_322 ) ;
if ( ! ( V_6 -> V_282 . V_283 & V_285 ) ) {
F_3 ( V_34 L_71 ,
V_6 -> V_35 , V_36 ) ;
F_117 ( V_103 ,
sizeof( T_20 ) / 4 ) ;
if ( ! ( V_6 -> V_282 . V_283 & V_323 ) ) {
V_20 = F_108 ( V_6 , V_308 ,
V_309 ) ;
V_20 = ( ! V_20 ) ? V_310 : V_302 ;
V_6 -> V_282 . V_283 = V_284 ;
F_103 ( V_6 , V_27 ) ;
goto V_303;
}
}
if ( V_6 -> V_282 . V_283 & V_287 ) {
V_29 = V_6 -> V_282 . V_281 ;
F_111 ( V_6 , F_3 ( V_58 L_72
L_73 ,
V_6 -> V_35 , F_9 ( V_29 -> V_38 ) ,
F_69 ( V_29 -> V_324 ) ,
F_69 ( V_29 -> V_325 ) ) ) ;
if ( V_6 -> V_8 & V_326 ) {
F_96 ( V_6 , V_29 -> V_327 ) ;
if ( V_29 -> V_38 )
F_117 ( V_103 ,
sizeof( T_20 ) / 4 ) ;
}
}
switch ( type ) {
case V_315 :
V_20 = V_310 ;
if ( V_89 -> V_90 == NULL )
break;
V_20 = V_302 ;
break;
case V_328 :
if ( F_40 ( V_6 , V_72 , V_73 ) )
V_20 = V_302 ;
else
V_20 = V_310 ;
break;
case V_329 :
case V_330 :
if ( F_41 ( V_6 , V_72 , V_95 , V_73 ) )
V_20 = V_302 ;
else
V_20 = V_310 ;
break;
case V_331 :
V_20 = V_310 ;
break;
default:
V_20 = V_302 ;
break;
}
F_103 ( V_6 , V_27 ) ;
V_6 -> V_282 . V_283 = V_284 ;
if ( V_296 == V_300 )
F_118 ( & V_6 -> V_282 . V_301 ) ;
return V_20 ;
V_303:
if ( V_296 == V_300 )
F_118 ( & V_6 -> V_282 . V_301 ) ;
return V_20 ;
}
static void
F_119 ( struct V_5 * V_6 , struct V_87 * V_90 )
{
struct V_156 * V_70 = V_90 -> V_43 -> V_332 ;
struct V_147 * V_333 = V_70 -> V_150 ;
struct V_45 * V_46 = NULL ;
unsigned long V_65 ;
char * V_334 = NULL ;
if ( ! V_333 )
return;
if ( V_6 -> V_261 )
V_334 = L_74 ;
else
V_334 = L_75 ;
F_120 ( V_90 ) ;
if ( V_333 -> V_65 & V_153 ) {
F_121 ( V_7 , V_70 , L_76
L_77 , V_334 , V_333 -> V_27 ,
V_334 , ( unsigned long long ) V_333 -> V_9 ) ;
} else {
F_18 ( & V_6 -> V_66 , V_65 ) ;
V_46 = F_15 ( V_6 ,
V_333 -> V_9 ) ;
if ( V_46 ) {
if ( V_333 -> V_65 &
V_167 ) {
F_121 ( V_7 , V_70 ,
L_78
L_79 ,
V_46 -> V_251 ,
( unsigned long long ) V_46 -> V_252 ) ;
}
F_121 ( V_7 , V_70 ,
L_80 ,
V_46 -> V_27 ,
( unsigned long long ) V_46 -> V_9 ,
V_46 -> V_262 ) ;
F_121 ( V_7 , V_70 ,
L_53 ,
( unsigned long long ) V_46 -> V_14 ,
V_46 -> V_18 ) ;
}
F_21 ( & V_6 -> V_66 , V_65 ) ;
}
}
static int
F_122 ( struct V_87 * V_90 )
{
struct V_5 * V_6 = F_58 ( V_90 -> V_43 -> V_143 ) ;
struct V_145 * V_146 ;
T_4 V_88 ;
T_4 V_27 ;
int V_74 ;
F_51 ( V_7 , V_90 -> V_43 , L_81
L_82 , V_90 ) ;
F_119 ( V_6 , V_90 ) ;
V_146 = V_90 -> V_43 -> V_150 ;
if ( ! V_146 || ! V_146 -> V_152 ) {
F_51 ( V_7 , V_90 -> V_43 , L_83
L_82 , V_90 ) ;
V_90 -> V_335 = V_336 << 16 ;
V_90 -> V_337 ( V_90 ) ;
V_74 = V_310 ;
goto V_75;
}
V_88 = F_39 ( V_6 , V_90 ) ;
if ( ! V_88 ) {
V_90 -> V_335 = V_338 << 16 ;
V_74 = V_310 ;
goto V_75;
}
if ( V_146 -> V_152 -> V_65 &
V_167 ||
V_146 -> V_152 -> V_65 & V_153 ) {
V_90 -> V_335 = V_338 << 16 ;
V_74 = V_302 ;
goto V_75;
}
F_123 ( V_6 ) ;
V_27 = V_146 -> V_152 -> V_27 ;
V_74 = F_104 ( V_6 , V_27 , V_90 -> V_43 -> V_73 ,
V_90 -> V_43 -> V_72 , V_90 -> V_43 -> V_95 ,
V_315 , V_88 , 30 , V_300 ) ;
V_75:
F_51 ( V_7 , V_90 -> V_43 , L_84 ,
( ( V_74 == V_310 ) ? L_85 : L_86 ) , V_90 ) ;
return V_74 ;
}
static int
F_124 ( struct V_87 * V_90 )
{
struct V_5 * V_6 = F_58 ( V_90 -> V_43 -> V_143 ) ;
struct V_145 * V_146 ;
struct V_45 * V_46 ;
unsigned long V_65 ;
T_4 V_27 ;
int V_74 ;
struct V_156 * V_70 = V_90 -> V_43 -> V_332 ;
F_121 ( V_7 , V_70 , L_87
L_82 , V_90 ) ;
F_119 ( V_6 , V_90 ) ;
V_146 = V_90 -> V_43 -> V_150 ;
if ( ! V_146 || ! V_146 -> V_152 ) {
F_121 ( V_7 , V_70 , L_83
L_82 , V_90 ) ;
V_90 -> V_335 = V_336 << 16 ;
V_90 -> V_337 ( V_90 ) ;
V_74 = V_310 ;
goto V_75;
}
V_27 = 0 ;
if ( V_146 -> V_152 -> V_65 &
V_167 ) {
F_18 ( & V_6 -> V_66 , V_65 ) ;
V_46 = F_16 ( V_6 ,
V_146 -> V_152 -> V_27 ) ;
if ( V_46 )
V_27 = V_46 -> V_251 ;
F_21 ( & V_6 -> V_66 , V_65 ) ;
} else
V_27 = V_146 -> V_152 -> V_27 ;
if ( ! V_27 ) {
V_90 -> V_335 = V_338 << 16 ;
V_74 = V_302 ;
goto V_75;
}
V_74 = F_104 ( V_6 , V_27 , V_90 -> V_43 -> V_73 ,
V_90 -> V_43 -> V_72 , V_90 -> V_43 -> V_95 ,
V_330 , 0 , 30 , V_300 ) ;
V_75:
F_51 ( V_7 , V_90 -> V_43 , L_88 ,
( ( V_74 == V_310 ) ? L_85 : L_86 ) , V_90 ) ;
return V_74 ;
}
static int
F_125 ( struct V_87 * V_90 )
{
struct V_5 * V_6 = F_58 ( V_90 -> V_43 -> V_143 ) ;
struct V_145 * V_146 ;
struct V_45 * V_46 ;
unsigned long V_65 ;
T_4 V_27 ;
int V_74 ;
struct V_156 * V_70 = V_90 -> V_43 -> V_332 ;
F_121 ( V_7 , V_70 , L_89
L_82 , V_90 ) ;
F_119 ( V_6 , V_90 ) ;
V_146 = V_90 -> V_43 -> V_150 ;
if ( ! V_146 || ! V_146 -> V_152 ) {
F_121 ( V_7 , V_70 , L_90
L_82 , V_90 ) ;
V_90 -> V_335 = V_336 << 16 ;
V_90 -> V_337 ( V_90 ) ;
V_74 = V_310 ;
goto V_75;
}
V_27 = 0 ;
if ( V_146 -> V_152 -> V_65 &
V_167 ) {
F_18 ( & V_6 -> V_66 , V_65 ) ;
V_46 = F_16 ( V_6 ,
V_146 -> V_152 -> V_27 ) ;
if ( V_46 )
V_27 = V_46 -> V_251 ;
F_21 ( & V_6 -> V_66 , V_65 ) ;
} else
V_27 = V_146 -> V_152 -> V_27 ;
if ( ! V_27 ) {
V_90 -> V_335 = V_338 << 16 ;
V_74 = V_302 ;
goto V_75;
}
V_74 = F_104 ( V_6 , V_27 , V_90 -> V_43 -> V_73 ,
V_90 -> V_43 -> V_72 , 0 , V_328 , 0 ,
30 , V_300 ) ;
V_75:
F_121 ( V_7 , V_70 , L_91 ,
( ( V_74 == V_310 ) ? L_85 : L_86 ) , V_90 ) ;
return V_74 ;
}
static int
F_126 ( struct V_87 * V_90 )
{
struct V_5 * V_6 = F_58 ( V_90 -> V_43 -> V_143 ) ;
int V_74 , V_339 ;
F_3 ( V_58 L_92 ,
V_6 -> V_35 , V_90 ) ;
F_120 ( V_90 ) ;
V_339 = F_108 ( V_6 , V_308 ,
V_309 ) ;
V_74 = ( V_339 < 0 ) ? V_302 : V_310 ;
F_3 ( V_58 L_93 ,
V_6 -> V_35 , ( ( V_74 == V_310 ) ? L_85 : L_86 ) , V_90 ) ;
return V_74 ;
}
static void
F_127 ( struct V_5 * V_6 , struct V_340 * V_341 )
{
unsigned long V_65 ;
if ( V_6 -> V_342 == NULL )
return;
F_18 ( & V_6 -> V_343 , V_65 ) ;
F_24 ( & V_341 -> V_67 , & V_6 -> V_344 ) ;
F_128 ( & V_341 -> V_345 , V_346 ) ;
F_129 ( V_6 -> V_342 ,
& V_341 -> V_345 , 0 ) ;
F_21 ( & V_6 -> V_343 , V_65 ) ;
}
static void
F_130 ( struct V_5 * V_6 , struct V_340
* V_341 )
{
unsigned long V_65 ;
F_18 ( & V_6 -> V_343 , V_65 ) ;
F_19 ( & V_341 -> V_67 ) ;
F_20 ( V_341 ) ;
F_21 ( & V_6 -> V_343 , V_65 ) ;
}
static void
F_131 ( struct V_5 * V_6 )
{
struct V_340 * V_341 ;
if ( V_6 -> V_49 )
return;
V_341 = F_62 ( sizeof( struct V_340 ) , V_347 ) ;
if ( ! V_341 )
return;
V_341 -> V_348 = V_349 ;
V_341 -> V_6 = V_6 ;
F_127 ( V_6 , V_341 ) ;
}
void
F_132 ( struct V_5 * V_6 )
{
struct V_340 * V_341 ;
V_341 = F_62 ( sizeof( struct V_340 ) , V_347 ) ;
if ( ! V_341 )
return;
V_341 -> V_348 = V_350 ;
V_341 -> V_6 = V_6 ;
F_127 ( V_6 , V_341 ) ;
}
static void
F_133 ( struct V_5 * V_6 )
{
struct V_340 * V_341 , * V_100 ;
if ( F_43 ( & V_6 -> V_344 ) ||
! V_6 -> V_342 || F_134 () )
return;
F_135 (fw_event, next, &ioc->fw_event_list, list) {
if ( F_136 ( & V_341 -> V_345 ) ) {
F_130 ( V_6 , V_341 ) ;
continue;
}
}
}
static void
F_137 ( struct V_5 * V_6 )
{
struct V_145 * V_146 ;
struct V_138 * V_139 ;
F_102 (sdev, ioc->shost) {
V_146 = V_139 -> V_150 ;
if ( ! V_146 )
continue;
if ( ! V_146 -> V_351 )
continue;
V_146 -> V_351 = 0 ;
F_23 ( V_6 , F_51 ( V_7 , V_139 , L_94
L_95 ,
V_146 -> V_152 -> V_27 ) ) ;
F_138 ( V_139 , V_352 ) ;
}
}
static void
F_139 ( struct V_5 * V_6 , T_1 V_9 )
{
struct V_145 * V_146 ;
struct V_138 * V_139 ;
F_102 (sdev, ioc->shost) {
V_146 = V_139 -> V_150 ;
if ( ! V_146 )
continue;
if ( ! V_146 -> V_351 )
continue;
if ( V_146 -> V_152 -> V_9 ==
V_9 ) {
F_23 ( V_6 , F_51 ( V_7 , V_139 ,
V_58 L_96
L_97 , V_6 -> V_35 ,
( unsigned long long ) V_9 ) ) ;
V_146 -> V_351 = 0 ;
F_138 ( V_139 , V_352 ) ;
}
}
}
static void
F_140 ( struct V_5 * V_6 )
{
struct V_145 * V_146 ;
struct V_138 * V_139 ;
F_102 (sdev, ioc->shost) {
V_146 = V_139 -> V_150 ;
if ( ! V_146 )
continue;
if ( V_146 -> V_351 )
continue;
V_146 -> V_351 = 1 ;
F_23 ( V_6 , F_51 ( V_7 , V_139 , L_98
L_95 ,
V_146 -> V_152 -> V_27 ) ) ;
F_141 ( V_139 ) ;
}
}
static void
F_142 ( struct V_5 * V_6 , T_4 V_27 )
{
struct V_145 * V_146 ;
struct V_138 * V_139 ;
F_102 (sdev, ioc->shost) {
V_146 = V_139 -> V_150 ;
if ( ! V_146 )
continue;
if ( V_146 -> V_351 )
continue;
if ( V_146 -> V_152 -> V_27 == V_27 ) {
F_23 ( V_6 , F_51 ( V_7 , V_139 ,
V_58 L_99
L_95 , V_6 -> V_35 , V_27 ) ) ;
V_146 -> V_351 = 1 ;
F_141 ( V_139 ) ;
}
}
}
static void
F_143 ( struct V_5 * V_6 ,
struct V_78 * V_79 )
{
struct V_353 * V_354 ;
struct V_45 * V_46 ;
struct V_78 * V_355 ;
unsigned long V_65 ;
if ( ! V_79 )
return;
F_4 (mpt2sas_port,
&sas_expander->sas_port_list, port_list) {
if ( V_354 -> V_356 . V_357 ==
V_358 ) {
F_18 ( & V_6 -> V_66 , V_65 ) ;
V_46 =
F_15 ( V_6 ,
V_354 -> V_356 . V_9 ) ;
if ( V_46 )
F_144 ( V_46 -> V_27 ,
V_6 -> V_359 ) ;
F_21 ( & V_6 -> V_66 , V_65 ) ;
}
}
F_4 (mpt2sas_port,
&sas_expander->sas_port_list, port_list) {
if ( V_354 -> V_356 . V_357 ==
V_360 ||
V_354 -> V_356 . V_357 ==
V_361 ) {
V_355 =
F_34 (
V_6 , V_354 -> V_356 . V_9 ) ;
F_143 ( V_6 ,
V_355 ) ;
}
}
}
static void
F_145 ( struct V_5 * V_6 ,
T_22 * V_362 )
{
int V_92 ;
T_4 V_27 ;
T_4 V_363 ;
T_6 V_364 ;
for ( V_92 = 0 ; V_92 < V_362 -> V_365 ; V_92 ++ ) {
V_27 = F_9 ( V_362 -> V_366 [ V_92 ] . V_367 ) ;
if ( ! V_27 )
continue;
V_364 = V_362 -> V_368 + V_92 ;
V_363 = V_362 -> V_366 [ V_92 ] . V_369 &
V_370 ;
if ( V_363 == V_371 )
F_142 ( V_6 , V_27 ) ;
}
}
static void
F_146 ( struct V_5 * V_6 , T_4 V_27 )
{
T_20 * V_103 ;
T_4 V_88 ;
struct V_45 * V_46 ;
struct V_147 * V_148 = NULL ;
T_1 V_9 = 0 ;
unsigned long V_65 ;
struct V_372 * V_373 ;
T_10 V_297 ;
if ( V_6 -> V_305 ) {
F_23 ( V_6 , F_3 ( V_58 L_100
L_101 , V_36 , V_6 -> V_35 , V_27 ) ) ;
return;
} else if ( V_6 -> V_306 ) {
F_23 ( V_6 , F_3 ( V_58 L_102
L_103 , V_36 , V_6 -> V_35 ,
V_27 ) ) ;
return;
}
V_297 = F_106 ( V_6 , 1 ) ;
if ( V_297 != V_374 ) {
F_23 ( V_6 , F_3 ( V_58 L_104
L_105 , V_36 , V_6 -> V_35 ,
V_27 ) ) ;
return;
}
if ( F_64 ( V_27 , V_6 -> V_166 ) )
return;
F_18 ( & V_6 -> V_66 , V_65 ) ;
V_46 = F_16 ( V_6 , V_27 ) ;
if ( V_46 && V_46 -> V_70 &&
V_46 -> V_70 -> V_150 ) {
V_148 = V_46 -> V_70 -> V_150 ;
V_148 -> V_375 = 1 ;
V_9 = V_46 -> V_9 ;
}
F_21 ( & V_6 -> V_66 , V_65 ) ;
if ( V_148 ) {
F_23 ( V_6 , F_3 ( V_58 L_106
L_107 , V_6 -> V_35 , V_27 ,
( unsigned long long ) V_9 ) ) ;
F_139 ( V_6 , V_9 ) ;
V_148 -> V_27 = V_161 ;
}
V_88 = F_110 ( V_6 , V_6 -> V_376 ) ;
if ( ! V_88 ) {
V_373 = F_62 ( sizeof( * V_373 ) , V_347 ) ;
if ( ! V_373 )
return;
F_147 ( & V_373 -> V_67 ) ;
V_373 -> V_27 = V_27 ;
F_24 ( & V_373 -> V_67 , & V_6 -> V_377 ) ;
F_23 ( V_6 , F_3 ( V_58
L_108 ,
V_6 -> V_35 , V_27 ) ) ;
return;
}
F_23 ( V_6 , F_3 ( V_58 L_109
L_110 , V_6 -> V_35 , V_27 , V_88 ,
V_6 -> V_376 ) ) ;
V_103 = F_48 ( V_6 , V_88 ) ;
memset ( V_103 , 0 , sizeof( T_20 ) ) ;
V_103 -> V_316 = V_317 ;
V_103 -> V_221 = F_112 ( V_27 ) ;
V_103 -> V_318 = V_328 ;
F_115 ( V_6 , V_88 ) ;
}
static T_6
F_148 ( struct V_5 * V_6 , T_4 V_88 ,
T_6 V_280 , T_10 V_281 )
{
T_23 * V_29 =
F_99 ( V_6 , V_281 ) ;
if ( F_149 ( V_29 ) ) {
F_23 ( V_6 , F_3 ( V_58
L_111
L_112 ,
V_6 -> V_35 , F_9 ( V_29 -> V_221 ) , V_88 ,
F_9 ( V_29 -> V_38 ) ,
F_69 ( V_29 -> V_324 ) ) ) ;
} else {
F_3 ( V_34 L_113 ,
V_6 -> V_35 , __FILE__ , __LINE__ , V_36 ) ;
}
return 1 ;
}
static void
F_150 ( struct V_5 * V_6 , T_4 V_27 )
{
T_20 * V_103 ;
T_4 V_88 ;
struct V_372 * V_373 ;
if ( V_6 -> V_304 || V_6 -> V_305 ||
V_6 -> V_306 ) {
F_23 ( V_6 , F_3 ( V_58 L_114
L_115 , V_36 , V_6 -> V_35 ) ) ;
return;
}
V_88 = F_110 ( V_6 , V_6 -> V_378 ) ;
if ( ! V_88 ) {
V_373 = F_62 ( sizeof( * V_373 ) , V_347 ) ;
if ( ! V_373 )
return;
F_147 ( & V_373 -> V_67 ) ;
V_373 -> V_27 = V_27 ;
F_24 ( & V_373 -> V_67 , & V_6 -> V_379 ) ;
F_23 ( V_6 , F_3 ( V_58
L_108 ,
V_6 -> V_35 , V_27 ) ) ;
return;
}
F_23 ( V_6 , F_3 ( V_58 L_109
L_110 , V_6 -> V_35 , V_27 , V_88 ,
V_6 -> V_378 ) ) ;
V_103 = F_48 ( V_6 , V_88 ) ;
memset ( V_103 , 0 , sizeof( T_20 ) ) ;
V_103 -> V_316 = V_317 ;
V_103 -> V_221 = F_112 ( V_27 ) ;
V_103 -> V_318 = V_328 ;
F_115 ( V_6 , V_88 ) ;
}
static T_6
F_151 ( struct V_5 * V_6 , T_4 V_88 ,
T_6 V_280 , T_10 V_281 )
{
T_4 V_27 ;
T_20 * V_380 ;
T_21 * V_29 =
F_99 ( V_6 , V_281 ) ;
if ( V_6 -> V_304 || V_6 -> V_305 ||
V_6 -> V_306 ) {
F_23 ( V_6 , F_3 ( V_58 L_114
L_115 , V_36 , V_6 -> V_35 ) ) ;
return 1 ;
}
if ( F_152 ( ! V_29 ) ) {
F_3 ( V_34 L_113 ,
V_6 -> V_35 , __FILE__ , __LINE__ , V_36 ) ;
return 1 ;
}
V_380 = F_48 ( V_6 , V_88 ) ;
V_27 = F_9 ( V_380 -> V_221 ) ;
if ( V_27 != F_9 ( V_29 -> V_221 ) ) {
F_23 ( V_6 , F_3 ( L_116
L_117 , V_27 ,
F_9 ( V_29 -> V_221 ) , V_88 ) ) ;
return 0 ;
}
F_23 ( V_6 , F_3 ( V_58
L_118
L_119 , V_6 -> V_35 ,
V_27 , V_88 , F_9 ( V_29 -> V_38 ) ,
F_69 ( V_29 -> V_324 ) ,
F_69 ( V_29 -> V_325 ) ) ) ;
return F_153 ( V_6 , V_88 ) ;
}
static T_6
F_154 ( struct V_5 * V_6 , T_4 V_88 , T_6 V_280 ,
T_10 V_281 )
{
T_4 V_27 ;
T_20 * V_380 ;
T_21 * V_29 =
F_99 ( V_6 , V_281 ) ;
T_24 * V_103 ;
T_4 V_381 ;
T_10 V_297 ;
if ( V_6 -> V_305 ) {
F_23 ( V_6 , F_3 ( V_58 L_100
L_120 , V_36 , V_6 -> V_35 ) ) ;
return 1 ;
} else if ( V_6 -> V_306 ) {
F_23 ( V_6 , F_3 ( V_58 L_102
L_121 , V_36 , V_6 -> V_35 ) ) ;
return 1 ;
}
V_297 = F_106 ( V_6 , 1 ) ;
if ( V_297 != V_374 ) {
F_23 ( V_6 , F_3 ( V_58 L_104
L_122 , V_36 , V_6 -> V_35 ) ) ;
return 1 ;
}
if ( F_152 ( ! V_29 ) ) {
F_3 ( V_34 L_113 ,
V_6 -> V_35 , __FILE__ , __LINE__ , V_36 ) ;
return 1 ;
}
V_380 = F_48 ( V_6 , V_88 ) ;
V_27 = F_9 ( V_380 -> V_221 ) ;
if ( V_27 != F_9 ( V_29 -> V_221 ) ) {
F_23 ( V_6 , F_3 ( V_58 L_116
L_117 , V_6 -> V_35 , V_27 ,
F_9 ( V_29 -> V_221 ) , V_88 ) ) ;
return 0 ;
}
F_23 ( V_6 , F_3 ( V_58
L_118
L_119 , V_6 -> V_35 ,
V_27 , V_88 , F_9 ( V_29 -> V_38 ) ,
F_69 ( V_29 -> V_324 ) ,
F_69 ( V_29 -> V_325 ) ) ) ;
V_381 = F_155 ( V_6 , V_6 -> V_382 ) ;
if ( ! V_381 ) {
F_3 ( V_34 L_68 ,
V_6 -> V_35 , V_36 ) ;
return 1 ;
}
F_23 ( V_6 , F_3 ( V_58 L_123
L_110 , V_6 -> V_35 , V_27 , V_381 ,
V_6 -> V_382 ) ) ;
V_103 = F_48 ( V_6 , V_381 ) ;
memset ( V_103 , 0 , sizeof( T_24 ) ) ;
V_103 -> V_316 = V_383 ;
V_103 -> V_384 = V_385 ;
V_103 -> V_221 = V_380 -> V_221 ;
F_156 ( V_6 , V_381 ) ;
return F_153 ( V_6 , V_88 ) ;
}
static T_6
F_153 ( struct V_5 * V_6 , T_4 V_88 )
{
struct V_372 * V_373 ;
if ( ! F_43 ( & V_6 -> V_379 ) ) {
V_373 = F_45 ( V_6 -> V_379 . V_100 ,
struct V_372 , V_67 ) ;
F_157 ( V_6 , V_88 ) ;
F_150 ( V_6 , V_373 -> V_27 ) ;
F_19 ( & V_373 -> V_67 ) ;
F_20 ( V_373 ) ;
return 0 ;
}
if ( ! F_43 ( & V_6 -> V_377 ) ) {
V_373 = F_45 ( V_6 -> V_377 . V_100 ,
struct V_372 , V_67 ) ;
F_157 ( V_6 , V_88 ) ;
F_146 ( V_6 , V_373 -> V_27 ) ;
F_19 ( & V_373 -> V_67 ) ;
F_20 ( V_373 ) ;
return 0 ;
}
return 1 ;
}
static void
F_158 ( struct V_5 * V_6 ,
T_22 * V_362 )
{
struct V_340 * V_341 ;
T_22 * V_386 ;
T_4 V_387 ;
struct V_78 * V_79 ;
unsigned long V_65 ;
int V_92 , V_363 ;
T_4 V_27 ;
for ( V_92 = 0 ; V_92 < V_362 -> V_365 ; V_92 ++ ) {
V_27 = F_9 ( V_362 -> V_366 [ V_92 ] . V_367 ) ;
if ( ! V_27 )
continue;
V_363 = V_362 -> V_366 [ V_92 ] . V_369 &
V_370 ;
if ( V_363 == V_388 )
F_146 ( V_6 , V_27 ) ;
}
V_387 = F_9 ( V_362 -> V_389 ) ;
if ( V_387 < V_6 -> V_31 . V_32 ) {
F_145 ( V_6 , V_362 ) ;
return;
}
if ( V_362 -> V_390 ==
V_391 ) {
F_18 ( & V_6 -> V_80 , V_65 ) ;
V_79 = F_33 ( V_6 ,
V_387 ) ;
F_143 ( V_6 , V_79 ) ;
F_21 ( & V_6 -> V_80 , V_65 ) ;
do {
V_27 = F_86 ( V_6 -> V_359 ,
V_6 -> V_245 . V_392 ) ;
if ( V_27 < V_6 -> V_245 . V_392 )
F_142 ( V_6 , V_27 ) ;
} while ( F_159 ( V_27 , V_6 -> V_359 ) );
} else if ( V_362 -> V_390 == V_393 )
F_145 ( V_6 , V_362 ) ;
if ( V_362 -> V_390 != V_394 )
return;
F_18 ( & V_6 -> V_343 , V_65 ) ;
F_4 (fw_event, &ioc->fw_event_list, list) {
if ( V_341 -> V_348 != V_395 ||
V_341 -> V_396 )
continue;
V_386 = ( T_22 * )
V_341 -> V_362 ;
if ( V_386 -> V_390 ==
V_397 ||
V_386 -> V_390 ==
V_393 ) {
if ( F_9 ( V_386 -> V_389 ) ==
V_387 ) {
F_23 ( V_6 , F_3 ( V_58
L_124 , V_6 -> V_35 ) ) ;
V_341 -> V_396 = 1 ;
}
}
}
F_21 ( & V_6 -> V_343 , V_65 ) ;
}
static void
F_160 ( struct V_5 * V_6 , T_4 V_27 )
{
struct V_47 * V_48 ;
struct V_147 * V_148 ;
unsigned long V_65 ;
F_18 ( & V_6 -> V_76 , V_65 ) ;
V_48 = F_29 ( V_6 , V_27 ) ;
if ( V_48 && V_48 -> V_70 &&
V_48 -> V_70 -> V_150 ) {
V_148 =
V_48 -> V_70 -> V_150 ;
V_148 -> V_375 = 1 ;
F_23 ( V_6 , F_3 ( V_58
L_125
L_126 , V_6 -> V_35 , V_27 ,
( unsigned long long ) V_48 -> V_52 ) ) ;
}
F_21 ( & V_6 -> V_76 , V_65 ) ;
}
static void
F_161 ( T_4 V_27 , T_4 * V_398 , T_4 * V_399 )
{
if ( ! V_27 || V_27 == * V_398 || V_27 == * V_399 )
return;
if ( ! * V_398 )
* V_398 = V_27 ;
else if ( ! * V_399 )
* V_399 = V_27 ;
}
static void
F_162 ( struct V_5 * V_6 ,
T_25 * V_362 )
{
T_26 * V_400 ;
int V_92 ;
T_4 V_27 , V_251 , V_398 , V_399 ;
struct V_372 * V_373 ;
V_398 = 0 ;
V_399 = 0 ;
if ( V_6 -> V_163 )
return;
V_400 = ( T_26 * ) & V_362 -> V_401 [ 0 ] ;
for ( V_92 = 0 ; V_92 < V_362 -> V_402 ; V_92 ++ , V_400 ++ ) {
if ( V_400 -> V_403 ==
V_404 ||
V_400 -> V_403 ==
V_405 ) {
V_251 = F_9 ( V_400 -> V_406 ) ;
F_160 ( V_6 , V_251 ) ;
F_161 ( V_251 , & V_398 , & V_399 ) ;
}
}
V_400 = ( T_26 * ) & V_362 -> V_401 [ 0 ] ;
for ( V_92 = 0 ; V_92 < V_362 -> V_402 ; V_92 ++ , V_400 ++ ) {
if ( F_69 ( V_362 -> V_171 ) &
V_407 )
continue;
if ( V_400 -> V_403 == V_408 ) {
V_251 = F_9 ( V_400 -> V_406 ) ;
F_161 ( V_251 , & V_398 , & V_399 ) ;
}
}
if ( V_398 )
F_150 ( V_6 , V_398 ) ;
if ( V_399 )
F_150 ( V_6 , V_399 ) ;
V_400 = ( T_26 * ) & V_362 -> V_401 [ 0 ] ;
for ( V_92 = 0 ; V_92 < V_362 -> V_402 ; V_92 ++ , V_400 ++ ) {
if ( V_400 -> V_403 != V_408 )
continue;
V_27 = F_9 ( V_400 -> V_409 ) ;
V_251 = F_9 ( V_400 -> V_406 ) ;
F_163 ( V_27 , V_6 -> V_166 ) ;
if ( ! V_251 )
F_146 ( V_6 , V_27 ) ;
else if ( V_251 == V_398 || V_251 == V_399 ) {
V_373 = F_62 ( sizeof( * V_373 ) , V_347 ) ;
F_164 ( ! V_373 ) ;
F_147 ( & V_373 -> V_67 ) ;
V_373 -> V_27 = V_27 ;
F_24 ( & V_373 -> V_67 , & V_6 -> V_377 ) ;
F_23 ( V_6 , F_3 ( V_58
L_108 , V_6 -> V_35 ,
V_27 ) ) ;
} else
F_146 ( V_6 , V_27 ) ;
}
}
static void
F_165 ( struct V_5 * V_6 ,
T_27 * V_362 )
{
T_10 V_188 ;
if ( V_362 -> V_403 != V_410 )
return;
V_188 = F_69 ( V_362 -> V_411 ) ;
if ( V_188 == V_198 || V_188 ==
V_197 )
F_160 ( V_6 ,
F_9 ( V_362 -> V_406 ) ) ;
}
static void
F_166 ( struct V_5 * V_6 )
{
struct V_87 * V_90 ;
T_4 V_88 ;
T_4 V_226 = 0 ;
for ( V_88 = 1 ; V_88 <= V_6 -> V_93 ; V_88 ++ ) {
V_90 = F_38 ( V_6 , V_88 ) ;
if ( ! V_90 )
continue;
V_226 ++ ;
F_157 ( V_6 , V_88 ) ;
F_167 ( V_90 ) ;
if ( V_6 -> V_306 )
V_90 -> V_335 = V_336 << 16 ;
else
V_90 -> V_335 = V_338 << 16 ;
V_90 -> V_337 ( V_90 ) ;
}
F_111 ( V_6 , F_3 ( V_58 L_127 ,
V_6 -> V_35 , V_226 ) ) ;
}
static void
F_168 ( struct V_87 * V_90 , T_11 * V_103 )
{
T_4 V_412 ;
unsigned char V_413 = F_169 ( V_90 ) ;
unsigned char V_414 = F_170 ( V_90 ) ;
if ( V_414 == V_415 || V_413 == V_416 )
return;
if ( V_413 == V_417 )
V_412 = V_418 ;
else if ( V_413 == V_419 )
V_412 = V_420 ;
else
return;
switch ( V_414 ) {
case V_421 :
case V_422 :
V_412 |= V_423 |
V_424 |
V_425 ;
V_103 -> V_426 . V_427 . V_428 =
F_171 ( F_172 ( V_90 ) ) ;
break;
case V_429 :
V_412 |= V_425 ;
break;
}
V_103 -> V_430 = F_173 ( V_90 -> V_43 -> V_431 ) ;
V_103 -> V_432 = F_112 ( V_412 ) ;
}
static void
F_174 ( struct V_87 * V_90 , T_4 V_30 )
{
T_6 V_433 ;
switch ( V_30 ) {
case V_434 :
V_433 = 0x01 ;
break;
case V_435 :
V_433 = 0x02 ;
break;
case V_436 :
V_433 = 0x03 ;
break;
default:
V_433 = 0x00 ;
break;
}
F_175 ( 0 , V_90 -> V_437 , V_438 , 0x10 , V_433 ) ;
V_90 -> V_335 = V_439 << 24 | ( V_440 << 16 ) |
V_441 ;
}
static inline T_6
F_176 ( struct V_5 * V_6 , T_4 V_88 )
{
return V_6 -> V_89 [ V_88 - 1 ] . V_442 ;
}
static inline void
F_177 ( struct V_5 * V_6 , T_4 V_88 , T_6 V_442 )
{
V_6 -> V_89 [ V_88 - 1 ] . V_442 = V_442 ;
}
static void
F_178 ( struct V_5 * V_6 , struct V_87 * V_90 ,
struct V_47 * V_48 , T_11 * V_103 ,
T_4 V_88 )
{
T_16 V_443 , V_444 , V_445 , V_446 , V_447 ;
T_10 V_227 , V_229 ;
T_6 V_215 , V_448 = V_90 -> V_449 [ 0 ] ;
if ( V_448 != V_450 && V_448 != V_451 &&
V_448 != V_452 && V_448 != V_453 )
return;
if ( V_448 == V_450 || V_448 == V_451 )
V_443 = F_179 ( & V_103 -> V_426 . V_454 [ 2 ] ) ;
else
V_443 = F_180 ( & V_103 -> V_426 . V_454 [ 2 ] ) ;
V_447 = F_52 ( V_90 ) >> V_48 -> V_241 ;
if ( V_443 + V_447 - 1 > V_48 -> V_242 )
return;
V_227 = V_48 -> V_227 ;
V_229 = V_48 -> V_240 ;
V_445 = V_443 & ( V_227 - 1 ) ;
if ( V_445 + V_447 > V_227 )
return;
V_215 = V_48 -> V_215 ;
V_444 = V_443 >> V_229 ;
V_446 = F_95 ( V_444 , V_215 ) ;
V_444 = ( V_444 << V_229 ) + V_445 ;
V_103 -> V_221 = F_112 ( V_48 -> V_237 [ V_446 ] ) ;
if ( V_448 == V_450 || V_448 == V_451 )
F_181 ( F_182 ( V_444 ) ,
& V_103 -> V_426 . V_454 [ 2 ] ) ;
else
F_183 ( V_444 , & V_103 -> V_426 . V_454 [ 2 ] ) ;
F_177 ( V_6 , V_88 , 1 ) ;
}
static int
F_184 ( struct V_141 * V_142 , struct V_87 * V_90 )
{
struct V_5 * V_6 = F_58 ( V_142 ) ;
struct V_145 * V_146 ;
struct V_147 * V_148 ;
struct V_47 * V_48 ;
T_11 * V_103 ;
T_10 V_455 ;
T_4 V_88 ;
V_146 = V_90 -> V_43 -> V_150 ;
if ( ! V_146 || ! V_146 -> V_152 ) {
V_90 -> V_335 = V_336 << 16 ;
V_90 -> V_337 ( V_90 ) ;
return 0 ;
}
if ( V_6 -> V_306 || V_6 -> V_305 ) {
V_90 -> V_335 = V_336 << 16 ;
V_90 -> V_337 ( V_90 ) ;
return 0 ;
}
V_148 = V_146 -> V_152 ;
if ( V_148 -> V_27 == V_161 ) {
V_90 -> V_335 = V_336 << 16 ;
V_90 -> V_337 ( V_90 ) ;
return 0 ;
}
if ( V_6 -> V_304 || V_6 -> V_456 )
return V_457 ;
else if ( V_146 -> V_351 || V_148 -> V_291 )
return V_458 ;
else if ( V_148 -> V_375 ) {
V_90 -> V_335 = V_336 << 16 ;
V_90 -> V_337 ( V_90 ) ;
return 0 ;
}
if ( V_90 -> V_118 == V_459 )
V_455 = V_460 ;
else if ( V_90 -> V_118 == V_119 )
V_455 = V_461 ;
else
V_455 = V_462 ;
V_455 |= V_463 ;
if ( ! V_6 -> V_163 && ! F_70 ( & V_90 -> V_43 -> V_212 ) &&
F_89 ( V_90 -> V_43 ) && V_90 -> V_464 != 32 )
V_455 |= V_465 ;
V_88 = F_185 ( V_6 , V_6 -> V_466 , V_90 ) ;
if ( ! V_88 ) {
F_3 ( V_34 L_68 ,
V_6 -> V_35 , V_36 ) ;
goto V_75;
}
V_103 = F_48 ( V_6 , V_88 ) ;
memset ( V_103 , 0 , sizeof( T_11 ) ) ;
F_168 ( V_90 , V_103 ) ;
if ( V_90 -> V_464 == 32 )
V_455 |= 4 << V_467 ;
V_103 -> V_316 = V_468 ;
if ( V_146 -> V_152 -> V_65 &
V_167 )
V_103 -> V_316 = V_469 ;
else
V_103 -> V_316 = V_468 ;
V_103 -> V_221 =
F_112 ( V_146 -> V_152 -> V_27 ) ;
V_103 -> V_470 = F_173 ( F_52 ( V_90 ) ) ;
V_103 -> V_471 = F_173 ( V_455 ) ;
V_103 -> V_472 = F_112 ( V_90 -> V_464 ) ;
V_103 -> V_473 = V_474 ;
V_103 -> V_475 = V_476 ;
V_103 -> V_477 =
F_186 ( V_6 , V_88 ) ;
V_103 -> V_478 = F_53 ( T_11 , V_127 ) / 4 ;
V_103 -> V_479 = F_112 ( V_480 +
V_481 ) ;
V_103 -> V_482 = 0 ;
V_103 -> V_483 = 0 ;
F_113 ( V_146 -> V_95 , (struct V_320 * )
V_103 -> V_321 ) ;
memcpy ( V_103 -> V_426 . V_454 , V_90 -> V_449 , V_90 -> V_464 ) ;
if ( ! V_103 -> V_470 ) {
F_187 ( V_6 , & V_103 -> V_127 ) ;
} else {
if ( F_47 ( V_6 , V_90 , V_88 ) ) {
F_157 ( V_6 , V_88 ) ;
goto V_75;
}
}
V_48 = V_148 -> V_48 ;
if ( V_48 && V_48 -> V_224 )
F_178 ( V_6 , V_90 , V_48 , V_103 ,
V_88 ) ;
if ( F_149 ( V_103 -> V_316 == V_468 ) )
F_188 ( V_6 , V_88 ,
F_9 ( V_103 -> V_221 ) ) ;
else
F_156 ( V_6 , V_88 ) ;
return 0 ;
V_75:
return V_457 ;
}
static void
F_189 ( char * V_437 , struct V_484 * V_485 )
{
if ( ( V_437 [ 0 ] & 0x7F ) >= 0x72 ) {
V_485 -> V_486 = V_437 [ 1 ] & 0x0F ;
V_485 -> V_487 = V_437 [ 2 ] ;
V_485 -> V_433 = V_437 [ 3 ] ;
} else {
V_485 -> V_486 = V_437 [ 2 ] & 0x0F ;
V_485 -> V_487 = V_437 [ 12 ] ;
V_485 -> V_433 = V_437 [ 13 ] ;
}
}
static void
F_190 ( struct V_5 * V_6 , struct V_87 * V_90 ,
T_28 * V_29 , T_4 V_88 )
{
T_10 V_488 ;
T_6 * V_489 ;
T_4 V_30 = F_9 ( V_29 -> V_38 ) &
V_39 ;
T_6 V_490 = V_29 -> V_491 ;
T_6 V_492 = V_29 -> V_493 ;
char * V_494 = NULL ;
char * V_495 = NULL ;
char * V_496 = V_6 -> V_497 ;
T_10 V_498 = F_69 ( V_29 -> V_324 ) ;
struct V_45 * V_46 = NULL ;
unsigned long V_65 ;
struct V_156 * V_70 = V_90 -> V_43 -> V_332 ;
struct V_147 * V_333 = V_70 -> V_150 ;
char * V_334 = NULL ;
if ( ! V_333 )
return;
if ( V_6 -> V_261 )
V_334 = L_74 ;
else
V_334 = L_75 ;
if ( V_498 == 0x31170000 )
return;
switch ( V_30 ) {
case V_40 :
V_494 = L_128 ;
break;
case V_499 :
V_494 = L_129 ;
break;
case V_500 :
V_494 = L_130 ;
break;
case V_501 :
V_494 = L_131 ;
break;
case V_502 :
V_494 = L_132 ;
break;
case V_503 :
V_494 = L_133 ;
break;
case V_504 :
V_494 = L_134 ;
break;
case V_505 :
V_494 = L_135 ;
break;
case V_506 :
V_494 = L_136 ;
break;
case V_507 :
V_494 = L_137 ;
break;
case V_508 :
V_494 = L_138 ;
break;
case V_509 :
V_494 = L_139 ;
break;
case V_510 :
V_494 = L_140 ;
break;
case V_511 :
V_494 = L_141 ;
break;
case V_434 :
V_494 = L_142 ;
break;
case V_436 :
V_494 = L_143 ;
break;
case V_435 :
V_494 = L_144 ;
break;
default:
V_494 = L_62 ;
break;
}
switch ( V_492 ) {
case V_512 :
V_495 = L_145 ;
break;
case V_513 :
V_495 = L_146 ;
break;
case V_514 :
V_495 = L_147 ;
break;
case V_515 :
V_495 = L_148 ;
break;
case V_516 :
V_495 = L_149 ;
break;
case V_517 :
V_495 = L_150 ;
break;
case V_518 :
V_495 = L_151 ;
break;
case V_519 :
V_495 = L_152 ;
break;
case V_520 :
V_495 = L_153 ;
break;
case V_521 :
V_495 = L_154 ;
break;
case V_522 :
V_495 = L_155 ;
break;
default:
V_495 = L_62 ;
break;
}
V_496 [ 0 ] = '\0' ;
if ( ! V_490 )
V_496 = L_156 ;
if ( V_490 & V_523 )
strcat ( V_496 , L_157 ) ;
if ( V_490 & V_524 )
strcat ( V_496 , L_158 ) ;
if ( V_490 & V_525 )
strcat ( V_496 , L_159 ) ;
if ( V_490 & V_526 )
strcat ( V_496 , L_160 ) ;
if ( V_490 & V_527 )
strcat ( V_496 , L_161 ) ;
F_120 ( V_90 ) ;
if ( V_333 -> V_65 & V_153 ) {
F_3 ( V_99 L_162 , V_6 -> V_35 ,
V_334 , ( unsigned long long ) V_333 -> V_9 ) ;
} else {
F_18 ( & V_6 -> V_66 , V_65 ) ;
V_46 = F_15 ( V_6 ,
V_333 -> V_9 ) ;
if ( V_46 ) {
F_3 ( V_99 L_163
L_164 , V_6 -> V_35 , V_46 -> V_9 ,
V_46 -> V_262 ) ;
F_3 ( V_99
L_165 ,
V_6 -> V_35 , V_46 -> V_14 ,
V_46 -> V_18 ) ;
}
F_21 ( & V_6 -> V_66 , V_65 ) ;
}
F_3 ( V_99 L_166
L_167 , V_6 -> V_35 , F_9 ( V_29 -> V_221 ) ,
V_494 , V_30 , V_88 ) ;
F_3 ( V_99 L_168
L_169 , V_6 -> V_35 , F_52 ( V_90 ) , V_90 -> V_528 ,
F_191 ( V_90 ) ) ;
F_3 ( V_99 L_170
L_171 , V_6 -> V_35 , F_9 ( V_29 -> V_529 ) ,
F_69 ( V_29 -> V_530 ) , V_90 -> V_335 ) ;
F_3 ( V_99 L_172
L_173 , V_6 -> V_35 , V_495 ,
V_492 , V_496 , V_490 ) ;
if ( V_490 & V_527 ) {
struct V_484 V_485 ;
F_189 ( V_90 -> V_437 , & V_485 ) ;
F_3 ( V_99 L_174
L_175 , V_6 -> V_35 , V_485 . V_486 ,
V_485 . V_487 , V_485 . V_433 , F_69 ( V_29 -> V_531 ) ) ;
}
if ( V_490 & V_523 ) {
V_488 = F_69 ( V_29 -> V_532 ) ;
V_489 = ( T_6 * ) & V_488 ;
F_96 ( V_6 , V_489 [ 0 ] ) ;
}
}
static void
F_192 ( struct V_5 * V_6 , T_4 V_27 )
{
T_29 V_29 ;
T_30 V_103 ;
struct V_45 * V_46 ;
V_46 = F_16 ( V_6 , V_27 ) ;
if ( ! V_46 )
return;
memset ( & V_103 , 0 , sizeof( T_30 ) ) ;
V_103 . V_316 = V_533 ;
V_103 . V_534 = V_535 ;
V_103 . V_536 =
F_173 ( V_537 ) ;
V_103 . V_221 = F_112 ( V_27 ) ;
V_103 . V_171 = V_538 ;
if ( ( F_193 ( V_6 , & V_29 ,
& V_103 ) ) != 0 ) {
F_3 ( V_34 L_2 , V_6 -> V_35 ,
__FILE__ , __LINE__ , V_36 ) ;
return;
}
V_46 -> V_539 = 1 ;
if ( V_29 . V_38 || V_29 . V_324 ) {
F_23 ( V_6 , F_3 ( V_58
L_176 ,
V_6 -> V_35 , F_9 ( V_29 . V_38 ) ,
F_69 ( V_29 . V_324 ) ) ) ;
return;
}
}
static void
F_194 ( struct V_5 * V_6 ,
struct V_45 * V_46 )
{
T_29 V_29 ;
T_30 V_103 ;
memset ( & V_103 , 0 , sizeof( T_30 ) ) ;
V_103 . V_316 = V_533 ;
V_103 . V_534 = V_535 ;
V_103 . V_536 = 0 ;
V_103 . V_540 = F_112 ( V_46 -> V_18 ) ;
V_103 . V_221 = 0 ;
V_103 . V_541 = F_112 ( V_46 -> V_542 ) ;
V_103 . V_171 = V_543 ;
if ( ( F_193 ( V_6 , & V_29 ,
& V_103 ) ) != 0 ) {
F_3 ( V_34 L_2 , V_6 -> V_35 ,
__FILE__ , __LINE__ , V_36 ) ;
return;
}
if ( V_29 . V_38 || V_29 . V_324 ) {
F_23 ( V_6 , F_3 ( V_58 L_177
L_178 , V_6 -> V_35 ,
F_9 ( V_29 . V_38 ) ,
F_69 ( V_29 . V_324 ) ) ) ;
return;
}
}
static void
F_195 ( struct V_5 * V_6 , T_4 V_27 )
{
struct V_340 * V_341 ;
V_341 = F_62 ( sizeof( struct V_340 ) , V_347 ) ;
if ( ! V_341 )
return;
V_341 -> V_348 = V_544 ;
V_341 -> V_545 = V_27 ;
V_341 -> V_6 = V_6 ;
F_127 ( V_6 , V_341 ) ;
}
static void
F_196 ( struct V_5 * V_6 , T_4 V_27 )
{
struct V_156 * V_70 ;
struct V_147 * V_148 ;
T_31 * V_546 ;
T_32 * V_362 ;
struct V_45 * V_46 ;
T_33 V_214 ;
unsigned long V_65 ;
F_18 ( & V_6 -> V_66 , V_65 ) ;
V_46 = F_16 ( V_6 , V_27 ) ;
if ( ! V_46 ) {
F_21 ( & V_6 -> V_66 , V_65 ) ;
return;
}
V_70 = V_46 -> V_70 ;
V_148 = V_70 -> V_150 ;
if ( ( V_148 -> V_65 & V_167 ) ||
( ( V_148 -> V_65 & V_153 ) ) ) {
F_21 ( & V_6 -> V_66 , V_65 ) ;
return;
}
F_121 ( V_547 , V_70 , L_179 ) ;
F_21 ( & V_6 -> V_66 , V_65 ) ;
if ( V_6 -> V_548 -> V_549 == V_550 )
F_195 ( V_6 , V_27 ) ;
V_214 = F_53 ( T_31 , V_551 ) +
sizeof( T_32 ) ;
V_546 = F_62 ( V_214 , V_347 ) ;
if ( ! V_546 ) {
F_3 ( V_34 L_2 ,
V_6 -> V_35 , __FILE__ , __LINE__ , V_36 ) ;
return;
}
V_546 -> V_316 = V_552 ;
V_546 -> V_553 =
F_112 ( V_554 ) ;
V_546 -> V_286 = V_214 / 4 ;
V_546 -> V_555 =
F_112 ( sizeof( T_32 ) / 4 ) ;
V_362 = ( T_32 * )
V_546 -> V_551 ;
V_362 -> V_403 = V_556 ;
V_362 -> V_557 = 0x5D ;
V_362 -> V_221 = F_112 ( V_27 ) ;
V_362 -> V_11 = F_197 ( V_148 -> V_9 ) ;
F_198 ( V_6 , V_546 ) ;
F_20 ( V_546 ) ;
}
static T_6
F_199 ( struct V_5 * V_6 , T_4 V_88 , T_6 V_280 , T_10 V_281 )
{
T_11 * V_103 ;
T_28 * V_29 ;
struct V_87 * V_90 ;
T_4 V_30 ;
T_10 V_558 ;
T_6 V_490 ;
T_6 V_492 ;
T_10 V_498 ;
struct V_145 * V_146 ;
T_10 V_271 = 0 ;
unsigned long V_65 ;
V_29 = F_99 ( V_6 , V_281 ) ;
V_90 = F_38 ( V_6 , V_88 ) ;
if ( V_90 == NULL )
return 1 ;
V_103 = F_48 ( V_6 , V_88 ) ;
if ( V_29 == NULL ) {
V_90 -> V_335 = V_559 << 16 ;
goto V_75;
}
V_146 = V_90 -> V_43 -> V_150 ;
if ( ! V_146 || ! V_146 -> V_152 ||
V_146 -> V_152 -> V_375 ) {
V_90 -> V_335 = V_336 << 16 ;
goto V_75;
}
V_30 = F_9 ( V_29 -> V_38 ) ;
if ( F_176 ( V_6 , V_88 ) &&
( ( V_30 & V_39 )
!= V_507 ) ) {
F_18 ( & V_6 -> V_91 , V_65 ) ;
V_6 -> V_89 [ V_88 - 1 ] . V_90 = V_90 ;
F_177 ( V_6 , V_88 , 0 ) ;
F_21 ( & V_6 -> V_91 , V_65 ) ;
memcpy ( V_103 -> V_426 . V_454 , V_90 -> V_449 , V_90 -> V_464 ) ;
V_103 -> V_221 =
F_112 ( V_146 -> V_152 -> V_27 ) ;
F_188 ( V_6 , V_88 ,
V_146 -> V_152 -> V_27 ) ;
return 0 ;
}
V_490 = V_29 -> V_491 ;
if ( V_490 & V_523 )
V_271 =
F_69 ( V_29 -> V_532 ) & 0xFF ;
if ( ! V_146 -> V_560 ) {
V_146 -> V_560 ++ ;
if ( ! V_6 -> V_163 && ! F_70 ( & V_90 -> V_43 -> V_212 ) &&
F_89 ( V_90 -> V_43 ) &&
V_271 == V_274 ) {
F_200 ( V_90 -> V_43 ) ;
F_51 ( V_7 , V_90 -> V_43 , L_180 ) ;
}
}
V_558 = F_69 ( V_29 -> V_530 ) ;
F_201 ( V_90 , F_52 ( V_90 ) - V_558 ) ;
if ( V_30 & V_561 )
V_498 = F_69 ( V_29 -> V_324 ) ;
else
V_498 = 0 ;
V_30 &= V_39 ;
V_492 = V_29 -> V_493 ;
if ( V_30 == V_504 && V_558 == 0 &&
( V_492 == V_515 ||
V_492 == V_518 ||
V_492 == V_520 ) ) {
V_30 = V_40 ;
}
if ( V_490 & V_527 ) {
struct V_484 V_485 ;
const void * V_562 = F_202 ( V_6 ,
V_88 ) ;
T_10 V_214 = F_203 ( T_10 , V_476 ,
F_69 ( V_29 -> V_531 ) ) ;
memcpy ( V_90 -> V_437 , V_562 , V_214 ) ;
F_189 ( V_90 -> V_437 , & V_485 ) ;
if ( V_485 . V_487 == 0x5D )
F_196 ( V_6 ,
F_9 ( V_29 -> V_221 ) ) ;
}
switch ( V_30 ) {
case V_563 :
case V_564 :
V_90 -> V_335 = V_565 ;
break;
case V_502 :
V_90 -> V_335 = V_336 << 16 ;
break;
case V_510 :
if ( V_146 -> V_351 ) {
V_90 -> V_335 = V_566 << 16 ;
goto V_75;
}
V_90 -> V_335 = V_567 << 16 ;
break;
case V_507 :
case V_511 :
V_90 -> V_335 = V_338 << 16 ;
break;
case V_508 :
if ( ( V_558 == 0 ) || ( V_90 -> V_528 > V_558 ) )
V_90 -> V_335 = V_567 << 16 ;
else
V_90 -> V_335 = ( V_559 << 16 ) | V_492 ;
break;
case V_504 :
V_90 -> V_335 = ( V_559 << 16 ) | V_492 ;
if ( ( V_490 & V_527 ) )
break;
if ( V_558 < V_90 -> V_528 ) {
if ( V_492 == V_565 )
V_90 -> V_335 = V_565 ;
else
V_90 -> V_335 = V_567 << 16 ;
} else if ( V_490 & ( V_526 |
V_525 ) )
V_90 -> V_335 = V_567 << 16 ;
else if ( V_490 & V_524 )
V_90 -> V_335 = V_338 << 16 ;
else if ( ! V_558 && V_90 -> V_449 [ 0 ] == V_568 ) {
V_29 -> V_491 = V_527 ;
V_29 -> V_493 = V_441 ;
V_90 -> V_335 = ( V_439 << 24 ) |
V_441 ;
V_90 -> V_437 [ 0 ] = 0x70 ;
V_90 -> V_437 [ 2 ] = V_438 ;
V_90 -> V_437 [ 12 ] = 0x20 ;
V_90 -> V_437 [ 13 ] = 0 ;
}
break;
case V_503 :
F_201 ( V_90 , 0 ) ;
case V_500 :
case V_40 :
V_90 -> V_335 = ( V_559 << 16 ) | V_492 ;
if ( V_271 ==
V_274 ||
( V_490 & ( V_526 |
V_525 ) ) )
V_90 -> V_335 = V_567 << 16 ;
else if ( V_490 & V_524 )
V_90 -> V_335 = V_338 << 16 ;
break;
case V_434 :
case V_436 :
case V_435 :
F_174 ( V_90 , V_30 ) ;
break;
case V_506 :
case V_499 :
case V_569 :
case V_570 :
case V_571 :
case V_572 :
case V_505 :
case V_509 :
default:
V_90 -> V_335 = V_567 << 16 ;
break;
}
#ifdef F_204
if ( V_90 -> V_335 && ( V_6 -> V_8 & V_573 ) )
F_190 ( V_6 , V_90 , V_29 , V_88 ) ;
#endif
V_75:
F_167 ( V_90 ) ;
V_90 -> V_337 ( V_90 ) ;
return 1 ;
}
static void
F_205 ( struct V_5 * V_6 )
{
T_4 V_214 ;
T_4 V_30 ;
int V_92 ;
T_9 V_29 ;
T_34 * V_574 = NULL ;
T_4 V_575 ;
T_6 V_576 ;
F_111 ( V_6 , F_3 ( V_58
L_181 ,
V_6 -> V_35 , ( unsigned long long ) V_6 -> V_31 . V_9 ) ) ;
V_214 = F_53 ( T_34 , V_577 ) + ( V_6 -> V_31 . V_32
* sizeof( V_578 ) ) ;
V_574 = F_62 ( V_214 , V_160 ) ;
if ( ! V_574 ) {
F_3 ( V_34 L_2 ,
V_6 -> V_35 , __FILE__ , __LINE__ , V_36 ) ;
return;
}
if ( ( F_206 ( V_6 , & V_29 ,
V_574 , V_214 ) ) != 0 )
goto V_75;
V_30 = F_9 ( V_29 . V_38 ) & V_39 ;
if ( V_30 != V_40 )
goto V_75;
for ( V_92 = 0 ; V_92 < V_6 -> V_31 . V_32 ; V_92 ++ ) {
V_576 = V_574 -> V_577 [ V_92 ] . V_579 >> 4 ;
if ( V_92 == 0 )
V_6 -> V_31 . V_27 = F_9 ( V_574 ->
V_577 [ 0 ] . V_580 ) ;
V_6 -> V_31 . V_262 [ V_92 ] . V_27 = V_6 -> V_31 . V_27 ;
V_575 = F_9 ( V_574 -> V_577 [ V_92 ] .
V_367 ) ;
if ( V_575 && V_576 < V_581 )
V_576 = V_581 ;
F_207 ( V_6 , V_6 -> V_31 . V_9 ,
V_575 , V_92 , V_576 ) ;
}
V_75:
F_20 ( V_574 ) ;
}
static void
F_208 ( struct V_5 * V_6 )
{
int V_92 ;
T_9 V_29 ;
T_34 * V_574 = NULL ;
T_35 * V_582 = NULL ;
T_36 V_583 ;
T_8 V_28 ;
T_37 V_584 ;
T_4 V_30 ;
T_4 V_214 ;
T_4 V_585 ;
F_209 ( V_6 , & V_6 -> V_31 . V_32 ) ;
if ( ! V_6 -> V_31 . V_32 ) {
F_3 ( V_34 L_2 ,
V_6 -> V_35 , __FILE__ , __LINE__ , V_36 ) ;
return;
}
V_214 = F_53 ( T_34 , V_577 ) + ( V_6 -> V_31 . V_32 *
sizeof( V_578 ) ) ;
V_574 = F_62 ( V_214 , V_160 ) ;
if ( ! V_574 ) {
F_3 ( V_34 L_2 ,
V_6 -> V_35 , __FILE__ , __LINE__ , V_36 ) ;
return;
}
if ( ( F_206 ( V_6 , & V_29 ,
V_574 , V_214 ) ) ) {
F_3 ( V_34 L_2 ,
V_6 -> V_35 , __FILE__ , __LINE__ , V_36 ) ;
goto V_75;
}
V_30 = F_9 ( V_29 . V_38 ) &
V_39 ;
if ( V_30 != V_40 ) {
F_3 ( V_34 L_2 ,
V_6 -> V_35 , __FILE__ , __LINE__ , V_36 ) ;
goto V_75;
}
V_214 = F_53 ( T_35 , V_577 ) + ( V_6 -> V_31 . V_32 *
sizeof( V_586 ) ) ;
V_582 = F_62 ( V_214 , V_160 ) ;
if ( ! V_582 ) {
F_3 ( V_34 L_2 ,
V_6 -> V_35 , __FILE__ , __LINE__ , V_36 ) ;
goto V_75;
}
if ( ( F_210 ( V_6 , & V_29 ,
V_582 , V_214 ) ) ) {
F_3 ( V_34 L_2 ,
V_6 -> V_35 , __FILE__ , __LINE__ , V_36 ) ;
goto V_75;
}
V_30 = F_9 ( V_29 . V_38 ) &
V_39 ;
if ( V_30 != V_40 ) {
F_3 ( V_34 L_2 ,
V_6 -> V_35 , __FILE__ , __LINE__ , V_36 ) ;
goto V_75;
}
V_6 -> V_587 =
F_9 ( V_582 -> V_588 ) ;
V_585 =
F_9 ( V_582 -> V_589 ) ;
if ( V_585 & V_590 )
V_6 -> V_585 = ( V_585 &
V_591 ) * 16 ;
else
V_6 -> V_585 = V_585 &
V_591 ;
V_6 -> V_31 . V_592 = & V_6 -> V_142 -> V_593 ;
V_6 -> V_31 . V_262 = F_211 ( V_6 -> V_31 . V_32 ,
sizeof( struct V_594 ) , V_160 ) ;
if ( ! V_6 -> V_31 . V_262 ) {
F_3 ( V_34 L_2 ,
V_6 -> V_35 , __FILE__ , __LINE__ , V_36 ) ;
goto V_75;
}
for ( V_92 = 0 ; V_92 < V_6 -> V_31 . V_32 ; V_92 ++ ) {
if ( ( F_212 ( V_6 , & V_29 , & V_583 ,
V_92 ) ) ) {
F_3 ( V_34 L_2 ,
V_6 -> V_35 , __FILE__ , __LINE__ , V_36 ) ;
goto V_75;
}
V_30 = F_9 ( V_29 . V_38 ) &
V_39 ;
if ( V_30 != V_40 ) {
F_3 ( V_34 L_2 ,
V_6 -> V_35 , __FILE__ , __LINE__ , V_36 ) ;
goto V_75;
}
if ( V_92 == 0 )
V_6 -> V_31 . V_27 = F_9 ( V_574 ->
V_577 [ 0 ] . V_580 ) ;
V_6 -> V_31 . V_262 [ V_92 ] . V_27 = V_6 -> V_31 . V_27 ;
V_6 -> V_31 . V_262 [ V_92 ] . V_595 = V_92 ;
F_213 ( V_6 , & V_6 -> V_31 . V_262 [ V_92 ] ,
V_583 , V_6 -> V_31 . V_592 ) ;
}
if ( ( F_12 ( V_6 , & V_29 , & V_28 ,
V_33 , V_6 -> V_31 . V_27 ) ) ) {
F_3 ( V_34 L_2 ,
V_6 -> V_35 , __FILE__ , __LINE__ , V_36 ) ;
goto V_75;
}
V_6 -> V_31 . V_542 =
F_9 ( V_28 . V_541 ) ;
V_6 -> V_31 . V_9 = F_6 ( V_28 . V_11 ) ;
F_3 ( V_58 L_182
L_183 , V_6 -> V_35 , V_6 -> V_31 . V_27 ,
( unsigned long long ) V_6 -> V_31 . V_9 ,
V_6 -> V_31 . V_32 ) ;
if ( V_6 -> V_31 . V_542 ) {
if ( ! ( F_214 ( V_6 , & V_29 ,
& V_584 ,
V_596 ,
V_6 -> V_31 . V_542 ) ) ) {
V_6 -> V_31 . V_14 =
F_6 ( V_584 . V_16 ) ;
}
}
V_75:
F_20 ( V_582 ) ;
F_20 ( V_574 ) ;
}
static int
F_215 ( struct V_5 * V_6 , T_4 V_27 )
{
struct V_78 * V_79 ;
T_9 V_29 ;
T_38 V_597 ;
T_39 V_598 ;
T_37 V_584 ;
T_10 V_30 ;
T_4 V_599 ;
T_1 V_9 , V_69 = 0 ;
int V_92 ;
unsigned long V_65 ;
struct V_353 * V_354 = NULL ;
int V_20 = 0 ;
if ( ! V_27 )
return - 1 ;
if ( V_6 -> V_304 || V_6 -> V_306 )
return - 1 ;
if ( ( F_216 ( V_6 , & V_29 , & V_597 ,
V_600 , V_27 ) ) ) {
F_3 ( V_34 L_2 ,
V_6 -> V_35 , __FILE__ , __LINE__ , V_36 ) ;
return - 1 ;
}
V_30 = F_9 ( V_29 . V_38 ) &
V_39 ;
if ( V_30 != V_40 ) {
F_3 ( V_34 L_2 ,
V_6 -> V_35 , __FILE__ , __LINE__ , V_36 ) ;
return - 1 ;
}
V_599 = F_9 ( V_597 . V_601 ) ;
if ( F_11 ( V_6 , V_599 , & V_69 )
!= 0 ) {
F_3 ( V_34 L_2 ,
V_6 -> V_35 , __FILE__ , __LINE__ , V_36 ) ;
return - 1 ;
}
if ( V_69 != V_6 -> V_31 . V_9 ) {
F_18 ( & V_6 -> V_80 , V_65 ) ;
V_79 = F_34 ( V_6 ,
V_69 ) ;
F_21 ( & V_6 -> V_80 , V_65 ) ;
if ( ! V_79 ) {
V_20 = F_215 ( V_6 , V_599 ) ;
if ( V_20 != 0 )
return V_20 ;
}
}
F_18 ( & V_6 -> V_80 , V_65 ) ;
V_9 = F_6 ( V_597 . V_11 ) ;
V_79 = F_34 ( V_6 ,
V_9 ) ;
F_21 ( & V_6 -> V_80 , V_65 ) ;
if ( V_79 )
return 0 ;
V_79 = F_62 ( sizeof( struct V_78 ) ,
V_160 ) ;
if ( ! V_79 ) {
F_3 ( V_34 L_2 ,
V_6 -> V_35 , __FILE__ , __LINE__ , V_36 ) ;
return - 1 ;
}
V_79 -> V_27 = V_27 ;
V_79 -> V_32 = V_597 . V_602 ;
V_79 -> V_69 = V_69 ;
V_79 -> V_9 = V_9 ;
F_3 ( V_58 L_184
L_185 , V_6 -> V_35 ,
V_27 , V_599 , ( unsigned long long )
V_79 -> V_9 , V_79 -> V_32 ) ;
if ( ! V_79 -> V_32 )
goto V_603;
V_79 -> V_262 = F_211 ( V_79 -> V_32 ,
sizeof( struct V_594 ) , V_160 ) ;
if ( ! V_79 -> V_262 ) {
F_3 ( V_34 L_2 ,
V_6 -> V_35 , __FILE__ , __LINE__ , V_36 ) ;
V_20 = - 1 ;
goto V_603;
}
F_147 ( & V_79 -> V_604 ) ;
V_354 = F_25 ( V_6 , V_27 ,
V_69 ) ;
if ( ! V_354 ) {
F_3 ( V_34 L_2 ,
V_6 -> V_35 , __FILE__ , __LINE__ , V_36 ) ;
V_20 = - 1 ;
goto V_603;
}
V_79 -> V_592 = & V_354 -> V_159 -> V_157 ;
for ( V_92 = 0 ; V_92 < V_79 -> V_32 ; V_92 ++ ) {
if ( ( F_217 ( V_6 , & V_29 ,
& V_598 , V_92 , V_27 ) ) ) {
F_3 ( V_34 L_2 ,
V_6 -> V_35 , __FILE__ , __LINE__ , V_36 ) ;
V_20 = - 1 ;
goto V_603;
}
V_79 -> V_262 [ V_92 ] . V_27 = V_27 ;
V_79 -> V_262 [ V_92 ] . V_595 = V_92 ;
if ( ( F_218 ( V_6 ,
& V_79 -> V_262 [ V_92 ] , V_598 ,
V_79 -> V_592 ) ) ) {
F_3 ( V_34 L_2 ,
V_6 -> V_35 , __FILE__ , __LINE__ , V_36 ) ;
V_20 = - 1 ;
goto V_603;
}
}
if ( V_79 -> V_542 ) {
if ( ! ( F_214 ( V_6 , & V_29 ,
& V_584 , V_596 ,
V_79 -> V_542 ) ) ) {
V_79 -> V_14 =
F_6 ( V_584 . V_16 ) ;
}
}
F_35 ( V_6 , V_79 ) ;
return 0 ;
V_603:
if ( V_354 )
F_26 ( V_6 , V_79 -> V_9 ,
V_69 ) ;
F_20 ( V_79 ) ;
return V_20 ;
}
static T_6
F_219 ( struct V_5 * V_6 , T_4 V_88 , T_6 V_280 , T_10 V_281 )
{
T_18 * V_29 ;
V_29 = F_99 ( V_6 , V_281 ) ;
if ( V_6 -> V_605 . V_283 == V_284 )
return 1 ;
if ( V_6 -> V_605 . V_88 != V_88 )
return 1 ;
V_6 -> V_605 . V_283 |= V_285 ;
if ( V_29 ) {
memcpy ( V_6 -> V_605 . V_281 , V_29 ,
V_29 -> V_286 * 4 ) ;
V_6 -> V_605 . V_283 |= V_287 ;
}
V_6 -> V_605 . V_283 &= ~ V_288 ;
F_100 ( & V_6 -> V_605 . V_289 ) ;
return 1 ;
}
void
F_220 ( struct V_5 * V_6 , T_1 V_9 )
{
struct V_78 * V_79 ;
unsigned long V_65 ;
if ( V_6 -> V_304 )
return;
F_18 ( & V_6 -> V_80 , V_65 ) ;
V_79 = F_34 ( V_6 ,
V_9 ) ;
if ( V_79 )
F_19 ( & V_79 -> V_67 ) ;
F_21 ( & V_6 -> V_80 , V_65 ) ;
if ( V_79 )
F_221 ( V_6 , V_79 ) ;
}
static T_6
F_222 ( struct V_5 * V_6 , T_1 V_9 ,
T_4 V_27 , T_6 V_606 )
{
T_6 V_20 = 1 ;
char * V_272 = NULL ;
switch ( V_606 ) {
case V_607 :
case V_608 :
V_20 = 0 ;
break;
case V_609 :
V_272 = L_186 ;
break;
case V_610 :
V_272 = L_187 ;
break;
case V_611 :
V_272 = L_188 ;
break;
case V_612 :
V_272 = L_189 ;
break;
case V_613 :
V_272 = L_190 ;
break;
case V_614 :
case V_615 :
case V_616 :
case V_617 :
case V_618 :
case V_619 :
case V_620 :
case V_621 :
case V_622 :
case V_623 :
case V_624 :
case V_625 :
V_272 = L_191 ;
break;
default:
V_272 = L_62 ;
break;
}
if ( ! V_20 )
return 0 ;
F_3 ( V_34 L_192
L_95 , V_6 -> V_35 , V_272 ,
( unsigned long long ) V_9 , V_27 ) ;
return V_20 ;
}
static void
F_223 ( struct V_5 * V_6 , T_4 V_27 )
{
T_9 V_29 ;
T_8 V_28 ;
struct V_45 * V_46 ;
T_10 V_30 ;
unsigned long V_65 ;
T_1 V_9 ;
struct V_156 * V_70 ;
struct V_147 * V_148 ;
T_10 V_82 ;
if ( ( F_12 ( V_6 , & V_29 , & V_28 ,
V_33 , V_27 ) ) )
return;
V_30 = F_9 ( V_29 . V_38 ) & V_39 ;
if ( V_30 != V_40 )
return;
V_82 = F_69 ( V_28 . V_172 ) ;
if ( ! ( F_36 ( V_82 ) ) )
return;
F_18 ( & V_6 -> V_66 , V_65 ) ;
V_9 = F_6 ( V_28 . V_11 ) ;
V_46 = F_15 ( V_6 ,
V_9 ) ;
if ( ! V_46 ) {
F_3 ( V_34 L_193
L_194 , V_6 -> V_35 , V_27 ) ;
F_21 ( & V_6 -> V_66 , V_65 ) ;
return;
}
if ( F_152 ( V_46 -> V_27 != V_27 ) ) {
V_70 = V_46 -> V_70 ;
V_148 = V_70 -> V_150 ;
F_121 ( V_7 , V_70 , L_195
L_196 , V_46 -> V_27 , V_27 ) ;
V_148 -> V_27 = V_27 ;
V_46 -> V_27 = V_27 ;
}
if ( ! ( F_9 ( V_28 . V_171 ) &
V_626 ) ) {
F_3 ( V_34 L_193
L_197 , V_6 -> V_35 , V_27 ) ;
F_21 ( & V_6 -> V_66 , V_65 ) ;
return;
}
if ( F_222 ( V_6 , V_9 , V_27 ,
V_28 . V_627 ) ) {
F_21 ( & V_6 -> V_66 , V_65 ) ;
return;
}
F_21 ( & V_6 -> V_66 , V_65 ) ;
F_139 ( V_6 , V_9 ) ;
}
static int
F_224 ( struct V_5 * V_6 , T_4 V_27 , T_6 V_628 , T_6 V_629 )
{
T_9 V_29 ;
T_8 V_28 ;
T_37 V_584 ;
struct V_45 * V_46 ;
T_10 V_30 ;
T_40 V_9 ;
T_10 V_82 ;
unsigned long V_65 ;
if ( ( F_12 ( V_6 , & V_29 , & V_28 ,
V_33 , V_27 ) ) ) {
F_3 ( V_34 L_2 ,
V_6 -> V_35 , __FILE__ , __LINE__ , V_36 ) ;
return - 1 ;
}
V_30 = F_9 ( V_29 . V_38 ) &
V_39 ;
if ( V_30 != V_40 ) {
F_3 ( V_34 L_2 ,
V_6 -> V_35 , __FILE__ , __LINE__ , V_36 ) ;
return - 1 ;
}
V_9 = F_6 ( V_28 . V_11 ) ;
if ( ! ( F_9 ( V_28 . V_171 ) &
V_626 ) ) {
F_3 ( V_34 L_2 ,
V_6 -> V_35 , __FILE__ , __LINE__ , V_36 ) ;
F_3 ( V_34 L_198 ,
V_6 -> V_35 , F_9 ( V_28 . V_171 ) ) ;
return - 1 ;
}
if ( F_222 ( V_6 , V_9 , V_27 ,
V_28 . V_627 ) )
return - 1 ;
V_82 = F_69 ( V_28 . V_172 ) ;
if ( ! ( F_36 ( V_82 ) ) ) {
F_3 ( V_34 L_2 ,
V_6 -> V_35 , __FILE__ , __LINE__ , V_36 ) ;
return - 1 ;
}
F_18 ( & V_6 -> V_66 , V_65 ) ;
V_46 = F_15 ( V_6 ,
V_9 ) ;
F_21 ( & V_6 -> V_66 , V_65 ) ;
if ( V_46 )
return 0 ;
V_46 = F_62 ( sizeof( struct V_45 ) ,
V_160 ) ;
if ( ! V_46 ) {
F_3 ( V_34 L_2 ,
V_6 -> V_35 , __FILE__ , __LINE__ , V_36 ) ;
return - 1 ;
}
V_46 -> V_27 = V_27 ;
if ( F_11 ( V_6 , F_9
( V_28 . V_601 ) ,
& V_46 -> V_69 ) != 0 )
F_3 ( V_34 L_2 ,
V_6 -> V_35 , __FILE__ , __LINE__ , V_36 ) ;
V_46 -> V_542 =
F_9 ( V_28 . V_541 ) ;
V_46 -> V_18 =
F_9 ( V_28 . V_540 ) ;
V_46 -> V_82 = V_82 ;
V_46 -> V_9 = V_9 ;
V_46 -> V_262 = V_28 . V_630 ;
if ( V_46 -> V_542 && ! ( F_214 (
V_6 , & V_29 , & V_584 , V_596 ,
V_46 -> V_542 ) ) )
V_46 -> V_14 =
F_6 ( V_584 . V_16 ) ;
V_46 -> V_12 = F_6 ( V_28 . V_13 ) ;
if ( V_6 -> V_631 )
F_27 ( V_6 , V_46 ) ;
else
F_22 ( V_6 , V_46 ) ;
return 0 ;
}
static void
F_225 ( struct V_5 * V_6 ,
struct V_45 * V_46 )
{
struct V_147 * V_148 ;
if ( ( V_6 -> V_548 -> V_549 == V_550 ) &&
( V_46 -> V_539 ) ) {
F_194 ( V_6 , V_46 ) ;
V_46 -> V_539 = 0 ;
}
F_23 ( V_6 , F_3 ( V_58 L_199
L_107 , V_6 -> V_35 , V_36 ,
V_46 -> V_27 , ( unsigned long long )
V_46 -> V_9 ) ) ;
if ( V_46 -> V_70 && V_46 -> V_70 -> V_150 ) {
V_148 = V_46 -> V_70 -> V_150 ;
V_148 -> V_375 = 1 ;
F_139 ( V_6 , V_46 -> V_9 ) ;
V_148 -> V_27 =
V_161 ;
}
if ( ! V_6 -> V_632 )
F_26 ( V_6 ,
V_46 -> V_9 ,
V_46 -> V_69 ) ;
F_3 ( V_58 L_200
L_201 , V_6 -> V_35 , V_46 -> V_27 ,
( unsigned long long ) V_46 -> V_9 ) ;
F_23 ( V_6 , F_3 ( V_58 L_202
L_107 , V_6 -> V_35 , V_36 ,
V_46 -> V_27 , ( unsigned long long )
V_46 -> V_9 ) ) ;
F_20 ( V_46 ) ;
}
static void
F_226 ( struct V_5 * V_6 , T_4 V_27 )
{
struct V_45 * V_46 ;
unsigned long V_65 ;
if ( V_6 -> V_304 )
return;
F_18 ( & V_6 -> V_66 , V_65 ) ;
V_46 = F_16 ( V_6 , V_27 ) ;
if ( V_46 )
F_19 ( & V_46 -> V_67 ) ;
F_21 ( & V_6 -> V_66 , V_65 ) ;
if ( V_46 )
F_225 ( V_6 , V_46 ) ;
}
void
F_227 ( struct V_5 * V_6 ,
T_1 V_9 )
{
struct V_45 * V_46 ;
unsigned long V_65 ;
if ( V_6 -> V_304 )
return;
F_18 ( & V_6 -> V_66 , V_65 ) ;
V_46 = F_15 ( V_6 ,
V_9 ) ;
if ( V_46 )
F_19 ( & V_46 -> V_67 ) ;
F_21 ( & V_6 -> V_66 , V_65 ) ;
if ( V_46 )
F_225 ( V_6 , V_46 ) ;
}
static void
F_228 ( struct V_5 * V_6 ,
T_22 * V_362 )
{
int V_92 ;
T_4 V_27 ;
T_4 V_363 ;
T_6 V_364 ;
char * V_633 = NULL ;
T_6 V_576 , V_634 ;
switch ( V_362 -> V_390 ) {
case V_397 :
V_633 = L_203 ;
break;
case V_394 :
V_633 = L_204 ;
break;
case V_393 :
case 0 :
V_633 = L_205 ;
break;
case V_391 :
V_633 = L_206 ;
break;
default:
V_633 = L_207 ;
break;
}
F_3 ( V_58 L_208 ,
V_6 -> V_35 , V_633 ) ;
F_3 ( V_7 L_209
L_210 ,
F_9 ( V_362 -> V_389 ) ,
F_9 ( V_362 -> V_541 ) ,
V_362 -> V_368 , V_362 -> V_365 ) ;
for ( V_92 = 0 ; V_92 < V_362 -> V_365 ; V_92 ++ ) {
V_27 = F_9 ( V_362 -> V_366 [ V_92 ] . V_367 ) ;
if ( ! V_27 )
continue;
V_364 = V_362 -> V_368 + V_92 ;
V_363 = V_362 -> V_366 [ V_92 ] . V_369 &
V_370 ;
switch ( V_363 ) {
case V_635 :
V_633 = L_211 ;
break;
case V_388 :
V_633 = L_212 ;
break;
case V_371 :
V_633 = L_213 ;
break;
case V_636 :
V_633 = L_214 ;
break;
case V_637 :
V_633 = L_215 ;
break;
default:
V_633 = L_62 ;
break;
}
V_576 = V_362 -> V_366 [ V_92 ] . V_638 >> 4 ;
V_634 = V_362 -> V_366 [ V_92 ] . V_638 & 0xF ;
F_3 ( V_7 L_216
L_217 , V_364 ,
V_27 , V_633 , V_576 , V_634 ) ;
}
}
static void
F_229 ( struct V_5 * V_6 ,
struct V_340 * V_341 )
{
int V_92 ;
T_4 V_599 , V_27 ;
T_4 V_363 ;
T_6 V_364 , V_639 ;
struct V_78 * V_79 ;
T_1 V_9 ;
unsigned long V_65 ;
T_6 V_576 , V_634 ;
T_22 * V_362 =
( T_22 * )
V_341 -> V_362 ;
#ifdef F_204
if ( V_6 -> V_8 & V_640 )
F_228 ( V_6 , V_362 ) ;
#endif
if ( V_6 -> V_305 || V_6 -> V_306 )
return;
if ( ! V_6 -> V_31 . V_32 )
F_208 ( V_6 ) ;
else
F_205 ( V_6 ) ;
if ( V_341 -> V_396 ) {
F_23 ( V_6 , F_3 ( V_58 L_218
L_219 , V_6 -> V_35 ) ) ;
return;
}
V_599 = F_9 ( V_362 -> V_389 ) ;
if ( V_362 -> V_390 == V_397 )
if ( F_215 ( V_6 , V_599 ) != 0 )
return;
F_18 ( & V_6 -> V_80 , V_65 ) ;
V_79 = F_33 ( V_6 ,
V_599 ) ;
if ( V_79 ) {
V_9 = V_79 -> V_9 ;
V_639 = V_79 -> V_32 ;
} else if ( V_599 < V_6 -> V_31 . V_32 ) {
V_9 = V_6 -> V_31 . V_9 ;
V_639 = V_6 -> V_31 . V_32 ;
} else {
F_21 ( & V_6 -> V_80 , V_65 ) ;
return;
}
F_21 ( & V_6 -> V_80 , V_65 ) ;
for ( V_92 = 0 ; V_92 < V_362 -> V_365 ; V_92 ++ ) {
if ( V_341 -> V_396 ) {
F_23 ( V_6 , F_3 ( V_58 L_220
L_221 , V_6 -> V_35 ) ) ;
return;
}
if ( V_6 -> V_304 || V_6 -> V_305 ||
V_6 -> V_306 )
return;
V_364 = V_362 -> V_368 + V_92 ;
if ( V_364 >= V_639 )
continue;
V_363 = V_362 -> V_366 [ V_92 ] . V_369 &
V_370 ;
if ( ( V_362 -> V_366 [ V_92 ] . V_369 &
V_641 ) && ( V_363 !=
V_388 ) )
continue;
V_27 = F_9 ( V_362 -> V_366 [ V_92 ] . V_367 ) ;
if ( ! V_27 )
continue;
V_576 = V_362 -> V_366 [ V_92 ] . V_638 >> 4 ;
V_634 = V_362 -> V_366 [ V_92 ] . V_638 & 0xF ;
switch ( V_363 ) {
case V_636 :
if ( V_6 -> V_304 )
break;
if ( V_576 == V_634 )
break;
F_207 ( V_6 , V_9 ,
V_27 , V_364 , V_576 ) ;
if ( V_576 < V_581 )
break;
F_223 ( V_6 , V_27 ) ;
break;
case V_635 :
if ( V_6 -> V_304 )
break;
F_207 ( V_6 , V_9 ,
V_27 , V_364 , V_576 ) ;
F_224 ( V_6 , V_27 , V_364 , 0 ) ;
break;
case V_388 :
F_226 ( V_6 , V_27 ) ;
break;
}
}
if ( V_362 -> V_390 == V_394 &&
V_79 )
F_220 ( V_6 , V_9 ) ;
}
static void
F_230 ( struct V_5 * V_6 ,
T_32 * V_362 )
{
char * V_642 = NULL ;
switch ( V_362 -> V_403 ) {
case V_556 :
V_642 = L_222 ;
break;
case V_643 :
V_642 = L_223 ;
break;
case V_644 :
V_642 = L_224 ;
break;
case V_645 :
V_642 = L_225 ;
break;
case V_646 :
V_642 = L_226 ;
break;
case V_647 :
V_642 = L_227 ;
break;
case V_648 :
V_642 = L_228 ;
break;
case V_649 :
V_642 = L_229 ;
break;
case V_650 :
V_642 = L_230 ;
break;
case V_651 :
V_642 = L_231 ;
break;
case V_652 :
V_642 = L_232 ;
break;
case V_653 :
V_642 = L_233 ;
break;
case V_654 :
V_642 = L_234 ;
break;
default:
V_642 = L_235 ;
break;
}
F_3 ( V_58 L_236
L_237 ,
V_6 -> V_35 , V_642 , F_9 ( V_362 -> V_221 ) ,
( unsigned long long ) F_6 ( V_362 -> V_11 ) ,
F_9 ( V_362 -> V_529 ) ) ;
if ( V_362 -> V_403 == V_556 )
F_3 ( V_58 L_238 , V_6 -> V_35 ,
V_362 -> V_557 , V_362 -> V_655 ) ;
F_3 ( V_7 L_239 ) ;
}
static void
F_231 ( struct V_5 * V_6 ,
struct V_340 * V_341 )
{
struct V_147 * V_656 ;
struct V_45 * V_46 ;
T_1 V_9 ;
unsigned long V_65 ;
T_32 * V_362 =
( T_32 * )
V_341 -> V_362 ;
#ifdef F_204
if ( V_6 -> V_8 & V_640 )
F_230 ( V_6 ,
V_362 ) ;
#endif
if ( ( V_6 -> V_245 . V_657 >> 8 ) < 0xC )
return;
if ( V_362 -> V_403 !=
V_644 &&
V_362 -> V_403 !=
V_650 )
return;
F_18 ( & V_6 -> V_66 , V_65 ) ;
V_9 = F_6 ( V_362 -> V_11 ) ;
V_46 = F_15 ( V_6 ,
V_9 ) ;
if ( ! V_46 || ! V_46 -> V_70 ) {
F_21 ( & V_6 -> V_66 , V_65 ) ;
return;
}
V_656 = V_46 -> V_70 -> V_150 ;
if ( ! V_656 ) {
F_21 ( & V_6 -> V_66 , V_65 ) ;
return;
}
if ( V_362 -> V_403 ==
V_644 )
V_656 -> V_291 = 1 ;
else
V_656 -> V_291 = 0 ;
F_21 ( & V_6 -> V_66 , V_65 ) ;
}
static void
F_232 ( struct V_5 * V_6 ,
T_41 * V_362 )
{
char * V_642 = NULL ;
switch ( V_362 -> V_403 ) {
case V_658 :
V_642 = L_240 ;
break;
case V_659 :
V_642 = L_241 ;
break;
default:
V_642 = L_235 ;
break;
}
F_3 ( V_58 L_242
L_243
L_244 , V_6 -> V_35 , V_642 ,
F_9 ( V_362 -> V_541 ) ,
( unsigned long long ) F_6 ( V_362 -> V_16 ) ,
F_9 ( V_362 -> V_660 ) ) ;
}
static void
F_233 ( struct V_5 * V_6 ,
struct V_340 * V_341 )
{
#ifdef F_204
if ( V_6 -> V_8 & V_640 )
F_232 ( V_6 ,
( T_41 * )
V_341 -> V_362 ) ;
#endif
}
static void
F_234 ( struct V_5 * V_6 ,
struct V_340 * V_341 )
{
struct V_87 * V_90 ;
struct V_138 * V_139 ;
T_4 V_88 , V_27 ;
T_10 V_95 ;
struct V_145 * V_146 ;
T_10 V_661 ;
T_10 V_662 ;
T_21 * V_29 ;
T_42 * V_362 =
( T_42 * )
V_341 -> V_362 ;
T_4 V_30 ;
unsigned long V_65 ;
int V_74 ;
T_6 V_663 = 0 ;
T_6 V_664 ;
F_105 ( & V_6 -> V_282 . V_301 ) ;
F_235 ( V_665
L_245 ,
V_6 -> V_35 , V_36 , V_362 -> V_630 ,
V_362 -> V_666 ) ;
F_140 ( V_6 ) ;
F_18 ( & V_6 -> V_91 , V_65 ) ;
V_29 = V_6 -> V_282 . V_281 ;
V_667:
if ( V_663 ++ == 5 ) {
F_23 ( V_6 , F_3 ( V_58 L_246 ,
V_6 -> V_35 , V_36 ) ) ;
goto V_75;
} else if ( V_663 > 1 )
F_23 ( V_6 , F_3 ( V_58 L_247 ,
V_6 -> V_35 , V_36 , V_663 - 1 ) ) ;
V_661 = 0 ;
V_662 = 0 ;
for ( V_88 = 1 ; V_88 <= V_6 -> V_93 ; V_88 ++ ) {
if ( V_6 -> V_304 )
goto V_75;
V_90 = F_37 ( V_6 , V_88 ) ;
if ( ! V_90 )
continue;
V_139 = V_90 -> V_43 ;
V_146 = V_139 -> V_150 ;
if ( ! V_146 || ! V_146 -> V_152 )
continue;
if ( V_146 -> V_152 -> V_65 &
V_167 )
continue;
if ( V_146 -> V_152 -> V_65 &
V_153 )
continue;
V_27 = V_146 -> V_152 -> V_27 ;
V_95 = V_146 -> V_95 ;
V_662 ++ ;
if ( V_6 -> V_304 )
goto V_75;
F_21 ( & V_6 -> V_91 , V_65 ) ;
V_74 = F_104 ( V_6 , V_27 , 0 , 0 , V_95 ,
V_331 , V_88 , 30 ,
V_668 ) ;
if ( V_74 == V_302 ) {
F_51 ( V_547 , V_139 ,
L_248
L_249 , V_90 ) ;
F_18 ( & V_6 -> V_91 , V_65 ) ;
goto V_667;
}
V_30 = F_9 ( V_29 -> V_38 )
& V_39 ;
if ( V_30 != V_40 ) {
F_51 ( V_547 , V_139 , L_250
L_251 , V_30 ,
V_90 ) ;
F_18 ( & V_6 -> V_91 , V_65 ) ;
goto V_667;
}
if ( V_29 -> V_327 ==
V_277 ||
V_29 -> V_327 ==
V_279 ) {
F_18 ( & V_6 -> V_91 , V_65 ) ;
continue;
}
V_664 = 0 ;
V_669:
if ( V_664 ++ == 60 ) {
F_23 ( V_6 , F_3 ( V_58
L_252 , V_6 -> V_35 ,
V_36 ) ) ;
F_18 ( & V_6 -> V_91 , V_65 ) ;
goto V_667;
}
if ( V_6 -> V_304 )
goto V_670;
V_74 = F_104 ( V_6 , V_27 , V_139 -> V_73 , V_139 -> V_72 ,
V_139 -> V_95 , V_315 , V_88 , 30 ,
V_668 ) ;
if ( V_74 == V_302 ) {
F_51 ( V_547 , V_139 ,
L_253
L_82 , V_90 ) ;
goto V_669;
}
if ( V_664 > 1 )
F_51 ( V_547 , V_139 ,
L_254
L_255 ,
V_664 - 1 , V_90 ) ;
V_661 += F_69 ( V_29 -> V_325 ) ;
F_18 ( & V_6 -> V_91 , V_65 ) ;
}
if ( V_6 -> V_671 ) {
F_23 ( V_6 , F_3 ( V_58 L_256
L_257 , V_6 -> V_35 , V_36 ) ) ;
V_6 -> V_671 = 0 ;
goto V_667;
}
V_75:
F_21 ( & V_6 -> V_91 , V_65 ) ;
V_670:
F_23 ( V_6 , F_3 ( V_58
L_258 ,
V_6 -> V_35 , V_36 , V_662 , V_661 ) ) ;
V_6 -> V_672 = 0 ;
if ( ! V_6 -> V_304 )
F_137 ( V_6 ) ;
F_118 ( & V_6 -> V_282 . V_301 ) ;
}
static void
F_236 ( struct V_5 * V_6 ,
struct V_340 * V_341 )
{
T_43 * V_362 =
( T_43 * )
V_341 -> V_362 ;
#ifdef F_204
if ( V_6 -> V_8 & V_640 ) {
F_3 ( V_58 L_259 , V_6 -> V_35 ,
( V_362 -> V_403 == V_673 ) ?
L_260 : L_261 ) ;
if ( V_362 -> V_674 )
F_3 ( L_262 ,
F_69 ( V_362 -> V_674 ) ) ;
F_3 ( L_239 ) ;
}
#endif
if ( V_362 -> V_403 == V_673 &&
! V_6 -> V_31 . V_32 ) {
if ( V_675 > 0 && V_6 -> V_304 ) {
while ( V_6 -> V_304 )
F_237 ( 1 ) ;
}
F_208 ( V_6 ) ;
}
}
static void
F_238 ( struct V_138 * V_139 , void * V_170 )
{
int V_20 ;
V_139 -> V_170 = V_170 ? 1 : 0 ;
F_51 ( V_7 , V_139 , L_263 ,
V_139 -> V_170 ? L_264 : L_265 ) ;
V_20 = F_239 ( V_139 ) ;
}
static void
F_240 ( struct V_5 * V_6 ,
T_26 * V_400 )
{
struct V_47 * V_48 ;
unsigned long V_65 ;
T_1 V_52 ;
T_4 V_27 = F_9 ( V_400 -> V_406 ) ;
int V_20 ;
F_92 ( V_6 , V_27 , & V_52 ) ;
if ( ! V_52 ) {
F_3 ( V_34
L_2 , V_6 -> V_35 ,
__FILE__ , __LINE__ , V_36 ) ;
return;
}
F_18 ( & V_6 -> V_76 , V_65 ) ;
V_48 = F_30 ( V_6 , V_52 ) ;
F_21 ( & V_6 -> V_76 , V_65 ) ;
if ( V_48 )
return;
V_48 = F_62 ( sizeof( struct V_47 ) , V_160 ) ;
if ( ! V_48 ) {
F_3 ( V_34
L_2 , V_6 -> V_35 ,
__FILE__ , __LINE__ , V_36 ) ;
return;
}
V_48 -> V_72 = V_6 -> V_676 ++ ;
V_48 -> V_73 = V_162 ;
V_48 -> V_27 = V_27 ;
V_48 -> V_52 = V_52 ;
F_31 ( V_6 , V_48 ) ;
if ( ! V_6 -> V_631 ) {
V_20 = F_241 ( V_6 -> V_142 , V_162 ,
V_48 -> V_72 , 0 ) ;
if ( V_20 )
F_32 ( V_6 , V_48 ) ;
} else {
F_18 ( & V_6 -> V_76 , V_65 ) ;
F_13 ( V_6 , V_48 , 1 ) ;
F_21 ( & V_6 -> V_76 , V_65 ) ;
}
}
static void
F_242 ( struct V_5 * V_6 , T_4 V_27 )
{
struct V_47 * V_48 ;
unsigned long V_65 ;
struct V_147 * V_148 ;
struct V_156 * V_70 = NULL ;
F_18 ( & V_6 -> V_76 , V_65 ) ;
V_48 = F_29 ( V_6 , V_27 ) ;
if ( V_48 ) {
if ( V_48 -> V_70 ) {
V_70 = V_48 -> V_70 ;
V_148 = V_70 -> V_150 ;
V_148 -> V_375 = 1 ;
}
F_3 ( V_58 L_266
L_201 , V_6 -> V_35 , V_48 -> V_27 ,
( unsigned long long ) V_48 -> V_52 ) ;
F_19 ( & V_48 -> V_67 ) ;
F_20 ( V_48 ) ;
}
F_21 ( & V_6 -> V_76 , V_65 ) ;
if ( V_70 )
F_243 ( & V_70 -> V_157 ) ;
}
static void
F_244 ( struct V_5 * V_6 ,
T_26 * V_400 )
{
struct V_45 * V_46 ;
struct V_156 * V_70 = NULL ;
struct V_147 * V_148 ;
unsigned long V_65 ;
T_4 V_27 = F_9 ( V_400 -> V_409 ) ;
F_18 ( & V_6 -> V_66 , V_65 ) ;
V_46 = F_16 ( V_6 , V_27 ) ;
if ( V_46 ) {
V_46 -> V_251 = 0 ;
V_46 -> V_252 = 0 ;
F_163 ( V_27 , V_6 -> V_166 ) ;
if ( V_46 -> V_70 && V_46 -> V_70 -> V_150 ) {
V_70 = V_46 -> V_70 ;
V_148 = V_70 -> V_150 ;
V_148 -> V_65 &=
~ V_167 ;
}
}
F_21 ( & V_6 -> V_66 , V_65 ) ;
if ( ! V_46 )
return;
if ( V_70 )
F_245 ( V_70 , NULL , F_238 ) ;
}
static void
F_246 ( struct V_5 * V_6 ,
T_26 * V_400 )
{
struct V_45 * V_46 ;
struct V_156 * V_70 = NULL ;
struct V_147 * V_148 ;
unsigned long V_65 ;
T_4 V_27 = F_9 ( V_400 -> V_409 ) ;
T_4 V_251 = 0 ;
T_1 V_252 = 0 ;
F_91 ( V_6 , V_27 , & V_251 ) ;
if ( V_251 )
F_92 ( V_6 , V_251 ,
& V_252 ) ;
F_18 ( & V_6 -> V_66 , V_65 ) ;
V_46 = F_16 ( V_6 , V_27 ) ;
if ( V_46 ) {
F_144 ( V_27 , V_6 -> V_166 ) ;
if ( V_46 -> V_70 && V_46 -> V_70 -> V_150 ) {
V_70 = V_46 -> V_70 ;
V_148 = V_70 -> V_150 ;
V_148 -> V_65 |=
V_167 ;
V_46 -> V_251 = V_251 ;
V_46 -> V_252 = V_252 ;
}
}
F_21 ( & V_6 -> V_66 , V_65 ) ;
if ( ! V_46 )
return;
if ( V_70 )
F_245 ( V_70 , ( void * ) 1 , F_238 ) ;
}
static void
F_247 ( struct V_5 * V_6 ,
T_26 * V_400 )
{
T_4 V_27 = F_9 ( V_400 -> V_409 ) ;
F_226 ( V_6 , V_27 ) ;
}
static void
F_248 ( struct V_5 * V_6 ,
T_26 * V_400 )
{
struct V_45 * V_46 ;
unsigned long V_65 ;
T_4 V_27 = F_9 ( V_400 -> V_409 ) ;
T_9 V_29 ;
T_8 V_28 ;
T_10 V_30 ;
T_1 V_9 ;
T_4 V_599 ;
F_144 ( V_27 , V_6 -> V_166 ) ;
F_18 ( & V_6 -> V_66 , V_65 ) ;
V_46 = F_16 ( V_6 , V_27 ) ;
F_21 ( & V_6 -> V_66 , V_65 ) ;
if ( V_46 )
return;
if ( ( F_12 ( V_6 , & V_29 , & V_28 ,
V_33 , V_27 ) ) ) {
F_3 ( V_34 L_2 ,
V_6 -> V_35 , __FILE__ , __LINE__ , V_36 ) ;
return;
}
V_30 = F_9 ( V_29 . V_38 ) &
V_39 ;
if ( V_30 != V_40 ) {
F_3 ( V_34 L_2 ,
V_6 -> V_35 , __FILE__ , __LINE__ , V_36 ) ;
return;
}
V_599 = F_9 ( V_28 . V_601 ) ;
if ( ! F_11 ( V_6 , V_599 , & V_9 ) )
F_207 ( V_6 , V_9 , V_27 ,
V_28 . V_630 , V_581 ) ;
F_224 ( V_6 , V_27 , 0 , 1 ) ;
}
static void
F_249 ( struct V_5 * V_6 ,
T_25 * V_362 )
{
T_26 * V_400 ;
T_6 V_677 ;
int V_92 ;
char * V_642 = NULL , * V_678 = NULL ;
V_400 = ( T_26 * ) & V_362 -> V_401 [ 0 ] ;
F_3 ( V_58 L_267 ,
V_6 -> V_35 , ( F_69 ( V_362 -> V_171 ) &
V_407 ) ?
L_268 : L_269 , V_362 -> V_402 ) ;
for ( V_92 = 0 ; V_92 < V_362 -> V_402 ; V_92 ++ , V_400 ++ ) {
switch ( V_400 -> V_403 ) {
case V_679 :
V_642 = L_203 ;
break;
case V_405 :
V_642 = L_204 ;
break;
case V_680 :
V_642 = L_270 ;
break;
case V_681 :
V_642 = L_271 ;
break;
case V_408 :
V_642 = L_272 ;
break;
case V_682 :
V_642 = L_273 ;
break;
case V_404 :
V_642 = L_274 ;
break;
case V_683 :
V_642 = L_275 ;
break;
case V_684 :
V_642 = L_276 ;
break;
default:
V_642 = L_235 ;
break;
}
V_677 = F_9 ( V_400 -> V_685 ) &
V_686 ;
switch ( V_677 ) {
case V_687 :
V_678 = L_75 ;
break;
case V_688 :
V_678 = L_277 ;
break;
case V_689 :
V_678 = L_278 ;
break;
default:
V_678 = L_279 ;
break;
}
F_3 ( V_7 L_280
L_281 , V_678 ,
V_642 , F_9 ( V_400 -> V_406 ) ,
F_9 ( V_400 -> V_409 ) ,
V_400 -> V_220 ) ;
}
}
static void
F_250 ( struct V_5 * V_6 ,
struct V_340 * V_341 )
{
T_26 * V_400 ;
int V_92 ;
T_6 V_690 ;
T_25 * V_362 =
( T_25 * )
V_341 -> V_362 ;
#ifdef F_204
if ( ( V_6 -> V_8 & V_640 )
&& ! V_6 -> V_261 )
F_249 ( V_6 , V_362 ) ;
#endif
if ( V_6 -> V_304 )
return;
V_690 = ( F_69 ( V_362 -> V_171 ) &
V_407 ) ? 1 : 0 ;
V_400 = ( T_26 * ) & V_362 -> V_401 [ 0 ] ;
for ( V_92 = 0 ; V_92 < V_362 -> V_402 ; V_92 ++ , V_400 ++ ) {
switch ( V_400 -> V_403 ) {
case V_682 :
case V_679 :
if ( ! V_690 )
F_240 ( V_6 , V_400 ) ;
break;
case V_404 :
case V_405 :
if ( ! V_690 )
F_242 ( V_6 ,
F_9 ( V_400 -> V_406 ) ) ;
break;
case V_683 :
if ( ! V_6 -> V_163 )
F_246 ( V_6 , V_400 ) ;
break;
case V_684 :
if ( ! V_6 -> V_163 )
F_244 ( V_6 , V_400 ) ;
break;
case V_681 :
if ( ! V_6 -> V_163 )
F_248 ( V_6 , V_400 ) ;
break;
case V_408 :
if ( ! V_6 -> V_163 )
F_247 ( V_6 , V_400 ) ;
break;
}
}
}
static void
F_251 ( struct V_5 * V_6 ,
struct V_340 * V_341 )
{
T_1 V_52 ;
unsigned long V_65 ;
struct V_47 * V_48 ;
T_4 V_27 ;
T_10 V_188 ;
int V_20 ;
T_27 * V_362 =
( T_27 * )
V_341 -> V_362 ;
if ( V_6 -> V_304 )
return;
if ( V_362 -> V_403 != V_410 )
return;
V_27 = F_9 ( V_362 -> V_406 ) ;
V_188 = F_69 ( V_362 -> V_411 ) ;
if ( ! V_6 -> V_261 )
F_23 ( V_6 , F_3 ( V_58 L_49
L_282 , V_6 -> V_35 , V_36 , V_27 ,
F_69 ( V_362 -> V_691 ) , V_188 ) ) ;
switch ( V_188 ) {
case V_198 :
case V_197 :
F_242 ( V_6 , V_27 ) ;
break;
case V_193 :
case V_195 :
case V_192 :
F_18 ( & V_6 -> V_76 , V_65 ) ;
V_48 = F_29 ( V_6 , V_27 ) ;
F_21 ( & V_6 -> V_76 , V_65 ) ;
if ( V_48 )
break;
F_92 ( V_6 , V_27 , & V_52 ) ;
if ( ! V_52 ) {
F_3 ( V_34
L_2 , V_6 -> V_35 ,
__FILE__ , __LINE__ , V_36 ) ;
break;
}
V_48 = F_62 ( sizeof( struct V_47 ) , V_160 ) ;
if ( ! V_48 ) {
F_3 ( V_34
L_2 , V_6 -> V_35 ,
__FILE__ , __LINE__ , V_36 ) ;
break;
}
V_48 -> V_72 = V_6 -> V_676 ++ ;
V_48 -> V_73 = V_162 ;
V_48 -> V_27 = V_27 ;
V_48 -> V_52 = V_52 ;
F_31 ( V_6 , V_48 ) ;
V_20 = F_241 ( V_6 -> V_142 , V_162 ,
V_48 -> V_72 , 0 ) ;
if ( V_20 )
F_32 ( V_6 , V_48 ) ;
break;
case V_692 :
default:
break;
}
}
static void
F_252 ( struct V_5 * V_6 ,
struct V_340 * V_341 )
{
T_4 V_27 , V_599 ;
T_10 V_188 ;
struct V_45 * V_46 ;
unsigned long V_65 ;
T_9 V_29 ;
T_8 V_28 ;
T_10 V_30 ;
T_44 * V_362 =
( T_44 * )
V_341 -> V_362 ;
T_1 V_9 ;
if ( V_6 -> V_304 )
return;
if ( V_362 -> V_403 != V_693 )
return;
V_27 = F_9 ( V_362 -> V_409 ) ;
V_188 = F_69 ( V_362 -> V_411 ) ;
if ( ! V_6 -> V_261 )
F_23 ( V_6 , F_3 ( V_58 L_49
L_282 , V_6 -> V_35 , V_36 , V_27 ,
F_69 ( V_362 -> V_691 ) , V_188 ) ) ;
switch ( V_188 ) {
case V_694 :
case V_695 :
case V_696 :
case V_697 :
case V_698 :
if ( ! V_6 -> V_163 )
F_144 ( V_27 , V_6 -> V_166 ) ;
F_18 ( & V_6 -> V_66 , V_65 ) ;
V_46 = F_16 ( V_6 , V_27 ) ;
F_21 ( & V_6 -> V_66 , V_65 ) ;
if ( V_46 )
return;
if ( ( F_12 ( V_6 , & V_29 ,
& V_28 , V_33 ,
V_27 ) ) ) {
F_3 ( V_34 L_2 ,
V_6 -> V_35 , __FILE__ , __LINE__ , V_36 ) ;
return;
}
V_30 = F_9 ( V_29 . V_38 ) &
V_39 ;
if ( V_30 != V_40 ) {
F_3 ( V_34 L_2 ,
V_6 -> V_35 , __FILE__ , __LINE__ , V_36 ) ;
return;
}
V_599 = F_9 ( V_28 . V_601 ) ;
if ( ! F_11 ( V_6 , V_599 , & V_9 ) )
F_207 ( V_6 , V_9 , V_27 ,
V_28 . V_630 , V_581 ) ;
F_224 ( V_6 , V_27 , 0 , 1 ) ;
break;
case V_699 :
case V_700 :
case V_701 :
default:
break;
}
}
static void
F_253 ( struct V_5 * V_6 ,
T_45 * V_362 )
{
char * V_642 = NULL ;
switch ( V_362 -> V_702 ) {
case V_703 :
V_642 = L_283 ;
break;
case V_704 :
V_642 = L_284 ;
break;
case V_705 :
V_642 = L_285 ;
break;
case V_706 :
V_642 = L_286 ;
break;
case V_707 :
V_642 = L_287 ;
break;
}
if ( ! V_642 )
return;
F_3 ( V_58 L_288
L_289 ,
V_6 -> V_35 , V_642 ,
F_9 ( V_362 -> V_406 ) ,
V_362 -> V_708 ) ;
}
static void
F_254 ( struct V_5 * V_6 ,
struct V_340 * V_341 )
{
T_45 * V_362 =
( T_45 * )
V_341 -> V_362 ;
static struct V_47 * V_48 ;
unsigned long V_65 ;
T_4 V_27 ;
#ifdef F_204
if ( ( V_6 -> V_8 & V_640 )
&& ! V_6 -> V_261 )
F_253 ( V_6 ,
V_362 ) ;
#endif
if ( V_362 -> V_702 == V_703 ) {
F_18 ( & V_6 -> V_76 , V_65 ) ;
V_27 = F_9 ( V_362 -> V_406 ) ;
V_48 = F_29 ( V_6 , V_27 ) ;
if ( V_48 )
V_48 -> V_181 =
V_362 -> V_708 ;
F_21 ( & V_6 -> V_76 , V_65 ) ;
}
}
static void
F_255 ( struct V_5 * V_6 )
{
struct V_145 * V_146 ;
struct V_138 * V_139 ;
F_102 (sdev, ioc->shost) {
V_146 = V_139 -> V_150 ;
if ( V_146 && V_146 -> V_152 )
V_146 -> V_152 -> V_375 = 1 ;
}
}
static void
F_256 ( struct V_5 * V_6 , T_1 V_9 ,
T_4 V_18 , T_4 V_27 )
{
struct V_147 * V_148 = NULL ;
struct V_156 * V_70 ;
struct V_45 * V_46 ;
unsigned long V_65 ;
F_18 ( & V_6 -> V_66 , V_65 ) ;
F_4 (sas_device, &ioc->sas_device_list, list) {
if ( V_46 -> V_9 == V_9 &&
V_46 -> V_18 == V_18 ) {
V_46 -> V_709 = 1 ;
V_70 = V_46 -> V_70 ;
if ( V_70 && V_70 -> V_150 ) {
V_148 = V_70 -> V_150 ;
V_148 -> V_291 = 0 ;
V_148 -> V_375 = 0 ;
} else
V_148 = NULL ;
if ( V_70 )
F_121 ( V_7 , V_70 ,
L_290
L_291
L_292 , V_27 ,
( unsigned long long ) V_46 -> V_9 ,
( unsigned long long )
V_46 -> V_14 ,
V_46 -> V_18 ) ;
if ( V_46 -> V_27 == V_27 )
goto V_75;
F_3 ( V_7 L_293 ,
V_46 -> V_27 ) ;
V_46 -> V_27 = V_27 ;
if ( V_148 )
V_148 -> V_27 = V_27 ;
goto V_75;
}
}
V_75:
F_21 ( & V_6 -> V_66 , V_65 ) ;
}
static void
F_257 ( struct V_5 * V_6 )
{
T_8 V_28 ;
T_9 V_29 ;
T_4 V_30 ;
T_40 V_9 ;
T_4 V_27 ;
T_10 V_82 ;
T_4 V_18 ;
F_3 ( V_58 L_294 , V_6 -> V_35 ) ;
if ( F_43 ( & V_6 -> V_68 ) )
goto V_75;
V_27 = 0xFFFF ;
while ( ! ( F_12 ( V_6 , & V_29 ,
& V_28 , V_710 ,
V_27 ) ) ) {
V_30 = F_9 ( V_29 . V_38 ) &
V_39 ;
if ( V_30 != V_40 )
break;
V_27 = F_9 ( V_28 . V_221 ) ;
V_82 = F_69 ( V_28 . V_172 ) ;
if ( ! ( F_36 ( V_82 ) ) )
continue;
V_9 = F_6 ( V_28 . V_11 ) ;
V_18 = F_9 ( V_28 . V_540 ) ;
F_256 ( V_6 , V_9 , V_18 ,
V_27 ) ;
}
V_75:
F_3 ( V_58 L_295 ,
V_6 -> V_35 ) ;
}
static void
F_258 ( struct V_5 * V_6 , T_1 V_52 ,
T_4 V_27 )
{
struct V_147 * V_148 ;
struct V_156 * V_70 ;
struct V_47 * V_48 ;
unsigned long V_65 ;
F_18 ( & V_6 -> V_76 , V_65 ) ;
F_4 (raid_device, &ioc->raid_device_list, list) {
if ( V_48 -> V_52 == V_52 && V_48 -> V_70 ) {
V_70 = V_48 -> V_70 ;
if ( V_70 && V_70 -> V_150 ) {
V_148 = V_70 -> V_150 ;
V_148 -> V_375 = 0 ;
} else
V_148 = NULL ;
V_48 -> V_709 = 1 ;
F_21 ( & V_6 -> V_76 , V_65 ) ;
F_121 ( V_7 , V_48 -> V_70 ,
L_296 , V_27 ,
( unsigned long long ) V_48 -> V_52 ) ;
F_85 ( V_6 , V_48 ) ;
F_18 ( & V_6 -> V_76 , V_65 ) ;
if ( V_48 -> V_27 == V_27 ) {
F_21 ( & V_6 -> V_76 ,
V_65 ) ;
return;
}
F_3 ( V_7 L_293 ,
V_48 -> V_27 ) ;
V_48 -> V_27 = V_27 ;
if ( V_148 )
V_148 -> V_27 = V_27 ;
F_21 ( & V_6 -> V_76 , V_65 ) ;
return;
}
}
F_21 ( & V_6 -> V_76 , V_65 ) ;
}
static void
F_259 ( struct V_5 * V_6 )
{
T_15 V_711 ;
T_13 V_712 ;
T_14 V_213 ;
T_9 V_29 ;
T_4 V_30 ;
T_4 V_27 ;
T_6 V_713 ;
if ( ! V_6 -> V_714 )
return;
F_3 ( V_58 L_297 ,
V_6 -> V_35 ) ;
if ( F_43 ( & V_6 -> V_77 ) )
goto V_75;
V_27 = 0xFFFF ;
while ( ! ( F_83 ( V_6 , & V_29 ,
& V_711 , V_223 , V_27 ) ) ) {
V_30 = F_9 ( V_29 . V_38 ) &
V_39 ;
if ( V_30 != V_40 )
break;
V_27 = F_9 ( V_711 . V_221 ) ;
if ( F_73 ( V_6 , & V_29 ,
& V_712 , V_182 , V_27 ,
sizeof( T_13 ) ) )
continue;
if ( V_712 . V_191 == V_192 ||
V_712 . V_191 == V_193 ||
V_712 . V_191 == V_195 )
F_258 ( V_6 ,
F_6 ( V_711 . V_715 ) , V_27 ) ;
}
if ( ! V_6 -> V_163 ) {
V_713 = 0xFF ;
memset ( V_6 -> V_166 , 0 , V_6 -> V_716 ) ;
while ( ! ( F_81 ( V_6 , & V_29 ,
& V_213 , V_717 ,
V_713 ) ) ) {
V_30 = F_9 ( V_29 . V_38 ) &
V_39 ;
if ( V_30 != V_40 )
break;
V_713 = V_213 . V_220 ;
V_27 = F_9 ( V_213 . V_221 ) ;
F_144 ( V_27 , V_6 -> V_166 ) ;
}
}
V_75:
F_3 ( V_58 L_298
L_299 , V_6 -> V_35 ) ;
}
static void
F_260 ( struct V_5 * V_6 , T_1 V_9 ,
T_4 V_27 )
{
struct V_78 * V_79 ;
unsigned long V_65 ;
int V_92 ;
F_18 ( & V_6 -> V_80 , V_65 ) ;
F_4 (sas_expander, &ioc->sas_expander_list, list) {
if ( V_79 -> V_9 != V_9 )
continue;
V_79 -> V_709 = 1 ;
if ( V_79 -> V_27 == V_27 )
goto V_75;
F_3 ( V_7 L_300
L_301 ,
( unsigned long long ) V_79 -> V_9 ,
V_79 -> V_27 , V_27 ) ;
V_79 -> V_27 = V_27 ;
for ( V_92 = 0 ; V_92 < V_79 -> V_32 ; V_92 ++ )
V_79 -> V_262 [ V_92 ] . V_27 = V_27 ;
goto V_75;
}
V_75:
F_21 ( & V_6 -> V_80 , V_65 ) ;
}
static void
F_261 ( struct V_5 * V_6 )
{
T_38 V_597 ;
T_9 V_29 ;
T_4 V_30 ;
T_1 V_9 ;
T_4 V_27 ;
F_3 ( V_58 L_302 , V_6 -> V_35 ) ;
if ( F_43 ( & V_6 -> V_81 ) )
goto V_75;
V_27 = 0xFFFF ;
while ( ! ( F_216 ( V_6 , & V_29 , & V_597 ,
V_718 , V_27 ) ) ) {
V_30 = F_9 ( V_29 . V_38 ) &
V_39 ;
if ( V_30 != V_40 )
break;
V_27 = F_9 ( V_597 . V_221 ) ;
V_9 = F_6 ( V_597 . V_11 ) ;
F_3 ( V_7 L_303
L_304 , V_27 ,
( unsigned long long ) V_9 ) ;
F_260 ( V_6 , V_9 , V_27 ) ;
}
V_75:
F_3 ( V_58 L_305 , V_6 -> V_35 ) ;
}
static void
F_262 ( struct V_5 * V_6 )
{
struct V_45 * V_46 , * V_719 ;
struct V_78 * V_79 , * V_720 ;
struct V_47 * V_48 , * V_721 ;
struct V_722 V_723 ;
unsigned long V_65 ;
F_3 ( V_58 L_306 ,
V_6 -> V_35 ) ;
F_3 ( V_58 L_307 ,
V_6 -> V_35 ) ;
F_135 (sas_device, sas_device_next,
&ioc->sas_device_list, list) {
if ( ! V_46 -> V_709 )
F_227 ( V_6 ,
V_46 -> V_9 ) ;
else
V_46 -> V_709 = 0 ;
}
if ( V_6 -> V_714 ) {
F_3 ( V_58 L_308
L_309 , V_6 -> V_35 ) ;
F_135 (raid_device, raid_device_next,
&ioc->raid_device_list, list) {
if ( ! V_48 -> V_709 )
F_242 ( V_6 ,
V_48 -> V_27 ) ;
else
V_48 -> V_709 = 0 ;
}
}
F_3 ( V_58 L_310 ,
V_6 -> V_35 ) ;
F_18 ( & V_6 -> V_80 , V_65 ) ;
F_147 ( & V_723 ) ;
F_135 (sas_expander, sas_expander_next,
&ioc->sas_expander_list, list) {
if ( ! V_79 -> V_709 )
F_263 ( & V_79 -> V_67 , & V_723 ) ;
else
V_79 -> V_709 = 0 ;
}
F_21 ( & V_6 -> V_80 , V_65 ) ;
F_135 (sas_expander, sas_expander_next, &tmp_list,
list) {
F_19 ( & V_79 -> V_67 ) ;
F_221 ( V_6 , V_79 ) ;
}
F_3 ( V_58 L_311 ,
V_6 -> V_35 ) ;
F_137 ( V_6 ) ;
}
static void
F_264 ( struct V_5 * V_6 ,
struct V_78 * V_79 , T_4 V_27 )
{
T_39 V_598 ;
T_9 V_29 ;
int V_92 ;
for ( V_92 = 0 ; V_92 < V_79 -> V_32 ; V_92 ++ ) {
if ( ( F_217 ( V_6 , & V_29 ,
& V_598 , V_92 , V_27 ) ) ) {
F_3 ( V_34 L_2 ,
V_6 -> V_35 , __FILE__ , __LINE__ , V_36 ) ;
return;
}
F_207 ( V_6 , V_79 -> V_9 ,
F_9 ( V_598 . V_367 ) , V_92 ,
V_598 . V_579 >> 4 ) ;
}
}
static void
F_265 ( struct V_5 * V_6 )
{
T_38 V_597 ;
T_8 V_28 ;
T_15 V_711 ;
T_13 V_712 ;
T_14 V_213 ;
T_26 V_400 ;
T_9 V_29 ;
T_6 V_713 ;
T_4 V_30 ;
T_4 V_27 , V_599 ;
T_1 V_9 ;
struct V_45 * V_46 ;
struct V_78 * V_724 ;
static struct V_47 * V_48 ;
T_6 V_725 ;
unsigned long V_65 ;
F_3 ( V_58 L_312 , V_6 -> V_35 ) ;
F_205 ( V_6 ) ;
F_3 ( V_58 L_313 ,
V_6 -> V_35 ) ;
V_27 = 0xFFFF ;
while ( ! ( F_216 ( V_6 , & V_29 , & V_597 ,
V_718 , V_27 ) ) ) {
V_30 = F_9 ( V_29 . V_38 ) &
V_39 ;
if ( V_30 != V_40 ) {
F_3 ( V_58 L_314
L_315 ,
V_6 -> V_35 , V_30 ,
F_69 ( V_29 . V_324 ) ) ;
break;
}
V_27 = F_9 ( V_597 . V_221 ) ;
F_18 ( & V_6 -> V_80 , V_65 ) ;
V_724 = F_34 (
V_6 , F_6 ( V_597 . V_11 ) ) ;
F_21 ( & V_6 -> V_80 , V_65 ) ;
if ( V_724 )
F_264 ( V_6 , V_724 ,
V_27 ) ;
else {
F_3 ( V_58 L_316
L_317 ,
V_6 -> V_35 , V_27 , ( unsigned long long )
F_6 ( V_597 . V_11 ) ) ;
F_215 ( V_6 , V_27 ) ;
F_3 ( V_58 L_318
L_317 ,
V_6 -> V_35 , V_27 , ( unsigned long long )
F_6 ( V_597 . V_11 ) ) ;
}
}
F_3 ( V_58 L_319 ,
V_6 -> V_35 ) ;
if ( ! V_6 -> V_714 )
goto V_726;
F_3 ( V_58 L_320 , V_6 -> V_35 ) ;
V_713 = 0xFF ;
while ( ! ( F_81 ( V_6 , & V_29 ,
& V_213 , V_717 ,
V_713 ) ) ) {
V_30 = F_9 ( V_29 . V_38 ) &
V_39 ;
if ( V_30 != V_40 ) {
F_3 ( V_58 L_321
L_315 ,
V_6 -> V_35 , V_30 ,
F_69 ( V_29 . V_324 ) ) ;
break;
}
V_713 = V_213 . V_220 ;
V_27 = F_9 ( V_213 . V_221 ) ;
F_18 ( & V_6 -> V_66 , V_65 ) ;
V_46 = F_16 ( V_6 , V_27 ) ;
F_21 ( & V_6 -> V_66 , V_65 ) ;
if ( V_46 )
continue;
if ( F_12 ( V_6 , & V_29 ,
& V_28 , V_33 ,
V_27 ) != 0 )
continue;
V_30 = F_9 ( V_29 . V_38 ) &
V_39 ;
if ( V_30 != V_40 ) {
F_3 ( V_58 L_322
L_315 ,
V_6 -> V_35 , V_30 ,
F_69 ( V_29 . V_324 ) ) ;
break;
}
V_599 = F_9 ( V_28 . V_601 ) ;
if ( ! F_11 ( V_6 , V_599 ,
& V_9 ) ) {
F_3 ( V_58 L_323
L_324 ,
V_6 -> V_35 , V_27 , ( unsigned long long )
F_6 ( V_28 . V_11 ) ) ;
F_207 ( V_6 , V_9 ,
V_27 , V_28 . V_630 ,
V_581 ) ;
F_144 ( V_27 , V_6 -> V_166 ) ;
V_725 = 0 ;
while ( F_224 ( V_6 , V_27 , V_725 ++ ,
1 ) ) {
F_237 ( 1 ) ;
}
F_3 ( V_58 L_325
L_324 ,
V_6 -> V_35 , V_27 , ( unsigned long long )
F_6 ( V_28 . V_11 ) ) ;
}
}
F_3 ( V_58 L_326 ,
V_6 -> V_35 ) ;
F_3 ( V_58 L_327 , V_6 -> V_35 ) ;
V_27 = 0xFFFF ;
while ( ! ( F_83 ( V_6 , & V_29 ,
& V_711 , V_223 , V_27 ) ) ) {
V_30 = F_9 ( V_29 . V_38 ) &
V_39 ;
if ( V_30 != V_40 ) {
F_3 ( V_58 L_328
L_315 ,
V_6 -> V_35 , V_30 ,
F_69 ( V_29 . V_324 ) ) ;
break;
}
V_27 = F_9 ( V_711 . V_221 ) ;
F_18 ( & V_6 -> V_76 , V_65 ) ;
V_48 = F_30 ( V_6 ,
F_6 ( V_711 . V_715 ) ) ;
F_21 ( & V_6 -> V_76 , V_65 ) ;
if ( V_48 )
continue;
if ( F_73 ( V_6 , & V_29 ,
& V_712 , V_182 , V_27 ,
sizeof( T_13 ) ) )
continue;
V_30 = F_9 ( V_29 . V_38 ) &
V_39 ;
if ( V_30 != V_40 ) {
F_3 ( V_58 L_328
L_315 ,
V_6 -> V_35 , V_30 ,
F_69 ( V_29 . V_324 ) ) ;
break;
}
if ( V_712 . V_191 == V_192 ||
V_712 . V_191 == V_193 ||
V_712 . V_191 == V_195 ) {
memset ( & V_400 , 0 , sizeof( T_26 ) ) ;
V_400 . V_403 = V_679 ;
V_400 . V_406 = V_711 . V_221 ;
F_3 ( V_58 L_329
L_330 , V_6 -> V_35 ,
V_711 . V_221 ) ;
F_240 ( V_6 , & V_400 ) ;
F_3 ( V_58 L_331
L_330 , V_6 -> V_35 ,
V_711 . V_221 ) ;
}
}
F_3 ( V_58 L_332 ,
V_6 -> V_35 ) ;
V_726:
F_3 ( V_58 L_333 ,
V_6 -> V_35 ) ;
V_27 = 0xFFFF ;
while ( ! ( F_12 ( V_6 , & V_29 ,
& V_28 , V_710 ,
V_27 ) ) ) {
V_30 = F_9 ( V_29 . V_38 ) &
V_39 ;
if ( V_30 != V_40 ) {
F_3 ( V_58 L_334
L_335 ,
V_6 -> V_35 , V_30 ,
F_69 ( V_29 . V_324 ) ) ;
break;
}
V_27 = F_9 ( V_28 . V_221 ) ;
if ( ! ( F_36 (
F_69 ( V_28 . V_172 ) ) ) )
continue;
F_18 ( & V_6 -> V_66 , V_65 ) ;
V_46 = F_15 ( V_6 ,
F_6 ( V_28 . V_11 ) ) ;
F_21 ( & V_6 -> V_66 , V_65 ) ;
if ( V_46 )
continue;
V_599 = F_9 ( V_28 . V_601 ) ;
if ( ! F_11 ( V_6 , V_599 , & V_9 ) ) {
F_3 ( V_58 L_336
L_317 ,
V_6 -> V_35 , V_27 , ( unsigned long long )
F_6 ( V_28 . V_11 ) ) ;
F_207 ( V_6 , V_9 , V_27 ,
V_28 . V_630 , V_581 ) ;
V_725 = 0 ;
while ( F_224 ( V_6 , V_27 , V_725 ++ ,
0 ) ) {
F_237 ( 1 ) ;
}
F_3 ( V_58 L_337
L_317 ,
V_6 -> V_35 , V_27 , ( unsigned long long )
F_6 ( V_28 . V_11 ) ) ;
}
}
F_3 ( V_58 L_338 ,
V_6 -> V_35 ) ;
F_3 ( V_58 L_339 , V_6 -> V_35 ) ;
}
void
F_266 ( struct V_5 * V_6 , int V_727 )
{
switch ( V_727 ) {
case V_728 :
F_111 ( V_6 , F_3 ( V_58 L_52
L_340 , V_6 -> V_35 , V_36 ) ) ;
break;
case V_729 :
F_111 ( V_6 , F_3 ( V_58 L_52
L_341 , V_6 -> V_35 , V_36 ) ) ;
if ( V_6 -> V_605 . V_283 & V_288 ) {
V_6 -> V_605 . V_283 |= V_323 ;
F_157 ( V_6 , V_6 -> V_605 . V_88 ) ;
F_100 ( & V_6 -> V_605 . V_289 ) ;
}
if ( V_6 -> V_282 . V_283 & V_288 ) {
V_6 -> V_282 . V_283 |= V_323 ;
F_157 ( V_6 , V_6 -> V_282 . V_88 ) ;
F_100 ( & V_6 -> V_282 . V_289 ) ;
}
F_133 ( V_6 ) ;
F_166 ( V_6 ) ;
break;
case V_730 :
F_111 ( V_6 , F_3 ( V_58 L_52
L_342 , V_6 -> V_35 , V_36 ) ) ;
F_205 ( V_6 ) ;
F_255 ( V_6 ) ;
F_257 ( V_6 ) ;
F_259 ( V_6 ) ;
F_261 ( V_6 ) ;
if ( ( ! V_6 -> V_49 ) && ! ( V_675 > 0 &&
! V_6 -> V_31 . V_32 ) ) {
F_255 ( V_6 ) ;
F_257 ( V_6 ) ;
F_259 ( V_6 ) ;
F_261 ( V_6 ) ;
F_131 ( V_6 ) ;
}
break;
}
}
static void
V_346 ( struct V_731 * V_732 )
{
struct V_340 * V_341 = F_267 ( V_732 ,
struct V_340 , V_345 . V_732 ) ;
struct V_5 * V_6 = V_341 -> V_6 ;
if ( V_6 -> V_305 ||
V_6 -> V_306 ) {
F_130 ( V_6 , V_341 ) ;
return;
}
switch ( V_341 -> V_348 ) {
case V_349 :
while ( F_268 ( V_6 -> V_142 ) || V_6 -> V_304 )
F_237 ( 1 ) ;
F_262 ( V_6 ) ;
F_265 ( V_6 ) ;
break;
case V_350 :
V_6 -> V_733 = 0 ;
if ( V_734 [ 0 ] != - 1 && V_734 [ 1 ] != - 1 )
F_269 ( V_6 , V_734 [ 0 ] ,
V_734 [ 1 ] ) ;
F_23 ( V_6 , F_3 ( V_58 L_343
L_344 , V_6 -> V_35 ) ) ;
break;
case V_544 :
F_192 ( V_6 , V_341 -> V_545 ) ;
break;
case V_395 :
F_229 ( V_6 , V_341 ) ;
break;
case V_554 :
F_231 ( V_6 ,
V_341 ) ;
break;
case V_735 :
F_236 ( V_6 ,
V_341 ) ;
break;
case V_736 :
F_234 ( V_6 ,
V_341 ) ;
break;
case V_737 :
F_233 ( V_6 ,
V_341 ) ;
break;
case V_738 :
F_250 ( V_6 , V_341 ) ;
break;
case V_739 :
F_251 ( V_6 , V_341 ) ;
break;
case V_740 :
F_252 ( V_6 , V_341 ) ;
break;
case V_741 :
F_254 ( V_6 , V_341 ) ;
break;
}
F_130 ( V_6 , V_341 ) ;
}
void
F_270 ( struct V_5 * V_6 , T_6 V_280 ,
T_10 V_281 )
{
struct V_340 * V_341 ;
T_31 * V_29 ;
T_4 V_348 ;
T_4 V_214 ;
if ( V_6 -> V_305 || V_6 -> V_306 )
return;
V_29 = F_99 ( V_6 , V_281 ) ;
if ( F_152 ( ! V_29 ) ) {
F_3 ( V_34 L_113 ,
V_6 -> V_35 , __FILE__ , __LINE__ , V_36 ) ;
return;
}
V_348 = F_9 ( V_29 -> V_553 ) ;
switch ( V_348 ) {
case V_736 :
{
T_42 * V_742 =
( T_42 * )
V_29 -> V_551 ;
if ( V_742 -> V_743 !=
V_744 )
return;
if ( V_6 -> V_672 ) {
V_6 -> V_671 ++ ;
return;
} else
V_6 -> V_672 = 1 ;
break;
}
case V_395 :
F_158 ( V_6 ,
( T_22 * )
V_29 -> V_551 ) ;
break;
case V_738 :
F_162 ( V_6 ,
( T_25 * )
V_29 -> V_551 ) ;
break;
case V_739 :
F_165 ( V_6 ,
( T_27 * )
V_29 -> V_551 ) ;
break;
case V_745 :
{
T_46 * V_746 ;
T_47 * V_747 ;
if ( ! V_6 -> V_163 )
break;
V_746 = ( T_46 * )
V_29 -> V_551 ;
V_747 = ( T_47 * ) V_746 -> V_748 ;
if ( F_9 ( V_746 -> V_749 )
!= V_750 )
break;
switch ( F_69 ( * V_747 ) ) {
case V_751 :
F_3 ( V_99 L_345
L_346
L_347
L_348 , V_6 -> V_35 ) ;
break;
case V_752 :
F_3 ( V_99 L_345
L_349
L_350
L_351 , V_6 -> V_35 ) ;
break;
case V_753 :
F_3 ( V_34 L_352
L_353
L_354
L_355
L_351 , V_6 -> V_35 ) ;
break;
case V_754 :
F_3 ( V_34 L_352
L_356
L_357
L_358 ,
V_6 -> V_35 ) ;
break;
}
break;
}
case V_554 :
case V_741 :
case V_735 :
case V_737 :
case V_740 :
break;
default:
return;
}
V_214 = F_9 ( V_29 -> V_555 ) * 4 ;
V_341 = F_62 ( sizeof( * V_341 ) + V_214 , V_347 ) ;
if ( ! V_341 ) {
F_3 ( V_34 L_2 ,
V_6 -> V_35 , __FILE__ , __LINE__ , V_36 ) ;
return;
}
memcpy ( V_341 -> V_362 , V_29 -> V_551 , V_214 ) ;
V_341 -> V_6 = V_6 ;
V_341 -> V_482 = V_29 -> V_482 ;
V_341 -> V_483 = V_29 -> V_483 ;
V_341 -> V_348 = V_348 ;
F_127 ( V_6 , V_341 ) ;
return;
}
static void
F_221 ( struct V_5 * V_6 ,
struct V_78 * V_79 )
{
struct V_353 * V_354 , * V_100 ;
F_135 (mpt2sas_port, next,
&sas_expander->sas_port_list, port_list) {
if ( V_6 -> V_304 )
return;
if ( V_354 -> V_356 . V_357 ==
V_358 )
F_227 ( V_6 ,
V_354 -> V_356 . V_9 ) ;
else if ( V_354 -> V_356 . V_357 ==
V_360 ||
V_354 -> V_356 . V_357 ==
V_361 )
F_220 ( V_6 ,
V_354 -> V_356 . V_9 ) ;
}
F_26 ( V_6 , V_79 -> V_9 ,
V_79 -> V_69 ) ;
F_3 ( V_58 L_359
L_8 , V_6 -> V_35 ,
V_79 -> V_27 , ( unsigned long long )
V_79 -> V_9 ) ;
F_20 ( V_79 -> V_262 ) ;
F_20 ( V_79 ) ;
}
static void
F_271 ( struct V_5 * V_6 )
{
T_48 * V_103 ;
T_49 * V_29 ;
T_4 V_88 ;
if ( ! V_6 -> V_714 )
return;
F_105 ( & V_6 -> V_605 . V_301 ) ;
if ( V_6 -> V_605 . V_283 != V_284 ) {
F_3 ( V_34 L_360 ,
V_6 -> V_35 , V_36 ) ;
goto V_75;
}
V_6 -> V_605 . V_283 = V_288 ;
V_88 = F_155 ( V_6 , V_6 -> V_755 ) ;
if ( ! V_88 ) {
F_3 ( V_34 L_68 ,
V_6 -> V_35 , V_36 ) ;
V_6 -> V_605 . V_283 = V_284 ;
goto V_75;
}
V_103 = F_48 ( V_6 , V_88 ) ;
V_6 -> V_605 . V_88 = V_88 ;
memset ( V_103 , 0 , sizeof( T_48 ) ) ;
V_103 -> V_316 = V_756 ;
V_103 -> V_534 = V_757 ;
if ( ! V_6 -> V_261 )
F_3 ( V_58 L_361 , V_6 -> V_35 ) ;
F_114 ( & V_6 -> V_605 . V_289 ) ;
F_156 ( V_6 , V_88 ) ;
F_116 ( & V_6 -> V_605 . V_289 , 10 * V_322 ) ;
if ( ! ( V_6 -> V_605 . V_283 & V_285 ) ) {
F_3 ( V_34 L_71 ,
V_6 -> V_35 , V_36 ) ;
goto V_75;
}
if ( V_6 -> V_605 . V_283 & V_287 ) {
V_29 = V_6 -> V_605 . V_281 ;
if ( ! V_6 -> V_261 )
F_3 ( V_58 L_362
L_315 ,
V_6 -> V_35 , F_9 ( V_29 -> V_38 ) ,
F_69 ( V_29 -> V_324 ) ) ;
}
V_75:
V_6 -> V_605 . V_283 = V_284 ;
F_118 ( & V_6 -> V_605 . V_301 ) ;
}
static void
F_272 ( struct V_758 * V_548 )
{
struct V_141 * V_142 = F_273 ( V_548 ) ;
struct V_5 * V_6 = F_58 ( V_142 ) ;
struct V_759 * V_760 ;
unsigned long V_65 ;
V_6 -> V_305 = 1 ;
F_133 ( V_6 ) ;
F_18 ( & V_6 -> V_343 , V_65 ) ;
V_760 = V_6 -> V_342 ;
V_6 -> V_342 = NULL ;
F_21 ( & V_6 -> V_343 , V_65 ) ;
if ( V_760 )
F_274 ( V_760 ) ;
F_271 ( V_6 ) ;
F_275 ( V_6 ) ;
}
static void
F_276 ( struct V_758 * V_548 )
{
struct V_141 * V_142 = F_273 ( V_548 ) ;
struct V_5 * V_6 = F_58 ( V_142 ) ;
struct V_353 * V_354 , * V_761 ;
struct V_47 * V_48 , * V_100 ;
struct V_147 * V_148 ;
struct V_759 * V_760 ;
unsigned long V_65 ;
V_6 -> V_305 = 1 ;
F_133 ( V_6 ) ;
F_18 ( & V_6 -> V_343 , V_65 ) ;
V_760 = V_6 -> V_342 ;
V_6 -> V_342 = NULL ;
F_21 ( & V_6 -> V_343 , V_65 ) ;
if ( V_760 )
F_274 ( V_760 ) ;
F_271 ( V_6 ) ;
F_135 (raid_device, next, &ioc->raid_device_list,
list) {
if ( V_48 -> V_70 ) {
V_148 =
V_48 -> V_70 -> V_150 ;
V_148 -> V_375 = 1 ;
F_243 ( & V_48 -> V_70 -> V_157 ) ;
}
F_3 ( V_58 L_266
L_201 , V_6 -> V_35 , V_48 -> V_27 ,
( unsigned long long ) V_48 -> V_52 ) ;
F_32 ( V_6 , V_48 ) ;
}
F_135 (mpt2sas_port, next_port,
&ioc->sas_hba.sas_port_list, port_list) {
if ( V_354 -> V_356 . V_357 ==
V_358 )
F_227 ( V_6 ,
V_354 -> V_356 . V_9 ) ;
else if ( V_354 -> V_356 . V_357 ==
V_360 ||
V_354 -> V_356 . V_357 ==
V_361 )
F_220 ( V_6 ,
V_354 -> V_356 . V_9 ) ;
}
if ( V_6 -> V_31 . V_32 ) {
F_20 ( V_6 -> V_31 . V_262 ) ;
V_6 -> V_31 . V_262 = NULL ;
V_6 -> V_31 . V_32 = 0 ;
}
F_277 ( V_142 ) ;
F_278 ( V_142 ) ;
F_275 ( V_6 ) ;
F_19 ( & V_6 -> V_67 ) ;
F_279 ( V_142 ) ;
}
static void
F_280 ( struct V_5 * V_6 )
{
T_6 V_44 ;
void * V_43 ;
struct V_45 * V_46 ;
struct V_47 * V_48 ;
T_4 V_27 ;
T_1 V_69 ;
T_1 V_9 ;
unsigned long V_65 ;
int V_20 ;
if ( ! V_6 -> V_50 . V_51 )
return;
V_43 = NULL ;
V_44 = 0 ;
if ( V_6 -> V_53 . V_43 ) {
V_43 = V_6 -> V_53 . V_43 ;
V_44 = V_6 -> V_53 . V_44 ;
} else if ( V_6 -> V_59 . V_43 ) {
V_43 = V_6 -> V_59 . V_43 ;
V_44 = V_6 -> V_59 . V_44 ;
} else if ( V_6 -> V_62 . V_43 ) {
V_43 = V_6 -> V_62 . V_43 ;
V_44 = V_6 -> V_62 . V_44 ;
}
if ( ! V_43 )
return;
if ( V_44 ) {
V_48 = V_43 ;
V_20 = F_241 ( V_6 -> V_142 , V_162 ,
V_48 -> V_72 , 0 ) ;
if ( V_20 )
F_32 ( V_6 , V_48 ) ;
} else {
F_18 ( & V_6 -> V_66 , V_65 ) ;
V_46 = V_43 ;
V_27 = V_46 -> V_27 ;
V_69 = V_46 -> V_69 ;
V_9 = V_46 -> V_9 ;
F_263 ( & V_46 -> V_67 , & V_6 -> V_68 ) ;
F_21 ( & V_6 -> V_66 , V_65 ) ;
if ( V_6 -> V_632 )
return;
if ( ! F_25 ( V_6 , V_46 -> V_27 ,
V_46 -> V_69 ) ) {
F_17 ( V_6 , V_46 ) ;
} else if ( ! V_46 -> V_70 ) {
if ( ! V_6 -> V_49 ) {
F_26 ( V_6 ,
V_9 ,
V_69 ) ;
F_17 ( V_6 , V_46 ) ;
}
}
}
}
static void
F_281 ( struct V_5 * V_6 )
{
struct V_47 * V_48 , * V_762 ;
int V_20 ;
F_135 (raid_device, raid_next,
&ioc->raid_device_list, list) {
if ( V_48 -> V_70 )
continue;
V_20 = F_241 ( V_6 -> V_142 , V_162 ,
V_48 -> V_72 , 0 ) ;
if ( V_20 )
F_32 ( V_6 , V_48 ) ;
}
}
static void
F_282 ( struct V_5 * V_6 )
{
struct V_45 * V_46 , * V_100 ;
unsigned long V_65 ;
F_135 (sas_device, next, &ioc->sas_device_init_list,
list) {
if ( V_6 -> V_632 )
continue;
if ( ! F_25 ( V_6 , V_46 -> V_27 ,
V_46 -> V_69 ) ) {
F_19 ( & V_46 -> V_67 ) ;
F_20 ( V_46 ) ;
continue;
} else if ( ! V_46 -> V_70 ) {
if ( ! V_6 -> V_49 ) {
F_26 ( V_6 ,
V_46 -> V_9 ,
V_46 -> V_69 ) ;
F_19 ( & V_46 -> V_67 ) ;
F_20 ( V_46 ) ;
continue;
}
}
F_18 ( & V_6 -> V_66 , V_65 ) ;
F_263 ( & V_46 -> V_67 , & V_6 -> V_68 ) ;
F_21 ( & V_6 -> V_66 , V_65 ) ;
}
}
static void
F_283 ( struct V_5 * V_6 )
{
T_4 V_763 ;
if ( ! ( V_6 -> V_245 . V_764 & V_765 ) )
return;
F_280 ( V_6 ) ;
if ( V_6 -> V_714 ) {
V_763 =
F_9 ( V_6 -> V_766 . V_767 ) &
V_768 ;
if ( V_763 ==
V_769 ) {
F_281 ( V_6 ) ;
F_282 ( V_6 ) ;
} else {
F_282 ( V_6 ) ;
F_281 ( V_6 ) ;
}
} else
F_282 ( V_6 ) ;
}
static void
F_284 ( struct V_141 * V_142 )
{
struct V_5 * V_6 = F_58 ( V_142 ) ;
int V_20 ;
if ( V_770 != - 1 && V_770 != 0 )
F_285 ( V_6 , V_770 ) ;
if ( V_675 > 0 )
return;
V_6 -> V_733 = 1 ;
V_20 = F_286 ( V_6 ) ;
if ( V_20 != 0 )
F_3 ( V_58 L_363 , V_6 -> V_35 ) ;
}
static int
F_287 ( struct V_141 * V_142 , unsigned long time )
{
struct V_5 * V_6 = F_58 ( V_142 ) ;
if ( V_675 > 0 ) {
V_6 -> V_49 = 0 ;
V_6 -> V_631 = 0 ;
return 1 ;
}
if ( time >= ( 300 * V_322 ) ) {
V_6 -> V_771 . V_283 = V_284 ;
F_3 ( V_58 L_364
L_365 , V_6 -> V_35 ) ;
V_6 -> V_49 = 0 ;
return 1 ;
}
if ( V_6 -> V_733 )
return 0 ;
if ( V_6 -> V_772 ) {
F_3 ( V_58 L_366
L_367 , V_6 -> V_35 , V_6 -> V_772 ) ;
V_6 -> V_49 = 0 ;
V_6 -> V_631 = 0 ;
V_6 -> V_305 = 1 ;
return 1 ;
}
F_3 ( V_58 L_368 , V_6 -> V_35 ) ;
V_6 -> V_771 . V_283 = V_284 ;
if ( V_6 -> V_631 ) {
V_6 -> V_631 = 0 ;
F_283 ( V_6 ) ;
}
F_288 ( V_6 ) ;
V_6 -> V_49 = 0 ;
return 1 ;
}
static int
F_289 ( struct V_758 * V_548 , const struct V_773 * V_72 )
{
struct V_5 * V_6 ;
struct V_141 * V_142 ;
int V_774 ;
V_142 = F_290 ( & V_775 ,
sizeof( struct V_5 ) ) ;
if ( ! V_142 )
return - V_776 ;
V_6 = F_58 ( V_142 ) ;
memset ( V_6 , 0 , sizeof( struct V_5 ) ) ;
F_147 ( & V_6 -> V_67 ) ;
F_24 ( & V_6 -> V_67 , & V_777 ) ;
V_6 -> V_142 = V_142 ;
V_6 -> V_72 = V_778 ++ ;
sprintf ( V_6 -> V_35 , L_369 , V_779 , V_6 -> V_72 ) ;
V_6 -> V_548 = V_548 ;
if ( V_72 -> V_43 == V_780 ) {
V_6 -> V_163 = 1 ;
V_6 -> V_261 = 1 ;
} else
V_6 -> V_232 = V_233 ;
V_6 -> V_466 = V_466 ;
V_6 -> V_314 = V_314 ;
V_6 -> V_781 = V_781 ;
V_6 -> V_782 = V_782 ;
V_6 -> V_783 = V_783 ;
V_6 -> V_784 = V_784 ;
V_6 -> V_755 = V_755 ;
V_6 -> V_785 = V_785 ;
V_6 -> V_376 = V_376 ;
V_6 -> V_378 = V_378 ;
V_6 -> V_382 = V_382 ;
V_6 -> V_8 = V_8 ;
V_6 -> V_786 = & F_166 ;
F_291 ( & V_6 -> V_787 ) ;
F_292 ( & V_6 -> V_788 ) ;
F_292 ( & V_6 -> V_91 ) ;
F_292 ( & V_6 -> V_66 ) ;
F_292 ( & V_6 -> V_80 ) ;
F_292 ( & V_6 -> V_343 ) ;
F_292 ( & V_6 -> V_76 ) ;
F_147 ( & V_6 -> V_68 ) ;
F_147 ( & V_6 -> V_71 ) ;
F_147 ( & V_6 -> V_81 ) ;
F_147 ( & V_6 -> V_344 ) ;
F_147 ( & V_6 -> V_77 ) ;
F_147 ( & V_6 -> V_31 . V_604 ) ;
F_147 ( & V_6 -> V_377 ) ;
F_147 ( & V_6 -> V_379 ) ;
F_147 ( & V_6 -> V_789 ) ;
V_142 -> V_790 = 32 ;
V_142 -> V_791 = V_791 ;
V_142 -> V_792 = V_793 ;
V_142 -> V_794 = V_6 -> V_72 ;
if ( V_795 != 0xFFFF ) {
if ( V_795 < 64 ) {
V_142 -> V_795 = 64 ;
F_3 ( V_99 L_370
L_371
L_372 , V_6 -> V_35 , V_795 ) ;
} else if ( V_795 > 32767 ) {
V_142 -> V_795 = 32767 ;
F_3 ( V_99 L_370
L_373
L_374 , V_6 -> V_35 ,
V_795 ) ;
} else {
V_142 -> V_795 = V_795 & 0xFFFE ;
F_3 ( V_58 L_375
L_376 , V_6 -> V_35 , V_142 -> V_795 ) ;
}
}
if ( V_796 )
F_293 ( V_142 , V_796 ) ;
else
F_293 ( V_142 , V_797
| V_798
| V_799 ) ;
F_294 ( V_142 , V_800 ) ;
snprintf ( V_6 -> V_801 , sizeof( V_6 -> V_801 ) ,
L_377 , V_6 -> V_72 ) ;
V_6 -> V_342 = F_295 (
V_6 -> V_801 ) ;
if ( ! V_6 -> V_342 ) {
F_3 ( V_34 L_2 ,
V_6 -> V_35 , __FILE__ , __LINE__ , V_36 ) ;
V_774 = - V_776 ;
goto V_802;
}
V_6 -> V_49 = 1 ;
if ( ( F_296 ( V_6 ) ) ) {
F_3 ( V_34 L_2 ,
V_6 -> V_35 , __FILE__ , __LINE__ , V_36 ) ;
V_774 = - V_776 ;
goto V_803;
}
if ( V_6 -> V_163 ) {
if ( V_6 -> V_232 == V_233 )
V_6 -> V_632 = 0 ;
else if ( V_6 -> V_232 == V_804 )
V_6 -> V_632 = 1 ;
else {
if ( F_84 ( V_6 ) )
V_6 -> V_632 = 1 ;
else
V_6 -> V_632 = 0 ;
}
} else
V_6 -> V_632 = 0 ;
V_774 = F_297 ( V_142 , & V_548 -> V_157 ) ;
if ( V_774 ) {
F_3 ( V_34 L_2 ,
V_6 -> V_35 , __FILE__ , __LINE__ , V_36 ) ;
goto V_805;
}
F_298 ( V_142 ) ;
return 0 ;
V_805:
F_275 ( V_6 ) ;
V_803:
F_274 ( V_6 -> V_342 ) ;
V_802:
F_19 ( & V_6 -> V_67 ) ;
F_279 ( V_142 ) ;
return V_774 ;
}
static int
F_299 ( struct V_758 * V_548 , T_50 V_188 )
{
struct V_141 * V_142 = F_273 ( V_548 ) ;
struct V_5 * V_6 = F_58 ( V_142 ) ;
T_51 V_806 ;
F_300 ( V_6 ) ;
F_301 ( V_142 ) ;
F_271 ( V_6 ) ;
V_806 = F_302 ( V_548 , V_188 ) ;
F_3 ( V_58 L_378
L_379 , V_6 -> V_35 , V_548 ,
F_303 ( V_548 ) , V_806 ) ;
F_304 ( V_6 ) ;
F_305 ( V_548 ) ;
F_306 ( V_548 , V_806 ) ;
return 0 ;
}
static int
F_307 ( struct V_758 * V_548 )
{
struct V_141 * V_142 = F_273 ( V_548 ) ;
struct V_5 * V_6 = F_58 ( V_142 ) ;
T_51 V_806 = V_548 -> V_807 ;
int V_74 ;
F_3 ( V_58 L_380
L_379 , V_6 -> V_35 , V_548 ,
F_303 ( V_548 ) , V_806 ) ;
F_306 ( V_548 , V_808 ) ;
F_308 ( V_548 , V_808 , 0 ) ;
F_309 ( V_548 ) ;
V_6 -> V_548 = V_548 ;
V_74 = F_310 ( V_6 ) ;
if ( V_74 )
return V_74 ;
F_108 ( V_6 , V_308 , V_809 ) ;
F_311 ( V_142 ) ;
F_288 ( V_6 ) ;
return 0 ;
}
static T_52
F_312 ( struct V_758 * V_548 , T_53 V_188 )
{
struct V_141 * V_142 = F_273 ( V_548 ) ;
struct V_5 * V_6 = F_58 ( V_142 ) ;
F_3 ( V_58 L_381 ,
V_6 -> V_35 , V_188 ) ;
switch ( V_188 ) {
case V_810 :
return V_811 ;
case V_812 :
V_6 -> V_306 = 1 ;
F_301 ( V_6 -> V_142 ) ;
F_300 ( V_6 ) ;
F_304 ( V_6 ) ;
return V_813 ;
case V_814 :
V_6 -> V_306 = 1 ;
F_300 ( V_6 ) ;
F_166 ( V_6 ) ;
return V_815 ;
}
return V_813 ;
}
static T_52
F_313 ( struct V_758 * V_548 )
{
struct V_141 * V_142 = F_273 ( V_548 ) ;
struct V_5 * V_6 = F_58 ( V_142 ) ;
int V_20 ;
F_3 ( V_58 L_382 ,
V_6 -> V_35 ) ;
V_6 -> V_306 = 0 ;
V_6 -> V_548 = V_548 ;
F_309 ( V_548 ) ;
V_20 = F_310 ( V_6 ) ;
if ( V_20 )
return V_815 ;
V_20 = F_108 ( V_6 , V_308 ,
V_309 ) ;
F_3 ( V_99 L_383 , V_6 -> V_35 ,
( V_20 == 0 ) ? L_128 : L_384 ) ;
if ( ! V_20 )
return V_816 ;
else
return V_815 ;
}
static void
F_314 ( struct V_758 * V_548 )
{
struct V_141 * V_142 = F_273 ( V_548 ) ;
struct V_5 * V_6 = F_58 ( V_142 ) ;
F_3 ( V_58 L_385 , V_6 -> V_35 ) ;
F_315 ( V_548 ) ;
F_288 ( V_6 ) ;
F_311 ( V_6 -> V_142 ) ;
}
static T_52
F_316 ( struct V_758 * V_548 )
{
struct V_141 * V_142 = F_273 ( V_548 ) ;
struct V_5 * V_6 = F_58 ( V_142 ) ;
F_3 ( V_58 L_386 ,
V_6 -> V_35 ) ;
return V_813 ;
}
static int T_54
F_317 ( void )
{
int error ;
V_778 = 0 ;
F_3 ( V_7 L_387 , V_779 ,
V_817 ) ;
V_793 =
F_318 ( & V_818 ) ;
if ( ! V_793 )
return - V_776 ;
V_185 = F_319 ( & V_819 ) ;
if ( ! V_185 ) {
F_320 ( V_793 ) ;
return - V_776 ;
}
F_321 () ;
V_466 = F_322 ( F_199 ) ;
V_314 = F_322 ( F_97 ) ;
V_782 = F_322 ( V_820 ) ;
V_783 = F_322 (
V_821 ) ;
V_784 = F_322 (
V_822 ) ;
V_755 = F_322 ( F_219 ) ;
V_785 = F_322 (
V_823 ) ;
V_781 = F_322 ( V_824 ) ;
V_376 = F_322 (
F_154 ) ;
V_378 = F_322 (
F_151 ) ;
V_382 = F_322 (
F_148 ) ;
F_323 () ;
error = F_324 ( & V_825 ) ;
if ( error ) {
F_325 ( V_185 ) ;
F_320 ( V_793 ) ;
}
return error ;
}
static void T_55
F_326 ( void )
{
F_3 ( V_7 L_388 ,
V_817 ) ;
F_327 ( & V_825 ) ;
F_328 () ;
F_329 ( V_466 ) ;
F_329 ( V_314 ) ;
F_329 ( V_782 ) ;
F_329 ( V_783 ) ;
F_329 ( V_784 ) ;
F_329 ( V_755 ) ;
F_329 ( V_785 ) ;
F_329 ( V_781 ) ;
F_329 ( V_376 ) ;
F_329 ( V_378 ) ;
F_329 ( V_382 ) ;
F_325 ( V_185 ) ;
F_320 ( V_793 ) ;
}
