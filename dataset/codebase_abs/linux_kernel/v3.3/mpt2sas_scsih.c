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
F_21 ( & V_6 -> V_66 , V_65 ) ;
if ( V_46 && V_46 -> V_82 &
V_86 )
V_144 = V_154 ;
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
V_148 -> V_48 = V_48 ;
V_48 -> V_70 = V_70 ;
}
F_21 ( & V_6 -> V_76 , V_65 ) ;
return 0 ;
}
F_18 ( & V_6 -> V_66 , V_65 ) ;
V_171 = F_70 ( V_70 -> V_169 . V_175 ) ;
V_46 = F_15 ( V_6 ,
V_171 -> V_176 . V_9 ) ;
if ( V_46 ) {
V_148 -> V_27 = V_46 -> V_27 ;
V_148 -> V_9 = V_46 -> V_9 ;
V_46 -> V_70 = V_70 ;
V_46 -> V_72 = V_70 -> V_72 ;
V_46 -> V_73 = V_70 -> V_73 ;
if ( F_71 ( V_46 -> V_27 , V_6 -> V_177 ) )
V_148 -> V_65 |=
V_178 ;
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
V_171 = F_70 ( V_70 -> V_169 . V_175 ) ;
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
F_73 ( struct V_138 * V_139 )
{
struct V_141 * V_142 ;
struct V_5 * V_6 ;
struct V_147 * V_148 ;
struct V_145 * V_146 ;
struct V_168 * V_70 ;
struct V_47 * V_48 ;
unsigned long V_65 ;
V_146 = F_69 ( sizeof( struct V_138 ) , V_172 ) ;
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
V_148 -> V_180 -- ;
V_142 = F_68 ( & V_70 -> V_169 ) ;
V_6 = F_58 ( V_142 ) ;
if ( ! ( V_148 -> V_65 & V_153 ) ) {
F_18 ( & V_6 -> V_66 , V_65 ) ;
V_46 = F_15 ( V_6 ,
V_148 -> V_9 ) ;
if ( V_46 && ! V_148 -> V_180 )
V_46 -> V_70 = NULL ;
F_21 ( & V_6 -> V_66 , V_65 ) ;
}
F_20 ( V_139 -> V_150 ) ;
V_139 -> V_150 = NULL ;
}
static void
F_75 ( struct V_5 * V_6 ,
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
V_82 = F_76 ( V_28 . V_183 ) ;
F_51 ( V_7 , V_139 ,
L_16
L_17 ,
( V_82 & V_184 ) ? L_18 : L_19 ,
( V_65 & V_185 ) ? L_18 : L_19 ,
( V_65 & V_186 ) ? L_18 :
L_19 ,
( V_65 & V_187 ) ? L_18 : L_19 ,
( V_65 & V_188 ) ? L_18 : L_19 ,
( V_65 & V_189 ) ? L_18 : L_19 ) ;
}
static int
F_77 ( struct V_43 * V_169 )
{
struct V_138 * V_139 = F_78 ( V_169 ) ;
struct V_5 * V_6 = F_58 ( V_139 -> V_143 ) ;
if ( V_6 -> V_190 )
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
T_6 V_193 = 0 ;
F_18 ( & V_6 -> V_76 , V_65 ) ;
V_48 = F_28 ( V_6 , V_139 -> V_72 ,
V_139 -> V_73 ) ;
F_21 ( & V_6 -> V_76 , V_65 ) ;
if ( ! V_48 || V_6 -> V_190 )
goto V_75;
if ( F_80 ( V_6 , & V_29 , & V_191 ,
V_194 , V_48 -> V_27 ,
sizeof( T_13 ) ) ) {
F_3 ( V_34 L_2 ,
V_6 -> V_35 , __FILE__ , __LINE__ , V_36 ) ;
goto V_75;
}
V_192 = F_76 ( V_191 . V_195 ) ;
if ( V_192 & V_196 )
V_193 = V_48 -> V_193 ;
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
F_18 ( & V_6 -> V_76 , V_65 ) ;
V_48 = F_28 ( V_6 , V_139 -> V_72 ,
V_139 -> V_73 ) ;
F_21 ( & V_6 -> V_76 , V_65 ) ;
if ( ! V_48 )
goto V_75;
if ( F_80 ( V_6 , & V_29 , & V_191 ,
V_194 , V_48 -> V_27 ,
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
F_84 ( struct V_138 * V_139 , struct V_47 * V_48 )
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
F_85 ( V_197 , & V_139 -> V_224 , V_213 ) ;
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
V_48 -> V_215 = V_191 -> V_230 ;
if ( ! ( F_88 ( V_6 , & V_29 ,
& V_225 , V_231 ,
V_191 -> V_228 [ 0 ] . V_232 ) ) ) {
if ( ! ( F_12 ( V_6 , & V_29 ,
& V_28 , V_33 ,
F_9 ( V_225 . V_233 ) ) ) ) {
V_48 -> V_82 =
F_76 ( V_28 . V_183 ) ;
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
unsigned long V_239 , V_240 ;
T_6 V_241 , V_242 ;
T_1 V_243 ;
if ( ! V_6 -> V_190 )
return;
if ( V_6 -> V_244 == V_245 ) {
F_3 ( V_58 L_20
L_21 , V_6 -> V_35 ) ;
return;
}
if ( F_91 ( V_6 ) > 1 ) {
F_89 ( V_6 ) ;
F_3 ( V_58 L_20
L_22 , V_6 -> V_35 ) ;
return;
}
if ( ( F_87 ( V_6 , V_48 -> V_27 ,
& V_227 ) ) || ! V_227 ) {
F_3 ( V_58 L_20
L_23 , V_6 -> V_35 ) ;
return;
}
V_226 = F_53 ( T_13 , V_228 ) + ( V_227 *
sizeof( V_229 ) ) ;
V_191 = F_69 ( V_226 , V_172 ) ;
if ( ! V_191 ) {
F_3 ( V_58 L_20
L_24 , V_6 -> V_35 ) ;
return;
}
if ( ( F_80 ( V_6 , & V_29 , V_191 ,
V_194 , V_48 -> V_27 , V_226 ) ) ) {
F_3 ( V_58 L_20
L_25 , V_6 -> V_35 ) ;
F_20 ( V_191 ) ;
return;
}
if ( V_227 > V_246 ) {
F_3 ( V_99 L_20
L_26
L_27 , V_6 -> V_35 , V_48 -> V_27 ,
V_227 , V_246 ) ;
F_20 ( V_191 ) ;
return;
}
for ( V_238 = 0 ; V_238 < V_227 ; V_238 ++ ) {
if ( F_88 ( V_6 , & V_29 ,
& V_225 , V_231 ,
V_191 -> V_228 [ V_238 ] . V_232 ) ||
V_225 . V_233 == V_173 ) {
F_3 ( V_58 L_28
L_29
L_30 ,
V_6 -> V_35 , V_48 -> V_27 ,
V_191 -> V_228 [ V_238 ] . V_232 ) ;
goto V_247;
}
V_243 = F_6 ( V_225 . V_248 ) ;
if ( V_243 >> 32 ) {
F_3 ( V_58 L_28
L_29
L_31 ,
V_6 -> V_35 , V_48 -> V_27 ,
F_9 ( V_225 . V_233 ) ,
( unsigned long long ) V_243 ) ;
goto V_247;
}
V_48 -> V_249 [ V_238 ] = F_9 ( V_225 . V_233 ) ;
}
if ( V_48 -> V_215 != V_216 ) {
F_3 ( V_58 L_20
L_32
L_33 , V_6 -> V_35 ,
V_48 -> V_27 , V_48 -> V_215 ,
( F_76 ( V_191 -> V_250 ) *
F_9 ( V_191 -> V_251 ) ) / 1024 ,
F_9 ( V_191 -> V_251 ) ) ;
goto V_247;
}
V_239 = F_76 ( V_191 -> V_250 ) ;
V_241 = F_93 ( & V_239 , 32 ) ;
if ( V_241 == 32 ) {
F_3 ( V_58 L_20
L_34 ,
V_6 -> V_35 , V_48 -> V_27 ,
( F_76 ( V_191 -> V_250 ) *
F_9 ( V_191 -> V_251 ) ) / 1024 ) ;
goto V_247;
}
V_48 -> V_252 = V_241 ;
V_240 = F_9 ( V_191 -> V_251 ) ;
V_242 = F_93 ( & V_240 , 16 ) ;
if ( V_242 == 16 ) {
F_3 ( V_58 L_20
L_35 ,
V_6 -> V_35 , V_48 -> V_27 ,
F_9 ( V_191 -> V_251 ) ) ;
goto V_247;
}
V_48 -> V_253 = V_242 ;
V_48 -> V_236 = 1 ;
F_3 ( V_58 L_36
L_37 , V_6 -> V_35 , V_48 -> V_27 ) ;
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
F_51 ( V_7 , V_139 , L_38 ,
F_96 ( V_139 ) ? L_39 : L_40 ) ;
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
char * V_261 = L_41 ;
char * V_262 = L_41 ;
V_140 = 1 ;
V_146 = V_139 -> V_150 ;
V_146 -> V_263 = 1 ;
V_146 -> V_65 &= ~ V_179 ;
V_148 = V_146 -> V_152 ;
if ( V_148 -> V_65 & V_153 ) {
F_18 ( & V_6 -> V_76 , V_65 ) ;
V_48 = F_29 ( V_6 ,
V_148 -> V_27 ) ;
F_21 ( & V_6 -> V_76 , V_65 ) ;
if ( ! V_48 ) {
F_44 ( V_6 , F_3 ( V_99
L_2 , V_6 -> V_35 , __FILE__ ,
__LINE__ , V_36 ) ) ;
return 1 ;
}
F_86 ( V_6 , V_48 ) ;
if ( F_86 ( V_6 , V_48 ) ) {
F_44 ( V_6 , F_3 ( V_99
L_2 , V_6 -> V_35 , __FILE__ ,
__LINE__ , V_36 ) ) ;
return 1 ;
}
F_92 ( V_6 , V_48 ) ;
if ( V_48 -> V_82 &
V_84 ) {
V_140 = V_264 ;
V_261 = L_42 ;
} else {
V_140 = V_154 ;
if ( V_48 -> V_82 &
V_86 )
V_261 = L_43 ;
else
V_261 = L_44 ;
}
switch ( V_48 -> V_215 ) {
case V_216 :
V_262 = L_45 ;
break;
case V_220 :
V_140 = V_265 ;
if ( V_6 -> V_266 . V_267 &&
( F_76 ( V_6 -> V_266 . V_268 ) &
V_269 ) &&
! ( V_48 -> V_227 % 2 ) )
V_262 = L_46 ;
else
V_262 = L_47 ;
break;
case V_222 :
V_140 = V_265 ;
V_262 = L_48 ;
break;
case V_218 :
V_140 = V_265 ;
V_262 = L_46 ;
break;
case V_270 :
default:
V_140 = V_265 ;
V_262 = L_49 ;
break;
}
if ( ! V_6 -> V_271 )
F_51 ( V_7 , V_139 , L_50
L_51 ,
V_262 , V_48 -> V_27 ,
( unsigned long long ) V_48 -> V_52 ,
V_48 -> V_227 , V_261 ) ;
F_61 ( V_139 , V_140 , V_157 ) ;
if ( ! V_6 -> V_190 )
F_84 ( V_139 , V_48 ) ;
return 0 ;
}
F_18 ( & V_6 -> V_66 , V_65 ) ;
V_46 = F_15 ( V_6 ,
V_146 -> V_152 -> V_9 ) ;
F_21 ( & V_6 -> V_66 , V_65 ) ;
if ( V_46 ) {
if ( V_148 -> V_65 &
V_178 ) {
if ( F_98 ( V_6 ,
V_46 -> V_27 , & V_46 -> V_272 ) ) {
F_44 ( V_6 , F_3 ( V_99
L_2 , V_6 -> V_35 ,
__FILE__ , __LINE__ , V_36 ) ) ;
return 1 ;
}
if ( V_46 -> V_272 &&
F_99 ( V_6 ,
V_46 -> V_272 ,
& V_46 -> V_273 ) ) {
F_44 ( V_6 , F_3 ( V_99
L_2 , V_6 -> V_35 ,
__FILE__ , __LINE__ , V_36 ) ) ;
return 1 ;
}
}
if ( V_46 -> V_82 & V_84 ) {
V_140 = V_264 ;
V_260 = 1 ;
V_261 = L_42 ;
} else {
V_140 = V_154 ;
if ( V_46 -> V_82 &
V_85 )
V_261 = L_44 ;
else if ( V_46 -> V_82 &
V_86 )
V_261 = L_43 ;
}
F_51 ( V_7 , V_139 , L_50
L_52 ,
V_261 , V_46 -> V_27 ,
( unsigned long long ) V_46 -> V_9 ,
V_46 -> V_274 ,
( unsigned long long ) V_46 -> V_12 ) ;
F_51 ( V_7 , V_139 , L_53
L_54 , V_261 ,
( unsigned long long ) V_46 -> V_14 ,
V_46 -> V_18 ) ;
if ( ! V_260 )
F_75 ( V_6 , V_46 , V_139 ) ;
} else {
F_44 ( V_6 , F_3 ( V_99
L_2 , V_6 -> V_35 , __FILE__ , __LINE__ ,
V_36 ) ) ;
return 1 ;
}
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
V_284 = L_55 ;
break;
case V_286 :
V_284 = L_56 ;
break;
case V_287 :
V_284 = L_57 ;
break;
case V_288 :
V_284 = L_58 ;
break;
case V_289 :
V_284 = L_59 ;
break;
case V_290 :
V_284 = L_60 ;
break;
case 0xA :
V_284 = L_61 ;
break;
case V_291 :
V_284 = L_62 ;
break;
default:
V_284 = L_63 ;
break;
}
F_3 ( V_99 L_64 ,
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
unsigned long V_307 , enum V_308 V_309 )
{
T_20 * V_103 ;
T_21 * V_29 ;
T_4 V_88 = 0 ;
T_10 V_310 ;
unsigned long V_311 ;
struct V_312 * V_89 = NULL ;
int V_20 ;
if ( V_309 == V_313 )
F_112 ( & V_6 -> V_294 . V_314 ) ;
if ( V_6 -> V_294 . V_295 != V_296 ) {
F_3 ( V_58 L_65 ,
V_36 , V_6 -> V_35 ) ;
V_20 = V_315 ;
goto V_316;
}
if ( V_6 -> V_317 || V_6 -> V_318 ||
V_6 -> V_319 ) {
F_3 ( V_58 L_66 ,
V_36 , V_6 -> V_35 ) ;
V_20 = V_315 ;
goto V_316;
}
V_310 = F_113 ( V_6 , 0 ) ;
if ( V_310 & V_320 ) {
F_114 ( V_6 , F_3 ( V_58 L_67
L_68 , V_6 -> V_35 ) ) ;
V_20 = F_115 ( V_6 , V_321 ,
V_322 ) ;
V_20 = ( ! V_20 ) ? V_323 : V_315 ;
goto V_316;
}
if ( ( V_310 & V_324 ) == V_325 ) {
F_116 ( V_6 , V_310 &
V_326 ) ;
V_20 = F_115 ( V_6 , V_321 ,
V_322 ) ;
V_20 = ( ! V_20 ) ? V_323 : V_315 ;
goto V_316;
}
V_88 = F_117 ( V_6 , V_6 -> V_327 ) ;
if ( ! V_88 ) {
F_3 ( V_34 L_69 ,
V_6 -> V_35 , V_36 ) ;
V_20 = V_315 ;
goto V_316;
}
if ( type == V_328 )
V_89 = & V_6 -> V_89 [ V_305 - 1 ] ;
F_118 ( V_6 , F_3 ( V_58 L_70
L_71 , V_6 -> V_35 , V_27 , type ,
V_305 ) ) ;
V_6 -> V_294 . V_295 = V_300 ;
V_103 = F_48 ( V_6 , V_88 ) ;
V_6 -> V_294 . V_88 = V_88 ;
memset ( V_103 , 0 , sizeof( T_20 ) ) ;
memset ( V_6 -> V_294 . V_293 , 0 , sizeof( T_21 ) ) ;
V_103 -> V_329 = V_330 ;
V_103 -> V_233 = F_119 ( V_27 ) ;
V_103 -> V_331 = type ;
V_103 -> V_332 = F_119 ( V_305 ) ;
F_120 ( V_95 , (struct V_333 * ) V_103 -> V_334 ) ;
F_108 ( V_6 , V_27 ) ;
F_121 ( & V_6 -> V_294 . V_301 ) ;
F_122 ( V_6 , V_88 ) ;
V_311 = F_123 ( & V_6 -> V_294 . V_301 , V_306 * V_335 ) ;
if ( ! ( V_6 -> V_294 . V_295 & V_297 ) ) {
F_3 ( V_34 L_72 ,
V_6 -> V_35 , V_36 ) ;
F_124 ( V_103 ,
sizeof( T_20 ) / 4 ) ;
if ( ! ( V_6 -> V_294 . V_295 & V_336 ) ) {
V_20 = F_115 ( V_6 , V_321 ,
V_322 ) ;
V_20 = ( ! V_20 ) ? V_323 : V_315 ;
V_6 -> V_294 . V_295 = V_296 ;
F_110 ( V_6 , V_27 ) ;
goto V_316;
}
}
if ( V_6 -> V_294 . V_295 & V_299 ) {
V_29 = V_6 -> V_294 . V_293 ;
F_118 ( V_6 , F_3 ( V_58 L_73
L_74 ,
V_6 -> V_35 , F_9 ( V_29 -> V_38 ) ,
F_76 ( V_29 -> V_337 ) ,
F_76 ( V_29 -> V_338 ) ) ) ;
if ( V_6 -> V_8 & V_339 ) {
F_103 ( V_6 , V_29 -> V_340 ) ;
if ( V_29 -> V_38 )
F_124 ( V_103 ,
sizeof( T_20 ) / 4 ) ;
}
}
switch ( type ) {
case V_328 :
V_20 = V_323 ;
if ( V_89 -> V_90 == NULL )
break;
V_20 = V_315 ;
break;
case V_341 :
if ( F_40 ( V_6 , V_72 , V_73 ) )
V_20 = V_315 ;
else
V_20 = V_323 ;
break;
case V_342 :
case V_343 :
if ( F_41 ( V_6 , V_72 , V_95 , V_73 ) )
V_20 = V_315 ;
else
V_20 = V_323 ;
break;
case V_344 :
V_20 = V_323 ;
break;
default:
V_20 = V_315 ;
break;
}
F_110 ( V_6 , V_27 ) ;
V_6 -> V_294 . V_295 = V_296 ;
if ( V_309 == V_313 )
F_125 ( & V_6 -> V_294 . V_314 ) ;
return V_20 ;
V_316:
if ( V_309 == V_313 )
F_125 ( & V_6 -> V_294 . V_314 ) ;
return V_20 ;
}
static void
F_126 ( struct V_5 * V_6 , struct V_87 * V_90 )
{
struct V_168 * V_70 = V_90 -> V_43 -> V_345 ;
struct V_147 * V_346 = V_70 -> V_150 ;
struct V_45 * V_46 = NULL ;
unsigned long V_65 ;
char * V_347 = NULL ;
if ( ! V_346 )
return;
if ( V_6 -> V_271 )
V_347 = L_75 ;
else
V_347 = L_76 ;
F_127 ( V_90 ) ;
if ( V_346 -> V_65 & V_153 ) {
F_128 ( V_7 , V_70 , L_77
L_78 , V_347 , V_346 -> V_27 ,
V_347 , ( unsigned long long ) V_346 -> V_9 ) ;
} else {
F_18 ( & V_6 -> V_66 , V_65 ) ;
V_46 = F_15 ( V_6 ,
V_346 -> V_9 ) ;
if ( V_46 ) {
if ( V_346 -> V_65 &
V_178 ) {
F_128 ( V_7 , V_70 ,
L_79
L_80 ,
V_46 -> V_272 ,
( unsigned long long ) V_46 -> V_273 ) ;
}
F_128 ( V_7 , V_70 ,
L_81 ,
V_46 -> V_27 ,
( unsigned long long ) V_46 -> V_9 ,
V_46 -> V_274 ) ;
F_128 ( V_7 , V_70 ,
L_54 ,
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
F_51 ( V_7 , V_90 -> V_43 , L_82
L_83 , V_90 ) ;
F_126 ( V_6 , V_90 ) ;
V_146 = V_90 -> V_43 -> V_150 ;
if ( ! V_146 || ! V_146 -> V_152 ) {
F_51 ( V_7 , V_90 -> V_43 , L_84
L_83 , V_90 ) ;
V_90 -> V_348 = V_349 << 16 ;
V_90 -> V_350 ( V_90 ) ;
V_74 = V_323 ;
goto V_75;
}
V_88 = F_39 ( V_6 , V_90 ) ;
if ( ! V_88 ) {
V_90 -> V_348 = V_351 << 16 ;
V_74 = V_323 ;
goto V_75;
}
if ( V_146 -> V_152 -> V_65 &
V_178 ||
V_146 -> V_152 -> V_65 & V_153 ) {
V_90 -> V_348 = V_351 << 16 ;
V_74 = V_315 ;
goto V_75;
}
F_130 ( V_6 ) ;
V_27 = V_146 -> V_152 -> V_27 ;
V_74 = F_111 ( V_6 , V_27 , V_90 -> V_43 -> V_73 ,
V_90 -> V_43 -> V_72 , V_90 -> V_43 -> V_95 ,
V_328 , V_88 , 30 ,
V_90 -> V_307 , V_313 ) ;
V_75:
F_51 ( V_7 , V_90 -> V_43 , L_85 ,
( ( V_74 == V_323 ) ? L_86 : L_87 ) , V_90 ) ;
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
struct V_168 * V_70 = V_90 -> V_43 -> V_345 ;
F_128 ( V_7 , V_70 , L_88
L_83 , V_90 ) ;
F_126 ( V_6 , V_90 ) ;
V_146 = V_90 -> V_43 -> V_150 ;
if ( ! V_146 || ! V_146 -> V_152 ) {
F_128 ( V_7 , V_70 , L_84
L_83 , V_90 ) ;
V_90 -> V_348 = V_349 << 16 ;
V_90 -> V_350 ( V_90 ) ;
V_74 = V_323 ;
goto V_75;
}
V_27 = 0 ;
if ( V_146 -> V_152 -> V_65 &
V_178 ) {
F_18 ( & V_6 -> V_66 , V_65 ) ;
V_46 = F_16 ( V_6 ,
V_146 -> V_152 -> V_27 ) ;
if ( V_46 )
V_27 = V_46 -> V_272 ;
F_21 ( & V_6 -> V_66 , V_65 ) ;
} else
V_27 = V_146 -> V_152 -> V_27 ;
if ( ! V_27 ) {
V_90 -> V_348 = V_351 << 16 ;
V_74 = V_315 ;
goto V_75;
}
V_74 = F_111 ( V_6 , V_27 , V_90 -> V_43 -> V_73 ,
V_90 -> V_43 -> V_72 , V_90 -> V_43 -> V_95 ,
V_343 , 0 , 30 , 0 ,
V_313 ) ;
V_75:
F_51 ( V_7 , V_90 -> V_43 , L_89 ,
( ( V_74 == V_323 ) ? L_86 : L_87 ) , V_90 ) ;
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
struct V_168 * V_70 = V_90 -> V_43 -> V_345 ;
F_128 ( V_7 , V_70 , L_90
L_83 , V_90 ) ;
F_126 ( V_6 , V_90 ) ;
V_146 = V_90 -> V_43 -> V_150 ;
if ( ! V_146 || ! V_146 -> V_152 ) {
F_128 ( V_7 , V_70 , L_91
L_83 , V_90 ) ;
V_90 -> V_348 = V_349 << 16 ;
V_90 -> V_350 ( V_90 ) ;
V_74 = V_323 ;
goto V_75;
}
V_27 = 0 ;
if ( V_146 -> V_152 -> V_65 &
V_178 ) {
F_18 ( & V_6 -> V_66 , V_65 ) ;
V_46 = F_16 ( V_6 ,
V_146 -> V_152 -> V_27 ) ;
if ( V_46 )
V_27 = V_46 -> V_272 ;
F_21 ( & V_6 -> V_66 , V_65 ) ;
} else
V_27 = V_146 -> V_152 -> V_27 ;
if ( ! V_27 ) {
V_90 -> V_348 = V_351 << 16 ;
V_74 = V_315 ;
goto V_75;
}
V_74 = F_111 ( V_6 , V_27 , V_90 -> V_43 -> V_73 ,
V_90 -> V_43 -> V_72 , 0 , V_341 , 0 ,
30 , 0 , V_313 ) ;
V_75:
F_128 ( V_7 , V_70 , L_92 ,
( ( V_74 == V_323 ) ? L_86 : L_87 ) , V_90 ) ;
return V_74 ;
}
static int
F_133 ( struct V_87 * V_90 )
{
struct V_5 * V_6 = F_58 ( V_90 -> V_43 -> V_143 ) ;
int V_74 , V_352 ;
F_3 ( V_58 L_93 ,
V_6 -> V_35 , V_90 ) ;
F_127 ( V_90 ) ;
V_352 = F_115 ( V_6 , V_321 ,
V_322 ) ;
V_74 = ( V_352 < 0 ) ? V_315 : V_323 ;
F_3 ( V_58 L_94 ,
V_6 -> V_35 , ( ( V_74 == V_323 ) ? L_86 : L_87 ) , V_90 ) ;
return V_74 ;
}
static void
F_134 ( struct V_5 * V_6 , struct V_353 * V_354 )
{
unsigned long V_65 ;
if ( V_6 -> V_355 == NULL )
return;
F_18 ( & V_6 -> V_356 , V_65 ) ;
F_24 ( & V_354 -> V_67 , & V_6 -> V_357 ) ;
F_135 ( & V_354 -> V_358 , V_359 ) ;
F_136 ( V_6 -> V_355 ,
& V_354 -> V_358 , 0 ) ;
F_21 ( & V_6 -> V_356 , V_65 ) ;
}
static void
F_137 ( struct V_5 * V_6 , struct V_353
* V_354 )
{
unsigned long V_65 ;
F_18 ( & V_6 -> V_356 , V_65 ) ;
F_19 ( & V_354 -> V_67 ) ;
F_20 ( V_354 -> V_360 ) ;
F_20 ( V_354 ) ;
F_21 ( & V_6 -> V_356 , V_65 ) ;
}
static void
F_138 ( struct V_5 * V_6 )
{
struct V_353 * V_354 ;
if ( V_6 -> V_49 )
return;
V_354 = F_69 ( sizeof( struct V_353 ) , V_361 ) ;
if ( ! V_354 )
return;
V_354 -> V_362 = V_363 ;
V_354 -> V_6 = V_6 ;
F_134 ( V_6 , V_354 ) ;
}
void
F_139 ( struct V_5 * V_6 )
{
struct V_353 * V_354 ;
V_354 = F_69 ( sizeof( struct V_353 ) , V_361 ) ;
if ( ! V_354 )
return;
V_354 -> V_362 = V_364 ;
V_354 -> V_6 = V_6 ;
F_134 ( V_6 , V_354 ) ;
}
static void
F_140 ( struct V_5 * V_6 )
{
struct V_353 * V_354 , * V_100 ;
if ( F_43 ( & V_6 -> V_357 ) ||
! V_6 -> V_355 || F_141 () )
return;
F_142 (fw_event, next, &ioc->fw_event_list, list) {
if ( F_143 ( & V_354 -> V_358 ) ) {
F_137 ( V_6 , V_354 ) ;
continue;
}
V_354 -> V_365 = 1 ;
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
if ( ! V_146 -> V_366 )
continue;
V_146 -> V_366 = 0 ;
F_23 ( V_6 , F_51 ( V_7 , V_139 , L_95
L_96 ,
V_146 -> V_152 -> V_27 ) ) ;
F_145 ( V_139 ) ;
}
}
static void
F_146 ( struct V_5 * V_6 , T_4 V_27 )
{
struct V_145 * V_146 ;
struct V_138 * V_139 ;
F_109 (sdev, ioc->shost) {
V_146 = V_139 -> V_150 ;
if ( ! V_146 )
continue;
if ( ! V_146 -> V_366 )
continue;
if ( V_146 -> V_152 -> V_27 == V_27 ) {
F_23 ( V_6 , F_51 ( V_7 , V_139 ,
V_58 L_97
L_96 , V_6 -> V_35 , V_27 ) ) ;
V_146 -> V_366 = 0 ;
F_145 ( V_139 ) ;
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
if ( V_146 -> V_366 )
continue;
V_146 -> V_366 = 1 ;
F_23 ( V_6 , F_51 ( V_7 , V_139 , L_98
L_96 ,
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
if ( V_146 -> V_366 )
continue;
if ( V_146 -> V_152 -> V_27 == V_27 ) {
F_23 ( V_6 , F_51 ( V_7 , V_139 ,
V_58 L_99
L_96 , V_6 -> V_35 , V_27 ) ) ;
V_146 -> V_366 = 1 ;
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
F_21 ( & V_6 -> V_66 , V_65 ) ;
if ( ! V_46 )
continue;
F_149 ( V_6 , V_46 -> V_27 ) ;
}
}
F_4 (mpt2sas_port,
&sas_expander->sas_port_list, port_list) {
if ( V_368 -> V_370 . V_371 ==
V_373 ||
V_368 -> V_370 . V_371 ==
V_374 ) {
F_18 ( & V_6 -> V_80 , V_65 ) ;
V_369 =
F_34 (
V_6 , V_368 -> V_370 . V_9 ) ;
F_21 ( & V_6 -> V_80 , V_65 ) ;
F_150 ( V_6 ,
V_369 ) ;
}
}
}
static void
F_151 ( struct V_5 * V_6 ,
T_22 * V_360 )
{
int V_92 ;
T_4 V_27 ;
T_4 V_375 ;
T_6 V_376 ;
for ( V_92 = 0 ; V_92 < V_360 -> V_377 ; V_92 ++ ) {
V_27 = F_9 ( V_360 -> V_378 [ V_92 ] . V_379 ) ;
if ( ! V_27 )
continue;
V_376 = V_360 -> V_380 + V_92 ;
V_375 = V_360 -> V_378 [ V_92 ] . V_381 &
V_382 ;
if ( V_375 == V_383 )
F_149 ( V_6 , V_27 ) ;
}
}
static void
F_152 ( struct V_5 * V_6 , T_4 V_27 )
{
T_20 * V_103 ;
T_4 V_88 ;
struct V_45 * V_46 ;
struct V_147 * V_148 = NULL ;
T_1 V_9 = 0 ;
unsigned long V_65 ;
struct V_384 * V_385 ;
T_10 V_310 ;
if ( V_6 -> V_318 ) {
F_23 ( V_6 , F_3 ( V_58 L_100
L_101 , V_36 , V_6 -> V_35 , V_27 ) ) ;
return;
} else if ( V_6 -> V_319 ) {
F_23 ( V_6 , F_3 ( V_58 L_102
L_103 , V_36 , V_6 -> V_35 ,
V_27 ) ) ;
return;
}
V_310 = F_113 ( V_6 , 1 ) ;
if ( V_310 != V_386 ) {
F_23 ( V_6 , F_3 ( V_58 L_104
L_105 , V_36 , V_6 -> V_35 ,
V_27 ) ) ;
return;
}
if ( F_71 ( V_27 , V_6 -> V_177 ) )
return;
F_18 ( & V_6 -> V_66 , V_65 ) ;
V_46 = F_16 ( V_6 , V_27 ) ;
if ( V_46 && V_46 -> V_70 &&
V_46 -> V_70 -> V_150 ) {
V_148 = V_46 -> V_70 -> V_150 ;
V_148 -> V_387 = 1 ;
V_9 = V_46 -> V_9 ;
}
F_21 ( & V_6 -> V_66 , V_65 ) ;
if ( V_148 ) {
F_23 ( V_6 , F_3 ( V_58 L_106
L_107 , V_6 -> V_35 , V_27 ,
( unsigned long long ) V_9 ) ) ;
F_146 ( V_6 , V_27 ) ;
V_148 -> V_27 = V_173 ;
}
V_88 = F_117 ( V_6 , V_6 -> V_388 ) ;
if ( ! V_88 ) {
V_385 = F_69 ( sizeof( * V_385 ) , V_361 ) ;
if ( ! V_385 )
return;
F_153 ( & V_385 -> V_67 ) ;
V_385 -> V_27 = V_27 ;
F_24 ( & V_385 -> V_67 , & V_6 -> V_389 ) ;
F_23 ( V_6 , F_3 ( V_58
L_108 ,
V_6 -> V_35 , V_27 ) ) ;
return;
}
F_23 ( V_6 , F_3 ( V_58 L_109
L_110 , V_6 -> V_35 , V_27 , V_88 ,
V_6 -> V_388 ) ) ;
V_103 = F_48 ( V_6 , V_88 ) ;
memset ( V_103 , 0 , sizeof( T_20 ) ) ;
V_103 -> V_329 = V_330 ;
V_103 -> V_233 = F_119 ( V_27 ) ;
V_103 -> V_331 = V_341 ;
F_122 ( V_6 , V_88 ) ;
}
static T_6
F_154 ( struct V_5 * V_6 , T_4 V_88 ,
T_6 V_292 , T_10 V_293 )
{
#ifdef F_155
T_23 * V_29 =
F_106 ( V_6 , V_293 ) ;
#endif
F_23 ( V_6 , F_3 ( V_58
L_111
L_112 ,
V_6 -> V_35 , F_9 ( V_29 -> V_233 ) , V_88 ,
F_9 ( V_29 -> V_38 ) ,
F_76 ( V_29 -> V_337 ) ) ) ;
return 1 ;
}
static void
F_156 ( struct V_5 * V_6 , T_4 V_27 )
{
T_20 * V_103 ;
T_4 V_88 ;
struct V_384 * V_385 ;
if ( V_6 -> V_317 || V_6 -> V_318 ||
V_6 -> V_319 ) {
F_23 ( V_6 , F_3 ( V_58 L_113
L_114 , V_36 , V_6 -> V_35 ) ) ;
return;
}
V_88 = F_117 ( V_6 , V_6 -> V_390 ) ;
if ( ! V_88 ) {
V_385 = F_69 ( sizeof( * V_385 ) , V_361 ) ;
if ( ! V_385 )
return;
F_153 ( & V_385 -> V_67 ) ;
V_385 -> V_27 = V_27 ;
F_24 ( & V_385 -> V_67 , & V_6 -> V_391 ) ;
F_23 ( V_6 , F_3 ( V_58
L_108 ,
V_6 -> V_35 , V_27 ) ) ;
return;
}
F_23 ( V_6 , F_3 ( V_58 L_109
L_110 , V_6 -> V_35 , V_27 , V_88 ,
V_6 -> V_390 ) ) ;
V_103 = F_48 ( V_6 , V_88 ) ;
memset ( V_103 , 0 , sizeof( T_20 ) ) ;
V_103 -> V_329 = V_330 ;
V_103 -> V_233 = F_119 ( V_27 ) ;
V_103 -> V_331 = V_341 ;
F_122 ( V_6 , V_88 ) ;
}
static T_6
F_157 ( struct V_5 * V_6 , T_4 V_88 ,
T_6 V_292 , T_10 V_293 )
{
T_4 V_27 ;
T_20 * V_392 ;
T_21 * V_29 =
F_106 ( V_6 , V_293 ) ;
if ( V_6 -> V_317 || V_6 -> V_318 ||
V_6 -> V_319 ) {
F_23 ( V_6 , F_3 ( V_58 L_113
L_114 , V_36 , V_6 -> V_35 ) ) ;
return 1 ;
}
V_392 = F_48 ( V_6 , V_88 ) ;
V_27 = F_9 ( V_392 -> V_233 ) ;
if ( V_27 != F_9 ( V_29 -> V_233 ) ) {
F_23 ( V_6 , F_3 ( L_115
L_116 , V_27 ,
F_9 ( V_29 -> V_233 ) , V_88 ) ) ;
return 0 ;
}
F_23 ( V_6 , F_3 ( V_58
L_117
L_118 , V_6 -> V_35 ,
V_27 , V_88 , F_9 ( V_29 -> V_38 ) ,
F_76 ( V_29 -> V_337 ) ,
F_76 ( V_29 -> V_338 ) ) ) ;
return F_158 ( V_6 , V_88 ) ;
}
static T_6
F_159 ( struct V_5 * V_6 , T_4 V_88 , T_6 V_292 ,
T_10 V_293 )
{
T_4 V_27 ;
T_20 * V_392 ;
T_21 * V_29 =
F_106 ( V_6 , V_293 ) ;
T_24 * V_103 ;
T_4 V_393 ;
T_10 V_310 ;
if ( V_6 -> V_318 ) {
F_23 ( V_6 , F_3 ( V_58 L_100
L_119 , V_36 , V_6 -> V_35 ) ) ;
return 1 ;
} else if ( V_6 -> V_319 ) {
F_23 ( V_6 , F_3 ( V_58 L_102
L_120 , V_36 , V_6 -> V_35 ) ) ;
return 1 ;
}
V_310 = F_113 ( V_6 , 1 ) ;
if ( V_310 != V_386 ) {
F_23 ( V_6 , F_3 ( V_58 L_104
L_121 , V_36 , V_6 -> V_35 ) ) ;
return 1 ;
}
V_392 = F_48 ( V_6 , V_88 ) ;
V_27 = F_9 ( V_392 -> V_233 ) ;
if ( V_27 != F_9 ( V_29 -> V_233 ) ) {
F_23 ( V_6 , F_3 ( V_58 L_115
L_116 , V_6 -> V_35 , V_27 ,
F_9 ( V_29 -> V_233 ) , V_88 ) ) ;
return 0 ;
}
F_23 ( V_6 , F_3 ( V_58
L_117
L_118 , V_6 -> V_35 ,
V_27 , V_88 , F_9 ( V_29 -> V_38 ) ,
F_76 ( V_29 -> V_337 ) ,
F_76 ( V_29 -> V_338 ) ) ) ;
V_393 = F_160 ( V_6 , V_6 -> V_394 ) ;
if ( ! V_393 ) {
F_3 ( V_34 L_69 ,
V_6 -> V_35 , V_36 ) ;
return 1 ;
}
F_23 ( V_6 , F_3 ( V_58 L_122
L_110 , V_6 -> V_35 , V_27 , V_393 ,
V_6 -> V_394 ) ) ;
V_103 = F_48 ( V_6 , V_393 ) ;
memset ( V_103 , 0 , sizeof( T_24 ) ) ;
V_103 -> V_329 = V_395 ;
V_103 -> V_396 = V_397 ;
V_103 -> V_233 = V_392 -> V_233 ;
F_161 ( V_6 , V_393 ) ;
return F_158 ( V_6 , V_88 ) ;
}
static T_6
F_158 ( struct V_5 * V_6 , T_4 V_88 )
{
struct V_384 * V_385 ;
if ( ! F_43 ( & V_6 -> V_391 ) ) {
V_385 = F_45 ( V_6 -> V_391 . V_100 ,
struct V_384 , V_67 ) ;
F_162 ( V_6 , V_88 ) ;
F_156 ( V_6 , V_385 -> V_27 ) ;
F_19 ( & V_385 -> V_67 ) ;
F_20 ( V_385 ) ;
return 0 ;
}
if ( ! F_43 ( & V_6 -> V_389 ) ) {
V_385 = F_45 ( V_6 -> V_389 . V_100 ,
struct V_384 , V_67 ) ;
F_162 ( V_6 , V_88 ) ;
F_152 ( V_6 , V_385 -> V_27 ) ;
F_19 ( & V_385 -> V_67 ) ;
F_20 ( V_385 ) ;
return 0 ;
}
return 1 ;
}
static void
F_163 ( struct V_5 * V_6 ,
T_22 * V_360 )
{
struct V_353 * V_354 ;
T_22 * V_398 ;
T_4 V_399 ;
struct V_78 * V_79 ;
unsigned long V_65 ;
int V_92 , V_375 ;
T_4 V_27 ;
for ( V_92 = 0 ; V_92 < V_360 -> V_377 ; V_92 ++ ) {
V_27 = F_9 ( V_360 -> V_378 [ V_92 ] . V_379 ) ;
if ( ! V_27 )
continue;
V_375 = V_360 -> V_378 [ V_92 ] . V_381 &
V_382 ;
if ( V_375 == V_400 )
F_152 ( V_6 , V_27 ) ;
}
V_399 = F_9 ( V_360 -> V_401 ) ;
if ( V_399 < V_6 -> V_31 . V_32 ) {
F_151 ( V_6 , V_360 ) ;
return;
}
if ( V_360 -> V_402 == V_403
|| V_360 -> V_402 == V_404 ) {
F_18 ( & V_6 -> V_80 , V_65 ) ;
V_79 = F_33 ( V_6 ,
V_399 ) ;
F_21 ( & V_6 -> V_80 , V_65 ) ;
F_150 ( V_6 , V_79 ) ;
} else if ( V_360 -> V_402 == V_405 )
F_151 ( V_6 , V_360 ) ;
if ( V_360 -> V_402 != V_404 )
return;
F_18 ( & V_6 -> V_356 , V_65 ) ;
F_4 (fw_event, &ioc->fw_event_list, list) {
if ( V_354 -> V_362 != V_406 ||
V_354 -> V_407 )
continue;
V_398 = V_354 -> V_360 ;
if ( V_398 -> V_402 ==
V_408 ||
V_398 -> V_402 ==
V_405 ) {
if ( F_9 ( V_398 -> V_401 ) ==
V_399 ) {
F_23 ( V_6 , F_3 ( V_58
L_123 , V_6 -> V_35 ) ) ;
V_354 -> V_407 = 1 ;
}
}
}
F_21 ( & V_6 -> V_356 , V_65 ) ;
}
static void
F_164 ( struct V_5 * V_6 , T_4 V_27 )
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
V_148 -> V_387 = 1 ;
F_23 ( V_6 , F_3 ( V_58
L_124
L_125 , V_6 -> V_35 , V_27 ,
( unsigned long long ) V_48 -> V_52 ) ) ;
}
F_21 ( & V_6 -> V_76 , V_65 ) ;
}
static void
F_165 ( T_4 V_27 , T_4 * V_409 , T_4 * V_410 )
{
if ( ! V_27 || V_27 == * V_409 || V_27 == * V_410 )
return;
if ( ! * V_409 )
* V_409 = V_27 ;
else if ( ! * V_410 )
* V_410 = V_27 ;
}
static void
F_166 ( struct V_5 * V_6 ,
T_25 * V_360 )
{
T_26 * V_411 ;
int V_92 ;
T_4 V_27 , V_272 , V_409 , V_410 ;
struct V_384 * V_385 ;
V_409 = 0 ;
V_410 = 0 ;
if ( V_6 -> V_190 )
return;
V_411 = ( T_26 * ) & V_360 -> V_412 [ 0 ] ;
for ( V_92 = 0 ; V_92 < V_360 -> V_413 ; V_92 ++ , V_411 ++ ) {
if ( V_411 -> V_414 ==
V_415 ||
V_411 -> V_414 ==
V_416 ) {
V_272 = F_9 ( V_411 -> V_417 ) ;
F_164 ( V_6 , V_272 ) ;
F_165 ( V_272 , & V_409 , & V_410 ) ;
}
}
V_411 = ( T_26 * ) & V_360 -> V_412 [ 0 ] ;
for ( V_92 = 0 ; V_92 < V_360 -> V_413 ; V_92 ++ , V_411 ++ ) {
if ( F_76 ( V_360 -> V_182 ) &
V_418 )
continue;
if ( V_411 -> V_414 == V_419 ) {
V_272 = F_9 ( V_411 -> V_417 ) ;
F_165 ( V_272 , & V_409 , & V_410 ) ;
}
}
if ( V_409 )
F_156 ( V_6 , V_409 ) ;
if ( V_410 )
F_156 ( V_6 , V_410 ) ;
V_411 = ( T_26 * ) & V_360 -> V_412 [ 0 ] ;
for ( V_92 = 0 ; V_92 < V_360 -> V_413 ; V_92 ++ , V_411 ++ ) {
if ( V_411 -> V_414 != V_419 )
continue;
V_27 = F_9 ( V_411 -> V_420 ) ;
V_272 = F_9 ( V_411 -> V_417 ) ;
F_167 ( V_27 , V_6 -> V_177 ) ;
if ( ! V_272 )
F_152 ( V_6 , V_27 ) ;
else if ( V_272 == V_409 || V_272 == V_410 ) {
V_385 = F_69 ( sizeof( * V_385 ) , V_361 ) ;
F_168 ( ! V_385 ) ;
F_153 ( & V_385 -> V_67 ) ;
V_385 -> V_27 = V_27 ;
F_24 ( & V_385 -> V_67 , & V_6 -> V_389 ) ;
F_23 ( V_6 , F_3 ( V_58
L_108 , V_6 -> V_35 ,
V_27 ) ) ;
} else
F_152 ( V_6 , V_27 ) ;
}
}
static void
F_169 ( struct V_5 * V_6 ,
T_27 * V_360 )
{
T_10 V_200 ;
if ( V_360 -> V_414 != V_421 )
return;
V_200 = F_76 ( V_360 -> V_422 ) ;
if ( V_200 == V_210 || V_200 ==
V_209 )
F_164 ( V_6 ,
F_9 ( V_360 -> V_417 ) ) ;
}
static void
F_170 ( struct V_5 * V_6 )
{
struct V_87 * V_90 ;
T_4 V_88 ;
T_4 V_238 = 0 ;
for ( V_88 = 1 ; V_88 <= V_6 -> V_93 ; V_88 ++ ) {
V_90 = F_38 ( V_6 , V_88 ) ;
if ( ! V_90 )
continue;
V_238 ++ ;
F_162 ( V_6 , V_88 ) ;
F_171 ( V_90 ) ;
if ( V_6 -> V_319 )
V_90 -> V_348 = V_349 << 16 ;
else
V_90 -> V_348 = V_351 << 16 ;
V_90 -> V_350 ( V_90 ) ;
}
F_118 ( V_6 , F_3 ( V_58 L_126 ,
V_6 -> V_35 , V_238 ) ) ;
}
static void
F_172 ( struct V_87 * V_90 , T_11 * V_103 )
{
T_4 V_423 ;
unsigned char V_424 = F_173 ( V_90 ) ;
unsigned char V_425 = F_174 ( V_90 ) ;
if ( V_425 == V_426 || V_424 == V_427 )
return;
if ( V_424 == V_428 )
V_423 = V_429 ;
else if ( V_424 == V_430 )
V_423 = V_431 ;
else
return;
switch ( V_425 ) {
case V_432 :
case V_433 :
V_423 |= V_434 |
V_435 |
V_436 ;
V_103 -> V_437 . V_438 . V_439 =
F_175 ( F_176 ( V_90 ) ) ;
break;
case V_440 :
V_423 |= V_436 ;
break;
}
V_103 -> V_441 = F_177 ( V_90 -> V_43 -> V_442 ) ;
V_103 -> V_443 = F_119 ( V_423 ) ;
}
static void
F_178 ( struct V_87 * V_90 , T_4 V_30 )
{
T_6 V_444 ;
T_6 V_445 ;
T_6 V_446 ;
switch ( V_30 ) {
case V_447 :
V_444 = 0x01 ;
break;
case V_448 :
V_444 = 0x02 ;
break;
case V_449 :
V_444 = 0x03 ;
break;
default:
V_444 = 0x00 ;
break;
}
if ( V_90 -> V_118 == V_119 ) {
V_445 = V_450 ;
V_446 = V_451 ;
} else {
V_445 = V_452 ;
V_446 = V_453 ;
}
F_179 ( 0 , V_90 -> V_454 , V_445 , 0x10 , V_444 ) ;
V_90 -> V_348 = V_455 << 24 | ( V_446 << 16 ) |
V_456 ;
}
static inline T_6
F_180 ( struct V_5 * V_6 , T_4 V_88 )
{
return V_6 -> V_89 [ V_88 - 1 ] . V_457 ;
}
static inline void
F_181 ( struct V_5 * V_6 , T_4 V_88 , T_6 V_457 )
{
V_6 -> V_89 [ V_88 - 1 ] . V_457 = V_457 ;
}
static void
F_182 ( struct V_5 * V_6 , struct V_87 * V_90 ,
struct V_47 * V_48 , T_11 * V_103 ,
T_4 V_88 )
{
T_10 V_458 , V_459 , V_460 , V_461 , V_462 , V_463 ;
T_10 V_239 , V_241 ;
T_6 V_227 , * V_464 , V_92 ;
T_6 V_465 = V_90 -> V_466 [ 0 ] ;
T_1 V_467 ;
if ( V_465 == V_468 || V_465 == V_469 ||
V_465 == V_470 || V_465 == V_471 ) {
V_464 = V_103 -> V_437 . V_472 ;
if ( ( V_465 < V_468 ) || ! ( V_464 [ 2 ] | V_464 [ 3 ] | V_464 [ 4 ]
| V_464 [ 5 ] ) ) {
V_463 = F_52 ( V_90 ) >>
V_48 -> V_253 ;
V_92 = ( V_465 < V_468 ) ? 2 : 6 ;
V_458 = F_183 ( * ( V_473 * ) ( & V_464 [ V_92 ] ) ) ;
if ( ( ( T_1 ) V_458 + ( T_1 ) V_463 - 1 ) <=
( T_10 ) V_48 -> V_254 ) {
V_239 = V_48 -> V_239 ;
V_241 = V_48 -> V_252 ;
V_460 = V_458 & ( V_239 - 1 ) ;
if ( ( V_460 + V_463 ) <= V_239 ) {
V_227 = V_48 -> V_227 ;
V_459 = V_458 >> V_241 ;
V_461 = V_459 / V_227 ;
V_462 = V_459 % V_227 ;
V_459 = ( V_461 << V_241 ) +
V_460 ;
V_103 -> V_233 =
F_119 ( V_48 ->
V_249 [ V_462 ] ) ;
( * ( V_473 * ) ( & V_464 [ V_92 ] ) ) =
F_175 ( V_459 ) ;
F_181 ( V_6 , V_88 , 1 ) ;
}
}
} else {
V_463 = F_52 ( V_90 ) >>
V_48 -> V_253 ;
V_467 = F_184 ( * ( V_474 * ) ( & V_464 [ 2 ] ) ) ;
if ( ( V_467 + ( T_1 ) V_463 - 1 ) <=
V_48 -> V_254 ) {
V_239 = V_48 -> V_239 ;
V_241 = V_48 -> V_252 ;
V_460 = ( T_10 ) ( V_467 & ( V_239 - 1 ) ) ;
if ( ( V_460 + V_463 ) <= V_239 ) {
V_227 = V_48 -> V_227 ;
V_459 = ( T_10 ) ( V_467 >> V_241 ) ;
V_461 = V_459 / V_227 ;
V_462 = V_459 % V_227 ;
V_459 = ( V_461 << V_241 ) +
V_460 ;
V_103 -> V_233 =
F_119 ( V_48 ->
V_249 [ V_462 ] ) ;
( * ( V_474 * ) ( & V_464 [ 2 ] ) ) =
F_185 ( ( T_1 ) V_459 ) ;
F_181 ( V_6 , V_88 , 1 ) ;
}
}
}
}
}
static int
F_186 ( struct V_87 * V_90 , void (* V_301)( struct V_87 * ) )
{
struct V_5 * V_6 = F_58 ( V_90 -> V_43 -> V_143 ) ;
struct V_145 * V_146 ;
struct V_147 * V_148 ;
struct V_47 * V_48 ;
T_11 * V_103 ;
T_10 V_475 ;
T_4 V_88 ;
V_90 -> V_350 = V_301 ;
V_146 = V_90 -> V_43 -> V_150 ;
if ( ! V_146 || ! V_146 -> V_152 ) {
V_90 -> V_348 = V_349 << 16 ;
V_90 -> V_350 ( V_90 ) ;
return 0 ;
}
if ( V_6 -> V_319 || V_6 -> V_318 ) {
V_90 -> V_348 = V_349 << 16 ;
V_90 -> V_350 ( V_90 ) ;
return 0 ;
}
V_148 = V_146 -> V_152 ;
if ( V_148 -> V_27 == V_173 ) {
V_90 -> V_348 = V_349 << 16 ;
V_90 -> V_350 ( V_90 ) ;
return 0 ;
}
if ( V_6 -> V_317 || V_6 -> V_476 )
return V_477 ;
else if ( V_146 -> V_366 || V_148 -> V_303 )
return V_478 ;
else if ( V_148 -> V_387 ) {
V_90 -> V_348 = V_349 << 16 ;
V_90 -> V_350 ( V_90 ) ;
return 0 ;
}
if ( V_90 -> V_118 == V_479 )
V_475 = V_480 ;
else if ( V_90 -> V_118 == V_119 )
V_475 = V_481 ;
else
V_475 = V_482 ;
if ( ! ( V_146 -> V_65 & V_179 ) ) {
if ( V_90 -> V_43 -> V_155 ) {
if ( V_90 -> V_43 -> V_164 )
V_475 |= V_483 ;
else
V_475 |= V_484 ;
} else
V_475 |= ( 0x500 ) ;
} else
V_475 |= V_484 ;
if ( ! V_6 -> V_190 && ! F_77 ( & V_90 -> V_43 -> V_224 ) &&
F_96 ( V_90 -> V_43 ) && V_90 -> V_485 != 32 )
V_475 |= V_486 ;
V_88 = F_187 ( V_6 , V_6 -> V_487 , V_90 ) ;
if ( ! V_88 ) {
F_3 ( V_34 L_69 ,
V_6 -> V_35 , V_36 ) ;
goto V_75;
}
V_103 = F_48 ( V_6 , V_88 ) ;
memset ( V_103 , 0 , sizeof( T_11 ) ) ;
F_172 ( V_90 , V_103 ) ;
if ( V_90 -> V_485 == 32 )
V_475 |= 4 << V_488 ;
V_103 -> V_329 = V_489 ;
if ( V_146 -> V_152 -> V_65 &
V_178 )
V_103 -> V_329 = V_490 ;
else
V_103 -> V_329 = V_489 ;
V_103 -> V_233 =
F_119 ( V_146 -> V_152 -> V_27 ) ;
V_103 -> V_491 = F_177 ( F_52 ( V_90 ) ) ;
V_103 -> V_492 = F_177 ( V_475 ) ;
V_103 -> V_493 = F_119 ( V_90 -> V_485 ) ;
V_103 -> V_494 = V_495 ;
V_103 -> V_496 = V_497 ;
V_103 -> V_498 =
F_188 ( V_6 , V_88 ) ;
V_103 -> V_499 = F_53 ( T_11 , V_127 ) / 4 ;
V_103 -> V_500 = F_119 ( V_501 +
V_502 ) ;
V_103 -> V_503 = 0 ;
V_103 -> V_504 = 0 ;
F_120 ( V_146 -> V_95 , (struct V_333 * )
V_103 -> V_334 ) ;
memcpy ( V_103 -> V_437 . V_472 , V_90 -> V_466 , V_90 -> V_485 ) ;
if ( ! V_103 -> V_491 ) {
F_189 ( V_6 , & V_103 -> V_127 ) ;
} else {
if ( F_47 ( V_6 , V_90 , V_88 ) ) {
F_162 ( V_6 , V_88 ) ;
goto V_75;
}
}
V_48 = V_148 -> V_48 ;
if ( V_48 && V_48 -> V_236 )
F_182 ( V_6 , V_90 , V_48 , V_103 ,
V_88 ) ;
if ( F_190 ( V_103 -> V_329 == V_489 ) )
F_191 ( V_6 , V_88 ,
F_9 ( V_103 -> V_233 ) ) ;
else
F_161 ( V_6 , V_88 ) ;
return 0 ;
V_75:
return V_477 ;
}
void
F_192 ( struct V_5 * V_6 , struct V_87 * V_90 ,
T_28 * V_29 , T_4 V_88 )
{
T_10 V_505 ;
T_6 * V_506 ;
T_4 V_30 = F_9 ( V_29 -> V_38 ) &
V_39 ;
T_6 V_507 = V_29 -> V_508 ;
T_6 V_509 = V_29 -> V_510 ;
char * V_511 = NULL ;
char * V_512 = NULL ;
char * V_513 = V_6 -> V_514 ;
T_10 V_515 = F_76 ( V_29 -> V_337 ) ;
struct V_45 * V_46 = NULL ;
unsigned long V_65 ;
struct V_168 * V_70 = V_90 -> V_43 -> V_345 ;
struct V_147 * V_346 = V_70 -> V_150 ;
char * V_347 = NULL ;
if ( ! V_346 )
return;
if ( V_6 -> V_271 )
V_347 = L_75 ;
else
V_347 = L_76 ;
if ( V_515 == 0x31170000 )
return;
switch ( V_30 ) {
case V_40 :
V_511 = L_127 ;
break;
case V_516 :
V_511 = L_128 ;
break;
case V_517 :
V_511 = L_129 ;
break;
case V_518 :
V_511 = L_130 ;
break;
case V_519 :
V_511 = L_131 ;
break;
case V_520 :
V_511 = L_132 ;
break;
case V_521 :
V_511 = L_133 ;
break;
case V_522 :
V_511 = L_134 ;
break;
case V_523 :
V_511 = L_135 ;
break;
case V_524 :
V_511 = L_136 ;
break;
case V_525 :
V_511 = L_137 ;
break;
case V_526 :
V_511 = L_138 ;
break;
case V_527 :
V_511 = L_139 ;
break;
case V_528 :
V_511 = L_140 ;
break;
case V_447 :
V_511 = L_141 ;
break;
case V_449 :
V_511 = L_142 ;
break;
case V_448 :
V_511 = L_143 ;
break;
default:
V_511 = L_63 ;
break;
}
switch ( V_509 ) {
case V_529 :
V_512 = L_144 ;
break;
case V_530 :
V_512 = L_145 ;
break;
case V_531 :
V_512 = L_146 ;
break;
case V_532 :
V_512 = L_147 ;
break;
case V_533 :
V_512 = L_148 ;
break;
case V_534 :
V_512 = L_149 ;
break;
case V_535 :
V_512 = L_150 ;
break;
case V_536 :
V_512 = L_151 ;
break;
case V_537 :
V_512 = L_152 ;
break;
case V_538 :
V_512 = L_153 ;
break;
case V_539 :
V_512 = L_154 ;
break;
default:
V_512 = L_63 ;
break;
}
V_513 [ 0 ] = '\0' ;
if ( ! V_507 )
V_513 = L_155 ;
if ( V_507 & V_540 )
strcat ( V_513 , L_156 ) ;
if ( V_507 & V_541 )
strcat ( V_513 , L_157 ) ;
if ( V_507 & V_542 )
strcat ( V_513 , L_158 ) ;
if ( V_507 & V_543 )
strcat ( V_513 , L_159 ) ;
if ( V_507 & V_544 )
strcat ( V_513 , L_160 ) ;
F_127 ( V_90 ) ;
if ( V_346 -> V_65 & V_153 ) {
F_3 ( V_99 L_161 , V_6 -> V_35 ,
V_347 , ( unsigned long long ) V_346 -> V_9 ) ;
} else {
F_18 ( & V_6 -> V_66 , V_65 ) ;
V_46 = F_15 ( V_6 ,
V_346 -> V_9 ) ;
if ( V_46 ) {
F_3 ( V_99 L_162
L_163 , V_6 -> V_35 , V_46 -> V_9 ,
V_46 -> V_274 ) ;
F_3 ( V_99
L_164 ,
V_6 -> V_35 , V_46 -> V_14 ,
V_46 -> V_18 ) ;
}
F_21 ( & V_6 -> V_66 , V_65 ) ;
}
F_3 ( V_99 L_165
L_166 , V_6 -> V_35 , F_9 ( V_29 -> V_233 ) ,
V_511 , V_30 , V_88 ) ;
F_3 ( V_99 L_167
L_168 , V_6 -> V_35 , F_52 ( V_90 ) , V_90 -> V_545 ,
F_193 ( V_90 ) ) ;
F_3 ( V_99 L_169
L_170 , V_6 -> V_35 , F_9 ( V_29 -> V_546 ) ,
F_76 ( V_29 -> V_547 ) , V_90 -> V_348 ) ;
F_3 ( V_99 L_171
L_172 , V_6 -> V_35 , V_512 ,
V_509 , V_513 , V_507 ) ;
if ( V_507 & V_544 ) {
struct V_548 V_549 ;
F_194 ( V_90 -> V_454 , & V_549 ) ;
F_3 ( V_99 L_173
L_174 , V_6 -> V_35 , V_549 . V_550 ,
V_549 . V_551 , V_549 . V_444 , F_76 ( V_29 -> V_552 ) ) ;
}
if ( V_507 & V_540 ) {
V_505 = F_76 ( V_29 -> V_553 ) ;
V_506 = ( T_6 * ) & V_505 ;
F_103 ( V_6 , V_506 [ 0 ] ) ;
}
}
static void
F_195 ( struct V_5 * V_6 , T_4 V_27 )
{
T_29 V_29 ;
T_30 V_103 ;
memset ( & V_103 , 0 , sizeof( T_30 ) ) ;
V_103 . V_329 = V_554 ;
V_103 . V_555 = V_556 ;
V_103 . V_557 =
F_177 ( V_558 ) ;
V_103 . V_233 = F_119 ( V_27 ) ;
V_103 . V_182 = V_559 ;
if ( ( F_196 ( V_6 , & V_29 ,
& V_103 ) ) != 0 ) {
F_3 ( V_34 L_2 , V_6 -> V_35 ,
__FILE__ , __LINE__ , V_36 ) ;
return;
}
if ( V_29 . V_38 || V_29 . V_337 ) {
F_23 ( V_6 , F_3 ( V_58 L_175
L_176 , V_6 -> V_35 ,
F_9 ( V_29 . V_38 ) ,
F_76 ( V_29 . V_337 ) ) ) ;
return;
}
}
static void
F_197 ( struct V_5 * V_6 , T_4 V_27 )
{
struct V_353 * V_354 ;
V_354 = F_69 ( sizeof( struct V_353 ) , V_361 ) ;
if ( ! V_354 )
return;
V_354 -> V_362 = V_560 ;
V_354 -> V_561 = V_27 ;
V_354 -> V_6 = V_6 ;
F_134 ( V_6 , V_354 ) ;
}
static void
F_198 ( struct V_5 * V_6 , T_4 V_27 )
{
struct V_168 * V_70 ;
struct V_147 * V_148 ;
T_31 * V_562 ;
T_32 * V_360 ;
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
F_128 ( V_563 , V_70 , L_177 ) ;
F_21 ( & V_6 -> V_66 , V_65 ) ;
if ( V_6 -> V_564 -> V_565 == V_566 )
F_197 ( V_6 , V_27 ) ;
V_226 = F_53 ( T_31 , V_567 ) +
sizeof( T_32 ) ;
V_562 = F_69 ( V_226 , V_361 ) ;
if ( ! V_562 ) {
F_3 ( V_34 L_2 ,
V_6 -> V_35 , __FILE__ , __LINE__ , V_36 ) ;
return;
}
V_562 -> V_329 = V_568 ;
V_562 -> V_569 =
F_119 ( V_570 ) ;
V_562 -> V_298 = V_226 / 4 ;
V_562 -> V_571 =
F_119 ( sizeof( T_32 ) / 4 ) ;
V_360 = ( T_32 * )
V_562 -> V_567 ;
V_360 -> V_414 = V_572 ;
V_360 -> V_573 = 0x5D ;
V_360 -> V_233 = F_119 ( V_27 ) ;
V_360 -> V_11 = F_199 ( V_148 -> V_9 ) ;
F_200 ( V_6 , V_562 ) ;
F_20 ( V_562 ) ;
}
static T_6
F_201 ( struct V_5 * V_6 , T_4 V_88 , T_6 V_292 , T_10 V_293 )
{
T_11 * V_103 ;
T_28 * V_29 ;
struct V_87 * V_90 ;
T_4 V_30 ;
T_10 V_574 ;
T_6 V_507 ;
T_6 V_509 ;
T_10 V_515 ;
struct V_145 * V_146 ;
T_10 V_283 = 0 ;
unsigned long V_65 ;
V_29 = F_106 ( V_6 , V_293 ) ;
V_90 = F_38 ( V_6 , V_88 ) ;
if ( V_90 == NULL )
return 1 ;
V_103 = F_48 ( V_6 , V_88 ) ;
if ( V_29 == NULL ) {
V_90 -> V_348 = V_453 << 16 ;
goto V_75;
}
V_146 = V_90 -> V_43 -> V_150 ;
if ( ! V_146 || ! V_146 -> V_152 ||
V_146 -> V_152 -> V_387 ) {
V_90 -> V_348 = V_349 << 16 ;
goto V_75;
}
V_30 = F_9 ( V_29 -> V_38 ) ;
if ( F_180 ( V_6 , V_88 ) &&
( ( V_30 & V_39 )
!= V_524 ) ) {
F_18 ( & V_6 -> V_91 , V_65 ) ;
V_6 -> V_89 [ V_88 - 1 ] . V_90 = V_90 ;
F_21 ( & V_6 -> V_91 , V_65 ) ;
F_181 ( V_6 , V_88 , 0 ) ;
memcpy ( V_103 -> V_437 . V_472 , V_90 -> V_466 , V_90 -> V_485 ) ;
V_103 -> V_233 =
F_119 ( V_146 -> V_152 -> V_27 ) ;
F_191 ( V_6 , V_88 ,
V_146 -> V_152 -> V_27 ) ;
return 0 ;
}
V_507 = V_29 -> V_508 ;
if ( V_507 & V_540 )
V_283 =
F_76 ( V_29 -> V_553 ) & 0xFF ;
if ( ! V_146 -> V_575 ) {
V_146 -> V_575 ++ ;
if ( ! V_6 -> V_190 && ! F_77 ( & V_90 -> V_43 -> V_224 ) &&
F_96 ( V_90 -> V_43 ) &&
V_283 == V_286 ) {
F_202 ( V_90 -> V_43 ) ;
F_51 ( V_7 , V_90 -> V_43 , L_178 ) ;
}
}
V_574 = F_76 ( V_29 -> V_547 ) ;
F_203 ( V_90 , F_52 ( V_90 ) - V_574 ) ;
if ( V_30 & V_576 )
V_515 = F_76 ( V_29 -> V_337 ) ;
else
V_515 = 0 ;
V_30 &= V_39 ;
V_509 = V_29 -> V_510 ;
if ( V_30 == V_521 && V_574 == 0 &&
( V_509 == V_532 ||
V_509 == V_535 ||
V_509 == V_537 ) ) {
V_30 = V_40 ;
}
if ( V_507 & V_544 ) {
struct V_548 V_549 ;
const void * V_577 = F_204 ( V_6 ,
V_88 ) ;
T_10 V_226 = F_205 ( T_10 , V_497 ,
F_76 ( V_29 -> V_552 ) ) ;
memcpy ( V_90 -> V_454 , V_577 , V_226 ) ;
F_194 ( V_90 -> V_454 , & V_549 ) ;
if ( V_549 . V_551 == 0x5D )
F_198 ( V_6 ,
F_9 ( V_29 -> V_233 ) ) ;
}
switch ( V_30 ) {
case V_578 :
case V_579 :
V_90 -> V_348 = V_580 ;
break;
case V_519 :
V_90 -> V_348 = V_349 << 16 ;
break;
case V_527 :
if ( V_146 -> V_366 ) {
V_90 -> V_348 = V_581 << 16 ;
goto V_75;
}
V_90 -> V_348 = V_582 << 16 ;
break;
case V_524 :
case V_528 :
V_90 -> V_348 = V_351 << 16 ;
break;
case V_525 :
if ( ( V_574 == 0 ) || ( V_90 -> V_545 > V_574 ) )
V_90 -> V_348 = V_582 << 16 ;
else
V_90 -> V_348 = ( V_453 << 16 ) | V_509 ;
break;
case V_521 :
V_90 -> V_348 = ( V_453 << 16 ) | V_509 ;
if ( ( V_507 & V_544 ) )
break;
if ( V_574 < V_90 -> V_545 ) {
if ( V_509 == V_580 )
V_90 -> V_348 = V_580 ;
else
V_90 -> V_348 = V_582 << 16 ;
} else if ( V_507 & ( V_543 |
V_542 ) )
V_90 -> V_348 = V_582 << 16 ;
else if ( V_507 & V_541 )
V_90 -> V_348 = V_351 << 16 ;
else if ( ! V_574 && V_90 -> V_466 [ 0 ] == V_583 ) {
V_29 -> V_508 = V_544 ;
V_29 -> V_510 = V_456 ;
V_90 -> V_348 = ( V_455 << 24 ) |
V_456 ;
V_90 -> V_454 [ 0 ] = 0x70 ;
V_90 -> V_454 [ 2 ] = V_450 ;
V_90 -> V_454 [ 12 ] = 0x20 ;
V_90 -> V_454 [ 13 ] = 0 ;
}
break;
case V_520 :
F_203 ( V_90 , 0 ) ;
case V_517 :
case V_40 :
V_90 -> V_348 = ( V_453 << 16 ) | V_509 ;
if ( V_283 ==
V_286 ||
( V_507 & ( V_543 |
V_542 ) ) )
V_90 -> V_348 = V_582 << 16 ;
else if ( V_507 & V_541 )
V_90 -> V_348 = V_351 << 16 ;
break;
case V_447 :
case V_449 :
case V_448 :
F_178 ( V_90 , V_30 ) ;
break;
case V_523 :
case V_516 :
case V_584 :
case V_585 :
case V_586 :
case V_587 :
case V_522 :
case V_526 :
default:
V_90 -> V_348 = V_582 << 16 ;
break;
}
#ifdef F_155
if ( V_90 -> V_348 && ( V_6 -> V_8 & V_588 ) )
F_192 ( V_6 , V_90 , V_29 , V_88 ) ;
#endif
V_75:
F_171 ( V_90 ) ;
V_90 -> V_350 ( V_90 ) ;
return 1 ;
}
static void
F_206 ( struct V_5 * V_6 )
{
T_4 V_226 ;
T_4 V_30 ;
int V_92 ;
T_9 V_29 ;
T_34 * V_589 = NULL ;
T_4 V_590 ;
T_6 V_591 ;
F_118 ( V_6 , F_3 ( V_58
L_179 ,
V_6 -> V_35 , ( unsigned long long ) V_6 -> V_31 . V_9 ) ) ;
V_226 = F_53 ( T_34 , V_592 ) + ( V_6 -> V_31 . V_32
* sizeof( V_593 ) ) ;
V_589 = F_69 ( V_226 , V_172 ) ;
if ( ! V_589 ) {
F_3 ( V_34 L_2 ,
V_6 -> V_35 , __FILE__ , __LINE__ , V_36 ) ;
return;
}
if ( ( F_207 ( V_6 , & V_29 ,
V_589 , V_226 ) ) != 0 )
goto V_75;
V_30 = F_9 ( V_29 . V_38 ) & V_39 ;
if ( V_30 != V_40 )
goto V_75;
for ( V_92 = 0 ; V_92 < V_6 -> V_31 . V_32 ; V_92 ++ ) {
V_591 = V_589 -> V_592 [ V_92 ] . V_594 >> 4 ;
if ( V_92 == 0 )
V_6 -> V_31 . V_27 = F_9 ( V_589 ->
V_592 [ 0 ] . V_595 ) ;
V_6 -> V_31 . V_274 [ V_92 ] . V_27 = V_6 -> V_31 . V_27 ;
V_590 = F_9 ( V_589 -> V_592 [ V_92 ] .
V_379 ) ;
if ( V_590 && V_591 < V_596 )
V_591 = V_596 ;
F_208 ( V_6 , V_6 -> V_31 . V_9 ,
V_590 , V_92 , V_591 ) ;
}
V_75:
F_20 ( V_589 ) ;
}
static void
F_209 ( struct V_5 * V_6 )
{
int V_92 ;
T_9 V_29 ;
T_34 * V_589 = NULL ;
T_35 * V_597 = NULL ;
T_36 V_598 ;
T_8 V_28 ;
T_37 V_599 ;
T_4 V_30 ;
T_4 V_226 ;
T_4 V_600 ;
F_210 ( V_6 , & V_6 -> V_31 . V_32 ) ;
if ( ! V_6 -> V_31 . V_32 ) {
F_3 ( V_34 L_2 ,
V_6 -> V_35 , __FILE__ , __LINE__ , V_36 ) ;
return;
}
V_226 = F_53 ( T_34 , V_592 ) + ( V_6 -> V_31 . V_32 *
sizeof( V_593 ) ) ;
V_589 = F_69 ( V_226 , V_172 ) ;
if ( ! V_589 ) {
F_3 ( V_34 L_2 ,
V_6 -> V_35 , __FILE__ , __LINE__ , V_36 ) ;
return;
}
if ( ( F_207 ( V_6 , & V_29 ,
V_589 , V_226 ) ) ) {
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
V_226 = F_53 ( T_35 , V_592 ) + ( V_6 -> V_31 . V_32 *
sizeof( V_601 ) ) ;
V_597 = F_69 ( V_226 , V_172 ) ;
if ( ! V_597 ) {
F_3 ( V_34 L_2 ,
V_6 -> V_35 , __FILE__ , __LINE__ , V_36 ) ;
goto V_75;
}
if ( ( F_211 ( V_6 , & V_29 ,
V_597 , V_226 ) ) ) {
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
V_6 -> V_602 =
F_9 ( V_597 -> V_603 ) ;
V_600 =
F_9 ( V_597 -> V_604 ) ;
if ( V_600 & V_605 )
V_6 -> V_600 = ( V_600 &
V_606 ) * 16 ;
else
V_6 -> V_600 = V_600 &
V_606 ;
V_6 -> V_31 . V_607 = & V_6 -> V_142 -> V_608 ;
V_6 -> V_31 . V_274 = F_212 ( V_6 -> V_31 . V_32 ,
sizeof( struct V_609 ) , V_172 ) ;
if ( ! V_6 -> V_31 . V_274 ) {
F_3 ( V_34 L_2 ,
V_6 -> V_35 , __FILE__ , __LINE__ , V_36 ) ;
goto V_75;
}
for ( V_92 = 0 ; V_92 < V_6 -> V_31 . V_32 ; V_92 ++ ) {
if ( ( F_213 ( V_6 , & V_29 , & V_598 ,
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
V_6 -> V_31 . V_27 = F_9 ( V_589 ->
V_592 [ 0 ] . V_595 ) ;
V_6 -> V_31 . V_274 [ V_92 ] . V_27 = V_6 -> V_31 . V_27 ;
V_6 -> V_31 . V_274 [ V_92 ] . V_610 = V_92 ;
F_214 ( V_6 , & V_6 -> V_31 . V_274 [ V_92 ] ,
V_598 , V_6 -> V_31 . V_607 ) ;
}
if ( ( F_12 ( V_6 , & V_29 , & V_28 ,
V_33 , V_6 -> V_31 . V_27 ) ) ) {
F_3 ( V_34 L_2 ,
V_6 -> V_35 , __FILE__ , __LINE__ , V_36 ) ;
goto V_75;
}
V_6 -> V_31 . V_611 =
F_9 ( V_28 . V_612 ) ;
V_6 -> V_31 . V_9 = F_6 ( V_28 . V_11 ) ;
F_3 ( V_58 L_180
L_181 , V_6 -> V_35 , V_6 -> V_31 . V_27 ,
( unsigned long long ) V_6 -> V_31 . V_9 ,
V_6 -> V_31 . V_32 ) ;
if ( V_6 -> V_31 . V_611 ) {
if ( ! ( F_215 ( V_6 , & V_29 ,
& V_599 ,
V_613 ,
V_6 -> V_31 . V_611 ) ) ) {
V_6 -> V_31 . V_14 =
F_6 ( V_599 . V_16 ) ;
}
}
V_75:
F_20 ( V_597 ) ;
F_20 ( V_589 ) ;
}
static int
F_216 ( struct V_5 * V_6 , T_4 V_27 )
{
struct V_78 * V_79 ;
T_9 V_29 ;
T_38 V_614 ;
T_39 V_615 ;
T_37 V_599 ;
T_10 V_30 ;
T_4 V_616 ;
T_1 V_9 , V_69 = 0 ;
int V_92 ;
unsigned long V_65 ;
struct V_367 * V_368 = NULL ;
int V_20 = 0 ;
if ( ! V_27 )
return - 1 ;
if ( V_6 -> V_317 || V_6 -> V_319 )
return - 1 ;
if ( ( F_217 ( V_6 , & V_29 , & V_614 ,
V_617 , V_27 ) ) ) {
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
V_616 = F_9 ( V_614 . V_618 ) ;
if ( F_11 ( V_6 , V_616 , & V_69 )
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
V_20 = F_216 ( V_6 , V_616 ) ;
if ( V_20 != 0 )
return V_20 ;
}
}
F_18 ( & V_6 -> V_80 , V_65 ) ;
V_9 = F_6 ( V_614 . V_11 ) ;
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
V_79 -> V_32 = V_614 . V_619 ;
V_79 -> V_69 = V_69 ;
V_79 -> V_9 = V_9 ;
F_3 ( V_58 L_182
L_183 , V_6 -> V_35 ,
V_27 , V_616 , ( unsigned long long )
V_79 -> V_9 , V_79 -> V_32 ) ;
if ( ! V_79 -> V_32 )
goto V_620;
V_79 -> V_274 = F_212 ( V_79 -> V_32 ,
sizeof( struct V_609 ) , V_172 ) ;
if ( ! V_79 -> V_274 ) {
F_3 ( V_34 L_2 ,
V_6 -> V_35 , __FILE__ , __LINE__ , V_36 ) ;
V_20 = - 1 ;
goto V_620;
}
F_153 ( & V_79 -> V_621 ) ;
V_368 = F_25 ( V_6 , V_27 ,
V_69 ) ;
if ( ! V_368 ) {
F_3 ( V_34 L_2 ,
V_6 -> V_35 , __FILE__ , __LINE__ , V_36 ) ;
V_20 = - 1 ;
goto V_620;
}
V_79 -> V_607 = & V_368 -> V_171 -> V_169 ;
for ( V_92 = 0 ; V_92 < V_79 -> V_32 ; V_92 ++ ) {
if ( ( F_218 ( V_6 , & V_29 ,
& V_615 , V_92 , V_27 ) ) ) {
F_3 ( V_34 L_2 ,
V_6 -> V_35 , __FILE__ , __LINE__ , V_36 ) ;
V_20 = - 1 ;
goto V_620;
}
V_79 -> V_274 [ V_92 ] . V_27 = V_27 ;
V_79 -> V_274 [ V_92 ] . V_610 = V_92 ;
if ( ( F_219 ( V_6 ,
& V_79 -> V_274 [ V_92 ] , V_615 ,
V_79 -> V_607 ) ) ) {
F_3 ( V_34 L_2 ,
V_6 -> V_35 , __FILE__ , __LINE__ , V_36 ) ;
V_20 = - 1 ;
goto V_620;
}
}
if ( V_79 -> V_611 ) {
if ( ! ( F_215 ( V_6 , & V_29 ,
& V_599 , V_613 ,
V_79 -> V_611 ) ) ) {
V_79 -> V_14 =
F_6 ( V_599 . V_16 ) ;
}
}
F_35 ( V_6 , V_79 ) ;
return 0 ;
V_620:
if ( V_368 )
F_26 ( V_6 , V_79 -> V_9 ,
V_69 ) ;
F_20 ( V_79 ) ;
return V_20 ;
}
static T_6
F_220 ( struct V_5 * V_6 , T_4 V_88 , T_6 V_292 , T_10 V_293 )
{
T_18 * V_29 ;
V_29 = F_106 ( V_6 , V_293 ) ;
if ( V_6 -> V_622 . V_295 == V_296 )
return 1 ;
if ( V_6 -> V_622 . V_88 != V_88 )
return 1 ;
V_6 -> V_622 . V_295 |= V_297 ;
if ( V_29 ) {
memcpy ( V_6 -> V_622 . V_293 , V_29 ,
V_29 -> V_298 * 4 ) ;
V_6 -> V_622 . V_295 |= V_299 ;
}
V_6 -> V_622 . V_295 &= ~ V_300 ;
F_107 ( & V_6 -> V_622 . V_301 ) ;
return 1 ;
}
void
F_221 ( struct V_5 * V_6 , T_1 V_9 )
{
struct V_78 * V_79 ;
unsigned long V_65 ;
if ( V_6 -> V_317 )
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
F_222 ( V_6 , V_79 ) ;
}
static T_6
F_223 ( struct V_5 * V_6 , T_1 V_9 ,
T_4 V_27 , T_6 V_623 )
{
T_6 V_20 = 1 ;
char * V_284 = NULL ;
switch ( V_623 ) {
case V_624 :
case V_625 :
V_20 = 0 ;
break;
case V_626 :
V_284 = L_184 ;
break;
case V_627 :
V_284 = L_185 ;
break;
case V_628 :
V_284 = L_186 ;
break;
case V_629 :
V_284 = L_187 ;
break;
case V_630 :
V_284 = L_188 ;
break;
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
case V_642 :
V_284 = L_189 ;
break;
default:
V_284 = L_63 ;
break;
}
if ( ! V_20 )
return 0 ;
F_3 ( V_34 L_190
L_96 , V_6 -> V_35 , V_284 ,
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
struct V_168 * V_70 ;
struct V_147 * V_148 ;
T_10 V_82 ;
if ( ( F_12 ( V_6 , & V_29 , & V_28 ,
V_33 , V_27 ) ) )
return;
V_30 = F_9 ( V_29 . V_38 ) & V_39 ;
if ( V_30 != V_40 )
return;
V_82 = F_76 ( V_28 . V_183 ) ;
if ( ! ( F_36 ( V_82 ) ) )
return;
F_18 ( & V_6 -> V_66 , V_65 ) ;
V_9 = F_6 ( V_28 . V_11 ) ;
V_46 = F_15 ( V_6 ,
V_9 ) ;
if ( ! V_46 ) {
F_3 ( V_34 L_191
L_192 , V_6 -> V_35 , V_27 ) ;
F_21 ( & V_6 -> V_66 , V_65 ) ;
return;
}
if ( F_225 ( V_46 -> V_27 != V_27 ) ) {
V_70 = V_46 -> V_70 ;
V_148 = V_70 -> V_150 ;
F_128 ( V_7 , V_70 , L_193
L_194 , V_46 -> V_27 , V_27 ) ;
V_148 -> V_27 = V_27 ;
V_46 -> V_27 = V_27 ;
}
F_21 ( & V_6 -> V_66 , V_65 ) ;
if ( ! ( F_9 ( V_28 . V_182 ) &
V_643 ) ) {
F_3 ( V_34 L_191
L_195 , V_6 -> V_35 , V_27 ) ;
return;
}
if ( F_223 ( V_6 , V_9 , V_27 ,
V_28 . V_644 ) )
return;
F_146 ( V_6 , V_27 ) ;
}
static int
F_226 ( struct V_5 * V_6 , T_4 V_27 , T_6 V_645 , T_6 V_646 )
{
T_9 V_29 ;
T_8 V_28 ;
T_37 V_599 ;
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
V_643 ) ) {
F_3 ( V_34 L_2 ,
V_6 -> V_35 , __FILE__ , __LINE__ , V_36 ) ;
F_3 ( V_34 L_196 ,
V_6 -> V_35 , F_9 ( V_28 . V_182 ) ) ;
return - 1 ;
}
if ( F_223 ( V_6 , V_9 , V_27 ,
V_28 . V_644 ) )
return - 1 ;
V_82 = F_76 ( V_28 . V_183 ) ;
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
( V_28 . V_618 ) ,
& V_46 -> V_69 ) != 0 )
F_3 ( V_34 L_2 ,
V_6 -> V_35 , __FILE__ , __LINE__ , V_36 ) ;
V_46 -> V_611 =
F_9 ( V_28 . V_612 ) ;
V_46 -> V_18 =
F_9 ( V_28 . V_647 ) ;
V_46 -> V_82 = V_82 ;
V_46 -> V_9 = V_9 ;
V_46 -> V_274 = V_28 . V_648 ;
if ( V_46 -> V_611 && ! ( F_215 (
V_6 , & V_29 , & V_599 , V_613 ,
V_46 -> V_611 ) ) )
V_46 -> V_14 =
F_6 ( V_599 . V_16 ) ;
V_46 -> V_12 = F_6 ( V_28 . V_13 ) ;
if ( V_6 -> V_649 )
F_27 ( V_6 , V_46 ) ;
else
F_22 ( V_6 , V_46 ) ;
return 0 ;
}
static void
F_227 ( struct V_5 * V_6 ,
struct V_45 * V_46 )
{
struct V_45 V_650 ;
struct V_147 * V_148 ;
if ( ! V_46 )
return;
memcpy ( & V_650 , V_46 , sizeof( struct V_45 ) ) ;
F_17 ( V_6 , V_46 ) ;
F_23 ( V_6 , F_3 ( V_58 L_197
L_107 , V_6 -> V_35 , V_36 ,
V_650 . V_27 , ( unsigned long long )
V_650 . V_9 ) ) ;
if ( V_650 . V_70 && V_650 . V_70 -> V_150 ) {
V_148 = V_650 . V_70 -> V_150 ;
V_148 -> V_387 = 1 ;
F_146 ( V_6 , V_650 . V_27 ) ;
V_148 -> V_27 =
V_173 ;
}
F_146 ( V_6 , V_650 . V_27 ) ;
if ( ! V_6 -> V_651 )
F_26 ( V_6 ,
V_650 . V_9 ,
V_650 . V_69 ) ;
F_3 ( V_58 L_198
L_199 , V_6 -> V_35 , V_650 . V_27 ,
( unsigned long long ) V_650 . V_9 ) ;
F_23 ( V_6 , F_3 ( V_58 L_200
L_107 , V_6 -> V_35 , V_36 ,
V_650 . V_27 , ( unsigned long long )
V_650 . V_9 ) ) ;
}
void
F_228 ( struct V_5 * V_6 , T_1 V_9 )
{
struct V_45 * V_46 ;
unsigned long V_65 ;
if ( V_6 -> V_317 )
return;
F_18 ( & V_6 -> V_66 , V_65 ) ;
V_46 = F_15 ( V_6 ,
V_9 ) ;
if ( ! V_46 ) {
F_21 ( & V_6 -> V_66 , V_65 ) ;
return;
}
F_21 ( & V_6 -> V_66 , V_65 ) ;
F_227 ( V_6 , V_46 ) ;
}
static void
F_229 ( struct V_5 * V_6 ,
T_22 * V_360 )
{
int V_92 ;
T_4 V_27 ;
T_4 V_375 ;
T_6 V_376 ;
char * V_652 = NULL ;
T_6 V_591 , V_653 ;
switch ( V_360 -> V_402 ) {
case V_408 :
V_652 = L_201 ;
break;
case V_404 :
V_652 = L_202 ;
break;
case V_405 :
case 0 :
V_652 = L_203 ;
break;
case V_403 :
V_652 = L_204 ;
break;
default:
V_652 = L_205 ;
break;
}
F_3 ( V_58 L_206 ,
V_6 -> V_35 , V_652 ) ;
F_3 ( V_7 L_207
L_208 ,
F_9 ( V_360 -> V_401 ) ,
F_9 ( V_360 -> V_612 ) ,
V_360 -> V_380 , V_360 -> V_377 ) ;
for ( V_92 = 0 ; V_92 < V_360 -> V_377 ; V_92 ++ ) {
V_27 = F_9 ( V_360 -> V_378 [ V_92 ] . V_379 ) ;
if ( ! V_27 )
continue;
V_376 = V_360 -> V_380 + V_92 ;
V_375 = V_360 -> V_378 [ V_92 ] . V_381 &
V_382 ;
switch ( V_375 ) {
case V_654 :
V_652 = L_209 ;
break;
case V_400 :
V_652 = L_210 ;
break;
case V_383 :
V_652 = L_211 ;
break;
case V_655 :
V_652 = L_212 ;
break;
case V_656 :
V_652 = L_213 ;
break;
default:
V_652 = L_63 ;
break;
}
V_591 = V_360 -> V_378 [ V_92 ] . V_657 >> 4 ;
V_653 = V_360 -> V_378 [ V_92 ] . V_657 & 0xF ;
F_3 ( V_7 L_214
L_215 , V_376 ,
V_27 , V_652 , V_591 , V_653 ) ;
}
}
static void
F_230 ( struct V_5 * V_6 ,
struct V_353 * V_354 )
{
int V_92 ;
T_4 V_616 , V_27 ;
T_4 V_375 ;
T_6 V_376 , V_658 ;
struct V_78 * V_79 ;
struct V_45 * V_46 ;
T_1 V_9 ;
unsigned long V_65 ;
T_6 V_591 , V_653 ;
T_22 * V_360 = V_354 -> V_360 ;
#ifdef F_155
if ( V_6 -> V_8 & V_659 )
F_229 ( V_6 , V_360 ) ;
#endif
if ( V_6 -> V_318 || V_6 -> V_319 )
return;
if ( ! V_6 -> V_31 . V_32 )
F_209 ( V_6 ) ;
else
F_206 ( V_6 ) ;
if ( V_354 -> V_407 ) {
F_23 ( V_6 , F_3 ( V_58 L_216
L_217 , V_6 -> V_35 ) ) ;
return;
}
V_616 = F_9 ( V_360 -> V_401 ) ;
if ( V_360 -> V_402 == V_408 )
if ( F_216 ( V_6 , V_616 ) != 0 )
return;
F_18 ( & V_6 -> V_80 , V_65 ) ;
V_79 = F_33 ( V_6 ,
V_616 ) ;
F_21 ( & V_6 -> V_80 , V_65 ) ;
if ( V_79 ) {
V_9 = V_79 -> V_9 ;
V_658 = V_79 -> V_32 ;
} else if ( V_616 < V_6 -> V_31 . V_32 ) {
V_9 = V_6 -> V_31 . V_9 ;
V_658 = V_6 -> V_31 . V_32 ;
} else
return;
for ( V_92 = 0 ; V_92 < V_360 -> V_377 ; V_92 ++ ) {
if ( V_354 -> V_407 ) {
F_23 ( V_6 , F_3 ( V_58 L_218
L_219 , V_6 -> V_35 ) ) ;
return;
}
if ( V_6 -> V_317 || V_6 -> V_318 ||
V_6 -> V_319 )
return;
V_376 = V_360 -> V_380 + V_92 ;
if ( V_376 >= V_658 )
continue;
V_375 = V_360 -> V_378 [ V_92 ] . V_381 &
V_382 ;
if ( ( V_360 -> V_378 [ V_92 ] . V_381 &
V_660 ) && ( V_375 !=
V_400 ) )
continue;
V_27 = F_9 ( V_360 -> V_378 [ V_92 ] . V_379 ) ;
if ( ! V_27 )
continue;
V_591 = V_360 -> V_378 [ V_92 ] . V_657 >> 4 ;
V_653 = V_360 -> V_378 [ V_92 ] . V_657 & 0xF ;
switch ( V_375 ) {
case V_655 :
if ( V_6 -> V_317 )
break;
if ( V_591 == V_653 )
break;
F_208 ( V_6 , V_9 ,
V_27 , V_376 , V_591 ) ;
if ( V_591 < V_596 )
break;
F_224 ( V_6 , V_27 ) ;
break;
case V_654 :
if ( V_6 -> V_317 )
break;
F_208 ( V_6 , V_9 ,
V_27 , V_376 , V_591 ) ;
F_226 ( V_6 , V_27 , V_376 , 0 ) ;
break;
case V_400 :
F_18 ( & V_6 -> V_66 , V_65 ) ;
V_46 = F_16 ( V_6 ,
V_27 ) ;
if ( ! V_46 ) {
F_21 ( & V_6 -> V_66 ,
V_65 ) ;
break;
}
F_21 ( & V_6 -> V_66 , V_65 ) ;
F_227 ( V_6 , V_46 ) ;
break;
}
}
if ( V_360 -> V_402 == V_404 &&
V_79 )
F_221 ( V_6 , V_9 ) ;
}
static void
F_231 ( struct V_5 * V_6 ,
T_32 * V_360 )
{
char * V_661 = NULL ;
switch ( V_360 -> V_414 ) {
case V_572 :
V_661 = L_220 ;
break;
case V_662 :
V_661 = L_221 ;
break;
case V_663 :
V_661 = L_222 ;
break;
case V_664 :
V_661 = L_223 ;
break;
case V_665 :
V_661 = L_224 ;
break;
case V_666 :
V_661 = L_225 ;
break;
case V_667 :
V_661 = L_226 ;
break;
case V_668 :
V_661 = L_227 ;
break;
case V_669 :
V_661 = L_228 ;
break;
case V_670 :
V_661 = L_229 ;
break;
case V_671 :
V_661 = L_230 ;
break;
case V_672 :
V_661 = L_231 ;
break;
case V_673 :
V_661 = L_232 ;
break;
default:
V_661 = L_233 ;
break;
}
F_3 ( V_58 L_234
L_235 ,
V_6 -> V_35 , V_661 , F_9 ( V_360 -> V_233 ) ,
( unsigned long long ) F_6 ( V_360 -> V_11 ) ,
F_9 ( V_360 -> V_546 ) ) ;
if ( V_360 -> V_414 == V_572 )
F_3 ( V_58 L_236 , V_6 -> V_35 ,
V_360 -> V_573 , V_360 -> V_674 ) ;
F_3 ( V_7 L_237 ) ;
}
static void
F_232 ( struct V_5 * V_6 ,
struct V_353 * V_354 )
{
struct V_147 * V_675 ;
struct V_45 * V_46 ;
T_1 V_9 ;
unsigned long V_65 ;
T_32 * V_360 =
V_354 -> V_360 ;
#ifdef F_155
if ( V_6 -> V_8 & V_659 )
F_231 ( V_6 ,
V_360 ) ;
#endif
if ( ( V_6 -> V_257 . V_676 >> 8 ) < 0xC )
return;
if ( V_360 -> V_414 !=
V_663 &&
V_360 -> V_414 !=
V_669 )
return;
F_18 ( & V_6 -> V_66 , V_65 ) ;
V_9 = F_6 ( V_360 -> V_11 ) ;
V_46 = F_15 ( V_6 ,
V_9 ) ;
F_21 ( & V_6 -> V_66 , V_65 ) ;
if ( ! V_46 || ! V_46 -> V_70 )
return;
V_675 = V_46 -> V_70 -> V_150 ;
if ( ! V_675 )
return;
if ( V_360 -> V_414 ==
V_663 )
V_675 -> V_303 = 1 ;
else
V_675 -> V_303 = 0 ;
}
static void
F_233 ( struct V_5 * V_6 ,
T_41 * V_360 )
{
char * V_661 = NULL ;
switch ( V_360 -> V_414 ) {
case V_677 :
V_661 = L_238 ;
break;
case V_678 :
V_661 = L_239 ;
break;
default:
V_661 = L_233 ;
break;
}
F_3 ( V_58 L_240
L_241
L_242 , V_6 -> V_35 , V_661 ,
F_9 ( V_360 -> V_612 ) ,
( unsigned long long ) F_6 ( V_360 -> V_16 ) ,
F_9 ( V_360 -> V_679 ) ) ;
}
static void
F_234 ( struct V_5 * V_6 ,
struct V_353 * V_354 )
{
#ifdef F_155
if ( V_6 -> V_8 & V_659 )
F_233 ( V_6 ,
V_354 -> V_360 ) ;
#endif
}
static void
F_235 ( struct V_5 * V_6 ,
struct V_353 * V_354 )
{
struct V_87 * V_90 ;
struct V_138 * V_139 ;
T_4 V_88 , V_27 ;
T_10 V_95 ;
struct V_145 * V_146 ;
T_10 V_680 ;
T_10 V_681 ;
T_21 * V_29 ;
T_42 * V_360 = V_354 -> V_360 ;
T_4 V_30 ;
unsigned long V_65 ;
int V_74 ;
T_6 V_682 = 0 ;
T_6 V_683 ;
F_112 ( & V_6 -> V_294 . V_314 ) ;
F_23 ( V_6 , F_3 ( V_58 L_243
L_244 , V_6 -> V_35 , V_36 , V_360 -> V_648 ,
V_360 -> V_684 ) ) ;
F_147 ( V_6 ) ;
F_18 ( & V_6 -> V_91 , V_65 ) ;
V_29 = V_6 -> V_294 . V_293 ;
V_685:
if ( V_682 ++ == 5 ) {
F_23 ( V_6 , F_3 ( V_58 L_245 ,
V_6 -> V_35 , V_36 ) ) ;
goto V_75;
} else if ( V_682 > 1 )
F_23 ( V_6 , F_3 ( V_58 L_246 ,
V_6 -> V_35 , V_36 , V_682 - 1 ) ) ;
V_680 = 0 ;
V_681 = 0 ;
for ( V_88 = 1 ; V_88 <= V_6 -> V_93 ; V_88 ++ ) {
if ( V_6 -> V_317 )
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
V_681 ++ ;
if ( V_6 -> V_317 )
goto V_75;
F_21 ( & V_6 -> V_91 , V_65 ) ;
V_74 = F_111 ( V_6 , V_27 , 0 , 0 , V_95 ,
V_344 , V_88 , 30 , 0 ,
V_686 ) ;
if ( V_74 == V_315 ) {
F_51 ( V_563 , V_139 ,
L_247
L_248 , V_90 ) ;
F_18 ( & V_6 -> V_91 , V_65 ) ;
goto V_685;
}
V_30 = F_9 ( V_29 -> V_38 )
& V_39 ;
if ( V_30 != V_40 ) {
F_51 ( V_563 , V_139 , L_249
L_250 , V_30 ,
V_90 ) ;
F_18 ( & V_6 -> V_91 , V_65 ) ;
goto V_685;
}
if ( V_29 -> V_340 ==
V_289 ||
V_29 -> V_340 ==
V_291 ) {
F_18 ( & V_6 -> V_91 , V_65 ) ;
continue;
}
V_683 = 0 ;
V_687:
if ( V_683 ++ == 60 ) {
F_23 ( V_6 , F_3 ( V_58
L_251 , V_6 -> V_35 ,
V_36 ) ) ;
F_18 ( & V_6 -> V_91 , V_65 ) ;
goto V_685;
}
if ( V_6 -> V_317 )
goto V_688;
V_74 = F_111 ( V_6 , V_27 , V_139 -> V_73 , V_139 -> V_72 ,
V_139 -> V_95 , V_328 , V_88 , 30 ,
V_90 -> V_307 , V_686 ) ;
if ( V_74 == V_315 ) {
F_51 ( V_563 , V_139 ,
L_252
L_83 , V_90 ) ;
goto V_687;
}
if ( V_683 > 1 )
F_51 ( V_563 , V_139 ,
L_253
L_254 ,
V_683 - 1 , V_90 ) ;
V_680 += F_76 ( V_29 -> V_338 ) ;
F_18 ( & V_6 -> V_91 , V_65 ) ;
}
if ( V_6 -> V_689 ) {
F_23 ( V_6 , F_3 ( V_58 L_255
L_256 , V_6 -> V_35 , V_36 ) ) ;
V_6 -> V_689 = 0 ;
goto V_685;
}
V_75:
F_21 ( & V_6 -> V_91 , V_65 ) ;
V_688:
F_23 ( V_6 , F_3 ( V_58
L_257 ,
V_6 -> V_35 , V_36 , V_681 , V_680 ) ) ;
V_6 -> V_690 = 0 ;
if ( ! V_6 -> V_317 )
F_144 ( V_6 ) ;
F_125 ( & V_6 -> V_294 . V_314 ) ;
}
static void
F_236 ( struct V_5 * V_6 ,
struct V_353 * V_354 )
{
T_43 * V_360 = V_354 -> V_360 ;
#ifdef F_155
if ( V_6 -> V_8 & V_659 ) {
F_3 ( V_58 L_258 , V_6 -> V_35 ,
( V_360 -> V_414 == V_691 ) ?
L_259 : L_260 ) ;
if ( V_360 -> V_692 )
F_3 ( L_261 ,
F_76 ( V_360 -> V_692 ) ) ;
F_3 ( L_237 ) ;
}
#endif
if ( V_360 -> V_414 == V_691 &&
! V_6 -> V_31 . V_32 )
F_209 ( V_6 ) ;
}
static void
F_237 ( struct V_138 * V_139 , void * V_181 )
{
int V_20 ;
V_139 -> V_181 = V_181 ? 1 : 0 ;
F_51 ( V_7 , V_139 , L_262 ,
V_139 -> V_181 ? L_263 : L_264 ) ;
V_20 = F_238 ( V_139 ) ;
}
static void
F_239 ( struct V_168 * V_70 , int V_181 )
{
struct V_147 * V_148 ;
if ( V_70 == NULL )
return;
V_148 = V_70 -> V_150 ;
if ( V_181 )
V_148 -> V_65 |= V_178 ;
else
V_148 -> V_65 &= ~ V_178 ;
F_240 ( V_70 , V_181 ? ( void * ) 1 : NULL ,
F_237 ) ;
}
static void
F_241 ( struct V_5 * V_6 ,
T_26 * V_411 )
{
struct V_47 * V_48 ;
unsigned long V_65 ;
T_1 V_52 ;
T_4 V_27 = F_9 ( V_411 -> V_417 ) ;
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
if ( ! V_6 -> V_649 ) {
V_20 = F_242 ( V_6 -> V_142 , V_174 ,
V_48 -> V_72 , 0 ) ;
if ( V_20 )
F_32 ( V_6 , V_48 ) ;
} else
F_13 ( V_6 , V_48 , 1 ) ;
}
static void
F_243 ( struct V_5 * V_6 , T_4 V_27 )
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
V_148 -> V_387 = 1 ;
F_244 ( & V_48 -> V_70 -> V_169 ) ;
}
F_3 ( V_58 L_265
L_199 , V_6 -> V_35 , V_48 -> V_27 ,
( unsigned long long ) V_48 -> V_52 ) ;
F_32 ( V_6 , V_48 ) ;
}
static void
F_245 ( struct V_5 * V_6 ,
T_26 * V_411 )
{
struct V_45 * V_46 ;
unsigned long V_65 ;
T_4 V_27 = F_9 ( V_411 -> V_420 ) ;
F_18 ( & V_6 -> V_66 , V_65 ) ;
V_46 = F_16 ( V_6 , V_27 ) ;
F_21 ( & V_6 -> V_66 , V_65 ) ;
if ( ! V_46 )
return;
V_46 -> V_272 = 0 ;
V_46 -> V_273 = 0 ;
F_167 ( V_27 , V_6 -> V_177 ) ;
F_239 ( V_46 -> V_70 , 0 ) ;
}
static void
F_246 ( struct V_5 * V_6 ,
T_26 * V_411 )
{
struct V_45 * V_46 ;
unsigned long V_65 ;
T_4 V_27 = F_9 ( V_411 -> V_420 ) ;
F_18 ( & V_6 -> V_66 , V_65 ) ;
V_46 = F_16 ( V_6 , V_27 ) ;
F_21 ( & V_6 -> V_66 , V_65 ) ;
if ( ! V_46 )
return;
F_98 ( V_6 , V_27 ,
& V_46 -> V_272 ) ;
F_99 ( V_6 , V_46 -> V_272 ,
& V_46 -> V_273 ) ;
F_247 ( V_27 , V_6 -> V_177 ) ;
F_239 ( V_46 -> V_70 , 1 ) ;
}
static void
F_248 ( struct V_5 * V_6 ,
T_26 * V_411 )
{
struct V_45 * V_46 ;
unsigned long V_65 ;
T_4 V_27 = F_9 ( V_411 -> V_420 ) ;
F_18 ( & V_6 -> V_66 , V_65 ) ;
V_46 = F_16 ( V_6 , V_27 ) ;
F_21 ( & V_6 -> V_66 , V_65 ) ;
if ( ! V_46 )
return;
F_227 ( V_6 , V_46 ) ;
}
static void
F_249 ( struct V_5 * V_6 ,
T_26 * V_411 )
{
struct V_45 * V_46 ;
unsigned long V_65 ;
T_4 V_27 = F_9 ( V_411 -> V_420 ) ;
T_9 V_29 ;
T_8 V_28 ;
T_10 V_30 ;
T_1 V_9 ;
T_4 V_616 ;
F_247 ( V_27 , V_6 -> V_177 ) ;
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
V_616 = F_9 ( V_28 . V_618 ) ;
if ( ! F_11 ( V_6 , V_616 , & V_9 ) )
F_208 ( V_6 , V_9 , V_27 ,
V_28 . V_648 , V_596 ) ;
F_226 ( V_6 , V_27 , 0 , 1 ) ;
}
static void
F_250 ( struct V_5 * V_6 ,
T_25 * V_360 )
{
T_26 * V_411 ;
T_6 V_694 ;
int V_92 ;
char * V_661 = NULL , * V_695 = NULL ;
V_411 = ( T_26 * ) & V_360 -> V_412 [ 0 ] ;
F_3 ( V_58 L_266 ,
V_6 -> V_35 , ( F_76 ( V_360 -> V_182 ) &
V_418 ) ?
L_267 : L_268 , V_360 -> V_413 ) ;
for ( V_92 = 0 ; V_92 < V_360 -> V_413 ; V_92 ++ , V_411 ++ ) {
switch ( V_411 -> V_414 ) {
case V_696 :
V_661 = L_201 ;
break;
case V_416 :
V_661 = L_202 ;
break;
case V_697 :
V_661 = L_269 ;
break;
case V_698 :
V_661 = L_270 ;
break;
case V_419 :
V_661 = L_271 ;
break;
case V_699 :
V_661 = L_272 ;
break;
case V_415 :
V_661 = L_273 ;
break;
case V_700 :
V_661 = L_274 ;
break;
case V_701 :
V_661 = L_275 ;
break;
default:
V_661 = L_233 ;
break;
}
V_694 = F_9 ( V_411 -> V_702 ) &
V_703 ;
switch ( V_694 ) {
case V_704 :
V_695 = L_76 ;
break;
case V_705 :
V_695 = L_276 ;
break;
case V_706 :
V_695 = L_277 ;
break;
default:
V_695 = L_278 ;
break;
}
F_3 ( V_7 L_279
L_280 , V_695 ,
V_661 , F_9 ( V_411 -> V_417 ) ,
F_9 ( V_411 -> V_420 ) ,
V_411 -> V_232 ) ;
}
}
static void
F_251 ( struct V_5 * V_6 ,
struct V_353 * V_354 )
{
T_26 * V_411 ;
int V_92 ;
T_6 V_707 ;
T_25 * V_360 = V_354 -> V_360 ;
#ifdef F_155
if ( ( V_6 -> V_8 & V_659 )
&& ! V_6 -> V_271 )
F_250 ( V_6 , V_360 ) ;
#endif
if ( V_6 -> V_317 )
return;
V_707 = ( F_76 ( V_360 -> V_182 ) &
V_418 ) ? 1 : 0 ;
V_411 = ( T_26 * ) & V_360 -> V_412 [ 0 ] ;
for ( V_92 = 0 ; V_92 < V_360 -> V_413 ; V_92 ++ , V_411 ++ ) {
switch ( V_411 -> V_414 ) {
case V_699 :
case V_696 :
if ( ! V_707 )
F_241 ( V_6 , V_411 ) ;
break;
case V_415 :
case V_416 :
if ( ! V_707 )
F_243 ( V_6 ,
F_9 ( V_411 -> V_417 ) ) ;
break;
case V_700 :
if ( ! V_6 -> V_190 )
F_246 ( V_6 , V_411 ) ;
break;
case V_701 :
if ( ! V_6 -> V_190 )
F_245 ( V_6 , V_411 ) ;
break;
case V_698 :
if ( ! V_6 -> V_190 )
F_249 ( V_6 , V_411 ) ;
break;
case V_419 :
if ( ! V_6 -> V_190 )
F_248 ( V_6 , V_411 ) ;
break;
}
}
}
static void
F_252 ( struct V_5 * V_6 ,
struct V_353 * V_354 )
{
T_1 V_52 ;
unsigned long V_65 ;
struct V_47 * V_48 ;
T_4 V_27 ;
T_10 V_200 ;
int V_20 ;
T_27 * V_360 = V_354 -> V_360 ;
if ( V_6 -> V_317 )
return;
if ( V_360 -> V_414 != V_421 )
return;
V_27 = F_9 ( V_360 -> V_417 ) ;
V_200 = F_76 ( V_360 -> V_422 ) ;
if ( ! V_6 -> V_271 )
F_23 ( V_6 , F_3 ( V_58 L_50
L_281 , V_6 -> V_35 , V_36 , V_27 ,
F_76 ( V_360 -> V_708 ) , V_200 ) ) ;
switch ( V_200 ) {
case V_210 :
case V_209 :
F_243 ( V_6 , V_27 ) ;
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
V_20 = F_242 ( V_6 -> V_142 , V_174 ,
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
F_253 ( struct V_5 * V_6 ,
struct V_353 * V_354 )
{
T_4 V_27 , V_616 ;
T_10 V_200 ;
struct V_45 * V_46 ;
unsigned long V_65 ;
T_9 V_29 ;
T_8 V_28 ;
T_10 V_30 ;
T_44 * V_360 = V_354 -> V_360 ;
T_1 V_9 ;
if ( V_6 -> V_317 )
return;
if ( V_360 -> V_414 != V_710 )
return;
V_27 = F_9 ( V_360 -> V_420 ) ;
V_200 = F_76 ( V_360 -> V_422 ) ;
if ( ! V_6 -> V_271 )
F_23 ( V_6 , F_3 ( V_58 L_50
L_281 , V_6 -> V_35 , V_36 , V_27 ,
F_76 ( V_360 -> V_708 ) , V_200 ) ) ;
switch ( V_200 ) {
case V_711 :
case V_712 :
case V_713 :
case V_714 :
case V_715 :
if ( ! V_6 -> V_190 )
F_247 ( V_27 , V_6 -> V_177 ) ;
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
V_616 = F_9 ( V_28 . V_618 ) ;
if ( ! F_11 ( V_6 , V_616 , & V_9 ) )
F_208 ( V_6 , V_9 , V_27 ,
V_28 . V_648 , V_596 ) ;
F_226 ( V_6 , V_27 , 0 , 1 ) ;
break;
case V_716 :
case V_717 :
case V_718 :
default:
break;
}
}
static void
F_254 ( struct V_5 * V_6 ,
T_45 * V_360 )
{
char * V_661 = NULL ;
switch ( V_360 -> V_719 ) {
case V_720 :
V_661 = L_282 ;
break;
case V_721 :
V_661 = L_283 ;
break;
case V_722 :
V_661 = L_284 ;
break;
case V_723 :
V_661 = L_285 ;
break;
case V_724 :
V_661 = L_286 ;
break;
}
if ( ! V_661 )
return;
F_3 ( V_58 L_287
L_288 ,
V_6 -> V_35 , V_661 ,
F_9 ( V_360 -> V_417 ) ,
V_360 -> V_725 ) ;
}
static void
F_255 ( struct V_5 * V_6 ,
struct V_353 * V_354 )
{
T_45 * V_360 = V_354 -> V_360 ;
static struct V_47 * V_48 ;
unsigned long V_65 ;
T_4 V_27 ;
#ifdef F_155
if ( ( V_6 -> V_8 & V_659 )
&& ! V_6 -> V_271 )
F_254 ( V_6 ,
V_360 ) ;
#endif
if ( V_360 -> V_719 == V_720 ) {
V_27 = F_9 ( V_360 -> V_417 ) ;
F_18 ( & V_6 -> V_76 , V_65 ) ;
V_48 = F_29 ( V_6 , V_27 ) ;
F_21 ( & V_6 -> V_76 , V_65 ) ;
if ( ! V_48 )
return;
if ( V_360 -> V_719 == V_720 )
V_48 -> V_193 =
V_360 -> V_725 ;
}
}
static void
F_256 ( struct V_5 * V_6 )
{
struct V_145 * V_146 ;
struct V_138 * V_139 ;
F_109 (sdev, ioc->shost) {
V_146 = V_139 -> V_150 ;
if ( V_146 && V_146 -> V_152 )
V_146 -> V_152 -> V_387 = 1 ;
}
}
static void
F_257 ( struct V_5 * V_6 , T_1 V_9 ,
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
V_148 -> V_387 = 0 ;
} else
V_148 = NULL ;
if ( V_70 )
F_128 ( V_7 , V_70 ,
L_289
L_290
L_291 , V_27 ,
( unsigned long long ) V_46 -> V_9 ,
( unsigned long long )
V_46 -> V_14 ,
V_46 -> V_18 ) ;
if ( V_46 -> V_27 == V_27 )
goto V_75;
F_3 ( V_7 L_292 ,
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
T_40 V_9 ;
T_4 V_27 ;
T_10 V_82 ;
T_4 V_18 ;
F_3 ( V_58 L_293 , V_6 -> V_35 ) ;
if ( F_43 ( & V_6 -> V_68 ) )
goto V_75;
V_27 = 0xFFFF ;
while ( ! ( F_12 ( V_6 , & V_29 ,
& V_28 , V_727 ,
V_27 ) ) ) {
V_30 = F_9 ( V_29 . V_38 ) &
V_39 ;
if ( V_30 == V_41 )
break;
V_27 = F_9 ( V_28 . V_233 ) ;
V_82 = F_76 ( V_28 . V_183 ) ;
if ( ! ( F_36 ( V_82 ) ) )
continue;
V_9 = F_6 ( V_28 . V_11 ) ;
V_18 = F_9 ( V_28 . V_647 ) ;
F_257 ( V_6 , V_9 , V_18 ,
V_27 ) ;
}
V_75:
F_3 ( V_58 L_294 ,
V_6 -> V_35 ) ;
}
static void
F_259 ( struct V_5 * V_6 , T_1 V_52 ,
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
V_148 -> V_387 = 0 ;
} else
V_148 = NULL ;
V_48 -> V_726 = 1 ;
F_21 ( & V_6 -> V_76 , V_65 ) ;
F_128 ( V_7 , V_48 -> V_70 ,
L_295 , V_27 ,
( unsigned long long ) V_48 -> V_52 ) ;
F_92 ( V_6 , V_48 ) ;
if ( V_48 -> V_27 == V_27 )
return;
F_3 ( V_7 L_292 ,
V_48 -> V_27 ) ;
V_48 -> V_27 = V_27 ;
if ( V_148 )
V_148 -> V_27 = V_27 ;
return;
}
}
F_21 ( & V_6 -> V_76 , V_65 ) ;
}
static void
F_260 ( struct V_5 * V_6 )
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
F_3 ( V_58 L_296 ,
V_6 -> V_35 ) ;
if ( F_43 ( & V_6 -> V_77 ) )
goto V_75;
V_27 = 0xFFFF ;
while ( ! ( F_90 ( V_6 , & V_29 ,
& V_728 , V_235 , V_27 ) ) ) {
V_30 = F_9 ( V_29 . V_38 ) &
V_39 ;
if ( V_30 == V_41 )
break;
V_27 = F_9 ( V_728 . V_233 ) ;
if ( F_80 ( V_6 , & V_29 ,
& V_729 , V_194 , V_27 ,
sizeof( T_13 ) ) )
continue;
if ( V_729 . V_203 == V_204 ||
V_729 . V_203 == V_205 ||
V_729 . V_203 == V_207 )
F_259 ( V_6 ,
F_6 ( V_728 . V_732 ) , V_27 ) ;
}
if ( ! V_6 -> V_190 ) {
V_730 = 0xFF ;
memset ( V_6 -> V_177 , 0 , V_6 -> V_733 ) ;
while ( ! ( F_88 ( V_6 , & V_29 ,
& V_225 , V_734 ,
V_730 ) ) ) {
V_30 = F_9 ( V_29 . V_38 ) &
V_39 ;
if ( V_30 == V_41 )
break;
V_730 = V_225 . V_232 ;
V_27 = F_9 ( V_225 . V_233 ) ;
F_247 ( V_27 , V_6 -> V_177 ) ;
}
}
V_75:
F_3 ( V_58 L_297
L_298 , V_6 -> V_35 ) ;
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
V_79 -> V_726 = 1 ;
if ( V_79 -> V_27 == V_27 )
goto V_75;
F_3 ( V_7 L_299
L_300 ,
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
F_262 ( struct V_5 * V_6 )
{
T_38 V_614 ;
T_9 V_29 ;
T_4 V_30 ;
T_1 V_9 ;
T_4 V_27 ;
F_3 ( V_58 L_301 , V_6 -> V_35 ) ;
if ( F_43 ( & V_6 -> V_81 ) )
goto V_75;
V_27 = 0xFFFF ;
while ( ! ( F_217 ( V_6 , & V_29 , & V_614 ,
V_735 , V_27 ) ) ) {
V_30 = F_9 ( V_29 . V_38 ) &
V_39 ;
if ( V_30 == V_41 )
break;
V_27 = F_9 ( V_614 . V_233 ) ;
V_9 = F_6 ( V_614 . V_11 ) ;
F_3 ( V_7 L_302
L_303 , V_27 ,
( unsigned long long ) V_9 ) ;
F_261 ( V_6 , V_9 , V_27 ) ;
}
V_75:
F_3 ( V_58 L_304 , V_6 -> V_35 ) ;
}
static void
F_263 ( struct V_5 * V_6 )
{
struct V_45 * V_46 , * V_736 ;
struct V_78 * V_79 ;
struct V_47 * V_48 , * V_737 ;
F_3 ( V_58 L_305 ,
V_6 -> V_35 ) ;
F_142 (sas_device, sas_device_next,
&ioc->sas_device_list, list) {
if ( V_46 -> V_726 ) {
V_46 -> V_726 = 0 ;
continue;
}
if ( V_46 -> V_70 )
F_128 ( V_7 , V_46 -> V_70 ,
L_306
L_307 ,
V_46 -> V_27 ,
( unsigned long long ) V_46 -> V_9 ,
( unsigned long long )
V_46 -> V_14 ,
V_46 -> V_18 ) ;
F_227 ( V_6 , V_46 ) ;
}
if ( ! V_6 -> V_731 )
goto V_738;
F_142 (raid_device, raid_device_next,
&ioc->raid_device_list, list) {
if ( V_48 -> V_726 ) {
V_48 -> V_726 = 0 ;
continue;
}
if ( V_48 -> V_70 ) {
F_128 ( V_7 , V_48 -> V_70 ,
L_308 ,
V_48 -> V_27 ,
( unsigned long long ) V_48 -> V_52 ) ;
F_244 ( & V_48 -> V_70 -> V_169 ) ;
}
F_32 ( V_6 , V_48 ) ;
}
V_738:
V_79 = NULL ;
F_4 (sas_expander, &ioc->sas_expander_list, list) {
if ( V_79 -> V_726 ) {
V_79 -> V_726 = 0 ;
continue;
}
F_221 ( V_6 , V_79 -> V_9 ) ;
goto V_738;
}
F_3 ( V_58 L_309 ,
V_6 -> V_35 ) ;
F_144 ( V_6 ) ;
}
static void
F_264 ( struct V_5 * V_6 ,
struct V_78 * V_79 , T_4 V_27 )
{
T_39 V_615 ;
T_9 V_29 ;
int V_92 ;
for ( V_92 = 0 ; V_92 < V_79 -> V_32 ; V_92 ++ ) {
if ( ( F_218 ( V_6 , & V_29 ,
& V_615 , V_92 , V_27 ) ) ) {
F_3 ( V_34 L_2 ,
V_6 -> V_35 , __FILE__ , __LINE__ , V_36 ) ;
return;
}
F_208 ( V_6 , V_79 -> V_9 ,
F_9 ( V_615 . V_379 ) , V_92 ,
V_615 . V_594 >> 4 ) ;
}
}
static void
F_265 ( struct V_5 * V_6 )
{
T_38 V_614 ;
T_8 V_28 ;
T_15 V_728 ;
T_13 V_729 ;
T_14 V_225 ;
T_26 V_411 ;
T_9 V_29 ;
T_6 V_730 ;
T_4 V_30 ;
T_4 V_27 , V_616 ;
T_1 V_9 ;
struct V_45 * V_46 ;
struct V_78 * V_739 ;
static struct V_47 * V_48 ;
F_3 ( V_58 L_310 , V_6 -> V_35 ) ;
F_206 ( V_6 ) ;
V_27 = 0xFFFF ;
while ( ! ( F_217 ( V_6 , & V_29 , & V_614 ,
V_735 , V_27 ) ) ) {
V_30 = F_9 ( V_29 . V_38 ) &
V_39 ;
if ( V_30 == V_41 )
break;
V_27 = F_9 ( V_614 . V_233 ) ;
V_739 = F_34 (
V_6 , F_6 ( V_614 . V_11 ) ) ;
if ( V_739 )
F_264 ( V_6 , V_739 ,
V_27 ) ;
else
F_216 ( V_6 , V_27 ) ;
}
if ( ! V_6 -> V_731 )
goto V_740;
V_730 = 0xFF ;
while ( ! ( F_88 ( V_6 , & V_29 ,
& V_225 , V_734 ,
V_730 ) ) ) {
V_30 = F_9 ( V_29 . V_38 ) &
V_39 ;
if ( V_30 == V_41 )
break;
V_730 = V_225 . V_232 ;
V_27 = F_9 ( V_225 . V_233 ) ;
V_46 = F_16 ( V_6 , V_27 ) ;
if ( V_46 )
continue;
if ( F_12 ( V_6 , & V_29 ,
& V_28 , V_33 ,
V_27 ) != 0 )
continue;
V_616 = F_9 ( V_28 . V_618 ) ;
if ( ! F_11 ( V_6 , V_616 ,
& V_9 ) ) {
F_208 ( V_6 , V_9 ,
V_27 , V_28 . V_648 ,
V_596 ) ;
F_247 ( V_27 , V_6 -> V_177 ) ;
F_226 ( V_6 , V_27 , 0 , 1 ) ;
}
}
V_27 = 0xFFFF ;
while ( ! ( F_90 ( V_6 , & V_29 ,
& V_728 , V_235 , V_27 ) ) ) {
V_30 = F_9 ( V_29 . V_38 ) &
V_39 ;
if ( V_30 == V_41 )
break;
V_27 = F_9 ( V_728 . V_233 ) ;
V_48 = F_30 ( V_6 ,
F_6 ( V_728 . V_732 ) ) ;
if ( V_48 )
continue;
if ( F_80 ( V_6 , & V_29 ,
& V_729 , V_194 , V_27 ,
sizeof( T_13 ) ) )
continue;
if ( V_729 . V_203 == V_204 ||
V_729 . V_203 == V_205 ||
V_729 . V_203 == V_207 ) {
memset ( & V_411 , 0 , sizeof( T_26 ) ) ;
V_411 . V_414 = V_696 ;
V_411 . V_417 = V_728 . V_233 ;
F_241 ( V_6 , & V_411 ) ;
}
}
V_740:
V_27 = 0xFFFF ;
while ( ! ( F_12 ( V_6 , & V_29 ,
& V_28 , V_727 ,
V_27 ) ) ) {
V_30 = F_9 ( V_29 . V_38 ) &
V_39 ;
if ( V_30 == V_41 )
break;
V_27 = F_9 ( V_28 . V_233 ) ;
if ( ! ( F_36 (
F_76 ( V_28 . V_183 ) ) ) )
continue;
V_46 = F_15 ( V_6 ,
F_6 ( V_28 . V_11 ) ) ;
if ( V_46 )
continue;
V_616 = F_9 ( V_28 . V_618 ) ;
if ( ! F_11 ( V_6 , V_616 , & V_9 ) ) {
F_208 ( V_6 , V_9 , V_27 ,
V_28 . V_648 , V_596 ) ;
F_226 ( V_6 , V_27 , 0 , 0 ) ;
}
}
F_3 ( V_58 L_311 , V_6 -> V_35 ) ;
}
void
F_266 ( struct V_5 * V_6 , int V_741 )
{
switch ( V_741 ) {
case V_742 :
F_118 ( V_6 , F_3 ( V_58 L_53
L_312 , V_6 -> V_35 , V_36 ) ) ;
break;
case V_743 :
F_118 ( V_6 , F_3 ( V_58 L_53
L_313 , V_6 -> V_35 , V_36 ) ) ;
if ( V_6 -> V_622 . V_295 & V_300 ) {
V_6 -> V_622 . V_295 |= V_336 ;
F_162 ( V_6 , V_6 -> V_622 . V_88 ) ;
F_107 ( & V_6 -> V_622 . V_301 ) ;
}
if ( V_6 -> V_294 . V_295 & V_300 ) {
V_6 -> V_294 . V_295 |= V_336 ;
F_162 ( V_6 , V_6 -> V_294 . V_88 ) ;
F_107 ( & V_6 -> V_294 . V_301 ) ;
}
F_140 ( V_6 ) ;
F_170 ( V_6 ) ;
break;
case V_744 :
F_118 ( V_6 , F_3 ( V_58 L_53
L_314 , V_6 -> V_35 , V_36 ) ) ;
F_206 ( V_6 ) ;
F_256 ( V_6 ) ;
F_258 ( V_6 ) ;
F_260 ( V_6 ) ;
F_262 ( V_6 ) ;
if ( ! V_6 -> V_49 ) {
F_256 ( V_6 ) ;
F_258 ( V_6 ) ;
F_260 ( V_6 ) ;
F_262 ( V_6 ) ;
F_138 ( V_6 ) ;
}
break;
}
}
static void
V_359 ( struct V_745 * V_746 )
{
struct V_353 * V_354 = F_267 ( V_746 ,
struct V_353 , V_358 . V_746 ) ;
struct V_5 * V_6 = V_354 -> V_6 ;
if ( V_6 -> V_318 || V_354 -> V_365 ||
V_6 -> V_319 ) {
F_137 ( V_6 , V_354 ) ;
return;
}
switch ( V_354 -> V_362 ) {
case V_363 :
while ( F_268 ( V_6 -> V_142 ) )
F_269 ( 1 ) ;
F_263 ( V_6 ) ;
F_265 ( V_6 ) ;
break;
case V_364 :
V_6 -> V_747 = 0 ;
F_23 ( V_6 , F_3 ( V_58 L_315
L_316 , V_6 -> V_35 ) ) ;
break;
case V_560 :
F_195 ( V_6 , V_354 -> V_561 ) ;
break;
case V_406 :
F_230 ( V_6 , V_354 ) ;
break;
case V_570 :
F_232 ( V_6 ,
V_354 ) ;
break;
case V_748 :
F_236 ( V_6 ,
V_354 ) ;
break;
case V_749 :
F_235 ( V_6 ,
V_354 ) ;
break;
case V_750 :
F_234 ( V_6 ,
V_354 ) ;
break;
case V_751 :
F_251 ( V_6 , V_354 ) ;
break;
case V_752 :
F_252 ( V_6 , V_354 ) ;
break;
case V_753 :
F_253 ( V_6 , V_354 ) ;
break;
case V_754 :
F_255 ( V_6 , V_354 ) ;
break;
}
F_137 ( V_6 , V_354 ) ;
}
T_6
F_270 ( struct V_5 * V_6 , T_6 V_292 ,
T_10 V_293 )
{
struct V_353 * V_354 ;
T_31 * V_29 ;
T_4 V_362 ;
T_4 V_226 ;
if ( V_6 -> V_318 || V_6 -> V_319 )
return 1 ;
V_29 = F_106 ( V_6 , V_293 ) ;
V_362 = F_9 ( V_29 -> V_569 ) ;
switch ( V_362 ) {
case V_749 :
{
T_42 * V_755 =
( T_42 * )
V_29 -> V_567 ;
if ( V_755 -> V_756 !=
V_757 )
return 1 ;
if ( V_6 -> V_690 ) {
V_6 -> V_689 ++ ;
return 1 ;
} else
V_6 -> V_690 = 1 ;
break;
}
case V_406 :
F_163 ( V_6 ,
( T_22 * )
V_29 -> V_567 ) ;
break;
case V_751 :
F_166 ( V_6 ,
( T_25 * )
V_29 -> V_567 ) ;
break;
case V_752 :
F_169 ( V_6 ,
( T_27 * )
V_29 -> V_567 ) ;
break;
case V_758 :
{
T_46 * V_759 ;
T_10 * V_760 ;
if ( ! V_6 -> V_190 )
break;
V_759 = ( T_46 * )
V_29 -> V_567 ;
V_760 = ( T_10 * ) V_759 -> V_761 ;
if ( F_9 ( V_759 -> V_762 )
!= V_763 )
break;
switch ( F_76 ( * V_760 ) ) {
case V_764 :
F_3 ( V_99 L_317
L_318
L_319
L_320 , V_6 -> V_35 ) ;
break;
case V_765 :
F_3 ( V_99 L_317
L_321
L_322
L_323 , V_6 -> V_35 ) ;
break;
case V_766 :
F_3 ( V_34 L_324
L_325
L_326
L_327
L_323 , V_6 -> V_35 ) ;
break;
case V_767 :
F_3 ( V_34 L_324
L_328
L_329
L_330 ,
V_6 -> V_35 ) ;
break;
}
break;
}
case V_570 :
case V_754 :
case V_748 :
case V_750 :
case V_753 :
break;
default:
return 1 ;
}
V_354 = F_69 ( sizeof( struct V_353 ) , V_361 ) ;
if ( ! V_354 ) {
F_3 ( V_34 L_2 ,
V_6 -> V_35 , __FILE__ , __LINE__ , V_36 ) ;
return 1 ;
}
V_226 = F_9 ( V_29 -> V_571 ) * 4 ;
V_354 -> V_360 = F_69 ( V_226 , V_361 ) ;
if ( ! V_354 -> V_360 ) {
F_3 ( V_34 L_2 ,
V_6 -> V_35 , __FILE__ , __LINE__ , V_36 ) ;
F_20 ( V_354 ) ;
return 1 ;
}
memcpy ( V_354 -> V_360 , V_29 -> V_567 ,
V_226 ) ;
V_354 -> V_6 = V_6 ;
V_354 -> V_503 = V_29 -> V_503 ;
V_354 -> V_504 = V_29 -> V_504 ;
V_354 -> V_362 = V_362 ;
F_134 ( V_6 , V_354 ) ;
return 1 ;
}
static void
F_222 ( struct V_5 * V_6 ,
struct V_78 * V_79 )
{
struct V_367 * V_368 , * V_100 ;
F_142 (mpt2sas_port, next,
&sas_expander->sas_port_list, port_list) {
if ( V_6 -> V_317 )
return;
if ( V_368 -> V_370 . V_371 ==
V_372 )
F_228 ( V_6 ,
V_368 -> V_370 . V_9 ) ;
else if ( V_368 -> V_370 . V_371 ==
V_373 ||
V_368 -> V_370 . V_371 ==
V_374 )
F_221 ( V_6 ,
V_368 -> V_370 . V_9 ) ;
}
F_26 ( V_6 , V_79 -> V_9 ,
V_79 -> V_69 ) ;
F_3 ( V_58 L_331
L_8 , V_6 -> V_35 ,
V_79 -> V_27 , ( unsigned long long )
V_79 -> V_9 ) ;
F_20 ( V_79 -> V_274 ) ;
F_20 ( V_79 ) ;
}
static void
F_271 ( struct V_5 * V_6 )
{
T_47 * V_103 ;
T_48 * V_29 ;
T_4 V_88 ;
if ( ! V_6 -> V_731 )
return;
if ( F_43 ( & V_6 -> V_77 ) )
return;
F_112 ( & V_6 -> V_622 . V_314 ) ;
if ( V_6 -> V_622 . V_295 != V_296 ) {
F_3 ( V_34 L_332 ,
V_6 -> V_35 , V_36 ) ;
goto V_75;
}
V_6 -> V_622 . V_295 = V_300 ;
V_88 = F_160 ( V_6 , V_6 -> V_768 ) ;
if ( ! V_88 ) {
F_3 ( V_34 L_69 ,
V_6 -> V_35 , V_36 ) ;
V_6 -> V_622 . V_295 = V_296 ;
goto V_75;
}
V_103 = F_48 ( V_6 , V_88 ) ;
V_6 -> V_622 . V_88 = V_88 ;
memset ( V_103 , 0 , sizeof( T_47 ) ) ;
V_103 -> V_329 = V_769 ;
V_103 -> V_555 = V_770 ;
if ( ! V_6 -> V_271 )
F_3 ( V_58 L_333 , V_6 -> V_35 ) ;
F_121 ( & V_6 -> V_622 . V_301 ) ;
F_161 ( V_6 , V_88 ) ;
F_123 ( & V_6 -> V_622 . V_301 , 10 * V_335 ) ;
if ( ! ( V_6 -> V_622 . V_295 & V_297 ) ) {
F_3 ( V_34 L_72 ,
V_6 -> V_35 , V_36 ) ;
goto V_75;
}
if ( V_6 -> V_622 . V_295 & V_299 ) {
V_29 = V_6 -> V_622 . V_293 ;
if ( ! V_6 -> V_271 )
F_3 ( V_58 L_334
L_335 ,
V_6 -> V_35 , F_9 ( V_29 -> V_38 ) ,
F_76 ( V_29 -> V_337 ) ) ;
}
V_75:
V_6 -> V_622 . V_295 = V_296 ;
F_125 ( & V_6 -> V_622 . V_314 ) ;
}
static void
F_272 ( struct V_771 * V_564 )
{
struct V_141 * V_142 = F_273 ( V_564 ) ;
struct V_5 * V_6 = F_58 ( V_142 ) ;
struct V_772 * V_773 ;
unsigned long V_65 ;
V_6 -> V_318 = 1 ;
F_140 ( V_6 ) ;
F_18 ( & V_6 -> V_356 , V_65 ) ;
V_773 = V_6 -> V_355 ;
V_6 -> V_355 = NULL ;
F_21 ( & V_6 -> V_356 , V_65 ) ;
if ( V_773 )
F_274 ( V_773 ) ;
F_271 ( V_6 ) ;
F_275 ( V_6 ) ;
}
static void T_49
F_276 ( struct V_771 * V_564 )
{
struct V_141 * V_142 = F_273 ( V_564 ) ;
struct V_5 * V_6 = F_58 ( V_142 ) ;
struct V_367 * V_368 , * V_774 ;
struct V_47 * V_48 , * V_100 ;
struct V_147 * V_148 ;
struct V_772 * V_773 ;
unsigned long V_65 ;
V_6 -> V_318 = 1 ;
F_140 ( V_6 ) ;
F_18 ( & V_6 -> V_356 , V_65 ) ;
V_773 = V_6 -> V_355 ;
V_6 -> V_355 = NULL ;
F_21 ( & V_6 -> V_356 , V_65 ) ;
if ( V_773 )
F_274 ( V_773 ) ;
F_271 ( V_6 ) ;
F_142 (raid_device, next, &ioc->raid_device_list,
list) {
if ( V_48 -> V_70 ) {
V_148 =
V_48 -> V_70 -> V_150 ;
V_148 -> V_387 = 1 ;
F_244 ( & V_48 -> V_70 -> V_169 ) ;
}
F_3 ( V_58 L_265
L_199 , V_6 -> V_35 , V_48 -> V_27 ,
( unsigned long long ) V_48 -> V_52 ) ;
F_32 ( V_6 , V_48 ) ;
}
F_142 (mpt2sas_port, next_port,
&ioc->sas_hba.sas_port_list, port_list) {
if ( V_368 -> V_370 . V_371 ==
V_372 )
F_228 ( V_6 ,
V_368 -> V_370 . V_9 ) ;
else if ( V_368 -> V_370 . V_371 ==
V_373 ||
V_368 -> V_370 . V_371 ==
V_374 )
F_221 ( V_6 ,
V_368 -> V_370 . V_9 ) ;
}
if ( V_6 -> V_31 . V_32 ) {
F_20 ( V_6 -> V_31 . V_274 ) ;
V_6 -> V_31 . V_274 = NULL ;
V_6 -> V_31 . V_32 = 0 ;
}
F_277 ( V_142 ) ;
F_275 ( V_6 ) ;
F_19 ( & V_6 -> V_67 ) ;
F_278 ( V_142 ) ;
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
V_20 = F_242 ( V_6 -> V_142 , V_174 ,
V_48 -> V_72 , 0 ) ;
if ( V_20 )
F_32 ( V_6 , V_48 ) ;
} else {
V_46 = V_43 ;
V_27 = V_46 -> V_27 ;
V_69 = V_46 -> V_69 ;
V_9 = V_46 -> V_9 ;
F_18 ( & V_6 -> V_66 , V_65 ) ;
F_281 ( & V_46 -> V_67 , & V_6 -> V_68 ) ;
F_21 ( & V_6 -> V_66 , V_65 ) ;
if ( V_6 -> V_651 )
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
F_282 ( struct V_5 * V_6 )
{
struct V_47 * V_48 , * V_775 ;
int V_20 ;
F_142 (raid_device, raid_next,
&ioc->raid_device_list, list) {
if ( V_48 -> V_70 )
continue;
V_20 = F_242 ( V_6 -> V_142 , V_174 ,
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
F_142 (sas_device, next, &ioc->sas_device_init_list,
list) {
if ( V_6 -> V_651 )
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
F_281 ( & V_46 -> V_67 , & V_6 -> V_68 ) ;
F_21 ( & V_6 -> V_66 , V_65 ) ;
}
}
static void
F_284 ( struct V_5 * V_6 )
{
T_4 V_776 ;
if ( ! ( V_6 -> V_257 . V_777 & V_778 ) )
return;
F_280 ( V_6 ) ;
if ( V_6 -> V_731 ) {
V_776 =
F_9 ( V_6 -> V_779 . V_780 ) &
V_781 ;
if ( V_776 ==
V_782 ) {
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
if ( V_783 != - 1 && V_783 != 0 )
F_286 ( V_6 , V_783 ) ;
V_6 -> V_747 = 1 ;
V_20 = F_287 ( V_6 ) ;
if ( V_20 != 0 )
F_3 ( V_58 L_336 , V_6 -> V_35 ) ;
}
static int
F_288 ( struct V_141 * V_142 , unsigned long time )
{
struct V_5 * V_6 = F_58 ( V_142 ) ;
if ( time >= ( 300 * V_335 ) ) {
V_6 -> V_784 . V_295 = V_296 ;
F_3 ( V_58 L_337
L_338 , V_6 -> V_35 ) ;
V_6 -> V_49 = 0 ;
return 1 ;
}
if ( V_6 -> V_747 )
return 0 ;
if ( V_6 -> V_785 ) {
F_3 ( V_58 L_339
L_340 , V_6 -> V_35 , V_6 -> V_785 ) ;
V_6 -> V_49 = 0 ;
V_6 -> V_649 = 0 ;
V_6 -> V_318 = 1 ;
return 1 ;
}
F_3 ( V_58 L_341 , V_6 -> V_35 ) ;
V_6 -> V_784 . V_295 = V_296 ;
if ( V_6 -> V_649 ) {
V_6 -> V_649 = 0 ;
F_284 ( V_6 ) ;
}
F_289 ( V_6 ) ;
V_6 -> V_49 = 0 ;
return 1 ;
}
static int
F_290 ( struct V_771 * V_564 , const struct V_786 * V_72 )
{
struct V_5 * V_6 ;
struct V_141 * V_142 ;
V_142 = F_291 ( & V_787 ,
sizeof( struct V_5 ) ) ;
if ( ! V_142 )
return - V_788 ;
V_6 = F_58 ( V_142 ) ;
memset ( V_6 , 0 , sizeof( struct V_5 ) ) ;
F_153 ( & V_6 -> V_67 ) ;
F_24 ( & V_6 -> V_67 , & V_789 ) ;
V_6 -> V_142 = V_142 ;
V_6 -> V_72 = V_790 ++ ;
sprintf ( V_6 -> V_35 , L_342 , V_791 , V_6 -> V_72 ) ;
V_6 -> V_564 = V_564 ;
if ( V_72 -> V_43 == V_792 ) {
V_6 -> V_190 = 1 ;
V_6 -> V_271 = 1 ;
} else
V_6 -> V_244 = V_245 ;
V_6 -> V_487 = V_487 ;
V_6 -> V_327 = V_327 ;
V_6 -> V_793 = V_793 ;
V_6 -> V_794 = V_794 ;
V_6 -> V_795 = V_795 ;
V_6 -> V_796 = V_796 ;
V_6 -> V_768 = V_768 ;
V_6 -> V_797 = V_797 ;
V_6 -> V_388 = V_388 ;
V_6 -> V_390 = V_390 ;
V_6 -> V_394 = V_394 ;
V_6 -> V_8 = V_8 ;
V_6 -> V_798 = & F_170 ;
F_292 ( & V_6 -> V_799 ) ;
F_293 ( & V_6 -> V_800 ) ;
F_293 ( & V_6 -> V_91 ) ;
F_293 ( & V_6 -> V_66 ) ;
F_293 ( & V_6 -> V_80 ) ;
F_293 ( & V_6 -> V_356 ) ;
F_293 ( & V_6 -> V_76 ) ;
F_153 ( & V_6 -> V_68 ) ;
F_153 ( & V_6 -> V_71 ) ;
F_153 ( & V_6 -> V_81 ) ;
F_153 ( & V_6 -> V_357 ) ;
F_153 ( & V_6 -> V_77 ) ;
F_153 ( & V_6 -> V_31 . V_621 ) ;
F_153 ( & V_6 -> V_389 ) ;
F_153 ( & V_6 -> V_391 ) ;
V_142 -> V_801 = 32 ;
V_142 -> V_802 = V_802 ;
V_142 -> V_803 = V_804 ;
V_142 -> V_805 = V_6 -> V_72 ;
if ( V_806 != 0xFFFF ) {
if ( V_806 < 64 ) {
V_142 -> V_806 = 64 ;
F_3 ( V_99 L_343
L_344
L_345 , V_6 -> V_35 , V_806 ) ;
} else if ( V_806 > 32767 ) {
V_142 -> V_806 = 32767 ;
F_3 ( V_99 L_343
L_344
L_346 , V_6 -> V_35 ,
V_806 ) ;
} else {
V_142 -> V_806 = V_806 & 0xFFFE ;
F_3 ( V_58 L_347
L_348 , V_6 -> V_35 , V_142 -> V_806 ) ;
}
}
if ( ( F_294 ( V_142 , & V_564 -> V_169 ) ) ) {
F_3 ( V_34 L_2 ,
V_6 -> V_35 , __FILE__ , __LINE__ , V_36 ) ;
F_19 ( & V_6 -> V_67 ) ;
goto V_807;
}
F_295 ( V_142 , V_808
| V_809 | V_810 ) ;
F_296 ( V_142 , V_811 ) ;
snprintf ( V_6 -> V_812 , sizeof( V_6 -> V_812 ) ,
L_349 , V_6 -> V_72 ) ;
V_6 -> V_355 = F_297 (
V_6 -> V_812 ) ;
if ( ! V_6 -> V_355 ) {
F_3 ( V_34 L_2 ,
V_6 -> V_35 , __FILE__ , __LINE__ , V_36 ) ;
goto V_813;
}
V_6 -> V_49 = 1 ;
if ( ( F_298 ( V_6 ) ) ) {
F_3 ( V_34 L_2 ,
V_6 -> V_35 , __FILE__ , __LINE__ , V_36 ) ;
goto V_814;
}
if ( V_6 -> V_190 ) {
if ( V_6 -> V_244 == V_245 )
V_6 -> V_651 = 0 ;
else if ( V_6 -> V_244 == V_815 )
V_6 -> V_651 = 1 ;
else {
if ( F_91 ( V_6 ) )
V_6 -> V_651 = 1 ;
else
V_6 -> V_651 = 0 ;
}
} else
V_6 -> V_651 = 0 ;
F_299 ( V_142 ) ;
return 0 ;
V_814:
F_274 ( V_6 -> V_355 ) ;
V_813:
F_19 ( & V_6 -> V_67 ) ;
F_278 ( V_142 ) ;
F_279 ( V_142 ) ;
V_807:
return - V_788 ;
}
static int
F_300 ( struct V_771 * V_564 , T_50 V_200 )
{
struct V_141 * V_142 = F_273 ( V_564 ) ;
struct V_5 * V_6 = F_58 ( V_142 ) ;
T_51 V_816 ;
F_301 ( V_6 ) ;
F_302 ( V_142 ) ;
V_816 = F_303 ( V_564 , V_200 ) ;
F_3 ( V_58 L_350
L_351 , V_6 -> V_35 , V_564 ,
F_304 ( V_564 ) , V_816 ) ;
F_305 ( V_6 ) ;
F_306 ( V_564 ) ;
F_307 ( V_564 ) ;
F_308 ( V_564 , V_816 ) ;
return 0 ;
}
static int
F_309 ( struct V_771 * V_564 )
{
struct V_141 * V_142 = F_273 ( V_564 ) ;
struct V_5 * V_6 = F_58 ( V_142 ) ;
T_51 V_816 = V_564 -> V_817 ;
int V_74 ;
F_3 ( V_58 L_352
L_351 , V_6 -> V_35 , V_564 ,
F_304 ( V_564 ) , V_816 ) ;
F_308 ( V_564 , V_818 ) ;
F_310 ( V_564 , V_818 , 0 ) ;
F_311 ( V_564 ) ;
V_6 -> V_564 = V_564 ;
V_74 = F_312 ( V_6 ) ;
if ( V_74 )
return V_74 ;
F_115 ( V_6 , V_321 , V_819 ) ;
F_313 ( V_142 ) ;
F_289 ( V_6 ) ;
return 0 ;
}
static T_52
F_314 ( struct V_771 * V_564 , T_53 V_200 )
{
struct V_141 * V_142 = F_273 ( V_564 ) ;
struct V_5 * V_6 = F_58 ( V_142 ) ;
F_3 ( V_58 L_353 ,
V_6 -> V_35 , V_200 ) ;
switch ( V_200 ) {
case V_820 :
return V_821 ;
case V_822 :
V_6 -> V_319 = 1 ;
F_302 ( V_6 -> V_142 ) ;
F_301 ( V_6 ) ;
F_305 ( V_6 ) ;
return V_823 ;
case V_824 :
V_6 -> V_319 = 1 ;
F_301 ( V_6 ) ;
F_170 ( V_6 ) ;
return V_825 ;
}
return V_823 ;
}
static T_52
F_315 ( struct V_771 * V_564 )
{
struct V_141 * V_142 = F_273 ( V_564 ) ;
struct V_5 * V_6 = F_58 ( V_142 ) ;
int V_20 ;
F_3 ( V_58 L_354 ,
V_6 -> V_35 ) ;
V_6 -> V_319 = 0 ;
V_6 -> V_564 = V_564 ;
F_311 ( V_564 ) ;
V_20 = F_312 ( V_6 ) ;
if ( V_20 )
return V_825 ;
V_20 = F_115 ( V_6 , V_321 ,
V_322 ) ;
F_3 ( V_99 L_355 , V_6 -> V_35 ,
( V_20 == 0 ) ? L_127 : L_356 ) ;
if ( ! V_20 )
return V_826 ;
else
return V_825 ;
}
static void
F_316 ( struct V_771 * V_564 )
{
struct V_141 * V_142 = F_273 ( V_564 ) ;
struct V_5 * V_6 = F_58 ( V_142 ) ;
F_3 ( V_58 L_357 , V_6 -> V_35 ) ;
F_317 ( V_564 ) ;
F_289 ( V_6 ) ;
F_313 ( V_6 -> V_142 ) ;
}
static T_52
F_318 ( struct V_771 * V_564 )
{
struct V_141 * V_142 = F_273 ( V_564 ) ;
struct V_5 * V_6 = F_58 ( V_142 ) ;
F_3 ( V_58 L_358 ,
V_6 -> V_35 ) ;
return V_823 ;
}
static int T_54
F_319 ( void )
{
int error ;
V_790 = 0 ;
F_3 ( V_7 L_359 , V_791 ,
V_827 ) ;
V_804 =
F_320 ( & V_828 ) ;
if ( ! V_804 )
return - V_788 ;
V_197 = F_321 ( & V_829 ) ;
if ( ! V_197 ) {
F_322 ( V_804 ) ;
return - V_788 ;
}
F_323 () ;
V_487 = F_324 ( F_201 ) ;
V_327 = F_324 ( F_104 ) ;
V_794 = F_324 ( V_830 ) ;
V_795 = F_324 (
V_831 ) ;
V_796 = F_324 (
V_832 ) ;
V_768 = F_324 ( F_220 ) ;
V_797 = F_324 (
V_833 ) ;
V_793 = F_324 ( V_834 ) ;
V_388 = F_324 (
F_159 ) ;
V_390 = F_324 (
F_157 ) ;
V_394 = F_324 (
F_154 ) ;
F_325 () ;
error = F_326 ( & V_835 ) ;
if ( error ) {
F_327 ( V_197 ) ;
F_322 ( V_804 ) ;
}
return error ;
}
static void T_55
F_328 ( void )
{
F_3 ( V_7 L_360 ,
V_827 ) ;
F_329 ( & V_835 ) ;
F_330 () ;
F_331 ( V_487 ) ;
F_331 ( V_327 ) ;
F_331 ( V_794 ) ;
F_331 ( V_795 ) ;
F_331 ( V_796 ) ;
F_331 ( V_768 ) ;
F_331 ( V_797 ) ;
F_331 ( V_793 ) ;
F_331 ( V_388 ) ;
F_331 ( V_390 ) ;
F_331 ( V_394 ) ;
F_327 ( V_197 ) ;
F_322 ( V_804 ) ;
}
