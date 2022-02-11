static inline T_1 F_1 ( struct V_1 * V_2 ,
unsigned int V_3 )
{
T_1 V_4 = F_2 ( V_2 -> V_5 + V_3 ) ;
F_3 ( V_2 -> V_6 . V_7 -> V_8 , L_1 ,
V_9 , V_2 -> V_5 , V_3 , V_4 ) ;
return V_4 ;
}
static inline void F_4 ( struct V_1 * V_2 ,
unsigned int V_3 , T_1 V_4 )
{
F_5 ( V_4 , V_2 -> V_5 + V_3 ) ;
F_3 ( V_2 -> V_6 . V_7 -> V_8 , L_1 ,
V_9 , V_2 -> V_5 , V_3 , V_4 ) ;
}
static inline T_1 F_6 ( struct V_10 * V_11 ,
unsigned int V_3 )
{
T_1 V_4 = F_2 ( V_11 -> V_5 + V_3 ) ;
F_3 ( V_11 -> V_12 . V_8 , L_1 ,
V_9 , V_11 -> V_5 , V_3 , V_4 ) ;
return V_4 ;
}
static inline void F_7 ( struct V_10 * V_11 ,
unsigned int V_3 , T_1 V_4 )
{
F_5 ( V_4 , V_11 -> V_5 + V_3 ) ;
F_3 ( V_11 -> V_12 . V_8 , L_1 ,
V_9 , V_11 -> V_5 , V_3 , V_4 ) ;
}
static void F_8 ( struct V_1 * V_2 )
{
F_4 ( V_2 , V_13 , V_14 ) ;
}
static bool F_9 ( struct V_1 * V_2 )
{
T_1 V_15 = F_6 ( V_2 -> V_11 , V_16 ) ;
return V_15 & F_10 ( V_2 - V_2 -> V_11 -> V_2 ) ;
}
static void F_11 ( struct V_1 * V_2 )
{
F_4 ( V_2 , V_13 , V_17 ) ;
}
static T_1 F_12 ( struct V_10 * V_11 )
{
return F_6 ( V_11 , V_18 ) ;
}
static struct V_1 * F_13 ( struct V_10 * V_11 , T_1 error )
{
return V_11 -> V_2 + F_14 ( error ) ;
}
static void F_15 ( struct V_1 * V_2 )
{
T_1 V_15 ;
int V_19 ;
F_8 ( V_2 ) ;
for ( V_19 = 1000 ; V_19 ; V_19 -- ) {
V_15 = F_1 ( V_2 , V_20 ) ;
if ( ! ( V_15 & V_21 ) )
break;
F_16 () ;
}
if ( ! V_19 )
F_17 ( V_2 -> V_6 . V_7 -> V_8 ,
L_2 , V_9 , V_15 ) ;
F_4 ( V_2 , V_13 , V_22 ) ;
}
static int F_18 ( struct V_23 * V_24 )
{
struct V_1 * V_2 = V_24 -> V_2 ;
struct V_25 * V_26 = F_19 ( & V_24 -> V_27 , struct V_25 , V_28 ) ;
F_4 ( V_2 , V_29 , ( T_1 ) V_26 -> V_30 ) ;
F_4 ( V_2 , V_13 , V_31 | V_32 ) ;
V_2 -> V_33 = false ;
if ( V_26 -> V_34 -> V_35 & V_36 )
F_4 ( V_2 , V_13 , V_37 ) ;
F_3 ( V_2 -> V_11 -> V_12 . V_8 , L_3 , V_9 ,
F_1 ( V_2 , V_29 ) , F_1 ( V_2 , V_38 ) ) ;
return 0 ;
}
static void F_20 ( struct V_1 * V_2 )
{
V_2 -> V_39 = ( V_2 -> V_40 & V_41 ? V_42 : 0 ) |
( V_2 -> V_40 & V_43 ? V_44 : 0 ) |
( V_2 -> V_40 & V_45 ?
V_46 | ( V_47 & 0x200 ) : 0 ) |
V_2 -> V_48 ;
}
static void F_21 ( struct V_1 * V_2 )
{
V_2 -> V_39 = V_47 & 0x400 ;
V_2 -> V_48 = 0 ;
V_2 -> V_40 = 0 ;
}
static void F_22 ( struct V_1 * V_2 )
{
F_4 ( V_2 , V_49 , V_50 | V_2 -> V_39 ) ;
}
static T_1 F_23 ( struct V_10 * V_11 , T_2 V_51 )
{
return F_24 ( int , F_14 ( V_51 ) , F_25 ( V_11 -> V_35 -> V_52 * 8 ) ) ;
}
static T_2 F_26 ( struct V_10 * V_11 ,
enum V_53 V_54 , T_1 V_55 )
{
T_2 V_51 ;
if ( ! V_55 )
V_55 = 1 ;
switch ( V_54 ) {
case V_56 :
V_51 = 8 * V_55 ;
break;
case V_57 :
V_51 = 4 * V_55 ;
break;
case V_58 :
V_51 = 2 * V_55 ;
break;
default:
F_27 ( L_4 , V_9 , V_54 ) ;
case V_59 :
V_51 = V_55 ;
}
return F_23 ( V_11 , V_51 ) ;
}
static int F_28 ( struct V_25 * V_26 ,
enum V_60 V_61 ,
T_3 V_62 , T_3 V_63 , T_2 V_51 , bool V_64 )
{
struct V_65 * V_34 = V_26 -> V_34 ;
struct V_23 * V_24 = V_26 -> V_24 ;
struct V_1 * V_2 = V_24 -> V_2 ;
struct V_7 * V_8 = V_2 -> V_6 . V_7 -> V_8 ;
T_2 V_66 , V_67 ;
bool V_68 ;
V_34 -> V_69 = V_70 | V_71 |
( V_64 ? V_72 : 0 ) ;
V_34 -> V_73 = V_62 ;
V_34 -> V_74 = V_63 ;
V_34 -> V_75 = V_51 ;
V_66 = F_23 ( V_2 -> V_11 , V_51 ) ;
switch ( V_61 ) {
case V_76 :
V_68 = V_2 -> V_77 >= 3 ;
V_67 = F_29 ( V_66 , V_68 ?
V_2 -> V_78 : V_2 -> V_77 ) ;
if ( V_66 > V_2 -> V_78 && ! V_68 )
V_66 = V_2 -> V_78 ;
V_34 -> V_35 = V_79 | ( V_80 & ( V_66 << 16 ) ) |
( V_81 & ( V_67 << 12 ) ) | V_82 |
V_83 ;
break;
case V_84 :
V_67 = F_29 ( V_66 , V_2 -> V_85 >= 3 ?
V_2 -> V_86 : V_2 -> V_85 ) ;
V_34 -> V_35 = V_87 | ( V_81 & ( V_66 << 12 ) ) |
( V_80 & ( V_67 << 16 ) ) | V_82 ;
break;
case V_88 :
V_34 -> V_35 = V_89 | V_36 |
( V_81 & ( V_66 << 12 ) ) |
( V_80 & ( V_66 << 16 ) ) ;
break;
default:
return - V_90 ;
}
V_34 -> V_35 |= V_2 -> V_39 | ( V_64 ? 0 : V_91 ) |
V_50 ;
F_3 ( V_8 , L_5 ,
V_9 , & V_26 -> V_30 , V_34 -> V_69 ,
V_34 -> V_35 , V_51 , & V_62 , & V_63 ) ;
F_30 ( V_8 , V_26 -> V_30 , sizeof( * V_34 ) ,
V_92 ) ;
return 0 ;
}
static T_2 F_31 ( struct V_1 * V_2 )
{
return F_1 ( V_2 , V_93 ) ;
}
static void F_32 ( struct V_10 * V_11 )
{
F_7 ( V_11 , V_94 , V_95 ) ;
}
static void F_33 ( struct V_6 * V_96 )
{
struct V_1 * V_2 = F_34 ( V_96 ) ;
unsigned long V_40 ;
F_3 ( V_96 -> V_7 -> V_8 , L_6 , V_9 ) ;
F_35 ( & V_2 -> V_97 , V_40 ) ;
if ( F_36 ( & V_2 -> V_98 ) )
goto V_99;
F_37 ( & V_2 -> V_98 , & V_2 -> V_100 ) ;
if ( ! V_2 -> V_101 ) {
struct V_23 * V_24 = F_19 ( & V_2 -> V_100 ,
struct V_23 , V_28 ) ;
if ( ! F_18 ( V_24 ) )
V_2 -> V_101 = V_24 ;
}
V_99:
F_38 ( & V_2 -> V_97 , V_40 ) ;
}
static enum V_102 F_39 ( struct V_6 * V_96 ,
T_4 V_103 , struct V_104 * V_105 )
{
struct V_1 * V_2 = F_34 ( V_96 ) ;
enum V_102 V_15 = F_40 ( V_96 , V_103 , V_105 ) ;
if ( V_105 ) {
T_4 V_101 ;
unsigned long V_40 ;
F_35 ( & V_2 -> V_97 , V_40 ) ;
V_101 = V_2 -> V_101 ? V_2 -> V_101 -> V_106 . V_103 : - V_90 ;
if ( V_103 == V_101 ) {
V_105 -> V_107 = F_31 ( V_2 ) ;
F_3 ( V_96 -> V_7 -> V_8 , L_7 , V_9 ,
V_105 -> V_107 ) ;
} else if ( V_15 == V_108 ) {
struct V_23 * V_24 ;
bool V_109 = false ;
F_41 (desc, &chan->active, node)
if ( V_24 -> V_106 . V_103 == V_103 ) {
V_109 = true ;
break;
}
if ( ! V_109 )
F_41 (desc, &chan->queued, node)
if ( V_24 -> V_106 . V_103 == V_103 ) {
V_109 = true ;
break;
}
V_105 -> V_107 = V_109 ? V_24 -> V_110 : 0 ;
}
F_38 ( & V_2 -> V_97 , V_40 ) ;
}
if ( V_2 -> V_33 )
V_15 = V_111 ;
return V_15 ;
}
static T_4 F_42 ( struct V_112 * V_113 )
{
struct V_23 * V_24 = F_43 ( V_113 , struct V_23 , V_106 ) ;
struct V_1 * V_2 = V_24 -> V_2 ;
unsigned long V_40 ;
T_4 V_103 ;
F_35 ( & V_2 -> V_97 , V_40 ) ;
V_103 = F_44 ( V_113 ) ;
F_45 ( & V_24 -> V_28 , & V_2 -> V_98 ) ;
F_38 ( & V_2 -> V_97 , V_40 ) ;
F_3 ( V_2 -> V_6 . V_7 -> V_8 , L_8 , V_9 , V_103 ) ;
return V_103 ;
}
static int F_46 ( struct V_1 * V_2 )
{
struct V_6 * V_96 = & V_2 -> V_6 ;
struct V_114 * V_115 = ( void * ) F_47 ( V_116 | V_117 ) ;
struct V_25 * V_26 ;
struct V_65 * V_34 ;
struct V_23 * V_24 ;
F_48 ( V_118 ) ;
F_48 ( V_119 ) ;
int V_19 ;
struct V_7 * V_8 = V_96 -> V_7 -> V_8 ;
if ( ! V_115 )
return - V_120 ;
F_3 ( V_8 , L_9 ,
V_9 , V_121 , V_122 , sizeof( * V_115 ) ) ;
for ( V_19 = 0 , V_26 = V_115 -> V_26 , V_34 = V_115 -> V_34 ;
V_19 < F_49 ( V_115 -> V_26 ) ;
V_19 ++ , V_26 ++ , V_34 ++ ) {
V_26 -> V_34 = V_34 ;
F_45 ( & V_26 -> V_28 , & V_119 ) ;
V_26 -> V_30 = F_50 ( V_96 -> V_7 -> V_8 ,
V_34 , sizeof( * V_34 ) , V_92 ) ;
F_3 ( V_8 , L_10 , V_9 ,
V_34 , & V_26 -> V_30 ) ;
}
for ( V_19 = 0 , V_24 = V_115 -> V_24 ;
V_19 < F_49 ( V_115 -> V_24 ) ;
V_19 ++ , V_24 ++ ) {
F_51 ( & V_24 -> V_106 , V_96 ) ;
V_24 -> V_106 . V_123 = F_42 ;
V_24 -> V_2 = V_2 ;
F_52 ( & V_24 -> V_27 ) ;
F_45 ( & V_24 -> V_28 , & V_118 ) ;
}
F_53 ( & V_2 -> V_97 ) ;
F_54 ( & V_119 , & V_2 -> V_124 ) ;
F_54 ( & V_118 , & V_2 -> free ) ;
F_55 ( & V_115 -> V_28 , & V_2 -> V_125 ) ;
F_56 ( & V_2 -> V_97 ) ;
return F_49 ( V_115 -> V_24 ) ;
}
static void F_57 ( struct V_23 * V_24 )
{
struct V_1 * V_2 = V_24 -> V_2 ;
struct V_25 * V_26 , * V_126 ;
unsigned long V_40 ;
F_35 ( & V_2 -> V_97 , V_40 ) ;
F_58 (ldesc, tmp, &desc->sg, node)
F_59 ( & V_26 -> V_28 , & V_2 -> V_124 ) ;
F_55 ( & V_24 -> V_28 , & V_2 -> free ) ;
F_38 ( & V_2 -> V_97 , V_40 ) ;
}
static void F_60 ( struct V_1 * V_2 )
{
struct V_23 * V_24 , * V_126 ;
unsigned long V_40 ;
F_48 ( V_118 ) ;
F_35 ( & V_2 -> V_97 , V_40 ) ;
F_58 (desc, tmp, &chan->done, node)
if ( F_61 ( & V_24 -> V_106 ) && V_24 -> V_127 ) {
F_59 ( & V_24 -> V_28 , & V_118 ) ;
V_24 -> V_127 = false ;
}
F_38 ( & V_2 -> V_97 , V_40 ) ;
F_58 (desc, tmp, &head, node) {
F_62 ( & V_24 -> V_28 ) ;
F_57 ( V_24 ) ;
}
}
static struct V_23 * F_63 ( struct V_1 * V_2 , T_2 V_128 )
{
struct V_23 * V_24 = NULL ;
struct V_25 * V_26 , * V_129 = NULL ;
F_60 ( V_2 ) ;
F_53 ( & V_2 -> V_97 ) ;
do {
int V_19 = 0 , V_130 ;
if ( F_36 ( & V_2 -> free ) ) {
F_56 ( & V_2 -> V_97 ) ;
V_130 = F_46 ( V_2 ) ;
if ( V_130 < 0 )
return NULL ;
F_53 ( & V_2 -> V_97 ) ;
continue;
}
V_24 = F_19 ( & V_2 -> free , struct V_23 , V_28 ) ;
F_62 ( & V_24 -> V_28 ) ;
do {
if ( F_36 ( & V_2 -> V_124 ) ) {
F_56 ( & V_2 -> V_97 ) ;
V_130 = F_46 ( V_2 ) ;
if ( V_130 < 0 ) {
F_57 ( V_24 ) ;
return NULL ;
}
F_53 ( & V_2 -> V_97 ) ;
continue;
}
V_26 = F_19 ( & V_2 -> V_124 ,
struct V_25 , V_28 ) ;
V_26 -> V_24 = V_24 ;
if ( V_129 )
V_129 -> V_34 -> V_131 = ( T_1 ) V_26 -> V_30 ;
V_129 = V_26 ;
F_64 ( & V_26 -> V_28 , & V_24 -> V_27 ) ;
V_19 ++ ;
} while ( V_19 < V_128 );
} while ( ! V_24 );
V_129 -> V_34 -> V_131 = 0 ;
F_56 ( & V_2 -> V_97 ) ;
return V_24 ;
}
static void F_65 ( struct V_1 * V_2 )
{
struct V_23 * V_24 , * V_126 ;
unsigned long V_40 ;
F_48 ( V_118 ) ;
F_35 ( & V_2 -> V_97 , V_40 ) ;
F_66 ( & V_2 -> V_132 , & V_118 ) ;
F_66 ( & V_2 -> V_100 , & V_118 ) ;
F_66 ( & V_2 -> V_98 , & V_118 ) ;
V_2 -> V_101 = NULL ;
F_38 ( & V_2 -> V_97 , V_40 ) ;
F_58 (desc, tmp, &head, node) {
F_3 ( V_2 -> V_11 -> V_12 . V_8 , L_11 ,
V_9 , V_24 , V_24 -> V_106 . V_103 ) ;
F_62 ( & V_24 -> V_28 ) ;
F_57 ( V_24 ) ;
}
}
static int F_67 ( struct V_6 * V_96 )
{
struct V_1 * V_2 = F_34 ( V_96 ) ;
F_3 ( V_96 -> V_7 -> V_8 , L_12 , V_9 ) ;
V_2 -> V_33 = true ;
F_4 ( V_2 , V_13 , V_133 ) ;
F_4 ( V_2 , V_13 , V_14 ) ;
return 0 ;
}
static int F_68 ( struct V_6 * V_96 )
{
struct V_1 * V_2 = F_34 ( V_96 ) ;
F_3 ( V_96 -> V_7 -> V_8 , L_12 , V_9 ) ;
F_3 ( V_96 -> V_7 -> V_8 , L_13 ) ;
F_8 ( V_2 ) ;
F_65 ( V_2 ) ;
return 0 ;
}
static int F_69 ( struct V_6 * V_96 ,
struct V_134 * V_35 )
{
struct V_1 * V_2 = F_34 ( V_96 ) ;
F_3 ( V_96 -> V_7 -> V_8 , L_12 , V_9 ) ;
V_2 -> V_135 = V_35 -> V_74 ;
V_2 -> V_85 = F_26 ( V_2 -> V_11 ,
V_35 -> V_136 , 1 ) ;
V_2 -> V_86 = F_26 ( V_2 -> V_11 ,
V_35 -> V_136 ,
V_35 -> V_137 ) ;
V_2 -> V_138 = V_35 -> V_73 ;
V_2 -> V_77 = F_26 ( V_2 -> V_11 ,
V_35 -> V_139 , 1 ) ;
V_2 -> V_78 = F_26 ( V_2 -> V_11 ,
V_35 -> V_139 ,
V_35 -> V_140 ) ;
return 0 ;
}
static struct V_112 * F_70 ( struct V_1 * V_2 ,
struct V_141 * V_142 , struct V_141 * V_143 ,
T_2 V_128 , enum V_60 V_61 ,
unsigned long V_40 )
{
struct V_25 * V_26 ;
struct V_141 * V_144 ;
struct V_23 * V_24 ;
bool V_145 , V_146 ;
T_2 V_147 = 0 ;
int V_19 = 0 ;
switch ( V_61 ) {
case V_76 :
V_144 = V_143 ;
V_145 = false ;
V_146 = true ;
break;
case V_84 :
V_144 = V_142 ;
V_145 = true ;
V_146 = false ;
break;
default:
case V_88 :
V_144 = V_142 ;
V_145 = true ;
V_146 = true ;
}
V_24 = F_63 ( V_2 , V_128 ) ;
if ( ! V_24 )
return NULL ;
V_24 -> V_106 . V_40 = V_40 ;
V_24 -> V_106 . V_103 = - V_148 ;
V_24 -> V_127 = false ;
F_41 (ldesc, &desc->sg, node) {
int V_130 = F_28 ( V_26 , V_61 ,
F_71 ( V_142 ) ,
F_71 ( V_143 ) ,
F_72 ( V_144 ) ,
V_19 == V_128 - 1 ) ;
if ( V_130 < 0 ) {
F_57 ( V_24 ) ;
return NULL ;
}
V_147 += F_72 ( V_144 ) ;
if ( V_145 )
V_142 = F_73 ( V_142 ) ;
if ( V_146 )
V_143 = F_73 ( V_143 ) ;
V_144 = V_61 == V_76 ? V_143 : V_142 ;
V_19 ++ ;
}
V_24 -> V_110 = V_147 ;
return & V_24 -> V_106 ;
}
static struct V_112 * F_74 (
struct V_6 * V_96 , T_3 V_63 , T_3 V_62 ,
T_2 V_128 , unsigned long V_40 )
{
struct V_1 * V_2 = F_34 ( V_96 ) ;
struct V_141 V_143 ;
struct V_141 V_142 ;
F_75 ( & V_143 , 1 ) ;
F_75 ( & V_142 , 1 ) ;
F_71 ( & V_143 ) = V_63 ;
F_71 ( & V_142 ) = V_62 ;
F_72 ( & V_143 ) = V_128 ;
F_72 ( & V_142 ) = V_128 ;
F_3 ( V_96 -> V_7 -> V_8 , L_14 ,
V_9 , V_128 , & V_62 , & V_63 ) ;
return F_70 ( V_2 , & V_142 , & V_143 , 1 ,
V_88 , V_40 ) ;
}
static struct V_112 * F_76 (
struct V_6 * V_96 ,
struct V_141 * V_143 , unsigned int V_149 ,
struct V_141 * V_142 , unsigned int V_150 ,
unsigned long V_40 )
{
struct V_1 * V_2 = F_34 ( V_96 ) ;
if ( V_149 != V_150 )
return NULL ;
return F_70 ( V_2 , V_142 , V_143 , V_150 ,
V_88 , V_40 ) ;
}
static struct V_112 * F_77 (
struct V_6 * V_96 , struct V_141 * V_151 , unsigned int V_152 ,
enum V_60 V_61 , unsigned long V_40 , void * V_153 )
{
struct V_1 * V_2 = F_34 ( V_96 ) ;
struct V_141 V_154 ;
F_3 ( V_96 -> V_7 -> V_8 , L_6 , V_9 ) ;
F_75 ( & V_154 , 1 ) ;
switch ( V_61 ) {
case V_84 :
F_71 ( & V_154 ) = V_2 -> V_135 ;
return F_70 ( V_2 , V_151 , & V_154 , V_152 ,
V_61 , V_40 ) ;
case V_76 :
F_71 ( & V_154 ) = V_2 -> V_138 ;
return F_70 ( V_2 , & V_154 , V_151 , V_152 ,
V_61 , V_40 ) ;
default:
return NULL ;
}
}
static int F_78 ( struct V_6 * V_96 )
{
struct V_1 * V_2 = F_34 ( V_96 ) ;
int V_130 ;
F_52 ( & V_2 -> free ) ;
F_52 ( & V_2 -> V_124 ) ;
F_52 ( & V_2 -> V_98 ) ;
F_52 ( & V_2 -> V_100 ) ;
F_52 ( & V_2 -> V_132 ) ;
V_130 = F_46 ( V_2 ) ;
if ( V_130 < 0 )
return V_130 ;
F_3 ( V_96 -> V_7 -> V_8 , L_15 , V_9 ,
V_2 -> V_48 ) ;
F_22 ( V_2 ) ;
return V_130 ;
}
static void F_79 ( struct V_6 * V_96 )
{
struct V_1 * V_2 = F_34 ( V_96 ) ;
struct V_114 * V_115 , * V_126 ;
F_3 ( V_96 -> V_7 -> V_8 , L_6 , V_9 ) ;
F_8 ( V_2 ) ;
F_65 ( V_2 ) ;
F_21 ( V_2 ) ;
F_58 (dpage, tmp, &chan->desc_page, node) {
struct V_25 * V_26 ;
int V_19 ;
F_62 ( & V_115 -> V_28 ) ;
for ( V_19 = 0 , V_26 = V_115 -> V_26 ;
V_19 < F_49 ( V_115 -> V_26 ) ;
V_19 ++ , V_26 ++ )
F_80 ( V_96 -> V_7 -> V_8 , V_26 -> V_30 ,
sizeof( * V_26 -> V_34 ) , V_92 ) ;
F_81 ( ( unsigned long ) V_115 ) ;
}
}
static struct V_6 * F_82 ( struct V_155 * V_156 ,
struct V_157 * V_158 )
{
struct V_10 * V_11 = V_158 -> V_159 ;
struct V_6 * V_96 ;
struct V_1 * V_2 ;
if ( V_156 -> V_160 != 2 )
return NULL ;
V_96 = F_83 ( & V_11 -> V_12 ) ;
if ( ! V_96 )
return NULL ;
F_3 ( V_96 -> V_7 -> V_8 , L_16 , V_9 ,
V_156 -> V_161 -> V_162 ) ;
V_2 = F_34 ( V_96 ) ;
V_2 -> V_48 = V_156 -> args [ 0 ] ;
V_2 -> V_40 = V_156 -> args [ 1 ] ;
F_20 ( V_2 ) ;
F_22 ( V_2 ) ;
return V_96 ;
}
static void F_84 ( unsigned long V_4 )
{
struct V_1 * V_2 = (struct V_1 * ) V_4 ;
struct V_23 * V_24 , * V_126 ;
T_5 V_163 ;
void * V_164 ;
while ( ! F_36 ( & V_2 -> V_132 ) ) {
bool V_109 = false , V_165 , V_166 = false ;
F_53 ( & V_2 -> V_97 ) ;
F_58 (desc, tmp, &chan->done, node) {
if ( ! V_24 -> V_127 ) {
V_109 = true ;
break;
} else if ( F_61 ( & V_24 -> V_106 ) ) {
F_62 ( & V_24 -> V_28 ) ;
F_56 ( & V_2 -> V_97 ) ;
F_57 ( V_24 ) ;
V_166 = true ;
break;
}
}
if ( V_166 )
continue;
if ( ! V_109 ) {
F_56 ( & V_2 -> V_97 ) ;
break;
}
F_85 ( & V_24 -> V_106 ) ;
if ( F_61 ( & V_24 -> V_106 ) ) {
F_62 ( & V_24 -> V_28 ) ;
V_165 = true ;
} else {
V_24 -> V_127 = true ;
V_165 = false ;
}
V_163 = V_24 -> V_106 . V_163 ;
V_164 = V_24 -> V_106 . V_167 ;
F_56 ( & V_2 -> V_97 ) ;
if ( V_163 )
V_163 ( V_164 ) ;
if ( V_165 )
F_57 ( V_24 ) ;
}
}
static T_6 F_86 ( int V_168 , void * V_8 )
{
struct V_1 * V_2 = V_8 ;
bool V_132 = F_9 ( V_2 ) ;
struct V_23 * V_24 ;
T_6 V_130 ;
bool V_169 = false ;
if ( ! V_132 )
return V_170 ;
F_11 ( V_2 ) ;
F_3 ( & V_2 -> V_6 . V_8 -> V_7 , L_17 , V_9 ) ;
F_87 ( & V_2 -> V_97 ) ;
V_24 = V_2 -> V_101 ;
if ( F_88 ( ! V_24 ) ) {
V_130 = V_170 ;
goto V_99;
} else {
V_130 = V_171 ;
V_169 = true ;
}
F_64 ( & V_24 -> V_28 , & V_2 -> V_132 ) ;
V_2 -> V_101 = NULL ;
if ( ! F_36 ( & V_2 -> V_100 ) ) {
V_24 = F_19 ( & V_2 -> V_100 ,
struct V_23 , V_28 ) ;
if ( ! F_18 ( V_24 ) )
V_2 -> V_101 = V_24 ;
}
V_99:
F_89 ( & V_2 -> V_97 ) ;
if ( V_169 )
F_90 ( & V_2 -> V_172 ) ;
return V_130 ;
}
static T_6 F_91 ( int V_168 , void * V_8 )
{
struct V_10 * V_11 = V_8 ;
T_1 error = F_12 ( V_11 ) ;
F_92 ( V_11 -> V_12 . V_8 , L_18 , V_168 ) ;
if ( ! error )
return V_170 ;
do {
struct V_1 * V_2 = F_13 ( V_11 , error ) ;
F_15 ( V_2 ) ;
F_65 ( V_2 ) ;
error = F_12 ( V_11 ) ;
} while ( error );
return V_171 ;
}
static int F_93 ( struct V_10 * V_11 , int V_173 )
{
struct V_174 * V_12 = & V_11 -> V_12 ;
struct V_1 * V_2 = V_11 -> V_2 + V_173 ;
int V_130 ;
V_2 -> V_11 = V_11 ;
V_2 -> V_5 = V_11 -> V_5 + V_175 + V_176 * V_173 ;
F_52 ( & V_2 -> V_125 ) ;
F_94 ( & V_2 -> V_97 ) ;
V_2 -> V_6 . V_7 = V_12 ;
F_95 ( & V_2 -> V_6 ) ;
F_21 ( V_2 ) ;
F_3 ( V_12 -> V_8 , L_19 , V_9 , V_173 , V_2 -> V_5 ) ;
snprintf ( V_2 -> V_162 , sizeof( V_2 -> V_162 ) , L_20 , V_173 ) ;
F_96 ( & V_2 -> V_172 , F_84 , ( unsigned long ) V_2 ) ;
V_130 = F_97 ( V_12 -> V_8 , V_2 -> V_168 ,
F_86 , V_177 ,
V_2 -> V_162 , V_2 ) ;
if ( V_130 < 0 )
return V_130 ;
F_45 ( & V_2 -> V_6 . V_178 ,
& V_12 -> V_179 ) ;
return 0 ;
}
static int F_98 ( struct V_180 * V_181 )
{
struct V_7 * V_8 = & V_181 -> V_8 ;
const struct V_182 * V_183 = F_99 ( V_184 , V_8 ) ;
struct V_178 * V_161 = V_8 -> V_185 ;
struct V_10 * V_11 ;
struct V_174 * V_12 ;
struct V_186 * V_187 , * V_188 ;
const struct F_69 * V_189 ;
int V_190 ;
int V_130 , V_168 , V_191 , V_19 ;
int V_192 [ 9 ] ;
unsigned int V_193 = 0 ;
F_100 ( sizeof( struct V_114 ) > V_194 ) ;
if ( ! V_161 || ! V_183 || ! V_183 -> V_4 )
return - V_195 ;
V_189 = V_183 -> V_4 ;
V_190 = V_189 -> V_190 ;
V_11 = F_101 ( V_8 , sizeof( * V_11 ) + V_190 *
sizeof( V_11 -> V_2 [ 0 ] ) , V_116 ) ;
if ( ! V_11 ) {
F_17 ( V_8 , L_21 ) ;
return - V_120 ;
}
V_12 = & V_11 -> V_12 ;
V_12 -> V_8 = V_8 ;
V_187 = F_102 ( V_181 , V_196 , 0 ) ;
V_11 -> V_5 = F_103 ( V_8 , V_187 ) ;
if ( F_104 ( V_11 -> V_5 ) )
return F_105 ( V_11 -> V_5 ) ;
V_11 -> V_197 = F_106 ( V_8 , NULL ) ;
if ( F_104 ( V_11 -> V_197 ) )
return F_105 ( V_11 -> V_197 ) ;
V_11 -> V_35 = V_189 ;
for ( V_19 = 0 ; V_193 < F_49 ( V_192 ) ; V_19 ++ ) {
V_188 = F_102 ( V_181 , V_198 , V_19 ) ;
if ( ! V_188 )
break;
for ( V_168 = V_188 -> V_199 ; V_168 <= V_188 -> V_200 ;
V_168 ++ , V_193 ++ )
V_192 [ V_193 ] = V_168 ;
}
if ( V_193 != 1 && V_193 != 2 && V_193 != V_190 + 1 )
return - V_201 ;
if ( V_193 == 1 ) {
V_191 = V_192 [ 0 ] ;
for ( V_19 = 0 ; V_19 <= V_190 ; V_19 ++ )
V_11 -> V_2 [ V_19 ] . V_168 = V_192 [ 0 ] ;
} else {
V_191 = F_107 ( V_181 , L_22 ) ;
if ( V_191 < 0 )
return V_191 ;
if ( V_193 == V_190 + 1 ) {
struct V_1 * V_2 ;
for ( V_19 = 0 , V_2 = V_11 -> V_2 ; V_19 <= V_190 ;
V_19 ++ , V_2 ++ ) {
if ( V_192 [ V_19 ] == V_191 )
V_19 ++ ;
V_2 -> V_168 = V_192 [ V_19 ] ;
}
if ( V_2 != V_11 -> V_2 + V_190 )
return - V_90 ;
} else {
if ( V_192 [ 0 ] == V_191 )
V_168 = V_192 [ 1 ] ;
else
V_168 = V_192 [ 0 ] ;
for ( V_19 = 0 ; V_19 <= V_190 ; V_19 ++ )
V_11 -> V_2 [ V_19 ] . V_168 = V_168 ;
}
}
V_130 = F_97 ( V_8 , V_191 , F_91 ,
V_177 , L_23 , V_11 ) ;
if ( V_130 < 0 )
return V_130 ;
F_52 ( & V_12 -> V_179 ) ;
for ( V_19 = 0 ; V_19 < V_190 ; V_19 ++ ) {
V_130 = F_93 ( V_11 , V_19 ) ;
if ( V_130 < 0 )
return V_130 ;
}
F_108 ( V_202 , V_12 -> V_203 ) ;
F_108 ( V_204 , V_12 -> V_203 ) ;
F_108 ( V_205 , V_12 -> V_203 ) ;
F_108 ( V_206 , V_12 -> V_203 ) ;
V_12 -> V_207
= F_78 ;
V_12 -> V_208 = F_79 ;
V_12 -> V_209 = F_76 ;
V_12 -> V_210 = F_74 ;
V_12 -> V_211 = F_39 ;
V_12 -> V_212 = F_33 ;
V_12 -> V_213 = F_77 ;
V_12 -> V_214 = F_69 ;
V_12 -> V_215 = F_67 ;
V_12 -> V_216 = F_68 ;
V_12 -> V_217 = V_218 ;
V_12 -> V_219 = V_218 ;
V_12 -> V_220 = F_10 ( V_76 ) | F_10 ( V_84 ) ;
F_109 ( V_181 , V_11 ) ;
V_130 = F_110 ( V_11 -> V_197 ) ;
if ( V_130 < 0 )
return V_130 ;
F_32 ( V_11 ) ;
V_130 = F_111 ( V_12 ) ;
if ( V_130 < 0 )
goto V_221;
V_130 = F_112 ( V_161 , F_82 , V_11 ) ;
if ( V_130 < 0 )
goto V_222;
return 0 ;
V_222:
F_113 ( V_12 ) ;
V_221:
F_114 ( V_11 -> V_197 ) ;
return V_130 ;
}
static int F_115 ( struct V_180 * V_181 )
{
struct V_10 * V_11 = F_116 ( V_181 ) ;
F_117 ( V_181 -> V_8 . V_185 ) ;
F_113 ( & V_11 -> V_12 ) ;
F_114 ( V_11 -> V_197 ) ;
return 0 ;
}
static int F_118 ( struct V_7 * V_8 )
{
struct V_10 * V_11 = F_116 ( F_119 ( V_8 ) ) ;
F_114 ( V_11 -> V_197 ) ;
return 0 ;
}
static int F_120 ( struct V_7 * V_8 )
{
struct V_10 * V_11 = F_116 ( F_119 ( V_8 ) ) ;
return F_110 ( V_11 -> V_197 ) ;
}
