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
static void
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
F_59 ( V_139 , F_60 ( V_139 ) , V_140 ) ;
}
static int
F_61 ( struct V_138 * V_139 , int V_140 , int V_156 )
{
if ( V_156 == V_157 || V_156 == V_158 )
F_57 ( V_139 , V_140 ) ;
else if ( V_156 == V_159 )
F_62 ( V_139 , V_140 ) ;
else
return - V_160 ;
if ( V_139 -> V_161 > 7 )
F_51 ( V_7 , V_139 , L_14
L_15 ,
V_139 -> V_162 , V_139 -> V_155 , V_139 -> V_163 ,
V_139 -> V_164 , V_139 -> V_165 ,
( V_139 -> V_166 [ 7 ] & 2 ) >> 1 ) ;
return V_139 -> V_162 ;
}
static int
F_63 ( struct V_138 * V_139 , int V_167 )
{
if ( V_139 -> V_155 ) {
F_64 ( V_139 , V_167 ) ;
if ( V_167 )
F_65 ( V_139 , V_139 -> V_162 ) ;
else
F_66 ( V_139 , V_139 -> V_162 ) ;
} else
V_167 = 0 ;
return V_167 ;
}
static int
F_67 ( struct V_168 * V_70 )
{
struct V_141 * V_142 = F_68 ( & V_70 -> V_169 ) ;
struct V_5 * V_6 = F_58 ( V_142 ) ;
struct V_147 * V_148 ;
struct V_45 * V_46 ;
struct V_47 * V_48 ;
unsigned long V_65 ;
struct V_170 * V_171 ;
V_148 = F_69 ( sizeof( struct V_168 ) , V_172 ) ;
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
if ( V_6 -> V_175 )
V_148 -> V_48 = V_48 ;
V_48 -> V_70 = V_70 ;
}
F_21 ( & V_6 -> V_76 , V_65 ) ;
return 0 ;
}
F_18 ( & V_6 -> V_66 , V_65 ) ;
V_171 = F_70 ( V_70 -> V_169 . V_176 ) ;
V_46 = F_15 ( V_6 ,
V_171 -> V_177 . V_9 ) ;
if ( V_46 ) {
V_148 -> V_27 = V_46 -> V_27 ;
V_148 -> V_9 = V_46 -> V_9 ;
V_46 -> V_70 = V_70 ;
V_46 -> V_72 = V_70 -> V_72 ;
V_46 -> V_73 = V_70 -> V_73 ;
if ( F_71 ( V_46 -> V_27 , V_6 -> V_178 ) )
V_148 -> V_65 |=
V_179 ;
}
F_21 ( & V_6 -> V_66 , V_65 ) ;
return 0 ;
}
static void
F_72 ( struct V_168 * V_70 )
{
struct V_141 * V_142 = F_68 ( & V_70 -> V_169 ) ;
struct V_5 * V_6 = F_58 ( V_142 ) ;
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
V_171 = F_70 ( V_70 -> V_169 . V_176 ) ;
V_46 = F_15 ( V_6 ,
V_171 -> V_177 . V_9 ) ;
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
F_73 ( struct V_138 * V_139 )
{
struct V_141 * V_142 ;
struct V_5 * V_6 ;
struct V_147 * V_148 ;
struct V_145 * V_146 ;
struct V_168 * V_70 ;
struct V_47 * V_48 ;
struct V_45 * V_46 ;
unsigned long V_65 ;
V_146 = F_69 ( sizeof( struct V_138 ) , V_172 ) ;
if ( ! V_146 )
return - V_126 ;
V_146 -> V_95 = V_139 -> V_95 ;
V_146 -> V_65 = V_180 ;
V_70 = V_168 ( V_139 ) ;
V_148 = V_70 -> V_150 ;
V_148 -> V_181 ++ ;
V_146 -> V_152 = V_148 ;
V_139 -> V_150 = V_146 ;
if ( ( V_148 -> V_65 & V_179 ) )
V_139 -> V_182 = 1 ;
V_142 = F_68 ( & V_70 -> V_169 ) ;
V_6 = F_58 ( V_142 ) ;
if ( V_70 -> V_73 == V_174 ) {
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
L_16 ,
V_36 , __LINE__ ) ;
V_46 -> V_70 = V_70 ;
}
F_21 ( & V_6 -> V_66 , V_65 ) ;
}
return 0 ;
}
static void
F_74 ( struct V_138 * V_139 )
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
V_148 -> V_181 -- ;
V_142 = F_68 ( & V_70 -> V_169 ) ;
V_6 = F_58 ( V_142 ) ;
if ( ! ( V_148 -> V_65 & V_153 ) ) {
F_18 ( & V_6 -> V_66 , V_65 ) ;
V_46 = F_15 ( V_6 ,
V_148 -> V_9 ) ;
if ( V_46 && ! V_148 -> V_181 )
V_46 -> V_70 = NULL ;
F_21 ( & V_6 -> V_66 , V_65 ) ;
}
F_20 ( V_139 -> V_150 ) ;
V_139 -> V_150 = NULL ;
}
static void
F_75 ( struct V_5 * V_6 ,
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
V_65 = F_9 ( V_28 . V_183 ) ;
V_82 = F_76 ( V_28 . V_184 ) ;
F_51 ( V_7 , V_139 ,
L_17
L_18 ,
( V_82 & V_185 ) ? L_19 : L_20 ,
( V_65 & V_186 ) ? L_19 : L_20 ,
( V_65 & V_187 ) ? L_19 :
L_20 ,
( V_65 & V_188 ) ? L_19 : L_20 ,
( V_65 & V_189 ) ? L_19 : L_20 ,
( V_65 & V_190 ) ? L_19 : L_20 ) ;
}
static int
F_77 ( struct V_43 * V_169 )
{
struct V_138 * V_139 = F_78 ( V_169 ) ;
struct V_5 * V_6 = F_58 ( V_139 -> V_143 ) ;
if ( V_6 -> V_175 )
return 0 ;
return ( V_139 -> V_73 == V_174 ) ? 1 : 0 ;
}
static void
F_79 ( struct V_43 * V_169 )
{
struct V_138 * V_139 = F_78 ( V_169 ) ;
struct V_5 * V_6 = F_58 ( V_139 -> V_143 ) ;
static struct V_47 * V_48 ;
unsigned long V_65 ;
T_13 V_191 ;
T_9 V_29 ;
T_10 V_192 ;
T_6 V_193 ;
T_4 V_27 ;
V_193 = 0 ;
V_27 = 0 ;
if ( V_6 -> V_175 )
goto V_75;
F_18 ( & V_6 -> V_76 , V_65 ) ;
V_48 = F_28 ( V_6 , V_139 -> V_72 ,
V_139 -> V_73 ) ;
if ( V_48 ) {
V_27 = V_48 -> V_27 ;
V_193 = V_48 -> V_193 ;
}
F_21 ( & V_6 -> V_76 , V_65 ) ;
if ( ! V_27 )
goto V_75;
if ( F_80 ( V_6 , & V_29 , & V_191 ,
V_194 , V_27 ,
sizeof( T_13 ) ) ) {
F_3 ( V_34 L_2 ,
V_6 -> V_35 , __FILE__ , __LINE__ , V_36 ) ;
V_193 = 0 ;
goto V_75;
}
V_192 = F_76 ( V_191 . V_195 ) ;
if ( ! ( V_192 &
V_196 ) )
V_193 = 0 ;
V_75:
F_81 ( V_197 , V_169 , V_193 ) ;
}
static void
F_82 ( struct V_43 * V_169 )
{
struct V_138 * V_139 = F_78 ( V_169 ) ;
struct V_5 * V_6 = F_58 ( V_139 -> V_143 ) ;
static struct V_47 * V_48 ;
unsigned long V_65 ;
T_13 V_191 ;
T_9 V_29 ;
T_10 V_198 ;
enum V_199 V_200 = V_201 ;
T_4 V_27 = 0 ;
F_18 ( & V_6 -> V_76 , V_65 ) ;
V_48 = F_28 ( V_6 , V_139 -> V_72 ,
V_139 -> V_73 ) ;
if ( V_48 )
V_27 = V_48 -> V_27 ;
F_21 ( & V_6 -> V_76 , V_65 ) ;
if ( ! V_48 )
goto V_75;
if ( F_80 ( V_6 , & V_29 , & V_191 ,
V_194 , V_27 ,
sizeof( T_13 ) ) ) {
F_3 ( V_34 L_2 ,
V_6 -> V_35 , __FILE__ , __LINE__ , V_36 ) ;
goto V_75;
}
V_198 = F_76 ( V_191 . V_195 ) ;
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
F_83 ( V_197 , V_169 , V_200 ) ;
}
static void
F_84 ( struct V_138 * V_139 , T_6 V_212 )
{
enum V_213 V_214 = V_215 ;
switch ( V_212 ) {
case V_216 :
V_214 = V_217 ;
break;
case V_218 :
V_214 = V_219 ;
break;
case V_220 :
V_214 = V_221 ;
break;
case V_222 :
V_214 = V_223 ;
break;
}
F_85 ( V_197 , & V_139 -> V_224 , V_214 ) ;
}
static int
F_86 ( struct V_5 * V_6 ,
struct V_47 * V_48 )
{
T_13 * V_191 ;
T_14 V_225 ;
T_8 V_28 ;
T_9 V_29 ;
T_4 V_226 ;
T_6 V_227 ;
if ( ( F_87 ( V_6 , V_48 -> V_27 ,
& V_227 ) ) || ! V_227 ) {
F_44 ( V_6 , F_3 ( V_99
L_2 , V_6 -> V_35 , __FILE__ , __LINE__ ,
V_36 ) ) ;
return 1 ;
}
V_48 -> V_227 = V_227 ;
V_226 = F_53 ( T_13 , V_228 ) + ( V_227 *
sizeof( V_229 ) ) ;
V_191 = F_69 ( V_226 , V_172 ) ;
if ( ! V_191 ) {
F_44 ( V_6 , F_3 ( V_99
L_2 , V_6 -> V_35 , __FILE__ , __LINE__ ,
V_36 ) ) ;
return 1 ;
}
if ( ( F_80 ( V_6 , & V_29 , V_191 ,
V_194 , V_48 -> V_27 , V_226 ) ) ) {
F_44 ( V_6 , F_3 ( V_99
L_2 , V_6 -> V_35 , __FILE__ , __LINE__ ,
V_36 ) ) ;
F_20 ( V_191 ) ;
return 1 ;
}
V_48 -> V_212 = V_191 -> V_230 ;
if ( ! ( F_88 ( V_6 , & V_29 ,
& V_225 , V_231 ,
V_191 -> V_228 [ 0 ] . V_232 ) ) ) {
if ( ! ( F_12 ( V_6 , & V_29 ,
& V_28 , V_33 ,
F_9 ( V_225 . V_233 ) ) ) ) {
V_48 -> V_82 =
F_76 ( V_28 . V_184 ) ;
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
unsigned long V_65 ;
V_27 = 0xFFFF ;
while ( ! ( F_90 ( V_6 , & V_29 ,
& V_234 , V_235 , V_27 ) ) ) {
V_30 = F_9 ( V_29 . V_38 ) &
V_39 ;
if ( V_30 == V_41 )
break;
V_27 = F_9 ( V_234 . V_233 ) ;
F_18 ( & V_6 -> V_76 , V_65 ) ;
V_48 = F_29 ( V_6 , V_27 ) ;
if ( V_48 )
V_48 -> V_236 = 0 ;
F_21 ( & V_6 -> V_76 , V_65 ) ;
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
unsigned long V_239 , V_240 ;
T_6 V_241 , V_242 ;
T_1 V_243 ;
if ( ! V_6 -> V_175 )
return;
if ( V_6 -> V_244 == V_245 ) {
F_3 ( V_58 L_21
L_22 , V_6 -> V_35 ) ;
return;
}
if ( F_91 ( V_6 ) > 1 ) {
F_89 ( V_6 ) ;
F_3 ( V_58 L_21
L_23 , V_6 -> V_35 ) ;
return;
}
if ( ( F_87 ( V_6 , V_48 -> V_27 ,
& V_227 ) ) || ! V_227 ) {
F_3 ( V_58 L_21
L_24 , V_6 -> V_35 ) ;
return;
}
V_226 = F_53 ( T_13 , V_228 ) + ( V_227 *
sizeof( V_229 ) ) ;
V_191 = F_69 ( V_226 , V_172 ) ;
if ( ! V_191 ) {
F_3 ( V_58 L_21
L_25 , V_6 -> V_35 ) ;
return;
}
if ( ( F_80 ( V_6 , & V_29 , V_191 ,
V_194 , V_48 -> V_27 , V_226 ) ) ) {
F_3 ( V_58 L_21
L_26 , V_6 -> V_35 ) ;
F_20 ( V_191 ) ;
return;
}
if ( V_227 > V_246 ) {
F_3 ( V_99 L_21
L_27
L_28 , V_6 -> V_35 , V_48 -> V_27 ,
V_227 , V_246 ) ;
F_20 ( V_191 ) ;
return;
}
for ( V_238 = 0 ; V_238 < V_227 ; V_238 ++ ) {
if ( F_88 ( V_6 , & V_29 ,
& V_225 , V_231 ,
V_191 -> V_228 [ V_238 ] . V_232 ) ||
F_9 ( V_225 . V_233 ) ==
V_173 ) {
F_3 ( V_58 L_29
L_30
L_31 ,
V_6 -> V_35 , V_48 -> V_27 ,
V_191 -> V_228 [ V_238 ] . V_232 ) ;
goto V_247;
}
V_243 = F_6 ( V_225 . V_248 ) ;
if ( V_243 >> 32 ) {
F_3 ( V_58 L_29
L_30
L_32 ,
V_6 -> V_35 , V_48 -> V_27 ,
F_9 ( V_225 . V_233 ) ,
( unsigned long long ) V_243 ) ;
goto V_247;
}
V_48 -> V_249 [ V_238 ] = F_9 ( V_225 . V_233 ) ;
}
if ( V_48 -> V_212 != V_216 ) {
F_3 ( V_58 L_21
L_33
L_34 , V_6 -> V_35 ,
V_48 -> V_27 , V_48 -> V_212 ,
( F_76 ( V_191 -> V_250 ) *
F_9 ( V_191 -> V_251 ) ) / 1024 ,
F_9 ( V_191 -> V_251 ) ) ;
goto V_247;
}
V_239 = F_76 ( V_191 -> V_250 ) ;
V_241 = F_93 ( & V_239 , 32 ) ;
if ( V_241 == 32 ) {
F_3 ( V_58 L_21
L_35 ,
V_6 -> V_35 , V_48 -> V_27 ,
( F_76 ( V_191 -> V_250 ) *
F_9 ( V_191 -> V_251 ) ) / 1024 ) ;
goto V_247;
}
V_48 -> V_252 = V_241 ;
V_240 = F_9 ( V_191 -> V_251 ) ;
V_242 = F_93 ( & V_240 , 16 ) ;
if ( V_242 == 16 ) {
F_3 ( V_58 L_21
L_36 ,
V_6 -> V_35 , V_48 -> V_27 ,
F_9 ( V_191 -> V_251 ) ) ;
goto V_247;
}
V_48 -> V_253 = V_242 ;
V_48 -> V_236 = 1 ;
F_3 ( V_58 L_37
L_38 , V_6 -> V_35 , V_48 -> V_27 ) ;
V_48 -> V_254 = F_6 ( V_191 -> V_255 ) ;
V_48 -> V_239 = F_76 ( V_191 -> V_250 ) ;
V_48 -> V_240 = F_9 ( V_191 -> V_251 ) ;
F_20 ( V_191 ) ;
return;
V_247:
V_48 -> V_236 = 0 ;
for ( V_238 = 0 ; V_238 < V_227 ; V_238 ++ )
V_48 -> V_249 [ V_238 ] = 0 ;
F_20 ( V_191 ) ;
return;
}
static void
F_94 ( struct V_5 * V_6 , struct V_138 * V_139 )
{
if ( V_139 -> type != V_256 )
return;
if ( ! ( V_6 -> V_257 . V_258 & V_259 ) )
return;
F_95 ( V_139 ) ;
F_51 ( V_7 , V_139 , L_39 ,
F_96 ( V_139 ) ? L_40 : L_41 ) ;
return;
}
static int
F_97 ( struct V_138 * V_139 )
{
struct V_141 * V_142 = V_139 -> V_143 ;
struct V_5 * V_6 = F_58 ( V_142 ) ;
struct V_145 * V_146 ;
struct V_147 * V_148 ;
struct V_45 * V_46 ;
struct V_47 * V_48 ;
unsigned long V_65 ;
int V_140 ;
T_6 V_260 = 0 ;
char * V_261 = L_42 ;
char * V_262 = L_42 ;
T_4 V_27 , V_263 = 0 ;
T_1 V_264 = 0 ;
V_140 = 1 ;
V_146 = V_139 -> V_150 ;
V_146 -> V_265 = 1 ;
V_146 -> V_65 &= ~ V_180 ;
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
if ( F_86 ( V_6 , V_48 ) ) {
F_44 ( V_6 , F_3 ( V_99
L_2 , V_6 -> V_35 , __FILE__ ,
__LINE__ , V_36 ) ) ;
return 1 ;
}
F_92 ( V_6 , V_48 ) ;
if ( V_48 -> V_82 &
V_84 ) {
V_140 = V_266 ;
V_261 = L_43 ;
} else {
V_140 = V_154 ;
if ( V_48 -> V_82 &
V_86 )
V_261 = L_44 ;
else
V_261 = L_45 ;
}
switch ( V_48 -> V_212 ) {
case V_216 :
V_262 = L_46 ;
break;
case V_220 :
V_140 = V_267 ;
if ( V_6 -> V_268 . V_269 &&
( F_76 ( V_6 -> V_268 . V_270 ) &
V_271 ) &&
! ( V_48 -> V_227 % 2 ) )
V_262 = L_47 ;
else
V_262 = L_48 ;
break;
case V_222 :
V_140 = V_267 ;
V_262 = L_49 ;
break;
case V_218 :
V_140 = V_267 ;
V_262 = L_47 ;
break;
case V_272 :
default:
V_140 = V_267 ;
V_262 = L_50 ;
break;
}
if ( ! V_6 -> V_273 )
F_51 ( V_7 , V_139 , L_51
L_52 ,
V_262 , V_48 -> V_27 ,
( unsigned long long ) V_48 -> V_52 ,
V_48 -> V_227 , V_261 ) ;
F_61 ( V_139 , V_140 , V_157 ) ;
if ( ! V_6 -> V_175 )
F_84 ( V_139 , V_48 -> V_212 ) ;
return 0 ;
}
if ( V_148 -> V_65 & V_179 ) {
if ( F_98 ( V_6 , V_27 ,
& V_263 ) ) {
F_44 ( V_6 , F_3 ( V_99
L_2 , V_6 -> V_35 ,
__FILE__ , __LINE__ , V_36 ) ) ;
return 1 ;
}
if ( V_263 && F_99 ( V_6 ,
V_263 , & V_264 ) ) {
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
V_46 -> V_263 = V_263 ;
V_46 -> V_264 = V_264 ;
if ( V_46 -> V_82 & V_84 ) {
V_140 = V_266 ;
V_260 = 1 ;
V_261 = L_43 ;
} else {
V_140 = V_154 ;
if ( V_46 -> V_82 & V_85 )
V_261 = L_45 ;
else if ( V_46 -> V_82 &
V_86 )
V_261 = L_44 ;
}
F_51 ( V_7 , V_139 , L_51
L_53 ,
V_261 , V_46 -> V_27 ,
( unsigned long long ) V_46 -> V_9 ,
V_46 -> V_274 ,
( unsigned long long ) V_46 -> V_12 ) ;
F_51 ( V_7 , V_139 , L_54
L_55 , V_261 ,
( unsigned long long ) V_46 -> V_14 ,
V_46 -> V_18 ) ;
F_21 ( & V_6 -> V_66 , V_65 ) ;
if ( ! V_260 )
F_75 ( V_6 , V_27 , V_139 ) ;
F_61 ( V_139 , V_140 , V_157 ) ;
if ( V_260 ) {
F_100 ( V_139 ) ;
F_94 ( V_6 , V_139 ) ;
}
return 0 ;
}
static int
F_101 ( struct V_138 * V_139 , struct V_275 * V_276 ,
T_16 V_277 , int V_278 [] )
{
int V_279 ;
int V_280 ;
T_16 V_281 ;
T_17 V_282 ;
V_279 = 64 ;
V_280 = 32 ;
V_282 = V_279 * V_280 ;
V_281 = V_277 ;
F_102 ( V_281 , V_282 ) ;
if ( ( T_17 ) V_277 >= 0x200000 ) {
V_279 = 255 ;
V_280 = 63 ;
V_282 = V_279 * V_280 ;
V_281 = V_277 ;
F_102 ( V_281 , V_282 ) ;
}
V_278 [ 0 ] = V_279 ;
V_278 [ 1 ] = V_280 ;
V_278 [ 2 ] = V_281 ;
return 0 ;
}
static void
F_103 ( struct V_5 * V_6 , T_6 V_283 )
{
char * V_284 ;
switch ( V_283 ) {
case V_285 :
V_284 = L_56 ;
break;
case V_286 :
V_284 = L_57 ;
break;
case V_287 :
V_284 = L_58 ;
break;
case V_288 :
V_284 = L_59 ;
break;
case V_289 :
V_284 = L_60 ;
break;
case V_290 :
V_284 = L_61 ;
break;
case 0xA :
V_284 = L_62 ;
break;
case V_291 :
V_284 = L_63 ;
break;
default:
V_284 = L_64 ;
break;
}
F_3 ( V_99 L_65 ,
V_6 -> V_35 , V_283 , V_284 ) ;
}
static T_6
F_104 ( struct V_5 * V_6 , T_4 V_88 , T_6 V_292 , T_10 V_293 )
{
T_18 * V_29 ;
if ( V_6 -> V_294 . V_295 == V_296 )
return 1 ;
if ( V_6 -> V_294 . V_88 != V_88 )
return 1 ;
F_105 ( V_6 ) ;
V_6 -> V_294 . V_295 |= V_297 ;
V_29 = F_106 ( V_6 , V_293 ) ;
if ( V_29 ) {
memcpy ( V_6 -> V_294 . V_293 , V_29 , V_29 -> V_298 * 4 ) ;
V_6 -> V_294 . V_295 |= V_299 ;
}
V_6 -> V_294 . V_295 &= ~ V_300 ;
F_107 ( & V_6 -> V_294 . V_301 ) ;
return 1 ;
}
void
F_108 ( struct V_5 * V_6 , T_4 V_27 )
{
struct V_145 * V_146 ;
struct V_138 * V_139 ;
T_6 V_302 = 0 ;
F_109 (sdev, ioc->shost) {
if ( V_302 )
continue;
V_146 = V_139 -> V_150 ;
if ( ! V_146 )
continue;
if ( V_146 -> V_152 -> V_27 == V_27 ) {
V_146 -> V_152 -> V_303 = 1 ;
V_302 = 1 ;
V_6 -> V_304 = 1 ;
}
}
}
void
F_110 ( struct V_5 * V_6 , T_4 V_27 )
{
struct V_145 * V_146 ;
struct V_138 * V_139 ;
T_6 V_302 = 0 ;
F_109 (sdev, ioc->shost) {
if ( V_302 )
continue;
V_146 = V_139 -> V_150 ;
if ( ! V_146 )
continue;
if ( V_146 -> V_152 -> V_27 == V_27 ) {
V_146 -> V_152 -> V_303 = 0 ;
V_302 = 1 ;
V_6 -> V_304 = 0 ;
}
}
}
int
F_111 ( struct V_5 * V_6 , T_4 V_27 , T_19 V_73 ,
T_19 V_72 , T_19 V_95 , T_6 type , T_4 V_305 , T_17 V_306 ,
enum V_307 V_308 )
{
T_20 * V_103 ;
T_21 * V_29 ;
T_4 V_88 = 0 ;
T_10 V_309 ;
unsigned long V_310 ;
struct V_311 * V_89 = NULL ;
int V_20 ;
if ( V_308 == V_312 )
F_112 ( & V_6 -> V_294 . V_313 ) ;
if ( V_6 -> V_294 . V_295 != V_296 ) {
F_3 ( V_58 L_66 ,
V_36 , V_6 -> V_35 ) ;
V_20 = V_314 ;
goto V_315;
}
if ( V_6 -> V_316 || V_6 -> V_317 ||
V_6 -> V_318 ) {
F_3 ( V_58 L_67 ,
V_36 , V_6 -> V_35 ) ;
V_20 = V_314 ;
goto V_315;
}
V_309 = F_113 ( V_6 , 0 ) ;
if ( V_309 & V_319 ) {
F_114 ( V_6 , F_3 ( V_58 L_68
L_69 , V_6 -> V_35 ) ) ;
V_20 = F_115 ( V_6 , V_320 ,
V_321 ) ;
V_20 = ( ! V_20 ) ? V_322 : V_314 ;
goto V_315;
}
if ( ( V_309 & V_323 ) == V_324 ) {
F_116 ( V_6 , V_309 &
V_325 ) ;
V_20 = F_115 ( V_6 , V_320 ,
V_321 ) ;
V_20 = ( ! V_20 ) ? V_322 : V_314 ;
goto V_315;
}
V_88 = F_117 ( V_6 , V_6 -> V_326 ) ;
if ( ! V_88 ) {
F_3 ( V_34 L_70 ,
V_6 -> V_35 , V_36 ) ;
V_20 = V_314 ;
goto V_315;
}
if ( type == V_327 )
V_89 = & V_6 -> V_89 [ V_305 - 1 ] ;
F_118 ( V_6 , F_3 ( V_58 L_71
L_72 , V_6 -> V_35 , V_27 , type ,
V_305 ) ) ;
V_6 -> V_294 . V_295 = V_300 ;
V_103 = F_48 ( V_6 , V_88 ) ;
V_6 -> V_294 . V_88 = V_88 ;
memset ( V_103 , 0 , sizeof( T_20 ) ) ;
memset ( V_6 -> V_294 . V_293 , 0 , sizeof( T_21 ) ) ;
V_103 -> V_328 = V_329 ;
V_103 -> V_233 = F_119 ( V_27 ) ;
V_103 -> V_330 = type ;
V_103 -> V_331 = F_119 ( V_305 ) ;
F_120 ( V_95 , (struct V_332 * ) V_103 -> V_333 ) ;
F_108 ( V_6 , V_27 ) ;
F_121 ( & V_6 -> V_294 . V_301 ) ;
F_122 ( V_6 , V_88 ) ;
V_310 = F_123 ( & V_6 -> V_294 . V_301 , V_306 * V_334 ) ;
if ( ! ( V_6 -> V_294 . V_295 & V_297 ) ) {
F_3 ( V_34 L_73 ,
V_6 -> V_35 , V_36 ) ;
F_124 ( V_103 ,
sizeof( T_20 ) / 4 ) ;
if ( ! ( V_6 -> V_294 . V_295 & V_335 ) ) {
V_20 = F_115 ( V_6 , V_320 ,
V_321 ) ;
V_20 = ( ! V_20 ) ? V_322 : V_314 ;
V_6 -> V_294 . V_295 = V_296 ;
F_110 ( V_6 , V_27 ) ;
goto V_315;
}
}
if ( V_6 -> V_294 . V_295 & V_299 ) {
V_29 = V_6 -> V_294 . V_293 ;
F_118 ( V_6 , F_3 ( V_58 L_74
L_75 ,
V_6 -> V_35 , F_9 ( V_29 -> V_38 ) ,
F_76 ( V_29 -> V_336 ) ,
F_76 ( V_29 -> V_337 ) ) ) ;
if ( V_6 -> V_8 & V_338 ) {
F_103 ( V_6 , V_29 -> V_339 ) ;
if ( V_29 -> V_38 )
F_124 ( V_103 ,
sizeof( T_20 ) / 4 ) ;
}
}
switch ( type ) {
case V_327 :
V_20 = V_322 ;
if ( V_89 -> V_90 == NULL )
break;
V_20 = V_314 ;
break;
case V_340 :
if ( F_40 ( V_6 , V_72 , V_73 ) )
V_20 = V_314 ;
else
V_20 = V_322 ;
break;
case V_341 :
case V_342 :
if ( F_41 ( V_6 , V_72 , V_95 , V_73 ) )
V_20 = V_314 ;
else
V_20 = V_322 ;
break;
case V_343 :
V_20 = V_322 ;
break;
default:
V_20 = V_314 ;
break;
}
F_110 ( V_6 , V_27 ) ;
V_6 -> V_294 . V_295 = V_296 ;
if ( V_308 == V_312 )
F_125 ( & V_6 -> V_294 . V_313 ) ;
return V_20 ;
V_315:
if ( V_308 == V_312 )
F_125 ( & V_6 -> V_294 . V_313 ) ;
return V_20 ;
}
static void
F_126 ( struct V_5 * V_6 , struct V_87 * V_90 )
{
struct V_168 * V_70 = V_90 -> V_43 -> V_344 ;
struct V_147 * V_345 = V_70 -> V_150 ;
struct V_45 * V_46 = NULL ;
unsigned long V_65 ;
char * V_346 = NULL ;
if ( ! V_345 )
return;
if ( V_6 -> V_273 )
V_346 = L_76 ;
else
V_346 = L_77 ;
F_127 ( V_90 ) ;
if ( V_345 -> V_65 & V_153 ) {
F_128 ( V_7 , V_70 , L_78
L_79 , V_346 , V_345 -> V_27 ,
V_346 , ( unsigned long long ) V_345 -> V_9 ) ;
} else {
F_18 ( & V_6 -> V_66 , V_65 ) ;
V_46 = F_15 ( V_6 ,
V_345 -> V_9 ) ;
if ( V_46 ) {
if ( V_345 -> V_65 &
V_179 ) {
F_128 ( V_7 , V_70 ,
L_80
L_81 ,
V_46 -> V_263 ,
( unsigned long long ) V_46 -> V_264 ) ;
}
F_128 ( V_7 , V_70 ,
L_82 ,
V_46 -> V_27 ,
( unsigned long long ) V_46 -> V_9 ,
V_46 -> V_274 ) ;
F_128 ( V_7 , V_70 ,
L_55 ,
( unsigned long long ) V_46 -> V_14 ,
V_46 -> V_18 ) ;
}
F_21 ( & V_6 -> V_66 , V_65 ) ;
}
}
static int
F_129 ( struct V_87 * V_90 )
{
struct V_5 * V_6 = F_58 ( V_90 -> V_43 -> V_143 ) ;
struct V_145 * V_146 ;
T_4 V_88 ;
T_4 V_27 ;
int V_74 ;
F_51 ( V_7 , V_90 -> V_43 , L_83
L_84 , V_90 ) ;
F_126 ( V_6 , V_90 ) ;
V_146 = V_90 -> V_43 -> V_150 ;
if ( ! V_146 || ! V_146 -> V_152 ) {
F_51 ( V_7 , V_90 -> V_43 , L_85
L_84 , V_90 ) ;
V_90 -> V_347 = V_348 << 16 ;
V_90 -> V_349 ( V_90 ) ;
V_74 = V_322 ;
goto V_75;
}
V_88 = F_39 ( V_6 , V_90 ) ;
if ( ! V_88 ) {
V_90 -> V_347 = V_350 << 16 ;
V_74 = V_322 ;
goto V_75;
}
if ( V_146 -> V_152 -> V_65 &
V_179 ||
V_146 -> V_152 -> V_65 & V_153 ) {
V_90 -> V_347 = V_350 << 16 ;
V_74 = V_314 ;
goto V_75;
}
F_130 ( V_6 ) ;
V_27 = V_146 -> V_152 -> V_27 ;
V_74 = F_111 ( V_6 , V_27 , V_90 -> V_43 -> V_73 ,
V_90 -> V_43 -> V_72 , V_90 -> V_43 -> V_95 ,
V_327 , V_88 , 30 , V_312 ) ;
V_75:
F_51 ( V_7 , V_90 -> V_43 , L_86 ,
( ( V_74 == V_322 ) ? L_87 : L_88 ) , V_90 ) ;
return V_74 ;
}
static int
F_131 ( struct V_87 * V_90 )
{
struct V_5 * V_6 = F_58 ( V_90 -> V_43 -> V_143 ) ;
struct V_145 * V_146 ;
struct V_45 * V_46 ;
unsigned long V_65 ;
T_4 V_27 ;
int V_74 ;
struct V_168 * V_70 = V_90 -> V_43 -> V_344 ;
F_128 ( V_7 , V_70 , L_89
L_84 , V_90 ) ;
F_126 ( V_6 , V_90 ) ;
V_146 = V_90 -> V_43 -> V_150 ;
if ( ! V_146 || ! V_146 -> V_152 ) {
F_128 ( V_7 , V_70 , L_85
L_84 , V_90 ) ;
V_90 -> V_347 = V_348 << 16 ;
V_90 -> V_349 ( V_90 ) ;
V_74 = V_322 ;
goto V_75;
}
V_27 = 0 ;
if ( V_146 -> V_152 -> V_65 &
V_179 ) {
F_18 ( & V_6 -> V_66 , V_65 ) ;
V_46 = F_16 ( V_6 ,
V_146 -> V_152 -> V_27 ) ;
if ( V_46 )
V_27 = V_46 -> V_263 ;
F_21 ( & V_6 -> V_66 , V_65 ) ;
} else
V_27 = V_146 -> V_152 -> V_27 ;
if ( ! V_27 ) {
V_90 -> V_347 = V_350 << 16 ;
V_74 = V_314 ;
goto V_75;
}
V_74 = F_111 ( V_6 , V_27 , V_90 -> V_43 -> V_73 ,
V_90 -> V_43 -> V_72 , V_90 -> V_43 -> V_95 ,
V_342 , 0 , 30 , V_312 ) ;
V_75:
F_51 ( V_7 , V_90 -> V_43 , L_90 ,
( ( V_74 == V_322 ) ? L_87 : L_88 ) , V_90 ) ;
return V_74 ;
}
static int
F_132 ( struct V_87 * V_90 )
{
struct V_5 * V_6 = F_58 ( V_90 -> V_43 -> V_143 ) ;
struct V_145 * V_146 ;
struct V_45 * V_46 ;
unsigned long V_65 ;
T_4 V_27 ;
int V_74 ;
struct V_168 * V_70 = V_90 -> V_43 -> V_344 ;
F_128 ( V_7 , V_70 , L_91
L_84 , V_90 ) ;
F_126 ( V_6 , V_90 ) ;
V_146 = V_90 -> V_43 -> V_150 ;
if ( ! V_146 || ! V_146 -> V_152 ) {
F_128 ( V_7 , V_70 , L_92
L_84 , V_90 ) ;
V_90 -> V_347 = V_348 << 16 ;
V_90 -> V_349 ( V_90 ) ;
V_74 = V_322 ;
goto V_75;
}
V_27 = 0 ;
if ( V_146 -> V_152 -> V_65 &
V_179 ) {
F_18 ( & V_6 -> V_66 , V_65 ) ;
V_46 = F_16 ( V_6 ,
V_146 -> V_152 -> V_27 ) ;
if ( V_46 )
V_27 = V_46 -> V_263 ;
F_21 ( & V_6 -> V_66 , V_65 ) ;
} else
V_27 = V_146 -> V_152 -> V_27 ;
if ( ! V_27 ) {
V_90 -> V_347 = V_350 << 16 ;
V_74 = V_314 ;
goto V_75;
}
V_74 = F_111 ( V_6 , V_27 , V_90 -> V_43 -> V_73 ,
V_90 -> V_43 -> V_72 , 0 , V_340 , 0 ,
30 , V_312 ) ;
V_75:
F_128 ( V_7 , V_70 , L_93 ,
( ( V_74 == V_322 ) ? L_87 : L_88 ) , V_90 ) ;
return V_74 ;
}
static int
F_133 ( struct V_87 * V_90 )
{
struct V_5 * V_6 = F_58 ( V_90 -> V_43 -> V_143 ) ;
int V_74 , V_351 ;
F_3 ( V_58 L_94 ,
V_6 -> V_35 , V_90 ) ;
F_127 ( V_90 ) ;
V_351 = F_115 ( V_6 , V_320 ,
V_321 ) ;
V_74 = ( V_351 < 0 ) ? V_314 : V_322 ;
F_3 ( V_58 L_95 ,
V_6 -> V_35 , ( ( V_74 == V_322 ) ? L_87 : L_88 ) , V_90 ) ;
return V_74 ;
}
static void
F_134 ( struct V_5 * V_6 , struct V_352 * V_353 )
{
unsigned long V_65 ;
if ( V_6 -> V_354 == NULL )
return;
F_18 ( & V_6 -> V_355 , V_65 ) ;
F_24 ( & V_353 -> V_67 , & V_6 -> V_356 ) ;
F_135 ( & V_353 -> V_357 , V_358 ) ;
F_136 ( V_6 -> V_354 ,
& V_353 -> V_357 , 0 ) ;
F_21 ( & V_6 -> V_355 , V_65 ) ;
}
static void
F_137 ( struct V_5 * V_6 , struct V_352
* V_353 )
{
unsigned long V_65 ;
F_18 ( & V_6 -> V_355 , V_65 ) ;
F_19 ( & V_353 -> V_67 ) ;
F_20 ( V_353 -> V_359 ) ;
F_20 ( V_353 ) ;
F_21 ( & V_6 -> V_355 , V_65 ) ;
}
static void
F_138 ( struct V_5 * V_6 )
{
struct V_352 * V_353 ;
if ( V_6 -> V_49 )
return;
V_353 = F_69 ( sizeof( struct V_352 ) , V_360 ) ;
if ( ! V_353 )
return;
V_353 -> V_361 = V_362 ;
V_353 -> V_6 = V_6 ;
F_134 ( V_6 , V_353 ) ;
}
void
F_139 ( struct V_5 * V_6 )
{
struct V_352 * V_353 ;
V_353 = F_69 ( sizeof( struct V_352 ) , V_360 ) ;
if ( ! V_353 )
return;
V_353 -> V_361 = V_363 ;
V_353 -> V_6 = V_6 ;
F_134 ( V_6 , V_353 ) ;
}
static void
F_140 ( struct V_5 * V_6 )
{
struct V_352 * V_353 , * V_100 ;
if ( F_43 ( & V_6 -> V_356 ) ||
! V_6 -> V_354 || F_141 () )
return;
F_142 (fw_event, next, &ioc->fw_event_list, list) {
if ( F_143 ( & V_353 -> V_357 ) ) {
F_137 ( V_6 , V_353 ) ;
continue;
}
V_353 -> V_364 = 1 ;
}
}
static void
F_144 ( struct V_5 * V_6 )
{
struct V_145 * V_146 ;
struct V_138 * V_139 ;
F_109 (sdev, ioc->shost) {
V_146 = V_139 -> V_150 ;
if ( ! V_146 )
continue;
if ( ! V_146 -> V_365 )
continue;
V_146 -> V_365 = 0 ;
F_23 ( V_6 , F_51 ( V_7 , V_139 , L_96
L_97 ,
V_146 -> V_152 -> V_27 ) ) ;
F_145 ( V_139 , V_366 ) ;
}
}
static void
F_146 ( struct V_5 * V_6 , T_1 V_9 )
{
struct V_145 * V_146 ;
struct V_138 * V_139 ;
F_109 (sdev, ioc->shost) {
V_146 = V_139 -> V_150 ;
if ( ! V_146 )
continue;
if ( ! V_146 -> V_365 )
continue;
if ( V_146 -> V_152 -> V_9 ==
V_9 ) {
F_23 ( V_6 , F_51 ( V_7 , V_139 ,
V_58 L_98
L_99 , V_6 -> V_35 ,
( unsigned long long ) V_9 ) ) ;
V_146 -> V_365 = 0 ;
F_145 ( V_139 , V_366 ) ;
}
}
}
static void
F_147 ( struct V_5 * V_6 )
{
struct V_145 * V_146 ;
struct V_138 * V_139 ;
F_109 (sdev, ioc->shost) {
V_146 = V_139 -> V_150 ;
if ( ! V_146 )
continue;
if ( V_146 -> V_365 )
continue;
V_146 -> V_365 = 1 ;
F_23 ( V_6 , F_51 ( V_7 , V_139 , L_100
L_97 ,
V_146 -> V_152 -> V_27 ) ) ;
F_148 ( V_139 ) ;
}
}
static void
F_149 ( struct V_5 * V_6 , T_4 V_27 )
{
struct V_145 * V_146 ;
struct V_138 * V_139 ;
F_109 (sdev, ioc->shost) {
V_146 = V_139 -> V_150 ;
if ( ! V_146 )
continue;
if ( V_146 -> V_365 )
continue;
if ( V_146 -> V_152 -> V_27 == V_27 ) {
F_23 ( V_6 , F_51 ( V_7 , V_139 ,
V_58 L_101
L_97 , V_6 -> V_35 , V_27 ) ) ;
V_146 -> V_365 = 1 ;
F_148 ( V_139 ) ;
}
}
}
static void
F_150 ( struct V_5 * V_6 ,
struct V_78 * V_79 )
{
struct V_367 * V_368 ;
struct V_45 * V_46 ;
struct V_78 * V_369 ;
unsigned long V_65 ;
if ( ! V_79 )
return;
F_4 (mpt2sas_port,
&sas_expander->sas_port_list, port_list) {
if ( V_368 -> V_370 . V_371 ==
V_372 ) {
F_18 ( & V_6 -> V_66 , V_65 ) ;
V_46 =
F_15 ( V_6 ,
V_368 -> V_370 . V_9 ) ;
if ( V_46 )
F_151 ( V_46 -> V_27 ,
V_6 -> V_373 ) ;
F_21 ( & V_6 -> V_66 , V_65 ) ;
}
}
F_4 (mpt2sas_port,
&sas_expander->sas_port_list, port_list) {
if ( V_368 -> V_370 . V_371 ==
V_374 ||
V_368 -> V_370 . V_371 ==
V_375 ) {
V_369 =
F_34 (
V_6 , V_368 -> V_370 . V_9 ) ;
F_150 ( V_6 ,
V_369 ) ;
}
}
}
static void
F_152 ( struct V_5 * V_6 ,
T_22 * V_359 )
{
int V_92 ;
T_4 V_27 ;
T_4 V_376 ;
T_6 V_377 ;
for ( V_92 = 0 ; V_92 < V_359 -> V_378 ; V_92 ++ ) {
V_27 = F_9 ( V_359 -> V_379 [ V_92 ] . V_380 ) ;
if ( ! V_27 )
continue;
V_377 = V_359 -> V_381 + V_92 ;
V_376 = V_359 -> V_379 [ V_92 ] . V_382 &
V_383 ;
if ( V_376 == V_384 )
F_149 ( V_6 , V_27 ) ;
}
}
static void
F_153 ( struct V_5 * V_6 , T_4 V_27 )
{
T_20 * V_103 ;
T_4 V_88 ;
struct V_45 * V_46 ;
struct V_147 * V_148 = NULL ;
T_1 V_9 = 0 ;
unsigned long V_65 ;
struct V_385 * V_386 ;
T_10 V_309 ;
if ( V_6 -> V_317 ) {
F_23 ( V_6 , F_3 ( V_58 L_102
L_103 , V_36 , V_6 -> V_35 , V_27 ) ) ;
return;
} else if ( V_6 -> V_318 ) {
F_23 ( V_6 , F_3 ( V_58 L_104
L_105 , V_36 , V_6 -> V_35 ,
V_27 ) ) ;
return;
}
V_309 = F_113 ( V_6 , 1 ) ;
if ( V_309 != V_387 ) {
F_23 ( V_6 , F_3 ( V_58 L_106
L_107 , V_36 , V_6 -> V_35 ,
V_27 ) ) ;
return;
}
if ( F_71 ( V_27 , V_6 -> V_178 ) )
return;
F_18 ( & V_6 -> V_66 , V_65 ) ;
V_46 = F_16 ( V_6 , V_27 ) ;
if ( V_46 && V_46 -> V_70 &&
V_46 -> V_70 -> V_150 ) {
V_148 = V_46 -> V_70 -> V_150 ;
V_148 -> V_388 = 1 ;
V_9 = V_46 -> V_9 ;
}
F_21 ( & V_6 -> V_66 , V_65 ) ;
if ( V_148 ) {
F_23 ( V_6 , F_3 ( V_58 L_108
L_109 , V_6 -> V_35 , V_27 ,
( unsigned long long ) V_9 ) ) ;
F_146 ( V_6 , V_9 ) ;
V_148 -> V_27 = V_173 ;
}
V_88 = F_117 ( V_6 , V_6 -> V_389 ) ;
if ( ! V_88 ) {
V_386 = F_69 ( sizeof( * V_386 ) , V_360 ) ;
if ( ! V_386 )
return;
F_154 ( & V_386 -> V_67 ) ;
V_386 -> V_27 = V_27 ;
F_24 ( & V_386 -> V_67 , & V_6 -> V_390 ) ;
F_23 ( V_6 , F_3 ( V_58
L_110 ,
V_6 -> V_35 , V_27 ) ) ;
return;
}
F_23 ( V_6 , F_3 ( V_58 L_111
L_112 , V_6 -> V_35 , V_27 , V_88 ,
V_6 -> V_389 ) ) ;
V_103 = F_48 ( V_6 , V_88 ) ;
memset ( V_103 , 0 , sizeof( T_20 ) ) ;
V_103 -> V_328 = V_329 ;
V_103 -> V_233 = F_119 ( V_27 ) ;
V_103 -> V_330 = V_340 ;
F_122 ( V_6 , V_88 ) ;
}
static T_6
F_155 ( struct V_5 * V_6 , T_4 V_88 ,
T_6 V_292 , T_10 V_293 )
{
T_23 * V_29 =
F_106 ( V_6 , V_293 ) ;
if ( F_156 ( V_29 ) ) {
F_23 ( V_6 , F_3 ( V_58
L_113
L_114 ,
V_6 -> V_35 , F_9 ( V_29 -> V_233 ) , V_88 ,
F_9 ( V_29 -> V_38 ) ,
F_76 ( V_29 -> V_336 ) ) ) ;
} else {
F_3 ( V_34 L_115 ,
V_6 -> V_35 , __FILE__ , __LINE__ , V_36 ) ;
}
return 1 ;
}
static void
F_157 ( struct V_5 * V_6 , T_4 V_27 )
{
T_20 * V_103 ;
T_4 V_88 ;
struct V_385 * V_386 ;
if ( V_6 -> V_316 || V_6 -> V_317 ||
V_6 -> V_318 ) {
F_23 ( V_6 , F_3 ( V_58 L_116
L_117 , V_36 , V_6 -> V_35 ) ) ;
return;
}
V_88 = F_117 ( V_6 , V_6 -> V_391 ) ;
if ( ! V_88 ) {
V_386 = F_69 ( sizeof( * V_386 ) , V_360 ) ;
if ( ! V_386 )
return;
F_154 ( & V_386 -> V_67 ) ;
V_386 -> V_27 = V_27 ;
F_24 ( & V_386 -> V_67 , & V_6 -> V_392 ) ;
F_23 ( V_6 , F_3 ( V_58
L_110 ,
V_6 -> V_35 , V_27 ) ) ;
return;
}
F_23 ( V_6 , F_3 ( V_58 L_111
L_112 , V_6 -> V_35 , V_27 , V_88 ,
V_6 -> V_391 ) ) ;
V_103 = F_48 ( V_6 , V_88 ) ;
memset ( V_103 , 0 , sizeof( T_20 ) ) ;
V_103 -> V_328 = V_329 ;
V_103 -> V_233 = F_119 ( V_27 ) ;
V_103 -> V_330 = V_340 ;
F_122 ( V_6 , V_88 ) ;
}
static T_6
F_158 ( struct V_5 * V_6 , T_4 V_88 ,
T_6 V_292 , T_10 V_293 )
{
T_4 V_27 ;
T_20 * V_393 ;
T_21 * V_29 =
F_106 ( V_6 , V_293 ) ;
if ( V_6 -> V_316 || V_6 -> V_317 ||
V_6 -> V_318 ) {
F_23 ( V_6 , F_3 ( V_58 L_116
L_117 , V_36 , V_6 -> V_35 ) ) ;
return 1 ;
}
if ( F_159 ( ! V_29 ) ) {
F_3 ( V_34 L_115 ,
V_6 -> V_35 , __FILE__ , __LINE__ , V_36 ) ;
return 1 ;
}
V_393 = F_48 ( V_6 , V_88 ) ;
V_27 = F_9 ( V_393 -> V_233 ) ;
if ( V_27 != F_9 ( V_29 -> V_233 ) ) {
F_23 ( V_6 , F_3 ( L_118
L_119 , V_27 ,
F_9 ( V_29 -> V_233 ) , V_88 ) ) ;
return 0 ;
}
F_23 ( V_6 , F_3 ( V_58
L_120
L_121 , V_6 -> V_35 ,
V_27 , V_88 , F_9 ( V_29 -> V_38 ) ,
F_76 ( V_29 -> V_336 ) ,
F_76 ( V_29 -> V_337 ) ) ) ;
return F_160 ( V_6 , V_88 ) ;
}
static T_6
F_161 ( struct V_5 * V_6 , T_4 V_88 , T_6 V_292 ,
T_10 V_293 )
{
T_4 V_27 ;
T_20 * V_393 ;
T_21 * V_29 =
F_106 ( V_6 , V_293 ) ;
T_24 * V_103 ;
T_4 V_394 ;
T_10 V_309 ;
if ( V_6 -> V_317 ) {
F_23 ( V_6 , F_3 ( V_58 L_102
L_122 , V_36 , V_6 -> V_35 ) ) ;
return 1 ;
} else if ( V_6 -> V_318 ) {
F_23 ( V_6 , F_3 ( V_58 L_104
L_123 , V_36 , V_6 -> V_35 ) ) ;
return 1 ;
}
V_309 = F_113 ( V_6 , 1 ) ;
if ( V_309 != V_387 ) {
F_23 ( V_6 , F_3 ( V_58 L_106
L_124 , V_36 , V_6 -> V_35 ) ) ;
return 1 ;
}
if ( F_159 ( ! V_29 ) ) {
F_3 ( V_34 L_115 ,
V_6 -> V_35 , __FILE__ , __LINE__ , V_36 ) ;
return 1 ;
}
V_393 = F_48 ( V_6 , V_88 ) ;
V_27 = F_9 ( V_393 -> V_233 ) ;
if ( V_27 != F_9 ( V_29 -> V_233 ) ) {
F_23 ( V_6 , F_3 ( V_58 L_118
L_119 , V_6 -> V_35 , V_27 ,
F_9 ( V_29 -> V_233 ) , V_88 ) ) ;
return 0 ;
}
F_23 ( V_6 , F_3 ( V_58
L_120
L_121 , V_6 -> V_35 ,
V_27 , V_88 , F_9 ( V_29 -> V_38 ) ,
F_76 ( V_29 -> V_336 ) ,
F_76 ( V_29 -> V_337 ) ) ) ;
V_394 = F_162 ( V_6 , V_6 -> V_395 ) ;
if ( ! V_394 ) {
F_3 ( V_34 L_70 ,
V_6 -> V_35 , V_36 ) ;
return 1 ;
}
F_23 ( V_6 , F_3 ( V_58 L_125
L_112 , V_6 -> V_35 , V_27 , V_394 ,
V_6 -> V_395 ) ) ;
V_103 = F_48 ( V_6 , V_394 ) ;
memset ( V_103 , 0 , sizeof( T_24 ) ) ;
V_103 -> V_328 = V_396 ;
V_103 -> V_397 = V_398 ;
V_103 -> V_233 = V_393 -> V_233 ;
F_163 ( V_6 , V_394 ) ;
return F_160 ( V_6 , V_88 ) ;
}
static T_6
F_160 ( struct V_5 * V_6 , T_4 V_88 )
{
struct V_385 * V_386 ;
if ( ! F_43 ( & V_6 -> V_392 ) ) {
V_386 = F_45 ( V_6 -> V_392 . V_100 ,
struct V_385 , V_67 ) ;
F_164 ( V_6 , V_88 ) ;
F_157 ( V_6 , V_386 -> V_27 ) ;
F_19 ( & V_386 -> V_67 ) ;
F_20 ( V_386 ) ;
return 0 ;
}
if ( ! F_43 ( & V_6 -> V_390 ) ) {
V_386 = F_45 ( V_6 -> V_390 . V_100 ,
struct V_385 , V_67 ) ;
F_164 ( V_6 , V_88 ) ;
F_153 ( V_6 , V_386 -> V_27 ) ;
F_19 ( & V_386 -> V_67 ) ;
F_20 ( V_386 ) ;
return 0 ;
}
return 1 ;
}
static void
F_165 ( struct V_5 * V_6 ,
T_22 * V_359 )
{
struct V_352 * V_353 ;
T_22 * V_399 ;
T_4 V_400 ;
struct V_78 * V_79 ;
unsigned long V_65 ;
int V_92 , V_376 ;
T_4 V_27 ;
for ( V_92 = 0 ; V_92 < V_359 -> V_378 ; V_92 ++ ) {
V_27 = F_9 ( V_359 -> V_379 [ V_92 ] . V_380 ) ;
if ( ! V_27 )
continue;
V_376 = V_359 -> V_379 [ V_92 ] . V_382 &
V_383 ;
if ( V_376 == V_401 )
F_153 ( V_6 , V_27 ) ;
}
V_400 = F_9 ( V_359 -> V_402 ) ;
if ( V_400 < V_6 -> V_31 . V_32 ) {
F_152 ( V_6 , V_359 ) ;
return;
}
if ( V_359 -> V_403 ==
V_404 ) {
F_18 ( & V_6 -> V_80 , V_65 ) ;
V_79 = F_33 ( V_6 ,
V_400 ) ;
F_150 ( V_6 , V_79 ) ;
F_21 ( & V_6 -> V_80 , V_65 ) ;
do {
V_27 = F_93 ( V_6 -> V_373 ,
V_6 -> V_257 . V_405 ) ;
if ( V_27 < V_6 -> V_257 . V_405 )
F_149 ( V_6 , V_27 ) ;
} while ( F_166 ( V_27 , V_6 -> V_373 ) );
} else if ( V_359 -> V_403 == V_406 )
F_152 ( V_6 , V_359 ) ;
if ( V_359 -> V_403 != V_407 )
return;
F_18 ( & V_6 -> V_355 , V_65 ) ;
F_4 (fw_event, &ioc->fw_event_list, list) {
if ( V_353 -> V_361 != V_408 ||
V_353 -> V_409 )
continue;
V_399 = V_353 -> V_359 ;
if ( V_399 -> V_403 ==
V_410 ||
V_399 -> V_403 ==
V_406 ) {
if ( F_9 ( V_399 -> V_402 ) ==
V_400 ) {
F_23 ( V_6 , F_3 ( V_58
L_126 , V_6 -> V_35 ) ) ;
V_353 -> V_409 = 1 ;
}
}
}
F_21 ( & V_6 -> V_355 , V_65 ) ;
}
static void
F_167 ( struct V_5 * V_6 , T_4 V_27 )
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
V_148 -> V_388 = 1 ;
F_23 ( V_6 , F_3 ( V_58
L_127
L_128 , V_6 -> V_35 , V_27 ,
( unsigned long long ) V_48 -> V_52 ) ) ;
}
F_21 ( & V_6 -> V_76 , V_65 ) ;
}
static void
F_168 ( T_4 V_27 , T_4 * V_411 , T_4 * V_412 )
{
if ( ! V_27 || V_27 == * V_411 || V_27 == * V_412 )
return;
if ( ! * V_411 )
* V_411 = V_27 ;
else if ( ! * V_412 )
* V_412 = V_27 ;
}
static void
F_169 ( struct V_5 * V_6 ,
T_25 * V_359 )
{
T_26 * V_413 ;
int V_92 ;
T_4 V_27 , V_263 , V_411 , V_412 ;
struct V_385 * V_386 ;
V_411 = 0 ;
V_412 = 0 ;
if ( V_6 -> V_175 )
return;
V_413 = ( T_26 * ) & V_359 -> V_414 [ 0 ] ;
for ( V_92 = 0 ; V_92 < V_359 -> V_415 ; V_92 ++ , V_413 ++ ) {
if ( V_413 -> V_416 ==
V_417 ||
V_413 -> V_416 ==
V_418 ) {
V_263 = F_9 ( V_413 -> V_419 ) ;
F_167 ( V_6 , V_263 ) ;
F_168 ( V_263 , & V_411 , & V_412 ) ;
}
}
V_413 = ( T_26 * ) & V_359 -> V_414 [ 0 ] ;
for ( V_92 = 0 ; V_92 < V_359 -> V_415 ; V_92 ++ , V_413 ++ ) {
if ( F_76 ( V_359 -> V_183 ) &
V_420 )
continue;
if ( V_413 -> V_416 == V_421 ) {
V_263 = F_9 ( V_413 -> V_419 ) ;
F_168 ( V_263 , & V_411 , & V_412 ) ;
}
}
if ( V_411 )
F_157 ( V_6 , V_411 ) ;
if ( V_412 )
F_157 ( V_6 , V_412 ) ;
V_413 = ( T_26 * ) & V_359 -> V_414 [ 0 ] ;
for ( V_92 = 0 ; V_92 < V_359 -> V_415 ; V_92 ++ , V_413 ++ ) {
if ( V_413 -> V_416 != V_421 )
continue;
V_27 = F_9 ( V_413 -> V_422 ) ;
V_263 = F_9 ( V_413 -> V_419 ) ;
F_170 ( V_27 , V_6 -> V_178 ) ;
if ( ! V_263 )
F_153 ( V_6 , V_27 ) ;
else if ( V_263 == V_411 || V_263 == V_412 ) {
V_386 = F_69 ( sizeof( * V_386 ) , V_360 ) ;
F_171 ( ! V_386 ) ;
F_154 ( & V_386 -> V_67 ) ;
V_386 -> V_27 = V_27 ;
F_24 ( & V_386 -> V_67 , & V_6 -> V_390 ) ;
F_23 ( V_6 , F_3 ( V_58
L_110 , V_6 -> V_35 ,
V_27 ) ) ;
} else
F_153 ( V_6 , V_27 ) ;
}
}
static void
F_172 ( struct V_5 * V_6 ,
T_27 * V_359 )
{
T_10 V_200 ;
if ( V_359 -> V_416 != V_423 )
return;
V_200 = F_76 ( V_359 -> V_424 ) ;
if ( V_200 == V_210 || V_200 ==
V_209 )
F_167 ( V_6 ,
F_9 ( V_359 -> V_419 ) ) ;
}
static void
F_173 ( struct V_5 * V_6 )
{
struct V_87 * V_90 ;
T_4 V_88 ;
T_4 V_238 = 0 ;
for ( V_88 = 1 ; V_88 <= V_6 -> V_93 ; V_88 ++ ) {
V_90 = F_38 ( V_6 , V_88 ) ;
if ( ! V_90 )
continue;
V_238 ++ ;
F_164 ( V_6 , V_88 ) ;
F_174 ( V_90 ) ;
if ( V_6 -> V_318 )
V_90 -> V_347 = V_348 << 16 ;
else
V_90 -> V_347 = V_350 << 16 ;
V_90 -> V_349 ( V_90 ) ;
}
F_118 ( V_6 , F_3 ( V_58 L_129 ,
V_6 -> V_35 , V_238 ) ) ;
}
static void
F_175 ( struct V_87 * V_90 , T_11 * V_103 )
{
T_4 V_425 ;
unsigned char V_426 = F_176 ( V_90 ) ;
unsigned char V_427 = F_177 ( V_90 ) ;
if ( V_427 == V_428 || V_426 == V_429 )
return;
if ( V_426 == V_430 )
V_425 = V_431 ;
else if ( V_426 == V_432 )
V_425 = V_433 ;
else
return;
switch ( V_427 ) {
case V_434 :
case V_435 :
V_425 |= V_436 |
V_437 |
V_438 ;
V_103 -> V_439 . V_440 . V_441 =
F_178 ( F_179 ( V_90 ) ) ;
break;
case V_442 :
V_425 |= V_438 ;
break;
}
V_103 -> V_443 = F_180 ( V_90 -> V_43 -> V_444 ) ;
V_103 -> V_445 = F_119 ( V_425 ) ;
}
static void
F_181 ( struct V_87 * V_90 , T_4 V_30 )
{
T_6 V_446 ;
switch ( V_30 ) {
case V_447 :
V_446 = 0x01 ;
break;
case V_448 :
V_446 = 0x02 ;
break;
case V_449 :
V_446 = 0x03 ;
break;
default:
V_446 = 0x00 ;
break;
}
F_182 ( 0 , V_90 -> V_450 , V_451 , 0x10 , V_446 ) ;
V_90 -> V_347 = V_452 << 24 | ( V_453 << 16 ) |
V_454 ;
}
static inline T_6
F_183 ( struct V_5 * V_6 , T_4 V_88 )
{
return V_6 -> V_89 [ V_88 - 1 ] . V_455 ;
}
static inline void
F_184 ( struct V_5 * V_6 , T_4 V_88 , T_6 V_455 )
{
V_6 -> V_89 [ V_88 - 1 ] . V_455 = V_455 ;
}
static void
F_185 ( struct V_5 * V_6 , struct V_87 * V_90 ,
struct V_47 * V_48 , T_11 * V_103 ,
T_4 V_88 )
{
T_10 V_456 , V_457 , V_458 , V_459 , V_460 , V_461 ;
T_10 V_239 , V_241 ;
T_6 V_227 , * V_462 , V_92 ;
T_6 V_463 = V_90 -> V_464 [ 0 ] ;
T_1 V_465 ;
if ( V_463 == V_466 || V_463 == V_467 ||
V_463 == V_468 || V_463 == V_469 ) {
V_462 = V_103 -> V_439 . V_470 ;
if ( ( V_463 < V_466 ) || ! ( V_462 [ 2 ] | V_462 [ 3 ] | V_462 [ 4 ]
| V_462 [ 5 ] ) ) {
V_461 = F_52 ( V_90 ) >>
V_48 -> V_253 ;
V_92 = ( V_463 < V_466 ) ? 2 : 6 ;
V_456 = F_186 ( * ( V_471 * ) ( & V_462 [ V_92 ] ) ) ;
if ( ( ( T_1 ) V_456 + ( T_1 ) V_461 - 1 ) <=
( T_10 ) V_48 -> V_254 ) {
V_239 = V_48 -> V_239 ;
V_241 = V_48 -> V_252 ;
V_458 = V_456 & ( V_239 - 1 ) ;
if ( ( V_458 + V_461 ) <= V_239 ) {
V_227 = V_48 -> V_227 ;
V_457 = V_456 >> V_241 ;
V_459 = V_457 / V_227 ;
V_460 = V_457 % V_227 ;
V_457 = ( V_459 << V_241 ) +
V_458 ;
V_103 -> V_233 =
F_119 ( V_48 ->
V_249 [ V_460 ] ) ;
( * ( V_471 * ) ( & V_462 [ V_92 ] ) ) =
F_178 ( V_457 ) ;
F_184 ( V_6 , V_88 , 1 ) ;
}
}
} else {
V_461 = F_52 ( V_90 ) >>
V_48 -> V_253 ;
V_465 = F_187 ( * ( V_472 * ) ( & V_462 [ 2 ] ) ) ;
if ( ( V_465 + ( T_1 ) V_461 - 1 ) <=
V_48 -> V_254 ) {
V_239 = V_48 -> V_239 ;
V_241 = V_48 -> V_252 ;
V_458 = ( T_10 ) ( V_465 & ( V_239 - 1 ) ) ;
if ( ( V_458 + V_461 ) <= V_239 ) {
V_227 = V_48 -> V_227 ;
V_457 = ( T_10 ) ( V_465 >> V_241 ) ;
V_459 = V_457 / V_227 ;
V_460 = V_457 % V_227 ;
V_457 = ( V_459 << V_241 ) +
V_458 ;
V_103 -> V_233 =
F_119 ( V_48 ->
V_249 [ V_460 ] ) ;
( * ( V_472 * ) ( & V_462 [ 2 ] ) ) =
F_188 ( ( T_1 ) V_457 ) ;
F_184 ( V_6 , V_88 , 1 ) ;
}
}
}
}
}
static int
F_189 ( struct V_141 * V_142 , struct V_87 * V_90 )
{
struct V_5 * V_6 = F_58 ( V_142 ) ;
struct V_145 * V_146 ;
struct V_147 * V_148 ;
struct V_47 * V_48 ;
T_11 * V_103 ;
T_10 V_473 ;
T_4 V_88 ;
V_146 = V_90 -> V_43 -> V_150 ;
if ( ! V_146 || ! V_146 -> V_152 ) {
V_90 -> V_347 = V_348 << 16 ;
V_90 -> V_349 ( V_90 ) ;
return 0 ;
}
if ( V_6 -> V_318 || V_6 -> V_317 ) {
V_90 -> V_347 = V_348 << 16 ;
V_90 -> V_349 ( V_90 ) ;
return 0 ;
}
V_148 = V_146 -> V_152 ;
if ( V_148 -> V_27 == V_173 ) {
V_90 -> V_347 = V_348 << 16 ;
V_90 -> V_349 ( V_90 ) ;
return 0 ;
}
if ( V_6 -> V_316 || V_6 -> V_474 )
return V_475 ;
else if ( V_146 -> V_365 || V_148 -> V_303 )
return V_476 ;
else if ( V_148 -> V_388 ) {
V_90 -> V_347 = V_348 << 16 ;
V_90 -> V_349 ( V_90 ) ;
return 0 ;
}
if ( V_90 -> V_118 == V_477 )
V_473 = V_478 ;
else if ( V_90 -> V_118 == V_119 )
V_473 = V_479 ;
else
V_473 = V_480 ;
if ( ! ( V_146 -> V_65 & V_180 ) ) {
if ( V_90 -> V_43 -> V_155 ) {
if ( V_90 -> V_43 -> V_164 )
V_473 |= V_481 ;
else
V_473 |= V_482 ;
} else
V_473 |= V_482 ;
} else
V_473 |= V_482 ;
if ( ! V_6 -> V_175 && ! F_77 ( & V_90 -> V_43 -> V_224 ) &&
F_96 ( V_90 -> V_43 ) && V_90 -> V_483 != 32 )
V_473 |= V_484 ;
V_88 = F_190 ( V_6 , V_6 -> V_485 , V_90 ) ;
if ( ! V_88 ) {
F_3 ( V_34 L_70 ,
V_6 -> V_35 , V_36 ) ;
goto V_75;
}
V_103 = F_48 ( V_6 , V_88 ) ;
memset ( V_103 , 0 , sizeof( T_11 ) ) ;
F_175 ( V_90 , V_103 ) ;
if ( V_90 -> V_483 == 32 )
V_473 |= 4 << V_486 ;
V_103 -> V_328 = V_487 ;
if ( V_146 -> V_152 -> V_65 &
V_179 )
V_103 -> V_328 = V_488 ;
else
V_103 -> V_328 = V_487 ;
V_103 -> V_233 =
F_119 ( V_146 -> V_152 -> V_27 ) ;
V_103 -> V_489 = F_180 ( F_52 ( V_90 ) ) ;
V_103 -> V_490 = F_180 ( V_473 ) ;
V_103 -> V_491 = F_119 ( V_90 -> V_483 ) ;
V_103 -> V_492 = V_493 ;
V_103 -> V_494 = V_495 ;
V_103 -> V_496 =
F_191 ( V_6 , V_88 ) ;
V_103 -> V_497 = F_53 ( T_11 , V_127 ) / 4 ;
V_103 -> V_498 = F_119 ( V_499 +
V_500 ) ;
V_103 -> V_501 = 0 ;
V_103 -> V_502 = 0 ;
F_120 ( V_146 -> V_95 , (struct V_332 * )
V_103 -> V_333 ) ;
memcpy ( V_103 -> V_439 . V_470 , V_90 -> V_464 , V_90 -> V_483 ) ;
if ( ! V_103 -> V_489 ) {
F_192 ( V_6 , & V_103 -> V_127 ) ;
} else {
if ( F_47 ( V_6 , V_90 , V_88 ) ) {
F_164 ( V_6 , V_88 ) ;
goto V_75;
}
}
V_48 = V_148 -> V_48 ;
if ( V_48 && V_48 -> V_236 )
F_185 ( V_6 , V_90 , V_48 , V_103 ,
V_88 ) ;
if ( F_156 ( V_103 -> V_328 == V_487 ) )
F_193 ( V_6 , V_88 ,
F_9 ( V_103 -> V_233 ) ) ;
else
F_163 ( V_6 , V_88 ) ;
return 0 ;
V_75:
return V_475 ;
}
static void
F_194 ( char * V_450 , struct V_503 * V_504 )
{
if ( ( V_450 [ 0 ] & 0x7F ) >= 0x72 ) {
V_504 -> V_505 = V_450 [ 1 ] & 0x0F ;
V_504 -> V_506 = V_450 [ 2 ] ;
V_504 -> V_446 = V_450 [ 3 ] ;
} else {
V_504 -> V_505 = V_450 [ 2 ] & 0x0F ;
V_504 -> V_506 = V_450 [ 12 ] ;
V_504 -> V_446 = V_450 [ 13 ] ;
}
}
static void
F_195 ( struct V_5 * V_6 , struct V_87 * V_90 ,
T_28 * V_29 , T_4 V_88 )
{
T_10 V_507 ;
T_6 * V_508 ;
T_4 V_30 = F_9 ( V_29 -> V_38 ) &
V_39 ;
T_6 V_509 = V_29 -> V_510 ;
T_6 V_511 = V_29 -> V_512 ;
char * V_513 = NULL ;
char * V_514 = NULL ;
char * V_515 = V_6 -> V_516 ;
T_10 V_517 = F_76 ( V_29 -> V_336 ) ;
struct V_45 * V_46 = NULL ;
unsigned long V_65 ;
struct V_168 * V_70 = V_90 -> V_43 -> V_344 ;
struct V_147 * V_345 = V_70 -> V_150 ;
char * V_346 = NULL ;
if ( ! V_345 )
return;
if ( V_6 -> V_273 )
V_346 = L_76 ;
else
V_346 = L_77 ;
if ( V_517 == 0x31170000 )
return;
switch ( V_30 ) {
case V_40 :
V_513 = L_130 ;
break;
case V_518 :
V_513 = L_131 ;
break;
case V_519 :
V_513 = L_132 ;
break;
case V_520 :
V_513 = L_133 ;
break;
case V_521 :
V_513 = L_134 ;
break;
case V_522 :
V_513 = L_135 ;
break;
case V_523 :
V_513 = L_136 ;
break;
case V_524 :
V_513 = L_137 ;
break;
case V_525 :
V_513 = L_138 ;
break;
case V_526 :
V_513 = L_139 ;
break;
case V_527 :
V_513 = L_140 ;
break;
case V_528 :
V_513 = L_141 ;
break;
case V_529 :
V_513 = L_142 ;
break;
case V_530 :
V_513 = L_143 ;
break;
case V_447 :
V_513 = L_144 ;
break;
case V_449 :
V_513 = L_145 ;
break;
case V_448 :
V_513 = L_146 ;
break;
default:
V_513 = L_64 ;
break;
}
switch ( V_511 ) {
case V_531 :
V_514 = L_147 ;
break;
case V_532 :
V_514 = L_148 ;
break;
case V_533 :
V_514 = L_149 ;
break;
case V_534 :
V_514 = L_150 ;
break;
case V_535 :
V_514 = L_151 ;
break;
case V_536 :
V_514 = L_152 ;
break;
case V_537 :
V_514 = L_153 ;
break;
case V_538 :
V_514 = L_154 ;
break;
case V_539 :
V_514 = L_155 ;
break;
case V_540 :
V_514 = L_156 ;
break;
case V_541 :
V_514 = L_157 ;
break;
default:
V_514 = L_64 ;
break;
}
V_515 [ 0 ] = '\0' ;
if ( ! V_509 )
V_515 = L_158 ;
if ( V_509 & V_542 )
strcat ( V_515 , L_159 ) ;
if ( V_509 & V_543 )
strcat ( V_515 , L_160 ) ;
if ( V_509 & V_544 )
strcat ( V_515 , L_161 ) ;
if ( V_509 & V_545 )
strcat ( V_515 , L_162 ) ;
if ( V_509 & V_546 )
strcat ( V_515 , L_163 ) ;
F_127 ( V_90 ) ;
if ( V_345 -> V_65 & V_153 ) {
F_3 ( V_99 L_164 , V_6 -> V_35 ,
V_346 , ( unsigned long long ) V_345 -> V_9 ) ;
} else {
F_18 ( & V_6 -> V_66 , V_65 ) ;
V_46 = F_15 ( V_6 ,
V_345 -> V_9 ) ;
if ( V_46 ) {
F_3 ( V_99 L_165
L_166 , V_6 -> V_35 , V_46 -> V_9 ,
V_46 -> V_274 ) ;
F_3 ( V_99
L_167 ,
V_6 -> V_35 , V_46 -> V_14 ,
V_46 -> V_18 ) ;
}
F_21 ( & V_6 -> V_66 , V_65 ) ;
}
F_3 ( V_99 L_168
L_169 , V_6 -> V_35 , F_9 ( V_29 -> V_233 ) ,
V_513 , V_30 , V_88 ) ;
F_3 ( V_99 L_170
L_171 , V_6 -> V_35 , F_52 ( V_90 ) , V_90 -> V_547 ,
F_196 ( V_90 ) ) ;
F_3 ( V_99 L_172
L_173 , V_6 -> V_35 , F_9 ( V_29 -> V_548 ) ,
F_76 ( V_29 -> V_549 ) , V_90 -> V_347 ) ;
F_3 ( V_99 L_174
L_175 , V_6 -> V_35 , V_514 ,
V_511 , V_515 , V_509 ) ;
if ( V_509 & V_546 ) {
struct V_503 V_504 ;
F_194 ( V_90 -> V_450 , & V_504 ) ;
F_3 ( V_99 L_176
L_177 , V_6 -> V_35 , V_504 . V_505 ,
V_504 . V_506 , V_504 . V_446 , F_76 ( V_29 -> V_550 ) ) ;
}
if ( V_509 & V_542 ) {
V_507 = F_76 ( V_29 -> V_551 ) ;
V_508 = ( T_6 * ) & V_507 ;
F_103 ( V_6 , V_508 [ 0 ] ) ;
}
}
static void
F_197 ( struct V_5 * V_6 , T_4 V_27 )
{
T_29 V_29 ;
T_30 V_103 ;
memset ( & V_103 , 0 , sizeof( T_30 ) ) ;
V_103 . V_328 = V_552 ;
V_103 . V_553 = V_554 ;
V_103 . V_555 =
F_180 ( V_556 ) ;
V_103 . V_233 = F_119 ( V_27 ) ;
V_103 . V_183 = V_557 ;
if ( ( F_198 ( V_6 , & V_29 ,
& V_103 ) ) != 0 ) {
F_3 ( V_34 L_2 , V_6 -> V_35 ,
__FILE__ , __LINE__ , V_36 ) ;
return;
}
if ( V_29 . V_38 || V_29 . V_336 ) {
F_23 ( V_6 , F_3 ( V_58 L_178
L_179 , V_6 -> V_35 ,
F_9 ( V_29 . V_38 ) ,
F_76 ( V_29 . V_336 ) ) ) ;
return;
}
}
static void
F_199 ( struct V_5 * V_6 , T_4 V_27 )
{
struct V_352 * V_353 ;
V_353 = F_69 ( sizeof( struct V_352 ) , V_360 ) ;
if ( ! V_353 )
return;
V_353 -> V_361 = V_558 ;
V_353 -> V_559 = V_27 ;
V_353 -> V_6 = V_6 ;
F_134 ( V_6 , V_353 ) ;
}
static void
F_200 ( struct V_5 * V_6 , T_4 V_27 )
{
struct V_168 * V_70 ;
struct V_147 * V_148 ;
T_31 * V_560 ;
T_32 * V_359 ;
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
if ( ( V_148 -> V_65 & V_179 ) ||
( ( V_148 -> V_65 & V_153 ) ) ) {
F_21 ( & V_6 -> V_66 , V_65 ) ;
return;
}
F_128 ( V_561 , V_70 , L_180 ) ;
F_21 ( & V_6 -> V_66 , V_65 ) ;
if ( V_6 -> V_562 -> V_563 == V_564 )
F_199 ( V_6 , V_27 ) ;
V_226 = F_53 ( T_31 , V_565 ) +
sizeof( T_32 ) ;
V_560 = F_69 ( V_226 , V_360 ) ;
if ( ! V_560 ) {
F_3 ( V_34 L_2 ,
V_6 -> V_35 , __FILE__ , __LINE__ , V_36 ) ;
return;
}
V_560 -> V_328 = V_566 ;
V_560 -> V_567 =
F_119 ( V_568 ) ;
V_560 -> V_298 = V_226 / 4 ;
V_560 -> V_569 =
F_119 ( sizeof( T_32 ) / 4 ) ;
V_359 = ( T_32 * )
V_560 -> V_565 ;
V_359 -> V_416 = V_570 ;
V_359 -> V_571 = 0x5D ;
V_359 -> V_233 = F_119 ( V_27 ) ;
V_359 -> V_11 = F_201 ( V_148 -> V_9 ) ;
F_202 ( V_6 , V_560 ) ;
F_20 ( V_560 ) ;
}
static T_6
F_203 ( struct V_5 * V_6 , T_4 V_88 , T_6 V_292 , T_10 V_293 )
{
T_11 * V_103 ;
T_28 * V_29 ;
struct V_87 * V_90 ;
T_4 V_30 ;
T_10 V_572 ;
T_6 V_509 ;
T_6 V_511 ;
T_10 V_517 ;
struct V_145 * V_146 ;
T_10 V_283 = 0 ;
unsigned long V_65 ;
V_29 = F_106 ( V_6 , V_293 ) ;
V_90 = F_38 ( V_6 , V_88 ) ;
if ( V_90 == NULL )
return 1 ;
V_103 = F_48 ( V_6 , V_88 ) ;
if ( V_29 == NULL ) {
V_90 -> V_347 = V_573 << 16 ;
goto V_75;
}
V_146 = V_90 -> V_43 -> V_150 ;
if ( ! V_146 || ! V_146 -> V_152 ||
V_146 -> V_152 -> V_388 ) {
V_90 -> V_347 = V_348 << 16 ;
goto V_75;
}
V_30 = F_9 ( V_29 -> V_38 ) ;
if ( F_183 ( V_6 , V_88 ) &&
( ( V_30 & V_39 )
!= V_526 ) ) {
F_18 ( & V_6 -> V_91 , V_65 ) ;
V_6 -> V_89 [ V_88 - 1 ] . V_90 = V_90 ;
F_184 ( V_6 , V_88 , 0 ) ;
F_21 ( & V_6 -> V_91 , V_65 ) ;
memcpy ( V_103 -> V_439 . V_470 , V_90 -> V_464 , V_90 -> V_483 ) ;
V_103 -> V_233 =
F_119 ( V_146 -> V_152 -> V_27 ) ;
F_193 ( V_6 , V_88 ,
V_146 -> V_152 -> V_27 ) ;
return 0 ;
}
V_509 = V_29 -> V_510 ;
if ( V_509 & V_542 )
V_283 =
F_76 ( V_29 -> V_551 ) & 0xFF ;
if ( ! V_146 -> V_574 ) {
V_146 -> V_574 ++ ;
if ( ! V_6 -> V_175 && ! F_77 ( & V_90 -> V_43 -> V_224 ) &&
F_96 ( V_90 -> V_43 ) &&
V_283 == V_286 ) {
F_204 ( V_90 -> V_43 ) ;
F_51 ( V_7 , V_90 -> V_43 , L_181 ) ;
}
}
V_572 = F_76 ( V_29 -> V_549 ) ;
F_205 ( V_90 , F_52 ( V_90 ) - V_572 ) ;
if ( V_30 & V_575 )
V_517 = F_76 ( V_29 -> V_336 ) ;
else
V_517 = 0 ;
V_30 &= V_39 ;
V_511 = V_29 -> V_512 ;
if ( V_30 == V_523 && V_572 == 0 &&
( V_511 == V_534 ||
V_511 == V_537 ||
V_511 == V_539 ) ) {
V_30 = V_40 ;
}
if ( V_509 & V_546 ) {
struct V_503 V_504 ;
const void * V_576 = F_206 ( V_6 ,
V_88 ) ;
T_10 V_226 = F_207 ( T_10 , V_495 ,
F_76 ( V_29 -> V_550 ) ) ;
memcpy ( V_90 -> V_450 , V_576 , V_226 ) ;
F_194 ( V_90 -> V_450 , & V_504 ) ;
if ( V_504 . V_506 == 0x5D )
F_200 ( V_6 ,
F_9 ( V_29 -> V_233 ) ) ;
}
switch ( V_30 ) {
case V_577 :
case V_578 :
V_90 -> V_347 = V_579 ;
break;
case V_521 :
V_90 -> V_347 = V_348 << 16 ;
break;
case V_529 :
if ( V_146 -> V_365 ) {
V_90 -> V_347 = V_580 << 16 ;
goto V_75;
}
V_90 -> V_347 = V_581 << 16 ;
break;
case V_526 :
case V_530 :
V_90 -> V_347 = V_350 << 16 ;
break;
case V_527 :
if ( ( V_572 == 0 ) || ( V_90 -> V_547 > V_572 ) )
V_90 -> V_347 = V_581 << 16 ;
else
V_90 -> V_347 = ( V_573 << 16 ) | V_511 ;
break;
case V_523 :
V_90 -> V_347 = ( V_573 << 16 ) | V_511 ;
if ( ( V_509 & V_546 ) )
break;
if ( V_572 < V_90 -> V_547 ) {
if ( V_511 == V_579 )
V_90 -> V_347 = V_579 ;
else
V_90 -> V_347 = V_581 << 16 ;
} else if ( V_509 & ( V_545 |
V_544 ) )
V_90 -> V_347 = V_581 << 16 ;
else if ( V_509 & V_543 )
V_90 -> V_347 = V_350 << 16 ;
else if ( ! V_572 && V_90 -> V_464 [ 0 ] == V_582 ) {
V_29 -> V_510 = V_546 ;
V_29 -> V_512 = V_454 ;
V_90 -> V_347 = ( V_452 << 24 ) |
V_454 ;
V_90 -> V_450 [ 0 ] = 0x70 ;
V_90 -> V_450 [ 2 ] = V_451 ;
V_90 -> V_450 [ 12 ] = 0x20 ;
V_90 -> V_450 [ 13 ] = 0 ;
}
break;
case V_522 :
F_205 ( V_90 , 0 ) ;
case V_519 :
case V_40 :
V_90 -> V_347 = ( V_573 << 16 ) | V_511 ;
if ( V_283 ==
V_286 ||
( V_509 & ( V_545 |
V_544 ) ) )
V_90 -> V_347 = V_581 << 16 ;
else if ( V_509 & V_543 )
V_90 -> V_347 = V_350 << 16 ;
break;
case V_447 :
case V_449 :
case V_448 :
F_181 ( V_90 , V_30 ) ;
break;
case V_525 :
case V_518 :
case V_583 :
case V_584 :
case V_585 :
case V_586 :
case V_524 :
case V_528 :
default:
V_90 -> V_347 = V_581 << 16 ;
break;
}
#ifdef F_208
if ( V_90 -> V_347 && ( V_6 -> V_8 & V_587 ) )
F_195 ( V_6 , V_90 , V_29 , V_88 ) ;
#endif
V_75:
F_174 ( V_90 ) ;
V_90 -> V_349 ( V_90 ) ;
return 1 ;
}
static void
F_209 ( struct V_5 * V_6 )
{
T_4 V_226 ;
T_4 V_30 ;
int V_92 ;
T_9 V_29 ;
T_34 * V_588 = NULL ;
T_4 V_589 ;
T_6 V_590 ;
F_118 ( V_6 , F_3 ( V_58
L_182 ,
V_6 -> V_35 , ( unsigned long long ) V_6 -> V_31 . V_9 ) ) ;
V_226 = F_53 ( T_34 , V_591 ) + ( V_6 -> V_31 . V_32
* sizeof( V_592 ) ) ;
V_588 = F_69 ( V_226 , V_172 ) ;
if ( ! V_588 ) {
F_3 ( V_34 L_2 ,
V_6 -> V_35 , __FILE__ , __LINE__ , V_36 ) ;
return;
}
if ( ( F_210 ( V_6 , & V_29 ,
V_588 , V_226 ) ) != 0 )
goto V_75;
V_30 = F_9 ( V_29 . V_38 ) & V_39 ;
if ( V_30 != V_40 )
goto V_75;
for ( V_92 = 0 ; V_92 < V_6 -> V_31 . V_32 ; V_92 ++ ) {
V_590 = V_588 -> V_591 [ V_92 ] . V_593 >> 4 ;
if ( V_92 == 0 )
V_6 -> V_31 . V_27 = F_9 ( V_588 ->
V_591 [ 0 ] . V_594 ) ;
V_6 -> V_31 . V_274 [ V_92 ] . V_27 = V_6 -> V_31 . V_27 ;
V_589 = F_9 ( V_588 -> V_591 [ V_92 ] .
V_380 ) ;
if ( V_589 && V_590 < V_595 )
V_590 = V_595 ;
F_211 ( V_6 , V_6 -> V_31 . V_9 ,
V_589 , V_92 , V_590 ) ;
}
V_75:
F_20 ( V_588 ) ;
}
static void
F_212 ( struct V_5 * V_6 )
{
int V_92 ;
T_9 V_29 ;
T_34 * V_588 = NULL ;
T_35 * V_596 = NULL ;
T_36 V_597 ;
T_8 V_28 ;
T_37 V_598 ;
T_4 V_30 ;
T_4 V_226 ;
T_4 V_599 ;
F_213 ( V_6 , & V_6 -> V_31 . V_32 ) ;
if ( ! V_6 -> V_31 . V_32 ) {
F_3 ( V_34 L_2 ,
V_6 -> V_35 , __FILE__ , __LINE__ , V_36 ) ;
return;
}
V_226 = F_53 ( T_34 , V_591 ) + ( V_6 -> V_31 . V_32 *
sizeof( V_592 ) ) ;
V_588 = F_69 ( V_226 , V_172 ) ;
if ( ! V_588 ) {
F_3 ( V_34 L_2 ,
V_6 -> V_35 , __FILE__ , __LINE__ , V_36 ) ;
return;
}
if ( ( F_210 ( V_6 , & V_29 ,
V_588 , V_226 ) ) ) {
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
V_226 = F_53 ( T_35 , V_591 ) + ( V_6 -> V_31 . V_32 *
sizeof( V_600 ) ) ;
V_596 = F_69 ( V_226 , V_172 ) ;
if ( ! V_596 ) {
F_3 ( V_34 L_2 ,
V_6 -> V_35 , __FILE__ , __LINE__ , V_36 ) ;
goto V_75;
}
if ( ( F_214 ( V_6 , & V_29 ,
V_596 , V_226 ) ) ) {
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
V_6 -> V_601 =
F_9 ( V_596 -> V_602 ) ;
V_599 =
F_9 ( V_596 -> V_603 ) ;
if ( V_599 & V_604 )
V_6 -> V_599 = ( V_599 &
V_605 ) * 16 ;
else
V_6 -> V_599 = V_599 &
V_605 ;
V_6 -> V_31 . V_606 = & V_6 -> V_142 -> V_607 ;
V_6 -> V_31 . V_274 = F_215 ( V_6 -> V_31 . V_32 ,
sizeof( struct V_608 ) , V_172 ) ;
if ( ! V_6 -> V_31 . V_274 ) {
F_3 ( V_34 L_2 ,
V_6 -> V_35 , __FILE__ , __LINE__ , V_36 ) ;
goto V_75;
}
for ( V_92 = 0 ; V_92 < V_6 -> V_31 . V_32 ; V_92 ++ ) {
if ( ( F_216 ( V_6 , & V_29 , & V_597 ,
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
V_6 -> V_31 . V_27 = F_9 ( V_588 ->
V_591 [ 0 ] . V_594 ) ;
V_6 -> V_31 . V_274 [ V_92 ] . V_27 = V_6 -> V_31 . V_27 ;
V_6 -> V_31 . V_274 [ V_92 ] . V_609 = V_92 ;
F_217 ( V_6 , & V_6 -> V_31 . V_274 [ V_92 ] ,
V_597 , V_6 -> V_31 . V_606 ) ;
}
if ( ( F_12 ( V_6 , & V_29 , & V_28 ,
V_33 , V_6 -> V_31 . V_27 ) ) ) {
F_3 ( V_34 L_2 ,
V_6 -> V_35 , __FILE__ , __LINE__ , V_36 ) ;
goto V_75;
}
V_6 -> V_31 . V_610 =
F_9 ( V_28 . V_611 ) ;
V_6 -> V_31 . V_9 = F_6 ( V_28 . V_11 ) ;
F_3 ( V_58 L_183
L_184 , V_6 -> V_35 , V_6 -> V_31 . V_27 ,
( unsigned long long ) V_6 -> V_31 . V_9 ,
V_6 -> V_31 . V_32 ) ;
if ( V_6 -> V_31 . V_610 ) {
if ( ! ( F_218 ( V_6 , & V_29 ,
& V_598 ,
V_612 ,
V_6 -> V_31 . V_610 ) ) ) {
V_6 -> V_31 . V_14 =
F_6 ( V_598 . V_16 ) ;
}
}
V_75:
F_20 ( V_596 ) ;
F_20 ( V_588 ) ;
}
static int
F_219 ( struct V_5 * V_6 , T_4 V_27 )
{
struct V_78 * V_79 ;
T_9 V_29 ;
T_38 V_613 ;
T_39 V_614 ;
T_37 V_598 ;
T_10 V_30 ;
T_4 V_615 ;
T_1 V_9 , V_69 = 0 ;
int V_92 ;
unsigned long V_65 ;
struct V_367 * V_368 = NULL ;
int V_20 = 0 ;
if ( ! V_27 )
return - 1 ;
if ( V_6 -> V_316 || V_6 -> V_318 )
return - 1 ;
if ( ( F_220 ( V_6 , & V_29 , & V_613 ,
V_616 , V_27 ) ) ) {
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
V_615 = F_9 ( V_613 . V_617 ) ;
if ( F_11 ( V_6 , V_615 , & V_69 )
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
V_20 = F_219 ( V_6 , V_615 ) ;
if ( V_20 != 0 )
return V_20 ;
}
}
F_18 ( & V_6 -> V_80 , V_65 ) ;
V_9 = F_6 ( V_613 . V_11 ) ;
V_79 = F_34 ( V_6 ,
V_9 ) ;
F_21 ( & V_6 -> V_80 , V_65 ) ;
if ( V_79 )
return 0 ;
V_79 = F_69 ( sizeof( struct V_78 ) ,
V_172 ) ;
if ( ! V_79 ) {
F_3 ( V_34 L_2 ,
V_6 -> V_35 , __FILE__ , __LINE__ , V_36 ) ;
return - 1 ;
}
V_79 -> V_27 = V_27 ;
V_79 -> V_32 = V_613 . V_618 ;
V_79 -> V_69 = V_69 ;
V_79 -> V_9 = V_9 ;
F_3 ( V_58 L_185
L_186 , V_6 -> V_35 ,
V_27 , V_615 , ( unsigned long long )
V_79 -> V_9 , V_79 -> V_32 ) ;
if ( ! V_79 -> V_32 )
goto V_619;
V_79 -> V_274 = F_215 ( V_79 -> V_32 ,
sizeof( struct V_608 ) , V_172 ) ;
if ( ! V_79 -> V_274 ) {
F_3 ( V_34 L_2 ,
V_6 -> V_35 , __FILE__ , __LINE__ , V_36 ) ;
V_20 = - 1 ;
goto V_619;
}
F_154 ( & V_79 -> V_620 ) ;
V_368 = F_25 ( V_6 , V_27 ,
V_69 ) ;
if ( ! V_368 ) {
F_3 ( V_34 L_2 ,
V_6 -> V_35 , __FILE__ , __LINE__ , V_36 ) ;
V_20 = - 1 ;
goto V_619;
}
V_79 -> V_606 = & V_368 -> V_171 -> V_169 ;
for ( V_92 = 0 ; V_92 < V_79 -> V_32 ; V_92 ++ ) {
if ( ( F_221 ( V_6 , & V_29 ,
& V_614 , V_92 , V_27 ) ) ) {
F_3 ( V_34 L_2 ,
V_6 -> V_35 , __FILE__ , __LINE__ , V_36 ) ;
V_20 = - 1 ;
goto V_619;
}
V_79 -> V_274 [ V_92 ] . V_27 = V_27 ;
V_79 -> V_274 [ V_92 ] . V_609 = V_92 ;
if ( ( F_222 ( V_6 ,
& V_79 -> V_274 [ V_92 ] , V_614 ,
V_79 -> V_606 ) ) ) {
F_3 ( V_34 L_2 ,
V_6 -> V_35 , __FILE__ , __LINE__ , V_36 ) ;
V_20 = - 1 ;
goto V_619;
}
}
if ( V_79 -> V_610 ) {
if ( ! ( F_218 ( V_6 , & V_29 ,
& V_598 , V_612 ,
V_79 -> V_610 ) ) ) {
V_79 -> V_14 =
F_6 ( V_598 . V_16 ) ;
}
}
F_35 ( V_6 , V_79 ) ;
return 0 ;
V_619:
if ( V_368 )
F_26 ( V_6 , V_79 -> V_9 ,
V_69 ) ;
F_20 ( V_79 ) ;
return V_20 ;
}
static T_6
F_223 ( struct V_5 * V_6 , T_4 V_88 , T_6 V_292 , T_10 V_293 )
{
T_18 * V_29 ;
V_29 = F_106 ( V_6 , V_293 ) ;
if ( V_6 -> V_621 . V_295 == V_296 )
return 1 ;
if ( V_6 -> V_621 . V_88 != V_88 )
return 1 ;
V_6 -> V_621 . V_295 |= V_297 ;
if ( V_29 ) {
memcpy ( V_6 -> V_621 . V_293 , V_29 ,
V_29 -> V_298 * 4 ) ;
V_6 -> V_621 . V_295 |= V_299 ;
}
V_6 -> V_621 . V_295 &= ~ V_300 ;
F_107 ( & V_6 -> V_621 . V_301 ) ;
return 1 ;
}
void
F_224 ( struct V_5 * V_6 , T_1 V_9 )
{
struct V_78 * V_79 ;
unsigned long V_65 ;
if ( V_6 -> V_316 )
return;
F_18 ( & V_6 -> V_80 , V_65 ) ;
V_79 = F_34 ( V_6 ,
V_9 ) ;
if ( V_79 )
F_19 ( & V_79 -> V_67 ) ;
F_21 ( & V_6 -> V_80 , V_65 ) ;
if ( V_79 )
F_225 ( V_6 , V_79 ) ;
}
static T_6
F_226 ( struct V_5 * V_6 , T_1 V_9 ,
T_4 V_27 , T_6 V_622 )
{
T_6 V_20 = 1 ;
char * V_284 = NULL ;
switch ( V_622 ) {
case V_623 :
case V_624 :
V_20 = 0 ;
break;
case V_625 :
V_284 = L_187 ;
break;
case V_626 :
V_284 = L_188 ;
break;
case V_627 :
V_284 = L_189 ;
break;
case V_628 :
V_284 = L_190 ;
break;
case V_629 :
V_284 = L_191 ;
break;
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
case V_641 :
V_284 = L_192 ;
break;
default:
V_284 = L_64 ;
break;
}
if ( ! V_20 )
return 0 ;
F_3 ( V_34 L_193
L_97 , V_6 -> V_35 , V_284 ,
( unsigned long long ) V_9 , V_27 ) ;
return V_20 ;
}
static void
F_227 ( struct V_5 * V_6 , T_4 V_27 )
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
V_82 = F_76 ( V_28 . V_184 ) ;
if ( ! ( F_36 ( V_82 ) ) )
return;
F_18 ( & V_6 -> V_66 , V_65 ) ;
V_9 = F_6 ( V_28 . V_11 ) ;
V_46 = F_15 ( V_6 ,
V_9 ) ;
if ( ! V_46 ) {
F_3 ( V_34 L_194
L_195 , V_6 -> V_35 , V_27 ) ;
F_21 ( & V_6 -> V_66 , V_65 ) ;
return;
}
if ( F_159 ( V_46 -> V_27 != V_27 ) ) {
V_70 = V_46 -> V_70 ;
V_148 = V_70 -> V_150 ;
F_128 ( V_7 , V_70 , L_196
L_197 , V_46 -> V_27 , V_27 ) ;
V_148 -> V_27 = V_27 ;
V_46 -> V_27 = V_27 ;
}
if ( ! ( F_9 ( V_28 . V_183 ) &
V_642 ) ) {
F_3 ( V_34 L_194
L_198 , V_6 -> V_35 , V_27 ) ;
F_21 ( & V_6 -> V_66 , V_65 ) ;
return;
}
if ( F_226 ( V_6 , V_9 , V_27 ,
V_28 . V_643 ) ) {
F_21 ( & V_6 -> V_66 , V_65 ) ;
return;
}
F_21 ( & V_6 -> V_66 , V_65 ) ;
F_146 ( V_6 , V_9 ) ;
}
static int
F_228 ( struct V_5 * V_6 , T_4 V_27 , T_6 V_644 , T_6 V_645 )
{
T_9 V_29 ;
T_8 V_28 ;
T_37 V_598 ;
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
if ( ! ( F_9 ( V_28 . V_183 ) &
V_642 ) ) {
F_3 ( V_34 L_2 ,
V_6 -> V_35 , __FILE__ , __LINE__ , V_36 ) ;
F_3 ( V_34 L_199 ,
V_6 -> V_35 , F_9 ( V_28 . V_183 ) ) ;
return - 1 ;
}
if ( F_226 ( V_6 , V_9 , V_27 ,
V_28 . V_643 ) )
return - 1 ;
V_82 = F_76 ( V_28 . V_184 ) ;
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
V_46 = F_69 ( sizeof( struct V_45 ) ,
V_172 ) ;
if ( ! V_46 ) {
F_3 ( V_34 L_2 ,
V_6 -> V_35 , __FILE__ , __LINE__ , V_36 ) ;
return - 1 ;
}
V_46 -> V_27 = V_27 ;
if ( F_11 ( V_6 , F_9
( V_28 . V_617 ) ,
& V_46 -> V_69 ) != 0 )
F_3 ( V_34 L_2 ,
V_6 -> V_35 , __FILE__ , __LINE__ , V_36 ) ;
V_46 -> V_610 =
F_9 ( V_28 . V_611 ) ;
V_46 -> V_18 =
F_9 ( V_28 . V_646 ) ;
V_46 -> V_82 = V_82 ;
V_46 -> V_9 = V_9 ;
V_46 -> V_274 = V_28 . V_647 ;
if ( V_46 -> V_610 && ! ( F_218 (
V_6 , & V_29 , & V_598 , V_612 ,
V_46 -> V_610 ) ) )
V_46 -> V_14 =
F_6 ( V_598 . V_16 ) ;
V_46 -> V_12 = F_6 ( V_28 . V_13 ) ;
if ( V_6 -> V_648 )
F_27 ( V_6 , V_46 ) ;
else
F_22 ( V_6 , V_46 ) ;
return 0 ;
}
static void
F_229 ( struct V_5 * V_6 ,
struct V_45 * V_46 )
{
struct V_147 * V_148 ;
F_23 ( V_6 , F_3 ( V_58 L_200
L_109 , V_6 -> V_35 , V_36 ,
V_46 -> V_27 , ( unsigned long long )
V_46 -> V_9 ) ) ;
if ( V_46 -> V_70 && V_46 -> V_70 -> V_150 ) {
V_148 = V_46 -> V_70 -> V_150 ;
V_148 -> V_388 = 1 ;
F_146 ( V_6 , V_46 -> V_9 ) ;
V_148 -> V_27 =
V_173 ;
}
if ( ! V_6 -> V_649 )
F_26 ( V_6 ,
V_46 -> V_9 ,
V_46 -> V_69 ) ;
F_3 ( V_58 L_201
L_202 , V_6 -> V_35 , V_46 -> V_27 ,
( unsigned long long ) V_46 -> V_9 ) ;
F_23 ( V_6 , F_3 ( V_58 L_203
L_109 , V_6 -> V_35 , V_36 ,
V_46 -> V_27 , ( unsigned long long )
V_46 -> V_9 ) ) ;
F_20 ( V_46 ) ;
}
static void
F_230 ( struct V_5 * V_6 , T_4 V_27 )
{
struct V_45 * V_46 ;
unsigned long V_65 ;
if ( V_6 -> V_316 )
return;
F_18 ( & V_6 -> V_66 , V_65 ) ;
V_46 = F_16 ( V_6 , V_27 ) ;
if ( V_46 )
F_19 ( & V_46 -> V_67 ) ;
F_21 ( & V_6 -> V_66 , V_65 ) ;
if ( V_46 )
F_229 ( V_6 , V_46 ) ;
}
void
F_231 ( struct V_5 * V_6 ,
T_1 V_9 )
{
struct V_45 * V_46 ;
unsigned long V_65 ;
if ( V_6 -> V_316 )
return;
F_18 ( & V_6 -> V_66 , V_65 ) ;
V_46 = F_15 ( V_6 ,
V_9 ) ;
if ( V_46 )
F_19 ( & V_46 -> V_67 ) ;
F_21 ( & V_6 -> V_66 , V_65 ) ;
if ( V_46 )
F_229 ( V_6 , V_46 ) ;
}
static void
F_232 ( struct V_5 * V_6 ,
T_22 * V_359 )
{
int V_92 ;
T_4 V_27 ;
T_4 V_376 ;
T_6 V_377 ;
char * V_650 = NULL ;
T_6 V_590 , V_651 ;
switch ( V_359 -> V_403 ) {
case V_410 :
V_650 = L_204 ;
break;
case V_407 :
V_650 = L_205 ;
break;
case V_406 :
case 0 :
V_650 = L_206 ;
break;
case V_404 :
V_650 = L_207 ;
break;
default:
V_650 = L_208 ;
break;
}
F_3 ( V_58 L_209 ,
V_6 -> V_35 , V_650 ) ;
F_3 ( V_7 L_210
L_211 ,
F_9 ( V_359 -> V_402 ) ,
F_9 ( V_359 -> V_611 ) ,
V_359 -> V_381 , V_359 -> V_378 ) ;
for ( V_92 = 0 ; V_92 < V_359 -> V_378 ; V_92 ++ ) {
V_27 = F_9 ( V_359 -> V_379 [ V_92 ] . V_380 ) ;
if ( ! V_27 )
continue;
V_377 = V_359 -> V_381 + V_92 ;
V_376 = V_359 -> V_379 [ V_92 ] . V_382 &
V_383 ;
switch ( V_376 ) {
case V_652 :
V_650 = L_212 ;
break;
case V_401 :
V_650 = L_213 ;
break;
case V_384 :
V_650 = L_214 ;
break;
case V_653 :
V_650 = L_215 ;
break;
case V_654 :
V_650 = L_216 ;
break;
default:
V_650 = L_64 ;
break;
}
V_590 = V_359 -> V_379 [ V_92 ] . V_655 >> 4 ;
V_651 = V_359 -> V_379 [ V_92 ] . V_655 & 0xF ;
F_3 ( V_7 L_217
L_218 , V_377 ,
V_27 , V_650 , V_590 , V_651 ) ;
}
}
static void
F_233 ( struct V_5 * V_6 ,
struct V_352 * V_353 )
{
int V_92 ;
T_4 V_615 , V_27 ;
T_4 V_376 ;
T_6 V_377 , V_656 ;
struct V_78 * V_79 ;
T_1 V_9 ;
unsigned long V_65 ;
T_6 V_590 , V_651 ;
T_22 * V_359 = V_353 -> V_359 ;
#ifdef F_208
if ( V_6 -> V_8 & V_657 )
F_232 ( V_6 , V_359 ) ;
#endif
if ( V_6 -> V_317 || V_6 -> V_318 )
return;
if ( ! V_6 -> V_31 . V_32 )
F_212 ( V_6 ) ;
else
F_209 ( V_6 ) ;
if ( V_353 -> V_409 ) {
F_23 ( V_6 , F_3 ( V_58 L_219
L_220 , V_6 -> V_35 ) ) ;
return;
}
V_615 = F_9 ( V_359 -> V_402 ) ;
if ( V_359 -> V_403 == V_410 )
if ( F_219 ( V_6 , V_615 ) != 0 )
return;
F_18 ( & V_6 -> V_80 , V_65 ) ;
V_79 = F_33 ( V_6 ,
V_615 ) ;
if ( V_79 ) {
V_9 = V_79 -> V_9 ;
V_656 = V_79 -> V_32 ;
} else if ( V_615 < V_6 -> V_31 . V_32 ) {
V_9 = V_6 -> V_31 . V_9 ;
V_656 = V_6 -> V_31 . V_32 ;
} else {
F_21 ( & V_6 -> V_80 , V_65 ) ;
return;
}
F_21 ( & V_6 -> V_80 , V_65 ) ;
for ( V_92 = 0 ; V_92 < V_359 -> V_378 ; V_92 ++ ) {
if ( V_353 -> V_409 ) {
F_23 ( V_6 , F_3 ( V_58 L_221
L_222 , V_6 -> V_35 ) ) ;
return;
}
if ( V_6 -> V_316 || V_6 -> V_317 ||
V_6 -> V_318 )
return;
V_377 = V_359 -> V_381 + V_92 ;
if ( V_377 >= V_656 )
continue;
V_376 = V_359 -> V_379 [ V_92 ] . V_382 &
V_383 ;
if ( ( V_359 -> V_379 [ V_92 ] . V_382 &
V_658 ) && ( V_376 !=
V_401 ) )
continue;
V_27 = F_9 ( V_359 -> V_379 [ V_92 ] . V_380 ) ;
if ( ! V_27 )
continue;
V_590 = V_359 -> V_379 [ V_92 ] . V_655 >> 4 ;
V_651 = V_359 -> V_379 [ V_92 ] . V_655 & 0xF ;
switch ( V_376 ) {
case V_653 :
if ( V_6 -> V_316 )
break;
if ( V_590 == V_651 )
break;
F_211 ( V_6 , V_9 ,
V_27 , V_377 , V_590 ) ;
if ( V_590 < V_595 )
break;
F_227 ( V_6 , V_27 ) ;
break;
case V_652 :
if ( V_6 -> V_316 )
break;
F_211 ( V_6 , V_9 ,
V_27 , V_377 , V_590 ) ;
F_228 ( V_6 , V_27 , V_377 , 0 ) ;
break;
case V_401 :
F_230 ( V_6 , V_27 ) ;
break;
}
}
if ( V_359 -> V_403 == V_407 &&
V_79 )
F_224 ( V_6 , V_9 ) ;
}
static void
F_234 ( struct V_5 * V_6 ,
T_32 * V_359 )
{
char * V_659 = NULL ;
switch ( V_359 -> V_416 ) {
case V_570 :
V_659 = L_223 ;
break;
case V_660 :
V_659 = L_224 ;
break;
case V_661 :
V_659 = L_225 ;
break;
case V_662 :
V_659 = L_226 ;
break;
case V_663 :
V_659 = L_227 ;
break;
case V_664 :
V_659 = L_228 ;
break;
case V_665 :
V_659 = L_229 ;
break;
case V_666 :
V_659 = L_230 ;
break;
case V_667 :
V_659 = L_231 ;
break;
case V_668 :
V_659 = L_232 ;
break;
case V_669 :
V_659 = L_233 ;
break;
case V_670 :
V_659 = L_234 ;
break;
case V_671 :
V_659 = L_235 ;
break;
default:
V_659 = L_236 ;
break;
}
F_3 ( V_58 L_237
L_238 ,
V_6 -> V_35 , V_659 , F_9 ( V_359 -> V_233 ) ,
( unsigned long long ) F_6 ( V_359 -> V_11 ) ,
F_9 ( V_359 -> V_548 ) ) ;
if ( V_359 -> V_416 == V_570 )
F_3 ( V_58 L_239 , V_6 -> V_35 ,
V_359 -> V_571 , V_359 -> V_672 ) ;
F_3 ( V_7 L_240 ) ;
}
static void
F_235 ( struct V_5 * V_6 ,
struct V_352 * V_353 )
{
struct V_147 * V_673 ;
struct V_45 * V_46 ;
T_1 V_9 ;
unsigned long V_65 ;
T_32 * V_359 =
V_353 -> V_359 ;
#ifdef F_208
if ( V_6 -> V_8 & V_657 )
F_234 ( V_6 ,
V_359 ) ;
#endif
if ( ( V_6 -> V_257 . V_674 >> 8 ) < 0xC )
return;
if ( V_359 -> V_416 !=
V_661 &&
V_359 -> V_416 !=
V_667 )
return;
F_18 ( & V_6 -> V_66 , V_65 ) ;
V_9 = F_6 ( V_359 -> V_11 ) ;
V_46 = F_15 ( V_6 ,
V_9 ) ;
if ( ! V_46 || ! V_46 -> V_70 ) {
F_21 ( & V_6 -> V_66 , V_65 ) ;
return;
}
V_673 = V_46 -> V_70 -> V_150 ;
if ( ! V_673 ) {
F_21 ( & V_6 -> V_66 , V_65 ) ;
return;
}
if ( V_359 -> V_416 ==
V_661 )
V_673 -> V_303 = 1 ;
else
V_673 -> V_303 = 0 ;
F_21 ( & V_6 -> V_66 , V_65 ) ;
}
static void
F_236 ( struct V_5 * V_6 ,
T_41 * V_359 )
{
char * V_659 = NULL ;
switch ( V_359 -> V_416 ) {
case V_675 :
V_659 = L_241 ;
break;
case V_676 :
V_659 = L_242 ;
break;
default:
V_659 = L_236 ;
break;
}
F_3 ( V_58 L_243
L_244
L_245 , V_6 -> V_35 , V_659 ,
F_9 ( V_359 -> V_611 ) ,
( unsigned long long ) F_6 ( V_359 -> V_16 ) ,
F_9 ( V_359 -> V_677 ) ) ;
}
static void
F_237 ( struct V_5 * V_6 ,
struct V_352 * V_353 )
{
#ifdef F_208
if ( V_6 -> V_8 & V_657 )
F_236 ( V_6 ,
V_353 -> V_359 ) ;
#endif
}
static void
F_238 ( struct V_5 * V_6 ,
struct V_352 * V_353 )
{
struct V_87 * V_90 ;
struct V_138 * V_139 ;
T_4 V_88 , V_27 ;
T_10 V_95 ;
struct V_145 * V_146 ;
T_10 V_678 ;
T_10 V_679 ;
T_21 * V_29 ;
T_42 * V_359 = V_353 -> V_359 ;
T_4 V_30 ;
unsigned long V_65 ;
int V_74 ;
T_6 V_680 = 0 ;
T_6 V_681 ;
F_112 ( & V_6 -> V_294 . V_313 ) ;
F_239 ( V_682
L_246 ,
V_6 -> V_35 , V_36 , V_359 -> V_647 ,
V_359 -> V_683 ) ;
F_147 ( V_6 ) ;
F_18 ( & V_6 -> V_91 , V_65 ) ;
V_29 = V_6 -> V_294 . V_293 ;
V_684:
if ( V_680 ++ == 5 ) {
F_23 ( V_6 , F_3 ( V_58 L_247 ,
V_6 -> V_35 , V_36 ) ) ;
goto V_75;
} else if ( V_680 > 1 )
F_23 ( V_6 , F_3 ( V_58 L_248 ,
V_6 -> V_35 , V_36 , V_680 - 1 ) ) ;
V_678 = 0 ;
V_679 = 0 ;
for ( V_88 = 1 ; V_88 <= V_6 -> V_93 ; V_88 ++ ) {
if ( V_6 -> V_316 )
goto V_75;
V_90 = F_37 ( V_6 , V_88 ) ;
if ( ! V_90 )
continue;
V_139 = V_90 -> V_43 ;
V_146 = V_139 -> V_150 ;
if ( ! V_146 || ! V_146 -> V_152 )
continue;
if ( V_146 -> V_152 -> V_65 &
V_179 )
continue;
if ( V_146 -> V_152 -> V_65 &
V_153 )
continue;
V_27 = V_146 -> V_152 -> V_27 ;
V_95 = V_146 -> V_95 ;
V_679 ++ ;
if ( V_6 -> V_316 )
goto V_75;
F_21 ( & V_6 -> V_91 , V_65 ) ;
V_74 = F_111 ( V_6 , V_27 , 0 , 0 , V_95 ,
V_343 , V_88 , 30 ,
V_685 ) ;
if ( V_74 == V_314 ) {
F_51 ( V_561 , V_139 ,
L_249
L_250 , V_90 ) ;
F_18 ( & V_6 -> V_91 , V_65 ) ;
goto V_684;
}
V_30 = F_9 ( V_29 -> V_38 )
& V_39 ;
if ( V_30 != V_40 ) {
F_51 ( V_561 , V_139 , L_251
L_252 , V_30 ,
V_90 ) ;
F_18 ( & V_6 -> V_91 , V_65 ) ;
goto V_684;
}
if ( V_29 -> V_339 ==
V_289 ||
V_29 -> V_339 ==
V_291 ) {
F_18 ( & V_6 -> V_91 , V_65 ) ;
continue;
}
V_681 = 0 ;
V_686:
if ( V_681 ++ == 60 ) {
F_23 ( V_6 , F_3 ( V_58
L_253 , V_6 -> V_35 ,
V_36 ) ) ;
F_18 ( & V_6 -> V_91 , V_65 ) ;
goto V_684;
}
if ( V_6 -> V_316 )
goto V_687;
V_74 = F_111 ( V_6 , V_27 , V_139 -> V_73 , V_139 -> V_72 ,
V_139 -> V_95 , V_327 , V_88 , 30 ,
V_685 ) ;
if ( V_74 == V_314 ) {
F_51 ( V_561 , V_139 ,
L_254
L_84 , V_90 ) ;
goto V_686;
}
if ( V_681 > 1 )
F_51 ( V_561 , V_139 ,
L_255
L_256 ,
V_681 - 1 , V_90 ) ;
V_678 += F_76 ( V_29 -> V_337 ) ;
F_18 ( & V_6 -> V_91 , V_65 ) ;
}
if ( V_6 -> V_688 ) {
F_23 ( V_6 , F_3 ( V_58 L_257
L_258 , V_6 -> V_35 , V_36 ) ) ;
V_6 -> V_688 = 0 ;
goto V_684;
}
V_75:
F_21 ( & V_6 -> V_91 , V_65 ) ;
V_687:
F_23 ( V_6 , F_3 ( V_58
L_259 ,
V_6 -> V_35 , V_36 , V_679 , V_678 ) ) ;
V_6 -> V_689 = 0 ;
if ( ! V_6 -> V_316 )
F_144 ( V_6 ) ;
F_125 ( & V_6 -> V_294 . V_313 ) ;
}
static void
F_240 ( struct V_5 * V_6 ,
struct V_352 * V_353 )
{
T_43 * V_359 = V_353 -> V_359 ;
#ifdef F_208
if ( V_6 -> V_8 & V_657 ) {
F_3 ( V_58 L_260 , V_6 -> V_35 ,
( V_359 -> V_416 == V_690 ) ?
L_261 : L_262 ) ;
if ( V_359 -> V_691 )
F_3 ( L_263 ,
F_76 ( V_359 -> V_691 ) ) ;
F_3 ( L_240 ) ;
}
#endif
if ( V_359 -> V_416 == V_690 &&
! V_6 -> V_31 . V_32 ) {
if ( V_692 > 0 && V_6 -> V_316 ) {
while ( V_6 -> V_316 )
F_241 ( 1 ) ;
}
F_212 ( V_6 ) ;
}
}
static void
F_242 ( struct V_138 * V_139 , void * V_182 )
{
int V_20 ;
V_139 -> V_182 = V_182 ? 1 : 0 ;
F_51 ( V_7 , V_139 , L_264 ,
V_139 -> V_182 ? L_265 : L_266 ) ;
V_20 = F_243 ( V_139 ) ;
}
static void
F_244 ( struct V_5 * V_6 ,
T_26 * V_413 )
{
struct V_47 * V_48 ;
unsigned long V_65 ;
T_1 V_52 ;
T_4 V_27 = F_9 ( V_413 -> V_419 ) ;
int V_20 ;
F_99 ( V_6 , V_27 , & V_52 ) ;
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
V_48 = F_69 ( sizeof( struct V_47 ) , V_172 ) ;
if ( ! V_48 ) {
F_3 ( V_34
L_2 , V_6 -> V_35 ,
__FILE__ , __LINE__ , V_36 ) ;
return;
}
V_48 -> V_72 = V_6 -> V_693 ++ ;
V_48 -> V_73 = V_174 ;
V_48 -> V_27 = V_27 ;
V_48 -> V_52 = V_52 ;
F_31 ( V_6 , V_48 ) ;
if ( ! V_6 -> V_648 ) {
V_20 = F_245 ( V_6 -> V_142 , V_174 ,
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
F_246 ( struct V_5 * V_6 , T_4 V_27 )
{
struct V_47 * V_48 ;
unsigned long V_65 ;
struct V_147 * V_148 ;
struct V_168 * V_70 = NULL ;
F_18 ( & V_6 -> V_76 , V_65 ) ;
V_48 = F_29 ( V_6 , V_27 ) ;
if ( V_48 ) {
if ( V_48 -> V_70 ) {
V_70 = V_48 -> V_70 ;
V_148 = V_70 -> V_150 ;
V_148 -> V_388 = 1 ;
}
F_3 ( V_58 L_267
L_202 , V_6 -> V_35 , V_48 -> V_27 ,
( unsigned long long ) V_48 -> V_52 ) ;
F_19 ( & V_48 -> V_67 ) ;
F_20 ( V_48 ) ;
}
F_21 ( & V_6 -> V_76 , V_65 ) ;
if ( V_70 )
F_247 ( & V_70 -> V_169 ) ;
}
static void
F_248 ( struct V_5 * V_6 ,
T_26 * V_413 )
{
struct V_45 * V_46 ;
struct V_168 * V_70 = NULL ;
struct V_147 * V_148 ;
unsigned long V_65 ;
T_4 V_27 = F_9 ( V_413 -> V_422 ) ;
F_18 ( & V_6 -> V_66 , V_65 ) ;
V_46 = F_16 ( V_6 , V_27 ) ;
if ( V_46 ) {
V_46 -> V_263 = 0 ;
V_46 -> V_264 = 0 ;
F_170 ( V_27 , V_6 -> V_178 ) ;
if ( V_46 -> V_70 && V_46 -> V_70 -> V_150 ) {
V_70 = V_46 -> V_70 ;
V_148 = V_70 -> V_150 ;
V_148 -> V_65 &=
~ V_179 ;
}
}
F_21 ( & V_6 -> V_66 , V_65 ) ;
if ( ! V_46 )
return;
if ( V_70 )
F_249 ( V_70 , NULL , F_242 ) ;
}
static void
F_250 ( struct V_5 * V_6 ,
T_26 * V_413 )
{
struct V_45 * V_46 ;
struct V_168 * V_70 = NULL ;
struct V_147 * V_148 ;
unsigned long V_65 ;
T_4 V_27 = F_9 ( V_413 -> V_422 ) ;
T_4 V_263 = 0 ;
T_1 V_264 = 0 ;
F_98 ( V_6 , V_27 , & V_263 ) ;
if ( V_263 )
F_99 ( V_6 , V_263 ,
& V_264 ) ;
F_18 ( & V_6 -> V_66 , V_65 ) ;
V_46 = F_16 ( V_6 , V_27 ) ;
if ( V_46 ) {
F_151 ( V_27 , V_6 -> V_178 ) ;
if ( V_46 -> V_70 && V_46 -> V_70 -> V_150 ) {
V_70 = V_46 -> V_70 ;
V_148 = V_70 -> V_150 ;
V_148 -> V_65 |=
V_179 ;
V_46 -> V_263 = V_263 ;
V_46 -> V_264 = V_264 ;
}
}
F_21 ( & V_6 -> V_66 , V_65 ) ;
if ( ! V_46 )
return;
if ( V_70 )
F_249 ( V_70 , ( void * ) 1 , F_242 ) ;
}
static void
F_251 ( struct V_5 * V_6 ,
T_26 * V_413 )
{
T_4 V_27 = F_9 ( V_413 -> V_422 ) ;
F_230 ( V_6 , V_27 ) ;
}
static void
F_252 ( struct V_5 * V_6 ,
T_26 * V_413 )
{
struct V_45 * V_46 ;
unsigned long V_65 ;
T_4 V_27 = F_9 ( V_413 -> V_422 ) ;
T_9 V_29 ;
T_8 V_28 ;
T_10 V_30 ;
T_1 V_9 ;
T_4 V_615 ;
F_151 ( V_27 , V_6 -> V_178 ) ;
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
V_615 = F_9 ( V_28 . V_617 ) ;
if ( ! F_11 ( V_6 , V_615 , & V_9 ) )
F_211 ( V_6 , V_9 , V_27 ,
V_28 . V_647 , V_595 ) ;
F_228 ( V_6 , V_27 , 0 , 1 ) ;
}
static void
F_253 ( struct V_5 * V_6 ,
T_25 * V_359 )
{
T_26 * V_413 ;
T_6 V_694 ;
int V_92 ;
char * V_659 = NULL , * V_695 = NULL ;
V_413 = ( T_26 * ) & V_359 -> V_414 [ 0 ] ;
F_3 ( V_58 L_268 ,
V_6 -> V_35 , ( F_76 ( V_359 -> V_183 ) &
V_420 ) ?
L_269 : L_270 , V_359 -> V_415 ) ;
for ( V_92 = 0 ; V_92 < V_359 -> V_415 ; V_92 ++ , V_413 ++ ) {
switch ( V_413 -> V_416 ) {
case V_696 :
V_659 = L_204 ;
break;
case V_418 :
V_659 = L_205 ;
break;
case V_697 :
V_659 = L_271 ;
break;
case V_698 :
V_659 = L_272 ;
break;
case V_421 :
V_659 = L_273 ;
break;
case V_699 :
V_659 = L_274 ;
break;
case V_417 :
V_659 = L_275 ;
break;
case V_700 :
V_659 = L_276 ;
break;
case V_701 :
V_659 = L_277 ;
break;
default:
V_659 = L_236 ;
break;
}
V_694 = F_9 ( V_413 -> V_702 ) &
V_703 ;
switch ( V_694 ) {
case V_704 :
V_695 = L_77 ;
break;
case V_705 :
V_695 = L_278 ;
break;
case V_706 :
V_695 = L_279 ;
break;
default:
V_695 = L_280 ;
break;
}
F_3 ( V_7 L_281
L_282 , V_695 ,
V_659 , F_9 ( V_413 -> V_419 ) ,
F_9 ( V_413 -> V_422 ) ,
V_413 -> V_232 ) ;
}
}
static void
F_254 ( struct V_5 * V_6 ,
struct V_352 * V_353 )
{
T_26 * V_413 ;
int V_92 ;
T_6 V_707 ;
T_25 * V_359 = V_353 -> V_359 ;
#ifdef F_208
if ( ( V_6 -> V_8 & V_657 )
&& ! V_6 -> V_273 )
F_253 ( V_6 , V_359 ) ;
#endif
if ( V_6 -> V_316 )
return;
V_707 = ( F_76 ( V_359 -> V_183 ) &
V_420 ) ? 1 : 0 ;
V_413 = ( T_26 * ) & V_359 -> V_414 [ 0 ] ;
for ( V_92 = 0 ; V_92 < V_359 -> V_415 ; V_92 ++ , V_413 ++ ) {
switch ( V_413 -> V_416 ) {
case V_699 :
case V_696 :
if ( ! V_707 )
F_244 ( V_6 , V_413 ) ;
break;
case V_417 :
case V_418 :
if ( ! V_707 )
F_246 ( V_6 ,
F_9 ( V_413 -> V_419 ) ) ;
break;
case V_700 :
if ( ! V_6 -> V_175 )
F_250 ( V_6 , V_413 ) ;
break;
case V_701 :
if ( ! V_6 -> V_175 )
F_248 ( V_6 , V_413 ) ;
break;
case V_698 :
if ( ! V_6 -> V_175 )
F_252 ( V_6 , V_413 ) ;
break;
case V_421 :
if ( ! V_6 -> V_175 )
F_251 ( V_6 , V_413 ) ;
break;
}
}
}
static void
F_255 ( struct V_5 * V_6 ,
struct V_352 * V_353 )
{
T_1 V_52 ;
unsigned long V_65 ;
struct V_47 * V_48 ;
T_4 V_27 ;
T_10 V_200 ;
int V_20 ;
T_27 * V_359 = V_353 -> V_359 ;
if ( V_6 -> V_316 )
return;
if ( V_359 -> V_416 != V_423 )
return;
V_27 = F_9 ( V_359 -> V_419 ) ;
V_200 = F_76 ( V_359 -> V_424 ) ;
if ( ! V_6 -> V_273 )
F_23 ( V_6 , F_3 ( V_58 L_51
L_283 , V_6 -> V_35 , V_36 , V_27 ,
F_76 ( V_359 -> V_708 ) , V_200 ) ) ;
switch ( V_200 ) {
case V_210 :
case V_209 :
F_246 ( V_6 , V_27 ) ;
break;
case V_205 :
case V_207 :
case V_204 :
F_18 ( & V_6 -> V_76 , V_65 ) ;
V_48 = F_29 ( V_6 , V_27 ) ;
F_21 ( & V_6 -> V_76 , V_65 ) ;
if ( V_48 )
break;
F_99 ( V_6 , V_27 , & V_52 ) ;
if ( ! V_52 ) {
F_3 ( V_34
L_2 , V_6 -> V_35 ,
__FILE__ , __LINE__ , V_36 ) ;
break;
}
V_48 = F_69 ( sizeof( struct V_47 ) , V_172 ) ;
if ( ! V_48 ) {
F_3 ( V_34
L_2 , V_6 -> V_35 ,
__FILE__ , __LINE__ , V_36 ) ;
break;
}
V_48 -> V_72 = V_6 -> V_693 ++ ;
V_48 -> V_73 = V_174 ;
V_48 -> V_27 = V_27 ;
V_48 -> V_52 = V_52 ;
F_31 ( V_6 , V_48 ) ;
V_20 = F_245 ( V_6 -> V_142 , V_174 ,
V_48 -> V_72 , 0 ) ;
if ( V_20 )
F_32 ( V_6 , V_48 ) ;
break;
case V_709 :
default:
break;
}
}
static void
F_256 ( struct V_5 * V_6 ,
struct V_352 * V_353 )
{
T_4 V_27 , V_615 ;
T_10 V_200 ;
struct V_45 * V_46 ;
unsigned long V_65 ;
T_9 V_29 ;
T_8 V_28 ;
T_10 V_30 ;
T_44 * V_359 = V_353 -> V_359 ;
T_1 V_9 ;
if ( V_6 -> V_316 )
return;
if ( V_359 -> V_416 != V_710 )
return;
V_27 = F_9 ( V_359 -> V_422 ) ;
V_200 = F_76 ( V_359 -> V_424 ) ;
if ( ! V_6 -> V_273 )
F_23 ( V_6 , F_3 ( V_58 L_51
L_283 , V_6 -> V_35 , V_36 , V_27 ,
F_76 ( V_359 -> V_708 ) , V_200 ) ) ;
switch ( V_200 ) {
case V_711 :
case V_712 :
case V_713 :
case V_714 :
case V_715 :
if ( ! V_6 -> V_175 )
F_151 ( V_27 , V_6 -> V_178 ) ;
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
V_615 = F_9 ( V_28 . V_617 ) ;
if ( ! F_11 ( V_6 , V_615 , & V_9 ) )
F_211 ( V_6 , V_9 , V_27 ,
V_28 . V_647 , V_595 ) ;
F_228 ( V_6 , V_27 , 0 , 1 ) ;
break;
case V_716 :
case V_717 :
case V_718 :
default:
break;
}
}
static void
F_257 ( struct V_5 * V_6 ,
T_45 * V_359 )
{
char * V_659 = NULL ;
switch ( V_359 -> V_719 ) {
case V_720 :
V_659 = L_284 ;
break;
case V_721 :
V_659 = L_285 ;
break;
case V_722 :
V_659 = L_286 ;
break;
case V_723 :
V_659 = L_287 ;
break;
case V_724 :
V_659 = L_288 ;
break;
}
if ( ! V_659 )
return;
F_3 ( V_58 L_289
L_290 ,
V_6 -> V_35 , V_659 ,
F_9 ( V_359 -> V_419 ) ,
V_359 -> V_725 ) ;
}
static void
F_258 ( struct V_5 * V_6 ,
struct V_352 * V_353 )
{
T_45 * V_359 = V_353 -> V_359 ;
static struct V_47 * V_48 ;
unsigned long V_65 ;
T_4 V_27 ;
#ifdef F_208
if ( ( V_6 -> V_8 & V_657 )
&& ! V_6 -> V_273 )
F_257 ( V_6 ,
V_359 ) ;
#endif
if ( V_359 -> V_719 == V_720 ) {
F_18 ( & V_6 -> V_76 , V_65 ) ;
V_27 = F_9 ( V_359 -> V_419 ) ;
V_48 = F_29 ( V_6 , V_27 ) ;
if ( V_48 )
V_48 -> V_193 =
V_359 -> V_725 ;
F_21 ( & V_6 -> V_76 , V_65 ) ;
}
}
static void
F_259 ( struct V_5 * V_6 )
{
struct V_145 * V_146 ;
struct V_138 * V_139 ;
F_109 (sdev, ioc->shost) {
V_146 = V_139 -> V_150 ;
if ( V_146 && V_146 -> V_152 )
V_146 -> V_152 -> V_388 = 1 ;
}
}
static void
F_260 ( struct V_5 * V_6 , T_1 V_9 ,
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
V_46 -> V_726 = 1 ;
V_70 = V_46 -> V_70 ;
if ( V_70 && V_70 -> V_150 ) {
V_148 = V_70 -> V_150 ;
V_148 -> V_303 = 0 ;
V_148 -> V_388 = 0 ;
} else
V_148 = NULL ;
if ( V_70 )
F_128 ( V_7 , V_70 ,
L_291
L_292
L_293 , V_27 ,
( unsigned long long ) V_46 -> V_9 ,
( unsigned long long )
V_46 -> V_14 ,
V_46 -> V_18 ) ;
if ( V_46 -> V_27 == V_27 )
goto V_75;
F_3 ( V_7 L_294 ,
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
F_261 ( struct V_5 * V_6 )
{
T_8 V_28 ;
T_9 V_29 ;
T_4 V_30 ;
T_40 V_9 ;
T_4 V_27 ;
T_10 V_82 ;
T_4 V_18 ;
F_3 ( V_58 L_295 , V_6 -> V_35 ) ;
if ( F_43 ( & V_6 -> V_68 ) )
goto V_75;
V_27 = 0xFFFF ;
while ( ! ( F_12 ( V_6 , & V_29 ,
& V_28 , V_727 ,
V_27 ) ) ) {
V_30 = F_9 ( V_29 . V_38 ) &
V_39 ;
if ( V_30 != V_40 )
break;
V_27 = F_9 ( V_28 . V_233 ) ;
V_82 = F_76 ( V_28 . V_184 ) ;
if ( ! ( F_36 ( V_82 ) ) )
continue;
V_9 = F_6 ( V_28 . V_11 ) ;
V_18 = F_9 ( V_28 . V_646 ) ;
F_260 ( V_6 , V_9 , V_18 ,
V_27 ) ;
}
V_75:
F_3 ( V_58 L_296 ,
V_6 -> V_35 ) ;
}
static void
F_262 ( struct V_5 * V_6 , T_1 V_52 ,
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
V_148 -> V_388 = 0 ;
} else
V_148 = NULL ;
V_48 -> V_726 = 1 ;
F_21 ( & V_6 -> V_76 , V_65 ) ;
F_128 ( V_7 , V_48 -> V_70 ,
L_297 , V_27 ,
( unsigned long long ) V_48 -> V_52 ) ;
F_92 ( V_6 , V_48 ) ;
F_18 ( & V_6 -> V_76 , V_65 ) ;
if ( V_48 -> V_27 == V_27 ) {
F_21 ( & V_6 -> V_76 ,
V_65 ) ;
return;
}
F_3 ( V_7 L_294 ,
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
F_263 ( struct V_5 * V_6 )
{
T_15 V_728 ;
T_13 V_729 ;
T_14 V_225 ;
T_9 V_29 ;
T_4 V_30 ;
T_4 V_27 ;
T_6 V_730 ;
if ( ! V_6 -> V_731 )
return;
F_3 ( V_58 L_298 ,
V_6 -> V_35 ) ;
if ( F_43 ( & V_6 -> V_77 ) )
goto V_75;
V_27 = 0xFFFF ;
while ( ! ( F_90 ( V_6 , & V_29 ,
& V_728 , V_235 , V_27 ) ) ) {
V_30 = F_9 ( V_29 . V_38 ) &
V_39 ;
if ( V_30 != V_40 )
break;
V_27 = F_9 ( V_728 . V_233 ) ;
if ( F_80 ( V_6 , & V_29 ,
& V_729 , V_194 , V_27 ,
sizeof( T_13 ) ) )
continue;
if ( V_729 . V_203 == V_204 ||
V_729 . V_203 == V_205 ||
V_729 . V_203 == V_207 )
F_262 ( V_6 ,
F_6 ( V_728 . V_732 ) , V_27 ) ;
}
if ( ! V_6 -> V_175 ) {
V_730 = 0xFF ;
memset ( V_6 -> V_178 , 0 , V_6 -> V_733 ) ;
while ( ! ( F_88 ( V_6 , & V_29 ,
& V_225 , V_734 ,
V_730 ) ) ) {
V_30 = F_9 ( V_29 . V_38 ) &
V_39 ;
if ( V_30 != V_40 )
break;
V_730 = V_225 . V_232 ;
V_27 = F_9 ( V_225 . V_233 ) ;
F_151 ( V_27 , V_6 -> V_178 ) ;
}
}
V_75:
F_3 ( V_58 L_299
L_300 , V_6 -> V_35 ) ;
}
static void
F_264 ( struct V_5 * V_6 , T_1 V_9 ,
T_4 V_27 )
{
struct V_78 * V_79 ;
unsigned long V_65 ;
int V_92 ;
F_18 ( & V_6 -> V_80 , V_65 ) ;
F_4 (sas_expander, &ioc->sas_expander_list, list) {
if ( V_79 -> V_9 != V_9 )
continue;
V_79 -> V_726 = 1 ;
if ( V_79 -> V_27 == V_27 )
goto V_75;
F_3 ( V_7 L_301
L_302 ,
( unsigned long long ) V_79 -> V_9 ,
V_79 -> V_27 , V_27 ) ;
V_79 -> V_27 = V_27 ;
for ( V_92 = 0 ; V_92 < V_79 -> V_32 ; V_92 ++ )
V_79 -> V_274 [ V_92 ] . V_27 = V_27 ;
goto V_75;
}
V_75:
F_21 ( & V_6 -> V_80 , V_65 ) ;
}
static void
F_265 ( struct V_5 * V_6 )
{
T_38 V_613 ;
T_9 V_29 ;
T_4 V_30 ;
T_1 V_9 ;
T_4 V_27 ;
F_3 ( V_58 L_303 , V_6 -> V_35 ) ;
if ( F_43 ( & V_6 -> V_81 ) )
goto V_75;
V_27 = 0xFFFF ;
while ( ! ( F_220 ( V_6 , & V_29 , & V_613 ,
V_735 , V_27 ) ) ) {
V_30 = F_9 ( V_29 . V_38 ) &
V_39 ;
if ( V_30 != V_40 )
break;
V_27 = F_9 ( V_613 . V_233 ) ;
V_9 = F_6 ( V_613 . V_11 ) ;
F_3 ( V_7 L_304
L_305 , V_27 ,
( unsigned long long ) V_9 ) ;
F_264 ( V_6 , V_9 , V_27 ) ;
}
V_75:
F_3 ( V_58 L_306 , V_6 -> V_35 ) ;
}
static void
F_266 ( struct V_5 * V_6 )
{
struct V_45 * V_46 , * V_736 ;
struct V_78 * V_79 , * V_737 ;
struct V_47 * V_48 , * V_738 ;
struct V_739 V_740 ;
unsigned long V_65 ;
F_3 ( V_58 L_307 ,
V_6 -> V_35 ) ;
F_3 ( V_58 L_308 ,
V_6 -> V_35 ) ;
F_142 (sas_device, sas_device_next,
&ioc->sas_device_list, list) {
if ( ! V_46 -> V_726 )
F_231 ( V_6 ,
V_46 -> V_9 ) ;
else
V_46 -> V_726 = 0 ;
}
if ( V_6 -> V_731 ) {
F_3 ( V_58 L_309
L_310 , V_6 -> V_35 ) ;
F_142 (raid_device, raid_device_next,
&ioc->raid_device_list, list) {
if ( ! V_48 -> V_726 )
F_246 ( V_6 ,
V_48 -> V_27 ) ;
else
V_48 -> V_726 = 0 ;
}
}
F_3 ( V_58 L_311 ,
V_6 -> V_35 ) ;
F_18 ( & V_6 -> V_80 , V_65 ) ;
F_154 ( & V_740 ) ;
F_142 (sas_expander, sas_expander_next,
&ioc->sas_expander_list, list) {
if ( ! V_79 -> V_726 )
F_267 ( & V_79 -> V_67 , & V_740 ) ;
else
V_79 -> V_726 = 0 ;
}
F_21 ( & V_6 -> V_80 , V_65 ) ;
F_142 (sas_expander, sas_expander_next, &tmp_list,
list) {
F_19 ( & V_79 -> V_67 ) ;
F_225 ( V_6 , V_79 ) ;
}
F_3 ( V_58 L_312 ,
V_6 -> V_35 ) ;
F_144 ( V_6 ) ;
}
static void
F_268 ( struct V_5 * V_6 ,
struct V_78 * V_79 , T_4 V_27 )
{
T_39 V_614 ;
T_9 V_29 ;
int V_92 ;
for ( V_92 = 0 ; V_92 < V_79 -> V_32 ; V_92 ++ ) {
if ( ( F_221 ( V_6 , & V_29 ,
& V_614 , V_92 , V_27 ) ) ) {
F_3 ( V_34 L_2 ,
V_6 -> V_35 , __FILE__ , __LINE__ , V_36 ) ;
return;
}
F_211 ( V_6 , V_79 -> V_9 ,
F_9 ( V_614 . V_380 ) , V_92 ,
V_614 . V_593 >> 4 ) ;
}
}
static void
F_269 ( struct V_5 * V_6 )
{
T_38 V_613 ;
T_8 V_28 ;
T_15 V_728 ;
T_13 V_729 ;
T_14 V_225 ;
T_26 V_413 ;
T_9 V_29 ;
T_6 V_730 ;
T_4 V_30 ;
T_4 V_27 , V_615 ;
T_1 V_9 ;
struct V_45 * V_46 ;
struct V_78 * V_741 ;
static struct V_47 * V_48 ;
T_6 V_742 ;
unsigned long V_65 ;
F_3 ( V_58 L_313 , V_6 -> V_35 ) ;
F_209 ( V_6 ) ;
F_3 ( V_58 L_314 ,
V_6 -> V_35 ) ;
V_27 = 0xFFFF ;
while ( ! ( F_220 ( V_6 , & V_29 , & V_613 ,
V_735 , V_27 ) ) ) {
V_30 = F_9 ( V_29 . V_38 ) &
V_39 ;
if ( V_30 != V_40 ) {
F_3 ( V_58 L_315
L_316 ,
V_6 -> V_35 , V_30 ,
F_76 ( V_29 . V_336 ) ) ;
break;
}
V_27 = F_9 ( V_613 . V_233 ) ;
F_18 ( & V_6 -> V_80 , V_65 ) ;
V_741 = F_34 (
V_6 , F_6 ( V_613 . V_11 ) ) ;
F_21 ( & V_6 -> V_80 , V_65 ) ;
if ( V_741 )
F_268 ( V_6 , V_741 ,
V_27 ) ;
else {
F_3 ( V_58 L_317
L_318 ,
V_6 -> V_35 , V_27 , ( unsigned long long )
F_6 ( V_613 . V_11 ) ) ;
F_219 ( V_6 , V_27 ) ;
F_3 ( V_58 L_319
L_318 ,
V_6 -> V_35 , V_27 , ( unsigned long long )
F_6 ( V_613 . V_11 ) ) ;
}
}
F_3 ( V_58 L_320 ,
V_6 -> V_35 ) ;
if ( ! V_6 -> V_731 )
goto V_743;
F_3 ( V_58 L_321 , V_6 -> V_35 ) ;
V_730 = 0xFF ;
while ( ! ( F_88 ( V_6 , & V_29 ,
& V_225 , V_734 ,
V_730 ) ) ) {
V_30 = F_9 ( V_29 . V_38 ) &
V_39 ;
if ( V_30 != V_40 ) {
F_3 ( V_58 L_322
L_316 ,
V_6 -> V_35 , V_30 ,
F_76 ( V_29 . V_336 ) ) ;
break;
}
V_730 = V_225 . V_232 ;
V_27 = F_9 ( V_225 . V_233 ) ;
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
F_3 ( V_58 L_323
L_316 ,
V_6 -> V_35 , V_30 ,
F_76 ( V_29 . V_336 ) ) ;
break;
}
V_615 = F_9 ( V_28 . V_617 ) ;
if ( ! F_11 ( V_6 , V_615 ,
& V_9 ) ) {
F_3 ( V_58 L_324
L_325 ,
V_6 -> V_35 , V_27 , ( unsigned long long )
F_6 ( V_28 . V_11 ) ) ;
F_211 ( V_6 , V_9 ,
V_27 , V_28 . V_647 ,
V_595 ) ;
F_151 ( V_27 , V_6 -> V_178 ) ;
V_742 = 0 ;
while ( F_228 ( V_6 , V_27 , V_742 ++ ,
1 ) ) {
F_241 ( 1 ) ;
}
F_3 ( V_58 L_326
L_325 ,
V_6 -> V_35 , V_27 , ( unsigned long long )
F_6 ( V_28 . V_11 ) ) ;
}
}
F_3 ( V_58 L_327 ,
V_6 -> V_35 ) ;
F_3 ( V_58 L_328 , V_6 -> V_35 ) ;
V_27 = 0xFFFF ;
while ( ! ( F_90 ( V_6 , & V_29 ,
& V_728 , V_235 , V_27 ) ) ) {
V_30 = F_9 ( V_29 . V_38 ) &
V_39 ;
if ( V_30 != V_40 ) {
F_3 ( V_58 L_329
L_316 ,
V_6 -> V_35 , V_30 ,
F_76 ( V_29 . V_336 ) ) ;
break;
}
V_27 = F_9 ( V_728 . V_233 ) ;
F_18 ( & V_6 -> V_76 , V_65 ) ;
V_48 = F_30 ( V_6 ,
F_6 ( V_728 . V_732 ) ) ;
F_21 ( & V_6 -> V_76 , V_65 ) ;
if ( V_48 )
continue;
if ( F_80 ( V_6 , & V_29 ,
& V_729 , V_194 , V_27 ,
sizeof( T_13 ) ) )
continue;
V_30 = F_9 ( V_29 . V_38 ) &
V_39 ;
if ( V_30 != V_40 ) {
F_3 ( V_58 L_329
L_316 ,
V_6 -> V_35 , V_30 ,
F_76 ( V_29 . V_336 ) ) ;
break;
}
if ( V_729 . V_203 == V_204 ||
V_729 . V_203 == V_205 ||
V_729 . V_203 == V_207 ) {
memset ( & V_413 , 0 , sizeof( T_26 ) ) ;
V_413 . V_416 = V_696 ;
V_413 . V_419 = V_728 . V_233 ;
F_3 ( V_58 L_330
L_331 , V_6 -> V_35 ,
V_728 . V_233 ) ;
F_244 ( V_6 , & V_413 ) ;
F_3 ( V_58 L_332
L_331 , V_6 -> V_35 ,
V_728 . V_233 ) ;
}
}
F_3 ( V_58 L_333 ,
V_6 -> V_35 ) ;
V_743:
F_3 ( V_58 L_334 ,
V_6 -> V_35 ) ;
V_27 = 0xFFFF ;
while ( ! ( F_12 ( V_6 , & V_29 ,
& V_28 , V_727 ,
V_27 ) ) ) {
V_30 = F_9 ( V_29 . V_38 ) &
V_39 ;
if ( V_30 != V_40 ) {
F_3 ( V_58 L_335
L_336 ,
V_6 -> V_35 , V_30 ,
F_76 ( V_29 . V_336 ) ) ;
break;
}
V_27 = F_9 ( V_28 . V_233 ) ;
if ( ! ( F_36 (
F_76 ( V_28 . V_184 ) ) ) )
continue;
F_18 ( & V_6 -> V_66 , V_65 ) ;
V_46 = F_15 ( V_6 ,
F_6 ( V_28 . V_11 ) ) ;
F_21 ( & V_6 -> V_66 , V_65 ) ;
if ( V_46 )
continue;
V_615 = F_9 ( V_28 . V_617 ) ;
if ( ! F_11 ( V_6 , V_615 , & V_9 ) ) {
F_3 ( V_58 L_337
L_318 ,
V_6 -> V_35 , V_27 , ( unsigned long long )
F_6 ( V_28 . V_11 ) ) ;
F_211 ( V_6 , V_9 , V_27 ,
V_28 . V_647 , V_595 ) ;
V_742 = 0 ;
while ( F_228 ( V_6 , V_27 , V_742 ++ ,
0 ) ) {
F_241 ( 1 ) ;
}
F_3 ( V_58 L_338
L_318 ,
V_6 -> V_35 , V_27 , ( unsigned long long )
F_6 ( V_28 . V_11 ) ) ;
}
}
F_3 ( V_58 L_339 ,
V_6 -> V_35 ) ;
F_3 ( V_58 L_340 , V_6 -> V_35 ) ;
}
void
F_270 ( struct V_5 * V_6 , int V_744 )
{
switch ( V_744 ) {
case V_745 :
F_118 ( V_6 , F_3 ( V_58 L_54
L_341 , V_6 -> V_35 , V_36 ) ) ;
break;
case V_746 :
F_118 ( V_6 , F_3 ( V_58 L_54
L_342 , V_6 -> V_35 , V_36 ) ) ;
if ( V_6 -> V_621 . V_295 & V_300 ) {
V_6 -> V_621 . V_295 |= V_335 ;
F_164 ( V_6 , V_6 -> V_621 . V_88 ) ;
F_107 ( & V_6 -> V_621 . V_301 ) ;
}
if ( V_6 -> V_294 . V_295 & V_300 ) {
V_6 -> V_294 . V_295 |= V_335 ;
F_164 ( V_6 , V_6 -> V_294 . V_88 ) ;
F_107 ( & V_6 -> V_294 . V_301 ) ;
}
F_140 ( V_6 ) ;
F_173 ( V_6 ) ;
break;
case V_747 :
F_118 ( V_6 , F_3 ( V_58 L_54
L_343 , V_6 -> V_35 , V_36 ) ) ;
F_209 ( V_6 ) ;
F_259 ( V_6 ) ;
F_261 ( V_6 ) ;
F_263 ( V_6 ) ;
F_265 ( V_6 ) ;
if ( ( ! V_6 -> V_49 ) && ! ( V_692 > 0 &&
! V_6 -> V_31 . V_32 ) ) {
F_259 ( V_6 ) ;
F_261 ( V_6 ) ;
F_263 ( V_6 ) ;
F_265 ( V_6 ) ;
F_138 ( V_6 ) ;
}
break;
}
}
static void
V_358 ( struct V_748 * V_749 )
{
struct V_352 * V_353 = F_271 ( V_749 ,
struct V_352 , V_357 . V_749 ) ;
struct V_5 * V_6 = V_353 -> V_6 ;
if ( V_6 -> V_317 || V_353 -> V_364 ||
V_6 -> V_318 ) {
F_137 ( V_6 , V_353 ) ;
return;
}
switch ( V_353 -> V_361 ) {
case V_362 :
while ( F_272 ( V_6 -> V_142 ) || V_6 -> V_316 )
F_241 ( 1 ) ;
F_266 ( V_6 ) ;
F_269 ( V_6 ) ;
break;
case V_363 :
V_6 -> V_750 = 0 ;
if ( V_751 [ 0 ] != - 1 && V_751 [ 1 ] != - 1 )
F_273 ( V_6 , V_751 [ 0 ] ,
V_751 [ 1 ] ) ;
F_23 ( V_6 , F_3 ( V_58 L_344
L_345 , V_6 -> V_35 ) ) ;
break;
case V_558 :
F_197 ( V_6 , V_353 -> V_559 ) ;
break;
case V_408 :
F_233 ( V_6 , V_353 ) ;
break;
case V_568 :
F_235 ( V_6 ,
V_353 ) ;
break;
case V_752 :
F_240 ( V_6 ,
V_353 ) ;
break;
case V_753 :
F_238 ( V_6 ,
V_353 ) ;
break;
case V_754 :
F_237 ( V_6 ,
V_353 ) ;
break;
case V_755 :
F_254 ( V_6 , V_353 ) ;
break;
case V_756 :
F_255 ( V_6 , V_353 ) ;
break;
case V_757 :
F_256 ( V_6 , V_353 ) ;
break;
case V_758 :
F_258 ( V_6 , V_353 ) ;
break;
}
F_137 ( V_6 , V_353 ) ;
}
void
F_274 ( struct V_5 * V_6 , T_6 V_292 ,
T_10 V_293 )
{
struct V_352 * V_353 ;
T_31 * V_29 ;
T_4 V_361 ;
T_4 V_226 ;
if ( V_6 -> V_317 || V_6 -> V_318 )
return;
V_29 = F_106 ( V_6 , V_293 ) ;
if ( F_159 ( ! V_29 ) ) {
F_3 ( V_34 L_115 ,
V_6 -> V_35 , __FILE__ , __LINE__ , V_36 ) ;
return;
}
V_361 = F_9 ( V_29 -> V_567 ) ;
switch ( V_361 ) {
case V_753 :
{
T_42 * V_759 =
( T_42 * )
V_29 -> V_565 ;
if ( V_759 -> V_760 !=
V_761 )
return;
if ( V_6 -> V_689 ) {
V_6 -> V_688 ++ ;
return;
} else
V_6 -> V_689 = 1 ;
break;
}
case V_408 :
F_165 ( V_6 ,
( T_22 * )
V_29 -> V_565 ) ;
break;
case V_755 :
F_169 ( V_6 ,
( T_25 * )
V_29 -> V_565 ) ;
break;
case V_756 :
F_172 ( V_6 ,
( T_27 * )
V_29 -> V_565 ) ;
break;
case V_762 :
{
T_46 * V_763 ;
T_47 * V_764 ;
if ( ! V_6 -> V_175 )
break;
V_763 = ( T_46 * )
V_29 -> V_565 ;
V_764 = ( T_47 * ) V_763 -> V_765 ;
if ( F_9 ( V_763 -> V_766 )
!= V_767 )
break;
switch ( F_76 ( * V_764 ) ) {
case V_768 :
F_3 ( V_99 L_346
L_347
L_348
L_349 , V_6 -> V_35 ) ;
break;
case V_769 :
F_3 ( V_99 L_346
L_350
L_351
L_352 , V_6 -> V_35 ) ;
break;
case V_770 :
F_3 ( V_34 L_353
L_354
L_355
L_356
L_352 , V_6 -> V_35 ) ;
break;
case V_771 :
F_3 ( V_34 L_353
L_357
L_358
L_359 ,
V_6 -> V_35 ) ;
break;
}
break;
}
case V_568 :
case V_758 :
case V_752 :
case V_754 :
case V_757 :
break;
default:
return;
}
V_353 = F_69 ( sizeof( struct V_352 ) , V_360 ) ;
if ( ! V_353 ) {
F_3 ( V_34 L_2 ,
V_6 -> V_35 , __FILE__ , __LINE__ , V_36 ) ;
return;
}
V_226 = F_9 ( V_29 -> V_569 ) * 4 ;
V_353 -> V_359 = F_69 ( V_226 , V_360 ) ;
if ( ! V_353 -> V_359 ) {
F_3 ( V_34 L_2 ,
V_6 -> V_35 , __FILE__ , __LINE__ , V_36 ) ;
F_20 ( V_353 ) ;
return;
}
memcpy ( V_353 -> V_359 , V_29 -> V_565 ,
V_226 ) ;
V_353 -> V_6 = V_6 ;
V_353 -> V_501 = V_29 -> V_501 ;
V_353 -> V_502 = V_29 -> V_502 ;
V_353 -> V_361 = V_361 ;
F_134 ( V_6 , V_353 ) ;
return;
}
static void
F_225 ( struct V_5 * V_6 ,
struct V_78 * V_79 )
{
struct V_367 * V_368 , * V_100 ;
F_142 (mpt2sas_port, next,
&sas_expander->sas_port_list, port_list) {
if ( V_6 -> V_316 )
return;
if ( V_368 -> V_370 . V_371 ==
V_372 )
F_231 ( V_6 ,
V_368 -> V_370 . V_9 ) ;
else if ( V_368 -> V_370 . V_371 ==
V_374 ||
V_368 -> V_370 . V_371 ==
V_375 )
F_224 ( V_6 ,
V_368 -> V_370 . V_9 ) ;
}
F_26 ( V_6 , V_79 -> V_9 ,
V_79 -> V_69 ) ;
F_3 ( V_58 L_360
L_8 , V_6 -> V_35 ,
V_79 -> V_27 , ( unsigned long long )
V_79 -> V_9 ) ;
F_20 ( V_79 -> V_274 ) ;
F_20 ( V_79 ) ;
}
static void
F_275 ( struct V_5 * V_6 )
{
T_48 * V_103 ;
T_49 * V_29 ;
T_4 V_88 ;
if ( ! V_6 -> V_731 )
return;
F_112 ( & V_6 -> V_621 . V_313 ) ;
if ( V_6 -> V_621 . V_295 != V_296 ) {
F_3 ( V_34 L_361 ,
V_6 -> V_35 , V_36 ) ;
goto V_75;
}
V_6 -> V_621 . V_295 = V_300 ;
V_88 = F_162 ( V_6 , V_6 -> V_772 ) ;
if ( ! V_88 ) {
F_3 ( V_34 L_70 ,
V_6 -> V_35 , V_36 ) ;
V_6 -> V_621 . V_295 = V_296 ;
goto V_75;
}
V_103 = F_48 ( V_6 , V_88 ) ;
V_6 -> V_621 . V_88 = V_88 ;
memset ( V_103 , 0 , sizeof( T_48 ) ) ;
V_103 -> V_328 = V_773 ;
V_103 -> V_553 = V_774 ;
if ( ! V_6 -> V_273 )
F_3 ( V_58 L_362 , V_6 -> V_35 ) ;
F_121 ( & V_6 -> V_621 . V_301 ) ;
F_163 ( V_6 , V_88 ) ;
F_123 ( & V_6 -> V_621 . V_301 , 10 * V_334 ) ;
if ( ! ( V_6 -> V_621 . V_295 & V_297 ) ) {
F_3 ( V_34 L_73 ,
V_6 -> V_35 , V_36 ) ;
goto V_75;
}
if ( V_6 -> V_621 . V_295 & V_299 ) {
V_29 = V_6 -> V_621 . V_293 ;
if ( ! V_6 -> V_273 )
F_3 ( V_58 L_363
L_316 ,
V_6 -> V_35 , F_9 ( V_29 -> V_38 ) ,
F_76 ( V_29 -> V_336 ) ) ;
}
V_75:
V_6 -> V_621 . V_295 = V_296 ;
F_125 ( & V_6 -> V_621 . V_313 ) ;
}
static void
F_276 ( struct V_775 * V_562 )
{
struct V_141 * V_142 = F_277 ( V_562 ) ;
struct V_5 * V_6 = F_58 ( V_142 ) ;
struct V_776 * V_777 ;
unsigned long V_65 ;
V_6 -> V_317 = 1 ;
F_140 ( V_6 ) ;
F_18 ( & V_6 -> V_355 , V_65 ) ;
V_777 = V_6 -> V_354 ;
V_6 -> V_354 = NULL ;
F_21 ( & V_6 -> V_355 , V_65 ) ;
if ( V_777 )
F_278 ( V_777 ) ;
F_275 ( V_6 ) ;
F_279 ( V_6 ) ;
}
static void
F_280 ( struct V_775 * V_562 )
{
struct V_141 * V_142 = F_277 ( V_562 ) ;
struct V_5 * V_6 = F_58 ( V_142 ) ;
struct V_367 * V_368 , * V_778 ;
struct V_47 * V_48 , * V_100 ;
struct V_147 * V_148 ;
struct V_776 * V_777 ;
unsigned long V_65 ;
V_6 -> V_317 = 1 ;
F_140 ( V_6 ) ;
F_18 ( & V_6 -> V_355 , V_65 ) ;
V_777 = V_6 -> V_354 ;
V_6 -> V_354 = NULL ;
F_21 ( & V_6 -> V_355 , V_65 ) ;
if ( V_777 )
F_278 ( V_777 ) ;
F_275 ( V_6 ) ;
F_142 (raid_device, next, &ioc->raid_device_list,
list) {
if ( V_48 -> V_70 ) {
V_148 =
V_48 -> V_70 -> V_150 ;
V_148 -> V_388 = 1 ;
F_247 ( & V_48 -> V_70 -> V_169 ) ;
}
F_3 ( V_58 L_267
L_202 , V_6 -> V_35 , V_48 -> V_27 ,
( unsigned long long ) V_48 -> V_52 ) ;
F_32 ( V_6 , V_48 ) ;
}
F_142 (mpt2sas_port, next_port,
&ioc->sas_hba.sas_port_list, port_list) {
if ( V_368 -> V_370 . V_371 ==
V_372 )
F_231 ( V_6 ,
V_368 -> V_370 . V_9 ) ;
else if ( V_368 -> V_370 . V_371 ==
V_374 ||
V_368 -> V_370 . V_371 ==
V_375 )
F_224 ( V_6 ,
V_368 -> V_370 . V_9 ) ;
}
if ( V_6 -> V_31 . V_32 ) {
F_20 ( V_6 -> V_31 . V_274 ) ;
V_6 -> V_31 . V_274 = NULL ;
V_6 -> V_31 . V_32 = 0 ;
}
F_281 ( V_142 ) ;
F_279 ( V_6 ) ;
F_19 ( & V_6 -> V_67 ) ;
F_282 ( V_142 ) ;
F_283 ( V_142 ) ;
}
static void
F_284 ( struct V_5 * V_6 )
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
V_20 = F_245 ( V_6 -> V_142 , V_174 ,
V_48 -> V_72 , 0 ) ;
if ( V_20 )
F_32 ( V_6 , V_48 ) ;
} else {
F_18 ( & V_6 -> V_66 , V_65 ) ;
V_46 = V_43 ;
V_27 = V_46 -> V_27 ;
V_69 = V_46 -> V_69 ;
V_9 = V_46 -> V_9 ;
F_267 ( & V_46 -> V_67 , & V_6 -> V_68 ) ;
F_21 ( & V_6 -> V_66 , V_65 ) ;
if ( V_6 -> V_649 )
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
F_285 ( struct V_5 * V_6 )
{
struct V_47 * V_48 , * V_779 ;
int V_20 ;
F_142 (raid_device, raid_next,
&ioc->raid_device_list, list) {
if ( V_48 -> V_70 )
continue;
V_20 = F_245 ( V_6 -> V_142 , V_174 ,
V_48 -> V_72 , 0 ) ;
if ( V_20 )
F_32 ( V_6 , V_48 ) ;
}
}
static void
F_286 ( struct V_5 * V_6 )
{
struct V_45 * V_46 , * V_100 ;
unsigned long V_65 ;
F_142 (sas_device, next, &ioc->sas_device_init_list,
list) {
if ( V_6 -> V_649 )
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
F_267 ( & V_46 -> V_67 , & V_6 -> V_68 ) ;
F_21 ( & V_6 -> V_66 , V_65 ) ;
}
}
static void
F_287 ( struct V_5 * V_6 )
{
T_4 V_780 ;
if ( ! ( V_6 -> V_257 . V_781 & V_782 ) )
return;
F_284 ( V_6 ) ;
if ( V_6 -> V_731 ) {
V_780 =
F_9 ( V_6 -> V_783 . V_784 ) &
V_785 ;
if ( V_780 ==
V_786 ) {
F_285 ( V_6 ) ;
F_286 ( V_6 ) ;
} else {
F_286 ( V_6 ) ;
F_285 ( V_6 ) ;
}
} else
F_286 ( V_6 ) ;
}
static void
F_288 ( struct V_141 * V_142 )
{
struct V_5 * V_6 = F_58 ( V_142 ) ;
int V_20 ;
if ( V_787 != - 1 && V_787 != 0 )
F_289 ( V_6 , V_787 ) ;
if ( V_692 > 0 )
return;
V_6 -> V_750 = 1 ;
V_20 = F_290 ( V_6 ) ;
if ( V_20 != 0 )
F_3 ( V_58 L_364 , V_6 -> V_35 ) ;
}
static int
F_291 ( struct V_141 * V_142 , unsigned long time )
{
struct V_5 * V_6 = F_58 ( V_142 ) ;
if ( V_692 > 0 ) {
V_6 -> V_49 = 0 ;
V_6 -> V_648 = 0 ;
return 1 ;
}
if ( time >= ( 300 * V_334 ) ) {
V_6 -> V_788 . V_295 = V_296 ;
F_3 ( V_58 L_365
L_366 , V_6 -> V_35 ) ;
V_6 -> V_49 = 0 ;
return 1 ;
}
if ( V_6 -> V_750 )
return 0 ;
if ( V_6 -> V_789 ) {
F_3 ( V_58 L_367
L_368 , V_6 -> V_35 , V_6 -> V_789 ) ;
V_6 -> V_49 = 0 ;
V_6 -> V_648 = 0 ;
V_6 -> V_317 = 1 ;
return 1 ;
}
F_3 ( V_58 L_369 , V_6 -> V_35 ) ;
V_6 -> V_788 . V_295 = V_296 ;
if ( V_6 -> V_648 ) {
V_6 -> V_648 = 0 ;
F_287 ( V_6 ) ;
}
F_292 ( V_6 ) ;
V_6 -> V_49 = 0 ;
return 1 ;
}
static int
F_293 ( struct V_775 * V_562 , const struct V_790 * V_72 )
{
struct V_5 * V_6 ;
struct V_141 * V_142 ;
V_142 = F_294 ( & V_791 ,
sizeof( struct V_5 ) ) ;
if ( ! V_142 )
return - V_792 ;
V_6 = F_58 ( V_142 ) ;
memset ( V_6 , 0 , sizeof( struct V_5 ) ) ;
F_154 ( & V_6 -> V_67 ) ;
F_24 ( & V_6 -> V_67 , & V_793 ) ;
V_6 -> V_142 = V_142 ;
V_6 -> V_72 = V_794 ++ ;
sprintf ( V_6 -> V_35 , L_370 , V_795 , V_6 -> V_72 ) ;
V_6 -> V_562 = V_562 ;
if ( V_72 -> V_43 == V_796 ) {
V_6 -> V_175 = 1 ;
V_6 -> V_273 = 1 ;
} else
V_6 -> V_244 = V_245 ;
V_6 -> V_485 = V_485 ;
V_6 -> V_326 = V_326 ;
V_6 -> V_797 = V_797 ;
V_6 -> V_798 = V_798 ;
V_6 -> V_799 = V_799 ;
V_6 -> V_800 = V_800 ;
V_6 -> V_772 = V_772 ;
V_6 -> V_801 = V_801 ;
V_6 -> V_389 = V_389 ;
V_6 -> V_391 = V_391 ;
V_6 -> V_395 = V_395 ;
V_6 -> V_8 = V_8 ;
V_6 -> V_802 = & F_173 ;
F_295 ( & V_6 -> V_803 ) ;
F_296 ( & V_6 -> V_804 ) ;
F_296 ( & V_6 -> V_91 ) ;
F_296 ( & V_6 -> V_66 ) ;
F_296 ( & V_6 -> V_80 ) ;
F_296 ( & V_6 -> V_355 ) ;
F_296 ( & V_6 -> V_76 ) ;
F_154 ( & V_6 -> V_68 ) ;
F_154 ( & V_6 -> V_71 ) ;
F_154 ( & V_6 -> V_81 ) ;
F_154 ( & V_6 -> V_356 ) ;
F_154 ( & V_6 -> V_77 ) ;
F_154 ( & V_6 -> V_31 . V_620 ) ;
F_154 ( & V_6 -> V_390 ) ;
F_154 ( & V_6 -> V_392 ) ;
F_154 ( & V_6 -> V_805 ) ;
V_142 -> V_806 = 32 ;
V_142 -> V_807 = V_807 ;
V_142 -> V_808 = V_809 ;
V_142 -> V_810 = V_6 -> V_72 ;
if ( V_811 != 0xFFFF ) {
if ( V_811 < 64 ) {
V_142 -> V_811 = 64 ;
F_3 ( V_99 L_371
L_372
L_373 , V_6 -> V_35 , V_811 ) ;
} else if ( V_811 > 32767 ) {
V_142 -> V_811 = 32767 ;
F_3 ( V_99 L_371
L_374
L_375 , V_6 -> V_35 ,
V_811 ) ;
} else {
V_142 -> V_811 = V_811 & 0xFFFE ;
F_3 ( V_58 L_376
L_377 , V_6 -> V_35 , V_142 -> V_811 ) ;
}
}
if ( ( F_297 ( V_142 , & V_562 -> V_169 ) ) ) {
F_3 ( V_34 L_2 ,
V_6 -> V_35 , __FILE__ , __LINE__ , V_36 ) ;
F_19 ( & V_6 -> V_67 ) ;
goto V_812;
}
if ( V_813 )
F_298 ( V_142 , V_813 ) ;
else
F_298 ( V_142 , V_814
| V_815
| V_816 ) ;
F_299 ( V_142 , V_817 ) ;
snprintf ( V_6 -> V_818 , sizeof( V_6 -> V_818 ) ,
L_378 , V_6 -> V_72 ) ;
V_6 -> V_354 = F_300 (
V_6 -> V_818 ) ;
if ( ! V_6 -> V_354 ) {
F_3 ( V_34 L_2 ,
V_6 -> V_35 , __FILE__ , __LINE__ , V_36 ) ;
goto V_819;
}
V_6 -> V_49 = 1 ;
if ( ( F_301 ( V_6 ) ) ) {
F_3 ( V_34 L_2 ,
V_6 -> V_35 , __FILE__ , __LINE__ , V_36 ) ;
goto V_820;
}
if ( V_6 -> V_175 ) {
if ( V_6 -> V_244 == V_245 )
V_6 -> V_649 = 0 ;
else if ( V_6 -> V_244 == V_821 )
V_6 -> V_649 = 1 ;
else {
if ( F_91 ( V_6 ) )
V_6 -> V_649 = 1 ;
else
V_6 -> V_649 = 0 ;
}
} else
V_6 -> V_649 = 0 ;
F_302 ( V_142 ) ;
return 0 ;
V_820:
F_278 ( V_6 -> V_354 ) ;
V_819:
F_19 ( & V_6 -> V_67 ) ;
F_282 ( V_142 ) ;
V_812:
F_283 ( V_142 ) ;
return - V_792 ;
}
static int
F_303 ( struct V_775 * V_562 , T_50 V_200 )
{
struct V_141 * V_142 = F_277 ( V_562 ) ;
struct V_5 * V_6 = F_58 ( V_142 ) ;
T_51 V_822 ;
F_304 ( V_6 ) ;
F_305 ( V_142 ) ;
F_275 ( V_6 ) ;
V_822 = F_306 ( V_562 , V_200 ) ;
F_3 ( V_58 L_379
L_380 , V_6 -> V_35 , V_562 ,
F_307 ( V_562 ) , V_822 ) ;
F_308 ( V_6 ) ;
F_309 ( V_562 ) ;
F_310 ( V_562 , V_822 ) ;
return 0 ;
}
static int
F_311 ( struct V_775 * V_562 )
{
struct V_141 * V_142 = F_277 ( V_562 ) ;
struct V_5 * V_6 = F_58 ( V_142 ) ;
T_51 V_822 = V_562 -> V_823 ;
int V_74 ;
F_3 ( V_58 L_381
L_380 , V_6 -> V_35 , V_562 ,
F_307 ( V_562 ) , V_822 ) ;
F_310 ( V_562 , V_824 ) ;
F_312 ( V_562 , V_824 , 0 ) ;
F_313 ( V_562 ) ;
V_6 -> V_562 = V_562 ;
V_74 = F_314 ( V_6 ) ;
if ( V_74 )
return V_74 ;
F_115 ( V_6 , V_320 , V_825 ) ;
F_315 ( V_142 ) ;
F_292 ( V_6 ) ;
return 0 ;
}
static T_52
F_316 ( struct V_775 * V_562 , T_53 V_200 )
{
struct V_141 * V_142 = F_277 ( V_562 ) ;
struct V_5 * V_6 = F_58 ( V_142 ) ;
F_3 ( V_58 L_382 ,
V_6 -> V_35 , V_200 ) ;
switch ( V_200 ) {
case V_826 :
return V_827 ;
case V_828 :
V_6 -> V_318 = 1 ;
F_305 ( V_6 -> V_142 ) ;
F_304 ( V_6 ) ;
F_308 ( V_6 ) ;
return V_829 ;
case V_830 :
V_6 -> V_318 = 1 ;
F_304 ( V_6 ) ;
F_173 ( V_6 ) ;
return V_831 ;
}
return V_829 ;
}
static T_52
F_317 ( struct V_775 * V_562 )
{
struct V_141 * V_142 = F_277 ( V_562 ) ;
struct V_5 * V_6 = F_58 ( V_142 ) ;
int V_20 ;
F_3 ( V_58 L_383 ,
V_6 -> V_35 ) ;
V_6 -> V_318 = 0 ;
V_6 -> V_562 = V_562 ;
F_313 ( V_562 ) ;
V_20 = F_314 ( V_6 ) ;
if ( V_20 )
return V_831 ;
V_20 = F_115 ( V_6 , V_320 ,
V_321 ) ;
F_3 ( V_99 L_384 , V_6 -> V_35 ,
( V_20 == 0 ) ? L_130 : L_385 ) ;
if ( ! V_20 )
return V_832 ;
else
return V_831 ;
}
static void
F_318 ( struct V_775 * V_562 )
{
struct V_141 * V_142 = F_277 ( V_562 ) ;
struct V_5 * V_6 = F_58 ( V_142 ) ;
F_3 ( V_58 L_386 , V_6 -> V_35 ) ;
F_319 ( V_562 ) ;
F_292 ( V_6 ) ;
F_315 ( V_6 -> V_142 ) ;
}
static T_52
F_320 ( struct V_775 * V_562 )
{
struct V_141 * V_142 = F_277 ( V_562 ) ;
struct V_5 * V_6 = F_58 ( V_142 ) ;
F_3 ( V_58 L_387 ,
V_6 -> V_35 ) ;
return V_829 ;
}
static int T_54
F_321 ( void )
{
int error ;
V_794 = 0 ;
F_3 ( V_7 L_388 , V_795 ,
V_833 ) ;
V_809 =
F_322 ( & V_834 ) ;
if ( ! V_809 )
return - V_792 ;
V_197 = F_323 ( & V_835 ) ;
if ( ! V_197 ) {
F_324 ( V_809 ) ;
return - V_792 ;
}
F_325 () ;
V_485 = F_326 ( F_203 ) ;
V_326 = F_326 ( F_104 ) ;
V_798 = F_326 ( V_836 ) ;
V_799 = F_326 (
V_837 ) ;
V_800 = F_326 (
V_838 ) ;
V_772 = F_326 ( F_223 ) ;
V_801 = F_326 (
V_839 ) ;
V_797 = F_326 ( V_840 ) ;
V_389 = F_326 (
F_161 ) ;
V_391 = F_326 (
F_158 ) ;
V_395 = F_326 (
F_155 ) ;
F_327 () ;
error = F_328 ( & V_841 ) ;
if ( error ) {
F_329 ( V_197 ) ;
F_324 ( V_809 ) ;
}
return error ;
}
static void T_55
F_330 ( void )
{
F_3 ( V_7 L_389 ,
V_833 ) ;
F_331 ( & V_841 ) ;
F_332 () ;
F_333 ( V_485 ) ;
F_333 ( V_326 ) ;
F_333 ( V_798 ) ;
F_333 ( V_799 ) ;
F_333 ( V_800 ) ;
F_333 ( V_772 ) ;
F_333 ( V_801 ) ;
F_333 ( V_797 ) ;
F_333 ( V_389 ) ;
F_333 ( V_391 ) ;
F_333 ( V_395 ) ;
F_329 ( V_197 ) ;
F_324 ( V_809 ) ;
}
