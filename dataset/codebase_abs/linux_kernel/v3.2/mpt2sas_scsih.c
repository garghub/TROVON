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
if ( F_15 ( V_6 ,
V_46 -> V_9 ) ) {
F_19 ( & V_46 -> V_67 ) ;
F_20 ( V_46 ) ;
}
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
if ( ! V_6 -> V_49 )
F_26 ( V_6 ,
V_46 -> V_9 ,
V_46 -> V_69 ) ;
F_17 ( V_6 , V_46 ) ;
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
F_21 ( & V_6 -> V_66 , V_65 ) ;
F_13 ( V_6 , V_46 , 0 ) ;
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
memset ( V_48 , 0 , sizeof( struct V_47 ) ) ;
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
F_3 ( V_99 L_10 ,
V_6 -> V_35 ) ;
return NULL ;
}
V_97 = F_44 ( V_6 -> V_98 . V_100 ,
struct V_96 , V_101 ) ;
F_45 ( & V_97 -> V_101 ) ;
F_24 ( & V_97 -> V_101 ,
& V_6 -> V_89 [ V_88 - 1 ] . V_102 ) ;
F_21 ( & V_6 -> V_91 , V_65 ) ;
return V_97 ;
}
static int
F_46 ( struct V_5 * V_6 ,
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
V_103 = F_47 ( V_6 , V_88 ) ;
V_114 = V_117 ;
if ( V_90 -> V_118 == V_119 )
V_114 |= V_120 ;
V_115 = ( V_114 | V_121 )
<< V_122 ;
V_116 = ( V_114 | V_121 |
V_123 | V_124 )
<< V_122 ;
V_114 = V_114 << V_122 ;
V_106 = F_48 ( V_90 ) ;
V_112 = F_49 ( V_90 ) ;
if ( V_112 < 0 ) {
F_50 ( V_125 , V_90 -> V_43 , L_11
L_12 , F_51 ( V_90 ) ) ;
return - V_126 ;
}
V_107 = & V_103 -> V_127 ;
V_113 = V_6 -> V_128 ;
if ( V_112 <= V_113 )
goto V_129;
V_103 -> V_130 = ( F_52 ( T_11 , V_127 ) +
( V_113 * V_6 -> V_131 ) ) / 4 ;
while ( V_113 ) {
if ( V_113 == 1 )
V_6 -> V_132 ( V_107 ,
V_115 | F_53 ( V_106 ) ,
F_54 ( V_106 ) ) ;
else
V_6 -> V_132 ( V_107 , V_114 |
F_53 ( V_106 ) , F_54 ( V_106 ) ) ;
V_106 = F_55 ( V_106 ) ;
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
F_53 ( V_106 ) ,
F_54 ( V_106 ) ) ;
else
V_6 -> V_132 ( V_107 , V_114 |
F_53 ( V_106 ) ,
F_54 ( V_106 ) ) ;
V_106 = F_55 ( V_106 ) ;
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
F_53 ( V_106 ) , F_54 ( V_106 ) ) ;
else
V_6 -> V_132 ( V_107 , V_114 |
F_53 ( V_106 ) , F_54 ( V_106 ) ) ;
V_106 = F_55 ( V_106 ) ;
V_107 += V_6 -> V_131 ;
V_112 -- ;
}
return 0 ;
}
static void
F_56 ( struct V_138 * V_139 , int V_140 )
{
struct V_141 * V_142 = V_139 -> V_143 ;
int V_144 ;
struct V_5 * V_6 = F_57 ( V_142 ) ;
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
F_21 ( & V_6 -> V_66 , V_65 ) ;
if ( V_46 && V_46 -> V_82 &
V_86 )
V_144 = V_154 ;
V_151:
if ( ! V_139 -> V_155 )
V_144 = 1 ;
if ( V_140 > V_144 )
V_140 = V_144 ;
F_58 ( V_139 , F_59 ( V_139 ) , V_140 ) ;
}
static int
F_60 ( struct V_138 * V_139 , int V_140 , int V_156 )
{
if ( V_156 == V_157 || V_156 == V_158 )
F_56 ( V_139 , V_140 ) ;
else if ( V_156 == V_159 )
F_61 ( V_139 , V_140 ) ;
else
return - V_160 ;
if ( V_139 -> V_161 > 7 )
F_50 ( V_7 , V_139 , L_13
L_14 ,
V_139 -> V_162 , V_139 -> V_155 , V_139 -> V_163 ,
V_139 -> V_164 , V_139 -> V_165 ,
( V_139 -> V_166 [ 7 ] & 2 ) >> 1 ) ;
return V_139 -> V_162 ;
}
static int
F_62 ( struct V_138 * V_139 , int V_167 )
{
if ( V_139 -> V_155 ) {
F_63 ( V_139 , V_167 ) ;
if ( V_167 )
F_64 ( V_139 , V_139 -> V_162 ) ;
else
F_65 ( V_139 , V_139 -> V_162 ) ;
} else
V_167 = 0 ;
return V_167 ;
}
static int
F_66 ( struct V_168 * V_70 )
{
struct V_141 * V_142 = F_67 ( & V_70 -> V_169 ) ;
struct V_5 * V_6 = F_57 ( V_142 ) ;
struct V_147 * V_148 ;
struct V_45 * V_46 ;
struct V_47 * V_48 ;
unsigned long V_65 ;
struct V_170 * V_171 ;
V_148 = F_68 ( sizeof( struct V_168 ) , V_172 ) ;
if ( ! V_148 )
return - V_126 ;
V_70 -> V_150 = V_148 ;
V_148 -> V_70 = V_70 ;
V_148 -> V_27 = V_173 ;
if ( V_70 -> V_73 == V_174 ) {
F_18 ( & V_6 -> V_76 , V_65 ) ;
V_48 = F_28 ( V_6 , V_70 -> V_72 ,
V_70 -> V_73 ) ;
if ( V_48 ) {
V_148 -> V_27 = V_48 -> V_27 ;
V_148 -> V_9 = V_48 -> V_52 ;
V_148 -> V_65 |= V_153 ;
V_148 -> V_48 = V_48 ;
V_48 -> V_70 = V_70 ;
}
F_21 ( & V_6 -> V_76 , V_65 ) ;
return 0 ;
}
F_18 ( & V_6 -> V_66 , V_65 ) ;
V_171 = F_69 ( V_70 -> V_169 . V_175 ) ;
V_46 = F_15 ( V_6 ,
V_171 -> V_176 . V_9 ) ;
if ( V_46 ) {
V_148 -> V_27 = V_46 -> V_27 ;
V_148 -> V_9 = V_46 -> V_9 ;
V_46 -> V_70 = V_70 ;
V_46 -> V_72 = V_70 -> V_72 ;
V_46 -> V_73 = V_70 -> V_73 ;
if ( F_70 ( V_46 -> V_27 , V_6 -> V_177 ) )
V_148 -> V_65 |=
V_178 ;
}
F_21 ( & V_6 -> V_66 , V_65 ) ;
return 0 ;
}
static void
F_71 ( struct V_168 * V_70 )
{
struct V_141 * V_142 = F_67 ( & V_70 -> V_169 ) ;
struct V_5 * V_6 = F_57 ( V_142 ) ;
struct V_147 * V_148 ;
struct V_45 * V_46 ;
struct V_47 * V_48 ;
unsigned long V_65 ;
struct V_170 * V_171 ;
V_148 = V_70 -> V_150 ;
if ( ! V_148 )
return;
if ( V_70 -> V_73 == V_174 ) {
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
V_171 = F_69 ( V_70 -> V_169 . V_175 ) ;
V_46 = F_15 ( V_6 ,
V_171 -> V_176 . V_9 ) ;
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
F_72 ( struct V_138 * V_139 )
{
struct V_141 * V_142 ;
struct V_5 * V_6 ;
struct V_147 * V_148 ;
struct V_145 * V_146 ;
struct V_168 * V_70 ;
struct V_47 * V_48 ;
unsigned long V_65 ;
V_146 = F_68 ( sizeof( struct V_138 ) , V_172 ) ;
if ( ! V_146 )
return - V_126 ;
V_146 -> V_95 = V_139 -> V_95 ;
V_146 -> V_65 = V_179 ;
V_70 = V_168 ( V_139 ) ;
V_148 = V_70 -> V_150 ;
V_148 -> V_180 ++ ;
V_146 -> V_152 = V_148 ;
V_139 -> V_150 = V_146 ;
if ( ( V_148 -> V_65 & V_178 ) )
V_139 -> V_181 = 1 ;
V_142 = F_67 ( & V_70 -> V_169 ) ;
V_6 = F_57 ( V_142 ) ;
if ( V_70 -> V_73 == V_174 ) {
F_18 ( & V_6 -> V_76 , V_65 ) ;
V_48 = F_28 ( V_6 ,
V_70 -> V_72 , V_70 -> V_73 ) ;
if ( V_48 )
V_48 -> V_139 = V_139 ;
F_21 ( & V_6 -> V_76 , V_65 ) ;
}
return 0 ;
}
static void
F_73 ( struct V_138 * V_139 )
{
struct V_147 * V_148 ;
struct V_168 * V_70 ;
struct V_141 * V_142 ;
struct V_5 * V_6 ;
struct V_45 * V_46 ;
unsigned long V_65 ;
if ( ! V_139 -> V_150 )
return;
V_70 = V_168 ( V_139 ) ;
V_148 = V_70 -> V_150 ;
V_148 -> V_180 -- ;
V_142 = F_67 ( & V_70 -> V_169 ) ;
V_6 = F_57 ( V_142 ) ;
if ( ! ( V_148 -> V_65 & V_153 ) ) {
F_18 ( & V_6 -> V_66 , V_65 ) ;
V_46 = F_15 ( V_6 ,
V_148 -> V_9 ) ;
if ( V_46 )
V_46 -> V_70 = NULL ;
F_21 ( & V_6 -> V_66 , V_65 ) ;
}
F_20 ( V_139 -> V_150 ) ;
V_139 -> V_150 = NULL ;
}
static void
F_74 ( struct V_5 * V_6 ,
struct V_45 * V_46 , struct V_138 * V_139 )
{
T_9 V_29 ;
T_8 V_28 ;
T_10 V_30 ;
T_4 V_65 ;
T_10 V_82 ;
if ( ( F_12 ( V_6 , & V_29 , & V_28 ,
V_33 , V_46 -> V_27 ) ) ) {
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
V_65 = F_9 ( V_28 . V_182 ) ;
V_82 = F_75 ( V_28 . V_183 ) ;
F_50 ( V_7 , V_139 ,
L_15
L_16 ,
( V_82 & V_184 ) ? L_17 : L_18 ,
( V_65 & V_185 ) ? L_17 : L_18 ,
( V_65 & V_186 ) ? L_17 :
L_18 ,
( V_65 & V_187 ) ? L_17 : L_18 ,
( V_65 & V_188 ) ? L_17 : L_18 ,
( V_65 & V_189 ) ? L_17 : L_18 ) ;
}
static int
F_76 ( struct V_43 * V_169 )
{
struct V_138 * V_139 = F_77 ( V_169 ) ;
struct V_5 * V_6 = F_57 ( V_139 -> V_143 ) ;
if ( V_6 -> V_190 )
return 0 ;
return ( V_139 -> V_73 == V_174 ) ? 1 : 0 ;
}
static void
F_78 ( struct V_43 * V_169 )
{
struct V_138 * V_139 = F_77 ( V_169 ) ;
struct V_5 * V_6 = F_57 ( V_139 -> V_143 ) ;
static struct V_47 * V_48 ;
unsigned long V_65 ;
T_13 V_191 ;
T_9 V_29 ;
T_10 V_192 ;
T_6 V_193 = 0 ;
F_18 ( & V_6 -> V_76 , V_65 ) ;
V_48 = F_28 ( V_6 , V_139 -> V_72 ,
V_139 -> V_73 ) ;
F_21 ( & V_6 -> V_76 , V_65 ) ;
if ( ! V_48 || V_6 -> V_190 )
goto V_75;
if ( F_79 ( V_6 , & V_29 , & V_191 ,
V_194 , V_48 -> V_27 ,
sizeof( T_13 ) ) ) {
F_3 ( V_34 L_2 ,
V_6 -> V_35 , __FILE__ , __LINE__ , V_36 ) ;
goto V_75;
}
V_192 = F_75 ( V_191 . V_195 ) ;
if ( V_192 & V_196 )
V_193 = V_48 -> V_193 ;
V_75:
F_80 ( V_197 , V_169 , V_193 ) ;
}
static void
F_81 ( struct V_43 * V_169 )
{
struct V_138 * V_139 = F_77 ( V_169 ) ;
struct V_5 * V_6 = F_57 ( V_139 -> V_143 ) ;
static struct V_47 * V_48 ;
unsigned long V_65 ;
T_13 V_191 ;
T_9 V_29 ;
T_10 V_198 ;
enum V_199 V_200 = V_201 ;
F_18 ( & V_6 -> V_76 , V_65 ) ;
V_48 = F_28 ( V_6 , V_139 -> V_72 ,
V_139 -> V_73 ) ;
F_21 ( & V_6 -> V_76 , V_65 ) ;
if ( ! V_48 )
goto V_75;
if ( F_79 ( V_6 , & V_29 , & V_191 ,
V_194 , V_48 -> V_27 ,
sizeof( T_13 ) ) ) {
F_3 ( V_34 L_2 ,
V_6 -> V_35 , __FILE__ , __LINE__ , V_36 ) ;
goto V_75;
}
V_198 = F_75 ( V_191 . V_195 ) ;
if ( V_198 & V_196 ) {
V_200 = V_202 ;
goto V_75;
}
switch ( V_191 . V_203 ) {
case V_204 :
case V_205 :
V_200 = V_206 ;
break;
case V_207 :
V_200 = V_208 ;
break;
case V_209 :
case V_210 :
V_200 = V_211 ;
break;
}
V_75:
F_82 ( V_197 , V_169 , V_200 ) ;
}
static void
F_83 ( struct V_138 * V_139 , struct V_47 * V_48 )
{
enum V_212 V_213 = V_214 ;
switch ( V_48 -> V_215 ) {
case V_216 :
V_213 = V_217 ;
break;
case V_218 :
V_213 = V_219 ;
break;
case V_220 :
V_213 = V_221 ;
break;
case V_222 :
V_213 = V_223 ;
break;
}
F_84 ( V_197 , & V_139 -> V_224 , V_213 ) ;
}
static int
F_85 ( struct V_5 * V_6 ,
struct V_47 * V_48 )
{
T_13 * V_191 ;
T_14 V_225 ;
T_8 V_28 ;
T_9 V_29 ;
T_4 V_226 ;
T_6 V_227 ;
if ( ( F_86 ( V_6 , V_48 -> V_27 ,
& V_227 ) ) || ! V_227 ) {
F_87 ( V_6 , F_3 ( V_99
L_2 , V_6 -> V_35 , __FILE__ , __LINE__ ,
V_36 ) ) ;
return 1 ;
}
V_48 -> V_227 = V_227 ;
V_226 = F_52 ( T_13 , V_228 ) + ( V_227 *
sizeof( V_229 ) ) ;
V_191 = F_68 ( V_226 , V_172 ) ;
if ( ! V_191 ) {
F_87 ( V_6 , F_3 ( V_99
L_2 , V_6 -> V_35 , __FILE__ , __LINE__ ,
V_36 ) ) ;
return 1 ;
}
if ( ( F_79 ( V_6 , & V_29 , V_191 ,
V_194 , V_48 -> V_27 , V_226 ) ) ) {
F_87 ( V_6 , F_3 ( V_99
L_2 , V_6 -> V_35 , __FILE__ , __LINE__ ,
V_36 ) ) ;
F_20 ( V_191 ) ;
return 1 ;
}
V_48 -> V_215 = V_191 -> V_230 ;
if ( ! ( F_88 ( V_6 , & V_29 ,
& V_225 , V_231 ,
V_191 -> V_228 [ 0 ] . V_232 ) ) ) {
if ( ! ( F_12 ( V_6 , & V_29 ,
& V_28 , V_33 ,
F_9 ( V_225 . V_233 ) ) ) ) {
V_48 -> V_82 =
F_75 ( V_28 . V_183 ) ;
}
}
F_20 ( V_191 ) ;
return 0 ;
}
static void
F_89 ( struct V_5 * V_6 )
{
T_15 V_234 ;
T_9 V_29 ;
struct V_47 * V_48 ;
T_4 V_27 ;
T_4 V_30 ;
V_27 = 0xFFFF ;
while ( ! ( F_90 ( V_6 , & V_29 ,
& V_234 , V_235 , V_27 ) ) ) {
V_30 = F_9 ( V_29 . V_38 ) &
V_39 ;
if ( V_30 == V_41 )
break;
V_27 = F_9 ( V_234 . V_233 ) ;
V_48 = F_29 ( V_6 , V_27 ) ;
if ( V_48 )
V_48 -> V_236 = 0 ;
}
return;
}
static T_6
F_91 ( struct V_5 * V_6 )
{
T_15 V_234 ;
T_9 V_29 ;
T_4 V_27 ;
T_6 V_237 = 0 ;
T_4 V_30 ;
V_27 = 0xFFFF ;
while ( ! ( F_90 ( V_6 , & V_29 ,
& V_234 , V_235 , V_27 ) ) ) {
V_30 = F_9 ( V_29 . V_38 ) &
V_39 ;
if ( V_30 == V_41 )
break;
V_237 ++ ;
V_27 = F_9 ( V_234 . V_233 ) ;
}
return V_237 ;
}
static void
F_92 ( struct V_5 * V_6 ,
struct V_47 * V_48 )
{
T_13 * V_191 ;
T_14 V_225 ;
T_9 V_29 ;
T_4 V_226 ;
T_6 V_227 , V_238 ;
T_1 V_239 = 1024 * 1024 ;
T_1 V_240 = 2 * V_239 * V_239 ;
T_1 V_241 ;
T_10 V_242 ;
T_6 V_92 , V_243 ;
if ( ! V_6 -> V_190 )
return;
if ( V_6 -> V_244 == V_245 ) {
F_3 ( V_58 L_19
L_20 , V_6 -> V_35 ) ;
return;
}
if ( F_91 ( V_6 ) > 1 ) {
F_89 ( V_6 ) ;
F_3 ( V_58 L_19
L_21 , V_6 -> V_35 ) ;
return;
}
if ( ( F_86 ( V_6 , V_48 -> V_27 ,
& V_227 ) ) || ! V_227 ) {
F_3 ( V_58 L_19
L_22 , V_6 -> V_35 ) ;
return;
}
V_226 = F_52 ( T_13 , V_228 ) + ( V_227 *
sizeof( V_229 ) ) ;
V_191 = F_68 ( V_226 , V_172 ) ;
if ( ! V_191 ) {
F_3 ( V_58 L_19
L_23 , V_6 -> V_35 ) ;
return;
}
if ( ( F_79 ( V_6 , & V_29 , V_191 ,
V_194 , V_48 -> V_27 , V_226 ) ) ) {
F_3 ( V_58 L_19
L_24 , V_6 -> V_35 ) ;
F_20 ( V_191 ) ;
return;
}
if ( V_227 > V_246 ) {
F_3 ( V_99 L_19
L_25
L_26 , V_6 -> V_35 , V_48 -> V_27 ,
V_227 , V_246 ) ;
F_20 ( V_191 ) ;
return;
}
for ( V_238 = 0 ; V_238 < V_227 ; V_238 ++ ) {
if ( F_88 ( V_6 , & V_29 ,
& V_225 , V_231 ,
V_191 -> V_228 [ V_238 ] . V_232 ) ||
V_225 . V_233 == V_173 ) {
F_3 ( V_58 L_27
L_28
L_29 ,
V_6 -> V_35 , V_48 -> V_27 ,
V_191 -> V_228 [ V_238 ] . V_232 ) ;
goto V_247;
}
V_48 -> V_248 [ V_238 ] = F_9 ( V_225 . V_233 ) ;
}
if ( V_48 -> V_215 != V_216 ||
F_9 ( V_191 -> V_249 ) != 512 ) {
F_3 ( V_58 L_19
L_30
L_31 , V_6 -> V_35 ,
V_48 -> V_27 , V_48 -> V_215 ,
F_75 ( V_191 -> V_250 ) / 2 ,
F_9 ( V_191 -> V_249 ) ) ;
goto V_247;
}
V_241 = ( T_1 ) F_9 ( V_191 -> V_249 ) *
( F_6 ( V_191 -> V_251 ) + 1 ) ;
if ( V_241 > V_240 ) {
F_3 ( V_58 L_19
L_32 ,
V_6 -> V_35 , V_48 -> V_27 ) ;
goto V_247;
}
V_242 = F_75 ( V_191 -> V_250 ) ;
V_243 = 0 ;
for ( V_92 = 0 ; V_92 < 32 ; V_92 ++ ) {
if ( V_242 & 1 )
break;
V_243 ++ ;
V_242 >>= 1 ;
}
if ( V_92 == 32 ) {
F_3 ( V_58 L_19
L_33 ,
V_6 -> V_35 , V_48 -> V_27 ,
F_75 ( V_191 -> V_250 ) / 2 ) ;
goto V_247;
}
V_48 -> V_252 = V_243 ;
V_48 -> V_236 = 1 ;
F_3 ( V_58 L_34
L_35 , V_6 -> V_35 , V_48 -> V_27 ) ;
V_48 -> V_253 = F_6 ( V_191 -> V_251 ) ;
V_48 -> V_242 = F_75 ( V_191 -> V_250 ) ;
V_48 -> V_254 = F_9 ( V_191 -> V_249 ) ;
F_20 ( V_191 ) ;
return;
V_247:
V_48 -> V_236 = 0 ;
for ( V_238 = 0 ; V_238 < V_227 ; V_238 ++ )
V_48 -> V_248 [ V_238 ] = 0 ;
F_20 ( V_191 ) ;
return;
}
static void
F_93 ( struct V_5 * V_6 , struct V_138 * V_139 )
{
if ( V_139 -> type != V_255 )
return;
if ( ! ( V_6 -> V_256 . V_257 & V_258 ) )
return;
F_94 ( V_139 ) ;
F_50 ( V_7 , V_139 , L_36 ,
F_95 ( V_139 ) ? L_37 : L_38 ) ;
return;
}
static int
F_96 ( struct V_138 * V_139 )
{
struct V_141 * V_142 = V_139 -> V_143 ;
struct V_5 * V_6 = F_57 ( V_142 ) ;
struct V_145 * V_146 ;
struct V_147 * V_148 ;
struct V_45 * V_46 ;
struct V_47 * V_48 ;
unsigned long V_65 ;
int V_140 ;
T_6 V_259 = 0 ;
char * V_260 = L_39 ;
char * V_261 = L_39 ;
V_140 = 1 ;
V_146 = V_139 -> V_150 ;
V_146 -> V_262 = 1 ;
V_146 -> V_65 &= ~ V_179 ;
V_148 = V_146 -> V_152 ;
if ( V_148 -> V_65 & V_153 ) {
F_18 ( & V_6 -> V_76 , V_65 ) ;
V_48 = F_29 ( V_6 ,
V_148 -> V_27 ) ;
F_21 ( & V_6 -> V_76 , V_65 ) ;
if ( ! V_48 ) {
F_87 ( V_6 , F_3 ( V_99
L_2 , V_6 -> V_35 , __FILE__ ,
__LINE__ , V_36 ) ) ;
return 1 ;
}
F_85 ( V_6 , V_48 ) ;
if ( F_85 ( V_6 , V_48 ) ) {
F_87 ( V_6 , F_3 ( V_99
L_2 , V_6 -> V_35 , __FILE__ ,
__LINE__ , V_36 ) ) ;
return 1 ;
}
F_92 ( V_6 , V_48 ) ;
if ( V_48 -> V_82 &
V_84 ) {
V_140 = V_263 ;
V_260 = L_40 ;
} else {
V_140 = V_154 ;
if ( V_48 -> V_82 &
V_86 )
V_260 = L_41 ;
else
V_260 = L_42 ;
}
switch ( V_48 -> V_215 ) {
case V_216 :
V_261 = L_43 ;
break;
case V_220 :
V_140 = V_264 ;
if ( V_6 -> V_265 . V_266 &&
( F_75 ( V_6 -> V_265 . V_267 ) &
V_268 ) &&
! ( V_48 -> V_227 % 2 ) )
V_261 = L_44 ;
else
V_261 = L_45 ;
break;
case V_222 :
V_140 = V_264 ;
V_261 = L_46 ;
break;
case V_218 :
V_140 = V_264 ;
V_261 = L_44 ;
break;
case V_269 :
default:
V_140 = V_264 ;
V_261 = L_47 ;
break;
}
if ( ! V_6 -> V_270 )
F_50 ( V_7 , V_139 , L_48
L_49 ,
V_261 , V_48 -> V_27 ,
( unsigned long long ) V_48 -> V_52 ,
V_48 -> V_227 , V_260 ) ;
F_60 ( V_139 , V_140 , V_157 ) ;
if ( ! V_6 -> V_190 )
F_83 ( V_139 , V_48 ) ;
return 0 ;
}
F_18 ( & V_6 -> V_66 , V_65 ) ;
V_46 = F_15 ( V_6 ,
V_146 -> V_152 -> V_9 ) ;
F_21 ( & V_6 -> V_66 , V_65 ) ;
if ( V_46 ) {
if ( V_148 -> V_65 &
V_178 ) {
if ( F_97 ( V_6 ,
V_46 -> V_27 , & V_46 -> V_271 ) ) {
F_87 ( V_6 , F_3 ( V_99
L_2 , V_6 -> V_35 ,
__FILE__ , __LINE__ , V_36 ) ) ;
return 1 ;
}
if ( V_46 -> V_271 &&
F_98 ( V_6 ,
V_46 -> V_271 ,
& V_46 -> V_272 ) ) {
F_87 ( V_6 , F_3 ( V_99
L_2 , V_6 -> V_35 ,
__FILE__ , __LINE__ , V_36 ) ) ;
return 1 ;
}
}
if ( V_46 -> V_82 & V_84 ) {
V_140 = V_263 ;
V_259 = 1 ;
V_260 = L_40 ;
} else {
V_140 = V_154 ;
if ( V_46 -> V_82 &
V_85 )
V_260 = L_42 ;
else if ( V_46 -> V_82 &
V_86 )
V_260 = L_41 ;
}
F_50 ( V_7 , V_139 , L_48
L_50 ,
V_260 , V_46 -> V_27 ,
( unsigned long long ) V_46 -> V_9 ,
V_46 -> V_273 ,
( unsigned long long ) V_46 -> V_12 ) ;
F_50 ( V_7 , V_139 , L_51
L_52 , V_260 ,
( unsigned long long ) V_46 -> V_14 ,
V_46 -> V_18 ) ;
if ( ! V_259 )
F_74 ( V_6 , V_46 , V_139 ) ;
} else {
F_87 ( V_6 , F_3 ( V_99
L_2 , V_6 -> V_35 , __FILE__ , __LINE__ ,
V_36 ) ) ;
return 1 ;
}
F_60 ( V_139 , V_140 , V_157 ) ;
if ( V_259 ) {
F_99 ( V_139 ) ;
F_93 ( V_6 , V_139 ) ;
}
return 0 ;
}
static int
F_100 ( struct V_138 * V_139 , struct V_274 * V_275 ,
T_16 V_241 , int V_276 [] )
{
int V_277 ;
int V_278 ;
T_16 V_279 ;
T_17 V_280 ;
V_277 = 64 ;
V_278 = 32 ;
V_280 = V_277 * V_278 ;
V_279 = V_241 ;
F_101 ( V_279 , V_280 ) ;
if ( ( T_17 ) V_241 >= 0x200000 ) {
V_277 = 255 ;
V_278 = 63 ;
V_280 = V_277 * V_278 ;
V_279 = V_241 ;
F_101 ( V_279 , V_280 ) ;
}
V_276 [ 0 ] = V_277 ;
V_276 [ 1 ] = V_278 ;
V_276 [ 2 ] = V_279 ;
return 0 ;
}
static void
F_102 ( struct V_5 * V_6 , T_6 V_281 )
{
char * V_282 ;
switch ( V_281 ) {
case V_283 :
V_282 = L_53 ;
break;
case V_284 :
V_282 = L_54 ;
break;
case V_285 :
V_282 = L_55 ;
break;
case V_286 :
V_282 = L_56 ;
break;
case V_287 :
V_282 = L_57 ;
break;
case V_288 :
V_282 = L_58 ;
break;
case 0xA :
V_282 = L_59 ;
break;
case V_289 :
V_282 = L_60 ;
break;
default:
V_282 = L_61 ;
break;
}
F_3 ( V_99 L_62 ,
V_6 -> V_35 , V_281 , V_282 ) ;
}
static T_6
F_103 ( struct V_5 * V_6 , T_4 V_88 , T_6 V_290 , T_10 V_291 )
{
T_18 * V_29 ;
if ( V_6 -> V_292 . V_293 == V_294 )
return 1 ;
if ( V_6 -> V_292 . V_88 != V_88 )
return 1 ;
F_104 ( V_6 ) ;
V_6 -> V_292 . V_293 |= V_295 ;
V_29 = F_105 ( V_6 , V_291 ) ;
if ( V_29 ) {
memcpy ( V_6 -> V_292 . V_291 , V_29 , V_29 -> V_296 * 4 ) ;
V_6 -> V_292 . V_293 |= V_297 ;
}
V_6 -> V_292 . V_293 &= ~ V_298 ;
F_106 ( & V_6 -> V_292 . V_299 ) ;
return 1 ;
}
void
F_107 ( struct V_5 * V_6 , T_4 V_27 )
{
struct V_145 * V_146 ;
struct V_138 * V_139 ;
T_6 V_300 = 0 ;
F_108 (sdev, ioc->shost) {
if ( V_300 )
continue;
V_146 = V_139 -> V_150 ;
if ( ! V_146 )
continue;
if ( V_146 -> V_152 -> V_27 == V_27 ) {
V_146 -> V_152 -> V_301 = 1 ;
V_300 = 1 ;
V_6 -> V_302 = 1 ;
}
}
}
void
F_109 ( struct V_5 * V_6 , T_4 V_27 )
{
struct V_145 * V_146 ;
struct V_138 * V_139 ;
T_6 V_300 = 0 ;
F_108 (sdev, ioc->shost) {
if ( V_300 )
continue;
V_146 = V_139 -> V_150 ;
if ( ! V_146 )
continue;
if ( V_146 -> V_152 -> V_27 == V_27 ) {
V_146 -> V_152 -> V_301 = 0 ;
V_300 = 1 ;
V_6 -> V_302 = 0 ;
}
}
}
int
F_110 ( struct V_5 * V_6 , T_4 V_27 , T_19 V_73 ,
T_19 V_72 , T_19 V_95 , T_6 type , T_4 V_303 , T_17 V_304 ,
unsigned long V_305 , enum V_306 V_307 )
{
T_20 * V_103 ;
T_21 * V_29 ;
T_4 V_88 = 0 ;
T_10 V_308 ;
unsigned long V_309 ;
struct V_310 * V_89 = NULL ;
int V_20 ;
if ( V_307 == V_311 )
F_111 ( & V_6 -> V_292 . V_312 ) ;
if ( V_6 -> V_292 . V_293 != V_294 ) {
F_3 ( V_58 L_63 ,
V_36 , V_6 -> V_35 ) ;
V_20 = V_313 ;
goto V_314;
}
if ( V_6 -> V_315 || V_6 -> V_316 ||
V_6 -> V_317 ) {
F_3 ( V_58 L_64 ,
V_36 , V_6 -> V_35 ) ;
V_20 = V_313 ;
goto V_314;
}
V_308 = F_112 ( V_6 , 0 ) ;
if ( V_308 & V_318 ) {
F_113 ( V_6 , F_3 ( V_58 L_65
L_66 , V_6 -> V_35 ) ) ;
V_20 = F_114 ( V_6 , V_319 ,
V_320 ) ;
V_20 = ( ! V_20 ) ? V_321 : V_313 ;
goto V_314;
}
if ( ( V_308 & V_322 ) == V_323 ) {
F_115 ( V_6 , V_308 &
V_324 ) ;
V_20 = F_114 ( V_6 , V_319 ,
V_320 ) ;
V_20 = ( ! V_20 ) ? V_321 : V_313 ;
goto V_314;
}
V_88 = F_116 ( V_6 , V_6 -> V_325 ) ;
if ( ! V_88 ) {
F_3 ( V_34 L_67 ,
V_6 -> V_35 , V_36 ) ;
V_20 = V_313 ;
goto V_314;
}
if ( type == V_326 )
V_89 = & V_6 -> V_89 [ V_303 - 1 ] ;
F_117 ( V_6 , F_3 ( V_58 L_68
L_69 , V_6 -> V_35 , V_27 , type ,
V_303 ) ) ;
V_6 -> V_292 . V_293 = V_298 ;
V_103 = F_47 ( V_6 , V_88 ) ;
V_6 -> V_292 . V_88 = V_88 ;
memset ( V_103 , 0 , sizeof( T_20 ) ) ;
memset ( V_6 -> V_292 . V_291 , 0 , sizeof( T_21 ) ) ;
V_103 -> V_327 = V_328 ;
V_103 -> V_233 = F_118 ( V_27 ) ;
V_103 -> V_329 = type ;
V_103 -> V_330 = F_118 ( V_303 ) ;
F_119 ( V_95 , (struct V_331 * ) V_103 -> V_332 ) ;
F_107 ( V_6 , V_27 ) ;
F_120 ( & V_6 -> V_292 . V_299 ) ;
F_121 ( V_6 , V_88 ) ;
V_309 = F_122 ( & V_6 -> V_292 . V_299 , V_304 * V_333 ) ;
if ( ! ( V_6 -> V_292 . V_293 & V_295 ) ) {
F_3 ( V_34 L_70 ,
V_6 -> V_35 , V_36 ) ;
F_123 ( V_103 ,
sizeof( T_20 ) / 4 ) ;
if ( ! ( V_6 -> V_292 . V_293 & V_334 ) ) {
V_20 = F_114 ( V_6 , V_319 ,
V_320 ) ;
V_20 = ( ! V_20 ) ? V_321 : V_313 ;
V_6 -> V_292 . V_293 = V_294 ;
F_109 ( V_6 , V_27 ) ;
goto V_314;
}
}
if ( V_6 -> V_292 . V_293 & V_297 ) {
V_29 = V_6 -> V_292 . V_291 ;
F_117 ( V_6 , F_3 ( V_58 L_71
L_72 ,
V_6 -> V_35 , F_9 ( V_29 -> V_38 ) ,
F_75 ( V_29 -> V_335 ) ,
F_75 ( V_29 -> V_336 ) ) ) ;
if ( V_6 -> V_8 & V_337 ) {
F_102 ( V_6 , V_29 -> V_338 ) ;
if ( V_29 -> V_38 )
F_123 ( V_103 ,
sizeof( T_20 ) / 4 ) ;
}
}
switch ( type ) {
case V_326 :
V_20 = V_321 ;
if ( V_89 -> V_90 == NULL )
break;
V_20 = V_313 ;
break;
case V_339 :
if ( F_40 ( V_6 , V_72 , V_73 ) )
V_20 = V_313 ;
else
V_20 = V_321 ;
break;
case V_340 :
case V_341 :
if ( F_41 ( V_6 , V_72 , V_95 , V_73 ) )
V_20 = V_313 ;
else
V_20 = V_321 ;
break;
case V_342 :
V_20 = V_321 ;
break;
default:
V_20 = V_313 ;
break;
}
F_109 ( V_6 , V_27 ) ;
V_6 -> V_292 . V_293 = V_294 ;
if ( V_307 == V_311 )
F_124 ( & V_6 -> V_292 . V_312 ) ;
return V_20 ;
V_314:
if ( V_307 == V_311 )
F_124 ( & V_6 -> V_292 . V_312 ) ;
return V_20 ;
}
static void
F_125 ( struct V_5 * V_6 , struct V_87 * V_90 )
{
struct V_168 * V_70 = V_90 -> V_43 -> V_343 ;
struct V_147 * V_344 = V_70 -> V_150 ;
struct V_45 * V_46 = NULL ;
unsigned long V_65 ;
char * V_345 = NULL ;
if ( ! V_344 )
return;
if ( V_6 -> V_270 )
V_345 = L_73 ;
else
V_345 = L_74 ;
F_126 ( V_90 ) ;
if ( V_344 -> V_65 & V_153 ) {
F_127 ( V_7 , V_70 , L_75
L_76 , V_345 , V_344 -> V_27 ,
V_345 , ( unsigned long long ) V_344 -> V_9 ) ;
} else {
F_18 ( & V_6 -> V_66 , V_65 ) ;
V_46 = F_15 ( V_6 ,
V_344 -> V_9 ) ;
if ( V_46 ) {
if ( V_344 -> V_65 &
V_178 ) {
F_127 ( V_7 , V_70 ,
L_77
L_78 ,
V_46 -> V_271 ,
( unsigned long long ) V_46 -> V_272 ) ;
}
F_127 ( V_7 , V_70 ,
L_79 ,
V_46 -> V_27 ,
( unsigned long long ) V_46 -> V_9 ,
V_46 -> V_273 ) ;
F_127 ( V_7 , V_70 ,
L_52 ,
( unsigned long long ) V_46 -> V_14 ,
V_46 -> V_18 ) ;
}
F_21 ( & V_6 -> V_66 , V_65 ) ;
}
}
static int
F_128 ( struct V_87 * V_90 )
{
struct V_5 * V_6 = F_57 ( V_90 -> V_43 -> V_143 ) ;
struct V_145 * V_146 ;
T_4 V_88 ;
T_4 V_27 ;
int V_74 ;
F_50 ( V_7 , V_90 -> V_43 , L_80
L_81 , V_90 ) ;
F_125 ( V_6 , V_90 ) ;
V_146 = V_90 -> V_43 -> V_150 ;
if ( ! V_146 || ! V_146 -> V_152 ) {
F_50 ( V_7 , V_90 -> V_43 , L_82
L_81 , V_90 ) ;
V_90 -> V_346 = V_347 << 16 ;
V_90 -> V_348 ( V_90 ) ;
V_74 = V_321 ;
goto V_75;
}
V_88 = F_39 ( V_6 , V_90 ) ;
if ( ! V_88 ) {
V_90 -> V_346 = V_349 << 16 ;
V_74 = V_321 ;
goto V_75;
}
if ( V_146 -> V_152 -> V_65 &
V_178 ||
V_146 -> V_152 -> V_65 & V_153 ) {
V_90 -> V_346 = V_349 << 16 ;
V_74 = V_313 ;
goto V_75;
}
F_129 ( V_6 ) ;
V_27 = V_146 -> V_152 -> V_27 ;
V_74 = F_110 ( V_6 , V_27 , V_90 -> V_43 -> V_73 ,
V_90 -> V_43 -> V_72 , V_90 -> V_43 -> V_95 ,
V_326 , V_88 , 30 ,
V_90 -> V_305 , V_311 ) ;
V_75:
F_50 ( V_7 , V_90 -> V_43 , L_83 ,
( ( V_74 == V_321 ) ? L_84 : L_85 ) , V_90 ) ;
return V_74 ;
}
static int
F_130 ( struct V_87 * V_90 )
{
struct V_5 * V_6 = F_57 ( V_90 -> V_43 -> V_143 ) ;
struct V_145 * V_146 ;
struct V_45 * V_46 ;
unsigned long V_65 ;
T_4 V_27 ;
int V_74 ;
struct V_168 * V_70 = V_90 -> V_43 -> V_343 ;
F_127 ( V_7 , V_70 , L_86
L_81 , V_90 ) ;
F_125 ( V_6 , V_90 ) ;
V_146 = V_90 -> V_43 -> V_150 ;
if ( ! V_146 || ! V_146 -> V_152 ) {
F_127 ( V_7 , V_70 , L_82
L_81 , V_90 ) ;
V_90 -> V_346 = V_347 << 16 ;
V_90 -> V_348 ( V_90 ) ;
V_74 = V_321 ;
goto V_75;
}
V_27 = 0 ;
if ( V_146 -> V_152 -> V_65 &
V_178 ) {
F_18 ( & V_6 -> V_66 , V_65 ) ;
V_46 = F_16 ( V_6 ,
V_146 -> V_152 -> V_27 ) ;
if ( V_46 )
V_27 = V_46 -> V_271 ;
F_21 ( & V_6 -> V_66 , V_65 ) ;
} else
V_27 = V_146 -> V_152 -> V_27 ;
if ( ! V_27 ) {
V_90 -> V_346 = V_349 << 16 ;
V_74 = V_313 ;
goto V_75;
}
V_74 = F_110 ( V_6 , V_27 , V_90 -> V_43 -> V_73 ,
V_90 -> V_43 -> V_72 , V_90 -> V_43 -> V_95 ,
V_341 , 0 , 30 , 0 ,
V_311 ) ;
V_75:
F_50 ( V_7 , V_90 -> V_43 , L_87 ,
( ( V_74 == V_321 ) ? L_84 : L_85 ) , V_90 ) ;
return V_74 ;
}
static int
F_131 ( struct V_87 * V_90 )
{
struct V_5 * V_6 = F_57 ( V_90 -> V_43 -> V_143 ) ;
struct V_145 * V_146 ;
struct V_45 * V_46 ;
unsigned long V_65 ;
T_4 V_27 ;
int V_74 ;
struct V_168 * V_70 = V_90 -> V_43 -> V_343 ;
F_127 ( V_7 , V_70 , L_88
L_81 , V_90 ) ;
F_125 ( V_6 , V_90 ) ;
V_146 = V_90 -> V_43 -> V_150 ;
if ( ! V_146 || ! V_146 -> V_152 ) {
F_127 ( V_7 , V_70 , L_89
L_81 , V_90 ) ;
V_90 -> V_346 = V_347 << 16 ;
V_90 -> V_348 ( V_90 ) ;
V_74 = V_321 ;
goto V_75;
}
V_27 = 0 ;
if ( V_146 -> V_152 -> V_65 &
V_178 ) {
F_18 ( & V_6 -> V_66 , V_65 ) ;
V_46 = F_16 ( V_6 ,
V_146 -> V_152 -> V_27 ) ;
if ( V_46 )
V_27 = V_46 -> V_271 ;
F_21 ( & V_6 -> V_66 , V_65 ) ;
} else
V_27 = V_146 -> V_152 -> V_27 ;
if ( ! V_27 ) {
V_90 -> V_346 = V_349 << 16 ;
V_74 = V_313 ;
goto V_75;
}
V_74 = F_110 ( V_6 , V_27 , V_90 -> V_43 -> V_73 ,
V_90 -> V_43 -> V_72 , 0 , V_339 , 0 ,
30 , 0 , V_311 ) ;
V_75:
F_127 ( V_7 , V_70 , L_90 ,
( ( V_74 == V_321 ) ? L_84 : L_85 ) , V_90 ) ;
return V_74 ;
}
static int
F_132 ( struct V_87 * V_90 )
{
struct V_5 * V_6 = F_57 ( V_90 -> V_43 -> V_143 ) ;
int V_74 , V_350 ;
F_3 ( V_58 L_91 ,
V_6 -> V_35 , V_90 ) ;
F_126 ( V_90 ) ;
V_350 = F_114 ( V_6 , V_319 ,
V_320 ) ;
V_74 = ( V_350 < 0 ) ? V_313 : V_321 ;
F_3 ( V_58 L_92 ,
V_6 -> V_35 , ( ( V_74 == V_321 ) ? L_84 : L_85 ) , V_90 ) ;
return V_74 ;
}
static void
F_133 ( struct V_5 * V_6 , struct V_351 * V_352 )
{
unsigned long V_65 ;
if ( V_6 -> V_353 == NULL )
return;
F_18 ( & V_6 -> V_354 , V_65 ) ;
F_24 ( & V_352 -> V_67 , & V_6 -> V_355 ) ;
F_134 ( & V_352 -> V_356 , V_357 ) ;
F_135 ( V_6 -> V_353 ,
& V_352 -> V_356 , 0 ) ;
F_21 ( & V_6 -> V_354 , V_65 ) ;
}
static void
F_136 ( struct V_5 * V_6 , struct V_351
* V_352 )
{
unsigned long V_65 ;
F_18 ( & V_6 -> V_354 , V_65 ) ;
F_19 ( & V_352 -> V_67 ) ;
F_20 ( V_352 -> V_358 ) ;
F_20 ( V_352 ) ;
F_21 ( & V_6 -> V_354 , V_65 ) ;
}
static void
F_137 ( struct V_5 * V_6 )
{
struct V_351 * V_352 ;
if ( V_6 -> V_49 )
return;
V_352 = F_68 ( sizeof( struct V_351 ) , V_359 ) ;
if ( ! V_352 )
return;
V_352 -> V_360 = V_361 ;
V_352 -> V_6 = V_6 ;
F_133 ( V_6 , V_352 ) ;
}
void
F_138 ( struct V_5 * V_6 )
{
struct V_351 * V_352 ;
V_352 = F_68 ( sizeof( struct V_351 ) , V_359 ) ;
if ( ! V_352 )
return;
V_352 -> V_360 = V_362 ;
V_352 -> V_6 = V_6 ;
F_133 ( V_6 , V_352 ) ;
}
static void
F_139 ( struct V_5 * V_6 )
{
struct V_351 * V_352 , * V_100 ;
if ( F_43 ( & V_6 -> V_355 ) ||
! V_6 -> V_353 || F_140 () )
return;
F_141 (fw_event, next, &ioc->fw_event_list, list) {
if ( F_142 ( & V_352 -> V_356 ) ) {
F_136 ( V_6 , V_352 ) ;
continue;
}
V_352 -> V_363 = 1 ;
}
}
static void
F_143 ( struct V_5 * V_6 )
{
struct V_145 * V_146 ;
struct V_138 * V_139 ;
F_108 (sdev, ioc->shost) {
V_146 = V_139 -> V_150 ;
if ( ! V_146 )
continue;
if ( ! V_146 -> V_364 )
continue;
V_146 -> V_364 = 0 ;
F_23 ( V_6 , F_50 ( V_7 , V_139 , L_93
L_94 ,
V_146 -> V_152 -> V_27 ) ) ;
F_144 ( V_139 ) ;
}
}
static void
F_145 ( struct V_5 * V_6 , T_4 V_27 )
{
struct V_145 * V_146 ;
struct V_138 * V_139 ;
F_108 (sdev, ioc->shost) {
V_146 = V_139 -> V_150 ;
if ( ! V_146 )
continue;
if ( ! V_146 -> V_364 )
continue;
if ( V_146 -> V_152 -> V_27 == V_27 ) {
F_23 ( V_6 , F_50 ( V_7 , V_139 ,
V_58 L_95
L_94 , V_6 -> V_35 , V_27 ) ) ;
V_146 -> V_364 = 0 ;
F_144 ( V_139 ) ;
}
}
}
static void
F_146 ( struct V_5 * V_6 )
{
struct V_145 * V_146 ;
struct V_138 * V_139 ;
F_108 (sdev, ioc->shost) {
V_146 = V_139 -> V_150 ;
if ( ! V_146 )
continue;
if ( V_146 -> V_364 )
continue;
V_146 -> V_364 = 1 ;
F_23 ( V_6 , F_50 ( V_7 , V_139 , L_96
L_94 ,
V_146 -> V_152 -> V_27 ) ) ;
F_147 ( V_139 ) ;
}
}
static void
F_148 ( struct V_5 * V_6 , T_4 V_27 )
{
struct V_145 * V_146 ;
struct V_138 * V_139 ;
F_108 (sdev, ioc->shost) {
V_146 = V_139 -> V_150 ;
if ( ! V_146 )
continue;
if ( V_146 -> V_364 )
continue;
if ( V_146 -> V_152 -> V_27 == V_27 ) {
F_23 ( V_6 , F_50 ( V_7 , V_139 ,
V_58 L_97
L_94 , V_6 -> V_35 , V_27 ) ) ;
V_146 -> V_364 = 1 ;
F_147 ( V_139 ) ;
}
}
}
static void
F_149 ( struct V_5 * V_6 ,
struct V_78 * V_79 )
{
struct V_365 * V_366 ;
struct V_45 * V_46 ;
struct V_78 * V_367 ;
unsigned long V_65 ;
if ( ! V_79 )
return;
F_4 (mpt2sas_port,
&sas_expander->sas_port_list, port_list) {
if ( V_366 -> V_368 . V_369 ==
V_370 ) {
F_18 ( & V_6 -> V_66 , V_65 ) ;
V_46 =
F_15 ( V_6 ,
V_366 -> V_368 . V_9 ) ;
F_21 ( & V_6 -> V_66 , V_65 ) ;
if ( ! V_46 )
continue;
F_148 ( V_6 , V_46 -> V_27 ) ;
}
}
F_4 (mpt2sas_port,
&sas_expander->sas_port_list, port_list) {
if ( V_366 -> V_368 . V_369 ==
V_371 ||
V_366 -> V_368 . V_369 ==
V_372 ) {
F_18 ( & V_6 -> V_80 , V_65 ) ;
V_367 =
F_34 (
V_6 , V_366 -> V_368 . V_9 ) ;
F_21 ( & V_6 -> V_80 , V_65 ) ;
F_149 ( V_6 ,
V_367 ) ;
}
}
}
static void
F_150 ( struct V_5 * V_6 ,
T_22 * V_358 )
{
int V_92 ;
T_4 V_27 ;
T_4 V_373 ;
T_6 V_374 ;
for ( V_92 = 0 ; V_92 < V_358 -> V_375 ; V_92 ++ ) {
V_27 = F_9 ( V_358 -> V_376 [ V_92 ] . V_377 ) ;
if ( ! V_27 )
continue;
V_374 = V_358 -> V_378 + V_92 ;
V_373 = V_358 -> V_376 [ V_92 ] . V_379 &
V_380 ;
if ( V_373 == V_381 )
F_148 ( V_6 , V_27 ) ;
}
}
static void
F_151 ( struct V_5 * V_6 , T_4 V_27 )
{
T_20 * V_103 ;
T_4 V_88 ;
struct V_45 * V_46 ;
struct V_147 * V_148 = NULL ;
T_1 V_9 = 0 ;
unsigned long V_65 ;
struct V_382 * V_383 ;
T_10 V_308 ;
if ( V_6 -> V_316 ) {
F_23 ( V_6 , F_3 ( V_58 L_98
L_99 , V_36 , V_6 -> V_35 , V_27 ) ) ;
return;
} else if ( V_6 -> V_317 ) {
F_23 ( V_6 , F_3 ( V_58 L_100
L_101 , V_36 , V_6 -> V_35 ,
V_27 ) ) ;
return;
}
V_308 = F_112 ( V_6 , 1 ) ;
if ( V_308 != V_384 ) {
F_23 ( V_6 , F_3 ( V_58 L_102
L_103 , V_36 , V_6 -> V_35 ,
V_27 ) ) ;
return;
}
if ( F_70 ( V_27 , V_6 -> V_177 ) )
return;
F_18 ( & V_6 -> V_66 , V_65 ) ;
V_46 = F_16 ( V_6 , V_27 ) ;
if ( V_46 && V_46 -> V_70 &&
V_46 -> V_70 -> V_150 ) {
V_148 = V_46 -> V_70 -> V_150 ;
V_148 -> V_385 = 1 ;
V_9 = V_46 -> V_9 ;
}
F_21 ( & V_6 -> V_66 , V_65 ) ;
if ( V_148 ) {
F_23 ( V_6 , F_3 ( V_58 L_104
L_105 , V_6 -> V_35 , V_27 ,
( unsigned long long ) V_9 ) ) ;
F_145 ( V_6 , V_27 ) ;
V_148 -> V_27 = V_173 ;
}
V_88 = F_116 ( V_6 , V_6 -> V_386 ) ;
if ( ! V_88 ) {
V_383 = F_68 ( sizeof( * V_383 ) , V_359 ) ;
if ( ! V_383 )
return;
F_152 ( & V_383 -> V_67 ) ;
V_383 -> V_27 = V_27 ;
F_24 ( & V_383 -> V_67 , & V_6 -> V_387 ) ;
F_23 ( V_6 , F_3 ( V_58
L_106 ,
V_6 -> V_35 , V_27 ) ) ;
return;
}
F_23 ( V_6 , F_3 ( V_58 L_107
L_108 , V_6 -> V_35 , V_27 , V_88 ,
V_6 -> V_386 ) ) ;
V_103 = F_47 ( V_6 , V_88 ) ;
memset ( V_103 , 0 , sizeof( T_20 ) ) ;
V_103 -> V_327 = V_328 ;
V_103 -> V_233 = F_118 ( V_27 ) ;
V_103 -> V_329 = V_339 ;
F_121 ( V_6 , V_88 ) ;
}
static T_6
F_153 ( struct V_5 * V_6 , T_4 V_88 ,
T_6 V_290 , T_10 V_291 )
{
#ifdef F_154
T_23 * V_29 =
F_105 ( V_6 , V_291 ) ;
#endif
F_23 ( V_6 , F_3 ( V_58
L_109
L_110 ,
V_6 -> V_35 , F_9 ( V_29 -> V_233 ) , V_88 ,
F_9 ( V_29 -> V_38 ) ,
F_75 ( V_29 -> V_335 ) ) ) ;
return 1 ;
}
static void
F_155 ( struct V_5 * V_6 , T_4 V_27 )
{
T_20 * V_103 ;
T_4 V_88 ;
struct V_382 * V_383 ;
if ( V_6 -> V_315 || V_6 -> V_316 ||
V_6 -> V_317 ) {
F_23 ( V_6 , F_3 ( V_58 L_111
L_112 , V_36 , V_6 -> V_35 ) ) ;
return;
}
V_88 = F_116 ( V_6 , V_6 -> V_388 ) ;
if ( ! V_88 ) {
V_383 = F_68 ( sizeof( * V_383 ) , V_359 ) ;
if ( ! V_383 )
return;
F_152 ( & V_383 -> V_67 ) ;
V_383 -> V_27 = V_27 ;
F_24 ( & V_383 -> V_67 , & V_6 -> V_389 ) ;
F_23 ( V_6 , F_3 ( V_58
L_106 ,
V_6 -> V_35 , V_27 ) ) ;
return;
}
F_23 ( V_6 , F_3 ( V_58 L_107
L_108 , V_6 -> V_35 , V_27 , V_88 ,
V_6 -> V_388 ) ) ;
V_103 = F_47 ( V_6 , V_88 ) ;
memset ( V_103 , 0 , sizeof( T_20 ) ) ;
V_103 -> V_327 = V_328 ;
V_103 -> V_233 = F_118 ( V_27 ) ;
V_103 -> V_329 = V_339 ;
F_121 ( V_6 , V_88 ) ;
}
static T_6
F_156 ( struct V_5 * V_6 , T_4 V_88 ,
T_6 V_290 , T_10 V_291 )
{
T_4 V_27 ;
T_20 * V_390 ;
T_21 * V_29 =
F_105 ( V_6 , V_291 ) ;
if ( V_6 -> V_315 || V_6 -> V_316 ||
V_6 -> V_317 ) {
F_23 ( V_6 , F_3 ( V_58 L_111
L_112 , V_36 , V_6 -> V_35 ) ) ;
return 1 ;
}
V_390 = F_47 ( V_6 , V_88 ) ;
V_27 = F_9 ( V_390 -> V_233 ) ;
if ( V_27 != F_9 ( V_29 -> V_233 ) ) {
F_23 ( V_6 , F_3 ( L_113
L_114 , V_27 ,
F_9 ( V_29 -> V_233 ) , V_88 ) ) ;
return 0 ;
}
F_23 ( V_6 , F_3 ( V_58
L_115
L_116 , V_6 -> V_35 ,
V_27 , V_88 , F_9 ( V_29 -> V_38 ) ,
F_75 ( V_29 -> V_335 ) ,
F_75 ( V_29 -> V_336 ) ) ) ;
return F_157 ( V_6 , V_88 ) ;
}
static T_6
F_158 ( struct V_5 * V_6 , T_4 V_88 , T_6 V_290 ,
T_10 V_291 )
{
T_4 V_27 ;
T_20 * V_390 ;
T_21 * V_29 =
F_105 ( V_6 , V_291 ) ;
T_24 * V_103 ;
T_4 V_391 ;
T_10 V_308 ;
if ( V_6 -> V_316 ) {
F_23 ( V_6 , F_3 ( V_58 L_98
L_117 , V_36 , V_6 -> V_35 ) ) ;
return 1 ;
} else if ( V_6 -> V_317 ) {
F_23 ( V_6 , F_3 ( V_58 L_100
L_118 , V_36 , V_6 -> V_35 ) ) ;
return 1 ;
}
V_308 = F_112 ( V_6 , 1 ) ;
if ( V_308 != V_384 ) {
F_23 ( V_6 , F_3 ( V_58 L_102
L_119 , V_36 , V_6 -> V_35 ) ) ;
return 1 ;
}
V_390 = F_47 ( V_6 , V_88 ) ;
V_27 = F_9 ( V_390 -> V_233 ) ;
if ( V_27 != F_9 ( V_29 -> V_233 ) ) {
F_23 ( V_6 , F_3 ( V_58 L_113
L_114 , V_6 -> V_35 , V_27 ,
F_9 ( V_29 -> V_233 ) , V_88 ) ) ;
return 0 ;
}
F_23 ( V_6 , F_3 ( V_58
L_115
L_116 , V_6 -> V_35 ,
V_27 , V_88 , F_9 ( V_29 -> V_38 ) ,
F_75 ( V_29 -> V_335 ) ,
F_75 ( V_29 -> V_336 ) ) ) ;
V_391 = F_159 ( V_6 , V_6 -> V_392 ) ;
if ( ! V_391 ) {
F_3 ( V_34 L_67 ,
V_6 -> V_35 , V_36 ) ;
return 1 ;
}
F_23 ( V_6 , F_3 ( V_58 L_120
L_108 , V_6 -> V_35 , V_27 , V_391 ,
V_6 -> V_392 ) ) ;
V_103 = F_47 ( V_6 , V_391 ) ;
memset ( V_103 , 0 , sizeof( T_24 ) ) ;
V_103 -> V_327 = V_393 ;
V_103 -> V_394 = V_395 ;
V_103 -> V_233 = V_390 -> V_233 ;
F_160 ( V_6 , V_391 ) ;
return F_157 ( V_6 , V_88 ) ;
}
static T_6
F_157 ( struct V_5 * V_6 , T_4 V_88 )
{
struct V_382 * V_383 ;
if ( ! F_43 ( & V_6 -> V_389 ) ) {
V_383 = F_44 ( V_6 -> V_389 . V_100 ,
struct V_382 , V_67 ) ;
F_161 ( V_6 , V_88 ) ;
F_155 ( V_6 , V_383 -> V_27 ) ;
F_19 ( & V_383 -> V_67 ) ;
F_20 ( V_383 ) ;
return 0 ;
}
if ( ! F_43 ( & V_6 -> V_387 ) ) {
V_383 = F_44 ( V_6 -> V_387 . V_100 ,
struct V_382 , V_67 ) ;
F_161 ( V_6 , V_88 ) ;
F_151 ( V_6 , V_383 -> V_27 ) ;
F_19 ( & V_383 -> V_67 ) ;
F_20 ( V_383 ) ;
return 0 ;
}
return 1 ;
}
static void
F_162 ( struct V_5 * V_6 ,
T_22 * V_358 )
{
struct V_351 * V_352 ;
T_22 * V_396 ;
T_4 V_397 ;
struct V_78 * V_79 ;
unsigned long V_65 ;
int V_92 , V_373 ;
T_4 V_27 ;
for ( V_92 = 0 ; V_92 < V_358 -> V_375 ; V_92 ++ ) {
V_27 = F_9 ( V_358 -> V_376 [ V_92 ] . V_377 ) ;
if ( ! V_27 )
continue;
V_373 = V_358 -> V_376 [ V_92 ] . V_379 &
V_380 ;
if ( V_373 == V_398 )
F_151 ( V_6 , V_27 ) ;
}
V_397 = F_9 ( V_358 -> V_399 ) ;
if ( V_397 < V_6 -> V_31 . V_32 ) {
F_150 ( V_6 , V_358 ) ;
return;
}
if ( V_358 -> V_400 == V_401
|| V_358 -> V_400 == V_402 ) {
F_18 ( & V_6 -> V_80 , V_65 ) ;
V_79 = F_33 ( V_6 ,
V_397 ) ;
F_21 ( & V_6 -> V_80 , V_65 ) ;
F_149 ( V_6 , V_79 ) ;
} else if ( V_358 -> V_400 == V_403 )
F_150 ( V_6 , V_358 ) ;
if ( V_358 -> V_400 != V_402 )
return;
F_18 ( & V_6 -> V_354 , V_65 ) ;
F_4 (fw_event, &ioc->fw_event_list, list) {
if ( V_352 -> V_360 != V_404 ||
V_352 -> V_405 )
continue;
V_396 = V_352 -> V_358 ;
if ( V_396 -> V_400 ==
V_406 ||
V_396 -> V_400 ==
V_403 ) {
if ( F_9 ( V_396 -> V_399 ) ==
V_397 ) {
F_23 ( V_6 , F_3 ( V_58
L_121 , V_6 -> V_35 ) ) ;
V_352 -> V_405 = 1 ;
}
}
}
F_21 ( & V_6 -> V_354 , V_65 ) ;
}
static void
F_163 ( struct V_5 * V_6 , T_4 V_27 )
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
V_148 -> V_385 = 1 ;
F_23 ( V_6 , F_3 ( V_58
L_122
L_123 , V_6 -> V_35 , V_27 ,
( unsigned long long ) V_48 -> V_52 ) ) ;
}
F_21 ( & V_6 -> V_76 , V_65 ) ;
}
static void
F_164 ( T_4 V_27 , T_4 * V_407 , T_4 * V_408 )
{
if ( ! V_27 || V_27 == * V_407 || V_27 == * V_408 )
return;
if ( ! * V_407 )
* V_407 = V_27 ;
else if ( ! * V_408 )
* V_408 = V_27 ;
}
static void
F_165 ( struct V_5 * V_6 ,
T_25 * V_358 )
{
T_26 * V_409 ;
int V_92 ;
T_4 V_27 , V_271 , V_407 , V_408 ;
struct V_382 * V_383 ;
V_407 = 0 ;
V_408 = 0 ;
if ( V_6 -> V_190 )
return;
V_409 = ( T_26 * ) & V_358 -> V_410 [ 0 ] ;
for ( V_92 = 0 ; V_92 < V_358 -> V_411 ; V_92 ++ , V_409 ++ ) {
if ( V_409 -> V_412 ==
V_413 ||
V_409 -> V_412 ==
V_414 ) {
V_271 = F_9 ( V_409 -> V_415 ) ;
F_163 ( V_6 , V_271 ) ;
F_164 ( V_271 , & V_407 , & V_408 ) ;
}
}
V_409 = ( T_26 * ) & V_358 -> V_410 [ 0 ] ;
for ( V_92 = 0 ; V_92 < V_358 -> V_411 ; V_92 ++ , V_409 ++ ) {
if ( F_75 ( V_358 -> V_182 ) &
V_416 )
continue;
if ( V_409 -> V_412 == V_417 ) {
V_271 = F_9 ( V_409 -> V_415 ) ;
F_164 ( V_271 , & V_407 , & V_408 ) ;
}
}
if ( V_407 )
F_155 ( V_6 , V_407 ) ;
if ( V_408 )
F_155 ( V_6 , V_408 ) ;
V_409 = ( T_26 * ) & V_358 -> V_410 [ 0 ] ;
for ( V_92 = 0 ; V_92 < V_358 -> V_411 ; V_92 ++ , V_409 ++ ) {
if ( V_409 -> V_412 != V_417 )
continue;
V_27 = F_9 ( V_409 -> V_418 ) ;
V_271 = F_9 ( V_409 -> V_415 ) ;
F_166 ( V_27 , V_6 -> V_177 ) ;
if ( ! V_271 )
F_151 ( V_6 , V_27 ) ;
else if ( V_271 == V_407 || V_271 == V_408 ) {
V_383 = F_68 ( sizeof( * V_383 ) , V_359 ) ;
F_167 ( ! V_383 ) ;
F_152 ( & V_383 -> V_67 ) ;
V_383 -> V_27 = V_27 ;
F_24 ( & V_383 -> V_67 , & V_6 -> V_387 ) ;
F_23 ( V_6 , F_3 ( V_58
L_106 , V_6 -> V_35 ,
V_27 ) ) ;
} else
F_151 ( V_6 , V_27 ) ;
}
}
static void
F_168 ( struct V_5 * V_6 ,
T_27 * V_358 )
{
T_10 V_200 ;
if ( V_358 -> V_412 != V_419 )
return;
V_200 = F_75 ( V_358 -> V_420 ) ;
if ( V_200 == V_210 || V_200 ==
V_209 )
F_163 ( V_6 ,
F_9 ( V_358 -> V_415 ) ) ;
}
static void
F_169 ( struct V_5 * V_6 )
{
struct V_87 * V_90 ;
T_4 V_88 ;
T_4 V_238 = 0 ;
for ( V_88 = 1 ; V_88 <= V_6 -> V_93 ; V_88 ++ ) {
V_90 = F_38 ( V_6 , V_88 ) ;
if ( ! V_90 )
continue;
V_238 ++ ;
F_161 ( V_6 , V_88 ) ;
F_170 ( V_90 ) ;
if ( V_6 -> V_317 )
V_90 -> V_346 = V_347 << 16 ;
else
V_90 -> V_346 = V_349 << 16 ;
V_90 -> V_348 ( V_90 ) ;
}
F_117 ( V_6 , F_3 ( V_58 L_124 ,
V_6 -> V_35 , V_238 ) ) ;
}
static void
F_171 ( struct V_87 * V_90 , T_11 * V_103 )
{
T_4 V_421 ;
unsigned char V_422 = F_172 ( V_90 ) ;
unsigned char V_423 = F_173 ( V_90 ) ;
if ( V_423 == V_424 || V_422 == V_425 )
return;
if ( V_422 == V_426 )
V_421 = V_427 ;
else if ( V_422 == V_428 )
V_421 = V_429 ;
else
return;
switch ( V_423 ) {
case V_430 :
case V_431 :
V_421 |= V_432 |
V_433 |
V_434 ;
V_103 -> V_435 . V_436 . V_437 =
F_174 ( F_175 ( V_90 ) ) ;
break;
case V_438 :
V_421 |= V_434 ;
break;
}
V_103 -> V_439 = F_176 ( V_90 -> V_43 -> V_440 ) ;
V_103 -> V_441 = F_118 ( V_421 ) ;
}
static void
F_177 ( struct V_87 * V_90 , T_4 V_30 )
{
T_6 V_442 ;
T_6 V_443 ;
T_6 V_444 ;
switch ( V_30 ) {
case V_445 :
V_442 = 0x01 ;
break;
case V_446 :
V_442 = 0x02 ;
break;
case V_447 :
V_442 = 0x03 ;
break;
default:
V_442 = 0x00 ;
break;
}
if ( V_90 -> V_118 == V_119 ) {
V_443 = V_448 ;
V_444 = V_449 ;
} else {
V_443 = V_450 ;
V_444 = V_451 ;
}
F_178 ( 0 , V_90 -> V_452 , V_443 , 0x10 , V_442 ) ;
V_90 -> V_346 = V_453 << 24 | ( V_444 << 16 ) |
V_454 ;
}
static inline T_6
F_179 ( struct V_5 * V_6 , T_4 V_88 )
{
return V_6 -> V_89 [ V_88 - 1 ] . V_455 ;
}
static inline void
F_180 ( struct V_5 * V_6 , T_4 V_88 , T_6 V_455 )
{
V_6 -> V_89 [ V_88 - 1 ] . V_455 = V_455 ;
}
static void
F_181 ( struct V_5 * V_6 , struct V_87 * V_90 ,
struct V_47 * V_48 , T_11 * V_103 ,
T_4 V_88 )
{
T_10 V_456 , V_457 , V_458 , V_459 , V_460 , V_461 ;
T_10 V_242 , V_243 ;
T_6 V_227 , * V_462 , * V_463 , * V_464 , * V_465 ;
T_6 V_466 = V_90 -> V_467 [ 0 ] ;
if ( V_466 == V_468 || V_466 == V_469 ||
V_466 == V_470 || V_466 == V_471 ) {
V_462 = V_103 -> V_435 . V_472 ;
if ( ( V_466 < V_468 ) || ! ( V_462 [ 2 ] | V_462 [ 3 ] | V_462 [ 4 ]
| V_462 [ 5 ] ) ) {
V_461 = F_51 ( V_90 ) >> 9 ;
V_464 = V_465 = ( V_466 < V_468 ) ? & V_462 [ 2 ] :
& V_462 [ 6 ] ;
V_463 = ( T_6 * ) & V_456 + 3 ;
* V_463 -- = * V_464 ++ ;
* V_463 -- = * V_464 ++ ;
* V_463 -- = * V_464 ++ ;
* V_463 = * V_464 ;
if ( ( ( T_1 ) V_456 + ( T_1 ) V_461 - 1 ) <=
( T_10 ) V_48 -> V_253 ) {
V_242 = V_48 -> V_242 ;
V_243 = V_48 -> V_252 ;
V_458 = V_456 & ( V_242 - 1 ) ;
if ( ( V_458 + V_461 ) <= V_242 ) {
V_227 = V_48 -> V_227 ;
V_457 = V_456 >> V_243 ;
V_459 = V_457 / V_227 ;
V_460 = V_457 % V_227 ;
V_457 = ( V_459 << V_243 ) +
V_458 ;
V_103 -> V_233 =
F_118 ( V_48 ->
V_248 [ V_460 ] ) ;
V_463 = ( T_6 * ) & V_457 + 3 ;
* V_465 ++ = * V_463 -- ;
* V_465 ++ = * V_463 -- ;
* V_465 ++ = * V_463 -- ;
* V_465 = * V_463 ;
F_180 ( V_6 , V_88 , 1 ) ;
}
}
}
}
}
static int
F_182 ( struct V_87 * V_90 , void (* V_299)( struct V_87 * ) )
{
struct V_5 * V_6 = F_57 ( V_90 -> V_43 -> V_143 ) ;
struct V_145 * V_146 ;
struct V_147 * V_148 ;
struct V_47 * V_48 ;
T_11 * V_103 ;
T_10 V_473 ;
T_4 V_88 ;
V_90 -> V_348 = V_299 ;
V_146 = V_90 -> V_43 -> V_150 ;
if ( ! V_146 || ! V_146 -> V_152 ) {
V_90 -> V_346 = V_347 << 16 ;
V_90 -> V_348 ( V_90 ) ;
return 0 ;
}
if ( V_6 -> V_317 || V_6 -> V_316 ) {
V_90 -> V_346 = V_347 << 16 ;
V_90 -> V_348 ( V_90 ) ;
return 0 ;
}
V_148 = V_146 -> V_152 ;
if ( V_148 -> V_27 == V_173 ) {
V_90 -> V_346 = V_347 << 16 ;
V_90 -> V_348 ( V_90 ) ;
return 0 ;
}
if ( V_6 -> V_315 || V_6 -> V_474 )
return V_475 ;
else if ( V_146 -> V_364 || V_148 -> V_301 )
return V_476 ;
else if ( V_148 -> V_385 ) {
V_90 -> V_346 = V_347 << 16 ;
V_90 -> V_348 ( V_90 ) ;
return 0 ;
}
if ( V_90 -> V_118 == V_477 )
V_473 = V_478 ;
else if ( V_90 -> V_118 == V_119 )
V_473 = V_479 ;
else
V_473 = V_480 ;
if ( ! ( V_146 -> V_65 & V_179 ) ) {
if ( V_90 -> V_43 -> V_155 ) {
if ( V_90 -> V_43 -> V_164 )
V_473 |= V_481 ;
else
V_473 |= V_482 ;
} else
V_473 |= ( 0x500 ) ;
} else
V_473 |= V_482 ;
if ( ! V_6 -> V_190 && ! F_76 ( & V_90 -> V_43 -> V_224 ) &&
F_95 ( V_90 -> V_43 ) && V_90 -> V_483 != 32 )
V_473 |= V_484 ;
V_88 = F_183 ( V_6 , V_6 -> V_485 , V_90 ) ;
if ( ! V_88 ) {
F_3 ( V_34 L_67 ,
V_6 -> V_35 , V_36 ) ;
goto V_75;
}
V_103 = F_47 ( V_6 , V_88 ) ;
memset ( V_103 , 0 , sizeof( T_11 ) ) ;
F_171 ( V_90 , V_103 ) ;
if ( V_90 -> V_483 == 32 )
V_473 |= 4 << V_486 ;
V_103 -> V_327 = V_487 ;
if ( V_146 -> V_152 -> V_65 &
V_178 )
V_103 -> V_327 = V_488 ;
else
V_103 -> V_327 = V_487 ;
V_103 -> V_233 =
F_118 ( V_146 -> V_152 -> V_27 ) ;
V_103 -> V_489 = F_176 ( F_51 ( V_90 ) ) ;
V_103 -> V_490 = F_176 ( V_473 ) ;
V_103 -> V_491 = F_118 ( V_90 -> V_483 ) ;
V_103 -> V_492 = V_493 ;
V_103 -> V_494 = V_495 ;
V_103 -> V_496 =
F_184 ( V_6 , V_88 ) ;
V_103 -> V_497 = F_52 ( T_11 , V_127 ) / 4 ;
V_103 -> V_498 = F_118 ( V_499 +
V_500 ) ;
V_103 -> V_501 = 0 ;
V_103 -> V_502 = 0 ;
F_119 ( V_146 -> V_95 , (struct V_331 * )
V_103 -> V_332 ) ;
memcpy ( V_103 -> V_435 . V_472 , V_90 -> V_467 , V_90 -> V_483 ) ;
if ( ! V_103 -> V_489 ) {
F_185 ( V_6 , & V_103 -> V_127 ) ;
} else {
if ( F_46 ( V_6 , V_90 , V_88 ) ) {
F_161 ( V_6 , V_88 ) ;
goto V_75;
}
}
V_48 = V_148 -> V_48 ;
if ( V_48 && V_48 -> V_236 )
F_181 ( V_6 , V_90 , V_48 , V_103 ,
V_88 ) ;
if ( F_186 ( V_103 -> V_327 == V_487 ) )
F_187 ( V_6 , V_88 ,
F_9 ( V_103 -> V_233 ) ) ;
else
F_160 ( V_6 , V_88 ) ;
return 0 ;
V_75:
return V_475 ;
}
void
F_188 ( struct V_5 * V_6 , struct V_87 * V_90 ,
T_28 * V_29 , T_4 V_88 )
{
T_10 V_503 ;
T_6 * V_504 ;
T_4 V_30 = F_9 ( V_29 -> V_38 ) &
V_39 ;
T_6 V_505 = V_29 -> V_506 ;
T_6 V_507 = V_29 -> V_508 ;
char * V_509 = NULL ;
char * V_510 = NULL ;
char * V_511 = V_6 -> V_512 ;
T_10 V_513 = F_75 ( V_29 -> V_335 ) ;
struct V_45 * V_46 = NULL ;
unsigned long V_65 ;
struct V_168 * V_70 = V_90 -> V_43 -> V_343 ;
struct V_147 * V_344 = V_70 -> V_150 ;
char * V_345 = NULL ;
if ( ! V_344 )
return;
if ( V_6 -> V_270 )
V_345 = L_73 ;
else
V_345 = L_74 ;
if ( V_513 == 0x31170000 )
return;
switch ( V_30 ) {
case V_40 :
V_509 = L_125 ;
break;
case V_514 :
V_509 = L_126 ;
break;
case V_515 :
V_509 = L_127 ;
break;
case V_516 :
V_509 = L_128 ;
break;
case V_517 :
V_509 = L_129 ;
break;
case V_518 :
V_509 = L_130 ;
break;
case V_519 :
V_509 = L_131 ;
break;
case V_520 :
V_509 = L_132 ;
break;
case V_521 :
V_509 = L_133 ;
break;
case V_522 :
V_509 = L_134 ;
break;
case V_523 :
V_509 = L_135 ;
break;
case V_524 :
V_509 = L_136 ;
break;
case V_525 :
V_509 = L_137 ;
break;
case V_526 :
V_509 = L_138 ;
break;
case V_445 :
V_509 = L_139 ;
break;
case V_447 :
V_509 = L_140 ;
break;
case V_446 :
V_509 = L_141 ;
break;
default:
V_509 = L_61 ;
break;
}
switch ( V_507 ) {
case V_527 :
V_510 = L_142 ;
break;
case V_528 :
V_510 = L_143 ;
break;
case V_529 :
V_510 = L_144 ;
break;
case V_530 :
V_510 = L_145 ;
break;
case V_531 :
V_510 = L_146 ;
break;
case V_532 :
V_510 = L_147 ;
break;
case V_533 :
V_510 = L_148 ;
break;
case V_534 :
V_510 = L_149 ;
break;
case V_535 :
V_510 = L_150 ;
break;
case V_536 :
V_510 = L_151 ;
break;
case V_537 :
V_510 = L_152 ;
break;
default:
V_510 = L_61 ;
break;
}
V_511 [ 0 ] = '\0' ;
if ( ! V_505 )
V_511 = L_153 ;
if ( V_505 & V_538 )
strcat ( V_511 , L_154 ) ;
if ( V_505 & V_539 )
strcat ( V_511 , L_155 ) ;
if ( V_505 & V_540 )
strcat ( V_511 , L_156 ) ;
if ( V_505 & V_541 )
strcat ( V_511 , L_157 ) ;
if ( V_505 & V_542 )
strcat ( V_511 , L_158 ) ;
F_126 ( V_90 ) ;
if ( V_344 -> V_65 & V_153 ) {
F_3 ( V_99 L_159 , V_6 -> V_35 ,
V_345 , ( unsigned long long ) V_344 -> V_9 ) ;
} else {
F_18 ( & V_6 -> V_66 , V_65 ) ;
V_46 = F_15 ( V_6 ,
V_344 -> V_9 ) ;
if ( V_46 ) {
F_3 ( V_99 L_160
L_161 , V_6 -> V_35 , V_46 -> V_9 ,
V_46 -> V_273 ) ;
F_3 ( V_99
L_162 ,
V_6 -> V_35 , V_46 -> V_14 ,
V_46 -> V_18 ) ;
}
F_21 ( & V_6 -> V_66 , V_65 ) ;
}
F_3 ( V_99 L_163
L_164 , V_6 -> V_35 , F_9 ( V_29 -> V_233 ) ,
V_509 , V_30 , V_88 ) ;
F_3 ( V_99 L_165
L_166 , V_6 -> V_35 , F_51 ( V_90 ) , V_90 -> V_543 ,
F_189 ( V_90 ) ) ;
F_3 ( V_99 L_167
L_168 , V_6 -> V_35 , F_9 ( V_29 -> V_544 ) ,
F_75 ( V_29 -> V_545 ) , V_90 -> V_346 ) ;
F_3 ( V_99 L_169
L_170 , V_6 -> V_35 , V_510 ,
V_507 , V_511 , V_505 ) ;
if ( V_505 & V_542 ) {
struct V_546 V_547 ;
F_190 ( V_90 -> V_452 , & V_547 ) ;
F_3 ( V_99 L_171
L_172 , V_6 -> V_35 , V_547 . V_548 ,
V_547 . V_549 , V_547 . V_442 , F_75 ( V_29 -> V_550 ) ) ;
}
if ( V_505 & V_538 ) {
V_503 = F_75 ( V_29 -> V_551 ) ;
V_504 = ( T_6 * ) & V_503 ;
F_102 ( V_6 , V_504 [ 0 ] ) ;
}
}
static void
F_191 ( struct V_5 * V_6 , T_4 V_27 )
{
T_29 V_29 ;
T_30 V_103 ;
memset ( & V_103 , 0 , sizeof( T_30 ) ) ;
V_103 . V_327 = V_552 ;
V_103 . V_553 = V_554 ;
V_103 . V_555 =
F_176 ( V_556 ) ;
V_103 . V_233 = F_118 ( V_27 ) ;
V_103 . V_182 = V_557 ;
if ( ( F_192 ( V_6 , & V_29 ,
& V_103 ) ) != 0 ) {
F_3 ( V_34 L_2 , V_6 -> V_35 ,
__FILE__ , __LINE__ , V_36 ) ;
return;
}
if ( V_29 . V_38 || V_29 . V_335 ) {
F_23 ( V_6 , F_3 ( V_58 L_173
L_174 , V_6 -> V_35 ,
F_9 ( V_29 . V_38 ) ,
F_75 ( V_29 . V_335 ) ) ) ;
return;
}
}
static void
F_193 ( struct V_5 * V_6 , T_4 V_27 )
{
struct V_351 * V_352 ;
V_352 = F_68 ( sizeof( struct V_351 ) , V_359 ) ;
if ( ! V_352 )
return;
V_352 -> V_360 = V_558 ;
V_352 -> V_559 = V_27 ;
V_352 -> V_6 = V_6 ;
F_133 ( V_6 , V_352 ) ;
}
static void
F_194 ( struct V_5 * V_6 , T_4 V_27 )
{
struct V_168 * V_70 ;
struct V_147 * V_148 ;
T_31 * V_560 ;
T_32 * V_358 ;
struct V_45 * V_46 ;
T_33 V_226 ;
unsigned long V_65 ;
F_18 ( & V_6 -> V_66 , V_65 ) ;
V_46 = F_16 ( V_6 , V_27 ) ;
if ( ! V_46 ) {
F_21 ( & V_6 -> V_66 , V_65 ) ;
return;
}
V_70 = V_46 -> V_70 ;
V_148 = V_70 -> V_150 ;
if ( ( V_148 -> V_65 & V_178 ) ||
( ( V_148 -> V_65 & V_153 ) ) ) {
F_21 ( & V_6 -> V_66 , V_65 ) ;
return;
}
F_127 ( V_561 , V_70 , L_175 ) ;
F_21 ( & V_6 -> V_66 , V_65 ) ;
if ( V_6 -> V_562 -> V_563 == V_564 )
F_193 ( V_6 , V_27 ) ;
V_226 = F_52 ( T_31 , V_565 ) +
sizeof( T_32 ) ;
V_560 = F_68 ( V_226 , V_359 ) ;
if ( ! V_560 ) {
F_3 ( V_34 L_2 ,
V_6 -> V_35 , __FILE__ , __LINE__ , V_36 ) ;
return;
}
V_560 -> V_327 = V_566 ;
V_560 -> V_567 =
F_118 ( V_568 ) ;
V_560 -> V_296 = V_226 / 4 ;
V_560 -> V_569 =
F_118 ( sizeof( T_32 ) / 4 ) ;
V_358 = ( T_32 * )
V_560 -> V_565 ;
V_358 -> V_412 = V_570 ;
V_358 -> V_571 = 0x5D ;
V_358 -> V_233 = F_118 ( V_27 ) ;
V_358 -> V_11 = F_195 ( V_148 -> V_9 ) ;
F_196 ( V_6 , V_560 ) ;
F_20 ( V_560 ) ;
}
static T_6
F_197 ( struct V_5 * V_6 , T_4 V_88 , T_6 V_290 , T_10 V_291 )
{
T_11 * V_103 ;
T_28 * V_29 ;
struct V_87 * V_90 ;
T_4 V_30 ;
T_10 V_572 ;
T_6 V_505 ;
T_6 V_507 ;
T_10 V_513 ;
struct V_145 * V_146 ;
T_10 V_281 = 0 ;
unsigned long V_65 ;
V_29 = F_105 ( V_6 , V_291 ) ;
V_90 = F_38 ( V_6 , V_88 ) ;
if ( V_90 == NULL )
return 1 ;
V_103 = F_47 ( V_6 , V_88 ) ;
if ( V_29 == NULL ) {
V_90 -> V_346 = V_451 << 16 ;
goto V_75;
}
V_146 = V_90 -> V_43 -> V_150 ;
if ( ! V_146 || ! V_146 -> V_152 ||
V_146 -> V_152 -> V_385 ) {
V_90 -> V_346 = V_347 << 16 ;
goto V_75;
}
if ( F_179 ( V_6 , V_88 ) ) {
F_18 ( & V_6 -> V_91 , V_65 ) ;
V_6 -> V_89 [ V_88 - 1 ] . V_90 = V_90 ;
F_21 ( & V_6 -> V_91 , V_65 ) ;
F_180 ( V_6 , V_88 , 0 ) ;
memcpy ( V_103 -> V_435 . V_472 , V_90 -> V_467 , V_90 -> V_483 ) ;
V_103 -> V_233 =
F_118 ( V_146 -> V_152 -> V_27 ) ;
F_187 ( V_6 , V_88 ,
V_146 -> V_152 -> V_27 ) ;
return 0 ;
}
V_505 = V_29 -> V_506 ;
if ( V_505 & V_538 )
V_281 =
F_75 ( V_29 -> V_551 ) & 0xFF ;
if ( ! V_146 -> V_573 ) {
V_146 -> V_573 ++ ;
if ( ! V_6 -> V_190 && ! F_76 ( & V_90 -> V_43 -> V_224 ) &&
F_95 ( V_90 -> V_43 ) &&
V_281 == V_284 ) {
F_198 ( V_90 -> V_43 ) ;
F_50 ( V_7 , V_90 -> V_43 , L_176 ) ;
}
}
V_572 = F_75 ( V_29 -> V_545 ) ;
F_199 ( V_90 , F_51 ( V_90 ) - V_572 ) ;
V_30 = F_9 ( V_29 -> V_38 ) ;
if ( V_30 & V_574 )
V_513 = F_75 ( V_29 -> V_335 ) ;
else
V_513 = 0 ;
V_30 &= V_39 ;
V_507 = V_29 -> V_508 ;
if ( V_30 == V_519 && V_572 == 0 &&
( V_507 == V_530 ||
V_507 == V_533 ||
V_507 == V_535 ) ) {
V_30 = V_40 ;
}
if ( V_505 & V_542 ) {
struct V_546 V_547 ;
const void * V_575 = F_200 ( V_6 ,
V_88 ) ;
T_10 V_226 = F_201 ( T_10 , V_495 ,
F_75 ( V_29 -> V_550 ) ) ;
memcpy ( V_90 -> V_452 , V_575 , V_226 ) ;
F_190 ( V_90 -> V_452 , & V_547 ) ;
if ( V_547 . V_549 == 0x5D )
F_194 ( V_6 ,
F_9 ( V_29 -> V_233 ) ) ;
}
switch ( V_30 ) {
case V_576 :
case V_577 :
V_90 -> V_346 = V_578 ;
break;
case V_517 :
V_90 -> V_346 = V_347 << 16 ;
break;
case V_525 :
if ( V_146 -> V_364 ) {
V_90 -> V_346 = V_579 << 16 ;
goto V_75;
}
case V_522 :
case V_526 :
V_90 -> V_346 = V_349 << 16 ;
break;
case V_523 :
if ( ( V_572 == 0 ) || ( V_90 -> V_543 > V_572 ) )
V_90 -> V_346 = V_580 << 16 ;
else
V_90 -> V_346 = ( V_451 << 16 ) | V_507 ;
break;
case V_519 :
V_90 -> V_346 = ( V_451 << 16 ) | V_507 ;
if ( ( V_505 & V_542 ) )
break;
if ( V_572 < V_90 -> V_543 ) {
if ( V_507 == V_578 )
V_90 -> V_346 = V_578 ;
else
V_90 -> V_346 = V_580 << 16 ;
} else if ( V_505 & ( V_541 |
V_540 ) )
V_90 -> V_346 = V_580 << 16 ;
else if ( V_505 & V_539 )
V_90 -> V_346 = V_349 << 16 ;
else if ( ! V_572 && V_90 -> V_467 [ 0 ] == V_581 ) {
V_29 -> V_506 = V_542 ;
V_29 -> V_508 = V_454 ;
V_90 -> V_346 = ( V_453 << 24 ) |
V_454 ;
V_90 -> V_452 [ 0 ] = 0x70 ;
V_90 -> V_452 [ 2 ] = V_448 ;
V_90 -> V_452 [ 12 ] = 0x20 ;
V_90 -> V_452 [ 13 ] = 0 ;
}
break;
case V_518 :
F_199 ( V_90 , 0 ) ;
case V_515 :
case V_40 :
V_90 -> V_346 = ( V_451 << 16 ) | V_507 ;
if ( V_281 ==
V_284 ||
( V_505 & ( V_541 |
V_540 ) ) )
V_90 -> V_346 = V_580 << 16 ;
else if ( V_505 & V_539 )
V_90 -> V_346 = V_349 << 16 ;
break;
case V_445 :
case V_447 :
case V_446 :
F_177 ( V_90 , V_30 ) ;
break;
case V_521 :
case V_514 :
case V_582 :
case V_583 :
case V_584 :
case V_585 :
case V_520 :
case V_524 :
default:
V_90 -> V_346 = V_580 << 16 ;
break;
}
#ifdef F_154
if ( V_90 -> V_346 && ( V_6 -> V_8 & V_586 ) )
F_188 ( V_6 , V_90 , V_29 , V_88 ) ;
#endif
V_75:
F_170 ( V_90 ) ;
V_90 -> V_348 ( V_90 ) ;
return 1 ;
}
static void
F_202 ( struct V_5 * V_6 )
{
T_4 V_226 ;
T_4 V_30 ;
int V_92 ;
T_9 V_29 ;
T_34 * V_587 = NULL ;
T_4 V_588 ;
T_6 V_589 ;
F_117 ( V_6 , F_3 ( V_58
L_177 ,
V_6 -> V_35 , ( unsigned long long ) V_6 -> V_31 . V_9 ) ) ;
V_226 = F_52 ( T_34 , V_590 ) + ( V_6 -> V_31 . V_32
* sizeof( V_591 ) ) ;
V_587 = F_68 ( V_226 , V_172 ) ;
if ( ! V_587 ) {
F_3 ( V_34 L_2 ,
V_6 -> V_35 , __FILE__ , __LINE__ , V_36 ) ;
return;
}
if ( ( F_203 ( V_6 , & V_29 ,
V_587 , V_226 ) ) != 0 )
goto V_75;
V_30 = F_9 ( V_29 . V_38 ) & V_39 ;
if ( V_30 != V_40 )
goto V_75;
for ( V_92 = 0 ; V_92 < V_6 -> V_31 . V_32 ; V_92 ++ ) {
V_589 = V_587 -> V_590 [ V_92 ] . V_592 >> 4 ;
if ( V_92 == 0 )
V_6 -> V_31 . V_27 = F_9 ( V_587 ->
V_590 [ 0 ] . V_593 ) ;
V_6 -> V_31 . V_273 [ V_92 ] . V_27 = V_6 -> V_31 . V_27 ;
V_588 = F_9 ( V_587 -> V_590 [ V_92 ] .
V_377 ) ;
if ( V_588 && V_589 < V_594 )
V_589 = V_594 ;
F_204 ( V_6 , V_6 -> V_31 . V_9 ,
V_588 , V_92 , V_589 ) ;
}
V_75:
F_20 ( V_587 ) ;
}
static void
F_205 ( struct V_5 * V_6 )
{
int V_92 ;
T_9 V_29 ;
T_34 * V_587 = NULL ;
T_35 * V_595 = NULL ;
T_36 V_596 ;
T_8 V_28 ;
T_37 V_597 ;
T_4 V_30 ;
T_4 V_226 ;
T_4 V_598 ;
F_206 ( V_6 , & V_6 -> V_31 . V_32 ) ;
if ( ! V_6 -> V_31 . V_32 ) {
F_3 ( V_34 L_2 ,
V_6 -> V_35 , __FILE__ , __LINE__ , V_36 ) ;
return;
}
V_226 = F_52 ( T_34 , V_590 ) + ( V_6 -> V_31 . V_32 *
sizeof( V_591 ) ) ;
V_587 = F_68 ( V_226 , V_172 ) ;
if ( ! V_587 ) {
F_3 ( V_34 L_2 ,
V_6 -> V_35 , __FILE__ , __LINE__ , V_36 ) ;
return;
}
if ( ( F_203 ( V_6 , & V_29 ,
V_587 , V_226 ) ) ) {
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
V_226 = F_52 ( T_35 , V_590 ) + ( V_6 -> V_31 . V_32 *
sizeof( V_599 ) ) ;
V_595 = F_68 ( V_226 , V_172 ) ;
if ( ! V_595 ) {
F_3 ( V_34 L_2 ,
V_6 -> V_35 , __FILE__ , __LINE__ , V_36 ) ;
goto V_75;
}
if ( ( F_207 ( V_6 , & V_29 ,
V_595 , V_226 ) ) ) {
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
V_6 -> V_600 =
F_9 ( V_595 -> V_601 ) ;
V_598 =
F_9 ( V_595 -> V_602 ) ;
if ( V_598 & V_603 )
V_6 -> V_598 = ( V_598 &
V_604 ) * 16 ;
else
V_6 -> V_598 = V_598 &
V_604 ;
V_6 -> V_31 . V_605 = & V_6 -> V_142 -> V_606 ;
V_6 -> V_31 . V_273 = F_208 ( V_6 -> V_31 . V_32 ,
sizeof( struct V_607 ) , V_172 ) ;
if ( ! V_6 -> V_31 . V_273 ) {
F_3 ( V_34 L_2 ,
V_6 -> V_35 , __FILE__ , __LINE__ , V_36 ) ;
goto V_75;
}
for ( V_92 = 0 ; V_92 < V_6 -> V_31 . V_32 ; V_92 ++ ) {
if ( ( F_209 ( V_6 , & V_29 , & V_596 ,
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
V_6 -> V_31 . V_27 = F_9 ( V_587 ->
V_590 [ 0 ] . V_593 ) ;
V_6 -> V_31 . V_273 [ V_92 ] . V_27 = V_6 -> V_31 . V_27 ;
V_6 -> V_31 . V_273 [ V_92 ] . V_608 = V_92 ;
F_210 ( V_6 , & V_6 -> V_31 . V_273 [ V_92 ] ,
V_596 , V_6 -> V_31 . V_605 ) ;
}
if ( ( F_12 ( V_6 , & V_29 , & V_28 ,
V_33 , V_6 -> V_31 . V_27 ) ) ) {
F_3 ( V_34 L_2 ,
V_6 -> V_35 , __FILE__ , __LINE__ , V_36 ) ;
goto V_75;
}
V_6 -> V_31 . V_609 =
F_9 ( V_28 . V_610 ) ;
V_6 -> V_31 . V_9 = F_6 ( V_28 . V_11 ) ;
F_3 ( V_58 L_178
L_179 , V_6 -> V_35 , V_6 -> V_31 . V_27 ,
( unsigned long long ) V_6 -> V_31 . V_9 ,
V_6 -> V_31 . V_32 ) ;
if ( V_6 -> V_31 . V_609 ) {
if ( ! ( F_211 ( V_6 , & V_29 ,
& V_597 ,
V_611 ,
V_6 -> V_31 . V_609 ) ) ) {
V_6 -> V_31 . V_14 =
F_6 ( V_597 . V_16 ) ;
}
}
V_75:
F_20 ( V_595 ) ;
F_20 ( V_587 ) ;
}
static int
F_212 ( struct V_5 * V_6 , T_4 V_27 )
{
struct V_78 * V_79 ;
T_9 V_29 ;
T_38 V_612 ;
T_39 V_613 ;
T_37 V_597 ;
T_10 V_30 ;
T_4 V_614 ;
T_1 V_9 , V_69 = 0 ;
int V_92 ;
unsigned long V_65 ;
struct V_365 * V_366 = NULL ;
int V_20 = 0 ;
if ( ! V_27 )
return - 1 ;
if ( V_6 -> V_315 || V_6 -> V_317 )
return - 1 ;
if ( ( F_213 ( V_6 , & V_29 , & V_612 ,
V_615 , V_27 ) ) ) {
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
V_614 = F_9 ( V_612 . V_616 ) ;
if ( F_11 ( V_6 , V_614 , & V_69 )
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
V_20 = F_212 ( V_6 , V_614 ) ;
if ( V_20 != 0 )
return V_20 ;
}
}
F_18 ( & V_6 -> V_80 , V_65 ) ;
V_9 = F_6 ( V_612 . V_11 ) ;
V_79 = F_34 ( V_6 ,
V_9 ) ;
F_21 ( & V_6 -> V_80 , V_65 ) ;
if ( V_79 )
return 0 ;
V_79 = F_68 ( sizeof( struct V_78 ) ,
V_172 ) ;
if ( ! V_79 ) {
F_3 ( V_34 L_2 ,
V_6 -> V_35 , __FILE__ , __LINE__ , V_36 ) ;
return - 1 ;
}
V_79 -> V_27 = V_27 ;
V_79 -> V_32 = V_612 . V_617 ;
V_79 -> V_69 = V_69 ;
V_79 -> V_9 = V_9 ;
F_3 ( V_58 L_180
L_181 , V_6 -> V_35 ,
V_27 , V_614 , ( unsigned long long )
V_79 -> V_9 , V_79 -> V_32 ) ;
if ( ! V_79 -> V_32 )
goto V_618;
V_79 -> V_273 = F_208 ( V_79 -> V_32 ,
sizeof( struct V_607 ) , V_172 ) ;
if ( ! V_79 -> V_273 ) {
F_3 ( V_34 L_2 ,
V_6 -> V_35 , __FILE__ , __LINE__ , V_36 ) ;
V_20 = - 1 ;
goto V_618;
}
F_152 ( & V_79 -> V_619 ) ;
V_366 = F_25 ( V_6 , V_27 ,
V_69 ) ;
if ( ! V_366 ) {
F_3 ( V_34 L_2 ,
V_6 -> V_35 , __FILE__ , __LINE__ , V_36 ) ;
V_20 = - 1 ;
goto V_618;
}
V_79 -> V_605 = & V_366 -> V_171 -> V_169 ;
for ( V_92 = 0 ; V_92 < V_79 -> V_32 ; V_92 ++ ) {
if ( ( F_214 ( V_6 , & V_29 ,
& V_613 , V_92 , V_27 ) ) ) {
F_3 ( V_34 L_2 ,
V_6 -> V_35 , __FILE__ , __LINE__ , V_36 ) ;
V_20 = - 1 ;
goto V_618;
}
V_79 -> V_273 [ V_92 ] . V_27 = V_27 ;
V_79 -> V_273 [ V_92 ] . V_608 = V_92 ;
if ( ( F_215 ( V_6 ,
& V_79 -> V_273 [ V_92 ] , V_613 ,
V_79 -> V_605 ) ) ) {
F_3 ( V_34 L_2 ,
V_6 -> V_35 , __FILE__ , __LINE__ , V_36 ) ;
V_20 = - 1 ;
goto V_618;
}
}
if ( V_79 -> V_609 ) {
if ( ! ( F_211 ( V_6 , & V_29 ,
& V_597 , V_611 ,
V_79 -> V_609 ) ) ) {
V_79 -> V_14 =
F_6 ( V_597 . V_16 ) ;
}
}
F_35 ( V_6 , V_79 ) ;
return 0 ;
V_618:
if ( V_366 )
F_26 ( V_6 , V_79 -> V_9 ,
V_69 ) ;
F_20 ( V_79 ) ;
return V_20 ;
}
static T_6
F_216 ( struct V_5 * V_6 , T_4 V_88 , T_6 V_290 , T_10 V_291 )
{
T_18 * V_29 ;
V_29 = F_105 ( V_6 , V_291 ) ;
if ( V_6 -> V_620 . V_293 == V_294 )
return 1 ;
if ( V_6 -> V_620 . V_88 != V_88 )
return 1 ;
V_6 -> V_620 . V_293 |= V_295 ;
if ( V_29 ) {
memcpy ( V_6 -> V_620 . V_291 , V_29 ,
V_29 -> V_296 * 4 ) ;
V_6 -> V_620 . V_293 |= V_297 ;
}
V_6 -> V_620 . V_293 &= ~ V_298 ;
F_106 ( & V_6 -> V_620 . V_299 ) ;
return 1 ;
}
void
F_217 ( struct V_5 * V_6 , T_1 V_9 )
{
struct V_78 * V_79 ;
unsigned long V_65 ;
if ( V_6 -> V_315 )
return;
F_18 ( & V_6 -> V_80 , V_65 ) ;
V_79 = F_34 ( V_6 ,
V_9 ) ;
if ( ! V_79 ) {
F_21 ( & V_6 -> V_80 , V_65 ) ;
return;
}
F_19 ( & V_79 -> V_67 ) ;
F_21 ( & V_6 -> V_80 , V_65 ) ;
F_218 ( V_6 , V_79 ) ;
}
static T_6
F_219 ( struct V_5 * V_6 , T_1 V_9 ,
T_4 V_27 , T_6 V_621 )
{
T_6 V_20 = 1 ;
char * V_282 = NULL ;
switch ( V_621 ) {
case V_622 :
case V_623 :
V_20 = 0 ;
break;
case V_624 :
V_282 = L_182 ;
break;
case V_625 :
V_282 = L_183 ;
break;
case V_626 :
V_282 = L_184 ;
break;
case V_627 :
V_282 = L_185 ;
break;
case V_628 :
V_282 = L_186 ;
break;
case V_629 :
case V_630 :
case V_631 :
case V_632 :
case V_633 :
case V_634 :
case V_635 :
case V_636 :
case V_637 :
case V_638 :
case V_639 :
case V_640 :
V_282 = L_187 ;
break;
default:
V_282 = L_61 ;
break;
}
if ( ! V_20 )
return 0 ;
F_3 ( V_34 L_188
L_94 , V_6 -> V_35 , V_282 ,
( unsigned long long ) V_9 , V_27 ) ;
return V_20 ;
}
static void
F_220 ( struct V_5 * V_6 , T_4 V_27 )
{
T_9 V_29 ;
T_8 V_28 ;
struct V_45 * V_46 ;
T_10 V_30 ;
unsigned long V_65 ;
T_1 V_9 ;
struct V_168 * V_70 ;
struct V_147 * V_148 ;
T_10 V_82 ;
if ( ( F_12 ( V_6 , & V_29 , & V_28 ,
V_33 , V_27 ) ) )
return;
V_30 = F_9 ( V_29 . V_38 ) & V_39 ;
if ( V_30 != V_40 )
return;
V_82 = F_75 ( V_28 . V_183 ) ;
if ( ! ( F_36 ( V_82 ) ) )
return;
F_18 ( & V_6 -> V_66 , V_65 ) ;
V_9 = F_6 ( V_28 . V_11 ) ;
V_46 = F_15 ( V_6 ,
V_9 ) ;
if ( ! V_46 ) {
F_3 ( V_34 L_189
L_190 , V_6 -> V_35 , V_27 ) ;
F_21 ( & V_6 -> V_66 , V_65 ) ;
return;
}
if ( F_221 ( V_46 -> V_27 != V_27 ) ) {
V_70 = V_46 -> V_70 ;
V_148 = V_70 -> V_150 ;
F_127 ( V_7 , V_70 , L_191
L_192 , V_46 -> V_27 , V_27 ) ;
V_148 -> V_27 = V_27 ;
V_46 -> V_27 = V_27 ;
}
F_21 ( & V_6 -> V_66 , V_65 ) ;
if ( ! ( F_9 ( V_28 . V_182 ) &
V_641 ) ) {
F_3 ( V_34 L_189
L_193 , V_6 -> V_35 , V_27 ) ;
return;
}
if ( F_219 ( V_6 , V_9 , V_27 ,
V_28 . V_642 ) )
return;
F_145 ( V_6 , V_27 ) ;
}
static int
F_222 ( struct V_5 * V_6 , T_4 V_27 , T_6 V_643 , T_6 V_644 )
{
T_9 V_29 ;
T_8 V_28 ;
T_37 V_597 ;
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
if ( ! ( F_9 ( V_28 . V_182 ) &
V_641 ) ) {
F_3 ( V_34 L_2 ,
V_6 -> V_35 , __FILE__ , __LINE__ , V_36 ) ;
F_3 ( V_34 L_194 ,
V_6 -> V_35 , F_9 ( V_28 . V_182 ) ) ;
return - 1 ;
}
if ( F_219 ( V_6 , V_9 , V_27 ,
V_28 . V_642 ) )
return - 1 ;
V_82 = F_75 ( V_28 . V_183 ) ;
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
V_46 = F_68 ( sizeof( struct V_45 ) ,
V_172 ) ;
if ( ! V_46 ) {
F_3 ( V_34 L_2 ,
V_6 -> V_35 , __FILE__ , __LINE__ , V_36 ) ;
return - 1 ;
}
V_46 -> V_27 = V_27 ;
if ( F_11 ( V_6 , F_9
( V_28 . V_616 ) ,
& V_46 -> V_69 ) != 0 )
F_3 ( V_34 L_2 ,
V_6 -> V_35 , __FILE__ , __LINE__ , V_36 ) ;
V_46 -> V_609 =
F_9 ( V_28 . V_610 ) ;
V_46 -> V_18 =
F_9 ( V_28 . V_645 ) ;
V_46 -> V_82 = V_82 ;
V_46 -> V_9 = V_9 ;
V_46 -> V_273 = V_28 . V_646 ;
if ( V_46 -> V_609 && ! ( F_211 (
V_6 , & V_29 , & V_597 , V_611 ,
V_46 -> V_609 ) ) )
V_46 -> V_14 =
F_6 ( V_597 . V_16 ) ;
V_46 -> V_12 = F_6 ( V_28 . V_13 ) ;
if ( V_6 -> V_647 )
F_27 ( V_6 , V_46 ) ;
else
F_22 ( V_6 , V_46 ) ;
return 0 ;
}
static void
F_223 ( struct V_5 * V_6 ,
struct V_45 * V_46 )
{
struct V_45 V_648 ;
struct V_147 * V_148 ;
if ( ! V_46 )
return;
memcpy ( & V_648 , V_46 , sizeof( struct V_45 ) ) ;
F_17 ( V_6 , V_46 ) ;
F_23 ( V_6 , F_3 ( V_58 L_195
L_105 , V_6 -> V_35 , V_36 ,
V_648 . V_27 , ( unsigned long long )
V_648 . V_9 ) ) ;
if ( V_648 . V_70 && V_648 . V_70 -> V_150 ) {
V_148 = V_648 . V_70 -> V_150 ;
V_148 -> V_385 = 1 ;
F_145 ( V_6 , V_648 . V_27 ) ;
V_148 -> V_27 =
V_173 ;
}
F_145 ( V_6 , V_648 . V_27 ) ;
if ( ! V_6 -> V_649 )
F_26 ( V_6 ,
V_648 . V_9 ,
V_648 . V_69 ) ;
F_3 ( V_58 L_196
L_197 , V_6 -> V_35 , V_648 . V_27 ,
( unsigned long long ) V_648 . V_9 ) ;
F_23 ( V_6 , F_3 ( V_58 L_198
L_105 , V_6 -> V_35 , V_36 ,
V_648 . V_27 , ( unsigned long long )
V_648 . V_9 ) ) ;
}
void
F_224 ( struct V_5 * V_6 , T_1 V_9 )
{
struct V_45 * V_46 ;
unsigned long V_65 ;
if ( V_6 -> V_315 )
return;
F_18 ( & V_6 -> V_66 , V_65 ) ;
V_46 = F_15 ( V_6 ,
V_9 ) ;
if ( ! V_46 ) {
F_21 ( & V_6 -> V_66 , V_65 ) ;
return;
}
F_21 ( & V_6 -> V_66 , V_65 ) ;
F_223 ( V_6 , V_46 ) ;
}
static void
F_225 ( struct V_5 * V_6 ,
T_22 * V_358 )
{
int V_92 ;
T_4 V_27 ;
T_4 V_373 ;
T_6 V_374 ;
char * V_650 = NULL ;
T_6 V_589 , V_651 ;
switch ( V_358 -> V_400 ) {
case V_406 :
V_650 = L_199 ;
break;
case V_402 :
V_650 = L_200 ;
break;
case V_403 :
case 0 :
V_650 = L_201 ;
break;
case V_401 :
V_650 = L_202 ;
break;
default:
V_650 = L_203 ;
break;
}
F_3 ( V_58 L_204 ,
V_6 -> V_35 , V_650 ) ;
F_3 ( V_7 L_205
L_206 ,
F_9 ( V_358 -> V_399 ) ,
F_9 ( V_358 -> V_610 ) ,
V_358 -> V_378 , V_358 -> V_375 ) ;
for ( V_92 = 0 ; V_92 < V_358 -> V_375 ; V_92 ++ ) {
V_27 = F_9 ( V_358 -> V_376 [ V_92 ] . V_377 ) ;
if ( ! V_27 )
continue;
V_374 = V_358 -> V_378 + V_92 ;
V_373 = V_358 -> V_376 [ V_92 ] . V_379 &
V_380 ;
switch ( V_373 ) {
case V_652 :
V_650 = L_207 ;
break;
case V_398 :
V_650 = L_208 ;
break;
case V_381 :
V_650 = L_209 ;
break;
case V_653 :
V_650 = L_210 ;
break;
case V_654 :
V_650 = L_211 ;
break;
default:
V_650 = L_61 ;
break;
}
V_589 = V_358 -> V_376 [ V_92 ] . V_655 >> 4 ;
V_651 = V_358 -> V_376 [ V_92 ] . V_655 & 0xF ;
F_3 ( V_7 L_212
L_213 , V_374 ,
V_27 , V_650 , V_589 , V_651 ) ;
}
}
static void
F_226 ( struct V_5 * V_6 ,
struct V_351 * V_352 )
{
int V_92 ;
T_4 V_614 , V_27 ;
T_4 V_373 ;
T_6 V_374 , V_656 ;
struct V_78 * V_79 ;
struct V_45 * V_46 ;
T_1 V_9 ;
unsigned long V_65 ;
T_6 V_589 , V_651 ;
T_22 * V_358 = V_352 -> V_358 ;
#ifdef F_154
if ( V_6 -> V_8 & V_657 )
F_225 ( V_6 , V_358 ) ;
#endif
if ( V_6 -> V_316 || V_6 -> V_317 )
return;
if ( ! V_6 -> V_31 . V_32 )
F_205 ( V_6 ) ;
else
F_202 ( V_6 ) ;
if ( V_352 -> V_405 ) {
F_23 ( V_6 , F_3 ( V_58 L_214
L_215 , V_6 -> V_35 ) ) ;
return;
}
V_614 = F_9 ( V_358 -> V_399 ) ;
if ( V_358 -> V_400 == V_406 )
if ( F_212 ( V_6 , V_614 ) != 0 )
return;
F_18 ( & V_6 -> V_80 , V_65 ) ;
V_79 = F_33 ( V_6 ,
V_614 ) ;
F_21 ( & V_6 -> V_80 , V_65 ) ;
if ( V_79 ) {
V_9 = V_79 -> V_9 ;
V_656 = V_79 -> V_32 ;
} else if ( V_614 < V_6 -> V_31 . V_32 ) {
V_9 = V_6 -> V_31 . V_9 ;
V_656 = V_6 -> V_31 . V_32 ;
} else
return;
for ( V_92 = 0 ; V_92 < V_358 -> V_375 ; V_92 ++ ) {
if ( V_352 -> V_405 ) {
F_23 ( V_6 , F_3 ( V_58 L_216
L_217 , V_6 -> V_35 ) ) ;
return;
}
if ( V_6 -> V_315 || V_6 -> V_316 ||
V_6 -> V_317 )
return;
V_374 = V_358 -> V_378 + V_92 ;
if ( V_374 >= V_656 )
continue;
V_373 = V_358 -> V_376 [ V_92 ] . V_379 &
V_380 ;
if ( ( V_358 -> V_376 [ V_92 ] . V_379 &
V_658 ) && ( V_373 !=
V_398 ) )
continue;
V_27 = F_9 ( V_358 -> V_376 [ V_92 ] . V_377 ) ;
if ( ! V_27 )
continue;
V_589 = V_358 -> V_376 [ V_92 ] . V_655 >> 4 ;
V_651 = V_358 -> V_376 [ V_92 ] . V_655 & 0xF ;
switch ( V_373 ) {
case V_653 :
if ( V_6 -> V_315 )
break;
if ( V_589 == V_651 )
break;
F_204 ( V_6 , V_9 ,
V_27 , V_374 , V_589 ) ;
if ( V_589 < V_594 )
break;
F_220 ( V_6 , V_27 ) ;
break;
case V_652 :
if ( V_6 -> V_315 )
break;
F_204 ( V_6 , V_9 ,
V_27 , V_374 , V_589 ) ;
F_222 ( V_6 , V_27 , V_374 , 0 ) ;
break;
case V_398 :
F_18 ( & V_6 -> V_66 , V_65 ) ;
V_46 = F_16 ( V_6 ,
V_27 ) ;
if ( ! V_46 ) {
F_21 ( & V_6 -> V_66 ,
V_65 ) ;
break;
}
F_21 ( & V_6 -> V_66 , V_65 ) ;
F_223 ( V_6 , V_46 ) ;
break;
}
}
if ( V_358 -> V_400 == V_402 &&
V_79 )
F_217 ( V_6 , V_9 ) ;
}
static void
F_227 ( struct V_5 * V_6 ,
T_32 * V_358 )
{
char * V_659 = NULL ;
switch ( V_358 -> V_412 ) {
case V_570 :
V_659 = L_218 ;
break;
case V_660 :
V_659 = L_219 ;
break;
case V_661 :
V_659 = L_220 ;
break;
case V_662 :
V_659 = L_221 ;
break;
case V_663 :
V_659 = L_222 ;
break;
case V_664 :
V_659 = L_223 ;
break;
case V_665 :
V_659 = L_224 ;
break;
case V_666 :
V_659 = L_225 ;
break;
case V_667 :
V_659 = L_226 ;
break;
case V_668 :
V_659 = L_227 ;
break;
case V_669 :
V_659 = L_228 ;
break;
case V_670 :
V_659 = L_229 ;
break;
case V_671 :
V_659 = L_230 ;
break;
default:
V_659 = L_231 ;
break;
}
F_3 ( V_58 L_232
L_233 ,
V_6 -> V_35 , V_659 , F_9 ( V_358 -> V_233 ) ,
( unsigned long long ) F_6 ( V_358 -> V_11 ) ,
F_9 ( V_358 -> V_544 ) ) ;
if ( V_358 -> V_412 == V_570 )
F_3 ( V_58 L_234 , V_6 -> V_35 ,
V_358 -> V_571 , V_358 -> V_672 ) ;
F_3 ( V_7 L_235 ) ;
}
static void
F_228 ( struct V_5 * V_6 ,
struct V_351 * V_352 )
{
struct V_147 * V_673 ;
struct V_45 * V_46 ;
T_1 V_9 ;
unsigned long V_65 ;
T_32 * V_358 =
V_352 -> V_358 ;
#ifdef F_154
if ( V_6 -> V_8 & V_657 )
F_227 ( V_6 ,
V_358 ) ;
#endif
if ( ( V_6 -> V_256 . V_674 >> 8 ) < 0xC )
return;
if ( V_358 -> V_412 !=
V_661 &&
V_358 -> V_412 !=
V_667 )
return;
F_18 ( & V_6 -> V_66 , V_65 ) ;
V_9 = F_6 ( V_358 -> V_11 ) ;
V_46 = F_15 ( V_6 ,
V_9 ) ;
F_21 ( & V_6 -> V_66 , V_65 ) ;
if ( ! V_46 || ! V_46 -> V_70 )
return;
V_673 = V_46 -> V_70 -> V_150 ;
if ( ! V_673 )
return;
if ( V_358 -> V_412 ==
V_661 )
V_673 -> V_301 = 1 ;
else
V_673 -> V_301 = 0 ;
}
static void
F_229 ( struct V_5 * V_6 ,
T_41 * V_358 )
{
char * V_659 = NULL ;
switch ( V_358 -> V_412 ) {
case V_675 :
V_659 = L_236 ;
break;
case V_676 :
V_659 = L_237 ;
break;
default:
V_659 = L_231 ;
break;
}
F_3 ( V_58 L_238
L_239
L_240 , V_6 -> V_35 , V_659 ,
F_9 ( V_358 -> V_610 ) ,
( unsigned long long ) F_6 ( V_358 -> V_16 ) ,
F_9 ( V_358 -> V_677 ) ) ;
}
static void
F_230 ( struct V_5 * V_6 ,
struct V_351 * V_352 )
{
#ifdef F_154
if ( V_6 -> V_8 & V_657 )
F_229 ( V_6 ,
V_352 -> V_358 ) ;
#endif
}
static void
F_231 ( struct V_5 * V_6 ,
struct V_351 * V_352 )
{
struct V_87 * V_90 ;
struct V_138 * V_139 ;
T_4 V_88 , V_27 ;
T_10 V_95 ;
struct V_145 * V_146 ;
T_10 V_678 ;
T_10 V_679 ;
T_21 * V_29 ;
T_42 * V_358 = V_352 -> V_358 ;
T_4 V_30 ;
unsigned long V_65 ;
int V_74 ;
T_6 V_680 = 0 ;
T_6 V_681 ;
F_111 ( & V_6 -> V_292 . V_312 ) ;
F_23 ( V_6 , F_3 ( V_58 L_241
L_242 , V_6 -> V_35 , V_36 , V_358 -> V_646 ,
V_358 -> V_682 ) ) ;
F_146 ( V_6 ) ;
F_18 ( & V_6 -> V_91 , V_65 ) ;
V_29 = V_6 -> V_292 . V_291 ;
V_683:
if ( V_680 ++ == 5 ) {
F_23 ( V_6 , F_3 ( V_58 L_243 ,
V_6 -> V_35 , V_36 ) ) ;
goto V_75;
} else if ( V_680 > 1 )
F_23 ( V_6 , F_3 ( V_58 L_244 ,
V_6 -> V_35 , V_36 , V_680 - 1 ) ) ;
V_678 = 0 ;
V_679 = 0 ;
for ( V_88 = 1 ; V_88 <= V_6 -> V_93 ; V_88 ++ ) {
if ( V_6 -> V_315 )
goto V_75;
V_90 = F_37 ( V_6 , V_88 ) ;
if ( ! V_90 )
continue;
V_139 = V_90 -> V_43 ;
V_146 = V_139 -> V_150 ;
if ( ! V_146 || ! V_146 -> V_152 )
continue;
if ( V_146 -> V_152 -> V_65 &
V_178 )
continue;
if ( V_146 -> V_152 -> V_65 &
V_153 )
continue;
V_27 = V_146 -> V_152 -> V_27 ;
V_95 = V_146 -> V_95 ;
V_679 ++ ;
if ( V_6 -> V_315 )
goto V_75;
F_21 ( & V_6 -> V_91 , V_65 ) ;
V_74 = F_110 ( V_6 , V_27 , 0 , 0 , V_95 ,
V_342 , V_88 , 30 , 0 ,
V_684 ) ;
if ( V_74 == V_313 ) {
F_50 ( V_561 , V_139 ,
L_245
L_246 , V_90 ) ;
F_18 ( & V_6 -> V_91 , V_65 ) ;
goto V_683;
}
V_30 = F_9 ( V_29 -> V_38 )
& V_39 ;
if ( V_30 != V_40 ) {
F_50 ( V_561 , V_139 , L_247
L_248 , V_30 ,
V_90 ) ;
F_18 ( & V_6 -> V_91 , V_65 ) ;
goto V_683;
}
if ( V_29 -> V_338 ==
V_287 ||
V_29 -> V_338 ==
V_289 ) {
F_18 ( & V_6 -> V_91 , V_65 ) ;
continue;
}
V_681 = 0 ;
V_685:
if ( V_681 ++ == 60 ) {
F_23 ( V_6 , F_3 ( V_58
L_249 , V_6 -> V_35 ,
V_36 ) ) ;
F_18 ( & V_6 -> V_91 , V_65 ) ;
goto V_683;
}
if ( V_6 -> V_315 )
goto V_686;
V_74 = F_110 ( V_6 , V_27 , V_139 -> V_73 , V_139 -> V_72 ,
V_139 -> V_95 , V_326 , V_88 , 30 ,
V_90 -> V_305 , V_684 ) ;
if ( V_74 == V_313 ) {
F_50 ( V_561 , V_139 ,
L_250
L_81 , V_90 ) ;
goto V_685;
}
if ( V_681 > 1 )
F_50 ( V_561 , V_139 ,
L_251
L_252 ,
V_681 - 1 , V_90 ) ;
V_678 += F_75 ( V_29 -> V_336 ) ;
F_18 ( & V_6 -> V_91 , V_65 ) ;
}
if ( V_6 -> V_687 ) {
F_23 ( V_6 , F_3 ( V_58 L_253
L_254 , V_6 -> V_35 , V_36 ) ) ;
V_6 -> V_687 = 0 ;
goto V_683;
}
V_75:
F_21 ( & V_6 -> V_91 , V_65 ) ;
V_686:
F_23 ( V_6 , F_3 ( V_58
L_255 ,
V_6 -> V_35 , V_36 , V_679 , V_678 ) ) ;
V_6 -> V_688 = 0 ;
if ( ! V_6 -> V_315 )
F_143 ( V_6 ) ;
F_124 ( & V_6 -> V_292 . V_312 ) ;
}
static void
F_232 ( struct V_5 * V_6 ,
struct V_351 * V_352 )
{
T_43 * V_358 = V_352 -> V_358 ;
#ifdef F_154
if ( V_6 -> V_8 & V_657 ) {
F_3 ( V_58 L_256 , V_6 -> V_35 ,
( V_358 -> V_412 == V_689 ) ?
L_257 : L_258 ) ;
if ( V_358 -> V_690 )
F_3 ( L_259 ,
F_75 ( V_358 -> V_690 ) ) ;
F_3 ( L_235 ) ;
}
#endif
if ( V_358 -> V_412 == V_689 &&
! V_6 -> V_31 . V_32 )
F_205 ( V_6 ) ;
}
static void
F_233 ( struct V_138 * V_139 , void * V_181 )
{
int V_20 ;
V_139 -> V_181 = V_181 ? 1 : 0 ;
F_50 ( V_7 , V_139 , L_260 ,
V_139 -> V_181 ? L_261 : L_262 ) ;
V_20 = F_234 ( V_139 ) ;
}
static void
F_235 ( struct V_168 * V_70 , int V_181 )
{
struct V_147 * V_148 ;
if ( V_70 == NULL )
return;
V_148 = V_70 -> V_150 ;
if ( V_181 )
V_148 -> V_65 |= V_178 ;
else
V_148 -> V_65 &= ~ V_178 ;
F_236 ( V_70 , V_181 ? ( void * ) 1 : NULL ,
F_233 ) ;
}
static void
F_237 ( struct V_5 * V_6 ,
T_26 * V_409 )
{
struct V_47 * V_48 ;
unsigned long V_65 ;
T_1 V_52 ;
T_4 V_27 = F_9 ( V_409 -> V_415 ) ;
int V_20 ;
F_98 ( V_6 , V_27 , & V_52 ) ;
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
V_48 = F_68 ( sizeof( struct V_47 ) , V_172 ) ;
if ( ! V_48 ) {
F_3 ( V_34
L_2 , V_6 -> V_35 ,
__FILE__ , __LINE__ , V_36 ) ;
return;
}
V_48 -> V_72 = V_6 -> V_691 ++ ;
V_48 -> V_73 = V_174 ;
V_48 -> V_27 = V_27 ;
V_48 -> V_52 = V_52 ;
F_31 ( V_6 , V_48 ) ;
if ( ! V_6 -> V_647 ) {
V_20 = F_238 ( V_6 -> V_142 , V_174 ,
V_48 -> V_72 , 0 ) ;
if ( V_20 )
F_32 ( V_6 , V_48 ) ;
} else
F_13 ( V_6 , V_48 , 1 ) ;
}
static void
F_239 ( struct V_5 * V_6 , T_4 V_27 )
{
struct V_47 * V_48 ;
unsigned long V_65 ;
struct V_147 * V_148 ;
F_18 ( & V_6 -> V_76 , V_65 ) ;
V_48 = F_29 ( V_6 , V_27 ) ;
F_21 ( & V_6 -> V_76 , V_65 ) ;
if ( ! V_48 )
return;
if ( V_48 -> V_70 ) {
V_148 = V_48 -> V_70 -> V_150 ;
V_148 -> V_385 = 1 ;
F_240 ( & V_48 -> V_70 -> V_169 ) ;
}
F_3 ( V_58 L_263
L_197 , V_6 -> V_35 , V_48 -> V_27 ,
( unsigned long long ) V_48 -> V_52 ) ;
F_32 ( V_6 , V_48 ) ;
}
static void
F_241 ( struct V_5 * V_6 ,
T_26 * V_409 )
{
struct V_45 * V_46 ;
unsigned long V_65 ;
T_4 V_27 = F_9 ( V_409 -> V_418 ) ;
F_18 ( & V_6 -> V_66 , V_65 ) ;
V_46 = F_16 ( V_6 , V_27 ) ;
F_21 ( & V_6 -> V_66 , V_65 ) ;
if ( ! V_46 )
return;
V_46 -> V_271 = 0 ;
V_46 -> V_272 = 0 ;
F_166 ( V_27 , V_6 -> V_177 ) ;
F_235 ( V_46 -> V_70 , 0 ) ;
}
static void
F_242 ( struct V_5 * V_6 ,
T_26 * V_409 )
{
struct V_45 * V_46 ;
unsigned long V_65 ;
T_4 V_27 = F_9 ( V_409 -> V_418 ) ;
F_18 ( & V_6 -> V_66 , V_65 ) ;
V_46 = F_16 ( V_6 , V_27 ) ;
F_21 ( & V_6 -> V_66 , V_65 ) ;
if ( ! V_46 )
return;
F_97 ( V_6 , V_27 ,
& V_46 -> V_271 ) ;
F_98 ( V_6 , V_46 -> V_271 ,
& V_46 -> V_272 ) ;
F_243 ( V_27 , V_6 -> V_177 ) ;
F_235 ( V_46 -> V_70 , 1 ) ;
}
static void
F_244 ( struct V_5 * V_6 ,
T_26 * V_409 )
{
struct V_45 * V_46 ;
unsigned long V_65 ;
T_4 V_27 = F_9 ( V_409 -> V_418 ) ;
F_18 ( & V_6 -> V_66 , V_65 ) ;
V_46 = F_16 ( V_6 , V_27 ) ;
F_21 ( & V_6 -> V_66 , V_65 ) ;
if ( ! V_46 )
return;
F_223 ( V_6 , V_46 ) ;
}
static void
F_245 ( struct V_5 * V_6 ,
T_26 * V_409 )
{
struct V_45 * V_46 ;
unsigned long V_65 ;
T_4 V_27 = F_9 ( V_409 -> V_418 ) ;
T_9 V_29 ;
T_8 V_28 ;
T_10 V_30 ;
T_1 V_9 ;
T_4 V_614 ;
F_243 ( V_27 , V_6 -> V_177 ) ;
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
V_614 = F_9 ( V_28 . V_616 ) ;
if ( ! F_11 ( V_6 , V_614 , & V_9 ) )
F_204 ( V_6 , V_9 , V_27 ,
V_28 . V_646 , V_594 ) ;
F_222 ( V_6 , V_27 , 0 , 1 ) ;
}
static void
F_246 ( struct V_5 * V_6 ,
T_25 * V_358 )
{
T_26 * V_409 ;
T_6 V_692 ;
int V_92 ;
char * V_659 = NULL , * V_693 = NULL ;
V_409 = ( T_26 * ) & V_358 -> V_410 [ 0 ] ;
F_3 ( V_58 L_264 ,
V_6 -> V_35 , ( F_75 ( V_358 -> V_182 ) &
V_416 ) ?
L_265 : L_266 , V_358 -> V_411 ) ;
for ( V_92 = 0 ; V_92 < V_358 -> V_411 ; V_92 ++ , V_409 ++ ) {
switch ( V_409 -> V_412 ) {
case V_694 :
V_659 = L_199 ;
break;
case V_414 :
V_659 = L_200 ;
break;
case V_695 :
V_659 = L_267 ;
break;
case V_696 :
V_659 = L_268 ;
break;
case V_417 :
V_659 = L_269 ;
break;
case V_697 :
V_659 = L_270 ;
break;
case V_413 :
V_659 = L_271 ;
break;
case V_698 :
V_659 = L_272 ;
break;
case V_699 :
V_659 = L_273 ;
break;
default:
V_659 = L_231 ;
break;
}
V_692 = F_9 ( V_409 -> V_700 ) &
V_701 ;
switch ( V_692 ) {
case V_702 :
V_693 = L_74 ;
break;
case V_703 :
V_693 = L_274 ;
break;
case V_704 :
V_693 = L_275 ;
break;
default:
V_693 = L_276 ;
break;
}
F_3 ( V_7 L_277
L_278 , V_693 ,
V_659 , F_9 ( V_409 -> V_415 ) ,
F_9 ( V_409 -> V_418 ) ,
V_409 -> V_232 ) ;
}
}
static void
F_247 ( struct V_5 * V_6 ,
struct V_351 * V_352 )
{
T_26 * V_409 ;
int V_92 ;
T_6 V_705 ;
T_25 * V_358 = V_352 -> V_358 ;
#ifdef F_154
if ( ( V_6 -> V_8 & V_657 )
&& ! V_6 -> V_270 )
F_246 ( V_6 , V_358 ) ;
#endif
if ( V_6 -> V_315 )
return;
V_705 = ( F_75 ( V_358 -> V_182 ) &
V_416 ) ? 1 : 0 ;
V_409 = ( T_26 * ) & V_358 -> V_410 [ 0 ] ;
for ( V_92 = 0 ; V_92 < V_358 -> V_411 ; V_92 ++ , V_409 ++ ) {
switch ( V_409 -> V_412 ) {
case V_697 :
case V_694 :
if ( ! V_705 )
F_237 ( V_6 , V_409 ) ;
break;
case V_413 :
case V_414 :
if ( ! V_705 )
F_239 ( V_6 ,
F_9 ( V_409 -> V_415 ) ) ;
break;
case V_698 :
if ( ! V_6 -> V_190 )
F_242 ( V_6 , V_409 ) ;
break;
case V_699 :
if ( ! V_6 -> V_190 )
F_241 ( V_6 , V_409 ) ;
break;
case V_696 :
if ( ! V_6 -> V_190 )
F_245 ( V_6 , V_409 ) ;
break;
case V_417 :
if ( ! V_6 -> V_190 )
F_244 ( V_6 , V_409 ) ;
break;
}
}
}
static void
F_248 ( struct V_5 * V_6 ,
struct V_351 * V_352 )
{
T_1 V_52 ;
unsigned long V_65 ;
struct V_47 * V_48 ;
T_4 V_27 ;
T_10 V_200 ;
int V_20 ;
T_27 * V_358 = V_352 -> V_358 ;
if ( V_6 -> V_315 )
return;
if ( V_358 -> V_412 != V_419 )
return;
V_27 = F_9 ( V_358 -> V_415 ) ;
V_200 = F_75 ( V_358 -> V_420 ) ;
if ( ! V_6 -> V_270 )
F_23 ( V_6 , F_3 ( V_58 L_48
L_279 , V_6 -> V_35 , V_36 , V_27 ,
F_75 ( V_358 -> V_706 ) , V_200 ) ) ;
switch ( V_200 ) {
case V_210 :
case V_209 :
F_239 ( V_6 , V_27 ) ;
break;
case V_205 :
case V_207 :
case V_204 :
F_18 ( & V_6 -> V_76 , V_65 ) ;
V_48 = F_29 ( V_6 , V_27 ) ;
F_21 ( & V_6 -> V_76 , V_65 ) ;
if ( V_48 )
break;
F_98 ( V_6 , V_27 , & V_52 ) ;
if ( ! V_52 ) {
F_3 ( V_34
L_2 , V_6 -> V_35 ,
__FILE__ , __LINE__ , V_36 ) ;
break;
}
V_48 = F_68 ( sizeof( struct V_47 ) , V_172 ) ;
if ( ! V_48 ) {
F_3 ( V_34
L_2 , V_6 -> V_35 ,
__FILE__ , __LINE__ , V_36 ) ;
break;
}
V_48 -> V_72 = V_6 -> V_691 ++ ;
V_48 -> V_73 = V_174 ;
V_48 -> V_27 = V_27 ;
V_48 -> V_52 = V_52 ;
F_31 ( V_6 , V_48 ) ;
V_20 = F_238 ( V_6 -> V_142 , V_174 ,
V_48 -> V_72 , 0 ) ;
if ( V_20 )
F_32 ( V_6 , V_48 ) ;
break;
case V_707 :
default:
break;
}
}
static void
F_249 ( struct V_5 * V_6 ,
struct V_351 * V_352 )
{
T_4 V_27 , V_614 ;
T_10 V_200 ;
struct V_45 * V_46 ;
unsigned long V_65 ;
T_9 V_29 ;
T_8 V_28 ;
T_10 V_30 ;
T_44 * V_358 = V_352 -> V_358 ;
T_1 V_9 ;
if ( V_6 -> V_315 )
return;
if ( V_358 -> V_412 != V_708 )
return;
V_27 = F_9 ( V_358 -> V_418 ) ;
V_200 = F_75 ( V_358 -> V_420 ) ;
if ( ! V_6 -> V_270 )
F_23 ( V_6 , F_3 ( V_58 L_48
L_279 , V_6 -> V_35 , V_36 , V_27 ,
F_75 ( V_358 -> V_706 ) , V_200 ) ) ;
switch ( V_200 ) {
case V_709 :
case V_710 :
case V_711 :
case V_712 :
case V_713 :
if ( ! V_6 -> V_190 )
F_243 ( V_27 , V_6 -> V_177 ) ;
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
V_614 = F_9 ( V_28 . V_616 ) ;
if ( ! F_11 ( V_6 , V_614 , & V_9 ) )
F_204 ( V_6 , V_9 , V_27 ,
V_28 . V_646 , V_594 ) ;
F_222 ( V_6 , V_27 , 0 , 1 ) ;
break;
case V_714 :
case V_715 :
case V_716 :
default:
break;
}
}
static void
F_250 ( struct V_5 * V_6 ,
T_45 * V_358 )
{
char * V_659 = NULL ;
switch ( V_358 -> V_717 ) {
case V_718 :
V_659 = L_280 ;
break;
case V_719 :
V_659 = L_281 ;
break;
case V_720 :
V_659 = L_282 ;
break;
case V_721 :
V_659 = L_283 ;
break;
case V_722 :
V_659 = L_284 ;
break;
}
if ( ! V_659 )
return;
F_3 ( V_58 L_285
L_286 ,
V_6 -> V_35 , V_659 ,
F_9 ( V_358 -> V_415 ) ,
V_358 -> V_723 ) ;
}
static void
F_251 ( struct V_5 * V_6 ,
struct V_351 * V_352 )
{
T_45 * V_358 = V_352 -> V_358 ;
static struct V_47 * V_48 ;
unsigned long V_65 ;
T_4 V_27 ;
#ifdef F_154
if ( ( V_6 -> V_8 & V_657 )
&& ! V_6 -> V_270 )
F_250 ( V_6 ,
V_358 ) ;
#endif
if ( V_358 -> V_717 == V_718 ) {
V_27 = F_9 ( V_358 -> V_415 ) ;
F_18 ( & V_6 -> V_76 , V_65 ) ;
V_48 = F_29 ( V_6 , V_27 ) ;
F_21 ( & V_6 -> V_76 , V_65 ) ;
if ( ! V_48 )
return;
if ( V_358 -> V_717 == V_718 )
V_48 -> V_193 =
V_358 -> V_723 ;
}
}
static void
F_252 ( struct V_5 * V_6 )
{
struct V_145 * V_146 ;
struct V_138 * V_139 ;
F_108 (sdev, ioc->shost) {
V_146 = V_139 -> V_150 ;
if ( V_146 && V_146 -> V_152 )
V_146 -> V_152 -> V_385 = 1 ;
}
}
static void
F_253 ( struct V_5 * V_6 , T_1 V_9 ,
T_4 V_18 , T_4 V_27 )
{
struct V_147 * V_148 = NULL ;
struct V_168 * V_70 ;
struct V_45 * V_46 ;
unsigned long V_65 ;
F_18 ( & V_6 -> V_66 , V_65 ) ;
F_4 (sas_device, &ioc->sas_device_list, list) {
if ( V_46 -> V_9 == V_9 &&
V_46 -> V_18 == V_18 ) {
V_46 -> V_724 = 1 ;
V_70 = V_46 -> V_70 ;
if ( V_70 && V_70 -> V_150 ) {
V_148 = V_70 -> V_150 ;
V_148 -> V_301 = 0 ;
V_148 -> V_385 = 0 ;
} else
V_148 = NULL ;
if ( V_70 )
F_127 ( V_7 , V_70 ,
L_287
L_288
L_289 , V_27 ,
( unsigned long long ) V_46 -> V_9 ,
( unsigned long long )
V_46 -> V_14 ,
V_46 -> V_18 ) ;
if ( V_46 -> V_27 == V_27 )
goto V_75;
F_3 ( V_7 L_290 ,
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
F_254 ( struct V_5 * V_6 )
{
T_8 V_28 ;
T_9 V_29 ;
T_4 V_30 ;
T_40 V_9 ;
T_4 V_27 ;
T_10 V_82 ;
T_4 V_18 ;
F_3 ( V_58 L_291 , V_6 -> V_35 ) ;
if ( F_43 ( & V_6 -> V_68 ) )
goto V_75;
V_27 = 0xFFFF ;
while ( ! ( F_12 ( V_6 , & V_29 ,
& V_28 , V_725 ,
V_27 ) ) ) {
V_30 = F_9 ( V_29 . V_38 ) &
V_39 ;
if ( V_30 == V_41 )
break;
V_27 = F_9 ( V_28 . V_233 ) ;
V_82 = F_75 ( V_28 . V_183 ) ;
if ( ! ( F_36 ( V_82 ) ) )
continue;
V_9 = F_6 ( V_28 . V_11 ) ;
V_18 = F_9 ( V_28 . V_645 ) ;
F_253 ( V_6 , V_9 , V_18 ,
V_27 ) ;
}
V_75:
F_3 ( V_58 L_292 ,
V_6 -> V_35 ) ;
}
static void
F_255 ( struct V_5 * V_6 , T_1 V_52 ,
T_4 V_27 )
{
struct V_147 * V_148 ;
struct V_168 * V_70 ;
struct V_47 * V_48 ;
unsigned long V_65 ;
F_18 ( & V_6 -> V_76 , V_65 ) ;
F_4 (raid_device, &ioc->raid_device_list, list) {
if ( V_48 -> V_52 == V_52 && V_48 -> V_70 ) {
V_70 = V_48 -> V_70 ;
if ( V_70 && V_70 -> V_150 ) {
V_148 = V_70 -> V_150 ;
V_148 -> V_385 = 0 ;
} else
V_148 = NULL ;
V_48 -> V_724 = 1 ;
F_127 ( V_7 , V_48 -> V_70 ,
L_293 , V_27 ,
( unsigned long long ) V_48 -> V_52 ) ;
F_92 ( V_6 , V_48 ) ;
if ( V_48 -> V_27 == V_27 )
goto V_75;
F_3 ( V_7 L_290 ,
V_48 -> V_27 ) ;
V_48 -> V_27 = V_27 ;
if ( V_148 )
V_148 -> V_27 = V_27 ;
goto V_75;
}
}
V_75:
F_21 ( & V_6 -> V_76 , V_65 ) ;
}
static void
F_256 ( struct V_5 * V_6 )
{
T_15 V_726 ;
T_13 V_727 ;
T_14 V_225 ;
T_9 V_29 ;
T_4 V_30 ;
T_4 V_27 ;
T_6 V_728 ;
if ( ! V_6 -> V_729 )
return;
F_3 ( V_58 L_294 ,
V_6 -> V_35 ) ;
if ( F_43 ( & V_6 -> V_77 ) )
goto V_75;
V_27 = 0xFFFF ;
while ( ! ( F_90 ( V_6 , & V_29 ,
& V_726 , V_235 , V_27 ) ) ) {
V_30 = F_9 ( V_29 . V_38 ) &
V_39 ;
if ( V_30 == V_41 )
break;
V_27 = F_9 ( V_726 . V_233 ) ;
if ( F_79 ( V_6 , & V_29 ,
& V_727 , V_194 , V_27 ,
sizeof( T_13 ) ) )
continue;
if ( V_727 . V_203 == V_204 ||
V_727 . V_203 == V_205 ||
V_727 . V_203 == V_207 )
F_255 ( V_6 ,
F_6 ( V_726 . V_730 ) , V_27 ) ;
}
if ( ! V_6 -> V_190 ) {
V_728 = 0xFF ;
memset ( V_6 -> V_177 , 0 , V_6 -> V_731 ) ;
while ( ! ( F_88 ( V_6 , & V_29 ,
& V_225 , V_732 ,
V_728 ) ) ) {
V_30 = F_9 ( V_29 . V_38 ) &
V_39 ;
if ( V_30 == V_41 )
break;
V_728 = V_225 . V_232 ;
V_27 = F_9 ( V_225 . V_233 ) ;
F_243 ( V_27 , V_6 -> V_177 ) ;
}
}
V_75:
F_3 ( V_58 L_295
L_296 , V_6 -> V_35 ) ;
}
static void
F_257 ( struct V_5 * V_6 , T_1 V_9 ,
T_4 V_27 )
{
struct V_78 * V_79 ;
unsigned long V_65 ;
int V_92 ;
F_18 ( & V_6 -> V_80 , V_65 ) ;
F_4 (sas_expander, &ioc->sas_expander_list, list) {
if ( V_79 -> V_9 != V_9 )
continue;
V_79 -> V_724 = 1 ;
if ( V_79 -> V_27 == V_27 )
goto V_75;
F_3 ( V_7 L_297
L_298 ,
( unsigned long long ) V_79 -> V_9 ,
V_79 -> V_27 , V_27 ) ;
V_79 -> V_27 = V_27 ;
for ( V_92 = 0 ; V_92 < V_79 -> V_32 ; V_92 ++ )
V_79 -> V_273 [ V_92 ] . V_27 = V_27 ;
goto V_75;
}
V_75:
F_21 ( & V_6 -> V_80 , V_65 ) ;
}
static void
F_258 ( struct V_5 * V_6 )
{
T_38 V_612 ;
T_9 V_29 ;
T_4 V_30 ;
T_1 V_9 ;
T_4 V_27 ;
F_3 ( V_58 L_299 , V_6 -> V_35 ) ;
if ( F_43 ( & V_6 -> V_81 ) )
goto V_75;
V_27 = 0xFFFF ;
while ( ! ( F_213 ( V_6 , & V_29 , & V_612 ,
V_733 , V_27 ) ) ) {
V_30 = F_9 ( V_29 . V_38 ) &
V_39 ;
if ( V_30 == V_41 )
break;
V_27 = F_9 ( V_612 . V_233 ) ;
V_9 = F_6 ( V_612 . V_11 ) ;
F_3 ( V_7 L_300
L_301 , V_27 ,
( unsigned long long ) V_9 ) ;
F_257 ( V_6 , V_9 , V_27 ) ;
}
V_75:
F_3 ( V_58 L_302 , V_6 -> V_35 ) ;
}
static void
F_259 ( struct V_5 * V_6 )
{
struct V_45 * V_46 , * V_734 ;
struct V_78 * V_79 ;
struct V_47 * V_48 , * V_735 ;
F_3 ( V_58 L_303 ,
V_6 -> V_35 ) ;
F_141 (sas_device, sas_device_next,
&ioc->sas_device_list, list) {
if ( V_46 -> V_724 ) {
V_46 -> V_724 = 0 ;
continue;
}
if ( V_46 -> V_70 )
F_127 ( V_7 , V_46 -> V_70 ,
L_304
L_305 ,
V_46 -> V_27 ,
( unsigned long long ) V_46 -> V_9 ,
( unsigned long long )
V_46 -> V_14 ,
V_46 -> V_18 ) ;
F_223 ( V_6 , V_46 ) ;
}
if ( ! V_6 -> V_729 )
goto V_736;
F_141 (raid_device, raid_device_next,
&ioc->raid_device_list, list) {
if ( V_48 -> V_724 ) {
V_48 -> V_724 = 0 ;
continue;
}
if ( V_48 -> V_70 ) {
F_127 ( V_7 , V_48 -> V_70 ,
L_306 ,
V_48 -> V_27 ,
( unsigned long long ) V_48 -> V_52 ) ;
F_240 ( & V_48 -> V_70 -> V_169 ) ;
}
F_32 ( V_6 , V_48 ) ;
}
V_736:
V_79 = NULL ;
F_4 (sas_expander, &ioc->sas_expander_list, list) {
if ( V_79 -> V_724 ) {
V_79 -> V_724 = 0 ;
continue;
}
F_217 ( V_6 , V_79 -> V_9 ) ;
goto V_736;
}
F_3 ( V_58 L_307 ,
V_6 -> V_35 ) ;
F_143 ( V_6 ) ;
}
static void
F_260 ( struct V_5 * V_6 ,
struct V_78 * V_79 , T_4 V_27 )
{
T_39 V_613 ;
T_9 V_29 ;
int V_92 ;
for ( V_92 = 0 ; V_92 < V_79 -> V_32 ; V_92 ++ ) {
if ( ( F_214 ( V_6 , & V_29 ,
& V_613 , V_92 , V_27 ) ) ) {
F_3 ( V_34 L_2 ,
V_6 -> V_35 , __FILE__ , __LINE__ , V_36 ) ;
return;
}
F_204 ( V_6 , V_79 -> V_9 ,
F_9 ( V_613 . V_377 ) , V_92 ,
V_613 . V_592 >> 4 ) ;
}
}
static void
F_261 ( struct V_5 * V_6 )
{
T_38 V_612 ;
T_8 V_28 ;
T_15 V_726 ;
T_13 V_727 ;
T_14 V_225 ;
T_26 V_409 ;
T_9 V_29 ;
T_6 V_728 ;
T_4 V_30 ;
T_4 V_27 , V_614 ;
T_1 V_9 ;
struct V_45 * V_46 ;
struct V_78 * V_737 ;
static struct V_47 * V_48 ;
F_3 ( V_58 L_308 , V_6 -> V_35 ) ;
F_202 ( V_6 ) ;
V_27 = 0xFFFF ;
while ( ! ( F_213 ( V_6 , & V_29 , & V_612 ,
V_733 , V_27 ) ) ) {
V_30 = F_9 ( V_29 . V_38 ) &
V_39 ;
if ( V_30 == V_41 )
break;
V_27 = F_9 ( V_612 . V_233 ) ;
V_737 = F_34 (
V_6 , F_6 ( V_612 . V_11 ) ) ;
if ( V_737 )
F_260 ( V_6 , V_737 ,
V_27 ) ;
else
F_212 ( V_6 , V_27 ) ;
}
if ( ! V_6 -> V_729 )
goto V_738;
V_728 = 0xFF ;
while ( ! ( F_88 ( V_6 , & V_29 ,
& V_225 , V_732 ,
V_728 ) ) ) {
V_30 = F_9 ( V_29 . V_38 ) &
V_39 ;
if ( V_30 == V_41 )
break;
V_728 = V_225 . V_232 ;
V_27 = F_9 ( V_225 . V_233 ) ;
V_46 = F_16 ( V_6 , V_27 ) ;
if ( V_46 )
continue;
if ( F_12 ( V_6 , & V_29 ,
& V_28 , V_33 ,
V_27 ) != 0 )
continue;
V_614 = F_9 ( V_28 . V_616 ) ;
if ( ! F_11 ( V_6 , V_614 ,
& V_9 ) ) {
F_204 ( V_6 , V_9 ,
V_27 , V_28 . V_646 ,
V_594 ) ;
F_243 ( V_27 , V_6 -> V_177 ) ;
F_222 ( V_6 , V_27 , 0 , 1 ) ;
}
}
V_27 = 0xFFFF ;
while ( ! ( F_90 ( V_6 , & V_29 ,
& V_726 , V_235 , V_27 ) ) ) {
V_30 = F_9 ( V_29 . V_38 ) &
V_39 ;
if ( V_30 == V_41 )
break;
V_27 = F_9 ( V_726 . V_233 ) ;
V_48 = F_30 ( V_6 ,
F_6 ( V_726 . V_730 ) ) ;
if ( V_48 )
continue;
if ( F_79 ( V_6 , & V_29 ,
& V_727 , V_194 , V_27 ,
sizeof( T_13 ) ) )
continue;
if ( V_727 . V_203 == V_204 ||
V_727 . V_203 == V_205 ||
V_727 . V_203 == V_207 ) {
memset ( & V_409 , 0 , sizeof( T_26 ) ) ;
V_409 . V_412 = V_694 ;
V_409 . V_415 = V_726 . V_233 ;
F_237 ( V_6 , & V_409 ) ;
}
}
V_738:
V_27 = 0xFFFF ;
while ( ! ( F_12 ( V_6 , & V_29 ,
& V_28 , V_725 ,
V_27 ) ) ) {
V_30 = F_9 ( V_29 . V_38 ) &
V_39 ;
if ( V_30 == V_41 )
break;
V_27 = F_9 ( V_28 . V_233 ) ;
if ( ! ( F_36 (
F_75 ( V_28 . V_183 ) ) ) )
continue;
V_46 = F_15 ( V_6 ,
F_6 ( V_28 . V_11 ) ) ;
if ( V_46 )
continue;
V_614 = F_9 ( V_28 . V_616 ) ;
if ( ! F_11 ( V_6 , V_614 , & V_9 ) ) {
F_204 ( V_6 , V_9 , V_27 ,
V_28 . V_646 , V_594 ) ;
F_222 ( V_6 , V_27 , 0 , 0 ) ;
}
}
F_3 ( V_58 L_309 , V_6 -> V_35 ) ;
}
void
F_262 ( struct V_5 * V_6 , int V_739 )
{
switch ( V_739 ) {
case V_740 :
F_117 ( V_6 , F_3 ( V_58 L_51
L_310 , V_6 -> V_35 , V_36 ) ) ;
break;
case V_741 :
F_117 ( V_6 , F_3 ( V_58 L_51
L_311 , V_6 -> V_35 , V_36 ) ) ;
if ( V_6 -> V_620 . V_293 & V_298 ) {
V_6 -> V_620 . V_293 |= V_334 ;
F_161 ( V_6 , V_6 -> V_620 . V_88 ) ;
F_106 ( & V_6 -> V_620 . V_299 ) ;
}
if ( V_6 -> V_292 . V_293 & V_298 ) {
V_6 -> V_292 . V_293 |= V_334 ;
F_161 ( V_6 , V_6 -> V_292 . V_88 ) ;
F_106 ( & V_6 -> V_292 . V_299 ) ;
}
F_139 ( V_6 ) ;
F_169 ( V_6 ) ;
break;
case V_742 :
F_117 ( V_6 , F_3 ( V_58 L_51
L_312 , V_6 -> V_35 , V_36 ) ) ;
F_202 ( V_6 ) ;
F_252 ( V_6 ) ;
F_254 ( V_6 ) ;
F_256 ( V_6 ) ;
F_258 ( V_6 ) ;
if ( ! V_6 -> V_49 ) {
F_252 ( V_6 ) ;
F_254 ( V_6 ) ;
F_256 ( V_6 ) ;
F_258 ( V_6 ) ;
F_137 ( V_6 ) ;
}
break;
}
}
static void
V_357 ( struct V_743 * V_744 )
{
struct V_351 * V_352 = F_263 ( V_744 ,
struct V_351 , V_356 . V_744 ) ;
struct V_5 * V_6 = V_352 -> V_6 ;
if ( V_6 -> V_316 || V_352 -> V_363 ||
V_6 -> V_317 ) {
F_136 ( V_6 , V_352 ) ;
return;
}
switch ( V_352 -> V_360 ) {
case V_361 :
while ( F_264 ( V_6 -> V_142 ) )
F_265 ( 1 ) ;
F_259 ( V_6 ) ;
F_261 ( V_6 ) ;
break;
case V_362 :
V_6 -> V_745 = 0 ;
F_23 ( V_6 , F_3 ( V_58 L_313
L_314 , V_6 -> V_35 ) ) ;
break;
case V_558 :
F_191 ( V_6 , V_352 -> V_559 ) ;
break;
case V_404 :
F_226 ( V_6 , V_352 ) ;
break;
case V_568 :
F_228 ( V_6 ,
V_352 ) ;
break;
case V_746 :
F_232 ( V_6 ,
V_352 ) ;
break;
case V_747 :
F_231 ( V_6 ,
V_352 ) ;
break;
case V_748 :
F_230 ( V_6 ,
V_352 ) ;
break;
case V_749 :
F_247 ( V_6 , V_352 ) ;
break;
case V_750 :
F_248 ( V_6 , V_352 ) ;
break;
case V_751 :
F_249 ( V_6 , V_352 ) ;
break;
case V_752 :
F_251 ( V_6 , V_352 ) ;
break;
}
F_136 ( V_6 , V_352 ) ;
}
T_6
F_266 ( struct V_5 * V_6 , T_6 V_290 ,
T_10 V_291 )
{
struct V_351 * V_352 ;
T_31 * V_29 ;
T_4 V_360 ;
T_4 V_226 ;
if ( V_6 -> V_316 || V_6 -> V_317 )
return 1 ;
V_29 = F_105 ( V_6 , V_291 ) ;
V_360 = F_9 ( V_29 -> V_567 ) ;
switch ( V_360 ) {
case V_747 :
{
T_42 * V_753 =
( T_42 * )
V_29 -> V_565 ;
if ( V_753 -> V_754 !=
V_755 )
return 1 ;
if ( V_6 -> V_688 ) {
V_6 -> V_687 ++ ;
return 1 ;
} else
V_6 -> V_688 = 1 ;
break;
}
case V_404 :
F_162 ( V_6 ,
( T_22 * )
V_29 -> V_565 ) ;
break;
case V_749 :
F_165 ( V_6 ,
( T_25 * )
V_29 -> V_565 ) ;
break;
case V_750 :
F_168 ( V_6 ,
( T_27 * )
V_29 -> V_565 ) ;
break;
case V_756 :
{
T_46 * V_757 ;
T_10 * V_758 ;
if ( ! V_6 -> V_190 )
break;
V_757 = ( T_46 * )
V_29 -> V_565 ;
V_758 = ( T_10 * ) V_757 -> V_759 ;
if ( F_9 ( V_757 -> V_760 )
!= V_761 )
break;
switch ( F_75 ( * V_758 ) ) {
case V_762 :
F_3 ( V_99 L_315
L_316
L_317
L_318 , V_6 -> V_35 ) ;
break;
case V_763 :
F_3 ( V_99 L_315
L_319
L_320
L_321 , V_6 -> V_35 ) ;
break;
case V_764 :
F_3 ( V_34 L_322
L_323
L_324
L_325
L_321 , V_6 -> V_35 ) ;
break;
case V_765 :
F_3 ( V_34 L_322
L_326
L_327
L_328 ,
V_6 -> V_35 ) ;
break;
}
break;
}
case V_568 :
case V_752 :
case V_746 :
case V_748 :
case V_751 :
break;
default:
return 1 ;
}
V_352 = F_68 ( sizeof( struct V_351 ) , V_359 ) ;
if ( ! V_352 ) {
F_3 ( V_34 L_2 ,
V_6 -> V_35 , __FILE__ , __LINE__ , V_36 ) ;
return 1 ;
}
V_226 = F_9 ( V_29 -> V_569 ) * 4 ;
V_352 -> V_358 = F_68 ( V_226 , V_359 ) ;
if ( ! V_352 -> V_358 ) {
F_3 ( V_34 L_2 ,
V_6 -> V_35 , __FILE__ , __LINE__ , V_36 ) ;
F_20 ( V_352 ) ;
return 1 ;
}
memcpy ( V_352 -> V_358 , V_29 -> V_565 ,
V_226 ) ;
V_352 -> V_6 = V_6 ;
V_352 -> V_501 = V_29 -> V_501 ;
V_352 -> V_502 = V_29 -> V_502 ;
V_352 -> V_360 = V_360 ;
F_133 ( V_6 , V_352 ) ;
return 1 ;
}
static void
F_218 ( struct V_5 * V_6 ,
struct V_78 * V_79 )
{
struct V_365 * V_366 , * V_100 ;
F_141 (mpt2sas_port, next,
&sas_expander->sas_port_list, port_list) {
if ( V_6 -> V_315 )
return;
if ( V_366 -> V_368 . V_369 ==
V_370 )
F_224 ( V_6 ,
V_366 -> V_368 . V_9 ) ;
else if ( V_366 -> V_368 . V_369 ==
V_371 ||
V_366 -> V_368 . V_369 ==
V_372 )
F_217 ( V_6 ,
V_366 -> V_368 . V_9 ) ;
}
F_26 ( V_6 , V_79 -> V_9 ,
V_79 -> V_69 ) ;
F_3 ( V_58 L_329
L_8 , V_6 -> V_35 ,
V_79 -> V_27 , ( unsigned long long )
V_79 -> V_9 ) ;
F_20 ( V_79 -> V_273 ) ;
F_20 ( V_79 ) ;
}
static void
F_267 ( struct V_5 * V_6 )
{
T_47 * V_103 ;
T_48 * V_29 ;
T_4 V_88 ;
if ( ! V_6 -> V_729 )
return;
if ( F_43 ( & V_6 -> V_77 ) )
return;
F_111 ( & V_6 -> V_620 . V_312 ) ;
if ( V_6 -> V_620 . V_293 != V_294 ) {
F_3 ( V_34 L_330 ,
V_6 -> V_35 , V_36 ) ;
goto V_75;
}
V_6 -> V_620 . V_293 = V_298 ;
V_88 = F_159 ( V_6 , V_6 -> V_766 ) ;
if ( ! V_88 ) {
F_3 ( V_34 L_67 ,
V_6 -> V_35 , V_36 ) ;
V_6 -> V_620 . V_293 = V_294 ;
goto V_75;
}
V_103 = F_47 ( V_6 , V_88 ) ;
V_6 -> V_620 . V_88 = V_88 ;
memset ( V_103 , 0 , sizeof( T_47 ) ) ;
V_103 -> V_327 = V_767 ;
V_103 -> V_553 = V_768 ;
if ( ! V_6 -> V_270 )
F_3 ( V_58 L_331 , V_6 -> V_35 ) ;
F_120 ( & V_6 -> V_620 . V_299 ) ;
F_160 ( V_6 , V_88 ) ;
F_122 ( & V_6 -> V_620 . V_299 , 10 * V_333 ) ;
if ( ! ( V_6 -> V_620 . V_293 & V_295 ) ) {
F_3 ( V_34 L_70 ,
V_6 -> V_35 , V_36 ) ;
goto V_75;
}
if ( V_6 -> V_620 . V_293 & V_297 ) {
V_29 = V_6 -> V_620 . V_291 ;
if ( ! V_6 -> V_270 )
F_3 ( V_58 L_332
L_333 ,
V_6 -> V_35 , F_9 ( V_29 -> V_38 ) ,
F_75 ( V_29 -> V_335 ) ) ;
}
V_75:
V_6 -> V_620 . V_293 = V_294 ;
F_124 ( & V_6 -> V_620 . V_312 ) ;
}
static void
F_268 ( struct V_769 * V_562 )
{
struct V_141 * V_142 = F_269 ( V_562 ) ;
struct V_5 * V_6 = F_57 ( V_142 ) ;
struct V_770 * V_771 ;
unsigned long V_65 ;
V_6 -> V_316 = 1 ;
F_139 ( V_6 ) ;
F_18 ( & V_6 -> V_354 , V_65 ) ;
V_771 = V_6 -> V_353 ;
V_6 -> V_353 = NULL ;
F_21 ( & V_6 -> V_354 , V_65 ) ;
if ( V_771 )
F_270 ( V_771 ) ;
F_267 ( V_6 ) ;
F_271 ( V_6 ) ;
}
static void T_49
F_272 ( struct V_769 * V_562 )
{
struct V_141 * V_142 = F_269 ( V_562 ) ;
struct V_5 * V_6 = F_57 ( V_142 ) ;
struct V_365 * V_366 , * V_772 ;
struct V_47 * V_48 , * V_100 ;
struct V_147 * V_148 ;
struct V_770 * V_771 ;
unsigned long V_65 ;
V_6 -> V_316 = 1 ;
F_139 ( V_6 ) ;
F_18 ( & V_6 -> V_354 , V_65 ) ;
V_771 = V_6 -> V_353 ;
V_6 -> V_353 = NULL ;
F_21 ( & V_6 -> V_354 , V_65 ) ;
if ( V_771 )
F_270 ( V_771 ) ;
F_267 ( V_6 ) ;
F_141 (raid_device, next, &ioc->raid_device_list,
list) {
if ( V_48 -> V_70 ) {
V_148 =
V_48 -> V_70 -> V_150 ;
V_148 -> V_385 = 1 ;
F_240 ( & V_48 -> V_70 -> V_169 ) ;
}
F_3 ( V_58 L_263
L_197 , V_6 -> V_35 , V_48 -> V_27 ,
( unsigned long long ) V_48 -> V_52 ) ;
F_32 ( V_6 , V_48 ) ;
}
F_141 (mpt2sas_port, next_port,
&ioc->sas_hba.sas_port_list, port_list) {
if ( V_366 -> V_368 . V_369 ==
V_370 )
F_224 ( V_6 ,
V_366 -> V_368 . V_9 ) ;
else if ( V_366 -> V_368 . V_369 ==
V_371 ||
V_366 -> V_368 . V_369 ==
V_372 )
F_217 ( V_6 ,
V_366 -> V_368 . V_9 ) ;
}
if ( V_6 -> V_31 . V_32 ) {
F_20 ( V_6 -> V_31 . V_273 ) ;
V_6 -> V_31 . V_273 = NULL ;
V_6 -> V_31 . V_32 = 0 ;
}
F_273 ( V_142 ) ;
F_271 ( V_6 ) ;
F_19 ( & V_6 -> V_67 ) ;
F_274 ( V_142 ) ;
F_275 ( V_142 ) ;
}
static void
F_276 ( struct V_5 * V_6 )
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
V_20 = F_238 ( V_6 -> V_142 , V_174 ,
V_48 -> V_72 , 0 ) ;
if ( V_20 )
F_32 ( V_6 , V_48 ) ;
} else {
V_46 = V_43 ;
V_27 = V_46 -> V_27 ;
V_69 = V_46 -> V_69 ;
V_9 = V_46 -> V_9 ;
F_18 ( & V_6 -> V_66 , V_65 ) ;
F_277 ( & V_46 -> V_67 , & V_6 -> V_68 ) ;
F_21 ( & V_6 -> V_66 , V_65 ) ;
if ( V_6 -> V_649 )
return;
if ( ! F_25 ( V_6 , V_46 -> V_27 ,
V_46 -> V_69 ) ) {
F_17 ( V_6 , V_46 ) ;
} else if ( ! V_46 -> V_70 ) {
if ( ! V_6 -> V_49 )
F_26 ( V_6 , V_9 ,
V_69 ) ;
F_17 ( V_6 , V_46 ) ;
}
}
}
static void
F_278 ( struct V_5 * V_6 )
{
struct V_47 * V_48 , * V_773 ;
int V_20 ;
F_141 (raid_device, raid_next,
&ioc->raid_device_list, list) {
if ( V_48 -> V_70 )
continue;
V_20 = F_238 ( V_6 -> V_142 , V_174 ,
V_48 -> V_72 , 0 ) ;
if ( V_20 )
F_32 ( V_6 , V_48 ) ;
}
}
static void
F_279 ( struct V_5 * V_6 )
{
struct V_45 * V_46 , * V_100 ;
unsigned long V_65 ;
F_141 (sas_device, next, &ioc->sas_device_init_list,
list) {
if ( V_6 -> V_649 )
continue;
if ( ! F_25 ( V_6 , V_46 -> V_27 ,
V_46 -> V_69 ) ) {
F_19 ( & V_46 -> V_67 ) ;
F_20 ( V_46 ) ;
continue;
} else if ( ! V_46 -> V_70 ) {
if ( ! V_6 -> V_49 )
F_26 ( V_6 ,
V_46 -> V_9 ,
V_46 -> V_69 ) ;
F_19 ( & V_46 -> V_67 ) ;
F_20 ( V_46 ) ;
continue;
}
F_18 ( & V_6 -> V_66 , V_65 ) ;
F_277 ( & V_46 -> V_67 , & V_6 -> V_68 ) ;
F_21 ( & V_6 -> V_66 , V_65 ) ;
}
}
static void
F_280 ( struct V_5 * V_6 )
{
T_4 V_774 ;
if ( ! ( V_6 -> V_256 . V_775 & V_776 ) )
return;
F_276 ( V_6 ) ;
if ( V_6 -> V_729 ) {
V_774 =
F_9 ( V_6 -> V_777 . V_778 ) &
V_779 ;
if ( V_774 ==
V_780 ) {
F_278 ( V_6 ) ;
F_279 ( V_6 ) ;
} else {
F_279 ( V_6 ) ;
F_278 ( V_6 ) ;
}
} else
F_279 ( V_6 ) ;
}
static void
F_281 ( struct V_141 * V_142 )
{
struct V_5 * V_6 = F_57 ( V_142 ) ;
int V_20 ;
if ( V_781 != - 1 && V_781 != 0 )
F_282 ( V_6 , V_781 ) ;
V_6 -> V_745 = 1 ;
V_20 = F_283 ( V_6 ) ;
if ( V_20 != 0 )
F_3 ( V_58 L_334 , V_6 -> V_35 ) ;
}
static int
F_284 ( struct V_141 * V_142 , unsigned long time )
{
struct V_5 * V_6 = F_57 ( V_142 ) ;
if ( time >= ( 300 * V_333 ) ) {
V_6 -> V_782 . V_293 = V_294 ;
F_3 ( V_58 L_335
L_336 , V_6 -> V_35 ) ;
V_6 -> V_49 = 0 ;
return 1 ;
}
if ( V_6 -> V_745 )
return 0 ;
if ( V_6 -> V_783 ) {
F_3 ( V_58 L_337
L_338 , V_6 -> V_35 , V_6 -> V_783 ) ;
V_6 -> V_49 = 0 ;
V_6 -> V_647 = 0 ;
V_6 -> V_316 = 1 ;
return 1 ;
}
F_3 ( V_58 L_339 , V_6 -> V_35 ) ;
V_6 -> V_782 . V_293 = V_294 ;
if ( V_6 -> V_647 ) {
V_6 -> V_647 = 0 ;
F_280 ( V_6 ) ;
}
F_285 ( V_6 ) ;
V_6 -> V_49 = 0 ;
return 1 ;
}
static int
F_286 ( struct V_769 * V_562 , const struct V_784 * V_72 )
{
struct V_5 * V_6 ;
struct V_141 * V_142 ;
V_142 = F_287 ( & V_785 ,
sizeof( struct V_5 ) ) ;
if ( ! V_142 )
return - V_786 ;
V_6 = F_57 ( V_142 ) ;
memset ( V_6 , 0 , sizeof( struct V_5 ) ) ;
F_152 ( & V_6 -> V_67 ) ;
F_24 ( & V_6 -> V_67 , & V_787 ) ;
V_6 -> V_142 = V_142 ;
V_6 -> V_72 = V_788 ++ ;
sprintf ( V_6 -> V_35 , L_340 , V_789 , V_6 -> V_72 ) ;
V_6 -> V_562 = V_562 ;
if ( V_72 -> V_43 == V_790 ) {
V_6 -> V_190 = 1 ;
V_6 -> V_270 = 1 ;
} else
V_6 -> V_244 = V_245 ;
V_6 -> V_485 = V_485 ;
V_6 -> V_325 = V_325 ;
V_6 -> V_791 = V_791 ;
V_6 -> V_792 = V_792 ;
V_6 -> V_793 = V_793 ;
V_6 -> V_794 = V_794 ;
V_6 -> V_766 = V_766 ;
V_6 -> V_795 = V_795 ;
V_6 -> V_386 = V_386 ;
V_6 -> V_388 = V_388 ;
V_6 -> V_392 = V_392 ;
V_6 -> V_8 = V_8 ;
F_288 ( & V_6 -> V_796 ) ;
F_289 ( & V_6 -> V_797 ) ;
F_289 ( & V_6 -> V_91 ) ;
F_289 ( & V_6 -> V_66 ) ;
F_289 ( & V_6 -> V_80 ) ;
F_289 ( & V_6 -> V_354 ) ;
F_289 ( & V_6 -> V_76 ) ;
F_152 ( & V_6 -> V_68 ) ;
F_152 ( & V_6 -> V_71 ) ;
F_152 ( & V_6 -> V_81 ) ;
F_152 ( & V_6 -> V_355 ) ;
F_152 ( & V_6 -> V_77 ) ;
F_152 ( & V_6 -> V_31 . V_619 ) ;
F_152 ( & V_6 -> V_387 ) ;
F_152 ( & V_6 -> V_389 ) ;
V_142 -> V_798 = 32 ;
V_142 -> V_799 = V_799 ;
V_142 -> V_800 = V_801 ;
V_142 -> V_802 = V_6 -> V_72 ;
if ( V_803 != 0xFFFF ) {
if ( V_803 < 64 ) {
V_142 -> V_803 = 64 ;
F_3 ( V_99 L_341
L_342
L_343 , V_6 -> V_35 , V_803 ) ;
} else if ( V_803 > 8192 ) {
V_142 -> V_803 = 8192 ;
F_3 ( V_99 L_341
L_342
L_344 , V_6 -> V_35 ,
V_803 ) ;
} else {
V_142 -> V_803 = V_803 & 0xFFFE ;
F_3 ( V_58 L_345
L_346 , V_6 -> V_35 , V_142 -> V_803 ) ;
}
}
if ( ( F_290 ( V_142 , & V_562 -> V_169 ) ) ) {
F_3 ( V_34 L_2 ,
V_6 -> V_35 , __FILE__ , __LINE__ , V_36 ) ;
F_19 ( & V_6 -> V_67 ) ;
goto V_804;
}
F_291 ( V_142 , V_805
| V_806 | V_807 ) ;
F_292 ( V_142 , V_808 ) ;
snprintf ( V_6 -> V_809 , sizeof( V_6 -> V_809 ) ,
L_347 , V_6 -> V_72 ) ;
V_6 -> V_353 = F_293 (
V_6 -> V_809 ) ;
if ( ! V_6 -> V_353 ) {
F_3 ( V_34 L_2 ,
V_6 -> V_35 , __FILE__ , __LINE__ , V_36 ) ;
goto V_810;
}
V_6 -> V_49 = 1 ;
if ( ( F_294 ( V_6 ) ) ) {
F_3 ( V_34 L_2 ,
V_6 -> V_35 , __FILE__ , __LINE__ , V_36 ) ;
goto V_811;
}
F_295 ( V_142 ) ;
if ( V_6 -> V_190 ) {
if ( V_6 -> V_244 == V_245 )
V_6 -> V_649 = 0 ;
else if ( V_6 -> V_244 == V_812 )
V_6 -> V_649 = 1 ;
else {
if ( F_91 ( V_6 ) )
V_6 -> V_649 = 1 ;
else
V_6 -> V_649 = 0 ;
}
} else
V_6 -> V_649 = 0 ;
F_280 ( V_6 ) ;
return 0 ;
V_811:
F_270 ( V_6 -> V_353 ) ;
V_810:
F_19 ( & V_6 -> V_67 ) ;
F_274 ( V_142 ) ;
F_275 ( V_142 ) ;
V_804:
return - V_786 ;
}
static int
F_296 ( struct V_769 * V_562 , T_50 V_200 )
{
struct V_141 * V_142 = F_269 ( V_562 ) ;
struct V_5 * V_6 = F_57 ( V_142 ) ;
T_51 V_813 ;
F_297 ( V_6 ) ;
F_298 ( V_142 ) ;
V_813 = F_299 ( V_562 , V_200 ) ;
F_3 ( V_58 L_348
L_349 , V_6 -> V_35 , V_562 ,
F_300 ( V_562 ) , V_813 ) ;
F_301 ( V_6 ) ;
F_302 ( V_562 ) ;
F_303 ( V_562 ) ;
F_304 ( V_562 , V_813 ) ;
return 0 ;
}
static int
F_305 ( struct V_769 * V_562 )
{
struct V_141 * V_142 = F_269 ( V_562 ) ;
struct V_5 * V_6 = F_57 ( V_142 ) ;
T_51 V_813 = V_562 -> V_814 ;
int V_74 ;
F_3 ( V_58 L_350
L_349 , V_6 -> V_35 , V_562 ,
F_300 ( V_562 ) , V_813 ) ;
F_304 ( V_562 , V_815 ) ;
F_306 ( V_562 , V_815 , 0 ) ;
F_307 ( V_562 ) ;
V_6 -> V_562 = V_562 ;
V_74 = F_308 ( V_6 ) ;
if ( V_74 )
return V_74 ;
F_114 ( V_6 , V_319 , V_816 ) ;
F_309 ( V_142 ) ;
F_285 ( V_6 ) ;
return 0 ;
}
static T_52
F_310 ( struct V_769 * V_562 , T_53 V_200 )
{
struct V_141 * V_142 = F_269 ( V_562 ) ;
struct V_5 * V_6 = F_57 ( V_142 ) ;
F_3 ( V_58 L_351 ,
V_6 -> V_35 , V_200 ) ;
switch ( V_200 ) {
case V_817 :
return V_818 ;
case V_819 :
V_6 -> V_317 = 1 ;
F_298 ( V_6 -> V_142 ) ;
F_297 ( V_6 ) ;
F_301 ( V_6 ) ;
return V_820 ;
case V_821 :
V_6 -> V_317 = 1 ;
F_297 ( V_6 ) ;
F_169 ( V_6 ) ;
return V_822 ;
}
return V_820 ;
}
static T_52
F_311 ( struct V_769 * V_562 )
{
struct V_141 * V_142 = F_269 ( V_562 ) ;
struct V_5 * V_6 = F_57 ( V_142 ) ;
int V_20 ;
F_3 ( V_58 L_352 ,
V_6 -> V_35 ) ;
V_6 -> V_317 = 0 ;
V_6 -> V_562 = V_562 ;
F_307 ( V_562 ) ;
V_20 = F_308 ( V_6 ) ;
if ( V_20 )
return V_822 ;
V_20 = F_114 ( V_6 , V_319 ,
V_320 ) ;
F_3 ( V_99 L_353 , V_6 -> V_35 ,
( V_20 == 0 ) ? L_125 : L_354 ) ;
if ( ! V_20 )
return V_823 ;
else
return V_822 ;
}
static void
F_312 ( struct V_769 * V_562 )
{
struct V_141 * V_142 = F_269 ( V_562 ) ;
struct V_5 * V_6 = F_57 ( V_142 ) ;
F_3 ( V_58 L_355 , V_6 -> V_35 ) ;
F_313 ( V_562 ) ;
F_285 ( V_6 ) ;
F_309 ( V_6 -> V_142 ) ;
}
static T_52
F_314 ( struct V_769 * V_562 )
{
struct V_141 * V_142 = F_269 ( V_562 ) ;
struct V_5 * V_6 = F_57 ( V_142 ) ;
F_3 ( V_58 L_356 ,
V_6 -> V_35 ) ;
return V_820 ;
}
static int T_54
F_315 ( void )
{
int error ;
V_788 = 0 ;
F_3 ( V_7 L_357 , V_789 ,
V_824 ) ;
V_801 =
F_316 ( & V_825 ) ;
if ( ! V_801 )
return - V_786 ;
V_197 = F_317 ( & V_826 ) ;
if ( ! V_197 ) {
F_318 ( V_801 ) ;
return - V_786 ;
}
F_319 () ;
V_485 = F_320 ( F_197 ) ;
V_325 = F_320 ( F_103 ) ;
V_792 = F_320 ( V_827 ) ;
V_793 = F_320 (
V_828 ) ;
V_794 = F_320 (
V_829 ) ;
V_766 = F_320 ( F_216 ) ;
V_795 = F_320 (
V_830 ) ;
V_791 = F_320 ( V_831 ) ;
V_386 = F_320 (
F_158 ) ;
V_388 = F_320 (
F_156 ) ;
V_392 = F_320 (
F_153 ) ;
F_321 () ;
error = F_322 ( & V_832 ) ;
if ( error ) {
F_323 ( V_197 ) ;
F_318 ( V_801 ) ;
}
return error ;
}
static void T_55
F_324 ( void )
{
F_3 ( V_7 L_358 ,
V_824 ) ;
F_325 ( & V_832 ) ;
F_326 () ;
F_327 ( V_485 ) ;
F_327 ( V_325 ) ;
F_327 ( V_792 ) ;
F_327 ( V_793 ) ;
F_327 ( V_794 ) ;
F_327 ( V_766 ) ;
F_327 ( V_795 ) ;
F_327 ( V_791 ) ;
F_327 ( V_386 ) ;
F_327 ( V_388 ) ;
F_327 ( V_392 ) ;
F_323 ( V_197 ) ;
F_318 ( V_801 ) ;
}
