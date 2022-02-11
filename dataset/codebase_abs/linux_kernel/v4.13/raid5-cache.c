static inline T_1 F_1 ( struct V_1 * V_2 ,
T_1 V_3 )
{
T_1 V_4 ;
V_4 = F_2 ( V_3 , V_2 -> V_5 ) ;
return V_3 ;
}
bool F_3 ( struct V_6 * log )
{
return ( log != NULL &&
log -> V_7 == V_8 ) ;
}
static T_1 F_4 ( struct V_6 * log , T_1 V_9 , T_1 V_10 )
{
V_9 += V_10 ;
if ( V_9 >= log -> V_11 )
V_9 = V_9 - log -> V_11 ;
return V_9 ;
}
static T_1 F_5 ( struct V_6 * log , T_1 V_9 ,
T_1 V_12 )
{
if ( V_12 >= V_9 )
return V_12 - V_9 ;
else
return V_12 + log -> V_11 - V_9 ;
}
static bool F_6 ( struct V_6 * log , T_1 V_13 )
{
T_1 V_14 ;
V_14 = F_5 ( log , log -> V_15 ,
log -> V_16 ) ;
return log -> V_11 > V_14 + V_13 ;
}
static void F_7 ( struct V_17 * V_18 ,
enum V_19 V_20 )
{
if ( F_8 ( V_18 -> V_20 >= V_20 ) )
return;
V_18 -> V_20 = V_20 ;
}
static void
F_9 ( struct V_1 * V_2 , struct V_21 * V_22 )
{
struct V_23 * V_24 , * V_25 ;
V_24 = V_22 -> V_26 ;
V_22 -> V_26 = NULL ;
while ( V_24 && V_24 -> V_27 . V_28 <
V_22 -> V_29 + V_30 ) {
V_25 = F_10 ( V_24 , V_22 -> V_29 ) ;
F_11 ( V_2 -> V_31 ) ;
F_12 ( V_24 ) ;
V_24 = V_25 ;
}
}
void F_13 ( struct V_1 * V_2 ,
struct V_32 * V_33 , int V_34 )
{
int V_35 ;
for ( V_35 = V_33 -> V_34 ; V_35 -- ; ) {
if ( V_33 -> V_22 [ V_35 ] . V_26 ) {
F_14 ( V_36 , & V_33 -> V_22 [ V_35 ] . V_37 ) ;
F_9 ( V_2 , & V_33 -> V_22 [ V_35 ] ) ;
F_15 ( V_2 -> V_31 -> V_38 , V_33 -> V_29 ,
V_30 ,
! F_16 ( V_39 , & V_33 -> V_20 ) ,
0 ) ;
}
}
}
void F_17 ( struct V_1 * V_2 )
{
int V_40 ;
if ( ! F_3 ( V_2 -> log ) )
return;
V_40 = F_18 ( & V_2 -> V_41 ) +
F_18 ( & V_2 -> V_42 ) ;
if ( V_40 > V_2 -> V_43 * 1 / 2 ||
F_18 ( & V_2 -> V_44 ) > 0 )
F_19 ( V_2 -> log , 0 ) ;
}
void F_20 ( struct V_1 * V_2 )
{
if ( ! F_3 ( V_2 -> log ) )
return;
if ( F_18 ( & V_2 -> V_42 ) >=
F_21 ( F_22 ( V_2 ) ,
V_2 -> V_5 >> V_45 ) )
F_19 ( V_2 -> log , 0 ) ;
}
static T_1 F_23 ( struct V_1 * V_2 )
{
struct V_6 * log = V_2 -> log ;
if ( ! F_3 ( log ) )
return 0 ;
return V_46 *
( ( V_2 -> V_47 + 1 ) * F_18 ( & log -> V_48 ) +
( V_2 -> V_49 - V_2 -> V_47 ) * ( V_2 -> V_50 + 1 ) ) ;
}
static inline void F_24 ( struct V_6 * log )
{
struct V_1 * V_2 = log -> V_51 -> V_31 -> V_52 ;
T_1 V_53 ;
T_1 V_54 ;
bool V_55 = false ;
if ( ! F_3 ( log ) )
return;
V_53 = F_5 ( log , log -> V_16 ,
log -> V_15 ) ;
V_54 = F_23 ( V_2 ) ;
if ( V_53 < 2 * V_54 )
F_14 ( V_56 , & V_2 -> V_57 ) ;
else {
if ( F_16 ( V_56 , & V_2 -> V_57 ) )
V_55 = true ;
F_25 ( V_56 , & V_2 -> V_57 ) ;
}
if ( V_53 < 3 * V_54 )
F_14 ( V_58 , & V_2 -> V_57 ) ;
else
F_25 ( V_58 , & V_2 -> V_57 ) ;
if ( V_55 )
F_19 ( log , 0 ) ;
}
void F_26 ( struct V_32 * V_33 )
{
struct V_1 * V_2 = V_33 -> V_59 ;
struct V_6 * log = V_2 -> log ;
F_27 ( ! F_3 ( log ) ) ;
F_8 ( ! F_16 ( V_60 , & V_33 -> V_20 ) ) ;
F_25 ( V_60 , & V_33 -> V_20 ) ;
if ( ! F_28 ( V_61 , & V_33 -> V_20 ) )
F_29 ( & V_2 -> V_62 ) ;
}
static void F_30 ( struct V_32 * V_33 )
{
int V_35 ;
for ( V_35 = V_33 -> V_34 ; V_35 -- ; )
if ( F_31 ( V_63 , & V_33 -> V_22 [ V_35 ] . V_37 ) ) {
F_14 ( V_64 , & V_33 -> V_22 [ V_35 ] . V_37 ) ;
F_25 ( V_65 , & V_33 -> V_22 [ V_35 ] . V_37 ) ;
}
F_25 ( V_66 , & V_33 -> V_20 ) ;
}
static void F_32 ( struct V_32 * V_33 )
{
int V_35 ;
for ( V_35 = V_33 -> V_34 ; V_35 -- ; )
if ( F_16 ( V_64 , & V_33 -> V_22 [ V_35 ] . V_37 ) )
F_14 ( V_63 , & V_33 -> V_22 [ V_35 ] . V_37 ) ;
}
static void F_33 ( struct V_32 * V_33 )
{
struct V_6 * log = V_33 -> V_59 -> log ;
if ( log -> V_7 == V_67 ) {
F_27 ( F_16 ( V_60 , & V_33 -> V_20 ) ) ;
F_14 ( V_64 , & V_33 -> V_22 [ V_33 -> V_68 ] . V_37 ) ;
} else if ( F_16 ( V_60 , & V_33 -> V_20 ) ) {
F_30 ( V_33 ) ;
} else {
F_32 ( V_33 ) ;
F_14 ( V_64 , & V_33 -> V_22 [ V_33 -> V_68 ] . V_37 ) ;
}
}
static void F_34 ( struct V_17 * V_18 )
{
struct V_32 * V_33 , * V_69 ;
F_35 (sh, next, &io->stripe_list, log_list) {
F_36 ( & V_33 -> V_70 ) ;
F_33 ( V_33 ) ;
F_14 ( V_71 , & V_33 -> V_20 ) ;
F_37 ( V_33 ) ;
}
}
static void F_38 ( struct V_6 * log )
{
struct V_17 * V_18 , * V_69 ;
F_39 ( & log -> V_72 ) ;
F_35 (io, next, &log->running_ios, log_sibling) {
if ( V_18 -> V_20 < V_73 )
break;
F_40 ( & V_18 -> V_74 , & log -> V_75 ) ;
F_34 ( V_18 ) ;
}
}
static void F_41 ( struct V_6 * log )
{
struct V_17 * V_18 , * V_69 ;
F_39 ( & log -> V_72 ) ;
F_35 (io, next, &log->running_ios, log_sibling) {
if ( V_18 -> V_20 < V_73 )
break;
F_40 ( & V_18 -> V_74 , & log -> V_76 ) ;
}
}
static void F_42 ( struct V_23 * V_23 )
{
struct V_17 * V_18 = V_23 -> V_77 ;
struct V_17 * V_78 ;
struct V_6 * log = V_18 -> log ;
unsigned long V_37 ;
bool V_79 ;
bool V_80 ;
if ( V_23 -> V_81 )
F_43 ( log -> V_51 -> V_31 , log -> V_51 ) ;
F_44 ( V_23 ) ;
F_45 ( V_18 -> V_82 , log -> V_83 ) ;
F_46 ( & log -> V_72 , V_37 ) ;
F_7 ( V_18 , V_73 ) ;
V_79 = V_18 -> V_79 ;
V_80 = V_18 -> V_80 ;
if ( log -> V_84 && ! F_47 ( & V_18 -> V_85 ) )
F_41 ( log ) ;
else
F_38 ( log ) ;
if ( ! F_47 ( & log -> V_86 ) ) {
V_78 = F_48 ( & log -> V_86 ,
struct V_17 , V_74 ) ;
if ( V_78 -> V_78 )
F_49 ( & log -> V_87 ) ;
}
F_50 ( & log -> V_72 , V_37 ) ;
if ( log -> V_84 )
F_51 ( log -> V_51 -> V_31 -> V_88 ) ;
if ( V_79 ) {
struct V_23 * V_89 ;
F_8 ( F_52 ( & V_18 -> V_90 ) ) ;
while ( ( V_89 = F_53 ( & V_18 -> V_90 ) ) != NULL ) {
F_12 ( V_89 ) ;
if ( F_54 ( & V_18 -> V_91 ) ) {
F_55 ( V_18 ) ;
return;
}
}
}
if ( V_80 )
if ( F_54 ( & V_18 -> V_91 ) )
F_55 ( V_18 ) ;
}
static void F_56 ( struct V_6 * log , struct V_17 * V_18 )
{
unsigned long V_37 ;
F_46 ( & log -> V_72 , V_37 ) ;
F_7 ( V_18 , V_92 ) ;
F_50 ( & log -> V_72 , V_37 ) ;
if ( V_18 -> V_93 ) {
if ( V_18 -> V_94 )
V_18 -> V_93 -> V_95 |= V_96 ;
if ( V_18 -> V_97 )
V_18 -> V_93 -> V_95 |= V_98 ;
F_57 ( V_18 -> V_93 ) ;
}
if ( V_18 -> V_94 )
V_18 -> V_99 -> V_95 |= V_96 ;
if ( V_18 -> V_97 )
V_18 -> V_99 -> V_95 |= V_98 ;
F_57 ( V_18 -> V_99 ) ;
}
static void F_58 ( struct V_100 * V_101 )
{
struct V_6 * log = F_59 ( V_101 , struct V_6 ,
V_87 ) ;
struct V_17 * V_18 = NULL ;
unsigned long V_37 ;
F_46 ( & log -> V_72 , V_37 ) ;
if ( ! F_47 ( & log -> V_86 ) ) {
V_18 = F_48 ( & log -> V_86 , struct V_17 ,
V_74 ) ;
if ( ! V_18 -> V_78 )
V_18 = NULL ;
else
V_18 -> V_78 = 0 ;
}
F_50 ( & log -> V_72 , V_37 ) ;
if ( V_18 )
F_56 ( log , V_18 ) ;
}
static void F_60 ( struct V_100 * V_101 )
{
struct V_6 * log = F_59 ( V_101 , struct V_6 ,
V_102 ) ;
struct V_31 * V_31 = log -> V_51 -> V_31 ;
if ( log -> V_7 == V_67 )
return;
F_61 ( L_1 ,
F_62 ( V_31 ) ) ;
F_63 ( V_31 -> V_103 ,
! F_16 ( V_104 , & V_31 -> V_105 ) ) ;
F_64 ( V_31 ) ;
log -> V_7 = V_67 ;
F_65 ( V_31 ) ;
}
static void F_66 ( struct V_6 * log )
{
struct V_17 * V_18 = log -> V_106 ;
struct V_23 * V_23 ;
struct V_107 * V_108 ;
unsigned long V_37 ;
T_2 V_109 ;
bool V_110 = true ;
if ( ! V_18 )
return;
V_108 = F_67 ( V_18 -> V_82 ) ;
V_108 -> V_111 = F_68 ( V_18 -> V_112 ) ;
V_109 = F_69 ( log -> V_113 , V_108 , V_114 ) ;
V_108 -> V_115 = F_68 ( V_109 ) ;
V_23 = V_18 -> V_99 ;
log -> V_106 = NULL ;
F_46 ( & log -> V_72 , V_37 ) ;
if ( V_18 -> V_94 || V_18 -> V_97 ) {
if ( V_18 != F_48 ( & log -> V_86 ,
struct V_17 , V_74 ) ) {
V_18 -> V_78 = 1 ;
V_110 = false ;
}
}
F_50 ( & log -> V_72 , V_37 ) ;
if ( V_110 )
F_56 ( log , V_18 ) ;
}
static struct V_23 * F_70 ( struct V_6 * log )
{
struct V_23 * V_23 = F_71 ( V_116 , V_117 , log -> V_118 ) ;
F_72 ( V_23 , V_119 , 0 ) ;
V_23 -> V_120 = log -> V_51 -> V_121 ;
V_23 -> V_27 . V_28 = log -> V_51 -> V_122 + log -> V_16 ;
return V_23 ;
}
static void F_73 ( struct V_6 * log , struct V_17 * V_18 )
{
log -> V_16 = F_4 ( log , log -> V_16 , V_46 ) ;
F_24 ( log ) ;
if ( log -> V_16 == 0 )
V_18 -> V_123 = true ;
V_18 -> V_124 = log -> V_16 ;
}
static struct V_17 * F_74 ( struct V_6 * log )
{
struct V_17 * V_18 ;
struct V_107 * V_108 ;
V_18 = F_75 ( log -> V_125 , V_126 ) ;
if ( ! V_18 )
return NULL ;
memset ( V_18 , 0 , sizeof( * V_18 ) ) ;
V_18 -> log = log ;
F_76 ( & V_18 -> V_74 ) ;
F_76 ( & V_18 -> V_85 ) ;
F_77 ( & V_18 -> V_90 ) ;
V_18 -> V_20 = V_127 ;
V_18 -> V_82 = F_75 ( log -> V_83 , V_116 ) ;
V_108 = F_67 ( V_18 -> V_82 ) ;
F_78 ( V_108 ) ;
V_108 -> V_128 = F_68 ( V_129 ) ;
V_108 -> V_130 = V_131 ;
V_108 -> V_132 = F_79 ( log -> V_132 ) ;
V_108 -> V_133 = F_79 ( log -> V_16 ) ;
V_18 -> V_16 = log -> V_16 ;
V_18 -> V_112 = sizeof( struct V_107 ) ;
V_18 -> V_132 = log -> V_132 ++ ;
V_18 -> V_99 = F_70 ( log ) ;
V_18 -> V_99 -> V_134 = F_42 ;
V_18 -> V_99 -> V_77 = V_18 ;
F_80 ( V_18 -> V_99 , V_18 -> V_82 , V_114 , 0 ) ;
F_73 ( log , V_18 ) ;
F_81 ( & log -> V_72 ) ;
F_82 ( & V_18 -> V_74 , & log -> V_86 ) ;
F_83 ( & log -> V_72 ) ;
return V_18 ;
}
static int F_84 ( struct V_6 * log , unsigned int V_135 )
{
if ( log -> V_106 &&
log -> V_106 -> V_112 + V_135 > V_114 )
F_66 ( log ) ;
if ( ! log -> V_106 ) {
log -> V_106 = F_74 ( log ) ;
if ( ! log -> V_106 )
return - V_136 ;
}
return 0 ;
}
static void F_85 ( struct V_6 * log , T_3 type ,
T_1 V_137 ,
T_2 V_138 , T_2 V_139 ,
bool V_140 )
{
struct V_17 * V_18 = log -> V_106 ;
struct V_141 * V_142 ;
V_142 = F_67 ( V_18 -> V_82 ) + V_18 -> V_112 ;
V_142 -> V_143 . type = F_86 ( type ) ;
V_142 -> V_143 . V_37 = F_86 ( 0 ) ;
V_142 -> V_13 = F_68 ( ( 1 + ! ! V_140 ) <<
( V_144 - 9 ) ) ;
V_142 -> V_137 = F_79 ( V_137 ) ;
V_142 -> V_115 [ 0 ] = F_68 ( V_138 ) ;
if ( V_140 )
V_142 -> V_115 [ 1 ] = F_68 ( V_139 ) ;
V_18 -> V_112 += sizeof( struct V_141 ) +
sizeof( V_145 ) * ( 1 + ! ! V_140 ) ;
}
static void F_87 ( struct V_6 * log , struct V_146 * V_146 )
{
struct V_17 * V_18 = log -> V_106 ;
if ( V_18 -> V_123 ) {
F_27 ( V_18 -> V_93 ) ;
V_18 -> V_93 = V_18 -> V_99 ;
V_18 -> V_99 = F_70 ( log ) ;
F_88 ( V_18 -> V_99 , V_18 -> V_93 ) ;
V_18 -> V_123 = false ;
}
if ( ! F_80 ( V_18 -> V_99 , V_146 , V_114 , 0 ) )
F_89 () ;
F_73 ( log , V_18 ) ;
}
static void F_90 ( struct V_6 * log , T_1 V_3 )
{
struct V_31 * V_31 = log -> V_51 -> V_31 ;
struct V_1 * V_2 = V_31 -> V_52 ;
struct V_17 * V_18 ;
struct V_147 * V_142 ;
int V_111 ;
if ( V_2 -> V_148 )
return;
F_91 ( & log -> V_149 ) ;
V_111 = sizeof( struct V_147 ) + sizeof( V_150 ) ;
if ( F_84 ( log , V_111 ) ) {
F_92 ( & log -> V_149 ) ;
return;
}
V_18 = log -> V_106 ;
V_142 = F_67 ( V_18 -> V_82 ) + V_18 -> V_112 ;
V_142 -> V_143 . type = F_86 ( V_151 ) ;
V_142 -> V_143 . V_37 = F_86 ( 0 ) ;
V_142 -> V_13 = F_68 ( sizeof( V_150 ) ) ;
V_142 -> V_152 [ 0 ] = F_79 ( V_3 ) ;
V_18 -> V_112 += V_111 ;
if ( ! V_18 -> V_80 ) {
V_18 -> V_80 = 1 ;
F_29 ( & V_18 -> V_91 ) ;
}
F_92 ( & log -> V_149 ) ;
}
static int F_93 ( struct V_6 * log , struct V_32 * V_33 ,
int V_153 , int V_154 )
{
int V_35 ;
int V_111 ;
int V_155 ;
struct V_17 * V_18 ;
V_111 =
( ( sizeof( struct V_141 ) + sizeof( V_145 ) )
* V_153 ) +
sizeof( struct V_141 ) +
sizeof( V_145 ) * V_154 ;
V_155 = F_84 ( log , V_111 ) ;
if ( V_155 )
return V_155 ;
V_18 = log -> V_106 ;
if ( F_31 ( V_156 , & V_33 -> V_20 ) )
V_18 -> V_94 = 1 ;
for ( V_35 = 0 ; V_35 < V_33 -> V_34 ; V_35 ++ ) {
if ( ! F_16 ( V_63 , & V_33 -> V_22 [ V_35 ] . V_37 ) ||
F_16 ( V_64 , & V_33 -> V_22 [ V_35 ] . V_37 ) )
continue;
if ( V_35 == V_33 -> V_68 || V_35 == V_33 -> V_157 )
continue;
if ( F_16 ( V_158 , & V_33 -> V_22 [ V_35 ] . V_37 ) &&
log -> V_7 == V_8 ) {
V_18 -> V_97 = 1 ;
V_18 -> V_94 = 1 ;
}
F_85 ( log , V_159 ,
F_94 ( V_33 , V_35 , 0 ) ,
V_33 -> V_22 [ V_35 ] . V_160 , 0 , false ) ;
F_87 ( log , V_33 -> V_22 [ V_35 ] . V_146 ) ;
}
if ( V_154 == 2 ) {
F_85 ( log , V_161 ,
V_33 -> V_29 , V_33 -> V_22 [ V_33 -> V_68 ] . V_160 ,
V_33 -> V_22 [ V_33 -> V_157 ] . V_160 , true ) ;
F_87 ( log , V_33 -> V_22 [ V_33 -> V_68 ] . V_146 ) ;
F_87 ( log , V_33 -> V_22 [ V_33 -> V_157 ] . V_146 ) ;
} else if ( V_154 == 1 ) {
F_85 ( log , V_161 ,
V_33 -> V_29 , V_33 -> V_22 [ V_33 -> V_68 ] . V_160 ,
0 , false ) ;
F_87 ( log , V_33 -> V_22 [ V_33 -> V_68 ] . V_146 ) ;
} else
F_27 ( V_154 != 0 ) ;
F_82 ( & V_33 -> V_70 , & V_18 -> V_85 ) ;
F_29 ( & V_18 -> V_91 ) ;
V_33 -> V_162 = V_18 ;
if ( log -> V_7 == V_67 )
return 0 ;
if ( V_33 -> V_16 == V_163 ) {
F_27 ( ! F_47 ( & V_33 -> V_164 ) ) ;
V_33 -> V_16 = V_18 -> V_16 ;
F_81 ( & log -> V_165 ) ;
F_82 ( & V_33 -> V_164 ,
& log -> V_166 ) ;
F_83 ( & log -> V_165 ) ;
F_29 ( & log -> V_48 ) ;
}
return 0 ;
}
static inline void F_95 ( struct V_6 * log ,
struct V_32 * V_33 )
{
F_96 ( & log -> V_167 ) ;
F_82 ( & V_33 -> V_70 , & log -> V_168 ) ;
F_97 ( & log -> V_167 ) ;
}
int F_98 ( struct V_6 * log , struct V_32 * V_33 )
{
struct V_1 * V_2 = V_33 -> V_59 ;
int V_169 = 0 ;
int V_153 , V_154 ;
int V_170 ;
int V_35 ;
int V_155 = 0 ;
bool V_55 = false ;
if ( ! log )
return - V_171 ;
if ( V_33 -> V_162 || ! F_16 ( V_63 , & V_33 -> V_22 [ V_33 -> V_68 ] . V_37 ) ||
F_16 ( V_172 , & V_33 -> V_20 ) ) {
F_25 ( V_66 , & V_33 -> V_20 ) ;
return - V_171 ;
}
F_8 ( F_16 ( V_60 , & V_33 -> V_20 ) ) ;
for ( V_35 = 0 ; V_35 < V_33 -> V_34 ; V_35 ++ ) {
void * V_173 ;
if ( ! F_16 ( V_63 , & V_33 -> V_22 [ V_35 ] . V_37 ) ||
F_16 ( V_64 , & V_33 -> V_22 [ V_35 ] . V_37 ) )
continue;
V_169 ++ ;
if ( F_16 ( V_66 , & V_33 -> V_20 ) )
continue;
V_173 = F_99 ( V_33 -> V_22 [ V_35 ] . V_146 ) ;
V_33 -> V_22 [ V_35 ] . V_160 = F_69 ( log -> V_113 ,
V_173 , V_114 ) ;
F_100 ( V_173 ) ;
}
V_154 = 1 + ! ! ( V_33 -> V_157 >= 0 ) ;
V_153 = V_169 - V_154 ;
F_14 ( V_66 , & V_33 -> V_20 ) ;
F_25 ( V_174 , & V_33 -> V_20 ) ;
F_29 ( & V_33 -> V_175 ) ;
F_91 ( & log -> V_149 ) ;
V_170 = ( 1 + V_169 ) << ( V_144 - 9 ) ;
if ( log -> V_7 == V_67 ) {
if ( ! F_6 ( log , V_170 ) ) {
F_95 ( log , V_33 ) ;
V_55 = true ;
} else {
V_155 = F_93 ( log , V_33 , V_153 , V_154 ) ;
if ( V_155 ) {
F_81 ( & log -> V_72 ) ;
F_82 ( & V_33 -> V_70 ,
& log -> V_176 ) ;
F_83 ( & log -> V_72 ) ;
}
}
} else {
if ( F_16 ( V_56 , & V_2 -> V_57 ) &&
V_33 -> V_16 == V_163 ) {
F_95 ( log , V_33 ) ;
V_55 = true ;
V_170 = 0 ;
} else if ( ! F_6 ( log , V_170 ) ) {
if ( V_33 -> V_16 == log -> V_15 )
F_89 () ;
else
F_95 ( log , V_33 ) ;
} else {
V_155 = F_93 ( log , V_33 , V_153 , V_154 ) ;
if ( V_155 ) {
F_81 ( & log -> V_72 ) ;
F_82 ( & V_33 -> V_70 ,
& log -> V_176 ) ;
F_83 ( & log -> V_72 ) ;
}
}
}
F_92 ( & log -> V_149 ) ;
if ( V_55 )
F_19 ( log , V_170 ) ;
return 0 ;
}
void F_101 ( struct V_6 * log )
{
if ( ! log )
return;
F_91 ( & log -> V_149 ) ;
F_66 ( log ) ;
F_92 ( & log -> V_149 ) ;
}
int F_102 ( struct V_6 * log , struct V_23 * V_23 )
{
if ( ! log )
return - V_177 ;
if ( log -> V_7 == V_67 ) {
if ( V_23 -> V_27 . V_178 == 0 ) {
F_12 ( V_23 ) ;
return 0 ;
}
V_23 -> V_95 &= ~ V_96 ;
} else {
if ( V_23 -> V_27 . V_178 == 0 ) {
F_91 ( & log -> V_149 ) ;
F_84 ( log , 0 ) ;
F_103 ( & log -> V_106 -> V_90 , V_23 ) ;
log -> V_106 -> V_94 = 1 ;
log -> V_106 -> V_79 = 1 ;
F_29 ( & log -> V_106 -> V_91 ) ;
F_66 ( log ) ;
F_92 ( & log -> V_149 ) ;
return 0 ;
}
}
return - V_171 ;
}
static void F_104 ( struct V_6 * log )
{
struct V_32 * V_33 ;
F_96 ( & log -> V_167 ) ;
while ( ! F_47 ( & log -> V_168 ) ) {
V_33 = F_48 ( & log -> V_168 ,
struct V_32 , V_70 ) ;
F_36 ( & V_33 -> V_70 ) ;
F_14 ( V_71 , & V_33 -> V_20 ) ;
F_37 ( V_33 ) ;
}
F_97 ( & log -> V_167 ) ;
}
static T_1 F_105 ( struct V_1 * V_2 )
{
struct V_32 * V_33 ;
struct V_6 * log = V_2 -> log ;
T_1 V_179 ;
unsigned long V_37 ;
if ( log -> V_7 == V_67 )
return log -> V_180 ;
F_46 ( & log -> V_165 , V_37 ) ;
if ( F_47 ( & V_2 -> log -> V_166 ) ) {
F_50 ( & log -> V_165 , V_37 ) ;
return log -> V_180 ;
}
V_33 = F_48 ( & V_2 -> log -> V_166 ,
struct V_32 , V_164 ) ;
V_179 = V_33 -> V_16 ;
F_50 ( & log -> V_165 , V_37 ) ;
return V_179 ;
}
static T_1 F_106 ( struct V_6 * log )
{
struct V_1 * V_2 = log -> V_51 -> V_31 -> V_52 ;
return F_5 ( log , log -> V_15 ,
F_105 ( V_2 ) ) ;
}
static void F_107 ( struct V_6 * log )
{
struct V_32 * V_33 ;
F_39 ( & log -> V_72 ) ;
if ( ! F_47 ( & log -> V_176 ) ) {
V_33 = F_48 ( & log -> V_176 ,
struct V_32 , V_70 ) ;
F_36 ( & V_33 -> V_70 ) ;
F_14 ( V_71 , & V_33 -> V_20 ) ;
F_37 ( V_33 ) ;
}
}
static bool F_108 ( struct V_6 * log )
{
struct V_17 * V_18 , * V_69 ;
bool V_181 = false ;
F_39 ( & log -> V_72 ) ;
F_35 (io, next, &log->finished_ios, log_sibling) {
if ( V_18 -> V_20 < V_182 )
break;
log -> V_180 = V_18 -> V_16 ;
F_109 ( & V_18 -> V_74 ) ;
F_45 ( V_18 , log -> V_125 ) ;
F_107 ( log ) ;
V_181 = true ;
}
return V_181 ;
}
static void F_55 ( struct V_17 * V_18 )
{
struct V_6 * log = V_18 -> log ;
struct V_1 * V_2 = log -> V_51 -> V_31 -> V_52 ;
unsigned long V_37 ;
F_46 ( & log -> V_72 , V_37 ) ;
F_7 ( V_18 , V_182 ) ;
if ( ! F_108 ( log ) ) {
F_50 ( & log -> V_72 , V_37 ) ;
return;
}
if ( F_106 ( log ) > log -> V_183 ||
F_16 ( V_58 , & V_2 -> V_57 ) )
F_19 ( log , 0 ) ;
F_50 ( & log -> V_72 , V_37 ) ;
F_110 ( & log -> V_184 ) ;
}
void F_111 ( struct V_32 * V_33 )
{
struct V_17 * V_18 ;
V_18 = V_33 -> V_162 ;
V_33 -> V_162 = NULL ;
if ( V_18 && F_54 ( & V_18 -> V_91 ) )
F_55 ( V_18 ) ;
}
static void F_112 ( struct V_23 * V_23 )
{
struct V_6 * log = F_59 ( V_23 , struct V_6 ,
V_185 ) ;
unsigned long V_37 ;
struct V_17 * V_18 ;
if ( V_23 -> V_81 )
F_43 ( log -> V_51 -> V_31 , log -> V_51 ) ;
F_46 ( & log -> V_72 , V_37 ) ;
F_113 (io, &log->flushing_ios, log_sibling)
F_34 ( V_18 ) ;
F_114 ( & log -> V_186 , & log -> V_75 ) ;
F_50 ( & log -> V_72 , V_37 ) ;
}
void F_115 ( struct V_6 * log )
{
bool V_187 ;
if ( ! log || ! log -> V_84 )
return;
F_81 ( & log -> V_72 ) ;
if ( ! F_47 ( & log -> V_186 ) ) {
F_83 ( & log -> V_72 ) ;
return;
}
F_114 ( & log -> V_76 , & log -> V_186 ) ;
V_187 = ! F_47 ( & log -> V_186 ) ;
F_83 ( & log -> V_72 ) ;
if ( ! V_187 )
return;
F_116 ( & log -> V_185 ) ;
log -> V_185 . V_120 = log -> V_51 -> V_121 ;
log -> V_185 . V_134 = F_112 ;
log -> V_185 . V_95 = V_119 | V_96 ;
F_57 ( & log -> V_185 ) ;
}
static void F_117 ( struct V_6 * log ,
T_1 V_12 )
{
struct V_188 * V_121 = log -> V_51 -> V_121 ;
struct V_31 * V_31 ;
F_118 ( log , V_12 ) ;
if ( ! F_119 ( F_120 ( V_121 ) ) )
return;
V_31 = log -> V_51 -> V_31 ;
F_121 ( & V_31 -> V_105 , 0 ,
F_122 ( V_189 ) | F_122 ( V_104 ) ) ;
if ( ! F_123 ( V_31 ) )
return;
F_124 ( V_31 , 1 ) ;
F_125 ( V_31 ) ;
if ( log -> V_15 < V_12 ) {
F_126 ( V_121 ,
log -> V_15 + log -> V_51 -> V_122 ,
V_12 - log -> V_15 , V_116 , 0 ) ;
} else {
F_126 ( V_121 ,
log -> V_15 + log -> V_51 -> V_122 ,
log -> V_11 - log -> V_15 ,
V_116 , 0 ) ;
F_126 ( V_121 , log -> V_51 -> V_122 , V_12 ,
V_116 , 0 ) ;
}
}
static void F_127 ( struct V_1 * V_2 , struct V_32 * V_33 )
{
F_27 ( F_47 ( & V_33 -> V_190 ) ) ;
F_27 ( ! F_16 ( V_60 , & V_33 -> V_20 ) ) ;
F_27 ( F_16 ( V_71 , & V_33 -> V_20 ) ) ;
F_27 ( F_16 ( V_191 , & V_33 -> V_20 ) ) ;
F_39 ( & V_2 -> V_192 ) ;
F_36 ( & V_33 -> V_190 ) ;
F_29 ( & V_33 -> V_175 ) ;
F_14 ( V_71 , & V_33 -> V_20 ) ;
F_29 ( & V_2 -> V_193 ) ;
F_26 ( V_33 ) ;
if ( F_16 ( V_194 , & V_33 -> V_20 ) )
F_29 ( & V_2 -> V_195 ) ;
else
F_29 ( & V_2 -> V_196 ) ;
F_37 ( V_33 ) ;
}
void F_128 ( struct V_1 * V_2 , int V_197 )
{
int V_175 ;
struct V_32 * V_33 , * V_69 ;
F_39 ( & V_2 -> V_192 ) ;
if ( ! V_2 -> log )
return;
V_175 = 0 ;
F_35 (sh, next, &conf->r5c_full_stripe_list, lru) {
F_127 ( V_2 , V_33 ) ;
V_175 ++ ;
}
if ( V_175 >= V_197 )
return;
F_35 (sh, next,
&conf->r5c_partial_stripe_list, lru) {
F_127 ( V_2 , V_33 ) ;
if ( ++ V_175 >= V_197 )
break;
}
}
static void F_129 ( struct V_1 * V_2 )
{
struct V_6 * log = V_2 -> log ;
struct V_32 * V_33 ;
int V_175 = 0 ;
unsigned long V_37 ;
int V_40 ;
int V_198 ;
int V_199 , V_200 ;
if ( ! F_3 ( log ) )
return;
V_199 = F_18 ( & V_2 -> V_195 ) ;
V_200 = F_18 ( & V_2 -> V_196 ) ;
V_40 = F_18 ( & V_2 -> V_41 ) +
F_18 ( & V_2 -> V_42 ) -
V_200 - V_199 ;
if ( V_40 > V_2 -> V_43 * 3 / 4 ||
F_18 ( & V_2 -> V_44 ) > 0 )
V_198 = V_201 ;
else if ( V_40 > V_2 -> V_43 * 1 / 2 ||
F_18 ( & V_2 -> V_42 ) - V_200 >
F_22 ( V_2 ) )
V_198 = 0 ;
else
V_198 = - 1 ;
if ( V_198 >= 0 ) {
F_46 ( & V_2 -> V_192 , V_37 ) ;
F_128 ( V_2 , V_198 ) ;
F_50 ( & V_2 -> V_192 , V_37 ) ;
}
if ( F_16 ( V_58 , & V_2 -> V_57 ) ) {
F_46 ( & log -> V_165 , V_37 ) ;
F_96 ( & V_2 -> V_192 ) ;
F_113 (sh, &log->stripe_in_journal_list, r5c) {
if ( ! F_47 ( & V_33 -> V_190 ) &&
! F_16 ( V_71 , & V_33 -> V_20 ) &&
F_18 ( & V_33 -> V_175 ) == 0 ) {
F_127 ( V_2 , V_33 ) ;
if ( V_175 ++ >= V_201 )
break;
}
}
F_97 ( & V_2 -> V_192 ) ;
F_50 ( & log -> V_165 , V_37 ) ;
}
if ( ! F_16 ( V_56 , & V_2 -> V_57 ) )
F_104 ( log ) ;
F_51 ( V_2 -> V_31 -> V_88 ) ;
}
static void F_130 ( struct V_6 * log )
{
struct V_1 * V_2 = log -> V_51 -> V_31 -> V_52 ;
T_1 V_202 = F_131 ( & log -> V_202 , 0 ) ;
T_1 V_203 ;
T_1 V_180 ;
bool V_204 ;
F_81 ( & log -> V_72 ) ;
V_204 = F_106 ( log ) > log -> V_183 ||
V_202 != 0 || ! F_47 ( & log -> V_168 ) ;
while ( 1 ) {
V_203 = F_106 ( log ) ;
if ( V_203 >= V_202 ||
( F_47 ( & log -> V_86 ) &&
F_47 ( & log -> V_76 ) &&
F_47 ( & log -> V_186 ) &&
F_47 ( & log -> V_75 ) ) )
break;
F_51 ( log -> V_51 -> V_31 -> V_88 ) ;
F_132 ( log -> V_184 ,
F_106 ( log ) > V_203 ,
log -> V_72 ) ;
}
V_180 = F_105 ( V_2 ) ;
F_83 ( & log -> V_72 ) ;
if ( V_203 == 0 || ! V_204 )
return;
F_117 ( log , V_180 ) ;
F_91 ( & log -> V_149 ) ;
log -> V_15 = V_180 ;
F_24 ( log ) ;
F_92 ( & log -> V_149 ) ;
F_104 ( log ) ;
}
static void F_133 ( struct V_205 * V_88 )
{
struct V_31 * V_31 = V_88 -> V_31 ;
struct V_1 * V_2 = V_31 -> V_52 ;
struct V_6 * log = V_2 -> log ;
if ( ! log )
return;
F_129 ( V_2 ) ;
F_130 ( log ) ;
}
void F_19 ( struct V_6 * log , T_1 V_206 )
{
unsigned long V_207 ;
unsigned long V_208 = ( unsigned long ) V_206 ;
if ( ! log )
return;
do {
V_207 = log -> V_202 ;
if ( V_208 < V_207 )
return;
} while ( F_134 ( & log -> V_202 , V_207 , V_208 ) != V_207 );
F_51 ( log -> V_209 ) ;
}
void F_135 ( struct V_6 * log , int V_20 )
{
struct V_31 * V_31 ;
if ( ! log || V_20 == 2 )
return;
if ( V_20 == 0 )
F_136 ( log -> V_209 -> V_210 ) ;
else if ( V_20 == 1 ) {
V_31 = log -> V_51 -> V_31 ;
F_110 ( & V_31 -> V_103 ) ;
F_137 ( log -> V_209 -> V_210 ) ;
F_19 ( log , V_163 ) ;
F_130 ( log ) ;
}
}
bool F_138 ( struct V_1 * V_2 )
{
struct V_6 * log ;
bool V_155 ;
F_139 () ;
log = F_140 ( V_2 -> log ) ;
if ( ! log )
V_155 = F_16 ( V_211 , & V_2 -> V_31 -> V_37 ) ;
else
V_155 = F_16 ( V_212 , & log -> V_51 -> V_37 ) ;
F_141 () ;
return V_155 ;
}
static int F_142 ( struct V_6 * log ,
struct V_213 * V_214 )
{
struct V_146 * V_146 ;
V_214 -> V_215 = F_71 ( V_216 , V_117 , log -> V_118 ) ;
if ( ! V_214 -> V_215 )
return - V_136 ;
V_214 -> V_217 = 0 ;
V_214 -> V_218 = 0 ;
while ( V_214 -> V_218 < V_219 ) {
V_146 = F_143 ( V_216 ) ;
if ( ! V_146 )
break;
V_214 -> V_220 [ V_214 -> V_218 ] = V_146 ;
V_214 -> V_218 += 1 ;
}
if ( V_214 -> V_218 == 0 ) {
F_44 ( V_214 -> V_215 ) ;
return - V_136 ;
}
V_214 -> V_221 = 0 ;
return 0 ;
}
static void F_144 ( struct V_6 * log ,
struct V_213 * V_214 )
{
int V_35 ;
for ( V_35 = 0 ; V_35 < V_214 -> V_218 ; ++ V_35 )
F_145 ( V_214 -> V_220 [ V_35 ] ) ;
F_44 ( V_214 -> V_215 ) ;
}
static int F_146 ( struct V_6 * log ,
struct V_213 * V_214 ,
T_1 V_4 )
{
F_116 ( V_214 -> V_215 ) ;
V_214 -> V_215 -> V_120 = log -> V_51 -> V_121 ;
F_72 ( V_214 -> V_215 , V_222 , 0 ) ;
V_214 -> V_215 -> V_27 . V_28 = log -> V_51 -> V_122 + V_4 ;
V_214 -> V_217 = 0 ;
V_214 -> V_221 = V_4 ;
while ( V_214 -> V_217 < V_214 -> V_218 ) {
F_80 ( V_214 -> V_215 ,
V_214 -> V_220 [ V_214 -> V_217 ] , V_114 , 0 ) ;
V_214 -> V_217 += 1 ;
V_4 = F_4 ( log , V_4 , V_46 ) ;
if ( V_4 == 0 )
break;
}
return F_147 ( V_214 -> V_215 ) ;
}
static int F_148 ( struct V_6 * log ,
struct V_213 * V_214 ,
struct V_146 * V_146 ,
T_1 V_4 )
{
int V_155 ;
if ( V_4 < V_214 -> V_221 ||
V_4 >= V_214 -> V_221 + V_214 -> V_217 * V_46 ) {
V_155 = F_146 ( log , V_214 , V_4 ) ;
if ( V_155 )
return V_155 ;
}
F_27 ( V_4 < V_214 -> V_221 ||
V_4 >= V_214 -> V_221 + V_214 -> V_217 * V_46 ) ;
memcpy ( F_67 ( V_146 ) ,
F_67 ( V_214 -> V_220 [ ( V_4 - V_214 -> V_221 ) >>
V_223 ] ) ,
V_114 ) ;
return 0 ;
}
static int F_149 ( struct V_6 * log ,
struct V_213 * V_214 )
{
struct V_146 * V_146 = V_214 -> V_82 ;
struct V_107 * V_224 ;
T_2 V_109 , V_225 ;
int V_155 ;
V_155 = F_148 ( log , V_214 , V_146 , V_214 -> V_226 ) ;
if ( V_155 != 0 )
return V_155 ;
V_224 = F_67 ( V_146 ) ;
V_225 = F_150 ( V_224 -> V_115 ) ;
V_224 -> V_115 = 0 ;
if ( F_150 ( V_224 -> V_128 ) != V_129 ||
F_151 ( V_224 -> V_132 ) != V_214 -> V_132 ||
V_224 -> V_130 != V_131 ||
F_151 ( V_224 -> V_133 ) != V_214 -> V_226 )
return - V_227 ;
V_109 = F_69 ( log -> V_113 , V_224 , V_114 ) ;
if ( V_225 != V_109 )
return - V_227 ;
if ( F_150 ( V_224 -> V_111 ) > V_114 )
return - V_227 ;
V_214 -> V_228 = V_46 ;
return 0 ;
}
static void
F_152 ( struct V_6 * log ,
struct V_146 * V_146 ,
T_1 V_226 , T_4 V_132 )
{
struct V_107 * V_224 ;
V_224 = F_67 ( V_146 ) ;
F_78 ( V_224 ) ;
V_224 -> V_128 = F_68 ( V_129 ) ;
V_224 -> V_130 = V_131 ;
V_224 -> V_111 = F_68 ( sizeof( struct V_107 ) ) ;
V_224 -> V_132 = F_79 ( V_132 ) ;
V_224 -> V_133 = F_79 ( V_226 ) ;
}
static int F_153 ( struct V_6 * log , T_1 V_226 ,
T_4 V_132 )
{
struct V_146 * V_146 ;
struct V_107 * V_224 ;
V_146 = F_143 ( V_216 ) ;
if ( ! V_146 )
return - V_136 ;
F_152 ( log , V_146 , V_226 , V_132 ) ;
V_224 = F_67 ( V_146 ) ;
V_224 -> V_115 = F_68 ( F_69 ( log -> V_113 ,
V_224 , V_114 ) ) ;
if ( ! F_154 ( log -> V_51 , V_226 , V_114 , V_146 , V_119 ,
V_229 | V_98 , false ) ) {
F_155 ( V_146 ) ;
return - V_230 ;
}
F_155 ( V_146 ) ;
return 0 ;
}
static void F_156 ( struct V_6 * log ,
struct V_32 * V_33 ,
struct V_213 * V_214 ,
struct V_141 * V_142 ,
T_1 V_231 )
{
struct V_31 * V_31 = log -> V_51 -> V_31 ;
struct V_1 * V_2 = V_31 -> V_52 ;
int V_232 ;
F_157 ( V_2 ,
F_151 ( V_142 -> V_137 ) , 0 ,
& V_232 , V_33 ) ;
F_148 ( log , V_214 , V_33 -> V_22 [ V_232 ] . V_146 , V_231 ) ;
V_33 -> V_22 [ V_232 ] . V_160 =
F_150 ( V_142 -> V_115 [ 0 ] ) ;
V_214 -> V_228 += V_46 ;
F_14 ( V_63 , & V_33 -> V_22 [ V_232 ] . V_37 ) ;
F_14 ( V_60 , & V_33 -> V_20 ) ;
}
static void F_158 ( struct V_6 * log ,
struct V_32 * V_33 ,
struct V_213 * V_214 ,
struct V_141 * V_142 ,
T_1 V_231 )
{
struct V_31 * V_31 = log -> V_51 -> V_31 ;
struct V_1 * V_2 = V_31 -> V_52 ;
V_214 -> V_228 += V_46 * V_2 -> V_47 ;
F_148 ( log , V_214 , V_33 -> V_22 [ V_33 -> V_68 ] . V_146 , V_231 ) ;
V_33 -> V_22 [ V_33 -> V_68 ] . V_160 =
F_150 ( V_142 -> V_115 [ 0 ] ) ;
F_14 ( V_63 , & V_33 -> V_22 [ V_33 -> V_68 ] . V_37 ) ;
if ( V_33 -> V_157 >= 0 ) {
F_148 (
log , V_214 , V_33 -> V_22 [ V_33 -> V_157 ] . V_146 ,
F_4 ( log , V_231 , V_46 ) ) ;
V_33 -> V_22 [ V_33 -> V_157 ] . V_160 =
F_150 ( V_142 -> V_115 [ 1 ] ) ;
F_14 ( V_63 , & V_33 -> V_22 [ V_33 -> V_157 ] . V_37 ) ;
}
F_25 ( V_60 , & V_33 -> V_20 ) ;
}
static void F_159 ( struct V_32 * V_33 )
{
int V_35 ;
V_33 -> V_20 = 0 ;
V_33 -> V_16 = V_163 ;
for ( V_35 = V_33 -> V_34 ; V_35 -- ; )
V_33 -> V_22 [ V_35 ] . V_37 = 0 ;
}
static void
F_160 ( struct V_1 * V_2 ,
struct V_32 * V_33 ,
struct V_213 * V_214 )
{
struct V_233 * V_51 , * V_234 ;
int V_235 ;
int V_236 = 0 ;
for ( V_235 = 0 ; V_235 < V_33 -> V_34 ; V_235 ++ ) {
if ( ! F_16 ( V_63 , & V_33 -> V_22 [ V_235 ] . V_37 ) )
continue;
if ( V_235 == V_33 -> V_157 || V_235 == V_33 -> V_68 )
continue;
V_236 ++ ;
}
if ( V_236 == 0 )
goto V_237;
for ( V_235 = 0 ; V_235 < V_33 -> V_34 ; V_235 ++ ) {
if ( ! F_16 ( V_63 , & V_33 -> V_22 [ V_235 ] . V_37 ) )
continue;
F_139 () ;
V_51 = F_140 ( V_2 -> V_34 [ V_235 ] . V_51 ) ;
if ( V_51 ) {
F_29 ( & V_51 -> V_238 ) ;
F_141 () ;
F_154 ( V_51 , V_33 -> V_29 , V_114 ,
V_33 -> V_22 [ V_235 ] . V_146 , V_119 , 0 ,
false ) ;
F_161 ( V_51 , V_51 -> V_31 ) ;
F_139 () ;
}
V_234 = F_140 ( V_2 -> V_34 [ V_235 ] . V_239 ) ;
if ( V_234 ) {
F_29 ( & V_234 -> V_238 ) ;
F_141 () ;
F_154 ( V_234 , V_33 -> V_29 , V_114 ,
V_33 -> V_22 [ V_235 ] . V_146 , V_119 , 0 ,
false ) ;
F_161 ( V_234 , V_234 -> V_31 ) ;
F_139 () ;
}
F_141 () ;
}
V_214 -> V_240 ++ ;
V_237:
F_159 ( V_33 ) ;
}
static struct V_32 *
F_162 ( struct V_1 * V_2 ,
T_1 V_241 )
{
struct V_32 * V_33 ;
V_33 = F_163 ( V_2 , V_241 , 0 , 1 , 0 ) ;
if ( ! V_33 )
return NULL ;
F_159 ( V_33 ) ;
return V_33 ;
}
static struct V_32 *
F_164 ( struct V_242 * V_243 , T_1 V_3 )
{
struct V_32 * V_33 ;
F_113 (sh, list, lru)
if ( V_33 -> V_29 == V_3 )
return V_33 ;
return NULL ;
}
static void
F_165 ( struct V_242 * V_244 ,
struct V_213 * V_214 )
{
struct V_32 * V_33 , * V_69 ;
F_35 (sh, next, cached_stripe_list, lru) {
F_159 ( V_33 ) ;
F_36 ( & V_33 -> V_190 ) ;
F_37 ( V_33 ) ;
}
}
static void
F_166 ( struct V_242 * V_244 ,
struct V_213 * V_214 )
{
struct V_32 * V_33 , * V_69 ;
F_35 (sh, next, cached_stripe_list, lru)
if ( ! F_16 ( V_60 , & V_33 -> V_20 ) ) {
F_160 ( V_33 -> V_59 , V_33 , V_214 ) ;
F_36 ( & V_33 -> V_190 ) ;
F_37 ( V_33 ) ;
}
}
static int
F_167 ( struct V_6 * log ,
struct V_213 * V_214 ,
struct V_146 * V_146 ,
T_1 V_231 , V_145 V_160 )
{
void * V_173 ;
T_2 V_115 ;
F_148 ( log , V_214 , V_146 , V_231 ) ;
V_173 = F_99 ( V_146 ) ;
V_115 = F_69 ( log -> V_113 , V_173 , V_114 ) ;
F_100 ( V_173 ) ;
return ( F_150 ( V_160 ) == V_115 ) ? 0 : - V_227 ;
}
static int
F_168 ( struct V_6 * log ,
struct V_213 * V_214 )
{
struct V_31 * V_31 = log -> V_51 -> V_31 ;
struct V_1 * V_2 = V_31 -> V_52 ;
struct V_107 * V_224 = F_67 ( V_214 -> V_82 ) ;
T_1 V_245 = sizeof( struct V_107 ) ;
T_1 V_231 = F_4 ( log , V_214 -> V_226 , V_46 ) ;
struct V_146 * V_146 ;
struct V_141 * V_142 ;
struct V_147 * V_246 ;
V_146 = F_143 ( V_216 ) ;
if ( ! V_146 )
return - V_136 ;
while ( V_245 < F_150 ( V_224 -> V_111 ) ) {
V_142 = ( void * ) V_224 + V_245 ;
V_246 = ( void * ) V_224 + V_245 ;
if ( F_169 ( V_142 -> V_143 . type ) == V_159 ) {
if ( F_167 (
log , V_214 , V_146 , V_231 ,
V_142 -> V_115 [ 0 ] ) < 0 )
goto V_247;
} else if ( F_169 ( V_142 -> V_143 . type ) == V_161 ) {
if ( F_167 (
log , V_214 , V_146 , V_231 ,
V_142 -> V_115 [ 0 ] ) < 0 )
goto V_247;
if ( V_2 -> V_47 == 2 &&
F_167 (
log , V_214 , V_146 ,
F_4 ( log , V_231 ,
V_46 ) ,
V_142 -> V_115 [ 1 ] ) < 0 )
goto V_247;
} else if ( F_169 ( V_142 -> V_143 . type ) == V_151 ) {
} else
goto V_247;
if ( F_169 ( V_142 -> V_143 . type ) == V_151 ) {
V_245 += sizeof( struct V_147 ) +
F_150 ( V_246 -> V_13 ) ;
} else {
V_231 = F_4 ( log , V_231 ,
F_150 ( V_142 -> V_13 ) ) ;
V_245 += sizeof( struct V_141 ) +
sizeof( V_145 ) *
( F_150 ( V_142 -> V_13 ) >> ( V_144 - 9 ) ) ;
}
}
F_145 ( V_146 ) ;
return 0 ;
V_247:
F_145 ( V_146 ) ;
return - V_227 ;
}
static int
F_170 ( struct V_6 * log ,
struct V_213 * V_214 ,
struct V_242 * V_244 )
{
struct V_31 * V_31 = log -> V_51 -> V_31 ;
struct V_1 * V_2 = V_31 -> V_52 ;
struct V_107 * V_224 ;
struct V_141 * V_142 ;
struct V_147 * V_246 ;
int V_245 ;
T_1 V_231 ;
T_1 V_241 ;
struct V_32 * V_33 ;
int V_155 ;
V_155 = F_168 ( log , V_214 ) ;
if ( V_155 == - V_227 )
return - V_171 ;
else if ( V_155 )
return V_155 ;
V_224 = F_67 ( V_214 -> V_82 ) ;
V_245 = sizeof( struct V_107 ) ;
V_231 = F_4 ( log , V_214 -> V_226 , V_46 ) ;
while ( V_245 < F_150 ( V_224 -> V_111 ) ) {
int V_248 ;
V_142 = ( void * ) V_224 + V_245 ;
V_246 = ( void * ) V_224 + V_245 ;
if ( F_169 ( V_142 -> V_143 . type ) == V_151 ) {
int V_35 , V_175 ;
V_175 = F_150 ( V_246 -> V_13 ) / sizeof( V_150 ) ;
for ( V_35 = 0 ; V_35 < V_175 ; ++ V_35 ) {
V_241 = F_151 ( V_246 -> V_152 [ V_35 ] ) ;
V_33 = F_164 ( V_244 ,
V_241 ) ;
if ( V_33 ) {
F_8 ( F_16 ( V_60 , & V_33 -> V_20 ) ) ;
F_159 ( V_33 ) ;
F_36 ( & V_33 -> V_190 ) ;
F_37 ( V_33 ) ;
}
}
V_245 += sizeof( struct V_147 ) +
F_150 ( V_246 -> V_13 ) ;
continue;
}
V_241 = ( F_169 ( V_142 -> V_143 . type ) == V_159 ) ?
F_157 (
V_2 , F_151 ( V_142 -> V_137 ) , 0 , & V_248 ,
NULL )
: F_151 ( V_142 -> V_137 ) ;
V_33 = F_164 ( V_244 ,
V_241 ) ;
if ( ! V_33 ) {
V_33 = F_162 ( V_2 , V_241 ) ;
if ( ! V_33 ) {
F_166 (
V_244 , V_214 ) ;
V_33 = F_162 (
V_2 , V_241 ) ;
}
if ( ! V_33 ) {
F_171 ( L_2 ,
F_62 ( V_31 ) ,
V_2 -> V_43 * 2 ) ;
F_172 ( V_31 ,
V_2 -> V_43 * 2 ) ;
V_33 = F_162 ( V_2 ,
V_241 ) ;
}
if ( ! V_33 ) {
F_173 ( L_3 ,
F_62 ( V_31 ) ) ;
return - V_136 ;
}
F_82 ( & V_33 -> V_190 , V_244 ) ;
}
if ( F_169 ( V_142 -> V_143 . type ) == V_159 ) {
if ( ! F_16 ( V_60 , & V_33 -> V_20 ) &&
F_16 ( V_63 , & V_33 -> V_22 [ V_33 -> V_68 ] . V_37 ) ) {
F_160 ( V_2 , V_33 , V_214 ) ;
F_40 ( & V_33 -> V_190 , V_244 ) ;
}
F_156 ( log , V_33 , V_214 , V_142 ,
V_231 ) ;
} else if ( F_169 ( V_142 -> V_143 . type ) == V_161 )
F_158 ( log , V_33 , V_214 , V_142 ,
V_231 ) ;
else
return - V_227 ;
V_231 = F_4 ( log , V_231 ,
F_150 ( V_142 -> V_13 ) ) ;
V_245 += sizeof( struct V_141 ) +
sizeof( V_145 ) *
( F_150 ( V_142 -> V_13 ) >> ( V_144 - 9 ) ) ;
}
return 0 ;
}
static void F_174 ( struct V_6 * log ,
struct V_32 * V_33 )
{
struct V_21 * V_22 ;
int V_35 ;
for ( V_35 = V_33 -> V_34 ; V_35 -- ; ) {
V_22 = V_33 -> V_22 + V_35 ;
if ( F_31 ( V_63 , & V_22 -> V_37 ) ) {
F_14 ( V_64 , & V_22 -> V_37 ) ;
F_14 ( V_36 , & V_22 -> V_37 ) ;
}
}
}
static int F_175 ( struct V_6 * log ,
struct V_213 * V_214 )
{
struct V_32 * V_33 ;
int V_155 = 0 ;
while ( 1 ) {
if ( F_149 ( log , V_214 ) )
break;
V_155 = F_170 ( log , V_214 ,
& V_214 -> V_249 ) ;
if ( V_155 && V_155 != - V_171 )
break;
V_214 -> V_132 ++ ;
V_214 -> V_226 = F_4 ( log , V_214 -> V_226 , V_214 -> V_228 ) ;
}
if ( V_155 == - V_136 ) {
F_165 ( & V_214 -> V_249 , V_214 ) ;
return V_155 ;
}
F_166 ( & V_214 -> V_249 , V_214 ) ;
F_113 (sh, &ctx->cached_list, lru) {
F_8 ( ! F_16 ( V_60 , & V_33 -> V_20 ) ) ;
F_174 ( log , V_33 ) ;
V_214 -> V_250 ++ ;
}
return 0 ;
}
static int
F_176 ( struct V_6 * log ,
struct V_213 * V_214 )
{
struct V_32 * V_33 ;
struct V_31 * V_31 = log -> V_51 -> V_31 ;
struct V_146 * V_146 ;
T_1 V_180 = V_163 ;
V_146 = F_143 ( V_216 ) ;
if ( ! V_146 ) {
F_173 ( L_4 ,
F_62 ( V_31 ) ) ;
return - V_136 ;
}
F_8 ( F_47 ( & V_214 -> V_249 ) ) ;
F_113 (sh, &ctx->cached_list, lru) {
struct V_107 * V_224 ;
int V_35 ;
int V_4 ;
T_1 V_251 ;
F_8 ( ! F_16 ( V_60 , & V_33 -> V_20 ) ) ;
F_152 ( log , V_146 ,
V_214 -> V_226 , V_214 -> V_132 ) ;
V_224 = F_67 ( V_146 ) ;
V_4 = F_150 ( V_224 -> V_111 ) ;
V_251 = F_4 ( log , V_214 -> V_226 , V_46 ) ;
for ( V_35 = V_33 -> V_34 ; V_35 -- ; ) {
struct V_21 * V_22 = & V_33 -> V_22 [ V_35 ] ;
struct V_141 * V_142 ;
void * V_173 ;
if ( F_16 ( V_64 , & V_22 -> V_37 ) ) {
V_142 = ( void * ) V_224 + V_4 ;
V_142 -> V_143 . type = F_86 (
V_159 ) ;
V_142 -> V_13 = F_68 ( V_46 ) ;
V_142 -> V_137 = F_79 (
F_94 ( V_33 , V_35 , 0 ) ) ;
V_173 = F_99 ( V_22 -> V_146 ) ;
V_142 -> V_115 [ 0 ] = F_68 (
F_69 ( log -> V_113 , V_173 ,
V_114 ) ) ;
F_100 ( V_173 ) ;
F_154 ( log -> V_51 , V_251 , V_114 ,
V_22 -> V_146 , V_119 , 0 , false ) ;
V_251 = F_4 ( log , V_251 ,
V_46 ) ;
V_4 += sizeof( V_145 ) +
sizeof( struct V_141 ) ;
}
}
V_224 -> V_111 = F_68 ( V_4 ) ;
V_224 -> V_115 = F_68 ( F_69 ( log -> V_113 ,
V_224 , V_114 ) ) ;
F_154 ( log -> V_51 , V_214 -> V_226 , V_114 , V_146 ,
V_119 , V_229 | V_98 , false ) ;
V_33 -> V_16 = V_214 -> V_226 ;
F_82 ( & V_33 -> V_164 , & log -> V_166 ) ;
F_29 ( & log -> V_48 ) ;
V_214 -> V_226 = V_251 ;
V_214 -> V_132 += 1 ;
V_180 = V_33 -> V_16 ;
}
log -> V_180 = V_180 ;
F_155 ( V_146 ) ;
return 0 ;
}
static void F_177 ( struct V_6 * log ,
struct V_213 * V_214 )
{
struct V_31 * V_31 = log -> V_51 -> V_31 ;
struct V_1 * V_2 = V_31 -> V_52 ;
struct V_32 * V_33 , * V_69 ;
if ( V_214 -> V_250 == 0 )
return;
log -> V_7 = V_8 ;
F_35 (sh, next, &ctx->cached_list, lru) {
F_26 ( V_33 ) ;
F_14 ( V_71 , & V_33 -> V_20 ) ;
F_36 ( & V_33 -> V_190 ) ;
F_37 ( V_33 ) ;
}
F_51 ( V_2 -> V_31 -> V_88 ) ;
F_63 ( V_2 -> V_252 ,
F_18 ( & V_2 -> V_193 ) == 0 ) ;
log -> V_7 = V_67 ;
}
static int F_178 ( struct V_6 * log )
{
struct V_31 * V_31 = log -> V_51 -> V_31 ;
struct V_213 * V_214 ;
int V_155 ;
T_1 V_226 ;
V_214 = F_179 ( sizeof( * V_214 ) , V_216 ) ;
if ( ! V_214 )
return - V_136 ;
V_214 -> V_226 = log -> V_15 ;
V_214 -> V_132 = log -> V_253 ;
F_76 ( & V_214 -> V_249 ) ;
V_214 -> V_82 = F_143 ( V_216 ) ;
if ( ! V_214 -> V_82 ) {
V_155 = - V_136 ;
goto V_82;
}
if ( F_142 ( log , V_214 ) != 0 ) {
V_155 = - V_136 ;
goto V_220;
}
V_155 = F_175 ( log , V_214 ) ;
if ( V_155 )
goto error;
V_226 = V_214 -> V_226 ;
V_214 -> V_132 += 10000 ;
if ( ( V_214 -> V_250 == 0 ) && ( V_214 -> V_240 == 0 ) )
F_171 ( L_5 ,
F_62 ( V_31 ) ) ;
else
F_171 ( L_6 ,
F_62 ( V_31 ) , V_214 -> V_250 ,
V_214 -> V_240 ) ;
if ( V_214 -> V_250 == 0 ) {
log -> V_180 = V_214 -> V_226 ;
F_153 ( log , V_214 -> V_226 , V_214 -> V_132 ++ ) ;
V_214 -> V_226 = F_4 ( log , V_214 -> V_226 , V_46 ) ;
} else if ( F_176 ( log , V_214 ) ) {
F_173 ( L_7 ,
F_62 ( V_31 ) ) ;
V_155 = - V_230 ;
goto error;
}
log -> V_16 = V_214 -> V_226 ;
log -> V_132 = V_214 -> V_132 ;
log -> V_15 = V_226 ;
F_118 ( log , V_226 ) ;
F_177 ( log , V_214 ) ;
V_155 = 0 ;
error:
F_144 ( log , V_214 ) ;
V_220:
F_155 ( V_214 -> V_82 ) ;
V_82:
F_180 ( V_214 ) ;
return V_155 ;
}
static void F_118 ( struct V_6 * log , T_1 V_254 )
{
struct V_31 * V_31 = log -> V_51 -> V_31 ;
log -> V_51 -> V_255 = V_254 ;
F_14 ( V_189 , & V_31 -> V_105 ) ;
}
static T_5 F_181 ( struct V_31 * V_31 , char * V_146 )
{
struct V_1 * V_2 = V_31 -> V_52 ;
int V_155 ;
if ( ! V_2 -> log )
return 0 ;
switch ( V_2 -> log -> V_7 ) {
case V_67 :
V_155 = snprintf (
V_146 , V_114 , L_8 ,
V_256 [ V_67 ] ,
V_256 [ V_8 ] ) ;
break;
case V_8 :
V_155 = snprintf (
V_146 , V_114 , L_9 ,
V_256 [ V_67 ] ,
V_256 [ V_8 ] ) ;
break;
default:
V_155 = 0 ;
}
return V_155 ;
}
int F_182 ( struct V_31 * V_31 , int V_257 )
{
struct V_1 * V_2 ;
int V_258 ;
if ( V_257 < V_67 ||
V_257 > V_8 )
return - V_227 ;
V_258 = F_183 ( V_31 ) ;
if ( V_258 )
return V_258 ;
V_2 = V_31 -> V_52 ;
if ( ! V_2 || ! V_2 -> log ) {
F_125 ( V_31 ) ;
return - V_177 ;
}
if ( F_184 ( V_2 ) > 0 &&
V_257 == V_8 ) {
F_125 ( V_31 ) ;
return - V_227 ;
}
F_64 ( V_31 ) ;
V_2 -> log -> V_7 = V_257 ;
F_65 ( V_31 ) ;
F_125 ( V_31 ) ;
F_171 ( L_10 ,
F_62 ( V_31 ) , V_257 , V_256 [ V_257 ] ) ;
return 0 ;
}
static T_5 F_185 ( struct V_31 * V_31 ,
const char * V_146 , T_6 V_259 )
{
int V_257 = F_186 ( V_256 ) ;
T_6 V_260 = V_259 ;
if ( V_260 < 2 )
return - V_227 ;
if ( V_146 [ V_260 - 1 ] == '\n' )
V_260 -- ;
while ( V_257 -- )
if ( strlen ( V_256 [ V_257 ] ) == V_260 &&
! strncmp ( V_146 , V_256 [ V_257 ] , V_260 ) )
break;
return F_182 ( V_31 , V_257 ) ? : V_259 ;
}
int F_187 ( struct V_1 * V_2 ,
struct V_32 * V_33 ,
struct V_261 * V_262 ,
int V_34 )
{
struct V_6 * log = V_2 -> log ;
int V_35 ;
struct V_21 * V_22 ;
int V_263 = 0 ;
void * * V_264 ;
T_1 V_265 ;
int V_155 ;
T_7 V_266 ;
F_27 ( ! F_3 ( log ) ) ;
if ( ! F_16 ( V_60 , & V_33 -> V_20 ) ) {
if ( V_262 -> V_267 > 0 || V_262 -> V_26 > 0 )
return - V_171 ;
F_14 ( V_60 , & V_33 -> V_20 ) ;
}
if ( V_262 -> V_268 || F_16 ( V_172 , & V_33 -> V_20 ) ) {
F_26 ( V_33 ) ;
return - V_171 ;
}
for ( V_35 = V_34 ; V_35 -- ; ) {
V_22 = & V_33 -> V_22 [ V_35 ] ;
if ( V_22 -> V_269 && ! F_16 ( V_270 , & V_22 -> V_37 ) &&
! F_16 ( V_64 , & V_22 -> V_37 ) ) {
F_26 ( V_33 ) ;
return - V_171 ;
}
}
if ( ! F_16 ( V_194 , & V_33 -> V_20 ) &&
! F_16 ( V_271 , & V_33 -> V_20 ) ) {
V_265 = F_1 ( V_2 , V_33 -> V_29 ) ;
F_96 ( & log -> V_272 ) ;
V_264 = F_188 ( & log -> V_273 ,
V_265 ) ;
if ( V_264 ) {
V_266 = ( T_7 ) F_189 (
V_264 , & log -> V_272 ) >>
V_274 ;
F_190 (
& log -> V_273 , V_264 ,
( void * ) ( ( V_266 + 1 ) << V_274 ) ) ;
} else {
V_155 = F_191 (
& log -> V_273 , V_265 ,
( void * ) ( 1 << V_274 ) ) ;
if ( V_155 ) {
F_97 ( & log -> V_272 ) ;
F_26 ( V_33 ) ;
return - V_171 ;
}
}
F_97 ( & log -> V_272 ) ;
F_14 ( V_194 , & V_33 -> V_20 ) ;
F_29 ( & V_2 -> V_41 ) ;
}
for ( V_35 = V_34 ; V_35 -- ; ) {
V_22 = & V_33 -> V_22 [ V_35 ] ;
if ( V_22 -> V_269 ) {
F_14 ( V_63 , & V_22 -> V_37 ) ;
F_14 ( V_275 , & V_22 -> V_37 ) ;
F_14 ( V_65 , & V_22 -> V_37 ) ;
V_263 ++ ;
}
}
if ( V_263 ) {
F_14 ( V_276 , & V_262 -> V_277 ) ;
F_14 ( V_66 , & V_33 -> V_20 ) ;
}
return 0 ;
}
void F_192 ( struct V_32 * V_33 )
{
struct V_1 * V_2 = V_33 -> V_59 ;
int V_35 ;
bool V_278 ;
V_278 =
V_33 -> V_22 [ 0 ] . V_279 == V_2 -> V_34 [ 0 ] . V_280 ;
for ( V_35 = V_33 -> V_34 ; V_35 -- ; )
if ( V_33 -> V_22 [ V_35 ] . V_146 != V_33 -> V_22 [ V_35 ] . V_279 ) {
struct V_146 * V_281 = V_33 -> V_22 [ V_35 ] . V_279 ;
V_33 -> V_22 [ V_35 ] . V_279 = V_33 -> V_22 [ V_35 ] . V_146 ;
F_25 ( V_282 , & V_33 -> V_22 [ V_35 ] . V_37 ) ;
if ( ! V_278 )
F_145 ( V_281 ) ;
}
if ( V_278 ) {
F_25 ( V_283 , & V_2 -> V_57 ) ;
F_51 ( V_2 -> V_31 -> V_88 ) ;
}
}
void F_193 ( struct V_32 * V_33 )
{
struct V_1 * V_2 = V_33 -> V_59 ;
int V_35 ;
struct V_21 * V_22 ;
for ( V_35 = V_33 -> V_34 ; V_35 -- ; ) {
V_22 = & V_33 -> V_22 [ V_35 ] ;
if ( V_22 -> V_279 != V_22 -> V_146 )
F_145 ( V_22 -> V_279 ) ;
V_22 -> V_279 = V_2 -> V_34 [ V_35 ] . V_280 ;
}
}
void F_194 ( struct V_1 * V_2 ,
struct V_32 * V_33 ,
struct V_261 * V_262 )
{
struct V_6 * log = V_2 -> log ;
int V_35 ;
int V_284 = 0 ;
T_1 V_265 ;
void * * V_264 ;
T_7 V_266 ;
if ( ! log || ! F_16 ( V_64 , & V_33 -> V_22 [ V_33 -> V_68 ] . V_37 ) )
return;
F_8 ( F_16 ( V_60 , & V_33 -> V_20 ) ) ;
F_25 ( V_64 , & V_33 -> V_22 [ V_33 -> V_68 ] . V_37 ) ;
if ( log -> V_7 == V_67 )
return;
for ( V_35 = V_33 -> V_34 ; V_35 -- ; ) {
F_25 ( V_64 , & V_33 -> V_22 [ V_35 ] . V_37 ) ;
if ( F_31 ( V_285 , & V_33 -> V_22 [ V_35 ] . V_37 ) )
V_284 = 1 ;
}
V_262 -> V_267 = 0 ;
if ( F_31 ( V_286 , & V_33 -> V_20 ) )
if ( F_54 ( & V_2 -> V_287 ) )
F_51 ( V_2 -> V_31 -> V_88 ) ;
if ( V_284 )
F_110 ( & V_2 -> V_288 ) ;
F_81 ( & log -> V_165 ) ;
F_36 ( & V_33 -> V_164 ) ;
F_83 ( & log -> V_165 ) ;
V_33 -> V_16 = V_163 ;
F_195 ( & log -> V_48 ) ;
F_24 ( log ) ;
if ( F_16 ( V_194 , & V_33 -> V_20 ) ||
F_16 ( V_271 , & V_33 -> V_20 ) ) {
V_265 = F_1 ( V_2 , V_33 -> V_29 ) ;
F_96 ( & log -> V_272 ) ;
V_264 = F_188 ( & log -> V_273 ,
V_265 ) ;
F_27 ( V_264 == NULL ) ;
V_266 = ( T_7 ) F_189 (
V_264 , & log -> V_272 ) >>
V_274 ;
if ( V_266 == 1 )
F_196 ( & log -> V_273 , V_265 ) ;
else
F_190 (
& log -> V_273 , V_264 ,
( void * ) ( ( V_266 - 1 ) << V_274 ) ) ;
F_97 ( & log -> V_272 ) ;
}
if ( F_31 ( V_194 , & V_33 -> V_20 ) ) {
F_27 ( F_18 ( & V_2 -> V_41 ) == 0 ) ;
F_195 ( & V_2 -> V_195 ) ;
F_195 ( & V_2 -> V_41 ) ;
}
if ( F_31 ( V_271 , & V_33 -> V_20 ) ) {
F_27 ( F_18 ( & V_2 -> V_42 ) == 0 ) ;
F_195 ( & V_2 -> V_196 ) ;
F_195 ( & V_2 -> V_42 ) ;
}
F_90 ( log , V_33 -> V_29 ) ;
if ( F_16 ( V_289 , & V_33 -> V_20 ) )
F_14 ( V_71 , & V_33 -> V_20 ) ;
}
int F_197 ( struct V_6 * log , struct V_32 * V_33 )
{
struct V_1 * V_2 = V_33 -> V_59 ;
int V_290 = 0 ;
int V_170 ;
int V_35 ;
int V_155 = 0 ;
F_27 ( ! log ) ;
for ( V_35 = 0 ; V_35 < V_33 -> V_34 ; V_35 ++ ) {
void * V_173 ;
if ( ! F_16 ( V_63 , & V_33 -> V_22 [ V_35 ] . V_37 ) )
continue;
V_173 = F_99 ( V_33 -> V_22 [ V_35 ] . V_146 ) ;
V_33 -> V_22 [ V_35 ] . V_160 = F_69 ( log -> V_113 ,
V_173 , V_114 ) ;
F_100 ( V_173 ) ;
V_290 ++ ;
}
F_8 ( V_290 == 0 ) ;
F_25 ( V_174 , & V_33 -> V_20 ) ;
F_29 ( & V_33 -> V_175 ) ;
F_91 ( & log -> V_149 ) ;
V_170 = ( 1 + V_290 ) << ( V_144 - 9 ) ;
if ( F_16 ( V_56 , & V_2 -> V_57 ) &&
V_33 -> V_16 == V_163 )
F_95 ( log , V_33 ) ;
else if ( ! F_6 ( log , V_170 ) ) {
if ( V_33 -> V_16 == log -> V_15 )
F_89 () ;
else
F_95 ( log , V_33 ) ;
} else {
V_155 = F_93 ( log , V_33 , V_290 , 0 ) ;
if ( V_155 ) {
F_81 ( & log -> V_72 ) ;
F_82 ( & V_33 -> V_70 , & log -> V_176 ) ;
F_83 ( & log -> V_72 ) ;
}
}
F_92 ( & log -> V_149 ) ;
return 0 ;
}
bool F_198 ( struct V_1 * V_2 , T_1 V_3 )
{
struct V_6 * log = V_2 -> log ;
T_1 V_265 ;
void * V_291 ;
if ( ! log )
return false ;
F_199 ( ! F_200 () ) ;
V_265 = F_1 ( V_2 , V_3 ) ;
V_291 = F_201 ( & log -> V_273 , V_265 ) ;
return V_291 != NULL ;
}
static int F_202 ( struct V_6 * log )
{
struct V_233 * V_51 = log -> V_51 ;
struct V_146 * V_146 ;
struct V_107 * V_224 ;
T_1 V_254 = log -> V_51 -> V_255 ;
T_2 V_225 , V_292 ;
bool V_293 = false ;
int V_155 = 0 ;
if ( V_254 >= V_51 -> V_294 || F_203 ( V_254 , V_46 ) != V_254 )
V_254 = 0 ;
V_146 = F_143 ( V_216 ) ;
if ( ! V_146 )
return - V_136 ;
if ( ! F_154 ( V_51 , V_254 , V_114 , V_146 , V_222 , 0 , false ) ) {
V_155 = - V_230 ;
goto V_295;
}
V_224 = F_67 ( V_146 ) ;
if ( F_150 ( V_224 -> V_128 ) != V_129 ||
V_224 -> V_130 != V_131 ) {
V_293 = true ;
goto V_296;
}
V_225 = F_150 ( V_224 -> V_115 ) ;
V_224 -> V_115 = 0 ;
V_292 = F_69 ( log -> V_113 , V_224 , V_114 ) ;
if ( V_225 != V_292 ) {
V_293 = true ;
goto V_296;
}
if ( F_151 ( V_224 -> V_133 ) != V_254 ) {
V_293 = true ;
goto V_296;
}
V_296:
if ( V_293 ) {
log -> V_253 = F_204 () ;
V_254 = 0 ;
F_153 ( log , V_254 , log -> V_253 ) ;
F_118 ( log , V_254 ) ;
} else
log -> V_253 = F_151 ( V_224 -> V_132 ) ;
log -> V_11 = F_203 ( V_51 -> V_294 , V_46 ) ;
log -> V_183 = log -> V_11 >> V_297 ;
if ( log -> V_183 > V_298 )
log -> V_183 = V_298 ;
log -> V_15 = V_254 ;
F_155 ( V_146 ) ;
if ( V_293 ) {
log -> V_16 = F_4 ( log , V_254 , V_46 ) ;
log -> V_132 = log -> V_253 + 1 ;
log -> V_180 = V_254 ;
} else
V_155 = F_178 ( log ) ;
F_24 ( log ) ;
return V_155 ;
V_295:
F_155 ( V_146 ) ;
return V_155 ;
}
void F_205 ( struct V_31 * V_31 , struct V_233 * V_51 )
{
struct V_1 * V_2 = V_31 -> V_52 ;
struct V_6 * log = V_2 -> log ;
if ( ! log )
return;
if ( ( F_184 ( V_2 ) > 0 ||
F_16 ( V_299 , & V_51 -> V_37 ) ) &&
V_2 -> log -> V_7 == V_8 )
F_49 ( & log -> V_102 ) ;
}
int F_206 ( struct V_1 * V_2 , struct V_233 * V_51 )
{
struct V_300 * V_301 = F_120 ( V_51 -> V_121 ) ;
struct V_6 * log ;
char V_302 [ V_303 ] ;
F_171 ( L_11 ,
F_62 ( V_2 -> V_31 ) , F_207 ( V_51 -> V_121 , V_302 ) ) ;
if ( V_114 != 4096 )
return - V_227 ;
if ( sizeof( struct V_107 ) +
( ( sizeof( struct V_141 ) + sizeof( V_145 ) ) *
V_2 -> V_49 ) > V_114 ) {
F_173 ( L_12 ,
F_62 ( V_2 -> V_31 ) , V_2 -> V_49 ) ;
return - V_227 ;
}
log = F_179 ( sizeof( * log ) , V_216 ) ;
if ( ! log )
return - V_136 ;
log -> V_51 = V_51 ;
log -> V_84 = F_16 ( V_304 , & V_301 -> V_305 ) != 0 ;
log -> V_113 = F_69 ( ~ 0 , V_51 -> V_31 -> V_306 ,
sizeof( V_51 -> V_31 -> V_306 ) ) ;
F_208 ( & log -> V_149 ) ;
F_209 ( & log -> V_72 ) ;
F_76 ( & log -> V_86 ) ;
F_76 ( & log -> V_76 ) ;
F_76 ( & log -> V_186 ) ;
F_76 ( & log -> V_75 ) ;
F_210 ( & log -> V_185 , NULL , 0 ) ;
log -> V_307 = F_211 ( V_17 , 0 ) ;
if ( ! log -> V_307 )
goto V_307;
log -> V_125 = F_212 ( V_308 , log -> V_307 ) ;
if ( ! log -> V_125 )
goto V_125;
log -> V_118 = F_213 ( V_308 , 0 , V_309 ) ;
if ( ! log -> V_118 )
goto V_310;
log -> V_83 = F_214 ( V_308 , 0 ) ;
if ( ! log -> V_83 )
goto V_311;
F_209 ( & log -> V_272 ) ;
F_215 ( & log -> V_273 , V_312 | V_313 ) ;
log -> V_209 = F_216 ( F_133 ,
log -> V_51 -> V_31 , L_13 ) ;
if ( ! log -> V_209 )
goto V_209;
log -> V_209 -> V_314 = V_315 ;
F_217 ( & log -> V_184 ) ;
F_76 ( & log -> V_176 ) ;
F_76 ( & log -> V_168 ) ;
F_209 ( & log -> V_167 ) ;
F_218 ( & log -> V_87 , F_58 ) ;
F_218 ( & log -> V_102 , F_60 ) ;
log -> V_7 = V_67 ;
F_76 ( & log -> V_166 ) ;
F_209 ( & log -> V_165 ) ;
F_219 ( & log -> V_48 , 0 ) ;
F_220 ( V_2 -> log , log ) ;
if ( F_202 ( log ) )
goto error;
F_14 ( V_211 , & V_2 -> V_31 -> V_37 ) ;
return 0 ;
error:
F_220 ( V_2 -> log , NULL ) ;
F_221 ( & log -> V_209 ) ;
V_209:
F_222 ( log -> V_83 ) ;
V_311:
F_223 ( log -> V_118 ) ;
V_310:
F_222 ( log -> V_125 ) ;
V_125:
F_224 ( log -> V_307 ) ;
V_307:
F_180 ( log ) ;
return - V_227 ;
}
void F_225 ( struct V_1 * V_2 )
{
struct V_6 * log = V_2 -> log ;
V_2 -> log = NULL ;
F_226 () ;
F_227 ( & log -> V_102 ) ;
F_221 ( & log -> V_209 ) ;
F_222 ( log -> V_83 ) ;
F_223 ( log -> V_118 ) ;
F_222 ( log -> V_125 ) ;
F_224 ( log -> V_307 ) ;
F_180 ( log ) ;
}
