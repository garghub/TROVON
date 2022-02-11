static struct V_1 *
F_1 (
struct V_2 * log )
{
struct V_1 * V_3 ;
V_3 = F_2 ( log , 0 , 1 , V_4 , 0 ,
V_5 | V_6 ) ;
V_3 -> V_7 = 0 ;
return V_3 ;
}
void
F_3 (
struct V_2 * log )
{
log -> V_8 -> V_9 -> V_10 = F_1 ( log ) ;
log -> V_8 -> V_9 -> V_11 = 1 ;
}
static inline int
F_4 (
T_1 V_12 )
{
return F_5 ( ( sizeof( struct V_13 ) +
V_12 * sizeof( struct V_14 ) ) ,
sizeof( V_15 ) ) ;
}
static void
F_6 (
struct V_2 * log ,
struct V_16 * V_17 )
{
struct V_18 * V_19 ;
F_7 (lidp, &tp->t_items, lid_trans) {
struct V_20 * V_21 = V_19 -> V_22 ;
struct V_13 * V_23 ;
int V_12 = 0 ;
int V_24 = 0 ;
int V_25 ;
bool V_26 = false ;
if ( ! ( V_19 -> V_27 & V_28 ) )
continue;
V_21 -> V_29 -> V_30 ( V_21 , & V_12 , & V_24 ) ;
if ( V_12 == V_31 ) {
V_26 = true ;
V_12 = 0 ;
V_24 = 0 ;
}
V_24 += V_12 * sizeof( V_15 ) ;
V_24 = F_5 ( V_24 , sizeof( V_15 ) ) ;
V_25 = V_24 + F_4 ( V_12 ) ;
if ( ! V_21 -> V_32 ||
V_25 > V_21 -> V_32 -> V_33 ) {
F_8 ( V_21 -> V_32 ) ;
V_23 = F_9 ( V_25 , V_5 | V_6 ) ;
memset ( V_23 , 0 , F_4 ( V_12 ) ) ;
V_23 -> V_34 = V_21 ;
V_23 -> V_33 = V_25 ;
if ( V_26 )
V_23 -> V_35 = V_31 ;
else
V_23 -> V_36 = (struct V_14 * ) & V_23 [ 1 ] ;
V_21 -> V_32 = V_23 ;
} else {
V_23 = V_21 -> V_32 ;
if ( V_26 )
V_23 -> V_35 = V_31 ;
else
V_23 -> V_35 = 0 ;
V_23 -> V_37 = 0 ;
V_23 -> V_38 = NULL ;
}
V_23 -> V_39 = V_12 ;
V_23 -> V_40 = ( char * ) V_23 + F_4 ( V_12 ) ;
}
}
STATIC void
F_10 (
struct V_2 * log ,
struct V_13 * V_23 ,
struct V_13 * V_41 ,
int * V_42 ,
int * V_43 )
{
if ( V_23 -> V_35 != V_31 ) {
* V_42 += V_23 -> V_37 ;
* V_43 += V_23 -> V_39 ;
}
if ( ! V_41 ) {
V_23 -> V_34 -> V_29 -> V_44 ( V_23 -> V_34 ) ;
V_23 -> V_34 -> V_32 = NULL ;
} else if ( V_41 != V_23 ) {
ASSERT ( V_23 -> V_35 != V_31 ) ;
* V_42 -= V_41 -> V_37 ;
* V_43 -= V_41 -> V_39 ;
V_23 -> V_34 -> V_32 = V_41 ;
}
V_23 -> V_34 -> V_45 = V_23 ;
if ( ! V_23 -> V_34 -> V_46 )
V_23 -> V_34 -> V_46 = log -> V_8 -> V_9 -> V_11 ;
}
static void
F_11 (
struct V_2 * log ,
struct V_16 * V_17 ,
int * V_42 ,
int * V_43 )
{
struct V_18 * V_19 ;
if ( F_12 ( & V_17 -> V_47 ) ) {
ASSERT ( 0 ) ;
return;
}
F_7 (lidp, &tp->t_items, lid_trans) {
struct V_20 * V_21 = V_19 -> V_22 ;
struct V_13 * V_23 ;
struct V_13 * V_41 = NULL ;
struct V_13 * V_48 ;
bool V_26 = false ;
if ( ! ( V_19 -> V_27 & V_28 ) )
continue;
V_48 = V_21 -> V_32 ;
if ( V_48 -> V_35 == V_31 )
V_26 = true ;
if ( ! V_48 -> V_39 && ! V_26 )
continue;
V_41 = V_21 -> V_45 ;
if ( V_21 -> V_45 && V_48 -> V_33 <= V_21 -> V_45 -> V_33 ) {
V_23 = V_21 -> V_45 ;
V_23 -> V_38 = NULL ;
if ( V_26 )
goto V_49;
* V_43 -= V_23 -> V_39 ;
* V_42 -= V_23 -> V_37 ;
V_23 -> V_39 = V_48 -> V_39 ;
V_23 -> V_35 = 0 ;
V_23 -> V_37 = 0 ;
V_23 -> V_40 = ( char * ) V_23 +
F_4 ( V_23 -> V_39 ) ;
} else {
V_23 = V_48 ;
V_23 -> V_34 = V_21 ;
if ( V_26 ) {
ASSERT ( V_21 -> V_45 == NULL ) ;
goto V_49;
}
}
ASSERT ( F_13 ( ( unsigned long ) V_23 -> V_40 , sizeof( V_15 ) ) ) ;
V_21 -> V_29 -> V_50 ( V_21 , V_23 ) ;
V_49:
F_10 ( log , V_23 , V_41 , V_42 , V_43 ) ;
}
}
static void
F_14 (
struct V_2 * log ,
struct V_16 * V_17 )
{
struct V_51 * V_52 = log -> V_8 ;
struct V_53 * V_54 = V_52 -> V_9 ;
struct V_18 * V_19 ;
int V_55 = 0 ;
int V_43 = 0 ;
int V_56 ;
int V_57 = 0 , V_58 = 0 , V_59 = 0 ;
ASSERT ( V_17 ) ;
F_11 ( log , V_17 , & V_55 , & V_43 ) ;
F_15 ( & V_52 -> V_60 ) ;
V_57 = V_43 * sizeof( V_61 ) ;
V_55 += V_57 ;
V_54 -> V_62 += V_43 ;
if ( ! F_12 ( & V_17 -> V_63 ) )
F_16 ( & V_17 -> V_63 , & V_54 -> V_64 ) ;
if ( V_54 -> V_10 -> V_7 == 0 ) {
V_59 = V_54 -> V_10 -> V_65 ;
V_54 -> V_10 -> V_7 = V_59 ;
V_17 -> V_66 -> V_7 -= V_59 ;
}
V_56 = log -> V_67 - log -> V_68 ;
if ( V_55 > 0 && ( V_54 -> V_69 / V_56 !=
( V_54 -> V_69 + V_55 ) / V_56 ) ) {
V_58 = ( V_55 + V_56 - 1 ) / V_56 ;
V_58 *= log -> V_68 + sizeof( struct V_70 ) ;
V_54 -> V_10 -> V_65 += V_58 ;
V_54 -> V_10 -> V_7 += V_58 ;
V_17 -> V_66 -> V_7 -= V_58 ;
ASSERT ( V_17 -> V_66 -> V_7 >= V_55 ) ;
}
V_17 -> V_66 -> V_7 -= V_55 ;
V_54 -> V_69 += V_55 ;
if ( F_17 ( V_17 -> V_66 -> V_7 < 0 ) ) {
F_18 ( log -> V_71 , L_1 ) ;
F_18 ( log -> V_71 ,
L_2 ,
V_55 , V_57 ) ;
F_18 ( log -> V_71 , L_3 ,
V_58 ) ;
F_18 ( log -> V_71 , L_4 , V_59 ) ;
F_19 ( V_17 ) ;
}
F_7 (lidp, &tp->t_items, lid_trans) {
struct V_20 * V_21 = V_19 -> V_22 ;
if ( ! ( V_19 -> V_27 & V_28 ) )
continue;
if ( ! F_20 ( & V_21 -> V_72 , & V_52 -> V_73 ) )
F_21 ( & V_21 -> V_72 , & V_52 -> V_73 ) ;
}
F_22 ( & V_52 -> V_60 ) ;
if ( V_17 -> V_66 -> V_7 < 0 )
F_23 ( log -> V_71 , V_74 ) ;
}
static void
F_24 (
struct V_13 * V_75 )
{
struct V_13 * V_23 ;
for ( V_23 = V_75 ; V_23 ; ) {
struct V_13 * V_76 = V_23 -> V_38 ;
F_8 ( V_23 ) ;
V_23 = V_76 ;
}
}
static void
F_25 (
struct V_77 * V_78 )
{
struct V_53 * V_54 =
F_26 ( V_78 , struct V_53 , V_79 ) ;
struct V_80 * V_81 = V_54 -> V_52 -> V_82 -> V_71 ;
F_27 ( V_81 , & V_54 -> V_64 , false ) ;
F_8 ( V_54 ) ;
}
static void
F_28 (
struct V_83 * V_83 )
{
struct V_53 * V_54 = V_83 -> V_84 ;
F_29 ( & V_54 -> V_79 , F_25 ) ;
F_30 ( V_85 , & V_54 -> V_79 ) ;
F_31 ( V_83 ) ;
}
static void
F_32 (
struct V_80 * V_81 ,
struct V_53 * V_54 )
{
struct V_86 * V_87 = & V_54 -> V_64 ;
struct V_88 * V_89 ;
struct V_83 * V_83 = NULL ;
struct V_90 V_91 ;
int error = 0 ;
ASSERT ( V_81 -> V_92 & V_93 ) ;
F_33 ( & V_91 ) ;
F_7 (busyp, list, list) {
F_34 ( V_81 , V_89 -> V_94 , V_89 -> V_95 ,
V_89 -> V_96 ) ;
error = F_35 ( V_81 -> V_97 -> V_98 ,
F_36 ( V_81 , V_89 -> V_94 , V_89 -> V_95 ) ,
F_37 ( V_81 , V_89 -> V_96 ) ,
V_99 , 0 , & V_83 ) ;
if ( error && error != - V_100 ) {
F_38 ( V_81 ,
L_5 ,
( unsigned long long ) V_89 -> V_95 ,
V_89 -> V_96 ,
error ) ;
break;
}
}
if ( V_83 ) {
V_83 -> V_84 = V_54 ;
V_83 -> V_101 = F_28 ;
F_39 ( V_83 ) ;
} else {
F_25 ( & V_54 -> V_79 ) ;
}
F_40 ( & V_91 ) ;
}
static void
F_41 (
void * args ,
int abort )
{
struct V_53 * V_54 = args ;
struct V_80 * V_81 = V_54 -> V_52 -> V_82 -> V_71 ;
F_42 ( V_54 -> V_52 -> V_82 -> V_102 , V_54 -> V_103 ,
V_54 -> V_104 , abort ) ;
F_43 ( & V_54 -> V_64 ) ;
F_27 ( V_81 , & V_54 -> V_64 ,
( V_81 -> V_92 & V_93 ) && ! abort ) ;
F_15 ( & V_54 -> V_52 -> V_105 ) ;
if ( abort )
F_44 ( & V_54 -> V_52 -> V_106 ) ;
F_45 ( & V_54 -> V_107 ) ;
F_22 ( & V_54 -> V_52 -> V_105 ) ;
F_24 ( V_54 -> V_103 ) ;
if ( ! F_12 ( & V_54 -> V_64 ) )
F_32 ( V_81 , V_54 ) ;
else
F_8 ( V_54 ) ;
}
STATIC int
F_46 (
struct V_2 * log )
{
struct V_51 * V_52 = log -> V_8 ;
struct V_13 * V_23 ;
struct V_53 * V_54 ;
struct V_53 * V_108 ;
struct V_109 * V_110 ;
struct V_1 * V_3 ;
int V_111 ;
int error = 0 ;
struct V_112 V_113 ;
struct V_14 V_114 ;
struct V_13 V_115 = { NULL } ;
T_2 V_116 ;
T_2 V_117 ;
if ( ! V_52 )
return 0 ;
V_108 = F_47 ( sizeof( * V_108 ) , V_5 | V_6 ) ;
V_108 -> V_10 = F_1 ( log ) ;
F_48 ( & V_52 -> V_118 ) ;
V_54 = V_52 -> V_9 ;
F_15 ( & V_52 -> V_105 ) ;
V_117 = V_52 -> V_119 ;
ASSERT ( V_117 <= V_54 -> V_11 ) ;
if ( F_12 ( & V_52 -> V_73 ) ) {
V_52 -> V_119 = 0 ;
F_22 ( & V_52 -> V_105 ) ;
goto V_120;
}
if ( V_117 < V_52 -> V_9 -> V_11 ) {
F_22 ( & V_52 -> V_105 ) ;
goto V_120;
}
F_49 ( & V_54 -> V_107 , & V_52 -> V_121 ) ;
F_22 ( & V_52 -> V_105 ) ;
V_23 = NULL ;
V_111 = 0 ;
while ( ! F_12 ( & V_52 -> V_73 ) ) {
struct V_20 * V_122 ;
V_122 = F_50 ( & V_52 -> V_73 ,
struct V_20 , V_72 ) ;
F_51 ( & V_122 -> V_72 ) ;
if ( ! V_54 -> V_103 )
V_54 -> V_103 = V_122 -> V_45 ;
else
V_23 -> V_38 = V_122 -> V_45 ;
V_23 = V_122 -> V_45 ;
V_122 -> V_45 = NULL ;
V_111 += V_23 -> V_39 ;
}
F_52 ( & V_108 -> V_107 ) ;
F_52 ( & V_108 -> V_64 ) ;
V_108 -> V_11 = V_54 -> V_11 + 1 ;
V_108 -> V_52 = V_52 ;
V_52 -> V_9 = V_108 ;
F_15 ( & V_52 -> V_105 ) ;
V_52 -> V_123 = V_108 -> V_11 ;
F_22 ( & V_52 -> V_105 ) ;
F_53 ( & V_52 -> V_118 ) ;
V_3 = V_54 -> V_10 ;
V_113 . V_124 = V_125 ;
V_113 . V_126 = V_127 ;
V_113 . V_128 = V_3 -> V_129 ;
V_113 . V_130 = V_111 ;
V_114 . V_131 = & V_113 ;
V_114 . V_132 = sizeof( V_133 ) ;
V_114 . V_134 = V_135 ;
V_3 -> V_7 -= V_114 . V_132 + sizeof( V_61 ) ;
V_115 . V_39 = 1 ;
V_115 . V_36 = & V_114 ;
V_115 . V_38 = V_54 -> V_103 ;
error = F_54 ( log , & V_115 , V_3 , & V_54 -> V_104 , NULL , 0 ) ;
if ( error )
goto V_136;
V_137:
F_15 ( & V_52 -> V_105 ) ;
F_7 (new_ctx, &cil->xc_committing, committing) {
if ( F_55 ( log ) ) {
F_22 ( & V_52 -> V_105 ) ;
goto V_136;
}
if ( V_108 -> V_11 >= V_54 -> V_11 )
continue;
if ( ! V_108 -> V_116 ) {
F_56 ( & V_52 -> V_106 , & V_52 -> V_105 ) ;
goto V_137;
}
}
F_22 ( & V_52 -> V_105 ) ;
V_116 = F_57 ( log -> V_71 , V_3 , & V_110 , false ) ;
if ( V_116 == - 1 )
goto V_138;
V_54 -> V_139 . V_140 = F_41 ;
V_54 -> V_139 . V_141 = V_54 ;
error = F_58 ( log -> V_71 , V_110 , & V_54 -> V_139 ) ;
if ( error )
goto V_138;
F_15 ( & V_52 -> V_105 ) ;
V_54 -> V_116 = V_116 ;
F_44 ( & V_52 -> V_106 ) ;
F_22 ( & V_52 -> V_105 ) ;
return F_59 ( log -> V_71 , V_110 ) ;
V_120:
F_53 ( & V_52 -> V_118 ) ;
F_60 ( V_108 -> V_10 ) ;
F_8 ( V_108 ) ;
return 0 ;
V_136:
F_60 ( V_3 ) ;
V_138:
F_41 ( V_54 , V_142 ) ;
return - V_143 ;
}
static void
F_61 (
struct V_77 * V_78 )
{
struct V_51 * V_52 = F_26 ( V_78 , struct V_51 ,
V_144 ) ;
F_46 ( V_52 -> V_82 ) ;
}
static void
F_62 (
struct V_2 * log )
{
struct V_51 * V_52 = log -> V_8 ;
ASSERT ( ! F_12 ( & V_52 -> V_73 ) ) ;
if ( V_52 -> V_9 -> V_69 < F_63 ( log ) )
return;
F_15 ( & V_52 -> V_105 ) ;
if ( V_52 -> V_119 < V_52 -> V_123 ) {
V_52 -> V_119 = V_52 -> V_123 ;
F_30 ( log -> V_71 -> V_145 , & V_52 -> V_144 ) ;
}
F_22 ( & V_52 -> V_105 ) ;
}
static void
F_64 (
struct V_2 * log ,
T_2 V_117 )
{
struct V_51 * V_52 = log -> V_8 ;
if ( ! V_52 )
return;
ASSERT ( V_117 && V_117 <= V_52 -> V_123 ) ;
F_65 ( & V_52 -> V_144 ) ;
F_15 ( & V_52 -> V_105 ) ;
if ( F_12 ( & V_52 -> V_73 ) || V_117 <= V_52 -> V_119 ) {
F_22 ( & V_52 -> V_105 ) ;
return;
}
V_52 -> V_119 = V_117 ;
F_30 ( log -> V_71 -> V_145 , & V_52 -> V_144 ) ;
F_22 ( & V_52 -> V_105 ) ;
}
bool
F_66 (
struct V_2 * log )
{
struct V_51 * V_52 = log -> V_8 ;
bool V_146 = false ;
F_15 ( & V_52 -> V_105 ) ;
if ( F_12 ( & V_52 -> V_73 ) )
V_146 = true ;
F_22 ( & V_52 -> V_105 ) ;
return V_146 ;
}
void
F_67 (
struct V_80 * V_81 ,
struct V_16 * V_17 ,
T_2 * V_116 ,
bool V_147 )
{
struct V_2 * log = V_81 -> V_148 ;
struct V_51 * V_52 = log -> V_8 ;
T_2 V_149 ;
F_6 ( log , V_17 ) ;
F_68 ( & V_52 -> V_118 ) ;
F_14 ( log , V_17 ) ;
V_149 = V_52 -> V_9 -> V_11 ;
if ( V_116 )
* V_116 = V_149 ;
F_57 ( V_81 , V_17 -> V_66 , NULL , V_147 ) ;
F_69 ( V_17 ) ;
F_70 ( V_17 , V_149 , false ) ;
F_62 ( log ) ;
F_71 ( & V_52 -> V_118 ) ;
}
T_2
F_72 (
struct V_2 * log ,
T_2 V_11 )
{
struct V_51 * V_52 = log -> V_8 ;
struct V_53 * V_54 ;
T_2 V_116 = V_150 ;
ASSERT ( V_11 <= V_52 -> V_123 ) ;
V_137:
F_64 ( log , V_11 ) ;
F_15 ( & V_52 -> V_105 ) ;
F_7 (ctx, &cil->xc_committing, committing) {
if ( F_55 ( log ) )
goto V_151;
if ( V_54 -> V_11 > V_11 )
continue;
if ( ! V_54 -> V_116 ) {
F_56 ( & V_52 -> V_106 , & V_52 -> V_105 ) ;
goto V_137;
}
if ( V_54 -> V_11 != V_11 )
continue;
V_116 = V_54 -> V_116 ;
}
if ( V_11 == V_52 -> V_123 &&
! F_12 ( & V_52 -> V_73 ) ) {
F_22 ( & V_52 -> V_105 ) ;
goto V_137;
}
F_22 ( & V_52 -> V_105 ) ;
return V_116 ;
V_151:
F_22 ( & V_52 -> V_105 ) ;
return 0 ;
}
bool
F_73 (
struct V_20 * V_21 )
{
struct V_53 * V_54 ;
if ( F_12 ( & V_21 -> V_72 ) )
return false ;
V_54 = V_21 -> V_152 -> V_148 -> V_8 -> V_9 ;
if ( F_74 ( V_21 -> V_46 , V_54 -> V_11 ) != 0 )
return false ;
return true ;
}
int
F_75 (
struct V_2 * log )
{
struct V_51 * V_52 ;
struct V_53 * V_54 ;
V_52 = F_47 ( sizeof( * V_52 ) , V_5 | V_153 ) ;
if ( ! V_52 )
return - V_154 ;
V_54 = F_47 ( sizeof( * V_54 ) , V_5 | V_153 ) ;
if ( ! V_54 ) {
F_8 ( V_52 ) ;
return - V_154 ;
}
F_29 ( & V_52 -> V_144 , F_61 ) ;
F_52 ( & V_52 -> V_73 ) ;
F_52 ( & V_52 -> V_121 ) ;
F_76 ( & V_52 -> V_60 ) ;
F_76 ( & V_52 -> V_105 ) ;
F_77 ( & V_52 -> V_118 ) ;
F_78 ( & V_52 -> V_106 ) ;
F_52 ( & V_54 -> V_107 ) ;
F_52 ( & V_54 -> V_64 ) ;
V_54 -> V_11 = 1 ;
V_54 -> V_52 = V_52 ;
V_52 -> V_9 = V_54 ;
V_52 -> V_123 = V_54 -> V_11 ;
V_52 -> V_82 = log ;
log -> V_8 = V_52 ;
return 0 ;
}
void
F_79 (
struct V_2 * log )
{
if ( log -> V_8 -> V_9 ) {
if ( log -> V_8 -> V_9 -> V_10 )
F_60 ( log -> V_8 -> V_9 -> V_10 ) ;
F_8 ( log -> V_8 -> V_9 ) ;
}
ASSERT ( F_12 ( & log -> V_8 -> V_73 ) ) ;
F_8 ( log -> V_8 ) ;
}
