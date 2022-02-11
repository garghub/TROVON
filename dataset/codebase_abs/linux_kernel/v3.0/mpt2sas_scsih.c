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
if ( V_27 <= V_6 -> V_31 . V_32 ) {
* V_9 = V_6 -> V_31 . V_9 ;
return 0 ;
} else
* V_9 = 0 ;
if ( ( F_12 ( V_6 , & V_29 , & V_28 ,
V_33 , V_27 ) ) ) {
F_3 ( V_34 L_2 ,
V_6 -> V_35 , __FILE__ , __LINE__ , V_36 ) ;
return - V_37 ;
}
V_30 = F_9 ( V_29 . V_38 ) &
V_39 ;
if ( V_30 != V_40 ) {
F_3 ( V_34 L_3
L_4 , V_6 -> V_35 , V_27 , V_30 ,
__FILE__ , __LINE__ , V_36 ) ;
return - V_41 ;
}
* V_9 = F_6 ( V_28 . V_11 ) ;
return 0 ;
}
static void
F_13 ( struct V_5 * V_6 ,
void * V_42 , T_6 V_43 )
{
struct V_44 * V_45 ;
struct V_46 * V_47 ;
T_1 V_9 ;
T_1 V_12 ;
T_1 V_14 ;
T_4 V_18 ;
if ( ! V_6 -> V_48 )
return;
if ( ! V_43 ) {
V_45 = V_42 ;
V_9 = V_45 -> V_9 ;
V_12 = V_45 -> V_12 ;
V_14 = V_45 -> V_14 ;
V_18 = V_45 -> V_18 ;
} else {
V_47 = V_42 ;
V_9 = V_47 -> V_49 ;
V_12 = 0 ;
V_14 = 0 ;
V_18 = 0 ;
}
if ( ! V_6 -> V_50 . V_42 ) {
if ( F_10 ( V_9 , V_12 ,
V_14 , V_18 ,
( V_6 -> V_51 . V_52 &
V_53 ) ,
& V_6 -> V_51 . V_54 ) ) {
F_14 ( V_6 , F_3 ( V_55
L_5 ,
V_6 -> V_35 , V_36 ,
( unsigned long long ) V_9 ) ) ;
V_6 -> V_50 . V_42 = V_42 ;
V_6 -> V_50 . V_43 = V_43 ;
}
}
if ( ! V_6 -> V_56 . V_42 ) {
if ( F_10 ( V_9 , V_12 ,
V_14 , V_18 ,
( V_6 -> V_51 . V_57 &
V_53 ) ,
& V_6 -> V_51 . V_58 ) ) {
F_14 ( V_6 , F_3 ( V_55
L_6 ,
V_6 -> V_35 , V_36 ,
( unsigned long long ) V_9 ) ) ;
V_6 -> V_56 . V_42 = V_42 ;
V_6 -> V_56 . V_43 = V_43 ;
}
}
if ( ! V_6 -> V_59 . V_42 ) {
if ( F_10 ( V_9 , V_12 ,
V_14 , V_18 ,
( V_6 -> V_51 . V_60 &
V_53 ) ,
& V_6 -> V_51 . V_61 ) ) {
F_14 ( V_6 , F_3 ( V_55
L_7 ,
V_6 -> V_35 , V_36 ,
( unsigned long long ) V_9 ) ) ;
V_6 -> V_59 . V_42 = V_42 ;
V_6 -> V_59 . V_43 = V_43 ;
}
}
}
struct V_44 *
F_15 ( struct V_5 * V_6 ,
T_1 V_9 )
{
struct V_44 * V_45 ;
F_4 (sas_device, &ioc->sas_device_list, list)
if ( V_45 -> V_9 == V_9 )
return V_45 ;
F_4 (sas_device, &ioc->sas_device_init_list, list)
if ( V_45 -> V_9 == V_9 )
return V_45 ;
return NULL ;
}
static struct V_44 *
F_16 ( struct V_5 * V_6 , T_4 V_27 )
{
struct V_44 * V_45 ;
F_4 (sas_device, &ioc->sas_device_list, list)
if ( V_45 -> V_27 == V_27 )
return V_45 ;
F_4 (sas_device, &ioc->sas_device_init_list, list)
if ( V_45 -> V_27 == V_27 )
return V_45 ;
return NULL ;
}
static void
F_17 ( struct V_5 * V_6 ,
struct V_44 * V_45 )
{
unsigned long V_62 ;
if ( ! V_45 )
return;
F_18 ( & V_6 -> V_63 , V_62 ) ;
if ( F_15 ( V_6 ,
V_45 -> V_9 ) ) {
F_19 ( & V_45 -> V_64 ) ;
F_20 ( V_45 ) ;
}
F_21 ( & V_6 -> V_63 , V_62 ) ;
}
static void
F_22 ( struct V_5 * V_6 ,
struct V_44 * V_45 )
{
unsigned long V_62 ;
F_23 ( V_6 , F_3 ( V_55 L_8
L_9 , V_6 -> V_35 , V_36 ,
V_45 -> V_27 , ( unsigned long long ) V_45 -> V_9 ) ) ;
F_18 ( & V_6 -> V_63 , V_62 ) ;
F_24 ( & V_45 -> V_64 , & V_6 -> V_65 ) ;
F_21 ( & V_6 -> V_63 , V_62 ) ;
if ( ! F_25 ( V_6 , V_45 -> V_27 ,
V_45 -> V_66 ) )
F_17 ( V_6 , V_45 ) ;
}
static void
F_26 ( struct V_5 * V_6 ,
struct V_44 * V_45 )
{
unsigned long V_62 ;
F_23 ( V_6 , F_3 ( V_55 L_8
L_9 , V_6 -> V_35 , V_36 ,
V_45 -> V_27 , ( unsigned long long ) V_45 -> V_9 ) ) ;
F_18 ( & V_6 -> V_63 , V_62 ) ;
F_24 ( & V_45 -> V_64 , & V_6 -> V_67 ) ;
F_21 ( & V_6 -> V_63 , V_62 ) ;
F_13 ( V_6 , V_45 , 0 ) ;
}
static struct V_46 *
F_27 ( struct V_5 * V_6 , int V_68 , int V_69 )
{
struct V_46 * V_47 , * V_70 ;
V_70 = NULL ;
F_4 (raid_device, &ioc->raid_device_list, list) {
if ( V_47 -> V_68 == V_68 && V_47 -> V_69 == V_69 ) {
V_70 = V_47 ;
goto V_71;
}
}
V_71:
return V_70 ;
}
static struct V_46 *
F_28 ( struct V_5 * V_6 , T_4 V_27 )
{
struct V_46 * V_47 , * V_70 ;
V_70 = NULL ;
F_4 (raid_device, &ioc->raid_device_list, list) {
if ( V_47 -> V_27 != V_27 )
continue;
V_70 = V_47 ;
goto V_71;
}
V_71:
return V_70 ;
}
static struct V_46 *
F_29 ( struct V_5 * V_6 , T_1 V_49 )
{
struct V_46 * V_47 , * V_70 ;
V_70 = NULL ;
F_4 (raid_device, &ioc->raid_device_list, list) {
if ( V_47 -> V_49 != V_49 )
continue;
V_70 = V_47 ;
goto V_71;
}
V_71:
return V_70 ;
}
static void
F_30 ( struct V_5 * V_6 ,
struct V_46 * V_47 )
{
unsigned long V_62 ;
F_23 ( V_6 , F_3 ( V_55 L_8
L_10 , V_6 -> V_35 , V_36 ,
V_47 -> V_27 , ( unsigned long long ) V_47 -> V_49 ) ) ;
F_18 ( & V_6 -> V_72 , V_62 ) ;
F_24 ( & V_47 -> V_64 , & V_6 -> V_73 ) ;
F_21 ( & V_6 -> V_72 , V_62 ) ;
}
static void
F_31 ( struct V_5 * V_6 ,
struct V_46 * V_47 )
{
unsigned long V_62 ;
F_18 ( & V_6 -> V_72 , V_62 ) ;
F_19 ( & V_47 -> V_64 ) ;
memset ( V_47 , 0 , sizeof( struct V_46 ) ) ;
F_20 ( V_47 ) ;
F_21 ( & V_6 -> V_72 , V_62 ) ;
}
struct V_74 *
F_32 ( struct V_5 * V_6 , T_4 V_27 )
{
struct V_74 * V_75 , * V_70 ;
V_70 = NULL ;
F_4 (sas_expander, &ioc->sas_expander_list, list) {
if ( V_75 -> V_27 != V_27 )
continue;
V_70 = V_75 ;
goto V_71;
}
V_71:
return V_70 ;
}
struct V_74 *
F_33 ( struct V_5 * V_6 ,
T_1 V_9 )
{
struct V_74 * V_75 , * V_70 ;
V_70 = NULL ;
F_4 (sas_expander, &ioc->sas_expander_list, list) {
if ( V_75 -> V_9 != V_9 )
continue;
V_70 = V_75 ;
goto V_71;
}
V_71:
return V_70 ;
}
static void
F_34 ( struct V_5 * V_6 ,
struct V_74 * V_75 )
{
unsigned long V_62 ;
F_18 ( & V_6 -> V_76 , V_62 ) ;
F_24 ( & V_75 -> V_64 , & V_6 -> V_77 ) ;
F_21 ( & V_6 -> V_76 , V_62 ) ;
}
static int
F_35 ( T_10 V_78 )
{
if ( V_78 & V_79 &&
( ( V_78 & V_80 ) |
( V_78 & V_81 ) |
( V_78 & V_82 ) ) )
return 1 ;
else
return 0 ;
}
static struct V_83 *
F_36 ( struct V_5 * V_6 , T_4 V_84 )
{
return V_6 -> V_85 [ V_84 - 1 ] . V_86 ;
}
static inline struct V_83 *
F_37 ( struct V_5 * V_6 , T_4 V_84 )
{
unsigned long V_62 ;
struct V_83 * V_86 ;
F_18 ( & V_6 -> V_87 , V_62 ) ;
V_86 = V_6 -> V_85 [ V_84 - 1 ] . V_86 ;
V_6 -> V_85 [ V_84 - 1 ] . V_86 = NULL ;
F_21 ( & V_6 -> V_87 , V_62 ) ;
return V_86 ;
}
static T_4
F_38 ( struct V_5 * V_6 , struct V_83
* V_86 )
{
T_4 V_84 ;
unsigned long V_62 ;
int V_88 ;
F_18 ( & V_6 -> V_87 , V_62 ) ;
V_84 = 0 ;
for ( V_88 = 0 ; V_88 < V_6 -> V_89 ; V_88 ++ ) {
if ( V_6 -> V_85 [ V_88 ] . V_86 == V_86 ) {
V_84 = V_6 -> V_85 [ V_88 ] . V_84 ;
goto V_71;
}
}
V_71:
F_21 ( & V_6 -> V_87 , V_62 ) ;
return V_84 ;
}
static T_6
F_39 ( struct V_5 * V_6 , int V_68 ,
int V_69 )
{
T_6 V_90 ;
unsigned long V_62 ;
int V_88 ;
F_18 ( & V_6 -> V_87 , V_62 ) ;
V_90 = 0 ;
for ( V_88 = 0 ; V_88 < V_6 -> V_89 ; V_88 ++ ) {
if ( V_6 -> V_85 [ V_88 ] . V_86 &&
( V_6 -> V_85 [ V_88 ] . V_86 -> V_42 -> V_68 == V_68 &&
V_6 -> V_85 [ V_88 ] . V_86 -> V_42 -> V_69 == V_69 ) ) {
V_90 = 1 ;
goto V_71;
}
}
V_71:
F_21 ( & V_6 -> V_87 , V_62 ) ;
return V_90 ;
}
static T_6
F_40 ( struct V_5 * V_6 , int V_68 ,
unsigned int V_91 , int V_69 )
{
T_6 V_90 ;
unsigned long V_62 ;
int V_88 ;
F_18 ( & V_6 -> V_87 , V_62 ) ;
V_90 = 0 ;
for ( V_88 = 0 ; V_88 < V_6 -> V_89 ; V_88 ++ ) {
if ( V_6 -> V_85 [ V_88 ] . V_86 &&
( V_6 -> V_85 [ V_88 ] . V_86 -> V_42 -> V_68 == V_68 &&
V_6 -> V_85 [ V_88 ] . V_86 -> V_42 -> V_69 == V_69 &&
V_6 -> V_85 [ V_88 ] . V_86 -> V_42 -> V_91 == V_91 ) ) {
V_90 = 1 ;
goto V_71;
}
}
V_71:
F_21 ( & V_6 -> V_87 , V_62 ) ;
return V_90 ;
}
static struct V_92 *
F_41 ( struct V_5 * V_6 , T_4 V_84 )
{
struct V_92 * V_93 ;
unsigned long V_62 ;
F_18 ( & V_6 -> V_87 , V_62 ) ;
if ( F_42 ( & V_6 -> V_94 ) ) {
F_21 ( & V_6 -> V_87 , V_62 ) ;
F_3 ( V_95 L_11 ,
V_6 -> V_35 ) ;
return NULL ;
}
V_93 = F_43 ( V_6 -> V_94 . V_96 ,
struct V_92 , V_97 ) ;
F_44 ( & V_93 -> V_97 ) ;
F_24 ( & V_93 -> V_97 ,
& V_6 -> V_85 [ V_84 - 1 ] . V_98 ) ;
F_21 ( & V_6 -> V_87 , V_62 ) ;
return V_93 ;
}
static int
F_45 ( struct V_5 * V_6 ,
struct V_83 * V_86 , T_4 V_84 )
{
T_11 * V_99 ;
T_12 V_100 ;
struct V_101 * V_102 ;
void * V_103 , * V_104 ;
T_10 V_105 ;
T_10 V_106 ;
T_10 V_107 ;
int V_108 ;
T_10 V_109 ;
T_10 V_110 ;
T_10 V_111 ;
T_10 V_112 ;
struct V_92 * V_93 ;
V_99 = F_46 ( V_6 , V_84 ) ;
V_110 = V_113 ;
if ( V_86 -> V_114 == V_115 )
V_110 |= V_116 ;
V_111 = ( V_110 | V_117 )
<< V_118 ;
V_112 = ( V_110 | V_117 |
V_119 | V_120 )
<< V_118 ;
V_110 = V_110 << V_118 ;
V_102 = F_47 ( V_86 ) ;
V_108 = F_48 ( V_86 ) ;
if ( V_108 < 0 ) {
F_49 ( V_121 , V_86 -> V_42 , L_12
L_13 , F_50 ( V_86 ) ) ;
return - V_122 ;
}
V_103 = & V_99 -> V_123 ;
V_109 = V_6 -> V_124 ;
if ( V_108 <= V_109 )
goto V_125;
V_99 -> V_126 = ( F_51 ( T_11 , V_123 ) +
( V_109 * V_6 -> V_127 ) ) / 4 ;
while ( V_109 ) {
if ( V_109 == 1 )
V_6 -> V_128 ( V_103 ,
V_111 | F_52 ( V_102 ) ,
F_53 ( V_102 ) ) ;
else
V_6 -> V_128 ( V_103 , V_110 |
F_52 ( V_102 ) , F_53 ( V_102 ) ) ;
V_102 = F_54 ( V_102 ) ;
V_103 += V_6 -> V_127 ;
V_108 -- ;
V_109 -- ;
}
V_107 = V_129 << V_118 ;
V_93 = F_41 ( V_6 , V_84 ) ;
if ( ! V_93 )
return - 1 ;
V_104 = V_93 -> V_130 ;
V_100 = V_93 -> V_131 ;
do {
V_109 = ( V_108 <=
V_6 -> V_132 ) ? V_108 :
V_6 -> V_132 ;
V_105 = ( V_108 == V_109 ) ?
0 : ( V_109 * V_6 -> V_127 ) / 4 ;
V_106 = V_109 * V_6 -> V_127 ;
if ( V_105 ) {
V_105 = V_105 <<
V_133 ;
V_106 += V_6 -> V_127 ;
}
V_6 -> V_128 ( V_103 , V_107 | V_105 |
V_106 , V_100 ) ;
V_103 = V_104 ;
if ( ! V_105 )
goto V_125;
while ( V_109 ) {
if ( V_109 == 1 )
V_6 -> V_128 ( V_103 ,
V_111 |
F_52 ( V_102 ) ,
F_53 ( V_102 ) ) ;
else
V_6 -> V_128 ( V_103 , V_110 |
F_52 ( V_102 ) ,
F_53 ( V_102 ) ) ;
V_102 = F_54 ( V_102 ) ;
V_103 += V_6 -> V_127 ;
V_108 -- ;
V_109 -- ;
}
V_93 = F_41 ( V_6 , V_84 ) ;
if ( ! V_93 )
return - 1 ;
V_104 = V_93 -> V_130 ;
V_100 = V_93 -> V_131 ;
} while ( 1 );
V_125:
while ( V_108 ) {
if ( V_108 == 1 )
V_6 -> V_128 ( V_103 , V_112 |
F_52 ( V_102 ) , F_53 ( V_102 ) ) ;
else
V_6 -> V_128 ( V_103 , V_110 |
F_52 ( V_102 ) , F_53 ( V_102 ) ) ;
V_102 = F_54 ( V_102 ) ;
V_103 += V_6 -> V_127 ;
V_108 -- ;
}
return 0 ;
}
static void
F_55 ( struct V_134 * V_135 , int V_136 )
{
struct V_137 * V_138 = V_135 -> V_139 ;
int V_140 ;
struct V_5 * V_6 = F_56 ( V_138 ) ;
struct V_141 * V_142 ;
struct V_143 * V_144 ;
struct V_44 * V_45 ;
unsigned long V_62 ;
V_140 = V_138 -> V_145 ;
V_142 = V_135 -> V_146 ;
if ( ! V_142 )
goto V_147;
V_144 = V_142 -> V_148 ;
if ( ! V_144 )
goto V_147;
if ( ( V_144 -> V_62 & V_149 ) )
goto V_147;
F_18 ( & V_6 -> V_63 , V_62 ) ;
V_45 = F_15 ( V_6 ,
V_142 -> V_148 -> V_9 ) ;
F_21 ( & V_6 -> V_63 , V_62 ) ;
if ( V_45 && V_45 -> V_78 &
V_82 )
V_140 = V_150 ;
V_147:
if ( ! V_135 -> V_151 )
V_140 = 1 ;
if ( V_136 > V_140 )
V_136 = V_140 ;
F_57 ( V_135 , F_58 ( V_135 ) , V_136 ) ;
}
static int
F_59 ( struct V_134 * V_135 , int V_136 , int V_152 )
{
if ( V_152 == V_153 || V_152 == V_154 )
F_55 ( V_135 , V_136 ) ;
else if ( V_152 == V_155 )
F_60 ( V_135 , V_136 ) ;
else
return - V_156 ;
if ( V_135 -> V_157 > 7 )
F_49 ( V_7 , V_135 , L_14
L_15 ,
V_135 -> V_158 , V_135 -> V_151 , V_135 -> V_159 ,
V_135 -> V_160 , V_135 -> V_161 ,
( V_135 -> V_162 [ 7 ] & 2 ) >> 1 ) ;
return V_135 -> V_158 ;
}
static int
F_61 ( struct V_134 * V_135 , int V_163 )
{
if ( V_135 -> V_151 ) {
F_62 ( V_135 , V_163 ) ;
if ( V_163 )
F_63 ( V_135 , V_135 -> V_158 ) ;
else
F_64 ( V_135 , V_135 -> V_158 ) ;
} else
V_163 = 0 ;
return V_163 ;
}
static int
F_65 ( struct V_164 * V_165 )
{
struct V_137 * V_138 = F_66 ( & V_165 -> V_166 ) ;
struct V_5 * V_6 = F_56 ( V_138 ) ;
struct V_143 * V_144 ;
struct V_44 * V_45 ;
struct V_46 * V_47 ;
unsigned long V_62 ;
struct V_167 * V_168 ;
V_144 = F_67 ( sizeof( struct V_164 ) , V_169 ) ;
if ( ! V_144 )
return - V_122 ;
V_165 -> V_146 = V_144 ;
V_144 -> V_165 = V_165 ;
V_144 -> V_27 = V_170 ;
if ( V_165 -> V_69 == V_171 ) {
F_18 ( & V_6 -> V_72 , V_62 ) ;
V_47 = F_27 ( V_6 , V_165 -> V_68 ,
V_165 -> V_69 ) ;
if ( V_47 ) {
V_144 -> V_27 = V_47 -> V_27 ;
V_144 -> V_9 = V_47 -> V_49 ;
V_144 -> V_62 |= V_149 ;
V_144 -> V_47 = V_47 ;
V_47 -> V_165 = V_165 ;
}
F_21 ( & V_6 -> V_72 , V_62 ) ;
return 0 ;
}
F_18 ( & V_6 -> V_63 , V_62 ) ;
V_168 = F_68 ( V_165 -> V_166 . V_172 ) ;
V_45 = F_15 ( V_6 ,
V_168 -> V_173 . V_9 ) ;
if ( V_45 ) {
V_144 -> V_27 = V_45 -> V_27 ;
V_144 -> V_9 = V_45 -> V_9 ;
V_45 -> V_165 = V_165 ;
V_45 -> V_68 = V_165 -> V_68 ;
V_45 -> V_69 = V_165 -> V_69 ;
if ( F_69 ( V_45 -> V_27 , V_6 -> V_174 ) )
V_144 -> V_62 |=
V_175 ;
}
F_21 ( & V_6 -> V_63 , V_62 ) ;
return 0 ;
}
static void
F_70 ( struct V_164 * V_165 )
{
struct V_137 * V_138 = F_66 ( & V_165 -> V_166 ) ;
struct V_5 * V_6 = F_56 ( V_138 ) ;
struct V_143 * V_144 ;
struct V_44 * V_45 ;
struct V_46 * V_47 ;
unsigned long V_62 ;
struct V_167 * V_168 ;
V_144 = V_165 -> V_146 ;
if ( ! V_144 )
return;
if ( V_165 -> V_69 == V_171 ) {
F_18 ( & V_6 -> V_72 , V_62 ) ;
V_47 = F_27 ( V_6 , V_165 -> V_68 ,
V_165 -> V_69 ) ;
if ( V_47 ) {
V_47 -> V_165 = NULL ;
V_47 -> V_135 = NULL ;
}
F_21 ( & V_6 -> V_72 , V_62 ) ;
goto V_71;
}
F_18 ( & V_6 -> V_63 , V_62 ) ;
V_168 = F_68 ( V_165 -> V_166 . V_172 ) ;
V_45 = F_15 ( V_6 ,
V_168 -> V_173 . V_9 ) ;
if ( V_45 && ( V_45 -> V_165 == V_165 ) &&
( V_45 -> V_68 == V_165 -> V_68 ) &&
( V_45 -> V_69 == V_165 -> V_69 ) )
V_45 -> V_165 = NULL ;
F_21 ( & V_6 -> V_63 , V_62 ) ;
V_71:
F_20 ( V_144 ) ;
V_165 -> V_146 = NULL ;
}
static int
F_71 ( struct V_134 * V_135 )
{
struct V_137 * V_138 ;
struct V_5 * V_6 ;
struct V_143 * V_144 ;
struct V_141 * V_142 ;
struct V_164 * V_165 ;
struct V_46 * V_47 ;
unsigned long V_62 ;
V_142 = F_67 ( sizeof( struct V_134 ) , V_169 ) ;
if ( ! V_142 )
return - V_122 ;
V_142 -> V_91 = V_135 -> V_91 ;
V_142 -> V_62 = V_176 ;
V_165 = V_164 ( V_135 ) ;
V_144 = V_165 -> V_146 ;
V_144 -> V_177 ++ ;
V_142 -> V_148 = V_144 ;
V_135 -> V_146 = V_142 ;
if ( ( V_144 -> V_62 & V_175 ) )
V_135 -> V_178 = 1 ;
V_138 = F_66 ( & V_165 -> V_166 ) ;
V_6 = F_56 ( V_138 ) ;
if ( V_165 -> V_69 == V_171 ) {
F_18 ( & V_6 -> V_72 , V_62 ) ;
V_47 = F_27 ( V_6 ,
V_165 -> V_68 , V_165 -> V_69 ) ;
if ( V_47 )
V_47 -> V_135 = V_135 ;
F_21 ( & V_6 -> V_72 , V_62 ) ;
}
return 0 ;
}
static void
F_72 ( struct V_134 * V_135 )
{
struct V_143 * V_144 ;
struct V_164 * V_165 ;
if ( ! V_135 -> V_146 )
return;
V_165 = V_164 ( V_135 ) ;
V_144 = V_165 -> V_146 ;
V_144 -> V_177 -- ;
F_20 ( V_135 -> V_146 ) ;
V_135 -> V_146 = NULL ;
}
static void
F_73 ( struct V_5 * V_6 ,
struct V_44 * V_45 , struct V_134 * V_135 )
{
T_9 V_29 ;
T_8 V_28 ;
T_10 V_30 ;
T_4 V_62 ;
T_10 V_78 ;
if ( ( F_12 ( V_6 , & V_29 , & V_28 ,
V_33 , V_45 -> V_27 ) ) ) {
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
V_62 = F_9 ( V_28 . V_179 ) ;
V_78 = F_74 ( V_28 . V_180 ) ;
F_49 ( V_7 , V_135 ,
L_16
L_17 ,
( V_78 & V_181 ) ? L_18 : L_19 ,
( V_62 & V_182 ) ? L_18 : L_19 ,
( V_62 & V_183 ) ? L_18 :
L_19 ,
( V_62 & V_184 ) ? L_18 : L_19 ,
( V_62 & V_185 ) ? L_18 : L_19 ,
( V_62 & V_186 ) ? L_18 : L_19 ) ;
}
static int
F_75 ( struct V_42 * V_166 )
{
struct V_134 * V_135 = F_76 ( V_166 ) ;
struct V_5 * V_6 = F_56 ( V_135 -> V_139 ) ;
if ( V_6 -> V_187 )
return 0 ;
return ( V_135 -> V_69 == V_171 ) ? 1 : 0 ;
}
static void
F_77 ( struct V_42 * V_166 )
{
struct V_134 * V_135 = F_76 ( V_166 ) ;
struct V_5 * V_6 = F_56 ( V_135 -> V_139 ) ;
static struct V_46 * V_47 ;
unsigned long V_62 ;
T_13 V_188 ;
T_9 V_29 ;
T_10 V_189 ;
T_6 V_190 = 0 ;
F_18 ( & V_6 -> V_72 , V_62 ) ;
V_47 = F_27 ( V_6 , V_135 -> V_68 ,
V_135 -> V_69 ) ;
F_21 ( & V_6 -> V_72 , V_62 ) ;
if ( ! V_47 || V_6 -> V_187 )
goto V_71;
if ( F_78 ( V_6 , & V_29 , & V_188 ,
V_191 , V_47 -> V_27 ,
sizeof( T_13 ) ) ) {
F_3 ( V_34 L_2 ,
V_6 -> V_35 , __FILE__ , __LINE__ , V_36 ) ;
goto V_71;
}
V_189 = F_74 ( V_188 . V_192 ) ;
if ( V_189 & V_193 )
V_190 = V_47 -> V_190 ;
V_71:
F_79 ( V_194 , V_166 , V_190 ) ;
}
static void
F_80 ( struct V_42 * V_166 )
{
struct V_134 * V_135 = F_76 ( V_166 ) ;
struct V_5 * V_6 = F_56 ( V_135 -> V_139 ) ;
static struct V_46 * V_47 ;
unsigned long V_62 ;
T_13 V_188 ;
T_9 V_29 ;
T_10 V_195 ;
enum V_196 V_197 = V_198 ;
F_18 ( & V_6 -> V_72 , V_62 ) ;
V_47 = F_27 ( V_6 , V_135 -> V_68 ,
V_135 -> V_69 ) ;
F_21 ( & V_6 -> V_72 , V_62 ) ;
if ( ! V_47 )
goto V_71;
if ( F_78 ( V_6 , & V_29 , & V_188 ,
V_191 , V_47 -> V_27 ,
sizeof( T_13 ) ) ) {
F_3 ( V_34 L_2 ,
V_6 -> V_35 , __FILE__ , __LINE__ , V_36 ) ;
goto V_71;
}
V_195 = F_74 ( V_188 . V_192 ) ;
if ( V_195 & V_193 ) {
V_197 = V_199 ;
goto V_71;
}
switch ( V_188 . V_200 ) {
case V_201 :
case V_202 :
V_197 = V_203 ;
break;
case V_204 :
V_197 = V_205 ;
break;
case V_206 :
case V_207 :
V_197 = V_208 ;
break;
}
V_71:
F_81 ( V_194 , V_166 , V_197 ) ;
}
static void
F_82 ( struct V_134 * V_135 , struct V_46 * V_47 )
{
enum V_209 V_210 = V_211 ;
switch ( V_47 -> V_212 ) {
case V_213 :
V_210 = V_214 ;
break;
case V_215 :
V_210 = V_216 ;
break;
case V_217 :
V_210 = V_218 ;
break;
case V_219 :
V_210 = V_220 ;
break;
}
F_83 ( V_194 , & V_135 -> V_221 , V_210 ) ;
}
static void
F_84 ( struct V_5 * V_6 ,
struct V_46 * V_47 )
{
T_13 * V_188 ;
T_14 V_222 ;
T_8 V_28 ;
T_9 V_29 ;
T_4 V_223 ;
T_6 V_224 ;
if ( ( F_85 ( V_6 , V_47 -> V_27 ,
& V_224 ) ) || ! V_224 ) {
F_3 ( V_34 L_2 ,
V_6 -> V_35 , __FILE__ , __LINE__ , V_36 ) ;
return;
}
V_47 -> V_224 = V_224 ;
V_223 = F_51 ( T_13 , V_225 ) + ( V_224 *
sizeof( V_226 ) ) ;
V_188 = F_67 ( V_223 , V_169 ) ;
if ( ! V_188 ) {
F_3 ( V_34 L_2 ,
V_6 -> V_35 , __FILE__ , __LINE__ , V_36 ) ;
return;
}
if ( ( F_78 ( V_6 , & V_29 , V_188 ,
V_191 , V_47 -> V_27 , V_223 ) ) ) {
F_3 ( V_34 L_2 ,
V_6 -> V_35 , __FILE__ , __LINE__ , V_36 ) ;
F_20 ( V_188 ) ;
return;
}
V_47 -> V_212 = V_188 -> V_227 ;
if ( ! ( F_86 ( V_6 , & V_29 ,
& V_222 , V_228 ,
V_188 -> V_225 [ 0 ] . V_229 ) ) ) {
if ( ! ( F_12 ( V_6 , & V_29 ,
& V_28 , V_33 ,
F_9 ( V_222 . V_230 ) ) ) ) {
V_47 -> V_78 =
F_74 ( V_28 . V_180 ) ;
}
}
F_20 ( V_188 ) ;
}
static void
F_87 ( struct V_5 * V_6 )
{
T_15 V_231 ;
T_9 V_29 ;
struct V_46 * V_47 ;
T_4 V_27 ;
T_4 V_30 ;
V_27 = 0xFFFF ;
while ( ! ( F_88 ( V_6 , & V_29 ,
& V_231 , V_232 , V_27 ) ) ) {
V_30 = F_9 ( V_29 . V_38 ) &
V_39 ;
if ( V_30 == V_233 )
break;
V_27 = F_9 ( V_231 . V_230 ) ;
V_47 = F_28 ( V_6 , V_27 ) ;
if ( V_47 )
V_47 -> V_234 = 0 ;
}
return;
}
static T_6
F_89 ( struct V_5 * V_6 )
{
T_15 V_231 ;
T_9 V_29 ;
T_4 V_27 ;
T_6 V_235 = 0 ;
T_4 V_30 ;
V_27 = 0xFFFF ;
while ( ! ( F_88 ( V_6 , & V_29 ,
& V_231 , V_232 , V_27 ) ) ) {
V_30 = F_9 ( V_29 . V_38 ) &
V_39 ;
if ( V_30 == V_233 )
break;
V_235 ++ ;
V_27 = F_9 ( V_231 . V_230 ) ;
}
return V_235 ;
}
static void
F_90 ( struct V_5 * V_6 ,
struct V_46 * V_47 )
{
T_13 * V_188 ;
T_14 V_222 ;
T_9 V_29 ;
T_4 V_223 ;
T_6 V_224 , V_236 ;
T_1 V_237 = 1024 * 1024 ;
T_1 V_238 = 2 * V_237 * V_237 ;
T_1 V_239 ;
T_10 V_240 ;
T_6 V_88 , V_241 ;
if ( ! V_6 -> V_187 )
return;
if ( V_6 -> V_242 == V_243 ) {
F_3 ( V_55 L_20
L_21 , V_6 -> V_35 ) ;
return;
}
if ( F_89 ( V_6 ) > 1 ) {
F_87 ( V_6 ) ;
F_3 ( V_55 L_20
L_22 , V_6 -> V_35 ) ;
return;
}
if ( ( F_85 ( V_6 , V_47 -> V_27 ,
& V_224 ) ) || ! V_224 ) {
F_3 ( V_55 L_20
L_23 , V_6 -> V_35 ) ;
return;
}
V_223 = F_51 ( T_13 , V_225 ) + ( V_224 *
sizeof( V_226 ) ) ;
V_188 = F_67 ( V_223 , V_169 ) ;
if ( ! V_188 ) {
F_3 ( V_55 L_20
L_24 , V_6 -> V_35 ) ;
return;
}
if ( ( F_78 ( V_6 , & V_29 , V_188 ,
V_191 , V_47 -> V_27 , V_223 ) ) ) {
F_3 ( V_55 L_20
L_25 , V_6 -> V_35 ) ;
F_20 ( V_188 ) ;
return;
}
if ( V_224 > V_244 ) {
F_3 ( V_95 L_20
L_26
L_27 , V_6 -> V_35 , V_47 -> V_27 ,
V_224 , V_244 ) ;
F_20 ( V_188 ) ;
return;
}
for ( V_236 = 0 ; V_236 < V_224 ; V_236 ++ ) {
if ( F_86 ( V_6 , & V_29 ,
& V_222 , V_228 ,
V_188 -> V_225 [ V_236 ] . V_229 ) ||
V_222 . V_230 == V_170 ) {
F_3 ( V_55 L_28
L_29
L_30 ,
V_6 -> V_35 , V_47 -> V_27 ,
V_188 -> V_225 [ V_236 ] . V_229 ) ;
goto V_245;
}
V_47 -> V_246 [ V_236 ] = F_9 ( V_222 . V_230 ) ;
}
if ( V_47 -> V_212 != V_213 ||
F_9 ( V_188 -> V_247 ) != 512 ) {
F_3 ( V_55 L_20
L_31
L_32 , V_6 -> V_35 ,
V_47 -> V_27 , V_47 -> V_212 ,
F_74 ( V_188 -> V_248 ) / 2 ,
F_9 ( V_188 -> V_247 ) ) ;
goto V_245;
}
V_239 = ( T_1 ) F_9 ( V_188 -> V_247 ) *
( F_6 ( V_188 -> V_249 ) + 1 ) ;
if ( V_239 > V_238 ) {
F_3 ( V_55 L_20
L_33 ,
V_6 -> V_35 , V_47 -> V_27 ) ;
goto V_245;
}
V_240 = F_74 ( V_188 -> V_248 ) ;
V_241 = 0 ;
for ( V_88 = 0 ; V_88 < 32 ; V_88 ++ ) {
if ( V_240 & 1 )
break;
V_241 ++ ;
V_240 >>= 1 ;
}
if ( V_88 == 32 ) {
F_3 ( V_55 L_20
L_34 ,
V_6 -> V_35 , V_47 -> V_27 ,
F_74 ( V_188 -> V_248 ) / 2 ) ;
goto V_245;
}
V_47 -> V_250 = V_241 ;
V_47 -> V_234 = 1 ;
F_3 ( V_55 L_35
L_36 , V_6 -> V_35 , V_47 -> V_27 ) ;
V_47 -> V_251 = F_6 ( V_188 -> V_249 ) ;
V_47 -> V_240 = F_74 ( V_188 -> V_248 ) ;
V_47 -> V_252 = F_9 ( V_188 -> V_247 ) ;
F_20 ( V_188 ) ;
return;
V_245:
V_47 -> V_234 = 0 ;
for ( V_236 = 0 ; V_236 < V_224 ; V_236 ++ )
V_47 -> V_246 [ V_236 ] = 0 ;
F_20 ( V_188 ) ;
return;
}
static void
F_91 ( struct V_5 * V_6 , struct V_134 * V_135 )
{
if ( V_135 -> type != V_253 )
return;
if ( ! ( V_6 -> V_254 . V_255 & V_256 ) )
return;
F_92 ( V_135 ) ;
F_49 ( V_7 , V_135 , L_37 ,
F_93 ( V_135 ) ? L_38 : L_39 ) ;
return;
}
static int
F_94 ( struct V_134 * V_135 )
{
struct V_137 * V_138 = V_135 -> V_139 ;
struct V_5 * V_6 = F_56 ( V_138 ) ;
struct V_141 * V_142 ;
struct V_143 * V_144 ;
struct V_44 * V_45 ;
struct V_46 * V_47 ;
unsigned long V_62 ;
int V_136 ;
T_6 V_257 = 0 ;
char * V_258 = L_40 ;
char * V_259 = L_40 ;
V_136 = 1 ;
V_142 = V_135 -> V_146 ;
V_142 -> V_260 = 1 ;
V_142 -> V_62 &= ~ V_176 ;
V_144 = V_142 -> V_148 ;
if ( V_144 -> V_62 & V_149 ) {
F_18 ( & V_6 -> V_72 , V_62 ) ;
V_47 = F_28 ( V_6 ,
V_144 -> V_27 ) ;
F_21 ( & V_6 -> V_72 , V_62 ) ;
if ( ! V_47 ) {
F_3 ( V_34 L_2 ,
V_6 -> V_35 , __FILE__ , __LINE__ , V_36 ) ;
return 0 ;
}
F_84 ( V_6 , V_47 ) ;
F_90 ( V_6 , V_47 ) ;
if ( V_47 -> V_78 &
V_80 ) {
V_136 = V_261 ;
V_258 = L_41 ;
} else {
V_136 = V_150 ;
if ( V_47 -> V_78 &
V_82 )
V_258 = L_42 ;
else
V_258 = L_43 ;
}
switch ( V_47 -> V_212 ) {
case V_213 :
V_259 = L_44 ;
break;
case V_217 :
V_136 = V_262 ;
if ( V_6 -> V_263 . V_264 &&
( V_6 -> V_263 . V_265 &
V_266 ) &&
! ( V_47 -> V_224 % 2 ) )
V_259 = L_45 ;
else
V_259 = L_46 ;
break;
case V_219 :
V_136 = V_262 ;
V_259 = L_47 ;
break;
case V_215 :
V_136 = V_262 ;
V_259 = L_45 ;
break;
case V_267 :
default:
V_136 = V_262 ;
V_259 = L_48 ;
break;
}
if ( ! V_6 -> V_268 )
F_49 ( V_7 , V_135 , L_49
L_50 ,
V_259 , V_47 -> V_27 ,
( unsigned long long ) V_47 -> V_49 ,
V_47 -> V_224 , V_258 ) ;
F_59 ( V_135 , V_136 , V_153 ) ;
if ( ! V_6 -> V_187 )
F_82 ( V_135 , V_47 ) ;
return 0 ;
}
F_18 ( & V_6 -> V_63 , V_62 ) ;
V_45 = F_15 ( V_6 ,
V_142 -> V_148 -> V_9 ) ;
F_21 ( & V_6 -> V_63 , V_62 ) ;
if ( V_45 ) {
if ( V_144 -> V_62 &
V_175 ) {
F_95 ( V_6 ,
V_45 -> V_27 , & V_45 -> V_269 ) ;
F_96 ( V_6 ,
V_45 -> V_269 ,
& V_45 -> V_270 ) ;
}
if ( V_45 -> V_78 & V_80 ) {
V_136 = V_261 ;
V_257 = 1 ;
V_258 = L_41 ;
} else {
V_136 = V_150 ;
if ( V_45 -> V_78 &
V_81 )
V_258 = L_43 ;
else if ( V_45 -> V_78 &
V_82 )
V_258 = L_42 ;
}
F_49 ( V_7 , V_135 , L_49
L_51 ,
V_258 , V_45 -> V_27 ,
( unsigned long long ) V_45 -> V_9 ,
V_45 -> V_271 ,
( unsigned long long ) V_45 -> V_12 ) ;
F_49 ( V_7 , V_135 , L_52
L_53 , V_258 ,
( unsigned long long ) V_45 -> V_14 ,
V_45 -> V_18 ) ;
if ( ! V_257 )
F_73 ( V_6 , V_45 , V_135 ) ;
}
F_59 ( V_135 , V_136 , V_153 ) ;
if ( V_257 ) {
F_97 ( V_135 ) ;
F_91 ( V_6 , V_135 ) ;
}
return 0 ;
}
static int
F_98 ( struct V_134 * V_135 , struct V_272 * V_273 ,
T_16 V_239 , int V_274 [] )
{
int V_275 ;
int V_276 ;
T_16 V_277 ;
T_17 V_278 ;
V_275 = 64 ;
V_276 = 32 ;
V_278 = V_275 * V_276 ;
V_277 = V_239 ;
F_99 ( V_277 , V_278 ) ;
if ( ( T_17 ) V_239 >= 0x200000 ) {
V_275 = 255 ;
V_276 = 63 ;
V_278 = V_275 * V_276 ;
V_277 = V_239 ;
F_99 ( V_277 , V_278 ) ;
}
V_274 [ 0 ] = V_275 ;
V_274 [ 1 ] = V_276 ;
V_274 [ 2 ] = V_277 ;
return 0 ;
}
static void
F_100 ( struct V_5 * V_6 , T_6 V_279 )
{
char * V_280 ;
switch ( V_279 ) {
case V_281 :
V_280 = L_54 ;
break;
case V_282 :
V_280 = L_55 ;
break;
case V_283 :
V_280 = L_56 ;
break;
case V_284 :
V_280 = L_57 ;
break;
case V_285 :
V_280 = L_58 ;
break;
case V_286 :
V_280 = L_59 ;
break;
case 0xA :
V_280 = L_60 ;
break;
case V_287 :
V_280 = L_61 ;
break;
default:
V_280 = L_62 ;
break;
}
F_3 ( V_95 L_63 ,
V_6 -> V_35 , V_279 , V_280 ) ;
}
static T_6
F_101 ( struct V_5 * V_6 , T_4 V_84 , T_6 V_288 , T_10 V_289 )
{
T_18 * V_29 ;
if ( V_6 -> V_290 . V_291 == V_292 )
return 1 ;
if ( V_6 -> V_290 . V_84 != V_84 )
return 1 ;
V_6 -> V_290 . V_291 |= V_293 ;
V_29 = F_102 ( V_6 , V_289 ) ;
if ( V_29 ) {
memcpy ( V_6 -> V_290 . V_289 , V_29 , V_29 -> V_294 * 4 ) ;
V_6 -> V_290 . V_291 |= V_295 ;
}
V_6 -> V_290 . V_291 &= ~ V_296 ;
F_103 ( & V_6 -> V_290 . V_297 ) ;
return 1 ;
}
void
F_104 ( struct V_5 * V_6 , T_4 V_27 )
{
struct V_141 * V_142 ;
struct V_134 * V_135 ;
T_6 V_298 = 0 ;
F_105 (sdev, ioc->shost) {
if ( V_298 )
continue;
V_142 = V_135 -> V_146 ;
if ( ! V_142 )
continue;
if ( V_142 -> V_148 -> V_27 == V_27 ) {
V_142 -> V_148 -> V_299 = 1 ;
V_298 = 1 ;
V_6 -> V_300 = 1 ;
}
}
}
void
F_106 ( struct V_5 * V_6 , T_4 V_27 )
{
struct V_141 * V_142 ;
struct V_134 * V_135 ;
T_6 V_298 = 0 ;
F_105 (sdev, ioc->shost) {
if ( V_298 )
continue;
V_142 = V_135 -> V_146 ;
if ( ! V_142 )
continue;
if ( V_142 -> V_148 -> V_27 == V_27 ) {
V_142 -> V_148 -> V_299 = 0 ;
V_298 = 1 ;
V_6 -> V_300 = 0 ;
}
}
}
int
F_107 ( struct V_5 * V_6 , T_4 V_27 , T_19 V_69 ,
T_19 V_68 , T_19 V_91 , T_6 type , T_4 V_301 , T_17 V_302 ,
struct V_83 * V_86 )
{
T_20 * V_99 ;
T_21 * V_29 ;
T_4 V_84 = 0 ;
T_10 V_303 ;
unsigned long V_304 ;
struct V_83 * V_305 ;
int V_20 ;
F_108 ( & V_6 -> V_290 . V_306 ) ;
if ( V_6 -> V_290 . V_291 != V_292 ) {
F_3 ( V_55 L_64 ,
V_36 , V_6 -> V_35 ) ;
V_20 = V_307 ;
goto V_308;
}
if ( V_6 -> V_309 || V_6 -> V_310 ||
V_6 -> V_311 ) {
F_3 ( V_55 L_65 ,
V_36 , V_6 -> V_35 ) ;
V_20 = V_307 ;
goto V_308;
}
V_303 = F_109 ( V_6 , 0 ) ;
if ( V_303 & V_312 ) {
F_110 ( V_6 , F_3 ( V_55 L_66
L_67 , V_6 -> V_35 ) ) ;
F_111 ( V_6 , V_313 ,
V_314 ) ;
V_20 = V_315 ;
goto V_308;
}
if ( ( V_303 & V_316 ) == V_317 ) {
F_112 ( V_6 , V_303 &
V_318 ) ;
F_111 ( V_6 , V_313 ,
V_314 ) ;
V_20 = V_315 ;
goto V_308;
}
V_84 = F_113 ( V_6 , V_6 -> V_319 ) ;
if ( ! V_84 ) {
F_3 ( V_34 L_68 ,
V_6 -> V_35 , V_36 ) ;
V_20 = V_307 ;
goto V_308;
}
F_114 ( V_6 , F_3 ( V_55 L_69
L_70 , V_6 -> V_35 , V_27 , type ,
V_301 ) ) ;
V_6 -> V_290 . V_291 = V_296 ;
V_99 = F_46 ( V_6 , V_84 ) ;
V_6 -> V_290 . V_84 = V_84 ;
memset ( V_99 , 0 , sizeof( T_20 ) ) ;
V_99 -> V_320 = V_321 ;
V_99 -> V_230 = F_115 ( V_27 ) ;
V_99 -> V_322 = type ;
V_99 -> V_323 = F_115 ( V_301 ) ;
F_116 ( V_91 , (struct V_324 * ) V_99 -> V_325 ) ;
F_104 ( V_6 , V_27 ) ;
F_117 ( & V_6 -> V_290 . V_297 ) ;
F_118 ( V_6 , V_84 ) ;
V_304 = F_119 ( & V_6 -> V_290 . V_297 , V_302 * V_326 ) ;
if ( ! ( V_6 -> V_290 . V_291 & V_293 ) ) {
F_3 ( V_34 L_71 ,
V_6 -> V_35 , V_36 ) ;
F_120 ( V_99 ,
sizeof( T_20 ) / 4 ) ;
if ( ! ( V_6 -> V_290 . V_291 & V_327 ) ) {
F_111 ( V_6 , V_313 ,
V_314 ) ;
V_20 = V_315 ;
V_6 -> V_290 . V_291 = V_292 ;
F_106 ( V_6 , V_27 ) ;
goto V_308;
}
}
if ( V_6 -> V_290 . V_291 & V_295 ) {
V_29 = V_6 -> V_290 . V_289 ;
F_114 ( V_6 , F_3 ( V_55 L_72
L_73 ,
V_6 -> V_35 , F_9 ( V_29 -> V_38 ) ,
F_74 ( V_29 -> V_328 ) ,
F_74 ( V_29 -> V_329 ) ) ) ;
if ( V_6 -> V_8 & V_330 ) {
F_100 ( V_6 , V_29 -> V_331 ) ;
if ( V_29 -> V_38 )
F_120 ( V_99 ,
sizeof( T_20 ) / 4 ) ;
}
}
V_20 = V_307 ;
if ( V_86 == NULL )
goto V_332;
switch ( type ) {
case V_333 :
V_305 = F_36 ( V_6 , V_301 ) ;
if ( V_305 )
V_20 = V_307 ;
else
V_20 = V_315 ;
break;
case V_334 :
if ( F_39 ( V_6 , V_68 , V_69 ) )
V_20 = V_307 ;
else
V_20 = V_315 ;
break;
case V_335 :
if ( F_40 ( V_6 , V_68 , V_91 , V_69 ) )
V_20 = V_307 ;
else
V_20 = V_315 ;
break;
}
V_332:
F_106 ( V_6 , V_27 ) ;
V_6 -> V_290 . V_291 = V_292 ;
F_121 ( & V_6 -> V_290 . V_306 ) ;
return V_20 ;
V_308:
F_121 ( & V_6 -> V_290 . V_306 ) ;
return V_20 ;
}
static void
F_122 ( struct V_5 * V_6 , struct V_83 * V_86 )
{
struct V_164 * V_165 = V_86 -> V_42 -> V_336 ;
struct V_143 * V_337 = V_165 -> V_146 ;
struct V_44 * V_45 = NULL ;
unsigned long V_62 ;
char * V_338 = NULL ;
if ( ! V_337 )
return;
if ( V_6 -> V_268 )
V_338 = L_74 ;
else
V_338 = L_75 ;
F_123 ( V_86 ) ;
if ( V_337 -> V_62 & V_149 ) {
F_124 ( V_7 , V_165 , L_76
L_77 , V_338 , V_337 -> V_27 ,
V_338 , ( unsigned long long ) V_337 -> V_9 ) ;
} else {
F_18 ( & V_6 -> V_63 , V_62 ) ;
V_45 = F_15 ( V_6 ,
V_337 -> V_9 ) ;
if ( V_45 ) {
if ( V_337 -> V_62 &
V_175 ) {
F_124 ( V_7 , V_165 ,
L_78
L_79 ,
V_45 -> V_269 ,
( unsigned long long ) V_45 -> V_270 ) ;
}
F_124 ( V_7 , V_165 ,
L_80 ,
V_45 -> V_27 ,
( unsigned long long ) V_45 -> V_9 ,
V_45 -> V_271 ) ;
F_124 ( V_7 , V_165 ,
L_53 ,
( unsigned long long ) V_45 -> V_14 ,
V_45 -> V_18 ) ;
}
F_21 ( & V_6 -> V_63 , V_62 ) ;
}
}
static int
F_125 ( struct V_83 * V_86 )
{
struct V_5 * V_6 = F_56 ( V_86 -> V_42 -> V_139 ) ;
struct V_141 * V_142 ;
T_4 V_84 ;
T_4 V_27 ;
int V_70 ;
F_49 ( V_7 , V_86 -> V_42 , L_81
L_82 , V_86 ) ;
F_122 ( V_6 , V_86 ) ;
V_142 = V_86 -> V_42 -> V_146 ;
if ( ! V_142 || ! V_142 -> V_148 ) {
F_49 ( V_7 , V_86 -> V_42 , L_83
L_82 , V_86 ) ;
V_86 -> V_339 = V_340 << 16 ;
V_86 -> V_341 ( V_86 ) ;
V_70 = V_315 ;
goto V_71;
}
V_84 = F_38 ( V_6 , V_86 ) ;
if ( ! V_84 ) {
V_86 -> V_339 = V_342 << 16 ;
V_70 = V_315 ;
goto V_71;
}
if ( V_142 -> V_148 -> V_62 &
V_175 ||
V_142 -> V_148 -> V_62 & V_149 ) {
V_86 -> V_339 = V_342 << 16 ;
V_70 = V_307 ;
goto V_71;
}
F_126 ( V_6 ) ;
V_27 = V_142 -> V_148 -> V_27 ;
V_70 = F_107 ( V_6 , V_27 , V_86 -> V_42 -> V_69 ,
V_86 -> V_42 -> V_68 , V_86 -> V_42 -> V_91 ,
V_333 , V_84 , 30 , V_86 ) ;
V_71:
F_49 ( V_7 , V_86 -> V_42 , L_84 ,
( ( V_70 == V_315 ) ? L_85 : L_86 ) , V_86 ) ;
return V_70 ;
}
static int
F_127 ( struct V_83 * V_86 )
{
struct V_5 * V_6 = F_56 ( V_86 -> V_42 -> V_139 ) ;
struct V_141 * V_142 ;
struct V_44 * V_45 ;
unsigned long V_62 ;
T_4 V_27 ;
int V_70 ;
struct V_164 * V_165 = V_86 -> V_42 -> V_336 ;
F_124 ( V_7 , V_165 , L_87
L_82 , V_86 ) ;
F_122 ( V_6 , V_86 ) ;
V_142 = V_86 -> V_42 -> V_146 ;
if ( ! V_142 || ! V_142 -> V_148 ) {
F_124 ( V_7 , V_165 , L_83
L_82 , V_86 ) ;
V_86 -> V_339 = V_340 << 16 ;
V_86 -> V_341 ( V_86 ) ;
V_70 = V_315 ;
goto V_71;
}
V_27 = 0 ;
if ( V_142 -> V_148 -> V_62 &
V_175 ) {
F_18 ( & V_6 -> V_63 , V_62 ) ;
V_45 = F_16 ( V_6 ,
V_142 -> V_148 -> V_27 ) ;
if ( V_45 )
V_27 = V_45 -> V_269 ;
F_21 ( & V_6 -> V_63 , V_62 ) ;
} else
V_27 = V_142 -> V_148 -> V_27 ;
if ( ! V_27 ) {
V_86 -> V_339 = V_342 << 16 ;
V_70 = V_307 ;
goto V_71;
}
V_70 = F_107 ( V_6 , V_27 , V_86 -> V_42 -> V_69 ,
V_86 -> V_42 -> V_68 , V_86 -> V_42 -> V_91 ,
V_335 , 0 , 30 , V_86 ) ;
V_71:
F_49 ( V_7 , V_86 -> V_42 , L_88 ,
( ( V_70 == V_315 ) ? L_85 : L_86 ) , V_86 ) ;
return V_70 ;
}
static int
F_128 ( struct V_83 * V_86 )
{
struct V_5 * V_6 = F_56 ( V_86 -> V_42 -> V_139 ) ;
struct V_141 * V_142 ;
struct V_44 * V_45 ;
unsigned long V_62 ;
T_4 V_27 ;
int V_70 ;
struct V_164 * V_165 = V_86 -> V_42 -> V_336 ;
F_124 ( V_7 , V_165 , L_89
L_82 , V_86 ) ;
F_122 ( V_6 , V_86 ) ;
V_142 = V_86 -> V_42 -> V_146 ;
if ( ! V_142 || ! V_142 -> V_148 ) {
F_124 ( V_7 , V_165 , L_90
L_82 , V_86 ) ;
V_86 -> V_339 = V_340 << 16 ;
V_86 -> V_341 ( V_86 ) ;
V_70 = V_315 ;
goto V_71;
}
V_27 = 0 ;
if ( V_142 -> V_148 -> V_62 &
V_175 ) {
F_18 ( & V_6 -> V_63 , V_62 ) ;
V_45 = F_16 ( V_6 ,
V_142 -> V_148 -> V_27 ) ;
if ( V_45 )
V_27 = V_45 -> V_269 ;
F_21 ( & V_6 -> V_63 , V_62 ) ;
} else
V_27 = V_142 -> V_148 -> V_27 ;
if ( ! V_27 ) {
V_86 -> V_339 = V_342 << 16 ;
V_70 = V_307 ;
goto V_71;
}
V_70 = F_107 ( V_6 , V_27 , V_86 -> V_42 -> V_69 ,
V_86 -> V_42 -> V_68 , 0 , V_334 , 0 ,
30 , V_86 ) ;
V_71:
F_124 ( V_7 , V_165 , L_91 ,
( ( V_70 == V_315 ) ? L_85 : L_86 ) , V_86 ) ;
return V_70 ;
}
static int
F_129 ( struct V_83 * V_86 )
{
struct V_5 * V_6 = F_56 ( V_86 -> V_42 -> V_139 ) ;
int V_70 , V_343 ;
F_3 ( V_55 L_92 ,
V_6 -> V_35 , V_86 ) ;
F_123 ( V_86 ) ;
V_343 = F_111 ( V_6 , V_313 ,
V_314 ) ;
V_70 = ( V_343 < 0 ) ? V_307 : V_315 ;
F_3 ( V_55 L_93 ,
V_6 -> V_35 , ( ( V_70 == V_315 ) ? L_85 : L_86 ) , V_86 ) ;
return V_70 ;
}
static void
F_130 ( struct V_5 * V_6 , struct V_344 * V_345 )
{
unsigned long V_62 ;
if ( V_6 -> V_346 == NULL )
return;
F_18 ( & V_6 -> V_347 , V_62 ) ;
F_24 ( & V_345 -> V_64 , & V_6 -> V_348 ) ;
F_131 ( & V_345 -> V_349 , V_350 ) ;
F_132 ( V_6 -> V_346 ,
& V_345 -> V_349 , 0 ) ;
F_21 ( & V_6 -> V_347 , V_62 ) ;
}
static void
F_133 ( struct V_5 * V_6 , struct V_344
* V_345 )
{
unsigned long V_62 ;
F_18 ( & V_6 -> V_347 , V_62 ) ;
F_19 ( & V_345 -> V_64 ) ;
F_20 ( V_345 -> V_351 ) ;
F_20 ( V_345 ) ;
F_21 ( & V_6 -> V_347 , V_62 ) ;
}
static void
F_134 ( struct V_5 * V_6 )
{
struct V_344 * V_345 ;
if ( V_6 -> V_48 )
return;
V_345 = F_67 ( sizeof( struct V_344 ) , V_352 ) ;
if ( ! V_345 )
return;
V_345 -> V_353 = V_354 ;
V_345 -> V_6 = V_6 ;
F_130 ( V_6 , V_345 ) ;
}
static void
F_135 ( struct V_5 * V_6 )
{
struct V_344 * V_345 , * V_96 ;
if ( F_42 ( & V_6 -> V_348 ) ||
! V_6 -> V_346 || F_136 () )
return;
F_137 (fw_event, next, &ioc->fw_event_list, list) {
if ( F_138 ( & V_345 -> V_349 ) ) {
F_133 ( V_6 , V_345 ) ;
continue;
}
V_345 -> V_355 = 1 ;
}
}
static void
F_139 ( struct V_5 * V_6 , T_4 V_27 )
{
struct V_141 * V_142 ;
struct V_134 * V_135 ;
F_105 (sdev, ioc->shost) {
V_142 = V_135 -> V_146 ;
if ( ! V_142 )
continue;
if ( ! V_142 -> V_356 )
continue;
if ( V_142 -> V_148 -> V_27 == V_27 ) {
F_23 ( V_6 , F_49 ( V_7 , V_135 ,
V_55 L_94
L_95 , V_6 -> V_35 , V_27 ) ) ;
V_142 -> V_356 = 0 ;
F_140 ( V_135 ) ;
}
}
}
static void
F_141 ( struct V_5 * V_6 , T_4 V_27 )
{
struct V_141 * V_142 ;
struct V_134 * V_135 ;
F_105 (sdev, ioc->shost) {
V_142 = V_135 -> V_146 ;
if ( ! V_142 )
continue;
if ( V_142 -> V_356 )
continue;
if ( V_142 -> V_148 -> V_27 == V_27 ) {
F_23 ( V_6 , F_49 ( V_7 , V_135 ,
V_55 L_96
L_95 , V_6 -> V_35 , V_27 ) ) ;
V_142 -> V_356 = 1 ;
F_142 ( V_135 ) ;
}
}
}
static void
F_143 ( struct V_5 * V_6 ,
struct V_74 * V_75 )
{
struct V_357 * V_358 ;
struct V_44 * V_45 ;
struct V_74 * V_359 ;
unsigned long V_62 ;
if ( ! V_75 )
return;
F_4 (mpt2sas_port,
&sas_expander->sas_port_list, port_list) {
if ( V_358 -> V_360 . V_361 ==
V_362 ) {
F_18 ( & V_6 -> V_63 , V_62 ) ;
V_45 =
F_15 ( V_6 ,
V_358 -> V_360 . V_9 ) ;
F_21 ( & V_6 -> V_63 , V_62 ) ;
if ( ! V_45 )
continue;
F_141 ( V_6 , V_45 -> V_27 ) ;
}
}
F_4 (mpt2sas_port,
&sas_expander->sas_port_list, port_list) {
if ( V_358 -> V_360 . V_361 ==
V_363 ||
V_358 -> V_360 . V_361 ==
V_364 ) {
F_18 ( & V_6 -> V_76 , V_62 ) ;
V_359 =
F_33 (
V_6 , V_358 -> V_360 . V_9 ) ;
F_21 ( & V_6 -> V_76 , V_62 ) ;
F_143 ( V_6 ,
V_359 ) ;
}
}
}
static void
F_144 ( struct V_5 * V_6 ,
T_22 * V_351 )
{
int V_88 ;
T_4 V_27 ;
T_4 V_365 ;
T_6 V_366 ;
for ( V_88 = 0 ; V_88 < V_351 -> V_367 ; V_88 ++ ) {
V_27 = F_9 ( V_351 -> V_368 [ V_88 ] . V_369 ) ;
if ( ! V_27 )
continue;
V_366 = V_351 -> V_370 + V_88 ;
V_365 = V_351 -> V_368 [ V_88 ] . V_371 &
V_372 ;
if ( V_365 == V_373 )
F_141 ( V_6 , V_27 ) ;
}
}
static void
F_145 ( struct V_5 * V_6 , T_4 V_27 )
{
T_20 * V_99 ;
T_4 V_84 ;
struct V_44 * V_45 ;
struct V_143 * V_144 ;
unsigned long V_62 ;
struct V_374 * V_375 ;
if ( V_6 -> V_309 || V_6 -> V_310 ||
V_6 -> V_311 ) {
F_23 ( V_6 , F_3 ( V_55 L_97
L_98 , V_36 , V_6 -> V_35 ) ) ;
return;
}
if ( F_69 ( V_27 , V_6 -> V_174 ) )
return;
F_18 ( & V_6 -> V_63 , V_62 ) ;
V_45 = F_16 ( V_6 , V_27 ) ;
if ( V_45 && V_45 -> V_165 &&
V_45 -> V_165 -> V_146 ) {
V_144 = V_45 -> V_165 -> V_146 ;
V_144 -> V_376 = 1 ;
F_23 ( V_6 , F_3 ( V_55
L_99
L_100 , V_6 -> V_35 , V_27 ,
( unsigned long long ) V_45 -> V_9 ) ) ;
}
F_21 ( & V_6 -> V_63 , V_62 ) ;
V_84 = F_113 ( V_6 , V_6 -> V_377 ) ;
if ( ! V_84 ) {
V_375 = F_67 ( sizeof( * V_375 ) , V_352 ) ;
if ( ! V_375 )
return;
F_146 ( & V_375 -> V_64 ) ;
V_375 -> V_27 = V_27 ;
F_24 ( & V_375 -> V_64 , & V_6 -> V_378 ) ;
F_23 ( V_6 , F_3 ( V_55
L_101 ,
V_6 -> V_35 , V_27 ) ) ;
return;
}
F_23 ( V_6 , F_3 ( V_55 L_102
L_103 , V_6 -> V_35 , V_27 , V_84 ,
V_6 -> V_377 ) ) ;
V_99 = F_46 ( V_6 , V_84 ) ;
memset ( V_99 , 0 , sizeof( T_20 ) ) ;
V_99 -> V_320 = V_321 ;
V_99 -> V_230 = F_115 ( V_27 ) ;
V_99 -> V_322 = V_334 ;
F_118 ( V_6 , V_84 ) ;
}
static T_6
F_147 ( struct V_5 * V_6 , T_4 V_84 ,
T_6 V_288 , T_10 V_289 )
{
#ifdef F_148
T_23 * V_29 =
F_102 ( V_6 , V_289 ) ;
#endif
F_23 ( V_6 , F_3 ( V_55
L_104
L_105 ,
V_6 -> V_35 , F_9 ( V_29 -> V_230 ) , V_84 ,
F_9 ( V_29 -> V_38 ) ,
F_74 ( V_29 -> V_328 ) ) ) ;
return 1 ;
}
static void
F_149 ( struct V_5 * V_6 , T_4 V_27 )
{
T_20 * V_99 ;
T_4 V_84 ;
struct V_374 * V_375 ;
if ( V_6 -> V_309 || V_6 -> V_310 ||
V_6 -> V_311 ) {
F_23 ( V_6 , F_3 ( V_55 L_97
L_98 , V_36 , V_6 -> V_35 ) ) ;
return;
}
V_84 = F_113 ( V_6 , V_6 -> V_379 ) ;
if ( ! V_84 ) {
V_375 = F_67 ( sizeof( * V_375 ) , V_352 ) ;
if ( ! V_375 )
return;
F_146 ( & V_375 -> V_64 ) ;
V_375 -> V_27 = V_27 ;
F_24 ( & V_375 -> V_64 , & V_6 -> V_380 ) ;
F_23 ( V_6 , F_3 ( V_55
L_101 ,
V_6 -> V_35 , V_27 ) ) ;
return;
}
F_23 ( V_6 , F_3 ( V_55 L_102
L_103 , V_6 -> V_35 , V_27 , V_84 ,
V_6 -> V_379 ) ) ;
V_99 = F_46 ( V_6 , V_84 ) ;
memset ( V_99 , 0 , sizeof( T_20 ) ) ;
V_99 -> V_320 = V_321 ;
V_99 -> V_230 = F_115 ( V_27 ) ;
V_99 -> V_322 = V_334 ;
F_118 ( V_6 , V_84 ) ;
}
static T_6
F_150 ( struct V_5 * V_6 , T_4 V_84 ,
T_6 V_288 , T_10 V_289 )
{
T_4 V_27 ;
T_20 * V_381 ;
T_21 * V_29 =
F_102 ( V_6 , V_289 ) ;
if ( V_6 -> V_309 || V_6 -> V_310 ||
V_6 -> V_311 ) {
F_23 ( V_6 , F_3 ( V_55 L_97
L_98 , V_36 , V_6 -> V_35 ) ) ;
return 1 ;
}
V_381 = F_46 ( V_6 , V_84 ) ;
V_27 = F_9 ( V_381 -> V_230 ) ;
if ( V_27 != F_9 ( V_29 -> V_230 ) ) {
F_23 ( V_6 , F_3 ( L_106
L_107 , V_27 ,
F_9 ( V_29 -> V_230 ) , V_84 ) ) ;
return 0 ;
}
F_23 ( V_6 , F_3 ( V_55
L_108
L_109 , V_6 -> V_35 ,
V_27 , V_84 , F_9 ( V_29 -> V_38 ) ,
F_74 ( V_29 -> V_328 ) ,
F_74 ( V_29 -> V_329 ) ) ) ;
return F_151 ( V_6 , V_84 ) ;
}
static T_6
F_152 ( struct V_5 * V_6 , T_4 V_84 , T_6 V_288 ,
T_10 V_289 )
{
T_4 V_27 ;
T_20 * V_381 ;
T_21 * V_29 =
F_102 ( V_6 , V_289 ) ;
T_24 * V_99 ;
T_4 V_382 ;
if ( V_6 -> V_309 || V_6 -> V_310 ||
V_6 -> V_311 ) {
F_23 ( V_6 , F_3 ( V_55 L_97
L_98 , V_36 , V_6 -> V_35 ) ) ;
return 1 ;
}
V_381 = F_46 ( V_6 , V_84 ) ;
V_27 = F_9 ( V_381 -> V_230 ) ;
if ( V_27 != F_9 ( V_29 -> V_230 ) ) {
F_23 ( V_6 , F_3 ( V_55 L_106
L_107 , V_6 -> V_35 , V_27 ,
F_9 ( V_29 -> V_230 ) , V_84 ) ) ;
return 0 ;
}
F_23 ( V_6 , F_3 ( V_55
L_108
L_109 , V_6 -> V_35 ,
V_27 , V_84 , F_9 ( V_29 -> V_38 ) ,
F_74 ( V_29 -> V_328 ) ,
F_74 ( V_29 -> V_329 ) ) ) ;
V_382 = F_153 ( V_6 , V_6 -> V_383 ) ;
if ( ! V_382 ) {
F_3 ( V_34 L_68 ,
V_6 -> V_35 , V_36 ) ;
return 1 ;
}
F_23 ( V_6 , F_3 ( V_55 L_110
L_103 , V_6 -> V_35 , V_27 , V_382 ,
V_6 -> V_383 ) ) ;
V_99 = F_46 ( V_6 , V_382 ) ;
memset ( V_99 , 0 , sizeof( T_24 ) ) ;
V_99 -> V_320 = V_384 ;
V_99 -> V_385 = V_386 ;
V_99 -> V_230 = V_381 -> V_230 ;
F_154 ( V_6 , V_382 ) ;
return F_151 ( V_6 , V_84 ) ;
}
static T_6
F_151 ( struct V_5 * V_6 , T_4 V_84 )
{
struct V_374 * V_375 ;
if ( ! F_42 ( & V_6 -> V_380 ) ) {
V_375 = F_43 ( V_6 -> V_380 . V_96 ,
struct V_374 , V_64 ) ;
F_155 ( V_6 , V_84 ) ;
F_149 ( V_6 , V_375 -> V_27 ) ;
F_19 ( & V_375 -> V_64 ) ;
F_20 ( V_375 ) ;
return 0 ;
}
if ( ! F_42 ( & V_6 -> V_378 ) ) {
V_375 = F_43 ( V_6 -> V_378 . V_96 ,
struct V_374 , V_64 ) ;
F_155 ( V_6 , V_84 ) ;
F_145 ( V_6 , V_375 -> V_27 ) ;
F_19 ( & V_375 -> V_64 ) ;
F_20 ( V_375 ) ;
return 0 ;
}
return 1 ;
}
static void
F_156 ( struct V_5 * V_6 ,
T_22 * V_351 )
{
struct V_344 * V_345 ;
T_22 * V_387 ;
T_4 V_388 ;
struct V_74 * V_75 ;
unsigned long V_62 ;
int V_88 , V_365 ;
T_4 V_27 ;
for ( V_88 = 0 ; V_88 < V_351 -> V_367 ; V_88 ++ ) {
V_27 = F_9 ( V_351 -> V_368 [ V_88 ] . V_369 ) ;
if ( ! V_27 )
continue;
V_365 = V_351 -> V_368 [ V_88 ] . V_371 &
V_372 ;
if ( V_365 == V_389 )
F_145 ( V_6 , V_27 ) ;
}
V_388 = F_9 ( V_351 -> V_390 ) ;
if ( V_388 < V_6 -> V_31 . V_32 ) {
F_144 ( V_6 , V_351 ) ;
return;
}
if ( V_351 -> V_391 == V_392
|| V_351 -> V_391 == V_393 ) {
F_18 ( & V_6 -> V_76 , V_62 ) ;
V_75 = F_32 ( V_6 ,
V_388 ) ;
F_21 ( & V_6 -> V_76 , V_62 ) ;
F_143 ( V_6 , V_75 ) ;
} else if ( V_351 -> V_391 == V_394 )
F_144 ( V_6 , V_351 ) ;
if ( V_351 -> V_391 != V_393 )
return;
F_18 ( & V_6 -> V_347 , V_62 ) ;
F_4 (fw_event, &ioc->fw_event_list, list) {
if ( V_345 -> V_353 != V_395 ||
V_345 -> V_396 )
continue;
V_387 = V_345 -> V_351 ;
if ( V_387 -> V_391 ==
V_397 ||
V_387 -> V_391 ==
V_394 ) {
if ( F_9 ( V_387 -> V_390 ) ==
V_388 ) {
F_23 ( V_6 , F_3 ( V_55
L_111 , V_6 -> V_35 ) ) ;
V_345 -> V_396 = 1 ;
}
}
}
F_21 ( & V_6 -> V_347 , V_62 ) ;
}
static void
F_157 ( struct V_5 * V_6 , T_4 V_27 )
{
struct V_46 * V_47 ;
struct V_143 * V_144 ;
unsigned long V_62 ;
F_18 ( & V_6 -> V_72 , V_62 ) ;
V_47 = F_28 ( V_6 , V_27 ) ;
if ( V_47 && V_47 -> V_165 &&
V_47 -> V_165 -> V_146 ) {
V_144 =
V_47 -> V_165 -> V_146 ;
V_144 -> V_376 = 1 ;
F_23 ( V_6 , F_3 ( V_55
L_99
L_112 , V_6 -> V_35 , V_27 ,
( unsigned long long ) V_47 -> V_49 ) ) ;
}
F_21 ( & V_6 -> V_72 , V_62 ) ;
}
static void
F_158 ( T_4 V_27 , T_4 * V_398 , T_4 * V_399 )
{
if ( ! V_27 || V_27 == * V_398 || V_27 == * V_399 )
return;
if ( ! * V_398 )
* V_398 = V_27 ;
else if ( ! * V_399 )
* V_399 = V_27 ;
}
static void
F_159 ( struct V_5 * V_6 ,
T_25 * V_351 )
{
T_26 * V_400 ;
int V_88 ;
T_4 V_27 , V_269 , V_398 , V_399 ;
struct V_374 * V_375 ;
V_398 = 0 ;
V_399 = 0 ;
if ( V_6 -> V_187 )
return;
V_400 = ( T_26 * ) & V_351 -> V_401 [ 0 ] ;
for ( V_88 = 0 ; V_88 < V_351 -> V_402 ; V_88 ++ , V_400 ++ ) {
if ( V_400 -> V_403 ==
V_404 ||
V_400 -> V_403 ==
V_405 ) {
V_269 = F_9 ( V_400 -> V_406 ) ;
F_157 ( V_6 , V_269 ) ;
F_158 ( V_269 , & V_398 , & V_399 ) ;
}
}
V_400 = ( T_26 * ) & V_351 -> V_401 [ 0 ] ;
for ( V_88 = 0 ; V_88 < V_351 -> V_402 ; V_88 ++ , V_400 ++ ) {
if ( F_74 ( V_351 -> V_179 ) &
V_407 )
continue;
if ( V_400 -> V_403 == V_408 ) {
V_269 = F_9 ( V_400 -> V_406 ) ;
F_158 ( V_269 , & V_398 , & V_399 ) ;
}
}
if ( V_398 )
F_149 ( V_6 , V_398 ) ;
if ( V_399 )
F_149 ( V_6 , V_399 ) ;
V_400 = ( T_26 * ) & V_351 -> V_401 [ 0 ] ;
for ( V_88 = 0 ; V_88 < V_351 -> V_402 ; V_88 ++ , V_400 ++ ) {
if ( V_400 -> V_403 != V_408 )
continue;
V_27 = F_9 ( V_400 -> V_409 ) ;
V_269 = F_9 ( V_400 -> V_406 ) ;
F_160 ( V_27 , V_6 -> V_174 ) ;
if ( ! V_269 )
F_145 ( V_6 , V_27 ) ;
else if ( V_269 == V_398 || V_269 == V_399 ) {
V_375 = F_67 ( sizeof( * V_375 ) , V_352 ) ;
F_161 ( ! V_375 ) ;
F_146 ( & V_375 -> V_64 ) ;
V_375 -> V_27 = V_27 ;
F_24 ( & V_375 -> V_64 , & V_6 -> V_378 ) ;
F_23 ( V_6 , F_3 ( V_55
L_101 , V_6 -> V_35 ,
V_27 ) ) ;
} else
F_145 ( V_6 , V_27 ) ;
}
}
static void
F_162 ( struct V_5 * V_6 ,
T_27 * V_351 )
{
T_10 V_197 ;
if ( V_351 -> V_403 != V_410 )
return;
V_197 = F_74 ( V_351 -> V_411 ) ;
if ( V_197 == V_207 || V_197 ==
V_206 )
F_157 ( V_6 ,
F_9 ( V_351 -> V_406 ) ) ;
}
static void
F_163 ( struct V_5 * V_6 )
{
struct V_83 * V_86 ;
T_4 V_84 ;
T_4 V_236 = 0 ;
for ( V_84 = 1 ; V_84 <= V_6 -> V_89 ; V_84 ++ ) {
V_86 = F_37 ( V_6 , V_84 ) ;
if ( ! V_86 )
continue;
V_236 ++ ;
F_155 ( V_6 , V_84 ) ;
F_164 ( V_86 ) ;
if ( V_6 -> V_311 )
V_86 -> V_339 = V_340 << 16 ;
else
V_86 -> V_339 = V_342 << 16 ;
V_86 -> V_341 ( V_86 ) ;
}
F_114 ( V_6 , F_3 ( V_55 L_113 ,
V_6 -> V_35 , V_236 ) ) ;
}
static void
F_165 ( struct V_83 * V_86 , T_11 * V_99 )
{
T_4 V_412 ;
unsigned char V_413 = F_166 ( V_86 ) ;
unsigned char V_414 = F_167 ( V_86 ) ;
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
V_99 -> V_426 . V_427 . V_428 =
F_168 ( F_169 ( V_86 ) ) ;
break;
case V_429 :
V_412 |= V_425 ;
break;
}
V_99 -> V_430 = F_170 ( V_86 -> V_42 -> V_431 ) ;
V_99 -> V_432 = F_115 ( V_412 ) ;
}
static void
F_171 ( struct V_83 * V_86 , T_4 V_30 )
{
T_6 V_433 ;
T_6 V_434 ;
T_6 V_435 ;
switch ( V_30 ) {
case V_436 :
V_433 = 0x01 ;
break;
case V_437 :
V_433 = 0x02 ;
break;
case V_438 :
V_433 = 0x03 ;
break;
default:
V_433 = 0x00 ;
break;
}
if ( V_86 -> V_114 == V_115 ) {
V_434 = V_439 ;
V_435 = V_440 ;
} else {
V_434 = V_441 ;
V_435 = V_442 ;
}
F_172 ( 0 , V_86 -> V_443 , V_434 , 0x10 , V_433 ) ;
V_86 -> V_339 = V_444 << 24 | ( V_435 << 16 ) |
V_445 ;
}
static inline T_6
F_173 ( struct V_5 * V_6 , T_4 V_84 )
{
return V_6 -> V_85 [ V_84 - 1 ] . V_446 ;
}
static inline void
F_174 ( struct V_5 * V_6 , T_4 V_84 , T_6 V_446 )
{
V_6 -> V_85 [ V_84 - 1 ] . V_446 = V_446 ;
}
static void
F_175 ( struct V_5 * V_6 , struct V_83 * V_86 ,
struct V_46 * V_47 , T_11 * V_99 ,
T_4 V_84 )
{
T_10 V_447 , V_448 , V_449 , V_450 , V_451 , V_452 ;
T_10 V_240 , V_241 ;
T_6 V_224 , * V_453 , * V_454 , * V_455 , * V_456 ;
T_6 V_457 = V_86 -> V_458 [ 0 ] ;
if ( V_457 == V_459 || V_457 == V_460 ||
V_457 == V_461 || V_457 == V_462 ) {
V_453 = V_99 -> V_426 . V_463 ;
if ( ( V_457 < V_459 ) || ! ( V_453 [ 2 ] | V_453 [ 3 ] | V_453 [ 4 ]
| V_453 [ 5 ] ) ) {
V_452 = F_50 ( V_86 ) >> 9 ;
V_455 = V_456 = ( V_457 < V_459 ) ? & V_453 [ 2 ] :
& V_453 [ 6 ] ;
V_454 = ( T_6 * ) & V_447 + 3 ;
* V_454 -- = * V_455 ++ ;
* V_454 -- = * V_455 ++ ;
* V_454 -- = * V_455 ++ ;
* V_454 = * V_455 ;
if ( ( ( T_1 ) V_447 + ( T_1 ) V_452 - 1 ) <=
( T_10 ) V_47 -> V_251 ) {
V_240 = V_47 -> V_240 ;
V_241 = V_47 -> V_250 ;
V_449 = V_447 & ( V_240 - 1 ) ;
if ( ( V_449 + V_452 ) <= V_240 ) {
V_224 = V_47 -> V_224 ;
V_448 = V_447 >> V_241 ;
V_450 = V_448 / V_224 ;
V_451 = V_448 % V_224 ;
V_448 = ( V_450 << V_241 ) +
V_449 ;
V_99 -> V_230 =
F_115 ( V_47 ->
V_246 [ V_451 ] ) ;
V_454 = ( T_6 * ) & V_448 + 3 ;
* V_456 ++ = * V_454 -- ;
* V_456 ++ = * V_454 -- ;
* V_456 ++ = * V_454 -- ;
* V_456 = * V_454 ;
F_174 ( V_6 , V_84 , 1 ) ;
}
}
}
}
}
static int
F_176 ( struct V_83 * V_86 , void (* V_297)( struct V_83 * ) )
{
struct V_5 * V_6 = F_56 ( V_86 -> V_42 -> V_139 ) ;
struct V_141 * V_142 ;
struct V_143 * V_144 ;
struct V_46 * V_47 ;
T_11 * V_99 ;
T_10 V_464 ;
T_4 V_84 ;
V_86 -> V_341 = V_297 ;
V_142 = V_86 -> V_42 -> V_146 ;
if ( ! V_142 || ! V_142 -> V_148 ) {
V_86 -> V_339 = V_340 << 16 ;
V_86 -> V_341 ( V_86 ) ;
return 0 ;
}
if ( V_6 -> V_311 ) {
V_86 -> V_339 = V_340 << 16 ;
V_86 -> V_341 ( V_86 ) ;
return 0 ;
}
V_144 = V_142 -> V_148 ;
if ( V_144 -> V_27 == V_170 ) {
V_86 -> V_339 = V_340 << 16 ;
V_86 -> V_341 ( V_86 ) ;
return 0 ;
}
if ( V_6 -> V_309 || V_6 -> V_465 )
return V_466 ;
else if ( V_142 -> V_356 || V_144 -> V_299 )
return V_467 ;
else if ( V_144 -> V_376 ) {
V_86 -> V_339 = V_340 << 16 ;
V_86 -> V_341 ( V_86 ) ;
return 0 ;
}
if ( V_86 -> V_114 == V_468 )
V_464 = V_469 ;
else if ( V_86 -> V_114 == V_115 )
V_464 = V_470 ;
else
V_464 = V_471 ;
if ( ! ( V_142 -> V_62 & V_176 ) ) {
if ( V_86 -> V_42 -> V_151 ) {
if ( V_86 -> V_42 -> V_160 )
V_464 |= V_472 ;
else
V_464 |= V_473 ;
} else
V_464 |= ( 0x500 ) ;
} else
V_464 |= V_473 ;
if ( ! V_6 -> V_187 && ! F_75 ( & V_86 -> V_42 -> V_221 ) &&
F_93 ( V_86 -> V_42 ) && V_86 -> V_474 != 32 )
V_464 |= V_475 ;
V_84 = F_177 ( V_6 , V_6 -> V_476 , V_86 ) ;
if ( ! V_84 ) {
F_3 ( V_34 L_68 ,
V_6 -> V_35 , V_36 ) ;
goto V_71;
}
V_99 = F_46 ( V_6 , V_84 ) ;
memset ( V_99 , 0 , sizeof( T_11 ) ) ;
F_165 ( V_86 , V_99 ) ;
if ( V_86 -> V_474 == 32 )
V_464 |= 4 << V_477 ;
V_99 -> V_320 = V_478 ;
if ( V_142 -> V_148 -> V_62 &
V_175 )
V_99 -> V_320 = V_479 ;
else
V_99 -> V_320 = V_478 ;
V_99 -> V_230 =
F_115 ( V_142 -> V_148 -> V_27 ) ;
V_99 -> V_480 = F_170 ( F_50 ( V_86 ) ) ;
V_99 -> V_481 = F_170 ( V_464 ) ;
V_99 -> V_482 = F_115 ( V_86 -> V_474 ) ;
V_99 -> V_483 = V_484 ;
V_99 -> V_485 = V_486 ;
V_99 -> V_487 =
F_178 ( V_6 , V_84 ) ;
V_99 -> V_488 = F_51 ( T_11 , V_123 ) / 4 ;
V_99 -> V_489 = F_115 ( V_490 +
V_491 ) ;
V_99 -> V_492 = 0 ;
V_99 -> V_493 = 0 ;
F_116 ( V_142 -> V_91 , (struct V_324 * )
V_99 -> V_325 ) ;
memcpy ( V_99 -> V_426 . V_463 , V_86 -> V_458 , V_86 -> V_474 ) ;
if ( ! V_99 -> V_480 ) {
F_179 ( V_6 , & V_99 -> V_123 ) ;
} else {
if ( F_45 ( V_6 , V_86 , V_84 ) ) {
F_155 ( V_6 , V_84 ) ;
goto V_71;
}
}
V_47 = V_144 -> V_47 ;
if ( V_47 && V_47 -> V_234 )
F_175 ( V_6 , V_86 , V_47 , V_99 ,
V_84 ) ;
if ( F_180 ( V_99 -> V_320 == V_478 ) )
F_181 ( V_6 , V_84 ,
F_9 ( V_99 -> V_230 ) ) ;
else
F_154 ( V_6 , V_84 ) ;
return 0 ;
V_71:
return V_466 ;
}
void
F_182 ( struct V_5 * V_6 , struct V_83 * V_86 ,
T_28 * V_29 , T_4 V_84 )
{
T_10 V_494 ;
T_6 * V_495 ;
T_4 V_30 = F_9 ( V_29 -> V_38 ) &
V_39 ;
T_6 V_496 = V_29 -> V_497 ;
T_6 V_498 = V_29 -> V_499 ;
char * V_500 = NULL ;
char * V_501 = NULL ;
char * V_502 = V_6 -> V_503 ;
T_10 V_504 = F_74 ( V_29 -> V_328 ) ;
struct V_44 * V_45 = NULL ;
unsigned long V_62 ;
struct V_164 * V_165 = V_86 -> V_42 -> V_336 ;
struct V_143 * V_337 = V_165 -> V_146 ;
char * V_338 = NULL ;
if ( ! V_337 )
return;
if ( V_6 -> V_268 )
V_338 = L_74 ;
else
V_338 = L_75 ;
if ( V_504 == 0x31170000 )
return;
switch ( V_30 ) {
case V_40 :
V_500 = L_114 ;
break;
case V_505 :
V_500 = L_115 ;
break;
case V_506 :
V_500 = L_116 ;
break;
case V_507 :
V_500 = L_117 ;
break;
case V_508 :
V_500 = L_118 ;
break;
case V_509 :
V_500 = L_119 ;
break;
case V_510 :
V_500 = L_120 ;
break;
case V_511 :
V_500 = L_121 ;
break;
case V_512 :
V_500 = L_122 ;
break;
case V_513 :
V_500 = L_123 ;
break;
case V_514 :
V_500 = L_124 ;
break;
case V_515 :
V_500 = L_125 ;
break;
case V_516 :
V_500 = L_126 ;
break;
case V_517 :
V_500 = L_127 ;
break;
case V_436 :
V_500 = L_128 ;
break;
case V_438 :
V_500 = L_129 ;
break;
case V_437 :
V_500 = L_130 ;
break;
default:
V_500 = L_62 ;
break;
}
switch ( V_498 ) {
case V_518 :
V_501 = L_131 ;
break;
case V_519 :
V_501 = L_132 ;
break;
case V_520 :
V_501 = L_133 ;
break;
case V_521 :
V_501 = L_134 ;
break;
case V_522 :
V_501 = L_135 ;
break;
case V_523 :
V_501 = L_136 ;
break;
case V_524 :
V_501 = L_137 ;
break;
case V_525 :
V_501 = L_138 ;
break;
case V_526 :
V_501 = L_139 ;
break;
case V_527 :
V_501 = L_140 ;
break;
case V_528 :
V_501 = L_141 ;
break;
default:
V_501 = L_62 ;
break;
}
V_502 [ 0 ] = '\0' ;
if ( ! V_496 )
V_502 = L_142 ;
if ( V_496 & V_529 )
strcat ( V_502 , L_143 ) ;
if ( V_496 & V_530 )
strcat ( V_502 , L_144 ) ;
if ( V_496 & V_531 )
strcat ( V_502 , L_145 ) ;
if ( V_496 & V_532 )
strcat ( V_502 , L_146 ) ;
if ( V_496 & V_533 )
strcat ( V_502 , L_147 ) ;
F_123 ( V_86 ) ;
if ( V_337 -> V_62 & V_149 ) {
F_3 ( V_95 L_148 , V_6 -> V_35 ,
V_338 , ( unsigned long long ) V_337 -> V_9 ) ;
} else {
F_18 ( & V_6 -> V_63 , V_62 ) ;
V_45 = F_15 ( V_6 ,
V_337 -> V_9 ) ;
if ( V_45 ) {
F_3 ( V_95 L_149
L_150 , V_6 -> V_35 , V_45 -> V_9 ,
V_45 -> V_271 ) ;
F_3 ( V_95
L_151 ,
V_6 -> V_35 , V_45 -> V_14 ,
V_45 -> V_18 ) ;
}
F_21 ( & V_6 -> V_63 , V_62 ) ;
}
F_3 ( V_95 L_152
L_153 , V_6 -> V_35 , F_9 ( V_29 -> V_230 ) ,
V_500 , V_30 , V_84 ) ;
F_3 ( V_95 L_154
L_155 , V_6 -> V_35 , F_50 ( V_86 ) , V_86 -> V_534 ,
F_183 ( V_86 ) ) ;
F_3 ( V_95 L_156
L_157 , V_6 -> V_35 , F_9 ( V_29 -> V_535 ) ,
F_74 ( V_29 -> V_536 ) , V_86 -> V_339 ) ;
F_3 ( V_95 L_158
L_159 , V_6 -> V_35 , V_501 ,
V_498 , V_502 , V_496 ) ;
if ( V_496 & V_533 ) {
struct V_537 V_538 ;
F_184 ( V_86 -> V_443 , & V_538 ) ;
F_3 ( V_95 L_160
L_161 , V_6 -> V_35 , V_538 . V_539 ,
V_538 . V_540 , V_538 . V_433 , F_74 ( V_29 -> V_541 ) ) ;
}
if ( V_496 & V_529 ) {
V_494 = F_74 ( V_29 -> V_542 ) ;
V_495 = ( T_6 * ) & V_494 ;
F_100 ( V_6 , V_495 [ 0 ] ) ;
}
}
static void
F_185 ( struct V_5 * V_6 , T_4 V_27 )
{
T_29 V_29 ;
T_30 V_99 ;
memset ( & V_99 , 0 , sizeof( T_30 ) ) ;
V_99 . V_320 = V_543 ;
V_99 . V_544 = V_545 ;
V_99 . V_546 =
F_170 ( V_547 ) ;
V_99 . V_230 = F_115 ( V_27 ) ;
V_99 . V_179 = V_548 ;
if ( ( F_186 ( V_6 , & V_29 ,
& V_99 ) ) != 0 ) {
F_3 ( V_34 L_2 , V_6 -> V_35 ,
__FILE__ , __LINE__ , V_36 ) ;
return;
}
if ( V_29 . V_38 || V_29 . V_328 ) {
F_23 ( V_6 , F_3 ( V_55 L_162
L_163 , V_6 -> V_35 ,
F_9 ( V_29 . V_38 ) ,
F_74 ( V_29 . V_328 ) ) ) ;
return;
}
}
static void
F_187 ( struct V_5 * V_6 , T_4 V_27 )
{
struct V_344 * V_345 ;
V_345 = F_67 ( sizeof( struct V_344 ) , V_352 ) ;
if ( ! V_345 )
return;
V_345 -> V_353 = V_549 ;
V_345 -> V_550 = V_27 ;
V_345 -> V_6 = V_6 ;
F_130 ( V_6 , V_345 ) ;
}
static void
F_188 ( struct V_5 * V_6 , T_4 V_27 )
{
struct V_164 * V_165 ;
struct V_143 * V_144 ;
T_31 * V_551 ;
T_32 * V_351 ;
struct V_44 * V_45 ;
T_33 V_223 ;
unsigned long V_62 ;
F_18 ( & V_6 -> V_63 , V_62 ) ;
V_45 = F_16 ( V_6 , V_27 ) ;
if ( ! V_45 ) {
F_21 ( & V_6 -> V_63 , V_62 ) ;
return;
}
V_165 = V_45 -> V_165 ;
V_144 = V_165 -> V_146 ;
if ( ( V_144 -> V_62 & V_175 ) ||
( ( V_144 -> V_62 & V_149 ) ) ) {
F_21 ( & V_6 -> V_63 , V_62 ) ;
return;
}
F_124 ( V_552 , V_165 , L_164 ) ;
F_21 ( & V_6 -> V_63 , V_62 ) ;
if ( V_6 -> V_553 -> V_554 == V_555 )
F_187 ( V_6 , V_27 ) ;
V_223 = F_51 ( T_31 , V_556 ) +
sizeof( T_32 ) ;
V_551 = F_67 ( V_223 , V_169 ) ;
if ( ! V_551 ) {
F_3 ( V_34 L_2 ,
V_6 -> V_35 , __FILE__ , __LINE__ , V_36 ) ;
return;
}
V_551 -> V_320 = V_557 ;
V_551 -> V_558 =
F_115 ( V_559 ) ;
V_551 -> V_294 = V_223 / 4 ;
V_551 -> V_560 =
F_115 ( sizeof( T_32 ) / 4 ) ;
V_351 = ( T_32 * )
V_551 -> V_556 ;
V_351 -> V_403 = V_561 ;
V_351 -> V_562 = 0x5D ;
V_351 -> V_230 = F_115 ( V_27 ) ;
V_351 -> V_11 = F_189 ( V_144 -> V_9 ) ;
F_190 ( V_6 , V_551 ) ;
F_20 ( V_551 ) ;
}
static T_6
F_191 ( struct V_5 * V_6 , T_4 V_84 , T_6 V_288 , T_10 V_289 )
{
T_11 * V_99 ;
T_28 * V_29 ;
struct V_83 * V_86 ;
T_4 V_30 ;
T_10 V_563 ;
T_6 V_496 ;
T_6 V_498 ;
T_10 V_504 ;
struct V_141 * V_142 ;
T_10 V_279 = 0 ;
V_29 = F_102 ( V_6 , V_289 ) ;
V_86 = F_37 ( V_6 , V_84 ) ;
if ( V_86 == NULL )
return 1 ;
V_99 = F_46 ( V_6 , V_84 ) ;
if ( V_29 == NULL ) {
V_86 -> V_339 = V_442 << 16 ;
goto V_71;
}
V_142 = V_86 -> V_42 -> V_146 ;
if ( ! V_142 || ! V_142 -> V_148 ||
V_142 -> V_148 -> V_376 ) {
V_86 -> V_339 = V_340 << 16 ;
goto V_71;
}
if ( F_173 ( V_6 , V_84 ) ) {
F_174 ( V_6 , V_84 , 0 ) ;
memcpy ( V_99 -> V_426 . V_463 , V_86 -> V_458 , V_86 -> V_474 ) ;
V_99 -> V_230 =
F_115 ( V_142 -> V_148 -> V_27 ) ;
F_181 ( V_6 , V_84 ,
V_142 -> V_148 -> V_27 ) ;
return 0 ;
}
V_496 = V_29 -> V_497 ;
if ( V_496 & V_529 )
V_279 =
F_74 ( V_29 -> V_542 ) & 0xFF ;
if ( ! V_142 -> V_564 ) {
V_142 -> V_564 ++ ;
if ( ! V_6 -> V_187 && ! F_75 ( & V_86 -> V_42 -> V_221 ) &&
F_93 ( V_86 -> V_42 ) &&
V_279 == V_282 ) {
F_192 ( V_86 -> V_42 ) ;
F_49 ( V_7 , V_86 -> V_42 , L_165 ) ;
}
}
V_563 = F_74 ( V_29 -> V_536 ) ;
F_193 ( V_86 , F_50 ( V_86 ) - V_563 ) ;
V_30 = F_9 ( V_29 -> V_38 ) ;
if ( V_30 & V_565 )
V_504 = F_74 ( V_29 -> V_328 ) ;
else
V_504 = 0 ;
V_30 &= V_39 ;
V_498 = V_29 -> V_499 ;
if ( V_30 == V_510 && V_563 == 0 &&
( V_498 == V_521 ||
V_498 == V_524 ||
V_498 == V_526 ) ) {
V_30 = V_40 ;
}
if ( V_496 & V_533 ) {
struct V_537 V_538 ;
const void * V_566 = F_194 ( V_6 ,
V_84 ) ;
T_10 V_223 = F_195 ( T_10 , V_486 ,
F_74 ( V_29 -> V_541 ) ) ;
memcpy ( V_86 -> V_443 , V_566 , V_223 ) ;
F_184 ( V_86 -> V_443 , & V_538 ) ;
if ( V_538 . V_540 == 0x5D )
F_188 ( V_6 ,
F_9 ( V_29 -> V_230 ) ) ;
}
switch ( V_30 ) {
case V_567 :
case V_568 :
V_86 -> V_339 = V_569 ;
break;
case V_508 :
V_86 -> V_339 = V_340 << 16 ;
break;
case V_516 :
if ( V_142 -> V_356 ) {
V_86 -> V_339 = V_570 << 16 ;
goto V_71;
}
case V_513 :
case V_517 :
V_86 -> V_339 = V_342 << 16 ;
break;
case V_514 :
if ( ( V_563 == 0 ) || ( V_86 -> V_534 > V_563 ) )
V_86 -> V_339 = V_571 << 16 ;
else
V_86 -> V_339 = ( V_442 << 16 ) | V_498 ;
break;
case V_510 :
V_86 -> V_339 = ( V_442 << 16 ) | V_498 ;
if ( ( V_496 & V_533 ) )
break;
if ( V_563 < V_86 -> V_534 ) {
if ( V_498 == V_569 )
V_86 -> V_339 = V_569 ;
else
V_86 -> V_339 = V_571 << 16 ;
} else if ( V_496 & ( V_532 |
V_531 ) )
V_86 -> V_339 = V_571 << 16 ;
else if ( V_496 & V_530 )
V_86 -> V_339 = V_342 << 16 ;
else if ( ! V_563 && V_86 -> V_458 [ 0 ] == V_572 ) {
V_29 -> V_497 = V_533 ;
V_29 -> V_499 = V_445 ;
V_86 -> V_339 = ( V_444 << 24 ) |
V_445 ;
V_86 -> V_443 [ 0 ] = 0x70 ;
V_86 -> V_443 [ 2 ] = V_439 ;
V_86 -> V_443 [ 12 ] = 0x20 ;
V_86 -> V_443 [ 13 ] = 0 ;
}
break;
case V_509 :
F_193 ( V_86 , 0 ) ;
case V_506 :
case V_40 :
V_86 -> V_339 = ( V_442 << 16 ) | V_498 ;
if ( V_279 ==
V_282 ||
( V_496 & ( V_532 |
V_531 ) ) )
V_86 -> V_339 = V_571 << 16 ;
else if ( V_496 & V_530 )
V_86 -> V_339 = V_342 << 16 ;
break;
case V_436 :
case V_438 :
case V_437 :
F_171 ( V_86 , V_30 ) ;
break;
case V_512 :
case V_505 :
case V_573 :
case V_574 :
case V_575 :
case V_576 :
case V_511 :
case V_515 :
default:
V_86 -> V_339 = V_571 << 16 ;
break;
}
#ifdef F_148
if ( V_86 -> V_339 && ( V_6 -> V_8 & V_577 ) )
F_182 ( V_6 , V_86 , V_29 , V_84 ) ;
#endif
V_71:
F_164 ( V_86 ) ;
V_86 -> V_341 ( V_86 ) ;
return 1 ;
}
static void
F_196 ( struct V_5 * V_6 )
{
T_4 V_223 ;
T_4 V_30 ;
int V_88 ;
T_9 V_29 ;
T_34 * V_578 = NULL ;
T_4 V_579 ;
T_6 V_580 ;
F_114 ( V_6 , F_3 ( V_55
L_166 ,
V_6 -> V_35 , ( unsigned long long ) V_6 -> V_31 . V_9 ) ) ;
V_223 = F_51 ( T_34 , V_581 ) + ( V_6 -> V_31 . V_32
* sizeof( V_582 ) ) ;
V_578 = F_67 ( V_223 , V_169 ) ;
if ( ! V_578 ) {
F_3 ( V_34 L_2 ,
V_6 -> V_35 , __FILE__ , __LINE__ , V_36 ) ;
return;
}
if ( ( F_197 ( V_6 , & V_29 ,
V_578 , V_223 ) ) != 0 )
goto V_71;
V_30 = F_9 ( V_29 . V_38 ) & V_39 ;
if ( V_30 != V_40 )
goto V_71;
for ( V_88 = 0 ; V_88 < V_6 -> V_31 . V_32 ; V_88 ++ ) {
V_580 = V_578 -> V_581 [ V_88 ] . V_583 >> 4 ;
if ( V_88 == 0 )
V_6 -> V_31 . V_27 = F_9 ( V_578 ->
V_581 [ 0 ] . V_584 ) ;
V_6 -> V_31 . V_271 [ V_88 ] . V_27 = V_6 -> V_31 . V_27 ;
V_579 = F_9 ( V_578 -> V_581 [ V_88 ] .
V_369 ) ;
if ( V_579 && V_580 < V_585 )
V_580 = V_585 ;
F_198 ( V_6 , V_6 -> V_31 . V_9 ,
V_579 , V_88 , V_580 ) ;
}
V_71:
F_20 ( V_578 ) ;
}
static void
F_199 ( struct V_5 * V_6 )
{
int V_88 ;
T_9 V_29 ;
T_34 * V_578 = NULL ;
T_35 * V_586 = NULL ;
T_36 V_587 ;
T_8 V_28 ;
T_37 V_588 ;
T_4 V_30 ;
T_4 V_223 ;
T_4 V_589 ;
F_200 ( V_6 , & V_6 -> V_31 . V_32 ) ;
if ( ! V_6 -> V_31 . V_32 ) {
F_3 ( V_34 L_2 ,
V_6 -> V_35 , __FILE__ , __LINE__ , V_36 ) ;
return;
}
V_223 = F_51 ( T_34 , V_581 ) + ( V_6 -> V_31 . V_32 *
sizeof( V_582 ) ) ;
V_578 = F_67 ( V_223 , V_169 ) ;
if ( ! V_578 ) {
F_3 ( V_34 L_2 ,
V_6 -> V_35 , __FILE__ , __LINE__ , V_36 ) ;
return;
}
if ( ( F_197 ( V_6 , & V_29 ,
V_578 , V_223 ) ) ) {
F_3 ( V_34 L_2 ,
V_6 -> V_35 , __FILE__ , __LINE__ , V_36 ) ;
goto V_71;
}
V_30 = F_9 ( V_29 . V_38 ) &
V_39 ;
if ( V_30 != V_40 ) {
F_3 ( V_34 L_2 ,
V_6 -> V_35 , __FILE__ , __LINE__ , V_36 ) ;
goto V_71;
}
V_223 = F_51 ( T_35 , V_581 ) + ( V_6 -> V_31 . V_32 *
sizeof( V_590 ) ) ;
V_586 = F_67 ( V_223 , V_169 ) ;
if ( ! V_586 ) {
F_3 ( V_34 L_2 ,
V_6 -> V_35 , __FILE__ , __LINE__ , V_36 ) ;
goto V_71;
}
if ( ( F_201 ( V_6 , & V_29 ,
V_586 , V_223 ) ) ) {
F_3 ( V_34 L_2 ,
V_6 -> V_35 , __FILE__ , __LINE__ , V_36 ) ;
goto V_71;
}
V_30 = F_9 ( V_29 . V_38 ) &
V_39 ;
if ( V_30 != V_40 ) {
F_3 ( V_34 L_2 ,
V_6 -> V_35 , __FILE__ , __LINE__ , V_36 ) ;
goto V_71;
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
V_6 -> V_31 . V_596 = & V_6 -> V_138 -> V_597 ;
V_6 -> V_31 . V_271 = F_202 ( V_6 -> V_31 . V_32 ,
sizeof( struct V_598 ) , V_169 ) ;
if ( ! V_6 -> V_31 . V_271 ) {
F_3 ( V_34 L_2 ,
V_6 -> V_35 , __FILE__ , __LINE__ , V_36 ) ;
goto V_71;
}
for ( V_88 = 0 ; V_88 < V_6 -> V_31 . V_32 ; V_88 ++ ) {
if ( ( F_203 ( V_6 , & V_29 , & V_587 ,
V_88 ) ) ) {
F_3 ( V_34 L_2 ,
V_6 -> V_35 , __FILE__ , __LINE__ , V_36 ) ;
goto V_71;
}
V_30 = F_9 ( V_29 . V_38 ) &
V_39 ;
if ( V_30 != V_40 ) {
F_3 ( V_34 L_2 ,
V_6 -> V_35 , __FILE__ , __LINE__ , V_36 ) ;
goto V_71;
}
if ( V_88 == 0 )
V_6 -> V_31 . V_27 = F_9 ( V_578 ->
V_581 [ 0 ] . V_584 ) ;
V_6 -> V_31 . V_271 [ V_88 ] . V_27 = V_6 -> V_31 . V_27 ;
V_6 -> V_31 . V_271 [ V_88 ] . V_599 = V_88 ;
F_204 ( V_6 , & V_6 -> V_31 . V_271 [ V_88 ] ,
V_587 , V_6 -> V_31 . V_596 ) ;
}
if ( ( F_12 ( V_6 , & V_29 , & V_28 ,
V_33 , V_6 -> V_31 . V_27 ) ) ) {
F_3 ( V_34 L_2 ,
V_6 -> V_35 , __FILE__ , __LINE__ , V_36 ) ;
goto V_71;
}
V_6 -> V_31 . V_600 =
F_9 ( V_28 . V_601 ) ;
V_6 -> V_31 . V_9 = F_6 ( V_28 . V_11 ) ;
F_3 ( V_55 L_167
L_168 , V_6 -> V_35 , V_6 -> V_31 . V_27 ,
( unsigned long long ) V_6 -> V_31 . V_9 ,
V_6 -> V_31 . V_32 ) ;
if ( V_6 -> V_31 . V_600 ) {
if ( ! ( F_205 ( V_6 , & V_29 ,
& V_588 ,
V_602 ,
V_6 -> V_31 . V_600 ) ) ) {
V_6 -> V_31 . V_14 =
F_6 ( V_588 . V_16 ) ;
}
}
V_71:
F_20 ( V_586 ) ;
F_20 ( V_578 ) ;
}
static int
F_206 ( struct V_5 * V_6 , T_4 V_27 )
{
struct V_74 * V_75 ;
T_9 V_29 ;
T_38 V_603 ;
T_39 V_604 ;
T_37 V_588 ;
T_10 V_30 ;
T_4 V_605 ;
T_40 V_9 , V_66 = 0 ;
int V_88 ;
unsigned long V_62 ;
struct V_357 * V_358 = NULL ;
int V_20 = 0 ;
if ( ! V_27 )
return - 1 ;
if ( V_6 -> V_309 || V_6 -> V_311 )
return - 1 ;
if ( ( F_207 ( V_6 , & V_29 , & V_603 ,
V_606 , V_27 ) ) ) {
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
V_605 = F_9 ( V_603 . V_607 ) ;
if ( F_11 ( V_6 , V_605 , & V_66 )
!= 0 ) {
F_3 ( V_34 L_2 ,
V_6 -> V_35 , __FILE__ , __LINE__ , V_36 ) ;
return - 1 ;
}
if ( V_66 != V_6 -> V_31 . V_9 ) {
F_18 ( & V_6 -> V_76 , V_62 ) ;
V_75 = F_33 ( V_6 ,
V_66 ) ;
F_21 ( & V_6 -> V_76 , V_62 ) ;
if ( ! V_75 ) {
V_20 = F_206 ( V_6 , V_605 ) ;
if ( V_20 != 0 )
return V_20 ;
}
}
F_18 ( & V_6 -> V_76 , V_62 ) ;
V_9 = F_6 ( V_603 . V_11 ) ;
V_75 = F_33 ( V_6 ,
V_9 ) ;
F_21 ( & V_6 -> V_76 , V_62 ) ;
if ( V_75 )
return 0 ;
V_75 = F_67 ( sizeof( struct V_74 ) ,
V_169 ) ;
if ( ! V_75 ) {
F_3 ( V_34 L_2 ,
V_6 -> V_35 , __FILE__ , __LINE__ , V_36 ) ;
return - 1 ;
}
V_75 -> V_27 = V_27 ;
V_75 -> V_32 = V_603 . V_608 ;
V_75 -> V_66 = V_66 ;
V_75 -> V_9 = V_9 ;
F_3 ( V_55 L_169
L_170 , V_6 -> V_35 ,
V_27 , V_605 , ( unsigned long long )
V_75 -> V_9 , V_75 -> V_32 ) ;
if ( ! V_75 -> V_32 )
goto V_609;
V_75 -> V_271 = F_202 ( V_75 -> V_32 ,
sizeof( struct V_598 ) , V_169 ) ;
if ( ! V_75 -> V_271 ) {
F_3 ( V_34 L_2 ,
V_6 -> V_35 , __FILE__ , __LINE__ , V_36 ) ;
V_20 = - 1 ;
goto V_609;
}
F_146 ( & V_75 -> V_610 ) ;
V_358 = F_25 ( V_6 , V_27 ,
V_66 ) ;
if ( ! V_358 ) {
F_3 ( V_34 L_2 ,
V_6 -> V_35 , __FILE__ , __LINE__ , V_36 ) ;
V_20 = - 1 ;
goto V_609;
}
V_75 -> V_596 = & V_358 -> V_168 -> V_166 ;
for ( V_88 = 0 ; V_88 < V_75 -> V_32 ; V_88 ++ ) {
if ( ( F_208 ( V_6 , & V_29 ,
& V_604 , V_88 , V_27 ) ) ) {
F_3 ( V_34 L_2 ,
V_6 -> V_35 , __FILE__ , __LINE__ , V_36 ) ;
V_20 = - 1 ;
goto V_609;
}
V_75 -> V_271 [ V_88 ] . V_27 = V_27 ;
V_75 -> V_271 [ V_88 ] . V_599 = V_88 ;
if ( ( F_209 ( V_6 ,
& V_75 -> V_271 [ V_88 ] , V_604 ,
V_75 -> V_596 ) ) ) {
F_3 ( V_34 L_2 ,
V_6 -> V_35 , __FILE__ , __LINE__ , V_36 ) ;
V_20 = - 1 ;
goto V_609;
}
}
if ( V_75 -> V_600 ) {
if ( ! ( F_205 ( V_6 , & V_29 ,
& V_588 , V_602 ,
V_75 -> V_600 ) ) ) {
V_75 -> V_14 =
F_6 ( V_588 . V_16 ) ;
}
}
F_34 ( V_6 , V_75 ) ;
return 0 ;
V_609:
if ( V_358 )
F_210 ( V_6 , V_75 -> V_9 ,
V_66 ) ;
F_20 ( V_75 ) ;
return V_20 ;
}
static T_6
F_211 ( struct V_5 * V_6 , T_4 V_84 , T_6 V_288 , T_10 V_289 )
{
T_18 * V_29 ;
V_29 = F_102 ( V_6 , V_289 ) ;
if ( V_6 -> V_611 . V_291 == V_292 )
return 1 ;
if ( V_6 -> V_611 . V_84 != V_84 )
return 1 ;
V_6 -> V_611 . V_291 |= V_293 ;
if ( V_29 ) {
memcpy ( V_6 -> V_611 . V_289 , V_29 ,
V_29 -> V_294 * 4 ) ;
V_6 -> V_611 . V_291 |= V_295 ;
}
V_6 -> V_611 . V_291 &= ~ V_296 ;
F_103 ( & V_6 -> V_611 . V_297 ) ;
return 1 ;
}
void
F_212 ( struct V_5 * V_6 , T_1 V_9 )
{
struct V_74 * V_75 ;
unsigned long V_62 ;
if ( V_6 -> V_309 )
return;
F_18 ( & V_6 -> V_76 , V_62 ) ;
V_75 = F_33 ( V_6 ,
V_9 ) ;
if ( ! V_75 ) {
F_21 ( & V_6 -> V_76 , V_62 ) ;
return;
}
F_19 ( & V_75 -> V_64 ) ;
F_21 ( & V_6 -> V_76 , V_62 ) ;
F_213 ( V_6 , V_75 ) ;
}
static T_6
F_214 ( struct V_5 * V_6 , T_1 V_9 ,
T_4 V_27 , T_6 V_612 )
{
T_6 V_20 = 1 ;
char * V_280 = NULL ;
switch ( V_612 ) {
case V_613 :
case V_614 :
V_20 = 0 ;
break;
case V_615 :
V_280 = L_171 ;
break;
case V_616 :
V_280 = L_172 ;
break;
case V_617 :
V_280 = L_173 ;
break;
case V_618 :
V_280 = L_174 ;
break;
case V_619 :
V_280 = L_175 ;
break;
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
case V_630 :
case V_631 :
V_280 = L_176 ;
break;
default:
V_280 = L_62 ;
break;
}
if ( ! V_20 )
return 0 ;
F_3 ( V_34 L_177
L_95 , V_6 -> V_35 , V_280 ,
( unsigned long long ) V_9 , V_27 ) ;
return V_20 ;
}
static void
F_215 ( struct V_5 * V_6 , T_4 V_27 )
{
T_9 V_29 ;
T_8 V_28 ;
struct V_44 * V_45 ;
T_10 V_30 ;
unsigned long V_62 ;
T_1 V_9 ;
struct V_164 * V_165 ;
struct V_143 * V_144 ;
T_10 V_78 ;
if ( ( F_12 ( V_6 , & V_29 , & V_28 ,
V_33 , V_27 ) ) )
return;
V_30 = F_9 ( V_29 . V_38 ) & V_39 ;
if ( V_30 != V_40 )
return;
V_78 = F_74 ( V_28 . V_180 ) ;
if ( ! ( F_35 ( V_78 ) ) )
return;
F_18 ( & V_6 -> V_63 , V_62 ) ;
V_9 = F_6 ( V_28 . V_11 ) ;
V_45 = F_15 ( V_6 ,
V_9 ) ;
if ( ! V_45 ) {
F_3 ( V_34 L_178
L_179 , V_6 -> V_35 , V_27 ) ;
F_21 ( & V_6 -> V_63 , V_62 ) ;
return;
}
if ( F_216 ( V_45 -> V_27 != V_27 ) ) {
V_165 = V_45 -> V_165 ;
V_144 = V_165 -> V_146 ;
F_124 ( V_7 , V_165 , L_180
L_181 , V_45 -> V_27 , V_27 ) ;
V_144 -> V_27 = V_27 ;
V_45 -> V_27 = V_27 ;
}
F_21 ( & V_6 -> V_63 , V_62 ) ;
if ( ! ( F_9 ( V_28 . V_179 ) &
V_632 ) ) {
F_3 ( V_34 L_178
L_182 , V_6 -> V_35 , V_27 ) ;
return;
}
if ( F_214 ( V_6 , V_9 , V_27 ,
V_28 . V_633 ) )
return;
F_139 ( V_6 , V_27 ) ;
}
static int
F_217 ( struct V_5 * V_6 , T_4 V_27 , T_6 V_634 , T_6 V_635 )
{
T_9 V_29 ;
T_8 V_28 ;
T_37 V_588 ;
struct V_44 * V_45 ;
T_10 V_30 ;
T_40 V_9 ;
T_10 V_78 ;
unsigned long V_62 ;
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
if ( ! ( F_9 ( V_28 . V_179 ) &
V_632 ) ) {
F_3 ( V_34 L_2 ,
V_6 -> V_35 , __FILE__ , __LINE__ , V_36 ) ;
F_3 ( V_34 L_183 ,
V_6 -> V_35 , F_9 ( V_28 . V_179 ) ) ;
return - 1 ;
}
if ( F_214 ( V_6 , V_9 , V_27 ,
V_28 . V_633 ) )
return - 1 ;
V_78 = F_74 ( V_28 . V_180 ) ;
if ( ! ( F_35 ( V_78 ) ) ) {
F_3 ( V_34 L_2 ,
V_6 -> V_35 , __FILE__ , __LINE__ , V_36 ) ;
return - 1 ;
}
F_18 ( & V_6 -> V_63 , V_62 ) ;
V_45 = F_15 ( V_6 ,
V_9 ) ;
F_21 ( & V_6 -> V_63 , V_62 ) ;
if ( V_45 )
return 0 ;
V_45 = F_67 ( sizeof( struct V_44 ) ,
V_169 ) ;
if ( ! V_45 ) {
F_3 ( V_34 L_2 ,
V_6 -> V_35 , __FILE__ , __LINE__ , V_36 ) ;
return - 1 ;
}
V_45 -> V_27 = V_27 ;
if ( F_11 ( V_6 , F_9
( V_28 . V_607 ) ,
& V_45 -> V_66 ) != 0 )
F_3 ( V_34 L_2 ,
V_6 -> V_35 , __FILE__ , __LINE__ , V_36 ) ;
V_45 -> V_600 =
F_9 ( V_28 . V_601 ) ;
V_45 -> V_18 =
F_9 ( V_28 . V_636 ) ;
V_45 -> V_78 = V_78 ;
V_45 -> V_9 = V_9 ;
V_45 -> V_271 = V_28 . V_637 ;
if ( V_45 -> V_600 && ! ( F_205 (
V_6 , & V_29 , & V_588 , V_602 ,
V_45 -> V_600 ) ) )
V_45 -> V_14 =
F_6 ( V_588 . V_16 ) ;
V_45 -> V_12 = F_6 ( V_28 . V_13 ) ;
if ( V_6 -> V_48 )
F_26 ( V_6 , V_45 ) ;
else
F_22 ( V_6 , V_45 ) ;
return 0 ;
}
static void
F_218 ( struct V_5 * V_6 ,
struct V_44 * V_45 )
{
struct V_44 V_638 ;
struct V_143 * V_144 ;
if ( ! V_45 )
return;
memcpy ( & V_638 , V_45 , sizeof( struct V_44 ) ) ;
F_17 ( V_6 , V_45 ) ;
F_23 ( V_6 , F_3 ( V_55 L_184
L_185 , V_6 -> V_35 , V_36 ,
V_638 . V_27 , ( unsigned long long )
V_638 . V_9 ) ) ;
if ( V_638 . V_165 && V_638 . V_165 -> V_146 ) {
V_144 = V_638 . V_165 -> V_146 ;
V_144 -> V_376 = 1 ;
}
F_139 ( V_6 , V_638 . V_27 ) ;
if ( ! V_6 -> V_639 )
F_210 ( V_6 ,
V_638 . V_9 ,
V_638 . V_66 ) ;
F_3 ( V_55 L_186
L_187 , V_6 -> V_35 , V_638 . V_27 ,
( unsigned long long ) V_638 . V_9 ) ;
F_23 ( V_6 , F_3 ( V_55 L_188
L_185 , V_6 -> V_35 , V_36 ,
V_638 . V_27 , ( unsigned long long )
V_638 . V_9 ) ) ;
}
void
F_219 ( struct V_5 * V_6 , T_1 V_9 )
{
struct V_44 * V_45 ;
unsigned long V_62 ;
if ( V_6 -> V_309 )
return;
F_18 ( & V_6 -> V_63 , V_62 ) ;
V_45 = F_15 ( V_6 ,
V_9 ) ;
if ( ! V_45 ) {
F_21 ( & V_6 -> V_63 , V_62 ) ;
return;
}
F_21 ( & V_6 -> V_63 , V_62 ) ;
F_218 ( V_6 , V_45 ) ;
}
static void
F_220 ( struct V_5 * V_6 ,
T_22 * V_351 )
{
int V_88 ;
T_4 V_27 ;
T_4 V_365 ;
T_6 V_366 ;
char * V_640 = NULL ;
T_6 V_580 , V_641 ;
switch ( V_351 -> V_391 ) {
case V_397 :
V_640 = L_189 ;
break;
case V_393 :
V_640 = L_190 ;
break;
case V_394 :
case 0 :
V_640 = L_191 ;
break;
case V_392 :
V_640 = L_192 ;
break;
default:
V_640 = L_193 ;
break;
}
F_3 ( V_55 L_194 ,
V_6 -> V_35 , V_640 ) ;
F_3 ( V_7 L_195
L_196 ,
F_9 ( V_351 -> V_390 ) ,
F_9 ( V_351 -> V_601 ) ,
V_351 -> V_370 , V_351 -> V_367 ) ;
for ( V_88 = 0 ; V_88 < V_351 -> V_367 ; V_88 ++ ) {
V_27 = F_9 ( V_351 -> V_368 [ V_88 ] . V_369 ) ;
if ( ! V_27 )
continue;
V_366 = V_351 -> V_370 + V_88 ;
V_365 = V_351 -> V_368 [ V_88 ] . V_371 &
V_372 ;
switch ( V_365 ) {
case V_642 :
V_640 = L_197 ;
break;
case V_389 :
V_640 = L_198 ;
break;
case V_373 :
V_640 = L_199 ;
break;
case V_643 :
V_640 = L_200 ;
break;
case V_644 :
V_640 = L_201 ;
break;
default:
V_640 = L_62 ;
break;
}
V_580 = V_351 -> V_368 [ V_88 ] . V_645 >> 4 ;
V_641 = V_351 -> V_368 [ V_88 ] . V_645 & 0xF ;
F_3 ( V_7 L_202
L_203 , V_366 ,
V_27 , V_640 , V_580 , V_641 ) ;
}
}
static void
F_221 ( struct V_5 * V_6 ,
struct V_344 * V_345 )
{
int V_88 ;
T_4 V_605 , V_27 ;
T_4 V_365 ;
T_6 V_366 , V_646 ;
struct V_74 * V_75 ;
struct V_44 * V_45 ;
T_1 V_9 ;
unsigned long V_62 ;
T_6 V_580 , V_641 ;
T_22 * V_351 = V_345 -> V_351 ;
#ifdef F_148
if ( V_6 -> V_8 & V_647 )
F_220 ( V_6 , V_351 ) ;
#endif
if ( V_6 -> V_309 || V_6 -> V_310 || V_6 -> V_311 )
return;
if ( ! V_6 -> V_31 . V_32 )
F_199 ( V_6 ) ;
else
F_196 ( V_6 ) ;
if ( V_345 -> V_396 ) {
F_23 ( V_6 , F_3 ( V_55 L_204
L_205 , V_6 -> V_35 ) ) ;
return;
}
V_605 = F_9 ( V_351 -> V_390 ) ;
if ( V_351 -> V_391 == V_397 )
if ( F_206 ( V_6 , V_605 ) != 0 )
return;
F_18 ( & V_6 -> V_76 , V_62 ) ;
V_75 = F_32 ( V_6 ,
V_605 ) ;
F_21 ( & V_6 -> V_76 , V_62 ) ;
if ( V_75 ) {
V_9 = V_75 -> V_9 ;
V_646 = V_75 -> V_32 ;
} else if ( V_605 < V_6 -> V_31 . V_32 ) {
V_9 = V_6 -> V_31 . V_9 ;
V_646 = V_6 -> V_31 . V_32 ;
} else
return;
for ( V_88 = 0 ; V_88 < V_351 -> V_367 ; V_88 ++ ) {
if ( V_345 -> V_396 ) {
F_23 ( V_6 , F_3 ( V_55 L_206
L_207 , V_6 -> V_35 ) ) ;
return;
}
if ( V_6 -> V_309 || V_6 -> V_310 ||
V_6 -> V_311 )
return;
V_366 = V_351 -> V_370 + V_88 ;
if ( V_366 >= V_646 )
continue;
V_365 = V_351 -> V_368 [ V_88 ] . V_371 &
V_372 ;
if ( ( V_351 -> V_368 [ V_88 ] . V_371 &
V_648 ) && ( V_365 !=
V_389 ) )
continue;
V_27 = F_9 ( V_351 -> V_368 [ V_88 ] . V_369 ) ;
if ( ! V_27 )
continue;
V_580 = V_351 -> V_368 [ V_88 ] . V_645 >> 4 ;
V_641 = V_351 -> V_368 [ V_88 ] . V_645 & 0xF ;
switch ( V_365 ) {
case V_643 :
if ( V_580 == V_641 )
break;
F_198 ( V_6 , V_9 ,
V_27 , V_366 , V_580 ) ;
if ( V_580 < V_585 )
break;
F_215 ( V_6 , V_27 ) ;
break;
case V_642 :
F_198 ( V_6 , V_9 ,
V_27 , V_366 , V_580 ) ;
F_217 ( V_6 , V_27 , V_366 , 0 ) ;
break;
case V_389 :
F_18 ( & V_6 -> V_63 , V_62 ) ;
V_45 = F_16 ( V_6 ,
V_27 ) ;
if ( ! V_45 ) {
F_21 ( & V_6 -> V_63 ,
V_62 ) ;
break;
}
F_21 ( & V_6 -> V_63 , V_62 ) ;
F_218 ( V_6 , V_45 ) ;
break;
}
}
if ( V_351 -> V_391 == V_393 &&
V_75 )
F_212 ( V_6 , V_9 ) ;
}
static void
F_222 ( struct V_5 * V_6 ,
T_32 * V_351 )
{
char * V_649 = NULL ;
switch ( V_351 -> V_403 ) {
case V_561 :
V_649 = L_208 ;
break;
case V_650 :
V_649 = L_209 ;
break;
case V_651 :
V_649 = L_210 ;
break;
case V_652 :
V_649 = L_211 ;
break;
case V_653 :
V_649 = L_212 ;
break;
case V_654 :
V_649 = L_213 ;
break;
case V_655 :
V_649 = L_214 ;
break;
case V_656 :
V_649 = L_215 ;
break;
case V_657 :
V_649 = L_216 ;
break;
case V_658 :
V_649 = L_217 ;
break;
case V_659 :
V_649 = L_218 ;
break;
case V_660 :
V_649 = L_219 ;
break;
case V_661 :
V_649 = L_220 ;
break;
default:
V_649 = L_221 ;
break;
}
F_3 ( V_55 L_222
L_223 , V_6 -> V_35 ,
V_649 , F_9 ( V_351 -> V_230 ) ,
( unsigned long long ) F_6 ( V_351 -> V_11 ) ) ;
if ( V_351 -> V_403 == V_561 )
F_3 ( V_55 L_224 , V_6 -> V_35 ,
V_351 -> V_562 , V_351 -> V_662 ) ;
F_3 ( V_7 L_225 ) ;
}
static void
F_223 ( struct V_5 * V_6 ,
struct V_344 * V_345 )
{
struct V_143 * V_663 ;
struct V_44 * V_45 ;
T_40 V_9 ;
unsigned long V_62 ;
T_32 * V_351 =
V_345 -> V_351 ;
#ifdef F_148
if ( V_6 -> V_8 & V_647 )
F_222 ( V_6 ,
V_351 ) ;
#endif
if ( ( V_6 -> V_254 . V_664 >> 8 ) < 0xC )
return;
if ( V_351 -> V_403 !=
V_651 &&
V_351 -> V_403 !=
V_657 )
return;
F_18 ( & V_6 -> V_63 , V_62 ) ;
V_9 = F_6 ( V_351 -> V_11 ) ;
V_45 = F_15 ( V_6 ,
V_9 ) ;
F_21 ( & V_6 -> V_63 , V_62 ) ;
if ( ! V_45 || ! V_45 -> V_165 )
return;
V_663 = V_45 -> V_165 -> V_146 ;
if ( ! V_663 )
return;
if ( V_351 -> V_403 ==
V_651 )
V_663 -> V_299 = 1 ;
else
V_663 -> V_299 = 0 ;
}
static void
F_224 ( struct V_5 * V_6 ,
T_41 * V_351 )
{
char * V_649 = NULL ;
switch ( V_351 -> V_403 ) {
case V_665 :
V_649 = L_226 ;
break;
case V_666 :
V_649 = L_227 ;
break;
default:
V_649 = L_221 ;
break;
}
F_3 ( V_55 L_228
L_229
L_230 , V_6 -> V_35 , V_649 ,
F_9 ( V_351 -> V_601 ) ,
( unsigned long long ) F_6 ( V_351 -> V_16 ) ,
F_9 ( V_351 -> V_667 ) ) ;
}
static void
F_225 ( struct V_5 * V_6 ,
struct V_344 * V_345 )
{
#ifdef F_148
if ( V_6 -> V_8 & V_647 )
F_224 ( V_6 ,
V_345 -> V_351 ) ;
#endif
}
static void
F_226 ( struct V_5 * V_6 ,
struct V_344 * V_345 )
{
struct V_83 * V_86 ;
struct V_134 * V_135 ;
T_4 V_84 , V_27 ;
T_10 V_91 ;
struct V_141 * V_142 ;
T_10 V_668 ;
T_10 V_669 ;
T_21 * V_29 ;
#ifdef F_148
T_42 * V_351 = V_345 -> V_351 ;
#endif
T_4 V_30 ;
unsigned long V_62 ;
int V_70 ;
F_23 ( V_6 , F_3 ( V_55 L_231
L_232 , V_6 -> V_35 , V_351 -> V_637 ,
V_351 -> V_670 ) ) ;
F_114 ( V_6 , F_3 ( V_55 L_233 , V_6 -> V_35 ,
V_36 ) ) ;
F_18 ( & V_6 -> V_87 , V_62 ) ;
V_6 -> V_671 = 0 ;
V_668 = 0 ;
V_669 = 0 ;
V_29 = V_6 -> V_290 . V_289 ;
for ( V_84 = 1 ; V_84 <= V_6 -> V_89 ; V_84 ++ ) {
V_86 = F_36 ( V_6 , V_84 ) ;
if ( ! V_86 )
continue;
V_135 = V_86 -> V_42 ;
V_142 = V_135 -> V_146 ;
if ( ! V_142 || ! V_142 -> V_148 )
continue;
if ( V_142 -> V_148 -> V_62 &
V_175 )
continue;
if ( V_142 -> V_148 -> V_62 &
V_149 )
continue;
V_27 = V_142 -> V_148 -> V_27 ;
V_91 = V_142 -> V_91 ;
V_669 ++ ;
F_21 ( & V_6 -> V_87 , V_62 ) ;
F_107 ( V_6 , V_27 , 0 , 0 , V_91 ,
V_672 , V_84 , 30 , NULL ) ;
V_6 -> V_290 . V_291 = V_292 ;
V_30 = F_9 ( V_29 -> V_38 )
& V_39 ;
if ( ( V_30 == V_40 ) &&
( V_29 -> V_331 ==
V_285 ||
V_29 -> V_331 ==
V_287 ) ) {
F_18 ( & V_6 -> V_87 , V_62 ) ;
continue;
}
V_70 = F_107 ( V_6 , V_27 , V_135 -> V_69 , V_135 -> V_68 ,
V_135 -> V_91 , V_333 , V_84 , 30 ,
V_86 ) ;
if ( V_70 == V_307 )
F_49 ( V_552 , V_135 , L_234
L_82 , V_86 ) ;
V_668 += F_74 ( V_29 -> V_329 ) ;
F_18 ( & V_6 -> V_87 , V_62 ) ;
}
F_21 ( & V_6 -> V_87 , V_62 ) ;
F_114 ( V_6 , F_3 ( V_55
L_235 ,
V_6 -> V_35 , V_36 , V_669 , V_668 ) ) ;
}
static void
F_227 ( struct V_5 * V_6 ,
struct V_344 * V_345 )
{
T_43 * V_351 = V_345 -> V_351 ;
#ifdef F_148
if ( V_6 -> V_8 & V_647 ) {
F_3 ( V_55 L_236 , V_6 -> V_35 ,
( V_351 -> V_403 == V_673 ) ?
L_237 : L_238 ) ;
if ( V_351 -> V_674 )
F_3 ( L_239 ,
F_74 ( V_351 -> V_674 ) ) ;
F_3 ( L_225 ) ;
}
#endif
if ( V_351 -> V_403 == V_673 &&
! V_6 -> V_31 . V_32 )
F_199 ( V_6 ) ;
}
static void
F_228 ( struct V_134 * V_135 , void * V_178 )
{
int V_20 ;
V_135 -> V_178 = V_178 ? 1 : 0 ;
F_49 ( V_7 , V_135 , L_240 ,
V_135 -> V_178 ? L_241 : L_242 ) ;
V_20 = F_229 ( V_135 ) ;
}
static void
F_230 ( struct V_164 * V_165 , int V_178 )
{
struct V_143 * V_144 = V_165 -> V_146 ;
if ( V_178 )
V_144 -> V_62 |= V_175 ;
else
V_144 -> V_62 &= ~ V_175 ;
F_231 ( V_165 , V_178 ? ( void * ) 1 : NULL ,
F_228 ) ;
}
static void
F_232 ( struct V_5 * V_6 ,
T_26 * V_400 )
{
struct V_46 * V_47 ;
unsigned long V_62 ;
T_1 V_49 ;
T_4 V_27 = F_9 ( V_400 -> V_406 ) ;
int V_20 ;
F_96 ( V_6 , V_27 , & V_49 ) ;
if ( ! V_49 ) {
F_3 ( V_34
L_2 , V_6 -> V_35 ,
__FILE__ , __LINE__ , V_36 ) ;
return;
}
F_18 ( & V_6 -> V_72 , V_62 ) ;
V_47 = F_29 ( V_6 , V_49 ) ;
F_21 ( & V_6 -> V_72 , V_62 ) ;
if ( V_47 )
return;
V_47 = F_67 ( sizeof( struct V_46 ) , V_169 ) ;
if ( ! V_47 ) {
F_3 ( V_34
L_2 , V_6 -> V_35 ,
__FILE__ , __LINE__ , V_36 ) ;
return;
}
V_47 -> V_68 = V_6 -> V_675 ++ ;
V_47 -> V_69 = V_171 ;
V_47 -> V_27 = V_27 ;
V_47 -> V_49 = V_49 ;
F_30 ( V_6 , V_47 ) ;
if ( ! V_6 -> V_48 ) {
V_20 = F_233 ( V_6 -> V_138 , V_171 ,
V_47 -> V_68 , 0 ) ;
if ( V_20 )
F_31 ( V_6 , V_47 ) ;
} else
F_13 ( V_6 , V_47 , 1 ) ;
}
static void
F_234 ( struct V_5 * V_6 , T_4 V_27 )
{
struct V_46 * V_47 ;
unsigned long V_62 ;
struct V_143 * V_144 ;
F_18 ( & V_6 -> V_72 , V_62 ) ;
V_47 = F_28 ( V_6 , V_27 ) ;
F_21 ( & V_6 -> V_72 , V_62 ) ;
if ( ! V_47 )
return;
if ( V_47 -> V_165 ) {
V_144 = V_47 -> V_165 -> V_146 ;
V_144 -> V_376 = 1 ;
F_235 ( & V_47 -> V_165 -> V_166 ) ;
}
F_3 ( V_55 L_243
L_187 , V_6 -> V_35 , V_47 -> V_27 ,
( unsigned long long ) V_47 -> V_49 ) ;
F_31 ( V_6 , V_47 ) ;
}
static void
F_236 ( struct V_5 * V_6 ,
T_26 * V_400 )
{
struct V_44 * V_45 ;
unsigned long V_62 ;
T_4 V_27 = F_9 ( V_400 -> V_409 ) ;
F_18 ( & V_6 -> V_63 , V_62 ) ;
V_45 = F_16 ( V_6 , V_27 ) ;
F_21 ( & V_6 -> V_63 , V_62 ) ;
if ( ! V_45 )
return;
V_45 -> V_269 = 0 ;
V_45 -> V_270 = 0 ;
F_160 ( V_27 , V_6 -> V_174 ) ;
F_230 ( V_45 -> V_165 , 0 ) ;
}
static void
F_237 ( struct V_5 * V_6 ,
T_26 * V_400 )
{
struct V_44 * V_45 ;
unsigned long V_62 ;
T_4 V_27 = F_9 ( V_400 -> V_409 ) ;
F_18 ( & V_6 -> V_63 , V_62 ) ;
V_45 = F_16 ( V_6 , V_27 ) ;
F_21 ( & V_6 -> V_63 , V_62 ) ;
if ( ! V_45 )
return;
F_95 ( V_6 , V_27 ,
& V_45 -> V_269 ) ;
F_96 ( V_6 , V_45 -> V_269 ,
& V_45 -> V_270 ) ;
F_238 ( V_27 , V_6 -> V_174 ) ;
F_230 ( V_45 -> V_165 , 1 ) ;
}
static void
F_239 ( struct V_5 * V_6 ,
T_26 * V_400 )
{
struct V_44 * V_45 ;
unsigned long V_62 ;
T_4 V_27 = F_9 ( V_400 -> V_409 ) ;
F_18 ( & V_6 -> V_63 , V_62 ) ;
V_45 = F_16 ( V_6 , V_27 ) ;
F_21 ( & V_6 -> V_63 , V_62 ) ;
if ( ! V_45 )
return;
F_218 ( V_6 , V_45 ) ;
}
static void
F_240 ( struct V_5 * V_6 ,
T_26 * V_400 )
{
struct V_44 * V_45 ;
unsigned long V_62 ;
T_4 V_27 = F_9 ( V_400 -> V_409 ) ;
T_9 V_29 ;
T_8 V_28 ;
T_10 V_30 ;
T_1 V_9 ;
T_4 V_605 ;
F_238 ( V_27 , V_6 -> V_174 ) ;
F_18 ( & V_6 -> V_63 , V_62 ) ;
V_45 = F_16 ( V_6 , V_27 ) ;
F_21 ( & V_6 -> V_63 , V_62 ) ;
if ( V_45 )
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
V_605 = F_9 ( V_28 . V_607 ) ;
if ( ! F_11 ( V_6 , V_605 , & V_9 ) )
F_198 ( V_6 , V_9 , V_27 ,
V_28 . V_637 , V_585 ) ;
F_217 ( V_6 , V_27 , 0 , 1 ) ;
}
static void
F_241 ( struct V_5 * V_6 ,
T_25 * V_351 )
{
T_26 * V_400 ;
T_6 V_676 ;
int V_88 ;
char * V_649 = NULL , * V_677 = NULL ;
V_400 = ( T_26 * ) & V_351 -> V_401 [ 0 ] ;
F_3 ( V_55 L_244 ,
V_6 -> V_35 , ( F_74 ( V_351 -> V_179 ) &
V_407 ) ?
L_245 : L_246 , V_351 -> V_402 ) ;
for ( V_88 = 0 ; V_88 < V_351 -> V_402 ; V_88 ++ , V_400 ++ ) {
switch ( V_400 -> V_403 ) {
case V_678 :
V_649 = L_189 ;
break;
case V_405 :
V_649 = L_190 ;
break;
case V_679 :
V_649 = L_247 ;
break;
case V_680 :
V_649 = L_248 ;
break;
case V_408 :
V_649 = L_249 ;
break;
case V_681 :
V_649 = L_250 ;
break;
case V_404 :
V_649 = L_251 ;
break;
case V_682 :
V_649 = L_252 ;
break;
case V_683 :
V_649 = L_253 ;
break;
default:
V_649 = L_221 ;
break;
}
V_676 = F_9 ( V_400 -> V_684 ) &
V_685 ;
switch ( V_676 ) {
case V_686 :
V_677 = L_75 ;
break;
case V_687 :
V_677 = L_254 ;
break;
case V_688 :
V_677 = L_255 ;
break;
default:
V_677 = L_256 ;
break;
}
F_3 ( V_7 L_257
L_258 , V_677 ,
V_649 , F_9 ( V_400 -> V_406 ) ,
F_9 ( V_400 -> V_409 ) ,
V_400 -> V_229 ) ;
}
}
static void
F_242 ( struct V_5 * V_6 ,
struct V_344 * V_345 )
{
T_26 * V_400 ;
int V_88 ;
T_6 V_689 ;
T_25 * V_351 = V_345 -> V_351 ;
#ifdef F_148
if ( ( V_6 -> V_8 & V_647 )
&& ! V_6 -> V_268 )
F_241 ( V_6 , V_351 ) ;
#endif
V_689 = ( F_74 ( V_351 -> V_179 ) &
V_407 ) ? 1 : 0 ;
V_400 = ( T_26 * ) & V_351 -> V_401 [ 0 ] ;
for ( V_88 = 0 ; V_88 < V_351 -> V_402 ; V_88 ++ , V_400 ++ ) {
switch ( V_400 -> V_403 ) {
case V_681 :
case V_678 :
if ( ! V_689 )
F_232 ( V_6 , V_400 ) ;
break;
case V_404 :
case V_405 :
if ( ! V_689 )
F_234 ( V_6 ,
F_9 ( V_400 -> V_406 ) ) ;
break;
case V_682 :
if ( ! V_6 -> V_187 )
F_237 ( V_6 , V_400 ) ;
break;
case V_683 :
if ( ! V_6 -> V_187 )
F_236 ( V_6 , V_400 ) ;
break;
case V_680 :
if ( ! V_6 -> V_187 )
F_240 ( V_6 , V_400 ) ;
break;
case V_408 :
if ( ! V_6 -> V_187 )
F_239 ( V_6 , V_400 ) ;
break;
}
}
}
static void
F_243 ( struct V_5 * V_6 ,
struct V_344 * V_345 )
{
T_1 V_49 ;
unsigned long V_62 ;
struct V_46 * V_47 ;
T_4 V_27 ;
T_10 V_197 ;
int V_20 ;
T_27 * V_351 = V_345 -> V_351 ;
if ( V_351 -> V_403 != V_410 )
return;
V_27 = F_9 ( V_351 -> V_406 ) ;
V_197 = F_74 ( V_351 -> V_411 ) ;
if ( ! V_6 -> V_268 )
F_23 ( V_6 , F_3 ( V_55 L_49
L_259 , V_6 -> V_35 , V_36 , V_27 ,
F_74 ( V_351 -> V_690 ) , V_197 ) ) ;
switch ( V_197 ) {
case V_207 :
case V_206 :
F_234 ( V_6 , V_27 ) ;
break;
case V_202 :
case V_204 :
case V_201 :
F_18 ( & V_6 -> V_72 , V_62 ) ;
V_47 = F_28 ( V_6 , V_27 ) ;
F_21 ( & V_6 -> V_72 , V_62 ) ;
if ( V_47 )
break;
F_96 ( V_6 , V_27 , & V_49 ) ;
if ( ! V_49 ) {
F_3 ( V_34
L_2 , V_6 -> V_35 ,
__FILE__ , __LINE__ , V_36 ) ;
break;
}
V_47 = F_67 ( sizeof( struct V_46 ) , V_169 ) ;
if ( ! V_47 ) {
F_3 ( V_34
L_2 , V_6 -> V_35 ,
__FILE__ , __LINE__ , V_36 ) ;
break;
}
V_47 -> V_68 = V_6 -> V_675 ++ ;
V_47 -> V_69 = V_171 ;
V_47 -> V_27 = V_27 ;
V_47 -> V_49 = V_49 ;
F_30 ( V_6 , V_47 ) ;
V_20 = F_233 ( V_6 -> V_138 , V_171 ,
V_47 -> V_68 , 0 ) ;
if ( V_20 )
F_31 ( V_6 , V_47 ) ;
break;
case V_691 :
default:
break;
}
}
static void
F_244 ( struct V_5 * V_6 ,
struct V_344 * V_345 )
{
T_4 V_27 , V_605 ;
T_10 V_197 ;
struct V_44 * V_45 ;
unsigned long V_62 ;
T_9 V_29 ;
T_8 V_28 ;
T_10 V_30 ;
T_44 * V_351 = V_345 -> V_351 ;
T_1 V_9 ;
if ( V_351 -> V_403 != V_692 )
return;
V_27 = F_9 ( V_351 -> V_409 ) ;
V_197 = F_74 ( V_351 -> V_411 ) ;
if ( ! V_6 -> V_268 )
F_23 ( V_6 , F_3 ( V_55 L_49
L_259 , V_6 -> V_35 , V_36 , V_27 ,
F_74 ( V_351 -> V_690 ) , V_197 ) ) ;
switch ( V_197 ) {
case V_693 :
case V_694 :
case V_695 :
case V_696 :
case V_697 :
if ( ! V_6 -> V_187 )
F_238 ( V_27 , V_6 -> V_174 ) ;
F_18 ( & V_6 -> V_63 , V_62 ) ;
V_45 = F_16 ( V_6 , V_27 ) ;
F_21 ( & V_6 -> V_63 , V_62 ) ;
if ( V_45 )
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
V_605 = F_9 ( V_28 . V_607 ) ;
if ( ! F_11 ( V_6 , V_605 , & V_9 ) )
F_198 ( V_6 , V_9 , V_27 ,
V_28 . V_637 , V_585 ) ;
F_217 ( V_6 , V_27 , 0 , 1 ) ;
break;
case V_698 :
case V_699 :
case V_700 :
default:
break;
}
}
static void
F_245 ( struct V_5 * V_6 ,
T_45 * V_351 )
{
char * V_649 = NULL ;
switch ( V_351 -> V_701 ) {
case V_702 :
V_649 = L_260 ;
break;
case V_703 :
V_649 = L_261 ;
break;
case V_704 :
V_649 = L_262 ;
break;
case V_705 :
V_649 = L_263 ;
break;
case V_706 :
V_649 = L_264 ;
break;
}
if ( ! V_649 )
return;
F_3 ( V_55 L_265
L_266 ,
V_6 -> V_35 , V_649 ,
F_9 ( V_351 -> V_406 ) ,
V_351 -> V_707 ) ;
}
static void
F_246 ( struct V_5 * V_6 ,
struct V_344 * V_345 )
{
T_45 * V_351 = V_345 -> V_351 ;
static struct V_46 * V_47 ;
unsigned long V_62 ;
T_4 V_27 ;
#ifdef F_148
if ( ( V_6 -> V_8 & V_647 )
&& ! V_6 -> V_268 )
F_245 ( V_6 ,
V_351 ) ;
#endif
if ( V_351 -> V_701 == V_702 ) {
V_27 = F_9 ( V_351 -> V_406 ) ;
F_18 ( & V_6 -> V_72 , V_62 ) ;
V_47 = F_28 ( V_6 , V_27 ) ;
F_21 ( & V_6 -> V_72 , V_62 ) ;
if ( ! V_47 )
return;
if ( V_351 -> V_701 == V_702 )
V_47 -> V_190 =
V_351 -> V_707 ;
}
}
static void
F_247 ( struct V_5 * V_6 )
{
struct V_141 * V_142 ;
struct V_134 * V_135 ;
F_105 (sdev, ioc->shost) {
V_142 = V_135 -> V_146 ;
if ( V_142 && V_142 -> V_148 )
V_142 -> V_148 -> V_376 = 1 ;
}
}
static void
F_248 ( struct V_5 * V_6 , T_1 V_9 ,
T_4 V_18 , T_4 V_27 )
{
struct V_143 * V_144 = NULL ;
struct V_164 * V_165 ;
struct V_44 * V_45 ;
unsigned long V_62 ;
F_18 ( & V_6 -> V_63 , V_62 ) ;
F_4 (sas_device, &ioc->sas_device_list, list) {
if ( V_45 -> V_9 == V_9 &&
V_45 -> V_18 == V_18 ) {
V_45 -> V_708 = 1 ;
V_165 = V_45 -> V_165 ;
if ( V_165 && V_165 -> V_146 ) {
V_144 = V_165 -> V_146 ;
V_144 -> V_299 = 0 ;
V_144 -> V_376 = 0 ;
} else
V_144 = NULL ;
if ( V_165 )
F_124 ( V_7 , V_165 ,
L_267
L_268
L_269 , V_27 ,
( unsigned long long ) V_45 -> V_9 ,
( unsigned long long )
V_45 -> V_14 ,
V_45 -> V_18 ) ;
if ( V_45 -> V_27 == V_27 )
goto V_71;
F_3 ( V_7 L_270 ,
V_45 -> V_27 ) ;
V_45 -> V_27 = V_27 ;
if ( V_144 )
V_144 -> V_27 = V_27 ;
goto V_71;
}
}
V_71:
F_21 ( & V_6 -> V_63 , V_62 ) ;
}
static void
F_249 ( struct V_5 * V_6 )
{
T_8 V_28 ;
T_9 V_29 ;
T_4 V_30 ;
T_40 V_9 ;
T_4 V_27 ;
T_10 V_78 ;
T_4 V_18 ;
F_3 ( V_55 L_271 , V_6 -> V_35 , V_36 ) ;
if ( F_42 ( & V_6 -> V_65 ) )
return;
V_27 = 0xFFFF ;
while ( ! ( F_12 ( V_6 , & V_29 ,
& V_28 , V_709 ,
V_27 ) ) ) {
V_30 = F_9 ( V_29 . V_38 ) &
V_39 ;
if ( V_30 == V_233 )
break;
V_27 = F_9 ( V_28 . V_230 ) ;
V_78 = F_74 ( V_28 . V_180 ) ;
if ( ! ( F_35 ( V_78 ) ) )
continue;
V_9 = F_6 ( V_28 . V_11 ) ;
V_18 = F_9 ( V_28 . V_636 ) ;
F_248 ( V_6 , V_9 , V_18 ,
V_27 ) ;
}
}
static void
F_250 ( struct V_5 * V_6 , T_1 V_49 ,
T_4 V_27 )
{
struct V_143 * V_144 ;
struct V_164 * V_165 ;
struct V_46 * V_47 ;
unsigned long V_62 ;
F_18 ( & V_6 -> V_72 , V_62 ) ;
F_4 (raid_device, &ioc->raid_device_list, list) {
if ( V_47 -> V_49 == V_49 && V_47 -> V_165 ) {
V_165 = V_47 -> V_165 ;
if ( V_165 && V_165 -> V_146 ) {
V_144 = V_165 -> V_146 ;
V_144 -> V_376 = 0 ;
} else
V_144 = NULL ;
V_47 -> V_708 = 1 ;
F_124 ( V_7 , V_47 -> V_165 ,
L_272 , V_27 ,
( unsigned long long ) V_47 -> V_49 ) ;
F_90 ( V_6 , V_47 ) ;
if ( V_47 -> V_27 == V_27 )
goto V_71;
F_3 ( V_7 L_270 ,
V_47 -> V_27 ) ;
V_47 -> V_27 = V_27 ;
if ( V_144 )
V_144 -> V_27 = V_27 ;
goto V_71;
}
}
V_71:
F_21 ( & V_6 -> V_72 , V_62 ) ;
}
static void
F_251 ( struct V_5 * V_6 )
{
T_15 V_710 ;
T_13 V_711 ;
T_14 V_222 ;
T_9 V_29 ;
T_4 V_30 ;
T_4 V_27 ;
T_6 V_712 ;
F_3 ( V_55 L_271 , V_6 -> V_35 , V_36 ) ;
if ( F_42 ( & V_6 -> V_73 ) )
return;
V_27 = 0xFFFF ;
while ( ! ( F_88 ( V_6 , & V_29 ,
& V_710 , V_232 , V_27 ) ) ) {
V_30 = F_9 ( V_29 . V_38 ) &
V_39 ;
if ( V_30 == V_233 )
break;
V_27 = F_9 ( V_710 . V_230 ) ;
if ( F_78 ( V_6 , & V_29 ,
& V_711 , V_191 , V_27 ,
sizeof( T_13 ) ) )
continue;
if ( V_711 . V_200 == V_201 ||
V_711 . V_200 == V_202 ||
V_711 . V_200 == V_204 )
F_250 ( V_6 ,
F_6 ( V_710 . V_713 ) , V_27 ) ;
}
if ( ! V_6 -> V_187 ) {
V_712 = 0xFF ;
memset ( V_6 -> V_174 , 0 , V_6 -> V_714 ) ;
while ( ! ( F_86 ( V_6 , & V_29 ,
& V_222 , V_715 ,
V_712 ) ) ) {
V_30 = F_9 ( V_29 . V_38 ) &
V_39 ;
if ( V_30 == V_233 )
break;
V_712 = V_222 . V_229 ;
V_27 = F_9 ( V_222 . V_230 ) ;
F_238 ( V_27 , V_6 -> V_174 ) ;
}
}
}
static void
F_252 ( struct V_5 * V_6 , T_1 V_9 ,
T_4 V_27 )
{
struct V_74 * V_75 ;
unsigned long V_62 ;
int V_88 ;
F_18 ( & V_6 -> V_76 , V_62 ) ;
F_4 (sas_expander, &ioc->sas_expander_list, list) {
if ( V_75 -> V_9 != V_9 )
continue;
V_75 -> V_708 = 1 ;
if ( V_75 -> V_27 == V_27 )
goto V_71;
F_3 ( V_7 L_273
L_274 ,
( unsigned long long ) V_75 -> V_9 ,
V_75 -> V_27 , V_27 ) ;
V_75 -> V_27 = V_27 ;
for ( V_88 = 0 ; V_88 < V_75 -> V_32 ; V_88 ++ )
V_75 -> V_271 [ V_88 ] . V_27 = V_27 ;
goto V_71;
}
V_71:
F_21 ( & V_6 -> V_76 , V_62 ) ;
}
static void
F_253 ( struct V_5 * V_6 )
{
T_38 V_603 ;
T_9 V_29 ;
T_4 V_30 ;
T_40 V_9 ;
T_4 V_27 ;
F_3 ( V_55 L_271 , V_6 -> V_35 , V_36 ) ;
if ( F_42 ( & V_6 -> V_77 ) )
return;
V_27 = 0xFFFF ;
while ( ! ( F_207 ( V_6 , & V_29 , & V_603 ,
V_716 , V_27 ) ) ) {
V_30 = F_9 ( V_29 . V_38 ) &
V_39 ;
if ( V_30 == V_233 )
break;
V_27 = F_9 ( V_603 . V_230 ) ;
V_9 = F_6 ( V_603 . V_11 ) ;
F_3 ( V_7 L_275
L_100 , V_27 ,
( unsigned long long ) V_9 ) ;
F_252 ( V_6 , V_9 , V_27 ) ;
}
}
static void
F_254 ( struct V_5 * V_6 )
{
struct V_44 * V_45 , * V_717 ;
struct V_74 * V_75 ;
struct V_46 * V_47 , * V_718 ;
F_137 (sas_device, sas_device_next,
&ioc->sas_device_list, list) {
if ( V_45 -> V_708 ) {
V_45 -> V_708 = 0 ;
continue;
}
if ( V_45 -> V_165 )
F_124 ( V_7 , V_45 -> V_165 ,
L_276
L_277 ,
V_45 -> V_27 ,
( unsigned long long ) V_45 -> V_9 ,
( unsigned long long )
V_45 -> V_14 ,
V_45 -> V_18 ) ;
F_218 ( V_6 , V_45 ) ;
}
F_137 (raid_device, raid_device_next,
&ioc->raid_device_list, list) {
if ( V_47 -> V_708 ) {
V_47 -> V_708 = 0 ;
continue;
}
if ( V_47 -> V_165 ) {
F_124 ( V_7 , V_47 -> V_165 ,
L_278 ,
V_47 -> V_27 ,
( unsigned long long ) V_47 -> V_49 ) ;
F_235 ( & V_47 -> V_165 -> V_166 ) ;
}
F_31 ( V_6 , V_47 ) ;
}
V_719:
V_75 = NULL ;
F_4 (sas_expander, &ioc->sas_expander_list, list) {
if ( V_75 -> V_708 ) {
V_75 -> V_708 = 0 ;
continue;
}
F_212 ( V_6 , V_75 -> V_9 ) ;
goto V_719;
}
}
static void
F_255 ( struct V_5 * V_6 )
{
struct V_44 * V_45 , * V_717 ;
if ( ! V_6 -> V_187 || V_6 -> V_242 !=
V_720 )
return;
if ( V_6 -> V_639 ) {
if ( F_89 ( V_6 ) )
return;
V_6 -> V_639 = 0 ;
F_137 (sas_device, sas_device_next,
&ioc->sas_device_list, list) {
if ( ! F_25 ( V_6 , V_45 -> V_27 ,
V_45 -> V_66 ) ) {
F_17 ( V_6 , V_45 ) ;
} else if ( ! V_45 -> V_165 ) {
F_210 ( V_6 ,
V_45 -> V_9 ,
V_45 -> V_66 ) ;
F_17 ( V_6 , V_45 ) ;
}
}
} else {
if ( ! F_89 ( V_6 ) )
return;
V_6 -> V_639 = 1 ;
F_137 (sas_device, sas_device_next,
&ioc->sas_device_list, list) {
F_210 ( V_6 ,
V_45 -> V_9 ,
V_45 -> V_66 ) ;
}
}
}
void
F_256 ( struct V_5 * V_6 , int V_721 )
{
switch ( V_721 ) {
case V_722 :
F_114 ( V_6 , F_3 ( V_55 L_52
L_279 , V_6 -> V_35 , V_36 ) ) ;
break;
case V_723 :
F_114 ( V_6 , F_3 ( V_55 L_52
L_280 , V_6 -> V_35 , V_36 ) ) ;
if ( V_6 -> V_611 . V_291 & V_296 ) {
V_6 -> V_611 . V_291 |= V_327 ;
F_155 ( V_6 , V_6 -> V_611 . V_84 ) ;
F_103 ( & V_6 -> V_611 . V_297 ) ;
}
if ( V_6 -> V_290 . V_291 & V_296 ) {
V_6 -> V_290 . V_291 |= V_327 ;
F_155 ( V_6 , V_6 -> V_290 . V_84 ) ;
F_103 ( & V_6 -> V_290 . V_297 ) ;
}
F_135 ( V_6 ) ;
F_163 ( V_6 ) ;
F_134 ( V_6 ) ;
break;
case V_724 :
F_114 ( V_6 , F_3 ( V_55 L_52
L_281 , V_6 -> V_35 , V_36 ) ) ;
F_196 ( V_6 ) ;
F_247 ( V_6 ) ;
F_249 ( V_6 ) ;
F_251 ( V_6 ) ;
F_253 ( V_6 ) ;
break;
}
}
static void
V_350 ( struct V_725 * V_726 )
{
struct V_344 * V_345 = F_257 ( V_726 ,
struct V_344 , V_349 . V_726 ) ;
unsigned long V_62 ;
struct V_5 * V_6 = V_345 -> V_6 ;
if ( V_6 -> V_310 || V_345 -> V_355 ||
V_6 -> V_311 ) {
F_133 ( V_6 , V_345 ) ;
return;
}
if ( V_345 -> V_353 == V_354 ) {
F_133 ( V_6 , V_345 ) ;
F_18 ( & V_6 -> V_727 , V_62 ) ;
if ( V_6 -> V_309 ) {
F_117 ( & V_6 -> V_728 ) ;
F_21 ( & V_6 -> V_727 ,
V_62 ) ;
F_258 ( & V_6 -> V_728 ) ;
} else
F_21 ( & V_6 -> V_727 ,
V_62 ) ;
F_254 ( V_6 ) ;
F_255 ( V_6 ) ;
return;
}
switch ( V_345 -> V_353 ) {
case V_549 :
F_185 ( V_6 , V_345 -> V_550 ) ;
break;
case V_395 :
F_221 ( V_6 , V_345 ) ;
break;
case V_559 :
F_223 ( V_6 ,
V_345 ) ;
break;
case V_729 :
F_227 ( V_6 ,
V_345 ) ;
break;
case V_730 :
F_226 ( V_6 ,
V_345 ) ;
break;
case V_731 :
F_225 ( V_6 ,
V_345 ) ;
break;
case V_732 :
F_242 ( V_6 , V_345 ) ;
break;
case V_733 :
F_243 ( V_6 , V_345 ) ;
break;
case V_734 :
F_244 ( V_6 , V_345 ) ;
break;
case V_735 :
F_246 ( V_6 , V_345 ) ;
break;
}
F_133 ( V_6 , V_345 ) ;
}
T_6
F_259 ( struct V_5 * V_6 , T_6 V_288 ,
T_10 V_289 )
{
struct V_344 * V_345 ;
T_31 * V_29 ;
T_4 V_353 ;
T_4 V_223 ;
if ( V_6 -> V_310 || V_6 -> V_311 )
return 1 ;
V_29 = F_102 ( V_6 , V_289 ) ;
V_353 = F_9 ( V_29 -> V_558 ) ;
switch ( V_353 ) {
case V_730 :
{
T_42 * V_736 =
( T_42 * )
V_29 -> V_556 ;
if ( V_736 -> V_737 !=
V_738 ||
V_6 -> V_671 )
return 1 ;
V_6 -> V_671 = 1 ;
break;
}
case V_395 :
F_156 ( V_6 ,
( T_22 * )
V_29 -> V_556 ) ;
break;
case V_732 :
F_159 ( V_6 ,
( T_25 * )
V_29 -> V_556 ) ;
break;
case V_733 :
F_162 ( V_6 ,
( T_27 * )
V_29 -> V_556 ) ;
break;
case V_739 :
{
T_46 * V_740 ;
T_10 * V_741 ;
if ( ! V_6 -> V_187 )
break;
V_740 = ( T_46 * )
V_29 -> V_556 ;
V_741 = ( T_10 * ) V_740 -> V_742 ;
if ( F_9 ( V_740 -> V_743 )
!= V_744 )
break;
switch ( F_74 ( * V_741 ) ) {
case V_745 :
F_3 ( V_95 L_282
L_283
L_284
L_285 , V_6 -> V_35 ) ;
break;
case V_746 :
F_3 ( V_95 L_282
L_286
L_287
L_288 , V_6 -> V_35 ) ;
break;
case V_747 :
F_3 ( V_34 L_289
L_290
L_291
L_292
L_288 , V_6 -> V_35 ) ;
break;
case V_748 :
F_3 ( V_34 L_289
L_293
L_294
L_295 ,
V_6 -> V_35 ) ;
break;
}
break;
}
case V_559 :
case V_735 :
case V_729 :
case V_731 :
case V_734 :
break;
default:
return 1 ;
}
V_345 = F_67 ( sizeof( struct V_344 ) , V_352 ) ;
if ( ! V_345 ) {
F_3 ( V_34 L_2 ,
V_6 -> V_35 , __FILE__ , __LINE__ , V_36 ) ;
return 1 ;
}
V_223 = F_9 ( V_29 -> V_560 ) * 4 ;
V_345 -> V_351 = F_67 ( V_223 , V_352 ) ;
if ( ! V_345 -> V_351 ) {
F_3 ( V_34 L_2 ,
V_6 -> V_35 , __FILE__ , __LINE__ , V_36 ) ;
F_20 ( V_345 ) ;
return 1 ;
}
memcpy ( V_345 -> V_351 , V_29 -> V_556 ,
V_223 ) ;
V_345 -> V_6 = V_6 ;
V_345 -> V_492 = V_29 -> V_492 ;
V_345 -> V_493 = V_29 -> V_493 ;
V_345 -> V_353 = V_353 ;
F_130 ( V_6 , V_345 ) ;
return 1 ;
}
static void
F_213 ( struct V_5 * V_6 ,
struct V_74 * V_75 )
{
struct V_357 * V_358 , * V_96 ;
F_137 (mpt2sas_port, next,
&sas_expander->sas_port_list, port_list) {
if ( V_6 -> V_309 )
return;
if ( V_358 -> V_360 . V_361 ==
V_362 )
F_219 ( V_6 ,
V_358 -> V_360 . V_9 ) ;
else if ( V_358 -> V_360 . V_361 ==
V_363 ||
V_358 -> V_360 . V_361 ==
V_364 )
F_212 ( V_6 ,
V_358 -> V_360 . V_9 ) ;
}
F_210 ( V_6 , V_75 -> V_9 ,
V_75 -> V_66 ) ;
F_3 ( V_55 L_296
L_9 , V_6 -> V_35 ,
V_75 -> V_27 , ( unsigned long long )
V_75 -> V_9 ) ;
F_20 ( V_75 -> V_271 ) ;
F_20 ( V_75 ) ;
}
static void
F_260 ( struct V_5 * V_6 )
{
T_47 * V_99 ;
T_48 * V_29 ;
T_4 V_84 ;
if ( ! V_6 -> V_749 )
return;
if ( F_42 ( & V_6 -> V_73 ) )
return;
F_108 ( & V_6 -> V_611 . V_306 ) ;
if ( V_6 -> V_611 . V_291 != V_292 ) {
F_3 ( V_34 L_297 ,
V_6 -> V_35 , V_36 ) ;
goto V_71;
}
V_6 -> V_611 . V_291 = V_296 ;
V_84 = F_153 ( V_6 , V_6 -> V_750 ) ;
if ( ! V_84 ) {
F_3 ( V_34 L_68 ,
V_6 -> V_35 , V_36 ) ;
V_6 -> V_611 . V_291 = V_292 ;
goto V_71;
}
V_99 = F_46 ( V_6 , V_84 ) ;
V_6 -> V_611 . V_84 = V_84 ;
memset ( V_99 , 0 , sizeof( T_47 ) ) ;
V_99 -> V_320 = V_751 ;
V_99 -> V_544 = V_752 ;
if ( ! V_6 -> V_268 )
F_3 ( V_55 L_298 , V_6 -> V_35 ) ;
F_117 ( & V_6 -> V_611 . V_297 ) ;
F_154 ( V_6 , V_84 ) ;
F_119 ( & V_6 -> V_611 . V_297 , 10 * V_326 ) ;
if ( ! ( V_6 -> V_611 . V_291 & V_293 ) ) {
F_3 ( V_34 L_71 ,
V_6 -> V_35 , V_36 ) ;
goto V_71;
}
if ( V_6 -> V_611 . V_291 & V_295 ) {
V_29 = V_6 -> V_611 . V_289 ;
if ( ! V_6 -> V_268 )
F_3 ( V_55 L_299
L_300 ,
V_6 -> V_35 , F_9 ( V_29 -> V_38 ) ,
F_74 ( V_29 -> V_328 ) ) ;
}
V_71:
V_6 -> V_611 . V_291 = V_292 ;
F_121 ( & V_6 -> V_611 . V_306 ) ;
}
static void
F_261 ( struct V_753 * V_553 )
{
struct V_137 * V_138 = F_262 ( V_553 ) ;
struct V_5 * V_6 = F_56 ( V_138 ) ;
struct V_754 * V_755 ;
unsigned long V_62 ;
V_6 -> V_310 = 1 ;
F_135 ( V_6 ) ;
F_18 ( & V_6 -> V_347 , V_62 ) ;
V_755 = V_6 -> V_346 ;
V_6 -> V_346 = NULL ;
F_21 ( & V_6 -> V_347 , V_62 ) ;
if ( V_755 )
F_263 ( V_755 ) ;
F_260 ( V_6 ) ;
F_264 ( V_6 ) ;
}
static void T_49
F_265 ( struct V_753 * V_553 )
{
struct V_137 * V_138 = F_262 ( V_553 ) ;
struct V_5 * V_6 = F_56 ( V_138 ) ;
struct V_357 * V_358 , * V_756 ;
struct V_46 * V_47 , * V_96 ;
struct V_143 * V_144 ;
struct V_754 * V_755 ;
unsigned long V_62 ;
V_6 -> V_310 = 1 ;
F_135 ( V_6 ) ;
F_18 ( & V_6 -> V_347 , V_62 ) ;
V_755 = V_6 -> V_346 ;
V_6 -> V_346 = NULL ;
F_21 ( & V_6 -> V_347 , V_62 ) ;
if ( V_755 )
F_263 ( V_755 ) ;
F_260 ( V_6 ) ;
F_137 (raid_device, next, &ioc->raid_device_list,
list) {
if ( V_47 -> V_165 ) {
V_144 =
V_47 -> V_165 -> V_146 ;
V_144 -> V_376 = 1 ;
F_235 ( & V_47 -> V_165 -> V_166 ) ;
}
F_3 ( V_55 L_243
L_187 , V_6 -> V_35 , V_47 -> V_27 ,
( unsigned long long ) V_47 -> V_49 ) ;
F_31 ( V_6 , V_47 ) ;
}
F_137 (mpt2sas_port, next_port,
&ioc->sas_hba.sas_port_list, port_list) {
if ( V_358 -> V_360 . V_361 ==
V_362 )
F_219 ( V_6 ,
V_358 -> V_360 . V_9 ) ;
else if ( V_358 -> V_360 . V_361 ==
V_363 ||
V_358 -> V_360 . V_361 ==
V_364 )
F_212 ( V_6 ,
V_358 -> V_360 . V_9 ) ;
}
if ( V_6 -> V_31 . V_32 ) {
F_20 ( V_6 -> V_31 . V_271 ) ;
V_6 -> V_31 . V_271 = NULL ;
V_6 -> V_31 . V_32 = 0 ;
}
F_266 ( V_138 ) ;
F_261 ( V_553 ) ;
F_19 ( & V_6 -> V_64 ) ;
F_267 ( V_138 ) ;
F_268 ( V_138 ) ;
}
static void
F_269 ( struct V_5 * V_6 )
{
T_6 V_43 ;
void * V_42 ;
struct V_44 * V_45 ;
struct V_46 * V_47 ;
T_4 V_27 ;
T_1 V_66 ;
T_1 V_9 ;
unsigned long V_62 ;
int V_20 ;
V_42 = NULL ;
if ( V_6 -> V_50 . V_42 ) {
V_42 = V_6 -> V_50 . V_42 ;
V_43 = V_6 -> V_50 . V_43 ;
} else if ( V_6 -> V_56 . V_42 ) {
V_42 = V_6 -> V_56 . V_42 ;
V_43 = V_6 -> V_56 . V_43 ;
} else if ( V_6 -> V_59 . V_42 ) {
V_42 = V_6 -> V_59 . V_42 ;
V_43 = V_6 -> V_59 . V_43 ;
}
if ( ! V_42 )
return;
if ( V_43 ) {
V_47 = V_42 ;
V_20 = F_233 ( V_6 -> V_138 , V_171 ,
V_47 -> V_68 , 0 ) ;
if ( V_20 )
F_31 ( V_6 , V_47 ) ;
} else {
V_45 = V_42 ;
V_27 = V_45 -> V_27 ;
V_66 = V_45 -> V_66 ;
V_9 = V_45 -> V_9 ;
F_18 ( & V_6 -> V_63 , V_62 ) ;
F_270 ( & V_45 -> V_64 , & V_6 -> V_65 ) ;
F_21 ( & V_6 -> V_63 , V_62 ) ;
if ( V_6 -> V_639 )
return;
if ( ! F_25 ( V_6 , V_45 -> V_27 ,
V_45 -> V_66 ) ) {
F_17 ( V_6 , V_45 ) ;
} else if ( ! V_45 -> V_165 ) {
F_210 ( V_6 , V_9 ,
V_66 ) ;
F_17 ( V_6 , V_45 ) ;
}
}
}
static void
F_271 ( struct V_5 * V_6 )
{
struct V_46 * V_47 , * V_757 ;
int V_20 ;
F_137 (raid_device, raid_next,
&ioc->raid_device_list, list) {
if ( V_47 -> V_165 )
continue;
V_20 = F_233 ( V_6 -> V_138 , V_171 ,
V_47 -> V_68 , 0 ) ;
if ( V_20 )
F_31 ( V_6 , V_47 ) ;
}
}
static void
F_272 ( struct V_5 * V_6 )
{
struct V_44 * V_45 , * V_96 ;
unsigned long V_62 ;
F_137 (sas_device, next, &ioc->sas_device_init_list,
list) {
F_18 ( & V_6 -> V_63 , V_62 ) ;
F_270 ( & V_45 -> V_64 , & V_6 -> V_65 ) ;
F_21 ( & V_6 -> V_63 , V_62 ) ;
if ( V_6 -> V_639 )
continue;
if ( ! F_25 ( V_6 , V_45 -> V_27 ,
V_45 -> V_66 ) ) {
F_17 ( V_6 , V_45 ) ;
} else if ( ! V_45 -> V_165 ) {
F_210 ( V_6 ,
V_45 -> V_9 ,
V_45 -> V_66 ) ;
F_17 ( V_6 , V_45 ) ;
}
}
}
static void
F_273 ( struct V_5 * V_6 )
{
T_4 V_758 =
F_9 ( V_6 -> V_759 . V_760 ) &
V_761 ;
if ( ! ( V_6 -> V_254 . V_762 & V_763 ) )
return;
F_269 ( V_6 ) ;
if ( V_6 -> V_749 ) {
if ( ( V_758 &
V_764 ) ) {
F_272 ( V_6 ) ;
F_271 ( V_6 ) ;
} else {
F_271 ( V_6 ) ;
F_272 ( V_6 ) ;
}
} else
F_272 ( V_6 ) ;
}
static int
F_274 ( struct V_753 * V_553 , const struct V_765 * V_68 )
{
struct V_5 * V_6 ;
struct V_137 * V_138 ;
V_138 = F_275 ( & V_766 ,
sizeof( struct V_5 ) ) ;
if ( ! V_138 )
return - V_767 ;
V_6 = F_56 ( V_138 ) ;
memset ( V_6 , 0 , sizeof( struct V_5 ) ) ;
F_146 ( & V_6 -> V_64 ) ;
F_24 ( & V_6 -> V_64 , & V_768 ) ;
V_6 -> V_138 = V_138 ;
V_6 -> V_68 = V_769 ++ ;
sprintf ( V_6 -> V_35 , L_301 , V_770 , V_6 -> V_68 ) ;
V_6 -> V_553 = V_553 ;
if ( V_68 -> V_42 == V_771 ) {
V_6 -> V_187 = 1 ;
V_6 -> V_268 = 1 ;
} else
V_6 -> V_242 = V_243 ;
V_6 -> V_476 = V_476 ;
V_6 -> V_319 = V_319 ;
V_6 -> V_772 = V_772 ;
V_6 -> V_773 = V_773 ;
V_6 -> V_774 = V_774 ;
V_6 -> V_750 = V_750 ;
V_6 -> V_775 = V_775 ;
V_6 -> V_377 = V_377 ;
V_6 -> V_379 = V_379 ;
V_6 -> V_383 = V_383 ;
V_6 -> V_8 = V_8 ;
F_276 ( & V_6 -> V_776 ) ;
F_277 ( & V_6 -> V_727 ) ;
F_277 ( & V_6 -> V_87 ) ;
F_277 ( & V_6 -> V_63 ) ;
F_277 ( & V_6 -> V_76 ) ;
F_277 ( & V_6 -> V_347 ) ;
F_277 ( & V_6 -> V_72 ) ;
F_146 ( & V_6 -> V_65 ) ;
F_146 ( & V_6 -> V_67 ) ;
F_146 ( & V_6 -> V_77 ) ;
F_146 ( & V_6 -> V_348 ) ;
F_146 ( & V_6 -> V_73 ) ;
F_146 ( & V_6 -> V_31 . V_610 ) ;
F_146 ( & V_6 -> V_378 ) ;
F_146 ( & V_6 -> V_380 ) ;
V_138 -> V_777 = 32 ;
V_138 -> V_778 = V_778 ;
V_138 -> V_779 = V_780 ;
V_138 -> V_781 = V_6 -> V_68 ;
if ( ( F_278 ( V_138 , & V_553 -> V_166 ) ) ) {
F_3 ( V_34 L_2 ,
V_6 -> V_35 , __FILE__ , __LINE__ , V_36 ) ;
F_19 ( & V_6 -> V_64 ) ;
goto V_782;
}
F_279 ( V_138 , V_783
| V_784 | V_785 ) ;
F_280 ( V_138 , V_786 ) ;
snprintf ( V_6 -> V_787 , sizeof( V_6 -> V_787 ) ,
L_302 , V_6 -> V_68 ) ;
V_6 -> V_346 = F_281 (
V_6 -> V_787 ) ;
if ( ! V_6 -> V_346 ) {
F_3 ( V_34 L_2 ,
V_6 -> V_35 , __FILE__ , __LINE__ , V_36 ) ;
goto V_788;
}
V_6 -> V_48 = 1 ;
if ( ( F_282 ( V_6 ) ) ) {
F_3 ( V_34 L_2 ,
V_6 -> V_35 , __FILE__ , __LINE__ , V_36 ) ;
goto V_789;
}
V_6 -> V_48 = 0 ;
if ( V_6 -> V_187 ) {
if ( V_6 -> V_242 == V_243 )
V_6 -> V_639 = 0 ;
else if ( V_6 -> V_242 == V_790 )
V_6 -> V_639 = 1 ;
else {
if ( F_89 ( V_6 ) )
V_6 -> V_639 = 1 ;
else
V_6 -> V_639 = 0 ;
}
} else
V_6 -> V_639 = 0 ;
F_273 ( V_6 ) ;
return 0 ;
V_789:
F_263 ( V_6 -> V_346 ) ;
V_788:
F_19 ( & V_6 -> V_64 ) ;
F_267 ( V_138 ) ;
V_782:
return - V_767 ;
}
static int
F_283 ( struct V_753 * V_553 , T_50 V_197 )
{
struct V_137 * V_138 = F_262 ( V_553 ) ;
struct V_5 * V_6 = F_56 ( V_138 ) ;
T_10 V_791 ;
F_284 ( V_6 ) ;
F_285 ( V_138 ) ;
V_791 = F_286 ( V_553 , V_197 ) ;
F_3 ( V_55 L_303
L_304 , V_6 -> V_35 , V_553 ,
F_287 ( V_553 ) , V_791 ) ;
F_288 ( V_6 ) ;
F_289 ( V_553 ) ;
F_290 ( V_553 ) ;
F_291 ( V_553 , V_791 ) ;
return 0 ;
}
static int
F_292 ( struct V_753 * V_553 )
{
struct V_137 * V_138 = F_262 ( V_553 ) ;
struct V_5 * V_6 = F_56 ( V_138 ) ;
T_10 V_791 = V_553 -> V_792 ;
int V_70 ;
F_3 ( V_55 L_305
L_304 , V_6 -> V_35 , V_553 ,
F_287 ( V_553 ) , V_791 ) ;
F_291 ( V_553 , V_793 ) ;
F_293 ( V_553 , V_793 , 0 ) ;
F_294 ( V_553 ) ;
V_6 -> V_553 = V_553 ;
V_70 = F_295 ( V_6 ) ;
if ( V_70 )
return V_70 ;
F_111 ( V_6 , V_313 , V_794 ) ;
F_296 ( V_138 ) ;
F_297 ( V_6 ) ;
return 0 ;
}
static T_51
F_298 ( struct V_753 * V_553 , T_52 V_197 )
{
struct V_137 * V_138 = F_262 ( V_553 ) ;
struct V_5 * V_6 = F_56 ( V_138 ) ;
F_3 ( V_55 L_306 ,
V_6 -> V_35 , V_197 ) ;
switch ( V_197 ) {
case V_795 :
return V_796 ;
case V_797 :
V_6 -> V_311 = 1 ;
F_285 ( V_6 -> V_138 ) ;
F_284 ( V_6 ) ;
F_288 ( V_6 ) ;
return V_798 ;
case V_799 :
V_6 -> V_311 = 1 ;
F_284 ( V_6 ) ;
F_163 ( V_6 ) ;
return V_800 ;
}
return V_798 ;
}
static T_51
F_299 ( struct V_753 * V_553 )
{
struct V_137 * V_138 = F_262 ( V_553 ) ;
struct V_5 * V_6 = F_56 ( V_138 ) ;
int V_20 ;
F_3 ( V_55 L_307 ,
V_6 -> V_35 ) ;
V_6 -> V_311 = 0 ;
V_6 -> V_553 = V_553 ;
F_294 ( V_553 ) ;
V_20 = F_295 ( V_6 ) ;
if ( V_20 )
return V_800 ;
V_20 = F_111 ( V_6 , V_313 ,
V_314 ) ;
F_3 ( V_95 L_308 , V_6 -> V_35 ,
( V_20 == 0 ) ? L_114 : L_309 ) ;
if ( ! V_20 )
return V_801 ;
else
return V_800 ;
}
static void
F_300 ( struct V_753 * V_553 )
{
struct V_137 * V_138 = F_262 ( V_553 ) ;
struct V_5 * V_6 = F_56 ( V_138 ) ;
F_3 ( V_55 L_310 , V_6 -> V_35 ) ;
F_301 ( V_553 ) ;
F_297 ( V_6 ) ;
F_296 ( V_6 -> V_138 ) ;
}
static T_51
F_302 ( struct V_753 * V_553 )
{
struct V_137 * V_138 = F_262 ( V_553 ) ;
struct V_5 * V_6 = F_56 ( V_138 ) ;
F_3 ( V_55 L_311 ,
V_6 -> V_35 ) ;
return V_798 ;
}
static int T_53
F_303 ( void )
{
int error ;
V_769 = 0 ;
F_3 ( V_7 L_312 , V_770 ,
V_802 ) ;
V_780 =
F_304 ( & V_803 ) ;
if ( ! V_780 )
return - V_767 ;
V_194 = F_305 ( & V_804 ) ;
if ( ! V_194 ) {
F_306 ( V_780 ) ;
return - V_767 ;
}
F_307 () ;
V_476 = F_308 ( F_191 ) ;
V_319 = F_308 ( F_101 ) ;
V_773 = F_308 ( V_805 ) ;
V_774 = F_308 (
V_806 ) ;
V_750 = F_308 ( F_211 ) ;
V_775 = F_308 (
V_807 ) ;
V_772 = F_308 ( V_808 ) ;
V_377 = F_308 (
F_152 ) ;
V_379 = F_308 (
F_150 ) ;
V_383 = F_308 (
F_147 ) ;
F_309 () ;
error = F_310 ( & V_809 ) ;
if ( error ) {
F_311 ( V_194 ) ;
F_306 ( V_780 ) ;
}
return error ;
}
static void T_54
F_312 ( void )
{
F_3 ( V_7 L_313 ,
V_802 ) ;
F_313 ( & V_809 ) ;
F_314 () ;
F_315 ( V_476 ) ;
F_315 ( V_319 ) ;
F_315 ( V_773 ) ;
F_315 ( V_774 ) ;
F_315 ( V_750 ) ;
F_315 ( V_775 ) ;
F_315 ( V_772 ) ;
F_315 ( V_377 ) ;
F_315 ( V_379 ) ;
F_315 ( V_383 ) ;
F_311 ( V_194 ) ;
F_306 ( V_780 ) ;
}
