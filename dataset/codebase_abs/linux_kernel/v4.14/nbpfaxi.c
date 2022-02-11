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
static T_1 F_23 ( struct V_10 * V_11 , T_2 V_51 ,
enum V_52 V_53 )
{
int V_54 = V_11 -> V_35 -> V_55 * 8 ;
if ( V_11 -> V_56 || V_11 -> V_57 ) {
switch ( V_53 ) {
case V_58 :
V_54 = F_24 ( V_11 -> V_56 ,
V_11 -> V_57 ) ;
break;
case V_59 :
if ( V_11 -> V_56 )
V_54 = V_11 -> V_56 ;
break;
case V_60 :
if ( V_11 -> V_57 )
V_54 = V_11 -> V_57 ;
break;
case V_61 :
default:
break;
}
}
return F_25 ( int , F_14 ( V_51 ) , F_26 ( V_54 ) ) ;
}
static T_2 F_27 ( struct V_10 * V_11 ,
enum V_62 V_63 , T_1 V_64 )
{
T_2 V_51 ;
if ( ! V_64 )
V_64 = 1 ;
switch ( V_63 ) {
case V_65 :
V_51 = 8 * V_64 ;
break;
case V_66 :
V_51 = 4 * V_64 ;
break;
case V_67 :
V_51 = 2 * V_64 ;
break;
default:
F_28 ( L_4 , V_9 , V_63 ) ;
case V_68 :
V_51 = V_64 ;
}
return F_23 ( V_11 , V_51 , V_69 ) ;
}
static int F_29 ( struct V_25 * V_26 ,
enum V_52 V_53 ,
T_3 V_70 , T_3 V_71 , T_2 V_51 , bool V_72 )
{
struct V_73 * V_34 = V_26 -> V_34 ;
struct V_23 * V_24 = V_26 -> V_24 ;
struct V_1 * V_2 = V_24 -> V_2 ;
struct V_7 * V_8 = V_2 -> V_6 . V_7 -> V_8 ;
T_2 V_74 , V_75 ;
bool V_76 ;
V_34 -> V_77 = V_78 | V_79 |
( V_72 ? V_80 : 0 ) ;
V_34 -> V_81 = V_70 ;
V_34 -> V_82 = V_71 ;
V_34 -> V_83 = V_51 ;
V_74 = F_23 ( V_2 -> V_11 , V_51 , V_53 ) ;
switch ( V_53 ) {
case V_60 :
V_76 = V_2 -> V_84 >= 3 ;
V_75 = F_30 ( V_74 , V_76 ?
V_2 -> V_85 : V_2 -> V_84 ) ;
if ( V_74 > V_2 -> V_85 && ! V_76 )
V_74 = V_2 -> V_85 ;
V_34 -> V_35 = V_86 | ( V_87 & ( V_74 << 16 ) ) |
( V_88 & ( V_75 << 12 ) ) | V_89 |
V_90 ;
break;
case V_59 :
V_75 = F_30 ( V_74 , V_2 -> V_91 >= 3 ?
V_2 -> V_92 : V_2 -> V_91 ) ;
V_34 -> V_35 = V_93 | ( V_88 & ( V_74 << 12 ) ) |
( V_87 & ( V_75 << 16 ) ) | V_89 ;
break;
case V_58 :
V_34 -> V_35 = V_94 | V_36 |
( V_88 & ( V_74 << 12 ) ) |
( V_87 & ( V_74 << 16 ) ) ;
break;
default:
return - V_95 ;
}
V_34 -> V_35 |= V_2 -> V_39 | ( V_72 ? 0 : V_96 ) |
V_50 ;
F_3 ( V_8 , L_5 ,
V_9 , & V_26 -> V_30 , V_34 -> V_77 ,
V_34 -> V_35 , V_51 , & V_70 , & V_71 ) ;
F_31 ( V_8 , V_26 -> V_30 , sizeof( * V_34 ) ,
V_97 ) ;
return 0 ;
}
static T_2 F_32 ( struct V_1 * V_2 )
{
return F_1 ( V_2 , V_98 ) ;
}
static void F_33 ( struct V_10 * V_11 )
{
F_7 ( V_11 , V_99 , V_100 ) ;
}
static void F_34 ( struct V_6 * V_101 )
{
struct V_1 * V_2 = F_35 ( V_101 ) ;
unsigned long V_40 ;
F_3 ( V_101 -> V_7 -> V_8 , L_6 , V_9 ) ;
F_36 ( & V_2 -> V_102 , V_40 ) ;
if ( F_37 ( & V_2 -> V_103 ) )
goto V_104;
F_38 ( & V_2 -> V_103 , & V_2 -> V_105 ) ;
if ( ! V_2 -> V_106 ) {
struct V_23 * V_24 = F_19 ( & V_2 -> V_105 ,
struct V_23 , V_28 ) ;
if ( ! F_18 ( V_24 ) )
V_2 -> V_106 = V_24 ;
}
V_104:
F_39 ( & V_2 -> V_102 , V_40 ) ;
}
static enum V_107 F_40 ( struct V_6 * V_101 ,
T_4 V_108 , struct V_109 * V_110 )
{
struct V_1 * V_2 = F_35 ( V_101 ) ;
enum V_107 V_15 = F_41 ( V_101 , V_108 , V_110 ) ;
if ( V_110 ) {
T_4 V_106 ;
unsigned long V_40 ;
F_36 ( & V_2 -> V_102 , V_40 ) ;
V_106 = V_2 -> V_106 ? V_2 -> V_106 -> V_111 . V_108 : - V_95 ;
if ( V_108 == V_106 ) {
V_110 -> V_112 = F_32 ( V_2 ) ;
F_3 ( V_101 -> V_7 -> V_8 , L_7 , V_9 ,
V_110 -> V_112 ) ;
} else if ( V_15 == V_113 ) {
struct V_23 * V_24 ;
bool V_114 = false ;
F_42 (desc, &chan->active, node)
if ( V_24 -> V_111 . V_108 == V_108 ) {
V_114 = true ;
break;
}
if ( ! V_114 )
F_42 (desc, &chan->queued, node)
if ( V_24 -> V_111 . V_108 == V_108 ) {
V_114 = true ;
break;
}
V_110 -> V_112 = V_114 ? V_24 -> V_115 : 0 ;
}
F_39 ( & V_2 -> V_102 , V_40 ) ;
}
if ( V_2 -> V_33 )
V_15 = V_116 ;
return V_15 ;
}
static T_4 F_43 ( struct V_117 * V_118 )
{
struct V_23 * V_24 = F_44 ( V_118 , struct V_23 , V_111 ) ;
struct V_1 * V_2 = V_24 -> V_2 ;
unsigned long V_40 ;
T_4 V_108 ;
F_36 ( & V_2 -> V_102 , V_40 ) ;
V_108 = F_45 ( V_118 ) ;
F_46 ( & V_24 -> V_28 , & V_2 -> V_103 ) ;
F_39 ( & V_2 -> V_102 , V_40 ) ;
F_3 ( V_2 -> V_6 . V_7 -> V_8 , L_8 , V_9 , V_108 ) ;
return V_108 ;
}
static int F_47 ( struct V_1 * V_2 )
{
struct V_6 * V_101 = & V_2 -> V_6 ;
struct V_119 * V_120 = ( void * ) F_48 ( V_121 | V_122 ) ;
struct V_25 * V_26 ;
struct V_73 * V_34 ;
struct V_23 * V_24 ;
F_49 ( V_123 ) ;
F_49 ( V_124 ) ;
int V_19 ;
struct V_7 * V_8 = V_101 -> V_7 -> V_8 ;
if ( ! V_120 )
return - V_125 ;
F_3 ( V_8 , L_9 ,
V_9 , V_126 , V_127 , sizeof( * V_120 ) ) ;
for ( V_19 = 0 , V_26 = V_120 -> V_26 , V_34 = V_120 -> V_34 ;
V_19 < F_50 ( V_120 -> V_26 ) ;
V_19 ++ , V_26 ++ , V_34 ++ ) {
V_26 -> V_34 = V_34 ;
F_46 ( & V_26 -> V_28 , & V_124 ) ;
V_26 -> V_30 = F_51 ( V_101 -> V_7 -> V_8 ,
V_34 , sizeof( * V_34 ) , V_97 ) ;
F_3 ( V_8 , L_10 , V_9 ,
V_34 , & V_26 -> V_30 ) ;
}
for ( V_19 = 0 , V_24 = V_120 -> V_24 ;
V_19 < F_50 ( V_120 -> V_24 ) ;
V_19 ++ , V_24 ++ ) {
F_52 ( & V_24 -> V_111 , V_101 ) ;
V_24 -> V_111 . V_128 = F_43 ;
V_24 -> V_2 = V_2 ;
F_53 ( & V_24 -> V_27 ) ;
F_46 ( & V_24 -> V_28 , & V_123 ) ;
}
F_54 ( & V_2 -> V_102 ) ;
F_55 ( & V_124 , & V_2 -> V_129 ) ;
F_55 ( & V_123 , & V_2 -> free ) ;
F_56 ( & V_120 -> V_28 , & V_2 -> V_130 ) ;
F_57 ( & V_2 -> V_102 ) ;
return F_50 ( V_120 -> V_24 ) ;
}
static void F_58 ( struct V_23 * V_24 )
{
struct V_1 * V_2 = V_24 -> V_2 ;
struct V_25 * V_26 , * V_131 ;
unsigned long V_40 ;
F_36 ( & V_2 -> V_102 , V_40 ) ;
F_59 (ldesc, tmp, &desc->sg, node)
F_60 ( & V_26 -> V_28 , & V_2 -> V_129 ) ;
F_56 ( & V_24 -> V_28 , & V_2 -> free ) ;
F_39 ( & V_2 -> V_102 , V_40 ) ;
}
static void F_61 ( struct V_1 * V_2 )
{
struct V_23 * V_24 , * V_131 ;
unsigned long V_40 ;
F_49 ( V_123 ) ;
F_36 ( & V_2 -> V_102 , V_40 ) ;
F_59 (desc, tmp, &chan->done, node)
if ( F_62 ( & V_24 -> V_111 ) && V_24 -> V_132 ) {
F_60 ( & V_24 -> V_28 , & V_123 ) ;
V_24 -> V_132 = false ;
}
F_39 ( & V_2 -> V_102 , V_40 ) ;
F_59 (desc, tmp, &head, node) {
F_63 ( & V_24 -> V_28 ) ;
F_58 ( V_24 ) ;
}
}
static struct V_23 * F_64 ( struct V_1 * V_2 , T_2 V_133 )
{
struct V_23 * V_24 = NULL ;
struct V_25 * V_26 , * V_134 = NULL ;
F_61 ( V_2 ) ;
F_54 ( & V_2 -> V_102 ) ;
do {
int V_19 = 0 , V_135 ;
if ( F_37 ( & V_2 -> free ) ) {
F_57 ( & V_2 -> V_102 ) ;
V_135 = F_47 ( V_2 ) ;
if ( V_135 < 0 )
return NULL ;
F_54 ( & V_2 -> V_102 ) ;
continue;
}
V_24 = F_19 ( & V_2 -> free , struct V_23 , V_28 ) ;
F_63 ( & V_24 -> V_28 ) ;
do {
if ( F_37 ( & V_2 -> V_129 ) ) {
F_57 ( & V_2 -> V_102 ) ;
V_135 = F_47 ( V_2 ) ;
if ( V_135 < 0 ) {
F_58 ( V_24 ) ;
return NULL ;
}
F_54 ( & V_2 -> V_102 ) ;
continue;
}
V_26 = F_19 ( & V_2 -> V_129 ,
struct V_25 , V_28 ) ;
V_26 -> V_24 = V_24 ;
if ( V_134 )
V_134 -> V_34 -> V_136 = ( T_1 ) V_26 -> V_30 ;
V_134 = V_26 ;
F_65 ( & V_26 -> V_28 , & V_24 -> V_27 ) ;
V_19 ++ ;
} while ( V_19 < V_133 );
} while ( ! V_24 );
V_134 -> V_34 -> V_136 = 0 ;
F_57 ( & V_2 -> V_102 ) ;
return V_24 ;
}
static void F_66 ( struct V_1 * V_2 )
{
struct V_23 * V_24 , * V_131 ;
unsigned long V_40 ;
F_49 ( V_123 ) ;
F_36 ( & V_2 -> V_102 , V_40 ) ;
F_67 ( & V_2 -> V_137 , & V_123 ) ;
F_67 ( & V_2 -> V_105 , & V_123 ) ;
F_67 ( & V_2 -> V_103 , & V_123 ) ;
V_2 -> V_106 = NULL ;
F_39 ( & V_2 -> V_102 , V_40 ) ;
F_59 (desc, tmp, &head, node) {
F_3 ( V_2 -> V_11 -> V_12 . V_8 , L_11 ,
V_9 , V_24 , V_24 -> V_111 . V_108 ) ;
F_63 ( & V_24 -> V_28 ) ;
F_58 ( V_24 ) ;
}
}
static int F_68 ( struct V_6 * V_101 )
{
struct V_1 * V_2 = F_35 ( V_101 ) ;
F_3 ( V_101 -> V_7 -> V_8 , L_12 , V_9 ) ;
V_2 -> V_33 = true ;
F_4 ( V_2 , V_13 , V_138 ) ;
F_4 ( V_2 , V_13 , V_14 ) ;
return 0 ;
}
static int F_69 ( struct V_6 * V_101 )
{
struct V_1 * V_2 = F_35 ( V_101 ) ;
F_3 ( V_101 -> V_7 -> V_8 , L_12 , V_9 ) ;
F_3 ( V_101 -> V_7 -> V_8 , L_13 ) ;
F_8 ( V_2 ) ;
F_66 ( V_2 ) ;
return 0 ;
}
static int F_70 ( struct V_6 * V_101 ,
struct V_139 * V_35 )
{
struct V_1 * V_2 = F_35 ( V_101 ) ;
F_3 ( V_101 -> V_7 -> V_8 , L_12 , V_9 ) ;
V_2 -> V_140 = V_35 -> V_82 ;
V_2 -> V_91 = F_27 ( V_2 -> V_11 ,
V_35 -> V_141 , 1 ) ;
V_2 -> V_92 = F_27 ( V_2 -> V_11 ,
V_35 -> V_141 ,
V_35 -> V_142 ) ;
V_2 -> V_143 = V_35 -> V_81 ;
V_2 -> V_84 = F_27 ( V_2 -> V_11 ,
V_35 -> V_144 , 1 ) ;
V_2 -> V_85 = F_27 ( V_2 -> V_11 ,
V_35 -> V_144 ,
V_35 -> V_145 ) ;
return 0 ;
}
static struct V_117 * F_71 ( struct V_1 * V_2 ,
struct V_146 * V_147 , struct V_146 * V_148 ,
T_2 V_133 , enum V_52 V_53 ,
unsigned long V_40 )
{
struct V_25 * V_26 ;
struct V_146 * V_149 ;
struct V_23 * V_24 ;
bool V_150 , V_151 ;
T_2 V_152 = 0 ;
int V_19 = 0 ;
switch ( V_53 ) {
case V_60 :
V_149 = V_148 ;
V_150 = false ;
V_151 = true ;
break;
case V_59 :
V_149 = V_147 ;
V_150 = true ;
V_151 = false ;
break;
default:
case V_58 :
V_149 = V_147 ;
V_150 = true ;
V_151 = true ;
}
V_24 = F_64 ( V_2 , V_133 ) ;
if ( ! V_24 )
return NULL ;
V_24 -> V_111 . V_40 = V_40 ;
V_24 -> V_111 . V_108 = - V_153 ;
V_24 -> V_132 = false ;
F_42 (ldesc, &desc->sg, node) {
int V_135 = F_29 ( V_26 , V_53 ,
F_72 ( V_147 ) ,
F_72 ( V_148 ) ,
F_73 ( V_149 ) ,
V_19 == V_133 - 1 ) ;
if ( V_135 < 0 ) {
F_58 ( V_24 ) ;
return NULL ;
}
V_152 += F_73 ( V_149 ) ;
if ( V_150 )
V_147 = F_74 ( V_147 ) ;
if ( V_151 )
V_148 = F_74 ( V_148 ) ;
V_149 = V_53 == V_60 ? V_148 : V_147 ;
V_19 ++ ;
}
V_24 -> V_115 = V_152 ;
return & V_24 -> V_111 ;
}
static struct V_117 * F_75 (
struct V_6 * V_101 , T_3 V_71 , T_3 V_70 ,
T_2 V_133 , unsigned long V_40 )
{
struct V_1 * V_2 = F_35 ( V_101 ) ;
struct V_146 V_148 ;
struct V_146 V_147 ;
F_76 ( & V_148 , 1 ) ;
F_76 ( & V_147 , 1 ) ;
F_72 ( & V_148 ) = V_71 ;
F_72 ( & V_147 ) = V_70 ;
F_73 ( & V_148 ) = V_133 ;
F_73 ( & V_147 ) = V_133 ;
F_3 ( V_101 -> V_7 -> V_8 , L_14 ,
V_9 , V_133 , & V_70 , & V_71 ) ;
return F_71 ( V_2 , & V_147 , & V_148 , 1 ,
V_58 , V_40 ) ;
}
static struct V_117 * F_77 (
struct V_6 * V_101 , struct V_146 * V_154 , unsigned int V_155 ,
enum V_52 V_53 , unsigned long V_40 , void * V_156 )
{
struct V_1 * V_2 = F_35 ( V_101 ) ;
struct V_146 V_157 ;
F_3 ( V_101 -> V_7 -> V_8 , L_6 , V_9 ) ;
F_76 ( & V_157 , 1 ) ;
switch ( V_53 ) {
case V_59 :
F_72 ( & V_157 ) = V_2 -> V_140 ;
return F_71 ( V_2 , V_154 , & V_157 , V_155 ,
V_53 , V_40 ) ;
case V_60 :
F_72 ( & V_157 ) = V_2 -> V_143 ;
return F_71 ( V_2 , & V_157 , V_154 , V_155 ,
V_53 , V_40 ) ;
default:
return NULL ;
}
}
static int F_78 ( struct V_6 * V_101 )
{
struct V_1 * V_2 = F_35 ( V_101 ) ;
int V_135 ;
F_53 ( & V_2 -> free ) ;
F_53 ( & V_2 -> V_129 ) ;
F_53 ( & V_2 -> V_103 ) ;
F_53 ( & V_2 -> V_105 ) ;
F_53 ( & V_2 -> V_137 ) ;
V_135 = F_47 ( V_2 ) ;
if ( V_135 < 0 )
return V_135 ;
F_3 ( V_101 -> V_7 -> V_8 , L_15 , V_9 ,
V_2 -> V_48 ) ;
F_22 ( V_2 ) ;
return V_135 ;
}
static void F_79 ( struct V_6 * V_101 )
{
struct V_1 * V_2 = F_35 ( V_101 ) ;
struct V_119 * V_120 , * V_131 ;
F_3 ( V_101 -> V_7 -> V_8 , L_6 , V_9 ) ;
F_8 ( V_2 ) ;
F_66 ( V_2 ) ;
F_21 ( V_2 ) ;
F_59 (dpage, tmp, &chan->desc_page, node) {
struct V_25 * V_26 ;
int V_19 ;
F_63 ( & V_120 -> V_28 ) ;
for ( V_19 = 0 , V_26 = V_120 -> V_26 ;
V_19 < F_50 ( V_120 -> V_26 ) ;
V_19 ++ , V_26 ++ )
F_80 ( V_101 -> V_7 -> V_8 , V_26 -> V_30 ,
sizeof( * V_26 -> V_34 ) , V_97 ) ;
F_81 ( ( unsigned long ) V_120 ) ;
}
}
static struct V_6 * F_82 ( struct V_158 * V_159 ,
struct V_160 * V_161 )
{
struct V_10 * V_11 = V_161 -> V_162 ;
struct V_6 * V_101 ;
struct V_1 * V_2 ;
if ( V_159 -> V_163 != 2 )
return NULL ;
V_101 = F_83 ( & V_11 -> V_12 ) ;
if ( ! V_101 )
return NULL ;
F_3 ( V_101 -> V_7 -> V_8 , L_16 , V_9 ,
V_159 -> V_164 -> V_165 ) ;
V_2 = F_35 ( V_101 ) ;
V_2 -> V_48 = V_159 -> args [ 0 ] ;
V_2 -> V_40 = V_159 -> args [ 1 ] ;
F_20 ( V_2 ) ;
F_22 ( V_2 ) ;
return V_101 ;
}
static void F_84 ( unsigned long V_4 )
{
struct V_1 * V_2 = (struct V_1 * ) V_4 ;
struct V_23 * V_24 , * V_131 ;
struct V_166 V_167 ;
while ( ! F_37 ( & V_2 -> V_137 ) ) {
bool V_114 = false , V_168 , V_169 = false ;
F_54 ( & V_2 -> V_102 ) ;
F_59 (desc, tmp, &chan->done, node) {
if ( ! V_24 -> V_132 ) {
V_114 = true ;
break;
} else if ( F_62 ( & V_24 -> V_111 ) ) {
F_63 ( & V_24 -> V_28 ) ;
F_57 ( & V_2 -> V_102 ) ;
F_58 ( V_24 ) ;
V_169 = true ;
break;
}
}
if ( V_169 )
continue;
if ( ! V_114 ) {
F_57 ( & V_2 -> V_102 ) ;
break;
}
F_85 ( & V_24 -> V_111 ) ;
if ( F_62 ( & V_24 -> V_111 ) ) {
F_63 ( & V_24 -> V_28 ) ;
V_168 = true ;
} else {
V_24 -> V_132 = true ;
V_168 = false ;
}
F_86 ( & V_24 -> V_111 , & V_167 ) ;
F_57 ( & V_2 -> V_102 ) ;
F_87 ( & V_167 , NULL ) ;
if ( V_168 )
F_58 ( V_24 ) ;
}
}
static T_5 F_88 ( int V_170 , void * V_8 )
{
struct V_1 * V_2 = V_8 ;
bool V_137 = F_9 ( V_2 ) ;
struct V_23 * V_24 ;
T_5 V_135 ;
bool V_171 = false ;
if ( ! V_137 )
return V_172 ;
F_11 ( V_2 ) ;
F_3 ( & V_2 -> V_6 . V_8 -> V_7 , L_17 , V_9 ) ;
F_89 ( & V_2 -> V_102 ) ;
V_24 = V_2 -> V_106 ;
if ( F_90 ( ! V_24 ) ) {
V_135 = V_172 ;
goto V_104;
} else {
V_135 = V_173 ;
V_171 = true ;
}
F_65 ( & V_24 -> V_28 , & V_2 -> V_137 ) ;
V_2 -> V_106 = NULL ;
if ( ! F_37 ( & V_2 -> V_105 ) ) {
V_24 = F_19 ( & V_2 -> V_105 ,
struct V_23 , V_28 ) ;
if ( ! F_18 ( V_24 ) )
V_2 -> V_106 = V_24 ;
}
V_104:
F_91 ( & V_2 -> V_102 ) ;
if ( V_171 )
F_92 ( & V_2 -> V_174 ) ;
return V_135 ;
}
static T_5 F_93 ( int V_170 , void * V_8 )
{
struct V_10 * V_11 = V_8 ;
T_1 error = F_12 ( V_11 ) ;
F_94 ( V_11 -> V_12 . V_8 , L_18 , V_170 ) ;
if ( ! error )
return V_172 ;
do {
struct V_1 * V_2 = F_13 ( V_11 , error ) ;
F_15 ( V_2 ) ;
F_66 ( V_2 ) ;
error = F_12 ( V_11 ) ;
} while ( error );
return V_173 ;
}
static int F_95 ( struct V_10 * V_11 , int V_175 )
{
struct V_176 * V_12 = & V_11 -> V_12 ;
struct V_1 * V_2 = V_11 -> V_2 + V_175 ;
int V_135 ;
V_2 -> V_11 = V_11 ;
V_2 -> V_5 = V_11 -> V_5 + V_177 + V_178 * V_175 ;
F_53 ( & V_2 -> V_130 ) ;
F_96 ( & V_2 -> V_102 ) ;
V_2 -> V_6 . V_7 = V_12 ;
F_97 ( & V_2 -> V_6 ) ;
F_21 ( V_2 ) ;
F_3 ( V_12 -> V_8 , L_19 , V_9 , V_175 , V_2 -> V_5 ) ;
snprintf ( V_2 -> V_165 , sizeof( V_2 -> V_165 ) , L_20 , V_175 ) ;
F_98 ( & V_2 -> V_174 , F_84 , ( unsigned long ) V_2 ) ;
V_135 = F_99 ( V_12 -> V_8 , V_2 -> V_170 ,
F_88 , V_179 ,
V_2 -> V_165 , V_2 ) ;
if ( V_135 < 0 )
return V_135 ;
F_46 ( & V_2 -> V_6 . V_180 ,
& V_12 -> V_181 ) ;
return 0 ;
}
static int F_100 ( struct V_182 * V_183 )
{
struct V_7 * V_8 = & V_183 -> V_8 ;
const struct V_184 * V_185 = F_101 ( V_186 , V_8 ) ;
struct V_180 * V_164 = V_8 -> V_187 ;
struct V_10 * V_11 ;
struct V_176 * V_12 ;
struct V_188 * V_189 , * V_190 ;
const struct F_70 * V_191 ;
int V_192 ;
int V_135 , V_170 , V_193 , V_19 ;
int V_194 [ 9 ] ;
unsigned int V_195 = 0 ;
F_102 ( sizeof( struct V_119 ) > V_196 ) ;
if ( ! V_164 || ! V_185 || ! V_185 -> V_4 )
return - V_197 ;
V_191 = V_185 -> V_4 ;
V_192 = V_191 -> V_192 ;
V_11 = F_103 ( V_8 , sizeof( * V_11 ) + V_192 *
sizeof( V_11 -> V_2 [ 0 ] ) , V_121 ) ;
if ( ! V_11 )
return - V_125 ;
V_12 = & V_11 -> V_12 ;
V_12 -> V_8 = V_8 ;
V_189 = F_104 ( V_183 , V_198 , 0 ) ;
V_11 -> V_5 = F_105 ( V_8 , V_189 ) ;
if ( F_106 ( V_11 -> V_5 ) )
return F_107 ( V_11 -> V_5 ) ;
V_11 -> V_199 = F_108 ( V_8 , NULL ) ;
if ( F_106 ( V_11 -> V_199 ) )
return F_107 ( V_11 -> V_199 ) ;
F_109 ( V_164 , L_21 ,
& V_11 -> V_56 ) ;
F_109 ( V_164 , L_22 ,
& V_11 -> V_57 ) ;
V_11 -> V_35 = V_191 ;
for ( V_19 = 0 ; V_195 < F_50 ( V_194 ) ; V_19 ++ ) {
V_190 = F_104 ( V_183 , V_200 , V_19 ) ;
if ( ! V_190 )
break;
for ( V_170 = V_190 -> V_201 ; V_170 <= V_190 -> V_202 ;
V_170 ++ , V_195 ++ )
V_194 [ V_195 ] = V_170 ;
}
if ( V_195 != 1 && V_195 != 2 && V_195 != V_192 + 1 )
return - V_203 ;
if ( V_195 == 1 ) {
V_193 = V_194 [ 0 ] ;
for ( V_19 = 0 ; V_19 <= V_192 ; V_19 ++ )
V_11 -> V_2 [ V_19 ] . V_170 = V_194 [ 0 ] ;
} else {
V_193 = F_110 ( V_183 , L_23 ) ;
if ( V_193 < 0 )
return V_193 ;
if ( V_195 == V_192 + 1 ) {
struct V_1 * V_2 ;
for ( V_19 = 0 , V_2 = V_11 -> V_2 ; V_19 <= V_192 ;
V_19 ++ , V_2 ++ ) {
if ( V_194 [ V_19 ] == V_193 )
V_19 ++ ;
V_2 -> V_170 = V_194 [ V_19 ] ;
}
if ( V_2 != V_11 -> V_2 + V_192 )
return - V_95 ;
} else {
if ( V_194 [ 0 ] == V_193 )
V_170 = V_194 [ 1 ] ;
else
V_170 = V_194 [ 0 ] ;
for ( V_19 = 0 ; V_19 <= V_192 ; V_19 ++ )
V_11 -> V_2 [ V_19 ] . V_170 = V_170 ;
}
}
V_135 = F_99 ( V_8 , V_193 , F_93 ,
V_179 , L_24 , V_11 ) ;
if ( V_135 < 0 )
return V_135 ;
V_11 -> V_193 = V_193 ;
F_53 ( & V_12 -> V_181 ) ;
for ( V_19 = 0 ; V_19 < V_192 ; V_19 ++ ) {
V_135 = F_95 ( V_11 , V_19 ) ;
if ( V_135 < 0 )
return V_135 ;
}
F_111 ( V_204 , V_12 -> V_205 ) ;
F_111 ( V_206 , V_12 -> V_205 ) ;
F_111 ( V_207 , V_12 -> V_205 ) ;
V_12 -> V_208
= F_78 ;
V_12 -> V_209 = F_79 ;
V_12 -> V_210 = F_75 ;
V_12 -> V_211 = F_40 ;
V_12 -> V_212 = F_34 ;
V_12 -> V_213 = F_77 ;
V_12 -> V_214 = F_70 ;
V_12 -> V_215 = F_68 ;
V_12 -> V_216 = F_69 ;
V_12 -> V_217 = V_218 ;
V_12 -> V_219 = V_218 ;
V_12 -> V_220 = F_10 ( V_60 ) | F_10 ( V_59 ) ;
F_112 ( V_183 , V_11 ) ;
V_135 = F_113 ( V_11 -> V_199 ) ;
if ( V_135 < 0 )
return V_135 ;
F_33 ( V_11 ) ;
V_135 = F_114 ( V_12 ) ;
if ( V_135 < 0 )
goto V_221;
V_135 = F_115 ( V_164 , F_82 , V_11 ) ;
if ( V_135 < 0 )
goto V_222;
return 0 ;
V_222:
F_116 ( V_12 ) ;
V_221:
F_117 ( V_11 -> V_199 ) ;
return V_135 ;
}
static int F_118 ( struct V_182 * V_183 )
{
struct V_10 * V_11 = F_119 ( V_183 ) ;
int V_19 ;
F_120 ( & V_183 -> V_8 , V_11 -> V_193 , V_11 ) ;
for ( V_19 = 0 ; V_19 < V_11 -> V_35 -> V_192 ; V_19 ++ ) {
struct V_1 * V_2 = V_11 -> V_2 + V_19 ;
F_120 ( & V_183 -> V_8 , V_2 -> V_170 , V_2 ) ;
F_121 ( & V_2 -> V_174 ) ;
}
F_122 ( V_183 -> V_8 . V_187 ) ;
F_116 ( & V_11 -> V_12 ) ;
F_117 ( V_11 -> V_199 ) ;
return 0 ;
}
static int F_123 ( struct V_7 * V_8 )
{
struct V_10 * V_11 = F_119 ( F_124 ( V_8 ) ) ;
F_117 ( V_11 -> V_199 ) ;
return 0 ;
}
static int F_125 ( struct V_7 * V_8 )
{
struct V_10 * V_11 = F_119 ( F_124 ( V_8 ) ) ;
return F_113 ( V_11 -> V_199 ) ;
}
