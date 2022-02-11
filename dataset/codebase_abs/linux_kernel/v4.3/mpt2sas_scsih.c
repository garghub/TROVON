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
F_13 ( V_15 L_1 , V_16 ) ;
F_14 ( & V_17 ) ;
F_15 (ioc, &mpt2sas_ioc_list, list)
V_14 -> V_16 = V_16 ;
F_16 ( & V_17 ) ;
return 0 ;
}
static inline int
F_17 ( T_1 V_18 ,
T_2 * V_19 )
{
return ( V_18 == F_18 ( V_19 -> V_20 ) ) ? 1 : 0 ;
}
static inline int
F_19 ( T_1 V_21 ,
T_3 * V_19 )
{
return ( V_21 == F_18 ( V_19 -> V_22 ) ) ? 1 : 0 ;
}
static inline int
F_20 ( T_1 V_23 , T_4 V_24 ,
T_5 * V_19 )
{
return ( V_23 == F_18 ( V_19 ->
V_25 ) && V_24 == F_21 ( V_19 ->
V_26 ) ) ? 1 : 0 ;
}
static int
F_22 ( T_1 V_18 , T_1 V_21 ,
T_1 V_23 , T_4 V_27 , T_6 V_28 ,
T_7 * V_19 )
{
int V_29 = 0 ;
switch ( V_28 ) {
case V_30 :
if ( ! V_18 )
break;
V_29 = F_17 (
V_18 , & V_19 -> V_31 ) ;
break;
case V_32 :
if ( ! V_23 )
break;
V_29 = F_20 (
V_23 ,
V_27 , & V_19 -> V_33 ) ;
break;
case V_34 :
if ( ! V_21 )
break;
V_29 = F_19 (
V_21 , & V_19 -> V_22 ) ;
break;
case V_35 :
break;
}
return V_29 ;
}
static int
F_23 ( struct V_13 * V_14 , T_4 V_36 ,
T_1 * V_18 )
{
T_8 V_37 ;
T_9 V_38 ;
T_10 V_39 ;
* V_18 = 0 ;
if ( V_36 <= V_14 -> V_40 . V_41 ) {
* V_18 = V_14 -> V_40 . V_18 ;
return 0 ;
}
if ( ( F_24 ( V_14 , & V_38 , & V_37 ,
V_42 , V_36 ) ) ) {
F_13 ( V_43 L_2 , V_14 -> V_44 ,
__FILE__ , __LINE__ , V_45 ) ;
return - V_46 ;
}
V_39 = F_21 ( V_38 . V_47 ) & V_48 ;
if ( V_39 == V_49 ) {
* V_18 = F_18 ( V_37 . V_20 ) ;
return 0 ;
}
if ( V_39 == V_50 )
return - V_46 ;
F_13 ( V_43 L_3
L_2 , V_14 -> V_44 , V_36 , V_39 ,
__FILE__ , __LINE__ , V_45 ) ;
return - V_51 ;
}
static void
F_25 ( struct V_13 * V_14 ,
void * V_52 , T_6 V_53 )
{
struct V_54 * V_55 ;
struct V_56 * V_57 ;
T_1 V_18 ;
T_1 V_21 ;
T_1 V_23 ;
T_4 V_27 ;
if ( ! V_14 -> V_58 )
return;
if ( ! V_14 -> V_59 . V_60 )
return;
if ( ! V_53 ) {
V_55 = V_52 ;
V_18 = V_55 -> V_18 ;
V_21 = V_55 -> V_21 ;
V_23 = V_55 -> V_23 ;
V_27 = V_55 -> V_27 ;
} else {
V_57 = V_52 ;
V_18 = V_57 -> V_61 ;
V_21 = 0 ;
V_23 = 0 ;
V_27 = 0 ;
}
if ( ! V_14 -> V_62 . V_52 ) {
if ( F_22 ( V_18 , V_21 ,
V_23 , V_27 ,
( V_14 -> V_63 . V_64 &
V_65 ) ,
& V_14 -> V_63 . V_66 ) ) {
F_26 ( V_14 , F_13 ( V_67
L_4 ,
V_14 -> V_44 , V_45 ,
( unsigned long long ) V_18 ) ) ;
V_14 -> V_62 . V_52 = V_52 ;
V_14 -> V_62 . V_53 = V_53 ;
}
}
if ( ! V_14 -> V_68 . V_52 ) {
if ( F_22 ( V_18 , V_21 ,
V_23 , V_27 ,
( V_14 -> V_63 . V_69 &
V_65 ) ,
& V_14 -> V_63 . V_70 ) ) {
F_26 ( V_14 , F_13 ( V_67
L_5 ,
V_14 -> V_44 , V_45 ,
( unsigned long long ) V_18 ) ) ;
V_14 -> V_68 . V_52 = V_52 ;
V_14 -> V_68 . V_53 = V_53 ;
}
}
if ( ! V_14 -> V_71 . V_52 ) {
if ( F_22 ( V_18 , V_21 ,
V_23 , V_27 ,
( V_14 -> V_63 . V_72 &
V_65 ) ,
& V_14 -> V_63 . V_73 ) ) {
F_26 ( V_14 , F_13 ( V_67
L_6 ,
V_14 -> V_44 , V_45 ,
( unsigned long long ) V_18 ) ) ;
V_14 -> V_71 . V_52 = V_52 ;
V_14 -> V_71 . V_53 = V_53 ;
}
}
}
static struct V_54 *
F_27 ( struct V_13 * V_14 ,
struct V_74 * V_75 )
{
struct V_54 * V_12 ;
F_28 ( & V_14 -> V_76 ) ;
V_12 = V_75 -> V_77 ;
if ( V_12 )
F_29 ( V_12 ) ;
return V_12 ;
}
static struct V_54 *
F_30 ( struct V_13 * V_14 ,
struct V_74 * V_75 )
{
struct V_54 * V_12 ;
unsigned long V_78 ;
F_31 ( & V_14 -> V_76 , V_78 ) ;
V_12 = F_27 ( V_14 , V_75 ) ;
F_32 ( & V_14 -> V_76 , V_78 ) ;
return V_12 ;
}
struct V_54 *
F_33 ( struct V_13 * V_14 ,
T_1 V_18 )
{
struct V_54 * V_55 ;
F_28 ( & V_14 -> V_76 ) ;
F_15 (sas_device, &ioc->sas_device_list, list)
if ( V_55 -> V_18 == V_18 )
goto V_79;
F_15 (sas_device, &ioc->sas_device_init_list, list)
if ( V_55 -> V_18 == V_18 )
goto V_79;
return NULL ;
V_79:
F_29 ( V_55 ) ;
return V_55 ;
}
struct V_54 *
F_34 ( struct V_13 * V_14 ,
T_1 V_18 )
{
struct V_54 * V_55 ;
unsigned long V_78 ;
F_31 ( & V_14 -> V_76 , V_78 ) ;
V_55 = F_33 ( V_14 ,
V_18 ) ;
F_32 ( & V_14 -> V_76 , V_78 ) ;
return V_55 ;
}
static struct V_54 *
F_35 ( struct V_13 * V_14 , T_4 V_36 )
{
struct V_54 * V_55 ;
F_28 ( & V_14 -> V_76 ) ;
F_15 (sas_device, &ioc->sas_device_list, list)
if ( V_55 -> V_36 == V_36 )
goto V_79;
F_15 (sas_device, &ioc->sas_device_init_list, list)
if ( V_55 -> V_36 == V_36 )
goto V_79;
return NULL ;
V_79:
F_29 ( V_55 ) ;
return V_55 ;
}
static struct V_54 *
F_36 ( struct V_13 * V_14 , T_4 V_36 )
{
struct V_54 * V_55 ;
unsigned long V_78 ;
F_31 ( & V_14 -> V_76 , V_78 ) ;
V_55 = F_35 ( V_14 , V_36 ) ;
F_32 ( & V_14 -> V_76 , V_78 ) ;
return V_55 ;
}
static void
F_37 ( struct V_13 * V_14 ,
struct V_54 * V_55 )
{
unsigned long V_78 ;
if ( ! V_55 )
return;
F_31 ( & V_14 -> V_76 , V_78 ) ;
if ( ! F_38 ( & V_55 -> V_80 ) ) {
F_39 ( & V_55 -> V_80 ) ;
F_40 ( V_55 ) ;
}
F_32 ( & V_14 -> V_76 , V_78 ) ;
}
static void
F_41 ( struct V_13 * V_14 ,
struct V_54 * V_55 )
{
unsigned long V_78 ;
F_42 ( V_14 , F_13 ( V_67 L_7
L_8 , V_14 -> V_44 , V_45 ,
V_55 -> V_36 , ( unsigned long long ) V_55 -> V_18 ) ) ;
F_31 ( & V_14 -> V_76 , V_78 ) ;
F_29 ( V_55 ) ;
F_43 ( & V_55 -> V_80 , & V_14 -> V_81 ) ;
F_32 ( & V_14 -> V_76 , V_78 ) ;
if ( ! F_44 ( V_14 , V_55 -> V_36 ,
V_55 -> V_82 ) ) {
F_37 ( V_14 , V_55 ) ;
} else if ( ! V_55 -> V_83 ) {
if ( ! V_14 -> V_58 ) {
F_45 ( V_14 ,
V_55 -> V_18 ,
V_55 -> V_82 ) ;
F_37 ( V_14 , V_55 ) ;
}
}
}
static void
F_46 ( struct V_13 * V_14 ,
struct V_54 * V_55 )
{
unsigned long V_78 ;
F_42 ( V_14 , F_13 ( V_67 L_7
L_8 , V_14 -> V_44 , V_45 ,
V_55 -> V_36 , ( unsigned long long ) V_55 -> V_18 ) ) ;
F_31 ( & V_14 -> V_76 , V_78 ) ;
F_29 ( V_55 ) ;
F_43 ( & V_55 -> V_80 , & V_14 -> V_84 ) ;
F_25 ( V_14 , V_55 , 0 ) ;
F_32 ( & V_14 -> V_76 , V_78 ) ;
}
static struct V_56 *
F_47 ( struct V_13 * V_14 , int V_85 , int V_86 )
{
struct V_56 * V_57 , * V_2 ;
V_2 = NULL ;
F_15 (raid_device, &ioc->raid_device_list, list) {
if ( V_57 -> V_85 == V_85 && V_57 -> V_86 == V_86 ) {
V_2 = V_57 ;
goto V_87;
}
}
V_87:
return V_2 ;
}
static struct V_56 *
F_48 ( struct V_13 * V_14 , T_4 V_36 )
{
struct V_56 * V_57 , * V_2 ;
V_2 = NULL ;
F_15 (raid_device, &ioc->raid_device_list, list) {
if ( V_57 -> V_36 != V_36 )
continue;
V_2 = V_57 ;
goto V_87;
}
V_87:
return V_2 ;
}
static struct V_56 *
F_49 ( struct V_13 * V_14 , T_1 V_61 )
{
struct V_56 * V_57 , * V_2 ;
V_2 = NULL ;
F_15 (raid_device, &ioc->raid_device_list, list) {
if ( V_57 -> V_61 != V_61 )
continue;
V_2 = V_57 ;
goto V_87;
}
V_87:
return V_2 ;
}
static void
F_50 ( struct V_13 * V_14 ,
struct V_56 * V_57 )
{
unsigned long V_78 ;
F_42 ( V_14 , F_13 ( V_67 L_7
L_9 , V_14 -> V_44 , V_45 ,
V_57 -> V_36 , ( unsigned long long ) V_57 -> V_61 ) ) ;
F_31 ( & V_14 -> V_88 , V_78 ) ;
F_43 ( & V_57 -> V_80 , & V_14 -> V_89 ) ;
F_32 ( & V_14 -> V_88 , V_78 ) ;
}
static void
F_51 ( struct V_13 * V_14 ,
struct V_56 * V_57 )
{
unsigned long V_78 ;
F_31 ( & V_14 -> V_88 , V_78 ) ;
F_52 ( & V_57 -> V_80 ) ;
F_2 ( V_57 ) ;
F_32 ( & V_14 -> V_88 , V_78 ) ;
}
struct V_90 *
F_53 ( struct V_13 * V_14 , T_4 V_36 )
{
struct V_90 * V_91 , * V_2 ;
V_2 = NULL ;
F_15 (sas_expander, &ioc->sas_expander_list, list) {
if ( V_91 -> V_36 != V_36 )
continue;
V_2 = V_91 ;
goto V_87;
}
V_87:
return V_2 ;
}
struct V_90 *
F_54 ( struct V_13 * V_14 ,
T_1 V_18 )
{
struct V_90 * V_91 , * V_2 ;
V_2 = NULL ;
F_15 (sas_expander, &ioc->sas_expander_list, list) {
if ( V_91 -> V_18 != V_18 )
continue;
V_2 = V_91 ;
goto V_87;
}
V_87:
return V_2 ;
}
static void
F_55 ( struct V_13 * V_14 ,
struct V_90 * V_91 )
{
unsigned long V_78 ;
F_31 ( & V_14 -> V_92 , V_78 ) ;
F_43 ( & V_91 -> V_80 , & V_14 -> V_93 ) ;
F_32 ( & V_14 -> V_92 , V_78 ) ;
}
static int
F_56 ( T_10 V_94 )
{
if ( V_94 & V_95 &&
( ( V_94 & V_96 ) |
( V_94 & V_97 ) |
( V_94 & V_98 ) ) )
return 1 ;
else
return 0 ;
}
static struct V_99 *
F_57 ( struct V_13 * V_14 , T_4 V_100 )
{
return V_14 -> V_101 [ V_100 - 1 ] . V_102 ;
}
static inline struct V_99 *
F_58 ( struct V_13 * V_14 , T_4 V_100 )
{
unsigned long V_78 ;
struct V_99 * V_102 ;
F_31 ( & V_14 -> V_103 , V_78 ) ;
V_102 = V_14 -> V_101 [ V_100 - 1 ] . V_102 ;
V_14 -> V_101 [ V_100 - 1 ] . V_102 = NULL ;
F_32 ( & V_14 -> V_103 , V_78 ) ;
return V_102 ;
}
static T_4
F_59 ( struct V_13 * V_14 , struct V_99
* V_102 )
{
T_4 V_100 ;
unsigned long V_78 ;
int V_104 ;
F_31 ( & V_14 -> V_103 , V_78 ) ;
V_100 = 0 ;
for ( V_104 = 0 ; V_104 < V_14 -> V_105 ; V_104 ++ ) {
if ( V_14 -> V_101 [ V_104 ] . V_102 == V_102 ) {
V_100 = V_14 -> V_101 [ V_104 ] . V_100 ;
goto V_87;
}
}
V_87:
F_32 ( & V_14 -> V_103 , V_78 ) ;
return V_100 ;
}
static T_6
F_60 ( struct V_13 * V_14 , int V_85 ,
int V_86 )
{
T_6 V_106 ;
unsigned long V_78 ;
int V_104 ;
F_31 ( & V_14 -> V_103 , V_78 ) ;
V_106 = 0 ;
for ( V_104 = 0 ; V_104 < V_14 -> V_105 ; V_104 ++ ) {
if ( V_14 -> V_101 [ V_104 ] . V_102 &&
( V_14 -> V_101 [ V_104 ] . V_102 -> V_52 -> V_85 == V_85 &&
V_14 -> V_101 [ V_104 ] . V_102 -> V_52 -> V_86 == V_86 ) ) {
V_106 = 1 ;
goto V_87;
}
}
V_87:
F_32 ( & V_14 -> V_103 , V_78 ) ;
return V_106 ;
}
static T_6
F_61 ( struct V_13 * V_14 , int V_85 ,
unsigned int V_107 , int V_86 )
{
T_6 V_106 ;
unsigned long V_78 ;
int V_104 ;
F_31 ( & V_14 -> V_103 , V_78 ) ;
V_106 = 0 ;
for ( V_104 = 0 ; V_104 < V_14 -> V_105 ; V_104 ++ ) {
if ( V_14 -> V_101 [ V_104 ] . V_102 &&
( V_14 -> V_101 [ V_104 ] . V_102 -> V_52 -> V_85 == V_85 &&
V_14 -> V_101 [ V_104 ] . V_102 -> V_52 -> V_86 == V_86 &&
V_14 -> V_101 [ V_104 ] . V_102 -> V_52 -> V_107 == V_107 ) ) {
V_106 = 1 ;
goto V_87;
}
}
V_87:
F_32 ( & V_14 -> V_103 , V_78 ) ;
return V_106 ;
}
static struct V_108 *
F_62 ( struct V_13 * V_14 , T_4 V_100 )
{
struct V_108 * V_109 ;
unsigned long V_78 ;
F_31 ( & V_14 -> V_103 , V_78 ) ;
if ( F_38 ( & V_14 -> V_110 ) ) {
F_32 ( & V_14 -> V_103 , V_78 ) ;
F_63 ( V_14 , F_13 ( V_111 L_10
L_11 , V_14 -> V_44 ) ) ;
return NULL ;
}
V_109 = F_64 ( V_14 -> V_110 . V_112 ,
struct V_108 , V_113 ) ;
F_39 ( & V_109 -> V_113 ) ;
F_43 ( & V_109 -> V_113 ,
& V_14 -> V_101 [ V_100 - 1 ] . V_114 ) ;
F_32 ( & V_14 -> V_103 , V_78 ) ;
return V_109 ;
}
static int
F_65 ( struct V_13 * V_14 ,
struct V_99 * V_102 , T_4 V_100 )
{
T_11 * V_115 ;
T_12 V_116 ;
struct V_117 * V_118 ;
void * V_119 , * V_120 ;
T_10 V_121 ;
T_10 V_122 ;
T_10 V_123 ;
int V_124 ;
T_10 V_125 ;
T_10 V_126 ;
T_10 V_127 ;
T_10 V_128 ;
struct V_108 * V_109 ;
V_115 = F_66 ( V_14 , V_100 ) ;
V_126 = V_129 ;
if ( V_102 -> V_130 == V_131 )
V_126 |= V_132 ;
V_127 = ( V_126 | V_133 )
<< V_134 ;
V_128 = ( V_126 | V_133 |
V_135 | V_136 )
<< V_134 ;
V_126 = V_126 << V_134 ;
V_118 = F_67 ( V_102 ) ;
V_124 = F_68 ( V_102 ) ;
if ( V_124 < 0 ) {
F_69 ( V_137 , V_102 -> V_52 , L_12
L_13 , F_70 ( V_102 ) ) ;
return - V_138 ;
}
V_119 = & V_115 -> V_139 ;
V_125 = V_14 -> V_140 ;
if ( V_124 <= V_125 )
goto V_141;
V_115 -> V_142 = ( F_71 ( T_11 , V_139 ) +
( V_125 * V_14 -> V_143 ) ) / 4 ;
while ( V_125 ) {
if ( V_125 == 1 )
V_14 -> V_144 ( V_119 ,
V_127 | F_72 ( V_118 ) ,
F_73 ( V_118 ) ) ;
else
V_14 -> V_144 ( V_119 , V_126 |
F_72 ( V_118 ) , F_73 ( V_118 ) ) ;
V_118 = F_74 ( V_118 ) ;
V_119 += V_14 -> V_143 ;
V_124 -- ;
V_125 -- ;
}
V_123 = V_145 << V_134 ;
V_109 = F_62 ( V_14 , V_100 ) ;
if ( ! V_109 )
return - 1 ;
V_120 = V_109 -> V_146 ;
V_116 = V_109 -> V_147 ;
do {
V_125 = ( V_124 <=
V_14 -> V_148 ) ? V_124 :
V_14 -> V_148 ;
V_121 = ( V_124 == V_125 ) ?
0 : ( V_125 * V_14 -> V_143 ) / 4 ;
V_122 = V_125 * V_14 -> V_143 ;
if ( V_121 ) {
V_121 = V_121 <<
V_149 ;
V_122 += V_14 -> V_143 ;
}
V_14 -> V_144 ( V_119 , V_123 | V_121 |
V_122 , V_116 ) ;
V_119 = V_120 ;
if ( ! V_121 )
goto V_141;
while ( V_125 ) {
if ( V_125 == 1 )
V_14 -> V_144 ( V_119 ,
V_127 |
F_72 ( V_118 ) ,
F_73 ( V_118 ) ) ;
else
V_14 -> V_144 ( V_119 , V_126 |
F_72 ( V_118 ) ,
F_73 ( V_118 ) ) ;
V_118 = F_74 ( V_118 ) ;
V_119 += V_14 -> V_143 ;
V_124 -- ;
V_125 -- ;
}
V_109 = F_62 ( V_14 , V_100 ) ;
if ( ! V_109 )
return - 1 ;
V_120 = V_109 -> V_146 ;
V_116 = V_109 -> V_147 ;
} while ( 1 );
V_141:
while ( V_124 ) {
if ( V_124 == 1 )
V_14 -> V_144 ( V_119 , V_128 |
F_72 ( V_118 ) , F_73 ( V_118 ) ) ;
else
V_14 -> V_144 ( V_119 , V_126 |
F_72 ( V_118 ) , F_73 ( V_118 ) ) ;
V_118 = F_74 ( V_118 ) ;
V_119 += V_14 -> V_143 ;
V_124 -- ;
}
return 0 ;
}
static int
F_75 ( struct V_150 * V_77 , int V_151 )
{
struct V_152 * V_153 = V_77 -> V_154 ;
int V_155 ;
struct V_13 * V_14 = F_76 ( V_153 ) ;
struct V_156 * V_157 ;
struct V_74 * V_158 ;
struct V_54 * V_55 ;
unsigned long V_78 ;
V_155 = V_153 -> V_159 ;
V_157 = V_77 -> V_160 ;
if ( ! V_157 )
goto V_161;
V_158 = V_157 -> V_162 ;
if ( ! V_158 )
goto V_161;
if ( ( V_158 -> V_78 & V_163 ) )
goto V_161;
F_31 ( & V_14 -> V_76 , V_78 ) ;
V_55 = F_27 ( V_14 , V_158 ) ;
if ( V_55 ) {
if ( V_55 -> V_94 & V_98 )
V_155 = V_164 ;
F_40 ( V_55 ) ;
}
F_32 ( & V_14 -> V_76 , V_78 ) ;
V_161:
if ( ! V_77 -> V_165 )
V_155 = 1 ;
if ( V_151 > V_155 )
V_151 = V_155 ;
return F_77 ( V_77 , V_151 ) ;
}
static int
F_78 ( struct V_166 * V_83 )
{
struct V_152 * V_153 = F_79 ( & V_83 -> V_167 ) ;
struct V_13 * V_14 = F_76 ( V_153 ) ;
struct V_74 * V_158 ;
struct V_54 * V_55 ;
struct V_56 * V_57 ;
unsigned long V_78 ;
struct V_168 * V_169 ;
V_158 = F_9 ( sizeof( * V_158 ) ,
V_170 ) ;
if ( ! V_158 )
return - V_138 ;
V_83 -> V_160 = V_158 ;
V_158 -> V_83 = V_83 ;
V_158 -> V_36 = V_171 ;
if ( V_83 -> V_86 == V_172 ) {
F_31 ( & V_14 -> V_88 , V_78 ) ;
V_57 = F_47 ( V_14 , V_83 -> V_85 ,
V_83 -> V_86 ) ;
if ( V_57 ) {
V_158 -> V_36 = V_57 -> V_36 ;
V_158 -> V_18 = V_57 -> V_61 ;
V_158 -> V_78 |= V_163 ;
if ( V_14 -> V_173 )
V_158 -> V_57 = V_57 ;
V_57 -> V_83 = V_83 ;
}
F_32 ( & V_14 -> V_88 , V_78 ) ;
return 0 ;
}
F_31 ( & V_14 -> V_76 , V_78 ) ;
V_169 = F_80 ( V_83 -> V_167 . V_174 ) ;
V_55 = F_33 ( V_14 ,
V_169 -> V_175 . V_18 ) ;
if ( V_55 ) {
V_158 -> V_36 = V_55 -> V_36 ;
V_158 -> V_18 = V_55 -> V_18 ;
V_158 -> V_77 = V_55 ;
V_55 -> V_83 = V_83 ;
V_55 -> V_85 = V_83 -> V_85 ;
V_55 -> V_86 = V_83 -> V_86 ;
if ( F_81 ( V_55 -> V_36 , V_14 -> V_176 ) )
V_158 -> V_78 |=
V_177 ;
}
F_32 ( & V_14 -> V_76 , V_78 ) ;
return 0 ;
}
static void
F_82 ( struct V_166 * V_83 )
{
struct V_152 * V_153 = F_79 ( & V_83 -> V_167 ) ;
struct V_13 * V_14 = F_76 ( V_153 ) ;
struct V_74 * V_158 ;
struct V_54 * V_55 ;
struct V_56 * V_57 ;
unsigned long V_78 ;
struct V_168 * V_169 ;
V_158 = V_83 -> V_160 ;
if ( ! V_158 )
return;
if ( V_83 -> V_86 == V_172 ) {
F_31 ( & V_14 -> V_88 , V_78 ) ;
V_57 = F_47 ( V_14 , V_83 -> V_85 ,
V_83 -> V_86 ) ;
if ( V_57 ) {
V_57 -> V_83 = NULL ;
V_57 -> V_77 = NULL ;
}
F_32 ( & V_14 -> V_88 , V_78 ) ;
goto V_87;
}
F_31 ( & V_14 -> V_76 , V_78 ) ;
V_169 = F_80 ( V_83 -> V_167 . V_174 ) ;
V_55 = F_27 ( V_14 , V_158 ) ;
if ( V_55 && ( V_55 -> V_83 == V_83 ) &&
( V_55 -> V_85 == V_83 -> V_85 ) &&
( V_55 -> V_86 == V_83 -> V_86 ) )
V_55 -> V_83 = NULL ;
if ( V_55 ) {
V_158 -> V_77 = NULL ;
F_40 ( V_55 ) ;
F_40 ( V_55 ) ;
}
F_32 ( & V_14 -> V_76 , V_78 ) ;
V_87:
F_2 ( V_158 ) ;
V_83 -> V_160 = NULL ;
}
static int
F_83 ( struct V_150 * V_77 )
{
struct V_152 * V_153 ;
struct V_13 * V_14 ;
struct V_74 * V_158 ;
struct V_156 * V_157 ;
struct V_166 * V_83 ;
struct V_56 * V_57 ;
struct V_54 * V_55 ;
unsigned long V_78 ;
V_157 = F_9 ( sizeof( * V_157 ) ,
V_170 ) ;
if ( ! V_157 )
return - V_138 ;
V_157 -> V_107 = V_77 -> V_107 ;
V_157 -> V_78 = V_178 ;
V_83 = V_166 ( V_77 ) ;
V_158 = V_83 -> V_160 ;
V_158 -> V_179 ++ ;
V_157 -> V_162 = V_158 ;
V_77 -> V_160 = V_157 ;
if ( ( V_158 -> V_78 & V_177 ) )
V_77 -> V_180 = 1 ;
V_153 = F_79 ( & V_83 -> V_167 ) ;
V_14 = F_76 ( V_153 ) ;
if ( V_83 -> V_86 == V_172 ) {
F_31 ( & V_14 -> V_88 , V_78 ) ;
V_57 = F_47 ( V_14 ,
V_83 -> V_85 , V_83 -> V_86 ) ;
if ( V_57 )
V_57 -> V_77 = V_77 ;
F_32 ( & V_14 -> V_88 , V_78 ) ;
}
if ( ! ( V_158 -> V_78 & V_163 ) ) {
F_31 ( & V_14 -> V_76 , V_78 ) ;
V_55 = F_33 ( V_14 ,
V_158 -> V_18 ) ;
if ( V_55 && ( V_55 -> V_83 == NULL ) ) {
F_69 ( V_15 , V_77 ,
L_14 ,
V_45 , __LINE__ ) ;
V_55 -> V_83 = V_83 ;
}
if ( V_55 )
F_40 ( V_55 ) ;
F_32 ( & V_14 -> V_76 , V_78 ) ;
}
return 0 ;
}
static void
F_84 ( struct V_150 * V_77 )
{
struct V_74 * V_158 ;
struct V_166 * V_83 ;
struct V_152 * V_153 ;
struct V_13 * V_14 ;
struct V_54 * V_55 ;
unsigned long V_78 ;
if ( ! V_77 -> V_160 )
return;
V_83 = V_166 ( V_77 ) ;
V_158 = V_83 -> V_160 ;
V_158 -> V_179 -- ;
V_153 = F_79 ( & V_83 -> V_167 ) ;
V_14 = F_76 ( V_153 ) ;
if ( ! ( V_158 -> V_78 & V_163 ) ) {
F_31 ( & V_14 -> V_76 , V_78 ) ;
V_55 = F_27 ( V_14 ,
V_158 ) ;
if ( V_55 && ! V_158 -> V_179 )
V_55 -> V_83 = NULL ;
if ( V_55 )
F_40 ( V_55 ) ;
F_32 ( & V_14 -> V_76 , V_78 ) ;
}
F_2 ( V_77 -> V_160 ) ;
V_77 -> V_160 = NULL ;
}
static void
F_85 ( struct V_13 * V_14 ,
T_4 V_36 , struct V_150 * V_77 )
{
T_9 V_38 ;
T_8 V_37 ;
T_10 V_39 ;
T_4 V_78 ;
T_10 V_94 ;
if ( ( F_24 ( V_14 , & V_38 , & V_37 ,
V_42 , V_36 ) ) ) {
F_13 ( V_43 L_2 ,
V_14 -> V_44 , __FILE__ , __LINE__ , V_45 ) ;
return;
}
V_39 = F_21 ( V_38 . V_47 ) &
V_48 ;
if ( V_39 != V_49 ) {
F_13 ( V_43 L_2 ,
V_14 -> V_44 , __FILE__ , __LINE__ , V_45 ) ;
return;
}
V_78 = F_21 ( V_37 . V_181 ) ;
V_94 = F_86 ( V_37 . V_182 ) ;
F_69 ( V_15 , V_77 ,
L_15
L_16 ,
( V_94 & V_183 ) ? L_17 : L_18 ,
( V_78 & V_184 ) ? L_17 : L_18 ,
( V_78 & V_185 ) ? L_17 :
L_18 ,
( V_78 & V_186 ) ? L_17 : L_18 ,
( V_78 & V_187 ) ? L_17 : L_18 ,
( V_78 & V_188 ) ? L_17 : L_18 ) ;
}
static int
F_87 ( struct V_52 * V_167 )
{
struct V_150 * V_77 = F_88 ( V_167 ) ;
struct V_13 * V_14 = F_76 ( V_77 -> V_154 ) ;
if ( V_14 -> V_173 )
return 0 ;
return ( V_77 -> V_86 == V_172 ) ? 1 : 0 ;
}
static void
F_89 ( struct V_52 * V_167 )
{
struct V_150 * V_77 = F_88 ( V_167 ) ;
struct V_13 * V_14 = F_76 ( V_77 -> V_154 ) ;
static struct V_56 * V_57 ;
unsigned long V_78 ;
T_13 V_189 ;
T_9 V_38 ;
T_10 V_190 ;
T_6 V_191 ;
T_4 V_36 ;
V_191 = 0 ;
V_36 = 0 ;
if ( V_14 -> V_173 )
goto V_87;
F_31 ( & V_14 -> V_88 , V_78 ) ;
V_57 = F_47 ( V_14 , V_77 -> V_85 ,
V_77 -> V_86 ) ;
if ( V_57 ) {
V_36 = V_57 -> V_36 ;
V_191 = V_57 -> V_191 ;
}
F_32 ( & V_14 -> V_88 , V_78 ) ;
if ( ! V_36 )
goto V_87;
if ( F_90 ( V_14 , & V_38 , & V_189 ,
V_192 , V_36 ,
sizeof( T_13 ) ) ) {
F_13 ( V_43 L_2 ,
V_14 -> V_44 , __FILE__ , __LINE__ , V_45 ) ;
V_191 = 0 ;
goto V_87;
}
V_190 = F_86 ( V_189 . V_193 ) ;
if ( ! ( V_190 &
V_194 ) )
V_191 = 0 ;
V_87:
F_91 ( V_195 , V_167 , V_191 ) ;
}
static void
F_92 ( struct V_52 * V_167 )
{
struct V_150 * V_77 = F_88 ( V_167 ) ;
struct V_13 * V_14 = F_76 ( V_77 -> V_154 ) ;
static struct V_56 * V_57 ;
unsigned long V_78 ;
T_13 V_189 ;
T_9 V_38 ;
T_10 V_196 ;
enum V_197 V_198 = V_199 ;
T_4 V_36 = 0 ;
F_31 ( & V_14 -> V_88 , V_78 ) ;
V_57 = F_47 ( V_14 , V_77 -> V_85 ,
V_77 -> V_86 ) ;
if ( V_57 )
V_36 = V_57 -> V_36 ;
F_32 ( & V_14 -> V_88 , V_78 ) ;
if ( ! V_57 )
goto V_87;
if ( F_90 ( V_14 , & V_38 , & V_189 ,
V_192 , V_36 ,
sizeof( T_13 ) ) ) {
F_13 ( V_43 L_2 ,
V_14 -> V_44 , __FILE__ , __LINE__ , V_45 ) ;
goto V_87;
}
V_196 = F_86 ( V_189 . V_193 ) ;
if ( V_196 & V_194 ) {
V_198 = V_200 ;
goto V_87;
}
switch ( V_189 . V_201 ) {
case V_202 :
case V_203 :
V_198 = V_204 ;
break;
case V_205 :
V_198 = V_206 ;
break;
case V_207 :
case V_208 :
V_198 = V_209 ;
break;
}
V_87:
F_93 ( V_195 , V_167 , V_198 ) ;
}
static void
F_94 ( struct V_150 * V_77 , T_6 V_210 )
{
enum V_211 V_212 = V_213 ;
switch ( V_210 ) {
case V_214 :
V_212 = V_215 ;
break;
case V_216 :
V_212 = V_217 ;
break;
case V_218 :
V_212 = V_219 ;
break;
case V_220 :
V_212 = V_221 ;
break;
}
F_95 ( V_195 , & V_77 -> V_222 , V_212 ) ;
}
static int
F_96 ( struct V_13 * V_14 ,
struct V_56 * V_57 )
{
T_13 * V_189 ;
T_14 V_223 ;
T_8 V_37 ;
T_9 V_38 ;
T_4 V_224 ;
T_6 V_225 ;
if ( ( F_97 ( V_14 , V_57 -> V_36 ,
& V_225 ) ) || ! V_225 ) {
F_63 ( V_14 , F_13 ( V_111
L_2 , V_14 -> V_44 , __FILE__ , __LINE__ ,
V_45 ) ) ;
return 1 ;
}
V_57 -> V_225 = V_225 ;
V_224 = F_71 ( T_13 , V_226 ) + ( V_225 *
sizeof( V_227 ) ) ;
V_189 = F_9 ( V_224 , V_170 ) ;
if ( ! V_189 ) {
F_63 ( V_14 , F_13 ( V_111
L_2 , V_14 -> V_44 , __FILE__ , __LINE__ ,
V_45 ) ) ;
return 1 ;
}
if ( ( F_90 ( V_14 , & V_38 , V_189 ,
V_192 , V_57 -> V_36 , V_224 ) ) ) {
F_63 ( V_14 , F_13 ( V_111
L_2 , V_14 -> V_44 , __FILE__ , __LINE__ ,
V_45 ) ) ;
F_2 ( V_189 ) ;
return 1 ;
}
V_57 -> V_210 = V_189 -> V_228 ;
if ( ! ( F_98 ( V_14 , & V_38 ,
& V_223 , V_229 ,
V_189 -> V_226 [ 0 ] . V_230 ) ) ) {
if ( ! ( F_24 ( V_14 , & V_38 ,
& V_37 , V_42 ,
F_21 ( V_223 . V_231 ) ) ) ) {
V_57 -> V_94 =
F_86 ( V_37 . V_182 ) ;
}
}
F_2 ( V_189 ) ;
return 0 ;
}
static void
F_99 ( struct V_13 * V_14 )
{
T_15 V_232 ;
T_9 V_38 ;
struct V_56 * V_57 ;
T_4 V_36 ;
T_4 V_39 ;
unsigned long V_78 ;
V_36 = 0xFFFF ;
while ( ! ( F_100 ( V_14 , & V_38 ,
& V_232 , V_233 , V_36 ) ) ) {
V_39 = F_21 ( V_38 . V_47 ) &
V_48 ;
if ( V_39 == V_50 )
break;
V_36 = F_21 ( V_232 . V_231 ) ;
F_31 ( & V_14 -> V_88 , V_78 ) ;
V_57 = F_48 ( V_14 , V_36 ) ;
if ( V_57 )
V_57 -> V_234 = 0 ;
F_32 ( & V_14 -> V_88 , V_78 ) ;
}
return;
}
static T_6
F_101 ( struct V_13 * V_14 )
{
T_15 V_232 ;
T_9 V_38 ;
T_4 V_36 ;
T_6 V_235 = 0 ;
T_4 V_39 ;
V_36 = 0xFFFF ;
while ( ! ( F_100 ( V_14 , & V_38 ,
& V_232 , V_233 , V_36 ) ) ) {
V_39 = F_21 ( V_38 . V_47 ) &
V_48 ;
if ( V_39 == V_50 )
break;
V_235 ++ ;
V_36 = F_21 ( V_232 . V_231 ) ;
}
return V_235 ;
}
static void
F_102 ( struct V_13 * V_14 ,
struct V_56 * V_57 )
{
T_13 * V_189 ;
T_14 V_223 ;
T_9 V_38 ;
T_4 V_224 ;
T_6 V_225 , V_236 ;
unsigned long V_237 , V_238 ;
T_6 V_239 , V_240 ;
T_1 V_241 ;
if ( ! V_14 -> V_173 )
return;
if ( V_14 -> V_242 == V_243 ) {
F_13 ( V_67 L_19
L_20 , V_14 -> V_44 ) ;
return;
}
if ( F_101 ( V_14 ) > 1 ) {
F_99 ( V_14 ) ;
F_13 ( V_67 L_19
L_21 , V_14 -> V_44 ) ;
return;
}
if ( ( F_97 ( V_14 , V_57 -> V_36 ,
& V_225 ) ) || ! V_225 ) {
F_13 ( V_67 L_19
L_22 , V_14 -> V_44 ) ;
return;
}
V_224 = F_71 ( T_13 , V_226 ) + ( V_225 *
sizeof( V_227 ) ) ;
V_189 = F_9 ( V_224 , V_170 ) ;
if ( ! V_189 ) {
F_13 ( V_67 L_19
L_23 , V_14 -> V_44 ) ;
return;
}
if ( ( F_90 ( V_14 , & V_38 , V_189 ,
V_192 , V_57 -> V_36 , V_224 ) ) ) {
F_13 ( V_67 L_19
L_24 , V_14 -> V_44 ) ;
F_2 ( V_189 ) ;
return;
}
if ( V_225 > V_244 ) {
F_13 ( V_111 L_19
L_25
L_26 , V_14 -> V_44 , V_57 -> V_36 ,
V_225 , V_244 ) ;
F_2 ( V_189 ) ;
return;
}
for ( V_236 = 0 ; V_236 < V_225 ; V_236 ++ ) {
if ( F_98 ( V_14 , & V_38 ,
& V_223 , V_229 ,
V_189 -> V_226 [ V_236 ] . V_230 ) ||
F_21 ( V_223 . V_231 ) ==
V_171 ) {
F_13 ( V_67 L_27
L_28
L_29 ,
V_14 -> V_44 , V_57 -> V_36 ,
V_189 -> V_226 [ V_236 ] . V_230 ) ;
goto V_245;
}
V_241 = F_18 ( V_223 . V_246 ) ;
if ( V_241 >> 32 ) {
F_13 ( V_67 L_27
L_28
L_30 ,
V_14 -> V_44 , V_57 -> V_36 ,
F_21 ( V_223 . V_231 ) ,
( unsigned long long ) V_241 ) ;
goto V_245;
}
V_57 -> V_247 [ V_236 ] = F_21 ( V_223 . V_231 ) ;
}
if ( V_57 -> V_210 != V_214 ) {
F_13 ( V_67 L_19
L_31
L_32 , V_14 -> V_44 ,
V_57 -> V_36 , V_57 -> V_210 ,
( F_86 ( V_189 -> V_248 ) *
F_21 ( V_189 -> V_249 ) ) / 1024 ,
F_21 ( V_189 -> V_249 ) ) ;
goto V_245;
}
V_237 = F_86 ( V_189 -> V_248 ) ;
V_239 = F_103 ( & V_237 , 32 ) ;
if ( V_239 == 32 ) {
F_13 ( V_67 L_19
L_33 ,
V_14 -> V_44 , V_57 -> V_36 ,
( F_86 ( V_189 -> V_248 ) *
F_21 ( V_189 -> V_249 ) ) / 1024 ) ;
goto V_245;
}
V_57 -> V_250 = V_239 ;
V_238 = F_21 ( V_189 -> V_249 ) ;
V_240 = F_103 ( & V_238 , 16 ) ;
if ( V_240 == 16 ) {
F_13 ( V_67 L_19
L_34 ,
V_14 -> V_44 , V_57 -> V_36 ,
F_21 ( V_189 -> V_249 ) ) ;
goto V_245;
}
V_57 -> V_251 = V_240 ;
V_57 -> V_234 = 1 ;
F_13 ( V_67 L_35
L_36 , V_14 -> V_44 , V_57 -> V_36 ) ;
V_57 -> V_252 = F_18 ( V_189 -> V_253 ) ;
V_57 -> V_237 = F_86 ( V_189 -> V_248 ) ;
V_57 -> V_238 = F_21 ( V_189 -> V_249 ) ;
F_2 ( V_189 ) ;
return;
V_245:
V_57 -> V_234 = 0 ;
for ( V_236 = 0 ; V_236 < V_225 ; V_236 ++ )
V_57 -> V_247 [ V_236 ] = 0 ;
F_2 ( V_189 ) ;
return;
}
static void
F_104 ( struct V_13 * V_14 , struct V_150 * V_77 )
{
if ( V_77 -> type != V_254 )
return;
if ( ! ( V_14 -> V_255 . V_256 & V_257 ) )
return;
F_105 ( V_77 ) ;
F_69 ( V_15 , V_77 , L_37 ,
F_106 ( V_77 ) ? L_38 : L_39 ) ;
return;
}
static int
F_107 ( struct V_150 * V_77 )
{
struct V_152 * V_153 = V_77 -> V_154 ;
struct V_13 * V_14 = F_76 ( V_153 ) ;
struct V_156 * V_157 ;
struct V_74 * V_158 ;
struct V_54 * V_55 ;
struct V_56 * V_57 ;
unsigned long V_78 ;
int V_151 ;
T_6 V_258 = 0 ;
char * V_259 = L_40 ;
char * V_260 = L_40 ;
T_4 V_36 , V_261 = 0 ;
T_1 V_262 = 0 ;
V_151 = 1 ;
V_157 = V_77 -> V_160 ;
V_157 -> V_263 = 1 ;
V_157 -> V_78 &= ~ V_178 ;
V_158 = V_157 -> V_162 ;
V_36 = V_158 -> V_36 ;
if ( V_158 -> V_78 & V_163 ) {
F_31 ( & V_14 -> V_88 , V_78 ) ;
V_57 = F_48 ( V_14 , V_36 ) ;
F_32 ( & V_14 -> V_88 , V_78 ) ;
if ( ! V_57 ) {
F_63 ( V_14 , F_13 ( V_111
L_2 , V_14 -> V_44 , __FILE__ ,
__LINE__ , V_45 ) ) ;
return 1 ;
}
if ( F_96 ( V_14 , V_57 ) ) {
F_63 ( V_14 , F_13 ( V_111
L_2 , V_14 -> V_44 , __FILE__ ,
__LINE__ , V_45 ) ) ;
return 1 ;
}
F_102 ( V_14 , V_57 ) ;
if ( V_57 -> V_94 &
V_96 ) {
V_151 = V_264 ;
V_259 = L_41 ;
} else {
V_151 = V_164 ;
if ( V_57 -> V_94 &
V_98 )
V_259 = L_42 ;
else
V_259 = L_43 ;
}
switch ( V_57 -> V_210 ) {
case V_214 :
V_260 = L_44 ;
break;
case V_218 :
V_151 = V_265 ;
if ( V_14 -> V_266 . V_267 &&
( F_86 ( V_14 -> V_266 . V_268 ) &
V_269 ) &&
! ( V_57 -> V_225 % 2 ) )
V_260 = L_45 ;
else
V_260 = L_46 ;
break;
case V_220 :
V_151 = V_265 ;
V_260 = L_47 ;
break;
case V_216 :
V_151 = V_265 ;
V_260 = L_45 ;
break;
case V_270 :
default:
V_151 = V_265 ;
V_260 = L_48 ;
break;
}
if ( ! V_14 -> V_271 )
F_69 ( V_15 , V_77 , L_49
L_50 ,
V_260 , V_57 -> V_36 ,
( unsigned long long ) V_57 -> V_61 ,
V_57 -> V_225 , V_259 ) ;
F_75 ( V_77 , V_151 ) ;
if ( ! V_14 -> V_173 )
F_94 ( V_77 , V_57 -> V_210 ) ;
return 0 ;
}
if ( V_158 -> V_78 & V_177 ) {
if ( F_108 ( V_14 , V_36 ,
& V_261 ) ) {
F_63 ( V_14 , F_13 ( V_111
L_2 , V_14 -> V_44 ,
__FILE__ , __LINE__ , V_45 ) ) ;
return 1 ;
}
if ( V_261 && F_109 ( V_14 ,
V_261 , & V_262 ) ) {
F_63 ( V_14 , F_13 ( V_111
L_2 , V_14 -> V_44 ,
__FILE__ , __LINE__ , V_45 ) ) ;
return 1 ;
}
}
F_31 ( & V_14 -> V_76 , V_78 ) ;
V_55 = F_33 ( V_14 ,
V_157 -> V_162 -> V_18 ) ;
if ( ! V_55 ) {
F_32 ( & V_14 -> V_76 , V_78 ) ;
F_63 ( V_14 , F_13 ( V_111
L_2 , V_14 -> V_44 , __FILE__ ,
__LINE__ , V_45 ) ) ;
return 1 ;
}
V_55 -> V_261 = V_261 ;
V_55 -> V_262 = V_262 ;
if ( V_55 -> V_94 & V_96 ) {
V_151 = V_264 ;
V_258 = 1 ;
V_259 = L_41 ;
} else {
V_151 = V_164 ;
if ( V_55 -> V_94 & V_97 )
V_259 = L_43 ;
else if ( V_55 -> V_94 &
V_98 )
V_259 = L_42 ;
}
F_69 ( V_15 , V_77 , L_49
L_51 ,
V_259 , V_55 -> V_36 ,
( unsigned long long ) V_55 -> V_18 ,
V_55 -> V_272 ,
( unsigned long long ) V_55 -> V_21 ) ;
F_69 ( V_15 , V_77 , L_52
L_53 , V_259 ,
( unsigned long long ) V_55 -> V_23 ,
V_55 -> V_27 ) ;
F_40 ( V_55 ) ;
F_32 ( & V_14 -> V_76 , V_78 ) ;
if ( ! V_258 )
F_85 ( V_14 , V_36 , V_77 ) ;
F_75 ( V_77 , V_151 ) ;
if ( V_258 ) {
F_110 ( V_77 ) ;
F_104 ( V_14 , V_77 ) ;
}
return 0 ;
}
static int
F_111 ( struct V_150 * V_77 , struct V_273 * V_274 ,
T_16 V_275 , int V_276 [] )
{
int V_277 ;
int V_278 ;
T_16 V_279 ;
T_17 V_280 ;
V_277 = 64 ;
V_278 = 32 ;
V_280 = V_277 * V_278 ;
V_279 = V_275 ;
F_112 ( V_279 , V_280 ) ;
if ( ( T_17 ) V_275 >= 0x200000 ) {
V_277 = 255 ;
V_278 = 63 ;
V_280 = V_277 * V_278 ;
V_279 = V_275 ;
F_112 ( V_279 , V_280 ) ;
}
V_276 [ 0 ] = V_277 ;
V_276 [ 1 ] = V_278 ;
V_276 [ 2 ] = V_279 ;
return 0 ;
}
static void
F_113 ( struct V_13 * V_14 , T_6 V_281 )
{
char * V_282 ;
switch ( V_281 ) {
case V_283 :
V_282 = L_54 ;
break;
case V_284 :
V_282 = L_55 ;
break;
case V_285 :
V_282 = L_56 ;
break;
case V_286 :
V_282 = L_57 ;
break;
case V_287 :
V_282 = L_58 ;
break;
case V_288 :
V_282 = L_59 ;
break;
case 0xA :
V_282 = L_60 ;
break;
case V_289 :
V_282 = L_61 ;
break;
default:
V_282 = L_62 ;
break;
}
F_13 ( V_111 L_63 ,
V_14 -> V_44 , V_281 , V_282 ) ;
}
static T_6
F_114 ( struct V_13 * V_14 , T_4 V_100 , T_6 V_290 , T_10 V_291 )
{
T_18 * V_38 ;
if ( V_14 -> V_292 . V_293 == V_294 )
return 1 ;
if ( V_14 -> V_292 . V_100 != V_100 )
return 1 ;
F_115 ( V_14 ) ;
V_14 -> V_292 . V_293 |= V_295 ;
V_38 = F_116 ( V_14 , V_291 ) ;
if ( V_38 ) {
memcpy ( V_14 -> V_292 . V_291 , V_38 , V_38 -> V_296 * 4 ) ;
V_14 -> V_292 . V_293 |= V_297 ;
}
V_14 -> V_292 . V_293 &= ~ V_298 ;
F_117 ( & V_14 -> V_292 . V_299 ) ;
return 1 ;
}
void
F_118 ( struct V_13 * V_14 , T_4 V_36 )
{
struct V_156 * V_157 ;
struct V_150 * V_77 ;
T_6 V_300 = 0 ;
F_119 (sdev, ioc->shost) {
if ( V_300 )
continue;
V_157 = V_77 -> V_160 ;
if ( ! V_157 )
continue;
if ( V_157 -> V_162 -> V_36 == V_36 ) {
V_157 -> V_162 -> V_301 = 1 ;
V_300 = 1 ;
V_14 -> V_302 = 1 ;
}
}
}
void
F_120 ( struct V_13 * V_14 , T_4 V_36 )
{
struct V_156 * V_157 ;
struct V_150 * V_77 ;
T_6 V_300 = 0 ;
F_119 (sdev, ioc->shost) {
if ( V_300 )
continue;
V_157 = V_77 -> V_160 ;
if ( ! V_157 )
continue;
if ( V_157 -> V_162 -> V_36 == V_36 ) {
V_157 -> V_162 -> V_301 = 0 ;
V_300 = 1 ;
V_14 -> V_302 = 0 ;
}
}
}
int
F_121 ( struct V_13 * V_14 , T_4 V_36 , T_19 V_86 ,
T_19 V_85 , T_19 V_107 , T_6 type , T_4 V_303 , T_17 V_304 ,
enum V_305 V_306 )
{
T_20 * V_115 ;
T_21 * V_38 ;
T_4 V_100 = 0 ;
T_10 V_307 ;
unsigned long V_308 ;
struct V_309 * V_101 = NULL ;
int V_29 ;
if ( V_306 == V_310 )
F_122 ( & V_14 -> V_292 . V_311 ) ;
if ( V_14 -> V_292 . V_293 != V_294 ) {
F_13 ( V_67 L_64 ,
V_45 , V_14 -> V_44 ) ;
V_29 = V_312 ;
goto V_313;
}
if ( V_14 -> V_314 || V_14 -> V_315 ||
V_14 -> V_316 ) {
F_13 ( V_67 L_65 ,
V_45 , V_14 -> V_44 ) ;
V_29 = V_312 ;
goto V_313;
}
V_307 = F_123 ( V_14 , 0 ) ;
if ( V_307 & V_317 ) {
F_124 ( V_14 , F_13 ( V_67 L_66
L_67 , V_14 -> V_44 ) ) ;
V_29 = F_125 ( V_14 , V_318 ,
V_319 ) ;
V_29 = ( ! V_29 ) ? V_320 : V_312 ;
goto V_313;
}
if ( ( V_307 & V_321 ) == V_322 ) {
F_126 ( V_14 , V_307 &
V_323 ) ;
V_29 = F_125 ( V_14 , V_318 ,
V_319 ) ;
V_29 = ( ! V_29 ) ? V_320 : V_312 ;
goto V_313;
}
V_100 = F_127 ( V_14 , V_14 -> V_324 ) ;
if ( ! V_100 ) {
F_13 ( V_43 L_68 ,
V_14 -> V_44 , V_45 ) ;
V_29 = V_312 ;
goto V_313;
}
if ( type == V_325 )
V_101 = & V_14 -> V_101 [ V_303 - 1 ] ;
F_128 ( V_14 , F_13 ( V_67 L_69
L_70 , V_14 -> V_44 , V_36 , type ,
V_303 ) ) ;
V_14 -> V_292 . V_293 = V_298 ;
V_115 = F_66 ( V_14 , V_100 ) ;
V_14 -> V_292 . V_100 = V_100 ;
memset ( V_115 , 0 , sizeof( T_20 ) ) ;
memset ( V_14 -> V_292 . V_291 , 0 , sizeof( T_21 ) ) ;
V_115 -> V_326 = V_327 ;
V_115 -> V_231 = F_129 ( V_36 ) ;
V_115 -> V_328 = type ;
V_115 -> V_329 = F_129 ( V_303 ) ;
F_130 ( V_107 , (struct V_330 * ) V_115 -> V_331 ) ;
F_118 ( V_14 , V_36 ) ;
F_131 ( & V_14 -> V_292 . V_299 ) ;
F_132 ( V_14 , V_100 ) ;
V_308 = F_133 ( & V_14 -> V_292 . V_299 , V_304 * V_332 ) ;
if ( ! ( V_14 -> V_292 . V_293 & V_295 ) ) {
F_13 ( V_43 L_71 ,
V_14 -> V_44 , V_45 ) ;
F_134 ( V_115 ,
sizeof( T_20 ) / 4 ) ;
if ( ! ( V_14 -> V_292 . V_293 & V_333 ) ) {
V_29 = F_125 ( V_14 , V_318 ,
V_319 ) ;
V_29 = ( ! V_29 ) ? V_320 : V_312 ;
V_14 -> V_292 . V_293 = V_294 ;
F_120 ( V_14 , V_36 ) ;
goto V_313;
}
}
if ( V_14 -> V_292 . V_293 & V_297 ) {
V_38 = V_14 -> V_292 . V_291 ;
F_128 ( V_14 , F_13 ( V_67 L_72
L_73 ,
V_14 -> V_44 , F_21 ( V_38 -> V_47 ) ,
F_86 ( V_38 -> V_334 ) ,
F_86 ( V_38 -> V_335 ) ) ) ;
if ( V_14 -> V_16 & V_336 ) {
F_113 ( V_14 , V_38 -> V_337 ) ;
if ( V_38 -> V_47 )
F_134 ( V_115 ,
sizeof( T_20 ) / 4 ) ;
}
}
switch ( type ) {
case V_325 :
V_29 = V_320 ;
if ( V_101 -> V_102 == NULL )
break;
V_29 = V_312 ;
break;
case V_338 :
if ( F_60 ( V_14 , V_85 , V_86 ) )
V_29 = V_312 ;
else
V_29 = V_320 ;
break;
case V_339 :
case V_340 :
if ( F_61 ( V_14 , V_85 , V_107 , V_86 ) )
V_29 = V_312 ;
else
V_29 = V_320 ;
break;
case V_341 :
V_29 = V_320 ;
break;
default:
V_29 = V_312 ;
break;
}
F_120 ( V_14 , V_36 ) ;
V_14 -> V_292 . V_293 = V_294 ;
if ( V_306 == V_310 )
F_135 ( & V_14 -> V_292 . V_311 ) ;
return V_29 ;
V_313:
if ( V_306 == V_310 )
F_135 ( & V_14 -> V_292 . V_311 ) ;
return V_29 ;
}
static void
F_136 ( struct V_13 * V_14 , struct V_99 * V_102 )
{
struct V_166 * V_83 = V_102 -> V_52 -> V_342 ;
struct V_74 * V_343 = V_83 -> V_160 ;
struct V_54 * V_55 = NULL ;
unsigned long V_78 ;
char * V_344 = NULL ;
if ( ! V_343 )
return;
if ( V_14 -> V_271 )
V_344 = L_74 ;
else
V_344 = L_75 ;
F_137 ( V_102 ) ;
if ( V_343 -> V_78 & V_163 ) {
F_138 ( V_15 , V_83 , L_76
L_77 , V_344 , V_343 -> V_36 ,
V_344 , ( unsigned long long ) V_343 -> V_18 ) ;
} else {
F_31 ( & V_14 -> V_76 , V_78 ) ;
V_55 = F_27 ( V_14 , V_343 ) ;
if ( V_55 ) {
if ( V_343 -> V_78 &
V_177 ) {
F_138 ( V_15 , V_83 ,
L_78
L_79 ,
V_55 -> V_261 ,
( unsigned long long ) V_55 -> V_262 ) ;
}
F_138 ( V_15 , V_83 ,
L_80 ,
V_55 -> V_36 ,
( unsigned long long ) V_55 -> V_18 ,
V_55 -> V_272 ) ;
F_138 ( V_15 , V_83 ,
L_53 ,
( unsigned long long ) V_55 -> V_23 ,
V_55 -> V_27 ) ;
F_40 ( V_55 ) ;
}
F_32 ( & V_14 -> V_76 , V_78 ) ;
}
}
static int
F_139 ( struct V_99 * V_102 )
{
struct V_13 * V_14 = F_76 ( V_102 -> V_52 -> V_154 ) ;
struct V_156 * V_157 ;
T_4 V_100 ;
T_4 V_36 ;
int V_2 ;
F_69 ( V_15 , V_102 -> V_52 , L_81
L_82 , V_102 ) ;
F_136 ( V_14 , V_102 ) ;
V_157 = V_102 -> V_52 -> V_160 ;
if ( ! V_157 || ! V_157 -> V_162 ) {
F_69 ( V_15 , V_102 -> V_52 , L_83
L_82 , V_102 ) ;
V_102 -> V_345 = V_346 << 16 ;
V_102 -> V_347 ( V_102 ) ;
V_2 = V_320 ;
goto V_87;
}
V_100 = F_59 ( V_14 , V_102 ) ;
if ( ! V_100 ) {
V_102 -> V_345 = V_348 << 16 ;
V_2 = V_320 ;
goto V_87;
}
if ( V_157 -> V_162 -> V_78 &
V_177 ||
V_157 -> V_162 -> V_78 & V_163 ) {
V_102 -> V_345 = V_348 << 16 ;
V_2 = V_312 ;
goto V_87;
}
F_140 ( V_14 ) ;
V_36 = V_157 -> V_162 -> V_36 ;
V_2 = F_121 ( V_14 , V_36 , V_102 -> V_52 -> V_86 ,
V_102 -> V_52 -> V_85 , V_102 -> V_52 -> V_107 ,
V_325 , V_100 , 30 , V_310 ) ;
V_87:
F_69 ( V_15 , V_102 -> V_52 , L_84 ,
( ( V_2 == V_320 ) ? L_85 : L_86 ) , V_102 ) ;
return V_2 ;
}
static int
F_141 ( struct V_99 * V_102 )
{
struct V_13 * V_14 = F_76 ( V_102 -> V_52 -> V_154 ) ;
struct V_156 * V_157 ;
struct V_54 * V_55 = NULL ;
T_4 V_36 ;
int V_2 ;
struct V_166 * V_83 = V_102 -> V_52 -> V_342 ;
struct V_74 * V_349 = V_83 -> V_160 ;
F_138 ( V_15 , V_83 , L_87
L_82 , V_102 ) ;
F_136 ( V_14 , V_102 ) ;
V_157 = V_102 -> V_52 -> V_160 ;
if ( ! V_157 || ! V_157 -> V_162 ) {
F_138 ( V_15 , V_83 , L_83
L_82 , V_102 ) ;
V_102 -> V_345 = V_346 << 16 ;
V_102 -> V_347 ( V_102 ) ;
V_2 = V_320 ;
goto V_87;
}
V_36 = 0 ;
if ( V_157 -> V_162 -> V_78 &
V_177 ) {
V_55 = F_30 ( V_14 ,
V_349 ) ;
if ( V_55 )
V_36 = V_55 -> V_261 ;
} else
V_36 = V_157 -> V_162 -> V_36 ;
if ( ! V_36 ) {
V_102 -> V_345 = V_348 << 16 ;
V_2 = V_312 ;
goto V_87;
}
V_2 = F_121 ( V_14 , V_36 , V_102 -> V_52 -> V_86 ,
V_102 -> V_52 -> V_85 , V_102 -> V_52 -> V_107 ,
V_340 , 0 , 30 , V_310 ) ;
V_87:
F_69 ( V_15 , V_102 -> V_52 , L_88 ,
( ( V_2 == V_320 ) ? L_85 : L_86 ) , V_102 ) ;
if ( V_55 )
F_40 ( V_55 ) ;
return V_2 ;
}
static int
F_142 ( struct V_99 * V_102 )
{
struct V_13 * V_14 = F_76 ( V_102 -> V_52 -> V_154 ) ;
struct V_156 * V_157 ;
struct V_54 * V_55 = NULL ;
T_4 V_36 ;
int V_2 ;
struct V_166 * V_83 = V_102 -> V_52 -> V_342 ;
struct V_74 * V_349 = V_83 -> V_160 ;
F_138 ( V_15 , V_83 , L_89
L_82 , V_102 ) ;
F_136 ( V_14 , V_102 ) ;
V_157 = V_102 -> V_52 -> V_160 ;
if ( ! V_157 || ! V_157 -> V_162 ) {
F_138 ( V_15 , V_83 , L_90
L_82 , V_102 ) ;
V_102 -> V_345 = V_346 << 16 ;
V_102 -> V_347 ( V_102 ) ;
V_2 = V_320 ;
goto V_87;
}
V_36 = 0 ;
if ( V_157 -> V_162 -> V_78 &
V_177 ) {
V_55 = F_30 ( V_14 ,
V_349 ) ;
if ( V_55 )
V_36 = V_55 -> V_261 ;
} else
V_36 = V_157 -> V_162 -> V_36 ;
if ( ! V_36 ) {
V_102 -> V_345 = V_348 << 16 ;
V_2 = V_312 ;
goto V_87;
}
V_2 = F_121 ( V_14 , V_36 , V_102 -> V_52 -> V_86 ,
V_102 -> V_52 -> V_85 , 0 , V_338 , 0 ,
30 , V_310 ) ;
V_87:
F_138 ( V_15 , V_83 , L_91 ,
( ( V_2 == V_320 ) ? L_85 : L_86 ) , V_102 ) ;
if ( V_55 )
F_40 ( V_55 ) ;
return V_2 ;
}
static int
F_143 ( struct V_99 * V_102 )
{
struct V_13 * V_14 = F_76 ( V_102 -> V_52 -> V_154 ) ;
int V_2 , V_350 ;
F_13 ( V_67 L_92 ,
V_14 -> V_44 , V_102 ) ;
F_137 ( V_102 ) ;
if ( V_14 -> V_58 ) {
F_13 ( V_67 L_93 ,
V_14 -> V_44 ) ;
V_2 = V_312 ;
goto V_87;
}
V_350 = F_125 ( V_14 , V_318 ,
V_319 ) ;
V_2 = ( V_350 < 0 ) ? V_312 : V_320 ;
V_87:
F_13 ( V_67 L_94 ,
V_14 -> V_44 , ( ( V_2 == V_320 ) ? L_85 : L_86 ) , V_102 ) ;
return V_2 ;
}
static void
F_144 ( struct V_13 * V_14 , struct V_3 * V_7 )
{
unsigned long V_78 ;
if ( V_14 -> V_351 == NULL )
return;
F_31 ( & V_14 -> V_352 , V_78 ) ;
F_4 ( V_7 ) ;
F_43 ( & V_7 -> V_80 , & V_14 -> V_353 ) ;
F_145 ( & V_7 -> V_354 , V_355 ) ;
F_4 ( V_7 ) ;
F_146 ( V_14 -> V_351 ,
& V_7 -> V_354 , 0 ) ;
F_32 ( & V_14 -> V_352 , V_78 ) ;
}
static void
F_147 ( struct V_13 * V_14 , struct V_3
* V_7 )
{
unsigned long V_78 ;
F_31 ( & V_14 -> V_352 , V_78 ) ;
if ( ! F_38 ( & V_7 -> V_80 ) ) {
F_39 ( & V_7 -> V_80 ) ;
F_6 ( V_7 ) ;
}
F_32 ( & V_14 -> V_352 , V_78 ) ;
}
static void
F_148 ( struct V_13 * V_14 )
{
struct V_3 * V_7 ;
if ( V_14 -> V_58 )
return;
V_7 = F_8 ( 0 ) ;
if ( ! V_7 )
return;
V_7 -> V_356 = V_357 ;
V_7 -> V_14 = V_14 ;
F_144 ( V_14 , V_7 ) ;
F_6 ( V_7 ) ;
}
void
F_149 ( struct V_13 * V_14 )
{
struct V_3 * V_7 ;
V_7 = F_8 ( 0 ) ;
if ( ! V_7 )
return;
V_7 -> V_356 = V_358 ;
V_7 -> V_14 = V_14 ;
F_144 ( V_14 , V_7 ) ;
F_6 ( V_7 ) ;
}
static struct V_3 * F_150 ( struct V_13 * V_14 )
{
unsigned long V_78 ;
struct V_3 * V_7 = NULL ;
F_31 ( & V_14 -> V_352 , V_78 ) ;
if ( ! F_38 ( & V_14 -> V_353 ) ) {
V_7 = F_151 ( & V_14 -> V_353 ,
struct V_3 , V_80 ) ;
F_39 ( & V_7 -> V_80 ) ;
}
F_32 ( & V_14 -> V_352 , V_78 ) ;
return V_7 ;
}
static void
F_152 ( struct V_13 * V_14 )
{
struct V_3 * V_7 ;
if ( F_38 ( & V_14 -> V_353 ) ||
! V_14 -> V_351 || F_153 () )
return;
while ( ( V_7 = F_150 ( V_14 ) ) ) {
if ( F_154 ( & V_7 -> V_354 ) )
F_6 ( V_7 ) ;
F_6 ( V_7 ) ;
}
}
static void
F_155 ( struct V_13 * V_14 )
{
struct V_156 * V_157 ;
struct V_150 * V_77 ;
F_119 (sdev, ioc->shost) {
V_157 = V_77 -> V_160 ;
if ( ! V_157 )
continue;
if ( ! V_157 -> V_359 )
continue;
V_157 -> V_359 = 0 ;
F_42 ( V_14 , F_69 ( V_15 , V_77 , L_95
L_96 ,
V_157 -> V_162 -> V_36 ) ) ;
F_156 ( V_77 , V_360 ) ;
}
}
static void
F_157 ( struct V_13 * V_14 , T_1 V_18 )
{
struct V_156 * V_157 ;
struct V_150 * V_77 ;
F_119 (sdev, ioc->shost) {
V_157 = V_77 -> V_160 ;
if ( ! V_157 )
continue;
if ( ! V_157 -> V_359 )
continue;
if ( V_157 -> V_162 -> V_18 ==
V_18 ) {
F_42 ( V_14 , F_69 ( V_15 , V_77 ,
V_67 L_97
L_98 , V_14 -> V_44 ,
( unsigned long long ) V_18 ) ) ;
V_157 -> V_359 = 0 ;
F_156 ( V_77 , V_360 ) ;
}
}
}
static void
F_158 ( struct V_13 * V_14 )
{
struct V_156 * V_157 ;
struct V_150 * V_77 ;
F_119 (sdev, ioc->shost) {
V_157 = V_77 -> V_160 ;
if ( ! V_157 )
continue;
if ( V_157 -> V_359 )
continue;
V_157 -> V_359 = 1 ;
F_42 ( V_14 , F_69 ( V_15 , V_77 , L_99
L_96 ,
V_157 -> V_162 -> V_36 ) ) ;
F_159 ( V_77 ) ;
}
}
static void
F_160 ( struct V_13 * V_14 , T_4 V_36 )
{
struct V_156 * V_157 ;
struct V_150 * V_77 ;
F_119 (sdev, ioc->shost) {
V_157 = V_77 -> V_160 ;
if ( ! V_157 )
continue;
if ( V_157 -> V_359 )
continue;
if ( V_157 -> V_162 -> V_36 == V_36 ) {
F_42 ( V_14 , F_69 ( V_15 , V_77 ,
V_67 L_100
L_96 , V_14 -> V_44 , V_36 ) ) ;
V_157 -> V_359 = 1 ;
F_159 ( V_77 ) ;
}
}
}
static void
F_161 ( struct V_13 * V_14 ,
struct V_90 * V_91 )
{
struct V_361 * V_362 ;
struct V_54 * V_55 ;
struct V_90 * V_363 ;
unsigned long V_78 ;
if ( ! V_91 )
return;
F_15 (mpt2sas_port,
&sas_expander->sas_port_list, port_list) {
if ( V_362 -> V_364 . V_365 == V_366 ) {
F_31 ( & V_14 -> V_76 , V_78 ) ;
V_55 = F_33 ( V_14 ,
V_362 -> V_364 . V_18 ) ;
if ( V_55 ) {
F_162 ( V_55 -> V_36 ,
V_14 -> V_367 ) ;
F_40 ( V_55 ) ;
}
F_32 ( & V_14 -> V_76 , V_78 ) ;
}
}
F_15 (mpt2sas_port,
&sas_expander->sas_port_list, port_list) {
if ( V_362 -> V_364 . V_365 ==
V_368 ||
V_362 -> V_364 . V_365 ==
V_369 ) {
V_363 =
F_54 (
V_14 , V_362 -> V_364 . V_18 ) ;
F_161 ( V_14 ,
V_363 ) ;
}
}
}
static void
F_163 ( struct V_13 * V_14 ,
T_22 * V_370 )
{
int V_104 ;
T_4 V_36 ;
T_4 V_371 ;
T_6 V_372 ;
for ( V_104 = 0 ; V_104 < V_370 -> V_373 ; V_104 ++ ) {
V_36 = F_21 ( V_370 -> V_374 [ V_104 ] . V_375 ) ;
if ( ! V_36 )
continue;
V_372 = V_370 -> V_376 + V_104 ;
V_371 = V_370 -> V_374 [ V_104 ] . V_377 &
V_378 ;
if ( V_371 == V_379 )
F_160 ( V_14 , V_36 ) ;
}
}
static void
F_164 ( struct V_13 * V_14 , T_4 V_36 )
{
T_20 * V_115 ;
T_4 V_100 ;
struct V_54 * V_55 = NULL ;
struct V_74 * V_158 = NULL ;
T_1 V_18 = 0 ;
unsigned long V_78 ;
struct V_380 * V_381 ;
T_10 V_307 ;
if ( V_14 -> V_315 ) {
F_42 ( V_14 , F_13 ( V_67 L_101
L_102 , V_45 , V_14 -> V_44 , V_36 ) ) ;
return;
} else if ( V_14 -> V_316 ) {
F_42 ( V_14 , F_13 ( V_67 L_103
L_104 , V_45 , V_14 -> V_44 ,
V_36 ) ) ;
return;
}
V_307 = F_123 ( V_14 , 1 ) ;
if ( V_307 != V_382 ) {
F_42 ( V_14 , F_13 ( V_67 L_105
L_106 , V_45 , V_14 -> V_44 ,
V_36 ) ) ;
return;
}
if ( F_81 ( V_36 , V_14 -> V_176 ) )
return;
F_31 ( & V_14 -> V_76 , V_78 ) ;
V_55 = F_35 ( V_14 , V_36 ) ;
if ( V_55 && V_55 -> V_83 &&
V_55 -> V_83 -> V_160 ) {
V_158 = V_55 -> V_83 -> V_160 ;
V_158 -> V_383 = 1 ;
V_18 = V_55 -> V_18 ;
}
F_32 ( & V_14 -> V_76 , V_78 ) ;
if ( V_158 ) {
F_42 ( V_14 , F_13 ( V_67 L_107
L_108 , V_14 -> V_44 , V_36 ,
( unsigned long long ) V_18 ) ) ;
F_157 ( V_14 , V_18 ) ;
V_158 -> V_36 = V_171 ;
}
V_100 = F_127 ( V_14 , V_14 -> V_384 ) ;
if ( ! V_100 ) {
V_381 = F_9 ( sizeof( * V_381 ) , V_8 ) ;
if ( ! V_381 )
goto V_87;
F_165 ( & V_381 -> V_80 ) ;
V_381 -> V_36 = V_36 ;
F_43 ( & V_381 -> V_80 , & V_14 -> V_385 ) ;
F_42 ( V_14 , F_13 ( V_67
L_109 ,
V_14 -> V_44 , V_36 ) ) ;
goto V_87;
}
F_42 ( V_14 , F_13 ( V_67 L_110
L_111 , V_14 -> V_44 , V_36 , V_100 ,
V_14 -> V_384 ) ) ;
V_115 = F_66 ( V_14 , V_100 ) ;
memset ( V_115 , 0 , sizeof( T_20 ) ) ;
V_115 -> V_326 = V_327 ;
V_115 -> V_231 = F_129 ( V_36 ) ;
V_115 -> V_328 = V_338 ;
F_132 ( V_14 , V_100 ) ;
V_87:
if ( V_55 )
F_40 ( V_55 ) ;
}
static T_6
F_166 ( struct V_13 * V_14 , T_4 V_100 ,
T_6 V_290 , T_10 V_291 )
{
T_23 * V_38 =
F_116 ( V_14 , V_291 ) ;
if ( F_167 ( V_38 ) ) {
F_42 ( V_14 , F_13 ( V_67
L_112
L_113 ,
V_14 -> V_44 , F_21 ( V_38 -> V_231 ) , V_100 ,
F_21 ( V_38 -> V_47 ) ,
F_86 ( V_38 -> V_334 ) ) ) ;
} else {
F_13 ( V_43 L_114 ,
V_14 -> V_44 , __FILE__ , __LINE__ , V_45 ) ;
}
return 1 ;
}
static void
F_168 ( struct V_13 * V_14 , T_4 V_36 )
{
T_20 * V_115 ;
T_4 V_100 ;
struct V_380 * V_381 ;
if ( V_14 -> V_314 || V_14 -> V_315 ||
V_14 -> V_316 ) {
F_42 ( V_14 , F_13 ( V_67 L_115
L_116 , V_45 , V_14 -> V_44 ) ) ;
return;
}
V_100 = F_127 ( V_14 , V_14 -> V_386 ) ;
if ( ! V_100 ) {
V_381 = F_9 ( sizeof( * V_381 ) , V_8 ) ;
if ( ! V_381 )
return;
F_165 ( & V_381 -> V_80 ) ;
V_381 -> V_36 = V_36 ;
F_43 ( & V_381 -> V_80 , & V_14 -> V_387 ) ;
F_42 ( V_14 , F_13 ( V_67
L_109 ,
V_14 -> V_44 , V_36 ) ) ;
return;
}
F_42 ( V_14 , F_13 ( V_67 L_110
L_111 , V_14 -> V_44 , V_36 , V_100 ,
V_14 -> V_386 ) ) ;
V_115 = F_66 ( V_14 , V_100 ) ;
memset ( V_115 , 0 , sizeof( T_20 ) ) ;
V_115 -> V_326 = V_327 ;
V_115 -> V_231 = F_129 ( V_36 ) ;
V_115 -> V_328 = V_338 ;
F_132 ( V_14 , V_100 ) ;
}
static T_6
F_169 ( struct V_13 * V_14 , T_4 V_100 ,
T_6 V_290 , T_10 V_291 )
{
T_4 V_36 ;
T_20 * V_388 ;
T_21 * V_38 =
F_116 ( V_14 , V_291 ) ;
if ( V_14 -> V_314 || V_14 -> V_315 ||
V_14 -> V_316 ) {
F_42 ( V_14 , F_13 ( V_67 L_115
L_116 , V_45 , V_14 -> V_44 ) ) ;
return 1 ;
}
if ( F_170 ( ! V_38 ) ) {
F_13 ( V_43 L_114 ,
V_14 -> V_44 , __FILE__ , __LINE__ , V_45 ) ;
return 1 ;
}
V_388 = F_66 ( V_14 , V_100 ) ;
V_36 = F_21 ( V_388 -> V_231 ) ;
if ( V_36 != F_21 ( V_38 -> V_231 ) ) {
F_42 ( V_14 , F_13 ( L_117
L_118 , V_36 ,
F_21 ( V_38 -> V_231 ) , V_100 ) ) ;
return 0 ;
}
F_42 ( V_14 , F_13 ( V_67
L_119
L_120 , V_14 -> V_44 ,
V_36 , V_100 , F_21 ( V_38 -> V_47 ) ,
F_86 ( V_38 -> V_334 ) ,
F_86 ( V_38 -> V_335 ) ) ) ;
return F_171 ( V_14 , V_100 ) ;
}
static T_6
F_172 ( struct V_13 * V_14 , T_4 V_100 , T_6 V_290 ,
T_10 V_291 )
{
T_4 V_36 ;
T_20 * V_388 ;
T_21 * V_38 =
F_116 ( V_14 , V_291 ) ;
T_24 * V_115 ;
T_4 V_389 ;
T_10 V_307 ;
if ( V_14 -> V_315 ) {
F_42 ( V_14 , F_13 ( V_67 L_101
L_121 , V_45 , V_14 -> V_44 ) ) ;
return 1 ;
} else if ( V_14 -> V_316 ) {
F_42 ( V_14 , F_13 ( V_67 L_103
L_122 , V_45 , V_14 -> V_44 ) ) ;
return 1 ;
}
V_307 = F_123 ( V_14 , 1 ) ;
if ( V_307 != V_382 ) {
F_42 ( V_14 , F_13 ( V_67 L_105
L_123 , V_45 , V_14 -> V_44 ) ) ;
return 1 ;
}
if ( F_170 ( ! V_38 ) ) {
F_13 ( V_43 L_114 ,
V_14 -> V_44 , __FILE__ , __LINE__ , V_45 ) ;
return 1 ;
}
V_388 = F_66 ( V_14 , V_100 ) ;
V_36 = F_21 ( V_388 -> V_231 ) ;
if ( V_36 != F_21 ( V_38 -> V_231 ) ) {
F_42 ( V_14 , F_13 ( V_67 L_117
L_118 , V_14 -> V_44 , V_36 ,
F_21 ( V_38 -> V_231 ) , V_100 ) ) ;
return 0 ;
}
F_42 ( V_14 , F_13 ( V_67
L_119
L_120 , V_14 -> V_44 ,
V_36 , V_100 , F_21 ( V_38 -> V_47 ) ,
F_86 ( V_38 -> V_334 ) ,
F_86 ( V_38 -> V_335 ) ) ) ;
V_389 = F_173 ( V_14 , V_14 -> V_390 ) ;
if ( ! V_389 ) {
F_13 ( V_43 L_68 ,
V_14 -> V_44 , V_45 ) ;
return 1 ;
}
F_42 ( V_14 , F_13 ( V_67 L_124
L_111 , V_14 -> V_44 , V_36 , V_389 ,
V_14 -> V_390 ) ) ;
V_115 = F_66 ( V_14 , V_389 ) ;
memset ( V_115 , 0 , sizeof( T_24 ) ) ;
V_115 -> V_326 = V_391 ;
V_115 -> V_392 = V_393 ;
V_115 -> V_231 = V_388 -> V_231 ;
F_174 ( V_14 , V_389 ) ;
return F_171 ( V_14 , V_100 ) ;
}
static T_6
F_171 ( struct V_13 * V_14 , T_4 V_100 )
{
struct V_380 * V_381 ;
if ( ! F_38 ( & V_14 -> V_387 ) ) {
V_381 = F_64 ( V_14 -> V_387 . V_112 ,
struct V_380 , V_80 ) ;
F_175 ( V_14 , V_100 ) ;
F_168 ( V_14 , V_381 -> V_36 ) ;
F_52 ( & V_381 -> V_80 ) ;
F_2 ( V_381 ) ;
return 0 ;
}
if ( ! F_38 ( & V_14 -> V_385 ) ) {
V_381 = F_64 ( V_14 -> V_385 . V_112 ,
struct V_380 , V_80 ) ;
F_175 ( V_14 , V_100 ) ;
F_164 ( V_14 , V_381 -> V_36 ) ;
F_52 ( & V_381 -> V_80 ) ;
F_2 ( V_381 ) ;
return 0 ;
}
return 1 ;
}
static void
F_176 ( struct V_13 * V_14 ,
T_22 * V_370 )
{
struct V_3 * V_7 ;
T_22 * V_394 ;
T_4 V_395 ;
struct V_90 * V_91 ;
unsigned long V_78 ;
int V_104 , V_371 ;
T_4 V_36 ;
for ( V_104 = 0 ; V_104 < V_370 -> V_373 ; V_104 ++ ) {
V_36 = F_21 ( V_370 -> V_374 [ V_104 ] . V_375 ) ;
if ( ! V_36 )
continue;
V_371 = V_370 -> V_374 [ V_104 ] . V_377 &
V_378 ;
if ( V_371 == V_396 )
F_164 ( V_14 , V_36 ) ;
}
V_395 = F_21 ( V_370 -> V_397 ) ;
if ( V_395 < V_14 -> V_40 . V_41 ) {
F_163 ( V_14 , V_370 ) ;
return;
}
if ( V_370 -> V_398 ==
V_399 ) {
F_31 ( & V_14 -> V_92 , V_78 ) ;
V_91 = F_53 ( V_14 ,
V_395 ) ;
F_161 ( V_14 , V_91 ) ;
F_32 ( & V_14 -> V_92 , V_78 ) ;
do {
V_36 = F_103 ( V_14 -> V_367 ,
V_14 -> V_255 . V_400 ) ;
if ( V_36 < V_14 -> V_255 . V_400 )
F_160 ( V_14 , V_36 ) ;
} while ( F_177 ( V_36 , V_14 -> V_367 ) );
} else if ( V_370 -> V_398 == V_401 )
F_163 ( V_14 , V_370 ) ;
if ( V_370 -> V_398 != V_402 )
return;
F_31 ( & V_14 -> V_352 , V_78 ) ;
F_15 (fw_event, &ioc->fw_event_list, list) {
if ( V_7 -> V_356 != V_403 ||
V_7 -> V_404 )
continue;
V_394 = ( T_22 * )
V_7 -> V_370 ;
if ( V_394 -> V_398 ==
V_405 ||
V_394 -> V_398 ==
V_401 ) {
if ( F_21 ( V_394 -> V_397 ) ==
V_395 ) {
F_42 ( V_14 , F_13 ( V_67
L_125 , V_14 -> V_44 ) ) ;
V_7 -> V_404 = 1 ;
}
}
}
F_32 ( & V_14 -> V_352 , V_78 ) ;
}
static void
F_178 ( struct V_13 * V_14 , T_4 V_36 )
{
struct V_56 * V_57 ;
struct V_74 * V_158 ;
unsigned long V_78 ;
F_31 ( & V_14 -> V_88 , V_78 ) ;
V_57 = F_48 ( V_14 , V_36 ) ;
if ( V_57 && V_57 -> V_83 &&
V_57 -> V_83 -> V_160 ) {
V_158 =
V_57 -> V_83 -> V_160 ;
V_158 -> V_383 = 1 ;
F_42 ( V_14 , F_13 ( V_67
L_126
L_127 , V_14 -> V_44 , V_36 ,
( unsigned long long ) V_57 -> V_61 ) ) ;
}
F_32 ( & V_14 -> V_88 , V_78 ) ;
}
static void
F_179 ( T_4 V_36 , T_4 * V_406 , T_4 * V_407 )
{
if ( ! V_36 || V_36 == * V_406 || V_36 == * V_407 )
return;
if ( ! * V_406 )
* V_406 = V_36 ;
else if ( ! * V_407 )
* V_407 = V_36 ;
}
static void
F_180 ( struct V_13 * V_14 ,
T_25 * V_370 )
{
T_26 * V_408 ;
int V_104 ;
T_4 V_36 , V_261 , V_406 , V_407 ;
struct V_380 * V_381 ;
V_406 = 0 ;
V_407 = 0 ;
if ( V_14 -> V_173 )
return;
V_408 = ( T_26 * ) & V_370 -> V_409 [ 0 ] ;
for ( V_104 = 0 ; V_104 < V_370 -> V_410 ; V_104 ++ , V_408 ++ ) {
if ( V_408 -> V_411 ==
V_412 ||
V_408 -> V_411 ==
V_413 ) {
V_261 = F_21 ( V_408 -> V_414 ) ;
F_178 ( V_14 , V_261 ) ;
F_179 ( V_261 , & V_406 , & V_407 ) ;
}
}
V_408 = ( T_26 * ) & V_370 -> V_409 [ 0 ] ;
for ( V_104 = 0 ; V_104 < V_370 -> V_410 ; V_104 ++ , V_408 ++ ) {
if ( F_86 ( V_370 -> V_181 ) &
V_415 )
continue;
if ( V_408 -> V_411 == V_416 ) {
V_261 = F_21 ( V_408 -> V_414 ) ;
F_179 ( V_261 , & V_406 , & V_407 ) ;
}
}
if ( V_406 )
F_168 ( V_14 , V_406 ) ;
if ( V_407 )
F_168 ( V_14 , V_407 ) ;
V_408 = ( T_26 * ) & V_370 -> V_409 [ 0 ] ;
for ( V_104 = 0 ; V_104 < V_370 -> V_410 ; V_104 ++ , V_408 ++ ) {
if ( V_408 -> V_411 != V_416 )
continue;
V_36 = F_21 ( V_408 -> V_417 ) ;
V_261 = F_21 ( V_408 -> V_414 ) ;
F_181 ( V_36 , V_14 -> V_176 ) ;
if ( ! V_261 )
F_164 ( V_14 , V_36 ) ;
else if ( V_261 == V_406 || V_261 == V_407 ) {
V_381 = F_9 ( sizeof( * V_381 ) , V_8 ) ;
F_182 ( ! V_381 ) ;
F_165 ( & V_381 -> V_80 ) ;
V_381 -> V_36 = V_36 ;
F_43 ( & V_381 -> V_80 , & V_14 -> V_385 ) ;
F_42 ( V_14 , F_13 ( V_67
L_109 , V_14 -> V_44 ,
V_36 ) ) ;
} else
F_164 ( V_14 , V_36 ) ;
}
}
static void
F_183 ( struct V_13 * V_14 ,
T_27 * V_370 )
{
T_10 V_198 ;
if ( V_370 -> V_411 != V_418 )
return;
V_198 = F_86 ( V_370 -> V_419 ) ;
if ( V_198 == V_208 || V_198 ==
V_207 )
F_178 ( V_14 ,
F_21 ( V_370 -> V_414 ) ) ;
}
static void
F_184 ( struct V_13 * V_14 ,
T_28 * V_370 )
{
if ( V_14 -> V_420 >= V_370 -> V_421 ) {
F_13 ( V_43 L_128
L_129 , V_14 -> V_44 ,
( ( F_21 ( V_370 -> V_422 ) & 0x1 ) == 1 ) ? L_130 : L_131 ,
( ( F_21 ( V_370 -> V_422 ) & 0x2 ) == 2 ) ? L_132 : L_131 ,
( ( F_21 ( V_370 -> V_422 ) & 0x4 ) == 4 ) ? L_133 : L_131 ,
( ( F_21 ( V_370 -> V_422 ) & 0x8 ) == 8 ) ? L_134 : L_131 ,
V_370 -> V_421 ) ;
F_13 ( V_43 L_135 ,
V_14 -> V_44 , V_370 -> V_423 ) ;
}
}
static void
F_185 ( struct V_13 * V_14 )
{
struct V_99 * V_102 ;
T_4 V_100 ;
T_4 V_236 = 0 ;
for ( V_100 = 1 ; V_100 <= V_14 -> V_105 ; V_100 ++ ) {
V_102 = F_58 ( V_14 , V_100 ) ;
if ( ! V_102 )
continue;
V_236 ++ ;
F_175 ( V_14 , V_100 ) ;
F_186 ( V_102 ) ;
if ( V_14 -> V_316 )
V_102 -> V_345 = V_346 << 16 ;
else
V_102 -> V_345 = V_348 << 16 ;
V_102 -> V_347 ( V_102 ) ;
}
F_128 ( V_14 , F_13 ( V_67 L_136 ,
V_14 -> V_44 , V_236 ) ) ;
}
static void
F_187 ( struct V_99 * V_102 , T_11 * V_115 )
{
T_4 V_424 ;
unsigned char V_425 = F_188 ( V_102 ) ;
unsigned char V_426 = F_189 ( V_102 ) ;
if ( V_426 == V_427 || V_425 == V_428 )
return;
if ( V_425 == V_429 )
V_424 = V_430 ;
else if ( V_425 == V_431 )
V_424 = V_432 ;
else
return;
switch ( V_426 ) {
case V_433 :
case V_434 :
V_424 |= V_435 |
V_436 |
V_437 ;
V_115 -> V_438 . V_439 . V_440 =
F_190 ( F_191 ( V_102 ) ) ;
break;
case V_441 :
V_424 |= V_437 ;
break;
}
V_115 -> V_442 = F_192 ( V_102 -> V_52 -> V_443 ) ;
V_115 -> V_444 = F_129 ( V_424 ) ;
}
static void
F_193 ( struct V_99 * V_102 , T_4 V_39 )
{
T_6 V_445 ;
switch ( V_39 ) {
case V_446 :
V_445 = 0x01 ;
break;
case V_447 :
V_445 = 0x02 ;
break;
case V_448 :
V_445 = 0x03 ;
break;
default:
V_445 = 0x00 ;
break;
}
F_194 ( 0 , V_102 -> V_449 , V_450 , 0x10 , V_445 ) ;
V_102 -> V_345 = V_451 << 24 | ( V_452 << 16 ) |
V_453 ;
}
static inline T_6
F_195 ( struct V_13 * V_14 , T_4 V_100 )
{
return V_14 -> V_101 [ V_100 - 1 ] . V_454 ;
}
static inline void
F_196 ( struct V_13 * V_14 , T_4 V_100 , T_6 V_454 )
{
V_14 -> V_101 [ V_100 - 1 ] . V_454 = V_454 ;
}
static void
F_197 ( struct V_13 * V_14 , struct V_99 * V_102 ,
struct V_56 * V_57 , T_11 * V_115 ,
T_4 V_100 )
{
T_16 V_455 , V_456 , V_457 , V_458 , V_459 ;
T_10 V_237 , V_239 ;
T_6 V_225 , V_460 = V_102 -> V_461 [ 0 ] ;
if ( V_460 != V_462 && V_460 != V_463 &&
V_460 != V_464 && V_460 != V_465 )
return;
if ( V_460 == V_462 || V_460 == V_463 )
V_455 = F_198 ( & V_115 -> V_438 . V_466 [ 2 ] ) ;
else
V_455 = F_199 ( & V_115 -> V_438 . V_466 [ 2 ] ) ;
V_459 = F_70 ( V_102 ) >> V_57 -> V_251 ;
if ( V_455 + V_459 - 1 > V_57 -> V_252 )
return;
V_237 = V_57 -> V_237 ;
V_239 = V_57 -> V_250 ;
V_457 = V_455 & ( V_237 - 1 ) ;
if ( V_457 + V_459 > V_237 )
return;
V_225 = V_57 -> V_225 ;
V_456 = V_455 >> V_239 ;
V_458 = F_112 ( V_456 , V_225 ) ;
V_456 = ( V_456 << V_239 ) + V_457 ;
V_115 -> V_231 = F_129 ( V_57 -> V_247 [ V_458 ] ) ;
if ( V_460 == V_462 || V_460 == V_463 )
F_200 ( F_201 ( V_456 ) ,
& V_115 -> V_438 . V_466 [ 2 ] ) ;
else
F_202 ( V_456 , & V_115 -> V_438 . V_466 [ 2 ] ) ;
F_196 ( V_14 , V_100 , 1 ) ;
}
static int
F_203 ( struct V_152 * V_153 , struct V_99 * V_102 )
{
struct V_13 * V_14 = F_76 ( V_153 ) ;
struct V_156 * V_157 ;
struct V_74 * V_158 ;
struct V_56 * V_57 ;
T_11 * V_115 ;
T_10 V_467 ;
T_4 V_100 ;
V_157 = V_102 -> V_52 -> V_160 ;
if ( ! V_157 || ! V_157 -> V_162 ) {
V_102 -> V_345 = V_346 << 16 ;
V_102 -> V_347 ( V_102 ) ;
return 0 ;
}
if ( V_14 -> V_316 || V_14 -> V_315 ) {
V_102 -> V_345 = V_346 << 16 ;
V_102 -> V_347 ( V_102 ) ;
return 0 ;
}
V_158 = V_157 -> V_162 ;
if ( V_158 -> V_36 == V_171 ) {
V_102 -> V_345 = V_346 << 16 ;
V_102 -> V_347 ( V_102 ) ;
return 0 ;
}
if ( V_14 -> V_314 || V_14 -> V_468 )
return V_469 ;
else if ( V_157 -> V_359 || V_158 -> V_301 )
return V_470 ;
else if ( V_158 -> V_383 ) {
V_102 -> V_345 = V_346 << 16 ;
V_102 -> V_347 ( V_102 ) ;
return 0 ;
}
if ( V_102 -> V_130 == V_471 )
V_467 = V_472 ;
else if ( V_102 -> V_130 == V_131 )
V_467 = V_473 ;
else
V_467 = V_474 ;
V_467 |= V_475 ;
if ( ! V_14 -> V_173 && ! F_87 ( & V_102 -> V_52 -> V_222 ) &&
F_106 ( V_102 -> V_52 ) && V_102 -> V_476 != 32 )
V_467 |= V_477 ;
V_100 = F_204 ( V_14 , V_14 -> V_478 , V_102 ) ;
if ( ! V_100 ) {
F_13 ( V_43 L_68 ,
V_14 -> V_44 , V_45 ) ;
goto V_87;
}
V_115 = F_66 ( V_14 , V_100 ) ;
memset ( V_115 , 0 , sizeof( T_11 ) ) ;
F_187 ( V_102 , V_115 ) ;
if ( V_102 -> V_476 == 32 )
V_467 |= 4 << V_479 ;
V_115 -> V_326 = V_480 ;
if ( V_157 -> V_162 -> V_78 &
V_177 )
V_115 -> V_326 = V_481 ;
else
V_115 -> V_326 = V_480 ;
V_115 -> V_231 =
F_129 ( V_157 -> V_162 -> V_36 ) ;
V_115 -> V_482 = F_192 ( F_70 ( V_102 ) ) ;
V_115 -> V_483 = F_192 ( V_467 ) ;
V_115 -> V_484 = F_129 ( V_102 -> V_476 ) ;
V_115 -> V_485 = V_486 ;
V_115 -> V_487 = V_488 ;
V_115 -> V_489 =
F_205 ( V_14 , V_100 ) ;
V_115 -> V_490 = F_71 ( T_11 , V_139 ) / 4 ;
V_115 -> V_491 = F_129 ( V_492 +
V_493 ) ;
V_115 -> V_494 = 0 ;
V_115 -> V_495 = 0 ;
F_130 ( V_157 -> V_107 , (struct V_330 * )
V_115 -> V_331 ) ;
memcpy ( V_115 -> V_438 . V_466 , V_102 -> V_461 , V_102 -> V_476 ) ;
if ( ! V_115 -> V_482 ) {
F_206 ( V_14 , & V_115 -> V_139 ) ;
} else {
if ( F_65 ( V_14 , V_102 , V_100 ) ) {
F_175 ( V_14 , V_100 ) ;
goto V_87;
}
}
V_57 = V_158 -> V_57 ;
if ( V_57 && V_57 -> V_234 )
F_197 ( V_14 , V_102 , V_57 , V_115 ,
V_100 ) ;
if ( F_167 ( V_115 -> V_326 == V_480 ) )
F_207 ( V_14 , V_100 ,
F_21 ( V_115 -> V_231 ) ) ;
else
F_174 ( V_14 , V_100 ) ;
return 0 ;
V_87:
return V_469 ;
}
static void
F_208 ( char * V_449 , struct V_496 * V_497 )
{
if ( ( V_449 [ 0 ] & 0x7F ) >= 0x72 ) {
V_497 -> V_498 = V_449 [ 1 ] & 0x0F ;
V_497 -> V_499 = V_449 [ 2 ] ;
V_497 -> V_445 = V_449 [ 3 ] ;
} else {
V_497 -> V_498 = V_449 [ 2 ] & 0x0F ;
V_497 -> V_499 = V_449 [ 12 ] ;
V_497 -> V_445 = V_449 [ 13 ] ;
}
}
static void
F_209 ( struct V_13 * V_14 , struct V_99 * V_102 ,
T_29 * V_38 , T_4 V_100 )
{
T_10 V_500 ;
T_6 * V_501 ;
T_4 V_39 = F_21 ( V_38 -> V_47 ) &
V_48 ;
T_6 V_502 = V_38 -> V_503 ;
T_6 V_504 = V_38 -> V_505 ;
char * V_506 = NULL ;
char * V_507 = NULL ;
char * V_508 = V_14 -> V_509 ;
T_10 V_510 = F_86 ( V_38 -> V_334 ) ;
struct V_54 * V_55 = NULL ;
struct V_166 * V_83 = V_102 -> V_52 -> V_342 ;
struct V_74 * V_343 = V_83 -> V_160 ;
char * V_344 = NULL ;
if ( ! V_343 )
return;
if ( V_14 -> V_271 )
V_344 = L_74 ;
else
V_344 = L_75 ;
if ( V_510 == 0x31170000 )
return;
switch ( V_39 ) {
case V_49 :
V_506 = L_137 ;
break;
case V_511 :
V_506 = L_138 ;
break;
case V_512 :
V_506 = L_139 ;
break;
case V_513 :
V_506 = L_140 ;
break;
case V_514 :
V_506 = L_141 ;
break;
case V_515 :
V_506 = L_142 ;
break;
case V_516 :
V_506 = L_143 ;
break;
case V_517 :
V_506 = L_144 ;
break;
case V_518 :
V_506 = L_145 ;
break;
case V_519 :
V_506 = L_146 ;
break;
case V_520 :
V_506 = L_147 ;
break;
case V_521 :
V_506 = L_148 ;
break;
case V_522 :
V_506 = L_149 ;
break;
case V_523 :
V_506 = L_150 ;
break;
case V_446 :
V_506 = L_151 ;
break;
case V_448 :
V_506 = L_152 ;
break;
case V_447 :
V_506 = L_153 ;
break;
default:
V_506 = L_62 ;
break;
}
switch ( V_504 ) {
case V_524 :
V_507 = L_154 ;
break;
case V_525 :
V_507 = L_155 ;
break;
case V_526 :
V_507 = L_156 ;
break;
case V_527 :
V_507 = L_157 ;
break;
case V_528 :
V_507 = L_158 ;
break;
case V_529 :
V_507 = L_159 ;
break;
case V_530 :
V_507 = L_160 ;
break;
case V_531 :
V_507 = L_161 ;
break;
case V_532 :
V_507 = L_162 ;
break;
case V_533 :
V_507 = L_163 ;
break;
case V_534 :
V_507 = L_164 ;
break;
default:
V_507 = L_62 ;
break;
}
V_508 [ 0 ] = '\0' ;
if ( ! V_502 )
V_508 = L_131 ;
if ( V_502 & V_535 )
strcat ( V_508 , L_165 ) ;
if ( V_502 & V_536 )
strcat ( V_508 , L_166 ) ;
if ( V_502 & V_537 )
strcat ( V_508 , L_167 ) ;
if ( V_502 & V_538 )
strcat ( V_508 , L_168 ) ;
if ( V_502 & V_539 )
strcat ( V_508 , L_169 ) ;
F_137 ( V_102 ) ;
if ( V_343 -> V_78 & V_163 ) {
F_13 ( V_111 L_170 , V_14 -> V_44 ,
V_344 , ( unsigned long long ) V_343 -> V_18 ) ;
} else {
V_55 = F_30 ( V_14 , V_343 ) ;
if ( V_55 ) {
F_13 ( V_111 L_171
L_172 , V_14 -> V_44 , V_55 -> V_18 ,
V_55 -> V_272 ) ;
F_13 ( V_111
L_173 ,
V_14 -> V_44 , V_55 -> V_23 ,
V_55 -> V_27 ) ;
F_40 ( V_55 ) ;
}
}
F_13 ( V_111 L_174
L_175 , V_14 -> V_44 , F_21 ( V_38 -> V_231 ) ,
V_506 , V_39 , V_100 ) ;
F_13 ( V_111 L_176
L_177 , V_14 -> V_44 , F_70 ( V_102 ) , V_102 -> V_540 ,
F_210 ( V_102 ) ) ;
F_13 ( V_111 L_178
L_179 , V_14 -> V_44 , F_21 ( V_38 -> V_541 ) ,
F_86 ( V_38 -> V_542 ) , V_102 -> V_345 ) ;
F_13 ( V_111 L_180
L_181 , V_14 -> V_44 , V_507 ,
V_504 , V_508 , V_502 ) ;
if ( V_502 & V_539 ) {
struct V_496 V_497 ;
F_208 ( V_102 -> V_449 , & V_497 ) ;
F_13 ( V_111 L_182
L_183 , V_14 -> V_44 , V_497 . V_498 ,
V_497 . V_499 , V_497 . V_445 , F_86 ( V_38 -> V_543 ) ) ;
}
if ( V_502 & V_535 ) {
V_500 = F_86 ( V_38 -> V_544 ) ;
V_501 = ( T_6 * ) & V_500 ;
F_113 ( V_14 , V_501 [ 0 ] ) ;
}
}
static void
F_211 ( struct V_13 * V_14 , T_4 V_36 )
{
T_30 V_38 ;
T_31 V_115 ;
struct V_54 * V_55 ;
V_55 = F_36 ( V_14 , V_36 ) ;
if ( ! V_55 )
return;
memset ( & V_115 , 0 , sizeof( T_31 ) ) ;
V_115 . V_326 = V_545 ;
V_115 . V_546 = V_547 ;
V_115 . V_548 =
F_192 ( V_549 ) ;
V_115 . V_231 = F_129 ( V_36 ) ;
V_115 . V_181 = V_550 ;
if ( ( F_212 ( V_14 , & V_38 ,
& V_115 ) ) != 0 ) {
F_13 ( V_43 L_2 , V_14 -> V_44 ,
__FILE__ , __LINE__ , V_45 ) ;
goto V_87;
}
V_55 -> V_551 = 1 ;
if ( V_38 . V_47 || V_38 . V_334 ) {
F_42 ( V_14 , F_13 ( V_67
L_184 ,
V_14 -> V_44 , F_21 ( V_38 . V_47 ) ,
F_86 ( V_38 . V_334 ) ) ) ;
goto V_87;
}
V_87:
F_40 ( V_55 ) ;
}
static void
F_213 ( struct V_13 * V_14 ,
struct V_54 * V_55 )
{
T_30 V_38 ;
T_31 V_115 ;
memset ( & V_115 , 0 , sizeof( T_31 ) ) ;
V_115 . V_326 = V_545 ;
V_115 . V_546 = V_547 ;
V_115 . V_548 = 0 ;
V_115 . V_552 = F_129 ( V_55 -> V_27 ) ;
V_115 . V_231 = 0 ;
V_115 . V_553 = F_129 ( V_55 -> V_554 ) ;
V_115 . V_181 = V_555 ;
if ( ( F_212 ( V_14 , & V_38 ,
& V_115 ) ) != 0 ) {
F_13 ( V_43 L_2 , V_14 -> V_44 ,
__FILE__ , __LINE__ , V_45 ) ;
return;
}
if ( V_38 . V_47 || V_38 . V_334 ) {
F_42 ( V_14 , F_13 ( V_67 L_185
L_186 , V_14 -> V_44 ,
F_21 ( V_38 . V_47 ) ,
F_86 ( V_38 . V_334 ) ) ) ;
return;
}
}
static void
F_214 ( struct V_13 * V_14 , T_4 V_36 )
{
struct V_3 * V_7 ;
V_7 = F_8 ( 0 ) ;
if ( ! V_7 )
return;
V_7 -> V_356 = V_556 ;
V_7 -> V_557 = V_36 ;
V_7 -> V_14 = V_14 ;
F_144 ( V_14 , V_7 ) ;
F_6 ( V_7 ) ;
}
static void
F_215 ( struct V_13 * V_14 , T_4 V_36 )
{
struct V_166 * V_83 ;
struct V_74 * V_158 ;
T_32 * V_558 ;
T_33 * V_370 ;
struct V_54 * V_55 ;
T_34 V_224 ;
unsigned long V_78 ;
F_31 ( & V_14 -> V_76 , V_78 ) ;
V_55 = F_35 ( V_14 , V_36 ) ;
if ( ! V_55 ) {
goto V_559;
}
V_83 = V_55 -> V_83 ;
V_158 = V_83 -> V_160 ;
if ( ( V_158 -> V_78 & V_177 ) ||
( ( V_158 -> V_78 & V_163 ) ) )
goto V_559;
F_138 ( V_560 , V_83 , L_187 ) ;
F_32 ( & V_14 -> V_76 , V_78 ) ;
if ( V_14 -> V_561 -> V_562 == V_563 )
F_214 ( V_14 , V_36 ) ;
V_224 = F_71 ( T_32 , V_564 ) +
sizeof( T_33 ) ;
V_558 = F_9 ( V_224 , V_8 ) ;
if ( ! V_558 ) {
F_13 ( V_43 L_2 ,
V_14 -> V_44 , __FILE__ , __LINE__ , V_45 ) ;
goto V_87;
}
V_558 -> V_326 = V_565 ;
V_558 -> V_566 =
F_129 ( V_567 ) ;
V_558 -> V_296 = V_224 / 4 ;
V_558 -> V_568 =
F_129 ( sizeof( T_33 ) / 4 ) ;
V_370 = ( T_33 * )
V_558 -> V_564 ;
V_370 -> V_411 = V_569 ;
V_370 -> V_570 = 0x5D ;
V_370 -> V_231 = F_129 ( V_36 ) ;
V_370 -> V_20 = F_216 ( V_158 -> V_18 ) ;
F_217 ( V_14 , V_558 ) ;
F_2 ( V_558 ) ;
V_87:
if ( V_55 )
F_40 ( V_55 ) ;
return;
V_559:
F_32 ( & V_14 -> V_76 , V_78 ) ;
goto V_87;
}
static T_6
F_218 ( struct V_13 * V_14 , T_4 V_100 , T_6 V_290 , T_10 V_291 )
{
T_11 * V_115 ;
T_29 * V_38 ;
struct V_99 * V_102 ;
T_4 V_39 ;
T_10 V_571 ;
T_6 V_502 ;
T_6 V_504 ;
T_10 V_510 ;
struct V_156 * V_157 ;
T_10 V_281 = 0 ;
unsigned long V_78 ;
V_38 = F_116 ( V_14 , V_291 ) ;
V_102 = F_58 ( V_14 , V_100 ) ;
if ( V_102 == NULL )
return 1 ;
V_115 = F_66 ( V_14 , V_100 ) ;
if ( V_38 == NULL ) {
V_102 -> V_345 = V_572 << 16 ;
goto V_87;
}
V_157 = V_102 -> V_52 -> V_160 ;
if ( ! V_157 || ! V_157 -> V_162 ||
V_157 -> V_162 -> V_383 ) {
V_102 -> V_345 = V_346 << 16 ;
goto V_87;
}
V_39 = F_21 ( V_38 -> V_47 ) ;
if ( F_195 ( V_14 , V_100 ) &&
( ( V_39 & V_48 )
!= V_519 ) ) {
F_31 ( & V_14 -> V_103 , V_78 ) ;
V_14 -> V_101 [ V_100 - 1 ] . V_102 = V_102 ;
F_196 ( V_14 , V_100 , 0 ) ;
F_32 ( & V_14 -> V_103 , V_78 ) ;
memcpy ( V_115 -> V_438 . V_466 , V_102 -> V_461 , V_102 -> V_476 ) ;
V_115 -> V_231 =
F_129 ( V_157 -> V_162 -> V_36 ) ;
F_207 ( V_14 , V_100 ,
V_157 -> V_162 -> V_36 ) ;
return 0 ;
}
V_502 = V_38 -> V_503 ;
if ( V_502 & V_535 )
V_281 =
F_86 ( V_38 -> V_544 ) & 0xFF ;
if ( ! V_157 -> V_573 ) {
V_157 -> V_573 ++ ;
if ( ! V_14 -> V_173 && ! F_87 ( & V_102 -> V_52 -> V_222 ) &&
F_106 ( V_102 -> V_52 ) &&
V_281 == V_284 ) {
F_219 ( V_102 -> V_52 ) ;
F_69 ( V_15 , V_102 -> V_52 , L_188 ) ;
}
}
V_571 = F_86 ( V_38 -> V_542 ) ;
F_220 ( V_102 , F_70 ( V_102 ) - V_571 ) ;
if ( V_39 & V_574 )
V_510 = F_86 ( V_38 -> V_334 ) ;
else
V_510 = 0 ;
V_39 &= V_48 ;
V_504 = V_38 -> V_505 ;
if ( V_39 == V_516 && V_571 == 0 &&
( V_504 == V_527 ||
V_504 == V_530 ||
V_504 == V_532 ) ) {
V_39 = V_49 ;
}
if ( V_502 & V_539 ) {
struct V_496 V_497 ;
const void * V_575 = F_221 ( V_14 ,
V_100 ) ;
T_10 V_224 = F_222 ( T_10 , V_488 ,
F_86 ( V_38 -> V_543 ) ) ;
memcpy ( V_102 -> V_449 , V_575 , V_224 ) ;
F_208 ( V_102 -> V_449 , & V_497 ) ;
if ( V_497 . V_499 == 0x5D )
F_215 ( V_14 ,
F_21 ( V_38 -> V_231 ) ) ;
}
switch ( V_39 ) {
case V_576 :
case V_577 :
V_102 -> V_345 = V_578 ;
break;
case V_514 :
V_102 -> V_345 = V_346 << 16 ;
break;
case V_522 :
if ( V_157 -> V_359 ) {
V_102 -> V_345 = V_579 << 16 ;
goto V_87;
}
if ( V_510 == 0x32010081 ) {
V_102 -> V_345 = V_348 << 16 ;
break;
}
V_102 -> V_345 = V_580 << 16 ;
break;
case V_519 :
case V_523 :
V_102 -> V_345 = V_348 << 16 ;
break;
case V_520 :
if ( ( V_571 == 0 ) || ( V_102 -> V_540 > V_571 ) )
V_102 -> V_345 = V_580 << 16 ;
else
V_102 -> V_345 = ( V_572 << 16 ) | V_504 ;
break;
case V_516 :
V_102 -> V_345 = ( V_572 << 16 ) | V_504 ;
if ( ( V_502 & V_539 ) )
break;
if ( V_571 < V_102 -> V_540 ) {
if ( V_504 == V_578 )
V_102 -> V_345 = V_578 ;
else
V_102 -> V_345 = V_580 << 16 ;
} else if ( V_502 & ( V_538 |
V_537 ) )
V_102 -> V_345 = V_580 << 16 ;
else if ( V_502 & V_536 )
V_102 -> V_345 = V_348 << 16 ;
else if ( ! V_571 && V_102 -> V_461 [ 0 ] == V_581 ) {
V_38 -> V_503 = V_539 ;
V_38 -> V_505 = V_453 ;
V_102 -> V_345 = ( V_451 << 24 ) |
V_453 ;
V_102 -> V_449 [ 0 ] = 0x70 ;
V_102 -> V_449 [ 2 ] = V_450 ;
V_102 -> V_449 [ 12 ] = 0x20 ;
V_102 -> V_449 [ 13 ] = 0 ;
}
break;
case V_515 :
F_220 ( V_102 , 0 ) ;
case V_512 :
case V_49 :
V_102 -> V_345 = ( V_572 << 16 ) | V_504 ;
if ( V_281 ==
V_284 ||
( V_502 & ( V_538 |
V_537 ) ) )
V_102 -> V_345 = V_580 << 16 ;
else if ( V_502 & V_536 )
V_102 -> V_345 = V_348 << 16 ;
break;
case V_446 :
case V_448 :
case V_447 :
F_193 ( V_102 , V_39 ) ;
break;
case V_518 :
case V_511 :
case V_582 :
case V_583 :
case V_584 :
case V_585 :
case V_517 :
case V_521 :
default:
V_102 -> V_345 = V_580 << 16 ;
break;
}
#ifdef F_223
if ( V_102 -> V_345 && ( V_14 -> V_16 & V_586 ) )
F_209 ( V_14 , V_102 , V_38 , V_100 ) ;
#endif
V_87:
F_186 ( V_102 ) ;
V_102 -> V_347 ( V_102 ) ;
return 1 ;
}
static void
F_224 ( struct V_13 * V_14 )
{
T_4 V_224 ;
T_4 V_39 ;
int V_104 ;
T_9 V_38 ;
T_35 * V_587 = NULL ;
T_4 V_588 ;
T_6 V_589 ;
F_128 ( V_14 , F_13 ( V_67
L_189 ,
V_14 -> V_44 , ( unsigned long long ) V_14 -> V_40 . V_18 ) ) ;
V_224 = F_71 ( T_35 , V_590 ) + ( V_14 -> V_40 . V_41
* sizeof( V_591 ) ) ;
V_587 = F_9 ( V_224 , V_170 ) ;
if ( ! V_587 ) {
F_13 ( V_43 L_2 ,
V_14 -> V_44 , __FILE__ , __LINE__ , V_45 ) ;
return;
}
if ( ( F_225 ( V_14 , & V_38 ,
V_587 , V_224 ) ) != 0 )
goto V_87;
V_39 = F_21 ( V_38 . V_47 ) & V_48 ;
if ( V_39 != V_49 )
goto V_87;
for ( V_104 = 0 ; V_104 < V_14 -> V_40 . V_41 ; V_104 ++ ) {
V_589 = V_587 -> V_590 [ V_104 ] . V_592 >> 4 ;
if ( V_104 == 0 )
V_14 -> V_40 . V_36 = F_21 ( V_587 ->
V_590 [ 0 ] . V_593 ) ;
V_14 -> V_40 . V_272 [ V_104 ] . V_36 = V_14 -> V_40 . V_36 ;
V_588 = F_21 ( V_587 -> V_590 [ V_104 ] .
V_375 ) ;
if ( V_588 && V_589 < V_594 )
V_589 = V_594 ;
F_226 ( V_14 , V_14 -> V_40 . V_18 ,
V_588 , V_104 , V_589 ) ;
}
V_87:
F_2 ( V_587 ) ;
}
static void
F_227 ( struct V_13 * V_14 )
{
int V_104 ;
T_9 V_38 ;
T_35 * V_587 = NULL ;
T_36 * V_595 = NULL ;
T_37 V_596 ;
T_8 V_37 ;
T_38 V_597 ;
T_4 V_39 ;
T_4 V_224 ;
T_4 V_598 ;
F_228 ( V_14 , & V_14 -> V_40 . V_41 ) ;
if ( ! V_14 -> V_40 . V_41 ) {
F_13 ( V_43 L_2 ,
V_14 -> V_44 , __FILE__ , __LINE__ , V_45 ) ;
return;
}
V_224 = F_71 ( T_35 , V_590 ) + ( V_14 -> V_40 . V_41 *
sizeof( V_591 ) ) ;
V_587 = F_9 ( V_224 , V_170 ) ;
if ( ! V_587 ) {
F_13 ( V_43 L_2 ,
V_14 -> V_44 , __FILE__ , __LINE__ , V_45 ) ;
return;
}
if ( ( F_225 ( V_14 , & V_38 ,
V_587 , V_224 ) ) ) {
F_13 ( V_43 L_2 ,
V_14 -> V_44 , __FILE__ , __LINE__ , V_45 ) ;
goto V_87;
}
V_39 = F_21 ( V_38 . V_47 ) &
V_48 ;
if ( V_39 != V_49 ) {
F_13 ( V_43 L_2 ,
V_14 -> V_44 , __FILE__ , __LINE__ , V_45 ) ;
goto V_87;
}
V_224 = F_71 ( T_36 , V_590 ) + ( V_14 -> V_40 . V_41 *
sizeof( V_599 ) ) ;
V_595 = F_9 ( V_224 , V_170 ) ;
if ( ! V_595 ) {
F_13 ( V_43 L_2 ,
V_14 -> V_44 , __FILE__ , __LINE__ , V_45 ) ;
goto V_87;
}
if ( ( F_229 ( V_14 , & V_38 ,
V_595 , V_224 ) ) ) {
F_13 ( V_43 L_2 ,
V_14 -> V_44 , __FILE__ , __LINE__ , V_45 ) ;
goto V_87;
}
V_39 = F_21 ( V_38 . V_47 ) &
V_48 ;
if ( V_39 != V_49 ) {
F_13 ( V_43 L_2 ,
V_14 -> V_44 , __FILE__ , __LINE__ , V_45 ) ;
goto V_87;
}
V_14 -> V_600 =
F_21 ( V_595 -> V_601 ) ;
V_598 =
F_21 ( V_595 -> V_602 ) ;
if ( V_598 & V_603 )
V_14 -> V_598 = ( V_598 &
V_604 ) * 16 ;
else
V_14 -> V_598 = V_598 &
V_604 ;
V_14 -> V_40 . V_605 = & V_14 -> V_153 -> V_606 ;
V_14 -> V_40 . V_272 = F_230 ( V_14 -> V_40 . V_41 ,
sizeof( struct V_607 ) , V_170 ) ;
if ( ! V_14 -> V_40 . V_272 ) {
F_13 ( V_43 L_2 ,
V_14 -> V_44 , __FILE__ , __LINE__ , V_45 ) ;
goto V_87;
}
for ( V_104 = 0 ; V_104 < V_14 -> V_40 . V_41 ; V_104 ++ ) {
if ( ( F_231 ( V_14 , & V_38 , & V_596 ,
V_104 ) ) ) {
F_13 ( V_43 L_2 ,
V_14 -> V_44 , __FILE__ , __LINE__ , V_45 ) ;
goto V_87;
}
V_39 = F_21 ( V_38 . V_47 ) &
V_48 ;
if ( V_39 != V_49 ) {
F_13 ( V_43 L_2 ,
V_14 -> V_44 , __FILE__ , __LINE__ , V_45 ) ;
goto V_87;
}
if ( V_104 == 0 )
V_14 -> V_40 . V_36 = F_21 ( V_587 ->
V_590 [ 0 ] . V_593 ) ;
V_14 -> V_40 . V_272 [ V_104 ] . V_36 = V_14 -> V_40 . V_36 ;
V_14 -> V_40 . V_272 [ V_104 ] . V_608 = V_104 ;
F_232 ( V_14 , & V_14 -> V_40 . V_272 [ V_104 ] ,
V_596 , V_14 -> V_40 . V_605 ) ;
}
if ( ( F_24 ( V_14 , & V_38 , & V_37 ,
V_42 , V_14 -> V_40 . V_36 ) ) ) {
F_13 ( V_43 L_2 ,
V_14 -> V_44 , __FILE__ , __LINE__ , V_45 ) ;
goto V_87;
}
V_14 -> V_40 . V_554 =
F_21 ( V_37 . V_553 ) ;
V_14 -> V_40 . V_18 = F_18 ( V_37 . V_20 ) ;
F_13 ( V_67 L_190
L_191 , V_14 -> V_44 , V_14 -> V_40 . V_36 ,
( unsigned long long ) V_14 -> V_40 . V_18 ,
V_14 -> V_40 . V_41 ) ;
if ( V_14 -> V_40 . V_554 ) {
if ( ! ( F_233 ( V_14 , & V_38 ,
& V_597 ,
V_609 ,
V_14 -> V_40 . V_554 ) ) ) {
V_14 -> V_40 . V_23 =
F_18 ( V_597 . V_25 ) ;
}
}
V_87:
F_2 ( V_595 ) ;
F_2 ( V_587 ) ;
}
static int
F_234 ( struct V_13 * V_14 , T_4 V_36 )
{
struct V_90 * V_91 ;
T_9 V_38 ;
T_39 V_610 ;
T_40 V_611 ;
T_38 V_597 ;
T_10 V_39 ;
T_4 V_612 ;
T_1 V_18 , V_82 = 0 ;
int V_104 ;
unsigned long V_78 ;
struct V_361 * V_362 = NULL ;
int V_29 = 0 ;
if ( ! V_36 )
return - 1 ;
if ( V_14 -> V_314 || V_14 -> V_316 )
return - 1 ;
if ( ( F_235 ( V_14 , & V_38 , & V_610 ,
V_613 , V_36 ) ) ) {
F_13 ( V_43 L_2 ,
V_14 -> V_44 , __FILE__ , __LINE__ , V_45 ) ;
return - 1 ;
}
V_39 = F_21 ( V_38 . V_47 ) &
V_48 ;
if ( V_39 != V_49 ) {
F_13 ( V_43 L_2 ,
V_14 -> V_44 , __FILE__ , __LINE__ , V_45 ) ;
return - 1 ;
}
V_612 = F_21 ( V_610 . V_614 ) ;
if ( F_23 ( V_14 , V_612 , & V_82 )
!= 0 ) {
F_13 ( V_43 L_2 ,
V_14 -> V_44 , __FILE__ , __LINE__ , V_45 ) ;
return - 1 ;
}
if ( V_82 != V_14 -> V_40 . V_18 ) {
F_31 ( & V_14 -> V_92 , V_78 ) ;
V_91 = F_54 ( V_14 ,
V_82 ) ;
F_32 ( & V_14 -> V_92 , V_78 ) ;
if ( ! V_91 ) {
V_29 = F_234 ( V_14 , V_612 ) ;
if ( V_29 != 0 )
return V_29 ;
}
}
F_31 ( & V_14 -> V_92 , V_78 ) ;
V_18 = F_18 ( V_610 . V_20 ) ;
V_91 = F_54 ( V_14 ,
V_18 ) ;
F_32 ( & V_14 -> V_92 , V_78 ) ;
if ( V_91 )
return 0 ;
V_91 = F_9 ( sizeof( struct V_90 ) ,
V_170 ) ;
if ( ! V_91 ) {
F_13 ( V_43 L_2 ,
V_14 -> V_44 , __FILE__ , __LINE__ , V_45 ) ;
return - 1 ;
}
V_91 -> V_36 = V_36 ;
V_91 -> V_41 = V_610 . V_615 ;
V_91 -> V_82 = V_82 ;
V_91 -> V_18 = V_18 ;
F_13 ( V_67 L_192
L_193 , V_14 -> V_44 ,
V_36 , V_612 , ( unsigned long long )
V_91 -> V_18 , V_91 -> V_41 ) ;
if ( ! V_91 -> V_41 )
goto V_616;
V_91 -> V_272 = F_230 ( V_91 -> V_41 ,
sizeof( struct V_607 ) , V_170 ) ;
if ( ! V_91 -> V_272 ) {
F_13 ( V_43 L_2 ,
V_14 -> V_44 , __FILE__ , __LINE__ , V_45 ) ;
V_29 = - 1 ;
goto V_616;
}
F_165 ( & V_91 -> V_617 ) ;
V_362 = F_44 ( V_14 , V_36 ,
V_82 ) ;
if ( ! V_362 ) {
F_13 ( V_43 L_2 ,
V_14 -> V_44 , __FILE__ , __LINE__ , V_45 ) ;
V_29 = - 1 ;
goto V_616;
}
V_91 -> V_605 = & V_362 -> V_169 -> V_167 ;
for ( V_104 = 0 ; V_104 < V_91 -> V_41 ; V_104 ++ ) {
if ( ( F_236 ( V_14 , & V_38 ,
& V_611 , V_104 , V_36 ) ) ) {
F_13 ( V_43 L_2 ,
V_14 -> V_44 , __FILE__ , __LINE__ , V_45 ) ;
V_29 = - 1 ;
goto V_616;
}
V_91 -> V_272 [ V_104 ] . V_36 = V_36 ;
V_91 -> V_272 [ V_104 ] . V_608 = V_104 ;
if ( ( F_237 ( V_14 ,
& V_91 -> V_272 [ V_104 ] , V_611 ,
V_91 -> V_605 ) ) ) {
F_13 ( V_43 L_2 ,
V_14 -> V_44 , __FILE__ , __LINE__ , V_45 ) ;
V_29 = - 1 ;
goto V_616;
}
}
if ( V_91 -> V_554 ) {
if ( ! ( F_233 ( V_14 , & V_38 ,
& V_597 , V_609 ,
V_91 -> V_554 ) ) ) {
V_91 -> V_23 =
F_18 ( V_597 . V_25 ) ;
}
}
F_55 ( V_14 , V_91 ) ;
return 0 ;
V_616:
if ( V_362 )
F_45 ( V_14 , V_91 -> V_18 ,
V_82 ) ;
F_2 ( V_91 ) ;
return V_29 ;
}
static T_6
F_238 ( struct V_13 * V_14 , T_4 V_100 , T_6 V_290 , T_10 V_291 )
{
T_18 * V_38 ;
V_38 = F_116 ( V_14 , V_291 ) ;
if ( V_14 -> V_618 . V_293 == V_294 )
return 1 ;
if ( V_14 -> V_618 . V_100 != V_100 )
return 1 ;
V_14 -> V_618 . V_293 |= V_295 ;
if ( V_38 ) {
memcpy ( V_14 -> V_618 . V_291 , V_38 ,
V_38 -> V_296 * 4 ) ;
V_14 -> V_618 . V_293 |= V_297 ;
}
V_14 -> V_618 . V_293 &= ~ V_298 ;
F_117 ( & V_14 -> V_618 . V_299 ) ;
return 1 ;
}
void
F_239 ( struct V_13 * V_14 , T_1 V_18 )
{
struct V_90 * V_91 ;
unsigned long V_78 ;
if ( V_14 -> V_314 )
return;
F_31 ( & V_14 -> V_92 , V_78 ) ;
V_91 = F_54 ( V_14 ,
V_18 ) ;
if ( V_91 )
F_52 ( & V_91 -> V_80 ) ;
F_32 ( & V_14 -> V_92 , V_78 ) ;
if ( V_91 )
F_240 ( V_14 , V_91 ) ;
}
static T_6
F_241 ( struct V_13 * V_14 , T_1 V_18 ,
T_4 V_36 , T_6 V_619 )
{
T_6 V_29 = 1 ;
char * V_282 = NULL ;
switch ( V_619 ) {
case V_620 :
case V_621 :
V_29 = 0 ;
break;
case V_622 :
V_282 = L_194 ;
break;
case V_623 :
V_282 = L_195 ;
break;
case V_624 :
V_282 = L_196 ;
break;
case V_625 :
V_282 = L_197 ;
break;
case V_626 :
V_282 = L_198 ;
break;
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
case V_637 :
case V_638 :
V_282 = L_199 ;
break;
default:
V_282 = L_62 ;
break;
}
if ( ! V_29 )
return 0 ;
F_13 ( V_43 L_200
L_96 , V_14 -> V_44 , V_282 ,
( unsigned long long ) V_18 , V_36 ) ;
return V_29 ;
}
static void
F_242 ( struct V_13 * V_14 , T_4 V_36 )
{
T_9 V_38 ;
T_8 V_37 ;
struct V_54 * V_55 ;
T_10 V_39 ;
unsigned long V_78 ;
T_1 V_18 ;
struct V_166 * V_83 ;
struct V_74 * V_158 ;
T_10 V_94 ;
if ( ( F_24 ( V_14 , & V_38 , & V_37 ,
V_42 , V_36 ) ) )
return;
V_39 = F_21 ( V_38 . V_47 ) & V_48 ;
if ( V_39 != V_49 )
return;
V_94 = F_86 ( V_37 . V_182 ) ;
if ( ! ( F_56 ( V_94 ) ) )
return;
F_31 ( & V_14 -> V_76 , V_78 ) ;
V_18 = F_18 ( V_37 . V_20 ) ;
V_55 = F_33 ( V_14 ,
V_18 ) ;
if ( ! V_55 ) {
F_13 ( V_43 L_201
L_202 , V_14 -> V_44 , V_36 ) ;
goto V_559;
}
if ( F_170 ( V_55 -> V_36 != V_36 ) ) {
V_83 = V_55 -> V_83 ;
V_158 = V_83 -> V_160 ;
F_138 ( V_15 , V_83 , L_203
L_204 , V_55 -> V_36 , V_36 ) ;
V_158 -> V_36 = V_36 ;
V_55 -> V_36 = V_36 ;
}
if ( ! ( F_21 ( V_37 . V_181 ) &
V_639 ) ) {
F_13 ( V_43 L_201
L_205 , V_14 -> V_44 , V_36 ) ;
goto V_559;
}
if ( F_241 ( V_14 , V_18 , V_36 ,
V_37 . V_640 ) )
goto V_559;
F_32 ( & V_14 -> V_76 , V_78 ) ;
F_157 ( V_14 , V_18 ) ;
if ( V_55 )
F_40 ( V_55 ) ;
return;
V_559:
F_32 ( & V_14 -> V_76 , V_78 ) ;
if ( V_55 )
F_40 ( V_55 ) ;
}
static int
F_243 ( struct V_13 * V_14 , T_4 V_36 , T_6 V_641 , T_6 V_642 )
{
T_9 V_38 ;
T_8 V_37 ;
T_38 V_597 ;
struct V_54 * V_55 ;
T_10 V_39 ;
T_41 V_18 ;
T_10 V_94 ;
if ( ( F_24 ( V_14 , & V_38 , & V_37 ,
V_42 , V_36 ) ) ) {
F_13 ( V_43 L_2 ,
V_14 -> V_44 , __FILE__ , __LINE__ , V_45 ) ;
return - 1 ;
}
V_39 = F_21 ( V_38 . V_47 ) &
V_48 ;
if ( V_39 != V_49 ) {
F_13 ( V_43 L_2 ,
V_14 -> V_44 , __FILE__ , __LINE__ , V_45 ) ;
return - 1 ;
}
V_18 = F_18 ( V_37 . V_20 ) ;
if ( ! ( F_21 ( V_37 . V_181 ) &
V_639 ) ) {
F_13 ( V_43 L_2 ,
V_14 -> V_44 , __FILE__ , __LINE__ , V_45 ) ;
F_13 ( V_43 L_206 ,
V_14 -> V_44 , F_21 ( V_37 . V_181 ) ) ;
return - 1 ;
}
if ( F_241 ( V_14 , V_18 , V_36 ,
V_37 . V_640 ) )
return - 1 ;
V_94 = F_86 ( V_37 . V_182 ) ;
if ( ! ( F_56 ( V_94 ) ) ) {
F_13 ( V_43 L_2 ,
V_14 -> V_44 , __FILE__ , __LINE__ , V_45 ) ;
return - 1 ;
}
V_55 = F_34 ( V_14 ,
V_18 ) ;
if ( V_55 ) {
F_40 ( V_55 ) ;
return 0 ;
}
V_55 = F_9 ( sizeof( struct V_54 ) ,
V_170 ) ;
if ( ! V_55 ) {
F_13 ( V_43 L_2 ,
V_14 -> V_44 , __FILE__ , __LINE__ , V_45 ) ;
return - 1 ;
}
F_10 ( & V_55 -> V_4 ) ;
V_55 -> V_36 = V_36 ;
if ( F_23 ( V_14 , F_21
( V_37 . V_614 ) ,
& V_55 -> V_82 ) != 0 )
F_13 ( V_43 L_2 ,
V_14 -> V_44 , __FILE__ , __LINE__ , V_45 ) ;
V_55 -> V_554 =
F_21 ( V_37 . V_553 ) ;
V_55 -> V_27 =
F_21 ( V_37 . V_552 ) ;
V_55 -> V_94 = V_94 ;
V_55 -> V_18 = V_18 ;
V_55 -> V_272 = V_37 . V_643 ;
if ( V_55 -> V_554 && ! ( F_233 (
V_14 , & V_38 , & V_597 , V_609 ,
V_55 -> V_554 ) ) )
V_55 -> V_23 =
F_18 ( V_597 . V_25 ) ;
V_55 -> V_21 = F_18 ( V_37 . V_22 ) ;
if ( V_14 -> V_644 )
F_46 ( V_14 , V_55 ) ;
else
F_41 ( V_14 , V_55 ) ;
F_40 ( V_55 ) ;
return 0 ;
}
static void
F_244 ( struct V_13 * V_14 ,
struct V_54 * V_55 )
{
struct V_74 * V_158 ;
if ( ( V_14 -> V_561 -> V_562 == V_563 ) &&
( V_55 -> V_551 ) ) {
F_213 ( V_14 , V_55 ) ;
V_55 -> V_551 = 0 ;
}
F_42 ( V_14 , F_13 ( V_67 L_207
L_108 , V_14 -> V_44 , V_45 ,
V_55 -> V_36 , ( unsigned long long )
V_55 -> V_18 ) ) ;
if ( V_55 -> V_83 && V_55 -> V_83 -> V_160 ) {
V_158 = V_55 -> V_83 -> V_160 ;
V_158 -> V_383 = 1 ;
F_157 ( V_14 , V_55 -> V_18 ) ;
V_158 -> V_36 =
V_171 ;
}
if ( ! V_14 -> V_645 )
F_45 ( V_14 ,
V_55 -> V_18 ,
V_55 -> V_82 ) ;
F_13 ( V_67 L_208
L_209 , V_14 -> V_44 , V_55 -> V_36 ,
( unsigned long long ) V_55 -> V_18 ) ;
F_42 ( V_14 , F_13 ( V_67 L_210
L_108 , V_14 -> V_44 , V_45 ,
V_55 -> V_36 , ( unsigned long long )
V_55 -> V_18 ) ) ;
}
static void
F_245 ( struct V_13 * V_14 , T_4 V_36 )
{
struct V_54 * V_55 ;
unsigned long V_78 ;
if ( V_14 -> V_314 )
return;
F_31 ( & V_14 -> V_76 , V_78 ) ;
V_55 = F_35 ( V_14 , V_36 ) ;
if ( V_55 ) {
F_39 ( & V_55 -> V_80 ) ;
F_40 ( V_55 ) ;
}
F_32 ( & V_14 -> V_76 , V_78 ) ;
if ( V_55 ) {
F_244 ( V_14 , V_55 ) ;
F_40 ( V_55 ) ;
}
}
void
F_246 ( struct V_13 * V_14 ,
T_1 V_18 )
{
struct V_54 * V_55 ;
unsigned long V_78 ;
if ( V_14 -> V_314 )
return;
F_31 ( & V_14 -> V_76 , V_78 ) ;
V_55 = F_33 ( V_14 , V_18 ) ;
if ( V_55 ) {
F_39 ( & V_55 -> V_80 ) ;
F_40 ( V_55 ) ;
}
F_32 ( & V_14 -> V_76 , V_78 ) ;
if ( V_55 ) {
F_244 ( V_14 , V_55 ) ;
F_40 ( V_55 ) ;
}
}
static void
F_247 ( struct V_13 * V_14 ,
T_22 * V_370 )
{
int V_104 ;
T_4 V_36 ;
T_4 V_371 ;
T_6 V_372 ;
char * V_646 = NULL ;
T_6 V_589 , V_647 ;
switch ( V_370 -> V_398 ) {
case V_405 :
V_646 = L_211 ;
break;
case V_402 :
V_646 = L_212 ;
break;
case V_401 :
case 0 :
V_646 = L_213 ;
break;
case V_399 :
V_646 = L_214 ;
break;
default:
V_646 = L_215 ;
break;
}
F_13 ( V_67 L_216 ,
V_14 -> V_44 , V_646 ) ;
F_13 ( V_15 L_217
L_218 ,
F_21 ( V_370 -> V_397 ) ,
F_21 ( V_370 -> V_553 ) ,
V_370 -> V_376 , V_370 -> V_373 ) ;
for ( V_104 = 0 ; V_104 < V_370 -> V_373 ; V_104 ++ ) {
V_36 = F_21 ( V_370 -> V_374 [ V_104 ] . V_375 ) ;
if ( ! V_36 )
continue;
V_372 = V_370 -> V_376 + V_104 ;
V_371 = V_370 -> V_374 [ V_104 ] . V_377 &
V_378 ;
switch ( V_371 ) {
case V_648 :
V_646 = L_219 ;
break;
case V_396 :
V_646 = L_220 ;
break;
case V_379 :
V_646 = L_221 ;
break;
case V_649 :
V_646 = L_222 ;
break;
case V_650 :
V_646 = L_223 ;
break;
default:
V_646 = L_62 ;
break;
}
V_589 = V_370 -> V_374 [ V_104 ] . V_651 >> 4 ;
V_647 = V_370 -> V_374 [ V_104 ] . V_651 & 0xF ;
F_13 ( V_15 L_224
L_225 , V_372 ,
V_36 , V_646 , V_589 , V_647 ) ;
}
}
static void
F_248 ( struct V_13 * V_14 ,
struct V_3 * V_7 )
{
int V_104 ;
T_4 V_612 , V_36 ;
T_4 V_371 ;
T_6 V_372 , V_652 ;
struct V_90 * V_91 ;
T_1 V_18 ;
unsigned long V_78 ;
T_6 V_589 , V_647 ;
T_22 * V_370 =
( T_22 * )
V_7 -> V_370 ;
#ifdef F_223
if ( V_14 -> V_16 & V_653 )
F_247 ( V_14 , V_370 ) ;
#endif
if ( V_14 -> V_315 || V_14 -> V_316 )
return;
if ( ! V_14 -> V_40 . V_41 )
F_227 ( V_14 ) ;
else
F_224 ( V_14 ) ;
if ( V_7 -> V_404 ) {
F_42 ( V_14 , F_13 ( V_67 L_226
L_227 , V_14 -> V_44 ) ) ;
return;
}
V_612 = F_21 ( V_370 -> V_397 ) ;
if ( V_370 -> V_398 == V_405 )
if ( F_234 ( V_14 , V_612 ) != 0 )
return;
F_31 ( & V_14 -> V_92 , V_78 ) ;
V_91 = F_53 ( V_14 ,
V_612 ) ;
if ( V_91 ) {
V_18 = V_91 -> V_18 ;
V_652 = V_91 -> V_41 ;
} else if ( V_612 < V_14 -> V_40 . V_41 ) {
V_18 = V_14 -> V_40 . V_18 ;
V_652 = V_14 -> V_40 . V_41 ;
} else {
F_32 ( & V_14 -> V_92 , V_78 ) ;
return;
}
F_32 ( & V_14 -> V_92 , V_78 ) ;
for ( V_104 = 0 ; V_104 < V_370 -> V_373 ; V_104 ++ ) {
if ( V_7 -> V_404 ) {
F_42 ( V_14 , F_13 ( V_67 L_228
L_229 , V_14 -> V_44 ) ) ;
return;
}
if ( V_14 -> V_314 || V_14 -> V_315 ||
V_14 -> V_316 )
return;
V_372 = V_370 -> V_376 + V_104 ;
if ( V_372 >= V_652 )
continue;
V_371 = V_370 -> V_374 [ V_104 ] . V_377 &
V_378 ;
if ( ( V_370 -> V_374 [ V_104 ] . V_377 &
V_654 ) && ( V_371 !=
V_396 ) )
continue;
V_36 = F_21 ( V_370 -> V_374 [ V_104 ] . V_375 ) ;
if ( ! V_36 )
continue;
V_589 = V_370 -> V_374 [ V_104 ] . V_651 >> 4 ;
V_647 = V_370 -> V_374 [ V_104 ] . V_651 & 0xF ;
switch ( V_371 ) {
case V_649 :
if ( V_14 -> V_314 )
break;
if ( V_589 == V_647 )
break;
F_226 ( V_14 , V_18 ,
V_36 , V_372 , V_589 ) ;
if ( V_589 < V_594 )
break;
F_242 ( V_14 , V_36 ) ;
break;
case V_648 :
if ( V_14 -> V_314 )
break;
F_226 ( V_14 , V_18 ,
V_36 , V_372 , V_589 ) ;
F_243 ( V_14 , V_36 , V_372 , 0 ) ;
break;
case V_396 :
F_245 ( V_14 , V_36 ) ;
break;
}
}
if ( V_370 -> V_398 == V_402 &&
V_91 )
F_239 ( V_14 , V_18 ) ;
}
static void
F_249 ( struct V_13 * V_14 ,
T_33 * V_370 )
{
char * V_655 = NULL ;
switch ( V_370 -> V_411 ) {
case V_569 :
V_655 = L_230 ;
break;
case V_656 :
V_655 = L_231 ;
break;
case V_657 :
V_655 = L_232 ;
break;
case V_658 :
V_655 = L_233 ;
break;
case V_659 :
V_655 = L_234 ;
break;
case V_660 :
V_655 = L_235 ;
break;
case V_661 :
V_655 = L_236 ;
break;
case V_662 :
V_655 = L_237 ;
break;
case V_663 :
V_655 = L_238 ;
break;
case V_664 :
V_655 = L_239 ;
break;
case V_665 :
V_655 = L_240 ;
break;
case V_666 :
V_655 = L_241 ;
break;
case V_667 :
V_655 = L_242 ;
break;
default:
V_655 = L_243 ;
break;
}
F_13 ( V_67 L_244
L_245 ,
V_14 -> V_44 , V_655 , F_21 ( V_370 -> V_231 ) ,
( unsigned long long ) F_18 ( V_370 -> V_20 ) ,
F_21 ( V_370 -> V_541 ) ) ;
if ( V_370 -> V_411 == V_569 )
F_13 ( V_67 L_246 , V_14 -> V_44 ,
V_370 -> V_570 , V_370 -> V_668 ) ;
F_13 ( V_15 L_247 ) ;
}
static void
F_250 ( struct V_13 * V_14 ,
struct V_3 * V_7 )
{
struct V_74 * V_349 ;
struct V_54 * V_55 ;
T_1 V_18 ;
unsigned long V_78 ;
T_33 * V_370 =
( T_33 * )
V_7 -> V_370 ;
#ifdef F_223
if ( V_14 -> V_16 & V_653 )
F_249 ( V_14 ,
V_370 ) ;
#endif
if ( ( V_14 -> V_255 . V_669 >> 8 ) < 0xC )
return;
if ( V_370 -> V_411 !=
V_657 &&
V_370 -> V_411 !=
V_663 )
return;
F_31 ( & V_14 -> V_76 , V_78 ) ;
V_18 = F_18 ( V_370 -> V_20 ) ;
V_55 = F_33 ( V_14 ,
V_18 ) ;
if ( ! V_55 || ! V_55 -> V_83 )
goto V_87;
V_349 = V_55 -> V_83 -> V_160 ;
if ( ! V_349 )
goto V_87;
if ( V_370 -> V_411 ==
V_657 )
V_349 -> V_301 = 1 ;
else
V_349 -> V_301 = 0 ;
V_87:
if ( V_55 )
F_40 ( V_55 ) ;
F_32 ( & V_14 -> V_76 , V_78 ) ;
}
static void
F_251 ( struct V_13 * V_14 ,
T_42 * V_370 )
{
char * V_655 = NULL ;
switch ( V_370 -> V_411 ) {
case V_670 :
V_655 = L_248 ;
break;
case V_671 :
V_655 = L_249 ;
break;
default:
V_655 = L_243 ;
break;
}
F_13 ( V_67 L_250
L_251
L_252 , V_14 -> V_44 , V_655 ,
F_21 ( V_370 -> V_553 ) ,
( unsigned long long ) F_18 ( V_370 -> V_25 ) ,
F_21 ( V_370 -> V_672 ) ) ;
}
static void
F_252 ( struct V_13 * V_14 ,
struct V_3 * V_7 )
{
#ifdef F_223
if ( V_14 -> V_16 & V_653 )
F_251 ( V_14 ,
( T_42 * )
V_7 -> V_370 ) ;
#endif
}
static void
F_253 ( struct V_13 * V_14 ,
struct V_3 * V_7 )
{
struct V_99 * V_102 ;
struct V_150 * V_77 ;
T_4 V_100 , V_36 ;
T_10 V_107 ;
struct V_156 * V_157 ;
T_10 V_673 ;
T_10 V_674 ;
T_21 * V_38 ;
T_43 * V_370 =
( T_43 * )
V_7 -> V_370 ;
T_4 V_39 ;
unsigned long V_78 ;
int V_2 ;
T_6 V_675 = 0 ;
T_6 V_676 ;
F_122 ( & V_14 -> V_292 . V_311 ) ;
F_254 ( V_677
L_253 ,
V_14 -> V_44 , V_45 , V_370 -> V_643 ,
V_370 -> V_678 ) ;
F_158 ( V_14 ) ;
F_31 ( & V_14 -> V_103 , V_78 ) ;
V_38 = V_14 -> V_292 . V_291 ;
V_679:
if ( V_675 ++ == 5 ) {
F_42 ( V_14 , F_13 ( V_67 L_254 ,
V_14 -> V_44 , V_45 ) ) ;
goto V_87;
} else if ( V_675 > 1 )
F_42 ( V_14 , F_13 ( V_67 L_255 ,
V_14 -> V_44 , V_45 , V_675 - 1 ) ) ;
V_673 = 0 ;
V_674 = 0 ;
for ( V_100 = 1 ; V_100 <= V_14 -> V_105 ; V_100 ++ ) {
if ( V_14 -> V_314 )
goto V_87;
V_102 = F_57 ( V_14 , V_100 ) ;
if ( ! V_102 )
continue;
V_77 = V_102 -> V_52 ;
V_157 = V_77 -> V_160 ;
if ( ! V_157 || ! V_157 -> V_162 )
continue;
if ( V_157 -> V_162 -> V_78 &
V_177 )
continue;
if ( V_157 -> V_162 -> V_78 &
V_163 )
continue;
V_36 = V_157 -> V_162 -> V_36 ;
V_107 = V_157 -> V_107 ;
V_674 ++ ;
if ( V_14 -> V_314 )
goto V_87;
F_32 ( & V_14 -> V_103 , V_78 ) ;
V_2 = F_121 ( V_14 , V_36 , 0 , 0 , V_107 ,
V_341 , V_100 , 30 ,
V_680 ) ;
if ( V_2 == V_312 ) {
F_69 ( V_560 , V_77 ,
L_256
L_257 , V_102 ) ;
F_31 ( & V_14 -> V_103 , V_78 ) ;
goto V_679;
}
V_39 = F_21 ( V_38 -> V_47 )
& V_48 ;
if ( V_39 != V_49 ) {
F_69 ( V_560 , V_77 , L_258
L_259 , V_39 ,
V_102 ) ;
F_31 ( & V_14 -> V_103 , V_78 ) ;
goto V_679;
}
if ( V_38 -> V_337 ==
V_287 ||
V_38 -> V_337 ==
V_289 ) {
F_31 ( & V_14 -> V_103 , V_78 ) ;
continue;
}
V_676 = 0 ;
V_681:
if ( V_676 ++ == 60 ) {
F_42 ( V_14 , F_13 ( V_67
L_260 , V_14 -> V_44 ,
V_45 ) ) ;
F_31 ( & V_14 -> V_103 , V_78 ) ;
goto V_679;
}
if ( V_14 -> V_314 )
goto V_682;
V_2 = F_121 ( V_14 , V_36 , V_77 -> V_86 , V_77 -> V_85 ,
V_77 -> V_107 , V_325 , V_100 , 30 ,
V_680 ) ;
if ( V_2 == V_312 ) {
F_69 ( V_560 , V_77 ,
L_261
L_82 , V_102 ) ;
goto V_681;
}
if ( V_676 > 1 )
F_69 ( V_560 , V_77 ,
L_262
L_263 ,
V_676 - 1 , V_102 ) ;
V_673 += F_86 ( V_38 -> V_335 ) ;
F_31 ( & V_14 -> V_103 , V_78 ) ;
}
if ( V_14 -> V_683 ) {
F_42 ( V_14 , F_13 ( V_67 L_264
L_265 , V_14 -> V_44 , V_45 ) ) ;
V_14 -> V_683 = 0 ;
goto V_679;
}
V_87:
F_32 ( & V_14 -> V_103 , V_78 ) ;
V_682:
F_42 ( V_14 , F_13 ( V_67
L_266 ,
V_14 -> V_44 , V_45 , V_674 , V_673 ) ) ;
V_14 -> V_684 = 0 ;
if ( ! V_14 -> V_314 )
F_155 ( V_14 ) ;
F_135 ( & V_14 -> V_292 . V_311 ) ;
}
static void
F_255 ( struct V_13 * V_14 ,
struct V_3 * V_7 )
{
T_44 * V_370 =
( T_44 * )
V_7 -> V_370 ;
#ifdef F_223
if ( V_14 -> V_16 & V_653 ) {
F_13 ( V_67 L_267 , V_14 -> V_44 ,
( V_370 -> V_411 == V_685 ) ?
L_268 : L_269 ) ;
if ( V_370 -> V_686 )
F_13 ( L_270 ,
F_86 ( V_370 -> V_686 ) ) ;
F_13 ( L_247 ) ;
}
#endif
if ( V_370 -> V_411 == V_685 &&
! V_14 -> V_40 . V_41 ) {
if ( V_687 > 0 && V_14 -> V_314 ) {
while ( V_14 -> V_314 )
F_256 ( 1 ) ;
}
F_227 ( V_14 ) ;
}
}
static void
F_257 ( struct V_150 * V_77 , void * V_180 )
{
int V_29 ;
V_77 -> V_180 = V_180 ? 1 : 0 ;
F_69 ( V_15 , V_77 , L_271 ,
V_77 -> V_180 ? L_272 : L_273 ) ;
V_29 = F_258 ( V_77 ) ;
}
static void
F_259 ( struct V_13 * V_14 ,
T_26 * V_408 )
{
struct V_56 * V_57 ;
unsigned long V_78 ;
T_1 V_61 ;
T_4 V_36 = F_21 ( V_408 -> V_414 ) ;
int V_29 ;
F_109 ( V_14 , V_36 , & V_61 ) ;
if ( ! V_61 ) {
F_13 ( V_43
L_2 , V_14 -> V_44 ,
__FILE__ , __LINE__ , V_45 ) ;
return;
}
F_31 ( & V_14 -> V_88 , V_78 ) ;
V_57 = F_49 ( V_14 , V_61 ) ;
F_32 ( & V_14 -> V_88 , V_78 ) ;
if ( V_57 )
return;
V_57 = F_9 ( sizeof( struct V_56 ) , V_170 ) ;
if ( ! V_57 ) {
F_13 ( V_43
L_2 , V_14 -> V_44 ,
__FILE__ , __LINE__ , V_45 ) ;
return;
}
V_57 -> V_85 = V_14 -> V_688 ++ ;
V_57 -> V_86 = V_172 ;
V_57 -> V_36 = V_36 ;
V_57 -> V_61 = V_61 ;
F_50 ( V_14 , V_57 ) ;
if ( ! V_14 -> V_644 ) {
V_29 = F_260 ( V_14 -> V_153 , V_172 ,
V_57 -> V_85 , 0 ) ;
if ( V_29 )
F_51 ( V_14 , V_57 ) ;
} else {
F_31 ( & V_14 -> V_88 , V_78 ) ;
F_25 ( V_14 , V_57 , 1 ) ;
F_32 ( & V_14 -> V_88 , V_78 ) ;
}
}
static void
F_261 ( struct V_13 * V_14 , T_4 V_36 )
{
struct V_56 * V_57 ;
unsigned long V_78 ;
struct V_74 * V_158 ;
struct V_166 * V_83 = NULL ;
F_31 ( & V_14 -> V_88 , V_78 ) ;
V_57 = F_48 ( V_14 , V_36 ) ;
if ( V_57 ) {
if ( V_57 -> V_83 ) {
V_83 = V_57 -> V_83 ;
V_158 = V_83 -> V_160 ;
V_158 -> V_383 = 1 ;
}
F_13 ( V_67 L_274
L_209 , V_14 -> V_44 , V_57 -> V_36 ,
( unsigned long long ) V_57 -> V_61 ) ;
F_52 ( & V_57 -> V_80 ) ;
F_2 ( V_57 ) ;
}
F_32 ( & V_14 -> V_88 , V_78 ) ;
if ( V_83 )
F_262 ( & V_83 -> V_167 ) ;
}
static void
F_263 ( struct V_13 * V_14 ,
T_26 * V_408 )
{
struct V_54 * V_55 ;
struct V_166 * V_83 = NULL ;
struct V_74 * V_158 ;
unsigned long V_78 ;
T_4 V_36 = F_21 ( V_408 -> V_417 ) ;
F_31 ( & V_14 -> V_76 , V_78 ) ;
V_55 = F_35 ( V_14 , V_36 ) ;
if ( V_55 ) {
V_55 -> V_261 = 0 ;
V_55 -> V_262 = 0 ;
F_181 ( V_36 , V_14 -> V_176 ) ;
if ( V_55 -> V_83 && V_55 -> V_83 -> V_160 ) {
V_83 = V_55 -> V_83 ;
V_158 = V_83 -> V_160 ;
V_158 -> V_78 &=
~ V_177 ;
}
}
F_32 ( & V_14 -> V_76 , V_78 ) ;
if ( ! V_55 )
return;
if ( V_83 )
F_264 ( V_83 , NULL , F_257 ) ;
F_40 ( V_55 ) ;
}
static void
F_265 ( struct V_13 * V_14 ,
T_26 * V_408 )
{
struct V_54 * V_55 ;
struct V_166 * V_83 = NULL ;
struct V_74 * V_158 ;
unsigned long V_78 ;
T_4 V_36 = F_21 ( V_408 -> V_417 ) ;
T_4 V_261 = 0 ;
T_1 V_262 = 0 ;
F_108 ( V_14 , V_36 , & V_261 ) ;
if ( V_261 )
F_109 ( V_14 , V_261 ,
& V_262 ) ;
F_31 ( & V_14 -> V_76 , V_78 ) ;
V_55 = F_35 ( V_14 , V_36 ) ;
if ( V_55 ) {
F_162 ( V_36 , V_14 -> V_176 ) ;
if ( V_55 -> V_83 && V_55 -> V_83 -> V_160 ) {
V_83 = V_55 -> V_83 ;
V_158 = V_83 -> V_160 ;
V_158 -> V_78 |=
V_177 ;
V_55 -> V_261 = V_261 ;
V_55 -> V_262 = V_262 ;
}
}
F_32 ( & V_14 -> V_76 , V_78 ) ;
if ( ! V_55 )
return;
if ( V_83 )
F_264 ( V_83 , ( void * ) 1 , F_257 ) ;
F_40 ( V_55 ) ;
}
static void
F_266 ( struct V_13 * V_14 ,
T_26 * V_408 )
{
T_4 V_36 = F_21 ( V_408 -> V_417 ) ;
F_245 ( V_14 , V_36 ) ;
}
static void
F_267 ( struct V_13 * V_14 ,
T_26 * V_408 )
{
struct V_54 * V_55 ;
T_4 V_36 = F_21 ( V_408 -> V_417 ) ;
T_9 V_38 ;
T_8 V_37 ;
T_10 V_39 ;
T_1 V_18 ;
T_4 V_612 ;
F_162 ( V_36 , V_14 -> V_176 ) ;
V_55 = F_36 ( V_14 , V_36 ) ;
if ( V_55 ) {
F_40 ( V_55 ) ;
return;
}
if ( ( F_24 ( V_14 , & V_38 , & V_37 ,
V_42 , V_36 ) ) ) {
F_13 ( V_43 L_2 ,
V_14 -> V_44 , __FILE__ , __LINE__ , V_45 ) ;
return;
}
V_39 = F_21 ( V_38 . V_47 ) &
V_48 ;
if ( V_39 != V_49 ) {
F_13 ( V_43 L_2 ,
V_14 -> V_44 , __FILE__ , __LINE__ , V_45 ) ;
return;
}
V_612 = F_21 ( V_37 . V_614 ) ;
if ( ! F_23 ( V_14 , V_612 , & V_18 ) )
F_226 ( V_14 , V_18 , V_36 ,
V_37 . V_643 , V_594 ) ;
F_243 ( V_14 , V_36 , 0 , 1 ) ;
}
static void
F_268 ( struct V_13 * V_14 ,
T_25 * V_370 )
{
T_26 * V_408 ;
T_6 V_689 ;
int V_104 ;
char * V_655 = NULL , * V_690 = NULL ;
V_408 = ( T_26 * ) & V_370 -> V_409 [ 0 ] ;
F_13 ( V_67 L_275 ,
V_14 -> V_44 , ( F_86 ( V_370 -> V_181 ) &
V_415 ) ?
L_276 : L_277 , V_370 -> V_410 ) ;
for ( V_104 = 0 ; V_104 < V_370 -> V_410 ; V_104 ++ , V_408 ++ ) {
switch ( V_408 -> V_411 ) {
case V_691 :
V_655 = L_211 ;
break;
case V_413 :
V_655 = L_212 ;
break;
case V_692 :
V_655 = L_278 ;
break;
case V_693 :
V_655 = L_279 ;
break;
case V_416 :
V_655 = L_280 ;
break;
case V_694 :
V_655 = L_281 ;
break;
case V_412 :
V_655 = L_282 ;
break;
case V_695 :
V_655 = L_283 ;
break;
case V_696 :
V_655 = L_284 ;
break;
default:
V_655 = L_243 ;
break;
}
V_689 = F_21 ( V_408 -> V_697 ) &
V_698 ;
switch ( V_689 ) {
case V_699 :
V_690 = L_75 ;
break;
case V_700 :
V_690 = L_285 ;
break;
case V_701 :
V_690 = L_286 ;
break;
default:
V_690 = L_287 ;
break;
}
F_13 ( V_15 L_288
L_289 , V_690 ,
V_655 , F_21 ( V_408 -> V_414 ) ,
F_21 ( V_408 -> V_417 ) ,
V_408 -> V_230 ) ;
}
}
static void
F_269 ( struct V_13 * V_14 ,
struct V_3 * V_7 )
{
T_26 * V_408 ;
int V_104 ;
T_6 V_702 ;
T_25 * V_370 =
( T_25 * )
V_7 -> V_370 ;
#ifdef F_223
if ( ( V_14 -> V_16 & V_653 )
&& ! V_14 -> V_271 )
F_268 ( V_14 , V_370 ) ;
#endif
if ( V_14 -> V_314 )
return;
V_702 = ( F_86 ( V_370 -> V_181 ) &
V_415 ) ? 1 : 0 ;
V_408 = ( T_26 * ) & V_370 -> V_409 [ 0 ] ;
for ( V_104 = 0 ; V_104 < V_370 -> V_410 ; V_104 ++ , V_408 ++ ) {
switch ( V_408 -> V_411 ) {
case V_694 :
case V_691 :
if ( ! V_702 )
F_259 ( V_14 , V_408 ) ;
break;
case V_412 :
case V_413 :
if ( ! V_702 )
F_261 ( V_14 ,
F_21 ( V_408 -> V_414 ) ) ;
break;
case V_695 :
if ( ! V_14 -> V_173 )
F_265 ( V_14 , V_408 ) ;
break;
case V_696 :
if ( ! V_14 -> V_173 )
F_263 ( V_14 , V_408 ) ;
break;
case V_693 :
if ( ! V_14 -> V_173 )
F_267 ( V_14 , V_408 ) ;
break;
case V_416 :
if ( ! V_14 -> V_173 )
F_266 ( V_14 , V_408 ) ;
break;
}
}
}
static void
F_270 ( struct V_13 * V_14 ,
struct V_3 * V_7 )
{
T_1 V_61 ;
unsigned long V_78 ;
struct V_56 * V_57 ;
T_4 V_36 ;
T_10 V_198 ;
int V_29 ;
T_27 * V_370 =
( T_27 * )
V_7 -> V_370 ;
if ( V_14 -> V_314 )
return;
if ( V_370 -> V_411 != V_418 )
return;
V_36 = F_21 ( V_370 -> V_414 ) ;
V_198 = F_86 ( V_370 -> V_419 ) ;
if ( ! V_14 -> V_271 )
F_42 ( V_14 , F_13 ( V_67 L_49
L_290 , V_14 -> V_44 , V_45 , V_36 ,
F_86 ( V_370 -> V_703 ) , V_198 ) ) ;
switch ( V_198 ) {
case V_208 :
case V_207 :
F_261 ( V_14 , V_36 ) ;
break;
case V_203 :
case V_205 :
case V_202 :
F_31 ( & V_14 -> V_88 , V_78 ) ;
V_57 = F_48 ( V_14 , V_36 ) ;
F_32 ( & V_14 -> V_88 , V_78 ) ;
if ( V_57 )
break;
F_109 ( V_14 , V_36 , & V_61 ) ;
if ( ! V_61 ) {
F_13 ( V_43
L_2 , V_14 -> V_44 ,
__FILE__ , __LINE__ , V_45 ) ;
break;
}
V_57 = F_9 ( sizeof( struct V_56 ) , V_170 ) ;
if ( ! V_57 ) {
F_13 ( V_43
L_2 , V_14 -> V_44 ,
__FILE__ , __LINE__ , V_45 ) ;
break;
}
V_57 -> V_85 = V_14 -> V_688 ++ ;
V_57 -> V_86 = V_172 ;
V_57 -> V_36 = V_36 ;
V_57 -> V_61 = V_61 ;
F_50 ( V_14 , V_57 ) ;
V_29 = F_260 ( V_14 -> V_153 , V_172 ,
V_57 -> V_85 , 0 ) ;
if ( V_29 )
F_51 ( V_14 , V_57 ) ;
break;
case V_704 :
default:
break;
}
}
static void
F_271 ( struct V_13 * V_14 ,
struct V_3 * V_7 )
{
T_4 V_36 , V_612 ;
T_10 V_198 ;
struct V_54 * V_55 ;
T_9 V_38 ;
T_8 V_37 ;
T_10 V_39 ;
T_45 * V_370 =
( T_45 * )
V_7 -> V_370 ;
T_1 V_18 ;
if ( V_14 -> V_314 )
return;
if ( V_370 -> V_411 != V_705 )
return;
V_36 = F_21 ( V_370 -> V_417 ) ;
V_198 = F_86 ( V_370 -> V_419 ) ;
if ( ! V_14 -> V_271 )
F_42 ( V_14 , F_13 ( V_67 L_49
L_290 , V_14 -> V_44 , V_45 , V_36 ,
F_86 ( V_370 -> V_703 ) , V_198 ) ) ;
switch ( V_198 ) {
case V_706 :
case V_707 :
case V_708 :
case V_709 :
case V_710 :
if ( ! V_14 -> V_173 )
F_162 ( V_36 , V_14 -> V_176 ) ;
V_55 = F_36 ( V_14 , V_36 ) ;
if ( V_55 ) {
F_40 ( V_55 ) ;
return;
}
if ( ( F_24 ( V_14 , & V_38 ,
& V_37 , V_42 ,
V_36 ) ) ) {
F_13 ( V_43 L_2 ,
V_14 -> V_44 , __FILE__ , __LINE__ , V_45 ) ;
return;
}
V_39 = F_21 ( V_38 . V_47 ) &
V_48 ;
if ( V_39 != V_49 ) {
F_13 ( V_43 L_2 ,
V_14 -> V_44 , __FILE__ , __LINE__ , V_45 ) ;
return;
}
V_612 = F_21 ( V_37 . V_614 ) ;
if ( ! F_23 ( V_14 , V_612 , & V_18 ) )
F_226 ( V_14 , V_18 , V_36 ,
V_37 . V_643 , V_594 ) ;
F_243 ( V_14 , V_36 , 0 , 1 ) ;
break;
case V_711 :
case V_712 :
case V_713 :
default:
break;
}
}
static void
F_272 ( struct V_13 * V_14 ,
T_46 * V_370 )
{
char * V_655 = NULL ;
switch ( V_370 -> V_714 ) {
case V_715 :
V_655 = L_291 ;
break;
case V_716 :
V_655 = L_292 ;
break;
case V_717 :
V_655 = L_293 ;
break;
case V_718 :
V_655 = L_294 ;
break;
case V_719 :
V_655 = L_295 ;
break;
}
if ( ! V_655 )
return;
F_13 ( V_67 L_296
L_297 ,
V_14 -> V_44 , V_655 ,
F_21 ( V_370 -> V_414 ) ,
V_370 -> V_720 ) ;
}
static void
F_273 ( struct V_13 * V_14 ,
struct V_3 * V_7 )
{
T_46 * V_370 =
( T_46 * )
V_7 -> V_370 ;
static struct V_56 * V_57 ;
unsigned long V_78 ;
T_4 V_36 ;
#ifdef F_223
if ( ( V_14 -> V_16 & V_653 )
&& ! V_14 -> V_271 )
F_272 ( V_14 ,
V_370 ) ;
#endif
if ( V_370 -> V_714 == V_715 ) {
F_31 ( & V_14 -> V_88 , V_78 ) ;
V_36 = F_21 ( V_370 -> V_414 ) ;
V_57 = F_48 ( V_14 , V_36 ) ;
if ( V_57 )
V_57 -> V_191 =
V_370 -> V_720 ;
F_32 ( & V_14 -> V_88 , V_78 ) ;
}
}
static void
F_274 ( struct V_13 * V_14 )
{
struct V_156 * V_157 ;
struct V_150 * V_77 ;
F_119 (sdev, ioc->shost) {
V_157 = V_77 -> V_160 ;
if ( V_157 && V_157 -> V_162 )
V_157 -> V_162 -> V_383 = 1 ;
}
}
static void
F_275 ( struct V_13 * V_14 , T_1 V_18 ,
T_4 V_27 , T_4 V_36 )
{
struct V_74 * V_158 = NULL ;
struct V_166 * V_83 ;
struct V_54 * V_55 ;
unsigned long V_78 ;
F_31 ( & V_14 -> V_76 , V_78 ) ;
F_15 (sas_device, &ioc->sas_device_list, list) {
if ( V_55 -> V_18 == V_18 &&
V_55 -> V_27 == V_27 ) {
V_55 -> V_721 = 1 ;
V_83 = V_55 -> V_83 ;
if ( V_83 && V_83 -> V_160 ) {
V_158 = V_83 -> V_160 ;
V_158 -> V_301 = 0 ;
V_158 -> V_383 = 0 ;
} else
V_158 = NULL ;
if ( V_83 )
F_138 ( V_15 , V_83 ,
L_298
L_299
L_300 , V_36 ,
( unsigned long long ) V_55 -> V_18 ,
( unsigned long long )
V_55 -> V_23 ,
V_55 -> V_27 ) ;
if ( V_55 -> V_36 == V_36 )
goto V_87;
F_13 ( V_15 L_301 ,
V_55 -> V_36 ) ;
V_55 -> V_36 = V_36 ;
if ( V_158 )
V_158 -> V_36 = V_36 ;
goto V_87;
}
}
V_87:
F_32 ( & V_14 -> V_76 , V_78 ) ;
}
static void
F_276 ( struct V_13 * V_14 )
{
T_8 V_37 ;
T_9 V_38 ;
T_4 V_39 ;
T_41 V_18 ;
T_4 V_36 ;
T_10 V_94 ;
T_4 V_27 ;
F_13 ( V_67 L_302 , V_14 -> V_44 ) ;
if ( F_38 ( & V_14 -> V_81 ) )
goto V_87;
V_36 = 0xFFFF ;
while ( ! ( F_24 ( V_14 , & V_38 ,
& V_37 , V_722 ,
V_36 ) ) ) {
V_39 = F_21 ( V_38 . V_47 ) &
V_48 ;
if ( V_39 != V_49 )
break;
V_36 = F_21 ( V_37 . V_231 ) ;
V_94 = F_86 ( V_37 . V_182 ) ;
if ( ! ( F_56 ( V_94 ) ) )
continue;
V_18 = F_18 ( V_37 . V_20 ) ;
V_27 = F_21 ( V_37 . V_552 ) ;
F_275 ( V_14 , V_18 , V_27 ,
V_36 ) ;
}
V_87:
F_13 ( V_67 L_303 ,
V_14 -> V_44 ) ;
}
static void
F_277 ( struct V_13 * V_14 , T_1 V_61 ,
T_4 V_36 )
{
struct V_74 * V_158 ;
struct V_166 * V_83 ;
struct V_56 * V_57 ;
unsigned long V_78 ;
F_31 ( & V_14 -> V_88 , V_78 ) ;
F_15 (raid_device, &ioc->raid_device_list, list) {
if ( V_57 -> V_61 == V_61 && V_57 -> V_83 ) {
V_83 = V_57 -> V_83 ;
if ( V_83 && V_83 -> V_160 ) {
V_158 = V_83 -> V_160 ;
V_158 -> V_383 = 0 ;
} else
V_158 = NULL ;
V_57 -> V_721 = 1 ;
F_32 ( & V_14 -> V_88 , V_78 ) ;
F_138 ( V_15 , V_57 -> V_83 ,
L_304 , V_36 ,
( unsigned long long ) V_57 -> V_61 ) ;
F_102 ( V_14 , V_57 ) ;
F_31 ( & V_14 -> V_88 , V_78 ) ;
if ( V_57 -> V_36 == V_36 ) {
F_32 ( & V_14 -> V_88 ,
V_78 ) ;
return;
}
F_13 ( V_15 L_301 ,
V_57 -> V_36 ) ;
V_57 -> V_36 = V_36 ;
if ( V_158 )
V_158 -> V_36 = V_36 ;
F_32 ( & V_14 -> V_88 , V_78 ) ;
return;
}
}
F_32 ( & V_14 -> V_88 , V_78 ) ;
}
static void
F_278 ( struct V_13 * V_14 )
{
T_15 V_723 ;
T_13 V_724 ;
T_14 V_223 ;
T_9 V_38 ;
T_4 V_39 ;
T_4 V_36 ;
T_6 V_725 ;
if ( ! V_14 -> V_726 )
return;
F_13 ( V_67 L_305 ,
V_14 -> V_44 ) ;
if ( F_38 ( & V_14 -> V_89 ) )
goto V_87;
V_36 = 0xFFFF ;
while ( ! ( F_100 ( V_14 , & V_38 ,
& V_723 , V_233 , V_36 ) ) ) {
V_39 = F_21 ( V_38 . V_47 ) &
V_48 ;
if ( V_39 != V_49 )
break;
V_36 = F_21 ( V_723 . V_231 ) ;
if ( F_90 ( V_14 , & V_38 ,
& V_724 , V_192 , V_36 ,
sizeof( T_13 ) ) )
continue;
if ( V_724 . V_201 == V_202 ||
V_724 . V_201 == V_203 ||
V_724 . V_201 == V_205 )
F_277 ( V_14 ,
F_18 ( V_723 . V_727 ) , V_36 ) ;
}
if ( ! V_14 -> V_173 ) {
V_725 = 0xFF ;
memset ( V_14 -> V_176 , 0 , V_14 -> V_728 ) ;
while ( ! ( F_98 ( V_14 , & V_38 ,
& V_223 , V_729 ,
V_725 ) ) ) {
V_39 = F_21 ( V_38 . V_47 ) &
V_48 ;
if ( V_39 != V_49 )
break;
V_725 = V_223 . V_230 ;
V_36 = F_21 ( V_223 . V_231 ) ;
F_162 ( V_36 , V_14 -> V_176 ) ;
}
}
V_87:
F_13 ( V_67 L_306
L_307 , V_14 -> V_44 ) ;
}
static void
F_279 ( struct V_13 * V_14 , T_1 V_18 ,
T_4 V_36 )
{
struct V_90 * V_91 ;
unsigned long V_78 ;
int V_104 ;
F_31 ( & V_14 -> V_92 , V_78 ) ;
F_15 (sas_expander, &ioc->sas_expander_list, list) {
if ( V_91 -> V_18 != V_18 )
continue;
V_91 -> V_721 = 1 ;
if ( V_91 -> V_36 == V_36 )
goto V_87;
F_13 ( V_15 L_308
L_309 ,
( unsigned long long ) V_91 -> V_18 ,
V_91 -> V_36 , V_36 ) ;
V_91 -> V_36 = V_36 ;
for ( V_104 = 0 ; V_104 < V_91 -> V_41 ; V_104 ++ )
V_91 -> V_272 [ V_104 ] . V_36 = V_36 ;
goto V_87;
}
V_87:
F_32 ( & V_14 -> V_92 , V_78 ) ;
}
static void
F_280 ( struct V_13 * V_14 )
{
T_39 V_610 ;
T_9 V_38 ;
T_4 V_39 ;
T_1 V_18 ;
T_4 V_36 ;
F_13 ( V_67 L_310 , V_14 -> V_44 ) ;
if ( F_38 ( & V_14 -> V_93 ) )
goto V_87;
V_36 = 0xFFFF ;
while ( ! ( F_235 ( V_14 , & V_38 , & V_610 ,
V_730 , V_36 ) ) ) {
V_39 = F_21 ( V_38 . V_47 ) &
V_48 ;
if ( V_39 != V_49 )
break;
V_36 = F_21 ( V_610 . V_231 ) ;
V_18 = F_18 ( V_610 . V_20 ) ;
F_13 ( V_15 L_311
L_312 , V_36 ,
( unsigned long long ) V_18 ) ;
F_279 ( V_14 , V_18 , V_36 ) ;
}
V_87:
F_13 ( V_67 L_313 , V_14 -> V_44 ) ;
}
static void
F_281 ( struct V_13 * V_14 )
{
struct V_54 * V_55 , * V_731 ;
struct V_90 * V_91 , * V_732 ;
struct V_56 * V_57 , * V_733 ;
struct V_734 V_735 ;
unsigned long V_78 ;
F_282 ( V_736 ) ;
F_13 ( V_67 L_314 ,
V_14 -> V_44 ) ;
F_13 ( V_67 L_315 ,
V_14 -> V_44 ) ;
F_31 ( & V_14 -> V_76 , V_78 ) ;
F_283 (sas_device, sas_device_next,
&ioc->sas_device_list, list) {
if ( ! V_55 -> V_721 )
F_284 ( & V_55 -> V_80 , & V_736 ) ;
else
V_55 -> V_721 = 0 ;
}
F_32 ( & V_14 -> V_76 , V_78 ) ;
F_283 (sas_device, sas_device_next, &head, list) {
F_244 ( V_14 , V_55 ) ;
F_39 ( & V_55 -> V_80 ) ;
F_40 ( V_55 ) ;
}
if ( V_14 -> V_726 ) {
F_13 ( V_67 L_316
L_317 , V_14 -> V_44 ) ;
F_283 (raid_device, raid_device_next,
&ioc->raid_device_list, list) {
if ( ! V_57 -> V_721 )
F_261 ( V_14 ,
V_57 -> V_36 ) ;
else
V_57 -> V_721 = 0 ;
}
}
F_13 ( V_67 L_318 ,
V_14 -> V_44 ) ;
F_31 ( & V_14 -> V_92 , V_78 ) ;
F_165 ( & V_735 ) ;
F_283 (sas_expander, sas_expander_next,
&ioc->sas_expander_list, list) {
if ( ! V_91 -> V_721 )
F_284 ( & V_91 -> V_80 , & V_735 ) ;
else
V_91 -> V_721 = 0 ;
}
F_32 ( & V_14 -> V_92 , V_78 ) ;
F_283 (sas_expander, sas_expander_next, &tmp_list,
list) {
F_52 ( & V_91 -> V_80 ) ;
F_240 ( V_14 , V_91 ) ;
}
F_13 ( V_67 L_319 ,
V_14 -> V_44 ) ;
F_155 ( V_14 ) ;
}
static void
F_285 ( struct V_13 * V_14 ,
struct V_90 * V_91 , T_4 V_36 )
{
T_40 V_611 ;
T_9 V_38 ;
int V_104 ;
for ( V_104 = 0 ; V_104 < V_91 -> V_41 ; V_104 ++ ) {
if ( ( F_236 ( V_14 , & V_38 ,
& V_611 , V_104 , V_36 ) ) ) {
F_13 ( V_43 L_2 ,
V_14 -> V_44 , __FILE__ , __LINE__ , V_45 ) ;
return;
}
F_226 ( V_14 , V_91 -> V_18 ,
F_21 ( V_611 . V_375 ) , V_104 ,
V_611 . V_592 >> 4 ) ;
}
}
static void
F_286 ( struct V_13 * V_14 )
{
T_39 V_610 ;
T_8 V_37 ;
T_15 V_723 ;
T_13 V_724 ;
T_14 V_223 ;
T_26 V_408 ;
T_9 V_38 ;
T_6 V_725 ;
T_4 V_39 ;
T_4 V_36 , V_612 ;
T_1 V_18 ;
struct V_54 * V_55 ;
struct V_90 * V_737 ;
static struct V_56 * V_57 ;
T_6 V_738 ;
unsigned long V_78 ;
F_13 ( V_67 L_320 , V_14 -> V_44 ) ;
F_224 ( V_14 ) ;
F_13 ( V_67 L_321 ,
V_14 -> V_44 ) ;
V_36 = 0xFFFF ;
while ( ! ( F_235 ( V_14 , & V_38 , & V_610 ,
V_730 , V_36 ) ) ) {
V_39 = F_21 ( V_38 . V_47 ) &
V_48 ;
if ( V_39 != V_49 ) {
F_13 ( V_67 L_322
L_323 ,
V_14 -> V_44 , V_39 ,
F_86 ( V_38 . V_334 ) ) ;
break;
}
V_36 = F_21 ( V_610 . V_231 ) ;
F_31 ( & V_14 -> V_92 , V_78 ) ;
V_737 = F_54 (
V_14 , F_18 ( V_610 . V_20 ) ) ;
F_32 ( & V_14 -> V_92 , V_78 ) ;
if ( V_737 )
F_285 ( V_14 , V_737 ,
V_36 ) ;
else {
F_13 ( V_67 L_324
L_325 ,
V_14 -> V_44 , V_36 , ( unsigned long long )
F_18 ( V_610 . V_20 ) ) ;
F_234 ( V_14 , V_36 ) ;
F_13 ( V_67 L_326
L_325 ,
V_14 -> V_44 , V_36 , ( unsigned long long )
F_18 ( V_610 . V_20 ) ) ;
}
}
F_13 ( V_67 L_327 ,
V_14 -> V_44 ) ;
if ( ! V_14 -> V_726 )
goto V_739;
F_13 ( V_67 L_328 , V_14 -> V_44 ) ;
V_725 = 0xFF ;
while ( ! ( F_98 ( V_14 , & V_38 ,
& V_223 , V_729 ,
V_725 ) ) ) {
V_39 = F_21 ( V_38 . V_47 ) &
V_48 ;
if ( V_39 != V_49 ) {
F_13 ( V_67 L_329
L_323 ,
V_14 -> V_44 , V_39 ,
F_86 ( V_38 . V_334 ) ) ;
break;
}
V_725 = V_223 . V_230 ;
V_36 = F_21 ( V_223 . V_231 ) ;
V_55 = F_36 ( V_14 , V_36 ) ;
if ( V_55 ) {
F_40 ( V_55 ) ;
continue;
}
if ( F_24 ( V_14 , & V_38 ,
& V_37 , V_42 ,
V_36 ) != 0 )
continue;
V_39 = F_21 ( V_38 . V_47 ) &
V_48 ;
if ( V_39 != V_49 ) {
F_13 ( V_67 L_330
L_323 ,
V_14 -> V_44 , V_39 ,
F_86 ( V_38 . V_334 ) ) ;
break;
}
V_612 = F_21 ( V_37 . V_614 ) ;
if ( ! F_23 ( V_14 , V_612 ,
& V_18 ) ) {
F_13 ( V_67 L_331
L_332 ,
V_14 -> V_44 , V_36 , ( unsigned long long )
F_18 ( V_37 . V_20 ) ) ;
F_226 ( V_14 , V_18 ,
V_36 , V_37 . V_643 ,
V_594 ) ;
F_162 ( V_36 , V_14 -> V_176 ) ;
V_738 = 0 ;
while ( F_243 ( V_14 , V_36 , V_738 ++ ,
1 ) ) {
F_256 ( 1 ) ;
}
F_13 ( V_67 L_333
L_332 ,
V_14 -> V_44 , V_36 , ( unsigned long long )
F_18 ( V_37 . V_20 ) ) ;
}
}
F_13 ( V_67 L_334 ,
V_14 -> V_44 ) ;
F_13 ( V_67 L_335 , V_14 -> V_44 ) ;
V_36 = 0xFFFF ;
while ( ! ( F_100 ( V_14 , & V_38 ,
& V_723 , V_233 , V_36 ) ) ) {
V_39 = F_21 ( V_38 . V_47 ) &
V_48 ;
if ( V_39 != V_49 ) {
F_13 ( V_67 L_336
L_323 ,
V_14 -> V_44 , V_39 ,
F_86 ( V_38 . V_334 ) ) ;
break;
}
V_36 = F_21 ( V_723 . V_231 ) ;
F_31 ( & V_14 -> V_88 , V_78 ) ;
V_57 = F_49 ( V_14 ,
F_18 ( V_723 . V_727 ) ) ;
F_32 ( & V_14 -> V_88 , V_78 ) ;
if ( V_57 )
continue;
if ( F_90 ( V_14 , & V_38 ,
& V_724 , V_192 , V_36 ,
sizeof( T_13 ) ) )
continue;
V_39 = F_21 ( V_38 . V_47 ) &
V_48 ;
if ( V_39 != V_49 ) {
F_13 ( V_67 L_336
L_323 ,
V_14 -> V_44 , V_39 ,
F_86 ( V_38 . V_334 ) ) ;
break;
}
if ( V_724 . V_201 == V_202 ||
V_724 . V_201 == V_203 ||
V_724 . V_201 == V_205 ) {
memset ( & V_408 , 0 , sizeof( T_26 ) ) ;
V_408 . V_411 = V_691 ;
V_408 . V_414 = V_723 . V_231 ;
F_13 ( V_67 L_337
L_338 , V_14 -> V_44 ,
V_723 . V_231 ) ;
F_259 ( V_14 , & V_408 ) ;
F_13 ( V_67 L_339
L_338 , V_14 -> V_44 ,
V_723 . V_231 ) ;
}
}
F_13 ( V_67 L_340 ,
V_14 -> V_44 ) ;
V_739:
F_13 ( V_67 L_341 ,
V_14 -> V_44 ) ;
V_36 = 0xFFFF ;
while ( ! ( F_24 ( V_14 , & V_38 ,
& V_37 , V_722 ,
V_36 ) ) ) {
V_39 = F_21 ( V_38 . V_47 ) &
V_48 ;
if ( V_39 != V_49 ) {
F_13 ( V_67 L_342
L_343 ,
V_14 -> V_44 , V_39 ,
F_86 ( V_38 . V_334 ) ) ;
break;
}
V_36 = F_21 ( V_37 . V_231 ) ;
if ( ! ( F_56 (
F_86 ( V_37 . V_182 ) ) ) )
continue;
V_55 = F_34 ( V_14 ,
F_18 ( V_37 . V_20 ) ) ;
if ( V_55 ) {
F_40 ( V_55 ) ;
continue;
}
V_612 = F_21 ( V_37 . V_614 ) ;
if ( ! F_23 ( V_14 , V_612 , & V_18 ) ) {
F_13 ( V_67 L_344
L_325 ,
V_14 -> V_44 , V_36 , ( unsigned long long )
F_18 ( V_37 . V_20 ) ) ;
F_226 ( V_14 , V_18 , V_36 ,
V_37 . V_643 , V_594 ) ;
V_738 = 0 ;
while ( F_243 ( V_14 , V_36 , V_738 ++ ,
0 ) ) {
F_256 ( 1 ) ;
}
F_13 ( V_67 L_345
L_325 ,
V_14 -> V_44 , V_36 , ( unsigned long long )
F_18 ( V_37 . V_20 ) ) ;
}
}
F_13 ( V_67 L_346 ,
V_14 -> V_44 ) ;
F_13 ( V_67 L_347 , V_14 -> V_44 ) ;
}
void
F_287 ( struct V_13 * V_14 , int V_740 )
{
switch ( V_740 ) {
case V_741 :
F_128 ( V_14 , F_13 ( V_67 L_52
L_348 , V_14 -> V_44 , V_45 ) ) ;
break;
case V_742 :
F_128 ( V_14 , F_13 ( V_67 L_52
L_349 , V_14 -> V_44 , V_45 ) ) ;
if ( V_14 -> V_618 . V_293 & V_298 ) {
V_14 -> V_618 . V_293 |= V_333 ;
F_175 ( V_14 , V_14 -> V_618 . V_100 ) ;
F_117 ( & V_14 -> V_618 . V_299 ) ;
}
if ( V_14 -> V_292 . V_293 & V_298 ) {
V_14 -> V_292 . V_293 |= V_333 ;
F_175 ( V_14 , V_14 -> V_292 . V_100 ) ;
F_117 ( & V_14 -> V_292 . V_299 ) ;
}
F_152 ( V_14 ) ;
F_185 ( V_14 ) ;
break;
case V_743 :
F_128 ( V_14 , F_13 ( V_67 L_52
L_350 , V_14 -> V_44 , V_45 ) ) ;
F_224 ( V_14 ) ;
F_274 ( V_14 ) ;
F_276 ( V_14 ) ;
F_278 ( V_14 ) ;
F_280 ( V_14 ) ;
if ( ( ! V_14 -> V_58 ) && ! ( V_687 > 0 &&
! V_14 -> V_40 . V_41 ) ) {
F_274 ( V_14 ) ;
F_276 ( V_14 ) ;
F_278 ( V_14 ) ;
F_280 ( V_14 ) ;
F_148 ( V_14 ) ;
}
break;
}
}
static void
V_355 ( struct V_744 * V_745 )
{
struct V_3 * V_7 = F_3 ( V_745 ,
struct V_3 , V_354 . V_745 ) ;
struct V_13 * V_14 = V_7 -> V_14 ;
F_147 ( V_14 , V_7 ) ;
if ( V_14 -> V_315 || V_14 -> V_316 ) {
F_6 ( V_7 ) ;
return;
}
switch ( V_7 -> V_356 ) {
case V_357 :
while ( F_288 ( V_14 -> V_153 ) ||
V_14 -> V_314 ) {
if ( V_14 -> V_315 )
goto V_87;
F_256 ( 1 ) ;
}
F_281 ( V_14 ) ;
F_286 ( V_14 ) ;
break;
case V_358 :
V_14 -> V_746 = 0 ;
if ( V_747 [ 0 ] != - 1 && V_747 [ 1 ] != - 1 )
F_289 ( V_14 , V_747 [ 0 ] ,
V_747 [ 1 ] ) ;
F_42 ( V_14 , F_13 ( V_67 L_351
L_352 , V_14 -> V_44 ) ) ;
break;
case V_556 :
F_211 ( V_14 , V_7 -> V_557 ) ;
break;
case V_403 :
F_248 ( V_14 , V_7 ) ;
break;
case V_567 :
F_250 ( V_14 ,
V_7 ) ;
break;
case V_748 :
F_255 ( V_14 ,
V_7 ) ;
break;
case V_749 :
F_253 ( V_14 ,
V_7 ) ;
break;
case V_750 :
F_252 ( V_14 ,
V_7 ) ;
break;
case V_751 :
F_269 ( V_14 , V_7 ) ;
break;
case V_752 :
F_270 ( V_14 , V_7 ) ;
break;
case V_753 :
F_271 ( V_14 , V_7 ) ;
break;
case V_754 :
F_273 ( V_14 , V_7 ) ;
break;
}
V_87:
F_6 ( V_7 ) ;
}
void
F_290 ( struct V_13 * V_14 , T_6 V_290 ,
T_10 V_291 )
{
struct V_3 * V_7 ;
T_32 * V_38 ;
T_4 V_356 ;
T_4 V_224 ;
if ( V_14 -> V_315 || V_14 -> V_316 )
return;
V_38 = F_116 ( V_14 , V_291 ) ;
if ( F_170 ( ! V_38 ) ) {
F_13 ( V_43 L_114 ,
V_14 -> V_44 , __FILE__ , __LINE__ , V_45 ) ;
return;
}
V_356 = F_21 ( V_38 -> V_566 ) ;
switch ( V_356 ) {
case V_749 :
{
T_43 * V_755 =
( T_43 * )
V_38 -> V_564 ;
if ( V_755 -> V_756 !=
V_757 )
return;
if ( V_14 -> V_684 ) {
V_14 -> V_683 ++ ;
return;
} else
V_14 -> V_684 = 1 ;
break;
}
case V_403 :
F_176 ( V_14 ,
( T_22 * )
V_38 -> V_564 ) ;
break;
case V_751 :
F_180 ( V_14 ,
( T_25 * )
V_38 -> V_564 ) ;
break;
case V_752 :
F_183 ( V_14 ,
( T_27 * )
V_38 -> V_564 ) ;
break;
case V_758 :
{
T_47 * V_759 ;
T_48 * V_760 ;
if ( ! V_14 -> V_173 )
break;
V_759 = ( T_47 * )
V_38 -> V_564 ;
V_760 = ( T_48 * ) V_759 -> V_761 ;
if ( F_21 ( V_759 -> V_762 )
!= V_763 )
break;
switch ( F_86 ( * V_760 ) ) {
case V_764 :
F_13 ( V_111 L_353
L_354
L_355
L_356 , V_14 -> V_44 ) ;
break;
case V_765 :
F_13 ( V_111 L_353
L_357
L_358
L_359 , V_14 -> V_44 ) ;
break;
case V_766 :
F_13 ( V_43 L_360
L_361
L_362
L_363
L_359 , V_14 -> V_44 ) ;
break;
case V_767 :
F_13 ( V_43 L_360
L_364
L_365
L_366 ,
V_14 -> V_44 ) ;
break;
}
break;
}
case V_567 :
case V_754 :
case V_748 :
case V_750 :
case V_753 :
break;
case V_768 :
F_184 ( V_14 ,
( T_28 * )
V_38 -> V_564 ) ;
break;
default:
return;
}
V_224 = F_21 ( V_38 -> V_568 ) * 4 ;
V_7 = F_8 ( V_224 ) ;
if ( ! V_7 ) {
F_13 ( V_43 L_2 ,
V_14 -> V_44 , __FILE__ , __LINE__ , V_45 ) ;
return;
}
memcpy ( V_7 -> V_370 , V_38 -> V_564 , V_224 ) ;
V_7 -> V_14 = V_14 ;
V_7 -> V_494 = V_38 -> V_494 ;
V_7 -> V_495 = V_38 -> V_495 ;
V_7 -> V_356 = V_356 ;
F_144 ( V_14 , V_7 ) ;
F_6 ( V_7 ) ;
return;
}
static void
F_240 ( struct V_13 * V_14 ,
struct V_90 * V_91 )
{
struct V_361 * V_362 , * V_112 ;
F_283 (mpt2sas_port, next,
&sas_expander->sas_port_list, port_list) {
if ( V_14 -> V_314 )
return;
if ( V_362 -> V_364 . V_365 ==
V_366 )
F_246 ( V_14 ,
V_362 -> V_364 . V_18 ) ;
else if ( V_362 -> V_364 . V_365 ==
V_368 ||
V_362 -> V_364 . V_365 ==
V_369 )
F_239 ( V_14 ,
V_362 -> V_364 . V_18 ) ;
}
F_45 ( V_14 , V_91 -> V_18 ,
V_91 -> V_82 ) ;
F_13 ( V_67 L_367
L_8 , V_14 -> V_44 ,
V_91 -> V_36 , ( unsigned long long )
V_91 -> V_18 ) ;
F_2 ( V_91 -> V_272 ) ;
F_2 ( V_91 ) ;
}
static void
F_291 ( struct V_13 * V_14 )
{
T_49 * V_115 ;
T_50 * V_38 ;
T_4 V_100 ;
if ( ! V_14 -> V_726 )
return;
F_122 ( & V_14 -> V_618 . V_311 ) ;
if ( V_14 -> V_618 . V_293 != V_294 ) {
F_13 ( V_43 L_368 ,
V_14 -> V_44 , V_45 ) ;
goto V_87;
}
V_14 -> V_618 . V_293 = V_298 ;
V_100 = F_173 ( V_14 , V_14 -> V_769 ) ;
if ( ! V_100 ) {
F_13 ( V_43 L_68 ,
V_14 -> V_44 , V_45 ) ;
V_14 -> V_618 . V_293 = V_294 ;
goto V_87;
}
V_115 = F_66 ( V_14 , V_100 ) ;
V_14 -> V_618 . V_100 = V_100 ;
memset ( V_115 , 0 , sizeof( T_49 ) ) ;
V_115 -> V_326 = V_770 ;
V_115 -> V_546 = V_771 ;
if ( ! V_14 -> V_271 )
F_13 ( V_67 L_369 , V_14 -> V_44 ) ;
F_131 ( & V_14 -> V_618 . V_299 ) ;
F_174 ( V_14 , V_100 ) ;
F_133 ( & V_14 -> V_618 . V_299 , 10 * V_332 ) ;
if ( ! ( V_14 -> V_618 . V_293 & V_295 ) ) {
F_13 ( V_43 L_71 ,
V_14 -> V_44 , V_45 ) ;
goto V_87;
}
if ( V_14 -> V_618 . V_293 & V_297 ) {
V_38 = V_14 -> V_618 . V_291 ;
if ( ! V_14 -> V_271 )
F_13 ( V_67 L_370
L_323 ,
V_14 -> V_44 , F_21 ( V_38 -> V_47 ) ,
F_86 ( V_38 -> V_334 ) ) ;
}
V_87:
V_14 -> V_618 . V_293 = V_294 ;
F_135 ( & V_14 -> V_618 . V_311 ) ;
}
static void
F_292 ( struct V_772 * V_561 )
{
struct V_152 * V_153 = F_293 ( V_561 ) ;
struct V_13 * V_14 = F_76 ( V_153 ) ;
struct V_773 * V_774 ;
unsigned long V_78 ;
V_14 -> V_315 = 1 ;
F_152 ( V_14 ) ;
F_31 ( & V_14 -> V_352 , V_78 ) ;
V_774 = V_14 -> V_351 ;
V_14 -> V_351 = NULL ;
F_32 ( & V_14 -> V_352 , V_78 ) ;
if ( V_774 )
F_294 ( V_774 ) ;
F_291 ( V_14 ) ;
F_295 ( V_14 ) ;
}
static void
F_296 ( struct V_772 * V_561 )
{
struct V_152 * V_153 = F_293 ( V_561 ) ;
struct V_13 * V_14 = F_76 ( V_153 ) ;
struct V_361 * V_362 , * V_775 ;
struct V_56 * V_57 , * V_112 ;
struct V_74 * V_158 ;
struct V_773 * V_774 ;
unsigned long V_78 ;
V_14 -> V_315 = 1 ;
F_152 ( V_14 ) ;
F_31 ( & V_14 -> V_352 , V_78 ) ;
V_774 = V_14 -> V_351 ;
V_14 -> V_351 = NULL ;
F_32 ( & V_14 -> V_352 , V_78 ) ;
if ( V_774 )
F_294 ( V_774 ) ;
F_291 ( V_14 ) ;
F_283 (raid_device, next, &ioc->raid_device_list,
list) {
if ( V_57 -> V_83 ) {
V_158 =
V_57 -> V_83 -> V_160 ;
V_158 -> V_383 = 1 ;
F_262 ( & V_57 -> V_83 -> V_167 ) ;
}
F_13 ( V_67 L_274
L_209 , V_14 -> V_44 , V_57 -> V_36 ,
( unsigned long long ) V_57 -> V_61 ) ;
F_51 ( V_14 , V_57 ) ;
}
F_283 (mpt2sas_port, next_port,
&ioc->sas_hba.sas_port_list, port_list) {
if ( V_362 -> V_364 . V_365 ==
V_366 )
F_246 ( V_14 ,
V_362 -> V_364 . V_18 ) ;
else if ( V_362 -> V_364 . V_365 ==
V_368 ||
V_362 -> V_364 . V_365 ==
V_369 )
F_239 ( V_14 ,
V_362 -> V_364 . V_18 ) ;
}
if ( V_14 -> V_40 . V_41 ) {
F_2 ( V_14 -> V_40 . V_272 ) ;
V_14 -> V_40 . V_272 = NULL ;
V_14 -> V_40 . V_41 = 0 ;
}
F_297 ( V_153 ) ;
F_298 ( V_153 ) ;
F_295 ( V_14 ) ;
F_14 ( & V_17 ) ;
F_52 ( & V_14 -> V_80 ) ;
F_16 ( & V_17 ) ;
F_299 ( V_153 ) ;
}
static void
F_300 ( struct V_13 * V_14 )
{
T_6 V_53 ;
void * V_52 ;
struct V_54 * V_55 ;
struct V_56 * V_57 ;
T_4 V_36 ;
T_1 V_82 ;
T_1 V_18 ;
unsigned long V_78 ;
int V_29 ;
if ( ! V_14 -> V_59 . V_60 )
return;
V_52 = NULL ;
V_53 = 0 ;
if ( V_14 -> V_62 . V_52 ) {
V_52 = V_14 -> V_62 . V_52 ;
V_53 = V_14 -> V_62 . V_53 ;
} else if ( V_14 -> V_68 . V_52 ) {
V_52 = V_14 -> V_68 . V_52 ;
V_53 = V_14 -> V_68 . V_53 ;
} else if ( V_14 -> V_71 . V_52 ) {
V_52 = V_14 -> V_71 . V_52 ;
V_53 = V_14 -> V_71 . V_53 ;
}
if ( ! V_52 )
return;
if ( V_53 ) {
V_57 = V_52 ;
V_29 = F_260 ( V_14 -> V_153 , V_172 ,
V_57 -> V_85 , 0 ) ;
if ( V_29 )
F_51 ( V_14 , V_57 ) ;
} else {
F_31 ( & V_14 -> V_76 , V_78 ) ;
V_55 = V_52 ;
V_36 = V_55 -> V_36 ;
V_82 = V_55 -> V_82 ;
V_18 = V_55 -> V_18 ;
F_284 ( & V_55 -> V_80 , & V_14 -> V_81 ) ;
F_32 ( & V_14 -> V_76 , V_78 ) ;
if ( V_14 -> V_645 )
return;
if ( ! F_44 ( V_14 , V_55 -> V_36 ,
V_55 -> V_82 ) ) {
F_37 ( V_14 , V_55 ) ;
} else if ( ! V_55 -> V_83 ) {
if ( ! V_14 -> V_58 ) {
F_45 ( V_14 ,
V_18 ,
V_82 ) ;
F_37 ( V_14 , V_55 ) ;
}
}
}
}
static void
F_301 ( struct V_13 * V_14 )
{
struct V_56 * V_57 , * V_776 ;
int V_29 ;
F_283 (raid_device, raid_next,
&ioc->raid_device_list, list) {
if ( V_57 -> V_83 )
continue;
V_29 = F_260 ( V_14 -> V_153 , V_172 ,
V_57 -> V_85 , 0 ) ;
if ( V_29 )
F_51 ( V_14 , V_57 ) ;
}
}
static struct V_54 * F_302 ( struct V_13 * V_14 )
{
struct V_54 * V_55 = NULL ;
unsigned long V_78 ;
F_31 ( & V_14 -> V_76 , V_78 ) ;
if ( ! F_38 ( & V_14 -> V_84 ) ) {
V_55 = F_151 ( & V_14 -> V_84 ,
struct V_54 , V_80 ) ;
F_29 ( V_55 ) ;
}
F_32 ( & V_14 -> V_76 , V_78 ) ;
return V_55 ;
}
static void F_303 ( struct V_13 * V_14 ,
struct V_54 * V_55 )
{
unsigned long V_78 ;
F_31 ( & V_14 -> V_76 , V_78 ) ;
if ( ! F_38 ( & V_55 -> V_80 ) ) {
F_39 ( & V_55 -> V_80 ) ;
F_40 ( V_55 ) ;
}
F_29 ( V_55 ) ;
F_43 ( & V_55 -> V_80 , & V_14 -> V_81 ) ;
F_32 ( & V_14 -> V_76 , V_78 ) ;
}
static void
F_304 ( struct V_13 * V_14 )
{
struct V_54 * V_55 ;
if ( V_14 -> V_645 )
return;
while ( ( V_55 = F_302 ( V_14 ) ) ) {
if ( ! F_44 ( V_14 , V_55 -> V_36 ,
V_55 -> V_82 ) ) {
F_37 ( V_14 , V_55 ) ;
F_40 ( V_55 ) ;
continue;
} else if ( ! V_55 -> V_83 ) {
if ( ! V_14 -> V_58 ) {
F_45 ( V_14 ,
V_55 -> V_18 ,
V_55 -> V_82 ) ;
F_37 ( V_14 , V_55 ) ;
F_40 ( V_55 ) ;
continue;
}
}
F_303 ( V_14 , V_55 ) ;
F_40 ( V_55 ) ;
}
}
static void
F_305 ( struct V_13 * V_14 )
{
T_4 V_777 ;
if ( ! ( V_14 -> V_255 . V_778 & V_779 ) )
return;
F_300 ( V_14 ) ;
if ( V_14 -> V_726 ) {
V_777 =
F_21 ( V_14 -> V_780 . V_781 ) &
V_782 ;
if ( V_777 ==
V_783 ) {
F_301 ( V_14 ) ;
F_304 ( V_14 ) ;
} else {
F_304 ( V_14 ) ;
F_301 ( V_14 ) ;
}
} else
F_304 ( V_14 ) ;
}
static void
F_306 ( struct V_152 * V_153 )
{
struct V_13 * V_14 = F_76 ( V_153 ) ;
int V_29 ;
if ( V_784 != - 1 && V_784 != 0 )
F_307 ( V_14 , V_784 ) ;
if ( V_687 > 0 )
return;
V_14 -> V_746 = 1 ;
V_29 = F_308 ( V_14 ) ;
if ( V_29 != 0 )
F_13 ( V_67 L_371 , V_14 -> V_44 ) ;
}
static int
F_309 ( struct V_152 * V_153 , unsigned long time )
{
struct V_13 * V_14 = F_76 ( V_153 ) ;
if ( V_687 > 0 ) {
V_14 -> V_58 = 0 ;
V_14 -> V_644 = 0 ;
return 1 ;
}
if ( time >= ( 300 * V_332 ) ) {
V_14 -> V_785 . V_293 = V_294 ;
F_13 ( V_67 L_372
L_373 , V_14 -> V_44 ) ;
V_14 -> V_58 = 0 ;
return 1 ;
}
if ( V_14 -> V_746 )
return 0 ;
if ( V_14 -> V_786 ) {
F_13 ( V_67 L_374
L_375 , V_14 -> V_44 , V_14 -> V_786 ) ;
V_14 -> V_58 = 0 ;
V_14 -> V_644 = 0 ;
V_14 -> V_315 = 1 ;
return 1 ;
}
F_13 ( V_67 L_376 , V_14 -> V_44 ) ;
V_14 -> V_785 . V_293 = V_294 ;
if ( V_14 -> V_644 ) {
V_14 -> V_644 = 0 ;
F_305 ( V_14 ) ;
}
F_310 ( V_14 ) ;
V_14 -> V_58 = 0 ;
return 1 ;
}
static int
F_311 ( struct V_772 * V_561 , const struct V_787 * V_85 )
{
struct V_13 * V_14 ;
struct V_152 * V_153 ;
int V_788 ;
V_153 = F_312 ( & V_789 ,
sizeof( struct V_13 ) ) ;
if ( ! V_153 )
return - V_790 ;
V_14 = F_76 ( V_153 ) ;
memset ( V_14 , 0 , sizeof( struct V_13 ) ) ;
F_165 ( & V_14 -> V_80 ) ;
F_14 ( & V_17 ) ;
F_43 ( & V_14 -> V_80 , & V_791 ) ;
F_16 ( & V_17 ) ;
V_14 -> V_153 = V_153 ;
V_14 -> V_85 = V_792 ++ ;
sprintf ( V_14 -> V_44 , L_377 , V_793 , V_14 -> V_85 ) ;
V_14 -> V_561 = V_561 ;
if ( V_85 -> V_52 == V_794 ) {
V_14 -> V_173 = 1 ;
V_14 -> V_271 = 1 ;
} else
V_14 -> V_242 = V_243 ;
V_14 -> V_478 = V_478 ;
V_14 -> V_324 = V_324 ;
V_14 -> V_795 = V_795 ;
V_14 -> V_796 = V_796 ;
V_14 -> V_797 = V_797 ;
V_14 -> V_798 = V_798 ;
V_14 -> V_769 = V_769 ;
V_14 -> V_799 = V_799 ;
V_14 -> V_384 = V_384 ;
V_14 -> V_386 = V_386 ;
V_14 -> V_390 = V_390 ;
V_14 -> V_16 = V_16 ;
V_14 -> V_800 = & F_185 ;
F_313 ( & V_14 -> V_801 ) ;
F_313 ( & V_14 -> V_802 ) ;
F_314 ( & V_14 -> V_803 ) ;
F_314 ( & V_14 -> V_103 ) ;
F_314 ( & V_14 -> V_76 ) ;
F_314 ( & V_14 -> V_92 ) ;
F_314 ( & V_14 -> V_352 ) ;
F_314 ( & V_14 -> V_88 ) ;
F_165 ( & V_14 -> V_81 ) ;
F_165 ( & V_14 -> V_84 ) ;
F_165 ( & V_14 -> V_93 ) ;
F_165 ( & V_14 -> V_353 ) ;
F_165 ( & V_14 -> V_89 ) ;
F_165 ( & V_14 -> V_40 . V_617 ) ;
F_165 ( & V_14 -> V_385 ) ;
F_165 ( & V_14 -> V_387 ) ;
F_165 ( & V_14 -> V_804 ) ;
V_153 -> V_805 = 32 ;
V_153 -> V_806 = V_806 ;
V_153 -> V_807 = V_808 ;
V_153 -> V_809 = V_14 -> V_85 ;
if ( V_810 != 0xFFFF ) {
if ( V_810 < 64 ) {
V_153 -> V_810 = 64 ;
F_13 ( V_111 L_378
L_379
L_380 , V_14 -> V_44 , V_810 ) ;
} else if ( V_810 > 32767 ) {
V_153 -> V_810 = 32767 ;
F_13 ( V_111 L_378
L_381
L_382 , V_14 -> V_44 ,
V_810 ) ;
} else {
V_153 -> V_810 = V_810 & 0xFFFE ;
F_13 ( V_67 L_383
L_384 , V_14 -> V_44 , V_153 -> V_810 ) ;
}
}
if ( V_811 )
F_315 ( V_153 , V_811 ) ;
else
F_315 ( V_153 , V_812
| V_813
| V_814 ) ;
F_316 ( V_153 , V_815 ) ;
snprintf ( V_14 -> V_816 , sizeof( V_14 -> V_816 ) ,
L_385 , V_14 -> V_85 ) ;
V_14 -> V_351 = F_317 (
V_14 -> V_816 ) ;
if ( ! V_14 -> V_351 ) {
F_13 ( V_43 L_2 ,
V_14 -> V_44 , __FILE__ , __LINE__ , V_45 ) ;
V_788 = - V_790 ;
goto V_817;
}
V_14 -> V_58 = 1 ;
if ( ( F_318 ( V_14 ) ) ) {
F_13 ( V_43 L_2 ,
V_14 -> V_44 , __FILE__ , __LINE__ , V_45 ) ;
V_788 = - V_790 ;
goto V_818;
}
if ( V_14 -> V_173 ) {
if ( V_14 -> V_242 == V_243 )
V_14 -> V_645 = 0 ;
else if ( V_14 -> V_242 == V_819 )
V_14 -> V_645 = 1 ;
else {
if ( F_101 ( V_14 ) )
V_14 -> V_645 = 1 ;
else
V_14 -> V_645 = 0 ;
}
} else
V_14 -> V_645 = 0 ;
V_788 = F_319 ( V_153 , & V_561 -> V_167 ) ;
if ( V_788 ) {
F_13 ( V_43 L_2 ,
V_14 -> V_44 , __FILE__ , __LINE__ , V_45 ) ;
goto V_820;
}
F_320 ( V_153 ) ;
return 0 ;
V_820:
F_295 ( V_14 ) ;
V_818:
F_294 ( V_14 -> V_351 ) ;
V_817:
F_14 ( & V_17 ) ;
F_52 ( & V_14 -> V_80 ) ;
F_16 ( & V_17 ) ;
F_299 ( V_153 ) ;
return V_788 ;
}
static int
F_321 ( struct V_772 * V_561 , T_51 V_198 )
{
struct V_152 * V_153 = F_293 ( V_561 ) ;
struct V_13 * V_14 = F_76 ( V_153 ) ;
T_52 V_821 ;
F_322 ( V_14 ) ;
F_323 ( V_153 ) ;
F_291 ( V_14 ) ;
V_821 = F_324 ( V_561 , V_198 ) ;
F_13 ( V_67 L_386
L_387 , V_14 -> V_44 , V_561 ,
F_325 ( V_561 ) , V_821 ) ;
F_326 ( V_14 ) ;
F_327 ( V_561 ) ;
F_328 ( V_561 , V_821 ) ;
return 0 ;
}
static int
F_329 ( struct V_772 * V_561 )
{
struct V_152 * V_153 = F_293 ( V_561 ) ;
struct V_13 * V_14 = F_76 ( V_153 ) ;
T_52 V_821 = V_561 -> V_822 ;
int V_2 ;
F_13 ( V_67 L_388
L_387 , V_14 -> V_44 , V_561 ,
F_325 ( V_561 ) , V_821 ) ;
F_328 ( V_561 , V_823 ) ;
F_330 ( V_561 , V_823 , 0 ) ;
F_331 ( V_561 ) ;
V_14 -> V_561 = V_561 ;
V_2 = F_332 ( V_14 ) ;
if ( V_2 )
return V_2 ;
F_125 ( V_14 , V_318 , V_824 ) ;
F_333 ( V_153 ) ;
F_310 ( V_14 ) ;
return 0 ;
}
static T_53
F_334 ( struct V_772 * V_561 , T_54 V_198 )
{
struct V_152 * V_153 = F_293 ( V_561 ) ;
struct V_13 * V_14 = F_76 ( V_153 ) ;
F_13 ( V_67 L_389 ,
V_14 -> V_44 , V_198 ) ;
switch ( V_198 ) {
case V_825 :
return V_826 ;
case V_827 :
V_14 -> V_316 = 1 ;
F_323 ( V_14 -> V_153 ) ;
F_322 ( V_14 ) ;
F_326 ( V_14 ) ;
return V_828 ;
case V_829 :
V_14 -> V_316 = 1 ;
F_322 ( V_14 ) ;
F_185 ( V_14 ) ;
return V_830 ;
}
return V_828 ;
}
static T_53
F_335 ( struct V_772 * V_561 )
{
struct V_152 * V_153 = F_293 ( V_561 ) ;
struct V_13 * V_14 = F_76 ( V_153 ) ;
int V_29 ;
F_13 ( V_67 L_390 ,
V_14 -> V_44 ) ;
V_14 -> V_316 = 0 ;
V_14 -> V_561 = V_561 ;
F_331 ( V_561 ) ;
V_29 = F_332 ( V_14 ) ;
if ( V_29 )
return V_830 ;
V_29 = F_125 ( V_14 , V_318 ,
V_319 ) ;
F_13 ( V_111 L_391 , V_14 -> V_44 ,
( V_29 == 0 ) ? L_137 : L_392 ) ;
if ( ! V_29 )
return V_831 ;
else
return V_830 ;
}
static void
F_336 ( struct V_772 * V_561 )
{
struct V_152 * V_153 = F_293 ( V_561 ) ;
struct V_13 * V_14 = F_76 ( V_153 ) ;
F_13 ( V_67 L_393 , V_14 -> V_44 ) ;
F_337 ( V_561 ) ;
F_310 ( V_14 ) ;
F_333 ( V_14 -> V_153 ) ;
}
static T_53
F_338 ( struct V_772 * V_561 )
{
struct V_152 * V_153 = F_293 ( V_561 ) ;
struct V_13 * V_14 = F_76 ( V_153 ) ;
F_13 ( V_67 L_394 ,
V_14 -> V_44 ) ;
return V_828 ;
}
static int T_55
F_339 ( void )
{
int error ;
V_792 = 0 ;
F_13 ( V_15 L_395 , V_793 ,
V_832 ) ;
V_808 =
F_340 ( & V_833 ) ;
if ( ! V_808 )
return - V_790 ;
V_195 = F_341 ( & V_834 ) ;
if ( ! V_195 ) {
F_342 ( V_808 ) ;
return - V_790 ;
}
F_343 () ;
V_478 = F_344 ( F_218 ) ;
V_324 = F_344 ( F_114 ) ;
V_796 = F_344 ( V_835 ) ;
V_797 = F_344 (
V_836 ) ;
V_798 = F_344 (
V_837 ) ;
V_769 = F_344 ( F_238 ) ;
V_799 = F_344 (
V_838 ) ;
V_795 = F_344 ( V_839 ) ;
V_384 = F_344 (
F_172 ) ;
V_386 = F_344 (
F_169 ) ;
V_390 = F_344 (
F_166 ) ;
F_345 () ;
error = F_346 ( & V_840 ) ;
if ( error ) {
F_347 ( V_195 ) ;
F_342 ( V_808 ) ;
}
return error ;
}
static void T_56
F_348 ( void )
{
F_13 ( V_15 L_396 ,
V_832 ) ;
F_349 ( & V_840 ) ;
F_350 () ;
F_351 ( V_478 ) ;
F_351 ( V_324 ) ;
F_351 ( V_796 ) ;
F_351 ( V_797 ) ;
F_351 ( V_798 ) ;
F_351 ( V_769 ) ;
F_351 ( V_799 ) ;
F_351 ( V_795 ) ;
F_351 ( V_384 ) ;
F_351 ( V_386 ) ;
F_351 ( V_390 ) ;
F_347 ( V_195 ) ;
F_342 ( V_808 ) ;
}
