bool F_1 ( struct V_1 * log )
{
return ( log != NULL &&
log -> V_2 == V_3 ) ;
}
static T_1 F_2 ( struct V_1 * log , T_1 V_4 , T_1 V_5 )
{
V_4 += V_5 ;
if ( V_4 >= log -> V_6 )
V_4 = V_4 - log -> V_6 ;
return V_4 ;
}
static T_1 F_3 ( struct V_1 * log , T_1 V_4 ,
T_1 V_7 )
{
if ( V_7 >= V_4 )
return V_7 - V_4 ;
else
return V_7 + log -> V_6 - V_4 ;
}
static bool F_4 ( struct V_1 * log , T_1 V_8 )
{
T_1 V_9 ;
V_9 = F_3 ( log , log -> V_10 ,
log -> V_11 ) ;
return log -> V_6 > V_9 + V_8 ;
}
static void F_5 ( struct V_12 * V_13 ,
enum V_14 V_15 )
{
if ( F_6 ( V_13 -> V_15 >= V_15 ) )
return;
V_13 -> V_15 = V_15 ;
}
static void
F_7 ( struct V_16 * V_17 , struct V_18 * V_19 ,
struct V_20 * V_21 )
{
struct V_22 * V_23 , * V_24 ;
V_23 = V_19 -> V_25 ;
V_19 -> V_25 = NULL ;
while ( V_23 && V_23 -> V_26 . V_27 <
V_19 -> V_28 + V_29 ) {
V_24 = F_8 ( V_23 , V_19 -> V_28 ) ;
if ( ! F_9 ( V_23 ) ) {
F_10 ( V_17 -> V_30 ) ;
F_11 ( V_21 , V_23 ) ;
}
V_23 = V_24 ;
}
}
void F_12 ( struct V_16 * V_17 ,
struct V_31 * V_32 , int V_33 , struct V_20 * V_21 )
{
int V_34 ;
for ( V_34 = V_32 -> V_33 ; V_34 -- ; ) {
if ( V_32 -> V_19 [ V_34 ] . V_25 ) {
F_13 ( V_35 , & V_32 -> V_19 [ V_34 ] . V_36 ) ;
F_7 ( V_17 , & V_32 -> V_19 [ V_34 ] ,
V_21 ) ;
F_14 ( V_17 -> V_30 -> V_37 , V_32 -> V_28 ,
V_29 ,
! F_15 ( V_38 , & V_32 -> V_15 ) ,
0 ) ;
}
}
}
void F_16 ( struct V_16 * V_17 )
{
int V_39 ;
if ( ! F_1 ( V_17 -> log ) )
return;
V_39 = F_17 ( & V_17 -> V_40 ) +
F_17 ( & V_17 -> V_41 ) ;
if ( V_39 > V_17 -> V_42 * 1 / 2 ||
F_17 ( & V_17 -> V_43 ) > 0 )
F_18 ( V_17 -> log , 0 ) ;
}
void F_19 ( struct V_16 * V_17 )
{
if ( ! F_1 ( V_17 -> log ) )
return;
if ( F_17 ( & V_17 -> V_41 ) >=
F_20 ( V_44 ,
V_17 -> V_45 >> V_46 ) )
F_18 ( V_17 -> log , 0 ) ;
}
static T_1 F_21 ( struct V_16 * V_17 )
{
struct V_1 * log = V_17 -> log ;
if ( ! F_1 ( log ) )
return 0 ;
return V_47 * ( V_17 -> V_48 + 1 ) *
F_17 ( & log -> V_49 ) ;
}
static inline void F_22 ( struct V_1 * log )
{
struct V_16 * V_17 = log -> V_50 -> V_30 -> V_51 ;
T_1 V_52 ;
T_1 V_53 ;
bool V_54 = false ;
if ( ! F_1 ( log ) )
return;
V_52 = F_3 ( log , log -> V_11 ,
log -> V_10 ) ;
V_53 = F_21 ( V_17 ) ;
if ( V_52 < 2 * V_53 )
F_13 ( V_55 , & V_17 -> V_56 ) ;
else {
if ( F_15 ( V_55 , & V_17 -> V_56 ) )
V_54 = true ;
F_23 ( V_55 , & V_17 -> V_56 ) ;
}
if ( V_52 < 3 * V_53 )
F_13 ( V_57 , & V_17 -> V_56 ) ;
else
F_23 ( V_57 , & V_17 -> V_56 ) ;
if ( V_54 )
F_18 ( log , 0 ) ;
}
void F_24 ( struct V_31 * V_32 )
{
struct V_16 * V_17 = V_32 -> V_58 ;
struct V_1 * log = V_17 -> log ;
F_25 ( ! F_1 ( log ) ) ;
F_6 ( ! F_15 ( V_59 , & V_32 -> V_15 ) ) ;
F_23 ( V_59 , & V_32 -> V_15 ) ;
if ( ! F_26 ( V_60 , & V_32 -> V_15 ) )
F_27 ( & V_17 -> V_61 ) ;
if ( F_28 ( V_62 , & V_32 -> V_15 ) ) {
F_25 ( F_17 ( & V_17 -> V_40 ) == 0 ) ;
F_29 ( & V_17 -> V_40 ) ;
}
if ( F_28 ( V_63 , & V_32 -> V_15 ) ) {
F_25 ( F_17 ( & V_17 -> V_41 ) == 0 ) ;
F_29 ( & V_17 -> V_41 ) ;
}
}
static void F_30 ( struct V_31 * V_32 )
{
int V_34 ;
for ( V_34 = V_32 -> V_33 ; V_34 -- ; )
if ( F_28 ( V_64 , & V_32 -> V_19 [ V_34 ] . V_36 ) ) {
F_13 ( V_65 , & V_32 -> V_19 [ V_34 ] . V_36 ) ;
F_23 ( V_66 , & V_32 -> V_19 [ V_34 ] . V_36 ) ;
}
F_23 ( V_67 , & V_32 -> V_15 ) ;
}
static void F_31 ( struct V_31 * V_32 )
{
int V_34 ;
for ( V_34 = V_32 -> V_33 ; V_34 -- ; )
if ( F_15 ( V_65 , & V_32 -> V_19 [ V_34 ] . V_36 ) )
F_13 ( V_64 , & V_32 -> V_19 [ V_34 ] . V_36 ) ;
}
static void F_32 ( struct V_31 * V_32 )
{
struct V_1 * log = V_32 -> V_58 -> log ;
if ( log -> V_2 == V_68 ) {
F_25 ( F_15 ( V_59 , & V_32 -> V_15 ) ) ;
F_13 ( V_65 , & V_32 -> V_19 [ V_32 -> V_69 ] . V_36 ) ;
} else if ( F_15 ( V_59 , & V_32 -> V_15 ) ) {
F_30 ( V_32 ) ;
} else {
F_31 ( V_32 ) ;
F_13 ( V_65 , & V_32 -> V_19 [ V_32 -> V_69 ] . V_36 ) ;
}
}
static void F_33 ( struct V_12 * V_13 )
{
struct V_31 * V_32 , * V_70 ;
F_34 (sh, next, &io->stripe_list, log_list) {
F_35 ( & V_32 -> V_71 ) ;
F_32 ( V_32 ) ;
F_13 ( V_72 , & V_32 -> V_15 ) ;
F_36 ( V_32 ) ;
}
}
static void F_37 ( struct V_1 * log )
{
struct V_12 * V_13 , * V_70 ;
F_38 ( & log -> V_73 ) ;
F_34 (io, next, &log->running_ios, log_sibling) {
if ( V_13 -> V_15 < V_74 )
break;
F_39 ( & V_13 -> V_75 , & log -> V_76 ) ;
F_33 ( V_13 ) ;
}
}
static void F_40 ( struct V_1 * log )
{
struct V_12 * V_13 , * V_70 ;
F_38 ( & log -> V_73 ) ;
F_34 (io, next, &log->running_ios, log_sibling) {
if ( V_13 -> V_15 < V_74 )
break;
F_39 ( & V_13 -> V_75 , & log -> V_77 ) ;
}
}
static void F_41 ( struct V_22 * V_22 )
{
struct V_12 * V_13 = V_22 -> V_78 ;
struct V_12 * V_79 ;
struct V_1 * log = V_13 -> log ;
unsigned long V_36 ;
if ( V_22 -> V_80 )
F_42 ( log -> V_50 -> V_30 , log -> V_50 ) ;
F_43 ( V_22 ) ;
F_44 ( V_13 -> V_81 , log -> V_82 ) ;
F_45 ( & log -> V_73 , V_36 ) ;
F_5 ( V_13 , V_74 ) ;
if ( log -> V_83 )
F_40 ( log ) ;
else
F_37 ( log ) ;
if ( ! F_46 ( & log -> V_84 ) ) {
V_79 = F_47 ( & log -> V_84 ,
struct V_12 , V_75 ) ;
if ( V_79 -> V_79 )
F_48 ( & log -> V_85 ) ;
}
F_49 ( & log -> V_73 , V_36 ) ;
if ( log -> V_83 )
F_50 ( log -> V_50 -> V_30 -> V_86 ) ;
if ( V_13 -> V_87 ) {
struct V_22 * V_88 ;
F_6 ( F_51 ( & V_13 -> V_89 ) ) ;
while ( ( V_88 = F_52 ( & V_13 -> V_89 ) ) != NULL ) {
F_53 ( V_88 ) ;
F_29 ( & V_13 -> V_90 ) ;
}
if ( F_17 ( & V_13 -> V_90 ) == 0 )
F_54 ( V_13 ) ;
}
}
static void F_55 ( struct V_1 * log , struct V_12 * V_13 )
{
unsigned long V_36 ;
F_45 ( & log -> V_73 , V_36 ) ;
F_5 ( V_13 , V_91 ) ;
F_49 ( & log -> V_73 , V_36 ) ;
if ( V_13 -> V_92 )
V_13 -> V_93 -> V_94 |= V_95 ;
if ( V_13 -> V_96 )
V_13 -> V_93 -> V_94 |= V_97 ;
F_56 ( V_13 -> V_93 ) ;
if ( ! V_13 -> V_98 )
return;
if ( V_13 -> V_92 )
V_13 -> V_98 -> V_94 |= V_95 ;
if ( V_13 -> V_96 )
V_13 -> V_98 -> V_94 |= V_97 ;
F_56 ( V_13 -> V_98 ) ;
}
static void F_57 ( struct V_99 * V_100 )
{
struct V_1 * log = F_58 ( V_100 , struct V_1 ,
V_85 ) ;
struct V_12 * V_13 = NULL ;
unsigned long V_36 ;
F_45 ( & log -> V_73 , V_36 ) ;
if ( ! F_46 ( & log -> V_84 ) ) {
V_13 = F_47 ( & log -> V_84 , struct V_12 ,
V_75 ) ;
if ( ! V_13 -> V_79 )
V_13 = NULL ;
else
V_13 -> V_79 = 0 ;
}
F_49 ( & log -> V_73 , V_36 ) ;
if ( V_13 )
F_55 ( log , V_13 ) ;
}
static void F_59 ( struct V_99 * V_100 )
{
struct V_1 * log = F_58 ( V_100 , struct V_1 ,
V_101 ) ;
struct V_30 * V_30 = log -> V_50 -> V_30 ;
if ( log -> V_2 == V_68 )
return;
F_60 ( L_1 ,
F_61 ( V_30 ) ) ;
F_62 ( V_30 ) ;
log -> V_2 = V_68 ;
F_63 ( V_30 ) ;
}
static void F_64 ( struct V_1 * log )
{
struct V_12 * V_13 = log -> V_102 ;
struct V_22 * V_22 ;
struct V_103 * V_104 ;
unsigned long V_36 ;
T_2 V_105 ;
bool V_106 = true ;
if ( ! V_13 )
return;
V_104 = F_65 ( V_13 -> V_81 ) ;
V_104 -> V_107 = F_66 ( V_13 -> V_108 ) ;
V_105 = F_67 ( log -> V_109 , V_104 , V_110 ) ;
V_104 -> V_111 = F_66 ( V_105 ) ;
V_22 = V_13 -> V_93 ;
log -> V_102 = NULL ;
F_45 ( & log -> V_73 , V_36 ) ;
if ( V_13 -> V_92 || V_13 -> V_96 ) {
if ( V_13 != F_47 ( & log -> V_84 ,
struct V_12 , V_75 ) ) {
V_13 -> V_79 = 1 ;
V_106 = false ;
}
}
F_49 ( & log -> V_73 , V_36 ) ;
if ( V_106 )
F_55 ( log , V_13 ) ;
}
static struct V_22 * F_68 ( struct V_1 * log )
{
struct V_22 * V_22 = F_69 ( V_112 , V_113 , log -> V_114 ) ;
F_70 ( V_22 , V_115 , 0 ) ;
V_22 -> V_116 = log -> V_50 -> V_117 ;
V_22 -> V_26 . V_27 = log -> V_50 -> V_118 + log -> V_11 ;
return V_22 ;
}
static void F_71 ( struct V_1 * log , struct V_12 * V_13 )
{
log -> V_11 = F_2 ( log , log -> V_11 , V_47 ) ;
F_22 ( log ) ;
if ( log -> V_11 == 0 )
V_13 -> V_119 = true ;
V_13 -> V_120 = log -> V_11 ;
}
static struct V_12 * F_72 ( struct V_1 * log )
{
struct V_12 * V_13 ;
struct V_103 * V_104 ;
V_13 = F_73 ( log -> V_121 , V_122 ) ;
if ( ! V_13 )
return NULL ;
memset ( V_13 , 0 , sizeof( * V_13 ) ) ;
V_13 -> log = log ;
F_74 ( & V_13 -> V_75 ) ;
F_74 ( & V_13 -> V_123 ) ;
F_75 ( & V_13 -> V_89 ) ;
V_13 -> V_15 = V_124 ;
V_13 -> V_81 = F_73 ( log -> V_82 , V_112 ) ;
V_104 = F_65 ( V_13 -> V_81 ) ;
F_76 ( V_104 ) ;
V_104 -> V_125 = F_66 ( V_126 ) ;
V_104 -> V_127 = V_128 ;
V_104 -> V_129 = F_77 ( log -> V_129 ) ;
V_104 -> V_130 = F_77 ( log -> V_11 ) ;
V_13 -> V_11 = log -> V_11 ;
V_13 -> V_108 = sizeof( struct V_103 ) ;
V_13 -> V_129 = log -> V_129 ++ ;
V_13 -> V_93 = F_68 ( log ) ;
V_13 -> V_93 -> V_131 = F_41 ;
V_13 -> V_93 -> V_78 = V_13 ;
F_78 ( V_13 -> V_93 , V_13 -> V_81 , V_110 , 0 ) ;
F_71 ( log , V_13 ) ;
F_79 ( & log -> V_73 ) ;
F_80 ( & V_13 -> V_75 , & log -> V_84 ) ;
F_81 ( & log -> V_73 ) ;
return V_13 ;
}
static int F_82 ( struct V_1 * log , unsigned int V_132 )
{
if ( log -> V_102 &&
log -> V_102 -> V_108 + V_132 > V_110 )
F_64 ( log ) ;
if ( ! log -> V_102 ) {
log -> V_102 = F_72 ( log ) ;
if ( ! log -> V_102 )
return - V_133 ;
}
return 0 ;
}
static void F_83 ( struct V_1 * log , T_3 type ,
T_1 V_134 ,
T_2 V_135 , T_2 V_136 ,
bool V_137 )
{
struct V_12 * V_13 = log -> V_102 ;
struct V_138 * V_139 ;
V_139 = F_65 ( V_13 -> V_81 ) + V_13 -> V_108 ;
V_139 -> V_140 . type = F_84 ( type ) ;
V_139 -> V_140 . V_36 = F_84 ( 0 ) ;
V_139 -> V_8 = F_66 ( ( 1 + ! ! V_137 ) <<
( V_141 - 9 ) ) ;
V_139 -> V_134 = F_77 ( V_134 ) ;
V_139 -> V_111 [ 0 ] = F_66 ( V_135 ) ;
if ( V_137 )
V_139 -> V_111 [ 1 ] = F_66 ( V_136 ) ;
V_13 -> V_108 += sizeof( struct V_138 ) +
sizeof( V_142 ) * ( 1 + ! ! V_137 ) ;
}
static void F_85 ( struct V_1 * log , struct V_143 * V_143 )
{
struct V_12 * V_13 = log -> V_102 ;
if ( V_13 -> V_119 ) {
F_25 ( V_13 -> V_98 ) ;
V_13 -> V_98 = V_13 -> V_93 ;
V_13 -> V_93 = F_68 ( log ) ;
F_86 ( V_13 -> V_93 , V_13 -> V_98 ) ;
V_13 -> V_119 = false ;
}
if ( ! F_78 ( V_13 -> V_93 , V_143 , V_110 , 0 ) )
F_87 () ;
F_71 ( log , V_13 ) ;
}
static int F_88 ( struct V_1 * log , struct V_31 * V_32 ,
int V_144 , int V_145 )
{
int V_34 ;
int V_107 ;
int V_146 ;
struct V_12 * V_13 ;
V_107 =
( ( sizeof( struct V_138 ) + sizeof( V_142 ) )
* V_144 ) +
sizeof( struct V_138 ) +
sizeof( V_142 ) * V_145 ;
V_146 = F_82 ( log , V_107 ) ;
if ( V_146 )
return V_146 ;
V_13 = log -> V_102 ;
if ( F_28 ( V_147 , & V_32 -> V_15 ) )
V_13 -> V_92 = 1 ;
for ( V_34 = 0 ; V_34 < V_32 -> V_33 ; V_34 ++ ) {
if ( ! F_15 ( V_64 , & V_32 -> V_19 [ V_34 ] . V_36 ) ||
F_15 ( V_65 , & V_32 -> V_19 [ V_34 ] . V_36 ) )
continue;
if ( V_34 == V_32 -> V_69 || V_34 == V_32 -> V_148 )
continue;
if ( F_15 ( V_149 , & V_32 -> V_19 [ V_34 ] . V_36 ) &&
log -> V_2 == V_3 ) {
V_13 -> V_96 = 1 ;
V_13 -> V_92 = 1 ;
}
F_83 ( log , V_150 ,
F_89 ( V_32 , V_34 , 0 ) ,
V_32 -> V_19 [ V_34 ] . V_151 , 0 , false ) ;
F_85 ( log , V_32 -> V_19 [ V_34 ] . V_143 ) ;
}
if ( V_145 == 2 ) {
F_83 ( log , V_152 ,
V_32 -> V_28 , V_32 -> V_19 [ V_32 -> V_69 ] . V_151 ,
V_32 -> V_19 [ V_32 -> V_148 ] . V_151 , true ) ;
F_85 ( log , V_32 -> V_19 [ V_32 -> V_69 ] . V_143 ) ;
F_85 ( log , V_32 -> V_19 [ V_32 -> V_148 ] . V_143 ) ;
} else if ( V_145 == 1 ) {
F_83 ( log , V_152 ,
V_32 -> V_28 , V_32 -> V_19 [ V_32 -> V_69 ] . V_151 ,
0 , false ) ;
F_85 ( log , V_32 -> V_19 [ V_32 -> V_69 ] . V_143 ) ;
} else
F_25 ( V_145 != 0 ) ;
F_80 ( & V_32 -> V_71 , & V_13 -> V_123 ) ;
F_27 ( & V_13 -> V_90 ) ;
V_32 -> V_153 = V_13 ;
if ( log -> V_2 == V_68 )
return 0 ;
if ( V_32 -> V_11 == V_154 ) {
F_25 ( ! F_46 ( & V_32 -> V_155 ) ) ;
V_32 -> V_11 = V_13 -> V_11 ;
F_79 ( & log -> V_156 ) ;
F_80 ( & V_32 -> V_155 ,
& log -> V_157 ) ;
F_81 ( & log -> V_156 ) ;
F_27 ( & log -> V_49 ) ;
}
return 0 ;
}
static inline void F_90 ( struct V_1 * log ,
struct V_31 * V_32 )
{
F_91 ( & log -> V_158 ) ;
F_80 ( & V_32 -> V_71 , & log -> V_159 ) ;
F_92 ( & log -> V_158 ) ;
}
int F_93 ( struct V_1 * log , struct V_31 * V_32 )
{
struct V_16 * V_17 = V_32 -> V_58 ;
int V_160 = 0 ;
int V_144 , V_145 ;
int V_161 ;
int V_34 ;
int V_146 = 0 ;
bool V_54 = false ;
if ( ! log )
return - V_162 ;
if ( V_32 -> V_153 || ! F_15 ( V_64 , & V_32 -> V_19 [ V_32 -> V_69 ] . V_36 ) ||
F_15 ( V_163 , & V_32 -> V_15 ) ) {
F_23 ( V_67 , & V_32 -> V_15 ) ;
return - V_162 ;
}
F_6 ( F_15 ( V_59 , & V_32 -> V_15 ) ) ;
for ( V_34 = 0 ; V_34 < V_32 -> V_33 ; V_34 ++ ) {
void * V_164 ;
if ( ! F_15 ( V_64 , & V_32 -> V_19 [ V_34 ] . V_36 ) ||
F_15 ( V_65 , & V_32 -> V_19 [ V_34 ] . V_36 ) )
continue;
V_160 ++ ;
if ( F_15 ( V_67 , & V_32 -> V_15 ) )
continue;
V_164 = F_94 ( V_32 -> V_19 [ V_34 ] . V_143 ) ;
V_32 -> V_19 [ V_34 ] . V_151 = F_67 ( log -> V_109 ,
V_164 , V_110 ) ;
F_95 ( V_164 ) ;
}
V_145 = 1 + ! ! ( V_32 -> V_148 >= 0 ) ;
V_144 = V_160 - V_145 ;
F_13 ( V_67 , & V_32 -> V_15 ) ;
F_23 ( V_165 , & V_32 -> V_15 ) ;
F_27 ( & V_32 -> V_166 ) ;
F_96 ( & log -> V_167 ) ;
V_161 = ( 1 + V_160 ) << ( V_141 - 9 ) ;
if ( log -> V_2 == V_68 ) {
if ( ! F_4 ( log , V_161 ) ) {
F_90 ( log , V_32 ) ;
V_54 = true ;
} else {
V_146 = F_88 ( log , V_32 , V_144 , V_145 ) ;
if ( V_146 ) {
F_79 ( & log -> V_73 ) ;
F_80 ( & V_32 -> V_71 ,
& log -> V_168 ) ;
F_81 ( & log -> V_73 ) ;
}
}
} else {
if ( F_15 ( V_55 , & V_17 -> V_56 ) &&
V_32 -> V_11 == V_154 ) {
F_90 ( log , V_32 ) ;
V_54 = true ;
V_161 = 0 ;
} else if ( ! F_4 ( log , V_161 ) ) {
if ( V_32 -> V_11 == log -> V_10 )
F_87 () ;
else
F_90 ( log , V_32 ) ;
} else {
V_146 = F_88 ( log , V_32 , V_144 , V_145 ) ;
if ( V_146 ) {
F_79 ( & log -> V_73 ) ;
F_80 ( & V_32 -> V_71 ,
& log -> V_168 ) ;
F_81 ( & log -> V_73 ) ;
}
}
}
F_97 ( & log -> V_167 ) ;
if ( V_54 )
F_18 ( log , V_161 ) ;
return 0 ;
}
void F_98 ( struct V_1 * log )
{
if ( ! log )
return;
F_96 ( & log -> V_167 ) ;
F_64 ( log ) ;
F_97 ( & log -> V_167 ) ;
}
int F_99 ( struct V_1 * log , struct V_22 * V_22 )
{
if ( ! log )
return - V_169 ;
if ( log -> V_2 == V_68 ) {
if ( V_22 -> V_26 . V_170 == 0 ) {
F_53 ( V_22 ) ;
return 0 ;
}
V_22 -> V_94 &= ~ V_95 ;
} else {
if ( V_22 -> V_26 . V_170 == 0 ) {
F_96 ( & log -> V_167 ) ;
F_82 ( log , 0 ) ;
F_11 ( & log -> V_102 -> V_89 , V_22 ) ;
log -> V_102 -> V_92 = 1 ;
log -> V_102 -> V_87 = 1 ;
F_27 ( & log -> V_102 -> V_90 ) ;
F_64 ( log ) ;
F_97 ( & log -> V_167 ) ;
return 0 ;
}
}
return - V_162 ;
}
static void F_100 ( struct V_1 * log )
{
struct V_31 * V_32 ;
F_91 ( & log -> V_158 ) ;
while ( ! F_46 ( & log -> V_159 ) ) {
V_32 = F_47 ( & log -> V_159 ,
struct V_31 , V_71 ) ;
F_35 ( & V_32 -> V_71 ) ;
F_13 ( V_72 , & V_32 -> V_15 ) ;
F_36 ( V_32 ) ;
}
F_92 ( & log -> V_158 ) ;
}
static T_1 F_101 ( struct V_16 * V_17 )
{
struct V_31 * V_32 ;
struct V_1 * log = V_17 -> log ;
T_1 V_171 ;
unsigned long V_36 ;
if ( log -> V_2 == V_68 )
return log -> V_172 ;
F_45 ( & log -> V_156 , V_36 ) ;
if ( F_46 ( & V_17 -> log -> V_157 ) ) {
F_49 ( & log -> V_156 , V_36 ) ;
return log -> V_172 ;
}
V_32 = F_47 ( & V_17 -> log -> V_157 ,
struct V_31 , V_155 ) ;
V_171 = V_32 -> V_11 ;
F_49 ( & log -> V_156 , V_36 ) ;
return V_171 ;
}
static T_1 F_102 ( struct V_1 * log )
{
struct V_16 * V_17 = log -> V_50 -> V_30 -> V_51 ;
return F_3 ( log , log -> V_10 ,
F_101 ( V_17 ) ) ;
}
static void F_103 ( struct V_1 * log )
{
struct V_31 * V_32 ;
F_38 ( & log -> V_73 ) ;
if ( ! F_46 ( & log -> V_168 ) ) {
V_32 = F_47 ( & log -> V_168 ,
struct V_31 , V_71 ) ;
F_35 ( & V_32 -> V_71 ) ;
F_13 ( V_72 , & V_32 -> V_15 ) ;
F_36 ( V_32 ) ;
}
}
static bool F_104 ( struct V_1 * log )
{
struct V_12 * V_13 , * V_70 ;
bool V_173 = false ;
F_38 ( & log -> V_73 ) ;
F_34 (io, next, &log->finished_ios, log_sibling) {
if ( V_13 -> V_15 < V_174 )
break;
log -> V_172 = V_13 -> V_11 ;
F_105 ( & V_13 -> V_75 ) ;
F_44 ( V_13 , log -> V_121 ) ;
F_103 ( log ) ;
V_173 = true ;
}
return V_173 ;
}
static void F_54 ( struct V_12 * V_13 )
{
struct V_1 * log = V_13 -> log ;
struct V_16 * V_17 = log -> V_50 -> V_30 -> V_51 ;
unsigned long V_36 ;
F_45 ( & log -> V_73 , V_36 ) ;
F_5 ( V_13 , V_174 ) ;
if ( ! F_104 ( log ) ) {
F_49 ( & log -> V_73 , V_36 ) ;
return;
}
if ( F_102 ( log ) > log -> V_175 ||
F_15 ( V_57 , & V_17 -> V_56 ) )
F_18 ( log , 0 ) ;
F_49 ( & log -> V_73 , V_36 ) ;
F_106 ( & log -> V_176 ) ;
}
void F_107 ( struct V_31 * V_32 )
{
struct V_12 * V_13 ;
V_13 = V_32 -> V_153 ;
V_32 -> V_153 = NULL ;
if ( V_13 && F_108 ( & V_13 -> V_90 ) )
F_54 ( V_13 ) ;
}
static void F_109 ( struct V_22 * V_22 )
{
struct V_1 * log = F_58 ( V_22 , struct V_1 ,
V_177 ) ;
unsigned long V_36 ;
struct V_12 * V_13 ;
if ( V_22 -> V_80 )
F_42 ( log -> V_50 -> V_30 , log -> V_50 ) ;
F_45 ( & log -> V_73 , V_36 ) ;
F_110 (io, &log->flushing_ios, log_sibling)
F_33 ( V_13 ) ;
F_111 ( & log -> V_178 , & log -> V_76 ) ;
F_49 ( & log -> V_73 , V_36 ) ;
}
void F_112 ( struct V_1 * log )
{
bool V_179 ;
if ( ! log || ! log -> V_83 )
return;
F_79 ( & log -> V_73 ) ;
if ( ! F_46 ( & log -> V_178 ) ) {
F_81 ( & log -> V_73 ) ;
return;
}
F_111 ( & log -> V_77 , & log -> V_178 ) ;
V_179 = ! F_46 ( & log -> V_178 ) ;
F_81 ( & log -> V_73 ) ;
if ( ! V_179 )
return;
F_113 ( & log -> V_177 ) ;
log -> V_177 . V_116 = log -> V_50 -> V_117 ;
log -> V_177 . V_131 = F_109 ;
log -> V_177 . V_94 = V_115 | V_95 ;
F_56 ( & log -> V_177 ) ;
}
static void F_114 ( struct V_1 * log ,
T_1 V_7 )
{
struct V_180 * V_117 = log -> V_50 -> V_117 ;
struct V_30 * V_30 ;
F_115 ( log , V_7 ) ;
if ( ! F_116 ( F_117 ( V_117 ) ) )
return;
V_30 = log -> V_50 -> V_30 ;
F_118 ( & V_30 -> V_181 , 0 ,
F_119 ( V_182 ) | F_119 ( V_183 ) ) ;
if ( ! F_120 ( V_30 ) )
return;
F_121 ( V_30 , 1 ) ;
F_122 ( V_30 ) ;
if ( log -> V_10 < V_7 ) {
F_123 ( V_117 ,
log -> V_10 + log -> V_50 -> V_118 ,
V_7 - log -> V_10 , V_112 , 0 ) ;
} else {
F_123 ( V_117 ,
log -> V_10 + log -> V_50 -> V_118 ,
log -> V_6 - log -> V_10 ,
V_112 , 0 ) ;
F_123 ( V_117 , log -> V_50 -> V_118 , V_7 ,
V_112 , 0 ) ;
}
}
static void F_124 ( struct V_16 * V_17 , struct V_31 * V_32 )
{
F_25 ( F_46 ( & V_32 -> V_184 ) ) ;
F_25 ( ! F_15 ( V_59 , & V_32 -> V_15 ) ) ;
F_25 ( F_15 ( V_72 , & V_32 -> V_15 ) ) ;
F_25 ( F_15 ( V_185 , & V_32 -> V_15 ) ) ;
F_38 ( & V_17 -> V_186 ) ;
F_35 ( & V_32 -> V_184 ) ;
F_27 ( & V_32 -> V_166 ) ;
F_13 ( V_72 , & V_32 -> V_15 ) ;
F_27 ( & V_17 -> V_187 ) ;
F_24 ( V_32 ) ;
F_36 ( V_32 ) ;
}
void F_125 ( struct V_16 * V_17 , int V_188 )
{
int V_166 ;
struct V_31 * V_32 , * V_70 ;
F_38 ( & V_17 -> V_186 ) ;
if ( ! V_17 -> log )
return;
V_166 = 0 ;
F_34 (sh, next, &conf->r5c_full_stripe_list, lru) {
F_124 ( V_17 , V_32 ) ;
V_166 ++ ;
}
if ( V_166 >= V_188 )
return;
F_34 (sh, next,
&conf->r5c_partial_stripe_list, lru) {
F_124 ( V_17 , V_32 ) ;
if ( ++ V_166 >= V_188 )
break;
}
}
static void F_126 ( struct V_16 * V_17 )
{
struct V_1 * log = V_17 -> log ;
struct V_31 * V_32 ;
int V_166 = 0 ;
unsigned long V_36 ;
int V_39 ;
int V_189 ;
if ( ! F_1 ( log ) )
return;
V_39 = F_17 ( & V_17 -> V_40 ) +
F_17 ( & V_17 -> V_41 ) ;
if ( V_39 > V_17 -> V_42 * 3 / 4 ||
F_17 ( & V_17 -> V_43 ) > 0 )
V_189 = V_190 ;
else if ( V_39 > V_17 -> V_42 * 1 / 2 ||
F_17 ( & V_17 -> V_41 ) >
V_44 )
V_189 = 0 ;
else
V_189 = - 1 ;
if ( V_189 >= 0 ) {
F_45 ( & V_17 -> V_186 , V_36 ) ;
F_125 ( V_17 , V_189 ) ;
F_49 ( & V_17 -> V_186 , V_36 ) ;
}
if ( F_15 ( V_57 , & V_17 -> V_56 ) ) {
F_45 ( & log -> V_156 , V_36 ) ;
F_91 ( & V_17 -> V_186 ) ;
F_110 (sh, &log->stripe_in_journal_list, r5c) {
if ( ! F_46 ( & V_32 -> V_184 ) &&
! F_15 ( V_72 , & V_32 -> V_15 ) &&
F_17 ( & V_32 -> V_166 ) == 0 ) {
F_124 ( V_17 , V_32 ) ;
}
if ( V_166 ++ >= V_190 )
break;
}
F_92 ( & V_17 -> V_186 ) ;
F_49 ( & log -> V_156 , V_36 ) ;
}
if ( ! F_15 ( V_55 , & V_17 -> V_56 ) )
F_100 ( log ) ;
F_50 ( V_17 -> V_30 -> V_86 ) ;
}
static void F_127 ( struct V_1 * log )
{
struct V_16 * V_17 = log -> V_50 -> V_30 -> V_51 ;
T_1 V_191 = F_128 ( & log -> V_191 , 0 ) ;
T_1 V_192 ;
T_1 V_172 ;
bool V_193 ;
F_79 ( & log -> V_73 ) ;
V_193 = F_102 ( log ) > log -> V_175 ||
V_191 != 0 || ! F_46 ( & log -> V_159 ) ;
while ( 1 ) {
V_192 = F_102 ( log ) ;
if ( V_192 >= V_191 ||
( F_46 ( & log -> V_84 ) &&
F_46 ( & log -> V_77 ) &&
F_46 ( & log -> V_178 ) &&
F_46 ( & log -> V_76 ) ) )
break;
F_50 ( log -> V_50 -> V_30 -> V_86 ) ;
F_129 ( log -> V_176 ,
F_102 ( log ) > V_192 ,
log -> V_73 ) ;
}
V_172 = F_101 ( V_17 ) ;
F_81 ( & log -> V_73 ) ;
if ( V_192 == 0 || ! V_193 )
return;
F_114 ( log , V_172 ) ;
F_96 ( & log -> V_167 ) ;
log -> V_10 = V_172 ;
F_22 ( log ) ;
F_97 ( & log -> V_167 ) ;
F_100 ( log ) ;
}
static void F_130 ( struct V_194 * V_86 )
{
struct V_30 * V_30 = V_86 -> V_30 ;
struct V_16 * V_17 = V_30 -> V_51 ;
struct V_1 * log = V_17 -> log ;
if ( ! log )
return;
F_126 ( V_17 ) ;
F_127 ( log ) ;
}
void F_18 ( struct V_1 * log , T_1 V_195 )
{
unsigned long V_196 ;
unsigned long V_197 = ( unsigned long ) V_195 ;
if ( ! log )
return;
do {
V_196 = log -> V_191 ;
if ( V_197 < V_196 )
return;
} while ( F_131 ( & log -> V_191 , V_196 , V_197 ) != V_196 );
F_50 ( log -> V_198 ) ;
}
void F_132 ( struct V_1 * log , int V_15 )
{
struct V_30 * V_30 ;
if ( ! log || V_15 == 2 )
return;
if ( V_15 == 0 )
F_133 ( log -> V_198 -> V_199 ) ;
else if ( V_15 == 1 ) {
V_30 = log -> V_50 -> V_30 ;
F_106 ( & V_30 -> V_200 ) ;
F_134 ( log -> V_198 -> V_199 ) ;
F_18 ( log , V_154 ) ;
F_127 ( log ) ;
}
}
bool F_135 ( struct V_16 * V_17 )
{
struct V_1 * log ;
bool V_146 ;
F_136 () ;
log = F_137 ( V_17 -> log ) ;
if ( ! log )
V_146 = F_15 ( V_201 , & V_17 -> V_30 -> V_36 ) ;
else
V_146 = F_15 ( V_202 , & log -> V_50 -> V_36 ) ;
F_138 () ;
return V_146 ;
}
static int F_139 ( struct V_1 * log ,
struct V_203 * V_204 )
{
struct V_143 * V_143 = V_204 -> V_81 ;
struct V_103 * V_205 ;
T_2 V_105 , V_206 ;
if ( ! F_140 ( log -> V_50 , V_204 -> V_207 , V_110 , V_143 , V_208 , 0 ,
false ) )
return - V_209 ;
V_205 = F_65 ( V_143 ) ;
V_206 = F_141 ( V_205 -> V_111 ) ;
V_205 -> V_111 = 0 ;
if ( F_141 ( V_205 -> V_125 ) != V_126 ||
F_142 ( V_205 -> V_129 ) != V_204 -> V_129 ||
V_205 -> V_127 != V_128 ||
F_142 ( V_205 -> V_130 ) != V_204 -> V_207 )
return - V_210 ;
V_105 = F_67 ( log -> V_109 , V_205 , V_110 ) ;
if ( V_206 != V_105 )
return - V_210 ;
if ( F_141 ( V_205 -> V_107 ) > V_110 )
return - V_210 ;
V_204 -> V_211 = V_47 ;
return 0 ;
}
static void
F_143 ( struct V_1 * log ,
struct V_143 * V_143 ,
T_1 V_207 , T_4 V_129 )
{
struct V_103 * V_205 ;
V_205 = F_65 ( V_143 ) ;
F_76 ( V_205 ) ;
V_205 -> V_125 = F_66 ( V_126 ) ;
V_205 -> V_127 = V_128 ;
V_205 -> V_107 = F_66 ( sizeof( struct V_103 ) ) ;
V_205 -> V_129 = F_77 ( V_129 ) ;
V_205 -> V_130 = F_77 ( V_207 ) ;
}
static int F_144 ( struct V_1 * log , T_1 V_207 ,
T_4 V_129 )
{
struct V_143 * V_143 ;
struct V_103 * V_205 ;
V_143 = F_145 ( V_212 ) ;
if ( ! V_143 )
return - V_133 ;
F_143 ( log , V_143 , V_207 , V_129 ) ;
V_205 = F_65 ( V_143 ) ;
V_205 -> V_111 = F_66 ( F_67 ( log -> V_109 ,
V_205 , V_110 ) ) ;
if ( ! F_140 ( log -> V_50 , V_207 , V_110 , V_143 , V_115 ,
V_97 , false ) ) {
F_146 ( V_143 ) ;
return - V_209 ;
}
F_146 ( V_143 ) ;
return 0 ;
}
static void F_147 ( struct V_1 * log ,
struct V_31 * V_32 ,
struct V_203 * V_204 ,
struct V_138 * V_139 ,
T_1 V_213 )
{
struct V_30 * V_30 = log -> V_50 -> V_30 ;
struct V_16 * V_17 = V_30 -> V_51 ;
int V_214 ;
F_148 ( V_17 ,
F_142 ( V_139 -> V_134 ) , 0 ,
& V_214 , V_32 ) ;
F_140 ( log -> V_50 , V_213 , V_110 ,
V_32 -> V_19 [ V_214 ] . V_143 , V_208 , 0 , false ) ;
V_32 -> V_19 [ V_214 ] . V_151 =
F_141 ( V_139 -> V_111 [ 0 ] ) ;
V_204 -> V_211 += V_47 ;
F_13 ( V_64 , & V_32 -> V_19 [ V_214 ] . V_36 ) ;
F_13 ( V_59 , & V_32 -> V_15 ) ;
}
static void F_149 ( struct V_1 * log ,
struct V_31 * V_32 ,
struct V_203 * V_204 ,
struct V_138 * V_139 ,
T_1 V_213 )
{
struct V_30 * V_30 = log -> V_50 -> V_30 ;
struct V_16 * V_17 = V_30 -> V_51 ;
V_204 -> V_211 += V_47 * V_17 -> V_215 ;
F_140 ( log -> V_50 , V_213 , V_110 ,
V_32 -> V_19 [ V_32 -> V_69 ] . V_143 , V_208 , 0 , false ) ;
V_32 -> V_19 [ V_32 -> V_69 ] . V_151 =
F_141 ( V_139 -> V_111 [ 0 ] ) ;
F_13 ( V_64 , & V_32 -> V_19 [ V_32 -> V_69 ] . V_36 ) ;
if ( V_32 -> V_148 >= 0 ) {
F_140 ( log -> V_50 ,
F_2 ( log , V_213 , V_47 ) ,
V_110 , V_32 -> V_19 [ V_32 -> V_148 ] . V_143 ,
V_208 , 0 , false ) ;
V_32 -> V_19 [ V_32 -> V_148 ] . V_151 =
F_141 ( V_139 -> V_111 [ 1 ] ) ;
F_13 ( V_64 , & V_32 -> V_19 [ V_32 -> V_148 ] . V_36 ) ;
}
F_23 ( V_59 , & V_32 -> V_15 ) ;
}
static void F_150 ( struct V_31 * V_32 )
{
int V_34 ;
V_32 -> V_15 = 0 ;
V_32 -> V_11 = V_154 ;
for ( V_34 = V_32 -> V_33 ; V_34 -- ; )
V_32 -> V_19 [ V_34 ] . V_36 = 0 ;
}
static void
F_151 ( struct V_16 * V_17 ,
struct V_31 * V_32 ,
struct V_203 * V_204 )
{
struct V_216 * V_50 , * V_217 ;
int V_218 ;
int V_219 = 0 ;
for ( V_218 = 0 ; V_218 < V_32 -> V_33 ; V_218 ++ ) {
if ( ! F_15 ( V_64 , & V_32 -> V_19 [ V_218 ] . V_36 ) )
continue;
if ( V_218 == V_32 -> V_148 || V_218 == V_32 -> V_69 )
continue;
V_219 ++ ;
}
if ( V_219 == 0 )
goto V_220;
for ( V_218 = 0 ; V_218 < V_32 -> V_33 ; V_218 ++ ) {
if ( ! F_15 ( V_64 , & V_32 -> V_19 [ V_218 ] . V_36 ) )
continue;
F_136 () ;
V_50 = F_137 ( V_17 -> V_33 [ V_218 ] . V_50 ) ;
if ( V_50 ) {
F_27 ( & V_50 -> V_221 ) ;
F_138 () ;
F_140 ( V_50 , V_32 -> V_28 , V_110 ,
V_32 -> V_19 [ V_218 ] . V_143 , V_115 , 0 ,
false ) ;
F_152 ( V_50 , V_50 -> V_30 ) ;
F_136 () ;
}
V_217 = F_137 ( V_17 -> V_33 [ V_218 ] . V_222 ) ;
if ( V_217 ) {
F_27 ( & V_217 -> V_221 ) ;
F_138 () ;
F_140 ( V_217 , V_32 -> V_28 , V_110 ,
V_32 -> V_19 [ V_218 ] . V_143 , V_115 , 0 ,
false ) ;
F_152 ( V_217 , V_217 -> V_30 ) ;
F_136 () ;
}
F_138 () ;
}
V_204 -> V_223 ++ ;
V_220:
F_150 ( V_32 ) ;
}
static struct V_31 *
F_153 ( struct V_16 * V_17 ,
T_1 V_224 )
{
struct V_31 * V_32 ;
V_32 = F_154 ( V_17 , V_224 , 0 , 1 , 0 ) ;
if ( ! V_32 )
return NULL ;
F_150 ( V_32 ) ;
return V_32 ;
}
static struct V_31 *
F_155 ( struct V_225 * V_226 , T_1 V_227 )
{
struct V_31 * V_32 ;
F_110 (sh, list, lru)
if ( V_32 -> V_28 == V_227 )
return V_32 ;
return NULL ;
}
static void
F_156 ( struct V_225 * V_228 ,
struct V_203 * V_204 )
{
struct V_31 * V_32 , * V_70 ;
F_34 (sh, next, cached_stripe_list, lru) {
F_150 ( V_32 ) ;
F_35 ( & V_32 -> V_184 ) ;
F_36 ( V_32 ) ;
}
}
static void
F_157 ( struct V_225 * V_228 ,
struct V_203 * V_204 )
{
struct V_31 * V_32 , * V_70 ;
F_34 (sh, next, cached_stripe_list, lru)
if ( ! F_15 ( V_59 , & V_32 -> V_15 ) ) {
F_151 ( V_32 -> V_58 , V_32 , V_204 ) ;
F_35 ( & V_32 -> V_184 ) ;
F_36 ( V_32 ) ;
}
}
static int
F_158 ( struct V_1 * log , struct V_143 * V_143 ,
T_1 V_213 , V_142 V_151 )
{
void * V_164 ;
T_2 V_111 ;
F_140 ( log -> V_50 , V_213 , V_110 ,
V_143 , V_208 , 0 , false ) ;
V_164 = F_94 ( V_143 ) ;
V_111 = F_67 ( log -> V_109 , V_164 , V_110 ) ;
F_95 ( V_164 ) ;
return ( F_141 ( V_151 ) == V_111 ) ? 0 : - V_210 ;
}
static int
F_159 ( struct V_1 * log ,
struct V_203 * V_204 )
{
struct V_30 * V_30 = log -> V_50 -> V_30 ;
struct V_16 * V_17 = V_30 -> V_51 ;
struct V_103 * V_205 = F_65 ( V_204 -> V_81 ) ;
T_1 V_229 = sizeof( struct V_103 ) ;
T_1 V_213 = F_2 ( log , V_204 -> V_207 , V_47 ) ;
struct V_143 * V_143 ;
struct V_138 * V_139 ;
V_143 = F_145 ( V_212 ) ;
if ( ! V_143 )
return - V_133 ;
while ( V_229 < F_141 ( V_205 -> V_107 ) ) {
V_139 = ( void * ) V_205 + V_229 ;
if ( V_139 -> V_140 . type == V_150 ) {
if ( F_158 (
log , V_143 , V_213 ,
V_139 -> V_111 [ 0 ] ) < 0 )
goto V_230;
} else if ( V_139 -> V_140 . type == V_152 ) {
if ( F_158 (
log , V_143 , V_213 ,
V_139 -> V_111 [ 0 ] ) < 0 )
goto V_230;
if ( V_17 -> V_215 == 2 &&
F_158 (
log , V_143 ,
F_2 ( log , V_213 ,
V_47 ) ,
V_139 -> V_111 [ 1 ] ) < 0 )
goto V_230;
} else
goto V_230;
V_213 = F_2 ( log , V_213 ,
F_141 ( V_139 -> V_8 ) ) ;
V_229 += sizeof( struct V_138 ) +
sizeof( V_142 ) *
( F_141 ( V_139 -> V_8 ) >> ( V_141 - 9 ) ) ;
}
F_160 ( V_143 ) ;
return 0 ;
V_230:
F_160 ( V_143 ) ;
return - V_210 ;
}
static int
F_161 ( struct V_1 * log ,
struct V_203 * V_204 ,
struct V_225 * V_228 )
{
struct V_30 * V_30 = log -> V_50 -> V_30 ;
struct V_16 * V_17 = V_30 -> V_51 ;
struct V_103 * V_205 ;
struct V_138 * V_139 ;
int V_229 ;
T_1 V_213 ;
T_1 V_224 ;
struct V_31 * V_32 ;
int V_146 ;
V_146 = F_159 ( log , V_204 ) ;
if ( V_146 == - V_210 )
return - V_162 ;
else if ( V_146 )
return V_146 ;
V_205 = F_65 ( V_204 -> V_81 ) ;
V_229 = sizeof( struct V_103 ) ;
V_213 = F_2 ( log , V_204 -> V_207 , V_47 ) ;
while ( V_229 < F_141 ( V_205 -> V_107 ) ) {
int V_231 ;
V_139 = ( void * ) V_205 + V_229 ;
V_224 = ( V_139 -> V_140 . type == V_150 ) ?
F_148 (
V_17 , F_142 ( V_139 -> V_134 ) , 0 , & V_231 ,
NULL )
: F_142 ( V_139 -> V_134 ) ;
V_32 = F_155 ( V_228 ,
V_224 ) ;
if ( ! V_32 ) {
V_32 = F_153 ( V_17 , V_224 ) ;
if ( ! V_32 ) {
F_157 (
V_228 , V_204 ) ;
V_32 = F_153 (
V_17 , V_224 ) ;
}
if ( ! V_32 ) {
F_162 ( L_2 ,
F_61 ( V_30 ) ,
V_17 -> V_42 * 2 ) ;
F_163 ( V_30 ,
V_17 -> V_42 * 2 ) ;
V_32 = F_153 ( V_17 ,
V_224 ) ;
}
if ( ! V_32 ) {
F_164 ( L_3 ,
F_61 ( V_30 ) ) ;
return - V_133 ;
}
F_80 ( & V_32 -> V_184 , V_228 ) ;
}
if ( V_139 -> V_140 . type == V_150 ) {
if ( ! F_15 ( V_59 , & V_32 -> V_15 ) &&
F_15 ( V_64 , & V_32 -> V_19 [ V_32 -> V_69 ] . V_36 ) ) {
F_151 ( V_17 , V_32 , V_204 ) ;
F_39 ( & V_32 -> V_184 , V_228 ) ;
}
F_147 ( log , V_32 , V_204 , V_139 ,
V_213 ) ;
} else if ( V_139 -> V_140 . type == V_152 )
F_149 ( log , V_32 , V_204 , V_139 ,
V_213 ) ;
else
return - V_210 ;
V_213 = F_2 ( log , V_213 ,
F_141 ( V_139 -> V_8 ) ) ;
V_229 += sizeof( struct V_138 ) +
sizeof( V_142 ) *
( F_141 ( V_139 -> V_8 ) >> ( V_141 - 9 ) ) ;
}
return 0 ;
}
static void F_165 ( struct V_1 * log ,
struct V_31 * V_32 )
{
struct V_18 * V_19 ;
int V_34 ;
for ( V_34 = V_32 -> V_33 ; V_34 -- ; ) {
V_19 = V_32 -> V_19 + V_34 ;
if ( F_28 ( V_64 , & V_19 -> V_36 ) ) {
F_13 ( V_65 , & V_19 -> V_36 ) ;
F_13 ( V_35 , & V_19 -> V_36 ) ;
}
}
}
static int F_166 ( struct V_1 * log ,
struct V_203 * V_204 )
{
struct V_31 * V_32 ;
int V_146 = 0 ;
while ( 1 ) {
if ( F_139 ( log , V_204 ) )
break;
V_146 = F_161 ( log , V_204 ,
& V_204 -> V_232 ) ;
if ( V_146 && V_146 != - V_162 )
break;
V_204 -> V_129 ++ ;
V_204 -> V_207 = F_2 ( log , V_204 -> V_207 , V_204 -> V_211 ) ;
}
if ( V_146 == - V_133 ) {
F_156 ( & V_204 -> V_232 , V_204 ) ;
return V_146 ;
}
F_157 ( & V_204 -> V_232 , V_204 ) ;
F_110 (sh, &ctx->cached_list, lru) {
F_6 ( ! F_15 ( V_59 , & V_32 -> V_15 ) ) ;
F_165 ( log , V_32 ) ;
V_204 -> V_233 ++ ;
}
return 0 ;
}
static int
F_167 ( struct V_1 * log ,
struct V_203 * V_204 )
{
struct V_31 * V_32 ;
struct V_30 * V_30 = log -> V_50 -> V_30 ;
struct V_143 * V_143 ;
T_1 V_172 = V_154 ;
V_143 = F_145 ( V_212 ) ;
if ( ! V_143 ) {
F_164 ( L_4 ,
F_61 ( V_30 ) ) ;
return - V_133 ;
}
F_6 ( F_46 ( & V_204 -> V_232 ) ) ;
F_110 (sh, &ctx->cached_list, lru) {
struct V_103 * V_205 ;
int V_34 ;
int V_234 ;
T_1 V_235 ;
F_6 ( ! F_15 ( V_59 , & V_32 -> V_15 ) ) ;
F_143 ( log , V_143 ,
V_204 -> V_207 , V_204 -> V_129 ) ;
V_205 = F_65 ( V_143 ) ;
V_234 = F_141 ( V_205 -> V_107 ) ;
V_235 = F_2 ( log , V_204 -> V_207 , V_47 ) ;
for ( V_34 = V_32 -> V_33 ; V_34 -- ; ) {
struct V_18 * V_19 = & V_32 -> V_19 [ V_34 ] ;
struct V_138 * V_139 ;
void * V_164 ;
if ( F_15 ( V_65 , & V_19 -> V_36 ) ) {
V_139 = ( void * ) V_205 + V_234 ;
V_139 -> V_140 . type = F_84 (
V_150 ) ;
V_139 -> V_8 = V_47 ;
V_139 -> V_134 = F_77 (
F_89 ( V_32 , V_34 , 0 ) ) ;
V_164 = F_94 ( V_19 -> V_143 ) ;
V_139 -> V_111 [ 0 ] = F_66 (
F_67 ( log -> V_109 , V_164 ,
V_110 ) ) ;
F_95 ( V_164 ) ;
F_140 ( log -> V_50 , V_235 , V_110 ,
V_19 -> V_143 , V_115 , 0 , false ) ;
V_235 = F_2 ( log , V_235 ,
V_47 ) ;
V_234 += sizeof( V_142 ) +
sizeof( struct V_138 ) ;
}
}
V_205 -> V_107 = F_66 ( V_234 ) ;
V_205 -> V_111 = F_66 ( F_67 ( log -> V_109 ,
V_205 , V_110 ) ) ;
F_140 ( log -> V_50 , V_204 -> V_207 , V_110 , V_143 ,
V_115 , V_97 , false ) ;
V_32 -> V_11 = V_204 -> V_207 ;
F_80 ( & V_32 -> V_155 , & log -> V_157 ) ;
F_27 ( & log -> V_49 ) ;
V_204 -> V_207 = V_235 ;
V_204 -> V_129 += 1 ;
V_172 = V_32 -> V_11 ;
}
log -> V_172 = V_172 ;
F_146 ( V_143 ) ;
return 0 ;
}
static void F_168 ( struct V_1 * log ,
struct V_203 * V_204 )
{
struct V_30 * V_30 = log -> V_50 -> V_30 ;
struct V_16 * V_17 = V_30 -> V_51 ;
struct V_31 * V_32 , * V_70 ;
if ( V_204 -> V_233 == 0 )
return;
log -> V_2 = V_3 ;
F_34 (sh, next, &ctx->cached_list, lru) {
F_24 ( V_32 ) ;
F_13 ( V_72 , & V_32 -> V_15 ) ;
F_35 ( & V_32 -> V_184 ) ;
F_36 ( V_32 ) ;
}
F_50 ( V_17 -> V_30 -> V_86 ) ;
F_169 ( V_17 -> V_236 ,
F_17 ( & V_17 -> V_187 ) == 0 ) ;
log -> V_2 = V_68 ;
}
static int F_170 ( struct V_1 * log )
{
struct V_30 * V_30 = log -> V_50 -> V_30 ;
struct V_203 V_204 ;
int V_146 ;
T_1 V_207 ;
V_204 . V_207 = log -> V_10 ;
V_204 . V_129 = log -> V_237 ;
V_204 . V_81 = F_145 ( V_212 ) ;
V_204 . V_233 = 0 ;
V_204 . V_223 = 0 ;
F_74 ( & V_204 . V_232 ) ;
if ( ! V_204 . V_81 )
return - V_133 ;
V_146 = F_166 ( log , & V_204 ) ;
F_146 ( V_204 . V_81 ) ;
if ( V_146 )
return V_146 ;
V_207 = V_204 . V_207 ;
V_204 . V_129 += 10000 ;
if ( ( V_204 . V_233 == 0 ) && ( V_204 . V_223 == 0 ) )
F_162 ( L_5 ,
F_61 ( V_30 ) ) ;
else
F_162 ( L_6 ,
F_61 ( V_30 ) , V_204 . V_233 ,
V_204 . V_223 ) ;
if ( V_204 . V_233 == 0 ) {
log -> V_172 = V_204 . V_207 ;
F_144 ( log , V_204 . V_207 , V_204 . V_129 ++ ) ;
V_204 . V_207 = F_2 ( log , V_204 . V_207 , V_47 ) ;
} else if ( F_167 ( log , & V_204 ) ) {
F_164 ( L_7 ,
F_61 ( V_30 ) ) ;
return - V_209 ;
}
log -> V_11 = V_204 . V_207 ;
log -> V_129 = V_204 . V_129 ;
log -> V_10 = V_207 ;
F_115 ( log , V_207 ) ;
F_168 ( log , & V_204 ) ;
return 0 ;
}
static void F_115 ( struct V_1 * log , T_1 V_238 )
{
struct V_30 * V_30 = log -> V_50 -> V_30 ;
log -> V_50 -> V_239 = V_238 ;
F_13 ( V_182 , & V_30 -> V_181 ) ;
}
static T_5 F_171 ( struct V_30 * V_30 , char * V_143 )
{
struct V_16 * V_17 = V_30 -> V_51 ;
int V_146 ;
if ( ! V_17 -> log )
return 0 ;
switch ( V_17 -> log -> V_2 ) {
case V_68 :
V_146 = snprintf (
V_143 , V_110 , L_8 ,
V_240 [ V_68 ] ,
V_240 [ V_3 ] ) ;
break;
case V_3 :
V_146 = snprintf (
V_143 , V_110 , L_9 ,
V_240 [ V_68 ] ,
V_240 [ V_3 ] ) ;
break;
default:
V_146 = 0 ;
}
return V_146 ;
}
static T_5 F_172 ( struct V_30 * V_30 ,
const char * V_143 , T_6 V_241 )
{
struct V_16 * V_17 = V_30 -> V_51 ;
struct V_1 * log = V_17 -> log ;
int V_242 = - 1 , V_34 ;
int V_243 = V_241 ;
if ( ! log )
return - V_169 ;
if ( V_243 && V_143 [ V_243 - 1 ] == '\n' )
V_243 -= 1 ;
for ( V_34 = 0 ; V_34 < F_173 ( V_240 ) ; V_34 ++ )
if ( strlen ( V_240 [ V_34 ] ) == V_243 &&
strncmp ( V_143 , V_240 [ V_34 ] , V_243 ) == 0 ) {
V_242 = V_34 ;
break;
}
if ( V_242 < V_68 ||
V_242 > V_3 )
return - V_210 ;
if ( F_174 ( V_17 ) > 0 &&
V_242 == V_3 )
return - V_210 ;
F_62 ( V_30 ) ;
V_17 -> log -> V_2 = V_242 ;
F_63 ( V_30 ) ;
F_162 ( L_10 ,
F_61 ( V_30 ) , V_242 , V_240 [ V_242 ] ) ;
return V_241 ;
}
int F_175 ( struct V_16 * V_17 ,
struct V_31 * V_32 ,
struct V_244 * V_245 ,
int V_33 )
{
struct V_1 * log = V_17 -> log ;
int V_34 ;
struct V_18 * V_19 ;
int V_246 = 0 ;
F_25 ( ! F_1 ( log ) ) ;
if ( ! F_15 ( V_59 , & V_32 -> V_15 ) ) {
if ( V_245 -> V_247 > 0 || V_245 -> V_25 > 0 )
return - V_162 ;
F_13 ( V_59 , & V_32 -> V_15 ) ;
}
if ( V_245 -> V_248 ) {
F_24 ( V_32 ) ;
return - V_162 ;
}
for ( V_34 = V_33 ; V_34 -- ; ) {
V_19 = & V_32 -> V_19 [ V_34 ] ;
if ( V_19 -> V_249 && ! F_15 ( V_250 , & V_19 -> V_36 ) &&
! F_15 ( V_65 , & V_19 -> V_36 ) ) {
F_24 ( V_32 ) ;
return - V_162 ;
}
}
for ( V_34 = V_33 ; V_34 -- ; ) {
V_19 = & V_32 -> V_19 [ V_34 ] ;
if ( V_19 -> V_249 ) {
F_13 ( V_64 , & V_19 -> V_36 ) ;
F_13 ( V_251 , & V_19 -> V_36 ) ;
F_13 ( V_66 , & V_19 -> V_36 ) ;
V_246 ++ ;
}
}
if ( V_246 ) {
F_13 ( V_252 , & V_245 -> V_253 ) ;
F_13 ( V_67 , & V_32 -> V_15 ) ;
}
return 0 ;
}
void F_176 ( struct V_31 * V_32 )
{
struct V_16 * V_17 = V_32 -> V_58 ;
int V_34 ;
bool V_254 ;
V_254 =
V_32 -> V_19 [ 0 ] . V_255 == V_17 -> V_33 [ 0 ] . V_256 ;
for ( V_34 = V_32 -> V_33 ; V_34 -- ; )
if ( V_32 -> V_19 [ V_34 ] . V_143 != V_32 -> V_19 [ V_34 ] . V_255 ) {
struct V_143 * V_257 = V_32 -> V_19 [ V_34 ] . V_255 ;
V_32 -> V_19 [ V_34 ] . V_255 = V_32 -> V_19 [ V_34 ] . V_143 ;
F_23 ( V_258 , & V_32 -> V_19 [ V_34 ] . V_36 ) ;
if ( ! V_254 )
F_160 ( V_257 ) ;
}
if ( V_254 ) {
F_23 ( V_259 , & V_17 -> V_56 ) ;
F_50 ( V_17 -> V_30 -> V_86 ) ;
}
}
void F_177 ( struct V_31 * V_32 )
{
struct V_16 * V_17 = V_32 -> V_58 ;
int V_34 ;
struct V_18 * V_19 ;
for ( V_34 = V_32 -> V_33 ; V_34 -- ; ) {
V_19 = & V_32 -> V_19 [ V_34 ] ;
if ( V_19 -> V_255 != V_19 -> V_143 )
F_160 ( V_19 -> V_255 ) ;
V_19 -> V_255 = V_17 -> V_33 [ V_34 ] . V_256 ;
}
}
void F_178 ( struct V_16 * V_17 ,
struct V_31 * V_32 ,
struct V_244 * V_245 )
{
int V_34 ;
int V_260 = 0 ;
if ( ! V_17 -> log ||
! F_15 ( V_65 , & V_32 -> V_19 [ V_32 -> V_69 ] . V_36 ) )
return;
F_6 ( F_15 ( V_59 , & V_32 -> V_15 ) ) ;
F_23 ( V_65 , & V_32 -> V_19 [ V_32 -> V_69 ] . V_36 ) ;
if ( V_17 -> log -> V_2 == V_68 )
return;
for ( V_34 = V_32 -> V_33 ; V_34 -- ; ) {
F_23 ( V_65 , & V_32 -> V_19 [ V_34 ] . V_36 ) ;
if ( F_28 ( V_261 , & V_32 -> V_19 [ V_34 ] . V_36 ) )
V_260 = 1 ;
}
V_245 -> V_247 = 0 ;
if ( F_28 ( V_262 , & V_32 -> V_15 ) )
if ( F_108 ( & V_17 -> V_263 ) )
F_50 ( V_17 -> V_30 -> V_86 ) ;
if ( V_260 )
F_106 ( & V_17 -> V_264 ) ;
F_79 ( & V_17 -> log -> V_156 ) ;
F_35 ( & V_32 -> V_155 ) ;
F_81 ( & V_17 -> log -> V_156 ) ;
V_32 -> V_11 = V_154 ;
F_29 ( & V_17 -> log -> V_49 ) ;
F_22 ( V_17 -> log ) ;
}
int
F_179 ( struct V_1 * log , struct V_31 * V_32 ,
struct V_244 * V_245 )
{
struct V_16 * V_17 = V_32 -> V_58 ;
int V_265 = 0 ;
int V_161 ;
int V_34 ;
int V_146 = 0 ;
F_25 ( ! log ) ;
for ( V_34 = 0 ; V_34 < V_32 -> V_33 ; V_34 ++ ) {
void * V_164 ;
if ( ! F_15 ( V_64 , & V_32 -> V_19 [ V_34 ] . V_36 ) )
continue;
V_164 = F_94 ( V_32 -> V_19 [ V_34 ] . V_143 ) ;
V_32 -> V_19 [ V_34 ] . V_151 = F_67 ( log -> V_109 ,
V_164 , V_110 ) ;
F_95 ( V_164 ) ;
V_265 ++ ;
}
F_6 ( V_265 == 0 ) ;
F_23 ( V_165 , & V_32 -> V_15 ) ;
F_27 ( & V_32 -> V_166 ) ;
F_96 ( & log -> V_167 ) ;
V_161 = ( 1 + V_265 ) << ( V_141 - 9 ) ;
if ( F_15 ( V_55 , & V_17 -> V_56 ) &&
V_32 -> V_11 == V_154 )
F_90 ( log , V_32 ) ;
else if ( ! F_4 ( log , V_161 ) ) {
if ( V_32 -> V_11 == log -> V_10 )
F_87 () ;
else
F_90 ( log , V_32 ) ;
} else {
V_146 = F_88 ( log , V_32 , V_265 , 0 ) ;
if ( V_146 ) {
F_79 ( & log -> V_73 ) ;
F_80 ( & V_32 -> V_71 , & log -> V_168 ) ;
F_81 ( & log -> V_73 ) ;
}
}
F_97 ( & log -> V_167 ) ;
return 0 ;
}
static int F_180 ( struct V_1 * log )
{
struct V_216 * V_50 = log -> V_50 ;
struct V_143 * V_143 ;
struct V_103 * V_205 ;
T_1 V_238 = log -> V_50 -> V_239 ;
T_2 V_206 , V_266 ;
bool V_267 = false ;
int V_146 = 0 ;
if ( V_238 >= V_50 -> V_268 || F_181 ( V_238 , V_47 ) != V_238 )
V_238 = 0 ;
V_143 = F_145 ( V_212 ) ;
if ( ! V_143 )
return - V_133 ;
if ( ! F_140 ( V_50 , V_238 , V_110 , V_143 , V_208 , 0 , false ) ) {
V_146 = - V_209 ;
goto V_269;
}
V_205 = F_65 ( V_143 ) ;
if ( F_141 ( V_205 -> V_125 ) != V_126 ||
V_205 -> V_127 != V_128 ) {
V_267 = true ;
goto V_270;
}
V_206 = F_141 ( V_205 -> V_111 ) ;
V_205 -> V_111 = 0 ;
V_266 = F_67 ( log -> V_109 , V_205 , V_110 ) ;
if ( V_206 != V_266 ) {
V_267 = true ;
goto V_270;
}
if ( F_142 ( V_205 -> V_130 ) != V_238 ) {
V_267 = true ;
goto V_270;
}
V_270:
if ( V_267 ) {
log -> V_237 = F_182 () ;
V_238 = 0 ;
F_144 ( log , V_238 , log -> V_237 ) ;
F_115 ( log , V_238 ) ;
} else
log -> V_237 = F_142 ( V_205 -> V_129 ) ;
log -> V_6 = F_181 ( V_50 -> V_268 , V_47 ) ;
log -> V_175 = log -> V_6 >> V_271 ;
if ( log -> V_175 > V_272 )
log -> V_175 = V_272 ;
log -> V_10 = V_238 ;
F_146 ( V_143 ) ;
if ( V_267 ) {
log -> V_11 = F_2 ( log , V_238 , V_47 ) ;
log -> V_129 = log -> V_237 + 1 ;
log -> V_172 = V_238 ;
} else
V_146 = F_170 ( log ) ;
F_22 ( log ) ;
return V_146 ;
V_269:
F_146 ( V_143 ) ;
return V_146 ;
}
void F_183 ( struct V_30 * V_30 )
{
struct V_16 * V_17 = V_30 -> V_51 ;
struct V_1 * log = V_17 -> log ;
if ( ! log )
return;
if ( F_174 ( V_17 ) > 0 &&
V_17 -> log -> V_2 == V_3 )
F_48 ( & log -> V_101 ) ;
}
int F_184 ( struct V_16 * V_17 , struct V_216 * V_50 )
{
struct V_273 * V_274 = F_117 ( V_50 -> V_117 ) ;
struct V_1 * log ;
if ( V_110 != 4096 )
return - V_210 ;
if ( sizeof( struct V_103 ) +
( ( sizeof( struct V_138 ) + sizeof( V_142 ) ) *
V_17 -> V_48 ) > V_110 ) {
F_164 ( L_11 ,
F_61 ( V_17 -> V_30 ) , V_17 -> V_48 ) ;
return - V_210 ;
}
log = F_185 ( sizeof( * log ) , V_212 ) ;
if ( ! log )
return - V_133 ;
log -> V_50 = V_50 ;
log -> V_83 = F_15 ( V_275 , & V_274 -> V_276 ) != 0 ;
log -> V_109 = F_67 ( ~ 0 , V_50 -> V_30 -> V_277 ,
sizeof( V_50 -> V_30 -> V_277 ) ) ;
F_186 ( & log -> V_167 ) ;
F_187 ( & log -> V_73 ) ;
F_74 ( & log -> V_84 ) ;
F_74 ( & log -> V_77 ) ;
F_74 ( & log -> V_178 ) ;
F_74 ( & log -> V_76 ) ;
F_188 ( & log -> V_177 , NULL , 0 ) ;
log -> V_278 = F_189 ( V_12 , 0 ) ;
if ( ! log -> V_278 )
goto V_278;
log -> V_121 = F_190 ( V_279 , log -> V_278 ) ;
if ( ! log -> V_121 )
goto V_121;
log -> V_114 = F_191 ( V_279 , 0 ) ;
if ( ! log -> V_114 )
goto V_280;
log -> V_82 = F_192 ( V_279 , 0 ) ;
if ( ! log -> V_82 )
goto V_281;
log -> V_198 = F_193 ( F_130 ,
log -> V_50 -> V_30 , L_12 ) ;
if ( ! log -> V_198 )
goto V_198;
log -> V_198 -> V_282 = V_283 ;
F_194 ( & log -> V_176 ) ;
F_74 ( & log -> V_168 ) ;
F_74 ( & log -> V_159 ) ;
F_187 ( & log -> V_158 ) ;
F_195 ( & log -> V_85 , F_57 ) ;
F_195 ( & log -> V_101 , F_59 ) ;
log -> V_2 = V_68 ;
F_74 ( & log -> V_157 ) ;
F_187 ( & log -> V_156 ) ;
F_196 ( & log -> V_49 , 0 ) ;
F_197 ( V_17 -> log , log ) ;
if ( F_180 ( log ) )
goto error;
F_13 ( V_201 , & V_17 -> V_30 -> V_36 ) ;
return 0 ;
error:
F_197 ( V_17 -> log , NULL ) ;
F_198 ( & log -> V_198 ) ;
V_198:
F_199 ( log -> V_82 ) ;
V_281:
F_200 ( log -> V_114 ) ;
V_280:
F_199 ( log -> V_121 ) ;
V_121:
F_201 ( log -> V_278 ) ;
V_278:
F_202 ( log ) ;
return - V_210 ;
}
void F_203 ( struct V_1 * log )
{
F_204 ( & log -> V_101 ) ;
F_198 ( & log -> V_198 ) ;
F_199 ( log -> V_82 ) ;
F_200 ( log -> V_114 ) ;
F_199 ( log -> V_121 ) ;
F_201 ( log -> V_278 ) ;
F_202 ( log ) ;
}
