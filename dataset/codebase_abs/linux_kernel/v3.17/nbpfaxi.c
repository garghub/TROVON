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
static void F_33 ( struct V_1 * V_2 )
{
F_4 ( V_2 , V_13 , V_96 ) ;
F_4 ( V_2 , V_13 , V_14 ) ;
}
static void F_34 ( struct V_6 * V_97 )
{
struct V_1 * V_2 = F_35 ( V_97 ) ;
unsigned long V_40 ;
F_3 ( V_97 -> V_7 -> V_8 , L_6 , V_9 ) ;
F_36 ( & V_2 -> V_98 , V_40 ) ;
if ( F_37 ( & V_2 -> V_99 ) )
goto V_100;
F_38 ( & V_2 -> V_99 , & V_2 -> V_101 ) ;
if ( ! V_2 -> V_102 ) {
struct V_23 * V_24 = F_19 ( & V_2 -> V_101 ,
struct V_23 , V_28 ) ;
if ( ! F_18 ( V_24 ) )
V_2 -> V_102 = V_24 ;
}
V_100:
F_39 ( & V_2 -> V_98 , V_40 ) ;
}
static enum V_103 F_40 ( struct V_6 * V_97 ,
T_4 V_104 , struct V_105 * V_106 )
{
struct V_1 * V_2 = F_35 ( V_97 ) ;
enum V_103 V_15 = F_41 ( V_97 , V_104 , V_106 ) ;
if ( V_106 ) {
T_4 V_102 ;
unsigned long V_40 ;
F_36 ( & V_2 -> V_98 , V_40 ) ;
V_102 = V_2 -> V_102 ? V_2 -> V_102 -> V_107 . V_104 : - V_90 ;
if ( V_104 == V_102 ) {
V_106 -> V_108 = F_31 ( V_2 ) ;
F_3 ( V_97 -> V_7 -> V_8 , L_7 , V_9 ,
V_106 -> V_108 ) ;
} else if ( V_15 == V_109 ) {
struct V_23 * V_24 ;
bool V_110 = false ;
F_42 (desc, &chan->active, node)
if ( V_24 -> V_107 . V_104 == V_104 ) {
V_110 = true ;
break;
}
if ( ! V_110 )
F_42 (desc, &chan->queued, node)
if ( V_24 -> V_107 . V_104 == V_104 ) {
V_110 = true ;
break;
}
V_106 -> V_108 = V_110 ? V_24 -> V_111 : 0 ;
}
F_39 ( & V_2 -> V_98 , V_40 ) ;
}
if ( V_2 -> V_33 )
V_15 = V_112 ;
return V_15 ;
}
static T_4 F_43 ( struct V_113 * V_114 )
{
struct V_23 * V_24 = F_44 ( V_114 , struct V_23 , V_107 ) ;
struct V_1 * V_2 = V_24 -> V_2 ;
unsigned long V_40 ;
T_4 V_104 ;
F_36 ( & V_2 -> V_98 , V_40 ) ;
V_104 = F_45 ( V_114 ) ;
F_46 ( & V_24 -> V_28 , & V_2 -> V_99 ) ;
F_39 ( & V_2 -> V_98 , V_40 ) ;
F_3 ( V_2 -> V_6 . V_7 -> V_8 , L_8 , V_9 , V_104 ) ;
return V_104 ;
}
static int F_47 ( struct V_1 * V_2 )
{
struct V_6 * V_97 = & V_2 -> V_6 ;
struct V_115 * V_116 = ( void * ) F_48 ( V_117 | V_118 ) ;
struct V_25 * V_26 ;
struct V_65 * V_34 ;
struct V_23 * V_24 ;
F_49 ( V_119 ) ;
F_49 ( V_120 ) ;
int V_19 ;
struct V_7 * V_8 = V_97 -> V_7 -> V_8 ;
if ( ! V_116 )
return - V_121 ;
F_3 ( V_8 , L_9 ,
V_9 , V_122 , V_123 , sizeof( * V_116 ) ) ;
for ( V_19 = 0 , V_26 = V_116 -> V_26 , V_34 = V_116 -> V_34 ;
V_19 < F_50 ( V_116 -> V_26 ) ;
V_19 ++ , V_26 ++ , V_34 ++ ) {
V_26 -> V_34 = V_34 ;
F_46 ( & V_26 -> V_28 , & V_120 ) ;
V_26 -> V_30 = F_51 ( V_97 -> V_7 -> V_8 ,
V_34 , sizeof( * V_34 ) , V_92 ) ;
F_3 ( V_8 , L_10 , V_9 ,
V_34 , & V_26 -> V_30 ) ;
}
for ( V_19 = 0 , V_24 = V_116 -> V_24 ;
V_19 < F_50 ( V_116 -> V_24 ) ;
V_19 ++ , V_24 ++ ) {
F_52 ( & V_24 -> V_107 , V_97 ) ;
V_24 -> V_107 . V_124 = F_43 ;
V_24 -> V_2 = V_2 ;
F_53 ( & V_24 -> V_27 ) ;
F_46 ( & V_24 -> V_28 , & V_119 ) ;
}
F_54 ( & V_2 -> V_98 ) ;
F_55 ( & V_120 , & V_2 -> V_125 ) ;
F_55 ( & V_119 , & V_2 -> free ) ;
F_56 ( & V_116 -> V_28 , & V_2 -> V_126 ) ;
F_57 ( & V_2 -> V_98 ) ;
return F_50 ( V_116 -> V_24 ) ;
}
static void F_58 ( struct V_23 * V_24 )
{
struct V_1 * V_2 = V_24 -> V_2 ;
struct V_25 * V_26 , * V_127 ;
unsigned long V_40 ;
F_36 ( & V_2 -> V_98 , V_40 ) ;
F_59 (ldesc, tmp, &desc->sg, node)
F_60 ( & V_26 -> V_28 , & V_2 -> V_125 ) ;
F_56 ( & V_24 -> V_28 , & V_2 -> free ) ;
F_39 ( & V_2 -> V_98 , V_40 ) ;
}
static void F_61 ( struct V_1 * V_2 )
{
struct V_23 * V_24 , * V_127 ;
unsigned long V_40 ;
F_49 ( V_119 ) ;
F_36 ( & V_2 -> V_98 , V_40 ) ;
F_59 (desc, tmp, &chan->done, node)
if ( F_62 ( & V_24 -> V_107 ) && V_24 -> V_128 ) {
F_60 ( & V_24 -> V_28 , & V_119 ) ;
V_24 -> V_128 = false ;
}
F_39 ( & V_2 -> V_98 , V_40 ) ;
F_59 (desc, tmp, &head, node) {
F_63 ( & V_24 -> V_28 ) ;
F_58 ( V_24 ) ;
}
}
static struct V_23 * F_64 ( struct V_1 * V_2 , T_2 V_129 )
{
struct V_23 * V_24 = NULL ;
struct V_25 * V_26 , * V_130 = NULL ;
F_61 ( V_2 ) ;
F_54 ( & V_2 -> V_98 ) ;
do {
int V_19 = 0 , V_131 ;
if ( F_37 ( & V_2 -> free ) ) {
F_57 ( & V_2 -> V_98 ) ;
V_131 = F_47 ( V_2 ) ;
if ( V_131 < 0 )
return NULL ;
F_54 ( & V_2 -> V_98 ) ;
continue;
}
V_24 = F_19 ( & V_2 -> free , struct V_23 , V_28 ) ;
F_63 ( & V_24 -> V_28 ) ;
do {
if ( F_37 ( & V_2 -> V_125 ) ) {
F_57 ( & V_2 -> V_98 ) ;
V_131 = F_47 ( V_2 ) ;
if ( V_131 < 0 ) {
F_58 ( V_24 ) ;
return NULL ;
}
F_54 ( & V_2 -> V_98 ) ;
continue;
}
V_26 = F_19 ( & V_2 -> V_125 ,
struct V_25 , V_28 ) ;
V_26 -> V_24 = V_24 ;
if ( V_130 )
V_130 -> V_34 -> V_132 = ( T_1 ) V_26 -> V_30 ;
V_130 = V_26 ;
F_65 ( & V_26 -> V_28 , & V_24 -> V_27 ) ;
V_19 ++ ;
} while ( V_19 < V_129 );
} while ( ! V_24 );
V_130 -> V_34 -> V_132 = 0 ;
F_57 ( & V_2 -> V_98 ) ;
return V_24 ;
}
static void F_66 ( struct V_1 * V_2 )
{
struct V_23 * V_24 , * V_127 ;
unsigned long V_40 ;
F_49 ( V_119 ) ;
F_36 ( & V_2 -> V_98 , V_40 ) ;
F_67 ( & V_2 -> V_133 , & V_119 ) ;
F_67 ( & V_2 -> V_101 , & V_119 ) ;
F_67 ( & V_2 -> V_99 , & V_119 ) ;
V_2 -> V_102 = NULL ;
F_39 ( & V_2 -> V_98 , V_40 ) ;
F_59 (desc, tmp, &head, node) {
F_3 ( V_2 -> V_11 -> V_12 . V_8 , L_11 ,
V_9 , V_24 , V_24 -> V_107 . V_104 ) ;
F_63 ( & V_24 -> V_28 ) ;
F_58 ( V_24 ) ;
}
}
static int F_68 ( struct V_6 * V_97 , enum V_134 V_135 ,
unsigned long V_136 )
{
struct V_1 * V_2 = F_35 ( V_97 ) ;
struct V_137 * V_35 ;
F_3 ( V_97 -> V_7 -> V_8 , L_8 , V_9 , V_135 ) ;
switch ( V_135 ) {
case V_138 :
F_3 ( V_97 -> V_7 -> V_8 , L_12 ) ;
F_8 ( V_2 ) ;
F_66 ( V_2 ) ;
break;
case V_139 :
if ( ! V_136 )
return - V_90 ;
V_35 = (struct V_137 * ) V_136 ;
V_2 -> V_140 = V_35 -> V_74 ;
V_2 -> V_85 = F_26 ( V_2 -> V_11 ,
V_35 -> V_141 , 1 ) ;
V_2 -> V_86 = F_26 ( V_2 -> V_11 ,
V_35 -> V_141 ,
V_35 -> V_142 ) ;
V_2 -> V_143 = V_35 -> V_73 ;
V_2 -> V_77 = F_26 ( V_2 -> V_11 ,
V_35 -> V_144 , 1 ) ;
V_2 -> V_78 = F_26 ( V_2 -> V_11 ,
V_35 -> V_144 ,
V_35 -> V_145 ) ;
break;
case V_146 :
V_2 -> V_33 = true ;
F_33 ( V_2 ) ;
break;
default:
return - V_147 ;
}
return 0 ;
}
static struct V_113 * F_69 ( struct V_1 * V_2 ,
struct V_148 * V_149 , struct V_148 * V_150 ,
T_2 V_129 , enum V_60 V_61 ,
unsigned long V_40 )
{
struct V_25 * V_26 ;
struct V_148 * V_151 ;
struct V_23 * V_24 ;
bool V_152 , V_153 ;
T_2 V_154 = 0 ;
int V_19 = 0 ;
switch ( V_61 ) {
case V_76 :
V_151 = V_150 ;
V_152 = false ;
V_153 = true ;
break;
case V_84 :
V_151 = V_149 ;
V_152 = true ;
V_153 = false ;
break;
default:
case V_88 :
V_151 = V_149 ;
V_152 = true ;
V_153 = true ;
}
V_24 = F_64 ( V_2 , V_129 ) ;
if ( ! V_24 )
return NULL ;
V_24 -> V_107 . V_40 = V_40 ;
V_24 -> V_107 . V_104 = - V_155 ;
V_24 -> V_128 = false ;
F_42 (ldesc, &desc->sg, node) {
int V_131 = F_28 ( V_26 , V_61 ,
F_70 ( V_149 ) ,
F_70 ( V_150 ) ,
F_71 ( V_151 ) ,
V_19 == V_129 - 1 ) ;
if ( V_131 < 0 ) {
F_58 ( V_24 ) ;
return NULL ;
}
V_154 += F_71 ( V_151 ) ;
if ( V_152 )
V_149 = F_72 ( V_149 ) ;
if ( V_153 )
V_150 = F_72 ( V_150 ) ;
V_151 = V_61 == V_76 ? V_150 : V_149 ;
V_19 ++ ;
}
V_24 -> V_111 = V_154 ;
return & V_24 -> V_107 ;
}
static struct V_113 * F_73 (
struct V_6 * V_97 , T_3 V_63 , T_3 V_62 ,
T_2 V_129 , unsigned long V_40 )
{
struct V_1 * V_2 = F_35 ( V_97 ) ;
struct V_148 V_150 ;
struct V_148 V_149 ;
F_74 ( & V_150 , 1 ) ;
F_74 ( & V_149 , 1 ) ;
F_70 ( & V_150 ) = V_63 ;
F_70 ( & V_149 ) = V_62 ;
F_71 ( & V_150 ) = V_129 ;
F_71 ( & V_149 ) = V_129 ;
F_3 ( V_97 -> V_7 -> V_8 , L_13 ,
V_9 , V_129 , & V_62 , & V_63 ) ;
return F_69 ( V_2 , & V_149 , & V_150 , 1 ,
V_88 , V_40 ) ;
}
static struct V_113 * F_75 (
struct V_6 * V_97 ,
struct V_148 * V_150 , unsigned int V_156 ,
struct V_148 * V_149 , unsigned int V_157 ,
unsigned long V_40 )
{
struct V_1 * V_2 = F_35 ( V_97 ) ;
if ( V_156 != V_157 )
return NULL ;
return F_69 ( V_2 , V_149 , V_150 , V_157 ,
V_88 , V_40 ) ;
}
static struct V_113 * F_76 (
struct V_6 * V_97 , struct V_148 * V_158 , unsigned int V_159 ,
enum V_60 V_61 , unsigned long V_40 , void * V_160 )
{
struct V_1 * V_2 = F_35 ( V_97 ) ;
struct V_148 V_161 ;
F_3 ( V_97 -> V_7 -> V_8 , L_6 , V_9 ) ;
F_74 ( & V_161 , 1 ) ;
switch ( V_61 ) {
case V_84 :
F_70 ( & V_161 ) = V_2 -> V_140 ;
return F_69 ( V_2 , V_158 , & V_161 , V_159 ,
V_61 , V_40 ) ;
case V_76 :
F_70 ( & V_161 ) = V_2 -> V_143 ;
return F_69 ( V_2 , & V_161 , V_158 , V_159 ,
V_61 , V_40 ) ;
default:
return NULL ;
}
}
static int F_77 ( struct V_6 * V_97 )
{
struct V_1 * V_2 = F_35 ( V_97 ) ;
int V_131 ;
F_53 ( & V_2 -> free ) ;
F_53 ( & V_2 -> V_125 ) ;
F_53 ( & V_2 -> V_99 ) ;
F_53 ( & V_2 -> V_101 ) ;
F_53 ( & V_2 -> V_133 ) ;
V_131 = F_47 ( V_2 ) ;
if ( V_131 < 0 )
return V_131 ;
F_3 ( V_97 -> V_7 -> V_8 , L_14 , V_9 ,
V_2 -> V_48 ) ;
F_22 ( V_2 ) ;
return V_131 ;
}
static void F_78 ( struct V_6 * V_97 )
{
struct V_1 * V_2 = F_35 ( V_97 ) ;
struct V_115 * V_116 , * V_127 ;
F_3 ( V_97 -> V_7 -> V_8 , L_6 , V_9 ) ;
F_8 ( V_2 ) ;
F_66 ( V_2 ) ;
F_21 ( V_2 ) ;
F_59 (dpage, tmp, &chan->desc_page, node) {
struct V_25 * V_26 ;
int V_19 ;
F_63 ( & V_116 -> V_28 ) ;
for ( V_19 = 0 , V_26 = V_116 -> V_26 ;
V_19 < F_50 ( V_116 -> V_26 ) ;
V_19 ++ , V_26 ++ )
F_79 ( V_97 -> V_7 -> V_8 , V_26 -> V_30 ,
sizeof( * V_26 -> V_34 ) , V_92 ) ;
F_80 ( ( unsigned long ) V_116 ) ;
}
}
static int F_81 ( struct V_6 * V_97 ,
struct V_162 * V_163 )
{
V_163 -> V_164 = V_165 ;
V_163 -> V_166 = V_165 ;
V_163 -> V_167 = F_10 ( V_76 ) | F_10 ( V_84 ) ;
V_163 -> V_168 = false ;
V_163 -> V_169 = true ;
return 0 ;
}
static struct V_6 * F_82 ( struct V_170 * V_171 ,
struct V_172 * V_173 )
{
struct V_10 * V_11 = V_173 -> V_174 ;
struct V_6 * V_97 ;
struct V_1 * V_2 ;
if ( V_171 -> V_175 != 2 )
return NULL ;
V_97 = F_83 ( & V_11 -> V_12 ) ;
if ( ! V_97 )
return NULL ;
F_3 ( V_97 -> V_7 -> V_8 , L_15 , V_9 ,
V_171 -> V_176 -> V_177 ) ;
V_2 = F_35 ( V_97 ) ;
V_2 -> V_48 = V_171 -> args [ 0 ] ;
V_2 -> V_40 = V_171 -> args [ 1 ] ;
F_20 ( V_2 ) ;
F_22 ( V_2 ) ;
return V_97 ;
}
static void F_84 ( unsigned long V_4 )
{
struct V_1 * V_2 = (struct V_1 * ) V_4 ;
struct V_23 * V_24 , * V_127 ;
T_5 V_178 ;
void * V_179 ;
while ( ! F_37 ( & V_2 -> V_133 ) ) {
bool V_110 = false , V_180 , V_181 = false ;
F_54 ( & V_2 -> V_98 ) ;
F_59 (desc, tmp, &chan->done, node) {
if ( ! V_24 -> V_128 ) {
V_110 = true ;
break;
} else if ( F_62 ( & V_24 -> V_107 ) ) {
F_63 ( & V_24 -> V_28 ) ;
F_57 ( & V_2 -> V_98 ) ;
F_58 ( V_24 ) ;
V_181 = true ;
break;
}
}
if ( V_181 )
continue;
if ( ! V_110 ) {
F_57 ( & V_2 -> V_98 ) ;
break;
}
F_85 ( & V_24 -> V_107 ) ;
if ( F_62 ( & V_24 -> V_107 ) ) {
F_63 ( & V_24 -> V_28 ) ;
V_180 = true ;
} else {
V_24 -> V_128 = true ;
V_180 = false ;
}
V_178 = V_24 -> V_107 . V_178 ;
V_179 = V_24 -> V_107 . V_182 ;
F_57 ( & V_2 -> V_98 ) ;
if ( V_178 )
V_178 ( V_179 ) ;
if ( V_180 )
F_58 ( V_24 ) ;
}
}
static T_6 F_86 ( int V_183 , void * V_8 )
{
struct V_1 * V_2 = V_8 ;
bool V_133 = F_9 ( V_2 ) ;
struct V_23 * V_24 ;
T_6 V_131 ;
bool V_184 = false ;
if ( ! V_133 )
return V_185 ;
F_11 ( V_2 ) ;
F_3 ( & V_2 -> V_6 . V_8 -> V_7 , L_16 , V_9 ) ;
F_87 ( & V_2 -> V_98 ) ;
V_24 = V_2 -> V_102 ;
if ( F_88 ( ! V_24 ) ) {
V_131 = V_185 ;
goto V_100;
} else {
V_131 = V_186 ;
V_184 = true ;
}
F_65 ( & V_24 -> V_28 , & V_2 -> V_133 ) ;
V_2 -> V_102 = NULL ;
if ( ! F_37 ( & V_2 -> V_101 ) ) {
V_24 = F_19 ( & V_2 -> V_101 ,
struct V_23 , V_28 ) ;
if ( ! F_18 ( V_24 ) )
V_2 -> V_102 = V_24 ;
}
V_100:
F_89 ( & V_2 -> V_98 ) ;
if ( V_184 )
F_90 ( & V_2 -> V_187 ) ;
return V_131 ;
}
static T_6 F_91 ( int V_183 , void * V_8 )
{
struct V_10 * V_11 = V_8 ;
T_1 error = F_12 ( V_11 ) ;
F_92 ( V_11 -> V_12 . V_8 , L_17 , V_183 ) ;
if ( ! error )
return V_185 ;
do {
struct V_1 * V_2 = F_13 ( V_11 , error ) ;
F_15 ( V_2 ) ;
F_66 ( V_2 ) ;
error = F_12 ( V_11 ) ;
} while ( error );
return V_186 ;
}
static int F_93 ( struct V_10 * V_11 , int V_188 )
{
struct V_189 * V_12 = & V_11 -> V_12 ;
struct V_1 * V_2 = V_11 -> V_2 + V_188 ;
int V_131 ;
V_2 -> V_11 = V_11 ;
V_2 -> V_5 = V_11 -> V_5 + V_190 + V_191 * V_188 ;
F_53 ( & V_2 -> V_126 ) ;
F_94 ( & V_2 -> V_98 ) ;
V_2 -> V_6 . V_7 = V_12 ;
F_95 ( & V_2 -> V_6 ) ;
F_21 ( V_2 ) ;
F_3 ( V_12 -> V_8 , L_18 , V_9 , V_188 , V_2 -> V_5 ) ;
snprintf ( V_2 -> V_177 , sizeof( V_2 -> V_177 ) , L_19 , V_188 ) ;
F_96 ( & V_2 -> V_187 , F_84 , ( unsigned long ) V_2 ) ;
V_131 = F_97 ( V_12 -> V_8 , V_2 -> V_183 ,
F_86 , V_192 ,
V_2 -> V_177 , V_2 ) ;
if ( V_131 < 0 )
return V_131 ;
F_46 ( & V_2 -> V_6 . V_193 ,
& V_12 -> V_194 ) ;
return 0 ;
}
static int F_98 ( struct V_195 * V_196 )
{
struct V_7 * V_8 = & V_196 -> V_8 ;
const struct V_197 * V_198 = F_99 ( V_199 , V_8 ) ;
struct V_193 * V_176 = V_8 -> V_200 ;
struct V_10 * V_11 ;
struct V_189 * V_12 ;
struct V_201 * V_202 , * V_203 ;
const struct V_204 * V_205 ;
int V_206 ;
int V_131 , V_183 , V_207 , V_19 ;
int V_208 [ 9 ] ;
unsigned int V_209 = 0 ;
F_100 ( sizeof( struct V_115 ) > V_210 ) ;
if ( ! V_176 || ! V_198 || ! V_198 -> V_4 )
return - V_211 ;
V_205 = V_198 -> V_4 ;
V_206 = V_205 -> V_206 ;
V_11 = F_101 ( V_8 , sizeof( * V_11 ) + V_206 *
sizeof( V_11 -> V_2 [ 0 ] ) , V_117 ) ;
if ( ! V_11 ) {
F_17 ( V_8 , L_20 ) ;
return - V_121 ;
}
V_12 = & V_11 -> V_12 ;
V_12 -> V_8 = V_8 ;
V_202 = F_102 ( V_196 , V_212 , 0 ) ;
V_11 -> V_5 = F_103 ( V_8 , V_202 ) ;
if ( F_104 ( V_11 -> V_5 ) )
return F_105 ( V_11 -> V_5 ) ;
V_11 -> V_213 = F_106 ( V_8 , NULL ) ;
if ( F_104 ( V_11 -> V_213 ) )
return F_105 ( V_11 -> V_213 ) ;
V_11 -> V_35 = V_205 ;
for ( V_19 = 0 ; V_209 < F_50 ( V_208 ) ; V_19 ++ ) {
V_203 = F_102 ( V_196 , V_214 , V_19 ) ;
if ( ! V_203 )
break;
for ( V_183 = V_203 -> V_215 ; V_183 <= V_203 -> V_216 ;
V_183 ++ , V_209 ++ )
V_208 [ V_209 ] = V_183 ;
}
if ( V_209 != 1 && V_209 != 2 && V_209 != V_206 + 1 )
return - V_147 ;
if ( V_209 == 1 ) {
V_207 = V_208 [ 0 ] ;
for ( V_19 = 0 ; V_19 <= V_206 ; V_19 ++ )
V_11 -> V_2 [ V_19 ] . V_183 = V_208 [ 0 ] ;
} else {
V_207 = F_107 ( V_196 , L_21 ) ;
if ( V_207 < 0 )
return V_207 ;
if ( V_209 == V_206 + 1 ) {
struct V_1 * V_2 ;
for ( V_19 = 0 , V_2 = V_11 -> V_2 ; V_19 <= V_206 ;
V_19 ++ , V_2 ++ ) {
if ( V_208 [ V_19 ] == V_207 )
V_19 ++ ;
V_2 -> V_183 = V_208 [ V_19 ] ;
}
if ( V_2 != V_11 -> V_2 + V_206 )
return - V_90 ;
} else {
if ( V_208 [ 0 ] == V_207 )
V_183 = V_208 [ 1 ] ;
else
V_183 = V_208 [ 0 ] ;
for ( V_19 = 0 ; V_19 <= V_206 ; V_19 ++ )
V_11 -> V_2 [ V_19 ] . V_183 = V_183 ;
}
}
V_131 = F_97 ( V_8 , V_207 , F_91 ,
V_192 , L_22 , V_11 ) ;
if ( V_131 < 0 )
return V_131 ;
F_53 ( & V_12 -> V_194 ) ;
for ( V_19 = 0 ; V_19 < V_206 ; V_19 ++ ) {
V_131 = F_93 ( V_11 , V_19 ) ;
if ( V_131 < 0 )
return V_131 ;
}
F_108 ( V_217 , V_12 -> V_218 ) ;
F_108 ( V_219 , V_12 -> V_218 ) ;
F_108 ( V_220 , V_12 -> V_218 ) ;
F_108 ( V_221 , V_12 -> V_218 ) ;
V_12 -> V_222
= F_77 ;
V_12 -> V_223 = F_78 ;
V_12 -> V_224 = F_75 ;
V_12 -> V_225 = F_73 ;
V_12 -> V_226 = F_40 ;
V_12 -> V_227 = F_34 ;
V_12 -> V_228 = F_81 ;
V_12 -> V_229 = F_76 ;
V_12 -> V_230 = F_68 ;
F_109 ( V_196 , V_11 ) ;
V_131 = F_110 ( V_11 -> V_213 ) ;
if ( V_131 < 0 )
return V_131 ;
F_32 ( V_11 ) ;
V_131 = F_111 ( V_12 ) ;
if ( V_131 < 0 )
goto V_231;
V_131 = F_112 ( V_176 , F_82 , V_11 ) ;
if ( V_131 < 0 )
goto V_232;
return 0 ;
V_232:
F_113 ( V_12 ) ;
V_231:
F_114 ( V_11 -> V_213 ) ;
return V_131 ;
}
static int F_115 ( struct V_195 * V_196 )
{
struct V_10 * V_11 = F_116 ( V_196 ) ;
F_117 ( V_196 -> V_8 . V_200 ) ;
F_113 ( & V_11 -> V_12 ) ;
F_114 ( V_11 -> V_213 ) ;
return 0 ;
}
static int F_118 ( struct V_7 * V_8 )
{
struct V_10 * V_11 = F_116 ( F_119 ( V_8 ) ) ;
F_114 ( V_11 -> V_213 ) ;
return 0 ;
}
static int F_120 ( struct V_7 * V_8 )
{
struct V_10 * V_11 = F_116 ( F_119 ( V_8 ) ) ;
return F_110 ( V_11 -> V_213 ) ;
}
