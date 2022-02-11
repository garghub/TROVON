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
( F_74 ( V_6 -> V_263 . V_265 ) &
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
unsigned long V_303 , enum V_304 V_305 )
{
T_20 * V_99 ;
T_21 * V_29 ;
T_4 V_84 = 0 ;
T_10 V_306 ;
unsigned long V_307 ;
struct V_308 * V_85 = NULL ;
int V_20 ;
if ( V_305 == V_309 )
F_108 ( & V_6 -> V_290 . V_310 ) ;
if ( V_6 -> V_290 . V_291 != V_292 ) {
F_3 ( V_55 L_64 ,
V_36 , V_6 -> V_35 ) ;
V_20 = V_311 ;
goto V_312;
}
if ( V_6 -> V_313 || V_6 -> V_314 ||
V_6 -> V_315 ) {
F_3 ( V_55 L_65 ,
V_36 , V_6 -> V_35 ) ;
V_20 = V_311 ;
goto V_312;
}
V_306 = F_109 ( V_6 , 0 ) ;
if ( V_306 & V_316 ) {
F_110 ( V_6 , F_3 ( V_55 L_66
L_67 , V_6 -> V_35 ) ) ;
V_20 = F_111 ( V_6 , V_317 ,
V_318 ) ;
V_20 = ( ! V_20 ) ? V_319 : V_311 ;
goto V_312;
}
if ( ( V_306 & V_320 ) == V_321 ) {
F_112 ( V_6 , V_306 &
V_322 ) ;
V_20 = F_111 ( V_6 , V_317 ,
V_318 ) ;
V_20 = ( ! V_20 ) ? V_319 : V_311 ;
goto V_312;
}
V_84 = F_113 ( V_6 , V_6 -> V_323 ) ;
if ( ! V_84 ) {
F_3 ( V_34 L_68 ,
V_6 -> V_35 , V_36 ) ;
V_20 = V_311 ;
goto V_312;
}
if ( type == V_324 )
V_85 = & V_6 -> V_85 [ V_301 - 1 ] ;
F_114 ( V_6 , F_3 ( V_55 L_69
L_70 , V_6 -> V_35 , V_27 , type ,
V_301 ) ) ;
V_6 -> V_290 . V_291 = V_296 ;
V_99 = F_46 ( V_6 , V_84 ) ;
V_6 -> V_290 . V_84 = V_84 ;
memset ( V_99 , 0 , sizeof( T_20 ) ) ;
memset ( V_6 -> V_290 . V_289 , 0 , sizeof( T_21 ) ) ;
V_99 -> V_325 = V_326 ;
V_99 -> V_230 = F_115 ( V_27 ) ;
V_99 -> V_327 = type ;
V_99 -> V_328 = F_115 ( V_301 ) ;
F_116 ( V_91 , (struct V_329 * ) V_99 -> V_330 ) ;
F_104 ( V_6 , V_27 ) ;
F_117 ( & V_6 -> V_290 . V_297 ) ;
F_118 ( V_6 , V_84 ) ;
V_307 = F_119 ( & V_6 -> V_290 . V_297 , V_302 * V_331 ) ;
if ( ! ( V_6 -> V_290 . V_291 & V_293 ) ) {
F_3 ( V_34 L_71 ,
V_6 -> V_35 , V_36 ) ;
F_120 ( V_99 ,
sizeof( T_20 ) / 4 ) ;
if ( ! ( V_6 -> V_290 . V_291 & V_332 ) ) {
V_20 = F_111 ( V_6 , V_317 ,
V_318 ) ;
V_20 = ( ! V_20 ) ? V_319 : V_311 ;
V_6 -> V_290 . V_291 = V_292 ;
F_106 ( V_6 , V_27 ) ;
goto V_312;
}
}
if ( V_6 -> V_290 . V_291 & V_295 ) {
V_29 = V_6 -> V_290 . V_289 ;
F_114 ( V_6 , F_3 ( V_55 L_72
L_73 ,
V_6 -> V_35 , F_9 ( V_29 -> V_38 ) ,
F_74 ( V_29 -> V_333 ) ,
F_74 ( V_29 -> V_334 ) ) ) ;
if ( V_6 -> V_8 & V_335 ) {
F_100 ( V_6 , V_29 -> V_336 ) ;
if ( V_29 -> V_38 )
F_120 ( V_99 ,
sizeof( T_20 ) / 4 ) ;
}
}
switch ( type ) {
case V_324 :
V_20 = V_319 ;
if ( V_85 -> V_86 == NULL )
break;
V_20 = V_311 ;
break;
case V_337 :
if ( F_39 ( V_6 , V_68 , V_69 ) )
V_20 = V_311 ;
else
V_20 = V_319 ;
break;
case V_338 :
case V_339 :
if ( F_40 ( V_6 , V_68 , V_91 , V_69 ) )
V_20 = V_311 ;
else
V_20 = V_319 ;
break;
case V_340 :
V_20 = V_319 ;
break;
default:
V_20 = V_311 ;
break;
}
F_106 ( V_6 , V_27 ) ;
V_6 -> V_290 . V_291 = V_292 ;
if ( V_305 == V_309 )
F_121 ( & V_6 -> V_290 . V_310 ) ;
return V_20 ;
V_312:
if ( V_305 == V_309 )
F_121 ( & V_6 -> V_290 . V_310 ) ;
return V_20 ;
}
static void
F_122 ( struct V_5 * V_6 , struct V_83 * V_86 )
{
struct V_164 * V_165 = V_86 -> V_42 -> V_341 ;
struct V_143 * V_342 = V_165 -> V_146 ;
struct V_44 * V_45 = NULL ;
unsigned long V_62 ;
char * V_343 = NULL ;
if ( ! V_342 )
return;
if ( V_6 -> V_268 )
V_343 = L_74 ;
else
V_343 = L_75 ;
F_123 ( V_86 ) ;
if ( V_342 -> V_62 & V_149 ) {
F_124 ( V_7 , V_165 , L_76
L_77 , V_343 , V_342 -> V_27 ,
V_343 , ( unsigned long long ) V_342 -> V_9 ) ;
} else {
F_18 ( & V_6 -> V_63 , V_62 ) ;
V_45 = F_15 ( V_6 ,
V_342 -> V_9 ) ;
if ( V_45 ) {
if ( V_342 -> V_62 &
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
V_86 -> V_344 = V_345 << 16 ;
V_86 -> V_346 ( V_86 ) ;
V_70 = V_319 ;
goto V_71;
}
V_84 = F_38 ( V_6 , V_86 ) ;
if ( ! V_84 ) {
V_86 -> V_344 = V_347 << 16 ;
V_70 = V_319 ;
goto V_71;
}
if ( V_142 -> V_148 -> V_62 &
V_175 ||
V_142 -> V_148 -> V_62 & V_149 ) {
V_86 -> V_344 = V_347 << 16 ;
V_70 = V_311 ;
goto V_71;
}
F_126 ( V_6 ) ;
V_27 = V_142 -> V_148 -> V_27 ;
V_70 = F_107 ( V_6 , V_27 , V_86 -> V_42 -> V_69 ,
V_86 -> V_42 -> V_68 , V_86 -> V_42 -> V_91 ,
V_324 , V_84 , 30 ,
V_86 -> V_303 , V_309 ) ;
V_71:
F_49 ( V_7 , V_86 -> V_42 , L_84 ,
( ( V_70 == V_319 ) ? L_85 : L_86 ) , V_86 ) ;
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
struct V_164 * V_165 = V_86 -> V_42 -> V_341 ;
F_124 ( V_7 , V_165 , L_87
L_82 , V_86 ) ;
F_122 ( V_6 , V_86 ) ;
V_142 = V_86 -> V_42 -> V_146 ;
if ( ! V_142 || ! V_142 -> V_148 ) {
F_124 ( V_7 , V_165 , L_83
L_82 , V_86 ) ;
V_86 -> V_344 = V_345 << 16 ;
V_86 -> V_346 ( V_86 ) ;
V_70 = V_319 ;
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
V_86 -> V_344 = V_347 << 16 ;
V_70 = V_311 ;
goto V_71;
}
V_70 = F_107 ( V_6 , V_27 , V_86 -> V_42 -> V_69 ,
V_86 -> V_42 -> V_68 , V_86 -> V_42 -> V_91 ,
V_339 , 0 , 30 , 0 ,
V_309 ) ;
V_71:
F_49 ( V_7 , V_86 -> V_42 , L_88 ,
( ( V_70 == V_319 ) ? L_85 : L_86 ) , V_86 ) ;
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
struct V_164 * V_165 = V_86 -> V_42 -> V_341 ;
F_124 ( V_7 , V_165 , L_89
L_82 , V_86 ) ;
F_122 ( V_6 , V_86 ) ;
V_142 = V_86 -> V_42 -> V_146 ;
if ( ! V_142 || ! V_142 -> V_148 ) {
F_124 ( V_7 , V_165 , L_90
L_82 , V_86 ) ;
V_86 -> V_344 = V_345 << 16 ;
V_86 -> V_346 ( V_86 ) ;
V_70 = V_319 ;
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
V_86 -> V_344 = V_347 << 16 ;
V_70 = V_311 ;
goto V_71;
}
V_70 = F_107 ( V_6 , V_27 , V_86 -> V_42 -> V_69 ,
V_86 -> V_42 -> V_68 , 0 , V_337 , 0 ,
30 , 0 , V_309 ) ;
V_71:
F_124 ( V_7 , V_165 , L_91 ,
( ( V_70 == V_319 ) ? L_85 : L_86 ) , V_86 ) ;
return V_70 ;
}
static int
F_129 ( struct V_83 * V_86 )
{
struct V_5 * V_6 = F_56 ( V_86 -> V_42 -> V_139 ) ;
int V_70 , V_348 ;
F_3 ( V_55 L_92 ,
V_6 -> V_35 , V_86 ) ;
F_123 ( V_86 ) ;
V_348 = F_111 ( V_6 , V_317 ,
V_318 ) ;
V_70 = ( V_348 < 0 ) ? V_311 : V_319 ;
F_3 ( V_55 L_93 ,
V_6 -> V_35 , ( ( V_70 == V_319 ) ? L_85 : L_86 ) , V_86 ) ;
return V_70 ;
}
static void
F_130 ( struct V_5 * V_6 , struct V_349 * V_350 )
{
unsigned long V_62 ;
if ( V_6 -> V_351 == NULL )
return;
F_18 ( & V_6 -> V_352 , V_62 ) ;
F_24 ( & V_350 -> V_64 , & V_6 -> V_353 ) ;
F_131 ( & V_350 -> V_354 , V_355 ) ;
F_132 ( V_6 -> V_351 ,
& V_350 -> V_354 , 0 ) ;
F_21 ( & V_6 -> V_352 , V_62 ) ;
}
static void
F_133 ( struct V_5 * V_6 , struct V_349
* V_350 )
{
unsigned long V_62 ;
F_18 ( & V_6 -> V_352 , V_62 ) ;
F_19 ( & V_350 -> V_64 ) ;
F_20 ( V_350 -> V_356 ) ;
F_20 ( V_350 ) ;
F_21 ( & V_6 -> V_352 , V_62 ) ;
}
static void
F_134 ( struct V_5 * V_6 )
{
struct V_349 * V_350 ;
if ( V_6 -> V_48 )
return;
V_350 = F_67 ( sizeof( struct V_349 ) , V_357 ) ;
if ( ! V_350 )
return;
V_350 -> V_358 = V_359 ;
V_350 -> V_6 = V_6 ;
F_130 ( V_6 , V_350 ) ;
}
static void
F_135 ( struct V_5 * V_6 )
{
struct V_349 * V_350 , * V_96 ;
if ( F_42 ( & V_6 -> V_353 ) ||
! V_6 -> V_351 || F_136 () )
return;
F_137 (fw_event, next, &ioc->fw_event_list, list) {
if ( F_138 ( & V_350 -> V_354 ) ) {
F_133 ( V_6 , V_350 ) ;
continue;
}
V_350 -> V_360 = 1 ;
}
}
static void
F_139 ( struct V_5 * V_6 )
{
struct V_141 * V_142 ;
struct V_134 * V_135 ;
F_105 (sdev, ioc->shost) {
V_142 = V_135 -> V_146 ;
if ( ! V_142 )
continue;
if ( ! V_142 -> V_361 )
continue;
V_142 -> V_361 = 0 ;
F_23 ( V_6 , F_49 ( V_7 , V_135 , L_94
L_95 ,
V_142 -> V_148 -> V_27 ) ) ;
F_140 ( V_135 ) ;
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
if ( ! V_142 -> V_361 )
continue;
if ( V_142 -> V_148 -> V_27 == V_27 ) {
F_23 ( V_6 , F_49 ( V_7 , V_135 ,
V_55 L_96
L_95 , V_6 -> V_35 , V_27 ) ) ;
V_142 -> V_361 = 0 ;
F_140 ( V_135 ) ;
}
}
}
static void
F_142 ( struct V_5 * V_6 )
{
struct V_141 * V_142 ;
struct V_134 * V_135 ;
F_105 (sdev, ioc->shost) {
V_142 = V_135 -> V_146 ;
if ( ! V_142 )
continue;
if ( V_142 -> V_361 )
continue;
V_142 -> V_361 = 1 ;
F_23 ( V_6 , F_49 ( V_7 , V_135 , L_97
L_95 ,
V_142 -> V_148 -> V_27 ) ) ;
F_143 ( V_135 ) ;
}
}
static void
F_144 ( struct V_5 * V_6 , T_4 V_27 )
{
struct V_141 * V_142 ;
struct V_134 * V_135 ;
F_105 (sdev, ioc->shost) {
V_142 = V_135 -> V_146 ;
if ( ! V_142 )
continue;
if ( V_142 -> V_361 )
continue;
if ( V_142 -> V_148 -> V_27 == V_27 ) {
F_23 ( V_6 , F_49 ( V_7 , V_135 ,
V_55 L_98
L_95 , V_6 -> V_35 , V_27 ) ) ;
V_142 -> V_361 = 1 ;
F_143 ( V_135 ) ;
}
}
}
static void
F_145 ( struct V_5 * V_6 ,
struct V_74 * V_75 )
{
struct V_362 * V_363 ;
struct V_44 * V_45 ;
struct V_74 * V_364 ;
unsigned long V_62 ;
if ( ! V_75 )
return;
F_4 (mpt2sas_port,
&sas_expander->sas_port_list, port_list) {
if ( V_363 -> V_365 . V_366 ==
V_367 ) {
F_18 ( & V_6 -> V_63 , V_62 ) ;
V_45 =
F_15 ( V_6 ,
V_363 -> V_365 . V_9 ) ;
F_21 ( & V_6 -> V_63 , V_62 ) ;
if ( ! V_45 )
continue;
F_144 ( V_6 , V_45 -> V_27 ) ;
}
}
F_4 (mpt2sas_port,
&sas_expander->sas_port_list, port_list) {
if ( V_363 -> V_365 . V_366 ==
V_368 ||
V_363 -> V_365 . V_366 ==
V_369 ) {
F_18 ( & V_6 -> V_76 , V_62 ) ;
V_364 =
F_33 (
V_6 , V_363 -> V_365 . V_9 ) ;
F_21 ( & V_6 -> V_76 , V_62 ) ;
F_145 ( V_6 ,
V_364 ) ;
}
}
}
static void
F_146 ( struct V_5 * V_6 ,
T_22 * V_356 )
{
int V_88 ;
T_4 V_27 ;
T_4 V_370 ;
T_6 V_371 ;
for ( V_88 = 0 ; V_88 < V_356 -> V_372 ; V_88 ++ ) {
V_27 = F_9 ( V_356 -> V_373 [ V_88 ] . V_374 ) ;
if ( ! V_27 )
continue;
V_371 = V_356 -> V_375 + V_88 ;
V_370 = V_356 -> V_373 [ V_88 ] . V_376 &
V_377 ;
if ( V_370 == V_378 )
F_144 ( V_6 , V_27 ) ;
}
}
static void
F_147 ( struct V_5 * V_6 , T_4 V_27 )
{
T_20 * V_99 ;
T_4 V_84 ;
struct V_44 * V_45 ;
struct V_143 * V_144 ;
unsigned long V_62 ;
struct V_379 * V_380 ;
if ( V_6 -> V_313 || V_6 -> V_314 ||
V_6 -> V_315 ) {
F_23 ( V_6 , F_3 ( V_55 L_99
L_100 , V_36 , V_6 -> V_35 ) ) ;
return;
}
if ( F_69 ( V_27 , V_6 -> V_174 ) )
return;
F_18 ( & V_6 -> V_63 , V_62 ) ;
V_45 = F_16 ( V_6 , V_27 ) ;
if ( V_45 && V_45 -> V_165 &&
V_45 -> V_165 -> V_146 ) {
V_144 = V_45 -> V_165 -> V_146 ;
V_144 -> V_381 = 1 ;
F_23 ( V_6 , F_3 ( V_55
L_101
L_102 , V_6 -> V_35 , V_27 ,
( unsigned long long ) V_45 -> V_9 ) ) ;
}
F_21 ( & V_6 -> V_63 , V_62 ) ;
V_84 = F_113 ( V_6 , V_6 -> V_382 ) ;
if ( ! V_84 ) {
V_380 = F_67 ( sizeof( * V_380 ) , V_357 ) ;
if ( ! V_380 )
return;
F_148 ( & V_380 -> V_64 ) ;
V_380 -> V_27 = V_27 ;
F_24 ( & V_380 -> V_64 , & V_6 -> V_383 ) ;
F_23 ( V_6 , F_3 ( V_55
L_103 ,
V_6 -> V_35 , V_27 ) ) ;
return;
}
F_23 ( V_6 , F_3 ( V_55 L_104
L_105 , V_6 -> V_35 , V_27 , V_84 ,
V_6 -> V_382 ) ) ;
V_99 = F_46 ( V_6 , V_84 ) ;
memset ( V_99 , 0 , sizeof( T_20 ) ) ;
V_99 -> V_325 = V_326 ;
V_99 -> V_230 = F_115 ( V_27 ) ;
V_99 -> V_327 = V_337 ;
F_118 ( V_6 , V_84 ) ;
}
static T_6
F_149 ( struct V_5 * V_6 , T_4 V_84 ,
T_6 V_288 , T_10 V_289 )
{
#ifdef F_150
T_23 * V_29 =
F_102 ( V_6 , V_289 ) ;
#endif
F_23 ( V_6 , F_3 ( V_55
L_106
L_107 ,
V_6 -> V_35 , F_9 ( V_29 -> V_230 ) , V_84 ,
F_9 ( V_29 -> V_38 ) ,
F_74 ( V_29 -> V_333 ) ) ) ;
return 1 ;
}
static void
F_151 ( struct V_5 * V_6 , T_4 V_27 )
{
T_20 * V_99 ;
T_4 V_84 ;
struct V_379 * V_380 ;
if ( V_6 -> V_313 || V_6 -> V_314 ||
V_6 -> V_315 ) {
F_23 ( V_6 , F_3 ( V_55 L_99
L_100 , V_36 , V_6 -> V_35 ) ) ;
return;
}
V_84 = F_113 ( V_6 , V_6 -> V_384 ) ;
if ( ! V_84 ) {
V_380 = F_67 ( sizeof( * V_380 ) , V_357 ) ;
if ( ! V_380 )
return;
F_148 ( & V_380 -> V_64 ) ;
V_380 -> V_27 = V_27 ;
F_24 ( & V_380 -> V_64 , & V_6 -> V_385 ) ;
F_23 ( V_6 , F_3 ( V_55
L_103 ,
V_6 -> V_35 , V_27 ) ) ;
return;
}
F_23 ( V_6 , F_3 ( V_55 L_104
L_105 , V_6 -> V_35 , V_27 , V_84 ,
V_6 -> V_384 ) ) ;
V_99 = F_46 ( V_6 , V_84 ) ;
memset ( V_99 , 0 , sizeof( T_20 ) ) ;
V_99 -> V_325 = V_326 ;
V_99 -> V_230 = F_115 ( V_27 ) ;
V_99 -> V_327 = V_337 ;
F_118 ( V_6 , V_84 ) ;
}
static T_6
F_152 ( struct V_5 * V_6 , T_4 V_84 ,
T_6 V_288 , T_10 V_289 )
{
T_4 V_27 ;
T_20 * V_386 ;
T_21 * V_29 =
F_102 ( V_6 , V_289 ) ;
if ( V_6 -> V_313 || V_6 -> V_314 ||
V_6 -> V_315 ) {
F_23 ( V_6 , F_3 ( V_55 L_99
L_100 , V_36 , V_6 -> V_35 ) ) ;
return 1 ;
}
V_386 = F_46 ( V_6 , V_84 ) ;
V_27 = F_9 ( V_386 -> V_230 ) ;
if ( V_27 != F_9 ( V_29 -> V_230 ) ) {
F_23 ( V_6 , F_3 ( L_108
L_109 , V_27 ,
F_9 ( V_29 -> V_230 ) , V_84 ) ) ;
return 0 ;
}
F_23 ( V_6 , F_3 ( V_55
L_110
L_111 , V_6 -> V_35 ,
V_27 , V_84 , F_9 ( V_29 -> V_38 ) ,
F_74 ( V_29 -> V_333 ) ,
F_74 ( V_29 -> V_334 ) ) ) ;
return F_153 ( V_6 , V_84 ) ;
}
static T_6
F_154 ( struct V_5 * V_6 , T_4 V_84 , T_6 V_288 ,
T_10 V_289 )
{
T_4 V_27 ;
T_20 * V_386 ;
T_21 * V_29 =
F_102 ( V_6 , V_289 ) ;
T_24 * V_99 ;
T_4 V_387 ;
if ( V_6 -> V_313 || V_6 -> V_314 ||
V_6 -> V_315 ) {
F_23 ( V_6 , F_3 ( V_55 L_99
L_100 , V_36 , V_6 -> V_35 ) ) ;
return 1 ;
}
V_386 = F_46 ( V_6 , V_84 ) ;
V_27 = F_9 ( V_386 -> V_230 ) ;
if ( V_27 != F_9 ( V_29 -> V_230 ) ) {
F_23 ( V_6 , F_3 ( V_55 L_108
L_109 , V_6 -> V_35 , V_27 ,
F_9 ( V_29 -> V_230 ) , V_84 ) ) ;
return 0 ;
}
F_23 ( V_6 , F_3 ( V_55
L_110
L_111 , V_6 -> V_35 ,
V_27 , V_84 , F_9 ( V_29 -> V_38 ) ,
F_74 ( V_29 -> V_333 ) ,
F_74 ( V_29 -> V_334 ) ) ) ;
V_387 = F_155 ( V_6 , V_6 -> V_388 ) ;
if ( ! V_387 ) {
F_3 ( V_34 L_68 ,
V_6 -> V_35 , V_36 ) ;
return 1 ;
}
F_23 ( V_6 , F_3 ( V_55 L_112
L_105 , V_6 -> V_35 , V_27 , V_387 ,
V_6 -> V_388 ) ) ;
V_99 = F_46 ( V_6 , V_387 ) ;
memset ( V_99 , 0 , sizeof( T_24 ) ) ;
V_99 -> V_325 = V_389 ;
V_99 -> V_390 = V_391 ;
V_99 -> V_230 = V_386 -> V_230 ;
F_156 ( V_6 , V_387 ) ;
return F_153 ( V_6 , V_84 ) ;
}
static T_6
F_153 ( struct V_5 * V_6 , T_4 V_84 )
{
struct V_379 * V_380 ;
if ( ! F_42 ( & V_6 -> V_385 ) ) {
V_380 = F_43 ( V_6 -> V_385 . V_96 ,
struct V_379 , V_64 ) ;
F_157 ( V_6 , V_84 ) ;
F_151 ( V_6 , V_380 -> V_27 ) ;
F_19 ( & V_380 -> V_64 ) ;
F_20 ( V_380 ) ;
return 0 ;
}
if ( ! F_42 ( & V_6 -> V_383 ) ) {
V_380 = F_43 ( V_6 -> V_383 . V_96 ,
struct V_379 , V_64 ) ;
F_157 ( V_6 , V_84 ) ;
F_147 ( V_6 , V_380 -> V_27 ) ;
F_19 ( & V_380 -> V_64 ) ;
F_20 ( V_380 ) ;
return 0 ;
}
return 1 ;
}
static void
F_158 ( struct V_5 * V_6 ,
T_22 * V_356 )
{
struct V_349 * V_350 ;
T_22 * V_392 ;
T_4 V_393 ;
struct V_74 * V_75 ;
unsigned long V_62 ;
int V_88 , V_370 ;
T_4 V_27 ;
for ( V_88 = 0 ; V_88 < V_356 -> V_372 ; V_88 ++ ) {
V_27 = F_9 ( V_356 -> V_373 [ V_88 ] . V_374 ) ;
if ( ! V_27 )
continue;
V_370 = V_356 -> V_373 [ V_88 ] . V_376 &
V_377 ;
if ( V_370 == V_394 )
F_147 ( V_6 , V_27 ) ;
}
V_393 = F_9 ( V_356 -> V_395 ) ;
if ( V_393 < V_6 -> V_31 . V_32 ) {
F_146 ( V_6 , V_356 ) ;
return;
}
if ( V_356 -> V_396 == V_397
|| V_356 -> V_396 == V_398 ) {
F_18 ( & V_6 -> V_76 , V_62 ) ;
V_75 = F_32 ( V_6 ,
V_393 ) ;
F_21 ( & V_6 -> V_76 , V_62 ) ;
F_145 ( V_6 , V_75 ) ;
} else if ( V_356 -> V_396 == V_399 )
F_146 ( V_6 , V_356 ) ;
if ( V_356 -> V_396 != V_398 )
return;
F_18 ( & V_6 -> V_352 , V_62 ) ;
F_4 (fw_event, &ioc->fw_event_list, list) {
if ( V_350 -> V_358 != V_400 ||
V_350 -> V_401 )
continue;
V_392 = V_350 -> V_356 ;
if ( V_392 -> V_396 ==
V_402 ||
V_392 -> V_396 ==
V_399 ) {
if ( F_9 ( V_392 -> V_395 ) ==
V_393 ) {
F_23 ( V_6 , F_3 ( V_55
L_113 , V_6 -> V_35 ) ) ;
V_350 -> V_401 = 1 ;
}
}
}
F_21 ( & V_6 -> V_352 , V_62 ) ;
}
static void
F_159 ( struct V_5 * V_6 , T_4 V_27 )
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
V_144 -> V_381 = 1 ;
F_23 ( V_6 , F_3 ( V_55
L_101
L_114 , V_6 -> V_35 , V_27 ,
( unsigned long long ) V_47 -> V_49 ) ) ;
}
F_21 ( & V_6 -> V_72 , V_62 ) ;
}
static void
F_160 ( T_4 V_27 , T_4 * V_403 , T_4 * V_404 )
{
if ( ! V_27 || V_27 == * V_403 || V_27 == * V_404 )
return;
if ( ! * V_403 )
* V_403 = V_27 ;
else if ( ! * V_404 )
* V_404 = V_27 ;
}
static void
F_161 ( struct V_5 * V_6 ,
T_25 * V_356 )
{
T_26 * V_405 ;
int V_88 ;
T_4 V_27 , V_269 , V_403 , V_404 ;
struct V_379 * V_380 ;
V_403 = 0 ;
V_404 = 0 ;
if ( V_6 -> V_187 )
return;
V_405 = ( T_26 * ) & V_356 -> V_406 [ 0 ] ;
for ( V_88 = 0 ; V_88 < V_356 -> V_407 ; V_88 ++ , V_405 ++ ) {
if ( V_405 -> V_408 ==
V_409 ||
V_405 -> V_408 ==
V_410 ) {
V_269 = F_9 ( V_405 -> V_411 ) ;
F_159 ( V_6 , V_269 ) ;
F_160 ( V_269 , & V_403 , & V_404 ) ;
}
}
V_405 = ( T_26 * ) & V_356 -> V_406 [ 0 ] ;
for ( V_88 = 0 ; V_88 < V_356 -> V_407 ; V_88 ++ , V_405 ++ ) {
if ( F_74 ( V_356 -> V_179 ) &
V_412 )
continue;
if ( V_405 -> V_408 == V_413 ) {
V_269 = F_9 ( V_405 -> V_411 ) ;
F_160 ( V_269 , & V_403 , & V_404 ) ;
}
}
if ( V_403 )
F_151 ( V_6 , V_403 ) ;
if ( V_404 )
F_151 ( V_6 , V_404 ) ;
V_405 = ( T_26 * ) & V_356 -> V_406 [ 0 ] ;
for ( V_88 = 0 ; V_88 < V_356 -> V_407 ; V_88 ++ , V_405 ++ ) {
if ( V_405 -> V_408 != V_413 )
continue;
V_27 = F_9 ( V_405 -> V_414 ) ;
V_269 = F_9 ( V_405 -> V_411 ) ;
F_162 ( V_27 , V_6 -> V_174 ) ;
if ( ! V_269 )
F_147 ( V_6 , V_27 ) ;
else if ( V_269 == V_403 || V_269 == V_404 ) {
V_380 = F_67 ( sizeof( * V_380 ) , V_357 ) ;
F_163 ( ! V_380 ) ;
F_148 ( & V_380 -> V_64 ) ;
V_380 -> V_27 = V_27 ;
F_24 ( & V_380 -> V_64 , & V_6 -> V_383 ) ;
F_23 ( V_6 , F_3 ( V_55
L_103 , V_6 -> V_35 ,
V_27 ) ) ;
} else
F_147 ( V_6 , V_27 ) ;
}
}
static void
F_164 ( struct V_5 * V_6 ,
T_27 * V_356 )
{
T_10 V_197 ;
if ( V_356 -> V_408 != V_415 )
return;
V_197 = F_74 ( V_356 -> V_416 ) ;
if ( V_197 == V_207 || V_197 ==
V_206 )
F_159 ( V_6 ,
F_9 ( V_356 -> V_411 ) ) ;
}
static void
F_165 ( struct V_5 * V_6 )
{
struct V_83 * V_86 ;
T_4 V_84 ;
T_4 V_236 = 0 ;
for ( V_84 = 1 ; V_84 <= V_6 -> V_89 ; V_84 ++ ) {
V_86 = F_37 ( V_6 , V_84 ) ;
if ( ! V_86 )
continue;
V_236 ++ ;
F_157 ( V_6 , V_84 ) ;
F_166 ( V_86 ) ;
if ( V_6 -> V_315 )
V_86 -> V_344 = V_345 << 16 ;
else
V_86 -> V_344 = V_347 << 16 ;
V_86 -> V_346 ( V_86 ) ;
}
F_114 ( V_6 , F_3 ( V_55 L_115 ,
V_6 -> V_35 , V_236 ) ) ;
}
static void
F_167 ( struct V_83 * V_86 , T_11 * V_99 )
{
T_4 V_417 ;
unsigned char V_418 = F_168 ( V_86 ) ;
unsigned char V_419 = F_169 ( V_86 ) ;
if ( V_419 == V_420 || V_418 == V_421 )
return;
if ( V_418 == V_422 )
V_417 = V_423 ;
else if ( V_418 == V_424 )
V_417 = V_425 ;
else
return;
switch ( V_419 ) {
case V_426 :
case V_427 :
V_417 |= V_428 |
V_429 |
V_430 ;
V_99 -> V_431 . V_432 . V_433 =
F_170 ( F_171 ( V_86 ) ) ;
break;
case V_434 :
V_417 |= V_430 ;
break;
}
V_99 -> V_435 = F_172 ( V_86 -> V_42 -> V_436 ) ;
V_99 -> V_437 = F_115 ( V_417 ) ;
}
static void
F_173 ( struct V_83 * V_86 , T_4 V_30 )
{
T_6 V_438 ;
T_6 V_439 ;
T_6 V_440 ;
switch ( V_30 ) {
case V_441 :
V_438 = 0x01 ;
break;
case V_442 :
V_438 = 0x02 ;
break;
case V_443 :
V_438 = 0x03 ;
break;
default:
V_438 = 0x00 ;
break;
}
if ( V_86 -> V_114 == V_115 ) {
V_439 = V_444 ;
V_440 = V_445 ;
} else {
V_439 = V_446 ;
V_440 = V_447 ;
}
F_174 ( 0 , V_86 -> V_448 , V_439 , 0x10 , V_438 ) ;
V_86 -> V_344 = V_449 << 24 | ( V_440 << 16 ) |
V_450 ;
}
static inline T_6
F_175 ( struct V_5 * V_6 , T_4 V_84 )
{
return V_6 -> V_85 [ V_84 - 1 ] . V_451 ;
}
static inline void
F_176 ( struct V_5 * V_6 , T_4 V_84 , T_6 V_451 )
{
V_6 -> V_85 [ V_84 - 1 ] . V_451 = V_451 ;
}
static void
F_177 ( struct V_5 * V_6 , struct V_83 * V_86 ,
struct V_46 * V_47 , T_11 * V_99 ,
T_4 V_84 )
{
T_10 V_452 , V_453 , V_454 , V_455 , V_456 , V_457 ;
T_10 V_240 , V_241 ;
T_6 V_224 , * V_458 , * V_459 , * V_460 , * V_461 ;
T_6 V_462 = V_86 -> V_463 [ 0 ] ;
if ( V_462 == V_464 || V_462 == V_465 ||
V_462 == V_466 || V_462 == V_467 ) {
V_458 = V_99 -> V_431 . V_468 ;
if ( ( V_462 < V_464 ) || ! ( V_458 [ 2 ] | V_458 [ 3 ] | V_458 [ 4 ]
| V_458 [ 5 ] ) ) {
V_457 = F_50 ( V_86 ) >> 9 ;
V_460 = V_461 = ( V_462 < V_464 ) ? & V_458 [ 2 ] :
& V_458 [ 6 ] ;
V_459 = ( T_6 * ) & V_452 + 3 ;
* V_459 -- = * V_460 ++ ;
* V_459 -- = * V_460 ++ ;
* V_459 -- = * V_460 ++ ;
* V_459 = * V_460 ;
if ( ( ( T_1 ) V_452 + ( T_1 ) V_457 - 1 ) <=
( T_10 ) V_47 -> V_251 ) {
V_240 = V_47 -> V_240 ;
V_241 = V_47 -> V_250 ;
V_454 = V_452 & ( V_240 - 1 ) ;
if ( ( V_454 + V_457 ) <= V_240 ) {
V_224 = V_47 -> V_224 ;
V_453 = V_452 >> V_241 ;
V_455 = V_453 / V_224 ;
V_456 = V_453 % V_224 ;
V_453 = ( V_455 << V_241 ) +
V_454 ;
V_99 -> V_230 =
F_115 ( V_47 ->
V_246 [ V_456 ] ) ;
V_459 = ( T_6 * ) & V_453 + 3 ;
* V_461 ++ = * V_459 -- ;
* V_461 ++ = * V_459 -- ;
* V_461 ++ = * V_459 -- ;
* V_461 = * V_459 ;
F_176 ( V_6 , V_84 , 1 ) ;
}
}
}
}
}
static int
F_178 ( struct V_83 * V_86 , void (* V_297)( struct V_83 * ) )
{
struct V_5 * V_6 = F_56 ( V_86 -> V_42 -> V_139 ) ;
struct V_141 * V_142 ;
struct V_143 * V_144 ;
struct V_46 * V_47 ;
T_11 * V_99 ;
T_10 V_469 ;
T_4 V_84 ;
V_86 -> V_346 = V_297 ;
V_142 = V_86 -> V_42 -> V_146 ;
if ( ! V_142 || ! V_142 -> V_148 ) {
V_86 -> V_344 = V_345 << 16 ;
V_86 -> V_346 ( V_86 ) ;
return 0 ;
}
if ( V_6 -> V_315 || V_6 -> V_314 ) {
V_86 -> V_344 = V_345 << 16 ;
V_86 -> V_346 ( V_86 ) ;
return 0 ;
}
V_144 = V_142 -> V_148 ;
if ( V_144 -> V_27 == V_170 ) {
V_86 -> V_344 = V_345 << 16 ;
V_86 -> V_346 ( V_86 ) ;
return 0 ;
}
if ( V_6 -> V_313 || V_6 -> V_470 )
return V_471 ;
else if ( V_142 -> V_361 || V_144 -> V_299 )
return V_472 ;
else if ( V_144 -> V_381 ) {
V_86 -> V_344 = V_345 << 16 ;
V_86 -> V_346 ( V_86 ) ;
return 0 ;
}
if ( V_86 -> V_114 == V_473 )
V_469 = V_474 ;
else if ( V_86 -> V_114 == V_115 )
V_469 = V_475 ;
else
V_469 = V_476 ;
if ( ! ( V_142 -> V_62 & V_176 ) ) {
if ( V_86 -> V_42 -> V_151 ) {
if ( V_86 -> V_42 -> V_160 )
V_469 |= V_477 ;
else
V_469 |= V_478 ;
} else
V_469 |= ( 0x500 ) ;
} else
V_469 |= V_478 ;
if ( ! V_6 -> V_187 && ! F_75 ( & V_86 -> V_42 -> V_221 ) &&
F_93 ( V_86 -> V_42 ) && V_86 -> V_479 != 32 )
V_469 |= V_480 ;
V_84 = F_179 ( V_6 , V_6 -> V_481 , V_86 ) ;
if ( ! V_84 ) {
F_3 ( V_34 L_68 ,
V_6 -> V_35 , V_36 ) ;
goto V_71;
}
V_99 = F_46 ( V_6 , V_84 ) ;
memset ( V_99 , 0 , sizeof( T_11 ) ) ;
F_167 ( V_86 , V_99 ) ;
if ( V_86 -> V_479 == 32 )
V_469 |= 4 << V_482 ;
V_99 -> V_325 = V_483 ;
if ( V_142 -> V_148 -> V_62 &
V_175 )
V_99 -> V_325 = V_484 ;
else
V_99 -> V_325 = V_483 ;
V_99 -> V_230 =
F_115 ( V_142 -> V_148 -> V_27 ) ;
V_99 -> V_485 = F_172 ( F_50 ( V_86 ) ) ;
V_99 -> V_486 = F_172 ( V_469 ) ;
V_99 -> V_487 = F_115 ( V_86 -> V_479 ) ;
V_99 -> V_488 = V_489 ;
V_99 -> V_490 = V_491 ;
V_99 -> V_492 =
F_180 ( V_6 , V_84 ) ;
V_99 -> V_493 = F_51 ( T_11 , V_123 ) / 4 ;
V_99 -> V_494 = F_115 ( V_495 +
V_496 ) ;
V_99 -> V_497 = 0 ;
V_99 -> V_498 = 0 ;
F_116 ( V_142 -> V_91 , (struct V_329 * )
V_99 -> V_330 ) ;
memcpy ( V_99 -> V_431 . V_468 , V_86 -> V_463 , V_86 -> V_479 ) ;
if ( ! V_99 -> V_485 ) {
F_181 ( V_6 , & V_99 -> V_123 ) ;
} else {
if ( F_45 ( V_6 , V_86 , V_84 ) ) {
F_157 ( V_6 , V_84 ) ;
goto V_71;
}
}
V_47 = V_144 -> V_47 ;
if ( V_47 && V_47 -> V_234 )
F_177 ( V_6 , V_86 , V_47 , V_99 ,
V_84 ) ;
if ( F_182 ( V_99 -> V_325 == V_483 ) )
F_183 ( V_6 , V_84 ,
F_9 ( V_99 -> V_230 ) ) ;
else
F_156 ( V_6 , V_84 ) ;
return 0 ;
V_71:
return V_471 ;
}
void
F_184 ( struct V_5 * V_6 , struct V_83 * V_86 ,
T_28 * V_29 , T_4 V_84 )
{
T_10 V_499 ;
T_6 * V_500 ;
T_4 V_30 = F_9 ( V_29 -> V_38 ) &
V_39 ;
T_6 V_501 = V_29 -> V_502 ;
T_6 V_503 = V_29 -> V_504 ;
char * V_505 = NULL ;
char * V_506 = NULL ;
char * V_507 = V_6 -> V_508 ;
T_10 V_509 = F_74 ( V_29 -> V_333 ) ;
struct V_44 * V_45 = NULL ;
unsigned long V_62 ;
struct V_164 * V_165 = V_86 -> V_42 -> V_341 ;
struct V_143 * V_342 = V_165 -> V_146 ;
char * V_343 = NULL ;
if ( ! V_342 )
return;
if ( V_6 -> V_268 )
V_343 = L_74 ;
else
V_343 = L_75 ;
if ( V_509 == 0x31170000 )
return;
switch ( V_30 ) {
case V_40 :
V_505 = L_116 ;
break;
case V_510 :
V_505 = L_117 ;
break;
case V_511 :
V_505 = L_118 ;
break;
case V_512 :
V_505 = L_119 ;
break;
case V_513 :
V_505 = L_120 ;
break;
case V_514 :
V_505 = L_121 ;
break;
case V_515 :
V_505 = L_122 ;
break;
case V_516 :
V_505 = L_123 ;
break;
case V_517 :
V_505 = L_124 ;
break;
case V_518 :
V_505 = L_125 ;
break;
case V_519 :
V_505 = L_126 ;
break;
case V_520 :
V_505 = L_127 ;
break;
case V_521 :
V_505 = L_128 ;
break;
case V_522 :
V_505 = L_129 ;
break;
case V_441 :
V_505 = L_130 ;
break;
case V_443 :
V_505 = L_131 ;
break;
case V_442 :
V_505 = L_132 ;
break;
default:
V_505 = L_62 ;
break;
}
switch ( V_503 ) {
case V_523 :
V_506 = L_133 ;
break;
case V_524 :
V_506 = L_134 ;
break;
case V_525 :
V_506 = L_135 ;
break;
case V_526 :
V_506 = L_136 ;
break;
case V_527 :
V_506 = L_137 ;
break;
case V_528 :
V_506 = L_138 ;
break;
case V_529 :
V_506 = L_139 ;
break;
case V_530 :
V_506 = L_140 ;
break;
case V_531 :
V_506 = L_141 ;
break;
case V_532 :
V_506 = L_142 ;
break;
case V_533 :
V_506 = L_143 ;
break;
default:
V_506 = L_62 ;
break;
}
V_507 [ 0 ] = '\0' ;
if ( ! V_501 )
V_507 = L_144 ;
if ( V_501 & V_534 )
strcat ( V_507 , L_145 ) ;
if ( V_501 & V_535 )
strcat ( V_507 , L_146 ) ;
if ( V_501 & V_536 )
strcat ( V_507 , L_147 ) ;
if ( V_501 & V_537 )
strcat ( V_507 , L_148 ) ;
if ( V_501 & V_538 )
strcat ( V_507 , L_149 ) ;
F_123 ( V_86 ) ;
if ( V_342 -> V_62 & V_149 ) {
F_3 ( V_95 L_150 , V_6 -> V_35 ,
V_343 , ( unsigned long long ) V_342 -> V_9 ) ;
} else {
F_18 ( & V_6 -> V_63 , V_62 ) ;
V_45 = F_15 ( V_6 ,
V_342 -> V_9 ) ;
if ( V_45 ) {
F_3 ( V_95 L_151
L_152 , V_6 -> V_35 , V_45 -> V_9 ,
V_45 -> V_271 ) ;
F_3 ( V_95
L_153 ,
V_6 -> V_35 , V_45 -> V_14 ,
V_45 -> V_18 ) ;
}
F_21 ( & V_6 -> V_63 , V_62 ) ;
}
F_3 ( V_95 L_154
L_155 , V_6 -> V_35 , F_9 ( V_29 -> V_230 ) ,
V_505 , V_30 , V_84 ) ;
F_3 ( V_95 L_156
L_157 , V_6 -> V_35 , F_50 ( V_86 ) , V_86 -> V_539 ,
F_185 ( V_86 ) ) ;
F_3 ( V_95 L_158
L_159 , V_6 -> V_35 , F_9 ( V_29 -> V_540 ) ,
F_74 ( V_29 -> V_541 ) , V_86 -> V_344 ) ;
F_3 ( V_95 L_160
L_161 , V_6 -> V_35 , V_506 ,
V_503 , V_507 , V_501 ) ;
if ( V_501 & V_538 ) {
struct V_542 V_543 ;
F_186 ( V_86 -> V_448 , & V_543 ) ;
F_3 ( V_95 L_162
L_163 , V_6 -> V_35 , V_543 . V_544 ,
V_543 . V_545 , V_543 . V_438 , F_74 ( V_29 -> V_546 ) ) ;
}
if ( V_501 & V_534 ) {
V_499 = F_74 ( V_29 -> V_547 ) ;
V_500 = ( T_6 * ) & V_499 ;
F_100 ( V_6 , V_500 [ 0 ] ) ;
}
}
static void
F_187 ( struct V_5 * V_6 , T_4 V_27 )
{
T_29 V_29 ;
T_30 V_99 ;
memset ( & V_99 , 0 , sizeof( T_30 ) ) ;
V_99 . V_325 = V_548 ;
V_99 . V_549 = V_550 ;
V_99 . V_551 =
F_172 ( V_552 ) ;
V_99 . V_230 = F_115 ( V_27 ) ;
V_99 . V_179 = V_553 ;
if ( ( F_188 ( V_6 , & V_29 ,
& V_99 ) ) != 0 ) {
F_3 ( V_34 L_2 , V_6 -> V_35 ,
__FILE__ , __LINE__ , V_36 ) ;
return;
}
if ( V_29 . V_38 || V_29 . V_333 ) {
F_23 ( V_6 , F_3 ( V_55 L_164
L_165 , V_6 -> V_35 ,
F_9 ( V_29 . V_38 ) ,
F_74 ( V_29 . V_333 ) ) ) ;
return;
}
}
static void
F_189 ( struct V_5 * V_6 , T_4 V_27 )
{
struct V_349 * V_350 ;
V_350 = F_67 ( sizeof( struct V_349 ) , V_357 ) ;
if ( ! V_350 )
return;
V_350 -> V_358 = V_554 ;
V_350 -> V_555 = V_27 ;
V_350 -> V_6 = V_6 ;
F_130 ( V_6 , V_350 ) ;
}
static void
F_190 ( struct V_5 * V_6 , T_4 V_27 )
{
struct V_164 * V_165 ;
struct V_143 * V_144 ;
T_31 * V_556 ;
T_32 * V_356 ;
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
F_124 ( V_557 , V_165 , L_166 ) ;
F_21 ( & V_6 -> V_63 , V_62 ) ;
if ( V_6 -> V_558 -> V_559 == V_560 )
F_189 ( V_6 , V_27 ) ;
V_223 = F_51 ( T_31 , V_561 ) +
sizeof( T_32 ) ;
V_556 = F_67 ( V_223 , V_169 ) ;
if ( ! V_556 ) {
F_3 ( V_34 L_2 ,
V_6 -> V_35 , __FILE__ , __LINE__ , V_36 ) ;
return;
}
V_556 -> V_325 = V_562 ;
V_556 -> V_563 =
F_115 ( V_564 ) ;
V_556 -> V_294 = V_223 / 4 ;
V_556 -> V_565 =
F_115 ( sizeof( T_32 ) / 4 ) ;
V_356 = ( T_32 * )
V_556 -> V_561 ;
V_356 -> V_408 = V_566 ;
V_356 -> V_567 = 0x5D ;
V_356 -> V_230 = F_115 ( V_27 ) ;
V_356 -> V_11 = F_191 ( V_144 -> V_9 ) ;
F_192 ( V_6 , V_556 ) ;
F_20 ( V_556 ) ;
}
static T_6
F_193 ( struct V_5 * V_6 , T_4 V_84 , T_6 V_288 , T_10 V_289 )
{
T_11 * V_99 ;
T_28 * V_29 ;
struct V_83 * V_86 ;
T_4 V_30 ;
T_10 V_568 ;
T_6 V_501 ;
T_6 V_503 ;
T_10 V_509 ;
struct V_141 * V_142 ;
T_10 V_279 = 0 ;
unsigned long V_62 ;
V_29 = F_102 ( V_6 , V_289 ) ;
V_86 = F_37 ( V_6 , V_84 ) ;
if ( V_86 == NULL )
return 1 ;
V_99 = F_46 ( V_6 , V_84 ) ;
if ( V_29 == NULL ) {
V_86 -> V_344 = V_447 << 16 ;
goto V_71;
}
V_142 = V_86 -> V_42 -> V_146 ;
if ( ! V_142 || ! V_142 -> V_148 ||
V_142 -> V_148 -> V_381 ) {
V_86 -> V_344 = V_345 << 16 ;
goto V_71;
}
if ( F_175 ( V_6 , V_84 ) ) {
F_18 ( & V_6 -> V_87 , V_62 ) ;
V_6 -> V_85 [ V_84 - 1 ] . V_86 = V_86 ;
F_21 ( & V_6 -> V_87 , V_62 ) ;
F_176 ( V_6 , V_84 , 0 ) ;
memcpy ( V_99 -> V_431 . V_468 , V_86 -> V_463 , V_86 -> V_479 ) ;
V_99 -> V_230 =
F_115 ( V_142 -> V_148 -> V_27 ) ;
F_183 ( V_6 , V_84 ,
V_142 -> V_148 -> V_27 ) ;
return 0 ;
}
V_501 = V_29 -> V_502 ;
if ( V_501 & V_534 )
V_279 =
F_74 ( V_29 -> V_547 ) & 0xFF ;
if ( ! V_142 -> V_569 ) {
V_142 -> V_569 ++ ;
if ( ! V_6 -> V_187 && ! F_75 ( & V_86 -> V_42 -> V_221 ) &&
F_93 ( V_86 -> V_42 ) &&
V_279 == V_282 ) {
F_194 ( V_86 -> V_42 ) ;
F_49 ( V_7 , V_86 -> V_42 , L_167 ) ;
}
}
V_568 = F_74 ( V_29 -> V_541 ) ;
F_195 ( V_86 , F_50 ( V_86 ) - V_568 ) ;
V_30 = F_9 ( V_29 -> V_38 ) ;
if ( V_30 & V_570 )
V_509 = F_74 ( V_29 -> V_333 ) ;
else
V_509 = 0 ;
V_30 &= V_39 ;
V_503 = V_29 -> V_504 ;
if ( V_30 == V_515 && V_568 == 0 &&
( V_503 == V_526 ||
V_503 == V_529 ||
V_503 == V_531 ) ) {
V_30 = V_40 ;
}
if ( V_501 & V_538 ) {
struct V_542 V_543 ;
const void * V_571 = F_196 ( V_6 ,
V_84 ) ;
T_10 V_223 = F_197 ( T_10 , V_491 ,
F_74 ( V_29 -> V_546 ) ) ;
memcpy ( V_86 -> V_448 , V_571 , V_223 ) ;
F_186 ( V_86 -> V_448 , & V_543 ) ;
if ( V_543 . V_545 == 0x5D )
F_190 ( V_6 ,
F_9 ( V_29 -> V_230 ) ) ;
}
switch ( V_30 ) {
case V_572 :
case V_573 :
V_86 -> V_344 = V_574 ;
break;
case V_513 :
V_86 -> V_344 = V_345 << 16 ;
break;
case V_521 :
if ( V_142 -> V_361 ) {
V_86 -> V_344 = V_575 << 16 ;
goto V_71;
}
case V_518 :
case V_522 :
V_86 -> V_344 = V_347 << 16 ;
break;
case V_519 :
if ( ( V_568 == 0 ) || ( V_86 -> V_539 > V_568 ) )
V_86 -> V_344 = V_576 << 16 ;
else
V_86 -> V_344 = ( V_447 << 16 ) | V_503 ;
break;
case V_515 :
V_86 -> V_344 = ( V_447 << 16 ) | V_503 ;
if ( ( V_501 & V_538 ) )
break;
if ( V_568 < V_86 -> V_539 ) {
if ( V_503 == V_574 )
V_86 -> V_344 = V_574 ;
else
V_86 -> V_344 = V_576 << 16 ;
} else if ( V_501 & ( V_537 |
V_536 ) )
V_86 -> V_344 = V_576 << 16 ;
else if ( V_501 & V_535 )
V_86 -> V_344 = V_347 << 16 ;
else if ( ! V_568 && V_86 -> V_463 [ 0 ] == V_577 ) {
V_29 -> V_502 = V_538 ;
V_29 -> V_504 = V_450 ;
V_86 -> V_344 = ( V_449 << 24 ) |
V_450 ;
V_86 -> V_448 [ 0 ] = 0x70 ;
V_86 -> V_448 [ 2 ] = V_444 ;
V_86 -> V_448 [ 12 ] = 0x20 ;
V_86 -> V_448 [ 13 ] = 0 ;
}
break;
case V_514 :
F_195 ( V_86 , 0 ) ;
case V_511 :
case V_40 :
V_86 -> V_344 = ( V_447 << 16 ) | V_503 ;
if ( V_279 ==
V_282 ||
( V_501 & ( V_537 |
V_536 ) ) )
V_86 -> V_344 = V_576 << 16 ;
else if ( V_501 & V_535 )
V_86 -> V_344 = V_347 << 16 ;
break;
case V_441 :
case V_443 :
case V_442 :
F_173 ( V_86 , V_30 ) ;
break;
case V_517 :
case V_510 :
case V_578 :
case V_579 :
case V_580 :
case V_581 :
case V_516 :
case V_520 :
default:
V_86 -> V_344 = V_576 << 16 ;
break;
}
#ifdef F_150
if ( V_86 -> V_344 && ( V_6 -> V_8 & V_582 ) )
F_184 ( V_6 , V_86 , V_29 , V_84 ) ;
#endif
V_71:
F_166 ( V_86 ) ;
V_86 -> V_346 ( V_86 ) ;
return 1 ;
}
static void
F_198 ( struct V_5 * V_6 )
{
T_4 V_223 ;
T_4 V_30 ;
int V_88 ;
T_9 V_29 ;
T_34 * V_583 = NULL ;
T_4 V_584 ;
T_6 V_585 ;
F_114 ( V_6 , F_3 ( V_55
L_168 ,
V_6 -> V_35 , ( unsigned long long ) V_6 -> V_31 . V_9 ) ) ;
V_223 = F_51 ( T_34 , V_586 ) + ( V_6 -> V_31 . V_32
* sizeof( V_587 ) ) ;
V_583 = F_67 ( V_223 , V_169 ) ;
if ( ! V_583 ) {
F_3 ( V_34 L_2 ,
V_6 -> V_35 , __FILE__ , __LINE__ , V_36 ) ;
return;
}
if ( ( F_199 ( V_6 , & V_29 ,
V_583 , V_223 ) ) != 0 )
goto V_71;
V_30 = F_9 ( V_29 . V_38 ) & V_39 ;
if ( V_30 != V_40 )
goto V_71;
for ( V_88 = 0 ; V_88 < V_6 -> V_31 . V_32 ; V_88 ++ ) {
V_585 = V_583 -> V_586 [ V_88 ] . V_588 >> 4 ;
if ( V_88 == 0 )
V_6 -> V_31 . V_27 = F_9 ( V_583 ->
V_586 [ 0 ] . V_589 ) ;
V_6 -> V_31 . V_271 [ V_88 ] . V_27 = V_6 -> V_31 . V_27 ;
V_584 = F_9 ( V_583 -> V_586 [ V_88 ] .
V_374 ) ;
if ( V_584 && V_585 < V_590 )
V_585 = V_590 ;
F_200 ( V_6 , V_6 -> V_31 . V_9 ,
V_584 , V_88 , V_585 ) ;
}
V_71:
F_20 ( V_583 ) ;
}
static void
F_201 ( struct V_5 * V_6 )
{
int V_88 ;
T_9 V_29 ;
T_34 * V_583 = NULL ;
T_35 * V_591 = NULL ;
T_36 V_592 ;
T_8 V_28 ;
T_37 V_593 ;
T_4 V_30 ;
T_4 V_223 ;
T_4 V_594 ;
F_202 ( V_6 , & V_6 -> V_31 . V_32 ) ;
if ( ! V_6 -> V_31 . V_32 ) {
F_3 ( V_34 L_2 ,
V_6 -> V_35 , __FILE__ , __LINE__ , V_36 ) ;
return;
}
V_223 = F_51 ( T_34 , V_586 ) + ( V_6 -> V_31 . V_32 *
sizeof( V_587 ) ) ;
V_583 = F_67 ( V_223 , V_169 ) ;
if ( ! V_583 ) {
F_3 ( V_34 L_2 ,
V_6 -> V_35 , __FILE__ , __LINE__ , V_36 ) ;
return;
}
if ( ( F_199 ( V_6 , & V_29 ,
V_583 , V_223 ) ) ) {
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
V_223 = F_51 ( T_35 , V_586 ) + ( V_6 -> V_31 . V_32 *
sizeof( V_595 ) ) ;
V_591 = F_67 ( V_223 , V_169 ) ;
if ( ! V_591 ) {
F_3 ( V_34 L_2 ,
V_6 -> V_35 , __FILE__ , __LINE__ , V_36 ) ;
goto V_71;
}
if ( ( F_203 ( V_6 , & V_29 ,
V_591 , V_223 ) ) ) {
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
V_6 -> V_596 =
F_9 ( V_591 -> V_597 ) ;
V_594 =
F_9 ( V_591 -> V_598 ) ;
if ( V_594 & V_599 )
V_6 -> V_594 = ( V_594 &
V_600 ) * 16 ;
else
V_6 -> V_594 = V_594 &
V_600 ;
V_6 -> V_31 . V_601 = & V_6 -> V_138 -> V_602 ;
V_6 -> V_31 . V_271 = F_204 ( V_6 -> V_31 . V_32 ,
sizeof( struct V_603 ) , V_169 ) ;
if ( ! V_6 -> V_31 . V_271 ) {
F_3 ( V_34 L_2 ,
V_6 -> V_35 , __FILE__ , __LINE__ , V_36 ) ;
goto V_71;
}
for ( V_88 = 0 ; V_88 < V_6 -> V_31 . V_32 ; V_88 ++ ) {
if ( ( F_205 ( V_6 , & V_29 , & V_592 ,
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
V_6 -> V_31 . V_27 = F_9 ( V_583 ->
V_586 [ 0 ] . V_589 ) ;
V_6 -> V_31 . V_271 [ V_88 ] . V_27 = V_6 -> V_31 . V_27 ;
V_6 -> V_31 . V_271 [ V_88 ] . V_604 = V_88 ;
F_206 ( V_6 , & V_6 -> V_31 . V_271 [ V_88 ] ,
V_592 , V_6 -> V_31 . V_601 ) ;
}
if ( ( F_12 ( V_6 , & V_29 , & V_28 ,
V_33 , V_6 -> V_31 . V_27 ) ) ) {
F_3 ( V_34 L_2 ,
V_6 -> V_35 , __FILE__ , __LINE__ , V_36 ) ;
goto V_71;
}
V_6 -> V_31 . V_605 =
F_9 ( V_28 . V_606 ) ;
V_6 -> V_31 . V_9 = F_6 ( V_28 . V_11 ) ;
F_3 ( V_55 L_169
L_170 , V_6 -> V_35 , V_6 -> V_31 . V_27 ,
( unsigned long long ) V_6 -> V_31 . V_9 ,
V_6 -> V_31 . V_32 ) ;
if ( V_6 -> V_31 . V_605 ) {
if ( ! ( F_207 ( V_6 , & V_29 ,
& V_593 ,
V_607 ,
V_6 -> V_31 . V_605 ) ) ) {
V_6 -> V_31 . V_14 =
F_6 ( V_593 . V_16 ) ;
}
}
V_71:
F_20 ( V_591 ) ;
F_20 ( V_583 ) ;
}
static int
F_208 ( struct V_5 * V_6 , T_4 V_27 )
{
struct V_74 * V_75 ;
T_9 V_29 ;
T_38 V_608 ;
T_39 V_609 ;
T_37 V_593 ;
T_10 V_30 ;
T_4 V_610 ;
T_1 V_9 , V_66 = 0 ;
int V_88 ;
unsigned long V_62 ;
struct V_362 * V_363 = NULL ;
int V_20 = 0 ;
if ( ! V_27 )
return - 1 ;
if ( V_6 -> V_313 || V_6 -> V_315 )
return - 1 ;
if ( ( F_209 ( V_6 , & V_29 , & V_608 ,
V_611 , V_27 ) ) ) {
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
V_610 = F_9 ( V_608 . V_612 ) ;
if ( F_11 ( V_6 , V_610 , & V_66 )
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
V_20 = F_208 ( V_6 , V_610 ) ;
if ( V_20 != 0 )
return V_20 ;
}
}
F_18 ( & V_6 -> V_76 , V_62 ) ;
V_9 = F_6 ( V_608 . V_11 ) ;
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
V_75 -> V_32 = V_608 . V_613 ;
V_75 -> V_66 = V_66 ;
V_75 -> V_9 = V_9 ;
F_3 ( V_55 L_171
L_172 , V_6 -> V_35 ,
V_27 , V_610 , ( unsigned long long )
V_75 -> V_9 , V_75 -> V_32 ) ;
if ( ! V_75 -> V_32 )
goto V_614;
V_75 -> V_271 = F_204 ( V_75 -> V_32 ,
sizeof( struct V_603 ) , V_169 ) ;
if ( ! V_75 -> V_271 ) {
F_3 ( V_34 L_2 ,
V_6 -> V_35 , __FILE__ , __LINE__ , V_36 ) ;
V_20 = - 1 ;
goto V_614;
}
F_148 ( & V_75 -> V_615 ) ;
V_363 = F_25 ( V_6 , V_27 ,
V_66 ) ;
if ( ! V_363 ) {
F_3 ( V_34 L_2 ,
V_6 -> V_35 , __FILE__ , __LINE__ , V_36 ) ;
V_20 = - 1 ;
goto V_614;
}
V_75 -> V_601 = & V_363 -> V_168 -> V_166 ;
for ( V_88 = 0 ; V_88 < V_75 -> V_32 ; V_88 ++ ) {
if ( ( F_210 ( V_6 , & V_29 ,
& V_609 , V_88 , V_27 ) ) ) {
F_3 ( V_34 L_2 ,
V_6 -> V_35 , __FILE__ , __LINE__ , V_36 ) ;
V_20 = - 1 ;
goto V_614;
}
V_75 -> V_271 [ V_88 ] . V_27 = V_27 ;
V_75 -> V_271 [ V_88 ] . V_604 = V_88 ;
if ( ( F_211 ( V_6 ,
& V_75 -> V_271 [ V_88 ] , V_609 ,
V_75 -> V_601 ) ) ) {
F_3 ( V_34 L_2 ,
V_6 -> V_35 , __FILE__ , __LINE__ , V_36 ) ;
V_20 = - 1 ;
goto V_614;
}
}
if ( V_75 -> V_605 ) {
if ( ! ( F_207 ( V_6 , & V_29 ,
& V_593 , V_607 ,
V_75 -> V_605 ) ) ) {
V_75 -> V_14 =
F_6 ( V_593 . V_16 ) ;
}
}
F_34 ( V_6 , V_75 ) ;
return 0 ;
V_614:
if ( V_363 )
F_212 ( V_6 , V_75 -> V_9 ,
V_66 ) ;
F_20 ( V_75 ) ;
return V_20 ;
}
static T_6
F_213 ( struct V_5 * V_6 , T_4 V_84 , T_6 V_288 , T_10 V_289 )
{
T_18 * V_29 ;
V_29 = F_102 ( V_6 , V_289 ) ;
if ( V_6 -> V_616 . V_291 == V_292 )
return 1 ;
if ( V_6 -> V_616 . V_84 != V_84 )
return 1 ;
V_6 -> V_616 . V_291 |= V_293 ;
if ( V_29 ) {
memcpy ( V_6 -> V_616 . V_289 , V_29 ,
V_29 -> V_294 * 4 ) ;
V_6 -> V_616 . V_291 |= V_295 ;
}
V_6 -> V_616 . V_291 &= ~ V_296 ;
F_103 ( & V_6 -> V_616 . V_297 ) ;
return 1 ;
}
void
F_214 ( struct V_5 * V_6 , T_1 V_9 )
{
struct V_74 * V_75 ;
unsigned long V_62 ;
if ( V_6 -> V_313 )
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
F_215 ( V_6 , V_75 ) ;
}
static T_6
F_216 ( struct V_5 * V_6 , T_1 V_9 ,
T_4 V_27 , T_6 V_617 )
{
T_6 V_20 = 1 ;
char * V_280 = NULL ;
switch ( V_617 ) {
case V_618 :
case V_619 :
V_20 = 0 ;
break;
case V_620 :
V_280 = L_173 ;
break;
case V_621 :
V_280 = L_174 ;
break;
case V_622 :
V_280 = L_175 ;
break;
case V_623 :
V_280 = L_176 ;
break;
case V_624 :
V_280 = L_177 ;
break;
case V_625 :
case V_626 :
case V_627 :
case V_628 :
case V_629 :
case V_630 :
case V_631 :
case V_632 :
case V_633 :
case V_634 :
case V_635 :
case V_636 :
V_280 = L_178 ;
break;
default:
V_280 = L_62 ;
break;
}
if ( ! V_20 )
return 0 ;
F_3 ( V_34 L_179
L_95 , V_6 -> V_35 , V_280 ,
( unsigned long long ) V_9 , V_27 ) ;
return V_20 ;
}
static void
F_217 ( struct V_5 * V_6 , T_4 V_27 )
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
F_3 ( V_34 L_180
L_181 , V_6 -> V_35 , V_27 ) ;
F_21 ( & V_6 -> V_63 , V_62 ) ;
return;
}
if ( F_218 ( V_45 -> V_27 != V_27 ) ) {
V_165 = V_45 -> V_165 ;
V_144 = V_165 -> V_146 ;
F_124 ( V_7 , V_165 , L_182
L_183 , V_45 -> V_27 , V_27 ) ;
V_144 -> V_27 = V_27 ;
V_45 -> V_27 = V_27 ;
}
F_21 ( & V_6 -> V_63 , V_62 ) ;
if ( ! ( F_9 ( V_28 . V_179 ) &
V_637 ) ) {
F_3 ( V_34 L_180
L_184 , V_6 -> V_35 , V_27 ) ;
return;
}
if ( F_216 ( V_6 , V_9 , V_27 ,
V_28 . V_638 ) )
return;
F_141 ( V_6 , V_27 ) ;
}
static int
F_219 ( struct V_5 * V_6 , T_4 V_27 , T_6 V_639 , T_6 V_640 )
{
T_9 V_29 ;
T_8 V_28 ;
T_37 V_593 ;
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
V_637 ) ) {
F_3 ( V_34 L_2 ,
V_6 -> V_35 , __FILE__ , __LINE__ , V_36 ) ;
F_3 ( V_34 L_185 ,
V_6 -> V_35 , F_9 ( V_28 . V_179 ) ) ;
return - 1 ;
}
if ( F_216 ( V_6 , V_9 , V_27 ,
V_28 . V_638 ) )
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
( V_28 . V_612 ) ,
& V_45 -> V_66 ) != 0 )
F_3 ( V_34 L_2 ,
V_6 -> V_35 , __FILE__ , __LINE__ , V_36 ) ;
V_45 -> V_605 =
F_9 ( V_28 . V_606 ) ;
V_45 -> V_18 =
F_9 ( V_28 . V_641 ) ;
V_45 -> V_78 = V_78 ;
V_45 -> V_9 = V_9 ;
V_45 -> V_271 = V_28 . V_642 ;
if ( V_45 -> V_605 && ! ( F_207 (
V_6 , & V_29 , & V_593 , V_607 ,
V_45 -> V_605 ) ) )
V_45 -> V_14 =
F_6 ( V_593 . V_16 ) ;
V_45 -> V_12 = F_6 ( V_28 . V_13 ) ;
if ( V_6 -> V_48 )
F_26 ( V_6 , V_45 ) ;
else
F_22 ( V_6 , V_45 ) ;
return 0 ;
}
static void
F_220 ( struct V_5 * V_6 ,
struct V_44 * V_45 )
{
struct V_44 V_643 ;
struct V_143 * V_144 ;
if ( ! V_45 )
return;
memcpy ( & V_643 , V_45 , sizeof( struct V_44 ) ) ;
F_17 ( V_6 , V_45 ) ;
F_23 ( V_6 , F_3 ( V_55 L_186
L_187 , V_6 -> V_35 , V_36 ,
V_643 . V_27 , ( unsigned long long )
V_643 . V_9 ) ) ;
if ( V_643 . V_165 && V_643 . V_165 -> V_146 ) {
V_144 = V_643 . V_165 -> V_146 ;
V_144 -> V_381 = 1 ;
}
F_141 ( V_6 , V_643 . V_27 ) ;
if ( ! V_6 -> V_644 )
F_212 ( V_6 ,
V_643 . V_9 ,
V_643 . V_66 ) ;
F_3 ( V_55 L_188
L_189 , V_6 -> V_35 , V_643 . V_27 ,
( unsigned long long ) V_643 . V_9 ) ;
F_23 ( V_6 , F_3 ( V_55 L_190
L_187 , V_6 -> V_35 , V_36 ,
V_643 . V_27 , ( unsigned long long )
V_643 . V_9 ) ) ;
}
void
F_221 ( struct V_5 * V_6 , T_1 V_9 )
{
struct V_44 * V_45 ;
unsigned long V_62 ;
if ( V_6 -> V_313 )
return;
F_18 ( & V_6 -> V_63 , V_62 ) ;
V_45 = F_15 ( V_6 ,
V_9 ) ;
if ( ! V_45 ) {
F_21 ( & V_6 -> V_63 , V_62 ) ;
return;
}
F_21 ( & V_6 -> V_63 , V_62 ) ;
F_220 ( V_6 , V_45 ) ;
}
static void
F_222 ( struct V_5 * V_6 ,
T_22 * V_356 )
{
int V_88 ;
T_4 V_27 ;
T_4 V_370 ;
T_6 V_371 ;
char * V_645 = NULL ;
T_6 V_585 , V_646 ;
switch ( V_356 -> V_396 ) {
case V_402 :
V_645 = L_191 ;
break;
case V_398 :
V_645 = L_192 ;
break;
case V_399 :
case 0 :
V_645 = L_193 ;
break;
case V_397 :
V_645 = L_194 ;
break;
default:
V_645 = L_195 ;
break;
}
F_3 ( V_55 L_196 ,
V_6 -> V_35 , V_645 ) ;
F_3 ( V_7 L_197
L_198 ,
F_9 ( V_356 -> V_395 ) ,
F_9 ( V_356 -> V_606 ) ,
V_356 -> V_375 , V_356 -> V_372 ) ;
for ( V_88 = 0 ; V_88 < V_356 -> V_372 ; V_88 ++ ) {
V_27 = F_9 ( V_356 -> V_373 [ V_88 ] . V_374 ) ;
if ( ! V_27 )
continue;
V_371 = V_356 -> V_375 + V_88 ;
V_370 = V_356 -> V_373 [ V_88 ] . V_376 &
V_377 ;
switch ( V_370 ) {
case V_647 :
V_645 = L_199 ;
break;
case V_394 :
V_645 = L_200 ;
break;
case V_378 :
V_645 = L_201 ;
break;
case V_648 :
V_645 = L_202 ;
break;
case V_649 :
V_645 = L_203 ;
break;
default:
V_645 = L_62 ;
break;
}
V_585 = V_356 -> V_373 [ V_88 ] . V_650 >> 4 ;
V_646 = V_356 -> V_373 [ V_88 ] . V_650 & 0xF ;
F_3 ( V_7 L_204
L_205 , V_371 ,
V_27 , V_645 , V_585 , V_646 ) ;
}
}
static void
F_223 ( struct V_5 * V_6 ,
struct V_349 * V_350 )
{
int V_88 ;
T_4 V_610 , V_27 ;
T_4 V_370 ;
T_6 V_371 , V_651 ;
struct V_74 * V_75 ;
struct V_44 * V_45 ;
T_1 V_9 ;
unsigned long V_62 ;
T_6 V_585 , V_646 ;
T_22 * V_356 = V_350 -> V_356 ;
#ifdef F_150
if ( V_6 -> V_8 & V_652 )
F_222 ( V_6 , V_356 ) ;
#endif
if ( V_6 -> V_313 || V_6 -> V_314 || V_6 -> V_315 )
return;
if ( ! V_6 -> V_31 . V_32 )
F_201 ( V_6 ) ;
else
F_198 ( V_6 ) ;
if ( V_350 -> V_401 ) {
F_23 ( V_6 , F_3 ( V_55 L_206
L_207 , V_6 -> V_35 ) ) ;
return;
}
V_610 = F_9 ( V_356 -> V_395 ) ;
if ( V_356 -> V_396 == V_402 )
if ( F_208 ( V_6 , V_610 ) != 0 )
return;
F_18 ( & V_6 -> V_76 , V_62 ) ;
V_75 = F_32 ( V_6 ,
V_610 ) ;
F_21 ( & V_6 -> V_76 , V_62 ) ;
if ( V_75 ) {
V_9 = V_75 -> V_9 ;
V_651 = V_75 -> V_32 ;
} else if ( V_610 < V_6 -> V_31 . V_32 ) {
V_9 = V_6 -> V_31 . V_9 ;
V_651 = V_6 -> V_31 . V_32 ;
} else
return;
for ( V_88 = 0 ; V_88 < V_356 -> V_372 ; V_88 ++ ) {
if ( V_350 -> V_401 ) {
F_23 ( V_6 , F_3 ( V_55 L_208
L_209 , V_6 -> V_35 ) ) ;
return;
}
if ( V_6 -> V_313 || V_6 -> V_314 ||
V_6 -> V_315 )
return;
V_371 = V_356 -> V_375 + V_88 ;
if ( V_371 >= V_651 )
continue;
V_370 = V_356 -> V_373 [ V_88 ] . V_376 &
V_377 ;
if ( ( V_356 -> V_373 [ V_88 ] . V_376 &
V_653 ) && ( V_370 !=
V_394 ) )
continue;
V_27 = F_9 ( V_356 -> V_373 [ V_88 ] . V_374 ) ;
if ( ! V_27 )
continue;
V_585 = V_356 -> V_373 [ V_88 ] . V_650 >> 4 ;
V_646 = V_356 -> V_373 [ V_88 ] . V_650 & 0xF ;
switch ( V_370 ) {
case V_648 :
if ( V_585 == V_646 )
break;
F_200 ( V_6 , V_9 ,
V_27 , V_371 , V_585 ) ;
if ( V_585 < V_590 )
break;
F_217 ( V_6 , V_27 ) ;
break;
case V_647 :
F_200 ( V_6 , V_9 ,
V_27 , V_371 , V_585 ) ;
F_219 ( V_6 , V_27 , V_371 , 0 ) ;
break;
case V_394 :
F_18 ( & V_6 -> V_63 , V_62 ) ;
V_45 = F_16 ( V_6 ,
V_27 ) ;
if ( ! V_45 ) {
F_21 ( & V_6 -> V_63 ,
V_62 ) ;
break;
}
F_21 ( & V_6 -> V_63 , V_62 ) ;
F_220 ( V_6 , V_45 ) ;
break;
}
}
if ( V_356 -> V_396 == V_398 &&
V_75 )
F_214 ( V_6 , V_9 ) ;
}
static void
F_224 ( struct V_5 * V_6 ,
T_32 * V_356 )
{
char * V_654 = NULL ;
switch ( V_356 -> V_408 ) {
case V_566 :
V_654 = L_210 ;
break;
case V_655 :
V_654 = L_211 ;
break;
case V_656 :
V_654 = L_212 ;
break;
case V_657 :
V_654 = L_213 ;
break;
case V_658 :
V_654 = L_214 ;
break;
case V_659 :
V_654 = L_215 ;
break;
case V_660 :
V_654 = L_216 ;
break;
case V_661 :
V_654 = L_217 ;
break;
case V_662 :
V_654 = L_218 ;
break;
case V_663 :
V_654 = L_219 ;
break;
case V_664 :
V_654 = L_220 ;
break;
case V_665 :
V_654 = L_221 ;
break;
case V_666 :
V_654 = L_222 ;
break;
default:
V_654 = L_223 ;
break;
}
F_3 ( V_55 L_224
L_225 ,
V_6 -> V_35 , V_654 , F_9 ( V_356 -> V_230 ) ,
( unsigned long long ) F_6 ( V_356 -> V_11 ) ,
F_9 ( V_356 -> V_540 ) ) ;
if ( V_356 -> V_408 == V_566 )
F_3 ( V_55 L_226 , V_6 -> V_35 ,
V_356 -> V_567 , V_356 -> V_667 ) ;
F_3 ( V_7 L_227 ) ;
}
static void
F_225 ( struct V_5 * V_6 ,
struct V_349 * V_350 )
{
struct V_143 * V_668 ;
struct V_44 * V_45 ;
T_1 V_9 ;
unsigned long V_62 ;
T_32 * V_356 =
V_350 -> V_356 ;
#ifdef F_150
if ( V_6 -> V_8 & V_652 )
F_224 ( V_6 ,
V_356 ) ;
#endif
if ( ( V_6 -> V_254 . V_669 >> 8 ) < 0xC )
return;
if ( V_356 -> V_408 !=
V_656 &&
V_356 -> V_408 !=
V_662 )
return;
F_18 ( & V_6 -> V_63 , V_62 ) ;
V_9 = F_6 ( V_356 -> V_11 ) ;
V_45 = F_15 ( V_6 ,
V_9 ) ;
F_21 ( & V_6 -> V_63 , V_62 ) ;
if ( ! V_45 || ! V_45 -> V_165 )
return;
V_668 = V_45 -> V_165 -> V_146 ;
if ( ! V_668 )
return;
if ( V_356 -> V_408 ==
V_656 )
V_668 -> V_299 = 1 ;
else
V_668 -> V_299 = 0 ;
}
static void
F_226 ( struct V_5 * V_6 ,
T_41 * V_356 )
{
char * V_654 = NULL ;
switch ( V_356 -> V_408 ) {
case V_670 :
V_654 = L_228 ;
break;
case V_671 :
V_654 = L_229 ;
break;
default:
V_654 = L_223 ;
break;
}
F_3 ( V_55 L_230
L_231
L_232 , V_6 -> V_35 , V_654 ,
F_9 ( V_356 -> V_606 ) ,
( unsigned long long ) F_6 ( V_356 -> V_16 ) ,
F_9 ( V_356 -> V_672 ) ) ;
}
static void
F_227 ( struct V_5 * V_6 ,
struct V_349 * V_350 )
{
#ifdef F_150
if ( V_6 -> V_8 & V_652 )
F_226 ( V_6 ,
V_350 -> V_356 ) ;
#endif
}
static void
F_228 ( struct V_5 * V_6 ,
struct V_349 * V_350 )
{
struct V_83 * V_86 ;
struct V_134 * V_135 ;
T_4 V_84 , V_27 ;
T_10 V_91 ;
struct V_141 * V_142 ;
T_10 V_673 ;
T_10 V_674 ;
T_21 * V_29 ;
T_42 * V_356 = V_350 -> V_356 ;
T_4 V_30 ;
unsigned long V_62 ;
int V_70 ;
T_6 V_675 = 0 ;
T_6 V_676 ;
F_108 ( & V_6 -> V_290 . V_310 ) ;
F_23 ( V_6 , F_3 ( V_55 L_233
L_234 , V_6 -> V_35 , V_36 , V_356 -> V_642 ,
V_356 -> V_677 ) ) ;
F_142 ( V_6 ) ;
F_18 ( & V_6 -> V_87 , V_62 ) ;
V_29 = V_6 -> V_290 . V_289 ;
V_678:
if ( V_675 ++ == 5 ) {
F_23 ( V_6 , F_3 ( V_55 L_235 ,
V_6 -> V_35 , V_36 ) ) ;
goto V_71;
} else if ( V_675 > 1 )
F_23 ( V_6 , F_3 ( V_55 L_236 ,
V_6 -> V_35 , V_36 , V_675 - 1 ) ) ;
V_673 = 0 ;
V_674 = 0 ;
for ( V_84 = 1 ; V_84 <= V_6 -> V_89 ; V_84 ++ ) {
if ( V_6 -> V_679 )
goto V_71;
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
V_674 ++ ;
if ( V_6 -> V_679 )
goto V_71;
F_21 ( & V_6 -> V_87 , V_62 ) ;
V_70 = F_107 ( V_6 , V_27 , 0 , 0 , V_91 ,
V_340 , V_84 , 30 , 0 ,
V_680 ) ;
if ( V_70 == V_311 ) {
F_49 ( V_557 , V_135 ,
L_237
L_238 , V_86 ) ;
F_18 ( & V_6 -> V_87 , V_62 ) ;
goto V_678;
}
V_30 = F_9 ( V_29 -> V_38 )
& V_39 ;
if ( V_30 != V_40 ) {
F_49 ( V_557 , V_135 , L_239
L_240 , V_30 ,
V_86 ) ;
F_18 ( & V_6 -> V_87 , V_62 ) ;
goto V_678;
}
if ( V_29 -> V_336 ==
V_285 ||
V_29 -> V_336 ==
V_287 ) {
F_18 ( & V_6 -> V_87 , V_62 ) ;
continue;
}
V_676 = 0 ;
V_681:
if ( V_676 ++ == 60 ) {
F_23 ( V_6 , F_3 ( V_55
L_241 , V_6 -> V_35 ,
V_36 ) ) ;
F_18 ( & V_6 -> V_87 , V_62 ) ;
goto V_678;
}
if ( V_6 -> V_679 )
goto V_682;
V_70 = F_107 ( V_6 , V_27 , V_135 -> V_69 , V_135 -> V_68 ,
V_135 -> V_91 , V_324 , V_84 , 30 ,
V_86 -> V_303 , V_680 ) ;
if ( V_70 == V_311 ) {
F_49 ( V_557 , V_135 ,
L_242
L_82 , V_86 ) ;
goto V_681;
}
if ( V_676 > 1 )
F_49 ( V_557 , V_135 ,
L_243
L_244 ,
V_676 - 1 , V_86 ) ;
V_673 += F_74 ( V_29 -> V_334 ) ;
F_18 ( & V_6 -> V_87 , V_62 ) ;
}
if ( V_6 -> V_683 ) {
F_23 ( V_6 , F_3 ( V_55 L_245
L_246 , V_6 -> V_35 , V_36 ) ) ;
V_6 -> V_683 = 0 ;
goto V_678;
}
V_71:
F_21 ( & V_6 -> V_87 , V_62 ) ;
V_682:
F_23 ( V_6 , F_3 ( V_55
L_247 ,
V_6 -> V_35 , V_36 , V_674 , V_673 ) ) ;
V_6 -> V_684 = 0 ;
if ( ! V_6 -> V_679 )
F_139 ( V_6 ) ;
F_121 ( & V_6 -> V_290 . V_310 ) ;
}
static void
F_229 ( struct V_5 * V_6 ,
struct V_349 * V_350 )
{
T_43 * V_356 = V_350 -> V_356 ;
#ifdef F_150
if ( V_6 -> V_8 & V_652 ) {
F_3 ( V_55 L_248 , V_6 -> V_35 ,
( V_356 -> V_408 == V_685 ) ?
L_249 : L_250 ) ;
if ( V_356 -> V_686 )
F_3 ( L_251 ,
F_74 ( V_356 -> V_686 ) ) ;
F_3 ( L_227 ) ;
}
#endif
if ( V_356 -> V_408 == V_685 &&
! V_6 -> V_31 . V_32 )
F_201 ( V_6 ) ;
}
static void
F_230 ( struct V_134 * V_135 , void * V_178 )
{
int V_20 ;
V_135 -> V_178 = V_178 ? 1 : 0 ;
F_49 ( V_7 , V_135 , L_252 ,
V_135 -> V_178 ? L_253 : L_254 ) ;
V_20 = F_231 ( V_135 ) ;
}
static void
F_232 ( struct V_164 * V_165 , int V_178 )
{
struct V_143 * V_144 = V_165 -> V_146 ;
if ( V_178 )
V_144 -> V_62 |= V_175 ;
else
V_144 -> V_62 &= ~ V_175 ;
F_233 ( V_165 , V_178 ? ( void * ) 1 : NULL ,
F_230 ) ;
}
static void
F_234 ( struct V_5 * V_6 ,
T_26 * V_405 )
{
struct V_46 * V_47 ;
unsigned long V_62 ;
T_1 V_49 ;
T_4 V_27 = F_9 ( V_405 -> V_411 ) ;
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
V_47 -> V_68 = V_6 -> V_687 ++ ;
V_47 -> V_69 = V_171 ;
V_47 -> V_27 = V_27 ;
V_47 -> V_49 = V_49 ;
F_30 ( V_6 , V_47 ) ;
if ( ! V_6 -> V_48 ) {
V_20 = F_235 ( V_6 -> V_138 , V_171 ,
V_47 -> V_68 , 0 ) ;
if ( V_20 )
F_31 ( V_6 , V_47 ) ;
} else
F_13 ( V_6 , V_47 , 1 ) ;
}
static void
F_236 ( struct V_5 * V_6 , T_4 V_27 )
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
V_144 -> V_381 = 1 ;
F_237 ( & V_47 -> V_165 -> V_166 ) ;
}
F_3 ( V_55 L_255
L_189 , V_6 -> V_35 , V_47 -> V_27 ,
( unsigned long long ) V_47 -> V_49 ) ;
F_31 ( V_6 , V_47 ) ;
}
static void
F_238 ( struct V_5 * V_6 ,
T_26 * V_405 )
{
struct V_44 * V_45 ;
unsigned long V_62 ;
T_4 V_27 = F_9 ( V_405 -> V_414 ) ;
F_18 ( & V_6 -> V_63 , V_62 ) ;
V_45 = F_16 ( V_6 , V_27 ) ;
F_21 ( & V_6 -> V_63 , V_62 ) ;
if ( ! V_45 )
return;
V_45 -> V_269 = 0 ;
V_45 -> V_270 = 0 ;
F_162 ( V_27 , V_6 -> V_174 ) ;
F_232 ( V_45 -> V_165 , 0 ) ;
}
static void
F_239 ( struct V_5 * V_6 ,
T_26 * V_405 )
{
struct V_44 * V_45 ;
unsigned long V_62 ;
T_4 V_27 = F_9 ( V_405 -> V_414 ) ;
F_18 ( & V_6 -> V_63 , V_62 ) ;
V_45 = F_16 ( V_6 , V_27 ) ;
F_21 ( & V_6 -> V_63 , V_62 ) ;
if ( ! V_45 )
return;
F_95 ( V_6 , V_27 ,
& V_45 -> V_269 ) ;
F_96 ( V_6 , V_45 -> V_269 ,
& V_45 -> V_270 ) ;
F_240 ( V_27 , V_6 -> V_174 ) ;
F_232 ( V_45 -> V_165 , 1 ) ;
}
static void
F_241 ( struct V_5 * V_6 ,
T_26 * V_405 )
{
struct V_44 * V_45 ;
unsigned long V_62 ;
T_4 V_27 = F_9 ( V_405 -> V_414 ) ;
F_18 ( & V_6 -> V_63 , V_62 ) ;
V_45 = F_16 ( V_6 , V_27 ) ;
F_21 ( & V_6 -> V_63 , V_62 ) ;
if ( ! V_45 )
return;
F_220 ( V_6 , V_45 ) ;
}
static void
F_242 ( struct V_5 * V_6 ,
T_26 * V_405 )
{
struct V_44 * V_45 ;
unsigned long V_62 ;
T_4 V_27 = F_9 ( V_405 -> V_414 ) ;
T_9 V_29 ;
T_8 V_28 ;
T_10 V_30 ;
T_1 V_9 ;
T_4 V_610 ;
F_240 ( V_27 , V_6 -> V_174 ) ;
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
V_610 = F_9 ( V_28 . V_612 ) ;
if ( ! F_11 ( V_6 , V_610 , & V_9 ) )
F_200 ( V_6 , V_9 , V_27 ,
V_28 . V_642 , V_590 ) ;
F_219 ( V_6 , V_27 , 0 , 1 ) ;
}
static void
F_243 ( struct V_5 * V_6 ,
T_25 * V_356 )
{
T_26 * V_405 ;
T_6 V_688 ;
int V_88 ;
char * V_654 = NULL , * V_689 = NULL ;
V_405 = ( T_26 * ) & V_356 -> V_406 [ 0 ] ;
F_3 ( V_55 L_256 ,
V_6 -> V_35 , ( F_74 ( V_356 -> V_179 ) &
V_412 ) ?
L_257 : L_258 , V_356 -> V_407 ) ;
for ( V_88 = 0 ; V_88 < V_356 -> V_407 ; V_88 ++ , V_405 ++ ) {
switch ( V_405 -> V_408 ) {
case V_690 :
V_654 = L_191 ;
break;
case V_410 :
V_654 = L_192 ;
break;
case V_691 :
V_654 = L_259 ;
break;
case V_692 :
V_654 = L_260 ;
break;
case V_413 :
V_654 = L_261 ;
break;
case V_693 :
V_654 = L_262 ;
break;
case V_409 :
V_654 = L_263 ;
break;
case V_694 :
V_654 = L_264 ;
break;
case V_695 :
V_654 = L_265 ;
break;
default:
V_654 = L_223 ;
break;
}
V_688 = F_9 ( V_405 -> V_696 ) &
V_697 ;
switch ( V_688 ) {
case V_698 :
V_689 = L_75 ;
break;
case V_699 :
V_689 = L_266 ;
break;
case V_700 :
V_689 = L_267 ;
break;
default:
V_689 = L_268 ;
break;
}
F_3 ( V_7 L_269
L_270 , V_689 ,
V_654 , F_9 ( V_405 -> V_411 ) ,
F_9 ( V_405 -> V_414 ) ,
V_405 -> V_229 ) ;
}
}
static void
F_244 ( struct V_5 * V_6 ,
struct V_349 * V_350 )
{
T_26 * V_405 ;
int V_88 ;
T_6 V_701 ;
T_25 * V_356 = V_350 -> V_356 ;
#ifdef F_150
if ( ( V_6 -> V_8 & V_652 )
&& ! V_6 -> V_268 )
F_243 ( V_6 , V_356 ) ;
#endif
V_701 = ( F_74 ( V_356 -> V_179 ) &
V_412 ) ? 1 : 0 ;
V_405 = ( T_26 * ) & V_356 -> V_406 [ 0 ] ;
for ( V_88 = 0 ; V_88 < V_356 -> V_407 ; V_88 ++ , V_405 ++ ) {
switch ( V_405 -> V_408 ) {
case V_693 :
case V_690 :
if ( ! V_701 )
F_234 ( V_6 , V_405 ) ;
break;
case V_409 :
case V_410 :
if ( ! V_701 )
F_236 ( V_6 ,
F_9 ( V_405 -> V_411 ) ) ;
break;
case V_694 :
if ( ! V_6 -> V_187 )
F_239 ( V_6 , V_405 ) ;
break;
case V_695 :
if ( ! V_6 -> V_187 )
F_238 ( V_6 , V_405 ) ;
break;
case V_692 :
if ( ! V_6 -> V_187 )
F_242 ( V_6 , V_405 ) ;
break;
case V_413 :
if ( ! V_6 -> V_187 )
F_241 ( V_6 , V_405 ) ;
break;
}
}
}
static void
F_245 ( struct V_5 * V_6 ,
struct V_349 * V_350 )
{
T_1 V_49 ;
unsigned long V_62 ;
struct V_46 * V_47 ;
T_4 V_27 ;
T_10 V_197 ;
int V_20 ;
T_27 * V_356 = V_350 -> V_356 ;
if ( V_356 -> V_408 != V_415 )
return;
V_27 = F_9 ( V_356 -> V_411 ) ;
V_197 = F_74 ( V_356 -> V_416 ) ;
if ( ! V_6 -> V_268 )
F_23 ( V_6 , F_3 ( V_55 L_49
L_271 , V_6 -> V_35 , V_36 , V_27 ,
F_74 ( V_356 -> V_702 ) , V_197 ) ) ;
switch ( V_197 ) {
case V_207 :
case V_206 :
F_236 ( V_6 , V_27 ) ;
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
V_47 -> V_68 = V_6 -> V_687 ++ ;
V_47 -> V_69 = V_171 ;
V_47 -> V_27 = V_27 ;
V_47 -> V_49 = V_49 ;
F_30 ( V_6 , V_47 ) ;
V_20 = F_235 ( V_6 -> V_138 , V_171 ,
V_47 -> V_68 , 0 ) ;
if ( V_20 )
F_31 ( V_6 , V_47 ) ;
break;
case V_703 :
default:
break;
}
}
static void
F_246 ( struct V_5 * V_6 ,
struct V_349 * V_350 )
{
T_4 V_27 , V_610 ;
T_10 V_197 ;
struct V_44 * V_45 ;
unsigned long V_62 ;
T_9 V_29 ;
T_8 V_28 ;
T_10 V_30 ;
T_44 * V_356 = V_350 -> V_356 ;
T_1 V_9 ;
if ( V_356 -> V_408 != V_704 )
return;
V_27 = F_9 ( V_356 -> V_414 ) ;
V_197 = F_74 ( V_356 -> V_416 ) ;
if ( ! V_6 -> V_268 )
F_23 ( V_6 , F_3 ( V_55 L_49
L_271 , V_6 -> V_35 , V_36 , V_27 ,
F_74 ( V_356 -> V_702 ) , V_197 ) ) ;
switch ( V_197 ) {
case V_705 :
case V_706 :
case V_707 :
case V_708 :
case V_709 :
if ( ! V_6 -> V_187 )
F_240 ( V_27 , V_6 -> V_174 ) ;
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
V_610 = F_9 ( V_28 . V_612 ) ;
if ( ! F_11 ( V_6 , V_610 , & V_9 ) )
F_200 ( V_6 , V_9 , V_27 ,
V_28 . V_642 , V_590 ) ;
F_219 ( V_6 , V_27 , 0 , 1 ) ;
break;
case V_710 :
case V_711 :
case V_712 :
default:
break;
}
}
static void
F_247 ( struct V_5 * V_6 ,
T_45 * V_356 )
{
char * V_654 = NULL ;
switch ( V_356 -> V_713 ) {
case V_714 :
V_654 = L_272 ;
break;
case V_715 :
V_654 = L_273 ;
break;
case V_716 :
V_654 = L_274 ;
break;
case V_717 :
V_654 = L_275 ;
break;
case V_718 :
V_654 = L_276 ;
break;
}
if ( ! V_654 )
return;
F_3 ( V_55 L_277
L_278 ,
V_6 -> V_35 , V_654 ,
F_9 ( V_356 -> V_411 ) ,
V_356 -> V_719 ) ;
}
static void
F_248 ( struct V_5 * V_6 ,
struct V_349 * V_350 )
{
T_45 * V_356 = V_350 -> V_356 ;
static struct V_46 * V_47 ;
unsigned long V_62 ;
T_4 V_27 ;
#ifdef F_150
if ( ( V_6 -> V_8 & V_652 )
&& ! V_6 -> V_268 )
F_247 ( V_6 ,
V_356 ) ;
#endif
if ( V_356 -> V_713 == V_714 ) {
V_27 = F_9 ( V_356 -> V_411 ) ;
F_18 ( & V_6 -> V_72 , V_62 ) ;
V_47 = F_28 ( V_6 , V_27 ) ;
F_21 ( & V_6 -> V_72 , V_62 ) ;
if ( ! V_47 )
return;
if ( V_356 -> V_713 == V_714 )
V_47 -> V_190 =
V_356 -> V_719 ;
}
}
static void
F_249 ( struct V_5 * V_6 )
{
struct V_141 * V_142 ;
struct V_134 * V_135 ;
F_105 (sdev, ioc->shost) {
V_142 = V_135 -> V_146 ;
if ( V_142 && V_142 -> V_148 )
V_142 -> V_148 -> V_381 = 1 ;
}
}
static void
F_250 ( struct V_5 * V_6 , T_1 V_9 ,
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
V_45 -> V_720 = 1 ;
V_165 = V_45 -> V_165 ;
if ( V_165 && V_165 -> V_146 ) {
V_144 = V_165 -> V_146 ;
V_144 -> V_299 = 0 ;
V_144 -> V_381 = 0 ;
} else
V_144 = NULL ;
if ( V_165 )
F_124 ( V_7 , V_165 ,
L_279
L_280
L_281 , V_27 ,
( unsigned long long ) V_45 -> V_9 ,
( unsigned long long )
V_45 -> V_14 ,
V_45 -> V_18 ) ;
if ( V_45 -> V_27 == V_27 )
goto V_71;
F_3 ( V_7 L_282 ,
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
F_251 ( struct V_5 * V_6 )
{
T_8 V_28 ;
T_9 V_29 ;
T_4 V_30 ;
T_40 V_9 ;
T_4 V_27 ;
T_10 V_78 ;
T_4 V_18 ;
F_3 ( V_55 L_283 , V_6 -> V_35 , V_36 ) ;
if ( F_42 ( & V_6 -> V_65 ) )
return;
V_27 = 0xFFFF ;
while ( ! ( F_12 ( V_6 , & V_29 ,
& V_28 , V_721 ,
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
V_18 = F_9 ( V_28 . V_641 ) ;
F_250 ( V_6 , V_9 , V_18 ,
V_27 ) ;
}
}
static void
F_252 ( struct V_5 * V_6 , T_1 V_49 ,
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
V_144 -> V_381 = 0 ;
} else
V_144 = NULL ;
V_47 -> V_720 = 1 ;
F_124 ( V_7 , V_47 -> V_165 ,
L_284 , V_27 ,
( unsigned long long ) V_47 -> V_49 ) ;
F_90 ( V_6 , V_47 ) ;
if ( V_47 -> V_27 == V_27 )
goto V_71;
F_3 ( V_7 L_282 ,
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
F_253 ( struct V_5 * V_6 )
{
T_15 V_722 ;
T_13 V_723 ;
T_14 V_222 ;
T_9 V_29 ;
T_4 V_30 ;
T_4 V_27 ;
T_6 V_724 ;
F_3 ( V_55 L_283 , V_6 -> V_35 , V_36 ) ;
if ( F_42 ( & V_6 -> V_73 ) )
return;
V_27 = 0xFFFF ;
while ( ! ( F_88 ( V_6 , & V_29 ,
& V_722 , V_232 , V_27 ) ) ) {
V_30 = F_9 ( V_29 . V_38 ) &
V_39 ;
if ( V_30 == V_233 )
break;
V_27 = F_9 ( V_722 . V_230 ) ;
if ( F_78 ( V_6 , & V_29 ,
& V_723 , V_191 , V_27 ,
sizeof( T_13 ) ) )
continue;
if ( V_723 . V_200 == V_201 ||
V_723 . V_200 == V_202 ||
V_723 . V_200 == V_204 )
F_252 ( V_6 ,
F_6 ( V_722 . V_725 ) , V_27 ) ;
}
if ( ! V_6 -> V_187 ) {
V_724 = 0xFF ;
memset ( V_6 -> V_174 , 0 , V_6 -> V_726 ) ;
while ( ! ( F_86 ( V_6 , & V_29 ,
& V_222 , V_727 ,
V_724 ) ) ) {
V_30 = F_9 ( V_29 . V_38 ) &
V_39 ;
if ( V_30 == V_233 )
break;
V_724 = V_222 . V_229 ;
V_27 = F_9 ( V_222 . V_230 ) ;
F_240 ( V_27 , V_6 -> V_174 ) ;
}
}
}
static void
F_254 ( struct V_5 * V_6 , T_1 V_9 ,
T_4 V_27 )
{
struct V_74 * V_75 ;
unsigned long V_62 ;
int V_88 ;
F_18 ( & V_6 -> V_76 , V_62 ) ;
F_4 (sas_expander, &ioc->sas_expander_list, list) {
if ( V_75 -> V_9 != V_9 )
continue;
V_75 -> V_720 = 1 ;
if ( V_75 -> V_27 == V_27 )
goto V_71;
F_3 ( V_7 L_285
L_286 ,
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
F_255 ( struct V_5 * V_6 )
{
T_38 V_608 ;
T_9 V_29 ;
T_4 V_30 ;
T_1 V_9 ;
T_4 V_27 ;
F_3 ( V_55 L_283 , V_6 -> V_35 , V_36 ) ;
if ( F_42 ( & V_6 -> V_77 ) )
return;
V_27 = 0xFFFF ;
while ( ! ( F_209 ( V_6 , & V_29 , & V_608 ,
V_728 , V_27 ) ) ) {
V_30 = F_9 ( V_29 . V_38 ) &
V_39 ;
if ( V_30 == V_233 )
break;
V_27 = F_9 ( V_608 . V_230 ) ;
V_9 = F_6 ( V_608 . V_11 ) ;
F_3 ( V_7 L_287
L_102 , V_27 ,
( unsigned long long ) V_9 ) ;
F_254 ( V_6 , V_9 , V_27 ) ;
}
}
static void
F_256 ( struct V_5 * V_6 )
{
struct V_44 * V_45 , * V_729 ;
struct V_74 * V_75 ;
struct V_46 * V_47 , * V_730 ;
F_137 (sas_device, sas_device_next,
&ioc->sas_device_list, list) {
if ( V_45 -> V_720 ) {
V_45 -> V_720 = 0 ;
continue;
}
if ( V_45 -> V_165 )
F_124 ( V_7 , V_45 -> V_165 ,
L_288
L_289 ,
V_45 -> V_27 ,
( unsigned long long ) V_45 -> V_9 ,
( unsigned long long )
V_45 -> V_14 ,
V_45 -> V_18 ) ;
F_220 ( V_6 , V_45 ) ;
}
F_137 (raid_device, raid_device_next,
&ioc->raid_device_list, list) {
if ( V_47 -> V_720 ) {
V_47 -> V_720 = 0 ;
continue;
}
if ( V_47 -> V_165 ) {
F_124 ( V_7 , V_47 -> V_165 ,
L_290 ,
V_47 -> V_27 ,
( unsigned long long ) V_47 -> V_49 ) ;
F_237 ( & V_47 -> V_165 -> V_166 ) ;
}
F_31 ( V_6 , V_47 ) ;
}
V_731:
V_75 = NULL ;
F_4 (sas_expander, &ioc->sas_expander_list, list) {
if ( V_75 -> V_720 ) {
V_75 -> V_720 = 0 ;
continue;
}
F_214 ( V_6 , V_75 -> V_9 ) ;
goto V_731;
}
}
static void
F_257 ( struct V_5 * V_6 )
{
struct V_44 * V_45 , * V_729 ;
if ( ! V_6 -> V_187 || V_6 -> V_242 !=
V_732 )
return;
if ( V_6 -> V_644 ) {
if ( F_89 ( V_6 ) )
return;
V_6 -> V_644 = 0 ;
F_137 (sas_device, sas_device_next,
&ioc->sas_device_list, list) {
if ( ! F_25 ( V_6 , V_45 -> V_27 ,
V_45 -> V_66 ) ) {
F_17 ( V_6 , V_45 ) ;
} else if ( ! V_45 -> V_165 ) {
F_212 ( V_6 ,
V_45 -> V_9 ,
V_45 -> V_66 ) ;
F_17 ( V_6 , V_45 ) ;
}
}
} else {
if ( ! F_89 ( V_6 ) )
return;
V_6 -> V_644 = 1 ;
F_137 (sas_device, sas_device_next,
&ioc->sas_device_list, list) {
F_212 ( V_6 ,
V_45 -> V_9 ,
V_45 -> V_66 ) ;
}
}
}
void
F_258 ( struct V_5 * V_6 , int V_733 )
{
switch ( V_733 ) {
case V_734 :
F_114 ( V_6 , F_3 ( V_55 L_52
L_291 , V_6 -> V_35 , V_36 ) ) ;
break;
case V_735 :
F_114 ( V_6 , F_3 ( V_55 L_52
L_292 , V_6 -> V_35 , V_36 ) ) ;
if ( V_6 -> V_616 . V_291 & V_296 ) {
V_6 -> V_616 . V_291 |= V_332 ;
F_157 ( V_6 , V_6 -> V_616 . V_84 ) ;
F_103 ( & V_6 -> V_616 . V_297 ) ;
}
if ( V_6 -> V_290 . V_291 & V_296 ) {
V_6 -> V_290 . V_291 |= V_332 ;
F_157 ( V_6 , V_6 -> V_290 . V_84 ) ;
F_103 ( & V_6 -> V_290 . V_297 ) ;
}
F_135 ( V_6 ) ;
F_165 ( V_6 ) ;
F_134 ( V_6 ) ;
break;
case V_736 :
F_114 ( V_6 , F_3 ( V_55 L_52
L_293 , V_6 -> V_35 , V_36 ) ) ;
F_198 ( V_6 ) ;
F_249 ( V_6 ) ;
F_251 ( V_6 ) ;
F_253 ( V_6 ) ;
F_255 ( V_6 ) ;
break;
}
}
static void
V_355 ( struct V_737 * V_738 )
{
struct V_349 * V_350 = F_259 ( V_738 ,
struct V_349 , V_354 . V_738 ) ;
unsigned long V_62 ;
struct V_5 * V_6 = V_350 -> V_6 ;
if ( V_6 -> V_314 || V_350 -> V_360 ||
V_6 -> V_315 ) {
F_133 ( V_6 , V_350 ) ;
return;
}
if ( V_350 -> V_358 == V_359 ) {
F_133 ( V_6 , V_350 ) ;
F_18 ( & V_6 -> V_739 , V_62 ) ;
if ( V_6 -> V_313 ) {
F_117 ( & V_6 -> V_740 ) ;
F_21 ( & V_6 -> V_739 ,
V_62 ) ;
F_260 ( & V_6 -> V_740 ) ;
} else
F_21 ( & V_6 -> V_739 ,
V_62 ) ;
F_256 ( V_6 ) ;
F_257 ( V_6 ) ;
return;
}
switch ( V_350 -> V_358 ) {
case V_554 :
F_187 ( V_6 , V_350 -> V_555 ) ;
break;
case V_400 :
F_223 ( V_6 , V_350 ) ;
break;
case V_564 :
F_225 ( V_6 ,
V_350 ) ;
break;
case V_741 :
F_229 ( V_6 ,
V_350 ) ;
break;
case V_742 :
F_228 ( V_6 ,
V_350 ) ;
break;
case V_743 :
F_227 ( V_6 ,
V_350 ) ;
break;
case V_744 :
F_244 ( V_6 , V_350 ) ;
break;
case V_745 :
F_245 ( V_6 , V_350 ) ;
break;
case V_746 :
F_246 ( V_6 , V_350 ) ;
break;
case V_747 :
F_248 ( V_6 , V_350 ) ;
break;
}
F_133 ( V_6 , V_350 ) ;
}
T_6
F_261 ( struct V_5 * V_6 , T_6 V_288 ,
T_10 V_289 )
{
struct V_349 * V_350 ;
T_31 * V_29 ;
T_4 V_358 ;
T_4 V_223 ;
if ( V_6 -> V_314 || V_6 -> V_315 )
return 1 ;
V_29 = F_102 ( V_6 , V_289 ) ;
V_358 = F_9 ( V_29 -> V_563 ) ;
switch ( V_358 ) {
case V_742 :
{
T_42 * V_748 =
( T_42 * )
V_29 -> V_561 ;
if ( V_748 -> V_749 !=
V_750 )
return 1 ;
if ( V_6 -> V_684 ) {
V_6 -> V_683 ++ ;
return 1 ;
} else
V_6 -> V_684 = 1 ;
break;
}
case V_400 :
F_158 ( V_6 ,
( T_22 * )
V_29 -> V_561 ) ;
break;
case V_744 :
F_161 ( V_6 ,
( T_25 * )
V_29 -> V_561 ) ;
break;
case V_745 :
F_164 ( V_6 ,
( T_27 * )
V_29 -> V_561 ) ;
break;
case V_751 :
{
T_46 * V_752 ;
T_10 * V_753 ;
if ( ! V_6 -> V_187 )
break;
V_752 = ( T_46 * )
V_29 -> V_561 ;
V_753 = ( T_10 * ) V_752 -> V_754 ;
if ( F_9 ( V_752 -> V_755 )
!= V_756 )
break;
switch ( F_74 ( * V_753 ) ) {
case V_757 :
F_3 ( V_95 L_294
L_295
L_296
L_297 , V_6 -> V_35 ) ;
break;
case V_758 :
F_3 ( V_95 L_294
L_298
L_299
L_300 , V_6 -> V_35 ) ;
break;
case V_759 :
F_3 ( V_34 L_301
L_302
L_303
L_304
L_300 , V_6 -> V_35 ) ;
break;
case V_760 :
F_3 ( V_34 L_301
L_305
L_306
L_307 ,
V_6 -> V_35 ) ;
break;
}
break;
}
case V_564 :
case V_747 :
case V_741 :
case V_743 :
case V_746 :
break;
default:
return 1 ;
}
V_350 = F_67 ( sizeof( struct V_349 ) , V_357 ) ;
if ( ! V_350 ) {
F_3 ( V_34 L_2 ,
V_6 -> V_35 , __FILE__ , __LINE__ , V_36 ) ;
return 1 ;
}
V_223 = F_9 ( V_29 -> V_565 ) * 4 ;
V_350 -> V_356 = F_67 ( V_223 , V_357 ) ;
if ( ! V_350 -> V_356 ) {
F_3 ( V_34 L_2 ,
V_6 -> V_35 , __FILE__ , __LINE__ , V_36 ) ;
F_20 ( V_350 ) ;
return 1 ;
}
memcpy ( V_350 -> V_356 , V_29 -> V_561 ,
V_223 ) ;
V_350 -> V_6 = V_6 ;
V_350 -> V_497 = V_29 -> V_497 ;
V_350 -> V_498 = V_29 -> V_498 ;
V_350 -> V_358 = V_358 ;
F_130 ( V_6 , V_350 ) ;
return 1 ;
}
static void
F_215 ( struct V_5 * V_6 ,
struct V_74 * V_75 )
{
struct V_362 * V_363 , * V_96 ;
F_137 (mpt2sas_port, next,
&sas_expander->sas_port_list, port_list) {
if ( V_6 -> V_313 )
return;
if ( V_363 -> V_365 . V_366 ==
V_367 )
F_221 ( V_6 ,
V_363 -> V_365 . V_9 ) ;
else if ( V_363 -> V_365 . V_366 ==
V_368 ||
V_363 -> V_365 . V_366 ==
V_369 )
F_214 ( V_6 ,
V_363 -> V_365 . V_9 ) ;
}
F_212 ( V_6 , V_75 -> V_9 ,
V_75 -> V_66 ) ;
F_3 ( V_55 L_308
L_9 , V_6 -> V_35 ,
V_75 -> V_27 , ( unsigned long long )
V_75 -> V_9 ) ;
F_20 ( V_75 -> V_271 ) ;
F_20 ( V_75 ) ;
}
static void
F_262 ( struct V_5 * V_6 )
{
T_47 * V_99 ;
T_48 * V_29 ;
T_4 V_84 ;
if ( ! V_6 -> V_761 )
return;
if ( F_42 ( & V_6 -> V_73 ) )
return;
F_108 ( & V_6 -> V_616 . V_310 ) ;
if ( V_6 -> V_616 . V_291 != V_292 ) {
F_3 ( V_34 L_309 ,
V_6 -> V_35 , V_36 ) ;
goto V_71;
}
V_6 -> V_616 . V_291 = V_296 ;
V_84 = F_155 ( V_6 , V_6 -> V_762 ) ;
if ( ! V_84 ) {
F_3 ( V_34 L_68 ,
V_6 -> V_35 , V_36 ) ;
V_6 -> V_616 . V_291 = V_292 ;
goto V_71;
}
V_99 = F_46 ( V_6 , V_84 ) ;
V_6 -> V_616 . V_84 = V_84 ;
memset ( V_99 , 0 , sizeof( T_47 ) ) ;
V_99 -> V_325 = V_763 ;
V_99 -> V_549 = V_764 ;
if ( ! V_6 -> V_268 )
F_3 ( V_55 L_310 , V_6 -> V_35 ) ;
F_117 ( & V_6 -> V_616 . V_297 ) ;
F_156 ( V_6 , V_84 ) ;
F_119 ( & V_6 -> V_616 . V_297 , 10 * V_331 ) ;
if ( ! ( V_6 -> V_616 . V_291 & V_293 ) ) {
F_3 ( V_34 L_71 ,
V_6 -> V_35 , V_36 ) ;
goto V_71;
}
if ( V_6 -> V_616 . V_291 & V_295 ) {
V_29 = V_6 -> V_616 . V_289 ;
if ( ! V_6 -> V_268 )
F_3 ( V_55 L_311
L_312 ,
V_6 -> V_35 , F_9 ( V_29 -> V_38 ) ,
F_74 ( V_29 -> V_333 ) ) ;
}
V_71:
V_6 -> V_616 . V_291 = V_292 ;
F_121 ( & V_6 -> V_616 . V_310 ) ;
}
static void
F_263 ( struct V_765 * V_558 )
{
struct V_137 * V_138 = F_264 ( V_558 ) ;
struct V_5 * V_6 = F_56 ( V_138 ) ;
struct V_766 * V_767 ;
unsigned long V_62 ;
V_6 -> V_314 = 1 ;
F_135 ( V_6 ) ;
F_18 ( & V_6 -> V_352 , V_62 ) ;
V_767 = V_6 -> V_351 ;
V_6 -> V_351 = NULL ;
F_21 ( & V_6 -> V_352 , V_62 ) ;
if ( V_767 )
F_265 ( V_767 ) ;
F_262 ( V_6 ) ;
F_266 ( V_6 ) ;
}
static void T_49
F_267 ( struct V_765 * V_558 )
{
struct V_137 * V_138 = F_264 ( V_558 ) ;
struct V_5 * V_6 = F_56 ( V_138 ) ;
struct V_362 * V_363 , * V_768 ;
struct V_46 * V_47 , * V_96 ;
struct V_143 * V_144 ;
struct V_766 * V_767 ;
unsigned long V_62 ;
V_6 -> V_314 = 1 ;
F_135 ( V_6 ) ;
F_18 ( & V_6 -> V_352 , V_62 ) ;
V_767 = V_6 -> V_351 ;
V_6 -> V_351 = NULL ;
F_21 ( & V_6 -> V_352 , V_62 ) ;
if ( V_767 )
F_265 ( V_767 ) ;
F_262 ( V_6 ) ;
F_137 (raid_device, next, &ioc->raid_device_list,
list) {
if ( V_47 -> V_165 ) {
V_144 =
V_47 -> V_165 -> V_146 ;
V_144 -> V_381 = 1 ;
F_237 ( & V_47 -> V_165 -> V_166 ) ;
}
F_3 ( V_55 L_255
L_189 , V_6 -> V_35 , V_47 -> V_27 ,
( unsigned long long ) V_47 -> V_49 ) ;
F_31 ( V_6 , V_47 ) ;
}
F_137 (mpt2sas_port, next_port,
&ioc->sas_hba.sas_port_list, port_list) {
if ( V_363 -> V_365 . V_366 ==
V_367 )
F_221 ( V_6 ,
V_363 -> V_365 . V_9 ) ;
else if ( V_363 -> V_365 . V_366 ==
V_368 ||
V_363 -> V_365 . V_366 ==
V_369 )
F_214 ( V_6 ,
V_363 -> V_365 . V_9 ) ;
}
if ( V_6 -> V_31 . V_32 ) {
F_20 ( V_6 -> V_31 . V_271 ) ;
V_6 -> V_31 . V_271 = NULL ;
V_6 -> V_31 . V_32 = 0 ;
}
F_268 ( V_138 ) ;
F_19 ( & V_6 -> V_64 ) ;
F_269 ( V_138 ) ;
F_270 ( V_138 ) ;
}
static void
F_271 ( struct V_5 * V_6 )
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
V_20 = F_235 ( V_6 -> V_138 , V_171 ,
V_47 -> V_68 , 0 ) ;
if ( V_20 )
F_31 ( V_6 , V_47 ) ;
} else {
V_45 = V_42 ;
V_27 = V_45 -> V_27 ;
V_66 = V_45 -> V_66 ;
V_9 = V_45 -> V_9 ;
F_18 ( & V_6 -> V_63 , V_62 ) ;
F_272 ( & V_45 -> V_64 , & V_6 -> V_65 ) ;
F_21 ( & V_6 -> V_63 , V_62 ) ;
if ( V_6 -> V_644 )
return;
if ( ! F_25 ( V_6 , V_45 -> V_27 ,
V_45 -> V_66 ) ) {
F_17 ( V_6 , V_45 ) ;
} else if ( ! V_45 -> V_165 ) {
F_212 ( V_6 , V_9 ,
V_66 ) ;
F_17 ( V_6 , V_45 ) ;
}
}
}
static void
F_273 ( struct V_5 * V_6 )
{
struct V_46 * V_47 , * V_769 ;
int V_20 ;
F_137 (raid_device, raid_next,
&ioc->raid_device_list, list) {
if ( V_47 -> V_165 )
continue;
V_20 = F_235 ( V_6 -> V_138 , V_171 ,
V_47 -> V_68 , 0 ) ;
if ( V_20 )
F_31 ( V_6 , V_47 ) ;
}
}
static void
F_274 ( struct V_5 * V_6 )
{
struct V_44 * V_45 , * V_96 ;
unsigned long V_62 ;
F_137 (sas_device, next, &ioc->sas_device_init_list,
list) {
F_18 ( & V_6 -> V_63 , V_62 ) ;
F_272 ( & V_45 -> V_64 , & V_6 -> V_65 ) ;
F_21 ( & V_6 -> V_63 , V_62 ) ;
if ( V_6 -> V_644 )
continue;
if ( ! F_25 ( V_6 , V_45 -> V_27 ,
V_45 -> V_66 ) ) {
F_17 ( V_6 , V_45 ) ;
} else if ( ! V_45 -> V_165 ) {
F_212 ( V_6 ,
V_45 -> V_9 ,
V_45 -> V_66 ) ;
F_17 ( V_6 , V_45 ) ;
}
}
}
static void
F_275 ( struct V_5 * V_6 )
{
T_4 V_770 =
F_9 ( V_6 -> V_771 . V_772 ) &
V_773 ;
if ( ! ( V_6 -> V_254 . V_774 & V_775 ) )
return;
F_271 ( V_6 ) ;
if ( V_6 -> V_761 ) {
if ( ( V_770 &
V_776 ) ) {
F_274 ( V_6 ) ;
F_273 ( V_6 ) ;
} else {
F_273 ( V_6 ) ;
F_274 ( V_6 ) ;
}
} else
F_274 ( V_6 ) ;
}
static int
F_276 ( struct V_765 * V_558 , const struct V_777 * V_68 )
{
struct V_5 * V_6 ;
struct V_137 * V_138 ;
V_138 = F_277 ( & V_778 ,
sizeof( struct V_5 ) ) ;
if ( ! V_138 )
return - V_779 ;
V_6 = F_56 ( V_138 ) ;
memset ( V_6 , 0 , sizeof( struct V_5 ) ) ;
F_148 ( & V_6 -> V_64 ) ;
F_24 ( & V_6 -> V_64 , & V_780 ) ;
V_6 -> V_138 = V_138 ;
V_6 -> V_68 = V_781 ++ ;
sprintf ( V_6 -> V_35 , L_313 , V_782 , V_6 -> V_68 ) ;
V_6 -> V_558 = V_558 ;
if ( V_68 -> V_42 == V_783 ) {
V_6 -> V_187 = 1 ;
V_6 -> V_268 = 1 ;
} else
V_6 -> V_242 = V_243 ;
V_6 -> V_481 = V_481 ;
V_6 -> V_323 = V_323 ;
V_6 -> V_784 = V_784 ;
V_6 -> V_785 = V_785 ;
V_6 -> V_786 = V_786 ;
V_6 -> V_762 = V_762 ;
V_6 -> V_787 = V_787 ;
V_6 -> V_382 = V_382 ;
V_6 -> V_384 = V_384 ;
V_6 -> V_388 = V_388 ;
V_6 -> V_8 = V_8 ;
F_278 ( & V_6 -> V_788 ) ;
F_279 ( & V_6 -> V_739 ) ;
F_279 ( & V_6 -> V_87 ) ;
F_279 ( & V_6 -> V_63 ) ;
F_279 ( & V_6 -> V_76 ) ;
F_279 ( & V_6 -> V_352 ) ;
F_279 ( & V_6 -> V_72 ) ;
F_148 ( & V_6 -> V_65 ) ;
F_148 ( & V_6 -> V_67 ) ;
F_148 ( & V_6 -> V_77 ) ;
F_148 ( & V_6 -> V_353 ) ;
F_148 ( & V_6 -> V_73 ) ;
F_148 ( & V_6 -> V_31 . V_615 ) ;
F_148 ( & V_6 -> V_383 ) ;
F_148 ( & V_6 -> V_385 ) ;
V_138 -> V_789 = 32 ;
V_138 -> V_790 = V_790 ;
V_138 -> V_791 = V_792 ;
V_138 -> V_793 = V_6 -> V_68 ;
if ( V_794 != 0xFFFF ) {
if ( V_794 < 64 ) {
V_138 -> V_794 = 64 ;
F_3 ( V_95 L_314
L_315
L_316 , V_6 -> V_35 , V_794 ) ;
} else if ( V_794 > 8192 ) {
V_138 -> V_794 = 8192 ;
F_3 ( V_95 L_314
L_315
L_317 , V_6 -> V_35 ,
V_794 ) ;
} else {
V_138 -> V_794 = V_794 & 0xFFFE ;
F_3 ( V_55 L_318
L_319 , V_6 -> V_35 , V_138 -> V_794 ) ;
}
}
if ( ( F_280 ( V_138 , & V_558 -> V_166 ) ) ) {
F_3 ( V_34 L_2 ,
V_6 -> V_35 , __FILE__ , __LINE__ , V_36 ) ;
F_19 ( & V_6 -> V_64 ) ;
goto V_795;
}
F_281 ( V_138 , V_796
| V_797 | V_798 ) ;
F_282 ( V_138 , V_799 ) ;
snprintf ( V_6 -> V_800 , sizeof( V_6 -> V_800 ) ,
L_320 , V_6 -> V_68 ) ;
V_6 -> V_351 = F_283 (
V_6 -> V_800 ) ;
if ( ! V_6 -> V_351 ) {
F_3 ( V_34 L_2 ,
V_6 -> V_35 , __FILE__ , __LINE__ , V_36 ) ;
goto V_801;
}
V_6 -> V_48 = 1 ;
if ( ( F_284 ( V_6 ) ) ) {
F_3 ( V_34 L_2 ,
V_6 -> V_35 , __FILE__ , __LINE__ , V_36 ) ;
goto V_802;
}
V_6 -> V_48 = 0 ;
if ( V_6 -> V_187 ) {
if ( V_6 -> V_242 == V_243 )
V_6 -> V_644 = 0 ;
else if ( V_6 -> V_242 == V_803 )
V_6 -> V_644 = 1 ;
else {
if ( F_89 ( V_6 ) )
V_6 -> V_644 = 1 ;
else
V_6 -> V_644 = 0 ;
}
} else
V_6 -> V_644 = 0 ;
F_275 ( V_6 ) ;
return 0 ;
V_802:
F_265 ( V_6 -> V_351 ) ;
V_801:
F_19 ( & V_6 -> V_64 ) ;
F_269 ( V_138 ) ;
V_795:
return - V_779 ;
}
static int
F_285 ( struct V_765 * V_558 , T_50 V_197 )
{
struct V_137 * V_138 = F_264 ( V_558 ) ;
struct V_5 * V_6 = F_56 ( V_138 ) ;
T_51 V_804 ;
F_286 ( V_6 ) ;
F_287 ( V_138 ) ;
V_804 = F_288 ( V_558 , V_197 ) ;
F_3 ( V_55 L_321
L_322 , V_6 -> V_35 , V_558 ,
F_289 ( V_558 ) , V_804 ) ;
F_290 ( V_6 ) ;
F_291 ( V_558 ) ;
F_292 ( V_558 ) ;
F_293 ( V_558 , V_804 ) ;
return 0 ;
}
static int
F_294 ( struct V_765 * V_558 )
{
struct V_137 * V_138 = F_264 ( V_558 ) ;
struct V_5 * V_6 = F_56 ( V_138 ) ;
T_51 V_804 = V_558 -> V_805 ;
int V_70 ;
F_3 ( V_55 L_323
L_322 , V_6 -> V_35 , V_558 ,
F_289 ( V_558 ) , V_804 ) ;
F_293 ( V_558 , V_806 ) ;
F_295 ( V_558 , V_806 , 0 ) ;
F_296 ( V_558 ) ;
V_6 -> V_558 = V_558 ;
V_70 = F_297 ( V_6 ) ;
if ( V_70 )
return V_70 ;
F_111 ( V_6 , V_317 , V_807 ) ;
F_298 ( V_138 ) ;
F_299 ( V_6 ) ;
return 0 ;
}
static T_52
F_300 ( struct V_765 * V_558 , T_53 V_197 )
{
struct V_137 * V_138 = F_264 ( V_558 ) ;
struct V_5 * V_6 = F_56 ( V_138 ) ;
F_3 ( V_55 L_324 ,
V_6 -> V_35 , V_197 ) ;
switch ( V_197 ) {
case V_808 :
return V_809 ;
case V_810 :
V_6 -> V_315 = 1 ;
F_287 ( V_6 -> V_138 ) ;
F_286 ( V_6 ) ;
F_290 ( V_6 ) ;
return V_811 ;
case V_812 :
V_6 -> V_315 = 1 ;
F_286 ( V_6 ) ;
F_165 ( V_6 ) ;
return V_813 ;
}
return V_811 ;
}
static T_52
F_301 ( struct V_765 * V_558 )
{
struct V_137 * V_138 = F_264 ( V_558 ) ;
struct V_5 * V_6 = F_56 ( V_138 ) ;
int V_20 ;
F_3 ( V_55 L_325 ,
V_6 -> V_35 ) ;
V_6 -> V_315 = 0 ;
V_6 -> V_558 = V_558 ;
F_296 ( V_558 ) ;
V_20 = F_297 ( V_6 ) ;
if ( V_20 )
return V_813 ;
V_20 = F_111 ( V_6 , V_317 ,
V_318 ) ;
F_3 ( V_95 L_326 , V_6 -> V_35 ,
( V_20 == 0 ) ? L_116 : L_327 ) ;
if ( ! V_20 )
return V_814 ;
else
return V_813 ;
}
static void
F_302 ( struct V_765 * V_558 )
{
struct V_137 * V_138 = F_264 ( V_558 ) ;
struct V_5 * V_6 = F_56 ( V_138 ) ;
F_3 ( V_55 L_328 , V_6 -> V_35 ) ;
F_303 ( V_558 ) ;
F_299 ( V_6 ) ;
F_298 ( V_6 -> V_138 ) ;
}
static T_52
F_304 ( struct V_765 * V_558 )
{
struct V_137 * V_138 = F_264 ( V_558 ) ;
struct V_5 * V_6 = F_56 ( V_138 ) ;
F_3 ( V_55 L_329 ,
V_6 -> V_35 ) ;
return V_811 ;
}
static int T_54
F_305 ( void )
{
int error ;
V_781 = 0 ;
F_3 ( V_7 L_330 , V_782 ,
V_815 ) ;
V_792 =
F_306 ( & V_816 ) ;
if ( ! V_792 )
return - V_779 ;
V_194 = F_307 ( & V_817 ) ;
if ( ! V_194 ) {
F_308 ( V_792 ) ;
return - V_779 ;
}
F_309 () ;
V_481 = F_310 ( F_193 ) ;
V_323 = F_310 ( F_101 ) ;
V_785 = F_310 ( V_818 ) ;
V_786 = F_310 (
V_819 ) ;
V_762 = F_310 ( F_213 ) ;
V_787 = F_310 (
V_820 ) ;
V_784 = F_310 ( V_821 ) ;
V_382 = F_310 (
F_154 ) ;
V_384 = F_310 (
F_152 ) ;
V_388 = F_310 (
F_149 ) ;
F_311 () ;
error = F_312 ( & V_822 ) ;
if ( error ) {
F_313 ( V_194 ) ;
F_308 ( V_792 ) ;
}
return error ;
}
static void T_55
F_314 ( void )
{
F_3 ( V_7 L_331 ,
V_815 ) ;
F_315 ( & V_822 ) ;
F_316 () ;
F_317 ( V_481 ) ;
F_317 ( V_323 ) ;
F_317 ( V_785 ) ;
F_317 ( V_786 ) ;
F_317 ( V_762 ) ;
F_317 ( V_787 ) ;
F_317 ( V_784 ) ;
F_317 ( V_382 ) ;
F_317 ( V_384 ) ;
F_317 ( V_388 ) ;
F_313 ( V_194 ) ;
F_308 ( V_792 ) ;
}
