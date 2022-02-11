static struct V_1 *
F_1 (
struct V_2 * log )
{
struct V_1 * V_3 ;
V_3 = F_2 ( log , 0 , 1 , V_4 , 0 ,
V_5 | V_6 ) ;
V_3 -> V_7 = V_8 ;
V_3 -> V_9 = 0 ;
return V_3 ;
}
void
F_3 (
struct V_2 * log )
{
log -> V_10 -> V_11 -> V_12 = F_1 ( log ) ;
log -> V_10 -> V_11 -> V_13 = 1 ;
log -> V_10 -> V_11 -> V_14 = F_4 ( log -> V_15 ,
log -> V_16 ) ;
}
STATIC void
F_5 (
struct V_2 * log ,
struct V_17 * V_18 ,
struct V_17 * V_19 ,
int * V_20 ,
int * V_21 )
{
if ( V_18 -> V_22 != V_23 ) {
* V_20 += V_18 -> V_24 ;
* V_21 += V_18 -> V_25 ;
}
if ( ! V_19 )
V_18 -> V_26 -> V_27 -> V_28 ( V_18 -> V_26 ) ;
else if ( V_19 != V_18 ) {
ASSERT ( V_18 -> V_22 != V_23 ) ;
* V_20 -= V_19 -> V_24 ;
* V_21 -= V_19 -> V_25 ;
F_6 ( V_19 ) ;
}
V_18 -> V_26 -> V_29 = V_18 ;
if ( ! V_18 -> V_26 -> V_30 )
V_18 -> V_26 -> V_30 = log -> V_10 -> V_11 -> V_13 ;
}
static void
F_7 (
struct V_2 * log ,
struct V_31 * V_32 ,
int * V_20 ,
int * V_21 )
{
struct V_33 * V_34 ;
if ( F_8 ( & V_32 -> V_35 ) ) {
ASSERT ( 0 ) ;
return;
}
F_9 (lidp, &tp->t_items, lid_trans) {
struct V_36 * V_37 = V_34 -> V_38 ;
struct V_17 * V_18 ;
struct V_17 * V_19 ;
int V_39 = 0 ;
int V_40 = 0 ;
int V_41 ;
bool V_42 = false ;
if ( ! ( V_34 -> V_43 & V_44 ) )
continue;
V_37 -> V_27 -> V_45 ( V_37 , & V_39 , & V_40 ) ;
if ( ! V_39 )
continue;
if ( V_39 == V_23 ) {
V_42 = true ;
V_39 = 0 ;
V_40 = 0 ;
}
V_40 += V_39 * sizeof( V_46 ) ;
V_40 = F_10 ( V_40 , sizeof( V_46 ) ) ;
V_19 = V_37 -> V_29 ;
V_41 = V_40 +
F_10 ( ( sizeof( struct V_17 ) +
V_39 * sizeof( struct V_47 ) ) ,
sizeof( V_46 ) ) ;
if ( V_37 -> V_29 && V_41 <= V_37 -> V_29 -> V_48 ) {
V_18 = V_37 -> V_29 ;
V_18 -> V_49 = NULL ;
if ( V_42 )
goto V_50;
* V_21 -= V_18 -> V_25 ;
* V_20 -= V_18 -> V_24 ;
} else {
V_18 = F_11 ( V_41 , V_5 | V_6 ) ;
V_18 -> V_26 = V_37 ;
V_18 -> V_48 = V_41 ;
if ( V_42 ) {
ASSERT ( V_37 -> V_29 == NULL ) ;
V_18 -> V_22 = V_23 ;
goto V_50;
}
V_18 -> V_51 = (struct V_47 * ) & V_18 [ 1 ] ;
}
V_18 -> V_25 = V_39 ;
V_18 -> V_22 = 0 ;
V_18 -> V_24 = 0 ;
V_18 -> V_52 = ( char * ) V_18 + V_41 - V_40 ;
ASSERT ( F_12 ( ( unsigned long ) V_18 -> V_52 , sizeof( V_46 ) ) ) ;
V_37 -> V_27 -> V_53 ( V_37 , V_18 ) ;
V_50:
ASSERT ( V_18 -> V_22 <= V_40 ) ;
F_5 ( log , V_18 , V_19 , V_20 , V_21 ) ;
}
}
static void
F_13 (
struct V_2 * log ,
struct V_31 * V_32 )
{
struct V_54 * V_55 = log -> V_10 ;
struct V_56 * V_57 = V_55 -> V_11 ;
struct V_33 * V_34 ;
int V_58 = 0 ;
int V_21 = 0 ;
int V_59 ;
ASSERT ( V_32 ) ;
F_7 ( log , V_32 , & V_58 , & V_21 ) ;
F_14 ( & V_55 -> V_60 ) ;
F_9 (lidp, &tp->t_items, lid_trans) {
struct V_36 * V_37 = V_34 -> V_38 ;
if ( ! ( V_34 -> V_43 & V_44 ) )
continue;
F_15 ( & V_37 -> V_61 , & V_55 -> V_62 ) ;
}
V_58 += V_21 * sizeof( V_63 ) ;
V_57 -> V_64 += V_21 ;
if ( ! F_8 ( & V_32 -> V_65 ) )
F_16 ( & V_32 -> V_65 , & V_57 -> V_66 ) ;
if ( V_57 -> V_12 -> V_9 == 0 ) {
V_57 -> V_12 -> V_9 = V_57 -> V_12 -> V_67 ;
V_32 -> V_68 -> V_9 -= V_57 -> V_12 -> V_67 ;
}
V_59 = log -> V_69 - log -> V_70 ;
if ( V_58 > 0 && ( V_57 -> V_71 / V_59 !=
( V_57 -> V_71 + V_58 ) / V_59 ) ) {
int V_72 ;
V_72 = ( V_58 + V_59 - 1 ) / V_59 ;
V_72 *= log -> V_70 + sizeof( struct V_73 ) ;
V_57 -> V_12 -> V_67 += V_72 ;
V_57 -> V_12 -> V_9 += V_72 ;
V_32 -> V_68 -> V_9 -= V_72 ;
ASSERT ( V_32 -> V_68 -> V_9 >= V_58 ) ;
}
V_32 -> V_68 -> V_9 -= V_58 ;
V_57 -> V_71 += V_58 ;
F_17 ( & V_55 -> V_60 ) ;
}
static void
F_18 (
struct V_17 * V_74 )
{
struct V_17 * V_18 ;
for ( V_18 = V_74 ; V_18 ; ) {
struct V_17 * V_75 = V_18 -> V_49 ;
F_6 ( V_18 ) ;
V_18 = V_75 ;
}
}
static void
F_19 (
void * args ,
int abort )
{
struct V_56 * V_57 = args ;
struct V_76 * V_77 = V_57 -> V_55 -> V_78 -> V_79 ;
F_20 ( V_57 -> V_55 -> V_78 -> V_80 , V_57 -> V_81 ,
V_57 -> V_82 , abort ) ;
F_21 ( & V_57 -> V_66 ) ;
F_22 ( V_77 , & V_57 -> V_66 ,
( V_77 -> V_83 & V_84 ) && ! abort ) ;
F_14 ( & V_57 -> V_55 -> V_85 ) ;
if ( abort )
F_23 ( & V_57 -> V_55 -> V_86 ) ;
F_24 ( & V_57 -> V_87 ) ;
F_17 ( & V_57 -> V_55 -> V_85 ) ;
F_18 ( V_57 -> V_81 ) ;
if ( ! F_8 ( & V_57 -> V_66 ) ) {
ASSERT ( V_77 -> V_83 & V_84 ) ;
F_25 ( V_77 , & V_57 -> V_66 ) ;
F_22 ( V_77 , & V_57 -> V_66 , false ) ;
}
F_6 ( V_57 ) ;
}
STATIC int
F_26 (
struct V_2 * log )
{
struct V_54 * V_55 = log -> V_10 ;
struct V_17 * V_18 ;
struct V_56 * V_57 ;
struct V_56 * V_88 ;
struct V_89 * V_90 ;
struct V_1 * V_3 ;
int V_91 ;
int error = 0 ;
struct V_92 V_93 ;
struct V_47 V_94 ;
struct V_17 V_95 = { NULL } ;
T_1 V_14 ;
T_1 V_96 ;
if ( ! V_55 )
return 0 ;
V_88 = F_11 ( sizeof( * V_88 ) , V_5 | V_6 ) ;
V_88 -> V_12 = F_1 ( log ) ;
F_27 ( & V_55 -> V_97 ) ;
V_57 = V_55 -> V_11 ;
F_14 ( & V_55 -> V_85 ) ;
V_96 = V_55 -> V_98 ;
ASSERT ( V_96 <= V_57 -> V_13 ) ;
if ( F_8 ( & V_55 -> V_62 ) ) {
V_55 -> V_98 = 0 ;
F_17 ( & V_55 -> V_85 ) ;
goto V_99;
}
F_17 ( & V_55 -> V_85 ) ;
if ( V_96 < V_55 -> V_11 -> V_13 )
goto V_99;
V_18 = NULL ;
V_91 = 0 ;
while ( ! F_8 ( & V_55 -> V_62 ) ) {
struct V_36 * V_100 ;
V_100 = F_28 ( & V_55 -> V_62 ,
struct V_36 , V_61 ) ;
F_29 ( & V_100 -> V_61 ) ;
if ( ! V_57 -> V_81 )
V_57 -> V_81 = V_100 -> V_29 ;
else
V_18 -> V_49 = V_100 -> V_29 ;
V_18 = V_100 -> V_29 ;
V_100 -> V_29 = NULL ;
V_91 += V_18 -> V_25 ;
}
F_30 ( & V_88 -> V_87 ) ;
F_30 ( & V_88 -> V_66 ) ;
V_88 -> V_13 = V_57 -> V_13 + 1 ;
V_88 -> V_55 = V_55 ;
V_55 -> V_11 = V_88 ;
F_14 ( & V_55 -> V_85 ) ;
V_55 -> V_101 = V_88 -> V_13 ;
F_31 ( & V_57 -> V_87 , & V_55 -> V_102 ) ;
F_17 ( & V_55 -> V_85 ) ;
F_32 ( & V_55 -> V_97 ) ;
V_3 = V_57 -> V_12 ;
V_93 . V_103 = V_104 ;
V_93 . V_105 = V_8 ;
V_93 . V_106 = V_3 -> V_107 ;
V_93 . V_108 = V_91 ;
V_94 . V_109 = & V_93 ;
V_94 . V_110 = sizeof( V_111 ) ;
V_94 . V_112 = V_113 ;
V_3 -> V_9 -= V_94 . V_110 + sizeof( V_63 ) ;
V_95 . V_25 = 1 ;
V_95 . V_51 = & V_94 ;
V_95 . V_49 = V_57 -> V_81 ;
error = F_33 ( log , & V_95 , V_3 , & V_57 -> V_82 , NULL , 0 ) ;
if ( error )
goto V_114;
V_115:
F_14 ( & V_55 -> V_85 ) ;
F_9 (new_ctx, &cil->xc_committing, committing) {
if ( F_34 ( log ) ) {
F_17 ( & V_55 -> V_85 ) ;
goto V_114;
}
if ( V_88 -> V_13 >= V_57 -> V_13 )
continue;
if ( ! V_88 -> V_14 ) {
F_35 ( & V_55 -> V_86 , & V_55 -> V_85 ) ;
goto V_115;
}
}
F_17 ( & V_55 -> V_85 ) ;
V_14 = F_36 ( log -> V_79 , V_3 , & V_90 , 0 ) ;
if ( V_14 == - 1 )
goto V_116;
V_57 -> V_117 . V_118 = F_19 ;
V_57 -> V_117 . V_119 = V_57 ;
error = F_37 ( log -> V_79 , V_90 , & V_57 -> V_117 ) ;
if ( error )
goto V_116;
F_14 ( & V_55 -> V_85 ) ;
V_57 -> V_14 = V_14 ;
F_23 ( & V_55 -> V_86 ) ;
F_17 ( & V_55 -> V_85 ) ;
return F_38 ( log -> V_79 , V_90 ) ;
V_99:
F_32 ( & V_55 -> V_97 ) ;
F_39 ( V_88 -> V_12 ) ;
F_6 ( V_88 ) ;
return 0 ;
V_114:
F_39 ( V_3 ) ;
V_116:
F_19 ( V_57 , V_120 ) ;
return F_40 ( V_121 ) ;
}
static void
F_41 (
struct V_122 * V_123 )
{
struct V_54 * V_55 = F_42 ( V_123 , struct V_54 ,
V_124 ) ;
F_26 ( V_55 -> V_78 ) ;
}
static void
F_43 (
struct V_2 * log )
{
struct V_54 * V_55 = log -> V_10 ;
ASSERT ( ! F_8 ( & V_55 -> V_62 ) ) ;
if ( V_55 -> V_11 -> V_71 < F_44 ( log ) )
return;
F_14 ( & V_55 -> V_85 ) ;
if ( V_55 -> V_98 < V_55 -> V_101 ) {
V_55 -> V_98 = V_55 -> V_101 ;
F_45 ( log -> V_79 -> V_125 , & V_55 -> V_124 ) ;
}
F_17 ( & V_55 -> V_85 ) ;
}
static void
F_46 (
struct V_2 * log ,
T_1 V_96 )
{
struct V_54 * V_55 = log -> V_10 ;
if ( ! V_55 )
return;
ASSERT ( V_96 && V_96 <= V_55 -> V_101 ) ;
F_47 ( & V_55 -> V_124 ) ;
F_14 ( & V_55 -> V_85 ) ;
if ( F_8 ( & V_55 -> V_62 ) || V_96 <= V_55 -> V_98 ) {
F_17 ( & V_55 -> V_85 ) ;
return;
}
V_55 -> V_98 = V_96 ;
F_45 ( log -> V_79 -> V_125 , & V_55 -> V_124 ) ;
F_17 ( & V_55 -> V_85 ) ;
}
bool
F_48 (
struct V_2 * log )
{
struct V_54 * V_55 = log -> V_10 ;
bool V_126 = false ;
F_14 ( & V_55 -> V_85 ) ;
if ( F_8 ( & V_55 -> V_62 ) )
V_126 = true ;
F_17 ( & V_55 -> V_85 ) ;
return V_126 ;
}
void
F_49 (
struct V_76 * V_77 ,
struct V_31 * V_32 ,
T_1 * V_14 ,
int V_127 )
{
struct V_2 * log = V_77 -> V_128 ;
struct V_54 * V_55 = log -> V_10 ;
int V_129 = 0 ;
if ( V_127 & V_130 )
V_129 = V_131 ;
F_50 ( & V_55 -> V_97 ) ;
F_13 ( log , V_32 ) ;
if ( V_32 -> V_68 -> V_9 < 0 )
F_51 ( V_77 , V_32 -> V_68 ) ;
V_32 -> V_132 = V_55 -> V_11 -> V_13 ;
if ( V_14 )
* V_14 = V_32 -> V_132 ;
F_36 ( V_77 , V_32 -> V_68 , NULL , V_129 ) ;
F_52 ( V_32 ) ;
F_53 ( V_32 , V_32 -> V_132 , 0 ) ;
F_43 ( log ) ;
F_54 ( & V_55 -> V_97 ) ;
}
T_1
F_55 (
struct V_2 * log ,
T_1 V_13 )
{
struct V_54 * V_55 = log -> V_10 ;
struct V_56 * V_57 ;
T_1 V_14 = V_133 ;
ASSERT ( V_13 <= V_55 -> V_101 ) ;
V_115:
F_46 ( log , V_13 ) ;
F_14 ( & V_55 -> V_85 ) ;
F_9 (ctx, &cil->xc_committing, committing) {
if ( F_34 ( log ) )
goto V_134;
if ( V_57 -> V_13 > V_13 )
continue;
if ( ! V_57 -> V_14 ) {
F_35 ( & V_55 -> V_86 , & V_55 -> V_85 ) ;
goto V_115;
}
if ( V_57 -> V_13 != V_13 )
continue;
V_14 = V_57 -> V_14 ;
}
if ( V_13 == V_55 -> V_101 &&
! F_8 ( & V_55 -> V_62 ) ) {
F_17 ( & V_55 -> V_85 ) ;
goto V_115;
}
F_17 ( & V_55 -> V_85 ) ;
return V_14 ;
V_134:
F_17 ( & V_55 -> V_85 ) ;
return 0 ;
}
bool
F_56 (
struct V_36 * V_37 )
{
struct V_56 * V_57 ;
if ( F_8 ( & V_37 -> V_61 ) )
return false ;
V_57 = V_37 -> V_135 -> V_128 -> V_10 -> V_11 ;
if ( F_57 ( V_37 -> V_30 , V_57 -> V_13 ) != 0 )
return false ;
return true ;
}
int
F_58 (
struct V_2 * log )
{
struct V_54 * V_55 ;
struct V_56 * V_57 ;
V_55 = F_11 ( sizeof( * V_55 ) , V_5 | V_136 ) ;
if ( ! V_55 )
return V_137 ;
V_57 = F_11 ( sizeof( * V_57 ) , V_5 | V_136 ) ;
if ( ! V_57 ) {
F_6 ( V_55 ) ;
return V_137 ;
}
F_59 ( & V_55 -> V_124 , F_41 ) ;
F_30 ( & V_55 -> V_62 ) ;
F_30 ( & V_55 -> V_102 ) ;
F_60 ( & V_55 -> V_60 ) ;
F_60 ( & V_55 -> V_85 ) ;
F_61 ( & V_55 -> V_97 ) ;
F_62 ( & V_55 -> V_86 ) ;
F_30 ( & V_57 -> V_87 ) ;
F_30 ( & V_57 -> V_66 ) ;
V_57 -> V_13 = 1 ;
V_57 -> V_55 = V_55 ;
V_55 -> V_11 = V_57 ;
V_55 -> V_101 = V_57 -> V_13 ;
V_55 -> V_78 = log ;
log -> V_10 = V_55 ;
return 0 ;
}
void
F_63 (
struct V_2 * log )
{
if ( log -> V_10 -> V_11 ) {
if ( log -> V_10 -> V_11 -> V_12 )
F_39 ( log -> V_10 -> V_11 -> V_12 ) ;
F_6 ( log -> V_10 -> V_11 ) ;
}
ASSERT ( F_8 ( & log -> V_10 -> V_62 ) ) ;
F_6 ( log -> V_10 ) ;
}
