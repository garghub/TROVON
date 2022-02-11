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
if ( V_6 -> V_49 ) {
F_3 ( V_58 L_93 ,
V_6 -> V_35 ) ;
V_74 = V_302 ;
goto V_75;
}
V_339 = F_108 ( V_6 , V_308 ,
V_309 ) ;
V_74 = ( V_339 < 0 ) ? V_302 : V_310 ;
V_75:
F_3 ( V_58 L_94 ,
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
F_23 ( V_6 , F_51 ( V_7 , V_139 , L_95
L_96 ,
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
V_58 L_97
L_98 , V_6 -> V_35 ,
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
F_23 ( V_6 , F_51 ( V_7 , V_139 , L_99
L_96 ,
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
V_58 L_100
L_96 , V_6 -> V_35 , V_27 ) ) ;
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
F_23 ( V_6 , F_3 ( V_58 L_101
L_102 , V_36 , V_6 -> V_35 , V_27 ) ) ;
return;
} else if ( V_6 -> V_306 ) {
F_23 ( V_6 , F_3 ( V_58 L_103
L_104 , V_36 , V_6 -> V_35 ,
V_27 ) ) ;
return;
}
V_297 = F_106 ( V_6 , 1 ) ;
if ( V_297 != V_374 ) {
F_23 ( V_6 , F_3 ( V_58 L_105
L_106 , V_36 , V_6 -> V_35 ,
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
F_23 ( V_6 , F_3 ( V_58 L_107
L_108 , V_6 -> V_35 , V_27 ,
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
L_109 ,
V_6 -> V_35 , V_27 ) ) ;
return;
}
F_23 ( V_6 , F_3 ( V_58 L_110
L_111 , V_6 -> V_35 , V_27 , V_88 ,
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
L_112
L_113 ,
V_6 -> V_35 , F_9 ( V_29 -> V_221 ) , V_88 ,
F_9 ( V_29 -> V_38 ) ,
F_69 ( V_29 -> V_324 ) ) ) ;
} else {
F_3 ( V_34 L_114 ,
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
F_23 ( V_6 , F_3 ( V_58 L_115
L_116 , V_36 , V_6 -> V_35 ) ) ;
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
L_109 ,
V_6 -> V_35 , V_27 ) ) ;
return;
}
F_23 ( V_6 , F_3 ( V_58 L_110
L_111 , V_6 -> V_35 , V_27 , V_88 ,
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
F_23 ( V_6 , F_3 ( V_58 L_115
L_116 , V_36 , V_6 -> V_35 ) ) ;
return 1 ;
}
if ( F_152 ( ! V_29 ) ) {
F_3 ( V_34 L_114 ,
V_6 -> V_35 , __FILE__ , __LINE__ , V_36 ) ;
return 1 ;
}
V_380 = F_48 ( V_6 , V_88 ) ;
V_27 = F_9 ( V_380 -> V_221 ) ;
if ( V_27 != F_9 ( V_29 -> V_221 ) ) {
F_23 ( V_6 , F_3 ( L_117
L_118 , V_27 ,
F_9 ( V_29 -> V_221 ) , V_88 ) ) ;
return 0 ;
}
F_23 ( V_6 , F_3 ( V_58
L_119
L_120 , V_6 -> V_35 ,
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
F_23 ( V_6 , F_3 ( V_58 L_101
L_121 , V_36 , V_6 -> V_35 ) ) ;
return 1 ;
} else if ( V_6 -> V_306 ) {
F_23 ( V_6 , F_3 ( V_58 L_103
L_122 , V_36 , V_6 -> V_35 ) ) ;
return 1 ;
}
V_297 = F_106 ( V_6 , 1 ) ;
if ( V_297 != V_374 ) {
F_23 ( V_6 , F_3 ( V_58 L_105
L_123 , V_36 , V_6 -> V_35 ) ) ;
return 1 ;
}
if ( F_152 ( ! V_29 ) ) {
F_3 ( V_34 L_114 ,
V_6 -> V_35 , __FILE__ , __LINE__ , V_36 ) ;
return 1 ;
}
V_380 = F_48 ( V_6 , V_88 ) ;
V_27 = F_9 ( V_380 -> V_221 ) ;
if ( V_27 != F_9 ( V_29 -> V_221 ) ) {
F_23 ( V_6 , F_3 ( V_58 L_117
L_118 , V_6 -> V_35 , V_27 ,
F_9 ( V_29 -> V_221 ) , V_88 ) ) ;
return 0 ;
}
F_23 ( V_6 , F_3 ( V_58
L_119
L_120 , V_6 -> V_35 ,
V_27 , V_88 , F_9 ( V_29 -> V_38 ) ,
F_69 ( V_29 -> V_324 ) ,
F_69 ( V_29 -> V_325 ) ) ) ;
V_381 = F_155 ( V_6 , V_6 -> V_382 ) ;
if ( ! V_381 ) {
F_3 ( V_34 L_68 ,
V_6 -> V_35 , V_36 ) ;
return 1 ;
}
F_23 ( V_6 , F_3 ( V_58 L_124
L_111 , V_6 -> V_35 , V_27 , V_381 ,
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
L_125 , V_6 -> V_35 ) ) ;
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
L_126
L_127 , V_6 -> V_35 , V_27 ,
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
L_109 , V_6 -> V_35 ,
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
F_166 ( struct V_5 * V_6 ,
T_28 * V_362 )
{
if ( V_6 -> V_412 >= V_362 -> V_413 ) {
F_3 ( V_34 L_128
L_129 , V_6 -> V_35 ,
( ( F_9 ( V_362 -> V_414 ) & 0x1 ) == 1 ) ? L_130 : L_131 ,
( ( F_9 ( V_362 -> V_414 ) & 0x2 ) == 2 ) ? L_132 : L_131 ,
( ( F_9 ( V_362 -> V_414 ) & 0x4 ) == 4 ) ? L_133 : L_131 ,
( ( F_9 ( V_362 -> V_414 ) & 0x8 ) == 8 ) ? L_134 : L_131 ,
V_362 -> V_413 ) ;
F_3 ( V_34 L_135 ,
V_6 -> V_35 , V_362 -> V_415 ) ;
}
}
static void
F_167 ( struct V_5 * V_6 )
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
F_168 ( V_90 ) ;
if ( V_6 -> V_306 )
V_90 -> V_335 = V_336 << 16 ;
else
V_90 -> V_335 = V_338 << 16 ;
V_90 -> V_337 ( V_90 ) ;
}
F_111 ( V_6 , F_3 ( V_58 L_136 ,
V_6 -> V_35 , V_226 ) ) ;
}
static void
F_169 ( struct V_87 * V_90 , T_11 * V_103 )
{
T_4 V_416 ;
unsigned char V_417 = F_170 ( V_90 ) ;
unsigned char V_418 = F_171 ( V_90 ) ;
if ( V_418 == V_419 || V_417 == V_420 )
return;
if ( V_417 == V_421 )
V_416 = V_422 ;
else if ( V_417 == V_423 )
V_416 = V_424 ;
else
return;
switch ( V_418 ) {
case V_425 :
case V_426 :
V_416 |= V_427 |
V_428 |
V_429 ;
V_103 -> V_430 . V_431 . V_432 =
F_172 ( F_173 ( V_90 ) ) ;
break;
case V_433 :
V_416 |= V_429 ;
break;
}
V_103 -> V_434 = F_174 ( V_90 -> V_43 -> V_435 ) ;
V_103 -> V_436 = F_112 ( V_416 ) ;
}
static void
F_175 ( struct V_87 * V_90 , T_4 V_30 )
{
T_6 V_437 ;
switch ( V_30 ) {
case V_438 :
V_437 = 0x01 ;
break;
case V_439 :
V_437 = 0x02 ;
break;
case V_440 :
V_437 = 0x03 ;
break;
default:
V_437 = 0x00 ;
break;
}
F_176 ( 0 , V_90 -> V_441 , V_442 , 0x10 , V_437 ) ;
V_90 -> V_335 = V_443 << 24 | ( V_444 << 16 ) |
V_445 ;
}
static inline T_6
F_177 ( struct V_5 * V_6 , T_4 V_88 )
{
return V_6 -> V_89 [ V_88 - 1 ] . V_446 ;
}
static inline void
F_178 ( struct V_5 * V_6 , T_4 V_88 , T_6 V_446 )
{
V_6 -> V_89 [ V_88 - 1 ] . V_446 = V_446 ;
}
static void
F_179 ( struct V_5 * V_6 , struct V_87 * V_90 ,
struct V_47 * V_48 , T_11 * V_103 ,
T_4 V_88 )
{
T_16 V_447 , V_448 , V_449 , V_450 , V_451 ;
T_10 V_227 , V_229 ;
T_6 V_215 , V_452 = V_90 -> V_453 [ 0 ] ;
if ( V_452 != V_454 && V_452 != V_455 &&
V_452 != V_456 && V_452 != V_457 )
return;
if ( V_452 == V_454 || V_452 == V_455 )
V_447 = F_180 ( & V_103 -> V_430 . V_458 [ 2 ] ) ;
else
V_447 = F_181 ( & V_103 -> V_430 . V_458 [ 2 ] ) ;
V_451 = F_52 ( V_90 ) >> V_48 -> V_241 ;
if ( V_447 + V_451 - 1 > V_48 -> V_242 )
return;
V_227 = V_48 -> V_227 ;
V_229 = V_48 -> V_240 ;
V_449 = V_447 & ( V_227 - 1 ) ;
if ( V_449 + V_451 > V_227 )
return;
V_215 = V_48 -> V_215 ;
V_448 = V_447 >> V_229 ;
V_450 = F_95 ( V_448 , V_215 ) ;
V_448 = ( V_448 << V_229 ) + V_449 ;
V_103 -> V_221 = F_112 ( V_48 -> V_237 [ V_450 ] ) ;
if ( V_452 == V_454 || V_452 == V_455 )
F_182 ( F_183 ( V_448 ) ,
& V_103 -> V_430 . V_458 [ 2 ] ) ;
else
F_184 ( V_448 , & V_103 -> V_430 . V_458 [ 2 ] ) ;
F_178 ( V_6 , V_88 , 1 ) ;
}
static int
F_185 ( struct V_141 * V_142 , struct V_87 * V_90 )
{
struct V_5 * V_6 = F_58 ( V_142 ) ;
struct V_145 * V_146 ;
struct V_147 * V_148 ;
struct V_47 * V_48 ;
T_11 * V_103 ;
T_10 V_459 ;
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
if ( V_6 -> V_304 || V_6 -> V_460 )
return V_461 ;
else if ( V_146 -> V_351 || V_148 -> V_291 )
return V_462 ;
else if ( V_148 -> V_375 ) {
V_90 -> V_335 = V_336 << 16 ;
V_90 -> V_337 ( V_90 ) ;
return 0 ;
}
if ( V_90 -> V_118 == V_463 )
V_459 = V_464 ;
else if ( V_90 -> V_118 == V_119 )
V_459 = V_465 ;
else
V_459 = V_466 ;
V_459 |= V_467 ;
if ( ! V_6 -> V_163 && ! F_70 ( & V_90 -> V_43 -> V_212 ) &&
F_89 ( V_90 -> V_43 ) && V_90 -> V_468 != 32 )
V_459 |= V_469 ;
V_88 = F_186 ( V_6 , V_6 -> V_470 , V_90 ) ;
if ( ! V_88 ) {
F_3 ( V_34 L_68 ,
V_6 -> V_35 , V_36 ) ;
goto V_75;
}
V_103 = F_48 ( V_6 , V_88 ) ;
memset ( V_103 , 0 , sizeof( T_11 ) ) ;
F_169 ( V_90 , V_103 ) ;
if ( V_90 -> V_468 == 32 )
V_459 |= 4 << V_471 ;
V_103 -> V_316 = V_472 ;
if ( V_146 -> V_152 -> V_65 &
V_167 )
V_103 -> V_316 = V_473 ;
else
V_103 -> V_316 = V_472 ;
V_103 -> V_221 =
F_112 ( V_146 -> V_152 -> V_27 ) ;
V_103 -> V_474 = F_174 ( F_52 ( V_90 ) ) ;
V_103 -> V_475 = F_174 ( V_459 ) ;
V_103 -> V_476 = F_112 ( V_90 -> V_468 ) ;
V_103 -> V_477 = V_478 ;
V_103 -> V_479 = V_480 ;
V_103 -> V_481 =
F_187 ( V_6 , V_88 ) ;
V_103 -> V_482 = F_53 ( T_11 , V_127 ) / 4 ;
V_103 -> V_483 = F_112 ( V_484 +
V_485 ) ;
V_103 -> V_486 = 0 ;
V_103 -> V_487 = 0 ;
F_113 ( V_146 -> V_95 , (struct V_320 * )
V_103 -> V_321 ) ;
memcpy ( V_103 -> V_430 . V_458 , V_90 -> V_453 , V_90 -> V_468 ) ;
if ( ! V_103 -> V_474 ) {
F_188 ( V_6 , & V_103 -> V_127 ) ;
} else {
if ( F_47 ( V_6 , V_90 , V_88 ) ) {
F_157 ( V_6 , V_88 ) ;
goto V_75;
}
}
V_48 = V_148 -> V_48 ;
if ( V_48 && V_48 -> V_224 )
F_179 ( V_6 , V_90 , V_48 , V_103 ,
V_88 ) ;
if ( F_149 ( V_103 -> V_316 == V_472 ) )
F_189 ( V_6 , V_88 ,
F_9 ( V_103 -> V_221 ) ) ;
else
F_156 ( V_6 , V_88 ) ;
return 0 ;
V_75:
return V_461 ;
}
static void
F_190 ( char * V_441 , struct V_488 * V_489 )
{
if ( ( V_441 [ 0 ] & 0x7F ) >= 0x72 ) {
V_489 -> V_490 = V_441 [ 1 ] & 0x0F ;
V_489 -> V_491 = V_441 [ 2 ] ;
V_489 -> V_437 = V_441 [ 3 ] ;
} else {
V_489 -> V_490 = V_441 [ 2 ] & 0x0F ;
V_489 -> V_491 = V_441 [ 12 ] ;
V_489 -> V_437 = V_441 [ 13 ] ;
}
}
static void
F_191 ( struct V_5 * V_6 , struct V_87 * V_90 ,
T_29 * V_29 , T_4 V_88 )
{
T_10 V_492 ;
T_6 * V_493 ;
T_4 V_30 = F_9 ( V_29 -> V_38 ) &
V_39 ;
T_6 V_494 = V_29 -> V_495 ;
T_6 V_496 = V_29 -> V_497 ;
char * V_498 = NULL ;
char * V_499 = NULL ;
char * V_500 = V_6 -> V_501 ;
T_10 V_502 = F_69 ( V_29 -> V_324 ) ;
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
if ( V_502 == 0x31170000 )
return;
switch ( V_30 ) {
case V_40 :
V_498 = L_137 ;
break;
case V_503 :
V_498 = L_138 ;
break;
case V_504 :
V_498 = L_139 ;
break;
case V_505 :
V_498 = L_140 ;
break;
case V_506 :
V_498 = L_141 ;
break;
case V_507 :
V_498 = L_142 ;
break;
case V_508 :
V_498 = L_143 ;
break;
case V_509 :
V_498 = L_144 ;
break;
case V_510 :
V_498 = L_145 ;
break;
case V_511 :
V_498 = L_146 ;
break;
case V_512 :
V_498 = L_147 ;
break;
case V_513 :
V_498 = L_148 ;
break;
case V_514 :
V_498 = L_149 ;
break;
case V_515 :
V_498 = L_150 ;
break;
case V_438 :
V_498 = L_151 ;
break;
case V_440 :
V_498 = L_152 ;
break;
case V_439 :
V_498 = L_153 ;
break;
default:
V_498 = L_62 ;
break;
}
switch ( V_496 ) {
case V_516 :
V_499 = L_154 ;
break;
case V_517 :
V_499 = L_155 ;
break;
case V_518 :
V_499 = L_156 ;
break;
case V_519 :
V_499 = L_157 ;
break;
case V_520 :
V_499 = L_158 ;
break;
case V_521 :
V_499 = L_159 ;
break;
case V_522 :
V_499 = L_160 ;
break;
case V_523 :
V_499 = L_161 ;
break;
case V_524 :
V_499 = L_162 ;
break;
case V_525 :
V_499 = L_163 ;
break;
case V_526 :
V_499 = L_164 ;
break;
default:
V_499 = L_62 ;
break;
}
V_500 [ 0 ] = '\0' ;
if ( ! V_494 )
V_500 = L_131 ;
if ( V_494 & V_527 )
strcat ( V_500 , L_165 ) ;
if ( V_494 & V_528 )
strcat ( V_500 , L_166 ) ;
if ( V_494 & V_529 )
strcat ( V_500 , L_167 ) ;
if ( V_494 & V_530 )
strcat ( V_500 , L_168 ) ;
if ( V_494 & V_531 )
strcat ( V_500 , L_169 ) ;
F_120 ( V_90 ) ;
if ( V_333 -> V_65 & V_153 ) {
F_3 ( V_99 L_170 , V_6 -> V_35 ,
V_334 , ( unsigned long long ) V_333 -> V_9 ) ;
} else {
F_18 ( & V_6 -> V_66 , V_65 ) ;
V_46 = F_15 ( V_6 ,
V_333 -> V_9 ) ;
if ( V_46 ) {
F_3 ( V_99 L_171
L_172 , V_6 -> V_35 , V_46 -> V_9 ,
V_46 -> V_262 ) ;
F_3 ( V_99
L_173 ,
V_6 -> V_35 , V_46 -> V_14 ,
V_46 -> V_18 ) ;
}
F_21 ( & V_6 -> V_66 , V_65 ) ;
}
F_3 ( V_99 L_174
L_175 , V_6 -> V_35 , F_9 ( V_29 -> V_221 ) ,
V_498 , V_30 , V_88 ) ;
F_3 ( V_99 L_176
L_177 , V_6 -> V_35 , F_52 ( V_90 ) , V_90 -> V_532 ,
F_192 ( V_90 ) ) ;
F_3 ( V_99 L_178
L_179 , V_6 -> V_35 , F_9 ( V_29 -> V_533 ) ,
F_69 ( V_29 -> V_534 ) , V_90 -> V_335 ) ;
F_3 ( V_99 L_180
L_181 , V_6 -> V_35 , V_499 ,
V_496 , V_500 , V_494 ) ;
if ( V_494 & V_531 ) {
struct V_488 V_489 ;
F_190 ( V_90 -> V_441 , & V_489 ) ;
F_3 ( V_99 L_182
L_183 , V_6 -> V_35 , V_489 . V_490 ,
V_489 . V_491 , V_489 . V_437 , F_69 ( V_29 -> V_535 ) ) ;
}
if ( V_494 & V_527 ) {
V_492 = F_69 ( V_29 -> V_536 ) ;
V_493 = ( T_6 * ) & V_492 ;
F_96 ( V_6 , V_493 [ 0 ] ) ;
}
}
static void
F_193 ( struct V_5 * V_6 , T_4 V_27 )
{
T_30 V_29 ;
T_31 V_103 ;
struct V_45 * V_46 ;
V_46 = F_16 ( V_6 , V_27 ) ;
if ( ! V_46 )
return;
memset ( & V_103 , 0 , sizeof( T_31 ) ) ;
V_103 . V_316 = V_537 ;
V_103 . V_538 = V_539 ;
V_103 . V_540 =
F_174 ( V_541 ) ;
V_103 . V_221 = F_112 ( V_27 ) ;
V_103 . V_171 = V_542 ;
if ( ( F_194 ( V_6 , & V_29 ,
& V_103 ) ) != 0 ) {
F_3 ( V_34 L_2 , V_6 -> V_35 ,
__FILE__ , __LINE__ , V_36 ) ;
return;
}
V_46 -> V_543 = 1 ;
if ( V_29 . V_38 || V_29 . V_324 ) {
F_23 ( V_6 , F_3 ( V_58
L_184 ,
V_6 -> V_35 , F_9 ( V_29 . V_38 ) ,
F_69 ( V_29 . V_324 ) ) ) ;
return;
}
}
static void
F_195 ( struct V_5 * V_6 ,
struct V_45 * V_46 )
{
T_30 V_29 ;
T_31 V_103 ;
memset ( & V_103 , 0 , sizeof( T_31 ) ) ;
V_103 . V_316 = V_537 ;
V_103 . V_538 = V_539 ;
V_103 . V_540 = 0 ;
V_103 . V_544 = F_112 ( V_46 -> V_18 ) ;
V_103 . V_221 = 0 ;
V_103 . V_545 = F_112 ( V_46 -> V_546 ) ;
V_103 . V_171 = V_547 ;
if ( ( F_194 ( V_6 , & V_29 ,
& V_103 ) ) != 0 ) {
F_3 ( V_34 L_2 , V_6 -> V_35 ,
__FILE__ , __LINE__ , V_36 ) ;
return;
}
if ( V_29 . V_38 || V_29 . V_324 ) {
F_23 ( V_6 , F_3 ( V_58 L_185
L_186 , V_6 -> V_35 ,
F_9 ( V_29 . V_38 ) ,
F_69 ( V_29 . V_324 ) ) ) ;
return;
}
}
static void
F_196 ( struct V_5 * V_6 , T_4 V_27 )
{
struct V_340 * V_341 ;
V_341 = F_62 ( sizeof( struct V_340 ) , V_347 ) ;
if ( ! V_341 )
return;
V_341 -> V_348 = V_548 ;
V_341 -> V_549 = V_27 ;
V_341 -> V_6 = V_6 ;
F_127 ( V_6 , V_341 ) ;
}
static void
F_197 ( struct V_5 * V_6 , T_4 V_27 )
{
struct V_156 * V_70 ;
struct V_147 * V_148 ;
T_32 * V_550 ;
T_33 * V_362 ;
struct V_45 * V_46 ;
T_34 V_214 ;
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
F_121 ( V_551 , V_70 , L_187 ) ;
F_21 ( & V_6 -> V_66 , V_65 ) ;
if ( V_6 -> V_552 -> V_553 == V_554 )
F_196 ( V_6 , V_27 ) ;
V_214 = F_53 ( T_32 , V_555 ) +
sizeof( T_33 ) ;
V_550 = F_62 ( V_214 , V_347 ) ;
if ( ! V_550 ) {
F_3 ( V_34 L_2 ,
V_6 -> V_35 , __FILE__ , __LINE__ , V_36 ) ;
return;
}
V_550 -> V_316 = V_556 ;
V_550 -> V_557 =
F_112 ( V_558 ) ;
V_550 -> V_286 = V_214 / 4 ;
V_550 -> V_559 =
F_112 ( sizeof( T_33 ) / 4 ) ;
V_362 = ( T_33 * )
V_550 -> V_555 ;
V_362 -> V_403 = V_560 ;
V_362 -> V_561 = 0x5D ;
V_362 -> V_221 = F_112 ( V_27 ) ;
V_362 -> V_11 = F_198 ( V_148 -> V_9 ) ;
F_199 ( V_6 , V_550 ) ;
F_20 ( V_550 ) ;
}
static T_6
F_200 ( struct V_5 * V_6 , T_4 V_88 , T_6 V_280 , T_10 V_281 )
{
T_11 * V_103 ;
T_29 * V_29 ;
struct V_87 * V_90 ;
T_4 V_30 ;
T_10 V_562 ;
T_6 V_494 ;
T_6 V_496 ;
T_10 V_502 ;
struct V_145 * V_146 ;
T_10 V_271 = 0 ;
unsigned long V_65 ;
V_29 = F_99 ( V_6 , V_281 ) ;
V_90 = F_38 ( V_6 , V_88 ) ;
if ( V_90 == NULL )
return 1 ;
V_103 = F_48 ( V_6 , V_88 ) ;
if ( V_29 == NULL ) {
V_90 -> V_335 = V_563 << 16 ;
goto V_75;
}
V_146 = V_90 -> V_43 -> V_150 ;
if ( ! V_146 || ! V_146 -> V_152 ||
V_146 -> V_152 -> V_375 ) {
V_90 -> V_335 = V_336 << 16 ;
goto V_75;
}
V_30 = F_9 ( V_29 -> V_38 ) ;
if ( F_177 ( V_6 , V_88 ) &&
( ( V_30 & V_39 )
!= V_511 ) ) {
F_18 ( & V_6 -> V_91 , V_65 ) ;
V_6 -> V_89 [ V_88 - 1 ] . V_90 = V_90 ;
F_178 ( V_6 , V_88 , 0 ) ;
F_21 ( & V_6 -> V_91 , V_65 ) ;
memcpy ( V_103 -> V_430 . V_458 , V_90 -> V_453 , V_90 -> V_468 ) ;
V_103 -> V_221 =
F_112 ( V_146 -> V_152 -> V_27 ) ;
F_189 ( V_6 , V_88 ,
V_146 -> V_152 -> V_27 ) ;
return 0 ;
}
V_494 = V_29 -> V_495 ;
if ( V_494 & V_527 )
V_271 =
F_69 ( V_29 -> V_536 ) & 0xFF ;
if ( ! V_146 -> V_564 ) {
V_146 -> V_564 ++ ;
if ( ! V_6 -> V_163 && ! F_70 ( & V_90 -> V_43 -> V_212 ) &&
F_89 ( V_90 -> V_43 ) &&
V_271 == V_274 ) {
F_201 ( V_90 -> V_43 ) ;
F_51 ( V_7 , V_90 -> V_43 , L_188 ) ;
}
}
V_562 = F_69 ( V_29 -> V_534 ) ;
F_202 ( V_90 , F_52 ( V_90 ) - V_562 ) ;
if ( V_30 & V_565 )
V_502 = F_69 ( V_29 -> V_324 ) ;
else
V_502 = 0 ;
V_30 &= V_39 ;
V_496 = V_29 -> V_497 ;
if ( V_30 == V_508 && V_562 == 0 &&
( V_496 == V_519 ||
V_496 == V_522 ||
V_496 == V_524 ) ) {
V_30 = V_40 ;
}
if ( V_494 & V_531 ) {
struct V_488 V_489 ;
const void * V_566 = F_203 ( V_6 ,
V_88 ) ;
T_10 V_214 = F_204 ( T_10 , V_480 ,
F_69 ( V_29 -> V_535 ) ) ;
memcpy ( V_90 -> V_441 , V_566 , V_214 ) ;
F_190 ( V_90 -> V_441 , & V_489 ) ;
if ( V_489 . V_491 == 0x5D )
F_197 ( V_6 ,
F_9 ( V_29 -> V_221 ) ) ;
}
switch ( V_30 ) {
case V_567 :
case V_568 :
V_90 -> V_335 = V_569 ;
break;
case V_506 :
V_90 -> V_335 = V_336 << 16 ;
break;
case V_514 :
if ( V_146 -> V_351 ) {
V_90 -> V_335 = V_570 << 16 ;
goto V_75;
}
if ( V_502 == 0x32010081 ) {
V_90 -> V_335 = V_338 << 16 ;
break;
}
V_90 -> V_335 = V_571 << 16 ;
break;
case V_511 :
case V_515 :
V_90 -> V_335 = V_338 << 16 ;
break;
case V_512 :
if ( ( V_562 == 0 ) || ( V_90 -> V_532 > V_562 ) )
V_90 -> V_335 = V_571 << 16 ;
else
V_90 -> V_335 = ( V_563 << 16 ) | V_496 ;
break;
case V_508 :
V_90 -> V_335 = ( V_563 << 16 ) | V_496 ;
if ( ( V_494 & V_531 ) )
break;
if ( V_562 < V_90 -> V_532 ) {
if ( V_496 == V_569 )
V_90 -> V_335 = V_569 ;
else
V_90 -> V_335 = V_571 << 16 ;
} else if ( V_494 & ( V_530 |
V_529 ) )
V_90 -> V_335 = V_571 << 16 ;
else if ( V_494 & V_528 )
V_90 -> V_335 = V_338 << 16 ;
else if ( ! V_562 && V_90 -> V_453 [ 0 ] == V_572 ) {
V_29 -> V_495 = V_531 ;
V_29 -> V_497 = V_445 ;
V_90 -> V_335 = ( V_443 << 24 ) |
V_445 ;
V_90 -> V_441 [ 0 ] = 0x70 ;
V_90 -> V_441 [ 2 ] = V_442 ;
V_90 -> V_441 [ 12 ] = 0x20 ;
V_90 -> V_441 [ 13 ] = 0 ;
}
break;
case V_507 :
F_202 ( V_90 , 0 ) ;
case V_504 :
case V_40 :
V_90 -> V_335 = ( V_563 << 16 ) | V_496 ;
if ( V_271 ==
V_274 ||
( V_494 & ( V_530 |
V_529 ) ) )
V_90 -> V_335 = V_571 << 16 ;
else if ( V_494 & V_528 )
V_90 -> V_335 = V_338 << 16 ;
break;
case V_438 :
case V_440 :
case V_439 :
F_175 ( V_90 , V_30 ) ;
break;
case V_510 :
case V_503 :
case V_573 :
case V_574 :
case V_575 :
case V_576 :
case V_509 :
case V_513 :
default:
V_90 -> V_335 = V_571 << 16 ;
break;
}
#ifdef F_205
if ( V_90 -> V_335 && ( V_6 -> V_8 & V_577 ) )
F_191 ( V_6 , V_90 , V_29 , V_88 ) ;
#endif
V_75:
F_168 ( V_90 ) ;
V_90 -> V_337 ( V_90 ) ;
return 1 ;
}
static void
F_206 ( struct V_5 * V_6 )
{
T_4 V_214 ;
T_4 V_30 ;
int V_92 ;
T_9 V_29 ;
T_35 * V_578 = NULL ;
T_4 V_579 ;
T_6 V_580 ;
F_111 ( V_6 , F_3 ( V_58
L_189 ,
V_6 -> V_35 , ( unsigned long long ) V_6 -> V_31 . V_9 ) ) ;
V_214 = F_53 ( T_35 , V_581 ) + ( V_6 -> V_31 . V_32
* sizeof( V_582 ) ) ;
V_578 = F_62 ( V_214 , V_160 ) ;
if ( ! V_578 ) {
F_3 ( V_34 L_2 ,
V_6 -> V_35 , __FILE__ , __LINE__ , V_36 ) ;
return;
}
if ( ( F_207 ( V_6 , & V_29 ,
V_578 , V_214 ) ) != 0 )
goto V_75;
V_30 = F_9 ( V_29 . V_38 ) & V_39 ;
if ( V_30 != V_40 )
goto V_75;
for ( V_92 = 0 ; V_92 < V_6 -> V_31 . V_32 ; V_92 ++ ) {
V_580 = V_578 -> V_581 [ V_92 ] . V_583 >> 4 ;
if ( V_92 == 0 )
V_6 -> V_31 . V_27 = F_9 ( V_578 ->
V_581 [ 0 ] . V_584 ) ;
V_6 -> V_31 . V_262 [ V_92 ] . V_27 = V_6 -> V_31 . V_27 ;
V_579 = F_9 ( V_578 -> V_581 [ V_92 ] .
V_367 ) ;
if ( V_579 && V_580 < V_585 )
V_580 = V_585 ;
F_208 ( V_6 , V_6 -> V_31 . V_9 ,
V_579 , V_92 , V_580 ) ;
}
V_75:
F_20 ( V_578 ) ;
}
static void
F_209 ( struct V_5 * V_6 )
{
int V_92 ;
T_9 V_29 ;
T_35 * V_578 = NULL ;
T_36 * V_586 = NULL ;
T_37 V_587 ;
T_8 V_28 ;
T_38 V_588 ;
T_4 V_30 ;
T_4 V_214 ;
T_4 V_589 ;
F_210 ( V_6 , & V_6 -> V_31 . V_32 ) ;
if ( ! V_6 -> V_31 . V_32 ) {
F_3 ( V_34 L_2 ,
V_6 -> V_35 , __FILE__ , __LINE__ , V_36 ) ;
return;
}
V_214 = F_53 ( T_35 , V_581 ) + ( V_6 -> V_31 . V_32 *
sizeof( V_582 ) ) ;
V_578 = F_62 ( V_214 , V_160 ) ;
if ( ! V_578 ) {
F_3 ( V_34 L_2 ,
V_6 -> V_35 , __FILE__ , __LINE__ , V_36 ) ;
return;
}
if ( ( F_207 ( V_6 , & V_29 ,
V_578 , V_214 ) ) ) {
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
V_214 = F_53 ( T_36 , V_581 ) + ( V_6 -> V_31 . V_32 *
sizeof( V_590 ) ) ;
V_586 = F_62 ( V_214 , V_160 ) ;
if ( ! V_586 ) {
F_3 ( V_34 L_2 ,
V_6 -> V_35 , __FILE__ , __LINE__ , V_36 ) ;
goto V_75;
}
if ( ( F_211 ( V_6 , & V_29 ,
V_586 , V_214 ) ) ) {
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
V_6 -> V_591 =
F_9 ( V_586 -> V_592 ) ;
V_589 =
F_9 ( V_586 -> V_593 ) ;
if ( V_589 & V_594 )
V_6 -> V_589 = ( V_589 &
V_595 ) * 16 ;
else
V_6 -> V_589 = V_589 &
V_595 ;
V_6 -> V_31 . V_596 = & V_6 -> V_142 -> V_597 ;
V_6 -> V_31 . V_262 = F_212 ( V_6 -> V_31 . V_32 ,
sizeof( struct V_598 ) , V_160 ) ;
if ( ! V_6 -> V_31 . V_262 ) {
F_3 ( V_34 L_2 ,
V_6 -> V_35 , __FILE__ , __LINE__ , V_36 ) ;
goto V_75;
}
for ( V_92 = 0 ; V_92 < V_6 -> V_31 . V_32 ; V_92 ++ ) {
if ( ( F_213 ( V_6 , & V_29 , & V_587 ,
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
V_6 -> V_31 . V_27 = F_9 ( V_578 ->
V_581 [ 0 ] . V_584 ) ;
V_6 -> V_31 . V_262 [ V_92 ] . V_27 = V_6 -> V_31 . V_27 ;
V_6 -> V_31 . V_262 [ V_92 ] . V_599 = V_92 ;
F_214 ( V_6 , & V_6 -> V_31 . V_262 [ V_92 ] ,
V_587 , V_6 -> V_31 . V_596 ) ;
}
if ( ( F_12 ( V_6 , & V_29 , & V_28 ,
V_33 , V_6 -> V_31 . V_27 ) ) ) {
F_3 ( V_34 L_2 ,
V_6 -> V_35 , __FILE__ , __LINE__ , V_36 ) ;
goto V_75;
}
V_6 -> V_31 . V_546 =
F_9 ( V_28 . V_545 ) ;
V_6 -> V_31 . V_9 = F_6 ( V_28 . V_11 ) ;
F_3 ( V_58 L_190
L_191 , V_6 -> V_35 , V_6 -> V_31 . V_27 ,
( unsigned long long ) V_6 -> V_31 . V_9 ,
V_6 -> V_31 . V_32 ) ;
if ( V_6 -> V_31 . V_546 ) {
if ( ! ( F_215 ( V_6 , & V_29 ,
& V_588 ,
V_600 ,
V_6 -> V_31 . V_546 ) ) ) {
V_6 -> V_31 . V_14 =
F_6 ( V_588 . V_16 ) ;
}
}
V_75:
F_20 ( V_586 ) ;
F_20 ( V_578 ) ;
}
static int
F_216 ( struct V_5 * V_6 , T_4 V_27 )
{
struct V_78 * V_79 ;
T_9 V_29 ;
T_39 V_601 ;
T_40 V_602 ;
T_38 V_588 ;
T_10 V_30 ;
T_4 V_603 ;
T_1 V_9 , V_69 = 0 ;
int V_92 ;
unsigned long V_65 ;
struct V_353 * V_354 = NULL ;
int V_20 = 0 ;
if ( ! V_27 )
return - 1 ;
if ( V_6 -> V_304 || V_6 -> V_306 )
return - 1 ;
if ( ( F_217 ( V_6 , & V_29 , & V_601 ,
V_604 , V_27 ) ) ) {
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
V_603 = F_9 ( V_601 . V_605 ) ;
if ( F_11 ( V_6 , V_603 , & V_69 )
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
V_20 = F_216 ( V_6 , V_603 ) ;
if ( V_20 != 0 )
return V_20 ;
}
}
F_18 ( & V_6 -> V_80 , V_65 ) ;
V_9 = F_6 ( V_601 . V_11 ) ;
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
V_79 -> V_32 = V_601 . V_606 ;
V_79 -> V_69 = V_69 ;
V_79 -> V_9 = V_9 ;
F_3 ( V_58 L_192
L_193 , V_6 -> V_35 ,
V_27 , V_603 , ( unsigned long long )
V_79 -> V_9 , V_79 -> V_32 ) ;
if ( ! V_79 -> V_32 )
goto V_607;
V_79 -> V_262 = F_212 ( V_79 -> V_32 ,
sizeof( struct V_598 ) , V_160 ) ;
if ( ! V_79 -> V_262 ) {
F_3 ( V_34 L_2 ,
V_6 -> V_35 , __FILE__ , __LINE__ , V_36 ) ;
V_20 = - 1 ;
goto V_607;
}
F_147 ( & V_79 -> V_608 ) ;
V_354 = F_25 ( V_6 , V_27 ,
V_69 ) ;
if ( ! V_354 ) {
F_3 ( V_34 L_2 ,
V_6 -> V_35 , __FILE__ , __LINE__ , V_36 ) ;
V_20 = - 1 ;
goto V_607;
}
V_79 -> V_596 = & V_354 -> V_159 -> V_157 ;
for ( V_92 = 0 ; V_92 < V_79 -> V_32 ; V_92 ++ ) {
if ( ( F_218 ( V_6 , & V_29 ,
& V_602 , V_92 , V_27 ) ) ) {
F_3 ( V_34 L_2 ,
V_6 -> V_35 , __FILE__ , __LINE__ , V_36 ) ;
V_20 = - 1 ;
goto V_607;
}
V_79 -> V_262 [ V_92 ] . V_27 = V_27 ;
V_79 -> V_262 [ V_92 ] . V_599 = V_92 ;
if ( ( F_219 ( V_6 ,
& V_79 -> V_262 [ V_92 ] , V_602 ,
V_79 -> V_596 ) ) ) {
F_3 ( V_34 L_2 ,
V_6 -> V_35 , __FILE__ , __LINE__ , V_36 ) ;
V_20 = - 1 ;
goto V_607;
}
}
if ( V_79 -> V_546 ) {
if ( ! ( F_215 ( V_6 , & V_29 ,
& V_588 , V_600 ,
V_79 -> V_546 ) ) ) {
V_79 -> V_14 =
F_6 ( V_588 . V_16 ) ;
}
}
F_35 ( V_6 , V_79 ) ;
return 0 ;
V_607:
if ( V_354 )
F_26 ( V_6 , V_79 -> V_9 ,
V_69 ) ;
F_20 ( V_79 ) ;
return V_20 ;
}
static T_6
F_220 ( struct V_5 * V_6 , T_4 V_88 , T_6 V_280 , T_10 V_281 )
{
T_18 * V_29 ;
V_29 = F_99 ( V_6 , V_281 ) ;
if ( V_6 -> V_609 . V_283 == V_284 )
return 1 ;
if ( V_6 -> V_609 . V_88 != V_88 )
return 1 ;
V_6 -> V_609 . V_283 |= V_285 ;
if ( V_29 ) {
memcpy ( V_6 -> V_609 . V_281 , V_29 ,
V_29 -> V_286 * 4 ) ;
V_6 -> V_609 . V_283 |= V_287 ;
}
V_6 -> V_609 . V_283 &= ~ V_288 ;
F_100 ( & V_6 -> V_609 . V_289 ) ;
return 1 ;
}
void
F_221 ( struct V_5 * V_6 , T_1 V_9 )
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
F_222 ( V_6 , V_79 ) ;
}
static T_6
F_223 ( struct V_5 * V_6 , T_1 V_9 ,
T_4 V_27 , T_6 V_610 )
{
T_6 V_20 = 1 ;
char * V_272 = NULL ;
switch ( V_610 ) {
case V_611 :
case V_612 :
V_20 = 0 ;
break;
case V_613 :
V_272 = L_194 ;
break;
case V_614 :
V_272 = L_195 ;
break;
case V_615 :
V_272 = L_196 ;
break;
case V_616 :
V_272 = L_197 ;
break;
case V_617 :
V_272 = L_198 ;
break;
case V_618 :
case V_619 :
case V_620 :
case V_621 :
case V_622 :
case V_623 :
case V_624 :
case V_625 :
case V_626 :
case V_627 :
case V_628 :
case V_629 :
V_272 = L_199 ;
break;
default:
V_272 = L_62 ;
break;
}
if ( ! V_20 )
return 0 ;
F_3 ( V_34 L_200
L_96 , V_6 -> V_35 , V_272 ,
( unsigned long long ) V_9 , V_27 ) ;
return V_20 ;
}
static void
F_224 ( struct V_5 * V_6 , T_4 V_27 )
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
F_3 ( V_34 L_201
L_202 , V_6 -> V_35 , V_27 ) ;
F_21 ( & V_6 -> V_66 , V_65 ) ;
return;
}
if ( F_152 ( V_46 -> V_27 != V_27 ) ) {
V_70 = V_46 -> V_70 ;
V_148 = V_70 -> V_150 ;
F_121 ( V_7 , V_70 , L_203
L_204 , V_46 -> V_27 , V_27 ) ;
V_148 -> V_27 = V_27 ;
V_46 -> V_27 = V_27 ;
}
if ( ! ( F_9 ( V_28 . V_171 ) &
V_630 ) ) {
F_3 ( V_34 L_201
L_205 , V_6 -> V_35 , V_27 ) ;
F_21 ( & V_6 -> V_66 , V_65 ) ;
return;
}
if ( F_223 ( V_6 , V_9 , V_27 ,
V_28 . V_631 ) ) {
F_21 ( & V_6 -> V_66 , V_65 ) ;
return;
}
F_21 ( & V_6 -> V_66 , V_65 ) ;
F_139 ( V_6 , V_9 ) ;
}
static int
F_225 ( struct V_5 * V_6 , T_4 V_27 , T_6 V_632 , T_6 V_633 )
{
T_9 V_29 ;
T_8 V_28 ;
T_38 V_588 ;
struct V_45 * V_46 ;
T_10 V_30 ;
T_41 V_9 ;
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
V_630 ) ) {
F_3 ( V_34 L_2 ,
V_6 -> V_35 , __FILE__ , __LINE__ , V_36 ) ;
F_3 ( V_34 L_206 ,
V_6 -> V_35 , F_9 ( V_28 . V_171 ) ) ;
return - 1 ;
}
if ( F_223 ( V_6 , V_9 , V_27 ,
V_28 . V_631 ) )
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
( V_28 . V_605 ) ,
& V_46 -> V_69 ) != 0 )
F_3 ( V_34 L_2 ,
V_6 -> V_35 , __FILE__ , __LINE__ , V_36 ) ;
V_46 -> V_546 =
F_9 ( V_28 . V_545 ) ;
V_46 -> V_18 =
F_9 ( V_28 . V_544 ) ;
V_46 -> V_82 = V_82 ;
V_46 -> V_9 = V_9 ;
V_46 -> V_262 = V_28 . V_634 ;
if ( V_46 -> V_546 && ! ( F_215 (
V_6 , & V_29 , & V_588 , V_600 ,
V_46 -> V_546 ) ) )
V_46 -> V_14 =
F_6 ( V_588 . V_16 ) ;
V_46 -> V_12 = F_6 ( V_28 . V_13 ) ;
if ( V_6 -> V_635 )
F_27 ( V_6 , V_46 ) ;
else
F_22 ( V_6 , V_46 ) ;
return 0 ;
}
static void
F_226 ( struct V_5 * V_6 ,
struct V_45 * V_46 )
{
struct V_147 * V_148 ;
if ( ( V_6 -> V_552 -> V_553 == V_554 ) &&
( V_46 -> V_543 ) ) {
F_195 ( V_6 , V_46 ) ;
V_46 -> V_543 = 0 ;
}
F_23 ( V_6 , F_3 ( V_58 L_207
L_108 , V_6 -> V_35 , V_36 ,
V_46 -> V_27 , ( unsigned long long )
V_46 -> V_9 ) ) ;
if ( V_46 -> V_70 && V_46 -> V_70 -> V_150 ) {
V_148 = V_46 -> V_70 -> V_150 ;
V_148 -> V_375 = 1 ;
F_139 ( V_6 , V_46 -> V_9 ) ;
V_148 -> V_27 =
V_161 ;
}
if ( ! V_6 -> V_636 )
F_26 ( V_6 ,
V_46 -> V_9 ,
V_46 -> V_69 ) ;
F_3 ( V_58 L_208
L_209 , V_6 -> V_35 , V_46 -> V_27 ,
( unsigned long long ) V_46 -> V_9 ) ;
F_23 ( V_6 , F_3 ( V_58 L_210
L_108 , V_6 -> V_35 , V_36 ,
V_46 -> V_27 , ( unsigned long long )
V_46 -> V_9 ) ) ;
F_20 ( V_46 ) ;
}
static void
F_227 ( struct V_5 * V_6 , T_4 V_27 )
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
F_226 ( V_6 , V_46 ) ;
}
void
F_228 ( struct V_5 * V_6 ,
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
F_226 ( V_6 , V_46 ) ;
}
static void
F_229 ( struct V_5 * V_6 ,
T_22 * V_362 )
{
int V_92 ;
T_4 V_27 ;
T_4 V_363 ;
T_6 V_364 ;
char * V_637 = NULL ;
T_6 V_580 , V_638 ;
switch ( V_362 -> V_390 ) {
case V_397 :
V_637 = L_211 ;
break;
case V_394 :
V_637 = L_212 ;
break;
case V_393 :
case 0 :
V_637 = L_213 ;
break;
case V_391 :
V_637 = L_214 ;
break;
default:
V_637 = L_215 ;
break;
}
F_3 ( V_58 L_216 ,
V_6 -> V_35 , V_637 ) ;
F_3 ( V_7 L_217
L_218 ,
F_9 ( V_362 -> V_389 ) ,
F_9 ( V_362 -> V_545 ) ,
V_362 -> V_368 , V_362 -> V_365 ) ;
for ( V_92 = 0 ; V_92 < V_362 -> V_365 ; V_92 ++ ) {
V_27 = F_9 ( V_362 -> V_366 [ V_92 ] . V_367 ) ;
if ( ! V_27 )
continue;
V_364 = V_362 -> V_368 + V_92 ;
V_363 = V_362 -> V_366 [ V_92 ] . V_369 &
V_370 ;
switch ( V_363 ) {
case V_639 :
V_637 = L_219 ;
break;
case V_388 :
V_637 = L_220 ;
break;
case V_371 :
V_637 = L_221 ;
break;
case V_640 :
V_637 = L_222 ;
break;
case V_641 :
V_637 = L_223 ;
break;
default:
V_637 = L_62 ;
break;
}
V_580 = V_362 -> V_366 [ V_92 ] . V_642 >> 4 ;
V_638 = V_362 -> V_366 [ V_92 ] . V_642 & 0xF ;
F_3 ( V_7 L_224
L_225 , V_364 ,
V_27 , V_637 , V_580 , V_638 ) ;
}
}
static void
F_230 ( struct V_5 * V_6 ,
struct V_340 * V_341 )
{
int V_92 ;
T_4 V_603 , V_27 ;
T_4 V_363 ;
T_6 V_364 , V_643 ;
struct V_78 * V_79 ;
T_1 V_9 ;
unsigned long V_65 ;
T_6 V_580 , V_638 ;
T_22 * V_362 =
( T_22 * )
V_341 -> V_362 ;
#ifdef F_205
if ( V_6 -> V_8 & V_644 )
F_229 ( V_6 , V_362 ) ;
#endif
if ( V_6 -> V_305 || V_6 -> V_306 )
return;
if ( ! V_6 -> V_31 . V_32 )
F_209 ( V_6 ) ;
else
F_206 ( V_6 ) ;
if ( V_341 -> V_396 ) {
F_23 ( V_6 , F_3 ( V_58 L_226
L_227 , V_6 -> V_35 ) ) ;
return;
}
V_603 = F_9 ( V_362 -> V_389 ) ;
if ( V_362 -> V_390 == V_397 )
if ( F_216 ( V_6 , V_603 ) != 0 )
return;
F_18 ( & V_6 -> V_80 , V_65 ) ;
V_79 = F_33 ( V_6 ,
V_603 ) ;
if ( V_79 ) {
V_9 = V_79 -> V_9 ;
V_643 = V_79 -> V_32 ;
} else if ( V_603 < V_6 -> V_31 . V_32 ) {
V_9 = V_6 -> V_31 . V_9 ;
V_643 = V_6 -> V_31 . V_32 ;
} else {
F_21 ( & V_6 -> V_80 , V_65 ) ;
return;
}
F_21 ( & V_6 -> V_80 , V_65 ) ;
for ( V_92 = 0 ; V_92 < V_362 -> V_365 ; V_92 ++ ) {
if ( V_341 -> V_396 ) {
F_23 ( V_6 , F_3 ( V_58 L_228
L_229 , V_6 -> V_35 ) ) ;
return;
}
if ( V_6 -> V_304 || V_6 -> V_305 ||
V_6 -> V_306 )
return;
V_364 = V_362 -> V_368 + V_92 ;
if ( V_364 >= V_643 )
continue;
V_363 = V_362 -> V_366 [ V_92 ] . V_369 &
V_370 ;
if ( ( V_362 -> V_366 [ V_92 ] . V_369 &
V_645 ) && ( V_363 !=
V_388 ) )
continue;
V_27 = F_9 ( V_362 -> V_366 [ V_92 ] . V_367 ) ;
if ( ! V_27 )
continue;
V_580 = V_362 -> V_366 [ V_92 ] . V_642 >> 4 ;
V_638 = V_362 -> V_366 [ V_92 ] . V_642 & 0xF ;
switch ( V_363 ) {
case V_640 :
if ( V_6 -> V_304 )
break;
if ( V_580 == V_638 )
break;
F_208 ( V_6 , V_9 ,
V_27 , V_364 , V_580 ) ;
if ( V_580 < V_585 )
break;
F_224 ( V_6 , V_27 ) ;
break;
case V_639 :
if ( V_6 -> V_304 )
break;
F_208 ( V_6 , V_9 ,
V_27 , V_364 , V_580 ) ;
F_225 ( V_6 , V_27 , V_364 , 0 ) ;
break;
case V_388 :
F_227 ( V_6 , V_27 ) ;
break;
}
}
if ( V_362 -> V_390 == V_394 &&
V_79 )
F_221 ( V_6 , V_9 ) ;
}
static void
F_231 ( struct V_5 * V_6 ,
T_33 * V_362 )
{
char * V_646 = NULL ;
switch ( V_362 -> V_403 ) {
case V_560 :
V_646 = L_230 ;
break;
case V_647 :
V_646 = L_231 ;
break;
case V_648 :
V_646 = L_232 ;
break;
case V_649 :
V_646 = L_233 ;
break;
case V_650 :
V_646 = L_234 ;
break;
case V_651 :
V_646 = L_235 ;
break;
case V_652 :
V_646 = L_236 ;
break;
case V_653 :
V_646 = L_237 ;
break;
case V_654 :
V_646 = L_238 ;
break;
case V_655 :
V_646 = L_239 ;
break;
case V_656 :
V_646 = L_240 ;
break;
case V_657 :
V_646 = L_241 ;
break;
case V_658 :
V_646 = L_242 ;
break;
default:
V_646 = L_243 ;
break;
}
F_3 ( V_58 L_244
L_245 ,
V_6 -> V_35 , V_646 , F_9 ( V_362 -> V_221 ) ,
( unsigned long long ) F_6 ( V_362 -> V_11 ) ,
F_9 ( V_362 -> V_533 ) ) ;
if ( V_362 -> V_403 == V_560 )
F_3 ( V_58 L_246 , V_6 -> V_35 ,
V_362 -> V_561 , V_362 -> V_659 ) ;
F_3 ( V_7 L_247 ) ;
}
static void
F_232 ( struct V_5 * V_6 ,
struct V_340 * V_341 )
{
struct V_147 * V_660 ;
struct V_45 * V_46 ;
T_1 V_9 ;
unsigned long V_65 ;
T_33 * V_362 =
( T_33 * )
V_341 -> V_362 ;
#ifdef F_205
if ( V_6 -> V_8 & V_644 )
F_231 ( V_6 ,
V_362 ) ;
#endif
if ( ( V_6 -> V_245 . V_661 >> 8 ) < 0xC )
return;
if ( V_362 -> V_403 !=
V_648 &&
V_362 -> V_403 !=
V_654 )
return;
F_18 ( & V_6 -> V_66 , V_65 ) ;
V_9 = F_6 ( V_362 -> V_11 ) ;
V_46 = F_15 ( V_6 ,
V_9 ) ;
if ( ! V_46 || ! V_46 -> V_70 ) {
F_21 ( & V_6 -> V_66 , V_65 ) ;
return;
}
V_660 = V_46 -> V_70 -> V_150 ;
if ( ! V_660 ) {
F_21 ( & V_6 -> V_66 , V_65 ) ;
return;
}
if ( V_362 -> V_403 ==
V_648 )
V_660 -> V_291 = 1 ;
else
V_660 -> V_291 = 0 ;
F_21 ( & V_6 -> V_66 , V_65 ) ;
}
static void
F_233 ( struct V_5 * V_6 ,
T_42 * V_362 )
{
char * V_646 = NULL ;
switch ( V_362 -> V_403 ) {
case V_662 :
V_646 = L_248 ;
break;
case V_663 :
V_646 = L_249 ;
break;
default:
V_646 = L_243 ;
break;
}
F_3 ( V_58 L_250
L_251
L_252 , V_6 -> V_35 , V_646 ,
F_9 ( V_362 -> V_545 ) ,
( unsigned long long ) F_6 ( V_362 -> V_16 ) ,
F_9 ( V_362 -> V_664 ) ) ;
}
static void
F_234 ( struct V_5 * V_6 ,
struct V_340 * V_341 )
{
#ifdef F_205
if ( V_6 -> V_8 & V_644 )
F_233 ( V_6 ,
( T_42 * )
V_341 -> V_362 ) ;
#endif
}
static void
F_235 ( struct V_5 * V_6 ,
struct V_340 * V_341 )
{
struct V_87 * V_90 ;
struct V_138 * V_139 ;
T_4 V_88 , V_27 ;
T_10 V_95 ;
struct V_145 * V_146 ;
T_10 V_665 ;
T_10 V_666 ;
T_21 * V_29 ;
T_43 * V_362 =
( T_43 * )
V_341 -> V_362 ;
T_4 V_30 ;
unsigned long V_65 ;
int V_74 ;
T_6 V_667 = 0 ;
T_6 V_668 ;
F_105 ( & V_6 -> V_282 . V_301 ) ;
F_236 ( V_669
L_253 ,
V_6 -> V_35 , V_36 , V_362 -> V_634 ,
V_362 -> V_670 ) ;
F_140 ( V_6 ) ;
F_18 ( & V_6 -> V_91 , V_65 ) ;
V_29 = V_6 -> V_282 . V_281 ;
V_671:
if ( V_667 ++ == 5 ) {
F_23 ( V_6 , F_3 ( V_58 L_254 ,
V_6 -> V_35 , V_36 ) ) ;
goto V_75;
} else if ( V_667 > 1 )
F_23 ( V_6 , F_3 ( V_58 L_255 ,
V_6 -> V_35 , V_36 , V_667 - 1 ) ) ;
V_665 = 0 ;
V_666 = 0 ;
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
V_666 ++ ;
if ( V_6 -> V_304 )
goto V_75;
F_21 ( & V_6 -> V_91 , V_65 ) ;
V_74 = F_104 ( V_6 , V_27 , 0 , 0 , V_95 ,
V_331 , V_88 , 30 ,
V_672 ) ;
if ( V_74 == V_302 ) {
F_51 ( V_551 , V_139 ,
L_256
L_257 , V_90 ) ;
F_18 ( & V_6 -> V_91 , V_65 ) ;
goto V_671;
}
V_30 = F_9 ( V_29 -> V_38 )
& V_39 ;
if ( V_30 != V_40 ) {
F_51 ( V_551 , V_139 , L_258
L_259 , V_30 ,
V_90 ) ;
F_18 ( & V_6 -> V_91 , V_65 ) ;
goto V_671;
}
if ( V_29 -> V_327 ==
V_277 ||
V_29 -> V_327 ==
V_279 ) {
F_18 ( & V_6 -> V_91 , V_65 ) ;
continue;
}
V_668 = 0 ;
V_673:
if ( V_668 ++ == 60 ) {
F_23 ( V_6 , F_3 ( V_58
L_260 , V_6 -> V_35 ,
V_36 ) ) ;
F_18 ( & V_6 -> V_91 , V_65 ) ;
goto V_671;
}
if ( V_6 -> V_304 )
goto V_674;
V_74 = F_104 ( V_6 , V_27 , V_139 -> V_73 , V_139 -> V_72 ,
V_139 -> V_95 , V_315 , V_88 , 30 ,
V_672 ) ;
if ( V_74 == V_302 ) {
F_51 ( V_551 , V_139 ,
L_261
L_82 , V_90 ) ;
goto V_673;
}
if ( V_668 > 1 )
F_51 ( V_551 , V_139 ,
L_262
L_263 ,
V_668 - 1 , V_90 ) ;
V_665 += F_69 ( V_29 -> V_325 ) ;
F_18 ( & V_6 -> V_91 , V_65 ) ;
}
if ( V_6 -> V_675 ) {
F_23 ( V_6 , F_3 ( V_58 L_264
L_265 , V_6 -> V_35 , V_36 ) ) ;
V_6 -> V_675 = 0 ;
goto V_671;
}
V_75:
F_21 ( & V_6 -> V_91 , V_65 ) ;
V_674:
F_23 ( V_6 , F_3 ( V_58
L_266 ,
V_6 -> V_35 , V_36 , V_666 , V_665 ) ) ;
V_6 -> V_676 = 0 ;
if ( ! V_6 -> V_304 )
F_137 ( V_6 ) ;
F_118 ( & V_6 -> V_282 . V_301 ) ;
}
static void
F_237 ( struct V_5 * V_6 ,
struct V_340 * V_341 )
{
T_44 * V_362 =
( T_44 * )
V_341 -> V_362 ;
#ifdef F_205
if ( V_6 -> V_8 & V_644 ) {
F_3 ( V_58 L_267 , V_6 -> V_35 ,
( V_362 -> V_403 == V_677 ) ?
L_268 : L_269 ) ;
if ( V_362 -> V_678 )
F_3 ( L_270 ,
F_69 ( V_362 -> V_678 ) ) ;
F_3 ( L_247 ) ;
}
#endif
if ( V_362 -> V_403 == V_677 &&
! V_6 -> V_31 . V_32 ) {
if ( V_679 > 0 && V_6 -> V_304 ) {
while ( V_6 -> V_304 )
F_238 ( 1 ) ;
}
F_209 ( V_6 ) ;
}
}
static void
F_239 ( struct V_138 * V_139 , void * V_170 )
{
int V_20 ;
V_139 -> V_170 = V_170 ? 1 : 0 ;
F_51 ( V_7 , V_139 , L_271 ,
V_139 -> V_170 ? L_272 : L_273 ) ;
V_20 = F_240 ( V_139 ) ;
}
static void
F_241 ( struct V_5 * V_6 ,
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
V_48 -> V_72 = V_6 -> V_680 ++ ;
V_48 -> V_73 = V_162 ;
V_48 -> V_27 = V_27 ;
V_48 -> V_52 = V_52 ;
F_31 ( V_6 , V_48 ) ;
if ( ! V_6 -> V_635 ) {
V_20 = F_242 ( V_6 -> V_142 , V_162 ,
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
F_243 ( struct V_5 * V_6 , T_4 V_27 )
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
F_3 ( V_58 L_274
L_209 , V_6 -> V_35 , V_48 -> V_27 ,
( unsigned long long ) V_48 -> V_52 ) ;
F_19 ( & V_48 -> V_67 ) ;
F_20 ( V_48 ) ;
}
F_21 ( & V_6 -> V_76 , V_65 ) ;
if ( V_70 )
F_244 ( & V_70 -> V_157 ) ;
}
static void
F_245 ( struct V_5 * V_6 ,
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
F_246 ( V_70 , NULL , F_239 ) ;
}
static void
F_247 ( struct V_5 * V_6 ,
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
F_246 ( V_70 , ( void * ) 1 , F_239 ) ;
}
static void
F_248 ( struct V_5 * V_6 ,
T_26 * V_400 )
{
T_4 V_27 = F_9 ( V_400 -> V_409 ) ;
F_227 ( V_6 , V_27 ) ;
}
static void
F_249 ( struct V_5 * V_6 ,
T_26 * V_400 )
{
struct V_45 * V_46 ;
unsigned long V_65 ;
T_4 V_27 = F_9 ( V_400 -> V_409 ) ;
T_9 V_29 ;
T_8 V_28 ;
T_10 V_30 ;
T_1 V_9 ;
T_4 V_603 ;
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
V_603 = F_9 ( V_28 . V_605 ) ;
if ( ! F_11 ( V_6 , V_603 , & V_9 ) )
F_208 ( V_6 , V_9 , V_27 ,
V_28 . V_634 , V_585 ) ;
F_225 ( V_6 , V_27 , 0 , 1 ) ;
}
static void
F_250 ( struct V_5 * V_6 ,
T_25 * V_362 )
{
T_26 * V_400 ;
T_6 V_681 ;
int V_92 ;
char * V_646 = NULL , * V_682 = NULL ;
V_400 = ( T_26 * ) & V_362 -> V_401 [ 0 ] ;
F_3 ( V_58 L_275 ,
V_6 -> V_35 , ( F_69 ( V_362 -> V_171 ) &
V_407 ) ?
L_276 : L_277 , V_362 -> V_402 ) ;
for ( V_92 = 0 ; V_92 < V_362 -> V_402 ; V_92 ++ , V_400 ++ ) {
switch ( V_400 -> V_403 ) {
case V_683 :
V_646 = L_211 ;
break;
case V_405 :
V_646 = L_212 ;
break;
case V_684 :
V_646 = L_278 ;
break;
case V_685 :
V_646 = L_279 ;
break;
case V_408 :
V_646 = L_280 ;
break;
case V_686 :
V_646 = L_281 ;
break;
case V_404 :
V_646 = L_282 ;
break;
case V_687 :
V_646 = L_283 ;
break;
case V_688 :
V_646 = L_284 ;
break;
default:
V_646 = L_243 ;
break;
}
V_681 = F_9 ( V_400 -> V_689 ) &
V_690 ;
switch ( V_681 ) {
case V_691 :
V_682 = L_75 ;
break;
case V_692 :
V_682 = L_285 ;
break;
case V_693 :
V_682 = L_286 ;
break;
default:
V_682 = L_287 ;
break;
}
F_3 ( V_7 L_288
L_289 , V_682 ,
V_646 , F_9 ( V_400 -> V_406 ) ,
F_9 ( V_400 -> V_409 ) ,
V_400 -> V_220 ) ;
}
}
static void
F_251 ( struct V_5 * V_6 ,
struct V_340 * V_341 )
{
T_26 * V_400 ;
int V_92 ;
T_6 V_694 ;
T_25 * V_362 =
( T_25 * )
V_341 -> V_362 ;
#ifdef F_205
if ( ( V_6 -> V_8 & V_644 )
&& ! V_6 -> V_261 )
F_250 ( V_6 , V_362 ) ;
#endif
if ( V_6 -> V_304 )
return;
V_694 = ( F_69 ( V_362 -> V_171 ) &
V_407 ) ? 1 : 0 ;
V_400 = ( T_26 * ) & V_362 -> V_401 [ 0 ] ;
for ( V_92 = 0 ; V_92 < V_362 -> V_402 ; V_92 ++ , V_400 ++ ) {
switch ( V_400 -> V_403 ) {
case V_686 :
case V_683 :
if ( ! V_694 )
F_241 ( V_6 , V_400 ) ;
break;
case V_404 :
case V_405 :
if ( ! V_694 )
F_243 ( V_6 ,
F_9 ( V_400 -> V_406 ) ) ;
break;
case V_687 :
if ( ! V_6 -> V_163 )
F_247 ( V_6 , V_400 ) ;
break;
case V_688 :
if ( ! V_6 -> V_163 )
F_245 ( V_6 , V_400 ) ;
break;
case V_685 :
if ( ! V_6 -> V_163 )
F_249 ( V_6 , V_400 ) ;
break;
case V_408 :
if ( ! V_6 -> V_163 )
F_248 ( V_6 , V_400 ) ;
break;
}
}
}
static void
F_252 ( struct V_5 * V_6 ,
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
L_290 , V_6 -> V_35 , V_36 , V_27 ,
F_69 ( V_362 -> V_695 ) , V_188 ) ) ;
switch ( V_188 ) {
case V_198 :
case V_197 :
F_243 ( V_6 , V_27 ) ;
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
V_48 -> V_72 = V_6 -> V_680 ++ ;
V_48 -> V_73 = V_162 ;
V_48 -> V_27 = V_27 ;
V_48 -> V_52 = V_52 ;
F_31 ( V_6 , V_48 ) ;
V_20 = F_242 ( V_6 -> V_142 , V_162 ,
V_48 -> V_72 , 0 ) ;
if ( V_20 )
F_32 ( V_6 , V_48 ) ;
break;
case V_696 :
default:
break;
}
}
static void
F_253 ( struct V_5 * V_6 ,
struct V_340 * V_341 )
{
T_4 V_27 , V_603 ;
T_10 V_188 ;
struct V_45 * V_46 ;
unsigned long V_65 ;
T_9 V_29 ;
T_8 V_28 ;
T_10 V_30 ;
T_45 * V_362 =
( T_45 * )
V_341 -> V_362 ;
T_1 V_9 ;
if ( V_6 -> V_304 )
return;
if ( V_362 -> V_403 != V_697 )
return;
V_27 = F_9 ( V_362 -> V_409 ) ;
V_188 = F_69 ( V_362 -> V_411 ) ;
if ( ! V_6 -> V_261 )
F_23 ( V_6 , F_3 ( V_58 L_49
L_290 , V_6 -> V_35 , V_36 , V_27 ,
F_69 ( V_362 -> V_695 ) , V_188 ) ) ;
switch ( V_188 ) {
case V_698 :
case V_699 :
case V_700 :
case V_701 :
case V_702 :
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
V_603 = F_9 ( V_28 . V_605 ) ;
if ( ! F_11 ( V_6 , V_603 , & V_9 ) )
F_208 ( V_6 , V_9 , V_27 ,
V_28 . V_634 , V_585 ) ;
F_225 ( V_6 , V_27 , 0 , 1 ) ;
break;
case V_703 :
case V_704 :
case V_705 :
default:
break;
}
}
static void
F_254 ( struct V_5 * V_6 ,
T_46 * V_362 )
{
char * V_646 = NULL ;
switch ( V_362 -> V_706 ) {
case V_707 :
V_646 = L_291 ;
break;
case V_708 :
V_646 = L_292 ;
break;
case V_709 :
V_646 = L_293 ;
break;
case V_710 :
V_646 = L_294 ;
break;
case V_711 :
V_646 = L_295 ;
break;
}
if ( ! V_646 )
return;
F_3 ( V_58 L_296
L_297 ,
V_6 -> V_35 , V_646 ,
F_9 ( V_362 -> V_406 ) ,
V_362 -> V_712 ) ;
}
static void
F_255 ( struct V_5 * V_6 ,
struct V_340 * V_341 )
{
T_46 * V_362 =
( T_46 * )
V_341 -> V_362 ;
static struct V_47 * V_48 ;
unsigned long V_65 ;
T_4 V_27 ;
#ifdef F_205
if ( ( V_6 -> V_8 & V_644 )
&& ! V_6 -> V_261 )
F_254 ( V_6 ,
V_362 ) ;
#endif
if ( V_362 -> V_706 == V_707 ) {
F_18 ( & V_6 -> V_76 , V_65 ) ;
V_27 = F_9 ( V_362 -> V_406 ) ;
V_48 = F_29 ( V_6 , V_27 ) ;
if ( V_48 )
V_48 -> V_181 =
V_362 -> V_712 ;
F_21 ( & V_6 -> V_76 , V_65 ) ;
}
}
static void
F_256 ( struct V_5 * V_6 )
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
F_257 ( struct V_5 * V_6 , T_1 V_9 ,
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
V_46 -> V_713 = 1 ;
V_70 = V_46 -> V_70 ;
if ( V_70 && V_70 -> V_150 ) {
V_148 = V_70 -> V_150 ;
V_148 -> V_291 = 0 ;
V_148 -> V_375 = 0 ;
} else
V_148 = NULL ;
if ( V_70 )
F_121 ( V_7 , V_70 ,
L_298
L_299
L_300 , V_27 ,
( unsigned long long ) V_46 -> V_9 ,
( unsigned long long )
V_46 -> V_14 ,
V_46 -> V_18 ) ;
if ( V_46 -> V_27 == V_27 )
goto V_75;
F_3 ( V_7 L_301 ,
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
F_258 ( struct V_5 * V_6 )
{
T_8 V_28 ;
T_9 V_29 ;
T_4 V_30 ;
T_41 V_9 ;
T_4 V_27 ;
T_10 V_82 ;
T_4 V_18 ;
F_3 ( V_58 L_302 , V_6 -> V_35 ) ;
if ( F_43 ( & V_6 -> V_68 ) )
goto V_75;
V_27 = 0xFFFF ;
while ( ! ( F_12 ( V_6 , & V_29 ,
& V_28 , V_714 ,
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
V_18 = F_9 ( V_28 . V_544 ) ;
F_257 ( V_6 , V_9 , V_18 ,
V_27 ) ;
}
V_75:
F_3 ( V_58 L_303 ,
V_6 -> V_35 ) ;
}
static void
F_259 ( struct V_5 * V_6 , T_1 V_52 ,
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
V_48 -> V_713 = 1 ;
F_21 ( & V_6 -> V_76 , V_65 ) ;
F_121 ( V_7 , V_48 -> V_70 ,
L_304 , V_27 ,
( unsigned long long ) V_48 -> V_52 ) ;
F_85 ( V_6 , V_48 ) ;
F_18 ( & V_6 -> V_76 , V_65 ) ;
if ( V_48 -> V_27 == V_27 ) {
F_21 ( & V_6 -> V_76 ,
V_65 ) ;
return;
}
F_3 ( V_7 L_301 ,
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
F_260 ( struct V_5 * V_6 )
{
T_15 V_715 ;
T_13 V_716 ;
T_14 V_213 ;
T_9 V_29 ;
T_4 V_30 ;
T_4 V_27 ;
T_6 V_717 ;
if ( ! V_6 -> V_718 )
return;
F_3 ( V_58 L_305 ,
V_6 -> V_35 ) ;
if ( F_43 ( & V_6 -> V_77 ) )
goto V_75;
V_27 = 0xFFFF ;
while ( ! ( F_83 ( V_6 , & V_29 ,
& V_715 , V_223 , V_27 ) ) ) {
V_30 = F_9 ( V_29 . V_38 ) &
V_39 ;
if ( V_30 != V_40 )
break;
V_27 = F_9 ( V_715 . V_221 ) ;
if ( F_73 ( V_6 , & V_29 ,
& V_716 , V_182 , V_27 ,
sizeof( T_13 ) ) )
continue;
if ( V_716 . V_191 == V_192 ||
V_716 . V_191 == V_193 ||
V_716 . V_191 == V_195 )
F_259 ( V_6 ,
F_6 ( V_715 . V_719 ) , V_27 ) ;
}
if ( ! V_6 -> V_163 ) {
V_717 = 0xFF ;
memset ( V_6 -> V_166 , 0 , V_6 -> V_720 ) ;
while ( ! ( F_81 ( V_6 , & V_29 ,
& V_213 , V_721 ,
V_717 ) ) ) {
V_30 = F_9 ( V_29 . V_38 ) &
V_39 ;
if ( V_30 != V_40 )
break;
V_717 = V_213 . V_220 ;
V_27 = F_9 ( V_213 . V_221 ) ;
F_144 ( V_27 , V_6 -> V_166 ) ;
}
}
V_75:
F_3 ( V_58 L_306
L_307 , V_6 -> V_35 ) ;
}
static void
F_261 ( struct V_5 * V_6 , T_1 V_9 ,
T_4 V_27 )
{
struct V_78 * V_79 ;
unsigned long V_65 ;
int V_92 ;
F_18 ( & V_6 -> V_80 , V_65 ) ;
F_4 (sas_expander, &ioc->sas_expander_list, list) {
if ( V_79 -> V_9 != V_9 )
continue;
V_79 -> V_713 = 1 ;
if ( V_79 -> V_27 == V_27 )
goto V_75;
F_3 ( V_7 L_308
L_309 ,
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
F_262 ( struct V_5 * V_6 )
{
T_39 V_601 ;
T_9 V_29 ;
T_4 V_30 ;
T_1 V_9 ;
T_4 V_27 ;
F_3 ( V_58 L_310 , V_6 -> V_35 ) ;
if ( F_43 ( & V_6 -> V_81 ) )
goto V_75;
V_27 = 0xFFFF ;
while ( ! ( F_217 ( V_6 , & V_29 , & V_601 ,
V_722 , V_27 ) ) ) {
V_30 = F_9 ( V_29 . V_38 ) &
V_39 ;
if ( V_30 != V_40 )
break;
V_27 = F_9 ( V_601 . V_221 ) ;
V_9 = F_6 ( V_601 . V_11 ) ;
F_3 ( V_7 L_311
L_312 , V_27 ,
( unsigned long long ) V_9 ) ;
F_261 ( V_6 , V_9 , V_27 ) ;
}
V_75:
F_3 ( V_58 L_313 , V_6 -> V_35 ) ;
}
static void
F_263 ( struct V_5 * V_6 )
{
struct V_45 * V_46 , * V_723 ;
struct V_78 * V_79 , * V_724 ;
struct V_47 * V_48 , * V_725 ;
struct V_726 V_727 ;
unsigned long V_65 ;
F_3 ( V_58 L_314 ,
V_6 -> V_35 ) ;
F_3 ( V_58 L_315 ,
V_6 -> V_35 ) ;
F_135 (sas_device, sas_device_next,
&ioc->sas_device_list, list) {
if ( ! V_46 -> V_713 )
F_228 ( V_6 ,
V_46 -> V_9 ) ;
else
V_46 -> V_713 = 0 ;
}
if ( V_6 -> V_718 ) {
F_3 ( V_58 L_316
L_317 , V_6 -> V_35 ) ;
F_135 (raid_device, raid_device_next,
&ioc->raid_device_list, list) {
if ( ! V_48 -> V_713 )
F_243 ( V_6 ,
V_48 -> V_27 ) ;
else
V_48 -> V_713 = 0 ;
}
}
F_3 ( V_58 L_318 ,
V_6 -> V_35 ) ;
F_18 ( & V_6 -> V_80 , V_65 ) ;
F_147 ( & V_727 ) ;
F_135 (sas_expander, sas_expander_next,
&ioc->sas_expander_list, list) {
if ( ! V_79 -> V_713 )
F_264 ( & V_79 -> V_67 , & V_727 ) ;
else
V_79 -> V_713 = 0 ;
}
F_21 ( & V_6 -> V_80 , V_65 ) ;
F_135 (sas_expander, sas_expander_next, &tmp_list,
list) {
F_19 ( & V_79 -> V_67 ) ;
F_222 ( V_6 , V_79 ) ;
}
F_3 ( V_58 L_319 ,
V_6 -> V_35 ) ;
F_137 ( V_6 ) ;
}
static void
F_265 ( struct V_5 * V_6 ,
struct V_78 * V_79 , T_4 V_27 )
{
T_40 V_602 ;
T_9 V_29 ;
int V_92 ;
for ( V_92 = 0 ; V_92 < V_79 -> V_32 ; V_92 ++ ) {
if ( ( F_218 ( V_6 , & V_29 ,
& V_602 , V_92 , V_27 ) ) ) {
F_3 ( V_34 L_2 ,
V_6 -> V_35 , __FILE__ , __LINE__ , V_36 ) ;
return;
}
F_208 ( V_6 , V_79 -> V_9 ,
F_9 ( V_602 . V_367 ) , V_92 ,
V_602 . V_583 >> 4 ) ;
}
}
static void
F_266 ( struct V_5 * V_6 )
{
T_39 V_601 ;
T_8 V_28 ;
T_15 V_715 ;
T_13 V_716 ;
T_14 V_213 ;
T_26 V_400 ;
T_9 V_29 ;
T_6 V_717 ;
T_4 V_30 ;
T_4 V_27 , V_603 ;
T_1 V_9 ;
struct V_45 * V_46 ;
struct V_78 * V_728 ;
static struct V_47 * V_48 ;
T_6 V_729 ;
unsigned long V_65 ;
F_3 ( V_58 L_320 , V_6 -> V_35 ) ;
F_206 ( V_6 ) ;
F_3 ( V_58 L_321 ,
V_6 -> V_35 ) ;
V_27 = 0xFFFF ;
while ( ! ( F_217 ( V_6 , & V_29 , & V_601 ,
V_722 , V_27 ) ) ) {
V_30 = F_9 ( V_29 . V_38 ) &
V_39 ;
if ( V_30 != V_40 ) {
F_3 ( V_58 L_322
L_323 ,
V_6 -> V_35 , V_30 ,
F_69 ( V_29 . V_324 ) ) ;
break;
}
V_27 = F_9 ( V_601 . V_221 ) ;
F_18 ( & V_6 -> V_80 , V_65 ) ;
V_728 = F_34 (
V_6 , F_6 ( V_601 . V_11 ) ) ;
F_21 ( & V_6 -> V_80 , V_65 ) ;
if ( V_728 )
F_265 ( V_6 , V_728 ,
V_27 ) ;
else {
F_3 ( V_58 L_324
L_325 ,
V_6 -> V_35 , V_27 , ( unsigned long long )
F_6 ( V_601 . V_11 ) ) ;
F_216 ( V_6 , V_27 ) ;
F_3 ( V_58 L_326
L_325 ,
V_6 -> V_35 , V_27 , ( unsigned long long )
F_6 ( V_601 . V_11 ) ) ;
}
}
F_3 ( V_58 L_327 ,
V_6 -> V_35 ) ;
if ( ! V_6 -> V_718 )
goto V_730;
F_3 ( V_58 L_328 , V_6 -> V_35 ) ;
V_717 = 0xFF ;
while ( ! ( F_81 ( V_6 , & V_29 ,
& V_213 , V_721 ,
V_717 ) ) ) {
V_30 = F_9 ( V_29 . V_38 ) &
V_39 ;
if ( V_30 != V_40 ) {
F_3 ( V_58 L_329
L_323 ,
V_6 -> V_35 , V_30 ,
F_69 ( V_29 . V_324 ) ) ;
break;
}
V_717 = V_213 . V_220 ;
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
F_3 ( V_58 L_330
L_323 ,
V_6 -> V_35 , V_30 ,
F_69 ( V_29 . V_324 ) ) ;
break;
}
V_603 = F_9 ( V_28 . V_605 ) ;
if ( ! F_11 ( V_6 , V_603 ,
& V_9 ) ) {
F_3 ( V_58 L_331
L_332 ,
V_6 -> V_35 , V_27 , ( unsigned long long )
F_6 ( V_28 . V_11 ) ) ;
F_208 ( V_6 , V_9 ,
V_27 , V_28 . V_634 ,
V_585 ) ;
F_144 ( V_27 , V_6 -> V_166 ) ;
V_729 = 0 ;
while ( F_225 ( V_6 , V_27 , V_729 ++ ,
1 ) ) {
F_238 ( 1 ) ;
}
F_3 ( V_58 L_333
L_332 ,
V_6 -> V_35 , V_27 , ( unsigned long long )
F_6 ( V_28 . V_11 ) ) ;
}
}
F_3 ( V_58 L_334 ,
V_6 -> V_35 ) ;
F_3 ( V_58 L_335 , V_6 -> V_35 ) ;
V_27 = 0xFFFF ;
while ( ! ( F_83 ( V_6 , & V_29 ,
& V_715 , V_223 , V_27 ) ) ) {
V_30 = F_9 ( V_29 . V_38 ) &
V_39 ;
if ( V_30 != V_40 ) {
F_3 ( V_58 L_336
L_323 ,
V_6 -> V_35 , V_30 ,
F_69 ( V_29 . V_324 ) ) ;
break;
}
V_27 = F_9 ( V_715 . V_221 ) ;
F_18 ( & V_6 -> V_76 , V_65 ) ;
V_48 = F_30 ( V_6 ,
F_6 ( V_715 . V_719 ) ) ;
F_21 ( & V_6 -> V_76 , V_65 ) ;
if ( V_48 )
continue;
if ( F_73 ( V_6 , & V_29 ,
& V_716 , V_182 , V_27 ,
sizeof( T_13 ) ) )
continue;
V_30 = F_9 ( V_29 . V_38 ) &
V_39 ;
if ( V_30 != V_40 ) {
F_3 ( V_58 L_336
L_323 ,
V_6 -> V_35 , V_30 ,
F_69 ( V_29 . V_324 ) ) ;
break;
}
if ( V_716 . V_191 == V_192 ||
V_716 . V_191 == V_193 ||
V_716 . V_191 == V_195 ) {
memset ( & V_400 , 0 , sizeof( T_26 ) ) ;
V_400 . V_403 = V_683 ;
V_400 . V_406 = V_715 . V_221 ;
F_3 ( V_58 L_337
L_338 , V_6 -> V_35 ,
V_715 . V_221 ) ;
F_241 ( V_6 , & V_400 ) ;
F_3 ( V_58 L_339
L_338 , V_6 -> V_35 ,
V_715 . V_221 ) ;
}
}
F_3 ( V_58 L_340 ,
V_6 -> V_35 ) ;
V_730:
F_3 ( V_58 L_341 ,
V_6 -> V_35 ) ;
V_27 = 0xFFFF ;
while ( ! ( F_12 ( V_6 , & V_29 ,
& V_28 , V_714 ,
V_27 ) ) ) {
V_30 = F_9 ( V_29 . V_38 ) &
V_39 ;
if ( V_30 != V_40 ) {
F_3 ( V_58 L_342
L_343 ,
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
V_603 = F_9 ( V_28 . V_605 ) ;
if ( ! F_11 ( V_6 , V_603 , & V_9 ) ) {
F_3 ( V_58 L_344
L_325 ,
V_6 -> V_35 , V_27 , ( unsigned long long )
F_6 ( V_28 . V_11 ) ) ;
F_208 ( V_6 , V_9 , V_27 ,
V_28 . V_634 , V_585 ) ;
V_729 = 0 ;
while ( F_225 ( V_6 , V_27 , V_729 ++ ,
0 ) ) {
F_238 ( 1 ) ;
}
F_3 ( V_58 L_345
L_325 ,
V_6 -> V_35 , V_27 , ( unsigned long long )
F_6 ( V_28 . V_11 ) ) ;
}
}
F_3 ( V_58 L_346 ,
V_6 -> V_35 ) ;
F_3 ( V_58 L_347 , V_6 -> V_35 ) ;
}
void
F_267 ( struct V_5 * V_6 , int V_731 )
{
switch ( V_731 ) {
case V_732 :
F_111 ( V_6 , F_3 ( V_58 L_52
L_348 , V_6 -> V_35 , V_36 ) ) ;
break;
case V_733 :
F_111 ( V_6 , F_3 ( V_58 L_52
L_349 , V_6 -> V_35 , V_36 ) ) ;
if ( V_6 -> V_609 . V_283 & V_288 ) {
V_6 -> V_609 . V_283 |= V_323 ;
F_157 ( V_6 , V_6 -> V_609 . V_88 ) ;
F_100 ( & V_6 -> V_609 . V_289 ) ;
}
if ( V_6 -> V_282 . V_283 & V_288 ) {
V_6 -> V_282 . V_283 |= V_323 ;
F_157 ( V_6 , V_6 -> V_282 . V_88 ) ;
F_100 ( & V_6 -> V_282 . V_289 ) ;
}
F_133 ( V_6 ) ;
F_167 ( V_6 ) ;
break;
case V_734 :
F_111 ( V_6 , F_3 ( V_58 L_52
L_350 , V_6 -> V_35 , V_36 ) ) ;
F_206 ( V_6 ) ;
F_256 ( V_6 ) ;
F_258 ( V_6 ) ;
F_260 ( V_6 ) ;
F_262 ( V_6 ) ;
if ( ( ! V_6 -> V_49 ) && ! ( V_679 > 0 &&
! V_6 -> V_31 . V_32 ) ) {
F_256 ( V_6 ) ;
F_258 ( V_6 ) ;
F_260 ( V_6 ) ;
F_262 ( V_6 ) ;
F_131 ( V_6 ) ;
}
break;
}
}
static void
V_346 ( struct V_735 * V_736 )
{
struct V_340 * V_341 = F_268 ( V_736 ,
struct V_340 , V_345 . V_736 ) ;
struct V_5 * V_6 = V_341 -> V_6 ;
if ( V_6 -> V_305 ||
V_6 -> V_306 ) {
F_130 ( V_6 , V_341 ) ;
return;
}
switch ( V_341 -> V_348 ) {
case V_349 :
while ( F_269 ( V_6 -> V_142 ) || V_6 -> V_304 )
F_238 ( 1 ) ;
F_263 ( V_6 ) ;
F_266 ( V_6 ) ;
break;
case V_350 :
V_6 -> V_737 = 0 ;
if ( V_738 [ 0 ] != - 1 && V_738 [ 1 ] != - 1 )
F_270 ( V_6 , V_738 [ 0 ] ,
V_738 [ 1 ] ) ;
F_23 ( V_6 , F_3 ( V_58 L_351
L_352 , V_6 -> V_35 ) ) ;
break;
case V_548 :
F_193 ( V_6 , V_341 -> V_549 ) ;
break;
case V_395 :
F_230 ( V_6 , V_341 ) ;
break;
case V_558 :
F_232 ( V_6 ,
V_341 ) ;
break;
case V_739 :
F_237 ( V_6 ,
V_341 ) ;
break;
case V_740 :
F_235 ( V_6 ,
V_341 ) ;
break;
case V_741 :
F_234 ( V_6 ,
V_341 ) ;
break;
case V_742 :
F_251 ( V_6 , V_341 ) ;
break;
case V_743 :
F_252 ( V_6 , V_341 ) ;
break;
case V_744 :
F_253 ( V_6 , V_341 ) ;
break;
case V_745 :
F_255 ( V_6 , V_341 ) ;
break;
}
F_130 ( V_6 , V_341 ) ;
}
void
F_271 ( struct V_5 * V_6 , T_6 V_280 ,
T_10 V_281 )
{
struct V_340 * V_341 ;
T_32 * V_29 ;
T_4 V_348 ;
T_4 V_214 ;
if ( V_6 -> V_305 || V_6 -> V_306 )
return;
V_29 = F_99 ( V_6 , V_281 ) ;
if ( F_152 ( ! V_29 ) ) {
F_3 ( V_34 L_114 ,
V_6 -> V_35 , __FILE__ , __LINE__ , V_36 ) ;
return;
}
V_348 = F_9 ( V_29 -> V_557 ) ;
switch ( V_348 ) {
case V_740 :
{
T_43 * V_746 =
( T_43 * )
V_29 -> V_555 ;
if ( V_746 -> V_747 !=
V_748 )
return;
if ( V_6 -> V_676 ) {
V_6 -> V_675 ++ ;
return;
} else
V_6 -> V_676 = 1 ;
break;
}
case V_395 :
F_158 ( V_6 ,
( T_22 * )
V_29 -> V_555 ) ;
break;
case V_742 :
F_162 ( V_6 ,
( T_25 * )
V_29 -> V_555 ) ;
break;
case V_743 :
F_165 ( V_6 ,
( T_27 * )
V_29 -> V_555 ) ;
break;
case V_749 :
{
T_47 * V_750 ;
T_48 * V_751 ;
if ( ! V_6 -> V_163 )
break;
V_750 = ( T_47 * )
V_29 -> V_555 ;
V_751 = ( T_48 * ) V_750 -> V_752 ;
if ( F_9 ( V_750 -> V_753 )
!= V_754 )
break;
switch ( F_69 ( * V_751 ) ) {
case V_755 :
F_3 ( V_99 L_353
L_354
L_355
L_356 , V_6 -> V_35 ) ;
break;
case V_756 :
F_3 ( V_99 L_353
L_357
L_358
L_359 , V_6 -> V_35 ) ;
break;
case V_757 :
F_3 ( V_34 L_360
L_361
L_362
L_363
L_359 , V_6 -> V_35 ) ;
break;
case V_758 :
F_3 ( V_34 L_360
L_364
L_365
L_366 ,
V_6 -> V_35 ) ;
break;
}
break;
}
case V_558 :
case V_745 :
case V_739 :
case V_741 :
case V_744 :
break;
case V_759 :
F_166 ( V_6 ,
( T_28 * )
V_29 -> V_555 ) ;
break;
default:
return;
}
V_214 = F_9 ( V_29 -> V_559 ) * 4 ;
V_341 = F_62 ( sizeof( * V_341 ) + V_214 , V_347 ) ;
if ( ! V_341 ) {
F_3 ( V_34 L_2 ,
V_6 -> V_35 , __FILE__ , __LINE__ , V_36 ) ;
return;
}
memcpy ( V_341 -> V_362 , V_29 -> V_555 , V_214 ) ;
V_341 -> V_6 = V_6 ;
V_341 -> V_486 = V_29 -> V_486 ;
V_341 -> V_487 = V_29 -> V_487 ;
V_341 -> V_348 = V_348 ;
F_127 ( V_6 , V_341 ) ;
return;
}
static void
F_222 ( struct V_5 * V_6 ,
struct V_78 * V_79 )
{
struct V_353 * V_354 , * V_100 ;
F_135 (mpt2sas_port, next,
&sas_expander->sas_port_list, port_list) {
if ( V_6 -> V_304 )
return;
if ( V_354 -> V_356 . V_357 ==
V_358 )
F_228 ( V_6 ,
V_354 -> V_356 . V_9 ) ;
else if ( V_354 -> V_356 . V_357 ==
V_360 ||
V_354 -> V_356 . V_357 ==
V_361 )
F_221 ( V_6 ,
V_354 -> V_356 . V_9 ) ;
}
F_26 ( V_6 , V_79 -> V_9 ,
V_79 -> V_69 ) ;
F_3 ( V_58 L_367
L_8 , V_6 -> V_35 ,
V_79 -> V_27 , ( unsigned long long )
V_79 -> V_9 ) ;
F_20 ( V_79 -> V_262 ) ;
F_20 ( V_79 ) ;
}
static void
F_272 ( struct V_5 * V_6 )
{
T_49 * V_103 ;
T_50 * V_29 ;
T_4 V_88 ;
if ( ! V_6 -> V_718 )
return;
F_105 ( & V_6 -> V_609 . V_301 ) ;
if ( V_6 -> V_609 . V_283 != V_284 ) {
F_3 ( V_34 L_368 ,
V_6 -> V_35 , V_36 ) ;
goto V_75;
}
V_6 -> V_609 . V_283 = V_288 ;
V_88 = F_155 ( V_6 , V_6 -> V_760 ) ;
if ( ! V_88 ) {
F_3 ( V_34 L_68 ,
V_6 -> V_35 , V_36 ) ;
V_6 -> V_609 . V_283 = V_284 ;
goto V_75;
}
V_103 = F_48 ( V_6 , V_88 ) ;
V_6 -> V_609 . V_88 = V_88 ;
memset ( V_103 , 0 , sizeof( T_49 ) ) ;
V_103 -> V_316 = V_761 ;
V_103 -> V_538 = V_762 ;
if ( ! V_6 -> V_261 )
F_3 ( V_58 L_369 , V_6 -> V_35 ) ;
F_114 ( & V_6 -> V_609 . V_289 ) ;
F_156 ( V_6 , V_88 ) ;
F_116 ( & V_6 -> V_609 . V_289 , 10 * V_322 ) ;
if ( ! ( V_6 -> V_609 . V_283 & V_285 ) ) {
F_3 ( V_34 L_71 ,
V_6 -> V_35 , V_36 ) ;
goto V_75;
}
if ( V_6 -> V_609 . V_283 & V_287 ) {
V_29 = V_6 -> V_609 . V_281 ;
if ( ! V_6 -> V_261 )
F_3 ( V_58 L_370
L_323 ,
V_6 -> V_35 , F_9 ( V_29 -> V_38 ) ,
F_69 ( V_29 -> V_324 ) ) ;
}
V_75:
V_6 -> V_609 . V_283 = V_284 ;
F_118 ( & V_6 -> V_609 . V_301 ) ;
}
static void
F_273 ( struct V_763 * V_552 )
{
struct V_141 * V_142 = F_274 ( V_552 ) ;
struct V_5 * V_6 = F_58 ( V_142 ) ;
struct V_764 * V_765 ;
unsigned long V_65 ;
V_6 -> V_305 = 1 ;
F_133 ( V_6 ) ;
F_18 ( & V_6 -> V_343 , V_65 ) ;
V_765 = V_6 -> V_342 ;
V_6 -> V_342 = NULL ;
F_21 ( & V_6 -> V_343 , V_65 ) ;
if ( V_765 )
F_275 ( V_765 ) ;
F_272 ( V_6 ) ;
F_276 ( V_6 ) ;
}
static void
F_277 ( struct V_763 * V_552 )
{
struct V_141 * V_142 = F_274 ( V_552 ) ;
struct V_5 * V_6 = F_58 ( V_142 ) ;
struct V_353 * V_354 , * V_766 ;
struct V_47 * V_48 , * V_100 ;
struct V_147 * V_148 ;
struct V_764 * V_765 ;
unsigned long V_65 ;
V_6 -> V_305 = 1 ;
F_133 ( V_6 ) ;
F_18 ( & V_6 -> V_343 , V_65 ) ;
V_765 = V_6 -> V_342 ;
V_6 -> V_342 = NULL ;
F_21 ( & V_6 -> V_343 , V_65 ) ;
if ( V_765 )
F_275 ( V_765 ) ;
F_272 ( V_6 ) ;
F_135 (raid_device, next, &ioc->raid_device_list,
list) {
if ( V_48 -> V_70 ) {
V_148 =
V_48 -> V_70 -> V_150 ;
V_148 -> V_375 = 1 ;
F_244 ( & V_48 -> V_70 -> V_157 ) ;
}
F_3 ( V_58 L_274
L_209 , V_6 -> V_35 , V_48 -> V_27 ,
( unsigned long long ) V_48 -> V_52 ) ;
F_32 ( V_6 , V_48 ) ;
}
F_135 (mpt2sas_port, next_port,
&ioc->sas_hba.sas_port_list, port_list) {
if ( V_354 -> V_356 . V_357 ==
V_358 )
F_228 ( V_6 ,
V_354 -> V_356 . V_9 ) ;
else if ( V_354 -> V_356 . V_357 ==
V_360 ||
V_354 -> V_356 . V_357 ==
V_361 )
F_221 ( V_6 ,
V_354 -> V_356 . V_9 ) ;
}
if ( V_6 -> V_31 . V_32 ) {
F_20 ( V_6 -> V_31 . V_262 ) ;
V_6 -> V_31 . V_262 = NULL ;
V_6 -> V_31 . V_32 = 0 ;
}
F_278 ( V_142 ) ;
F_279 ( V_142 ) ;
F_276 ( V_6 ) ;
F_19 ( & V_6 -> V_67 ) ;
F_280 ( V_142 ) ;
}
static void
F_281 ( struct V_5 * V_6 )
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
V_20 = F_242 ( V_6 -> V_142 , V_162 ,
V_48 -> V_72 , 0 ) ;
if ( V_20 )
F_32 ( V_6 , V_48 ) ;
} else {
F_18 ( & V_6 -> V_66 , V_65 ) ;
V_46 = V_43 ;
V_27 = V_46 -> V_27 ;
V_69 = V_46 -> V_69 ;
V_9 = V_46 -> V_9 ;
F_264 ( & V_46 -> V_67 , & V_6 -> V_68 ) ;
F_21 ( & V_6 -> V_66 , V_65 ) ;
if ( V_6 -> V_636 )
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
F_282 ( struct V_5 * V_6 )
{
struct V_47 * V_48 , * V_767 ;
int V_20 ;
F_135 (raid_device, raid_next,
&ioc->raid_device_list, list) {
if ( V_48 -> V_70 )
continue;
V_20 = F_242 ( V_6 -> V_142 , V_162 ,
V_48 -> V_72 , 0 ) ;
if ( V_20 )
F_32 ( V_6 , V_48 ) ;
}
}
static void
F_283 ( struct V_5 * V_6 )
{
struct V_45 * V_46 , * V_100 ;
unsigned long V_65 ;
F_135 (sas_device, next, &ioc->sas_device_init_list,
list) {
if ( V_6 -> V_636 )
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
F_264 ( & V_46 -> V_67 , & V_6 -> V_68 ) ;
F_21 ( & V_6 -> V_66 , V_65 ) ;
}
}
static void
F_284 ( struct V_5 * V_6 )
{
T_4 V_768 ;
if ( ! ( V_6 -> V_245 . V_769 & V_770 ) )
return;
F_281 ( V_6 ) ;
if ( V_6 -> V_718 ) {
V_768 =
F_9 ( V_6 -> V_771 . V_772 ) &
V_773 ;
if ( V_768 ==
V_774 ) {
F_282 ( V_6 ) ;
F_283 ( V_6 ) ;
} else {
F_283 ( V_6 ) ;
F_282 ( V_6 ) ;
}
} else
F_283 ( V_6 ) ;
}
static void
F_285 ( struct V_141 * V_142 )
{
struct V_5 * V_6 = F_58 ( V_142 ) ;
int V_20 ;
if ( V_775 != - 1 && V_775 != 0 )
F_286 ( V_6 , V_775 ) ;
if ( V_679 > 0 )
return;
V_6 -> V_737 = 1 ;
V_20 = F_287 ( V_6 ) ;
if ( V_20 != 0 )
F_3 ( V_58 L_371 , V_6 -> V_35 ) ;
}
static int
F_288 ( struct V_141 * V_142 , unsigned long time )
{
struct V_5 * V_6 = F_58 ( V_142 ) ;
if ( V_679 > 0 ) {
V_6 -> V_49 = 0 ;
V_6 -> V_635 = 0 ;
return 1 ;
}
if ( time >= ( 300 * V_322 ) ) {
V_6 -> V_776 . V_283 = V_284 ;
F_3 ( V_58 L_372
L_373 , V_6 -> V_35 ) ;
V_6 -> V_49 = 0 ;
return 1 ;
}
if ( V_6 -> V_737 )
return 0 ;
if ( V_6 -> V_777 ) {
F_3 ( V_58 L_374
L_375 , V_6 -> V_35 , V_6 -> V_777 ) ;
V_6 -> V_49 = 0 ;
V_6 -> V_635 = 0 ;
V_6 -> V_305 = 1 ;
return 1 ;
}
F_3 ( V_58 L_376 , V_6 -> V_35 ) ;
V_6 -> V_776 . V_283 = V_284 ;
if ( V_6 -> V_635 ) {
V_6 -> V_635 = 0 ;
F_284 ( V_6 ) ;
}
F_289 ( V_6 ) ;
V_6 -> V_49 = 0 ;
return 1 ;
}
static int
F_290 ( struct V_763 * V_552 , const struct V_778 * V_72 )
{
struct V_5 * V_6 ;
struct V_141 * V_142 ;
int V_779 ;
V_142 = F_291 ( & V_780 ,
sizeof( struct V_5 ) ) ;
if ( ! V_142 )
return - V_781 ;
V_6 = F_58 ( V_142 ) ;
memset ( V_6 , 0 , sizeof( struct V_5 ) ) ;
F_147 ( & V_6 -> V_67 ) ;
F_24 ( & V_6 -> V_67 , & V_782 ) ;
V_6 -> V_142 = V_142 ;
V_6 -> V_72 = V_783 ++ ;
sprintf ( V_6 -> V_35 , L_377 , V_784 , V_6 -> V_72 ) ;
V_6 -> V_552 = V_552 ;
if ( V_72 -> V_43 == V_785 ) {
V_6 -> V_163 = 1 ;
V_6 -> V_261 = 1 ;
} else
V_6 -> V_232 = V_233 ;
V_6 -> V_470 = V_470 ;
V_6 -> V_314 = V_314 ;
V_6 -> V_786 = V_786 ;
V_6 -> V_787 = V_787 ;
V_6 -> V_788 = V_788 ;
V_6 -> V_789 = V_789 ;
V_6 -> V_760 = V_760 ;
V_6 -> V_790 = V_790 ;
V_6 -> V_376 = V_376 ;
V_6 -> V_378 = V_378 ;
V_6 -> V_382 = V_382 ;
V_6 -> V_8 = V_8 ;
V_6 -> V_791 = & F_167 ;
F_292 ( & V_6 -> V_792 ) ;
F_293 ( & V_6 -> V_793 ) ;
F_293 ( & V_6 -> V_91 ) ;
F_293 ( & V_6 -> V_66 ) ;
F_293 ( & V_6 -> V_80 ) ;
F_293 ( & V_6 -> V_343 ) ;
F_293 ( & V_6 -> V_76 ) ;
F_147 ( & V_6 -> V_68 ) ;
F_147 ( & V_6 -> V_71 ) ;
F_147 ( & V_6 -> V_81 ) ;
F_147 ( & V_6 -> V_344 ) ;
F_147 ( & V_6 -> V_77 ) ;
F_147 ( & V_6 -> V_31 . V_608 ) ;
F_147 ( & V_6 -> V_377 ) ;
F_147 ( & V_6 -> V_379 ) ;
F_147 ( & V_6 -> V_794 ) ;
V_142 -> V_795 = 32 ;
V_142 -> V_796 = V_796 ;
V_142 -> V_797 = V_798 ;
V_142 -> V_799 = V_6 -> V_72 ;
if ( V_800 != 0xFFFF ) {
if ( V_800 < 64 ) {
V_142 -> V_800 = 64 ;
F_3 ( V_99 L_378
L_379
L_380 , V_6 -> V_35 , V_800 ) ;
} else if ( V_800 > 32767 ) {
V_142 -> V_800 = 32767 ;
F_3 ( V_99 L_378
L_381
L_382 , V_6 -> V_35 ,
V_800 ) ;
} else {
V_142 -> V_800 = V_800 & 0xFFFE ;
F_3 ( V_58 L_383
L_384 , V_6 -> V_35 , V_142 -> V_800 ) ;
}
}
if ( V_801 )
F_294 ( V_142 , V_801 ) ;
else
F_294 ( V_142 , V_802
| V_803
| V_804 ) ;
F_295 ( V_142 , V_805 ) ;
snprintf ( V_6 -> V_806 , sizeof( V_6 -> V_806 ) ,
L_385 , V_6 -> V_72 ) ;
V_6 -> V_342 = F_296 (
V_6 -> V_806 ) ;
if ( ! V_6 -> V_342 ) {
F_3 ( V_34 L_2 ,
V_6 -> V_35 , __FILE__ , __LINE__ , V_36 ) ;
V_779 = - V_781 ;
goto V_807;
}
V_6 -> V_49 = 1 ;
if ( ( F_297 ( V_6 ) ) ) {
F_3 ( V_34 L_2 ,
V_6 -> V_35 , __FILE__ , __LINE__ , V_36 ) ;
V_779 = - V_781 ;
goto V_808;
}
if ( V_6 -> V_163 ) {
if ( V_6 -> V_232 == V_233 )
V_6 -> V_636 = 0 ;
else if ( V_6 -> V_232 == V_809 )
V_6 -> V_636 = 1 ;
else {
if ( F_84 ( V_6 ) )
V_6 -> V_636 = 1 ;
else
V_6 -> V_636 = 0 ;
}
} else
V_6 -> V_636 = 0 ;
V_779 = F_298 ( V_142 , & V_552 -> V_157 ) ;
if ( V_779 ) {
F_3 ( V_34 L_2 ,
V_6 -> V_35 , __FILE__ , __LINE__ , V_36 ) ;
goto V_810;
}
F_299 ( V_142 ) ;
return 0 ;
V_810:
F_276 ( V_6 ) ;
V_808:
F_275 ( V_6 -> V_342 ) ;
V_807:
F_19 ( & V_6 -> V_67 ) ;
F_280 ( V_142 ) ;
return V_779 ;
}
static int
F_300 ( struct V_763 * V_552 , T_51 V_188 )
{
struct V_141 * V_142 = F_274 ( V_552 ) ;
struct V_5 * V_6 = F_58 ( V_142 ) ;
T_52 V_811 ;
F_301 ( V_6 ) ;
F_302 ( V_142 ) ;
F_272 ( V_6 ) ;
V_811 = F_303 ( V_552 , V_188 ) ;
F_3 ( V_58 L_386
L_387 , V_6 -> V_35 , V_552 ,
F_304 ( V_552 ) , V_811 ) ;
F_305 ( V_6 ) ;
F_306 ( V_552 ) ;
F_307 ( V_552 , V_811 ) ;
return 0 ;
}
static int
F_308 ( struct V_763 * V_552 )
{
struct V_141 * V_142 = F_274 ( V_552 ) ;
struct V_5 * V_6 = F_58 ( V_142 ) ;
T_52 V_811 = V_552 -> V_812 ;
int V_74 ;
F_3 ( V_58 L_388
L_387 , V_6 -> V_35 , V_552 ,
F_304 ( V_552 ) , V_811 ) ;
F_307 ( V_552 , V_813 ) ;
F_309 ( V_552 , V_813 , 0 ) ;
F_310 ( V_552 ) ;
V_6 -> V_552 = V_552 ;
V_74 = F_311 ( V_6 ) ;
if ( V_74 )
return V_74 ;
F_108 ( V_6 , V_308 , V_814 ) ;
F_312 ( V_142 ) ;
F_289 ( V_6 ) ;
return 0 ;
}
static T_53
F_313 ( struct V_763 * V_552 , T_54 V_188 )
{
struct V_141 * V_142 = F_274 ( V_552 ) ;
struct V_5 * V_6 = F_58 ( V_142 ) ;
F_3 ( V_58 L_389 ,
V_6 -> V_35 , V_188 ) ;
switch ( V_188 ) {
case V_815 :
return V_816 ;
case V_817 :
V_6 -> V_306 = 1 ;
F_302 ( V_6 -> V_142 ) ;
F_301 ( V_6 ) ;
F_305 ( V_6 ) ;
return V_818 ;
case V_819 :
V_6 -> V_306 = 1 ;
F_301 ( V_6 ) ;
F_167 ( V_6 ) ;
return V_820 ;
}
return V_818 ;
}
static T_53
F_314 ( struct V_763 * V_552 )
{
struct V_141 * V_142 = F_274 ( V_552 ) ;
struct V_5 * V_6 = F_58 ( V_142 ) ;
int V_20 ;
F_3 ( V_58 L_390 ,
V_6 -> V_35 ) ;
V_6 -> V_306 = 0 ;
V_6 -> V_552 = V_552 ;
F_310 ( V_552 ) ;
V_20 = F_311 ( V_6 ) ;
if ( V_20 )
return V_820 ;
V_20 = F_108 ( V_6 , V_308 ,
V_309 ) ;
F_3 ( V_99 L_391 , V_6 -> V_35 ,
( V_20 == 0 ) ? L_137 : L_392 ) ;
if ( ! V_20 )
return V_821 ;
else
return V_820 ;
}
static void
F_315 ( struct V_763 * V_552 )
{
struct V_141 * V_142 = F_274 ( V_552 ) ;
struct V_5 * V_6 = F_58 ( V_142 ) ;
F_3 ( V_58 L_393 , V_6 -> V_35 ) ;
F_316 ( V_552 ) ;
F_289 ( V_6 ) ;
F_312 ( V_6 -> V_142 ) ;
}
static T_53
F_317 ( struct V_763 * V_552 )
{
struct V_141 * V_142 = F_274 ( V_552 ) ;
struct V_5 * V_6 = F_58 ( V_142 ) ;
F_3 ( V_58 L_394 ,
V_6 -> V_35 ) ;
return V_818 ;
}
static int T_55
F_318 ( void )
{
int error ;
V_783 = 0 ;
F_3 ( V_7 L_395 , V_784 ,
V_822 ) ;
V_798 =
F_319 ( & V_823 ) ;
if ( ! V_798 )
return - V_781 ;
V_185 = F_320 ( & V_824 ) ;
if ( ! V_185 ) {
F_321 ( V_798 ) ;
return - V_781 ;
}
F_322 () ;
V_470 = F_323 ( F_200 ) ;
V_314 = F_323 ( F_97 ) ;
V_787 = F_323 ( V_825 ) ;
V_788 = F_323 (
V_826 ) ;
V_789 = F_323 (
V_827 ) ;
V_760 = F_323 ( F_220 ) ;
V_790 = F_323 (
V_828 ) ;
V_786 = F_323 ( V_829 ) ;
V_376 = F_323 (
F_154 ) ;
V_378 = F_323 (
F_151 ) ;
V_382 = F_323 (
F_148 ) ;
F_324 () ;
error = F_325 ( & V_830 ) ;
if ( error ) {
F_326 ( V_185 ) ;
F_321 ( V_798 ) ;
}
return error ;
}
static void T_56
F_327 ( void )
{
F_3 ( V_7 L_396 ,
V_822 ) ;
F_328 ( & V_830 ) ;
F_329 () ;
F_330 ( V_470 ) ;
F_330 ( V_314 ) ;
F_330 ( V_787 ) ;
F_330 ( V_788 ) ;
F_330 ( V_789 ) ;
F_330 ( V_760 ) ;
F_330 ( V_790 ) ;
F_330 ( V_786 ) ;
F_330 ( V_376 ) ;
F_330 ( V_378 ) ;
F_330 ( V_382 ) ;
F_326 ( V_185 ) ;
F_321 ( V_798 ) ;
}
