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
F_26 ( V_44 , V_11 -> V_45 ) ;
}
static struct V_24 * F_27 ( struct V_1 * log )
{
struct V_24 * V_24 = F_28 ( V_46 , V_47 , log -> V_48 ) ;
V_24 -> V_49 = V_44 ;
V_24 -> V_50 = log -> V_28 -> V_51 ;
V_24 -> V_52 . V_53 = log -> V_28 -> V_54 + log -> V_9 ;
return V_24 ;
}
static void F_29 ( struct V_1 * log , struct V_10 * V_11 )
{
log -> V_9 = F_1 ( log , log -> V_9 , V_55 ) ;
if ( log -> V_9 == 0 )
V_11 -> V_56 = true ;
V_11 -> V_57 = log -> V_9 ;
}
static struct V_10 * F_30 ( struct V_1 * log )
{
struct V_10 * V_11 ;
struct V_35 * V_36 ;
V_11 = F_31 ( log -> V_58 , V_59 ) ;
if ( ! V_11 )
return NULL ;
memset ( V_11 , 0 , sizeof( * V_11 ) ) ;
V_11 -> log = log ;
F_32 ( & V_11 -> V_21 ) ;
F_32 ( & V_11 -> V_60 ) ;
V_11 -> V_13 = V_61 ;
V_11 -> V_30 = F_31 ( log -> V_31 , V_46 ) ;
V_36 = F_23 ( V_11 -> V_30 ) ;
F_33 ( V_36 ) ;
V_36 -> V_62 = F_24 ( V_63 ) ;
V_36 -> V_64 = V_65 ;
V_36 -> V_66 = F_34 ( log -> V_66 ) ;
V_36 -> V_67 = F_34 ( log -> V_9 ) ;
V_11 -> V_9 = log -> V_9 ;
V_11 -> V_39 = sizeof( struct V_35 ) ;
V_11 -> V_66 = log -> V_66 ++ ;
V_11 -> V_45 = F_27 ( log ) ;
V_11 -> V_45 -> V_68 = F_15 ;
V_11 -> V_45 -> V_25 = V_11 ;
F_35 ( V_11 -> V_45 , V_11 -> V_30 , V_41 , 0 ) ;
F_29 ( log , V_11 ) ;
F_36 ( & log -> V_19 ) ;
F_37 ( & V_11 -> V_21 , & log -> V_69 ) ;
F_38 ( & log -> V_19 ) ;
return V_11 ;
}
static int F_39 ( struct V_1 * log , unsigned int V_70 )
{
if ( log -> V_34 &&
log -> V_34 -> V_39 + V_70 > V_41 )
F_22 ( log ) ;
if ( ! log -> V_34 ) {
log -> V_34 = F_30 ( log ) ;
if ( ! log -> V_34 )
return - V_71 ;
}
return 0 ;
}
static void F_40 ( struct V_1 * log , T_3 type ,
T_1 V_72 ,
T_2 V_73 , T_2 V_74 ,
bool V_75 )
{
struct V_10 * V_11 = log -> V_34 ;
struct V_76 * V_77 ;
V_77 = F_23 ( V_11 -> V_30 ) + V_11 -> V_39 ;
V_77 -> V_78 . type = F_41 ( type ) ;
V_77 -> V_78 . V_26 = F_41 ( 0 ) ;
V_77 -> V_6 = F_24 ( ( 1 + ! ! V_75 ) <<
( V_79 - 9 ) ) ;
V_77 -> V_72 = F_34 ( V_72 ) ;
V_77 -> V_42 [ 0 ] = F_24 ( V_73 ) ;
if ( V_75 )
V_77 -> V_42 [ 1 ] = F_24 ( V_74 ) ;
V_11 -> V_39 += sizeof( struct V_76 ) +
sizeof( V_80 ) * ( 1 + ! ! V_75 ) ;
}
static void F_42 ( struct V_1 * log , struct V_81 * V_81 )
{
struct V_10 * V_11 = log -> V_34 ;
if ( V_11 -> V_56 ) {
struct V_24 * V_82 = V_11 -> V_45 ;
V_11 -> V_45 = F_27 ( log ) ;
F_43 ( V_11 -> V_45 , V_82 ) ;
F_26 ( V_44 , V_82 ) ;
}
if ( ! F_35 ( V_11 -> V_45 , V_81 , V_41 , 0 ) )
F_44 () ;
F_29 ( log , V_11 ) ;
}
static int F_45 ( struct V_1 * log , struct V_14 * V_15 ,
int V_83 , int V_84 )
{
int V_85 ;
int V_38 ;
int V_86 ;
struct V_10 * V_11 ;
V_38 =
( ( sizeof( struct V_76 ) + sizeof( V_80 ) )
* V_83 ) +
sizeof( struct V_76 ) +
sizeof( V_80 ) * V_84 ;
V_86 = F_39 ( log , V_38 ) ;
if ( V_86 )
return V_86 ;
V_11 = log -> V_34 ;
for ( V_85 = 0 ; V_85 < V_15 -> V_87 ; V_85 ++ ) {
if ( ! F_46 ( V_88 , & V_15 -> V_89 [ V_85 ] . V_26 ) )
continue;
if ( V_85 == V_15 -> V_90 || V_85 == V_15 -> V_91 )
continue;
F_40 ( log , V_92 ,
F_47 ( V_15 , V_85 , 0 ) ,
V_15 -> V_89 [ V_85 ] . V_93 , 0 , false ) ;
F_42 ( log , V_15 -> V_89 [ V_85 ] . V_81 ) ;
}
if ( V_15 -> V_91 >= 0 ) {
F_40 ( log , V_94 ,
V_15 -> V_95 , V_15 -> V_89 [ V_15 -> V_90 ] . V_93 ,
V_15 -> V_89 [ V_15 -> V_91 ] . V_93 , true ) ;
F_42 ( log , V_15 -> V_89 [ V_15 -> V_90 ] . V_81 ) ;
F_42 ( log , V_15 -> V_89 [ V_15 -> V_91 ] . V_81 ) ;
} else {
F_40 ( log , V_94 ,
V_15 -> V_95 , V_15 -> V_89 [ V_15 -> V_90 ] . V_93 ,
0 , false ) ;
F_42 ( log , V_15 -> V_89 [ V_15 -> V_90 ] . V_81 ) ;
}
F_37 ( & V_15 -> V_17 , & V_11 -> V_60 ) ;
F_48 ( & V_11 -> V_96 ) ;
V_15 -> V_97 = V_11 ;
return 0 ;
}
int F_49 ( struct V_1 * log , struct V_14 * V_15 )
{
int V_98 = 0 ;
int V_83 , V_84 ;
int V_38 ;
int V_99 ;
int V_85 ;
int V_86 = 0 ;
if ( ! log )
return - V_100 ;
if ( V_15 -> V_97 || ! F_46 ( V_88 , & V_15 -> V_89 [ V_15 -> V_90 ] . V_26 ) ||
F_46 ( V_101 , & V_15 -> V_13 ) ) {
F_50 ( V_102 , & V_15 -> V_13 ) ;
return - V_100 ;
}
for ( V_85 = 0 ; V_85 < V_15 -> V_87 ; V_85 ++ ) {
void * V_103 ;
if ( ! F_46 ( V_88 , & V_15 -> V_89 [ V_85 ] . V_26 ) )
continue;
V_98 ++ ;
if ( F_46 ( V_102 , & V_15 -> V_13 ) )
continue;
V_103 = F_51 ( V_15 -> V_89 [ V_85 ] . V_81 ) ;
V_15 -> V_89 [ V_85 ] . V_93 = F_25 ( log -> V_40 ,
V_103 , V_41 ) ;
F_52 ( V_103 ) ;
}
V_84 = 1 + ! ! ( V_15 -> V_91 >= 0 ) ;
V_83 = V_98 - V_84 ;
V_38 =
( ( sizeof( struct V_76 ) + sizeof( V_80 ) )
* V_83 ) +
sizeof( struct V_76 ) +
sizeof( V_80 ) * V_84 ;
if ( V_38 + sizeof( struct V_35 ) > V_41 )
return - V_104 ;
F_9 ( V_102 , & V_15 -> V_13 ) ;
F_50 ( V_105 , & V_15 -> V_13 ) ;
F_48 ( & V_15 -> V_106 ) ;
F_53 ( & log -> V_107 ) ;
V_99 = ( 1 + V_98 ) << ( V_79 - 9 ) ;
if ( ! F_3 ( log , V_99 ) ) {
F_54 ( & log -> V_108 ) ;
F_37 ( & V_15 -> V_17 , & log -> V_109 ) ;
F_55 ( & log -> V_108 ) ;
F_56 ( log , V_99 ) ;
} else {
V_86 = F_45 ( log , V_15 , V_83 , V_84 ) ;
if ( V_86 ) {
F_36 ( & log -> V_19 ) ;
F_37 ( & V_15 -> V_17 , & log -> V_110 ) ;
F_38 ( & log -> V_19 ) ;
}
}
F_57 ( & log -> V_107 ) ;
return 0 ;
}
void F_58 ( struct V_1 * log )
{
if ( ! log )
return;
F_53 ( & log -> V_107 ) ;
F_22 ( log ) ;
F_57 ( & log -> V_107 ) ;
}
int F_59 ( struct V_1 * log , struct V_24 * V_24 )
{
if ( ! log )
return - V_111 ;
if ( V_24 -> V_52 . V_112 == 0 ) {
F_60 ( V_24 ) ;
return 0 ;
}
V_24 -> V_49 &= ~ V_113 ;
return - V_100 ;
}
static void F_61 ( struct V_1 * log )
{
struct V_14 * V_15 ;
F_54 ( & log -> V_108 ) ;
while ( ! F_62 ( & log -> V_109 ) ) {
V_15 = F_63 ( & log -> V_109 ,
struct V_14 , V_17 ) ;
F_8 ( & V_15 -> V_17 ) ;
F_9 ( V_18 , & V_15 -> V_13 ) ;
F_10 ( V_15 ) ;
}
F_55 ( & log -> V_108 ) ;
}
static T_1 F_64 ( struct V_1 * log )
{
return F_2 ( log , log -> V_8 ,
log -> V_114 ) ;
}
static void F_65 ( struct V_1 * log )
{
struct V_14 * V_15 ;
F_12 ( & log -> V_19 ) ;
if ( ! F_62 ( & log -> V_110 ) ) {
V_15 = F_63 ( & log -> V_110 ,
struct V_14 , V_17 ) ;
F_8 ( & V_15 -> V_17 ) ;
F_9 ( V_18 , & V_15 -> V_13 ) ;
F_10 ( V_15 ) ;
}
}
static bool F_66 ( struct V_1 * log )
{
struct V_10 * V_11 , * V_16 ;
bool V_115 = false ;
F_12 ( & log -> V_19 ) ;
F_7 (io, next, &log->finished_ios, log_sibling) {
if ( V_11 -> V_13 < V_116 )
break;
log -> V_114 = V_11 -> V_9 ;
log -> V_117 = V_11 -> V_66 ;
F_67 ( & V_11 -> V_21 ) ;
F_18 ( V_11 , log -> V_58 ) ;
F_65 ( log ) ;
V_115 = true ;
}
return V_115 ;
}
static void F_68 ( struct V_10 * V_11 )
{
struct V_1 * log = V_11 -> log ;
unsigned long V_26 ;
F_19 ( & log -> V_19 , V_26 ) ;
F_4 ( V_11 , V_116 ) ;
if ( ! F_66 ( log ) ) {
F_20 ( & log -> V_19 , V_26 ) ;
return;
}
if ( F_64 ( log ) > log -> V_118 )
F_56 ( log , 0 ) ;
F_20 ( & log -> V_19 , V_26 ) ;
F_69 ( & log -> V_119 ) ;
}
void F_70 ( struct V_14 * V_15 )
{
struct V_10 * V_11 ;
V_11 = V_15 -> V_97 ;
V_15 -> V_97 = NULL ;
if ( V_11 && F_71 ( & V_11 -> V_96 ) )
F_68 ( V_11 ) ;
}
static void F_72 ( struct V_24 * V_24 )
{
struct V_1 * log = F_73 ( V_24 , struct V_1 ,
V_120 ) ;
unsigned long V_26 ;
struct V_10 * V_11 ;
if ( V_24 -> V_27 )
F_16 ( log -> V_28 -> V_29 , log -> V_28 ) ;
F_19 ( & log -> V_19 , V_26 ) ;
F_74 (io, &log->flushing_ios, log_sibling)
F_6 ( V_11 ) ;
F_75 ( & log -> V_121 , & log -> V_22 ) ;
F_20 ( & log -> V_19 , V_26 ) ;
}
void F_76 ( struct V_1 * log )
{
bool V_122 ;
if ( ! log || ! log -> V_32 )
return;
F_36 ( & log -> V_19 ) ;
if ( ! F_62 ( & log -> V_121 ) ) {
F_38 ( & log -> V_19 ) ;
return;
}
F_75 ( & log -> V_23 , & log -> V_121 ) ;
V_122 = ! F_62 ( & log -> V_121 ) ;
F_38 ( & log -> V_19 ) ;
if ( ! V_122 )
return;
F_77 ( & log -> V_120 ) ;
log -> V_120 . V_50 = log -> V_28 -> V_51 ;
log -> V_120 . V_68 = F_72 ;
F_26 ( V_123 , & log -> V_120 ) ;
}
static void F_78 ( struct V_1 * log ,
T_1 V_5 )
{
struct V_124 * V_51 = log -> V_28 -> V_51 ;
struct V_29 * V_29 ;
F_79 ( log , V_5 ) ;
if ( ! F_80 ( F_81 ( V_51 ) ) )
return;
V_29 = log -> V_28 -> V_29 ;
if ( ! log -> V_125 ) {
F_82 ( & V_29 -> V_26 , 0 ,
F_83 ( V_126 ) | F_83 ( V_127 ) ) ;
F_21 ( V_29 -> V_33 ) ;
F_84 ( V_29 -> V_128 ,
! F_46 ( V_127 , & V_29 -> V_26 ) ||
log -> V_125 ) ;
if ( log -> V_125 )
F_85 ( V_29 , 1 ) ;
} else {
F_5 ( ! F_86 ( V_29 ) ) ;
F_85 ( V_29 , 1 ) ;
}
if ( log -> V_8 < V_5 ) {
F_87 ( V_51 ,
log -> V_8 + log -> V_28 -> V_54 ,
V_5 - log -> V_8 , V_46 , 0 ) ;
} else {
F_87 ( V_51 ,
log -> V_8 + log -> V_28 -> V_54 ,
log -> V_4 - log -> V_8 ,
V_46 , 0 ) ;
F_87 ( V_51 , log -> V_28 -> V_54 , V_5 ,
V_46 , 0 ) ;
}
}
static void F_88 ( struct V_1 * log )
{
T_1 V_129 = F_89 ( & log -> V_129 , 0 ) ;
T_1 V_130 ;
T_1 V_114 ;
T_4 V_117 ;
F_36 ( & log -> V_19 ) ;
while ( 1 ) {
V_130 = F_64 ( log ) ;
if ( V_130 >= V_129 ||
( F_62 ( & log -> V_69 ) &&
F_62 ( & log -> V_23 ) &&
F_62 ( & log -> V_121 ) &&
F_62 ( & log -> V_22 ) ) )
break;
F_21 ( log -> V_28 -> V_29 -> V_33 ) ;
F_90 ( log -> V_119 ,
F_64 ( log ) > V_130 ,
log -> V_19 ) ;
}
V_114 = log -> V_114 ;
V_117 = log -> V_117 ;
F_38 ( & log -> V_19 ) ;
F_91 ( V_130 < 0 ) ;
if ( V_130 == 0 )
return;
F_78 ( log , V_114 ) ;
F_53 ( & log -> V_107 ) ;
log -> V_8 = V_114 ;
log -> V_131 = V_117 ;
F_57 ( & log -> V_107 ) ;
F_61 ( log ) ;
}
static void F_92 ( struct V_132 * V_33 )
{
struct V_29 * V_29 = V_33 -> V_29 ;
struct V_133 * V_134 = V_29 -> V_135 ;
struct V_1 * log = V_134 -> log ;
if ( ! log )
return;
F_88 ( log ) ;
}
static void F_56 ( struct V_1 * log , T_1 V_136 )
{
unsigned long V_137 ;
unsigned long V_138 = ( unsigned long ) V_136 ;
do {
V_137 = log -> V_129 ;
if ( V_138 < V_137 )
return;
} while ( F_93 ( & log -> V_129 , V_137 , V_138 ) != V_137 );
F_21 ( log -> V_139 ) ;
}
void F_94 ( struct V_1 * log , int V_13 )
{
struct V_29 * V_29 ;
if ( ! log || V_13 == 2 )
return;
if ( V_13 == 0 ) {
log -> V_125 = 0 ;
if ( log -> V_139 )
return;
log -> V_139 = F_95 ( F_92 ,
log -> V_28 -> V_29 , L_1 ) ;
} else if ( V_13 == 1 ) {
log -> V_125 = 1 ;
V_29 = log -> V_28 -> V_29 ;
F_69 ( & V_29 -> V_128 ) ;
F_56 ( log , - 1L ) ;
F_96 ( & log -> V_139 ) ;
F_88 ( log ) ;
}
}
bool F_97 ( struct V_133 * V_134 )
{
struct V_1 * log ;
bool V_86 ;
F_98 () ;
log = F_99 ( V_134 -> log ) ;
if ( ! log )
V_86 = F_46 ( V_140 , & V_134 -> V_29 -> V_26 ) ;
else
V_86 = F_46 ( V_141 , & log -> V_28 -> V_26 ) ;
F_100 () ;
return V_86 ;
}
static int F_101 ( struct V_1 * log ,
struct V_142 * V_143 )
{
struct V_81 * V_81 = V_143 -> V_30 ;
struct V_35 * V_144 ;
T_2 V_37 , V_145 ;
if ( ! F_102 ( log -> V_28 , V_143 -> V_146 , V_41 , V_81 , V_147 , false ) )
return - V_148 ;
V_144 = F_23 ( V_81 ) ;
V_145 = F_103 ( V_144 -> V_42 ) ;
V_144 -> V_42 = 0 ;
if ( F_103 ( V_144 -> V_62 ) != V_63 ||
F_104 ( V_144 -> V_66 ) != V_143 -> V_66 ||
V_144 -> V_64 != V_65 ||
F_104 ( V_144 -> V_67 ) != V_143 -> V_146 )
return - V_104 ;
V_37 = F_25 ( log -> V_40 , V_144 , V_41 ) ;
if ( V_145 != V_37 )
return - V_104 ;
if ( F_103 ( V_144 -> V_38 ) > V_41 )
return - V_104 ;
V_143 -> V_149 = V_55 ;
return 0 ;
}
static int F_105 ( struct V_1 * log ,
struct V_142 * V_143 ,
T_1 V_150 ,
int * V_151 , T_1 * V_152 )
{
struct V_133 * V_134 = log -> V_28 -> V_29 -> V_135 ;
struct V_14 * V_15 ;
struct V_76 * V_77 ;
int V_153 ;
V_15 = F_106 ( V_134 , V_150 , 0 , 0 , 0 ) ;
while ( 1 ) {
V_77 = F_23 ( V_143 -> V_30 ) + * V_151 ;
if ( F_107 ( V_77 -> V_78 . type ) == V_92 ) {
F_108 ( V_134 ,
F_104 ( V_77 -> V_72 ) , 0 ,
& V_153 , V_15 ) ;
F_102 ( log -> V_28 , * V_152 , V_41 ,
V_15 -> V_89 [ V_153 ] . V_81 , V_147 , false ) ;
V_15 -> V_89 [ V_153 ] . V_93 =
F_103 ( V_77 -> V_42 [ 0 ] ) ;
F_9 ( V_88 , & V_15 -> V_89 [ V_153 ] . V_26 ) ;
V_143 -> V_149 += V_55 ;
} else {
V_153 = V_15 -> V_90 ;
F_102 ( log -> V_28 , * V_152 , V_41 ,
V_15 -> V_89 [ V_153 ] . V_81 , V_147 , false ) ;
V_15 -> V_89 [ V_153 ] . V_93 =
F_103 ( V_77 -> V_42 [ 0 ] ) ;
F_9 ( V_88 , & V_15 -> V_89 [ V_153 ] . V_26 ) ;
if ( V_15 -> V_91 >= 0 ) {
V_153 = V_15 -> V_91 ;
F_102 ( log -> V_28 ,
F_1 ( log , * V_152 , V_55 ) ,
V_41 , V_15 -> V_89 [ V_153 ] . V_81 ,
V_147 , false ) ;
V_15 -> V_89 [ V_153 ] . V_93 =
F_103 ( V_77 -> V_42 [ 1 ] ) ;
F_9 ( V_88 ,
& V_15 -> V_89 [ V_153 ] . V_26 ) ;
}
V_143 -> V_149 += V_55 * V_134 -> V_154 ;
}
* V_152 = F_1 ( log , * V_152 ,
F_103 ( V_77 -> V_6 ) ) ;
* V_151 += sizeof( struct V_76 ) +
sizeof( V_80 ) *
( F_103 ( V_77 -> V_6 ) >> ( V_79 - 9 ) ) ;
if ( F_107 ( V_77 -> V_78 . type ) == V_94 )
break;
}
for ( V_153 = 0 ; V_153 < V_15 -> V_87 ; V_153 ++ ) {
void * V_103 ;
T_2 V_42 ;
if ( ! F_46 ( V_88 , & V_15 -> V_89 [ V_153 ] . V_26 ) )
continue;
V_103 = F_51 ( V_15 -> V_89 [ V_153 ] . V_81 ) ;
V_42 = F_25 ( log -> V_40 , V_103 , V_41 ) ;
F_52 ( V_103 ) ;
if ( V_42 != V_15 -> V_89 [ V_153 ] . V_93 )
goto error;
}
for ( V_153 = 0 ; V_153 < V_15 -> V_87 ; V_153 ++ ) {
struct V_155 * V_28 , * V_156 ;
if ( ! F_109 ( V_88 ,
& V_15 -> V_89 [ V_153 ] . V_26 ) )
continue;
V_28 = F_99 ( V_134 -> V_87 [ V_153 ] . V_28 ) ;
if ( V_28 )
F_102 ( V_28 , V_150 , V_41 ,
V_15 -> V_89 [ V_153 ] . V_81 , V_44 , false ) ;
V_156 = F_99 ( V_134 -> V_87 [ V_153 ] . V_157 ) ;
if ( V_156 )
F_102 ( V_156 , V_150 , V_41 ,
V_15 -> V_89 [ V_153 ] . V_81 , V_44 , false ) ;
}
F_10 ( V_15 ) ;
return 0 ;
error:
for ( V_153 = 0 ; V_153 < V_15 -> V_87 ; V_153 ++ )
V_15 -> V_89 [ V_153 ] . V_26 = 0 ;
F_10 ( V_15 ) ;
return - V_104 ;
}
static int F_110 ( struct V_1 * log ,
struct V_142 * V_143 )
{
struct V_133 * V_134 = log -> V_28 -> V_29 -> V_135 ;
struct V_76 * V_77 ;
struct V_35 * V_144 ;
int V_151 ;
T_1 V_152 ;
T_1 V_158 ;
V_144 = F_23 ( V_143 -> V_30 ) ;
V_151 = sizeof( struct V_35 ) ;
V_152 = F_1 ( log , V_143 -> V_146 , V_55 ) ;
while ( V_151 < F_103 ( V_144 -> V_38 ) ) {
int V_159 ;
V_77 = ( void * ) V_144 + V_151 ;
V_158 = F_108 ( V_134 ,
F_104 ( V_77 -> V_72 ) , 0 , & V_159 , NULL ) ;
if ( F_105 ( log , V_143 , V_158 ,
& V_151 , & V_152 ) )
return - V_104 ;
}
return 0 ;
}
static void F_111 ( struct V_1 * log ,
struct V_142 * V_143 )
{
while ( 1 ) {
if ( F_101 ( log , V_143 ) )
return;
if ( F_110 ( log , V_143 ) )
return;
V_143 -> V_66 ++ ;
V_143 -> V_146 = F_1 ( log , V_143 -> V_146 , V_143 -> V_149 ) ;
}
}
static int F_112 ( struct V_1 * log , T_1 V_146 ,
T_4 V_66 )
{
struct V_81 * V_81 ;
struct V_35 * V_144 ;
T_2 V_37 ;
V_81 = F_113 ( V_160 | V_161 ) ;
if ( ! V_81 )
return - V_71 ;
V_144 = F_23 ( V_81 ) ;
V_144 -> V_62 = F_24 ( V_63 ) ;
V_144 -> V_64 = V_65 ;
V_144 -> V_38 = F_24 ( sizeof( struct V_35 ) ) ;
V_144 -> V_66 = F_34 ( V_66 ) ;
V_144 -> V_67 = F_34 ( V_146 ) ;
V_37 = F_25 ( log -> V_40 , V_144 , V_41 ) ;
V_144 -> V_42 = F_24 ( V_37 ) ;
if ( ! F_102 ( log -> V_28 , V_146 , V_41 , V_81 , V_162 , false ) ) {
F_114 ( V_81 ) ;
return - V_148 ;
}
F_114 ( V_81 ) ;
return 0 ;
}
static int F_115 ( struct V_1 * log )
{
struct V_142 V_143 ;
V_143 . V_146 = log -> V_8 ;
V_143 . V_66 = log -> V_131 ;
V_143 . V_30 = F_113 ( V_160 ) ;
if ( ! V_143 . V_30 )
return - V_71 ;
F_111 ( log , & V_143 ) ;
F_114 ( V_143 . V_30 ) ;
if ( V_143 . V_66 > log -> V_131 + 1 ) {
int V_86 ;
V_86 = F_112 ( log , V_143 . V_146 , V_143 . V_66 + 10 ) ;
if ( V_86 )
return V_86 ;
log -> V_66 = V_143 . V_66 + 11 ;
log -> V_9 = F_1 ( log , V_143 . V_146 , V_55 ) ;
F_79 ( log , V_143 . V_146 ) ;
} else {
log -> V_9 = V_143 . V_146 ;
log -> V_66 = V_143 . V_66 ;
}
return 0 ;
}
static void F_79 ( struct V_1 * log , T_1 V_163 )
{
struct V_29 * V_29 = log -> V_28 -> V_29 ;
log -> V_28 -> V_164 = V_163 ;
F_9 ( V_126 , & V_29 -> V_26 ) ;
}
static int F_116 ( struct V_1 * log )
{
struct V_155 * V_28 = log -> V_28 ;
struct V_81 * V_81 ;
struct V_35 * V_144 ;
T_1 V_163 = log -> V_28 -> V_164 ;
T_2 V_145 , V_165 ;
bool V_166 = false ;
int V_86 ;
if ( V_163 >= V_28 -> V_167 || F_117 ( V_163 , V_55 ) != V_163 )
V_163 = 0 ;
V_81 = F_113 ( V_160 ) ;
if ( ! V_81 )
return - V_71 ;
if ( ! F_102 ( V_28 , V_163 , V_41 , V_81 , V_147 , false ) ) {
V_86 = - V_148 ;
goto V_168;
}
V_144 = F_23 ( V_81 ) ;
if ( F_103 ( V_144 -> V_62 ) != V_63 ||
V_144 -> V_64 != V_65 ) {
V_166 = true ;
goto V_169;
}
V_145 = F_103 ( V_144 -> V_42 ) ;
V_144 -> V_42 = 0 ;
V_165 = F_25 ( log -> V_40 , V_144 , V_41 ) ;
if ( V_145 != V_165 ) {
V_166 = true ;
goto V_169;
}
if ( F_104 ( V_144 -> V_67 ) != V_163 ) {
V_166 = true ;
goto V_169;
}
V_169:
if ( V_166 ) {
log -> V_131 = F_118 () ;
V_163 = 0 ;
F_79 ( log , V_163 ) ;
} else
log -> V_131 = F_104 ( V_144 -> V_66 ) ;
log -> V_4 = F_117 ( V_28 -> V_167 , V_55 ) ;
log -> V_118 = log -> V_4 >> V_170 ;
if ( log -> V_118 > V_171 )
log -> V_118 = V_171 ;
log -> V_8 = V_163 ;
F_114 ( V_81 ) ;
return F_115 ( log ) ;
V_168:
F_114 ( V_81 ) ;
return V_86 ;
}
int F_119 ( struct V_133 * V_134 , struct V_155 * V_28 )
{
struct V_172 * V_173 = F_81 ( V_28 -> V_51 ) ;
struct V_1 * log ;
if ( V_41 != 4096 )
return - V_104 ;
log = F_120 ( sizeof( * log ) , V_160 ) ;
if ( ! log )
return - V_71 ;
log -> V_28 = V_28 ;
log -> V_32 = F_46 ( V_174 , & V_173 -> V_175 ) != 0 ;
log -> V_40 = F_25 ( ~ 0 , V_28 -> V_29 -> V_176 ,
sizeof( V_28 -> V_29 -> V_176 ) ) ;
F_121 ( & log -> V_107 ) ;
F_122 ( & log -> V_19 ) ;
F_32 ( & log -> V_69 ) ;
F_32 ( & log -> V_23 ) ;
F_32 ( & log -> V_121 ) ;
F_32 ( & log -> V_22 ) ;
F_123 ( & log -> V_120 ) ;
log -> V_177 = F_124 ( V_10 , 0 ) ;
if ( ! log -> V_177 )
goto V_177;
log -> V_58 = F_125 ( V_178 , log -> V_177 ) ;
if ( ! log -> V_58 )
goto V_58;
log -> V_48 = F_126 ( V_178 , 0 ) ;
if ( ! log -> V_48 )
goto V_179;
log -> V_31 = F_127 ( V_178 , 0 ) ;
if ( ! log -> V_31 )
goto V_180;
log -> V_139 = F_95 ( F_92 ,
log -> V_28 -> V_29 , L_1 ) ;
if ( ! log -> V_139 )
goto V_139;
F_128 ( & log -> V_119 ) ;
F_32 ( & log -> V_110 ) ;
F_32 ( & log -> V_109 ) ;
F_122 ( & log -> V_108 ) ;
if ( F_116 ( log ) )
goto error;
F_129 ( V_134 -> log , log ) ;
F_9 ( V_140 , & V_134 -> V_29 -> V_26 ) ;
return 0 ;
error:
F_96 ( & log -> V_139 ) ;
V_139:
F_130 ( log -> V_31 ) ;
V_180:
F_131 ( log -> V_48 ) ;
V_179:
F_130 ( log -> V_58 ) ;
V_58:
F_132 ( log -> V_177 ) ;
V_177:
F_133 ( log ) ;
return - V_104 ;
}
void F_134 ( struct V_1 * log )
{
F_96 ( & log -> V_139 ) ;
F_130 ( log -> V_31 ) ;
F_131 ( log -> V_48 ) ;
F_130 ( log -> V_58 ) ;
F_132 ( log -> V_177 ) ;
F_133 ( log ) ;
}
