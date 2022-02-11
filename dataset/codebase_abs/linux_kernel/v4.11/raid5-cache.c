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
F_9 ( struct V_1 * V_2 , struct V_21 * V_22 ,
struct V_23 * V_24 )
{
struct V_25 * V_26 , * V_27 ;
V_26 = V_22 -> V_28 ;
V_22 -> V_28 = NULL ;
while ( V_26 && V_26 -> V_29 . V_30 <
V_22 -> V_31 + V_32 ) {
V_27 = F_10 ( V_26 , V_22 -> V_31 ) ;
if ( ! F_11 ( V_26 ) ) {
F_12 ( V_2 -> V_33 ) ;
F_13 ( V_24 , V_26 ) ;
}
V_26 = V_27 ;
}
}
void F_14 ( struct V_1 * V_2 ,
struct V_34 * V_35 , int V_36 , struct V_23 * V_24 )
{
int V_37 ;
for ( V_37 = V_35 -> V_36 ; V_37 -- ; ) {
if ( V_35 -> V_22 [ V_37 ] . V_28 ) {
F_15 ( V_38 , & V_35 -> V_22 [ V_37 ] . V_39 ) ;
F_9 ( V_2 , & V_35 -> V_22 [ V_37 ] ,
V_24 ) ;
F_16 ( V_2 -> V_33 -> V_40 , V_35 -> V_31 ,
V_32 ,
! F_17 ( V_41 , & V_35 -> V_20 ) ,
0 ) ;
}
}
}
void F_18 ( struct V_1 * V_2 )
{
int V_42 ;
if ( ! F_3 ( V_2 -> log ) )
return;
V_42 = F_19 ( & V_2 -> V_43 ) +
F_19 ( & V_2 -> V_44 ) ;
if ( V_42 > V_2 -> V_45 * 1 / 2 ||
F_19 ( & V_2 -> V_46 ) > 0 )
F_20 ( V_2 -> log , 0 ) ;
}
void F_21 ( struct V_1 * V_2 )
{
if ( ! F_3 ( V_2 -> log ) )
return;
if ( F_19 ( & V_2 -> V_44 ) >=
F_22 ( V_47 ,
V_2 -> V_5 >> V_48 ) )
F_20 ( V_2 -> log , 0 ) ;
}
static T_1 F_23 ( struct V_1 * V_2 )
{
struct V_6 * log = V_2 -> log ;
if ( ! F_3 ( log ) )
return 0 ;
return V_49 *
( ( V_2 -> V_50 + 1 ) * F_19 ( & log -> V_51 ) +
( V_2 -> V_52 - V_2 -> V_50 ) * ( V_2 -> V_53 + 1 ) ) ;
}
static inline void F_24 ( struct V_6 * log )
{
struct V_1 * V_2 = log -> V_54 -> V_33 -> V_55 ;
T_1 V_56 ;
T_1 V_57 ;
bool V_58 = false ;
if ( ! F_3 ( log ) )
return;
V_56 = F_5 ( log , log -> V_16 ,
log -> V_15 ) ;
V_57 = F_23 ( V_2 ) ;
if ( V_56 < 2 * V_57 )
F_15 ( V_59 , & V_2 -> V_60 ) ;
else {
if ( F_17 ( V_59 , & V_2 -> V_60 ) )
V_58 = true ;
F_25 ( V_59 , & V_2 -> V_60 ) ;
}
if ( V_56 < 3 * V_57 )
F_15 ( V_61 , & V_2 -> V_60 ) ;
else
F_25 ( V_61 , & V_2 -> V_60 ) ;
if ( V_58 )
F_20 ( log , 0 ) ;
}
void F_26 ( struct V_34 * V_35 )
{
struct V_1 * V_2 = V_35 -> V_62 ;
struct V_6 * log = V_2 -> log ;
F_27 ( ! F_3 ( log ) ) ;
F_8 ( ! F_17 ( V_63 , & V_35 -> V_20 ) ) ;
F_25 ( V_63 , & V_35 -> V_20 ) ;
if ( ! F_28 ( V_64 , & V_35 -> V_20 ) )
F_29 ( & V_2 -> V_65 ) ;
}
static void F_30 ( struct V_34 * V_35 )
{
int V_37 ;
for ( V_37 = V_35 -> V_36 ; V_37 -- ; )
if ( F_31 ( V_66 , & V_35 -> V_22 [ V_37 ] . V_39 ) ) {
F_15 ( V_67 , & V_35 -> V_22 [ V_37 ] . V_39 ) ;
F_25 ( V_68 , & V_35 -> V_22 [ V_37 ] . V_39 ) ;
}
F_25 ( V_69 , & V_35 -> V_20 ) ;
}
static void F_32 ( struct V_34 * V_35 )
{
int V_37 ;
for ( V_37 = V_35 -> V_36 ; V_37 -- ; )
if ( F_17 ( V_67 , & V_35 -> V_22 [ V_37 ] . V_39 ) )
F_15 ( V_66 , & V_35 -> V_22 [ V_37 ] . V_39 ) ;
}
static void F_33 ( struct V_34 * V_35 )
{
struct V_6 * log = V_35 -> V_62 -> log ;
if ( log -> V_7 == V_70 ) {
F_27 ( F_17 ( V_63 , & V_35 -> V_20 ) ) ;
F_15 ( V_67 , & V_35 -> V_22 [ V_35 -> V_71 ] . V_39 ) ;
} else if ( F_17 ( V_63 , & V_35 -> V_20 ) ) {
F_30 ( V_35 ) ;
} else {
F_32 ( V_35 ) ;
F_15 ( V_67 , & V_35 -> V_22 [ V_35 -> V_71 ] . V_39 ) ;
}
}
static void F_34 ( struct V_17 * V_18 )
{
struct V_34 * V_35 , * V_72 ;
F_35 (sh, next, &io->stripe_list, log_list) {
F_36 ( & V_35 -> V_73 ) ;
F_33 ( V_35 ) ;
F_15 ( V_74 , & V_35 -> V_20 ) ;
F_37 ( V_35 ) ;
}
}
static void F_38 ( struct V_6 * log )
{
struct V_17 * V_18 , * V_72 ;
F_39 ( & log -> V_75 ) ;
F_35 (io, next, &log->running_ios, log_sibling) {
if ( V_18 -> V_20 < V_76 )
break;
F_40 ( & V_18 -> V_77 , & log -> V_78 ) ;
F_34 ( V_18 ) ;
}
}
static void F_41 ( struct V_6 * log )
{
struct V_17 * V_18 , * V_72 ;
F_39 ( & log -> V_75 ) ;
F_35 (io, next, &log->running_ios, log_sibling) {
if ( V_18 -> V_20 < V_76 )
break;
F_40 ( & V_18 -> V_77 , & log -> V_79 ) ;
}
}
static void F_42 ( struct V_25 * V_25 )
{
struct V_17 * V_18 = V_25 -> V_80 ;
struct V_17 * V_81 ;
struct V_6 * log = V_18 -> log ;
unsigned long V_39 ;
if ( V_25 -> V_82 )
F_43 ( log -> V_54 -> V_33 , log -> V_54 ) ;
F_44 ( V_25 ) ;
F_45 ( V_18 -> V_83 , log -> V_84 ) ;
F_46 ( & log -> V_75 , V_39 ) ;
F_7 ( V_18 , V_76 ) ;
if ( log -> V_85 )
F_41 ( log ) ;
else
F_38 ( log ) ;
if ( ! F_47 ( & log -> V_86 ) ) {
V_81 = F_48 ( & log -> V_86 ,
struct V_17 , V_77 ) ;
if ( V_81 -> V_81 )
F_49 ( & log -> V_87 ) ;
}
F_50 ( & log -> V_75 , V_39 ) ;
if ( log -> V_85 )
F_51 ( log -> V_54 -> V_33 -> V_88 ) ;
if ( V_18 -> V_89 ) {
struct V_25 * V_90 ;
F_8 ( F_52 ( & V_18 -> V_91 ) ) ;
while ( ( V_90 = F_53 ( & V_18 -> V_91 ) ) != NULL ) {
F_54 ( V_90 ) ;
F_55 ( & V_18 -> V_92 ) ;
}
if ( F_19 ( & V_18 -> V_92 ) == 0 )
F_56 ( V_18 ) ;
}
}
static void F_57 ( struct V_6 * log , struct V_17 * V_18 )
{
unsigned long V_39 ;
F_46 ( & log -> V_75 , V_39 ) ;
F_7 ( V_18 , V_93 ) ;
F_50 ( & log -> V_75 , V_39 ) ;
if ( V_18 -> V_94 )
V_18 -> V_95 -> V_96 |= V_97 ;
if ( V_18 -> V_98 )
V_18 -> V_95 -> V_96 |= V_99 ;
F_58 ( V_18 -> V_95 ) ;
if ( ! V_18 -> V_100 )
return;
if ( V_18 -> V_94 )
V_18 -> V_100 -> V_96 |= V_97 ;
if ( V_18 -> V_98 )
V_18 -> V_100 -> V_96 |= V_99 ;
F_58 ( V_18 -> V_100 ) ;
}
static void F_59 ( struct V_101 * V_102 )
{
struct V_6 * log = F_60 ( V_102 , struct V_6 ,
V_87 ) ;
struct V_17 * V_18 = NULL ;
unsigned long V_39 ;
F_46 ( & log -> V_75 , V_39 ) ;
if ( ! F_47 ( & log -> V_86 ) ) {
V_18 = F_48 ( & log -> V_86 , struct V_17 ,
V_77 ) ;
if ( ! V_18 -> V_81 )
V_18 = NULL ;
else
V_18 -> V_81 = 0 ;
}
F_50 ( & log -> V_75 , V_39 ) ;
if ( V_18 )
F_57 ( log , V_18 ) ;
}
static void F_61 ( struct V_101 * V_102 )
{
struct V_6 * log = F_60 ( V_102 , struct V_6 ,
V_103 ) ;
struct V_33 * V_33 = log -> V_54 -> V_33 ;
if ( log -> V_7 == V_70 )
return;
F_62 ( L_1 ,
F_63 ( V_33 ) ) ;
F_64 ( V_33 ) ;
log -> V_7 = V_70 ;
F_65 ( V_33 ) ;
}
static void F_66 ( struct V_6 * log )
{
struct V_17 * V_18 = log -> V_104 ;
struct V_25 * V_25 ;
struct V_105 * V_106 ;
unsigned long V_39 ;
T_2 V_107 ;
bool V_108 = true ;
if ( ! V_18 )
return;
V_106 = F_67 ( V_18 -> V_83 ) ;
V_106 -> V_109 = F_68 ( V_18 -> V_110 ) ;
V_107 = F_69 ( log -> V_111 , V_106 , V_112 ) ;
V_106 -> V_113 = F_68 ( V_107 ) ;
V_25 = V_18 -> V_95 ;
log -> V_104 = NULL ;
F_46 ( & log -> V_75 , V_39 ) ;
if ( V_18 -> V_94 || V_18 -> V_98 ) {
if ( V_18 != F_48 ( & log -> V_86 ,
struct V_17 , V_77 ) ) {
V_18 -> V_81 = 1 ;
V_108 = false ;
}
}
F_50 ( & log -> V_75 , V_39 ) ;
if ( V_108 )
F_57 ( log , V_18 ) ;
}
static struct V_25 * F_70 ( struct V_6 * log )
{
struct V_25 * V_25 = F_71 ( V_114 , V_115 , log -> V_116 ) ;
F_72 ( V_25 , V_117 , 0 ) ;
V_25 -> V_118 = log -> V_54 -> V_119 ;
V_25 -> V_29 . V_30 = log -> V_54 -> V_120 + log -> V_16 ;
return V_25 ;
}
static void F_73 ( struct V_6 * log , struct V_17 * V_18 )
{
log -> V_16 = F_4 ( log , log -> V_16 , V_49 ) ;
F_24 ( log ) ;
if ( log -> V_16 == 0 )
V_18 -> V_121 = true ;
V_18 -> V_122 = log -> V_16 ;
}
static struct V_17 * F_74 ( struct V_6 * log )
{
struct V_17 * V_18 ;
struct V_105 * V_106 ;
V_18 = F_75 ( log -> V_123 , V_124 ) ;
if ( ! V_18 )
return NULL ;
memset ( V_18 , 0 , sizeof( * V_18 ) ) ;
V_18 -> log = log ;
F_76 ( & V_18 -> V_77 ) ;
F_76 ( & V_18 -> V_125 ) ;
F_77 ( & V_18 -> V_91 ) ;
V_18 -> V_20 = V_126 ;
V_18 -> V_83 = F_75 ( log -> V_84 , V_114 ) ;
V_106 = F_67 ( V_18 -> V_83 ) ;
F_78 ( V_106 ) ;
V_106 -> V_127 = F_68 ( V_128 ) ;
V_106 -> V_129 = V_130 ;
V_106 -> V_131 = F_79 ( log -> V_131 ) ;
V_106 -> V_132 = F_79 ( log -> V_16 ) ;
V_18 -> V_16 = log -> V_16 ;
V_18 -> V_110 = sizeof( struct V_105 ) ;
V_18 -> V_131 = log -> V_131 ++ ;
V_18 -> V_95 = F_70 ( log ) ;
V_18 -> V_95 -> V_133 = F_42 ;
V_18 -> V_95 -> V_80 = V_18 ;
F_80 ( V_18 -> V_95 , V_18 -> V_83 , V_112 , 0 ) ;
F_73 ( log , V_18 ) ;
F_81 ( & log -> V_75 ) ;
F_82 ( & V_18 -> V_77 , & log -> V_86 ) ;
F_83 ( & log -> V_75 ) ;
return V_18 ;
}
static int F_84 ( struct V_6 * log , unsigned int V_134 )
{
if ( log -> V_104 &&
log -> V_104 -> V_110 + V_134 > V_112 )
F_66 ( log ) ;
if ( ! log -> V_104 ) {
log -> V_104 = F_74 ( log ) ;
if ( ! log -> V_104 )
return - V_135 ;
}
return 0 ;
}
static void F_85 ( struct V_6 * log , T_3 type ,
T_1 V_136 ,
T_2 V_137 , T_2 V_138 ,
bool V_139 )
{
struct V_17 * V_18 = log -> V_104 ;
struct V_140 * V_141 ;
V_141 = F_67 ( V_18 -> V_83 ) + V_18 -> V_110 ;
V_141 -> V_142 . type = F_86 ( type ) ;
V_141 -> V_142 . V_39 = F_86 ( 0 ) ;
V_141 -> V_13 = F_68 ( ( 1 + ! ! V_139 ) <<
( V_143 - 9 ) ) ;
V_141 -> V_136 = F_79 ( V_136 ) ;
V_141 -> V_113 [ 0 ] = F_68 ( V_137 ) ;
if ( V_139 )
V_141 -> V_113 [ 1 ] = F_68 ( V_138 ) ;
V_18 -> V_110 += sizeof( struct V_140 ) +
sizeof( V_144 ) * ( 1 + ! ! V_139 ) ;
}
static void F_87 ( struct V_6 * log , struct V_145 * V_145 )
{
struct V_17 * V_18 = log -> V_104 ;
if ( V_18 -> V_121 ) {
F_27 ( V_18 -> V_100 ) ;
V_18 -> V_100 = V_18 -> V_95 ;
V_18 -> V_95 = F_70 ( log ) ;
F_88 ( V_18 -> V_95 , V_18 -> V_100 ) ;
V_18 -> V_121 = false ;
}
if ( ! F_80 ( V_18 -> V_95 , V_145 , V_112 , 0 ) )
F_89 () ;
F_73 ( log , V_18 ) ;
}
static int F_90 ( struct V_6 * log , struct V_34 * V_35 ,
int V_146 , int V_147 )
{
int V_37 ;
int V_109 ;
int V_148 ;
struct V_17 * V_18 ;
V_109 =
( ( sizeof( struct V_140 ) + sizeof( V_144 ) )
* V_146 ) +
sizeof( struct V_140 ) +
sizeof( V_144 ) * V_147 ;
V_148 = F_84 ( log , V_109 ) ;
if ( V_148 )
return V_148 ;
V_18 = log -> V_104 ;
if ( F_31 ( V_149 , & V_35 -> V_20 ) )
V_18 -> V_94 = 1 ;
for ( V_37 = 0 ; V_37 < V_35 -> V_36 ; V_37 ++ ) {
if ( ! F_17 ( V_66 , & V_35 -> V_22 [ V_37 ] . V_39 ) ||
F_17 ( V_67 , & V_35 -> V_22 [ V_37 ] . V_39 ) )
continue;
if ( V_37 == V_35 -> V_71 || V_37 == V_35 -> V_150 )
continue;
if ( F_17 ( V_151 , & V_35 -> V_22 [ V_37 ] . V_39 ) &&
log -> V_7 == V_8 ) {
V_18 -> V_98 = 1 ;
V_18 -> V_94 = 1 ;
}
F_85 ( log , V_152 ,
F_91 ( V_35 , V_37 , 0 ) ,
V_35 -> V_22 [ V_37 ] . V_153 , 0 , false ) ;
F_87 ( log , V_35 -> V_22 [ V_37 ] . V_145 ) ;
}
if ( V_147 == 2 ) {
F_85 ( log , V_154 ,
V_35 -> V_31 , V_35 -> V_22 [ V_35 -> V_71 ] . V_153 ,
V_35 -> V_22 [ V_35 -> V_150 ] . V_153 , true ) ;
F_87 ( log , V_35 -> V_22 [ V_35 -> V_71 ] . V_145 ) ;
F_87 ( log , V_35 -> V_22 [ V_35 -> V_150 ] . V_145 ) ;
} else if ( V_147 == 1 ) {
F_85 ( log , V_154 ,
V_35 -> V_31 , V_35 -> V_22 [ V_35 -> V_71 ] . V_153 ,
0 , false ) ;
F_87 ( log , V_35 -> V_22 [ V_35 -> V_71 ] . V_145 ) ;
} else
F_27 ( V_147 != 0 ) ;
F_82 ( & V_35 -> V_73 , & V_18 -> V_125 ) ;
F_29 ( & V_18 -> V_92 ) ;
V_35 -> V_155 = V_18 ;
if ( log -> V_7 == V_70 )
return 0 ;
if ( V_35 -> V_16 == V_156 ) {
F_27 ( ! F_47 ( & V_35 -> V_157 ) ) ;
V_35 -> V_16 = V_18 -> V_16 ;
F_81 ( & log -> V_158 ) ;
F_82 ( & V_35 -> V_157 ,
& log -> V_159 ) ;
F_83 ( & log -> V_158 ) ;
F_29 ( & log -> V_51 ) ;
}
return 0 ;
}
static inline void F_92 ( struct V_6 * log ,
struct V_34 * V_35 )
{
F_93 ( & log -> V_160 ) ;
F_82 ( & V_35 -> V_73 , & log -> V_161 ) ;
F_94 ( & log -> V_160 ) ;
}
int F_95 ( struct V_6 * log , struct V_34 * V_35 )
{
struct V_1 * V_2 = V_35 -> V_62 ;
int V_162 = 0 ;
int V_146 , V_147 ;
int V_163 ;
int V_37 ;
int V_148 = 0 ;
bool V_58 = false ;
if ( ! log )
return - V_164 ;
if ( V_35 -> V_155 || ! F_17 ( V_66 , & V_35 -> V_22 [ V_35 -> V_71 ] . V_39 ) ||
F_17 ( V_165 , & V_35 -> V_20 ) ) {
F_25 ( V_69 , & V_35 -> V_20 ) ;
return - V_164 ;
}
F_8 ( F_17 ( V_63 , & V_35 -> V_20 ) ) ;
for ( V_37 = 0 ; V_37 < V_35 -> V_36 ; V_37 ++ ) {
void * V_166 ;
if ( ! F_17 ( V_66 , & V_35 -> V_22 [ V_37 ] . V_39 ) ||
F_17 ( V_67 , & V_35 -> V_22 [ V_37 ] . V_39 ) )
continue;
V_162 ++ ;
if ( F_17 ( V_69 , & V_35 -> V_20 ) )
continue;
V_166 = F_96 ( V_35 -> V_22 [ V_37 ] . V_145 ) ;
V_35 -> V_22 [ V_37 ] . V_153 = F_69 ( log -> V_111 ,
V_166 , V_112 ) ;
F_97 ( V_166 ) ;
}
V_147 = 1 + ! ! ( V_35 -> V_150 >= 0 ) ;
V_146 = V_162 - V_147 ;
F_15 ( V_69 , & V_35 -> V_20 ) ;
F_25 ( V_167 , & V_35 -> V_20 ) ;
F_29 ( & V_35 -> V_168 ) ;
F_98 ( & log -> V_169 ) ;
V_163 = ( 1 + V_162 ) << ( V_143 - 9 ) ;
if ( log -> V_7 == V_70 ) {
if ( ! F_6 ( log , V_163 ) ) {
F_92 ( log , V_35 ) ;
V_58 = true ;
} else {
V_148 = F_90 ( log , V_35 , V_146 , V_147 ) ;
if ( V_148 ) {
F_81 ( & log -> V_75 ) ;
F_82 ( & V_35 -> V_73 ,
& log -> V_170 ) ;
F_83 ( & log -> V_75 ) ;
}
}
} else {
if ( F_17 ( V_59 , & V_2 -> V_60 ) &&
V_35 -> V_16 == V_156 ) {
F_92 ( log , V_35 ) ;
V_58 = true ;
V_163 = 0 ;
} else if ( ! F_6 ( log , V_163 ) ) {
if ( V_35 -> V_16 == log -> V_15 )
F_89 () ;
else
F_92 ( log , V_35 ) ;
} else {
V_148 = F_90 ( log , V_35 , V_146 , V_147 ) ;
if ( V_148 ) {
F_81 ( & log -> V_75 ) ;
F_82 ( & V_35 -> V_73 ,
& log -> V_170 ) ;
F_83 ( & log -> V_75 ) ;
}
}
}
F_99 ( & log -> V_169 ) ;
if ( V_58 )
F_20 ( log , V_163 ) ;
return 0 ;
}
void F_100 ( struct V_6 * log )
{
if ( ! log )
return;
F_98 ( & log -> V_169 ) ;
F_66 ( log ) ;
F_99 ( & log -> V_169 ) ;
}
int F_101 ( struct V_6 * log , struct V_25 * V_25 )
{
if ( ! log )
return - V_171 ;
if ( log -> V_7 == V_70 ) {
if ( V_25 -> V_29 . V_172 == 0 ) {
F_54 ( V_25 ) ;
return 0 ;
}
V_25 -> V_96 &= ~ V_97 ;
} else {
if ( V_25 -> V_29 . V_172 == 0 ) {
F_98 ( & log -> V_169 ) ;
F_84 ( log , 0 ) ;
F_13 ( & log -> V_104 -> V_91 , V_25 ) ;
log -> V_104 -> V_94 = 1 ;
log -> V_104 -> V_89 = 1 ;
F_29 ( & log -> V_104 -> V_92 ) ;
F_66 ( log ) ;
F_99 ( & log -> V_169 ) ;
return 0 ;
}
}
return - V_164 ;
}
static void F_102 ( struct V_6 * log )
{
struct V_34 * V_35 ;
F_93 ( & log -> V_160 ) ;
while ( ! F_47 ( & log -> V_161 ) ) {
V_35 = F_48 ( & log -> V_161 ,
struct V_34 , V_73 ) ;
F_36 ( & V_35 -> V_73 ) ;
F_15 ( V_74 , & V_35 -> V_20 ) ;
F_37 ( V_35 ) ;
}
F_94 ( & log -> V_160 ) ;
}
static T_1 F_103 ( struct V_1 * V_2 )
{
struct V_34 * V_35 ;
struct V_6 * log = V_2 -> log ;
T_1 V_173 ;
unsigned long V_39 ;
if ( log -> V_7 == V_70 )
return log -> V_174 ;
F_46 ( & log -> V_158 , V_39 ) ;
if ( F_47 ( & V_2 -> log -> V_159 ) ) {
F_50 ( & log -> V_158 , V_39 ) ;
return log -> V_174 ;
}
V_35 = F_48 ( & V_2 -> log -> V_159 ,
struct V_34 , V_157 ) ;
V_173 = V_35 -> V_16 ;
F_50 ( & log -> V_158 , V_39 ) ;
return V_173 ;
}
static T_1 F_104 ( struct V_6 * log )
{
struct V_1 * V_2 = log -> V_54 -> V_33 -> V_55 ;
return F_5 ( log , log -> V_15 ,
F_103 ( V_2 ) ) ;
}
static void F_105 ( struct V_6 * log )
{
struct V_34 * V_35 ;
F_39 ( & log -> V_75 ) ;
if ( ! F_47 ( & log -> V_170 ) ) {
V_35 = F_48 ( & log -> V_170 ,
struct V_34 , V_73 ) ;
F_36 ( & V_35 -> V_73 ) ;
F_15 ( V_74 , & V_35 -> V_20 ) ;
F_37 ( V_35 ) ;
}
}
static bool F_106 ( struct V_6 * log )
{
struct V_17 * V_18 , * V_72 ;
bool V_175 = false ;
F_39 ( & log -> V_75 ) ;
F_35 (io, next, &log->finished_ios, log_sibling) {
if ( V_18 -> V_20 < V_176 )
break;
log -> V_174 = V_18 -> V_16 ;
F_107 ( & V_18 -> V_77 ) ;
F_45 ( V_18 , log -> V_123 ) ;
F_105 ( log ) ;
V_175 = true ;
}
return V_175 ;
}
static void F_56 ( struct V_17 * V_18 )
{
struct V_6 * log = V_18 -> log ;
struct V_1 * V_2 = log -> V_54 -> V_33 -> V_55 ;
unsigned long V_39 ;
F_46 ( & log -> V_75 , V_39 ) ;
F_7 ( V_18 , V_176 ) ;
if ( ! F_106 ( log ) ) {
F_50 ( & log -> V_75 , V_39 ) ;
return;
}
if ( F_104 ( log ) > log -> V_177 ||
F_17 ( V_61 , & V_2 -> V_60 ) )
F_20 ( log , 0 ) ;
F_50 ( & log -> V_75 , V_39 ) ;
F_108 ( & log -> V_178 ) ;
}
void F_109 ( struct V_34 * V_35 )
{
struct V_17 * V_18 ;
V_18 = V_35 -> V_155 ;
V_35 -> V_155 = NULL ;
if ( V_18 && F_110 ( & V_18 -> V_92 ) )
F_56 ( V_18 ) ;
}
static void F_111 ( struct V_25 * V_25 )
{
struct V_6 * log = F_60 ( V_25 , struct V_6 ,
V_179 ) ;
unsigned long V_39 ;
struct V_17 * V_18 ;
if ( V_25 -> V_82 )
F_43 ( log -> V_54 -> V_33 , log -> V_54 ) ;
F_46 ( & log -> V_75 , V_39 ) ;
F_112 (io, &log->flushing_ios, log_sibling)
F_34 ( V_18 ) ;
F_113 ( & log -> V_180 , & log -> V_78 ) ;
F_50 ( & log -> V_75 , V_39 ) ;
}
void F_114 ( struct V_6 * log )
{
bool V_181 ;
if ( ! log || ! log -> V_85 )
return;
F_81 ( & log -> V_75 ) ;
if ( ! F_47 ( & log -> V_180 ) ) {
F_83 ( & log -> V_75 ) ;
return;
}
F_113 ( & log -> V_79 , & log -> V_180 ) ;
V_181 = ! F_47 ( & log -> V_180 ) ;
F_83 ( & log -> V_75 ) ;
if ( ! V_181 )
return;
F_115 ( & log -> V_179 ) ;
log -> V_179 . V_118 = log -> V_54 -> V_119 ;
log -> V_179 . V_133 = F_111 ;
log -> V_179 . V_96 = V_117 | V_97 ;
F_58 ( & log -> V_179 ) ;
}
static void F_116 ( struct V_6 * log ,
T_1 V_12 )
{
struct V_182 * V_119 = log -> V_54 -> V_119 ;
struct V_33 * V_33 ;
F_117 ( log , V_12 ) ;
if ( ! F_118 ( F_119 ( V_119 ) ) )
return;
V_33 = log -> V_54 -> V_33 ;
F_120 ( & V_33 -> V_183 , 0 ,
F_121 ( V_184 ) | F_121 ( V_185 ) ) ;
if ( ! F_122 ( V_33 ) )
return;
F_123 ( V_33 , 1 ) ;
F_124 ( V_33 ) ;
if ( log -> V_15 < V_12 ) {
F_125 ( V_119 ,
log -> V_15 + log -> V_54 -> V_120 ,
V_12 - log -> V_15 , V_114 , 0 ) ;
} else {
F_125 ( V_119 ,
log -> V_15 + log -> V_54 -> V_120 ,
log -> V_11 - log -> V_15 ,
V_114 , 0 ) ;
F_125 ( V_119 , log -> V_54 -> V_120 , V_12 ,
V_114 , 0 ) ;
}
}
static void F_126 ( struct V_1 * V_2 , struct V_34 * V_35 )
{
F_27 ( F_47 ( & V_35 -> V_186 ) ) ;
F_27 ( ! F_17 ( V_63 , & V_35 -> V_20 ) ) ;
F_27 ( F_17 ( V_74 , & V_35 -> V_20 ) ) ;
F_27 ( F_17 ( V_187 , & V_35 -> V_20 ) ) ;
F_39 ( & V_2 -> V_188 ) ;
F_36 ( & V_35 -> V_186 ) ;
F_29 ( & V_35 -> V_168 ) ;
F_15 ( V_74 , & V_35 -> V_20 ) ;
F_29 ( & V_2 -> V_189 ) ;
F_26 ( V_35 ) ;
if ( F_17 ( V_190 , & V_35 -> V_20 ) )
F_29 ( & V_2 -> V_191 ) ;
else
F_29 ( & V_2 -> V_192 ) ;
F_37 ( V_35 ) ;
}
void F_127 ( struct V_1 * V_2 , int V_193 )
{
int V_168 ;
struct V_34 * V_35 , * V_72 ;
F_39 ( & V_2 -> V_188 ) ;
if ( ! V_2 -> log )
return;
V_168 = 0 ;
F_35 (sh, next, &conf->r5c_full_stripe_list, lru) {
F_126 ( V_2 , V_35 ) ;
V_168 ++ ;
}
if ( V_168 >= V_193 )
return;
F_35 (sh, next,
&conf->r5c_partial_stripe_list, lru) {
F_126 ( V_2 , V_35 ) ;
if ( ++ V_168 >= V_193 )
break;
}
}
static void F_128 ( struct V_1 * V_2 )
{
struct V_6 * log = V_2 -> log ;
struct V_34 * V_35 ;
int V_168 = 0 ;
unsigned long V_39 ;
int V_42 ;
int V_194 ;
int V_195 , V_196 ;
if ( ! F_3 ( log ) )
return;
V_195 = F_19 ( & V_2 -> V_191 ) ;
V_196 = F_19 ( & V_2 -> V_192 ) ;
V_42 = F_19 ( & V_2 -> V_43 ) +
F_19 ( & V_2 -> V_44 ) -
V_196 - V_195 ;
if ( V_42 > V_2 -> V_45 * 3 / 4 ||
F_19 ( & V_2 -> V_46 ) > 0 )
V_194 = V_197 ;
else if ( V_42 > V_2 -> V_45 * 1 / 2 ||
F_19 ( & V_2 -> V_44 ) - V_196 >
V_47 )
V_194 = 0 ;
else
V_194 = - 1 ;
if ( V_194 >= 0 ) {
F_46 ( & V_2 -> V_188 , V_39 ) ;
F_127 ( V_2 , V_194 ) ;
F_50 ( & V_2 -> V_188 , V_39 ) ;
}
if ( F_17 ( V_61 , & V_2 -> V_60 ) ) {
F_46 ( & log -> V_158 , V_39 ) ;
F_93 ( & V_2 -> V_188 ) ;
F_112 (sh, &log->stripe_in_journal_list, r5c) {
if ( ! F_47 ( & V_35 -> V_186 ) &&
! F_17 ( V_74 , & V_35 -> V_20 ) &&
F_19 ( & V_35 -> V_168 ) == 0 ) {
F_126 ( V_2 , V_35 ) ;
if ( V_168 ++ >= V_197 )
break;
}
}
F_94 ( & V_2 -> V_188 ) ;
F_50 ( & log -> V_158 , V_39 ) ;
}
if ( ! F_17 ( V_59 , & V_2 -> V_60 ) )
F_102 ( log ) ;
F_51 ( V_2 -> V_33 -> V_88 ) ;
}
static void F_129 ( struct V_6 * log )
{
struct V_1 * V_2 = log -> V_54 -> V_33 -> V_55 ;
T_1 V_198 = F_130 ( & log -> V_198 , 0 ) ;
T_1 V_199 ;
T_1 V_174 ;
bool V_200 ;
F_81 ( & log -> V_75 ) ;
V_200 = F_104 ( log ) > log -> V_177 ||
V_198 != 0 || ! F_47 ( & log -> V_161 ) ;
while ( 1 ) {
V_199 = F_104 ( log ) ;
if ( V_199 >= V_198 ||
( F_47 ( & log -> V_86 ) &&
F_47 ( & log -> V_79 ) &&
F_47 ( & log -> V_180 ) &&
F_47 ( & log -> V_78 ) ) )
break;
F_51 ( log -> V_54 -> V_33 -> V_88 ) ;
F_131 ( log -> V_178 ,
F_104 ( log ) > V_199 ,
log -> V_75 ) ;
}
V_174 = F_103 ( V_2 ) ;
F_83 ( & log -> V_75 ) ;
if ( V_199 == 0 || ! V_200 )
return;
F_116 ( log , V_174 ) ;
F_98 ( & log -> V_169 ) ;
log -> V_15 = V_174 ;
F_24 ( log ) ;
F_99 ( & log -> V_169 ) ;
F_102 ( log ) ;
}
static void F_132 ( struct V_201 * V_88 )
{
struct V_33 * V_33 = V_88 -> V_33 ;
struct V_1 * V_2 = V_33 -> V_55 ;
struct V_6 * log = V_2 -> log ;
if ( ! log )
return;
F_128 ( V_2 ) ;
F_129 ( log ) ;
}
void F_20 ( struct V_6 * log , T_1 V_202 )
{
unsigned long V_203 ;
unsigned long V_204 = ( unsigned long ) V_202 ;
if ( ! log )
return;
do {
V_203 = log -> V_198 ;
if ( V_204 < V_203 )
return;
} while ( F_133 ( & log -> V_198 , V_203 , V_204 ) != V_203 );
F_51 ( log -> V_205 ) ;
}
void F_134 ( struct V_6 * log , int V_20 )
{
struct V_33 * V_33 ;
if ( ! log || V_20 == 2 )
return;
if ( V_20 == 0 )
F_135 ( log -> V_205 -> V_206 ) ;
else if ( V_20 == 1 ) {
V_33 = log -> V_54 -> V_33 ;
F_108 ( & V_33 -> V_207 ) ;
F_136 ( log -> V_205 -> V_206 ) ;
F_20 ( log , V_156 ) ;
F_129 ( log ) ;
}
}
bool F_137 ( struct V_1 * V_2 )
{
struct V_6 * log ;
bool V_148 ;
F_138 () ;
log = F_139 ( V_2 -> log ) ;
if ( ! log )
V_148 = F_17 ( V_208 , & V_2 -> V_33 -> V_39 ) ;
else
V_148 = F_17 ( V_209 , & log -> V_54 -> V_39 ) ;
F_140 () ;
return V_148 ;
}
static int F_141 ( struct V_6 * log ,
struct V_210 * V_211 )
{
struct V_145 * V_145 = V_211 -> V_83 ;
struct V_105 * V_212 ;
T_2 V_107 , V_213 ;
if ( ! F_142 ( log -> V_54 , V_211 -> V_214 , V_112 , V_145 , V_215 , 0 ,
false ) )
return - V_216 ;
V_212 = F_67 ( V_145 ) ;
V_213 = F_143 ( V_212 -> V_113 ) ;
V_212 -> V_113 = 0 ;
if ( F_143 ( V_212 -> V_127 ) != V_128 ||
F_144 ( V_212 -> V_131 ) != V_211 -> V_131 ||
V_212 -> V_129 != V_130 ||
F_144 ( V_212 -> V_132 ) != V_211 -> V_214 )
return - V_217 ;
V_107 = F_69 ( log -> V_111 , V_212 , V_112 ) ;
if ( V_213 != V_107 )
return - V_217 ;
if ( F_143 ( V_212 -> V_109 ) > V_112 )
return - V_217 ;
V_211 -> V_218 = V_49 ;
return 0 ;
}
static void
F_145 ( struct V_6 * log ,
struct V_145 * V_145 ,
T_1 V_214 , T_4 V_131 )
{
struct V_105 * V_212 ;
V_212 = F_67 ( V_145 ) ;
F_78 ( V_212 ) ;
V_212 -> V_127 = F_68 ( V_128 ) ;
V_212 -> V_129 = V_130 ;
V_212 -> V_109 = F_68 ( sizeof( struct V_105 ) ) ;
V_212 -> V_131 = F_79 ( V_131 ) ;
V_212 -> V_132 = F_79 ( V_214 ) ;
}
static int F_146 ( struct V_6 * log , T_1 V_214 ,
T_4 V_131 )
{
struct V_145 * V_145 ;
struct V_105 * V_212 ;
V_145 = F_147 ( V_219 ) ;
if ( ! V_145 )
return - V_135 ;
F_145 ( log , V_145 , V_214 , V_131 ) ;
V_212 = F_67 ( V_145 ) ;
V_212 -> V_113 = F_68 ( F_69 ( log -> V_111 ,
V_212 , V_112 ) ) ;
if ( ! F_142 ( log -> V_54 , V_214 , V_112 , V_145 , V_117 ,
V_99 , false ) ) {
F_148 ( V_145 ) ;
return - V_216 ;
}
F_148 ( V_145 ) ;
return 0 ;
}
static void F_149 ( struct V_6 * log ,
struct V_34 * V_35 ,
struct V_210 * V_211 ,
struct V_140 * V_141 ,
T_1 V_220 )
{
struct V_33 * V_33 = log -> V_54 -> V_33 ;
struct V_1 * V_2 = V_33 -> V_55 ;
int V_221 ;
F_150 ( V_2 ,
F_144 ( V_141 -> V_136 ) , 0 ,
& V_221 , V_35 ) ;
F_142 ( log -> V_54 , V_220 , V_112 ,
V_35 -> V_22 [ V_221 ] . V_145 , V_215 , 0 , false ) ;
V_35 -> V_22 [ V_221 ] . V_153 =
F_143 ( V_141 -> V_113 [ 0 ] ) ;
V_211 -> V_218 += V_49 ;
F_15 ( V_66 , & V_35 -> V_22 [ V_221 ] . V_39 ) ;
F_15 ( V_63 , & V_35 -> V_20 ) ;
}
static void F_151 ( struct V_6 * log ,
struct V_34 * V_35 ,
struct V_210 * V_211 ,
struct V_140 * V_141 ,
T_1 V_220 )
{
struct V_33 * V_33 = log -> V_54 -> V_33 ;
struct V_1 * V_2 = V_33 -> V_55 ;
V_211 -> V_218 += V_49 * V_2 -> V_50 ;
F_142 ( log -> V_54 , V_220 , V_112 ,
V_35 -> V_22 [ V_35 -> V_71 ] . V_145 , V_215 , 0 , false ) ;
V_35 -> V_22 [ V_35 -> V_71 ] . V_153 =
F_143 ( V_141 -> V_113 [ 0 ] ) ;
F_15 ( V_66 , & V_35 -> V_22 [ V_35 -> V_71 ] . V_39 ) ;
if ( V_35 -> V_150 >= 0 ) {
F_142 ( log -> V_54 ,
F_4 ( log , V_220 , V_49 ) ,
V_112 , V_35 -> V_22 [ V_35 -> V_150 ] . V_145 ,
V_215 , 0 , false ) ;
V_35 -> V_22 [ V_35 -> V_150 ] . V_153 =
F_143 ( V_141 -> V_113 [ 1 ] ) ;
F_15 ( V_66 , & V_35 -> V_22 [ V_35 -> V_150 ] . V_39 ) ;
}
F_25 ( V_63 , & V_35 -> V_20 ) ;
}
static void F_152 ( struct V_34 * V_35 )
{
int V_37 ;
V_35 -> V_20 = 0 ;
V_35 -> V_16 = V_156 ;
for ( V_37 = V_35 -> V_36 ; V_37 -- ; )
V_35 -> V_22 [ V_37 ] . V_39 = 0 ;
}
static void
F_153 ( struct V_1 * V_2 ,
struct V_34 * V_35 ,
struct V_210 * V_211 )
{
struct V_222 * V_54 , * V_223 ;
int V_224 ;
int V_225 = 0 ;
for ( V_224 = 0 ; V_224 < V_35 -> V_36 ; V_224 ++ ) {
if ( ! F_17 ( V_66 , & V_35 -> V_22 [ V_224 ] . V_39 ) )
continue;
if ( V_224 == V_35 -> V_150 || V_224 == V_35 -> V_71 )
continue;
V_225 ++ ;
}
if ( V_225 == 0 )
goto V_226;
for ( V_224 = 0 ; V_224 < V_35 -> V_36 ; V_224 ++ ) {
if ( ! F_17 ( V_66 , & V_35 -> V_22 [ V_224 ] . V_39 ) )
continue;
F_138 () ;
V_54 = F_139 ( V_2 -> V_36 [ V_224 ] . V_54 ) ;
if ( V_54 ) {
F_29 ( & V_54 -> V_227 ) ;
F_140 () ;
F_142 ( V_54 , V_35 -> V_31 , V_112 ,
V_35 -> V_22 [ V_224 ] . V_145 , V_117 , 0 ,
false ) ;
F_154 ( V_54 , V_54 -> V_33 ) ;
F_138 () ;
}
V_223 = F_139 ( V_2 -> V_36 [ V_224 ] . V_228 ) ;
if ( V_223 ) {
F_29 ( & V_223 -> V_227 ) ;
F_140 () ;
F_142 ( V_223 , V_35 -> V_31 , V_112 ,
V_35 -> V_22 [ V_224 ] . V_145 , V_117 , 0 ,
false ) ;
F_154 ( V_223 , V_223 -> V_33 ) ;
F_138 () ;
}
F_140 () ;
}
V_211 -> V_229 ++ ;
V_226:
F_152 ( V_35 ) ;
}
static struct V_34 *
F_155 ( struct V_1 * V_2 ,
T_1 V_230 )
{
struct V_34 * V_35 ;
V_35 = F_156 ( V_2 , V_230 , 0 , 1 , 0 ) ;
if ( ! V_35 )
return NULL ;
F_152 ( V_35 ) ;
return V_35 ;
}
static struct V_34 *
F_157 ( struct V_231 * V_232 , T_1 V_3 )
{
struct V_34 * V_35 ;
F_112 (sh, list, lru)
if ( V_35 -> V_31 == V_3 )
return V_35 ;
return NULL ;
}
static void
F_158 ( struct V_231 * V_233 ,
struct V_210 * V_211 )
{
struct V_34 * V_35 , * V_72 ;
F_35 (sh, next, cached_stripe_list, lru) {
F_152 ( V_35 ) ;
F_36 ( & V_35 -> V_186 ) ;
F_37 ( V_35 ) ;
}
}
static void
F_159 ( struct V_231 * V_233 ,
struct V_210 * V_211 )
{
struct V_34 * V_35 , * V_72 ;
F_35 (sh, next, cached_stripe_list, lru)
if ( ! F_17 ( V_63 , & V_35 -> V_20 ) ) {
F_153 ( V_35 -> V_62 , V_35 , V_211 ) ;
F_36 ( & V_35 -> V_186 ) ;
F_37 ( V_35 ) ;
}
}
static int
F_160 ( struct V_6 * log , struct V_145 * V_145 ,
T_1 V_220 , V_144 V_153 )
{
void * V_166 ;
T_2 V_113 ;
F_142 ( log -> V_54 , V_220 , V_112 ,
V_145 , V_215 , 0 , false ) ;
V_166 = F_96 ( V_145 ) ;
V_113 = F_69 ( log -> V_111 , V_166 , V_112 ) ;
F_97 ( V_166 ) ;
return ( F_143 ( V_153 ) == V_113 ) ? 0 : - V_217 ;
}
static int
F_161 ( struct V_6 * log ,
struct V_210 * V_211 )
{
struct V_33 * V_33 = log -> V_54 -> V_33 ;
struct V_1 * V_2 = V_33 -> V_55 ;
struct V_105 * V_212 = F_67 ( V_211 -> V_83 ) ;
T_1 V_234 = sizeof( struct V_105 ) ;
T_1 V_220 = F_4 ( log , V_211 -> V_214 , V_49 ) ;
struct V_145 * V_145 ;
struct V_140 * V_141 ;
V_145 = F_147 ( V_219 ) ;
if ( ! V_145 )
return - V_135 ;
while ( V_234 < F_143 ( V_212 -> V_109 ) ) {
V_141 = ( void * ) V_212 + V_234 ;
if ( V_141 -> V_142 . type == V_152 ) {
if ( F_160 (
log , V_145 , V_220 ,
V_141 -> V_113 [ 0 ] ) < 0 )
goto V_235;
} else if ( V_141 -> V_142 . type == V_154 ) {
if ( F_160 (
log , V_145 , V_220 ,
V_141 -> V_113 [ 0 ] ) < 0 )
goto V_235;
if ( V_2 -> V_50 == 2 &&
F_160 (
log , V_145 ,
F_4 ( log , V_220 ,
V_49 ) ,
V_141 -> V_113 [ 1 ] ) < 0 )
goto V_235;
} else
goto V_235;
V_220 = F_4 ( log , V_220 ,
F_143 ( V_141 -> V_13 ) ) ;
V_234 += sizeof( struct V_140 ) +
sizeof( V_144 ) *
( F_143 ( V_141 -> V_13 ) >> ( V_143 - 9 ) ) ;
}
F_162 ( V_145 ) ;
return 0 ;
V_235:
F_162 ( V_145 ) ;
return - V_217 ;
}
static int
F_163 ( struct V_6 * log ,
struct V_210 * V_211 ,
struct V_231 * V_233 )
{
struct V_33 * V_33 = log -> V_54 -> V_33 ;
struct V_1 * V_2 = V_33 -> V_55 ;
struct V_105 * V_212 ;
struct V_140 * V_141 ;
int V_234 ;
T_1 V_220 ;
T_1 V_230 ;
struct V_34 * V_35 ;
int V_148 ;
V_148 = F_161 ( log , V_211 ) ;
if ( V_148 == - V_217 )
return - V_164 ;
else if ( V_148 )
return V_148 ;
V_212 = F_67 ( V_211 -> V_83 ) ;
V_234 = sizeof( struct V_105 ) ;
V_220 = F_4 ( log , V_211 -> V_214 , V_49 ) ;
while ( V_234 < F_143 ( V_212 -> V_109 ) ) {
int V_236 ;
V_141 = ( void * ) V_212 + V_234 ;
V_230 = ( V_141 -> V_142 . type == V_152 ) ?
F_150 (
V_2 , F_144 ( V_141 -> V_136 ) , 0 , & V_236 ,
NULL )
: F_144 ( V_141 -> V_136 ) ;
V_35 = F_157 ( V_233 ,
V_230 ) ;
if ( ! V_35 ) {
V_35 = F_155 ( V_2 , V_230 ) ;
if ( ! V_35 ) {
F_159 (
V_233 , V_211 ) ;
V_35 = F_155 (
V_2 , V_230 ) ;
}
if ( ! V_35 ) {
F_164 ( L_2 ,
F_63 ( V_33 ) ,
V_2 -> V_45 * 2 ) ;
F_165 ( V_33 ,
V_2 -> V_45 * 2 ) ;
V_35 = F_155 ( V_2 ,
V_230 ) ;
}
if ( ! V_35 ) {
F_166 ( L_3 ,
F_63 ( V_33 ) ) ;
return - V_135 ;
}
F_82 ( & V_35 -> V_186 , V_233 ) ;
}
if ( V_141 -> V_142 . type == V_152 ) {
if ( ! F_17 ( V_63 , & V_35 -> V_20 ) &&
F_17 ( V_66 , & V_35 -> V_22 [ V_35 -> V_71 ] . V_39 ) ) {
F_153 ( V_2 , V_35 , V_211 ) ;
F_40 ( & V_35 -> V_186 , V_233 ) ;
}
F_149 ( log , V_35 , V_211 , V_141 ,
V_220 ) ;
} else if ( V_141 -> V_142 . type == V_154 )
F_151 ( log , V_35 , V_211 , V_141 ,
V_220 ) ;
else
return - V_217 ;
V_220 = F_4 ( log , V_220 ,
F_143 ( V_141 -> V_13 ) ) ;
V_234 += sizeof( struct V_140 ) +
sizeof( V_144 ) *
( F_143 ( V_141 -> V_13 ) >> ( V_143 - 9 ) ) ;
}
return 0 ;
}
static void F_167 ( struct V_6 * log ,
struct V_34 * V_35 )
{
struct V_21 * V_22 ;
int V_37 ;
for ( V_37 = V_35 -> V_36 ; V_37 -- ; ) {
V_22 = V_35 -> V_22 + V_37 ;
if ( F_31 ( V_66 , & V_22 -> V_39 ) ) {
F_15 ( V_67 , & V_22 -> V_39 ) ;
F_15 ( V_38 , & V_22 -> V_39 ) ;
}
}
}
static int F_168 ( struct V_6 * log ,
struct V_210 * V_211 )
{
struct V_34 * V_35 ;
int V_148 = 0 ;
while ( 1 ) {
if ( F_141 ( log , V_211 ) )
break;
V_148 = F_163 ( log , V_211 ,
& V_211 -> V_237 ) ;
if ( V_148 && V_148 != - V_164 )
break;
V_211 -> V_131 ++ ;
V_211 -> V_214 = F_4 ( log , V_211 -> V_214 , V_211 -> V_218 ) ;
}
if ( V_148 == - V_135 ) {
F_158 ( & V_211 -> V_237 , V_211 ) ;
return V_148 ;
}
F_159 ( & V_211 -> V_237 , V_211 ) ;
F_112 (sh, &ctx->cached_list, lru) {
F_8 ( ! F_17 ( V_63 , & V_35 -> V_20 ) ) ;
F_167 ( log , V_35 ) ;
V_211 -> V_238 ++ ;
}
return 0 ;
}
static int
F_169 ( struct V_6 * log ,
struct V_210 * V_211 )
{
struct V_34 * V_35 ;
struct V_33 * V_33 = log -> V_54 -> V_33 ;
struct V_145 * V_145 ;
T_1 V_174 = V_156 ;
V_145 = F_147 ( V_219 ) ;
if ( ! V_145 ) {
F_166 ( L_4 ,
F_63 ( V_33 ) ) ;
return - V_135 ;
}
F_8 ( F_47 ( & V_211 -> V_237 ) ) ;
F_112 (sh, &ctx->cached_list, lru) {
struct V_105 * V_212 ;
int V_37 ;
int V_4 ;
T_1 V_239 ;
F_8 ( ! F_17 ( V_63 , & V_35 -> V_20 ) ) ;
F_145 ( log , V_145 ,
V_211 -> V_214 , V_211 -> V_131 ) ;
V_212 = F_67 ( V_145 ) ;
V_4 = F_143 ( V_212 -> V_109 ) ;
V_239 = F_4 ( log , V_211 -> V_214 , V_49 ) ;
for ( V_37 = V_35 -> V_36 ; V_37 -- ; ) {
struct V_21 * V_22 = & V_35 -> V_22 [ V_37 ] ;
struct V_140 * V_141 ;
void * V_166 ;
if ( F_17 ( V_67 , & V_22 -> V_39 ) ) {
V_141 = ( void * ) V_212 + V_4 ;
V_141 -> V_142 . type = F_86 (
V_152 ) ;
V_141 -> V_13 = V_49 ;
V_141 -> V_136 = F_79 (
F_91 ( V_35 , V_37 , 0 ) ) ;
V_166 = F_96 ( V_22 -> V_145 ) ;
V_141 -> V_113 [ 0 ] = F_68 (
F_69 ( log -> V_111 , V_166 ,
V_112 ) ) ;
F_97 ( V_166 ) ;
F_142 ( log -> V_54 , V_239 , V_112 ,
V_22 -> V_145 , V_117 , 0 , false ) ;
V_239 = F_4 ( log , V_239 ,
V_49 ) ;
V_4 += sizeof( V_144 ) +
sizeof( struct V_140 ) ;
}
}
V_212 -> V_109 = F_68 ( V_4 ) ;
V_212 -> V_113 = F_68 ( F_69 ( log -> V_111 ,
V_212 , V_112 ) ) ;
F_142 ( log -> V_54 , V_211 -> V_214 , V_112 , V_145 ,
V_117 , V_99 , false ) ;
V_35 -> V_16 = V_211 -> V_214 ;
F_82 ( & V_35 -> V_157 , & log -> V_159 ) ;
F_29 ( & log -> V_51 ) ;
V_211 -> V_214 = V_239 ;
V_211 -> V_131 += 1 ;
V_174 = V_35 -> V_16 ;
}
log -> V_174 = V_174 ;
F_148 ( V_145 ) ;
return 0 ;
}
static void F_170 ( struct V_6 * log ,
struct V_210 * V_211 )
{
struct V_33 * V_33 = log -> V_54 -> V_33 ;
struct V_1 * V_2 = V_33 -> V_55 ;
struct V_34 * V_35 , * V_72 ;
if ( V_211 -> V_238 == 0 )
return;
log -> V_7 = V_8 ;
F_35 (sh, next, &ctx->cached_list, lru) {
F_26 ( V_35 ) ;
F_15 ( V_74 , & V_35 -> V_20 ) ;
F_36 ( & V_35 -> V_186 ) ;
F_37 ( V_35 ) ;
}
F_51 ( V_2 -> V_33 -> V_88 ) ;
F_171 ( V_2 -> V_240 ,
F_19 ( & V_2 -> V_189 ) == 0 ) ;
log -> V_7 = V_70 ;
}
static int F_172 ( struct V_6 * log )
{
struct V_33 * V_33 = log -> V_54 -> V_33 ;
struct V_210 V_211 ;
int V_148 ;
T_1 V_214 ;
V_211 . V_214 = log -> V_15 ;
V_211 . V_131 = log -> V_241 ;
V_211 . V_83 = F_147 ( V_219 ) ;
V_211 . V_238 = 0 ;
V_211 . V_229 = 0 ;
F_76 ( & V_211 . V_237 ) ;
if ( ! V_211 . V_83 )
return - V_135 ;
V_148 = F_168 ( log , & V_211 ) ;
F_148 ( V_211 . V_83 ) ;
if ( V_148 )
return V_148 ;
V_214 = V_211 . V_214 ;
V_211 . V_131 += 10000 ;
if ( ( V_211 . V_238 == 0 ) && ( V_211 . V_229 == 0 ) )
F_164 ( L_5 ,
F_63 ( V_33 ) ) ;
else
F_164 ( L_6 ,
F_63 ( V_33 ) , V_211 . V_238 ,
V_211 . V_229 ) ;
if ( V_211 . V_238 == 0 ) {
log -> V_174 = V_211 . V_214 ;
F_146 ( log , V_211 . V_214 , V_211 . V_131 ++ ) ;
V_211 . V_214 = F_4 ( log , V_211 . V_214 , V_49 ) ;
} else if ( F_169 ( log , & V_211 ) ) {
F_166 ( L_7 ,
F_63 ( V_33 ) ) ;
return - V_216 ;
}
log -> V_16 = V_211 . V_214 ;
log -> V_131 = V_211 . V_131 ;
log -> V_15 = V_214 ;
F_117 ( log , V_214 ) ;
F_170 ( log , & V_211 ) ;
return 0 ;
}
static void F_117 ( struct V_6 * log , T_1 V_242 )
{
struct V_33 * V_33 = log -> V_54 -> V_33 ;
log -> V_54 -> V_243 = V_242 ;
F_15 ( V_184 , & V_33 -> V_183 ) ;
}
static T_5 F_173 ( struct V_33 * V_33 , char * V_145 )
{
struct V_1 * V_2 = V_33 -> V_55 ;
int V_148 ;
if ( ! V_2 -> log )
return 0 ;
switch ( V_2 -> log -> V_7 ) {
case V_70 :
V_148 = snprintf (
V_145 , V_112 , L_8 ,
V_244 [ V_70 ] ,
V_244 [ V_8 ] ) ;
break;
case V_8 :
V_148 = snprintf (
V_145 , V_112 , L_9 ,
V_244 [ V_70 ] ,
V_244 [ V_8 ] ) ;
break;
default:
V_148 = 0 ;
}
return V_148 ;
}
static T_5 F_174 ( struct V_33 * V_33 ,
const char * V_145 , T_6 V_245 )
{
struct V_1 * V_2 = V_33 -> V_55 ;
struct V_6 * log = V_2 -> log ;
int V_246 = - 1 , V_37 ;
int V_247 = V_245 ;
if ( ! log )
return - V_171 ;
if ( V_247 && V_145 [ V_247 - 1 ] == '\n' )
V_247 -= 1 ;
for ( V_37 = 0 ; V_37 < F_175 ( V_244 ) ; V_37 ++ )
if ( strlen ( V_244 [ V_37 ] ) == V_247 &&
strncmp ( V_145 , V_244 [ V_37 ] , V_247 ) == 0 ) {
V_246 = V_37 ;
break;
}
if ( V_246 < V_70 ||
V_246 > V_8 )
return - V_217 ;
if ( F_176 ( V_2 ) > 0 &&
V_246 == V_8 )
return - V_217 ;
F_64 ( V_33 ) ;
V_2 -> log -> V_7 = V_246 ;
F_65 ( V_33 ) ;
F_164 ( L_10 ,
F_63 ( V_33 ) , V_246 , V_244 [ V_246 ] ) ;
return V_245 ;
}
int F_177 ( struct V_1 * V_2 ,
struct V_34 * V_35 ,
struct V_248 * V_249 ,
int V_36 )
{
struct V_6 * log = V_2 -> log ;
int V_37 ;
struct V_21 * V_22 ;
int V_250 = 0 ;
void * * V_251 ;
T_1 V_252 ;
int V_148 ;
T_7 V_253 ;
F_27 ( ! F_3 ( log ) ) ;
if ( ! F_17 ( V_63 , & V_35 -> V_20 ) ) {
if ( V_249 -> V_254 > 0 || V_249 -> V_28 > 0 )
return - V_164 ;
F_15 ( V_63 , & V_35 -> V_20 ) ;
}
if ( V_249 -> V_255 ) {
F_26 ( V_35 ) ;
return - V_164 ;
}
for ( V_37 = V_36 ; V_37 -- ; ) {
V_22 = & V_35 -> V_22 [ V_37 ] ;
if ( V_22 -> V_256 && ! F_17 ( V_257 , & V_22 -> V_39 ) &&
! F_17 ( V_67 , & V_22 -> V_39 ) ) {
F_26 ( V_35 ) ;
return - V_164 ;
}
}
if ( ! F_17 ( V_190 , & V_35 -> V_20 ) &&
! F_17 ( V_258 , & V_35 -> V_20 ) ) {
V_252 = F_1 ( V_2 , V_35 -> V_31 ) ;
F_93 ( & log -> V_259 ) ;
V_251 = F_178 ( & log -> V_260 ,
V_252 ) ;
if ( V_251 ) {
V_253 = ( T_7 ) F_179 (
V_251 , & log -> V_259 ) >>
V_261 ;
F_180 (
& log -> V_260 , V_251 ,
( void * ) ( ( V_253 + 1 ) << V_261 ) ) ;
} else {
V_148 = F_181 (
& log -> V_260 , V_252 ,
( void * ) ( 1 << V_261 ) ) ;
if ( V_148 ) {
F_94 ( & log -> V_259 ) ;
F_26 ( V_35 ) ;
return - V_164 ;
}
}
F_94 ( & log -> V_259 ) ;
F_15 ( V_190 , & V_35 -> V_20 ) ;
F_29 ( & V_2 -> V_43 ) ;
}
for ( V_37 = V_36 ; V_37 -- ; ) {
V_22 = & V_35 -> V_22 [ V_37 ] ;
if ( V_22 -> V_256 ) {
F_15 ( V_66 , & V_22 -> V_39 ) ;
F_15 ( V_262 , & V_22 -> V_39 ) ;
F_15 ( V_68 , & V_22 -> V_39 ) ;
V_250 ++ ;
}
}
if ( V_250 ) {
F_15 ( V_263 , & V_249 -> V_264 ) ;
F_15 ( V_69 , & V_35 -> V_20 ) ;
}
return 0 ;
}
void F_182 ( struct V_34 * V_35 )
{
struct V_1 * V_2 = V_35 -> V_62 ;
int V_37 ;
bool V_265 ;
V_265 =
V_35 -> V_22 [ 0 ] . V_266 == V_2 -> V_36 [ 0 ] . V_267 ;
for ( V_37 = V_35 -> V_36 ; V_37 -- ; )
if ( V_35 -> V_22 [ V_37 ] . V_145 != V_35 -> V_22 [ V_37 ] . V_266 ) {
struct V_145 * V_268 = V_35 -> V_22 [ V_37 ] . V_266 ;
V_35 -> V_22 [ V_37 ] . V_266 = V_35 -> V_22 [ V_37 ] . V_145 ;
F_25 ( V_269 , & V_35 -> V_22 [ V_37 ] . V_39 ) ;
if ( ! V_265 )
F_162 ( V_268 ) ;
}
if ( V_265 ) {
F_25 ( V_270 , & V_2 -> V_60 ) ;
F_51 ( V_2 -> V_33 -> V_88 ) ;
}
}
void F_183 ( struct V_34 * V_35 )
{
struct V_1 * V_2 = V_35 -> V_62 ;
int V_37 ;
struct V_21 * V_22 ;
for ( V_37 = V_35 -> V_36 ; V_37 -- ; ) {
V_22 = & V_35 -> V_22 [ V_37 ] ;
if ( V_22 -> V_266 != V_22 -> V_145 )
F_162 ( V_22 -> V_266 ) ;
V_22 -> V_266 = V_2 -> V_36 [ V_37 ] . V_267 ;
}
}
void F_184 ( struct V_1 * V_2 ,
struct V_34 * V_35 ,
struct V_248 * V_249 )
{
struct V_6 * log = V_2 -> log ;
int V_37 ;
int V_271 = 0 ;
T_1 V_252 ;
void * * V_251 ;
T_7 V_253 ;
if ( ! log || ! F_17 ( V_67 , & V_35 -> V_22 [ V_35 -> V_71 ] . V_39 ) )
return;
F_8 ( F_17 ( V_63 , & V_35 -> V_20 ) ) ;
F_25 ( V_67 , & V_35 -> V_22 [ V_35 -> V_71 ] . V_39 ) ;
if ( log -> V_7 == V_70 )
return;
for ( V_37 = V_35 -> V_36 ; V_37 -- ; ) {
F_25 ( V_67 , & V_35 -> V_22 [ V_37 ] . V_39 ) ;
if ( F_31 ( V_272 , & V_35 -> V_22 [ V_37 ] . V_39 ) )
V_271 = 1 ;
}
V_249 -> V_254 = 0 ;
if ( F_31 ( V_273 , & V_35 -> V_20 ) )
if ( F_110 ( & V_2 -> V_274 ) )
F_51 ( V_2 -> V_33 -> V_88 ) ;
if ( V_271 )
F_108 ( & V_2 -> V_275 ) ;
F_81 ( & log -> V_158 ) ;
F_36 ( & V_35 -> V_157 ) ;
F_83 ( & log -> V_158 ) ;
V_35 -> V_16 = V_156 ;
F_55 ( & log -> V_51 ) ;
F_24 ( log ) ;
if ( F_17 ( V_190 , & V_35 -> V_20 ) ||
F_17 ( V_258 , & V_35 -> V_20 ) ) {
V_252 = F_1 ( V_2 , V_35 -> V_31 ) ;
F_93 ( & log -> V_259 ) ;
V_251 = F_178 ( & log -> V_260 ,
V_252 ) ;
F_27 ( V_251 == NULL ) ;
V_253 = ( T_7 ) F_179 (
V_251 , & log -> V_259 ) >>
V_261 ;
if ( V_253 == 1 )
F_185 ( & log -> V_260 , V_252 ) ;
else
F_180 (
& log -> V_260 , V_251 ,
( void * ) ( ( V_253 - 1 ) << V_261 ) ) ;
F_94 ( & log -> V_259 ) ;
}
if ( F_31 ( V_190 , & V_35 -> V_20 ) ) {
F_27 ( F_19 ( & V_2 -> V_43 ) == 0 ) ;
F_55 ( & V_2 -> V_191 ) ;
F_55 ( & V_2 -> V_43 ) ;
}
if ( F_31 ( V_258 , & V_35 -> V_20 ) ) {
F_27 ( F_19 ( & V_2 -> V_44 ) == 0 ) ;
F_55 ( & V_2 -> V_192 ) ;
F_55 ( & V_2 -> V_44 ) ;
}
}
int
F_186 ( struct V_6 * log , struct V_34 * V_35 ,
struct V_248 * V_249 )
{
struct V_1 * V_2 = V_35 -> V_62 ;
int V_276 = 0 ;
int V_163 ;
int V_37 ;
int V_148 = 0 ;
F_27 ( ! log ) ;
for ( V_37 = 0 ; V_37 < V_35 -> V_36 ; V_37 ++ ) {
void * V_166 ;
if ( ! F_17 ( V_66 , & V_35 -> V_22 [ V_37 ] . V_39 ) )
continue;
V_166 = F_96 ( V_35 -> V_22 [ V_37 ] . V_145 ) ;
V_35 -> V_22 [ V_37 ] . V_153 = F_69 ( log -> V_111 ,
V_166 , V_112 ) ;
F_97 ( V_166 ) ;
V_276 ++ ;
}
F_8 ( V_276 == 0 ) ;
F_25 ( V_167 , & V_35 -> V_20 ) ;
F_29 ( & V_35 -> V_168 ) ;
F_98 ( & log -> V_169 ) ;
V_163 = ( 1 + V_276 ) << ( V_143 - 9 ) ;
if ( F_17 ( V_59 , & V_2 -> V_60 ) &&
V_35 -> V_16 == V_156 )
F_92 ( log , V_35 ) ;
else if ( ! F_6 ( log , V_163 ) ) {
if ( V_35 -> V_16 == log -> V_15 )
F_89 () ;
else
F_92 ( log , V_35 ) ;
} else {
V_148 = F_90 ( log , V_35 , V_276 , 0 ) ;
if ( V_148 ) {
F_81 ( & log -> V_75 ) ;
F_82 ( & V_35 -> V_73 , & log -> V_170 ) ;
F_83 ( & log -> V_75 ) ;
}
}
F_99 ( & log -> V_169 ) ;
return 0 ;
}
bool F_187 ( struct V_1 * V_2 , T_1 V_3 )
{
struct V_6 * log = V_2 -> log ;
T_1 V_252 ;
void * V_277 ;
if ( ! log )
return false ;
F_188 ( ! F_189 () ) ;
V_252 = F_1 ( V_2 , V_3 ) ;
V_277 = F_190 ( & log -> V_260 , V_252 ) ;
return V_277 != NULL ;
}
static int F_191 ( struct V_6 * log )
{
struct V_222 * V_54 = log -> V_54 ;
struct V_145 * V_145 ;
struct V_105 * V_212 ;
T_1 V_242 = log -> V_54 -> V_243 ;
T_2 V_213 , V_278 ;
bool V_279 = false ;
int V_148 = 0 ;
if ( V_242 >= V_54 -> V_280 || F_192 ( V_242 , V_49 ) != V_242 )
V_242 = 0 ;
V_145 = F_147 ( V_219 ) ;
if ( ! V_145 )
return - V_135 ;
if ( ! F_142 ( V_54 , V_242 , V_112 , V_145 , V_215 , 0 , false ) ) {
V_148 = - V_216 ;
goto V_281;
}
V_212 = F_67 ( V_145 ) ;
if ( F_143 ( V_212 -> V_127 ) != V_128 ||
V_212 -> V_129 != V_130 ) {
V_279 = true ;
goto V_282;
}
V_213 = F_143 ( V_212 -> V_113 ) ;
V_212 -> V_113 = 0 ;
V_278 = F_69 ( log -> V_111 , V_212 , V_112 ) ;
if ( V_213 != V_278 ) {
V_279 = true ;
goto V_282;
}
if ( F_144 ( V_212 -> V_132 ) != V_242 ) {
V_279 = true ;
goto V_282;
}
V_282:
if ( V_279 ) {
log -> V_241 = F_193 () ;
V_242 = 0 ;
F_146 ( log , V_242 , log -> V_241 ) ;
F_117 ( log , V_242 ) ;
} else
log -> V_241 = F_144 ( V_212 -> V_131 ) ;
log -> V_11 = F_192 ( V_54 -> V_280 , V_49 ) ;
log -> V_177 = log -> V_11 >> V_283 ;
if ( log -> V_177 > V_284 )
log -> V_177 = V_284 ;
log -> V_15 = V_242 ;
F_148 ( V_145 ) ;
if ( V_279 ) {
log -> V_16 = F_4 ( log , V_242 , V_49 ) ;
log -> V_131 = log -> V_241 + 1 ;
log -> V_174 = V_242 ;
} else
V_148 = F_172 ( log ) ;
F_24 ( log ) ;
return V_148 ;
V_281:
F_148 ( V_145 ) ;
return V_148 ;
}
void F_194 ( struct V_33 * V_33 )
{
struct V_1 * V_2 = V_33 -> V_55 ;
struct V_6 * log = V_2 -> log ;
if ( ! log )
return;
if ( F_176 ( V_2 ) > 0 &&
V_2 -> log -> V_7 == V_8 )
F_49 ( & log -> V_103 ) ;
}
int F_195 ( struct V_1 * V_2 , struct V_222 * V_54 )
{
struct V_285 * V_286 = F_119 ( V_54 -> V_119 ) ;
struct V_6 * log ;
if ( V_112 != 4096 )
return - V_217 ;
if ( sizeof( struct V_105 ) +
( ( sizeof( struct V_140 ) + sizeof( V_144 ) ) *
V_2 -> V_52 ) > V_112 ) {
F_166 ( L_11 ,
F_63 ( V_2 -> V_33 ) , V_2 -> V_52 ) ;
return - V_217 ;
}
log = F_196 ( sizeof( * log ) , V_219 ) ;
if ( ! log )
return - V_135 ;
log -> V_54 = V_54 ;
log -> V_85 = F_17 ( V_287 , & V_286 -> V_288 ) != 0 ;
log -> V_111 = F_69 ( ~ 0 , V_54 -> V_33 -> V_289 ,
sizeof( V_54 -> V_33 -> V_289 ) ) ;
F_197 ( & log -> V_169 ) ;
F_198 ( & log -> V_75 ) ;
F_76 ( & log -> V_86 ) ;
F_76 ( & log -> V_79 ) ;
F_76 ( & log -> V_180 ) ;
F_76 ( & log -> V_78 ) ;
F_199 ( & log -> V_179 , NULL , 0 ) ;
log -> V_290 = F_200 ( V_17 , 0 ) ;
if ( ! log -> V_290 )
goto V_290;
log -> V_123 = F_201 ( V_291 , log -> V_290 ) ;
if ( ! log -> V_123 )
goto V_123;
log -> V_116 = F_202 ( V_291 , 0 ) ;
if ( ! log -> V_116 )
goto V_292;
log -> V_84 = F_203 ( V_291 , 0 ) ;
if ( ! log -> V_84 )
goto V_293;
F_198 ( & log -> V_259 ) ;
F_204 ( & log -> V_260 , V_294 | V_295 ) ;
log -> V_205 = F_205 ( F_132 ,
log -> V_54 -> V_33 , L_12 ) ;
if ( ! log -> V_205 )
goto V_205;
log -> V_205 -> V_296 = V_297 ;
F_206 ( & log -> V_178 ) ;
F_76 ( & log -> V_170 ) ;
F_76 ( & log -> V_161 ) ;
F_198 ( & log -> V_160 ) ;
F_207 ( & log -> V_87 , F_59 ) ;
F_207 ( & log -> V_103 , F_61 ) ;
log -> V_7 = V_70 ;
F_76 ( & log -> V_159 ) ;
F_198 ( & log -> V_158 ) ;
F_208 ( & log -> V_51 , 0 ) ;
F_209 ( V_2 -> log , log ) ;
if ( F_191 ( log ) )
goto error;
F_15 ( V_208 , & V_2 -> V_33 -> V_39 ) ;
return 0 ;
error:
F_209 ( V_2 -> log , NULL ) ;
F_210 ( & log -> V_205 ) ;
V_205:
F_211 ( log -> V_84 ) ;
V_293:
F_212 ( log -> V_116 ) ;
V_292:
F_211 ( log -> V_123 ) ;
V_123:
F_213 ( log -> V_290 ) ;
V_290:
F_214 ( log ) ;
return - V_217 ;
}
void F_215 ( struct V_6 * log )
{
F_216 ( & log -> V_103 ) ;
F_210 ( & log -> V_205 ) ;
F_211 ( log -> V_84 ) ;
F_212 ( log -> V_116 ) ;
F_211 ( log -> V_123 ) ;
F_213 ( log -> V_290 ) ;
F_214 ( log ) ;
}
