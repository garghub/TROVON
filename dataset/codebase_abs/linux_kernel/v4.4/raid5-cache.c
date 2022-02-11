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
static void F_4 ( struct V_1 * log , struct V_10 * V_11 )
{
F_5 ( V_11 -> V_12 ) ;
F_6 ( log -> V_13 , V_11 ) ;
}
static void F_7 ( struct V_14 * V_15 , struct V_14 * V_16 ,
enum V_17 V_18 )
{
struct V_10 * V_11 ;
while ( ! F_8 ( V_15 ) ) {
V_11 = F_9 ( V_15 , struct V_10 , V_19 ) ;
if ( V_11 -> V_18 >= V_18 )
F_10 ( & V_11 -> V_19 , V_16 ) ;
else
break;
}
}
static void F_11 ( struct V_10 * V_11 ,
enum V_17 V_18 )
{
if ( F_12 ( V_11 -> V_18 >= V_18 ) )
return;
V_11 -> V_18 = V_18 ;
}
static void F_13 ( struct V_10 * V_11 )
{
struct V_20 * V_21 , * V_22 ;
F_14 (sh, next, &io->stripe_list, log_list) {
F_15 ( & V_21 -> V_23 ) ;
F_16 ( V_24 , & V_21 -> V_18 ) ;
F_17 ( V_21 ) ;
}
}
static void F_18 ( struct V_1 * log )
{
struct V_10 * V_11 , * V_22 ;
F_19 ( & log -> V_25 ) ;
F_14 (io, next, &log->running_ios, log_sibling) {
if ( V_11 -> V_18 < V_26 )
break;
F_10 ( & V_11 -> V_19 , & log -> V_27 ) ;
F_13 ( V_11 ) ;
}
}
static void F_20 ( struct V_28 * V_28 )
{
struct V_10 * V_11 = V_28 -> V_29 ;
struct V_1 * log = V_11 -> log ;
unsigned long V_30 ;
if ( V_28 -> V_31 )
F_21 ( log -> V_32 -> V_33 , log -> V_32 ) ;
F_22 ( V_28 ) ;
F_23 ( & log -> V_25 , V_30 ) ;
F_11 ( V_11 , V_26 ) ;
if ( log -> V_34 )
F_7 ( & log -> V_35 , & log -> V_36 ,
V_26 ) ;
else
F_18 ( log ) ;
F_24 ( & log -> V_25 , V_30 ) ;
if ( log -> V_34 )
F_25 ( log -> V_32 -> V_33 -> V_37 ) ;
}
static void F_26 ( struct V_1 * log )
{
struct V_10 * V_11 = log -> V_38 ;
struct V_39 * V_40 ;
unsigned long V_30 ;
T_2 V_41 ;
if ( ! V_11 )
return;
V_40 = F_27 ( V_11 -> V_12 ) ;
V_40 -> V_42 = F_28 ( V_11 -> V_43 ) ;
V_41 = F_29 ( log -> V_44 , V_40 , V_45 ) ;
V_40 -> V_46 = F_28 ( V_41 ) ;
log -> V_38 = NULL ;
F_23 ( & log -> V_25 , V_30 ) ;
F_11 ( V_11 , V_47 ) ;
F_24 ( & log -> V_25 , V_30 ) ;
F_30 ( V_48 , V_11 -> V_49 ) ;
}
static struct V_28 * F_31 ( struct V_1 * log )
{
struct V_28 * V_28 = F_32 ( V_50 | V_51 , V_52 ) ;
V_28 -> V_53 = V_48 ;
V_28 -> V_54 = log -> V_32 -> V_55 ;
V_28 -> V_56 . V_57 = log -> V_32 -> V_58 + log -> V_9 ;
return V_28 ;
}
static void F_33 ( struct V_1 * log , struct V_10 * V_11 )
{
log -> V_9 = F_1 ( log , log -> V_9 , V_59 ) ;
if ( log -> V_9 == 0 )
V_11 -> V_60 = true ;
V_11 -> V_61 = log -> V_9 ;
}
static struct V_10 * F_34 ( struct V_1 * log )
{
struct V_10 * V_11 ;
struct V_39 * V_40 ;
V_11 = F_35 ( log -> V_13 , V_50 | V_51 ) ;
V_11 -> log = log ;
F_36 ( & V_11 -> V_19 ) ;
F_36 ( & V_11 -> V_62 ) ;
V_11 -> V_18 = V_63 ;
V_11 -> V_12 = F_37 ( V_50 | V_51 | V_64 ) ;
V_40 = F_27 ( V_11 -> V_12 ) ;
V_40 -> V_65 = F_28 ( V_66 ) ;
V_40 -> V_67 = V_68 ;
V_40 -> V_69 = F_38 ( log -> V_69 ) ;
V_40 -> V_70 = F_38 ( log -> V_9 ) ;
V_11 -> V_9 = log -> V_9 ;
V_11 -> V_43 = sizeof( struct V_39 ) ;
V_11 -> V_69 = log -> V_69 ++ ;
V_11 -> V_49 = F_31 ( log ) ;
V_11 -> V_49 -> V_71 = F_20 ;
V_11 -> V_49 -> V_29 = V_11 ;
F_39 ( V_11 -> V_49 , V_11 -> V_12 , V_45 , 0 ) ;
F_33 ( log , V_11 ) ;
F_40 ( & log -> V_25 ) ;
F_41 ( & V_11 -> V_19 , & log -> V_35 ) ;
F_42 ( & log -> V_25 ) ;
return V_11 ;
}
static int F_43 ( struct V_1 * log , unsigned int V_72 )
{
if ( log -> V_38 &&
log -> V_38 -> V_43 + V_72 > V_45 )
F_26 ( log ) ;
if ( ! log -> V_38 )
log -> V_38 = F_34 ( log ) ;
return 0 ;
}
static void F_44 ( struct V_1 * log , T_3 type ,
T_1 V_73 ,
T_2 V_74 , T_2 V_75 ,
bool V_76 )
{
struct V_10 * V_11 = log -> V_38 ;
struct V_77 * V_78 ;
V_78 = F_27 ( V_11 -> V_12 ) + V_11 -> V_43 ;
V_78 -> V_79 . type = F_45 ( type ) ;
V_78 -> V_79 . V_30 = F_45 ( 0 ) ;
V_78 -> V_6 = F_28 ( ( 1 + ! ! V_76 ) <<
( V_80 - 9 ) ) ;
V_78 -> V_73 = F_38 ( V_73 ) ;
V_78 -> V_46 [ 0 ] = F_28 ( V_74 ) ;
if ( V_76 )
V_78 -> V_46 [ 1 ] = F_28 ( V_75 ) ;
V_11 -> V_43 += sizeof( struct V_77 ) +
sizeof( V_81 ) * ( 1 + ! ! V_76 ) ;
}
static void F_46 ( struct V_1 * log , struct V_82 * V_82 )
{
struct V_10 * V_11 = log -> V_38 ;
if ( V_11 -> V_60 ) {
struct V_28 * V_83 = V_11 -> V_49 ;
V_11 -> V_49 = F_31 ( log ) ;
F_47 ( V_11 -> V_49 , V_83 ) ;
F_30 ( V_48 , V_83 ) ;
}
if ( ! F_39 ( V_11 -> V_49 , V_82 , V_45 , 0 ) )
F_48 () ;
F_33 ( log , V_11 ) ;
}
static void F_49 ( struct V_1 * log , struct V_20 * V_21 ,
int V_84 , int V_85 )
{
int V_86 ;
int V_42 ;
struct V_10 * V_11 ;
V_42 =
( ( sizeof( struct V_77 ) + sizeof( V_81 ) )
* V_84 ) +
sizeof( struct V_77 ) +
sizeof( V_81 ) * V_85 ;
F_43 ( log , V_42 ) ;
V_11 = log -> V_38 ;
for ( V_86 = 0 ; V_86 < V_21 -> V_87 ; V_86 ++ ) {
if ( ! F_50 ( V_88 , & V_21 -> V_89 [ V_86 ] . V_30 ) )
continue;
if ( V_86 == V_21 -> V_90 || V_86 == V_21 -> V_91 )
continue;
F_44 ( log , V_92 ,
F_51 ( V_21 , V_86 , 0 ) ,
V_21 -> V_89 [ V_86 ] . V_93 , 0 , false ) ;
F_46 ( log , V_21 -> V_89 [ V_86 ] . V_82 ) ;
}
if ( V_21 -> V_91 >= 0 ) {
F_44 ( log , V_94 ,
V_21 -> V_95 , V_21 -> V_89 [ V_21 -> V_90 ] . V_93 ,
V_21 -> V_89 [ V_21 -> V_91 ] . V_93 , true ) ;
F_46 ( log , V_21 -> V_89 [ V_21 -> V_90 ] . V_82 ) ;
F_46 ( log , V_21 -> V_89 [ V_21 -> V_91 ] . V_82 ) ;
} else {
F_44 ( log , V_94 ,
V_21 -> V_95 , V_21 -> V_89 [ V_21 -> V_90 ] . V_93 ,
0 , false ) ;
F_46 ( log , V_21 -> V_89 [ V_21 -> V_90 ] . V_82 ) ;
}
F_41 ( & V_21 -> V_23 , & V_11 -> V_62 ) ;
F_52 ( & V_11 -> V_96 ) ;
V_21 -> V_97 = V_11 ;
}
int F_53 ( struct V_1 * log , struct V_20 * V_21 )
{
int V_98 = 0 ;
int V_84 , V_85 ;
int V_42 ;
int V_99 ;
int V_86 ;
if ( ! log )
return - V_100 ;
if ( V_21 -> V_97 || ! F_50 ( V_88 , & V_21 -> V_89 [ V_21 -> V_90 ] . V_30 ) ||
F_50 ( V_101 , & V_21 -> V_18 ) ) {
F_54 ( V_102 , & V_21 -> V_18 ) ;
return - V_100 ;
}
for ( V_86 = 0 ; V_86 < V_21 -> V_87 ; V_86 ++ ) {
void * V_103 ;
if ( ! F_50 ( V_88 , & V_21 -> V_89 [ V_86 ] . V_30 ) )
continue;
V_98 ++ ;
if ( F_50 ( V_102 , & V_21 -> V_18 ) )
continue;
V_103 = F_55 ( V_21 -> V_89 [ V_86 ] . V_82 ) ;
V_21 -> V_89 [ V_86 ] . V_93 = F_29 ( log -> V_44 ,
V_103 , V_45 ) ;
F_56 ( V_103 ) ;
}
V_85 = 1 + ! ! ( V_21 -> V_91 >= 0 ) ;
V_84 = V_98 - V_85 ;
V_42 =
( ( sizeof( struct V_77 ) + sizeof( V_81 ) )
* V_84 ) +
sizeof( struct V_77 ) +
sizeof( V_81 ) * V_85 ;
if ( V_42 + sizeof( struct V_39 ) > V_45 )
return - V_104 ;
F_16 ( V_102 , & V_21 -> V_18 ) ;
F_54 ( V_105 , & V_21 -> V_18 ) ;
F_52 ( & V_21 -> V_106 ) ;
F_57 ( & log -> V_107 ) ;
V_99 = ( 1 + V_98 ) << ( V_80 - 9 ) ;
if ( F_3 ( log , V_99 ) )
F_49 ( log , V_21 , V_84 , V_85 ) ;
else {
F_58 ( & log -> V_108 ) ;
F_41 ( & V_21 -> V_23 , & log -> V_109 ) ;
F_59 ( & log -> V_108 ) ;
F_60 ( log , V_99 ) ;
}
F_61 ( & log -> V_107 ) ;
return 0 ;
}
void F_62 ( struct V_1 * log )
{
if ( ! log )
return;
F_57 ( & log -> V_107 ) ;
F_26 ( log ) ;
F_61 ( & log -> V_107 ) ;
}
int F_63 ( struct V_1 * log , struct V_28 * V_28 )
{
if ( ! log )
return - V_110 ;
if ( V_28 -> V_56 . V_111 == 0 ) {
F_64 ( V_28 ) ;
return 0 ;
}
V_28 -> V_53 &= ~ V_112 ;
return - V_100 ;
}
static void F_65 ( struct V_1 * log )
{
struct V_20 * V_21 ;
F_58 ( & log -> V_108 ) ;
while ( ! F_8 ( & log -> V_109 ) ) {
V_21 = F_9 ( & log -> V_109 ,
struct V_20 , V_23 ) ;
F_15 ( & V_21 -> V_23 ) ;
F_16 ( V_24 , & V_21 -> V_18 ) ;
F_17 ( V_21 ) ;
}
F_59 ( & log -> V_108 ) ;
}
static T_1 F_66 ( struct V_1 * log )
{
return F_2 ( log , log -> V_8 ,
log -> V_113 ) ;
}
static bool F_67 ( struct V_1 * log )
{
struct V_10 * V_11 , * V_22 ;
bool V_114 = false ;
F_19 ( & log -> V_25 ) ;
F_14 (io, next, &log->finished_ios, log_sibling) {
if ( V_11 -> V_18 < V_115 )
break;
log -> V_113 = V_11 -> V_9 ;
log -> V_116 = V_11 -> V_69 ;
F_68 ( & V_11 -> V_19 ) ;
F_4 ( log , V_11 ) ;
V_114 = true ;
}
return V_114 ;
}
static void F_69 ( struct V_10 * V_11 )
{
struct V_1 * log = V_11 -> log ;
unsigned long V_30 ;
F_23 ( & log -> V_25 , V_30 ) ;
F_11 ( V_11 , V_115 ) ;
if ( ! F_67 ( log ) ) {
F_24 ( & log -> V_25 , V_30 ) ;
return;
}
if ( F_66 ( log ) > log -> V_117 )
F_60 ( log , 0 ) ;
F_24 ( & log -> V_25 , V_30 ) ;
F_70 ( & log -> V_118 ) ;
}
void F_71 ( struct V_20 * V_21 )
{
struct V_10 * V_11 ;
V_11 = V_21 -> V_97 ;
V_21 -> V_97 = NULL ;
if ( V_11 && F_72 ( & V_11 -> V_96 ) )
F_69 ( V_11 ) ;
}
static void F_73 ( struct V_28 * V_28 )
{
struct V_1 * log = F_74 ( V_28 , struct V_1 ,
V_119 ) ;
unsigned long V_30 ;
struct V_10 * V_11 ;
if ( V_28 -> V_31 )
F_21 ( log -> V_32 -> V_33 , log -> V_32 ) ;
F_23 ( & log -> V_25 , V_30 ) ;
F_75 (io, &log->flushing_ios, log_sibling)
F_13 ( V_11 ) ;
F_76 ( & log -> V_120 , & log -> V_27 ) ;
F_24 ( & log -> V_25 , V_30 ) ;
}
void F_77 ( struct V_1 * log )
{
bool V_121 ;
if ( ! log || ! log -> V_34 )
return;
F_40 ( & log -> V_25 ) ;
if ( ! F_8 ( & log -> V_120 ) ) {
F_42 ( & log -> V_25 ) ;
return;
}
F_76 ( & log -> V_36 , & log -> V_120 ) ;
V_121 = ! F_8 ( & log -> V_120 ) ;
F_42 ( & log -> V_25 ) ;
if ( ! V_121 )
return;
F_78 ( & log -> V_119 ) ;
log -> V_119 . V_54 = log -> V_32 -> V_55 ;
log -> V_119 . V_71 = F_73 ;
F_30 ( V_122 , & log -> V_119 ) ;
}
static void F_79 ( struct V_1 * log ,
T_1 V_5 )
{
struct V_123 * V_55 = log -> V_32 -> V_55 ;
struct V_33 * V_33 ;
F_80 ( log , V_5 ) ;
if ( ! F_81 ( F_82 ( V_55 ) ) )
return;
V_33 = log -> V_32 -> V_33 ;
if ( ! log -> V_124 ) {
F_16 ( V_125 , & V_33 -> V_30 ) ;
F_16 ( V_126 , & V_33 -> V_30 ) ;
F_25 ( V_33 -> V_37 ) ;
F_83 ( V_33 -> V_127 ,
! F_50 ( V_126 , & V_33 -> V_30 ) ||
log -> V_124 ) ;
if ( log -> V_124 )
F_84 ( V_33 , 1 ) ;
} else {
F_12 ( ! F_85 ( V_33 ) ) ;
F_84 ( V_33 , 1 ) ;
}
if ( log -> V_8 < V_5 ) {
F_86 ( V_55 ,
log -> V_8 + log -> V_32 -> V_58 ,
V_5 - log -> V_8 , V_50 , 0 ) ;
} else {
F_86 ( V_55 ,
log -> V_8 + log -> V_32 -> V_58 ,
log -> V_4 - log -> V_8 ,
V_50 , 0 ) ;
F_86 ( V_55 , log -> V_32 -> V_58 , V_5 ,
V_50 , 0 ) ;
}
}
static void F_87 ( struct V_1 * log )
{
T_1 V_128 = F_88 ( & log -> V_128 , 0 ) ;
T_1 V_129 ;
T_1 V_113 ;
T_4 V_116 ;
F_40 ( & log -> V_25 ) ;
while ( 1 ) {
V_129 = F_66 ( log ) ;
if ( V_129 >= V_128 ||
( F_8 ( & log -> V_35 ) &&
F_8 ( & log -> V_36 ) &&
F_8 ( & log -> V_120 ) &&
F_8 ( & log -> V_27 ) ) )
break;
F_25 ( log -> V_32 -> V_33 -> V_37 ) ;
F_89 ( log -> V_118 ,
F_66 ( log ) > V_129 ,
log -> V_25 ) ;
}
V_113 = log -> V_113 ;
V_116 = log -> V_116 ;
F_42 ( & log -> V_25 ) ;
F_90 ( V_129 < 0 ) ;
if ( V_129 == 0 )
return;
F_79 ( log , V_113 ) ;
F_57 ( & log -> V_107 ) ;
log -> V_8 = V_113 ;
log -> V_130 = V_116 ;
F_61 ( & log -> V_107 ) ;
F_65 ( log ) ;
}
static void F_91 ( struct V_131 * V_37 )
{
struct V_33 * V_33 = V_37 -> V_33 ;
struct V_132 * V_133 = V_33 -> V_134 ;
struct V_1 * log = V_133 -> log ;
if ( ! log )
return;
F_87 ( log ) ;
}
static void F_60 ( struct V_1 * log , T_1 V_135 )
{
unsigned long V_136 ;
unsigned long V_137 = ( unsigned long ) V_135 ;
do {
V_136 = log -> V_128 ;
if ( V_137 < V_136 )
return;
} while ( F_92 ( & log -> V_128 , V_136 , V_137 ) != V_136 );
F_25 ( log -> V_138 ) ;
}
void F_93 ( struct V_1 * log , int V_18 )
{
struct V_33 * V_33 ;
if ( ! log || V_18 == 2 )
return;
if ( V_18 == 0 ) {
log -> V_124 = 0 ;
log -> V_138 = F_94 ( F_91 ,
log -> V_32 -> V_33 , L_1 ) ;
} else if ( V_18 == 1 ) {
log -> V_124 = 1 ;
V_33 = log -> V_32 -> V_33 ;
F_70 ( & V_33 -> V_127 ) ;
F_60 ( log , - 1L ) ;
F_95 ( & log -> V_138 ) ;
F_87 ( log ) ;
}
}
bool F_96 ( struct V_132 * V_133 )
{
if ( ! V_133 -> log )
return F_50 ( V_139 , & V_133 -> V_33 -> V_30 ) ;
return F_50 ( V_140 , & V_133 -> log -> V_32 -> V_30 ) ;
}
static int F_97 ( struct V_1 * log ,
struct V_141 * V_142 )
{
struct V_82 * V_82 = V_142 -> V_12 ;
struct V_39 * V_143 ;
T_2 V_41 , V_144 ;
if ( ! F_98 ( log -> V_32 , V_142 -> V_145 , V_45 , V_82 , V_146 , false ) )
return - V_147 ;
V_143 = F_27 ( V_82 ) ;
V_144 = F_99 ( V_143 -> V_46 ) ;
V_143 -> V_46 = 0 ;
if ( F_99 ( V_143 -> V_65 ) != V_66 ||
F_100 ( V_143 -> V_69 ) != V_142 -> V_69 ||
V_143 -> V_67 != V_68 ||
F_100 ( V_143 -> V_70 ) != V_142 -> V_145 )
return - V_104 ;
V_41 = F_29 ( log -> V_44 , V_143 , V_45 ) ;
if ( V_144 != V_41 )
return - V_104 ;
if ( F_99 ( V_143 -> V_42 ) > V_45 )
return - V_104 ;
V_142 -> V_148 = V_59 ;
return 0 ;
}
static int F_101 ( struct V_1 * log ,
struct V_141 * V_142 ,
T_1 V_149 ,
int * V_150 , T_1 * V_151 )
{
struct V_132 * V_133 = log -> V_32 -> V_33 -> V_134 ;
struct V_20 * V_21 ;
struct V_77 * V_78 ;
int V_152 ;
V_21 = F_102 ( V_133 , V_149 , 0 , 0 , 0 ) ;
while ( 1 ) {
V_78 = F_27 ( V_142 -> V_12 ) + * V_150 ;
if ( F_103 ( V_78 -> V_79 . type ) == V_92 ) {
F_104 ( V_133 ,
F_100 ( V_78 -> V_73 ) , 0 ,
& V_152 , V_21 ) ;
F_98 ( log -> V_32 , * V_151 , V_45 ,
V_21 -> V_89 [ V_152 ] . V_82 , V_146 , false ) ;
V_21 -> V_89 [ V_152 ] . V_93 =
F_99 ( V_78 -> V_46 [ 0 ] ) ;
F_16 ( V_88 , & V_21 -> V_89 [ V_152 ] . V_30 ) ;
V_142 -> V_148 += V_59 ;
} else {
V_152 = V_21 -> V_90 ;
F_98 ( log -> V_32 , * V_151 , V_45 ,
V_21 -> V_89 [ V_152 ] . V_82 , V_146 , false ) ;
V_21 -> V_89 [ V_152 ] . V_93 =
F_99 ( V_78 -> V_46 [ 0 ] ) ;
F_16 ( V_88 , & V_21 -> V_89 [ V_152 ] . V_30 ) ;
if ( V_21 -> V_91 >= 0 ) {
V_152 = V_21 -> V_91 ;
F_98 ( log -> V_32 ,
F_1 ( log , * V_151 , V_59 ) ,
V_45 , V_21 -> V_89 [ V_152 ] . V_82 ,
V_146 , false ) ;
V_21 -> V_89 [ V_152 ] . V_93 =
F_99 ( V_78 -> V_46 [ 1 ] ) ;
F_16 ( V_88 ,
& V_21 -> V_89 [ V_152 ] . V_30 ) ;
}
V_142 -> V_148 += V_59 * V_133 -> V_153 ;
}
* V_151 = F_1 ( log , * V_151 ,
F_99 ( V_78 -> V_6 ) ) ;
* V_150 += sizeof( struct V_77 ) +
sizeof( V_81 ) *
( F_99 ( V_78 -> V_6 ) >> ( V_80 - 9 ) ) ;
if ( F_103 ( V_78 -> V_79 . type ) == V_94 )
break;
}
for ( V_152 = 0 ; V_152 < V_21 -> V_87 ; V_152 ++ ) {
void * V_103 ;
T_2 V_46 ;
if ( ! F_50 ( V_88 , & V_21 -> V_89 [ V_152 ] . V_30 ) )
continue;
V_103 = F_55 ( V_21 -> V_89 [ V_152 ] . V_82 ) ;
V_46 = F_29 ( log -> V_44 , V_103 , V_45 ) ;
F_56 ( V_103 ) ;
if ( V_46 != V_21 -> V_89 [ V_152 ] . V_93 )
goto error;
}
for ( V_152 = 0 ; V_152 < V_21 -> V_87 ; V_152 ++ ) {
struct V_154 * V_32 , * V_155 ;
if ( ! F_105 ( V_88 ,
& V_21 -> V_89 [ V_152 ] . V_30 ) )
continue;
V_32 = F_106 ( V_133 -> V_87 [ V_152 ] . V_32 ) ;
if ( V_32 )
F_98 ( V_32 , V_149 , V_45 ,
V_21 -> V_89 [ V_152 ] . V_82 , V_48 , false ) ;
V_155 = F_106 ( V_133 -> V_87 [ V_152 ] . V_156 ) ;
if ( V_155 )
F_98 ( V_155 , V_149 , V_45 ,
V_21 -> V_89 [ V_152 ] . V_82 , V_48 , false ) ;
}
F_17 ( V_21 ) ;
return 0 ;
error:
for ( V_152 = 0 ; V_152 < V_21 -> V_87 ; V_152 ++ )
V_21 -> V_89 [ V_152 ] . V_30 = 0 ;
F_17 ( V_21 ) ;
return - V_104 ;
}
static int F_107 ( struct V_1 * log ,
struct V_141 * V_142 )
{
struct V_132 * V_133 = log -> V_32 -> V_33 -> V_134 ;
struct V_77 * V_78 ;
struct V_39 * V_143 ;
int V_150 ;
T_1 V_151 ;
T_1 V_157 ;
V_143 = F_27 ( V_142 -> V_12 ) ;
V_150 = sizeof( struct V_39 ) ;
V_151 = F_1 ( log , V_142 -> V_145 , V_59 ) ;
while ( V_150 < F_99 ( V_143 -> V_42 ) ) {
int V_158 ;
V_78 = ( void * ) V_143 + V_150 ;
V_157 = F_104 ( V_133 ,
F_100 ( V_78 -> V_73 ) , 0 , & V_158 , NULL ) ;
if ( F_101 ( log , V_142 , V_157 ,
& V_150 , & V_151 ) )
return - V_104 ;
}
return 0 ;
}
static void F_108 ( struct V_1 * log ,
struct V_141 * V_142 )
{
while ( 1 ) {
if ( F_97 ( log , V_142 ) )
return;
if ( F_107 ( log , V_142 ) )
return;
V_142 -> V_69 ++ ;
V_142 -> V_145 = F_1 ( log , V_142 -> V_145 , V_142 -> V_148 ) ;
}
}
static int F_109 ( struct V_1 * log , T_1 V_145 ,
T_4 V_69 )
{
struct V_82 * V_82 ;
struct V_39 * V_143 ;
T_2 V_41 ;
V_82 = F_37 ( V_159 | V_64 ) ;
if ( ! V_82 )
return - V_160 ;
V_143 = F_27 ( V_82 ) ;
V_143 -> V_65 = F_28 ( V_66 ) ;
V_143 -> V_67 = V_68 ;
V_143 -> V_42 = F_28 ( sizeof( struct V_39 ) ) ;
V_143 -> V_69 = F_38 ( V_69 ) ;
V_143 -> V_70 = F_38 ( V_145 ) ;
V_41 = F_29 ( log -> V_44 , V_143 , V_45 ) ;
V_143 -> V_46 = F_28 ( V_41 ) ;
if ( ! F_98 ( log -> V_32 , V_145 , V_45 , V_82 , V_161 , false ) ) {
F_5 ( V_82 ) ;
return - V_147 ;
}
F_5 ( V_82 ) ;
return 0 ;
}
static int F_110 ( struct V_1 * log )
{
struct V_141 V_142 ;
V_142 . V_145 = log -> V_8 ;
V_142 . V_69 = log -> V_130 ;
V_142 . V_12 = F_37 ( V_159 ) ;
if ( ! V_142 . V_12 )
return - V_160 ;
F_108 ( log , & V_142 ) ;
F_5 ( V_142 . V_12 ) ;
if ( V_142 . V_69 > log -> V_130 + 1 ) {
int V_162 ;
V_162 = F_109 ( log , V_142 . V_145 , V_142 . V_69 + 10 ) ;
if ( V_162 )
return V_162 ;
log -> V_69 = V_142 . V_69 + 11 ;
log -> V_9 = F_1 ( log , V_142 . V_145 , V_59 ) ;
F_80 ( log , V_142 . V_145 ) ;
} else {
log -> V_9 = V_142 . V_145 ;
log -> V_69 = V_142 . V_69 ;
}
return 0 ;
}
static void F_80 ( struct V_1 * log , T_1 V_163 )
{
struct V_33 * V_33 = log -> V_32 -> V_33 ;
log -> V_32 -> V_164 = V_163 ;
F_16 ( V_125 , & V_33 -> V_30 ) ;
}
static int F_111 ( struct V_1 * log )
{
struct V_154 * V_32 = log -> V_32 ;
struct V_82 * V_82 ;
struct V_39 * V_143 ;
T_1 V_163 = log -> V_32 -> V_164 ;
T_2 V_144 , V_165 ;
bool V_166 = false ;
int V_162 ;
if ( V_163 >= V_32 -> V_167 || F_112 ( V_163 , V_59 ) != V_163 )
V_163 = 0 ;
V_82 = F_37 ( V_159 ) ;
if ( ! V_82 )
return - V_160 ;
if ( ! F_98 ( V_32 , V_163 , V_45 , V_82 , V_146 , false ) ) {
V_162 = - V_147 ;
goto V_168;
}
V_143 = F_27 ( V_82 ) ;
if ( F_99 ( V_143 -> V_65 ) != V_66 ||
V_143 -> V_67 != V_68 ) {
V_166 = true ;
goto V_169;
}
V_144 = F_99 ( V_143 -> V_46 ) ;
V_143 -> V_46 = 0 ;
V_165 = F_29 ( log -> V_44 , V_143 , V_45 ) ;
if ( V_144 != V_165 ) {
V_166 = true ;
goto V_169;
}
if ( F_100 ( V_143 -> V_70 ) != V_163 ) {
V_166 = true ;
goto V_169;
}
V_169:
if ( V_166 ) {
log -> V_130 = F_113 () ;
V_163 = 0 ;
F_80 ( log , V_163 ) ;
} else
log -> V_130 = F_100 ( V_143 -> V_69 ) ;
log -> V_4 = F_112 ( V_32 -> V_167 , V_59 ) ;
log -> V_117 = log -> V_4 >> V_170 ;
if ( log -> V_117 > V_171 )
log -> V_117 = V_171 ;
log -> V_8 = V_163 ;
F_5 ( V_82 ) ;
return F_110 ( log ) ;
V_168:
F_5 ( V_82 ) ;
return V_162 ;
}
int F_114 ( struct V_132 * V_133 , struct V_154 * V_32 )
{
struct V_1 * log ;
if ( V_45 != 4096 )
return - V_104 ;
log = F_115 ( sizeof( * log ) , V_159 ) ;
if ( ! log )
return - V_160 ;
log -> V_32 = V_32 ;
log -> V_34 = ( V_32 -> V_55 -> V_172 -> V_173 -> V_174 != 0 ) ;
log -> V_44 = F_29 ( ~ 0 , V_32 -> V_33 -> V_175 ,
sizeof( V_32 -> V_33 -> V_175 ) ) ;
F_116 ( & log -> V_107 ) ;
F_117 ( & log -> V_25 ) ;
F_36 ( & log -> V_35 ) ;
F_36 ( & log -> V_36 ) ;
F_36 ( & log -> V_120 ) ;
F_36 ( & log -> V_27 ) ;
F_118 ( & log -> V_119 ) ;
log -> V_13 = F_119 ( V_10 , 0 ) ;
if ( ! log -> V_13 )
goto V_13;
log -> V_138 = F_94 ( F_91 ,
log -> V_32 -> V_33 , L_1 ) ;
if ( ! log -> V_138 )
goto V_138;
F_120 ( & log -> V_118 ) ;
F_36 ( & log -> V_109 ) ;
F_117 ( & log -> V_108 ) ;
if ( F_111 ( log ) )
goto error;
V_133 -> log = log ;
return 0 ;
error:
F_95 ( & log -> V_138 ) ;
V_138:
F_121 ( log -> V_13 ) ;
V_13:
F_122 ( log ) ;
return - V_104 ;
}
void F_123 ( struct V_1 * log )
{
F_95 ( & log -> V_138 ) ;
F_121 ( log -> V_13 ) ;
F_122 ( log ) ;
}
