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
F_73 ( V_23 , log -> V_51 -> V_120 ) ;
V_23 -> V_27 . V_28 = log -> V_51 -> V_121 + log -> V_16 ;
return V_23 ;
}
static void F_74 ( struct V_6 * log , struct V_17 * V_18 )
{
log -> V_16 = F_4 ( log , log -> V_16 , V_46 ) ;
F_24 ( log ) ;
if ( log -> V_16 == 0 )
V_18 -> V_122 = true ;
V_18 -> V_123 = log -> V_16 ;
}
static struct V_17 * F_75 ( struct V_6 * log )
{
struct V_17 * V_18 ;
struct V_107 * V_108 ;
V_18 = F_76 ( log -> V_124 , V_125 ) ;
if ( ! V_18 )
return NULL ;
memset ( V_18 , 0 , sizeof( * V_18 ) ) ;
V_18 -> log = log ;
F_77 ( & V_18 -> V_74 ) ;
F_77 ( & V_18 -> V_85 ) ;
F_78 ( & V_18 -> V_90 ) ;
V_18 -> V_20 = V_126 ;
V_18 -> V_82 = F_76 ( log -> V_83 , V_116 ) ;
V_108 = F_67 ( V_18 -> V_82 ) ;
F_79 ( V_108 ) ;
V_108 -> V_127 = F_68 ( V_128 ) ;
V_108 -> V_129 = V_130 ;
V_108 -> V_131 = F_80 ( log -> V_131 ) ;
V_108 -> V_132 = F_80 ( log -> V_16 ) ;
V_18 -> V_16 = log -> V_16 ;
V_18 -> V_112 = sizeof( struct V_107 ) ;
V_18 -> V_131 = log -> V_131 ++ ;
V_18 -> V_99 = F_70 ( log ) ;
V_18 -> V_99 -> V_133 = F_42 ;
V_18 -> V_99 -> V_77 = V_18 ;
F_81 ( V_18 -> V_99 , V_18 -> V_82 , V_114 , 0 ) ;
F_74 ( log , V_18 ) ;
F_82 ( & log -> V_72 ) ;
F_83 ( & V_18 -> V_74 , & log -> V_86 ) ;
F_84 ( & log -> V_72 ) ;
return V_18 ;
}
static int F_85 ( struct V_6 * log , unsigned int V_134 )
{
if ( log -> V_106 &&
log -> V_106 -> V_112 + V_134 > V_114 )
F_66 ( log ) ;
if ( ! log -> V_106 ) {
log -> V_106 = F_75 ( log ) ;
if ( ! log -> V_106 )
return - V_135 ;
}
return 0 ;
}
static void F_86 ( struct V_6 * log , T_3 type ,
T_1 V_136 ,
T_2 V_137 , T_2 V_138 ,
bool V_139 )
{
struct V_17 * V_18 = log -> V_106 ;
struct V_140 * V_141 ;
V_141 = F_67 ( V_18 -> V_82 ) + V_18 -> V_112 ;
V_141 -> V_142 . type = F_87 ( type ) ;
V_141 -> V_142 . V_37 = F_87 ( 0 ) ;
V_141 -> V_13 = F_68 ( ( 1 + ! ! V_139 ) <<
( V_143 - 9 ) ) ;
V_141 -> V_136 = F_80 ( V_136 ) ;
V_141 -> V_115 [ 0 ] = F_68 ( V_137 ) ;
if ( V_139 )
V_141 -> V_115 [ 1 ] = F_68 ( V_138 ) ;
V_18 -> V_112 += sizeof( struct V_140 ) +
sizeof( V_144 ) * ( 1 + ! ! V_139 ) ;
}
static void F_88 ( struct V_6 * log , struct V_145 * V_145 )
{
struct V_17 * V_18 = log -> V_106 ;
if ( V_18 -> V_122 ) {
F_27 ( V_18 -> V_93 ) ;
V_18 -> V_93 = V_18 -> V_99 ;
V_18 -> V_99 = F_70 ( log ) ;
F_89 ( V_18 -> V_99 , V_18 -> V_93 ) ;
V_18 -> V_122 = false ;
}
if ( ! F_81 ( V_18 -> V_99 , V_145 , V_114 , 0 ) )
F_90 () ;
F_74 ( log , V_18 ) ;
}
static void F_91 ( struct V_6 * log , T_1 V_3 )
{
struct V_31 * V_31 = log -> V_51 -> V_31 ;
struct V_1 * V_2 = V_31 -> V_52 ;
struct V_17 * V_18 ;
struct V_146 * V_141 ;
int V_111 ;
if ( V_2 -> V_147 )
return;
F_92 ( & log -> V_148 ) ;
V_111 = sizeof( struct V_146 ) + sizeof( V_149 ) ;
if ( F_85 ( log , V_111 ) ) {
F_93 ( & log -> V_148 ) ;
return;
}
V_18 = log -> V_106 ;
V_141 = F_67 ( V_18 -> V_82 ) + V_18 -> V_112 ;
V_141 -> V_142 . type = F_87 ( V_150 ) ;
V_141 -> V_142 . V_37 = F_87 ( 0 ) ;
V_141 -> V_13 = F_68 ( sizeof( V_149 ) ) ;
V_141 -> V_151 [ 0 ] = F_80 ( V_3 ) ;
V_18 -> V_112 += V_111 ;
if ( ! V_18 -> V_80 ) {
V_18 -> V_80 = 1 ;
F_29 ( & V_18 -> V_91 ) ;
}
F_93 ( & log -> V_148 ) ;
}
static int F_94 ( struct V_6 * log , struct V_32 * V_33 ,
int V_152 , int V_153 )
{
int V_35 ;
int V_111 ;
int V_154 ;
struct V_17 * V_18 ;
V_111 =
( ( sizeof( struct V_140 ) + sizeof( V_144 ) )
* V_152 ) +
sizeof( struct V_140 ) +
sizeof( V_144 ) * V_153 ;
V_154 = F_85 ( log , V_111 ) ;
if ( V_154 )
return V_154 ;
V_18 = log -> V_106 ;
if ( F_31 ( V_155 , & V_33 -> V_20 ) )
V_18 -> V_94 = 1 ;
for ( V_35 = 0 ; V_35 < V_33 -> V_34 ; V_35 ++ ) {
if ( ! F_16 ( V_63 , & V_33 -> V_22 [ V_35 ] . V_37 ) ||
F_16 ( V_64 , & V_33 -> V_22 [ V_35 ] . V_37 ) )
continue;
if ( V_35 == V_33 -> V_68 || V_35 == V_33 -> V_156 )
continue;
if ( F_16 ( V_157 , & V_33 -> V_22 [ V_35 ] . V_37 ) &&
log -> V_7 == V_8 ) {
V_18 -> V_97 = 1 ;
V_18 -> V_94 = 1 ;
}
F_86 ( log , V_158 ,
F_95 ( V_33 , V_35 , 0 ) ,
V_33 -> V_22 [ V_35 ] . V_159 , 0 , false ) ;
F_88 ( log , V_33 -> V_22 [ V_35 ] . V_145 ) ;
}
if ( V_153 == 2 ) {
F_86 ( log , V_160 ,
V_33 -> V_29 , V_33 -> V_22 [ V_33 -> V_68 ] . V_159 ,
V_33 -> V_22 [ V_33 -> V_156 ] . V_159 , true ) ;
F_88 ( log , V_33 -> V_22 [ V_33 -> V_68 ] . V_145 ) ;
F_88 ( log , V_33 -> V_22 [ V_33 -> V_156 ] . V_145 ) ;
} else if ( V_153 == 1 ) {
F_86 ( log , V_160 ,
V_33 -> V_29 , V_33 -> V_22 [ V_33 -> V_68 ] . V_159 ,
0 , false ) ;
F_88 ( log , V_33 -> V_22 [ V_33 -> V_68 ] . V_145 ) ;
} else
F_27 ( V_153 != 0 ) ;
F_83 ( & V_33 -> V_70 , & V_18 -> V_85 ) ;
F_29 ( & V_18 -> V_91 ) ;
V_33 -> V_161 = V_18 ;
if ( log -> V_7 == V_67 )
return 0 ;
if ( V_33 -> V_16 == V_162 ) {
F_27 ( ! F_47 ( & V_33 -> V_163 ) ) ;
V_33 -> V_16 = V_18 -> V_16 ;
F_82 ( & log -> V_164 ) ;
F_83 ( & V_33 -> V_163 ,
& log -> V_165 ) ;
F_84 ( & log -> V_164 ) ;
F_29 ( & log -> V_48 ) ;
}
return 0 ;
}
static inline void F_96 ( struct V_6 * log ,
struct V_32 * V_33 )
{
F_97 ( & log -> V_166 ) ;
F_83 ( & V_33 -> V_70 , & log -> V_167 ) ;
F_98 ( & log -> V_166 ) ;
}
int F_99 ( struct V_6 * log , struct V_32 * V_33 )
{
struct V_1 * V_2 = V_33 -> V_59 ;
int V_168 = 0 ;
int V_152 , V_153 ;
int V_169 ;
int V_35 ;
int V_154 = 0 ;
bool V_55 = false ;
if ( ! log )
return - V_170 ;
if ( V_33 -> V_161 || ! F_16 ( V_63 , & V_33 -> V_22 [ V_33 -> V_68 ] . V_37 ) ||
F_16 ( V_171 , & V_33 -> V_20 ) ) {
F_25 ( V_66 , & V_33 -> V_20 ) ;
return - V_170 ;
}
F_8 ( F_16 ( V_60 , & V_33 -> V_20 ) ) ;
for ( V_35 = 0 ; V_35 < V_33 -> V_34 ; V_35 ++ ) {
void * V_172 ;
if ( ! F_16 ( V_63 , & V_33 -> V_22 [ V_35 ] . V_37 ) ||
F_16 ( V_64 , & V_33 -> V_22 [ V_35 ] . V_37 ) )
continue;
V_168 ++ ;
if ( F_16 ( V_66 , & V_33 -> V_20 ) )
continue;
V_172 = F_100 ( V_33 -> V_22 [ V_35 ] . V_145 ) ;
V_33 -> V_22 [ V_35 ] . V_159 = F_69 ( log -> V_113 ,
V_172 , V_114 ) ;
F_101 ( V_172 ) ;
}
V_153 = 1 + ! ! ( V_33 -> V_156 >= 0 ) ;
V_152 = V_168 - V_153 ;
F_14 ( V_66 , & V_33 -> V_20 ) ;
F_25 ( V_173 , & V_33 -> V_20 ) ;
F_29 ( & V_33 -> V_174 ) ;
F_92 ( & log -> V_148 ) ;
V_169 = ( 1 + V_168 ) << ( V_143 - 9 ) ;
if ( log -> V_7 == V_67 ) {
if ( ! F_6 ( log , V_169 ) ) {
F_96 ( log , V_33 ) ;
V_55 = true ;
} else {
V_154 = F_94 ( log , V_33 , V_152 , V_153 ) ;
if ( V_154 ) {
F_82 ( & log -> V_72 ) ;
F_83 ( & V_33 -> V_70 ,
& log -> V_175 ) ;
F_84 ( & log -> V_72 ) ;
}
}
} else {
if ( F_16 ( V_56 , & V_2 -> V_57 ) &&
V_33 -> V_16 == V_162 ) {
F_96 ( log , V_33 ) ;
V_55 = true ;
V_169 = 0 ;
} else if ( ! F_6 ( log , V_169 ) ) {
if ( V_33 -> V_16 == log -> V_15 )
F_90 () ;
else
F_96 ( log , V_33 ) ;
} else {
V_154 = F_94 ( log , V_33 , V_152 , V_153 ) ;
if ( V_154 ) {
F_82 ( & log -> V_72 ) ;
F_83 ( & V_33 -> V_70 ,
& log -> V_175 ) ;
F_84 ( & log -> V_72 ) ;
}
}
}
F_93 ( & log -> V_148 ) ;
if ( V_55 )
F_19 ( log , V_169 ) ;
return 0 ;
}
void F_102 ( struct V_6 * log )
{
if ( ! log )
return;
F_92 ( & log -> V_148 ) ;
F_66 ( log ) ;
F_93 ( & log -> V_148 ) ;
}
int F_103 ( struct V_6 * log , struct V_23 * V_23 )
{
if ( ! log )
return - V_176 ;
if ( log -> V_7 == V_67 ) {
if ( V_23 -> V_27 . V_177 == 0 ) {
F_12 ( V_23 ) ;
return 0 ;
}
V_23 -> V_95 &= ~ V_96 ;
} else {
if ( V_23 -> V_27 . V_177 == 0 ) {
F_92 ( & log -> V_148 ) ;
F_85 ( log , 0 ) ;
F_104 ( & log -> V_106 -> V_90 , V_23 ) ;
log -> V_106 -> V_94 = 1 ;
log -> V_106 -> V_79 = 1 ;
F_29 ( & log -> V_106 -> V_91 ) ;
F_66 ( log ) ;
F_93 ( & log -> V_148 ) ;
return 0 ;
}
}
return - V_170 ;
}
static void F_105 ( struct V_6 * log )
{
struct V_32 * V_33 ;
F_97 ( & log -> V_166 ) ;
while ( ! F_47 ( & log -> V_167 ) ) {
V_33 = F_48 ( & log -> V_167 ,
struct V_32 , V_70 ) ;
F_36 ( & V_33 -> V_70 ) ;
F_14 ( V_71 , & V_33 -> V_20 ) ;
F_37 ( V_33 ) ;
}
F_98 ( & log -> V_166 ) ;
}
static T_1 F_106 ( struct V_1 * V_2 )
{
struct V_32 * V_33 ;
struct V_6 * log = V_2 -> log ;
T_1 V_178 ;
unsigned long V_37 ;
if ( log -> V_7 == V_67 )
return log -> V_179 ;
F_46 ( & log -> V_164 , V_37 ) ;
if ( F_47 ( & V_2 -> log -> V_165 ) ) {
F_50 ( & log -> V_164 , V_37 ) ;
return log -> V_179 ;
}
V_33 = F_48 ( & V_2 -> log -> V_165 ,
struct V_32 , V_163 ) ;
V_178 = V_33 -> V_16 ;
F_50 ( & log -> V_164 , V_37 ) ;
return V_178 ;
}
static T_1 F_107 ( struct V_6 * log )
{
struct V_1 * V_2 = log -> V_51 -> V_31 -> V_52 ;
return F_5 ( log , log -> V_15 ,
F_106 ( V_2 ) ) ;
}
static void F_108 ( struct V_6 * log )
{
struct V_32 * V_33 ;
F_39 ( & log -> V_72 ) ;
if ( ! F_47 ( & log -> V_175 ) ) {
V_33 = F_48 ( & log -> V_175 ,
struct V_32 , V_70 ) ;
F_36 ( & V_33 -> V_70 ) ;
F_14 ( V_71 , & V_33 -> V_20 ) ;
F_37 ( V_33 ) ;
}
}
static bool F_109 ( struct V_6 * log )
{
struct V_17 * V_18 , * V_69 ;
bool V_180 = false ;
F_39 ( & log -> V_72 ) ;
F_35 (io, next, &log->finished_ios, log_sibling) {
if ( V_18 -> V_20 < V_181 )
break;
log -> V_179 = V_18 -> V_16 ;
F_110 ( & V_18 -> V_74 ) ;
F_45 ( V_18 , log -> V_124 ) ;
F_108 ( log ) ;
V_180 = true ;
}
return V_180 ;
}
static void F_55 ( struct V_17 * V_18 )
{
struct V_6 * log = V_18 -> log ;
struct V_1 * V_2 = log -> V_51 -> V_31 -> V_52 ;
unsigned long V_37 ;
F_46 ( & log -> V_72 , V_37 ) ;
F_7 ( V_18 , V_181 ) ;
if ( ! F_109 ( log ) ) {
F_50 ( & log -> V_72 , V_37 ) ;
return;
}
if ( F_107 ( log ) > log -> V_182 ||
F_16 ( V_58 , & V_2 -> V_57 ) )
F_19 ( log , 0 ) ;
F_50 ( & log -> V_72 , V_37 ) ;
F_111 ( & log -> V_183 ) ;
}
void F_112 ( struct V_32 * V_33 )
{
struct V_17 * V_18 ;
V_18 = V_33 -> V_161 ;
V_33 -> V_161 = NULL ;
if ( V_18 && F_54 ( & V_18 -> V_91 ) )
F_55 ( V_18 ) ;
}
static void F_113 ( struct V_23 * V_23 )
{
struct V_6 * log = F_59 ( V_23 , struct V_6 ,
V_184 ) ;
unsigned long V_37 ;
struct V_17 * V_18 ;
if ( V_23 -> V_81 )
F_43 ( log -> V_51 -> V_31 , log -> V_51 ) ;
F_46 ( & log -> V_72 , V_37 ) ;
F_114 (io, &log->flushing_ios, log_sibling)
F_34 ( V_18 ) ;
F_115 ( & log -> V_185 , & log -> V_75 ) ;
F_50 ( & log -> V_72 , V_37 ) ;
}
void F_116 ( struct V_6 * log )
{
bool V_186 ;
if ( ! log || ! log -> V_84 )
return;
F_82 ( & log -> V_72 ) ;
if ( ! F_47 ( & log -> V_185 ) ) {
F_84 ( & log -> V_72 ) ;
return;
}
F_115 ( & log -> V_76 , & log -> V_185 ) ;
V_186 = ! F_47 ( & log -> V_185 ) ;
F_84 ( & log -> V_72 ) ;
if ( ! V_186 )
return;
F_117 ( & log -> V_184 ) ;
F_73 ( & log -> V_184 , log -> V_51 -> V_120 ) ;
log -> V_184 . V_133 = F_113 ;
log -> V_184 . V_95 = V_119 | V_96 ;
F_57 ( & log -> V_184 ) ;
}
static void F_118 ( struct V_6 * log ,
T_1 V_12 )
{
struct V_187 * V_120 = log -> V_51 -> V_120 ;
struct V_31 * V_31 ;
F_119 ( log , V_12 ) ;
if ( ! F_120 ( F_121 ( V_120 ) ) )
return;
V_31 = log -> V_51 -> V_31 ;
F_122 ( & V_31 -> V_105 , 0 ,
F_123 ( V_188 ) | F_123 ( V_104 ) ) ;
if ( ! F_124 ( V_31 ) )
return;
F_125 ( V_31 , 1 ) ;
F_126 ( V_31 ) ;
if ( log -> V_15 < V_12 ) {
F_127 ( V_120 ,
log -> V_15 + log -> V_51 -> V_121 ,
V_12 - log -> V_15 , V_116 , 0 ) ;
} else {
F_127 ( V_120 ,
log -> V_15 + log -> V_51 -> V_121 ,
log -> V_11 - log -> V_15 ,
V_116 , 0 ) ;
F_127 ( V_120 , log -> V_51 -> V_121 , V_12 ,
V_116 , 0 ) ;
}
}
static void F_128 ( struct V_1 * V_2 , struct V_32 * V_33 )
{
F_27 ( F_47 ( & V_33 -> V_189 ) ) ;
F_27 ( ! F_16 ( V_60 , & V_33 -> V_20 ) ) ;
F_27 ( F_16 ( V_71 , & V_33 -> V_20 ) ) ;
F_27 ( F_16 ( V_190 , & V_33 -> V_20 ) ) ;
F_39 ( & V_2 -> V_191 ) ;
F_36 ( & V_33 -> V_189 ) ;
F_29 ( & V_33 -> V_174 ) ;
F_14 ( V_71 , & V_33 -> V_20 ) ;
F_29 ( & V_2 -> V_192 ) ;
F_26 ( V_33 ) ;
if ( F_16 ( V_193 , & V_33 -> V_20 ) )
F_29 ( & V_2 -> V_194 ) ;
else
F_29 ( & V_2 -> V_195 ) ;
F_37 ( V_33 ) ;
}
void F_129 ( struct V_1 * V_2 , int V_196 )
{
int V_174 ;
struct V_32 * V_33 , * V_69 ;
F_39 ( & V_2 -> V_191 ) ;
if ( ! V_2 -> log )
return;
V_174 = 0 ;
F_35 (sh, next, &conf->r5c_full_stripe_list, lru) {
F_128 ( V_2 , V_33 ) ;
V_174 ++ ;
}
if ( V_174 >= V_196 )
return;
F_35 (sh, next,
&conf->r5c_partial_stripe_list, lru) {
F_128 ( V_2 , V_33 ) ;
if ( ++ V_174 >= V_196 )
break;
}
}
static void F_130 ( struct V_1 * V_2 )
{
struct V_6 * log = V_2 -> log ;
struct V_32 * V_33 ;
int V_174 = 0 ;
unsigned long V_37 ;
int V_40 ;
int V_197 ;
int V_198 , V_199 ;
if ( ! F_3 ( log ) )
return;
V_198 = F_18 ( & V_2 -> V_194 ) ;
V_199 = F_18 ( & V_2 -> V_195 ) ;
V_40 = F_18 ( & V_2 -> V_41 ) +
F_18 ( & V_2 -> V_42 ) -
V_199 - V_198 ;
if ( V_40 > V_2 -> V_43 * 3 / 4 ||
F_18 ( & V_2 -> V_44 ) > 0 )
V_197 = V_200 ;
else if ( V_40 > V_2 -> V_43 * 1 / 2 ||
F_18 ( & V_2 -> V_42 ) - V_199 >
F_22 ( V_2 ) )
V_197 = 0 ;
else
V_197 = - 1 ;
if ( V_197 >= 0 ) {
F_46 ( & V_2 -> V_191 , V_37 ) ;
F_129 ( V_2 , V_197 ) ;
F_50 ( & V_2 -> V_191 , V_37 ) ;
}
if ( F_16 ( V_58 , & V_2 -> V_57 ) ) {
F_46 ( & log -> V_164 , V_37 ) ;
F_97 ( & V_2 -> V_191 ) ;
F_114 (sh, &log->stripe_in_journal_list, r5c) {
if ( ! F_47 ( & V_33 -> V_189 ) &&
! F_16 ( V_71 , & V_33 -> V_20 ) &&
F_18 ( & V_33 -> V_174 ) == 0 ) {
F_128 ( V_2 , V_33 ) ;
if ( V_174 ++ >= V_200 )
break;
}
}
F_98 ( & V_2 -> V_191 ) ;
F_50 ( & log -> V_164 , V_37 ) ;
}
if ( ! F_16 ( V_56 , & V_2 -> V_57 ) )
F_105 ( log ) ;
F_51 ( V_2 -> V_31 -> V_88 ) ;
}
static void F_131 ( struct V_6 * log )
{
struct V_1 * V_2 = log -> V_51 -> V_31 -> V_52 ;
T_1 V_201 = F_132 ( & log -> V_201 , 0 ) ;
T_1 V_202 ;
T_1 V_179 ;
bool V_203 ;
F_82 ( & log -> V_72 ) ;
V_203 = F_107 ( log ) > log -> V_182 ||
V_201 != 0 || ! F_47 ( & log -> V_167 ) ;
while ( 1 ) {
V_202 = F_107 ( log ) ;
if ( V_202 >= V_201 ||
( F_47 ( & log -> V_86 ) &&
F_47 ( & log -> V_76 ) &&
F_47 ( & log -> V_185 ) &&
F_47 ( & log -> V_75 ) ) )
break;
F_51 ( log -> V_51 -> V_31 -> V_88 ) ;
F_133 ( log -> V_183 ,
F_107 ( log ) > V_202 ,
log -> V_72 ) ;
}
V_179 = F_106 ( V_2 ) ;
F_84 ( & log -> V_72 ) ;
if ( V_202 == 0 || ! V_203 )
return;
F_118 ( log , V_179 ) ;
F_92 ( & log -> V_148 ) ;
log -> V_15 = V_179 ;
F_24 ( log ) ;
F_93 ( & log -> V_148 ) ;
F_105 ( log ) ;
}
static void F_134 ( struct V_204 * V_88 )
{
struct V_31 * V_31 = V_88 -> V_31 ;
struct V_1 * V_2 = V_31 -> V_52 ;
struct V_6 * log = V_2 -> log ;
if ( ! log )
return;
F_130 ( V_2 ) ;
F_131 ( log ) ;
}
void F_19 ( struct V_6 * log , T_1 V_205 )
{
unsigned long V_206 ;
unsigned long V_207 = ( unsigned long ) V_205 ;
if ( ! log )
return;
do {
V_206 = log -> V_201 ;
if ( V_207 < V_206 )
return;
} while ( F_135 ( & log -> V_201 , V_206 , V_207 ) != V_206 );
F_51 ( log -> V_208 ) ;
}
void F_136 ( struct V_6 * log , int V_20 )
{
struct V_31 * V_31 ;
if ( ! log || V_20 == 2 )
return;
if ( V_20 == 0 )
F_137 ( log -> V_208 -> V_209 ) ;
else if ( V_20 == 1 ) {
V_31 = log -> V_51 -> V_31 ;
F_111 ( & V_31 -> V_103 ) ;
F_138 ( log -> V_208 -> V_209 ) ;
F_19 ( log , V_162 ) ;
F_131 ( log ) ;
}
}
bool F_139 ( struct V_1 * V_2 )
{
struct V_6 * log ;
bool V_154 ;
F_140 () ;
log = F_141 ( V_2 -> log ) ;
if ( ! log )
V_154 = F_16 ( V_210 , & V_2 -> V_31 -> V_37 ) ;
else
V_154 = F_16 ( V_211 , & log -> V_51 -> V_37 ) ;
F_142 () ;
return V_154 ;
}
static int F_143 ( struct V_6 * log ,
struct V_212 * V_213 )
{
struct V_145 * V_145 ;
V_213 -> V_214 = F_71 ( V_215 , V_117 , log -> V_118 ) ;
if ( ! V_213 -> V_214 )
return - V_135 ;
V_213 -> V_216 = 0 ;
V_213 -> V_217 = 0 ;
while ( V_213 -> V_217 < V_218 ) {
V_145 = F_144 ( V_215 ) ;
if ( ! V_145 )
break;
V_213 -> V_219 [ V_213 -> V_217 ] = V_145 ;
V_213 -> V_217 += 1 ;
}
if ( V_213 -> V_217 == 0 ) {
F_44 ( V_213 -> V_214 ) ;
return - V_135 ;
}
V_213 -> V_220 = 0 ;
return 0 ;
}
static void F_145 ( struct V_6 * log ,
struct V_212 * V_213 )
{
int V_35 ;
for ( V_35 = 0 ; V_35 < V_213 -> V_217 ; ++ V_35 )
F_146 ( V_213 -> V_219 [ V_35 ] ) ;
F_44 ( V_213 -> V_214 ) ;
}
static int F_147 ( struct V_6 * log ,
struct V_212 * V_213 ,
T_1 V_4 )
{
F_117 ( V_213 -> V_214 ) ;
F_73 ( V_213 -> V_214 , log -> V_51 -> V_120 ) ;
F_72 ( V_213 -> V_214 , V_221 , 0 ) ;
V_213 -> V_214 -> V_27 . V_28 = log -> V_51 -> V_121 + V_4 ;
V_213 -> V_216 = 0 ;
V_213 -> V_220 = V_4 ;
while ( V_213 -> V_216 < V_213 -> V_217 ) {
F_81 ( V_213 -> V_214 ,
V_213 -> V_219 [ V_213 -> V_216 ] , V_114 , 0 ) ;
V_213 -> V_216 += 1 ;
V_4 = F_4 ( log , V_4 , V_46 ) ;
if ( V_4 == 0 )
break;
}
return F_148 ( V_213 -> V_214 ) ;
}
static int F_149 ( struct V_6 * log ,
struct V_212 * V_213 ,
struct V_145 * V_145 ,
T_1 V_4 )
{
int V_154 ;
if ( V_4 < V_213 -> V_220 ||
V_4 >= V_213 -> V_220 + V_213 -> V_216 * V_46 ) {
V_154 = F_147 ( log , V_213 , V_4 ) ;
if ( V_154 )
return V_154 ;
}
F_27 ( V_4 < V_213 -> V_220 ||
V_4 >= V_213 -> V_220 + V_213 -> V_216 * V_46 ) ;
memcpy ( F_67 ( V_145 ) ,
F_67 ( V_213 -> V_219 [ ( V_4 - V_213 -> V_220 ) >>
V_222 ] ) ,
V_114 ) ;
return 0 ;
}
static int F_150 ( struct V_6 * log ,
struct V_212 * V_213 )
{
struct V_145 * V_145 = V_213 -> V_82 ;
struct V_107 * V_223 ;
T_2 V_109 , V_224 ;
int V_154 ;
V_154 = F_149 ( log , V_213 , V_145 , V_213 -> V_225 ) ;
if ( V_154 != 0 )
return V_154 ;
V_223 = F_67 ( V_145 ) ;
V_224 = F_151 ( V_223 -> V_115 ) ;
V_223 -> V_115 = 0 ;
if ( F_151 ( V_223 -> V_127 ) != V_128 ||
F_152 ( V_223 -> V_131 ) != V_213 -> V_131 ||
V_223 -> V_129 != V_130 ||
F_152 ( V_223 -> V_132 ) != V_213 -> V_225 )
return - V_226 ;
V_109 = F_69 ( log -> V_113 , V_223 , V_114 ) ;
if ( V_224 != V_109 )
return - V_226 ;
if ( F_151 ( V_223 -> V_111 ) > V_114 )
return - V_226 ;
V_213 -> V_227 = V_46 ;
return 0 ;
}
static void
F_153 ( struct V_6 * log ,
struct V_145 * V_145 ,
T_1 V_225 , T_4 V_131 )
{
struct V_107 * V_223 ;
V_223 = F_67 ( V_145 ) ;
F_79 ( V_223 ) ;
V_223 -> V_127 = F_68 ( V_128 ) ;
V_223 -> V_129 = V_130 ;
V_223 -> V_111 = F_68 ( sizeof( struct V_107 ) ) ;
V_223 -> V_131 = F_80 ( V_131 ) ;
V_223 -> V_132 = F_80 ( V_225 ) ;
}
static int F_154 ( struct V_6 * log , T_1 V_225 ,
T_4 V_131 )
{
struct V_145 * V_145 ;
struct V_107 * V_223 ;
V_145 = F_144 ( V_215 ) ;
if ( ! V_145 )
return - V_135 ;
F_153 ( log , V_145 , V_225 , V_131 ) ;
V_223 = F_67 ( V_145 ) ;
V_223 -> V_115 = F_68 ( F_69 ( log -> V_113 ,
V_223 , V_114 ) ) ;
if ( ! F_155 ( log -> V_51 , V_225 , V_114 , V_145 , V_119 ,
V_228 | V_98 , false ) ) {
F_156 ( V_145 ) ;
return - V_229 ;
}
F_156 ( V_145 ) ;
return 0 ;
}
static void F_157 ( struct V_6 * log ,
struct V_32 * V_33 ,
struct V_212 * V_213 ,
struct V_140 * V_141 ,
T_1 V_230 )
{
struct V_31 * V_31 = log -> V_51 -> V_31 ;
struct V_1 * V_2 = V_31 -> V_52 ;
int V_231 ;
F_158 ( V_2 ,
F_152 ( V_141 -> V_136 ) , 0 ,
& V_231 , V_33 ) ;
F_149 ( log , V_213 , V_33 -> V_22 [ V_231 ] . V_145 , V_230 ) ;
V_33 -> V_22 [ V_231 ] . V_159 =
F_151 ( V_141 -> V_115 [ 0 ] ) ;
V_213 -> V_227 += V_46 ;
F_14 ( V_63 , & V_33 -> V_22 [ V_231 ] . V_37 ) ;
F_14 ( V_60 , & V_33 -> V_20 ) ;
}
static void F_159 ( struct V_6 * log ,
struct V_32 * V_33 ,
struct V_212 * V_213 ,
struct V_140 * V_141 ,
T_1 V_230 )
{
struct V_31 * V_31 = log -> V_51 -> V_31 ;
struct V_1 * V_2 = V_31 -> V_52 ;
V_213 -> V_227 += V_46 * V_2 -> V_47 ;
F_149 ( log , V_213 , V_33 -> V_22 [ V_33 -> V_68 ] . V_145 , V_230 ) ;
V_33 -> V_22 [ V_33 -> V_68 ] . V_159 =
F_151 ( V_141 -> V_115 [ 0 ] ) ;
F_14 ( V_63 , & V_33 -> V_22 [ V_33 -> V_68 ] . V_37 ) ;
if ( V_33 -> V_156 >= 0 ) {
F_149 (
log , V_213 , V_33 -> V_22 [ V_33 -> V_156 ] . V_145 ,
F_4 ( log , V_230 , V_46 ) ) ;
V_33 -> V_22 [ V_33 -> V_156 ] . V_159 =
F_151 ( V_141 -> V_115 [ 1 ] ) ;
F_14 ( V_63 , & V_33 -> V_22 [ V_33 -> V_156 ] . V_37 ) ;
}
F_25 ( V_60 , & V_33 -> V_20 ) ;
}
static void F_160 ( struct V_32 * V_33 )
{
int V_35 ;
V_33 -> V_20 = 0 ;
V_33 -> V_16 = V_162 ;
for ( V_35 = V_33 -> V_34 ; V_35 -- ; )
V_33 -> V_22 [ V_35 ] . V_37 = 0 ;
}
static void
F_161 ( struct V_1 * V_2 ,
struct V_32 * V_33 ,
struct V_212 * V_213 )
{
struct V_232 * V_51 , * V_233 ;
int V_234 ;
int V_235 = 0 ;
for ( V_234 = 0 ; V_234 < V_33 -> V_34 ; V_234 ++ ) {
if ( ! F_16 ( V_63 , & V_33 -> V_22 [ V_234 ] . V_37 ) )
continue;
if ( V_234 == V_33 -> V_156 || V_234 == V_33 -> V_68 )
continue;
V_235 ++ ;
}
if ( V_235 == 0 )
goto V_236;
for ( V_234 = 0 ; V_234 < V_33 -> V_34 ; V_234 ++ ) {
if ( ! F_16 ( V_63 , & V_33 -> V_22 [ V_234 ] . V_37 ) )
continue;
F_140 () ;
V_51 = F_141 ( V_2 -> V_34 [ V_234 ] . V_51 ) ;
if ( V_51 ) {
F_29 ( & V_51 -> V_237 ) ;
F_142 () ;
F_155 ( V_51 , V_33 -> V_29 , V_114 ,
V_33 -> V_22 [ V_234 ] . V_145 , V_119 , 0 ,
false ) ;
F_162 ( V_51 , V_51 -> V_31 ) ;
F_140 () ;
}
V_233 = F_141 ( V_2 -> V_34 [ V_234 ] . V_238 ) ;
if ( V_233 ) {
F_29 ( & V_233 -> V_237 ) ;
F_142 () ;
F_155 ( V_233 , V_33 -> V_29 , V_114 ,
V_33 -> V_22 [ V_234 ] . V_145 , V_119 , 0 ,
false ) ;
F_162 ( V_233 , V_233 -> V_31 ) ;
F_140 () ;
}
F_142 () ;
}
V_213 -> V_239 ++ ;
V_236:
F_160 ( V_33 ) ;
}
static struct V_32 *
F_163 ( struct V_1 * V_2 ,
T_1 V_240 )
{
struct V_32 * V_33 ;
V_33 = F_164 ( V_2 , V_240 , 0 , 1 , 0 ) ;
if ( ! V_33 )
return NULL ;
F_160 ( V_33 ) ;
return V_33 ;
}
static struct V_32 *
F_165 ( struct V_241 * V_242 , T_1 V_3 )
{
struct V_32 * V_33 ;
F_114 (sh, list, lru)
if ( V_33 -> V_29 == V_3 )
return V_33 ;
return NULL ;
}
static void
F_166 ( struct V_241 * V_243 ,
struct V_212 * V_213 )
{
struct V_32 * V_33 , * V_69 ;
F_35 (sh, next, cached_stripe_list, lru) {
F_160 ( V_33 ) ;
F_36 ( & V_33 -> V_189 ) ;
F_37 ( V_33 ) ;
}
}
static void
F_167 ( struct V_241 * V_243 ,
struct V_212 * V_213 )
{
struct V_32 * V_33 , * V_69 ;
F_35 (sh, next, cached_stripe_list, lru)
if ( ! F_16 ( V_60 , & V_33 -> V_20 ) ) {
F_161 ( V_33 -> V_59 , V_33 , V_213 ) ;
F_36 ( & V_33 -> V_189 ) ;
F_37 ( V_33 ) ;
}
}
static int
F_168 ( struct V_6 * log ,
struct V_212 * V_213 ,
struct V_145 * V_145 ,
T_1 V_230 , V_144 V_159 )
{
void * V_172 ;
T_2 V_115 ;
F_149 ( log , V_213 , V_145 , V_230 ) ;
V_172 = F_100 ( V_145 ) ;
V_115 = F_69 ( log -> V_113 , V_172 , V_114 ) ;
F_101 ( V_172 ) ;
return ( F_151 ( V_159 ) == V_115 ) ? 0 : - V_226 ;
}
static int
F_169 ( struct V_6 * log ,
struct V_212 * V_213 )
{
struct V_31 * V_31 = log -> V_51 -> V_31 ;
struct V_1 * V_2 = V_31 -> V_52 ;
struct V_107 * V_223 = F_67 ( V_213 -> V_82 ) ;
T_1 V_244 = sizeof( struct V_107 ) ;
T_1 V_230 = F_4 ( log , V_213 -> V_225 , V_46 ) ;
struct V_145 * V_145 ;
struct V_140 * V_141 ;
struct V_146 * V_245 ;
V_145 = F_144 ( V_215 ) ;
if ( ! V_145 )
return - V_135 ;
while ( V_244 < F_151 ( V_223 -> V_111 ) ) {
V_141 = ( void * ) V_223 + V_244 ;
V_245 = ( void * ) V_223 + V_244 ;
if ( F_170 ( V_141 -> V_142 . type ) == V_158 ) {
if ( F_168 (
log , V_213 , V_145 , V_230 ,
V_141 -> V_115 [ 0 ] ) < 0 )
goto V_246;
} else if ( F_170 ( V_141 -> V_142 . type ) == V_160 ) {
if ( F_168 (
log , V_213 , V_145 , V_230 ,
V_141 -> V_115 [ 0 ] ) < 0 )
goto V_246;
if ( V_2 -> V_47 == 2 &&
F_168 (
log , V_213 , V_145 ,
F_4 ( log , V_230 ,
V_46 ) ,
V_141 -> V_115 [ 1 ] ) < 0 )
goto V_246;
} else if ( F_170 ( V_141 -> V_142 . type ) == V_150 ) {
} else
goto V_246;
if ( F_170 ( V_141 -> V_142 . type ) == V_150 ) {
V_244 += sizeof( struct V_146 ) +
F_151 ( V_245 -> V_13 ) ;
} else {
V_230 = F_4 ( log , V_230 ,
F_151 ( V_141 -> V_13 ) ) ;
V_244 += sizeof( struct V_140 ) +
sizeof( V_144 ) *
( F_151 ( V_141 -> V_13 ) >> ( V_143 - 9 ) ) ;
}
}
F_146 ( V_145 ) ;
return 0 ;
V_246:
F_146 ( V_145 ) ;
return - V_226 ;
}
static int
F_171 ( struct V_6 * log ,
struct V_212 * V_213 ,
struct V_241 * V_243 )
{
struct V_31 * V_31 = log -> V_51 -> V_31 ;
struct V_1 * V_2 = V_31 -> V_52 ;
struct V_107 * V_223 ;
struct V_140 * V_141 ;
struct V_146 * V_245 ;
int V_244 ;
T_1 V_230 ;
T_1 V_240 ;
struct V_32 * V_33 ;
int V_154 ;
V_154 = F_169 ( log , V_213 ) ;
if ( V_154 == - V_226 )
return - V_170 ;
else if ( V_154 )
return V_154 ;
V_223 = F_67 ( V_213 -> V_82 ) ;
V_244 = sizeof( struct V_107 ) ;
V_230 = F_4 ( log , V_213 -> V_225 , V_46 ) ;
while ( V_244 < F_151 ( V_223 -> V_111 ) ) {
int V_247 ;
V_141 = ( void * ) V_223 + V_244 ;
V_245 = ( void * ) V_223 + V_244 ;
if ( F_170 ( V_141 -> V_142 . type ) == V_150 ) {
int V_35 , V_174 ;
V_174 = F_151 ( V_245 -> V_13 ) / sizeof( V_149 ) ;
for ( V_35 = 0 ; V_35 < V_174 ; ++ V_35 ) {
V_240 = F_152 ( V_245 -> V_151 [ V_35 ] ) ;
V_33 = F_165 ( V_243 ,
V_240 ) ;
if ( V_33 ) {
F_8 ( F_16 ( V_60 , & V_33 -> V_20 ) ) ;
F_160 ( V_33 ) ;
F_36 ( & V_33 -> V_189 ) ;
F_37 ( V_33 ) ;
}
}
V_244 += sizeof( struct V_146 ) +
F_151 ( V_245 -> V_13 ) ;
continue;
}
V_240 = ( F_170 ( V_141 -> V_142 . type ) == V_158 ) ?
F_158 (
V_2 , F_152 ( V_141 -> V_136 ) , 0 , & V_247 ,
NULL )
: F_152 ( V_141 -> V_136 ) ;
V_33 = F_165 ( V_243 ,
V_240 ) ;
if ( ! V_33 ) {
V_33 = F_163 ( V_2 , V_240 ) ;
if ( ! V_33 ) {
F_167 (
V_243 , V_213 ) ;
V_33 = F_163 (
V_2 , V_240 ) ;
}
if ( ! V_33 ) {
F_172 ( L_2 ,
F_62 ( V_31 ) ,
V_2 -> V_43 * 2 ) ;
F_173 ( V_31 ,
V_2 -> V_43 * 2 ) ;
V_33 = F_163 ( V_2 ,
V_240 ) ;
}
if ( ! V_33 ) {
F_174 ( L_3 ,
F_62 ( V_31 ) ) ;
return - V_135 ;
}
F_83 ( & V_33 -> V_189 , V_243 ) ;
}
if ( F_170 ( V_141 -> V_142 . type ) == V_158 ) {
if ( ! F_16 ( V_60 , & V_33 -> V_20 ) &&
F_16 ( V_63 , & V_33 -> V_22 [ V_33 -> V_68 ] . V_37 ) ) {
F_161 ( V_2 , V_33 , V_213 ) ;
F_40 ( & V_33 -> V_189 , V_243 ) ;
}
F_157 ( log , V_33 , V_213 , V_141 ,
V_230 ) ;
} else if ( F_170 ( V_141 -> V_142 . type ) == V_160 )
F_159 ( log , V_33 , V_213 , V_141 ,
V_230 ) ;
else
return - V_226 ;
V_230 = F_4 ( log , V_230 ,
F_151 ( V_141 -> V_13 ) ) ;
V_244 += sizeof( struct V_140 ) +
sizeof( V_144 ) *
( F_151 ( V_141 -> V_13 ) >> ( V_143 - 9 ) ) ;
}
return 0 ;
}
static void F_175 ( struct V_6 * log ,
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
static int F_176 ( struct V_6 * log ,
struct V_212 * V_213 )
{
struct V_32 * V_33 ;
int V_154 = 0 ;
while ( 1 ) {
if ( F_150 ( log , V_213 ) )
break;
V_154 = F_171 ( log , V_213 ,
& V_213 -> V_248 ) ;
if ( V_154 && V_154 != - V_170 )
break;
V_213 -> V_131 ++ ;
V_213 -> V_225 = F_4 ( log , V_213 -> V_225 , V_213 -> V_227 ) ;
}
if ( V_154 == - V_135 ) {
F_166 ( & V_213 -> V_248 , V_213 ) ;
return V_154 ;
}
F_167 ( & V_213 -> V_248 , V_213 ) ;
F_114 (sh, &ctx->cached_list, lru) {
F_8 ( ! F_16 ( V_60 , & V_33 -> V_20 ) ) ;
F_175 ( log , V_33 ) ;
V_213 -> V_249 ++ ;
}
return 0 ;
}
static int
F_177 ( struct V_6 * log ,
struct V_212 * V_213 )
{
struct V_32 * V_33 ;
struct V_31 * V_31 = log -> V_51 -> V_31 ;
struct V_145 * V_145 ;
T_1 V_179 = V_162 ;
V_145 = F_144 ( V_215 ) ;
if ( ! V_145 ) {
F_174 ( L_4 ,
F_62 ( V_31 ) ) ;
return - V_135 ;
}
F_8 ( F_47 ( & V_213 -> V_248 ) ) ;
F_114 (sh, &ctx->cached_list, lru) {
struct V_107 * V_223 ;
int V_35 ;
int V_4 ;
T_1 V_250 ;
F_8 ( ! F_16 ( V_60 , & V_33 -> V_20 ) ) ;
F_153 ( log , V_145 ,
V_213 -> V_225 , V_213 -> V_131 ) ;
V_223 = F_67 ( V_145 ) ;
V_4 = F_151 ( V_223 -> V_111 ) ;
V_250 = F_4 ( log , V_213 -> V_225 , V_46 ) ;
for ( V_35 = V_33 -> V_34 ; V_35 -- ; ) {
struct V_21 * V_22 = & V_33 -> V_22 [ V_35 ] ;
struct V_140 * V_141 ;
void * V_172 ;
if ( F_16 ( V_64 , & V_22 -> V_37 ) ) {
V_141 = ( void * ) V_223 + V_4 ;
V_141 -> V_142 . type = F_87 (
V_158 ) ;
V_141 -> V_13 = F_68 ( V_46 ) ;
V_141 -> V_136 = F_80 (
F_95 ( V_33 , V_35 , 0 ) ) ;
V_172 = F_100 ( V_22 -> V_145 ) ;
V_141 -> V_115 [ 0 ] = F_68 (
F_69 ( log -> V_113 , V_172 ,
V_114 ) ) ;
F_101 ( V_172 ) ;
F_155 ( log -> V_51 , V_250 , V_114 ,
V_22 -> V_145 , V_119 , 0 , false ) ;
V_250 = F_4 ( log , V_250 ,
V_46 ) ;
V_4 += sizeof( V_144 ) +
sizeof( struct V_140 ) ;
}
}
V_223 -> V_111 = F_68 ( V_4 ) ;
V_223 -> V_115 = F_68 ( F_69 ( log -> V_113 ,
V_223 , V_114 ) ) ;
F_155 ( log -> V_51 , V_213 -> V_225 , V_114 , V_145 ,
V_119 , V_228 | V_98 , false ) ;
V_33 -> V_16 = V_213 -> V_225 ;
F_83 ( & V_33 -> V_163 , & log -> V_165 ) ;
F_29 ( & log -> V_48 ) ;
V_213 -> V_225 = V_250 ;
V_213 -> V_131 += 1 ;
V_179 = V_33 -> V_16 ;
}
log -> V_179 = V_179 ;
F_156 ( V_145 ) ;
return 0 ;
}
static void F_178 ( struct V_6 * log ,
struct V_212 * V_213 )
{
struct V_31 * V_31 = log -> V_51 -> V_31 ;
struct V_1 * V_2 = V_31 -> V_52 ;
struct V_32 * V_33 , * V_69 ;
if ( V_213 -> V_249 == 0 )
return;
log -> V_7 = V_8 ;
F_35 (sh, next, &ctx->cached_list, lru) {
F_26 ( V_33 ) ;
F_14 ( V_71 , & V_33 -> V_20 ) ;
F_36 ( & V_33 -> V_189 ) ;
F_37 ( V_33 ) ;
}
F_51 ( V_2 -> V_31 -> V_88 ) ;
F_63 ( V_2 -> V_251 ,
F_18 ( & V_2 -> V_192 ) == 0 ) ;
log -> V_7 = V_67 ;
}
static int F_179 ( struct V_6 * log )
{
struct V_31 * V_31 = log -> V_51 -> V_31 ;
struct V_212 * V_213 ;
int V_154 ;
T_1 V_225 ;
V_213 = F_180 ( sizeof( * V_213 ) , V_215 ) ;
if ( ! V_213 )
return - V_135 ;
V_213 -> V_225 = log -> V_15 ;
V_213 -> V_131 = log -> V_252 ;
F_77 ( & V_213 -> V_248 ) ;
V_213 -> V_82 = F_144 ( V_215 ) ;
if ( ! V_213 -> V_82 ) {
V_154 = - V_135 ;
goto V_82;
}
if ( F_143 ( log , V_213 ) != 0 ) {
V_154 = - V_135 ;
goto V_219;
}
V_154 = F_176 ( log , V_213 ) ;
if ( V_154 )
goto error;
V_225 = V_213 -> V_225 ;
V_213 -> V_131 += 10000 ;
if ( ( V_213 -> V_249 == 0 ) && ( V_213 -> V_239 == 0 ) )
F_172 ( L_5 ,
F_62 ( V_31 ) ) ;
else
F_172 ( L_6 ,
F_62 ( V_31 ) , V_213 -> V_249 ,
V_213 -> V_239 ) ;
if ( V_213 -> V_249 == 0 ) {
log -> V_179 = V_213 -> V_225 ;
F_154 ( log , V_213 -> V_225 , V_213 -> V_131 ++ ) ;
V_213 -> V_225 = F_4 ( log , V_213 -> V_225 , V_46 ) ;
} else if ( F_177 ( log , V_213 ) ) {
F_174 ( L_7 ,
F_62 ( V_31 ) ) ;
V_154 = - V_229 ;
goto error;
}
log -> V_16 = V_213 -> V_225 ;
log -> V_131 = V_213 -> V_131 ;
log -> V_15 = V_225 ;
F_119 ( log , V_225 ) ;
F_178 ( log , V_213 ) ;
V_154 = 0 ;
error:
F_145 ( log , V_213 ) ;
V_219:
F_156 ( V_213 -> V_82 ) ;
V_82:
F_181 ( V_213 ) ;
return V_154 ;
}
static void F_119 ( struct V_6 * log , T_1 V_253 )
{
struct V_31 * V_31 = log -> V_51 -> V_31 ;
log -> V_51 -> V_254 = V_253 ;
F_14 ( V_188 , & V_31 -> V_105 ) ;
}
static T_5 F_182 ( struct V_31 * V_31 , char * V_145 )
{
struct V_1 * V_2 ;
int V_154 ;
V_154 = F_183 ( V_31 ) ;
if ( V_154 )
return V_154 ;
V_2 = V_31 -> V_52 ;
if ( ! V_2 || ! V_2 -> log ) {
F_126 ( V_31 ) ;
return 0 ;
}
switch ( V_2 -> log -> V_7 ) {
case V_67 :
V_154 = snprintf (
V_145 , V_114 , L_8 ,
V_255 [ V_67 ] ,
V_255 [ V_8 ] ) ;
break;
case V_8 :
V_154 = snprintf (
V_145 , V_114 , L_9 ,
V_255 [ V_67 ] ,
V_255 [ V_8 ] ) ;
break;
default:
V_154 = 0 ;
}
F_126 ( V_31 ) ;
return V_154 ;
}
int F_184 ( struct V_31 * V_31 , int V_256 )
{
struct V_1 * V_2 ;
int V_257 ;
if ( V_256 < V_67 ||
V_256 > V_8 )
return - V_226 ;
V_257 = F_183 ( V_31 ) ;
if ( V_257 )
return V_257 ;
V_2 = V_31 -> V_52 ;
if ( ! V_2 || ! V_2 -> log ) {
F_126 ( V_31 ) ;
return - V_176 ;
}
if ( F_185 ( V_2 ) > 0 &&
V_256 == V_8 ) {
F_126 ( V_31 ) ;
return - V_226 ;
}
F_64 ( V_31 ) ;
V_2 -> log -> V_7 = V_256 ;
F_65 ( V_31 ) ;
F_126 ( V_31 ) ;
F_172 ( L_10 ,
F_62 ( V_31 ) , V_256 , V_255 [ V_256 ] ) ;
return 0 ;
}
static T_5 F_186 ( struct V_31 * V_31 ,
const char * V_145 , T_6 V_258 )
{
int V_256 = F_187 ( V_255 ) ;
T_6 V_259 = V_258 ;
if ( V_259 < 2 )
return - V_226 ;
if ( V_145 [ V_259 - 1 ] == '\n' )
V_259 -- ;
while ( V_256 -- )
if ( strlen ( V_255 [ V_256 ] ) == V_259 &&
! strncmp ( V_145 , V_255 [ V_256 ] , V_259 ) )
break;
return F_184 ( V_31 , V_256 ) ? : V_258 ;
}
int F_188 ( struct V_1 * V_2 ,
struct V_32 * V_33 ,
struct V_260 * V_261 ,
int V_34 )
{
struct V_6 * log = V_2 -> log ;
int V_35 ;
struct V_21 * V_22 ;
int V_262 = 0 ;
void * * V_263 ;
T_1 V_264 ;
int V_154 ;
T_7 V_265 ;
F_27 ( ! F_3 ( log ) ) ;
if ( ! F_16 ( V_60 , & V_33 -> V_20 ) ) {
if ( V_261 -> V_266 > 0 || V_261 -> V_26 > 0 )
return - V_170 ;
F_14 ( V_60 , & V_33 -> V_20 ) ;
}
if ( V_261 -> V_267 || F_16 ( V_171 , & V_33 -> V_20 ) ) {
F_26 ( V_33 ) ;
return - V_170 ;
}
for ( V_35 = V_34 ; V_35 -- ; ) {
V_22 = & V_33 -> V_22 [ V_35 ] ;
if ( V_22 -> V_268 && ! F_16 ( V_269 , & V_22 -> V_37 ) &&
! F_16 ( V_64 , & V_22 -> V_37 ) ) {
F_26 ( V_33 ) ;
return - V_170 ;
}
}
if ( ! F_16 ( V_193 , & V_33 -> V_20 ) &&
! F_16 ( V_270 , & V_33 -> V_20 ) ) {
V_264 = F_1 ( V_2 , V_33 -> V_29 ) ;
F_97 ( & log -> V_271 ) ;
V_263 = F_189 ( & log -> V_272 ,
V_264 ) ;
if ( V_263 ) {
V_265 = ( T_7 ) F_190 (
V_263 , & log -> V_271 ) >>
V_273 ;
F_191 (
& log -> V_272 , V_263 ,
( void * ) ( ( V_265 + 1 ) << V_273 ) ) ;
} else {
V_154 = F_192 (
& log -> V_272 , V_264 ,
( void * ) ( 1 << V_273 ) ) ;
if ( V_154 ) {
F_98 ( & log -> V_271 ) ;
F_26 ( V_33 ) ;
return - V_170 ;
}
}
F_98 ( & log -> V_271 ) ;
F_14 ( V_193 , & V_33 -> V_20 ) ;
F_29 ( & V_2 -> V_41 ) ;
}
for ( V_35 = V_34 ; V_35 -- ; ) {
V_22 = & V_33 -> V_22 [ V_35 ] ;
if ( V_22 -> V_268 ) {
F_14 ( V_63 , & V_22 -> V_37 ) ;
F_14 ( V_274 , & V_22 -> V_37 ) ;
F_14 ( V_65 , & V_22 -> V_37 ) ;
V_262 ++ ;
}
}
if ( V_262 ) {
F_14 ( V_275 , & V_261 -> V_276 ) ;
F_14 ( V_66 , & V_33 -> V_20 ) ;
}
return 0 ;
}
void F_193 ( struct V_32 * V_33 )
{
struct V_1 * V_2 = V_33 -> V_59 ;
int V_35 ;
bool V_277 ;
V_277 =
V_33 -> V_22 [ 0 ] . V_278 == V_2 -> V_34 [ 0 ] . V_279 ;
for ( V_35 = V_33 -> V_34 ; V_35 -- ; )
if ( V_33 -> V_22 [ V_35 ] . V_145 != V_33 -> V_22 [ V_35 ] . V_278 ) {
struct V_145 * V_280 = V_33 -> V_22 [ V_35 ] . V_278 ;
V_33 -> V_22 [ V_35 ] . V_278 = V_33 -> V_22 [ V_35 ] . V_145 ;
F_25 ( V_281 , & V_33 -> V_22 [ V_35 ] . V_37 ) ;
if ( ! V_277 )
F_146 ( V_280 ) ;
}
if ( V_277 ) {
F_25 ( V_282 , & V_2 -> V_57 ) ;
F_51 ( V_2 -> V_31 -> V_88 ) ;
}
}
void F_194 ( struct V_32 * V_33 )
{
struct V_1 * V_2 = V_33 -> V_59 ;
int V_35 ;
struct V_21 * V_22 ;
for ( V_35 = V_33 -> V_34 ; V_35 -- ; ) {
V_22 = & V_33 -> V_22 [ V_35 ] ;
if ( V_22 -> V_278 != V_22 -> V_145 )
F_146 ( V_22 -> V_278 ) ;
V_22 -> V_278 = V_2 -> V_34 [ V_35 ] . V_279 ;
}
}
void F_195 ( struct V_1 * V_2 ,
struct V_32 * V_33 ,
struct V_260 * V_261 )
{
struct V_6 * log = V_2 -> log ;
int V_35 ;
int V_283 = 0 ;
T_1 V_264 ;
void * * V_263 ;
T_7 V_265 ;
if ( ! log || ! F_16 ( V_64 , & V_33 -> V_22 [ V_33 -> V_68 ] . V_37 ) )
return;
F_8 ( F_16 ( V_60 , & V_33 -> V_20 ) ) ;
F_25 ( V_64 , & V_33 -> V_22 [ V_33 -> V_68 ] . V_37 ) ;
if ( log -> V_7 == V_67 )
return;
for ( V_35 = V_33 -> V_34 ; V_35 -- ; ) {
F_25 ( V_64 , & V_33 -> V_22 [ V_35 ] . V_37 ) ;
if ( F_31 ( V_284 , & V_33 -> V_22 [ V_35 ] . V_37 ) )
V_283 = 1 ;
}
V_261 -> V_266 = 0 ;
if ( F_31 ( V_285 , & V_33 -> V_20 ) )
if ( F_54 ( & V_2 -> V_286 ) )
F_51 ( V_2 -> V_31 -> V_88 ) ;
if ( V_283 )
F_111 ( & V_2 -> V_287 ) ;
F_82 ( & log -> V_164 ) ;
F_36 ( & V_33 -> V_163 ) ;
F_84 ( & log -> V_164 ) ;
V_33 -> V_16 = V_162 ;
F_196 ( & log -> V_48 ) ;
F_24 ( log ) ;
if ( F_16 ( V_193 , & V_33 -> V_20 ) ||
F_16 ( V_270 , & V_33 -> V_20 ) ) {
V_264 = F_1 ( V_2 , V_33 -> V_29 ) ;
F_97 ( & log -> V_271 ) ;
V_263 = F_189 ( & log -> V_272 ,
V_264 ) ;
F_27 ( V_263 == NULL ) ;
V_265 = ( T_7 ) F_190 (
V_263 , & log -> V_271 ) >>
V_273 ;
if ( V_265 == 1 )
F_197 ( & log -> V_272 , V_264 ) ;
else
F_191 (
& log -> V_272 , V_263 ,
( void * ) ( ( V_265 - 1 ) << V_273 ) ) ;
F_98 ( & log -> V_271 ) ;
}
if ( F_31 ( V_193 , & V_33 -> V_20 ) ) {
F_27 ( F_18 ( & V_2 -> V_41 ) == 0 ) ;
F_196 ( & V_2 -> V_194 ) ;
F_196 ( & V_2 -> V_41 ) ;
}
if ( F_31 ( V_270 , & V_33 -> V_20 ) ) {
F_27 ( F_18 ( & V_2 -> V_42 ) == 0 ) ;
F_196 ( & V_2 -> V_195 ) ;
F_196 ( & V_2 -> V_42 ) ;
}
F_91 ( log , V_33 -> V_29 ) ;
if ( F_16 ( V_288 , & V_33 -> V_20 ) )
F_14 ( V_71 , & V_33 -> V_20 ) ;
}
int F_198 ( struct V_6 * log , struct V_32 * V_33 )
{
struct V_1 * V_2 = V_33 -> V_59 ;
int V_289 = 0 ;
int V_169 ;
int V_35 ;
int V_154 = 0 ;
F_27 ( ! log ) ;
for ( V_35 = 0 ; V_35 < V_33 -> V_34 ; V_35 ++ ) {
void * V_172 ;
if ( ! F_16 ( V_63 , & V_33 -> V_22 [ V_35 ] . V_37 ) )
continue;
V_172 = F_100 ( V_33 -> V_22 [ V_35 ] . V_145 ) ;
V_33 -> V_22 [ V_35 ] . V_159 = F_69 ( log -> V_113 ,
V_172 , V_114 ) ;
F_101 ( V_172 ) ;
V_289 ++ ;
}
F_8 ( V_289 == 0 ) ;
F_25 ( V_173 , & V_33 -> V_20 ) ;
F_29 ( & V_33 -> V_174 ) ;
F_92 ( & log -> V_148 ) ;
V_169 = ( 1 + V_289 ) << ( V_143 - 9 ) ;
if ( F_16 ( V_56 , & V_2 -> V_57 ) &&
V_33 -> V_16 == V_162 )
F_96 ( log , V_33 ) ;
else if ( ! F_6 ( log , V_169 ) ) {
if ( V_33 -> V_16 == log -> V_15 )
F_90 () ;
else
F_96 ( log , V_33 ) ;
} else {
V_154 = F_94 ( log , V_33 , V_289 , 0 ) ;
if ( V_154 ) {
F_82 ( & log -> V_72 ) ;
F_83 ( & V_33 -> V_70 , & log -> V_175 ) ;
F_84 ( & log -> V_72 ) ;
}
}
F_93 ( & log -> V_148 ) ;
return 0 ;
}
bool F_199 ( struct V_1 * V_2 , T_1 V_3 )
{
struct V_6 * log = V_2 -> log ;
T_1 V_264 ;
void * V_290 ;
if ( ! log )
return false ;
F_200 ( ! F_201 () ) ;
V_264 = F_1 ( V_2 , V_3 ) ;
V_290 = F_202 ( & log -> V_272 , V_264 ) ;
return V_290 != NULL ;
}
static int F_203 ( struct V_6 * log )
{
struct V_232 * V_51 = log -> V_51 ;
struct V_145 * V_145 ;
struct V_107 * V_223 ;
T_1 V_253 = log -> V_51 -> V_254 ;
T_2 V_224 , V_291 ;
bool V_292 = false ;
int V_154 = 0 ;
if ( V_253 >= V_51 -> V_293 || F_204 ( V_253 , V_46 ) != V_253 )
V_253 = 0 ;
V_145 = F_144 ( V_215 ) ;
if ( ! V_145 )
return - V_135 ;
if ( ! F_155 ( V_51 , V_253 , V_114 , V_145 , V_221 , 0 , false ) ) {
V_154 = - V_229 ;
goto V_294;
}
V_223 = F_67 ( V_145 ) ;
if ( F_151 ( V_223 -> V_127 ) != V_128 ||
V_223 -> V_129 != V_130 ) {
V_292 = true ;
goto V_295;
}
V_224 = F_151 ( V_223 -> V_115 ) ;
V_223 -> V_115 = 0 ;
V_291 = F_69 ( log -> V_113 , V_223 , V_114 ) ;
if ( V_224 != V_291 ) {
V_292 = true ;
goto V_295;
}
if ( F_152 ( V_223 -> V_132 ) != V_253 ) {
V_292 = true ;
goto V_295;
}
V_295:
if ( V_292 ) {
log -> V_252 = F_205 () ;
V_253 = 0 ;
F_154 ( log , V_253 , log -> V_252 ) ;
F_119 ( log , V_253 ) ;
} else
log -> V_252 = F_152 ( V_223 -> V_131 ) ;
log -> V_11 = F_204 ( V_51 -> V_293 , V_46 ) ;
log -> V_182 = log -> V_11 >> V_296 ;
if ( log -> V_182 > V_297 )
log -> V_182 = V_297 ;
log -> V_15 = V_253 ;
F_156 ( V_145 ) ;
if ( V_292 ) {
log -> V_16 = F_4 ( log , V_253 , V_46 ) ;
log -> V_131 = log -> V_252 + 1 ;
log -> V_179 = V_253 ;
} else
V_154 = F_179 ( log ) ;
F_24 ( log ) ;
return V_154 ;
V_294:
F_156 ( V_145 ) ;
return V_154 ;
}
void F_206 ( struct V_31 * V_31 , struct V_232 * V_51 )
{
struct V_1 * V_2 = V_31 -> V_52 ;
struct V_6 * log = V_2 -> log ;
if ( ! log )
return;
if ( ( F_185 ( V_2 ) > 0 ||
F_16 ( V_298 , & V_51 -> V_37 ) ) &&
V_2 -> log -> V_7 == V_8 )
F_49 ( & log -> V_102 ) ;
}
int F_207 ( struct V_1 * V_2 , struct V_232 * V_51 )
{
struct V_299 * V_300 = F_121 ( V_51 -> V_120 ) ;
struct V_6 * log ;
char V_301 [ V_302 ] ;
F_172 ( L_11 ,
F_62 ( V_2 -> V_31 ) , F_208 ( V_51 -> V_120 , V_301 ) ) ;
if ( V_114 != 4096 )
return - V_226 ;
if ( sizeof( struct V_107 ) +
( ( sizeof( struct V_140 ) + sizeof( V_144 ) ) *
V_2 -> V_49 ) > V_114 ) {
F_174 ( L_12 ,
F_62 ( V_2 -> V_31 ) , V_2 -> V_49 ) ;
return - V_226 ;
}
log = F_180 ( sizeof( * log ) , V_215 ) ;
if ( ! log )
return - V_135 ;
log -> V_51 = V_51 ;
log -> V_84 = F_16 ( V_303 , & V_300 -> V_304 ) != 0 ;
log -> V_113 = F_69 ( ~ 0 , V_51 -> V_31 -> V_305 ,
sizeof( V_51 -> V_31 -> V_305 ) ) ;
F_209 ( & log -> V_148 ) ;
F_210 ( & log -> V_72 ) ;
F_77 ( & log -> V_86 ) ;
F_77 ( & log -> V_76 ) ;
F_77 ( & log -> V_185 ) ;
F_77 ( & log -> V_75 ) ;
F_211 ( & log -> V_184 , NULL , 0 ) ;
log -> V_306 = F_212 ( V_17 , 0 ) ;
if ( ! log -> V_306 )
goto V_306;
log -> V_124 = F_213 ( V_307 , log -> V_306 ) ;
if ( ! log -> V_124 )
goto V_124;
log -> V_118 = F_214 ( V_307 , 0 , V_308 ) ;
if ( ! log -> V_118 )
goto V_309;
log -> V_83 = F_215 ( V_307 , 0 ) ;
if ( ! log -> V_83 )
goto V_310;
F_210 ( & log -> V_271 ) ;
F_216 ( & log -> V_272 , V_311 | V_312 ) ;
log -> V_208 = F_217 ( F_134 ,
log -> V_51 -> V_31 , L_13 ) ;
if ( ! log -> V_208 )
goto V_208;
log -> V_208 -> V_313 = V_314 ;
F_218 ( & log -> V_183 ) ;
F_77 ( & log -> V_175 ) ;
F_77 ( & log -> V_167 ) ;
F_210 ( & log -> V_166 ) ;
F_219 ( & log -> V_87 , F_58 ) ;
F_219 ( & log -> V_102 , F_60 ) ;
log -> V_7 = V_67 ;
F_77 ( & log -> V_165 ) ;
F_210 ( & log -> V_164 ) ;
F_220 ( & log -> V_48 , 0 ) ;
F_221 ( V_2 -> log , log ) ;
if ( F_203 ( log ) )
goto error;
F_14 ( V_210 , & V_2 -> V_31 -> V_37 ) ;
return 0 ;
error:
F_221 ( V_2 -> log , NULL ) ;
F_222 ( & log -> V_208 ) ;
V_208:
F_223 ( log -> V_83 ) ;
V_310:
F_224 ( log -> V_118 ) ;
V_309:
F_223 ( log -> V_124 ) ;
V_124:
F_225 ( log -> V_306 ) ;
V_306:
F_181 ( log ) ;
return - V_226 ;
}
void F_226 ( struct V_1 * V_2 )
{
struct V_6 * log = V_2 -> log ;
V_2 -> log = NULL ;
F_227 () ;
F_228 ( & log -> V_102 ) ;
F_222 ( & log -> V_208 ) ;
F_223 ( log -> V_83 ) ;
F_224 ( log -> V_118 ) ;
F_223 ( log -> V_124 ) ;
F_225 ( log -> V_306 ) ;
F_181 ( log ) ;
}
