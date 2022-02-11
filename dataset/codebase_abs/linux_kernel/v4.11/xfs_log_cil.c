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
ASSERT ( V_17 ) ;
F_11 ( log , V_17 , & V_55 , & V_43 ) ;
F_15 ( & V_52 -> V_57 ) ;
F_7 (lidp, &tp->t_items, lid_trans) {
struct V_20 * V_21 = V_19 -> V_22 ;
if ( ! ( V_19 -> V_27 & V_28 ) )
continue;
if ( ! F_16 ( & V_21 -> V_58 , & V_52 -> V_59 ) )
F_17 ( & V_21 -> V_58 , & V_52 -> V_59 ) ;
}
V_55 += V_43 * sizeof( V_60 ) ;
V_54 -> V_61 += V_43 ;
if ( ! F_12 ( & V_17 -> V_62 ) )
F_18 ( & V_17 -> V_62 , & V_54 -> V_63 ) ;
if ( V_54 -> V_10 -> V_7 == 0 ) {
V_54 -> V_10 -> V_7 = V_54 -> V_10 -> V_64 ;
V_17 -> V_65 -> V_7 -= V_54 -> V_10 -> V_64 ;
}
V_56 = log -> V_66 - log -> V_67 ;
if ( V_55 > 0 && ( V_54 -> V_68 / V_56 !=
( V_54 -> V_68 + V_55 ) / V_56 ) ) {
int V_69 ;
V_69 = ( V_55 + V_56 - 1 ) / V_56 ;
V_69 *= log -> V_67 + sizeof( struct V_70 ) ;
V_54 -> V_10 -> V_64 += V_69 ;
V_54 -> V_10 -> V_7 += V_69 ;
V_17 -> V_65 -> V_7 -= V_69 ;
ASSERT ( V_17 -> V_65 -> V_7 >= V_55 ) ;
}
V_17 -> V_65 -> V_7 -= V_55 ;
V_54 -> V_68 += V_55 ;
F_19 ( & V_52 -> V_57 ) ;
}
static void
F_20 (
struct V_13 * V_71 )
{
struct V_13 * V_23 ;
for ( V_23 = V_71 ; V_23 ; ) {
struct V_13 * V_72 = V_23 -> V_38 ;
F_8 ( V_23 ) ;
V_23 = V_72 ;
}
}
static void
F_21 (
struct V_73 * V_74 )
{
struct V_53 * V_54 =
F_22 ( V_74 , struct V_53 , V_75 ) ;
struct V_76 * V_77 = V_54 -> V_52 -> V_78 -> V_79 ;
F_23 ( V_77 , & V_54 -> V_63 , false ) ;
F_8 ( V_54 ) ;
}
static void
F_24 (
struct V_80 * V_80 )
{
struct V_53 * V_54 = V_80 -> V_81 ;
F_25 ( & V_54 -> V_75 , F_21 ) ;
F_26 ( V_82 , & V_54 -> V_75 ) ;
}
static void
F_27 (
struct V_76 * V_77 ,
struct V_53 * V_54 )
{
struct V_83 * V_84 = & V_54 -> V_63 ;
struct V_85 * V_86 ;
struct V_80 * V_80 = NULL ;
struct V_87 V_88 ;
int error = 0 ;
ASSERT ( V_77 -> V_89 & V_90 ) ;
F_28 ( & V_88 ) ;
F_7 (busyp, list, list) {
F_29 ( V_77 , V_86 -> V_91 , V_86 -> V_92 ,
V_86 -> V_93 ) ;
error = F_30 ( V_77 -> V_94 -> V_95 ,
F_31 ( V_77 , V_86 -> V_91 , V_86 -> V_92 ) ,
F_32 ( V_77 , V_86 -> V_93 ) ,
V_96 , 0 , & V_80 ) ;
if ( error && error != - V_97 ) {
F_33 ( V_77 ,
L_1 ,
( unsigned long long ) V_86 -> V_92 ,
V_86 -> V_93 ,
error ) ;
break;
}
}
if ( V_80 ) {
V_80 -> V_81 = V_54 ;
V_80 -> V_98 = F_24 ;
F_34 ( V_80 ) ;
} else {
F_21 ( & V_54 -> V_75 ) ;
}
F_35 ( & V_88 ) ;
}
static void
F_36 (
void * args ,
int abort )
{
struct V_53 * V_54 = args ;
struct V_76 * V_77 = V_54 -> V_52 -> V_78 -> V_79 ;
F_37 ( V_54 -> V_52 -> V_78 -> V_99 , V_54 -> V_100 ,
V_54 -> V_101 , abort ) ;
F_38 ( & V_54 -> V_63 ) ;
F_23 ( V_77 , & V_54 -> V_63 ,
( V_77 -> V_89 & V_90 ) && ! abort ) ;
F_15 ( & V_54 -> V_52 -> V_102 ) ;
if ( abort )
F_39 ( & V_54 -> V_52 -> V_103 ) ;
F_40 ( & V_54 -> V_104 ) ;
F_19 ( & V_54 -> V_52 -> V_102 ) ;
F_20 ( V_54 -> V_100 ) ;
if ( ! F_12 ( & V_54 -> V_63 ) )
F_27 ( V_77 , V_54 ) ;
else
F_8 ( V_54 ) ;
}
STATIC int
F_41 (
struct V_2 * log )
{
struct V_51 * V_52 = log -> V_8 ;
struct V_13 * V_23 ;
struct V_53 * V_54 ;
struct V_53 * V_105 ;
struct V_106 * V_107 ;
struct V_1 * V_3 ;
int V_108 ;
int error = 0 ;
struct V_109 V_110 ;
struct V_14 V_111 ;
struct V_13 V_112 = { NULL } ;
T_2 V_113 ;
T_2 V_114 ;
if ( ! V_52 )
return 0 ;
V_105 = F_42 ( sizeof( * V_105 ) , V_5 | V_6 ) ;
V_105 -> V_10 = F_1 ( log ) ;
F_43 ( & V_52 -> V_115 ) ;
V_54 = V_52 -> V_9 ;
F_15 ( & V_52 -> V_102 ) ;
V_114 = V_52 -> V_116 ;
ASSERT ( V_114 <= V_54 -> V_11 ) ;
if ( F_12 ( & V_52 -> V_59 ) ) {
V_52 -> V_116 = 0 ;
F_19 ( & V_52 -> V_102 ) ;
goto V_117;
}
if ( V_114 < V_52 -> V_9 -> V_11 ) {
F_19 ( & V_52 -> V_102 ) ;
goto V_117;
}
F_44 ( & V_54 -> V_104 , & V_52 -> V_118 ) ;
F_19 ( & V_52 -> V_102 ) ;
V_23 = NULL ;
V_108 = 0 ;
while ( ! F_12 ( & V_52 -> V_59 ) ) {
struct V_20 * V_119 ;
V_119 = F_45 ( & V_52 -> V_59 ,
struct V_20 , V_58 ) ;
F_46 ( & V_119 -> V_58 ) ;
if ( ! V_54 -> V_100 )
V_54 -> V_100 = V_119 -> V_45 ;
else
V_23 -> V_38 = V_119 -> V_45 ;
V_23 = V_119 -> V_45 ;
V_119 -> V_45 = NULL ;
V_108 += V_23 -> V_39 ;
}
F_47 ( & V_105 -> V_104 ) ;
F_47 ( & V_105 -> V_63 ) ;
V_105 -> V_11 = V_54 -> V_11 + 1 ;
V_105 -> V_52 = V_52 ;
V_52 -> V_9 = V_105 ;
F_15 ( & V_52 -> V_102 ) ;
V_52 -> V_120 = V_105 -> V_11 ;
F_19 ( & V_52 -> V_102 ) ;
F_48 ( & V_52 -> V_115 ) ;
V_3 = V_54 -> V_10 ;
V_110 . V_121 = V_122 ;
V_110 . V_123 = V_124 ;
V_110 . V_125 = V_3 -> V_126 ;
V_110 . V_127 = V_108 ;
V_111 . V_128 = & V_110 ;
V_111 . V_129 = sizeof( V_130 ) ;
V_111 . V_131 = V_132 ;
V_3 -> V_7 -= V_111 . V_129 + sizeof( V_60 ) ;
V_112 . V_39 = 1 ;
V_112 . V_36 = & V_111 ;
V_112 . V_38 = V_54 -> V_100 ;
error = F_49 ( log , & V_112 , V_3 , & V_54 -> V_101 , NULL , 0 ) ;
if ( error )
goto V_133;
V_134:
F_15 ( & V_52 -> V_102 ) ;
F_7 (new_ctx, &cil->xc_committing, committing) {
if ( F_50 ( log ) ) {
F_19 ( & V_52 -> V_102 ) ;
goto V_133;
}
if ( V_105 -> V_11 >= V_54 -> V_11 )
continue;
if ( ! V_105 -> V_113 ) {
F_51 ( & V_52 -> V_103 , & V_52 -> V_102 ) ;
goto V_134;
}
}
F_19 ( & V_52 -> V_102 ) ;
V_113 = F_52 ( log -> V_79 , V_3 , & V_107 , false ) ;
if ( V_113 == - 1 )
goto V_135;
V_54 -> V_136 . V_137 = F_36 ;
V_54 -> V_136 . V_138 = V_54 ;
error = F_53 ( log -> V_79 , V_107 , & V_54 -> V_136 ) ;
if ( error )
goto V_135;
F_15 ( & V_52 -> V_102 ) ;
V_54 -> V_113 = V_113 ;
F_39 ( & V_52 -> V_103 ) ;
F_19 ( & V_52 -> V_102 ) ;
return F_54 ( log -> V_79 , V_107 ) ;
V_117:
F_48 ( & V_52 -> V_115 ) ;
F_55 ( V_105 -> V_10 ) ;
F_8 ( V_105 ) ;
return 0 ;
V_133:
F_55 ( V_3 ) ;
V_135:
F_36 ( V_54 , V_139 ) ;
return - V_140 ;
}
static void
F_56 (
struct V_73 * V_74 )
{
struct V_51 * V_52 = F_22 ( V_74 , struct V_51 ,
V_141 ) ;
F_41 ( V_52 -> V_78 ) ;
}
static void
F_57 (
struct V_2 * log )
{
struct V_51 * V_52 = log -> V_8 ;
ASSERT ( ! F_12 ( & V_52 -> V_59 ) ) ;
if ( V_52 -> V_9 -> V_68 < F_58 ( log ) )
return;
F_15 ( & V_52 -> V_102 ) ;
if ( V_52 -> V_116 < V_52 -> V_120 ) {
V_52 -> V_116 = V_52 -> V_120 ;
F_26 ( log -> V_79 -> V_142 , & V_52 -> V_141 ) ;
}
F_19 ( & V_52 -> V_102 ) ;
}
static void
F_59 (
struct V_2 * log ,
T_2 V_114 )
{
struct V_51 * V_52 = log -> V_8 ;
if ( ! V_52 )
return;
ASSERT ( V_114 && V_114 <= V_52 -> V_120 ) ;
F_60 ( & V_52 -> V_141 ) ;
F_15 ( & V_52 -> V_102 ) ;
if ( F_12 ( & V_52 -> V_59 ) || V_114 <= V_52 -> V_116 ) {
F_19 ( & V_52 -> V_102 ) ;
return;
}
V_52 -> V_116 = V_114 ;
F_26 ( log -> V_79 -> V_142 , & V_52 -> V_141 ) ;
F_19 ( & V_52 -> V_102 ) ;
}
bool
F_61 (
struct V_2 * log )
{
struct V_51 * V_52 = log -> V_8 ;
bool V_143 = false ;
F_15 ( & V_52 -> V_102 ) ;
if ( F_12 ( & V_52 -> V_59 ) )
V_143 = true ;
F_19 ( & V_52 -> V_102 ) ;
return V_143 ;
}
void
F_62 (
struct V_76 * V_77 ,
struct V_16 * V_17 ,
T_2 * V_113 ,
bool V_144 )
{
struct V_2 * log = V_77 -> V_145 ;
struct V_51 * V_52 = log -> V_8 ;
F_6 ( log , V_17 ) ;
F_63 ( & V_52 -> V_115 ) ;
F_14 ( log , V_17 ) ;
if ( V_17 -> V_65 -> V_7 < 0 )
F_64 ( V_77 , V_17 -> V_65 ) ;
V_17 -> V_146 = V_52 -> V_9 -> V_11 ;
if ( V_113 )
* V_113 = V_17 -> V_146 ;
F_52 ( V_77 , V_17 -> V_65 , NULL , V_144 ) ;
F_65 ( V_17 ) ;
F_66 ( V_17 , V_17 -> V_146 , false ) ;
F_57 ( log ) ;
F_67 ( & V_52 -> V_115 ) ;
}
T_2
F_68 (
struct V_2 * log ,
T_2 V_11 )
{
struct V_51 * V_52 = log -> V_8 ;
struct V_53 * V_54 ;
T_2 V_113 = V_147 ;
ASSERT ( V_11 <= V_52 -> V_120 ) ;
V_134:
F_59 ( log , V_11 ) ;
F_15 ( & V_52 -> V_102 ) ;
F_7 (ctx, &cil->xc_committing, committing) {
if ( F_50 ( log ) )
goto V_148;
if ( V_54 -> V_11 > V_11 )
continue;
if ( ! V_54 -> V_113 ) {
F_51 ( & V_52 -> V_103 , & V_52 -> V_102 ) ;
goto V_134;
}
if ( V_54 -> V_11 != V_11 )
continue;
V_113 = V_54 -> V_113 ;
}
if ( V_11 == V_52 -> V_120 &&
! F_12 ( & V_52 -> V_59 ) ) {
F_19 ( & V_52 -> V_102 ) ;
goto V_134;
}
F_19 ( & V_52 -> V_102 ) ;
return V_113 ;
V_148:
F_19 ( & V_52 -> V_102 ) ;
return 0 ;
}
bool
F_69 (
struct V_20 * V_21 )
{
struct V_53 * V_54 ;
if ( F_12 ( & V_21 -> V_58 ) )
return false ;
V_54 = V_21 -> V_149 -> V_145 -> V_8 -> V_9 ;
if ( F_70 ( V_21 -> V_46 , V_54 -> V_11 ) != 0 )
return false ;
return true ;
}
int
F_71 (
struct V_2 * log )
{
struct V_51 * V_52 ;
struct V_53 * V_54 ;
V_52 = F_42 ( sizeof( * V_52 ) , V_5 | V_150 ) ;
if ( ! V_52 )
return - V_151 ;
V_54 = F_42 ( sizeof( * V_54 ) , V_5 | V_150 ) ;
if ( ! V_54 ) {
F_8 ( V_52 ) ;
return - V_151 ;
}
F_25 ( & V_52 -> V_141 , F_56 ) ;
F_47 ( & V_52 -> V_59 ) ;
F_47 ( & V_52 -> V_118 ) ;
F_72 ( & V_52 -> V_57 ) ;
F_72 ( & V_52 -> V_102 ) ;
F_73 ( & V_52 -> V_115 ) ;
F_74 ( & V_52 -> V_103 ) ;
F_47 ( & V_54 -> V_104 ) ;
F_47 ( & V_54 -> V_63 ) ;
V_54 -> V_11 = 1 ;
V_54 -> V_52 = V_52 ;
V_52 -> V_9 = V_54 ;
V_52 -> V_120 = V_54 -> V_11 ;
V_52 -> V_78 = log ;
log -> V_8 = V_52 ;
return 0 ;
}
void
F_75 (
struct V_2 * log )
{
if ( log -> V_8 -> V_9 ) {
if ( log -> V_8 -> V_9 -> V_10 )
F_55 ( log -> V_8 -> V_9 -> V_10 ) ;
F_8 ( log -> V_8 -> V_9 ) ;
}
ASSERT ( F_12 ( & log -> V_8 -> V_59 ) ) ;
F_8 ( log -> V_8 ) ;
}
