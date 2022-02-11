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
STATIC int
F_5 (
struct V_17 * V_18 ,
struct V_19 * V_20 )
{
int V_21 ;
char * V_22 ;
V_18 -> V_23 -> V_24 ( V_18 , V_20 -> V_25 ) ;
V_22 = V_20 -> V_26 ;
for ( V_21 = 0 ; V_21 < V_20 -> V_27 ; V_21 ++ ) {
struct V_28 * V_29 = & V_20 -> V_25 [ V_21 ] ;
memcpy ( V_22 , V_29 -> V_30 , V_29 -> V_31 ) ;
V_29 -> V_30 = V_22 ;
V_22 += V_29 -> V_31 ;
}
return V_22 - V_20 -> V_26 ;
}
STATIC void
F_6 (
struct V_2 * log ,
struct V_19 * V_20 ,
struct V_19 * V_32 ,
int * V_33 ,
int * V_34 )
{
if ( V_20 -> V_35 != V_36 ) {
* V_33 += V_20 -> V_35 ;
* V_34 += V_20 -> V_27 ;
}
if ( ! V_32 )
V_20 -> V_37 -> V_23 -> V_38 ( V_20 -> V_37 ) ;
else if ( V_32 != V_20 ) {
ASSERT ( V_20 -> V_35 != V_36 ) ;
* V_33 -= V_32 -> V_35 ;
* V_34 -= V_32 -> V_27 ;
F_7 ( V_32 ) ;
}
V_20 -> V_37 -> V_39 = V_20 ;
if ( ! V_20 -> V_37 -> V_40 )
V_20 -> V_37 -> V_40 = log -> V_10 -> V_11 -> V_13 ;
}
static void
F_8 (
struct V_2 * log ,
struct V_41 * V_42 ,
int * V_33 ,
int * V_34 )
{
struct V_43 * V_44 ;
if ( F_9 ( & V_42 -> V_45 ) ) {
ASSERT ( 0 ) ;
return;
}
F_10 (lidp, &tp->t_items, lid_trans) {
struct V_17 * V_18 = V_44 -> V_46 ;
struct V_19 * V_20 ;
struct V_19 * V_32 ;
int V_47 = 0 ;
int V_48 = 0 ;
int V_49 ;
bool V_50 = false ;
if ( ! ( V_44 -> V_51 & V_52 ) )
continue;
V_18 -> V_23 -> V_53 ( V_18 , & V_47 , & V_48 ) ;
if ( ! V_47 )
continue;
if ( V_47 == V_36 ) {
V_50 = true ;
V_47 = 0 ;
V_48 = 0 ;
}
V_32 = V_18 -> V_39 ;
V_49 = sizeof( struct V_19 ) + V_48 +
V_47 * sizeof( struct V_28 ) ;
if ( V_18 -> V_39 && V_49 <= V_18 -> V_39 -> V_54 ) {
V_20 = V_18 -> V_39 ;
V_20 -> V_55 = NULL ;
if ( V_50 )
goto V_56;
* V_34 -= V_20 -> V_27 ;
* V_33 -= V_20 -> V_35 ;
V_20 -> V_27 = V_47 ;
V_20 -> V_26 = ( char * ) V_20 + V_49 - V_48 ;
V_20 -> V_35 = F_5 ( V_18 , V_20 ) ;
goto V_56;
}
V_20 = F_11 ( V_49 , V_5 | V_6 ) ;
V_20 -> V_37 = V_18 ;
V_20 -> V_54 = V_49 ;
V_20 -> V_27 = V_47 ;
if ( V_50 ) {
ASSERT ( V_18 -> V_39 == NULL ) ;
V_20 -> V_35 = V_36 ;
goto V_56;
}
V_20 -> V_25 = (struct V_28 * ) & V_20 [ 1 ] ;
V_20 -> V_26 = ( char * ) V_20 + V_49 - V_48 ;
V_20 -> V_35 = F_5 ( V_18 , V_20 ) ;
V_56:
ASSERT ( V_20 -> V_35 <= V_48 ) ;
F_6 ( log , V_20 , V_32 , V_33 , V_34 ) ;
}
}
static void
F_12 (
struct V_2 * log ,
struct V_41 * V_42 )
{
struct V_57 * V_58 = log -> V_10 ;
struct V_59 * V_60 = V_58 -> V_11 ;
struct V_43 * V_44 ;
int V_61 = 0 ;
int V_34 = 0 ;
int V_62 ;
ASSERT ( V_42 ) ;
F_8 ( log , V_42 , & V_61 , & V_34 ) ;
F_13 ( & V_58 -> V_63 ) ;
F_10 (lidp, &tp->t_items, lid_trans) {
struct V_17 * V_18 = V_44 -> V_46 ;
if ( ! ( V_44 -> V_51 & V_52 ) )
continue;
F_14 ( & V_18 -> V_64 , & V_58 -> V_65 ) ;
}
V_61 += V_34 * sizeof( V_66 ) ;
V_60 -> V_67 += V_34 ;
if ( ! F_9 ( & V_42 -> V_68 ) )
F_15 ( & V_42 -> V_68 , & V_60 -> V_69 ) ;
if ( V_60 -> V_12 -> V_9 == 0 ) {
V_60 -> V_12 -> V_9 = V_60 -> V_12 -> V_70 ;
V_42 -> V_71 -> V_9 -= V_60 -> V_12 -> V_70 ;
}
V_62 = log -> V_72 - log -> V_73 ;
if ( V_61 > 0 && ( V_60 -> V_74 / V_62 !=
( V_60 -> V_74 + V_61 ) / V_62 ) ) {
int V_75 ;
V_75 = ( V_61 + V_62 - 1 ) / V_62 ;
V_75 *= log -> V_73 + sizeof( struct V_76 ) ;
V_60 -> V_12 -> V_70 += V_75 ;
V_60 -> V_12 -> V_9 += V_75 ;
V_42 -> V_71 -> V_9 -= V_75 ;
ASSERT ( V_42 -> V_71 -> V_9 >= V_61 ) ;
}
V_42 -> V_71 -> V_9 -= V_61 ;
V_60 -> V_74 += V_61 ;
F_16 ( & V_58 -> V_63 ) ;
}
static void
F_17 (
struct V_19 * V_77 )
{
struct V_19 * V_20 ;
for ( V_20 = V_77 ; V_20 ; ) {
struct V_19 * V_78 = V_20 -> V_55 ;
F_7 ( V_20 ) ;
V_20 = V_78 ;
}
}
static void
F_18 (
void * args ,
int abort )
{
struct V_59 * V_60 = args ;
struct V_79 * V_80 = V_60 -> V_58 -> V_81 -> V_82 ;
F_19 ( V_60 -> V_58 -> V_81 -> V_83 , V_60 -> V_84 ,
V_60 -> V_85 , abort ) ;
F_20 ( & V_60 -> V_69 ) ;
F_21 ( V_80 , & V_60 -> V_69 ,
( V_80 -> V_86 & V_87 ) && ! abort ) ;
F_13 ( & V_60 -> V_58 -> V_88 ) ;
F_22 ( & V_60 -> V_89 ) ;
F_16 ( & V_60 -> V_58 -> V_88 ) ;
F_17 ( V_60 -> V_84 ) ;
if ( ! F_9 ( & V_60 -> V_69 ) ) {
ASSERT ( V_80 -> V_86 & V_87 ) ;
F_23 ( V_80 , & V_60 -> V_69 ) ;
F_21 ( V_80 , & V_60 -> V_69 , false ) ;
}
F_7 ( V_60 ) ;
}
STATIC int
F_24 (
struct V_2 * log )
{
struct V_57 * V_58 = log -> V_10 ;
struct V_19 * V_20 ;
struct V_59 * V_60 ;
struct V_59 * V_90 ;
struct V_91 * V_92 ;
struct V_1 * V_3 ;
int V_93 ;
int error = 0 ;
struct V_94 V_95 ;
struct V_28 V_96 ;
struct V_19 V_97 = { NULL } ;
T_1 V_14 ;
T_1 V_98 ;
if ( ! V_58 )
return 0 ;
V_90 = F_11 ( sizeof( * V_90 ) , V_5 | V_6 ) ;
V_90 -> V_12 = F_1 ( log ) ;
F_25 ( & V_58 -> V_99 ) ;
V_60 = V_58 -> V_11 ;
F_13 ( & V_58 -> V_88 ) ;
V_98 = V_58 -> V_100 ;
ASSERT ( V_98 <= V_60 -> V_13 ) ;
if ( F_9 ( & V_58 -> V_65 ) ) {
V_58 -> V_100 = 0 ;
F_16 ( & V_58 -> V_88 ) ;
goto V_101;
}
F_16 ( & V_58 -> V_88 ) ;
if ( V_98 < V_58 -> V_11 -> V_13 )
goto V_101;
V_20 = NULL ;
V_93 = 0 ;
while ( ! F_9 ( & V_58 -> V_65 ) ) {
struct V_17 * V_102 ;
V_102 = F_26 ( & V_58 -> V_65 ,
struct V_17 , V_64 ) ;
F_27 ( & V_102 -> V_64 ) ;
if ( ! V_60 -> V_84 )
V_60 -> V_84 = V_102 -> V_39 ;
else
V_20 -> V_55 = V_102 -> V_39 ;
V_20 = V_102 -> V_39 ;
V_102 -> V_39 = NULL ;
V_93 += V_20 -> V_27 ;
}
F_28 ( & V_90 -> V_89 ) ;
F_28 ( & V_90 -> V_69 ) ;
V_90 -> V_13 = V_60 -> V_13 + 1 ;
V_90 -> V_58 = V_58 ;
V_58 -> V_11 = V_90 ;
V_58 -> V_103 = V_90 -> V_13 ;
F_13 ( & V_58 -> V_88 ) ;
F_29 ( & V_60 -> V_89 , & V_58 -> V_104 ) ;
F_16 ( & V_58 -> V_88 ) ;
F_30 ( & V_58 -> V_99 ) ;
V_3 = V_60 -> V_12 ;
V_95 . V_105 = V_106 ;
V_95 . V_107 = V_8 ;
V_95 . V_108 = V_3 -> V_109 ;
V_95 . V_110 = V_93 ;
V_96 . V_30 = & V_95 ;
V_96 . V_31 = sizeof( V_111 ) ;
V_96 . V_112 = V_113 ;
V_3 -> V_9 -= V_96 . V_31 + sizeof( V_66 ) ;
V_97 . V_27 = 1 ;
V_97 . V_25 = & V_96 ;
V_97 . V_55 = V_60 -> V_84 ;
error = F_31 ( log , & V_97 , V_3 , & V_60 -> V_85 , NULL , 0 ) ;
if ( error )
goto V_114;
V_115:
F_13 ( & V_58 -> V_88 ) ;
F_10 (new_ctx, &cil->xc_committing, committing) {
if ( V_90 -> V_13 >= V_60 -> V_13 )
continue;
if ( ! V_90 -> V_14 ) {
F_32 ( & V_58 -> V_116 , & V_58 -> V_88 ) ;
goto V_115;
}
}
F_16 ( & V_58 -> V_88 ) ;
V_14 = F_33 ( log -> V_82 , V_3 , & V_92 , 0 ) ;
if ( V_14 == - 1 )
goto V_117;
V_60 -> V_118 . V_119 = F_18 ;
V_60 -> V_118 . V_120 = V_60 ;
error = F_34 ( log -> V_82 , V_92 , & V_60 -> V_118 ) ;
if ( error )
goto V_117;
F_13 ( & V_58 -> V_88 ) ;
V_60 -> V_14 = V_14 ;
F_35 ( & V_58 -> V_116 ) ;
F_16 ( & V_58 -> V_88 ) ;
return F_36 ( log -> V_82 , V_92 ) ;
V_101:
F_30 ( & V_58 -> V_99 ) ;
F_37 ( V_90 -> V_12 ) ;
F_7 ( V_90 ) ;
return 0 ;
V_114:
F_37 ( V_3 ) ;
V_117:
F_18 ( V_60 , V_121 ) ;
return F_38 ( V_122 ) ;
}
static void
F_39 (
struct V_123 * V_124 )
{
struct V_57 * V_58 = F_40 ( V_124 , struct V_57 ,
V_125 ) ;
F_24 ( V_58 -> V_81 ) ;
}
static void
F_41 (
struct V_2 * log )
{
struct V_57 * V_58 = log -> V_10 ;
ASSERT ( ! F_9 ( & V_58 -> V_65 ) ) ;
if ( V_58 -> V_11 -> V_74 < F_42 ( log ) )
return;
F_13 ( & V_58 -> V_88 ) ;
if ( V_58 -> V_100 < V_58 -> V_103 ) {
V_58 -> V_100 = V_58 -> V_103 ;
F_43 ( log -> V_82 -> V_126 , & V_58 -> V_125 ) ;
}
F_16 ( & V_58 -> V_88 ) ;
}
static void
F_44 (
struct V_2 * log ,
T_1 V_98 )
{
struct V_57 * V_58 = log -> V_10 ;
if ( ! V_58 )
return;
ASSERT ( V_98 && V_98 <= V_58 -> V_103 ) ;
F_45 ( & V_58 -> V_125 ) ;
F_13 ( & V_58 -> V_88 ) ;
if ( F_9 ( & V_58 -> V_65 ) || V_98 <= V_58 -> V_100 ) {
F_16 ( & V_58 -> V_88 ) ;
return;
}
V_58 -> V_100 = V_98 ;
F_16 ( & V_58 -> V_88 ) ;
F_24 ( log ) ;
}
bool
F_46 (
struct V_2 * log )
{
struct V_57 * V_58 = log -> V_10 ;
bool V_127 = false ;
F_13 ( & V_58 -> V_88 ) ;
if ( F_9 ( & V_58 -> V_65 ) )
V_127 = true ;
F_16 ( & V_58 -> V_88 ) ;
return V_127 ;
}
int
F_47 (
struct V_79 * V_80 ,
struct V_41 * V_42 ,
T_1 * V_14 ,
int V_128 )
{
struct V_2 * log = V_80 -> V_129 ;
struct V_57 * V_58 = log -> V_10 ;
int V_130 = 0 ;
if ( V_128 & V_131 )
V_130 = V_132 ;
F_48 ( & V_58 -> V_99 ) ;
F_12 ( log , V_42 ) ;
if ( V_42 -> V_71 -> V_9 < 0 )
F_49 ( V_80 , V_42 -> V_71 ) ;
V_42 -> V_133 = V_58 -> V_11 -> V_13 ;
if ( V_14 )
* V_14 = V_42 -> V_133 ;
F_33 ( V_80 , V_42 -> V_71 , NULL , V_130 ) ;
F_50 ( V_42 ) ;
F_51 ( V_42 , V_42 -> V_133 , 0 ) ;
F_41 ( log ) ;
F_52 ( & V_58 -> V_99 ) ;
return 0 ;
}
T_1
F_53 (
struct V_2 * log ,
T_1 V_13 )
{
struct V_57 * V_58 = log -> V_10 ;
struct V_59 * V_60 ;
T_1 V_14 = V_134 ;
ASSERT ( V_13 <= V_58 -> V_103 ) ;
F_44 ( log , V_13 ) ;
V_115:
F_13 ( & V_58 -> V_88 ) ;
F_10 (ctx, &cil->xc_committing, committing) {
if ( V_60 -> V_13 > V_13 )
continue;
if ( ! V_60 -> V_14 ) {
F_32 ( & V_58 -> V_116 , & V_58 -> V_88 ) ;
goto V_115;
}
if ( V_60 -> V_13 != V_13 )
continue;
V_14 = V_60 -> V_14 ;
}
F_16 ( & V_58 -> V_88 ) ;
return V_14 ;
}
bool
F_54 (
struct V_17 * V_18 )
{
struct V_59 * V_60 ;
if ( F_9 ( & V_18 -> V_64 ) )
return false ;
V_60 = V_18 -> V_135 -> V_129 -> V_10 -> V_11 ;
if ( F_55 ( V_18 -> V_40 , V_60 -> V_13 ) != 0 )
return false ;
return true ;
}
int
F_56 (
struct V_2 * log )
{
struct V_57 * V_58 ;
struct V_59 * V_60 ;
V_58 = F_11 ( sizeof( * V_58 ) , V_5 | V_136 ) ;
if ( ! V_58 )
return V_137 ;
V_60 = F_11 ( sizeof( * V_60 ) , V_5 | V_136 ) ;
if ( ! V_60 ) {
F_7 ( V_58 ) ;
return V_137 ;
}
F_57 ( & V_58 -> V_125 , F_39 ) ;
F_28 ( & V_58 -> V_65 ) ;
F_28 ( & V_58 -> V_104 ) ;
F_58 ( & V_58 -> V_63 ) ;
F_58 ( & V_58 -> V_88 ) ;
F_59 ( & V_58 -> V_99 ) ;
F_60 ( & V_58 -> V_116 ) ;
F_28 ( & V_60 -> V_89 ) ;
F_28 ( & V_60 -> V_69 ) ;
V_60 -> V_13 = 1 ;
V_60 -> V_58 = V_58 ;
V_58 -> V_11 = V_60 ;
V_58 -> V_103 = V_60 -> V_13 ;
V_58 -> V_81 = log ;
log -> V_10 = V_58 ;
return 0 ;
}
void
F_61 (
struct V_2 * log )
{
if ( log -> V_10 -> V_11 ) {
if ( log -> V_10 -> V_11 -> V_12 )
F_37 ( log -> V_10 -> V_11 -> V_12 ) ;
F_7 ( log -> V_10 -> V_11 ) ;
}
ASSERT ( F_9 ( & log -> V_10 -> V_65 ) ) ;
F_7 ( log -> V_10 ) ;
}
