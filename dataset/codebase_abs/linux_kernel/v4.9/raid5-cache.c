static T_1 F_1 ( struct V_1 * log , T_1 V_2 , T_1 V_3 )
{
V_2 += V_3 ;
if ( V_2 >= log -> V_4 )
V_2 = V_2 - log -> V_4 ;
return V_2 ;
}
static T_1 F_2 ( struct V_1 * log , T_1 V_2 ,
T_1 V_5 )
{
if ( V_5 >= V_2 )
return V_5 - V_2 ;
else
return V_5 + log -> V_4 - V_2 ;
}
static bool F_3 ( struct V_1 * log , T_1 V_6 )
{
T_1 V_7 ;
V_7 = F_2 ( log , log -> V_8 ,
log -> V_9 ) ;
return log -> V_4 > V_7 + V_6 ;
}
static void F_4 ( struct V_10 * V_11 ,
enum V_12 V_13 )
{
if ( F_5 ( V_11 -> V_13 >= V_13 ) )
return;
V_11 -> V_13 = V_13 ;
}
static void F_6 ( struct V_10 * V_11 )
{
struct V_14 * V_15 , * V_16 ;
F_7 (sh, next, &io->stripe_list, log_list) {
F_8 ( & V_15 -> V_17 ) ;
F_9 ( V_18 , & V_15 -> V_13 ) ;
F_10 ( V_15 ) ;
}
}
static void F_11 ( struct V_1 * log )
{
struct V_10 * V_11 , * V_16 ;
F_12 ( & log -> V_19 ) ;
F_7 (io, next, &log->running_ios, log_sibling) {
if ( V_11 -> V_13 < V_20 )
break;
F_13 ( & V_11 -> V_21 , & log -> V_22 ) ;
F_6 ( V_11 ) ;
}
}
static void F_14 ( struct V_1 * log )
{
struct V_10 * V_11 , * V_16 ;
F_12 ( & log -> V_19 ) ;
F_7 (io, next, &log->running_ios, log_sibling) {
if ( V_11 -> V_13 < V_20 )
break;
F_13 ( & V_11 -> V_21 , & log -> V_23 ) ;
}
}
static void F_15 ( struct V_24 * V_24 )
{
struct V_10 * V_11 = V_24 -> V_25 ;
struct V_1 * log = V_11 -> log ;
unsigned long V_26 ;
if ( V_24 -> V_27 )
F_16 ( log -> V_28 -> V_29 , log -> V_28 ) ;
F_17 ( V_24 ) ;
F_18 ( V_11 -> V_30 , log -> V_31 ) ;
F_19 ( & log -> V_19 , V_26 ) ;
F_4 ( V_11 , V_20 ) ;
if ( log -> V_32 )
F_14 ( log ) ;
else
F_11 ( log ) ;
F_20 ( & log -> V_19 , V_26 ) ;
if ( log -> V_32 )
F_21 ( log -> V_28 -> V_29 -> V_33 ) ;
}
static void F_22 ( struct V_1 * log )
{
struct V_10 * V_11 = log -> V_34 ;
struct V_35 * V_36 ;
unsigned long V_26 ;
T_2 V_37 ;
if ( ! V_11 )
return;
V_36 = F_23 ( V_11 -> V_30 ) ;
V_36 -> V_38 = F_24 ( V_11 -> V_39 ) ;
V_37 = F_25 ( log -> V_40 , V_36 , V_41 ) ;
V_36 -> V_42 = F_24 ( V_37 ) ;
log -> V_34 = NULL ;
F_19 ( & log -> V_19 , V_26 ) ;
F_4 ( V_11 , V_43 ) ;
F_20 ( & log -> V_19 , V_26 ) ;
F_26 ( V_11 -> V_44 ) ;
}
static struct V_24 * F_27 ( struct V_1 * log )
{
struct V_24 * V_24 = F_28 ( V_45 , V_46 , log -> V_47 ) ;
F_29 ( V_24 , V_48 , 0 ) ;
V_24 -> V_49 = log -> V_28 -> V_50 ;
V_24 -> V_51 . V_52 = log -> V_28 -> V_53 + log -> V_9 ;
return V_24 ;
}
static void F_30 ( struct V_1 * log , struct V_10 * V_11 )
{
log -> V_9 = F_1 ( log , log -> V_9 , V_54 ) ;
if ( log -> V_9 == 0 )
V_11 -> V_55 = true ;
V_11 -> V_56 = log -> V_9 ;
}
static struct V_10 * F_31 ( struct V_1 * log )
{
struct V_10 * V_11 ;
struct V_35 * V_36 ;
V_11 = F_32 ( log -> V_57 , V_58 ) ;
if ( ! V_11 )
return NULL ;
memset ( V_11 , 0 , sizeof( * V_11 ) ) ;
V_11 -> log = log ;
F_33 ( & V_11 -> V_21 ) ;
F_33 ( & V_11 -> V_59 ) ;
V_11 -> V_13 = V_60 ;
V_11 -> V_30 = F_32 ( log -> V_31 , V_45 ) ;
V_36 = F_23 ( V_11 -> V_30 ) ;
F_34 ( V_36 ) ;
V_36 -> V_61 = F_24 ( V_62 ) ;
V_36 -> V_63 = V_64 ;
V_36 -> V_65 = F_35 ( log -> V_65 ) ;
V_36 -> V_66 = F_35 ( log -> V_9 ) ;
V_11 -> V_9 = log -> V_9 ;
V_11 -> V_39 = sizeof( struct V_35 ) ;
V_11 -> V_65 = log -> V_65 ++ ;
V_11 -> V_44 = F_27 ( log ) ;
V_11 -> V_44 -> V_67 = F_15 ;
V_11 -> V_44 -> V_25 = V_11 ;
F_36 ( V_11 -> V_44 , V_11 -> V_30 , V_41 , 0 ) ;
F_30 ( log , V_11 ) ;
F_37 ( & log -> V_19 ) ;
F_38 ( & V_11 -> V_21 , & log -> V_68 ) ;
F_39 ( & log -> V_19 ) ;
return V_11 ;
}
static int F_40 ( struct V_1 * log , unsigned int V_69 )
{
if ( log -> V_34 &&
log -> V_34 -> V_39 + V_69 > V_41 )
F_22 ( log ) ;
if ( ! log -> V_34 ) {
log -> V_34 = F_31 ( log ) ;
if ( ! log -> V_34 )
return - V_70 ;
}
return 0 ;
}
static void F_41 ( struct V_1 * log , T_3 type ,
T_1 V_71 ,
T_2 V_72 , T_2 V_73 ,
bool V_74 )
{
struct V_10 * V_11 = log -> V_34 ;
struct V_75 * V_76 ;
V_76 = F_23 ( V_11 -> V_30 ) + V_11 -> V_39 ;
V_76 -> V_77 . type = F_42 ( type ) ;
V_76 -> V_77 . V_26 = F_42 ( 0 ) ;
V_76 -> V_6 = F_24 ( ( 1 + ! ! V_74 ) <<
( V_78 - 9 ) ) ;
V_76 -> V_71 = F_35 ( V_71 ) ;
V_76 -> V_42 [ 0 ] = F_24 ( V_72 ) ;
if ( V_74 )
V_76 -> V_42 [ 1 ] = F_24 ( V_73 ) ;
V_11 -> V_39 += sizeof( struct V_75 ) +
sizeof( V_79 ) * ( 1 + ! ! V_74 ) ;
}
static void F_43 ( struct V_1 * log , struct V_80 * V_80 )
{
struct V_10 * V_11 = log -> V_34 ;
if ( V_11 -> V_55 ) {
struct V_24 * V_81 = V_11 -> V_44 ;
V_11 -> V_44 = F_27 ( log ) ;
F_44 ( V_11 -> V_44 , V_81 ) ;
F_26 ( V_81 ) ;
}
if ( ! F_36 ( V_11 -> V_44 , V_80 , V_41 , 0 ) )
F_45 () ;
F_30 ( log , V_11 ) ;
}
static int F_46 ( struct V_1 * log , struct V_14 * V_15 ,
int V_82 , int V_83 )
{
int V_84 ;
int V_38 ;
int V_85 ;
struct V_10 * V_11 ;
V_38 =
( ( sizeof( struct V_75 ) + sizeof( V_79 ) )
* V_82 ) +
sizeof( struct V_75 ) +
sizeof( V_79 ) * V_83 ;
V_85 = F_40 ( log , V_38 ) ;
if ( V_85 )
return V_85 ;
V_11 = log -> V_34 ;
for ( V_84 = 0 ; V_84 < V_15 -> V_86 ; V_84 ++ ) {
if ( ! F_47 ( V_87 , & V_15 -> V_88 [ V_84 ] . V_26 ) )
continue;
if ( V_84 == V_15 -> V_89 || V_84 == V_15 -> V_90 )
continue;
F_41 ( log , V_91 ,
F_48 ( V_15 , V_84 , 0 ) ,
V_15 -> V_88 [ V_84 ] . V_92 , 0 , false ) ;
F_43 ( log , V_15 -> V_88 [ V_84 ] . V_80 ) ;
}
if ( V_15 -> V_90 >= 0 ) {
F_41 ( log , V_93 ,
V_15 -> V_94 , V_15 -> V_88 [ V_15 -> V_89 ] . V_92 ,
V_15 -> V_88 [ V_15 -> V_90 ] . V_92 , true ) ;
F_43 ( log , V_15 -> V_88 [ V_15 -> V_89 ] . V_80 ) ;
F_43 ( log , V_15 -> V_88 [ V_15 -> V_90 ] . V_80 ) ;
} else {
F_41 ( log , V_93 ,
V_15 -> V_94 , V_15 -> V_88 [ V_15 -> V_89 ] . V_92 ,
0 , false ) ;
F_43 ( log , V_15 -> V_88 [ V_15 -> V_89 ] . V_80 ) ;
}
F_38 ( & V_15 -> V_17 , & V_11 -> V_59 ) ;
F_49 ( & V_11 -> V_95 ) ;
V_15 -> V_96 = V_11 ;
return 0 ;
}
int F_50 ( struct V_1 * log , struct V_14 * V_15 )
{
int V_97 = 0 ;
int V_82 , V_83 ;
int V_38 ;
int V_98 ;
int V_84 ;
int V_85 = 0 ;
if ( ! log )
return - V_99 ;
if ( V_15 -> V_96 || ! F_47 ( V_87 , & V_15 -> V_88 [ V_15 -> V_89 ] . V_26 ) ||
F_47 ( V_100 , & V_15 -> V_13 ) ) {
F_51 ( V_101 , & V_15 -> V_13 ) ;
return - V_99 ;
}
for ( V_84 = 0 ; V_84 < V_15 -> V_86 ; V_84 ++ ) {
void * V_102 ;
if ( ! F_47 ( V_87 , & V_15 -> V_88 [ V_84 ] . V_26 ) )
continue;
V_97 ++ ;
if ( F_47 ( V_101 , & V_15 -> V_13 ) )
continue;
V_102 = F_52 ( V_15 -> V_88 [ V_84 ] . V_80 ) ;
V_15 -> V_88 [ V_84 ] . V_92 = F_25 ( log -> V_40 ,
V_102 , V_41 ) ;
F_53 ( V_102 ) ;
}
V_83 = 1 + ! ! ( V_15 -> V_90 >= 0 ) ;
V_82 = V_97 - V_83 ;
V_38 =
( ( sizeof( struct V_75 ) + sizeof( V_79 ) )
* V_82 ) +
sizeof( struct V_75 ) +
sizeof( V_79 ) * V_83 ;
if ( V_38 + sizeof( struct V_35 ) > V_41 )
return - V_103 ;
F_9 ( V_101 , & V_15 -> V_13 ) ;
F_51 ( V_104 , & V_15 -> V_13 ) ;
F_49 ( & V_15 -> V_105 ) ;
F_54 ( & log -> V_106 ) ;
V_98 = ( 1 + V_97 ) << ( V_78 - 9 ) ;
if ( ! F_3 ( log , V_98 ) ) {
F_55 ( & log -> V_107 ) ;
F_38 ( & V_15 -> V_17 , & log -> V_108 ) ;
F_56 ( & log -> V_107 ) ;
F_57 ( log , V_98 ) ;
} else {
V_85 = F_46 ( log , V_15 , V_82 , V_83 ) ;
if ( V_85 ) {
F_37 ( & log -> V_19 ) ;
F_38 ( & V_15 -> V_17 , & log -> V_109 ) ;
F_39 ( & log -> V_19 ) ;
}
}
F_58 ( & log -> V_106 ) ;
return 0 ;
}
void F_59 ( struct V_1 * log )
{
if ( ! log )
return;
F_54 ( & log -> V_106 ) ;
F_22 ( log ) ;
F_58 ( & log -> V_106 ) ;
}
int F_60 ( struct V_1 * log , struct V_24 * V_24 )
{
if ( ! log )
return - V_110 ;
if ( V_24 -> V_51 . V_111 == 0 ) {
F_61 ( V_24 ) ;
return 0 ;
}
V_24 -> V_112 &= ~ V_113 ;
return - V_99 ;
}
static void F_62 ( struct V_1 * log )
{
struct V_14 * V_15 ;
F_55 ( & log -> V_107 ) ;
while ( ! F_63 ( & log -> V_108 ) ) {
V_15 = F_64 ( & log -> V_108 ,
struct V_14 , V_17 ) ;
F_8 ( & V_15 -> V_17 ) ;
F_9 ( V_18 , & V_15 -> V_13 ) ;
F_10 ( V_15 ) ;
}
F_56 ( & log -> V_107 ) ;
}
static T_1 F_65 ( struct V_1 * log )
{
return F_2 ( log , log -> V_8 ,
log -> V_114 ) ;
}
static void F_66 ( struct V_1 * log )
{
struct V_14 * V_15 ;
F_12 ( & log -> V_19 ) ;
if ( ! F_63 ( & log -> V_109 ) ) {
V_15 = F_64 ( & log -> V_109 ,
struct V_14 , V_17 ) ;
F_8 ( & V_15 -> V_17 ) ;
F_9 ( V_18 , & V_15 -> V_13 ) ;
F_10 ( V_15 ) ;
}
}
static bool F_67 ( struct V_1 * log )
{
struct V_10 * V_11 , * V_16 ;
bool V_115 = false ;
F_12 ( & log -> V_19 ) ;
F_7 (io, next, &log->finished_ios, log_sibling) {
if ( V_11 -> V_13 < V_116 )
break;
log -> V_114 = V_11 -> V_9 ;
log -> V_117 = V_11 -> V_65 ;
F_68 ( & V_11 -> V_21 ) ;
F_18 ( V_11 , log -> V_57 ) ;
F_66 ( log ) ;
V_115 = true ;
}
return V_115 ;
}
static void F_69 ( struct V_10 * V_11 )
{
struct V_1 * log = V_11 -> log ;
unsigned long V_26 ;
F_19 ( & log -> V_19 , V_26 ) ;
F_4 ( V_11 , V_116 ) ;
if ( ! F_67 ( log ) ) {
F_20 ( & log -> V_19 , V_26 ) ;
return;
}
if ( F_65 ( log ) > log -> V_118 )
F_57 ( log , 0 ) ;
F_20 ( & log -> V_19 , V_26 ) ;
F_70 ( & log -> V_119 ) ;
}
void F_71 ( struct V_14 * V_15 )
{
struct V_10 * V_11 ;
V_11 = V_15 -> V_96 ;
V_15 -> V_96 = NULL ;
if ( V_11 && F_72 ( & V_11 -> V_95 ) )
F_69 ( V_11 ) ;
}
static void F_73 ( struct V_24 * V_24 )
{
struct V_1 * log = F_74 ( V_24 , struct V_1 ,
V_120 ) ;
unsigned long V_26 ;
struct V_10 * V_11 ;
if ( V_24 -> V_27 )
F_16 ( log -> V_28 -> V_29 , log -> V_28 ) ;
F_19 ( & log -> V_19 , V_26 ) ;
F_75 (io, &log->flushing_ios, log_sibling)
F_6 ( V_11 ) ;
F_76 ( & log -> V_121 , & log -> V_22 ) ;
F_20 ( & log -> V_19 , V_26 ) ;
}
void F_77 ( struct V_1 * log )
{
bool V_122 ;
if ( ! log || ! log -> V_32 )
return;
F_37 ( & log -> V_19 ) ;
if ( ! F_63 ( & log -> V_121 ) ) {
F_39 ( & log -> V_19 ) ;
return;
}
F_76 ( & log -> V_23 , & log -> V_121 ) ;
V_122 = ! F_63 ( & log -> V_121 ) ;
F_39 ( & log -> V_19 ) ;
if ( ! V_122 )
return;
F_78 ( & log -> V_120 ) ;
log -> V_120 . V_49 = log -> V_28 -> V_50 ;
log -> V_120 . V_67 = F_73 ;
F_29 ( & log -> V_120 , V_48 , V_123 ) ;
F_26 ( & log -> V_120 ) ;
}
static void F_79 ( struct V_1 * log ,
T_1 V_5 )
{
struct V_124 * V_50 = log -> V_28 -> V_50 ;
struct V_29 * V_29 ;
F_80 ( log , V_5 ) ;
if ( ! F_81 ( F_82 ( V_50 ) ) )
return;
V_29 = log -> V_28 -> V_29 ;
F_83 ( & V_29 -> V_26 , 0 ,
F_84 ( V_125 ) | F_84 ( V_126 ) ) ;
if ( ! F_85 ( V_29 ) )
return;
F_86 ( V_29 , 1 ) ;
F_87 ( V_29 ) ;
if ( log -> V_8 < V_5 ) {
F_88 ( V_50 ,
log -> V_8 + log -> V_28 -> V_53 ,
V_5 - log -> V_8 , V_45 , 0 ) ;
} else {
F_88 ( V_50 ,
log -> V_8 + log -> V_28 -> V_53 ,
log -> V_4 - log -> V_8 ,
V_45 , 0 ) ;
F_88 ( V_50 , log -> V_28 -> V_53 , V_5 ,
V_45 , 0 ) ;
}
}
static void F_89 ( struct V_1 * log )
{
T_1 V_127 = F_90 ( & log -> V_127 , 0 ) ;
T_1 V_128 ;
T_1 V_114 ;
T_4 V_117 ;
F_37 ( & log -> V_19 ) ;
while ( 1 ) {
V_128 = F_65 ( log ) ;
if ( V_128 >= V_127 ||
( F_63 ( & log -> V_68 ) &&
F_63 ( & log -> V_23 ) &&
F_63 ( & log -> V_121 ) &&
F_63 ( & log -> V_22 ) ) )
break;
F_21 ( log -> V_28 -> V_29 -> V_33 ) ;
F_91 ( log -> V_119 ,
F_65 ( log ) > V_128 ,
log -> V_19 ) ;
}
V_114 = log -> V_114 ;
V_117 = log -> V_117 ;
F_39 ( & log -> V_19 ) ;
F_92 ( V_128 < 0 ) ;
if ( V_128 == 0 )
return;
F_79 ( log , V_114 ) ;
F_54 ( & log -> V_106 ) ;
log -> V_8 = V_114 ;
log -> V_129 = V_117 ;
F_58 ( & log -> V_106 ) ;
F_62 ( log ) ;
}
static void F_93 ( struct V_130 * V_33 )
{
struct V_29 * V_29 = V_33 -> V_29 ;
struct V_131 * V_132 = V_29 -> V_133 ;
struct V_1 * log = V_132 -> log ;
if ( ! log )
return;
F_89 ( log ) ;
}
static void F_57 ( struct V_1 * log , T_1 V_134 )
{
unsigned long V_135 ;
unsigned long V_136 = ( unsigned long ) V_134 ;
do {
V_135 = log -> V_127 ;
if ( V_136 < V_135 )
return;
} while ( F_94 ( & log -> V_127 , V_135 , V_136 ) != V_135 );
F_21 ( log -> V_137 ) ;
}
void F_95 ( struct V_1 * log , int V_13 )
{
struct V_29 * V_29 ;
if ( ! log || V_13 == 2 )
return;
if ( V_13 == 0 ) {
if ( log -> V_137 )
return;
log -> V_137 = F_96 ( F_93 ,
log -> V_28 -> V_29 , L_1 ) ;
} else if ( V_13 == 1 ) {
V_29 = log -> V_28 -> V_29 ;
F_70 ( & V_29 -> V_138 ) ;
F_57 ( log , - 1L ) ;
F_97 ( & log -> V_137 ) ;
F_89 ( log ) ;
}
}
bool F_98 ( struct V_131 * V_132 )
{
struct V_1 * log ;
bool V_85 ;
F_99 () ;
log = F_100 ( V_132 -> log ) ;
if ( ! log )
V_85 = F_47 ( V_139 , & V_132 -> V_29 -> V_26 ) ;
else
V_85 = F_47 ( V_140 , & log -> V_28 -> V_26 ) ;
F_101 () ;
return V_85 ;
}
static int F_102 ( struct V_1 * log ,
struct V_141 * V_142 )
{
struct V_80 * V_80 = V_142 -> V_30 ;
struct V_35 * V_143 ;
T_2 V_37 , V_144 ;
if ( ! F_103 ( log -> V_28 , V_142 -> V_145 , V_41 , V_80 , V_146 , 0 ,
false ) )
return - V_147 ;
V_143 = F_23 ( V_80 ) ;
V_144 = F_104 ( V_143 -> V_42 ) ;
V_143 -> V_42 = 0 ;
if ( F_104 ( V_143 -> V_61 ) != V_62 ||
F_105 ( V_143 -> V_65 ) != V_142 -> V_65 ||
V_143 -> V_63 != V_64 ||
F_105 ( V_143 -> V_66 ) != V_142 -> V_145 )
return - V_103 ;
V_37 = F_25 ( log -> V_40 , V_143 , V_41 ) ;
if ( V_144 != V_37 )
return - V_103 ;
if ( F_104 ( V_143 -> V_38 ) > V_41 )
return - V_103 ;
V_142 -> V_148 = V_54 ;
return 0 ;
}
static int F_106 ( struct V_1 * log ,
struct V_141 * V_142 ,
T_1 V_149 ,
int * V_150 , T_1 * V_151 )
{
struct V_131 * V_132 = log -> V_28 -> V_29 -> V_133 ;
struct V_14 * V_15 ;
struct V_75 * V_76 ;
int V_152 ;
V_15 = F_107 ( V_132 , V_149 , 0 , 0 , 0 ) ;
while ( 1 ) {
V_76 = F_23 ( V_142 -> V_30 ) + * V_150 ;
if ( F_108 ( V_76 -> V_77 . type ) == V_91 ) {
F_109 ( V_132 ,
F_105 ( V_76 -> V_71 ) , 0 ,
& V_152 , V_15 ) ;
F_103 ( log -> V_28 , * V_151 , V_41 ,
V_15 -> V_88 [ V_152 ] . V_80 , V_146 , 0 ,
false ) ;
V_15 -> V_88 [ V_152 ] . V_92 =
F_104 ( V_76 -> V_42 [ 0 ] ) ;
F_9 ( V_87 , & V_15 -> V_88 [ V_152 ] . V_26 ) ;
V_142 -> V_148 += V_54 ;
} else {
V_152 = V_15 -> V_89 ;
F_103 ( log -> V_28 , * V_151 , V_41 ,
V_15 -> V_88 [ V_152 ] . V_80 , V_146 , 0 ,
false ) ;
V_15 -> V_88 [ V_152 ] . V_92 =
F_104 ( V_76 -> V_42 [ 0 ] ) ;
F_9 ( V_87 , & V_15 -> V_88 [ V_152 ] . V_26 ) ;
if ( V_15 -> V_90 >= 0 ) {
V_152 = V_15 -> V_90 ;
F_103 ( log -> V_28 ,
F_1 ( log , * V_151 , V_54 ) ,
V_41 , V_15 -> V_88 [ V_152 ] . V_80 ,
V_146 , 0 , false ) ;
V_15 -> V_88 [ V_152 ] . V_92 =
F_104 ( V_76 -> V_42 [ 1 ] ) ;
F_9 ( V_87 ,
& V_15 -> V_88 [ V_152 ] . V_26 ) ;
}
V_142 -> V_148 += V_54 * V_132 -> V_153 ;
}
* V_151 = F_1 ( log , * V_151 ,
F_104 ( V_76 -> V_6 ) ) ;
* V_150 += sizeof( struct V_75 ) +
sizeof( V_79 ) *
( F_104 ( V_76 -> V_6 ) >> ( V_78 - 9 ) ) ;
if ( F_108 ( V_76 -> V_77 . type ) == V_93 )
break;
}
for ( V_152 = 0 ; V_152 < V_15 -> V_86 ; V_152 ++ ) {
void * V_102 ;
T_2 V_42 ;
if ( ! F_47 ( V_87 , & V_15 -> V_88 [ V_152 ] . V_26 ) )
continue;
V_102 = F_52 ( V_15 -> V_88 [ V_152 ] . V_80 ) ;
V_42 = F_25 ( log -> V_40 , V_102 , V_41 ) ;
F_53 ( V_102 ) ;
if ( V_42 != V_15 -> V_88 [ V_152 ] . V_92 )
goto error;
}
for ( V_152 = 0 ; V_152 < V_15 -> V_86 ; V_152 ++ ) {
struct V_154 * V_28 , * V_155 ;
if ( ! F_110 ( V_87 ,
& V_15 -> V_88 [ V_152 ] . V_26 ) )
continue;
V_28 = F_100 ( V_132 -> V_86 [ V_152 ] . V_28 ) ;
if ( V_28 )
F_103 ( V_28 , V_149 , V_41 ,
V_15 -> V_88 [ V_152 ] . V_80 , V_48 , 0 ,
false ) ;
V_155 = F_100 ( V_132 -> V_86 [ V_152 ] . V_156 ) ;
if ( V_155 )
F_103 ( V_155 , V_149 , V_41 ,
V_15 -> V_88 [ V_152 ] . V_80 , V_48 , 0 ,
false ) ;
}
F_10 ( V_15 ) ;
return 0 ;
error:
for ( V_152 = 0 ; V_152 < V_15 -> V_86 ; V_152 ++ )
V_15 -> V_88 [ V_152 ] . V_26 = 0 ;
F_10 ( V_15 ) ;
return - V_103 ;
}
static int F_111 ( struct V_1 * log ,
struct V_141 * V_142 )
{
struct V_131 * V_132 = log -> V_28 -> V_29 -> V_133 ;
struct V_75 * V_76 ;
struct V_35 * V_143 ;
int V_150 ;
T_1 V_151 ;
T_1 V_157 ;
V_143 = F_23 ( V_142 -> V_30 ) ;
V_150 = sizeof( struct V_35 ) ;
V_151 = F_1 ( log , V_142 -> V_145 , V_54 ) ;
while ( V_150 < F_104 ( V_143 -> V_38 ) ) {
int V_158 ;
V_76 = ( void * ) V_143 + V_150 ;
V_157 = F_109 ( V_132 ,
F_105 ( V_76 -> V_71 ) , 0 , & V_158 , NULL ) ;
if ( F_106 ( log , V_142 , V_157 ,
& V_150 , & V_151 ) )
return - V_103 ;
}
return 0 ;
}
static void F_112 ( struct V_1 * log ,
struct V_141 * V_142 )
{
while ( 1 ) {
if ( F_102 ( log , V_142 ) )
return;
if ( F_111 ( log , V_142 ) )
return;
V_142 -> V_65 ++ ;
V_142 -> V_145 = F_1 ( log , V_142 -> V_145 , V_142 -> V_148 ) ;
}
}
static int F_113 ( struct V_1 * log , T_1 V_145 ,
T_4 V_65 )
{
struct V_80 * V_80 ;
struct V_35 * V_143 ;
T_2 V_37 ;
V_80 = F_114 ( V_159 | V_160 ) ;
if ( ! V_80 )
return - V_70 ;
V_143 = F_23 ( V_80 ) ;
V_143 -> V_61 = F_24 ( V_62 ) ;
V_143 -> V_63 = V_64 ;
V_143 -> V_38 = F_24 ( sizeof( struct V_35 ) ) ;
V_143 -> V_65 = F_35 ( V_65 ) ;
V_143 -> V_66 = F_35 ( V_145 ) ;
V_37 = F_25 ( log -> V_40 , V_143 , V_41 ) ;
V_143 -> V_42 = F_24 ( V_37 ) ;
if ( ! F_103 ( log -> V_28 , V_145 , V_41 , V_80 , V_48 ,
V_161 , false ) ) {
F_115 ( V_80 ) ;
return - V_147 ;
}
F_115 ( V_80 ) ;
return 0 ;
}
static int F_116 ( struct V_1 * log )
{
struct V_141 V_142 ;
V_142 . V_145 = log -> V_8 ;
V_142 . V_65 = log -> V_129 ;
V_142 . V_30 = F_114 ( V_159 ) ;
if ( ! V_142 . V_30 )
return - V_70 ;
F_112 ( log , & V_142 ) ;
F_115 ( V_142 . V_30 ) ;
if ( V_142 . V_65 > log -> V_129 ) {
int V_85 ;
V_85 = F_113 ( log , V_142 . V_145 , V_142 . V_65 + 10 ) ;
if ( V_85 )
return V_85 ;
log -> V_65 = V_142 . V_65 + 11 ;
log -> V_9 = F_1 ( log , V_142 . V_145 , V_54 ) ;
F_80 ( log , V_142 . V_145 ) ;
log -> V_8 = V_142 . V_145 ;
log -> V_114 = V_142 . V_145 ;
} else {
log -> V_9 = V_142 . V_145 ;
log -> V_65 = V_142 . V_65 ;
}
return 0 ;
}
static void F_80 ( struct V_1 * log , T_1 V_162 )
{
struct V_29 * V_29 = log -> V_28 -> V_29 ;
log -> V_28 -> V_163 = V_162 ;
F_9 ( V_125 , & V_29 -> V_26 ) ;
}
static int F_117 ( struct V_1 * log )
{
struct V_154 * V_28 = log -> V_28 ;
struct V_80 * V_80 ;
struct V_35 * V_143 ;
T_1 V_162 = log -> V_28 -> V_163 ;
T_2 V_144 , V_164 ;
bool V_165 = false ;
int V_85 ;
if ( V_162 >= V_28 -> V_166 || F_118 ( V_162 , V_54 ) != V_162 )
V_162 = 0 ;
V_80 = F_114 ( V_159 ) ;
if ( ! V_80 )
return - V_70 ;
if ( ! F_103 ( V_28 , V_162 , V_41 , V_80 , V_146 , 0 , false ) ) {
V_85 = - V_147 ;
goto V_167;
}
V_143 = F_23 ( V_80 ) ;
if ( F_104 ( V_143 -> V_61 ) != V_62 ||
V_143 -> V_63 != V_64 ) {
V_165 = true ;
goto V_168;
}
V_144 = F_104 ( V_143 -> V_42 ) ;
V_143 -> V_42 = 0 ;
V_164 = F_25 ( log -> V_40 , V_143 , V_41 ) ;
if ( V_144 != V_164 ) {
V_165 = true ;
goto V_168;
}
if ( F_105 ( V_143 -> V_66 ) != V_162 ) {
V_165 = true ;
goto V_168;
}
V_168:
if ( V_165 ) {
log -> V_129 = F_119 () ;
V_162 = 0 ;
F_113 ( log , V_162 , log -> V_129 ) ;
F_80 ( log , V_162 ) ;
} else
log -> V_129 = F_105 ( V_143 -> V_65 ) ;
log -> V_4 = F_118 ( V_28 -> V_166 , V_54 ) ;
log -> V_118 = log -> V_4 >> V_169 ;
if ( log -> V_118 > V_170 )
log -> V_118 = V_170 ;
log -> V_8 = V_162 ;
log -> V_114 = V_162 ;
F_115 ( V_80 ) ;
return F_116 ( log ) ;
V_167:
F_115 ( V_80 ) ;
return V_85 ;
}
int F_120 ( struct V_131 * V_132 , struct V_154 * V_28 )
{
struct V_171 * V_172 = F_82 ( V_28 -> V_50 ) ;
struct V_1 * log ;
if ( V_41 != 4096 )
return - V_103 ;
log = F_121 ( sizeof( * log ) , V_159 ) ;
if ( ! log )
return - V_70 ;
log -> V_28 = V_28 ;
log -> V_32 = F_47 ( V_173 , & V_172 -> V_174 ) != 0 ;
log -> V_40 = F_25 ( ~ 0 , V_28 -> V_29 -> V_175 ,
sizeof( V_28 -> V_29 -> V_175 ) ) ;
F_122 ( & log -> V_106 ) ;
F_123 ( & log -> V_19 ) ;
F_33 ( & log -> V_68 ) ;
F_33 ( & log -> V_23 ) ;
F_33 ( & log -> V_121 ) ;
F_33 ( & log -> V_22 ) ;
F_124 ( & log -> V_120 ) ;
log -> V_176 = F_125 ( V_10 , 0 ) ;
if ( ! log -> V_176 )
goto V_176;
log -> V_57 = F_126 ( V_177 , log -> V_176 ) ;
if ( ! log -> V_57 )
goto V_57;
log -> V_47 = F_127 ( V_177 , 0 ) ;
if ( ! log -> V_47 )
goto V_178;
log -> V_31 = F_128 ( V_177 , 0 ) ;
if ( ! log -> V_31 )
goto V_179;
log -> V_137 = F_96 ( F_93 ,
log -> V_28 -> V_29 , L_1 ) ;
if ( ! log -> V_137 )
goto V_137;
F_129 ( & log -> V_119 ) ;
F_33 ( & log -> V_109 ) ;
F_33 ( & log -> V_108 ) ;
F_123 ( & log -> V_107 ) ;
if ( F_117 ( log ) )
goto error;
F_130 ( V_132 -> log , log ) ;
F_9 ( V_139 , & V_132 -> V_29 -> V_26 ) ;
return 0 ;
error:
F_97 ( & log -> V_137 ) ;
V_137:
F_131 ( log -> V_31 ) ;
V_179:
F_132 ( log -> V_47 ) ;
V_178:
F_131 ( log -> V_57 ) ;
V_57:
F_133 ( log -> V_176 ) ;
V_176:
F_134 ( log ) ;
return - V_103 ;
}
void F_135 ( struct V_1 * log )
{
F_97 ( & log -> V_137 ) ;
F_131 ( log -> V_31 ) ;
F_132 ( log -> V_47 ) ;
F_131 ( log -> V_57 ) ;
F_133 ( log -> V_176 ) ;
F_134 ( log ) ;
}
